#!/usr/bin/env python3
"""Create the assignment's Phase 2 submission archive from an explicit file list."""
from pathlib import Path
from zipfile import ZipFile, ZIP_DEFLATED

root = Path(__file__).resolve().parent
files = [
    'main.cpp', '2205163_symbol_table.hpp', 'ICGVisitor.h', 'ICGVisitor.cpp',
    'PeepholeOptimizer.h', 'PeepholeOptimizer.cpp', 'CSubset.g4', 'Lexer.g4',
    'CSubsetLexer.cpp', 'CSubsetLexer.h', 'CSubsetParser.cpp', 'CSubsetParser.h',
    'CSubsetBaseVisitor.cpp', 'CSubsetBaseVisitor.h', 'CSubsetVisitor.cpp', 'CSubsetVisitor.h',
    'run-script.sh', 'printProc.lib', 'README.md', 'package.py', 'tests/run_tests.py',
]
files += [str(path.relative_to(root)) for path in sorted((root / 'tests').glob('*.c'))]
for name in files:
    if not (root / name).is_file():
        raise SystemExit(f'Missing submission file: {name}')
archive = root / '2205163_P2.zip'
with ZipFile(archive, 'w', ZIP_DEFLATED) as output:
    for name in files:
        output.write(root / name, '2205163/' + name)
print(f'Created {archive.name} ({len(files)} files)')
