
// Generated from CSubset.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CSubsetParser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, INCOP = 22, DECOP = 23, ADDOP = 24, 
    MULOP = 25, NOT = 26, RELOP = 27, LOGICOP = 28, ASSIGNOP = 29, ID = 30, 
    CONST_FLOAT = 31, CONST_INT = 32, UNKNOWN = 33
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleCompound_statement = 6, 
    RuleVar_declaration = 7, RuleType_specifier = 8, RuleDeclaration_list = 9, 
    RuleStatements = 10, RuleStatement = 11, RuleExpression_statement = 12, 
    RuleVariable = 13, RuleExpression = 14, RuleLogic_expression = 15, RuleRel_expression = 16, 
    RuleSimple_expression = 17, RuleTerm = 18, RuleUnary_expression = 19, 
    RuleFactor = 20, RuleArgument_list = 21, RuleArguments = 22
  };

  explicit CSubsetParser(antlr4::TokenStream *input);

  CSubsetParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CSubsetParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgramContext() = default;
    void copyFrom(ProgramContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ProgramMultipleContext : public ProgramContext {
  public:
    ProgramMultipleContext(ProgramContext *ctx);

    CSubsetParser::ProgramContext *previous = nullptr;
    CSubsetParser::UnitContext *current = nullptr;
    ProgramContext *program();
    UnitContext *unit();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ProgramSingleContext : public ProgramContext {
  public:
    ProgramSingleContext(ProgramContext *ctx);

    CSubsetParser::UnitContext *current = nullptr;
    UnitContext *unit();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnitContext() = default;
    void copyFrom(UnitContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnitFunctionDefinitionContext : public UnitContext {
  public:
    UnitFunctionDefinitionContext(UnitContext *ctx);

    Func_definitionContext *func_definition();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnitFunctionDeclarationContext : public UnitContext {
  public:
    UnitFunctionDeclarationContext(UnitContext *ctx);

    Func_declarationContext *func_declaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnitVariableDeclarationContext : public UnitContext {
  public:
    UnitVariableDeclarationContext(UnitContext *ctx);

    Var_declarationContext *var_declaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Func_declarationContext() = default;
    void copyFrom(Func_declarationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionDeclarationWithParametersContext : public Func_declarationContext {
  public:
    FunctionDeclarationWithParametersContext(Func_declarationContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionDeclarationWithoutParametersContext : public Func_declarationContext {
  public:
    FunctionDeclarationWithoutParametersContext(Func_declarationContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Func_definitionContext() = default;
    void copyFrom(Func_definitionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FunctionDefinitionWithParametersContext : public Func_definitionContext {
  public:
    FunctionDefinitionWithParametersContext(Func_definitionContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionDefinitionWithoutParametersContext : public Func_definitionContext {
  public:
    FunctionDefinitionWithoutParametersContext(Func_definitionContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Parameter_listContext() = default;
    void copyFrom(Parameter_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParameterUnnamedAppendContext : public Parameter_listContext {
  public:
    ParameterUnnamedAppendContext(Parameter_listContext *ctx);

    CSubsetParser::Parameter_listContext *previous = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    Type_specifierContext *type_specifier();
    Parameter_listContext *parameter_list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParameterInvalidSingleContext : public Parameter_listContext {
  public:
    ParameterInvalidSingleContext(Parameter_listContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ADDOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParameterNamedAppendContext : public Parameter_listContext {
  public:
    ParameterNamedAppendContext(Parameter_listContext *ctx);

    CSubsetParser::Parameter_listContext *previous = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParameterInvalidAppendContext : public Parameter_listContext {
  public:
    ParameterInvalidAppendContext(Parameter_listContext *ctx);

    CSubsetParser::Parameter_listContext *previous = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ADDOP();
    Parameter_listContext *parameter_list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParameterUnnamedSingleContext : public Parameter_listContext {
  public:
    ParameterUnnamedSingleContext(Parameter_listContext *ctx);

    Type_specifierContext *type_specifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParameterNamedSingleContext : public Parameter_listContext {
  public:
    ParameterNamedSingleContext(Parameter_listContext *ctx);

    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Compound_statementContext() = default;
    void copyFrom(Compound_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CompoundWithStatementsContext : public Compound_statementContext {
  public:
    CompoundWithStatementsContext(Compound_statementContext *ctx);

    antlr4::tree::TerminalNode *LCURL();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *RCURL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompoundEmptyContext : public Compound_statementContext {
  public:
    CompoundEmptyContext(Compound_statementContext *ctx);

    antlr4::tree::TerminalNode *LCURL();
    antlr4::tree::TerminalNode *RCURL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Type_specifierContext() = default;
    void copyFrom(Type_specifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TypeFloatContext : public Type_specifierContext {
  public:
    TypeFloatContext(Type_specifierContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeVoidContext : public Type_specifierContext {
  public:
    TypeVoidContext(Type_specifierContext *ctx);

    antlr4::tree::TerminalNode *VOID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeIntContext : public Type_specifierContext {
  public:
    TypeIntContext(Type_specifierContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Declaration_listContext() = default;
    void copyFrom(Declaration_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DeclarationArrayAppendContext : public Declaration_listContext {
  public:
    DeclarationArrayAppendContext(Declaration_listContext *ctx);

    CSubsetParser::Declaration_listContext *previous = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();
    Declaration_listContext *declaration_list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclarationInvalidAppendContext : public Declaration_listContext {
  public:
    DeclarationInvalidAppendContext(Declaration_listContext *ctx);

    CSubsetParser::Declaration_listContext *previous = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ID();
    Declaration_listContext *declaration_list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclarationArraySingleContext : public Declaration_listContext {
  public:
    DeclarationArraySingleContext(Declaration_listContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclarationScalarAppendContext : public Declaration_listContext {
  public:
    DeclarationScalarAppendContext(Declaration_listContext *ctx);

    CSubsetParser::Declaration_listContext *previous = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *ID();
    Declaration_listContext *declaration_list();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeclarationScalarSingleContext : public Declaration_listContext {
  public:
    DeclarationScalarSingleContext(Declaration_listContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementsContext() = default;
    void copyFrom(StatementsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatementsSingleContext : public StatementsContext {
  public:
    StatementsSingleContext(StatementsContext *ctx);

    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementsMultipleContext : public StatementsContext {
  public:
    StatementsMultipleContext(StatementsContext *ctx);

    CSubsetParser::StatementsContext *previous = nullptr;
    CSubsetParser::StatementContext *current = nullptr;
    StatementsContext *statements();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatementIfContext : public StatementContext {
  public:
    StatementIfContext(StatementContext *ctx);

    CSubsetParser::ExpressionContext *condition = nullptr;
    CSubsetParser::StatementContext *thenBranch = nullptr;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementVariableDeclarationContext : public StatementContext {
  public:
    StatementVariableDeclarationContext(StatementContext *ctx);

    Var_declarationContext *var_declaration();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementForContext : public StatementContext {
  public:
    StatementForContext(StatementContext *ctx);

    CSubsetParser::Expression_statementContext *init = nullptr;
    CSubsetParser::Expression_statementContext *condition = nullptr;
    CSubsetParser::ExpressionContext *update = nullptr;
    CSubsetParser::StatementContext *body = nullptr;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    ExpressionContext *expression();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementReturnContext : public StatementContext {
  public:
    StatementReturnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementWhileContext : public StatementContext {
  public:
    StatementWhileContext(StatementContext *ctx);

    CSubsetParser::ExpressionContext *condition = nullptr;
    CSubsetParser::StatementContext *body = nullptr;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    StatementContext *statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementExpressionContext : public StatementContext {
  public:
    StatementExpressionContext(StatementContext *ctx);

    Expression_statementContext *expression_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementCompoundContext : public StatementContext {
  public:
    StatementCompoundContext(StatementContext *ctx);

    Compound_statementContext *compound_statement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementPrintlnContext : public StatementContext {
  public:
    StatementPrintlnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementIfElseContext : public StatementContext {
  public:
    StatementIfElseContext(StatementContext *ctx);

    CSubsetParser::ExpressionContext *condition = nullptr;
    CSubsetParser::StatementContext *thenBranch = nullptr;
    CSubsetParser::StatementContext *elseBranch = nullptr;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *ELSE();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expression_statementContext() = default;
    void copyFrom(Expression_statementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExpressionStatementEmptyContext : public Expression_statementContext {
  public:
    ExpressionStatementEmptyContext(Expression_statementContext *ctx);

    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionStatementNormalContext : public Expression_statementContext {
  public:
    ExpressionStatementNormalContext(Expression_statementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionStatementMissingSemicolonContext : public Expression_statementContext {
  public:
    ExpressionStatementMissingSemicolonContext(Expression_statementContext *ctx);

    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VariableContext() = default;
    void copyFrom(VariableContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VariableScalarContext : public VariableContext {
  public:
    VariableScalarContext(VariableContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableArrayContext : public VariableContext {
  public:
    VariableArrayContext(VariableContext *ctx);

    CSubsetParser::ExpressionContext *index = nullptr;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExpressionLogicContext : public ExpressionContext {
  public:
    ExpressionLogicContext(ExpressionContext *ctx);

    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionAssignContext : public ExpressionContext {
  public:
    ExpressionAssignContext(ExpressionContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Logic_expressionContext() = default;
    void copyFrom(Logic_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LogicSingleContext : public Logic_expressionContext {
  public:
    LogicSingleContext(Logic_expressionContext *ctx);

    Rel_expressionContext *rel_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicBinaryContext : public Logic_expressionContext {
  public:
    LogicBinaryContext(Logic_expressionContext *ctx);

    CSubsetParser::Rel_expressionContext *left = nullptr;
    CSubsetParser::Rel_expressionContext *right = nullptr;
    antlr4::tree::TerminalNode *LOGICOP();
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rel_expressionContext() = default;
    void copyFrom(Rel_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelSingleContext : public Rel_expressionContext {
  public:
    RelSingleContext(Rel_expressionContext *ctx);

    Simple_expressionContext *simple_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelBinaryContext : public Rel_expressionContext {
  public:
    RelBinaryContext(Rel_expressionContext *ctx);

    CSubsetParser::Simple_expressionContext *left = nullptr;
    CSubsetParser::Simple_expressionContext *right = nullptr;
    antlr4::tree::TerminalNode *RELOP();
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Simple_expressionContext() = default;
    void copyFrom(Simple_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimpleSingleContext : public Simple_expressionContext {
  public:
    SimpleSingleContext(Simple_expressionContext *ctx);

    TermContext *term();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleBinaryContext : public Simple_expressionContext {
  public:
    SimpleBinaryContext(Simple_expressionContext *ctx);

    CSubsetParser::Simple_expressionContext *left = nullptr;
    CSubsetParser::TermContext *right = nullptr;
    antlr4::tree::TerminalNode *ADDOP();
    Simple_expressionContext *simple_expression();
    TermContext *term();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleInvalidAssignmentContext : public Simple_expressionContext {
  public:
    SimpleInvalidAssignmentContext(Simple_expressionContext *ctx);

    CSubsetParser::Simple_expressionContext *left = nullptr;
    antlr4::tree::TerminalNode *ADDOP();
    antlr4::tree::TerminalNode *ASSIGNOP();
    Simple_expressionContext *simple_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TermContext() = default;
    void copyFrom(TermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TermSingleContext : public TermContext {
  public:
    TermSingleContext(TermContext *ctx);

    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TermBinaryContext : public TermContext {
  public:
    TermBinaryContext(TermContext *ctx);

    CSubsetParser::TermContext *left = nullptr;
    CSubsetParser::Unary_expressionContext *right = nullptr;
    antlr4::tree::TerminalNode *MULOP();
    TermContext *term();
    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Unary_expressionContext() = default;
    void copyFrom(Unary_expressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryNotContext : public Unary_expressionContext {
  public:
    UnaryNotContext(Unary_expressionContext *ctx);

    CSubsetParser::Unary_expressionContext *operand = nullptr;
    antlr4::tree::TerminalNode *NOT();
    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryFactorContext : public Unary_expressionContext {
  public:
    UnaryFactorContext(Unary_expressionContext *ctx);

    FactorContext *factor();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryAddContext : public Unary_expressionContext {
  public:
    UnaryAddContext(Unary_expressionContext *ctx);

    CSubsetParser::Unary_expressionContext *operand = nullptr;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FactorContext() = default;
    void copyFrom(FactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FactorFunctionCallContext : public FactorContext {
  public:
    FactorFunctionCallContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorVariableContext : public FactorContext {
  public:
    FactorVariableContext(FactorContext *ctx);

    VariableContext *variable();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorIntContext : public FactorContext {
  public:
    FactorIntContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *CONST_INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorParenthesizedContext : public FactorContext {
  public:
    FactorParenthesizedContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorFloatContext : public FactorContext {
  public:
    FactorFloatContext(FactorContext *ctx);

    antlr4::tree::TerminalNode *CONST_FLOAT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorIncrementContext : public FactorContext {
  public:
    FactorIncrementContext(FactorContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *INCOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactorDecrementContext : public FactorContext {
  public:
    FactorDecrementContext(FactorContext *ctx);

    VariableContext *variable();
    antlr4::tree::TerminalNode *DECOP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Argument_listContext() = default;
    void copyFrom(Argument_listContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArgumentListEmptyContext : public Argument_listContext {
  public:
    ArgumentListEmptyContext(Argument_listContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArgumentListNonEmptyContext : public Argument_listContext {
  public:
    ArgumentListNonEmptyContext(Argument_listContext *ctx);

    ArgumentsContext *arguments();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArgumentsContext() = default;
    void copyFrom(ArgumentsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArgumentsSingleContext : public ArgumentsContext {
  public:
    ArgumentsSingleContext(ArgumentsContext *ctx);

    CSubsetParser::Logic_expressionContext *current = nullptr;
    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArgumentsMultipleContext : public ArgumentsContext {
  public:
    ArgumentsMultipleContext(ArgumentsContext *ctx);

    CSubsetParser::ArgumentsContext *previous = nullptr;
    CSubsetParser::Logic_expressionContext *current = nullptr;
    antlr4::tree::TerminalNode *COMMA();
    ArgumentsContext *arguments();
    Logic_expressionContext *logic_expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

