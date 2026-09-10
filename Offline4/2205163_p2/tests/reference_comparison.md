# Comparison against a.out

Input directory: `/home/tanzeem/Documents/Compiler/Offline4/2205163_p2/input`
Reference compiler: `/home/tanzeem/Documents/Compiler/Offline4/2205163_p2/a.out`
Reference printing library: `/home/tanzeem/Documents/Compiler/Offline4/printProc.lib`
Generated assembly, executables, and reference files: `/tmp/icg-reference-comparison-xyz3vhg4`

Each `.c` file is compiled separately. All four assembly files are assembled with FASM and executed. MATCH means identical stdout, stderr, and exit status to the executable generated from the reference compiler’s `code.asm`.

`input/output.txt` is expected-output documentation, not a C test.

| Test | Our code.asm | Our optimized_code.asm | Reference optcode.asm |
|---|---|---|---|
| exp.c | MATCH | MATCH | MATCH |
| func.c | MATCH | MATCH | MATCH |
| loop.c | MATCH | MATCH | MATCH |
| recursion1_i.c | MATCH | MATCH | MATCH |
| recursion2_i.c | MATCH | MATCH | MATCH |
| test1_i.c | MATCH | MATCH | MATCH |
| test2_i.c | MATCH | MATCH | MATCH |
| test3_i.c | MATCH | MATCH | MATCH |
| test4_i.c | MATCH | MATCH | MATCH |
| test5_i.c | MATCH | MATCH | MATCH |
| test6_i.c | MATCH | MATCH | MATCH |
| test7_i.c | MATCH | MATCH | MATCH |

## Exact program output

### exp.c

`reference_raw` — exit status: 0

```text
2
1
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### func.c

`reference_raw` — exit status: 0

```text
5
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### loop.c

`reference_raw` — exit status: 0

```text
-1
12
1
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### recursion1_i.c

`reference_raw` — exit status: 0

```text
63
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### recursion2_i.c

`reference_raw` — exit status: 0

```text
28
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test1_i.c

`reference_raw` — exit status: 0

```text
1
13
27
0
1
1
1
1
2
-2
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test2_i.c

`reference_raw` — exit status: 0

```text
8
6
3
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test3_i.c

`reference_raw` — exit status: 0

```text
0
1
2
3
4
5
18
0
18
-1
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test4_i.c

`reference_raw` — exit status: 0

```text
7
8
32
170
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test5_i.c

`reference_raw` — exit status: 0

```text
25
0
14
4
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test6_i.c

`reference_raw` — exit status: 0

```text
-2
-2
-1
-1
100
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

### test7_i.c

`reference_raw` — exit status: 0

```text
600
```

`reference_optimized`: identical to reference.
`ours_raw`: identical to reference.
`ours_optimized`: identical to reference.

## Interpretation

`test1_i.c` reads the uninitialized local `ll`; `test7_i.c` reads the uninitialized local `i`. Their comparisons describe the observed runs, not a guarantee for uninitialized C values.
