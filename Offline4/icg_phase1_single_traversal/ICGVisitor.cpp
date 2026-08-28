#include "ICGVisitor.h"

#include <stdexcept>

using namespace std;

ICGVisitor::ICGVisitor(const string& outputFile)
    : currentDeclarationType("error"),
      nextLocalOffset(0),
      labelCounter(0),
      nextCompoundIsFunctionBody(false)
{
    out.open(outputFile, ios::trunc);
    if (!out) {
        throw runtime_error("Could not create " + outputFile);
    }

    // Root/global scope.
    symbolTable.enterScope();
}

ICGVisitor::~ICGVisitor()
{
    if (out.is_open()) {
        out.close();
    }
}

void ICGVisitor::emit(const string& instruction)
{
    out << "    " << instruction << '\n';
}

void ICGVisitor::emitRaw(const string& text)
{
    out << text << '\n';
}

void ICGVisitor::emitLabel(const string& label)
{
    out << label << ":\n";
}

void ICGVisitor::emitLineComment(antlr4::ParserRuleContext* ctx)
{
    out << "    ; Line " << ctx->getStart()->getLine() << '\n';
}

string ICGVisitor::newLabel(const string& prefix)
{
    return "L_" + prefix + "_" + to_string(labelCounter++);
}

string ICGVisitor::memory(const StorageInfo& storage) const
{
    if (storage.global) {
        return "[" + storage.name + "]";
    }

    return "[ebp-" + to_string(storage.offset) + "]";
}

void ICGVisitor::load(const StorageInfo& storage)
{
    emit("mov eax, " + memory(storage));
}

void ICGVisitor::store(const StorageInfo& storage)
{
    emit("mov " + memory(storage) + ", eax");
}

void ICGVisitor::writeHeader()
{
    emitRaw("format ELF executable 3");
    emitRaw("entry _start");
    emitRaw();
    emitRaw("segment readable executable");
    emitRaw();

    emitLabel("_start");
    emit("call main");
    emit("mov ebx, eax");
    emit("mov eax, 1");
    emit("int 0x80");
    emitRaw();
}

void ICGVisitor::writePrintProcedureInclude()
{
    emitRaw();
    emitRaw("; println helper supplied with the assignment/project");
    emitRaw("include 'printProc.lib'");
}

void ICGVisitor::writeDataSegment()
{
    if (globals.empty()) {
        return;
    }

    emitRaw();
    emitRaw("segment readable writeable");

    for (const StorageInfo& variable : globals) {
        emitRaw("    ; Line " + to_string(variable.sourceLine));
        emitRaw(variable.name + " dd 0");
    }
}

void ICGVisitor::generate(antlr4::tree::ParseTree* tree)
{
    writeHeader();

    // This is the ONLY traversal of the parse tree.
    visit(tree);

    // These are appended after traversal. We do not walk the parse tree again.
    writePrintProcedureInclude();
    writeDataSegment();
    out.flush();
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
        // IMPORTANT FOR THE SINGLE TRAVERSAL:
        // Allocate each local exactly when its declaration is visited. Therefore
        // we do not need an earlier tree pass to count all local variables.
        nextLocalOffset += 4;
        storage.global = false;
        storage.offset = nextLocalOffset;

        emit("sub esp, 4");
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
    int oldLocalOffset = nextLocalOffset;

    currentFunction = ctx->ID()->getText();
    currentExitLabel = newLabel(currentFunction + "_exit");
    nextLocalOffset = 0;

    emitRaw();
    emitRaw("; Line " + to_string(ctx->getStart()->getLine()) + ": function " + currentFunction);
    emitLabel(currentFunction);
    emit("push ebp");
    emit("mov ebp, esp");

    // The function body itself uses this scope. Nested compound statements
    // create their own child scopes.
    symbolTable.enterScope();
    nextCompoundIsFunctionBody = true;
    visit(ctx->compound_statement());

    emitLabel(currentExitLabel);
    emit("mov esp, ebp");
    emit("pop ebp");
    emit("ret");

    symbolTable.exitScope();

    currentFunction = oldFunction;
    currentExitLabel = oldExitLabel;
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
        // We intentionally do NOT emit "add esp, ..." here. Local slots are
        // kept until the function epilogue. This keeps one-pass stack layout
        // simple and still stores every local through the stack as required.
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

    // For globals the actual dd declarations are emitted later in the data
    // segment, so no executable line comment is needed here.
    if (!currentFunction.empty()) {
        emitLineComment(ctx);
    }

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
    emitLineComment(ctx);
    visit(ctx->expression());
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
    emitLineComment(ctx);

    StorageInfo storage = lookupStorage(ctx->ID()->getText());
    load(storage);

    // printProc.lib expects the integer to print in EAX.
    emit("call print_number");
    return {};
}

any ICGVisitor::visitStatementReturn(
    CSubsetParser::StatementReturnContext* ctx)
{
    emitLineComment(ctx);
    visit(ctx->expression());          // result -> EAX
    emit("jmp " + currentExitLabel);
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
    // Do not visit the left variable: that would unnecessarily load its old
    // value. Only evaluate the RHS, then store EAX into the LHS.
    StorageInfo left = lookupStorage(ctx->variable()->getText());

    visit(ctx->logic_expression());
    store(left);

    // EAX still contains the assigned value.
    return {};
}

// -----------------------------------------------------------------------------
// Boolean expressions
// -----------------------------------------------------------------------------

any ICGVisitor::visitLogicBinary(CSubsetParser::LogicBinaryContext* ctx)
{
    string op = ctx->LOGICOP()->getText();
    string shortLabel = newLabel(op == "&&" ? "and_false" : "or_true");
    string endLabel = newLabel("logic_end");

    visit(ctx->left);
    emit("cmp eax, 0");

    if (op == "&&") {
        // Short circuit: if left is false, right is not evaluated.
        emit("je " + shortLabel);

        visit(ctx->right);
        emit("cmp eax, 0");
        emit("je " + shortLabel);

        emit("mov eax, 1");
        emit("jmp " + endLabel);

        emitLabel(shortLabel);
        emit("mov eax, 0");
    }
    else {
        // Short circuit: if left is true, right is not evaluated.
        emit("jne " + shortLabel);

        visit(ctx->right);
        emit("cmp eax, 0");
        emit("jne " + shortLabel);

        emit("mov eax, 0");
        emit("jmp " + endLabel);

        emitLabel(shortLabel);
        emit("mov eax, 1");
    }

    emitLabel(endLabel);
    return {};
}

any ICGVisitor::visitRelBinary(CSubsetParser::RelBinaryContext* ctx)
{
    visit(ctx->left);
    emit("push eax");

    visit(ctx->right);
    emit("mov ebx, eax");
    emit("pop eax");
    emit("cmp eax, ebx");

    string op = ctx->RELOP()->getText();
    string trueLabel = newLabel("rel_true");
    string endLabel = newLabel("rel_end");

    if (op == "<")       emit("jl "  + trueLabel);
    else if (op == "<=") emit("jle " + trueLabel);
    else if (op == ">")  emit("jg "  + trueLabel);
    else if (op == ">=") emit("jge " + trueLabel);
    else if (op == "==") emit("je "  + trueLabel);
    else if (op == "!=") emit("jne " + trueLabel);

    emit("mov eax, 0");
    emit("jmp " + endLabel);
    emitLabel(trueLabel);
    emit("mov eax, 1");
    emitLabel(endLabel);

    return {};
}

// -----------------------------------------------------------------------------
// Arithmetic expressions
// -----------------------------------------------------------------------------

any ICGVisitor::visitSimpleBinary(CSubsetParser::SimpleBinaryContext* ctx)
{
    visit(ctx->left);
    emit("push eax");

    visit(ctx->right);
    emit("mov ebx, eax");
    emit("pop eax");

    if (ctx->ADDOP()->getText() == "+") {
        emit("add eax, ebx");
    }
    else {
        emit("sub eax, ebx");
    }

    return {};
}

any ICGVisitor::visitTermBinary(CSubsetParser::TermBinaryContext* ctx)
{
    visit(ctx->left);
    emit("push eax");

    visit(ctx->right);
    emit("mov ebx, eax");
    emit("pop eax");

    string op = ctx->MULOP()->getText();

    if (op == "*") {
        emit("imul eax, ebx");
    }
    else {
        // Signed division: EDX:EAX / EBX
        emit("cdq");
        emit("idiv ebx");

        if (op == "%") {
            emit("mov eax, edx");
        }
    }

    return {};
}

any ICGVisitor::visitUnaryAdd(CSubsetParser::UnaryAddContext* ctx)
{
    visit(ctx->operand);

    if (ctx->ADDOP()->getText() == "-") {
        emit("neg eax");
    }

    // Unary + needs no instruction.
    return {};
}

any ICGVisitor::visitUnaryNot(CSubsetParser::UnaryNotContext* ctx)
{
    visit(ctx->operand);

    string trueLabel = newLabel("not_true");
    string endLabel = newLabel("not_end");

    emit("cmp eax, 0");
    emit("je " + trueLabel);
    emit("mov eax, 0");
    emit("jmp " + endLabel);
    emitLabel(trueLabel);
    emit("mov eax, 1");
    emitLabel(endLabel);

    return {};
}

// -----------------------------------------------------------------------------
// Factors
// -----------------------------------------------------------------------------

any ICGVisitor::visitFactorInt(CSubsetParser::FactorIntContext* ctx)
{
    emit("mov eax, " + ctx->CONST_INT()->getText());
    return {};
}

any ICGVisitor::visitFactorFloat(CSubsetParser::FactorFloatContext* ctx)
{
    // CONST_FLOAT is highlighted in the Phase-1 grammar, but the assignment
    // specification explicitly says floating-point operations are not required.
    throw runtime_error(
        "Floating-point code generation is not required by the assignment");

    (void)ctx;
    return {};
}

any ICGVisitor::visitFactorIncrement(CSubsetParser::FactorIncrementContext* ctx)
{
    StorageInfo storage = lookupStorage(ctx->variable()->getText());

    // Postfix semantics: EAX keeps the OLD value.
    load(storage);
    emit("inc dword " + memory(storage));
    return {};
}

any ICGVisitor::visitFactorDecrement(CSubsetParser::FactorDecrementContext* ctx)
{
    StorageInfo storage = lookupStorage(ctx->variable()->getText());

    // Postfix semantics: EAX keeps the OLD value.
    load(storage);
    emit("dec dword " + memory(storage));
    return {};
}
