; oomfutilslib.lib | OOMF V15.0 | AMD64 Windows COFF
; Intel syntax, one object per .member, in library search order.
; reloc(symbol, addend) retains the original COFF symbol identity.
; Local jumps, function ends and unwind sites use labels.
; short/long and modrm are AsmTK encoding choices.
; .symbol declarations retain COFF storage class, type and record order.
; .index lists the symbols actually offered by this archive member.
.archive 1743626484


; ====================================================================
.member x64\Release\xfile.obj 1743626483
.index RTO_CLOSE_XFILE_F
.index RTO_FLUSH_XFILE_F
.index RTO_LOADBUF_XFILE_F
.index RTO_OPENRD_XFILE_F
.index RTO_OPENUP_XFILE_F
.index RTO_OPENWR_XFILE_F
.index RTO_READ_XFILE_F
.index RTO_READ_XHDR_F
.index RTO_READ_XREC_F
.index RTO_RECLEN_XFILE_F
.index RTO_UNLOADBUF_XFILE_F
.index RTO_UPDATEBUF_XFILE_F
.index RTO_UPDATE_XFILE_F
.index RTO_UPDATE_XHDR_F
.index RTO_WRITE_XFILE_F
.index RTO_WRITE_XHDR_F
.index XFILE_COMMON
.index XFILE_COMMON2

.symbol .text section local
.symbol RTO_RECLEN_XFILE_F function public
.symbol RTO_OPENRD_XFILE_F function public
.symbol RTO_OPENWR_XFILE_F function public
.symbol RTO_OPENUP_XFILE_F function public
.symbol RTO_READ_XHDR_F function public
.symbol RTO_WRITE_XHDR_F function public
.symbol RTO_UPDATE_XHDR_F function public
.symbol RTO_READ_XREC_F function public
.symbol RTO_READ_XFILE_F function public
.symbol RTO_LOADBUF_XFILE_F function public
.symbol RTO_WRITE_XFILE_F function public
.symbol RTO_FLUSH_XFILE_F function public
.symbol RTO_UNLOADBUF_XFILE_F function public
.symbol RTO_UPDATE_XFILE_F function public
.symbol RTO_UPDATEBUF_XFILE_F function public
.symbol RTO_CLOSE_XFILE_F function public
.symbol .xdata section local
.symbol .pdata section local
.symbol .rdata section local
.symbol __STRLITPACK_2 data local
.symbol __STRLITPACK_1 data local
.symbol __STRLITPACK_0 data local
.symbol XFILE_COMMON common public 2112
.symbol for_open external public function
.symbol __NLITPACK_0 data local
.symbol __STRLITPACK_3 data local
.symbol __STRLITPACK_6 data local
.symbol __STRLITPACK_5 data local
.symbol __STRLITPACK_4 data local
.symbol __NLITPACK_1 data local
.symbol __STRLITPACK_7 data local
.symbol __STRLITPACK_10 data local
.symbol __STRLITPACK_9 data local
.symbol __STRLITPACK_8 data local
.symbol __NLITPACK_2 data local
.symbol __STRLITPACK_11 data local
.symbol for_read_dir external public function
.symbol .data section local
.symbol __STRLITPACK_12 data local
.symbol for_write_dir external public function
.symbol __STRLITPACK_13 data local
.symbol __STRLITPACK_14 data local
.symbol __STRLITPACK_15 data local
.symbol __STRLITPACK_16 data local
.symbol memcpy external public function
.symbol __STRLITPACK_17 data local
.symbol __STRLITPACK_18 data local
.symbol __STRLITPACK_19 data local
.symbol __STRLITPACK_20 data local
.symbol __STRLITPACK_21 data local
.symbol __STRLITPACK_22 data local
.symbol __STRLITPACK_23 data local
.symbol for_close external public function
.symbol __STRLITPACK_24 data local
.symbol .bss section local
.symbol XFILE_COMMON2 data public
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

RTO_RECLEN_XFILE_F:
    push rbp
pro_RTO_RECLEN_XFILE_F_01:
    sub rsp, 0x20
pro_RTO_RECLEN_XFILE_F_05:
    lea rbp, [rsp + 0x20]
pro_RTO_RECLEN_XFILE_F_0a:
    mov qword ptr [rbp + 0x10], rcx
    mov qword ptr [rbp + 0x18], rdx
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x18]
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    lea rsp, [rbp]
    pop rbp
    ret
end_RTO_RECLEN_XFILE_F:

RTO_OPENRD_XFILE_F:
    push rbp
pro_RTO_OPENRD_XFILE_F_01:
    sub rsp, 0xf0
pro_RTO_OPENRD_XFILE_F_08:
    lea rbp, [rsp + 0x40]
pro_RTO_OPENRD_XFILE_F_0d:
    mov qword ptr [rbp + 0xa8], rsi
pro_RTO_OPENRD_XFILE_F_14:
    mov qword ptr [rbp + 0xa0], rbx
pro_RTO_OPENRD_XFILE_F_1b:
    mov qword ptr [rbp + 0xc0], rcx
    mov qword ptr [rbp + 0xc8], rdx
    mov qword ptr [rbp + 0xd0], r8
    mov qword ptr [rbp + 0xd8], r9
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x20)], 0xffffffffffffffff
    lea rax, [rip + reloc(.rdata, __NLITPACK_0 - .rdata)]
    lea rdx, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_RECLEN_XFILE_F)
    mov rax, qword ptr [rbp + 0x100]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 0
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0x50], rax
    mov qword ptr [rbp + 0x58], 3
    lea rax, [rip + reloc(.rdata, __STRLITPACK_2 - .rdata)]
    mov qword ptr [rbp + 0x60], rax
    mov qword ptr [rbp + 0x68], 6
    lea rax, [rip + reloc(.rdata, __STRLITPACK_1 - .rdata)]
    mov qword ptr [rbp + 0x70], rax
    mov qword ptr [rbp + 0x78], 0xb
    lea rax, [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0xc0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x90], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x90]
    mov r8, rax
    mov r9, rbx
    call reloc(for_open)
    mov dword ptr [rbp], eax
    mov eax, dword ptr [rbp]
    mov dword ptr [rbp + 4], eax
    mov eax, dword ptr [rbp + 4]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0xf8]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0xf8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_01af
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0xd0]
    mov rcx, qword ptr [rbp + 0xd8]
    mov rbx, qword ptr [rbp + 0xe0]
    mov rsi, qword ptr [rbp + 0xe8]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rbp + 0xf0]
    mov qword ptr [rsp + 0x28], rsi
    mov rsi, qword ptr [rbp + 0xf8]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0x98], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x98]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XHDR_F)
L_01af:
    mov rax, qword ptr [rbp + 0xf8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_01c9
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x20)], 0
L_01c9:
    mov rbx, qword ptr [rbp + 0xa0]
    mov rsi, qword ptr [rbp + 0xa8]
    lea rsp, [rbp + 0xb0]
    pop rbp
    ret
end_RTO_OPENRD_XFILE_F:

RTO_OPENWR_XFILE_F:
    push rbp
pro_RTO_OPENWR_XFILE_F_01:
    sub rsp, 0xe0
pro_RTO_OPENWR_XFILE_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_OPENWR_XFILE_F_0d:
    mov qword ptr [rbp + 0xa8], rsi
pro_RTO_OPENWR_XFILE_F_14:
    mov qword ptr [rbp + 0xa0], rbx
pro_RTO_OPENWR_XFILE_F_1b:
    mov qword ptr [rbp + 0xc0], rcx
    mov qword ptr [rbp + 0xc8], rdx
    mov qword ptr [rbp + 0xd0], r8
    mov qword ptr [rbp + 0xd8], r9
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x20)], 0xffffffffffffffff
    lea rax, [rip + reloc(.rdata, __NLITPACK_1 - .rdata)]
    lea rdx, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_RECLEN_XFILE_F)
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 0
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0x50], rax
    mov qword ptr [rbp + 0x58], 7
    lea rax, [rip + reloc(.rdata, __STRLITPACK_6 - .rdata)]
    mov qword ptr [rbp + 0x60], rax
    mov qword ptr [rbp + 0x68], 6
    lea rax, [rip + reloc(.rdata, __STRLITPACK_5 - .rdata)]
    mov qword ptr [rbp + 0x70], rax
    mov qword ptr [rbp + 0x78], 0xb
    lea rax, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0xc0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x90], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x90]
    mov r8, rax
    mov r9, rbx
    call reloc(for_open)
    mov dword ptr [rbp], eax
    mov eax, dword ptr [rbp]
    mov dword ptr [rbp + 4], eax
    mov eax, dword ptr [rbp + 4]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0xe8]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0351
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0xd0]
    mov rcx, qword ptr [rbp + 0xd8]
    mov rbx, qword ptr [rbp + 0xe0]
    mov rsi, qword ptr [rbp + 0xe8]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x98], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x98]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_WRITE_XHDR_F)
L_0351:
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_036b
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x20)], 1
L_036b:
    mov rbx, qword ptr [rbp + 0xa0]
    mov rsi, qword ptr [rbp + 0xa8]
    lea rsp, [rbp + 0xb0]
    pop rbp
    ret
end_RTO_OPENWR_XFILE_F:

RTO_OPENUP_XFILE_F:
    push rbp
pro_RTO_OPENUP_XFILE_F_01:
    sub rsp, 0x100
pro_RTO_OPENUP_XFILE_F_08:
    lea rbp, [rsp + 0x40]
pro_RTO_OPENUP_XFILE_F_0d:
    mov qword ptr [rbp + 0xb0], rsi
pro_RTO_OPENUP_XFILE_F_14:
    mov qword ptr [rbp + 0xa8], rbx
pro_RTO_OPENUP_XFILE_F_1b:
    mov qword ptr [rbp + 0xd0], rcx
    mov qword ptr [rbp + 0xd8], rdx
    mov qword ptr [rbp + 0xe0], r8
    mov qword ptr [rbp + 0xe8], r9
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x20)], 0xffffffffffffffff
    lea rax, [rip + reloc(.rdata, __NLITPACK_2 - .rdata)]
    lea rdx, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_RECLEN_XFILE_F)
    mov rax, qword ptr [rbp + 0x110]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 0
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0xd8]
    mov qword ptr [rbp + 0x50], rax
    mov qword ptr [rbp + 0x58], 3
    lea rax, [rip + reloc(.rdata, __STRLITPACK_10 - .rdata)]
    mov qword ptr [rbp + 0x60], rax
    mov qword ptr [rbp + 0x68], 6
    lea rax, [rip + reloc(.rdata, __STRLITPACK_9 - .rdata)]
    mov qword ptr [rbp + 0x70], rax
    mov qword ptr [rbp + 0x78], 0xb
    lea rax, [rip + reloc(.rdata, __STRLITPACK_8 - .rdata)]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0xd0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_11 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x90], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x90]
    mov r8, rax
    mov r9, rbx
    call reloc(for_open)
    mov dword ptr [rbp], eax
    mov eax, dword ptr [rbp]
    mov dword ptr [rbp + 4], eax
    mov eax, dword ptr [rbp + 4]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x108]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    test rax, rax
    long jne L_058d
    mov rax, qword ptr [rbp + 0xd0]
    mov rdx, qword ptr [rbp + 0xe0]
    mov rcx, qword ptr [rbp + 0xe8]
    mov rbx, qword ptr [rbp + 0xf0]
    mov rsi, qword ptr [rbp + 0xf8]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rbp + 0x100]
    mov qword ptr [rsp + 0x28], rsi
    mov rsi, qword ptr [rbp + 0x108]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0x98], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x98]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XHDR_F)
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    test rax, rax
    long jne L_05bd
    mov rax, qword ptr [rbp + 0xd0]
    mov rdx, qword ptr [rbp + 0xe0]
    mov rcx, qword ptr [rbp + 0xe8]
    mov rbx, qword ptr [rbp + 0xf0]
    mov rsi, qword ptr [rbp + 0xf8]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rbp + 0x100]
    mov qword ptr [rsp + 0x28], rsi
    mov rsi, qword ptr [rbp + 0x108]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0xa0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa0]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_UPDATE_XHDR_F)
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_05bd
L_058d:
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_05bd
    mov qword ptr [rip + reloc(XFILE_COMMON)], 1
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 0x200
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x20)], 2
L_05bd:
    mov rbx, qword ptr [rbp + 0xa8]
    mov rsi, qword ptr [rbp + 0xb0]
    lea rsp, [rbp + 0xc0]
    pop rbp
    ret
end_RTO_OPENUP_XFILE_F:

RTO_READ_XHDR_F:
    ; Set up the 2048-byte direct-read buffer and descriptor; expand the first signed 32-bit header value to a 64-bit output.
    push rbp
pro_RTO_READ_XHDR_F_01:
    sub rsp, 0x8d0
pro_RTO_READ_XHDR_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_READ_XHDR_F_0d:
    mov qword ptr [rbp + 0x78], rsi
pro_RTO_READ_XHDR_F_11:
    mov qword ptr [rbp + 0x70], rbx
pro_RTO_READ_XHDR_F_15:
    mov qword ptr [rbp], r13
pro_RTO_READ_XHDR_F_19:
    lea r13, [rbp + 0x9f]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0x8b0], rcx
    mov qword ptr [rbp + 0x8b8], rdx
    mov qword ptr [rbp + 0x8c0], r8
    mov qword ptr [rbp + 0x8c8], r9
    mov qword ptr [rbp + 0x10], 0
    mov qword ptr [rbp + 0x40], 0x800
    lea rax, [r13]
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x8b0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_12 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rsp + 0x28], 1
    mov qword ptr [rbp + 0x68], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x68]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_dir)
    mov eax, dword ptr [r13]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x8b8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x50], 1
L_068f:
    lea rax, [r13 + 0x10]
    mov rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov eax, dword ptr [rax]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x8c0]
    add rdx, -8
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    cmp rax, 0x10
    short jle L_068f
    mov eax, dword ptr [r13 + 0x50]
    movsxd rax, eax
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x60], rax
    mov qword ptr [rbp + 0x50], 1
    mov rax, qword ptr [rbp + 0x60]
    test rax, rax
    short jle L_0745
L_06f8:
    lea rax, [r13]
    mov edx, 0x15
    add rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov eax, dword ptr [rax]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x8c8]
    add rdx, -8
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x60]
    modrm cmp rax, rdx
    short jle L_06f8
L_0745:
    mov eax, 1
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x50], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x58]
    cmp rax, 0x19
    short jg L_0792
L_0761:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x8c8]
    add rax, -8
    mov qword ptr [rax], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    cmp rax, 0x19
    short jle L_0761
L_0792:
    lea rax, [r13]
    mov edx, 0x16
    add rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov eax, dword ptr [rax]
    movsxd rax, eax
    mov qword ptr [rip + reloc(XFILE_COMMON2)], rax
    mov rax, qword ptr [rip + reloc(XFILE_COMMON2)]
    cmp rax, 0x7d4
    short je L_07eb
    mov eax, 0x30
    add rax, qword ptr [rbp + 0x8c8]
    mov qword ptr [rax], 0
    mov eax, 8
    add rax, qword ptr [rbp + 0x8c8]
    mov qword ptr [rax], 0
L_07eb:
    mov eax, dword ptr [r13 + 4]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x8d0]
    mov qword ptr [rdx], rax
    mov eax, dword ptr [r13 + 8]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x8d8]
    mov qword ptr [rdx], rax
    mov qword ptr [rip + reloc(XFILE_COMMON)], 1
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 0x200
    mov rax, qword ptr [rbp + 0x8e0]
    mov qword ptr [rax], 0
    mov r13, qword ptr [rbp]
    mov rbx, qword ptr [rbp + 0x70]
    mov rsi, qword ptr [rbp + 0x78]
    lea rsp, [rbp + 0x8a0]
    pop rbp
    ret
end_RTO_READ_XHDR_F:

RTO_WRITE_XHDR_F:
    push rbp
pro_RTO_WRITE_XHDR_F_01:
    sub rsp, 0x8c0
pro_RTO_WRITE_XHDR_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_WRITE_XHDR_F_0d:
    mov qword ptr [rbp + 0x68], rsi
pro_RTO_WRITE_XHDR_F_11:
    mov qword ptr [rbp + 0x60], rbx
pro_RTO_WRITE_XHDR_F_15:
    mov qword ptr [rbp], r13
pro_RTO_WRITE_XHDR_F_19:
    lea r13, [rbp + 0x8f]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0x8a0], rcx
    mov qword ptr [rbp + 0x8a8], rdx
    mov qword ptr [rbp + 0x8b0], r8
    mov qword ptr [rbp + 0x8b8], r9
    mov qword ptr [rip + reloc(XFILE_COMMON2)], 0x7d4
    mov rax, qword ptr [rbp + 0x8a8]
    mov eax, dword ptr [rax]
    mov dword ptr [r13], eax
    mov dword ptr [r13 + 0xc], 0x20
    mov qword ptr [rbp + 0x10], 1
L_08b2:
    mov rax, qword ptr [rbp + 0x10]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x8b0]
    add rax, -8
    mov eax, dword ptr [rax]
    lea rdx, [r13 + 0x10]
    mov rcx, qword ptr [rbp + 0x10]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 0x10
    short jle L_08b2
    mov dword ptr [r13 + 0x50], 0x19
    mov qword ptr [rbp + 0x10], 1
L_0903:
    mov rax, qword ptr [rbp + 0x10]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x8b8]
    add rax, -8
    mov eax, dword ptr [rax]
    lea rdx, [r13 + 0x54]
    mov rcx, qword ptr [rbp + 0x10]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 0x19
    short jle L_0903
    mov eax, dword ptr [rip + reloc(XFILE_COMMON2)]
    mov dword ptr [r13 + 0xb8], eax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x48], 0x800
    lea rax, [r13]
    mov qword ptr [rbp + 0x50], rax
    lea rax, [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x8a0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_13 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rsp + 0x28], 1
    mov qword ptr [rbp + 0x58], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x58]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_dir)
    mov qword ptr [rbp + 0x10], 1
L_09b7:
    mov rax, qword ptr [rbp + 0x10]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov dword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 0x200
    short jle L_09b7
    mov qword ptr [rip + reloc(XFILE_COMMON)], 2
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 0
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x10)], 0xffffffffffffffff
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x18)], 0xffffffffffffffff
    mov rax, qword ptr [rbp + 0x8c0]
    mov qword ptr [rax], 0
    mov r13, qword ptr [rbp]
    mov rbx, qword ptr [rbp + 0x60]
    mov rsi, qword ptr [rbp + 0x68]
    lea rsp, [rbp + 0x890]
    pop rbp
    ret
end_RTO_WRITE_XHDR_F:

RTO_UPDATE_XHDR_F:
    push rbp
pro_RTO_UPDATE_XHDR_F_01:
    sub rsp, 0x8e0
pro_RTO_UPDATE_XHDR_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_UPDATE_XHDR_F_0d:
    mov qword ptr [rbp + 0x80], rsi
pro_RTO_UPDATE_XHDR_F_14:
    mov qword ptr [rbp + 0x78], rbx
pro_RTO_UPDATE_XHDR_F_18:
    mov qword ptr [rbp], r13
pro_RTO_UPDATE_XHDR_F_1c:
    lea r13, [rbp + 0xaf]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0x8c0], rcx
    mov qword ptr [rbp + 0x8c8], rdx
    mov qword ptr [rbp + 0x8d0], r8
    mov qword ptr [rbp + 0x8d8], r9
    mov qword ptr [rip + reloc(XFILE_COMMON2)], 0x7d4
    mov qword ptr [rbp + 0x10], 0
    mov qword ptr [rbp + 0x40], 0x800
    lea rax, [r13]
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x8c0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_14 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rsp + 0x28], 1
    mov qword ptr [rbp + 0x68], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x68]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_dir)
    mov rax, qword ptr [rbp + 0x8c8]
    mov eax, dword ptr [rax]
    mov dword ptr [r13], eax
    mov qword ptr [rbp + 0x50], 1
L_0b04:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x8d0]
    add rax, -8
    mov eax, dword ptr [rax]
    lea rdx, [r13 + 0x10]
    mov rcx, qword ptr [rbp + 0x50]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    cmp rax, 0x10
    short jle L_0b04
    mov qword ptr [rbp + 0x50], 1
L_0b4d:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x8d8]
    add rax, -8
    mov eax, dword ptr [rax]
    lea rdx, [r13 + 0x54]
    mov rcx, qword ptr [rbp + 0x50]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    cmp rax, 0x19
    short jle L_0b4d
    mov eax, dword ptr [rip + reloc(XFILE_COMMON2)]
    mov dword ptr [r13 + 0xb8], eax
    mov rax, qword ptr [rbp + 0x8e0]
    mov eax, dword ptr [rax]
    mov dword ptr [r13 + 4], eax
    mov rax, qword ptr [rbp + 0x8e8]
    mov eax, dword ptr [rax]
    mov dword ptr [r13 + 8], eax
    mov qword ptr [rbp + 0x10], 0
    mov qword ptr [rbp + 0x58], 0x800
    lea rax, [r13]
    mov qword ptr [rbp + 0x60], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x8c0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_15 - .rdata)]
    lea rsi, [rbp + 0x58]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rsp + 0x28], 1
    mov qword ptr [rbp + 0x70], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x70]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_dir)
    mov qword ptr [rbp + 0x50], 1
L_0c1b:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov dword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    cmp rax, 0x200
    short jle L_0c1b
    mov rax, qword ptr [rbp + 0x8f0]
    mov qword ptr [rax], 0
    mov r13, qword ptr [rbp]
    mov rbx, qword ptr [rbp + 0x78]
    mov rsi, qword ptr [rbp + 0x80]
    lea rsp, [rbp + 0x8b0]
    pop rbp
    ret
end_RTO_UPDATE_XHDR_F:

RTO_READ_XREC_F:
    push rbp
pro_RTO_READ_XREC_F_01:
    sub rsp, 0xf0
pro_RTO_READ_XREC_F_08:
    lea rbp, [rsp + 0x60]
pro_RTO_READ_XREC_F_0d:
    mov qword ptr [rbp + 0x80], rsi
pro_RTO_READ_XREC_F_14:
    mov qword ptr [rbp + 0x78], rbx
pro_RTO_READ_XREC_F_18:
    mov qword ptr [rbp + 0xa0], rcx
    mov qword ptr [rbp + 0xa8], rdx
    mov qword ptr [rbp + 0xb0], r8
    mov qword ptr [rbp + 0xb8], r9
    mov qword ptr [rbp], 1
    mov rax, qword ptr [rbp + 0xb0]
    mov rax, qword ptr [rax]
    test rax, rax
    short jle L_0cd2
    mov eax, 0x20
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
L_0cd2:
    mov rax, qword ptr [rbp + 0xc0]
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0xb8]
    mov rax, qword ptr [rax]
    imul rax, rax, 2
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    imul rdx, qword ptr [rbp]
    sar rdx, 8
    shr rdx, 0x37
    mov rax, qword ptr [rbp + 0xa8]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rax]
    imul rcx, qword ptr [rbp]
    modrm add rdx, rcx
    sar rdx, 9
    inc rdx
    mov qword ptr [rbp + 8], rdx
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    imul rdx, qword ptr [rbp]
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 8]
    imul rax, rax, 0x200
    neg rax
    modrm add rdx, rax
    inc rdx
    mov qword ptr [rbp + 0x10], rdx
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], rax
    mov eax, 1
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rip + reloc(XFILE_COMMON)], rax
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    test rax, rax
    short jle L_0e09
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x48], 0x800
    lea rax, [rip + reloc(XFILE_COMMON)]
    add rax, 0x28
    mov qword ptr [rbp + 0x50], rax
    lea rax, [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0xa0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_16 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x68], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x68]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_dir)
    short jmp L_0e29
L_0e09:
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 0x200
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rip + reloc(XFILE_COMMON)], rax
L_0e29:
    mov rax, qword ptr [rbp + 0xa0]
    mov rdx, qword ptr [rbp + 0xb0]
    mov rcx, qword ptr [rbp + 0xb8]
    mov rbx, qword ptr [rbp + 0xc0]
    lea rsi, [rbp + 0x58]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rbp + 0xc8]
    mov qword ptr [rsp + 0x28], rsi
    mov rsi, qword ptr [rbp + 0xd0]
    mov qword ptr [rsp + 0x30], rsi
    mov rsi, qword ptr [rbp + 0xd8]
    mov qword ptr [rsp + 0x38], rsi
    lea rsi, [rbp + 0x60]
    mov qword ptr [rsp + 0x40], rsi
    mov rsi, qword ptr [rbp + 0xe0]
    mov qword ptr [rsp + 0x48], rsi
    mov qword ptr [rsp + 0x50], 0x80
    mov qword ptr [rbp + 0x70], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x70]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XFILE_F)
    mov rbx, qword ptr [rbp + 0x78]
    mov rsi, qword ptr [rbp + 0x80]
    lea rsp, [rbp + 0x90]
    pop rbp
    ret
end_RTO_READ_XREC_F:

RTO_READ_XFILE_F:
    push rbp
pro_RTO_READ_XFILE_F_01:
    sub rsp, 0x100
pro_RTO_READ_XFILE_F_08:
    lea rbp, [rsp + 0x20]
pro_RTO_READ_XFILE_F_0d:
    mov qword ptr [rbp], r13
pro_RTO_READ_XFILE_F_11:
    lea r13, [rbp + 0x5f]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0xf0], rcx
    mov qword ptr [rbp + 0xf8], rdx
    mov qword ptr [rbp + 0x100], r8
    mov qword ptr [rbp + 0x108], r9
    mov rax, qword ptr [rbp + 0x138]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x130]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_LOADBUF_XFILE_F)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov eax, dword ptr [rdx]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x110]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x110]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_0f6c
    mov rax, qword ptr [rbp + 0x130]
    mov qword ptr [rax], 1
    long jmp L_1140
L_0f6c:
    mov rax, qword ptr [rbp + 0xf8]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_1004
    mov qword ptr [rbp + 0x10], 1
L_0f87:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_LOADBUF_XFILE_F)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    lea rax, [r13]
    mov rcx, qword ptr [rbp + 0x10]
    imul rcx, rcx, 4
    modrm add rax, rcx
    add rax, -4
    mov edx, dword ptr [rdx]
    mov dword ptr [rax], edx
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 0x20
    short jle L_0f87
    mov rax, qword ptr [rbp + 0x118]
    lea rdx, [r13]
    mov ecx, 0x80
    mov qword ptr [rbp + 0x30], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x30]
    mov r8, rax
    call reloc(memcpy)
L_1004:
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    short jle L_1080
L_1023:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_LOADBUF_XFILE_F)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 4
    add rax, qword ptr [rbp + 0x120]
    add rax, -4
    mov edx, dword ptr [rdx]
    mov dword ptr [rax], edx
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    short jle L_1023
L_1080:
    mov rax, qword ptr [rbp + 0x100]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_1140
L_10a3:
    mov qword ptr [rbp + 0x10], 1
L_10ab:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_LOADBUF_XFILE_F)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    lea rax, [r13]
    mov rcx, qword ptr [rbp + 0x10]
    imul rcx, rcx, 4
    modrm add rax, rcx
    add rax, -4
    mov edx, dword ptr [rdx]
    mov dword ptr [rax], edx
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 2
    short jle L_10ab
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x128]
    add rax, -8
    movsd xmm0, qword ptr [r13]
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_10a3
L_1140:
    mov r13, qword ptr [rbp]
    lea rsp, [rbp + 0xe0]
    pop rbp
    ret
end_RTO_READ_XFILE_F:

RTO_LOADBUF_XFILE_F:
    push rbp
pro_RTO_LOADBUF_XFILE_F_01:
    sub rsp, 0x90
pro_RTO_LOADBUF_XFILE_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_LOADBUF_XFILE_F_0d:
    mov qword ptr [rbp + 0x50], rsi
pro_RTO_LOADBUF_XFILE_F_11:
    mov qword ptr [rbp + 0x48], rbx
pro_RTO_LOADBUF_XFILE_F_15:
    mov qword ptr [rbp + 0x70], rcx
    mov eax, 1
    add rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], rax
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    cmp rax, 0x200
    long jle L_120f
    mov eax, 1
    add rax, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rip + reloc(XFILE_COMMON)], rax
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 1
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 0x30], 0x800
    lea rax, [rip + reloc(XFILE_COMMON)]
    add rax, 0x28
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x70]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_17 - .rdata)]
    lea rsi, [rbp + 0x30]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x40], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x40]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_dir)
L_120f:
    mov rbx, qword ptr [rbp + 0x48]
    mov rsi, qword ptr [rbp + 0x50]
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_RTO_LOADBUF_XFILE_F:

RTO_WRITE_XFILE_F:
    push rbp
pro_RTO_WRITE_XFILE_F_01:
    sub rsp, 0x100
pro_RTO_WRITE_XFILE_F_08:
    lea rbp, [rsp + 0x20]
pro_RTO_WRITE_XFILE_F_0d:
    mov qword ptr [rbp], r13
pro_RTO_WRITE_XFILE_F_11:
    lea r13, [rbp + 0x5f]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0xf0], rcx
    mov qword ptr [rbp + 0xf8], rdx
    mov qword ptr [rbp + 0x100], r8
    mov qword ptr [rbp + 0x108], r9
    mov rax, qword ptr [rbp + 0x130]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UNLOADBUF_XFILE_F)
    mov rax, qword ptr [rbp + 0x110]
    mov eax, dword ptr [rax]
    mov rdx, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rdx, rdx, 4
    lea rcx, [rip + reloc(XFILE_COMMON)]
    add rcx, 0x28
    modrm add rcx, rdx
    add rcx, -4
    mov dword ptr [rcx], eax
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x10)]
    test rax, rax
    short jg L_12b8
    mov rax, qword ptr [rbp + 0x110]
    mov rax, qword ptr [rax]
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x10)], rax
L_12b8:
    mov rax, qword ptr [rbp + 0x110]
    mov rax, qword ptr [rax]
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x18)], rax
    mov rax, qword ptr [rbp + 0xf8]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_1361
    lea rax, [r13]
    mov rdx, qword ptr [rbp + 0x118]
    mov ecx, 0x80
    mov qword ptr [rbp + 0x30], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x30]
    mov r8, rax
    call reloc(memcpy)
    mov qword ptr [rbp + 0x20], 1
L_1307:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UNLOADBUF_XFILE_F)
    lea rax, [r13]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov rdx, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rdx, rdx, 4
    lea rcx, [rip + reloc(XFILE_COMMON)]
    add rcx, 0x28
    modrm add rcx, rdx
    add rcx, -4
    mov eax, dword ptr [rax]
    mov dword ptr [rcx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 0x20
    short jle L_1307
L_1361:
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_13dd
L_1380:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UNLOADBUF_XFILE_F)
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 4
    add rax, qword ptr [rbp + 0x120]
    add rax, -4
    mov rdx, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rdx, rdx, 4
    lea rcx, [rip + reloc(XFILE_COMMON)]
    add rcx, 0x28
    modrm add rcx, rdx
    add rcx, -4
    mov eax, dword ptr [rax]
    mov dword ptr [rcx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_1380
L_13dd:
    mov rax, qword ptr [rbp + 0x100]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_149d
L_1400:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x128]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [r13], xmm0
    mov qword ptr [rbp + 0x20], 1
L_1425:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UNLOADBUF_XFILE_F)
    lea rax, [r13]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov rdx, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rdx, rdx, 4
    lea rcx, [rip + reloc(XFILE_COMMON)]
    add rcx, 0x28
    modrm add rcx, rdx
    add rcx, -4
    mov eax, dword ptr [rax]
    mov dword ptr [rcx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 2
    short jle L_1425
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_1400
L_149d:
    mov r13, qword ptr [rbp]
    lea rsp, [rbp + 0xe0]
    pop rbp
    ret
end_RTO_WRITE_XFILE_F:

RTO_FLUSH_XFILE_F:
    push rbp
pro_RTO_FLUSH_XFILE_F_01:
    sub rsp, 0x8f0
pro_RTO_FLUSH_XFILE_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_FLUSH_XFILE_F_0d:
    mov qword ptr [rbp + 0x90], rsi
pro_RTO_FLUSH_XFILE_F_14:
    mov qword ptr [rbp + 0x88], rbx
pro_RTO_FLUSH_XFILE_F_1b:
    mov qword ptr [rbp], r13
pro_RTO_FLUSH_XFILE_F_1f:
    lea r13, [rbp + 0xbf]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0x8d0], rcx
    mov qword ptr [rbp + 0x8d8], rdx
    mov rax, qword ptr [rbp + 0x8d8]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x20)]
    test rax, rax
    long jle L_1692
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x20)]
    cmp rax, 1
    short jne L_1543
    mov rax, qword ptr [rbp + 0x8d0]
    mov rcx, rax
    call reloc(RTO_UNLOADBUF_XFILE_F)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov dword ptr [rdx], 0xffffffff
L_1543:
    mov qword ptr [rbp + 0x10], 0
    mov qword ptr [rbp + 0x40], 0x800
    lea rax, [rip + reloc(XFILE_COMMON)]
    add rax, 0x28
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x8d0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_18 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x70], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x70]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_dir)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x20)]
    cmp rax, 1
    long jg L_1692
    mov qword ptr [rbp + 0x10], 0
    mov qword ptr [rbp + 0x50], 0x800
    lea rax, [r13]
    mov qword ptr [rbp + 0x58], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x8d0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_19 - .rdata)]
    lea rsi, [rbp + 0x50]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rsp + 0x28], 1
    mov qword ptr [rbp + 0x78], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x78]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_dir)
    mov eax, dword ptr [rip + reloc(XFILE_COMMON, 0x10)]
    mov dword ptr [r13 + 4], eax
    mov eax, dword ptr [rip + reloc(XFILE_COMMON, 0x18)]
    mov dword ptr [r13 + 8], eax
    mov qword ptr [rbp + 0x10], 0
    mov qword ptr [rbp + 0x60], 0x800
    lea rax, [r13]
    mov qword ptr [rbp + 0x68], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x8d0]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_20 - .rdata)]
    lea rsi, [rbp + 0x60]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rsp + 0x28], 1
    mov qword ptr [rbp + 0x80], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x80]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_dir)
L_1692:
    mov r13, qword ptr [rbp]
    mov rbx, qword ptr [rbp + 0x88]
    mov rsi, qword ptr [rbp + 0x90]
    lea rsp, [rbp + 0x8c0]
    pop rbp
    ret
end_RTO_FLUSH_XFILE_F:

RTO_UNLOADBUF_XFILE_F:
    push rbp
pro_RTO_UNLOADBUF_XFILE_F_01:
    sub rsp, 0x90
pro_RTO_UNLOADBUF_XFILE_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_UNLOADBUF_XFILE_F_0d:
    mov qword ptr [rbp + 0x58], rsi
pro_RTO_UNLOADBUF_XFILE_F_11:
    mov qword ptr [rbp + 0x50], rbx
pro_RTO_UNLOADBUF_XFILE_F_15:
    mov qword ptr [rbp + 0x70], rcx
    mov eax, 1
    add rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], rax
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    cmp rax, 0x200
    long jle L_17b0
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 0x30], 0x800
    lea rax, [rip + reloc(XFILE_COMMON)]
    add rax, 0x28
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x70]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_21 - .rdata)]
    lea rsi, [rbp + 0x30]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x48], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x48]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_dir)
    mov eax, 1
    add rax, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rip + reloc(XFILE_COMMON)], rax
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 1
    mov qword ptr [rbp + 0x40], 1
L_1777:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov dword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    cmp rax, 0x200
    short jle L_1777
L_17b0:
    mov rbx, qword ptr [rbp + 0x50]
    mov rsi, qword ptr [rbp + 0x58]
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_RTO_UNLOADBUF_XFILE_F:

RTO_UPDATE_XFILE_F:
    push rbp
pro_RTO_UPDATE_XFILE_F_01:
    sub rsp, 0x100
pro_RTO_UPDATE_XFILE_F_08:
    lea rbp, [rsp + 0x20]
pro_RTO_UPDATE_XFILE_F_0d:
    mov qword ptr [rbp], r13
pro_RTO_UPDATE_XFILE_F_11:
    lea r13, [rbp + 0x5f]
    and r13, 0xffffffffffffffe0
    mov qword ptr [rbp + 8], r13
    mov qword ptr [rbp + 0xf0], rcx
    mov qword ptr [rbp + 0xf8], rdx
    mov qword ptr [rbp + 0x100], r8
    mov qword ptr [rbp + 0x108], r9
    mov rax, qword ptr [rbp + 0x130]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UPDATEBUF_XFILE_F)
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rax, rax, 4
    lea rdx, [rip + reloc(XFILE_COMMON)]
    add rdx, 0x28
    modrm add rdx, rax
    add rdx, -4
    mov eax, dword ptr [rdx]
    movsxd rax, eax
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jge L_1856
    mov rax, qword ptr [rbp + 0x130]
    mov qword ptr [rax], 0xffffffffffffffff
    long jmp L_1a1d
L_1856:
    mov rax, qword ptr [rbp + 0xf8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jle L_1893
    mov qword ptr [rbp + 0x18], 1
L_186d:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UPDATEBUF_XFILE_F)
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    cmp rax, 0x20
    short jle L_186d
L_1893:
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    short jle L_1929
L_18b2:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UPDATEBUF_XFILE_F)
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 4
    add rax, qword ptr [rbp + 0x110]
    add rax, -4
    mov eax, dword ptr [rax]
    cmp eax, 1
    short jne L_190f
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 4
    add rax, qword ptr [rbp + 0x118]
    add rax, -4
    mov rdx, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rdx, rdx, 4
    lea rcx, [rip + reloc(XFILE_COMMON)]
    add rcx, 0x28
    modrm add rcx, rdx
    add rcx, -4
    mov eax, dword ptr [rax]
    mov dword ptr [rcx], eax
L_190f:
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_18b2
L_1929:
    mov rax, qword ptr [rbp + 0x100]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jle L_1a1d
L_194c:
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 4
    add rax, qword ptr [rbp + 0x120]
    add rax, -4
    mov eax, dword ptr [rax]
    cmp eax, 1
    short jne L_1983
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x128]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [r13], xmm0
L_1983:
    mov qword ptr [rbp + 0x18], 1
L_198b:
    mov rax, qword ptr [rbp + 0xf0]
    mov rcx, rax
    call reloc(RTO_UPDATEBUF_XFILE_F)
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 4
    add rax, qword ptr [rbp + 0x120]
    add rax, -4
    mov eax, dword ptr [rax]
    cmp eax, 1
    short jne L_19e8
    lea rax, [r13]
    mov rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov rdx, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    imul rdx, rdx, 4
    lea rcx, [rip + reloc(XFILE_COMMON)]
    add rcx, 0x28
    modrm add rcx, rdx
    add rcx, -4
    mov eax, dword ptr [rax]
    mov dword ptr [rcx], eax
L_19e8:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    cmp rax, 2
    short jle L_198b
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long jle L_194c
L_1a1d:
    mov r13, qword ptr [rbp]
    lea rsp, [rbp + 0xe0]
    pop rbp
    ret
end_RTO_UPDATE_XFILE_F:

RTO_UPDATEBUF_XFILE_F:
    push rbp
pro_RTO_UPDATEBUF_XFILE_F_01:
    sub rsp, 0xa0
pro_RTO_UPDATEBUF_XFILE_F_08:
    lea rbp, [rsp + 0x30]
pro_RTO_UPDATEBUF_XFILE_F_0d:
    mov qword ptr [rbp + 0x68], rsi
pro_RTO_UPDATEBUF_XFILE_F_11:
    mov qword ptr [rbp + 0x60], rbx
pro_RTO_UPDATEBUF_XFILE_F_15:
    mov qword ptr [rbp + 0x80], rcx
    mov eax, 1
    add rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], rax
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x8)]
    cmp rax, 0x200
    long jle L_1b67
    mov rax, qword ptr [rip + reloc(XFILE_COMMON)]
    cmp rax, 1
    short jle L_1ae1
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 0x30], 0x800
    lea rax, [rip + reloc(XFILE_COMMON)]
    add rax, 0x28
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x80]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_22 - .rdata)]
    lea rsi, [rbp + 0x30]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x50], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x50]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_dir)
L_1ae1:
    mov eax, 1
    add rax, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rip + reloc(XFILE_COMMON)], rax
    mov qword ptr [rip + reloc(XFILE_COMMON, 0x8)], 1
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 0x40], 0x800
    lea rax, [rip + reloc(XFILE_COMMON)]
    add rax, 0x28
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x80]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_23 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rip + reloc(XFILE_COMMON)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x58], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x58]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_dir)
L_1b67:
    mov rbx, qword ptr [rbp + 0x60]
    mov rsi, qword ptr [rbp + 0x68]
    lea rsp, [rbp + 0x70]
    pop rbp
    ret
end_RTO_UPDATEBUF_XFILE_F:

RTO_CLOSE_XFILE_F:
    push rbp
pro_RTO_CLOSE_XFILE_F_01:
    sub rsp, 0x70
pro_RTO_CLOSE_XFILE_F_05:
    lea rbp, [rsp + 0x30]
pro_RTO_CLOSE_XFILE_F_0a:
    mov qword ptr [rbp + 0x38], rbx
pro_RTO_CLOSE_XFILE_F_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov rax, qword ptr [rip + reloc(XFILE_COMMON, 0x20)]
    test rax, rax
    short jle L_1ba7
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x58]
    mov rcx, rax
    call reloc(RTO_FLUSH_XFILE_F)
L_1ba7:
    mov qword ptr [rbp], 0
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x50]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_24 - .rdata)]
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x30], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x30]
    mov r8, rax
    mov r9, rbx
    call reloc(for_close)
    mov rbx, qword ptr [rbp + 0x38]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_RTO_CLOSE_XFILE_F:
    nop

.section .xdata 0x40300040
unwind_RTO_RECLEN_XFILE_F:
    .unwind RTO_RECLEN_XFILE_F, pro_RTO_RECLEN_XFILE_F_0a, rbp, 32
        .set_fpreg pro_RTO_RECLEN_XFILE_F_0a
        .alloc_small pro_RTO_RECLEN_XFILE_F_05, 32
        .push_nonvol pro_RTO_RECLEN_XFILE_F_01, rbp
    .endunwind
unwind_RTO_OPENRD_XFILE_F:
    .unwind RTO_OPENRD_XFILE_F, pro_RTO_OPENRD_XFILE_F_1b, rbp, 64
        .save_nonvol pro_RTO_OPENRD_XFILE_F_1b, rbx, 224
        .save_nonvol pro_RTO_OPENRD_XFILE_F_14, rsi, 232
        .set_fpreg pro_RTO_OPENRD_XFILE_F_0d
        .alloc_large pro_RTO_OPENRD_XFILE_F_08, 240
        .push_nonvol pro_RTO_OPENRD_XFILE_F_01, rbp
    .endunwind
unwind_RTO_OPENWR_XFILE_F:
    .unwind RTO_OPENWR_XFILE_F, pro_RTO_OPENWR_XFILE_F_1b, rbp, 48
        .save_nonvol pro_RTO_OPENWR_XFILE_F_1b, rbx, 208
        .save_nonvol pro_RTO_OPENWR_XFILE_F_14, rsi, 216
        .set_fpreg pro_RTO_OPENWR_XFILE_F_0d
        .alloc_large pro_RTO_OPENWR_XFILE_F_08, 224
        .push_nonvol pro_RTO_OPENWR_XFILE_F_01, rbp
    .endunwind
unwind_RTO_OPENUP_XFILE_F:
    .unwind RTO_OPENUP_XFILE_F, pro_RTO_OPENUP_XFILE_F_1b, rbp, 64
        .save_nonvol pro_RTO_OPENUP_XFILE_F_1b, rbx, 232
        .save_nonvol pro_RTO_OPENUP_XFILE_F_14, rsi, 240
        .set_fpreg pro_RTO_OPENUP_XFILE_F_0d
        .alloc_large pro_RTO_OPENUP_XFILE_F_08, 256
        .push_nonvol pro_RTO_OPENUP_XFILE_F_01, rbp
    .endunwind
unwind_RTO_READ_XHDR_F:
    .unwind RTO_READ_XHDR_F, pro_RTO_READ_XHDR_F_19, rbp, 48
        .save_nonvol pro_RTO_READ_XHDR_F_19, r13, 48
        .save_nonvol pro_RTO_READ_XHDR_F_15, rbx, 160
        .save_nonvol pro_RTO_READ_XHDR_F_11, rsi, 168
        .set_fpreg pro_RTO_READ_XHDR_F_0d
        .alloc_large pro_RTO_READ_XHDR_F_08, 2256
        .push_nonvol pro_RTO_READ_XHDR_F_01, rbp
    .endunwind
unwind_RTO_WRITE_XHDR_F:
    .unwind RTO_WRITE_XHDR_F, pro_RTO_WRITE_XHDR_F_19, rbp, 48
        .save_nonvol pro_RTO_WRITE_XHDR_F_19, r13, 48
        .save_nonvol pro_RTO_WRITE_XHDR_F_15, rbx, 144
        .save_nonvol pro_RTO_WRITE_XHDR_F_11, rsi, 152
        .set_fpreg pro_RTO_WRITE_XHDR_F_0d
        .alloc_large pro_RTO_WRITE_XHDR_F_08, 2240
        .push_nonvol pro_RTO_WRITE_XHDR_F_01, rbp
    .endunwind
unwind_RTO_UPDATE_XHDR_F:
    .unwind RTO_UPDATE_XHDR_F, pro_RTO_UPDATE_XHDR_F_1c, rbp, 48
        .save_nonvol pro_RTO_UPDATE_XHDR_F_1c, r13, 48
        .save_nonvol pro_RTO_UPDATE_XHDR_F_18, rbx, 168
        .save_nonvol pro_RTO_UPDATE_XHDR_F_14, rsi, 176
        .set_fpreg pro_RTO_UPDATE_XHDR_F_0d
        .alloc_large pro_RTO_UPDATE_XHDR_F_08, 2272
        .push_nonvol pro_RTO_UPDATE_XHDR_F_01, rbp
    .endunwind
unwind_RTO_READ_XREC_F:
    .unwind RTO_READ_XREC_F, pro_RTO_READ_XREC_F_18, rbp, 96
        .save_nonvol pro_RTO_READ_XREC_F_18, rbx, 216
        .save_nonvol pro_RTO_READ_XREC_F_14, rsi, 224
        .set_fpreg pro_RTO_READ_XREC_F_0d
        .alloc_large pro_RTO_READ_XREC_F_08, 240
        .push_nonvol pro_RTO_READ_XREC_F_01, rbp
    .endunwind
unwind_RTO_READ_XFILE_F:
    .unwind RTO_READ_XFILE_F, pro_RTO_READ_XFILE_F_11, rbp, 32
        .save_nonvol pro_RTO_READ_XFILE_F_11, r13, 32
        .set_fpreg pro_RTO_READ_XFILE_F_0d
        .alloc_large pro_RTO_READ_XFILE_F_08, 256
        .push_nonvol pro_RTO_READ_XFILE_F_01, rbp
    .endunwind
unwind_RTO_LOADBUF_XFILE_F:
    .unwind RTO_LOADBUF_XFILE_F, pro_RTO_LOADBUF_XFILE_F_15, rbp, 48
        .save_nonvol pro_RTO_LOADBUF_XFILE_F_15, rbx, 120
        .save_nonvol pro_RTO_LOADBUF_XFILE_F_11, rsi, 128
        .set_fpreg pro_RTO_LOADBUF_XFILE_F_0d
        .alloc_large pro_RTO_LOADBUF_XFILE_F_08, 144
        .push_nonvol pro_RTO_LOADBUF_XFILE_F_01, rbp
    .endunwind
unwind_RTO_WRITE_XFILE_F:
    .unwind RTO_WRITE_XFILE_F, pro_RTO_WRITE_XFILE_F_11, rbp, 32
        .save_nonvol pro_RTO_WRITE_XFILE_F_11, r13, 32
        .set_fpreg pro_RTO_WRITE_XFILE_F_0d
        .alloc_large pro_RTO_WRITE_XFILE_F_08, 256
        .push_nonvol pro_RTO_WRITE_XFILE_F_01, rbp
    .endunwind
unwind_RTO_FLUSH_XFILE_F:
    .unwind RTO_FLUSH_XFILE_F, pro_RTO_FLUSH_XFILE_F_1f, rbp, 48
        .save_nonvol pro_RTO_FLUSH_XFILE_F_1f, r13, 48
        .save_nonvol pro_RTO_FLUSH_XFILE_F_1b, rbx, 184
        .save_nonvol pro_RTO_FLUSH_XFILE_F_14, rsi, 192
        .set_fpreg pro_RTO_FLUSH_XFILE_F_0d
        .alloc_large pro_RTO_FLUSH_XFILE_F_08, 2288
        .push_nonvol pro_RTO_FLUSH_XFILE_F_01, rbp
    .endunwind
unwind_RTO_UNLOADBUF_XFILE_F:
    .unwind RTO_UNLOADBUF_XFILE_F, pro_RTO_UNLOADBUF_XFILE_F_15, rbp, 48
        .save_nonvol pro_RTO_UNLOADBUF_XFILE_F_15, rbx, 128
        .save_nonvol pro_RTO_UNLOADBUF_XFILE_F_11, rsi, 136
        .set_fpreg pro_RTO_UNLOADBUF_XFILE_F_0d
        .alloc_large pro_RTO_UNLOADBUF_XFILE_F_08, 144
        .push_nonvol pro_RTO_UNLOADBUF_XFILE_F_01, rbp
    .endunwind
unwind_RTO_UPDATE_XFILE_F:
    .unwind RTO_UPDATE_XFILE_F, pro_RTO_UPDATE_XFILE_F_11, rbp, 32
        .save_nonvol pro_RTO_UPDATE_XFILE_F_11, r13, 32
        .set_fpreg pro_RTO_UPDATE_XFILE_F_0d
        .alloc_large pro_RTO_UPDATE_XFILE_F_08, 256
        .push_nonvol pro_RTO_UPDATE_XFILE_F_01, rbp
    .endunwind
unwind_RTO_UPDATEBUF_XFILE_F:
    .unwind RTO_UPDATEBUF_XFILE_F, pro_RTO_UPDATEBUF_XFILE_F_15, rbp, 48
        .save_nonvol pro_RTO_UPDATEBUF_XFILE_F_15, rbx, 144
        .save_nonvol pro_RTO_UPDATEBUF_XFILE_F_11, rsi, 152
        .set_fpreg pro_RTO_UPDATEBUF_XFILE_F_0d
        .alloc_large pro_RTO_UPDATEBUF_XFILE_F_08, 160
        .push_nonvol pro_RTO_UPDATEBUF_XFILE_F_01, rbp
    .endunwind
unwind_RTO_CLOSE_XFILE_F:
    .unwind RTO_CLOSE_XFILE_F, pro_RTO_CLOSE_XFILE_F_0e, rbp, 48
        .save_nonvol pro_RTO_CLOSE_XFILE_F_0e, rbx, 104
        .set_fpreg pro_RTO_CLOSE_XFILE_F_0a
        .alloc_small pro_RTO_CLOSE_XFILE_F_05, 112
        .push_nonvol pro_RTO_CLOSE_XFILE_F_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTO_RECLEN_XFILE_F
    .rva RTO_RECLEN_XFILE_F, end_RTO_RECLEN_XFILE_F - RTO_RECLEN_XFILE_F
    .rva .xdata, unwind_RTO_RECLEN_XFILE_F - .xdata
    .rva RTO_OPENRD_XFILE_F
    .rva RTO_OPENRD_XFILE_F, end_RTO_OPENRD_XFILE_F - RTO_OPENRD_XFILE_F
    .rva .xdata, unwind_RTO_OPENRD_XFILE_F - .xdata
    .rva RTO_OPENWR_XFILE_F
    .rva RTO_OPENWR_XFILE_F, end_RTO_OPENWR_XFILE_F - RTO_OPENWR_XFILE_F
    .rva .xdata, unwind_RTO_OPENWR_XFILE_F - .xdata
    .rva RTO_OPENUP_XFILE_F
    .rva RTO_OPENUP_XFILE_F, end_RTO_OPENUP_XFILE_F - RTO_OPENUP_XFILE_F
    .rva .xdata, unwind_RTO_OPENUP_XFILE_F - .xdata
    .rva RTO_READ_XHDR_F
    .rva RTO_READ_XHDR_F, end_RTO_READ_XHDR_F - RTO_READ_XHDR_F
    .rva .xdata, unwind_RTO_READ_XHDR_F - .xdata
    .rva RTO_WRITE_XHDR_F
    .rva RTO_WRITE_XHDR_F, end_RTO_WRITE_XHDR_F - RTO_WRITE_XHDR_F
    .rva .xdata, unwind_RTO_WRITE_XHDR_F - .xdata
    .rva RTO_UPDATE_XHDR_F
    .rva RTO_UPDATE_XHDR_F, end_RTO_UPDATE_XHDR_F - RTO_UPDATE_XHDR_F
    .rva .xdata, unwind_RTO_UPDATE_XHDR_F - .xdata
    .rva RTO_READ_XREC_F
    .rva RTO_READ_XREC_F, end_RTO_READ_XREC_F - RTO_READ_XREC_F
    .rva .xdata, unwind_RTO_READ_XREC_F - .xdata
    .rva RTO_READ_XFILE_F
    .rva RTO_READ_XFILE_F, end_RTO_READ_XFILE_F - RTO_READ_XFILE_F
    .rva .xdata, unwind_RTO_READ_XFILE_F - .xdata
    .rva RTO_LOADBUF_XFILE_F
    .rva RTO_LOADBUF_XFILE_F, end_RTO_LOADBUF_XFILE_F - RTO_LOADBUF_XFILE_F
    .rva .xdata, unwind_RTO_LOADBUF_XFILE_F - .xdata
    .rva RTO_WRITE_XFILE_F
    .rva RTO_WRITE_XFILE_F, end_RTO_WRITE_XFILE_F - RTO_WRITE_XFILE_F
    .rva .xdata, unwind_RTO_WRITE_XFILE_F - .xdata
    .rva RTO_FLUSH_XFILE_F
    .rva RTO_FLUSH_XFILE_F, end_RTO_FLUSH_XFILE_F - RTO_FLUSH_XFILE_F
    .rva .xdata, unwind_RTO_FLUSH_XFILE_F - .xdata
    .rva RTO_UNLOADBUF_XFILE_F
    .rva RTO_UNLOADBUF_XFILE_F, end_RTO_UNLOADBUF_XFILE_F - RTO_UNLOADBUF_XFILE_F
    .rva .xdata, unwind_RTO_UNLOADBUF_XFILE_F - .xdata
    .rva RTO_UPDATE_XFILE_F
    .rva RTO_UPDATE_XFILE_F, end_RTO_UPDATE_XFILE_F - RTO_UPDATE_XFILE_F
    .rva .xdata, unwind_RTO_UPDATE_XFILE_F - .xdata
    .rva RTO_UPDATEBUF_XFILE_F
    .rva RTO_UPDATEBUF_XFILE_F, end_RTO_UPDATEBUF_XFILE_F - RTO_UPDATEBUF_XFILE_F
    .rva .xdata, unwind_RTO_UPDATEBUF_XFILE_F - .xdata
    .rva RTO_CLOSE_XFILE_F
    .rva RTO_CLOSE_XFILE_F, end_RTO_CLOSE_XFILE_F - RTO_CLOSE_XFILE_F
    .rva .xdata, unwind_RTO_CLOSE_XFILE_F - .xdata

.section .rdata 0x40400040
__STRLITPACK_2:
    .byte 0x6f, 0x6c, 0x64, 0x00
__STRLITPACK_1:
    .ascii "direct"
    .zero 2
__STRLITPACK_0:
    .ascii "unformatted"
    .byte 0x00
__NLITPACK_0:
    .byte 0x00, 0x02
    .zero 6
__STRLITPACK_3:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x38, 0x04, 0x1a, 0x00, 0x38, 0x04, 0x02, 0x00, 0x38, 0x04, 0x0f, 0x00
    .byte 0x0b, 0x01, 0x15, 0x00, 0x01
    .zero 7
__STRLITPACK_6:
    .ascii "unknown"
    .byte 0x00
__STRLITPACK_5:
    .ascii "direct"
    .zero 2
__STRLITPACK_4:
    .ascii "unformatted"
    .byte 0x00
__NLITPACK_1:
    .byte 0x00, 0x02
    .zero 6
__STRLITPACK_7:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x38, 0x04, 0x1a, 0x00, 0x38, 0x04, 0x02, 0x00, 0x38, 0x04, 0x0f, 0x00
    .byte 0x0b, 0x01, 0x15, 0x00, 0x01
    .zero 7
__STRLITPACK_10:
    .byte 0x6f, 0x6c, 0x64, 0x00
__STRLITPACK_9:
    .ascii "direct"
    .zero 2
__STRLITPACK_8:
    .ascii "unformatted"
    .zero 5
__NLITPACK_2:
    .byte 0x00, 0x02
    .zero 6
__STRLITPACK_11:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x38, 0x04, 0x1a, 0x00, 0x38, 0x04, 0x02, 0x00, 0x38, 0x04, 0x0f, 0x00
    .byte 0x0b, 0x01, 0x15, 0x00, 0x01
    .zero 7
__STRLITPACK_12:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_13:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_14:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_15:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_16:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_17:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_18:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_19:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_20:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_21:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_22:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_23:
    .byte 0x09, 0x05, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_24:
    .byte 0x01
    .zero 3
    .byte 0x38
    .zero 7

.section .data 0xc0300040

.section .bss 0xc0600080
XFILE_COMMON2:
    .space 32

.section .drectve 0x00100a00
    .ascii "-export:RTO_CLOSE_XFILE_F  -export:RTO_READ_XFILE_F  -export:RTO_READ_XREC_F  -export:RTO_OPENRD_XFILE_F  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\oomfmalloc_f.obj 1743626483
.index FORTRAN_MALLOC_INIT

.symbol .text section local
.symbol FORTRAN_MALLOC_INIT function public
.symbol OOMF_PLEX common public 128
.symbol RTO_MALLOC_INIT external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

FORTRAN_MALLOC_INIT:
    push rbp
pro_FORTRAN_MALLOC_INIT_01:
    sub rsp, 0x40
pro_FORTRAN_MALLOC_INIT_05:
    lea rbp, [rsp + 0x20]
pro_FORTRAN_MALLOC_INIT_0a:
    mov qword ptr [rbp + 0x18], rbx
pro_FORTRAN_MALLOC_INIT_0e:
    mov eax, 8
    mov edx, 8
    modrm sub rax, rdx
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rax, rdx
    mov edx, 8
    mov ecx, 8
    modrm sub rdx, rcx
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rcx
    mov ecx, 8
    mov ebx, 8
    modrm sub rcx, rbx
    lea rbx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x10], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x10]
    mov r8, rax
    call reloc(RTO_MALLOC_INIT)
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov rbx, qword ptr [rbp + 0x18]
    lea rsp, [rbp + 0x20]
    pop rbp
    ret
end_FORTRAN_MALLOC_INIT:

.section .xdata 0x40300040
unwind_FORTRAN_MALLOC_INIT:
    .unwind FORTRAN_MALLOC_INIT, pro_FORTRAN_MALLOC_INIT_0e, rbp, 32
        .save_nonvol pro_FORTRAN_MALLOC_INIT_0e, rbx, 56
        .set_fpreg pro_FORTRAN_MALLOC_INIT_0a
        .alloc_small pro_FORTRAN_MALLOC_INIT_05, 64
        .push_nonvol pro_FORTRAN_MALLOC_INIT_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva FORTRAN_MALLOC_INIT
    .rva FORTRAN_MALLOC_INIT, end_FORTRAN_MALLOC_INIT - FORTRAN_MALLOC_INIT
    .rva .xdata, unwind_FORTRAN_MALLOC_INIT - .xdata

.section .drectve 0x00100a00
    .ascii "-export:FORTRAN_MALLOC_INIT  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\fpipe.obj 1743626483
.index FPIPECLOSE
.index FPIPEPUSH

.symbol .text section local
.symbol FPIPEPUSH function public
.symbol FPIPECLOSE function public
.symbol .rdata section local
.symbol .data section local
.symbol for_write_seq_fmt external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol FPIPEPUSH$format_pack data local
.symbol __STRLITPACK_2 data local
.symbol for_close external public function
.symbol __STRLITPACK_3 data local
.symbol __ImageBase external public function
.symbol .drectve section local

.section .text 0x60300020

FPIPEPUSH:
    push rbp
pro_FPIPEPUSH_01:
    sub rsp, 0xa0
pro_FPIPEPUSH_08:
    lea rbp, [rsp + 0x30]
pro_FPIPEPUSH_0d:
    mov qword ptr [rbp + 0x68], rsi
pro_FPIPEPUSH_11:
    mov qword ptr [rbp + 0x60], rbx
pro_FPIPEPUSH_15:
    mov qword ptr [rbp + 0x80], rcx
    mov qword ptr [rbp + 0x88], rdx
    mov qword ptr [rbp + 0x90], r8
    mov qword ptr [rbp + 0x98], r9
    mov rax, qword ptr [rbp + 0x90]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    test rax, rax
    short jg L_0052
    mov qword ptr [rbp + 8], 0
    short jmp L_005a
L_0052:
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 8], rax
L_005a:
    mov qword ptr [rbp + 0x10], 0
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x40], rax
    mov eax, 0
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x80]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_2 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rip + reloc(.data, FPIPEPUSH$format_pack - .data)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x58], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x58]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_fmt)
    mov qword ptr [rbp + 0x50], 1
    mov rax, qword ptr [rbp + 0x50]
    mov rbx, qword ptr [rbp + 0x60]
    mov rsi, qword ptr [rbp + 0x68]
    lea rsp, [rbp + 0x70]
    pop rbp
    ret
end_FPIPEPUSH:

FPIPECLOSE:
    push rbp
pro_FPIPECLOSE_01:
    sub rsp, 0x70
pro_FPIPECLOSE_05:
    lea rbp, [rsp + 0x30]
pro_FPIPECLOSE_0a:
    mov qword ptr [rbp + 0x38], rbx
pro_FPIPECLOSE_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp], 0
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x50]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x30], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x30]
    mov r8, rax
    mov r9, rbx
    call reloc(for_close)
    mov rbx, qword ptr [rbp + 0x38]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_FPIPECLOSE:
    nop

.section .rdata 0x40300040
__STRLITPACK_2:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_3:
    .byte 0x01
    .zero 7

.section .data 0xc0300040
FPIPEPUSH$format_pack:
    .byte 0x36
    .zero 3
    .byte 0x48, 0x00, 0x01, 0x00, 0x45
    .zero 3
    .byte 0x37
    .zero 3

.section .xdata 0x40300040
unwind_FPIPEPUSH:
    .unwind FPIPEPUSH, pro_FPIPEPUSH_15, rbp, 48
        .save_nonvol pro_FPIPEPUSH_15, rbx, 144
        .save_nonvol pro_FPIPEPUSH_11, rsi, 152
        .set_fpreg pro_FPIPEPUSH_0d
        .alloc_large pro_FPIPEPUSH_08, 160
        .push_nonvol pro_FPIPEPUSH_01, rbp
    .endunwind
unwind_FPIPECLOSE:
    .unwind FPIPECLOSE, pro_FPIPECLOSE_0e, rbp, 48
        .save_nonvol pro_FPIPECLOSE_0e, rbx, 104
        .set_fpreg pro_FPIPECLOSE_0a
        .alloc_small pro_FPIPECLOSE_05, 112
        .push_nonvol pro_FPIPECLOSE_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva FPIPEPUSH
    .rva FPIPEPUSH, end_FPIPEPUSH - FPIPEPUSH
    .rva .xdata, unwind_FPIPEPUSH - .xdata
    .rva FPIPECLOSE
    .rva FPIPECLOSE, end_FPIPECLOSE - FPIPECLOSE
    .rva .xdata, unwind_FPIPECLOSE - .xdata

.section .drectve 0x00100a00
    .ascii "-defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\cmndatainit.obj 1743626483
.index CMNDATAINIT
.index OOMF_FLES
.index OOMF_GLOBAL
.index OOMF_RGLOB

.symbol .text section local
.symbol CMNDATAINIT function public
.symbol .xdata section local
.symbol .pdata section local
.symbol .data section local
.symbol OOMF_RGLOB data public
.symbol OOMF_GLOBAL data public
.symbol OOMF_FLES data public
.symbol OOMF_PLEX common public 128
.symbol __ImageBase external public function
.symbol .drectve section local

.section .text 0x60300020

CMNDATAINIT:
    push rbp
pro_CMNDATAINIT_01:
    sub rsp, 0x20
pro_CMNDATAINIT_05:
    lea rbp, [rsp + 0x20]
pro_CMNDATAINIT_0a:
    lea rsp, [rbp]
    pop rbp
    ret
end_CMNDATAINIT:

.section .xdata 0x40300040
unwind_CMNDATAINIT:
    .unwind CMNDATAINIT, pro_CMNDATAINIT_0a, rbp, 32
        .set_fpreg pro_CMNDATAINIT_0a
        .alloc_small pro_CMNDATAINIT_05, 32
        .push_nonvol pro_CMNDATAINIT_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva CMNDATAINIT
    .rva CMNDATAINIT, end_CMNDATAINIT - CMNDATAINIT
    .rva .xdata, unwind_CMNDATAINIT - .xdata

.section .data 0xc0600040
OOMF_RGLOB:
    .byte 0x82, 0x4d, 0xc7
    .ascii "raB3G"
    .zero 24
OOMF_GLOBAL:
    .byte 0xff, 0xe0, 0xf5, 0x05
    .zero 28
OOMF_FLES:
    .zero 96
    .byte 0x24
    .zero 7
    .byte 0x0e
    .zero 215

.section .drectve 0x00100a00
    .ascii "-defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\slatec.obj 1743626483
.index SLATEC_DSORT
.index SLATEC_ISORT

.symbol .text section local
.symbol SLATEC_DSORT function public
.symbol SLATEC_ISORT function public
.symbol .rdata section local
.symbol _2il0floatpacket.4 data local
.symbol _2il0floatpacket.0 data local
.symbol _2il0floatpacket.1 data local
.symbol _2il0floatpacket.2 data local
.symbol _2il0floatpacket.3 data local
.symbol .xdata section local
.symbol .pdata section local
.symbol _2il0floatpacket.5 data local
.symbol _2il0floatpacket.6 data local
.symbol _2il0floatpacket.7 data local
.symbol _2il0floatpacket.8 data local
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

SLATEC_DSORT:
    ; Check count and sort-control magnitude before operating on double-precision data.
    push rbp
pro_SLATEC_DSORT_01:
    sub rsp, 0x200
pro_SLATEC_DSORT_08:
    lea rbp, [rsp + 0x20]
pro_SLATEC_DSORT_0d:
    mov qword ptr [rbp + 0x1f0], rcx
    mov qword ptr [rbp + 0x1f8], rdx
    mov qword ptr [rbp + 0x200], r8
    mov qword ptr [rbp + 0x208], r9
    mov rax, qword ptr [rbp + 0x200]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    test rax, rax
    long jle L_0e9c
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov rdx, rax
    sar rdx, 0x3f
    modrm xor rax, rdx
    modrm sub rax, rdx
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    cmp rax, 1
    short je L_0077
    mov rax, qword ptr [rbp + 8]
    cmp rax, 2
    long jne L_0e9c
L_0077:
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_00ef
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_00ef
L_009f:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    xorpd xmm0, xmmword ptr [rip + reloc(.rdata, _2il0floatpacket.4 - .rdata)]
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_009f
L_00ef:
    mov rax, qword ptr [rbp + 8]
    cmp rax, 2
    long je L_0682
    mov qword ptr [rbp + 0x20], 1
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x28], rax
    movsd xmm0, qword ptr [rip + reloc(.rdata, _2il0floatpacket.0 - .rdata)]
    movsd qword ptr [rbp + 0x30], xmm0
L_0122:
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long je L_0504
    movsd xmm0, qword ptr [rbp + 0x30]
    movsd xmm1, qword ptr [rip + reloc(.rdata, _2il0floatpacket.1 - .rdata)]
    comisd xmm0, xmm1
    short ja L_0160
    short jp L_0160
    movsd xmm0, qword ptr [rip + reloc(.rdata, _2il0floatpacket.2 - .rdata)]
    movsd xmm1, qword ptr [rbp + 0x30]
    addsd xmm1, xmm0
    movsd qword ptr [rbp + 0x30], xmm1
    short jmp L_0176
L_0160:
    movsd xmm0, qword ptr [rip + reloc(.rdata, _2il0floatpacket.3 - .rdata)]
    movsd xmm1, qword ptr [rbp + 0x30]
    subsd xmm1, xmm0
    movsd qword ptr [rbp + 0x30], xmm1
L_0176:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 0x28]
    cvtsi2sd xmm0, rax
    movsd xmm1, qword ptr [rbp + 0x30]
    mulsd xmm0, xmm1
    cvttsd2si rax, xmm0
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short jbe L_0248
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
L_0248:
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    long jae L_036a
    long jp L_036a
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short jbe L_036a
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
L_036a:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short ja L_036a
L_039b:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short jp L_03cc
    short jb L_039b
L_03cc:
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x60]
    modrm cmp rax, rdx
    short jg L_0444
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x68], xmm0
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x68]
    movsd qword ptr [rax], xmm0
    long jmp L_036a
L_0444:
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x40]
    neg rdx
    add rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    short jle L_04b3
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x18]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    long jmp L_055a
L_04b3:
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x40]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x28]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x28], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_055a
L_0504:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    long je L_0e24
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
L_055a:
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jg L_0176
    mov rax, qword ptr [rbp + 0x18]
    cmp rax, 1
    long je L_0122
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
L_058b:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long je L_0504
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short jp L_05ee
    short jbe L_058b
L_05ee:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x40], rax
L_05f6:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    movsd xmm0, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm1, qword ptr [rax]
    comisd xmm0, xmm1
    short jp L_065c
    short jb L_05f6
L_065c:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    long jmp L_058b
L_0682:
    mov qword ptr [rbp + 0x20], 1
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x28], rax
    movsd xmm0, qword ptr [rip + reloc(.rdata, _2il0floatpacket.0 - .rdata)]
    movsd qword ptr [rbp + 0x30], xmm0
L_06a7:
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long je L_0c2f
    movsd xmm0, qword ptr [rbp + 0x30]
    movsd xmm1, qword ptr [rip + reloc(.rdata, _2il0floatpacket.1 - .rdata)]
    comisd xmm0, xmm1
    short ja L_06e5
    short jp L_06e5
    movsd xmm0, qword ptr [rip + reloc(.rdata, _2il0floatpacket.2 - .rdata)]
    movsd xmm1, qword ptr [rbp + 0x30]
    addsd xmm1, xmm0
    movsd qword ptr [rbp + 0x30], xmm1
    short jmp L_06fb
L_06e5:
    movsd xmm0, qword ptr [rip + reloc(.rdata, _2il0floatpacket.3 - .rdata)]
    movsd xmm1, qword ptr [rbp + 0x30]
    subsd xmm1, xmm0
    movsd qword ptr [rbp + 0x30], xmm1
L_06fb:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 0x28]
    cvtsi2sd xmm0, rax
    movsd xmm1, qword ptr [rbp + 0x30]
    mulsd xmm0, xmm1
    cvttsd2si rax, xmm0
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    long jbe L_084b
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
L_084b:
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    long jae L_0a31
    long jp L_0a31
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    long jbe L_0a31
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
L_0a31:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short ja L_0a31
L_0a62:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short jp L_0a93
    short jb L_0a62
L_0a93:
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x60]
    modrm cmp rax, rdx
    long jg L_0b6f
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x68], xmm0
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x68]
    movsd qword ptr [rax], xmm0
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x70]
    mov qword ptr [rax], rdx
    long jmp L_0a31
L_0b6f:
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x40]
    neg rdx
    add rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    short jle L_0bde
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x18]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    long jmp L_0c85
L_0bde:
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x40]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x28]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x28], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_0c85
L_0c2f:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    long je L_0e24
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
L_0c85:
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jg L_06fb
    mov rax, qword ptr [rbp + 0x18]
    cmp rax, 1
    long je L_06a7
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
L_0cb6:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long je L_0c2f
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x50], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x50]
    comisd xmm0, xmm1
    short jp L_0d3c
    long jbe L_0cb6
L_0d3c:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x40], rax
L_0d44:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    movsd xmm0, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm1, qword ptr [rax]
    comisd xmm0, xmm1
    short jp L_0ddf
    long jb L_0d44
L_0ddf:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x50]
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    long jmp L_0cb6
L_0e24:
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_0e9c
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x38], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x38]
    test rax, rax
    short jle L_0e9c
L_0e4c:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    xorpd xmm0, xmmword ptr [rip + reloc(.rdata, _2il0floatpacket.4 - .rdata)]
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x38]
    modrm cmp rax, rdx
    short jle L_0e4c
L_0e9c:
    lea rsp, [rbp + 0x1e0]
    pop rbp
    ret
end_SLATEC_DSORT:

SLATEC_ISORT:
    push rbp
pro_SLATEC_ISORT_01:
    sub rsp, 0x200
pro_SLATEC_ISORT_08:
    lea rbp, [rsp + 0x20]
pro_SLATEC_ISORT_0d:
    mov qword ptr [rbp + 0x1f0], rcx
    mov qword ptr [rbp + 0x1f8], rdx
    mov qword ptr [rbp + 0x200], r8
    mov qword ptr [rbp + 0x208], r9
    mov rax, qword ptr [rbp + 0x200]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    long jle L_1cab
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov rdx, rax
    sar rdx, 0x3f
    modrm xor rax, rdx
    modrm sub rax, rdx
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 1
    short je L_0f1c
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 2
    long jne L_1cab
L_0f1c:
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_0f8d
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    short jle L_0f8d
L_0f44:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    neg rax
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    short jle L_0f44
L_0f8d:
    mov rax, qword ptr [rbp + 0x10]
    cmp rax, 2
    long je L_14de
    mov qword ptr [rbp + 0x28], 1
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x30], rax
    movss xmm0, dword ptr [rip + reloc(.rdata, _2il0floatpacket.5 - .rdata)]
    movss dword ptr [rbp], xmm0
L_0fc0:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long je L_1370
    movss xmm0, dword ptr [rbp]
    movss xmm1, dword ptr [rip + reloc(.rdata, _2il0floatpacket.6 - .rdata)]
    comiss xmm0, xmm1
    short ja L_0ffd
    short jp L_0ffd
    movss xmm0, dword ptr [rip + reloc(.rdata, _2il0floatpacket.7 - .rdata)]
    movss xmm1, dword ptr [rbp]
    addss xmm1, xmm0
    movss dword ptr [rbp], xmm1
    short jmp L_1013
L_0ffd:
    movss xmm0, dword ptr [rip + reloc(.rdata, _2il0floatpacket.8 - .rdata)]
    movss xmm1, dword ptr [rbp]
    subss xmm1, xmm0
    movss dword ptr [rbp], xmm1
L_1013:
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x20]
    neg rax
    add rax, qword ptr [rbp + 0x30]
    cvtsi2ss xmm0, rax
    movss xmm1, dword ptr [rbp]
    mulss xmm0, xmm1
    cvttss2si rax, xmm0
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jle L_10da
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
L_10da:
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jge L_11e4
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jle L_11e4
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
L_11e4:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jg L_11e4
L_1212:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jl L_1212
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x60]
    modrm cmp rax, rdx
    short jg L_12b0
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x68], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x68]
    mov qword ptr [rax], rdx
    long jmp L_11e4
L_12b0:
    mov rax, qword ptr [rbp + 0x20]
    neg rax
    add rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x40]
    neg rdx
    add rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    short jle L_131f
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x20]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x20], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    long jmp L_13c6
L_131f:
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x40]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x30]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x30], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    short jmp L_13c6
L_1370:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long je L_1c3a
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
L_13c6:
    mov rax, qword ptr [rbp + 0x20]
    neg rax
    add rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jg L_1013
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 1
    long je L_0fc0
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_13f7:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long je L_1370
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jle L_13f7
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x40], rax
L_145b:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jl L_145b
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    long jmp L_13f7
L_14de:
    mov qword ptr [rbp + 0x28], 1
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x30], rax
    movss xmm0, dword ptr [rip + reloc(.rdata, _2il0floatpacket.5 - .rdata)]
    movss dword ptr [rbp], xmm0
L_1503:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long je L_1a59
    movss xmm0, dword ptr [rbp]
    movss xmm1, dword ptr [rip + reloc(.rdata, _2il0floatpacket.6 - .rdata)]
    comiss xmm0, xmm1
    short ja L_1540
    short jp L_1540
    movss xmm0, dword ptr [rip + reloc(.rdata, _2il0floatpacket.7 - .rdata)]
    movss xmm1, dword ptr [rbp]
    addss xmm1, xmm0
    movss dword ptr [rbp], xmm1
    short jmp L_1556
L_1540:
    movss xmm0, dword ptr [rip + reloc(.rdata, _2il0floatpacket.8 - .rdata)]
    movss xmm1, dword ptr [rbp]
    subss xmm1, xmm0
    movss dword ptr [rbp], xmm1
L_1556:
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x20]
    neg rax
    add rax, qword ptr [rbp + 0x30]
    cvtsi2ss xmm0, rax
    movss xmm1, dword ptr [rbp]
    mulss xmm0, xmm1
    cvttss2si rax, xmm0
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jle L_169b
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
L_169b:
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jge L_1869
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jle L_1869
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
L_1869:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jg L_1869
L_1897:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jl L_1897
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x60]
    modrm cmp rax, rdx
    long jg L_1999
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x68], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x68]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x70]
    mov qword ptr [rax], rdx
    long jmp L_1869
L_1999:
    mov rax, qword ptr [rbp + 0x20]
    neg rax
    add rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x40]
    neg rdx
    add rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    short jle L_1a08
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x20]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x60]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x20], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    long jmp L_1aaf
L_1a08:
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x40]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rdx, qword ptr [rbp + 0x30]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x30], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    short jmp L_1aaf
L_1a59:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long je L_1c3a
    lea rax, [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    lea rax, [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0x28]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
L_1aaf:
    mov rax, qword ptr [rbp + 0x20]
    neg rax
    add rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jg L_1556
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 1
    long je L_1503
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_1ae0:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long je L_1a59
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    short jle L_1ae0
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x40], rax
L_1b63:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f8]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x40]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    long jl L_1b63
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x58]
    mov qword ptr [rax], rdx
    long jmp L_1ae0
L_1c3a:
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_1cab
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x38], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x38]
    test rax, rax
    short jle L_1cab
L_1c62:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    neg rax
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x1f0]
    add rdx, -8
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x38]
    modrm cmp rax, rdx
    short jle L_1c62
L_1cab:
    lea rsp, [rbp + 0x1e0]
    pop rbp
    ret
end_SLATEC_ISORT:

.section .rdata 0x40500040
_2il0floatpacket.4:
    .zero 7
    .byte 0x80
    .zero 8
_2il0floatpacket.0:
    .zero 6
    .byte 0xd8, 0x3f
_2il0floatpacket.1:
    .byte 0x65, 0x0d, 0x28, 0xe5, 0xff, 0xdf, 0xe2, 0x3f
_2il0floatpacket.2:
    .zero 6
    .byte 0xa4, 0x3f
_2il0floatpacket.3:
    .zero 6
    .byte 0xcc, 0x3f
_2il0floatpacket.5:
    .zero 2
    .byte 0xc0, 0x3e
_2il0floatpacket.6:
    .byte 0xff, 0xff, 0x16, 0x3f
_2il0floatpacket.7:
    .zero 2
    .byte 0x20, 0x3d
_2il0floatpacket.8:
    .zero 2
    .byte 0x60, 0x3e

.section .xdata 0x40300040
unwind_SLATEC_DSORT:
    .unwind SLATEC_DSORT, pro_SLATEC_DSORT_0d, rbp, 32
        .set_fpreg pro_SLATEC_DSORT_0d
        .alloc_large pro_SLATEC_DSORT_08, 512
        .push_nonvol pro_SLATEC_DSORT_01, rbp
    .endunwind
unwind_SLATEC_ISORT:
    .unwind SLATEC_ISORT, pro_SLATEC_ISORT_0d, rbp, 32
        .set_fpreg pro_SLATEC_ISORT_0d
        .alloc_large pro_SLATEC_ISORT_08, 512
        .push_nonvol pro_SLATEC_ISORT_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva SLATEC_DSORT
    .rva SLATEC_DSORT, end_SLATEC_DSORT - SLATEC_DSORT
    .rva .xdata, unwind_SLATEC_DSORT - .xdata
    .rva SLATEC_ISORT
    .rva SLATEC_ISORT, end_SLATEC_ISORT - SLATEC_ISORT
    .rva .xdata, unwind_SLATEC_ISORT - .xdata

.section .drectve 0x00100a00
    .ascii "-export:SLATEC_ISORT  -export:SLATEC_DSORT  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\util.obj 1743626482
.index GETPOINTER
.index PUTPOINTER
.index U3NJAC_COMPUTE
.index U3VGRP_COMPUTE
.index U3VGRP_CREATE
.index U3VGRP_DESTROY
.index U3VGRP_READ_FM_FILE
.index U3VGRP_REPORT_BY_IDX
.index U3VGRP_SAVE_TO_FILE

.symbol .text section local
.symbol U3VGRP_CREATE function public
.symbol U3VGRP_DESTROY function public
.symbol U3VGRP_COMPUTE function public
.symbol U3NJAC_COMPUTE function public
.symbol U3VGRP_REPORT_BY_IDX function public
.symbol U3VGRP_SAVE_TO_FILE function public
.symbol U3VGRP_READ_FM_FILE function public
.symbol PUTPOINTER function public
.symbol GETPOINTER function public
.symbol OOMF_PLEX common public 128
.symbol .rdata section local
.symbol RTO_IMALLOC external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol __NLITPACK_0 data local
.symbol RTO_IFREE external public function
.symbol U3_SUP2 common public 1024
.symbol U3VFXD external public function
.symbol U3_KPR external public function
.symbol _2il0floatpacket.0 data local
.symbol .bss section local
.symbol RTO_DMALLOC external public function
.symbol RTO_DFREE external public function
.symbol U3VGPT external public function
.symbol U3NJAC_COMPUTE$NUMGRP data local
.symbol U3NJAC_COMPUTE$MARKER data local
.symbol U3NJAC_COMPUTE$LBF0 data local
.symbol U3NJAC_COMPUTE$LBDX data local
.symbol U3NJAC_COMPUTE$LBY0 data local
.symbol U3NJAC_COMPUTE$LBV2G data local
.symbol __STRLITPACK_3 data local
.symbol .data section local
.symbol for_write_int_fmt external public function
.symbol RTOHIS_WRITELN external public function
.symbol for_write_int_fmt_xmit external public function
.symbol U3VGRP_REPORT_BY_IDX$format_pack data local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_5 data local
.symbol __STRLITPACK_6 data local
.symbol __STRLITPACK_7 data local
.symbol __STRLITPACK_8 data local
.symbol __STRLITPACK_9 data local
.symbol __STRLITPACK_10 data local
.symbol __STRLITPACK_11 data local
.symbol for_write_seq external public function
.symbol for_write_seq_xmit external public function
.symbol __STRLITPACK_12 data local
.symbol __STRLITPACK_13 data local
.symbol __STRLITPACK_14 data local
.symbol __STRLITPACK_15 data local
.symbol __STRLITPACK_16 data local
.symbol __STRLITPACK_17 data local
.symbol for_read_seq external public function
.symbol for_read_seq_xmit external public function
.symbol __STRLITPACK_18 data local
.symbol __STRLITPACK_19 data local
.symbol __STRLITPACK_20 data local
.symbol __STRLITPACK_21 data local
.symbol __STRLITPACK_22 data local
.symbol __STRLITPACK_23 data local
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

U3VGRP_CREATE:
    push rbp
pro_U3VGRP_CREATE_01:
    sub rsp, 0x60
pro_U3VGRP_CREATE_05:
    lea rbp, [rsp + 0x20]
pro_U3VGRP_CREATE_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_01bc
    mov rax, qword ptr [rbp + 0x58]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_01bc
    mov rax, qword ptr [rbp + 0x60]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_01bc
    mov rax, qword ptr [rbp + 0x68]
    mov qword ptr [rax], 0
    lea rax, [rip + reloc(.rdata, __NLITPACK_0 - .rdata)]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rbp]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x68]
    mov ecx, 1
    add rcx, qword ptr [rdx]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x68]
    mov ecx, 2
    add rcx, qword ptr [rdx]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x68]
    mov edx, 3
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 2
    mov qword ptr [rbp + 8], rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0x68]
    mov ecx, 4
    add rcx, qword ptr [rdx]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    lea rdx, [rbp + 0x18]
    mov rcx, rax
    call reloc(PUTPOINTER)
    mov rax, qword ptr [rbp + 0x58]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rdx
    lea rax, [rbp + 0x20]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x30], rax
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0x68]
    mov ecx, 6
    add rcx, qword ptr [rdx]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    lea rdx, [rbp + 0x30]
    mov rcx, rax
    call reloc(PUTPOINTER)
L_01bc:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3VGRP_CREATE:

U3VGRP_DESTROY:
    push rbp
pro_U3VGRP_DESTROY_01:
    sub rsp, 0x30
pro_U3VGRP_DESTROY_05:
    lea rbp, [rsp + 0x20]
pro_U3VGRP_DESTROY_0a:
    mov qword ptr [rbp + 0x20], rcx
    mov rax, qword ptr [rbp + 0x20]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_027f
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0x20]
    mov ecx, 6
    add rcx, qword ptr [rdx]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov rcx, rax
    call reloc(GETPOINTER)
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    short je L_022e
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IFREE)
L_022e:
    mov rax, qword ptr [rbp + 0x20]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    short je L_0268
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IFREE)
L_0268:
    mov rax, qword ptr [rbp + 0x20]
    mov rcx, rax
    call reloc(RTO_IFREE)
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rax], 0
L_027f:
    lea rsp, [rbp + 0x10]
    pop rbp
    ret
end_U3VGRP_DESTROY:

U3VGRP_COMPUTE:
    push rbp
pro_U3VGRP_COMPUTE_01:
    sub rsp, 0x160
pro_U3VGRP_COMPUTE_08:
    lea rbp, [rsp + 0x70]
pro_U3VGRP_COMPUTE_0d:
    mov qword ptr [rbp + 0xe0], rdi
pro_U3VGRP_COMPUTE_14:
    mov qword ptr [rbp + 0xd8], rsi
pro_U3VGRP_COMPUTE_1b:
    mov qword ptr [rbp + 0xd0], rbx
pro_U3VGRP_COMPUTE_22:
    mov qword ptr [rbp + 0x100], rcx
    mov qword ptr [rbp + 0x108], rdx
    mov qword ptr [rbp + 0x110], r8
    mov qword ptr [rbp + 0x118], r9
    mov rax, qword ptr [rbp + 0x138]
    mov qword ptr [rax], 1
    mov rax, qword ptr [rbp + 0x130]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_0ac3
    mov rax, qword ptr [rbp + 0x130]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x130]
    mov edx, 1
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x130]
    mov edx, 2
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 8]
    or rax, qword ptr [rbp]
    long jl L_0ac3
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    long jl L_0ac3
    mov rax, qword ptr [rbp + 0x138]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    long je L_0ac3
    mov rax, qword ptr [rbp + 0x118]
    mov rax, qword ptr [rax]
    test rax, rax
    short jl L_03ab
    mov rax, qword ptr [rbp + 0x120]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_03be
L_03ab:
    mov rax, qword ptr [rbp + 0x138]
    mov qword ptr [rax], 1
    long jmp L_0ac3
L_03be:
    mov rax, qword ptr [rbp + 0x118]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0439
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    short jle L_0439
L_03e6:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x100]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x118]
    mov rdx, qword ptr [rdx]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x100]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    short jle L_03e6
L_0439:
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_05e8
L_0456:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x120]
    mov rdx, qword ptr [rdx]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short jle L_04cd
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp]
    modrm cmp rax, rdx
    long jle L_05ca
L_04cd:
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x48], rax
    mov qword ptr [rbp + 0x50], 1
    mov rax, qword ptr [rbp + 0x48]
    test rax, rax
    short jle L_0536
L_04e6:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x120]
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x48]
    modrm cmp rax, rdx
    short jle L_04e6
L_0536:
    mov rax, qword ptr [rbp + 0x118]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_05b7
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x80], rax
    mov qword ptr [rbp + 0x50], 1
    mov rax, qword ptr [rbp + 0x80]
    test rax, rax
    short jle L_05b7
L_0564:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x100]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x118]
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x100]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x80]
    modrm cmp rax, rdx
    short jle L_0564
L_05b7:
    mov rax, qword ptr [rbp + 0x138]
    mov qword ptr [rax], 2
    long jmp L_0ac3
L_05ca:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_0456
L_05e8:
    lea rax, [rbp + 0x10]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x58], rax
    mov eax, 1
    add rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x60], rax
    lea rax, [rbp + 0x60]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x68], rax
    mov rax, qword ptr [rbp + 0x68]
    mov qword ptr [rbp + 0x70], rax
    lea rax, [rbp]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x78], rax
    mov rax, qword ptr [rbp + 0x78]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x10]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x128]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_06f5
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0xa0], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0xa0]
    test rax, rax
    long jle L_07d5
L_06ab:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0xa0]
    modrm cmp rax, rdx
    short jle L_06ab
    long jmp L_07d5
L_06f5:
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0xa8], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0xa8]
    test rax, rax
    long jle L_07d5
L_0718:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x108]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x110]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0xb0], rax
    mov eax, dword ptr [rbp + 0xb0]
    test al, 1
    short je L_078c
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 1
    short jmp L_07b4
L_078c:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
L_07b4:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0xa8]
    modrm cmp rax, rdx
    long jle L_0718
L_07d5:
    mov qword ptr [rip + reloc(U3_SUP2, 0x80)], 2
    lea rax, [rbp + 8]
    lea rdx, [rbp]
    lea rcx, [rbp + 0x10]
    mov rbx, qword ptr [rbp + 0x100]
    mov rsi, qword ptr [rbp + 0x108]
    mov qword ptr [rsp + 0x20], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x38]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x28], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x130]
    mov r8d, 4
    add r8, qword ptr [rdi]
    imul rdi, r8, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    add r8, -8
    mov rdi, qword ptr [r8]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x30], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x130]
    mov r8d, 3
    add r8, qword ptr [rdi]
    imul rdi, r8, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x38], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x58]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x40], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x130]
    mov r8d, 6
    add r8, qword ptr [rdi]
    imul rdi, r8, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    add r8, -8
    mov rdi, qword ptr [r8]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x48], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x70]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x50], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x88]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x58], rsi
    mov esi, 8
    neg rsi
    mov rdi, qword ptr [rbp + 0x98]
    imul rdi, rdi, 8
    lea r8, [rip + reloc(OOMF_PLEX)]
    modrm add r8, rdi
    modrm add rsi, r8
    mov qword ptr [rsp + 0x60], rsi
    mov qword ptr [rbp + 0xc8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xc8]
    mov r8, rax
    mov r9, rbx
    call reloc(U3_KPR)
    mov rax, qword ptr [rbp + 0x118]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0a00
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0xb8], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0xb8]
    test rax, rax
    short jle L_0a00
L_09ad:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x100]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x118]
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x100]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0xb8]
    modrm cmp rax, rdx
    short jle L_09ad
L_0a00:
    mov rax, qword ptr [rbp + 0x120]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0a81
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0xc0], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0xc0]
    test rax, rax
    short jle L_0a81
L_0a2e:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x120]
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0xc0]
    modrm cmp rax, rdx
    short jle L_0a2e
L_0a81:
    lea rax, [rbp + 0x98]
    mov rcx, rax
    call reloc(RTO_IFREE)
    lea rax, [rbp + 0x88]
    mov rcx, rax
    call reloc(RTO_IFREE)
    lea rax, [rbp + 0x70]
    mov rcx, rax
    call reloc(RTO_IFREE)
    lea rax, [rbp + 0x58]
    mov rcx, rax
    call reloc(RTO_IFREE)
    lea rax, [rbp + 0x38]
    mov rcx, rax
    call reloc(RTO_IFREE)
L_0ac3:
    mov rbx, qword ptr [rbp + 0xd0]
    mov rsi, qword ptr [rbp + 0xd8]
    mov rdi, qword ptr [rbp + 0xe0]
    lea rsp, [rbp + 0xf0]
    pop rbp
    ret
end_U3VGRP_COMPUTE:

U3NJAC_COMPUTE:
    push rbp
pro_U3NJAC_COMPUTE_01:
    sub rsp, 0x110
pro_U3NJAC_COMPUTE_08:
    lea rbp, [rsp + 0x20]
pro_U3NJAC_COMPUTE_0d:
    mov qword ptr [rbp + 0x100], rcx
    mov qword ptr [rbp + 0x108], rdx
    mov qword ptr [rbp + 0x110], r8
    mov qword ptr [rbp + 0x118], r9
    mov rax, qword ptr [rbp + 0x158]
    mov qword ptr [rax], 1
    mov rax, qword ptr [rbp + 0x100]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_159d
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 3
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 1
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x100]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 2
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp]
    test rax, rax
    long jl L_159d
    mov rax, qword ptr [rbp + 8]
    or rax, qword ptr [rbp + 0x10]
    long jl L_159d
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    long jl L_159d
    mov rax, qword ptr [rbp + 0x158]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    long je L_159d
    mov rax, qword ptr [rbp + 0x150]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0c41
    mov rax, qword ptr [rbp + 0x150]
    mov qword ptr [rax], 1
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$NUMGRP - .bss)], 0
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$MARKER - .bss)], 1
    long jmp L_159d
L_0c41:
    mov rax, qword ptr [rbp + 0x150]
    mov rax, qword ptr [rax]
    cmp rax, 1
    long jne L_159d
    mov rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$NUMGRP - .bss)]
    test rax, rax
    long jne L_0f0f
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_DMALLOC)
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBF0 - .bss)], rax
    lea rax, [rbp + 0x10]
    mov rcx, rax
    call reloc(RTO_DMALLOC)
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBDX - .bss)], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x90], rax
    mov qword ptr [rbp + 0x60], 1
    mov rax, qword ptr [rbp + 0x90]
    test rax, rax
    short jle L_0d16
L_0cba:
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x120]
    add rax, -8
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBF0 - .bss)]
    add rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rcx], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x90]
    modrm cmp rax, rdx
    short jle L_0cba
L_0d16:
    lea rax, [rbp + 0x10]
    mov rcx, rax
    call reloc(RTO_DMALLOC)
    mov qword ptr [rbp + 0xa0], rax
    mov rax, qword ptr [rbp + 0xa0]
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBY0 - .bss)], rax
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0xb0], rax
    mov qword ptr [rbp + 0x60], 1
    mov rax, qword ptr [rbp + 0xb0]
    test rax, rax
    short jle L_0db2
L_0d56:
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBY0 - .bss)]
    add rdx, qword ptr [rbp + 0x60]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rcx], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0xb0]
    modrm cmp rax, rdx
    short jle L_0d56
L_0db2:
    lea rax, [rbp + 0x10]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0xc0], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBV2G - .bss)], rax
    mov qword ptr [rbp + 0xd0], 1
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0xd8], rax
    mov qword ptr [rbp + 0x60], 1
    mov rax, qword ptr [rbp + 0xd8]
    test rax, rax
    long jle L_12f3
L_0e01:
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rdx]
    add rax, qword ptr [rbp + 0xd0]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0xe8], rax
    mov qword ptr [rbp + 0x38], 1
    mov rax, qword ptr [rbp + 0xe8]
    test rax, rax
    short jle L_0ed4
L_0e73:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBV2G - .bss)]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    add rax, qword ptr [rcx]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0xe8]
    modrm cmp rax, rdx
    short jle L_0e73
L_0ed4:
    mov rax, qword ptr [rbp + 0x50]
    add rax, qword ptr [rbp + 0xd0]
    inc rax
    mov qword ptr [rbp + 0xd0], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0xd8]
    modrm cmp rax, rdx
    long jle L_0e01
    long jmp L_12f3
L_0f0f:
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 6
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x30], rax
    mov qword ptr [rbp + 0x38], 1
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jle L_1109
L_0f54:
    mov rax, qword ptr [rbp + 0x38]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x120]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBF0 - .bss)]
    dec rdx
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rcx]
    subsd xmm0, xmm1
    movsd qword ptr [rbp + 0x68], xmm0
    mov rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x28]
    dec rax
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x78], rax
    mov rax, qword ptr [rbp + 0x78]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x70]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x70]
    modrm cmp rax, rdx
    long jl L_10eb
L_100e:
    mov rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x130]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x128]
    mov rdx, qword ptr [rdx]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x98], rdx
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBV2G - .bss)]
    add rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov rdx, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$NUMGRP - .bss)]
    modrm cmp rax, rdx
    short jne L_10c1
    movsd xmm0, qword ptr [rbp + 0x68]
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBDX - .bss)]
    add rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    mov rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x148]
    add rax, -8
    movsd qword ptr [rax], xmm0
    short jmp L_10eb
L_10c1:
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x80]
    modrm cmp rax, rdx
    long jle L_100e
L_10eb:
    mov eax, 1
    add rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long jle L_0f54
L_1109:
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rdx]
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$MARKER - .bss)]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x58], rax
    mov qword ptr [rbp + 0x60], 1
    mov rax, qword ptr [rbp + 0x58]
    test rax, rax
    long jle L_1200
L_1179:
    mov rax, qword ptr [rbp + 0x60]
    add rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x98], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBY0 - .bss)]
    add rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    movsd xmm0, qword ptr [rdx]
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x58]
    modrm cmp rax, rdx
    long jle L_1179
L_1200:
    mov rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$NUMGRP - .bss)]
    mov rdx, qword ptr [rbp]
    modrm cmp rax, rdx
    long jne L_12de
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0xa8], rax
    mov qword ptr [rbp + 0x60], 1
    mov rax, qword ptr [rbp + 0xa8]
    test rax, rax
    short jle L_128f
L_1233:
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBF0 - .bss)]
    add rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x60]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x120]
    add rax, -8
    movsd xmm0, qword ptr [rdx]
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0xa8]
    modrm cmp rax, rdx
    short jle L_1233
L_128f:
    lea rax, [rip + reloc(.bss, U3NJAC_COMPUTE$LBF0 - .bss)]
    mov rcx, rax
    call reloc(RTO_DFREE)
    lea rax, [rip + reloc(.bss, U3NJAC_COMPUTE$LBY0 - .bss)]
    mov rcx, rax
    call reloc(RTO_DFREE)
    lea rax, [rip + reloc(.bss, U3NJAC_COMPUTE$LBDX - .bss)]
    mov rcx, rax
    call reloc(RTO_DFREE)
    lea rax, [rip + reloc(.bss, U3NJAC_COMPUTE$LBV2G - .bss)]
    mov rcx, rax
    call reloc(RTO_IFREE)
    mov rax, qword ptr [rbp + 0x150]
    mov qword ptr [rax], 2
    long jmp L_159d
L_12de:
    mov rax, qword ptr [rbp + 0x50]
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$MARKER - .bss)]
    inc rax
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$MARKER - .bss)], rax
L_12f3:
    mov eax, 1
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$NUMGRP - .bss)]
    mov qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$NUMGRP - .bss)], rax
    mov rax, qword ptr [rbp + 0x100]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rdx]
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$MARKER - .bss)]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0xb8], rax
    mov qword ptr [rbp + 0x60], 1
    mov rax, qword ptr [rbp + 0xb8]
    test rax, rax
    long jle L_158f
L_137c:
    mov rax, qword ptr [rbp + 0x60]
    add rax, qword ptr [rbp + 0x48]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x98], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x98]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x118]
    modrm add rax, rdx
    lea rdx, [rbp + 0xc8]
    mov rcx, rax
    call reloc(U3VGPT)
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x138]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x110]
    add rax, -8
    movsd xmm1, qword ptr [rax]
    mulsd xmm0, xmm1
    movsd qword ptr [rbp + 0xe0], xmm0
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    andpd xmm0, xmmword ptr [rip + reloc(.rdata, _2il0floatpacket.0 - .rdata)]
    movsd xmm1, qword ptr [rbp + 0xe0]
    comisd xmm0, xmm1
    short jae L_1499
    short jp L_1499
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0xe0]
    mov rdx, qword ptr [rbp + 0x140]
    movsd xmm1, qword ptr [rdx]
    mulsd xmm0, xmm1
    movsd xmm1, qword ptr [rax]
    addsd xmm1, xmm0
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    movsd qword ptr [rax], xmm1
    short jmp L_14fa
L_1499:
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x98]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x108]
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    mov rdx, qword ptr [rbp + 0x140]
    movsd xmm1, qword ptr [rdx]
    mulsd xmm0, xmm1
    movsd xmm1, qword ptr [rax]
    addsd xmm1, xmm0
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    movsd qword ptr [rax], xmm1
L_14fa:
    mov rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x108]
    add rax, -8
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBY0 - .bss)]
    add rdx, qword ptr [rbp + 0x98]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rcx]
    subsd xmm0, xmm1
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rip + reloc(.bss, U3NJAC_COMPUTE$LBDX - .bss)]
    add rax, qword ptr [rbp + 0x98]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd qword ptr [rdx], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0xb8]
    modrm cmp rax, rdx
    long jle L_137c
L_158f:
    mov rax, qword ptr [rbp + 0x150]
    mov qword ptr [rax], 1
L_159d:
    lea rsp, [rbp + 0xf0]
    pop rbp
    ret
end_U3NJAC_COMPUTE:

U3VGRP_REPORT_BY_IDX:
    push rbp
pro_U3VGRP_REPORT_BY_IDX_01:
    sub rsp, 0x1d0
pro_U3VGRP_REPORT_BY_IDX_08:
    lea rbp, [rsp + 0x30]
pro_U3VGRP_REPORT_BY_IDX_0d:
    mov qword ptr [rbp + 0x198], rsi
pro_U3VGRP_REPORT_BY_IDX_14:
    mov qword ptr [rbp + 0x190], rbx
pro_U3VGRP_REPORT_BY_IDX_1b:
    mov qword ptr [rbp + 0x1b0], rcx
    mov qword ptr [rbp + 0x1b8], rdx
    mov rax, qword ptr [rbp + 0x1b0]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_1b91
    mov rax, qword ptr [rbp + 0x1b8]
    mov rax, qword ptr [rax]
    test rax, rax
    long jl L_1b91
    mov rax, qword ptr [rbp + 0x1b0]
    mov edx, 3
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    test rax, rax
    long jle L_1b91
    mov rax, qword ptr [rbp + 0x1b0]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x58]
    test rax, rax
    long je L_1b91
    mov qword ptr [rbp + 0x60], 0
    mov qword ptr [rbp + 0x90], 0x50
    lea rax, [rbp]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0xa0], rax
    lea rax, [rbp + 0x60]
    mov rdx, 0x801208384ff00
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    lea rbx, [rbp + 0x90]
    lea rsi, [rip + reloc(.data, U3VGRP_REPORT_BY_IDX$format_pack - .data)]
    add rsi, 0x8c
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x148], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x148]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_int_fmt)
    lea rax, [rbp]
    mov edx, 0x50
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov qword ptr [rbp + 0xa8], 1
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0xb0], rax
    mov qword ptr [rbp + 0xb8], 1
    mov rax, qword ptr [rbp + 0xb0]
    test rax, rax
    long jle L_1b7d
L_171c:
    mov rax, qword ptr [rbp + 0xa8]
    add rax, qword ptr [rbp + 0x58]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0xc0], rax
    mov rax, qword ptr [rbp + 0xc0]
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xc8], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, 0x4924924924924925
    mov qword ptr [rbp + 0x150], rax
    mov rax, rdx
    mov rdx, qword ptr [rbp + 0x150]
    imul rdx
    sar rdx, 1
    mov rax, qword ptr [rbp + 0xc0]
    sar rax, 0x3f
    modrm sub rdx, rax
    inc rdx
    mov qword ptr [rbp + 0xd0], rdx
    mov qword ptr [rbp + 0xd8], 1
    mov rax, qword ptr [rbp + 0xd0]
    test rax, rax
    long jle L_1b40
L_17b3:
    mov eax, 1
    add rax, qword ptr [rbp + 0xa8]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rbp + 0xd8]
    imul rdx, rdx, 6
    modrm add rax, rdx
    mov qword ptr [rbp + 0xe0], rax
    mov rax, qword ptr [rbp + 0xe0]
    neg rax
    add rax, qword ptr [rbp + 0xc8]
    cmp rax, 5
    short jge L_180c
    mov rax, qword ptr [rbp + 0xe0]
    neg rax
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xe8], rax
    short jmp L_1817
L_180c:
    mov qword ptr [rbp + 0xe8], 5
L_1817:
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xe0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0xd8]
    cmp rax, 1
    long jne L_19c1
    mov qword ptr [rbp + 0x60], 0
    mov qword ptr [rbp + 0xf8], 0x50
    lea rax, [rbp]
    mov qword ptr [rbp + 0x100], rax
    mov rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0x108], rax
    lea rax, [rbp + 0x60]
    mov rdx, 0x801208384ff00
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_5 - .rdata)]
    lea rbx, [rbp + 0xf8]
    lea rsi, [rip + reloc(.data, U3VGRP_REPORT_BY_IDX$format_pack - .data)]
    add rsi, 0x34
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x158], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x158]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_int_fmt)
    lea rax, [rbp + 0x60]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_6 - .rdata)]
    mov ecx, 0
    mov qword ptr [rbp + 0x160], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x160]
    mov r8, rax
    call reloc(for_write_int_fmt_xmit)
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0x130], rax
    mov rax, qword ptr [rbp + 0xe0]
    mov qword ptr [rbp + 0x128], rax
    mov rax, qword ptr [rbp + 0x130]
    mov rdx, qword ptr [rbp + 0xe0]
    modrm cmp rax, rdx
    long jl L_1993
L_190d:
    mov rax, qword ptr [rbp + 0x1b8]
    mov rdx, qword ptr [rbp + 0x128]
    add rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rdx, qword ptr [rcx]
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x140], rdx
    lea rax, [rbp + 0x60]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    lea rcx, [rbp + 0x140]
    mov qword ptr [rbp + 0x168], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x168]
    mov r8, rax
    call reloc(for_write_int_fmt_xmit)
    mov eax, 1
    add rax, qword ptr [rbp + 0x128]
    mov qword ptr [rbp + 0x128], rax
    mov rax, qword ptr [rbp + 0x128]
    mov rdx, qword ptr [rbp + 0x130]
    modrm cmp rax, rdx
    long jle L_190d
L_1993:
    lea rax, [rbp + 0x60]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_8 - .rdata)]
    mov ecx, 0
    mov qword ptr [rbp + 0x170], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x170]
    mov r8, rax
    call reloc(for_write_int_fmt_xmit)
    long jmp L_1b05
L_19c1:
    mov qword ptr [rbp + 0x60], 0
    mov qword ptr [rbp + 0x110], 0x50
    lea rax, [rbp]
    mov qword ptr [rbp + 0x118], rax
    lea rax, [rbp + 0x60]
    mov rdx, 0x801208384ff00
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_9 - .rdata)]
    lea rbx, [rbp + 0x110]
    lea rsi, [rip + reloc(.data, U3VGRP_REPORT_BY_IDX$format_pack - .data)]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x178], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x178]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_int_fmt)
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0x120], rax
    mov rax, qword ptr [rbp + 0xe0]
    mov qword ptr [rbp + 0x128], rax
    mov rax, qword ptr [rbp + 0x120]
    mov rdx, qword ptr [rbp + 0xe0]
    modrm cmp rax, rdx
    long jl L_1adc
L_1a56:
    mov rax, qword ptr [rbp + 0x1b8]
    mov rdx, qword ptr [rbp + 0x128]
    add rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rdx, qword ptr [rcx]
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x138], rdx
    lea rax, [rbp + 0x60]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_10 - .rdata)]
    lea rcx, [rbp + 0x138]
    mov qword ptr [rbp + 0x180], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x180]
    mov r8, rax
    call reloc(for_write_int_fmt_xmit)
    mov eax, 1
    add rax, qword ptr [rbp + 0x128]
    mov qword ptr [rbp + 0x128], rax
    mov rax, qword ptr [rbp + 0x128]
    mov rdx, qword ptr [rbp + 0x120]
    modrm cmp rax, rdx
    long jle L_1a56
L_1adc:
    lea rax, [rbp + 0x60]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_11 - .rdata)]
    mov ecx, 0
    mov qword ptr [rbp + 0x188], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x188]
    mov r8, rax
    call reloc(for_write_int_fmt_xmit)
L_1b05:
    lea rax, [rbp]
    mov edx, 0x50
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 1
    add rax, qword ptr [rbp + 0xd8]
    mov qword ptr [rbp + 0xd8], rax
    mov rax, qword ptr [rbp + 0xd8]
    mov rdx, qword ptr [rbp + 0xd0]
    modrm cmp rax, rdx
    long jle L_17b3
L_1b40:
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xa8], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 0xb0]
    modrm cmp rax, rdx
    long jle L_171c
L_1b7d:
    lea rax, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    mov edx, 1
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
L_1b91:
    mov rbx, qword ptr [rbp + 0x190]
    mov rsi, qword ptr [rbp + 0x198]
    lea rsp, [rbp + 0x1a0]
    pop rbp
    ret
end_U3VGRP_REPORT_BY_IDX:

U3VGRP_SAVE_TO_FILE:
    push rbp
pro_U3VGRP_SAVE_TO_FILE_01:
    sub rsp, 0x120
pro_U3VGRP_SAVE_TO_FILE_08:
    lea rbp, [rsp + 0x30]
pro_U3VGRP_SAVE_TO_FILE_0d:
    mov qword ptr [rbp + 0xe0], rsi
pro_U3VGRP_SAVE_TO_FILE_14:
    mov qword ptr [rbp + 0xd8], rbx
pro_U3VGRP_SAVE_TO_FILE_1b:
    mov qword ptr [rbp + 0x100], rcx
    mov qword ptr [rbp + 0x108], rdx
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_1f6d
    mov rax, qword ptr [rbp + 0x108]
    mov edx, 3
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x108]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x108]
    mov edx, 1
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x108]
    mov edx, 2
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x50], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x100]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_12 - .rdata)]
    lea rsi, [rbp + 0x50]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xa8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq)
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x58], rax
    lea rax, [rbp + 0x20]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_13 - .rdata)]
    lea rcx, [rbp + 0x58]
    mov qword ptr [rbp + 0xb0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb0]
    mov r8, rax
    call reloc(for_write_seq_xmit)
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x60], rax
    lea rax, [rbp + 0x20]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_14 - .rdata)]
    lea rcx, [rbp + 0x60]
    mov qword ptr [rbp + 0xb8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb8]
    mov r8, rax
    call reloc(for_write_seq_xmit)
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x68], rax
    lea rax, [rbp + 0x20]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_15 - .rdata)]
    lea rcx, [rbp + 0x68]
    mov qword ptr [rbp + 0xc0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xc0]
    mov r8, rax
    call reloc(for_write_seq_xmit)
    mov rax, qword ptr [rbp + 0x108]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x70]
    test rax, rax
    long je L_1e5e
    mov rax, qword ptr [rbp + 8]
    imul rax, rax, 2
    mov qword ptr [rbp + 0x78], rax
    mov qword ptr [rbp + 0x80], 1
    mov rax, qword ptr [rbp + 0x78]
    test rax, rax
    long jle L_1e5e
L_1dbb:
    mov qword ptr [rbp + 0x20], 0
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x70]
    add rax, qword ptr [rbp + 0x80]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x90], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x100]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_16 - .rdata)]
    lea rsi, [rbp + 0x90]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xc8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xc8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq)
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x78]
    modrm cmp rax, rdx
    long jle L_1dbb
L_1e5e:
    mov rax, qword ptr [rbp + 0x108]
    mov edx, 6
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x88]
    test rax, rax
    long je L_1f6d
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x98], rax
    mov qword ptr [rbp + 0x80], 1
    mov rax, qword ptr [rbp + 0x98]
    test rax, rax
    long jle L_1f6d
L_1ec4:
    mov qword ptr [rbp + 0x20], 0
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x88]
    add rax, qword ptr [rbp + 0x80]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0xa0], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x100]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_17 - .rdata)]
    lea rsi, [rbp + 0xa0]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xd0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xd0]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq)
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x98]
    modrm cmp rax, rdx
    long jle L_1ec4
L_1f6d:
    mov rbx, qword ptr [rbp + 0xd8]
    mov rsi, qword ptr [rbp + 0xe0]
    lea rsp, [rbp + 0xf0]
    pop rbp
    ret
end_U3VGRP_SAVE_TO_FILE:

U3VGRP_READ_FM_FILE:
    push rbp
pro_U3VGRP_READ_FM_FILE_01:
    sub rsp, 0x130
pro_U3VGRP_READ_FM_FILE_08:
    lea rbp, [rsp + 0x30]
pro_U3VGRP_READ_FM_FILE_0d:
    mov qword ptr [rbp + 0xf8], rsi
pro_U3VGRP_READ_FM_FILE_14:
    mov qword ptr [rbp + 0xf0], rbx
pro_U3VGRP_READ_FM_FILE_1b:
    mov qword ptr [rbp + 0x110], rcx
    mov qword ptr [rbp + 0x118], rdx
    mov rax, qword ptr [rbp + 0x118]
    mov qword ptr [rax], 0
    mov qword ptr [rbp], 0
    lea rax, [rbp + 0x30]
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x110]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_18 - .rdata)]
    lea rsi, [rbp + 0x38]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xb8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_seq)
    lea rax, [rbp + 0x40]
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_19 - .rdata)]
    lea rcx, [rbp + 0x48]
    mov qword ptr [rbp + 0xc0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xc0]
    mov r8, rax
    call reloc(for_read_seq_xmit)
    lea rax, [rbp + 0x50]
    mov qword ptr [rbp + 0x58], rax
    lea rax, [rbp]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_20 - .rdata)]
    lea rcx, [rbp + 0x58]
    mov qword ptr [rbp + 0xc8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xc8]
    mov r8, rax
    call reloc(for_read_seq_xmit)
    lea rax, [rbp + 0x60]
    mov qword ptr [rbp + 0x68], rax
    lea rax, [rbp]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_21 - .rdata)]
    lea rcx, [rbp + 0x68]
    mov qword ptr [rbp + 0xd0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xd0]
    mov r8, rax
    call reloc(for_read_seq_xmit)
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jl L_2356
    mov rax, qword ptr [rbp + 0x50]
    or rax, qword ptr [rbp + 0x40]
    long jl L_2356
    mov rax, qword ptr [rbp + 0x60]
    test rax, rax
    long jl L_2356
    lea rax, [rbp + 0x40]
    lea rdx, [rbp + 0x50]
    lea rcx, [rbp + 0x60]
    mov rbx, qword ptr [rbp + 0x118]
    mov qword ptr [rbp + 0xd8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xd8]
    mov r8, rax
    mov r9, rbx
    call reloc(U3VGRP_CREATE)
    mov rax, qword ptr [rbp + 0x118]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_2356
    mov rax, qword ptr [rbp + 0x118]
    mov edx, 3
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x118]
    mov edx, 4
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x70]
    test rax, rax
    long je L_223b
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 2
    mov qword ptr [rbp + 0x78], rax
    mov qword ptr [rbp + 0x80], 1
    mov rax, qword ptr [rbp + 0x78]
    test rax, rax
    long jle L_223b
L_2189:
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 0x90], 8
    mov eax, 8
    neg rax
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rbp + 0x70]
    add rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov qword ptr [rbp + 0x98], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x110]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_22 - .rdata)]
    lea rsi, [rbp + 0x90]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xe0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xe0]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_seq)
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x78]
    modrm cmp rax, rdx
    long jle L_2189
L_223b:
    mov rax, qword ptr [rbp + 0x118]
    mov edx, 6
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x70]
    test rax, rax
    long je L_2356
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0xa0], rax
    mov qword ptr [rbp + 0x80], 1
    mov rax, qword ptr [rbp + 0xa0]
    test rax, rax
    long jle L_2356
L_229e:
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 0xa8], 8
    mov eax, 8
    neg rax
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rbp + 0x88]
    add rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov qword ptr [rbp + 0xb0], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x110]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_23 - .rdata)]
    lea rsi, [rbp + 0xa8]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xe8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xe8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_seq)
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0xa0]
    modrm cmp rax, rdx
    long jle L_229e
L_2356:
    mov rbx, qword ptr [rbp + 0xf0]
    mov rsi, qword ptr [rbp + 0xf8]
    lea rsp, [rbp + 0x100]
    pop rbp
    ret
end_U3VGRP_READ_FM_FILE:

PUTPOINTER:
    push rbp
pro_PUTPOINTER_01:
    sub rsp, 0x20
pro_PUTPOINTER_05:
    lea rbp, [rsp + 0x20]
pro_PUTPOINTER_0a:
    mov qword ptr [rbp + 0x10], rcx
    mov qword ptr [rbp + 0x18], rdx
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    lea rsp, [rbp]
    pop rbp
    ret
end_PUTPOINTER:

GETPOINTER:
    push rbp
pro_GETPOINTER_01:
    sub rsp, 0x30
pro_GETPOINTER_05:
    lea rbp, [rsp + 0x20]
pro_GETPOINTER_0a:
    mov qword ptr [rbp + 0x20], rcx
    mov rax, qword ptr [rbp + 0x20]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    lea rsp, [rbp + 0x10]
    pop rbp
    ret
end_GETPOINTER:
    nop
    nop

.section .rdata 0x40500040
__NLITPACK_0:
    .byte 0x08
    .zero 15
_2il0floatpacket.0:
    .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f
    .zero 8
__STRLITPACK_3:
    .byte 0x20
    .zero 3
__STRLITPACK_4:
    .byte 0x38, 0x04, 0x0b, 0x01, 0x01
    .zero 3
__STRLITPACK_5:
    .byte 0x38, 0x04, 0x0b, 0x01, 0x02
    .zero 3
__STRLITPACK_6:
    .byte 0x02, 0x00, 0x0b, 0x00
__STRLITPACK_7:
    .byte 0x0b, 0x01, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_8:
    .byte 0x01, 0x00, 0x02, 0x00
__STRLITPACK_9:
    .byte 0x38, 0x04, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_10:
    .byte 0x0b, 0x01, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_11:
    .byte 0x01, 0x00, 0x02, 0x00
__STRLITPACK_12:
    .byte 0x0b, 0x01, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_13:
    .byte 0x0b, 0x01, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_14:
    .byte 0x0b, 0x01, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_15:
    .byte 0x0b, 0x01, 0x01, 0x00, 0x02
    .zero 3
__STRLITPACK_16:
    .byte 0x0b, 0x01, 0x01, 0x00, 0x02
    .zero 3
__STRLITPACK_17:
    .byte 0x0b, 0x01, 0x01, 0x00, 0x02
    .zero 3
__STRLITPACK_18:
    .byte 0x0b, 0x03, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_19:
    .byte 0x0b, 0x03, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_20:
    .byte 0x0b, 0x03, 0x02, 0x00, 0x02
    .zero 3
__STRLITPACK_21:
    .byte 0x0b, 0x03, 0x01, 0x00, 0x02
    .zero 3
__STRLITPACK_22:
    .byte 0x0b, 0x05, 0x01, 0x00, 0x02
    .zero 3
__STRLITPACK_23:
    .byte 0x0b, 0x05, 0x01, 0x00, 0x02
    .zero 11

.section .xdata 0x40300040
unwind_U3VGRP_CREATE:
    .unwind U3VGRP_CREATE, pro_U3VGRP_CREATE_0a, rbp, 32
        .set_fpreg pro_U3VGRP_CREATE_0a
        .alloc_small pro_U3VGRP_CREATE_05, 96
        .push_nonvol pro_U3VGRP_CREATE_01, rbp
    .endunwind
unwind_U3VGRP_DESTROY:
    .unwind U3VGRP_DESTROY, pro_U3VGRP_DESTROY_0a, rbp, 32
        .set_fpreg pro_U3VGRP_DESTROY_0a
        .alloc_small pro_U3VGRP_DESTROY_05, 48
        .push_nonvol pro_U3VGRP_DESTROY_01, rbp
    .endunwind
unwind_U3VGRP_COMPUTE:
    .unwind U3VGRP_COMPUTE, pro_U3VGRP_COMPUTE_22, rbp, 112
        .save_nonvol pro_U3VGRP_COMPUTE_22, rbx, 320
        .save_nonvol pro_U3VGRP_COMPUTE_1b, rsi, 328
        .save_nonvol pro_U3VGRP_COMPUTE_14, rdi, 336
        .set_fpreg pro_U3VGRP_COMPUTE_0d
        .alloc_large pro_U3VGRP_COMPUTE_08, 352
        .push_nonvol pro_U3VGRP_COMPUTE_01, rbp
    .endunwind
unwind_U3NJAC_COMPUTE:
    .unwind U3NJAC_COMPUTE, pro_U3NJAC_COMPUTE_0d, rbp, 32
        .set_fpreg pro_U3NJAC_COMPUTE_0d
        .alloc_large pro_U3NJAC_COMPUTE_08, 272
        .push_nonvol pro_U3NJAC_COMPUTE_01, rbp
    .endunwind
unwind_U3VGRP_REPORT_BY_IDX:
    .unwind U3VGRP_REPORT_BY_IDX, pro_U3VGRP_REPORT_BY_IDX_1b, rbp, 48
        .save_nonvol pro_U3VGRP_REPORT_BY_IDX_1b, rbx, 448
        .save_nonvol pro_U3VGRP_REPORT_BY_IDX_14, rsi, 456
        .set_fpreg pro_U3VGRP_REPORT_BY_IDX_0d
        .alloc_large pro_U3VGRP_REPORT_BY_IDX_08, 464
        .push_nonvol pro_U3VGRP_REPORT_BY_IDX_01, rbp
    .endunwind
unwind_U3VGRP_SAVE_TO_FILE:
    .unwind U3VGRP_SAVE_TO_FILE, pro_U3VGRP_SAVE_TO_FILE_1b, rbp, 48
        .save_nonvol pro_U3VGRP_SAVE_TO_FILE_1b, rbx, 264
        .save_nonvol pro_U3VGRP_SAVE_TO_FILE_14, rsi, 272
        .set_fpreg pro_U3VGRP_SAVE_TO_FILE_0d
        .alloc_large pro_U3VGRP_SAVE_TO_FILE_08, 288
        .push_nonvol pro_U3VGRP_SAVE_TO_FILE_01, rbp
    .endunwind
unwind_U3VGRP_READ_FM_FILE:
    .unwind U3VGRP_READ_FM_FILE, pro_U3VGRP_READ_FM_FILE_1b, rbp, 48
        .save_nonvol pro_U3VGRP_READ_FM_FILE_1b, rbx, 288
        .save_nonvol pro_U3VGRP_READ_FM_FILE_14, rsi, 296
        .set_fpreg pro_U3VGRP_READ_FM_FILE_0d
        .alloc_large pro_U3VGRP_READ_FM_FILE_08, 304
        .push_nonvol pro_U3VGRP_READ_FM_FILE_01, rbp
    .endunwind
unwind_PUTPOINTER:
    .unwind PUTPOINTER, pro_PUTPOINTER_0a, rbp, 32
        .set_fpreg pro_PUTPOINTER_0a
        .alloc_small pro_PUTPOINTER_05, 32
        .push_nonvol pro_PUTPOINTER_01, rbp
    .endunwind
unwind_GETPOINTER:
    .unwind GETPOINTER, pro_GETPOINTER_0a, rbp, 32
        .set_fpreg pro_GETPOINTER_0a
        .alloc_small pro_GETPOINTER_05, 48
        .push_nonvol pro_GETPOINTER_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva U3VGRP_CREATE
    .rva U3VGRP_CREATE, end_U3VGRP_CREATE - U3VGRP_CREATE
    .rva .xdata, unwind_U3VGRP_CREATE - .xdata
    .rva U3VGRP_DESTROY
    .rva U3VGRP_DESTROY, end_U3VGRP_DESTROY - U3VGRP_DESTROY
    .rva .xdata, unwind_U3VGRP_DESTROY - .xdata
    .rva U3VGRP_COMPUTE
    .rva U3VGRP_COMPUTE, end_U3VGRP_COMPUTE - U3VGRP_COMPUTE
    .rva .xdata, unwind_U3VGRP_COMPUTE - .xdata
    .rva U3NJAC_COMPUTE
    .rva U3NJAC_COMPUTE, end_U3NJAC_COMPUTE - U3NJAC_COMPUTE
    .rva .xdata, unwind_U3NJAC_COMPUTE - .xdata
    .rva U3VGRP_REPORT_BY_IDX
    .rva U3VGRP_REPORT_BY_IDX, end_U3VGRP_REPORT_BY_IDX - U3VGRP_REPORT_BY_IDX
    .rva .xdata, unwind_U3VGRP_REPORT_BY_IDX - .xdata
    .rva U3VGRP_SAVE_TO_FILE
    .rva U3VGRP_SAVE_TO_FILE, end_U3VGRP_SAVE_TO_FILE - U3VGRP_SAVE_TO_FILE
    .rva .xdata, unwind_U3VGRP_SAVE_TO_FILE - .xdata
    .rva U3VGRP_READ_FM_FILE
    .rva U3VGRP_READ_FM_FILE, end_U3VGRP_READ_FM_FILE - U3VGRP_READ_FM_FILE
    .rva .xdata, unwind_U3VGRP_READ_FM_FILE - .xdata
    .rva PUTPOINTER
    .rva PUTPOINTER, end_PUTPOINTER - PUTPOINTER
    .rva .xdata, unwind_PUTPOINTER - .xdata
    .rva GETPOINTER
    .rva GETPOINTER, end_GETPOINTER - GETPOINTER
    .rva .xdata, unwind_GETPOINTER - .xdata

.section .bss 0xc0400080
U3NJAC_COMPUTE$NUMGRP:
    .space 8
U3NJAC_COMPUTE$MARKER:
    .space 8
U3NJAC_COMPUTE$LBF0:
    .space 8
U3NJAC_COMPUTE$LBDX:
    .space 8
U3NJAC_COMPUTE$LBY0:
    .space 8
U3NJAC_COMPUTE$LBV2G:
    .space 8

.section .data 0xc0600040
U3VGRP_REPORT_BY_IDX$format_pack:
    .byte 0x36
    .zero 3
    .byte 0x0c
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x20
    .zero 3
    .byte 0x38, 0x00, 0x06, 0x00, 0x0e
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x06
    .zero 3
    .byte 0x39
    .zero 3
    .byte 0x37
    .zero 3
    .byte 0x36
    .zero 3
    .byte 0x1c, 0x00, 0x07, 0x00
    .ascii " Group "
    .byte 0x00, 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x04
    .zero 3
    .byte 0x1c, 0x00, 0x14, 0x00
    .ascii " contains variables:8"
    .byte 0x00, 0x06, 0x00, 0x0e
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x06
    .zero 3
    .byte 0x39
    .zero 3
    .byte 0x37
    .zero 3
    .byte 0x36
    .zero 3
    .byte 0x1c, 0x00, 0x1d, 0x00
    .ascii " Number of groups detected = "
    .zero 3
    .byte 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x03
    .zero 3
    .byte 0x37
    .zero 31

.section .drectve 0x00100a00
    .ascii "-export:U3VGRP_READ_FM_FILE  -export:U3VGRP_SAVE_TO_FILE  -export:U3VGRP_REPORT_BY_IDX  -export:U3NJAC_COMPUTE  -export:U3VGRP_COMPUTE  -export:U3VGRP_DESTROY  -export:PUTPOINTER  -export:U3VGRP_CREATE  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\rto_resioc.obj 1743626482
.index RTO_RESIOC

.symbol .text section local
.symbol RTO_RESIOC function public
.symbol RTUT_RTIOC common public 352
.symbol .data section local
.symbol RTO_GETIOC external public function
.symbol RTO_FREIOC external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol RTO_RESIOC$FIRST_TIME data local
.symbol __ImageBase external public function
.symbol .drectve section local

.section .text 0x60300020

RTO_RESIOC:
    push rbp
pro_RTO_RESIOC_01:
    sub rsp, 0x30
pro_RTO_RESIOC_05:
    lea rbp, [rsp + 0x20]
pro_RTO_RESIOC_0a:
    mov qword ptr [rbp + 0x20], rcx
    mov rax, qword ptr [rip + reloc(.data, RTO_RESIOC$FIRST_TIME - .data)]
    test rax, rax
    short je L_004a
    lea rax, [rbp]
    lea rdx, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_GETIOC)
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    short jne L_003f
    lea rax, [rbp]
    mov rcx, rax
    call reloc(RTO_FREIOC)
L_003f:
    mov qword ptr [rip + reloc(.data, RTO_RESIOC$FIRST_TIME - .data)], 0
L_004a:
    mov rax, qword ptr [rbp + 0x20]
    mov rax, qword ptr [rax]
    cmp rax, 0x3c
    short jl L_008f
    mov rax, qword ptr [rbp + 0x20]
    mov rax, qword ptr [rax]
    cmp rax, 0x64
    short jge L_008f
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, 0xffffffffffffffc5
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(RTUT_RTIOC)]
    add rdx, 8
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 1
L_008f:
    lea rsp, [rbp + 0x10]
    pop rbp
    ret
end_RTO_RESIOC:
    nop
    nop
    nop

.section .data 0xc0400040
RTO_RESIOC$FIRST_TIME:
    .byte 0x01
    .zero 7

.section .xdata 0x40300040
unwind_RTO_RESIOC:
    .unwind RTO_RESIOC, pro_RTO_RESIOC_0a, rbp, 32
        .set_fpreg pro_RTO_RESIOC_0a
        .alloc_small pro_RTO_RESIOC_05, 48
        .push_nonvol pro_RTO_RESIOC_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTO_RESIOC
    .rva RTO_RESIOC, end_RTO_RESIOC - RTO_RESIOC
    .rva .xdata, unwind_RTO_RESIOC - .xdata

.section .drectve 0x00100a00
    .ascii "-defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\rto_share_openew.obj 1743626482
.index RTO_SHARE_OPENEW

.symbol .text section local
.symbol RTO_SHARE_OPENEW function public
.symbol .rdata section local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_3 data local
.symbol __STRLITPACK_2 data local
.symbol __STRLITPACK_1 data local
.symbol __STRLITPACK_0 data local
.symbol for_inquire external public function
.symbol RTO_OPFUNT external public function
.symbol for_close external public function
.symbol for_open external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol __STRLITPACK_5 data local
.symbol __STRLITPACK_6 data local
.symbol __STRLITPACK_7 data local
.symbol __STRLITPACK_8 data local
.symbol __STRLITPACK_9 data local
.symbol __STRLITPACK_10 data local
.symbol .drectve section local
.symbol __ImageBase external public function

.section .text 0x60300020

RTO_SHARE_OPENEW:
    push rbp
pro_RTO_SHARE_OPENEW_01:
    sub rsp, 0x190
pro_RTO_SHARE_OPENEW_08:
    lea rbp, [rsp + 0x30]
pro_RTO_SHARE_OPENEW_0d:
    mov qword ptr [rbp + 0x150], rsi
pro_RTO_SHARE_OPENEW_14:
    mov qword ptr [rbp + 0x148], rbx
pro_RTO_SHARE_OPENEW_1b:
    mov qword ptr [rbp + 0x170], rcx
    mov qword ptr [rbp + 0x178], rdx
    mov qword ptr [rbp + 0x180], r8
    mov qword ptr [rbp + 0x188], r9
    mov rax, qword ptr [rbp + 0x180]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x188]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x170]
    mov qword ptr [rbp + 0x58], rax
    lea rax, [rbp + 0x70]
    mov qword ptr [rbp + 0x60], rax
    lea rax, [rbp + 0x78]
    mov qword ptr [rbp + 0x68], rax
    lea rax, [rbp + 0x20]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_5 - .rdata)]
    lea rsi, [rbp + 0x50]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x110], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x110]
    mov r8, rax
    mov r9, rbx
    call reloc(for_inquire)
    mov eax, dword ptr [rbp + 0x78]
    test al, 1
    short je L_00d4
    mov rax, qword ptr [rbp + 0x178]
    mov rdx, qword ptr [rbp + 0x70]
    mov qword ptr [rax], rdx
    long jmp L_03f3
L_00d4:
    mov rax, qword ptr [rbp + 0x178]
    mov rax, qword ptr [rax]
    test rax, rax
    short jge L_012f
    mov rax, qword ptr [rbp + 0x178]
    mov rax, qword ptr [rax]
    neg rax
    mov qword ptr [rbp + 0x70], rax
    mov qword ptr [rbp + 0x80], 0x63
    lea rax, [rbp + 0x70]
    lea rdx, [rbp + 0x80]
    mov rcx, qword ptr [rbp + 0x178]
    mov qword ptr [rbp + 0x118], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x118]
    mov r8, rax
    call reloc(RTO_OPFUNT)
    long jmp L_01da
L_012f:
    mov qword ptr [rbp + 0x20], 0
    lea rax, [rbp + 0x78]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x178]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_6 - .rdata)]
    lea rsi, [rbp + 0x88]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x120], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x120]
    mov r8, rax
    mov r9, rbx
    call reloc(for_inquire)
    mov eax, dword ptr [rbp + 0x78]
    test al, 1
    short je L_01da
    mov qword ptr [rbp + 0x20], 0
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x178]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x128], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x128]
    mov r8, rax
    mov r9, rbx
    call reloc(for_close)
L_01da:
    mov rax, qword ptr [rbp + 0x188]
    mov qword ptr [rbp + 0x90], rax
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x170]
    mov qword ptr [rbp + 0xa0], rax
    mov qword ptr [rbp + 0xa8], 0xa
    lea rax, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    mov qword ptr [rbp + 0xb0], rax
    mov qword ptr [rbp + 0xb8], 7
    lea rax, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x178]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_8 - .rdata)]
    lea rsi, [rbp + 0x98]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x130], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x130]
    mov r8, rax
    mov r9, rbx
    call reloc(for_open)
    mov dword ptr [rbp], eax
    mov eax, dword ptr [rbp]
    mov dword ptr [rbp + 4], eax
    mov eax, dword ptr [rbp + 4]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x180]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x180]
    mov rax, qword ptr [rax]
    test rax, rax
    long jne L_0330
    mov qword ptr [rbp + 0x20], 0
    mov qword ptr [rbp + 0xc8], 6
    lea rax, [rip + reloc(.rdata, __STRLITPACK_2 - .rdata)]
    mov qword ptr [rbp + 0xd0], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x178]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_9 - .rdata)]
    lea rsi, [rbp + 0xc8]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x138], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x138]
    mov r8, rax
    mov r9, rbx
    call reloc(for_close)
    mov dword ptr [rbp + 8], eax
    mov eax, dword ptr [rbp + 8]
    mov dword ptr [rbp + 0x10], eax
    mov eax, dword ptr [rbp + 0x10]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x180]
    mov qword ptr [rdx], rax
L_0330:
    mov rax, qword ptr [rbp + 0x188]
    mov qword ptr [rbp + 0xd8], rax
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0xd8]
    mov qword ptr [rbp + 0xe0], rax
    mov rax, qword ptr [rbp + 0x170]
    mov qword ptr [rbp + 0xe8], rax
    mov qword ptr [rbp + 0xf0], 0xa
    lea rax, [rip + reloc(.rdata, __STRLITPACK_1 - .rdata)]
    mov qword ptr [rbp + 0xf8], rax
    mov qword ptr [rbp + 0x100], 7
    lea rax, [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    mov qword ptr [rbp + 0x108], rax
    lea rax, [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x178]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_10 - .rdata)]
    lea rsi, [rbp + 0xe0]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x140], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x140]
    mov r8, rax
    mov r9, rbx
    call reloc(for_open)
    mov dword ptr [rbp + 0xc], eax
    mov eax, dword ptr [rbp + 0xc]
    mov dword ptr [rbp + 0x14], eax
    mov eax, dword ptr [rbp + 0x14]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x180]
    mov qword ptr [rdx], rax
L_03f3:
    mov rbx, qword ptr [rbp + 0x148]
    mov rsi, qword ptr [rbp + 0x150]
    lea rsp, [rbp + 0x160]
    pop rbp
    ret
end_RTO_SHARE_OPENEW:
    nop
    nop

.section .rdata 0x40300040
__STRLITPACK_4:
    .ascii "sequential"
    .zero 2
__STRLITPACK_3:
    .ascii "UNKNOWN"
    .byte 0x00
__STRLITPACK_2:
    .ascii "DELETE"
    .zero 2
__STRLITPACK_1:
    .ascii "sequential"
    .zero 2
__STRLITPACK_0:
    .ascii "UNKNOWN"
    .byte 0x00
__STRLITPACK_5:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x0b, 0x03, 0x21, 0x00, 0x11, 0x03, 0x23, 0x00, 0x01
    .zero 7
__STRLITPACK_6:
    .byte 0x11, 0x03, 0x23, 0x00, 0x01
    .zero 3
    .byte 0x11
    .zero 3
__STRLITPACK_7:
    .byte 0x01
    .zero 3
    .byte 0x01
    .zero 3
__STRLITPACK_8:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x38, 0x04, 0x02, 0x00, 0x38, 0x04, 0x1a, 0x00, 0x01
    .zero 7
__STRLITPACK_9:
    .byte 0x38, 0x04, 0x0c, 0x00, 0x01
    .zero 3
    .byte 0x38
    .zero 3
__STRLITPACK_10:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x38, 0x04, 0x02, 0x00, 0x38, 0x04, 0x1a, 0x00, 0x01
    .zero 7

.section .xdata 0x40300040
unwind_RTO_SHARE_OPENEW:
    .unwind RTO_SHARE_OPENEW, pro_RTO_SHARE_OPENEW_1b, rbp, 48
        .save_nonvol pro_RTO_SHARE_OPENEW_1b, rbx, 376
        .save_nonvol pro_RTO_SHARE_OPENEW_14, rsi, 384
        .set_fpreg pro_RTO_SHARE_OPENEW_0d
        .alloc_large pro_RTO_SHARE_OPENEW_08, 400
        .push_nonvol pro_RTO_SHARE_OPENEW_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTO_SHARE_OPENEW
    .rva RTO_SHARE_OPENEW, end_RTO_SHARE_OPENEW - RTO_SHARE_OPENEW
    .rva .xdata, unwind_RTO_SHARE_OPENEW - .xdata

.section .drectve 0x00100a00
    .ascii "-export:RTO_SHARE_OPENEW  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\stredf.obj 1743626482
.index COPY_CHAR_STR

.symbol .text section local
.symbol COPY_CHAR_STR function public
.symbol .rdata section local
.symbol __STRLITPACK_0 data local
.symbol .xdata section local
.symbol .pdata section local
.symbol .drectve section local
.symbol __ImageBase external public function

.section .text 0x60300020

COPY_CHAR_STR:
    push rbp
pro_COPY_CHAR_STR_01:
    sub rsp, 0x60
pro_COPY_CHAR_STR_05:
    lea rbp, [rsp + 0x20]
pro_COPY_CHAR_STR_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x58]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jle L_0050
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
    short jmp L_005b
L_0050:
    mov rax, qword ptr [rbp + 0x58]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
L_005b:
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    short jle L_00b1
L_007c:
    mov rax, qword ptr [rbp + 0x28]
    add rax, qword ptr [rbp + 0x50]
    dec rax
    mov rdx, qword ptr [rbp + 0x28]
    add rdx, qword ptr [rbp + 0x60]
    dec rdx
    movzx eax, byte ptr [rax]
    mov byte ptr [rdx], al
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_007c
L_00b1:
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x30]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    short jl L_0109
L_00db:
    mov rax, qword ptr [rbp + 0x28]
    add rax, qword ptr [rbp + 0x60]
    dec rax
    movzx edx, byte ptr [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    mov byte ptr [rax], dl
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    short jle L_00db
L_0109:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_COPY_CHAR_STR:
    nop

.section .rdata 0x40300040
__STRLITPACK_0:
    .byte 0x20
    .zero 3

.section .xdata 0x40300040
unwind_COPY_CHAR_STR:
    .unwind COPY_CHAR_STR, pro_COPY_CHAR_STR_0a, rbp, 32
        .set_fpreg pro_COPY_CHAR_STR_0a
        .alloc_small pro_COPY_CHAR_STR_05, 96
        .push_nonvol pro_COPY_CHAR_STR_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva COPY_CHAR_STR
    .rva COPY_CHAR_STR, end_COPY_CHAR_STR - COPY_CHAR_STR
    .rva .xdata, unwind_COPY_CHAR_STR - .xdata

.section .drectve 0x00100a00
    .ascii "-export:COPY_CHAR_STR  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\rtxfile.obj 1743626481
.index RTXFILE_CLOSE
.index RTXFILE_MATCH_MD
.index RTXFILE_OPEN
.index RTXFILE_QUERY
.index RTXFILE_RESTORE_EXCEPT
.index RTXFILE_RESTORE_VARIABLE
.index RTXFILE_SAVE_VARIABLE
.index RTXFILE_UPDATE_VARIABLE

.symbol .text section local
.symbol RTXFILE_OPEN function public
.symbol RTXFILE_CLOSE function public
.symbol RTXFILE_SAVE_VARIABLE function public
.symbol RTXFILE_MATCH_MD function public
.symbol RTXFILE_RESTORE_EXCEPT function public
.symbol RTXFILE_RESTORE_VARIABLE function public
.symbol RTXFILE_UPDATE_VARIABLE function public
.symbol RTXFILE_QUERY function public
.symbol .rdata section local
.symbol __STRLITPACK_15 data local
.symbol __STRLITPACK_14 data local
.symbol __STRLITPACK_11 data local
.symbol __STRLITPACK_8 data local
.symbol __STRLITPACK_7 data local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_3 data local
.symbol __STRLITPACK_0 data local
.symbol RTO_GETIOC external public function
.symbol RTO_OPENRD_XFILE_F external public function
.symbol RTOHIS_WRITELN external public function
.symbol __chkstk external public function
.symbol for_concat external public function
.symbol memmove external public function
.symbol RTO_OPENWR_XFILE_F external public function
.symbol RTO_OPENUP_XFILE_F external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol __NLITPACK_0 data local
.symbol __STRLITPACK_18 data local
.symbol __STRLITPACK_19 data local
.symbol __STRLITPACK_20 data local
.symbol __STRLITPACK_21 data local
.symbol __STRLITPACK_22 data local
.symbol RTO_CLOSE_XFILE_F external public function
.symbol RTO_FREIOC external public function
.symbol OOMF_PLEX common public 128
.symbol RTOVARLST_INQ_NVAR_F external public function
.symbol RTOVARLST_OOMF_LBX external public function
.symbol RTOVARLST_OOMF_LBXLB external public function
.symbol RTOVARLST_OOMF_LBXUB external public function
.symbol RTOVARLST_OOMF_LBXSTAT external public function
.symbol RTOVARLST_OOMF_LBXSCL external public function
.symbol RTOVARLST_OOMF_LBXBASEUOM external public function
.symbol RTOVARLST_OOMF_LBXINIT external public function
.symbol U3V_GET_SPEC external public function
.symbol RTOVARLST_INQ_VAR_QUALITY_F external public function
.symbol RTOVARLST_INQ_VAR_MODIFIED_MASK1_F external public function
.symbol RTOVARLST_INQ_VAR_MODIFIED_MASK2_F external public function
.symbol RTOVARLST_INQ_VAR_UOM_F external public function
.symbol U3VGPT external public function
.symbol RTOVARLST_INQ_VAR_CONN_TYPE_F external public function
.symbol U3V_GET_BNDTYP external public function
.symbol RTOVARLST_INQ_VAR_PARAM_HOMO_F external public function
.symbol RTOVARLST_INQ_VAR_STEP_INBASEUOM_F external public function
.symbol RTOVARLST_INQ_VAR_SBWEIGHT_F external public function
.symbol RTOVARLST_INQ_VAR_RAMPED_F external public function
.symbol RTOVARLST_INQ_VAR_TARGET_HOMO_F external public function
.symbol RTOVARLST_INQ_VAR_THRESHOLD_F external public function
.symbol RTOVARLST_INQ_VAR_NAME_F external public function
.symbol RTO_WRITE_XFILE_F external public function
.symbol __NLITPACK_1 data local
.symbol __STRLITPACK_27 data local
.symbol __STRLITPACK_28 data local
.symbol __STRLITPACK_57 data local
.symbol __STRLITPACK_52 data local
.symbol __STRLITPACK_51 data local
.symbol __STRLITPACK_50 data local
.symbol __STRLITPACK_49 data local
.symbol __STRLITPACK_48 data local
.symbol __STRLITPACK_47 data local
.symbol __STRLITPACK_46 data local
.symbol __STRLITPACK_45 data local
.symbol __STRLITPACK_44 data local
.symbol __STRLITPACK_43 data local
.symbol __STRLITPACK_42 data local
.symbol __STRLITPACK_41 data local
.symbol __STRLITPACK_40 data local
.symbol __STRLITPACK_39 data local
.symbol __STRLITPACK_38 data local
.symbol __STRLITPACK_37 data local
.symbol __STRLITPACK_36 data local
.symbol __STRLITPACK_35 data local
.symbol __STRLITPACK_34 data local
.symbol __STRLITPACK_33 data local
.symbol __STRLITPACK_30 data local
.symbol __STRLITPACK_29 data local
.symbol RTO_READ_XHDR_F external public function
.symbol RTO_READ_XFILE_F external public function
.symbol STRED_REPLACE_REGEXPS_F external public function
.symbol RTOVARLST_VARNAME2INDEX external public function
.symbol STRSTR_F external public function
.symbol U3VFXD external public function
.symbol RTOVARLST_SET_SPEC_VALUE_F external public function
.symbol RTOVARLST_SET_VAR_QUALITY_F external public function
.symbol RTOVARLST_SET_VAR_MODIFIED_MASK_F external public function
.symbol RTOVARLST_SET_UOM_VALUE_F external public function
.symbol RTOVARLST_SET_PHYSICAL_TYPE_F external public function
.symbol RTOVARLST_SET_VAR_CONN_TYPE_F external public function
.symbol U3V_SET_BNDTYP external public function
.symbol RTOVARLST_SET_VAR_PARAM_HOMO_F external public function
.symbol RTOVARLST_SET_VAR_RAMPED_F external public function
.symbol RTOVARLST_SET_VAR_LOWER_F external public function
.symbol RTOVARLST_SET_VAR_VALUE_F external public function
.symbol RTOVARLST_SET_VAR_UPPER_F external public function
.symbol RTOVARLST_SET_VAR_STEP_INBASEUOM_F external public function
.symbol RTOVARLST_SET_VAR_INITIAL_F external public function
.symbol RTOVARLST_SET_VAR_SBWEIGHT_F external public function
.symbol RTOVARLST_SET_VAR_TARGET_HOMO_F external public function
.symbol RTOVARLST_SET_VAR_THRESHOLD_F external public function
.symbol __STRLITPACK_60 data local
.symbol __STRLITPACK_62 data local
.symbol __NLITPACK_2 data local
.symbol __NLITPACK_3 data local
.symbol __STRLITPACK_61 data local
.symbol __STRLITPACK_63 data local
.symbol __NLITPACK_4 data local
.symbol __STRLITPACK_66 data local
.symbol RTO_UPDATE_XFILE_F external public function
.symbol __STRLITPACK_72 data local
.symbol __NLITPACK_5 data local
.symbol __STRLITPACK_71 data local
.symbol __STRLITPACK_73 data local
.symbol RTXFILE_QUERY_DIGEST external public function
.symbol __STRLITPACK_76 data local
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

RTXFILE_OPEN:
    push rbp
pro_RTXFILE_OPEN_01:
    sub rsp, 0x370
pro_RTXFILE_OPEN_08:
    lea rbp, [rsp + 0x50]
pro_RTXFILE_OPEN_0d:
    mov qword ptr [rbp + 0x1c8], rsi
pro_RTXFILE_OPEN_14:
    mov qword ptr [rbp + 0x1c0], rbx
pro_RTXFILE_OPEN_1b:
    mov qword ptr [rbp + 0x330], rcx
    mov qword ptr [rbp + 0x338], rdx
    mov qword ptr [rbp + 0x340], r8
    mov qword ptr [rbp + 0x348], r9
    mov qword ptr [rbp], 0
    lea rax, [rbp + 8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTO_GETIOC)
    mov rax, qword ptr [rbp]
    test rax, rax
    long jne L_0aef
    mov rax, qword ptr [rbp + 0x340]
    mov rax, qword ptr [rax]
    test rax, rax
    long jne L_02fa
    mov rax, qword ptr [rbp + 0x358]
    mov qword ptr [rbp + 0x18], rax
    lea rax, [rbp + 8]
    mov rdx, qword ptr [rbp + 0x330]
    lea rcx, [rbp + 0x20]
    lea rbx, [rbp + 0x1d0]
    lea rsi, [rbp + 0x250]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp + 0x28]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rbp]
    mov qword ptr [rsp + 0x38], rsi
    mov rsi, qword ptr [rbp + 0x18]
    mov qword ptr [rsp + 0x40], rsi
    mov qword ptr [rbp + 0x180], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x180]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_OPENRD_XFILE_F)
    mov rax, qword ptr [rbp]
    test rax, rax
    long jne L_02ed
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 0x7ffffffe
    short jne L_011b
    long jmp L_0202
L_0102:
    mov rax, qword ptr [rbp + 0x88]
    mov edx, 0x5a
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    long jmp L_01e2
L_011b:
    mov rax, rsp
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp + 0x50]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_18 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x58]
    mov qword ptr [rax], 0x2e
    lea rax, [rbp + 0x50]
    add rax, 0x10
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_15 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x58]
    add rax, 0x10
    mov qword ptr [rax], 0x1b
    lea rax, [rbp + 0x50]
    add rax, 0x20
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_14 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x58]
    add rax, 0x20
    mov qword ptr [rax], 0x11
    mov eax, 0x5a
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x50]
    mov edx, 3
    mov rcx, qword ptr [rbp + 0x88]
    mov ebx, 0x5a
    mov qword ptr [rbp + 0x188], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x188]
    mov r8, rax
    mov r9, rbx
    call reloc(for_concat)
    long jmp L_0102
L_01e2:
    mov rax, qword ptr [rbp + 0x48]
    mov rsp, rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTXFILE_CLOSE)
    mov qword ptr [rbp + 0x10], 0
    long jmp L_0af7
L_0202:
    mov rax, qword ptr [rbp + 0x338]
    lea rdx, [rbp + 0x1d0]
    mov rcx, rax
    call reloc(RTXFILE_MATCH_MD)
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x90]
    cmp rax, 1
    long jne L_02c6
    mov rax, qword ptr [rbp + 0x350]
    mov qword ptr [rax], 0
    mov rax, rsp
    mov qword ptr [rbp + 0xa0], rax
    mov eax, 0x31
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xb0], rax
    mov rax, qword ptr [rbp + 0xb0]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_19 - .rdata)]
    mov ecx, 0x31
    mov qword ptr [rbp + 0x190], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x190]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0xb0]
    mov edx, 0x31
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0xa0]
    mov rsp, rax
    long jmp L_0af7
L_02c6:
    mov rax, qword ptr [rbp + 0x350]
    mov qword ptr [rax], 1
    lea rax, [rip + reloc(.rdata, __STRLITPACK_11 - .rdata)]
    mov edx, 0x18
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    long jmp L_0af7
L_02ed:
    mov qword ptr [rbp + 0x10], 0
    long jmp L_0af7
L_02fa:
    mov rax, qword ptr [rbp + 0x340]
    mov rax, qword ptr [rax]
    cmp rax, 1
    long jne L_038f
    mov rax, qword ptr [rbp + 0x358]
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp + 8]
    mov rdx, qword ptr [rbp + 0x330]
    lea rcx, [rip + reloc(.rdata, __NLITPACK_0 - .rdata)]
    mov rbx, qword ptr [rbp + 0x338]
    mov rsi, qword ptr [rbp + 0x348]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp]
    mov qword ptr [rsp + 0x28], rsi
    mov rsi, qword ptr [rbp + 0x38]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0x198], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x198]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_OPENWR_XFILE_F)
    mov rax, qword ptr [rbp]
    test rax, rax
    short jne L_0382
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    long jmp L_0af7
L_0382:
    mov qword ptr [rbp + 0x10], 0
    long jmp L_0af7
L_038f:
    mov rax, qword ptr [rbp + 0x340]
    mov rax, qword ptr [rax]
    cmp rax, 2
    long jne L_0af7
    mov rax, qword ptr [rbp + 0x358]
    mov qword ptr [rbp + 0x40], rax
    lea rax, [rbp + 8]
    mov rdx, qword ptr [rbp + 0x330]
    lea rcx, [rbp + 0x20]
    lea rbx, [rbp + 0x1d0]
    lea rsi, [rbp + 0x250]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp + 0x28]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rbp]
    mov qword ptr [rsp + 0x38], rsi
    mov rsi, qword ptr [rbp + 0x40]
    mov qword ptr [rsp + 0x40], rsi
    mov qword ptr [rbp + 0x1a0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1a0]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_OPENUP_XFILE_F)
    mov rax, qword ptr [rbp]
    test rax, rax
    long jne L_0ae5
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x338]
    lea rdx, [rbp + 0x1d0]
    mov rcx, rax
    call reloc(RTXFILE_MATCH_MD)
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x98]
    cmp rax, 1
    short jne L_0477
    long jmp L_0556
L_0454:
    mov rax, qword ptr [rbp + 0xf8]
    mov edx, 0x6f
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0xb8]
    mov rsp, rax
    long jmp L_0556
L_0477:
    mov rax, rsp
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0xc0]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_20 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0xc8]
    mov qword ptr [rax], 0x36
    lea rax, [rbp + 0xc0]
    add rax, 0x10
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_8 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0xc8]
    add rax, 0x10
    mov qword ptr [rax], 0x24
    lea rax, [rbp + 0xc0]
    add rax, 0x20
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0xc8]
    add rax, 0x20
    mov qword ptr [rax], 0x15
    mov eax, 0x6f
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf8], rax
    lea rax, [rbp + 0xc0]
    mov edx, 3
    mov rcx, qword ptr [rbp + 0xf8]
    mov ebx, 0x6f
    mov qword ptr [rbp + 0x1a8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1a8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_concat)
    long jmp L_0454
L_0556:
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 0x7ffffffe
    short jne L_0580
    long jmp L_0682
L_0567:
    mov rax, qword ptr [rbp + 0x140]
    mov edx, 0x5a
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    long jmp L_065f
L_0580:
    mov rax, rsp
    mov qword ptr [rbp + 0x100], rax
    lea rax, [rbp + 0x108]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_21 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x110]
    mov qword ptr [rax], 0x2e
    lea rax, [rbp + 0x108]
    add rax, 0x10
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x110]
    add rax, 0x10
    mov qword ptr [rax], 0x1b
    lea rax, [rbp + 0x108]
    add rax, 0x20
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x110]
    add rax, 0x20
    mov qword ptr [rax], 0x11
    mov eax, 0x5a
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x138], rax
    mov rax, qword ptr [rbp + 0x138]
    mov qword ptr [rbp + 0x140], rax
    lea rax, [rbp + 0x108]
    mov edx, 3
    mov rcx, qword ptr [rbp + 0x140]
    mov ebx, 0x5a
    mov qword ptr [rbp + 0x1b0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1b0]
    mov r8, rax
    mov r9, rbx
    call reloc(for_concat)
    long jmp L_0567
L_065f:
    mov rax, qword ptr [rbp + 0x100]
    mov rsp, rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTXFILE_CLOSE)
    mov qword ptr [rbp + 0x10], 0
    long jmp L_0af7
L_0682:
    mov qword ptr [rbp], 0
    lea rax, [rbp + 0x250]
    add rax, 0x38
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_06b9
    mov eax, 0x38
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_06b9
    mov qword ptr [rbp], 0xffffffffffffffff
L_06b9:
    lea rax, [rbp + 0x250]
    add rax, 0x28
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_06e8
    mov eax, 0x28
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_06e8
    mov qword ptr [rbp], 0xffffffffffffffff
L_06e8:
    lea rax, [rbp + 0x250]
    add rax, 0x10
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0717
    mov eax, 0x10
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0717
    mov qword ptr [rbp], 0xffffffffffffffff
L_0717:
    lea rax, [rbp + 0x250]
    add rax, 0x18
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0746
    mov eax, 0x18
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0746
    mov qword ptr [rbp], 0xffffffffffffffff
L_0746:
    lea rax, [rbp + 0x250]
    add rax, 0x20
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0775
    mov eax, 0x20
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0775
    mov qword ptr [rbp], 0xffffffffffffffff
L_0775:
    lea rax, [rbp + 0x250]
    add rax, 0x60
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_07a4
    mov eax, 0x60
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_07a4
    mov qword ptr [rbp], 0xffffffffffffffff
L_07a4:
    lea rax, [rbp + 0x250]
    add rax, 0x68
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_07d3
    mov eax, 0x68
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_07d3
    mov qword ptr [rbp], 0xffffffffffffffff
L_07d3:
    lea rax, [rbp + 0x250]
    add rax, 0xa0
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0804
    mov eax, 0xa0
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0804
    mov qword ptr [rbp], 0xffffffffffffffff
L_0804:
    lea rax, [rbp + 0x250]
    add rax, 0x30
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0833
    mov eax, 0x30
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0833
    mov qword ptr [rbp], 0xffffffffffffffff
L_0833:
    lea rax, [rbp + 0x250]
    add rax, 8
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0862
    mov eax, 8
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0862
    mov qword ptr [rbp], 0xffffffffffffffff
L_0862:
    lea rax, [rbp + 0x250]
    add rax, 0xc0
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0893
    mov eax, 0xc0
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0893
    mov qword ptr [rbp], 0xffffffffffffffff
L_0893:
    lea rax, [rbp + 0x250]
    add rax, 0x70
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_08c2
    mov eax, 0x70
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_08c2
    mov qword ptr [rbp], 0xffffffffffffffff
L_08c2:
    lea rax, [rbp + 0x250]
    add rax, 0x48
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_08f1
    mov eax, 0x48
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_08f1
    mov qword ptr [rbp], 0xffffffffffffffff
L_08f1:
    lea rax, [rbp + 0x250]
    add rax, 0x80
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0922
    mov eax, 0x80
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0922
    mov qword ptr [rbp], 0xffffffffffffffff
L_0922:
    lea rax, [rbp + 0x250]
    add rax, 0x88
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0953
    mov eax, 0x88
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0953
    mov qword ptr [rbp], 0xffffffffffffffff
L_0953:
    lea rax, [rbp + 0x250]
    add rax, 0x90
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_0984
    mov eax, 0x90
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0984
    mov qword ptr [rbp], 0xffffffffffffffff
L_0984:
    lea rax, [rbp + 0x250]
    add rax, 0xb0
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_09b5
    mov eax, 0xb0
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_09b5
    mov qword ptr [rbp], 0xffffffffffffffff
L_09b5:
    lea rax, [rbp + 0x250]
    add rax, 0xb8
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_09e6
    mov eax, 0xb8
    add rax, qword ptr [rbp + 0x348]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_09e6
    mov qword ptr [rbp], 0xffffffffffffffff
L_09e6:
    mov rax, qword ptr [rbp]
    test rax, rax
    short jne L_0a0d
    long jmp L_0af7
L_09f4:
    mov rax, qword ptr [rbp + 0x178]
    mov edx, 0x46
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    long jmp L_0ac5
L_0a0d:
    mov rax, rsp
    mov qword ptr [rbp + 0x148], rax
    lea rax, [rbp + 0x150]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_22 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x158]
    mov qword ptr [rax], 0x31
    lea rax, [rbp + 0x150]
    add rax, 0x10
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x158]
    add rax, 0x10
    mov qword ptr [rax], 0x15
    mov eax, 0x46
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x170], rax
    mov rax, qword ptr [rbp + 0x170]
    mov qword ptr [rbp + 0x178], rax
    lea rax, [rbp + 0x150]
    mov edx, 2
    mov rcx, qword ptr [rbp + 0x178]
    mov ebx, 0x46
    mov qword ptr [rbp + 0x1b8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1b8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_concat)
    long jmp L_09f4
L_0ac5:
    mov rax, qword ptr [rbp + 0x148]
    mov rsp, rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTXFILE_CLOSE)
    mov qword ptr [rbp + 0x10], 0
    short jmp L_0af7
L_0ae5:
    mov qword ptr [rbp + 0x10], 0
    short jmp L_0af7
L_0aef:
    mov qword ptr [rbp + 0x10], 0
L_0af7:
    mov rax, qword ptr [rbp + 0x10]
    mov rbx, qword ptr [rbp + 0x1c0]
    mov rsi, qword ptr [rbp + 0x1c8]
    lea rsp, [rbp + 0x320]
    pop rbp
    ret
end_RTXFILE_OPEN:

RTXFILE_CLOSE:
    push rbp
pro_RTXFILE_CLOSE_01:
    sub rsp, 0x30
pro_RTXFILE_CLOSE_05:
    lea rbp, [rsp + 0x20]
pro_RTXFILE_CLOSE_0a:
    mov qword ptr [rbp + 0x20], rcx
    mov rax, qword ptr [rbp + 0x20]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTO_CLOSE_XFILE_F)
    mov rax, qword ptr [rbp + 0x20]
    mov rcx, rax
    call reloc(RTO_FREIOC)
    lea rsp, [rbp + 0x10]
    pop rbp
    ret
end_RTXFILE_CLOSE:

RTXFILE_SAVE_VARIABLE:
    push rbp
pro_RTXFILE_SAVE_VARIABLE_01:
    sub rsp, 0x270
pro_RTXFILE_SAVE_VARIABLE_08:
    lea rbp, [rsp + 0x50]
pro_RTXFILE_SAVE_VARIABLE_0d:
    mov qword ptr [rbp + 0x1b8], rsi
pro_RTXFILE_SAVE_VARIABLE_14:
    mov qword ptr [rbp + 0x1b0], rbx
pro_RTXFILE_SAVE_VARIABLE_1b:
    mov qword ptr [rbp + 0x230], rcx
    mov qword ptr [rbp + 0x238], rdx
    mov qword ptr [rbp + 0x240], r8
    mov qword ptr [rbp + 0x248], r9
    mov rax, qword ptr [rbp + 0x238]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_NVAR_F)
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x240]
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x88]
    modrm cmp rax, rdx
    short jg L_0bcd
    mov rax, qword ptr [rbp + 0x248]
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x88]
    modrm cmp rax, rdx
    long jle L_0c55
L_0bcd:
    mov rax, rsp
    mov qword ptr [rbp + 0x90], rax
    mov eax, 0x3c
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x98]
    mov qword ptr [rbp + 0xa0], rax
    mov rax, qword ptr [rbp + 0xa0]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_27 - .rdata)]
    mov ecx, 0x3c
    mov qword ptr [rbp + 0x188], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x188]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0xa0]
    mov edx, 0x3c
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x90]
    mov rsp, rax
    long jmp L_187d
L_0c55:
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xa8]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBX)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xb0]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXLB)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xb8]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXUB)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xc0]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXSTAT)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xc8]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXSCL)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xd0]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXBASEUOM)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xd0]
    mov qword ptr [rbp + 0xd0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xd8]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXINIT)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xd8]
    mov qword ptr [rbp + 0xd8], rax
    mov rax, qword ptr [rbp + 0x248]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xe0], rax
    mov rax, qword ptr [rbp + 0x240]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xe8], rax
    mov rax, qword ptr [rbp + 0xe0]
    mov rdx, qword ptr [rbp + 0x240]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    long jl L_187d
L_0dbe:
    mov qword ptr [rbp + 0xf0], 0
    mov qword ptr [rbp + 0xf8], 0
    mov eax, 0x38
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0e52
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0xe8]
    add rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov rcx, rax
    call reloc(U3V_GET_SPEC)
    mov qword ptr [rbp + 0x100], rax
    mov eax, dword ptr [rbp + 0x100]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_0e52:
    mov eax, 0x60
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0eb6
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xd0]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov eax, dword ptr [rdx]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_0eb6:
    mov eax, 0x68
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0f1b
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_QUALITY_F)
    mov qword ptr [rbp + 0x108], rax
    mov eax, dword ptr [rbp + 0x108]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_0f1b:
    mov eax, 0xa0
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_0fd5
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_MODIFIED_MASK1_F)
    mov qword ptr [rbp + 0x110], rax
    mov eax, dword ptr [rbp + 0x110]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_MODIFIED_MASK2_F)
    mov qword ptr [rbp + 0x118], rax
    mov eax, dword ptr [rbp + 0x118]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_0fd5:
    mov eax, 0x30
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_103a
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_UOM_F)
    mov qword ptr [rbp + 0x120], rax
    mov eax, dword ptr [rbp + 0x120]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_103a:
    mov eax, 8
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_10b0
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0xe8]
    add rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov edx, 4
    neg rdx
    lea rcx, [rbp + 0x1c0]
    mov rbx, qword ptr [rbp + 0xf0]
    imul rbx, rbx, 4
    modrm add rcx, rbx
    modrm add rdx, rcx
    mov rcx, rax
    call reloc(U3VGPT)
L_10b0:
    mov eax, 0xc0
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1115
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_CONN_TYPE_F)
    mov qword ptr [rbp + 0x128], rax
    mov eax, dword ptr [rbp + 0x128]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_1115:
    mov eax, 0x80
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_118b
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0xe8]
    add rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov edx, 4
    neg rdx
    lea rcx, [rbp + 0x1c0]
    mov rbx, qword ptr [rbp + 0xf0]
    imul rbx, rbx, 4
    modrm add rcx, rbx
    modrm add rdx, rcx
    mov rcx, rax
    call reloc(U3V_GET_BNDTYP)
L_118b:
    mov eax, 0x88
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_11f0
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_PARAM_HOMO_F)
    mov qword ptr [rbp + 0x130], rax
    mov eax, dword ptr [rbp + 0x130]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_11f0:
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xc8]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd qword ptr [rbp + 0x138], xmm0
    mov eax, 0x28
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1268
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x138]
    movsd qword ptr [rax], xmm0
L_1268:
    mov eax, 0x10
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_12dc
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xb0]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x138]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
L_12dc:
    mov eax, 0x18
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1350
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x138]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
L_1350:
    mov eax, 0x20
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_13c4
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xb8]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x138]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
L_13c4:
    mov eax, 0x40
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_1478
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_STEP_INBASEUOM_F)
    movsd qword ptr [rbp + 0x140], xmm0
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x140]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x138]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
L_1478:
    mov eax, 0x70
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_14ec
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0xe8]
    add rax, qword ptr [rbp + 0xd8]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x138]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
L_14ec:
    mov eax, 0x48
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1556
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_SBWEIGHT_F)
    movsd qword ptr [rbp + 0x148], xmm0
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x148]
    movsd qword ptr [rax], xmm0
L_1556:
    mov eax, 0xb8
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_15bb
    mov eax, 1
    add rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0xf0], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_RAMPED_F)
    mov qword ptr [rbp + 0x150], rax
    mov eax, dword ptr [rbp + 0x150]
    lea rdx, [rbp + 0x1c0]
    mov rcx, qword ptr [rbp + 0xf0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
L_15bb:
    mov eax, 0x90
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_1687
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    lea rcx, [rip + reloc(.rdata, __NLITPACK_1 - .rdata)]
    mov qword ptr [rbp + 0x190], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x190]
    mov r8, rax
    call reloc(RTOVARLST_INQ_VAR_TARGET_HOMO_F)
    movsd qword ptr [rbp + 0x158], xmm0
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x158]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x138]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
L_1687:
    mov eax, 0xb0
    add rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_16f1
    mov eax, 1
    add rax, qword ptr [rbp + 0xf8]
    mov qword ptr [rbp + 0xf8], rax
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_THRESHOLD_F)
    movsd qword ptr [rbp + 0x160], xmm0
    lea rax, [rbp + 0x1e0]
    mov rdx, qword ptr [rbp + 0xf8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x160]
    movsd qword ptr [rax], xmm0
L_16f1:
    mov rax, qword ptr [rbp + 0x250]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1733
    mov rax, qword ptr [rbp + 0x238]
    lea rdx, [rbp + 0xe8]
    lea rcx, [rbp]
    mov ebx, 0x80
    mov qword ptr [rbp + 0x198], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x198]
    mov r8, rax
    mov r9, rbx
    call reloc(RTOVARLST_INQ_VAR_NAME_F)
L_1733:
    mov rax, qword ptr [rbp + 0x230]
    mov edx, 0
    mov ecx, 8
    modrm add rdx, rcx
    add rdx, -8
    add rdx, qword ptr [rbp + 0x250]
    lea rcx, [rbp + 0xf8]
    lea rbx, [rbp + 0xf0]
    lea rsi, [rbp + 0xe8]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x1c0]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rbp + 0x1e0]
    mov qword ptr [rsp + 0x38], rsi
    lea rsi, [rbp + 0x168]
    mov qword ptr [rsp + 0x40], rsi
    mov qword ptr [rsp + 0x48], 0x80
    mov qword ptr [rbp + 0x1a0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1a0]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_WRITE_XFILE_F)
    mov rax, qword ptr [rbp + 0x168]
    test rax, rax
    long je L_1853
    mov rax, rsp
    mov qword ptr [rbp + 0x170], rax
    mov eax, 0x30
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x178], rax
    mov rax, qword ptr [rbp + 0x178]
    mov qword ptr [rbp + 0x180], rax
    mov rax, qword ptr [rbp + 0x180]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_28 - .rdata)]
    mov ecx, 0x30
    mov qword ptr [rbp + 0x1a8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1a8]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0x180]
    mov edx, 0x30
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x170]
    mov rsp, rax
    short jmp L_187d
L_1853:
    mov eax, 1
    add rax, qword ptr [rbp + 0xe8]
    mov qword ptr [rbp + 0xe8], rax
    mov rax, qword ptr [rbp + 0xe8]
    mov rdx, qword ptr [rbp + 0xe0]
    modrm cmp rax, rdx
    long jle L_0dbe
L_187d:
    mov rbx, qword ptr [rbp + 0x1b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    lea rsp, [rbp + 0x220]
    pop rbp
    ret
end_RTXFILE_SAVE_VARIABLE:

RTXFILE_MATCH_MD:
    ; Compare two arrays of sixteen 64-bit words. Return 1 after the last equal pair or 0 on the first unequal pair.
    push rbp
pro_RTXFILE_MATCH_MD_01:
    sub rsp, 0x30
pro_RTXFILE_MATCH_MD_05:
    lea rbp, [rsp + 0x20]
pro_RTXFILE_MATCH_MD_0a:
    mov qword ptr [rbp + 0x20], rcx
    mov qword ptr [rbp + 0x28], rdx
    mov qword ptr [rbp], 0
    mov qword ptr [rbp + 8], 1
L_18b6:
    mov rax, qword ptr [rbp + 8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x20]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 8]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x28]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jne L_1900
    mov eax, 1
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    cmp rax, 0x10
    short jle L_18b6
    mov qword ptr [rbp], 1
L_1900:
    mov rax, qword ptr [rbp]
    lea rsp, [rbp + 0x10]
    pop rbp
    ret
end_RTXFILE_MATCH_MD:

RTXFILE_RESTORE_EXCEPT:
    ; Read the header, resolve the variable tables, then read and apply selected record fields. Win64 register and stack arguments are explicit at each call.
    push rbp
pro_RTXFILE_RESTORE_EXCEPT_01:
    sub rsp, 0x570
pro_RTXFILE_RESTORE_EXCEPT_08:
    lea rbp, [rsp + 0x60]
pro_RTXFILE_RESTORE_EXCEPT_0d:
    mov qword ptr [rbp + 0x2d0], rsi
pro_RTXFILE_RESTORE_EXCEPT_14:
    mov qword ptr [rbp + 0x2c8], rbx
pro_RTXFILE_RESTORE_EXCEPT_1b:
    mov qword ptr [rbp + 0x520], rcx
    mov qword ptr [rbp + 0x528], rdx
    mov qword ptr [rbp + 0x530], r8
    mov qword ptr [rbp + 0x538], r9
    mov qword ptr [rbp + 0x80], 0
    mov qword ptr [rbp + 0x88], 0
    mov rax, qword ptr [rbp + 0x520]
    lea rdx, [rbp + 0x90]
    lea rcx, [rbp + 0x2e0]
    lea rbx, [rbp + 0x360]
    lea rsi, [rbp + 0x98]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp + 0xa0]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0xa8]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0x1f8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1f8]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XHDR_F)
    mov qword ptr [rbp + 0xb0], 0
    mov qword ptr [rbp + 0xb8], 0
    mov qword ptr [rbp + 0xc0], 0
    mov rax, qword ptr [rbp + 0x538]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_1b5e
    lea rax, [rbp + 0x360]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1a14
    long jmp L_1b5e
L_19fb:
    mov rax, qword ptr [rbp + 0x110]
    mov edx, 0x49
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    long jmp L_1acc
L_1a14:
    mov rax, rsp
    mov qword ptr [rbp + 0xe0], rax
    lea rax, [rbp + 0xe8]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_60 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0xf0]
    mov qword ptr [rax], 0x3f
    lea rax, [rbp + 0xe8]
    add rax, 0x10
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_57 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0xf0]
    add rax, 0x10
    mov qword ptr [rax], 0xa
    mov eax, 0x49
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x60]
    mov qword ptr [rbp + 0x108], rax
    mov rax, qword ptr [rbp + 0x108]
    mov qword ptr [rbp + 0x110], rax
    lea rax, [rbp + 0xe8]
    mov edx, 2
    mov rcx, qword ptr [rbp + 0x110]
    mov ebx, 0x49
    mov qword ptr [rbp + 0x200], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x200]
    mov r8, rax
    mov r9, rbx
    call reloc(for_concat)
    long jmp L_19fb
L_1acc:
    mov rax, qword ptr [rbp + 0xe0]
    mov rsp, rax
    mov rax, rsp
    mov qword ptr [rbp + 0x118], rax
    mov eax, 0x2b
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x60]
    mov qword ptr [rbp + 0x120], rax
    mov rax, qword ptr [rbp + 0x120]
    mov qword ptr [rbp + 0x128], rax
    mov rax, qword ptr [rbp + 0x128]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_61 - .rdata)]
    mov ecx, 0x2b
    mov qword ptr [rbp + 0x208], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x208]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0x128]
    mov edx, 0x2b
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x118]
    mov rsp, rax
    long jmp L_348c
L_1b5e:
    mov rax, rsp
    mov qword ptr [rbp + 0xc8], rax
    mov eax, 0x41
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x60]
    mov qword ptr [rbp + 0xd0], rax
    mov rax, qword ptr [rbp + 0xd0]
    mov qword ptr [rbp + 0xd8], rax
    mov rax, qword ptr [rbp + 0xd8]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_62 - .rdata)]
    mov ecx, 0x41
    mov qword ptr [rbp + 0x210], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x210]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0xd8]
    mov edx, 0x41
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0xc8]
    mov rsp, rax
    lea rax, [rbp + 0x360]
    add rax, 0x38
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1c62
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 8
    lea rax, [rip + reloc(.rdata, __STRLITPACK_52 - .rdata)]
    mov edx, 6
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x38
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1c62
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_1c62:
    lea rax, [rbp + 0x360]
    add rax, 0x60
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1ce3
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xd
    lea rax, [rip + reloc(.rdata, __STRLITPACK_51 - .rdata)]
    mov edx, 9
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x60
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1ce3
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_1ce3:
    lea rax, [rbp + 0x360]
    add rax, 0x68
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1d64
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xe
    lea rax, [rip + reloc(.rdata, __STRLITPACK_50 - .rdata)]
    mov edx, 9
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x68
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1d64
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_1d64:
    lea rax, [rbp + 0x360]
    add rax, 0xa0
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_1e32
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x15
    lea rax, [rip + reloc(.rdata, __STRLITPACK_49 - .rdata)]
    mov edx, 0x10
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x15
    lea rax, [rip + reloc(.rdata, __STRLITPACK_48 - .rdata)]
    mov edx, 0x10
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0xa0
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1e32
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_1e32:
    lea rax, [rbp + 0x360]
    add rax, 0x30
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1eb3
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 7
    lea rax, [rip + reloc(.rdata, __STRLITPACK_47 - .rdata)]
    mov edx, 5
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x30
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1eb3
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_1eb3:
    lea rax, [rbp + 0x360]
    add rax, 8
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1f0d
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 2
    lea rax, [rip + reloc(.rdata, __STRLITPACK_46 - .rdata)]
    mov edx, 0xf
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
L_1f0d:
    lea rax, [rbp + 0x360]
    add rax, 0xc0
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1f90
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x19
    lea rax, [rip + reloc(.rdata, __STRLITPACK_45 - .rdata)]
    mov edx, 0x11
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0xc0
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_1f90
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_1f90:
    lea rax, [rbp + 0x360]
    add rax, 0x80
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2013
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x11
    lea rax, [rip + reloc(.rdata, __STRLITPACK_44 - .rdata)]
    mov edx, 0xf
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x80
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2013
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_2013:
    lea rax, [rbp + 0x360]
    add rax, 0x88
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2096
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x12
    lea rax, [rip + reloc(.rdata, __STRLITPACK_43 - .rdata)]
    mov edx, 0x10
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x88
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2096
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_2096:
    lea rax, [rbp + 0x360]
    add rax, 0x28
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2117
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 6
    lea rax, [rip + reloc(.rdata, __STRLITPACK_42 - .rdata)]
    mov edx, 7
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x28
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2117
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_2117:
    lea rax, [rbp + 0x360]
    add rax, 0x10
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2198
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 3
    lea rax, [rip + reloc(.rdata, __STRLITPACK_41 - .rdata)]
    mov edx, 7
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x10
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2198
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_2198:
    lea rax, [rbp + 0x360]
    add rax, 0x18
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2219
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 4
    lea rax, [rip + reloc(.rdata, __STRLITPACK_40 - .rdata)]
    mov edx, 7
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x18
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2219
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_2219:
    lea rax, [rbp + 0x360]
    add rax, 0x20
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_229a
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 5
    lea rax, [rip + reloc(.rdata, __STRLITPACK_39 - .rdata)]
    mov edx, 7
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x20
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_229a
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_229a:
    lea rax, [rbp + 0x360]
    add rax, 0x40
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_231b
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 9
    lea rax, [rip + reloc(.rdata, __STRLITPACK_38 - .rdata)]
    mov edx, 6
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x40
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_231b
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_231b:
    lea rax, [rbp + 0x360]
    add rax, 0x70
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_239c
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xf
    lea rax, [rip + reloc(.rdata, __STRLITPACK_37 - .rdata)]
    mov edx, 9
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x70
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_239c
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_239c:
    lea rax, [rbp + 0x360]
    add rax, 0x48
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_241d
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xa
    lea rax, [rip + reloc(.rdata, __STRLITPACK_36 - .rdata)]
    mov edx, 0xa
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x48
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_241d
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_241d:
    lea rax, [rbp + 0x360]
    add rax, 0x90
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_24a0
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x13
    lea rax, [rip + reloc(.rdata, __STRLITPACK_35 - .rdata)]
    mov edx, 0x11
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0x90
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_24a0
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_24a0:
    lea rax, [rbp + 0x360]
    add rax, 0xb0
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2523
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x17
    lea rax, [rip + reloc(.rdata, __STRLITPACK_34 - .rdata)]
    mov edx, 0xb
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0xb0
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2523
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_2523:
    lea rax, [rbp + 0x360]
    add rax, 0xb8
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_25a6
    mov eax, 1
    add rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0xb8], rax
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0xb8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x18
    lea rax, [rip + reloc(.rdata, __STRLITPACK_33 - .rdata)]
    mov edx, 8
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov eax, 0xb8
    add rax, qword ptr [rbp + 0x530]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_25a6
    mov eax, 1
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
L_25a6:
    mov rax, qword ptr [rbp + 0xb0]
    test rax, rax
    long je L_348c
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x130]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBX)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x130]
    mov qword ptr [rbp + 0x130], rax
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x138]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXLB)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x138]
    mov qword ptr [rbp + 0x138], rax
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x140]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXUB)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x140]
    mov qword ptr [rbp + 0x140], rax
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x148]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXSCL)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x148]
    mov qword ptr [rbp + 0x148], rax
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x150]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXSTAT)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x150]
    mov qword ptr [rbp + 0x150], rax
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x158]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXBASEUOM)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x158]
    mov qword ptr [rbp + 0x158], rax
    mov qword ptr [rbp + 0x90], 1
L_26c3:
    mov rax, qword ptr [rbp + 0x520]
    mov edx, 8
    mov ecx, 8
    modrm sub rdx, rcx
    lea rcx, [rbp + 0x360]
    modrm add rdx, rcx
    lea rcx, [rbp + 0xc0]
    lea rbx, [rbp + 0xb8]
    lea rsi, [rbp + 0x160]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x4b0]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rbp + 0x4d0]
    mov qword ptr [rsp + 0x38], rsi
    lea rsi, [rbp + 0x168]
    mov qword ptr [rsp + 0x40], rsi
    lea rsi, [rbp + 0xa8]
    mov qword ptr [rsp + 0x48], rsi
    mov qword ptr [rsp + 0x50], 0x80
    mov qword ptr [rbp + 0x218], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x218]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XFILE_F)
    mov rax, qword ptr [rbp + 0xa8]
    test rax, rax
    long je L_27f1
    mov rax, rsp
    mov qword ptr [rbp + 0x170], rax
    mov eax, 0x33
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x60]
    mov qword ptr [rbp + 0x178], rax
    mov rax, qword ptr [rbp + 0x178]
    mov qword ptr [rbp + 0x180], rax
    mov rax, qword ptr [rbp + 0x180]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_63 - .rdata)]
    mov ecx, 0x33
    mov qword ptr [rbp + 0x220], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x220]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0x180]
    mov edx, 0x33
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x170]
    mov rsp, rax
    long jmp L_348c
L_27f1:
    mov rax, qword ptr [rbp + 0x168]
    cmp rax, 1
    long je L_347b
    mov rax, qword ptr [rbp + 0x538]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_28a0
    mov rax, qword ptr [rbp + 0x540]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_2862
    lea rax, [rbp]
    lea rdx, [rip + reloc(.rdata, __NLITPACK_2 - .rdata)]
    mov rcx, qword ptr [rbp + 0x548]
    mov rbx, qword ptr [rbp + 0x550]
    mov qword ptr [rsp + 0x20], 0x80
    mov qword ptr [rbp + 0x228], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x228]
    mov r8, rax
    mov r9, rbx
    call reloc(STRED_REPLACE_REGEXPS_F)
L_2862:
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp]
    mov ecx, 0x80
    mov qword ptr [rbp + 0x230], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x230]
    mov r8, rax
    call reloc(RTOVARLST_VARNAME2INDEX)
    mov qword ptr [rbp + 0x188], rax
    mov rax, qword ptr [rbp + 0x188]
    mov qword ptr [rbp + 0x160], rax
L_28a0:
    mov rax, qword ptr [rbp + 0x160]
    test rax, rax
    long jne L_2965
    mov rax, qword ptr [rbp + 0x540]
    mov rax, qword ptr [rax]
    test rax, rax
    long jne L_3455
    lea rax, [rbp]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_30 - .rdata)]
    mov ecx, 0x80
    mov ebx, 5
    mov qword ptr [rbp + 0x238], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x238]
    mov r8, rax
    mov r9, rbx
    call reloc(STRSTR_F)
    mov qword ptr [rbp + 0x198], rax
    short jmp L_2913
L_28fd:
    mov rax, qword ptr [rbp + 0x1a0]
    or rax, qword ptr [rbp + 0x198]
    long jne L_3455
    short jmp L_294d
L_2913:
    lea rax, [rbp]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_29 - .rdata)]
    mov ecx, 0x80
    mov ebx, 5
    mov qword ptr [rbp + 0x240], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x240]
    mov r8, rax
    mov r9, rbx
    call reloc(STRSTR_F)
    mov qword ptr [rbp + 0x1a0], rax
    short jmp L_28fd
L_294d:
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    long jmp L_3455
L_2965:
    mov qword ptr [rbp + 0x190], 0xffffffffffffffff
    mov rax, qword ptr [rbp + 0x558]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_29a8
    mov rax, qword ptr [rbp + 0x160]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x560]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_29a8
    mov qword ptr [rbp + 0x190], 0
L_29a8:
    mov rax, qword ptr [rbp + 0x568]
    mov rax, qword ptr [rax]
    cmp rax, 1
    short jne L_2a03
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp + 0x160]
    add rdx, qword ptr [rbp + 0x150]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x1a8], rax
    mov eax, dword ptr [rbp + 0x1a8]
    test al, 1
    short je L_2a03
    mov qword ptr [rbp + 0x190], 0
L_2a03:
    mov eax, dword ptr [rbp + 0x190]
    test al, 1
    long je L_3455
    mov rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0x1b0], rax
    mov qword ptr [rbp + 0x1b8], 1
    mov rax, qword ptr [rbp + 0x1b0]
    test rax, rax
    long jle L_2ee1
L_2a3a:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x530]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_2eb7
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 8
    short jne L_2adf
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x248], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x248]
    mov r8, rax
    call reloc(RTOVARLST_SET_SPEC_VALUE_F)
    long jmp L_2eb7
L_2adf:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0xd
    short jne L_2b47
    lea rax, [rbp + 0x4b0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov eax, dword ptr [rax]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x160]
    add rdx, qword ptr [rbp + 0x158]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov qword ptr [rcx], rax
    long jmp L_2eb7
L_2b47:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0xe
    short jne L_2bb5
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x250], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x250]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_QUALITY_F)
    long jmp L_2eb7
L_2bb5:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x15
    short jne L_2c23
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x258], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x258]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_MODIFIED_MASK_F)
    long jmp L_2eb7
L_2c23:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 7
    short jne L_2c91
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x260], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x260]
    mov r8, rax
    call reloc(RTOVARLST_SET_UOM_VALUE_F)
    long jmp L_2eb7
L_2c91:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 2
    short jne L_2cff
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x268], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x268]
    mov r8, rax
    call reloc(RTOVARLST_SET_PHYSICAL_TYPE_F)
    long jmp L_2eb7
L_2cff:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x19
    short jne L_2d6d
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x270], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x270]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_CONN_TYPE_F)
    long jmp L_2eb7
L_2d6d:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x11
    short jne L_2de3
    mov eax, 4
    neg rax
    lea rdx, [rbp + 0x4b0]
    mov rcx, qword ptr [rbp + 0x1b8]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    modrm add rax, rdx
    mov edx, 8
    neg rdx
    mov rcx, qword ptr [rbp + 0x160]
    add rcx, qword ptr [rbp + 0x150]
    imul rcx, rcx, 8
    lea rbx, [rip + reloc(OOMF_PLEX)]
    modrm add rbx, rcx
    modrm add rdx, rbx
    mov rcx, rax
    call reloc(U3V_SET_BNDTYP)
    long jmp L_2eb7
L_2de3:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x12
    short jne L_2e4e
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x278], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x278]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_PARAM_HOMO_F)
    short jmp L_2eb7
L_2e4e:
    lea rax, [rbp + 0x430]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x18
    short jne L_2eb7
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 4
    neg rcx
    lea rbx, [rbp + 0x4b0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 4
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x280], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x280]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_RAMPED_F)
L_2eb7:
    mov eax, 1
    add rax, qword ptr [rbp + 0x1b8]
    mov qword ptr [rbp + 0x1b8], rax
    mov rax, qword ptr [rbp + 0x1b8]
    mov rdx, qword ptr [rbp + 0x1b0]
    modrm cmp rax, rdx
    long jle L_2a3a
L_2ee1:
    mov rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0x1c0], rax
    mov qword ptr [rbp + 0x1b8], 1
    mov rax, qword ptr [rbp + 0x1c0]
    test rax, rax
    long jle L_3455
L_2f0a:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x530]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_342b
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 3
    long jne L_2ff1
    lea rax, [rbp + 0x4d0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x160]
    add rax, qword ptr [rbp + 0x148]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    movsd qword ptr [rbp + 0x1c8], xmm0
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    lea rcx, [rbp + 0x1c8]
    lea rbx, [rip + reloc(.rdata, __NLITPACK_3 - .rdata)]
    mov qword ptr [rbp + 0x288], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x288]
    mov r8, rax
    mov r9, rbx
    call reloc(RTOVARLST_SET_VAR_LOWER_F)
    long jmp L_342b
L_2ff1:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 4
    long jne L_30a1
    lea rax, [rbp + 0x4d0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x160]
    add rax, qword ptr [rbp + 0x148]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    movsd qword ptr [rbp + 0x1d0], xmm0
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    lea rcx, [rbp + 0x1d0]
    lea rbx, [rip + reloc(.rdata, __NLITPACK_3 - .rdata)]
    mov qword ptr [rbp + 0x290], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x290]
    mov r8, rax
    mov r9, rbx
    call reloc(RTOVARLST_SET_VAR_VALUE_F)
    long jmp L_342b
L_30a1:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 5
    long jne L_3151
    lea rax, [rbp + 0x4d0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x160]
    add rax, qword ptr [rbp + 0x148]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    movsd qword ptr [rbp + 0x1d8], xmm0
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    lea rcx, [rbp + 0x1d8]
    lea rbx, [rip + reloc(.rdata, __NLITPACK_3 - .rdata)]
    mov qword ptr [rbp + 0x298], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x298]
    mov r8, rax
    mov r9, rbx
    call reloc(RTOVARLST_SET_VAR_UPPER_F)
    long jmp L_342b
L_3151:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 9
    long jne L_31f7
    lea rax, [rbp + 0x4d0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x160]
    add rax, qword ptr [rbp + 0x148]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    movsd qword ptr [rbp + 0x1e0], xmm0
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    lea rcx, [rbp + 0x1e0]
    mov qword ptr [rbp + 0x2a0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x2a0]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_STEP_INBASEUOM_F)
    long jmp L_342b
L_31f7:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0xf
    long jne L_32a7
    lea rax, [rbp + 0x4d0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x160]
    add rax, qword ptr [rbp + 0x148]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    movsd qword ptr [rbp + 0x1e8], xmm0
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    lea rcx, [rbp + 0x1e8]
    lea rbx, [rip + reloc(.rdata, __NLITPACK_3 - .rdata)]
    mov qword ptr [rbp + 0x2a8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x2a8]
    mov r8, rax
    mov r9, rbx
    call reloc(RTOVARLST_SET_VAR_INITIAL_F)
    long jmp L_342b
L_32a7:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0xa
    short jne L_3315
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 8
    neg rcx
    lea rbx, [rbp + 0x4d0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 8
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x2b0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x2b0]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_SBWEIGHT_F)
    long jmp L_342b
L_3315:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x13
    long jne L_33c2
    lea rax, [rbp + 0x4d0]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x160]
    add rax, qword ptr [rbp + 0x148]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm1, qword ptr [rdx]
    divsd xmm0, xmm1
    movsd qword ptr [rbp + 0x1f0], xmm0
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    lea rcx, [rbp + 0x1f0]
    lea rbx, [rip + reloc(.rdata, __NLITPACK_3 - .rdata)]
    mov qword ptr [rbp + 0x2b8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x2b8]
    mov r8, rax
    mov r9, rbx
    call reloc(RTOVARLST_SET_VAR_TARGET_HOMO_F)
    short jmp L_342b
L_33c2:
    lea rax, [rbp + 0x470]
    mov rdx, qword ptr [rbp + 0x1b8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, 0x17
    short jne L_342b
    mov rax, qword ptr [rbp + 0x528]
    lea rdx, [rbp + 0x160]
    mov ecx, 8
    neg rcx
    lea rbx, [rbp + 0x4d0]
    mov rsi, qword ptr [rbp + 0x1b8]
    imul rsi, rsi, 8
    modrm add rbx, rsi
    modrm add rcx, rbx
    mov qword ptr [rbp + 0x2c0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x2c0]
    mov r8, rax
    call reloc(RTOVARLST_SET_VAR_THRESHOLD_F)
L_342b:
    mov eax, 1
    add rax, qword ptr [rbp + 0x1b8]
    mov qword ptr [rbp + 0x1b8], rax
    mov rax, qword ptr [rbp + 0x1b8]
    mov rdx, qword ptr [rbp + 0x1c0]
    modrm cmp rax, rdx
    long jle L_2f0a
L_3455:
    mov eax, 1
    add rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x90]
    cmp rax, 0x5f5e100
    long jle L_26c3
L_347b:
    mov rax, qword ptr [rbp + 0x88]
    neg rax
    mov qword ptr [rbp + 0x80], rax
L_348c:
    mov rax, qword ptr [rbp + 0x80]
    mov rbx, qword ptr [rbp + 0x2c8]
    mov rsi, qword ptr [rbp + 0x2d0]
    lea rsp, [rbp + 0x510]
    pop rbp
    ret
end_RTXFILE_RESTORE_EXCEPT:

RTXFILE_RESTORE_VARIABLE:
    push rbp
pro_RTXFILE_RESTORE_VARIABLE_01:
    sub rsp, 0x90
pro_RTXFILE_RESTORE_VARIABLE_08:
    lea rbp, [rsp + 0x50]
pro_RTXFILE_RESTORE_VARIABLE_0d:
    mov qword ptr [rbp + 0x20], rsi
pro_RTXFILE_RESTORE_VARIABLE_11:
    mov qword ptr [rbp + 0x18], rbx
pro_RTXFILE_RESTORE_VARIABLE_15:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x58]
    mov rcx, qword ptr [rbp + 0x60]
    mov rbx, qword ptr [rbp + 0x68]
    mov rsi, qword ptr [rbp + 0x70]
    mov qword ptr [rsp + 0x20], rsi
    mov rsi, qword ptr [rbp + 0x78]
    mov qword ptr [rsp + 0x28], rsi
    mov rsi, qword ptr [rbp + 0x80]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rip + reloc(.rdata, __NLITPACK_4 - .rdata)]
    mov qword ptr [rsp + 0x38], rsi
    lea rsi, [rbp + 0x30]
    mov qword ptr [rsp + 0x40], rsi
    lea rsi, [rip + reloc(.rdata, __NLITPACK_4 - .rdata)]
    mov qword ptr [rsp + 0x48], rsi
    mov qword ptr [rbp + 0x10], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x10]
    mov r8, rax
    mov r9, rbx
    call reloc(RTXFILE_RESTORE_EXCEPT)
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov rbx, qword ptr [rbp + 0x18]
    mov rsi, qword ptr [rbp + 0x20]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_RTXFILE_RESTORE_VARIABLE:

RTXFILE_UPDATE_VARIABLE:
    push rbp
pro_RTXFILE_UPDATE_VARIABLE_01:
    sub rsp, 0x3e0
pro_RTXFILE_UPDATE_VARIABLE_08:
    lea rbp, [rsp + 0x50]
pro_RTXFILE_UPDATE_VARIABLE_0d:
    mov qword ptr [rbp + 0x190], rsi
pro_RTXFILE_UPDATE_VARIABLE_14:
    mov qword ptr [rbp + 0x188], rbx
pro_RTXFILE_UPDATE_VARIABLE_1b:
    mov qword ptr [rbp + 0x3a0], rcx
    mov qword ptr [rbp + 0x3a8], rdx
    mov qword ptr [rbp + 0x3b0], r8
    mov rax, qword ptr [rbp + 0x3a0]
    lea rdx, [rbp]
    lea rcx, [rbp + 0x1a0]
    lea rbx, [rbp + 0x220]
    lea rsi, [rbp + 8]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp + 0x10]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x18]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0x158], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x158]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XHDR_F)
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    short je L_364e
    mov rax, rsp
    mov qword ptr [rbp + 0x20], rax
    mov eax, 0x39
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_71 - .rdata)]
    mov ecx, 0x39
    mov qword ptr [rbp + 0x160], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x160]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0x30]
    mov edx, 0x39
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x20]
    mov rsp, rax
    long jmp L_4ae7
L_364e:
    mov rax, qword ptr [rbp + 0x3a8]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_NVAR_F)
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 8]
    mov rdx, qword ptr [rbp + 0x40]
    modrm cmp rax, rdx
    short jg L_36a5
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x40]
    modrm cmp rax, rdx
    short jg L_36a5
    long jmp L_373f
L_3688:
    mov rax, qword ptr [rbp + 0x78]
    mov edx, 0x60
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x48]
    mov rsp, rax
    long jmp L_4ae7
L_36a5:
    mov rax, rsp
    mov qword ptr [rbp + 0x48], rax
    lea rax, [rbp + 0x50]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_72 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x58]
    mov qword ptr [rax], 0x49
    lea rax, [rbp + 0x50]
    add rax, 0x10
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_66 - .rdata)]
    mov qword ptr [rax], rdx
    lea rax, [rbp + 0x58]
    add rax, 0x10
    mov qword ptr [rax], 0x17
    mov eax, 0x60
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x70]
    mov qword ptr [rbp + 0x78], rax
    lea rax, [rbp + 0x50]
    mov edx, 2
    mov rcx, qword ptr [rbp + 0x78]
    mov ebx, 0x60
    mov qword ptr [rbp + 0x168], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x168]
    mov r8, rax
    mov r9, rbx
    call reloc(for_concat)
    long jmp L_3688
L_373f:
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0x80]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBX)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0x88]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXLB)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0x90]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXUB)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0x98]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXSTAT)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x98]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0xa0]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXSCL)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xa0]
    mov qword ptr [rbp + 0xa0], rax
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0xa8]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXBASEUOM)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp + 0xb0]
    mov rcx, rax
    call reloc(RTOVARLST_OOMF_LBXINIT)
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0xb0], rax
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0xb8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 8]
    modrm cmp rax, rdx
    long jl L_4ae7
L_3893:
    mov qword ptr [rbp + 0xc0], 0
    mov qword ptr [rbp + 0xc8], 0
    lea rax, [rbp + 0x220]
    add rax, 0x38
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_39a4
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x38
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_39a4
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp]
    add rdx, qword ptr [rbp + 0x98]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0xd0], rax
    mov eax, dword ptr [rbp + 0xd0]
    test al, 1
    short je L_3985
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3985:
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_39a4:
    lea rax, [rbp + 0x220]
    add rax, 0x60
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3a79
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x60
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_3a79
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov eax, dword ptr [rdx]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3a79:
    lea rax, [rbp + 0x220]
    add rax, 0x68
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3b4f
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x68
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_3b4f
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_QUALITY_F)
    mov qword ptr [rbp + 0xd8], rax
    mov eax, dword ptr [rbp + 0xd8]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3b4f:
    lea rax, [rbp + 0x220]
    add rax, 0xa0
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3ce6
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0xa0
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_3c27
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_MODIFIED_MASK1_F)
    mov qword ptr [rbp + 0xe0], rax
    mov eax, dword ptr [rbp + 0xe0]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3c27:
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0xa0
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_3ce6
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_MODIFIED_MASK2_F)
    mov qword ptr [rbp + 0xe8], rax
    mov eax, dword ptr [rbp + 0xe8]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3ce6:
    lea rax, [rbp + 0x220]
    add rax, 0x30
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3dbc
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x30
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_3dbc
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_UOM_F)
    mov qword ptr [rbp + 0xf0], rax
    mov eax, dword ptr [rbp + 0xf0]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3dbc:
    lea rax, [rbp + 0x220]
    add rax, 8
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3ea7
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 8
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3ea7
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp]
    add rdx, qword ptr [rbp + 0x98]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov edx, 4
    neg rdx
    lea rcx, [rbp + 0x310]
    mov rbx, qword ptr [rbp + 0xc0]
    imul rbx, rbx, 4
    modrm add rcx, rbx
    modrm add rdx, rcx
    mov rcx, rax
    call reloc(U3VGPT)
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3ea7:
    lea rax, [rbp + 0x220]
    add rax, 0xc0
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_3f7f
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0xc0
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_3f7f
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_CONN_TYPE_F)
    mov qword ptr [rbp + 0xf8], rax
    mov eax, dword ptr [rbp + 0xf8]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_3f7f:
    lea rax, [rbp + 0x220]
    add rax, 0x80
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_406c
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x80
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_406c
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 8
    neg rax
    mov rdx, qword ptr [rbp]
    add rdx, qword ptr [rbp + 0x98]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    modrm add rax, rcx
    mov edx, 4
    neg rdx
    lea rcx, [rbp + 0x310]
    mov rbx, qword ptr [rbp + 0xc0]
    imul rbx, rbx, 4
    modrm add rcx, rbx
    modrm add rdx, rcx
    mov rcx, rax
    call reloc(U3V_GET_BNDTYP)
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_406c:
    lea rax, [rbp + 0x220]
    add rax, 0x88
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_4144
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x88
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4144
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_PARAM_HOMO_F)
    mov qword ptr [rbp + 0x100], rax
    mov eax, dword ptr [rbp + 0x100]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_4144:
    lea rax, [rbp + 0x220]
    add rax, 0xb8
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_421c
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0xb8
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_421c
    lea rax, [rbp + 0x310]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_RAMPED_F)
    mov qword ptr [rbp + 0x110], rax
    mov eax, dword ptr [rbp + 0x110]
    lea rdx, [rbp + 0x310]
    mov rcx, qword ptr [rbp + 0xc0]
    imul rcx, rcx, 4
    modrm add rdx, rcx
    add rdx, -4
    mov dword ptr [rdx], eax
    lea rax, [rbp + 0x2f0]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_421c:
    mov rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 0xa0]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd qword ptr [rbp + 0x108], xmm0
    lea rax, [rbp + 0x220]
    add rax, 0x28
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_42e6
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x28
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_42e6
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x108]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc0]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_42e6:
    lea rax, [rbp + 0x220]
    add rax, 0x10
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_43ac
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x10
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_43ac
    mov rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x108]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_43ac:
    lea rax, [rbp + 0x220]
    add rax, 0x18
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_4472
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x18
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4472
    mov rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 0x80]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x108]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_4472:
    lea rax, [rbp + 0x220]
    add rax, 0x20
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_4538
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x20
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4538
    mov rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 0x90]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x108]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_4538:
    lea rax, [rbp + 0x220]
    add rax, 0x40
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_463e
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x40
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_463e
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_STEP_INBASEUOM_F)
    movsd qword ptr [rbp + 0x118], xmm0
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x118]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x108]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_463e:
    lea rax, [rbp + 0x220]
    add rax, 0x70
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_4704
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x70
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4704
    mov rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 0xb0]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    movsd xmm0, qword ptr [rdx]
    movsd xmm1, qword ptr [rbp + 0x108]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_4704:
    lea rax, [rbp + 0x220]
    add rax, 0x48
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_47c0
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x48
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_47c0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_SBWEIGHT_F)
    movsd qword ptr [rbp + 0x120], xmm0
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x120]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_47c0:
    lea rax, [rbp + 0x220]
    add rax, 0x90
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_48e0
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0x90
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_48e0
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    lea rcx, [rip + reloc(.rdata, __NLITPACK_5 - .rdata)]
    mov qword ptr [rbp + 0x170], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x170]
    mov r8, rax
    call reloc(RTOVARLST_INQ_VAR_TARGET_HOMO_F)
    movsd qword ptr [rbp + 0x128], xmm0
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x128]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd xmm1, qword ptr [rbp + 0x108]
    mulsd xmm0, xmm1
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_48e0:
    lea rax, [rbp + 0x220]
    add rax, 0xb0
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_499e
    mov eax, 1
    add rax, qword ptr [rbp + 0xc8]
    mov qword ptr [rbp + 0xc8], rax
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 0
    mov eax, 0xb0
    add rax, qword ptr [rbp + 0x3b0]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_499e
    mov rax, qword ptr [rbp + 0x3a8]
    lea rdx, [rbp]
    mov rcx, rax
    call reloc(RTOVARLST_INQ_VAR_THRESHOLD_F)
    movsd qword ptr [rbp + 0x138], xmm0
    lea rax, [rbp + 0x350]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x138]
    movsd qword ptr [rax], xmm0
    lea rax, [rbp + 0x330]
    mov rdx, qword ptr [rbp + 0xc8]
    imul rdx, rdx, 4
    modrm add rax, rdx
    add rax, -4
    mov dword ptr [rax], 1
L_499e:
    mov qword ptr [rbp + 0x130], 0
    lea rax, [rbp + 0x220]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_49c3
    mov qword ptr [rbp + 0x130], 1
L_49c3:
    mov rax, qword ptr [rbp + 0x3a0]
    lea rdx, [rbp + 0x130]
    lea rcx, [rbp + 0xc8]
    lea rbx, [rbp + 0xc0]
    lea rsi, [rbp + 0x2f0]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp + 0x310]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x330]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rbp + 0x350]
    mov qword ptr [rsp + 0x38], rsi
    lea rsi, [rbp + 0x18]
    mov qword ptr [rsp + 0x40], rsi
    mov qword ptr [rbp + 0x178], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x178]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_UPDATE_XFILE_F)
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    long je L_4ac6
    mov rax, rsp
    mov qword ptr [rbp + 0x140], rax
    mov eax, 0x33
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x50]
    mov qword ptr [rbp + 0x148], rax
    mov rax, qword ptr [rbp + 0x148]
    mov qword ptr [rbp + 0x150], rax
    mov rax, qword ptr [rbp + 0x150]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_73 - .rdata)]
    mov ecx, 0x33
    mov qword ptr [rbp + 0x180], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x180]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0x150]
    mov edx, 0x33
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0x140]
    mov rsp, rax
    short jmp L_4ae7
L_4ac6:
    mov eax, 1
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    mov rdx, qword ptr [rbp + 0xb8]
    modrm cmp rax, rdx
    long jle L_3893
L_4ae7:
    mov rbx, qword ptr [rbp + 0x188]
    mov rsi, qword ptr [rbp + 0x190]
    lea rsp, [rbp + 0x390]
    pop rbp
    ret
end_RTXFILE_UPDATE_VARIABLE:

RTXFILE_QUERY:
    push rbp
pro_RTXFILE_QUERY_01:
    sub rsp, 0x2d0
pro_RTXFILE_QUERY_08:
    lea rbp, [rsp + 0x60]
pro_RTXFILE_QUERY_0d:
    mov qword ptr [rbp + 0x108], rsi
pro_RTXFILE_QUERY_14:
    mov qword ptr [rbp + 0x100], rbx
pro_RTXFILE_QUERY_1b:
    mov qword ptr [rbp + 0x280], rcx
    mov qword ptr [rbp + 0x288], rdx
    mov qword ptr [rbp + 0x290], r8
    mov qword ptr [rbp + 0x80], 0
    mov qword ptr [rbp + 0x88], 0
    mov qword ptr [rbp + 0x90], 1
    mov rax, qword ptr [rbp + 0x280]
    lea rdx, [rbp + 0x98]
    lea rcx, [rbp + 0x110]
    mov rbx, qword ptr [rbp + 0x288]
    lea rsi, [rbp + 0xa0]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp + 0xa8]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0xb0]
    mov qword ptr [rsp + 0x30], rsi
    mov qword ptr [rbp + 0xe0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xe0]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XHDR_F)
    mov rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_52c0
    mov rax, qword ptr [rbp + 0x290]
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_4bdd
    mov qword ptr [rbp + 0x90], 0
    long jmp L_52c0
L_4bdd:
    mov eax, 0x38
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4c24
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 8
L_4c24:
    mov eax, 0x60
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4c6b
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xd
L_4c6b:
    mov eax, 0x68
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4cb2
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xe
L_4cb2:
    mov eax, 0xa0
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4cf9
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x15
L_4cf9:
    mov eax, 0x30
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4d40
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 7
L_4d40:
    mov eax, 8
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4d87
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 2
L_4d87:
    mov eax, 0xc0
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4dce
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x19
L_4dce:
    mov eax, 0x80
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4e15
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x11
L_4e15:
    mov eax, 0x88
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4e5c
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x12
L_4e5c:
    mov eax, 0xb8
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4ea3
    mov eax, 1
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x190]
    mov rdx, qword ptr [rbp + 0x80]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x18
L_4ea3:
    mov eax, 0x28
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4eea
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 6
L_4eea:
    mov eax, 0x10
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4f31
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 3
L_4f31:
    mov eax, 0x18
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4f78
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 4
L_4f78:
    mov eax, 0x20
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_4fbf
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 5
L_4fbf:
    mov eax, 0x40
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_5006
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 9
L_5006:
    mov eax, 0x70
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_504d
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xf
L_504d:
    mov eax, 0x48
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_5094
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0xa
L_5094:
    mov eax, 0xb0
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_50db
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x17
L_50db:
    mov eax, 0x90
    add rax, qword ptr [rbp + 0x288]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_5122
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x1d0]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    modrm add rax, rdx
    add rax, -8
    mov qword ptr [rax], 0x13
L_5122:
    mov qword ptr [rbp + 0x98], 1
L_512d:
    mov rax, qword ptr [rbp + 0x280]
    mov edx, 0
    mov ecx, 8
    modrm add rdx, rcx
    add rdx, -8
    add rdx, qword ptr [rbp + 0x288]
    lea rcx, [rbp + 0x88]
    lea rbx, [rbp + 0x80]
    lea rsi, [rbp + 0xb8]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rbp]
    mov qword ptr [rsp + 0x28], rsi
    lea rsi, [rbp + 0x210]
    mov qword ptr [rsp + 0x30], rsi
    lea rsi, [rbp + 0x230]
    mov qword ptr [rsp + 0x38], rsi
    lea rsi, [rbp + 0xc0]
    mov qword ptr [rsp + 0x40], rsi
    lea rsi, [rbp + 0xb0]
    mov qword ptr [rsp + 0x48], rsi
    mov qword ptr [rsp + 0x50], 0x80
    mov qword ptr [rbp + 0xe8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xe8]
    mov r8, rax
    mov r9, rbx
    call reloc(RTO_READ_XFILE_F)
    mov rax, qword ptr [rbp + 0xb0]
    test rax, rax
    long je L_5259
    mov rax, rsp
    mov qword ptr [rbp + 0xc8], rax
    mov eax, 0x28
    add rax, 0xf
    and rax, 0xfffffffffffffff0
    call reloc(__chkstk)
    modrm sub rsp, rax
    lea rax, [rsp + 0x60]
    mov qword ptr [rbp + 0xd0], rax
    mov rax, qword ptr [rbp + 0xd0]
    mov qword ptr [rbp + 0xd8], rax
    mov rax, qword ptr [rbp + 0xd8]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_76 - .rdata)]
    mov ecx, 0x28
    mov qword ptr [rbp + 0xf0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xf0]
    mov r8, rax
    call reloc(memmove)
    mov rax, qword ptr [rbp + 0xd8]
    mov edx, 0x28
    mov rcx, rax
    call reloc(RTOHIS_WRITELN)
    mov rax, qword ptr [rbp + 0xc8]
    mov rsp, rax
    short jmp L_52c0
L_5259:
    mov rax, qword ptr [rbp + 0xc0]
    cmp rax, 1
    short je L_52b5
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x290]
    mov ecx, 0x80
    mov qword ptr [rbp + 0xf8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xf8]
    mov r8, rax
    call reloc(RTXFILE_QUERY_DIGEST)
    mov eax, 1
    add rax, qword ptr [rbp + 0x98]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x98]
    cmp rax, 0x5f5e100
    long jle L_512d
L_52b5:
    mov qword ptr [rbp + 0x90], 0
L_52c0:
    mov rax, qword ptr [rbp + 0x90]
    mov rbx, qword ptr [rbp + 0x100]
    mov rsi, qword ptr [rbp + 0x108]
    lea rsp, [rbp + 0x270]
    pop rbp
    ret
end_RTXFILE_QUERY:
    nop
    nop

.section .rdata 0x40600040
__STRLITPACK_15:
    .ascii "been created with the save "
    .byte 0x00
__STRLITPACK_14:
    .ascii "variables command"
    .zero 3
__STRLITPACK_11:
    .ascii "Restoring values by name"
    .zero 4
__STRLITPACK_8:
    .ascii "being updated. Possible mismatch of "
    .zero 4
__STRLITPACK_7:
    .ascii "number of equations. "
    .zero 3
__STRLITPACK_4:
    .ascii "been created with the save "
    .byte 0x00
__STRLITPACK_3:
    .ascii "variables command"
    .zero 3
__STRLITPACK_0:
    .ascii "not currently in file"
    .zero 7
__NLITPACK_0:
    .byte 0xfe, 0xff, 0xff, 0x7f
    .zero 4
__STRLITPACK_18:
    .ascii "!! rtxfile_open: The file appears not to have "
    .zero 2
__STRLITPACK_19:
    .ascii "Matched message digest, restoring values by index"
    .zero 3
__STRLITPACK_20:
    .ascii "!! rtxfile_open: Current digest does not match x-file "
    .zero 2
__STRLITPACK_21:
    .ascii "!! rtxfile_open: The file appears not to have "
    .zero 2
__STRLITPACK_22:
    .ascii "!! rtxfile_open: Attemping update with attributes"
    .zero 3
__NLITPACK_1:
    .zero 8
__STRLITPACK_27:
    .ascii "!! rtxfile_save_variable: Variable subscript is out of range"
    .zero 4
__STRLITPACK_28:
    .ascii "!! rtxfile_save_variable: Problem writing X file"
    .zero 4
__STRLITPACK_57:
    .ascii "and cannot"
    .zero 2
__STRLITPACK_52:
    .ascii "  spec"
    .zero 2
__STRLITPACK_51:
    .ascii "  baseuom"
    .zero 3
__STRLITPACK_50:
    .ascii "  quality"
    .zero 3
__STRLITPACK_49:
    .ascii "  modified-mask1"
    .zero 4
__STRLITPACK_48:
    .ascii "  modified-mask2"
    .zero 4
__STRLITPACK_47:
    .ascii "  UOM"
    .zero 3
__STRLITPACK_46:
    .ascii "  physical type"
    .byte 0x00
__STRLITPACK_45:
    .ascii "  connection type"
    .zero 3
__STRLITPACK_44:
    .ascii "  bound type   "
    .byte 0x00
__STRLITPACK_43:
    .ascii "  homotopy param"
    .zero 4
__STRLITPACK_42:
    .ascii "  scale"
    .byte 0x00
__STRLITPACK_41:
    .ascii "  lower"
    .byte 0x00
__STRLITPACK_40:
    .ascii "  value"
    .byte 0x00
__STRLITPACK_39:
    .ascii "  upper"
    .byte 0x00
__STRLITPACK_38:
    .ascii "  step"
    .zero 2
__STRLITPACK_37:
    .ascii "  initial"
    .zero 3
__STRLITPACK_36:
    .ascii "  SBWeight"
    .zero 2
__STRLITPACK_35:
    .ascii "  homotopy target"
    .zero 3
__STRLITPACK_34:
    .ascii "  threshold"
    .byte 0x00
__STRLITPACK_33:
    .ascii "  ramped"
    .zero 4
__STRLITPACK_30:
    .ascii "ZFLOW"
    .zero 3
__STRLITPACK_29:
    .ascii "ZFRAC"
    .zero 7
__STRLITPACK_60:
    .ascii "Variables in this file were not saved with the NAME attribute, "
    .byte 0x00
__STRLITPACK_62:
    .ascii "Variables in this file were saved  with the following attributes:"
    .zero 7
__NLITPACK_2:
    .byte 0x80
    .zero 7
__NLITPACK_3:
    .zero 8
__STRLITPACK_61:
    .ascii "be restored into the current configuration."
    .byte 0x00
__STRLITPACK_63:
    .ascii "!! rtxfile_restore_variable: Problem reading X file"
    .byte 0x00
__NLITPACK_4:
    .zero 8
__STRLITPACK_66:
    .ascii "updated are mismatched."
    .zero 9
__STRLITPACK_72:
    .ascii "!! rtxfile_update_variable: There current variable list and x-file being "
    .zero 7
__NLITPACK_5:
    .zero 8
__STRLITPACK_71:
    .ascii "!! rtxfile_update_variable: Problem reading Header record"
    .zero 3
__STRLITPACK_73:
    .ascii "!! rtxfile_update_variable: Problem updating X file"
    .byte 0x00
__STRLITPACK_76:
    .ascii "!! rtxfile_query: Problem reading X file"
    .zero 16

.section .xdata 0x40300040
unwind_RTXFILE_OPEN:
    .unwind RTXFILE_OPEN, pro_RTXFILE_OPEN_1b, rbp, 80
        .save_nonvol pro_RTXFILE_OPEN_1b, rbx, 528
        .save_nonvol pro_RTXFILE_OPEN_14, rsi, 536
        .set_fpreg pro_RTXFILE_OPEN_0d
        .alloc_large pro_RTXFILE_OPEN_08, 880
        .push_nonvol pro_RTXFILE_OPEN_01, rbp
    .endunwind
unwind_RTXFILE_CLOSE:
    .unwind RTXFILE_CLOSE, pro_RTXFILE_CLOSE_0a, rbp, 32
        .set_fpreg pro_RTXFILE_CLOSE_0a
        .alloc_small pro_RTXFILE_CLOSE_05, 48
        .push_nonvol pro_RTXFILE_CLOSE_01, rbp
    .endunwind
unwind_RTXFILE_SAVE_VARIABLE:
    .unwind RTXFILE_SAVE_VARIABLE, pro_RTXFILE_SAVE_VARIABLE_1b, rbp, 80
        .save_nonvol pro_RTXFILE_SAVE_VARIABLE_1b, rbx, 512
        .save_nonvol pro_RTXFILE_SAVE_VARIABLE_14, rsi, 520
        .set_fpreg pro_RTXFILE_SAVE_VARIABLE_0d
        .alloc_large pro_RTXFILE_SAVE_VARIABLE_08, 624
        .push_nonvol pro_RTXFILE_SAVE_VARIABLE_01, rbp
    .endunwind
unwind_RTXFILE_MATCH_MD:
    .unwind RTXFILE_MATCH_MD, pro_RTXFILE_MATCH_MD_0a, rbp, 32
        .set_fpreg pro_RTXFILE_MATCH_MD_0a
        .alloc_small pro_RTXFILE_MATCH_MD_05, 48
        .push_nonvol pro_RTXFILE_MATCH_MD_01, rbp
    .endunwind
unwind_RTXFILE_RESTORE_EXCEPT:
    .unwind RTXFILE_RESTORE_EXCEPT, pro_RTXFILE_RESTORE_EXCEPT_1b, rbp, 96
        .save_nonvol pro_RTXFILE_RESTORE_EXCEPT_1b, rbx, 808
        .save_nonvol pro_RTXFILE_RESTORE_EXCEPT_14, rsi, 816
        .set_fpreg pro_RTXFILE_RESTORE_EXCEPT_0d
        .alloc_large pro_RTXFILE_RESTORE_EXCEPT_08, 1392
        .push_nonvol pro_RTXFILE_RESTORE_EXCEPT_01, rbp
    .endunwind
unwind_RTXFILE_RESTORE_VARIABLE:
    .unwind RTXFILE_RESTORE_VARIABLE, pro_RTXFILE_RESTORE_VARIABLE_15, rbp, 80
        .save_nonvol pro_RTXFILE_RESTORE_VARIABLE_15, rbx, 104
        .save_nonvol pro_RTXFILE_RESTORE_VARIABLE_11, rsi, 112
        .set_fpreg pro_RTXFILE_RESTORE_VARIABLE_0d
        .alloc_large pro_RTXFILE_RESTORE_VARIABLE_08, 144
        .push_nonvol pro_RTXFILE_RESTORE_VARIABLE_01, rbp
    .endunwind
unwind_RTXFILE_UPDATE_VARIABLE:
    .unwind RTXFILE_UPDATE_VARIABLE, pro_RTXFILE_UPDATE_VARIABLE_1b, rbp, 80
        .save_nonvol pro_RTXFILE_UPDATE_VARIABLE_1b, rbx, 472
        .save_nonvol pro_RTXFILE_UPDATE_VARIABLE_14, rsi, 480
        .set_fpreg pro_RTXFILE_UPDATE_VARIABLE_0d
        .alloc_large pro_RTXFILE_UPDATE_VARIABLE_08, 992
        .push_nonvol pro_RTXFILE_UPDATE_VARIABLE_01, rbp
    .endunwind
unwind_RTXFILE_QUERY:
    .unwind RTXFILE_QUERY, pro_RTXFILE_QUERY_1b, rbp, 96
        .save_nonvol pro_RTXFILE_QUERY_1b, rbx, 352
        .save_nonvol pro_RTXFILE_QUERY_14, rsi, 360
        .set_fpreg pro_RTXFILE_QUERY_0d
        .alloc_large pro_RTXFILE_QUERY_08, 720
        .push_nonvol pro_RTXFILE_QUERY_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTXFILE_OPEN
    .rva RTXFILE_OPEN, end_RTXFILE_OPEN - RTXFILE_OPEN
    .rva .xdata, unwind_RTXFILE_OPEN - .xdata
    .rva RTXFILE_CLOSE
    .rva RTXFILE_CLOSE, end_RTXFILE_CLOSE - RTXFILE_CLOSE
    .rva .xdata, unwind_RTXFILE_CLOSE - .xdata
    .rva RTXFILE_SAVE_VARIABLE
    .rva RTXFILE_SAVE_VARIABLE, end_RTXFILE_SAVE_VARIABLE - RTXFILE_SAVE_VARIABLE
    .rva .xdata, unwind_RTXFILE_SAVE_VARIABLE - .xdata
    .rva RTXFILE_MATCH_MD
    .rva RTXFILE_MATCH_MD, end_RTXFILE_MATCH_MD - RTXFILE_MATCH_MD
    .rva .xdata, unwind_RTXFILE_MATCH_MD - .xdata
    .rva RTXFILE_RESTORE_EXCEPT
    .rva RTXFILE_RESTORE_EXCEPT, end_RTXFILE_RESTORE_EXCEPT - RTXFILE_RESTORE_EXCEPT
    .rva .xdata, unwind_RTXFILE_RESTORE_EXCEPT - .xdata
    .rva RTXFILE_RESTORE_VARIABLE
    .rva RTXFILE_RESTORE_VARIABLE, end_RTXFILE_RESTORE_VARIABLE - RTXFILE_RESTORE_VARIABLE
    .rva .xdata, unwind_RTXFILE_RESTORE_VARIABLE - .xdata
    .rva RTXFILE_UPDATE_VARIABLE
    .rva RTXFILE_UPDATE_VARIABLE, end_RTXFILE_UPDATE_VARIABLE - RTXFILE_UPDATE_VARIABLE
    .rva .xdata, unwind_RTXFILE_UPDATE_VARIABLE - .xdata
    .rva RTXFILE_QUERY
    .rva RTXFILE_QUERY, end_RTXFILE_QUERY - RTXFILE_QUERY
    .rva .xdata, unwind_RTXFILE_QUERY - .xdata

.section .drectve 0x00100a00
    .ascii "-export:RTXFILE_QUERY  -export:RTXFILE_UPDATE_VARIABLE  -export:RTXFILE_RESTORE_VARIABLE  -export:RTXFILE_RESTORE_EXCEPT  -export:RTXFILE_SAVE_VARIABLE  -export:RTXFILE_CLOSE  -export:RTXFILE_OPEN  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\rto_share_open.obj 1743626481
.index RTO_FLUSH_UNIT
.index RTO_OPFUNT
.index RTO_SHARE_OPEN

.symbol .text section local
.symbol RTO_SHARE_OPEN function public
.symbol RTO_FLUSH_UNIT function public
.symbol RTO_OPFUNT function public
.symbol .rdata section local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_3 data local
.symbol __STRLITPACK_2 data local
.symbol for_inquire external public function
.symbol for_cpystr external public function
.symbol for_open external public function
.symbol .data section local
.symbol for_read_seq_fmt external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol RTO_SHARE_OPEN$format_pack data local
.symbol __STRLITPACK_5 data local
.symbol __STRLITPACK_6 data local
.symbol __STRLITPACK_7 data local
.symbol __STRLITPACK_8 data local
.symbol __STRLITPACK_9 data local
.symbol .drectve section local
.symbol __ImageBase external public function

.section .text 0x60300020

RTO_SHARE_OPEN:
    push rbp
pro_RTO_SHARE_OPEN_01:
    sub rsp, 0x1c0
pro_RTO_SHARE_OPEN_08:
    lea rbp, [rsp + 0x30]
pro_RTO_SHARE_OPEN_0d:
    mov qword ptr [rbp + 0x180], rsi
pro_RTO_SHARE_OPEN_14:
    mov qword ptr [rbp + 0x178], rbx
pro_RTO_SHARE_OPEN_1b:
    mov qword ptr [rbp + 0x1a0], rcx
    mov qword ptr [rbp + 0x1a8], rdx
    mov qword ptr [rbp + 0x1b0], r8
    mov qword ptr [rbp + 0x1b8], r9
    mov rax, qword ptr [rbp + 0x1b0]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x1a8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jg L_005e
    mov qword ptr [rbp + 0x40], 0
    short jmp L_0066
L_005e:
    mov qword ptr [rbp + 0x40], 0xffffffffffffffff
L_0066:
    mov rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x1b8]
    mov qword ptr [rbp + 0x50], rax
    mov qword ptr [rbp + 0x58], 0
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x1a0]
    mov qword ptr [rbp + 0x90], rax
    lea rax, [rbp + 0xa8]
    mov qword ptr [rbp + 0x98], rax
    lea rax, [rbp + 0xb0]
    mov qword ptr [rbp + 0xa0], rax
    lea rax, [rbp + 0x58]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_5 - .rdata)]
    lea rsi, [rbp + 0x88]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x138], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x138]
    mov r8, rax
    mov r9, rbx
    call reloc(for_inquire)
    mov eax, dword ptr [rbp + 0xb0]
    test al, 1
    short je L_0120
    mov rax, qword ptr [rbp + 0x1a8]
    mov rdx, qword ptr [rbp + 0xa8]
    mov qword ptr [rax], rdx
    mov qword ptr [rbp + 0x48], 0
    long jmp L_0385
L_0120:
    mov rax, qword ptr [rbp + 0x1a8]
    mov rax, qword ptr [rax]
    mov rdx, rax
    sar rdx, 0x3f
    modrm xor rax, rdx
    modrm sub rax, rdx
    mov qword ptr [rbp + 0xa8], rax
    mov qword ptr [rbp + 0xb8], 0x63
    lea rax, [rbp + 0xa8]
    lea rdx, [rbp + 0xb8]
    mov rcx, qword ptr [rbp + 0x1a8]
    mov qword ptr [rbp + 0x140], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x140]
    mov r8, rax
    call reloc(RTO_OPFUNT)
    mov rax, qword ptr [rbp + 0x1b8]
    mov qword ptr [rbp + 0xc0], rax
    mov qword ptr [rbp + 0x58], 0
    mov rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc8], rax
    mov rax, qword ptr [rbp + 0x1a0]
    mov qword ptr [rbp + 0xd0], rax
    lea rax, [rbp + 0xe0]
    mov qword ptr [rbp + 0xd8], rax
    lea rax, [rbp + 0x58]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_6 - .rdata)]
    lea rsi, [rbp + 0xc8]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x148], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x148]
    mov r8, rax
    mov r9, rbx
    call reloc(for_inquire)
    mov eax, dword ptr [rbp + 0xe0]
    test al, 1
    short jne L_020b
    mov qword ptr [rbp + 0x48], 0
L_020b:
    lea rax, [rbp + 1]
    mov edx, 0x14
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    mov ebx, 0xa
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x150], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x150]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    lea rax, [rbp + 0x15]
    mov edx, 0x14
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    mov ebx, 7
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x158], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x158]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    mov eax, dword ptr [rbp + 0x48]
    test al, 1
    short je L_02c8
    mov qword ptr [rbp + 0x48], 0
    lea rax, [rbp + 1]
    mov edx, 0x14
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_2 - .rdata)]
    mov ebx, 6
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x160], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x160]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
L_02c8:
    mov rax, qword ptr [rbp + 0x1b8]
    mov qword ptr [rbp + 0x100], rax
    mov qword ptr [rbp + 0x58], 0
    mov rax, qword ptr [rbp + 0x100]
    mov qword ptr [rbp + 0x108], rax
    mov rax, qword ptr [rbp + 0x1a0]
    mov qword ptr [rbp + 0x110], rax
    mov qword ptr [rbp + 0x118], 0x14
    lea rax, [rbp + 1]
    mov qword ptr [rbp + 0x120], rax
    mov qword ptr [rbp + 0x128], 0x14
    lea rax, [rbp + 0x15]
    mov qword ptr [rbp + 0x130], rax
    lea rax, [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x1a8]
    mov edx, dword ptr [rdx]
    mov rcx, 0x881208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    lea rsi, [rbp + 0x108]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x168], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x168]
    mov r8, rax
    mov r9, rbx
    call reloc(for_open)
    mov dword ptr [rbp + 0x34], eax
    mov eax, dword ptr [rbp + 0x34]
    mov dword ptr [rbp + 0x38], eax
    mov eax, dword ptr [rbp + 0x38]
    movsxd rax, eax
    mov rdx, qword ptr [rbp + 0x1b0]
    mov qword ptr [rdx], rax
L_0385:
    mov eax, dword ptr [rbp + 0x48]
    test al, 1
    long je L_0449
    mov qword ptr [rbp + 0xe8], 1
L_039b:
    mov qword ptr [rbp + 0x58], 0
    mov qword ptr [rbp + 0xf0], 1
    lea rax, [rbp]
    mov qword ptr [rbp + 0xf8], rax
    lea rax, [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x1a8]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff03
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_8 - .rdata)]
    lea rsi, [rbp + 0xf0]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rip + reloc(.data, RTO_SHARE_OPEN$format_pack - .data)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x170], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x170]
    mov r8, rax
    mov r9, rbx
    call reloc(for_read_seq_fmt)
    mov dword ptr [rbp + 0x2c], eax
    mov eax, dword ptr [rbp + 0x2c]
    mov dword ptr [rbp + 0x30], eax
    mov eax, dword ptr [rbp + 0x30]
    cmp eax, -1
    short je L_0449
    mov eax, dword ptr [rbp + 0x30]
    test eax, eax
    short jg L_0449
    mov eax, 1
    add rax, qword ptr [rbp + 0xe8]
    mov qword ptr [rbp + 0xe8], rax
    mov rax, qword ptr [rbp + 0xe8]
    cmp rax, 0x5f5e100
    long jle L_039b
L_0449:
    mov rbx, qword ptr [rbp + 0x178]
    mov rsi, qword ptr [rbp + 0x180]
    lea rsp, [rbp + 0x190]
    pop rbp
    ret
end_RTO_SHARE_OPEN:

RTO_FLUSH_UNIT:
    push rbp
pro_RTO_FLUSH_UNIT_01:
    sub rsp, 0x20
pro_RTO_FLUSH_UNIT_05:
    lea rbp, [rsp + 0x20]
pro_RTO_FLUSH_UNIT_0a:
    mov qword ptr [rbp + 0x10], rcx
    lea rsp, [rbp]
    pop rbp
    ret
end_RTO_FLUSH_UNIT:

RTO_OPFUNT:
    push rbp
pro_RTO_OPFUNT_01:
    sub rsp, 0x90
pro_RTO_OPFUNT_08:
    lea rbp, [rsp + 0x30]
pro_RTO_OPFUNT_0d:
    mov qword ptr [rbp + 0x58], rsi
pro_RTO_OPFUNT_11:
    mov qword ptr [rbp + 0x50], rbx
pro_RTO_OPFUNT_15:
    mov qword ptr [rbp + 0x70], rcx
    mov qword ptr [rbp + 0x78], rdx
    mov qword ptr [rbp + 0x80], r8
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x70]
    mov rdx, qword ptr [rbp + 0x80]
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp]
    mov rdx, qword ptr [rbp + 0x70]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    long jl L_0548
L_04c8:
    mov qword ptr [rbp + 8], 0
    lea rax, [rbp + 0x38]
    mov qword ptr [rbp + 0x40], rax
    lea rax, [rbp + 8]
    mov rdx, qword ptr [rbp + 0x80]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_9 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x48], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x48]
    mov r8, rax
    mov r9, rbx
    call reloc(for_inquire)
    mov eax, dword ptr [rbp + 0x38]
    test al, 1
    short je L_0556
    mov rax, qword ptr [rbp + 0x80]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x80]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x80]
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp]
    modrm cmp rax, rdx
    short jle L_04c8
L_0548:
    mov rax, qword ptr [rbp + 0x80]
    mov qword ptr [rax], 0xffffffffffffffff
L_0556:
    mov rbx, qword ptr [rbp + 0x50]
    mov rsi, qword ptr [rbp + 0x58]
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_RTO_OPFUNT:

.section .rdata 0x40300040
__STRLITPACK_4:
    .ascii "SEQUENTIAL"
    .zero 2
__STRLITPACK_3:
    .ascii "UNKNOWN"
    .byte 0x00
__STRLITPACK_2:
    .ascii "APPEND"
    .zero 2
__STRLITPACK_5:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x0b, 0x03, 0x21, 0x00, 0x11, 0x03, 0x23, 0x00, 0x01
    .zero 7
__STRLITPACK_6:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x11, 0x03, 0x1b, 0x00, 0x01
    .zero 3
    .byte 0x01
    .zero 3
__STRLITPACK_7:
    .byte 0x38, 0x04, 0x0d, 0x00, 0x38, 0x04, 0x02, 0x00, 0x38, 0x04, 0x1a, 0x00, 0x01
    .zero 7
__STRLITPACK_8:
    .byte 0x38, 0x04, 0x01, 0x00, 0x38
    .zero 3
__STRLITPACK_9:
    .byte 0x11, 0x03, 0x23, 0x00, 0x01
    .zero 3
    .byte 0x38
    .zero 3

.section .data 0xc0300040
RTO_SHARE_OPEN$format_pack:
    .byte 0x36
    .zero 3
    .byte 0x48, 0x00, 0x01, 0x00, 0x37
    .zero 3

.section .xdata 0x40300040
unwind_RTO_SHARE_OPEN:
    .unwind RTO_SHARE_OPEN, pro_RTO_SHARE_OPEN_1b, rbp, 48
        .save_nonvol pro_RTO_SHARE_OPEN_1b, rbx, 424
        .save_nonvol pro_RTO_SHARE_OPEN_14, rsi, 432
        .set_fpreg pro_RTO_SHARE_OPEN_0d
        .alloc_large pro_RTO_SHARE_OPEN_08, 448
        .push_nonvol pro_RTO_SHARE_OPEN_01, rbp
    .endunwind
unwind_RTO_FLUSH_UNIT:
    .unwind RTO_FLUSH_UNIT, pro_RTO_FLUSH_UNIT_0a, rbp, 32
        .set_fpreg pro_RTO_FLUSH_UNIT_0a
        .alloc_small pro_RTO_FLUSH_UNIT_05, 32
        .push_nonvol pro_RTO_FLUSH_UNIT_01, rbp
    .endunwind
unwind_RTO_OPFUNT:
    .unwind RTO_OPFUNT, pro_RTO_OPFUNT_15, rbp, 48
        .save_nonvol pro_RTO_OPFUNT_15, rbx, 128
        .save_nonvol pro_RTO_OPFUNT_11, rsi, 136
        .set_fpreg pro_RTO_OPFUNT_0d
        .alloc_large pro_RTO_OPFUNT_08, 144
        .push_nonvol pro_RTO_OPFUNT_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTO_SHARE_OPEN
    .rva RTO_SHARE_OPEN, end_RTO_SHARE_OPEN - RTO_SHARE_OPEN
    .rva .xdata, unwind_RTO_SHARE_OPEN - .xdata
    .rva RTO_FLUSH_UNIT
    .rva RTO_FLUSH_UNIT, end_RTO_FLUSH_UNIT - RTO_FLUSH_UNIT
    .rva .xdata, unwind_RTO_FLUSH_UNIT - .xdata
    .rva RTO_OPFUNT
    .rva RTO_OPFUNT, end_RTO_OPFUNT - RTO_OPFUNT
    .rva .xdata, unwind_RTO_OPFUNT - .xdata

.section .drectve 0x00100a00
    .ascii "-export:RTO_FLUSH_UNIT  -export:RTO_OPFUNT  -export:RTO_SHARE_OPEN  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\rto_freioc.obj 1743626481
.index RTO_FREIOC

.symbol .text section local
.symbol RTO_FREIOC function public
.symbol RTUT_RTIOC common public 352
.symbol .xdata section local
.symbol .pdata section local
.symbol .drectve section local
.symbol __ImageBase external public function

.section .text 0x60300020

RTO_FREIOC:
    ; Accept unit numbers in the inclusive range 60..99 before clearing the corresponding table slot.
    push rbp
pro_RTO_FREIOC_01:
    sub rsp, 0x20
pro_RTO_FREIOC_05:
    lea rbp, [rsp + 0x20]
pro_RTO_FREIOC_0a:
    mov qword ptr [rbp + 0x10], rcx
    mov rax, qword ptr [rbp + 0x10]
    mov rax, qword ptr [rax]
    cmp rax, 0x3c
    short jl L_0066
    mov rax, qword ptr [rbp + 0x10]
    mov rax, qword ptr [rax]
    cmp rax, 0x64
    short jge L_0066
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, 0xffffffffffffffc4
    add rdx, qword ptr [rax]
    mov qword ptr [rip + reloc(RTUT_RTIOC)], rdx
    mov eax, 1
    add rax, qword ptr [rip + reloc(RTUT_RTIOC)]
    imul rax, rax, 8
    lea rdx, [rip + reloc(RTUT_RTIOC)]
    add rdx, 8
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
L_0066:
    lea rsp, [rbp]
    pop rbp
    ret
end_RTO_FREIOC:

.section .xdata 0x40300040
unwind_RTO_FREIOC:
    .unwind RTO_FREIOC, pro_RTO_FREIOC_0a, rbp, 32
        .set_fpreg pro_RTO_FREIOC_0a
        .alloc_small pro_RTO_FREIOC_05, 32
        .push_nonvol pro_RTO_FREIOC_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTO_FREIOC
    .rva RTO_FREIOC, end_RTO_FREIOC - RTO_FREIOC
    .rva .xdata, unwind_RTO_FREIOC - .xdata

.section .drectve 0x00100a00
    .ascii "-export:RTO_FREIOC  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\oomf_aemap.obj 1743626481
.index NZ_IN_ROW
.index OOMF_PLEX
.index U3MAP_REL_INCIDENCE
.index U3MAP_VAR_INCIDENCE
.index U3PERM_APPLY_IVEC
.index U3PERM_APPLY_RVEC
.index U3PERM_COMP2UNCOMP
.index U3PERM_COPY_APPLY_IVEC
.index U3PERM_COPY_APPLY_RVEC
.index U3PERM_DESTROY
.index U3PERM_EQN_CREATE
.index U3PERM_EQN_CREATE_INCIDENCE
.index U3PERM_JAC_APPLY_COL
.index U3PERM_JAC_APPLY_ROW
.index U3PERM_JAC_COPY_APPLY_COL
.index U3PERM_JAC_COPY_APPLY_ROW
.index U3PERM_JAC_CREATE
.index U3PERM_JAC_CREATE_INCIDENCE
.index U3PERM_UNCOMP2COMP
.index U3PERM_VAR_CREATE
.index U3PERM_VAR_CREATE_INCIDENCE
.index U3PERM_VAR_CREATE_INCIDENCEONLY
.index U3REMAP
.index USR3_FNDOBJ

.symbol .text section local
.symbol U3PERM_VAR_CREATE function public
.symbol U3PERM_VAR_CREATE_INCIDENCE function public
.symbol U3PERM_VAR_CREATE_INCIDENCEONLY function public
.symbol U3PERM_DESTROY function public
.symbol U3PERM_APPLY_RVEC function public
.symbol U3PERM_COPY_APPLY_RVEC function public
.symbol U3PERM_APPLY_IVEC function public
.symbol U3PERM_COPY_APPLY_IVEC function public
.symbol U3PERM_EQN_CREATE function public
.symbol U3PERM_EQN_CREATE_INCIDENCE function public
.symbol U3PERM_JAC_CREATE function public
.symbol U3PERM_JAC_CREATE_INCIDENCE function public
.symbol U3PERM_JAC_APPLY_ROW function public
.symbol U3PERM_JAC_COPY_APPLY_ROW function public
.symbol U3PERM_JAC_APPLY_COL function public
.symbol U3PERM_JAC_COPY_APPLY_COL function public
.symbol U3PERM_COMP2UNCOMP function public
.symbol U3PERM_UNCOMP2COMP function public
.symbol U3MAP_REL_INCIDENCE function public
.symbol U3MAP_VAR_INCIDENCE function public
.symbol U3REMAP function public
.symbol USR3_FNDOBJ function public
.symbol NZ_IN_ROW function public
.symbol OOMF_PLEX common public 128
.symbol RTO_IMALLOC external public function
.symbol U3VFXD external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol RTO_IFREE external public function
.symbol RTO_DMALLOC external public function
.symbol U3RINC external public function
.symbol U3RGMT external public function
.symbol .rdata section local
.symbol __STRLITPACK_2 data local
.symbol __STRLITPACK_1 data local
.symbol __STRLITPACK_0 data local
.symbol for_write_seq_lis external public function
.symbol for_write_seq_lis_xmit external public function
.symbol __STRLITPACK_3 data local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_5 data local
.symbol __STRLITPACK_6 data local
.symbol __STRLITPACK_7 data local
.symbol __STRLITPACK_10 data local
.symbol __STRLITPACK_9 data local
.symbol __STRLITPACK_8 data local
.symbol __STRLITPACK_11 data local
.symbol __STRLITPACK_12 data local
.symbol __STRLITPACK_13 data local
.symbol __STRLITPACK_14 data local
.symbol __STRLITPACK_15 data local
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

U3PERM_VAR_CREATE:
    push rbp
pro_U3PERM_VAR_CREATE_01:
    sub rsp, 0x80
pro_U3PERM_VAR_CREATE_08:
    lea rbp, [rsp + 0x20]
pro_U3PERM_VAR_CREATE_0d:
    mov qword ptr [rbp + 0x70], rcx
    mov qword ptr [rbp + 0x78], rdx
    mov qword ptr [rbp + 0x80], r8
    mov qword ptr [rbp + 0x88], r9
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x78]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x80]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x30], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_026b
L_00af:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x70]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x38], rax
    mov eax, dword ptr [rbp + 0x38]
    test al, 1
    long je L_0209
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x48], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x30]
    modrm cmp rdx, rax
    long jl L_023d
L_0117:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x48]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x70]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x50], rax
    mov eax, dword ptr [rbp + 0x50]
    test al, 1
    short je L_01ac
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x48]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x48]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x48]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    mov rdx, qword ptr [rbp + 0x40]
    modrm cmp rax, rdx
    long jge L_0117
    long jmp L_023d
L_01ac:
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x48]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x48]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_023d
L_0209:
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_023d:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_026b
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_00af
L_026b:
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x88]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x80]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x80]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_U3PERM_VAR_CREATE:

U3PERM_VAR_CREATE_INCIDENCE:
    push rbp
pro_U3PERM_VAR_CREATE_INCIDENCE_01:
    sub rsp, 0x80
pro_U3PERM_VAR_CREATE_INCIDENCE_08:
    lea rbp, [rsp + 0x20]
pro_U3PERM_VAR_CREATE_INCIDENCE_0d:
    mov qword ptr [rbp + 0x70], rcx
    mov qword ptr [rbp + 0x78], rdx
    mov qword ptr [rbp + 0x80], r8
    mov qword ptr [rbp + 0x88], r9
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x78]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x88]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov qword ptr [rbp + 0x38], 1
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jle L_05b2
L_03b2:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x38]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x70]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x40], rax
    mov eax, dword ptr [rbp + 0x40]
    test al, 1
    short jne L_0407
    mov rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    long jne L_0550
L_0407:
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x38]
    modrm cmp rdx, rax
    long jl L_0584
L_043c:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x70]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x58], rax
    mov eax, dword ptr [rbp + 0x58]
    test al, 1
    short jne L_049a
    mov rax, qword ptr [rbp + 0x50]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    short jne L_04f3
L_049a:
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x50]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x48]
    modrm cmp rax, rdx
    long jge L_043c
    long jmp L_0584
L_04f3:
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x50]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_0584
L_0550:
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_0584:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_05b2
    mov eax, 1
    add rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long jle L_03b2
L_05b2:
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x90]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x88]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, qword ptr [rbp + 0x88]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_U3PERM_VAR_CREATE_INCIDENCE:

U3PERM_VAR_CREATE_INCIDENCEONLY:
    push rbp
pro_U3PERM_VAR_CREATE_INCIDENCEONLY_01:
    sub rsp, 0x70
pro_U3PERM_VAR_CREATE_INCIDENCEONLY_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_VAR_CREATE_INCIDENCEONLY_0a:
    mov qword ptr [rbp + 0x60], rcx
    mov qword ptr [rbp + 0x68], rdx
    mov qword ptr [rbp + 0x70], r8
    mov qword ptr [rbp + 0x78], r9
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x68]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x70]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rdx
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov qword ptr [rbp + 0x38], 1
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jle L_0879
L_06e7:
    mov rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    long jne L_081a
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x48], rdx
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x38]
    modrm cmp rdx, rax
    long jl L_084b
L_0742:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x48]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    short jne L_07c3
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x48]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x48]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x48]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    mov rdx, qword ptr [rbp + 0x40]
    modrm cmp rax, rdx
    short jge L_0742
    long jmp L_084b
L_07c3:
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x48]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x48]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_084b
L_081a:
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_084b:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_0879
    mov eax, 1
    add rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long jle L_06e7
L_0879:
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x80]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rbp + 0x78]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x80]
    mov rdx, qword ptr [rbp + 0x78]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x50]
    pop rbp
    ret
end_U3PERM_VAR_CREATE_INCIDENCEONLY:

U3PERM_DESTROY:
    push rbp
pro_U3PERM_DESTROY_01:
    sub rsp, 0x20
pro_U3PERM_DESTROY_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_DESTROY_0a:
    mov qword ptr [rbp + 0x10], rcx
    mov rax, qword ptr [rbp + 0x10]
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_091c
    mov rax, qword ptr [rbp + 0x10]
    mov rcx, rax
    call reloc(RTO_IFREE)
L_091c:
    lea rsp, [rbp]
    pop rbp
    ret
end_U3PERM_DESTROY:

U3PERM_APPLY_RVEC:
    push rbp
pro_U3PERM_APPLY_RVEC_01:
    sub rsp, 0x60
pro_U3PERM_APPLY_RVEC_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_APPLY_RVEC_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    long jle L_0a8b
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x18]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jl L_0a8b
L_09e2:
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x20]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short je L_0a6d
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rbp + 0x30], xmm0
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x58]
    add rdx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rdx], xmm0
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    movsd xmm0, qword ptr [rbp + 0x30]
    movsd qword ptr [rax], xmm0
L_0a6d:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    long jle L_09e2
L_0a8b:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3PERM_APPLY_RVEC:

U3PERM_COPY_APPLY_RVEC:
    push rbp
pro_U3PERM_COPY_APPLY_RVEC_01:
    sub rsp, 0x60
pro_U3PERM_COPY_APPLY_RVEC_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_COPY_APPLY_RVEC_0a:
    mov qword ptr [rbp + 0x30], rbx
pro_U3PERM_COPY_APPLY_RVEC_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_DMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rdx
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    short jle L_0b88
L_0b3c:
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x28]
    add rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    movsd xmm0, qword ptr [rax]
    movsd qword ptr [rcx], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_0b3c
L_0b88:
    mov rax, qword ptr [rbp + 0x50]
    mov edx, 8
    neg rdx
    mov rcx, qword ptr [rbp + 0x60]
    mov rcx, qword ptr [rcx]
    imul rcx, rcx, 8
    lea rbx, [rip + reloc(OOMF_PLEX)]
    modrm add rbx, rcx
    modrm add rdx, rbx
    mov rcx, rax
    call reloc(U3PERM_APPLY_RVEC)
    mov rbx, qword ptr [rbp + 0x30]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3PERM_COPY_APPLY_RVEC:

U3PERM_APPLY_IVEC:
    push rbp
pro_U3PERM_APPLY_IVEC_01:
    sub rsp, 0x60
pro_U3PERM_APPLY_IVEC_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_APPLY_IVEC_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    long jle L_0d21
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x18]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jl L_0d21
L_0c7e:
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x20]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short je L_0d03
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x58]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x30]
    mov qword ptr [rax], rdx
L_0d03:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    long jle L_0c7e
L_0d21:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3PERM_APPLY_IVEC:

U3PERM_COPY_APPLY_IVEC:
    push rbp
pro_U3PERM_COPY_APPLY_IVEC_01:
    sub rsp, 0x60
pro_U3PERM_COPY_APPLY_IVEC_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_COPY_APPLY_IVEC_0a:
    mov qword ptr [rbp + 0x30], rbx
pro_U3PERM_COPY_APPLY_IVEC_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rdx
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    short jle L_0e1c
L_0dd2:
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x58]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x28]
    add rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_0dd2
L_0e1c:
    mov rax, qword ptr [rbp + 0x50]
    mov edx, 8
    neg rdx
    mov rcx, qword ptr [rbp + 0x60]
    mov rcx, qword ptr [rcx]
    imul rcx, rcx, 8
    lea rbx, [rip + reloc(OOMF_PLEX)]
    modrm add rbx, rcx
    modrm add rdx, rbx
    mov rcx, rax
    call reloc(U3PERM_APPLY_IVEC)
    mov rbx, qword ptr [rbp + 0x30]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3PERM_COPY_APPLY_IVEC:

U3PERM_EQN_CREATE:
    push rbp
pro_U3PERM_EQN_CREATE_01:
    sub rsp, 0x90
pro_U3PERM_EQN_CREATE_08:
    lea rbp, [rsp + 0x20]
pro_U3PERM_EQN_CREATE_0d:
    mov qword ptr [rbp + 0x80], rcx
    mov qword ptr [rbp + 0x88], rdx
    mov qword ptr [rbp + 0x90], r8
    mov qword ptr [rbp + 0x98], r9
    mov rax, qword ptr [rbp + 0x88]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x88]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x90]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x88]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x30], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_1153
L_0f10:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x38], rax
    short jmp L_0f53
L_0f3d:
    mov eax, dword ptr [rbp + 0x38]
    test al, 1
    short je L_0f80
    mov rax, qword ptr [rbp + 0x40]
    cmp rax, 5
    short je L_0f80
    long jmp L_10ee
L_0f53:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x40], rax
    short jmp L_0f3d
L_0f80:
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rdx
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x30]
    modrm cmp rdx, rax
    long jl L_1122
L_0fbb:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x58], rax
    short jmp L_100b
L_0ff5:
    mov eax, dword ptr [rbp + 0x58]
    test al, 1
    short je L_1038
    mov rax, qword ptr [rbp + 0x60]
    cmp rax, 5
    short je L_1038
    long jmp L_1091
L_100b:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x50]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x60], rax
    short jmp L_0ff5
L_1038:
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, qword ptr [rbp + 0x50]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x48]
    modrm cmp rax, rdx
    long jge L_0fbb
    long jmp L_1122
L_1091:
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, qword ptr [rbp + 0x50]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_1122
L_10ee:
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_1122:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_1153
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_0f10
L_1153:
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x98]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x90]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0x90]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x70]
    pop rbp
    ret
end_U3PERM_EQN_CREATE:

U3PERM_EQN_CREATE_INCIDENCE:
    push rbp
pro_U3PERM_EQN_CREATE_INCIDENCE_01:
    sub rsp, 0x90
pro_U3PERM_EQN_CREATE_INCIDENCE_08:
    lea rbp, [rsp + 0x20]
pro_U3PERM_EQN_CREATE_INCIDENCE_0d:
    mov qword ptr [rbp + 0x80], rcx
    mov qword ptr [rbp + 0x88], rdx
    mov qword ptr [rbp + 0x90], r8
    mov qword ptr [rbp + 0x98], r9
    mov rax, qword ptr [rbp + 0x88]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x88]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x98]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0x90]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rdx
    mov rax, qword ptr [rbp + 0x88]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov qword ptr [rbp + 0x38], 1
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jle L_1528
L_12af:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x38]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x40], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x38]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x48], rax
    mov eax, dword ptr [rbp + 0x40]
    test al, 1
    short je L_133c
    mov rax, qword ptr [rbp + 0x48]
    cmp rax, 5
    short je L_133c
    mov rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    long jne L_14c3
L_133c:
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rdx
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x38]
    modrm cmp rdx, rax
    long jl L_14f7
L_1377:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x60], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x80]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x68], rax
    mov eax, dword ptr [rbp + 0x60]
    test al, 1
    short je L_140d
    mov rax, qword ptr [rbp + 0x68]
    cmp rax, 5
    short je L_140d
    mov rax, qword ptr [rbp + 0x58]
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    short jne L_1466
L_140d:
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0x58]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jge L_1377
    long jmp L_14f7
L_1466:
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0x58]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_14f7
L_14c3:
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0x38]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_14f7:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_1528
    mov eax, 1
    add rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long jle L_12af
L_1528:
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0xa0]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x98]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0xa0]
    mov rdx, qword ptr [rbp + 0x98]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x70]
    pop rbp
    ret
end_U3PERM_EQN_CREATE_INCIDENCE:

U3PERM_JAC_CREATE:
    push rbp
pro_U3PERM_JAC_CREATE_01:
    sub rsp, 0xa0
pro_U3PERM_JAC_CREATE_08:
    lea rbp, [rsp + 0x20]
pro_U3PERM_JAC_CREATE_0d:
    mov qword ptr [rbp + 0x90], rcx
    mov qword ptr [rbp + 0x98], rdx
    mov qword ptr [rbp + 0xa0], r8
    mov qword ptr [rbp + 0xa8], r9
    mov rax, qword ptr [rbp + 0xb0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0xb0]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0xb8]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0xb0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x30], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_1982
L_166f:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xa8]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x98]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x38], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xa0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x40], rax
    short jmp L_1708
L_16eb:
    mov eax, dword ptr [rbp + 0x38]
    test al, 1
    short jne L_1747
    mov eax, dword ptr [rbp + 0x40]
    test al, 1
    short je L_1747
    mov rax, qword ptr [rbp + 0x48]
    cmp rax, 5
    short je L_1747
    long jmp L_191d
L_1708:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xa0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x48], rax
    short jmp L_16eb
L_1747:
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0xb0]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rdx
    mov rax, qword ptr [rbp + 0xb0]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x30]
    modrm cmp rdx, rax
    long jl L_1951
L_1782:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xa8]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x98]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x60], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xa0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x68], rax
    short jmp L_1828
L_180b:
    mov eax, dword ptr [rbp + 0x60]
    test al, 1
    short jne L_1867
    mov eax, dword ptr [rbp + 0x68]
    test al, 1
    short je L_1867
    mov rax, qword ptr [rbp + 0x70]
    cmp rax, 5
    short je L_1867
    long jmp L_18c0
L_1828:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xa0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x70], rax
    short jmp L_180b
L_1867:
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 0x58]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jge L_1782
    long jmp L_1951
L_18c0:
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 0x58]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_1951
L_191d:
    mov rax, qword ptr [rbp + 0xb8]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_1951:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0xb0]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_1982
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_166f
L_1982:
    mov rax, qword ptr [rbp + 0xb0]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0xb0]
    mov rdx, qword ptr [rbp + 0xb8]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0xb8]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x80]
    pop rbp
    ret
end_U3PERM_JAC_CREATE:

U3PERM_JAC_CREATE_INCIDENCE:
    push rbp
pro_U3PERM_JAC_CREATE_INCIDENCE_01:
    sub rsp, 0xa0
pro_U3PERM_JAC_CREATE_INCIDENCE_08:
    lea rbp, [rsp + 0x20]
pro_U3PERM_JAC_CREATE_INCIDENCE_0d:
    mov qword ptr [rbp + 0x90], rcx
    mov qword ptr [rbp + 0x98], rdx
    mov qword ptr [rbp + 0xa0], r8
    mov qword ptr [rbp + 0xa8], r9
    mov rax, qword ptr [rbp + 0xc0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov edx, 3
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0xc8]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0xc8]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x20], 0
    mov rax, qword ptr [rbp + 0xc0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x30], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_1eed
L_1acc:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xb8]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x98]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x38], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xb0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x40], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xb0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x48], rax
    mov eax, dword ptr [rbp + 0x38]
    test al, 1
    long jne L_1c2d
    mov eax, dword ptr [rbp + 0x40]
    test al, 1
    long je L_1c2d
    mov rax, qword ptr [rbp + 0x48]
    cmp rax, 5
    long je L_1c2d
    mov rax, qword ptr [rbp + 0xa0]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0xb8]
    add rax, -8
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    short je L_1c2d
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x30]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0xb0]
    add rax, -8
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    long jne L_1e88
L_1c2d:
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x58], rdx
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x30]
    modrm cmp rdx, rax
    long jl L_1ebc
L_1c68:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xb8]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x98]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x60], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xb0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x68], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x58]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0xb0]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x90]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x70], rax
    mov eax, dword ptr [rbp + 0x60]
    test al, 1
    long jne L_1dd2
    mov eax, dword ptr [rbp + 0x68]
    test al, 1
    long je L_1dd2
    mov rax, qword ptr [rbp + 0x70]
    cmp rax, 5
    long je L_1dd2
    mov rax, qword ptr [rbp + 0xa0]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x58]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0xb8]
    add rax, -8
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    short je L_1dd2
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x58]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0xb0]
    add rax, -8
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    short jne L_1e2b
L_1dd2:
    mov rax, qword ptr [rbp + 0xc8]
    mov rdx, qword ptr [rbp + 0x58]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x50]
    modrm cmp rax, rdx
    long jge L_1c68
    long jmp L_1ebc
L_1e2b:
    mov rax, qword ptr [rbp + 0xc8]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0xc8]
    mov rdx, qword ptr [rbp + 0x58]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 2
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    short jmp L_1ebc
L_1e88:
    mov rax, qword ptr [rbp + 0xc8]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rdx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
L_1ebc:
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short je L_1eed
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_1acc
L_1eed:
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0x18]
    neg rdx
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0xd0]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0xc8]
    mov rcx, 0xfffffffffffffffe
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    mov rax, qword ptr [rbp + 0xd0]
    mov rdx, qword ptr [rbp + 0xc8]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rdx]
    add rcx, qword ptr [rbp + 8]
    imul rdx, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rcx], rax
    lea rsp, [rbp + 0x80]
    pop rbp
    ret
end_U3PERM_JAC_CREATE_INCIDENCE:

U3PERM_JAC_APPLY_ROW:
    push rbp
pro_U3PERM_JAC_APPLY_ROW_01:
    sub rsp, 0x40
pro_U3PERM_JAC_APPLY_ROW_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_JAC_APPLY_ROW_0a:
    mov qword ptr [rbp + 0x30], rcx
    mov qword ptr [rbp + 0x38], rdx
    mov qword ptr [rbp + 0x40], r8
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x40]
    mov rcx, rax
    call reloc(U3PERM_APPLY_IVEC)
    mov rax, qword ptr [rbp + 0x30]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_205f
L_2003:
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x40]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x40]
    add rax, -8
    mov rdx, qword ptr [rdx]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_2003
L_205f:
    lea rsp, [rbp + 0x20]
    pop rbp
    ret
end_U3PERM_JAC_APPLY_ROW:

U3PERM_JAC_COPY_APPLY_ROW:
    push rbp
pro_U3PERM_JAC_COPY_APPLY_ROW_01:
    sub rsp, 0x50
pro_U3PERM_JAC_COPY_APPLY_ROW_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_JAC_COPY_APPLY_ROW_0a:
    mov qword ptr [rbp + 0x28], rbx
pro_U3PERM_JAC_COPY_APPLY_ROW_0e:
    mov qword ptr [rbp + 0x40], rcx
    mov qword ptr [rbp + 0x48], rdx
    mov qword ptr [rbp + 0x50], r8
    mov qword ptr [rbp + 0x58], r9
    mov rax, qword ptr [rbp + 0x40]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    short jle L_2172
L_2102:
    mov rax, qword ptr [rbp + 0x48]
    mov rdx, qword ptr [rbp + 0x20]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x50]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x58]
    mov rcx, 0xffffffffffffffff
    add rcx, qword ptr [rax]
    add rcx, qword ptr [rbp + 0x20]
    imul rax, rcx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rax
    add rcx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rcx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    short jle L_2102
L_2172:
    mov rax, qword ptr [rbp + 0x40]
    mov edx, 8
    neg rdx
    mov rcx, qword ptr [rbp + 0x58]
    mov rcx, qword ptr [rcx]
    imul rcx, rcx, 8
    lea rbx, [rip + reloc(OOMF_PLEX)]
    modrm add rbx, rcx
    modrm add rdx, rbx
    mov rcx, rax
    call reloc(U3PERM_APPLY_IVEC)
    mov rbx, qword ptr [rbp + 0x28]
    lea rsp, [rbp + 0x30]
    pop rbp
    ret
end_U3PERM_JAC_COPY_APPLY_ROW:

U3PERM_JAC_APPLY_COL:
    push rbp
pro_U3PERM_JAC_APPLY_COL_01:
    sub rsp, 0x40
pro_U3PERM_JAC_APPLY_COL_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_JAC_APPLY_COL_0a:
    mov qword ptr [rbp + 0x30], rcx
    mov qword ptr [rbp + 0x38], rdx
    mov qword ptr [rbp + 0x40], r8
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x40]
    mov rcx, rax
    call reloc(U3PERM_APPLY_IVEC)
    mov rax, qword ptr [rbp + 0x30]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_228e
L_2232:
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x40]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x40]
    add rax, -8
    mov rdx, qword ptr [rdx]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_2232
L_228e:
    lea rsp, [rbp + 0x20]
    pop rbp
    ret
end_U3PERM_JAC_APPLY_COL:

U3PERM_JAC_COPY_APPLY_COL:
    push rbp
pro_U3PERM_JAC_COPY_APPLY_COL_01:
    sub rsp, 0x60
pro_U3PERM_JAC_COPY_APPLY_COL_05:
    lea rbp, [rsp + 0x20]
pro_U3PERM_JAC_COPY_APPLY_COL_0a:
    mov qword ptr [rbp + 0x38], rbx
pro_U3PERM_JAC_COPY_APPLY_COL_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xfffffffffffffffe
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    add rdx, qword ptr [rbp]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    lea rax, [rbp + 8]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, qword ptr [rbp + 0x18]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x68]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rdx
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x30], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    short jle L_23d4
L_236e:
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x30]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x60]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x30]
    add rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rax
    add rcx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rcx], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    short jle L_236e
L_23d4:
    mov rax, qword ptr [rbp + 0x50]
    mov edx, 8
    neg rdx
    mov rcx, qword ptr [rbp + 0x68]
    mov rcx, qword ptr [rcx]
    imul rcx, rcx, 8
    lea rbx, [rip + reloc(OOMF_PLEX)]
    modrm add rbx, rcx
    modrm add rdx, rbx
    mov rcx, rax
    call reloc(U3PERM_APPLY_IVEC)
    mov rbx, qword ptr [rbp + 0x38]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3PERM_JAC_COPY_APPLY_COL:

U3PERM_COMP2UNCOMP:
    push rbp
pro_U3PERM_COMP2UNCOMP_01:
    sub rsp, 0x100
pro_U3PERM_COMP2UNCOMP_08:
    lea rbp, [rsp + 0x30]
pro_U3PERM_COMP2UNCOMP_0d:
    mov qword ptr [rbp + 0xc0], rsi
pro_U3PERM_COMP2UNCOMP_14:
    mov qword ptr [rbp + 0xb8], rbx
pro_U3PERM_COMP2UNCOMP_1b:
    mov qword ptr [rbp + 0xe0], rcx
    mov qword ptr [rbp + 0xe8], rdx
    mov rax, qword ptr [rbp + 0xe0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp]
    add rax, qword ptr [rbp + 8]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jl L_24ac
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jle L_2633
L_24ac:
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x48], 0x29
    lea rax, [rip + reloc(.rdata, __STRLITPACK_2 - .rdata)]
    mov qword ptr [rbp + 0x50], rax
    lea rax, [rbp + 0x18]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x90], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x90]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_lis)
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x58], 8
    lea rax, [rip + reloc(.rdata, __STRLITPACK_1 - .rdata)]
    mov qword ptr [rbp + 0x60], rax
    lea rax, [rbp + 0x18]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    lea rsi, [rbp + 0x58]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x98], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x98]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_lis)
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x70], rax
    lea rax, [rbp + 0x18]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_5 - .rdata)]
    lea rcx, [rbp + 0x70]
    mov qword ptr [rbp + 0xa0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa0]
    mov r8, rax
    call reloc(for_write_seq_lis_xmit)
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x78], 8
    lea rax, [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x18]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_6 - .rdata)]
    lea rsi, [rbp + 0x78]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xa8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_lis)
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x18]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    lea rcx, [rbp + 0x88]
    mov qword ptr [rbp + 0xb0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb0]
    mov r8, rax
    call reloc(for_write_seq_lis_xmit)
    mov qword ptr [rbp + 0x68], 0
    short jmp L_265a
L_2633:
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x68], rax
L_265a:
    mov rax, qword ptr [rbp + 0x68]
    mov rbx, qword ptr [rbp + 0xb8]
    mov rsi, qword ptr [rbp + 0xc0]
    lea rsp, [rbp + 0xd0]
    pop rbp
    ret
end_U3PERM_COMP2UNCOMP:

U3PERM_UNCOMP2COMP:
    push rbp
pro_U3PERM_UNCOMP2COMP_01:
    sub rsp, 0x100
pro_U3PERM_UNCOMP2COMP_08:
    lea rbp, [rsp + 0x30]
pro_U3PERM_UNCOMP2COMP_0d:
    mov qword ptr [rbp + 0xc0], rsi
pro_U3PERM_UNCOMP2COMP_14:
    mov qword ptr [rbp + 0xb8], rbx
pro_U3PERM_UNCOMP2COMP_1b:
    mov qword ptr [rbp + 0xe0], rcx
    mov qword ptr [rbp + 0xe8], rdx
    mov rax, qword ptr [rbp + 0xe0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 8], rax
    mov rax, 0xfffffffffffffffe
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    test rax, rax
    short jl L_26fe
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jle L_2885
L_26fe:
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x48], 0x29
    lea rax, [rip + reloc(.rdata, __STRLITPACK_10 - .rdata)]
    mov qword ptr [rbp + 0x50], rax
    lea rax, [rbp + 0x18]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_11 - .rdata)]
    lea rsi, [rbp + 0x48]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x90], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x90]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_lis)
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x58], 8
    lea rax, [rip + reloc(.rdata, __STRLITPACK_9 - .rdata)]
    mov qword ptr [rbp + 0x60], rax
    lea rax, [rbp + 0x18]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_12 - .rdata)]
    lea rsi, [rbp + 0x58]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x98], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x98]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_lis)
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x70], rax
    lea rax, [rbp + 0x18]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_13 - .rdata)]
    lea rcx, [rbp + 0x70]
    mov qword ptr [rbp + 0xa0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa0]
    mov r8, rax
    call reloc(for_write_seq_lis_xmit)
    mov qword ptr [rbp + 0x18], 0
    mov qword ptr [rbp + 0x78], 8
    lea rax, [rip + reloc(.rdata, __STRLITPACK_8 - .rdata)]
    mov qword ptr [rbp + 0x80], rax
    lea rax, [rbp + 0x18]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_14 - .rdata)]
    lea rsi, [rbp + 0x78]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0xa8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_lis)
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x88], rax
    lea rax, [rbp + 0x18]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_15 - .rdata)]
    lea rcx, [rbp + 0x88]
    mov qword ptr [rbp + 0xb0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb0]
    mov r8, rax
    call reloc(for_write_seq_lis_xmit)
    mov qword ptr [rbp + 0x68], 0
    short jmp L_28ac
L_2885:
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x68], rax
L_28ac:
    mov rax, qword ptr [rbp + 0x68]
    mov rbx, qword ptr [rbp + 0xb8]
    mov rsi, qword ptr [rbp + 0xc0]
    lea rsp, [rbp + 0xd0]
    pop rbp
    ret
end_U3PERM_UNCOMP2COMP:

U3MAP_REL_INCIDENCE:
    push rbp
pro_U3MAP_REL_INCIDENCE_01:
    sub rsp, 0x60
pro_U3MAP_REL_INCIDENCE_05:
    lea rbp, [rsp + 0x20]
pro_U3MAP_REL_INCIDENCE_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x70]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 8]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    dec rdx
    mov qword ptr [rbp + 0x10], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jl L_296e
L_2937:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_2937
L_296e:
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rdx
    mov rax, qword ptr [rbp + 0x70]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_2a66
L_29a0:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x68]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x58]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3VFXD)
    mov qword ptr [rbp + 0x30], rax
    mov eax, dword ptr [rbp + 0x30]
    test al, 1
    short jne L_2a48
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x60]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short jle L_2a48
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x60]
    add rax, -8
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov eax, 1
    add rax, qword ptr [rdx]
    mov rdx, qword ptr [rbp + 0x38]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov qword ptr [rcx], rax
L_2a48:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_29a0
L_2a66:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3MAP_REL_INCIDENCE:

U3MAP_VAR_INCIDENCE:
    push rbp
pro_U3MAP_VAR_INCIDENCE_01:
    sub rsp, 0x60
pro_U3MAP_VAR_INCIDENCE_05:
    lea rbp, [rsp + 0x20]
pro_U3MAP_VAR_INCIDENCE_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x70]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 8]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rdx]
    add rdx, qword ptr [rax]
    dec rdx
    mov qword ptr [rbp + 0x10], rdx
    mov rax, qword ptr [rbp + 0x78]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x78]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jl L_2b13
L_2adc:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_2adc
L_2b13:
    mov rax, qword ptr [rbp + 0x78]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rdx
    mov rax, qword ptr [rbp + 0x70]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x28]
    test rax, rax
    long jle L_2bf3
L_2b45:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x18]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x60]
    add rdx, -8
    mov rdx, qword ptr [rdx]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x58]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x30], rax
    mov eax, dword ptr [rbp + 0x30]
    test al, 1
    short je L_2bd5
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x68]
    add rax, -8
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov eax, 1
    add rax, qword ptr [rdx]
    mov rdx, qword ptr [rbp + 0x38]
    imul rdx, rdx, 8
    lea rcx, [rip + reloc(OOMF_PLEX)]
    modrm add rcx, rdx
    add rcx, -8
    mov qword ptr [rcx], rax
L_2bd5:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    long jle L_2b45
L_2bf3:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3MAP_VAR_INCIDENCE:

U3REMAP:
    push rbp
pro_U3REMAP_01:
    sub rsp, 0x60
pro_U3REMAP_05:
    lea rbp, [rsp + 0x20]
pro_U3REMAP_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x60]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 8], rdx
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_2c7b
L_2c4a:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x68]
    add rax, -8
    mov qword ptr [rax], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_2c4a
L_2c7b:
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    short jle L_2cfc
L_2c97:
    mov rax, qword ptr [rbp + 0x18]
    add rax, qword ptr [rbp + 8]
    dec rax
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jg L_2ce2
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x68]
    add rax, -8
    mov qword ptr [rax], 1
L_2ce2:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_2c97
L_2cfc:
    mov qword ptr [rbp + 0x28], 0
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x30], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x30]
    test rax, rax
    long jle L_2db1
L_2d24:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x68]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_2d62
    mov rax, qword ptr [rbp + 0x18]
    add rax, qword ptr [rbp + 8]
    dec rax
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
    short jmp L_2d93
L_2d62:
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x18]
    add rax, qword ptr [rbp + 8]
    dec rax
    imul rax, rax, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rdx], rax
L_2d93:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long jle L_2d24
L_2db1:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_U3REMAP:

USR3_FNDOBJ:
    push rbp
pro_USR3_FNDOBJ_01:
    sub rsp, 0x50
pro_USR3_FNDOBJ_05:
    lea rbp, [rsp + 0x20]
pro_USR3_FNDOBJ_0a:
    mov qword ptr [rbp + 0x40], rcx
    mov qword ptr [rbp + 0x48], rdx
    mov qword ptr [rbp + 0x50], r8
    mov rax, qword ptr [rbp + 0x40]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x40]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov qword ptr [rbp + 0x10], 1
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    long jle L_2e8f
L_2e03:
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x10]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x48]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RINC)
    mov qword ptr [rbp + 0x18], rax
    mov eax, 0
    mov edx, 8
    modrm sub rax, rdx
    mov rdx, qword ptr [rbp + 0x10]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x48]
    modrm add rax, rdx
    mov rcx, rax
    call reloc(U3RGMT)
    mov qword ptr [rbp + 0x20], rax
    mov eax, dword ptr [rbp + 0x18]
    test al, 1
    short je L_2e71
    mov rax, qword ptr [rbp + 0x20]
    cmp rax, 5
    short jne L_2e71
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x10]
    mov qword ptr [rax], rdx
    short jmp L_2e8f
L_2e71:
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 8]
    modrm cmp rax, rdx
    long jle L_2e03
L_2e8f:
    lea rsp, [rbp + 0x30]
    pop rbp
    ret
end_USR3_FNDOBJ:

NZ_IN_ROW:
    push rbp
pro_NZ_IN_ROW_01:
    sub rsp, 0x50
pro_NZ_IN_ROW_05:
    lea rbp, [rsp + 0x20]
pro_NZ_IN_ROW_0a:
    mov qword ptr [rbp + 0x40], rcx
    mov qword ptr [rbp + 0x48], rdx
    mov qword ptr [rbp + 0x50], r8
    mov qword ptr [rbp + 0x58], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov qword ptr [rbp + 0x10], 1
    mov rax, qword ptr [rbp + 8]
    test rax, rax
    short jle L_2f2d
L_2ee1:
    mov rax, qword ptr [rbp + 0x10]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x48]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jne L_2f13
    mov rax, qword ptr [rbp + 0x60]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rax], rdx
L_2f13:
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 8]
    modrm cmp rax, rdx
    short jle L_2ee1
L_2f2d:
    mov rax, qword ptr [rbp + 0x60]
    mov rcx, rax
    call reloc(RTO_IMALLOC)
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, qword ptr [rbp + 0x18]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x10], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    long jle L_2fed
L_2f73:
    mov rax, qword ptr [rbp + 0x10]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x48]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rdx]
    modrm cmp rax, rdx
    short jne L_2fd3
    mov rax, qword ptr [rbp + 0x60]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x58]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x60]
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    lea rdx, [rip + reloc(OOMF_PLEX)]
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rdx], rax
L_2fd3:
    mov eax, 1
    add rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_2f73
L_2fed:
    lea rsp, [rbp + 0x30]
    pop rbp
    ret
end_NZ_IN_ROW:
    nop

.section .xdata 0x40300040
unwind_U3PERM_VAR_CREATE:
    .unwind U3PERM_VAR_CREATE, pro_U3PERM_VAR_CREATE_0d, rbp, 32
        .set_fpreg pro_U3PERM_VAR_CREATE_0d
        .alloc_small pro_U3PERM_VAR_CREATE_08, 128
        .push_nonvol pro_U3PERM_VAR_CREATE_01, rbp
    .endunwind
unwind_U3PERM_VAR_CREATE_INCIDENCE:
    .unwind U3PERM_VAR_CREATE_INCIDENCE, pro_U3PERM_VAR_CREATE_INCIDENCE_0d, rbp, 32
        .set_fpreg pro_U3PERM_VAR_CREATE_INCIDENCE_0d
        .alloc_small pro_U3PERM_VAR_CREATE_INCIDENCE_08, 128
        .push_nonvol pro_U3PERM_VAR_CREATE_INCIDENCE_01, rbp
    .endunwind
unwind_U3PERM_VAR_CREATE_INCIDENCEONLY:
    .unwind U3PERM_VAR_CREATE_INCIDENCEONLY, pro_U3PERM_VAR_CREATE_INCIDENCEONLY_0a, rbp, 32
        .set_fpreg pro_U3PERM_VAR_CREATE_INCIDENCEONLY_0a
        .alloc_small pro_U3PERM_VAR_CREATE_INCIDENCEONLY_05, 112
        .push_nonvol pro_U3PERM_VAR_CREATE_INCIDENCEONLY_01, rbp
    .endunwind
unwind_U3PERM_DESTROY:
    .unwind U3PERM_DESTROY, pro_U3PERM_DESTROY_0a, rbp, 32
        .set_fpreg pro_U3PERM_DESTROY_0a
        .alloc_small pro_U3PERM_DESTROY_05, 32
        .push_nonvol pro_U3PERM_DESTROY_01, rbp
    .endunwind
unwind_U3PERM_APPLY_RVEC:
    .unwind U3PERM_APPLY_RVEC, pro_U3PERM_APPLY_RVEC_0a, rbp, 32
        .set_fpreg pro_U3PERM_APPLY_RVEC_0a
        .alloc_small pro_U3PERM_APPLY_RVEC_05, 96
        .push_nonvol pro_U3PERM_APPLY_RVEC_01, rbp
    .endunwind
unwind_U3PERM_COPY_APPLY_RVEC:
    .unwind U3PERM_COPY_APPLY_RVEC, pro_U3PERM_COPY_APPLY_RVEC_0e, rbp, 32
        .save_nonvol pro_U3PERM_COPY_APPLY_RVEC_0e, rbx, 80
        .set_fpreg pro_U3PERM_COPY_APPLY_RVEC_0a
        .alloc_small pro_U3PERM_COPY_APPLY_RVEC_05, 96
        .push_nonvol pro_U3PERM_COPY_APPLY_RVEC_01, rbp
    .endunwind
unwind_U3PERM_APPLY_IVEC:
    .unwind U3PERM_APPLY_IVEC, pro_U3PERM_APPLY_IVEC_0a, rbp, 32
        .set_fpreg pro_U3PERM_APPLY_IVEC_0a
        .alloc_small pro_U3PERM_APPLY_IVEC_05, 96
        .push_nonvol pro_U3PERM_APPLY_IVEC_01, rbp
    .endunwind
unwind_U3PERM_COPY_APPLY_IVEC:
    .unwind U3PERM_COPY_APPLY_IVEC, pro_U3PERM_COPY_APPLY_IVEC_0e, rbp, 32
        .save_nonvol pro_U3PERM_COPY_APPLY_IVEC_0e, rbx, 80
        .set_fpreg pro_U3PERM_COPY_APPLY_IVEC_0a
        .alloc_small pro_U3PERM_COPY_APPLY_IVEC_05, 96
        .push_nonvol pro_U3PERM_COPY_APPLY_IVEC_01, rbp
    .endunwind
unwind_U3PERM_EQN_CREATE:
    .unwind U3PERM_EQN_CREATE, pro_U3PERM_EQN_CREATE_0d, rbp, 32
        .set_fpreg pro_U3PERM_EQN_CREATE_0d
        .alloc_large pro_U3PERM_EQN_CREATE_08, 144
        .push_nonvol pro_U3PERM_EQN_CREATE_01, rbp
    .endunwind
unwind_U3PERM_EQN_CREATE_INCIDENCE:
    .unwind U3PERM_EQN_CREATE_INCIDENCE, pro_U3PERM_EQN_CREATE_INCIDENCE_0d, rbp, 32
        .set_fpreg pro_U3PERM_EQN_CREATE_INCIDENCE_0d
        .alloc_large pro_U3PERM_EQN_CREATE_INCIDENCE_08, 144
        .push_nonvol pro_U3PERM_EQN_CREATE_INCIDENCE_01, rbp
    .endunwind
unwind_U3PERM_JAC_CREATE:
    .unwind U3PERM_JAC_CREATE, pro_U3PERM_JAC_CREATE_0d, rbp, 32
        .set_fpreg pro_U3PERM_JAC_CREATE_0d
        .alloc_large pro_U3PERM_JAC_CREATE_08, 160
        .push_nonvol pro_U3PERM_JAC_CREATE_01, rbp
    .endunwind
unwind_U3PERM_JAC_CREATE_INCIDENCE:
    .unwind U3PERM_JAC_CREATE_INCIDENCE, pro_U3PERM_JAC_CREATE_INCIDENCE_0d, rbp, 32
        .set_fpreg pro_U3PERM_JAC_CREATE_INCIDENCE_0d
        .alloc_large pro_U3PERM_JAC_CREATE_INCIDENCE_08, 160
        .push_nonvol pro_U3PERM_JAC_CREATE_INCIDENCE_01, rbp
    .endunwind
unwind_U3PERM_JAC_APPLY_ROW:
    .unwind U3PERM_JAC_APPLY_ROW, pro_U3PERM_JAC_APPLY_ROW_0a, rbp, 32
        .set_fpreg pro_U3PERM_JAC_APPLY_ROW_0a
        .alloc_small pro_U3PERM_JAC_APPLY_ROW_05, 64
        .push_nonvol pro_U3PERM_JAC_APPLY_ROW_01, rbp
    .endunwind
unwind_U3PERM_JAC_COPY_APPLY_ROW:
    .unwind U3PERM_JAC_COPY_APPLY_ROW, pro_U3PERM_JAC_COPY_APPLY_ROW_0e, rbp, 32
        .save_nonvol pro_U3PERM_JAC_COPY_APPLY_ROW_0e, rbx, 72
        .set_fpreg pro_U3PERM_JAC_COPY_APPLY_ROW_0a
        .alloc_small pro_U3PERM_JAC_COPY_APPLY_ROW_05, 80
        .push_nonvol pro_U3PERM_JAC_COPY_APPLY_ROW_01, rbp
    .endunwind
unwind_U3PERM_JAC_APPLY_COL:
    .unwind U3PERM_JAC_APPLY_COL, pro_U3PERM_JAC_APPLY_COL_0a, rbp, 32
        .set_fpreg pro_U3PERM_JAC_APPLY_COL_0a
        .alloc_small pro_U3PERM_JAC_APPLY_COL_05, 64
        .push_nonvol pro_U3PERM_JAC_APPLY_COL_01, rbp
    .endunwind
unwind_U3PERM_JAC_COPY_APPLY_COL:
    .unwind U3PERM_JAC_COPY_APPLY_COL, pro_U3PERM_JAC_COPY_APPLY_COL_0e, rbp, 32
        .save_nonvol pro_U3PERM_JAC_COPY_APPLY_COL_0e, rbx, 88
        .set_fpreg pro_U3PERM_JAC_COPY_APPLY_COL_0a
        .alloc_small pro_U3PERM_JAC_COPY_APPLY_COL_05, 96
        .push_nonvol pro_U3PERM_JAC_COPY_APPLY_COL_01, rbp
    .endunwind
unwind_U3PERM_COMP2UNCOMP:
    .unwind U3PERM_COMP2UNCOMP, pro_U3PERM_COMP2UNCOMP_1b, rbp, 48
        .save_nonvol pro_U3PERM_COMP2UNCOMP_1b, rbx, 232
        .save_nonvol pro_U3PERM_COMP2UNCOMP_14, rsi, 240
        .set_fpreg pro_U3PERM_COMP2UNCOMP_0d
        .alloc_large pro_U3PERM_COMP2UNCOMP_08, 256
        .push_nonvol pro_U3PERM_COMP2UNCOMP_01, rbp
    .endunwind
unwind_U3PERM_UNCOMP2COMP:
    .unwind U3PERM_UNCOMP2COMP, pro_U3PERM_UNCOMP2COMP_1b, rbp, 48
        .save_nonvol pro_U3PERM_UNCOMP2COMP_1b, rbx, 232
        .save_nonvol pro_U3PERM_UNCOMP2COMP_14, rsi, 240
        .set_fpreg pro_U3PERM_UNCOMP2COMP_0d
        .alloc_large pro_U3PERM_UNCOMP2COMP_08, 256
        .push_nonvol pro_U3PERM_UNCOMP2COMP_01, rbp
    .endunwind
unwind_U3MAP_REL_INCIDENCE:
    .unwind U3MAP_REL_INCIDENCE, pro_U3MAP_REL_INCIDENCE_0a, rbp, 32
        .set_fpreg pro_U3MAP_REL_INCIDENCE_0a
        .alloc_small pro_U3MAP_REL_INCIDENCE_05, 96
        .push_nonvol pro_U3MAP_REL_INCIDENCE_01, rbp
    .endunwind
unwind_U3MAP_VAR_INCIDENCE:
    .unwind U3MAP_VAR_INCIDENCE, pro_U3MAP_VAR_INCIDENCE_0a, rbp, 32
        .set_fpreg pro_U3MAP_VAR_INCIDENCE_0a
        .alloc_small pro_U3MAP_VAR_INCIDENCE_05, 96
        .push_nonvol pro_U3MAP_VAR_INCIDENCE_01, rbp
    .endunwind
unwind_U3REMAP:
    .unwind U3REMAP, pro_U3REMAP_0a, rbp, 32
        .set_fpreg pro_U3REMAP_0a
        .alloc_small pro_U3REMAP_05, 96
        .push_nonvol pro_U3REMAP_01, rbp
    .endunwind
unwind_USR3_FNDOBJ:
    .unwind USR3_FNDOBJ, pro_USR3_FNDOBJ_0a, rbp, 32
        .set_fpreg pro_USR3_FNDOBJ_0a
        .alloc_small pro_USR3_FNDOBJ_05, 80
        .push_nonvol pro_USR3_FNDOBJ_01, rbp
    .endunwind
unwind_NZ_IN_ROW:
    .unwind NZ_IN_ROW, pro_NZ_IN_ROW_0a, rbp, 32
        .set_fpreg pro_NZ_IN_ROW_0a
        .alloc_small pro_NZ_IN_ROW_05, 80
        .push_nonvol pro_NZ_IN_ROW_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva U3PERM_VAR_CREATE
    .rva U3PERM_VAR_CREATE, end_U3PERM_VAR_CREATE - U3PERM_VAR_CREATE
    .rva .xdata, unwind_U3PERM_VAR_CREATE - .xdata
    .rva U3PERM_VAR_CREATE_INCIDENCE
    .rva U3PERM_VAR_CREATE_INCIDENCE, end_U3PERM_VAR_CREATE_INCIDENCE - U3PERM_VAR_CREATE_INCIDENCE
    .rva .xdata, unwind_U3PERM_VAR_CREATE_INCIDENCE - .xdata
    .rva U3PERM_VAR_CREATE_INCIDENCEONLY
    .rva U3PERM_VAR_CREATE_INCIDENCEONLY, end_U3PERM_VAR_CREATE_INCIDENCEONLY - U3PERM_VAR_CREATE_INCIDENCEONLY
    .rva .xdata, unwind_U3PERM_VAR_CREATE_INCIDENCEONLY - .xdata
    .rva U3PERM_DESTROY
    .rva U3PERM_DESTROY, end_U3PERM_DESTROY - U3PERM_DESTROY
    .rva .xdata, unwind_U3PERM_DESTROY - .xdata
    .rva U3PERM_APPLY_RVEC
    .rva U3PERM_APPLY_RVEC, end_U3PERM_APPLY_RVEC - U3PERM_APPLY_RVEC
    .rva .xdata, unwind_U3PERM_APPLY_RVEC - .xdata
    .rva U3PERM_COPY_APPLY_RVEC
    .rva U3PERM_COPY_APPLY_RVEC, end_U3PERM_COPY_APPLY_RVEC - U3PERM_COPY_APPLY_RVEC
    .rva .xdata, unwind_U3PERM_COPY_APPLY_RVEC - .xdata
    .rva U3PERM_APPLY_IVEC
    .rva U3PERM_APPLY_IVEC, end_U3PERM_APPLY_IVEC - U3PERM_APPLY_IVEC
    .rva .xdata, unwind_U3PERM_APPLY_IVEC - .xdata
    .rva U3PERM_COPY_APPLY_IVEC
    .rva U3PERM_COPY_APPLY_IVEC, end_U3PERM_COPY_APPLY_IVEC - U3PERM_COPY_APPLY_IVEC
    .rva .xdata, unwind_U3PERM_COPY_APPLY_IVEC - .xdata
    .rva U3PERM_EQN_CREATE
    .rva U3PERM_EQN_CREATE, end_U3PERM_EQN_CREATE - U3PERM_EQN_CREATE
    .rva .xdata, unwind_U3PERM_EQN_CREATE - .xdata
    .rva U3PERM_EQN_CREATE_INCIDENCE
    .rva U3PERM_EQN_CREATE_INCIDENCE, end_U3PERM_EQN_CREATE_INCIDENCE - U3PERM_EQN_CREATE_INCIDENCE
    .rva .xdata, unwind_U3PERM_EQN_CREATE_INCIDENCE - .xdata
    .rva U3PERM_JAC_CREATE
    .rva U3PERM_JAC_CREATE, end_U3PERM_JAC_CREATE - U3PERM_JAC_CREATE
    .rva .xdata, unwind_U3PERM_JAC_CREATE - .xdata
    .rva U3PERM_JAC_CREATE_INCIDENCE
    .rva U3PERM_JAC_CREATE_INCIDENCE, end_U3PERM_JAC_CREATE_INCIDENCE - U3PERM_JAC_CREATE_INCIDENCE
    .rva .xdata, unwind_U3PERM_JAC_CREATE_INCIDENCE - .xdata
    .rva U3PERM_JAC_APPLY_ROW
    .rva U3PERM_JAC_APPLY_ROW, end_U3PERM_JAC_APPLY_ROW - U3PERM_JAC_APPLY_ROW
    .rva .xdata, unwind_U3PERM_JAC_APPLY_ROW - .xdata
    .rva U3PERM_JAC_COPY_APPLY_ROW
    .rva U3PERM_JAC_COPY_APPLY_ROW, end_U3PERM_JAC_COPY_APPLY_ROW - U3PERM_JAC_COPY_APPLY_ROW
    .rva .xdata, unwind_U3PERM_JAC_COPY_APPLY_ROW - .xdata
    .rva U3PERM_JAC_APPLY_COL
    .rva U3PERM_JAC_APPLY_COL, end_U3PERM_JAC_APPLY_COL - U3PERM_JAC_APPLY_COL
    .rva .xdata, unwind_U3PERM_JAC_APPLY_COL - .xdata
    .rva U3PERM_JAC_COPY_APPLY_COL
    .rva U3PERM_JAC_COPY_APPLY_COL, end_U3PERM_JAC_COPY_APPLY_COL - U3PERM_JAC_COPY_APPLY_COL
    .rva .xdata, unwind_U3PERM_JAC_COPY_APPLY_COL - .xdata
    .rva U3PERM_COMP2UNCOMP
    .rva U3PERM_COMP2UNCOMP, end_U3PERM_COMP2UNCOMP - U3PERM_COMP2UNCOMP
    .rva .xdata, unwind_U3PERM_COMP2UNCOMP - .xdata
    .rva U3PERM_UNCOMP2COMP
    .rva U3PERM_UNCOMP2COMP, end_U3PERM_UNCOMP2COMP - U3PERM_UNCOMP2COMP
    .rva .xdata, unwind_U3PERM_UNCOMP2COMP - .xdata
    .rva U3MAP_REL_INCIDENCE
    .rva U3MAP_REL_INCIDENCE, end_U3MAP_REL_INCIDENCE - U3MAP_REL_INCIDENCE
    .rva .xdata, unwind_U3MAP_REL_INCIDENCE - .xdata
    .rva U3MAP_VAR_INCIDENCE
    .rva U3MAP_VAR_INCIDENCE, end_U3MAP_VAR_INCIDENCE - U3MAP_VAR_INCIDENCE
    .rva .xdata, unwind_U3MAP_VAR_INCIDENCE - .xdata
    .rva U3REMAP
    .rva U3REMAP, end_U3REMAP - U3REMAP
    .rva .xdata, unwind_U3REMAP - .xdata
    .rva USR3_FNDOBJ
    .rva USR3_FNDOBJ, end_USR3_FNDOBJ - USR3_FNDOBJ
    .rva .xdata, unwind_USR3_FNDOBJ - .xdata
    .rva NZ_IN_ROW
    .rva NZ_IN_ROW, end_NZ_IN_ROW - NZ_IN_ROW
    .rva .xdata, unwind_NZ_IN_ROW - .xdata

.section .rdata 0x40300040
__STRLITPACK_2:
    .ascii "!! u3perm_comp2uncomp: i is out of bounds"
    .zero 3
__STRLITPACK_1:
    .ascii "  i   = "
    .zero 4
__STRLITPACK_0:
    .ascii "  nxc = "
    .zero 4
__STRLITPACK_3:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_4:
    .byte 0x38, 0x04, 0x02
    .zero 5
__STRLITPACK_5:
    .byte 0x0b, 0x01, 0x01
    .zero 5
__STRLITPACK_6:
    .byte 0x38, 0x04, 0x02
    .zero 5
__STRLITPACK_7:
    .byte 0x0b, 0x01, 0x01
    .zero 5
__STRLITPACK_10:
    .ascii "!! u3perm_uncomp2comp: i is out of bounds"
    .zero 3
__STRLITPACK_9:
    .ascii "  i   = "
    .zero 4
__STRLITPACK_8:
    .ascii "  nx  = "
    .zero 4
__STRLITPACK_11:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_12:
    .byte 0x38, 0x04, 0x02
    .zero 5
__STRLITPACK_13:
    .byte 0x0b, 0x01, 0x01
    .zero 5
__STRLITPACK_14:
    .byte 0x38, 0x04, 0x02
    .zero 5
__STRLITPACK_15:
    .byte 0x0b, 0x01, 0x01
    .zero 5

.section .drectve 0x00100a00
    .ascii "-export:NZ_IN_ROW  -export:USR3_FNDOBJ  -export:U3REMAP  -export:U3MAP_VAR_INCIDENCE  -export:U3MAP_REL_INCIDENCE  -export:U3PERM_UNCOMP2COMP  -export:U3PERM_COMP2UNCOMP  -export:U3PERM_JAC_COPY_APPLY_COL  -export:U3PERM_JAC_APPLY_COL  -export:U3PERM_JAC_COPY_APPLY_ROW  -export:U3PERM_JAC_APPLY_ROW  -export:U3PERM_JAC_CREATE_INCIDENCE  -export:U3PERM_JAC_CREATE  -export:U3PERM_EQN_CREATE_INCIDENCE  -export:U3PERM_EQN_CREATE  -export:U3PERM_COPY_APPLY_IVEC  -export:U3PERM_APPLY_IVEC  -export:U3PERM_COPY_APPLY_RVEC  -export:U3PERM_APPLY_RVEC  -export:U3PERM_DESTROY  -export:U3PERM_VAR_CREATE_INCIDENCEONLY  -export:U3PERM_VAR_CREATE_INCIDENCE  -export:U3PERM_VAR_CREATE  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\strings.obj 1743626480
.index IU_CLRSCR
.index IU_CLRSTR
.index IU_I42STR
.index IU_PACKSTR
.index IU_R82STR
.index IU_STR2I4
.index IU_STR2R8
.index IU_STRCAT
.index IU_STRLEN
.index IU_STRLWR
.index IU_STRUPR
.index IU_TRIMSTR

.symbol .text section local
.symbol IU_STRUPR function public
.symbol IU_STRLWR function public
.symbol IU_CLRSTR function public
.symbol IU_TRIMSTR function public
.symbol IU_CLRSCR function public
.symbol IU_STRLEN function public
.symbol IU_PACKSTR function public
.symbol IU_I42STR function public
.symbol IU_STR2I4 function public
.symbol IU_R82STR function public
.symbol IU_STR2R8 function public
.symbol IU_STRCAT function public
.symbol .rdata section local
.symbol __STRLITPACK_2 data local
.symbol __STRLITPACK_1 data local
.symbol __STRLITPACK_0 data local
.symbol .bss section local
.symbol memcpy external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol IU_STRUPR$LA data local
.symbol IU_STRUPR$LZ data local
.symbol IU_STRUPR$LOFF data local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_3 data local
.symbol for_cpstr external public function
.symbol .data section local
.symbol for_f90_index external public function
.symbol IU_STRLWR$UPP data local
.symbol IU_STRLWR$LOW data local
.symbol __STRLITPACK_7 data local
.symbol for_cpystr external public function
.symbol __STRLITPACK_10 data local
.symbol __STRLITPACK_9 data local
.symbol __STRLITPACK_14 data local
.symbol for_write_seq_fmt external public function
.symbol IU_CLRSCR$format_pack data local
.symbol __STRLITPACK_15 data local
.symbol __STRLITPACK_16 data local
.symbol __STRLITPACK_18 data local
.symbol __STRLITPACK_17 data local
.symbol __STRLITPACK_19 data local
.symbol RTO_I42STR external public function
.symbol RTO_STR2I4 external public function
.symbol IU_STR2I4$IBLANK data local
.symbol __STRLITPACK_20 data local
.symbol RTO_R82STR external public function
.symbol RTO_STR2R8 external public function
.symbol IU_STR2R8$RBLANK data local
.symbol .drectve section local
.symbol __ImageBase external public function
.symbol _fltused external public data

.section .text 0x60300020

IU_STRUPR:
    push rbp
pro_IU_STRUPR_01:
    sub rsp, 0x80
pro_IU_STRUPR_08:
    lea rbp, [rsp + 0x20]
pro_IU_STRUPR_0d:
    mov qword ptr [rbp + 0x70], rcx
    mov qword ptr [rbp + 0x78], rdx
    mov rax, qword ptr [rip + reloc(.bss, IU_STRUPR$LA - .bss)]
    test rax, rax
    short jne L_006a
    lea rax, [rip + reloc(.rdata, __STRLITPACK_2 - .rdata)]
    movzx eax, byte ptr [rax]
    movzx eax, al
    mov qword ptr [rip + reloc(.bss, IU_STRUPR$LA - .bss)], rax
    lea rax, [rip + reloc(.rdata, __STRLITPACK_1 - .rdata)]
    movzx eax, byte ptr [rax]
    movzx eax, al
    mov qword ptr [rip + reloc(.bss, IU_STRUPR$LZ - .bss)], rax
    lea rax, [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    movzx eax, byte ptr [rax]
    movzx eax, al
    mov rdx, qword ptr [rip + reloc(.bss, IU_STRUPR$LA - .bss)]
    neg rdx
    modrm add rax, rdx
    mov qword ptr [rip + reloc(.bss, IU_STRUPR$LOFF - .bss)], rax
L_006a:
    mov rax, qword ptr [rbp + 0x78]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    long jle L_0151
L_008f:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x28], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x30]
    add rax, qword ptr [rbp + 0x70]
    movzx eax, byte ptr [rax]
    movzx eax, al
    mov qword ptr [rbp + 0x38], rax
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rip + reloc(.bss, IU_STRUPR$LA - .bss)]
    modrm cmp rax, rdx
    short jl L_0133
    mov rax, qword ptr [rbp + 0x38]
    mov rdx, qword ptr [rip + reloc(.bss, IU_STRUPR$LZ - .bss)]
    modrm cmp rax, rdx
    short jg L_0133
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x48], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x50], rax
    mov eax, dword ptr [rip + reloc(.bss, IU_STRUPR$LOFF - .bss)]
    add eax, dword ptr [rbp + 0x38]
    mov byte ptr [rbp], al
    mov rax, qword ptr [rbp + 0x50]
    add rax, qword ptr [rbp + 0x70]
    add rax, 0
    lea rdx, [rbp]
    mov ecx, 1
    mov qword ptr [rbp + 0x58], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x58]
    mov r8, rax
    call reloc(memcpy)
L_0133:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jle L_008f
L_0151:
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_IU_STRUPR:

IU_STRLWR:
    push rbp
pro_IU_STRLWR_01:
    sub rsp, 0xf0
pro_IU_STRLWR_08:
    lea rbp, [rsp + 0x30]
pro_IU_STRLWR_0d:
    mov qword ptr [rbp + 0xb0], rbx
pro_IU_STRLWR_14:
    mov qword ptr [rbp + 0xd0], rcx
    mov qword ptr [rbp + 0xd8], rdx
    mov rax, qword ptr [rbp + 0xd8]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    long jle L_036b
L_01a1:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x28], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x30], rax
    lea rax, [rbp]
    mov rdx, qword ptr [rbp + 0x30]
    add rdx, qword ptr [rbp + 0xd0]
    add rdx, 0
    mov ecx, 1
    mov qword ptr [rbp + 0x88], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x88]
    mov r8, rax
    call reloc(memcpy)
    lea rax, [rbp]
    mov edx, 1
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    mov ebx, 1
    mov qword ptr [rsp + 0x20], 4
    mov qword ptr [rbp + 0x90], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x90]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpstr)
    mov qword ptr [rbp + 0x38], rax
    lea rax, [rbp]
    mov edx, 1
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    mov ebx, 1
    mov qword ptr [rsp + 0x20], 5
    mov qword ptr [rbp + 0x98], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x98]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpstr)
    mov qword ptr [rbp + 0x40], rax
    mov eax, dword ptr [rbp + 0x38]
    test eax, eax
    long je L_034d
    mov eax, dword ptr [rbp + 0x40]
    test eax, eax
    long je L_034d
    lea rax, [rip + reloc(.data, IU_STRLWR$UPP - .data)]
    mov edx, 0x1a
    lea rcx, [rbp]
    mov ebx, 1
    mov dword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0xa0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa0]
    mov r8, rax
    mov r9d, ebx
    call reloc(for_f90_index)
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x48]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    test rax, rax
    short jle L_034d
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x60], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x68], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x78], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x70]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x68]
    add rax, qword ptr [rbp + 0xd0]
    add rax, 0
    lea rdx, [rip + reloc(.data, IU_STRLWR$LOW - .data)]
    add rdx, qword ptr [rbp + 0x80]
    mov ecx, 1
    mov qword ptr [rbp + 0xa8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xa8]
    mov r8, rax
    call reloc(memcpy)
L_034d:
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jle L_01a1
L_036b:
    mov rbx, qword ptr [rbp + 0xb0]
    lea rsp, [rbp + 0xc0]
    pop rbp
    ret
end_IU_STRLWR:

IU_CLRSTR:
    push rbp
pro_IU_CLRSTR_01:
    sub rsp, 0x50
pro_IU_CLRSTR_05:
    lea rbp, [rsp + 0x30]
pro_IU_CLRSTR_0a:
    mov qword ptr [rbp + 0x10], rbx
pro_IU_CLRSTR_0e:
    mov qword ptr [rbp + 0x30], rcx
    mov qword ptr [rbp + 0x38], rdx
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x30]
    mov rdx, qword ptr [rbp]
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    mov ebx, 1
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    mov rbx, qword ptr [rbp + 0x10]
    lea rsp, [rbp + 0x20]
    pop rbp
    ret
end_IU_CLRSTR:

IU_TRIMSTR:
    push rbp
pro_IU_TRIMSTR_01:
    sub rsp, 0x100
pro_IU_TRIMSTR_08:
    lea rbp, [rsp + 0x30]
pro_IU_TRIMSTR_0d:
    mov qword ptr [rbp + 0xc0], rbx
pro_IU_TRIMSTR_14:
    mov qword ptr [rbp + 0xe0], rcx
    mov qword ptr [rbp + 0xe8], rdx
    mov qword ptr [rbp + 0xf0], r8
    mov qword ptr [rbp], 1
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_0490
L_042b:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x38], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    add rax, qword ptr [rbp + 0xe0]
    movzx eax, byte ptr [rax]
    movzx eax, al
    movzx edx, byte ptr [rip + reloc(.rdata, __STRLITPACK_10 - .rdata)]
    movzx edx, dl
    modrm cmp eax, edx
    short jne L_0490
    mov eax, 1
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_042b
L_0490:
    mov rax, qword ptr [rbp + 0xe8]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp]
    modrm cmp rax, rdx
    short jl L_0537
L_04c6:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x50], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x48]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x58]
    add rax, qword ptr [rbp + 0xe0]
    movzx eax, byte ptr [rax]
    movzx eax, al
    movzx edx, byte ptr [rip + reloc(.rdata, __STRLITPACK_9 - .rdata)]
    movzx edx, dl
    modrm cmp eax, edx
    short je L_0537
    mov rax, qword ptr [rbp + 0xe8]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0xe8]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    short jle L_04c6
L_0537:
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    test rax, rax
    long je L_06c8
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    test rax, rax
    short jg L_056b
    mov qword ptr [rbp + 0x68], 0
    short jmp L_0573
L_056b:
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x68], rax
L_0573:
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0xe8]
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp]
    dec rax
    mov qword ptr [rbp + 0x78], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x70]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x80]
    neg rax
    add rax, qword ptr [rbp + 0x78]
    test rax, rax
    short jg L_05c2
    mov qword ptr [rbp + 0x88], 0
    short jmp L_05d7
L_05c2:
    mov rax, qword ptr [rbp + 0x80]
    neg rax
    add rax, qword ptr [rbp + 0x78]
    mov qword ptr [rbp + 0x88], rax
L_05d7:
    mov eax, 0
    add rax, qword ptr [rbp + 0xe0]
    mov rdx, qword ptr [rbp + 0x68]
    mov rcx, qword ptr [rbp + 0x80]
    add rcx, qword ptr [rbp + 0xe0]
    add rcx, 0
    mov rbx, qword ptr [rbp + 0x88]
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0xb8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    mov rax, qword ptr [rbp + 0xf0]
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0xe8]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rdx
    mov rax, qword ptr [rbp + 0x98]
    mov rdx, qword ptr [rbp + 0xe8]
    mov ecx, 1
    add rcx, qword ptr [rdx]
    modrm cmp rax, rcx
    short jl L_06c8
L_066f:
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0xa0], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0xa0]
    mov qword ptr [rbp + 0xb0], rax
    mov rax, qword ptr [rbp + 0xb0]
    add rax, qword ptr [rbp + 0xe0]
    mov byte ptr [rax], 0x20
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x98]
    modrm cmp rax, rdx
    short jle L_066f
L_06c8:
    mov rbx, qword ptr [rbp + 0xc0]
    lea rsp, [rbp + 0xd0]
    pop rbp
    ret
end_IU_TRIMSTR:

IU_CLRSCR:
    push rbp
pro_IU_CLRSCR_01:
    sub rsp, 0xa0
pro_IU_CLRSCR_08:
    lea rbp, [rsp + 0x30]
pro_IU_CLRSCR_0d:
    mov qword ptr [rbp + 0x60], rsi
pro_IU_CLRSCR_11:
    mov qword ptr [rbp + 0x58], rbx
pro_IU_CLRSCR_15:
    lea rax, [rbp]
    mov byte ptr [rax], 0x1b
    lea rax, [rbp]
    inc rax
    mov edx, 3
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_14 - .rdata)]
    mov ebx, 2
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x48], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x48]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    lea rax, [rbp]
    add rax, 4
    mov byte ptr [rax], 0x1b
    lea rax, [rbp]
    add rax, 5
    mov word ptr [rax], 0x325b
    lea rax, [rbp]
    add rax, 5
    add rax, 2
    mov byte ptr [rax], 0x4a
    mov qword ptr [rbp + 8], 0
    mov qword ptr [rbp + 0x38], 8
    lea rax, [rbp]
    mov qword ptr [rbp + 0x40], rax
    lea rax, [rbp + 8]
    mov edx, 0xffffffff
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_15 - .rdata)]
    lea rsi, [rbp + 0x38]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rip + reloc(.data, IU_CLRSCR$format_pack - .data)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x50], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x50]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_fmt)
    mov rbx, qword ptr [rbp + 0x58]
    mov rsi, qword ptr [rbp + 0x60]
    lea rsp, [rbp + 0x70]
    pop rbp
    ret
end_IU_CLRSCR:

IU_STRLEN:
    push rbp
pro_IU_STRLEN_01:
    sub rsp, 0x60
pro_IU_STRLEN_05:
    lea rbp, [rsp + 0x20]
pro_IU_STRLEN_0a:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp]
    mov qword ptr [rax], rdx
L_07e6:
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_0888
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x18]
    add rax, qword ptr [rbp + 0x58]
    movzx eax, byte ptr [rax]
    movzx eax, al
    movzx edx, byte ptr [rip + reloc(.rdata, __STRLITPACK_16 - .rdata)]
    movzx edx, dl
    modrm cmp eax, edx
    short je L_086e
    mov rax, qword ptr [rbp + 0x30]
    add rax, qword ptr [rbp + 0x58]
    movzx eax, byte ptr [rax]
    movzx eax, al
    test eax, eax
    short jne L_0888
L_086e:
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x50]
    mov qword ptr [rax], rdx
    long jmp L_07e6
L_0888:
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_IU_STRLEN:

IU_PACKSTR:
    push rbp
pro_IU_PACKSTR_01:
    sub rsp, 0x100
pro_IU_PACKSTR_08:
    lea rbp, [rsp + 0x30]
pro_IU_PACKSTR_0d:
    mov qword ptr [rbp + 0xc0], rbx
pro_IU_PACKSTR_14:
    mov qword ptr [rbp + 0xe0], rcx
    mov qword ptr [rbp + 0xe8], rdx
    mov rax, qword ptr [rbp + 0xe8]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov byte ptr [rbp], 0
    mov qword ptr [rbp + 0x18], 0
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    long jle L_0a30
L_08ec:
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x30], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x38], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x50], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x48]
    mov qword ptr [rbp + 0x58], rax
    mov rax, qword ptr [rbp + 0x40]
    add rax, qword ptr [rbp + 0xe0]
    movzx eax, byte ptr [rax]
    movzx eax, al
    movzx edx, byte ptr [rip + reloc(.rdata, __STRLITPACK_18 - .rdata)]
    movzx edx, dl
    modrm cmp eax, edx
    long je L_0a12
    mov rax, qword ptr [rbp + 0x58]
    add rax, qword ptr [rbp + 0xe0]
    movzx eax, byte ptr [rax]
    movzx eax, al
    movzx edx, byte ptr [rbp]
    movzx edx, dl
    modrm cmp eax, edx
    long je L_0a12
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x80], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x88], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x80]
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x98], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0xa0], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x98]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0x90]
    add rax, qword ptr [rbp + 0xe0]
    add rax, 0
    mov rdx, qword ptr [rbp + 0xa8]
    add rdx, qword ptr [rbp + 0xe0]
    add rdx, 0
    mov ecx, 1
    mov qword ptr [rbp + 0xb0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb0]
    mov r8, rax
    call reloc(memcpy)
L_0a12:
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    long jle L_08ec
L_0a30:
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    long jge L_0ad5
    mov rax, qword ptr [rbp + 0xe8]
    mov qword ptr [rbp + 0x60], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x68], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x68]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x70]
    neg rax
    add rax, qword ptr [rbp + 0x60]
    test rax, rax
    short jg L_0a82
    mov qword ptr [rbp + 0x78], 0
    short jmp L_0a91
L_0a82:
    mov rax, qword ptr [rbp + 0x70]
    neg rax
    add rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x78], rax
L_0a91:
    mov rax, qword ptr [rbp + 0x70]
    add rax, qword ptr [rbp + 0xe0]
    add rax, 0
    mov rdx, qword ptr [rbp + 0x78]
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_17 - .rdata)]
    mov ebx, 1
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0xb8], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0xb8]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
L_0ad5:
    mov rbx, qword ptr [rbp + 0xc0]
    lea rsp, [rbp + 0xd0]
    pop rbp
    ret
end_IU_PACKSTR:

IU_I42STR:
    push rbp
pro_IU_I42STR_01:
    sub rsp, 0x70
pro_IU_I42STR_05:
    lea rbp, [rsp + 0x30]
pro_IU_I42STR_0a:
    mov qword ptr [rbp + 0x30], rbx
pro_IU_I42STR_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x58]
    mov rax, qword ptr [rax]
    imul rax, rax, 4
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x68]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jg L_0b6c
    mov rax, qword ptr [rbp + 0x68]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x18]
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_19 - .rdata)]
    mov ebx, 1
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x20], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x20]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    short jmp L_0b74
L_0b6c:
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp], rax
L_0b74:
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x50]
    mov rcx, qword ptr [rbp]
    mov qword ptr [rbp + 0x28], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x28]
    mov r8, rax
    call reloc(RTO_I42STR)
    mov rbx, qword ptr [rbp + 0x30]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_IU_I42STR:

IU_STR2I4:
    push rbp
pro_IU_STR2I4_01:
    sub rsp, 0x50
pro_IU_STR2I4_05:
    lea rbp, [rsp + 0x20]
pro_IU_STR2I4_0a:
    mov qword ptr [rbp + 0x40], rcx
    mov qword ptr [rbp + 0x48], rdx
    mov qword ptr [rbp + 0x50], r8
    mov qword ptr [rbp + 0x58], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov qword ptr [rbp + 8], 1
    mov rax, qword ptr [rbp]
    test rax, rax
    short jle L_0c07
L_0bd3:
    mov rax, qword ptr [rbp + 8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x48]
    add rax, -8
    mov rdx, qword ptr [rip + reloc(.data, IU_STR2I4$IBLANK - .data)]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov rdx, qword ptr [rbp]
    modrm cmp rax, rdx
    short jle L_0bd3
L_0c07:
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 4
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_0c3b
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x10], rax
L_0c3b:
    mov rax, qword ptr [rbp + 0x48]
    mov rdx, qword ptr [rbp + 0x40]
    mov rcx, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x28], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x28]
    mov r8, rax
    call reloc(RTO_STR2I4)
    lea rsp, [rbp + 0x30]
    pop rbp
    ret
end_IU_STR2I4:

IU_R82STR:
    push rbp
pro_IU_R82STR_01:
    sub rsp, 0x70
pro_IU_R82STR_05:
    lea rbp, [rsp + 0x30]
pro_IU_R82STR_0a:
    mov qword ptr [rbp + 0x30], rbx
pro_IU_R82STR_0e:
    mov qword ptr [rbp + 0x50], rcx
    mov qword ptr [rbp + 0x58], rdx
    mov qword ptr [rbp + 0x60], r8
    mov qword ptr [rbp + 0x68], r9
    mov rax, qword ptr [rbp + 0x58]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x68]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jg L_0ce7
    mov rax, qword ptr [rbp + 0x68]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x18]
    lea rcx, [rip + reloc(.rdata, __STRLITPACK_20 - .rdata)]
    mov ebx, 1
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x20], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x20]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    short jmp L_0cef
L_0ce7:
    mov rax, qword ptr [rbp + 0x10]
    mov qword ptr [rbp], rax
L_0cef:
    mov rax, qword ptr [rbp + 0x60]
    mov rdx, qword ptr [rbp + 0x50]
    mov rcx, qword ptr [rbp]
    mov qword ptr [rbp + 0x28], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x28]
    mov r8, rax
    call reloc(RTO_R82STR)
    mov rbx, qword ptr [rbp + 0x30]
    lea rsp, [rbp + 0x40]
    pop rbp
    ret
end_IU_R82STR:

IU_STR2R8:
    push rbp
pro_IU_STR2R8_01:
    sub rsp, 0x50
pro_IU_STR2R8_05:
    lea rbp, [rsp + 0x20]
pro_IU_STR2R8_0a:
    mov qword ptr [rbp + 0x40], rcx
    mov qword ptr [rbp + 0x48], rdx
    mov qword ptr [rbp + 0x50], r8
    mov qword ptr [rbp + 0x58], r9
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov qword ptr [rbp + 8], 1
    mov rax, qword ptr [rbp]
    test rax, rax
    short jle L_0d84
L_0d4e:
    mov rax, qword ptr [rbp + 8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x48]
    add rax, -8
    movsd xmm0, qword ptr [rip + reloc(.data, IU_STR2R8$RBLANK - .data)]
    movsd qword ptr [rax], xmm0
    mov eax, 1
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 8]
    mov rdx, qword ptr [rbp]
    modrm cmp rax, rdx
    short jle L_0d4e
L_0d84:
    mov rax, qword ptr [rbp + 0x50]
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x10]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_0db8
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x10], rax
L_0db8:
    mov rax, qword ptr [rbp + 0x48]
    mov rdx, qword ptr [rbp + 0x40]
    mov rcx, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x28], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x28]
    mov r8, rax
    call reloc(RTO_STR2R8)
    lea rsp, [rbp + 0x30]
    pop rbp
    ret
end_IU_STR2R8:

IU_STRCAT:
    push rbp
pro_IU_STRCAT_01:
    sub rsp, 0xc0
pro_IU_STRCAT_08:
    lea rbp, [rsp + 0x30]
pro_IU_STRCAT_0d:
    mov qword ptr [rbp + 0x88], rbx
pro_IU_STRCAT_14:
    mov qword ptr [rbp + 0xa0], rcx
    mov qword ptr [rbp + 0xa8], rdx
    mov qword ptr [rbp + 0xb0], r8
    mov qword ptr [rbp + 0xb8], r9
    mov rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0xb0]
    mov qword ptr [rbp + 0x10], rax
    lea rax, [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0xa0]
    mov rcx, qword ptr [rbp + 0x10]
    mov qword ptr [rbp + 0x70], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x70]
    mov r8, rax
    call reloc(IU_STRLEN)
    mov rax, qword ptr [rbp + 0xb8]
    mov qword ptr [rbp + 0x20], rax
    lea rax, [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0xa8]
    mov rcx, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x78], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x78]
    mov r8, rax
    call reloc(IU_STRLEN)
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 8]
    mov rdx, qword ptr [rbp + 0x28]
    modrm cmp rax, rdx
    short jle L_0e98
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x30], rax
    short jmp L_0ea7
L_0e98:
    mov rax, qword ptr [rbp + 0x18]
    neg rax
    add rax, qword ptr [rbp + 8]
    mov qword ptr [rbp + 0x30], rax
L_0ea7:
    mov rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x38], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x38]
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x48], rax
    mov rax, 0xffffffffffffffff
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    neg rax
    add rax, qword ptr [rbp + 0x48]
    test rax, rax
    short jg L_0ef1
    mov qword ptr [rbp + 0x58], 0
    short jmp L_0f00
L_0ef1:
    mov rax, qword ptr [rbp + 0x50]
    neg rax
    add rax, qword ptr [rbp + 0x48]
    mov qword ptr [rbp + 0x58], rax
L_0f00:
    mov rax, qword ptr [rbp + 0x38]
    mov qword ptr [rbp + 0x60], rax
    mov rax, qword ptr [rbp + 0x60]
    test rax, rax
    short jg L_0f1b
    mov qword ptr [rbp + 0x68], 0
    short jmp L_0f23
L_0f1b:
    mov rax, qword ptr [rbp + 0x60]
    mov qword ptr [rbp + 0x68], rax
L_0f23:
    mov rax, qword ptr [rbp + 0x50]
    add rax, qword ptr [rbp + 0xa0]
    add rax, 0
    mov rdx, qword ptr [rbp + 0x58]
    mov ecx, 0
    add rcx, qword ptr [rbp + 0xa8]
    mov rbx, qword ptr [rbp + 0x68]
    mov qword ptr [rsp + 0x20], 0
    mov qword ptr [rbp + 0x80], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x80]
    mov r8, rax
    mov r9, rbx
    call reloc(for_cpystr)
    mov rbx, qword ptr [rbp + 0x88]
    lea rsp, [rbp + 0x90]
    pop rbp
    ret
end_IU_STRCAT:
    nop

.section .rdata 0x40300040
__STRLITPACK_2:
    .byte 0x61
    .zero 3
__STRLITPACK_1:
    .byte 0x7a
    .zero 3
__STRLITPACK_0:
    .byte 0x41
    .zero 3
__STRLITPACK_4:
    .byte 0x41
    .zero 3
__STRLITPACK_3:
    .byte 0x5a
    .zero 3
__STRLITPACK_7:
    .byte 0x20
    .zero 3
__STRLITPACK_10:
    .byte 0x20
    .zero 3
__STRLITPACK_9:
    .byte 0x20
    .zero 3
__STRLITPACK_14:
    .byte 0x5b, 0x48
    .zero 2
__STRLITPACK_15:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_16:
    .byte 0x20
    .zero 3
__STRLITPACK_18:
    .byte 0x20
    .zero 3
__STRLITPACK_17:
    .byte 0x20
    .zero 3
__STRLITPACK_19:
    .byte 0x20
    .zero 3
__STRLITPACK_20:
    .byte 0x20
    .zero 3

.section .bss 0xc0400080
IU_STRUPR$LA:
    .space 8
IU_STRUPR$LZ:
    .space 8
IU_STRUPR$LOFF:
    .space 8

.section .xdata 0x40300040
unwind_IU_STRUPR:
    .unwind IU_STRUPR, pro_IU_STRUPR_0d, rbp, 32
        .set_fpreg pro_IU_STRUPR_0d
        .alloc_small pro_IU_STRUPR_08, 128
        .push_nonvol pro_IU_STRUPR_01, rbp
    .endunwind
unwind_IU_STRLWR:
    .unwind IU_STRLWR, pro_IU_STRLWR_14, rbp, 48
        .save_nonvol pro_IU_STRLWR_14, rbx, 224
        .set_fpreg pro_IU_STRLWR_0d
        .alloc_large pro_IU_STRLWR_08, 240
        .push_nonvol pro_IU_STRLWR_01, rbp
    .endunwind
unwind_IU_CLRSTR:
    .unwind IU_CLRSTR, pro_IU_CLRSTR_0e, rbp, 48
        .save_nonvol pro_IU_CLRSTR_0e, rbx, 64
        .set_fpreg pro_IU_CLRSTR_0a
        .alloc_small pro_IU_CLRSTR_05, 80
        .push_nonvol pro_IU_CLRSTR_01, rbp
    .endunwind
unwind_IU_TRIMSTR:
    .unwind IU_TRIMSTR, pro_IU_TRIMSTR_14, rbp, 48
        .save_nonvol pro_IU_TRIMSTR_14, rbx, 240
        .set_fpreg pro_IU_TRIMSTR_0d
        .alloc_large pro_IU_TRIMSTR_08, 256
        .push_nonvol pro_IU_TRIMSTR_01, rbp
    .endunwind
unwind_IU_CLRSCR:
    .unwind IU_CLRSCR, pro_IU_CLRSCR_15, rbp, 48
        .save_nonvol pro_IU_CLRSCR_15, rbx, 136
        .save_nonvol pro_IU_CLRSCR_11, rsi, 144
        .set_fpreg pro_IU_CLRSCR_0d
        .alloc_large pro_IU_CLRSCR_08, 160
        .push_nonvol pro_IU_CLRSCR_01, rbp
    .endunwind
unwind_IU_STRLEN:
    .unwind IU_STRLEN, pro_IU_STRLEN_0a, rbp, 32
        .set_fpreg pro_IU_STRLEN_0a
        .alloc_small pro_IU_STRLEN_05, 96
        .push_nonvol pro_IU_STRLEN_01, rbp
    .endunwind
unwind_IU_PACKSTR:
    .unwind IU_PACKSTR, pro_IU_PACKSTR_14, rbp, 48
        .save_nonvol pro_IU_PACKSTR_14, rbx, 240
        .set_fpreg pro_IU_PACKSTR_0d
        .alloc_large pro_IU_PACKSTR_08, 256
        .push_nonvol pro_IU_PACKSTR_01, rbp
    .endunwind
unwind_IU_I42STR:
    .unwind IU_I42STR, pro_IU_I42STR_0e, rbp, 48
        .save_nonvol pro_IU_I42STR_0e, rbx, 96
        .set_fpreg pro_IU_I42STR_0a
        .alloc_small pro_IU_I42STR_05, 112
        .push_nonvol pro_IU_I42STR_01, rbp
    .endunwind
unwind_IU_STR2I4:
    .unwind IU_STR2I4, pro_IU_STR2I4_0a, rbp, 32
        .set_fpreg pro_IU_STR2I4_0a
        .alloc_small pro_IU_STR2I4_05, 80
        .push_nonvol pro_IU_STR2I4_01, rbp
    .endunwind
unwind_IU_R82STR:
    .unwind IU_R82STR, pro_IU_R82STR_0e, rbp, 48
        .save_nonvol pro_IU_R82STR_0e, rbx, 96
        .set_fpreg pro_IU_R82STR_0a
        .alloc_small pro_IU_R82STR_05, 112
        .push_nonvol pro_IU_R82STR_01, rbp
    .endunwind
unwind_IU_STR2R8:
    .unwind IU_STR2R8, pro_IU_STR2R8_0a, rbp, 32
        .set_fpreg pro_IU_STR2R8_0a
        .alloc_small pro_IU_STR2R8_05, 80
        .push_nonvol pro_IU_STR2R8_01, rbp
    .endunwind
unwind_IU_STRCAT:
    .unwind IU_STRCAT, pro_IU_STRCAT_14, rbp, 48
        .save_nonvol pro_IU_STRCAT_14, rbx, 184
        .set_fpreg pro_IU_STRCAT_0d
        .alloc_large pro_IU_STRCAT_08, 192
        .push_nonvol pro_IU_STRCAT_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva IU_STRUPR
    .rva IU_STRUPR, end_IU_STRUPR - IU_STRUPR
    .rva .xdata, unwind_IU_STRUPR - .xdata
    .rva IU_STRLWR
    .rva IU_STRLWR, end_IU_STRLWR - IU_STRLWR
    .rva .xdata, unwind_IU_STRLWR - .xdata
    .rva IU_CLRSTR
    .rva IU_CLRSTR, end_IU_CLRSTR - IU_CLRSTR
    .rva .xdata, unwind_IU_CLRSTR - .xdata
    .rva IU_TRIMSTR
    .rva IU_TRIMSTR, end_IU_TRIMSTR - IU_TRIMSTR
    .rva .xdata, unwind_IU_TRIMSTR - .xdata
    .rva IU_CLRSCR
    .rva IU_CLRSCR, end_IU_CLRSCR - IU_CLRSCR
    .rva .xdata, unwind_IU_CLRSCR - .xdata
    .rva IU_STRLEN
    .rva IU_STRLEN, end_IU_STRLEN - IU_STRLEN
    .rva .xdata, unwind_IU_STRLEN - .xdata
    .rva IU_PACKSTR
    .rva IU_PACKSTR, end_IU_PACKSTR - IU_PACKSTR
    .rva .xdata, unwind_IU_PACKSTR - .xdata
    .rva IU_I42STR
    .rva IU_I42STR, end_IU_I42STR - IU_I42STR
    .rva .xdata, unwind_IU_I42STR - .xdata
    .rva IU_STR2I4
    .rva IU_STR2I4, end_IU_STR2I4 - IU_STR2I4
    .rva .xdata, unwind_IU_STR2I4 - .xdata
    .rva IU_R82STR
    .rva IU_R82STR, end_IU_R82STR - IU_R82STR
    .rva .xdata, unwind_IU_R82STR - .xdata
    .rva IU_STR2R8
    .rva IU_STR2R8, end_IU_STR2R8 - IU_STR2R8
    .rva .xdata, unwind_IU_STR2R8 - .xdata
    .rva IU_STRCAT
    .rva IU_STRCAT, end_IU_STRCAT - IU_STRCAT
    .rva .xdata, unwind_IU_STRCAT - .xdata

.section .data 0xc0400040
IU_STRLWR$UPP:
    .ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
IU_STRLWR$LOW:
    .ascii "abcdefghijklmnopqrstuvwxyz"
IU_CLRSCR$format_pack:
    .byte 0x36
    .zero 3
    .byte 0x0e
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x1d
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x08
    .zero 3
    .byte 0x37
    .zero 7
IU_STR2I4$IBLANK:
    .ascii "        "
IU_STR2R8$RBLANK:
    .ascii "        "

.section .drectve 0x00100a00
    .ascii "-export:IU_STRCAT  -export:IU_STR2R8  -export:IU_R82STR  -export:IU_STR2I4  -export:IU_I42STR  -export:IU_PACKSTR  -export:IU_STRLEN  -export:IU_CLRSCR  -export:IU_TRIMSTR  -export:IU_CLRSTR  -export:IU_STRLWR  -export:IU_STRUPR  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\rto_getioc.obj 1743626480
.index RTO_GETIOC
.index RTUT_RTIOC

.symbol .text section local
.symbol RTO_GETIOC function public
.symbol RTUT_RTIOC common public 352
.symbol .data section local
.symbol .rdata section local
.symbol for_inquire external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol RTO_GETIOC$FIRST_TIME data local
.symbol __STRLITPACK_0 data local
.symbol .drectve section local
.symbol __ImageBase external public function

.section .text 0x60300020

RTO_GETIOC:
    ; RTUT_RTIOC contains the rotating index and forty 8-byte slots. The index plus 59 supplies the candidate unit number.
    push rbp
pro_RTO_GETIOC_01:
    sub rsp, 0x90
pro_RTO_GETIOC_08:
    lea rbp, [rsp + 0x30]
pro_RTO_GETIOC_0d:
    mov qword ptr [rbp + 0x58], rsi
pro_RTO_GETIOC_11:
    mov qword ptr [rbp + 0x50], rbx
pro_RTO_GETIOC_15:
    mov qword ptr [rbp + 0x70], rcx
    mov qword ptr [rbp + 0x78], rdx
    mov rax, qword ptr [rip + reloc(.data, RTO_GETIOC$FIRST_TIME - .data)]
    test rax, rax
    short je L_007f
    mov qword ptr [rip + reloc(RTUT_RTIOC)], 0
    mov qword ptr [rip + reloc(.data, RTO_GETIOC$FIRST_TIME - .data)], 0
    mov qword ptr [rbp], 1
L_0047:
    mov rax, qword ptr [rbp]
    imul rax, rax, 8
    lea rdx, [rip + reloc(RTUT_RTIOC)]
    add rdx, 8
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 0
    mov eax, 1
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    cmp rax, 0x28
    short jle L_0047
L_007f:
    mov qword ptr [rbp], 1
L_0087:
    mov eax, 1
    add rax, qword ptr [rip + reloc(RTUT_RTIOC)]
    mov qword ptr [rip + reloc(RTUT_RTIOC)], rax
    mov rax, qword ptr [rip + reloc(RTUT_RTIOC)]
    cmp rax, 0x28
    short jle L_00b2
    mov qword ptr [rip + reloc(RTUT_RTIOC)], 1
L_00b2:
    mov rax, qword ptr [rip + reloc(RTUT_RTIOC)]
    imul rax, rax, 8
    lea rdx, [rip + reloc(RTUT_RTIOC)]
    add rdx, 8
    modrm add rdx, rax
    add rdx, -8
    mov rax, qword ptr [rdx]
    test rax, rax
    long jne L_0172
    mov eax, 0x3b
    add rax, qword ptr [rip + reloc(RTUT_RTIOC)]
    mov rdx, qword ptr [rbp + 0x70]
    mov qword ptr [rdx], rax
    mov qword ptr [rbp + 8], 0
    lea rax, [rbp + 0x38]
    mov qword ptr [rbp + 0x40], rax
    lea rax, [rbp + 8]
    mov rdx, qword ptr [rbp + 0x70]
    mov edx, dword ptr [rdx]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_0 - .rdata)]
    lea rsi, [rbp + 0x40]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x48], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x48]
    mov r8, rax
    mov r9, rbx
    call reloc(for_inquire)
    mov eax, dword ptr [rbp + 0x38]
    test al, 1
    short je L_0165
    mov rax, qword ptr [rip + reloc(RTUT_RTIOC)]
    imul rax, rax, 8
    lea rdx, [rip + reloc(RTUT_RTIOC)]
    add rdx, 8
    modrm add rdx, rax
    add rdx, -8
    mov qword ptr [rdx], 1
    short jmp L_0172
L_0165:
    mov rax, qword ptr [rbp + 0x78]
    mov qword ptr [rax], 0
    short jmp L_01a3
L_0172:
    mov eax, 1
    add rax, qword ptr [rbp]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp]
    cmp rax, 0x28
    long jle L_0087
    mov rax, qword ptr [rbp + 0x78]
    mov qword ptr [rax], 1
    mov rax, qword ptr [rbp + 0x70]
    mov qword ptr [rax], 0xffffffffffffffff
L_01a3:
    mov rbx, qword ptr [rbp + 0x50]
    mov rsi, qword ptr [rbp + 0x58]
    lea rsp, [rbp + 0x60]
    pop rbp
    ret
end_RTO_GETIOC:
    nop
    nop
    nop

.section .data 0xc0400040
RTO_GETIOC$FIRST_TIME:
    .byte 0x01
    .zero 7

.section .rdata 0x40300040
__STRLITPACK_0:
    .byte 0x11, 0x03, 0x23, 0x00, 0x01
    .zero 7

.section .xdata 0x40300040
unwind_RTO_GETIOC:
    .unwind RTO_GETIOC, pro_RTO_GETIOC_15, rbp, 48
        .save_nonvol pro_RTO_GETIOC_15, rbx, 128
        .save_nonvol pro_RTO_GETIOC_11, rsi, 136
        .set_fpreg pro_RTO_GETIOC_0d
        .alloc_large pro_RTO_GETIOC_08, 144
        .push_nonvol pro_RTO_GETIOC_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva RTO_GETIOC
    .rva RTO_GETIOC, end_RTO_GETIOC - RTO_GETIOC
    .rva .xdata, unwind_RTO_GETIOC - .xdata

.section .drectve 0x00100a00
    .ascii "-export:RTO_GETIOC  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "

; ====================================================================
.member x64\Release\kpr.obj 1743626480
.index U3_BKSORT
.index U3_KPR
.index U3_SUP2

.symbol .text section local
.symbol U3_KPR function public
.symbol U3_BKSORT function public
.symbol U3_SUP2 common public 1024
.symbol .rdata section local
.symbol .data section local
.symbol for_write_seq_fmt external public function
.symbol for_write_seq_fmt_xmit external public function
.symbol .xdata section local
.symbol .pdata section local
.symbol U3_KPR$format_pack data local
.symbol __STRLITPACK_3 data local
.symbol __STRLITPACK_4 data local
.symbol __STRLITPACK_5 data local
.symbol __STRLITPACK_6 data local
.symbol __STRLITPACK_7 data local
.symbol .drectve section local
.symbol __ImageBase external public function

.section .text 0x60300020

U3_KPR:
    push rbp
pro_U3_KPR_01:
    sub rsp, 0x1f0
pro_U3_KPR_08:
    lea rbp, [rsp + 0x30]
pro_U3_KPR_0d:
    mov qword ptr [rbp + 0x1b0], rsi
pro_U3_KPR_14:
    mov qword ptr [rbp + 0x1a8], rbx
pro_U3_KPR_1b:
    mov qword ptr [rbp + 0x1d0], rcx
    mov qword ptr [rbp + 0x1d8], rdx
    mov qword ptr [rbp + 0x1e0], r8
    mov qword ptr [rbp + 0x1e8], r9
    mov rax, qword ptr [rbp + 0x1e0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x1d8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x1d0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
    mov rax, qword ptr [rbp + 0x1d8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x18]
    test rax, rax
    short jle L_00ce
L_0080:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov qword ptr [rax], 0xffffffffffffffff
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov qword ptr [rax], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x18]
    modrm cmp rax, rdx
    short jle L_0080
L_00ce:
    mov rax, qword ptr [rbp + 0x1d8]
    mov edx, 1
    add rdx, qword ptr [rax]
    imul rax, rdx, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov qword ptr [rax], 0
    mov qword ptr [rbp + 0x28], 0
    mov qword ptr [rbp + 0x30], 0
    mov rax, qword ptr [rbp + 0x1e0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x38], rax
    mov qword ptr [rbp + 0x40], 1
    mov rax, qword ptr [rbp + 0x38]
    test rax, rax
    long jle L_0247
L_0126:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_015d
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, -1
    short jne L_0189
L_015d:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov qword ptr [rax], 0
L_0189:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1e8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    long je L_0229
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1e8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x78], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x78]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    short jl L_0221
L_01ed:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x218]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x40]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x78]
    modrm cmp rax, rdx
    short jle L_01ed
L_0221:
    mov rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x30], rax
L_0229:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x38]
    modrm cmp rax, rdx
    long jle L_0126
L_0247:
    mov rax, qword ptr [rbp + 0x1d0]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x48], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x48]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x30]
    modrm cmp rax, rdx
    short jl L_02b8
L_0279:
    mov rax, qword ptr [rbp + 0x1e0]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x218]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x50]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    mov rdx, qword ptr [rbp + 0x48]
    modrm cmp rax, rdx
    short jle L_0279
L_02b8:
    mov rax, qword ptr [rbp + 0x1d8]
    mov rdx, qword ptr [rbp + 0x1e0]
    mov rcx, qword ptr [rbp + 0x1f0]
    mov rbx, qword ptr [rbp + 0x230]
    mov rsi, qword ptr [rbp + 0x228]
    mov qword ptr [rsp + 0x20], rsi
    mov qword ptr [rbp + 0x178], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x178]
    mov r8, rax
    mov r9, rbx
    call reloc(U3_BKSORT)
    mov qword ptr [rbp + 0x58], 0
    mov rax, qword ptr [rbp + 0x1e0]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x60], rax
    mov qword ptr [rbp + 0x40], 1
    mov rax, qword ptr [rbp + 0x60]
    test rax, rax
    long jle L_041b
L_0327:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x230]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov rdx, qword ptr [rbp + 0x58]
    modrm cmp rax, rdx
    long je L_03fd
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x230]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x90], rax
    mov rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x98], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x98]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x58]
    modrm cmp rax, rdx
    short jl L_03f2
L_03bb:
    mov rax, qword ptr [rbp + 0x70]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x40]
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x70]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x70]
    mov rdx, qword ptr [rbp + 0x98]
    modrm cmp rax, rdx
    short jle L_03bb
L_03f2:
    mov rax, qword ptr [rbp + 0x90]
    mov qword ptr [rbp + 0x58], rax
L_03fd:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x60]
    modrm cmp rax, rdx
    long jle L_0327
L_041b:
    mov rax, qword ptr [rbp + 0x1d8]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x68], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x58]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x68]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x58]
    modrm cmp rax, rdx
    short jl L_048c
L_044d:
    mov rax, qword ptr [rbp + 0x1e0]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x70]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x70]
    mov qword ptr [rbp + 0x70], rax
    mov rax, qword ptr [rbp + 0x70]
    mov rdx, qword ptr [rbp + 0x68]
    modrm cmp rax, rdx
    short jle L_044d
L_048c:
    mov rax, qword ptr [rbp + 0x208]
    mov qword ptr [rax], 0
    mov rax, qword ptr [rbp + 0x1d8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x80], rax
    mov qword ptr [rbp + 0x88], 1
    mov rax, qword ptr [rbp + 0x80]
    test rax, rax
    long jle L_085c
L_04c6:
    mov rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    long jne L_0832
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xb0], rax
    mov qword ptr [rbp + 0xa8], 1
    mov rax, qword ptr [rbp + 0xb0]
    test rax, rax
    short jle L_0553
L_0510:
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov qword ptr [rax], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, qword ptr [rbp + 0xb0]
    modrm cmp rax, rdx
    short jle L_0510
L_0553:
    mov rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x100], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x108], rdx
    mov rax, qword ptr [rbp + 0x100]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x108]
    mov rdx, qword ptr [rbp + 0x100]
    modrm cmp rax, rdx
    long jl L_0768
L_05c1:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x230]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x50], rax
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short je L_0616
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    cmp rax, -1
    long jne L_0747
L_0616:
    mov rax, qword ptr [rbp + 0x50]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1e8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x218]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x150], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x218]
    add rax, -8
    mov rdx, 0xffffffffffffffff
    add rdx, qword ptr [rax]
    mov qword ptr [rbp + 0x158], rdx
    mov rax, qword ptr [rbp + 0x150]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x158]
    mov rdx, qword ptr [rbp + 0x150]
    modrm cmp rax, rdx
    long jl L_0747
L_0698:
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f0]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0x40]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x1f8]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x160], rax
    mov rax, qword ptr [rbp + 0x160]
    test rax, rax
    short je L_06fd
    mov rax, qword ptr [rbp + 0x160]
    cmp rax, -1
    short jne L_0726
L_06fd:
    mov rax, qword ptr [rbp + 0xa8]
    test rax, rax
    short jle L_0726
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov qword ptr [rax], 1
L_0726:
    mov eax, 1
    add rax, qword ptr [rbp + 0x40]
    mov qword ptr [rbp + 0x40], rax
    mov rax, qword ptr [rbp + 0x40]
    mov rdx, qword ptr [rbp + 0x158]
    modrm cmp rax, rdx
    long jle L_0698
L_0747:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x108]
    modrm cmp rax, rdx
    long jle L_05c1
L_0768:
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x130], rax
    mov qword ptr [rbp + 0xa8], 1
    mov rax, qword ptr [rbp + 0x130]
    test rax, rax
    short jle L_07f6
L_0790:
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short jne L_07d0
    mov rax, qword ptr [rbp + 0x88]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rdx, qword ptr [rbp + 0xa8]
    mov qword ptr [rax], rdx
    short jmp L_0832
L_07d0:
    mov eax, 1
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, qword ptr [rbp + 0x130]
    modrm cmp rax, rdx
    short jle L_0790
L_07f6:
    mov rax, qword ptr [rbp + 0x208]
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x208]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x208]
    mov rdx, qword ptr [rbp + 0x88]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x210]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
L_0832:
    mov eax, 1
    add rax, qword ptr [rbp + 0x88]
    mov qword ptr [rbp + 0x88], rax
    mov rax, qword ptr [rbp + 0x88]
    mov rdx, qword ptr [rbp + 0x80]
    modrm cmp rax, rdx
    long jle L_04c6
L_085c:
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    test rax, rax
    long jle L_0b5f
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xa0], rax
    mov qword ptr [rbp + 0xa8], 1
    mov rax, qword ptr [rbp + 0xa0]
    test rax, rax
    short jle L_08da
L_0897:
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov qword ptr [rax], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, qword ptr [rbp + 0xa0]
    modrm cmp rax, rdx
    short jle L_0897
L_08da:
    mov rax, qword ptr [rbp + 0x1d8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xb8], rax
    mov qword ptr [rbp + 0xc0], 1
    mov rax, qword ptr [rbp + 0xb8]
    test rax, rax
    long jle L_09a9
L_0906:
    mov rax, qword ptr [rbp + 0xc0]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rax, qword ptr [rax]
    test rax, rax
    short jle L_097f
    mov rax, qword ptr [rbp + 0xc0]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0xc0]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov qword ptr [rax], rdx
L_097f:
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0xb8]
    modrm cmp rax, rdx
    long jle L_0906
L_09a9:
    mov qword ptr [rbp + 0x110], 1
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x118], rax
    mov qword ptr [rbp + 0xa8], 1
    mov rax, qword ptr [rbp + 0x118]
    test rax, rax
    long jle L_0a86
L_09e0:
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x110]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x110]
    imul rdx, rdx, 8
    add rdx, qword ptr [rbp + 0x200]
    add rdx, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rdx], rax
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x220]
    add rax, -8
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp + 0x110]
    inc rax
    mov qword ptr [rbp + 0x110], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0xa8]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0xa8]
    mov rdx, qword ptr [rbp + 0x118]
    modrm cmp rax, rdx
    long jle L_09e0
L_0a86:
    mov rax, qword ptr [rbp + 0x1d8]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x138], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x138]
    test rax, rax
    long jle L_0b5f
L_0aaf:
    mov rax, qword ptr [rbp + 0x20]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x210]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xa8], rax
    mov rax, qword ptr [rbp + 0xa8]
    test rax, rax
    short jle L_0b3e
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0xa8]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x228]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x200]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x20]
    mov qword ptr [rax], rdx
L_0b3e:
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x138]
    modrm cmp rax, rdx
    long jle L_0aaf
L_0b5f:
    mov rax, qword ptr [rip + reloc(U3_SUP2, 0x80)]
    cmp rax, 3
    short jl L_0bde
    mov qword ptr [rbp + 0xc8], 0
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0xf8], rax
    lea rax, [rbp + 0xc8]
    mov edx, dword ptr [rip + reloc(U3_SUP2, 0x88)]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_3 - .rdata)]
    lea rsi, [rbp + 0xf8]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rip + reloc(.data, U3_KPR$format_pack - .data)]
    add rsi, 0x70
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x180], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x180]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_fmt)
L_0bde:
    mov rax, qword ptr [rip + reloc(U3_SUP2, 0x80)]
    cmp rax, 4
    long jl L_0deb
    mov qword ptr [rbp + 0x120], 1
    mov rax, qword ptr [rbp + 0x208]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x128], rax
    mov qword ptr [rbp + 0x20], 1
    mov rax, qword ptr [rbp + 0x128]
    test rax, rax
    long jle L_0deb
L_0c23:
    mov rax, qword ptr [rbp + 0x120]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x200]
    add rax, -8
    mov rax, qword ptr [rax]
    add rax, qword ptr [rbp + 0x120]
    mov qword ptr [rbp + 0x140], rax
    mov qword ptr [rbp + 0xc8], 0
    mov rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x148], rax
    lea rax, [rbp + 0xc8]
    mov edx, dword ptr [rip + reloc(U3_SUP2, 0x88)]
    mov rcx, 0x801208384ff00
    lea rbx, [rip + reloc(.rdata, __STRLITPACK_4 - .rdata)]
    lea rsi, [rbp + 0x148]
    mov qword ptr [rsp + 0x20], rsi
    lea rsi, [rip + reloc(.data, U3_KPR$format_pack - .data)]
    mov qword ptr [rsp + 0x28], rsi
    mov qword ptr [rbp + 0x188], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x188]
    mov r8, rax
    mov r9, rbx
    call reloc(for_write_seq_fmt)
    lea rax, [rbp + 0xc8]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_5 - .rdata)]
    mov ecx, 0
    mov qword ptr [rbp + 0x190], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x190]
    mov r8, rax
    call reloc(for_write_seq_fmt_xmit)
    mov rax, qword ptr [rbp + 0x140]
    mov qword ptr [rbp + 0x168], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x120]
    mov qword ptr [rbp + 0xc0], rax
    mov rax, qword ptr [rbp + 0x168]
    mov edx, 1
    add rdx, qword ptr [rbp + 0x120]
    modrm cmp rax, rdx
    short jl L_0d8b
L_0d17:
    mov rax, qword ptr [rbp + 0xc0]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x200]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x170], rax
    lea rax, [rbp + 0xc8]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_6 - .rdata)]
    lea rcx, [rbp + 0x170]
    mov qword ptr [rbp + 0x198], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x198]
    mov r8, rax
    call reloc(for_write_seq_fmt_xmit)
    mov eax, 1
    add rax, qword ptr [rbp + 0xc0]
    mov qword ptr [rbp + 0xc0], rax
    mov rax, qword ptr [rbp + 0xc0]
    mov rdx, qword ptr [rbp + 0x168]
    modrm cmp rax, rdx
    short jle L_0d17
L_0d8b:
    lea rax, [rbp + 0xc8]
    lea rdx, [rip + reloc(.rdata, __STRLITPACK_7 - .rdata)]
    mov ecx, 0
    mov qword ptr [rbp + 0x1a0], rcx
    mov rcx, rax
    mov rax, qword ptr [rbp + 0x1a0]
    mov r8, rax
    call reloc(for_write_seq_fmt_xmit)
    mov eax, 1
    add rax, qword ptr [rbp + 0x140]
    mov qword ptr [rbp + 0x120], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x20]
    mov qword ptr [rbp + 0x20], rax
    mov rax, qword ptr [rbp + 0x20]
    mov rdx, qword ptr [rbp + 0x128]
    modrm cmp rax, rdx
    long jle L_0c23
L_0deb:
    mov rbx, qword ptr [rbp + 0x1a8]
    mov rsi, qword ptr [rbp + 0x1b0]
    lea rsp, [rbp + 0x1c0]
    pop rbp
    ret
end_U3_KPR:

U3_BKSORT:
    push rbp
pro_U3_BKSORT_01:
    sub rsp, 0x70
pro_U3_BKSORT_05:
    lea rbp, [rsp + 0x20]
pro_U3_BKSORT_0a:
    mov qword ptr [rbp + 0x60], rcx
    mov qword ptr [rbp + 0x68], rdx
    mov qword ptr [rbp + 0x70], r8
    mov qword ptr [rbp + 0x78], r9
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 8], rax
    mov rax, qword ptr [rbp + 0x60]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x10], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x10]
    test rax, rax
    short jle L_0e82
L_0e4e:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov qword ptr [rax], 0
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x10]
    modrm cmp rax, rdx
    short jle L_0e4e
L_0e82:
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x20], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x20]
    test rax, rax
    short jle L_0f00
L_0e9e:
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x70]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x20]
    modrm cmp rax, rdx
    short jle L_0e9e
L_0f00:
    mov qword ptr [rbp + 0x30], 1
    mov rax, qword ptr [rbp + 0x60]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x38], rax
    mov qword ptr [rbp + 0x18], 1
    mov rax, qword ptr [rbp + 0x38]
    test rax, rax
    short jle L_0f7e
L_0f24:
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x48], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x30]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x48]
    add rax, qword ptr [rbp + 0x30]
    mov qword ptr [rbp + 0x30], rax
    mov eax, 1
    add rax, qword ptr [rbp + 0x18]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    mov rdx, qword ptr [rbp + 0x38]
    modrm cmp rax, rdx
    short jle L_0f24
L_0f7e:
    mov rax, qword ptr [rbp + 0x68]
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x40], rax
    mov qword ptr [rbp + 0x28], 1
    mov rax, qword ptr [rbp + 0x40]
    test rax, rax
    long jle L_102d
L_0f9e:
    mov rax, qword ptr [rbp + 0x28]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x70]
    add rax, -8
    mov rax, qword ptr [rax]
    mov qword ptr [rbp + 0x18], rax
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov rax, qword ptr [rax]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x78]
    add rax, -8
    mov rdx, qword ptr [rbp + 0x28]
    mov qword ptr [rax], rdx
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov edx, 1
    add rdx, qword ptr [rax]
    mov rax, qword ptr [rbp + 0x18]
    imul rax, rax, 8
    add rax, qword ptr [rbp + 0x80]
    add rax, -8
    mov qword ptr [rax], rdx
    mov eax, 1
    add rax, qword ptr [rbp + 0x28]
    mov qword ptr [rbp + 0x28], rax
    mov rax, qword ptr [rbp + 0x28]
    mov rdx, qword ptr [rbp + 0x40]
    modrm cmp rax, rdx
    long jle L_0f9e
L_102d:
    lea rsp, [rbp + 0x50]
    pop rbp
    ret
end_U3_BKSORT:
    nop

.section .rdata 0x40300040
__STRLITPACK_3:
    .byte 0x0b, 0x01, 0x01
    .zero 5
__STRLITPACK_4:
    .byte 0x0b, 0x01, 0x02
    .zero 5
__STRLITPACK_5:
    .byte 0x02, 0x00, 0x02, 0x00
__STRLITPACK_6:
    .byte 0x0b, 0x01, 0x02
    .zero 5
__STRLITPACK_7:
    .byte 0x01, 0x00, 0x02, 0x00

.section .data 0xc0600040
U3_KPR$format_pack:
    .byte 0x36
    .zero 3
    .byte 0x1c, 0x00, 0x0d, 0x00
    .ascii " KPR-I-Group "
    .zero 3
    .byte 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x03
    .zero 3
    .byte 0x1c, 0x00, 0x0d, 0x00
    .ascii " : Variables "
    .zero 3
    .byte 0x38, 0x00, 0x01, 0x00, 0x0c
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x1e
    .zero 3
    .byte 0x38, 0x00, 0x0a, 0x00, 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x06
    .zero 3
    .byte 0x0e
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x39
    .zero 3
    .byte 0x39
    .zero 3
    .byte 0x37
    .zero 3
    .byte 0x36
    .zero 3
    .byte 0x1c, 0x00, 0x23, 0x00
    .ascii " KPR-I-Number of groups detected = "
    .byte 0x00, 0x24
    .zero 3
    .byte 0x01
    .zero 3
    .byte 0x03
    .zero 3
    .byte 0x37
    .zero 23

.section .xdata 0x40300040
unwind_U3_KPR:
    .unwind U3_KPR, pro_U3_KPR_1b, rbp, 48
        .save_nonvol pro_U3_KPR_1b, rbx, 472
        .save_nonvol pro_U3_KPR_14, rsi, 480
        .set_fpreg pro_U3_KPR_0d
        .alloc_large pro_U3_KPR_08, 496
        .push_nonvol pro_U3_KPR_01, rbp
    .endunwind
unwind_U3_BKSORT:
    .unwind U3_BKSORT, pro_U3_BKSORT_0a, rbp, 32
        .set_fpreg pro_U3_BKSORT_0a
        .alloc_small pro_U3_BKSORT_05, 112
        .push_nonvol pro_U3_BKSORT_01, rbp
    .endunwind

.section .pdata 0x40300040
    .rva U3_KPR
    .rva U3_KPR, end_U3_KPR - U3_KPR
    .rva .xdata, unwind_U3_KPR - .xdata
    .rva U3_BKSORT
    .rva U3_BKSORT, end_U3_BKSORT - U3_BKSORT
    .rva .xdata, unwind_U3_BKSORT - .xdata

.section .drectve 0x00100a00
    .ascii "-export:U3_KPR  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "
