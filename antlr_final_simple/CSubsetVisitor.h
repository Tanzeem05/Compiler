
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CSubsetParser.
 */
class  CSubsetVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CSubsetParser.
   */
    virtual std::any visitStart(CSubsetParser::StartContext *context) = 0;

    virtual std::any visitProgramMultiple(CSubsetParser::ProgramMultipleContext *context) = 0;

    virtual std::any visitProgramSingle(CSubsetParser::ProgramSingleContext *context) = 0;

    virtual std::any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *context) = 0;

    virtual std::any visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext *context) = 0;

    virtual std::any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *context) = 0;

    virtual std::any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext *context) = 0;

    virtual std::any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext *context) = 0;

    virtual std::any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *context) = 0;

    virtual std::any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *context) = 0;

    virtual std::any visitParameterUnnamedAppend(CSubsetParser::ParameterUnnamedAppendContext *context) = 0;

    virtual std::any visitParameterInvalidSingle(CSubsetParser::ParameterInvalidSingleContext *context) = 0;

    virtual std::any visitParameterNamedAppend(CSubsetParser::ParameterNamedAppendContext *context) = 0;

    virtual std::any visitParameterInvalidAppend(CSubsetParser::ParameterInvalidAppendContext *context) = 0;

    virtual std::any visitParameterUnnamedSingle(CSubsetParser::ParameterUnnamedSingleContext *context) = 0;

    virtual std::any visitParameterNamedSingle(CSubsetParser::ParameterNamedSingleContext *context) = 0;

    virtual std::any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *context) = 0;

    virtual std::any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext *context) = 0;

    virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *context) = 0;

    virtual std::any visitTypeInt(CSubsetParser::TypeIntContext *context) = 0;

    virtual std::any visitTypeFloat(CSubsetParser::TypeFloatContext *context) = 0;

    virtual std::any visitTypeVoid(CSubsetParser::TypeVoidContext *context) = 0;

    virtual std::any visitDeclarationArrayAppend(CSubsetParser::DeclarationArrayAppendContext *context) = 0;

    virtual std::any visitDeclarationInvalidAppend(CSubsetParser::DeclarationInvalidAppendContext *context) = 0;

    virtual std::any visitDeclarationArraySingle(CSubsetParser::DeclarationArraySingleContext *context) = 0;

    virtual std::any visitDeclarationScalarAppend(CSubsetParser::DeclarationScalarAppendContext *context) = 0;

    virtual std::any visitDeclarationScalarSingle(CSubsetParser::DeclarationScalarSingleContext *context) = 0;

    virtual std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext *context) = 0;

    virtual std::any visitStatementsMultiple(CSubsetParser::StatementsMultipleContext *context) = 0;

    virtual std::any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *context) = 0;

    virtual std::any visitStatementExpression(CSubsetParser::StatementExpressionContext *context) = 0;

    virtual std::any visitStatementCompound(CSubsetParser::StatementCompoundContext *context) = 0;

    virtual std::any visitStatementFor(CSubsetParser::StatementForContext *context) = 0;

    virtual std::any visitStatementIfElse(CSubsetParser::StatementIfElseContext *context) = 0;

    virtual std::any visitStatementIf(CSubsetParser::StatementIfContext *context) = 0;

    virtual std::any visitStatementWhile(CSubsetParser::StatementWhileContext *context) = 0;

    virtual std::any visitStatementPrintln(CSubsetParser::StatementPrintlnContext *context) = 0;

    virtual std::any visitStatementReturn(CSubsetParser::StatementReturnContext *context) = 0;

    virtual std::any visitExpressionStatementEmpty(CSubsetParser::ExpressionStatementEmptyContext *context) = 0;

    virtual std::any visitExpressionStatementNormal(CSubsetParser::ExpressionStatementNormalContext *context) = 0;

    virtual std::any visitExpressionStatementMissingSemicolon(CSubsetParser::ExpressionStatementMissingSemicolonContext *context) = 0;

    virtual std::any visitVariableScalar(CSubsetParser::VariableScalarContext *context) = 0;

    virtual std::any visitVariableArray(CSubsetParser::VariableArrayContext *context) = 0;

    virtual std::any visitExpressionLogic(CSubsetParser::ExpressionLogicContext *context) = 0;

    virtual std::any visitExpressionAssign(CSubsetParser::ExpressionAssignContext *context) = 0;

    virtual std::any visitLogicSingle(CSubsetParser::LogicSingleContext *context) = 0;

    virtual std::any visitLogicBinary(CSubsetParser::LogicBinaryContext *context) = 0;

    virtual std::any visitRelSingle(CSubsetParser::RelSingleContext *context) = 0;

    virtual std::any visitRelBinary(CSubsetParser::RelBinaryContext *context) = 0;

    virtual std::any visitSimpleSingle(CSubsetParser::SimpleSingleContext *context) = 0;

    virtual std::any visitSimpleBinary(CSubsetParser::SimpleBinaryContext *context) = 0;

    virtual std::any visitSimpleInvalidAssignment(CSubsetParser::SimpleInvalidAssignmentContext *context) = 0;

    virtual std::any visitTermSingle(CSubsetParser::TermSingleContext *context) = 0;

    virtual std::any visitTermBinary(CSubsetParser::TermBinaryContext *context) = 0;

    virtual std::any visitUnaryAdd(CSubsetParser::UnaryAddContext *context) = 0;

    virtual std::any visitUnaryNot(CSubsetParser::UnaryNotContext *context) = 0;

    virtual std::any visitUnaryFactor(CSubsetParser::UnaryFactorContext *context) = 0;

    virtual std::any visitFactorVariable(CSubsetParser::FactorVariableContext *context) = 0;

    virtual std::any visitFactorFunctionCall(CSubsetParser::FactorFunctionCallContext *context) = 0;

    virtual std::any visitFactorParenthesized(CSubsetParser::FactorParenthesizedContext *context) = 0;

    virtual std::any visitFactorInt(CSubsetParser::FactorIntContext *context) = 0;

    virtual std::any visitFactorFloat(CSubsetParser::FactorFloatContext *context) = 0;

    virtual std::any visitFactorIncrement(CSubsetParser::FactorIncrementContext *context) = 0;

    virtual std::any visitFactorDecrement(CSubsetParser::FactorDecrementContext *context) = 0;

    virtual std::any visitArgumentListNonEmpty(CSubsetParser::ArgumentListNonEmptyContext *context) = 0;

    virtual std::any visitArgumentListEmpty(CSubsetParser::ArgumentListEmptyContext *context) = 0;

    virtual std::any visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext *context) = 0;

    virtual std::any visitArgumentsMultiple(CSubsetParser::ArgumentsMultipleContext *context) = 0;


};

