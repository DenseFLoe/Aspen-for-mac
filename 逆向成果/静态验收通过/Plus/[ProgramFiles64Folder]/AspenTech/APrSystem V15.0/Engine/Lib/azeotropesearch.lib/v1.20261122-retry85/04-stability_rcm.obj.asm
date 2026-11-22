; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

STABILITY_RCM:
    push rbp                                                   ; 0000
    push r15                                                   ; 0001
    push r14                                                   ; 0003
    push r13                                                   ; 0005
    push r12                                                   ; 0007
    push rsi                                                   ; 0009
    push rdi                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x78                                               ; 000c
    lea rbp,[rsp+0x70]                                         ; 0010
    mov [rbp-0x50],r9                                          ; 0015
    mov [rbp-0x28],r8                                          ; 0019
    mov [rbp-0x68],rdx                                         ; 001d
    mov rdi,rcx                                                ; 0021
    mov r8,[rbp+0xa0]                                          ; 0024
    mov rax,[rcx]                                              ; 002b
    lea r9,[rax-0x1]                                           ; 002e
    mov r10,rax                                                ; 0032
    test r9,r9                                                 ; 0035
    mov edx,0x0                                                ; 0038
    cmovg rdx,r9                                               ; 003d
    mov rax,rdx                                                ; 0041
    imul rax,rdx                                               ; 0044
    lea rcx,[rax*8+0xf]                                        ; 0048
    and rcx,0xfffffffffffffff0                                 ; 0050
    mov rax,rcx                                                ; 0054
    call $+5                                                   ; 0057 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 005c
    mov [rbp-0x38],rsp                                         ; 005f
    mov rax,rcx                                                ; 0063
    call $+5                                                   ; 0066 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 006b
    mov [rbp-0x20],rsp                                         ; 006e
    lea rax,[rdx*8+0xf]                                        ; 0072
    and rax,0xfffffffffffffff0                                 ; 007a
    call $+5                                                   ; 007e | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0083
    mov [rbp-0x18],rsp                                         ; 0086
    lea rdx,[r10+r10*4]                                        ; 008a
    test rdx,rdx                                               ; 008e
    mov eax,0x0                                                ; 0091
    mov [rbp-0x58],rdx                                         ; 0096
    cmovg rax,rdx                                              ; 009a
    lea rax,[rax*8+0xf]                                        ; 009e
    and rax,0xfffffffffffffff0                                 ; 00a6
    call $+5                                                   ; 00aa | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00af
    mov [rbp-0x8],rsp                                          ; 00b2
    mov rax,rcx                                                ; 00b6
    call $+5                                                   ; 00b9 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00be
    mov [rbp-0x10],rsp                                         ; 00c1
    test r10,r10                                               ; 00c5
    mov eax,0x0                                                ; 00c8
    cmovg rax,r10                                              ; 00cd
    mov [rbp-0x30],r10                                         ; 00d1
    lea rdx,[rax*8+0xf]                                        ; 00d5
    and rdx,0xfffffffffffffff0                                 ; 00dd
    mov rax,rdx                                                ; 00e1
    call $+5                                                   ; 00e4 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00e9
    mov [rbp-0x48],rsp                                         ; 00ec
    mov rax,rdx                                                ; 00f0
    call $+5                                                   ; 00f3 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00f8
    mov rsi,rsp                                                ; 00fb
    mov rax,rdx                                                ; 00fe
    call $+5                                                   ; 0101 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0106
    mov rbx,rsp                                                ; 0109
    mov rax,rdx                                                ; 010c
    call $+5                                                   ; 010f | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0114
    mov r15,rsp                                                ; 0117
    mov rax,rdx                                                ; 011a
    call $+5                                                   ; 011d | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0122
    mov r14,rsp                                                ; 0125
    mov rax,rdx                                                ; 0128
    call $+5                                                   ; 012b | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0130
    mov r12,rsp                                                ; 0133
    mov rax,rdx                                                ; 0136
    call $+5                                                   ; 0139 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 013e
    mov r13,rsp                                                ; 0141
    mov rax,rcx                                                ; 0144
    call $+5                                                   ; 0147 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 014c
    mov rcx,rsp                                                ; 014f
    lea rdx,[r10*8-0x8]                                        ; 0152
    mov qword [r8],0x0                                         ; 015a
    mov rax,0x3eb0c6f7a0b5ed8d                                 ; 0161
    mov [rel $+7],rax                                          ; 016b | REL32 +3 STABILITY_RCM$XSTEP addendLE=00000000
    mov word [rel $+7],0x5650                                  ; 0172 | REL32 +3 STABILITY_RCM$FLASHTYPE addendLE=feffffff
    mov byte [rel $+8],0x0                                     ; 017b | REL32 +2 STABILITY_RCM$FLASHTYPE addendLE=01000000
    mov qword [rel $+7],0x0                                    ; 0182 | REL32 +3 STABILITY_RCM$VFRAC addendLE=fcffffff
    mov [rel $+7],r9                                           ; 018d | REL32 +3 STABILITY_RCM$NEQ addendLE=00000000
    mov [rbp-0x60],rdx                                         ; 0194
    mov r8,rdx                                                 ; 0198
    mov [rbp-0x40],r9                                          ; 019b
    imul r8,r9                                                 ; 019f
    sub rsp,0x20                                               ; 01a3
    mov [rbp+0x0],rcx                                          ; 01a7
    xor edx,edx                                                ; 01ab
    call $+5                                                   ; 01ad | REL32 +1 _intel_fast_memset addendLE=00000000
    mov rax,[rbp-0x30]                                         ; 01b2
    add rsp,0x20                                               ; 01b6
    cmp rax,0x2                                                ; 01ba
    jnl short loc_01f6                                          ; 01be
    mov qword [rel $+7],0x1                                    ; 01c0 | REL32 +3 STABILITY_RCM$I addendLE=fcffffff
    mov rsi,[rbp+0x90]                                         ; 01cb
    mov r9,[rbp+0x98]                                          ; 01d2
    mov rdx,[rbp-0x28]                                         ; 01d9
    mov r10,[rbp-0x20]                                         ; 01dd
    mov r11,[rbp-0x18]                                         ; 01e1
    mov rbx,[rbp-0x10]                                         ; 01e5
    mov r8,[rbp-0x8]                                           ; 01e9
    mov rcx,[rbp-0x58]                                         ; 01ed
    jmp near loc_05ba                                           ; 01f1
loc_01f6:
    lea rax,[rax*8+0x0]                                        ; 01f6
    xor ecx,ecx                                                ; 01fe
    mov rdx,0x3ff0000000000000                                 ; 0200
    mov r8,[rbp+0x0]                                           ; 020a
    mov r9,[rbp-0x40]                                          ; 020e
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0212 | nop word [cs:rax+rax+0x0]
loc_0220:
    mov [r8],rdx                                               ; 0220
    add r8,rax                                                 ; 0223
    inc rcx                                                    ; 0226
    cmp rcx,r9                                                 ; 0229
    jl short loc_0220                                           ; 022c
    mov qword [rel $+7],0x1                                    ; 022e | REL32 +3 STABILITY_RCM$I addendLE=fcffffff
    jmp short loc_0255                                          ; 0239
    nop dword [byte rax+rax+0x0]                               ; 023b
loc_0240:
    lea rcx,[rax+0x1]                                          ; 0240
    mov [rel $+7],rcx                                          ; 0244 | REL32 +3 STABILITY_RCM$I addendLE=00000000
    cmp rax,[rbp-0x40]                                         ; 024b
    jnl near loc_0553                                           ; 024f
loc_0255:
    sub rsp,0x40                                               ; 0255
    mov [rsp+0x30],r12                                         ; 0259
    mov [rsp+0x28],r13                                         ; 025e
    mov rax,[rbp-0x68]                                         ; 0263
    mov [rsp+0x20],rax                                         ; 0267
    mov rcx,rdi                                                ; 026c
    lea rdx,[rel $+7]                                          ; 026f | REL32 +3 STABILITY_RCM$XSTEP addendLE=00000000
    lea r8,[rel $+7]                                           ; 0276 | REL32 +3 STABILITY_RCM$I addendLE=00000000
    mov r9,rdi                                                 ; 027d
    call $+5                                                   ; 0280 | REL32 +1 COMP_DRIV addendLE=00000000
    sub rsp,0x50                                               ; 0285
    mov rax,[rbp+0xa8]                                         ; 0289
    mov [rsp+0x80],rax                                         ; 0290
    lea rax,[rel $+7]                                          ; 0298 | REL32 +3 STABILITY_RCM$KERR addendLE=00000000
    mov [rsp+0x70],rax                                         ; 029f
    mov [rsp+0x68],rsi                                         ; 02a4
    mov [rsp+0x60],rbx                                         ; 02a9
    lea rax,[rel $+7]                                          ; 02ae | REL32 +3 STABILITY_RCM$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 02b5
    mov rax,[rbp-0x48]                                         ; 02ba
    mov [rsp+0x50],rax                                         ; 02be
    mov [rsp+0x48],r14                                         ; 02c3
    lea rax,[rel $+7]                                          ; 02c8 | REL32 +3 STABILITY_RCM$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 02cf
    mov rax,[rbp-0x50]                                         ; 02d4
    mov [rsp+0x38],rax                                         ; 02d8
    lea rax,[rel $+7]                                          ; 02dd | REL32 +3 STABILITY_RCM$TEMP addendLE=00000000
    mov [rsp+0x30],rax                                         ; 02e4
    mov [rsp+0x28],r13                                         ; 02e9
    mov rax,[rbp+0x70]                                         ; 02ee
    mov [rsp+0x20],rax                                         ; 02f2
    mov qword [rsp+0x78],0x3                                   ; 02f7
    lea rcx,[rel $+7]                                          ; 0300 | REL32 +3 STABILITY_RCM$FLASHTYPE addendLE=00000000
    mov rdx,[rbp+0x80]                                         ; 0307
    mov r8,[rbp+0x78]                                          ; 030e
    mov r9,rdi                                                 ; 0312
    call $+5                                                   ; 0315 | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 031a
    cmp qword [rel $+7],0x0                                    ; 0321 | REL32 +3 STABILITY_RCM$KERR addendLE=ffffffff
    jz near loc_03ba                                            ; 0329
    jng short loc_0370                                          ; 032f
    mov qword [rel $+7],0x1f6                                  ; 0331 | REL32 +3 STABILITY_RCM$IMSG addendLE=fcffffff
    sub rsp,0x30                                               ; 033c
    mov qword [rsp+0x20],0xf                                   ; 0340
    mov r9d,0xf                                                ; 0349
    lea rcx,[rel $+7]                                          ; 034f | REL32 +3 STABILITY_RCM$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0356 | REL32 +3 STABILITY_RCM$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 035d | REL32 +3 STABILITY_RCM$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 0364 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 0369
    jmp short loc_03ba                                          ; 036d
    nop                                                        ; 036f
loc_0370:
    mov qword [rel $+7],0x1fb                                  ; 0370 | REL32 +3 STABILITY_RCM$IMSG addendLE=fcffffff
    sub rsp,0x30                                               ; 037b
    mov qword [rsp+0x20],0xf                                   ; 037f
    mov r9d,0xf                                                ; 0388
    lea rcx,[rel $+7]                                          ; 038e | REL32 +3 STABILITY_RCM$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0395 | REL32 +3 STABILITY_RCM$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 039c | REL32 +3 STABILITY_RCM$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 03a3 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 03a8
    mov rax,[rbp+0xa0]                                         ; 03ac
    mov qword [rax],0xffffffffffffffff                         ; 03b3
loc_03ba:
    sub rsp,0x90                                               ; 03ba
    mov rax,[rbp+0xa8]                                         ; 03c1
    mov [rsp+0x80],rax                                         ; 03c8
    lea rax,[rel $+7]                                          ; 03d0 | REL32 +3 STABILITY_RCM$KERR addendLE=00000000
    mov [rsp+0x70],rax                                         ; 03d7
    mov [rsp+0x68],rsi                                         ; 03dc
    mov [rsp+0x60],rbx                                         ; 03e1
    lea rax,[rel $+7]                                          ; 03e6 | REL32 +3 STABILITY_RCM$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 03ed
    mov rax,[rbp-0x48]                                         ; 03f2
    mov [rsp+0x50],rax                                         ; 03f6
    mov [rsp+0x48],r15                                         ; 03fb
    lea rax,[rel $+7]                                          ; 0400 | REL32 +3 STABILITY_RCM$VFRAC addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0407
    mov rax,[rbp-0x50]                                         ; 040c
    mov [rsp+0x38],rax                                         ; 0410
    lea rax,[rel $+7]                                          ; 0415 | REL32 +3 STABILITY_RCM$TEMP addendLE=00000000
    mov [rsp+0x30],rax                                         ; 041c
    mov [rsp+0x28],r12                                         ; 0421
    mov rax,[rbp+0x70]                                         ; 0426
    mov [rsp+0x20],rax                                         ; 042a
    mov qword [rsp+0x78],0x3                                   ; 042f
    lea rcx,[rel $+7]                                          ; 0438 | REL32 +3 STABILITY_RCM$FLASHTYPE addendLE=00000000
    mov rdx,[rbp+0x80]                                         ; 043f
    mov r8,[rbp+0x78]                                          ; 0446
    mov r9,rdi                                                 ; 044a
    call $+5                                                   ; 044d | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 0452
    cmp qword [rel $+7],0x0                                    ; 0459 | REL32 +3 STABILITY_RCM$KERR addendLE=ffffffff
    jz near loc_04fa                                            ; 0461
    jng short loc_04b0                                          ; 0467
    mov qword [rel $+7],0x1f6                                  ; 0469 | REL32 +3 STABILITY_RCM$IMSG addendLE=fcffffff
    sub rsp,0x30                                               ; 0474
    mov qword [rsp+0x20],0xf                                   ; 0478
    mov r9d,0xf                                                ; 0481
    lea rcx,[rel $+7]                                          ; 0487 | REL32 +3 STABILITY_RCM$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 048e | REL32 +3 STABILITY_RCM$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 0495 | REL32 +3 STABILITY_RCM$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 049c | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 04a1
    jmp short loc_04fa                                          ; 04a5
    nop word [dword rax+rax+0x0]                               ; 04a7
loc_04b0:
    mov qword [rel $+7],0x1fb                                  ; 04b0 | REL32 +3 STABILITY_RCM$IMSG addendLE=fcffffff
    sub rsp,0x30                                               ; 04bb
    mov qword [rsp+0x20],0xf                                   ; 04bf
    mov r9d,0xf                                                ; 04c8
    lea rcx,[rel $+7]                                          ; 04ce | REL32 +3 STABILITY_RCM$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 04d5 | REL32 +3 STABILITY_RCM$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 04dc | REL32 +3 STABILITY_RCM$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 04e3 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 04e8
    mov rax,[rbp+0xa0]                                         ; 04ec
    mov qword [rax],0xffffffffffffffff                         ; 04f3
loc_04fa:
    mov rcx,[rel $+7]                                          ; 04fa | REL32 +3 STABILITY_RCM$NEQ addendLE=00000000
    mov rax,[rel $+7]                                          ; 0501 | REL32 +3 STABILITY_RCM$I addendLE=00000000
    test rcx,rcx                                               ; 0508
    jng near loc_0240                                           ; 050b
    movsd xmm0,qword [rel $+8]                                 ; 0511 | REL32 +4 STABILITY_RCM$XSTEP addendLE=00000000
    lea rdx,[rax-0x1]                                          ; 0519
    imul rdx,[rbp-0x60]                                        ; 051d
    add rdx,[rbp-0x38]                                         ; 0522
    xor r8d,r8d                                                ; 0526
    nop dword [dword rax+0x0]                                  ; 0529
loc_0530:
    movsd xmm1,qword [r14+r8*8]                                ; 0530
    subsd xmm1,qword [r15+r8*8]                                ; 0536
    divsd xmm1,xmm0                                            ; 053c
    movsd qword [rdx+r8*8],xmm1                                ; 0540
    inc r8                                                     ; 0546
    cmp rcx,r8                                                 ; 0549
    jnz short loc_0530                                          ; 054c
    jmp near loc_0240                                           ; 054e
loc_0553:
    mov rcx,[rbp-0x30]                                         ; 0553
    lea rax,[rcx-0x2]                                          ; 0557
    imul rax,rcx                                               ; 055b
    inc rax                                                    ; 055f
    xor ecx,ecx                                                ; 0562
    mov rdx,[rbp-0x28]                                         ; 0564
    mov rbx,[rbp-0x10]                                         ; 0568
    mov r8,[rbp-0x38]                                          ; 056c
    mov r9,[rbp+0x0]                                           ; 0570
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0574 | nop word [cs:rax+rax+0x0]
loc_0580:
    movsd xmm0,qword [r9+rcx*8]                                ; 0580
    subsd xmm0,qword [r8+rcx*8]                                ; 0586
    movsd qword [rbx+rcx*8],xmm0                               ; 058c
    inc rcx                                                    ; 0591
    cmp rax,rcx                                                ; 0594
    jnz short loc_0580                                          ; 0597
    mov rax,[rdi]                                              ; 0599
    lea rcx,[rax+rax*4]                                        ; 059c
    mov rsi,[rbp+0x90]                                         ; 05a0
    mov r9,[rbp+0x98]                                          ; 05a7
    mov r10,[rbp-0x20]                                         ; 05ae
    mov r11,[rbp-0x18]                                         ; 05b2
    mov r8,[rbp-0x8]                                           ; 05b6
loc_05ba:
    cmp qword [rdx],0x1                                        ; 05ba
    setnz al                                                   ; 05be
    shl al,byte 0x3                                            ; 05c1
    add al,0x4e                                                ; 05c4
    mov [rel $+6],al                                           ; 05c6 | REL32 +2 STABILITY_RCM$JOBVR addendLE=00000000
    lea rdx,[rel $+7]                                          ; 05cc | REL32 +3 STABILITY_RCM$JOBVR addendLE=00000000
    mov [rel $+7],rcx                                          ; 05d3 | REL32 +3 STABILITY_RCM$LWORK addendLE=00000000
    lea rax,[rel $+7]                                          ; 05da | REL32 +3 STABILITY_RCM$LWORK addendLE=00000000
    sub rsp,0x80                                               ; 05e1
    lea rcx,[rel $+7]                                          ; 05e8 | REL32 +3 STABILITY_RCM$INFO addendLE=00000000
    mov [rsp+0x68],rcx                                         ; 05ef
    mov [rsp+0x60],rax                                         ; 05f4
    mov [rsp+0x58],r8                                          ; 05f9
    lea r8,[rel $+7]                                           ; 05fe | REL32 +3 STABILITY_RCM$NEQ addendLE=00000000
    mov [rsp+0x50],r8                                          ; 0605
    mov [rsp+0x48],r9                                          ; 060a
    mov [rsp+0x40],r8                                          ; 060f
    mov [rsp+0x38],r10                                         ; 0614
    mov [rsp+0x30],r11                                         ; 0619
    mov [rsp+0x28],rsi                                         ; 061e
    mov [rsp+0x20],r8                                          ; 0623
    mov qword [rsp+0x78],0x1                                   ; 0628
    mov qword [rsp+0x70],0x1                                   ; 0631
    lea rcx,[rel $+7]                                          ; 063a | REL32 +3 strlit.1 addendLE=00000000
    mov r9,rbx                                                 ; 0641
    call $+5                                                   ; 0644 | REL32 +1 DGEEV addendLE=00000000
    add rsp,0x80                                               ; 0649
    cmp qword [rel $+7],0x0                                    ; 0650 | REL32 +3 STABILITY_RCM$INFO addendLE=ffffffff
    jz short loc_06a6                                           ; 0658
    mov qword [rel $+7],0x1fc                                  ; 065a | REL32 +3 STABILITY_RCM$IMSG addendLE=fcffffff
    lea rcx,[rel $+7]                                          ; 0665 | REL32 +3 STABILITY_RCM$IMSG addendLE=00000000
    sub rsp,0x30                                               ; 066c
    mov qword [rsp+0x20],0xf                                   ; 0670
    lea rdx,[rel $+7]                                          ; 0679 | REL32 +3 STABILITY_RCM$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 0680 | REL32 +3 STABILITY_RCM$OPT_MESSAGE addendLE=00000000
    mov r9d,0xf                                                ; 0687
    call $+5                                                   ; 068d | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 0692
    mov rax,[rbp+0xa0]                                         ; 0696
    mov qword [rax],0xfffffffffffffffe                         ; 069d
    jmp short loc_071b                                          ; 06a4
loc_06a6:
    mov rax,[rbp+0x88]                                         ; 06a6
    mov rcx,[rel $+7]                                          ; 06ad | REL32 +3 STABILITY_RCM$NEQ addendLE=00000000
    mov qword [rel $+7],0x1                                    ; 06b4 | REL32 +3 STABILITY_RCM$I addendLE=fcffffff
    test rcx,rcx                                               ; 06bf
    jng short loc_0714                                          ; 06c2
    mov r8,0xffffffffffffffff                                  ; 06c4
    xor r10d,r10d                                              ; 06cb
    xorpd xmm0,xmm0                                            ; 06ce
    xor r11d,r11d                                              ; 06d2
    xor edx,edx                                                ; 06d5
    mov r9,0xffffffffffffffff                                  ; 06d7
    o16 nop                                                    ; 06de
loc_06e0:
    ucomisd xmm0,qword [rsi+r11*8]                             ; 06e0
    cmovna r9,r10                                              ; 06e6
    cmova rdx,r8                                               ; 06ea
    inc r11                                                    ; 06ee
    cmp r11,rcx                                                ; 06f1
    jl short loc_06e0                                           ; 06f4
    inc rcx                                                    ; 06f6
    mov [rel $+7],rcx                                          ; 06f9 | REL32 +3 STABILITY_RCM$I addendLE=00000000
    test r9b,0x1                                               ; 0700
    jnz short loc_0714                                          ; 0704
    test dl,0x1                                                ; 0706
    jnz short loc_072c                                          ; 0709
    mov qword [rax],0x3                                        ; 070b
    jmp short loc_071b                                          ; 0712
loc_0714:
    mov qword [rax],0x1                                        ; 0714
loc_071b:
    lea rsp,[rbp+0x8]                                          ; 071b
    pop rbx                                                    ; 071f
    pop rdi                                                    ; 0720
    pop rsi                                                    ; 0721
    pop r12                                                    ; 0722
    pop r13                                                    ; 0724
    pop r14                                                    ; 0726
    pop r15                                                    ; 0728
    pop rbp                                                    ; 072a
    retq                                                       ; 072b
loc_072c:
    mov qword [rax],0x2                                        ; 072c
    jmp short loc_071b                                          ; 0733

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x53,0x74,0x61,0x62,0x69,0x6c,0x69,0x74,0x79,0x5f,0x52,0x43,0x4d,0x00,0x20

; .xdata (COFF section 4)
coff_section_4:
    db 0x01,0x15,0x0a,0x75,0x15,0x03,0x10,0xe2,0x0c,0x30,0x0b,0x70,0x0a,0x60,0x09,0xc0
    db 0x07,0xd0,0x05,0xe0,0x03,0xf0,0x01,0x50

; .rdata (COFF section 5)
coff_section_5:
    db 0x4e,0x50,0x56,0x00

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
    dd 0x00000735 ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 6)
