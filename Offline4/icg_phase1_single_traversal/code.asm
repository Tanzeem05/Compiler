format ELF executable 3
entry main
segment readable writeable
	i dd 1 DUP (0)
	j dd 1 DUP (0)
segment readable executable
main:
	PUSH EBP
	MOV EBP, ESP
	SUB ESP, 4
	SUB ESP, 4
	SUB ESP, 4
	SUB ESP, 4
	SUB ESP, 4
	SUB ESP, 4
.L1:
	MOV EAX, 1       ; Line 6
	MOV [i], EAX
	PUSH EAX
	POP EAX
.L2:
	MOV EAX, [i]       ; Line 7
	CALL print_number
.L3:
	MOV EAX, 8       ; Line 9
	MOV EDX, EAX
	MOV EAX, 5       ; Line 9
	ADD EAX, EDX
	PUSH EAX
	POP EAX       ; Line 9
	MOV [j], EAX
	PUSH EAX
	POP EAX
.L4:
	MOV EAX, [j]       ; Line 10
	CALL print_number
.L5:
	MOV EAX, [j]       ; Line 12
	MOV ECX, EAX
	MOV EAX, 2       ; Line 12
	CWD
	MUL ECX
	PUSH EAX
	POP EAX       ; Line 12
	MOV EDX, EAX
	MOV EAX, [i]       ; Line 12
	ADD EAX, EDX
	PUSH EAX
	POP EAX       ; Line 12
	MOV [EBP-4], EAX
	PUSH EAX
	POP EAX
.L6:
	MOV EAX, [EBP-4]       ; Line 13
	CALL print_number
.L7:
	MOV EAX, 9       ; Line 15
	MOV ECX, EAX
	MOV EAX, [EBP-4]       ; Line 15
	CWD
	DIV ECX
	PUSH EDX
	POP EAX       ; Line 15
	MOV [EBP-12], EAX
	PUSH EAX
	POP EAX
.L8:
	MOV EAX, [EBP-12]       ; Line 16
	CALL print_number
.L9:
	MOV EAX, [EBP-8]       ; Line 18
	MOV EDX, EAX
	MOV EAX, [EBP-12]       ; Line 18
	CMP EAX, EDX
	JLE .L10
	JMP .L12
.L10:
	MOV EAX, 1       ; Line 18
	JMP .L11
.L12:
	MOV EAX, 0
.L11:
	MOV [EBP-16], EAX
	PUSH EAX
	POP EAX
.L13:
	MOV EAX, [EBP-16]       ; Line 19
	CALL print_number
.L14:
	MOV EAX, [j]       ; Line 21
	MOV EDX, EAX
	MOV EAX, [i]       ; Line 21
	CMP EAX, EDX
	JNE .L15
	JMP .L17
.L15:
	MOV EAX, 1       ; Line 21
	JMP .L16
.L17:
	MOV EAX, 0
.L16:
	MOV [EBP-20], EAX
	PUSH EAX
	POP EAX
.L18:
	MOV EAX, [EBP-20]       ; Line 22
	CALL print_number
.L19:
	MOV EAX, [EBP-16]       ; Line 24
	CMP EAX, 0
	JNE .L21
	JMP .L20
.L20:
	MOV EAX, [EBP-20]       ; Line 24
	CMP EAX, 0
	JNE .L21
	JMP .L23
.L21:
	MOV EAX, 1       ; Line 24
	JMP .L22
.L23:
	MOV EAX, 0
.L22:
	MOV [EBP-24], EAX
	PUSH EAX
	POP EAX
.L24:
	MOV EAX, [EBP-24]       ; Line 25
	CALL print_number
.L25:
	MOV EAX, [EBP-16]       ; Line 27
	CMP EAX, 0
	JNE .L26
	JMP .L29
.L26:
	MOV EAX, [EBP-20]       ; Line 27
	CMP EAX, 0
	JNE .L27
	JMP .L29
.L27:
	MOV EAX, 1       ; Line 27
	JMP .L28
.L29:
	MOV EAX, 0
.L28:
	MOV [EBP-24], EAX
	PUSH EAX
	POP EAX
.L30:
	MOV EAX, [EBP-24]       ; Line 28
	CALL print_number
.L31:
	MOV EAX, [EBP-24]       ; Line 30
	PUSH EAX
	INC EAX
	MOV [EBP-24], EAX
	POP EAX
.L32:
	MOV EAX, [EBP-24]       ; Line 31
	CALL print_number
.L33:
	MOV EAX, [EBP-24]       ; Line 33
	NEG EAX
	PUSH EAX
	POP EAX       ; Line 33
	MOV [EBP-4], EAX
	PUSH EAX
	POP EAX
.L34:
	MOV EAX, [EBP-4]       ; Line 34
	CALL print_number
.L35:
	MOV EAX, 0       ; Line 36
	JMP .L37
.L36:
.L37:
	ADD ESP, 24
	POP EBP
	MOV EAX,1
	XOR EBX, EBX
	INT 0x80
	POP EBP
	RET
;-------------------------------
;         print library         
;-------------------------------
print_number:
    push eax
    push ebx
    push ecx
    push edx
    push esi
    push edi

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
    ret
;-------------------------------
