; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FUNEQ1:
    push r15                                                   ; 0000
    push r14                                                   ; 0002
    push r13                                                   ; 0004
    push r12                                                   ; 0006
    push rsi                                                   ; 0008
    push rdi                                                   ; 0009
    push rbp                                                   ; 000a
    push rbx                                                   ; 000b
    sub rsp,0xe8                                               ; 000c
    cmp qword [rcx],0x0                                        ; 0013
    jng near loc_00e3                                           ; 0017
    mov qword [rcx],0xa                                        ; 001d
    mov qword [rsp+0xb8],0x0                                   ; 0024
    mov dword [rsp+0x8c],0x1010b                               ; 0030
    mov qword [rsp+0xa0],0xa                                   ; 003b
    lea rax,[rel $+119]                                        ; 0047 | REL32 +3 FUNEQ1$format_pack addendLE=70000000
    mov [rsp+0x28],rax                                         ; 004e
    lea rax,[rsp+0xa0]                                         ; 0053
    mov [rsp+0x20],rax                                         ; 005b
    lea rsi,[rsp+0xb8]                                         ; 0060
    mov rdi,0x801208384ff00                                    ; 0068
    lea r9,[rsp+0x8c]                                          ; 0072
    mov rcx,rsi                                                ; 007a
    xor edx,edx                                                ; 007d
    mov r8,rdi                                                 ; 007f
    call $+5                                                   ; 0082 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov qword [rsp+0xb8],0x0                                   ; 0087
    mov dword [rsp+0x88],0x10438                               ; 0093
    mov qword [rsp+0xa8],0x21                                  ; 009e
    lea rax,[rel $+7]                                          ; 00aa | REL32 +3 strlit.6 addendLE=00000000
    mov [rsp+0xb0],rax                                         ; 00b1
    lea rax,[rsp+0xa8]                                         ; 00b9
    mov [rsp+0x20],rax                                         ; 00c1
    lea r9,[rsp+0x88]                                          ; 00c6
    mov rcx,rsi                                                ; 00ce
    mov edx,0x7                                                ; 00d1
    mov r8,rdi                                                 ; 00d6
    call $+5                                                   ; 00d9 | REL32 +1 for_write_seq_lis addendLE=00000000
    jmp near loc_0231                                           ; 00de
loc_00e3:
    mov r11,[rsp+0x188]                                        ; 00e3
    mov r10,[rsp+0x170]                                        ; 00eb
    mov rax,[rdx]                                              ; 00f3
    mov rsi,[r11+0x18]                                         ; 00f6
    mov rdi,[r10]                                              ; 00fa
    test rax,rax                                               ; 00fd
    jng near loc_019a                                           ; 0100
    cmp rdi,rax                                                ; 0106
    jl near loc_019a                                            ; 0109
    mov rsi,[rsp+0x190]                                        ; 010f
    mov rdi,[rsp+0x180]                                        ; 0117
    mov rbx,[rsp+0x178]                                        ; 011f
    mov r14,[rsp+0x168]                                        ; 0127
    mov r15,[rsp+0x160]                                        ; 012f
    mov r12,[rsp+0x158]                                        ; 0137
    mov r13,[rsp+0x150]                                        ; 013f
    lea rbp,[rax*8+0x0]                                        ; 0147
    shl rax,byte 0x4                                           ; 014f
    add rax,rbx                                                ; 0153
    add rbp,rbx                                                ; 0156
    mov [rsp+0x70],rsi                                         ; 0159
    mov [rsp+0x68],r11                                         ; 015e
    mov [rsp+0x60],r10                                         ; 0163
    mov [rsp+0x58],r14                                         ; 0168
    mov [rsp+0x50],rbp                                         ; 016d
    mov [rsp+0x48],rbx                                         ; 0172
    mov [rsp+0x38],r13                                         ; 0177
    mov [rsp+0x30],rdi                                         ; 017c
    mov [rsp+0x28],r15                                         ; 0181
    mov [rsp+0x20],r12                                         ; 0186
    mov [rsp+0x40],rax                                         ; 018b
    call $+5                                                   ; 0190 | REL32 +1 FUNEQ2 addendLE=00000000
    jmp near loc_0231                                           ; 0195
loc_019a:
    mov qword [rcx],0x9                                        ; 019a
    test rsi,rsi                                               ; 01a1
    jz near loc_0231                                            ; 01a4
    mov qword [rsp+0xb8],0x0                                   ; 01aa
    mov dword [rsp+0x84],0x2010b                               ; 01b6
    mov [rsp+0x98],rax                                         ; 01c1
    lea rax,[rel $+7]                                          ; 01c9 | REL32 +3 FUNEQ1$format_pack addendLE=00000000
    mov [rsp+0x28],rax                                         ; 01d0
    lea rax,[rsp+0x98]                                         ; 01d5
    mov [rsp+0x20],rax                                         ; 01dd
    lea rsi,[rsp+0xb8]                                         ; 01e2
    mov r8,0x801208384ff00                                     ; 01ea
    lea r9,[rsp+0x84]                                          ; 01f4
    mov rcx,rsi                                                ; 01fc
    xor edx,edx                                                ; 01ff
    call $+5                                                   ; 0201 | REL32 +1 for_write_seq_fmt addendLE=00000000
    mov dword [rsp+0x80],0x1010b                               ; 0206
    mov [rsp+0x90],rdi                                         ; 0211
    lea rdx,[rsp+0x80]                                         ; 0219
    lea r8,[rsp+0x90]                                          ; 0221
    mov rcx,rsi                                                ; 0229
    call $+5                                                   ; 022c | REL32 +1 for_write_seq_fmt_xmit addendLE=00000000
loc_0231:
    nop                                                        ; 0231
    add rsp,0xe8                                               ; 0232
    pop rbx                                                    ; 0239
    pop rbp                                                    ; 023a
    pop rdi                                                    ; 023b
    pop rsi                                                    ; 023c
    pop r12                                                    ; 023d
    pop r13                                                    ; 023f
    pop r14                                                    ; 0241
    pop r15                                                    ; 0243
    retq                                                       ; 0245

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .data (COFF section 2)
coff_section_2:
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x2d,0x00,0x20,0x2a,0x2a,0x2a
    db 0x20,0x45,0x52,0x52,0x4f,0x52,0x20,0x46,0x52,0x4f,0x4d,0x20,0x46,0x55,0x4e,0x45
    db 0x51,0x31,0x3a,0x20,0x49,0x4e,0x56,0x41,0x4c,0x49,0x44,0x20,0x50,0x41,0x52,0x41
    db 0x4d,0x45,0x54,0x45,0x52,0x20,0x2a,0x2a,0x2a,0x00,0x00,0x00,0x1c,0x00,0x08,0x00
    db 0x20,0x20,0x20,0x20,0x20,0x4e,0x20,0x3d,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x04,0x00,0x00,0x00,0x1c,0x00,0x07,0x00,0x20,0x20,0x4c,0x44,0x42,0x20,0x3d,0x00
    db 0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x37,0x00,0x00,0x00
    db 0x36,0x00,0x00,0x00,0x47,0x00,0x01,0x00,0x1c,0x00,0x2f,0x00,0x20,0x2a,0x2a,0x2a
    db 0x20,0x45,0x58,0x45,0x43,0x55,0x54,0x49,0x4f,0x4e,0x20,0x54,0x45,0x52,0x4d,0x49
    db 0x4e,0x41,0x54,0x45,0x44,0x20,0x49,0x4e,0x20,0x52,0x4f,0x55,0x54,0x49,0x4e,0x45
    db 0x20,0x46,0x55,0x4e,0x45,0x51,0x31,0x20,0x2a,0x2a,0x2a,0x00,0x47,0x00,0x01,0x00
    db 0x1c,0x00,0x14,0x00,0x20,0x20,0x20,0x20,0x20,0x42,0x45,0x43,0x41,0x55,0x53,0x45
    db 0x20,0x49,0x46,0x4c,0x41,0x47,0x20,0x3d,0x24,0x00,0x00,0x00,0x01,0x00,0x00,0x00
    db 0x04,0x00,0x00,0x00,0x1c,0x00,0x0a,0x00,0x20,0x20,0x4f,0x4e,0x20,0x49,0x4e,0x50
    db 0x55,0x54,0x00,0x00,0x37,0x00,0x00,0x00

; .xdata (COFF section 4)
coff_section_4:
    db 0x01,0x13,0x0a,0x00,0x13,0x01,0x1d,0x00,0x0c,0x30,0x0b,0x50,0x0a,0x70,0x09,0x60
    db 0x08,0xc0,0x06,0xd0,0x04,0xe0,0x02,0xf0

; .rdata (COFF section 5)
coff_section_5:
    db 0x2a,0x2a,0x2a,0x20,0x45,0x72,0x72,0x6f,0x72,0x20,0x69,0x6e,0x20,0x66,0x75,0x6e
    db 0x65,0x71,0x31,0x20,0x6c,0x61,0x62,0x65,0x6c,0x20,0x37,0x31,0x30,0x20,0x2a,0x2a
    db 0x2a

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
    dd 0x00000246 ; ADDR32NB .text (COFF symbol 0)
    dd 0x00000000 ; ADDR32NB .xdata (COFF symbol 6)
