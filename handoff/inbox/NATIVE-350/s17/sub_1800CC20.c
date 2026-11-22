#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0xcc20 through 0xccae (exclusive). */
__asm__(".globl rva_cc20\n.set rva_cc20, sub_1800CC20\n");
NAKED void sub_1800CC20(void) {
    __asm__(START
        "    push rsi\n" /* 0cc20 */
        "    push rdi\n" /* 0cc21 */
        "    push rbx\n" /* 0cc22 */
        "    sub rsp, 0x20\n" /* 0cc23 */
        ".Lblock_cc27:\n"
        "    mov rax, qword ptr [rip + data_rva_22d30]\n" /* 0cc27 */
        "    test rax, rax\n" /* 0cc2e */
        "    jne .Lblock_cc3a\n" /* 0cc31 */
        "    call sub_180011080_rva_11080\n" /* 0cc33 */
        "    jmp .Lblock_cc27\n" /* 0cc38 */
        ".Lblock_cc3a:\n"
        "    mov r9, rax\n" /* 0cc3a */
        "    not r9\n" /* 0cc3d */
        "    movabs r10, 0x7189d9fee\n" /* 0cc40 */
        "    test r9, r10\n" /* 0cc4a */
        "    jne .Lblock_cc5f\n" /* 0cc4d */
        "    mov rsi, r8\n" /* 0cc4f */
        "    mov rbx, rdx\n" /* 0cc52 */
        "    mov rdi, rcx\n" /* 0cc55 */
        "    call sub_18000CBF0_rva_cbf0\n" /* 0cc58 */
        "    jmp .Lblock_cc7c\n" /* 0cc5d */
        ".Lblock_cc5f:\n"
        "    mov r9d, eax\n" /* 0cc5f */
        "    not r9d\n" /* 0cc62 */
        "    test r9d, 0x9d9fee\n" /* 0cc65 */
        "    jne .Lblock_cc87\n" /* 0cc6c */
        "    mov rsi, r8\n" /* 0cc6e */
        "    mov rbx, rdx\n" /* 0cc71 */
        "    mov rdi, rcx\n" /* 0cc74 */
        "    call sub_18000CBE0_rva_cbe0\n" /* 0cc77 */
        ".Lblock_cc7c:\n"
        "    mov rcx, rdi\n" /* 0cc7c */
        "    mov rdx, rbx\n" /* 0cc7f */
        "    mov r8, rsi\n" /* 0cc82 */
        "    jmp .Lblock_cc9d\n" /* 0cc85 */
        ".Lblock_cc87:\n"
        "    not eax\n" /* 0cc87 */
        "    test al, 0x6e\n" /* 0cc89 */
        "    lea r9, [rip + text_rva_16560]\n" /* 0cc8b */
        "    lea rax, [rip + text_rva_18084]\n" /* 0cc92 */
        "    cmove rax, r9\n" /* 0cc99 */
        ".Lblock_cc9d:\n"
        "    mov qword ptr [rip + data_rva_22d10], rax\n" /* 0cc9d */
        "    add rsp, 0x20\n" /* 0cca4 */
        "    pop rbx\n" /* 0cca8 */
        "    pop rdi\n" /* 0cca9 */
        "    pop rsi\n" /* 0ccaa */
        ".byte 0x48\n        jmp rax\n" /* 0ccab */
        END);
}
