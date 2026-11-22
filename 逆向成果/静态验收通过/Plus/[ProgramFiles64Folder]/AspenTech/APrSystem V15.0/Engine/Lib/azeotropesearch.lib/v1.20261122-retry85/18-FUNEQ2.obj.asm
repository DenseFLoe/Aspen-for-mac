; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ2:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbp                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x1e8                                              ; 000c
    movapd oword [rsp+0x1d0],xmm9                              ; 0013
    movapd oword [rsp+0x1c0],xmm8                              ; 001d
    movapd oword [rsp+0x1b0],xmm7                              ; 0027
    movapd oword [rsp+0x1a0],xmm6                              ; 0030
    mov rbx,r8                                                 ; 0039
    mov r10,rdx                                                ; 003c
    mov r12,rcx                                                ; 003f
    mov r14,[rsp+0x2a0]                                        ; 0042
    mov rdi,[rsp+0x298]                                        ; 004a
    mov rax,[rsp+0x290]                                        ; 0052
    mov rdx,[rsp+0x278]                                        ; 005a
    mov rsi,[rsp+0x268]                                        ; 0062
    mov rax,[rax]                                              ; 006a
    shl rax,byte 0x3                                           ; 006d
    mov [rsp+0xf0],rax                                         ; 0071
    mov r15,[rdi+0x18]                                         ; 0079
    mov [rel $+7],r15                                          ; 007d | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    mov qword [rel $+7],0x0                                    ; 0084 | REL32 +3 FUNEQ2$LPRINT addendLE=fcffffff
    cmp qword [rcx],0x0                                        ; 008f
    mov r13,[rsp+0x258]                                        ; 0093
    mov r11,[rsp+0x250]                                        ; 009b
    mov [rsp+0x68],r9                                          ; 00a3
    mov [rsp+0x60],r10                                         ; 00a8
    js near loc_0356                                            ; 00ad
loc_00b3:
    mov [rsp+0x70],r12                                         ; 00b3
    mov rax,[rdi]                                              ; 00b8
    lea rcx,[rax-0x3]                                          ; 00bb
    cmp rcx,0xfffffffffffffffd                                 ; 00bf
    ja short loc_00ce                                           ; 00c3
    mov qword [rdi],0x0                                        ; 00c5
    xor eax,eax                                                ; 00cc
loc_00ce:
    mov r12,[rdi+0x8]                                          ; 00ce
    cmp r12,0x2                                                ; 00d2
    jnc near loc_038b                                           ; 00d6
    cmp qword [rdi+0x10],0x1                                   ; 00dc
    jnz near loc_03a4                                           ; 00e1
loc_00e7:
    cmp r15,0xb                                                ; 00e7
    jl short loc_00fb                                           ; 00eb
loc_00ed:
    mov qword [rdi+0x18],0x3                                   ; 00ed
    mov r15d,0x3                                               ; 00f5
loc_00fb:
    mov r8,[rdi+0x20]                                          ; 00fb
    lea rcx,[r8-0x64]                                          ; 00ff
    cmp rcx,0xffffffffffffff9d                                 ; 0103
    jc short loc_010f                                           ; 0107
    cmp r8,0x6                                                 ; 0109
    jnz short loc_011a                                          ; 010d
loc_010f:
    mov qword [rdi+0x20],0x0                                   ; 010f
    xor r8d,r8d                                                ; 0117
loc_011a:
    mov rcx,0xfffffffffffffc18                                 ; 011a
    mov rdx,[rdi+0x28]                                         ; 0121
    add rdx,rcx                                                ; 0125
    cmp rdx,0xfffffffffffffc18                                 ; 0128
    ja short loc_0139                                           ; 012f
    mov qword [rdi+0x28],0x32                                  ; 0131
loc_0139:
    add rcx,[rdi+0x30]                                         ; 0139
    cmp rcx,0xfffffffffffffc18                                 ; 013d
    ja short loc_014e                                           ; 0144
    mov qword [rdi+0x30],0x5                                   ; 0146
loc_014e:
    mov r9,[rdi+0x38]                                          ; 014e
    cmp r9,0x1                                                 ; 0152
    jz short loc_0160                                           ; 0156
    mov qword [rdi+0x38],0x0                                   ; 0158
loc_0160:
    mov rcx,[rdi+0x40]                                         ; 0160
    cmp rcx,0x1                                                ; 0164
    jz short loc_0172                                           ; 0168
    mov qword [rdi+0x40],0x0                                   ; 016a
loc_0172:
    cmp qword [rdi+0x48],0x1                                   ; 0172
    jz short loc_0181                                           ; 0177
    mov qword [rdi+0x48],0x2                                   ; 0179
loc_0181:
    movsd xmm3,qword [r14]                                     ; 0181
    xorpd xmm2,xmm2                                            ; 0186
    ucomisd xmm2,xmm3                                          ; 018a
    movsd xmm1,qword [rel $+8]                                 ; 018e | REL32 +4 __real@3f1a36e2eb1c432d addendLE=00000000
    movapd xmm4,xmm1                                           ; 0196
    jnc short loc_01a0                                          ; 019a
    movapd xmm4,xmm3                                           ; 019c
loc_01a0:
    movsd xmm0,qword [r14+0x8]                                 ; 01a0
    ucomisd xmm3,qword [rel $+8]                               ; 01a6 | REL32 +4 __real@3fe0000000000000 addendLE=00000000
    ja short loc_01b4                                           ; 01ae
    movapd xmm1,xmm4                                           ; 01b0
loc_01b4:
    ucomisd xmm2,xmm0                                          ; 01b4
    setnc dl                                                   ; 01b8
    ucomisd xmm0,qword [rel $+8]                               ; 01bb | REL32 +4 __real@3f50624dd2f1a9fc addendLE=00000000
    ja short loc_01c9                                           ; 01c3
    test dl,dl                                                 ; 01c5
    jz short loc_01ff                                           ; 01c7
loc_01c9:
    movsd xmm2,qword [rel $+8]                                 ; 01c9 | REL32 +4 __real@4008000000000000 addendLE=00000000
    movsd xmm0,qword [rel $+8]                                 ; 01d1 | REL32 +4 __real@4010000000000000 addendLE=00000000
    divsd xmm0,xmm2                                            ; 01d9
    movsd xmm3,qword [rel $+8]                                 ; 01dd | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    subsd xmm0,xmm3                                            ; 01e5
    mulsd xmm0,xmm2                                            ; 01e9
    subsd xmm0,xmm3                                            ; 01ed
    andpd xmm0,[rel $+8]                                       ; 01f1 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    movlpd qword [r14+0x8],xmm0                                ; 01f9
loc_01ff:
    minsd xmm1,[rel $+8]                                       ; 01ff | REL32 +4 __real@3fb999999999999a addendLE=00000000
    maxsd xmm1,xmm0                                            ; 0207
    movsd qword [r14],xmm1                                     ; 020b
    movsd xmm2,qword [r14+0x10]                                ; 0210
    ucomisd xmm2,qword [rel $+8]                               ; 0216 | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    jna short loc_0228                                          ; 021e
    mov qword [r14+0x10],0x0                                   ; 0220
loc_0228:
    movsd xmm2,qword [r14+0x18]                                ; 0228
    movsd xmm3,qword [rel $+8]                                 ; 022e | REL32 +4 __real@3ee4f8b588e368f1 addendLE=00000000
    ucomisd xmm3,xmm2                                          ; 0236
    setnc dl                                                   ; 023a
    ucomisd xmm2,qword [rel $+8]                               ; 023d | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    ja short loc_024b                                           ; 0245
    test dl,dl                                                 ; 0247
    jz short loc_0259                                           ; 0249
loc_024b:
    mov rdx,0x3ff0000000000000                                 ; 024b
    mov [r14+0x18],rdx                                         ; 0255
loc_0259:
    movsd xmm2,qword [r14+0x20]                                ; 0259
    xorpd xmm3,xmm3                                            ; 025f
    ucomisd xmm3,xmm2                                          ; 0263
    setnc dl                                                   ; 0267
    ucomisd xmm2,qword [rel $+8]                               ; 026a | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    ja short loc_0278                                           ; 0272
    test dl,dl                                                 ; 0274
    jz short loc_027e                                           ; 0276
loc_0278:
    movsd qword [r14+0x20],xmm1                                ; 0278
loc_027e:
    movsd xmm1,qword [r14+0x28]                                ; 027e
    ucomisd xmm1,qword [rel $+8]                               ; 0284 | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    jna short loc_02a3                                          ; 028c
    xorps xmm1,xmm1                                            ; 028e
    sqrtsd xmm1,xmm0                                           ; 0291
    mulsd xmm1,qword [rel $+8]                                 ; 0295 | REL32 +4 __real@4024000000000000 addendLE=00000000
    movsd qword [r14+0x28],xmm1                                ; 029d
loc_02a3:
    movsd xmm1,qword [r14+0x30]                                ; 02a3
    ucomisd xmm1,qword [rel $+8]                               ; 02a9 | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    jna short loc_02bd                                          ; 02b1
    sqrtsd xmm0,xmm0                                           ; 02b3
    movsd qword [r14+0x30],xmm0                                ; 02b7
loc_02bd:
    mov [rel $+7],r15                                          ; 02bd | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    mov [rel $+7],r8                                           ; 02c4 | REL32 +3 FUNEQ2$LPRINT addendLE=00000000
    mov rbp,[r10]                                              ; 02cb
    test rbp,rbp                                               ; 02ce
    mov [rsp+0xe8],r8                                          ; 02d1
    mov [rsp+0xf8],r9                                          ; 02d9
    jng near loc_03bb                                           ; 02e1
    cmp r9,0x1                                                 ; 02e7
    jnz near loc_04a3                                           ; 02eb
    cmp rcx,0x1                                                ; 02f1
    jnz near loc_057f                                           ; 02f5
    cmp rbp,0xd                                                ; 02fb
    jc near loc_0c3c                                            ; 02ff
    lea r8,[rbp*8+0x0]                                         ; 0305
    xor r12d,r12d                                              ; 030d
    mov rcx,rsi                                                ; 0310
    xor edx,edx                                                ; 0313
    call $+5                                                   ; 0315 | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 031a
    xorpd xmm0,xmm0                                            ; 0322
    movapd xmm1,oword [rel $+8]                                ; 0326 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xor eax,eax                                                ; 032e
loc_0330:
    movsd xmm2,qword [rbx+r12*8]                               ; 0330
    xor ecx,ecx                                                ; 0336
    ucomisd xmm0,xmm2                                          ; 0338
    seta cl                                                    ; 033c
    add rax,rcx                                                ; 033f
    andpd xmm2,xmm1                                            ; 0342
    movlpd qword [rbx+r12*8],xmm2                              ; 0346
    inc r12                                                    ; 034c
    cmp rbp,r12                                                ; 034f
    jnz short loc_0330                                          ; 0352
    jmp short loc_03bd                                          ; 0354
loc_0356:
    mov eax,[rdi+0x78]                                         ; 0356
    dec eax                                                    ; 0359
    cmp eax,0x3                                                ; 035b
    ja near loc_00b3                                            ; 035e
    mov rbp,r9                                                 ; 0364
; The linker fixes RCX to section 27. Four signed table offsets are relative to its start.
    lea rcx,[rel $+7]                                          ; 0367 | REL32 +3 .rdata addendLE=00000000
    movsxd rax,dword [rcx+rax*4]                               ; 036e
    add rax,rcx                                                ; 0372
    jmp rax                                                    ; 0375
loc_0377:
    movsd xmm0,qword [rbp+0x0]                                 ; 0377
    xor eax,eax                                                ; 037c
    mov [rsp+0xe8],rax                                         ; 037e
    jmp near loc_041b                                           ; 0386
loc_038b:
    mov qword [rdi+0x8],0x2                                    ; 038b
    mov r12d,0x2                                               ; 0393
    cmp qword [rdi+0x10],0x1                                   ; 0399
    jz near loc_00e7                                            ; 039e
loc_03a4:
    mov qword [rdi+0x10],0x2                                   ; 03a4
    cmp r15,0xb                                                ; 03ac
    jnl near loc_00ed                                           ; 03b0
    jmp near loc_00fb                                           ; 03b6
loc_03bb:
    xor eax,eax                                                ; 03bb
loc_03bd:
    cmp qword [rsp+0xf8],0x1                                   ; 03bd
    setz cl                                                    ; 03c6
    xorpd xmm0,xmm0                                            ; 03c9
    movupd oword [rdi+0x80],xmm0                               ; 03cd
    mov qword [rdi+0xa8],0x0                                   ; 03d5
    mov r12,[rsp+0x70]                                         ; 03e0
    mov qword [r12],0xffffffffffffffff                         ; 03e5
    mov qword [rdi+0x78],0x1                                   ; 03ed
    mov rbp,[rsp+0x68]                                         ; 03f5
    movsd xmm0,qword [rbp+0x0]                                 ; 03fa
    test rax,rax                                               ; 03ff
    setg al                                                    ; 0402
    ucomisd xmm0,qword [rel $+8]                               ; 0405 | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    jnc near loc_2420                                           ; 040d
    and al,cl                                                  ; 0413
    jnz near loc_2420                                           ; 0415
loc_041b:
    ucomisd xmm0,qword [rel $+8]                               ; 041b | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    jc near loc_04fb                                            ; 0423
    mov qword [r12],0x8                                        ; 0429
    mov r12d,0x8                                               ; 0431
    cmp r15,0x2                                                ; 0437
    mov r10,[rsp+0x60]                                         ; 043b
    jng near loc_1e2b                                           ; 0440
    mov qword [rsp+0x88],0x0                                   ; 0446
    mov word [rsp+0x80],0x1                                    ; 0452
    lea rax,[rel $+371]                                        ; 045c | REL32 +3 FUNEQ2$format_pack addendLE=6c010000
    mov [rsp+0x28],rax                                         ; 0463
    mov qword [rsp+0x20],0x0                                   ; 0468
    lea rcx,[rsp+0x88]                                         ; 0471
    mov r8,0x801208384ff00                                     ; 0479
    lea r9,[rsp+0x80]                                          ; 0483
    mov rdx,[rsp+0xe8]                                         ; 048b
    mov r15,r10                                                ; 0493
    call $+5                                                   ; 0496 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,r15                                                ; 049b
    jmp near loc_1e2b                                           ; 049e
loc_04a3:
    cmp rcx,0x1                                                ; 04a3
    jnz near loc_066a                                           ; 04a7
    cmp rbp,0xd                                                ; 04ad
    jc near loc_0c7f                                            ; 04b1
    lea r8,[rbp*8+0x0]                                         ; 04b7
    xor r12d,r12d                                              ; 04bf
    mov rcx,rsi                                                ; 04c2
    xor edx,edx                                                ; 04c5
    call $+5                                                   ; 04c7 | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 04cc
    xorpd xmm0,xmm0                                            ; 04d4
    xor eax,eax                                                ; 04d8
    nop word [byte rax+rax+0x0]                                ; 04da
loc_04e0:
    xor ecx,ecx                                                ; 04e0
    ucomisd xmm0,qword [rbx+r12*8]                             ; 04e2
    seta cl                                                    ; 04e8
    add rax,rcx                                                ; 04eb
    inc r12                                                    ; 04ee
    cmp rbp,r12                                                ; 04f1
    jnz short loc_04e0                                          ; 04f4
    jmp near loc_03bd                                           ; 04f6
loc_04fb:
    mov r10,[rsp+0x60]                                         ; 04fb
    mov r15,[r10]                                              ; 0500
    test r15,r15                                               ; 0503
    mov rdx,[rsp+0x278]                                        ; 0506
    mov r9,[rsp+0x280]                                         ; 050e
    jng near loc_0b9e                                           ; 0516
    cmp r15,0xd                                                ; 051c
    jc near loc_0b78                                            ; 0520
    mov [rsp+0x70],r12                                         ; 0526
    mov r12,rbp                                                ; 052b
    lea rbp,[r15*8+0x0]                                        ; 052e
    mov rcx,rdx                                                ; 0536
    mov rdx,rbx                                                ; 0539
    mov r8,rbp                                                 ; 053c
    mov r13,r10                                                ; 053f
    call $+5                                                   ; 0542 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov rcx,[rsp+0x280]                                        ; 0547
    mov rdx,r12                                                ; 054f
    mov r12,[rsp+0x70]                                         ; 0552
    mov r8,rbp                                                 ; 0557
    call $+5                                                   ; 055a | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r10,r13                                                ; 055f
    mov r11,[rsp+0x250]                                        ; 0562
    mov r9,[rsp+0x280]                                         ; 056a
    mov rdx,[rsp+0x278]                                        ; 0572
    jmp near loc_0b9e                                           ; 057a
loc_057f:
    cmp rax,0x1                                                ; 057f
    jnz near loc_0cb2                                           ; 0583
    cmp rbp,0xd                                                ; 0589
    jc near loc_0f1b                                            ; 058d
    lea r8,[rbp*8+0x0]                                         ; 0593
    xor r13d,r13d                                              ; 059b
    mov rcx,rsi                                                ; 059e
    xor edx,edx                                                ; 05a1
    call $+5                                                   ; 05a3 | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 05a8
    xorpd xmm0,xmm0                                            ; 05b0
    movapd xmm1,oword [rel $+8]                                ; 05b4 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    mov rcx,0x3ff0000000000000                                 ; 05bc
    movsd xmm2,qword [rel $+8]                                 ; 05c6 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 05ce
    jmp short loc_05f2                                          ; 05d0
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 05d2 | nop word [cs:rax+rax+0x0]
loc_05e0:
    mov dl,r8b                                                 ; 05e0
    add rax,rdx                                                ; 05e3
    inc r13                                                    ; 05e6
    cmp rbp,r13                                                ; 05e9
    jz near loc_03bd                                            ; 05ec
loc_05f2:
    movsd xmm3,qword [rbx+r13*8]                               ; 05f2
    xor edx,edx                                                ; 05f8
    ucomisd xmm0,xmm3                                          ; 05fa
    seta r8b                                                   ; 05fe
    andpd xmm3,xmm1                                            ; 0602
    ucomisd xmm0,qword [r11+r13*8]                             ; 0606
    movlpd qword [rbx+r13*8],xmm3                              ; 060c
    setpe r9b                                                  ; 0612
    setnz r10b                                                 ; 0616
    or r10b,r9b                                                ; 061a
    jnz short loc_0623                                          ; 061d
    mov [r11+r13*8],rcx                                        ; 061f
loc_0623:
    mov r9,[rsp+0x258]                                         ; 0623
    cmp r12,0x1                                                ; 062b
    jnz short loc_0640                                          ; 062f
    movsd xmm3,qword [r9+r13*8]                                ; 0631
    jmp short loc_0648                                          ; 0637
    nop dword [dword rax+0x0]                                  ; 0639
loc_0640:
    mov [r9+r13*8],rcx                                         ; 0640
    movapd xmm3,xmm2                                           ; 0644
loc_0648:
    ucomisd xmm3,xmm0                                          ; 0648
    setpe r9b                                                  ; 064c
    setnz r10b                                                 ; 0650
    or r10b,r9b                                                ; 0654
    jnz short loc_05e0                                          ; 0657
    mov r9,[rsp+0x258]                                         ; 0659
    mov [r9+r13*8],rcx                                         ; 0661
    jmp near loc_05e0                                           ; 0665
loc_066a:
    cmp rax,0x1                                                ; 066a
    jnz near loc_0d77                                           ; 066e
    cmp rbp,0xd                                                ; 0674
    jc near loc_0fe8                                            ; 0678
    lea r8,[rbp*8+0x0]                                         ; 067e
    xor r13d,r13d                                              ; 0686
    mov rcx,rsi                                                ; 0689
    xor edx,edx                                                ; 068c
    call $+5                                                   ; 068e | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 0693
    xorpd xmm0,xmm0                                            ; 069b
    mov rcx,0x3ff0000000000000                                 ; 069f
    movsd xmm1,qword [rel $+8]                                 ; 06a9 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 06b1
    jmp short loc_06d2                                          ; 06b3
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 06b5 | nop word [cs:rax+rax+0x0]
loc_06c0:
    mov dl,r8b                                                 ; 06c0
    add rax,rdx                                                ; 06c3
    inc r13                                                    ; 06c6
    cmp rbp,r13                                                ; 06c9
    jz near loc_03bd                                            ; 06cc
loc_06d2:
    xor edx,edx                                                ; 06d2
    ucomisd xmm0,qword [rbx+r13*8]                             ; 06d4
    seta r8b                                                   ; 06da
    ucomisd xmm0,qword [r11+r13*8]                             ; 06de
    setpe r9b                                                  ; 06e4
    setnz r10b                                                 ; 06e8
    or r10b,r9b                                                ; 06ec
    jnz short loc_06f5                                          ; 06ef
    mov [r11+r13*8],rcx                                        ; 06f1
loc_06f5:
    mov r9,[rsp+0x258]                                         ; 06f5
    cmp r12,0x1                                                ; 06fd
    jnz short loc_0710                                          ; 0701
    movsd xmm2,qword [r9+r13*8]                                ; 0703
    jmp short loc_0718                                          ; 0709
    nop dword [byte rax+rax+0x0]                               ; 070b
loc_0710:
    mov [r9+r13*8],rcx                                         ; 0710
    movapd xmm2,xmm1                                           ; 0714
loc_0718:
    ucomisd xmm2,xmm0                                          ; 0718
    setpe r9b                                                  ; 071c
    setnz r10b                                                 ; 0720
    or r10b,r9b                                                ; 0724
    jnz short loc_06c0                                          ; 0727
    mov r9,[rsp+0x258]                                         ; 0729
    mov [r9+r13*8],rcx                                         ; 0731
    jmp short loc_06c0                                          ; 0735
loc_0737:
    mov r15,[r10]                                              ; 0737
    jmp near loc_1396                                           ; 073a
loc_073f:
    movsd xmm0,qword [rel $+8]                                 ; 073f | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    ucomisd xmm0,qword [rbp+0x0]                               ; 0747
    jna near loc_0e27                                           ; 074c
    mov rax,[r10]                                              ; 0752
    test rax,rax                                               ; 0755
    jng short loc_077d                                          ; 0758
    xor ecx,ecx                                                ; 075a
    nop dword [byte rax+0x0]                                   ; 075c
loc_0760:
    movsd xmm0,qword [rbx+rcx*8]                               ; 0760
    subsd xmm0,qword [rdx+rcx*8]                               ; 0765
    divsd xmm0,[r11+rcx*8]                                     ; 076a
    movsd qword [rsi+rcx*8],xmm0                               ; 0770
    inc rcx                                                    ; 0775
    cmp rcx,rax                                                ; 0778
    jl short loc_0760                                           ; 077b
loc_077d:
    mov rcx,r10                                                ; 077d
    mov rdx,rsi                                                ; 0780
    call $+5                                                   ; 0783 | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 0788 | REL32 +4 FUNEQ2$STEP addendLE=00000000
    mov qword [rdi+0xb0],0x0                                   ; 0790
    movsd xmm1,qword [r14+0x20]                                ; 079b
    mulsd xmm1,qword [r14+0x88]                                ; 07a1
    ucomisd xmm1,xmm0                                          ; 07aa
    jc short loc_07bb                                           ; 07ae
    mov qword [rdi+0xb0],0x1                                   ; 07b0
loc_07bb:
    mov rax,[rsp+0x270]                                        ; 07bb
    mov [rsp+0x30],rax                                         ; 07c3
    mov [rsp+0x28],rsi                                         ; 07c8
    mov rax,[rsp+0x290]                                        ; 07cd
    mov [rsp+0x20],rax                                         ; 07d5
    lea rcx,[rel $+7]                                          ; 07da | REL32 +3 __unnamed_1 addendLE=00000000
    mov r15,[rsp+0x60]                                         ; 07e1
    mov rdx,r15                                                ; 07e6
    mov r8,[rsp+0x260]                                         ; 07e9
    mov r9,[rsp+0x288]                                         ; 07f1
    call $+5                                                   ; 07f9 | REL32 +1 FUNEQ6 addendLE=00000000
    mov r8,[rsp+0x270]                                         ; 07fe
    movsd xmm0,qword [r14+0x50]                                ; 0806
    movsd qword [rel $+8],xmm0                                 ; 080c | REL32 +4 FUNEQ2$FNORM addendLE=00000000
    cmp qword [rdi+0x90],0x1                                   ; 0814
    mov rax,[r15]                                              ; 081c
    mov rdx,[rsp+0x280]                                        ; 081f
    jnz short loc_087f                                          ; 0827
    xorpd xmm1,xmm1                                            ; 0829
    test rax,rax                                               ; 082d
    jng short loc_0863                                          ; 0830
    xor r9d,r9d                                                ; 0832
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0835 | nop word [cs:rax+rax+0x0]
loc_0840:
    movsd xmm2,qword [rdx+r9*8]                                ; 0840
    divsd xmm2,[r13+r9*8+0x0]                                  ; 0846
    divsd xmm2,xmm0                                            ; 084d
    mulsd xmm2,qword [r8+r9*8]                                 ; 0851
    addsd xmm1,xmm2                                            ; 0857
    inc r9                                                     ; 085b
    cmp r9,rax                                                 ; 085e
    jl short loc_0840                                           ; 0861
loc_0863:
    mulsd xmm1,qword [rel $+8]                                 ; 0863 | REL32 +4 __real@4000000000000000 addendLE=00000000
    divsd xmm1,xmm0                                            ; 086b
    xorpd xmm1,oword [rel $+8]                                 ; 086f | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    movlpd qword [rel $+8],xmm1                                ; 0877 | REL32 +4 FUNEQ2$DERATE addendLE=00000000
loc_087f:
    test rax,rax                                               ; 087f
    jng short loc_08c6                                          ; 0882
    xor r9d,r9d                                                ; 0884
    nop word [dword rax+rax+0x0]                               ; 0887
loc_0890:
    movsd xmm0,qword [rbp+r9*8+0x0]                            ; 0890
    movsd xmm1,qword [r13+r9*8+0x0]                            ; 0897
    divsd xmm0,xmm1                                            ; 089e
    movsd xmm2,qword [rdx+r9*8]                                ; 08a2
    divsd xmm2,xmm1                                            ; 08a8
    addsd xmm2,[r8+r9*8]                                       ; 08ac
    movsd qword [rsi+r9*8],xmm0                                ; 08b2
    movsd qword [r8+r9*8],xmm2                                 ; 08b8
    inc r9                                                     ; 08be
    cmp r9,rax                                                 ; 08c1
    jl short loc_0890                                           ; 08c4
loc_08c6:
    mov rcx,r15                                                ; 08c6
    mov rdx,r8                                                 ; 08c9
    call $+5                                                   ; 08cc | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 08d1 | REL32 +4 FUNEQ2$FNORMP addendLE=00000000
    mov rcx,r15                                                ; 08d9
    mov rdx,rsi                                                ; 08dc
    call $+5                                                   ; 08df | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 08e4 | REL32 +4 FUNEQ2$FNORMN addendLE=00000000
    movsd xmm2,qword [rel $+8]                                 ; 08ec | REL32 +4 FUNEQ2$STEP addendLE=00000000
    xorpd xmm1,xmm1                                            ; 08f4
    ucomisd xmm2,xmm1                                          ; 08f8
    jna near loc_11e1                                           ; 08fc
    mov rax,[r15]                                              ; 0902
    movsd xmm0,qword [rel $+8]                                 ; 0905 | REL32 +4 FUNEQ2$FNORM addendLE=00000000
    test rax,rax                                               ; 090d
    mov r9,[rsp+0x278]                                         ; 0910
    mov r8,[rsp+0x250]                                         ; 0918
    mov rdx,[rsp+0x270]                                        ; 0920
    jng short loc_098e                                          ; 0928
    xor r10d,r10d                                              ; 092a
    movapd xmm3,oword [rel $+8]                                ; 092d | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0935 | nop word [cs:rax+rax+0x0]
loc_0940:
    movsd xmm4,qword [rsi+r10*8]                               ; 0940
    movapd xmm5,xmm4                                           ; 0946
    subsd xmm5,qword [rdx+r10*8]                               ; 094a
    divsd xmm4,xmm0                                            ; 0950
    mulsd xmm4,xmm5                                            ; 0954
    andpd xmm4,xmm3                                            ; 0958
    addsd xmm1,xmm4                                            ; 095c
    divsd xmm5,xmm2                                            ; 0960
    movsd qword [rdx+r10*8],xmm5                               ; 0964
    movsd xmm4,qword [rbx+r10*8]                               ; 096a
    subsd xmm4,qword [r9+r10*8]                                ; 0970
    divsd xmm4,[r8+r10*8]                                      ; 0976
    divsd xmm4,xmm2                                            ; 097c
    movsd qword [rsi+r10*8],xmm4                               ; 0980
    inc r10                                                    ; 0986
    cmp r10,rax                                                ; 0989
    jl short loc_0940                                           ; 098c
loc_098e:
    divsd xmm1,xmm0                                            ; 098e
    movsd qword [rel $+8],xmm1                                 ; 0992 | REL32 +4 FUNEQ2$SP addendLE=00000000
    mov rcx,r15                                                ; 099a
    call $+5                                                   ; 099d | REL32 +1 FU2NRM addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 09a2
    movsd xmm1,qword [rel $+8]                                 ; 09a7 | REL32 +4 FUNEQ2$FNORM addendLE=00000000
    divsd xmm0,xmm1                                            ; 09af
    mulsd xmm0,qword [rel $+8]                                 ; 09b3 | REL32 +4 FUNEQ2$STEP addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 09bb | REL32 +4 FUNEQ2$SS addendLE=00000000
    movsd xmm2,qword [r14]                                     ; 09c3
    movsd xmm3,qword [r14+0x80]                                ; 09c8
    movsd xmm4,qword [r14+0x88]                                ; 09d1
    maxsd xmm4,[rel $+8]                                       ; 09da | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    movapd xmm5,xmm2                                           ; 09e2
    mulsd xmm5,xmm4                                            ; 09e6
    movsd xmm0,qword [rel $+8]                                 ; 09ea | REL32 +4 FUNEQ2$FNORMN addendLE=00000000
    xorpd xmm6,xmm6                                            ; 09f2
    ucomisd xmm6,xmm0                                          ; 09f6
    setpe al                                                   ; 09fa
    setnz cl                                                   ; 09fd
    ucomisd xmm3,xmm5                                          ; 0a00
    jna near loc_1d58                                           ; 0a04
    or cl,al                                                   ; 0a0a
    jz near loc_1d58                                            ; 0a0c
loc_0a12:
    mov rcx,[rdi+0xa0]                                         ; 0a12
    lea rax,[rcx+0x1]                                          ; 0a19
    mov [rdi+0xa0],rax                                         ; 0a1d
    movsd xmm2,qword [rel $+8]                                 ; 0a24 | REL32 +4 __real@3feff7ced916872b addendLE=00000000
    mulsd xmm2,xmm1                                            ; 0a2c
    ucomisd xmm2,xmm0                                          ; 0a30
    jna short loc_0a4b                                          ; 0a34
    lea rdx,[rcx-0x1]                                          ; 0a36
    xor eax,eax                                                ; 0a3a
    cmp rcx,0x2                                                ; 0a3c
    cmovnl rax,rdx                                             ; 0a40
    mov [rdi+0xa0],rax                                         ; 0a44
loc_0a4b:
    mov r15,[r10]                                              ; 0a4b
    lea rcx,[r15+0x4]                                          ; 0a4e
    cmp r15,0x7                                                ; 0a52
    mov edx,0xa                                                ; 0a56
    cmovl rdx,rcx                                              ; 0a5b
    cmp rax,rdx                                                ; 0a5f
    mov r11,[rsp+0x250]                                        ; 0a62
    jng near loc_1e38                                           ; 0a6a
    mov qword [r12],0x4                                        ; 0a70
    mov r12d,0x4                                               ; 0a78
    cmp qword [rel $+7],0x2                                    ; 0a7e | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jng near loc_1e2b                                           ; 0a86
    mov qword [rsp+0x88],0x0                                   ; 0a8c
    mov edx,[rel $+6]                                          ; 0a98 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov word [rsp+0x82],0x1                                    ; 0a9e
    lea rax,[rel $+719]                                        ; 0aa8 | REL32 +3 FUNEQ2$format_pack addendLE=c8020000
    mov [rsp+0x28],rax                                         ; 0aaf
    mov qword [rsp+0x20],0x0                                   ; 0ab4
    lea rcx,[rsp+0x88]                                         ; 0abd
    mov r8,0x801208384ff00                                     ; 0ac5
    lea r9,[rsp+0x82]                                          ; 0acf
    jmp near loc_24ca                                           ; 0ad7
loc_0adc:
    lea rcx,[rdi+0xb0]                                         ; 0adc
    mov r8,[rdi+0xb0]                                          ; 0ae3
    mov r9,r8                                                  ; 0aea
    neg r9                                                     ; 0aed
    mov rax,r8                                                 ; 0af0
    cmovns rax,r9                                              ; 0af3
    lea rdx,[rbx+rax*8-0x8]                                    ; 0af7
    movsd xmm2,qword [rbx+rax*8-0x8]                           ; 0afc
    movsd xmm0,qword [r14+0x78]                                ; 0b02
    subsd xmm2,xmm0                                            ; 0b08
    movsd qword [rel $+8],xmm2                                 ; 0b0c | REL32 +4 FUNEQ2$STEP addendLE=00000000
    movapd xmm3,oword [rel $+8]                                ; 0b14 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    movapd xmm4,xmm2                                           ; 0b1c
    andpd xmm4,xmm3                                            ; 0b20
    movsd xmm1,qword [r14+0x60]                                ; 0b24
    andpd xmm3,xmm1                                            ; 0b2a
    movsd xmm5,qword [rel $+8]                                 ; 0b2e | REL32 +4 __real@3f847ae147ae147b addendLE=00000000
    mulsd xmm5,xmm3                                            ; 0b36
    mulsd xmm3,qword [rel $+8]                                 ; 0b3a | REL32 +4 __real@3f1a36e2eb1c432d addendLE=00000000
    ucomisd xmm4,xmm3                                          ; 0b42
    seta r10b                                                  ; 0b46
    test r8,r8                                                 ; 0b4a
    sets r11b                                                  ; 0b4d
    ucomisd xmm4,xmm5                                          ; 0b51
    ja near loc_0e47                                            ; 0b55
    and r10b,r11b                                              ; 0b5b
    jnz near loc_0e47                                           ; 0b5e
    test r8,r8                                                 ; 0b64
    js near loc_1cd9                                            ; 0b67
    dec rax                                                    ; 0b6d
    mov [rcx],r9                                               ; 0b70
    jmp near loc_135e                                           ; 0b73
loc_0b78:
    xor eax,eax                                                ; 0b78
    nop word [byte rax+rax+0x0]                                ; 0b7a
loc_0b80:
    movsd xmm0,qword [rbx+rax*8]                               ; 0b80
    movsd qword [rdx+rax*8],xmm0                               ; 0b85
    movsd xmm0,qword [rbp+rax*8+0x0]                           ; 0b8a
    movsd qword [r9+rax*8],xmm0                                ; 0b90
    inc rax                                                    ; 0b96
    cmp r15,rax                                                ; 0b99
    jnz short loc_0b80                                          ; 0b9c
loc_0b9e:
    mov r13,[rsp+0x258]                                        ; 0b9e
loc_0ba6:
    mov rcx,[rdi+0x40]                                         ; 0ba6
    mov rax,[rdi+0x88]                                         ; 0baa
    lea r8,[rax+0x1]                                           ; 0bb1
    mov [rdi+0x88],r8                                          ; 0bb5
    mov qword [rdi+0x90],0x1                                   ; 0bbc
    cmp rcx,0x1                                                ; 0bc7
    jnz short loc_0bda                                          ; 0bcb
    test rax,rax                                               ; 0bcd
    jnz short loc_0bda                                          ; 0bd0
    mov rbp,r10                                                ; 0bd2
    jmp near loc_14e3                                           ; 0bd5
loc_0bda:
    mov r13,r10                                                ; 0bda
    test r15,r15                                               ; 0bdd
    mov rbp,[rsp+0x68]                                         ; 0be0
    jng near loc_0ee6                                           ; 0be5
    cmp r15,0xd                                                ; 0beb
    jc near loc_0eb9                                            ; 0bef
    lea rbp,[r15*8+0x0]                                        ; 0bf5
    mov rcx,rbx                                                ; 0bfd
    mov r8,rbp                                                 ; 0c00
    call $+5                                                   ; 0c03 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov rcx,[rsp+0x68]                                         ; 0c08
    mov rdx,[rsp+0x280]                                        ; 0c0d
    mov r8,rbp                                                 ; 0c15
    call $+5                                                   ; 0c18 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov rcx,rsi                                                ; 0c1d
    xor edx,edx                                                ; 0c20
    mov r8,rbp                                                 ; 0c22
    mov rbp,[rsp+0x68]                                         ; 0c25
    call $+5                                                   ; 0c2a | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 0c2f
    jmp near loc_0ee6                                           ; 0c37
loc_0c3c:
    xor ecx,ecx                                                ; 0c3c
    xorpd xmm0,xmm0                                            ; 0c3e
    movapd xmm1,oword [rel $+8]                                ; 0c42 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xor eax,eax                                                ; 0c4a
    nop dword [byte rax+0x0]                                   ; 0c4c
loc_0c50:
    movsd xmm2,qword [rbx+rcx*8]                               ; 0c50
    xor edx,edx                                                ; 0c55
    ucomisd xmm0,xmm2                                          ; 0c57
    seta dl                                                    ; 0c5b
    add rax,rdx                                                ; 0c5e
    andpd xmm2,xmm1                                            ; 0c61
    movlpd qword [rbx+rcx*8],xmm2                              ; 0c65
    mov qword [rsi+rcx*8],0x0                                  ; 0c6a
    inc rcx                                                    ; 0c72
    cmp rbp,rcx                                                ; 0c75
    jnz short loc_0c50                                          ; 0c78
    jmp near loc_03bd                                           ; 0c7a
loc_0c7f:
    xor ecx,ecx                                                ; 0c7f
    xorpd xmm0,xmm0                                            ; 0c81
    xor eax,eax                                                ; 0c85
    nop word [dword rax+rax+0x0]                               ; 0c87
loc_0c90:
    xor edx,edx                                                ; 0c90
    ucomisd xmm0,qword [rbx+rcx*8]                             ; 0c92
    seta dl                                                    ; 0c97
    add rax,rdx                                                ; 0c9a
    mov qword [rsi+rcx*8],0x0                                  ; 0c9d
    inc rcx                                                    ; 0ca5
    cmp rbp,rcx                                                ; 0ca8
    jnz short loc_0c90                                          ; 0cab
    jmp near loc_03bd                                           ; 0cad
loc_0cb2:
    cmp rbp,0xd                                                ; 0cb2
    jc near loc_10a8                                            ; 0cb6
    lea r8,[rbp*8+0x0]                                         ; 0cbc
    xor r13d,r13d                                              ; 0cc4
    mov rcx,rsi                                                ; 0cc7
    xor edx,edx                                                ; 0cca
    call $+5                                                   ; 0ccc | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 0cd1
    xorpd xmm0,xmm0                                            ; 0cd9
    movapd xmm1,oword [rel $+8]                                ; 0cdd | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    mov rcx,0x3ff0000000000000                                 ; 0ce5
    movsd xmm2,qword [rel $+8]                                 ; 0cef | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 0cf7
    jmp short loc_0d12                                          ; 0cf9
    nop dword [byte rax+rax+0x0]                               ; 0cfb
loc_0d00:
    mov dl,r8b                                                 ; 0d00
    add rax,rdx                                                ; 0d03
    inc r13                                                    ; 0d06
    cmp rbp,r13                                                ; 0d09
    jz near loc_03bd                                            ; 0d0c
loc_0d12:
    movsd xmm3,qword [rbx+r13*8]                               ; 0d12
    xor edx,edx                                                ; 0d18
    ucomisd xmm0,xmm3                                          ; 0d1a
    seta r8b                                                   ; 0d1e
    andpd xmm3,xmm1                                            ; 0d22
    movlpd qword [rbx+r13*8],xmm3                              ; 0d26
    mov [r11+r13*8],rcx                                        ; 0d2c
    mov r9,[rsp+0x258]                                         ; 0d30
    cmp r12,0x1                                                ; 0d38
    jnz short loc_0d50                                          ; 0d3c
    movsd xmm3,qword [r9+r13*8]                                ; 0d3e
    jmp short loc_0d58                                          ; 0d44
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 0d46 | nop word [cs:rax+rax+0x0]
loc_0d50:
    mov [r9+r13*8],rcx                                         ; 0d50
    movapd xmm3,xmm2                                           ; 0d54
loc_0d58:
    ucomisd xmm3,xmm0                                          ; 0d58
    setpe r9b                                                  ; 0d5c
    setnz r10b                                                 ; 0d60
    or r10b,r9b                                                ; 0d64
    jnz short loc_0d00                                          ; 0d67
    mov r9,[rsp+0x258]                                         ; 0d69
    mov [r9+r13*8],rcx                                         ; 0d71
    jmp short loc_0d00                                          ; 0d75
loc_0d77:
    cmp rbp,0xd                                                ; 0d77
    jc near loc_1154                                            ; 0d7b
    lea r8,[rbp*8+0x0]                                         ; 0d81
    xor r13d,r13d                                              ; 0d89
    mov rcx,rsi                                                ; 0d8c
    xor edx,edx                                                ; 0d8f
    call $+5                                                   ; 0d91 | REL32 +1 _intel_fast_memset addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 0d96
    xorpd xmm0,xmm0                                            ; 0d9e
    mov rcx,0x3ff0000000000000                                 ; 0da2
    movsd xmm1,qword [rel $+8]                                 ; 0dac | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 0db4
    jmp short loc_0dd2                                          ; 0db6
    nop dword [dword rax+rax+0x0]                              ; 0db8
loc_0dc0:
    mov dl,r8b                                                 ; 0dc0
    add rax,rdx                                                ; 0dc3
    inc r13                                                    ; 0dc6
    cmp rbp,r13                                                ; 0dc9
    jz near loc_03bd                                            ; 0dcc
loc_0dd2:
    xor edx,edx                                                ; 0dd2
    ucomisd xmm0,qword [rbx+r13*8]                             ; 0dd4
    seta r8b                                                   ; 0dda
    mov [r11+r13*8],rcx                                        ; 0dde
    mov r9,[rsp+0x258]                                         ; 0de2
    cmp r12,0x1                                                ; 0dea
    jnz short loc_0e00                                          ; 0dee
    movsd xmm2,qword [r9+r13*8]                                ; 0df0
    jmp short loc_0e08                                          ; 0df6
    nop dword [dword rax+rax+0x0]                              ; 0df8
loc_0e00:
    mov [r9+r13*8],rcx                                         ; 0e00
    movapd xmm2,xmm1                                           ; 0e04
loc_0e08:
    ucomisd xmm2,xmm0                                          ; 0e08
    setpe r9b                                                  ; 0e0c
    setnz r10b                                                 ; 0e10
    or r10b,r9b                                                ; 0e14
    jnz short loc_0dc0                                          ; 0e17
    mov r9,[rsp+0x258]                                         ; 0e19
    mov [r9+r13*8],rcx                                         ; 0e21
    jmp short loc_0dc0                                          ; 0e25
loc_0e27:
    movsd xmm0,qword [r14+0x60]                                ; 0e27
    mulsd xmm0,qword [rel $+8]                                 ; 0e2d | REL32 +4 __real@3fd0000000000000 addendLE=00000000
    movsd qword [r14+0x60],xmm0                                ; 0e35
    lea rbp,[rdi+0x80]                                         ; 0e3b
    jmp near loc_1b42                                           ; 0e42
loc_0e47:
    movsd qword [rdx],xmm0                                     ; 0e47
    mov r10,[rsp+0x60]                                         ; 0e4b
    mov r15,[r10]                                              ; 0e50
    test r15,r15                                               ; 0e53
    jng near loc_1295                                           ; 0e56
    mov [rsp+0x70],rcx                                         ; 0e5c
    mov rdx,[rsp+0x288]                                        ; 0e61
    lea rax,[rdx+rax*8]                                        ; 0e69
    add rax,0xfffffffffffffff8                                 ; 0e6d
    xor edx,edx                                                ; 0e71
    mov r9,[rsp+0x280]                                         ; 0e73
    mov r11,[rsp+0x250]                                        ; 0e7b
    mov rcx,[rsp+0xf0]                                         ; 0e83
    nop dword [byte rax+rax+0x0]                               ; 0e8b
loc_0e90:
    movsd xmm0,qword [rbp+rdx*8+0x0]                           ; 0e90
    subsd xmm0,qword [r9+rdx*8]                                ; 0e96
    divsd xmm0,xmm2                                            ; 0e9c
    movsd qword [rax],xmm0                                     ; 0ea0
    inc rdx                                                    ; 0ea4
    add rax,rcx                                                ; 0ea7
    cmp rdx,r15                                                ; 0eaa
    jl short loc_0e90                                           ; 0ead
    mov rcx,[rsp+0x70]                                         ; 0eaf
    jmp near loc_129d                                           ; 0eb4
loc_0eb9:
    xor eax,eax                                                ; 0eb9
    nop dword [byte rax+rax+0x0]                               ; 0ebb
loc_0ec0:
    movsd xmm0,qword [rdx+rax*8]                               ; 0ec0
    movsd qword [rbx+rax*8],xmm0                               ; 0ec5
    movsd xmm0,qword [r9+rax*8]                                ; 0eca
    movsd qword [rbp+rax*8+0x0],xmm0                           ; 0ed0
    mov qword [rsi+rax*8],0x0                                  ; 0ed6
    inc rax                                                    ; 0ede
    cmp r15,rax                                                ; 0ee1
    jnz short loc_0ec0                                          ; 0ee4
loc_0ee6:
    mov qword [r12],0xfffffffffffffffe                         ; 0ee6
    mov qword [rdi+0x78],0x3                                   ; 0eee
    cmp qword [rdi+0x48],0x1                                   ; 0ef6
    jz near loc_2420                                            ; 0efb
    lea rcx,[rdi+0xb0]                                         ; 0f01
    xor r8d,r8d                                                ; 0f08
    mov r10,r13                                                ; 0f0b
    mov r13,[rsp+0x258]                                        ; 0f0e
    jmp near loc_129d                                           ; 0f16
loc_0f1b:
    xor ecx,ecx                                                ; 0f1b
    xorpd xmm0,xmm0                                            ; 0f1d
    movapd xmm1,oword [rel $+8]                                ; 0f21 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    mov rdx,0x3ff0000000000000                                 ; 0f29
    movsd xmm2,qword [rel $+8]                                 ; 0f33 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 0f3b
    jmp short loc_0f5a                                          ; 0f3d
    nop                                                        ; 0f3f
loc_0f40:
    mov r8b,r9b                                                ; 0f40
    add rax,r8                                                 ; 0f43
    inc rcx                                                    ; 0f46
    cmp rbp,rcx                                                ; 0f49
    mov r11,[rsp+0x250]                                        ; 0f4c
    jz near loc_03bd                                            ; 0f54
loc_0f5a:
    movsd xmm3,qword [rbx+rcx*8]                               ; 0f5a
    xor r8d,r8d                                                ; 0f5f
    ucomisd xmm0,xmm3                                          ; 0f62
    seta r9b                                                   ; 0f66
    andpd xmm3,xmm1                                            ; 0f6a
    movlpd qword [rbx+rcx*8],xmm3                              ; 0f6e
    ucomisd xmm0,qword [r11+rcx*8]                             ; 0f73
    mov qword [rsi+rcx*8],0x0                                  ; 0f79
    setpe r10b                                                 ; 0f81
    setnz r11b                                                 ; 0f85
    or r11b,r10b                                               ; 0f89
    jnz short loc_0f9a                                          ; 0f8c
    mov r10,[rsp+0x250]                                        ; 0f8e
    mov [r10+rcx*8],rdx                                        ; 0f96
loc_0f9a:
    cmp r12,0x1                                                ; 0f9a
    mov r13,[rsp+0x258]                                        ; 0f9e
    jnz short loc_0fc0                                          ; 0fa6
    movsd xmm3,qword [r13+rcx*8+0x0]                           ; 0fa8
    jmp short loc_0fc9                                          ; 0faf
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0fb1 | nop word [cs:rax+rax+0x0]
loc_0fc0:
    mov [r13+rcx*8+0x0],rdx                                    ; 0fc0
    movapd xmm3,xmm2                                           ; 0fc5
loc_0fc9:
    ucomisd xmm3,xmm0                                          ; 0fc9
    setpe r10b                                                 ; 0fcd
    setnz r11b                                                 ; 0fd1
    or r11b,r10b                                               ; 0fd5
    jnz near loc_0f40                                           ; 0fd8
    mov [r13+rcx*8+0x0],rdx                                    ; 0fde
    jmp near loc_0f40                                           ; 0fe3
loc_0fe8:
    xor ecx,ecx                                                ; 0fe8
    xorpd xmm0,xmm0                                            ; 0fea
    mov rdx,0x3ff0000000000000                                 ; 0fee
    movsd xmm1,qword [rel $+8]                                 ; 0ff8 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 1000
    jmp short loc_102a                                          ; 1002
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 1004 | nop word [cs:rax+rax+0x0]
loc_1010:
    mov r8b,r9b                                                ; 1010
    add rax,r8                                                 ; 1013
    inc rcx                                                    ; 1016
    cmp rbp,rcx                                                ; 1019
    mov r11,[rsp+0x250]                                        ; 101c
    jz near loc_03bd                                            ; 1024
loc_102a:
    xor r8d,r8d                                                ; 102a
    ucomisd xmm0,qword [rbx+rcx*8]                             ; 102d
    seta r9b                                                   ; 1032
    ucomisd xmm0,qword [r11+rcx*8]                             ; 1036
    mov qword [rsi+rcx*8],0x0                                  ; 103c
    setpe r10b                                                 ; 1044
    setnz r11b                                                 ; 1048
    or r11b,r10b                                               ; 104c
    jnz short loc_105d                                          ; 104f
    mov r10,[rsp+0x250]                                        ; 1051
    mov [r10+rcx*8],rdx                                        ; 1059
loc_105d:
    cmp r12,0x1                                                ; 105d
    mov r13,[rsp+0x258]                                        ; 1061
    jnz short loc_1080                                          ; 1069
    movsd xmm2,qword [r13+rcx*8+0x0]                           ; 106b
    jmp short loc_1089                                          ; 1072
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 1074 | nop word [cs:rax+rax+0x0]
loc_1080:
    mov [r13+rcx*8+0x0],rdx                                    ; 1080
    movapd xmm2,xmm1                                           ; 1085
loc_1089:
    ucomisd xmm2,xmm0                                          ; 1089
    setpe r10b                                                 ; 108d
    setnz r11b                                                 ; 1091
    or r11b,r10b                                               ; 1095
    jnz near loc_1010                                           ; 1098
    mov [r13+rcx*8+0x0],rdx                                    ; 109e
    jmp near loc_1010                                           ; 10a3
loc_10a8:
    xor ecx,ecx                                                ; 10a8
    xorpd xmm0,xmm0                                            ; 10aa
    movapd xmm1,oword [rel $+8]                                ; 10ae | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    mov rdx,0x3ff0000000000000                                 ; 10b6
    movsd xmm2,qword [rel $+8]                                 ; 10c0 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 10c8
    jmp short loc_10ea                                          ; 10ca
    nop dword [byte rax+0x0]                                   ; 10cc
loc_10d0:
    mov r8b,r9b                                                ; 10d0
    add rax,r8                                                 ; 10d3
    inc rcx                                                    ; 10d6
    cmp rbp,rcx                                                ; 10d9
    mov r11,[rsp+0x250]                                        ; 10dc
    jz near loc_03bd                                            ; 10e4
loc_10ea:
    movsd xmm3,qword [rbx+rcx*8]                               ; 10ea
    xor r8d,r8d                                                ; 10ef
    ucomisd xmm0,xmm3                                          ; 10f2
    seta r9b                                                   ; 10f6
    andpd xmm3,xmm1                                            ; 10fa
    movlpd qword [rbx+rcx*8],xmm3                              ; 10fe
    mov qword [rsi+rcx*8],0x0                                  ; 1103
    mov [r11+rcx*8],rdx                                        ; 110b
    mov r13,[rsp+0x258]                                        ; 110f
    cmp r12,0x1                                                ; 1117
    jnz short loc_1130                                          ; 111b
    movsd xmm3,qword [r13+rcx*8+0x0]                           ; 111d
    jmp short loc_1139                                          ; 1124
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 1126 | nop word [cs:rax+rax+0x0]
loc_1130:
    mov [r13+rcx*8+0x0],rdx                                    ; 1130
    movapd xmm3,xmm2                                           ; 1135
loc_1139:
    ucomisd xmm3,xmm0                                          ; 1139
    setpe r10b                                                 ; 113d
    setnz r11b                                                 ; 1141
    or r11b,r10b                                               ; 1145
    jnz short loc_10d0                                          ; 1148
    mov [r13+rcx*8+0x0],rdx                                    ; 114a
    jmp near loc_10d0                                           ; 114f
loc_1154:
    xor ecx,ecx                                                ; 1154
    xorpd xmm0,xmm0                                            ; 1156
    mov rdx,0x3ff0000000000000                                 ; 115a
    movsd xmm1,qword [rel $+8]                                 ; 1164 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xor eax,eax                                                ; 116c
    jmp short loc_118a                                          ; 116e
loc_1170:
    mov r8b,r9b                                                ; 1170
    add rax,r8                                                 ; 1173
    inc rcx                                                    ; 1176
    cmp rbp,rcx                                                ; 1179
    mov r11,[rsp+0x250]                                        ; 117c
    jz near loc_03bd                                            ; 1184
loc_118a:
    xor r8d,r8d                                                ; 118a
    ucomisd xmm0,qword [rbx+rcx*8]                             ; 118d
    seta r9b                                                   ; 1192
    mov qword [rsi+rcx*8],0x0                                  ; 1196
    mov [r11+rcx*8],rdx                                        ; 119e
    mov r13,[rsp+0x258]                                        ; 11a2
    cmp r12,0x1                                                ; 11aa
    jnz short loc_11c0                                          ; 11ae
    movsd xmm2,qword [r13+rcx*8+0x0]                           ; 11b0
    jmp short loc_11c9                                          ; 11b7
    nop dword [dword rax+0x0]                                  ; 11b9
loc_11c0:
    mov [r13+rcx*8+0x0],rdx                                    ; 11c0
    movapd xmm2,xmm1                                           ; 11c5
loc_11c9:
    ucomisd xmm2,xmm0                                          ; 11c9
    setpe r10b                                                 ; 11cd
    setnz r11b                                                 ; 11d1
    or r11b,r10b                                               ; 11d5
    jnz short loc_1170                                          ; 11d8
    mov [r13+rcx*8+0x0],rdx                                    ; 11da
    jmp short loc_1170                                          ; 11df
loc_11e1:
    movsd xmm2,qword [r14]                                     ; 11e1
    xorps xmm1,xmm1                                            ; 11e6
    sqrtsd xmm1,xmm2                                           ; 11e9
    ucomisd xmm1,xmm0                                          ; 11ed
    mov r10,r15                                                ; 11f1
    jnc near loc_1599                                           ; 11f4
    movsd xmm3,qword [r14+0x80]                                ; 11fa
    movsd xmm4,qword [r14+0x88]                                ; 1203
    maxsd xmm4,[rel $+8]                                       ; 120c | REL32 +4 __real@3ff0000000000000 addendLE=00000000
loc_1214:
    xorps xmm0,xmm0                                            ; 1214
    sqrtsd xmm0,xmm2                                           ; 1217
    mulsd xmm0,xmm4                                            ; 121b
    ucomisd xmm3,xmm0                                          ; 121f
    jna near loc_1daf                                           ; 1223
    mov qword [r12],0x3                                        ; 1229
    mov r12d,0x3                                               ; 1231
    cmp qword [rel $+7],0x2                                    ; 1237 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jng near loc_1e2b                                           ; 123f
    mov qword [rsp+0x88],0x0                                   ; 1245
    mov edx,[rel $+6]                                          ; 1251 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov word [rsp+0x84],0x1                                    ; 1257
    lea rax,[rel $+767]                                        ; 1261 | REL32 +3 FUNEQ2$format_pack addendLE=f8020000
    mov [rsp+0x28],rax                                         ; 1268
    mov qword [rsp+0x20],0x0                                   ; 126d
    lea rcx,[rsp+0x88]                                         ; 1276
    mov r8,0x801208384ff00                                     ; 127e
    lea r9,[rsp+0x84]                                          ; 1288
    jmp near loc_24ca                                           ; 1290
loc_1295:
    mov r11,[rsp+0x250]                                        ; 1295
loc_129d:
    mov rax,r8                                                 ; 129d
    neg rax                                                    ; 12a0
    cmovs rax,r8                                               ; 12a3
    lea rdx,[rax+0x1]                                          ; 12a7
    mov [rcx],rdx                                              ; 12ab
    cmp rax,r15                                                ; 12ae
    jnl near loc_1396                                           ; 12b1
    movsd xmm0,qword [rbx+rax*8]                               ; 12b7
    movsd qword [r14+0x78],xmm0                                ; 12bc
    movapd xmm1,oword [rel $+8]                                ; 12c2 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    andpd xmm1,xmm0                                            ; 12ca
    mulsd xmm1,qword [r14+0x28]                                ; 12ce
    maxsd xmm1,[r14+0x30]                                      ; 12d4
    movapd xmm2,xmm0                                           ; 12da
    addsd xmm2,xmm1                                            ; 12de
    movsd xmm3,qword [rel $+8]                                 ; 12e2 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    ucomisd xmm2,xmm3                                          ; 12ea
    movsd qword [rel $+8],xmm1                                 ; 12ee | REL32 +4 FUNEQ2$STEP addendLE=00000000
    setnc cl                                                   ; 12f6
    ucomisd xmm3,xmm0                                          ; 12f9
    jna short loc_1313                                          ; 12fd
    test cl,cl                                                 ; 12ff
    jz short loc_1313                                           ; 1301
    xorpd xmm1,oword [rel $+8]                                 ; 1303 | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    movlpd qword [rel $+8],xmm1                                ; 130b | REL32 +4 FUNEQ2$STEP addendLE=00000000
loc_1313:
    movapd xmm3,xmm0                                           ; 1313
    addsd xmm3,xmm1                                            ; 1317
    xorpd xmm2,xmm2                                            ; 131b
    ucomisd xmm2,xmm3                                          ; 131f
    setnc cl                                                   ; 1323
    ucomisd xmm0,xmm2                                          ; 1326
    jna short loc_1340                                          ; 132a
    test cl,cl                                                 ; 132c
    jz short loc_1340                                           ; 132e
    xorpd xmm1,oword [rel $+8]                                 ; 1330 | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    movlpd qword [rel $+8],xmm1                                ; 1338 | REL32 +4 FUNEQ2$STEP addendLE=00000000
loc_1340:
    lea rdx,[rbx+rax*8]                                        ; 1340
    movapd xmm3,xmm0                                           ; 1344
    addsd xmm3,xmm1                                            ; 1348
    ucomisd xmm2,xmm3                                          ; 134c
    seta cl                                                    ; 1350
    cmp qword [rdi+0x38],0x1                                   ; 1353
    jnz short loc_136e                                          ; 1358
    test cl,cl                                                 ; 135a
    jz short loc_136e                                           ; 135c
loc_135e:
    xorpd xmm1,oword [rel $+8]                                 ; 135e | REL32 +4 __xmm@80000000000000008000000000000000 addendLE=00000000
    movlpd qword [rel $+8],xmm1                                ; 1366 | REL32 +4 FUNEQ2$STEP addendLE=00000000
loc_136e:
    addsd xmm0,xmm1                                            ; 136e
    movsd qword [rdx],xmm0                                     ; 1372
    movsd qword [rsi+rax*8],xmm1                               ; 1376
    movsd qword [r14+0x60],xmm1                                ; 137b
    mov qword [r12],0xffffffffffffffff                         ; 1381
    mov qword [rdi+0x78],0x2                                   ; 1389
    jmp near loc_2420                                           ; 1391
loc_1396:
    test r15,r15                                               ; 1396
    jng near loc_1448                                           ; 1399
    mov eax,0x1                                                ; 139f
    xorpd xmm0,xmm0                                            ; 13a4
    mov rdx,[rsp+0x288]                                        ; 13a8
    mov rcx,rdx                                                ; 13b0
loc_13b3:
    xor r8d,r8d                                                ; 13b3
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 13b6 | nop word [cs:rax+rax+0x0]
loc_13c0:
    ucomisd xmm0,qword [rdx+r8*8]                              ; 13c0
    setpo r9b                                                  ; 13c6
    setz r10b                                                  ; 13ca
    test r10b,r9b                                              ; 13ce
    jz short loc_13e0                                           ; 13d1
    inc r8                                                     ; 13d3
    cmp r15,r8                                                 ; 13d6
    jnz short loc_13c0                                          ; 13d9
    jmp near loc_16a9                                           ; 13db
loc_13e0:
    mov [rsp+0x70],r12                                         ; 13e0
    mov r8,rcx                                                 ; 13e5
    mov r9,r15                                                 ; 13e8
    mov r12,[rsp+0xf0]                                         ; 13eb
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 13f3 | nop word [cs:rax+rax+0x0]
loc_1400:
    ucomisd xmm0,qword [r8]                                    ; 1400
    setpo r10b                                                 ; 1405
    setz r11b                                                  ; 1409
    test r11b,r10b                                             ; 140d
    jz short loc_141f                                           ; 1410
    add r8,r12                                                 ; 1412
    dec r9                                                     ; 1415
    jnz short loc_1400                                          ; 1418
    jmp near loc_1747                                           ; 141a
loc_141f:
    lea r8,[rax+0x1]                                           ; 141f
    add rdx,r12                                                ; 1423
    add rcx,0x8                                                ; 1426
    cmp rax,r15                                                ; 142a
    mov rax,r8                                                 ; 142d
    mov r12,[rsp+0x70]                                         ; 1430
    mov r11,[rsp+0x250]                                        ; 1435
    mov r10,[rsp+0x60]                                         ; 143d
    jl near loc_13b3                                            ; 1442
loc_1448:
    lea r8,[rdi+0x8]                                           ; 1448
    mov rax,[rsp+0x290]                                        ; 144c
    mov [rsp+0x30],rax                                         ; 1454
    mov rbp,[rsp+0x288]                                        ; 1459
    mov [rsp+0x28],rbp                                         ; 1461
    mov [rsp+0x20],r13                                         ; 1466
    mov rcx,r10                                                ; 146b
    mov rdx,rdi                                                ; 146e
    mov r9,r11                                                 ; 1471
    mov r15,r10                                                ; 1474
    call $+5                                                   ; 1477 | REL32 +1 FUNEQ9 addendLE=00000000
    lea rcx,[r14+0x10]                                         ; 147c
    lea rax,[r14+0x8]                                          ; 1480
    mov [rsp+0x28],rax                                         ; 1484
    mov [rsp+0x70],rcx                                         ; 1489
    mov [rsp+0x20],rcx                                         ; 148e
    mov rcx,r15                                                ; 1493
    mov rdx,[rsp+0x290]                                        ; 1496
    mov r8,rbp                                                 ; 149e
    mov r13,[rsp+0x260]                                        ; 14a1
    mov r9,r13                                                 ; 14a9
    call $+5                                                   ; 14ac | REL32 +1 FUNEQ3 addendLE=00000000
    mov r11,[rsp+0x250]                                        ; 14b1
    mov rbp,r15                                                ; 14b9
    mov r15,[r15]                                              ; 14bc
    cmp qword [r13+r15*8-0x8],0x0                              ; 14bf
    mov r13,[rsp+0x258]                                        ; 14c5
    mov rdx,[rsp+0x278]                                        ; 14cd
    mov r9,[rsp+0x280]                                         ; 14d5
    jz near loc_17c2                                            ; 14dd
loc_14e3:
    test r15,r15                                               ; 14e3
    mov r8,[rsp+0x270]                                         ; 14e6
    jng short loc_152b                                          ; 14ee
    xor eax,eax                                                ; 14f0
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 14f2 | nop word [cs:rax+rax+0x0]
loc_1500:
    movsd xmm0,qword [rdx+rax*8]                               ; 1500
    divsd xmm0,[r11+rax*8]                                     ; 1505
    movsd xmm1,qword [r9+rax*8]                                ; 150b
    divsd xmm1,[r13+rax*8+0x0]                                 ; 1511
    movsd qword [rsi+rax*8],xmm0                               ; 1518
    movsd qword [r8+rax*8],xmm1                                ; 151d
    inc rax                                                    ; 1523
    cmp rax,r15                                                ; 1526
    jl short loc_1500                                           ; 1529
loc_152b:
    mov rcx,rbp                                                ; 152b
    mov rdx,rsi                                                ; 152e
    mov r15,r8                                                 ; 1531
    call $+5                                                   ; 1534 | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 1539 | REL32 +4 FUNEQ2$XNORM addendLE=00000000
    mov rcx,rbp                                                ; 1541
    mov rdx,r15                                                ; 1544
    call $+5                                                   ; 1547 | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 154c | REL32 +4 FUNEQ2$FNORM addendLE=00000000
    movsd qword [r14+0x50],xmm0                                ; 1554
    xorpd xmm1,xmm1                                            ; 155a
    ucomisd xmm0,xmm1                                          ; 155e
    movsd qword [r14+0x58],xmm0                                ; 1562
    setpe al                                                   ; 1568
    setnz cl                                                   ; 156b
    or cl,al                                                   ; 156e
    jnz short loc_157d                                          ; 1570
    mov qword [r14+0x80],0x0                                   ; 1572
loc_157d:
    ucomisd xmm0,xmm1                                          ; 157d
    setpo al                                                   ; 1581
    setz cl                                                    ; 1584
    test cl,al                                                 ; 1587
    mov rbp,[rsp+0x68]                                         ; 1589
    mov r10,[rsp+0x60]                                         ; 158e
    jz near loc_1673                                            ; 1593
loc_1599:
    mov qword [r12],0x1                                        ; 1599
    mov rax,[rdi+0x88]                                         ; 15a1
    sub rax,[rdi+0x40]                                         ; 15a8
    mov [rel $+7],rax                                          ; 15ac | REL32 +3 FUNEQ2$I1 addendLE=00000000
    mov r12d,0x1                                               ; 15b3
    cmp qword [rel $+7],0x7                                    ; 15b9 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jl near loc_1e2b                                            ; 15c1
    mov rax,[rdi+0x80]                                         ; 15c7
    mov qword [rsp+0x88],0x0                                   ; 15ce
    mov edx,[rel $+6]                                          ; 15da | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xd8],0x2010b                               ; 15e0
    mov [rsp+0x140],rax                                        ; 15eb
    lea rax,[rel $+983]                                        ; 15f3 | REL32 +3 FUNEQ2$format_pack addendLE=d0030000
    mov [rsp+0x28],rax                                         ; 15fa
    lea rax,[rsp+0x140]                                        ; 15ff
    mov [rsp+0x20],rax                                         ; 1607
    lea r15,[rsp+0x88]                                         ; 160c
    mov r8,0x801208384ff00                                     ; 1614
    lea r9,[rsp+0xd8]                                          ; 161e
    mov rcx,r15                                                ; 1626
    mov r13,r10                                                ; 1629
    call $+5                                                   ; 162c | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov rax,[rel $+7]                                          ; 1631 | REL32 +3 FUNEQ2$I1 addendLE=00000000
    mov dword [rsp+0xd4],0x1010b                               ; 1638
    mov [rsp+0x138],rax                                        ; 1643
    lea rdx,[rsp+0xd4]                                         ; 164b
    lea r8,[rsp+0x138]                                         ; 1653
    mov rcx,r15                                                ; 165b
    call $+5                                                   ; 165e | REL32 +1 for_write_seq_fmt_xmit addendLE=00000000
    mov r10,r13                                                ; 1663
    mov rdx,[rsp+0x278]                                        ; 1666
    jmp near loc_228f                                           ; 166e
loc_1673:
    mov rax,[rdi+0x40]                                         ; 1673
    mov rcx,[rdi+0x88]                                         ; 1677
    cmp rcx,0x1                                                ; 167e
    jnz near loc_1722                                           ; 1682
    cmp rax,0x1                                                ; 1688
    jnz near loc_1722                                           ; 168c
    movsd xmm1,qword [rel $+8]                                 ; 1692 | REL32 +4 __real@4000000000000000 addendLE=00000000
    mulsd xmm1,xmm0                                            ; 169a
    movsd qword [r14+0x58],xmm1                                ; 169e
    jmp near loc_172c                                           ; 16a4
loc_16a9:
    mov rcx,r12                                                ; 16a9
    imul r12,rax,0x64                                          ; 16ac
    add r12,0xb                                                ; 16b0
    mov [rcx],r12                                              ; 16b4
    cmp qword [rel $+7],0x2                                    ; 16b7 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jng near loc_1d46                                           ; 16bf
    mov qword [rsp+0x88],0x0                                   ; 16c5
    mov edx,[rel $+6]                                          ; 16d1 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xbc],0x1010b                               ; 16d7
    mov [rsp+0x108],rax                                        ; 16e2
    lea rax,[rel $+187]                                        ; 16ea | REL32 +3 FUNEQ2$format_pack addendLE=b4000000
    mov [rsp+0x28],rax                                         ; 16f1
    lea rax,[rsp+0x108]                                        ; 16f6
    mov [rsp+0x20],rax                                         ; 16fe
    lea rcx,[rsp+0x88]                                         ; 1703
    mov r8,0x801208384ff00                                     ; 170b
    lea r9,[rsp+0xbc]                                          ; 1715
    jmp near loc_1d41                                           ; 171d
loc_1722:
    cmp rcx,0x1                                                ; 1722
    jnz near loc_1855                                           ; 1726
loc_172c:
    movsd xmm0,qword [rel $+8]                                 ; 172c | REL32 +4 FUNEQ2$XNORM addendLE=00000000
    maxsd xmm0,[rel $+8]                                       ; 1734 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    mulsd xmm0,qword [r14+0x18]                                ; 173c
    jmp near loc_185b                                           ; 1742
loc_1747:
    imul r12,rax,0x64                                          ; 1747
    add r12,0xc                                                ; 174b
    mov rcx,[rsp+0x70]                                         ; 174f
    mov [rcx],r12                                              ; 1754
    cmp qword [rel $+7],0x2                                    ; 1757 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jng near loc_1d46                                           ; 175f
    mov qword [rsp+0x88],0x0                                   ; 1765
    mov edx,[rel $+6]                                          ; 1771 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xb8],0x1010b                               ; 1777
    mov [rsp+0x100],rax                                        ; 1782
    lea rax,[rel $+83]                                         ; 178a | REL32 +3 FUNEQ2$format_pack addendLE=4c000000
    mov [rsp+0x28],rax                                         ; 1791
    lea rax,[rsp+0x100]                                        ; 1796
    mov [rsp+0x20],rax                                         ; 179e
    lea rcx,[rsp+0x88]                                         ; 17a3
    mov r8,0x801208384ff00                                     ; 17ab
    lea r9,[rsp+0xb8]                                          ; 17b5
    jmp near loc_1d41                                           ; 17bd
loc_17c2:
    mov rax,[rsp+0x70]                                         ; 17c2
    mov qword [r12],0x7                                        ; 17c7
    mov r12d,0x7                                               ; 17cf
    cmp qword [rel $+7],0x2                                    ; 17d5 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jng near loc_1da7                                           ; 17dd
    movsd xmm0,qword [rax]                                     ; 17e3
    mov qword [rsp+0x88],0x0                                   ; 17e7
    mov edx,[rel $+6]                                          ; 17f3 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xc4],0x10130                               ; 17f9
    movsd qword [rsp+0x118],xmm0                               ; 1804
    lea rax,[rel $+431]                                        ; 180d | REL32 +3 FUNEQ2$format_pack addendLE=a8010000
    mov [rsp+0x28],rax                                         ; 1814
    lea rax,[rsp+0x118]                                        ; 1819
    mov [rsp+0x20],rax                                         ; 1821
    lea rcx,[rsp+0x88]                                         ; 1826
    mov r8,0x801208384ff00                                     ; 182e
    lea r9,[rsp+0xc4]                                          ; 1838
    call $+5                                                   ; 1840 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov rdx,[rsp+0x278]                                        ; 1845
    mov r10,rbp                                                ; 184d
    jmp near loc_228a                                           ; 1850
loc_1855:
    movsd xmm0,qword [r14+0x68]                                ; 1855
loc_185b:
    mov r15,0x801208384ff00                                    ; 185b
    movsd qword [r14+0x60],xmm0                                ; 1865
    mov rdx,0x4000000000000000                                 ; 186b
    mov [r14+0x78],rdx                                         ; 1875
    mov rdx,[rdi+0x80]                                         ; 1879
    inc rdx                                                    ; 1880
    mov [rdi+0x98],rdx                                         ; 1883
    mov qword [rdi+0xa0],0x0                                   ; 188a
    mov rdx,[rel $+7]                                          ; 1895 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    cmp rcx,0x2                                                ; 189c
    setnl r8b                                                  ; 18a0
    cmp rax,0x1                                                ; 18a4
    setnz r9b                                                  ; 18a8
    cmp rdx,0x6                                                ; 18ac
    jl short loc_1924                                           ; 18b0
    or r8b,r9b                                                 ; 18b2
    jz short loc_1924                                           ; 18b5
    mov qword [rsp+0x88],0x0                                   ; 18b7
    mov edx,[rel $+6]                                          ; 18c3 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xe4],0x1010b                               ; 18c9
    mov [rsp+0x148],rcx                                        ; 18d4
    lea rax,[rel $+1287]                                       ; 18dc | REL32 +3 FUNEQ2$format_pack addendLE=00050000
    mov [rsp+0x28],rax                                         ; 18e3
    lea rax,[rsp+0x148]                                        ; 18e8
    mov [rsp+0x20],rax                                         ; 18f0
    lea rcx,[rsp+0x88]                                         ; 18f5
    lea r9,[rsp+0xe4]                                          ; 18fd
    mov r8,r15                                                 ; 1905
    call $+5                                                   ; 1908 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 190d
    mov rdx,[rel $+7]                                          ; 1912 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    mov rax,[rdi+0x40]                                         ; 1919
    mov rcx,[rdi+0x88]                                         ; 191d
loc_1924:
    cmp rdx,0x6                                                ; 1924
    mov r8,[rsp+0x280]                                         ; 1928
    jl short loc_199b                                           ; 1930
    cmp rcx,0x1                                                ; 1932
    jnz short loc_199b                                          ; 1936
    cmp rax,0x1                                                ; 1938
    jnz short loc_199b                                          ; 193c
    mov qword [rsp+0x88],0x0                                   ; 193e
    mov edx,[rel $+6]                                          ; 194a | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov word [rsp+0x86],0x1                                    ; 1950
    lea rax,[rel $+1239]                                       ; 195a | REL32 +3 FUNEQ2$format_pack addendLE=d0040000
    mov [rsp+0x28],rax                                         ; 1961
    mov qword [rsp+0x20],0x0                                   ; 1966
    lea rcx,[rsp+0x88]                                         ; 196f
    lea r9,[rsp+0x86]                                          ; 1977
    mov r8,r15                                                 ; 197f
    call $+5                                                   ; 1982 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 1987
    mov r8,[rsp+0x280]                                         ; 198c
    mov rdx,[rel $+7]                                          ; 1994 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
loc_199b:
    lea rbp,[rdi+0x80]                                         ; 199b
    cmp rdx,0x8                                                ; 19a2
    jl near loc_1af8                                            ; 19a6
    mov rax,[r10]                                              ; 19ac
    xor ecx,ecx                                                ; 19af
    test rax,rax                                               ; 19b1
    cmovg rcx,rax                                              ; 19b4
    mov qword [rsp+0x88],0x0                                   ; 19b8
    mov edx,[rel $+6]                                          ; 19c4 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xe0],0x10730                               ; 19ca
    mov qword [rsp+0x178],0x1                                  ; 19d5
    mov rax,[rsp+0x250]                                        ; 19e1
    mov [rsp+0x180],rax                                        ; 19e9
    mov qword [rsp+0x188],0x1                                  ; 19f1
    mov [rsp+0x190],rcx                                        ; 19fd
    mov qword [rsp+0x198],0x8                                  ; 1a05
    lea rax,[rel $+1171]                                       ; 1a11 | REL32 +3 FUNEQ2$format_pack addendLE=8c040000
    mov [rsp+0x28],rax                                         ; 1a18
    lea rax,[rsp+0x178]                                        ; 1a1d
    mov [rsp+0x20],rax                                         ; 1a25
    lea rcx,[rsp+0x88]                                         ; 1a2a
    lea r9,[rsp+0xe0]                                          ; 1a32
    mov r8,r15                                                 ; 1a3a
    call $+5                                                   ; 1a3d | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 1a42
    mov r8,[rsp+0x280]                                         ; 1a47
    cmp qword [rel $+7],0x8                                    ; 1a4f | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jl near loc_1af8                                            ; 1a57
    mov rax,[r10]                                              ; 1a5d
    xor ecx,ecx                                                ; 1a60
    test rax,rax                                               ; 1a62
    cmovg rcx,rax                                              ; 1a65
    mov qword [rsp+0x88],0x0                                   ; 1a69
    mov edx,[rel $+6]                                          ; 1a75 | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xdc],0x10730                               ; 1a7b
    mov qword [rsp+0x150],0x1                                  ; 1a86
    mov [rsp+0x158],r13                                        ; 1a92
    mov qword [rsp+0x160],0x1                                  ; 1a9a
    mov [rsp+0x168],rcx                                        ; 1aa6
    mov qword [rsp+0x170],0x8                                  ; 1aae
    lea rax,[rel $+1103]                                       ; 1aba | REL32 +3 FUNEQ2$format_pack addendLE=48040000
    mov [rsp+0x28],rax                                         ; 1ac1
    lea rax,[rsp+0x150]                                        ; 1ac6
    mov [rsp+0x20],rax                                         ; 1ace
    lea rcx,[rsp+0x88]                                         ; 1ad3
    lea r9,[rsp+0xdc]                                          ; 1adb
    mov r8,r15                                                 ; 1ae3
    call $+5                                                   ; 1ae6 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 1aeb
    mov r8,[rsp+0x280]                                         ; 1af0
loc_1af8:
    lea rax,[rel $+7]                                          ; 1af8 | REL32 +3 FUNEQ2$LPRINT addendLE=00000000
    mov [rsp+0x30],rax                                         ; 1aff
    lea rax,[rel $+7]                                          ; 1b04 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    mov [rsp+0x28],rax                                         ; 1b0b
    mov [rsp+0x20],r8                                          ; 1b10
    lea r8,[rel $+7]                                           ; 1b15 | REL32 +3 FUNEQ2$FNORM addendLE=00000000
    mov rcx,r10                                                ; 1b1c
    mov rdx,rbp                                                ; 1b1f
    mov r15,[rsp+0x278]                                        ; 1b22
    mov r9,r15                                                 ; 1b2a
    call $+5                                                   ; 1b2d | REL32 +1 FUNEQ8 addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 1b32
    mov rdx,r15                                                ; 1b37
    mov r11,[rsp+0x250]                                        ; 1b3a
loc_1b42:
    mov rax,[rdi+0x28]                                         ; 1b42
    mov rcx,[rdi+0x80]                                         ; 1b46
    cmp rcx,rax                                                ; 1b4d
    jnl near loc_2207                                           ; 1b50
    mov rax,rbp                                                ; 1b56
    mov rbp,r12                                                ; 1b59
    inc rcx                                                    ; 1b5c
    mov [rax],rcx                                              ; 1b5f
    mov rax,[r10]                                              ; 1b62
    test rax,rax                                               ; 1b65
    jng short loc_1b88                                          ; 1b68
    xor ecx,ecx                                                ; 1b6a
    nop dword [byte rax+0x0]                                   ; 1b6c
loc_1b70:
    movsd xmm0,qword [rdx+rcx*8]                               ; 1b70
    divsd xmm0,[r11+rcx*8]                                     ; 1b75
    movsd qword [rsi+rcx*8],xmm0                               ; 1b7b
    inc rcx                                                    ; 1b80
    cmp rcx,rax                                                ; 1b83
    jl short loc_1b70                                           ; 1b86
loc_1b88:
    mov rcx,r10                                                ; 1b88
    mov rdx,rsi                                                ; 1b8b
    mov r15,r10                                                ; 1b8e
    call $+5                                                   ; 1b91 | REL32 +1 FU2NRM addendLE=00000000
    movsd qword [r14+0x88],xmm0                                ; 1b96
    lea rdx,[rdi+0x10]                                         ; 1b9f
    lea r8,[r14+0x60]                                          ; 1ba3
    sub r14,0xffffffffffffff80                                 ; 1ba7
    mov rax,[rsp+0x68]                                         ; 1bab
    mov [rsp+0x58],rax                                         ; 1bb0
    mov [rsp+0x50],rbx                                         ; 1bb5
    mov [rsp+0x48],rsi                                         ; 1bba
    mov rax,[rsp+0x260]                                        ; 1bbf
    mov [rsp+0x40],rax                                         ; 1bc7
    mov rax,[rsp+0x290]                                        ; 1bcc
    mov [rsp+0x38],rax                                         ; 1bd4
    mov rax,[rsp+0x288]                                        ; 1bd9
    mov [rsp+0x30],rax                                         ; 1be1
    mov rax,[rsp+0x280]                                        ; 1be6
    mov [rsp+0x28],rax                                         ; 1bee
    mov [rsp+0x20],r13                                         ; 1bf3
    mov rcx,r15                                                ; 1bf8
    mov r9,r14                                                 ; 1bfb
    call $+5                                                   ; 1bfe | REL32 +1 FUNEQ4 addendLE=00000000
    mov r8,[rsp+0x250]                                         ; 1c03
    mov rdx,[rsp+0x278]                                        ; 1c0b
    mov r14,[r15]                                              ; 1c13
    test r14,r14                                               ; 1c16
    jng near loc_1cc4                                           ; 1c19
    mov r15,[rdi+0x38]                                         ; 1c1f
    xor r12d,r12d                                              ; 1c23
    xorpd xmm6,xmm6                                            ; 1c26
    movsd xmm7,qword [rel $+8]                                 ; 1c2a | REL32 +4 __real@c000000000000000 addendLE=00000000
    movapd xmm8,oword [rel $+9]                                ; 1c32 | REL32 +5 __xmm@80000000000000008000000000000000 addendLE=00000000
    jmp short loc_1c4e                                          ; 1c3b
    nop dword [rax]                                            ; 1c3d
loc_1c40:
    movsd qword [rbx+r12*8],xmm0                               ; 1c40
    inc r12                                                    ; 1c46
    cmp r14,r12                                                ; 1c49
    jz short loc_1cc4                                           ; 1c4c
loc_1c4e:
    movsd xmm1,qword [rsi+r12*8]                               ; 1c4e
    mulsd xmm1,qword [r8+r12*8]                                ; 1c54
    movsd qword [rsi+r12*8],xmm1                               ; 1c5a
    movsd xmm9,qword [rdx+r12*8]                               ; 1c60
    movapd xmm0,xmm9                                           ; 1c66
    addsd xmm0,xmm1                                            ; 1c6b
    ucomisd xmm0,xmm6                                          ; 1c6f
    jnc short loc_1c40                                          ; 1c73
    cmp r15,0x1                                                ; 1c75
    jnz short loc_1c40                                          ; 1c79
    ucomisd xmm9,xmm6                                          ; 1c7b
    setpo al                                                   ; 1c80
    setz cl                                                    ; 1c83
    test cl,al                                                 ; 1c86
    jnz short loc_1cb1                                          ; 1c88
    divsd xmm1,xmm9                                            ; 1c8a
    maxsd xmm1,xmm7                                            ; 1c8f
    movapd xmm0,xmm1                                           ; 1c93
    call $+5                                                   ; 1c97 | REL32 +1 exp addendLE=00000000
    mov r8,[rsp+0x250]                                         ; 1c9c
    mov rdx,[rsp+0x278]                                        ; 1ca4
    mulsd xmm0,xmm9                                            ; 1cac
loc_1cb1:
    ucomisd xmm9,xmm6                                          ; 1cb1
    jnz short loc_1c40                                          ; 1cb6
    jpe short loc_1c40                                          ; 1cb8
    xorpd xmm0,xmm8                                            ; 1cba
    jmp near loc_1c40                                           ; 1cbf
loc_1cc4:
    mov qword [rbp+0x0],0xffffffffffffffff                     ; 1cc4
    mov qword [rdi+0x78],0x4                                   ; 1ccc
    jmp near loc_2420                                           ; 1cd4
loc_1cd9:
    mov rcx,r12                                                ; 1cd9
    imul r12,rax,0x64                                          ; 1cdc
    add r12,0xa                                                ; 1ce0
    mov [rcx],r12                                              ; 1ce4
    cmp r15,0x2                                                ; 1ce7
    jng short loc_1d46                                          ; 1ceb
    mov qword [rsp+0x88],0x0                                   ; 1ced
    mov dword [rsp+0xc0],0x1010b                               ; 1cf9
    mov [rsp+0x110],rax                                        ; 1d04
    lea rax,[rel $+283]                                        ; 1d0c | REL32 +3 FUNEQ2$format_pack addendLE=14010000
    mov [rsp+0x28],rax                                         ; 1d13
    lea rax,[rsp+0x110]                                        ; 1d18
    mov [rsp+0x20],rax                                         ; 1d20
    lea rcx,[rsp+0x88]                                         ; 1d25
    mov r8,0x801208384ff00                                     ; 1d2d
    lea r9,[rsp+0xc0]                                          ; 1d37
    xor edx,edx                                                ; 1d3f
loc_1d41:
    call $+5                                                   ; 1d41 | REL32 +1 for_write_seq_fmt addendLE=00000000
loc_1d46:
    mov rdx,[rsp+0x278]                                        ; 1d46
    mov r10,[rsp+0x60]                                         ; 1d4e
    jmp near loc_228f                                           ; 1d53
loc_1d58:
    xorps xmm5,xmm5                                            ; 1d58
    sqrtsd xmm5,xmm2                                           ; 1d5b
    ucomisd xmm5,xmm0                                          ; 1d5f
    jnc near loc_1599                                           ; 1d63
    mov rdx,[rdi+0xa8]                                         ; 1d69
    mov rax,[rdi+0xb0]                                         ; 1d70
    lea rcx,[rdx+0x1]                                          ; 1d77
    mov [rdi+0xa8],rcx                                         ; 1d7b
    cmp rax,0x1                                                ; 1d82
    setz al                                                    ; 1d86
    ucomisd xmm0,xmm1                                          ; 1d89
    setnc cl                                                   ; 1d8d
    cmp rdx,0x1                                                ; 1d90
    jg near loc_1214                                            ; 1d94
    and al,cl                                                  ; 1d9a
    jz near loc_0a12                                            ; 1d9c
    jmp near loc_1214                                           ; 1da2
loc_1da7:
    mov r10,rbp                                                ; 1da7
    jmp near loc_228a                                           ; 1daa
loc_1daf:
    mov qword [r12],0x2                                        ; 1daf
    mov r12d,0x2                                               ; 1db7
    cmp qword [rel $+7],0x3                                    ; 1dbd | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jl short loc_1e2b                                           ; 1dc5
    mov rax,[rdi+0xa8]                                         ; 1dc7
    mov qword [rsp+0x88],0x0                                   ; 1dce
    mov edx,[rel $+6]                                          ; 1dda | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xd0],0x1010b                               ; 1de0
    mov [rsp+0x130],rax                                        ; 1deb
    lea rax,[rel $+835]                                        ; 1df3 | REL32 +3 FUNEQ2$format_pack addendLE=3c030000
    mov [rsp+0x28],rax                                         ; 1dfa
    lea rax,[rsp+0x130]                                        ; 1dff
    mov [rsp+0x20],rax                                         ; 1e07
    lea rcx,[rsp+0x88]                                         ; 1e0c
    mov r8,0x801208384ff00                                     ; 1e14
    lea r9,[rsp+0xd0]                                          ; 1e1e
    jmp near loc_24ca                                           ; 1e26
loc_1e2b:
    mov rdx,[rsp+0x278]                                        ; 1e2b
    jmp near loc_228f                                           ; 1e33
loc_1e38:
    minsd xmm1,xmm0                                            ; 1e38
    movsd xmm6,qword [rel $+8]                                 ; 1e3c | REL32 +4 __real@3fe0000000000000 addendLE=00000000
    movsd xmm2,qword [r14+0x58]                                ; 1e44
    mulsd xmm2,xmm6                                            ; 1e4a
    ucomisd xmm2,xmm1                                          ; 1e4e
    seta r8b                                                   ; 1e52
    cmp rax,0x4                                                ; 1e56
    jl near loc_1eea                                            ; 1e5a
    test r8b,r8b                                               ; 1e60
    jz near loc_1eea                                            ; 1e63
loc_1e69:
    ucomisd xmm0,qword [r14+0x50]                              ; 1e69
    mov rdx,[rsp+0x278]                                        ; 1e6f
    mov r9,[rsp+0x280]                                         ; 1e77
    ja near loc_21e5                                            ; 1e7f
    test r15,r15                                               ; 1e85
    jng near loc_21e5                                           ; 1e88
    cmp r15,0xd                                                ; 1e8e
    jc near loc_21c5                                            ; 1e92
    lea rbp,[r15*8+0x0]                                        ; 1e98
    mov rcx,rdx                                                ; 1ea0
    mov rdx,rbx                                                ; 1ea3
    mov r8,rbp                                                 ; 1ea6
    call $+5                                                   ; 1ea9 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov rcx,[rsp+0x280]                                        ; 1eae
    mov rdx,[rsp+0x68]                                         ; 1eb6
    mov r8,rbp                                                 ; 1ebb
    mov rbp,[rsp+0x68]                                         ; 1ebe
    call $+5                                                   ; 1ec3 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 1ec8
    mov r11,[rsp+0x250]                                        ; 1ecd
    mov r9,[rsp+0x280]                                         ; 1ed5
    mov rdx,[rsp+0x278]                                        ; 1edd
    jmp near loc_21e5                                           ; 1ee5
loc_1eea:
    mov rcx,[rdi+0x80]                                         ; 1eea
    mov r10,0x6666666666666667                                 ; 1ef1
    mov rax,rcx                                                ; 1efb
    imul r10                                                   ; 1efe
    mov rax,rdx                                                ; 1f01
    shr rax,byte 0x3f                                          ; 1f04
    sar rdx,byte 0x2                                           ; 1f08
    add rdx,rax                                                ; 1f0c
    add rdx,rdx                                                ; 1f0f
    lea rax,[rdx+rdx*4]                                        ; 1f12
    mov r9,rcx                                                 ; 1f16
    sub r9,rax                                                 ; 1f19
    neg rax                                                    ; 1f1c
    add rax,rcx                                                ; 1f1f
    add rax,0x13                                               ; 1f22
    mov [rel $+7],rax                                          ; 1f26 | REL32 +3 FUNEQ2$I1 addendLE=00000000
    mov rax,[rdi+0x98]                                         ; 1f2d
    add rax,0xc                                                ; 1f34
    cmp rcx,rax                                                ; 1f38
    jnl short loc_1f4e                                          ; 1f3b
    lea rax,[r14+r9*8]                                         ; 1f3d
    add rax,0x90                                               ; 1f41
    mov r10,[rsp+0x60]                                         ; 1f47
    jmp short loc_1faf                                          ; 1f4c
loc_1f4e:
    add rcx,0x5                                                ; 1f4e
    mov rax,rcx                                                ; 1f52
    imul r10                                                   ; 1f55
    mov rax,rdx                                                ; 1f58
    shr rax,byte 0x3f                                          ; 1f5b
    sar rdx,byte 0x2                                           ; 1f5f
    add rdx,rax                                                ; 1f63
    add rdx,rdx                                                ; 1f66
    lea rax,[rdx+rdx*4]                                        ; 1f69
    sub rcx,rax                                                ; 1f6d
    movsd xmm2,qword [r14+rcx*8+0x90]                          ; 1f70
    movapd xmm3,xmm1                                           ; 1f7a
    divsd xmm3,xmm2                                            ; 1f7e
    mulsd xmm3,xmm3                                            ; 1f82
    divsd xmm2,[r14+r9*8+0x90]                                 ; 1f86
    ucomisd xmm3,xmm2                                          ; 1f90
    seta al                                                    ; 1f94
    test al,r8b                                                ; 1f97
    mov r10,[rsp+0x60]                                         ; 1f9a
    jnz near loc_1e69                                           ; 1f9f
    lea rax,[r14+r9*8]                                         ; 1fa5
    add rax,0x90                                               ; 1fa9
loc_1faf:
    lea rbp,[rdi+0x80]                                         ; 1faf
    movsd qword [rax],xmm1                                     ; 1fb6
    lea rax,[rel $+7]                                          ; 1fba | REL32 +3 FUNEQ2$LPRINT addendLE=00000000
    mov [rsp+0x30],rax                                         ; 1fc1
    lea rax,[rel $+7]                                          ; 1fc6 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    mov [rsp+0x28],rax                                         ; 1fcd
    mov rax,[rsp+0x68]                                         ; 1fd2
    mov [rsp+0x20],rax                                         ; 1fd7
    lea r8,[rel $+7]                                           ; 1fdc | REL32 +3 FUNEQ2$FNORMN addendLE=00000000
    mov rcx,r10                                                ; 1fe3
    mov rdx,rbp                                                ; 1fe6
    mov r9,rbx                                                 ; 1fe9
    call $+5                                                   ; 1fec | REL32 +1 FUNEQ8 addendLE=00000000
    movsd xmm0,qword [rel $+8]                                 ; 1ff1 | REL32 +4 FUNEQ2$FNORMN addendLE=00000000
    movsd xmm1,qword [rel $+8]                                 ; 1ff9 | REL32 +4 FUNEQ2$FNORM addendLE=00000000
    movapd xmm3,xmm0                                           ; 2001
    divsd xmm3,xmm1                                            ; 2005
    movsd xmm4,qword [rel $+8]                                 ; 2009 | REL32 +4 FUNEQ2$FNORMP addendLE=00000000
    divsd xmm4,xmm1                                            ; 2011
    movsd xmm2,qword [rel $+8]                                 ; 2015 | REL32 +4 __real@408f400000000000 addendLE=00000000
    ucomisd xmm3,xmm2                                          ; 201d
    ja short loc_2027                                           ; 2021
    movapd xmm2,xmm3                                           ; 2023
loc_2027:
    cmp qword [rdi+0x90],0x1                                   ; 2027
    mov rdx,[rsp+0x278]                                        ; 202f
    mov r8,[rsp+0x280]                                         ; 2037
    mov r11,[rsp+0x250]                                        ; 203f
    mov r10,[rsp+0x60]                                         ; 2047
    jnz short loc_208a                                          ; 204c
    cmp qword [rdi+0x88],0x1                                   ; 204e
    movsd xmm3,qword [rel $+8]                                 ; 2056 | REL32 +4 FUNEQ2$STEP addendLE=00000000
    jnz short loc_2066                                          ; 205e
    movsd qword [r14+0x68],xmm3                                ; 2060
loc_2066:
    movsd xmm5,qword [rel $+8]                                 ; 2066 | REL32 +4 __real@3eb0c6f7a0b5ed8d addendLE=00000000
    mulsd xmm5,xmm3                                            ; 206e
    maxsd xmm5,[rel $+8]                                       ; 2072 | REL32 +4 __real@3e112e0be826d695 addendLE=00000000
    movsd qword [r14+0x70],xmm5                                ; 207a
    ucomisd xmm1,xmm0                                          ; 2080
    jna near loc_24e1                                           ; 2084
loc_208a:
    mulsd xmm2,xmm2                                            ; 208a
    movsd xmm5,qword [rel $+8]                                 ; 208e | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    movapd xmm3,xmm5                                           ; 2096
    subsd xmm3,xmm2                                            ; 209a
    mulsd xmm4,xmm4                                            ; 209e
    subsd xmm5,xmm4                                            ; 20a2
    mulsd xmm5,qword [rel $+8]                                 ; 20a6 | REL32 +4 __real@3fb999999999999a addendLE=00000000
    subsd xmm3,xmm5                                            ; 20ae
    xorpd xmm2,xmm2                                            ; 20b2
    ucomisd xmm2,xmm3                                          ; 20b6
    ja short loc_2119                                           ; 20ba
    movsd xmm4,qword [rel $+8]                                 ; 20bc | REL32 +4 FUNEQ2$SP addendLE=00000000
    movapd xmm2,xmm4                                           ; 20c4
    mulsd xmm2,xmm4                                            ; 20c8
    movsd xmm5,qword [rel $+8]                                 ; 20cc | REL32 +4 FUNEQ2$SS addendLE=00000000
    mulsd xmm5,xmm5                                            ; 20d4
    mulsd xmm5,xmm3                                            ; 20d8
    addsd xmm5,xmm2                                            ; 20dc
    xorps xmm2,xmm2                                            ; 20e0
    sqrtsd xmm2,xmm5                                           ; 20e3
    addsd xmm2,xmm4                                            ; 20e7
    movsd xmm4,qword [rel $+8]                                 ; 20eb | REL32 +4 __real@4030000000000000 addendLE=00000000
    mulsd xmm4,xmm2                                            ; 20f3
    ucomisd xmm3,xmm4                                          ; 20f7
    jna short loc_2109                                          ; 20fb
    movapd xmm2,xmm3                                           ; 20fd
    divsd xmm2,[rel $+8]                                       ; 2101 | REL32 +4 __real@4030000000000000 addendLE=00000000
loc_2109:
    divsd xmm3,xmm2                                            ; 2109
    addsd xmm3,[rel $+8]                                       ; 210d | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    sqrtsd xmm6,xmm3                                           ; 2115
loc_2119:
    movapd xmm2,xmm6                                           ; 2119
    minsd xmm2,[r14+0x78]                                      ; 211d
    movsd xmm3,qword [rel $+8]                                 ; 2123 | REL32 +4 FUNEQ2$STEP addendLE=00000000
    mulsd xmm3,xmm2                                            ; 212b
    maxsd xmm3,[r14+0x70]                                      ; 212f
    movsd qword [r14+0x60],xmm3                                ; 2135
    divsd xmm6,xmm2                                            ; 213b
    minsd xmm6,[rel $+8]                                       ; 213f | REL32 +4 __real@4000000000000000 addendLE=00000000
    movsd qword [r14+0x78],xmm6                                ; 2147
loc_214d:
    ucomisd xmm0,xmm1                                          ; 214d
    jc short loc_215e                                           ; 2151
    mov qword [rdi+0xb0],0x0                                   ; 2153
loc_215e:
    ucomisd xmm0,xmm1                                          ; 215e
    ja near loc_2570                                            ; 2162
    movsd qword [r14+0x50],xmm0                                ; 2168
    mov r15,[r10]                                              ; 216e
    test r15,r15                                               ; 2171
    jng near loc_2570                                           ; 2174
    cmp r15,0xd                                                ; 217a
    jc near loc_254c                                            ; 217e
    shl r15,byte 0x3                                           ; 2184
    mov rcx,rdx                                                ; 2188
    mov rdx,rbx                                                ; 218b
    mov r8,r15                                                 ; 218e
    call $+5                                                   ; 2191 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov rcx,[rsp+0x280]                                        ; 2196
    mov rdx,[rsp+0x68]                                         ; 219e
    mov r8,r15                                                 ; 21a3
    call $+5                                                   ; 21a6 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 21ab
    mov r11,[rsp+0x250]                                        ; 21b0
    mov rdx,[rsp+0x278]                                        ; 21b8
    jmp near loc_2570                                           ; 21c0
loc_21c5:
    xor eax,eax                                                ; 21c5
loc_21c7:
    movsd xmm0,qword [rbx+rax*8]                               ; 21c7
    movsd qword [rdx+rax*8],xmm0                               ; 21cc
    movsd xmm0,qword [rbp+rax*8+0x0]                           ; 21d1
    movsd qword [r9+rax*8],xmm0                                ; 21d7
    inc rax                                                    ; 21dd
    cmp r15,rax                                                ; 21e0
    jnz short loc_21c7                                          ; 21e3
loc_21e5:
    mov rax,[rdi+0x88]                                         ; 21e5
    cmp rax,[rdi+0x30]                                         ; 21ec
    jnl near loc_2456                                           ; 21f0
    mov rax,[rdi+0x28]                                         ; 21f6
    cmp [rdi+0x80],rax                                         ; 21fa
    jl near loc_0ba6                                            ; 2201
loc_2207:
    mov qword [r12],0x6                                        ; 2207
    mov r12d,0x6                                               ; 220f
    cmp qword [rel $+7],0x3                                    ; 2215 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jl short loc_228a                                           ; 221d
    mov qword [rsp+0x88],0x0                                   ; 221f
    mov edx,[rel $+6]                                          ; 222b | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xc8],0x1010b                               ; 2231
    mov [rsp+0x120],rax                                        ; 223c
    lea rax,[rel $+523]                                        ; 2244 | REL32 +3 FUNEQ2$format_pack addendLE=04020000
    mov [rsp+0x28],rax                                         ; 224b
    lea rax,[rsp+0x120]                                        ; 2250
    mov [rsp+0x20],rax                                         ; 2258
    lea rcx,[rsp+0x88]                                         ; 225d
    mov r8,0x801208384ff00                                     ; 2265
    lea r9,[rsp+0xc8]                                          ; 226f
    mov r15,r10                                                ; 2277
    call $+5                                                   ; 227a | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,r15                                                ; 227f
    mov rdx,[rsp+0x278]                                        ; 2282
loc_228a:
    mov rbp,[rsp+0x68]                                         ; 228a
loc_228f:
    movsd xmm6,qword [r14+0x50]                                ; 228f
    add r14,0x50                                               ; 2295
    movsd xmm0,qword [rel $+8]                                 ; 2299 | REL32 +4 FUNEQ2$FNORMN addendLE=00000000
    ucomisd xmm6,xmm0                                          ; 22a1
    jnc short loc_2321                                          ; 22a5
    movsd qword [rel $+8],xmm6                                 ; 22a7 | REL32 +4 FUNEQ2$FNORMN addendLE=00000000
    mov r15,[r10]                                              ; 22af
    test r15,r15                                               ; 22b2
    jng short loc_231d                                          ; 22b5
    cmp r15,0xd                                                ; 22b7
    jc short loc_22e7                                           ; 22bb
    shl r15,byte 0x3                                           ; 22bd
    mov rcx,rbx                                                ; 22c1
    mov r8,r15                                                 ; 22c4
    mov r13,r10                                                ; 22c7
    call $+5                                                   ; 22ca | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov rcx,rbp                                                ; 22cf
    mov rdx,[rsp+0x280]                                        ; 22d2
    mov r8,r15                                                 ; 22da
    call $+5                                                   ; 22dd | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r10,r13                                                ; 22e2
    jmp short loc_231d                                          ; 22e5
loc_22e7:
    xor eax,eax                                                ; 22e7
    mov rcx,[rsp+0x280]                                        ; 22e9
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 22f1 | nop word [cs:rax+rax+0x0]
loc_2300:
    movsd xmm0,qword [rdx+rax*8]                               ; 2300
    movsd qword [rbx+rax*8],xmm0                               ; 2305
    movsd xmm0,qword [rcx+rax*8]                               ; 230a
    movsd qword [rbp+rax*8+0x0],xmm0                           ; 230f
    inc rax                                                    ; 2315
    cmp r15,rax                                                ; 2318
    jnz short loc_2300                                          ; 231b
loc_231d:
    movapd xmm0,xmm6                                           ; 231d
loc_2321:
    movsd qword [r14],xmm0                                     ; 2321
    mov rax,[rel $+7]                                          ; 2326 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    cmp rax,0x3                                                ; 232d
    setnl cl                                                   ; 2331
    cmp r12,0x2                                                ; 2334
    setnl dl                                                   ; 2338
    cmp rax,0x6                                                ; 233b
    jg short loc_2345                                           ; 233f
    and cl,dl                                                  ; 2341
    jz short loc_2355                                           ; 2343
loc_2345:
    mov qword [rel $+7],0x9                                    ; 2345 | REL32 +3 FUNEQ2$LDIAG addendLE=fcffffff
    mov eax,0x9                                                ; 2350
loc_2355:
    cmp r12,0x2                                                ; 2355
    jl short loc_23b1                                           ; 2359
    cmp rax,0x3                                                ; 235b
    jl short loc_23b1                                           ; 235f
    mov qword [rsp+0x88],0x0                                   ; 2361
    mov edx,[rel $+6]                                          ; 236d | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov word [rsp+0x7e],0x1                                    ; 2373
    lea rax,[rel $+7]                                          ; 237a | REL32 +3 FUNEQ2$format_pack addendLE=00000000
    mov [rsp+0x28],rax                                         ; 2381
    mov qword [rsp+0x20],0x0                                   ; 2386
    lea rcx,[rsp+0x88]                                         ; 238f
    mov r8,0x801208384ff00                                     ; 2397
    lea r9,[rsp+0x7e]                                          ; 23a1
    mov r15,r10                                                ; 23a6
    call $+5                                                   ; 23a9 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,r15                                                ; 23ae
loc_23b1:
    sub rdi,0xffffffffffffff80                                 ; 23b1
    lea rax,[rel $+7]                                          ; 23b5 | REL32 +3 FUNEQ2$LPRINT addendLE=00000000
    mov [rsp+0x30],rax                                         ; 23bc
    lea rax,[rel $+7]                                          ; 23c1 | REL32 +3 FUNEQ2$LDIAG addendLE=00000000
    mov [rsp+0x28],rax                                         ; 23c8
    mov [rsp+0x20],rbp                                         ; 23cd
    mov rcx,r10                                                ; 23d2
    mov rdx,rdi                                                ; 23d5
    mov r8,r14                                                 ; 23d8
    mov r9,rbx                                                 ; 23db
    mov rdi,r10                                                ; 23de
    call $+5                                                   ; 23e1 | REL32 +1 FUNEQ8 addendLE=00000000
    mov r8,[rdi]                                               ; 23e6
    test r8,r8                                                 ; 23e9
    jng short loc_2420                                          ; 23ec
    cmp r8,0xd                                                 ; 23ee
    jc short loc_2404                                           ; 23f2
    shl r8,byte 0x3                                            ; 23f4
    mov rcx,rsi                                                ; 23f8
    xor edx,edx                                                ; 23fb
    call $+5                                                   ; 23fd | REL32 +1 _intel_fast_memset addendLE=00000000
    jmp short loc_2420                                          ; 2402
loc_2404:
    xor eax,eax                                                ; 2404
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 2406 | nop word [cs:rax+rax+0x0]
loc_2410:
    mov qword [rsi+rax*8],0x0                                  ; 2410
    inc rax                                                    ; 2418
    cmp r8,rax                                                 ; 241b
    jnz short loc_2410                                          ; 241e
loc_2420:
    movaps xmm6,oword [rsp+0x1a0]                              ; 2420
    movaps xmm7,oword [rsp+0x1b0]                              ; 2428
    movaps xmm8,oword [rsp+0x1c0]                              ; 2430
    movaps xmm9,oword [rsp+0x1d0]                              ; 2439
    add rsp,0x1e8                                              ; 2442
    pop rbx                                                    ; 2449
    pop rbp                                                    ; 244a
    pop rdi                                                    ; 244b
    pop rsi                                                    ; 244c
    pop r12                                                    ; 244d
    pop r13                                                    ; 244f
    pop r14                                                    ; 2451
    pop r15                                                    ; 2453
    retq                                                       ; 2455
loc_2456:
    mov qword [r12],0x5                                        ; 2456
    mov r12d,0x5                                               ; 245e
    cmp qword [rel $+7],0x2                                    ; 2464 | REL32 +3 FUNEQ2$LDIAG addendLE=ffffffff
    jng near loc_228f                                           ; 246c
    mov qword [rsp+0x88],0x0                                   ; 2472
    mov edx,[rel $+6]                                          ; 247e | REL32 +2 FUNEQ2$LPRINT addendLE=00000000
    mov dword [rsp+0xcc],0x1010b                               ; 2484
    mov [rsp+0x128],rax                                        ; 248f
    lea rax,[rel $+615]                                        ; 2497 | REL32 +3 FUNEQ2$format_pack addendLE=60020000
    mov [rsp+0x28],rax                                         ; 249e
    lea rax,[rsp+0x128]                                        ; 24a3
    mov [rsp+0x20],rax                                         ; 24ab
    lea rcx,[rsp+0x88]                                         ; 24b0
    mov r8,0x801208384ff00                                     ; 24b8
    lea r9,[rsp+0xcc]                                          ; 24c2
loc_24ca:
    call $+5                                                   ; 24ca | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 24cf
    mov rdx,[rsp+0x278]                                        ; 24d4
    jmp near loc_228f                                           ; 24dc
loc_24e1:
    movsd xmm4,qword [rel $+8]                                 ; 24e1 | REL32 +4 __real@3ff199999999999a addendLE=00000000
    ucomisd xmm4,xmm2                                          ; 24e9
    ja near loc_214d                                            ; 24ed
    movsd xmm4,qword [rel $+8]                                 ; 24f3 | REL32 +4 FUNEQ2$DERATE addendLE=00000000
    movsd xmm5,qword [rel $+8]                                 ; 24fb | REL32 +4 __real@3fe0000000000000 addendLE=00000000
    movapd xmm6,xmm5                                           ; 2503
    mulsd xmm6,xmm4                                            ; 2507
    movapd xmm7,xmm2                                           ; 250b
    mulsd xmm7,xmm2                                            ; 250f
    addsd xmm7,xmm4                                            ; 2513
    subsd xmm7,qword [rel $+8]                                 ; 2517 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    divsd xmm6,xmm7                                            ; 251f
    minsd xmm6,xmm5                                            ; 2523
    maxsd xmm6,[rel $+8]                                       ; 2527 | REL32 +4 __real@3fb999999999999a addendLE=00000000
    mulsd xmm3,xmm6                                            ; 252f
    movsd qword [r14+0x60],xmm3                                ; 2533
    ucomisd xmm2,qword [rel $+8]                               ; 2539 | REL32 +4 __real@3ff8000000000000 addendLE=00000000
    ja near loc_1b42                                            ; 2541
    jmp near loc_214d                                           ; 2547
loc_254c:
    xor eax,eax                                                ; 254c
    mov rcx,[rsp+0x68]                                         ; 254e
loc_2553:
    movsd xmm0,qword [rbx+rax*8]                               ; 2553
    movsd qword [rdx+rax*8],xmm0                               ; 2558
    movsd xmm0,qword [rcx+rax*8]                               ; 255d
    movsd qword [r8+rax*8],xmm0                                ; 2562
    inc rax                                                    ; 2568
    cmp r15,rax                                                ; 256b
    jnz short loc_2553                                          ; 256e
loc_2570:
    mov qword [rdi+0x90],0x0                                   ; 2570
    cmp qword [rdi+0xb0],0x1                                   ; 257b
    jz near loc_1b42                                            ; 2583
    lea rcx,[rel $+7]                                          ; 2589 | REL32 +3 __unnamed_1 addendLE=00000000
    mov rdx,r10                                                ; 2590
    mov r8,[rsp+0x260]                                         ; 2593
    mov r15,[rsp+0x270]                                        ; 259b
    mov r9,r15                                                 ; 25a3
    call $+5                                                   ; 25a6 | REL32 +1 FUNEQ7 addendLE=00000000
    lea rax,[r14+0x8]                                          ; 25ab
    mov [rsp+0x28],rax                                         ; 25af
    mov rax,[rsp+0x290]                                        ; 25b4
    mov [rsp+0x20],rax                                         ; 25bc
    mov rcx,[rsp+0x60]                                         ; 25c1
    mov rdx,r15                                                ; 25c6
    mov r8,rsi                                                 ; 25c9
    mov r9,[rsp+0x288]                                         ; 25cc
    call $+5                                                   ; 25d4 | REL32 +1 FUNEQ5 addendLE=00000000
    mov r10,[rsp+0x60]                                         ; 25d9
    mov r11,[rsp+0x250]                                        ; 25de
    mov rdx,[rsp+0x278]                                        ; 25e6
    jmp near loc_1b42                                           ; 25ee

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x36,0x00,0x00,0x00,0x1c,0x00,0x2c,0x00,0x20,0x45,0x52,0x52,0x4f,0x52,0x20,0x52
    db 0x45,0x54,0x55,0x52,0x4e,0x20,0x46,0x52,0x4f,0x4d,0x20,0x4e,0x4f,0x4e,0x4c,0x49
    db 0x4e,0x45,0x41,0x52,0x20,0x45,0x51,0x55,0x41,0x54,0x49,0x4f,0x4e,0x20,0x53,0x4f
    db 0x4c,0x56,0x45,0x52,0x1c,0x00,0x0e,0x00,0x20,0x46,0x55,0x4e,0x45,0x51,0x32,0x2f
    db 0x46,0x55,0x4e,0x45,0x51,0x31,0x00,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00
    db 0x47,0x00,0x01,0x00,0x1c,0x00,0x0f,0x00,0x20,0x53,0x49,0x4e,0x47,0x55,0x4c,0x41
    db 0x52,0x20,0x2d,0x20,0x54,0x48,0x45,0x00,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x04,0x00,0x00,0x00,0x1c,0x00,0x1a,0x00,0x20,0x54,0x48,0x20,0x56,0x41,0x52,0x49
    db 0x41,0x42,0x4c,0x45,0x20,0x48,0x41,0x53,0x20,0x4e,0x4f,0x20,0x45,0x46,0x46,0x45
    db 0x43,0x54,0x00,0x00,0x1c,0x00,0x18,0x00,0x20,0x4f,0x4e,0x20,0x41,0x4e,0x59,0x20
    db 0x4f,0x46,0x20,0x54,0x48,0x45,0x20,0x46,0x55,0x4e,0x43,0x54,0x49,0x4f,0x4e,0x53
    db 0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x0f,0x00
    db 0x20,0x53,0x49,0x4e,0x47,0x55,0x4c,0x41,0x52,0x20,0x2d,0x20,0x54,0x48,0x45,0x00
    db 0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1c,0x00,0x1c,0x00
    db 0x20,0x54,0x48,0x20,0x46,0x55,0x4e,0x43,0x54,0x49,0x4f,0x4e,0x20,0x49,0x53,0x20
    db 0x4e,0x4f,0x54,0x20,0x41,0x46,0x46,0x45,0x43,0x54,0x45,0x44,0x1c,0x00,0x10,0x00
    db 0x20,0x42,0x59,0x20,0x41,0x4e,0x59,0x20,0x56,0x41,0x52,0x49,0x41,0x42,0x4c,0x45
    db 0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x13,0x00
    db 0x20,0x43,0x41,0x4e,0x4e,0x4f,0x54,0x20,0x50,0x45,0x52,0x54,0x55,0x52,0x42,0x20
    db 0x54,0x48,0x45,0x00,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00
    db 0x1c,0x00,0x24,0x00,0x20,0x54,0x48,0x20,0x56,0x41,0x52,0x49,0x41,0x42,0x4c,0x45
    db 0x20,0x46,0x4f,0x52,0x20,0x4a,0x41,0x43,0x4f,0x42,0x49,0x41,0x4e,0x20,0x45,0x56
    db 0x41,0x4c,0x55,0x41,0x54,0x49,0x4f,0x4e,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00
    db 0x47,0x00,0x01,0x00,0x1c,0x00,0x2c,0x00,0x20,0x46,0x55,0x4e,0x43,0x54,0x49,0x4f
    db 0x4e,0x20,0x49,0x53,0x20,0x55,0x4e,0x44,0x45,0x46,0x49,0x4e,0x45,0x44,0x20,0x41
    db 0x54,0x20,0x54,0x48,0x45,0x20,0x53,0x54,0x41,0x52,0x54,0x49,0x4e,0x47,0x20,0x50
    db 0x4f,0x49,0x4e,0x54,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00
    db 0x1c,0x00,0x21,0x00,0x20,0x4a,0x41,0x43,0x4f,0x42,0x49,0x41,0x4e,0x20,0x4d,0x41
    db 0x54,0x52,0x49,0x58,0x20,0x42,0x45,0x43,0x4f,0x4d,0x45,0x20,0x53,0x49,0x4e,0x47
    db 0x55,0x4c,0x41,0x52,0x2c,0x00,0x00,0x00,0x1c,0x00,0x18,0x00,0x20,0x53,0x49,0x4e
    db 0x47,0x55,0x4c,0x41,0x52,0x49,0x54,0x59,0x20,0x50,0x41,0x52,0x41,0x4d,0x45,0x54
    db 0x45,0x52,0x20,0x3d,0x1f,0x00,0x00,0x06,0x01,0x00,0x00,0x00,0x0d,0x00,0x00,0x00
    db 0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x2d,0x00
    db 0x20,0x53,0x55,0x42,0x52,0x4f,0x55,0x54,0x49,0x4e,0x45,0x20,0x46,0x55,0x4e,0x45
    db 0x51,0x32,0x20,0x44,0x49,0x44,0x20,0x4e,0x4f,0x54,0x20,0x46,0x49,0x4e,0x44,0x20
    db 0x41,0x20,0x53,0x4f,0x4c,0x55,0x54,0x49,0x4f,0x4e,0x20,0x49,0x4e,0x00,0x00,0x00
    db 0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1c,0x00,0x0b,0x00
    db 0x20,0x49,0x54,0x45,0x52,0x41,0x54,0x49,0x4f,0x4e,0x53,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x2d,0x00,0x20,0x53,0x55,0x42
    db 0x52,0x4f,0x55,0x54,0x49,0x4e,0x45,0x20,0x46,0x55,0x4e,0x45,0x51,0x32,0x20,0x44
    db 0x49,0x44,0x20,0x4e,0x4f,0x54,0x20,0x46,0x49,0x4e,0x44,0x20,0x41,0x20,0x53,0x4f
    db 0x4c,0x55,0x54,0x49,0x4f,0x4e,0x20,0x49,0x4e,0x00,0x00,0x00,0x24,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x1c,0x00,0x15,0x00,0x20,0x4a,0x41,0x43
    db 0x4f,0x42,0x49,0x41,0x4e,0x20,0x45,0x56,0x41,0x4c,0x55,0x41,0x54,0x49,0x4f,0x4e
    db 0x53,0x00,0x00,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00
    db 0x1c,0x00,0x20,0x00,0x20,0x56,0x45,0x52,0x59,0x20,0x53,0x4c,0x4f,0x57,0x20,0x43
    db 0x4f,0x4e,0x56,0x45,0x52,0x47,0x45,0x4e,0x43,0x45,0x20,0x49,0x4e,0x20,0x46,0x55
    db 0x4e,0x45,0x51,0x32,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00
    db 0x1c,0x00,0x32,0x00,0x20,0x56,0x45,0x52,0x59,0x20,0x53,0x4d,0x41,0x4c,0x4c,0x20
    db 0x53,0x54,0x45,0x50,0x20,0x50,0x4f,0x53,0x53,0x49,0x42,0x4c,0x59,0x20,0x44,0x55
    db 0x45,0x20,0x54,0x4f,0x20,0x42,0x4f,0x55,0x4e,0x44,0x20,0x43,0x4f,0x4e,0x53,0x54
    db 0x52,0x41,0x49,0x4e,0x54,0x53,0x00,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00
    db 0x47,0x00,0x01,0x00,0x1c,0x00,0x1d,0x00,0x20,0x54,0x48,0x45,0x20,0x53,0x4f,0x4c
    db 0x55,0x54,0x49,0x4f,0x4e,0x20,0x58,0x20,0x48,0x41,0x53,0x20,0x43,0x4f,0x4e,0x56
    db 0x45,0x52,0x47,0x45,0x44,0x00,0x00,0x00,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x02,0x00,0x00,0x00,0x1c,0x00,0x06,0x00,0x20,0x54,0x49,0x4d,0x45,0x53,0x00,0x00
    db 0x47,0x00,0x01,0x00,0x1c,0x00,0x2a,0x00,0x20,0x42,0x55,0x54,0x20,0x46,0x55,0x4e
    db 0x43,0x54,0x49,0x4f,0x4e,0x20,0x49,0x53,0x20,0x53,0x54,0x49,0x4c,0x4c,0x20,0x54
    db 0x4f,0x4f,0x20,0x42,0x49,0x47,0x20,0x2d,0x2d,0x20,0x53,0x4f,0x4c,0x55,0x54,0x49
    db 0x4f,0x4e,0x00,0x00,0x1c,0x00,0x11,0x00,0x20,0x4d,0x41,0x59,0x20,0x42,0x45,0x20
    db 0x49,0x4e,0x43,0x4f,0x52,0x52,0x45,0x43,0x54,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x1e,0x00,0x20,0x46,0x55,0x4e
    db 0x45,0x51,0x32,0x20,0x46,0x4f,0x55,0x4e,0x44,0x20,0x41,0x20,0x53,0x4f,0x4c,0x55
    db 0x54,0x49,0x4f,0x4e,0x20,0x41,0x46,0x54,0x45,0x52,0x00,0x00,0x24,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1c,0x00,0x0f,0x00,0x20,0x49,0x54,0x45
    db 0x52,0x41,0x54,0x49,0x4f,0x4e,0x53,0x20,0x41,0x4e,0x44,0x00,0x24,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x1c,0x00,0x15,0x00,0x20,0x4a,0x41,0x43
    db 0x4f,0x42,0x49,0x41,0x4e,0x20,0x45,0x56,0x41,0x4c,0x55,0x41,0x54,0x49,0x4f,0x4e
    db 0x53,0x00,0x00,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x1c,0x00,0x06,0x00
    db 0x20,0x44,0x49,0x41,0x47,0x46,0x00,0x00,0x1f,0x00,0x00,0x06,0x05,0x00,0x00,0x00
    db 0x0e,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x38,0x00,0x01,0x00,0x0e,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1f,0x00,0x00,0x06,0x05,0x00,0x00,0x00
    db 0x0e,0x00,0x00,0x00,0x39,0x00,0x00,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00
    db 0x1c,0x00,0x06,0x00,0x20,0x44,0x49,0x41,0x47,0x58,0x00,0x00,0x1f,0x00,0x00,0x06
    db 0x05,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x38,0x00,0x01,0x00
    db 0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x1f,0x00,0x00,0x06
    db 0x05,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x39,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x20,0x00,0x20,0x2a,0x2a,0x2a
    db 0x20,0x52,0x45,0x55,0x53,0x45,0x20,0x50,0x52,0x45,0x56,0x49,0x4f,0x55,0x53,0x20
    db 0x4a,0x41,0x43,0x4f,0x42,0x49,0x41,0x4e,0x20,0x2a,0x2a,0x2a,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x1c,0x00,0x20,0x2a,0x2a,0x2a
    db 0x20,0x4a,0x41,0x43,0x4f,0x42,0x49,0x41,0x4e,0x20,0x45,0x56,0x41,0x4c,0x55,0x41
    db 0x54,0x49,0x4f,0x4e,0x20,0x4e,0x4f,0x2e,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x03,0x00,0x00,0x00,0x1c,0x00,0x04,0x00,0x20,0x2a,0x2a,0x2a,0x37,0x00,0x00,0x00

; .rdata (COFF section 4)
coff_section_4:
    db 0xea,0x8c,0xa0,0x39,0x59,0x3e,0x29,0x46

; .rdata (COFF section 5)
coff_section_5:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xd0,0x3f

; .rdata (COFF section 6)
coff_section_6:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40

; .rdata (COFF section 7)
coff_section_7:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80

; .rdata (COFF section 8)
coff_section_8:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .rdata (COFF section 9)
coff_section_9:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f

; .rdata (COFF section 10)
coff_section_10:
    db 0x2b,0x87,0x16,0xd9,0xce,0xf7,0xef,0x3f

; .rdata (COFF section 11)
coff_section_11:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x3f

; .rdata (COFF section 12)
coff_section_12:
    db 0x00,0x00,0x00,0x00,0x00,0x40,0x8f,0x40

; .rdata (COFF section 13)
coff_section_13:
    db 0x8d,0xed,0xb5,0xa0,0xf7,0xc6,0xb0,0x3e

; .rdata (COFF section 14)
coff_section_14:
    db 0x95,0xd6,0x26,0xe8,0x0b,0x2e,0x11,0x3e

; .rdata (COFF section 15)
coff_section_15:
    db 0x9a,0x99,0x99,0x99,0x99,0x99,0xf1,0x3f

; .rdata (COFF section 16)
coff_section_16:
    db 0x9a,0x99,0x99,0x99,0x99,0x99,0xb9,0x3f

; .rdata (COFF section 17)
coff_section_17:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x3f

; .rdata (COFF section 18)
coff_section_18:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x40

; .rdata (COFF section 19)
coff_section_19:
    db 0x7b,0x14,0xae,0x47,0xe1,0x7a,0x84,0x3f

; .rdata (COFF section 20)
coff_section_20:
    db 0x2d,0x43,0x1c,0xeb,0xe2,0x36,0x1a,0x3f

; .rdata (COFF section 21)
coff_section_21:
    db 0xfc,0xa9,0xf1,0xd2,0x4d,0x62,0x50,0x3f

; .rdata (COFF section 22)
coff_section_22:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x40

; .rdata (COFF section 23)
coff_section_23:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x40

; .rdata (COFF section 24)
coff_section_24:
    db 0xf1,0x68,0xe3,0x88,0xb5,0xf8,0xe4,0x3e

; .rdata (COFF section 25)
coff_section_25:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x40

; .rdata (COFF section 26)
coff_section_26:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0

; .rdata (COFF section 27)
coff_section_27:
    dd 0x0000037b ; REL32 .text (COFF symbol 0)
    dd 0x00000ae4 ; REL32 .text (COFF symbol 0)
    dd 0x00000743 ; REL32 .text (COFF symbol 0)
    dd 0x0000074f ; REL32 .text (COFF symbol 0)
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

; .xdata (COFF section 28)
coff_section_28:
    db 0x01,0x39,0x12,0x00,0x39,0x68,0x1a,0x00,0x30,0x78,0x1b,0x00,0x27,0x88,0x1c,0x00
    db 0x1d,0x98,0x1d,0x00,0x13,0x01,0x3d,0x00,0x0c,0x30,0x0b,0x50,0x0a,0x70,0x09,0x60
    db 0x08,0xc0,0x06,0xd0,0x04,0xe0,0x02,0xf0

; .drectve (COFF section 29)
coff_section_29:
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

; .pdata (COFF section 30)
coff_section_30:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x000025f3 ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 77)
