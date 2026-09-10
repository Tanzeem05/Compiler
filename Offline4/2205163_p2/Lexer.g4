lexer grammar Lexer;

// Keep the lexer simple. The parser/visitor performs the actual ICG work.

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
PRINTLN  : 'println';
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

CONST_FLOAT
    : [0-9]+ '.' [0-9]* ([Ee] [+-]? [0-9]+)?
    | [0-9]+ [Ee] [+-]? [0-9]+
    | '.' [0-9]+ ([Ee] [+-]? [0-9]+)?
    ;

CONST_INT
    : [0-9]+
    ;

UNKNOWN
    : .
    ;
