; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

SPNCAZ:
    push rbp                                                   ; 0000
    push r15                                                   ; 0001
    push r14                                                   ; 0003
    push r13                                                   ; 0005
    push r12                                                   ; 0007
    push rsi                                                   ; 0009
    push rdi                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x468                                              ; 000c
    lea rbp,[rsp+0x80]                                         ; 0013
    movapd oword [rbp+0x3d0],xmm15                             ; 001b
    movapd oword [rbp+0x3c0],xmm14                             ; 0024
    movapd oword [rbp+0x3b0],xmm13                             ; 002d
    movapd oword [rbp+0x3a0],xmm12                             ; 0036
    movapd oword [rbp+0x390],xmm11                             ; 003f
    movapd oword [rbp+0x380],xmm10                             ; 0048
    movapd oword [rbp+0x370],xmm9                              ; 0051
    movapd oword [rbp+0x360],xmm8                              ; 005a
    movapd oword [rbp+0x350],xmm7                              ; 0063
    movapd oword [rbp+0x340],xmm6                              ; 006b
    mov [rbp+0x308],r9                                         ; 0073
    mov r13,r8                                                 ; 007a
    mov r15,0x801208384ff00                                    ; 007d
    mov r12,[r8]                                               ; 0087
    xor eax,eax                                                ; 008a
    test r12,r12                                               ; 008c
    cmovg rax,r12                                              ; 008f
    lea r8,[rax*8+0xf]                                         ; 0093
    and r8,0xfffffffffffffff0                                  ; 009b
    mov rax,r8                                                 ; 009f
    call $+5                                                   ; 00a2 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00a7
    mov [rbp+0x2d0],rsp                                        ; 00aa
    mov rax,r8                                                 ; 00b1
    call $+5                                                   ; 00b4 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00b9
    mov [rbp+0x320],rsp                                        ; 00bc
    mov rax,r8                                                 ; 00c3
    call $+5                                                   ; 00c6 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00cb
    mov [rbp+0x2c8],rsp                                        ; 00ce
    mov rax,r8                                                 ; 00d5
    call $+5                                                   ; 00d8 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00dd
    mov [rbp+0x328],rsp                                        ; 00e0
    mov rax,r8                                                 ; 00e7
    call $+5                                                   ; 00ea | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00ef
    mov [rbp+0x330],rsp                                        ; 00f2
    mov byte [rel $+8],0x0                                     ; 00f9 | REL32 +2 SPNCAZ$FLASHTYPE addendLE=01000000
    mov word [rel $+7],0x5650                                  ; 0100 | REL32 +3 SPNCAZ$FLASHTYPE addendLE=feffffff
    mov dword [rel $+9],0x20202020                             ; 0109 | REL32 +2 SPNCAZ$FLASHTYPE addendLE=ffffffff
    mov dword [rel $+12],0x20202020                            ; 0113 | REL32 +2 SPNCAZ$FLASHTYPE addendLE=02000000
    mov qword [rel $+7],0x0                                    ; 011d | REL32 +3 SPNCAZ$VFRAC addendLE=fcffffff
    mov rdi,[rdx]                                              ; 0128
    cmp rdi,0x3                                                ; 012b
    mov [rbp+0x338],r13                                        ; 012f
    jng near loc_034f                                           ; 0136
    mov [rbp+0x2c0],rcx                                        ; 013c
    mov [rbp+0x318],rdi                                        ; 0143
    mov rax,[rbp+0x450]                                        ; 014a
    movsd xmm0,qword [rax]                                     ; 0151
    mov qword [rbp+0x2d8],0x0                                  ; 0155
    mov dword [rbp+0x1f8],0x10130                              ; 0160
    movsd qword [rbp+0x130],xmm0                               ; 016a
    sub rsp,0x30                                               ; 0172
    lea rax,[rel $+155]                                        ; 0176 | REL32 +3 SPNCAZ$format_pack addendLE=94000000
    mov [rsp+0x28],rax                                         ; 017d
    lea rax,[rbp+0x130]                                        ; 0182
    mov [rsp+0x20],rax                                         ; 0189
    lea rsi,[rbp+0x2d8]                                        ; 018e
    lea r9,[rbp+0x1f8]                                         ; 0195
    mov rcx,rsi                                                ; 019c
    xor edx,edx                                                ; 019f
    mov r8,r15                                                 ; 01a1
    call $+5                                                   ; 01a4 | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 01a9
    mov qword [rbp+0x2d8],0x0                                  ; 01ad
    mov word [rbp+0x316],0x1                                   ; 01b8
    sub rsp,0x30                                               ; 01c1
    lea rax,[rel $+115]                                        ; 01c5 | REL32 +3 SPNCAZ$format_pack addendLE=6c000000
    mov [rsp+0x28],rax                                         ; 01cc
    mov qword [rsp+0x20],0x0                                   ; 01d1
    lea r9,[rbp+0x316]                                         ; 01da
    mov rcx,rsi                                                ; 01e1
    xor edx,edx                                                ; 01e4
    mov r8,r15                                                 ; 01e6
    call $+5                                                   ; 01e9 | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 01ee
    mov rdi,[r13+0x0]                                          ; 01f2
    mov qword [rel $+7],0x1                                    ; 01f6 | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test rdi,rdi                                               ; 0201
    jng near loc_02d8                                           ; 0204
    xor eax,eax                                                ; 020a
    lea rbx,[rbp+0x1fc]                                        ; 020c
    lea r13,[rel $+7]                                          ; 0213 | REL32 +3 SPNCAZ$CNAME addendLE=00000000
    lea r14,[rbp+0x200]                                        ; 021a
    lea r12,[rbp-0x30]                                         ; 0221
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0225 | nop word [cs:rax+rax+0x0]
loc_0230:
    lea rcx,[rel $+7]                                          ; 0230 | REL32 +3 SPNCAZ$COMIDS addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 0237
    mov qword [rbp+0x2d8],0x0                                  ; 023b
    mov dword [rbp+0x1fc],0x20638                              ; 0246
    mov qword [rbp-0x78],0x8                                   ; 0250
    mov [rbp-0x70],rax                                         ; 0258
    mov qword [rbp-0x68],0x8                                   ; 025c
    sub rsp,0x30                                               ; 0264
    lea rax,[rel $+59]                                         ; 0268 | REL32 +3 SPNCAZ$format_pack addendLE=34000000
    mov [rsp+0x28],rax                                         ; 026f
    lea rax,[rbp-0x78]                                         ; 0274
    mov [rsp+0x20],rax                                         ; 0278
    mov rcx,rsi                                                ; 027d
    xor edx,edx                                                ; 0280
    mov r8,r15                                                 ; 0282
    mov r9,rbx                                                 ; 0285
    call $+5                                                   ; 0288 | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 028d
    mov dword [rbp+0x200],0x10438                              ; 0291
    mov qword [rbp-0x30],0x20                                  ; 029b
    mov [rbp-0x28],r13                                         ; 02a3
    sub rsp,0x20                                               ; 02a7
    mov rcx,rsi                                                ; 02ab
    mov rdx,r14                                                ; 02ae
    mov r8,r12                                                 ; 02b1
    call $+5                                                   ; 02b4 | REL32 +1 for_write_seq_fmt_xmit addendLE=00000000
    add rsp,0x20                                               ; 02b9
    mov rax,[rel $+7]                                          ; 02bd | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 02c4
    mov [rel $+7],rcx                                          ; 02c8 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    cmp rax,rdi                                                ; 02cf
    jl near loc_0230                                            ; 02d2
loc_02d8:
    mov rax,[rbp+0x308]                                        ; 02d8
    mov rax,[rax]                                              ; 02df
    mov qword [rbp+0x2d8],0x0                                  ; 02e2
    mov dword [rbp+0x204],0x1010b                              ; 02ed
    mov [rbp+0x138],rax                                        ; 02f7
    sub rsp,0x30                                               ; 02fe
    lea rax,[rel $+7]                                          ; 0302 | REL32 +3 SPNCAZ$format_pack addendLE=00000000
    mov [rsp+0x28],rax                                         ; 0309
    lea rax,[rbp+0x138]                                        ; 030e
    mov [rsp+0x20],rax                                         ; 0315
    lea rcx,[rbp+0x2d8]                                        ; 031a
    lea r9,[rbp+0x204]                                         ; 0321
    xor edx,edx                                                ; 0328
    mov r8,r15                                                 ; 032a
    call $+5                                                   ; 032d | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 0332
    mov r13,[rbp+0x338]                                        ; 0336
    mov r12,[r13+0x0]                                          ; 033d
    mov rdi,[rbp+0x318]                                        ; 0341
    mov rcx,[rbp+0x2c0]                                        ; 0348
loc_034f:
    mov r10,[rbp+0x488]                                        ; 034f
    mov r11,[rbp+0x458]                                        ; 0356
    cmp r12,0x2                                                ; 035d
    jnl short loc_03bc                                          ; 0361
    mov qword [rcx],0x1                                        ; 0363
    cmp rdi,0x1                                                ; 036a
    jng near loc_1f9b                                           ; 036e
    mov qword [rbp+0x2d8],0x0                                  ; 0374
    mov dword [rbp+0x208],0x10438                              ; 037f
    mov qword [rbp-0x20],0x47                                  ; 0389
    lea rax,[rel $+7]                                          ; 0391 | REL32 +3 strlit.40 addendLE=00000000
    mov [rbp-0x18],rax                                         ; 0398
    sub rsp,0x30                                               ; 039c
    lea rax,[rbp-0x20]                                         ; 03a0
    mov [rsp+0x20],rax                                         ; 03a4
    lea rcx,[rbp+0x2d8]                                        ; 03a9
    lea r9,[rbp+0x208]                                         ; 03b0
    jmp near loc_149a                                           ; 03b7
loc_03bc:
    cmp r12,0x14                                               ; 03bc
    jna short loc_041b                                          ; 03c0
    mov qword [rcx],0x1                                        ; 03c2
    cmp rdi,0x1                                                ; 03c9
    jng near loc_1f9b                                           ; 03cd
    mov qword [rbp+0x2d8],0x0                                  ; 03d3
    mov dword [rbp+0x20c],0x10438                              ; 03de
    mov qword [rbp-0x10],0x47                                  ; 03e8
    lea rax,[rel $+7]                                          ; 03f0 | REL32 +3 strlit.38 addendLE=00000000
    mov [rbp-0x8],rax                                          ; 03f7
    sub rsp,0x30                                               ; 03fb
    lea rax,[rbp-0x10]                                         ; 03ff
    mov [rsp+0x20],rax                                         ; 0403
    lea rcx,[rbp+0x2d8]                                        ; 0408
    lea r9,[rbp+0x20c]                                         ; 040f
    jmp near loc_149a                                           ; 0416
loc_041b:
    mov [rbp+0x318],rdi                                        ; 041b
    mov rdi,[rbp+0x480]                                        ; 0422
    mov rax,[rbp+0x470]                                        ; 0429
    mov rsi,[rbp+0x468]                                        ; 0430
    mov qword [rel $+7],0x1                                    ; 0437 | REL32 +3 SPNCAZ$IPARAM addendLE=fcffffff
    mov qword [rel $+15],0x2                                   ; 0442 | REL32 +3 SPNCAZ$IPARAM addendLE=04000000
    mov qword [rel $+23],0x2                                   ; 044d | REL32 +3 SPNCAZ$IPARAM addendLE=0c000000
    mov qword [rel $+31],0x3                                   ; 0458 | REL32 +3 SPNCAZ$IPARAM addendLE=14000000
    mov qword [rel $+39],0x0                                   ; 0463 | REL32 +3 SPNCAZ$IPARAM addendLE=1c000000
    mov qword [rel $+47],0x46                                  ; 046e | REL32 +3 SPNCAZ$IPARAM addendLE=24000000
    mov qword [rel $+55],0xa                                   ; 0479 | REL32 +3 SPNCAZ$IPARAM addendLE=2c000000
    mov qword [rel $+63],0x1                                   ; 0484 | REL32 +3 SPNCAZ$IPARAM addendLE=34000000
    mov qword [rel $+71],0x0                                   ; 048f | REL32 +3 SPNCAZ$IPARAM addendLE=3c000000
    mov qword [rel $+79],0x2                                   ; 049a | REL32 +3 SPNCAZ$IPARAM addendLE=44000000
    mov rdx,0x3f50624dd2f1a9fc                                 ; 04a5
    mov [rel $+7],rdx                                          ; 04af | REL32 +3 SPNCAZ$FPARAM addendLE=00000000
    mov rdx,0x3e45798ee2308c3a                                 ; 04b6
    mov [rel $+15],rdx                                         ; 04c0 | REL32 +3 SPNCAZ$FPARAM addendLE=08000000
    mov rdx,0x3eb0c6f7a0b5ed8d                                 ; 04c7
    mov [rel $+23],rdx                                         ; 04d1 | REL32 +3 SPNCAZ$FPARAM addendLE=10000000
    mov rdx,0x3fc999999999999a                                 ; 04d8
    mov [rel $+31],rdx                                         ; 04e2 | REL32 +3 SPNCAZ$FPARAM addendLE=18000000
    mov rdx,0x3fb999999999999a                                 ; 04e9
    mov [rel $+39],rdx                                         ; 04f3 | REL32 +3 SPNCAZ$FPARAM addendLE=20000000
    mov rdx,0x3fa999999999999a                                 ; 04fa
    mov [rel $+47],rdx                                         ; 0504 | REL32 +3 SPNCAZ$FPARAM addendLE=28000000
    mov [rel $+55],rdx                                         ; 050b | REL32 +3 SPNCAZ$FPARAM addendLE=30000000
    lea rbx,[r12+0x1]                                          ; 0512
    lea rdx,[rel $+7]                                          ; 0517 | REL32 +3 SPNCAZ$DIAGX addendLE=00000000
    mov r8,0x3ff0000000000000                                  ; 051e
    mov r9,r12                                                 ; 0528
    nop dword [byte rax+rax+0x0]                               ; 052b
loc_0530:
    mov [rdx],r8                                               ; 0530
    add rdx,0x8                                                ; 0533
    dec r9                                                     ; 0537
    jnz short loc_0530                                          ; 053a
    mov [rel $+7],rbx                                          ; 053c | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov qword [rel $+7],0x0                                    ; 0543 | REL32 +3 SPNCAZ$IFLAG addendLE=fcffffff
    mov qword [r11],0x0                                        ; 054e
    mov qword [rsi],0x0                                        ; 0555
    test byte [rax],0x1                                        ; 055c
    jnz short loc_0595                                          ; 055f
    xor eax,eax                                                ; 0561
    movsd xmm0,qword [rel $+8]                                 ; 0563 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    nop dword [byte rax+rax+0x0]                               ; 056b
loc_0570:
    xorps xmm1,xmm1                                            ; 0570
    cvtsi2sd xmm1,r12                                          ; 0573
    movapd xmm2,xmm0                                           ; 0578
    divsd xmm2,xmm1                                            ; 057c
    movsd qword [r10+rax*8],xmm2                               ; 0580
    inc rax                                                    ; 0586
    cmp r12,rax                                                ; 0589
    jnz short loc_0570                                          ; 058c
    mov [rel $+7],rbx                                          ; 058e | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
loc_0595:
    cmp r12,0x2                                                ; 0595
    jnz near loc_0864                                           ; 0599
    mov rax,0x3fefff2e40000000                                 ; 059f
    mov [rel $+7],rax                                          ; 05a9 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    lea rdx,[rel $+7]                                          ; 05b0 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    mov rax,0x3f1a380000000000                                 ; 05b7
    mov [rel $+15],rax                                         ; 05c1 | REL32 +3 SPNCAZ$XINP addendLE=08000000
    sub rsp,0x90                                               ; 05c8
    mov rax,[rbp+0x498]                                        ; 05cf
    mov [rsp+0x80],rax                                         ; 05d6
    lea rax,[rel $+7]                                          ; 05de | REL32 +3 SPNCAZ$KER addendLE=00000000
    mov [rsp+0x70],rax                                         ; 05e5
    mov rdi,[rbp+0x320]                                        ; 05ea
    mov [rsp+0x68],rdi                                         ; 05f1
    mov [rbp+0x2c0],rcx                                        ; 05f6
    mov r14,[rbp+0x2c8]                                        ; 05fd
    mov [rsp+0x60],r14                                         ; 0604
    lea rax,[rel $+7]                                          ; 0609 | REL32 +3 SPNCAZ$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 0610
    mov rbx,[rbp+0x328]                                        ; 0615
    mov [rsp+0x50],rbx                                         ; 061c
    mov rsi,[rbp+0x330]                                        ; 0621
    mov [rsp+0x48],rsi                                         ; 0628
    lea rax,[rel $+7]                                          ; 062d | REL32 +3 SPNCAZ$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0634
    mov rax,[rbp+0x450]                                        ; 0639
    mov [rsp+0x38],rax                                         ; 0640
    mov rax,[rbp+0x460]                                        ; 0645
    mov [rsp+0x30],rax                                         ; 064c
    mov [rsp+0x28],rdx                                         ; 0651
    mov rax,[rbp+0x478]                                        ; 0656
    mov [rsp+0x20],rax                                         ; 065d
    mov qword [rsp+0x78],0xa                                   ; 0662
    lea rcx,[rel $+7]                                          ; 066b | REL32 +3 SPNCAZ$FLASHTYPE addendLE=00000000
    lea r9,[rel $+7]                                           ; 0672 | REL32 +3 __unnamed_1 addendLE=00000000
    mov r12,[rbp+0x308]                                        ; 0679
    mov rdx,r12                                                ; 0680
    mov r8,[rbp+0x490]                                         ; 0683
    call $+5                                                   ; 068a | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 068f
    movsd xmm0,qword [rsi]                                     ; 0696
    divsd xmm0,[rbx]                                           ; 069a
    movsd qword [rel $+8],xmm0                                 ; 069e | REL32 +4 SPNCAZ$REFKVAL addendLE=00000000
    mov rax,[rbp+0x488]                                        ; 06a6
    movsd xmm0,qword [rax]                                     ; 06ad
    movsd qword [rel $+8],xmm0                                 ; 06b1 | REL32 +4 SPNCAZ$XINP addendLE=00000000
    movsd xmm1,qword [rax+0x8]                                 ; 06b9
    movsd qword [rel $+16],xmm1                                ; 06be | REL32 +4 SPNCAZ$XINP addendLE=08000000
    movsd qword [rel $+8],xmm0                                 ; 06c6 | REL32 +4 SPNCAZ$XT addendLE=00000000
    sub rsp,0x20                                               ; 06ce
    lea rcx,[rel $+7]                                          ; 06d2 | REL32 +3 __unnamed_2 addendLE=00000000
    lea rdx,[rel $+7]                                          ; 06d9 | REL32 +3 __unnamed_1 addendLE=00000000
    lea r8,[rel $+7]                                           ; 06e0 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    mov r9,r8                                                  ; 06e7
    call $+5                                                   ; 06ea | REL32 +1 NORML addendLE=00000000
    sub rsp,0x70                                               ; 06ef
    mov rax,[rbp+0x498]                                        ; 06f3
    mov [rsp+0x80],rax                                         ; 06fa
    lea rax,[rel $+7]                                          ; 0702 | REL32 +3 SPNCAZ$KER addendLE=00000000
    mov [rsp+0x70],rax                                         ; 0709
    mov [rsp+0x68],rdi                                         ; 070e
    mov [rsp+0x60],r14                                         ; 0713
    mov r14,[rbp+0x2c0]                                        ; 0718
    lea rax,[rel $+7]                                          ; 071f | REL32 +3 SPNCAZ$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 0726
    mov [rsp+0x50],rbx                                         ; 072b
    mov [rsp+0x48],rsi                                         ; 0730
    lea rax,[rel $+7]                                          ; 0735 | REL32 +3 SPNCAZ$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 073c
    mov rax,[rbp+0x450]                                        ; 0741
    mov [rsp+0x38],rax                                         ; 0748
    mov rax,[rbp+0x460]                                        ; 074d
    mov [rsp+0x30],rax                                         ; 0754
    lea rax,[rel $+7]                                          ; 0759 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    mov [rsp+0x28],rax                                         ; 0760
    mov rax,[rbp+0x478]                                        ; 0765
    mov [rsp+0x20],rax                                         ; 076c
    mov qword [rsp+0x78],0xa                                   ; 0771
    lea rcx,[rel $+7]                                          ; 077a | REL32 +3 SPNCAZ$FLASHTYPE addendLE=00000000
    mov rdx,r12                                                ; 0781
    lea r9,[rel $+7]                                           ; 0784 | REL32 +3 __unnamed_1 addendLE=00000000
    mov r8,[rbp+0x490]                                         ; 078b
    call $+5                                                   ; 0792 | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 0797
    mov qword [rel $+7],0x1                                    ; 079e | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    mov eax,0x1                                                ; 07a9
    xor ecx,ecx                                                ; 07ae
    xorpd xmm0,xmm0                                            ; 07b0
    xor edx,edx                                                ; 07b4
    mov rdi,[rbp+0x318]                                        ; 07b6
    mov r10,[rbp+0x2d0]                                        ; 07bd
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 07c4 | nop word [cs:rax+rax+0x0]
loc_07d0:
    mov r8,[rbp+0x328]                                         ; 07d0
    movsd xmm1,qword [r8+rax*8-0x8]                            ; 07d7
    ucomisd xmm0,xmm1                                          ; 07de
    setpe r8b                                                  ; 07e2
    setnz r9b                                                  ; 07e6
    or r9b,r8b                                                 ; 07ea
    jz near loc_14ad                                            ; 07ed
    mov rcx,[rbp+0x330]                                        ; 07f3
    movsd xmm2,qword [rcx+rax*8-0x8]                           ; 07fa
    divsd xmm2,xmm1                                            ; 0800
    movsd qword [r10+rax*8-0x8],xmm2                           ; 0804
    lea rcx,[rdx+0x2]                                          ; 080b
    inc rdx                                                    ; 080f
    inc rax                                                    ; 0812
    cmp rax,0x3                                                ; 0815
    jnz short loc_07d0                                          ; 0819
    mov [rel $+7],rax                                          ; 081b | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    movsd xmm0,qword [r10]                                     ; 0822
    subsd xmm0,qword [r10+0x8]                                 ; 0827
    movsd qword [rel $+8],xmm0                                 ; 082d | REL32 +4 SPNCAZ$F0 addendLE=00000000
    movsd xmm0,qword [rel $+8]                                 ; 0835 | REL32 +4 SPNCAZ$XT addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 083d | REL32 +4 SPNCAZ$XT0 addendLE=00000000
    movsd xmm1,qword [rel $+8]                                 ; 0845 | REL32 +4 __real@3fefae147ae147ae addendLE=00000000
    ucomisd xmm1,xmm0                                          ; 084d
    jna near loc_150b                                           ; 0851
    addsd xmm0,[rel $+8]                                       ; 0857 | REL32 +4 __real@3f847ae147ae147b addendLE=00000000
    jmp near loc_1513                                           ; 085f
loc_0864:
    mov qword [rel $+7],0x1                                    ; 0864 | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    mov eax,0x1                                                ; 086f
    lea rsi,[rel $+7]                                          ; 0874 | REL32 +3 SPNCAZ$KDMAX addendLE=00000000
    movsd xmm6,qword [rel $+8]                                 ; 087b | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    xorpd xmm7,xmm7                                            ; 0883
    mov r13,rbp                                                ; 0887
    lea rbx,[rbp+0x2d8]                                        ; 088a
    lea r14,[rbp+0x210]                                        ; 0891
    mov [rbp+0x2c0],r12                                        ; 0898
    jmp short loc_08ce                                          ; 089f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 08a1 | nop word [cs:rax+rax+0x0]
loc_08b0:
    lea rcx,[rax+0x1]                                          ; 08b0
    mov [rel $+7],rcx                                          ; 08b4 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov r12,[rbp+0x2c0]                                        ; 08bb
    cmp rax,r12                                                ; 08c2
    mov rax,rcx                                                ; 08c5
    jnl near loc_09e8                                           ; 08c8
loc_08ce:
    mov qword [rsi+rax*8-0x8],0x0                              ; 08ce
    mov rcx,[rbp+0x338]                                        ; 08d7
    mov r12,[rcx]                                              ; 08de
    mov qword [rel $+7],0x1                                    ; 08e1 | REL32 +3 SPNCAZ$JCOMP addendLE=fcffffff
    test r12,r12                                               ; 08ec
    jng short loc_08b0                                          ; 08ef
    xor edx,edx                                                ; 08f1
    jmp short loc_091c                                          ; 08f3
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 08f5 | nop word [cs:rax+rax+0x0]
loc_0900:
    movsd qword [rsi+rcx*8],xmm0                               ; 0900
loc_0905:
    mov rdx,[rel $+7]                                          ; 0905 | REL32 +3 SPNCAZ$JCOMP addendLE=00000000
    lea rcx,[rdx+0x1]                                          ; 090c
    mov [rel $+7],rcx                                          ; 0910 | REL32 +3 SPNCAZ$JCOMP addendLE=00000000
    cmp rdx,r12                                                ; 0917
    jnl short loc_08b0                                          ; 091a
loc_091c:
    lea rcx,[rax-0x1]                                          ; 091c
    imul r8,rcx,0x320                                          ; 0920
    add r8,rdi                                                 ; 0927
    movsd xmm0,qword [r8+rdx*8]                                ; 092a
    ucomisd xmm6,xmm0                                          ; 0930
    jna short loc_0960                                          ; 0934
    ucomisd xmm0,xmm7                                          ; 0936
    jna short loc_0980                                          ; 093a
    movapd xmm1,xmm6                                           ; 093c
    divsd xmm1,xmm0                                            ; 0940
    movsd qword [rel $+8],xmm1                                 ; 0944 | REL32 +4 SPNCAZ$KD addendLE=00000000
    movapd xmm0,xmm1                                           ; 094c
    ucomisd xmm0,qword [rsi+rcx*8]                             ; 0950
    jna short loc_0905                                          ; 0955
    jmp short loc_0900                                          ; 0957
    nop dword [dword rax+0x0]                                  ; 0959
loc_0960:
    movsd qword [rel $+8],xmm0                                 ; 0960 | REL32 +4 SPNCAZ$KD addendLE=00000000
    ucomisd xmm0,qword [rsi+rcx*8]                             ; 0968
    ja short loc_0900                                           ; 096d
    jmp short loc_0905                                          ; 096f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0971 | nop word [cs:rax+rax+0x0]
loc_0980:
    mov qword [rbp+0x2d8],0x0                                  ; 0980
    mov dword [rbp+0x210],0x10438                              ; 098b
    mov qword [rbp+0x0],0x20                                   ; 0995
    lea rax,[rel $+7]                                          ; 099d | REL32 +3 strlit.36 addendLE=00000000
    mov [rbp+0x8],rax                                          ; 09a4
    sub rsp,0x30                                               ; 09a8
    mov [rsp+0x20],r13                                         ; 09ac
    mov rcx,rbx                                                ; 09b1
    xor edx,edx                                                ; 09b4
    mov r8,r15                                                 ; 09b6
    mov r9,r14                                                 ; 09b9
    call $+5                                                   ; 09bc | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 09c1
    movsd xmm0,qword [rel $+8]                                 ; 09c5 | REL32 +4 SPNCAZ$KD addendLE=00000000
    mov rax,[rel $+7]                                          ; 09cd | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    lea rcx,[rax-0x1]                                          ; 09d4
    ucomisd xmm0,qword [rsi+rcx*8]                             ; 09d8
    jna near loc_0905                                           ; 09dd
    jmp near loc_0900                                           ; 09e3
loc_09e8:
    mov rax,[rbp+0x338]                                        ; 09e8
    mov rdi,[rax]                                              ; 09ef
    mov qword [rel $+7],0x0                                    ; 09f2 | REL32 +3 SPNCAZ$MIN addendLE=fcffffff
    mov qword [rel $+7],0x1                                    ; 09fd | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test rdi,rdi                                               ; 0a08
    mov r13,[rbp+0x478]                                        ; 0a0b
    jng near loc_0c61                                           ; 0a12
    mov eax,0x1                                                ; 0a18
    movsd xmm7,qword [rel $+8]                                 ; 0a1d | REL32 +4 __real@46293e5939a08cea addendLE=00000000
    lea r10,[rel $+7]                                          ; 0a25 | REL32 +3 SPNCAZ$ADX addendLE=00000000
    lea r11,[rel $+7]                                          ; 0a2c | REL32 +3 SPNCAZ$CMIDS addendLE=00000000
    lea r14,[rel $+7]                                          ; 0a33 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    lea rbx,[rbp+0x2d8]                                        ; 0a3a
    mov rcx,rdi                                                ; 0a41
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0a44 | nop word [cs:rax+rax+0x0]
loc_0a50:
    mov qword [rel $+7],0x1                                    ; 0a50 | REL32 +3 SPNCAZ$JCOMP addendLE=fcffffff
    movapd xmm0,xmm7                                           ; 0a5b
    test rcx,rcx                                               ; 0a5f
    jng short loc_0aca                                          ; 0a62
    mov r8d,0x1                                                ; 0a64
    movsd xmm1,qword [rel $+8]                                 ; 0a6a | REL32 +4 SPNCAZ$MIN addendLE=00000000
    mov rdx,rsi                                                ; 0a72
    movapd xmm0,xmm7                                           ; 0a75
    jmp short loc_0a90                                          ; 0a79
    nop dword [byte rax+rax+0x0]                               ; 0a7b
loc_0a80:
    lea r9,[r8+0x1]                                            ; 0a80
    add rdx,0x8                                                ; 0a84
    cmp r8,rcx                                                 ; 0a88
    mov r8,r9                                                  ; 0a8b
    jnl short loc_0ac0                                          ; 0a8e
loc_0a90:
    movsd xmm2,qword [rdx]                                     ; 0a90
    ucomisd xmm2,xmm1                                          ; 0a94
    seta r9b                                                   ; 0a98
    ucomisd xmm0,xmm2                                          ; 0a9c
    jna short loc_0a80                                          ; 0aa0
    test r9b,r9b                                               ; 0aa2
    jz short loc_0a80                                           ; 0aa5
    mov [rel $+7],r8                                           ; 0aa7 | REL32 +3 SPNCAZ$COMP addendLE=00000000
    movapd xmm0,xmm2                                           ; 0aae
    jmp short loc_0a80                                          ; 0ab2
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0ab4 | nop word [cs:rax+rax+0x0]
loc_0ac0:
    inc rcx                                                    ; 0ac0
    mov [rel $+7],rcx                                          ; 0ac3 | REL32 +3 SPNCAZ$JCOMP addendLE=00000000
loc_0aca:
    mov rcx,[rel $+7]                                          ; 0aca | REL32 +3 SPNCAZ$COMP addendLE=00000000
    mov rdx,[r13+rcx*8-0x8]                                    ; 0ad1
    mov [r10+rax*8-0x8],rdx                                    ; 0ad6
    lea rdx,[rel $+7]                                          ; 0adb | REL32 +3 SPNCAZ$COMIDS addendLE=00000000
    mov rdx,[rdx+rcx*8-0x8]                                    ; 0ae2
    mov [r11+rax*8-0x8],rdx                                    ; 0ae7
    mov rdx,[rbp+0x488]                                        ; 0aec
    movsd xmm1,qword [rdx+rcx*8-0x8]                           ; 0af3
    movsd qword [r14+rax*8-0x8],xmm1                           ; 0af9
    movsd qword [rel $+8],xmm0                                 ; 0b00 | REL32 +4 SPNCAZ$MIN addendLE=00000000
    cmp qword [rbp+0x318],0x4                                  ; 0b08
    jl near loc_0c40                                            ; 0b10
    mov qword [rbp+0x2d8],0x0                                  ; 0b16
    mov dword [rbp+0x214],0x20438                              ; 0b21
    mov qword [rbp+0x10],0x9                                   ; 0b2b
    lea rax,[rel $+7]                                          ; 0b33 | REL32 +3 strlit.33 addendLE=00000000
    mov [rbp+0x18],rax                                         ; 0b3a
    sub rsp,0x30                                               ; 0b3e
    lea rax,[rbp+0x10]                                         ; 0b42
    mov [rsp+0x20],rax                                         ; 0b46
    mov rcx,rbx                                                ; 0b4b
    xor edx,edx                                                ; 0b4e
    mov r8,0x801208384ff00                                     ; 0b50
    lea r9,[rbp+0x214]                                         ; 0b5a
    mov r12,r13                                                ; 0b61
    mov r13,r10                                                ; 0b64
    mov r15,r11                                                ; 0b67
    call $+5                                                   ; 0b6a | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 0b6f
    mov rax,[rel $+7]                                          ; 0b73 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov dword [rbp+0x218],0x2010b                              ; 0b7a
    mov [rbp+0x140],rax                                        ; 0b84
    sub rsp,0x20                                               ; 0b8b
    mov rcx,rbx                                                ; 0b8f
    lea rdx,[rbp+0x218]                                        ; 0b92
    lea r8,[rbp+0x140]                                         ; 0b99
    call $+5                                                   ; 0ba0 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0ba5
    mov dword [rbp+0x21c],0x20438                              ; 0ba9
    mov qword [rbp+0x20],0x4                                   ; 0bb3
    lea rax,[rel $+7]                                          ; 0bbb | REL32 +3 strlit.32 addendLE=00000000
    mov [rbp+0x28],rax                                         ; 0bc2
    sub rsp,0x20                                               ; 0bc6
    mov rcx,rbx                                                ; 0bca
    lea rdx,[rbp+0x21c]                                        ; 0bcd
    lea r8,[rbp+0x20]                                          ; 0bd4
    call $+5                                                   ; 0bd8 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0bdd
    mov rax,[rel $+7]                                          ; 0be1 | REL32 +3 SPNCAZ$COMP addendLE=00000000
    lea rcx,[rel $+7]                                          ; 0be8 | REL32 +3 SPNCAZ$COMIDS addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 0bef
    add rax,0xfffffffffffffff8                                 ; 0bf3
    mov dword [rbp+0x220],0x10638                              ; 0bf7
    mov qword [rbp-0x60],0x8                                   ; 0c01
    mov [rbp-0x58],rax                                         ; 0c09
    mov qword [rbp-0x50],0x8                                   ; 0c0d
    sub rsp,0x20                                               ; 0c15
    mov rcx,rbx                                                ; 0c19
    lea rdx,[rbp+0x220]                                        ; 0c1c
    lea r8,[rbp-0x60]                                          ; 0c23
    call $+5                                                   ; 0c27 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    mov r11,r15                                                ; 0c2c
    mov r10,r13                                                ; 0c2f
    mov r13,r12                                                ; 0c32
    add rsp,0x20                                               ; 0c35
    mov rax,[rel $+7]                                          ; 0c39 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
loc_0c40:
    mov rcx,rax                                                ; 0c40
    inc rax                                                    ; 0c43
    mov [rel $+7],rax                                          ; 0c46 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    cmp rcx,rdi                                                ; 0c4d
    jnl short loc_0c61                                          ; 0c50
    mov rcx,[rbp+0x338]                                        ; 0c52
    mov rcx,[rcx]                                              ; 0c59
    jmp near loc_0a50                                           ; 0c5c
loc_0c61:
    lea rsi,[rel $+7]                                          ; 0c61 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    movsd xmm7,qword [rel $+8]                                 ; 0c68 | REL32 +4 __real@3e112e0be826d695 addendLE=00000000
    movsd xmm8,qword [rel $+9]                                 ; 0c70 | REL32 +5 __real@39b4484bfeebc2a0 addendLE=00000000
    movsd xmm9,qword [rel $+9]                                 ; 0c79 | REL32 +5 __real@3ff051eb851eb852 addendLE=00000000
    movsd xmm10,qword [rel $+9]                                ; 0c82 | REL32 +5 __real@3fef5c28f5c28f5c addendLE=00000000
    lea r12,[rbp+0x2d8]                                        ; 0c8b
    lea r15,[rbp+0x244]                                        ; 0c92
    mov rdi,[rbp+0x318]                                        ; 0c99
    jmp near loc_0ded                                           ; 0ca0
loc_0ca5:
    sub rsp,0x70                                               ; 0ca5
    lea rax,[rel $+7]                                          ; 0ca9 | REL32 +3 SPNCAZ$FPARAM addendLE=00000000
    mov [rsp+0x60],rax                                         ; 0cb0
    lea rax,[rel $+7]                                          ; 0cb5 | REL32 +3 SPNCAZ$IPARAM addendLE=00000000
    mov [rsp+0x58],rax                                         ; 0cbc
    lea rax,[rel $+7]                                          ; 0cc1 | REL32 +3 SPNCAZ$IPVT addendLE=00000000
    mov [rsp+0x50],rax                                         ; 0cc8
    lea rax,[rel $+7]                                          ; 0ccd | REL32 +3 SPNCAZ$WA addendLE=00000000
    mov [rsp+0x48],rax                                         ; 0cd4
    lea rax,[rel $+7]                                          ; 0cd9 | REL32 +3 __unnamed_3 addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0ce0
    lea rax,[rel $+7]                                          ; 0ce5 | REL32 +3 SPNCAZ$BLU addendLE=00000000
    mov [rsp+0x38],rax                                         ; 0cec
    lea rax,[rel $+7]                                          ; 0cf1 | REL32 +3 SPNCAZ$DIAGF addendLE=00000000
    mov [rsp+0x30],rax                                         ; 0cf8
    lea rax,[rel $+7]                                          ; 0cfd | REL32 +3 SPNCAZ$DIAGX addendLE=00000000
    mov [rsp+0x28],rax                                         ; 0d04
    lea rax,[rel $+7]                                          ; 0d09 | REL32 +3 SPNCAZ$DELTA addendLE=00000000
    mov [rsp+0x20],rax                                         ; 0d10
    lea rcx,[rel $+7]                                          ; 0d15 | REL32 +3 SPNCAZ$IFLAG addendLE=00000000
    mov rdx,[rbp+0x338]                                        ; 0d1c
    mov r8,rdi                                                 ; 0d23
    lea r9,[rel $+7]                                           ; 0d26 | REL32 +3 SPNCAZ$FUNC addendLE=00000000
    call $+5                                                   ; 0d2d | REL32 +1 FUNEQ1 addendLE=00000000
    add rsp,0x70                                               ; 0d32
    mov r13,[rbp+0x478]                                        ; 0d36
    mov rax,[rbp+0x318]                                        ; 0d3d
    mov rsi,rdi                                                ; 0d44
    mov rdi,rax                                                ; 0d47
loc_0d4a:
    mov qword [rbp+0x2d8],0x0                                  ; 0d4a
    mov dword [rbp+0x258],0x20438                              ; 0d55
    mov qword [rbp+0x80],0x9                                   ; 0d5f
    lea rax,[rel $+7]                                          ; 0d6a | REL32 +3 strlit.20 addendLE=00000000
    mov [rbp+0x88],rax                                         ; 0d71
    sub rsp,0x30                                               ; 0d78
    lea rax,[rbp+0x80]                                         ; 0d7c
    mov [rsp+0x20],rax                                         ; 0d83
    mov rcx,r12                                                ; 0d88
    xor edx,edx                                                ; 0d8b
    mov r8,0x801208384ff00                                     ; 0d8d
    lea r9,[rbp+0x258]                                         ; 0d97
    call $+5                                                   ; 0d9e | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 0da3
    mov rax,[rel $+7]                                          ; 0da7 | REL32 +3 SPNCAZ$IFLAG addendLE=00000000
    mov dword [rbp+0x25c],0x1010b                              ; 0dae
    mov [rbp+0x180],rax                                        ; 0db8
    sub rsp,0x20                                               ; 0dbf
    mov rcx,r12                                                ; 0dc3
    lea rdx,[rbp+0x25c]                                        ; 0dc6
    lea r8,[rbp+0x180]                                         ; 0dcd
    call $+5                                                   ; 0dd4 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0dd9
loc_0ddd:
    mov rax,[rel $+7]                                          ; 0ddd | REL32 +3 SPNCAZ$IFLAG addendLE=00000000
    test rax,rax                                               ; 0de4
    jns near loc_1ffd                                           ; 0de7
loc_0ded:
    sub rsp,0x20                                               ; 0ded
    lea rcx,[rel $+7]                                          ; 0df1 | REL32 +3 __unnamed_2 addendLE=00000000
    mov rbx,[rbp+0x338]                                        ; 0df8
    mov rdx,rbx                                                ; 0dff
    mov r8,rsi                                                 ; 0e02
    mov r9,rsi                                                 ; 0e05
    call $+5                                                   ; 0e08 | REL32 +1 NORML addendLE=00000000
    sub rsp,0x70                                               ; 0e0d
    mov rax,[rbp+0x498]                                        ; 0e11
    mov [rsp+0x80],rax                                         ; 0e18
    lea rax,[rel $+7]                                          ; 0e20 | REL32 +3 SPNCAZ$KER addendLE=00000000
    mov [rsp+0x70],rax                                         ; 0e27
    mov rax,[rbp+0x320]                                        ; 0e2c
    mov [rsp+0x68],rax                                         ; 0e33
    mov rax,[rbp+0x2c8]                                        ; 0e38
    mov [rsp+0x60],rax                                         ; 0e3f
    lea rax,[rel $+7]                                          ; 0e44 | REL32 +3 SPNCAZ$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 0e4b
    mov rax,[rbp+0x328]                                        ; 0e50
    mov [rsp+0x50],rax                                         ; 0e57
    mov rax,[rbp+0x330]                                        ; 0e5c
    mov [rsp+0x48],rax                                         ; 0e63
    lea rax,[rel $+7]                                          ; 0e68 | REL32 +3 SPNCAZ$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0e6f
    mov rax,[rbp+0x450]                                        ; 0e74
    mov [rsp+0x38],rax                                         ; 0e7b
    mov rax,[rbp+0x460]                                        ; 0e80
    mov [rsp+0x30],rax                                         ; 0e87
    mov [rsp+0x28],rsi                                         ; 0e8c
    lea rax,[rel $+7]                                          ; 0e91 | REL32 +3 SPNCAZ$ADX addendLE=00000000
    mov [rsp+0x20],rax                                         ; 0e98
    mov qword [rsp+0x78],0xa                                   ; 0e9d
    lea rcx,[rel $+7]                                          ; 0ea6 | REL32 +3 SPNCAZ$FLASHTYPE addendLE=00000000
    mov rdx,[rbp+0x308]                                        ; 0ead
    mov r8,[rbp+0x490]                                         ; 0eb4
    mov r9,rbx                                                 ; 0ebb
    call $+5                                                   ; 0ebe | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 0ec3
    mov rbx,[rbx]                                              ; 0eca
    mov qword [rel $+7],0x1                                    ; 0ecd | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test rbx,rbx                                               ; 0ed8
    jng near loc_11a5                                           ; 0edb
    mov eax,0x1                                                ; 0ee1
    mov rdx,[rbp+0x2d0]                                        ; 0ee6
    jmp short loc_0f07                                          ; 0eed
    nop                                                        ; 0eef
loc_0ef0:
    lea rcx,[rax+0x1]                                          ; 0ef0
    mov [rel $+7],rcx                                          ; 0ef4 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    cmp rax,rbx                                                ; 0efb
    mov rax,rcx                                                ; 0efe
    jnl near loc_1190                                           ; 0f01
loc_0f07:
    mov rcx,[rbp+0x328]                                        ; 0f07
    movsd xmm0,qword [rcx+rax*8-0x8]                           ; 0f0e
    ucomisd xmm7,xmm0                                          ; 0f14
    jna short loc_0f50                                          ; 0f18
    ucomisd xmm0,xmm8                                          ; 0f1a
    jna near loc_1160                                           ; 0f1f
    mov rcx,[rbp+0x330]                                        ; 0f25
    movsd xmm1,qword [rcx+rax*8-0x8]                           ; 0f2c
    divsd xmm1,xmm0                                            ; 0f32
    movsd qword [rdx+rax*8-0x8],xmm1                           ; 0f36
    jmp near loc_1166                                           ; 0f3c
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0f41 | nop word [cs:rax+rax+0x0]
loc_0f50:
    mov rcx,[rbp+0x330]                                        ; 0f50
    movsd xmm1,qword [rcx+rax*8-0x8]                           ; 0f57
    divsd xmm1,xmm0                                            ; 0f5d
    movsd qword [rdx+rax*8-0x8],xmm1                           ; 0f61
    cmp rdi,0x3                                                ; 0f67
    jng short loc_0ef0                                          ; 0f6b
    mov qword [rbp+0x2d8],0x0                                  ; 0f6d
    mov dword [rbp+0x228],0x20438                              ; 0f78
    mov qword [rbp+0x40],0xd                                   ; 0f82
    lea rax,[rel $+7]                                          ; 0f8a | REL32 +3 strlit.27 addendLE=00000000
    mov [rbp+0x48],rax                                         ; 0f91
    sub rsp,0x30                                               ; 0f95
    lea rax,[rbp+0x40]                                         ; 0f99
    mov [rsp+0x20],rax                                         ; 0f9d
    mov rcx,r12                                                ; 0fa2
    xor edx,edx                                                ; 0fa5
    mov r8,0x801208384ff00                                     ; 0fa7
    lea r9,[rbp+0x228]                                         ; 0fb1
    call $+5                                                   ; 0fb8 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 0fbd
    mov rax,[rel $+7]                                          ; 0fc1 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov dword [rbp+0x22c],0x2010b                              ; 0fc8
    mov [rbp+0x148],rax                                        ; 0fd2
    sub rsp,0x20                                               ; 0fd9
    mov rcx,r12                                                ; 0fdd
    lea rdx,[rbp+0x22c]                                        ; 0fe0
    lea r8,[rbp+0x148]                                         ; 0fe7
    call $+5                                                   ; 0fee | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0ff3
    mov dword [rbp+0x230],0x20438                              ; 0ff7
    mov qword [rbp+0x50],0x4                                   ; 1001
    lea rax,[rel $+7]                                          ; 1009 | REL32 +3 strlit.32 addendLE=00000000
    mov [rbp+0x58],rax                                         ; 1010
    sub rsp,0x20                                               ; 1014
    mov rcx,r12                                                ; 1018
    lea rdx,[rbp+0x230]                                        ; 101b
    lea r8,[rbp+0x50]                                          ; 1022
    call $+5                                                   ; 1026 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 102b
    mov rax,[rel $+7]                                          ; 102f | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov rcx,[rbp+0x330]                                        ; 1036
    movsd xmm0,qword [rcx+rax*8-0x8]                           ; 103d
    mov dword [rbp+0x234],0x20130                              ; 1043
    movsd qword [rbp+0x150],xmm0                               ; 104d
    sub rsp,0x20                                               ; 1055
    mov rcx,r12                                                ; 1059
    lea rdx,[rbp+0x234]                                        ; 105c
    lea r8,[rbp+0x150]                                         ; 1063
    call $+5                                                   ; 106a | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 106f
    mov rax,[rel $+7]                                          ; 1073 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov rcx,[rbp+0x328]                                        ; 107a
    movsd xmm0,qword [rcx+rax*8-0x8]                           ; 1081
    mov dword [rbp+0x238],0x20130                              ; 1087
    movsd qword [rbp+0x158],xmm0                               ; 1091
    sub rsp,0x20                                               ; 1099
    mov rcx,r12                                                ; 109d
    lea rdx,[rbp+0x238]                                        ; 10a0
    lea r8,[rbp+0x158]                                         ; 10a7
    call $+5                                                   ; 10ae | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 10b3
    mov rax,[rel $+7]                                          ; 10b7 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov rcx,[rbp+0x2c8]                                        ; 10be
    movsd xmm0,qword [rcx+rax*8-0x8]                           ; 10c5
    mov dword [rbp+0x23c],0x20130                              ; 10cb
    movsd qword [rbp+0x160],xmm0                               ; 10d5
    sub rsp,0x20                                               ; 10dd
    mov rcx,r12                                                ; 10e1
    lea rdx,[rbp+0x23c]                                        ; 10e4
    lea r8,[rbp+0x160]                                         ; 10eb
    call $+5                                                   ; 10f2 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 10f7
    mov rax,[rel $+7]                                          ; 10fb | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov rcx,[rbp+0x320]                                        ; 1102
    movsd xmm0,qword [rcx+rax*8-0x8]                           ; 1109
    mov dword [rbp+0x240],0x10130                              ; 110f
    movsd qword [rbp+0x168],xmm0                               ; 1119
    sub rsp,0x20                                               ; 1121
    mov rcx,r12                                                ; 1125
    lea rdx,[rbp+0x240]                                        ; 1128
    lea r8,[rbp+0x168]                                         ; 112f
    call $+5                                                   ; 1136 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    mov rdx,[rbp+0x2d0]                                        ; 113b
    add rsp,0x20                                               ; 1142
    mov rax,[rel $+7]                                          ; 1146 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    jmp near loc_0ef0                                           ; 114d
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 1152 | nop word [cs:rax+rax+0x0]
loc_1160:
    movsd xmm1,qword [rdx+rax*8-0x8]                           ; 1160
loc_1166:
    ucomisd xmm1,xmm9                                          ; 1166
    seta cl                                                    ; 116b
    ucomisd xmm10,xmm1                                         ; 116e
    ja near loc_1443                                            ; 1173
    test cl,cl                                                 ; 1179
    jz near loc_0ef0                                            ; 117b
    jmp near loc_1443                                           ; 1181
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 1186 | nop word [cs:rax+rax+0x0]
loc_1190:
    mov rax,[rbp+0x338]                                        ; 1190
    mov rbx,[rax]                                              ; 1197
    cmp rdi,0x3                                                ; 119a
    jg short loc_11b6                                           ; 119e
    jmp near loc_1363                                           ; 11a0
loc_11a5:
    mov rdx,[rbp+0x2d0]                                        ; 11a5
    cmp rdi,0x3                                                ; 11ac
    jng near loc_1363                                           ; 11b0
loc_11b6:
    mov qword [rel $+7],0x1                                    ; 11b6 | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test rbx,rbx                                               ; 11c1
    lea r14,[rbp+0x60]                                         ; 11c4
    mov rdi,rsi                                                ; 11c8
    mov rsi,0x801208384ff00                                    ; 11cb
    jng near loc_0ca5                                           ; 11d5
    mov r13,rdx                                                ; 11db
    o16 nop                                                    ; 11de
loc_11e0:
    mov qword [rbp+0x2d8],0x0                                  ; 11e0
    mov dword [rbp+0x244],0x20438                              ; 11eb
    mov qword [rbp+0x60],0xc                                   ; 11f5
    lea rax,[rel $+7]                                          ; 11fd | REL32 +3 strlit.23 addendLE=00000000
    mov [rbp+0x68],rax                                         ; 1204
    sub rsp,0x30                                               ; 1208
    mov [rsp+0x20],r14                                         ; 120c
    mov rcx,r12                                                ; 1211
    xor edx,edx                                                ; 1214
    mov r8,rsi                                                 ; 1216
    mov r9,r15                                                 ; 1219
    call $+5                                                   ; 121c | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1221
    mov rax,[rel $+7]                                          ; 1225 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    lea rcx,[rel $+7]                                          ; 122c | REL32 +3 SPNCAZ$CMIDS addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 1233
    add rax,0xfffffffffffffff8                                 ; 1237
    mov dword [rbp+0x248],0x20638                              ; 123b
    mov qword [rbp-0x48],0x8                                   ; 1245
    mov [rbp-0x40],rax                                         ; 124d
    mov qword [rbp-0x38],0x8                                   ; 1251
    sub rsp,0x20                                               ; 1259
    mov rcx,r12                                                ; 125d
    lea rdx,[rbp+0x248]                                        ; 1260
    lea r8,[rbp-0x48]                                          ; 1267
    call $+5                                                   ; 126b | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1270
    mov dword [rbp+0x24c],0x20438                              ; 1274
    mov qword [rbp+0x70],0x4                                   ; 127e
    lea rax,[rel $+7]                                          ; 1286 | REL32 +3 strlit.32 addendLE=00000000
    mov [rbp+0x78],rax                                         ; 128d
    sub rsp,0x20                                               ; 1291
    mov rcx,r12                                                ; 1295
    lea rdx,[rbp+0x24c]                                        ; 1298
    lea r8,[rbp+0x70]                                          ; 129f
    call $+5                                                   ; 12a3 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 12a8
    mov rax,[rel $+7]                                          ; 12ac | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    movsd xmm0,qword [rdi+rax*8-0x8]                           ; 12b3
    mov dword [rbp+0x250],0x20130                              ; 12b9
    movsd qword [rbp+0x170],xmm0                               ; 12c3
    sub rsp,0x20                                               ; 12cb
    mov rcx,r12                                                ; 12cf
    lea rdx,[rbp+0x250]                                        ; 12d2
    lea r8,[rbp+0x170]                                         ; 12d9
    call $+5                                                   ; 12e0 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 12e5
    mov rax,[rel $+7]                                          ; 12e9 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    movsd xmm0,qword [r13+rax*8-0x8]                           ; 12f0
    mov dword [rbp+0x254],0x10130                              ; 12f7
    movsd qword [rbp+0x178],xmm0                               ; 1301
    sub rsp,0x20                                               ; 1309
    mov rcx,r12                                                ; 130d
    lea rdx,[rbp+0x254]                                        ; 1310
    lea r8,[rbp+0x178]                                         ; 1317
    call $+5                                                   ; 131e | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1323
    mov rax,[rel $+7]                                          ; 1327 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 132e
    mov [rel $+7],rcx                                          ; 1332 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    cmp rax,rbx                                                ; 1339
    jl near loc_11e0                                            ; 133c
    mov rax,[rbp+0x338]                                        ; 1342
    mov rbx,[rax]                                              ; 1349
    mov rdx,r13                                                ; 134c
    mov r13,[rbp+0x478]                                        ; 134f
    mov rax,[rbp+0x318]                                        ; 1356
    mov rsi,rdi                                                ; 135d
    mov rdi,rax                                                ; 1360
loc_1363:
    mov qword [rel $+7],0x1                                    ; 1363 | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test rbx,rbx                                               ; 136e
    jng short loc_13a3                                          ; 1371
    lea rax,[rel $+7]                                          ; 1373 | REL32 +3 SPNCAZ$FUNC addendLE=00000000
    xor ecx,ecx                                                ; 137a
    nop dword [byte rax+0x0]                                   ; 137c
loc_1380:
    movapd xmm0,xmm6                                           ; 1380
    subsd xmm0,qword [rdx+rcx*8]                               ; 1384
    movsd qword [rax],xmm0                                     ; 1389
    inc rcx                                                    ; 138d
    add rax,0x8                                                ; 1390
    cmp rcx,rbx                                                ; 1394
    jl short loc_1380                                           ; 1397
    inc rbx                                                    ; 1399
    mov [rel $+7],rbx                                          ; 139c | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
loc_13a3:
    sub rsp,0x70                                               ; 13a3
    lea rax,[rel $+7]                                          ; 13a7 | REL32 +3 SPNCAZ$FPARAM addendLE=00000000
    mov [rsp+0x60],rax                                         ; 13ae
    lea rax,[rel $+7]                                          ; 13b3 | REL32 +3 SPNCAZ$IPARAM addendLE=00000000
    mov [rsp+0x58],rax                                         ; 13ba
    lea rax,[rel $+7]                                          ; 13bf | REL32 +3 SPNCAZ$IPVT addendLE=00000000
    mov [rsp+0x50],rax                                         ; 13c6
    lea rax,[rel $+7]                                          ; 13cb | REL32 +3 SPNCAZ$WA addendLE=00000000
    mov [rsp+0x48],rax                                         ; 13d2
    lea rax,[rel $+7]                                          ; 13d7 | REL32 +3 __unnamed_3 addendLE=00000000
    mov [rsp+0x40],rax                                         ; 13de
    lea rax,[rel $+7]                                          ; 13e3 | REL32 +3 SPNCAZ$BLU addendLE=00000000
    mov [rsp+0x38],rax                                         ; 13ea
    lea rax,[rel $+7]                                          ; 13ef | REL32 +3 SPNCAZ$DIAGF addendLE=00000000
    mov [rsp+0x30],rax                                         ; 13f6
    lea rax,[rel $+7]                                          ; 13fb | REL32 +3 SPNCAZ$DIAGX addendLE=00000000
    mov [rsp+0x28],rax                                         ; 1402
    lea rax,[rel $+7]                                          ; 1407 | REL32 +3 SPNCAZ$DELTA addendLE=00000000
    mov [rsp+0x20],rax                                         ; 140e
    lea rcx,[rel $+7]                                          ; 1413 | REL32 +3 SPNCAZ$IFLAG addendLE=00000000
    mov rdx,[rbp+0x338]                                        ; 141a
    mov r8,rsi                                                 ; 1421
    lea r9,[rel $+7]                                           ; 1424 | REL32 +3 SPNCAZ$FUNC addendLE=00000000
    call $+5                                                   ; 142b | REL32 +1 FUNEQ1 addendLE=00000000
    add rsp,0x70                                               ; 1430
    cmp rdi,0x4                                                ; 1434
    jnl near loc_0d4a                                           ; 1438
    jmp near loc_0ddd                                           ; 143e
loc_1443:
    cmp rdi,0x2                                                ; 1443
    mov r15,0x801208384ff00                                    ; 1447
    jng near loc_1f9b                                           ; 1451
    mov qword [rbp+0x2d8],0x0                                  ; 1457
    mov dword [rbp+0x224],0x10438                              ; 1462
    mov qword [rbp+0x30],0x40                                  ; 146c
    lea rax,[rel $+7]                                          ; 1474 | REL32 +3 strlit.30 addendLE=00000000
    mov [rbp+0x38],rax                                         ; 147b
    sub rsp,0x30                                               ; 147f
    lea rax,[rbp+0x30]                                         ; 1483
    mov [rsp+0x20],rax                                         ; 1487
    lea rcx,[rbp+0x2d8]                                        ; 148c
    lea r9,[rbp+0x224]                                         ; 1493
loc_149a:
    xor edx,edx                                                ; 149a
    mov r8,r15                                                 ; 149c
    call $+5                                                   ; 149f | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 14a4
    jmp near loc_1dc7                                           ; 14a8
loc_14ad:
    cmp rax,0x1                                                ; 14ad
    jz short loc_14ba                                           ; 14b1
    mov [rel $+7],rcx                                          ; 14b3 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
loc_14ba:
    mov qword [rbp+0x2d8],0x0                                  ; 14ba
    mov dword [rbp+0x260],0x10438                              ; 14c5
    mov qword [rbp+0x90],0x46                                  ; 14cf
    lea rax,[rel $+7]                                          ; 14da | REL32 +3 strlit.18 addendLE=00000000
    mov [rbp+0x98],rax                                         ; 14e1
    sub rsp,0x30                                               ; 14e8
    lea rax,[rbp+0x90]                                         ; 14ec
    mov [rsp+0x20],rax                                         ; 14f3
    lea rcx,[rbp+0x2d8]                                        ; 14f8
    lea r9,[rbp+0x260]                                         ; 14ff
    jmp near loc_1db2                                           ; 1506
loc_150b:
    subsd xmm0,qword [rel $+8]                                 ; 150b | REL32 +4 __real@3f847ae147ae147b addendLE=00000000
loc_1513:
    movsd qword [rel $+8],xmm0                                 ; 1513 | REL32 +4 SPNCAZ$XT addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 151b | REL32 +4 SPNCAZ$XINP addendLE=00000000
    movsd xmm6,qword [rel $+8]                                 ; 1523 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    movapd xmm1,xmm6                                           ; 152b
    subsd xmm1,xmm0                                            ; 152f
    movsd qword [rel $+16],xmm1                                ; 1533 | REL32 +4 SPNCAZ$XINP addendLE=08000000
    mov qword [rel $+7],0x1                                    ; 153b | REL32 +3 SPNCAZ$NSTEP addendLE=fcffffff
    lea rcx,[rel $+7]                                          ; 1546 | REL32 +3 __unnamed_2 addendLE=00000000
    lea rdx,[rel $+7]                                          ; 154d | REL32 +3 __unnamed_1 addendLE=00000000
    lea r12,[rel $+7]                                          ; 1554 | REL32 +3 SPNCAZ$FLASHTYPE addendLE=00000000
    xorpd xmm7,xmm7                                            ; 155b
    movapd xmm8,oword [rel $+9]                                ; 155f | REL32 +5 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    movsd xmm9,qword [rel $+9]                                 ; 1568 | REL32 +5 __real@3f2a36e2eb1c432d addendLE=00000000
    movsd xmm10,qword [rel $+9]                                ; 1571 | REL32 +5 __real@39b4484bfeebc2a0 addendLE=00000000
    movapd xmm11,oword [rel $+9]                               ; 157a | REL32 +5 __xmm@80000000000000008000000000000000 addendLE=00000000
    movsd xmm12,qword [rel $+9]                                ; 1583 | REL32 +5 __real@3fc3333333333333 addendLE=00000000
    movsd xmm15,qword [rel $+9]                                ; 158c | REL32 +5 __real@bfc3333333333333 addendLE=00000000
    mov rsi,[rbp+0x320]                                        ; 1595
loc_159c:
    sub rsp,0x20                                               ; 159c
    lea r13,[rel $+7]                                          ; 15a0 | REL32 +3 SPNCAZ$XINP addendLE=00000000
    mov r8,r13                                                 ; 15a7
    mov r9,r13                                                 ; 15aa
    mov rbx,r14                                                ; 15ad
    mov r14,rdx                                                ; 15b0
    call $+5                                                   ; 15b3 | REL32 +1 NORML addendLE=00000000
    sub rsp,0x70                                               ; 15b8
    mov rax,[rbp+0x498]                                        ; 15bc
    mov [rsp+0x80],rax                                         ; 15c3
    lea rax,[rel $+7]                                          ; 15cb | REL32 +3 SPNCAZ$KER addendLE=00000000
    mov [rsp+0x70],rax                                         ; 15d2
    mov [rsp+0x68],rsi                                         ; 15d7
    mov rax,[rbp+0x2c8]                                        ; 15dc
    mov [rsp+0x60],rax                                         ; 15e3
    lea rax,[rel $+7]                                          ; 15e8 | REL32 +3 SPNCAZ$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 15ef
    mov rax,[rbp+0x328]                                        ; 15f4
    mov [rsp+0x50],rax                                         ; 15fb
    mov rax,[rbp+0x330]                                        ; 1600
    mov [rsp+0x48],rax                                         ; 1607
    lea rax,[rel $+7]                                          ; 160c | REL32 +3 SPNCAZ$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 1613
    mov rax,[rbp+0x450]                                        ; 1618
    mov [rsp+0x38],rax                                         ; 161f
    mov rax,[rbp+0x460]                                        ; 1624
    mov [rsp+0x30],rax                                         ; 162b
    mov [rsp+0x28],r13                                         ; 1630
    mov rax,[rbp+0x478]                                        ; 1635
    mov [rsp+0x20],rax                                         ; 163c
    mov qword [rsp+0x78],0xa                                   ; 1641
    mov rcx,r12                                                ; 164a
    mov rdx,[rbp+0x308]                                        ; 164d
    mov r8,[rbp+0x490]                                         ; 1654
    mov r9,r14                                                 ; 165b
    mov r14,rbx                                                ; 165e
    call $+5                                                   ; 1661 | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 1666
    mov qword [rel $+7],0x1                                    ; 166d | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    mov eax,0x1                                                ; 1678
    xor ecx,ecx                                                ; 167d
    xor edx,edx                                                ; 167f
    mov r10,[rbp+0x2d0]                                        ; 1681
    nop dword [dword rax+rax+0x0]                              ; 1688
loc_1690:
    mov r8,[rbp+0x328]                                         ; 1690
    movsd xmm0,qword [r8+rax*8-0x8]                            ; 1697
    ucomisd xmm7,xmm0                                          ; 169e
    setpe r8b                                                  ; 16a2
    setnz r9b                                                  ; 16a6
    or r9b,r8b                                                 ; 16aa
    jz near loc_1d59                                            ; 16ad
    mov rcx,[rbp+0x330]                                        ; 16b3
    movsd xmm1,qword [rcx+rax*8-0x8]                           ; 16ba
    divsd xmm1,xmm0                                            ; 16c0
    movsd qword [r10+rax*8-0x8],xmm1                           ; 16c4
    lea rcx,[rdx+0x2]                                          ; 16cb
    inc rdx                                                    ; 16cf
    inc rax                                                    ; 16d2
    cmp rax,0x3                                                ; 16d5
    jnz short loc_1690                                          ; 16d9
    mov [rel $+7],rax                                          ; 16db | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    movsd xmm14,qword [r10]                                    ; 16e2
    movsd xmm13,qword [r10+0x8]                                ; 16e7
    movapd xmm0,xmm14                                          ; 16ed
    subsd xmm0,xmm13                                           ; 16f2
    movsd qword [rel $+8],xmm0                                 ; 16f7 | REL32 +4 SPNCAZ$FX addendLE=00000000
    cmp rdi,0x4                                                ; 16ff
    jng near loc_18d7                                           ; 1703
    mov qword [rbp+0x2d8],0x0                                  ; 1709
    mov dword [rbp+0x26c],0x20438                              ; 1714
    mov qword [rbp+0xc0],0x6                                   ; 171e
    lea rax,[rel $+7]                                          ; 1729 | REL32 +3 strlit.11 addendLE=00000000
    mov [rbp+0xc8],rax                                         ; 1730
    sub rsp,0x30                                               ; 1737
    lea rax,[rbp+0xc0]                                         ; 173b
    mov [rsp+0x20],rax                                         ; 1742
    lea rbx,[rbp+0x2d8]                                        ; 1747
    mov rcx,rbx                                                ; 174e
    xor edx,edx                                                ; 1751
    mov r8,r15                                                 ; 1753
    lea r9,[rbp+0x26c]                                         ; 1756
    call $+5                                                   ; 175d | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1762
    movsd xmm0,qword [rel $+8]                                 ; 1766 | REL32 +4 SPNCAZ$XINP addendLE=00000000
    mov dword [rbp+0x270],0x20130                              ; 176e
    movsd qword [rbp+0x188],xmm0                               ; 1778
    sub rsp,0x20                                               ; 1780
    mov rcx,rbx                                                ; 1784
    lea rdx,[rbp+0x270]                                        ; 1787
    lea r8,[rbp+0x188]                                         ; 178e
    call $+5                                                   ; 1795 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 179a
    mov dword [rbp+0x274],0x20438                              ; 179e
    mov qword [rbp+0xd0],0x7                                   ; 17a8
    lea rax,[rel $+7]                                          ; 17b3 | REL32 +3 strlit.10 addendLE=00000000
    mov [rbp+0xd8],rax                                         ; 17ba
    sub rsp,0x20                                               ; 17c1
    mov rcx,rbx                                                ; 17c5
    lea rdx,[rbp+0x274]                                        ; 17c8
    lea r8,[rbp+0xd0]                                          ; 17cf
    call $+5                                                   ; 17d6 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 17db
    movsd xmm0,qword [rel $+8]                                 ; 17df | REL32 +4 SPNCAZ$FX addendLE=00000000
    mov dword [rbp+0x278],0x10130                              ; 17e7
    movsd qword [rbp+0x190],xmm0                               ; 17f1
    sub rsp,0x20                                               ; 17f9
    mov rcx,rbx                                                ; 17fd
    lea rdx,[rbp+0x278]                                        ; 1800
    lea r8,[rbp+0x190]                                         ; 1807
    call $+5                                                   ; 180e | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1813
    mov qword [rbp+0x2d8],0x0                                  ; 1817
    mov dword [rbp+0x27c],0x20438                              ; 1822
    mov qword [rbp+0xe0],0x8                                   ; 182c
    lea rax,[rel $+7]                                          ; 1837 | REL32 +3 strlit.8 addendLE=00000000
    mov [rbp+0xe8],rax                                         ; 183e
    sub rsp,0x30                                               ; 1845
    lea rax,[rbp+0xe0]                                         ; 1849
    mov [rsp+0x20],rax                                         ; 1850
    mov rcx,rbx                                                ; 1855
    xor edx,edx                                                ; 1858
    mov r8,r15                                                 ; 185a
    lea r9,[rbp+0x27c]                                         ; 185d
    call $+5                                                   ; 1864 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1869
    mov dword [rbp+0x280],0x20130                              ; 186d
    movsd qword [rbp+0x198],xmm14                              ; 1877
    sub rsp,0x20                                               ; 1880
    mov rcx,rbx                                                ; 1884
    lea rdx,[rbp+0x280]                                        ; 1887
    lea r8,[rbp+0x198]                                         ; 188e
    call $+5                                                   ; 1895 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 189a
    mov dword [rbp+0x284],0x10130                              ; 189e
    movsd qword [rbp+0x1a0],xmm13                              ; 18a8
    sub rsp,0x20                                               ; 18b1
    mov rcx,rbx                                                ; 18b5
    lea rdx,[rbp+0x284]                                        ; 18b8
    lea r8,[rbp+0x1a0]                                         ; 18bf
    call $+5                                                   ; 18c6 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 18cb
    movsd xmm0,qword [rel $+8]                                 ; 18cf | REL32 +4 SPNCAZ$FX addendLE=00000000
loc_18d7:
    movapd xmm1,xmm0                                           ; 18d7
    andpd xmm1,xmm8                                            ; 18db
    ucomisd xmm9,xmm1                                          ; 18e0
    ja near loc_20ee                                            ; 18e5
    movsd xmm1,qword [rel $+8]                                 ; 18eb | REL32 +4 SPNCAZ$XT addendLE=00000000
    movsd xmm2,qword [rel $+8]                                 ; 18f3 | REL32 +4 SPNCAZ$XT0 addendLE=00000000
    movapd xmm3,xmm1                                           ; 18fb
    subsd xmm3,xmm2                                            ; 18ff
    ucomisd xmm3,xmm7                                          ; 1903
    setpo al                                                   ; 1907
    setz cl                                                    ; 190a
    test cl,al                                                 ; 190d
    jz short loc_1922                                           ; 190f
    movapd xmm1,xmm2                                           ; 1911
    addsd xmm1,xmm10                                           ; 1915
    movsd qword [rel $+8],xmm1                                 ; 191a | REL32 +4 SPNCAZ$XT addendLE=00000000
loc_1922:
    movapd xmm3,xmm0                                           ; 1922
    subsd xmm3,qword [rel $+8]                                 ; 1926 | REL32 +4 SPNCAZ$F0 addendLE=00000000
    subsd xmm1,xmm2                                            ; 192e
    divsd xmm3,xmm1                                            ; 1932
    movsd qword [rel $+8],xmm3                                 ; 1936 | REL32 +4 SPNCAZ$SLOPE addendLE=00000000
    divsd xmm0,xmm3                                            ; 193e
    andpd xmm0,xmm8                                            ; 1942
    movlpd qword [rel $+8],xmm0                                ; 1947 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
    movsd xmm1,qword [rel $+8]                                 ; 194f | REL32 +4 SPNCAZ$REFKVAL addendLE=00000000
    subsd xmm1,xmm6                                            ; 1957
    subsd xmm14,xmm6                                           ; 195b
    mulsd xmm14,xmm1                                           ; 1960
    ucomisd xmm14,xmm7                                         ; 1965
    jna short loc_1979                                          ; 196a
    xorpd xmm0,xmm11                                           ; 196c
    movlpd qword [rel $+8],xmm0                                ; 1971 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
loc_1979:
    cmp rdi,0x5                                                ; 1979
    jl near loc_1b00                                            ; 197d
    mov qword [rbp+0x2d8],0x0                                  ; 1983
    mov dword [rbp+0x288],0x20438                              ; 198e
    mov qword [rbp+0xf0],0x1b                                  ; 1998
    lea rax,[rel $+7]                                          ; 19a3 | REL32 +3 strlit.6 addendLE=00000000
    mov [rbp+0xf8],rax                                         ; 19aa
    sub rsp,0x30                                               ; 19b1
    lea rax,[rbp+0xf0]                                         ; 19b5
    mov [rsp+0x20],rax                                         ; 19bc
    lea rsi,[rbp+0x2d8]                                        ; 19c1
    mov rcx,rsi                                                ; 19c8
    xor edx,edx                                                ; 19cb
    mov r8,r15                                                 ; 19cd
    lea r9,[rbp+0x288]                                         ; 19d0
    call $+5                                                   ; 19d7 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 19dc
    movsd xmm0,qword [rel $+8]                                 ; 19e0 | REL32 +4 SPNCAZ$FX addendLE=00000000
    mov dword [rbp+0x28c],0x20130                              ; 19e8
    movsd qword [rbp+0x1a8],xmm0                               ; 19f2
    sub rsp,0x20                                               ; 19fa
    mov rcx,rsi                                                ; 19fe
    lea rdx,[rbp+0x28c]                                        ; 1a01
    lea r8,[rbp+0x1a8]                                         ; 1a08
    call $+5                                                   ; 1a0f | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1a14
    movsd xmm0,qword [rel $+8]                                 ; 1a18 | REL32 +4 SPNCAZ$F0 addendLE=00000000
    mov dword [rbp+0x290],0x20130                              ; 1a20
    movsd qword [rbp+0x1b0],xmm0                               ; 1a2a
    sub rsp,0x20                                               ; 1a32
    mov rcx,rsi                                                ; 1a36
    lea rdx,[rbp+0x290]                                        ; 1a39
    lea r8,[rbp+0x1b0]                                         ; 1a40
    call $+5                                                   ; 1a47 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1a4c
    movsd xmm0,qword [rel $+8]                                 ; 1a50 | REL32 +4 SPNCAZ$XT addendLE=00000000
    mov dword [rbp+0x294],0x20130                              ; 1a58
    movsd qword [rbp+0x1b8],xmm0                               ; 1a62
    sub rsp,0x20                                               ; 1a6a
    mov rcx,rsi                                                ; 1a6e
    lea rdx,[rbp+0x294]                                        ; 1a71
    lea r8,[rbp+0x1b8]                                         ; 1a78
    call $+5                                                   ; 1a7f | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1a84
    movsd xmm0,qword [rel $+8]                                 ; 1a88 | REL32 +4 SPNCAZ$SLOPE addendLE=00000000
    mov dword [rbp+0x298],0x20130                              ; 1a90
    movsd qword [rbp+0x1c0],xmm0                               ; 1a9a
    sub rsp,0x20                                               ; 1aa2
    mov rcx,rsi                                                ; 1aa6
    lea rdx,[rbp+0x298]                                        ; 1aa9
    lea r8,[rbp+0x1c0]                                         ; 1ab0
    call $+5                                                   ; 1ab7 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1abc
    movsd xmm0,qword [rel $+8]                                 ; 1ac0 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
    mov dword [rbp+0x29c],0x10130                              ; 1ac8
    movsd qword [rbp+0x1c8],xmm0                               ; 1ad2
    sub rsp,0x20                                               ; 1ada
    mov rcx,rsi                                                ; 1ade
    lea rdx,[rbp+0x29c]                                        ; 1ae1
    lea r8,[rbp+0x1c8]                                         ; 1ae8
    call $+5                                                   ; 1aef | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1af4
    movsd xmm0,qword [rel $+8]                                 ; 1af8 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
loc_1b00:
    ucomisd xmm0,xmm12                                         ; 1b00
    movapd xmm1,xmm12                                          ; 1b05
    ja short loc_1b18                                           ; 1b0a
    ucomisd xmm15,xmm0                                         ; 1b0c
    movapd xmm1,xmm15                                          ; 1b11
    jna short loc_1b24                                          ; 1b16
loc_1b18:
    movsd qword [rel $+8],xmm1                                 ; 1b18 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
    movapd xmm0,xmm1                                           ; 1b20
loc_1b24:
    cmp qword [rel $+7],0x8                                    ; 1b24 | REL32 +3 SPNCAZ$NSTEP addendLE=ffffffff
    movsd xmm1,qword [rel $+8]                                 ; 1b2c | REL32 +4 SPNCAZ$XT addendLE=00000000
    jnl short loc_1ba3                                          ; 1b34
    movapd xmm2,xmm1                                           ; 1b36
    addsd xmm2,xmm0                                            ; 1b3a
    ucomisd xmm2,xmm6                                          ; 1b3e
    setnc al                                                   ; 1b42
    ucomisd xmm0,xmm7                                          ; 1b45
    jna short loc_1b68                                          ; 1b49
    test al,al                                                 ; 1b4b
    jz short loc_1b68                                           ; 1b4d
    movapd xmm0,xmm6                                           ; 1b4f
    subsd xmm0,xmm1                                            ; 1b53
    mulsd xmm0,qword [rel $+8]                                 ; 1b57 | REL32 +4 __real@3fecccccc0000000 addendLE=00000000
    mov rsi,[rbp+0x320]                                        ; 1b5f
    jmp short loc_1b99                                          ; 1b66
loc_1b68:
    movapd xmm2,xmm1                                           ; 1b68
    addsd xmm2,xmm0                                            ; 1b6c
    ucomisd xmm7,xmm2                                          ; 1b70
    setnc al                                                   ; 1b74
    ucomisd xmm7,xmm0                                          ; 1b77
    jna short loc_1ba3                                          ; 1b7b
    test al,al                                                 ; 1b7d
    mov rsi,[rbp+0x320]                                        ; 1b7f
    jz short loc_1baa                                           ; 1b86
    movapd xmm0,xmm1                                           ; 1b88
    mulsd xmm0,qword [rel $+8]                                 ; 1b8c | REL32 +4 __real@3feccccccccccccd addendLE=00000000
    xorpd xmm0,xmm11                                           ; 1b94
loc_1b99:
    movsd qword [rel $+8],xmm0                                 ; 1b99 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
    jmp short loc_1baa                                          ; 1ba1
loc_1ba3:
    mov rsi,[rbp+0x320]                                        ; 1ba3
loc_1baa:
    movsd qword [rel $+8],xmm1                                 ; 1baa | REL32 +4 SPNCAZ$XT0 addendLE=00000000
    addsd xmm0,xmm1                                            ; 1bb2
    movsd qword [rel $+8],xmm0                                 ; 1bb6 | REL32 +4 SPNCAZ$XT addendLE=00000000
    cmp rdi,0x5                                                ; 1bbe
    jl near loc_1c9d                                            ; 1bc2
    mov qword [rbp+0x2d8],0x0                                  ; 1bc8
    mov dword [rbp+0x2a0],0x20438                              ; 1bd3
    mov qword [rbp+0x100],0x19                                 ; 1bdd
    lea rax,[rel $+7]                                          ; 1be8 | REL32 +3 strlit.4 addendLE=00000000
    mov [rbp+0x108],rax                                        ; 1bef
    sub rsp,0x30                                               ; 1bf6
    lea rax,[rbp+0x100]                                        ; 1bfa
    mov [rsp+0x20],rax                                         ; 1c01
    lea rbx,[rbp+0x2d8]                                        ; 1c06
    mov rcx,rbx                                                ; 1c0d
    xor edx,edx                                                ; 1c10
    mov r8,r15                                                 ; 1c12
    lea r9,[rbp+0x2a0]                                         ; 1c15
    call $+5                                                   ; 1c1c | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1c21
    movsd xmm0,qword [rel $+8]                                 ; 1c25 | REL32 +4 SPNCAZ$XSTEP addendLE=00000000
    mov dword [rbp+0x2a4],0x20130                              ; 1c2d
    movsd qword [rbp+0x1d0],xmm0                               ; 1c37
    sub rsp,0x20                                               ; 1c3f
    mov rcx,rbx                                                ; 1c43
    lea rdx,[rbp+0x2a4]                                        ; 1c46
    lea r8,[rbp+0x1d0]                                         ; 1c4d
    call $+5                                                   ; 1c54 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1c59
    movsd xmm0,qword [rel $+8]                                 ; 1c5d | REL32 +4 SPNCAZ$XT addendLE=00000000
    mov dword [rbp+0x2a8],0x10130                              ; 1c65
    movsd qword [rbp+0x1d8],xmm0                               ; 1c6f
    sub rsp,0x20                                               ; 1c77
    mov rcx,rbx                                                ; 1c7b
    lea rdx,[rbp+0x2a8]                                        ; 1c7e
    lea r8,[rbp+0x1d8]                                         ; 1c85
    call $+5                                                   ; 1c8c | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1c91
    movsd xmm0,qword [rel $+8]                                 ; 1c95 | REL32 +4 SPNCAZ$XT addendLE=00000000
loc_1c9d:
    movsd qword [rel $+8],xmm0                                 ; 1c9d | REL32 +4 SPNCAZ$XINP addendLE=00000000
    movapd xmm1,xmm6                                           ; 1ca5
    subsd xmm1,xmm0                                            ; 1ca9
    movsd qword [rel $+16],xmm1                                ; 1cad | REL32 +4 SPNCAZ$XINP addendLE=08000000
    ucomisd xmm7,xmm1                                          ; 1cb5
    seta al                                                    ; 1cb9
    ucomisd xmm7,xmm0                                          ; 1cbc
    ja near loc_1dc7                                            ; 1cc0
    test al,al                                                 ; 1cc6
    jnz near loc_1dc7                                           ; 1cc8
    movsd xmm0,qword [rel $+8]                                 ; 1cce | REL32 +4 SPNCAZ$FX addendLE=00000000
    movsd qword [rel $+8],xmm0                                 ; 1cd6 | REL32 +4 SPNCAZ$F0 addendLE=00000000
    mov rax,[rel $+7]                                          ; 1cde | REL32 +3 SPNCAZ$NSTEP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 1ce5
    mov [rel $+7],rcx                                          ; 1ce9 | REL32 +3 SPNCAZ$NSTEP addendLE=00000000
    cmp rax,0x18                                               ; 1cf0
    lea rcx,[rel $+7]                                          ; 1cf4 | REL32 +3 __unnamed_2 addendLE=00000000
    lea rdx,[rel $+7]                                          ; 1cfb | REL32 +3 __unnamed_1 addendLE=00000000
    jng near loc_159c                                           ; 1d02
    mov qword [rbp+0x2d8],0x0                                  ; 1d08
    mov dword [rbp+0x264],0x10438                              ; 1d13
    mov qword [rbp+0xa0],0x27                                  ; 1d1d
    lea rax,[rel $+7]                                          ; 1d28 | REL32 +3 strlit.16 addendLE=00000000
    mov [rbp+0xa8],rax                                         ; 1d2f
    sub rsp,0x30                                               ; 1d36
    lea rax,[rbp+0xa0]                                         ; 1d3a
    mov [rsp+0x20],rax                                         ; 1d41
    lea rcx,[rbp+0x2d8]                                        ; 1d46
    lea r9,[rbp+0x264]                                         ; 1d4d
    jmp near loc_149a                                           ; 1d54
loc_1d59:
    cmp rax,0x1                                                ; 1d59
    jz short loc_1d66                                           ; 1d5d
    mov [rel $+7],rcx                                          ; 1d5f | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
loc_1d66:
    mov qword [rbp+0x2d8],0x0                                  ; 1d66
    mov dword [rbp+0x268],0x10438                              ; 1d71
    mov qword [rbp+0xb0],0x40                                  ; 1d7b
    lea rax,[rel $+7]                                          ; 1d86 | REL32 +3 strlit.14 addendLE=00000000
    mov [rbp+0xb8],rax                                         ; 1d8d
    sub rsp,0x30                                               ; 1d94
    lea rax,[rbp+0xb0]                                         ; 1d98
    mov [rsp+0x20],rax                                         ; 1d9f
    lea rcx,[rbp+0x2d8]                                        ; 1da4
    lea r9,[rbp+0x268]                                         ; 1dab
loc_1db2:
    xor edx,edx                                                ; 1db2
    mov r8,r15                                                 ; 1db4
    call $+5                                                   ; 1db7 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1dbc
    mov qword [r14],0x1                                        ; 1dc0
loc_1dc7:
    mov rax,[rbp+0x458]                                        ; 1dc7
    test byte [rax],0x1                                        ; 1dce
    mov r13,[rbp+0x488]                                        ; 1dd1
    jz near loc_1f9b                                            ; 1dd8
    cmp rdi,0x3                                                ; 1dde
    jng near loc_1f9b                                           ; 1de2
    mov qword [rbp+0x2d8],0x0                                  ; 1de8
    mov dword [rbp+0x2ac],0x10438                              ; 1df3
    mov qword [rbp+0x110],0x10                                 ; 1dfd
    lea rax,[rel $+7]                                          ; 1e08 | REL32 +3 strlit.2 addendLE=00000000
    mov [rbp+0x118],rax                                        ; 1e0f
    sub rsp,0x30                                               ; 1e16
    lea rax,[rbp+0x110]                                        ; 1e1a
    mov [rsp+0x20],rax                                         ; 1e21
    lea rcx,[rbp+0x2d8]                                        ; 1e26
    lea r9,[rbp+0x2ac]                                         ; 1e2d
    xor edx,edx                                                ; 1e34
    mov r8,r15                                                 ; 1e36
    call $+5                                                   ; 1e39 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1e3e
    mov rax,[rbp+0x338]                                        ; 1e42
    mov r14,[rax]                                              ; 1e49
    mov qword [rel $+7],0x1                                    ; 1e4c | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test r14,r14                                               ; 1e57
    jng near loc_1f9b                                           ; 1e5a
    lea rdi,[rbp+0x2d8]                                        ; 1e60
    lea r12,[rel $+7]                                          ; 1e67 | REL32 +3 SPNCAZ$KVAL addendLE=00000000
    lea rsi,[rbp+0x2bc]                                        ; 1e6e
    lea rbx,[rbp+0x1f0]                                        ; 1e75
    nop dword [byte rax+0x0]                                   ; 1e7c
loc_1e80:
    mov qword [rbp+0x2d8],0x0                                  ; 1e80
    mov dword [rbp+0x2b0],0x20438                              ; 1e8b
    mov qword [rbp+0x120],0x9                                  ; 1e95
    lea rax,[rel $+7]                                          ; 1ea0 | REL32 +3 strlit addendLE=00000000
    mov [rbp+0x128],rax                                        ; 1ea7
    sub rsp,0x30                                               ; 1eae
    lea rax,[rbp+0x120]                                        ; 1eb2
    mov [rsp+0x20],rax                                         ; 1eb9
    mov rcx,rdi                                                ; 1ebe
    xor edx,edx                                                ; 1ec1
    mov r8,r15                                                 ; 1ec3
    lea r9,[rbp+0x2b0]                                         ; 1ec6
    call $+5                                                   ; 1ecd | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 1ed2
    mov rax,[rel $+7]                                          ; 1ed6 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    mov dword [rbp+0x2b4],0x2010b                              ; 1edd
    mov [rbp+0x1e0],rax                                        ; 1ee7
    sub rsp,0x20                                               ; 1eee
    mov rcx,rdi                                                ; 1ef2
    lea rdx,[rbp+0x2b4]                                        ; 1ef5
    lea r8,[rbp+0x1e0]                                         ; 1efc
    call $+5                                                   ; 1f03 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1f08
    mov rax,[rel $+7]                                          ; 1f0c | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    movsd xmm0,qword [r13+rax*8-0x8]                           ; 1f13
    mov dword [rbp+0x2b8],0x20130                              ; 1f1a
    movsd qword [rbp+0x1e8],xmm0                               ; 1f24
    sub rsp,0x20                                               ; 1f2c
    mov rcx,rdi                                                ; 1f30
    lea rdx,[rbp+0x2b8]                                        ; 1f33
    lea r8,[rbp+0x1e8]                                         ; 1f3a
    call $+5                                                   ; 1f41 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1f46
    mov rax,[rel $+7]                                          ; 1f4a | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    movsd xmm0,qword [r12+rax*8-0x8]                           ; 1f51
    mov dword [rbp+0x2bc],0x10130                              ; 1f58
    movsd qword [rbp+0x1f0],xmm0                               ; 1f62
    sub rsp,0x20                                               ; 1f6a
    mov rcx,rdi                                                ; 1f6e
    mov rdx,rsi                                                ; 1f71
    mov r8,rbx                                                 ; 1f74
    call $+5                                                   ; 1f77 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 1f7c
    mov rax,[rel $+7]                                          ; 1f80 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 1f87
    mov [rel $+7],rcx                                          ; 1f8b | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    cmp rax,r14                                                ; 1f92
    jl near loc_1e80                                            ; 1f95
loc_1f9b:
    movaps xmm6,oword [rbp+0x340]                              ; 1f9b
    movaps xmm7,oword [rbp+0x350]                              ; 1fa2
    movaps xmm8,oword [rbp+0x360]                              ; 1fa9
    movaps xmm9,oword [rbp+0x370]                              ; 1fb1
    movaps xmm10,oword [rbp+0x380]                             ; 1fb9
    movaps xmm11,oword [rbp+0x390]                             ; 1fc1
    movaps xmm12,oword [rbp+0x3a0]                             ; 1fc9
    movaps xmm13,oword [rbp+0x3b0]                             ; 1fd1
    movaps xmm14,oword [rbp+0x3c0]                             ; 1fd9
    movaps xmm15,oword [rbp+0x3d0]                             ; 1fe1
    lea rsp,[rbp+0x3e8]                                        ; 1fe9
    pop rbx                                                    ; 1ff0
    pop rdi                                                    ; 1ff1
    pop rsi                                                    ; 1ff2
    pop r12                                                    ; 1ff3
    pop r13                                                    ; 1ff5
    pop r14                                                    ; 1ff7
    pop r15                                                    ; 1ff9
    pop rbp                                                    ; 1ffb
    retq                                                       ; 1ffc
loc_1ffd:
    add rax,0xfffffffffffffffd                                 ; 1ffd
    cmp rax,0xfffffffffffffffe                                 ; 2001
    jnc short loc_2024                                          ; 2005
    mov rax,[rbp+0x458]                                        ; 2007
    mov qword [rax],0x0                                        ; 200e
    mov r15,0x801208384ff00                                    ; 2015
    jmp near loc_1dc7                                           ; 201f
loc_2024:
    mov rax,[rbp+0x458]                                        ; 2024
    mov qword [rax],0xffffffffffffffff                         ; 202b
    mov rax,[rbp+0x338]                                        ; 2032
    mov rax,[rax]                                              ; 2039
    mov qword [rel $+7],0x1                                    ; 203c | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    test rax,rax                                               ; 2047
    mov rbx,[rbp+0x488]                                        ; 204a
    mov r15,0x801208384ff00                                    ; 2051
    jng near loc_214c                                           ; 205b
    lea rcx,[rax+0x1]                                          ; 2061
    mov edx,0x1                                                ; 2065
    lea r8,[rel $+7]                                           ; 206a | REL32 +3 SPNCAZ$KVAL addendLE=00000000
    lea r12,[rel $+7]                                          ; 2071 | REL32 +3 SPNCAZ$ADX addendLE=00000000
    jmp short loc_2086                                          ; 2078
loc_207a:
    lea r9,[rdx+0x1]                                           ; 207a
    cmp rdx,rax                                                ; 207e
    mov rdx,r9                                                 ; 2081
    jnl short loc_20de                                          ; 2084
loc_2086:
    mov r9,[r13+rdx*8-0x8]                                     ; 2086
    xor r10d,r10d                                              ; 208b
    mov r11,rax                                                ; 208e
    jmp short loc_20a9                                          ; 2091
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 2093 | nop word [cs:rax+rax+0x0]
loc_20a0:
    add r10,0x8                                                ; 20a0
    dec r11                                                    ; 20a4
    jz short loc_207a                                           ; 20a7
loc_20a9:
    cmp [r10+r12],r9                                           ; 20a9
    jnz short loc_20a0                                          ; 20ad
    movsd xmm0,qword [r10+rsi]                                 ; 20af
    movsd qword [rbx+rdx*8-0x8],xmm0                           ; 20b5
    mov r14,[rbp+0x330]                                        ; 20bb
    movsd xmm0,qword [r14+r10]                                 ; 20c2
    mov r14,[rbp+0x328]                                        ; 20c8
    divsd xmm0,[r14+r10]                                       ; 20cf
    movsd qword [r8+rdx*8-0x8],xmm0                            ; 20d5
    jmp short loc_20a0                                          ; 20dc
loc_20de:
    mov [rel $+7],rcx                                          ; 20de | REL32 +3 SPNCAZ$JCOMP addendLE=00000000
    mov [rel $+7],rcx                                          ; 20e5 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
    jmp short loc_214c                                          ; 20ec
loc_20ee:
    mov rax,[rbp+0x458]                                        ; 20ee
    mov qword [rax],0xffffffffffffffff                         ; 20f5
    movsd xmm0,qword [rel $+8]                                 ; 20fc | REL32 +4 SPNCAZ$XINP addendLE=00000000
    mov rax,[rbp+0x488]                                        ; 2104
    movsd qword [rax],xmm0                                     ; 210b
    movsd xmm0,qword [rel $+16]                                ; 210f | REL32 +4 SPNCAZ$XINP addendLE=08000000
    movsd qword [rax+0x8],xmm0                                 ; 2117
    mov rcx,[rbp+0x330]                                        ; 211c
    movsd xmm0,qword [rcx]                                     ; 2123
    mov rax,[rbp+0x328]                                        ; 2127
    divsd xmm0,[rax]                                           ; 212e
    movsd qword [rel $+8],xmm0                                 ; 2132 | REL32 +4 SPNCAZ$KVAL addendLE=00000000
    movsd xmm0,qword [rcx+0x8]                                 ; 213a
    divsd xmm0,[rax+0x8]                                       ; 213f
    movsd qword [rel $+16],xmm0                                ; 2144 | REL32 +4 SPNCAZ$KVAL addendLE=08000000
loc_214c:
    mov rax,[rbp+0x308]                                        ; 214c
    cmp qword [rax],0x3                                        ; 2153
    mov r14,[rbp+0x320]                                        ; 2157
    jnz near loc_1dc7                                           ; 215e
    sub rsp,0x90                                               ; 2164
    mov rax,[rbp+0x498]                                        ; 216b
    mov [rsp+0x80],rax                                         ; 2172
    lea rax,[rel $+7]                                          ; 217a | REL32 +3 SPNCAZ$KER addendLE=00000000
    mov [rsp+0x70],rax                                         ; 2181
    mov [rsp+0x68],r14                                         ; 2186
    mov r12,[rbp+0x2c8]                                        ; 218b
    mov [rsp+0x60],r12                                         ; 2192
    lea rax,[rel $+7]                                          ; 2197 | REL32 +3 SPNCAZ$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 219e
    mov rax,[rbp+0x328]                                        ; 21a3
    mov [rsp+0x50],rax                                         ; 21aa
    mov rax,[rbp+0x330]                                        ; 21af
    mov [rsp+0x48],rax                                         ; 21b6
    lea rax,[rel $+7]                                          ; 21bb | REL32 +3 SPNCAZ$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 21c2
    mov rax,[rbp+0x450]                                        ; 21c7
    mov [rsp+0x38],rax                                         ; 21ce
    mov rax,[rbp+0x460]                                        ; 21d3
    mov [rsp+0x30],rax                                         ; 21da
    mov rax,[rbp+0x488]                                        ; 21df
    mov [rsp+0x28],rax                                         ; 21e6
    mov rax,[rbp+0x478]                                        ; 21eb
    mov [rsp+0x20],rax                                         ; 21f2
    mov qword [rsp+0x78],0xa                                   ; 21f7
    lea rcx,[rel $+7]                                          ; 2200 | REL32 +3 SPNCAZ$FLASHTYPE addendLE=00000000
    mov rdx,[rbp+0x308]                                        ; 2207
    mov r8,[rbp+0x490]                                         ; 220e
    mov rbx,[rbp+0x338]                                        ; 2215
    mov r9,rbx                                                 ; 221c
    call $+5                                                   ; 221f | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 2224
    mov rax,[rbx]                                              ; 222b
    mov qword [rel $+7],0x1                                    ; 222e | REL32 +3 SPNCAZ$ICOMP addendLE=fcffffff
    xorpd xmm0,xmm0                                            ; 2239
    cmp rax,0x2                                                ; 223d
    jl short loc_226c                                           ; 2241
    lea rcx,[rax-0x1]                                          ; 2243
    xor edx,edx                                                ; 2247
loc_2249:
    movsd xmm1,qword [r12+rdx*8]                               ; 2249
    subsd xmm1,qword [r14+rdx*8]                               ; 224f
    mulsd xmm1,xmm1                                            ; 2255
    addsd xmm0,xmm1                                            ; 2259
    inc rdx                                                    ; 225d
    cmp rdx,rcx                                                ; 2260
    jl short loc_2249                                           ; 2263
    mov [rel $+7],rax                                          ; 2265 | REL32 +3 SPNCAZ$ICOMP addendLE=00000000
loc_226c:
    ucomisd xmm0,qword [rel $+8]                               ; 226c | REL32 +4 __real@3f847ae147ae147b addendLE=00000000
    jna near loc_1dc7                                           ; 2274
    mov rax,[rbp+0x468]                                        ; 227a
    mov qword [rax],0xffffffffffffffff                         ; 2281
    jmp near loc_1dc7                                           ; 2288

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x06,0x00,0x55,0x73,0x69,0x6e
    db 0x67,0x20,0x00,0x00,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x1c,0x00,0x0c,0x00,0x20,0x70,0x68,0x61,0x73,0x65,0x20,0x66,0x6c,0x61,0x73,0x68
    db 0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x02,0x00,0x00,0x00,0x1d,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x08,0x00,0x00,0x00
    db 0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x1d,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00
    db 0x47,0x00,0x01,0x00,0x1c,0x00,0x15,0x00,0x20,0x20,0x43,0x4f,0x4d,0x50,0x20,0x49
    db 0x44,0x20,0x20,0x20,0x43,0x4f,0x4d,0x50,0x20,0x4e,0x41,0x4d,0x45,0x00,0x00,0x00
    db 0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x17,0x00
    db 0x53,0x45,0x41,0x52,0x43,0x48,0x49,0x4e,0x47,0x20,0x41,0x5a,0x45,0x4f,0x54,0x52
    db 0x4f,0x50,0x45,0x20,0x41,0x54,0x20,0x00,0x22,0x00,0x00,0x04,0x01,0x00,0x00,0x00
    db 0x0f,0x00,0x00,0x00,0x1c,0x00,0x0a,0x00,0x20,0x4e,0x2f,0x4d,0x32,0x20,0x46,0x4f
    db 0x52,0x3a,0x00,0x00,0x37,0x00,0x00,0x00

; .rdata (COFF section 4)
coff_section_4:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .rdata (COFF section 5)
coff_section_5:
    db 0xea,0x8c,0xa0,0x39,0x59,0x3e,0x29,0x46

; .rdata (COFF section 6)
coff_section_6:
    db 0x95,0xd6,0x26,0xe8,0x0b,0x2e,0x11,0x3e

; .rdata (COFF section 7)
coff_section_7:
    db 0xa0,0xc2,0xeb,0xfe,0x4b,0x48,0xb4,0x39

; .rdata (COFF section 8)
coff_section_8:
    db 0x52,0xb8,0x1e,0x85,0xeb,0x51,0xf0,0x3f

; .rdata (COFF section 9)
coff_section_9:
    db 0x5c,0x8f,0xc2,0xf5,0x28,0x5c,0xef,0x3f

; .rdata (COFF section 10)
coff_section_10:
    db 0xae,0x47,0xe1,0x7a,0x14,0xae,0xef,0x3f

; .rdata (COFF section 11)
coff_section_11:
    db 0x7b,0x14,0xae,0x47,0xe1,0x7a,0x84,0x3f

; .rdata (COFF section 12)
coff_section_12:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f

; .rdata (COFF section 13)
coff_section_13:
    db 0x2d,0x43,0x1c,0xeb,0xe2,0x36,0x2a,0x3f

; .rdata (COFF section 14)
coff_section_14:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80

; .rdata (COFF section 15)
coff_section_15:
    db 0x33,0x33,0x33,0x33,0x33,0x33,0xc3,0x3f

; .rdata (COFF section 16)
coff_section_16:
    db 0x33,0x33,0x33,0x33,0x33,0x33,0xc3,0xbf

; .rdata (COFF section 17)
coff_section_17:
    db 0xcd,0xcc,0xcc,0xcc,0xcc,0xcc,0xec,0x3f

; .rdata (COFF section 18)
coff_section_18:
    db 0x00,0x00,0x00,0xc0,0xcc,0xcc,0xec,0x3f

; .xdata (COFF section 19)
coff_section_19:
    db 0x01,0x73,0x1f,0x85,0x73,0x68,0x3c,0x00,0x6b,0x78,0x3d,0x00,0x63,0x88,0x3e,0x00
    db 0x5a,0x98,0x3f,0x00,0x51,0xa8,0x40,0x00,0x48,0xb8,0x41,0x00,0x3f,0xc8,0x42,0x00
    db 0x36,0xd8,0x43,0x00,0x2d,0xe8,0x44,0x00,0x24,0xf8,0x45,0x00,0x1b,0x03,0x13,0x01
    db 0x8d,0x00,0x0c,0x30,0x0b,0x70,0x0a,0x60,0x09,0xc0,0x07,0xd0,0x05,0xe0,0x03,0xf0
    db 0x01,0x50,0x00,0x00

; .rdata (COFF section 20)
coff_section_20:
    db 0x49,0x43,0x4f,0x4d,0x50,0x2c,0x58,0x2c,0x4b,0x41,0x74,0x20,0x74,0x65,0x72,0x6d
    db 0x69,0x6e,0x61,0x74,0x69,0x6f,0x6e,0x3a,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x41,0x63,0x74,0x75,0x61,0x6c,0x20,0x58,0x53,0x54,0x45,0x50,0x20,0x61,0x6e,0x64
    db 0x20,0x6e,0x65,0x77,0x20,0x58,0x54,0x3a,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x46,0x58,0x2c,0x20,0x46,0x30,0x2c,0x20,0x58,0x54,0x2c,0x20,0x53,0x4c,0x4f,0x50
    db 0x45,0x2c,0x20,0x58,0x53,0x54,0x45,0x50,0x20,0x3a,0x20,0x4b,0x76,0x61,0x6c,0x75
    db 0x65,0x73,0x20,0x20,0x46,0x58,0x20,0x69,0x73,0x20,0x41,0x74,0x20,0x58,0x54,0x20
    db 0x53,0x45,0x56,0x45,0x52,0x45,0x20,0x45,0x52,0x52,0x4f,0x52,0x3a,0x20,0x43,0x4f
    db 0x4d,0x50,0x4f,0x4e,0x45,0x4e,0x54,0x20,0x4d,0x4f,0x4c,0x45,0x20,0x46,0x52,0x41
    db 0x43,0x54,0x49,0x4f,0x4e,0x4d,0x49,0x53,0x53,0x49,0x4e,0x47,0x20,0x49,0x4e,0x20
    db 0x41,0x5a,0x45,0x4f,0x54,0x52,0x4f,0x50,0x45,0x20,0x53,0x45,0x41,0x52,0x43,0x48
    db 0x53,0x50,0x4e,0x43,0x41,0x5a,0x20,0x74,0x65,0x72,0x6d,0x69,0x6e,0x61,0x74,0x65
    db 0x64,0x20,0x64,0x75,0x65,0x20,0x74,0x6f,0x20,0x6e,0x6f,0x6e,0x63,0x6f,0x6e,0x76
    db 0x65,0x72,0x67,0x65,0x6e,0x63,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x53,0x45,0x56,0x45,0x52,0x45,0x20,0x45,0x52,0x52,0x4f,0x52,0x3a,0x20,0x43,0x4f
    db 0x4d,0x50,0x4f,0x4e,0x45,0x4e,0x54,0x20,0x4d,0x4f,0x4c,0x45,0x20,0x46,0x52,0x41
    db 0x43,0x54,0x49,0x4f,0x4e,0x20,0x4d,0x49,0x53,0x53,0x49,0x4e,0x47,0x20,0x49,0x4e
    db 0x20,0x41,0x5a,0x45,0x4f,0x54,0x52,0x4f,0x50,0x45,0x20,0x43,0x41,0x4c,0x43,0x55
    db 0x4c,0x41,0x54,0x49,0x4f,0x4e,0x49,0x46,0x4c,0x41,0x47,0x20,0x69,0x73,0x20,0x4e
    db 0x65,0x77,0x20,0x58,0x2c,0x20,0x4b,0x20,0x6f,0x66,0x20,0x59,0x2c,0x58,0x2c,0x58
    db 0x31,0x2c,0x58,0x32,0x20,0x6f,0x66,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x53,0x45,0x41,0x52,0x43,0x48,0x20,0x54,0x45,0x52,0x4d,0x49,0x4e,0x41,0x54,0x45
    db 0x44,0x20,0x42,0x45,0x43,0x41,0x55,0x53,0x45,0x20,0x41,0x20,0x4d,0x4f,0x4c,0x45
    db 0x20,0x20,0x20,0x20,0x20,0x46,0x52,0x41,0x43,0x54,0x49,0x4f,0x4e,0x20,0x57,0x41
    db 0x53,0x20,0x44,0x52,0x49,0x56,0x45,0x4e,0x20,0x54,0x4f,0x20,0x5a,0x45,0x52,0x4f
    db 0x20,0x69,0x73,0x20,0x43,0x6f,0x6d,0x70,0x6f,0x6e,0x65,0x6e,0x74,0x00,0x00,0x00
    db 0x45,0x72,0x72,0x6f,0x72,0x20,0x69,0x6e,0x20,0x69,0x6e,0x66,0x20,0x64,0x69,0x6c
    db 0x20,0x4b,0x76,0x61,0x6c,0x73,0x20,0x69,0x6e,0x20,0x53,0x50,0x4e,0x43,0x41,0x5a
    db 0x53,0x65,0x61,0x72,0x63,0x68,0x20,0x66,0x6f,0x72,0x20,0x61,0x7a,0x65,0x6f,0x74
    db 0x72,0x6f,0x70,0x65,0x20,0x69,0x6d,0x70,0x6f,0x73,0x73,0x69,0x62,0x6c,0x65,0x20
    db 0x62,0x65,0x63,0x61,0x75,0x73,0x65,0x20,0x6f,0x6e,0x6c,0x79,0x20,0x74,0x77,0x65
    db 0x6e,0x74,0x79,0x20,0x63,0x6f,0x6d,0x70,0x6f,0x6e,0x65,0x6e,0x74,0x73,0x20,0x61
    db 0x6c,0x6c,0x6f,0x77,0x65,0x64,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x53,0x65,0x61,0x72,0x63,0x68,0x20,0x66,0x6f,0x72,0x20,0x61,0x7a,0x65,0x6f,0x74
    db 0x72,0x6f,0x70,0x65,0x20,0x69,0x6d,0x70,0x6f,0x73,0x73,0x69,0x62,0x6c,0x65,0x20
    db 0x62,0x65,0x63,0x61,0x75,0x73,0x65,0x20,0x6c,0x65,0x73,0x73,0x20,0x74,0x68,0x61
    db 0x6e,0x20,0x74,0x77,0x6f,0x20,0x63,0x6f,0x6d,0x70,0x6f,0x6e,0x65,0x6e,0x74,0x73
    db 0x20,0x67,0x69,0x76,0x65,0x6e,0x21,0x50,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f
    db 0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00

; .drectve (COFF section 21)
coff_section_21:
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

; .pdata (COFF section 22)
coff_section_22:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x0000228d ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 51)
