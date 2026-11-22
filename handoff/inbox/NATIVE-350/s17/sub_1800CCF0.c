#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0xccf0 through 0xcd7b (exclusive). */
__asm__(".globl rva_ccf0\n.set rva_ccf0, sub_1800CCF0\n");
NAKED void sub_1800CCF0(void) {
    __asm__(START
        "    push rsi\n" /* 0ccf0 */
        "    push rdi\n" /* 0ccf1 */
        "    push rbx\n" /* 0ccf2 */
        "    sub rsp, 0x20\n" /* 0ccf3 */
        ".Lblock_ccf7:\n"
        "    mov rax, qword ptr [rip + data_rva_22d30]\n" /* 0ccf7 */
        "    test rax, rax\n" /* 0ccfe */
        "    jne .Lblock_cd0a\n" /* 0cd01 */
        "    call sub_180011080_rva_11080\n" /* 0cd03 */
        "    jmp .Lblock_ccf7\n" /* 0cd08 */
        ".Lblock_cd0a:\n"
        "    mov r9, rax\n" /* 0cd0a */
        "    not r9\n" /* 0cd0d */
        "    movabs r10, 0x7189d9fee\n" /* 0cd10 */
        "    test r9, r10\n" /* 0cd1a */
        "    jne .Lblock_cd2e\n" /* 0cd1d */
        "    mov rsi, r8\n" /* 0cd1f */
        "    mov ebx, edx\n" /* 0cd22 */
        "    mov rdi, rcx\n" /* 0cd24 */
        "    call sub_18000CCC0_rva_ccc0\n" /* 0cd27 */
        "    jmp .Lblock_cd4a\n" /* 0cd2c */
        ".Lblock_cd2e:\n"
        "    mov r9d, eax\n" /* 0cd2e */
        "    not r9d\n" /* 0cd31 */
        "    test r9d, 0x9d9fee\n" /* 0cd34 */
        "    jne .Lblock_cd54\n" /* 0cd3b */
        "    mov rsi, r8\n" /* 0cd3d */
        "    mov ebx, edx\n" /* 0cd40 */
        "    mov rdi, rcx\n" /* 0cd42 */
        "    call sub_18000CCB0_rva_ccb0\n" /* 0cd45 */
        ".Lblock_cd4a:\n"
        "    mov rcx, rdi\n" /* 0cd4a */
        "    mov edx, ebx\n" /* 0cd4d */
        "    mov r8, rsi\n" /* 0cd4f */
        "    jmp .Lblock_cd6a\n" /* 0cd52 */
        ".Lblock_cd54:\n"
        "    not eax\n" /* 0cd54 */
        "    test al, 0x6e\n" /* 0cd56 */
        "    lea r9, [rip + text_rva_17610]\n" /* 0cd58 */
        "    lea rax, [rip + text_rva_1807e]\n" /* 0cd5f */
        "    cmove rax, r9\n" /* 0cd66 */
        ".Lblock_cd6a:\n"
        "    mov qword ptr [rip + data_rva_22d18], rax\n" /* 0cd6a */
        "    add rsp, 0x20\n" /* 0cd71 */
        "    pop rbx\n" /* 0cd75 */
        "    pop rdi\n" /* 0cd76 */
        "    pop rsi\n" /* 0cd77 */
        ".byte 0x48\n        jmp rax\n" /* 0cd78 */
        END);
}
