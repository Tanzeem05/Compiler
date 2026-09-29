grammar CSubset;
import Lexer;

start
    : program
    ;

program
    : previous=program current=unit                                  # ProgramMultiple
    | current=unit                                                   # ProgramSingle
    ;

unit
    : var_declaration                                                # UnitVariableDeclaration
    | func_declaration                                               # UnitFunctionDeclaration
    | func_definition                                                # UnitFunctionDefinition
    ;

func_declaration
    : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON       # FunctionDeclarationWithParameters
    | type_specifier ID LPAREN RPAREN SEMICOLON                      # FunctionDeclarationWithoutParameters
    ;

func_definition
    : type_specifier ID LPAREN parameter_list RPAREN compound_statement # FunctionDefinitionWithParameters
    | type_specifier ID LPAREN RPAREN compound_statement                # FunctionDefinitionWithoutParameters
    ;

parameter_list
    : previous=parameter_list COMMA type_specifier ID                # ParameterNamedAppend
    | previous=parameter_list COMMA type_specifier                   # ParameterUnnamedAppend
    | type_specifier ID                                              # ParameterNamedSingle
    | type_specifier                                                 # ParameterUnnamedSingle

    // Recovery rules 
    | previous=parameter_list COMMA type_specifier ADDOP             # ParameterInvalidAppend
    | type_specifier ADDOP                                           # ParameterInvalidSingle
    ;

compound_statement
    : LCURL statements RCURL                                         # CompoundWithStatements
    | LCURL RCURL                                                    # CompoundEmpty
    ;

var_declaration
    : type_specifier declaration_list SEMICOLON
    ;

type_specifier
    : INT                                                            # TypeInt
    | FLOAT                                                          # TypeFloat
    | VOID                                                           # TypeVoid
    ;

declaration_list
    : previous=declaration_list COMMA ID                             # DeclarationScalarAppend
    | previous=declaration_list COMMA ID LTHIRD CONST_INT RTHIRD     # DeclarationArrayAppend
    | ID                                                             # DeclarationScalarSingle
    | ID LTHIRD CONST_INT RTHIRD                                     # DeclarationArraySingle

    // Recovery for input : int x-y,z;
    | previous=declaration_list ADDOP ID                             # DeclarationInvalidAppend
    ;

statements
    : statement                                                      # StatementsSingle
    | previous=statements current=statement                          # StatementsMultiple
    ;

statement
    : var_declaration                                                # StatementVariableDeclaration
    | expression_statement                                           # StatementExpression
    | compound_statement                                             # StatementCompound
    | FOR LPAREN init=expression_statement condition=expression_statement update=expression RPAREN body=statement
                                                                     # StatementFor
    | IF LPAREN condition=expression RPAREN thenBranch=statement ELSE elseBranch=statement
                                                                     # StatementIfElse
    | IF LPAREN condition=expression RPAREN thenBranch=statement     # StatementIf
    | WHILE LPAREN condition=expression RPAREN body=statement        # StatementWhile
    | PRINTLN LPAREN ID RPAREN SEMICOLON                             # StatementPrintln
    | RETURN expression SEMICOLON                                    # StatementReturn
    ;

expression_statement
    : SEMICOLON                                                      # ExpressionStatementEmpty
    | expression SEMICOLON                                           # ExpressionStatementNormal

    // Recovery for the missing-semicolon syntax sample.
    | expression                                                     # ExpressionStatementMissingSemicolon
    ;

variable
    : ID                                                             # VariableScalar
    | ID LTHIRD index=expression RTHIRD                              # VariableArray
    ;

expression
    : logic_expression                                               # ExpressionLogic
    | variable ASSIGNOP logic_expression                             # ExpressionAssign
    ;

logic_expression
    : rel_expression                                                 # LogicSingle
    | left=rel_expression LOGICOP right=rel_expression               # LogicBinary
    ;

rel_expression
    : simple_expression                                              # RelSingle
    | left=simple_expression RELOP right=simple_expression           # RelBinary
    ;

simple_expression
    : term                                                           # SimpleSingle
    | left=simple_expression ADDOP right=term                        # SimpleBinary

    // Recovery for malformed input such as 2+=6.
    | left=simple_expression ADDOP ASSIGNOP                          # SimpleInvalidAssignment
    ;

term
    : unary_expression                                               # TermSingle
    | left=term MULOP right=unary_expression                         # TermBinary
    ;

unary_expression
    : ADDOP operand=unary_expression                                 # UnaryAdd
    | NOT operand=unary_expression                                   # UnaryNot
    | factor                                                         # UnaryFactor
    ;

factor
    : variable                                                       # FactorVariable
    | ID LPAREN argument_list RPAREN                                 # FactorFunctionCall
    | LPAREN expression RPAREN                                       # FactorParenthesized
    | CONST_INT                                                      # FactorInt
    | CONST_FLOAT                                                    # FactorFloat
    | variable INCOP                                                 # FactorIncrement
    | variable DECOP                                                 # FactorDecrement
    ;

argument_list
    : arguments                                                      # ArgumentListNonEmpty
    |                                                                # ArgumentListEmpty
    ;

arguments
    : previous=arguments COMMA current=logic_expression              # ArgumentsMultiple
    | current=logic_expression                                       # ArgumentsSingle
    ;
