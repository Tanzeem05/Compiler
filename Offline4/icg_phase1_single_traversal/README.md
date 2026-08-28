# CSE 310 ICG - Phase 1 only

This version uses the requested two-stage flow:

1. ANTLR parses the source once and creates one parse tree.
2. `ICGVisitor` traverses that parse tree exactly once and generates `code.asm`.

There is no preliminary ICG visitor and no second parse-tree traversal.

## Why local variables still work in one traversal

A local stack slot is allocated immediately when its declaration is visited:

```asm
sub esp, 4
```

The first local uses `[ebp-4]`, the next `[ebp-8]`, and so on. Local stack
slots are not reclaimed at nested-block exit; the function epilogue restores
`esp` from `ebp`. This avoids a separate pass just to count locals.

## Phase 1 only

The ICG visitor implements only the green Phase-1 productions:

- global/local scalar `int` declarations
- no-parameter function definitions
- compound statements
- expression statements
- scalar variables
- assignment
- integer constants
- `+ - * / %`
- unary `+`, unary `-`, `!`
- relational operators
- short-circuit `&&` and `||`
- postfix `++` / `--`
- `println(ID)`
- `return expression;`

The original parser grammar is kept because the assignment says to use the
same grammar as Assignment 3. Phase-2 productions simply have no ICG visitor
implementation here.

`CONST_FLOAT` remains in the grammar, but floating-point code generation throws
an error because the specification says floating-point operations are not
required.

## println

`Lexer.g4` now recognizes:

```text
PRINTLN : 'println';
```

The generated assembly calls `print_number`, which is provided by the attached
`printProc.lib`:

```asm
mov eax, [ebp-4]
call print_number
```

`code.asm` contains:

```asm
include 'printProc.lib'
```

so keep `printProc.lib` beside `code.asm` when assembling.

## Build and run

```bash
./run-script.sh sample_p1.c
```

Then:

```bash
fasm code.asm program
chmod +x program
./program
```

You can similarly assemble `optimized_code.asm`.
