#ifndef ICG_VISITOR_H
#define ICG_VISITOR_H

#include "2205163_symbol_table.hpp"
#include "CSubsetBaseVisitor.h"
#include <any>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct StorageInfo {
    std::string name; // Original global name, escaped only for assembler conflicts.
    bool global = false;
    bool array = false;
    int offset = 0; // Signed EBP displacement; parameters are positive.
    int count = 1;
    int sourceLine = 0;
};

struct ParameterInfo {
    std::string type;
    std::string name;
};

class ICGVisitor : public CSubsetBaseVisitor {
public:
    explicit ICGVisitor(const std::string& outputFile,
                        const std::string& libraryFile = "printProc.lib");
    ~ICGVisitor();
    void generate(antlr4::tree::ParseTree* tree);

    std::any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext* ctx) override;
    std::any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext* ctx) override;
    std::any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext* ctx) override;
    std::any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx) override;
    std::any visitParameterNamedSingle(CSubsetParser::ParameterNamedSingleContext* ctx) override;
    std::any visitParameterNamedAppend(CSubsetParser::ParameterNamedAppendContext* ctx) override;
    std::any visitParameterUnnamedSingle(CSubsetParser::ParameterUnnamedSingleContext* ctx) override;
    std::any visitParameterUnnamedAppend(CSubsetParser::ParameterUnnamedAppendContext* ctx) override;
    std::any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext* ctx) override;
    std::any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext* ctx) override;
    std::any visitVar_declaration(CSubsetParser::Var_declarationContext* ctx) override;
    std::any visitDeclarationScalarSingle(CSubsetParser::DeclarationScalarSingleContext* ctx) override;
    std::any visitDeclarationScalarAppend(CSubsetParser::DeclarationScalarAppendContext* ctx) override;
    std::any visitDeclarationArraySingle(CSubsetParser::DeclarationArraySingleContext* ctx) override;
    std::any visitDeclarationArrayAppend(CSubsetParser::DeclarationArrayAppendContext* ctx) override;
    std::any visitExpressionStatementNormal(CSubsetParser::ExpressionStatementNormalContext* ctx) override;
    std::any visitExpressionStatementEmpty(CSubsetParser::ExpressionStatementEmptyContext* ctx) override;
    std::any visitStatementPrintln(CSubsetParser::StatementPrintlnContext* ctx) override;
    std::any visitStatementReturn(CSubsetParser::StatementReturnContext* ctx) override;
    std::any visitStatementIf(CSubsetParser::StatementIfContext* ctx) override;
    std::any visitStatementIfElse(CSubsetParser::StatementIfElseContext* ctx) override;
    std::any visitStatementWhile(CSubsetParser::StatementWhileContext* ctx) override;
    std::any visitStatementFor(CSubsetParser::StatementForContext* ctx) override;
    std::any visitVariableScalar(CSubsetParser::VariableScalarContext* ctx) override;
    std::any visitVariableArray(CSubsetParser::VariableArrayContext* ctx) override;
    std::any visitExpressionAssign(CSubsetParser::ExpressionAssignContext* ctx) override;
    std::any visitLogicBinary(CSubsetParser::LogicBinaryContext* ctx) override;
    std::any visitRelBinary(CSubsetParser::RelBinaryContext* ctx) override;
    std::any visitSimpleBinary(CSubsetParser::SimpleBinaryContext* ctx) override;
    std::any visitTermBinary(CSubsetParser::TermBinaryContext* ctx) override;
    std::any visitUnaryAdd(CSubsetParser::UnaryAddContext* ctx) override;
    std::any visitUnaryNot(CSubsetParser::UnaryNotContext* ctx) override;
    std::any visitFactorInt(CSubsetParser::FactorIntContext* ctx) override;
    std::any visitFactorFloat(CSubsetParser::FactorFloatContext* ctx) override;
    std::any visitFactorIncrement(CSubsetParser::FactorIncrementContext* ctx) override;
    std::any visitFactorDecrement(CSubsetParser::FactorDecrementContext* ctx) override;
    std::any visitFactorFunctionCall(CSubsetParser::FactorFunctionCallContext* ctx) override;
    std::any visitArgumentListNonEmpty(CSubsetParser::ArgumentListNonEmptyContext* ctx) override;
    std::any visitArgumentListEmpty(CSubsetParser::ArgumentListEmptyContext* ctx) override;
    std::any visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext* ctx) override;
    std::any visitArgumentsMultiple(CSubsetParser::ArgumentsMultipleContext* ctx) override;
    std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext* ctx) override;
    std::any visitStatementsMultiple(CSubsetParser::StatementsMultipleContext* ctx) override;

    // Preserve expression types across grammar wrappers.
    std::any visitExpressionLogic(CSubsetParser::ExpressionLogicContext* ctx) override {
        return visit(ctx->logic_expression());
    }
    std::any visitLogicSingle(CSubsetParser::LogicSingleContext* ctx) override {
        return visit(ctx->rel_expression());
    }
    std::any visitRelSingle(CSubsetParser::RelSingleContext* ctx) override {
        return visit(ctx->simple_expression());
    }
    std::any visitSimpleSingle(CSubsetParser::SimpleSingleContext* ctx) override {
        return visit(ctx->term());
    }
    std::any visitTermSingle(CSubsetParser::TermSingleContext* ctx) override {
        return visit(ctx->unary_expression());
    }
    std::any visitUnaryFactor(CSubsetParser::UnaryFactorContext* ctx) override {
        return visit(ctx->factor());
    }
    std::any visitFactorVariable(CSubsetParser::FactorVariableContext* ctx) override {
        return visit(ctx->variable());
    }
    std::any visitFactorParenthesized(CSubsetParser::FactorParenthesizedContext* ctx) override {
        return visit(ctx->expression());
    }

    // Assignment 3 recovery alternatives must never silently generate code.
    std::any visitParameterInvalidSingle(CSubsetParser::ParameterInvalidSingleContext* ctx) override {
        fail(ctx, "Invalid syntax");
    }
    std::any visitParameterInvalidAppend(CSubsetParser::ParameterInvalidAppendContext* ctx) override {
        fail(ctx, "Invalid syntax");
    }
    std::any visitDeclarationInvalidAppend(CSubsetParser::DeclarationInvalidAppendContext* ctx) override {
        fail(ctx, "Invalid syntax");
    }
    std::any visitExpressionStatementMissingSemicolon(CSubsetParser::ExpressionStatementMissingSemicolonContext* ctx) override {
        fail(ctx, "Invalid syntax");
    }
    std::any visitSimpleInvalidAssignment(CSubsetParser::SimpleInvalidAssignmentContext* ctx) override {
        fail(ctx, "Invalid syntax");
    }

private:
    std::ofstream out, body;
    std::string outputFile, temporaryFile, libraryFile;
    SymbolTable symbolTable;
    std::unordered_map<const SymbolInfo*, StorageInfo> storageOfSymbol;
    std::vector<StorageInfo> globals;
    std::unordered_set<std::string> calledFunctions;
    std::string currentFunction, currentReturnType, currentDeclarationType;
    std::string currentExitLabel;
    std::string branchTrue, branchFalse;
    bool conditionEmitted = false;
    bool valueOnStack = false;
    struct FunctionFrame {
        std::string marker;
        std::vector<int> allocations;
        std::string exitLabel;
    };
    std::vector<FunctionFrame> frames;
    std::vector<std::string> emittedLabels;
    int nextLocalOffset = 0;
    int labelCounter = 1;
    int currentExpressionLine = 0;
    bool nextCompoundIsFunctionBody = false;

    [[noreturn]] void fail(antlr4::ParserRuleContext* ctx, const std::string& message) const;
    void requireInt(antlr4::ParserRuleContext* ctx, bool materialize = true);
    void materialize(bool comment = true);
    void condition(antlr4::ParserRuleContext* ctx, std::string yes, std::string no);
    void operands(antlr4::ParserRuleContext* left, antlr4::ParserRuleContext* right,
                  const std::string& scratch);
    std::string assemblyName(const std::string& name) const;
    void arrayOffset(const StorageInfo& storage, bool preserveValue, bool comment);
    std::vector<ParameterInfo> parameters(CSubsetParser::Parameter_listContext* ctx);
    void installFunction(const std::string& name, const std::string& returnType,
                         const std::vector<ParameterInfo>& params, bool definition,
                         antlr4::ParserRuleContext* ctx);
    void defineFunction(const std::string& name, const std::string& returnType,
                        const std::vector<ParameterInfo>& params,
                        CSubsetParser::Compound_statementContext* compound,
                        antlr4::ParserRuleContext* ctx);
    void declareVariable(const std::string& name, int count, bool array, int sourceLine);
    StorageInfo lookupStorage(const std::string& name) const;
    std::string memory(const StorageInfo& storage) const;
    void postfix(CSubsetParser::VariableContext* ctx, const std::string& instruction);
    void emit(const std::string& instruction);
    void emitAtLine(const std::string& instruction, int sourceLine);
    void emitLabel(const std::string& label);
    void annotate(antlr4::ParserRuleContext* ctx);
    std::string newLabel();
    void writePrintProcedure();
};

#endif
