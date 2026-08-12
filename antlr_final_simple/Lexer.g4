lexer grammar Lexer;

// No symbol-table work and no embedded lexer logging actions are needed for
// Assignment 3. The parser/visitor performs syntax/semantic logging.

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
    ;

BLOCK_COMMENT
    : '/*' ( . | '\r' | '\n' )*? '*/' -> skip
    ;

STRING
    : '"' ( '\\' . | ~["\\\r\n] )* '"' -> skip
    ;

WS
    : [ \t\f\r\n]+ -> skip
    ;

IF       : 'if';
ELSE     : 'else';
FOR      : 'for';
WHILE    : 'while';
PRINTLN  : 'printf';
RETURN   : 'return';
INT      : 'int';
FLOAT    : 'float';
VOID     : 'void';

LPAREN    : '(';
RPAREN    : ')';
LCURL     : '{';
RCURL     : '}';
LTHIRD    : '[';
RTHIRD    : ']';
SEMICOLON : ';';
COMMA     : ',';

INCOP    : '++';
DECOP    : '--';
ADDOP    : [+-];
MULOP    : [*/%];
NOT      : '!';
RELOP    : '<=' | '==' | '>=' | '>' | '<' | '!=';
LOGICOP  : '&&' | '||';
ASSIGNOP : '=';

ID        : [A-Za-z_] [A-Za-z0-9_]*;

// Put CONST_FLOAT before CONST_INT so 2.50 is one FLOAT token, while plain
// integers still become CONST_INT.
CONST_FLOAT
    : [0-9]+ '.' [0-9]* ([Ee] [+-]? [0-9]+)?
    | [0-9]+ [Ee] [+-]? [0-9]+
    | '.' [0-9]+ ([Ee] [+-]? [0-9]+)?
    ;

CONST_INT
    : [0-9]+
    ;

// Keep an unknown character in the token stream so the parser/error listener
// can report it instead of silently losing it at lexer level.
UNKNOWN
    : .
    ;
