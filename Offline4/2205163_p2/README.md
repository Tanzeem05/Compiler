# CSE 310 — Intermediate Code Generation, Phase 2

Student ID: 2205163

## Build and run

Requirements: Linux, a C++17 compiler, ANTLR4 C++ runtime **4.13.2**, and FASM.
Java and the ANTLR generator are optional because generated C++ sources are included.
Linux must support execution of 32-bit i386 ELF programs.

```sh
./run-script.sh tests/phase2.c
fasm code.asm program
chmod +x program
./program

fasm optimized_code.asm optimized_program
chmod +x optimized_program
./optimized_program
```

`run-script.sh` accepts one source path and writes `code.asm` and
`optimized_code.asm` in the script's directory. The demonstration deliberately
returns exit status 23. To compile another input without rebuilding:

```sh
./icg.out path/to/input.c
```

Direct invocation writes assembly in the current working directory. `printProc.lib`
is loaded beside the compiler executable, so invocation from another directory works.
Compilation errors return a nonzero status and remove incomplete assembly outputs.

To regenerate the parser, set `ANTLR_JAR` to the ANTLR **4.13.2** complete JAR.
The script also recognizes an installed `antlr4` command; use a matching version.
Runtime paths can be supplied through `ANTLR4_INCLUDE` and `ANTLR4_LIB` when
`pkg-config` does not provide them.

## Implementation

- The Assignment 3 grammar and its visitor alternative names are retained. The
  two existing `if` alternatives were reordered to resolve the dangling `else`
  ambiguity in favor of the nearest unmatched `if`. No embedded actions are used.
- Integer scalars and fixed-size arrays support global and block scope, shadowing,
  indexing, assignment, and postfix increment/decrement.
- Expressions include signed arithmetic, division/remainder, unary operators,
  comparisons, and short-circuit `&&` and `||` using conditional jumps.
- Statements include nested blocks, `if`, `if/else`, `while`, `for`, `println(ID)`,
  and expression returns. An empty `for` condition means true.
- Function declarations, definitions, integer parameters, void calls, forward
  declarations, early returns, recursion, and mutually recursive functions work.
  A called function must be declared before use and defined in the input program.
- All locals, including arrays and declarations in branches or loops, occupy a
  fixed frame reserved once at function entry. EBP addresses locals at negative
  offsets and parameters at positive offsets. Arguments are evaluated and pushed
  left to right, `RET n` in the callee removes them, and EAX carries the return value.
  Expression intermediates and array indices are saved on the stack across calls.
  The printing procedure also receives its integer argument on the stack.
- Code is emitted during one visitor traversal into **one temporary file**,
  `code.asm.tmp`. Frame markers are replaced with numeric `SUB ESP, n` instructions
  when the temporary file is copied, without another tree traversal. Final output
  combines global storage, the emitted functions, and
  the stack-buffered integer printing procedure. The temporary file is removed.
- Source line comments annotate generated code. Function and global names are kept
  as written; names that conflict with assembler keywords or the print procedure
  are escaped.
- The peephole optimizer removes redundant moves, register push/pop pairs, safe
  arithmetic identities, adjacent internal labels, and jumps to the next label.
  It folds literal arithmetic into immediate operands, preserves source comments,
  and checks flag use before removing operations that set flags.

## Assembly pattern

The generator follows the supplied `a.out` compiler's assembly conventions:
`entry main`, data before executable code, plain function labels, sequential
`.L1`, `.L2`, ... labels, EBP-relative storage, scalar `MOV` assignments, stack-held
expression results, ECX for multiply/divide operands, EDX for add/compare operands,
and `RET n` for function arguments. Array accesses use `[name+EBX]` for globals
and `[EBP+ESI]` for locals. Conditions jump directly to their true/false destinations;
`for` loops place the update block between the condition and body in the assembly.

The output is not intended to be byte-for-byte identical. It retains these
correctness and assignment requirements:

- Signed division uses `CDQ`/`IDIV`, so negative values work correctly.
- All local storage is reserved once at entry, including declarations inside loops.
- `println` takes a stack argument, with the same `print_number` procedure name.
- `main` preserves its return status; falling off a function returns zero.
- Reserved assembler names are escaped, and a startup wrapper is emitted if the
  program calls `main` recursively.

The compiler does not invoke `a.out`; its visitor generates these patterns itself.

Floating-point code generation is explicitly unsupported, as permitted by the
specification. The supplied grammar does not include array parameters, `break`,
`continue`, `return;`, variable initializers, or an omitted `for` update expression;
these are not added. Local variables must be initialized before being read, and
array indices must stay within their declared bounds. As in C, signed overflow
and division by zero do not have defined results here.

## Verification

After building:

```sh
python3 tests/run_tests.py
# Optionally also run a directory of assignment sample inputs:
python3 tests/run_tests.py --samples /path/to/input
```

The suite assembles and executes both output files, compares defined test programs
against GCC, stresses repeated block declarations, and checks invalid inputs and
optimizer hazards. Two supplied samples (`test1_i.c` and `test7_i.c`) read
uninitialized locals, so their output is not compared with GCC.

## Submission archive

```sh
python3 package.py
```

This creates `2205163_P2.zip` containing a `2205163/` folder with source files,
generated parser sources, build/run scripts, printing library, and custom tests.
Executables, temporary files, editor caches, and generated assembly are excluded.
