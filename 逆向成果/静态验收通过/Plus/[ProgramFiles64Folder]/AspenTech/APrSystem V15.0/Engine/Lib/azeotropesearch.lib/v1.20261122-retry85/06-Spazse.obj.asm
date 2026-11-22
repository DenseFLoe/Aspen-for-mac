; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

SPAZSE:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbp                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x228                                              ; 000c
    movapd oword [rsp+0x210],xmm9                              ; 0013
    movapd oword [rsp+0x200],xmm8                              ; 001d
    movapd oword [rsp+0x1f0],xmm7                              ; 0027
    movapd oword [rsp+0x1e0],xmm6                              ; 0030
    mov [rsp+0xa0],rdx                                         ; 0039
    mov [rsp+0x98],rcx                                         ; 0041
    mov rcx,[rsp+0x2b0]                                        ; 0049
    mov rax,[rsp+0x2a8]                                        ; 0051
    mov r10,0x801208384ff00                                    ; 0059
    mov r14,[r8]                                               ; 0063
    mov rdx,[rax]                                              ; 0066
    mov qword [rel $+7],0x0                                    ; 0069 | REL32 +3 SPAZSE$INIT addendLE=fcffffff
    mov r12,[rcx]                                              ; 0074
    mov rax,rdx                                                ; 0077
    mov [rsp+0xd8],rdx                                         ; 007a
    cmp r12,rdx                                                ; 0082
    jnl near loc_0e6c                                           ; 0085
    mov rdi,r9                                                 ; 008b
    mov rax,[rsp+0x2f8]                                        ; 008e
    mov rcx,[rsp+0x2d8]                                        ; 0096
    mov rdx,[rsp+0x2b8]                                        ; 009e
    mov r8,[rsp+0x2a0]                                         ; 00a6
    mov r15,[rsp+0x298]                                        ; 00ae
    lea r13,[r14*8+0x0]                                        ; 00b6
    mov rax,[rax]                                              ; 00be
    mov [rsp+0xf8],rax                                         ; 00c1
    mov rbx,r14                                                ; 00c9
    neg rbx                                                    ; 00cc
    xorpd xmm6,xmm6                                            ; 00cf
    movsd xmm7,qword [rel $+8]                                 ; 00d3 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    movsd xmm8,qword [rel $+9]                                 ; 00db | REL32 +5 __real@4008000000000000 addendLE=00000000
    movsd xmm9,qword [rel $+9]                                 ; 00e4 | REL32 +5 __real@4024000000000000 addendLE=00000000
    mov rax,[rsp+0xd8]                                         ; 00ed
    lea rbp,[rax*8+0x0]                                        ; 00f5
    lea rax,[r14+0x1]                                          ; 00fd
    mov [rsp+0xe8],rax                                         ; 0101
    mov rax,[rcx]                                              ; 0109
    mov [rsp+0x80],rax                                         ; 010c
    lea rax,[r14-0x1]                                          ; 0114
    mov [rsp+0xe0],rax                                         ; 0118
    lea rax,[rdx-0x8]                                          ; 0120
    mov [rsp+0xf0],rax                                         ; 0124
    jmp short loc_0180                                          ; 012c
    o16 nop                                                    ; 012e
loc_0130:
    xorps xmm0,xmm0                                            ; 0130
    cvtsi2sd xmm0,rax                                          ; 0133
    movapd xmm1,xmm7                                           ; 0138
    divsd xmm1,xmm0                                            ; 013c
    lea rcx,[rel $+7]                                          ; 0140 | REL32 +3 SPAZSE$XNAZEO addendLE=00000000
    movsd qword [rcx+rax*8-0x8],xmm1                           ; 0147
    mov qword [rel $+7],0xffffffffffffffff                     ; 014d | REL32 +3 SPAZSE$INIT addendLE=fcffffff
    mov r12,[rsp+0x88]                                         ; 0158
    cmp r12,[rsp+0xd8]                                         ; 0160
    mov r10,0x801208384ff00                                    ; 0168
    mov r8,[rsp+0x2a0]                                         ; 0172
    jnl near loc_0e6c                                           ; 017a
loc_0180:
    cmp qword [rsp+0x80],0x320                                 ; 0180
    jnl near loc_0f0a                                           ; 018c
    mov qword [rel $+7],0x0                                    ; 0192 | REL32 +3 SPAZSE$AZEO addendLE=fcffffff
    mov qword [rel $+7],0x2                                    ; 019d | REL32 +3 SPAZSE$NPHASE addendLE=fcffffff
    mov rax,[r8]                                               ; 01a8
    cmp qword [rsp+0xf8],0x2                                   ; 01ab
    mov [rsp+0x88],r12                                         ; 01b4
    jz short loc_01c8                                           ; 01bc
    cmp rax,0x2                                                ; 01be
    jnl near loc_0640                                           ; 01c2
loc_01c8:
    test rax,rax                                               ; 01c8
    jng near loc_02f0                                           ; 01cb
    mov rdx,[rel $+7]                                          ; 01d1 | REL32 +3 SPAZSE$COM1 addendLE=00000000
    mov ecx,0x1                                                ; 01d8
    mov r8,[rel $+7]                                           ; 01dd | REL32 +3 SPAZSE$COM2 addendLE=00000000
    mov r12,[rsp+0x2e8]                                        ; 01e4
    jmp short loc_0200                                          ; 01ec
    o16 nop                                                    ; 01ee
loc_01f0:
    lea r9,[rcx+0x1]                                           ; 01f0
    cmp rcx,rax                                                ; 01f4
    mov rcx,r9                                                 ; 01f7
    jnl near loc_02f0                                           ; 01fa
loc_0200:
    test r14,r14                                               ; 0200
    jng short loc_0250                                          ; 0203
    mov r9,[r15+rcx*8-0x8]                                     ; 0205
    mov r10d,0x1                                               ; 020a
    jmp short loc_0230                                          ; 0210
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0212 | nop word [cs:rax+rax+0x0]
loc_0220:
    lea r11,[rbx+r10]                                          ; 0220
    inc r11                                                    ; 0224
    inc r10                                                    ; 0227
    cmp r11,0x1                                                ; 022a
    jz short loc_0250                                           ; 022e
loc_0230:
    cmp r9,[rdi+r10*8-0x8]                                     ; 0230
    jnz short loc_0220                                          ; 0235
    mov [rel $+7],r10                                          ; 0237 | REL32 +3 SPAZSE$COM1 addendLE=00000000
    mov rdx,r10                                                ; 023e
    jmp short loc_0220                                          ; 0241
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0243 | nop word [cs:rax+rax+0x0]
loc_0250:
    mov r9d,0x1                                                ; 0250
    jmp short loc_028b                                          ; 0256
    nop dword [dword rax+rax+0x0]                              ; 0258
loc_0260:
    imul r10,r9,0x320                                          ; 0260
    lea r11,[rel $+7]                                          ; 0267 | REL32 +3 SPAZSE$KVLS addendLE=00000000
    add r10,r11                                                ; 026e
    movsd qword [r10+rcx*8-0x328],xmm0                         ; 0271
    lea r10,[r9+0x1]                                           ; 027b
    cmp r9,rax                                                 ; 027f
    mov r9,r10                                                 ; 0282
    jz near loc_01f0                                            ; 0285
loc_028b:
    test r14,r14                                               ; 028b
    jng short loc_02d0                                          ; 028e
    mov r10,[r15+r9*8-0x8]                                     ; 0290
    mov r11d,0x1                                               ; 0295
    jmp short loc_02b0                                          ; 029b
    nop dword [rax]                                            ; 029d
loc_02a0:
    lea rsi,[rbx+r11]                                          ; 02a0
    inc rsi                                                    ; 02a4
    inc r11                                                    ; 02a7
    cmp rsi,0x1                                                ; 02aa
    jz short loc_02d0                                           ; 02ae
loc_02b0:
    cmp r10,[rdi+r11*8-0x8]                                    ; 02b0
    jnz short loc_02a0                                          ; 02b5
    mov [rel $+7],r11                                          ; 02b7 | REL32 +3 SPAZSE$COM2 addendLE=00000000
    mov r8,r11                                                 ; 02be
    jmp short loc_02a0                                          ; 02c1
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 02c3 | nop word [cs:rax+rax+0x0]
loc_02d0:
    movapd xmm0,xmm7                                           ; 02d0
    cmp rdx,r8                                                 ; 02d4
    jz short loc_0260                                           ; 02d7
    lea r10,[r8-0x1]                                           ; 02d9
    imul r10,r13                                               ; 02dd
    add r10,r12                                                ; 02e1
    movsd xmm0,qword [r10+rdx*8-0x8]                           ; 02e4
    jmp near loc_0260                                           ; 02eb
loc_02f0:
    mov rax,[rsp+0x308]                                        ; 02f0
    mov [rsp+0x68],rax                                         ; 02f8
    mov rax,[rsp+0x300]                                        ; 02fd
    mov [rsp+0x60],rax                                         ; 0305
    lea rax,[rel $+7]                                          ; 030a | REL32 +3 SPAZSE$XNAZEO addendLE=00000000
    mov [rsp+0x58],rax                                         ; 0311
    lea rax,[rel $+7]                                          ; 0316 | REL32 +3 SPAZSE$KVLS addendLE=00000000
    mov [rsp+0x50],rax                                         ; 031d
    mov [rsp+0x48],r15                                         ; 0322
    lea rax,[rel $+7]                                          ; 0327 | REL32 +3 SPAZSE$INIT addendLE=00000000
    mov [rsp+0x40],rax                                         ; 032e
    lea rax,[rel $+7]                                          ; 0333 | REL32 +3 SPAZSE$HETERO addendLE=00000000
    mov [rsp+0x38],rax                                         ; 033a
    lea rax,[rel $+7]                                          ; 033f | REL32 +3 SPAZSE$TBUB addendLE=00000000
    mov [rsp+0x30],rax                                         ; 0346
    lea rax,[rel $+7]                                          ; 034b | REL32 +3 SPAZSE$AZEO addendLE=00000000
    mov [rsp+0x28],rax                                         ; 0352
    mov rax,[rsp+0x290]                                        ; 0357
    mov [rsp+0x20],rax                                         ; 035f
    mov rcx,[rsp+0x98]                                         ; 0364
    mov rdx,[rsp+0xa0]                                         ; 036c
    mov rsi,[rsp+0x2a0]                                        ; 0374
    mov r8,rsi                                                 ; 037c
    lea r9,[rel $+7]                                           ; 037f | REL32 +3 SPAZSE$NPHASE addendLE=00000000
    call $+5                                                   ; 0386 | REL32 +1 SPNCAZ addendLE=00000000
    test byte [rel $+6],0x1                                    ; 038b | REL32 +2 SPAZSE$AZEO addendLE=ffffffff
    jnz near loc_0460                                           ; 0392
    mov rax,[rsp+0x80]                                         ; 0398
    lea rcx,[rax+0x1]                                          ; 03a0
    mov rax,[rsp+0x2d8]                                        ; 03a4
    mov [rax],rcx                                              ; 03ac
    mov qword [rel $+7],0x1                                    ; 03af | REL32 +3 SPAZSE$ICOMP addendLE=fcffffff
    mov rax,[rsi]                                              ; 03ba
    test r14,r14                                               ; 03bd
    mov r12,[rsp+0x88]                                         ; 03c0
    jng near loc_07ac                                           ; 03c8
    mov edx,0x1                                                ; 03ce
    mov r11,[rsp+0x80]                                         ; 03d3
    jmp short loc_03f0                                          ; 03db
    nop dword [rax]                                            ; 03dd
loc_03e0:
    lea r8,[rdx+0x1]                                           ; 03e0
    cmp rdx,r14                                                ; 03e4
    mov rdx,r8                                                 ; 03e7
    jnl near loc_0610                                           ; 03ea
loc_03f0:
    imul r8,rdx,0x1900                                         ; 03f0
    mov r9,[rsp+0x2e0]                                         ; 03f7
    add r9,r8                                                  ; 03ff
    mov r10,[rsp+0x80]                                         ; 0402
    mov qword [r9+r10*8-0x1900],0x0                            ; 040a
    test rax,rax                                               ; 0416
    jng short loc_03e0                                          ; 0419
    mov r9,[rsp+0x2e0]                                         ; 041b
    add r8,r9                                                  ; 0423
    add r8,0xffffffffffffe700                                  ; 0426
    mov r9,[rdi+rdx*8-0x8]                                     ; 042d
    xor r10d,r10d                                              ; 0432
    jmp short loc_0448                                          ; 0435
    nop word [dword rax+rax+0x0]                               ; 0437
loc_0440:
    inc r10                                                    ; 0440
    cmp rax,r10                                                ; 0443
    jz short loc_03e0                                           ; 0446
loc_0448:
    cmp r9,[r15+r10*8]                                         ; 0448
    jnz short loc_0440                                          ; 044c
    mov qword [r8+r11*8],0x1                                   ; 044e
    jmp short loc_0440                                          ; 0456
    nop dword [dword rax+rax+0x0]                              ; 0458
loc_0460:
    mov rax,[rsp+0x88]                                         ; 0460
    lea rcx,[rax+0x1]                                          ; 0468
    mov rax,[rsp+0x2b0]                                        ; 046c
    mov [rax],rcx                                              ; 0474
    mov qword [rsp+0x108],0x0                                  ; 0477
    mov dword [rsp+0xca],0x10b0438                             ; 0483
    mov word [rsp+0xce],0x2                                    ; 048e
    mov qword [rsp+0x1c8],0x50                                 ; 0498
    lea rax,[rel $+7]                                          ; 04a4 | REL32 +3 SPAZSE$MSG addendLE=00000000
    mov [rsp+0x1d0],rax                                        ; 04ab
    mov [rsp+0x90],rcx                                         ; 04b3
    mov [rsp+0x1d8],rcx                                        ; 04bb
    lea rax,[rel $+7]                                          ; 04c3 | REL32 +3 SPAZSE$format_pack addendLE=00000000
    mov [rsp+0x20],rax                                         ; 04ca
    lea r12,[rsp+0x108]                                        ; 04cf
    mov rcx,r12                                                ; 04d7
    mov rdx,0x801208384ff00                                    ; 04da
    lea r8,[rsp+0xca]                                          ; 04e4
    lea r9,[rsp+0x1c8]                                         ; 04ec
    call $+5                                                   ; 04f4 | REL32 +1 for_write_int_fmt addendLE=00000000
    mov byte [rsp+0x78],0x0                                    ; 04f9
    mov dword [rsp+0xc6],0x10438                               ; 04fe
    mov qword [rsp+0x198],0x1                                  ; 0509
    lea rax,[rsp+0x78]                                         ; 0515
    mov [rsp+0x1a0],rax                                        ; 051a
    mov rcx,r12                                                ; 0522
    lea rdx,[rsp+0xc6]                                         ; 0525
    lea r8,[rsp+0x198]                                         ; 052d
    call $+5                                                   ; 0535 | REL32 +1 for_write_int_fmt_xmit addendLE=00000000
    mov r11,[rsp+0x88]                                         ; 053a
    mov rax,[rsi]                                              ; 0542
    mov rcx,[rsp+0x2d0]                                        ; 0545
    mov [rcx+r11*8],rax                                        ; 054d
    movsd xmm0,qword [rel $+8]                                 ; 0551 | REL32 +4 SPAZSE$TBUB addendLE=00000000
    mov rcx,[rsp+0x2c0]                                        ; 0559
    movsd qword [rcx+r11*8],xmm0                               ; 0561
    mov rcx,[rel $+7]                                          ; 0567 | REL32 +3 SPAZSE$HETERO addendLE=00000000
    and ecx,0x1                                                ; 056e
    inc rcx                                                    ; 0571
    mov rdx,[rsp+0x2c8]                                        ; 0574
    mov [rdx+r11*8],rcx                                        ; 057c
    mov qword [rel $+7],0x1                                    ; 0580 | REL32 +3 SPAZSE$ICOMP addendLE=fcffffff
    test r14,r14                                               ; 058b
    jng near loc_07b6                                           ; 058e
    mov ecx,0x1                                                ; 0594
    mov r12,[rsp+0x90]                                         ; 0599
    lea rsi,[rel $+7]                                          ; 05a1 | REL32 +3 SPAZSE$XNAZEO addendLE=00000000
    jmp short loc_05bc                                          ; 05a8
    nop word [byte rax+rax+0x0]                                ; 05aa
loc_05b0:
    lea rdx,[rcx+0x1]                                          ; 05b0
    cmp rcx,r14                                                ; 05b4
    mov rcx,rdx                                                ; 05b7
    jnl short loc_0618                                          ; 05ba
loc_05bc:
    lea rdx,[rcx-0x1]                                          ; 05bc
    imul rdx,rbp                                               ; 05c0
    add rdx,[rsp+0x2b8]                                        ; 05c4
    mov qword [rdx+r11*8],0x0                                  ; 05cc
    test rax,rax                                               ; 05d4
    jng short loc_05b0                                          ; 05d7
    mov r8,[rdi+rcx*8-0x8]                                     ; 05d9
    xor r9d,r9d                                                ; 05de
    mov r10,rax                                                ; 05e1
    jmp short loc_05f9                                          ; 05e4
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 05e6 | nop word [cs:rax+rax+0x0]
loc_05f0:
    add r9,0x8                                                 ; 05f0
    dec r10                                                    ; 05f4
    jz short loc_05b0                                           ; 05f7
loc_05f9:
    cmp r8,[r15+r9]                                            ; 05f9
    jnz short loc_05f0                                          ; 05fd
    movsd xmm0,qword [r9+rsi]                                  ; 05ff
    movsd qword [rdx+r11*8],xmm0                               ; 0605
    jmp short loc_05f0                                          ; 060b
    nop dword [rax]                                            ; 060d
loc_0610:
    mov [rsp+0x80],rcx                                         ; 0610
loc_0618:
    mov rcx,[rsp+0xe8]                                         ; 0618
    mov [rel $+7],rcx                                          ; 0620 | REL32 +3 SPAZSE$ICOMP addendLE=00000000
    cmp r14,0x2                                                ; 0627
    mov rsi,[rsp+0x2a0]                                        ; 062b
    jnz near loc_07c0                                           ; 0633
    jmp near loc_0ed4                                           ; 0639
    o16 nop                                                    ; 063e
loc_0640:
    lea rcx,[rax-0x1]                                          ; 0640
    mov [rsp+0x90],rcx                                         ; 0644
    mov r8,[rel $+7]                                           ; 064c | REL32 +3 SPAZSE$COM1 addendLE=00000000
    mov ecx,0x1                                                ; 0653
    mov rsi,[rel $+7]                                          ; 0658 | REL32 +3 SPAZSE$COM2 addendLE=00000000
    jmp short loc_0683                                          ; 065f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0661 | nop word [cs:rax+rax+0x0]
loc_0670:
    lea rcx,[r12+0x1]                                          ; 0670
    cmp r12,[rsp+0x90]                                         ; 0675
    jnl near loc_01c8                                           ; 067d
loc_0683:
    test r14,r14                                               ; 0683
    jng short loc_06d0                                          ; 0686
    mov r12,rcx                                                ; 0688
    mov rcx,[r15+rcx*8-0x8]                                    ; 068b
    mov r9d,0x1                                                ; 0690
    jmp short loc_06b0                                          ; 0696
    nop dword [dword rax+rax+0x0]                              ; 0698
loc_06a0:
    lea r10,[rbx+r9]                                           ; 06a0
    inc r10                                                    ; 06a4
    inc r9                                                     ; 06a7
    cmp r10,0x1                                                ; 06aa
    jz short loc_06d3                                           ; 06ae
loc_06b0:
    cmp rcx,[rdi+r9*8-0x8]                                     ; 06b0
    jnz short loc_06a0                                          ; 06b5
    mov [rel $+7],r9                                           ; 06b7 | REL32 +3 SPAZSE$COM1 addendLE=00000000
    mov r8,r9                                                  ; 06be
    jmp short loc_06a0                                          ; 06c1
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 06c3 | nop word [cs:rax+rax+0x0]
loc_06d0:
    mov r12,rcx                                                ; 06d0
loc_06d3:
    lea r10,[r8-0x1]                                           ; 06d3
    imul r10,r13                                               ; 06d7
    add r10,[rsp+0x2e8]                                        ; 06db
    mov r11d,0x2                                               ; 06e3
    jmp short loc_070b                                          ; 06e9
    nop dword [byte rax+rax+0x0]                               ; 06eb
loc_06f0:
    mov qword [rel $+7],0x3                                    ; 06f0 | REL32 +3 SPAZSE$NPHASE addendLE=fcffffff
loc_06fb:
    lea rcx,[r11+0x1]                                          ; 06fb
    cmp r11,rax                                                ; 06ff
    mov r11,rcx                                                ; 0702
    jz near loc_0670                                            ; 0705
loc_070b:
    test r14,r14                                               ; 070b
    jng short loc_0750                                          ; 070e
    mov rcx,[r15+r11*8-0x8]                                    ; 0710
    mov r9d,0x1                                                ; 0715
    jmp short loc_0730                                          ; 071b
    nop dword [rax]                                            ; 071d
loc_0720:
    lea rdx,[rbx+r9]                                           ; 0720
    inc rdx                                                    ; 0724
    inc r9                                                     ; 0727
    cmp rdx,0x1                                                ; 072a
    jz short loc_0750                                           ; 072e
loc_0730:
    cmp rcx,[rdi+r9*8-0x8]                                     ; 0730
    jnz short loc_0720                                          ; 0735
    mov [rel $+7],r9                                           ; 0737 | REL32 +3 SPAZSE$COM2 addendLE=00000000
    mov rsi,r9                                                 ; 073e
    jmp short loc_0720                                          ; 0741
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0743 | nop word [cs:rax+rax+0x0]
loc_0750:
    lea rcx,[rsi-0x1]                                          ; 0750
    imul rcx,r13                                               ; 0754
    add rcx,[rsp+0x2e8]                                        ; 0758
    movsd xmm1,qword [rcx+r8*8-0x8]                            ; 0760
    ucomisd xmm1,xmm8                                          ; 0767
    seta r9b                                                   ; 076c
    movsd xmm0,qword [r10+rsi*8-0x8]                           ; 0770
    ucomisd xmm0,xmm8                                          ; 0777
    seta cl                                                    ; 077c
    cmp r8,rsi                                                 ; 077f
    jz short loc_0791                                           ; 0782
    test r9b,r9b                                               ; 0784
    jz short loc_0791                                           ; 0787
    test cl,cl                                                 ; 0789
    jnz near loc_06f0                                           ; 078b
loc_0791:
    ucomisd xmm1,xmm9                                          ; 0791
    ja near loc_06f0                                            ; 0796
    ucomisd xmm0,xmm9                                          ; 079c
    ja near loc_06f0                                            ; 07a1
    jmp near loc_06fb                                           ; 07a7
loc_07ac:
    mov [rsp+0x80],rcx                                         ; 07ac
    jmp short loc_07c0                                          ; 07b4
loc_07b6:
    mov r12,[rsp+0x90]                                         ; 07b6
    o16 nop                                                    ; 07be
loc_07c0:
    mov rcx,[rel $+7]                                          ; 07c0 | REL32 +3 SPAZSE$AZEO addendLE=00000000
    test cl,0x1                                                ; 07c7
    jnz short loc_07d6                                          ; 07ca
    cmp rax,0x2                                                ; 07cc
    jz near loc_0ed4                                            ; 07d0
loc_07d6:
    cmp rax,r14                                                ; 07d6
    jnz short loc_0800                                          ; 07d9
    mov rax,[rsp+0xe0]                                         ; 07db
    mov [rsi],rax                                              ; 07e3
    mov qword [rel $+7],0x0                                    ; 07e6 | REL32 +3 SPAZSE$INIT addendLE=fcffffff
    jmp short loc_080b                                          ; 07f1
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 07f3 | nop word [cs:rax+rax+0x0]
loc_0800:
    test cl,0x1                                                ; 0800
    jz short loc_080b                                           ; 0803
    inc rax                                                    ; 0805
    mov [rsi],rax                                              ; 0808
loc_080b:
    mov [rsp+0x88],r12                                         ; 080b
    mov rax,[rsp+0xf0]                                         ; 0813
    lea rax,[rax+r12*8]                                        ; 081b
    mov [rsp+0x90],rax                                         ; 081f
loc_0827:
    mov rax,[rsp+0xa0]                                         ; 0827
    cmp qword [rax],0x3                                        ; 082f
    lea r12,[rsp+0x108]                                        ; 0833
    jng near loc_09a2                                           ; 083b
    mov qword [rsp+0x108],0x0                                  ; 0841
    mov dword [rsp+0xc2],0x20438                               ; 084d
    mov qword [rsp+0x188],0x1d                                 ; 0858
    lea rax,[rel $+7]                                          ; 0864 | REL32 +3 strlit.6 addendLE=00000000
    mov [rsp+0x190],rax                                        ; 086b
    lea rax,[rsp+0x188]                                        ; 0873
    mov [rsp+0x20],rax                                         ; 087b
    mov rcx,r12                                                ; 0880
    xor edx,edx                                                ; 0883
    mov r8,0x801208384ff00                                     ; 0885
    lea r9,[rsp+0xc2]                                          ; 088f
    call $+5                                                   ; 0897 | REL32 +1 for_write_seq_lis addendLE=00000000
    mov rsi,[rsp+0x2a0]                                        ; 089c
    mov rax,[rsi]                                              ; 08a4
    mov dword [rsp+0xbe],0x2010b                               ; 08a7
    mov [rsp+0x100],rax                                        ; 08b2
    mov rcx,r12                                                ; 08ba
    lea rdx,[rsp+0xbe]                                         ; 08bd
    lea r8,[rsp+0x100]                                         ; 08c5
    call $+5                                                   ; 08cd | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    mov dword [rsp+0xba],0x10438                               ; 08d2
    mov qword [rsp+0x178],0x17                                 ; 08dd
    lea rax,[rel $+7]                                          ; 08e9 | REL32 +3 strlit.5 addendLE=00000000
    mov [rsp+0x180],rax                                        ; 08f0
    mov rcx,r12                                                ; 08f8
    lea rdx,[rsp+0xba]                                         ; 08fb
    lea r8,[rsp+0x178]                                         ; 0903
    call $+5                                                   ; 090b | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    mov rsi,[rsi]                                              ; 0910
    mov qword [rel $+7],0x1                                    ; 0913 | REL32 +3 SPAZSE$ICOMP addendLE=fcffffff
    cmp rsi,0x2                                                ; 091e
    jl near loc_09a2                                            ; 0922
    dec rsi                                                    ; 0928
    nop dword [byte rax+rax+0x0]                               ; 092b
loc_0930:
    mov qword [rsp+0x108],0x0                                  ; 0930
    mov dword [rsp+0xb6],0x10438                               ; 093c
    mov qword [rsp+0x168],0x8                                  ; 0947
    lea rax,[rel $+7]                                          ; 0953 | REL32 +3 SPAZSE$COMPID addendLE=00000000
    mov [rsp+0x170],rax                                        ; 095a
    lea rax,[rsp+0x168]                                        ; 0962
    mov [rsp+0x20],rax                                         ; 096a
    mov rcx,r12                                                ; 096f
    xor edx,edx                                                ; 0972
    mov r8,0x801208384ff00                                     ; 0974
    lea r9,[rsp+0xb6]                                          ; 097e
    call $+5                                                   ; 0986 | REL32 +1 for_write_seq_lis addendLE=00000000
    mov rax,[rel $+7]                                          ; 098b | REL32 +3 SPAZSE$ICOMP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 0992
    mov [rel $+7],rcx                                          ; 0996 | REL32 +3 SPAZSE$ICOMP addendLE=00000000
    cmp rax,rsi                                                ; 099d
    jl short loc_0930                                           ; 09a0
loc_09a2:
    mov qword [rel $+7],0x1                                    ; 09a2 | REL32 +3 SPAZSE$ICOMP addendLE=fcffffff
    test r14,r14                                               ; 09ad
    jng near loc_0e50                                           ; 09b0
    xor ecx,ecx                                                ; 09b6
    jmp short loc_09eb                                          ; 09b8
loc_09ba:
    mov qword [rel $+7],0x0                                    ; 09ba | REL32 +3 SPAZSE$INIT addendLE=fcffffff
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 09c5 | nop word [cs:rax+rax+0x0]
loc_09d0:
    mov rcx,[rel $+7]                                          ; 09d0 | REL32 +3 SPAZSE$ICOMP addendLE=00000000
    lea rax,[rcx+0x1]                                          ; 09d7
    mov [rel $+7],rax                                          ; 09db | REL32 +3 SPAZSE$ICOMP addendLE=00000000
    cmp rcx,r14                                                ; 09e2
    jnl near loc_0e50                                           ; 09e5
loc_09eb:
    mov rax,[rsp+0x2a0]                                        ; 09eb
    mov rax,[rax]                                              ; 09f3
    mov rcx,[rdi+rcx*8]                                        ; 09f6
    cmp rax,0x2                                                ; 09fa
    jl short loc_0a1e                                           ; 09fe
    lea rdx,[rax-0x1]                                          ; 0a00
    xor r8d,r8d                                                ; 0a04
    nop word [dword rax+rax+0x0]                               ; 0a07
loc_0a10:
    cmp rcx,[r15+r8*8]                                         ; 0a10
    jz short loc_09d0                                           ; 0a14
    inc r8                                                     ; 0a16
    cmp r8,rdx                                                 ; 0a19
    jl short loc_0a10                                           ; 0a1c
loc_0a1e:
    mov [r15+rax*8-0x8],rcx                                    ; 0a1e
    mov rax,[rsp+0xa0]                                         ; 0a23
    cmp qword [rax],0x4                                        ; 0a2b
    jl near loc_0b14                                            ; 0a2f
    mov qword [rsp+0x108],0x0                                  ; 0a35
    mov dword [rsp+0xb2],0x20438                               ; 0a41
    mov qword [rsp+0x158],0x19                                 ; 0a4c
    lea rax,[rel $+7]                                          ; 0a58 | REL32 +3 strlit.2 addendLE=00000000
    mov [rsp+0x160],rax                                        ; 0a5f
    lea rax,[rsp+0x158]                                        ; 0a67
    mov [rsp+0x20],rax                                         ; 0a6f
    lea rsi,[rsp+0x108]                                        ; 0a74
    mov rcx,rsi                                                ; 0a7c
    xor edx,edx                                                ; 0a7f
    mov r8,0x801208384ff00                                     ; 0a81
    lea r9,[rsp+0xb2]                                          ; 0a8b
    call $+5                                                   ; 0a93 | REL32 +1 for_write_seq_lis addendLE=00000000
    mov dword [rsp+0xae],0x20438                               ; 0a98
    mov qword [rsp+0x148],0x8                                  ; 0aa3
    lea rax,[rel $+7]                                          ; 0aaf | REL32 +3 SPAZSE$COMPID addendLE=00000000
    mov [rsp+0x150],rax                                        ; 0ab6
    mov rcx,rsi                                                ; 0abe
    lea rdx,[rsp+0xae]                                         ; 0ac1
    lea r8,[rsp+0x148]                                         ; 0ac9
    call $+5                                                   ; 0ad1 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    mov dword [rsp+0xaa],0x10438                               ; 0ad6
    mov qword [rsp+0x138],0x19                                 ; 0ae1
    lea rax,[rel $+7]                                          ; 0aed | REL32 +3 strlit.1 addendLE=00000000
    mov [rsp+0x140],rax                                        ; 0af4
    mov rcx,rsi                                                ; 0afc
    lea rdx,[rsp+0xaa]                                         ; 0aff
    lea r8,[rsp+0x138]                                         ; 0b07
    call $+5                                                   ; 0b0f | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
loc_0b14:
    cmp qword [rsp+0x80],0x0                                   ; 0b14
    jng near loc_0c20                                           ; 0b1d
    mov rax,[rsp+0x2a0]                                        ; 0b23
    mov rax,[rax]                                              ; 0b2b
    mov edx,0x1                                                ; 0b2e
    mov rcx,[rsp+0x2e0]                                        ; 0b33
    mov r12,[rsp+0x2e0]                                        ; 0b3b
loc_0b43:
    test rax,rax                                               ; 0b43
    jng short loc_0bb0                                          ; 0b46
    mov r8d,0x1                                                ; 0b48
    jmp short loc_0b5c                                          ; 0b4e
loc_0b50:
    lea r9,[r8+0x1]                                            ; 0b50
    cmp r8,rax                                                 ; 0b54
    mov r8,r9                                                  ; 0b57
    jz short loc_0bb0                                           ; 0b5a
loc_0b5c:
    mov r9,[r15+r8*8-0x8]                                      ; 0b5c
    mov r10,rcx                                                ; 0b61
    xor r11d,r11d                                              ; 0b64
    jmp short loc_0b7f                                          ; 0b67
    nop dword [dword rax+0x0]                                  ; 0b69
loc_0b70:
    inc r11                                                    ; 0b70
    add r10,0x1900                                             ; 0b73
    cmp r14,r11                                                ; 0b7a
    jz short loc_0b50                                           ; 0b7d
loc_0b7f:
    cmp r9,[rdi+r11*8]                                         ; 0b7f
    jnz short loc_0b70                                          ; 0b83
    cmp qword [r10],0x0                                        ; 0b85
    jnz short loc_0b70                                          ; 0b89
loc_0b8b:
    lea r8,[rdx+0x1]                                           ; 0b8b
    add rcx,0x8                                                ; 0b8f
    cmp rdx,[rsp+0x80]                                         ; 0b93
    mov rdx,r8                                                 ; 0b9b
    jl short loc_0b43                                           ; 0b9e
    jmp short loc_0c20                                          ; 0ba0
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0ba2 | nop word [cs:rax+rax+0x0]
loc_0bb0:
    mov r8d,0x1                                                ; 0bb0
    jmp short loc_0bd0                                          ; 0bb6
    nop dword [dword rax+rax+0x0]                              ; 0bb8
loc_0bc0:
    lea r9,[r8+0x1]                                            ; 0bc0
    cmp r8,r14                                                 ; 0bc4
    mov r8,r9                                                  ; 0bc7
    jz near loc_09d0                                            ; 0bca
loc_0bd0:
    imul r9,r8,0x1900                                          ; 0bd0
    add r9,r12                                                 ; 0bd7
    cmp qword [r9+rdx*8-0x1908],0x0                            ; 0bda
    jng short loc_0bc0                                          ; 0be3
    test rax,rax                                               ; 0be5
    jng short loc_0b8b                                          ; 0be8
    mov r9,[rdi+r8*8-0x8]                                      ; 0bea
    xor r10d,r10d                                              ; 0bef
    xor r11d,r11d                                              ; 0bf2
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0bf5 | nop word [cs:rax+rax+0x0]
loc_0c00:
    cmp [r15+r10*8],r9                                         ; 0c00
    setz sil                                                   ; 0c04
    or r11b,sil                                                ; 0c08
    inc r10                                                    ; 0c0b
    cmp rax,r10                                                ; 0c0e
    jnz short loc_0c00                                          ; 0c11
    test r11b,0x1                                              ; 0c13
    jnz short loc_0bc0                                          ; 0c17
    jmp near loc_0b8b                                           ; 0c19
    o16 nop                                                    ; 0c1e
loc_0c20:
    cmp qword [rsp+0x88],0x0                                   ; 0c20
    jng near loc_09ba                                           ; 0c29
    mov rax,[rsp+0x2a0]                                        ; 0c2f
    mov rax,[rax]                                              ; 0c37
    mov edx,0x1                                                ; 0c3a
    mov rcx,[rsp+0x2b8]                                        ; 0c3f
loc_0c47:
    test rax,rax                                               ; 0c47
    jng short loc_0cc0                                          ; 0c4a
    mov r8d,0x1                                                ; 0c4c
    jmp short loc_0c6c                                          ; 0c52
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0c54 | nop word [cs:rax+rax+0x0]
loc_0c60:
    lea r9,[r8+0x1]                                            ; 0c60
    cmp r8,rax                                                 ; 0c64
    mov r8,r9                                                  ; 0c67
    jz short loc_0cc0                                           ; 0c6a
loc_0c6c:
    mov r9,[r15+r8*8-0x8]                                      ; 0c6c
    mov r10,rcx                                                ; 0c71
    xor r11d,r11d                                              ; 0c74
    jmp short loc_0c8b                                          ; 0c77
    nop dword [dword rax+0x0]                                  ; 0c79
loc_0c80:
    inc r11                                                    ; 0c80
    add r10,rbp                                                ; 0c83
    cmp r14,r11                                                ; 0c86
    jz short loc_0c60                                           ; 0c89
loc_0c8b:
    cmp r9,[rdi+r11*8]                                         ; 0c8b
    jnz short loc_0c80                                          ; 0c8f
    ucomisd xmm6,qword [r10]                                   ; 0c91
    setpo sil                                                  ; 0c96
    setz r12b                                                  ; 0c9a
    test r12b,sil                                              ; 0c9e
    jz short loc_0c80                                           ; 0ca1
loc_0ca3:
    lea r8,[rdx+0x1]                                           ; 0ca3
    add rcx,0x8                                                ; 0ca7
    mov r9,[rsp+0x88]                                          ; 0cab
    cmp rdx,r9                                                 ; 0cb3
    mov rdx,r8                                                 ; 0cb6
    jl short loc_0c47                                           ; 0cb9
    jmp short loc_0d2e                                          ; 0cbb
    nop dword [rax]                                            ; 0cbd
loc_0cc0:
    mov r8d,0x1                                                ; 0cc0
    mov r12,[rsp+0x2b8]                                        ; 0cc6
    jmp short loc_0ce0                                          ; 0cce
loc_0cd0:
    lea r9,[r8+0x1]                                            ; 0cd0
    cmp r8,r14                                                 ; 0cd4
    mov r8,r9                                                  ; 0cd7
    jz near loc_09d0                                            ; 0cda
loc_0ce0:
    lea r9,[r8-0x1]                                            ; 0ce0
    imul r9,rbp                                                ; 0ce4
    add r9,r12                                                 ; 0ce8
    movsd xmm0,qword [r9+rdx*8-0x8]                            ; 0ceb
    ucomisd xmm0,xmm6                                          ; 0cf2
    jna short loc_0cd0                                          ; 0cf6
    test rax,rax                                               ; 0cf8
    jng short loc_0ca3                                          ; 0cfb
    mov r9,[rdi+r8*8-0x8]                                      ; 0cfd
    xor r10d,r10d                                              ; 0d02
    xor r11d,r11d                                              ; 0d05
    nop dword [dword rax+rax+0x0]                              ; 0d08
loc_0d10:
    cmp [r15+r10*8],r9                                         ; 0d10
    setz sil                                                   ; 0d14
    or r11b,sil                                                ; 0d18
    inc r10                                                    ; 0d1b
    cmp rax,r10                                                ; 0d1e
    jnz short loc_0d10                                          ; 0d21
    test r11b,0x1                                              ; 0d23
    jnz short loc_0cd0                                          ; 0d27
    jmp near loc_0ca3                                           ; 0d29
loc_0d2e:
    mov qword [rel $+7],0x0                                    ; 0d2e | REL32 +3 SPAZSE$INIT addendLE=fcffffff
    mov rcx,[rsp+0x90]                                         ; 0d39
    mov rdx,r9                                                 ; 0d41
    jmp short loc_0d65                                          ; 0d44
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 0d46 | nop word [cs:rax+rax+0x0]
loc_0d50:
    lea r8,[rdx-0x1]                                           ; 0d50
    add rcx,0xfffffffffffffff8                                 ; 0d54
    cmp rdx,0x1                                                ; 0d58
    mov rdx,r8                                                 ; 0d5c
    jng near loc_09d0                                           ; 0d5f
loc_0d65:
    cmp rax,0x2                                                ; 0d65
    jnl short loc_0de0                                          ; 0d69
loc_0d6b:
    mov r8d,0x1                                                ; 0d6b
    mov r12,[rsp+0x2b8]                                        ; 0d71
    jmp short loc_0d90                                          ; 0d79
    nop dword [byte rax+rax+0x0]                               ; 0d7b
loc_0d80:
    lea r9,[r8+0x1]                                            ; 0d80
    cmp r8,r14                                                 ; 0d84
    mov r8,r9                                                  ; 0d87
    jz near loc_0130                                            ; 0d8a
loc_0d90:
    lea r9,[r8-0x1]                                            ; 0d90
    imul r9,rbp                                                ; 0d94
    add r9,r12                                                 ; 0d98
    movsd xmm0,qword [r9+rdx*8-0x8]                            ; 0d9b
    ucomisd xmm0,xmm6                                          ; 0da2
    jna short loc_0d80                                          ; 0da6
    test rax,rax                                               ; 0da8
    jng short loc_0d50                                          ; 0dab
    mov r9,[rdi+r8*8-0x8]                                      ; 0dad
    xor r10d,r10d                                              ; 0db2
    xor r11d,r11d                                              ; 0db5
    nop dword [dword rax+rax+0x0]                              ; 0db8
loc_0dc0:
    cmp [r15+r10*8],r9                                         ; 0dc0
    setz sil                                                   ; 0dc4
    or r11b,sil                                                ; 0dc8
    inc r10                                                    ; 0dcb
    cmp rax,r10                                                ; 0dce
    jnz short loc_0dc0                                          ; 0dd1
    test r11b,0x1                                              ; 0dd3
    jnz short loc_0d80                                          ; 0dd7
    jmp near loc_0d50                                           ; 0dd9
    o16 nop                                                    ; 0dde
loc_0de0:
    mov r8d,0x1                                                ; 0de0
    jmp short loc_0dfc                                          ; 0de6
    nop dword [dword rax+rax+0x0]                              ; 0de8
loc_0df0:
    inc r8                                                     ; 0df0
    cmp r8,rax                                                 ; 0df3
    jz near loc_0d6b                                            ; 0df6
loc_0dfc:
    mov r9,[r15+r8*8-0x8]                                      ; 0dfc
    mov r10,rcx                                                ; 0e01
    xor r11d,r11d                                              ; 0e04
    jmp short loc_0e1b                                          ; 0e07
    nop dword [dword rax+0x0]                                  ; 0e09
loc_0e10:
    inc r11                                                    ; 0e10
    add r10,rbp                                                ; 0e13
    cmp r14,r11                                                ; 0e16
    jz short loc_0df0                                           ; 0e19
loc_0e1b:
    cmp r9,[rdi+r11*8]                                         ; 0e1b
    jnz short loc_0e10                                          ; 0e1f
    movsd xmm0,qword [r10]                                     ; 0e21
    ucomisd xmm6,xmm0                                          ; 0e26
    setpo sil                                                  ; 0e2a
    setz r12b                                                  ; 0e2e
    test r12b,sil                                              ; 0e32
    jnz near loc_0d50                                           ; 0e35
    lea rsi,[rel $+7]                                          ; 0e3b | REL32 +3 SPAZSE$XNAZEO addendLE=00000000
    movsd qword [rsi+r8*8-0x8],xmm0                            ; 0e42
    jmp short loc_0e10                                          ; 0e49
    nop dword [byte rax+rax+0x0]                               ; 0e4b
loc_0e50:
    mov rcx,[rsp+0x2a0]                                        ; 0e50
    mov rax,[rcx]                                              ; 0e58
    cmp rax,0x4                                                ; 0e5b
    jl short loc_0ed4                                           ; 0e5f
    dec rax                                                    ; 0e61
    mov [rcx],rax                                              ; 0e64
    jmp near loc_0827                                           ; 0e67
loc_0e6c:
    mov rax,[rsp+0x98]                                         ; 0e6c
    mov qword [rax],0x1                                        ; 0e74
    mov qword [rsp+0x108],0x0                                  ; 0e7b
    mov dword [rsp+0xd4],0x10438                               ; 0e87
    mov qword [rsp+0x1b8],0x36                                 ; 0e92
    lea rax,[rel $+7]                                          ; 0e9e | REL32 +3 strlit.13 addendLE=00000000
    mov [rsp+0x1c0],rax                                        ; 0ea5
    lea rax,[rsp+0x1b8]                                        ; 0ead
    mov [rsp+0x20],rax                                         ; 0eb5
    lea rcx,[rsp+0x108]                                        ; 0eba
    lea r9,[rsp+0xd4]                                          ; 0ec2
loc_0eca:
    xor edx,edx                                                ; 0eca
    mov r8,r10                                                 ; 0ecc
    call $+5                                                   ; 0ecf | REL32 +1 for_write_seq_lis addendLE=00000000
loc_0ed4:
    movaps xmm6,oword [rsp+0x1e0]                              ; 0ed4
    movaps xmm7,oword [rsp+0x1f0]                              ; 0edc
    movaps xmm8,oword [rsp+0x200]                              ; 0ee4
    movaps xmm9,oword [rsp+0x210]                              ; 0eed
    add rsp,0x228                                              ; 0ef6
    pop rbx                                                    ; 0efd
    pop rbp                                                    ; 0efe
    pop rdi                                                    ; 0eff
    pop rsi                                                    ; 0f00
    pop r12                                                    ; 0f01
    pop r13                                                    ; 0f03
    pop r14                                                    ; 0f05
    pop r15                                                    ; 0f07
    retq                                                       ; 0f09
loc_0f0a:
    mov rax,[rsp+0x98]                                         ; 0f0a
    mov qword [rax],0x1                                        ; 0f12
    mov qword [rsp+0x108],0x0                                  ; 0f19
    mov dword [rsp+0xd0],0x10438                               ; 0f25
    mov qword [rsp+0x1a8],0x36                                 ; 0f30
    lea rax,[rel $+7]                                          ; 0f3c | REL32 +3 strlit.13 addendLE=00000000
    mov [rsp+0x1b0],rax                                        ; 0f43
    lea rax,[rsp+0x1a8]                                        ; 0f4b
    mov [rsp+0x20],rax                                         ; 0f53
    lea rcx,[rsp+0x108]                                        ; 0f58
    lea r9,[rsp+0xd0]                                          ; 0f60
    jmp near loc_0eca                                           ; 0f68

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x36,0x00,0x00,0x00,0x1c,0x00,0x14,0x00,0x46,0x6f,0x75,0x6e,0x64,0x20,0x61,0x7a
    db 0x65,0x6f,0x74,0x72,0x6f,0x70,0x65,0x20,0x4e,0x6f,0x2e,0x20,0x24,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1d,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x37,0x00,0x00,0x00

; .rdata (COFF section 4)
coff_section_4:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x40

; .rdata (COFF section 5)
coff_section_5:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x40

; .rdata (COFF section 6)
coff_section_6:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .xdata (COFF section 7)
coff_section_7:
    db 0x01,0x39,0x12,0x00,0x39,0x68,0x1e,0x00,0x30,0x78,0x1f,0x00,0x27,0x88,0x20,0x00
    db 0x1d,0x98,0x21,0x00,0x13,0x01,0x45,0x00,0x0c,0x30,0x0b,0x50,0x0a,0x70,0x09,0x60
    db 0x08,0xc0,0x06,0xd0,0x04,0xe0,0x02,0xf0

; .rdata (COFF section 8)
coff_section_8:
    db 0x20,0x68,0x61,0x73,0x20,0x62,0x65,0x65,0x6e,0x20,0x65,0x78,0x61,0x6d,0x69,0x6e
    db 0x65,0x64,0x20,0x62,0x65,0x66,0x6f,0x72,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x43,0x68,0x65,0x63,0x6b,0x69,0x6e,0x67,0x20,0x69,0x66,0x20,0x6d,0x69,0x78,0x74
    db 0x75,0x72,0x65,0x20,0x77,0x69,0x74,0x68,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x20,0x63,0x6f,0x6d,0x70,0x6f,0x6e,0x65,0x6e,0x74,0x73,0x20,0x63,0x6f,0x6e,0x74
    db 0x61,0x69,0x6e,0x69,0x6e,0x67,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x53,0x65,0x61,0x72,0x63,0x68,0x69,0x6e,0x67,0x20,0x6e,0x65,0x77,0x20,0x63,0x6f
    db 0x6d,0x62,0x69,0x6e,0x61,0x74,0x69,0x6f,0x6e,0x20,0x6f,0x66,0x20,0x00,0x00,0x00
    db 0x53,0x45,0x41,0x52,0x43,0x48,0x20,0x46,0x4f,0x52,0x20,0x41,0x5a,0x45,0x4f,0x54
    db 0x52,0x4f,0x50,0x45,0x53,0x20,0x54,0x45,0x52,0x4d,0x49,0x4e,0x41,0x54,0x45,0x44
    db 0x20,0x44,0x55,0x45,0x20,0x54,0x4f,0x20,0x53,0x54,0x41,0x43,0x4b,0x20,0x4f,0x56
    db 0x45,0x52,0x46,0x4c,0x4f,0x57

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
    dd 0x00000f6d ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 15)
