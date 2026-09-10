#include "ICGVisitor.h"

#include <cstdio>
#include <limits>
#include <algorithm>
#include <cctype>
#include <regex>
#include <stdexcept>

using namespace std;

ICGVisitor::ICGVisitor(const string& outputFile, const string& libraryFile)
    : outputFile(outputFile), temporaryFile(outputFile + ".tmp"),
      libraryFile(libraryFile)
{
    body.open(temporaryFile, ios::trunc);
    if (!body) throw runtime_error("Could not create " + temporaryFile);
    symbolTable.enterScope();
}

ICGVisitor::~ICGVisitor()
{
    body.close();
    out.close();
    remove(temporaryFile.c_str());
}

[[noreturn]] void ICGVisitor::fail(antlr4::ParserRuleContext* ctx, const string& message) const
{
    throw runtime_error("Line " + to_string(ctx->getStart()->getLine()) + ": " + message);
}

void ICGVisitor::emit(const string& instruction) { body << '\t' << instruction << '\n'; }
void ICGVisitor::emitAtLine(const string& instruction, int sourceLine)
{
    body << '\t' << instruction << "       ; Line " << sourceLine << '\n';
}
void ICGVisitor::emitLabel(const string& label)
{
    body << label << ":\n";
    if (label.rfind(".L", 0) == 0) emittedLabels.push_back(label);
}
string ICGVisitor::newLabel() { return ".L" + to_string(labelCounter++); }
void ICGVisitor::annotate(antlr4::ParserRuleContext* ctx)
{
    currentExpressionLine = ctx->getStart()->getLine();
}

void ICGVisitor::materialize(bool comment)
{
    if (valueOnStack) {
        if (comment) emitAtLine("POP EAX", currentExpressionLine);
        else emit("POP EAX");
        valueOnStack = false;
    }
}

void ICGVisitor::requireInt(antlr4::ParserRuleContext* ctx, bool materializeValue)
{
    const string savedTrue = branchTrue, savedFalse = branchFalse;
    const bool savedCondition = conditionEmitted;
    branchTrue.clear();
    branchFalse.clear();
    conditionEmitted = false;
    valueOnStack = false;
    auto type = visit(ctx);
    if (!type.has_value() || any_cast<string>(type) != "int")
        fail(ctx, "An integer value is required (void function used as a value)");
    if (materializeValue) materialize();
    branchTrue = savedTrue;
    branchFalse = savedFalse;
    conditionEmitted = savedCondition;
}

void ICGVisitor::condition(antlr4::ParserRuleContext* ctx, string yes, string no)
{
    const string savedTrue = branchTrue, savedFalse = branchFalse;
    const bool savedCondition = conditionEmitted;
    branchTrue = yes;
    branchFalse = no;
    conditionEmitted = false;
    valueOnStack = false;
    auto type = visit(ctx);
    if (!type.has_value() || any_cast<string>(type) != "int")
        fail(ctx, "An integer condition is required");
    if (!conditionEmitted) {
        materialize();
        emit("CMP EAX, 0");
        emit("JNE " + yes);
        emit("JMP " + no);
    }
    branchTrue = savedTrue;
    branchFalse = savedFalse;
    conditionEmitted = savedCondition;
    valueOnStack = false;
}

void ICGVisitor::operands(antlr4::ParserRuleContext* left,
                         antlr4::ParserRuleContext* right, const string& scratch)
{
    // A leaf can be loaded after the right operand without clobbering its
    // register. Compound left expressions stay on the stack across RHS calls.
    static const regex leaf("([A-Za-z_][A-Za-z_0-9]*|[0-9]+)");
    if (regex_match(left->getText(), leaf)) {
        requireInt(right);
        emit("MOV " + scratch + ", EAX");
        requireInt(left);
    } else {
        requireInt(left, false);
        if (!valueOnStack) emit("PUSH EAX");
        valueOnStack = false;
        requireInt(right);
        emit("MOV " + scratch + ", EAX");
        emitAtLine("POP EAX", currentExpressionLine);
    }
}

string ICGVisitor::assemblyName(const string& name) const
{
    static const unordered_set<string> reserved = {
        "eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp", "eip",
        "ax", "bx", "cx", "dx", "si", "di", "bp", "sp", "al", "ah", "bl", "bh",
        "cl", "ch", "dl", "dh", "cs", "ds", "es", "fs", "gs", "ss",
        "format", "entry", "segment", "section", "readable", "writeable", "executable",
        "byte", "word", "dword", "qword", "tword", "dqword", "ptr", "dup",
        "db", "dw", "dd", "dq", "dt", "rb", "rw", "rd", "rq", "rt",
        "equ", "label", "macro", "end", "if", "else", "include", "file", "virtual",
        "repeat", "times", "load", "store", "org", "use16", "use32", "use64",
        "mov", "lea", "push", "pop", "call", "ret", "int", "add", "sub", "mul",
        "imul", "div", "idiv", "cmp", "test", "and", "or", "xor", "not", "neg",
        "inc", "dec", "jmp", "je", "jne", "jl", "jle", "jg", "jge", "loop",
        "shl", "shr", "sar", "rol", "ror", "xchg", "nop", "print_number"
    };
    string lowered = name;
    transform(lowered.begin(), lowered.end(), lowered.begin(),
              [](unsigned char c) { return tolower(c); });
    if (!reserved.count(lowered) && name.rfind("__icg_", 0) != 0) return name;
    const char* hex = "0123456789abcdef";
    string encoded = "__icg_symbol_";
    for (unsigned char c : name) { encoded += hex[c >> 4]; encoded += hex[c & 15]; }
    return encoded;
}

string ICGVisitor::memory(const StorageInfo& storage) const
{
    if (storage.global) return "[" + storage.name + "]";
    return "[EBP" + string(storage.offset < 0 ? "" : "+") + to_string(storage.offset) + "]";
}

void ICGVisitor::writePrintProcedure()
{
    ifstream library(libraryFile);
    if (!library) throw runtime_error("Could not open " + libraryFile);
    out << ";-------------------------------\n"
        << ";         print library         \n"
        << ";-------------------------------\n";
    string line;
    while (getline(library, line)) out << line << '\n';
    out << ";-------------------------------\n";
}

void ICGVisitor::generate(antlr4::tree::ParseTree* tree)
{
    // Emit on the fly during one visitor traversal into the only temporary file.
    visit(tree);
    auto main = symbolTable.lookUp("main");
    if (!main || !main->isFunction() || !main->isDefinedFunction())
        throw runtime_error("A definition of main is required");
    if (!main->getParameterTypes().empty())
        throw runtime_error("main must have no parameters");
    for (const auto& name : calledFunctions) {
        if (!symbolTable.lookUp(name)->isDefinedFunction())
            throw runtime_error("Called function '" + name + "' has no definition");
    }
    body.flush();
    if (!body) throw runtime_error("Could not write " + temporaryFile);
    body.close();
    out.open(outputFile, ios::trunc);
    if (!out) throw runtime_error("Could not create " + outputFile);
    const bool callableMain = calledFunctions.count("main") != 0;
    out << "format ELF executable 3\nentry " << (callableMain ? "__icg_start" : "main")
        << "\nsegment readable writeable\n";
    for (const auto& variable : globals)
        out << '\t' << variable.name << " dd " << variable.count << " DUP (0)"
            << "       ; Line " << variable.sourceLine << '\n';
    out << "segment readable executable\n";
    if (callableMain)
        out << "__icg_start:\n\tCALL main\n\tMOV EBX, EAX\n"
            << "\tMOV EAX,1\n\tINT 0x80\n";
    ifstream generatedBody(temporaryFile);
    if (!generatedBody) throw runtime_error("Could not open " + temporaryFile);
    unordered_map<string, string> labelNames;
    for (size_t i = 0; i < emittedLabels.size(); ++i)
        labelNames[emittedLabels[i]] = ".L" + to_string(i + 1);
    const regex labelToken("\\.L[0-9]+\\b");
    string line;
    while (getline(generatedBody, line)) {
        bool allocation = false;
        for (const auto& frame : frames) {
            if (line == frame.marker) {
                for (int size : frame.allocations) out << "\tSUB ESP, " << size << '\n';
                allocation = true;
                break;
            }
            const string exitMarker = frame.marker + "EXIT";
            auto at = line.find(exitMarker);
            if (at != string::npos) line.replace(at, exitMarker.size(), frame.exitLabel);
        }
        if (allocation) continue;
        if (line == "@@MAIN_EXIT@@") {
            if (callableMain) out << "\tRET\n";
            else out << "\tMOV EBX, EAX\n\tMOV EAX,1\n\tINT 0x80\n";
        } else {
            // Assign final numbers in textual order, including forward branches.
            size_t copied = 0;
            for (sregex_iterator it(line.begin(), line.end(), labelToken), end; it != end; ++it) {
                out << line.substr(copied, it->position() - copied) << labelNames.at(it->str());
                copied = it->position() + it->length();
            }
            out << line.substr(copied) << '\n';
        }
    }
    writePrintProcedure();
    out.flush();
    if (!out) throw runtime_error("Could not write " + outputFile);
    out.close();
}

vector<ParameterInfo> ICGVisitor::parameters(CSubsetParser::Parameter_listContext* ctx)
{
    auto result = ctx ? any_cast<vector<ParameterInfo>>(visit(ctx)) : vector<ParameterInfo>{};
    if (result.size() == 1 && result[0].type == "void" && result[0].name.empty())
        result.clear(); // f(void) and f() both have zero parameters.
    return result;
}

any ICGVisitor::visitParameterNamedSingle(CSubsetParser::ParameterNamedSingleContext* ctx)
{
    return vector<ParameterInfo>{{ctx->type_specifier()->getText(), ctx->ID()->getText()}};
}
any ICGVisitor::visitParameterUnnamedSingle(CSubsetParser::ParameterUnnamedSingleContext* ctx)
{
    return vector<ParameterInfo>{{ctx->type_specifier()->getText(), ""}};
}
any ICGVisitor::visitParameterNamedAppend(CSubsetParser::ParameterNamedAppendContext* ctx)
{
    auto result = any_cast<vector<ParameterInfo>>(visit(ctx->previous));
    result.push_back({ctx->type_specifier()->getText(), ctx->ID()->getText()});
    return result;
}
any ICGVisitor::visitParameterUnnamedAppend(CSubsetParser::ParameterUnnamedAppendContext* ctx)
{
    auto result = any_cast<vector<ParameterInfo>>(visit(ctx->previous));
    result.push_back({ctx->type_specifier()->getText(), ""});
    return result;
}

void ICGVisitor::installFunction(const string& name, const string& returnType,
    const vector<ParameterInfo>& params, bool definition, antlr4::ParserRuleContext* ctx)
{
    if (returnType != "int" && returnType != "void")
        fail(ctx, "Floating-point code generation is not supported");
    vector<string> types;
    unordered_set<string> names;
    for (const auto& param : params) {
        if (param.type != "int") fail(ctx, "Function parameters must have type int");
        if (!param.name.empty() && !names.insert(param.name).second)
            fail(ctx, "Duplicate parameter '" + param.name + "'");
        if (definition && param.name.empty()) fail(ctx, "Function definition needs named parameters");
        types.push_back(param.type);
    }
    SymbolInfo* symbol = symbolTable.lookUpCurrent(name);
    if (symbol) {
        if (!symbol->isFunction() || symbol->getReturnType() != returnType ||
            symbol->getParameterTypes() != types)
            fail(ctx, "Conflicting declaration of '" + name + "'");
        if (definition && symbol->isDefinedFunction())
            fail(ctx, "Redefinition of function '" + name + "'");
    } else {
        symbol = symbolTable.insertAndGet(name, "ID");
        symbol->setFunction(true);
        symbol->setReturnType(returnType);
        symbol->setParameterTypes(types);
    }
    if (definition) symbol->setDefinedFunction(true);
}

any ICGVisitor::visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext* ctx)
{
    installFunction(ctx->ID()->getText(), ctx->type_specifier()->getText(), parameters(ctx->parameter_list()), false, ctx);
    return {};
}
any ICGVisitor::visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext* ctx)
{
    installFunction(ctx->ID()->getText(), ctx->type_specifier()->getText(), {}, false, ctx);
    return {};
}
any ICGVisitor::visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext* ctx)
{
    defineFunction(ctx->ID()->getText(), ctx->type_specifier()->getText(), parameters(ctx->parameter_list()), ctx->compound_statement(), ctx);
    return {};
}
any ICGVisitor::visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx)
{
    defineFunction(ctx->ID()->getText(), ctx->type_specifier()->getText(), {}, ctx->compound_statement(), ctx);
    return {};
}

void ICGVisitor::defineFunction(const string& name, const string& returnType,
    const vector<ParameterInfo>& params, CSubsetParser::Compound_statementContext* compound,
    antlr4::ParserRuleContext* ctx)
{
    installFunction(name, returnType, params, true, ctx);
    currentFunction = name;
    currentReturnType = returnType;
    frames.push_back({"@@FRAME" + to_string(frames.size()) + "@@", {}, ""});
    currentExitLabel = frames.back().marker + "EXIT";
    nextLocalOffset = 0;
    annotate(ctx);
    emitLabel(assemblyName(name));
    emit("PUSH EBP");
    emit("MOV EBP, ESP");
    // Patch this single marker while copying the only temporary file, once the
    // visitor knows all locals. Numeric SUB instructions match the reference.
    body << frames.back().marker << '\n';
    symbolTable.enterScope();
    for (size_t i = 0; i < params.size(); ++i) {
        auto symbol = symbolTable.insertAndGet(params[i].name, "ID");
        symbol->setDataType("int");
        StorageInfo storage;
        storage.name = params[i].name;
        // Arguments are evaluated and pushed left to right; RET n removes them.
        storage.offset = 8 + 4 * static_cast<int>(params.size() - 1 - i);
        storageOfSymbol[symbol] = storage;
    }
    nextCompoundIsFunctionBody = true;
    visit(compound);
    emit("MOV EAX, 0"); // Deterministic fallthrough, including implicit main return.
    frames.back().exitLabel = newLabel();
    emitLabel(frames.back().exitLabel);
    if (nextLocalOffset) emit("ADD ESP, " + to_string(nextLocalOffset));
    emit("POP EBP");
    if (name == "main") body << "@@MAIN_EXIT@@\n";
    else if (!params.empty()) {
        const size_t bytes = params.size() * 4;
        if (bytes <= 65535) emit("RET " + to_string(bytes));
        else {
            // RET's immediate is only 16 bits; retain stack cleanup for large signatures.
            emit("POP ECX");
            emit("ADD ESP, " + to_string(bytes));
            emit("JMP ECX");
        }
    } else emit("RET");
    symbolTable.exitScope();
    currentFunction.clear();
    currentReturnType.clear();
}

any ICGVisitor::visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext* ctx)
{
    bool functionBody = nextCompoundIsFunctionBody;
    nextCompoundIsFunctionBody = false;
    if (!functionBody) symbolTable.enterScope();
    visit(ctx->statements());
    emitLabel(newLabel());
    if (!functionBody) symbolTable.exitScope();
    return {};
}
any ICGVisitor::visitCompoundEmpty(CSubsetParser::CompoundEmptyContext*)
{
    nextCompoundIsFunctionBody = false;
    return {};
}

void ICGVisitor::declareVariable(const string& name, int count, bool array, int sourceLine)
{
    if (currentDeclarationType != "int")
        throw runtime_error("Line " + to_string(sourceLine) + ": Variables must have type int; floating-point code generation is not supported");
    if (count <= 0 || count > numeric_limits<int>::max() / 4)
        throw runtime_error("Line " + to_string(sourceLine) + ": Invalid array size");
    auto symbol = symbolTable.insertAndGet(name, "ID");
    if (!symbol) throw runtime_error("Line " + to_string(sourceLine) + ": Duplicate declaration of '" + name + "'");
    symbol->setDataType("int");
    symbol->setArray(array);
    StorageInfo storage;
    storage.name = assemblyName(name);
    storage.array = array;
    storage.count = count;
    storage.sourceLine = sourceLine;
    if (currentFunction.empty()) {
        storage.global = true;
        globals.push_back(storage);
    } else {
        if (nextLocalOffset > numeric_limits<int>::max() - count * 4)
            throw runtime_error("Function stack frame is too large");
        nextLocalOffset += count * 4;
        storage.offset = -nextLocalOffset;
        frames.back().allocations.push_back(count * 4);
    }
    storageOfSymbol[symbol] = storage;
}

StorageInfo ICGVisitor::lookupStorage(const string& name) const
{
    auto symbol = symbolTable.lookUp(name);
    if (!symbol || symbol->isFunction())
        throw runtime_error("Line " + to_string(currentExpressionLine) + ": Undeclared variable '" + name + "'");
    return storageOfSymbol.at(symbol);
}
any ICGVisitor::visitVar_declaration(CSubsetParser::Var_declarationContext* ctx)
{
    currentDeclarationType = ctx->type_specifier()->getText();
    visit(ctx->declaration_list());
    return {};
}
any ICGVisitor::visitDeclarationScalarSingle(CSubsetParser::DeclarationScalarSingleContext* ctx)
{
    declareVariable(ctx->ID()->getText(), 1, false, ctx->getStart()->getLine());
    return {};
}
any ICGVisitor::visitDeclarationScalarAppend(CSubsetParser::DeclarationScalarAppendContext* ctx)
{
    visit(ctx->previous);
    declareVariable(ctx->ID()->getText(), 1, false, ctx->ID()->getSymbol()->getLine());
    return {};
}
any ICGVisitor::visitDeclarationArraySingle(CSubsetParser::DeclarationArraySingleContext* ctx)
{
    declareVariable(ctx->ID()->getText(), stoi(ctx->CONST_INT()->getText()), true, ctx->getStart()->getLine());
    return {};
}
any ICGVisitor::visitDeclarationArrayAppend(CSubsetParser::DeclarationArrayAppendContext* ctx)
{
    visit(ctx->previous);
    declareVariable(ctx->ID()->getText(), stoi(ctx->CONST_INT()->getText()), true, ctx->ID()->getSymbol()->getLine());
    return {};
}

any ICGVisitor::visitStatementsSingle(CSubsetParser::StatementsSingleContext* ctx)
{
    return visit(ctx->statement());
}
any ICGVisitor::visitStatementsMultiple(CSubsetParser::StatementsMultipleContext* ctx)
{
    visit(ctx->previous);
    emitLabel(newLabel());
    return visit(ctx->current);
}
any ICGVisitor::visitExpressionStatementNormal(CSubsetParser::ExpressionStatementNormalContext* ctx)
{
    annotate(ctx);
    valueOnStack = false;
    visit(ctx->expression());
    materialize(false);
    return {};
}
any ICGVisitor::visitExpressionStatementEmpty(CSubsetParser::ExpressionStatementEmptyContext*) { return {}; }
any ICGVisitor::visitStatementPrintln(CSubsetParser::StatementPrintlnContext* ctx)
{
    annotate(ctx);
    auto storage = lookupStorage(ctx->ID()->getText());
    if (storage.array) fail(ctx, "println requires a scalar variable");
    emitAtLine("MOV EAX, " + memory(storage), currentExpressionLine);
    emit("PUSH EAX");
    emit("CALL print_number");
    emit("ADD ESP, 4");
    return {};
}
any ICGVisitor::visitStatementReturn(CSubsetParser::StatementReturnContext* ctx)
{
    annotate(ctx);
    if (currentReturnType != "int") fail(ctx, "A void function cannot return a value");
    requireInt(ctx->expression());
    emit("JMP " + currentExitLabel);
    return {};
}
any ICGVisitor::visitStatementIf(CSubsetParser::StatementIfContext* ctx)
{
    annotate(ctx);
    string yes = newLabel(), end = newLabel();
    condition(ctx->condition, yes, end);
    emitLabel(yes);
    visit(ctx->thenBranch);
    emitLabel(end);
    return {};
}
any ICGVisitor::visitStatementIfElse(CSubsetParser::StatementIfElseContext* ctx)
{
    annotate(ctx);
    string yes = newLabel(), otherwise = newLabel(), end = newLabel();
    condition(ctx->condition, yes, otherwise);
    emitLabel(yes);
    visit(ctx->thenBranch);
    emit("JMP " + end);
    emitLabel(otherwise);
    visit(ctx->elseBranch);
    emitLabel(end);
    return {};
}
any ICGVisitor::visitStatementWhile(CSubsetParser::StatementWhileContext* ctx)
{
    annotate(ctx);
    string test = newLabel(), yes = newLabel(), end = newLabel();
    emitLabel(test);
    condition(ctx->condition, yes, end);
    emitLabel(yes);
    visit(ctx->body);
    emit("JMP " + test);
    emitLabel(end);
    return {};
}
any ICGVisitor::visitStatementFor(CSubsetParser::StatementForContext* ctx)
{
    annotate(ctx);
    visit(ctx->init);
    string test = newLabel(), update = newLabel(), yes = newLabel(), end = newLabel();
    emitLabel(test);
    auto expression = dynamic_cast<CSubsetParser::ExpressionStatementNormalContext*>(ctx->condition);
    if (expression) condition(expression->expression(), yes, end);
    else { visit(ctx->condition); emit("JMP " + yes); }
    // Match the reference's physical order: condition, update, then loop body.
    emitLabel(update);
    annotate(ctx->update);
    valueOnStack = false;
    visit(ctx->update);
    materialize(false);
    emit("JMP " + test);
    emitLabel(yes);
    visit(ctx->body);
    emit("JMP " + update);
    emitLabel(end);
    return {};
}

// Convert an index in EBX into the reference's byte-offset representation.
void ICGVisitor::arrayOffset(const StorageInfo& storage, bool preserveValue, bool comment)
{
    if (preserveValue) emit("PUSH EAX");
    if (comment) emitAtLine("MOV EAX, 4", currentExpressionLine);
    else emit("MOV EAX, 4");
    emit("MUL EBX");
    emit("MOV EBX, EAX");
    if (!storage.global) {
        emit("MOV EAX, " + to_string(-storage.offset));
        emit("SUB EAX, EBX");
        emit("MOV EBX, EAX");
    }
    if (preserveValue) emit("POP EAX");
    if (!storage.global) { emit("MOV ESI, EBX"); emit("NEG ESI"); }
}

any ICGVisitor::visitVariableScalar(CSubsetParser::VariableScalarContext* ctx)
{
    auto storage = lookupStorage(ctx->ID()->getText());
    if (storage.array) fail(ctx, "Array requires an index");
    emitAtLine("MOV EAX, " + memory(storage), ctx->getStart()->getLine());
    valueOnStack = false;
    return string("int");
}
any ICGVisitor::visitVariableArray(CSubsetParser::VariableArrayContext* ctx)
{
    auto storage = lookupStorage(ctx->ID()->getText());
    if (!storage.array) fail(ctx, "Subscript requires an array");
    requireInt(ctx->index);
    emit("PUSH EAX");
    emit("POP EBX");
    arrayOffset(storage, false, true);
    emit("MOV EAX, " + (storage.global ? "[" + storage.name + "+EBX]" : "[EBP+ESI]"));
    valueOnStack = false;
    return string("int");
}
any ICGVisitor::visitExpressionAssign(CSubsetParser::ExpressionAssignContext* ctx)
{
    if (auto scalar = dynamic_cast<CSubsetParser::VariableScalarContext*>(ctx->variable())) {
        auto storage = lookupStorage(scalar->ID()->getText());
        if (storage.array) fail(ctx, "Array requires an index");
        requireInt(ctx->logic_expression());
        emit("MOV " + memory(storage) + ", EAX");
    } else {
        auto array = dynamic_cast<CSubsetParser::VariableArrayContext*>(ctx->variable());
        auto storage = lookupStorage(array->ID()->getText());
        if (!storage.array) fail(ctx, "Subscript requires an array");
        requireInt(array->index);
        emit("PUSH EAX"); // Save the index across all calls in the RHS.
        requireInt(ctx->logic_expression());
        emit("POP EBX");
        arrayOffset(storage, true, false);
        emit("MOV " + (storage.global ? "[" + storage.name + "+EBX]" : "[EBP+ESI]") + ", EAX");
    }
    emit("PUSH EAX");
    valueOnStack = true;
    return string("int");
}

any ICGVisitor::visitLogicBinary(CSubsetParser::LogicBinaryContext* ctx)
{
    const bool branching = !branchTrue.empty();
    string right = newLabel();
    string yes = branching ? branchTrue : newLabel();
    string end = branching ? "" : newLabel();
    string no = branching ? branchFalse : newLabel();
    if (ctx->LOGICOP()->getText() == "&&") condition(ctx->left, right, no);
    else condition(ctx->left, yes, right);
    emitLabel(right);
    condition(ctx->right, yes, no);
    if (branching) conditionEmitted = true;
    else {
        emitLabel(yes);
        emitAtLine("MOV EAX, 1", currentExpressionLine);
        emit("JMP " + end);
        emitLabel(no);
        emit("MOV EAX, 0");
        emitLabel(end);
    }
    valueOnStack = false;
    return string("int");
}
any ICGVisitor::visitRelBinary(CSubsetParser::RelBinaryContext* ctx)
{
    operands(ctx->left, ctx->right, "EDX");
    emit("CMP EAX, EDX");
    static const unordered_map<string, string> branches = {
        {"<", "JL"}, {"<=", "JLE"}, {">", "JG"}, {">=", "JGE"}, {"==", "JE"}, {"!=", "JNE"}
    };
    const bool branching = !branchTrue.empty();
    string yes = branching ? branchTrue : newLabel();
    string end = branching ? "" : newLabel();
    string no = branching ? branchFalse : newLabel();
    emit(branches.at(ctx->RELOP()->getText()) + " " + yes);
    emit("JMP " + no);
    if (branching) conditionEmitted = true;
    else {
        emitLabel(yes);
        emitAtLine("MOV EAX, 1", currentExpressionLine);
        emit("JMP " + end);
        emitLabel(no);
        emit("MOV EAX, 0");
        emitLabel(end);
    }
    valueOnStack = false;
    return string("int");
}
any ICGVisitor::visitSimpleBinary(CSubsetParser::SimpleBinaryContext* ctx)
{
    operands(ctx->left, ctx->right, "EDX");
    emit(string(ctx->ADDOP()->getText() == "+" ? "ADD" : "SUB") + " EAX, EDX");
    emit("PUSH EAX");
    valueOnStack = true;
    return string("int");
}
any ICGVisitor::visitTermBinary(CSubsetParser::TermBinaryContext* ctx)
{
    operands(ctx->left, ctx->right, "ECX");
    string op = ctx->MULOP()->getText();
    // MUL's low 32 bits also give the signed product. Its high half is unused.
    // Division needs CDQ/IDIV: CWD/DIV is incorrect for signed 32-bit operands.
    emit(op == "*" ? "CWD" : "CDQ");
    emit(op == "*" ? "MUL ECX" : "IDIV ECX");
    emit(op == "%" ? "PUSH EDX" : "PUSH EAX");
    valueOnStack = true;
    return string("int");
}
any ICGVisitor::visitUnaryAdd(CSubsetParser::UnaryAddContext* ctx)
{
    requireInt(ctx->operand);
    if (ctx->ADDOP()->getText() == "-") emit("NEG EAX");
    emit("PUSH EAX");
    valueOnStack = true;
    return string("int");
}
any ICGVisitor::visitUnaryNot(CSubsetParser::UnaryNotContext* ctx)
{
    if (!branchTrue.empty()) {
        condition(ctx->operand, branchFalse, branchTrue);
        conditionEmitted = true;
    } else {
        string yes = newLabel(), end = newLabel(), no = newLabel();
        condition(ctx->operand, no, yes);
        emitLabel(yes);
        emitAtLine("MOV EAX, 1", currentExpressionLine);
        emit("JMP " + end);
        emitLabel(no);
        emit("MOV EAX, 0");
        emitLabel(end);
    }
    valueOnStack = false;
    return string("int");
}
any ICGVisitor::visitFactorInt(CSubsetParser::FactorIntContext* ctx)
{
    auto literal = stoull(ctx->CONST_INT()->getText());
    if (literal > 0xffffffffULL) fail(ctx, "Integer literal does not fit in 32 bits");
    emitAtLine("MOV EAX, " + to_string(literal), ctx->getStart()->getLine());
    return string("int");
}
any ICGVisitor::visitFactorFloat(CSubsetParser::FactorFloatContext* ctx)
{
    fail(ctx, "Floating-point code generation is not required by the assignment");
}
void ICGVisitor::postfix(CSubsetParser::VariableContext* ctx, const string& instruction)
{
    if (auto scalar = dynamic_cast<CSubsetParser::VariableScalarContext*>(ctx)) {
        auto storage = lookupStorage(scalar->ID()->getText());
        if (storage.array) fail(ctx, "Array requires an index");
        emitAtLine("MOV EAX, " + memory(storage), currentExpressionLine);
        emit("PUSH EAX");
        emit(instruction + " EAX");
        emit("MOV " + memory(storage) + ", EAX");
    } else {
        auto array = dynamic_cast<CSubsetParser::VariableArrayContext*>(ctx);
        auto storage = lookupStorage(array->ID()->getText());
        if (!storage.array) fail(ctx, "Subscript requires an array");
        requireInt(array->index);
        // ECX keeps the once-evaluated index; offset generation never changes it.
        emit("PUSH EAX");
        emit("POP ECX");
        emit("PUSH ECX");
        emit("POP EBX");
        arrayOffset(storage, false, true);
        const string location = storage.global ? "[" + storage.name + "+EBX]" : "[EBP+ESI]";
        emit("MOV EAX, " + location);
        emit("PUSH EAX");
        emit(instruction + " EAX");
        emit("PUSH ECX");
        emit("POP EBX");
        arrayOffset(storage, true, false);
        emit("MOV " + location + ", EAX");
    }
    valueOnStack = true;
}
any ICGVisitor::visitFactorIncrement(CSubsetParser::FactorIncrementContext* ctx)
{
    postfix(ctx->variable(), "INC");
    return string("int");
}
any ICGVisitor::visitFactorDecrement(CSubsetParser::FactorDecrementContext* ctx)
{
    postfix(ctx->variable(), "DEC");
    return string("int");
}
any ICGVisitor::visitArgumentListEmpty(CSubsetParser::ArgumentListEmptyContext*) { return size_t(0); }
any ICGVisitor::visitArgumentListNonEmpty(CSubsetParser::ArgumentListNonEmptyContext* ctx)
{
    return visit(ctx->arguments());
}
any ICGVisitor::visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext* ctx)
{
    requireInt(ctx->current);
    emit("PUSH EAX");
    return size_t(1);
}
any ICGVisitor::visitArgumentsMultiple(CSubsetParser::ArgumentsMultipleContext* ctx)
{
    size_t count = any_cast<size_t>(visit(ctx->previous));
    requireInt(ctx->current);
    emit("PUSH EAX");
    return count + 1;
}
any ICGVisitor::visitFactorFunctionCall(CSubsetParser::FactorFunctionCallContext* ctx)
{
    string name = ctx->ID()->getText();
    auto symbol = symbolTable.lookUp(name);
    if (!symbol || !symbol->isFunction()) fail(ctx, "Undeclared function '" + name + "'");
    size_t count = any_cast<size_t>(visit(ctx->argument_list()));
    if (count != symbol->getParameterTypes().size()) fail(ctx, "Wrong number of arguments to '" + name + "'");
    calledFunctions.insert(name);
    emitAtLine("CALL " + assemblyName(name), ctx->getStart()->getLine());
    emit("PUSH EAX");
    valueOnStack = true;
    return symbol->getReturnType();
}
