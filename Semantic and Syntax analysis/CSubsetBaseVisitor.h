
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CSubsetVisitor.h"


/**
 * This class provides an empty implementation of CSubsetVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CSubsetBaseVisitor : public CSubsetVisitor {
public:

  virtual std::any visitStart(CSubsetParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramMultiple(CSubsetParser::ProgramMultipleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramSingle(CSubsetParser::ProgramSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitVariableDeclaration(CSubsetParser::UnitVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitFunctionDeclaration(CSubsetParser::UnitFunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnitFunctionDefinition(CSubsetParser::UnitFunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclarationWithParameters(CSubsetParser::FunctionDeclarationWithParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclarationWithoutParameters(CSubsetParser::FunctionDeclarationWithoutParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefinitionWithParameters(CSubsetParser::FunctionDefinitionWithParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefinitionWithoutParameters(CSubsetParser::FunctionDefinitionWithoutParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterUnnamedAppend(CSubsetParser::ParameterUnnamedAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterInvalidSingle(CSubsetParser::ParameterInvalidSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterNamedAppend(CSubsetParser::ParameterNamedAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterInvalidAppend(CSubsetParser::ParameterInvalidAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterUnnamedSingle(CSubsetParser::ParameterUnnamedSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameterNamedSingle(CSubsetParser::ParameterNamedSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundWithStatements(CSubsetParser::CompoundWithStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundEmpty(CSubsetParser::CompoundEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declaration(CSubsetParser::Var_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeInt(CSubsetParser::TypeIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeFloat(CSubsetParser::TypeFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeVoid(CSubsetParser::TypeVoidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationArrayAppend(CSubsetParser::DeclarationArrayAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationInvalidAppend(CSubsetParser::DeclarationInvalidAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationArraySingle(CSubsetParser::DeclarationArraySingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationScalarAppend(CSubsetParser::DeclarationScalarAppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationScalarSingle(CSubsetParser::DeclarationScalarSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementsSingle(CSubsetParser::StatementsSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementsMultiple(CSubsetParser::StatementsMultipleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementVariableDeclaration(CSubsetParser::StatementVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementExpression(CSubsetParser::StatementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementCompound(CSubsetParser::StatementCompoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementFor(CSubsetParser::StatementForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementIfElse(CSubsetParser::StatementIfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementIf(CSubsetParser::StatementIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementWhile(CSubsetParser::StatementWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementPrintln(CSubsetParser::StatementPrintlnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementReturn(CSubsetParser::StatementReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatementEmpty(CSubsetParser::ExpressionStatementEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatementNormal(CSubsetParser::ExpressionStatementNormalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatementMissingSemicolon(CSubsetParser::ExpressionStatementMissingSemicolonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableScalar(CSubsetParser::VariableScalarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableArray(CSubsetParser::VariableArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionLogic(CSubsetParser::ExpressionLogicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionAssign(CSubsetParser::ExpressionAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicSingle(CSubsetParser::LogicSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicBinary(CSubsetParser::LogicBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelSingle(CSubsetParser::RelSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelBinary(CSubsetParser::RelBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleSingle(CSubsetParser::SimpleSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleBinary(CSubsetParser::SimpleBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleInvalidAssignment(CSubsetParser::SimpleInvalidAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermSingle(CSubsetParser::TermSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermBinary(CSubsetParser::TermBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryAdd(CSubsetParser::UnaryAddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryNot(CSubsetParser::UnaryNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryFactor(CSubsetParser::UnaryFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorVariable(CSubsetParser::FactorVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorFunctionCall(CSubsetParser::FactorFunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorParenthesized(CSubsetParser::FactorParenthesizedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorInt(CSubsetParser::FactorIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorFloat(CSubsetParser::FactorFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorIncrement(CSubsetParser::FactorIncrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorDecrement(CSubsetParser::FactorDecrementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentListNonEmpty(CSubsetParser::ArgumentListNonEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentListEmpty(CSubsetParser::ArgumentListEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentsSingle(CSubsetParser::ArgumentsSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentsMultiple(CSubsetParser::ArgumentsMultipleContext *ctx) override {
    return visitChildren(ctx);
  }


};

