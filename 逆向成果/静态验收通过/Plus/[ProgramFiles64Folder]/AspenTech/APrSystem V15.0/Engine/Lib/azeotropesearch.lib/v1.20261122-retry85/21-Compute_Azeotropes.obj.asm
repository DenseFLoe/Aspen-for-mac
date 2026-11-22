; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

COMPUTE_AZEOTROPES:
    push rbp                                                   ; 0000
    push r15                                                   ; 0001
    push r14                                                   ; 0003
    push r13                                                   ; 0005
    push r12                                                   ; 0007
    push rsi                                                   ; 0009
    push rdi                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0xd8                                               ; 000c
    lea rbp,[rsp+0x80]                                         ; 0013
    mov [rbp+0x28],r9                                          ; 001b
    mov r15,r8                                                 ; 001f
    mov [rbp+0x50],rdx                                         ; 0022
    mov r13,rcx                                                ; 0026
    mov r12,[rcx]                                              ; 0029
    xor r11d,r11d                                              ; 002c
    test r12,r12                                               ; 002f
    mov edx,0x0                                                ; 0032
    cmovg rdx,r12                                              ; 0037
    lea rcx,[rdx*8+0xf]                                        ; 003b
    and rcx,0xfffffffffffffff0                                 ; 0043
    mov rax,[rbp+0xc8]                                         ; 0047
    mov r8,0x801208384ff00                                     ; 004e
    mov rbx,[rax]                                              ; 0058
    lea r9,[rdx*8+0x0]                                         ; 005b
    mov rax,rcx                                                ; 0063
    call $+5                                                   ; 0066 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 006b
    mov [rbp+0x38],rsp                                         ; 006e
    mov rax,rcx                                                ; 0072
    call $+5                                                   ; 0075 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 007a
    mov r14,rsp                                                ; 007d
    cmp r12,0x2                                                ; 0080
    mov esi,0x1                                                ; 0084
    mov r10d,0x1                                               ; 0089
    cmovnl r10,r12                                             ; 008f
    lea rax,[r10-0x1]                                          ; 0093
    imul rax,rax                                               ; 0097
    lea rax,[rax*8+0xf]                                        ; 009b
    and rax,0xfffffffffffffff0                                 ; 00a3
    call $+5                                                   ; 00a7 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00ac
    mov [rbp+0x18],rsp                                         ; 00af
    lea rax,[rbx+r12]                                          ; 00b3
    mov [rbp-0x10],rax                                         ; 00b7
    lea rax,[r10*8+0x7]                                        ; 00bb
    and rax,0xfffffffffffffff0                                 ; 00c3
    call $+5                                                   ; 00c7 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00cc
    mov [rbp+0x20],rsp                                         ; 00cf
    test rbx,rbx                                               ; 00d3
    cmovg r11,rbx                                              ; 00d6
    mov rax,r9                                                 ; 00da
    imul rax,r11                                               ; 00dd
    add rax,0xf                                                ; 00e1
    and rax,0xfffffffffffffff0                                 ; 00e5
    call $+5                                                   ; 00e9 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 00ee
    mov [rbp+0x40],rsp                                         ; 00f1
    imul rdx,r9                                                ; 00f5
    add rdx,0xf                                                ; 00f9
    and rdx,0xfffffffffffffff0                                 ; 00fd
    mov rax,rdx                                                ; 0101
    call $+5                                                   ; 0104 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0109
    mov [rbp-0x8],rsp                                          ; 010c
    lea rax,[r11*8+0xf]                                        ; 0110
    and rax,0xfffffffffffffff0                                 ; 0118
    call $+5                                                   ; 011c | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 0121
    mov rdi,rsp                                                ; 0124
    mov rax,rcx                                                ; 0127
    call $+5                                                   ; 012a | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 012f
    mov [rbp+0x10],rsp                                         ; 0132
    mov rax,rcx                                                ; 0136
    call $+5                                                   ; 0139 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 013e
    mov [rbp-0x20],rsp                                         ; 0141
    mov rax,rcx                                                ; 0145
    call $+5                                                   ; 0148 | REL32 +1 __chkstk addendLE=00000000
    sub rsp,rax                                                ; 014d
    mov [rbp+0x30],rsp                                         ; 0150
    lea rax,[r12*8+0x0]                                        ; 0154
    mov [rbp+0x48],rax                                         ; 015c
    mov rax,[rbp+0x110]                                        ; 0160
    mov qword [rax],0x0                                        ; 0167
    mov qword [rel $+7],0x2                                    ; 016e | REL32 +3 COMPUTE_AZEOTROPES$SPERR addendLE=fcffffff
    mov qword [rel $+7],0x0                                    ; 0179 | REL32 +3 COMPUTE_AZEOTROPES$LDEBUG addendLE=fcffffff
    mov [rel $+7],rbx                                          ; 0184 | REL32 +3 COMPUTE_AZEOTROPES$MAXAZ addendLE=00000000
    shl rbx,byte 0x3                                           ; 018b
    mov qword [rbp-0x78],0x0                                   ; 018f
    mov rax,0x1a0109000d0438                                   ; 0197
    mov [rbp-0x2c],rax                                         ; 01a1
    mov dword [rbp-0x24],0x1                                   ; 01a5
    mov qword [rbp-0x48],0x3                                   ; 01ac
    lea rax,[rel $+7]                                          ; 01b4 | REL32 +3 strlit.1 addendLE=00000000
    mov [rbp-0x40],rax                                         ; 01bb
    mov qword [rbp-0x38],0x4                                   ; 01bf
    sub rsp,0x30                                               ; 01c7
    lea rax,[rbp-0x48]                                         ; 01cb
    mov [rsp+0x20],rax                                         ; 01cf
    lea rcx,[rbp-0x78]                                         ; 01d4
    lea r9,[rbp-0x2c]                                          ; 01d8
    xor edx,edx                                                ; 01dc
    call $+5                                                   ; 01de | REL32 +1 for_open addendLE=00000000
    add rsp,0x30                                               ; 01e3
    mov [rbp+0x0],r12                                          ; 01e7
    cmp r12,0x3                                                ; 01eb
    jnz near loc_08c8                                           ; 01ef
    mov [rbp-0x18],rdi                                         ; 01f5
    mov rdi,r15                                                ; 01f9
    xor eax,eax                                                ; 01fc
    lea rcx,[rel $+7]                                          ; 01fe | REL32 +3 .T8_ addendLE=00000000
    lea r15,[rel $+7]                                          ; 0205 | REL32 +3 COMPUTE_AZEOTROPES$PERM addendLE=00000000
    mov r12,[rbp+0xc8]                                         ; 020c
    mov r10,[rbp+0x40]                                         ; 0213
    mov r11,[rbp+0xe0]                                         ; 0217
    o16 nop                                                    ; 021e
loc_0220:
    xor edx,edx                                                ; 0220
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0222 | nop word [cs:rax+rax+0x0]
loc_0230:
    lea r8,[rax+rdx]                                           ; 0230
    mov r9,[rcx+r8]                                            ; 0234
    mov [r15+r8],r9                                            ; 0238
    add rdx,0x8                                                ; 023c
    cmp rdx,0x30                                               ; 0240
    jnz short loc_0230                                          ; 0244
    inc rsi                                                    ; 0246
    add rax,0x30                                               ; 0249
    cmp rsi,0x4                                                ; 024d
    jnz short loc_0220                                          ; 0251
    mov esi,0x3                                                ; 0253
    xor ecx,ecx                                                ; 0258
    mov r8,[rbp+0xc0]                                          ; 025a
    mov r15,[rbp+0xe8]                                         ; 0261
    nop dword [dword rax+rax+0x0]                              ; 0268
loc_0270:
    lea rax,[rcx+0x1]                                          ; 0270
    mov [rel $+7],rax                                          ; 0274 | REL32 +3 COMPUTE_AZEOTROPES$ITER addendLE=00000000
    test rsi,rsi                                               ; 027b
    mov r9,[rbp-0x20]                                          ; 027e
    jng short loc_02b8                                          ; 0282
    lea rax,[rel $+7]                                          ; 0284 | REL32 +3 COMPUTE_AZEOTROPES$PERM addendLE=00000000
    lea rax,[rax+rcx*8]                                        ; 028b
    xor ecx,ecx                                                ; 028f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0291 | nop word [cs:rax+rax+0x0]
loc_02a0:
    mov rdx,[rax]                                              ; 02a0
    mov rdx,[r8+rdx*8-0x8]                                     ; 02a3
    mov [r9+rcx*8],rdx                                         ; 02a8
    inc rcx                                                    ; 02ac
    add rax,0x30                                               ; 02af
    cmp rsi,rcx                                                ; 02b3
    jnz short loc_02a0                                          ; 02b6
loc_02b8:
    sub rsp,0x90                                               ; 02b8
    mov rax,[rbp+0x118]                                        ; 02bf
    mov [rsp+0x80],rax                                         ; 02c6
    mov rax,[rbp+0x28]                                         ; 02ce
    mov [rsp+0x78],rax                                         ; 02d2
    mov [rsp+0x70],rdi                                         ; 02d7
    mov [rsp+0x68],r10                                         ; 02dc
    mov rax,[rbp+0xd8]                                         ; 02e1
    mov [rsp+0x60],rax                                         ; 02e8
    mov [rsp+0x58],r11                                         ; 02ed
    mov [rsp+0x50],r15                                         ; 02f2
    mov [rsp+0x48],r12                                         ; 02f7
    lea rax,[rel $+7]                                          ; 02fc | REL32 +3 COMPUTE_AZEOTROPES$MAXAZ addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0303
    mov rax,[rbp-0x8]                                          ; 0308
    mov [rsp+0x38],rax                                         ; 030c
    mov rax,[rbp-0x18]                                         ; 0311
    mov [rsp+0x30],rax                                         ; 0315
    mov rax,[rbp+0x38]                                         ; 031a
    mov [rsp+0x28],rax                                         ; 031e
    mov rax,[rbp+0x50]                                         ; 0323
    mov [rsp+0x20],rax                                         ; 0327
    lea rcx,[rel $+7]                                          ; 032c | REL32 +3 COMPUTE_AZEOTROPES$SPERR addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0333 | REL32 +3 COMPUTE_AZEOTROPES$LDEBUG addendLE=00000000
    mov r8,r13                                                 ; 033a
    call $+5                                                   ; 033d | REL32 +1 SPALAZ addendLE=00000000
    add rsp,0x90                                               ; 0342
    cmp qword [rel $+7],0x1                                    ; 0349 | REL32 +3 COMPUTE_AZEOTROPES$SPERR addendLE=ffffffff
    jg short loc_039d                                           ; 0351
    mov qword [rel $+7],0x1fd                                  ; 0353 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    mov rax,[rbp+0x110]                                        ; 035e
    mov qword [rax],0x1                                        ; 0365
    sub rsp,0x30                                               ; 036c
    mov qword [rsp+0x20],0xf                                   ; 0370
    mov r9d,0xf                                                ; 0379
    lea rcx,[rel $+7]                                          ; 037f | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0386 | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 038d | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 0394 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 0399
loc_039d:
    mov rsi,[r12]                                              ; 039d
    mov r12,[r13+0x0]                                          ; 03a1
    test rsi,rsi                                               ; 03a5
    jng short loc_0420                                          ; 03a8
    mov rax,[rel $+7]                                          ; 03aa | REL32 +3 COMPUTE_AZEOTROPES$ITER addendLE=00000000
    lea rcx,[rel $+7]                                          ; 03b1 | REL32 +3 COMPUTE_AZEOTROPES$PERM addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 03b8
    add rax,0xfffffffffffffff8                                 ; 03bc
    mov edx,0x1                                                ; 03c0
    mov rcx,[rbp+0x40]                                         ; 03c5
    jmp short loc_03e0                                          ; 03c9
    nop dword [byte rax+rax+0x0]                               ; 03cb
loc_03d0:
    lea r8,[rdx+0x1]                                           ; 03d0
    add rcx,0x8                                                ; 03d4
    cmp rdx,rsi                                                ; 03d8
    mov rdx,r8                                                 ; 03db
    jnl short loc_0420                                          ; 03de
loc_03e0:
    test r12,r12                                               ; 03e0
    jng short loc_03d0                                          ; 03e3
    lea r8,[rdx-0x1]                                           ; 03e5
    imul r8,[rbp+0x48]                                         ; 03e9
    add r8,[rbp+0xd0]                                          ; 03ee
    mov r9,rax                                                 ; 03f5
    mov r10,rcx                                                ; 03f8
    mov r11,r12                                                ; 03fb
    o16 nop                                                    ; 03fe
loc_0400:
    movsd xmm0,qword [r10]                                     ; 0400
    mov r15,[r9]                                               ; 0405
    movsd qword [r8+r15*8-0x8],xmm0                            ; 0408
    add r10,rbx                                                ; 040f
    add r9,0x30                                                ; 0412
    dec r11                                                    ; 0416
    jnz short loc_0400                                          ; 0419
    jmp short loc_03d0                                          ; 041b
    nop dword [rax]                                            ; 041d
loc_0420:
    test r12,r12                                               ; 0420
    mov r8,[rbp+0x10]                                          ; 0423
    mov r9,[rbp+0x38]                                          ; 0427
    lea rcx,[rel $+7]                                          ; 042b | REL32 +3 COMPUTE_AZEOTROPES$PERM addendLE=00000000
    jng short loc_046c                                          ; 0432
    mov rax,[rel $+7]                                          ; 0434 | REL32 +3 COMPUTE_AZEOTROPES$ITER addendLE=00000000
    lea rax,[rcx+rax*8]                                        ; 043b
    add rax,0xfffffffffffffff8                                 ; 043f
    xor ecx,ecx                                                ; 0443
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0445 | nop word [cs:rax+rax+0x0]
loc_0450:
    movsd xmm0,qword [r9+rcx*8]                                ; 0450
    mov rdx,[rax]                                              ; 0456
    movsd qword [r8+rdx*8-0x8],xmm0                            ; 0459
    inc rcx                                                    ; 0460
    add rax,0x30                                               ; 0463
    cmp rcx,r12                                                ; 0467
    jl short loc_0450                                           ; 046a
loc_046c:
    mov qword [rel $+7],0x1                                    ; 046c | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=fcffffff
    mov qword [rel $+7],0x1                                    ; 0477 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=fcffffff
    test rsi,rsi                                               ; 0482
    mov r8,[rbp+0xc0]                                          ; 0485
    jng near loc_0620                                           ; 048c
    mov r15d,0x1                                               ; 0492
    mov rdx,[rbp+0x118]                                        ; 0498
    jmp short loc_04dd                                          ; 049f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 04a1 | nop word [cs:rax+rax+0x0]
loc_04b0:
    mov r12,[r13+0x0]                                          ; 04b0
    mov rax,[rel $+7]                                          ; 04b4 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    lea r15,[rax+0x1]                                          ; 04bb
    mov [rel $+7],r15                                          ; 04bf | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    cmp rax,rsi                                                ; 04c6
    mov rdx,[rbp+0x118]                                        ; 04c9
    mov r8,[rbp+0xc0]                                          ; 04d0
    jnl near loc_0620                                           ; 04d7
loc_04dd:
    test r12,r12                                               ; 04dd
    jng short loc_0553                                          ; 04e0
    lea rax,[r15+r15*2]                                        ; 04e2
    mov rcx,[rbp+0xd0]                                         ; 04e6
    cmp r12,0xc                                                ; 04ed
    jna short loc_0530                                          ; 04f1
    lea rdx,[rcx+rax*8]                                        ; 04f3
    add rdx,0xffffffffffffffe8                                 ; 04f7
    shl r12,byte 0x3                                           ; 04fb
    sub rsp,0x20                                               ; 04ff
    mov rcx,r14                                                ; 0503
    mov r8,r12                                                 ; 0506
    call $+5                                                   ; 0509 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r8,[rbp+0xc0]                                          ; 050e
    mov rdx,[rbp+0x118]                                        ; 0515
    add rsp,0x20                                               ; 051c
    jmp short loc_0553                                          ; 0520
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0522 | nop word [cs:rax+rax+0x0]
loc_0530:
    lea rax,[rcx+rax*8]                                        ; 0530
    add rax,0xffffffffffffffe8                                 ; 0534
    xor ecx,ecx                                                ; 0538
    nop word [byte rax+rax+0x0]                                ; 053a
loc_0540:
    movsd xmm0,qword [rax+rcx*8]                               ; 0540
    movsd qword [r14+rcx*8],xmm0                               ; 0545
    inc rcx                                                    ; 054b
    cmp r12,rcx                                                ; 054e
    jnz short loc_0540                                          ; 0551
loc_0553:
    mov rax,[rbp+0xf0]                                         ; 0553
    lea rax,[rax+r15*8]                                        ; 055a
    add rax,0xfffffffffffffff8                                 ; 055e
    sub rsp,0x60                                               ; 0562
    mov [rsp+0x58],rdx                                         ; 0566
    lea rcx,[rel $+7]                                          ; 056b | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=00000000
    mov [rsp+0x50],rcx                                         ; 0572
    mov rcx,[rbp+0x18]                                         ; 0577
    mov [rsp+0x48],rcx                                         ; 057b
    mov rcx,[rbp+0x20]                                         ; 0580
    mov [rsp+0x40],rcx                                         ; 0584
    mov [rsp+0x38],rax                                         ; 0589
    mov [rsp+0x30],rdi                                         ; 058e
    mov rax,[rbp+0x28]                                         ; 0593
    mov [rsp+0x28],rax                                         ; 0597
    mov [rsp+0x20],r8                                          ; 059c
    mov rcx,r13                                                ; 05a1
    mov rdx,r14                                                ; 05a4
    lea r8,[rel $+7]                                           ; 05a7 | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=00000000
    mov r9,[rbp+0x50]                                          ; 05ae
    call $+5                                                   ; 05b2 | REL32 +1 STABILITY_RCM addendLE=00000000
    add rsp,0x60                                               ; 05b7
    cmp qword [rel $+7],0x0                                    ; 05bb | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=ffffffff
    jz near loc_04b0                                            ; 05c3
    mov qword [rel $+7],0x1fe                                  ; 05c9 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    mov rax,[rbp+0x110]                                        ; 05d4
    mov qword [rax],0x2                                        ; 05db
    sub rsp,0x30                                               ; 05e2
    mov qword [rsp+0x20],0xf                                   ; 05e6
    mov r9d,0xf                                                ; 05ef
    lea rcx,[rel $+7]                                          ; 05f5 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 05fc | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 0603 | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 060a | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 060f
    jmp near loc_04b0                                           ; 0613
    nop dword [dword rax+rax+0x0]                              ; 0618
loc_0620:
    mov qword [rel $+7],0x1                                    ; 0620 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=fcffffff
    test r12,r12                                               ; 062b
    jng near loc_0770                                           ; 062e
    xor r15d,r15d                                              ; 0634
    jmp short loc_0654                                          ; 0637
    nop dword [dword rax+0x0]                                  ; 0639
loc_0640:
    lea rax,[r15+0x1]                                          ; 0640
    mov [rel $+7],rax                                          ; 0644 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    cmp r15,r12                                                ; 064b
    jnl near loc_0773                                           ; 064e
loc_0654:
    sub rsp,0x20                                               ; 0654
    mov rcx,r14                                                ; 0658
    xor edx,edx                                                ; 065b
    mov r8,[rbp+0x48]                                          ; 065d
    call $+5                                                   ; 0661 | REL32 +1 _intel_fast_memset addendLE=00000000
    add rsp,0x20                                               ; 0666
    mov rax,0x3ff0000000000000                                 ; 066a
    mov [r14+r15*8],rax                                        ; 0674
    mov rax,[rbp+0x30]                                         ; 0678
    lea rax,[rax+r15*8]                                        ; 067c
    sub rsp,0x60                                               ; 0680
    mov rcx,[rbp+0x118]                                        ; 0684
    mov [rsp+0x58],rcx                                         ; 068b
    lea rcx,[rel $+7]                                          ; 0690 | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=00000000
    mov [rsp+0x50],rcx                                         ; 0697
    mov rcx,[rbp+0x18]                                         ; 069c
    mov [rsp+0x48],rcx                                         ; 06a0
    mov rcx,[rbp+0x20]                                         ; 06a5
    mov [rsp+0x40],rcx                                         ; 06a9
    mov [rsp+0x38],rax                                         ; 06ae
    mov [rsp+0x30],rdi                                         ; 06b3
    mov rax,[rbp+0x28]                                         ; 06b8
    mov [rsp+0x28],rax                                         ; 06bc
    mov rax,[rbp+0xc0]                                         ; 06c1
    mov [rsp+0x20],rax                                         ; 06c8
    mov rcx,r13                                                ; 06cd
    mov rdx,r14                                                ; 06d0
    lea r8,[rel $+7]                                           ; 06d3 | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=00000000
    mov r9,[rbp+0x50]                                          ; 06da
    call $+5                                                   ; 06de | REL32 +1 STABILITY_RCM addendLE=00000000
    add rsp,0x60                                               ; 06e3
    cmp qword [rel $+7],0x0                                    ; 06e7 | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=ffffffff
    jz short loc_073b                                           ; 06ef
    mov qword [rel $+7],0x1fe                                  ; 06f1 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    mov rax,[rbp+0x110]                                        ; 06fc
    mov qword [rax],0x2                                        ; 0703
    sub rsp,0x30                                               ; 070a
    mov qword [rsp+0x20],0xf                                   ; 070e
    mov r9d,0xf                                                ; 0717
    lea rcx,[rel $+7]                                          ; 071d | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0724 | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 072b | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 0732 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 0737
loc_073b:
    mov rsi,[r13+0x0]                                          ; 073b
    mov r15,[rel $+7]                                          ; 073f | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    lea rax,[rsi-0xe]                                          ; 0746
    cmp rax,0xfffffffffffffff3                                 ; 074a
    jna near loc_0640                                           ; 074e
    lea rax,[rsi-0x1]                                          ; 0754
    nop dword [dword rax+rax+0x0]                              ; 0758
loc_0760:
    dec rax                                                    ; 0760
    jnz short loc_0760                                          ; 0763
    jmp near loc_0640                                           ; 0765
    nop word [byte rax+rax+0x0]                                ; 076a
loc_0770:
    mov rsi,r12                                                ; 0770
loc_0773:
    mov r12,[rbp+0xc8]                                         ; 0773
    mov rcx,[r12]                                              ; 077a
    test rcx,rcx                                               ; 077e
    jng short loc_07f0                                          ; 0781
    xor edx,edx                                                ; 0783
    xor eax,eax                                                ; 0785
    mov r9,[rbp+0xf0]                                          ; 0787
    mov r10,[rbp+0x30]                                         ; 078e
    mov r11,[rbp+0xe0]                                         ; 0792
    jmp short loc_07bb                                          ; 0799
    nop dword [byte rax+rax+0x0]                               ; 079b
loc_07a0:
    xor r8d,r8d                                                ; 07a0
    cmp qword [r9+rdx*8],0x2                                   ; 07a3
    setnz r8b                                                  ; 07a8
    lea rax,[rax+r8*2]                                         ; 07ac
    dec rax                                                    ; 07b0
loc_07b3:
    inc rdx                                                    ; 07b3
    cmp rdx,rcx                                                ; 07b6
    jnl short loc_07fd                                          ; 07b9
loc_07bb:
    mov r8,[r11+rdx*8]                                         ; 07bb
    cmp r8,0x2                                                 ; 07bf
    jz short loc_07a0                                           ; 07c3
    cmp r8,0x3                                                 ; 07c5
    jnz short loc_07b3                                          ; 07c9
    xor r8d,r8d                                                ; 07cb
    cmp qword [r9+rdx*8],0x2                                   ; 07ce
    setnz r8b                                                  ; 07d3
    lea rax,[rax+r8*4]                                         ; 07d7
    add rax,0xfffffffffffffffe                                 ; 07db
    jmp short loc_07b3                                          ; 07df
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 07e1 | nop word [cs:rax+rax+0x0]
loc_07f0:
    xor eax,eax                                                ; 07f0
    mov r10,[rbp+0x30]                                         ; 07f2
    mov r11,[rbp+0xe0]                                         ; 07f6
loc_07fd:
    mov qword [rel $+7],0x1                                    ; 07fd | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=fcffffff
    test rsi,rsi                                               ; 0808
    jng short loc_0850                                          ; 080b
    xor ecx,ecx                                                ; 080d
    mov r8,[rbp+0xc0]                                          ; 080f
    mov r15,[rbp+0xe8]                                         ; 0816
    nop dword [rax]                                            ; 081d
loc_0820:
    xor edx,edx                                                ; 0820
    cmp qword [r10+rcx*8],0x2                                  ; 0822
    setnz dl                                                   ; 0827
    add rax,rdx                                                ; 082a
    inc rcx                                                    ; 082d
    cmp rcx,rsi                                                ; 0830
    jl short loc_0820                                           ; 0833
    lea rcx,[rsi+0x1]                                          ; 0835
    mov [rel $+7],rcx                                          ; 0839 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    jmp short loc_085e                                          ; 0840
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0842 | nop word [cs:rax+rax+0x0]
loc_0850:
    mov r8,[rbp+0xc0]                                          ; 0850
    mov r15,[rbp+0xe8]                                         ; 0857
loc_085e:
    mov rcx,[rel $+7]                                          ; 085e | REL32 +3 COMPUTE_AZEOTROPES$ITER addendLE=00000000
    cmp rcx,0x5                                                ; 0865
    mov r10,[rbp+0x40]                                         ; 0869
    jg short loc_0879                                           ; 086d
    cmp rax,0x2                                                ; 086f
    jnz near loc_0270                                           ; 0873
loc_0879:
    cmp rax,0x2                                                ; 0879
    jz near loc_0d0e                                            ; 087d
    mov qword [rel $+7],0x1ff                                  ; 0883 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    lea rcx,[rel $+7]                                          ; 088e | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    sub rsp,0x30                                               ; 0895
    mov qword [rsp+0x20],0xf                                   ; 0899
    lea rdx,[rel $+7]                                          ; 08a2 | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 08a9 | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    mov r9d,0xf                                                ; 08b0
    call $+5                                                   ; 08b6 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 08bb
    mov rsi,[r13+0x0]                                          ; 08bf
    jmp near loc_0d0e                                           ; 08c3
loc_08c8:
    sub rsp,0x90                                               ; 08c8
    mov rax,[rbp+0xe0]                                         ; 08cf
    mov [rsp+0x58],rax                                         ; 08d6
    mov rax,[rbp+0x118]                                        ; 08db
    mov [rsp+0x80],rax                                         ; 08e2
    mov r12,[rbp+0x28]                                         ; 08ea
    mov [rsp+0x78],r12                                         ; 08ee
    mov [rbp+0x38],r15                                         ; 08f3
    mov [rsp+0x70],r15                                         ; 08f7
    mov rax,[rbp+0x40]                                         ; 08fc
    mov [rsp+0x68],rax                                         ; 0900
    mov rax,[rbp+0xd8]                                         ; 0905
    mov [rsp+0x60],rax                                         ; 090c
    mov rax,[rbp+0xe8]                                         ; 0911
    mov [rsp+0x50],rax                                         ; 0918
    mov rsi,[rbp+0xc8]                                         ; 091d
    mov [rsp+0x48],rsi                                         ; 0924
    lea rax,[rel $+7]                                          ; 0929 | REL32 +3 COMPUTE_AZEOTROPES$MAXAZ addendLE=00000000
    mov [rsp+0x40],rax                                         ; 0930
    mov rax,[rbp-0x8]                                          ; 0935
    mov [rsp+0x38],rax                                         ; 0939
    mov [rsp+0x30],rdi                                         ; 093e
    mov rax,[rbp+0x10]                                         ; 0943
    mov [rsp+0x28],rax                                         ; 0947
    mov rax,[rbp+0x50]                                         ; 094c
    mov [rsp+0x20],rax                                         ; 0950
    lea rcx,[rel $+7]                                          ; 0955 | REL32 +3 COMPUTE_AZEOTROPES$SPERR addendLE=00000000
    lea rdx,[rel $+7]                                          ; 095c | REL32 +3 COMPUTE_AZEOTROPES$LDEBUG addendLE=00000000
    mov r8,r13                                                 ; 0963
    mov r9,[rbp+0xc0]                                          ; 0966
    call $+5                                                   ; 096d | REL32 +1 SPALAZ addendLE=00000000
    add rsp,0x90                                               ; 0972
    cmp qword [rel $+7],0x2                                    ; 0979 | REL32 +3 COMPUTE_AZEOTROPES$SPERR addendLE=ffffffff
    mov rdi,r12                                                ; 0981
    jnl short loc_09d0                                          ; 0984
    mov qword [rel $+7],0x1fd                                  ; 0986 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    lea rcx,[rel $+7]                                          ; 0991 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    mov rax,[rbp+0x110]                                        ; 0998
    mov qword [rax],0x1                                        ; 099f
    sub rsp,0x30                                               ; 09a6
    mov qword [rsp+0x20],0xf                                   ; 09aa
    lea rdx,[rel $+7]                                          ; 09b3 | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 09ba | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    mov r9d,0xf                                                ; 09c1
    call $+5                                                   ; 09c7 | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 09cc
loc_09d0:
    mov rsi,[rsi]                                              ; 09d0
    test rsi,rsi                                               ; 09d3
    mov r9,[rbp+0xc0]                                          ; 09d6
    jng near loc_0bc8                                           ; 09dd
    mov r12,[r13+0x0]                                          ; 09e3
    mov ecx,0x1                                                ; 09e7
    mov rax,[rbp+0xd0]                                         ; 09ec
    mov r10,[rbp+0x40]                                         ; 09f3
    jmp short loc_0a14                                          ; 09f7
    nop dword [dword rax+0x0]                                  ; 09f9
loc_0a00:
    lea rdx,[rcx+0x1]                                          ; 0a00
    add r10,0x8                                                ; 0a04
    add rax,[rbp+0x48]                                         ; 0a08
    cmp rcx,rsi                                                ; 0a0c
    mov rcx,rdx                                                ; 0a0f
    jnl short loc_0a37                                          ; 0a12
loc_0a14:
    test r12,r12                                               ; 0a14
    jng short loc_0a00                                          ; 0a17
    mov rdx,r10                                                ; 0a19
    xor r8d,r8d                                                ; 0a1c
    nop                                                        ; 0a1f
loc_0a20:
    movsd xmm0,qword [rdx]                                     ; 0a20
    movsd qword [rax+r8*8],xmm0                                ; 0a24
    inc r8                                                     ; 0a2a
    add rdx,rbx                                                ; 0a2d
    cmp r12,r8                                                 ; 0a30
    jnz short loc_0a20                                          ; 0a33
    jmp short loc_0a00                                          ; 0a35
loc_0a37:
    mov qword [rel $+7],0x1                                    ; 0a37 | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=fcffffff
    mov qword [rel $+7],0x1                                    ; 0a42 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=fcffffff
    mov ebx,0x1                                                ; 0a4d
    mov rdx,[rbp+0x118]                                        ; 0a52
    mov r15,[rbp+0xd0]                                         ; 0a59
    jmp short loc_0a9d                                          ; 0a60
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0a62 | nop word [cs:rax+rax+0x0]
loc_0a70:
    mov r12,[r13+0x0]                                          ; 0a70
    mov rax,[rel $+7]                                          ; 0a74 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    lea rbx,[rax+0x1]                                          ; 0a7b
    mov [rel $+7],rbx                                          ; 0a7f | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    cmp rax,rsi                                                ; 0a86
    mov rdx,[rbp+0x118]                                        ; 0a89
    mov r9,[rbp+0xc0]                                          ; 0a90
    jnl near loc_0bd7                                           ; 0a97
loc_0a9d:
    test r12,r12                                               ; 0a9d
    jng short loc_0b03                                          ; 0aa0
    cmp r12,0xc                                                ; 0aa2
    jna short loc_0ae0                                          ; 0aa6
    lea rdx,[rbx-0x1]                                          ; 0aa8
    imul rdx,[rbp+0x48]                                        ; 0aac
    add rdx,[rbp+0xd0]                                         ; 0ab1
    shl r12,byte 0x3                                           ; 0ab8
    sub rsp,0x20                                               ; 0abc
    mov rcx,r14                                                ; 0ac0
    mov r8,r12                                                 ; 0ac3
    call $+5                                                   ; 0ac6 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    mov r9,[rbp+0xc0]                                          ; 0acb
    mov rdx,[rbp+0x118]                                        ; 0ad2
    add rsp,0x20                                               ; 0ad9
    jmp short loc_0b03                                          ; 0add
    nop                                                        ; 0adf
loc_0ae0:
    lea rax,[rbx-0x1]                                          ; 0ae0
    imul rax,[rbp+0x48]                                        ; 0ae4
    add rax,r15                                                ; 0ae9
    xor ecx,ecx                                                ; 0aec
    o16 nop                                                    ; 0aee
loc_0af0:
    movsd xmm0,qword [rax+rcx*8]                               ; 0af0
    movsd qword [r14+rcx*8],xmm0                               ; 0af5
    inc rcx                                                    ; 0afb
    cmp r12,rcx                                                ; 0afe
    jnz short loc_0af0                                          ; 0b01
loc_0b03:
    mov rax,[rbp+0xf0]                                         ; 0b03
    lea rax,[rax+rbx*8]                                        ; 0b0a
    add rax,0xfffffffffffffff8                                 ; 0b0e
    sub rsp,0x60                                               ; 0b12
    mov [rsp+0x58],rdx                                         ; 0b16
    lea rcx,[rel $+7]                                          ; 0b1b | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=00000000
    mov [rsp+0x50],rcx                                         ; 0b22
    mov rcx,[rbp+0x18]                                         ; 0b27
    mov [rsp+0x48],rcx                                         ; 0b2b
    mov rcx,[rbp+0x20]                                         ; 0b30
    mov [rsp+0x40],rcx                                         ; 0b34
    mov [rsp+0x38],rax                                         ; 0b39
    mov rax,[rbp+0x38]                                         ; 0b3e
    mov [rsp+0x30],rax                                         ; 0b42
    mov [rsp+0x28],rdi                                         ; 0b47
    mov [rsp+0x20],r9                                          ; 0b4c
    mov rcx,r13                                                ; 0b51
    mov rdx,r14                                                ; 0b54
    lea r8,[rel $+7]                                           ; 0b57 | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=00000000
    mov r9,[rbp+0x50]                                          ; 0b5e
    call $+5                                                   ; 0b62 | REL32 +1 STABILITY_RCM addendLE=00000000
    add rsp,0x60                                               ; 0b67
    cmp qword [rel $+7],0x0                                    ; 0b6b | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=ffffffff
    jz near loc_0a70                                            ; 0b73
    mov qword [rel $+7],0x1fe                                  ; 0b79 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    mov rax,[rbp+0x110]                                        ; 0b84
    mov qword [rax],0x2                                        ; 0b8b
    sub rsp,0x30                                               ; 0b92
    mov qword [rsp+0x20],0xf                                   ; 0b96
    mov r9d,0xf                                                ; 0b9f
    lea rcx,[rel $+7]                                          ; 0ba5 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0bac | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 0bb3 | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 0bba | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 0bbf
    jmp near loc_0a70                                           ; 0bc3
loc_0bc8:
    mov qword [rel $+7],0x1                                    ; 0bc8 | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=fcffffff
    mov r12,[r13+0x0]                                          ; 0bd3
loc_0bd7:
    mov qword [rel $+7],0x1                                    ; 0bd7 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=fcffffff
    test r12,r12                                               ; 0be2
    jng near loc_0d0b                                           ; 0be5
    lea rbx,[rel $+7]                                          ; 0beb | REL32 +3 COMPUTE_AZEOTROPES$CALC_TYPE addendLE=00000000
    xor r15d,r15d                                              ; 0bf2
    jmp short loc_0c1f                                          ; 0bf5
    nop word [dword rax+rax+0x0]                               ; 0bf7
loc_0c00:
    mov rsi,[r13+0x0]                                          ; 0c00
    mov r15,[rel $+7]                                          ; 0c04 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    lea rax,[r15+0x1]                                          ; 0c0b
    mov [rel $+7],rax                                          ; 0c0f | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
    cmp r15,r12                                                ; 0c16
    jnl near loc_0d0e                                           ; 0c19
loc_0c1f:
    sub rsp,0x20                                               ; 0c1f
    mov rcx,r14                                                ; 0c23
    xor edx,edx                                                ; 0c26
    mov r8,[rbp+0x48]                                          ; 0c28
    call $+5                                                   ; 0c2c | REL32 +1 _intel_fast_memset addendLE=00000000
    add rsp,0x20                                               ; 0c31
    mov rax,0x3ff0000000000000                                 ; 0c35
    mov [r14+r15*8],rax                                        ; 0c3f
    mov rax,[rbp+0x30]                                         ; 0c43
    lea rax,[rax+r15*8]                                        ; 0c47
    sub rsp,0x60                                               ; 0c4b
    mov rcx,[rbp+0x118]                                        ; 0c4f
    mov [rsp+0x58],rcx                                         ; 0c56
    lea rcx,[rel $+7]                                          ; 0c5b | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=00000000
    mov [rsp+0x50],rcx                                         ; 0c62
    mov rcx,[rbp+0x18]                                         ; 0c67
    mov [rsp+0x48],rcx                                         ; 0c6b
    mov rcx,[rbp+0x20]                                         ; 0c70
    mov [rsp+0x40],rcx                                         ; 0c74
    mov [rsp+0x38],rax                                         ; 0c79
    mov rax,[rbp+0x38]                                         ; 0c7e
    mov [rsp+0x30],rax                                         ; 0c82
    mov [rsp+0x28],rdi                                         ; 0c87
    mov rax,[rbp+0xc0]                                         ; 0c8c
    mov [rsp+0x20],rax                                         ; 0c93
    mov rcx,r13                                                ; 0c98
    mov rdx,r14                                                ; 0c9b
    mov r8,rbx                                                 ; 0c9e
    mov r9,[rbp+0x50]                                          ; 0ca1
    call $+5                                                   ; 0ca5 | REL32 +1 STABILITY_RCM addendLE=00000000
    add rsp,0x60                                               ; 0caa
    cmp qword [rel $+7],0x0                                    ; 0cae | REL32 +3 COMPUTE_AZEOTROPES$JERR addendLE=ffffffff
    jz near loc_0c00                                            ; 0cb6
    mov qword [rel $+7],0x1fe                                  ; 0cbc | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=fcffffff
    mov rax,[rbp+0x110]                                        ; 0cc7
    mov qword [rax],0x2                                        ; 0cce
    sub rsp,0x30                                               ; 0cd5
    mov qword [rsp+0x20],0xf                                   ; 0cd9
    mov r9d,0xf                                                ; 0ce2
    lea rcx,[rel $+7]                                          ; 0ce8 | REL32 +3 COMPUTE_AZEOTROPES$IMSG addendLE=00000000
    lea rdx,[rel $+7]                                          ; 0cef | REL32 +3 COMPUTE_AZEOTROPES$SUB_NAME addendLE=00000000
    lea r8,[rel $+7]                                           ; 0cf6 | REL32 +3 COMPUTE_AZEOTROPES$OPT_MESSAGE addendLE=00000000
    call $+5                                                   ; 0cfd | REL32 +1 ERR_MSG addendLE=00000000
    add rsp,0x30                                               ; 0d02
    jmp near loc_0c00                                           ; 0d06
loc_0d0b:
    mov rsi,r12                                                ; 0d0b
loc_0d0e:
    mov rdi,[rbp+0x48]                                         ; 0d0e
    mov r8,[rbp-0x10]                                          ; 0d12
    imul r8,rdi                                                ; 0d16
    sub rsp,0x20                                               ; 0d1a
    mov r14,[rbp+0xf8]                                         ; 0d1e
    mov rcx,r14                                                ; 0d25
    xor edx,edx                                                ; 0d28
    call $+5                                                   ; 0d2a | REL32 +1 _intel_fast_memset addendLE=00000000
    add rsp,0x20                                               ; 0d2f
    mov qword [rel $+7],0x1                                    ; 0d33 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=fcffffff
    test rsi,rsi                                               ; 0d3e
    mov r13,[rbp+0xd0]                                         ; 0d41
    mov r9,[rbp+0xc8]                                          ; 0d48
    jng short loc_0d89                                          ; 0d4f
    lea rax,[rdi+0x8]                                          ; 0d51
    xor ecx,ecx                                                ; 0d55
    mov rdx,0x3ff0000000000000                                 ; 0d57
    mov r8,r14                                                 ; 0d61
    db 0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0d64 | nop word [cs:rax+rax+0x0]
loc_0d70:
    mov [r8],rdx                                               ; 0d70
    add r8,rax                                                 ; 0d73
    inc rcx                                                    ; 0d76
    cmp rcx,rsi                                                ; 0d79
    jl short loc_0d70                                           ; 0d7c
    lea rax,[rsi+0x1]                                          ; 0d7e
    mov [rel $+7],rax                                          ; 0d82 | REL32 +3 COMPUTE_AZEOTROPES$I addendLE=00000000
loc_0d89:
    mov rax,[r9]                                               ; 0d89
    mov [rbp+0x50],rax                                         ; 0d8c
    test rax,rax                                               ; 0d90
    jng near loc_0e47                                           ; 0d93
    test rsi,rsi                                               ; 0d99
    jng near loc_0e47                                           ; 0d9c
    cmp rsi,0xd                                                ; 0da2
    jc short loc_0df2                                           ; 0da6
    lea rdi,[rsi*8+0x0]                                        ; 0da8
    mov rax,[rbp+0x0]                                          ; 0db0
    imul rax,rsi                                               ; 0db4
    lea r14,[r14+rax*8]                                        ; 0db8
    xor r15d,r15d                                              ; 0dbc
    mov r12,[rbp+0x50]                                         ; 0dbf
    mov rbx,[rbp+0x48]                                         ; 0dc3
    nop word [dword rax+rax+0x0]                               ; 0dc7
loc_0dd0:
    lea rcx,[r14+r15]                                          ; 0dd0
    lea rdx,[r15+r13]                                          ; 0dd4
    sub rsp,0x20                                               ; 0dd8
    mov r8,rdi                                                 ; 0ddc
    call $+5                                                   ; 0ddf | REL32 +1 _intel_fast_memcpy addendLE=00000000
    add rsp,0x20                                               ; 0de4
    add r15,rbx                                                ; 0de8
    dec r12                                                    ; 0deb
    jnz short loc_0dd0                                          ; 0dee
    jmp short loc_0e47                                          ; 0df0
loc_0df2:
    mov rax,[rbp+0x50]                                         ; 0df2
    dec rax                                                    ; 0df6
    mov rcx,[rbp+0x0]                                          ; 0df9
    imul rcx,rsi                                               ; 0dfd
    lea rcx,[r14+rcx*8]                                        ; 0e01
    xor edx,edx                                                ; 0e05
    mov r9,[rbp+0x48]                                          ; 0e07
    nop dword [byte rax+rax+0x0]                               ; 0e0b
loc_0e10:
    xor r8d,r8d                                                ; 0e10
    db 0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0e13 | nop word [cs:rax+rax+0x0]
loc_0e20:
    movsd xmm0,qword [r13+r8*8+0x0]                            ; 0e20
    movsd qword [rcx+r8*8],xmm0                                ; 0e27
    inc r8                                                     ; 0e2d
    cmp rsi,r8                                                 ; 0e30
    jnz short loc_0e20                                          ; 0e33
    lea r8,[rdx+0x1]                                           ; 0e35
    add r13,r9                                                 ; 0e39
    add rcx,r9                                                 ; 0e3c
    cmp rdx,rax                                                ; 0e3f
    mov rdx,r8                                                 ; 0e42
    jnz short loc_0e10                                          ; 0e45
loc_0e47:
    mov rdi,[rbp+0x108]                                        ; 0e47
    test rsi,rsi                                               ; 0e4e
    mov r14,[rbp+0xd8]                                         ; 0e51
    mov r15,[rbp+0xf0]                                         ; 0e58
    mov rdx,[rbp+0x30]                                         ; 0e5f
    mov rbx,[rbp+0x50]                                         ; 0e63
    jng short loc_0ea0                                          ; 0e67
    cmp rsi,0xc                                                ; 0e69
    jna short loc_0e89                                          ; 0e6d
    lea r8,[rsi*8+0x0]                                         ; 0e6f
    sub rsp,0x20                                               ; 0e77
    mov rcx,rdi                                                ; 0e7b
    call $+5                                                   ; 0e7e | REL32 +1 _intel_fast_memcpy addendLE=00000000
    add rsp,0x20                                               ; 0e83
    jmp short loc_0ea0                                          ; 0e87
loc_0e89:
    xor eax,eax                                                ; 0e89
    nop dword [byte rax+rax+0x0]                               ; 0e8b
loc_0e90:
    mov rcx,[rdx+rax*8]                                        ; 0e90
    mov [rdi+rax*8],rcx                                        ; 0e94
    inc rax                                                    ; 0e98
    cmp rsi,rax                                                ; 0e9b
    jnz short loc_0e90                                          ; 0e9e
loc_0ea0:
    test rbx,rbx                                               ; 0ea0
    jng short loc_0ee0                                          ; 0ea3
    cmp rbx,0xc                                                ; 0ea5
    jna short loc_0ec9                                          ; 0ea9
    lea rcx,[rdi+rsi*8]                                        ; 0eab
    lea r8,[rbx*8+0x0]                                         ; 0eaf
    sub rsp,0x20                                               ; 0eb7
    mov rdx,r15                                                ; 0ebb
    call $+5                                                   ; 0ebe | REL32 +1 _intel_fast_memcpy addendLE=00000000
    add rsp,0x20                                               ; 0ec3
    jmp short loc_0ee0                                          ; 0ec7
loc_0ec9:
    lea rax,[rdi+rsi*8]                                        ; 0ec9
    xor ecx,ecx                                                ; 0ecd
    nop                                                        ; 0ecf
loc_0ed0:
    mov rdx,[r15+rcx*8]                                        ; 0ed0
    mov [rax+rcx*8],rdx                                        ; 0ed4
    inc rcx                                                    ; 0ed8
    cmp rbx,rcx                                                ; 0edb
    jnz short loc_0ed0                                          ; 0ede
loc_0ee0:
    mov rdi,[rbp+0x100]                                        ; 0ee0
    test rsi,rsi                                               ; 0ee7
    mov rdx,[rbp+0x10]                                         ; 0eea
    jng short loc_0f32                                          ; 0eee
    cmp rsi,0xc                                                ; 0ef0
    jna short loc_0f10                                          ; 0ef4
    lea r8,[rsi*8+0x0]                                         ; 0ef6
    sub rsp,0x20                                               ; 0efe
    mov rcx,rdi                                                ; 0f02
    call $+5                                                   ; 0f05 | REL32 +1 _intel_fast_memcpy addendLE=00000000
    add rsp,0x20                                               ; 0f0a
    jmp short loc_0f32                                          ; 0f0e
loc_0f10:
    xor eax,eax                                                ; 0f10
    db 0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0f12 | nop word [cs:rax+rax+0x0]
loc_0f20:
    movsd xmm0,qword [rdx+rax*8]                               ; 0f20
    movsd qword [rdi+rax*8],xmm0                               ; 0f25
    inc rax                                                    ; 0f2a
    cmp rsi,rax                                                ; 0f2d
    jnz short loc_0f20                                          ; 0f30
loc_0f32:
    test rbx,rbx                                               ; 0f32
    jng short loc_0f73                                          ; 0f35
    cmp rbx,0xc                                                ; 0f37
    jna short loc_0f5a                                          ; 0f3b
    lea rcx,[rdi+rsi*8]                                        ; 0f3d
    shl rbx,byte 0x3                                           ; 0f41
    sub rsp,0x20                                               ; 0f45
    mov rdx,r14                                                ; 0f49
    mov r8,rbx                                                 ; 0f4c
    call $+5                                                   ; 0f4f | REL32 +1 _intel_fast_memcpy addendLE=00000000
    add rsp,0x20                                               ; 0f54
    jmp short loc_0f73                                          ; 0f58
loc_0f5a:
    lea rax,[rdi+rsi*8]                                        ; 0f5a
    xor ecx,ecx                                                ; 0f5e
loc_0f60:
    movsd xmm0,qword [r14+rcx*8]                               ; 0f60
    movsd qword [rax+rcx*8],xmm0                               ; 0f66
    inc rcx                                                    ; 0f6b
    cmp rbx,rcx                                                ; 0f6e
    jnz short loc_0f60                                          ; 0f71
loc_0f73:
    mov qword [rbp-0x78],0x0                                   ; 0f73
    mov dword [rbp+0xc],0x1                                    ; 0f7b
    sub rsp,0x30                                               ; 0f82
    mov qword [rsp+0x20],0x0                                   ; 0f86
    lea rcx,[rbp-0x78]                                         ; 0f8f
    lea r9,[rbp+0xc]                                           ; 0f93
    xor edx,edx                                                ; 0f97
    mov r8,0x801208384ff00                                     ; 0f99
    call $+5                                                   ; 0fa3 | REL32 +1 for_close addendLE=00000000
    nop                                                        ; 0fa8
    lea rsp,[rbp+0x58]                                         ; 0fa9
    pop rbx                                                    ; 0fad
    pop rdi                                                    ; 0fae
    pop rsi                                                    ; 0faf
    pop r12                                                    ; 0fb0
    pop r13                                                    ; 0fb2
    pop r14                                                    ; 0fb4
    pop r15                                                    ; 0fb6
    pop rbp                                                    ; 0fb8
    retq                                                       ; 0fb9

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x41,0x7a,0x65,0x6f,0x5f,0x53,0x65,0x61,0x72,0x63,0x68,0x00,0x20,0x20,0x20

; .xdata (COFF section 4)
coff_section_4:
    db 0x01,0x1b,0x0b,0x85,0x1b,0x03,0x13,0x01,0x1b,0x00,0x0c,0x30,0x0b,0x70,0x0a,0x60
    db 0x09,0xc0,0x07,0xd0,0x05,0xe0,0x03,0xf0,0x01,0x50,0x00,0x00

; .rdata (COFF section 5)
coff_section_5:
    db 0x4e,0x55,0x4c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00
    db 0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00

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
    dd 0x00000fba ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 6)
