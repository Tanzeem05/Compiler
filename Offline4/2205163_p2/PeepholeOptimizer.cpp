#include "PeepholeOptimizer.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace {
string trim(const string& s)
{
    auto first = s.find_first_not_of(" \t\r\n");
    return first == string::npos ? "" : s.substr(first, s.find_last_not_of(" \t\r\n") - first + 1);
}
string lower(string s)
{
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    return s;
}
struct Line {
    string code, comment, op, a, b, label;
    explicit Line(const string& raw) {
        auto semicolon = raw.find(';');
        code = trim(raw.substr(0, semicolon));
        if (semicolon != string::npos) comment = raw.substr(semicolon);
        if (code.empty()) return;
        if (code.back() == ':') { label = trim(code.substr(0, code.size() - 1)); return; }
        auto space = code.find_first_of(" \t");
        op = lower(code.substr(0, space));
        if (space == string::npos) return;
        auto rest = trim(code.substr(space + 1));
        auto comma = rest.find(',');
        a = trim(rest.substr(0, comma));
        if (comma != string::npos) b = trim(rest.substr(comma + 1));
    }
};
bool reg(const string& s)
{
    static const unordered_set<string> registers = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp"};
    return registers.count(lower(s)); // ESP has special push/pop and addressing semantics.
}
bool same(const string& a, const string& b)
{
    return reg(a) && reg(b) ? lower(a) == lower(b) : a == b;
}
bool usesRegister(const string& operand, const string& name)
{
    static const regex token("[A-Za-z_][A-Za-z_0-9]*");
    for (sregex_iterator i(operand.begin(), operand.end(), token), end; i != end; ++i)
        if (lower(i->str()) == lower(name)) return true;
    return false;
}
size_t nextCode(const vector<string>& lines, size_t i)
{
    while (i < lines.size() && Line(lines[i]).code.empty()) ++i;
    return i;
}
void eraseInstruction(vector<string>& lines, size_t i)
{
    lines[i] = Line(lines[i]).comment; // Retain source line annotations.
}

// Removing ADD/SUB 0 or IMUL 1 is safe only if its flags cannot be read.
bool flagsDead(const vector<string>& lines, size_t begin)
{
    static const unordered_set<string> overwrite = {"cmp", "test", "add", "sub", "and", "or", "xor", "neg"};
    static const unordered_set<string> preserve = {"mov", "lea", "push", "pop", "cdq", "nop"};
    for (size_t i = begin; i < lines.size(); ++i) {
        Line l(lines[i]);
        if (l.code.empty()) continue;
        if (!l.label.empty()) return false;
        if (overwrite.count(l.op) || l.op == "ret") return true;
        if (!preserve.count(l.op)) return false;
    }
    return false;
}

bool simplePass(vector<string>& lines)
{
    bool changed = false;
    for (size_t i = 0; i < lines.size(); ++i) {
        Line l(lines[i]);
        if (l.code.empty()) continue;
        if ((l.op == "mov" && reg(l.a) && same(l.a, l.b)) ||
            (((l.op == "add" || l.op == "sub") && l.b == "0" && reg(l.a) && flagsDead(lines, i + 1))) ||
            (l.op == "imul" && l.b == "1" && reg(l.a) && flagsDead(lines, i + 1))) {
            eraseInstruction(lines, i);
            changed = true;
            continue;
        }
        size_t j = nextCode(lines, i + 1);
        if (j == lines.size()) continue;
        Line r(lines[j]);
        if (l.op == "push" && r.op == "pop" && reg(l.a) && reg(r.a)) {
            if (same(l.a, r.a)) eraseInstruction(lines, j);
            else lines[j] = "\tMOV " + r.a + ", " + l.a + " " + r.comment;
            eraseInstruction(lines, i);
            changed = true;
        } else if (l.op == "mov" && r.op == "mov" && reg(l.a) &&
                   same(l.a, r.b) && same(l.b, r.a) &&
                   (reg(l.b) || (l.b.find('[') != string::npos && !usesRegister(l.b, l.a)))) {
            // Do not eliminate MOV EAX,[EAX]; MOV [EAX],EAX: the address changed.
            eraseInstruction(lines, j);
            changed = true;
        }
    }
    return changed;
}

bool foldImmediateArithmetic(vector<string>& lines)
{
    bool changed = false;
    static const regex integer("[0-9]+");
    for (size_t i = 0; i < lines.size(); ++i) {
        Line first(lines[i]);
        if (first.op != "push" || lower(first.a) != "eax") continue;
        size_t positions[5] = {i};
        for (int n = 1; n < 5; ++n) positions[n] = nextCode(lines, positions[n - 1] + 1);
        if (positions[4] >= lines.size()) continue;
        Line literal(lines[positions[1]]), copy(lines[positions[2]]),
             restore(lines[positions[3]]), arithmetic(lines[positions[4]]);
        if (literal.op != "mov" || lower(literal.a) != "eax" || !regex_match(literal.b, integer) ||
            copy.op != "mov" || lower(copy.b) != "eax" ||
            (lower(copy.a) != "edx" && lower(copy.a) != "ecx") ||
            restore.op != "pop" || lower(restore.a) != "eax" ||
            (arithmetic.op != "add" && arithmetic.op != "sub" && arithmetic.op != "imul") ||
            lower(arithmetic.a) != "eax" || !same(arithmetic.b, copy.a)) continue;
        // Preserve the scratch register's final value as well as arithmetic flags.
        lines[positions[1]] = "\tMOV " + copy.a + ", " + literal.b + " " + literal.comment;
        eraseInstruction(lines, positions[0]);
        eraseInstruction(lines, positions[2]);
        eraseInstruction(lines, positions[3]);
        lines[positions[4]] = "\t" + arithmetic.op + " EAX, " + literal.b + " " + arithmetic.comment;
        changed = true;
    }
    return changed;
}

bool collapseLabels(vector<string>& lines)
{
    unordered_map<string, string> redirect;
    vector<string> scopes(lines.size());
    string canonical, canonicalScope, scope;
    static const regex generatedLocal("\\.L[0-9]+");
    for (size_t i = 0; i < lines.size(); ++i) {
        Line l(lines[i]);
        scopes[i] = scope;
        if (l.code.empty()) continue;
        const bool local = regex_match(l.label, generatedLocal);
        const bool global = l.label.rfind("__icg_L", 0) == 0;
        if (local || global) {
            string labelScope = local ? scope : "";
            if (canonical.empty() || canonicalScope != labelScope) {
                canonical = l.label;
                canonicalScope = labelScope;
            } else {
                redirect[labelScope + "\n" + l.label] = canonical;
                eraseInstruction(lines, i);
            }
        } else canonical.clear();
        if (!l.label.empty() && l.label.front() != '.') scope = l.label;
    }
    if (redirect.empty()) return false;
    for (size_t i = 0; i < lines.size(); ++i) {
        Line l(lines[i]);
        if (l.op.empty() || l.op[0] != 'j') continue;
        string labelScope = !l.a.empty() && l.a.front() == '.' ? scopes[i] : "";
        auto target = redirect.find(labelScope + "\n" + l.a);
        if (target != redirect.end()) lines[i] = "\t" + l.op + " " + target->second + " " + l.comment;
    }
    return true;
}

bool removeJumpsToNextLabel(vector<string>& lines)
{
    bool changed = false;
    for (size_t i = 0; i < lines.size(); ++i) {
        Line l(lines[i]);
        if (l.op != "jmp") continue;
        size_t j = nextCode(lines, i + 1);
        if (j < lines.size() && Line(lines[j]).label == l.a) {
            eraseInstruction(lines, i);
            changed = true;
        }
    }
    return changed;
}
} // namespace

void PeepholeOptimizer::optimize(const string& inputFile, const string& outputFile)
{
    ifstream in(inputFile);
    if (!in) throw runtime_error("Could not open " + inputFile);
    vector<string> lines;
    string line;
    while (getline(in, line)) lines.push_back(line);
    bool changed;
    do {
        changed = foldImmediateArithmetic(lines);
        changed = simplePass(lines) || changed;
        changed = collapseLabels(lines) || changed;
        changed = removeJumpsToNextLabel(lines) || changed;
    } while (changed);
    ofstream out(outputFile, ios::trunc);
    if (!out) throw runtime_error("Could not create " + outputFile);
    for (const auto& current : lines) if (!current.empty()) out << current << '\n';
    out.flush();
    if (!out) throw runtime_error("Could not write " + outputFile);
}
