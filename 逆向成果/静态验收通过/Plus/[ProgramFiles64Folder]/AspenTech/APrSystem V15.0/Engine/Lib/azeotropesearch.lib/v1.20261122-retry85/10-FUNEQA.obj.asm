; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQA:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push rsi                                                   ; 0004
    push rdi                                                   ; 0005
    push rbx                                                   ; 0006
    mov r10,[rdx]                                              ; 0007
    lea rax,[r10*8+0x0]                                        ; 000a
    mov rcx,[rcx]                                              ; 0012
    mov edx,0x2                                                ; 0015
    cmp rcx,0x1                                                ; 001a
    jz short loc_008d                                           ; 001e
    jg short loc_002a                                           ; 0020
loc_0022:
    pop rbx                                                    ; 0022
    pop rdi                                                    ; 0023
    pop rsi                                                    ; 0024
    pop r14                                                    ; 0025
    pop r15                                                    ; 0027
    retq                                                       ; 0029
loc_002a:
    lea rdx,[r8+rax]                                           ; 002a
    mov esi,0x2                                                ; 002e
    mov r11d,0x1                                               ; 0033
    jmp short loc_0059                                          ; 0039
    nop dword [byte rax+rax+0x0]                               ; 003b
loc_0040:
    movsd qword [r9+rsi*8-0x8],xmm0                            ; 0040
    lea rdi,[rsi+0x1]                                          ; 0047
    add rdx,rax                                                ; 004b
    inc r11                                                    ; 004e
    cmp rsi,rcx                                                ; 0051
    mov rsi,rdi                                                ; 0054
    jnl short loc_0089                                          ; 0057
loc_0059:
    movsd xmm0,qword [r9+rsi*8-0x8]                            ; 0059
    cmp rsi,0x2                                                ; 0060
    jc short loc_0040                                           ; 0064
    xor edi,edi                                                ; 0066
    nop dword [dword rax+rax+0x0]                              ; 0068
loc_0070:
    movsd xmm1,qword [rdx+rdi*8]                               ; 0070
    mulsd xmm1,qword [r9+rdi*8]                                ; 0075
    subsd xmm0,xmm1                                            ; 007b
    inc rdi                                                    ; 007f
    cmp r11,rdi                                                ; 0082
    jnz short loc_0070                                          ; 0085
    jmp short loc_0040                                          ; 0087
loc_0089:
    lea rdx,[rcx+0x1]                                          ; 0089
loc_008d:
    cmp rcx,0x2                                                ; 008d
    mov r11d,0x1                                               ; 0091
    cmovnl r11,rcx                                             ; 0097
    mov esi,0x1                                                ; 009b
    lea rdi,[rcx-0x1]                                          ; 00a0
    imul r10,rdi                                               ; 00a4
    lea r10,[r8+r10*8]                                         ; 00a8
    mov rdi,0xfffffffffffffff8                                 ; 00ac
    sub rdi,rax                                                ; 00b3
    dec rdx                                                    ; 00b6
    mov rbx,r9                                                 ; 00b9
    jmp short loc_00f0                                          ; 00bc
    o16 nop                                                    ; 00be
loc_00c0:
    mov r15,rax                                                ; 00c0
    imul r15,r14                                               ; 00c3
    add r15,r8                                                 ; 00c7
    divsd xmm0,[r15+r14*8]                                     ; 00ca
    movsd qword [r9+r14*8],xmm0                                ; 00d0
    lea r14,[rsi+0x1]                                          ; 00d6
    add r10,rdi                                                ; 00da
    add rbx,0xfffffffffffffff8                                 ; 00dd
    inc rdx                                                    ; 00e1
    cmp rsi,r11                                                ; 00e4
    mov rsi,r14                                                ; 00e7
    jz near loc_0022                                            ; 00ea
loc_00f0:
    mov r14,rcx                                                ; 00f0
    sub r14,rsi                                                ; 00f3
    lea r15,[r14+0x2]                                          ; 00f6
    movsd xmm0,qword [r9+r14*8]                                ; 00fa
    cmp r15,rcx                                                ; 0100
    jg short loc_00c0                                           ; 0103
    mov r15,rcx                                                ; 0105
    nop dword [dword rax+rax+0x0]                              ; 0108
loc_0110:
    movsd xmm1,qword [r10+r15*8]                               ; 0110
    mulsd xmm1,qword [rbx+r15*8]                               ; 0116
    subsd xmm0,xmm1                                            ; 011c
    inc r15                                                    ; 0120
    cmp rdx,r15                                                ; 0123
    jnz short loc_0110                                          ; 0126
    jmp short loc_00c0                                          ; 0128

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .xdata (COFF section 4)
coff_section_4:
    db 0x01,0x07,0x05,0x00,0x07,0x30,0x06,0x70,0x05,0x60,0x04,0xe0,0x02,0xf0,0x00,0x00

; .drectve (COFF section 5)
coff_section_5:
    db 0x20,0x2f,0x44,0x45,0x46,0x41,0x55,0x4c,0x54,0x4c,0x49,0x42,0x3a,0x6d,0x73,0x76
    db 0x63,0x72,0x74,0x20,0x2f,0x44,0x45,0x46,0x41,0x55,0x4c,0x54,0x4c,0x49,0x42,0x3a
    db 0x69,0x66,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x2e,0x6c,0x69,0x62,0x20,0x2f,0x44,0x45
    db 0x46,0x41,0x55,0x4c,0x54,0x4c,0x49,0x42,0x3a,0x6c,0x69,0x62,0x69,0x66,0x63,0x6f
    db 0x72,0x65,0x6d,0x64,0x2e,0x6c,0x69,0x62,0x20,0x2f,0x44,0x45,0x46,0x41,0x55,0x4c
    db 0x54,0x4c,0x49,0x42,0x3a,0x6c,0x69,0x62,0x69,0x66,0x70,0x6f,0x72,0x74,0x6d,0x64
    db 0x2e,0x6c,0x69,0x62,0x20,0x2f,0x44,0x45,0x46,0x41,0x55,0x4c,0x54,0x4c,0x49,0x42
    db 0x3a,0x6c,0x69,0x62,0x69,0x72,0x63,0x6d,0x74,0x20,0x2f,0x44,0x45,0x46,0x41,0x55
    db 0x4c,0x54,0x4c,0x49,0x42,0x3a,0x6c,0x69,0x62,0x6d,0x6d,0x64,0x20,0x2f,0x44,0x45
    db 0x46,0x41,0x55,0x4c,0x54,0x4c,0x49,0x42,0x3a,0x6f,0x6c,0x64,0x6e,0x61,0x6d,0x65
    db 0x73,0x20,0x2f,0x44,0x45,0x46,0x41,0x55,0x4c,0x54,0x4c,0x49,0x42,0x3a,0x73,0x76
    db 0x6d,0x6c,0x5f,0x64,0x69,0x73,0x70,0x6d,0x64

; .pdata (COFF section 6)
coff_section_6:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x0000012a ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 6)
