#include "CSubsetLexer.h"
#include "CSubsetParser.h"
#include "ICGVisitor.h"
#include "PeepholeOptimizer.h"
#include "antlr4-runtime.h"


#include <fstream>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

using namespace std;

// The inherited lexer skips string literals. They are not expressions in this
// subset, so diagnose them instead of silently dropping invalid source text.
class CheckedLexer : public CSubsetLexer {
public:
    using CSubsetLexer::CSubsetLexer;
    void skip() override {
        const auto text = getText();
        if (!text.empty() && text.front() == '"')
            throw runtime_error("Line " + to_string(getLine()) +
                                ": String literals are not supported by this grammar");
        CSubsetLexer::skip();
    }
};

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input.c>\n";
        return 1;
    }

    try {
        // Never leave stale assembly behind after a failed compilation.
        filesystem::remove("code.asm");
        filesystem::remove("optimized_code.asm");
        ifstream inputFile(argv[1]);
        if (!inputFile)
            throw runtime_error("Could not open input file: " + string(argv[1]));
        const string source(
            (istreambuf_iterator<char>(inputFile)),
            istreambuf_iterator<char>());
        antlr4::ANTLRInputStream input(source);
        CheckedLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer); 
        tokens.fill();
        for (auto token : tokens.getTokens()) {
            if (token->getType() == CSubsetLexer::UNKNOWN ||
                token->getType() == CSubsetLexer::STRING) {
                throw runtime_error("Line " + to_string(token->getLine()) +
                                    ": Invalid token '" + token->getText() + "'");
            }
        }
        CSubsetParser parser(&tokens);

        antlr4::tree::ParseTree* tree = parser.start();

        if (lexer.getNumberOfSyntaxErrors() != 0 ||
            parser.getNumberOfSyntaxErrors() != 0 ||
            tokens.LA(1) != antlr4::Token::EOF) {
            cerr << "ICG stopped because the input has syntax errors.\n";
            return 1;
        }

        const auto library = filesystem::canonical("/proc/self/exe").parent_path() / "printProc.lib";
        ICGVisitor visitor("code.asm", library.string());
        visitor.generate(tree);

        PeepholeOptimizer::optimize("code.asm", "optimized_code.asm");
    }
    catch (const exception& e) {
        error_code ignored;
        filesystem::remove("code.asm", ignored);
        filesystem::remove("optimized_code.asm", ignored);
        cerr << "ICG error: " << e.what() << '\n';
        return 1;
    }

    cout << "Generated code.asm and optimized_code.asm\n";
    return 0;
}
