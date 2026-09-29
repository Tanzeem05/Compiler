#ifndef SEMANTIC_VISITOR_H
#define SEMANTIC_VISITOR_H

#include "2205163_symbol_table.hpp"
#include "CSubsetBaseVisitor.h"
#include "CSubsetParser.h"
#include "antlr4-runtime.h"

#include <any>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct ParameterInfo {
    string type;
    string name;
};

class SemanticVisitor : public CSubsetBaseVisitor {
public:
    SemanticVisitor(string source, ofstream& logFile, int totalLines);

    void writeErrorFile(string fileName);

    any visitStart(CSubsetParser::StartContext* ctx) override;

    any visitProgramMultiple(CSubsetParser::ProgramMultipleContext* ctx) override;
    any visitProgramSingle(CSubsetParser::ProgramSingleContext* ctx) override;

    any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext* ctx) override;
    any visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext* ctx) override;
    any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext* ctx) override;

    any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext* ctx) override;
    any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext* ctx) override;
    any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext* ctx) override;
    any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext* ctx) override;

    any visitParameterNamedAppend(CSubsetParser::ParameterNamedAppendContext* ctx) override;
    any visitParameterUnnamedAppend(CSubsetParser::ParameterUnnamedAppendContext* ctx) override;
    any visitParameterNamedSingle(CSubsetParser::ParameterNamedSingleContext* ctx) override;
    any visitParameterUnnamedSingle(CSubsetParser::ParameterUnnamedSingleContext* ctx) override;
    any visitParameterInvalidAppend(CSubsetParser::ParameterInvalidAppendContext* ctx) override;
    any visitParameterInvalidSingle(CSubsetParser::ParameterInvalidSingleContext* ctx) override;

    any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext* ctx) override;
    any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext* ctx) override;

    any visitVar_declaration(CSubsetParser::Var_declarationContext* ctx) override;

    any visitTypeInt(CSubsetParser::TypeIntContext* ctx) override;
    any visitTypeFloat(CSubsetParser::TypeFloatContext* ctx) override;
    any visitTypeVoid(CSubsetParser::TypeVoidContext* ctx) override;

    any visitDeclarationScalarAppend(CSubsetParser::DeclarationScalarAppendContext* ctx) override;
    any visitDeclarationArrayAppend(CSubsetParser::DeclarationArrayAppendContext* ctx) override;
    any visitDeclarationScalarSingle(CSubsetParser::DeclarationScalarSingleContext* ctx) override;
    any visitDeclarationArraySingle(CSubsetParser::DeclarationArraySingleContext* ctx) override;
    any visitDeclarationInvalidAppend(CSubsetParser::DeclarationInvalidAppendContext* ctx) override;

    any visitStatementsSingle(CSubsetParser::StatementsSingleContext* ctx) override;
    any visitStatementsMultiple(CSubsetParser::StatementsMultipleContext* ctx) override;

    any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext* ctx) override;
    any visitStatementExpression(CSubsetParser::StatementExpressionContext* ctx) override;
    any visitStatementCompound(CSubsetParser::StatementCompoundContext* ctx) override;
    any visitStatementFor(CSubsetParser::StatementForContext* ctx) override;
    any visitStatementIfElse(CSubsetParser::StatementIfElseContext* ctx) override;
    any visitStatementIf(CSubsetParser::StatementIfContext* ctx) override;
    any visitStatementWhile(CSubsetParser::StatementWhileContext* ctx) override;
    any visitStatementPrintln(CSubsetParser::StatementPrintlnContext* ctx) override;
    any visitStatementReturn(CSubsetParser::StatementReturnContext* ctx) override;

    any visitExpressionStatementEmpty(CSubsetParser::ExpressionStatementEmptyContext* ctx) override;
    any visitExpressionStatementNormal(CSubsetParser::ExpressionStatementNormalContext* ctx) override;
    any visitExpressionStatementMissingSemicolon(CSubsetParser::ExpressionStatementMissingSemicolonContext* ctx) override;

    any visitVariableScalar(CSubsetParser::VariableScalarContext* ctx) override;
    any visitVariableArray(CSubsetParser::VariableArrayContext* ctx) override;

    any visitExpressionLogic(CSubsetParser::ExpressionLogicContext* ctx) override;
    any visitExpressionAssign(CSubsetParser::ExpressionAssignContext* ctx) override;

    any visitLogicSingle(CSubsetParser::LogicSingleContext* ctx) override;
    any visitLogicBinary(CSubsetParser::LogicBinaryContext* ctx) override;

    any visitRelSingle(CSubsetParser::RelSingleContext* ctx) override;
    any visitRelBinary(CSubsetParser::RelBinaryContext* ctx) override;

    any visitSimpleSingle(CSubsetParser::SimpleSingleContext* ctx) override;
    any visitSimpleBinary(CSubsetParser::SimpleBinaryContext* ctx) override;
    any visitSimpleInvalidAssignment(CSubsetParser::SimpleInvalidAssignmentContext* ctx) override;

    any visitTermSingle(CSubsetParser::TermSingleContext* ctx) override;
    any visitTermBinary(CSubsetParser::TermBinaryContext* ctx) override;

    any visitUnaryAdd(CSubsetParser::UnaryAddContext* ctx) override;
    any visitUnaryNot(CSubsetParser::UnaryNotContext* ctx) override;
    any visitUnaryFactor(CSubsetParser::UnaryFactorContext* ctx) override;

    any visitFactorVariable(CSubsetParser::FactorVariableContext* ctx) override;
    any visitFactorFunctionCall(CSubsetParser::FactorFunctionCallContext* ctx) override;
    any visitFactorParenthesized(CSubsetParser::FactorParenthesizedContext* ctx) override;
    any visitFactorInt(CSubsetParser::FactorIntContext* ctx) override;
    any visitFactorFloat(CSubsetParser::FactorFloatContext* ctx) override;
    any visitFactorIncrement(CSubsetParser::FactorIncrementContext* ctx) override;
    any visitFactorDecrement(CSubsetParser::FactorDecrementContext* ctx) override;

    any visitArgumentListNonEmpty(CSubsetParser::ArgumentListNonEmptyContext* ctx) override;
    any visitArgumentListEmpty(CSubsetParser::ArgumentListEmptyContext* ctx) override;
    any visitArgumentsMultiple(CSubsetParser::ArgumentsMultipleContext* ctx) override;
    any visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext* ctx) override;

private:
    struct ExprInfo {
        string type;
        bool isZero;

        ExprInfo(string type = "error", bool isZero = false) {
            this->type = type;
            this->isZero = isZero;
        }
    };

    struct NodeInfo {
        string text;
        bool changed;
        string type;
        bool isZero;
        vector<ParameterInfo> parameters;
        vector<ExprInfo> arguments;

        NodeInfo() {
            text = "";
            changed = false;
            type = "error";
            isZero = false;
        }
    };

    string source;
    ofstream& logFile;
    int totalLines;
    SymbolTable symbolTable;
    vector<string> errors;

    string declarationType;
    bool nextCompoundIsFunctionBody; //we can compound stmt from 'stmt' or 'function_declaration'. So, if we enter the compound statement from function, we have already entered a scope beforehand. But in case of stmt, we have not entered a new scope yet. So to keep track of it....
    int lastUnitBlankLines;

    NodeInfo getInfo(any value);
    NodeInfo makeInfo(antlr4::ParserRuleContext* ctx, string correctedText, bool changed);

    void logWrite(antlr4::ParserRuleContext* ctx, string rule, string production, string text, int line = 0, int blankLines = 1);

    void addError(antlr4::ParserRuleContext* ctx, string message);

    bool canAssign(string leftType, string rightType);
    string arithmeticType(string leftType, string rightType);
    bool checkVoid(antlr4::ParserRuleContext* ctx, ExprInfo& left, ExprInfo& right);

    SymbolInfo* lookup(string name);
    SymbolInfo* lookupCurrent(string name);
    SymbolInfo* insertSymbol(string name);

    bool hasParameter(vector<ParameterInfo> parameters, string name);
    void addFunction(antlr4::ParserRuleContext* ctx, string name, string returnType, vector<ParameterInfo> parameters, bool definition);
    void declareVariable(antlr4::ParserRuleContext* ctx, string name, bool isArray);
};

#endif
