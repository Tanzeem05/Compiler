#ifndef ICG_VISITOR_H
#define ICG_VISITOR_H

#include "2205163_symbol_table.hpp"
#include "CSubsetBaseVisitor.h"
#include "CSubsetParser.h"
#include "antlr4-runtime.h"

#include <any>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Where a scalar variable lives in the generated assembly.
struct StorageInfo {
    string name;
    bool global = false;
    int offset = 0;      // local variable => [ebp-offset]
    int sourceLine = 0;
};

// One parse-tree traversal only.
// The parse tree itself is created by ANTLR before this visitor is run.
class ICGVisitor : public CSubsetBaseVisitor {
public:
    explicit ICGVisitor(const string& outputFile);
    ~ICGVisitor();

    void generate(antlr4::tree::ParseTree* tree);

    // ---------------- Phase 1 productions only ----------------

    any visitFunctionDefinitionWithoutParameters(
        CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx) override;

    any visitCompoundWithStatements(
        CSubsetParser::CompoundWithStatementsContext* ctx) override;

    any visitCompoundEmpty(
        CSubsetParser::CompoundEmptyContext* ctx) override;

    any visitVar_declaration(
        CSubsetParser::Var_declarationContext* ctx) override;

    any visitDeclarationScalarSingle(
        CSubsetParser::DeclarationScalarSingleContext* ctx) override;

    any visitDeclarationScalarAppend(
        CSubsetParser::DeclarationScalarAppendContext* ctx) override;

    any visitExpressionStatementNormal(
        CSubsetParser::ExpressionStatementNormalContext* ctx) override;

    any visitExpressionStatementEmpty(
        CSubsetParser::ExpressionStatementEmptyContext* ctx) override;

    any visitStatementPrintln(
        CSubsetParser::StatementPrintlnContext* ctx) override;

    any visitStatementReturn(
        CSubsetParser::StatementReturnContext* ctx) override;

    any visitVariableScalar(
        CSubsetParser::VariableScalarContext* ctx) override;

    any visitExpressionAssign(
        CSubsetParser::ExpressionAssignContext* ctx) override;

    any visitLogicBinary(
        CSubsetParser::LogicBinaryContext* ctx) override;

    any visitRelBinary(
        CSubsetParser::RelBinaryContext* ctx) override;

    any visitSimpleBinary(
        CSubsetParser::SimpleBinaryContext* ctx) override;

    any visitTermBinary(
        CSubsetParser::TermBinaryContext* ctx) override;

    any visitUnaryAdd(
        CSubsetParser::UnaryAddContext* ctx) override;

    any visitUnaryNot(
        CSubsetParser::UnaryNotContext* ctx) override;

    any visitFactorInt(
        CSubsetParser::FactorIntContext* ctx) override;

    any visitFactorFloat(
        CSubsetParser::FactorFloatContext* ctx) override;

    any visitFactorIncrement(
        CSubsetParser::FactorIncrementContext* ctx) override;

    any visitFactorDecrement(
        CSubsetParser::FactorDecrementContext* ctx) override;

private:
    ofstream out;
    SymbolTable symbolTable;

    // SymbolInfo already stores language-level information. This map only adds
    // the assembly location that the supplied symbol table does not contain.
    unordered_map<const SymbolInfo*, StorageInfo> storageOfSymbol;
    vector<StorageInfo> globals;

    string currentFunction;
    string currentDeclarationType;
    string currentExitLabel;

    int nextLocalOffset;
    int labelCounter;
    bool nextCompoundIsFunctionBody;

    // ---------- symbol/storage helpers ----------
    void installFunction(
        CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx);

    void declareScalar(const string& name, int sourceLine);
    StorageInfo lookupStorage(const string& name) const;
    string memory(const StorageInfo& storage) const;

    // ---------- assembly helpers ----------
    void emit(const string& instruction);
    void emitRaw(const string& text = "");
    void emitLabel(const string& label);
    void emitLineComment(antlr4::ParserRuleContext* ctx);

    void load(const StorageInfo& storage);
    void store(const StorageInfo& storage);

    string newLabel(const string& prefix);

    void writeHeader();
    void writePrintProcedureInclude();
    void writeDataSegment();
};

#endif
