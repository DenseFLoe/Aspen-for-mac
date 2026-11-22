#include "s5-registers.h"

/* 0x12188..0x121e8, Windows AMD64. */
NAKED void internal_12188(void) {
    __asm__(START
        ".Ls5_12188:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rbp\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rdi, r9)
        S5_MOV64(rsi, r8)
        S5_MOV32(ebx, edx)
        S5_MOV64(rbp, rcx)
        "call rva_12c64\n"
        "test eax, eax\n"
        "jne .Ls5_121c6\n"
        "cmp ebx, 1\n"
        "jne .Ls5_121c6\n"
        S5_MOV64(r8, rsi)
        S5_XOR32(edx, edx)
        S5_MOV64(rcx, rbp)
        S5_MOV64(rax, rdi)
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_121c6:\n"
        "mov rdx, qword ptr [rsp + 0x58]\n"
        "mov ecx, dword ptr [rsp + 0x50]\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rbp, qword ptr [rsp + 0x38]\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "jmp rva_147ac\n" END);
}

/* 0x121e8..0x12218, Windows AMD64. */
NAKED void internal_121e8(void) {
    __asm__(START
        ".Ls5_121e8:\n"
        "sub rsp, 0x28\n"
        "call rva_12c64\n"
        "test eax, eax\n"
        "je .Ls5_12205\n"
        "lea rcx, [rip + rva_20a48]\n"
        "add rsp, 0x28\n"
        "jmp rva_147ca\n"
        ".Ls5_12205:\n"
        "call rva_14c20\n"
        "test eax, eax\n"
        "jne .Ls5_12213\n"
        "call rva_147dc\n"
        ".Ls5_12213:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12218..0x1222c, Windows AMD64. */
NAKED void internal_12218(void) {
    __asm__(START
        ".Ls5_12218:\n"
        "sub rsp, 0x28\n"
        S5_XOR32(ecx, ecx)
        "call rva_14c1c\n"
        "add rsp, 0x28\n"
        "jmp rva_14c1c\n" END);
}

/* 0x1222c..0x12266, Windows AMD64. */
NAKED void internal_1222c(void) {
    __asm__(START
        ".Ls5_1222c:\n"
        "sub rsp, 0x28\n"
        "test ecx, ecx\n"
        "jne .Ls5_1223b\n"
        "mov byte ptr [rip + rva_20a40], 1\n"
        ".Ls5_1223b:\n"
        "call rva_12990\n"
        "call rva_14c0c\n"
        "test al, al\n"
        "jne .Ls5_1224d\n"
        ".Ls5_12249:\n"
        S5_XOR8(al, al)
        "jmp .Ls5_12261\n"
        ".Ls5_1224d:\n"
        "call rva_14c0c\n"
        "test al, al\n"
        "jne .Ls5_1225f\n"
        S5_XOR32(ecx, ecx)
        "call rva_14c18\n"
        "jmp .Ls5_12249\n"
        ".Ls5_1225f:\n"
        "mov al, 1\n"
        ".Ls5_12261:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12268..0x122f3, Windows AMD64. */
NAKED void internal_12268(void) {
    __asm__(START
        ".Ls5_12268:\n"
        ".byte 0x40\npush rbx\n"
        "sub rsp, 0x20\n"
        "cmp byte ptr [rip + rva_20a41], 0\n"
        S5_MOV32(ebx, ecx)
        "jne .Ls5_122e0\n"
        "cmp ecx, 1\n"
        "ja .Ls5_122e8\n"
        "call rva_12c64\n"
        "test eax, eax\n"
        "je .Ls5_122af\n"
        "test ebx, ebx\n"
        "jne .Ls5_122af\n"
        "lea rcx, [rip + rva_20a48]\n"
        "call rva_147be\n"
        "test eax, eax\n"
        "jne .Ls5_122ab\n"
        "lea rcx, [rip + rva_20a60]\n"
        "call rva_147be\n"
        "test eax, eax\n"
        "je .Ls5_122d9\n"
        ".Ls5_122ab:\n"
        S5_XOR8(al, al)
        "jmp .Ls5_122e2\n"
        ".Ls5_122af:\n"
        "movdqa xmm0, xmmword ptr [rip + rva_17c60]\n"
        "or rax, 0xffffffffffffffff\n"
        "movdqu xmmword ptr [rip + rva_20a48], xmm0\n"
        "mov qword ptr [rip + rva_20a58], rax\n"
        "movdqu xmmword ptr [rip + rva_20a60], xmm0\n"
        "mov qword ptr [rip + rva_20a70], rax\n"
        ".Ls5_122d9:\n"
        "mov byte ptr [rip + rva_20a41], 1\n"
        ".Ls5_122e0:\n"
        "mov al, 1\n"
        ".Ls5_122e2:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        ".Ls5_122e8:\n"
        "mov ecx, 5\n"
        "call rva_12460\n"
        "int3\n" END);
}

/* 0x122f4..0x1238c, Windows AMD64. */
NAKED void internal_122f4(void) {
    __asm__(START
        ".Ls5_122f4:\n"
        "sub rsp, 0x18\n"
        S5_MOV64(r8, rcx)
        "mov eax, 0x5a4d\n"
        "cmp word ptr [rip + rva_0], ax\n"
        "jne .Ls5_12381\n"
        "movsxd rcx, dword ptr [rip + rva_3c]\n"
        "lea rdx, [rip + rva_0]\n"
        S5_ADD64(rcx, rdx)
        "cmp dword ptr [rcx], 0x4550\n"
        "jne .Ls5_12381\n"
        "mov eax, 0x20b\n"
        "cmp word ptr [rcx + 0x18], ax\n"
        "jne .Ls5_12381\n"
        S5_SUB64(r8, rdx)
        "movzx edx, word ptr [rcx + 0x14]\n"
        "add rdx, 0x18\n"
        S5_ADD64(rdx, rcx)
        "movzx eax, word ptr [rcx + 6]\n"
        "lea rcx, [rax + rax*4]\n"
        "lea r9, [rdx + rcx*8]\n"
        ".Ls5_12347:\n"
        "mov qword ptr [rsp], rdx\n"
        S5_CMP64(rdx, r9)
        "je .Ls5_12368\n"
        "mov ecx, dword ptr [rdx + 0xc]\n"
        S5_CMP64(r8, rcx)
        "jb .Ls5_12362\n"
        "mov eax, dword ptr [rdx + 8]\n"
        S5_ADD32(eax, ecx)
        S5_CMP64(r8, rax)
        "jb .Ls5_1236a\n"
        ".Ls5_12362:\n"
        "add rdx, 0x28\n"
        "jmp .Ls5_12347\n"
        ".Ls5_12368:\n"
        S5_XOR32(edx, edx)
        ".Ls5_1236a:\n"
        "test rdx, rdx\n"
        "jne .Ls5_12373\n"
        S5_XOR8(al, al)
        "jmp .Ls5_12387\n"
        ".Ls5_12373:\n"
        "cmp dword ptr [rdx + 0x24], 0\n"
        "jge .Ls5_1237d\n"
        S5_XOR8(al, al)
        "jmp .Ls5_12387\n"
        ".Ls5_1237d:\n"
        "mov al, 1\n"
        "jmp .Ls5_12387\n"
        ".Ls5_12381:\n"
        S5_XOR8(al, al)
        "jmp .Ls5_12387\n"
        S5_XOR8(al, al)
        ".Ls5_12387:\n"
        "add rsp, 0x18\n"
        "ret\n" END);
}

/* 0x1238c..0x123b0, Windows AMD64. */
NAKED void internal_1238c(void) {
    __asm__(START
        ".Ls5_1238c:\n"
        ".byte 0x40\npush rbx\n"
        "sub rsp, 0x20\n"
        S5_MOV8(bl, cl)
        "call rva_12c64\n"
        S5_XOR32(edx, edx)
        "test eax, eax\n"
        "je .Ls5_123aa\n"
        "test bl, bl\n"
        "jne .Ls5_123aa\n"
        "xchg qword ptr [rip + rva_20a38], rdx\n"
        ".Ls5_123aa:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n" END);
}

/* 0x123b0..0x123d9, Windows AMD64. */
NAKED void internal_123b0(void) {
    __asm__(START
        ".Ls5_123b0:\n"
        ".byte 0x40\npush rbx\n"
        "sub rsp, 0x20\n"
        "cmp byte ptr [rip + rva_20a40], 0\n"
        S5_MOV8(bl, cl)
        "je .Ls5_123c5\n"
        "test dl, dl\n"
        "jne .Ls5_123d1\n"
        ".Ls5_123c5:\n"
        "call rva_14c18\n"
        S5_MOV8(cl, bl)
        "call rva_14c18\n"
        ".Ls5_123d1:\n"
        "mov al, 1\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n" END);
}

/* 0x123dc..0x12416, Windows AMD64. */
NAKED void internal_123dc(void) {
    __asm__(START
        ".Ls5_123dc:\n"
        ".byte 0x40\npush rbx\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [rip + rva_20a48], -1\n"
        S5_MOV64(rbx, rcx)
        "jne .Ls5_123f6\n"
        "call rva_147d0\n"
        "jmp .Ls5_12405\n"
        ".Ls5_123f6:\n"
        S5_MOV64(rdx, rbx)
        "lea rcx, [rip + rva_20a48]\n"
        "call rva_147c4\n"
        ".Ls5_12405:\n"
        S5_XOR32(edx, edx)
        "test eax, eax\n"
        "cmove rdx, rbx\n"
        S5_MOV64(rax, rdx)
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n" END);
}

/* 0x12418..0x12435, Windows AMD64. */
NAKED void internal_12418(void) {
    __asm__(START
        ".Ls5_12418:\n"
        "cmp qword ptr [rip + rva_20a60], -1\n"
        "je rva_147d6\n"
        S5_MOV64(rdx, rcx)
        "lea rcx, [rip + rva_20a60]\n"
        "jmp rva_147c4\n" END);
}

/* 0x12438..0x1244f, Windows AMD64. */
NAKED void internal_12438(void) {
    __asm__(START
        ".Ls5_12438:\n"
        "sub rsp, 0x28\n"
        "call rva_123dc\n"
        "neg rax\n"
        S5_SBB32(eax, eax)
        "neg eax\n"
        "dec eax\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12450..0x12458, Windows AMD64. */
NAKED void internal_12450(void) {
    __asm__(START
        ".Ls5_12450:\n"
        "lea rax, [rip + rva_22148]\n"
        "ret\n" END);
}

/* 0x12458..0x12460, Windows AMD64. */
NAKED void internal_12458(void) {
    __asm__(START
        ".Ls5_12458:\n"
        "and dword ptr [rip + rva_20a78], 0\n"
        "ret\n" END);
}

/* 0x12460..0x125a8, Windows AMD64. */
NAKED void internal_12460(void) {
    __asm__(START
        ".Ls5_12460:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rbp\n"
        "lea rbp, [rsp - 0x4c0]\n"
        "sub rsp, 0x5c0\n"
        S5_MOV32(ebx, ecx)
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_15090]\n"
        "test eax, eax\n"
        "je .Ls5_1248a\n"
        S5_MOV32(ecx, ebx)
        "int 0x29\n"
        ".Ls5_1248a:\n"
        "mov ecx, 3\n"
        "call rva_12458\n"
        S5_XOR32(edx, edx)
        "lea rcx, [rbp - 0x10]\n"
        "mov r8d, 0x4d0\n"
        "call rva_14794\n"
        "lea rcx, [rbp - 0x10]\n"
        "call qword ptr [rip + rva_15058]\n"
        "mov rbx, qword ptr [rbp + 0xe8]\n"
        "lea rdx, [rbp + 0x4d8]\n"
        S5_MOV64(rcx, rbx)
        S5_XOR32(r8d, r8d)
        "call qword ptr [rip + rva_15060]\n"
        "test rax, rax\n"
        "je .Ls5_1250a\n"
        "and qword ptr [rsp + 0x38], 0\n"
        "lea rcx, [rbp + 0x4e0]\n"
        "mov rdx, qword ptr [rbp + 0x4d8]\n"
        S5_MOV64(r9, rax)
        "mov qword ptr [rsp + 0x30], rcx\n"
        S5_MOV64(r8, rbx)
        "lea rcx, [rbp + 0x4e8]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "lea rcx, [rbp - 0x10]\n"
        "mov qword ptr [rsp + 0x20], rcx\n"
        S5_XOR32(ecx, ecx)
        "call qword ptr [rip + rva_15068]\n"
        ".Ls5_1250a:\n"
        "mov rax, qword ptr [rbp + 0x4c8]\n"
        "lea rcx, [rsp + 0x50]\n"
        "mov qword ptr [rbp + 0xe8], rax\n"
        S5_XOR32(edx, edx)
        "lea rax, [rbp + 0x4c8]\n"
        "mov r8d, 0x98\n"
        "add rax, 8\n"
        "mov qword ptr [rbp + 0x88], rax\n"
        "call rva_14794\n"
        "mov rax, qword ptr [rbp + 0x4c8]\n"
        "mov qword ptr [rsp + 0x60], rax\n"
        "mov dword ptr [rsp + 0x50], 0x40000015\n"
        "mov dword ptr [rsp + 0x54], 1\n"
        "call qword ptr [rip + rva_15070]\n"
        S5_MOV32(ebx, eax)
        S5_XOR32(ecx, ecx)
        "lea rax, [rsp + 0x50]\n"
        "mov qword ptr [rsp + 0x40], rax\n"
        "lea rax, [rbp - 0x10]\n"
        "mov qword ptr [rsp + 0x48], rax\n"
        "call qword ptr [rip + rva_15080]\n"
        "lea rcx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_15078]\n"
        "test eax, eax\n"
        "jne .Ls5_12597\n"
        "cmp ebx, 1\n"
        "je .Ls5_12597\n"
        "lea ecx, [rax + 3]\n"
        "call rva_12458\n"
        ".Ls5_12597:\n"
        "mov rbx, qword ptr [rsp + 0x5d0]\n"
        "add rsp, 0x5c0\n"
        "pop rbp\n"
        "ret\n" END);
}

/* 0x125a8..0x125e2, Windows AMD64. */
NAKED void internal_125a8(void) {
    __asm__(START
        ".Ls5_125a8:\n"
        "sub rsp, 0x98\n"
        S5_XOR32(edx, edx)
        "lea rcx, [rsp + 0x20]\n"
        "lea r8d, [rdx + 0x68]\n"
        "call rva_14794\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_15088]\n"
        "test byte ptr [rsp + 0x5c], 1\n"
        "mov eax, 0xa\n"
        "cmovne ax, word ptr [rsp + 0x60]\n"
        "add rsp, 0x98\n"
        "ret\n" END);
}

/* 0x125e4..0x125e9, Windows AMD64. */
NAKED void internal_125e4(void) {
    __asm__(START
        ".Ls5_125e4:\n"
        "jmp rva_12654\n" END);
}

/* 0x125ec..0x125ef, Windows AMD64. */
NAKED void internal_125ec(void) {
    __asm__(START
        ".Ls5_125ec:\n"
        S5_XOR32(eax, eax)
        "ret\n" END);
}

/* 0x125f0..0x12641, Windows AMD64. */
NAKED void internal_125f0(void) {
    __asm__(START
        ".Ls5_125f0:\n"
        "sub rsp, 0x28\n"
        S5_XOR32(ecx, ecx)
        "call qword ptr [rip + rva_15098]\n"
        "test rax, rax\n"
        "je .Ls5_1263a\n"
        "mov ecx, 0x5a4d\n"
        "cmp word ptr [rax], cx\n"
        "jne .Ls5_1263a\n"
        "movsxd rcx, dword ptr [rax + 0x3c]\n"
        S5_ADD64(rcx, rax)
        "cmp dword ptr [rcx], 0x4550\n"
        "jne .Ls5_1263a\n"
        "mov eax, 0x20b\n"
        "cmp word ptr [rcx + 0x18], ax\n"
        "jne .Ls5_1263a\n"
        "cmp dword ptr [rcx + 0x84], 0xe\n"
        "jbe .Ls5_1263a\n"
        "cmp dword ptr [rcx + 0xf8], 0\n"
        "setne al\n"
        "jmp .Ls5_1263c\n"
        ".Ls5_1263a:\n"
        S5_XOR8(al, al)
        ".Ls5_1263c:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12644..0x12652, Windows AMD64. */
NAKED void internal_12644(void) {
    __asm__(START
        ".Ls5_12644:\n"
        "lea rcx, [rip + rva_12658]\n"
        ".byte 0x48\njmp qword ptr [rip + rva_15080]\n" END);
}

/* 0x12654..0x12657, Windows AMD64. */
NAKED void internal_12654(void) {
    __asm__(START
        ".Ls5_12654:\n"
        S5_XOR32(eax, eax)
        "ret\n" END);
}

/* 0x12658..0x126b3, Windows AMD64. */
NAKED void internal_12658(void) {
    __asm__(START
        ".Ls5_12658:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "mov rbx, qword ptr [rcx]\n"
        S5_MOV64(rdi, rcx)
        "cmp dword ptr [rbx], 0xe06d7363\n"
        "jne .Ls5_1268c\n"
        "cmp dword ptr [rbx + 0x18], 4\n"
        "jne .Ls5_1268c\n"
        "mov edx, dword ptr [rbx + 0x20]\n"
        "lea eax, [rdx - 0x19930520]\n"
        "cmp eax, 2\n"
        "jbe .Ls5_12699\n"
        "cmp edx, 0x1994000\n"
        "je .Ls5_12699\n"
        ".Ls5_1268c:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        S5_XOR32(eax, eax)
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        ".Ls5_12699:\n"
        "call rva_14788\n"
        "mov qword ptr [rax], rbx\n"
        "mov rbx, qword ptr [rdi + 8]\n"
        "call rva_1478e\n"
        "mov qword ptr [rax], rbx\n"
        "call rva_147e2\n"
        "int3\n" END);
}

/* 0x126b4..0x126f0, Windows AMD64. */
NAKED void internal_126b4(void) {
    __asm__(START
        ".Ls5_126b4:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "lea rbx, [rip + rva_1a000]\n"
        "lea rdi, [rip + rva_1a000]\n"
        "jmp .Ls5_126e0\n"
        ".Ls5_126ce:\n"
        "mov rax, qword ptr [rbx]\n"
        "test rax, rax\n"
        "je .Ls5_126dc\n"
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_126dc:\n"
        "add rbx, 8\n"
        ".Ls5_126e0:\n"
        S5_CMP64(rbx, rdi)
        "jb .Ls5_126ce\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n" END);
}

/* 0x126f0..0x1272c, Windows AMD64. */
NAKED void internal_126f0(void) {
    __asm__(START
        ".Ls5_126f0:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "lea rbx, [rip + rva_1a010]\n"
        "lea rdi, [rip + rva_1a010]\n"
        "jmp .Ls5_1271c\n"
        ".Ls5_1270a:\n"
        "mov rax, qword ptr [rbx]\n"
        "test rax, rax\n"
        "je .Ls5_12718\n"
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_12718:\n"
        "add rbx, 8\n"
        ".Ls5_1271c:\n"
        S5_CMP64(rbx, rdi)
        "jb .Ls5_1270a\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n" END);
}

/* 0x1272c..0x1272f, Windows AMD64. */
NAKED void internal_1272c(void) {
    __asm__(START
        ".Ls5_1272c:\n"
        "ret 0\n" END);
}

/* 0x12730..0x12734, Windows AMD64. */
NAKED void internal_12730(void) {
    __asm__(START
        ".Ls5_12730:\n"
        "mov rax, qword ptr [rcx]\n"
        "ret\n" END);
}

/* 0x12734..0x12738, Windows AMD64. */
NAKED void internal_12734(void) {
    __asm__(START
        ".Ls5_12734:\n"
        "mov rax, qword ptr [rcx]\n"
        "ret\n" END);
}

/* 0x12738..0x12753, Windows AMD64. */
NAKED void internal_12738(void) {
    __asm__(START
        ".Ls5_12738:\n"
        "lea rdx, [rip + rva_19b80]\n"
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rcx, rdx)
        S5_SUB64(rax, rdx)
        S5_CMP64(rcx, rax)
        "ja .Ls5_12752\n"
        "int3\n"
        ".Ls5_12752:\n"
        "ret\n" END);
}

/* 0x12754..0x12775, Windows AMD64. */
NAKED void internal_12754(void) {
    __asm__(START
        ".Ls5_12754:\n"
        "lea rdx, [rip + rva_19b80]\n"
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rcx, rdx)
        S5_SUB64(rax, rdx)
        S5_CMP64(rcx, rax)
        "ja .Ls5_12774\n"
        "mov ecx, 0x41\n"
        "int 0x29\n"
        ".Ls5_12774:\n"
        "ret\n" END);
}

/* 0x12778..0x1277b, Windows AMD64. */
NAKED void internal_12778(void) {
    __asm__(START
        ".Ls5_12778:\n"
        "ret 0\n" END);
}

/* 0x1277c..0x127af, Windows AMD64. */
NAKED void internal_1277c(void) {
    __asm__(START
        ".Ls5_1277c:\n"
        "sub rsp, 0x28\n"
        "lea r8, [rip + rva_19b80]\n"
        S5_MOV64(rax, rcx)
        "lea rdx, [rip + rva_19b80]\n"
        S5_SUB64(rax, r8)
        S5_SUB64(rdx, r8)
        S5_CMP64(rax, rdx)
        "ja .Ls5_127aa\n"
        "mov rax, qword ptr [rip + rva_15d18]\n"
        "test rax, rax\n"
        "je .Ls5_127aa\n"
        "call rax\n"
        ".Ls5_127aa:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x127b0..0x127c7, Windows AMD64. */
NAKED void internal_127b0(void) {
    __asm__(START
        ".Ls5_127b0:\n"
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_15d18]\n"
        "test rax, rax\n"
        "je .Ls5_127c2\n"
        "call rax\n"
        ".Ls5_127c2:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x127c8..0x127ff, Windows AMD64. */
NAKED void internal_127c8(void) {
    __asm__(START
        ".Ls5_127c8:\n"
        "sub rsp, 0x28\n"
        "lea r8, [rip + rva_19b80]\n"
        S5_MOV64(rax, rcx)
        "lea rdx, [rip + rva_19b80]\n"
        S5_SUB64(rax, r8)
        S5_SUB64(rdx, r8)
        S5_CMP64(rax, rdx)
        "ja .Ls5_127fa\n"
        "mov rax, qword ptr [rip + rva_20a80]\n"
        "test rax, rax\n"
        "je .Ls5_127fa\n"
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_127fa:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12800..0x1281b, Windows AMD64. */
NAKED void internal_12800(void) {
    __asm__(START
        ".Ls5_12800:\n"
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_20a80]\n"
        "test rax, rax\n"
        "je .Ls5_12816\n"
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_12816:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x1281c..0x12839, Windows AMD64. */
NAKED void internal_1281c(void) {
    __asm__(START
        ".Ls5_1281c:\n"
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rcx, rax)
        "lea rdx, [rip + rva_19b80]\n"
        S5_SUB64(rdx, rax)
        S5_XOR32(eax, eax)
        S5_CMP64(rcx, rdx)
        "setbe al\n"
        "ret\n" END);
}

/* 0x1283c..0x12847, Windows AMD64. */
NAKED void internal_1283c(void) {
    __asm__(START
        ".Ls5_1283c:\n"
        "xchg qword ptr [rip + rva_20a80], rcx\n"
        S5_MOV64(rax, rcx)
        "ret\n" END);
}

/* 0x12848..0x1287c, Windows AMD64. */
NAKED void internal_12848(void) {
    __asm__(START
        ".Ls5_12848:\n"
        S5_MOV64(rax, rcx)
        S5_SUB64(rax, rdx)
        "lea rdx, [rip + rva_19b00]\n"
        S5_SUB64(rax, rdx)
        "add rax, -0x80\n"
        S5_CMP64(rax, r8)
        "jbe .Ls5_1287b\n"
        "lea rdx, [rip + rva_19b80]\n"
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rcx, rdx)
        S5_SUB64(rax, rdx)
        S5_CMP64(rcx, rax)
        "ja .Ls5_1287b\n"
        "int3\n"
        ".Ls5_1287b:\n"
        "ret\n" END);
}

/* 0x1287c..0x128b6, Windows AMD64. */
NAKED void internal_1287c(void) {
    __asm__(START
        ".Ls5_1287c:\n"
        S5_MOV64(rax, rcx)
        S5_SUB64(rax, rdx)
        "lea rdx, [rip + rva_19b00]\n"
        S5_SUB64(rax, rdx)
        "add rax, -0x80\n"
        S5_CMP64(rax, r8)
        "jbe .Ls5_128b5\n"
        "lea rdx, [rip + rva_19b80]\n"
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rcx, rdx)
        S5_SUB64(rax, rdx)
        S5_CMP64(rcx, rax)
        "ja .Ls5_128b5\n"
        "mov ecx, 0x41\n"
        "int 0x29\n"
        ".Ls5_128b5:\n"
        "ret\n" END);
}

/* 0x128b8..0x128bb, Windows AMD64. */
NAKED void internal_128b8(void) {
    __asm__(START
        ".Ls5_128b8:\n"
        "ret 0\n" END);
}

/* 0x128bc..0x12908, Windows AMD64. */
NAKED void internal_128bc(void) {
    __asm__(START
        ".Ls5_128bc:\n"
        "sub rsp, 0x28\n"
        S5_MOV64(rax, rcx)
        S5_SUB64(rax, rdx)
        "lea rdx, [rip + rva_19b00]\n"
        S5_SUB64(rax, rdx)
        "add rax, -0x80\n"
        S5_CMP64(rax, r8)
        "jbe .Ls5_12903\n"
        "lea r8, [rip + rva_19b80]\n"
        S5_MOV64(rdx, rcx)
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rdx, r8)
        S5_SUB64(rax, r8)
        S5_CMP64(rdx, rax)
        "ja .Ls5_12903\n"
        "mov rax, qword ptr [rip + rva_15d18]\n"
        "test rax, rax\n"
        "je .Ls5_12903\n"
        "call rax\n"
        ".Ls5_12903:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12908..0x12958, Windows AMD64. */
NAKED void internal_12908(void) {
    __asm__(START
        ".Ls5_12908:\n"
        "sub rsp, 0x28\n"
        S5_MOV64(rax, rcx)
        S5_SUB64(rax, rdx)
        "lea rdx, [rip + rva_19b00]\n"
        S5_SUB64(rax, rdx)
        "add rax, -0x80\n"
        S5_CMP64(rax, r8)
        "jbe .Ls5_12953\n"
        "lea r8, [rip + rva_19b80]\n"
        S5_MOV64(rdx, rcx)
        "lea rax, [rip + rva_19b80]\n"
        S5_SUB64(rdx, r8)
        S5_SUB64(rax, r8)
        S5_CMP64(rdx, rax)
        "ja .Ls5_12953\n"
        "mov rax, qword ptr [rip + rva_20a80]\n"
        "test rax, rax\n"
        "je .Ls5_12953\n"
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_12953:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12958..0x12972, Windows AMD64. */
NAKED void internal_12958(void) {
    __asm__(START
        ".Ls5_12958:\n"
        S5_SUB64(rcx, rdx)
        "lea rax, [rip + rva_19b00]\n"
        S5_SUB64(rcx, rax)
        S5_XOR32(eax, eax)
        "add rcx, -0x80\n"
        S5_CMP64(rcx, r8)
        "seta al\n"
        "ret\n" END);
}

/* 0x12974..0x1298b, Windows AMD64. */
NAKED void internal_12974(void) {
    __asm__(START
        ".Ls5_12974:\n"
        "mov rcx, qword ptr [rip + rva_15cf0]\n"
        "lea rdx, [rip + rva_1272c]\n"
        S5_XOR32(eax, eax)
        S5_CMP64(rcx, rdx)
        "setne al\n"
        "ret\n" END);
}

/* 0x1298c..0x1298f, Windows AMD64. */
NAKED void internal_1298c(void) {
    __asm__(START
        ".Ls5_1298c:\n"
        S5_XOR32(eax, eax)
        "ret\n" END);
}

/* 0x12990..0x12c5a, Windows AMD64. */
NAKED void internal_12990(void) {
    __asm__(START
        ".Ls5_12990:\n"
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rbp\n"
        "push rdi\n"
        "push r14\n"
        S5_MOV64(rbp, rsp)
        "sub rsp, 0x10\n"
        S5_XOR32(eax, eax)
        S5_XOR32(ecx, ecx)
        "cpuid\n"
        S5_MOV32(r8d, ecx)
        S5_MOV32(r10d, edx)
        "xor r10d, 0x49656e69\n"
        "xor r8d, 0x6c65746e\n"
        S5_MOV32(r9d, ebx)
        S5_MOV32(r14d, eax)
        S5_XOR32(ecx, ecx)
        "mov eax, 1\n"
        "cpuid\n"
        S5_OR32(r10d, r8d)
        "mov dword ptr [rbp - 0x10], eax\n"
        "xor r9d, 0x756e6547\n"
        "mov dword ptr [rbp - 0xc], ebx\n"
        S5_OR32(r10d, r9d)
        "mov dword ptr [rbp - 8], ecx\n"
        S5_MOV32(edi, ecx)
        "mov dword ptr [rbp - 4], edx\n"
        "jne .Ls5_12a46\n"
        "or qword ptr [rip + rva_1e860], 0xffffffffffffffff\n"
        "and eax, 0xfff3ff0\n"
        "mov qword ptr [rip + rva_1e858], 0x8000\n"
        "cmp eax, 0x106c0\n"
        "je .Ls5_12a32\n"
        "cmp eax, 0x20660\n"
        "je .Ls5_12a32\n"
        "cmp eax, 0x20670\n"
        "je .Ls5_12a32\n"
        "add eax, 0xfffcf9b0\n"
        "cmp eax, 0x20\n"
        "ja .Ls5_12a46\n"
        "movabs rcx, 0x100010001\n"
        "bt rcx, rax\n"
        "jae .Ls5_12a46\n"
        ".Ls5_12a32:\n"
        "mov r8d, dword ptr [rip + rva_20a8c]\n"
        "or r8d, 1\n"
        "mov dword ptr [rip + rva_20a8c], r8d\n"
        "jmp .Ls5_12a4d\n"
        ".Ls5_12a46:\n"
        "mov r8d, dword ptr [rip + rva_20a8c]\n"
        ".Ls5_12a4d:\n"
        S5_XOR32(r9d, r9d)
        S5_MOV32(esi, r9d)
        S5_MOV32(r11d, r9d)
        S5_MOV32(r10d, r9d)
        "cmp r14d, 7\n"
        "jl .Ls5_12ac4\n"
        "lea eax, [r9 + 7]\n"
        S5_XOR32(ecx, ecx)
        "cpuid\n"
        "mov dword ptr [rbp - 0x10], eax\n"
        S5_MOV32(esi, edx)
        "mov dword ptr [rbp - 0xc], ebx\n"
        S5_MOV32(r9d, ebx)
        "mov dword ptr [rbp - 8], ecx\n"
        "mov dword ptr [rbp - 4], edx\n"
        "bt ebx, 9\n"
        "jae .Ls5_12a89\n"
        "or r8d, 2\n"
        "mov dword ptr [rip + rva_20a8c], r8d\n"
        ".Ls5_12a89:\n"
        "cmp eax, 1\n"
        "jl .Ls5_12aa7\n"
        "mov eax, 7\n"
        "lea ecx, [rax - 6]\n"
        "cpuid\n"
        S5_MOV32(r11d, edx)
        "mov dword ptr [rbp - 0x10], eax\n"
        "mov dword ptr [rbp - 0xc], ebx\n"
        "mov dword ptr [rbp - 8], ecx\n"
        "mov dword ptr [rbp - 4], edx\n"
        ".Ls5_12aa7:\n"
        "mov eax, 0x24\n"
        S5_CMP32(r14d, eax)
        "jl .Ls5_12ac4\n"
        S5_XOR32(ecx, ecx)
        "cpuid\n"
        S5_MOV32(r10d, ebx)
        "mov dword ptr [rbp - 0x10], eax\n"
        "mov dword ptr [rbp - 0xc], ebx\n"
        "mov dword ptr [rbp - 8], ecx\n"
        "mov dword ptr [rbp - 4], edx\n"
        ".Ls5_12ac4:\n"
        "mov rax, qword ptr [rip + rva_1e848]\n"
        "mov ebx, 6\n"
        "and rax, 0xfffffffffffffffe\n"
        "mov dword ptr [rip + rva_1e850], 1\n"
        "mov dword ptr [rip + rva_1e854], 2\n"
        "mov qword ptr [rip + rva_1e848], rax\n"
        "bt edi, 0x14\n"
        "jae .Ls5_12b10\n"
        "and rax, 0xffffffffffffffef\n"
        "mov dword ptr [rip + rva_1e850], 2\n"
        "mov qword ptr [rip + rva_1e848], rax\n"
        "mov dword ptr [rip + rva_1e854], ebx\n"
        ".Ls5_12b10:\n"
        "bt edi, 0x1b\n"
        "jae rva_12c45\n"
        S5_XOR32(ecx, ecx)
        "xgetbv\n"
        "shl rdx, 0x20\n"
        S5_OR64(rdx, rax)
        "mov qword ptr [rbp + 0x20], rdx\n"
        "bt edi, 0x1c\n"
        "jae rva_12c2a\n"
        "mov rax, qword ptr [rbp + 0x20]\n"
        S5_AND8(al, bl)
        S5_CMP8(al, bl)
        "jne rva_12c2a\n"
        "mov eax, dword ptr [rip + rva_1e854]\n"
        "mov dl, 0xe0\n"
        "or eax, 8\n"
        "mov dword ptr [rip + rva_1e850], 3\n"
        "mov dword ptr [rip + rva_1e854], eax\n"
        "test r9b, 0x20\n"
        "je .Ls5_12bc0\n"
        "or eax, 0x20\n"
        "mov dword ptr [rip + rva_1e850], 5\n"
        "mov dword ptr [rip + rva_1e854], eax\n"
        "mov ecx, 0xd0030000\n"
        "mov rax, qword ptr [rip + rva_1e848]\n"
        S5_AND32(r9d, ecx)
        "and rax, 0xfffffffffffffffd\n"
        "mov qword ptr [rip + rva_1e848], rax\n"
        S5_CMP32(r9d, ecx)
        "jne .Ls5_12bc7\n"
        "mov rax, qword ptr [rbp + 0x20]\n"
        S5_AND8(al, dl)
        S5_CMP8(al, dl)
        "jne .Ls5_12bc0\n"
        "mov rax, qword ptr [rip + rva_1e848]\n"
        "or dword ptr [rip + rva_1e854], 0x40\n"
        "and rax, 0xffffffffffffffdb\n"
        "mov dword ptr [rip + rva_1e850], ebx\n"
        "mov qword ptr [rip + rva_1e848], rax\n"
        "jmp .Ls5_12bc7\n"
        ".Ls5_12bc0:\n"
        "mov rax, qword ptr [rip + rva_1e848]\n"
        ".Ls5_12bc7:\n"
        "bt esi, 0x17\n"
        "jae .Ls5_12bd9\n"
        "btr rax, 0x18\n"
        "mov qword ptr [rip + rva_1e848], rax\n"
        ".Ls5_12bd9:\n"
        "bt r11d, 0x13\n"
        "jae .Ls5_12c2a\n"
        "mov rax, qword ptr [rbp + 0x20]\n"
        S5_AND8(al, dl)
        S5_CMP8(al, dl)
        "jne .Ls5_12c2a\n"
        S5_MOV32(ecx, r10d)
        S5_MOV32(eax, r10d)
        "shr rcx, 0x10\n"
        "and eax, 0x400ff\n"
        "and ecx, 7\n"
        "mov dword ptr [rip + rva_20a88], eax\n"
        "or rcx, 0x1000028\n"
        "not rcx\n"
        "and rcx, qword ptr [rip + rva_1e848]\n"
        "mov qword ptr [rip + rva_1e848], rcx\n"
        "cmp eax, 1\n"
        "jbe .Ls5_12c2a\n"
        "and rcx, 0xffffffffffffffbf\n"
        "mov qword ptr [rip + rva_1e848], rcx\n"
        ".Ls5_12c2a:\n"
        "bt r10d, 0x15\n"
        "jae .Ls5_12c45\n"
        "mov rax, qword ptr [rbp + 0x20]\n"
        "bt rax, 0x13\n"
        "jae .Ls5_12c45\n"
        "btr qword ptr [rip + rva_1e848], 7\n"
        ".Ls5_12c45:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        S5_XOR32(eax, eax)
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x10\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rbp\n"
        "ret\n" END);
}

/* 0x12c5c..0x12c62, Windows AMD64. */
NAKED void internal_12c5c(void) {
    __asm__(START
        ".Ls5_12c5c:\n"
        "mov eax, 1\n"
        "ret\n" END);
}

/* 0x12c64..0x12c70, Windows AMD64. */
NAKED void internal_12c64(void) {
    __asm__(START
        ".Ls5_12c64:\n"
        S5_XOR32(eax, eax)
        "cmp dword ptr [rip + rva_1e8b0], eax\n"
        "setne al\n"
        "ret\n" END);
}

/* 0x12c70..0x13d1a, Windows AMD64. */
NAKED void internal_12c70(void) {
    __asm__(START
        ".Ls5_12c70:\n"
        "cmp r8, 1\n"
        S5_MOV64(rax, rcx)
        "jne .Ls5_12c80\n"
        "mov r9b, byte ptr [rdx]\n"
        "mov byte ptr [rcx], r9b\n"
        "ret\n"
        ".Ls5_12c80:\n"
        "lea r11, [rip + rva_24040]\n"
        "cmp r8, 8\n"
        "jg .Ls5_12ca0\n"
        S5_ADD64(rcx, r8)
        S5_ADD64(rdx, r8)
        "jmp qword ptr [r11 + r8*8]\n"
        ".byte 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_12ca0:\n"
        "test rcx, 7\n"
        "jne .Ls5_12cc7\n"
        ".Ls5_12ca9:\n"
        "lea r11, [rip + rva_24040]\n"
        "cmp r8, 0xb0\n"
        "jg rva_13540\n"
        S5_ADD64(rcx, r8)
        S5_ADD64(rdx, r8)
        "jmp qword ptr [r11 + r8*8]\n"
        ".Ls5_12cc7:\n"
        "lea r11, [rip + rva_24000]\n"
        S5_MOV64(r9, rcx)
        "and r9, 7\n"
        "jmp qword ptr [r11 + r9*8]\n"
        "mov r11b, byte ptr [rdx]\n"
        "mov r10w, word ptr [rdx + 1]\n"
        "mov r9d, dword ptr [rdx + 3]\n"
        "mov byte ptr [rcx], r11b\n"
        "mov word ptr [rcx + 1], r10w\n"
        "mov dword ptr [rcx + 3], r9d\n"
        "sub r8, 7\n"
        "add rcx, 7\n"
        "add rdx, 7\n"
        "jmp .Ls5_12ca9\n"
        "mov r10w, word ptr [rdx]\n"
        "mov r9d, dword ptr [rdx + 2]\n"
        "mov word ptr [rcx], r10w\n"
        "mov dword ptr [rcx + 2], r9d\n"
        "sub r8, 6\n"
        "add rcx, 6\n"
        "add rdx, 6\n"
        "jmp .Ls5_12ca9\n"
        "mov r11b, byte ptr [rdx]\n"
        "mov r9d, dword ptr [rdx + 1]\n"
        "mov byte ptr [rcx], r11b\n"
        "mov dword ptr [rcx + 1], r9d\n"
        "sub r8, 5\n"
        "add rcx, 5\n"
        "add rdx, 5\n"
        "jmp rva_12ca9\n"
        "mov r9d, dword ptr [rdx]\n"
        "mov dword ptr [rcx], r9d\n"
        "sub r8, 4\n"
        "add rcx, 4\n"
        "add rdx, 4\n"
        "jmp rva_12ca9\n"
        "mov r11b, byte ptr [rdx]\n"
        "mov r10w, word ptr [rdx + 1]\n"
        "mov byte ptr [rcx], r11b\n"
        "mov word ptr [rcx + 1], r10w\n"
        "sub r8, 3\n"
        "add rcx, 3\n"
        "add rdx, 3\n"
        "jmp rva_12ca9\n"
        "mov r10w, word ptr [rdx]\n"
        "mov word ptr [rcx], r10w\n"
        "sub r8, 2\n"
        "add rcx, 2\n"
        "add rdx, 2\n"
        "jmp rva_12ca9\n"
        "mov r11b, byte ptr [rdx]\n"
        "mov byte ptr [rcx], r11b\n"
        "dec r8\n"
        "inc rcx\n"
        "inc rdx\n"
        "jmp rva_12ca9\n"
        "ret\n"
        "test rcx, 1\n"
        "je .Ls5_12dbd\n"
        "mov r10b, byte ptr [rdx]\n"
        "mov byte ptr [rcx], r10b\n"
        "add rcx, 1\n"
        "sub r8, 1\n"
        "add rdx, 1\n"
        ".Ls5_12dbd:\n"
        "test rcx, 2\n"
        "je .Ls5_12dda\n"
        "mov r10w, word ptr [rdx]\n"
        "mov word ptr [rcx], r10w\n"
        "add rcx, 2\n"
        "sub r8, 2\n"
        "add rdx, 2\n"
        ".Ls5_12dda:\n"
        "test rcx, 4\n"
        "je rva_12ca9\n"
        "mov r10d, dword ptr [rdx]\n"
        "mov dword ptr [rcx], r10d\n"
        "sub r8, 4\n"
        "add rdx, 4\n"
        "add rcx, 4\n"
        "jmp rva_12ca9\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        "mov r9, qword ptr [rdx - 0xb0]\n"
        "mov qword ptr [rcx - 0xb0], r9\n"
        "mov r11, qword ptr [rdx - 0xa8]\n"
        "mov qword ptr [rcx - 0xa8], r11\n"
        "mov r9, qword ptr [rdx - 0xa0]\n"
        "mov qword ptr [rcx - 0xa0], r9\n"
        "mov r10, qword ptr [rdx - 0x98]\n"
        "mov qword ptr [rcx - 0x98], r10\n"
        "mov r9, qword ptr [rdx - 0x90]\n"
        "mov qword ptr [rcx - 0x90], r9\n"
        "mov r10, qword ptr [rdx - 0x88]\n"
        "mov qword ptr [rcx - 0x88], r10\n"
        "mov r9, qword ptr [rdx - 0x80]\n"
        "mov qword ptr [rcx - 0x80], r9\n"
        "mov r10, qword ptr [rdx - 0x78]\n"
        "mov qword ptr [rcx - 0x78], r10\n"
        "mov r9, qword ptr [rdx - 0x70]\n"
        "mov qword ptr [rcx - 0x70], r9\n"
        "mov r10, qword ptr [rdx - 0x68]\n"
        "mov qword ptr [rcx - 0x68], r10\n"
        "mov r9, qword ptr [rdx - 0x60]\n"
        "mov qword ptr [rcx - 0x60], r9\n"
        "mov r10, qword ptr [rdx - 0x58]\n"
        "mov qword ptr [rcx - 0x58], r10\n"
        "mov r9, qword ptr [rdx - 0x50]\n"
        "mov qword ptr [rcx - 0x50], r9\n"
        "mov r10, qword ptr [rdx - 0x48]\n"
        "mov qword ptr [rcx - 0x48], r10\n"
        "mov r9, qword ptr [rdx - 0x40]\n"
        "mov qword ptr [rcx - 0x40], r9\n"
        "mov r10, qword ptr [rdx - 0x38]\n"
        "mov qword ptr [rcx - 0x38], r10\n"
        "mov r9, qword ptr [rdx - 0x30]\n"
        "mov qword ptr [rcx - 0x30], r9\n"
        "mov r10, qword ptr [rdx - 0x28]\n"
        "mov qword ptr [rcx - 0x28], r10\n"
        "mov r9, qword ptr [rdx - 0x20]\n"
        "mov qword ptr [rcx - 0x20], r9\n"
        "mov r10, qword ptr [rdx - 0x18]\n"
        "mov qword ptr [rcx - 0x18], r10\n"
        "mov r9, qword ptr [rdx - 0x10]\n"
        "mov qword ptr [rcx - 0x10], r9\n"
        "mov r10, qword ptr [rdx - 8]\n"
        "mov qword ptr [rcx - 8], r10\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb1]\n"
        "mov qword ptr [rcx - 0xb1], r9\n"
        "mov r9, qword ptr [rdx - 0xa9]\n"
        "mov qword ptr [rcx - 0xa9], r9\n"
        "mov r9, qword ptr [rdx - 0xa1]\n"
        "mov qword ptr [rcx - 0xa1], r9\n"
        "mov r9, qword ptr [rdx - 0x99]\n"
        "mov qword ptr [rcx - 0x99], r9\n"
        "mov r9, qword ptr [rdx - 0x91]\n"
        "mov qword ptr [rcx - 0x91], r9\n"
        "mov r9, qword ptr [rdx - 0x89]\n"
        "mov qword ptr [rcx - 0x89], r9\n"
        "mov r9, qword ptr [rdx - 0x81]\n"
        "mov qword ptr [rcx - 0x81], r9\n"
        "mov r9, qword ptr [rdx - 0x79]\n"
        "mov qword ptr [rcx - 0x79], r9\n"
        "mov r9, qword ptr [rdx - 0x71]\n"
        "mov qword ptr [rcx - 0x71], r9\n"
        "mov r9, qword ptr [rdx - 0x69]\n"
        "mov qword ptr [rcx - 0x69], r9\n"
        "mov r9, qword ptr [rdx - 0x61]\n"
        "mov qword ptr [rcx - 0x61], r9\n"
        "mov r11, qword ptr [rdx - 0x59]\n"
        "mov qword ptr [rcx - 0x59], r11\n"
        "mov r10, qword ptr [rdx - 0x51]\n"
        "mov qword ptr [rcx - 0x51], r10\n"
        "mov r9, qword ptr [rdx - 0x49]\n"
        "mov qword ptr [rcx - 0x49], r9\n"
        "mov r11, qword ptr [rdx - 0x41]\n"
        "mov qword ptr [rcx - 0x41], r11\n"
        "mov r10, qword ptr [rdx - 0x39]\n"
        "mov qword ptr [rcx - 0x39], r10\n"
        "mov r9, qword ptr [rdx - 0x31]\n"
        "mov qword ptr [rcx - 0x31], r9\n"
        "mov r11, qword ptr [rdx - 0x29]\n"
        "mov qword ptr [rcx - 0x29], r11\n"
        "mov r10, qword ptr [rdx - 0x21]\n"
        "mov qword ptr [rcx - 0x21], r10\n"
        "mov r9, qword ptr [rdx - 0x19]\n"
        "mov qword ptr [rcx - 0x19], r9\n"
        "mov r11, qword ptr [rdx - 0x11]\n"
        "mov qword ptr [rcx - 0x11], r11\n"
        "mov r10, qword ptr [rdx - 9]\n"
        "mov qword ptr [rcx - 9], r10\n"
        "mov r9b, byte ptr [rdx - 1]\n"
        "mov byte ptr [rcx - 1], r9b\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb2]\n"
        "mov qword ptr [rcx - 0xb2], r9\n"
        "mov r9, qword ptr [rdx - 0xaa]\n"
        "mov qword ptr [rcx - 0xaa], r9\n"
        "mov r9, qword ptr [rdx - 0xa2]\n"
        "mov qword ptr [rcx - 0xa2], r9\n"
        "mov r9, qword ptr [rdx - 0x9a]\n"
        "mov qword ptr [rcx - 0x9a], r9\n"
        "mov r9, qword ptr [rdx - 0x92]\n"
        "mov qword ptr [rcx - 0x92], r9\n"
        "mov r9, qword ptr [rdx - 0x8a]\n"
        "mov qword ptr [rcx - 0x8a], r9\n"
        "mov r9, qword ptr [rdx - 0x82]\n"
        "mov qword ptr [rcx - 0x82], r9\n"
        "mov r9, qword ptr [rdx - 0x7a]\n"
        "mov qword ptr [rcx - 0x7a], r9\n"
        "mov r9, qword ptr [rdx - 0x72]\n"
        "mov qword ptr [rcx - 0x72], r9\n"
        "mov r9, qword ptr [rdx - 0x6a]\n"
        "mov qword ptr [rcx - 0x6a], r9\n"
        "mov r9, qword ptr [rdx - 0x62]\n"
        "mov qword ptr [rcx - 0x62], r9\n"
        "mov r9, qword ptr [rdx - 0x5a]\n"
        "mov qword ptr [rcx - 0x5a], r9\n"
        "mov r9, qword ptr [rdx - 0x52]\n"
        "mov qword ptr [rcx - 0x52], r9\n"
        "mov r9, qword ptr [rdx - 0x4a]\n"
        "mov qword ptr [rcx - 0x4a], r9\n"
        "mov r9, qword ptr [rdx - 0x42]\n"
        "mov qword ptr [rcx - 0x42], r9\n"
        "mov r9, qword ptr [rdx - 0x3a]\n"
        "mov qword ptr [rcx - 0x3a], r9\n"
        "mov r9, qword ptr [rdx - 0x32]\n"
        "mov qword ptr [rcx - 0x32], r9\n"
        "mov r9, qword ptr [rdx - 0x2a]\n"
        "mov qword ptr [rcx - 0x2a], r9\n"
        "mov r9, qword ptr [rdx - 0x22]\n"
        "mov qword ptr [rcx - 0x22], r9\n"
        "mov r9, qword ptr [rdx - 0x1a]\n"
        "mov qword ptr [rcx - 0x1a], r9\n"
        "mov r9, qword ptr [rdx - 0x12]\n"
        "mov qword ptr [rcx - 0x12], r9\n"
        "mov r9, qword ptr [rdx - 0xa]\n"
        "mov qword ptr [rcx - 0xa], r9\n"
        "mov r9w, word ptr [rdx - 2]\n"
        "mov word ptr [rcx - 2], r9w\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb3]\n"
        "mov qword ptr [rcx - 0xb3], r9\n"
        "mov r9, qword ptr [rdx - 0xab]\n"
        "mov qword ptr [rcx - 0xab], r9\n"
        "mov r9, qword ptr [rdx - 0xa3]\n"
        "mov qword ptr [rcx - 0xa3], r9\n"
        "mov r9, qword ptr [rdx - 0x9b]\n"
        "mov qword ptr [rcx - 0x9b], r9\n"
        "mov r9, qword ptr [rdx - 0x93]\n"
        "mov qword ptr [rcx - 0x93], r9\n"
        "mov r9, qword ptr [rdx - 0x8b]\n"
        "mov qword ptr [rcx - 0x8b], r9\n"
        "mov r9, qword ptr [rdx - 0x83]\n"
        "mov qword ptr [rcx - 0x83], r9\n"
        "mov r9, qword ptr [rdx - 0x7b]\n"
        "mov qword ptr [rcx - 0x7b], r9\n"
        "mov r9, qword ptr [rdx - 0x73]\n"
        "mov qword ptr [rcx - 0x73], r9\n"
        "mov r9, qword ptr [rdx - 0x6b]\n"
        "mov qword ptr [rcx - 0x6b], r9\n"
        "mov r9, qword ptr [rdx - 0x63]\n"
        "mov qword ptr [rcx - 0x63], r9\n"
        "mov r9, qword ptr [rdx - 0x5b]\n"
        "mov qword ptr [rcx - 0x5b], r9\n"
        "mov r9, qword ptr [rdx - 0x53]\n"
        "mov qword ptr [rcx - 0x53], r9\n"
        "mov r9, qword ptr [rdx - 0x4b]\n"
        "mov qword ptr [rcx - 0x4b], r9\n"
        "mov r9, qword ptr [rdx - 0x43]\n"
        "mov qword ptr [rcx - 0x43], r9\n"
        "mov r9, qword ptr [rdx - 0x3b]\n"
        "mov qword ptr [rcx - 0x3b], r9\n"
        "mov r9, qword ptr [rdx - 0x33]\n"
        "mov qword ptr [rcx - 0x33], r9\n"
        "mov r9, qword ptr [rdx - 0x2b]\n"
        "mov qword ptr [rcx - 0x2b], r9\n"
        "mov r9, qword ptr [rdx - 0x23]\n"
        "mov qword ptr [rcx - 0x23], r9\n"
        "mov r9, qword ptr [rdx - 0x1b]\n"
        "mov qword ptr [rcx - 0x1b], r9\n"
        "mov r9, qword ptr [rdx - 0x13]\n"
        "mov qword ptr [rcx - 0x13], r9\n"
        "mov r9, qword ptr [rdx - 0xb]\n"
        "mov qword ptr [rcx - 0xb], r9\n"
        "mov r9w, word ptr [rdx - 3]\n"
        "mov r10b, byte ptr [rdx - 1]\n"
        "mov word ptr [rcx - 3], r9w\n"
        "mov byte ptr [rcx - 1], r10b\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb4]\n"
        "mov qword ptr [rcx - 0xb4], r9\n"
        "mov r9, qword ptr [rdx - 0xac]\n"
        "mov qword ptr [rcx - 0xac], r9\n"
        "mov r9, qword ptr [rdx - 0xa4]\n"
        "mov qword ptr [rcx - 0xa4], r9\n"
        "mov r9, qword ptr [rdx - 0x9c]\n"
        "mov qword ptr [rcx - 0x9c], r9\n"
        "mov r9, qword ptr [rdx - 0x94]\n"
        "mov qword ptr [rcx - 0x94], r9\n"
        "mov r9, qword ptr [rdx - 0x8c]\n"
        "mov qword ptr [rcx - 0x8c], r9\n"
        "mov r9, qword ptr [rdx - 0x84]\n"
        "mov qword ptr [rcx - 0x84], r9\n"
        "mov r9, qword ptr [rdx - 0x7c]\n"
        "mov qword ptr [rcx - 0x7c], r9\n"
        "mov r9, qword ptr [rdx - 0x74]\n"
        "mov qword ptr [rcx - 0x74], r9\n"
        "mov r9, qword ptr [rdx - 0x6c]\n"
        "mov qword ptr [rcx - 0x6c], r9\n"
        "mov r9, qword ptr [rdx - 0x64]\n"
        "mov qword ptr [rcx - 0x64], r9\n"
        "mov r9, qword ptr [rdx - 0x5c]\n"
        "mov qword ptr [rcx - 0x5c], r9\n"
        "mov r9, qword ptr [rdx - 0x54]\n"
        "mov qword ptr [rcx - 0x54], r9\n"
        "mov r9, qword ptr [rdx - 0x4c]\n"
        "mov qword ptr [rcx - 0x4c], r9\n"
        "mov r9, qword ptr [rdx - 0x44]\n"
        "mov qword ptr [rcx - 0x44], r9\n"
        "mov r9, qword ptr [rdx - 0x3c]\n"
        "mov qword ptr [rcx - 0x3c], r9\n"
        "mov r9, qword ptr [rdx - 0x34]\n"
        "mov qword ptr [rcx - 0x34], r9\n"
        "mov r9, qword ptr [rdx - 0x2c]\n"
        "mov qword ptr [rcx - 0x2c], r9\n"
        "mov r9, qword ptr [rdx - 0x24]\n"
        "mov qword ptr [rcx - 0x24], r9\n"
        "mov r9, qword ptr [rdx - 0x1c]\n"
        "mov qword ptr [rcx - 0x1c], r9\n"
        "mov r9, qword ptr [rdx - 0x14]\n"
        "mov qword ptr [rcx - 0x14], r9\n"
        "mov r9, qword ptr [rdx - 0xc]\n"
        "mov qword ptr [rcx - 0xc], r9\n"
        "mov r9d, dword ptr [rdx - 4]\n"
        "mov dword ptr [rcx - 4], r9d\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb5]\n"
        "mov qword ptr [rcx - 0xb5], r9\n"
        "mov r9, qword ptr [rdx - 0xad]\n"
        "mov qword ptr [rcx - 0xad], r9\n"
        "mov r9, qword ptr [rdx - 0xa5]\n"
        "mov qword ptr [rcx - 0xa5], r9\n"
        "mov r9, qword ptr [rdx - 0x9d]\n"
        "mov qword ptr [rcx - 0x9d], r9\n"
        "mov r9, qword ptr [rdx - 0x95]\n"
        "mov qword ptr [rcx - 0x95], r9\n"
        "mov r9, qword ptr [rdx - 0x8d]\n"
        "mov qword ptr [rcx - 0x8d], r9\n"
        "mov r9, qword ptr [rdx - 0x85]\n"
        "mov qword ptr [rcx - 0x85], r9\n"
        "mov r9, qword ptr [rdx - 0x7d]\n"
        "mov qword ptr [rcx - 0x7d], r9\n"
        "mov r9, qword ptr [rdx - 0x75]\n"
        "mov qword ptr [rcx - 0x75], r9\n"
        "mov r9, qword ptr [rdx - 0x6d]\n"
        "mov qword ptr [rcx - 0x6d], r9\n"
        "mov r9, qword ptr [rdx - 0x65]\n"
        "mov qword ptr [rcx - 0x65], r9\n"
        "mov r9, qword ptr [rdx - 0x5d]\n"
        "mov qword ptr [rcx - 0x5d], r9\n"
        "mov r9, qword ptr [rdx - 0x55]\n"
        "mov qword ptr [rcx - 0x55], r9\n"
        "mov r9, qword ptr [rdx - 0x4d]\n"
        "mov qword ptr [rcx - 0x4d], r9\n"
        "mov r9, qword ptr [rdx - 0x45]\n"
        "mov qword ptr [rcx - 0x45], r9\n"
        "mov r9, qword ptr [rdx - 0x3d]\n"
        "mov qword ptr [rcx - 0x3d], r9\n"
        "mov r9, qword ptr [rdx - 0x35]\n"
        "mov qword ptr [rcx - 0x35], r9\n"
        "mov r9, qword ptr [rdx - 0x2d]\n"
        "mov qword ptr [rcx - 0x2d], r9\n"
        "mov r9, qword ptr [rdx - 0x25]\n"
        "mov qword ptr [rcx - 0x25], r9\n"
        "mov r9, qword ptr [rdx - 0x1d]\n"
        "mov qword ptr [rcx - 0x1d], r9\n"
        "mov r9, qword ptr [rdx - 0x15]\n"
        "mov qword ptr [rcx - 0x15], r9\n"
        "mov r9, qword ptr [rdx - 0xd]\n"
        "mov qword ptr [rcx - 0xd], r9\n"
        "mov r9d, dword ptr [rdx - 5]\n"
        "mov r10b, byte ptr [rdx - 1]\n"
        "mov dword ptr [rcx - 5], r9d\n"
        "mov byte ptr [rcx - 1], r10b\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb6]\n"
        "mov qword ptr [rcx - 0xb6], r9\n"
        "mov r9, qword ptr [rdx - 0xae]\n"
        "mov qword ptr [rcx - 0xae], r9\n"
        "mov r9, qword ptr [rdx - 0xa6]\n"
        "mov qword ptr [rcx - 0xa6], r9\n"
        "mov r9, qword ptr [rdx - 0x9e]\n"
        "mov qword ptr [rcx - 0x9e], r9\n"
        "mov r9, qword ptr [rdx - 0x96]\n"
        "mov qword ptr [rcx - 0x96], r9\n"
        "mov r9, qword ptr [rdx - 0x8e]\n"
        "mov qword ptr [rcx - 0x8e], r9\n"
        "mov r9, qword ptr [rdx - 0x86]\n"
        "mov qword ptr [rcx - 0x86], r9\n"
        "mov r9, qword ptr [rdx - 0x7e]\n"
        "mov qword ptr [rcx - 0x7e], r9\n"
        "mov r9, qword ptr [rdx - 0x76]\n"
        "mov qword ptr [rcx - 0x76], r9\n"
        "mov r9, qword ptr [rdx - 0x6e]\n"
        "mov qword ptr [rcx - 0x6e], r9\n"
        "mov r9, qword ptr [rdx - 0x66]\n"
        "mov qword ptr [rcx - 0x66], r9\n"
        "mov r9, qword ptr [rdx - 0x5e]\n"
        "mov qword ptr [rcx - 0x5e], r9\n"
        "mov r9, qword ptr [rdx - 0x56]\n"
        "mov qword ptr [rcx - 0x56], r9\n"
        "mov r9, qword ptr [rdx - 0x4e]\n"
        "mov qword ptr [rcx - 0x4e], r9\n"
        "mov r9, qword ptr [rdx - 0x46]\n"
        "mov qword ptr [rcx - 0x46], r9\n"
        "mov r9, qword ptr [rdx - 0x3e]\n"
        "mov qword ptr [rcx - 0x3e], r9\n"
        "mov r9, qword ptr [rdx - 0x36]\n"
        "mov qword ptr [rcx - 0x36], r9\n"
        "mov r9, qword ptr [rdx - 0x2e]\n"
        "mov qword ptr [rcx - 0x2e], r9\n"
        "mov r9, qword ptr [rdx - 0x26]\n"
        "mov qword ptr [rcx - 0x26], r9\n"
        "mov r9, qword ptr [rdx - 0x1e]\n"
        "mov qword ptr [rcx - 0x1e], r9\n"
        "mov r9, qword ptr [rdx - 0x16]\n"
        "mov qword ptr [rcx - 0x16], r9\n"
        "mov r9, qword ptr [rdx - 0xe]\n"
        "mov qword ptr [rcx - 0xe], r9\n"
        "mov r9d, dword ptr [rdx - 6]\n"
        "mov r10w, word ptr [rdx - 2]\n"
        "mov dword ptr [rcx - 6], r9d\n"
        "mov word ptr [rcx - 2], r10w\n"
        "ret\n"
        "mov r9, qword ptr [rdx - 0xb7]\n"
        "mov qword ptr [rcx - 0xb7], r9\n"
        "mov r9, qword ptr [rdx - 0xaf]\n"
        "mov qword ptr [rcx - 0xaf], r9\n"
        "mov r9, qword ptr [rdx - 0xa7]\n"
        "mov qword ptr [rcx - 0xa7], r9\n"
        "mov r9, qword ptr [rdx - 0x9f]\n"
        "mov qword ptr [rcx - 0x9f], r9\n"
        "mov r9, qword ptr [rdx - 0x97]\n"
        "mov qword ptr [rcx - 0x97], r9\n"
        "mov r9, qword ptr [rdx - 0x8f]\n"
        "mov qword ptr [rcx - 0x8f], r9\n"
        "mov r9, qword ptr [rdx - 0x87]\n"
        "mov qword ptr [rcx - 0x87], r9\n"
        "mov r9, qword ptr [rdx - 0x7f]\n"
        "mov qword ptr [rcx - 0x7f], r9\n"
        "mov r9, qword ptr [rdx - 0x77]\n"
        "mov qword ptr [rcx - 0x77], r9\n"
        "mov r9, qword ptr [rdx - 0x6f]\n"
        "mov qword ptr [rcx - 0x6f], r9\n"
        "mov r9, qword ptr [rdx - 0x67]\n"
        "mov qword ptr [rcx - 0x67], r9\n"
        "mov r9, qword ptr [rdx - 0x5f]\n"
        "mov qword ptr [rcx - 0x5f], r9\n"
        "mov r9, qword ptr [rdx - 0x57]\n"
        "mov qword ptr [rcx - 0x57], r9\n"
        "mov r9, qword ptr [rdx - 0x4f]\n"
        "mov qword ptr [rcx - 0x4f], r9\n"
        "mov r9, qword ptr [rdx - 0x47]\n"
        "mov qword ptr [rcx - 0x47], r9\n"
        "mov r9, qword ptr [rdx - 0x3f]\n"
        "mov qword ptr [rcx - 0x3f], r9\n"
        "mov r9, qword ptr [rdx - 0x37]\n"
        "mov qword ptr [rcx - 0x37], r9\n"
        "mov r9, qword ptr [rdx - 0x2f]\n"
        "mov qword ptr [rcx - 0x2f], r9\n"
        "mov r9, qword ptr [rdx - 0x27]\n"
        "mov qword ptr [rcx - 0x27], r9\n"
        "mov r9, qword ptr [rdx - 0x1f]\n"
        "mov qword ptr [rcx - 0x1f], r9\n"
        "mov r9, qword ptr [rdx - 0x17]\n"
        "mov qword ptr [rcx - 0x17], r9\n"
        "mov r9, qword ptr [rdx - 0xf]\n"
        "mov qword ptr [rcx - 0xf], r9\n"
        "mov r9d, dword ptr [rdx - 7]\n"
        "mov r10w, word ptr [rdx - 3]\n"
        "mov r11b, byte ptr [rdx - 1]\n"
        "mov dword ptr [rcx - 7], r9d\n"
        "mov word ptr [rcx - 3], r10w\n"
        "mov byte ptr [rcx - 1], r11b\n"
        "ret\n"
        ".byte 0x66, 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        "cmp dword ptr [rip + rva_213b0], 2\n"
        "jne rva_13b80\n"
        "test rcx, 0xf\n"
        "jne rva_13cc8\n"
        S5_XOR64(r9, r9)
        "cmp r8, qword ptr [rip + rva_1e878]\n"
        "jg rva_13a90\n"
        "test rdx, 0xf\n"
        "je rva_13b00\n"
        "lea r10, [rip + rva_24600]\n"
        S5_MOV64(r11, rdx)
        "and r11, 0xf\n"
        "movdqu xmm0, xmmword ptr [rdx]\n"
        "movdqa xmmword ptr [rcx], xmm0\n"
        "add rdx, 0x10\n"
        S5_SUB64(rdx, r11)
        "add rcx, 0x10\n"
        "sub r8, 0x10\n"
        "movdqa xmm1, xmmword ptr [rdx]\n"
        "jmp qword ptr [r10 + r11*8]\n"
        "lea r10, [rip + rva_24680]\n"
        S5_MOV64(r9, r8)
        "shr r9, 4\n"
        "shl r9, 4\n"
        S5_ADD64(rcx, r9)
        S5_ADD64(rdx, r9)
        S5_SUB64(r8, r9)
        "shr r9, 4\n"
        "jmp qword ptr [r10 + r9*8]\n"
        ".byte 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_135d0:\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "lea rdx, [rdx + 0x20]\n"
        "lea r8, [r8 - 0x20]\n"
        "psrldq xmm1, 1\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 0xf\n"
        "por xmm3, xmm1\n"
        "cmp r8, 0x20\n"
        "psrldq xmm2, 1\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 0xf\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "lea rcx, [rcx + 0x20]\n"
        "jge .Ls5_135d0\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13620:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 2\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 0xe\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 2\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 0xe\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13620\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13670:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 3\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 0xd\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 3\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 0xd\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13670\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_136c0:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 4\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 0xc\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 4\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 0xc\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_136c0\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13710:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 5\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 0xb\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 5\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 0xb\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13710\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13760:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 6\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 0xa\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 6\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 0xa\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13760\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_137b0:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 7\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 9\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 7\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 9\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_137b0\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13800:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 8\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 8\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 8\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 8\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13800\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13850:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 9\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 7\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 9\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 7\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13850\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_138a0:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 0xa\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 6\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 0xa\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 6\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_138a0\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_138f0:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 0xb\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 5\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 0xb\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 5\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_138f0\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13940:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 0xc\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 4\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 0xc\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 4\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13940\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_13990:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 0xd\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 3\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 0xd\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 3\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13990\n"
        "jmp rva_13a79\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_139e0:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 0xe\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 2\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 0xe\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 2\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_139e0\n"
        "jmp .Ls5_13a79\n"
        ".byte 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        ".Ls5_13a30:\n"
        "sub r8, 0x20\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x20]\n"
        "add rdx, 0x20\n"
        "psrldq xmm1, 0xf\n"
        "movdqa xmm2, xmm3\n"
        "pslldq xmm3, 1\n"
        "por xmm3, xmm1\n"
        "psrldq xmm2, 0xf\n"
        "movdqa xmm1, xmm0\n"
        "pslldq xmm0, 1\n"
        "por xmm0, xmm2\n"
        "movdqa xmmword ptr [rcx], xmm3\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "add rcx, 0x20\n"
        "cmp r8, 0x20\n"
        "jge .Ls5_13a30\n"
        ".Ls5_13a79:\n"
        "lea r10, [rip + rva_24040]\n"
        S5_ADD64(rdx, r11)
        S5_ADD64(rcx, r8)
        S5_ADD64(rdx, r8)
        "jmp qword ptr [r10 + r8*8]\n"
        ".byte 0xf, 0x1f, 0x0 # alignment nop\n"
        ".Ls5_13a90:\n"
        "lea rcx, [rcx + 0x40]\n"
        "lea rdx, [rdx + 0x40]\n"
        "lea r8, [r8 - 0x40]\n"
        "prefetchnta byte ptr [rdx + 0x180]\n"
        "movdqu xmm0, xmmword ptr [rdx - 0x40]\n"
        "movdqu xmm1, xmmword ptr [rdx - 0x30]\n"
        "cmp r8, 0x40\n"
        "movntdq xmmword ptr [rcx - 0x40], xmm0\n"
        "movntdq xmmword ptr [rcx - 0x30], xmm1\n"
        "movdqu xmm2, xmmword ptr [rdx - 0x20]\n"
        "movdqu xmm3, xmmword ptr [rdx - 0x10]\n"
        "movntdq xmmword ptr [rcx - 0x20], xmm2\n"
        "movntdq xmmword ptr [rcx - 0x10], xmm3\n"
        "jge .Ls5_13a90\n"
        "lea r10, [rip + rva_24680]\n"
        S5_MOV64(r9, r8)
        "shr r9, 4\n"
        "shl r9, 4\n"
        S5_ADD64(rcx, r9)
        S5_ADD64(rdx, r9)
        S5_SUB64(r8, r9)
        "shr r9, 4\n"
        "sfence\n"
        "jmp qword ptr [r10 + r9*8]\n"
        ".byte 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_13b00:\n"
        "movdqa xmm0, xmmword ptr [rdx]\n"
        "movdqa xmm1, xmmword ptr [rdx + 0x10]\n"
        "movdqa xmmword ptr [rcx], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm1\n"
        "lea r8, [r8 - 0x80]\n"
        "movdqa xmm2, xmmword ptr [rdx + 0x20]\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x30]\n"
        "movdqa xmmword ptr [rcx + 0x20], xmm2\n"
        "movdqa xmmword ptr [rcx + 0x30], xmm3\n"
        "movdqa xmm0, xmmword ptr [rdx + 0x40]\n"
        "movdqa xmm1, xmmword ptr [rdx + 0x50]\n"
        "cmp r8, 0xa8\n"
        "movdqa xmmword ptr [rcx + 0x40], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x50], xmm1\n"
        "movdqa xmm2, xmmword ptr [rdx + 0x60]\n"
        "movdqa xmm3, xmmword ptr [rdx + 0x70]\n"
        "lea rdx, [rdx + 0x80]\n"
        "movdqa xmmword ptr [rcx + 0x60], xmm2\n"
        "movdqa xmmword ptr [rcx + 0x70], xmm3\n"
        "lea rcx, [rcx + 0x80]\n"
        "jge .Ls5_13b00\n"
        "lea r10, [rip + rva_24040]\n"
        S5_ADD64(rcx, r8)
        S5_ADD64(rdx, r8)
        "jmp qword ptr [r10 + r8*8]\n"
        ".byte 0x66, 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        "cmp r8, qword ptr [rip + rva_1e878]\n"
        "jg .Ls5_13c00\n"
        "jmp .Ls5_13b90\n"
        ".byte 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        ".Ls5_13b90:\n"
        "mov r9, qword ptr [rdx]\n"
        "mov r10, qword ptr [rdx + 8]\n"
        "lea r8, [r8 - 0x40]\n"
        "mov qword ptr [rcx], r9\n"
        "mov qword ptr [rcx + 8], r10\n"
        "mov r11, qword ptr [rdx + 0x10]\n"
        "mov r9, qword ptr [rdx + 0x18]\n"
        "mov qword ptr [rcx + 0x10], r11\n"
        "mov qword ptr [rcx + 0x18], r9\n"
        "cmp r8, 0x40\n"
        "mov r10, qword ptr [rdx + 0x20]\n"
        "mov r11, qword ptr [rdx + 0x28]\n"
        "mov qword ptr [rcx + 0x20], r10\n"
        "mov qword ptr [rcx + 0x28], r11\n"
        "mov r9, qword ptr [rdx + 0x30]\n"
        "mov r10, qword ptr [rdx + 0x38]\n"
        "lea rdx, [rdx + 0x40]\n"
        "mov qword ptr [rcx + 0x30], r9\n"
        "mov qword ptr [rcx + 0x38], r10\n"
        "lea rcx, [rcx + 0x40]\n"
        "jg .Ls5_13b90\n"
        "lea r10, [rip + rva_24040]\n"
        "lea rdx, [rdx + r8]\n"
        "lea rcx, [rcx + r8]\n"
        "jmp qword ptr [r10 + r8*8]\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_13c00:\n"
        "sub r8, 0x40\n"
        "prefetchnta byte ptr [rdx + 0x180]\n"
        "mov r9, qword ptr [rdx]\n"
        "movnti qword ptr [rcx], r9\n"
        "mov r10, qword ptr [rdx + 8]\n"
        "movnti qword ptr [rcx + 8], r10\n"
        "mov r11, qword ptr [rdx + 0x10]\n"
        "movnti qword ptr [rcx + 0x10], r11\n"
        "mov r9, qword ptr [rdx + 0x18]\n"
        "movnti qword ptr [rcx + 0x18], r9\n"
        "mov r10, qword ptr [rdx + 0x20]\n"
        "movnti qword ptr [rcx + 0x20], r10\n"
        "mov r11, qword ptr [rdx + 0x28]\n"
        "movnti qword ptr [rcx + 0x28], r11\n"
        "mov r9, qword ptr [rdx + 0x30]\n"
        "movnti qword ptr [rcx + 0x30], r9\n"
        "mov r10, qword ptr [rdx + 0x38]\n"
        "movnti qword ptr [rcx + 0x38], r10\n"
        "lea rdx, [rdx + 0x40]\n"
        "lea rcx, [rcx + 0x40]\n"
        "cmp r8, 0x40\n"
        "jge .Ls5_13c00\n"
        "sfence\n"
        "jmp rva_13be0\n"
        "movdqu xmm0, xmmword ptr [rdx - 0x80]\n"
        "movdqa xmmword ptr [rcx - 0x80], xmm0\n"
        "movdqu xmm1, xmmword ptr [rdx - 0x70]\n"
        "movdqa xmmword ptr [rcx - 0x70], xmm1\n"
        "movdqu xmm2, xmmword ptr [rdx - 0x60]\n"
        "movdqa xmmword ptr [rcx - 0x60], xmm2\n"
        "movdqu xmm3, xmmword ptr [rdx - 0x50]\n"
        "movdqa xmmword ptr [rcx - 0x50], xmm3\n"
        "movdqu xmm0, xmmword ptr [rdx - 0x40]\n"
        "movdqa xmmword ptr [rcx - 0x40], xmm0\n"
        "movdqu xmm1, xmmword ptr [rdx - 0x30]\n"
        "movdqa xmmword ptr [rcx - 0x30], xmm1\n"
        "movdqu xmm2, xmmword ptr [rdx - 0x20]\n"
        "movdqa xmmword ptr [rcx - 0x20], xmm2\n"
        "movdqu xmm3, xmmword ptr [rdx - 0x10]\n"
        "movdqa xmmword ptr [rcx - 0x10], xmm3\n"
        "lea r10, [rip + rva_24040]\n"
        S5_ADD64(rdx, r8)
        S5_ADD64(rcx, r8)
        "jmp qword ptr [r10 + r8*8]\n"
        "mov r9, qword ptr [rdx]\n"
        "mov qword ptr [rcx], r9\n"
        "add rcx, 8\n"
        "add rdx, 8\n"
        "sub r8, 8\n"
        "jmp rva_1355a\n"
        "mov r9d, dword ptr [rdx]\n"
        "mov dword ptr [rcx], r9d\n"
        "add rcx, 4\n"
        "add rdx, 4\n"
        "sub r8, 4\n"
        "mov r9d, dword ptr [rdx]\n"
        "mov dword ptr [rcx], r9d\n"
        "add rcx, 4\n"
        "add rdx, 4\n"
        "sub r8, 4\n"
        "mov r9d, dword ptr [rdx]\n"
        "mov dword ptr [rcx], r9d\n"
        "add rdx, 4\n"
        "add rcx, 4\n"
        "sub r8, 4\n"
        "jmp rva_1355a\n" END);
}

/* 0x13d20..0x14704, Windows AMD64. */
NAKED void internal_13d20(void) {
    __asm__(START
        ".Ls5_13d20:\n"
        "cmp r8, 1\n"
        S5_MOV64(rax, rcx)
        "jne .Ls5_13d2c\n"
        "mov byte ptr [rcx], dl\n"
        "ret\n"
        ".Ls5_13d2c:\n"
        "movabs r9, 0x101010101010101\n"
        "jl .Ls5_13d67\n"
        "and rdx, 0xff\n"
        "imul rdx, r9\n"
        "test rcx, 7\n"
        "jne .Ls5_13d70\n"
        ".Ls5_13d4c:\n"
        "lea r11, [rip + rva_24730]\n"
        "cmp r8, 0x80\n"
        "jge rva_14007\n"
        S5_ADD64(rcx, r8)
        "jmp qword ptr [r11 + r8*8]\n"
        ".Ls5_13d67:\n"
        "ret\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_13d70:\n"
        "cmp r8, 8\n"
        "jle .Ls5_13d4c\n"
        "lea r11, [rip + rva_246f0]\n"
        S5_MOV64(r9, rcx)
        "and r9, 7\n"
        "neg r9\n"
        "add r9, 8\n"
        S5_ADD64(rcx, r9)
        S5_SUB64(r8, r9)
        "jmp qword ptr [r11 + r9*8]\n"
        ".byte 0x66, 0x66, 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        "mov dword ptr [rcx - 4], edx\n"
        "jmp .Ls5_13d4c\n"
        "mov dword ptr [rcx - 5], edx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "jmp .Ls5_13d4c\n"
        "mov dword ptr [rcx - 6], edx\n"
        "mov word ptr [rcx - 2], dx\n"
        "jmp .Ls5_13d4c\n"
        "mov dword ptr [rcx - 7], edx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "jmp .Ls5_13d4c\n"
        "mov qword ptr [rcx - 0x81], rdx\n"
        "mov qword ptr [rcx - 0x79], rdx\n"
        "mov qword ptr [rcx - 0x71], rdx\n"
        "mov qword ptr [rcx - 0x69], rdx\n"
        "mov qword ptr [rcx - 0x61], rdx\n"
        "mov qword ptr [rcx - 0x59], rdx\n"
        "mov qword ptr [rcx - 0x51], rdx\n"
        "mov qword ptr [rcx - 0x49], rdx\n"
        "mov qword ptr [rcx - 0x41], rdx\n"
        "mov qword ptr [rcx - 0x39], rdx\n"
        "mov qword ptr [rcx - 0x31], rdx\n"
        "mov qword ptr [rcx - 0x29], rdx\n"
        "mov qword ptr [rcx - 0x21], rdx\n"
        "mov qword ptr [rcx - 0x19], rdx\n"
        "mov qword ptr [rcx - 0x11], rdx\n"
        "mov qword ptr [rcx - 9], rdx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "mov qword ptr [rcx - 0x80], rdx\n"
        "mov qword ptr [rcx - 0x78], rdx\n"
        "mov qword ptr [rcx - 0x70], rdx\n"
        "mov qword ptr [rcx - 0x68], rdx\n"
        "mov qword ptr [rcx - 0x60], rdx\n"
        "mov qword ptr [rcx - 0x58], rdx\n"
        "mov qword ptr [rcx - 0x50], rdx\n"
        "mov qword ptr [rcx - 0x48], rdx\n"
        "mov qword ptr [rcx - 0x40], rdx\n"
        "mov qword ptr [rcx - 0x38], rdx\n"
        "mov qword ptr [rcx - 0x30], rdx\n"
        "mov qword ptr [rcx - 0x28], rdx\n"
        "mov qword ptr [rcx - 0x20], rdx\n"
        "mov qword ptr [rcx - 0x18], rdx\n"
        "mov qword ptr [rcx - 0x10], rdx\n"
        "mov qword ptr [rcx - 8], rdx\n"
        "ret\n"
        "mov qword ptr [rcx - 0x82], rdx\n"
        "mov qword ptr [rcx - 0x7a], rdx\n"
        "mov qword ptr [rcx - 0x72], rdx\n"
        "mov qword ptr [rcx - 0x6a], rdx\n"
        "mov qword ptr [rcx - 0x62], rdx\n"
        "mov qword ptr [rcx - 0x5a], rdx\n"
        "mov qword ptr [rcx - 0x52], rdx\n"
        "mov qword ptr [rcx - 0x4a], rdx\n"
        "mov qword ptr [rcx - 0x42], rdx\n"
        "mov qword ptr [rcx - 0x3a], rdx\n"
        "mov qword ptr [rcx - 0x32], rdx\n"
        "mov qword ptr [rcx - 0x2a], rdx\n"
        "mov qword ptr [rcx - 0x22], rdx\n"
        "mov qword ptr [rcx - 0x1a], rdx\n"
        "mov qword ptr [rcx - 0x12], rdx\n"
        "mov qword ptr [rcx - 0xa], rdx\n"
        "mov word ptr [rcx - 2], dx\n"
        "ret\n"
        "mov qword ptr [rcx - 0x83], rdx\n"
        "mov qword ptr [rcx - 0x7b], rdx\n"
        "mov qword ptr [rcx - 0x73], rdx\n"
        "mov qword ptr [rcx - 0x6b], rdx\n"
        "mov qword ptr [rcx - 0x63], rdx\n"
        "mov qword ptr [rcx - 0x5b], rdx\n"
        "mov qword ptr [rcx - 0x53], rdx\n"
        "mov qword ptr [rcx - 0x4b], rdx\n"
        "mov qword ptr [rcx - 0x43], rdx\n"
        "mov qword ptr [rcx - 0x3b], rdx\n"
        "mov qword ptr [rcx - 0x33], rdx\n"
        "mov qword ptr [rcx - 0x2b], rdx\n"
        "mov qword ptr [rcx - 0x23], rdx\n"
        "mov qword ptr [rcx - 0x1b], rdx\n"
        "mov qword ptr [rcx - 0x13], rdx\n"
        "mov qword ptr [rcx - 0xb], rdx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "mov qword ptr [rcx - 0x84], rdx\n"
        "mov qword ptr [rcx - 0x7c], rdx\n"
        "mov qword ptr [rcx - 0x74], rdx\n"
        "mov qword ptr [rcx - 0x6c], rdx\n"
        "mov qword ptr [rcx - 0x64], rdx\n"
        "mov qword ptr [rcx - 0x5c], rdx\n"
        "mov qword ptr [rcx - 0x54], rdx\n"
        "mov qword ptr [rcx - 0x4c], rdx\n"
        "mov qword ptr [rcx - 0x44], rdx\n"
        "mov qword ptr [rcx - 0x3c], rdx\n"
        "mov qword ptr [rcx - 0x34], rdx\n"
        "mov qword ptr [rcx - 0x2c], rdx\n"
        "mov qword ptr [rcx - 0x24], rdx\n"
        "mov qword ptr [rcx - 0x1c], rdx\n"
        "mov qword ptr [rcx - 0x14], rdx\n"
        "mov qword ptr [rcx - 0xc], rdx\n"
        "mov dword ptr [rcx - 4], edx\n"
        "ret\n"
        "mov qword ptr [rcx - 0x84], rdx\n"
        "mov qword ptr [rcx - 0x7d], rdx\n"
        "mov qword ptr [rcx - 0x75], rdx\n"
        "mov qword ptr [rcx - 0x6d], rdx\n"
        "mov qword ptr [rcx - 0x65], rdx\n"
        "mov qword ptr [rcx - 0x5d], rdx\n"
        "mov qword ptr [rcx - 0x55], rdx\n"
        "mov qword ptr [rcx - 0x4d], rdx\n"
        "mov qword ptr [rcx - 0x45], rdx\n"
        "mov qword ptr [rcx - 0x3d], rdx\n"
        "mov qword ptr [rcx - 0x35], rdx\n"
        "mov qword ptr [rcx - 0x2d], rdx\n"
        "mov qword ptr [rcx - 0x25], rdx\n"
        "mov qword ptr [rcx - 0x1d], rdx\n"
        "mov qword ptr [rcx - 0x15], rdx\n"
        "mov qword ptr [rcx - 0xd], rdx\n"
        "mov dword ptr [rcx - 5], edx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "mov qword ptr [rcx - 0x86], rdx\n"
        "mov qword ptr [rcx - 0x7e], rdx\n"
        "mov qword ptr [rcx - 0x76], rdx\n"
        "mov qword ptr [rcx - 0x6e], rdx\n"
        "mov qword ptr [rcx - 0x66], rdx\n"
        "mov qword ptr [rcx - 0x5e], rdx\n"
        "mov qword ptr [rcx - 0x56], rdx\n"
        "mov qword ptr [rcx - 0x4e], rdx\n"
        "mov qword ptr [rcx - 0x46], rdx\n"
        "mov qword ptr [rcx - 0x3e], rdx\n"
        "mov qword ptr [rcx - 0x36], rdx\n"
        "mov qword ptr [rcx - 0x2e], rdx\n"
        "mov qword ptr [rcx - 0x26], rdx\n"
        "mov qword ptr [rcx - 0x1e], rdx\n"
        "mov qword ptr [rcx - 0x16], rdx\n"
        "mov qword ptr [rcx - 0xe], rdx\n"
        "mov dword ptr [rcx - 6], edx\n"
        "mov word ptr [rcx - 2], dx\n"
        "ret\n"
        "mov qword ptr [rcx - 0x87], rdx\n"
        "mov qword ptr [rcx - 0x7f], rdx\n"
        "mov qword ptr [rcx - 0x77], rdx\n"
        "mov qword ptr [rcx - 0x6f], rdx\n"
        "mov qword ptr [rcx - 0x67], rdx\n"
        "mov qword ptr [rcx - 0x5f], rdx\n"
        "mov qword ptr [rcx - 0x57], rdx\n"
        "mov qword ptr [rcx - 0x4f], rdx\n"
        "mov qword ptr [rcx - 0x47], rdx\n"
        "mov qword ptr [rcx - 0x3f], rdx\n"
        "mov qword ptr [rcx - 0x37], rdx\n"
        "mov qword ptr [rcx - 0x2f], rdx\n"
        "mov qword ptr [rcx - 0x27], rdx\n"
        "mov qword ptr [rcx - 0x1f], rdx\n"
        "mov qword ptr [rcx - 0x17], rdx\n"
        "mov qword ptr [rcx - 0xf], rdx\n"
        "mov dword ptr [rcx - 7], edx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "cmp dword ptr [rip + rva_213b0], 2\n"
        "jl rva_14660\n"
        "movq xmm0, rdx\n"
        "punpcklqdq xmm0, xmm0\n"
        "lea r11, [rip + rva_24b70]\n"
        "mov r10, 0x10\n"
        S5_MOV64(r9, rcx)
        "and r9, 0xf\n"
        S5_SUB64(r10, r9)
        "and r10, 0xf\n"
        S5_ADD64(rcx, r10)
        S5_SUB64(r8, r10)
        "jmp qword ptr [r11 + r10*8]\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 8], rdx\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 9], rdx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 0xa], rdx\n"
        "mov word ptr [rcx - 2], dx\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 0xb], rdx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 0xc], rdx\n"
        "mov dword ptr [rcx - 4], edx\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 0xd], rdx\n"
        "mov dword ptr [rcx - 5], edx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 0xe], rdx\n"
        "mov dword ptr [rcx - 6], edx\n"
        "mov word ptr [rcx - 2], dx\n"
        "jmp .Ls5_1409b\n"
        "mov qword ptr [rcx - 0xf], rdx\n"
        "mov dword ptr [rcx - 7], edx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        ".Ls5_1409b:\n"
        "lea r11, [rip + rva_24c00]\n"
        "cmp r8, 0xb0\n"
        "jge rva_145a3\n"
        S5_ADD64(rcx, r8)
        "jmp qword ptr [r11 + r8*8]\n"
        "mov dword ptr [rcx], edx\n"
        "add rcx, 4\n"
        "sub r8, 4\n"
        "test rcx, 0xf\n"
        "je .Ls5_1409b\n"
        "mov dword ptr [rcx], edx\n"
        "add rcx, 4\n"
        "sub r8, 4\n"
        "test rcx, 0xf\n"
        "je .Ls5_1409b\n"
        "mov dword ptr [rcx], edx\n"
        "add rcx, 4\n"
        "sub r8, 4\n"
        "jmp .Ls5_1409b\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        "movdqa xmmword ptr [rcx - 0xb0], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa0], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x90], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x80], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x70], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x60], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x50], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x40], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x30], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x20], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x10], xmm0\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb1], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa1], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x91], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x81], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x71], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x61], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x51], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x41], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x31], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x21], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x11], xmm0\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb2], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa2], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x92], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x82], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x72], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x62], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x52], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x42], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x32], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x22], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x12], xmm0\n"
        "mov word ptr [rcx - 2], dx\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb3], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa3], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x93], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x83], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x73], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x63], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x53], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x43], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x33], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x23], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x13], xmm0\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb4], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa4], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x94], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x84], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x74], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x64], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x54], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x44], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x34], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x24], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x14], xmm0\n"
        "mov dword ptr [rcx - 4], edx\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb5], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa5], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x95], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x85], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x75], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x65], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x55], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x45], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x35], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x25], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x15], xmm0\n"
        "mov dword ptr [rcx - 5], edx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb6], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa6], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x96], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x86], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x76], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x66], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x56], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x46], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x36], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x26], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x16], xmm0\n"
        "mov dword ptr [rcx - 6], edx\n"
        "mov word ptr [rcx - 2], dx\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb7], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa7], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x97], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x87], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x77], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x67], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x57], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x47], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x37], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x27], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x17], xmm0\n"
        "mov dword ptr [rcx - 7], edx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb8], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa8], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x98], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x88], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x78], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x68], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x58], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x48], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x38], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x28], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x18], xmm0\n"
        "movq qword ptr [rcx - 8], xmm0\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xb9], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xa9], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x99], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x89], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x79], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x69], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x59], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x49], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x39], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x29], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x19], xmm0\n"
        "movq qword ptr [rcx - 9], xmm0\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xba], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xaa], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x9a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x8a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x7a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x6a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x5a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x4a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x3a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x2a], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x1a], xmm0\n"
        "movq qword ptr [rcx - 0xa], xmm0\n"
        "mov word ptr [rcx - 2], dx\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xbb], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xab], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x9b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x8b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x7b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x6b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x5b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x4b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x3b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x2b], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x1b], xmm0\n"
        "movq qword ptr [rcx - 0xb], xmm0\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xbc], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xac], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x9c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x8c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x7c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x6c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x5c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x4c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x3c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x2c], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x1c], xmm0\n"
        "movq qword ptr [rcx - 0xc], xmm0\n"
        "mov dword ptr [rcx - 4], edx\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xbd], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xad], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x9d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x8d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x7d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x6d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x5d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x4d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x3d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x2d], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x1d], xmm0\n"
        "movq qword ptr [rcx - 0xd], xmm0\n"
        "mov dword ptr [rcx - 5], edx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xbe], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xae], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x9e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x8e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x7e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x6e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x5e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x4e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x3e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x2e], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x1e], xmm0\n"
        "mov qword ptr [rcx - 0xe], rdx\n"
        "mov dword ptr [rcx - 6], edx\n"
        "mov word ptr [rcx - 2], dx\n"
        "ret\n"
        "movdqa xmmword ptr [rcx - 0xbf], xmm0\n"
        "movdqa xmmword ptr [rcx - 0xaf], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x9f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x8f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x7f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x6f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x5f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x4f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x3f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x2f], xmm0\n"
        "movdqa xmmword ptr [rcx - 0x1f], xmm0\n"
        "mov qword ptr [rcx - 0xf], rdx\n"
        "mov dword ptr [rcx - 7], edx\n"
        "mov word ptr [rcx - 3], dx\n"
        "mov byte ptr [rcx - 1], dl\n"
        "ret\n"
        "cmp r8, qword ptr [rip + rva_1e870]\n"
        "jg .Ls5_145f9\n"
        "jmp .Ls5_145b0\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_145b0:\n"
        "lea r8, [r8 - 0x80]\n"
        "movdqa xmmword ptr [rcx], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x10], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x20], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x30], xmm0\n"
        "cmp r8, 0x80\n"
        "movdqa xmmword ptr [rcx + 0x40], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x50], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x60], xmm0\n"
        "movdqa xmmword ptr [rcx + 0x70], xmm0\n"
        "lea rcx, [rcx + 0x80]\n"
        "jge .Ls5_145b0\n"
        "lea r11, [rip + rva_24c00]\n"
        S5_ADD64(rcx, r8)
        "jmp qword ptr [r11 + r8*8]\n"
        ".Ls5_145f9:\n"
        "cmp r9, 0\n"
        "je .Ls5_145b0\n"
        "jmp .Ls5_14610\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_14610:\n"
        "sub r8, 0x80\n"
        "movntdq xmmword ptr [rcx], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x10], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x20], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x30], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x40], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x50], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x60], xmm0\n"
        "movntdq xmmword ptr [rcx + 0x70], xmm0\n"
        "add rcx, 0x80\n"
        "cmp r8, 0x80\n"
        "jge .Ls5_14610\n"
        "sfence\n"
        "lea r11, [rip + rva_24c00]\n"
        S5_ADD64(rcx, r8)
        "jmp qword ptr [r11 + r8*8]\n"
        ".byte 0x90 # alignment nop\n"
        "cmp r8, qword ptr [rip + rva_1e870]\n"
        "jg .Ls5_146b0\n"
        "jmp .Ls5_14670\n"
        ".byte 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        ".Ls5_14670:\n"
        "mov qword ptr [rcx], rdx\n"
        "mov qword ptr [rcx + 8], rdx\n"
        "lea r8, [r8 - 0x40]\n"
        "mov qword ptr [rcx + 0x10], rdx\n"
        "mov qword ptr [rcx + 0x18], rdx\n"
        "cmp r8, 0x40\n"
        "mov qword ptr [rcx + 0x20], rdx\n"
        "mov qword ptr [rcx + 0x28], rdx\n"
        "mov qword ptr [rcx + 0x30], rdx\n"
        "mov qword ptr [rcx + 0x38], rdx\n"
        "lea rcx, [rcx + 0x40]\n"
        "jg .Ls5_14670\n"
        "lea r11, [rip + rva_24730]\n"
        "lea rcx, [rcx + r8]\n"
        "jmp qword ptr [r11 + r8*8]\n"
        ".byte 0xf, 0x1f, 0x40, 0x0 # alignment nop\n"
        ".Ls5_146b0:\n"
        "cmp r9, 0\n"
        "je .Ls5_14670\n"
        "jmp .Ls5_146c0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_146c0:\n"
        "movnti qword ptr [rcx], rdx\n"
        "movnti qword ptr [rcx + 8], rdx\n"
        "lea r8, [r8 - 0x40]\n"
        "movnti qword ptr [rcx + 0x10], rdx\n"
        "movnti qword ptr [rcx + 0x18], rdx\n"
        "movnti qword ptr [rcx + 0x20], rdx\n"
        "cmp r8, 0x40\n"
        "movnti qword ptr [rcx + 0x28], rdx\n"
        "movnti qword ptr [rcx + 0x30], rdx\n"
        "movnti qword ptr [rcx + 0x38], rdx\n"
        "lea rcx, [rcx + 0x40]\n"
        "jge .Ls5_146c0\n"
        "lea r11, [rip + rva_24730]\n"
        "lea rcx, [rcx + r8]\n"
        "jmp qword ptr [r11 + r8*8]\n" END);
}

/* 0x1470a..0x14710, Windows AMD64. */
NAKED void internal_1470a(void) {
    __asm__(START
        ".Ls5_1470a:\n"
        "jmp qword ptr [rip + rva_15028]\n" END);
}

/* 0x14710..0x14716, Windows AMD64. */
NAKED void internal_14710(void) {
    __asm__(START
        ".Ls5_14710:\n"
        "jmp qword ptr [rip + rva_15030]\n" END);
}

/* 0x14716..0x1471c, Windows AMD64. */
NAKED void internal_14716(void) {
    __asm__(START
        ".Ls5_14716:\n"
        "jmp qword ptr [rip + rva_15038]\n" END);
}

/* 0x1471c..0x14722, Windows AMD64. */
NAKED void internal_1471c(void) {
    __asm__(START
        ".Ls5_1471c:\n"
        "jmp qword ptr [rip + rva_15040]\n" END);
}

/* 0x14722..0x14728, Windows AMD64. */
NAKED void internal_14722(void) {
    __asm__(START
        ".Ls5_14722:\n"
        "jmp qword ptr [rip + rva_15048]\n" END);
}

/* 0x14728..0x1472e, Windows AMD64. */
NAKED void internal_14728(void) {
    __asm__(START
        ".Ls5_14728:\n"
        "jmp qword ptr [rip + rva_15050]\n" END);
}

/* 0x1472e..0x14734, Windows AMD64. */
NAKED void internal_1472e(void) {
    __asm__(START
        ".Ls5_1472e:\n"
        "jmp qword ptr [rip + rva_15058]\n" END);
}

/* 0x14734..0x1473a, Windows AMD64. */
NAKED void internal_14734(void) {
    __asm__(START
        ".Ls5_14734:\n"
        "jmp qword ptr [rip + rva_15060]\n" END);
}

/* 0x1473a..0x14740, Windows AMD64. */
NAKED void internal_1473a(void) {
    __asm__(START
        ".Ls5_1473a:\n"
        "jmp qword ptr [rip + rva_15068]\n" END);
}

/* 0x14740..0x14746, Windows AMD64. */
NAKED void internal_14740(void) {
    __asm__(START
        ".Ls5_14740:\n"
        "jmp qword ptr [rip + rva_15070]\n" END);
}

/* 0x14746..0x1474c, Windows AMD64. */
NAKED void internal_14746(void) {
    __asm__(START
        ".Ls5_14746:\n"
        "jmp qword ptr [rip + rva_15078]\n" END);
}

/* 0x1474c..0x14752, Windows AMD64. */
NAKED void internal_1474c(void) {
    __asm__(START
        ".Ls5_1474c:\n"
        "jmp qword ptr [rip + rva_15080]\n" END);
}

/* 0x14752..0x14758, Windows AMD64. */
NAKED void internal_14752(void) {
    __asm__(START
        ".Ls5_14752:\n"
        "jmp qword ptr [rip + rva_15088]\n" END);
}

/* 0x14758..0x1475e, Windows AMD64. */
NAKED void internal_14758(void) {
    __asm__(START
        ".Ls5_14758:\n"
        "jmp qword ptr [rip + rva_15090]\n" END);
}

/* 0x1475e..0x14764, Windows AMD64. */
NAKED void internal_1475e(void) {
    __asm__(START
        ".Ls5_1475e:\n"
        "jmp qword ptr [rip + rva_15098]\n" END);
}

/* 0x14764..0x1476a, Windows AMD64. */
NAKED void internal_14764(void) {
    __asm__(START
        ".Ls5_14764:\n"
        "jmp qword ptr [rip + rva_150a0]\n" END);
}

/* 0x1476a..0x14770, Windows AMD64. */
NAKED void internal_1476a(void) {
    __asm__(START
        ".Ls5_1476a:\n"
        "jmp qword ptr [rip + rva_150a8]\n" END);
}

/* 0x14770..0x14776, Windows AMD64. */
NAKED void internal_14770(void) {
    __asm__(START
        ".Ls5_14770:\n"
        "jmp qword ptr [rip + rva_15010]\n" END);
}

/* 0x14776..0x1477c, Windows AMD64. */
NAKED void internal_14776(void) {
    __asm__(START
        ".Ls5_14776:\n"
        "jmp qword ptr [rip + rva_15008]\n" END);
}

/* 0x1477c..0x14782, Windows AMD64. */
NAKED void internal_1477c(void) {
    __asm__(START
        ".Ls5_1477c:\n"
        "jmp qword ptr [rip + rva_150c0]\n" END);
}

/* 0x1479a..0x147a0, Windows AMD64. */
NAKED void internal_1479a(void) {
    __asm__(START
        ".Ls5_1479a:\n"
        "jmp qword ptr [rip + rva_150b8]\n" END);
}

/* 0x147d6..0x147dc, Windows AMD64. */
NAKED void internal_147d6(void) {
    __asm__(START
        ".Ls5_147d6:\n"
        "jmp qword ptr [rip + rva_15148]\n" END);
}

/* 0x14830..0x1484e, Windows AMD64. */
NAKED void internal_14830(void) {
    __asm__(START
        ".Ls5_14830:\n"
        "cmp rcx, qword ptr [rip + rva_1e800]\n"
        "jne .Ls5_14849\n"
        "rol rcx, 0x10\n"
        "test cx, 0xffff\n"
        "jne .Ls5_14845\n"
        "ret\n"
        ".Ls5_14845:\n"
        "ror rcx, 0x10\n"
        ".Ls5_14849:\n"
        "jmp rva_14884\n" END);
}

/* 0x14850..0x14884, Windows AMD64. */
NAKED void internal_14850(void) {
    __asm__(START
        ".Ls5_14850:\n"
        ".byte 0x40\npush rbx\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rbx, rcx)
        S5_XOR32(ecx, ecx)
        "call qword ptr [rip + rva_15080]\n"
        S5_MOV64(rcx, rbx)
        "call qword ptr [rip + rva_15078]\n"
        "call qword ptr [rip + rva_15018]\n"
        S5_MOV64(rcx, rax)
        "mov edx, 0xc0000409\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48\njmp qword ptr [rip + rva_15000]\n" END);
}
