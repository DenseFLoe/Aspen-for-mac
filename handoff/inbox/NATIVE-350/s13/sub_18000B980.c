#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0xb980 through 0xbec3 (exclusive). */
__asm__(".globl rva_b980\n.set rva_b980, sub_18000B980\n");
NAKED void sub_18000B980(void) {
    __asm__(START
        "    push rsi\n" /* 0b980 */
        "    sub rsp, 0x40\n" /* 0b981 */
        "    mov rax, qword ptr [rsp + 0x70]\n" /* 0b985 */
        "    mov rdx, qword ptr [rip + data_rva_24290]\n" /* 0b98a */
        "    movsd xmm2, qword ptr [rax + rdx*8 - 8]\n" /* 0b991 */
        "    movsd qword ptr [rip + data_rva_22ba0], xmm2\n" /* 0b997 */
        "    mov rdx, qword ptr [rip + data_rva_24288]\n" /* 0b99f */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0b9a6 */
        "    movsd qword ptr [rip + data_rva_22ba8], xmm1\n" /* 0b9ac */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 0b9b4 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0b9bb */
        "    movsd qword ptr [rip + data_rva_22bb0], xmm0\n" /* 0b9bf */
        "    ucomisd xmm0, xmm2\n" /* 0b9c7 */
        "    jbe .Lblock_b9e1\n" /* 0b9cb */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 0b9cd */
        "    mulsd xmm2, qword ptr [rdx + 0x60]\n" /* 0b9d4 */
        "    movsd qword ptr [rip + data_rva_22ba0], xmm2\n" /* 0b9d9 */
        ".Lblock_b9e1:\n"
        "    ucomisd xmm0, xmm1\n" /* 0b9e1 */
        "    jbe .Lblock_b9fb\n" /* 0b9e5 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 0b9e7 */
        "    mulsd xmm1, qword ptr [rdx + 0x60]\n" /* 0b9ee */
        "    movsd qword ptr [rip + data_rva_22ba8], xmm1\n" /* 0b9f3 */
        ".Lblock_b9fb:\n"
        "    mov rdx, qword ptr [rip + data_rva_24258]\n" /* 0b9fb */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba02 */
        "    movsd qword ptr [rip + data_rva_22bb8], xmm1\n" /* 0ba08 */
        "    mov rdx, qword ptr [rip + data_rva_24260]\n" /* 0ba10 */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba17 */
        "    movsd qword ptr [rip + data_rva_22bc0], xmm1\n" /* 0ba1d */
        "    mov rdx, qword ptr [rip + data_rva_24268]\n" /* 0ba25 */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba2c */
        "    movsd qword ptr [rip + data_rva_22bc8], xmm1\n" /* 0ba32 */
        "    mov rdx, qword ptr [rip + data_rva_24270]\n" /* 0ba3a */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba41 */
        "    movsd qword ptr [rip + data_rva_22bd0], xmm1\n" /* 0ba47 */
        "    mov rdx, qword ptr [rip + data_rva_24278]\n" /* 0ba4f */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba56 */
        "    movsd qword ptr [rip + data_rva_22bd8], xmm1\n" /* 0ba5c */
        "    addsd xmm1, qword ptr [rip + rdata_rva_19550]\n" /* 0ba64 */
        "    movsd qword ptr [rip + data_rva_22be0], xmm1\n" /* 0ba6c */
        "    mov rdx, qword ptr [rip + data_rva_24248]\n" /* 0ba74 */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba7b */
        "    movsd qword ptr [rip + data_rva_22be8], xmm1\n" /* 0ba81 */
        "    mov rdx, qword ptr [rip + data_rva_24250]\n" /* 0ba89 */
        "    movsd xmm1, qword ptr [rax + rdx*8 - 8]\n" /* 0ba90 */
        "    movsd qword ptr [rip + data_rva_22bf0], xmm1\n" /* 0ba96 */
        "    movsd qword ptr [rip + data_rva_22bf8], xmm0\n" /* 0ba9e */
        "    mov rdx, qword ptr [rip + data_rva_24220]\n" /* 0baa6 */
        "    ucomisd xmm0, qword ptr [rax + rdx*8 - 8]\n" /* 0baad */
        "    jbe .Lblock_baca\n" /* 0bab3 */
        "    mov rdx, qword ptr [rip + data_rva_24280]\n" /* 0bab5 */
        "    movsd xmm0, qword ptr [rax + rdx*8 - 8]\n" /* 0babc */
        "    movsd qword ptr [rip + data_rva_22bf8], xmm0\n" /* 0bac2 */
        ".Lblock_baca:\n"
        "    mov rdx, qword ptr [rip + data_rva_242a8]\n" /* 0baca */
        "    movsd xmm0, qword ptr [rax + rdx*8 - 8]\n" /* 0bad1 */
        "    movsd qword ptr [rip + data_rva_22c00], xmm0\n" /* 0bad7 */
        "    call thunk_aphier_dll_APHIER_GETACHANDLE_rva_153d0\n" /* 0badf */
        "    mov qword ptr [rip + data_rva_22c08], rax\n" /* 0bae4 */
        "    test rax, rax\n" /* 0baeb */
        S9_JE32(.Lblock_bbd2) /* 0baee */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0baf4 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22ba0]\n" /* 0baf8 */
        S9_JA32(.Lblock_bc2a) /* 0bb00 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22ba8]\n" /* 0bb06 */
        S9_JA32(.Lblock_bc66) /* 0bb0e */
        ".Lblock_bb14:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bb8]\n" /* 0bb14 */
        S9_JA32(.Lblock_bca2) /* 0bb1c */
        ".Lblock_bb22:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bc0]\n" /* 0bb22 */
        S9_JA32(.Lblock_bcde) /* 0bb2a */
        ".Lblock_bb30:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bc8]\n" /* 0bb30 */
        S9_JA32(.Lblock_bd1a) /* 0bb38 */
        ".Lblock_bb3e:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bd0]\n" /* 0bb3e */
        S9_JA32(.Lblock_bd56) /* 0bb46 */
        ".Lblock_bb4c:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bd8]\n" /* 0bb4c */
        S9_JA32(.Lblock_bd92) /* 0bb54 */
        ".Lblock_bb5a:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22be0]\n" /* 0bb5a */
        S9_JA32(.Lblock_bdce) /* 0bb62 */
        ".Lblock_bb68:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22be8]\n" /* 0bb68 */
        S9_JA32(.Lblock_be0a) /* 0bb70 */
        ".Lblock_bb76:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bf0]\n" /* 0bb76 */
        S9_JA32(.Lblock_be46) /* 0bb7e */
        ".Lblock_bb84:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bf8]\n" /* 0bb84 */
        S9_JA32(.Lblock_be82) /* 0bb8c */
        ".Lblock_bb92:\n"
        "    ucomisd xmm0, qword ptr [rip + data_rva_22c00]\n" /* 0bb92 */
        "    jbe .Lblock_bbc6\n" /* 0bb9a */
        ".Lblock_bb9c:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bb9c */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bba5 */
        "    lea rdx, [rip + rdata_rva_198f0]\n" /* 0bbac */
        "    lea r8, [rip + data_rva_22c00]\n" /* 0bbb3 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bbba */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bbc1 */
        ".Lblock_bbc6:\n"
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bbc6 */
        "    call thunk_aphier_dll_AFRELEASE_rva_153dc\n" /* 0bbcd */
        ".Lblock_bbd2:\n"
        "    lea rax, [rip + rdata_rva_19b40]\n" /* 0bbd2 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 0bbd9 */
        "    lea rax, [rip + rdata_rva_19b38]\n" /* 0bbde */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 0bbe5 */
        "    lea rax, [rip + rdata_rva_19b30]\n" /* 0bbea */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0bbf1 */
        "    lea rax, [rip + data_rva_22ba0]\n" /* 0bbf6 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0bbfd */
        "    lea rcx, [rip + data_rva_21940]\n" /* 0bc02 */
        "    lea rdx, [rip + data_rva_218c0]\n" /* 0bc09 */
        "    lea r8, [rip + data_rva_21840]\n" /* 0bc10 */
        "    lea r9, [rip + data_rva_22c20]\n" /* 0bc17 */
        "    call thunk_zereport_dll_ZREP_SUMVEC_rva_15340\n" /* 0bc1e */
        "    nop\n" /* 0bc23 */
        "    add rsp, 0x40\n" /* 0bc24 */
        "    pop rsi\n" /* 0bc28 */
        "    ret\n" /* 0bc29 */
        ".Lblock_bc2a:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bc2a */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bc33 */
        "    lea rdx, [rip + rdata_rva_19b00]\n" /* 0bc3a */
        "    lea r8, [rip + data_rva_22ba0]\n" /* 0bc41 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bc48 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bc4f */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bc54 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22ba8]\n" /* 0bc58 */
        S9_JBE32(.Lblock_bb14) /* 0bc60 */
        ".Lblock_bc66:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bc66 */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bc6f */
        "    lea rdx, [rip + rdata_rva_19ad0]\n" /* 0bc76 */
        "    lea r8, [rip + data_rva_22ba8]\n" /* 0bc7d */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bc84 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bc8b */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bc90 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bb8]\n" /* 0bc94 */
        S9_JBE32(.Lblock_bb22) /* 0bc9c */
        ".Lblock_bca2:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bca2 */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bcab */
        "    lea rdx, [rip + rdata_rva_19aa0]\n" /* 0bcb2 */
        "    lea r8, [rip + data_rva_22bb8]\n" /* 0bcb9 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bcc0 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bcc7 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bccc */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bc0]\n" /* 0bcd0 */
        S9_JBE32(.Lblock_bb30) /* 0bcd8 */
        ".Lblock_bcde:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bcde */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bce7 */
        "    lea rdx, [rip + rdata_rva_19a70]\n" /* 0bcee */
        "    lea r8, [rip + data_rva_22bc0]\n" /* 0bcf5 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bcfc */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bd03 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bd08 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bc8]\n" /* 0bd0c */
        S9_JBE32(.Lblock_bb3e) /* 0bd14 */
        ".Lblock_bd1a:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bd1a */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bd23 */
        "    lea rdx, [rip + rdata_rva_19a40]\n" /* 0bd2a */
        "    lea r8, [rip + data_rva_22bc8]\n" /* 0bd31 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bd38 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bd3f */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bd44 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bd0]\n" /* 0bd48 */
        S9_JBE32(.Lblock_bb4c) /* 0bd50 */
        ".Lblock_bd56:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bd56 */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bd5f */
        "    lea rdx, [rip + rdata_rva_19a10]\n" /* 0bd66 */
        "    lea r8, [rip + data_rva_22bd0]\n" /* 0bd6d */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bd74 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bd7b */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bd80 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bd8]\n" /* 0bd84 */
        S9_JBE32(.Lblock_bb5a) /* 0bd8c */
        ".Lblock_bd92:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bd92 */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bd9b */
        "    lea rdx, [rip + rdata_rva_199e0]\n" /* 0bda2 */
        "    lea r8, [rip + data_rva_22bd8]\n" /* 0bda9 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bdb0 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bdb7 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bdbc */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22be0]\n" /* 0bdc0 */
        S9_JBE32(.Lblock_bb68) /* 0bdc8 */
        ".Lblock_bdce:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0bdce */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0bdd7 */
        "    lea rdx, [rip + rdata_rva_199b0]\n" /* 0bdde */
        "    lea r8, [rip + data_rva_22be0]\n" /* 0bde5 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bdec */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bdf3 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0bdf8 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22be8]\n" /* 0bdfc */
        S9_JBE32(.Lblock_bb76) /* 0be04 */
        ".Lblock_be0a:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0be0a */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0be13 */
        "    lea rdx, [rip + rdata_rva_19980]\n" /* 0be1a */
        "    lea r8, [rip + data_rva_22be8]\n" /* 0be21 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0be28 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0be2f */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0be34 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bf0]\n" /* 0be38 */
        S9_JBE32(.Lblock_bb84) /* 0be40 */
        ".Lblock_be46:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0be46 */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0be4f */
        "    lea rdx, [rip + rdata_rva_19950]\n" /* 0be56 */
        "    lea r8, [rip + data_rva_22bf0]\n" /* 0be5d */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0be64 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0be6b */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0be70 */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22bf8]\n" /* 0be74 */
        S9_JBE32(.Lblock_bb92) /* 0be7c */
        ".Lblock_be82:\n"
        "    mov qword ptr [rsp + 0x20], 0x26\n" /* 0be82 */
        "    lea rcx, [rip + data_rva_22c08]\n" /* 0be8b */
        "    lea rdx, [rip + rdata_rva_19920]\n" /* 0be92 */
        "    lea r8, [rip + data_rva_22bf8]\n" /* 0be99 */
        "    lea r9, [rip + rdata_rva_19b28]\n" /* 0bea0 */
        "    call thunk_aphier_dll_AFSETVAL_rva_153d6\n" /* 0bea7 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 0beac */
        "    ucomisd xmm0, qword ptr [rip + data_rva_22c00]\n" /* 0beb0 */
        S9_JA32(.Lblock_bb9c) /* 0beb8 */
        S9_JMP32(.Lblock_bbc6) /* 0bebe */
        END);
}
