#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "Usage: ./run-script.sh <input.c>" >&2
    exit 1
fi

INPUT="$1"
if [[ ! -f "$INPUT" ]]; then
    echo "Input file not found: $INPUT" >&2
    exit 1
fi

# Generate lexer/parser + visitor from the combined CSubset grammar.
if command -v antlr4 >/dev/null 2>&1; then
    antlr4 -Dlanguage=Cpp -visitor -no-listener -lib . CSubset.g4
elif [[ -n "${ANTLR_JAR:-}" && -f "${ANTLR_JAR}" ]]; then
    java -jar "$ANTLR_JAR" -Dlanguage=Cpp -visitor -no-listener -lib . CSubset.g4
else
    echo "ANTLR4 generator not found." >&2
    echo "Configure antlr4 or export ANTLR_JAR=/path/to/antlr-4.x-complete.jar" >&2
    exit 1
fi

if pkg-config --exists antlr4-runtime 2>/dev/null; then
    read -r -a ANTLR_CFLAGS <<< "$(pkg-config --cflags antlr4-runtime)"
    read -r -a ANTLR_LIBS <<< "$(pkg-config --libs antlr4-runtime)"
else
    ANTLR4_INCLUDE="${ANTLR4_INCLUDE:-/usr/local/include/antlr4-runtime}"
    ANTLR4_LIB="${ANTLR4_LIB:-/usr/local/lib}"
    ANTLR_CFLAGS=("-I${ANTLR4_INCLUDE}")
    # Keep the non-standard library directory in the executable so parser.out
    # can find the ANTLR runtime when it is launched directly.
    ANTLR_LIBS=("-L${ANTLR4_LIB}" "-Wl,-rpath,${ANTLR4_LIB}" -lantlr4-runtime)
fi

g++ -std=c++17 -O2 -Wall -Wextra \
    "${ANTLR_CFLAGS[@]}" -I. \
    CSubsetLexer.cpp \
    CSubsetParser.cpp \
    CSubsetBaseVisitor.cpp \
    CSubsetVisitor.cpp \
    SemanticVisitor.cpp \
    main.cpp \
    "${ANTLR_LIBS[@]}" \
    -o parser.out

./parser.out "$INPUT"

echo "Generated log.txt and error.txt"
