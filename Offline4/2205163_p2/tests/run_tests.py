#!/usr/bin/env python3
"""Assemble/run both outputs and compare with GCC; build icg.out first."""
import argparse
import pathlib
import re
import subprocess
import tempfile

ROOT = pathlib.Path(__file__).resolve().parent.parent


def run(command, cwd, ok=True):
    result = subprocess.run([str(x) for x in command], cwd=cwd, text=True,
                            capture_output=True, timeout=20)
    if ok and result.returncode:
        raise AssertionError(f"{command}: exit {result.returncode}\n{result.stdout}{result.stderr}")
    return result


def execute(path, cwd):
    path.chmod(0o755)
    result = run([path], cwd, ok=False)
    if result.returncode < 0:
        raise AssertionError(f"{path.name} died with signal {-result.returncode}")
    return result.stdout, result.returncode


def check_program(source, work, compare_gcc=True):
    run([ROOT / 'icg.out', source], work)
    generated = (work / 'code.asm').read_text().split(';         print library')[0]
    labels = re.findall(r'^\.L(\d+):', generated, re.MULTILINE)
    assert labels == [str(i) for i in range(1, len(labels) + 1)], 'Labels must follow textual order'
    assert '@@' not in generated and '__icg_frame_' not in generated, 'Unresolved frame marker'
    if source.name == 'phase2.c':
        assert 'entry main\n' in generated
        assert 'fact:\n\tPUSH EBP\n\tMOV EBP, ESP\n' in generated
        assert '\tRET 12\n' in generated and '\tCALL combine' in generated
        assert '[EBP+ESI]' in generated and '[values+EBX]' in generated
        assert '\tCWD\n\tMUL ECX\n' in generated
        assert '\tCDQ\n\tIDIV ECX\n' in generated
    results = []
    for assembly in ('code.asm', 'optimized_code.asm'):
        target = work / assembly.replace('.asm', '.out')
        run(['fasm', work / assembly, target], work)
        results.append(execute(target, work))
    assert results[0] == results[1], f"Optimization changed behavior for {source.name}: {results}"
    if compare_gcc:
        reference = work / 'reference.c'
        reference.write_text('#include <stdio.h>\n#define println(x) printf("%d\\n", (x))\n' + source.read_text())
        run(['gcc', '-std=c11', '-O0', reference, '-o', work / 'reference'], work)
        expected = execute(work / 'reference', work)
        assert results[0] == expected, f"{source.name}: actual {results[0]}, expected {expected}"
    assert not (work / 'code.asm.tmp').exists(), 'Compiler left its temporary file behind'
    print(f'PASS {source.name}: original and optimized assembly')


def check_optimizer(work):
    harness = work / 'optimizer_main.cpp'
    harness.write_text('#include "PeepholeOptimizer.h"\nint main(int n,char**v){'
                       'if(n!=3)return 1; PeepholeOptimizer::optimize(v[1],v[2]);}\n')
    run(['g++', '-std=c++17', '-I', ROOT, harness, ROOT / 'PeepholeOptimizer.cpp', '-o', work / 'optimizer'], work)
    cases = [
        ('push eax ; Line 1\n; Line 2\npop eax\n', [], ['Line 1', 'Line 2']),
        ('mov eax, [value]\nmov [value], eax\n', ['mov [value], eax'], ['mov eax, [value]']),
        ('mov eax, [eax]\nmov [eax], eax\n', [], ['mov [eax], eax']),
        ('mov eax, [Value]\nmov [value], eax\n', [], ['mov [value], eax']),
        ('push esp\npop esp\n', [], ['push esp', 'pop esp']),
        ('add eax, 0\nje target\n', [], ['add eax, 0']),
        ('sub eax, 0\nsetnz al\n', [], ['sub eax, 0']),
        ('imul eax, 1\njo target\n', [], ['imul eax, 1']),
        ('add eax, 0\nmov edx, eax\ncmp eax, 1\n', ['add eax, 0'], ['cmp eax, 1']),
        ('imul eax, 1\nret\n', ['imul eax, 1'], ['ret']),
        ('__icg_L1:\n; Line 4\n__icg_L2:\n__icg_L3:\nmov eax, 1\nje __icg_L3 ; Line 5\n',
         ['__icg_L2:', '__icg_L3:'], ['je __icg_L1', 'Line 4', 'Line 5']),
        ('first:\n.local:\nmov eax,1\nsecond:\n.local:\nret\n', [], ['first:', 'second:']),
        ('first:\n.L1:\n.L2:\nmov eax,1\nje .L2\nsecond:\n.L2:\nmov eax,2\nje .L2\n',
         [], ['je .L1', 'second:\n.L2:', 'je .L2']),
        ('push eax\nmov eax, 0 ; Line 8\nmov edx, eax\npop eax\nadd eax, edx\ncmp eax, 1\n',
         ['push eax', 'pop eax', 'add eax'], ['MOV edx, 0', 'Line 8', 'cmp eax, 1']),
    ]
    for text, absent, present in cases:
        (work / 'peephole.asm').write_text(text)
        run([work / 'optimizer', work / 'peephole.asm', work / 'peephole_opt.asm'], work)
        optimized = (work / 'peephole_opt.asm').read_text()
        for part in absent:
            assert part not in optimized, (text, optimized, part)
        for part in present:
            assert part in optimized, (text, optimized, part)
    print(f'PASS {len(cases)} optimizer cases (including flag and address hazards)')


def check_invalid(work):
    cases = [
        'int main(){ int x; x=2 return 0; }',
        'int main(){ int x,- y; return 0; }',
        'int f(int +){ return 0; } int main(){return 0;}',
        'int main(){ int x; x=2+=; return 0; }',
        'int main(){ return missing; }',
        'int main(){ int x,x; return 0; }',
        'int main(){ int a[2]; return a; }',
        'int main(){ int x; return x[0]; }',
        'int main(){ int a[0]; return 0; }',
        'int main(){ return 1.5; }',
        'int main(){ void x; return 0; }',
        'void f(){} int main(){ return f()+1; }',
        'int f(int a){return a;} int main(){return f();}',
        'int f(int); int main(){return f(1);}',
        'int f(int); int f(){return 1;} int main(){return 0;}',
        'int f(){return 1;} int f(){return 2;} int main(){return 0;}',
        'void f(){return 1;} int main(){return 0;}',
        'int f(int a, int a){return a;} int main(){return 0;}',
        'int main(){return 0;} trailing',
        'int main(){ @ return 0; }',
        'int main(){ "ignored string" return 0; }',
        'int f(){return 0;}',
        'int main(int x){return x;}',
        'int main(){ {int x;} return x; }',
    ]
    for text in cases:
        source = work / 'invalid.c'
        source.write_text(text)
        (work / 'code.asm').write_text('stale output')
        (work / 'optimized_code.asm').write_text('stale output')
        result = run([ROOT / 'icg.out', source], work, ok=False)
        assert result.returncode != 0, f'Invalid input accepted: {text}'
        assert not (work / 'code.asm').exists(), text
        assert not (work / 'optimized_code.asm').exists(), text
        assert not (work / 'code.asm.tmp').exists(), text
    print(f'PASS {len(cases)} invalid programs and failed-output cleanup')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--samples', type=pathlib.Path, help='Also check a directory of assignment samples')
    args = parser.parse_args()
    with tempfile.TemporaryDirectory(prefix='icg-tests-') as directory:
        work = pathlib.Path(directory)
        for source in sorted((ROOT / 'tests').glob('*.c')):
            check_program(source, work)
        if args.samples:
            for source in sorted(args.samples.resolve().glob('*.c')):
                # These supplied samples read uninitialized locals, so GCC is not
                # a valid reference for their numeric output.
                check_program(source, work, source.name not in ('test1_i.c', 'test7_i.c'))
        check_optimizer(work)
        check_invalid(work)
    print('All checks passed.')


if __name__ == '__main__':
    main()
