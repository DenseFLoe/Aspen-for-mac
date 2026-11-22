; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

PURE_PROPERTY:
    push rbp                                                   ; 0000
    push r15                                                   ; 0001
    push r14                                                   ; 0003
    push r13                                                   ; 0005
    push r12                                                   ; 0007
    push rsi                                                   ; 0009
    push rdi                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x58                                               ; 000c
    lea rbp,[rsp+0x50]                                         ; 0010
    movapd oword [rbp-0x10],xmm6                               ; 0015
    mov [rbp-0x48],rcx                                         ; 001a
    mov rdi,[rcx]                                              ; 001e
    xor eax,eax                                                ; 0021
    test rdi,rdi                                               ; 0023
    cmovg rax,rdi                                              ; 0026
    lea rcx,[rax*8+0xf]                                        ; 002a
    and rcx,0xfffffffffffffff0                                 ; 0032
    mov rax,rcx                                                ; 0036
    call $+5                                                   ; 0039 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 003e
    mov r12,rsp                                                ; 0041
    mov rax,rcx                                                ; 0044
    call $+5                                                   ; 0047 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 004c
    mov r14,rsp                                                ; 004f
    mov rax,rcx                                                ; 0052
    call $+5                                                   ; 0055 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 005a
    mov r10,rsp                                                ; 005d
    mov rax,rcx                                                ; 0060
    call $+5                                                   ; 0063 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0068
    mov r11,rsp                                                ; 006b
    mov rax,rcx                                                ; 006e
    call $+5                                                   ; 0071 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0076
    mov r15,rsp                                                ; 0079
    mov byte [rel $+8],0x0                                     ; 007c | REL32 +2 PURE_PROPERTY$FLASHTYPE addendLE=01000000
    mov word [rel $+7],0x5650                                  ; 0083 | REL32 +3 PURE_PROPERTY$FLASHTYPE addendLE=feffffff
    mov qword [rel $+7],0x0                                    ; 008c | REL32 +3 PURE_PROPERTY$VFRAC addendLE=fcffffff
    mov qword [rel $+7],0x2                                    ; 0097 | REL32 +3 PURE_PROPERTY$NPHASE_1 addendLE=fcffffff
    mov qword [rel $+7],0x1                                    ; 00a2 | REL32 +3 PURE_PROPERTY$NCOMP_1 addendLE=fcffffff
    mov rax,0x3ff0000000000000                                 ; 00ad
    mov [rel $+7],rax                                          ; 00b7 | REL32 +3 PURE_PROPERTY$XPURE addendLE=00000000
    mov qword [rel $+7],0x1                                    ; 00be | REL32 +3 PURE_PROPERTY$I addendLE=fcffffff
    test rdi,rdi                                               ; 00c9
    jng near loc_045a                                           ; 00cc
    lea rax,[rdi*8+0x0]                                        ; 00d2
    mov [rbp-0x40],rax                                         ; 00da
    mov rsi,[rbp+0x88]                                         ; 00de
    xor eax,eax                                                ; 00e5
    lea rbx,[rel $+7]                                          ; 00e7 | REL32 +3 PURE_PROPERTY$TEMP addendLE=00000000
    mov [rbp-0x30],rdx                                         ; 00ee
    mov [rbp-0x28],r8                                          ; 00f2
    mov [rbp-0x20],r10                                         ; 00f6
    mov [rbp-0x18],r11                                         ; 00fa
    o16 nop                                                    ; 00fe
loc_0100:
    mov rax,[r8+rax*8]                                         ; 0100
    mov [rel $+7],rax                                          ; 0104 | REL32 +3 PURE_PROPERTY$JDX addendLE=00000000
    sub rsp,0x90                                               ; 010b
    mov rax,[rbp+0x98]                                         ; 0112
    mov [rsp+0x80],rax                                         ; 0119
    lea rax,[rel $+7]                                          ; 0121 | REL32 +3 PURE_PROPERTY$KERR addendLE=00000000
    mov [rsp+0x70],rax                                         ; 0128
    mov [rsp+0x68],r14                                         ; 012d
    mov [rsp+0x60],r10                                         ; 0132
    lea rax,[rel $+7]                                          ; 0137 | REL32 +3 PURE_PROPERTY$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 013e
    mov [rsp+0x50],r11                                         ; 0143
    mov [rsp+0x48],r15                                         ; 0148
    lea rax,[rel $+7]                                          ; 014d | REL32 +3 PURE_PROPERTY$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0154
    mov [rsp+0x38],rdx                                         ; 0159
    mov [rsp+0x30],rbx                                         ; 015e
    lea rax,[rel $+7]                                          ; 0163 | REL32 +3 PURE_PROPERTY$XPURE addendLE=00000000
    mov [rsp+0x28],rax                                         ; 016a
    lea rax,[rel $+7]                                          ; 016f | REL32 +3 PURE_PROPERTY$JDX addendLE=00000000
    mov [rsp+0x20],rax                                         ; 0176
    mov qword [rsp+0x78],0x3                                   ; 017b
    lea rcx,[rel $+7]                                          ; 0184 | REL32 +3 PURE_PROPERTY$FLASHTYPE addendLE=00000000
    lea rdx,[rel $+7]                                          ; 018b | REL32 +3 PURE_PROPERTY$NPHASE_1 addendLE=00000000
    mov r8,r9                                                  ; 0192
    mov r13,r9                                                 ; 0195
    lea r9,[rel $+7]                                           ; 0198 | REL32 +3 PURE_PROPERTY$NCOMP_1 addendLE=00000000
    call $+5                                                   ; 019f | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    mov r11,[rbp-0x18]                                         ; 01a4
    mov r10,[rbp-0x20]                                         ; 01a8
    mov rdx,[rbp-0x30]                                         ; 01ac
    mov r8,[rbp-0x28]                                          ; 01b0
    mov r9,r13                                                 ; 01b4
    add rsp,0x90                                               ; 01b7
    movsd xmm0,qword [rel $+8]                                 ; 01be | REL32 +4 PURE_PROPERTY$TEMP addendLE=00000000
    mov rax,[rel $+7]                                          ; 01c6 | REL32 +3 PURE_PROPERTY$I addendLE=00000000
    mov rcx,[rbp+0x78]                                         ; 01cd
    movsd qword [rcx+rax*8-0x8],xmm0                           ; 01d1
    lea rcx,[rax+0x1]                                          ; 01d7
    mov [rel $+7],rcx                                          ; 01db | REL32 +3 PURE_PROPERTY$I addendLE=00000000
    cmp rax,rdi                                                ; 01e2
    jl near loc_0100                                            ; 01e5
    mov qword [rel $+7],0x1                                    ; 01eb | REL32 +3 PURE_PROPERTY$I addendLE=fcffffff
    xor ecx,ecx                                                ; 01f6
    mov rbx,0x3e7ad7f29abcaf48                                 ; 01f8
    cvtsi2sd xmm6,ecx                                          ; 0202
    mov [rbp-0x38],r14                                         ; 0206
    jmp short loc_023b                                          ; 020a
    nop dword [byte rax+0x0]                                   ; 020c
loc_0210:
    lea rax,[rcx+0x1]                                          ; 0210
    mov [rel $+7],rax                                          ; 0214 | REL32 +3 PURE_PROPERTY$I addendLE=00000000
    cmp rcx,rdi                                                ; 021b
    mov r9,r13                                                 ; 021e
    mov r8,[rbp-0x28]                                          ; 0221
    mov rdx,[rbp-0x30]                                         ; 0225
    mov r14,[rbp-0x38]                                         ; 0229
    mov r10,[rbp-0x20]                                         ; 022d
    mov r11,[rbp-0x18]                                         ; 0231
    jnl near loc_044e                                           ; 0235
loc_023b:
    xor eax,eax                                                ; 023b
    nop dword [rax]                                            ; 023d
loc_0240:
    mov [r12+rax*8],rbx                                        ; 0240
    inc rax                                                    ; 0244
    cmp rdi,rax                                                ; 0247
    jnz short loc_0240                                          ; 024a
    mov rax,0x3fefffffc0000000                                 ; 024c
    mov [r12+rcx*8],rax                                        ; 0256
    xor eax,eax                                                ; 025a
    movapd xmm0,xmm6                                           ; 025c
loc_0260:
    addsd xmm0,[r12+rax*8]                                     ; 0260
    inc rax                                                    ; 0266
    cmp rdi,rax                                                ; 0269
    jnz short loc_0260                                          ; 026c
    xor eax,eax                                                ; 026e
    mov rcx,[rbp+0x98]                                         ; 0270
    nop word [dword rax+rax+0x0]                               ; 0277
loc_0280:
    movsd xmm1,qword [r12+rax*8]                               ; 0280
    divsd xmm1,xmm0                                            ; 0286
    movsd qword [r12+rax*8],xmm1                               ; 028a
    inc rax                                                    ; 0290
    cmp rdi,rax                                                ; 0293
    jnz short loc_0280                                          ; 0296
    sub rsp,0x90                                               ; 0298
    mov [rsp+0x80],rcx                                         ; 029f
    lea rax,[rel $+7]                                          ; 02a7 | REL32 +3 PURE_PROPERTY$KERR addendLE=00000000
    mov [rsp+0x70],rax                                         ; 02ae
    mov [rsp+0x68],r14                                         ; 02b3
    mov [rsp+0x60],r10                                         ; 02b8
    lea rax,[rel $+7]                                          ; 02bd | REL32 +3 PURE_PROPERTY$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 02c4
    mov [rsp+0x50],r11                                         ; 02c9
    mov [rsp+0x48],r15                                         ; 02ce
    lea rax,[rel $+7]                                          ; 02d3 | REL32 +3 PURE_PROPERTY$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 02da
    mov [rsp+0x38],rdx                                         ; 02df
    lea rax,[rel $+7]                                          ; 02e4 | REL32 +3 PURE_PROPERTY$TEMP addendLE=00000000
    mov [rsp+0x30],rax                                         ; 02eb
    mov [rsp+0x28],r12                                         ; 02f0
    mov [rsp+0x20],r8                                          ; 02f5
    mov qword [rsp+0x78],0x3                                   ; 02fa
    lea rcx,[rel $+7]                                          ; 0303 | REL32 +3 PURE_PROPERTY$FLASHTYPE addendLE=00000000
    mov rdx,[rbp+0x70]                                         ; 030a
    mov r8,r9                                                  ; 030e
    mov r14,[rbp-0x48]                                         ; 0311
    mov r9,r14                                                 ; 0315
    call $+5                                                   ; 0318 | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 031d
    mov rax,[r14]                                              ; 0324
    mov rcx,[rel $+7]                                          ; 0327 | REL32 +3 PURE_PROPERTY$I addendLE=00000000
    test rax,rax                                               ; 032e
    jng near loc_0210                                           ; 0331
    lea rdx,[rcx-0x1]                                          ; 0337
    imul rdx,[rbp-0x40]                                        ; 033b
    add rdx,rsi                                                ; 0340
    xor r8d,r8d                                                ; 0343
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 0346 | nop word [cs:rax+rax+0x0]
loc_0350:
    movsd xmm0,qword [r15+r8*8]                                ; 0350
    divsd xmm0,[r12+r8*8]                                      ; 0356
    movsd qword [rdx+r8*8],xmm0                                ; 035c
    inc r8                                                     ; 0362
    cmp rax,r8                                                 ; 0365
    jnz short loc_0350                                          ; 0368
    lea rdx,[rcx+0x1]                                          ; 036a
    mov [rel $+7],rdx                                          ; 036e | REL32 +3 PURE_PROPERTY$I addendLE=00000000
    cmp rcx,rdi                                                ; 0375
    mov r9,r13                                                 ; 0378
    mov r8,[rbp-0x28]                                          ; 037b
    mov rdx,[rbp-0x30]                                         ; 037f
    mov r14,[rbp-0x38]                                         ; 0383
    mov r10,[rbp-0x20]                                         ; 0387
    mov r11,[rbp-0x18]                                         ; 038b
    jl near loc_023b                                            ; 038f
    lea rcx,[rax+0x1]                                          ; 0395
    mov r8d,0x1                                                ; 0399
    xor edx,edx                                                ; 039f
    movsd xmm0,qword [rel $+8]                                 ; 03a1 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor r9d,r9d                                                ; 03a9
    mov rbx,[rbp+0x80]                                         ; 03ac
    jmp short loc_03dc                                          ; 03b3
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 03b5 | nop word [cs:rax+rax+0x0]
loc_03c0:
    mov qword [rbx+r8*8-0x8],0x1                               ; 03c0
loc_03c9:
    lea r10,[r8+0x1]                                           ; 03c9
    add rsi,[rbp-0x40]                                         ; 03cd
    inc r9                                                     ; 03d1
    cmp r8,rax                                                 ; 03d4
    mov r8,r10                                                 ; 03d7
    jnl short loc_0453                                          ; 03da
loc_03dc:
    mov r10,0xffffffffffffffff                                 ; 03dc
    xor edi,edi                                                ; 03e3
    mov r11,0xffffffffffffffff                                 ; 03e5
    jmp short loc_03f8                                          ; 03ec
    o16 nop                                                    ; 03ee
loc_03f0:
    inc rdi                                                    ; 03f0
    cmp rax,rdi                                                ; 03f3
    jz short loc_0420                                           ; 03f6
loc_03f8:
    cmp r9,rdi                                                 ; 03f8
    jz short loc_03f0                                           ; 03fb
    movsd xmm1,qword [rsi+rdi*8]                               ; 03fd
    ucomisd xmm1,xmm0                                          ; 0402
    cmovc r11,rdx                                              ; 0406
    ucomisd xmm0,xmm1                                          ; 040a
    cmovc r10,rdx                                              ; 040e
    jmp short loc_03f0                                          ; 0412
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0414 | nop word [cs:rax+rax+0x0]
loc_0420:
    test r11b,0x1                                              ; 0420
    jnz short loc_03c0                                          ; 0424
    test r10b,0x1                                              ; 0426
    jnz short loc_0440                                          ; 042a
    mov qword [rbx+r8*8-0x8],0x2                               ; 042c
    jmp short loc_03c9                                          ; 0435
    nop word [dword rax+rax+0x0]                               ; 0437
loc_0440:
    mov qword [rbx+r8*8-0x8],0x3                               ; 0440
    jmp near loc_03c9                                           ; 0449
loc_044e:
    mov ecx,0x1                                                ; 044e
loc_0453:
    mov [rel $+7],rcx                                          ; 0453 | REL32 +3 PURE_PROPERTY$I addendLE=00000000
loc_045a:
    movaps xmm6,oword [rbp-0x10]                               ; 045a
    lea rsp,[rbp+0x8]                                          ; 045e
    pop rbx                                                    ; 0462
    pop rdi                                                    ; 0463
    pop rsi                                                    ; 0464
    pop r12                                                    ; 0465
    pop r13                                                    ; 0467
    pop r14                                                    ; 0469
    pop r15                                                    ; 046b
    pop rbp                                                    ; 046d
    retq                                                       ; 046e

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .rdata (COFF section 4)
coff_section_4:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .xdata (COFF section 5)
coff_section_5:
    db 0x01,0x1a,0x0c,0x55,0x1a,0x68,0x04,0x00,0x15,0x03,0x10,0xa2,0x0c,0x30,0x0b,0x70
    db 0x0a,0x60,0x09,0xc0,0x07,0xd0,0x05,0xe0,0x03,0xf0,0x01,0x50

; .rdata (COFF section 6)
coff_section_6:
    db 0x50,0x56,0x00

; .drectve (COFF section 7)
coff_section_7:
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

; .pdata (COFF section 8)
coff_section_8:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x0000046f ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 9)
