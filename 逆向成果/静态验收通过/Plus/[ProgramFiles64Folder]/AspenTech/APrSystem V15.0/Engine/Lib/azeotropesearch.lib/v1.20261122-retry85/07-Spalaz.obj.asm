; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

SPALAZ:
    push rbp                                                   ; 0000
    push r15                                                   ; 0001
    push r14                                                   ; 0003
    push r13                                                   ; 0005
    push r12                                                   ; 0007
    push rsi                                                   ; 0009
    push rdi                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0x1c8                                              ; 000c
    lea rbp,[rsp+0x80]                                         ; 0013
    movapd oword [rbp+0x130],xmm8                              ; 001b
    movapd oword [rbp+0x120],xmm7                              ; 0024
    movapd oword [rbp+0x110],xmm6                              ; 002c
    mov rbx,r8                                                 ; 0034
    mov [rbp+0xd8],rcx                                         ; 0037
    mov r13,0x801208384ff00                                    ; 003e
    mov r14,[r8]                                               ; 0048
    xor eax,eax                                                ; 004b
    test r14,r14                                               ; 004d
    cmovg rax,r14                                              ; 0050
    lea rcx,[rax*8+0xf]                                        ; 0054
    and rcx,0xfffffffffffffff0                                 ; 005c
    mov rax,rcx                                                ; 0060
    call $+5                                                   ; 0063 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0068
    mov r8,rsp                                                 ; 006b
    mov rax,rcx                                                ; 006e
    call $+5                                                   ; 0071 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0076
    mov r10,rsp                                                ; 0079
    mov rax,rcx                                                ; 007c
    call $+5                                                   ; 007f | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0084
    mov rdi,rsp                                                ; 0087
    mov rax,rcx                                                ; 008a
    call $+5                                                   ; 008d | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0092
    mov rax,rsp                                                ; 0095
    mov byte [rel $+8],0x0                                     ; 0098 | REL32 +2 SPALAZ$FLASHTYPE addendLE=01000000
    mov word [rel $+7],0x5650                                  ; 009f | REL32 +3 SPALAZ$FLASHTYPE addendLE=feffffff
    mov qword [rel $+7],0x0                                    ; 00a8 | REL32 +3 SPALAZ$VFRAC addendLE=fcffffff
    mov [rbp+0x90],rdx                                         ; 00b3
    mov r15,[rdx]                                              ; 00ba
    mov r11,r14                                                ; 00bd
    cmp r15,0x3                                                ; 00c0
    mov [rbp+0xf0],r9                                          ; 00c4
    mov [rbp+0xe0],r8                                          ; 00cb
    mov [rbp+0xe8],r10                                         ; 00d2
    jng near loc_0287                                           ; 00d9
    mov [rbp+0x100],rax                                        ; 00df
    mov qword [rbp+0x50],0x0                                   ; 00e6
    mov word [rbp+0xfc],0x1                                    ; 00ee
    sub rsp,0x30                                               ; 00f7
    lea rax,[rel $+263]                                        ; 00fb | REL32 +3 SPALAZ$format_pack addendLE=00010000
    mov [rsp+0x28],rax                                         ; 0102
    mov qword [rsp+0x20],0x0                                   ; 0107
    lea rsi,[rbp+0x50]                                         ; 0110
    lea r9,[rbp+0xfc]                                          ; 0114
    mov rcx,rsi                                                ; 011b
    xor edx,edx                                                ; 011e
    mov r8,r13                                                 ; 0120
    call $+5                                                   ; 0123 | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 0128
    mov qword [rbp+0x50],0x0                                   ; 012c
    mov word [rbp+0xfe],0x1                                    ; 0134
    sub rsp,0x30                                               ; 013d
    lea rax,[rel $+215]                                        ; 0141 | REL32 +3 SPALAZ$format_pack addendLE=d0000000
    mov [rsp+0x28],rax                                         ; 0148
    mov qword [rsp+0x20],0x0                                   ; 014d
    lea r9,[rbp+0xfe]                                          ; 0156
    mov rcx,rsi                                                ; 015d
    xor edx,edx                                                ; 0160
    mov r8,r13                                                 ; 0162
    call $+5                                                   ; 0165 | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 016a
    mov r12,[rbx]                                              ; 016e
    mov qword [rel $+7],0x1                                    ; 0171 | REL32 +3 SPALAZ$ICOMP addendLE=fcffffff
    test r12,r12                                               ; 017c
    jng near loc_0c44                                           ; 017f
    mov [rbp+0x108],rbx                                        ; 0185
    xor eax,eax                                                ; 018c
    lea rbx,[rbp+0xa8]                                         ; 018e
    lea r13,[rbp-0x30]                                         ; 0195
    nop dword [dword rax+0x0]                                  ; 0199
loc_01a0:
    lea rcx,[rel $+7]                                          ; 01a0 | REL32 +3 SPALAZ$COMIDS addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 01a7
    mov qword [rbp+0x50],0x0                                   ; 01ab
    mov dword [rbp+0xa4],0x20638                               ; 01b3
    mov qword [rbp-0x78],0x8                                   ; 01bd
    mov [rbp-0x70],rax                                         ; 01c5
    mov qword [rbp-0x68],0x8                                   ; 01c9
    sub rsp,0x30                                               ; 01d1
    lea rax,[rel $+159]                                        ; 01d5 | REL32 +3 SPALAZ$format_pack addendLE=98000000
    mov [rsp+0x28],rax                                         ; 01dc
    lea rax,[rbp-0x78]                                         ; 01e1
    mov [rsp+0x20],rax                                         ; 01e5
    mov rcx,rsi                                                ; 01ea
    xor edx,edx                                                ; 01ed
    mov r8,0x801208384ff00                                     ; 01ef
    lea r9,[rbp+0xa4]                                          ; 01f9
    call $+5                                                   ; 0200 | REL32 +1 for_write_seq_fmt addendLE=00000000
    add rsp,0x30                                               ; 0205
    mov dword [rbp+0xa8],0x10438                               ; 0209
    mov qword [rbp-0x30],0x20                                  ; 0213
    lea rax,[rel $+7]                                          ; 021b | REL32 +3 SPALAZ$CNAME addendLE=00000000
    mov [rbp-0x28],rax                                         ; 0222
    sub rsp,0x20                                               ; 0226
    mov rcx,rsi                                                ; 022a
    mov rdx,rbx                                                ; 022d
    mov r8,r13                                                 ; 0230
    call $+5                                                   ; 0233 | REL32 +1 for_write_seq_fmt_xmit addendLE=00000000
    add rsp,0x20                                               ; 0238
    mov rax,[rel $+7]                                          ; 023c | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 0243
    mov [rel $+7],rcx                                          ; 0247 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    cmp rax,r12                                                ; 024e
    jl near loc_01a0                                            ; 0251
    mov rbx,[rbp+0x108]                                        ; 0257
    mov r11,[rbx]                                              ; 025e
    mov r9,[rbp+0xf0]                                          ; 0261
    mov r13,0x801208384ff00                                    ; 0268
    mov r8,[rbp+0xe0]                                          ; 0272
    mov r10,[rbp+0xe8]                                         ; 0279
    mov rax,[rbp+0x100]                                        ; 0280
loc_0287:
    cmp r11,0x2                                                ; 0287
    jnl short loc_02aa                                          ; 028b
    mov rax,[rbp+0xd8]                                         ; 028d
    mov qword [rax],0x1                                        ; 0294
    cmp r15,0x1                                                ; 029b
    jg near loc_0c52                                            ; 029f
    jmp near loc_0c9d                                           ; 02a5
loc_02aa:
    cmp r11,0x64                                               ; 02aa
    jna near loc_0389                                           ; 02ae
    mov rax,[rbp+0xd8]                                         ; 02b4
    mov qword [rax],0x1                                        ; 02bb
    cmp r15,0x1                                                ; 02c2
    jng near loc_0c9d                                           ; 02c6
    mov qword [rbp+0x50],0x0                                   ; 02cc
    mov dword [rbp+0xb0],0x20438                               ; 02d4
    mov qword [rbp-0x10],0x2d                                  ; 02de
    lea rax,[rel $+7]                                          ; 02e6 | REL32 +3 strlit.11 addendLE=00000000
    mov [rbp-0x8],rax                                          ; 02ed
    sub rsp,0x30                                               ; 02f1
    lea rax,[rbp-0x10]                                         ; 02f5
    mov [rsp+0x20],rax                                         ; 02f9
    lea rsi,[rbp+0x50]                                         ; 02fe
    lea r9,[rbp+0xb0]                                          ; 0302
    mov rcx,rsi                                                ; 0309
    xor edx,edx                                                ; 030c
    mov r8,r13                                                 ; 030e
    call $+5                                                   ; 0311 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 0316
    mov dword [rbp+0xb4],0x2010b                               ; 031a
    mov qword [rbp+0x80],0x64                                  ; 0324
    sub rsp,0x20                                               ; 032f
    lea rdx,[rbp+0xb4]                                         ; 0333
    lea r8,[rbp+0x80]                                          ; 033a
    mov rcx,rsi                                                ; 0341
    call $+5                                                   ; 0344 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0349
    mov dword [rbp+0xb8],0x10438                               ; 034d
    mov qword [rbp+0x0],0x14                                   ; 0357
    lea rax,[rel $+7]                                          ; 035f | REL32 +3 strlit.10 addendLE=00000000
    mov [rbp+0x8],rax                                          ; 0366
    sub rsp,0x20                                               ; 036a
    lea rdx,[rbp+0xb8]                                         ; 036e
    mov r8,rbp                                                 ; 0375
    mov rcx,rsi                                                ; 0378
    call $+5                                                   ; 037b | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0380
    jmp near loc_0c9d                                           ; 0384
loc_0389:
    mov [rbp+0x100],rax                                        ; 0389
    mov [rbp+0x108],rbx                                        ; 0390
    mov rbx,[rbp+0x1c8]                                        ; 0397
    shl r14,byte 0x3                                           ; 039e
    mov eax,0x1                                                ; 03a2
    lea rcx,[rel $+7]                                          ; 03a7 | REL32 +3 SPALAZ$NONAZ addendLE=00000000
    o16 nop                                                    ; 03ae
loc_03b0:
    mov rdx,0xfffffffffff63c00                                 ; 03b0
    nop word [dword rax+rax+0x0]                               ; 03b7
loc_03c0:
    mov qword [rcx+rdx+0x9c400],0x0                            ; 03c0
    add rdx,0x1900                                             ; 03cc
    jnz short loc_03c0                                          ; 03d3
    inc rax                                                    ; 03d5
    add rcx,0x8                                                ; 03d8
    cmp rax,0x321                                              ; 03dc
    jnz short loc_03b0                                          ; 03e2
    mov qword [rel $+7],0x1                                    ; 03e4 | REL32 +3 SPALAZ$ICOMP addendLE=fcffffff
    xor eax,eax                                                ; 03ef
    lea rdx,[rel $+7]                                          ; 03f1 | REL32 +3 SPALAZ$VFRAC addendLE=00000000
    lea rcx,[rel $+7]                                          ; 03f8 | REL32 +3 SPALAZ$KER addendLE=00000000
    xorpd xmm6,xmm6                                            ; 03ff
    lea r13,[rbp+0x50]                                         ; 0403
    movsd xmm7,qword [rel $+8]                                 ; 0407 | REL32 +4 __real@3ff0147ae147ae14 addendLE=00000000
    movsd xmm8,qword [rel $+9]                                 ; 040f | REL32 +5 __real@3fefd70a3d70a3d7 addendLE=00000000
    mov r12,0x3e45798ee2308c3a                                 ; 0418
    mov rsi,r11                                                ; 0422
    mov [rbp+0x98],r11                                         ; 0425
    jmp short loc_0488                                          ; 042c
    o16 nop                                                    ; 042e
loc_0430:
    mov rax,[rel $+7]                                          ; 0430 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    mov rcx,[rbp+0x1c0]                                        ; 0437
    mov qword [rcx+rax*8-0x8],0x1                              ; 043e
    mov r9,[rbp+0xf0]                                          ; 0447
    mov r8,[rbp+0xe0]                                          ; 044e
    mov r10,[rbp+0xe8]                                         ; 0455
    lea rdx,[rel $+7]                                          ; 045c | REL32 +3 SPALAZ$VFRAC addendLE=00000000
loc_0463:
    lea rcx,[rax+0x1]                                          ; 0463
    mov [rel $+7],rcx                                          ; 0467 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    mov rcx,[rbp+0x108]                                        ; 046e
    mov rsi,[rcx]                                              ; 0475
    cmp rax,r11                                                ; 0478
    lea rcx,[rel $+7]                                          ; 047b | REL32 +3 SPALAZ$KER addendLE=00000000
    jnl near loc_08ee                                           ; 0482
loc_0488:
    mov qword [rel $+7],0x1                                    ; 0488 | REL32 +3 SPALAZ$JCOMP addendLE=fcffffff
    test rsi,rsi                                               ; 0493
    jng short loc_04d7                                          ; 0496
    xor ecx,ecx                                                ; 0498
    lea rdx,[rel $+7]                                          ; 049a | REL32 +3 SPALAZ$XINP addendLE=00000000
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 04a1 | nop word [cs:rax+rax+0x0]
loc_04b0:
    mov [rdx],r12                                              ; 04b0
    add rdx,0x8                                                ; 04b3
    inc rcx                                                    ; 04b7
    cmp rcx,rsi                                                ; 04ba
    jl short loc_04b0                                           ; 04bd
    inc rsi                                                    ; 04bf
    mov [rel $+7],rsi                                          ; 04c2 | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    lea rdx,[rel $+7]                                          ; 04c9 | REL32 +3 SPALAZ$VFRAC addendLE=00000000
    lea rcx,[rel $+7]                                          ; 04d0 | REL32 +3 SPALAZ$KER addendLE=00000000
loc_04d7:
    lea r11,[rel $+7]                                          ; 04d7 | REL32 +3 SPALAZ$XINP addendLE=00000000
    mov rsi,0x3feffffffaa19c47                                 ; 04de
    mov [r11+rax*8],rsi                                        ; 04e8
    mov byte [rel $+6],0x1                                     ; 04ec | REL32 +2 SPALAZ$SN addendLE=ffffffff
    mov byte [rel $+6],0x1                                     ; 04f3 | REL32 +2 SPALAZ$UN addendLE=ffffffff
    mov qword [rel $+7],0x0                                    ; 04fa | REL32 +3 SPALAZ$VFRAC addendLE=fcffffff
    sub rsp,0x90                                               ; 0505
    mov rax,[rbp+0x210]                                        ; 050c
    mov [rsp+0x80],rax                                         ; 0513
    mov [rsp+0x70],rcx                                         ; 051b
    mov [rsp+0x68],r8                                          ; 0520
    mov [rsp+0x60],r10                                         ; 0525
    lea rax,[rel $+7]                                          ; 052a | REL32 +3 SPALAZ$BETA addendLE=00000000
    mov [rsp+0x58],rax                                         ; 0531
    mov [rsp+0x50],rdi                                         ; 0536
    mov rax,[rbp+0x100]                                        ; 053b
    mov [rsp+0x48],rax                                         ; 0542
    mov [rsp+0x40],rdx                                         ; 0547
    mov rax,[rbp+0x1b0]                                        ; 054c
    mov [rsp+0x38],rax                                         ; 0553
    lea rax,[rel $+7]                                          ; 0558 | REL32 +3 SPALAZ$TBUB addendLE=00000000
    mov [rsp+0x30],rax                                         ; 055f
    mov [rsp+0x28],r11                                         ; 0564
    mov [rsp+0x20],r9                                          ; 0569
    mov qword [rsp+0x78],0x3                                   ; 056e
    lea rcx,[rel $+7]                                          ; 0577 | REL32 +3 SPALAZ$FLASHTYPE addendLE=00000000
    mov rdx,[rbp+0x200]                                        ; 057e
    mov r8,[rbp+0x208]                                         ; 0585
    mov rsi,[rbp+0x108]                                        ; 058c
    mov r9,rsi                                                 ; 0593
    call $+5                                                   ; 0596 | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    add rsp,0x90                                               ; 059b
    mov rsi,[rsi]                                              ; 05a2
    mov qword [rel $+7],0x1                                    ; 05a5 | REL32 +3 SPALAZ$JCOMP addendLE=fcffffff
    test rsi,rsi                                               ; 05b0
    jng near loc_0880                                           ; 05b3
    mov eax,0x1                                                ; 05b9
    jmp short loc_05d7                                          ; 05be
loc_05c0:
    lea rcx,[rax+0x1]                                          ; 05c0
    mov [rel $+7],rcx                                          ; 05c4 | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    cmp rax,rsi                                                ; 05cb
    mov rax,rcx                                                ; 05ce
    jnl near loc_0880                                           ; 05d1
loc_05d7:
    movsd xmm0,qword [rdi+rax*8-0x8]                           ; 05d7
    ucomisd xmm0,xmm6                                          ; 05dd
    jna short loc_0620                                          ; 05e1
    lea rdx,[rax-0x1]                                          ; 05e3
    mov rcx,[rbp+0x100]                                        ; 05e7
    movsd xmm1,qword [rcx+rax*8-0x8]                           ; 05ee
    divsd xmm1,xmm0                                            ; 05f4
    mov rcx,[rel $+7]                                          ; 05f8 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    imul rdx,r14                                               ; 05ff
    add rdx,rbx                                                ; 0603
    movsd qword [rdx+rcx*8-0x8],xmm1                           ; 0606
    cmp rcx,rax                                                ; 060c
    jnz short loc_0684                                          ; 060f
    jmp near loc_06b0                                           ; 0611
    db 0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00       ; 0616 | nop word [cs:rax+rax+0x0]
loc_0620:
    mov qword [rbp+0x50],0x0                                   ; 0620
    mov dword [rbp+0xbc],0x10438                               ; 0628
    mov qword [rbp+0x10],0x1b                                  ; 0632
    lea rax,[rel $+7]                                          ; 063a | REL32 +3 strlit.8 addendLE=00000000
    mov [rbp+0x18],rax                                         ; 0641
    sub rsp,0x30                                               ; 0645
    lea rax,[rbp+0x10]                                         ; 0649
    mov [rsp+0x20],rax                                         ; 064d
    mov rcx,r13                                                ; 0652
    xor edx,edx                                                ; 0655
    mov r8,0x801208384ff00                                     ; 0657
    lea r9,[rbp+0xbc]                                          ; 0661
    call $+5                                                   ; 0668 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 066d
    mov rcx,[rel $+7]                                          ; 0671 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    mov rax,[rel $+7]                                          ; 0678 | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    cmp rcx,rax                                                ; 067f
    jz short loc_06b0                                           ; 0682
loc_0684:
    lea rdx,[rax-0x1]                                          ; 0684
    imul rdx,r14                                               ; 0688
    add rdx,rbx                                                ; 068c
    movsd xmm0,qword [rdx+rcx*8-0x8]                           ; 068f
    ucomisd xmm0,xmm7                                          ; 0695
    jna short loc_06a2                                          ; 0699
    mov byte [rel $+6],0x0                                     ; 069b | REL32 +2 SPALAZ$UN addendLE=ffffffff
loc_06a2:
    ucomisd xmm8,xmm0                                          ; 06a2
    jna short loc_06b0                                          ; 06a7
    mov byte [rel $+6],0x0                                     ; 06a9 | REL32 +2 SPALAZ$SN addendLE=ffffffff
loc_06b0:
    cmp r15,0x5                                                ; 06b0
    jl near loc_05c0                                            ; 06b4
    mov qword [rbp+0x50],0x0                                   ; 06ba
    mov dword [rbp+0xc0],0x20438                               ; 06c2
    mov qword [rbp+0x20],0x7                                   ; 06cc
    lea rax,[rel $+7]                                          ; 06d4 | REL32 +3 strlit.4 addendLE=00000000
    mov [rbp+0x28],rax                                         ; 06db
    sub rsp,0x30                                               ; 06df
    lea rax,[rbp+0x20]                                         ; 06e3
    mov [rsp+0x20],rax                                         ; 06e7
    mov rcx,r13                                                ; 06ec
    xor edx,edx                                                ; 06ef
    mov r8,0x801208384ff00                                     ; 06f1
    lea r9,[rbp+0xc0]                                          ; 06fb
    call $+5                                                   ; 0702 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 0707
    mov rax,[rel $+7]                                          ; 070b | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    lea rcx,[rel $+7]                                          ; 0712 | REL32 +3 SPALAZ$COMIDS addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 0719
    add rax,0xfffffffffffffff8                                 ; 071d
    mov dword [rbp+0xc4],0x20638                               ; 0721
    mov qword [rbp-0x60],0x8                                   ; 072b
    mov [rbp-0x58],rax                                         ; 0733
    mov qword [rbp-0x50],0x8                                   ; 0737
    sub rsp,0x20                                               ; 073f
    mov rcx,r13                                                ; 0743
    lea rdx,[rbp+0xc4]                                         ; 0746
    lea r8,[rbp-0x60]                                          ; 074d
    call $+5                                                   ; 0751 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0756
    mov dword [rbp+0xc8],0x20438                               ; 075a
    mov qword [rbp+0x30],0x4                                   ; 0764
    lea rax,[rel $+7]                                          ; 076c | REL32 +3 strlit.3 addendLE=00000000
    mov [rbp+0x38],rax                                         ; 0773
    sub rsp,0x20                                               ; 0777
    mov rcx,r13                                                ; 077b
    lea rdx,[rbp+0xc8]                                         ; 077e
    lea r8,[rbp+0x30]                                          ; 0785
    call $+5                                                   ; 0789 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 078e
    mov rax,[rel $+7]                                          ; 0792 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    lea rcx,[rel $+7]                                          ; 0799 | REL32 +3 SPALAZ$COMIDS addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 07a0
    add rax,0xfffffffffffffff8                                 ; 07a4
    mov dword [rbp+0xcc],0x20638                               ; 07a8
    mov qword [rbp-0x48],0x8                                   ; 07b2
    mov [rbp-0x40],rax                                         ; 07ba
    mov qword [rbp-0x38],0x8                                   ; 07be
    sub rsp,0x20                                               ; 07c6
    mov rcx,r13                                                ; 07ca
    lea rdx,[rbp+0xcc]                                         ; 07cd
    lea r8,[rbp-0x48]                                          ; 07d4
    call $+5                                                   ; 07d8 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 07dd
    mov dword [rbp+0xd0],0x20438                               ; 07e1
    mov qword [rbp+0x40],0x4                                   ; 07eb
    lea rax,[rel $+7]                                          ; 07f3 | REL32 +3 strlit.2 addendLE=00000000
    mov [rbp+0x48],rax                                         ; 07fa
    sub rsp,0x20                                               ; 07fe
    mov rcx,r13                                                ; 0802
    lea rdx,[rbp+0xd0]                                         ; 0805
    lea r8,[rbp+0x40]                                          ; 080c
    call $+5                                                   ; 0810 | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0815
    mov rax,[rel $+7]                                          ; 0819 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    mov rcx,[rel $+7]                                          ; 0820 | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    dec rcx                                                    ; 0827
    imul rcx,r14                                               ; 082a
    add rcx,rbx                                                ; 082e
    movsd xmm0,qword [rcx+rax*8-0x8]                           ; 0831
    mov dword [rbp+0xd4],0x10130                               ; 0837
    movsd qword [rbp+0x88],xmm0                                ; 0841
    sub rsp,0x20                                               ; 0849
    mov rcx,r13                                                ; 084d
    lea rdx,[rbp+0xd4]                                         ; 0850
    lea r8,[rbp+0x88]                                          ; 0857
    call $+5                                                   ; 085e | REL32 +1 for_write_seq_lis_xmit addendLE=00000000
    add rsp,0x20                                               ; 0863
    mov rax,[rel $+7]                                          ; 0867 | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    jmp near loc_05c0                                           ; 086e
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0873 | nop word [cs:rax+rax+0x0]
loc_0880:
    cmp byte [rel $+6],0x0                                     ; 0880 | REL32 +2 SPALAZ$SN addendLE=ffffffff
    mov r11,[rbp+0x98]                                         ; 0887
    jnz near loc_0430                                           ; 088e
    mov rax,[rel $+7]                                          ; 0894 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    cmp byte [rel $+6],0x0                                     ; 089b | REL32 +2 SPALAZ$UN addendLE=ffffffff
    mov r9,[rbp+0xf0]                                          ; 08a2
    mov r8,[rbp+0xe0]                                          ; 08a9
    mov r10,[rbp+0xe8]                                         ; 08b0
    lea rdx,[rel $+7]                                          ; 08b7 | REL32 +3 SPALAZ$VFRAC addendLE=00000000
    mov rcx,[rbp+0x1c0]                                        ; 08be
    jz short loc_08e0                                           ; 08c5
    mov qword [rcx+rax*8-0x8],0x2                              ; 08c7
    jmp near loc_0463                                           ; 08d0
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 08d5 | nop word [cs:rax+rax+0x0]
loc_08e0:
    mov qword [rcx+rax*8-0x8],0x3                              ; 08e0
    jmp near loc_0463                                           ; 08e9
loc_08ee:
    mov qword [rel $+7],0x1                                    ; 08ee | REL32 +3 SPALAZ$ICOMP addendLE=fcffffff
    test rsi,rsi                                               ; 08f9
    jng near loc_0cc7                                           ; 08fc
    xor eax,eax                                                ; 0902
    lea r12,[rel $+7]                                          ; 0904 | REL32 +3 SPALAZ$ADX addendLE=00000000
    mov r13,[rbp+0x100]                                        ; 090b
    lea r15,[rel $+7]                                          ; 0912 | REL32 +3 SPALAZ$BETA addendLE=00000000
    nop dword [dword rax+0x0]                                  ; 0919
loc_0920:
    mov rcx,[r9+rax*8]                                         ; 0920
    mov [rel $+7],rcx                                          ; 0924 | REL32 +3 SPALAZ$ADX addendLE=00000000
    mov rcx,0x3ff0000000000000                                 ; 092b
    mov [rel $+7],rcx                                          ; 0935 | REL32 +3 SPALAZ$XINP addendLE=00000000
    mov qword [rel $+7],0x0                                    ; 093c | REL32 +3 SPALAZ$VFRAC addendLE=fcffffff
    mov rcx,[rbp+0x1b8]                                        ; 0947
    lea rax,[rcx+rax*8]                                        ; 094e
    sub rsp,0x90                                               ; 0952
    mov rcx,[rbp+0x210]                                        ; 0959
    mov [rsp+0x80],rcx                                         ; 0960
    lea rcx,[rel $+7]                                          ; 0968 | REL32 +3 SPALAZ$KER addendLE=00000000
    mov [rsp+0x70],rcx                                         ; 096f
    mov [rsp+0x68],r8                                          ; 0974
    mov [rsp+0x60],r10                                         ; 0979
    mov [rsp+0x58],r15                                         ; 097e
    mov [rsp+0x50],rdi                                         ; 0983
    mov [rsp+0x48],r13                                         ; 0988
    mov [rsp+0x40],rdx                                         ; 098d
    mov rcx,[rbp+0x1b0]                                        ; 0992
    mov [rsp+0x38],rcx                                         ; 0999
    mov [rsp+0x30],rax                                         ; 099e
    lea rax,[rel $+7]                                          ; 09a3 | REL32 +3 SPALAZ$XINP addendLE=00000000
    mov [rsp+0x28],rax                                         ; 09aa
    mov [rsp+0x20],r12                                         ; 09af
    mov qword [rsp+0x78],0x3                                   ; 09b4
    lea rcx,[rel $+7]                                          ; 09bd | REL32 +3 SPALAZ$FLASHTYPE addendLE=00000000
    lea rdx,[rel $+7]                                          ; 09c4 | REL32 +3 __unnamed_1 addendLE=00000000
    mov r8,[rbp+0x208]                                         ; 09cb
    lea r9,[rel $+7]                                           ; 09d2 | REL32 +3 __unnamed_2 addendLE=00000000
    call $+5                                                   ; 09d9 | REL32 +1 CALC_EQUILIBRIUM addendLE=00000000
    lea rdx,[rel $+7]                                          ; 09de | REL32 +3 SPALAZ$VFRAC addendLE=00000000
    mov r10,[rbp+0xe8]                                         ; 09e5
    mov r8,[rbp+0xe0]                                          ; 09ec
    mov r9,[rbp+0xf0]                                          ; 09f3
    add rsp,0x90                                               ; 09fa
    mov rax,[rel $+7]                                          ; 0a01 | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    lea rcx,[rax+0x1]                                          ; 0a08
    mov [rel $+7],rcx                                          ; 0a0c | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    cmp rax,rsi                                                ; 0a13
    jl near loc_0920                                            ; 0a16
    mov rax,[rbp+0x108]                                        ; 0a1c
    mov r8,[rax]                                               ; 0a23
    mov rax,[rbp+0x1d8]                                        ; 0a26
    mov qword [rax],0x0                                        ; 0a2d
    mov qword [rel $+7],0x0                                    ; 0a34 | REL32 +3 SPALAZ$NZEO addendLE=fcffffff
    mov qword [rel $+7],0x1                                    ; 0a3f | REL32 +3 SPALAZ$ICOMP addendLE=fcffffff
    cmp r8,0x2                                                 ; 0a4a
    jl near loc_0c9d                                            ; 0a4e
    dec r8                                                     ; 0a54
    mov eax,0x1                                                ; 0a57
    movsd xmm6,qword [rel $+8]                                 ; 0a5c | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    lea rdi,[rel $+7]                                          ; 0a64 | REL32 +3 SPALAZ$NGROUP addendLE=00000000
    lea r15,[rel $+7]                                          ; 0a6b | REL32 +3 SPALAZ$NONAZ addendLE=00000000
    lea r13,[rel $+7]                                          ; 0a72 | REL32 +3 SPALAZ$NZEO addendLE=00000000
    mov [rbp+0x100],r8                                         ; 0a79
    jmp short loc_0aae                                          ; 0a80
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0a82 | nop word [cs:rax+rax+0x0]
loc_0a90:
    lea rcx,[rax+0x1]                                          ; 0a90
    mov r8,[rbp+0x100]                                         ; 0a94
loc_0a9b:
    mov [rel $+7],rcx                                          ; 0a9b | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    cmp rax,r8                                                 ; 0aa2
    mov rax,rcx                                                ; 0aa5
    jnl near loc_0c9d                                           ; 0aa8
loc_0aae:
    lea rcx,[rax+0x1]                                          ; 0aae
    mov rdx,[rbp+0x108]                                        ; 0ab2
    mov rsi,[rdx]                                              ; 0ab9
    mov [rel $+7],rcx                                          ; 0abc | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    cmp rsi,rax                                                ; 0ac3
    jg near loc_0bf0                                            ; 0ac6
    jmp short loc_0a9b                                          ; 0acc
    o16 nop                                                    ; 0ace
loc_0ad0:
    mov qword [rel $+7],0x2                                    ; 0ad0 | REL32 +3 SPALAZ$NGROUP addendLE=fcffffff
    mov rax,[r9+rax*8-0x8]                                     ; 0adb
    mov [rel $+7],rax                                          ; 0ae0 | REL32 +3 SPALAZ$ADX addendLE=00000000
    mov rax,[r9+rcx*8-0x8]                                     ; 0ae7
    mov [rel $+15],rax                                         ; 0aec | REL32 +3 SPALAZ$ADX addendLE=08000000
    sub rsp,0xa0                                               ; 0af3
    mov rax,[rbp+0x210]                                        ; 0afa
    mov [rsp+0x98],rax                                         ; 0b01
    mov rax,[rbp+0x208]                                        ; 0b09
    mov [rsp+0x90],rax                                         ; 0b10
    mov rax,[rbp+0x200]                                        ; 0b18
    mov [rsp+0x88],rax                                         ; 0b1f
    mov rax,[rbp+0x1b8]                                        ; 0b27
    mov [rsp+0x80],rax                                         ; 0b2e
    mov [rsp+0x78],rbx                                         ; 0b36
    mov [rsp+0x70],r15                                         ; 0b3b
    mov [rsp+0x68],r13                                         ; 0b40
    mov rax,[rbp+0x1e8]                                        ; 0b45
    mov [rsp+0x60],rax                                         ; 0b4c
    mov rax,[rbp+0x1e0]                                        ; 0b51
    mov [rsp+0x58],rax                                         ; 0b58
    mov rax,[rbp+0x1f0]                                        ; 0b5d
    mov [rsp+0x50],rax                                         ; 0b64
    mov rax,[rbp+0x1f8]                                        ; 0b69
    mov [rsp+0x48],rax                                         ; 0b70
    mov rax,[rbp+0x1d8]                                        ; 0b75
    mov [rsp+0x40],rax                                         ; 0b7c
    mov rax,[rbp+0x1d0]                                        ; 0b81
    mov [rsp+0x38],rax                                         ; 0b88
    mov [rsp+0x30],rdi                                         ; 0b8d
    mov [rsp+0x28],r12                                         ; 0b92
    mov rax,[rbp+0x1b0]                                        ; 0b97
    mov [rsp+0x20],rax                                         ; 0b9e
    mov rcx,[rbp+0xd8]                                         ; 0ba3
    mov rdx,[rbp+0x90]                                         ; 0baa
    mov r8,[rbp+0x108]                                         ; 0bb1
    call $+5                                                   ; 0bb8 | REL32 +1 SPAZSE addendLE=00000000
    mov r9,[rbp+0xf0]                                          ; 0bbd
    add rsp,0xa0                                               ; 0bc4
    mov rax,[rel $+7]                                          ; 0bcb | REL32 +3 SPALAZ$ICOMP addendLE=00000000
    mov rcx,[rel $+7]                                          ; 0bd2 | REL32 +3 SPALAZ$JCOMP addendLE=00000000
loc_0bd9:
    lea rdx,[rcx+0x1]                                          ; 0bd9
    mov [rel $+7],rdx                                          ; 0bdd | REL32 +3 SPALAZ$JCOMP addendLE=00000000
    cmp rcx,rsi                                                ; 0be4
    mov rcx,rdx                                                ; 0be7
    jnl near loc_0a90                                           ; 0bea
loc_0bf0:
    lea rdx,[rcx-0x1]                                          ; 0bf0
    imul rdx,r14                                               ; 0bf4
    add rdx,rbx                                                ; 0bf8
    movsd xmm0,qword [rdx+rax*8-0x8]                           ; 0bfb
    ucomisd xmm0,xmm6                                          ; 0c01
    lea rdx,[rax-0x1]                                          ; 0c05
    seta r11b                                                  ; 0c09
    imul rdx,r14                                               ; 0c0d
    add rdx,rbx                                                ; 0c11
    movsd xmm1,qword [rdx+rcx*8-0x8]                           ; 0c14
    ucomisd xmm1,xmm6                                          ; 0c1a
    seta r10b                                                  ; 0c1e
    ucomisd xmm6,xmm0                                          ; 0c22
    seta dl                                                    ; 0c26
    ucomisd xmm6,xmm1                                          ; 0c29
    seta r8b                                                   ; 0c2d
    test r11b,r10b                                             ; 0c31
    jnz near loc_0ad0                                           ; 0c34
    and dl,r8b                                                 ; 0c3a
    jz short loc_0bd9                                           ; 0c3d
    jmp near loc_0ad0                                           ; 0c3f
loc_0c44:
    mov rax,[rbp+0xd8]                                         ; 0c44
    mov qword [rax],0x1                                        ; 0c4b
loc_0c52:
    mov qword [rbp+0x50],0x0                                   ; 0c52
    mov dword [rbp+0xac],0x10438                               ; 0c5a
    mov qword [rbp-0x20],0x47                                  ; 0c64
    lea rax,[rel $+7]                                          ; 0c6c | REL32 +3 strlit.14 addendLE=00000000
    mov [rbp-0x18],rax                                         ; 0c73
    sub rsp,0x30                                               ; 0c77
    lea rax,[rbp-0x20]                                         ; 0c7b
    mov [rsp+0x20],rax                                         ; 0c7f
    lea rcx,[rbp+0x50]                                         ; 0c84
    lea r9,[rbp+0xac]                                          ; 0c88
    xor edx,edx                                                ; 0c8f
    mov r8,r13                                                 ; 0c91
    call $+5                                                   ; 0c94 | REL32 +1 for_write_seq_lis addendLE=00000000
    add rsp,0x30                                               ; 0c99
loc_0c9d:
    movaps xmm6,oword [rbp+0x110]                              ; 0c9d
    movaps xmm7,oword [rbp+0x120]                              ; 0ca4
    movaps xmm8,oword [rbp+0x130]                              ; 0cab
    lea rsp,[rbp+0x148]                                        ; 0cb3
    pop rbx                                                    ; 0cba
    pop rdi                                                    ; 0cbb
    pop rsi                                                    ; 0cbc
    pop r12                                                    ; 0cbd
    pop r13                                                    ; 0cbf
    pop r14                                                    ; 0cc1
    pop r15                                                    ; 0cc3
    pop rbp                                                    ; 0cc5
    retq                                                       ; 0cc6
loc_0cc7:
    mov rax,[rbp+0x1d8]                                        ; 0cc7
    mov qword [rax],0x0                                        ; 0cce
    mov qword [rel $+7],0x0                                    ; 0cd5 | REL32 +3 SPALAZ$NZEO addendLE=fcffffff
    jmp short loc_0c9d                                          ; 0ce0

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x36,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00
    db 0x1d,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x0e,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x1d,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x20,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00
    db 0x22,0x00,0x00,0x05,0x01,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x31,0x00,0x20,0x20,0x43,0x4f
    db 0x4d,0x50,0x20,0x49,0x44,0x20,0x20,0x20,0x43,0x4f,0x4d,0x50,0x4f,0x4e,0x45,0x4e
    db 0x54,0x20,0x4e,0x41,0x4d,0x45,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20
    db 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x54,0x45,0x4d,0x50,0x00,0x00,0x00
    db 0x47,0x00,0x01,0x00,0x37,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x0e,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x1d,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x08,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00
    db 0x1d,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x1a,0x00,0x20,0x20,0x43,0x4f
    db 0x4d,0x50,0x20,0x49,0x44,0x20,0x20,0x20,0x43,0x4f,0x4d,0x50,0x4f,0x4e,0x45,0x4e
    db 0x54,0x20,0x4e,0x41,0x4d,0x45,0x00,0x00,0x47,0x00,0x01,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x2a,0x00,0x49,0x4e,0x46,0x49
    db 0x4e,0x49,0x54,0x45,0x20,0x44,0x49,0x4c,0x55,0x54,0x49,0x4f,0x4e,0x20,0x4b,0x2d
    db 0x56,0x41,0x4c,0x55,0x45,0x53,0x20,0x46,0x4f,0x52,0x20,0x54,0x48,0x45,0x20,0x4d
    db 0x49,0x58,0x54,0x55,0x52,0x45,0x00,0x00,0x37,0x00,0x00,0x00

; .rdata (COFF section 4)
coff_section_4:
    db 0x14,0xae,0x47,0xe1,0x7a,0x14,0xf0,0x3f

; .rdata (COFF section 5)
coff_section_5:
    db 0xd7,0xa3,0x70,0x3d,0x0a,0xd7,0xef,0x3f

; .rdata (COFF section 6)
coff_section_6:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .xdata (COFF section 7)
coff_section_7:
    db 0x01,0x34,0x11,0x85,0x34,0x68,0x19,0x00,0x2c,0x78,0x1a,0x00,0x24,0x88,0x1b,0x00
    db 0x1b,0x03,0x13,0x01,0x39,0x00,0x0c,0x30,0x0b,0x70,0x0a,0x60,0x09,0xc0,0x07,0xd0
    db 0x05,0xe0,0x03,0xf0,0x01,0x50,0x00,0x00

; .rdata (COFF section 8)
coff_section_8:
    db 0x20,0x69,0x73,0x20,0x20,0x69,0x6e,0x20,0x4b,0x56,0x4c,0x20,0x6f,0x66,0x20,0x00
    db 0x45,0x72,0x72,0x6f,0x72,0x20,0x69,0x6e,0x20,0x4b,0x2d,0x76,0x61,0x6c,0x75,0x65
    db 0x73,0x20,0x69,0x6e,0x20,0x53,0x50,0x41,0x4c,0x41,0x5a,0x00,0x00,0x00,0x00,0x00
    db 0x20,0x63,0x6f,0x6d,0x70,0x6f,0x6e,0x65,0x6e,0x74,0x73,0x20,0x61,0x6c,0x6c,0x6f
    db 0x77,0x65,0x64,0x21,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x53,0x65,0x61,0x72,0x63,0x68,0x20,0x66,0x6f,0x72,0x20,0x61,0x7a,0x65,0x6f,0x74
    db 0x72,0x6f,0x70,0x65,0x20,0x69,0x6d,0x70,0x6f,0x73,0x73,0x69,0x62,0x6c,0x65,0x20
    db 0x62,0x65,0x63,0x61,0x75,0x73,0x65,0x20,0x6f,0x6e,0x6c,0x79,0x20,0x00,0x00,0x00
    db 0x53,0x65,0x61,0x72,0x63,0x68,0x20,0x66,0x6f,0x72,0x20,0x61,0x7a,0x65,0x6f,0x74
    db 0x72,0x6f,0x70,0x65,0x20,0x69,0x6d,0x70,0x6f,0x73,0x73,0x69,0x62,0x6c,0x65,0x20
    db 0x62,0x65,0x63,0x61,0x75,0x73,0x65,0x20,0x6c,0x65,0x73,0x73,0x20,0x74,0x68,0x61
    db 0x6e,0x20,0x74,0x77,0x6f,0x20,0x63,0x6f,0x6d,0x70,0x6f,0x6e,0x65,0x6e,0x74,0x73
    db 0x20,0x67,0x69,0x76,0x65,0x6e,0x21,0x50,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00

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
    dd 0x00000ce2 ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 15)
