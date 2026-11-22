; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ4:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbp                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x68                                               ; 000c
    movaps oword [rsp+0x50],xmm7                               ; 0010
    movaps oword [rsp+0x40],xmm6                               ; 0015
    mov r15,r9                                                 ; 001a
    mov rbp,r8                                                 ; 001d
    mov rdi,rdx                                                ; 0020
    mov rbx,rcx                                                ; 0023
    mov r14,[rsp+0x108]                                        ; 0026
    mov rsi,[rsp+0xf8]                                         ; 002e
    mov r8,[rsp+0xf0]                                          ; 0036
    mov r13,[rsp+0xe8]                                         ; 003e
    mov r12,[rsp+0xe0]                                         ; 0046
    mov rax,[rcx]                                              ; 004e
    test rax,rax                                               ; 0051
    jng short loc_00a4                                          ; 0054
    mov rcx,[rsp+0xd8]                                         ; 0056
    mov rdx,[rsp+0xd0]                                         ; 005e
    xor r9d,r9d                                                ; 0066
    movapd xmm0,oword [rel $+8]                                ; 0069 | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0071 | nop word [cs:rax+rax+0x0]
loc_0080:
    movsd xmm1,qword [rcx+r9*8]                                ; 0080
    divsd xmm1,[rdx+r9*8]                                      ; 0086
    xorpd xmm1,xmm0                                            ; 008c
    movlpd qword [rsi+r9*8],xmm1                               ; 0090
    movlpd qword [r14+r9*8],xmm1                               ; 0096
    inc r9                                                     ; 009c
    cmp r9,rax                                                 ; 009f
    jl short loc_0080                                           ; 00a2
loc_00a4:
    lea rcx,[rel $+7]                                          ; 00a4 | REL32 +3 __unnamed_1 addendLE=00000000
    mov rdx,rbx                                                ; 00ab
    mov r9,rsi                                                 ; 00ae
    call $+5                                                   ; 00b1 | REL32 +1 FUNEQ7 addendLE=00000000
    mov rcx,rbx                                                ; 00b6
    mov rdx,r13                                                ; 00b9
    mov r8,r12                                                 ; 00bc
    mov r9,rsi                                                 ; 00bf
    call $+5                                                   ; 00c2 | REL32 +1 FUNEQA addendLE=00000000
    mov rcx,rbx                                                ; 00c7
    mov rdx,rsi                                                ; 00ca
    call $+5                                                   ; 00cd | REL32 +1 FU2NRM addendLE=00000000
    movapd xmm6,xmm0                                           ; 00d2
    movsd qword [r15],xmm0                                     ; 00d6
    movsd xmm7,qword [rbp+0x0]                                 ; 00db
    mulsd xmm0,qword [rel $+8]                                 ; 00e0 | REL32 +4 __real@3feccccccccccccd addendLE=00000000
    ucomisd xmm7,xmm0                                          ; 00e8
    jna short loc_00f7                                          ; 00ec
    movsd qword [rbp+0x0],xmm6                                 ; 00ee
    movapd xmm7,xmm6                                           ; 00f3
loc_00f7:
    ucomisd xmm6,xmm7                                          ; 00f7
    mov rax,[rbx]                                              ; 00fb
    jna short loc_0165                                          ; 00fe
    cmp qword [rdi],0x1                                        ; 0100
    jz short loc_0165                                           ; 0104
    cmp rax,0x2                                                ; 0106
    jl short loc_0165                                           ; 010a
    mov rdi,[rsp+0x100]                                        ; 010c
    mov [rsp+0x30],rdi                                         ; 0114
    mov [rsp+0x28],r14                                         ; 0119
    mov [rsp+0x20],r13                                         ; 011e
    lea rcx,[rel $+7]                                          ; 0123 | REL32 +3 __unnamed_2 addendLE=00000000
    mov rdx,rbx                                                ; 012a
    mov r8,[rsp+0xf0]                                          ; 012d
    mov r9,r12                                                 ; 0135
    call $+5                                                   ; 0138 | REL32 +1 FUNEQ6 addendLE=00000000
    mov rcx,rbx                                                ; 013d
    mov rdx,rdi                                                ; 0140
    call $+5                                                   ; 0143 | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 0148 | REL32 +4 FUNEQ4$SNRMG addendLE=00000000
    xorpd xmm1,xmm1                                            ; 0150
    ucomisd xmm0,xmm1                                          ; 0154
    setpe al                                                   ; 0158
    setnz cl                                                   ; 015b
    or cl,al                                                   ; 015e
    mov rax,[rbx]                                              ; 0160
    jnz short loc_01b1                                          ; 0163
loc_0165:
    divsd xmm7,xmm6                                            ; 0165
    minsd xmm7,[rel $+8]                                       ; 0169 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    test rax,rax                                               ; 0171
    jng short loc_0196                                          ; 0174
    xor ecx,ecx                                                ; 0176
    nop dword [dword rax+rax+0x0]                              ; 0178
loc_0180:
    movsd xmm0,qword [rsi+rcx*8]                               ; 0180
    mulsd xmm0,xmm7                                            ; 0185
    movsd qword [rsi+rcx*8],xmm0                               ; 0189
    inc rcx                                                    ; 018e
    cmp rcx,rax                                                ; 0191
    jl short loc_0180                                           ; 0194
loc_0196:
    movaps xmm6,oword [rsp+0x40]                               ; 0196
    movaps xmm7,oword [rsp+0x50]                               ; 019b
    add rsp,0x68                                               ; 01a0
    pop rbx                                                    ; 01a4
    pop rbp                                                    ; 01a5
    pop rdi                                                    ; 01a6
    pop rsi                                                    ; 01a7
    pop r12                                                    ; 01a8
    pop r13                                                    ; 01aa
    pop r14                                                    ; 01ac
    pop r15                                                    ; 01ae
    retq                                                       ; 01b0
loc_01b1:
    test rax,rax                                               ; 01b1
    jng short loc_01d6                                          ; 01b4
    xor ecx,ecx                                                ; 01b6
    nop dword [dword rax+rax+0x0]                              ; 01b8
loc_01c0:
    movsd xmm1,qword [rdi+rcx*8]                               ; 01c0
    divsd xmm1,xmm0                                            ; 01c5
    movsd qword [rdi+rcx*8],xmm1                               ; 01c9
    inc rcx                                                    ; 01ce
    cmp rcx,rax                                                ; 01d1
    jl short loc_01c0                                           ; 01d4
loc_01d6:
    mov [rsp+0x30],r14                                         ; 01d6
    mov [rsp+0x28],rdi                                         ; 01db
    mov [rsp+0x20],r13                                         ; 01e0
    lea rcx,[rel $+7]                                          ; 01e5 | REL32 +3 __unnamed_1 addendLE=00000000
    mov rdx,rbx                                                ; 01ec
    mov r8,[rsp+0xf0]                                          ; 01ef
    mov r9,r12                                                 ; 01f7
    call $+5                                                   ; 01fa | REL32 +1 FUNEQ6 addendLE=00000000
    mov rcx,rbx                                                ; 01ff
    mov rdx,r14                                                ; 0202
    call $+5                                                   ; 0205 | REL32 +1 FU2NRM addendLE=00000000
    movsd xmm1,qword [rel $+8]                                 ; 020a | REL32 +4 FUNEQ4$SNRMG addendLE=00000000
    divsd xmm1,xmm0                                            ; 0212
    divsd xmm1,xmm0                                            ; 0216
    ucomisd xmm7,xmm1                                          ; 021a
    jna near loc_02e8                                           ; 021e
    movapd xmm3,xmm1                                           ; 0224
    divsd xmm3,xmm7                                            ; 0228
    mulsd xmm3,xmm3                                            ; 022c
    mov rax,[rbx]                                              ; 0230
    xorpd xmm0,xmm0                                            ; 0233
    test rax,rax                                               ; 0237
    jng short loc_0256                                          ; 023a
    xor ecx,ecx                                                ; 023c
    o16 nop                                                    ; 023e
loc_0240:
    movsd xmm2,qword [rsi+rcx*8]                               ; 0240
    mulsd xmm2,qword [rdi+rcx*8]                               ; 0245
    addsd xmm0,xmm2                                            ; 024a
    inc rcx                                                    ; 024e
    cmp rcx,rax                                                ; 0251
    jl short loc_0240                                           ; 0254
loc_0256:
    divsd xmm0,xmm7                                            ; 0256
    movapd xmm4,xmm1                                           ; 025a
    divsd xmm4,xmm7                                            ; 025e
    mulsd xmm4,xmm0                                            ; 0262
    movsd xmm0,qword [rel $+8]                                 ; 0266 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    movapd xmm2,xmm0                                           ; 026e
    subsd xmm2,xmm3                                            ; 0272
    movapd xmm5,xmm4                                           ; 0276
    subsd xmm5,xmm3                                            ; 027a
    subsd xmm4,xmm0                                            ; 027e
    mulsd xmm4,xmm4                                            ; 0282
    divsd xmm6,xmm7                                            ; 0286
    mulsd xmm6,xmm6                                            ; 028a
    subsd xmm6,xmm0                                            ; 028e
    mulsd xmm6,xmm2                                            ; 0292
    addsd xmm6,xmm4                                            ; 0296
    xorps xmm3,xmm3                                            ; 029a
    sqrtsd xmm3,xmm6                                           ; 029d
    addsd xmm3,xmm5                                            ; 02a1
    divsd xmm2,xmm3                                            ; 02a5
    subsd xmm0,xmm2                                            ; 02a9
    mulsd xmm0,xmm1                                            ; 02ad
    test rax,rax                                               ; 02b1
    jng near loc_0196                                           ; 02b4
    xor ecx,ecx                                                ; 02ba
    nop dword [byte rax+0x0]                                   ; 02bc
loc_02c0:
    movsd xmm1,qword [rsi+rcx*8]                               ; 02c0
    mulsd xmm1,xmm2                                            ; 02c5
    movsd xmm3,qword [rdi+rcx*8]                               ; 02c9
    mulsd xmm3,xmm0                                            ; 02ce
    addsd xmm3,xmm1                                            ; 02d2
    movsd qword [rsi+rcx*8],xmm3                               ; 02d6
    inc rcx                                                    ; 02db
    cmp rcx,rax                                                ; 02de
    jl short loc_02c0                                           ; 02e1
    jmp near loc_0196                                           ; 02e3
loc_02e8:
    mov rax,[rbx]                                              ; 02e8
    test rax,rax                                               ; 02eb
    jng near loc_0196                                           ; 02ee
    xor ecx,ecx                                                ; 02f4
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 02f6 | nop word [cs:rax+rax+0x0]
loc_0300:
    movsd xmm0,qword [rdi+rcx*8]                               ; 0300
    mulsd xmm0,xmm7                                            ; 0305
    movsd qword [rsi+rcx*8],xmm0                               ; 0309
    inc rcx                                                    ; 030e
    cmp rcx,rax                                                ; 0311
    jl short loc_0300                                           ; 0314
    jmp near loc_0196                                           ; 0316

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .rdata (COFF section 4)
coff_section_4:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80

; .rdata (COFF section 5)
coff_section_5:
    db 0xcd,0xcc,0xcc,0xcc,0xcc,0xcc,0xec,0x3f

; .rdata (COFF section 6)
coff_section_6:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .xdata (COFF section 7)
coff_section_7:
    db 0x01,0x1a,0x0d,0x00,0x1a,0x68,0x04,0x00,0x15,0x78,0x05,0x00,0x10,0xc2,0x0c,0x30
    db 0x0b,0x50,0x0a,0x70,0x09,0x60,0x08,0xc0,0x06,0xd0,0x04,0xe0,0x02,0xf0,0x00,0x00

; .rdata (COFF section 8)
coff_section_8:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

; .drectve (COFF section 9)
coff_section_9:
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

; .pdata (COFF section 10)
coff_section_10:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x0000031b ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 15)
