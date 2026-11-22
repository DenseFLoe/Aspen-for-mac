; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ5:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbp                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x98                                               ; 000c
    movapd oword [rsp+0x80],xmm13                              ; 0013
    movapd oword [rsp+0x70],xmm12                              ; 001d
    movaps oword [rsp+0x60],xmm11                              ; 0024
    movapd oword [rsp+0x50],xmm10                              ; 002a
    movapd oword [rsp+0x40],xmm9                               ; 0031
    movapd oword [rsp+0x30],xmm8                               ; 0038
    movapd oword [rsp+0x20],xmm7                               ; 003f
    movapd oword [rsp+0x10],xmm6                               ; 0045
    mov rax,[rsp+0x108]                                        ; 004b
    movsd xmm0,qword [rel $+8]                                 ; 0053 | REL32 +4 __real@4030000000000000 addendLE=00000000
    mulsd xmm0,qword [rax]                                     ; 005b
    mov rax,[rcx]                                              ; 005f
    test rax,rax                                               ; 0062
    jng near loc_0227                                           ; 0065
    mov rcx,[rsp+0x100]                                        ; 006b
    mov r10,[rcx]                                              ; 0073
    lea rbp,[r10*8+0x0]                                        ; 0076
    movapd xmm1,oword [rel $+8]                                ; 007e | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    andpd xmm1,xmm0                                            ; 0086
    movapd xmm2,oword [rel $+8]                                ; 008a | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    orpd xmm2,xmm0                                             ; 0092
    lea r11,[rax-0x1]                                          ; 0096
    lea rsi,[rbp+0x8]                                          ; 009a
    movsd xmm3,qword [rel $+8]                                 ; 009e | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor r15d,r15d                                              ; 00a6
    movapd xmm4,oword [rel $+8]                                ; 00a9 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xorps xmm5,xmm5                                            ; 00b1
    mov rdi,rdx                                                ; 00b4
    mov rbx,r8                                                 ; 00b7
    mov r14,r9                                                 ; 00ba
    mov r12,rax                                                ; 00bd
    mov [rsp+0x8],rax                                          ; 00c0
    jmp short loc_0101                                          ; 00c5
    nop word [dword rax+rax+0x0]                               ; 00c7
loc_00d0:
    mulsd xmm6,xmm8                                            ; 00d0
    subsd xmm3,xmm6                                            ; 00d5
    mov rbp,r11                                                ; 00d9
    mov r11,rsi                                                ; 00dc
    mov rsi,rax                                                ; 00df
    mov rax,[rsp+0x8]                                          ; 00e2
loc_00e7:
    dec r12                                                    ; 00e7
    add r14,rsi                                                ; 00ea
    add rbx,0x8                                                ; 00ed
    add rdi,0x8                                                ; 00f1
    cmp r15,r11                                                ; 00f5
    mov r15,r13                                                ; 00f8
    jz near loc_0227                                            ; 00fb
loc_0101:
    movsd xmm6,qword [r8+r15*8]                                ; 0101
    mov rcx,rbp                                                ; 0107
    imul rcx,r15                                               ; 010a
    add rcx,r9                                                 ; 010e
    movsd xmm11,qword [rcx+r15*8]                              ; 0111
    movapd xmm7,xmm6                                           ; 0117
    divsd xmm7,xmm11                                           ; 011b
    movsd xmm9,qword [rdx+r15*8]                               ; 0120
    movapd xmm8,xmm9                                           ; 0126
    mulsd xmm8,xmm3                                            ; 012b
    movapd xmm10,xmm6                                          ; 0130
    mulsd xmm10,xmm8                                           ; 0135
    addsd xmm10,xmm11                                          ; 013a
    movsd qword [rcx+r15*8],xmm10                              ; 013f
    movapd xmm11,xmm10                                         ; 0145
    andpd xmm11,xmm4                                           ; 014a
    ucomisd xmm0,xmm11                                         ; 014f
    jna short loc_0176                                          ; 0154
    xorps xmm11,xmm11                                          ; 0156
    cvtss2sd xmm11,xmm5                                        ; 015a
    ucomisd xmm11,xmm10                                        ; 015f
    movapd xmm10,xmm2                                          ; 0164
    ja short loc_0170                                           ; 0169
    movapd xmm10,xmm1                                          ; 016b
loc_0170:
    movsd qword [rcx+r15*8],xmm10                              ; 0170
loc_0176:
    lea r13,[r15+0x1]                                          ; 0176
    cmp r13,rax                                                ; 017a
    jz near loc_00e7                                            ; 017d
    mov rax,rsi                                                ; 0183
    mov rsi,r11                                                ; 0186
    mov r11,rbp                                                ; 0189
    mulsd xmm6,xmm3                                            ; 018c
    divsd xmm6,xmm10                                           ; 0190
    jnl near loc_00d0                                           ; 0195
    mov ebp,0x1                                                ; 019b
    mov rcx,r10                                                ; 01a0
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 01a3 | nop word [cs:rax+rax+0x0]
loc_01b0:
    movsd xmm10,qword [r14+rcx*8]                              ; 01b0
    movapd xmm11,xmm10                                         ; 01b6
    mulsd xmm11,xmm9                                           ; 01bb
    movsd xmm12,qword [rdi+rbp*8]                              ; 01c0
    subsd xmm12,xmm11                                          ; 01c6
    movsd qword [rdi+rbp*8],xmm12                              ; 01cb
    mulsd xmm12,xmm6                                           ; 01d1
    addsd xmm12,xmm10                                          ; 01d6
    movsd qword [r14+rcx*8],xmm12                              ; 01db
    movsd xmm10,qword [rbx+rbp*8]                              ; 01e1
    movapd xmm11,xmm8                                          ; 01e7
    mulsd xmm11,xmm10                                          ; 01ec
    movsd xmm12,qword [r14+rbp*8]                              ; 01f1
    movapd xmm13,xmm7                                          ; 01f7
    mulsd xmm13,xmm12                                          ; 01fc
    subsd xmm10,xmm13                                          ; 0201
    movsd qword [rbx+rbp*8],xmm10                              ; 0206
    addsd xmm11,xmm12                                          ; 020c
    movsd qword [r14+rbp*8],xmm11                              ; 0211
    inc rbp                                                    ; 0217
    add rcx,r10                                                ; 021a
    cmp r12,rbp                                                ; 021d
    jnz short loc_01b0                                          ; 0220
    jmp near loc_00d0                                           ; 0222
loc_0227:
    movaps xmm6,oword [rsp+0x10]                               ; 0227
    movaps xmm7,oword [rsp+0x20]                               ; 022c
    movaps xmm8,oword [rsp+0x30]                               ; 0231
    movaps xmm9,oword [rsp+0x40]                               ; 0237
    movaps xmm10,oword [rsp+0x50]                              ; 023d
    movaps xmm11,oword [rsp+0x60]                              ; 0243
    movaps xmm12,oword [rsp+0x70]                              ; 0249
    movaps xmm13,oword [rsp+0x80]                              ; 024f
    add rsp,0x98                                               ; 0258
    pop rbx                                                    ; 025f
    pop rbp                                                    ; 0260
    pop rdi                                                    ; 0261
    pop rsi                                                    ; 0262
    pop r12                                                    ; 0263
    pop r13                                                    ; 0265
    pop r14                                                    ; 0267
    pop r15                                                    ; 0269
    retq                                                       ; 026b

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .rdata (COFF section 4)
coff_section_4:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x40

; .rdata (COFF section 5)
coff_section_5:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f

; .rdata (COFF section 6)
coff_section_6:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80

; .rdata (COFF section 7)
coff_section_7:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .xdata (COFF section 8)
coff_section_8:
    db 0x01,0x4b,0x1a,0x00,0x4b,0x68,0x01,0x00,0x45,0x78,0x02,0x00,0x3f,0x88,0x03,0x00
    db 0x38,0x98,0x04,0x00,0x31,0xa8,0x05,0x00,0x2a,0xb8,0x06,0x00,0x24,0xc8,0x07,0x00
    db 0x1d,0xd8,0x08,0x00,0x13,0x01,0x13,0x00,0x0c,0x30,0x0b,0x50,0x0a,0x70,0x09,0x60
    db 0x08,0xc0,0x06,0xd0,0x04,0xe0,0x02,0xf0

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
    dd 0x0000026c ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 18)
