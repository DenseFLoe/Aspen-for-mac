; Windows AMD64 COFF section payloads; exact original layout and relocations are retained.
; Offsets and relocation annotations refer to the original COFF member.
bits 64
org 0

FU2NRM:
    movsd xmm1,qword [rel $+8]                                 ; 0000 | REL32 +4 __real@4008000000000000 addendLE=00000000
    movsd xmm0,qword [rel $+8]                                 ; 0008 | REL32 +4 __real@4000000000000000 addendLE=00000000
    divsd xmm0,xmm1                                            ; 0010
    movsd xmm2,qword [rel $+8]                                 ; 0014 | REL32 +4 __real@3fe0000000000000 addendLE=00000000
    subsd xmm0,xmm2                                            ; 001c
    mulsd xmm0,xmm1                                            ; 0020
    subsd xmm0,xmm2                                            ; 0024
    mov rax,[rcx]                                              ; 0028
    test rax,rax                                               ; 002b
    jng near loc_00c5                                           ; 002e
    andpd xmm0,[rel $+8]                                       ; 0034 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    xorpd xmm1,xmm1                                            ; 003c
    xor ecx,ecx                                                ; 0040
    movapd xmm2,oword [rel $+8]                                ; 0042 | REL32 +4 __xmm@7fffffffffffffff7fffffffffffffff addendLE=00000000
    nop word [byte rax+rax+0x0]                                ; 004a
loc_0050:
    movapd xmm3,xmm1                                           ; 0050
    movsd xmm1,qword [rdx+rcx*8]                               ; 0054
    andpd xmm1,xmm2                                            ; 0059
    maxsd xmm1,xmm3                                            ; 005d
    inc rcx                                                    ; 0061
    cmp rax,rcx                                                ; 0064
    jnz short loc_0050                                          ; 0067
    xorpd xmm3,xmm3                                            ; 0069
    ucomisd xmm1,xmm3                                          ; 006d
    setpo cl                                                   ; 0071
    setz r8b                                                   ; 0074
    test r8b,cl                                                ; 0078
    jnz short loc_00cd                                          ; 007b
    movsd xmm4,qword [rel $+8]                                 ; 007d | REL32 +4 __real@3ff0000000000000 addendLE=00000000
    divsd xmm4,xmm1                                            ; 0085
    mulsd xmm0,xmm1                                            ; 0089
    xor ecx,ecx                                                ; 008d
    jmp short loc_00a8                                          ; 008f
    db 0x66,0x66,0x66,0x66,0x66,0x66,0x2e,0x0f,0x1f,0x84,0x00,0x00,0x00,0x00,0x00 ; 0091 | nop word [cs:rax+rax+0x0]
loc_00a0:
    inc rcx                                                    ; 00a0
    cmp rax,rcx                                                ; 00a3
    jz short loc_00cd                                           ; 00a6
loc_00a8:
    movsd xmm5,qword [rdx+rcx*8]                               ; 00a8
    andpd xmm5,xmm2                                            ; 00ad
    ucomisd xmm5,xmm0                                          ; 00b1
    jna short loc_00a0                                          ; 00b5
    mulsd xmm5,xmm4                                            ; 00b7
    mulsd xmm5,xmm5                                            ; 00bb
    addsd xmm3,xmm5                                            ; 00bf
    jmp short loc_00a0                                          ; 00c3
loc_00c5:
    xorpd xmm1,xmm1                                            ; 00c5
    xorpd xmm3,xmm3                                            ; 00c9
loc_00cd:
    xorps xmm0,xmm0                                            ; 00cd
    sqrtsd xmm0,xmm3                                           ; 00d0
    mulsd xmm0,xmm1                                            ; 00d4
    retq                                                       ; 00d8

; Initialized non-code sections. Boundaries are fixed by archive-layout.json.

; .rdata (COFF section 4)
coff_section_4:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x40

; .rdata (COFF section 5)
coff_section_5:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40

; .rdata (COFF section 6)
coff_section_6:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x3f

; .rdata (COFF section 7)
coff_section_7:
    db 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f

; .rdata (COFF section 8)
coff_section_8:
    db 0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f

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
