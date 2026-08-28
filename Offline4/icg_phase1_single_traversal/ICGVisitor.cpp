#include "ICGVisitor.h"

#include <cstdio>
#include <stdexcept>

using namespace std;

ICGVisitor::ICGVisitor(const string& outputFile)
    : outputFile(outputFile),
      temporaryFile(outputFile + ".tmp"),
      currentDeclarationType("error"),
      nextLocalOffset(0),
      labelCounter(1),
      currentExpressionLine(0),
      nextCompoundIsFunctionBody(false)
{
    body.open(temporaryFile, ios::trunc);
    if (!body) {
        throw runtime_error("Could not create " + temporaryFile);
    }

    // Root/global scope.
    symbolTable.enterScope();
}

ICGVisitor::~ICGVisitor()
{
    if (body.is_open()) {
        body.close();
    }
    if (out.is_open()) {
        out.close();
    }
    remove(temporaryFile.c_str());
}

void ICGVisitor::emit(const string& instruction)
{
    body << '\t' << instruction << '\n';
}

void ICGVisitor::emitAtLine(const string& instruction, int sourceLine)
{
    body << '\t' << instruction;
    if (sourceLine > 0) {
        body << "       ; Line " << sourceLine;
    }
    body << '\n';
}

void ICGVisitor::emitLabel(const string& label)
{
    body << label << ":\n";
}

void ICGVisitor::emitStatementLabel()
{
    emitLabel(newLabel(""));
}

string ICGVisitor::newLabel(const string& prefix)
{
    (void)prefix;
    return ".L" + to_string(labelCounter++);
}

string ICGVisitor::replaceAll(
    string text,
    const string& needle,
    const string& replacement) const
{
    size_t position = 0;
    while ((position = text.find(needle, position)) != string::npos) {
        text.replace(position, needle.size(), replacement);
        position += replacement.size();
    }
    return text;
}

string ICGVisitor::memory(const StorageInfo& storage) const
{
    if (storage.global) {
        return "[" + storage.name + "]";
    }

    return "[EBP-" + to_string(storage.offset) + "]";
}

void ICGVisitor::load(const StorageInfo& storage)
{
    emitAtLine("MOV EAX, " + memory(storage), currentExpressionLine);
}

void ICGVisitor::store(const StorageInfo& storage)
{
    emit("MOV " + memory(storage) + ", EAX");
}

void ICGVisitor::writeHeader()
{
    out << "format ELF executable 3\n";
    out << "entry main\n";
}

void ICGVisitor::writePrintProcedure()
{
    out << ";-------------------------------\n";
    out << ";         print library         \n";
    out << ";-------------------------------\n";

    // getline removes only '\n'. If printProc.lib uses CRLF, its '\r' is
    // deliberately retained so the generated text matches the reference.
    ifstream library("printProc.lib");
    if (!library) {
        throw runtime_error("Could not open printProc.lib");
    }

    string line;
    while (getline(library, line)) {
        out << line << '\n';
    }
    out << ";-------------------------------\n";
}

void ICGVisitor::writeDataSegment()
{
    out << "segment readable writeable\n";

    for (const StorageInfo& variable : globals) {
        out << '\t' << variable.name << " dd 1 DUP (0)"
            << "       ; Line " << variable.sourceLine << '\n';
    }
}

void ICGVisitor::generate(antlr4::tree::ParseTree* tree)
{
    // This is the ONLY traversal of the parse tree.
    visit(tree);

    body.flush();
    body.close();

    out.open(outputFile, ios::trunc);
    if (!out) {
        throw runtime_error("Could not create " + outputFile);
    }

    // Assembly is buffered during the single traversal so declarations can be
    // placed before the executable segment, as required by the reference.
    writeHeader();
    writeDataSegment();
    out << "segment readable executable\n";

    ifstream generatedBody(temporaryFile);
    if (!generatedBody) {
        throw runtime_error("Could not open " + temporaryFile);
    }

    string line;
    while (getline(generatedBody, line)) {
        for (const auto& replacement : exitReplacements) {
            line = replaceAll(line, replacement.first, replacement.second);
        }
        out << line << '\n';
    }

    writePrintProcedure();
    out.flush();
    generatedBody.close();
    remove(temporaryFile.c_str());
}

// -----------------------------------------------------------------------------
// Symbol-table / storage helpers
// -----------------------------------------------------------------------------

void ICGVisitor::installFunction(
    CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx)
{
    string name = ctx->ID()->getText();

    SymbolInfo* symbol = symbolTable.lookUpCurrent(name);
    if (symbol == nullptr) {
        symbol = symbolTable.insertAndGet(name, "ID");
    }

    if (symbol == nullptr) {
        throw runtime_error("Could not insert function '" + name + "'");
    }

    symbol->setFunction(true);
    symbol->setDefinedFunction(true);
    symbol->setReturnType(ctx->type_specifier()->getText());
    symbol->setParameterTypes(vector<string>());
}

void ICGVisitor::declareScalar(const string& name, int sourceLine)
{
    // Phase 1 highlights scalar declarations only. FLOAT type_specifier itself
    // is not a Phase-1 production, and a void variable is semantically invalid.
    if (currentDeclarationType != "int") {
        throw runtime_error(
            "Phase-1 ICG supports only int scalar variable declarations");
    }

    SymbolInfo* symbol = symbolTable.insertAndGet(name, "ID");
    if (symbol == nullptr) {
        throw runtime_error("Duplicate declaration of '" + name + "'");
    }

    symbol->setDataType("int");
    symbol->setArray(false);
    symbol->setFunction(false);

    StorageInfo storage;
    storage.name = name;
    storage.sourceLine = sourceLine;

    if (currentFunction.empty()) {
        storage.global = true;
        globals.push_back(storage);
    }
    else {
        // Allocate every local as soon as its declaration is visited. This
        // preserves the single parse-tree traversal required by Phase 1.
        nextLocalOffset += 4;
        storage.global = false;
        storage.offset = nextLocalOffset;

        emitAtLine("SUB ESP, 4", sourceLine);
    }

    storageOfSymbol[symbol] = storage;
}

StorageInfo ICGVisitor::lookupStorage(const string& name) const
{
    SymbolInfo* symbol = symbolTable.lookUp(name);
    if (symbol == nullptr) {
        throw runtime_error("Variable '" + name + "' was not found");
    }

    auto it = storageOfSymbol.find(symbol);
    if (it == storageOfSymbol.end()) {
        throw runtime_error("'" + name + "' is not a Phase-1 scalar variable");
    }

    return it->second;
}

// -----------------------------------------------------------------------------
// Function / scopes
// -----------------------------------------------------------------------------

any ICGVisitor::visitFunctionDefinitionWithoutParameters(
    CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx)
{
    installFunction(ctx);

    string oldFunction = currentFunction;
    string oldExitLabel = currentExitLabel;
    string oldExitPlaceholder = currentExitPlaceholder;
    int oldLocalOffset = nextLocalOffset;

    currentFunction = ctx->ID()->getText();
    currentExitLabel.clear();
    currentExitPlaceholder = "__" + currentFunction + "_EXIT__";
    nextLocalOffset = 0;

    emitLabel(currentFunction);
    emit("PUSH EBP");
    emit("MOV EBP, ESP");

    // The function body itself uses this scope. Nested compound statements
    // create their own child scopes.
    symbolTable.enterScope();
    nextCompoundIsFunctionBody = true;
    visit(ctx->compound_statement());

    string fallthroughLabel = newLabel("");
    currentExitLabel = newLabel("");
    emitLabel(fallthroughLabel);
    emitLabel(currentExitLabel);
    if (nextLocalOffset > 0) {
        emit("ADD ESP, " + to_string(nextLocalOffset));
    }
    emit("POP EBP");

    if (currentFunction == "main") {
        // Linux i386 sys_exit takes the status in EBX. Preserve the source
        // program's return expression before loading the syscall number.
        emit("MOV EBX, EAX");
        emit("MOV EAX, 1");
        emit("INT 0x80");
    }
    else {
        emit("RET");
    }

    exitReplacements.push_back({currentExitPlaceholder, currentExitLabel});

    symbolTable.exitScope();

    currentFunction = oldFunction;
    currentExitLabel = oldExitLabel;
    currentExitPlaceholder = oldExitPlaceholder;
    nextLocalOffset = oldLocalOffset;

    return {};
}

any ICGVisitor::visitCompoundWithStatements(
    CSubsetParser::CompoundWithStatementsContext* ctx)
{
    bool functionBody = nextCompoundIsFunctionBody;
    nextCompoundIsFunctionBody = false;

    if (!functionBody) {
        symbolTable.enterScope();
    }

    visit(ctx->statements());

    if (!functionBody) {
        // Local slots remain allocated until the function epilogue.
        symbolTable.exitScope();
    }

    return {};
}

any ICGVisitor::visitCompoundEmpty(
    CSubsetParser::CompoundEmptyContext* ctx)
{
    bool functionBody = nextCompoundIsFunctionBody;
    nextCompoundIsFunctionBody = false;

    if (!functionBody) {
        symbolTable.enterScope();
        symbolTable.exitScope();
    }

    (void)ctx;
    return {};
}

// -----------------------------------------------------------------------------
// Declarations
// -----------------------------------------------------------------------------

any ICGVisitor::visitVar_declaration(
    CSubsetParser::Var_declarationContext* ctx)
{
    string oldType = currentDeclarationType;
    currentDeclarationType = ctx->type_specifier()->getText();

    visit(ctx->declaration_list());
    currentDeclarationType = oldType;

    return {};
}

any ICGVisitor::visitDeclarationScalarSingle(
    CSubsetParser::DeclarationScalarSingleContext* ctx)
{
    declareScalar(ctx->ID()->getText(), ctx->ID()->getSymbol()->getLine());
    return {};
}

any ICGVisitor::visitDeclarationScalarAppend(
    CSubsetParser::DeclarationScalarAppendContext* ctx)
{
    // declaration_list is left-recursive: declare old items before the new ID.
    visit(ctx->previous);
    declareScalar(ctx->ID()->getText(), ctx->ID()->getSymbol()->getLine());
    return {};
}

// -----------------------------------------------------------------------------
// Statements
// -----------------------------------------------------------------------------

any ICGVisitor::visitExpressionStatementNormal(
    CSubsetParser::ExpressionStatementNormalContext* ctx)
{
    emitStatementLabel();
    int oldLine = currentExpressionLine;
    currentExpressionLine = ctx->getStart()->getLine();
    visit(ctx->expression());
    currentExpressionLine = oldLine;
    return {};
}

any ICGVisitor::visitExpressionStatementEmpty(
    CSubsetParser::ExpressionStatementEmptyContext* ctx)
{
    (void)ctx;
    return {};
}

any ICGVisitor::visitStatementPrintln(
    CSubsetParser::StatementPrintlnContext* ctx)
{
    emitStatementLabel();
    int oldLine = currentExpressionLine;
    currentExpressionLine = ctx->getStart()->getLine();

    StorageInfo storage = lookupStorage(ctx->ID()->getText());
    load(storage);

    // printProc.lib expects the integer to print in EAX.
    emit("CALL print_number");
    currentExpressionLine = oldLine;
    return {};
}

any ICGVisitor::visitStatementReturn(
    CSubsetParser::StatementReturnContext* ctx)
{
    emitStatementLabel();
    int oldLine = currentExpressionLine;
    currentExpressionLine = ctx->getStart()->getLine();
    visit(ctx->expression());
    emit("JMP " + currentExitPlaceholder);
    currentExpressionLine = oldLine;
    return {};
}

// -----------------------------------------------------------------------------
// Variable and assignment
// -----------------------------------------------------------------------------

any ICGVisitor::visitVariableScalar(
    CSubsetParser::VariableScalarContext* ctx)
{
    StorageInfo storage = lookupStorage(ctx->ID()->getText());
    load(storage);
    return {};
}

any ICGVisitor::visitExpressionAssign(
    CSubsetParser::ExpressionAssignContext* ctx)
{
    // Only evaluate the right side; loading the old left-side value is not
    // required for assignment.
    StorageInfo left = lookupStorage(ctx->variable()->getText());

    visit(ctx->logic_expression());
    store(left);
    emit("PUSH EAX");
    emit("POP EAX");

    // EAX still contains the assigned value.
    return {};
}

// -----------------------------------------------------------------------------
// Boolean expressions
// -----------------------------------------------------------------------------

any ICGVisitor::visitLogicBinary(CSubsetParser::LogicBinaryContext* ctx)
{
    string op = ctx->LOGICOP()->getText();
    string rightLabel = newLabel("");
    string trueLabel = newLabel("");
    string endLabel = newLabel("");
    string falseLabel = newLabel("");

    if (op == "&&") {
        visit(ctx->left);
        emit("CMP EAX, 0");
        emit("JNE " + rightLabel);
        emit("JMP " + falseLabel);
        emitLabel(rightLabel);
        visit(ctx->right);
        emit("CMP EAX, 0");
        emit("JNE " + trueLabel);
        emit("JMP " + falseLabel);
    }
    else {
        visit(ctx->left);
        emit("CMP EAX, 0");
        emit("JNE " + trueLabel);
        emit("JMP " + rightLabel);
        emitLabel(rightLabel);
        visit(ctx->right);
        emit("CMP EAX, 0");
        emit("JNE " + trueLabel);
        emit("JMP " + falseLabel);
    }

    emitLabel(trueLabel);
    emitAtLine("MOV EAX, 1", currentExpressionLine);
    emit("JMP " + endLabel);
    emitLabel(falseLabel);
    emit("MOV EAX, 0");
    emitLabel(endLabel);
    return {};
}

any ICGVisitor::visitRelBinary(CSubsetParser::RelBinaryContext* ctx)
{
    visit(ctx->left);
    emit("PUSH EAX");
    visit(ctx->right);
    emit("MOV EDX, EAX");
    emit("POP EAX");
    emit("CMP EAX, EDX");

    string op = ctx->RELOP()->getText();
    string trueLabel = newLabel("");
    string endLabel = newLabel("");
    string falseLabel = newLabel("");

    if (op == "<")       emit("JL "  + trueLabel);
    else if (op == "<=") emit("JLE " + trueLabel);
    else if (op == ">")  emit("JG "  + trueLabel);
    else if (op == ">=") emit("JGE " + trueLabel);
    else if (op == "==") emit("JE "  + trueLabel);
    else if (op == "!=") emit("JNE " + trueLabel);

    emit("JMP " + falseLabel);
    emitLabel(trueLabel);
    emitAtLine("MOV EAX, 1", currentExpressionLine);
    emit("JMP " + endLabel);
    emitLabel(falseLabel);
    emit("MOV EAX, 0");
    emitLabel(endLabel);

    return {};
}

// -----------------------------------------------------------------------------
// Arithmetic expressions
// -----------------------------------------------------------------------------

any ICGVisitor::visitSimpleBinary(CSubsetParser::SimpleBinaryContext* ctx)
{
    visit(ctx->left);
    emit("PUSH EAX");
    visit(ctx->right);
    emit("MOV EDX, EAX");
    emit("POP EAX");

    if (ctx->ADDOP()->getText() == "+") {
        emit("ADD EAX, EDX");
    }
    else {
        emit("SUB EAX, EDX");
    }
    emit("PUSH EAX");
    emitAtLine("POP EAX", currentExpressionLine);

    return {};
}

any ICGVisitor::visitTermBinary(CSubsetParser::TermBinaryContext* ctx)
{
    visit(ctx->left);
    emit("PUSH EAX");
    visit(ctx->right);
    emit("MOV ECX, EAX");
    emit("POP EAX");

    string op = ctx->MULOP()->getText();

    if (op == "*") {
        emit("IMUL EAX, ECX");
        emit("PUSH EAX");
    }
    else {
        emit("CDQ");
        emit("IDIV ECX");
        emit(op == "%" ? "PUSH EDX" : "PUSH EAX");
    }
    emitAtLine("POP EAX", currentExpressionLine);

    return {};
}

any ICGVisitor::visitUnaryAdd(CSubsetParser::UnaryAddContext* ctx)
{
    visit(ctx->operand);

    if (ctx->ADDOP()->getText() == "-") {
        emit("NEG EAX");
    }

    emit("PUSH EAX");
    emitAtLine("POP EAX", currentExpressionLine);
    return {};
}

any ICGVisitor::visitUnaryNot(CSubsetParser::UnaryNotContext* ctx)
{
    visit(ctx->operand);

    string trueLabel = newLabel("");
    string endLabel = newLabel("");
    string falseLabel = newLabel("");

    emit("CMP EAX, 0");
    emit("JE " + trueLabel);
    emit("JMP " + falseLabel);
    emitLabel(trueLabel);
    emitAtLine("MOV EAX, 1", currentExpressionLine);
    emit("JMP " + endLabel);
    emitLabel(falseLabel);
    emit("MOV EAX, 0");
    emitLabel(endLabel);

    return {};
}

// -----------------------------------------------------------------------------
// Factors
// -----------------------------------------------------------------------------

any ICGVisitor::visitFactorInt(CSubsetParser::FactorIntContext* ctx)
{
    emitAtLine(
        "MOV EAX, " + ctx->CONST_INT()->getText(),
        currentExpressionLine);
    return {};
}

any ICGVisitor::visitFactorFloat(CSubsetParser::FactorFloatContext* ctx)
{
    // Floating-point code generation is outside the Phase-1 requirements.
    throw runtime_error(
        "Floating-point code generation is not required by the assignment");

    (void)ctx;
    return {};
}

any ICGVisitor::visitFactorIncrement(CSubsetParser::FactorIncrementContext* ctx)
{
    StorageInfo storage = lookupStorage(ctx->variable()->getText());

    // Postfix semantics: EAX keeps the old value while memory gets old + 1.
    load(storage);
    emit("PUSH EAX");
    emit("INC EAX");
    store(storage);
    emit("POP EAX");
    return {};
}

any ICGVisitor::visitFactorDecrement(CSubsetParser::FactorDecrementContext* ctx)
{
    StorageInfo storage = lookupStorage(ctx->variable()->getText());

    // Postfix semantics: EAX keeps the old value while memory gets old - 1.
    load(storage);
    emit("PUSH EAX");
    emit("DEC EAX");
    store(storage);
    emit("POP EAX");
    return {};
}
