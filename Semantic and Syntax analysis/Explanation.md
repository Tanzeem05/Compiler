# Complete Workflow of the Compiler Front End

## 1. What this project does

This project is a small compiler front end for a C-like language. It does not generate machine code or assembly. Its job is to:

1. read a source program from an input file;
2. tokenize the source with an ANTLR-generated lexer;
3. build a parse tree with an ANTLR-generated parser;
4. walk that tree with `SemanticVisitor`;
5. maintain nested symbol tables and perform syntax-recovery and semantic checks;
6. write a detailed grammar/semantic trace to `log.txt`; and
7. write only the collected errors to `error.txt`.

The end-to-end runtime path is:

```text
input file
    |
    v
main.cpp reads the whole file into a string
    |
    v
ANTLRInputStream
    |
    v
CSubsetLexer -> tokens -> CommonTokenStream
    |
    v
CSubsetParser.start() -> parse tree
    |
    v
SemanticVisitor.visit(tree)
    |             |
    |             +-> symbol-table operations and semantic checks
    |             +-> grammar-rule and error entries in log.txt
    |
    v
visitor.writeErrorFile("error.txt")
    |
    v
error.txt receives the collected error messages
```

## 2. Build-and-run workflow

The normal command is:

```bash
chmod +x run-script.sh
./run-script.sh <input.c>
```

`run-script.sh` performs three stages.

### 2.1 Validate the command line

The script requires exactly one argument and verifies that it names an existing regular file. If either condition fails, it prints a message to standard error and exits.

### 2.2 Generate and compile the ANTLR code

The script generates the C++ lexer, parser, base visitor, and visitor from `CSubset.g4`. That grammar imports the lexer grammar from `Lexer.g4`.

It first tries an `antlr4` executable. If that is unavailable, it tries the JAR identified by `ANTLR_JAR`. Generation uses:

```text
-Dlanguage=Cpp -visitor -no-listener -lib . CSubset.g4
```

The important consequences are:

- the target language is C++;
- visitor classes are generated;
- parse listeners are not generated; and
- the imported lexer grammar is resolved from the current directory.

The script then locates the ANTLR4 C++ runtime, preferably through `pkg-config`, and compiles the generated sources together with `SemanticVisitor.cpp` and `main.cpp`. The resulting executable is `parser.out`.

The generated files such as `CSubsetLexer.cpp`, `CSubsetParser.cpp`, `CSubsetBaseVisitor.cpp`, and their headers are framework code derived from the grammars. The hand-written behavior is mainly in `main.cpp`, `SemanticVisitor.h`, `SemanticVisitor.cpp`, and `2205163_symbol_table.hpp`.

### 2.3 Execute the parser

Finally, the script runs:

```bash
./parser.out <input.c>
```

On successful completion it reports that `log.txt` and `error.txt` were generated. These files are created in the process's current working directory, not beside the input file unless that is also the current directory.

## 3. Reading the input in `main.cpp`

`main` expects exactly one argument after the executable name. If the argument is missing or there are extra arguments, it prints a usage message and returns status `1`.

It opens the supplied file with `ifstream`. If opening fails, it prints `Could not open input file` and returns status `1` before creating the normal output files.

Once the file is open, the entire file is copied into one `std::string` named `source` using stream-buffer iterators. Keeping the original source string is useful later because parse-tree token intervals do not include skipped whitespace and comments, while character indexes can still be used to recover exact portions of the original input.

`countLines(source)` calculates the line total for the final log summary:

- an empty input has zero lines;
- every newline character counts as a line; and
- if the file does not end in a newline, the final partial line adds one.

Next, `log.txt` is opened with `ios::trunc`, so an older log is replaced at the start of every valid run.

## 4. Lexical analysis

`main.cpp` wraps the source string in `antlr4::ANTLRInputStream` and passes that stream to `CSubsetLexer`.

`Lexer.g4` defines the language's tokens:

- keywords: `if`, `else`, `for`, `while`, `printf`, `return`, `int`, `float`, and `void`;
- punctuation: parentheses, braces, square brackets, semicolon, and comma;
- operators: increment/decrement, arithmetic, logical, relational, assignment, and logical negation;
- identifiers;
- integer constants; and
- floating-point constants, including decimal and exponent forms.

Comments, strings, and whitespace are skipped. They therefore do not become parser tokens. `CONST_FLOAT` is placed before `CONST_INT` so text such as `2.50` is recognized as one floating-point token. Any otherwise unrecognized character becomes an `UNKNOWN` token and stays in the token stream.

The default lexer error listeners are removed. Consequently, lexer diagnostics are not printed by ANTLR to the console by this program.

## 5. Parsing and parse-tree creation

The lexer is connected to an `antlr4::CommonTokenStream`, which supplies tokens to `CSubsetParser`. The parser's default error listeners are also removed, so standard ANTLR parser diagnostics are suppressed.

Parsing begins with:

```cpp
antlr4::tree::ParseTree* tree = parser.start();
```

The `start` rule delegates to `program`. A program consists of one or more `unit` nodes, where a unit can be:

- a variable declaration;
- a function declaration; or
- a function definition.

The grammar then describes parameters, blocks, statements, variables, assignments, expression precedence, function calls, and argument lists. Labeled alternatives such as `# ProgramMultiple`, `# VariableArray`, and `# FactorFunctionCall` cause ANTLR to dispatch directly to the corresponding methods such as `visitProgramMultiple`, `visitVariableArray`, and `visitFactorFunctionCall`.

Expression precedence is represented by the nesting of grammar rules:

```text
expression
  -> logic_expression
     -> rel_expression
        -> simple_expression       (+ and -)
           -> term                 (*, /, and %)
              -> unary_expression  (unary +, unary -, and !)
                 -> factor         (variables, calls, constants, parentheses)
```

The grammar also contains explicit recovery alternatives for the malformed patterns required by the assignment, including:

- an unexpected `+` or `-` in a parameter list;
- an unexpected `+ ID` or `- ID` inside a declaration list;
- a missing semicolon after an expression; and
- malformed input such as `2 += 6`.

These alternatives are important because the normal ANTLR error listeners are disabled. They let the semantic visitor create the project's expected custom syntax-error messages and continue processing the rest of the tree. They are targeted recovery rules, not a general replacement for every possible parser error.

## 6. Starting semantic analysis

After parsing, `main.cpp` constructs:

```cpp
SemanticVisitor visitor(source, logFile, countLines(source));
```

The visitor stores:

- the original source text;
- a reference to the already-open `log.txt` stream;
- the total line count;
- a `SymbolTable`;
- a vector of error strings;
- temporary declaration and scope state.

Its constructor creates the global scope, whose ID is `1`.

Then `visitor.visit(tree)` starts a depth-first walk. Each visitor method explicitly visits its child nodes first, obtains their results, performs the checks relevant to the parent rule, logs the parent rule, and returns information upward.

## 7. Information passed between visitor methods

ANTLR visitor methods return `std::any`. This implementation consistently places one `NodeInfo` object inside that `any`.

`NodeInfo` can carry:

- `text`: normalized or recovered source text for the subtree;
- `changed`: whether a recovery rule changed or removed malformed input;
- `type`: the expression/type result (`int`, `float`, `void`, or `error`);
- `isZero`: whether the subtree is the integer literal zero;
- `parameters`: function parameter types and names; and
- `arguments`: function-call argument types and zero information.

`getInfo` safely returns a default `NodeInfo` when a child returns an empty `any`. `makeInfo` initializes the text and changed flag for a result.

This creates the recurring visitor pattern:

```text
visit child node(s)
    -> read child NodeInfo
    -> update symbol table / perform checks
    -> combine child text and attributes
    -> write the grammar-rule entry to log.txt
    -> return a new NodeInfo to the parent
```

Because children are visited before their parent is logged, `log.txt` is largely a bottom-up trace. For example, an integer literal is logged as a `factor`, then its enclosing `unary_expression`, `term`, `simple_expression`, `rel_expression`, and so on.

## 8. Reconstructed text and line information

Visitor methods build a normalized representation of each recognized construct. Examples include:

- declarations as `int x,y;`;
- assignments as `x=expression`;
- blocks as braces with statements on separate lines;
- float constants formatted to exactly two decimal places; and
- recovered constructs with invalid pieces omitted.

This text is for logging and upward propagation; the visitor does not rewrite the input file.

The class also contains two source helpers:

- `sourceText(ctx)` retrieves the original character range covered by a parse context when valid indexes are available, falling back to `ctx->getText()`;
- `gapBetween(left, right)` retrieves original text between two contexts, with a newline fallback.

The current visitor's main reconstruction paths mostly assemble normalized strings directly. The original `source` is still retained for these helper facilities and accurate token-index-based access.

Log and error line numbers normally come from the first token of the relevant parse context. Some list-like parent rules deliberately use the current child's starting line.

## 9. Symbol-table design and scope lifecycle

The symbol table is implemented in `2205163_symbol_table.hpp` as three layers:

```text
SymbolTable
  -> current ScopeTable
       -> 30 hash buckets
            -> linked lists of SymbolInfo objects
```

The hash value is the sum of the identifier's unsigned character values modulo `30`. Collisions are stored as linked lists in the corresponding bucket.

Each `SymbolInfo` stores the identifier name and token category (`ID`) plus semantic metadata:

- variable data type;
- whether it is an array;
- whether it is a function;
- whether a function has been defined;
- function return type; and
- function parameter types.

`lookUpCurrent` searches only the current scope and is used for duplicate declarations. `lookUp` starts at the current scope and follows parent scopes, so a local declaration can shadow an outer declaration and ordinary uses can find enclosing declarations.

Scope IDs form a hierarchy such as `1`, `1.1`, `1.2`, and `1.2.1`.

### Function scopes

A function definition creates a child scope before visiting its compound body. Named, non-`void` parameters are inserted into that scope. The `nextCompoundIsFunctionBody` flag tells the immediately following compound-statement visitor to reuse this scope instead of creating another nested scope. The scope is printed while it still exists and is removed after the function body finishes.

A function declaration briefly enters and exits an empty scope. That scope is not printed, but creating it preserves the expected scope-number sequence.

### Nested block scopes

A compound statement that is not the outer function body creates a new child scope. It visits all contained statements, logs and prints the active scope chain, then exits and deletes that block scope. Empty compound statements follow the same lifecycle.

At the end of the whole program, the global scope is printed again.

## 10. Declarations and functions

When visiting a variable declaration, the visitor first obtains the declared type and temporarily stores it in `declarationType`. Each scalar or array in the declaration list is then inserted into the current scope with that type and array flag.

The declaration checks include:

- a variable cannot have type `void`; and
- a name cannot be declared more than once in the same scope.

For functions, `addFunction` records the return type, parameter types, and whether the function is a declaration or definition. It detects:

- a function name conflicting with an existing variable;
- repeated declarations or definitions;
- a definition whose return type differs from an earlier declaration;
- a definition whose parameter count differs from its declaration; and
- a definition whose parameter types differ from its declaration.

Parameter-list visitors collect both types and names. They detect duplicate named parameters. A function declaration may contain unnamed parameters, but a function definition reports each parameter whose name is missing.

## 11. Expression analysis

Types are propagated upward through the expression tree.

### Variables and arrays

A scalar use must name a declared, non-function, non-array symbol. An indexed use must name an array, and its index must have type `int`. These checks produce errors for undeclared variables, scalar/array misuse, and non-integer indexes.

### Assignment and arithmetic

`canAssign` permits equal types and widening from `int` to `float`. It does not permit narrowing from `float` to `int`. If either side already has type `error`, assignment compatibility returns true to avoid cascading type-mismatch messages.

For ordinary arithmetic, the result is `float` if either operand is `float`; otherwise it is `int`. An existing `error` propagates. Using a `void` function result in an expression produces an error.

The modulus operator has extra rules:

- both operands must be integers; and
- an integer literal zero as the right operand produces `Modulus by Zero`.

Relational and logical binary operations produce `int` when their operands are valid. Unary logical negation also produces `int`. Parentheses preserve the inner expression's type, and increment/decrement preserve the variable's type.

### Function calls

A call must refer to a declared function. The visitor compares the collected arguments with the function's stored parameter types and reports a count mismatch or the first incompatible positional argument. The call expression's type is the function return type.

If a void-returning call is used where a value is required, the enclosing visitor reports `Void function used in expression`.

### Statements

Statement visitors recursively analyze declarations, expressions, nested blocks, loops, conditionals, `printf`, and returns. A `printf(ID)` argument must be a declared scalar variable. Return-expression traversal validates the expression itself, although this implementation does not store the current function return type and therefore does not compare a return expression against its enclosing function's declared return type.

## 12. How `log.txt` is generated

`logRule` writes entries in this form:

```text
Line <line-number>: <grammar-rule> : <production>

<normalized subtree text>
```

Blank-line counts vary for certain higher-level rules so the result matches the required reference-log format.

The log contains more than successful grammar reductions. `addError` immediately writes every custom syntax or semantic error into `log.txt` at the point where the visitor detects it. This means an error appears in traversal order among the surrounding rule entries.

Compound-statement visitors also call `symbolTable.printAll(logFile)`. The current scope is printed first, followed by its parents. Only nonempty hash buckets are displayed, except that an empty scope still has its scope heading.

When traversal reaches `visitStart`, it:

1. logs the final `start : program` reduction;
2. prints the remaining global symbol table;
3. writes `Total lines: N`; and
4. writes `Total errors: M`.

The normalized whole-program text is carried through `NodeInfo`, but the `start` log entry intentionally passes an empty text string. The detailed program text has already appeared in the lower `program` entries.

## 13. How `error.txt` is generated

Every call to `addError` creates one string with the format:

```text
Error at line <line-number>: <message>
```

That string is handled in two ways:

1. it is appended immediately to `log.txt`; and
2. it is stored in the visitor's `errors` vector.

Only after the entire parse tree has been visited does `main.cpp` call:

```cpp
visitor.writeErrorFile("error.txt");
```

`writeErrorFile` opens `error.txt` with truncation and writes the collected messages in detection order, with a blank line between errors. Therefore:

- `log.txt` is a full rule trace plus symbol tables, errors, and totals;
- `error.txt` contains only errors; and
- if no custom errors were found, `error.txt` is created as an empty file.

## 14. Output lifetime and completion

After `writeErrorFile` returns, `main` returns `0`. The output streams close automatically as their C++ objects are destroyed. The visitor and symbol-table destructors also delete all remaining scopes and chained `SymbolInfo` objects.

Neither output file is appended across runs: both are truncated. The input source file is opened only for reading and is never modified.

## 15. Responsibilities of the main project files

| File | Responsibility |
|---|---|
| `run-script.sh` | Validates the input path, regenerates ANTLR sources, compiles the program, and executes it. |
| `Lexer.g4` | Defines keywords, operators, identifiers, constants, skipped text, and unknown tokens. |
| `CSubset.g4` | Defines the parser rules, labeled visitor alternatives, precedence structure, and targeted recovery alternatives. |
| Generated `CSubset*` files | Implement the lexer, parser, parse-tree contexts, and visitor interfaces produced by ANTLR. |
| `main.cpp` | Reads the input, counts lines, creates the ANTLR pipeline, starts parsing, runs semantic traversal, and requests the error file. |
| `SemanticVisitor.h` | Declares visitor methods, result structures, analysis state, and helper operations. |
| `SemanticVisitor.cpp` | Reconstructs subtree text, logs rules, manages scopes, checks semantics, and collects errors. |
| `2205163_symbol_table.hpp` | Implements symbols, 30-bucket scope tables, nested scope lookup, and scope printing. |
| `log.txt` | Generated full traversal log with errors, symbol-table snapshots, and final totals. |
| `error.txt` | Generated error-only report. |

In short, `main.cpp` builds the pipeline, ANTLR turns characters into a parse tree, `SemanticVisitor` turns that tree into semantic information and diagnostic output, and the symbol table supplies the scope-aware name and type information needed by the visitor.
