; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ3:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbp                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x98                                               ; 000c
    movapd oword [rsp+0x80],xmm12                              ; 0013
    movapd oword [rsp+0x70],xmm11                              ; 001d
    movapd oword [rsp+0x60],xmm10                              ; 0024
    movapd oword [rsp+0x50],xmm9                               ; 002b
    movapd oword [rsp+0x40],xmm8                               ; 0032
    movapd oword [rsp+0x30],xmm7                               ; 0039
    movapd oword [rsp+0x20],xmm6                               ; 003f
    mov rax,[rsp+0x108]                                        ; 0045
    movsd xmm0,qword [rel $+8]                                 ; 004d | REL32 +4 __real@4030000000000000 addendLE=00000000
    mulsd xmm0,qword [rax]                                     ; 0055
    mov rdx,[rdx]                                              ; 0059
    mov rax,[rcx]                                              ; 005c
    mov [rsp+0x18],r9                                          ; 005f
    mov qword [r9+rax*8-0x8],0x1                               ; 0064
    test rax,rax                                               ; 006d
    jng near loc_0346                                           ; 0070
    mov rcx,[rsp+0x100]                                        ; 0076
    shl rdx,byte 0x3                                           ; 007e
    lea r9,[rax-0x1]                                           ; 0082
    movsd xmm1,qword [rcx]                                     ; 0086
    movapd xmm2,oword [rel $+8]                                ; 008a | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    andpd xmm2,xmm0                                            ; 0092
    movapd xmm3,oword [rel $+8]                                ; 0096 | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    orpd xmm3,xmm0                                             ; 009e
    mov rcx,rdx                                                ; 00a2
    imul rcx,r9                                                ; 00a5
    add rcx,r8                                                 ; 00a9
    lea rbx,[rcx+r9*8]                                         ; 00ac
    lea r10,[r8+rdx]                                           ; 00b0
    lea r14,[rdx+0x8]                                          ; 00b4
    lea rcx,[r8+rdx]                                           ; 00b8
    add rcx,0x8                                                ; 00bc
    lea rdi,[r8+0x8]                                           ; 00c0
    mov r11d,0x1                                               ; 00c4
    xor r12d,r12d                                              ; 00ca
    movapd xmm4,oword [rel $+8]                                ; 00cd | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xorps xmm5,xmm5                                            ; 00d5
    movapd xmm6,oword [rel $+8]                                ; 00d8 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xorpd xmm7,xmm7                                            ; 00e0
    movsd xmm8,qword [rel $+9]                                 ; 00e4 | REL32 +5 __real@3ff0000000000000 addendLE=00000000
    mov r15,r8                                                 ; 00ed
    mov [rsp],rbx                                              ; 00f0
    mov [rsp+0x10],r14                                         ; 00f4
    jmp short loc_0128                                          ; 00f9
    nop dword [byte rax+rax+0x0]                               ; 00fb
loc_0100:
    movsd qword [rbp+0x0],xmm9                                 ; 0100
loc_0106:
    mov r9b,sil                                                ; 0106
    add r12,r9                                                 ; 0109
    lea r9,[r11+0x1]                                           ; 010c
    add r10,r14                                                ; 0110
    add r15,rdx                                                ; 0113
    add rcx,r14                                                ; 0116
    add rdi,r14                                                ; 0119
    cmp r11,rax                                                ; 011c
    mov r11,r9                                                 ; 011f
    jnl near loc_0333                                           ; 0122
loc_0128:
    mov rbp,rbx                                                ; 0128
    cmp r11,rax                                                ; 012b
    jz near loc_02e9                                            ; 012e
    mov [rsp+0x8],r12                                          ; 0134
    lea r12,[r11+0x1]                                          ; 0139
    cmp rax,r11                                                ; 013d
    jng short loc_01b0                                          ; 0140
    lea r13,[r11-0x1]                                          ; 0142
    mov rsi,r10                                                ; 0146
    mov r14,r11                                                ; 0149
    mov rbp,r12                                                ; 014c
    jmp short loc_0172                                          ; 014f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0151 | nop word [cs:rax+rax+0x0]
loc_0160:
    lea rbx,[rbp+0x1]                                          ; 0160
    add rsi,rdx                                                ; 0164
    mov r14,r9                                                 ; 0167
    cmp rbp,rax                                                ; 016a
    mov rbp,rbx                                                ; 016d
    jnl short loc_01c0                                          ; 0170
loc_0172:
    movsd xmm9,qword [rsi]                                     ; 0172
    andpd xmm9,xmm6                                            ; 0177
    lea r9,[r14-0x1]                                           ; 017c
    imul r9,rdx                                                ; 0180
    add r9,r8                                                  ; 0184
    movsd xmm10,qword [r9+r11*8-0x8]                           ; 0187
    andpd xmm10,xmm6                                           ; 018e
    ucomisd xmm9,xmm10                                         ; 0193
    mov r9,rbp                                                 ; 0198
    ja short loc_0160                                           ; 019b
    mov r9,r14                                                 ; 019d
    jmp short loc_0160                                          ; 01a0
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 01a2 | nop word [cs:rax+rax+0x0]
loc_01b0:
    lea rsi,[r11-0x1]                                          ; 01b0
    mov r13,rsi                                                ; 01b4
    mov r9,r11                                                 ; 01b7
    jmp short loc_01c4                                          ; 01ba
    nop dword [byte rax+0x0]                                   ; 01bc
loc_01c0:
    lea rsi,[r9-0x1]                                           ; 01c0
loc_01c4:
    mov rbx,[rsp+0x18]                                         ; 01c4
    mov [rbx+r13*8],r9                                         ; 01c9
    imul rsi,rdx                                               ; 01cd
    add rsi,r8                                                 ; 01d1
    mov r9,rdx                                                 ; 01d4
    imul r9,r13                                                ; 01d7
    add r9,r8                                                  ; 01db
    xor r14d,r14d                                              ; 01de
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 01e1 | nop word [cs:rax+rax+0x0]
loc_01f0:
    movsd xmm9,qword [rsi+r14*8]                               ; 01f0
    movsd xmm10,qword [r15+r14*8]                              ; 01f6
    movsd qword [rsi+r14*8],xmm10                              ; 01fc
    movsd qword [r15+r14*8],xmm9                               ; 0202
    inc r14                                                    ; 0208
    cmp rax,r14                                                ; 020b
    jnz short loc_01f0                                          ; 020e
    movsd xmm10,qword [r9+r13*8]                               ; 0210
    ucomisd xmm7,xmm10                                         ; 0216
    lea rbp,[r9+r13*8]                                         ; 021b
    setpo r9b                                                  ; 021f
    setz bl                                                    ; 0223
    test bl,r9b                                                ; 0226
    jz short loc_0240                                           ; 0229
    mov rbx,[rsp]                                              ; 022b
    mov r14,[rsp+0x10]                                         ; 022f
    jmp near loc_02e4                                           ; 0234
    nop dword [dword rax+0x0]                                  ; 0239
loc_0240:
    movapd xmm9,xmm8                                           ; 0240
    divsd xmm9,xmm10                                           ; 0245
    cmp rax,r11                                                ; 024a
    mov r14,[rsp+0x10]                                         ; 024d
    jng near loc_02e0                                           ; 0252
    mov rsi,rcx                                                ; 0258
    jmp short loc_0270                                          ; 025b
    nop dword [rax]                                            ; 025d
loc_0260:
    lea r9,[r12+0x1]                                           ; 0260
    add rsi,rdx                                                ; 0265
    cmp r12,rax                                                ; 0268
    mov r12,r9                                                 ; 026b
    jnl short loc_02e0                                          ; 026e
loc_0270:
    lea r9,[r12-0x1]                                           ; 0270
    imul r9,rdx                                                ; 0275
    add r9,r8                                                  ; 0279
    movsd xmm10,qword [r9+r13*8]                               ; 027c
    mulsd xmm10,xmm9                                           ; 0282
    ucomisd xmm10,xmm7                                         ; 0287
    movsd qword [r9+r13*8],xmm10                               ; 028c
    setpo r9b                                                  ; 0292
    setz bl                                                    ; 0296
    test bl,r9b                                                ; 0299
    jnz short loc_0260                                          ; 029c
    xor r9d,r9d                                                ; 029e
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 02a1 | nop word [cs:rax+rax+0x0]
loc_02b0:
    movsd xmm11,qword [rsi+r9*8]                               ; 02b0
    movsd xmm12,qword [rdi+r9*8]                               ; 02b6
    mulsd xmm12,xmm10                                          ; 02bc
    subsd xmm11,xmm12                                          ; 02c1
    movsd qword [rsi+r9*8],xmm11                               ; 02c6
    lea rbx,[r11+r9]                                           ; 02cc
    inc rbx                                                    ; 02d0
    inc r9                                                     ; 02d3
    cmp rbx,rax                                                ; 02d6
    jl short loc_02b0                                           ; 02d9
    jmp short loc_0260                                          ; 02db
    nop dword [rax]                                            ; 02dd
loc_02e0:
    mov rbx,[rsp]                                              ; 02e0
loc_02e4:
    mov r12,[rsp+0x8]                                          ; 02e4
loc_02e9:
    movsd xmm9,qword [rbp+0x0]                                 ; 02e9
    movapd xmm10,xmm9                                          ; 02ef
    andpd xmm10,xmm4                                           ; 02f4
    xor r9d,r9d                                                ; 02f9
    ucomisd xmm1,xmm10                                         ; 02fc
    seta sil                                                   ; 0301
    ucomisd xmm0,xmm10                                         ; 0305
    jna near loc_0106                                           ; 030a
    xorps xmm10,xmm10                                          ; 0310
    cvtss2sd xmm10,xmm5                                        ; 0314
    ucomisd xmm10,xmm9                                         ; 0319
    movapd xmm9,xmm3                                           ; 031e
    ja near loc_0100                                            ; 0323
    movapd xmm9,xmm2                                           ; 0329
    jmp near loc_0100                                           ; 032e
loc_0333:
    test r12,r12                                               ; 0333
    jz short loc_0346                                           ; 0336
    mov rcx,[rsp+0x18]                                         ; 0338
    mov qword [rcx+rax*8-0x8],0x0                              ; 033d
loc_0346:
    movaps xmm6,oword [rsp+0x20]                               ; 0346
    movaps xmm7,oword [rsp+0x30]                               ; 034b
    movaps xmm8,oword [rsp+0x40]                               ; 0350
    movaps xmm9,oword [rsp+0x50]                               ; 0356
    movaps xmm10,oword [rsp+0x60]                              ; 035c
    movaps xmm11,oword [rsp+0x70]                              ; 0362
    movaps xmm12,oword [rsp+0x80]                              ; 0368
    add rsp,0x98                                               ; 0371
    pop rbx                                                    ; 0378
    pop rbp                                                    ; 0379
    pop rdi                                                    ; 037a
    pop rsi                                                    ; 037b
    pop r12                                                    ; 037c
    pop r13                                                    ; 037e
    pop r14                                                    ; 0380
    pop r15                                                    ; 0382
    retq                                                       ; 0384

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
    db 0x01,0x45,0x18,0x00,0x45,0x68,0x02,0x00,0x3f,0x78,0x03,0x00,0x39,0x88,0x04,0x00
    db 0x32,0x98,0x05,0x00,0x2b,0xa8,0x06,0x00,0x24,0xb8,0x07,0x00,0x1d,0xc8,0x08,0x00
    db 0x13,0x01,0x13,0x00,0x0c,0x30,0x0b,0x50,0x0a,0x70,0x09,0x60,0x08,0xc0,0x06,0xd0
    db 0x04,0xe0,0x02,0xf0

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
    dd 0x00000385 ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 18)
