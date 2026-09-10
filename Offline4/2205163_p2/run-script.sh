#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
    echo "Usage: ./run-script.sh <input.c>" >&2
    exit 1
fi

INPUT="$(realpath "$1")"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

if [[ -n "${ANTLR_JAR:-}" && -f "${ANTLR_JAR}" ]]; then
    java -jar "$ANTLR_JAR" -Dlanguage=Cpp -visitor -no-listener -lib . CSubset.g4
elif command -v antlr4 >/dev/null 2>&1; then
    antlr4 -Dlanguage=Cpp -visitor -no-listener -lib . CSubset.g4
else
    REQUIRED_GENERATED=(
        CSubsetLexer.cpp CSubsetLexer.h
        CSubsetParser.cpp CSubsetParser.h
        CSubsetBaseVisitor.cpp CSubsetBaseVisitor.h
        CSubsetVisitor.cpp CSubsetVisitor.h
    )

    for generated in "${REQUIRED_GENERATED[@]}"; do
        if [[ ! -f "$generated" ]]; then
            echo "ANTLR4 generator not found and $generated is missing." >&2
            echo "Install antlr4 or set ANTLR_JAR=/path/to/antlr-4.x-complete.jar" >&2
            exit 1
        fi
    done

    echo "ANTLR4 generator not found; using checked-in generated sources." >&2
fi

if command -v pkg-config >/dev/null 2>&1 && \
   pkg-config --exists antlr4-runtime 2>/dev/null; then
    read -r -a ANTLR_CFLAGS <<< "$(pkg-config --cflags antlr4-runtime)"
    read -r -a ANTLR_LIBS <<< "$(pkg-config --libs antlr4-runtime)"
else
    if [[ -d /usr/local/include/antlr4-runtime ]]; then
        DEFAULT_ANTLR_INCLUDE=/usr/local/include/antlr4-runtime
        DEFAULT_ANTLR_LIB=/usr/local/lib
    else
        DEFAULT_ANTLR_INCLUDE=/usr/include/antlr4-runtime
        DEFAULT_ANTLR_LIB=/usr/lib
    fi
    ANTLR4_INCLUDE="${ANTLR4_INCLUDE:-$DEFAULT_ANTLR_INCLUDE}"
    ANTLR4_LIB="${ANTLR4_LIB:-$DEFAULT_ANTLR_LIB}"
    ANTLR_CFLAGS=("-I${ANTLR4_INCLUDE}")
    ANTLR_LIBS=("-L${ANTLR4_LIB}" "-Wl,-rpath,${ANTLR4_LIB}" -lantlr4-runtime)
fi

g++ -std=c++17 -O2 -Wall -Wextra \
    "${ANTLR_CFLAGS[@]}" -I. \
    CSubsetLexer.cpp \
    CSubsetParser.cpp \
    CSubsetBaseVisitor.cpp \
    CSubsetVisitor.cpp \
    ICGVisitor.cpp \
    PeepholeOptimizer.cpp \
    main.cpp \
    "${ANTLR_LIBS[@]}" \
    -o icg.out

./icg.out "$INPUT"

echo "Assemble with: fasm code.asm program"
echo "Then run:      chmod +x program && ./program"
