format ELF executable 3
entry _start

segment readable executable

_start:
    call main
    mov ebx, eax
    mov eax, 1
    int 0x80


; Line 2: function main
main:
    push ebp
    mov ebp, esp
    ; Line 4
    sub esp, 4
    sub esp, 4
    sub esp, 4
    sub esp, 4
    sub esp, 4
    sub esp, 4
    ; Line 6
    mov eax, 1
    mov [i], eax
    ; Line 7
    mov eax, [i]
    call print_number
    ; Line 9
    mov eax, 5
    push eax
    mov eax, 8
    mov ebx, eax
    pop eax
    add eax, ebx
    mov [j], eax
    ; Line 10
    mov eax, [j]
    call print_number
    ; Line 12
    mov eax, [i]
    push eax
    mov eax, 2
    push eax
    mov eax, [j]
    mov ebx, eax
    pop eax
    imul eax, ebx
    mov ebx, eax
    pop eax
    add eax, ebx
    mov [ebp-4], eax
    ; Line 13
    mov eax, [ebp-4]
    call print_number
    ; Line 15
    mov eax, [ebp-4]
    push eax
    mov eax, 9
    mov ebx, eax
    pop eax
    cdq
    idiv ebx
    mov eax, edx
    mov [ebp-12], eax
    ; Line 16
    mov eax, [ebp-12]
    call print_number
    ; Line 18
    mov eax, [ebp-12]
    push eax
    mov eax, [ebp-8]
    mov ebx, eax
    pop eax
    cmp eax, ebx
    jle L_rel_true_1
    mov eax, 0
    jmp L_rel_end_2
L_rel_true_1:
    mov eax, 1
L_rel_end_2:
    mov [ebp-16], eax
    ; Line 19
    mov eax, [ebp-16]
    call print_number
    ; Line 21
    mov eax, [i]
    push eax
    mov eax, [j]
    mov ebx, eax
    pop eax
    cmp eax, ebx
    jne L_rel_true_3
    mov eax, 0
    jmp L_rel_end_4
L_rel_true_3:
    mov eax, 1
L_rel_end_4:
    mov [ebp-20], eax
    ; Line 22
    mov eax, [ebp-20]
    call print_number
    ; Line 24
    mov eax, [ebp-16]
    cmp eax, 0
    jne L_or_true_5
    mov eax, [ebp-20]
    cmp eax, 0
    jne L_or_true_5
    mov eax, 0
    jmp L_logic_end_6
L_or_true_5:
    mov eax, 1
L_logic_end_6:
    mov [ebp-24], eax
    ; Line 25
    mov eax, [ebp-24]
    call print_number
    ; Line 27
    mov eax, [ebp-16]
    cmp eax, 0
    je L_and_false_7
    mov eax, [ebp-20]
    cmp eax, 0
    je L_and_false_7
    mov eax, 1
    jmp L_logic_end_8
L_and_false_7:
    mov eax, 0
L_logic_end_8:
    mov [ebp-24], eax
    ; Line 28
    mov eax, [ebp-24]
    call print_number
    ; Line 30
    mov eax, [ebp-24]
    inc dword [ebp-24]
    ; Line 31
    mov eax, [ebp-24]
    call print_number
    ; Line 33
    mov eax, [ebp-24]
    neg eax
    mov [ebp-4], eax
    ; Line 34
    mov eax, [ebp-4]
    call print_number
    ; Line 36
    mov eax, 0
    jmp L_main_exit_0
L_main_exit_0:
    mov esp, ebp
    pop ebp
    ret

; println helper supplied with the assignment/project
include 'printProc.lib'

segment readable writeable
    ; Line 1
i dd 0
    ; Line 1
j dd 0
