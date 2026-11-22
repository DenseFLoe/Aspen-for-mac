; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ9:
    push r14                                                   ; 0000
    push rsi                                                   ; 0002
    push rdi                                                   ; 0003
    push rbx                                                   ; 0004
    mov r11,[rsp+0x48]                                         ; 0005
    mov rax,[rcx]                                              ; 000a
    cmp rax,0x2                                                ; 000d
    jl short loc_0081                                           ; 0011
    mov rcx,[rsp+0x50]                                         ; 0013
    mov r10,[rsp+0x58]                                         ; 0018
    mov r10,[r10]                                              ; 001d
    shl r10,byte 0x3                                           ; 0020
    mov rdx,[rdx]                                              ; 0024
    mov r8,[r8]                                                ; 0027
    cmp rdx,0x1                                                ; 002a
    jnz short loc_0097                                          ; 002e
    cmp r8,0x1                                                 ; 0030
    jnz short loc_0097                                          ; 0034
    mov edx,0x1                                                ; 0036
    nop dword [byte rax+rax+0x0]                               ; 003b
loc_0040:
    movsd xmm0,qword [r9+rdx*8-0x8]                            ; 0040
    mov r8,rcx                                                 ; 0047
    xor esi,esi                                                ; 004a
    nop dword [byte rax+0x0]                                   ; 004c
loc_0050:
    movsd xmm1,qword [r8]                                      ; 0050
    divsd xmm1,[r11+rsi*8]                                     ; 0055
    mulsd xmm1,xmm0                                            ; 005b
    movsd qword [r8],xmm1                                      ; 005f
    inc rsi                                                    ; 0064
    add r8,r10                                                 ; 0067
    cmp rax,rsi                                                ; 006a
    jnz short loc_0050                                          ; 006d
    lea r8,[rdx+0x1]                                           ; 006f
    add rcx,0x8                                                ; 0073
    cmp rdx,rax                                                ; 0077
    mov rdx,r8                                                 ; 007a
    jnz short loc_0040                                          ; 007d
    jmp short loc_0091                                          ; 007f
loc_0081:
    mov rax,0x3ff0000000000000                                 ; 0081
    mov [r9],rax                                               ; 008b
    mov [r11],rax                                              ; 008e
loc_0091:
    pop rbx                                                    ; 0091
    pop rdi                                                    ; 0092
    pop rsi                                                    ; 0093
    pop r14                                                    ; 0094
    retq                                                       ; 0096
loc_0097:
    cmp rdx,0x1                                                ; 0097
    jnz short loc_00e4                                          ; 009b
    mov edi,0x1                                                ; 009d
    mov rsi,rcx                                                ; 00a2
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 00a5 | nop word [cs:rax+rax+0x0]
loc_00b0:
    movsd xmm0,qword [r9+rdi*8-0x8]                            ; 00b0
    mov rbx,rsi                                                ; 00b7
    mov r14,rax                                                ; 00ba
    nop dword [rax]                                            ; 00bd
loc_00c0:
    movsd xmm1,qword [rbx]                                     ; 00c0
    mulsd xmm1,xmm0                                            ; 00c4
    movsd qword [rbx],xmm1                                     ; 00c8
    add rbx,r10                                                ; 00cc
    dec r14                                                    ; 00cf
    jnz short loc_00c0                                          ; 00d2
    lea rbx,[rdi+0x1]                                          ; 00d4
    add rsi,0x8                                                ; 00d8
    cmp rdi,rax                                                ; 00dc
    mov rdi,rbx                                                ; 00df
    jnz short loc_00b0                                          ; 00e2
loc_00e4:
    cmp r8,0x2                                                 ; 00e4
    jnz near loc_0171                                           ; 00e8
    mov r8d,0x1                                                ; 00ee
    movapd xmm0,oword [rel $+8]                                ; 00f4 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xorpd xmm1,xmm1                                            ; 00fc
    movsd xmm2,qword [rel $+8]                                 ; 0100 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    movsd xmm3,qword [rel $+8]                                 ; 0108 | REL32 +4 __real@3e45798ee2308c3a addendLE=00000000
    mov rsi,rcx                                                ; 0110
    jmp short loc_0136                                          ; 0113
    db 0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00  ; 0115 | nop word [cs:rax+rax+0x0]
loc_0120:
    movsd qword [r11+r8*8-0x8],xmm5                            ; 0120
    lea rdi,[r8+0x1]                                           ; 0127
    add rsi,r10                                                ; 012b
    cmp r8,rax                                                 ; 012e
    mov r8,rdi                                                 ; 0131
    jz short loc_0171                                           ; 0134
loc_0136:
    xor edi,edi                                                ; 0136
    xorpd xmm4,xmm4                                            ; 0138
    nop dword [byte rax+0x0]                                   ; 013c
loc_0140:
    movsd xmm5,qword [rsi+rdi*8]                               ; 0140
    andpd xmm5,xmm0                                            ; 0145
    maxsd xmm4,xmm5                                            ; 0149
    inc rdi                                                    ; 014d
    cmp rax,rdi                                                ; 0150
    jnz short loc_0140                                          ; 0153
    ucomisd xmm4,xmm1                                          ; 0155
    jnz short loc_0161                                          ; 0159
    jpe short loc_0161                                          ; 015b
    movapd xmm4,xmm2                                           ; 015d
loc_0161:
    ucomisd xmm3,xmm4                                          ; 0161
    movapd xmm5,xmm3                                           ; 0165
    ja short loc_0120                                           ; 0169
    movapd xmm5,xmm4                                           ; 016b
    jmp short loc_0120                                          ; 016f
loc_0171:
    mov esi,0x1                                                ; 0171
    mov r8,rcx                                                 ; 0176
    nop dword [dword rax+0x0]                                  ; 0179
loc_0180:
    movsd xmm0,qword [r11+rsi*8-0x8]                           ; 0180
    xor edi,edi                                                ; 0187
    nop dword [dword rax+0x0]                                  ; 0189
loc_0190:
    movsd xmm1,qword [r8+rdi*8]                                ; 0190
    divsd xmm1,xmm0                                            ; 0196
    movsd qword [r8+rdi*8],xmm1                                ; 019a
    inc rdi                                                    ; 01a0
    cmp rax,rdi                                                ; 01a3
    jnz short loc_0190                                          ; 01a6
    lea rdi,[rsi+0x1]                                          ; 01a8
    add r8,r10                                                 ; 01ac
    cmp rsi,rax                                                ; 01af
    mov rsi,rdi                                                ; 01b2
    jnz short loc_0180                                          ; 01b5
    cmp rdx,0x2                                                ; 01b7
    jnz near loc_0091                                           ; 01bb
    mov edx,0x1                                                ; 01c1
    movapd xmm0,oword [rel $+8]                                ; 01c6 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xorpd xmm1,xmm1                                            ; 01ce
    movsd xmm2,qword [rel $+8]                                 ; 01d2 | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    mov r8,rcx                                                 ; 01da
    jmp short loc_01ff                                          ; 01dd
    nop                                                        ; 01df
loc_01e0:
    movapd xmm4,xmm2                                           ; 01e0
    divsd xmm4,xmm3                                            ; 01e4
    movsd qword [r9+rdx*8-0x8],xmm4                            ; 01e8
    lea r11,[rdx+0x1]                                          ; 01ef
    add r8,0x8                                                 ; 01f3
    cmp rdx,rax                                                ; 01f7
    mov rdx,r11                                                ; 01fa
    jz short loc_0233                                           ; 01fd
loc_01ff:
    mov r11,r8                                                 ; 01ff
    mov rsi,rax                                                ; 0202
    xorpd xmm3,xmm3                                            ; 0205
    nop dword [dword rax+0x0]                                  ; 0209
loc_0210:
    movsd xmm4,qword [r11]                                     ; 0210
    andpd xmm4,xmm0                                            ; 0215
    maxsd xmm3,xmm4                                            ; 0219
    add r11,r10                                                ; 021d
    dec rsi                                                    ; 0220
    jnz short loc_0210                                          ; 0223
    ucomisd xmm3,xmm1                                          ; 0225
    jnz short loc_01e0                                          ; 0229
    jpe short loc_01e0                                          ; 022b
    movapd xmm3,xmm2                                           ; 022d
    jmp short loc_01e0                                          ; 0231
loc_0233:
    mov edx,0x1                                                ; 0233
    nop dword [dword rax+rax+0x0]                              ; 0238
loc_0240:
    movsd xmm0,qword [r9+rdx*8-0x8]                            ; 0240
    mov r8,rcx                                                 ; 0247
    mov r11,rax                                                ; 024a
    nop dword [rax]                                            ; 024d
loc_0250:
    movsd xmm1,qword [r8]                                      ; 0250
    mulsd xmm1,xmm0                                            ; 0255
    movsd qword [r8],xmm1                                      ; 0259
    add r8,r10                                                 ; 025e
    dec r11                                                    ; 0261
    jnz short loc_0250                                          ; 0264
    lea r8,[rdx+0x1]                                           ; 0266
    add rcx,0x8                                                ; 026a
    cmp rdx,rax                                                ; 026e
    mov rdx,r8                                                 ; 0271
    jnz short loc_0240                                          ; 0274
    jmp near loc_0091                                           ; 0276

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .rdata (COFF section 4)
coff_section_4:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f

; .rdata (COFF section 5)
coff_section_5:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

; .rdata (COFF section 6)
coff_section_6:
    db 0x3a,0x8c,0x30,0xe2,0x8e,0x79,0x45,0x3e

; .xdata (COFF section 7)
coff_section_7:
    db 0x01,0x05,0x04,0x00,0x05,0x30,0x04,0x70,0x03,0x60,0x02,0xe0

; .drectve (COFF section 8)
coff_section_8:
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

; .pdata (COFF section 9)
coff_section_9:
    dd 0x00000000 ; ADDR32NB .text (COFF symbol 0)
    dd 0x0000027b ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 15)
