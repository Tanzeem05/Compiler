format ELF executable 3
entry main
segment readable writeable
segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 4
.L1:
	MOV EAX, 0       ; Line 3
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 3
	CMP EAX, EDX
	JG .L3
	JMP .L2
.L2:
	MOV EAX, 10       ; Line 3
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 3
	CMP EAX, EDX
	JL .L3
	JMP .L4
.L3:
	MOV EAX, 100       ; Line 4
	MOV [EBP-4], EAX
	JMP .L5
.L4:
	MOV EAX, 200       ; Line 6
	MOV [EBP-4], EAX
.L5:
	MOV EAX, 20       ; Line 8
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 8
	CMP EAX, EDX
	JG .L6
	JMP .L8
.L6:
	MOV EAX, 30       ; Line 8
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 8
	CMP EAX, EDX
	JL .L7
	JMP .L8
.L7:
	MOV EAX, 300       ; Line 9
	MOV [EBP-4], EAX
	JMP .L9
.L8:
	MOV EAX, 400       ; Line 11
	MOV [EBP-4], EAX
.L9:
	MOV EAX, 40       ; Line 13
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 13
	CMP EAX, EDX
	JG .L10
	JMP .L11
.L10:
	MOV EAX, 50       ; Line 13
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 13
	CMP EAX, EDX
	JL .L13
	JMP .L11
.L11:
	MOV EAX, 60       ; Line 13
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 13
	CMP EAX, EDX
	JL .L12
	JMP .L14
.L12:
	MOV EAX, 70       ; Line 13
	MOV EDX, EAX
	MOV EAX, [EBP-4]       ; Line 13
	CMP EAX, EDX
	JG .L13
	JMP .L14
.L13:
	MOV EAX, 500       ; Line 14
	MOV [EBP-4], EAX
	JMP .L15
.L14:
	MOV EAX, 600       ; Line 16
	MOV [EBP-4], EAX
.L15:
	MOV EAX, [EBP-4]       ; Line 17
	CALL print_number
.L16:
	MOV EAX, 0       ; Line 19
	JMP .L18
.L17:
.L18:
	ADD ESP, 4
	POP EBP
	MOV EAX,1
	XOR EBX, EBX
	INT 0x80
	POP EBP
	RET
;-------------------------------
;         print library         
;-------------------------------
__icg_print_number:
    push ebp
    mov ebp, esp
    push eax
    push ebx
    push ecx
    push edx
    push esi
    push edi

    mov eax, [ebp + 8]      ; println argument is passed on the stack
    sub esp, 32             ; local buffer

    test eax, eax
    jns .positive

    ; print '-'
    push eax

    sub esp, 1
    mov byte [esp], '-'

    mov eax, 4              ; sys_write
    mov ebx, 1              ; stdout
    mov ecx, esp
    mov edx, 1
    int 0x80

    add esp, 1
    pop eax

    neg eax

.positive:
    mov ebx, 10

    lea esi, [esp + 31]
    mov byte [esi], 10
    dec esi

.convert:
    xor edx, edx
    div ebx

    add dl, '0'
    mov [esi], dl
    dec esi

    test eax, eax
    jnz .convert

    inc esi

    lea edx, [esp + 32]
    sub edx, esi

    mov eax, 4              ; sys_write
    mov ebx, 1              ; stdout
    mov ecx, esi
    int 0x80

    add esp, 32

    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    pop eax
    pop ebp
    ret
;-------------------------------
