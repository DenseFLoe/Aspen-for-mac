#include "s5-registers.h"

/* 0x14884..0x14957, Windows AMD64. */
NAKED void internal_14884(void) {
    __asm__(START
        ".Ls5_14884:\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "sub rsp, 0x38\n"
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_15090]\n"
        "test eax, eax\n"
        "je .Ls5_148a3\n"
        "mov ecx, 2\n"
        "int 0x29\n"
        ".Ls5_148a3:\n"
        "lea rcx, [rip + rva_21a90]\n"
        "call rva_14b8c\n"
        "mov rax, qword ptr [rsp + 0x38]\n"
        "mov qword ptr [rip + rva_21b88], rax\n"
        "lea rax, [rsp + 0x38]\n"
        "add rax, 8\n"
        "mov qword ptr [rip + rva_21b28], rax\n"
        "mov rax, qword ptr [rip + rva_21b88]\n"
        "mov qword ptr [rip + rva_21a00], rax\n"
        "mov rax, qword ptr [rsp + 0x40]\n"
        "mov qword ptr [rip + rva_21b10], rax\n"
        "mov dword ptr [rip + rva_219f0], 0xc0000409\n"
        "mov dword ptr [rip + rva_219f4], 1\n"
        "mov dword ptr [rip + rva_21a08], 1\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "lea rcx, [rip + rva_21a10]\n"
        "mov qword ptr [rcx + rax], 2\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "mov rcx, qword ptr [rip + rva_1e800]\n"
        "mov qword ptr [rsp + rax + 0x20], rcx\n"
        "mov eax, 8\n"
        "imul rax, rax, 1\n"
        "mov rcx, qword ptr [rip + rva_1e840]\n"
        "mov qword ptr [rsp + rax + 0x20], rcx\n"
        "lea rcx, [rip + rva_19938]\n"
        "call rva_14850\n"
        ".byte 0x90 # alignment nop\n"
        "add rsp, 0x38\n"
        "ret\n" END);
}

/* 0x14958..0x1496c, Windows AMD64. */
NAKED void internal_14958(void) {
    __asm__(START
        ".Ls5_14958:\n"
        "sub rsp, 0x28\n"
        "mov ecx, 8\n"
        "call rva_1496c\n"
        ".byte 0x90 # alignment nop\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x1496c..0x14a09, Windows AMD64. */
NAKED void internal_1496c(void) {
    __asm__(START
        ".Ls5_1496c:\n"
        "mov dword ptr [rsp + 8], ecx\n"
        "sub rsp, 0x28\n"
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_15090]\n"
        "test eax, eax\n"
        "je .Ls5_1498b\n"
        "mov eax, dword ptr [rsp + 0x30]\n"
        S5_MOV32(ecx, eax)
        "int 0x29\n"
        ".Ls5_1498b:\n"
        "lea rcx, [rip + rva_21a90]\n"
        "call rva_14b1c\n"
        "mov rax, qword ptr [rsp + 0x28]\n"
        "mov qword ptr [rip + rva_21b88], rax\n"
        "lea rax, [rsp + 0x28]\n"
        "add rax, 8\n"
        "mov qword ptr [rip + rva_21b28], rax\n"
        "mov rax, qword ptr [rip + rva_21b88]\n"
        "mov qword ptr [rip + rva_21a00], rax\n"
        "mov dword ptr [rip + rva_219f0], 0xc0000409\n"
        "mov dword ptr [rip + rva_219f4], 1\n"
        "mov dword ptr [rip + rva_21a08], 1\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "lea rcx, [rip + rva_21a10]\n"
        "mov edx, dword ptr [rsp + 0x30]\n"
        "mov qword ptr [rcx + rax], rdx\n"
        "lea rcx, [rip + rva_19938]\n"
        "call rva_14850\n"
        ".byte 0x90 # alignment nop\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x14a0c..0x14b1c, Windows AMD64. */
NAKED void internal_14a0c(void) {
    __asm__(START
        ".Ls5_14a0c:\n"
        "mov qword ptr [rsp + 0x18], r8\n"
        "mov dword ptr [rsp + 0x10], edx\n"
        "mov dword ptr [rsp + 8], ecx\n"
        "sub rsp, 0x38\n"
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_15090]\n"
        "test eax, eax\n"
        "je .Ls5_14a34\n"
        "mov eax, dword ptr [rsp + 0x40]\n"
        S5_MOV32(ecx, eax)
        "int 0x29\n"
        ".Ls5_14a34:\n"
        "lea rcx, [rip + rva_21a90]\n"
        "call rva_14b1c\n"
        "mov rax, qword ptr [rsp + 0x38]\n"
        "mov qword ptr [rip + rva_21b88], rax\n"
        "lea rax, [rsp + 0x38]\n"
        "add rax, 8\n"
        "mov qword ptr [rip + rva_21b28], rax\n"
        "mov rax, qword ptr [rip + rva_21b88]\n"
        "mov qword ptr [rip + rva_21a00], rax\n"
        "mov dword ptr [rip + rva_219f0], 0xc0000409\n"
        "mov dword ptr [rip + rva_219f4], 1\n"
        "cmp dword ptr [rsp + 0x48], 0\n"
        "jbe .Ls5_14a95\n"
        "cmp qword ptr [rsp + 0x50], 0\n"
        "jne .Ls5_14a95\n"
        "mov dword ptr [rsp + 0x48], 0\n"
        ".Ls5_14a95:\n"
        "cmp dword ptr [rsp + 0x48], 0xe\n"
        "jbe .Ls5_14aa6\n"
        "mov eax, dword ptr [rsp + 0x48]\n"
        "dec eax\n"
        "mov dword ptr [rsp + 0x48], eax\n"
        ".Ls5_14aa6:\n"
        "mov eax, dword ptr [rsp + 0x48]\n"
        "inc eax\n"
        "mov dword ptr [rip + rva_21a08], eax\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "lea rcx, [rip + rva_21a10]\n"
        "mov edx, dword ptr [rsp + 0x40]\n"
        "mov qword ptr [rcx + rax], rdx\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "jmp .Ls5_14ade\n"
        ".Ls5_14ad4:\n"
        "mov eax, dword ptr [rsp + 0x20]\n"
        "inc eax\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        ".Ls5_14ade:\n"
        "mov eax, dword ptr [rsp + 0x48]\n"
        "cmp dword ptr [rsp + 0x20], eax\n"
        "jae .Ls5_14b0a\n"
        "mov eax, dword ptr [rsp + 0x20]\n"
        "mov ecx, dword ptr [rsp + 0x20]\n"
        "inc ecx\n"
        S5_MOV32(ecx, ecx)
        "lea rdx, [rip + rva_21a10]\n"
        "mov r8, qword ptr [rsp + 0x50]\n"
        "mov rax, qword ptr [r8 + rax*8]\n"
        "mov qword ptr [rdx + rcx*8], rax\n"
        "jmp .Ls5_14ad4\n"
        ".Ls5_14b0a:\n"
        "lea rcx, [rip + rva_19938]\n"
        "call rva_14850\n"
        ".byte 0x90 # alignment nop\n"
        "add rsp, 0x38\n"
        "ret\n" END);
}

/* 0x14b1c..0x14b89, Windows AMD64. */
NAKED void internal_14b1c(void) {
    __asm__(START
        ".Ls5_14b1c:\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        S5_MOV64(rbx, rcx)
        "call qword ptr [rip + rva_15058]\n"
        "mov rdi, qword ptr [rbx + 0xf8]\n"
        "lea rdx, [rsp + 0x50]\n"
        S5_MOV64(rcx, rdi)
        S5_XOR32(r8d, r8d)
        "call qword ptr [rip + rva_15060]\n"
        "test rax, rax\n"
        "je .Ls5_14b7e\n"
        "and qword ptr [rsp + 0x38], 0\n"
        "lea rcx, [rsp + 0x58]\n"
        "mov rdx, qword ptr [rsp + 0x50]\n"
        S5_MOV64(r9, rax)
        "mov qword ptr [rsp + 0x30], rcx\n"
        S5_MOV64(r8, rdi)
        "lea rcx, [rsp + 0x60]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        S5_XOR32(ecx, ecx)
        "mov qword ptr [rsp + 0x20], rbx\n"
        "call qword ptr [rip + rva_15068]\n"
        ".Ls5_14b7e:\n"
        "mov rbx, qword ptr [rsp + 0x68]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n" END);
}

/* 0x14b8c..0x14bfd, Windows AMD64. */
NAKED void internal_14b8c(void) {
    __asm__(START
        ".Ls5_14b8c:\n"
        ".byte 0x40\npush rbx\n"
        "push rsi\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        S5_MOV64(rbx, rcx)
        "call qword ptr [rip + rva_15058]\n"
        "mov rsi, qword ptr [rbx + 0xf8]\n"
        S5_XOR32(edi, edi)
        ".Ls5_14ba6:\n"
        S5_XOR32(r8d, r8d)
        "lea rdx, [rsp + 0x60]\n"
        S5_MOV64(rcx, rsi)
        "call qword ptr [rip + rva_15060]\n"
        "test rax, rax\n"
        "je .Ls5_14bf5\n"
        "and qword ptr [rsp + 0x38], 0\n"
        "lea rcx, [rsp + 0x68]\n"
        "mov rdx, qword ptr [rsp + 0x60]\n"
        S5_MOV64(r9, rax)
        "mov qword ptr [rsp + 0x30], rcx\n"
        S5_MOV64(r8, rsi)
        "lea rcx, [rsp + 0x70]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        S5_XOR32(ecx, ecx)
        "mov qword ptr [rsp + 0x20], rbx\n"
        "call qword ptr [rip + rva_15068]\n"
        "inc edi\n"
        "cmp edi, 2\n"
        "jl .Ls5_14ba6\n"
        ".Ls5_14bf5:\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n" END);
}

/* 0x14bfd..0x14c03, Windows AMD64. */
NAKED void internal_14bfd(void) {
    __asm__(START
        ".Ls5_14bfd:\n"
        "jmp qword ptr [rip + rva_15018]\n" END);
}

/* 0x14c03..0x14c09, Windows AMD64. */
NAKED void internal_14c03(void) {
    __asm__(START
        ".Ls5_14c03:\n"
        "jmp qword ptr [rip + rva_15000]\n" END);
}

/* 0x14c0c..0x14c0f, Windows AMD64. */
NAKED void internal_14c0c(void) {
    __asm__(START
        ".Ls5_14c0c:\n"
        "mov al, 1\n"
        "ret\n" END);
}

/* 0x14c10..0x14c13, Windows AMD64. */
NAKED void internal_14c10(void) {
    __asm__(START
        ".Ls5_14c10:\n"
        "mov al, 1\n"
        "ret\n" END);
}

/* 0x14c14..0x14c17, Windows AMD64. */
NAKED void internal_14c14(void) {
    __asm__(START
        ".Ls5_14c14:\n"
        "mov al, 1\n"
        "ret\n" END);
}

/* 0x14c18..0x14c1b, Windows AMD64. */
NAKED void internal_14c18(void) {
    __asm__(START
        ".Ls5_14c18:\n"
        "mov al, 1\n"
        "ret\n" END);
}

/* 0x14c1c..0x14c1f, Windows AMD64. */
NAKED void internal_14c1c(void) {
    __asm__(START
        ".Ls5_14c1c:\n"
        "mov al, 1\n"
        "ret\n" END);
}

/* 0x14c20..0x14c23, Windows AMD64. */
NAKED void internal_14c20(void) {
    __asm__(START
        ".Ls5_14c20:\n"
        S5_XOR32(eax, eax)
        "ret\n" END);
}

/* 0x14c40..0x14c42, Windows AMD64. */
NAKED void internal_14c40(void) {
    __asm__(START
        ".Ls5_14c40:\n"
        "jmp rax\n" END);
}

/* 0x14c60..0x14c66, Windows AMD64. */
NAKED void internal_14c60(void) {
    __asm__(START
        ".Ls5_14c60:\n"
        "jmp qword ptr [rip + rva_15d00]\n" END);
}

/* 0x14c70..0x14cc6, Windows AMD64. */
NAKED void internal_14c70(void) {
    __asm__(START
        ".Ls5_14c70:\n"
        "push rsi\n"
        "sub rsp, 0x40\n"
        "mov rax, rdx\n"
        "lea rdx, [rsp + 0x60]\n"
        "mov qword ptr [rdx], r8\n"
        "mov qword ptr [rdx + 8], r9\n"
        "mov r8, qword ptr [rip + rva_1e800]\n"
        "xor r8, rsp\n"
        "mov qword ptr [rsp + 0x38], r8\n"
        "mov qword ptr [rsp + 0x30], rdx\n"
        "mov qword ptr [rsp + 0x20], rdx\n"
        "mov rdx, 0xffffffffffffffff\n"
        "mov r8, rax\n"
        "xor r9d, r9d\n"
        "call rva_14d40\n"
        "mov esi, eax\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "xor rcx, rsp\n"
        "call rva_14830\n"
        "mov eax, esi\n"
        "add rsp, 0x40\n"
        "pop rsi\n"
        "ret\n" END);
}

/* 0x14cd0..0x14d3f, Windows AMD64. */
NAKED void internal_14cd0(void) {
    __asm__(START
        ".Ls5_14cd0:\n"
        "push rsi\n"
        "push rdi\n"
        "push rbx\n"
        "sub rsp, 0x40\n"
        "mov rsi, rcx\n"
        "lea rbx, [rsp + 0x68]\n"
        "mov qword ptr [rbx], rdx\n"
        "mov qword ptr [rbx + 8], r8\n"
        "mov qword ptr [rbx + 0x10], r9\n"
        "mov rax, qword ptr [rip + rva_1e800]\n"
        "xor rax, rsp\n"
        "mov qword ptr [rsp + 0x38], rax\n"
        "mov qword ptr [rsp + 0x30], rbx\n"
        "mov ecx, 1\n"
        "call rva_14806\n"
        "mov rdi, rax\n"
        "call rva_11ff0\n"
        "mov rcx, qword ptr [rax]\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "mov rdx, rdi\n"
        "mov r8, rsi\n"
        "xor r9d, r9d\n"
        "call rva_1480c\n"
        "mov esi, eax\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "xor rcx, rsp\n"
        "call rva_14830\n"
        "mov eax, esi\n"
        "add rsp, 0x40\n"
        "pop rbx\n"
        "pop rdi\n"
        "pop rsi\n"
        "ret\n" END);
}

/* 0x14d40..0x14d99, Windows AMD64. */
NAKED void internal_14d40(void) {
    __asm__(START
        ".Ls5_14d40:\n"
        "push r15\n"
        "push r14\n"
        "push rsi\n"
        "push rdi\n"
        "push rbx\n"
        "sub rsp, 0x30\n"
        "mov rsi, r9\n"
        "mov rdi, r8\n"
        "mov rbx, rdx\n"
        "mov r14, rcx\n"
        "mov r15, qword ptr [rsp + 0x80]\n"
        "call rva_11ff0\n"
        "mov rcx, qword ptr [rax]\n"
        "or rcx, 1\n"
        "mov qword ptr [rsp + 0x28], r15\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "mov rdx, r14\n"
        "mov r8, rbx\n"
        "mov r9, rdi\n"
        "call rva_147f4\n"
        "test eax, eax\n"
        "mov ecx, 0xffffffff\n"
        "cmovs eax, ecx\n"
        "add rsp, 0x30\n"
        "pop rbx\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop r14\n"
        "pop r15\n"
        "ret\n" END);
}

/* 0x14d99..0x14db0, Windows AMD64. */
NAKED void internal_14d99(void) {
    __asm__(START
        ".Ls5_14d99:\n"
        ".byte 0x40\npush rbp\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rbp, rdx)
        "mov cl, byte ptr [rbp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "jmp rva_1238c\n"
        "int3\n" END);
}

/* 0x14db0..0x14dc9, Windows AMD64. */
NAKED void internal_14db0(void) {
    __asm__(START
        ".Ls5_14db0:\n"
        ".byte 0x40\npush rbp\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rbp, rdx)
        "mov cl, byte ptr [rbp + 0x20]\n"
        "call rva_1238c\n"
        ".byte 0x90 # alignment nop\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        "int3\n" END);
}

/* 0x14dc9..0x14ddd, Windows AMD64. */
NAKED void internal_14dc9(void) {
    __asm__(START
        ".Ls5_14dc9:\n"
        ".byte 0x40\npush rbp\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rbp, rdx)
        "add rsp, 0x20\n"
        "pop rbp\n"
        "jmp rva_12218\n"
        "int3\n" END);
}

/* 0x14ddd..0x14e13, Windows AMD64. */
NAKED void internal_14ddd(void) {
    __asm__(START
        ".Ls5_14ddd:\n"
        ".byte 0x40\npush rbp\n"
        "sub rsp, 0x30\n"
        S5_MOV64(rbp, rdx)
        "mov rax, qword ptr [rcx]\n"
        "mov edx, dword ptr [rax]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "mov dword ptr [rsp + 0x20], edx\n"
        "lea r9, [rip + rva_11b24]\n"
        "mov r8, qword ptr [rbp + 0x70]\n"
        "mov edx, dword ptr [rbp + 0x68]\n"
        "mov rcx, qword ptr [rbp + 0x60]\n"
        "call rva_12188\n"
        ".byte 0x90 # alignment nop\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        "int3\n" END);
}

/* 0x14e13..0x14e2b, Windows AMD64. */
NAKED void internal_14e13(void) {
    __asm__(START
        ".Ls5_14e13:\n"
        ".byte 0x40\npush rbp\n"
        S5_MOV64(rbp, rdx)
        "mov rax, qword ptr [rcx]\n"
        S5_XOR32(ecx, ecx)
        "cmp dword ptr [rax], 0xc0000005\n"
        "sete cl\n"
        S5_MOV32(eax, ecx)
        "pop rbp\n"
        "ret\n"
        "int3\n" END);
}
