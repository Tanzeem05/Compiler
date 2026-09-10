#!/usr/bin/env python3
"""Compare execution of both compilers' assembly for every input/*.c file."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent.parent


def command(args, cwd):
    try:
        p = subprocess.run([str(x) for x in args], cwd=cwd, capture_output=True,
                           text=True, timeout=15)
        return {'stdout': p.stdout, 'stderr': p.stderr, 'exit': p.returncode}
    except subprocess.TimeoutExpired:
        return {'stdout': '', 'stderr': 'Timed out after 15 seconds', 'exit': None}


def assemble_and_run(assembly, directory):
    if not assembly.exists():
        return {'error': f'{assembly.name} was not generated'}
    binary = assembly.with_suffix('.out')
    assembled = command(['fasm', assembly, binary], directory)
    if assembled['exit'] != 0:
        return {'error': 'FASM failed', 'assembly_result': assembled}
    binary.chmod(0o755)
    result = command([binary], directory)
    if result['exit'] is None or result['exit'] < 0:
        result['error'] = 'Program timed out or crashed'
    return result


def matches(a, b):
    return ('error' not in a and 'error' not in b and
            all(a[key] == b[key] for key in ('stdout', 'stderr', 'exit')))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, default=ROOT / 'input')
    parser.add_argument('--reference', type=Path, default=ROOT / 'a.out')
    parser.add_argument('--compiler', type=Path, default=ROOT / 'icg.out')
    parser.add_argument('--reference-library', type=Path, default=ROOT.parent / 'printProc.lib',
                        help='Original register-argument printProc.lib expected by a.out')
    parser.add_argument('--report', type=Path, default=ROOT / 'tests/reference_comparison.md')
    args = parser.parse_args()
    sources = sorted(args.input.resolve().glob('*.c'))
    if not sources:
        raise SystemExit(f'No C tests found in {args.input}')
    for path in (args.reference, args.compiler, args.reference_library):
        if not path.is_file():
            raise SystemExit(f'Missing required file: {path}')
    work = Path(tempfile.mkdtemp(prefix='icg-reference-comparison-'))
    results = []
    for source in sources:
        record = {'test': source.name}
        for label, compiler, assemblies in (
                ('reference', args.reference, ('code.asm', 'optcode.asm')),
                ('ours', args.compiler, ('code.asm', 'optimized_code.asm'))):
            directory = work / source.stem / label
            directory.mkdir(parents=True)
            if label == 'reference':
                shutil.copy2(args.reference_library, directory / 'printProc.lib')
            compiled = command([compiler.resolve(), source], directory)
            record[label + '_compile'] = compiled
            for assembly in assemblies:
                key = label + ('_raw' if assembly == 'code.asm' else '_optimized')
                record[key] = (assemble_and_run(directory / assembly, directory)
                               if compiled['exit'] == 0 else {'error': 'Compilation failed'})
        record['raw_matches'] = matches(record['reference_raw'], record['ours_raw'])
        record['optimized_matches'] = matches(record['reference_raw'], record['ours_optimized'])
        record['reference_optimized_matches'] = matches(record['reference_raw'], record['reference_optimized'])
        results.append(record)
        print(f"{source.name}: code.asm={'MATCH' if record['raw_matches'] else 'DIFFER'}; "
              f"optimized_code.asm={'MATCH' if record['optimized_matches'] else 'DIFFER'}; "
              f"reference optcode.asm={'MATCH' if record['reference_optimized_matches'] else 'DIFFER'}",
              flush=True)

    report = [
        '# Comparison against a.out', '',
        f'Input directory: `{args.input.resolve()}`',
        f'Reference compiler: `{args.reference.resolve()}`',
        f'Reference printing library: `{args.reference_library.resolve()}`',
        f'Generated assembly, executables, and reference files: `{work}`', '',
        'Each `.c` file is compiled separately. All four assembly files are assembled '
        'with FASM and executed. MATCH means identical stdout, stderr, and exit status '
        'to the executable generated from the reference compiler’s `code.asm`.', '',
        '`input/output.txt` is expected-output documentation, not a C test.', '',
        '| Test | Our code.asm | Our optimized_code.asm | Reference optcode.asm |',
        '|---|---|---|---|',
    ]
    for row in results:
        statuses = ['MATCH' if row[key] else 'DIFFER' for key in
                    ('raw_matches', 'optimized_matches', 'reference_optimized_matches')]
        report.append('| ' + row['test'] + ' | ' + ' | '.join(statuses) + ' |')
    report += ['', '## Exact program output', '']
    for row in results:
        report += ['### ' + row['test'], '']
        for key in ('reference_raw', 'reference_optimized', 'ours_raw', 'ours_optimized'):
            result = row[key]
            if key != 'reference_raw' and matches(row['reference_raw'], result):
                report.append(f'`{key}`: identical to reference.')
                continue
            report += [f'`{key}` — exit status: {result.get("exit", "unavailable")}', '',
                       '```text', result.get('stdout', '').rstrip('\n'), '```', '']
            if result.get('stderr'):
                report += ['stderr:', '```text', result['stderr'].rstrip('\n'), '```', '']
            if result.get('error'):
                report += ['Error: ' + json.dumps(result), '']
        report.append('')
    report += ['## Interpretation', '',
               '`test1_i.c` reads the uninitialized local `ll`; `test7_i.c` reads '
               'the uninitialized local `i`. Their comparisons describe the observed '
               'runs, not a guarantee for uninitialized C values.', '']
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text('\n'.join(report))
    args.report.with_suffix('.json').write_text(json.dumps(results, indent=2) + '\n')
    matched = sum(row['raw_matches'] and row['optimized_matches'] for row in results)
    print(f'\n{matched}/{len(results)} tests match a.out for both compiler outputs.')
    print(f'Report: {args.report}')
    return 0 if matched == len(results) else 1


if __name__ == '__main__':
    raise SystemExit(main())
