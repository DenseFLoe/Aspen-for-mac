; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ8:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbx                                                   ; 000a
    sub rsp,0xe0                                               ; 000b
    mov rbx,r9                                                 ; 0012
    mov r15,r8                                                 ; 0015
    mov r12,rdx                                                ; 0018
    mov r14,rcx                                                ; 001b
    mov rax,[rsp+0x150]                                        ; 001e
    mov rcx,[rsp+0x148]                                        ; 0026
    mov rsi,0x801208384ff00                                    ; 002e
    mov r13,[rcx]                                              ; 0038
    cmp r13,0x9                                                ; 003b
    jl short loc_0084                                           ; 003f
    mov qword [rsp+0xb0],0x0                                   ; 0041
    mov edi,[rax]                                              ; 004d
    mov word [rsp+0x3e],0x1                                    ; 004f
    lea rax,[rel $+219]                                        ; 0056 | REL32 +3 FUNEQ8$format_pack addendLE=d4000000
    mov [rsp+0x28],rax                                         ; 005d
    mov qword [rsp+0x20],0x0                                   ; 0062
    lea rcx,[rsp+0xb0]                                         ; 006b
    lea r9,[rsp+0x3e]                                          ; 0073
    mov edx,edi                                                ; 0078
    mov r8,rsi                                                 ; 007a
    call $+5                                                   ; 007d | REL32 +1 for_write_seq_fmt addendLE=00000000
    jmp short loc_0090                                          ; 0082
loc_0084:
    cmp r13,0x6                                                ; 0084
    jl near loc_0200                                            ; 0088
    mov edi,[rax]                                              ; 008e
loc_0090:
    mov rax,[r12]                                              ; 0090
    mov qword [rsp+0xb0],0x0                                   ; 0094
    mov dword [rsp+0x4c],0x2010b                               ; 00a0
    mov [rsp+0x58],rax                                         ; 00a8
    lea rax,[rel $+135]                                        ; 00ad | REL32 +3 FUNEQ8$format_pack addendLE=80000000
    mov [rsp+0x28],rax                                         ; 00b4
    lea rax,[rsp+0x58]                                         ; 00b9
    mov [rsp+0x20],rax                                         ; 00be
    lea r12,[rsp+0xb0]                                         ; 00c3
    lea r9,[rsp+0x4c]                                          ; 00cb
    mov rcx,r12                                                ; 00d0
    mov edx,edi                                                ; 00d3
    mov r8,rsi                                                 ; 00d5
    call $+5                                                   ; 00d8 | REL32 +1 for_write_seq_fmt addendLE=00000000
    movsd xmm0,qword [r15]                                     ; 00dd
    mov dword [rsp+0x48],0x10130                               ; 00e2
    movsd qword [rsp+0x50],xmm0                                ; 00ea
    lea rdx,[rsp+0x48]                                         ; 00f0
    lea r8,[rsp+0x50]                                          ; 00f5
    mov rcx,r12                                                ; 00fa
    call $+5                                                   ; 00fd | REL32 +1 for_write_seq_fmt_xmit addendLE=00000000
    cmp r13,0x9                                                ; 0102
    jl near loc_0200                                            ; 0106
    mov rax,[r14]                                              ; 010c
    xor r14d,r14d                                              ; 010f
    test rax,rax                                               ; 0112
    cmovg r14,rax                                              ; 0115
    mov r15,[rsp+0x140]                                        ; 0119
    mov qword [rsp+0xb0],0x0                                   ; 0121
    mov dword [rsp+0x44],0x10730                               ; 012d
    mov qword [rsp+0x88],0x1                                   ; 0135
    mov [rsp+0x90],rbx                                         ; 0141
    mov qword [rsp+0x98],0x1                                   ; 0149
    mov [rsp+0xa0],r14                                         ; 0155
    mov qword [rsp+0xa8],0x8                                   ; 015d
    lea rax,[rel $+71]                                         ; 0169 | REL32 +3 FUNEQ8$format_pack addendLE=40000000
    mov [rsp+0x28],rax                                         ; 0170
    lea rax,[rsp+0x88]                                         ; 0175
    mov [rsp+0x20],rax                                         ; 017d
    lea rbx,[rsp+0xb0]                                         ; 0182
    lea r9,[rsp+0x44]                                          ; 018a
    mov rcx,rbx                                                ; 018f
    mov edx,edi                                                ; 0192
    mov r8,rsi                                                 ; 0194
    call $+5                                                   ; 0197 | REL32 +1 for_write_seq_fmt addendLE=00000000
    lea rax,[rel $+7]                                          ; 019c | REL32 +3 FUNEQ8$format_pack addendLE=00000000
    mov qword [rsp+0xb0],0x0                                   ; 01a3
    mov dword [rsp+0x40],0x10730                               ; 01af
    mov qword [rsp+0x60],0x1                                   ; 01b7
    mov [rsp+0x68],r15                                         ; 01c0
    mov qword [rsp+0x70],0x1                                   ; 01c5
    mov [rsp+0x78],r14                                         ; 01ce
    mov qword [rsp+0x80],0x8                                   ; 01d3
    mov [rsp+0x28],rax                                         ; 01df
    lea rax,[rsp+0x60]                                         ; 01e4
    mov [rsp+0x20],rax                                         ; 01e9
    lea r9,[rsp+0x40]                                          ; 01ee
    mov rcx,rbx                                                ; 01f3
    mov edx,edi                                                ; 01f6
    mov r8,rsi                                                 ; 01f8
    call $+5                                                   ; 01fb | REL32 +1 for_write_seq_fmt addendLE=00000000
loc_0200:
    nop                                                        ; 0200
    add rsp,0xe0                                               ; 0201
    pop rbx                                                    ; 0208
    pop rdi                                                    ; 0209
    pop rsi                                                    ; 020a
    pop r12                                                    ; 020b
    pop r13                                                    ; 020d
    pop r14                                                    ; 020f
    pop r15                                                    ; 0211
    retq                                                       ; 0213

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x36,0x00,0x00,0x00,0x1c,0x00,0x04,0x00,0x20,0x46,0x20,0x3d,0x1f,0x00,0x00,0x07
    db 0x05,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x38,0x00,0x01,0x00
    db 0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1f,0x00,0x00,0x07
    db 0x05,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x39,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x1c,0x00,0x04,0x00,0x20,0x58,0x20,0x3d,0x1f,0x00,0x00,0x07
    db 0x05,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x38,0x00,0x01,0x00
    db 0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1f,0x00,0x00,0x07
    db 0x05,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x39,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x1c,0x00,0x11,0x00,0x20,0x41,0x54,0x20,0x49,0x54,0x45,0x52
    db 0x41,0x54,0x49,0x4f,0x4e,0x20,0x4e,0x4f,0x2e,0x00,0x00,0x00,0x24,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x1c,0x00,0x15,0x00,0x20,0x20,0x32,0x2d
    db 0x4e,0x4f,0x52,0x4d,0x20,0x4f,0x46,0x20,0x46,0x2f,0x44,0x49,0x41,0x47,0x46,0x20
    db 0x3d,0x00,0x00,0x00,0x1f,0x00,0x00,0x08,0x01,0x00,0x00,0x00,0x0f,0x00,0x00,0x00
    db 0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x1c,0x00,0x01,0x00,0x20,0x00,0x00,0x00
    db 0x37,0x00,0x00,0x00

; .xdata (COFF section 4)
coff_section_4:
    db 0x01,0x12,0x09,0x00,0x12,0x01,0x1c,0x00,0x0b,0x30,0x0a,0x70,0x09,0x60,0x08,0xc0
    db 0x06,0xd0,0x04,0xe0,0x02,0xf0,0x00,0x00

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
    dd 0x00000214 ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 6)
