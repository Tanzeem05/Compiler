# Assignment 3 - Simple Visitor Implementation

This version is intentionally written in a simple style.

## Main idea

Every visitor returns `any`.
Inside that `any`, the visitor returns one small `NodeInfo` object.
The parent visitor directly reads the result returned by its child.

So the basic flow is:

```text
visit child
   -> get NodeInfo
   -> perform semantic check
   -> log the grammar rule
   -> return NodeInfo
```

There are no `savedExpr`, `savedParams`, or `savedArguments` maps.

## Symbol table

The supplied `SymbolInfo -> ScopeTable -> SymbolTable` chained-hash design is used.
`SymbolInfo` is extended only with the information needed by Assignment 3:

- variable data type
- array flag
- function flag
- declared/defined flags
- function return type
- parameter types
- parameter names

Every scope has exactly 30 buckets.
The hash function is:

```cpp
int hashOf(const string& name) {
    unsigned long sum = 0;
    for (char c : name) {
        sum += (unsigned char)c;
    }
    return (int)(sum % NUM_BUCKETS);
}
```

## Files

- `Lexer.g4`
- `CSubset.g4`
- `2205163_symbol_table.hpp`
- `SemanticVisitor.h`
- `SemanticVisitor.cpp`
- `main.cpp`
- `run-script.sh`

## Run

```bash
chmod +x run-script.sh
./run-script.sh input.c
```

This creates:

```text
log.txt
error.txt
```

For exact comparison with a supplied expected output:

```bash
cmp -s log.txt expected_log.txt && echo "LOG EXACT MATCH"
cmp -s error.txt expected_error.txt && echo "ERROR EXACT MATCH"
```

If a comparison fails:

```bash
diff -u expected_log.txt log.txt
diff -u expected_error.txt error.txt
```
