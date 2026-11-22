; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ6:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbx                                                   ; 000a
    sub rsp,0x20                                               ; 000b
    mov rsi,[rsp+0x90]                                         ; 000f
    mov r10,[rsp+0x88]                                         ; 0017
    mov rax,[rdx]                                              ; 001f
    cmp rax,0x2                                                ; 0022
    jl near loc_011a                                            ; 0026
    mov r11,[rsp+0x80]                                         ; 002c
    mov r11,[r11]                                              ; 0034
    lea rbx,[r11*8+0x0]                                        ; 0037
    test byte [rcx],0x1                                        ; 003f
    jnz near loc_012d                                           ; 0042
    lea rcx,[rbx+0x8]                                          ; 0048
    mov r14d,0x1                                               ; 004c
    xor edi,edi                                                ; 0052
    mov r15,r9                                                 ; 0054
    nop word [dword rax+rax+0x0]                               ; 0057
loc_0060:
    xorpd xmm0,xmm0                                            ; 0060
    mov r12,rdi                                                ; 0064
    mov r13,r15                                                ; 0067
    nop word [byte rax+rax+0x0]                                ; 006a
loc_0070:
    movsd xmm1,qword [r13+0x0]                                 ; 0070
    mulsd xmm1,qword [r10+r12*8]                               ; 0076
    addsd xmm0,xmm1                                            ; 007c
    add r13,0x8                                                ; 0080
    inc r12                                                    ; 0084
    cmp r12,rax                                                ; 0087
    jl short loc_0070                                           ; 008a
    movsd qword [rsi+r14*8-0x8],xmm0                           ; 008c
    lea r12,[r14+0x1]                                          ; 0093
    add r15,rcx                                                ; 0097
    inc rdi                                                    ; 009a
    cmp r14,rax                                                ; 009d
    mov r14,r12                                                ; 00a0
    jnz short loc_0060                                          ; 00a3
    lea rcx,[rax-0x1]                                          ; 00a5
    imul r11,rcx                                               ; 00a9
    lea rcx,[r9+r11*8]                                         ; 00ad
    neg rbx                                                    ; 00b1
    mov r10d,0x2                                               ; 00b4
    mov r9,rax                                                 ; 00ba
    jmp short loc_00e0                                          ; 00bd
    nop                                                        ; 00bf
loc_00c0:
    addsd xmm0,[rsi+r11*8+0x8]                                 ; 00c0
    movsd qword [rsi+r11*8+0x8],xmm0                           ; 00c7
    lea r11,[r10+0x1]                                          ; 00ce
    dec r9                                                     ; 00d2
    add rcx,rbx                                                ; 00d5
    cmp rax,r10                                                ; 00d8
    mov r10,r11                                                ; 00db
    jz short loc_0156                                           ; 00de
loc_00e0:
    mov r11,rax                                                ; 00e0
    xorpd xmm0,xmm0                                            ; 00e3
    sub r11,r10                                                ; 00e7
    js short loc_00c0                                           ; 00ea
    mov edi,0x1                                                ; 00ec
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 00f1 | nop word [cs:rax+rax+0x0]
loc_0100:
    movsd xmm1,qword [rcx+rdi*8-0x8]                           ; 0100
    mulsd xmm1,qword [rsi+rdi*8-0x8]                           ; 0106
    addsd xmm0,xmm1                                            ; 010c
    inc rdi                                                    ; 0110
    cmp r9,rdi                                                 ; 0113
    jnz short loc_0100                                          ; 0116
    jmp short loc_00c0                                          ; 0118
loc_011a:
    movsd xmm0,qword [r9]                                      ; 011a
    mulsd xmm0,qword [r10]                                     ; 011f
    movsd qword [rsi],xmm0                                     ; 0124
    jmp near loc_020c                                           ; 0128
loc_012d:
    mov r14,r9                                                 ; 012d
    cmp rax,0xc                                                ; 0130
    jna short loc_016a                                          ; 0134
    shl rax,byte 0x3                                           ; 0136
    mov rcx,rsi                                                ; 013a
    mov rdi,rdx                                                ; 013d
    mov rdx,r10                                                ; 0140
    mov r15,r8                                                 ; 0143
    mov r8,rax                                                 ; 0146
    call $+5                                                   ; 0149 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r8,r15                                                 ; 014e
    mov rdx,rdi                                                ; 0151
    jmp short loc_0183                                          ; 0154
loc_0156:
    lea rcx,[rel $+7]                                          ; 0156 | REL32 +3 __unnamed_1 addendLE=00000000
    mov r9,rsi                                                 ; 015d
    call $+5                                                   ; 0160 | REL32 +1 FUNEQ7 addendLE=00000000
    jmp near loc_020c                                           ; 0165
loc_016a:
    xor ecx,ecx                                                ; 016a
    nop dword [byte rax+0x0]                                   ; 016c
loc_0170:
    movsd xmm0,qword [r10+rcx*8]                               ; 0170
    movsd qword [rsi+rcx*8],xmm0                               ; 0176
    inc rcx                                                    ; 017b
    cmp rax,rcx                                                ; 017e
    jnz short loc_0170                                          ; 0181
loc_0183:
    lea rcx,[rel $+7]                                          ; 0183 | REL32 +3 __unnamed_2 addendLE=00000000
    mov rdi,rdx                                                ; 018a
    mov r9,rsi                                                 ; 018d
    call $+5                                                   ; 0190 | REL32 +1 FUNEQ7 addendLE=00000000
    mov rax,[rdi]                                              ; 0195
    cmp rax,0x2                                                ; 0198
    mov rcx,r14                                                ; 019c
    jnl short loc_021c                                          ; 019f
loc_01a1:
    test rax,rax                                               ; 01a1
    jng short loc_020c                                          ; 01a4
    lea rcx,[rcx+rax*8]                                        ; 01a6
    add rcx,0xfffffffffffffff8                                 ; 01aa
    mov r8d,0x1                                                ; 01ae
    mov rdx,rax                                                ; 01b4
    jmp short loc_01d9                                          ; 01b7
    nop dword [dword rax+0x0]                                  ; 01b9
loc_01c0:
    movsd qword [rsi+r9*8],xmm0                                ; 01c0
    lea r9,[r8+0x1]                                            ; 01c6
    add rcx,0xfffffffffffffff8                                 ; 01ca
    dec rdx                                                    ; 01ce
    cmp rax,r8                                                 ; 01d1
    mov r8,r9                                                  ; 01d4
    jng short loc_020c                                          ; 01d7
loc_01d9:
    mov r9,rax                                                 ; 01d9
    xorpd xmm0,xmm0                                            ; 01dc
    sub r9,r8                                                  ; 01e0
    js short loc_01c0                                           ; 01e3
    xor r10d,r10d                                              ; 01e5
    mov r11,rcx                                                ; 01e8
    nop dword [byte rax+rax+0x0]                               ; 01eb
loc_01f0:
    movsd xmm1,qword [r11]                                     ; 01f0
    mulsd xmm1,qword [rsi+r10*8]                               ; 01f5
    addsd xmm0,xmm1                                            ; 01fb
    add r11,rbx                                                ; 01ff
    inc r10                                                    ; 0202
    cmp rdx,r10                                                ; 0205
    jnz short loc_01f0                                          ; 0208
    jmp short loc_01c0                                          ; 020a
loc_020c:
    add rsp,0x20                                               ; 020c
    pop rbx                                                    ; 0210
    pop rdi                                                    ; 0211
    pop rsi                                                    ; 0212
    pop r12                                                    ; 0213
    pop r13                                                    ; 0215
    pop r14                                                    ; 0217
    pop r15                                                    ; 0219
    retq                                                       ; 021b
loc_021c:
    lea rdx,[rcx+rbx]                                          ; 021c
    lea r8,[rbx+0x8]                                           ; 0220
    mov r10d,0x2                                               ; 0224
    mov r9d,0x1                                                ; 022a
    jmp short loc_0262                                          ; 0230
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0232 | nop word [cs:rax+rax+0x0]
loc_0240:
    addsd xmm0,[rsi+r11*8]                                     ; 0240
    movsd qword [rsi+r11*8],xmm0                               ; 0246
    lea r11,[r10+0x1]                                          ; 024c
    add rdx,r8                                                 ; 0250
    inc r9                                                     ; 0253
    cmp r10,rax                                                ; 0256
    mov r10,r11                                                ; 0259
    jnl near loc_01a1                                           ; 025c
loc_0262:
    lea r11,[r10-0x2]                                          ; 0262
    xorpd xmm0,xmm0                                            ; 0266
    cmp rax,r10                                                ; 026a
    jl short loc_0240                                           ; 026d
    mov rdi,r9                                                 ; 026f
    mov r14,rdx                                                ; 0272
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0275 | nop word [cs:rax+rax+0x0]
loc_0280:
    movsd xmm1,qword [r14]                                     ; 0280
    mulsd xmm1,qword [rsi+rdi*8]                               ; 0285
    addsd xmm0,xmm1                                            ; 028a
    add r14,rbx                                                ; 028e
    inc rdi                                                    ; 0291
    cmp rdi,rax                                                ; 0294
    jl short loc_0280                                           ; 0297
    jmp short loc_0240                                          ; 0299

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .xdata (COFF section 4)
coff_section_4:
    db 0x01,0x0f,0x08,0x00,0x0f,0x32,0x0b,0x30,0x0a,0x70,0x09,0x60,0x08,0xc0,0x06,0xd0
    db 0x04,0xe0,0x02,0xf0

; .rdata (COFF section 5)
coff_section_5:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

; .drectve (COFF section 6)
coff_section_6:
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

; .pdata (COFF section 7)
coff_section_7:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x0000029b ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 6)
