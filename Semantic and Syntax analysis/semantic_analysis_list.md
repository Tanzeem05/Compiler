# Semantic analysis errors handled by `SemanticVisitor`

This document catalogs every error that `SemanticVisitor.cpp` can emit, together
with the relevant visitor/helper and the grammar construct that reaches it. The
first section contains semantic errors. The final section contains the four
syntax-recovery errors that are also emitted by this visitor; they are included
so that no diagnostic produced by `SemanticVisitor` is omitted.

## How errors are represented and reported

- `SemanticVisitor.h:117-141` defines `ExprInfo` and `NodeInfo`. Their `type`
  fields carry `int`, `float`, `void`, or `error` through the expression tree.
  `ExprInfo::isZero`/`NodeInfo::isZero` are used for the modulus-by-zero check.

- `SemanticVisitor.h:146-170` declares the error list, symbol table, type-checking
  helpers, symbol helpers, and declaration helpers used by the checks below.

- `SemanticVisitor.cpp:27-34` (`addError`) formats every visitor diagnostic as
  `Error at line <line>: <message>`, stores it in `errors`, and writes it to the
  log.

- `SemanticVisitor.cpp:17-25` (`writeErrorFile`) writes all collected errors to
  the requested error file.
  
- An expression marked with type `error` generally suppresses follow-on type
  mismatch diagnostics. In particular, `canAssign` accepts an `error` operand
  (`SemanticVisitor.cpp:89-103`).

## 1. Declaration and symbol errors

### 1.1 Multiple declaration in the current scope

**Diagnostic:** `Multiple declaration of <name>`

This is emitted in either of these cases:

- A scalar or array is declared when the same name already exists in the current
  scope. `declareVariable` performs the check with `lookupCurrent`
  (`SemanticVisitor.cpp:236-253`). It is reached from all four valid
  `declaration_list` visitors at `SemanticVisitor.cpp:731-792`, corresponding to
  `CSubset.g4:55-63`.
- `addFunction` finds an incompatible existing symbol in the current scope:
  the name is already a variable, the new occurrence is another function
  declaration, or the function has already been defined
  (`SemanticVisitor.cpp:173-200`). It is reached from every function declaration
  and definition visitor (`SemanticVisitor.cpp:330-468`), corresponding to
  `CSubset.g4:19-27`.

Only the current scope is checked, so shadowing a name from an outer scope is
allowed.

### 1.2 Duplicate named parameter

**Diagnostic:** `Multiple declaration of <name> in parameter`

`visitParameterNamedAppend` checks whether the new named parameter is already in
the accumulated parameter list (`SemanticVisitor.cpp:505-531`). This handles the
`parameter_list COMMA type_specifier ID` alternative at `CSubset.g4:30`.

### 1.3 Variable declared with type `void`

**Diagnostic:** `Variable type cannot be void`

`visitVar_declaration` emits this once for a `void` declaration
(`SemanticVisitor.cpp:673-699`; grammar at `CSubset.g4:45-53`). While the
declaration list is visited, `declareVariable` also refuses to insert any of its
names into the symbol table when `declarationType` is `void`
(`SemanticVisitor.cpp:236-241`).

## 2. Function declaration and definition errors

The checks in this section compare a definition with an earlier declaration.
They are implemented by `addFunction` (`SemanticVisitor.cpp:173-234`) and called
from the function visitors at `SemanticVisitor.cpp:330-468`.

### 2.1 Definition return type differs from its declaration

**Diagnostic:**
`Return type mismatch with function declaration in function <name>`

The stored declaration return type is compared with the definition return type
at `SemanticVisitor.cpp:205-210`.

### 2.2 Definition parameter count differs from its declaration

**Diagnostic:**
`Total number of arguments mismatch with declaration in function <name>`

Despite the word "arguments" in the message, this compares declaration and
definition **parameter counts** (`SemanticVisitor.cpp:211-217`).

### 2.3 Definition parameter type differs from its declaration

**Diagnostic:**
`<position>th argument mismatch with declaration in function <name>`

Parameter types are compared position by position at
`SemanticVisitor.cpp:218-230`. The comparison requires exact type equality; the
assignment conversion from `int` to `float` is not applied here. Only the first
mismatching position is reported.

The return-type, parameter-count, and parameter-type tests form an `if`/`else
if` chain, so at most one signature mismatch is reported for a definition. The
function is then marked defined even when a mismatch was found.

### 2.4 Unnamed parameter in a function definition

**Diagnostic:**
`<position>th parameter's name not given in function definition of <name>`

`visitFunctionDefinitionWithParameters` reports every parameter whose stored
name is empty (`SemanticVisitor.cpp:379-397`). Both valid unnamed parameters
(`CSubset.g4:31,33`) and parameters recovered from an invalid `ADDOP`
(`CSubset.g4:36-37`) have empty names. Empty-name and `void` parameters are not
inserted into the function-body scope (`SemanticVisitor.cpp:401-420`). Unnamed
parameters are allowed in function declarations because this check runs only
for definitions.

## 3. Variable and array-use errors

### 3.1 Undeclared variable (or a function used where a variable is required)

**Diagnostic:** `Undeclared variable <name>`

This is emitted when no symbol is found **or when the found symbol is a
function**:

- Scalar variable use in `visitVariableScalar`
  (`SemanticVisitor.cpp:1047-1071`; `CSubset.g4:93`).
- Indexed variable use in `visitVariableArray`
  (`SemanticVisitor.cpp:1073-1109`; `CSubset.g4:94`).
- The identifier accepted by `printf` in `visitStatementPrintln`
  (`SemanticVisitor.cpp:949-973`; `CSubset.g4:80`).

Lookup searches the active scope chain, so a variable declared in an enclosing
scope is valid.

### 3.2 Array used as a scalar

**Diagnostic:** `Type mismatch, <name> is an array`

This is emitted when an array name is used without an index:

- By `visitVariableScalar` (`SemanticVisitor.cpp:1059-1063`). This also covers
  scalar expression and assignment-LHS uses because both go through the
  `variable` rule.
- By `visitStatementPrintln` (`SemanticVisitor.cpp:958-961`) when an array is
  passed to the grammar's `printf(ID);` statement.

### 3.3 Scalar used as an array

**Diagnostic:** `<name> not an array`

`visitVariableArray` emits this when an existing non-function symbol is indexed
(`SemanticVisitor.cpp:1088-1092`; grammar at `CSubset.g4:94`).

### 3.4 Non-integer array index

**Diagnostic:** `Expression inside third brackets not an integer`

`visitVariableArray` requires an array index to have type `int`
(`SemanticVisitor.cpp:1093-1104`). An index already marked `error` does not
produce this additional diagnostic. The phrase "third brackets" refers to the
grammar tokens `LTHIRD` and `RTHIRD` (`[` and `]` in `Lexer.g4:36-37`).

## 4. Expression type errors

### 4.1 Assignment type mismatch

**Diagnostic:** `Type Mismatch`

`visitExpressionAssign` compares the variable type on the left with the logical
expression type on the right (`SemanticVisitor.cpp:1123-1155`; grammar at
`CSubset.g4:97-100`). The policy is implemented by `canAssign`
(`SemanticVisitor.cpp:89-103`):

- identical types are allowed;
- assigning an `int` value to a `float` variable is allowed;
- assigning a `float` value to an `int` variable is rejected;
- an operand already typed `error` suppresses this extra mismatch.

A `void` right-hand side is handled first by the separate void-expression error
below.

### 4.2 Void-returning function used as a value

**Diagnostic:** `Void function used in expression`

A function call receives the declared function return type in
`visitFactorFunctionCall` (`SemanticVisitor.cpp:1435-1481`). If that type is
`void`, the diagnostic is emitted when its value is consumed in any of these
contexts:

- Binary logical, relational, additive, or multiplicative expression through
  `checkVoid` (`SemanticVisitor.cpp:125-136`), called at
  `SemanticVisitor.cpp:1173-1203`, `1216-1246`, `1259-1281`, and `1310-1361`.
- Assignment right-hand side in `visitExpressionAssign`
  (`SemanticVisitor.cpp:1129-1137`).
- Unary `+` or `-` in `visitUnaryAdd` (`SemanticVisitor.cpp:1367-1386`).
- Unary `!` in `visitUnaryNot` (`SemanticVisitor.cpp:1389-1411`).
- A return expression in `visitStatementReturn`
  (`SemanticVisitor.cpp:975-995`). This only rejects a void-valued expression;
  it does not compare the returned value with the enclosing function's declared
  return type.
- A function-call argument in `visitArgumentsSingle` or
  `visitArgumentsMultiple` (`SemanticVisitor.cpp:1583-1625`).

After the report, the affected value is normally changed to type `error` to
reduce cascading diagnostics.

### 4.3 Non-integer operand of modulus

**Diagnostic:** `Non-Integer operand on modulus operator`

In `visitTermBinary`, `%` requires both operands to have type `int`. A `float`
operand causes this error (`SemanticVisitor.cpp:1310-1361`, specifically
`1331-1336`; grammar at `CSubset.g4:120-123`). Operands already marked `error`
do not cause another modulus type error.

### 4.4 Modulus by zero

**Diagnostic:** `Modulus by Zero`

`visitTermBinary` emits this for `%` when the right operand is an integer value
whose propagated `isZero` flag is true (`SemanticVisitor.cpp:1348-1351`). The
flag originates from the literal `0` in `visitFactorInt`
(`SemanticVisitor.cpp:1506-1513`) and is propagated through parentheses and the
single-child/unary-add expression paths. This is not general constant folding,
and division by zero is not checked.

## 5. Function-call errors

All checks in this section occur in `visitFactorFunctionCall`
(`SemanticVisitor.cpp:1435-1489`), reached from `ID LPAREN argument_list RPAREN`
at `CSubset.g4:133`.

### 5.1 Call to an undeclared function

**Diagnostic:** `Undeclared function <name>`

Emitted when symbol-table lookup finds no declaration for the called name
(`SemanticVisitor.cpp:1445-1449`). Therefore, a function must be declared or
defined before its call is visited.

### 5.2 Non-function symbol called as a function

**Diagnostic:** `<name> is not a function`

Emitted when lookup finds the name, but the symbol represents a variable or
array (`SemanticVisitor.cpp:1450-1454`).

### 5.3 Wrong number of call arguments

**Diagnostic:** `Total number of arguments mismatch in function <name>`

The call argument count is compared with the stored parameter count at
`SemanticVisitor.cpp:1457-1464`.

### 5.4 Wrong call argument type

**Diagnostic:** `<position>th argument mismatch in function <name>`

When the counts match, each argument is checked against its corresponding
parameter at `SemanticVisitor.cpp:1465-1477`. This uses `canAssign`, so an `int`
argument is accepted for a `float` parameter, but a `float` argument is rejected
for an `int` parameter. An argument already typed `error` suppresses the
additional mismatch, and only the first mismatching position is reported.

## 6. Syntax-recovery diagnostics emitted by this visitor

These are not semantic errors, but they are collected by the same `addError`
mechanism and count toward `Total errors`. Each corresponds to an explicit
recovery alternative in `CSubset.g4`.

### 6.1 Unexpected `+` or `-` in a parameter list

**Diagnostic:** `syntax error, unexpected token(s) '<operator>' before ')'`

Handled by `visitParameterInvalidSingle` and `visitParameterInvalidAppend`
(`SemanticVisitor.cpp:558-601`) for the recovery alternatives at
`CSubset.g4:35-37`. The invalid `ADDOP` is removed from the corrected text and an
unnamed parameter of the preceding type is retained.

### 6.2 Unexpected operator and identifier in a declaration list

**Diagnostic:**
`syntax error, unexpected token(s) '<operator> <name>' in declaration list`

Handled by `visitDeclarationInvalidAppend` (`SemanticVisitor.cpp:794-806`) for
the recovery alternative at `CSubset.g4:61-62`, such as `int x-y,z;`. The bad
operator/name pair is omitted from the corrected declaration text.

### 6.3 Invalid `=` after an additive operator

**Diagnostic:** `syntax error, invalid operand '=' after '<operator>'`

Handled by `visitSimpleInvalidAssignment` (`SemanticVisitor.cpp:1283-1297`) for
the recovery alternative at `CSubset.g4:116-117`, intended for malformed input
such as `2+=6`.

### 6.4 Missing expression-statement semicolon

**Diagnostic:** `syntax error, missing ';' after expression '<expression>'`

Handled by `visitExpressionStatementMissingSemicolon`
(`SemanticVisitor.cpp:1025-1041`) for the recovery alternative at
`CSubset.g4:88-89`.

## Checks that are not implemented

For clarity, the current visitor does **not** diagnose every possible C semantic
error. Notably, it does not compare a `return` expression type with its enclosing
function return type, require integer/scalar conditions for `if`/`while`/`for`,
validate array sizes, reject `void` parameter types as such, detect division by
zero, require every declared function to be defined, or perform general
constant-expression evaluation. `Lexer.g4` only tokenizes/skips input and does
not perform semantic checks.
