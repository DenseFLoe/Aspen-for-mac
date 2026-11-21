; x64\Release\open_his_rpt_file.obj
; Reconstructed Win64 NASM source. Original .text offsets follow the instructions.
bits 64

extern for_cpystr:function
required __ImageBase:function
extern for_concat:function
extern memmove:function
extern for_inquire:function
extern for_open:function
extern for_write_int_fmt:function
extern CLOSE_HIS_RPT_FILE:function
global OPEN_HIS_RPT_FILE:function
global DMOFIL:function
global DMO_STRLEN:function
global RESET_HIS_RPT_FILE:function
global DMO_LOWER:function

section .text code align=16

; Build names, inquire and open history, error, and report units, then initialize output.
OPEN_HIS_RPT_FILE:
section_text:
    push rbx                                                                    ; .text+0x0000
    push rsi                                                                    ; .text+0x0001
    push rdi                                                                    ; .text+0x0002
    push r12                                                                    ; .text+0x0003
    push r13                                                                    ; .text+0x0005
    push r14                                                                    ; .text+0x0007
    push r15                                                                    ; .text+0x0009
    push rbp                                                                    ; .text+0x000b
    sub rsp, 0x2f8                                                              ; .text+0x000c
    mov r14, rdx                                                                ; .text+0x0013
    mov rax, rsp                                                                ; .text+0x0016
    mov rbp, rcx                                                                ; .text+0x0019
    lea rcx, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x001c
    mov edx, 0x50                                                               ; .text+0x0023
    mov r8, rbp                                                                 ; .text+0x0028
    mov r9, r14                                                                 ; .text+0x002b
    xor r15d, r15d                                                              ; .text+0x002e
    lea rdi, [rel __STRLITPACK_19]                                              ; .text+0x0031
    mov qword [byte rax + 0x20], 0                                              ; .text+0x0038
    mov r13, r15                                                                ; .text+0x0040
    call for_cpystr                                                             ; .text+0x0043
    lea rdx, [rel __STRLITPACK_8]                                               ; .text+0x0048
    lea rax, [dword rsp + 0x2d8]                                                ; .text+0x004f
    mov rbx, rax                                                                ; .text+0x0057
    mov r15, rdx                                                                ; .text+0x005a
    lea rsi, [rel __STRLITPACK_20]                                              ; .text+0x005d
    lea r12, [dword rsp + 0x2d0]                                                ; .text+0x0064
branch_006c:
    xor r11d, r11d                                                              ; .text+0x006c
    mov r10, 0xffffffffffffffff                                                 ; .text+0x006f
    xor ecx, ecx                                                                ; .text+0x0076
    lea rax, [rel __ImageBase]                                                  ; .text+0x0078
branch_007f:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 wrt ..imagebase], 0x20 ; .text+0x007f
    jbe short branch_0095                                                       ; .text+0x0087
    test r11, r11                                                               ; .text+0x0089
    lea r10, [byte rcx + rcx + 1]                                               ; .text+0x008c
    cmove r11, r10                                                              ; .text+0x0091
branch_0095:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 + 1 wrt ..imagebase], 0x20 ; .text+0x0095
    jbe short branch_00ab                                                       ; .text+0x009d
    test r11, r11                                                               ; .text+0x009f
    lea r10, [byte rcx + rcx + 2]                                               ; .text+0x00a2
    cmove r11, r10                                                              ; .text+0x00a7
branch_00ab:
    inc rcx                                                                     ; .text+0x00ab
    cmp rcx, strict byte 0x28                                                   ; .text+0x00ae
    jb short branch_007f                                                        ; .text+0x00b2
    sub r10, r11                                                                ; .text+0x00b4
    lea r11, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x00b7
    mov edx, 3                                                                  ; .text+0x00be
    lea rcx, [dword rsp + 0x90]                                                 ; .text+0x00c3
    mov r9d, 6                                                                  ; .text+0x00cb
    mov [rcx], rsi                                                              ; .text+0x00d1
    mov qword [byte rcx + 8], 1                                                 ; .text+0x00d4
    lea r8, [byte r11 + r10 + 1]                                                ; .text+0x00dc
    mov [byte rcx + 0x10], r15                                                  ; .text+0x00e1
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x00e5
    mov [byte rcx + 0x20], rdi                                                  ; .text+0x00ed
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x00f1
    call for_concat                                                             ; .text+0x00f9
    mov r10d, 1                                                                 ; .text+0x00fe
    lea r11, [rel __ImageBase]                                                  ; .text+0x0104
branch_010b:
    movzx edx, byte [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x010b
    cmp edx, strict byte 0x27                                                   ; .text+0x0114
    jne short branch_016b                                                       ; .text+0x0117
    mov byte [dword rsp + r10 + 0x1df], 0x27                                    ; .text+0x0119
    inc r10                                                                     ; .text+0x0122
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0125
    cmp cl, strict byte 0x27                                                    ; .text+0x012d
    je short branch_0158                                                        ; .text+0x0130
branch_0132:
    cmp r10, strict byte 0x51                                                   ; .text+0x0132
    je short branch_01a7                                                        ; .text+0x0136
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0138
    mov [dword rsp + r10 + 0x1df], cl                                           ; .text+0x0140
    inc r10                                                                     ; .text+0x0148
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x014b
    cmp cl, strict byte 0x27                                                    ; .text+0x0153
    jne short branch_0132                                                       ; .text+0x0156
branch_0158:
    cmp r10, strict byte 0x51                                                   ; .text+0x0158
    je short branch_01a7                                                        ; .text+0x015c
    mov [dword rsp + r10 + 0x1df], cl                                           ; .text+0x015e
    inc r10                                                                     ; .text+0x0166
    jmp short branch_019d                                                       ; .text+0x0169
branch_016b:
    xor eax, eax                                                                ; .text+0x016b
    cmp edx, strict byte 0x41                                                   ; .text+0x016d
    setge al                                                                    ; .text+0x0170
    xor ecx, ecx                                                                ; .text+0x0173
    cmp edx, strict byte 0x5a                                                   ; .text+0x0175
    setle cl                                                                    ; .text+0x0178
    dec eax                                                                     ; .text+0x017b
    dec ecx                                                                     ; .text+0x017d
    or eax, ecx                                                                 ; .text+0x017f
    test al, 1                                                                  ; .text+0x0181
    je short branch_018f                                                        ; .text+0x0183
    mov [dword rsp + r10 + 0x1df], dl                                           ; .text+0x0185
    jmp short branch_019a                                                       ; .text+0x018d
branch_018f:
    add edx, strict byte 0x20                                                   ; .text+0x018f
    mov [dword rsp + r10 + 0x1df], dl                                           ; .text+0x0192
branch_019a:
    inc r10                                                                     ; .text+0x019a
branch_019d:
    cmp r10, strict byte 0x51                                                   ; .text+0x019d
    jne near branch_010b                                                        ; .text+0x01a1
branch_01a7:
    lea rcx, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x01a7
    lea rdx, [dword rsp + 0x1e0]                                                ; .text+0x01ae
    mov r8d, 0x50                                                               ; .text+0x01b6
    call memmove                                                                ; .text+0x01bc
    mov r10, rsp                                                                ; .text+0x01c1
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x01c4
    mov edx, 0x24                                                               ; .text+0x01cc
    mov r8, 0x801208384ff00                                                     ; .text+0x01d1
    lea r9, [rel __STRLITPACK_9.0.1]                                            ; .text+0x01db
    mov qword [rcx], 0                                                          ; .text+0x01e2
    mov [dword rcx + 0x218], r12                                                ; .text+0x01e9
    mov [byte r10 + 0x20], rbx                                                  ; .text+0x01f0
    call for_inquire                                                            ; .text+0x01f4
    test byte [dword rsp + 0x2d0], 1                                            ; .text+0x01f9
    jne near branch_0309                                                        ; .text+0x0201
    mov rcx, rsp                                                                ; .text+0x0207
    lea r11, [dword rsp + 0x198]                                                ; .text+0x020a
    mov edx, 0x24                                                               ; .text+0x0212
    mov r8, 0x801208384ff01                                                     ; .text+0x0217
    lea r9, [rel __STRLITPACK_10.0.1]                                           ; .text+0x0221
    lea r10, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x0228
    mov qword [dword r11 - 0xd8], 0                                             ; .text+0x022f
    mov [byte rcx + 0x20], r11                                                  ; .text+0x023a
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x023e
    mov qword [dword rcx + 0xd8], 0x50                                          ; .text+0x0246
    mov [dword rcx + 0xe0], r10                                                 ; .text+0x0251
    mov qword [dword rcx + 0xe8], 4                                             ; .text+0x0258
    call for_open                                                               ; .text+0x0263
    test eax, eax                                                               ; .text+0x0268
    jle near branch_0309                                                        ; .text+0x026a
    mov rcx, rsp                                                                ; .text+0x0270
    lea r11, [rel OPEN_HIS_RPT_FILE$format_pack.0.1]                            ; .text+0x0273
    mov rdx, 0x801208384ff00                                                    ; .text+0x027a
    lea r8, [rel __STRLITPACK_11.0.1]                                           ; .text+0x0284
    inc r13                                                                     ; .text+0x028b
    lea r9, [dword rsp + 0x150]                                                 ; .text+0x028e
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x0296
    mov [byte rcx + 0x20], r11                                                  ; .text+0x029d
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x02a1
    mov qword [rcx], 0                                                          ; .text+0x02a9
    mov qword [dword rcx + 0x90], 1                                             ; .text+0x02b0
    mov [dword rcx + 0x98], r10                                                 ; .text+0x02bb
    mov [dword rcx + 0xa0], r13                                                 ; .text+0x02c2
    call for_write_int_fmt                                                      ; .text+0x02c9
    mov edx, 2                                                                  ; .text+0x02ce
    lea rcx, [byte rsp + 0x30]                                                  ; .text+0x02d3
    lea r8, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                           ; .text+0x02d8
    mov r9d, 0x50                                                               ; .text+0x02df
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x02e5
    mov [rcx], rbp                                                              ; .text+0x02ec
    mov [byte rcx + 8], r14                                                     ; .text+0x02ef
    mov [byte rcx + 0x10], r10                                                  ; .text+0x02f3
    mov qword [byte rcx + 0x18], 1                                              ; .text+0x02f7
    call for_concat                                                             ; .text+0x02ff
    jmp near branch_006c                                                        ; .text+0x0304
branch_0309:
    mov rax, rsp                                                                ; .text+0x0309
    lea rcx, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x030c
    mov edx, 0x50                                                               ; .text+0x0313
    mov r8, rbp                                                                 ; .text+0x0318
    mov r9, r14                                                                 ; .text+0x031b
    xor r15d, r15d                                                              ; .text+0x031e
    mov r13, r15                                                                ; .text+0x0321
    lea rsi, [rel __STRLITPACK_19]                                              ; .text+0x0324
    mov qword [byte rax + 0x20], 0                                              ; .text+0x032b
    lea rbx, [rel __STRLITPACK_20]                                              ; .text+0x0333
    call for_cpystr                                                             ; .text+0x033a
    lea rdx, [rel __STRLITPACK_5]                                               ; .text+0x033f
    lea rax, [dword rsp + 0x2e0]                                                ; .text+0x0346
    mov r12, rax                                                                ; .text+0x034e
    mov r15, rdx                                                                ; .text+0x0351
    lea rdi, [dword rsp + 0x2d0]                                                ; .text+0x0354
branch_035c:
    xor r11d, r11d                                                              ; .text+0x035c
    mov r10, 0xffffffffffffffff                                                 ; .text+0x035f
    xor ecx, ecx                                                                ; .text+0x0366
    lea rax, [rel __ImageBase]                                                  ; .text+0x0368
branch_036f:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 wrt ..imagebase], 0x20 ; .text+0x036f
    jbe short branch_0385                                                       ; .text+0x0377
    test r11, r11                                                               ; .text+0x0379
    lea r10, [byte rcx + rcx + 1]                                               ; .text+0x037c
    cmove r11, r10                                                              ; .text+0x0381
branch_0385:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 + 1 wrt ..imagebase], 0x20 ; .text+0x0385
    jbe short branch_039b                                                       ; .text+0x038d
    test r11, r11                                                               ; .text+0x038f
    lea r10, [byte rcx + rcx + 2]                                               ; .text+0x0392
    cmove r11, r10                                                              ; .text+0x0397
branch_039b:
    inc rcx                                                                     ; .text+0x039b
    cmp rcx, strict byte 0x28                                                   ; .text+0x039e
    jb short branch_036f                                                        ; .text+0x03a2
    sub r10, r11                                                                ; .text+0x03a4
    lea r11, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x03a7
    mov edx, 3                                                                  ; .text+0x03ae
    lea rcx, [dword rsp + 0xf0]                                                 ; .text+0x03b3
    mov r9d, 6                                                                  ; .text+0x03bb
    mov [rcx], rbx                                                              ; .text+0x03c1
    mov qword [byte rcx + 8], 1                                                 ; .text+0x03c4
    lea r8, [byte r11 + r10 + 1]                                                ; .text+0x03cc
    mov [byte rcx + 0x10], r15                                                  ; .text+0x03d1
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x03d5
    mov [byte rcx + 0x20], rsi                                                  ; .text+0x03dd
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x03e1
    call for_concat                                                             ; .text+0x03e9
    mov r10d, 1                                                                 ; .text+0x03ee
    lea r11, [rel __ImageBase]                                                  ; .text+0x03f4
branch_03fb:
    movzx edx, byte [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x03fb
    cmp edx, strict byte 0x27                                                   ; .text+0x0404
    jne short branch_045b                                                       ; .text+0x0407
    mov byte [dword rsp + r10 + 0x22f], 0x27                                    ; .text+0x0409
    inc r10                                                                     ; .text+0x0412
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0415
    cmp cl, strict byte 0x27                                                    ; .text+0x041d
    je short branch_0448                                                        ; .text+0x0420
branch_0422:
    cmp r10, strict byte 0x51                                                   ; .text+0x0422
    je short branch_0497                                                        ; .text+0x0426
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0428
    mov [dword rsp + r10 + 0x22f], cl                                           ; .text+0x0430
    inc r10                                                                     ; .text+0x0438
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x043b
    cmp cl, strict byte 0x27                                                    ; .text+0x0443
    jne short branch_0422                                                       ; .text+0x0446
branch_0448:
    cmp r10, strict byte 0x51                                                   ; .text+0x0448
    je short branch_0497                                                        ; .text+0x044c
    mov [dword rsp + r10 + 0x22f], cl                                           ; .text+0x044e
    inc r10                                                                     ; .text+0x0456
    jmp short branch_048d                                                       ; .text+0x0459
branch_045b:
    xor eax, eax                                                                ; .text+0x045b
    cmp edx, strict byte 0x41                                                   ; .text+0x045d
    setge al                                                                    ; .text+0x0460
    xor ecx, ecx                                                                ; .text+0x0463
    cmp edx, strict byte 0x5a                                                   ; .text+0x0465
    setle cl                                                                    ; .text+0x0468
    dec eax                                                                     ; .text+0x046b
    dec ecx                                                                     ; .text+0x046d
    or eax, ecx                                                                 ; .text+0x046f
    test al, 1                                                                  ; .text+0x0471
    je short branch_047f                                                        ; .text+0x0473
    mov [dword rsp + r10 + 0x22f], dl                                           ; .text+0x0475
    jmp short branch_048a                                                       ; .text+0x047d
branch_047f:
    add edx, strict byte 0x20                                                   ; .text+0x047f
    mov [dword rsp + r10 + 0x22f], dl                                           ; .text+0x0482
branch_048a:
    inc r10                                                                     ; .text+0x048a
branch_048d:
    cmp r10, strict byte 0x51                                                   ; .text+0x048d
    jne near branch_03fb                                                        ; .text+0x0491
branch_0497:
    lea rcx, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x0497
    lea rdx, [dword rsp + 0x230]                                                ; .text+0x049e
    mov r8d, 0x50                                                               ; .text+0x04a6
    call memmove                                                                ; .text+0x04ac
    mov r10, rsp                                                                ; .text+0x04b1
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x04b4
    mov edx, 6                                                                  ; .text+0x04bc
    mov r8, 0x801208384ff00                                                     ; .text+0x04c1
    lea r9, [rel __STRLITPACK_12.0.1]                                           ; .text+0x04cb
    mov qword [rcx], 0                                                          ; .text+0x04d2
    mov [dword rcx + 0x220], rdi                                                ; .text+0x04d9
    mov [byte r10 + 0x20], r12                                                  ; .text+0x04e0
    call for_inquire                                                            ; .text+0x04e4
    test byte [dword rsp + 0x2d0], 1                                            ; .text+0x04e9
    jne near branch_05f9                                                        ; .text+0x04f1
    mov rcx, rsp                                                                ; .text+0x04f7
    lea r11, [dword rsp + 0x1b0]                                                ; .text+0x04fa
    mov edx, 6                                                                  ; .text+0x0502
    mov r8, 0x801208384ff01                                                     ; .text+0x0507
    lea r9, [rel __STRLITPACK_13.0.1]                                           ; .text+0x0511
    lea r10, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x0518
    mov qword [dword r11 - 0xf0], 0                                             ; .text+0x051f
    mov [byte rcx + 0x20], r11                                                  ; .text+0x052a
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x052e
    mov qword [dword rcx + 0xf0], 0x50                                          ; .text+0x0536
    mov [dword rcx + 0xf8], r10                                                 ; .text+0x0541
    mov qword [dword rcx + 0x100], 4                                            ; .text+0x0548
    call for_open                                                               ; .text+0x0553
    test eax, eax                                                               ; .text+0x0558
    jle near branch_05f9                                                        ; .text+0x055a
    mov rcx, rsp                                                                ; .text+0x0560
    lea r11, [rel OPEN_HIS_RPT_FILE$format_pack.0.1 + 20]                       ; .text+0x0563
    mov rdx, 0x801208384ff00                                                    ; .text+0x056a
    lea r8, [rel __STRLITPACK_14.0.1]                                           ; .text+0x0574
    inc r13                                                                     ; .text+0x057b
    lea r9, [dword rsp + 0x168]                                                 ; .text+0x057e
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x0586
    mov [byte rcx + 0x20], r11                                                  ; .text+0x058d
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0591
    mov qword [rcx], 0                                                          ; .text+0x0599
    mov qword [dword rcx + 0xa8], 1                                             ; .text+0x05a0
    mov [dword rcx + 0xb0], r10                                                 ; .text+0x05ab
    mov [dword rcx + 0xb8], r13                                                 ; .text+0x05b2
    call for_write_int_fmt                                                      ; .text+0x05b9
    mov edx, 2                                                                  ; .text+0x05be
    lea rcx, [byte rsp + 0x50]                                                  ; .text+0x05c3
    lea r8, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                           ; .text+0x05c8
    mov r9d, 0x50                                                               ; .text+0x05cf
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x05d5
    mov [rcx], rbp                                                              ; .text+0x05dc
    mov [byte rcx + 8], r14                                                     ; .text+0x05df
    mov [byte rcx + 0x10], r10                                                  ; .text+0x05e3
    mov qword [byte rcx + 0x18], 1                                              ; .text+0x05e7
    call for_concat                                                             ; .text+0x05ef
    jmp near branch_035c                                                        ; .text+0x05f4
branch_05f9:
    mov rax, rsp                                                                ; .text+0x05f9
    lea rcx, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x05fc
    mov edx, 0x50                                                               ; .text+0x0603
    mov r8, rbp                                                                 ; .text+0x0608
    mov r9, r14                                                                 ; .text+0x060b
    xor r15d, r15d                                                              ; .text+0x060e
    mov r13, r15                                                                ; .text+0x0611
    lea rdi, [rel __STRLITPACK_19]                                              ; .text+0x0614
    mov qword [byte rax + 0x20], 0                                              ; .text+0x061b
    lea rsi, [rel __STRLITPACK_20]                                              ; .text+0x0623
    call for_cpystr                                                             ; .text+0x062a
    lea rdx, [rel __STRLITPACK_2]                                               ; .text+0x062f
    lea rax, [dword rsp + 0x2e8]                                                ; .text+0x0636
    mov r15, rax                                                                ; .text+0x063e
    mov rbx, rdx                                                                ; .text+0x0641
    lea r12, [dword rsp + 0x2d0]                                                ; .text+0x0644
branch_064c:
    xor r9d, r9d                                                                ; .text+0x064c
    mov r8, 0xffffffffffffffff                                                  ; .text+0x064f
    xor ecx, ecx                                                                ; .text+0x0656
    lea r10, [rel __ImageBase]                                                  ; .text+0x0658
branch_065f:
    cmp byte [r10 + rcx*2 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 wrt ..imagebase], 0x20 ; .text+0x065f
    jbe short branch_0676                                                       ; .text+0x0668
    test r9, r9                                                                 ; .text+0x066a
    lea r8, [byte rcx + rcx + 1]                                                ; .text+0x066d
    cmove r9, r8                                                                ; .text+0x0672
branch_0676:
    cmp byte [r10 + rcx*2 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 + 1 wrt ..imagebase], 0x20 ; .text+0x0676
    jbe short branch_068d                                                       ; .text+0x067f
    test r9, r9                                                                 ; .text+0x0681
    lea r8, [byte rcx + rcx + 2]                                                ; .text+0x0684
    cmove r9, r8                                                                ; .text+0x0689
branch_068d:
    inc rcx                                                                     ; .text+0x068d
    cmp rcx, strict byte 0x28                                                   ; .text+0x0690
    jb short branch_065f                                                        ; .text+0x0694
    sub r8, r9                                                                  ; .text+0x0696
    lea r10, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x0699
    mov edx, 3                                                                  ; .text+0x06a0
    lea rcx, [dword rsp + 0x120]                                                ; .text+0x06a5
    mov r9d, 6                                                                  ; .text+0x06ad
    mov [rcx], rsi                                                              ; .text+0x06b3
    mov qword [byte rcx + 8], 1                                                 ; .text+0x06b6
    lea r8, [byte r10 + r8 + 1]                                                 ; .text+0x06be
    mov [byte rcx + 0x10], rbx                                                  ; .text+0x06c3
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x06c7
    mov [byte rcx + 0x20], rdi                                                  ; .text+0x06cf
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x06d3
    call for_concat                                                             ; .text+0x06db
    mov r8d, 1                                                                  ; .text+0x06e0
    lea r9, [rel __ImageBase]                                                   ; .text+0x06e6
branch_06ed:
    movzx r11d, byte [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x06ed
    cmp r11d, strict byte 0x27                                                  ; .text+0x06f6
    jne short branch_074e                                                       ; .text+0x06fa
    mov byte [dword rsp + r8 + 0x27f], 0x27                                     ; .text+0x06fc
    inc r8                                                                      ; .text+0x0705
    mov cl, [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0708
    cmp cl, strict byte 0x27                                                    ; .text+0x0710
    je short branch_073b                                                        ; .text+0x0713
branch_0715:
    cmp r8, strict byte 0x51                                                    ; .text+0x0715
    je short branch_0796                                                        ; .text+0x0719
    mov cl, [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x071b
    mov [dword rsp + r8 + 0x27f], cl                                            ; .text+0x0723
    inc r8                                                                      ; .text+0x072b
    mov cl, [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x072e
    cmp cl, strict byte 0x27                                                    ; .text+0x0736
    jne short branch_0715                                                       ; .text+0x0739
branch_073b:
    cmp r8, strict byte 0x51                                                    ; .text+0x073b
    je short branch_0796                                                        ; .text+0x073f
    mov [dword rsp + r8 + 0x27f], cl                                            ; .text+0x0741
    inc r8                                                                      ; .text+0x0749
    jmp short branch_078c                                                       ; .text+0x074c
branch_074e:
    xor r10d, r10d                                                              ; .text+0x074e
    cmp r11d, strict byte 0x41                                                  ; .text+0x0751
    setge r10b                                                                  ; .text+0x0755
    xor ecx, ecx                                                                ; .text+0x0759
    cmp r11d, strict byte 0x5a                                                  ; .text+0x075b
    setle cl                                                                    ; .text+0x075f
    dec r10d                                                                    ; .text+0x0762
    dec ecx                                                                     ; .text+0x0765
    or r10d, ecx                                                                ; .text+0x0767
    test r10d, 1                                                                ; .text+0x076a
    je short branch_077d                                                        ; .text+0x0771
    mov [dword rsp + r8 + 0x27f], r11b                                          ; .text+0x0773
    jmp short branch_0789                                                       ; .text+0x077b
branch_077d:
    add r11d, strict byte 0x20                                                  ; .text+0x077d
    mov [dword rsp + r8 + 0x27f], r11b                                          ; .text+0x0781
branch_0789:
    inc r8                                                                      ; .text+0x0789
branch_078c:
    cmp r8, strict byte 0x51                                                    ; .text+0x078c
    jne near branch_06ed                                                        ; .text+0x0790
branch_0796:
    lea rcx, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x0796
    lea rdx, [dword rsp + 0x280]                                                ; .text+0x079d
    mov r8d, 0x50                                                               ; .text+0x07a5
    call memmove                                                                ; .text+0x07ab
    mov r10, rsp                                                                ; .text+0x07b0
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x07b3
    mov edx, 0xe                                                                ; .text+0x07bb
    mov r8, 0x801208384ff00                                                     ; .text+0x07c0
    lea r9, [rel __STRLITPACK_15.0.1]                                           ; .text+0x07ca
    mov qword [rcx], 0                                                          ; .text+0x07d1
    mov [dword rcx + 0x228], r12                                                ; .text+0x07d8
    mov [byte r10 + 0x20], r15                                                  ; .text+0x07df
    call for_inquire                                                            ; .text+0x07e3
    test byte [dword rsp + 0x2d0], 1                                            ; .text+0x07e8
    jne near branch_08f8                                                        ; .text+0x07f0
    mov rcx, rsp                                                                ; .text+0x07f6
    lea r11, [dword rsp + 0x1c8]                                                ; .text+0x07f9
    mov edx, 0xe                                                                ; .text+0x0801
    mov r8, 0x801208384ff01                                                     ; .text+0x0806
    lea r9, [rel __STRLITPACK_16.0.1]                                           ; .text+0x0810
    lea r10, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x0817
    mov qword [dword r11 - 0x108], 0                                            ; .text+0x081e
    mov [byte rcx + 0x20], r11                                                  ; .text+0x0829
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x082d
    mov qword [dword rcx + 0x108], 0x50                                         ; .text+0x0835
    mov [dword rcx + 0x110], r10                                                ; .text+0x0840
    mov qword [dword rcx + 0x118], 4                                            ; .text+0x0847
    call for_open                                                               ; .text+0x0852
    test eax, eax                                                               ; .text+0x0857
    jle near branch_08f8                                                        ; .text+0x0859
    mov rcx, rsp                                                                ; .text+0x085f
    lea r11, [rel OPEN_HIS_RPT_FILE$format_pack.0.1 + 40]                       ; .text+0x0862
    mov rdx, 0x801208384ff00                                                    ; .text+0x0869
    lea r8, [rel __STRLITPACK_17.0.1]                                           ; .text+0x0873
    inc r13                                                                     ; .text+0x087a
    lea r9, [dword rsp + 0x180]                                                 ; .text+0x087d
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x0885
    mov [byte rcx + 0x20], r11                                                  ; .text+0x088c
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0890
    mov qword [rcx], 0                                                          ; .text+0x0898
    mov qword [dword rcx + 0xc0], 1                                             ; .text+0x089f
    mov [dword rcx + 0xc8], r10                                                 ; .text+0x08aa
    mov [dword rcx + 0xd0], r13                                                 ; .text+0x08b1
    call for_write_int_fmt                                                      ; .text+0x08b8
    mov edx, 2                                                                  ; .text+0x08bd
    lea rcx, [byte rsp + 0x70]                                                  ; .text+0x08c2
    lea r8, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                           ; .text+0x08c7
    mov r9d, 0x50                                                               ; .text+0x08ce
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x08d4
    mov [rcx], rbp                                                              ; .text+0x08db
    mov [byte rcx + 8], r14                                                     ; .text+0x08de
    mov [byte rcx + 0x10], r10                                                  ; .text+0x08e2
    mov qword [byte rcx + 0x18], 1                                              ; .text+0x08e6
    call for_concat                                                             ; .text+0x08ee
    jmp near branch_064c                                                        ; .text+0x08f3
branch_08f8:
    add rsp, 0x2f8                                                              ; .text+0x08f8
    pop rbp                                                                     ; .text+0x08ff
    pop r15                                                                     ; .text+0x0900
    pop r14                                                                     ; .text+0x0902
    pop r13                                                                     ; .text+0x0904
    pop r12                                                                     ; .text+0x0906
    pop rdi                                                                     ; .text+0x0908
    pop rsi                                                                     ; .text+0x0909
    pop rbx                                                                     ; .text+0x090a
    ret                                                                         ; .text+0x090b
    nop dword [byte rax]                                                        ; .text+0x090c

; Build a file name with a dot and suffix, then lowercase it outside single quotes.
DMOFIL:
    push rdi                                                                    ; .text+0x0910
    sub rsp, 0xa0                                                               ; .text+0x0911
    mov rdi, rcx                                                                ; .text+0x0918
    mov r11, [r8]                                                               ; .text+0x091b
    lea rcx, [byte rsp + 0x20]                                                  ; .text+0x091e
    mov [byte rcx + 0x10], rdx                                                  ; .text+0x0923
    mov edx, 3                                                                  ; .text+0x0927
    mov r9d, 6                                                                  ; .text+0x092c
    lea rax, [rel __STRLITPACK_20]                                              ; .text+0x0932
    lea r10, [rel __STRLITPACK_19]                                              ; .text+0x0939
    lea r8, [byte rdi + r11 - 1]                                                ; .text+0x0940
    mov [rcx], rax                                                              ; .text+0x0945
    mov qword [byte rcx + 8], 1                                                 ; .text+0x0948
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x0950
    mov [byte rcx + 0x20], r10                                                  ; .text+0x0958
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x095c
    call for_concat                                                             ; .text+0x0964
    mov edx, 1                                                                  ; .text+0x0969
branch_096e:
    movzx r9d, byte [byte rdx + rdi - 1]                                        ; .text+0x096e
    cmp r9d, strict byte 0x27                                                   ; .text+0x0974
    jne short branch_09b2                                                       ; .text+0x0978
    mov byte [byte rsp + rdx + 0x4f], 0x27                                      ; .text+0x097a
    inc rdx                                                                     ; .text+0x097f
    mov al, [byte rdx + rdi - 1]                                                ; .text+0x0982
    cmp al, 0x27                                                                ; .text+0x0986
    je short branch_09a3                                                        ; .text+0x0988
branch_098a:
    cmp rdx, strict byte 0x51                                                   ; .text+0x098a
    je short branch_09f4                                                        ; .text+0x098e
    mov al, [byte rdx + rdi - 1]                                                ; .text+0x0990
    mov [byte rsp + rdx + 0x4f], al                                             ; .text+0x0994
    inc rdx                                                                     ; .text+0x0998
    mov al, [byte rdx + rdi - 1]                                                ; .text+0x099b
    cmp al, 0x27                                                                ; .text+0x099f
    jne short branch_098a                                                       ; .text+0x09a1
branch_09a3:
    cmp rdx, strict byte 0x51                                                   ; .text+0x09a3
    je short branch_09f4                                                        ; .text+0x09a7
    mov [byte rsp + rdx + 0x4f], al                                             ; .text+0x09a9
    inc rdx                                                                     ; .text+0x09ad
    jmp short branch_09ea                                                       ; .text+0x09b0
branch_09b2:
    xor r8d, r8d                                                                ; .text+0x09b2
    cmp r9d, strict byte 0x41                                                   ; .text+0x09b5
    setge r8b                                                                   ; .text+0x09b9
    xor eax, eax                                                                ; .text+0x09bd
    cmp r9d, strict byte 0x5a                                                   ; .text+0x09bf
    setle al                                                                    ; .text+0x09c3
    dec r8d                                                                     ; .text+0x09c6
    dec eax                                                                     ; .text+0x09c9
    or r8d, eax                                                                 ; .text+0x09cb
    test r8d, 1                                                                 ; .text+0x09ce
    je short branch_09de                                                        ; .text+0x09d5
    mov [byte rsp + rdx + 0x4f], r9b                                            ; .text+0x09d7
    jmp short branch_09e7                                                       ; .text+0x09dc
branch_09de:
    add r9d, strict byte 0x20                                                   ; .text+0x09de
    mov [byte rsp + rdx + 0x4f], r9b                                            ; .text+0x09e2
branch_09e7:
    inc rdx                                                                     ; .text+0x09e7
branch_09ea:
    cmp rdx, strict byte 0x51                                                   ; .text+0x09ea
    jne near branch_096e                                                        ; .text+0x09ee
branch_09f4:
    mov rcx, rdi                                                                ; .text+0x09f4
    lea rdx, [byte rsp + 0x50]                                                  ; .text+0x09f7
    mov r8d, 0x50                                                               ; .text+0x09fc
    call memmove                                                                ; .text+0x0a02
    add rsp, 0xa0                                                               ; .text+0x0a07
    pop rdi                                                                     ; .text+0x0a0e
    ret                                                                         ; .text+0x0a0f

; Scan the character field for positions with bytes above ASCII space.
DMO_STRLEN:
    mov r11, rcx                                                                ; .text+0x0a10
    xor r8d, r8d                                                                ; .text+0x0a13
    mov rax, 0xffffffffffffffff                                                 ; .text+0x0a16
    test rdx, rdx                                                               ; .text+0x0a1d
    jle short branch_0a98                                                       ; .text+0x0a20
    mov r9, rdx                                                                 ; .text+0x0a22
    mov ecx, 1                                                                  ; .text+0x0a25
    xor r10d, r10d                                                              ; .text+0x0a2a
    shr r9, 1                                                                   ; .text+0x0a2d
    je short branch_0a7e                                                        ; .text+0x0a30
    cmp byte [r11], strict byte 0x20                                            ; .text+0x0a32
    jbe short branch_0a42                                                       ; .text+0x0a36
    xor ecx, ecx                                                                ; .text+0x0a38
branch_0a3a:
    lea r8, [byte rcx + 1]                                                      ; .text+0x0a3a
branch_0a3e:
    lea rax, [byte rcx + 1]                                                     ; .text+0x0a3e
branch_0a42:
    cmp byte [byte r11 + r10*2 + 1], strict byte 0x20                           ; .text+0x0a42
    jbe short branch_0a56                                                       ; .text+0x0a48
    test r8, r8                                                                 ; .text+0x0a4a
    lea rax, [byte r10 + r10 + 2]                                               ; .text+0x0a4d
    cmove r8, rax                                                               ; .text+0x0a52
branch_0a56:
    inc r10                                                                     ; .text+0x0a56
    cmp r10, r9                                                                 ; .text+0x0a59
    jae short branch_0a79                                                       ; .text+0x0a5c
    lea rcx, [r10 + r10]                                                        ; .text+0x0a5e
    cmp byte [r11 + rcx], strict byte 0x20                                      ; .text+0x0a62
    jbe short branch_0a42                                                       ; .text+0x0a67
    nop word [dword rax + rax]                                                  ; .text+0x0a69
    test r8, r8                                                                 ; .text+0x0a72
    jne short branch_0a3e                                                       ; .text+0x0a75
    jmp short branch_0a3a                                                       ; .text+0x0a77
branch_0a79:
    lea rcx, [byte r10 + r10 + 1]                                               ; .text+0x0a79
branch_0a7e:
    lea r9, [byte rcx - 1]                                                      ; .text+0x0a7e
    cmp r9, rdx                                                                 ; .text+0x0a82
    jae short branch_0a98                                                       ; .text+0x0a85
    cmp byte [r9 + r11], strict byte 0x20                                       ; .text+0x0a87
    jbe short branch_0a98                                                       ; .text+0x0a8c
    test r8, r8                                                                 ; .text+0x0a8e
    mov rax, rcx                                                                ; .text+0x0a91
    cmove r8, rax                                                               ; .text+0x0a94
branch_0a98:
    sub rax, r8                                                                 ; .text+0x0a98
    inc rax                                                                     ; .text+0x0a9b
    ret                                                                         ; .text+0x0a9e
    nop                                                                         ; .text+0x0a9f

; Close the existing units, then repeat the file setup.
RESET_HIS_RPT_FILE:
    push rbx                                                                    ; .text+0x0aa0
    push rsi                                                                    ; .text+0x0aa1
    push rdi                                                                    ; .text+0x0aa2
    push r12                                                                    ; .text+0x0aa3
    push r13                                                                    ; .text+0x0aa5
    push r14                                                                    ; .text+0x0aa7
    push r15                                                                    ; .text+0x0aa9
    push rbp                                                                    ; .text+0x0aab
    sub rsp, 0x2f8                                                              ; .text+0x0aac
    mov r14, rdx                                                                ; .text+0x0ab3
    mov rbp, rcx                                                                ; .text+0x0ab6
    call CLOSE_HIS_RPT_FILE                                                     ; .text+0x0ab9
    mov rax, rsp                                                                ; .text+0x0abe
    lea rcx, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x0ac1
    mov edx, 0x50                                                               ; .text+0x0ac8
    mov r8, rbp                                                                 ; .text+0x0acd
    mov r9, r14                                                                 ; .text+0x0ad0
    xor r15d, r15d                                                              ; .text+0x0ad3
    mov r13, r15                                                                ; .text+0x0ad6
    lea rdi, [rel __STRLITPACK_19]                                              ; .text+0x0ad9
    mov qword [byte rax + 0x20], 0                                              ; .text+0x0ae0
    lea rsi, [rel __STRLITPACK_20]                                              ; .text+0x0ae8
    call for_cpystr                                                             ; .text+0x0aef
    lea rdx, [rel __STRLITPACK_8]                                               ; .text+0x0af4
    lea rax, [dword rsp + 0x2d8]                                                ; .text+0x0afb
    mov rbx, rax                                                                ; .text+0x0b03
    mov r15, rdx                                                                ; .text+0x0b06
    lea r12, [dword rsp + 0x2d0]                                                ; .text+0x0b09
branch_0b11:
    xor r11d, r11d                                                              ; .text+0x0b11
    mov r10, 0xffffffffffffffff                                                 ; .text+0x0b14
    xor ecx, ecx                                                                ; .text+0x0b1b
    lea rax, [rel __ImageBase]                                                  ; .text+0x0b1d
branch_0b24:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 wrt ..imagebase], 0x20 ; .text+0x0b24
    jbe short branch_0b3a                                                       ; .text+0x0b2c
    test r11, r11                                                               ; .text+0x0b2e
    lea r10, [byte rcx + rcx + 1]                                               ; .text+0x0b31
    cmove r11, r10                                                              ; .text+0x0b36
branch_0b3a:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 + 1 wrt ..imagebase], 0x20 ; .text+0x0b3a
    jbe short branch_0b50                                                       ; .text+0x0b42
    test r11, r11                                                               ; .text+0x0b44
    lea r10, [byte rcx + rcx + 2]                                               ; .text+0x0b47
    cmove r11, r10                                                              ; .text+0x0b4c
branch_0b50:
    inc rcx                                                                     ; .text+0x0b50
    cmp rcx, strict byte 0x28                                                   ; .text+0x0b53
    jb short branch_0b24                                                        ; .text+0x0b57
    sub r10, r11                                                                ; .text+0x0b59
    lea r11, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x0b5c
    mov edx, 3                                                                  ; .text+0x0b63
    lea rcx, [dword rsp + 0x90]                                                 ; .text+0x0b68
    mov r9d, 6                                                                  ; .text+0x0b70
    mov [rcx], rsi                                                              ; .text+0x0b76
    mov qword [byte rcx + 8], 1                                                 ; .text+0x0b79
    lea r8, [byte r11 + r10 + 1]                                                ; .text+0x0b81
    mov [byte rcx + 0x10], r15                                                  ; .text+0x0b86
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x0b8a
    mov [byte rcx + 0x20], rdi                                                  ; .text+0x0b92
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x0b96
    call for_concat                                                             ; .text+0x0b9e
    mov r10d, 1                                                                 ; .text+0x0ba3
    lea r11, [rel __ImageBase]                                                  ; .text+0x0ba9
branch_0bb0:
    movzx edx, byte [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0bb0
    cmp edx, strict byte 0x27                                                   ; .text+0x0bb9
    jne short branch_0c10                                                       ; .text+0x0bbc
    mov byte [dword rsp + r10 + 0x1df], 0x27                                    ; .text+0x0bbe
    inc r10                                                                     ; .text+0x0bc7
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0bca
    cmp cl, strict byte 0x27                                                    ; .text+0x0bd2
    je short branch_0bfd                                                        ; .text+0x0bd5
branch_0bd7:
    cmp r10, strict byte 0x51                                                   ; .text+0x0bd7
    je short branch_0c4c                                                        ; .text+0x0bdb
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0bdd
    mov [dword rsp + r10 + 0x1df], cl                                           ; .text+0x0be5
    inc r10                                                                     ; .text+0x0bed
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0bf0
    cmp cl, strict byte 0x27                                                    ; .text+0x0bf8
    jne short branch_0bd7                                                       ; .text+0x0bfb
branch_0bfd:
    cmp r10, strict byte 0x51                                                   ; .text+0x0bfd
    je short branch_0c4c                                                        ; .text+0x0c01
    mov [dword rsp + r10 + 0x1df], cl                                           ; .text+0x0c03
    inc r10                                                                     ; .text+0x0c0b
    jmp short branch_0c42                                                       ; .text+0x0c0e
branch_0c10:
    xor eax, eax                                                                ; .text+0x0c10
    cmp edx, strict byte 0x41                                                   ; .text+0x0c12
    setge al                                                                    ; .text+0x0c15
    xor ecx, ecx                                                                ; .text+0x0c18
    cmp edx, strict byte 0x5a                                                   ; .text+0x0c1a
    setle cl                                                                    ; .text+0x0c1d
    dec eax                                                                     ; .text+0x0c20
    dec ecx                                                                     ; .text+0x0c22
    or eax, ecx                                                                 ; .text+0x0c24
    test al, 1                                                                  ; .text+0x0c26
    je short branch_0c34                                                        ; .text+0x0c28
    mov [dword rsp + r10 + 0x1df], dl                                           ; .text+0x0c2a
    jmp short branch_0c3f                                                       ; .text+0x0c32
branch_0c34:
    add edx, strict byte 0x20                                                   ; .text+0x0c34
    mov [dword rsp + r10 + 0x1df], dl                                           ; .text+0x0c37
branch_0c3f:
    inc r10                                                                     ; .text+0x0c3f
branch_0c42:
    cmp r10, strict byte 0x51                                                   ; .text+0x0c42
    jne near branch_0bb0                                                        ; .text+0x0c46
branch_0c4c:
    lea rcx, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x0c4c
    lea rdx, [dword rsp + 0x1e0]                                                ; .text+0x0c53
    mov r8d, 0x50                                                               ; .text+0x0c5b
    call memmove                                                                ; .text+0x0c61
    mov r10, rsp                                                                ; .text+0x0c66
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0c69
    mov edx, 0x24                                                               ; .text+0x0c71
    mov r8, 0x801208384ff00                                                     ; .text+0x0c76
    lea r9, [rel __STRLITPACK_9.0.1]                                            ; .text+0x0c80
    mov qword [rcx], 0                                                          ; .text+0x0c87
    mov [dword rcx + 0x218], r12                                                ; .text+0x0c8e
    mov [byte r10 + 0x20], rbx                                                  ; .text+0x0c95
    call for_inquire                                                            ; .text+0x0c99
    test byte [dword rsp + 0x2d0], 1                                            ; .text+0x0c9e
    jne near branch_0dae                                                        ; .text+0x0ca6
    mov rcx, rsp                                                                ; .text+0x0cac
    lea r11, [dword rsp + 0x198]                                                ; .text+0x0caf
    mov edx, 0x24                                                               ; .text+0x0cb7
    mov r8, 0x801208384ff01                                                     ; .text+0x0cbc
    lea r9, [rel __STRLITPACK_10.0.1]                                           ; .text+0x0cc6
    lea r10, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                          ; .text+0x0ccd
    mov qword [dword r11 - 0xd8], 0                                             ; .text+0x0cd4
    mov [byte rcx + 0x20], r11                                                  ; .text+0x0cdf
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0ce3
    mov qword [dword rcx + 0xd8], 0x50                                          ; .text+0x0ceb
    mov [dword rcx + 0xe0], r10                                                 ; .text+0x0cf6
    mov qword [dword rcx + 0xe8], 4                                             ; .text+0x0cfd
    call for_open                                                               ; .text+0x0d08
    test eax, eax                                                               ; .text+0x0d0d
    jle near branch_0dae                                                        ; .text+0x0d0f
    mov rcx, rsp                                                                ; .text+0x0d15
    lea r11, [rel OPEN_HIS_RPT_FILE$format_pack.0.1]                            ; .text+0x0d18
    mov rdx, 0x801208384ff00                                                    ; .text+0x0d1f
    lea r8, [rel __STRLITPACK_11.0.1]                                           ; .text+0x0d29
    inc r13                                                                     ; .text+0x0d30
    lea r9, [dword rsp + 0x150]                                                 ; .text+0x0d33
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x0d3b
    mov [byte rcx + 0x20], r11                                                  ; .text+0x0d42
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0d46
    mov qword [rcx], 0                                                          ; .text+0x0d4e
    mov qword [dword rcx + 0x90], 1                                             ; .text+0x0d55
    mov [dword rcx + 0x98], r10                                                 ; .text+0x0d60
    mov [dword rcx + 0xa0], r13                                                 ; .text+0x0d67
    call for_write_int_fmt                                                      ; .text+0x0d6e
    mov edx, 2                                                                  ; .text+0x0d73
    lea rcx, [byte rsp + 0x30]                                                  ; .text+0x0d78
    lea r8, [rel OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1]                           ; .text+0x0d7d
    mov r9d, 0x50                                                               ; .text+0x0d84
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x0d8a
    mov [rcx], rbp                                                              ; .text+0x0d91
    mov [byte rcx + 8], r14                                                     ; .text+0x0d94
    mov [byte rcx + 0x10], r10                                                  ; .text+0x0d98
    mov qword [byte rcx + 0x18], 1                                              ; .text+0x0d9c
    call for_concat                                                             ; .text+0x0da4
    jmp near branch_0b11                                                        ; .text+0x0da9
branch_0dae:
    mov rax, rsp                                                                ; .text+0x0dae
    lea rcx, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x0db1
    mov edx, 0x50                                                               ; .text+0x0db8
    mov r8, rbp                                                                 ; .text+0x0dbd
    mov r9, r14                                                                 ; .text+0x0dc0
    xor r15d, r15d                                                              ; .text+0x0dc3
    mov r13, r15                                                                ; .text+0x0dc6
    lea rsi, [rel __STRLITPACK_19]                                              ; .text+0x0dc9
    mov qword [byte rax + 0x20], 0                                              ; .text+0x0dd0
    lea rbx, [rel __STRLITPACK_20]                                              ; .text+0x0dd8
    call for_cpystr                                                             ; .text+0x0ddf
    lea rdx, [rel __STRLITPACK_5]                                               ; .text+0x0de4
    lea rax, [dword rsp + 0x2e0]                                                ; .text+0x0deb
    mov r12, rax                                                                ; .text+0x0df3
    mov r15, rdx                                                                ; .text+0x0df6
    lea rdi, [dword rsp + 0x2d0]                                                ; .text+0x0df9
branch_0e01:
    xor r11d, r11d                                                              ; .text+0x0e01
    mov r10, 0xffffffffffffffff                                                 ; .text+0x0e04
    xor ecx, ecx                                                                ; .text+0x0e0b
    lea rax, [rel __ImageBase]                                                  ; .text+0x0e0d
branch_0e14:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 wrt ..imagebase], 0x20 ; .text+0x0e14
    jbe short branch_0e2a                                                       ; .text+0x0e1c
    test r11, r11                                                               ; .text+0x0e1e
    lea r10, [byte rcx + rcx + 1]                                               ; .text+0x0e21
    cmove r11, r10                                                              ; .text+0x0e26
branch_0e2a:
    cmp byte [rax + rcx*2 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 + 1 wrt ..imagebase], 0x20 ; .text+0x0e2a
    jbe short branch_0e40                                                       ; .text+0x0e32
    test r11, r11                                                               ; .text+0x0e34
    lea r10, [byte rcx + rcx + 2]                                               ; .text+0x0e37
    cmove r11, r10                                                              ; .text+0x0e3c
branch_0e40:
    inc rcx                                                                     ; .text+0x0e40
    cmp rcx, strict byte 0x28                                                   ; .text+0x0e43
    jb short branch_0e14                                                        ; .text+0x0e47
    sub r10, r11                                                                ; .text+0x0e49
    lea r11, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x0e4c
    mov edx, 3                                                                  ; .text+0x0e53
    lea rcx, [dword rsp + 0xf0]                                                 ; .text+0x0e58
    mov r9d, 6                                                                  ; .text+0x0e60
    mov [rcx], rbx                                                              ; .text+0x0e66
    mov qword [byte rcx + 8], 1                                                 ; .text+0x0e69
    lea r8, [byte r11 + r10 + 1]                                                ; .text+0x0e71
    mov [byte rcx + 0x10], r15                                                  ; .text+0x0e76
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x0e7a
    mov [byte rcx + 0x20], rsi                                                  ; .text+0x0e82
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x0e86
    call for_concat                                                             ; .text+0x0e8e
    mov r10d, 1                                                                 ; .text+0x0e93
    lea r11, [rel __ImageBase]                                                  ; .text+0x0e99
branch_0ea0:
    movzx edx, byte [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0ea0
    cmp edx, strict byte 0x27                                                   ; .text+0x0ea9
    jne short branch_0f00                                                       ; .text+0x0eac
    mov byte [dword rsp + r10 + 0x22f], 0x27                                    ; .text+0x0eae
    inc r10                                                                     ; .text+0x0eb7
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0eba
    cmp cl, strict byte 0x27                                                    ; .text+0x0ec2
    je short branch_0eed                                                        ; .text+0x0ec5
branch_0ec7:
    cmp r10, strict byte 0x51                                                   ; .text+0x0ec7
    je short branch_0f3c                                                        ; .text+0x0ecb
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0ecd
    mov [dword rsp + r10 + 0x22f], cl                                           ; .text+0x0ed5
    inc r10                                                                     ; .text+0x0edd
    mov cl, [r11 + r10 + OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x0ee0
    cmp cl, strict byte 0x27                                                    ; .text+0x0ee8
    jne short branch_0ec7                                                       ; .text+0x0eeb
branch_0eed:
    cmp r10, strict byte 0x51                                                   ; .text+0x0eed
    je short branch_0f3c                                                        ; .text+0x0ef1
    mov [dword rsp + r10 + 0x22f], cl                                           ; .text+0x0ef3
    inc r10                                                                     ; .text+0x0efb
    jmp short branch_0f32                                                       ; .text+0x0efe
branch_0f00:
    xor eax, eax                                                                ; .text+0x0f00
    cmp edx, strict byte 0x41                                                   ; .text+0x0f02
    setge al                                                                    ; .text+0x0f05
    xor ecx, ecx                                                                ; .text+0x0f08
    cmp edx, strict byte 0x5a                                                   ; .text+0x0f0a
    setle cl                                                                    ; .text+0x0f0d
    dec eax                                                                     ; .text+0x0f10
    dec ecx                                                                     ; .text+0x0f12
    or eax, ecx                                                                 ; .text+0x0f14
    test al, 1                                                                  ; .text+0x0f16
    je short branch_0f24                                                        ; .text+0x0f18
    mov [dword rsp + r10 + 0x22f], dl                                           ; .text+0x0f1a
    jmp short branch_0f2f                                                       ; .text+0x0f22
branch_0f24:
    add edx, strict byte 0x20                                                   ; .text+0x0f24
    mov [dword rsp + r10 + 0x22f], dl                                           ; .text+0x0f27
branch_0f2f:
    inc r10                                                                     ; .text+0x0f2f
branch_0f32:
    cmp r10, strict byte 0x51                                                   ; .text+0x0f32
    jne near branch_0ea0                                                        ; .text+0x0f36
branch_0f3c:
    lea rcx, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x0f3c
    lea rdx, [dword rsp + 0x230]                                                ; .text+0x0f43
    mov r8d, 0x50                                                               ; .text+0x0f4b
    call memmove                                                                ; .text+0x0f51
    mov r10, rsp                                                                ; .text+0x0f56
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0f59
    mov edx, 6                                                                  ; .text+0x0f61
    mov r8, 0x801208384ff00                                                     ; .text+0x0f66
    lea r9, [rel __STRLITPACK_12.0.1]                                           ; .text+0x0f70
    mov qword [rcx], 0                                                          ; .text+0x0f77
    mov [dword rcx + 0x220], rdi                                                ; .text+0x0f7e
    mov [byte r10 + 0x20], r12                                                  ; .text+0x0f85
    call for_inquire                                                            ; .text+0x0f89
    test byte [dword rsp + 0x2d0], 1                                            ; .text+0x0f8e
    jne near branch_109e                                                        ; .text+0x0f96
    mov rcx, rsp                                                                ; .text+0x0f9c
    lea r11, [dword rsp + 0x1b0]                                                ; .text+0x0f9f
    mov edx, 6                                                                  ; .text+0x0fa7
    mov r8, 0x801208384ff01                                                     ; .text+0x0fac
    lea r9, [rel __STRLITPACK_13.0.1]                                           ; .text+0x0fb6
    lea r10, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                          ; .text+0x0fbd
    mov qword [dword r11 - 0xf0], 0                                             ; .text+0x0fc4
    mov [byte rcx + 0x20], r11                                                  ; .text+0x0fcf
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x0fd3
    mov qword [dword rcx + 0xf0], 0x50                                          ; .text+0x0fdb
    mov [dword rcx + 0xf8], r10                                                 ; .text+0x0fe6
    mov qword [dword rcx + 0x100], 4                                            ; .text+0x0fed
    call for_open                                                               ; .text+0x0ff8
    test eax, eax                                                               ; .text+0x0ffd
    jle near branch_109e                                                        ; .text+0x0fff
    mov rcx, rsp                                                                ; .text+0x1005
    lea r11, [rel OPEN_HIS_RPT_FILE$format_pack.0.1 + 20]                       ; .text+0x1008
    mov rdx, 0x801208384ff00                                                    ; .text+0x100f
    lea r8, [rel __STRLITPACK_14.0.1]                                           ; .text+0x1019
    inc r13                                                                     ; .text+0x1020
    lea r9, [dword rsp + 0x168]                                                 ; .text+0x1023
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x102b
    mov [byte rcx + 0x20], r11                                                  ; .text+0x1032
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x1036
    mov qword [rcx], 0                                                          ; .text+0x103e
    mov qword [dword rcx + 0xa8], 1                                             ; .text+0x1045
    mov [dword rcx + 0xb0], r10                                                 ; .text+0x1050
    mov [dword rcx + 0xb8], r13                                                 ; .text+0x1057
    call for_write_int_fmt                                                      ; .text+0x105e
    mov edx, 2                                                                  ; .text+0x1063
    lea rcx, [byte rsp + 0x50]                                                  ; .text+0x1068
    lea r8, [rel OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1]                           ; .text+0x106d
    mov r9d, 0x50                                                               ; .text+0x1074
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x107a
    mov [rcx], rbp                                                              ; .text+0x1081
    mov [byte rcx + 8], r14                                                     ; .text+0x1084
    mov [byte rcx + 0x10], r10                                                  ; .text+0x1088
    mov qword [byte rcx + 0x18], 1                                              ; .text+0x108c
    call for_concat                                                             ; .text+0x1094
    jmp near branch_0e01                                                        ; .text+0x1099
branch_109e:
    mov rax, rsp                                                                ; .text+0x109e
    lea rcx, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x10a1
    mov edx, 0x50                                                               ; .text+0x10a8
    mov r8, rbp                                                                 ; .text+0x10ad
    mov r9, r14                                                                 ; .text+0x10b0
    xor r15d, r15d                                                              ; .text+0x10b3
    mov r13, r15                                                                ; .text+0x10b6
    lea rdi, [rel __STRLITPACK_19]                                              ; .text+0x10b9
    mov qword [byte rax + 0x20], 0                                              ; .text+0x10c0
    lea rsi, [rel __STRLITPACK_20]                                              ; .text+0x10c8
    call for_cpystr                                                             ; .text+0x10cf
    lea rdx, [rel __STRLITPACK_2]                                               ; .text+0x10d4
    lea rax, [dword rsp + 0x2e8]                                                ; .text+0x10db
    mov r15, rax                                                                ; .text+0x10e3
    mov rbx, rdx                                                                ; .text+0x10e6
    lea r12, [dword rsp + 0x2d0]                                                ; .text+0x10e9
branch_10f1:
    xor r9d, r9d                                                                ; .text+0x10f1
    mov r8, 0xffffffffffffffff                                                  ; .text+0x10f4
    xor ecx, ecx                                                                ; .text+0x10fb
    lea r10, [rel __ImageBase]                                                  ; .text+0x10fd
branch_1104:
    cmp byte [r10 + rcx*2 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 wrt ..imagebase], 0x20 ; .text+0x1104
    jbe short branch_111b                                                       ; .text+0x110d
    test r9, r9                                                                 ; .text+0x110f
    lea r8, [byte rcx + rcx + 1]                                                ; .text+0x1112
    cmove r9, r8                                                                ; .text+0x1117
branch_111b:
    cmp byte [r10 + rcx*2 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 + 1 wrt ..imagebase], 0x20 ; .text+0x111b
    jbe short branch_1132                                                       ; .text+0x1124
    test r9, r9                                                                 ; .text+0x1126
    lea r8, [byte rcx + rcx + 2]                                                ; .text+0x1129
    cmove r9, r8                                                                ; .text+0x112e
branch_1132:
    inc rcx                                                                     ; .text+0x1132
    cmp rcx, strict byte 0x28                                                   ; .text+0x1135
    jb short branch_1104                                                        ; .text+0x1139
    sub r8, r9                                                                  ; .text+0x113b
    lea r10, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x113e
    mov edx, 3                                                                  ; .text+0x1145
    lea rcx, [dword rsp + 0x120]                                                ; .text+0x114a
    mov r9d, 6                                                                  ; .text+0x1152
    mov [rcx], rsi                                                              ; .text+0x1158
    mov qword [byte rcx + 8], 1                                                 ; .text+0x115b
    lea r8, [byte r10 + r8 + 1]                                                 ; .text+0x1163
    mov [byte rcx + 0x10], rbx                                                  ; .text+0x1168
    mov qword [byte rcx + 0x18], 3                                              ; .text+0x116c
    mov [byte rcx + 0x20], rdi                                                  ; .text+0x1174
    mov qword [byte rcx + 0x28], 2                                              ; .text+0x1178
    call for_concat                                                             ; .text+0x1180
    mov r8d, 1                                                                  ; .text+0x1185
    lea r9, [rel __ImageBase]                                                   ; .text+0x118b
branch_1192:
    movzx r11d, byte [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x1192
    cmp r11d, strict byte 0x27                                                  ; .text+0x119b
    jne short branch_11f3                                                       ; .text+0x119f
    mov byte [dword rsp + r8 + 0x27f], 0x27                                     ; .text+0x11a1
    inc r8                                                                      ; .text+0x11aa
    mov cl, [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x11ad
    cmp cl, strict byte 0x27                                                    ; .text+0x11b5
    je short branch_11e0                                                        ; .text+0x11b8
branch_11ba:
    cmp r8, strict byte 0x51                                                    ; .text+0x11ba
    je short branch_123b                                                        ; .text+0x11be
    mov cl, [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x11c0
    mov [dword rsp + r8 + 0x27f], cl                                            ; .text+0x11c8
    inc r8                                                                      ; .text+0x11d0
    mov cl, [r9 + r8 + OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1 - 1 wrt ..imagebase] ; .text+0x11d3
    cmp cl, strict byte 0x27                                                    ; .text+0x11db
    jne short branch_11ba                                                       ; .text+0x11de
branch_11e0:
    cmp r8, strict byte 0x51                                                    ; .text+0x11e0
    je short branch_123b                                                        ; .text+0x11e4
    mov [dword rsp + r8 + 0x27f], cl                                            ; .text+0x11e6
    inc r8                                                                      ; .text+0x11ee
    jmp short branch_1231                                                       ; .text+0x11f1
branch_11f3:
    xor r10d, r10d                                                              ; .text+0x11f3
    cmp r11d, strict byte 0x41                                                  ; .text+0x11f6
    setge r10b                                                                  ; .text+0x11fa
    xor ecx, ecx                                                                ; .text+0x11fe
    cmp r11d, strict byte 0x5a                                                  ; .text+0x1200
    setle cl                                                                    ; .text+0x1204
    dec r10d                                                                    ; .text+0x1207
    dec ecx                                                                     ; .text+0x120a
    or r10d, ecx                                                                ; .text+0x120c
    test r10d, 1                                                                ; .text+0x120f
    je short branch_1222                                                        ; .text+0x1216
    mov [dword rsp + r8 + 0x27f], r11b                                          ; .text+0x1218
    jmp short branch_122e                                                       ; .text+0x1220
branch_1222:
    add r11d, strict byte 0x20                                                  ; .text+0x1222
    mov [dword rsp + r8 + 0x27f], r11b                                          ; .text+0x1226
branch_122e:
    inc r8                                                                      ; .text+0x122e
branch_1231:
    cmp r8, strict byte 0x51                                                    ; .text+0x1231
    jne near branch_1192                                                        ; .text+0x1235
branch_123b:
    lea rcx, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x123b
    lea rdx, [dword rsp + 0x280]                                                ; .text+0x1242
    mov r8d, 0x50                                                               ; .text+0x124a
    call memmove                                                                ; .text+0x1250
    mov r10, rsp                                                                ; .text+0x1255
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x1258
    mov edx, 0xe                                                                ; .text+0x1260
    mov r8, 0x801208384ff00                                                     ; .text+0x1265
    lea r9, [rel __STRLITPACK_15.0.1]                                           ; .text+0x126f
    mov qword [rcx], 0                                                          ; .text+0x1276
    mov [dword rcx + 0x228], r12                                                ; .text+0x127d
    mov [byte r10 + 0x20], r15                                                  ; .text+0x1284
    call for_inquire                                                            ; .text+0x1288
    test byte [dword rsp + 0x2d0], 1                                            ; .text+0x128d
    jne near branch_139d                                                        ; .text+0x1295
    mov rcx, rsp                                                                ; .text+0x129b
    lea r11, [dword rsp + 0x1c8]                                                ; .text+0x129e
    mov edx, 0xe                                                                ; .text+0x12a6
    mov r8, 0x801208384ff01                                                     ; .text+0x12ab
    lea r9, [rel __STRLITPACK_16.0.1]                                           ; .text+0x12b5
    lea r10, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                          ; .text+0x12bc
    mov qword [dword r11 - 0x108], 0                                            ; .text+0x12c3
    mov [byte rcx + 0x20], r11                                                  ; .text+0x12ce
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x12d2
    mov qword [dword rcx + 0x108], 0x50                                         ; .text+0x12da
    mov [dword rcx + 0x110], r10                                                ; .text+0x12e5
    mov qword [dword rcx + 0x118], 4                                            ; .text+0x12ec
    call for_open                                                               ; .text+0x12f7
    test eax, eax                                                               ; .text+0x12fc
    jle near branch_139d                                                        ; .text+0x12fe
    mov rcx, rsp                                                                ; .text+0x1304
    lea r11, [rel OPEN_HIS_RPT_FILE$format_pack.0.1 + 40]                       ; .text+0x1307
    mov rdx, 0x801208384ff00                                                    ; .text+0x130e
    lea r8, [rel __STRLITPACK_17.0.1]                                           ; .text+0x1318
    inc r13                                                                     ; .text+0x131f
    lea r9, [dword rsp + 0x180]                                                 ; .text+0x1322
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x132a
    mov [byte rcx + 0x20], r11                                                  ; .text+0x1331
    lea rcx, [dword rsp + 0xc0]                                                 ; .text+0x1335
    mov qword [rcx], 0                                                          ; .text+0x133d
    mov qword [dword rcx + 0xc0], 1                                             ; .text+0x1344
    mov [dword rcx + 0xc8], r10                                                 ; .text+0x134f
    mov [dword rcx + 0xd0], r13                                                 ; .text+0x1356
    call for_write_int_fmt                                                      ; .text+0x135d
    mov edx, 2                                                                  ; .text+0x1362
    lea rcx, [byte rsp + 0x70]                                                  ; .text+0x1367
    lea r8, [rel OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1]                           ; .text+0x136c
    mov r9d, 0x50                                                               ; .text+0x1373
    lea r10, [rel OPEN_HIS_RPT_FILE$BUFFER.0.1]                                 ; .text+0x1379
    mov [rcx], rbp                                                              ; .text+0x1380
    mov [byte rcx + 8], r14                                                     ; .text+0x1383
    mov [byte rcx + 0x10], r10                                                  ; .text+0x1387
    mov qword [byte rcx + 0x18], 1                                              ; .text+0x138b
    call for_concat                                                             ; .text+0x1393
    jmp near branch_10f1                                                        ; .text+0x1398
branch_139d:
    add rsp, 0x2f8                                                              ; .text+0x139d
    pop rbp                                                                     ; .text+0x13a4
    pop r15                                                                     ; .text+0x13a5
    pop r14                                                                     ; .text+0x13a7
    pop r13                                                                     ; .text+0x13a9
    pop r12                                                                     ; .text+0x13ab
    pop rdi                                                                     ; .text+0x13ad
    pop rsi                                                                     ; .text+0x13ae
    pop rbx                                                                     ; .text+0x13af
    ret                                                                         ; .text+0x13b0
    nop dword [dword rax + rax]                                                 ; .text+0x13b1
    nop dword [dword rax]                                                       ; .text+0x13b9

; Copy the bounded character field, lowercasing ASCII A-Z outside single quotes.
DMO_LOWER:
    mov r10, rdx                                                                ; .text+0x13c0
    cmp r10, r9                                                                 ; .text+0x13c3
    cmovl r9, r10                                                               ; .text+0x13c6
    mov edx, 1                                                                  ; .text+0x13ca
    inc r9                                                                      ; .text+0x13cf
    cmp r9, strict byte 1                                                       ; .text+0x13d2
    je near branch_1465                                                         ; .text+0x13d6
branch_13dc:
    movzx eax, byte [byte rdx + r8 - 1]                                         ; .text+0x13dc
    cmp eax, strict byte 0x27                                                   ; .text+0x13e2
    jne short branch_1426                                                       ; .text+0x13e5
    mov byte [byte rdx + rcx - 1], 0x27                                         ; .text+0x13e7
    inc rdx                                                                     ; .text+0x13ec
    mov r10b, [byte rdx + r8 - 1]                                               ; .text+0x13ef
    cmp r10b, strict byte 0x27                                                  ; .text+0x13f4
    je short branch_1417                                                        ; .text+0x13f8
branch_13fa:
    cmp rdx, r9                                                                 ; .text+0x13fa
    je short branch_1465                                                        ; .text+0x13fd
    mov r10b, [byte rdx + r8 - 1]                                               ; .text+0x13ff
    mov [byte rdx + rcx - 1], r10b                                              ; .text+0x1404
    inc rdx                                                                     ; .text+0x1409
    mov r10b, [byte rdx + r8 - 1]                                               ; .text+0x140c
    cmp r10b, strict byte 0x27                                                  ; .text+0x1411
    jne short branch_13fa                                                       ; .text+0x1415
branch_1417:
    cmp rdx, r9                                                                 ; .text+0x1417
    je short branch_1465                                                        ; .text+0x141a
    mov [byte rdx + rcx - 1], r10b                                              ; .text+0x141c
    inc rdx                                                                     ; .text+0x1421
    jmp short branch_145c                                                       ; .text+0x1424
branch_1426:
    xor r11d, r11d                                                              ; .text+0x1426
    cmp eax, strict byte 0x41                                                   ; .text+0x1429
    setge r11b                                                                  ; .text+0x142c
    xor r10d, r10d                                                              ; .text+0x1430
    cmp eax, strict byte 0x5a                                                   ; .text+0x1433
    setle r10b                                                                  ; .text+0x1436
    dec r11d                                                                    ; .text+0x143a
    dec r10d                                                                    ; .text+0x143d
    or r11d, r10d                                                               ; .text+0x1440
    test r11d, 1                                                                ; .text+0x1443
    je short branch_1452                                                        ; .text+0x144a
    mov [byte rdx + rcx - 1], al                                                ; .text+0x144c
    jmp short branch_1459                                                       ; .text+0x1450
branch_1452:
    add eax, strict byte 0x20                                                   ; .text+0x1452
    mov [byte rdx + rcx - 1], al                                                ; .text+0x1455
branch_1459:
    inc rdx                                                                     ; .text+0x1459
branch_145c:
    cmp rdx, r9                                                                 ; .text+0x145c
    jne near branch_13dc                                                        ; .text+0x145f
branch_1465:
    mov rax, rcx                                                                ; .text+0x1465
    ret                                                                         ; .text+0x1468
    nop dword [dword rax]                                                       ; .text+0x1469

section .bss bss align=32
OPEN_HIS_RPT_FILE$HIS_FILE_NAME.0.1:
section_bss:
    resb 96
OPEN_HIS_RPT_FILE$ERR_FILE_NAME.0.1:
    resb 96
OPEN_HIS_RPT_FILE$RPT_FILE_NAME.0.1:
    resb 80
OPEN_HIS_RPT_FILE$BUFFER.0.1:
    resb 16

section .rdata rdata align=4
__STRLITPACK_19:
section_rdata:
    db 0x20, 0x20, 0x00, 0x00
__STRLITPACK_8:
    db 0x48, 0x49, 0x53, 0x00
__STRLITPACK_20:
    db 0x2e, 0x00, 0x00, 0x00
__STRLITPACK_9.0.1:
    db 0x11, 0x03, 0x23, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
__STRLITPACK_10.0.1:
    db 0x38, 0x04, 0x0d, 0x00, 0x09, 0x01, 0x1a, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
__STRLITPACK_11.0.1:
    db 0x38, 0x04, 0x0b, 0x01, 0x01, 0x00, 0x1a, 0x00
__STRLITPACK_5:
    db 0x45, 0x52, 0x52, 0x00
__STRLITPACK_12.0.1:
    db 0x11, 0x03, 0x23, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
__STRLITPACK_13.0.1:
    db 0x38, 0x04, 0x0d, 0x00, 0x09, 0x01, 0x1a, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
__STRLITPACK_14.0.1:
    db 0x38, 0x04, 0x0b, 0x01, 0x01, 0x00, 0x1a, 0x00
__STRLITPACK_2:
    db 0x52, 0x50, 0x54, 0x00
__STRLITPACK_15.0.1:
    db 0x11, 0x03, 0x23, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
__STRLITPACK_16.0.1:
    db 0x38, 0x04, 0x0d, 0x00, 0x09, 0x01, 0x1a, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
__STRLITPACK_17.0.1:
    db 0x38, 0x04, 0x0b, 0x01, 0x01, 0x00, 0x1a, 0x00

section .data data align=4
OPEN_HIS_RPT_FILE$format_pack.0.1:
section_data:
    db 0x36, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    db 0x37, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    db 0x01, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00
    db 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00

section .xdata rdata align=4
section_xdata:
    db 0x01, 0x13, 0x0a, 0x00, 0x13, 0x01, 0x5f, 0x00, 0x0c, 0x50, 0x0b, 0xf0, 0x09, 0xe0, 0x07, 0xd0
    db 0x05, 0xc0, 0x03, 0x70, 0x02, 0x60, 0x01, 0x30
unwind_0018:
    db 0x01, 0x08, 0x03, 0x00, 0x08, 0x01, 0x14, 0x00, 0x01, 0x70, 0x00, 0x00
unwind_0024:
    db 0x01, 0x13, 0x0a, 0x00, 0x13, 0x01, 0x5f, 0x00, 0x0c, 0x50, 0x0b, 0xf0, 0x09, 0xe0, 0x07, 0xd0
    db 0x05, 0xc0, 0x03, 0x70, 0x02, 0x60, 0x01, 0x30

section .pdata rdata align=4
    ; RUNTIME_FUNCTION for OPEN_HIS_RPT_FILE: begin, end, unwind.
    dd OPEN_HIS_RPT_FILE wrt ..imagebase
    dd DMOFIL wrt ..imagebase
    dd section_xdata wrt ..imagebase
    ; RUNTIME_FUNCTION for DMOFIL: begin, end, unwind.
    dd DMOFIL wrt ..imagebase
    dd DMO_STRLEN wrt ..imagebase
    dd unwind_0018 wrt ..imagebase
    ; RUNTIME_FUNCTION for RESET_HIS_RPT_FILE: begin, end, unwind.
    dd RESET_HIS_RPT_FILE wrt ..imagebase
    dd DMO_LOWER wrt ..imagebase
    dd unwind_0024 wrt ..imagebase

section .drectve info align=1
    db '-defaultlib:"ifconsol" '
    db '-defaultlib:"libifcoremd" '
    db '-defaultlib:"libifportmd" '
    db '-defaultlib:"ifwin" '
    db '-defaultlib:"user32" '
    db '-defaultlib:"gdi32" '
    db '-defaultlib:"libmmd" '
    db '-defaultlib:"MSVCRT" '
    db '-defaultlib:"libirc" '
    db '-defaultlib:"svml_dispmd" '
    db '-defaultlib:"OLDNAMES" '
