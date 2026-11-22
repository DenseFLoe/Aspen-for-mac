#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0x2640 through 0x78a6 (exclusive). */
__asm__(".globl rva_2640\n.set rva_2640, sub_180002640\n");
NAKED void sub_180002640(void) {
    __asm__(START
        "    push r15\n" /* 02640 */
        "    push r14\n" /* 02642 */
        "    push r13\n" /* 02644 */
        "    push r12\n" /* 02646 */
        "    push rsi\n" /* 02648 */
        "    push rdi\n" /* 02649 */
        "    push rbp\n" /* 0264a */
        "    push rbx\n" /* 0264b */
        "    sub rsp, 0x698\n" /* 0264c */
        "    movapd xmmword ptr [rsp + 0x680], xmm15\n" /* 02653 */
        "    movapd xmmword ptr [rsp + 0x670], xmm14\n" /* 0265d */
        "    movapd xmmword ptr [rsp + 0x660], xmm13\n" /* 02667 */
        "    movapd xmmword ptr [rsp + 0x650], xmm12\n" /* 02671 */
        "    movapd xmmword ptr [rsp + 0x640], xmm11\n" /* 0267b */
        "    movapd xmmword ptr [rsp + 0x630], xmm10\n" /* 02685 */
        "    movapd xmmword ptr [rsp + 0x620], xmm9\n" /* 0268f */
        "    movapd xmmword ptr [rsp + 0x610], xmm8\n" /* 02699 */
        "    movapd xmmword ptr [rsp + 0x600], xmm7\n" /* 026a3 */
        "    movapd xmmword ptr [rsp + 0x5f0], xmm6\n" /* 026ac */
        "    mov rbp, r8\n" /* 026b5 */
        "    mov r12, rcx\n" /* 026b8 */
        "    mov rsi, qword ptr [rsp + 0x728]\n" /* 026bb */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 026c3 */
        "    mov r9, qword ptr [rsp + 0x710]\n" /* 026cb */
        "    mov r8, qword ptr [rsp + 0x700]\n" /* 026d3 */
        "    mov rax, qword ptr [rsp + 0x798]\n" /* 026db */
        "    mov rcx, qword ptr [rsp + 0x788]\n" /* 026e3 */
        "    mov r11, qword ptr [rcx]\n" /* 026eb */
        "    mov rdi, qword ptr [rax]\n" /* 026ee */
        "    mov qword ptr [rip + data_rva_22520], 0\n" /* 026f1 */
        "    mov r10, qword ptr [rip + iat_atdms_dll_DMS_NCOMP_rva_19218]\n" /* 026fc */
        "    mov rax, qword ptr [r10]\n" /* 02703 */
        "    lea rcx, [rax + 1]\n" /* 02706 */
        "    mov qword ptr [rip + data_rva_227a0], rcx\n" /* 0270a */
        "    lea rcx, [rax + 2]\n" /* 02711 */
        "    mov qword ptr [rip + data_rva_22798], rcx\n" /* 02715 */
        "    lea rcx, [rax + 4]\n" /* 0271c */
        "    mov qword ptr [rip + data_rva_22790], rcx\n" /* 02720 */
        "    lea rcx, [rax + 5]\n" /* 02727 */
        "    mov qword ptr [rip + data_rva_22788], rcx\n" /* 0272b */
        "    lea rcx, [rax + 6]\n" /* 02732 */
        "    mov qword ptr [rip + data_rva_22780], rcx\n" /* 02736 */
        "    lea rcx, [rax + 9]\n" /* 0273d */
        "    mov qword ptr [rip + data_rva_22778], rcx\n" /* 02741 */
        "    mov rcx, qword ptr [rip + data_rva_241e8]\n" /* 02748 */
        "    movsd xmm0, qword ptr [r8 + rcx*8 - 8]\n" /* 0274f */
        "    movsd qword ptr [rip + data_rva_22518], xmm0\n" /* 02756 */
        "    mov rcx, qword ptr [rip + data_rva_241f0]\n" /* 0275e */
        "    movsd xmm0, qword ptr [r8 + rcx*8 - 8]\n" /* 02765 */
        "    movsd qword ptr [rip + data_rva_22510], xmm0\n" /* 0276c */
        "    mov qword ptr [rip + data_rva_22618], 0\n" /* 02774 */
        "    mov qword ptr [rip + data_rva_22610], 0\n" /* 0277f */
        "    mov rcx, qword ptr [rip + data_rva_24218]\n" /* 0278a */
        "    movsd xmm0, qword ptr [r8 + rcx*8 - 8]\n" /* 02791 */
        "    movsd qword ptr [rip + data_rva_22508], xmm0\n" /* 02798 */
        "    mov rcx, qword ptr [rip + data_rva_24200]\n" /* 027a0 */
        "    movsd xmm1, qword ptr [r8 + rcx*8 - 8]\n" /* 027a7 */
        "    movsd qword ptr [rip + data_rva_22608], xmm1\n" /* 027ae */
        "    mov rcx, qword ptr [rip + data_rva_24208]\n" /* 027b6 */
        "    movsd xmm2, qword ptr [r8 + rcx*8 - 8]\n" /* 027bd */
        "    movsd qword ptr [rip + data_rva_22600], xmm2\n" /* 027c4 */
        "    mov rcx, qword ptr [rip + data_rva_24210]\n" /* 027cc */
        "    movsd xmm0, qword ptr [r8 + rcx*8 - 8]\n" /* 027d3 */
        "    movsd qword ptr [rip + data_rva_22500], xmm0\n" /* 027da */
        "    mov rcx, qword ptr [rip + data_rva_24228]\n" /* 027e2 */
        "    movsd xmm0, qword ptr [r8 + rcx*8 - 8]\n" /* 027e9 */
        "    addsd xmm2, xmm1\n" /* 027f0 */
        "    divsd xmm2, qword ptr [rip + rdata_rva_196a0]\n" /* 027f4 */
        "    movsd qword ptr [rip + data_rva_225f8], xmm0\n" /* 027fc */
        "    movsd qword ptr [rip + data_rva_225f0], xmm2\n" /* 02804 */
        "    mov rcx, qword ptr [rip + data_rva_242b8]\n" /* 0280c */
        "    mov rcx, qword ptr [r9 + rcx*8 - 8]\n" /* 02813 */
        "    mov qword ptr [rip + data_rva_22558], rcx\n" /* 02818 */
        "    mov rcx, qword ptr [rip + data_rva_242c0]\n" /* 0281f */
        "    mov rcx, qword ptr [r9 + rcx*8 - 8]\n" /* 02826 */
        "    mov qword ptr [rip + data_rva_22550], rcx\n" /* 0282b */
        "    mov rcx, qword ptr [rip + data_rva_24248]\n" /* 02832 */
        "    movsd xmm1, qword ptr [r8 + rcx*8 - 8]\n" /* 02839 */
        "    movsd qword ptr [rip + data_rva_225e8], xmm1\n" /* 02840 */
        "    mov rcx, qword ptr [rip + data_rva_24250]\n" /* 02848 */
        "    movsd xmm1, qword ptr [r8 + rcx*8 - 8]\n" /* 0284f */
        "    movsd qword ptr [rip + data_rva_225e0], xmm1\n" /* 02856 */
        "    mov qword ptr [rip + data_rva_22770], 2\n" /* 0285e */
        "    mov rcx, qword ptr [r15 + 0x70]\n" /* 02869 */
        "    lea rcx, [rcx + rcx*4]\n" /* 0286d */
        "    lea rcx, [rcx + rcx + 2]\n" /* 02871 */
        "    mov qword ptr [rip + data_rva_22768], rcx\n" /* 02876 */
        "    mov rcx, qword ptr [rip + data_rva_242d0]\n" /* 0287d */
        "    mov rcx, qword ptr [r9 + rcx*8 - 8]\n" /* 02884 */
        "    mov qword ptr [rip + data_rva_22760], rcx\n" /* 02889 */
        "    mov rcx, qword ptr [rip + data_rva_242e0]\n" /* 02890 */
        "    mov rcx, qword ptr [r9 + rcx*8 - 8]\n" /* 02897 */
        "    mov qword ptr [rip + data_rva_22548], rcx\n" /* 0289c */
        "    mov rcx, qword ptr [rip + data_rva_24230]\n" /* 028a3 */
        "    movsd xmm1, qword ptr [r8 + rcx*8 - 8]\n" /* 028aa */
        "    movsd qword ptr [rip + data_rva_225d8], xmm1\n" /* 028b1 */
        "    mov rcx, qword ptr [rip + data_rva_24238]\n" /* 028b9 */
        "    movsd xmm1, qword ptr [r8 + rcx*8 - 8]\n" /* 028c0 */
        "    movsd qword ptr [rip + data_rva_224f8], xmm1\n" /* 028c7 */
        "    mov rcx, qword ptr [rip + data_rva_24240]\n" /* 028cf */
        "    movsd xmm1, qword ptr [r8 + rcx*8 - 8]\n" /* 028d6 */
        "    movsd qword ptr [rip + data_rva_224f0], xmm1\n" /* 028dd */
        "    mov rcx, qword ptr [rip + data_rva_242c8]\n" /* 028e5 */
        "    mov rcx, qword ptr [r9 + rcx*8 - 8]\n" /* 028ec */
        "    mov qword ptr [rip + data_rva_22758], rcx\n" /* 028f1 */
        "    mov qword ptr [rip + data_rva_22750], 3\n" /* 028f8 */
        "    mov rcx, qword ptr [r15 + 0x28]\n" /* 02903 */
        "    mov qword ptr [rip + data_rva_22748], rcx\n" /* 02907 */
        "    mov qword ptr [rip + data_rva_22740], 0\n" /* 0290e */
        "    mov rbx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 02919 */
        "    lea rcx, [rax + rax]\n" /* 02920 */
        "    lea r9, [rax*4]\n" /* 02924 */
        "    xor r8d, r8d\n" /* 0292c */
        "    cmp qword ptr [rbx + 0x100], 2\n" /* 0292f */
        "    setge r8b\n" /* 02937 */
        "    mov qword ptr [rip + data_rva_22738], r8\n" /* 0293b */
        "    mov qword ptr [rip + data_rva_22730], 1\n" /* 02942 */
        "    mov qword ptr [rip + data_rva_22728], rcx\n" /* 0294d */
        "    lea rcx, [rax + rax*2]\n" /* 02954 */
        "    mov qword ptr [rip + data_rva_22720], rcx\n" /* 02958 */
        "    mov qword ptr [rip + data_rva_22718], r9\n" /* 0295f */
        "    lea rcx, [rax + rax*4]\n" /* 02966 */
        "    mov qword ptr [rip + data_rva_22710], rcx\n" /* 0296a */
        S9_JNE32(.Lblock_2b49) /* 02971 */
        ".Lblock_2977:\n"
        "    xorpd xmm1, xmm1\n" /* 02977 */
        "    ucomisd xmm0, xmm1\n" /* 0297b */
        "    setnp dl\n" /* 0297f */
        "    sete r8b\n" /* 02982 */
        "    ucomisd xmm0, qword ptr [rip + rdata_rva_19550]\n" /* 02986 */
        "    setnp al\n" /* 0298e */
        "    sete cl\n" /* 02991 */
        "    test r8b, dl\n" /* 02994 */
        S9_JNE32(.Lblock_58f9) /* 02997 */
        "    and cl, al\n" /* 0299d */
        S9_JNE32(.Lblock_58f9) /* 0299f */
        "    mov rax, qword ptr [r10]\n" /* 029a5 */
        "    movsd xmm0, qword ptr [rbp + rax*8 + 8]\n" /* 029a8 */
        "    movsd qword ptr [rip + data_rva_225e8], xmm0\n" /* 029ae */
        "    mov r12, rsi\n" /* 029b6 */
        "    lea rbx, [rip + data_rva_225e8]\n" /* 029b9 */
        "    movsd xmm0, qword ptr [rbp + rax*8 + 0x10]\n" /* 029c0 */
        "    movsd qword ptr [rip + data_rva_22608], xmm0\n" /* 029c6 */
        "    lea r14, [rip + data_rva_22608]\n" /* 029ce */
        "    mov qword ptr [rip + data_rva_22750], 2\n" /* 029d5 */
        "    lea rsi, [rip + data_rva_22750]\n" /* 029e0 */
        /* Open the property workspace for the DMS_GLOBAL + 0x100 == 2 branch. */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 029e7 */
        "    lea rax, [r15 + 8]\n" /* 029ec */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 029f0 */
        "    mov rdx, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 029f7 */
        "    mov r8, qword ptr [rdx + 0xc0]\n" /* 029fe */
        "    mov rdx, qword ptr [rdx + 0xe8]\n" /* 02a05 */
        "    add r8, qword ptr [rcx]\n" /* 02a0c */
        "    mov r9, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 02a0f */
        "    lea r8, [r9 + r8*8]\n" /* 02a16 */
        "    add r8, -8\n" /* 02a1a */
        "    add rdx, qword ptr [rcx + 8]\n" /* 02a1e */
        "    lea rcx, [r9 + rdx*8]\n" /* 02a22 */
        "    add rcx, -8\n" /* 02a26 */
        "    lea rdi, [rip + data_rva_226e8]\n" /* 02a2a */
        "    mov qword ptr [rsp + 0x98], rdi\n" /* 02a31 */
        "    mov qword ptr [rsp + 0x90], rcx\n" /* 02a39 */
        "    mov qword ptr [rsp + 0x88], r8\n" /* 02a41 */
        "    lea rcx, [rip + data_rva_22738]\n" /* 02a49 */
        "    mov qword ptr [rsp + 0x80], rcx\n" /* 02a50 */
        "    lea rcx, [rip + data_rva_226d8]\n" /* 02a58 */
        "    mov qword ptr [rsp + 0x78], rcx\n" /* 02a5f */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 02a64 */
        "    lea rax, [rip + data_rva_226f8]\n" /* 02a69 */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 02a70 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 02a75 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 02a7c */
        "    mov qword ptr [rsp + 0x58], r14\n" /* 02a81 */
        "    mov qword ptr [rsp + 0x50], rbx\n" /* 02a86 */
        "    lea rax, [rip + data_rva_225d8]\n" /* 02a8b */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 02a92 */
        "    lea rax, [rip + data_rva_22760]\n" /* 02a97 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 02a9e */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 02aa3 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 02aaa */
        "    lea rax, [rip + data_rva_22768]\n" /* 02aaf */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 02ab6 */
        "    mov qword ptr [rsp + 0x28], rsi\n" /* 02abb */
        "    mov qword ptr [rsp + 0x20], r12\n" /* 02ac0 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 02ac5 */
        "    mov rcx, rbp\n" /* 02acc */
        "    mov r8, rdx\n" /* 02acf */
        "    mov r9, rdx\n" /* 02ad2 */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 02ad5 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 02ada */
        "    mov rdx, rdi\n" /* 02ae1 */
        /* Save and check the flash status before choosing a message and exit path. */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 02ae4 */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 02ae9 */
        "    cmp rax, 1\n" /* 02af0 */
        S9_JNE32(.Lblock_3435) /* 02af4 */
        "    mov r8d, 0xb0\n" /* 02afa */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 02b00 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 02b07 */
        "    lea rdx, [rip + data_rva_1f1e0]\n" /* 02b0e */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 02b15 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 02b1a */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 02b21 */
        "    lea r8, [rip + rdata_rva_19810]\n" /* 02b28 */
        "    mov r9, r15\n" /* 02b2f */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 02b32 */
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffff4\n" /* 02b37 */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 02b3f */
        S9_JMP32(.Lblock_58f9) /* 02b44 */
        ".Lblock_2b49:\n"
        "    mov qword ptr [rip + data_rva_22708], 0\n" /* 02b49 */
        "    mov qword ptr [rip + data_rva_22700], 0\n" /* 02b54 */
        "    movsd xmm2, qword ptr [r12 + rax*8 + 0x18]\n" /* 02b5f */
        "    movsd qword ptr [rip + data_rva_224e8], xmm2\n" /* 02b66 */
        "    movsd xmm0, qword ptr [r12 + rax*8 + 8]\n" /* 02b6e */
        "    movsd qword ptr [rip + data_rva_225d0], xmm0\n" /* 02b75 */
        "    movsd xmm1, qword ptr [r12 + rax*8 + 0x20]\n" /* 02b7d */
        "    movsd qword ptr [rip + data_rva_224e0], xmm1\n" /* 02b84 */
        "    mulsd xmm2, qword ptr [r12 + rax*8 + 0x40]\n" /* 02b8c */
        "    movsd qword ptr [rip + data_rva_224d8], xmm2\n" /* 02b93 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 02b9b */
        "    movsd xmm2, qword ptr [rax]\n" /* 02ba2 */
        "    ucomisd xmm0, xmm2\n" /* 02ba6 */
        "    jb .Lblock_2bc5\n" /* 02baa */
        "    movabs rax, 0x4072c00000000000\n" /* 02bac */
        "    mov qword ptr [rip + data_rva_225d0], rax\n" /* 02bb6 */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196a8]\n" /* 02bbd */
        ".Lblock_2bc5:\n"
        "    ucomisd xmm1, xmm2\n" /* 02bc5 */
        "    jb .Lblock_2be4\n" /* 02bc9 */
        "    movabs rax, 0x3fe0000000000000\n" /* 02bcb */
        "    mov qword ptr [rip + data_rva_224e0], rax\n" /* 02bd5 */
        "    movsd xmm1, qword ptr [rip + rdata_rva_19548]\n" /* 02bdc */
        ".Lblock_2be4:\n"
        "    mov qword ptr [rsp + 0x110], rdi\n" /* 02be4 */
        "    mov qword ptr [rsp + 0x118], r11\n" /* 02bec */
        "    mov qword ptr [rsp + 0xb0], rdx\n" /* 02bf4 */
        "    mov r14, qword ptr [rsp + 0x7a0]\n" /* 02bfc */
        "    movabs rdi, 0x801208384ff00\n" /* 02c04 */
        "    movsd qword ptr [rip + data_rva_224d0], xmm0\n" /* 02c0e */
        "    movsd qword ptr [rip + data_rva_224c8], xmm1\n" /* 02c16 */
        "    mov rax, qword ptr [r15]\n" /* 02c1e */
        "    dec rax\n" /* 02c21 */
        "    mov qword ptr [rip + data_rva_226f8], rax\n" /* 02c24 */
        "    mov qword ptr [rip + data_rva_226f0], 1\n" /* 02c2b */
        "    mov qword ptr [rip + data_rva_225c8], 0\n" /* 02c36 */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 02c41 */
        "    cmp qword ptr [rip + data_rva_226f8], 4\n" /* 02c46 */
        "    jl .Lblock_2c96\n" /* 02c4e */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 02c50 */
        "    mov edx, dword ptr [rbx + 0x20]\n" /* 02c5c */
        "    mov word ptr [rsp + 0x10e], 1\n" /* 02c5f */
        "    lea rax, [rip + data_rva_1f6a4]\n" /* 02c69 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 02c70 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 02c75 */
        "    lea rcx, [rsp + 0xd0]\n" /* 02c7e */
        "    lea r9, [rsp + 0x10e]\n" /* 02c86 */
        "    mov r8, rdi\n" /* 02c8e */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 02c91 */
        ".Lblock_2c96:\n"
        "    mov rdx, qword ptr [rsp + 0x7b8]\n" /* 02c96 */
        "    mov r13, qword ptr [rsp + 0x730]\n" /* 02c9e */
        "    lea rcx, [r15 + 8]\n" /* 02ca6 */
        "    lea rax, [rip + data_rva_226e8]\n" /* 02caa */
        "    mov qword ptr [rsp + 0x98], rax\n" /* 02cb1 */
        "    mov qword ptr [rsp + 0x90], r14\n" /* 02cb9 */
        "    mov rax, qword ptr [rsp + 0x790]\n" /* 02cc1 */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 02cc9 */
        "    lea rax, [rip + data_rva_22730]\n" /* 02cd1 */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 02cd8 */
        "    lea rax, [rip + data_rva_22748]\n" /* 02ce0 */
        "    mov qword ptr [rsp + 0x78], rax\n" /* 02ce7 */
        "    mov qword ptr [rsp + 0xc8], rcx\n" /* 02cec */
        "    mov qword ptr [rsp + 0x70], rcx\n" /* 02cf4 */
        "    lea rax, [rip + data_rva_226f8]\n" /* 02cf9 */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 02d00 */
        "    lea rax, [rip + data_rva_225d0]\n" /* 02d05 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 02d0c */
        "    lea rax, [rip + data_rva_225c8]\n" /* 02d11 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 02d18 */
        "    lea rax, [rip + data_rva_225f0]\n" /* 02d1d */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 02d24 */
        "    lea rax, [rip + data_rva_225d8]\n" /* 02d29 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 02d30 */
        "    lea rax, [rip + data_rva_22760]\n" /* 02d35 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 02d3c */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 02d41 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 02d48 */
        "    lea rax, [rip + data_rva_22770]\n" /* 02d4d */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 02d54 */
        "    lea rax, [rip + data_rva_226f0]\n" /* 02d59 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 02d60 */
        "    mov qword ptr [rsp + 0x20], rsi\n" /* 02d65 */
        "    mov rsi, rdx\n" /* 02d6a */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 02d6d */
        "    mov rcx, r12\n" /* 02d74 */
        "    mov r8, rdx\n" /* 02d77 */
        "    mov r9, rdx\n" /* 02d7a */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 02d7d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 02d82 */
        "    mov rdi, qword ptr [rax + 0x10]\n" /* 02d89 */
        "    mov qword ptr [rip + data_rva_226e0], rdi\n" /* 02d8d */
        "    test rdi, rdi\n" /* 02d94 */
        S9_JLE32(.Lblock_2ee2) /* 02d97 */
        "    mov rsi, rbp\n" /* 02d9d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 02da0 */
        "    mov rcx, qword ptr [rax]\n" /* 02da7 */
        "    mov rbp, qword ptr [rax + 8]\n" /* 02daa */
        "    mov rax, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 02dae */
        "    mov rdx, qword ptr [rax + 0x70]\n" /* 02db5 */
        "    mov r15, qword ptr [rax + 0xc8]\n" /* 02db9 */
        "    mov rbx, qword ptr [rip + data_rva_22558]\n" /* 02dc0 */
        "    mov r14, qword ptr [rip + data_rva_22550]\n" /* 02dc7 */
        "    cmp rdi, 0xc\n" /* 02dce */
        S9_JBE32(.Lblock_2e68) /* 02dd2 */
        "    add rcx, rdx\n" /* 02dd8 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 02ddb */
        "    lea rdx, [rax + rcx*8]\n" /* 02de2 */
        "    add rdx, -8\n" /* 02de6 */
        "    lea r8, [rdi*8]\n" /* 02dea */
        "    mov rcx, r13\n" /* 02df2 */
        /* The property-workspace path reaches the separate indirect dispatch helper. */
        "    call sub_18000CC00_rva_cc00\n" /* 02df5 */
        "    add r15, rbp\n" /* 02dfa */
        "    mov rax, rdi\n" /* 02dfd */
        "    neg rax\n" /* 02e00 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 02e03 */
        "    lea rcx, [rcx + r15*8]\n" /* 02e0a */
        "    mov edx, 1\n" /* 02e0e */
        "    mov rbp, rsi\n" /* 02e13 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 02e16 */
        "    mov rsi, qword ptr [rsp + 0x7b8]\n" /* 02e1e */
        "    jmp .Lblock_2e44\n" /* 02e26 */
        S9_NOP8 /* 02e28 */
        ".Lblock_2e30:\n"
        "    lea r8, [rax + rdx]\n" /* 02e30 */
        "    inc r8\n" /* 02e34 */
        "    inc rdx\n" /* 02e37 */
        "    cmp r8, 1\n" /* 02e3a */
        S9_JE32(.Lblock_2ee2) /* 02e3e */
        ".Lblock_2e44:\n"
        "    mov r8, qword ptr [rcx + rdx*8 - 0x10]\n" /* 02e44 */
        "    mov qword ptr [rsi + rdx*8 - 8], r8\n" /* 02e49 */
        "    cmp r8, rbx\n" /* 02e4e */
        "    jne .Lblock_2e5a\n" /* 02e51 */
        "    mov qword ptr [rip + data_rva_22708], rdx\n" /* 02e53 */
        ".Lblock_2e5a:\n"
        "    cmp r8, r14\n" /* 02e5a */
        "    jne .Lblock_2e30\n" /* 02e5d */
        "    mov qword ptr [rip + data_rva_22700], rdx\n" /* 02e5f */
        "    jmp .Lblock_2e30\n" /* 02e66 */
        ".Lblock_2e68:\n"
        "    add r15, rbp\n" /* 02e68 */
        "    mov rax, rdi\n" /* 02e6b */
        "    neg rax\n" /* 02e6e */
        "    add rdx, rcx\n" /* 02e71 */
        "    mov r8, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 02e74 */
        "    lea rcx, [r8 + rdx*8]\n" /* 02e7b */
        "    lea rdx, [r8 + r15*8]\n" /* 02e7f */
        "    mov r8d, 1\n" /* 02e83 */
        "    mov rbp, rsi\n" /* 02e89 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 02e8c */
        "    mov rsi, qword ptr [rsp + 0x7b8]\n" /* 02e94 */
        "    jmp .Lblock_2eb0\n" /* 02e9c */
        S9_NOP2 /* 02e9e */
        ".Lblock_2ea0:\n"
        "    lea r9, [rax + r8]\n" /* 02ea0 */
        "    inc r9\n" /* 02ea4 */
        "    inc r8\n" /* 02ea7 */
        "    cmp r9, 1\n" /* 02eaa */
        "    je .Lblock_2ee2\n" /* 02eae */
        ".Lblock_2eb0:\n"
        "    mov r9, qword ptr [rdx + r8*8 - 0x10]\n" /* 02eb0 */
        "    mov qword ptr [rsi + r8*8 - 8], r9\n" /* 02eb5 */
        "    movsd xmm0, qword ptr [rcx + r8*8 - 0x10]\n" /* 02eba */
        "    movsd qword ptr [r13 + r8*8 - 8], xmm0\n" /* 02ec1 */
        "    cmp r9, rbx\n" /* 02ec8 */
        "    jne .Lblock_2ed4\n" /* 02ecb */
        "    mov qword ptr [rip + data_rva_22708], r8\n" /* 02ecd */
        ".Lblock_2ed4:\n"
        "    cmp r9, r14\n" /* 02ed4 */
        "    jne .Lblock_2ea0\n" /* 02ed7 */
        "    mov qword ptr [rip + data_rva_22700], r8\n" /* 02ed9 */
        "    jmp .Lblock_2ea0\n" /* 02ee0 */
        ".Lblock_2ee2:\n"
        "    mov r8, qword ptr [rsp + 0x7b0]\n" /* 02ee2 */
        "    mov r9, qword ptr [rsp + 0x7a8]\n" /* 02eea */
        "    mov rdx, qword ptr [rsp + 0x758]\n" /* 02ef2 */
        "    mov r10, qword ptr [rsp + 0x740]\n" /* 02efa */
        "    mov r11, qword ptr [rsp + 0x738]\n" /* 02f02 */
        "    mov rax, qword ptr [r15 + 0x28]\n" /* 02f0a */
        "    cmp rdi, qword ptr [rip + data_rva_22548]\n" /* 02f0e */
        "    je .Lblock_2f32\n" /* 02f15 */
        "    cmp rax, 2\n" /* 02f17 */
        "    jne .Lblock_2f32\n" /* 02f1b */
        "    mov qword ptr [r15 + 0x28], 1\n" /* 02f1d */
        "    mov qword ptr [rip + data_rva_22748], 1\n" /* 02f25 */
        "    jmp .Lblock_2f6b\n" /* 02f30 */
        ".Lblock_2f32:\n"
        "    test rdi, rdi\n" /* 02f32 */
        "    jle .Lblock_2f6b\n" /* 02f35 */
        "    cmp rax, 2\n" /* 02f37 */
        "    jne .Lblock_2f6b\n" /* 02f3b */
        "    xor eax, eax\n" /* 02f3d */
        "    nop\n" /* 02f3f */
        ".Lblock_2f40:\n"
        "    mov rcx, qword ptr [rsi + rax*8]\n" /* 02f40 */
        "    movsd xmm0, qword ptr [r9 + rcx*8 - 8]\n" /* 02f44 */
        "    movsd qword ptr [rdx + rax*8], xmm0\n" /* 02f4b */
        "    movsd xmm0, qword ptr [r8 + rcx*8 - 8]\n" /* 02f50 */
        "    movsd qword ptr [r10 + rax*8], xmm0\n" /* 02f57 */
        "    movsd qword ptr [r11 + rax*8], xmm0\n" /* 02f5d */
        "    inc rax\n" /* 02f63 */
        "    cmp rax, rdi\n" /* 02f66 */
        "    jl .Lblock_2f40\n" /* 02f69 */
        ".Lblock_2f6b:\n"
        "    lea r14, [rip + rdata_rva_19840]\n" /* 02f6b */
        "    lea rdx, [rip + data_rva_226e8]\n" /* 02f72 */
        "    mov rcx, r14\n" /* 02f79 */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 02f7c */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 02f81 */
        "    cmp rax, 1\n" /* 02f88 */
        "    mov rbx, qword ptr [rsp + 0xb0]\n" /* 02f8c */
        "    jne .Lblock_2ff9\n" /* 02f94 */
        "    mov r8d, 0xb0\n" /* 02f96 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 02f9c */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 02fa3 */
        "    lea rdx, [rip + data_rva_1f5a0]\n" /* 02faa */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 02fb1 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 02fb6 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 02fbd */
        "    mov r8, rdx\n" /* 02fc4 */
        "    mov r9, r15\n" /* 02fc7 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 02fca */
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffff7\n" /* 02fcf */
        "    movsd xmm0, qword ptr [rip + data_rva_224e0]\n" /* 02fd7 */
        "    movsd qword ptr [rip + data_rva_224c8], xmm0\n" /* 02fdf */
        "    movsd xmm0, qword ptr [rip + data_rva_225d0]\n" /* 02fe7 */
        "    movsd qword ptr [rip + data_rva_224d0], xmm0\n" /* 02fef */
        "    jmp .Lblock_3048\n" /* 02ff7 */
        ".Lblock_2ff9:\n"
        "    jle .Lblock_3048\n" /* 02ff9 */
        "    mov r8d, 0xb0\n" /* 02ffb */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03001 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 03008 */
        "    lea rdx, [rip + data_rva_1f140]\n" /* 0300f */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 03016 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 0301b */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 03022 */
        "    lea r8, [rip + rdata_rva_19760]\n" /* 03029 */
        "    mov r9, r15\n" /* 03030 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 03033 */
        "    lea rdx, [r15 + 0x20]\n" /* 03038 */
        "    lea rcx, [rip + data_rva_226e8]\n" /* 0303c */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 03043 */
        ".Lblock_3048:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 03048 */
        "    mov rax, qword ptr [rip + data_rva_22708]\n" /* 0304d */
        "    test rax, rax\n" /* 03054 */
        S9_JE32(.Lblock_3370) /* 03057 */
        "    mov rcx, qword ptr [rip + data_rva_22700]\n" /* 0305d */
        "    test rcx, rcx\n" /* 03064 */
        S9_JE32(.Lblock_3495) /* 03067 */
        "    lea rdx, [r15 + 0x20]\n" /* 0306d */
        "    mov qword ptr [rsp + 0xa8], rdx\n" /* 03071 */
        "    cmp qword ptr [r15 + 0x20], -9\n" /* 03079 */
        S9_JE32(.Lblock_389b) /* 0307e */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03084 */
        "    mov rdx, qword ptr [rdx]\n" /* 0308b */
        "    mov rdi, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 0308e */
        "    mov r8, qword ptr [rdi + 0x78]\n" /* 03095 */
        "    add rcx, rdx\n" /* 03099 */
        "    add rcx, r8\n" /* 0309c */
        "    mov rbx, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 0309f */
        "    movsd xmm0, qword ptr [rbx + rcx*8 - 0x10]\n" /* 030a6 */
        "    movsd qword ptr [rip + data_rva_224c0], xmm0\n" /* 030ac */
        "    add rax, rdx\n" /* 030b4 */
        "    add rax, r8\n" /* 030b7 */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 0x10]\n" /* 030ba */
        "    mov rax, qword ptr [rip + data_rva_22790]\n" /* 030c0 */
        "    movsd xmm1, qword ptr [r12 + rax*8 - 8]\n" /* 030c7 */
        "    mov rax, qword ptr [rip + data_rva_22778]\n" /* 030ce */
        "    mulsd xmm1, qword ptr [r12 + rax*8 - 8]\n" /* 030d5 */
        "    movsd qword ptr [rip + data_rva_224b8], xmm0\n" /* 030dc */
        "    movsd qword ptr [rip + data_rva_224d8], xmm1\n" /* 030e4 */
        "    mov rax, qword ptr [rip + data_rva_22788]\n" /* 030ec */
        "    movsd xmm1, qword ptr [r12 + rax*8 - 8]\n" /* 030f3 */
        "    movsd qword ptr [rip + data_rva_224c8], xmm1\n" /* 030fa */
        "    mov rax, qword ptr [rip + data_rva_22798]\n" /* 03102 */
        "    movsd xmm0, qword ptr [r12 + rax*8 - 8]\n" /* 03109 */
        "    movsd xmm6, qword ptr [rip + rdata_rva_19550]\n" /* 03110 */
        "    ucomisd xmm6, xmm1\n" /* 03118 */
        "    seta al\n" /* 0311c */
        "    movsd qword ptr [rip + data_rva_224d0], xmm0\n" /* 0311f */
        "    xorpd xmm2, xmm2\n" /* 03127 */
        "    ucomisd xmm1, xmm2\n" /* 0312b */
        "    jbe .Lblock_3139\n" /* 0312f */
        "    test al, al\n" /* 03131 */
        S9_JNE32(.Lblock_389b) /* 03133 */
        ".Lblock_3139:\n"
        "    mov qword ptr [rsp + 0xc0], rbp\n" /* 03139 */
        "    mov qword ptr [rip + data_rva_226d8], 0\n" /* 03141 */
        "    movsd qword ptr [rip + data_rva_225c0], xmm0\n" /* 0314c */
        "    mov qword ptr [rip + data_rva_225b8], 0\n" /* 03154 */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 0315f */
        "    cmp qword ptr [rip + data_rva_226f8], 4\n" /* 03164 */
        "    jl .Lblock_31c2\n" /* 0316c */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0316e */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 0317a */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 03181 */
        "    mov word ptr [rsp + 0x10c], 1\n" /* 03184 */
        "    lea rax, [rip + data_rva_1f6a4]\n" /* 0318e */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 03195 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0319a */
        "    lea rcx, [rsp + 0xd0]\n" /* 031a3 */
        "    lea r9, [rsp + 0x10c]\n" /* 031ab */
        "    movabs r8, 0x801208384ff00\n" /* 031b3 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 031bd */
        ".Lblock_31c2:\n"
        "    mov rax, qword ptr [rdi + 0xc0]\n" /* 031c2 */
        "    mov rcx, qword ptr [rdi + 0xe8]\n" /* 031c9 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 031d0 */
        "    add rax, qword ptr [rdx]\n" /* 031d7 */
        "    lea rax, [rbx + rax*8]\n" /* 031da */
        "    add rax, -8\n" /* 031de */
        "    add rcx, qword ptr [rdx + 8]\n" /* 031e2 */
        "    lea rcx, [rbx + rcx*8]\n" /* 031e6 */
        "    add rcx, -8\n" /* 031ea */
        "    lea r14, [rip + data_rva_226e8]\n" /* 031ee */
        "    mov qword ptr [rsp + 0x98], r14\n" /* 031f5 */
        "    mov qword ptr [rsp + 0x90], rcx\n" /* 031fd */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 03205 */
        "    lea rax, [rip + data_rva_22740]\n" /* 0320d */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 03214 */
        "    lea r15, [rip + data_rva_226d8]\n" /* 0321c */
        "    mov qword ptr [rsp + 0x78], r15\n" /* 03223 */
        "    mov rax, qword ptr [rsp + 0xc8]\n" /* 03228 */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 03230 */
        "    lea rax, [rip + data_rva_226f8]\n" /* 03235 */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 0323c */
        "    lea rax, [rip + data_rva_225c0]\n" /* 03241 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 03248 */
        "    lea rax, [rip + data_rva_225b8]\n" /* 0324d */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 03254 */
        "    lea rax, [rip + data_rva_225f0]\n" /* 03259 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 03260 */
        "    lea rax, [rip + data_rva_225d8]\n" /* 03265 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 0326c */
        "    lea rax, [rip + data_rva_22760]\n" /* 03271 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 03278 */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 0327d */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 03284 */
        "    lea rax, [rip + data_rva_22770]\n" /* 03289 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 03290 */
        "    lea rbp, [rip + data_rva_22750]\n" /* 03295 */
        "    mov qword ptr [rsp + 0x28], rbp\n" /* 0329c */
        "    mov rax, qword ptr [rsp + 0x728]\n" /* 032a1 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 032a9 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 032ae */
        "    mov rsi, r12\n" /* 032b5 */
        "    mov rcx, r12\n" /* 032b8 */
        "    mov r8, rdx\n" /* 032bb */
        "    mov r9, rdx\n" /* 032be */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 032c1 */
        "    mov rax, qword ptr [rip + data_rva_22790]\n" /* 032c6 */
        "    movsd xmm0, qword ptr [r12 + rax*8 - 8]\n" /* 032cd */
        "    mov rax, qword ptr [rip + data_rva_22778]\n" /* 032d4 */
        "    mulsd xmm0, qword ptr [r12 + rax*8 - 8]\n" /* 032db */
        "    movsd qword ptr [rip + data_rva_224b0], xmm0\n" /* 032e2 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 032ea */
        "    mov rdx, r14\n" /* 032f1 */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 032f4 */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 032f9 */
        "    cmp rax, 1\n" /* 03300 */
        S9_JNE32(.Lblock_358a) /* 03304 */
        "    mov r8d, 0xb0\n" /* 0330a */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03310 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 03317 */
        "    lea rdx, [rip + data_rva_1f4c0]\n" /* 0331e */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 03325 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 0332a */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 03331 */
        "    lea r8, [rip + rdata_rva_19768]\n" /* 03338 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 0333f */
        "    mov r9, r15\n" /* 03347 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 0334a */
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffff4\n" /* 0334f */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 03357 */
        "    mov rbp, qword ptr [rsp + 0xc0]\n" /* 0335c */
        "    lea r14, [rip + rdata_rva_19840]\n" /* 03364 */
        S9_JMP32(.Lblock_389b) /* 0336b */
        ".Lblock_3370:\n"
        "    xor eax, eax\n" /* 03370 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 03372 */
        "    cmp qword ptr [rcx + 0x100], 0\n" /* 03379 */
        "    setle al\n" /* 03381 */
        "    lea rax, [rax + rax + 1]\n" /* 03384 */
        "    mov qword ptr [rip + data_rva_22540], rax\n" /* 03389 */
        "    lea rdx, [rip + data_rva_22540]\n" /* 03390 */
        "    lea r8, [rip + rdata_rva_19848]\n" /* 03397 */
        "    mov qword ptr [rsp + 0x38], r8\n" /* 0339e */
        "    mov qword ptr [rsp + 0x30], r14\n" /* 033a3 */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 033a8 */
        "    add rcx, 0x38\n" /* 033ad */
        "    mov qword ptr [rsp + 0x20], rcx\n" /* 033b1 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 033b6 */
        "    mov r9, r15\n" /* 033bd */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 033c0 */
        "    test rax, rax\n" /* 033c5 */
        S9_JE32(.Lblock_3573) /* 033c8 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 033ce */
        "    mov dword ptr [rsp + 0x23c], 0x10638\n" /* 033da */
        "    mov qword ptr [rsp + 0x488], 0x320\n" /* 033e5 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 033f1 */
        "    mov qword ptr [rsp + 0x490], rax\n" /* 033f8 */
        "    mov qword ptr [rsp + 0x498], 0x50\n" /* 03400 */
        "    lea rax, [rip + data_rva_20540]\n" /* 0340c */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 03413 */
        "    lea rcx, [rsp + 0xd0]\n" /* 03418 */
        "    lea r8, [rsp + 0x23c]\n" /* 03420 */
        "    lea r9, [rsp + 0x488]\n" /* 03428 */
        S9_JMP32(.Lblock_3558) /* 03430 */
        ".Lblock_3435:\n"
        S9_JLE32(.Lblock_3580) /* 03435 */
        "    mov r8d, 0xb0\n" /* 0343b */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03441 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 03448 */
        "    lea rdx, [rip + data_rva_1ee00]\n" /* 0344f */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 03456 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 0345b */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 03462 */
        "    lea r8, [rip + rdata_rva_19818]\n" /* 03469 */
        "    mov r9, r15\n" /* 03470 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 03473 */
        "    add r15, 0x20\n" /* 03478 */
        "    lea rcx, [rip + data_rva_226e8]\n" /* 0347c */
        "    mov rdx, r15\n" /* 03483 */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 03486 */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 0348b */
        S9_JMP32(.Lblock_58f9) /* 03490 */
        ".Lblock_3495:\n"
        "    xor eax, eax\n" /* 03495 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 03497 */
        "    cmp qword ptr [rcx + 0x100], 0\n" /* 0349e */
        "    setle al\n" /* 034a6 */
        "    lea rax, [rax + rax + 1]\n" /* 034a9 */
        "    mov qword ptr [rip + data_rva_22540], rax\n" /* 034ae */
        "    lea rdx, [rip + data_rva_22540]\n" /* 034b5 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 034bc */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 034c3 */
        "    mov qword ptr [rsp + 0x30], r14\n" /* 034c8 */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 034cd */
        "    add rcx, 0x38\n" /* 034d2 */
        "    mov qword ptr [rsp + 0x20], rcx\n" /* 034d6 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 034db */
        "    lea r8, [rip + rdata_rva_197f8]\n" /* 034e2 */
        "    mov r9, r15\n" /* 034e9 */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 034ec */
        "    test rax, rax\n" /* 034f1 */
        "    je .Lblock_3573\n" /* 034f4 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 034f6 */
        "    mov dword ptr [rsp + 0x238], 0x10638\n" /* 03502 */
        "    mov qword ptr [rsp + 0x470], 0x320\n" /* 0350d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 03519 */
        "    mov qword ptr [rsp + 0x478], rax\n" /* 03520 */
        "    mov qword ptr [rsp + 0x480], 0x50\n" /* 03528 */
        "    lea rax, [rip + data_rva_204dc]\n" /* 03534 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0353b */
        "    lea rcx, [rsp + 0xd0]\n" /* 03540 */
        "    lea r8, [rsp + 0x238]\n" /* 03548 */
        "    lea r9, [rsp + 0x470]\n" /* 03550 */
        ".Lblock_3558:\n"
        "    movabs rdx, 0x801208384ff00\n" /* 03558 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 03562 */
        "    lea rcx, [rip + rdata_rva_19830]\n" /* 03567 */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 0356e */
        ".Lblock_3573:\n"
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffffe\n" /* 03573 */
        S9_JMP32(.Lblock_587e) /* 0357b */
        ".Lblock_3580:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 03580 */
        S9_JMP32(.Lblock_58f9) /* 03585 */
        ".Lblock_358a:\n"
        "    lea r14, [rip + rdata_rva_19840]\n" /* 0358a */
        "    jle .Lblock_35e9\n" /* 03591 */
        "    mov r8d, 0xb0\n" /* 03593 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03599 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 035a0 */
        "    lea rdx, [rip + data_rva_1f0c0]\n" /* 035a7 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 035ae */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 035b3 */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 035ba */
        "    lea r8, [rip + rdata_rva_19770]\n" /* 035c1 */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 035c8 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 035d0 */
        "    lea rcx, [rip + data_rva_226e8]\n" /* 035d5 */
        "    mov rdx, qword ptr [rsp + 0xa8]\n" /* 035dc */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 035e4 */
        ".Lblock_35e9:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 035e9 */
        "    movsd xmm0, qword ptr [rip + data_rva_224d0]\n" /* 035ee */
        "    movsd qword ptr [rip + data_rva_225b0], xmm0\n" /* 035f6 */
        "    movabs rax, 0x3ff0000000000000\n" /* 035fe */
        "    mov qword ptr [rip + data_rva_225a8], rax\n" /* 03608 */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 0360f */
        "    cmp qword ptr [rip + data_rva_226f8], 3\n" /* 03614 */
        "    jle .Lblock_3672\n" /* 0361c */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0361e */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 0362a */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 03631 */
        "    mov word ptr [rsp + 0x10a], 1\n" /* 03634 */
        "    lea rax, [rip + data_rva_1f6a4]\n" /* 0363e */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 03645 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0364a */
        "    lea rcx, [rsp + 0xd0]\n" /* 03653 */
        "    lea r9, [rsp + 0x10a]\n" /* 0365b */
        "    movabs r8, 0x801208384ff00\n" /* 03663 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0366d */
        ".Lblock_3672:\n"
        "    mov rax, qword ptr [rdi + 0xc0]\n" /* 03672 */
        "    mov rcx, qword ptr [rdi + 0xe8]\n" /* 03679 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03680 */
        "    add rax, qword ptr [rdx]\n" /* 03687 */
        "    lea rax, [rbx + rax*8]\n" /* 0368a */
        "    add rax, -8\n" /* 0368e */
        "    add rcx, qword ptr [rdx + 8]\n" /* 03692 */
        "    lea rcx, [rbx + rcx*8]\n" /* 03696 */
        "    add rcx, -8\n" /* 0369a */
        "    lea rdi, [rip + data_rva_226e8]\n" /* 0369e */
        "    mov qword ptr [rsp + 0x98], rdi\n" /* 036a5 */
        "    mov qword ptr [rsp + 0x90], rcx\n" /* 036ad */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 036b5 */
        "    lea rax, [rip + data_rva_22740]\n" /* 036bd */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 036c4 */
        "    mov qword ptr [rsp + 0x78], r15\n" /* 036cc */
        "    mov rax, qword ptr [rsp + 0xc8]\n" /* 036d1 */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 036d9 */
        "    lea rax, [rip + data_rva_226f8]\n" /* 036de */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 036e5 */
        "    lea rax, [rip + data_rva_225b0]\n" /* 036ea */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 036f1 */
        "    lea rax, [rip + data_rva_225a8]\n" /* 036f6 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 036fd */
        "    lea rax, [rip + data_rva_225f0]\n" /* 03702 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 03709 */
        "    lea rax, [rip + data_rva_225d8]\n" /* 0370e */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 03715 */
        "    lea rax, [rip + data_rva_22760]\n" /* 0371a */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 03721 */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 03726 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 0372d */
        "    lea rax, [rip + data_rva_22770]\n" /* 03732 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 03739 */
        "    mov qword ptr [rsp + 0x28], rbp\n" /* 0373e */
        "    mov rax, qword ptr [rsp + 0x728]\n" /* 03743 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0374b */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 03750 */
        "    mov rsi, r12\n" /* 03757 */
        "    mov rcx, r12\n" /* 0375a */
        "    mov r8, rdx\n" /* 0375d */
        "    mov r9, rdx\n" /* 03760 */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 03763 */
        "    mov rax, qword ptr [rip + data_rva_22790]\n" /* 03768 */
        "    movsd xmm0, qword ptr [r12 + rax*8 - 8]\n" /* 0376f */
        "    mov rax, qword ptr [rip + data_rva_22778]\n" /* 03776 */
        "    mulsd xmm0, qword ptr [r12 + rax*8 - 8]\n" /* 0377d */
        "    movsd qword ptr [rip + data_rva_224a8], xmm0\n" /* 03784 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 0378c */
        "    mov rdx, rdi\n" /* 03793 */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 03796 */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 0379b */
        "    cmp rax, 1\n" /* 037a2 */
        "    jne .Lblock_3807\n" /* 037a6 */
        "    mov r8d, 0xb0\n" /* 037a8 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 037ae */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 037b5 */
        "    lea rdx, [rip + data_rva_1f3e0]\n" /* 037bc */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 037c3 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 037c8 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 037cf */
        "    lea r8, [rip + rdata_rva_19778]\n" /* 037d6 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 037dd */
        "    mov r9, r15\n" /* 037e5 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 037e8 */
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffff3\n" /* 037ed */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 037f5 */
        "    mov rbp, qword ptr [rsp + 0xc0]\n" /* 037fa */
        S9_JMP32(.Lblock_389b) /* 03802 */
        ".Lblock_3807:\n"
        "    mov rbp, qword ptr [rsp + 0xc0]\n" /* 03807 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 0380f */
        "    jle .Lblock_386a\n" /* 03817 */
        "    mov r8d, 0xb0\n" /* 03819 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 0381f */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 03826 */
        "    lea rdx, [rip + data_rva_1f040]\n" /* 0382d */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 03834 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 03839 */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 03840 */
        "    lea r8, [rip + rdata_rva_19780]\n" /* 03847 */
        "    mov r9, r15\n" /* 0384e */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 03851 */
        "    lea rcx, [rip + data_rva_226e8]\n" /* 03856 */
        "    mov rdx, qword ptr [rsp + 0xa8]\n" /* 0385d */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 03865 */
        ".Lblock_386a:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 0386a */
        "    movsd xmm0, qword ptr [rip + data_rva_224a8]\n" /* 0386f */
        "    movapd xmm1, xmm0\n" /* 03877 */
        "    subsd xmm1, qword ptr [rip + data_rva_224d8]\n" /* 0387b */
        "    subsd xmm0, qword ptr [rip + data_rva_224b0]\n" /* 03883 */
        "    divsd xmm1, xmm0\n" /* 0388b */
        "    subsd xmm6, xmm1\n" /* 0388f */
        "    movsd qword ptr [rip + data_rva_224c8], xmm6\n" /* 03893 */
        ".Lblock_389b:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_224c8]\n" /* 0389b */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 038a3 */
        "    movsd xmm1, qword ptr [rax + 8]\n" /* 038aa */
        "    ucomisd xmm1, qword ptr [rip + data_rva_224c0]\n" /* 038af */
        "    setae al\n" /* 038b7 */
        "    ucomisd xmm0, qword ptr [rip + rdata_rva_19550]\n" /* 038ba */
        "    jae .Lblock_38d6\n" /* 038c2 */
        "    test al, al\n" /* 038c4 */
        "    jne .Lblock_38d6\n" /* 038c6 */
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 038c8 */
        "    cmp qword ptr [rax], -9\n" /* 038d0 */
        "    jne .Lblock_3902\n" /* 038d4 */
        ".Lblock_38d6:\n"
        "    mov rax, qword ptr [rip + data_rva_22700]\n" /* 038d6 */
        "    movsd xmm1, qword ptr [r13 + rax*8 - 8]\n" /* 038dd */
        "    movsd qword ptr [rip + data_rva_224c0], xmm1\n" /* 038e4 */
        "    mov rax, qword ptr [rip + data_rva_22708]\n" /* 038ec */
        "    movsd xmm1, qword ptr [r13 + rax*8 - 8]\n" /* 038f3 */
        "    movsd qword ptr [rip + data_rva_224b8], xmm1\n" /* 038fa */
        ".Lblock_3902:\n"
        "    mov rax, qword ptr [r15 + 0x28]\n" /* 03902 */
        "    cmp rax, 2\n" /* 03906 */
        "    mov rbx, qword ptr [rsp + 0xb0]\n" /* 0390a */
        "    je .Lblock_3940\n" /* 03912 */
        "    movsd xmm1, qword ptr [rip + data_rva_224d0]\n" /* 03914 */
        "    movsd xmm2, qword ptr [rip + rdata_rva_196b0]\n" /* 0391c */
        "    movapd xmm3, xmm1\n" /* 03924 */
        "    addsd xmm3, xmm2\n" /* 03928 */
        "    movsd qword ptr [rip + data_rva_225e0], xmm3\n" /* 0392c */
        "    subsd xmm1, xmm2\n" /* 03934 */
        "    movsd qword ptr [rip + data_rva_225e8], xmm1\n" /* 03938 */
        ".Lblock_3940:\n"
        "    movsd xmm11, qword ptr [rip + rdata_rva_19550]\n" /* 03940 */
        "    movapd xmm1, xmm11\n" /* 03949 */
        "    subsd xmm1, xmm0\n" /* 0394e */
        "    movsd qword ptr [rip + data_rva_224a0], xmm1\n" /* 03952 */
        "    mov qword ptr [rip + data_rva_22538], 0\n" /* 0395a */
        "    mov qword ptr [rip + data_rva_22748], rax\n" /* 03965 */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 0396c */
        "    mov rax, qword ptr [rip + data_rva_22538]\n" /* 03971 */
        "    lea rcx, [rax + 1]\n" /* 03978 */
        "    mov qword ptr [rip + data_rva_22538], rcx\n" /* 0397c */
        "    cmp rax, qword ptr [rip + data_rva_22758]\n" /* 03983 */
        S9_JGE32(.Lblock_4eed) /* 0398a */
        "    mov rsi, qword ptr [rsp + 0x780]\n" /* 03990 */
        "    mov r15, qword ptr [rsp + 0x750]\n" /* 03998 */
        "    mov rax, qword ptr [rsp + 0x118]\n" /* 039a0 */
        "    lea rdx, [rax*8]\n" /* 039a8 */
        "    mov rcx, qword ptr [rsp + 0x110]\n" /* 039b0 */
        "    lea r8, [rcx*8]\n" /* 039b8 */
        "    shl rax, 4\n" /* 039c0 */
        "    mov r9, qword ptr [rsp + 0x790]\n" /* 039c4 */
        "    add rax, r9\n" /* 039cc */
        "    mov qword ptr [rsp + 0x118], rax\n" /* 039cf */
        "    shl rcx, 4\n" /* 039d7 */
        "    mov rax, qword ptr [rsp + 0x7a0]\n" /* 039db */
        "    add rcx, rax\n" /* 039e3 */
        "    mov qword ptr [rsp + 0x110], rcx\n" /* 039e6 */
        "    add rdx, r9\n" /* 039ee */
        "    mov qword ptr [rsp + 0x260], rdx\n" /* 039f1 */
        "    add r8, rax\n" /* 039f9 */
        "    mov qword ptr [rsp + 0x258], r8\n" /* 039fc */
        "    xorpd xmm12, xmm12\n" /* 03a04 */
        "    mov eax, 0xb0\n" /* 03a09 */
        "    add rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 03a0e */
        "    mov qword ptr [rsp + 0x240], rax\n" /* 03a15 */
        "    mov qword ptr [rsp + 0xc0], rbp\n" /* 03a1d */
        "    mov qword ptr [rsp + 0xb8], r12\n" /* 03a25 */
        ".Lblock_3a2d:\n"
        "    call thunk_atdms_dll_DMS_PPITER_rva_1528c\n" /* 03a2d */
        "    cmp qword ptr [rip + data_rva_22538], 1\n" /* 03a32 */
        S9_JNE32(.Lblock_3b35) /* 03a3a */
        "    mov rax, qword ptr [rsp + 0x720]\n" /* 03a40 */
        "    cmp qword ptr [rax + 0x28], 2\n" /* 03a48 */
        S9_JE32(.Lblock_3b35) /* 03a4d */
        "    lea rax, [rip + data_rva_226d0]\n" /* 03a53 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 03a5a */
        "    lea rax, [rip + data_rva_22620]\n" /* 03a5f */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 03a66 */
        "    mov r14, qword ptr [rsp + 0x748]\n" /* 03a6b */
        "    mov qword ptr [rsp + 0x48], r14\n" /* 03a73 */
        "    lea rax, [rip + rdata_rva_19790]\n" /* 03a78 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 03a7f */
        "    mov rbx, qword ptr [rsp + 0xc8]\n" /* 03a84 */
        "    mov qword ptr [rsp + 0x38], rbx\n" /* 03a8c */
        "    mov rdi, qword ptr [rsp + 0x728]\n" /* 03a91 */
        "    mov qword ptr [rsp + 0x30], rdi\n" /* 03a99 */
        "    mov rax, qword ptr [rsp + 0x7b8]\n" /* 03a9e */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 03aa6 */
        "    lea rax, [rip + data_rva_226e0]\n" /* 03aab */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 03ab2 */
        "    lea rcx, [rip + data_rva_225e0]\n" /* 03ab7 */
        "    lea rdx, [rip + data_rva_22600]\n" /* 03abe */
        "    mov r8, r13\n" /* 03ac5 */
        "    mov r9, r13\n" /* 03ac8 */
        "    call thunk_ppmon_dll_PPMON_KVL_rva_15358\n" /* 03acb */
        "    lea rax, [rip + data_rva_226d0]\n" /* 03ad0 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 03ad7 */
        "    lea rax, [rip + data_rva_22620]\n" /* 03adc */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 03ae3 */
        "    mov qword ptr [rsp + 0x48], r15\n" /* 03ae8 */
        "    lea rax, [rip + rdata_rva_19790]\n" /* 03aed */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 03af4 */
        "    mov qword ptr [rsp + 0x38], rbx\n" /* 03af9 */
        "    mov qword ptr [rsp + 0x30], rdi\n" /* 03afe */
        "    mov rax, qword ptr [rsp + 0x7b8]\n" /* 03b03 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 03b0b */
        "    lea rax, [rip + data_rva_226e0]\n" /* 03b10 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 03b17 */
        "    lea rcx, [rip + data_rva_225e8]\n" /* 03b1c */
        "    lea rdx, [rip + data_rva_22608]\n" /* 03b23 */
        "    mov r8, r13\n" /* 03b2a */
        "    mov r9, r13\n" /* 03b2d */
        S9_JMP32(.Lblock_3c41) /* 03b30 */
        ".Lblock_3b35:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_22618]\n" /* 03b35 */
        "    movsd qword ptr [rip + data_rva_22498], xmm0\n" /* 03b3d */
        "    movsd xmm0, qword ptr [rip + data_rva_22610]\n" /* 03b45 */
        "    movsd qword ptr [rip + data_rva_22490], xmm0\n" /* 03b4d */
        "    lea rax, [rip + data_rva_226d0]\n" /* 03b55 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 03b5c */
        "    lea rax, [rip + data_rva_22620]\n" /* 03b61 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 03b68 */
        "    mov r14, qword ptr [rsp + 0x748]\n" /* 03b6d */
        "    mov qword ptr [rsp + 0x48], r14\n" /* 03b75 */
        "    lea rax, [rip + rdata_rva_19830]\n" /* 03b7a */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 03b81 */
        "    mov rbx, qword ptr [rsp + 0xc8]\n" /* 03b86 */
        "    mov qword ptr [rsp + 0x38], rbx\n" /* 03b8e */
        "    mov rdi, qword ptr [rsp + 0x728]\n" /* 03b93 */
        "    mov qword ptr [rsp + 0x30], rdi\n" /* 03b9b */
        "    mov rax, qword ptr [rsp + 0x7b8]\n" /* 03ba0 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 03ba8 */
        "    lea rax, [rip + data_rva_226e0]\n" /* 03bad */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 03bb4 */
        "    lea rcx, [rip + data_rva_225e0]\n" /* 03bb9 */
        "    lea rdx, [rip + data_rva_22600]\n" /* 03bc0 */
        "    mov r8, qword ptr [rsp + 0x758]\n" /* 03bc7 */
        "    mov r9, r8\n" /* 03bcf */
        "    call thunk_ppmon_dll_PPMON_KVL_rva_15358\n" /* 03bd2 */
        "    lea rax, [rip + data_rva_226d0]\n" /* 03bd7 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 03bde */
        "    lea rax, [rip + data_rva_22620]\n" /* 03be3 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 03bea */
        "    mov qword ptr [rsp + 0x48], r15\n" /* 03bef */
        "    lea rax, [rip + rdata_rva_19830]\n" /* 03bf4 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 03bfb */
        "    mov qword ptr [rsp + 0x38], rbx\n" /* 03c00 */
        "    mov qword ptr [rsp + 0x30], rdi\n" /* 03c05 */
        "    mov rax, qword ptr [rsp + 0x7b8]\n" /* 03c0a */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 03c12 */
        "    lea rax, [rip + data_rva_226e0]\n" /* 03c17 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 03c1e */
        "    lea rcx, [rip + data_rva_225e8]\n" /* 03c23 */
        "    lea rdx, [rip + data_rva_22608]\n" /* 03c2a */
        "    mov r8, qword ptr [rsp + 0x740]\n" /* 03c31 */
        "    mov r9, qword ptr [rsp + 0x738]\n" /* 03c39 */
        ".Lblock_3c41:\n"
        "    call thunk_ppmon_dll_PPMON_KVL_rva_15358\n" /* 03c41 */
        "    mov rdi, qword ptr [rip + data_rva_22708]\n" /* 03c46 */
        "    movsd xmm7, qword ptr [r14 + rdi*8 - 8]\n" /* 03c4d */
        "    movsd qword ptr [rip + data_rva_22618], xmm7\n" /* 03c54 */
        "    movsd xmm6, qword ptr [r15 + rdi*8 - 8]\n" /* 03c5c */
        "    movsd qword ptr [rip + data_rva_22610], xmm6\n" /* 03c63 */
        "    mov rbx, qword ptr [rip + data_rva_22700]\n" /* 03c6b */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 03c72 */
        "    movsd xmm8, qword ptr [rax + 8]\n" /* 03c79 */
        "    ucomisd xmm8, qword ptr [r15 + rbx*8 - 8]\n" /* 03c7f */
        "    mov r10, qword ptr [rsp + 0x778]\n" /* 03c86 */
        S9_JAE32(.Lblock_50ca) /* 03c8e */
        "    ucomisd xmm8, qword ptr [r14 + rbx*8 - 8]\n" /* 03c94 */
        S9_JAE32(.Lblock_52b0) /* 03c9b */
        "    ucomisd xmm8, xmm6\n" /* 03ca1 */
        S9_JAE32(.Lblock_5498) /* 03ca6 */
        "    ucomisd xmm8, xmm7\n" /* 03cac */
        S9_JAE32(.Lblock_5678) /* 03cb1 */
        "    ucomisd xmm6, xmm7\n" /* 03cb7 */
        "    setnp cl\n" /* 03cbb */
        "    sete dl\n" /* 03cbe */
        "    ucomisd xmm6, xmm8\n" /* 03cc1 */
        "    seta al\n" /* 03cc6 */
        "    movapd xmm9, xmm11\n" /* 03cc9 */
        "    test dl, cl\n" /* 03cce */
        "    jne .Lblock_3cfa\n" /* 03cd0 */
        "    movapd xmm9, xmm11\n" /* 03cd2 */
        "    test al, al\n" /* 03cd7 */
        "    je .Lblock_3cfa\n" /* 03cd9 */
        "    movapd xmm0, xmm6\n" /* 03cdb */
        "    divsd xmm0, xmm7\n" /* 03cdf */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 03ce3 */
        "    mov r10, qword ptr [rsp + 0x778]\n" /* 03ce8 */
        "    movapd xmm9, xmm11\n" /* 03cf0 */
        "    divsd xmm9, xmm0\n" /* 03cf5 */
        ".Lblock_3cfa:\n"
        "    mov r12, qword ptr [rip + data_rva_226e0]\n" /* 03cfa */
        "    test r12, r12\n" /* 03d01 */
        "    mov r9, qword ptr [rsp + 0x770]\n" /* 03d04 */
        "    movabs rcx, 0x3ff0000000000000\n" /* 03d0c */
        S9_JLE32(.Lblock_3e28) /* 03d16 */
        "    lea r14, [rdi - 1]\n" /* 03d1c */
        "    xor ebp, ebp\n" /* 03d20 */
        "    jmp .Lblock_3d46\n" /* 03d22 */
        S9_NOP12 /* 03d24 */
        ".Lblock_3d30:\n"
        "    mov qword ptr [r10 + rdi*8 - 8], rcx\n" /* 03d30 */
        "    mov qword ptr [r9 + rdi*8 - 8], rcx\n" /* 03d35 */
        ".Lblock_3d3a:\n"
        "    inc rbp\n" /* 03d3a */
        "    cmp rbp, r12\n" /* 03d3d */
        S9_JGE32(.Lblock_3e28) /* 03d40 */
        ".Lblock_3d46:\n"
        "    movsd xmm10, qword ptr [r15 + rbp*8]\n" /* 03d46 */
        "    mov rax, qword ptr [rsp + 0x748]\n" /* 03d4c */
        "    movsd xmm1, qword ptr [rax + rbp*8]\n" /* 03d54 */
        "    ucomisd xmm8, xmm1\n" /* 03d59 */
        "    seta al\n" /* 03d5e */
        "    ucomisd xmm8, xmm10\n" /* 03d61 */
        S9_JA32(.Lblock_3df0) /* 03d66 */
        "    test al, al\n" /* 03d6c */
        S9_JNE32(.Lblock_3df0) /* 03d6e */
        "    cmp r14, rbp\n" /* 03d74 */
        "    je .Lblock_3d30\n" /* 03d77 */
        "    ucomisd xmm6, xmm7\n" /* 03d79 */
        "    setnp dl\n" /* 03d7d */
        "    sete r8b\n" /* 03d80 */
        "    ucomisd xmm10, xmm1\n" /* 03d84 */
        "    setnp al\n" /* 03d89 */
        "    sete cl\n" /* 03d8c */
        "    test r8b, dl\n" /* 03d8f */
        "    jne .Lblock_3e01\n" /* 03d92 */
        "    and cl, al\n" /* 03d94 */
        "    jne .Lblock_3e01\n" /* 03d96 */
        "    movapd xmm0, xmm10\n" /* 03d98 */
        "    divsd xmm0, xmm1\n" /* 03d9d */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 03da1 */
        "    movapd xmm1, xmm0\n" /* 03da6 */
        "    mulsd xmm1, xmm9\n" /* 03daa */
        "    mov rax, qword ptr [rsp + 0x778]\n" /* 03daf */
        "    movsd qword ptr [rax + rbp*8], xmm1\n" /* 03db7 */
        "    movapd xmm0, xmm6\n" /* 03dbc */
        "    call thunk_libmmd_dll_pow_rva_15406\n" /* 03dc0 */
        "    mov r10, qword ptr [rsp + 0x778]\n" /* 03dc5 */
        "    mov r9, qword ptr [rsp + 0x770]\n" /* 03dcd */
        "    divsd xmm10, xmm0\n" /* 03dd5 */
        "    movsd qword ptr [r9 + rbp*8], xmm10\n" /* 03dda */
        "    movabs rcx, 0x3ff0000000000000\n" /* 03de0 */
        S9_JMP32(.Lblock_3d3a) /* 03dea */
        "    nop\n" /* 03def */
        ".Lblock_3df0:\n"
        "    mov qword ptr [r9 + rbp*8], 0\n" /* 03df0 */
        ".Lblock_3df8:\n"
        "    mov qword ptr [r10 + rbp*8], rcx\n" /* 03df8 */
        S9_JMP32(.Lblock_3d3a) /* 03dfc */
        ".Lblock_3e01:\n"
        "    divsd xmm10, xmm6\n" /* 03e01 */
        "    divsd xmm1, xmm7\n" /* 03e06 */
        "    mulsd xmm1, xmm10\n" /* 03e0a */
        "    xorps xmm0, xmm0\n" /* 03e0f */
        "    sqrtsd xmm0, xmm1\n" /* 03e12 */
        "    movsd qword ptr [r9 + rbp*8], xmm0\n" /* 03e16 */
        "    movabs rcx, 0x3ff0000000000000\n" /* 03e1c */
        "    jmp .Lblock_3df8\n" /* 03e26 */
        ".Lblock_3e28:\n"
        "    mov qword ptr [rip + data_rva_225a0], 0\n" /* 03e28 */
        "    mov qword ptr [rip + data_rva_22530], 0\n" /* 03e33 */
        "    mov qword ptr [rip + data_rva_226c8], 1\n" /* 03e3e */
        "    mov qword ptr [rip + data_rva_22528], 1\n" /* 03e49 */
        "    cmp qword ptr [rip + data_rva_22538], 1\n" /* 03e54 */
        "    jne .Lblock_3e7a\n" /* 03e5c */
        "    movabs rax, 0x3fe0000000000000\n" /* 03e5e */
        "    mov qword ptr [rip + data_rva_22598], rax\n" /* 03e68 */
        "    movsd xmm15, qword ptr [rip + rdata_rva_19548]\n" /* 03e6f */
        "    jmp .Lblock_3e83\n" /* 03e78 */
        ".Lblock_3e7a:\n"
        "    movsd xmm15, qword ptr [rip + data_rva_22598]\n" /* 03e7a */
        ".Lblock_3e83:\n"
        "    mov rbp, qword ptr [rsp + 0xc0]\n" /* 03e83 */
        "    mov r14, qword ptr [rsp + 0x758]\n" /* 03e8b */
        "    movabs rax, 0x3eb0c6f7a0b5ed8d\n" /* 03e93 */
        "    mov qword ptr [rip + data_rva_22640], rax\n" /* 03e9d */
        "    movapd xmm0, xmm11\n" /* 03ea4 */
        "    subsd xmm0, qword ptr [rip + rdata_rva_19558]\n" /* 03ea9 */
        "    movsd qword ptr [rip + data_rva_22648], xmm0\n" /* 03eb1 */
        "    movabs rdx, 0x3fc999999999999a\n" /* 03eb9 */
        "    mov qword ptr [rip + data_rva_22650], rdx\n" /* 03ec3 */
        "    mov qword ptr [rip + data_rva_22658], 0\n" /* 03eca */
        "    mov qword ptr [rip + data_rva_22660], rax\n" /* 03ed5 */
        "    mov qword ptr [rip + data_rva_22668], rcx\n" /* 03edc */
        "    movsd xmm0, qword ptr [rip + data_rva_22510]\n" /* 03ee3 */
        "    movsd qword ptr [rsp + 0x250], xmm0\n" /* 03eeb */
        "    movsd xmm9, qword ptr [rip + data_rva_225f8]\n" /* 03ef4 */
        "    movsd xmm0, qword ptr [rip + data_rva_22518]\n" /* 03efd */
        "    movsd qword ptr [rsp + 0x248], xmm0\n" /* 03f05 */
        "    jmp .Lblock_3f39\n" /* 03f0e */
        ".Lblock_3f10:\n"
        "    ucomisd xmm0, xmm12\n" /* 03f10 */
        S9_JAE32(.Lblock_430a) /* 03f15 */
        ".Lblock_3f1b:\n"
        "    subsd xmm15, qword ptr [rip + rdata_rva_196d8]\n" /* 03f1b */
        "    mov eax, 2\n" /* 03f24 */
        ".Lblock_3f29:\n"
        "    movsd qword ptr [rip + data_rva_22598], xmm15\n" /* 03f29 */
        "    mov qword ptr [rip + data_rva_22528], rax\n" /* 03f32 */
        ".Lblock_3f39:\n"
        "    movapd xmm6, xmm11\n" /* 03f39 */
        "    subsd xmm6, xmm15\n" /* 03f3e */
        "    divsd xmm6, xmm15\n" /* 03f43 */
        "    movsd xmm1, qword ptr [rsp + 0x250]\n" /* 03f48 */
        "    movapd xmm7, xmm1\n" /* 03f51 */
        "    mulsd xmm7, xmm6\n" /* 03f55 */
        "    movapd xmm0, xmm11\n" /* 03f59 */
        "    subsd xmm0, xmm1\n" /* 03f5e */
        "    divsd xmm7, xmm0\n" /* 03f62 */
        "    movsd xmm0, qword ptr [r15 + rbx*8 - 8]\n" /* 03f66 */
        "    subsd xmm0, xmm11\n" /* 03f6d */
        "    mulsd xmm0, xmm9\n" /* 03f72 */
        "    addsd xmm0, xmm11\n" /* 03f77 */
        "    divsd xmm7, xmm0\n" /* 03f7c */
        "    movsd xmm1, qword ptr [rsp + 0x248]\n" /* 03f80 */
        "    mulsd xmm6, xmm1\n" /* 03f89 */
        "    movapd xmm0, xmm11\n" /* 03f8d */
        "    subsd xmm0, xmm1\n" /* 03f92 */
        "    divsd xmm6, xmm0\n" /* 03f96 */
        "    movsd xmm0, qword ptr [r15 + rdi*8 - 8]\n" /* 03f9a */
        "    subsd xmm0, xmm11\n" /* 03fa1 */
        "    mulsd xmm0, xmm9\n" /* 03fa6 */
        "    addsd xmm0, xmm11\n" /* 03fab */
        "    divsd xmm6, xmm0\n" /* 03fb0 */
        "    movapd xmm0, xmm7\n" /* 03fb4 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 03fb8 */
        "    movapd xmm8, xmm0\n" /* 03fbd */
        "    movapd xmm0, xmm6\n" /* 03fc2 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 03fc6 */
        "    mov rax, qword ptr [rsp + 0x778]\n" /* 03fcb */
        "    mulsd xmm0, qword ptr [rax + rbx*8 - 8]\n" /* 03fd3 */
        "    subsd xmm8, xmm0\n" /* 03fd9 */
        "    mov rax, qword ptr [rsp + 0x770]\n" /* 03fde */
        "    movsd xmm0, qword ptr [rax + rbx*8 - 8]\n" /* 03fe6 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 03fec */
        "    divsd xmm8, xmm0\n" /* 03ff1 */
        "    movsd qword ptr [rip + data_rva_22488], xmm8\n" /* 03ff6 */
        "    test r12, r12\n" /* 03fff */
        S9_JLE32(.Lblock_41e0) /* 04002 */
        "    movsd qword ptr [rsp + 0x268], xmm9\n" /* 04008 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 04012 */
        "    movsd xmm12, qword ptr [rax + 8]\n" /* 04019 */
        "    mov rax, qword ptr [rip + iat_ppbase_dll_PPBASE_XFLSHZ_rva_192f8]\n" /* 0401f */
        "    movsd xmm14, qword ptr [rax + 0x30]\n" /* 04026 */
        "    xor r14d, r14d\n" /* 0402c */
        "    mov r8, qword ptr [rsp + 0x770]\n" /* 0402f */
        "    jmp .Lblock_4052\n" /* 04037 */
        S9_NOP7 /* 04039 */
        ".Lblock_4040:\n"
        "    movsd qword ptr [rsi + r14*8], xmm0\n" /* 04040 */
        "    inc r14\n" /* 04046 */
        "    cmp r12, r14\n" /* 04049 */
        S9_JE32(.Lblock_4130) /* 0404c */
        ".Lblock_4052:\n"
        "    xorpd xmm0, xmm0\n" /* 04052 */
        "    ucomisd xmm0, qword ptr [r13 + r14*8]\n" /* 04056 */
        "    setnp cl\n" /* 0405d */
        "    sete dl\n" /* 04060 */
        "    movsd xmm9, qword ptr [r8 + r14*8]\n" /* 04063 */
        "    ucomisd xmm9, xmm12\n" /* 04069 */
        "    seta al\n" /* 0406e */
        "    test dl, cl\n" /* 04071 */
        "    jne .Lblock_4040\n" /* 04073 */
        "    test al, al\n" /* 04075 */
        "    je .Lblock_4040\n" /* 04077 */
        "    movapd xmm0, xmm9\n" /* 04079 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 0407e */
        "    movapd xmm11, xmm0\n" /* 04083 */
        "    movapd xmm13, xmm14\n" /* 04088 */
        "    divsd xmm13, xmm8\n" /* 0408d */
        "    movapd xmm0, xmm6\n" /* 04092 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 04096 */
        "    mov r8, qword ptr [rsp + 0x770]\n" /* 0409b */
        "    movapd xmm2, xmmword ptr [rip + rdata_rva_196c0]\n" /* 040a3 */
        "    andpd xmm0, xmm2\n" /* 040ab */
        "    mov rax, qword ptr [rsp + 0x778]\n" /* 040af */
        "    movsd xmm10, qword ptr [rax + r14*8]\n" /* 040b7 */
        "    movapd xmm1, xmm14\n" /* 040bd */
        "    divsd xmm1, xmm10\n" /* 040c2 */
        "    andpd xmm1, xmm2\n" /* 040c7 */
        "    ucomisd xmm1, xmm0\n" /* 040cb */
        "    seta al\n" /* 040cf */
        "    ucomisd xmm13, xmm11\n" /* 040d2 */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196d0]\n" /* 040d7 */
        S9_JBE32(.Lblock_4040) /* 040df */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196d0]\n" /* 040e5 */
        "    test al, al\n" /* 040ed */
        S9_JE32(.Lblock_4040) /* 040ef */
        "    movapd xmm0, xmm9\n" /* 040f5 */
        "    movapd xmm1, xmm8\n" /* 040fa */
        "    call thunk_libmmd_dll_pow_rva_15406\n" /* 040ff */
        "    movapd xmm9, xmm0\n" /* 04104 */
        "    movapd xmm0, xmm6\n" /* 04109 */
        "    movapd xmm1, xmm10\n" /* 0410d */
        "    call thunk_libmmd_dll_pow_rva_15406\n" /* 04112 */
        "    mov r8, qword ptr [rsp + 0x770]\n" /* 04117 */
        "    mulsd xmm0, xmm9\n" /* 0411f */
        S9_JMP32(.Lblock_4040) /* 04124 */
        S9_NOP7 /* 04129 */
        ".Lblock_4130:\n"
        "    movsd qword ptr [rsi + rdi*8 - 8], xmm6\n" /* 04130 */
        "    movsd qword ptr [rsi + rbx*8 - 8], xmm7\n" /* 04136 */
        "    mov qword ptr [rip + data_rva_22590], 0\n" /* 0413c */
        "    xorpd xmm0, xmm0\n" /* 04147 */
        "    xor eax, eax\n" /* 0414b */
        "    mov r14, qword ptr [rsp + 0x758]\n" /* 0414d */
        "    movsd xmm11, qword ptr [rip + rdata_rva_19550]\n" /* 04155 */
        "    xorpd xmm12, xmm12\n" /* 0415e */
        "    movsd xmm9, qword ptr [rsp + 0x268]\n" /* 04163 */
        "    jmp .Lblock_417c\n" /* 0416d */
        "    nop\n" /* 0416f */
        ".Lblock_4170:\n"
        "    inc rax\n" /* 04170 */
        "    cmp r12, rax\n" /* 04173 */
        S9_JE32(.Lblock_41fb) /* 04176 */
        ".Lblock_417c:\n"
        "    movsd xmm1, qword ptr [r13 + rax*8]\n" /* 0417c */
        "    ucomisd xmm12, xmm1\n" /* 04183 */
        "    jae .Lblock_4170\n" /* 04188 */
        "    movsd xmm2, qword ptr [rsi + rax*8]\n" /* 0418a */
        "    movapd xmm3, xmm9\n" /* 0418f */
        "    mulsd xmm3, xmm15\n" /* 04194 */
        "    mulsd xmm3, xmm2\n" /* 04199 */
        "    subsd xmm2, xmm11\n" /* 0419d */
        "    mulsd xmm1, xmm2\n" /* 041a2 */
        "    mulsd xmm2, xmm15\n" /* 041a6 */
        "    addsd xmm2, xmm11\n" /* 041ab */
        "    movsd xmm4, qword ptr [r15 + rax*8]\n" /* 041b0 */
        "    subsd xmm4, xmm11\n" /* 041b6 */
        "    mulsd xmm4, xmm3\n" /* 041bb */
        "    addsd xmm4, xmm2\n" /* 041bf */
        "    divsd xmm1, xmm4\n" /* 041c3 */
        "    addsd xmm0, xmm1\n" /* 041c7 */
        "    movsd qword ptr [rip + data_rva_22590], xmm0\n" /* 041cb */
        "    jmp .Lblock_4170\n" /* 041d3 */
        S9_NOP11 /* 041d5 */
        ".Lblock_41e0:\n"
        "    movsd qword ptr [rsi + rdi*8 - 8], xmm6\n" /* 041e0 */
        "    movsd qword ptr [rsi + rbx*8 - 8], xmm7\n" /* 041e6 */
        "    mov qword ptr [rip + data_rva_22590], 0\n" /* 041ec */
        "    xorpd xmm0, xmm0\n" /* 041f7 */
        ".Lblock_41fb:\n"
        "    mov rax, qword ptr [rip + data_rva_22530]\n" /* 041fb */
        "    lea rcx, [rax + 1]\n" /* 04202 */
        "    mov qword ptr [rip + data_rva_22530], rcx\n" /* 04206 */
        "    cmp rax, 0x4b\n" /* 0420d */
        S9_JG32(.Lblock_4fd0) /* 04211 */
        "    mov ecx, dword ptr [rip + data_rva_22528]\n" /* 04217 */
        "    cmp ecx, 3\n" /* 0421d */
        S9_JE32(.Lblock_42f0) /* 04220 */
        "    cmp ecx, 2\n" /* 04226 */
        S9_JE32(.Lblock_3f10) /* 04229 */
        "    cmp rax, 0x2d\n" /* 0422f */
        S9_JG32(.Lblock_42cd) /* 04233 */
        "    lea rax, [rip + data_rva_1f1c8]\n" /* 04239 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 04240 */
        "    lea rcx, [rip + data_rva_226c8]\n" /* 04245 */
        "    lea rdx, [rip + data_rva_22598]\n" /* 0424c */
        "    lea r8, [rip + data_rva_22590]\n" /* 04253 */
        "    lea r9, [rip + data_rva_22640]\n" /* 0425a */
        "    call thunk_zemath_dll_ZMTH_ARCONS_rva_15346\n" /* 04261 */
        "    mov rax, qword ptr [rip + data_rva_226c8]\n" /* 04266 */
        "    test rax, rax\n" /* 0426d */
        S9_JS32(.Lblock_4fd0) /* 04270 */
        "    movsd xmm15, qword ptr [rip + data_rva_22598]\n" /* 04276 */
        "    movsd xmm0, qword ptr [rip + data_rva_22510]\n" /* 0427f */
        "    movsd qword ptr [rsp + 0x250], xmm0\n" /* 04287 */
        "    movsd xmm9, qword ptr [rip + data_rva_225f8]\n" /* 04290 */
        "    mov rbx, qword ptr [rip + data_rva_22700]\n" /* 04299 */
        "    movsd xmm0, qword ptr [rip + data_rva_22518]\n" /* 042a0 */
        "    movsd qword ptr [rsp + 0x248], xmm0\n" /* 042a8 */
        "    mov rdi, qword ptr [rip + data_rva_22708]\n" /* 042b1 */
        "    mov r12, qword ptr [rip + data_rva_226e0]\n" /* 042b8 */
        S9_JNE32(.Lblock_3f39) /* 042bf */
        "    movsd xmm0, qword ptr [rip + data_rva_22590]\n" /* 042c5 */
        ".Lblock_42cd:\n"
        "    xor eax, eax\n" /* 042cd */
        "    xorps xmm1, xmm1\n" /* 042cf */
        "    cvtsi2sd xmm1, eax\n" /* 042d2 */
        "    ucomisd xmm1, xmm0\n" /* 042d6 */
        S9_JA32(.Lblock_3f1b) /* 042da */
        "    ucomisd xmm0, xmm1\n" /* 042e0 */
        "    setnp al\n" /* 042e4 */
        "    sete cl\n" /* 042e7 */
        "    test cl, al\n" /* 042ea */
        "    je .Lblock_42f7\n" /* 042ec */
        "    jmp .Lblock_430a\n" /* 042ee */
        ".Lblock_42f0:\n"
        "    ucomisd xmm12, xmm0\n" /* 042f0 */
        "    jae .Lblock_430a\n" /* 042f5 */
        ".Lblock_42f7:\n"
        "    addsd xmm15, qword ptr [rip + rdata_rva_196d8]\n" /* 042f7 */
        "    mov eax, 3\n" /* 04300 */
        S9_JMP32(.Lblock_3f29) /* 04305 */
        ".Lblock_430a:\n"
        "    mov rax, qword ptr [rip + data_rva_22538]\n" /* 0430a */
        "    mov rcx, qword ptr [rip + data_rva_22758]\n" /* 04311 */
        "    mov rdx, rcx\n" /* 04318 */
        "    shr rdx, 0x3f\n" /* 0431b */
        "    add rdx, rcx\n" /* 0431f */
        "    sar rdx, 1\n" /* 04322 */
        "    cmp rdx, 3\n" /* 04325 */
        "    mov ecx, 2\n" /* 04329 */
        "    cmovl rdx, rcx\n" /* 0432e */
        "    cmp rax, rdx\n" /* 04332 */
        "    jle .Lblock_4352\n" /* 04335 */
        "    addsd xmm15, qword ptr [rip + data_rva_22520]\n" /* 04337 */
        "    divsd xmm15, qword ptr [rip + rdata_rva_196a0]\n" /* 04340 */
        "    movsd qword ptr [rip + data_rva_22598], xmm15\n" /* 04349 */
        ".Lblock_4352:\n"
        "    mov rdi, qword ptr [rsp + 0xb0]\n" /* 04352 */
        "    mov rbx, qword ptr [rsp + 0x728]\n" /* 0435a */
        "    movsd qword ptr [rip + data_rva_22520], xmm15\n" /* 04362 */
        "    xorpd xmm0, xmm0\n" /* 0436b */
        "    test r12, r12\n" /* 0436f */
        S9_JLE32(.Lblock_442a) /* 04372 */
        "    xor ecx, ecx\n" /* 04378 */
        "    jmp .Lblock_4390\n" /* 0437a */
        S9_NOP4 /* 0437c */
        ".Lblock_4380:\n"
        "    addsd xmm0, xmm1\n" /* 04380 */
        ".Lblock_4384:\n"
        "    inc rcx\n" /* 04384 */
        "    cmp rcx, r12\n" /* 04387 */
        S9_JGE32(.Lblock_442a) /* 0438a */
        ".Lblock_4390:\n"
        "    movsd xmm1, qword ptr [r13 + rcx*8]\n" /* 04390 */
        "    ucomisd xmm12, xmm1\n" /* 04397 */
        "    setnp dl\n" /* 0439c */
        "    sete r8b\n" /* 0439f */
        "    test r8b, dl\n" /* 043a3 */
        "    je .Lblock_43c0\n" /* 043a6 */
        "    mov rdx, qword ptr [rsp + 0x760]\n" /* 043a8 */
        "    mov qword ptr [rdx + rcx*8], 0\n" /* 043b0 */
        "    jmp .Lblock_4384\n" /* 043b8 */
        S9_NOP6 /* 043ba */
        ".Lblock_43c0:\n"
        "    movsd xmm2, qword ptr [rsi + rcx*8]\n" /* 043c0 */
        "    mulsd xmm1, xmm2\n" /* 043c5 */
        "    movapd xmm3, xmm15\n" /* 043c9 */
        "    mulsd xmm3, xmm2\n" /* 043ce */
        "    addsd xmm3, xmm11\n" /* 043d2 */
        "    subsd xmm3, xmm15\n" /* 043d7 */
        "    movapd xmm4, xmm9\n" /* 043dc */
        "    mulsd xmm4, xmm15\n" /* 043e1 */
        "    mulsd xmm4, xmm2\n" /* 043e6 */
        "    movsd xmm2, qword ptr [r15 + rcx*8]\n" /* 043ea */
        "    subsd xmm2, xmm11\n" /* 043f0 */
        "    mulsd xmm2, xmm4\n" /* 043f5 */
        "    addsd xmm2, xmm3\n" /* 043f9 */
        "    divsd xmm1, xmm2\n" /* 043fd */
        "    mov rdx, qword ptr [rsp + 0x760]\n" /* 04401 */
        "    movsd qword ptr [rdx + rcx*8], xmm1\n" /* 04409 */
        "    ucomisd xmm12, xmm1\n" /* 0440e */
        S9_JBE32(.Lblock_4380) /* 04413 */
        "    mov qword ptr [rdx + rcx*8], 0\n" /* 04419 */
        "    xorpd xmm1, xmm1\n" /* 04421 */
        S9_JMP32(.Lblock_4380) /* 04425 */
        ".Lblock_442a:\n"
        "    mov rcx, qword ptr [rip + data_rva_227a0]\n" /* 0442a */
        "    mov rdx, qword ptr [rsp + 0xb8]\n" /* 04431 */
        "    movsd xmm2, qword ptr [rdx + rcx*8 - 8]\n" /* 04439 */
        "    mulsd xmm15, xmm2\n" /* 0443f */
        "    movsd qword ptr [rbp + rcx*8 - 8], xmm15\n" /* 04444 */
        "    subsd xmm2, xmm15\n" /* 0444b */
        "    movsd qword ptr [rdi + rcx*8 - 8], xmm2\n" /* 04450 */
        "    test r12, r12\n" /* 04456 */
        "    movsd xmm9, qword ptr [rip + rdata_rva_196a0]\n" /* 04459 */
        "    movapd xmm8, xmmword ptr [rip + rdata_rva_196c0]\n" /* 04462 */
        S9_JLE32(.Lblock_4559) /* 0446b */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 04471 */
        "    movsd xmm3, qword ptr [rdx + 8]\n" /* 04478 */
        "    xorpd xmm4, xmm4\n" /* 0447d */
        "    xorpd xmm1, xmm1\n" /* 04481 */
        "    xor edx, edx\n" /* 04485 */
        "    jmp .Lblock_44b5\n" /* 04487 */
        S9_NOP7 /* 04489 */
        ".Lblock_4490:\n"
        "    mov r9, qword ptr [rsp + 0xb8]\n" /* 04490 */
        "    movsd xmm5, qword ptr [r9 + r8*8 - 8]\n" /* 04498 */
        "    divsd xmm5, xmm2\n" /* 0449f */
        ".Lblock_44a3:\n"
        "    movsd qword ptr [r14 + rdx*8], xmm5\n" /* 044a3 */
        "    addsd xmm1, xmm5\n" /* 044a9 */
        "    inc rdx\n" /* 044ad */
        "    cmp r12, rdx\n" /* 044b0 */
        "    je .Lblock_4522\n" /* 044b3 */
        ".Lblock_44b5:\n"
        "    mov r8, qword ptr [rsp + 0x7b8]\n" /* 044b5 */
        "    mov r8, qword ptr [r8 + rdx*8]\n" /* 044bd */
        "    mov r9, qword ptr [rsp + 0x760]\n" /* 044c1 */
        "    movsd xmm6, qword ptr [r9 + rdx*8]\n" /* 044c9 */
        "    divsd xmm6, xmm0\n" /* 044cf */
        "    movsd qword ptr [r9 + rdx*8], xmm6\n" /* 044d3 */
        "    movsd xmm5, qword ptr [rbp + rcx*8 - 8]\n" /* 044d9 */
        "    mulsd xmm5, xmm6\n" /* 044df */
        "    movsd qword ptr [rbp + r8*8 - 8], xmm5\n" /* 044e3 */
        "    movsd xmm7, qword ptr [rsi + rdx*8]\n" /* 044ea */
        "    ucomisd xmm7, xmm4\n" /* 044ef */
        "    xorpd xmm5, xmm5\n" /* 044f3 */
        "    jbe .Lblock_4501\n" /* 044f7 */
        "    movapd xmm5, xmm6\n" /* 044f9 */
        "    divsd xmm5, xmm7\n" /* 044fd */
        ".Lblock_4501:\n"
        "    ucomisd xmm7, xmm12\n" /* 04501 */
        "    setnp r9b\n" /* 04506 */
        "    sete r10b\n" /* 0450a */
        "    ucomisd xmm3, xmm6\n" /* 0450e */
        S9_JA32(.Lblock_4490) /* 04512 */
        "    and r10b, r9b\n" /* 04518 */
        "    je .Lblock_44a3\n" /* 0451b */
        S9_JMP32(.Lblock_4490) /* 0451d */
        ".Lblock_4522:\n"
        "    xor edx, edx\n" /* 04522 */
        "    mov r9, qword ptr [rsp + 0x7b8]\n" /* 04524 */
        S9_NOP4 /* 0452c */
        ".Lblock_4530:\n"
        "    movsd xmm0, qword ptr [r14 + rdx*8]\n" /* 04530 */
        "    divsd xmm0, xmm1\n" /* 04536 */
        "    movsd qword ptr [r14 + rdx*8], xmm0\n" /* 0453a */
        "    mulsd xmm0, qword ptr [rdi + rcx*8 - 8]\n" /* 04540 */
        "    mov r8, qword ptr [r9 + rdx*8]\n" /* 04546 */
        "    movsd qword ptr [rdi + r8*8 - 8], xmm0\n" /* 0454a */
        "    inc rdx\n" /* 04551 */
        "    cmp r12, rdx\n" /* 04554 */
        "    jne .Lblock_4530\n" /* 04557 */
        ".Lblock_4559:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_225e0]\n" /* 04559 */
        "    movsd qword ptr [rip + data_rva_22480], xmm0\n" /* 04561 */
        "    movsd xmm0, qword ptr [rip + data_rva_225e8]\n" /* 04569 */
        "    movsd qword ptr [rip + data_rva_22588], xmm0\n" /* 04571 */
        "    mov rcx, qword ptr [rsp + 0x720]\n" /* 04579 */
        "    cmp qword ptr [rcx], 6\n" /* 04581 */
        S9_JL32(.Lblock_4833) /* 04585 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0458b */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 04597 */
        "    mov edx, dword ptr [rcx + 0x20]\n" /* 0459e */
        "    mov dword ptr [rsp + 0x1c8], 0x2010b\n" /* 045a1 */
        "    mov qword ptr [rsp + 0x368], rax\n" /* 045ac */
        "    lea rax, [rip + data_rva_1fa74]\n" /* 045b4 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 045bb */
        "    lea rax, [rsp + 0x368]\n" /* 045c0 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 045c8 */
        "    lea r14, [rsp + 0xd0]\n" /* 045cd */
        "    mov rcx, r14\n" /* 045d5 */
        "    movabs r8, 0x801208384ff00\n" /* 045d8 */
        "    lea r9, [rsp + 0x1c8]\n" /* 045e2 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 045ea */
        "    movsd xmm0, qword ptr [rip + data_rva_225e8]\n" /* 045ef */
        "    mov dword ptr [rsp + 0x1c4], 0x20130\n" /* 045f7 */
        "    movsd qword ptr [rsp + 0x360], xmm0\n" /* 04602 */
        "    mov rcx, r14\n" /* 0460b */
        "    lea rdx, [rsp + 0x1c4]\n" /* 0460e */
        "    lea r8, [rsp + 0x360]\n" /* 04616 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0461e */
        "    movsd xmm0, qword ptr [rip + data_rva_225e0]\n" /* 04623 */
        "    mov dword ptr [rsp + 0x1c0], 0x20130\n" /* 0462b */
        "    movsd qword ptr [rsp + 0x358], xmm0\n" /* 04636 */
        "    mov rcx, r14\n" /* 0463f */
        "    lea rdx, [rsp + 0x1c0]\n" /* 04642 */
        "    lea r8, [rsp + 0x358]\n" /* 0464a */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 04652 */
        "    movsd xmm0, qword ptr [rip + data_rva_22488]\n" /* 04657 */
        "    mov dword ptr [rsp + 0x1bc], 0x20130\n" /* 0465f */
        "    movsd qword ptr [rsp + 0x350], xmm0\n" /* 0466a */
        "    mov rcx, r14\n" /* 04673 */
        "    lea rdx, [rsp + 0x1bc]\n" /* 04676 */
        "    lea r8, [rsp + 0x350]\n" /* 0467e */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 04686 */
        "    movsd xmm0, qword ptr [rip + data_rva_22598]\n" /* 0468b */
        "    mov dword ptr [rsp + 0x1b8], 0x10130\n" /* 04693 */
        "    movsd qword ptr [rsp + 0x348], xmm0\n" /* 0469e */
        "    mov rcx, r14\n" /* 046a7 */
        "    lea rdx, [rsp + 0x1b8]\n" /* 046aa */
        "    lea r8, [rsp + 0x348]\n" /* 046b2 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 046ba */
        "    mov rax, qword ptr [rsp + 0x720]\n" /* 046bf */
        "    cmp qword ptr [rax], 7\n" /* 046c7 */
        S9_JL32(.Lblock_4833) /* 046cb */
        "    mov rax, qword ptr [rip + data_rva_226e0]\n" /* 046d1 */
        "    test rax, rax\n" /* 046d8 */
        "    mov ecx, 0\n" /* 046db */
        "    cmovle rax, rcx\n" /* 046e0 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 046e4 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 046f0 */
        "    mov edx, dword ptr [rcx + 0x20]\n" /* 046f7 */
        "    mov dword ptr [rsp + 0x1b4], 0x10730\n" /* 046fa */
        "    mov qword ptr [rsp + 0x5c8], 1\n" /* 04705 */
        "    mov rcx, qword ptr [rsp + 0x770]\n" /* 04711 */
        "    mov qword ptr [rsp + 0x5d0], rcx\n" /* 04719 */
        "    mov qword ptr [rsp + 0x5d8], 1\n" /* 04721 */
        "    mov qword ptr [rsp + 0x5e0], rax\n" /* 0472d */
        "    mov qword ptr [rsp + 0x5e8], 8\n" /* 04735 */
        "    lea rax, [rip + data_rva_1fa48]\n" /* 04741 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 04748 */
        "    lea rax, [rsp + 0x5c8]\n" /* 0474d */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 04755 */
        "    lea rcx, [rsp + 0xd0]\n" /* 0475a */
        "    movabs r8, 0x801208384ff00\n" /* 04762 */
        "    lea r9, [rsp + 0x1b4]\n" /* 0476c */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 04774 */
        "    mov rax, qword ptr [rsp + 0x720]\n" /* 04779 */
        "    cmp qword ptr [rax], 7\n" /* 04781 */
        S9_JL32(.Lblock_4833) /* 04785 */
        "    mov rax, qword ptr [rip + data_rva_226e0]\n" /* 0478b */
        "    test rax, rax\n" /* 04792 */
        "    mov ecx, 0\n" /* 04795 */
        "    cmovle rax, rcx\n" /* 0479a */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0479e */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 047aa */
        "    mov edx, dword ptr [rcx + 0x20]\n" /* 047b1 */
        "    mov dword ptr [rsp + 0x1b0], 0x10730\n" /* 047b4 */
        "    mov qword ptr [rsp + 0x5a0], 1\n" /* 047bf */
        "    mov rcx, qword ptr [rsp + 0x778]\n" /* 047cb */
        "    mov qword ptr [rsp + 0x5a8], rcx\n" /* 047d3 */
        "    mov qword ptr [rsp + 0x5b0], 1\n" /* 047db */
        "    mov qword ptr [rsp + 0x5b8], rax\n" /* 047e7 */
        "    mov qword ptr [rsp + 0x5c0], 8\n" /* 047ef */
        "    lea rax, [rip + data_rva_1fa1c]\n" /* 047fb */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 04802 */
        "    lea rax, [rsp + 0x5a0]\n" /* 04807 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0480f */
        "    lea rcx, [rsp + 0xd0]\n" /* 04814 */
        "    movabs r8, 0x801208384ff00\n" /* 0481c */
        "    lea r9, [rsp + 0x1b0]\n" /* 04826 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0482e */
        ".Lblock_4833:\n"
        "    cmp qword ptr [rip + data_rva_226f8], 4\n" /* 04833 */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 0483b */
        "    mov r14, qword ptr [rsp + 0x7d8]\n" /* 04843 */
        "    jl .Lblock_48a1\n" /* 0484b */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0484d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 04859 */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 04860 */
        "    mov word ptr [rsp + 0x108], 1\n" /* 04863 */
        "    lea rax, [rip + data_rva_1f67c]\n" /* 0486d */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 04874 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 04879 */
        "    lea rcx, [rsp + 0xd0]\n" /* 04882 */
        "    movabs r8, 0x801208384ff00\n" /* 0488a */
        "    lea r9, [rsp + 0x108]\n" /* 04894 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0489c */
        ".Lblock_48a1:\n"
        "    lea rax, [rip + data_rva_226c0]\n" /* 048a1 */
        "    mov qword ptr [rsp + 0x98], rax\n" /* 048a8 */
        "    mov rax, qword ptr [rsp + 0x110]\n" /* 048b0 */
        "    mov qword ptr [rsp + 0x90], rax\n" /* 048b8 */
        "    mov rax, qword ptr [rsp + 0x118]\n" /* 048c0 */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 048c8 */
        "    lea rax, [rip + data_rva_22738]\n" /* 048d0 */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 048d7 */
        "    lea rax, [rip + data_rva_22748]\n" /* 048df */
        "    mov qword ptr [rsp + 0x78], rax\n" /* 048e6 */
        "    mov rax, qword ptr [rsp + 0xc8]\n" /* 048eb */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 048f3 */
        "    lea rax, [rip + data_rva_226f8]\n" /* 048f8 */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 048ff */
        "    lea rax, [rip + data_rva_225e0]\n" /* 04904 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 0490b */
        "    lea rax, [rip + data_rva_225a0]\n" /* 04910 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 04917 */
        "    lea rax, [rip + data_rva_22600]\n" /* 0491c */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 04923 */
        "    lea rax, [rip + data_rva_225d8]\n" /* 04928 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 0492f */
        "    lea rax, [rip + data_rva_22760]\n" /* 04934 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 0493b */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 04940 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 04947 */
        "    lea rax, [rip + data_rva_22770]\n" /* 0494c */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 04953 */
        "    lea rax, [rip + data_rva_22750]\n" /* 04958 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0495f */
        "    mov qword ptr [rsp + 0x20], rbx\n" /* 04964 */
        "    mov rcx, rdi\n" /* 04969 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 0496c */
        "    mov r8, rdx\n" /* 04973 */
        "    mov r9, rdx\n" /* 04976 */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 04979 */
        "    mov rax, qword ptr [rip + data_rva_22798]\n" /* 0497e */
        "    movsd xmm0, qword ptr [rdi + rax*8 - 8]\n" /* 04985 */
        "    movsd qword ptr [rip + data_rva_225e0], xmm0\n" /* 0498b */
        "    mov rax, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 04993 */
        "    movsd xmm0, qword ptr [rax + 0x178]\n" /* 0499a */
        "    movsd qword ptr [rip + data_rva_22478], xmm0\n" /* 049a2 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 049aa */
        "    mov rax, qword ptr [rax + 0x10]\n" /* 049b1 */
        "    test rax, rax\n" /* 049b5 */
        S9_JLE32(.Lblock_4a4d) /* 049b8 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 049be */
        "    mov r9, qword ptr [rcx]\n" /* 049c5 */
        "    mov r10, qword ptr [rcx + 8]\n" /* 049c8 */
        "    mov rcx, qword ptr [rip + data_rva_22720]\n" /* 049cc */
        "    mov rdx, qword ptr [rip + data_rva_22710]\n" /* 049d3 */
        "    mov r11, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 049da */
        "    mov r8, qword ptr [r11 + 0x78]\n" /* 049e1 */
        "    add r8, r9\n" /* 049e5 */
        "    mov rdi, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 049e8 */
        "    lea r8, [rdi + r8*8]\n" /* 049ef */
        "    add r8, -8\n" /* 049f3 */
        "    add r9, qword ptr [r11 + 0x90]\n" /* 049f7 */
        "    lea r9, [rdi + r9*8]\n" /* 049fe */
        "    add r9, -8\n" /* 04a02 */
        "    add r10, qword ptr [r11 + 0xc8]\n" /* 04a06 */
        "    lea r10, [rdi + r10*8]\n" /* 04a0d */
        "    add r10, -8\n" /* 04a11 */
        "    xor r11d, r11d\n" /* 04a15 */
        S9_NOP8 /* 04a18 */
        ".Lblock_4a20:\n"
        "    mov rdi, qword ptr [r10 + r11*8]\n" /* 04a20 */
        "    movsd xmm0, qword ptr [r9 + r11*8]\n" /* 04a24 */
        "    lea rbx, [rcx + rdi]\n" /* 04a2a */
        "    movsd qword ptr [r14 + rbx*8 - 8], xmm0\n" /* 04a2e */
        "    movsd xmm0, qword ptr [r8 + r11*8]\n" /* 04a35 */
        "    add rdi, rdx\n" /* 04a3b */
        "    movsd qword ptr [r14 + rdi*8 - 8], xmm0\n" /* 04a3e */
        "    inc r11\n" /* 04a45 */
        "    cmp r11, rax\n" /* 04a48 */
        "    jl .Lblock_4a20\n" /* 04a4b */
        ".Lblock_4a4d:\n"
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 04a4d */
        "    lea rdx, [rip + data_rva_226c0]\n" /* 04a54 */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 04a5b */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 04a60 */
        "    cmp rax, 1\n" /* 04a67 */
        S9_JE32(.Lblock_5965) /* 04a6b */
        "    jle .Lblock_4ac4\n" /* 04a71 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 04a73 */
        "    lea rdx, [rip + data_rva_1efc0]\n" /* 04a7a */
        "    mov r8, qword ptr [rsp + 0x240]\n" /* 04a81 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 04a89 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 04a8e */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 04a95 */
        "    lea r8, [rip + rdata_rva_197c0]\n" /* 04a9c */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 04aa3 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 04aab */
        "    lea rcx, [rip + data_rva_226c0]\n" /* 04ab0 */
        "    mov rdx, qword ptr [rsp + 0xa8]\n" /* 04ab7 */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 04abf */
        ".Lblock_4ac4:\n"
        "    cmp qword ptr [rip + data_rva_226f8], 3\n" /* 04ac4 */
        "    mov rdi, qword ptr [rsp + 0x728]\n" /* 04acc */
        "    jle .Lblock_4b2a\n" /* 04ad4 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 04ad6 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 04ae2 */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 04ae9 */
        "    mov word ptr [rsp + 0x106], 1\n" /* 04aec */
        "    lea rax, [rip + data_rva_1f650]\n" /* 04af6 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 04afd */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 04b02 */
        "    lea rcx, [rsp + 0xd0]\n" /* 04b0b */
        "    movabs r8, 0x801208384ff00\n" /* 04b13 */
        "    lea r9, [rsp + 0x106]\n" /* 04b1d */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 04b25 */
        ".Lblock_4b2a:\n"
        "    lea rax, [rip + data_rva_226c0]\n" /* 04b2a */
        "    mov qword ptr [rsp + 0x98], rax\n" /* 04b31 */
        "    mov rax, qword ptr [rsp + 0x258]\n" /* 04b39 */
        "    mov qword ptr [rsp + 0x90], rax\n" /* 04b41 */
        "    mov rax, qword ptr [rsp + 0x260]\n" /* 04b49 */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 04b51 */
        "    lea rax, [rip + data_rva_22738]\n" /* 04b59 */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 04b60 */
        "    lea rax, [rip + data_rva_22748]\n" /* 04b68 */
        "    mov qword ptr [rsp + 0x78], rax\n" /* 04b6f */
        "    mov rax, qword ptr [rsp + 0xc8]\n" /* 04b74 */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 04b7c */
        "    lea rax, [rip + data_rva_226f8]\n" /* 04b81 */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 04b88 */
        "    lea rax, [rip + data_rva_225e8]\n" /* 04b8d */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 04b94 */
        "    lea rax, [rip + data_rva_225f8]\n" /* 04b99 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 04ba0 */
        "    lea rax, [rip + data_rva_22608]\n" /* 04ba5 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 04bac */
        "    lea rax, [rip + data_rva_225d8]\n" /* 04bb1 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 04bb8 */
        "    lea rax, [rip + data_rva_22760]\n" /* 04bbd */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 04bc4 */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 04bc9 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 04bd0 */
        "    lea rax, [rip + data_rva_22768]\n" /* 04bd5 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 04bdc */
        "    lea rax, [rip + data_rva_22750]\n" /* 04be1 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 04be8 */
        "    mov qword ptr [rsp + 0x20], rdi\n" /* 04bed */
        "    mov rcx, rbp\n" /* 04bf2 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 04bf5 */
        "    mov r8, rdx\n" /* 04bfc */
        "    mov r9, rdx\n" /* 04bff */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 04c02 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_NCOMP_rva_19218]\n" /* 04c07 */
        "    mov r12, qword ptr [rax]\n" /* 04c0e */
        "    test r12, r12\n" /* 04c11 */
        "    mov rbx, qword ptr [rsp + 0xb0]\n" /* 04c14 */
        "    mov rcx, qword ptr [rsp + 0x740]\n" /* 04c1c */
        "    mov rbp, qword ptr [rsp + 0x738]\n" /* 04c24 */
        "    jle .Lblock_4c89\n" /* 04c2c */
        "    cmp r12, 0xd\n" /* 04c2e */
        "    jb .Lblock_4c66\n" /* 04c32 */
        "    shl r12, 3\n" /* 04c34 */
        "    xor edx, edx\n" /* 04c38 */
        "    mov r8, r12\n" /* 04c3a */
        /* Both direct calls here reach the dispatch helper at 0xccd0. */
        "    call sub_18000CCD0_rva_ccd0\n" /* 04c3d */
        "    mov rcx, qword ptr [rsp + 0x738]\n" /* 04c42 */
        "    xor edx, edx\n" /* 04c4a */
        "    mov r8, r12\n" /* 04c4c */
        "    call sub_18000CCD0_rva_ccd0\n" /* 04c4f */
        "    mov rbp, qword ptr [rsp + 0x738]\n" /* 04c54 */
        "    mov rcx, qword ptr [rsp + 0x740]\n" /* 04c5c */
        "    jmp .Lblock_4c89\n" /* 04c64 */
        ".Lblock_4c66:\n"
        "    xor eax, eax\n" /* 04c66 */
        S9_NOP8 /* 04c68 */
        ".Lblock_4c70:\n"
        "    mov qword ptr [rcx + rax*8], 0\n" /* 04c70 */
        "    mov qword ptr [rbp + rax*8], 0\n" /* 04c78 */
        "    inc rax\n" /* 04c81 */
        "    cmp r12, rax\n" /* 04c84 */
        "    jne .Lblock_4c70\n" /* 04c87 */
        ".Lblock_4c89:\n"
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 04c89 */
        "    mov rax, qword ptr [rax + 0x10]\n" /* 04c90 */
        "    test rax, rax\n" /* 04c94 */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 04c97 */
        "    mov rdi, rcx\n" /* 04c9f */
        S9_JLE32(.Lblock_4d30) /* 04ca2 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 04ca8 */
        "    mov r8, qword ptr [rcx]\n" /* 04caf */
        "    mov r9, qword ptr [rcx + 8]\n" /* 04cb2 */
        "    mov rcx, qword ptr [rip + data_rva_22728]\n" /* 04cb6 */
        "    mov r10, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 04cbd */
        "    mov rdx, qword ptr [r10 + 0x90]\n" /* 04cc4 */
        "    add rdx, r8\n" /* 04ccb */
        "    mov r11, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 04cce */
        "    lea rdx, [r11 + rdx*8]\n" /* 04cd5 */
        "    add rdx, -8\n" /* 04cd9 */
        "    add r8, qword ptr [r10 + 0x78]\n" /* 04cdd */
        "    lea r8, [r11 + r8*8]\n" /* 04ce1 */
        "    add r8, -8\n" /* 04ce5 */
        "    add r9, qword ptr [r10 + 0xc8]\n" /* 04ce9 */
        "    lea r9, [r11 + r9*8]\n" /* 04cf0 */
        "    add r9, -8\n" /* 04cf4 */
        "    xor r10d, r10d\n" /* 04cf8 */
        S9_NOP5 /* 04cfb */
        ".Lblock_4d00:\n"
        "    mov r11, qword ptr [r9 + r10*8]\n" /* 04d00 */
        "    movsd xmm0, qword ptr [r8 + r10*8]\n" /* 04d04 */
        "    movsd qword ptr [rdi + r11*8 - 8], xmm0\n" /* 04d0a */
        "    movsd xmm0, qword ptr [rdx + r10*8]\n" /* 04d11 */
        "    movsd qword ptr [rbp + r11*8 - 8], xmm0\n" /* 04d17 */
        "    add r11, rcx\n" /* 04d1e */
        "    movsd qword ptr [r14 + r11*8 - 8], xmm0\n" /* 04d21 */
        "    inc r10\n" /* 04d28 */
        "    cmp r10, rax\n" /* 04d2b */
        "    jl .Lblock_4d00\n" /* 04d2e */
        ".Lblock_4d30:\n"
        "    mov rax, qword ptr [rip + data_rva_226e0]\n" /* 04d30 */
        "    test rax, rax\n" /* 04d37 */
        "    mov r8, qword ptr [rsp + 0x7b8]\n" /* 04d3a */
        "    jle .Lblock_4d73\n" /* 04d42 */
        "    xor ecx, ecx\n" /* 04d44 */
        S9_NOP10 /* 04d46 */
        ".Lblock_4d50:\n"
        "    mov rdx, qword ptr [r8 + rcx*8]\n" /* 04d50 */
        "    movsd xmm0, qword ptr [rdi + rdx*8 - 8]\n" /* 04d54 */
        "    movsd qword ptr [rdi + rcx*8], xmm0\n" /* 04d5a */
        "    movsd xmm0, qword ptr [rbp + rdx*8 - 8]\n" /* 04d5f */
        "    movsd qword ptr [rbp + rcx*8], xmm0\n" /* 04d65 */
        "    inc rcx\n" /* 04d6b */
        "    cmp rcx, rax\n" /* 04d6e */
        "    jl .Lblock_4d50\n" /* 04d71 */
        ".Lblock_4d73:\n"
        "    mov rax, qword ptr [rip + data_rva_22798]\n" /* 04d73 */
        "    mov rbp, qword ptr [rsp + 0xc0]\n" /* 04d7a */
        "    movsd xmm0, qword ptr [rbp + rax*8 - 8]\n" /* 04d82 */
        "    movsd qword ptr [rip + data_rva_225e8], xmm0\n" /* 04d88 */
        "    mov rax, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 04d90 */
        "    movsd xmm0, qword ptr [rax + 0x170]\n" /* 04d97 */
        "    movsd xmm1, qword ptr [rax + 0x178]\n" /* 04d9f */
        "    movsd qword ptr [rip + data_rva_22470], xmm0\n" /* 04da7 */
        "    movsd qword ptr [rip + data_rva_22468], xmm1\n" /* 04daf */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 04db7 */
        "    lea rdx, [rip + data_rva_226c0]\n" /* 04dbe */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 04dc5 */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 04dca */
        "    cmp rax, 1\n" /* 04dd1 */
        "    lea r14, [rip + rdata_rva_19840]\n" /* 04dd5 */
        S9_JE32(.Lblock_59bc) /* 04ddc */
        "    jle .Lblock_4e35\n" /* 04de2 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 04de4 */
        "    lea rdx, [rip + data_rva_1ef20]\n" /* 04deb */
        "    mov r8, qword ptr [rsp + 0x240]\n" /* 04df2 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 04dfa */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 04dff */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 04e06 */
        "    lea r8, [rip + rdata_rva_197d0]\n" /* 04e0d */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 04e14 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 04e1c */
        "    lea rcx, [rip + data_rva_226c0]\n" /* 04e21 */
        "    mov rdx, qword ptr [rsp + 0xa8]\n" /* 04e28 */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 04e30 */
        ".Lblock_4e35:\n"
        "    cmp qword ptr [rip + data_rva_22748], 1\n" /* 04e35 */
        "    jne .Lblock_4e4a\n" /* 04e3d */
        "    mov qword ptr [rip + data_rva_22748], 2\n" /* 04e3f */
        ".Lblock_4e4a:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_225e8]\n" /* 04e4a */
        "    subsd xmm0, qword ptr [rip + data_rva_22588]\n" /* 04e52 */
        "    andpd xmm0, xmm8\n" /* 04e5a */
        "    movsd xmm1, qword ptr [rip + data_rva_225e0]\n" /* 04e5f */
        "    subsd xmm1, qword ptr [rip + data_rva_22480]\n" /* 04e67 */
        "    andpd xmm1, xmm8\n" /* 04e6f */
        "    addsd xmm1, xmm0\n" /* 04e74 */
        "    ucomisd xmm1, qword ptr [rip + data_rva_224f8]\n" /* 04e78 */
        "    ja .Lblock_4ece\n" /* 04e80 */
        "    movsd xmm0, qword ptr [rip + data_rva_22490]\n" /* 04e82 */
        "    movsd xmm1, qword ptr [rip + data_rva_22610]\n" /* 04e8a */
        "    subsd xmm0, xmm1\n" /* 04e92 */
        "    divsd xmm0, xmm1\n" /* 04e96 */
        "    movsd xmm1, qword ptr [rip + data_rva_22498]\n" /* 04e9a */
        "    movsd xmm2, qword ptr [rip + data_rva_22618]\n" /* 04ea2 */
        "    subsd xmm1, xmm2\n" /* 04eaa */
        "    divsd xmm1, xmm2\n" /* 04eae */
        "    andpd xmm0, xmm8\n" /* 04eb2 */
        "    andpd xmm1, xmm8\n" /* 04eb7 */
        "    addsd xmm1, xmm0\n" /* 04ebc */
        "    ucomisd xmm1, qword ptr [rip + data_rva_224f0]\n" /* 04ec0 */
        S9_JBE32(.Lblock_5a13) /* 04ec8 */
        ".Lblock_4ece:\n"
        "    mov rax, qword ptr [rip + data_rva_22538]\n" /* 04ece */
        "    lea rcx, [rax + 1]\n" /* 04ed5 */
        "    mov qword ptr [rip + data_rva_22538], rcx\n" /* 04ed9 */
        "    cmp rax, qword ptr [rip + data_rva_22758]\n" /* 04ee0 */
        S9_JL32(.Lblock_3a2d) /* 04ee7 */
        ".Lblock_4eed:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 04eed */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 04ef2 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 04ef9 */
        "    mov qword ptr [rsp + 0x30], r14\n" /* 04efe */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 04f03 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 04f08 */
        "    add rax, 0x38\n" /* 04f0f */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 04f13 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 04f18 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 04f1f */
        "    lea r8, [rip + rdata_rva_19788]\n" /* 04f26 */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 04f2d */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 04f35 */
        "    test rax, rax\n" /* 04f3a */
        "    je .Lblock_4fbc\n" /* 04f3d */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 04f3f */
        "    mov dword ptr [rsp + 0x234], 0x10638\n" /* 04f4b */
        "    mov qword ptr [rsp + 0x458], 0x320\n" /* 04f56 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 04f62 */
        "    mov qword ptr [rsp + 0x460], rax\n" /* 04f69 */
        "    mov qword ptr [rsp + 0x468], 0x50\n" /* 04f71 */
        "    lea rax, [rip + data_rva_20454]\n" /* 04f7d */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 04f84 */
        "    lea rcx, [rsp + 0xd0]\n" /* 04f89 */
        "    lea r8, [rsp + 0x234]\n" /* 04f91 */
        "    lea r9, [rsp + 0x458]\n" /* 04f99 */
        "    movabs rdx, 0x801208384ff00\n" /* 04fa1 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 04fab */
        "    lea rcx, [rip + rdata_rva_19848]\n" /* 04fb0 */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 04fb7 */
        ".Lblock_4fbc:\n"
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 04fbc */
        "    mov qword ptr [rax], 0xfffffffffffffffc\n" /* 04fc4 */
        S9_JMP32(.Lblock_587e) /* 04fcb */
        ".Lblock_4fd0:\n"
        "    mov rsi, qword ptr [rsp + 0x720]\n" /* 04fd0 */
        "    mov qword ptr [rsi + 0x20], 0xfffffffffffffffc\n" /* 04fd8 */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 04fe0 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 04fe5 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 04fec */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 04ff1 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 04ff8 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 04ffd */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 05002 */
        "    add rax, 0x38\n" /* 05009 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0500d */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 05012 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 05019 */
        "    lea r8, [rip + rdata_rva_19820]\n" /* 05020 */
        "    mov r9, rsi\n" /* 05027 */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 0502a */
        "    test rax, rax\n" /* 0502f */
        "    mov rbx, qword ptr [rsp + 0xb0]\n" /* 05032 */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 0503a */
        S9_JE32(.Lblock_587e) /* 05042 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05048 */
        "    mov dword ptr [rsp + 0x128], 0x10638\n" /* 05054 */
        "    mov qword ptr [rsp + 0x440], 0x320\n" /* 0505f */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 0506b */
        "    mov qword ptr [rsp + 0x448], rax\n" /* 05072 */
        "    mov qword ptr [rsp + 0x450], 0x50\n" /* 0507a */
        "    lea rax, [rip + data_rva_203d8]\n" /* 05086 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0508d */
        "    lea rcx, [rsp + 0xd0]\n" /* 05092 */
        "    lea r8, [rsp + 0x128]\n" /* 0509a */
        "    lea r9, [rsp + 0x440]\n" /* 050a2 */
        ".Lblock_50aa:\n"
        "    movabs rdx, 0x801208384ff00\n" /* 050aa */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 050b4 */
        "    lea rcx, [rip + rdata_rva_19848]\n" /* 050b9 */
        ".Lblock_50c0:\n"
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 050c0 */
        S9_JMP32(.Lblock_587e) /* 050c5 */
        ".Lblock_50ca:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 050ca */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 050cf */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 050d6 */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 050db */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 050e2 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 050e7 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 050ec */
        "    add rax, 0x38\n" /* 050f3 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 050f7 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 050fc */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 05103 */
        "    lea r8, [rip + rdata_rva_19798]\n" /* 0510a */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 05111 */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 05119 */
        "    test rax, rax\n" /* 0511e */
        S9_JE32(.Lblock_5867) /* 05121 */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_ERRTWO_rva_191f0]\n" /* 05127 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 0512e */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05132 */
        "    mov dword ptr [rsp + 0x22e], 0x10b0638\n" /* 0513e */
        "    mov word ptr [rsp + 0x232], 2\n" /* 05149 */
        "    mov qword ptr [rsp + 0x580], 0x320\n" /* 05153 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 0515f */
        "    mov qword ptr [rsp + 0x588], rcx\n" /* 05166 */
        "    mov qword ptr [rsp + 0x590], 0x50\n" /* 0516e */
        "    mov qword ptr [rsp + 0x598], rax\n" /* 0517a */
        "    lea rax, [rip + data_rva_1ff38]\n" /* 05182 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05189 */
        "    lea r14, [rsp + 0xd0]\n" /* 0518e */
        "    lea r8, [rsp + 0x22e]\n" /* 05196 */
        "    lea r9, [rsp + 0x580]\n" /* 0519e */
        "    mov rcx, r14\n" /* 051a6 */
        "    movabs rdx, 0x801208384ff00\n" /* 051a9 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 051b3 */
        "    mov rax, qword ptr [rip + data_rva_22700]\n" /* 051b8 */
        "    movsd xmm0, qword ptr [r15 + rax*8 - 8]\n" /* 051bf */
        "    mov dword ptr [rsp + 0x22a], 0x20130\n" /* 051c6 */
        "    movsd qword ptr [rsp + 0x408], xmm0\n" /* 051d1 */
        "    lea rdx, [rsp + 0x22a]\n" /* 051da */
        "    lea r8, [rsp + 0x408]\n" /* 051e2 */
        "    mov rcx, r14\n" /* 051ea */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 051ed */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 051f2 */
        "    mov dword ptr [rsp + 0x226], 0x2010b\n" /* 051f6 */
        "    mov qword ptr [rsp + 0x400], rax\n" /* 05201 */
        "    lea rdx, [rsp + 0x226]\n" /* 05209 */
        "    lea r8, [rsp + 0x400]\n" /* 05211 */
        "    mov rcx, r14\n" /* 05219 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 0521c */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 05221 */
        "    mov dword ptr [rsp + 0x222], 0x2010b\n" /* 05225 */
        "    mov qword ptr [rsp + 0x3f8], rax\n" /* 05230 */
        "    lea rdx, [rsp + 0x222]\n" /* 05238 */
        "    lea r8, [rsp + 0x3f8]\n" /* 05240 */
        "    mov rcx, r14\n" /* 05248 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 0524b */
        "    movsd xmm0, qword ptr [rip + data_rva_225e8]\n" /* 05250 */
        "    mov dword ptr [rsp + 0x21e], 0x20130\n" /* 05258 */
        "    movsd qword ptr [rsp + 0x3f0], xmm0\n" /* 05263 */
        "    lea rdx, [rsp + 0x21e]\n" /* 0526c */
        "    lea r8, [rsp + 0x3f0]\n" /* 05274 */
        "    mov rcx, r14\n" /* 0527c */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 0527f */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 05284 */
        "    mov dword ptr [rsp + 0x21a], 0x1010b\n" /* 05288 */
        "    mov qword ptr [rsp + 0x3e8], rax\n" /* 05293 */
        "    lea rdx, [rsp + 0x21a]\n" /* 0529b */
        "    lea r8, [rsp + 0x3e8]\n" /* 052a3 */
        S9_JMP32(.Lblock_5853) /* 052ab */
        ".Lblock_52b0:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 052b0 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 052b5 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 052bc */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 052c1 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 052c8 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 052cd */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 052d2 */
        "    add rax, 0x38\n" /* 052d9 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 052dd */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 052e2 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 052e9 */
        "    lea r8, [rip + rdata_rva_197a0]\n" /* 052f0 */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 052f7 */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 052ff */
        "    test rax, rax\n" /* 05304 */
        S9_JE32(.Lblock_5867) /* 05307 */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_ERRTWO_rva_191f0]\n" /* 0530d */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 05314 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05318 */
        "    mov dword ptr [rsp + 0x214], 0x10b0638\n" /* 05324 */
        "    mov word ptr [rsp + 0x218], 2\n" /* 0532f */
        "    mov qword ptr [rsp + 0x560], 0x320\n" /* 05339 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 05345 */
        "    mov qword ptr [rsp + 0x568], rcx\n" /* 0534c */
        "    mov qword ptr [rsp + 0x570], 0x50\n" /* 05354 */
        "    mov qword ptr [rsp + 0x578], rax\n" /* 05360 */
        "    lea rax, [rip + data_rva_1fe10]\n" /* 05368 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0536f */
        "    mov rdi, r14\n" /* 05374 */
        "    lea r14, [rsp + 0xd0]\n" /* 05377 */
        "    lea r8, [rsp + 0x214]\n" /* 0537f */
        "    lea r9, [rsp + 0x560]\n" /* 05387 */
        "    mov rcx, r14\n" /* 0538f */
        "    movabs rdx, 0x801208384ff00\n" /* 05392 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 0539c */
        "    mov rax, qword ptr [rip + data_rva_22700]\n" /* 053a1 */
        "    movsd xmm0, qword ptr [rdi + rax*8 - 8]\n" /* 053a8 */
        "    mov dword ptr [rsp + 0x210], 0x20130\n" /* 053ae */
        "    movsd qword ptr [rsp + 0x3e0], xmm0\n" /* 053b9 */
        "    lea rdx, [rsp + 0x210]\n" /* 053c2 */
        "    lea r8, [rsp + 0x3e0]\n" /* 053ca */
        "    mov rcx, r14\n" /* 053d2 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 053d5 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 053da */
        "    mov dword ptr [rsp + 0x20c], 0x2010b\n" /* 053de */
        "    mov qword ptr [rsp + 0x3d8], rax\n" /* 053e9 */
        "    lea rdx, [rsp + 0x20c]\n" /* 053f1 */
        "    lea r8, [rsp + 0x3d8]\n" /* 053f9 */
        "    mov rcx, r14\n" /* 05401 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05404 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 05409 */
        "    mov dword ptr [rsp + 0x208], 0x2010b\n" /* 0540d */
        "    mov qword ptr [rsp + 0x3d0], rax\n" /* 05418 */
        "    lea rdx, [rsp + 0x208]\n" /* 05420 */
        "    lea r8, [rsp + 0x3d0]\n" /* 05428 */
        "    mov rcx, r14\n" /* 05430 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05433 */
        "    movsd xmm0, qword ptr [rip + data_rva_225e0]\n" /* 05438 */
        "    mov dword ptr [rsp + 0x204], 0x20130\n" /* 05440 */
        "    movsd qword ptr [rsp + 0x3c8], xmm0\n" /* 0544b */
        "    lea rdx, [rsp + 0x204]\n" /* 05454 */
        "    lea r8, [rsp + 0x3c8]\n" /* 0545c */
        "    mov rcx, r14\n" /* 05464 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05467 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 0546c */
        "    mov dword ptr [rsp + 0x200], 0x1010b\n" /* 05470 */
        "    mov qword ptr [rsp + 0x3c0], rax\n" /* 0547b */
        "    lea rdx, [rsp + 0x200]\n" /* 05483 */
        "    lea r8, [rsp + 0x3c0]\n" /* 0548b */
        S9_JMP32(.Lblock_5853) /* 05493 */
        ".Lblock_5498:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 05498 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 0549d */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 054a4 */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 054a9 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 054b0 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 054b5 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 054ba */
        "    add rax, 0x38\n" /* 054c1 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 054c5 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 054ca */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 054d1 */
        "    lea r8, [rip + rdata_rva_197a8]\n" /* 054d8 */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 054df */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 054e7 */
        "    test rax, rax\n" /* 054ec */
        S9_JE32(.Lblock_5867) /* 054ef */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_ERRTWO_rva_191f0]\n" /* 054f5 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 054fc */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05500 */
        "    mov dword ptr [rsp + 0x1fa], 0x10b0638\n" /* 0550c */
        "    mov word ptr [rsp + 0x1fe], 2\n" /* 05517 */
        "    mov qword ptr [rsp + 0x540], 0x320\n" /* 05521 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 0552d */
        "    mov qword ptr [rsp + 0x548], rcx\n" /* 05534 */
        "    mov qword ptr [rsp + 0x550], 0x50\n" /* 0553c */
        "    mov qword ptr [rsp + 0x558], rax\n" /* 05548 */
        "    lea rax, [rip + data_rva_1fce4]\n" /* 05550 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05557 */
        "    lea r14, [rsp + 0xd0]\n" /* 0555c */
        "    lea r8, [rsp + 0x1fa]\n" /* 05564 */
        "    lea r9, [rsp + 0x540]\n" /* 0556c */
        "    mov rcx, r14\n" /* 05574 */
        "    movabs rdx, 0x801208384ff00\n" /* 05577 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 05581 */
        "    movsd xmm0, qword ptr [rip + data_rva_22610]\n" /* 05586 */
        "    mov dword ptr [rsp + 0x1f6], 0x20130\n" /* 0558e */
        "    movsd qword ptr [rsp + 0x3b8], xmm0\n" /* 05599 */
        "    lea rdx, [rsp + 0x1f6]\n" /* 055a2 */
        "    lea r8, [rsp + 0x3b8]\n" /* 055aa */
        "    mov rcx, r14\n" /* 055b2 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 055b5 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 055ba */
        "    mov dword ptr [rsp + 0x1f2], 0x2010b\n" /* 055be */
        "    mov qword ptr [rsp + 0x3b0], rax\n" /* 055c9 */
        "    lea rdx, [rsp + 0x1f2]\n" /* 055d1 */
        "    lea r8, [rsp + 0x3b0]\n" /* 055d9 */
        "    mov rcx, r14\n" /* 055e1 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 055e4 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 055e9 */
        "    mov dword ptr [rsp + 0x1ee], 0x2010b\n" /* 055ed */
        "    mov qword ptr [rsp + 0x3a8], rax\n" /* 055f8 */
        "    lea rdx, [rsp + 0x1ee]\n" /* 05600 */
        "    lea r8, [rsp + 0x3a8]\n" /* 05608 */
        "    mov rcx, r14\n" /* 05610 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05613 */
        "    movsd xmm0, qword ptr [rip + data_rva_225e8]\n" /* 05618 */
        "    mov dword ptr [rsp + 0x1ea], 0x20130\n" /* 05620 */
        "    movsd qword ptr [rsp + 0x3a0], xmm0\n" /* 0562b */
        "    lea rdx, [rsp + 0x1ea]\n" /* 05634 */
        "    lea r8, [rsp + 0x3a0]\n" /* 0563c */
        "    mov rcx, r14\n" /* 05644 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05647 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 0564c */
        "    mov dword ptr [rsp + 0x1e6], 0x1010b\n" /* 05650 */
        "    mov qword ptr [rsp + 0x398], rax\n" /* 0565b */
        "    lea rdx, [rsp + 0x1e6]\n" /* 05663 */
        "    lea r8, [rsp + 0x398]\n" /* 0566b */
        S9_JMP32(.Lblock_5853) /* 05673 */
        ".Lblock_5678:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 05678 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 0567d */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 05684 */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 05689 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 05690 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 05695 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 0569a */
        "    add rax, 0x38\n" /* 056a1 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 056a5 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 056aa */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 056b1 */
        "    lea r8, [rip + rdata_rva_197b0]\n" /* 056b8 */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 056bf */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 056c7 */
        "    test rax, rax\n" /* 056cc */
        S9_JE32(.Lblock_5867) /* 056cf */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_ERRTWO_rva_191f0]\n" /* 056d5 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 056dc */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 056e0 */
        "    mov dword ptr [rsp + 0x1e0], 0x10b0638\n" /* 056ec */
        "    mov word ptr [rsp + 0x1e4], 2\n" /* 056f7 */
        "    mov qword ptr [rsp + 0x520], 0x320\n" /* 05701 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 0570d */
        "    mov qword ptr [rsp + 0x528], rcx\n" /* 05714 */
        "    mov qword ptr [rsp + 0x530], 0x50\n" /* 0571c */
        "    mov qword ptr [rsp + 0x538], rax\n" /* 05728 */
        "    lea rax, [rip + data_rva_1fbbc]\n" /* 05730 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05737 */
        "    lea r14, [rsp + 0xd0]\n" /* 0573c */
        "    lea r8, [rsp + 0x1e0]\n" /* 05744 */
        "    lea r9, [rsp + 0x520]\n" /* 0574c */
        "    mov rcx, r14\n" /* 05754 */
        "    movabs rdx, 0x801208384ff00\n" /* 05757 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 05761 */
        "    movsd xmm0, qword ptr [rip + data_rva_22618]\n" /* 05766 */
        "    mov dword ptr [rsp + 0x1dc], 0x20130\n" /* 0576e */
        "    movsd qword ptr [rsp + 0x390], xmm0\n" /* 05779 */
        "    lea rdx, [rsp + 0x1dc]\n" /* 05782 */
        "    lea r8, [rsp + 0x390]\n" /* 0578a */
        "    mov rcx, r14\n" /* 05792 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05795 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 0579a */
        "    mov dword ptr [rsp + 0x1d8], 0x2010b\n" /* 0579e */
        "    mov qword ptr [rsp + 0x388], rax\n" /* 057a9 */
        "    lea rdx, [rsp + 0x1d8]\n" /* 057b1 */
        "    lea r8, [rsp + 0x388]\n" /* 057b9 */
        "    mov rcx, r14\n" /* 057c1 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 057c4 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 057c9 */
        "    mov dword ptr [rsp + 0x1d4], 0x2010b\n" /* 057cd */
        "    mov qword ptr [rsp + 0x380], rax\n" /* 057d8 */
        "    lea rdx, [rsp + 0x1d4]\n" /* 057e0 */
        "    lea r8, [rsp + 0x380]\n" /* 057e8 */
        "    mov rcx, r14\n" /* 057f0 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 057f3 */
        "    movsd xmm0, qword ptr [rip + data_rva_225e0]\n" /* 057f8 */
        "    mov dword ptr [rsp + 0x1d0], 0x20130\n" /* 05800 */
        "    movsd qword ptr [rsp + 0x378], xmm0\n" /* 0580b */
        "    lea rdx, [rsp + 0x1d0]\n" /* 05814 */
        "    lea r8, [rsp + 0x378]\n" /* 0581c */
        "    mov rcx, r14\n" /* 05824 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05827 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 0582c */
        "    mov dword ptr [rsp + 0x1cc], 0x1010b\n" /* 05830 */
        "    mov qword ptr [rsp + 0x370], rax\n" /* 0583b */
        "    lea rdx, [rsp + 0x1cc]\n" /* 05843 */
        "    lea r8, [rsp + 0x370]\n" /* 0584b */
        ".Lblock_5853:\n"
        "    mov rcx, r14\n" /* 05853 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05856 */
        "    lea rcx, [rip + rdata_rva_197f8]\n" /* 0585b */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 05862 */
        ".Lblock_5867:\n"
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 05867 */
        "    mov qword ptr [rax], 0xfffffffffffffff0\n" /* 0586f */
        ".Lblock_5876:\n"
        "    mov rbx, qword ptr [rsp + 0xb0]\n" /* 05876 */
        ".Lblock_587e:\n"
        "    mov rax, qword ptr [rip + data_rva_227a0]\n" /* 0587e */
        "    test rax, rax\n" /* 05885 */
        "    jle .Lblock_58c5\n" /* 05888 */
        "    xor ecx, ecx\n" /* 0588a */
        "    movsd xmm0, qword ptr [rip + rdata_rva_19548]\n" /* 0588c */
        S9_NOP12 /* 05894 */
        ".Lblock_58a0:\n"
        "    movsd xmm1, qword ptr [r12 + rcx*8]\n" /* 058a0 */
        "    movapd xmm2, xmm0\n" /* 058a6 */
        "    mulsd xmm2, xmm1\n" /* 058aa */
        "    movsd qword ptr [rbx + rcx*8], xmm2\n" /* 058ae */
        "    mulsd xmm1, xmm0\n" /* 058b3 */
        "    movsd qword ptr [rbp + rcx*8], xmm1\n" /* 058b7 */
        "    inc rcx\n" /* 058bd */
        "    cmp rcx, rax\n" /* 058c0 */
        "    jl .Lblock_58a0\n" /* 058c3 */
        ".Lblock_58c5:\n"
        "    mov rax, qword ptr [rip + data_rva_22798]\n" /* 058c5 */
        "    mov rcx, qword ptr [rip + data_rva_22778]\n" /* 058cc */
        "    cmp rcx, rax\n" /* 058d3 */
        "    jl .Lblock_58f9\n" /* 058d6 */
        "    dec rax\n" /* 058d8 */
        S9_NOP5 /* 058db */
        ".Lblock_58e0:\n"
        "    movsd xmm0, qword ptr [r12 + rax*8]\n" /* 058e0 */
        "    movsd qword ptr [rbx + rax*8], xmm0\n" /* 058e6 */
        "    movsd qword ptr [rbp + rax*8], xmm0\n" /* 058eb */
        "    inc rax\n" /* 058f1 */
        "    cmp rax, rcx\n" /* 058f4 */
        "    jl .Lblock_58e0\n" /* 058f7 */
        ".Lblock_58f9:\n"
        "    movaps xmm6, xmmword ptr [rsp + 0x5f0]\n" /* 058f9 */
        "    movaps xmm7, xmmword ptr [rsp + 0x600]\n" /* 05901 */
        "    movaps xmm8, xmmword ptr [rsp + 0x610]\n" /* 05909 */
        "    movaps xmm9, xmmword ptr [rsp + 0x620]\n" /* 05912 */
        "    movaps xmm10, xmmword ptr [rsp + 0x630]\n" /* 0591b */
        "    movaps xmm11, xmmword ptr [rsp + 0x640]\n" /* 05924 */
        "    movaps xmm12, xmmword ptr [rsp + 0x650]\n" /* 0592d */
        "    movaps xmm13, xmmword ptr [rsp + 0x660]\n" /* 05936 */
        "    movaps xmm14, xmmword ptr [rsp + 0x670]\n" /* 0593f */
        "    movaps xmm15, xmmword ptr [rsp + 0x680]\n" /* 05948 */
        "    add rsp, 0x698\n" /* 05951 */
        "    pop rbx\n" /* 05958 */
        "    pop rbp\n" /* 05959 */
        "    pop rdi\n" /* 0595a */
        "    pop rsi\n" /* 0595b */
        "    pop r12\n" /* 0595c */
        "    pop r13\n" /* 0595e */
        "    pop r14\n" /* 05960 */
        "    pop r15\n" /* 05962 */
        "    ret\n" /* 05964 */
        ".Lblock_5965:\n"
        "    mov r8d, 0xb0\n" /* 05965 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 0596b */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 05972 */
        "    lea rdx, [rip + data_rva_1f360]\n" /* 05979 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 05980 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 05985 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 0598c */
        "    lea r8, [rip + rdata_rva_197b8]\n" /* 05993 */
        "    mov rsi, qword ptr [rsp + 0x720]\n" /* 0599a */
        "    mov r9, rsi\n" /* 059a2 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 059a5 */
        "    mov qword ptr [rsi + 0x20], 0xfffffffffffffff9\n" /* 059aa */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 059b2 */
        S9_JMP32(.Lblock_5876) /* 059b7 */
        ".Lblock_59bc:\n"
        "    mov r8d, 0xb0\n" /* 059bc */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 059c2 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 059c9 */
        "    lea rdx, [rip + data_rva_1f2c0]\n" /* 059d0 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 059d7 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 059dc */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 059e3 */
        "    lea r8, [rip + rdata_rva_197c8]\n" /* 059ea */
        "    mov rsi, qword ptr [rsp + 0x720]\n" /* 059f1 */
        "    mov r9, rsi\n" /* 059f9 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 059fc */
        "    mov qword ptr [rsi + 0x20], 0xfffffffffffffff8\n" /* 05a01 */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 05a09 */
        S9_JMP32(.Lblock_587e) /* 05a0e */
        ".Lblock_5a13:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 05a13 */
        "    movsd xmm8, qword ptr [rip + data_rva_22488]\n" /* 05a18 */
        "    xorpd xmm0, xmm0\n" /* 05a21 */
        "    ucomisd xmm0, xmm8\n" /* 05a25 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 05a2a */
        S9_JB32(.Lblock_5b34) /* 05a32 */
        "    lea rdx, [rip + rdata_rva_19848]\n" /* 05a38 */
        "    mov qword ptr [rsp + 0x38], rdx\n" /* 05a3f */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 05a44 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 05a4b */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 05a50 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 05a55 */
        "    add rax, 0x38\n" /* 05a5c */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05a60 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 05a65 */
        "    lea r8, [rip + rdata_rva_197d8]\n" /* 05a6c */
        "    mov r9, r15\n" /* 05a73 */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 05a76 */
        "    test rax, rax\n" /* 05a7b */
        S9_JE32(.Lblock_5b1c) /* 05a7e */
        "    movsd xmm0, qword ptr [rip + data_rva_22488]\n" /* 05a84 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05a8c */
        "    mov dword ptr [rsp + 0x1aa], 0x1300638\n" /* 05a98 */
        "    mov word ptr [rsp + 0x1ae], 1\n" /* 05aa3 */
        "    mov qword ptr [rsp + 0x500], 0x320\n" /* 05aad */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 05ab9 */
        "    mov qword ptr [rsp + 0x508], rax\n" /* 05ac0 */
        "    mov qword ptr [rsp + 0x510], 0x50\n" /* 05ac8 */
        "    movsd qword ptr [rsp + 0x518], xmm0\n" /* 05ad4 */
        "    lea rax, [rip + data_rva_20204]\n" /* 05add */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05ae4 */
        "    lea rcx, [rsp + 0xd0]\n" /* 05ae9 */
        "    lea r8, [rsp + 0x1aa]\n" /* 05af1 */
        "    lea r9, [rsp + 0x500]\n" /* 05af9 */
        "    movabs rdx, 0x801208384ff00\n" /* 05b01 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 05b0b */
        "    lea rcx, [rip + rdata_rva_197f8]\n" /* 05b10 */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 05b17 */
        ".Lblock_5b1c:\n"
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 05b1c */
        "    mov qword ptr [rax], 0xfffffffffffffff3\n" /* 05b24 */
        "    movsd xmm8, qword ptr [rip + data_rva_22488]\n" /* 05b2b */
        ".Lblock_5b34:\n"
        "    mov rsi, qword ptr [rip + data_rva_22700]\n" /* 05b34 */
        "    mov rdi, qword ptr [rsp + 0x760]\n" /* 05b3b */
        "    movsd xmm0, qword ptr [rdi + rsi*8 - 8]\n" /* 05b43 */
        "    divsd xmm0, qword ptr [rip + data_rva_224c0]\n" /* 05b49 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 05b51 */
        "    movapd xmm6, xmm0\n" /* 05b56 */
        "    movsd xmm0, qword ptr [rip + data_rva_224b8]\n" /* 05b5a */
        "    mov rax, qword ptr [rip + data_rva_22708]\n" /* 05b62 */
        "    divsd xmm0, qword ptr [rdi + rax*8 - 8]\n" /* 05b69 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 05b6f */
        "    movapd xmm7, xmm0\n" /* 05b74 */
        "    mov rax, qword ptr [rsp + 0x778]\n" /* 05b78 */
        "    mulsd xmm7, qword ptr [rax + rsi*8 - 8]\n" /* 05b80 */
        "    addsd xmm7, xmm6\n" /* 05b86 */
        "    mov rax, qword ptr [rsp + 0x770]\n" /* 05b8a */
        "    movsd xmm0, qword ptr [rax + rsi*8 - 8]\n" /* 05b92 */
        "    call thunk_libmmd_dll_log_rva_15400\n" /* 05b98 */
        "    divsd xmm7, xmm0\n" /* 05b9d */
        "    movsd qword ptr [rip + data_rva_22460], xmm7\n" /* 05ba1 */
        "    ucomisd xmm7, xmm8\n" /* 05ba9 */
        S9_JBE32(.Lblock_5d43) /* 05bae */
        "    lea rdx, [rip + rdata_rva_19848]\n" /* 05bb4 */
        "    mov qword ptr [rsp + 0x38], rdx\n" /* 05bbb */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 05bc0 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 05bc7 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 05bcc */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 05bd1 */
        "    add rax, 0x38\n" /* 05bd8 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05bdc */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 05be1 */
        "    lea r8, [rip + rdata_rva_197e0]\n" /* 05be8 */
        "    mov r9, r15\n" /* 05bef */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 05bf2 */
        "    test rax, rax\n" /* 05bf7 */
        S9_JE32(.Lblock_5d34) /* 05bfa */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_ERRTWO_rva_191f0]\n" /* 05c00 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 05c07 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05c0b */
        "    mov dword ptr [rsp + 0x1a4], 0x10b0638\n" /* 05c17 */
        "    mov word ptr [rsp + 0x1a8], 2\n" /* 05c22 */
        "    mov qword ptr [rsp + 0x4e0], 0x320\n" /* 05c2c */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 05c38 */
        "    mov qword ptr [rsp + 0x4e8], rcx\n" /* 05c3f */
        "    mov qword ptr [rsp + 0x4f0], 0x50\n" /* 05c47 */
        "    mov qword ptr [rsp + 0x4f8], rax\n" /* 05c53 */
        "    lea rax, [rip + data_rva_2013c]\n" /* 05c5b */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05c62 */
        "    lea r12, [rsp + 0xd0]\n" /* 05c67 */
        "    lea r8, [rsp + 0x1a4]\n" /* 05c6f */
        "    lea r9, [rsp + 0x4e0]\n" /* 05c77 */
        "    mov rcx, r12\n" /* 05c7f */
        "    movabs rdx, 0x801208384ff00\n" /* 05c82 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 05c8c */
        "    movsd xmm0, qword ptr [rip + data_rva_22460]\n" /* 05c91 */
        "    mov dword ptr [rsp + 0x1a0], 0x20130\n" /* 05c99 */
        "    movsd qword ptr [rsp + 0x340], xmm0\n" /* 05ca4 */
        "    lea rdx, [rsp + 0x1a0]\n" /* 05cad */
        "    lea r8, [rsp + 0x340]\n" /* 05cb5 */
        "    mov rcx, r12\n" /* 05cbd */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05cc0 */
        "    mov rax, qword ptr [rsi + 0x78]\n" /* 05cc5 */
        "    mov dword ptr [rsp + 0x19c], 0x2010b\n" /* 05cc9 */
        "    mov qword ptr [rsp + 0x338], rax\n" /* 05cd4 */
        "    lea rdx, [rsp + 0x19c]\n" /* 05cdc */
        "    lea r8, [rsp + 0x338]\n" /* 05ce4 */
        "    mov rcx, r12\n" /* 05cec */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05cef */
        "    movsd xmm0, qword ptr [rip + data_rva_22488]\n" /* 05cf4 */
        "    mov dword ptr [rsp + 0x198], 0x10130\n" /* 05cfc */
        "    movsd qword ptr [rsp + 0x330], xmm0\n" /* 05d07 */
        "    lea rdx, [rsp + 0x198]\n" /* 05d10 */
        "    lea r8, [rsp + 0x330]\n" /* 05d18 */
        "    mov rcx, r12\n" /* 05d20 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 05d23 */
        "    lea rcx, [rip + rdata_rva_19848]\n" /* 05d28 */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 05d2f */
        ".Lblock_5d34:\n"
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 05d34 */
        "    mov qword ptr [rax], 0xfffffffffffffff2\n" /* 05d3c */
        ".Lblock_5d43:\n"
        "    mov rsi, qword ptr [rip + data_rva_226e0]\n" /* 05d43 */
        "    test rsi, rsi\n" /* 05d4a */
        S9_JLE32(.Lblock_5e21) /* 05d4d */
        "    movsd xmm7, qword ptr [rip + data_rva_22610]\n" /* 05d53 */
        "    movsd xmm8, qword ptr [rip + data_rva_22618]\n" /* 05d5b */
        "    xor edi, edi\n" /* 05d64 */
        "    movsd xmm6, qword ptr [rip + rdata_rva_19550]\n" /* 05d66 */
        "    mov r14, qword ptr [rsp + 0x770]\n" /* 05d6e */
        "    mov r12, qword ptr [rsp + 0x768]\n" /* 05d76 */
        "    mov r15, qword ptr [rsp + 0x778]\n" /* 05d7e */
        ".Lblock_5d86:\n"
        "    movapd xmm0, xmm7\n" /* 05d86 */
        "    mulsd xmm0, xmm8\n" /* 05d8a */
        "    movsd xmm1, qword ptr [r15 + rdi*8]\n" /* 05d8f */
        "    subsd xmm1, xmm6\n" /* 05d95 */
        "    divsd xmm1, xmm9\n" /* 05d99 */
        "    call thunk_libmmd_dll_pow_rva_15406\n" /* 05d9e */
        "    mulsd xmm0, qword ptr [r14 + rdi*8]\n" /* 05da3 */
        "    movsd qword ptr [r12 + rdi*8], xmm0\n" /* 05da9 */
        "    inc rdi\n" /* 05daf */
        "    cmp rdi, rsi\n" /* 05db2 */
        "    jl .Lblock_5d86\n" /* 05db5 */
        "    movabs rax, 0x4197d78400000000\n" /* 05db7 */
        "    mov qword ptr [rip + data_rva_22458], rax\n" /* 05dc1 */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196e0]\n" /* 05dc8 */
        "    xor eax, eax\n" /* 05dd0 */
        "    xorpd xmm1, xmm1\n" /* 05dd2 */
        "    mov rdi, r12\n" /* 05dd6 */
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 05dd9 */
        "    jmp .Lblock_5deb\n" /* 05de1 */
        ".Lblock_5de3:\n"
        "    inc rax\n" /* 05de3 */
        "    cmp rsi, rax\n" /* 05de6 */
        "    je .Lblock_5e42\n" /* 05de9 */
        ".Lblock_5deb:\n"
        "    movsd xmm3, qword ptr [r13 + rax*8]\n" /* 05deb */
        "    movsd xmm2, qword ptr [rdi + rax*8]\n" /* 05df2 */
        "    ucomisd xmm2, xmm6\n" /* 05df7 */
        "    seta dl\n" /* 05dfb */
        "    ucomisd xmm0, xmm2\n" /* 05dfe */
        "    seta cl\n" /* 05e02 */
        "    ucomisd xmm3, xmm1\n" /* 05e05 */
        "    jbe .Lblock_5de3\n" /* 05e09 */
        "    test dl, dl\n" /* 05e0b */
        "    je .Lblock_5de3\n" /* 05e0d */
        "    test cl, cl\n" /* 05e0f */
        "    je .Lblock_5de3\n" /* 05e11 */
        "    movsd qword ptr [rip + data_rva_22458], xmm2\n" /* 05e13 */
        "    movapd xmm0, xmm2\n" /* 05e1b */
        "    jmp .Lblock_5de3\n" /* 05e1f */
        ".Lblock_5e21:\n"
        "    movabs rax, 0x4197d78400000000\n" /* 05e21 */
        "    mov qword ptr [rip + data_rva_22458], rax\n" /* 05e2b */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196e0]\n" /* 05e32 */
        "    mov rdi, qword ptr [rsp + 0x768]\n" /* 05e3a */
        ".Lblock_5e42:\n"
        "    cmp qword ptr [r15], 7\n" /* 05e42 */
        "    jl .Lblock_5eb2\n" /* 05e46 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 05e48 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 05e54 */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 05e5b */
        "    mov dword ptr [rsp + 0x194], 0x10130\n" /* 05e5e */
        "    movsd qword ptr [rsp + 0x328], xmm0\n" /* 05e69 */
        "    lea rax, [rip + data_rva_1f9e0]\n" /* 05e72 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 05e79 */
        "    lea rax, [rsp + 0x328]\n" /* 05e7e */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05e86 */
        "    lea rcx, [rsp + 0xd0]\n" /* 05e8b */
        "    lea r9, [rsp + 0x194]\n" /* 05e93 */
        "    movabs r8, 0x801208384ff00\n" /* 05e9b */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 05ea5 */
        "    movsd xmm0, qword ptr [rip + data_rva_22458]\n" /* 05eaa */
        ".Lblock_5eb2:\n"
        "    movabs rcx, 0x3ff0000000000000\n" /* 05eb2 */
        "    mov qword ptr [rip + data_rva_226c8], 1\n" /* 05ebc */
        "    movabs rax, 0x3ff000010c6f7a0b\n" /* 05ec7 */
        "    mov qword ptr [rip + data_rva_22640], rax\n" /* 05ed1 */
        "    mulsd xmm0, qword ptr [rip + rdata_rva_196e8]\n" /* 05ed8 */
        "    movsd qword ptr [rip + data_rva_22648], xmm0\n" /* 05ee0 */
        "    movsd xmm1, qword ptr [rip + rdata_rva_196f0]\n" /* 05ee8 */
        "    movapd xmm2, xmm0\n" /* 05ef0 */
        "    subsd xmm2, xmm1\n" /* 05ef4 */
        "    mulsd xmm2, qword ptr [rip + rdata_rva_19560]\n" /* 05ef8 */
        "    movsd qword ptr [rip + data_rva_22650], xmm2\n" /* 05f00 */
        "    mov qword ptr [rip + data_rva_22658], 0\n" /* 05f08 */
        "    movabs rsi, 0x3f0a36e2eb1c432d\n" /* 05f13 */
        "    mov qword ptr [rip + data_rva_22660], rsi\n" /* 05f1d */
        "    mov qword ptr [rip + data_rva_22668], rcx\n" /* 05f24 */
        "    subsd xmm0, xmm1\n" /* 05f2b */
        "    divsd xmm0, qword ptr [rip + rdata_rva_196a0]\n" /* 05f2f */
        "    addsd xmm0, xmm1\n" /* 05f37 */
        "    movsd qword ptr [rip + data_rva_22580], xmm0\n" /* 05f3b */
        "    movsd xmm6, qword ptr [rip + rdata_rva_196f8]\n" /* 05f43 */
        "    lea r14, [rip + data_rva_22590]\n" /* 05f4b */
        "    lea r12, [rip + data_rva_22640]\n" /* 05f52 */
        "    xorpd xmm7, xmm7\n" /* 05f59 */
        ".Lblock_5f5d:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_224a0]\n" /* 05f5d */
        "    addsd xmm0, xmm6\n" /* 05f65 */
        "    movsd qword ptr [rip + data_rva_22590], xmm0\n" /* 05f69 */
        "    mov rax, qword ptr [rip + data_rva_226e0]\n" /* 05f71 */
        "    test rax, rax\n" /* 05f78 */
        "    jle .Lblock_5fc4\n" /* 05f7b */
        "    movsd xmm1, qword ptr [rip + data_rva_22580]\n" /* 05f7d */
        "    xor ecx, ecx\n" /* 05f85 */
        "    jmp .Lblock_5f98\n" /* 05f87 */
        S9_NOP7 /* 05f89 */
        ".Lblock_5f90:\n"
        "    inc rcx\n" /* 05f90 */
        "    cmp rcx, rax\n" /* 05f93 */
        "    jge .Lblock_5fc4\n" /* 05f96 */
        ".Lblock_5f98:\n"
        "    movsd xmm2, qword ptr [r13 + rcx*8]\n" /* 05f98 */
        "    ucomisd xmm2, xmm7\n" /* 05f9f */
        "    jbe .Lblock_5f90\n" /* 05fa3 */
        "    movsd xmm3, qword ptr [rdi + rcx*8]\n" /* 05fa5 */
        "    mulsd xmm2, xmm3\n" /* 05faa */
        "    subsd xmm3, xmm1\n" /* 05fae */
        "    divsd xmm2, xmm3\n" /* 05fb2 */
        "    addsd xmm0, xmm2\n" /* 05fb6 */
        "    movsd qword ptr [rip + data_rva_22590], xmm0\n" /* 05fba */
        "    jmp .Lblock_5f90\n" /* 05fc2 */
        ".Lblock_5fc4:\n"
        "    lea rax, [rip + data_rva_1f1c8]\n" /* 05fc4 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 05fcb */
        "    lea rcx, [rip + data_rva_226c8]\n" /* 05fd0 */
        "    lea rdx, [rip + data_rva_22580]\n" /* 05fd7 */
        "    mov r8, r14\n" /* 05fde */
        "    mov r9, r12\n" /* 05fe1 */
        "    call thunk_zemath_dll_ZMTH_ARCONS_rva_15346\n" /* 05fe4 */
        "    cmp qword ptr [rip + data_rva_226c8], 0\n" /* 05fe9 */
        S9_JS32(.Lblock_6103) /* 05ff1 */
        "    mov rdx, qword ptr [rsp + 0x760]\n" /* 05ff7 */
        S9_JNE32(.Lblock_5f5d) /* 05fff */
        "    movabs rax, 0xbff0000000000000\n" /* 06005 */
        "    mov qword ptr [rip + data_rva_22450], rax\n" /* 0600f */
        "    cmp qword ptr [r15], 5\n" /* 06016 */
        "    jle .Lblock_608e\n" /* 0601a */
        "    movsd xmm0, qword ptr [rip + data_rva_22580]\n" /* 0601c */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 06024 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 06030 */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 06037 */
        "    mov dword ptr [rsp + 0x190], 0x10130\n" /* 0603a */
        "    movsd qword ptr [rsp + 0x320], xmm0\n" /* 06045 */
        "    lea rax, [rip + data_rva_1f9a4]\n" /* 0604e */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 06055 */
        "    lea rax, [rsp + 0x320]\n" /* 0605a */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06062 */
        "    lea rcx, [rsp + 0xd0]\n" /* 06067 */
        "    lea r9, [rsp + 0x190]\n" /* 0606f */
        "    movabs r8, 0x801208384ff00\n" /* 06077 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 06081 */
        "    mov rdx, qword ptr [rsp + 0x760]\n" /* 06086 */
        ".Lblock_608e:\n"
        "    mov rax, qword ptr [rip + data_rva_226e0]\n" /* 0608e */
        "    movsd xmm0, qword ptr [rip + data_rva_22450]\n" /* 06095 */
        "    test rax, rax\n" /* 0609d */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 060a0 */
        "    mov r14, qword ptr [rsp + 0x758]\n" /* 060a8 */
        S9_JLE32(.Lblock_61e3) /* 060b0 */
        "    movsd xmm1, qword ptr [rip + data_rva_22580]\n" /* 060b6 */
        "    xor ecx, ecx\n" /* 060be */
        "    xorpd xmm2, xmm2\n" /* 060c0 */
        "    jmp .Lblock_60d2\n" /* 060c4 */
        ".Lblock_60c6:\n"
        "    inc rcx\n" /* 060c6 */
        "    cmp rcx, rax\n" /* 060c9 */
        S9_JGE32(.Lblock_61e3) /* 060cc */
        ".Lblock_60d2:\n"
        "    movsd xmm3, qword ptr [r13 + rcx*8]\n" /* 060d2 */
        "    ucomisd xmm3, xmm2\n" /* 060d9 */
        "    jbe .Lblock_60c6\n" /* 060dd */
        "    movsd xmm3, qword ptr [rdi + rcx*8]\n" /* 060df */
        "    movsd xmm4, qword ptr [rdx + rcx*8]\n" /* 060e4 */
        "    mulsd xmm4, xmm3\n" /* 060e9 */
        "    subsd xmm3, xmm1\n" /* 060ed */
        "    divsd xmm4, xmm3\n" /* 060f1 */
        "    addsd xmm0, xmm4\n" /* 060f5 */
        "    movsd qword ptr [rip + data_rva_22450], xmm0\n" /* 060f9 */
        "    jmp .Lblock_60c6\n" /* 06101 */
        ".Lblock_6103:\n"
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffffb\n" /* 06103 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 0610b */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 06112 */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 06117 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 0611e */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 06123 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 06128 */
        "    add rax, 0x38\n" /* 0612f */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06133 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 06138 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 0613f */
        "    lea r8, [rip + rdata_rva_19828]\n" /* 06146 */
        "    mov r9, r15\n" /* 0614d */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 06150 */
        "    test rax, rax\n" /* 06155 */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 06158 */
        S9_JE32(.Lblock_587e) /* 06160 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 06166 */
        "    mov dword ptr [rsp + 0x124], 0x10638\n" /* 06172 */
        "    mov qword ptr [rsp + 0x428], 0x320\n" /* 0617d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 06189 */
        "    mov qword ptr [rsp + 0x430], rax\n" /* 06190 */
        "    mov qword ptr [rsp + 0x438], 0x50\n" /* 06198 */
        "    lea rax, [rip + data_rva_20380]\n" /* 061a4 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 061ab */
        "    lea rcx, [rsp + 0xd0]\n" /* 061b0 */
        "    lea r8, [rsp + 0x124]\n" /* 061b8 */
        "    lea r9, [rsp + 0x428]\n" /* 061c0 */
        "    movabs rdx, 0x801208384ff00\n" /* 061c8 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 061d2 */
        "    lea rcx, [rip + rdata_rva_19830]\n" /* 061d7 */
        S9_JMP32(.Lblock_50c0) /* 061de */
        ".Lblock_61e3:\n"
        "    xorpd xmm1, xmm1\n" /* 061e3 */
        "    ucomisd xmm1, xmm0\n" /* 061e7 */
        "    mov r13, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 061eb */
        S9_JB32(.Lblock_636d) /* 061f2 */
        "    lea rdx, [rip + rdata_rva_19848]\n" /* 061f8 */
        "    mov qword ptr [rsp + 0x38], rdx\n" /* 061ff */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 06204 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 0620b */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 06210 */
        "    lea rax, [r13 + 0x38]\n" /* 06215 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06219 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 0621e */
        "    lea r8, [rip + rdata_rva_197e8]\n" /* 06225 */
        "    mov r9, r15\n" /* 0622c */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 0622f */
        "    test rax, rax\n" /* 06234 */
        S9_JE32(.Lblock_6345) /* 06237 */
        "    mov rdi, qword ptr [rip + iat_atdms_dll_DMS_ERRTWO_rva_191f0]\n" /* 0623d */
        "    mov rax, qword ptr [rdi + 0x78]\n" /* 06244 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 06248 */
        "    mov dword ptr [rsp + 0x18a], 0x10b0638\n" /* 06254 */
        "    mov word ptr [rsp + 0x18e], 2\n" /* 0625f */
        "    mov qword ptr [rsp + 0x4c0], 0x320\n" /* 06269 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 06275 */
        "    mov qword ptr [rsp + 0x4c8], rcx\n" /* 0627c */
        "    mov qword ptr [rsp + 0x4d0], 0x50\n" /* 06284 */
        "    mov qword ptr [rsp + 0x4d8], rax\n" /* 06290 */
        "    lea rax, [rip + data_rva_1fb08]\n" /* 06298 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0629f */
        "    lea r14, [rsp + 0xd0]\n" /* 062a4 */
        "    lea r8, [rsp + 0x18a]\n" /* 062ac */
        "    lea r9, [rsp + 0x4c0]\n" /* 062b4 */
        "    mov rcx, r14\n" /* 062bc */
        "    movabs rdx, 0x801208384ff00\n" /* 062bf */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 062c9 */
        "    movsd xmm0, qword ptr [rip + data_rva_22450]\n" /* 062ce */
        "    mov dword ptr [rsp + 0x186], 0x20130\n" /* 062d6 */
        "    movsd qword ptr [rsp + 0x318], xmm0\n" /* 062e1 */
        "    lea rdx, [rsp + 0x186]\n" /* 062ea */
        "    lea r8, [rsp + 0x318]\n" /* 062f2 */
        "    mov rcx, r14\n" /* 062fa */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 062fd */
        "    mov rax, qword ptr [rdi + 0x78]\n" /* 06302 */
        "    mov dword ptr [rsp + 0x182], 0x1010b\n" /* 06306 */
        "    mov qword ptr [rsp + 0x310], rax\n" /* 06311 */
        "    lea rdx, [rsp + 0x182]\n" /* 06319 */
        "    lea r8, [rsp + 0x310]\n" /* 06321 */
        "    mov rcx, r14\n" /* 06329 */
        "    mov r14, qword ptr [rsp + 0x758]\n" /* 0632c */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 06334 */
        "    lea rcx, [rip + rdata_rva_19848]\n" /* 06339 */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 06340 */
        ".Lblock_6345:\n"
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 06345 */
        "    mov qword ptr [rax], 0xfffffffffffffff6\n" /* 0634d */
        "    movabs rax, 0x3fb999999999999a\n" /* 06354 */
        "    mov qword ptr [rip + data_rva_22450], rax\n" /* 0635e */
        "    movsd xmm0, qword ptr [rip + rdata_rva_19700]\n" /* 06365 */
        ".Lblock_636d:\n"
        "    movsd xmm1, qword ptr [rip + data_rva_22500]\n" /* 0636d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 06375 */
        "    movsd xmm2, qword ptr [rax]\n" /* 0637c */
        "    ucomisd xmm1, xmm2\n" /* 06380 */
        S9_JB32(.Lblock_6572) /* 06384 */
        "    movsd xmm0, qword ptr [rip + data_rva_22508]\n" /* 0638a */
        "    movsd xmm1, qword ptr [rip + data_rva_22488]\n" /* 06392 */
        "    ucomisd xmm1, xmm0\n" /* 0639a */
        "    jb .Lblock_63b4\n" /* 0639e */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196a0]\n" /* 063a0 */
        "    mulsd xmm0, xmm1\n" /* 063a8 */
        "    movsd qword ptr [rip + data_rva_22508], xmm0\n" /* 063ac */
        ".Lblock_63b4:\n"
        "    ucomisd xmm0, xmm2\n" /* 063b4 */
        "    movabs rax, 0x3ff0000000000000\n" /* 063b8 */
        "    jb .Lblock_63d8\n" /* 063c2 */
        "    movsd xmm0, qword ptr [rip + rdata_rva_196a0]\n" /* 063c4 */
        "    mulsd xmm0, xmm1\n" /* 063cc */
        "    movsd qword ptr [rip + data_rva_22508], xmm0\n" /* 063d0 */
        ".Lblock_63d8:\n"
        "    mov qword ptr [rip + data_rva_226c8], 1\n" /* 063d8 */
        "    movabs rcx, 0x3eb0c6f7a0b5ed8d\n" /* 063e3 */
        "    mov qword ptr [rip + data_rva_22640], rcx\n" /* 063ed */
        "    movsd xmm2, qword ptr [rip + rdata_rva_19550]\n" /* 063f4 */
        "    movapd xmm3, xmm0\n" /* 063fc */
        "    addsd xmm0, xmm2\n" /* 06400 */
        "    subsd xmm2, qword ptr [rip + rdata_rva_19558]\n" /* 06404 */
        "    mulsd xmm2, qword ptr [rip + rdata_rva_19560]\n" /* 0640c */
        "    mov qword ptr [rip + data_rva_22648], rax\n" /* 06414 */
        "    movsd qword ptr [rip + data_rva_22650], xmm2\n" /* 0641b */
        "    subsd xmm3, xmm1\n" /* 06423 */
        "    divsd xmm3, xmm0\n" /* 06427 */
        "    movsd qword ptr [rip + data_rva_22658], xmm3\n" /* 0642b */
        "    mov qword ptr [rip + data_rva_22660], rsi\n" /* 06433 */
        "    mov qword ptr [rip + data_rva_22668], rax\n" /* 0643a */
        "    movabs rax, 0x3fe0000000000000\n" /* 06441 */
        "    mov qword ptr [rip + data_rva_22578], rax\n" /* 0644b */
        "    lea rsi, [rip + data_rva_22578]\n" /* 06452 */
        "    movss xmm6, dword ptr [rip + rdata_rva_19720]\n" /* 06459 */
        "    movsd xmm7, qword ptr [rip + rdata_rva_19728]\n" /* 06461 */
        "    movsd xmm8, qword ptr [rip + rdata_rva_19730]\n" /* 06469 */
        "    movsd xmm9, qword ptr [rip + rdata_rva_19738]\n" /* 06472 */
        "    movsd xmm10, qword ptr [rip + rdata_rva_19740]\n" /* 0647b */
        "    movsd xmm11, qword ptr [rip + rdata_rva_19748]\n" /* 06484 */
        "    movsd xmm12, qword ptr [rip + rdata_rva_19750]\n" /* 0648d */
        "    movsd xmm13, qword ptr [rip + rdata_rva_19758]\n" /* 06496 */
        "    lea r12, [rip + data_rva_22570]\n" /* 0649f */
        "    lea r13, [rip + data_rva_226c8]\n" /* 064a6 */
        "    lea r14, [rip + data_rva_22640]\n" /* 064ad */
        ".Lblock_64b4:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_22578]\n" /* 064b4 */
        "    xorps xmm1, xmm1\n" /* 064bc */
        "    cvtss2sd xmm1, xmm6\n" /* 064bf */
        "    mulsd xmm1, xmm0\n" /* 064c3 */
        "    addsd xmm1, xmm7\n" /* 064c7 */
        "    mulsd xmm1, xmm0\n" /* 064cb */
        "    addsd xmm1, xmm8\n" /* 064cf */
        "    mulsd xmm1, xmm0\n" /* 064d4 */
        "    addsd xmm1, xmm9\n" /* 064d8 */
        "    mulsd xmm1, xmm0\n" /* 064dd */
        "    addsd xmm1, xmm10\n" /* 064e1 */
        "    mulsd xmm1, xmm0\n" /* 064e6 */
        "    addsd xmm1, xmm11\n" /* 064ea */
        "    mulsd xmm1, xmm0\n" /* 064ef */
        "    addsd xmm1, xmm12\n" /* 064f3 */
        "    mulsd xmm1, xmm0\n" /* 064f8 */
        "    addsd xmm1, xmm13\n" /* 064fc */
        "    movsd qword ptr [rip + data_rva_22570], xmm1\n" /* 06501 */
        "    lea rax, [rip + data_rva_1f1c8]\n" /* 06509 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06510 */
        "    mov rcx, r13\n" /* 06515 */
        "    mov rdx, rsi\n" /* 06518 */
        "    mov r8, r12\n" /* 0651b */
        "    mov r9, r14\n" /* 0651e */
        "    call thunk_zemath_dll_ZMTH_ARCONS_rva_15346\n" /* 06521 */
        "    cmp qword ptr [rip + data_rva_226c8], 0\n" /* 06526 */
        S9_JS32(.Lblock_66e3) /* 0652e */
        S9_JNE32(.Lblock_64b4) /* 06534 */
        "    movsd xmm0, qword ptr [rip + data_rva_22578]\n" /* 0653a */
        "    movsd xmm1, qword ptr [rip + data_rva_22450]\n" /* 06542 */
        "    addsd xmm1, xmm0\n" /* 0654a */
        "    lea rax, [rip + data_rva_22500]\n" /* 0654e */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 06555 */
        "    mov rdi, qword ptr [rsp + 0x7b8]\n" /* 0655d */
        "    mov r14, qword ptr [rsp + 0x758]\n" /* 06565 */
        S9_JMP32(.Lblock_6866) /* 0656d */
        ".Lblock_6572:\n"
        "    ucomisd xmm0, xmm1\n" /* 06572 */
        "    seta al\n" /* 06576 */
        "    ucomisd xmm1, qword ptr [rip + rdata_rva_196f8]\n" /* 06579 */
        S9_JB32(.Lblock_67ad) /* 06581 */
        "    test al, al\n" /* 06587 */
        "    mov rdi, qword ptr [rsp + 0x7b8]\n" /* 06589 */
        S9_JE32(.Lblock_67b5) /* 06591 */
        "    lea rdx, [rip + rdata_rva_19848]\n" /* 06597 */
        "    mov qword ptr [rsp + 0x38], rdx\n" /* 0659e */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 065a3 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 065aa */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 065af */
        "    lea rax, [r13 + 0x38]\n" /* 065b4 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 065b8 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 065bd */
        "    lea r8, [rip + rdata_rva_197f0]\n" /* 065c4 */
        "    mov r9, r15\n" /* 065cb */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 065ce */
        "    test rax, rax\n" /* 065d3 */
        S9_JE32(.Lblock_66ab) /* 065d6 */
        "    movsd xmm0, qword ptr [rip + data_rva_22500]\n" /* 065dc */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 065e4 */
        "    mov dword ptr [rsp + 0x17c], 0x1300638\n" /* 065f0 */
        "    mov word ptr [rsp + 0x180], 2\n" /* 065fb */
        "    mov qword ptr [rsp + 0x4a0], 0x320\n" /* 06605 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 06611 */
        "    mov qword ptr [rsp + 0x4a8], rax\n" /* 06618 */
        "    mov qword ptr [rsp + 0x4b0], 0x50\n" /* 06620 */
        "    movsd qword ptr [rsp + 0x4b8], xmm0\n" /* 0662c */
        "    lea rax, [rip + data_rva_20064]\n" /* 06635 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0663c */
        "    lea r14, [rsp + 0xd0]\n" /* 06641 */
        "    lea r8, [rsp + 0x17c]\n" /* 06649 */
        "    lea r9, [rsp + 0x4a0]\n" /* 06651 */
        "    mov rcx, r14\n" /* 06659 */
        "    movabs rdx, 0x801208384ff00\n" /* 0665c */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 06666 */
        "    movsd xmm0, qword ptr [rip + data_rva_22450]\n" /* 0666b */
        "    mov dword ptr [rsp + 0x178], 0x10130\n" /* 06673 */
        "    movsd qword ptr [rsp + 0x308], xmm0\n" /* 0667e */
        "    lea rdx, [rsp + 0x178]\n" /* 06687 */
        "    lea r8, [rsp + 0x308]\n" /* 0668f */
        "    mov rcx, r14\n" /* 06697 */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 0669a */
        "    lea rcx, [rip + rdata_rva_197f8]\n" /* 0669f */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 066a6 */
        ".Lblock_66ab:\n"
        "    mov rax, qword ptr [rsp + 0xa8]\n" /* 066ab */
        "    mov qword ptr [rax], 0xfffffffffffffff1\n" /* 066b3 */
        "    movsd xmm0, qword ptr [rip + data_rva_22450]\n" /* 066ba */
        "    movsd xmm1, qword ptr [rip + rdata_rva_196a0]\n" /* 066c2 */
        "    mulsd xmm1, xmm0\n" /* 066ca */
        "    movsd qword ptr [rip + data_rva_22500], xmm1\n" /* 066ce */
        "    mov r14, qword ptr [rsp + 0x758]\n" /* 066d6 */
        S9_JMP32(.Lblock_67b5) /* 066de */
        ".Lblock_66e3:\n"
        "    mov qword ptr [r15 + 0x20], 0xfffffffffffffffa\n" /* 066e3 */
        "    lea rax, [rip + rdata_rva_19848]\n" /* 066eb */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 066f2 */
        "    lea rax, [rip + rdata_rva_19840]\n" /* 066f7 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 066fe */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 06703 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 06708 */
        "    add rax, 0x38\n" /* 0670f */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06713 */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 06718 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 0671f */
        "    lea r8, [rip + rdata_rva_19838]\n" /* 06726 */
        "    mov r9, r15\n" /* 0672d */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 06730 */
        "    test rax, rax\n" /* 06735 */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 06738 */
        S9_JE32(.Lblock_587e) /* 06740 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 06746 */
        "    mov dword ptr [rsp + 0x120], 0x10638\n" /* 06752 */
        "    mov qword ptr [rsp + 0x410], 0x320\n" /* 0675d */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 06769 */
        "    mov qword ptr [rsp + 0x418], rax\n" /* 06770 */
        "    mov qword ptr [rsp + 0x420], 0x50\n" /* 06778 */
        "    lea rax, [rip + data_rva_202f4]\n" /* 06784 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0678b */
        "    lea rcx, [rsp + 0xd0]\n" /* 06790 */
        "    lea r8, [rsp + 0x120]\n" /* 06798 */
        "    lea r9, [rsp + 0x410]\n" /* 067a0 */
        S9_JMP32(.Lblock_50aa) /* 067a8 */
        ".Lblock_67ad:\n"
        "    mov rdi, qword ptr [rsp + 0x7b8]\n" /* 067ad */
        ".Lblock_67b5:\n"
        "    ucomisd xmm6, xmm1\n" /* 067b5 */
        "    jbe .Lblock_67cf\n" /* 067b9 */
        "    mulsd xmm1, xmm0\n" /* 067bb */
        "    xorpd xmm1, xmmword ptr [rip + rdata_rva_19710]\n" /* 067bf */
        "    movlpd qword ptr [rip + data_rva_22500], xmm1\n" /* 067c7 */
        ".Lblock_67cf:\n"
        "    movapd xmm2, xmm1\n" /* 067cf */
        "    subsd xmm2, xmm0\n" /* 067d3 */
        "    addsd xmm1, qword ptr [rip + rdata_rva_19550]\n" /* 067d7 */
        "    divsd xmm2, xmm1\n" /* 067df */
        "    movss xmm0, dword ptr [rip + rdata_rva_19720]\n" /* 067e3 */
        "    cvtss2sd xmm0, xmm0\n" /* 067eb */
        "    mulsd xmm0, xmm2\n" /* 067ef */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19728]\n" /* 067f3 */
        "    mulsd xmm0, xmm2\n" /* 067fb */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19730]\n" /* 067ff */
        "    mulsd xmm0, xmm2\n" /* 06807 */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19738]\n" /* 0680b */
        "    mulsd xmm0, xmm2\n" /* 06813 */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19740]\n" /* 06817 */
        "    mulsd xmm0, xmm2\n" /* 0681f */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19748]\n" /* 06823 */
        "    mulsd xmm0, xmm2\n" /* 0682b */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19750]\n" /* 0682f */
        "    movsd qword ptr [rip + data_rva_22578], xmm2\n" /* 06837 */
        "    mulsd xmm0, xmm2\n" /* 0683f */
        "    addsd xmm0, qword ptr [rip + rdata_rva_19758]\n" /* 06843 */
        "    movsd qword ptr [rip + data_rva_22570], xmm0\n" /* 0684b */
        "    movsd xmm1, qword ptr [rip + data_rva_22488]\n" /* 06853 */
        "    addsd xmm1, xmm0\n" /* 0685b */
        "    lea rax, [rip + data_rva_22508]\n" /* 0685f */
        ".Lblock_6866:\n"
        "    movsd xmm6, qword ptr [rip + rdata_rva_19550]\n" /* 06866 */
        "    movapd xmm2, xmm6\n" /* 0686e */
        "    subsd xmm2, xmm0\n" /* 06872 */
        "    divsd xmm1, xmm2\n" /* 06876 */
        "    movsd qword ptr [rax], xmm1\n" /* 0687a */
        "    mov rax, qword ptr [rip + data_rva_226e0]\n" /* 0687e */
        "    mov rdx, qword ptr [rip + data_rva_22700]\n" /* 06885 */
        "    mov rcx, qword ptr [rip + data_rva_22708]\n" /* 0688c */
        "    test rax, rax\n" /* 06893 */
        "    jle .Lblock_6910\n" /* 06896 */
        "    mov r8, qword ptr [rip + data_rva_227a0]\n" /* 06898 */
        "    lea r9, [rdx - 1]\n" /* 0689f */
        "    lea r10, [rcx - 1]\n" /* 068a3 */
        "    xorpd xmm0, xmm0\n" /* 068a7 */
        "    xor r11d, r11d\n" /* 068ab */
        "    xorpd xmm1, xmm1\n" /* 068ae */
        "    jmp .Lblock_68d6\n" /* 068b2 */
        ".Lblock_68b4:\n"
        "    subsd xmm2, xmm3\n" /* 068b4 */
        "    movsd qword ptr [rbp + rsi*8 - 8], xmm2\n" /* 068b8 */
        "    addsd xmm1, xmm3\n" /* 068be */
        "    addsd xmm0, xmm2\n" /* 068c2 */
        "    mov rdi, qword ptr [rsp + 0x7b8]\n" /* 068c6 */
        ".Lblock_68ce:\n"
        "    inc r11\n" /* 068ce */
        "    cmp r11, rax\n" /* 068d1 */
        "    jge .Lblock_6918\n" /* 068d4 */
        ".Lblock_68d6:\n"
        "    cmp r9, r11\n" /* 068d6 */
        "    je .Lblock_68ce\n" /* 068d9 */
        "    cmp r10, r11\n" /* 068db */
        "    je .Lblock_68ce\n" /* 068de */
        "    mov rsi, qword ptr [rdi + r11*8]\n" /* 068e0 */
        "    movsd xmm3, qword ptr [r14 + r11*8]\n" /* 068e4 */
        "    mulsd xmm3, qword ptr [rbx + r8*8 - 8]\n" /* 068ea */
        "    movsd qword ptr [rbx + rsi*8 - 8], xmm3\n" /* 068f1 */
        "    movsd xmm2, qword ptr [r12 + rsi*8 - 8]\n" /* 068f7 */
        "    ucomisd xmm3, xmm2\n" /* 068fe */
        "    jbe .Lblock_68b4\n" /* 06902 */
        "    movsd qword ptr [rbx + rsi*8 - 8], xmm2\n" /* 06904 */
        "    movapd xmm3, xmm2\n" /* 0690a */
        "    jmp .Lblock_68b4\n" /* 0690e */
        ".Lblock_6910:\n"
        "    xorpd xmm0, xmm0\n" /* 06910 */
        "    xorpd xmm1, xmm1\n" /* 06914 */
        ".Lblock_6918:\n"
        "    mov rdx, qword ptr [rdi + rdx*8 - 8]\n" /* 06918 */
        "    movsd xmm2, qword ptr [r12 + rdx*8 - 8]\n" /* 0691d */
        "    movsd xmm3, qword ptr [rip + data_rva_22510]\n" /* 06924 */
        "    mulsd xmm3, xmm2\n" /* 0692c */
        "    movsd qword ptr [rbp + rdx*8 - 8], xmm3\n" /* 06930 */
        "    subsd xmm2, xmm3\n" /* 06936 */
        "    movsd qword ptr [rbx + rdx*8 - 8], xmm2\n" /* 0693a */
        "    addsd xmm2, xmm1\n" /* 06940 */
        "    addsd xmm3, xmm0\n" /* 06944 */
        "    mov rcx, qword ptr [rdi + rcx*8 - 8]\n" /* 06948 */
        "    movsd xmm1, qword ptr [r12 + rcx*8 - 8]\n" /* 0694d */
        "    movsd xmm0, qword ptr [rip + data_rva_22518]\n" /* 06954 */
        "    mulsd xmm0, xmm1\n" /* 0695c */
        "    movsd qword ptr [rbp + rcx*8 - 8], xmm0\n" /* 06960 */
        "    subsd xmm1, xmm0\n" /* 06966 */
        "    movsd qword ptr [rbx + rcx*8 - 8], xmm1\n" /* 0696a */
        "    addsd xmm1, xmm2\n" /* 06970 */
        "    addsd xmm0, xmm3\n" /* 06974 */
        "    test rax, rax\n" /* 06978 */
        "    mov r10, qword ptr [rsp + 0x7b0]\n" /* 0697b */
        "    mov r9, qword ptr [rsp + 0x7a8]\n" /* 06983 */
        "    mov r8, qword ptr [rsp + 0x760]\n" /* 0698b */
        "    jle .Lblock_69d1\n" /* 06993 */
        "    xor ecx, ecx\n" /* 06995 */
        ".Lblock_6997:\n"
        "    mov rdx, qword ptr [rdi + rcx*8]\n" /* 06997 */
        "    movsd xmm2, qword ptr [rbp + rdx*8 - 8]\n" /* 0699b */
        "    divsd xmm2, xmm0\n" /* 069a1 */
        "    movsd qword ptr [r8 + rcx*8], xmm2\n" /* 069a5 */
        "    movsd xmm3, qword ptr [rbx + rdx*8 - 8]\n" /* 069ab */
        "    divsd xmm3, xmm1\n" /* 069b1 */
        "    movsd qword ptr [r14 + rcx*8], xmm3\n" /* 069b5 */
        "    movsd qword ptr [r10 + rdx*8 - 8], xmm2\n" /* 069bb */
        "    movsd qword ptr [r9 + rdx*8 - 8], xmm3\n" /* 069c2 */
        "    inc rcx\n" /* 069c9 */
        "    cmp rcx, rax\n" /* 069cc */
        "    jl .Lblock_6997\n" /* 069cf */
        ".Lblock_69d1:\n"
        "    mov rcx, qword ptr [rip + data_rva_242e0]\n" /* 069d1 */
        "    mov rdx, qword ptr [rsp + 0x710]\n" /* 069d8 */
        "    mov qword ptr [rdx + rcx*8 - 8], rax\n" /* 069e0 */
        "    mov rax, qword ptr [rip + data_rva_227a0]\n" /* 069e5 */
        "    movsd qword ptr [rbp + rax*8 - 8], xmm0\n" /* 069ec */
        "    movsd xmm1, qword ptr [r12 + rax*8 - 8]\n" /* 069f2 */
        "    movapd xmm2, xmm1\n" /* 069f9 */
        "    subsd xmm2, xmm0\n" /* 069fd */
        "    movsd qword ptr [rbx + rax*8 - 8], xmm2\n" /* 06a01 */
        "    divsd xmm0, xmm1\n" /* 06a07 */
        "    movsd qword ptr [rip + data_rva_22598], xmm0\n" /* 06a0b */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 06a13 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 06a1a */
        "    mov rax, qword ptr [rip + data_rva_22790]\n" /* 06a1e */
        "    movsd qword ptr [rbp + rax*8 - 8], xmm0\n" /* 06a25 */
        "    movsd xmm0, qword ptr [rip + data_rva_225f8]\n" /* 06a2b */
        "    mov rax, qword ptr [rip + data_rva_22788]\n" /* 06a33 */
        "    movsd qword ptr [rbp + rax*8 - 8], xmm0\n" /* 06a3a */
        "    movapd xmm1, xmm6\n" /* 06a40 */
        "    subsd xmm1, xmm0\n" /* 06a44 */
        "    mov rax, qword ptr [rip + data_rva_22780]\n" /* 06a48 */
        "    movsd qword ptr [rbp + rax*8 - 8], xmm1\n" /* 06a4f */
        "    mov r13, r14\n" /* 06a55 */
        "    lea r14, [rip + data_rva_226e0]\n" /* 06a58 */
        "    mov rcx, r14\n" /* 06a5f */
        "    mov rdx, rdi\n" /* 06a62 */
        "    call thunk_pputil_dll_PPUTL_AVEMW_rva_1534c\n" /* 06a65 */
        "    mov rax, qword ptr [rip + data_rva_22778]\n" /* 06a6a */
        "    movsd qword ptr [rbp + rax*8 - 8], xmm0\n" /* 06a71 */
        "    movsd xmm0, qword ptr [rsi]\n" /* 06a77 */
        "    mov rax, qword ptr [rip + data_rva_22790]\n" /* 06a7b */
        "    movsd qword ptr [rbx + rax*8 - 8], xmm0\n" /* 06a82 */
        "    mov rcx, r14\n" /* 06a88 */
        "    mov rdx, rdi\n" /* 06a8b */
        "    mov r8, r13\n" /* 06a8e */
        "    call thunk_pputil_dll_PPUTL_AVEMW_rva_1534c\n" /* 06a91 */
        "    mov rcx, qword ptr [rip + data_rva_22778]\n" /* 06a96 */
        "    movsd qword ptr [rbx + rcx*8 - 8], xmm0\n" /* 06a9d */
        "    cmp qword ptr [r15 + 0x10], 0\n" /* 06aa3 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06aa8 */
        "    mov rax, qword ptr [rax + 0x10]\n" /* 06aaf */
        S9_JE32(.Lblock_7016) /* 06ab3 */
        "    movsd xmm1, qword ptr [rip + data_rva_225f8]\n" /* 06ab9 */
        "    movapd xmm2, xmm6\n" /* 06ac1 */
        "    subsd xmm2, xmm1\n" /* 06ac5 */
        "    mulsd xmm2, qword ptr [rip + data_rva_22468]\n" /* 06ac9 */
        "    movsd xmm3, qword ptr [rip + data_rva_22470]\n" /* 06ad1 */
        "    mulsd xmm3, xmm1\n" /* 06ad9 */
        "    addsd xmm3, xmm2\n" /* 06add */
        "    divsd xmm3, qword ptr [rbp + rcx*8 - 8]\n" /* 06ae1 */
        "    mov rcx, qword ptr [rip + data_rva_22790]\n" /* 06ae7 */
        "    movsd qword ptr [rbp + rcx*8 - 8], xmm3\n" /* 06aee */
        "    movsd xmm2, qword ptr [rip + data_rva_22478]\n" /* 06af4 */
        "    divsd xmm2, xmm0\n" /* 06afc */
        "    movsd qword ptr [rbx + rcx*8 - 8], xmm2\n" /* 06b00 */
        "    movsd xmm0, qword ptr [rip + data_rva_22500]\n" /* 06b06 */
        "    movapd xmm2, xmm0\n" /* 06b0e */
        "    addsd xmm2, xmm6\n" /* 06b12 */
        "    movsd qword ptr [rip + data_rva_22448], xmm2\n" /* 06b16 */
        "    test rax, rax\n" /* 06b1e */
        "    mov rdi, qword ptr [rsp + 0x770]\n" /* 06b21 */
        S9_JLE32(.Lblock_6bb2) /* 06b29 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06b2f */
        "    mov rdx, qword ptr [rcx]\n" /* 06b36 */
        "    mov r8, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 06b39 */
        "    mov rcx, qword ptr [r8 + 0x90]\n" /* 06b40 */
        "    add rcx, rdx\n" /* 06b47 */
        "    mov r9, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 06b4a */
        "    lea rcx, [r9 + rcx*8]\n" /* 06b51 */
        "    add rcx, -8\n" /* 06b55 */
        "    add rdx, qword ptr [r8 + 0x78]\n" /* 06b59 */
        "    lea rdx, [r9 + rdx*8]\n" /* 06b5d */
        "    add rdx, -8\n" /* 06b61 */
        "    xor r8d, r8d\n" /* 06b65 */
        ".Lblock_6b68:\n"
        "    movsd xmm3, qword ptr [rcx + r8*8]\n" /* 06b68 */
        "    mulsd xmm3, xmm1\n" /* 06b6e */
        "    movapd xmm4, xmm6\n" /* 06b72 */
        "    subsd xmm4, xmm1\n" /* 06b76 */
        "    movsd xmm5, qword ptr [rdx + r8*8]\n" /* 06b7a */
        "    movapd xmm7, xmm2\n" /* 06b80 */
        "    mulsd xmm7, xmm5\n" /* 06b84 */
        "    mulsd xmm7, xmm4\n" /* 06b88 */
        "    movapd xmm4, xmm1\n" /* 06b8c */
        "    mulsd xmm4, xmm0\n" /* 06b90 */
        "    mulsd xmm4, xmm5\n" /* 06b94 */
        "    addsd xmm4, xmm3\n" /* 06b98 */
        "    addsd xmm4, xmm7\n" /* 06b9c */
        "    divsd xmm4, xmm2\n" /* 06ba0 */
        "    movsd qword ptr [rdi + r8*8], xmm4\n" /* 06ba4 */
        "    inc r8\n" /* 06baa */
        "    cmp r8, rax\n" /* 06bad */
        "    jl .Lblock_6b68\n" /* 06bb0 */
        ".Lblock_6bb2:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_22608]\n" /* 06bb2 */
        "    movapd xmm1, xmm0\n" /* 06bba */
        "    subsd xmm1, qword ptr [rip + data_rva_22600]\n" /* 06bbe */
        "    movsd xmm2, qword ptr [rip + data_rva_22508]\n" /* 06bc6 */
        "    movapd xmm3, xmm2\n" /* 06bce */
        "    subsd xmm3, xmm6\n" /* 06bd2 */
        "    divsd xmm1, xmm3\n" /* 06bd6 */
        "    subsd xmm0, xmm1\n" /* 06bda */
        "    movsd qword ptr [rip + data_rva_22568], xmm0\n" /* 06bde */
        "    movsd xmm0, qword ptr [rip + data_rva_225e8]\n" /* 06be6 */
        "    movapd xmm1, xmm0\n" /* 06bee */
        "    subsd xmm1, qword ptr [rip + data_rva_225e0]\n" /* 06bf2 */
        "    lea r14, [rip + data_rva_22568]\n" /* 06bfa */
        "    subsd xmm2, xmm6\n" /* 06c01 */
        "    divsd xmm1, xmm2\n" /* 06c05 */
        "    subsd xmm0, xmm1\n" /* 06c09 */
        "    movsd qword ptr [rip + data_rva_22588], xmm0\n" /* 06c0d */
        "    lea r15, [rip + data_rva_22588]\n" /* 06c15 */
        "    mov qword ptr [rip + data_rva_226b8], 1\n" /* 06c1c */
        "    lea rsi, [rip + data_rva_226b8]\n" /* 06c27 */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 06c2e */
        "    mov rax, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 06c33 */
        "    mov rax, qword ptr [rax + 0xc8]\n" /* 06c3a */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06c41 */
        "    add rax, qword ptr [rdx + 8]\n" /* 06c48 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 06c4c */
        "    lea rax, [rcx + rax*8]\n" /* 06c53 */
        "    add rax, -8\n" /* 06c57 */
        "    lea rcx, [rip + data_rva_226d0]\n" /* 06c5b */
        "    mov qword ptr [rsp + 0x58], rcx\n" /* 06c62 */
        "    lea rcx, [rip + data_rva_22620]\n" /* 06c67 */
        "    mov qword ptr [rsp + 0x50], rcx\n" /* 06c6e */
        "    lea rcx, [rip + data_rva_22560]\n" /* 06c73 */
        "    mov qword ptr [rsp + 0x48], rcx\n" /* 06c7a */
        "    lea rcx, [rip + rdata_rva_19830]\n" /* 06c7f */
        "    mov qword ptr [rsp + 0x40], rcx\n" /* 06c86 */
        "    mov qword ptr [rsp + 0x38], rsi\n" /* 06c8b */
        "    mov rcx, qword ptr [rsp + 0xc8]\n" /* 06c90 */
        "    mov qword ptr [rsp + 0x30], rcx\n" /* 06c98 */
        "    mov rcx, qword ptr [rsp + 0x728]\n" /* 06c9d */
        "    mov qword ptr [rsp + 0x28], rcx\n" /* 06ca5 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06caa */
        "    lea r9, [rdx + 0x10]\n" /* 06caf */
        "    mov rcx, r15\n" /* 06cb3 */
        "    mov rdx, r14\n" /* 06cb6 */
        "    mov r8, rdi\n" /* 06cb9 */
        "    call thunk_ppmon_dll_PPMON_ENTHV_rva_1535e\n" /* 06cbc */
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 06cc1 */
        "    movsd xmm0, qword ptr [rip + data_rva_225f8]\n" /* 06cc6 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 06cce */
        "    movsd xmm1, qword ptr [rax + 8]\n" /* 06cd5 */
        "    ucomisd xmm1, xmm0\n" /* 06cda */
        "    jbe .Lblock_6cf0\n" /* 06cde */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06ce0 */
        "    mov rax, qword ptr [rax + 0x10]\n" /* 06ce7 */
        S9_JMP32(.Lblock_7016) /* 06ceb */
        ".Lblock_6cf0:\n"
        "    mov qword ptr [rip + data_rva_22750], 3\n" /* 06cf0 */
        "    movsd qword ptr [rip + data_rva_225a0], xmm0\n" /* 06cfb */
        "    call thunk_atdms_dll_DMS_PPENT_rva_1527a\n" /* 06d03 */
        "    cmp qword ptr [rip + data_rva_226f8], 4\n" /* 06d08 */
        "    jl .Lblock_6d66\n" /* 06d10 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 06d12 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 06d1e */
        "    mov edx, dword ptr [rax + 0x20]\n" /* 06d25 */
        "    mov word ptr [rsp + 0x104], 1\n" /* 06d28 */
        "    lea rax, [rip + data_rva_1f650]\n" /* 06d32 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 06d39 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 06d3e */
        "    lea rcx, [rsp + 0xd0]\n" /* 06d47 */
        "    lea r9, [rsp + 0x104]\n" /* 06d4f */
        "    movabs r8, 0x801208384ff00\n" /* 06d57 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 06d61 */
        ".Lblock_6d66:\n"
        "    mov rcx, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 06d66 */
        "    mov rax, qword ptr [rcx + 0xc0]\n" /* 06d6d */
        "    mov rcx, qword ptr [rcx + 0xe8]\n" /* 06d74 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06d7b */
        "    add rax, qword ptr [rdx]\n" /* 06d82 */
        "    mov r8, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 06d85 */
        "    lea rax, [r8 + rax*8]\n" /* 06d8c */
        "    add rax, -8\n" /* 06d90 */
        "    add rcx, qword ptr [rdx + 8]\n" /* 06d94 */
        "    lea rcx, [r8 + rcx*8]\n" /* 06d98 */
        "    add rcx, -8\n" /* 06d9c */
        "    mov qword ptr [rsp + 0x90], rcx\n" /* 06da0 */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 06da8 */
        "    lea rax, [rip + data_rva_22738]\n" /* 06db0 */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 06db7 */
        "    lea rax, [rip + data_rva_226d8]\n" /* 06dbf */
        "    mov qword ptr [rsp + 0x78], rax\n" /* 06dc6 */
        "    mov rax, qword ptr [rsp + 0xc8]\n" /* 06dcb */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 06dd3 */
        "    lea rax, [rip + data_rva_226f8]\n" /* 06dd8 */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 06ddf */
        "    lea rax, [rip + data_rva_225e8]\n" /* 06de4 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 06deb */
        "    lea rax, [rip + data_rva_225a0]\n" /* 06df0 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 06df7 */
        "    lea rax, [rip + data_rva_22608]\n" /* 06dfc */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 06e03 */
        "    lea rax, [rip + data_rva_225d8]\n" /* 06e08 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 06e0f */
        "    lea rax, [rip + data_rva_22760]\n" /* 06e14 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 06e1b */
        "    lea rsi, [rip + data_rva_226e8]\n" /* 06e20 */
        "    mov qword ptr [rsp + 0x98], rsi\n" /* 06e27 */
        "    lea rax, [rip + data_rva_1ede0]\n" /* 06e2f */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 06e36 */
        "    lea rax, [rip + data_rva_22768]\n" /* 06e3b */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 06e42 */
        "    lea rax, [rip + data_rva_22750]\n" /* 06e47 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 06e4e */
        "    mov rax, qword ptr [rsp + 0x728]\n" /* 06e53 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 06e5b */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 06e60 */
        "    mov rcx, rbp\n" /* 06e67 */
        "    mov r8, rdx\n" /* 06e6a */
        "    mov r9, rdx\n" /* 06e6d */
        "    call thunk_ppflash_dll_FLSH_FLASH_rva_1536a\n" /* 06e70 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 06e75 */
        "    mov rdx, rsi\n" /* 06e7c */
        "    call thunk_ppflash_dll_FLSH_FLSTAT_rva_15370\n" /* 06e7f */
        "    mov qword ptr [rip + data_rva_227a8], rax\n" /* 06e84 */
        "    cmp rax, 1\n" /* 06e8b */
        "    jne .Lblock_6ee0\n" /* 06e8f */
        "    mov r8d, 0xb0\n" /* 06e91 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06e97 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 06e9e */
        "    lea rdx, [rip + data_rva_1f260]\n" /* 06ea5 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 06eac */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 06eb1 */
        "    lea rdx, [rip + rdata_rva_19830]\n" /* 06eb8 */
        "    lea r8, [rip + rdata_rva_19800]\n" /* 06ebf */
        "    mov rsi, qword ptr [rsp + 0x720]\n" /* 06ec6 */
        "    mov r9, rsi\n" /* 06ece */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 06ed1 */
        "    mov qword ptr [rsi + 0x20], 0xfffffffffffffff5\n" /* 06ed6 */
        "    jmp .Lblock_6f38\n" /* 06ede */
        ".Lblock_6ee0:\n"
        "    jle .Lblock_6f38\n" /* 06ee0 */
        "    mov r8d, 0xb0\n" /* 06ee2 */
        "    add r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06ee8 */
        "    lea rcx, [rip + rdata_rva_19840]\n" /* 06eef */
        "    lea rdx, [rip + data_rva_1eea0]\n" /* 06ef6 */
        "    call thunk_ppflash_dll_FLSH_FLSMSG_rva_15376\n" /* 06efd */
        "    lea rcx, [rip + data_rva_1f640]\n" /* 06f02 */
        "    lea rdx, [rip + data_rva_227a8]\n" /* 06f09 */
        "    lea r8, [rip + rdata_rva_19808]\n" /* 06f10 */
        "    mov r9, qword ptr [rsp + 0x720]\n" /* 06f17 */
        "    call thunk_ppflash_dll_FLSH_FLSERR_rva_1537c\n" /* 06f1f */
        "    lea rcx, [rip + data_rva_226e8]\n" /* 06f24 */
        "    mov rdx, qword ptr [rsp + 0xa8]\n" /* 06f2b */
        "    call thunk_ppflash_dll_FLSH_FLSISCP5_rva_15382\n" /* 06f33 */
        ".Lblock_6f38:\n"
        "    call thunk_atdms_dll_DMS_PPEXT_rva_15286\n" /* 06f38 */
        "    mov rax, qword ptr [rip + data_rva_22798]\n" /* 06f3d */
        "    mov rcx, qword ptr [rsp + 0xc0]\n" /* 06f44 */
        "    movsd xmm0, qword ptr [rcx + rax*8 - 8]\n" /* 06f4c */
        "    movsd qword ptr [rip + data_rva_225e8], xmm0\n" /* 06f52 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06f5a */
        "    mov rax, qword ptr [rax + 0x10]\n" /* 06f61 */
        "    test rax, rax\n" /* 06f65 */
        S9_JLE32(.Lblock_6ffe) /* 06f68 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 06f6e */
        "    mov r9, qword ptr [rcx]\n" /* 06f75 */
        "    mov r10, qword ptr [rcx + 8]\n" /* 06f78 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_NCOMP_rva_19218]\n" /* 06f7c */
        "    mov rcx, qword ptr [rcx]\n" /* 06f83 */
        "    mov rdx, qword ptr [rip + data_rva_22728]\n" /* 06f86 */
        "    mov r11, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 06f8d */
        "    mov r8, qword ptr [r11 + 0x90]\n" /* 06f94 */
        "    add r8, r9\n" /* 06f9b */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 06f9e */
        "    lea r8, [rsi + r8*8]\n" /* 06fa5 */
        "    add r8, -8\n" /* 06fa9 */
        "    add r9, qword ptr [r11 + 0x78]\n" /* 06fad */
        "    lea r9, [rsi + r9*8]\n" /* 06fb1 */
        "    add r9, -8\n" /* 06fb5 */
        "    add r10, qword ptr [r11 + 0xc8]\n" /* 06fb9 */
        "    lea r10, [rsi + r10*8]\n" /* 06fc0 */
        "    add r10, -8\n" /* 06fc4 */
        "    xor r11d, r11d\n" /* 06fc8 */
        "    mov rbx, qword ptr [rsp + 0x7d8]\n" /* 06fcb */
        ".Lblock_6fd3:\n"
        "    mov rsi, qword ptr [r10 + r11*8]\n" /* 06fd3 */
        "    movsd xmm0, qword ptr [r9 + r11*8]\n" /* 06fd7 */
        "    lea rdi, [rcx + rsi]\n" /* 06fdd */
        "    movsd qword ptr [rbx + rdi*8 - 8], xmm0\n" /* 06fe1 */
        "    movsd xmm0, qword ptr [r8 + r11*8]\n" /* 06fe7 */
        "    add rsi, rdx\n" /* 06fed */
        "    movsd qword ptr [rbx + rsi*8 - 8], xmm0\n" /* 06ff0 */
        "    inc r11\n" /* 06ff6 */
        "    cmp r11, rax\n" /* 06ff9 */
        "    jl .Lblock_6fd3\n" /* 06ffc */
        ".Lblock_6ffe:\n"
        "    mov rbp, qword ptr [rsp + 0xc0]\n" /* 06ffe */
        "    mov rbx, qword ptr [rsp + 0xb0]\n" /* 07006 */
        "    mov r12, qword ptr [rsp + 0xb8]\n" /* 0700e */
        ".Lblock_7016:\n"
        "    mov rsi, qword ptr [rsp + 0x7d0]\n" /* 07016 */
        "    mov r10, qword ptr [rsp + 0x770]\n" /* 0701e */
        "    mov rcx, qword ptr [rip + data_rva_227a0]\n" /* 07026 */
        "    movsd xmm1, qword ptr [rbp + rcx*8 - 8]\n" /* 0702d */
        "    movsd xmm0, qword ptr [rip + data_rva_22500]\n" /* 07033 */
        "    movapd xmm5, xmm1\n" /* 0703b */
        "    mulsd xmm5, xmm0\n" /* 0703f */
        "    movsd qword ptr [rsi + 0x18], xmm5\n" /* 07043 */
        "    movapd xmm2, xmm5\n" /* 07048 */
        "    addsd xmm2, xmm1\n" /* 0704c */
        "    movsd qword ptr [rsi], xmm2\n" /* 07050 */
        "    movsd xmm2, qword ptr [rip + data_rva_225f8]\n" /* 07054 */
        "    movapd xmm3, xmm2\n" /* 0705c */
        "    mulsd xmm3, xmm1\n" /* 07060 */
        "    movsd qword ptr [rsi + 0x10], xmm3\n" /* 07064 */
        "    movapd xmm3, xmm6\n" /* 07069 */
        "    subsd xmm3, xmm2\n" /* 0706d */
        "    mulsd xmm3, xmm1\n" /* 07071 */
        "    movsd qword ptr [rsi + 0x28], xmm3\n" /* 07075 */
        "    test rax, rax\n" /* 0707a */
        S9_JLE32(.Lblock_710a) /* 0707d */
        "    mov rdx, qword ptr [rip + iat_zeshs_dll_SHS_STWORK_rva_19440]\n" /* 07083 */
        "    mov rdx, qword ptr [rdx + 0xc8]\n" /* 0708a */
        "    mov r8, qword ptr [rip + iat_atdms_dll_DMS_STWKWK_rva_19280]\n" /* 07091 */
        "    add rdx, qword ptr [r8 + 8]\n" /* 07098 */
        "    mov r8, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 0709c */
        "    lea r8, [r8 + rdx*8]\n" /* 070a3 */
        "    add r8, -8\n" /* 070a7 */
        "    xor edx, edx\n" /* 070ab */
        "    mov r11, qword ptr [rsp + 0x7d8]\n" /* 070ad */
        ".Lblock_70b5:\n"
        "    mov r9, qword ptr [r8 + rdx*8]\n" /* 070b5 */
        "    movsd xmm3, qword ptr [r10 + rdx*8]\n" /* 070b9 */
        "    movsd qword ptr [r11 + r9*8 - 8], xmm3\n" /* 070bf */
        "    inc rdx\n" /* 070c6 */
        "    cmp rdx, rax\n" /* 070c9 */
        "    jl .Lblock_70b5\n" /* 070cc */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 070ce */
        "    ucomisd xmm2, qword ptr [rdx + 8]\n" /* 070d5 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_NCOMP_rva_19218]\n" /* 070da */
        "    mov rdx, qword ptr [rdx]\n" /* 070e1 */
        "    ja .Lblock_7120\n" /* 070e4 */
        "    xor r9d, r9d\n" /* 070e6 */
        "    mov rdi, r10\n" /* 070e9 */
        ".Lblock_70ec:\n"
        "    movsd xmm2, qword ptr [rdi + r9*8]\n" /* 070ec */
        "    mov r10, qword ptr [r8 + r9*8]\n" /* 070f2 */
        "    add r10, rdx\n" /* 070f6 */
        "    movsd qword ptr [r11 + r10*8 - 8], xmm2\n" /* 070f9 */
        "    inc r9\n" /* 07100 */
        "    cmp rax, r9\n" /* 07103 */
        "    jne .Lblock_70ec\n" /* 07106 */
        "    jmp .Lblock_7120\n" /* 07108 */
        ".Lblock_710a:\n"
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 0710a */
        "    ucomisd xmm2, qword ptr [rax + 8]\n" /* 07111 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_NCOMP_rva_19218]\n" /* 07116 */
        "    mov rdx, qword ptr [rax]\n" /* 0711d */
        ".Lblock_7120:\n"
        "    mov r15, qword ptr [rsp + 0x720]\n" /* 07120 */
        "    mov r14, qword ptr [rsp + 0x700]\n" /* 07128 */
        "    mov r13, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 07130 */
        "    movsd xmm2, qword ptr [rip + data_rva_224a0]\n" /* 07137 */
        "    movsd xmm4, qword ptr [r12 + rcx*8 - 8]\n" /* 0713f */
        "    movapd xmm3, xmm2\n" /* 07146 */
        "    mulsd xmm3, xmm4\n" /* 0714a */
        "    addsd xmm5, xmm3\n" /* 0714e */
        "    movsd qword ptr [rsi + 0x20], xmm5\n" /* 07152 */
        "    movsd xmm3, qword ptr [rbx + rcx*8 - 8]\n" /* 07157 */
        "    movapd xmm7, xmm5\n" /* 0715d */
        "    subsd xmm7, xmm3\n" /* 07161 */
        "    movsd qword ptr [rsi + 8], xmm7\n" /* 07165 */
        "    test rdx, rdx\n" /* 0716a */
        "    jle .Lblock_71c9\n" /* 0716d */
        "    mov rax, qword ptr [rip + data_rva_22720]\n" /* 0716f */
        "    mov rcx, qword ptr [rip + data_rva_22710]\n" /* 07176 */
        "    mov r8, qword ptr [rip + data_rva_22718]\n" /* 0717d */
        "    mov r9, qword ptr [rsp + 0x7d8]\n" /* 07184 */
        "    lea rax, [r9 + rax*8]\n" /* 0718c */
        "    lea rcx, [r9 + rcx*8]\n" /* 07190 */
        "    lea r8, [r9 + r8*8]\n" /* 07194 */
        "    xor r9d, r9d\n" /* 07198 */
        ".Lblock_719b:\n"
        "    movsd xmm8, qword ptr [rax + r9*8]\n" /* 0719b */
        "    mulsd xmm8, xmm7\n" /* 071a1 */
        "    movsd xmm9, qword ptr [rcx + r9*8]\n" /* 071a6 */
        "    mulsd xmm9, xmm3\n" /* 071ac */
        "    addsd xmm9, xmm8\n" /* 071b1 */
        "    divsd xmm9, xmm5\n" /* 071b6 */
        "    movsd qword ptr [r8 + r9*8], xmm9\n" /* 071bb */
        "    inc r9\n" /* 071c1 */
        "    cmp r9, rdx\n" /* 071c4 */
        "    jl .Lblock_719b\n" /* 071c7 */
        ".Lblock_71c9:\n"
        "    movsd xmm7, qword ptr [rip + data_rva_225e8]\n" /* 071c9 */
        "    mov rdx, qword ptr [rsp + 0x7c0]\n" /* 071d1 */
        "    movsd qword ptr [rdx], xmm7\n" /* 071d9 */
        "    movsd xmm5, qword ptr [rip + data_rva_22588]\n" /* 071dd */
        "    movsd qword ptr [rdx + 8], xmm5\n" /* 071e5 */
        "    movsd xmm5, qword ptr [rip + data_rva_225e0]\n" /* 071ea */
        "    movsd xmm8, qword ptr [rip + data_rva_22508]\n" /* 071f2 */
        "    movsd xmm9, qword ptr [rip + data_rva_22488]\n" /* 071fb */
        "    mov rax, qword ptr [rip + data_rva_24268]\n" /* 07204 */
        "    movsd qword ptr [r14 + rax*8 - 8], xmm9\n" /* 0720b */
        "    movsd xmm10, qword ptr [rip + data_rva_22598]\n" /* 07212 */
        "    mov rax, qword ptr [rip + data_rva_242a8]\n" /* 0721b */
        "    movsd qword ptr [r14 + rax*8 - 8], xmm10\n" /* 07222 */
        "    movsd xmm10, qword ptr [rip + data_rva_22450]\n" /* 07229 */
        "    mov rax, qword ptr [rip + data_rva_24258]\n" /* 07232 */
        "    movsd qword ptr [r14 + rax*8 - 8], xmm10\n" /* 07239 */
        "    movapd xmm10, xmm8\n" /* 07240 */
        "    divsd xmm10, xmm9\n" /* 07245 */
        "    mulsd xmm10, qword ptr [rip + data_rva_22460]\n" /* 0724a */
        "    mov rax, qword ptr [rip + data_rva_24278]\n" /* 07253 */
        "    movsd qword ptr [r14 + rax*8 - 8], xmm10\n" /* 0725a */
        "    mov rax, qword ptr [rip + data_rva_24260]\n" /* 07261 */
        "    movsd qword ptr [r14 + rax*8 - 8], xmm0\n" /* 07268 */
        "    mov rax, qword ptr [rip + data_rva_24270]\n" /* 0726f */
        "    movsd qword ptr [r14 + rax*8 - 8], xmm8\n" /* 07276 */
        "    mov rax, qword ptr [rip + data_rva_24220]\n" /* 0727d */
        "    movsd xmm9, qword ptr [r14 + rax*8 - 8]\n" /* 07284 */
        "    divsd xmm9, xmm8\n" /* 0728b */
        "    mov rcx, qword ptr [rip + data_rva_24280]\n" /* 07290 */
        "    movsd qword ptr [r14 + rcx*8 - 8], xmm9\n" /* 07297 */
        "    mov rcx, qword ptr [rip + data_rva_24248]\n" /* 0729e */
        "    movsd qword ptr [r14 + rcx*8 - 8], xmm7\n" /* 072a5 */
        "    subsd xmm7, xmm5\n" /* 072ac */
        "    movapd xmm9, xmm8\n" /* 072b0 */
        "    subsd xmm8, xmm6\n" /* 072b5 */
        "    divsd xmm7, xmm8\n" /* 072ba */
        "    addsd xmm7, xmm5\n" /* 072bf */
        "    movsd qword ptr [rdx + 0x10], xmm7\n" /* 072c3 */
        "    movsd qword ptr [rdx + 0x18], xmm5\n" /* 072c8 */
        "    movsd xmm7, qword ptr [rip + data_rva_22608]\n" /* 072cd */
        "    mov rdx, qword ptr [rsp + 0x7c8]\n" /* 072d5 */
        "    movsd qword ptr [rdx], xmm7\n" /* 072dd */
        "    movsd xmm8, qword ptr [rip + data_rva_22568]\n" /* 072e1 */
        "    movsd qword ptr [rdx + 8], xmm8\n" /* 072ea */
        "    movsd xmm8, qword ptr [rip + data_rva_22600]\n" /* 072f0 */
        "    subsd xmm7, xmm8\n" /* 072f9 */
        "    subsd xmm9, xmm6\n" /* 072fe */
        "    divsd xmm7, xmm9\n" /* 07303 */
        "    addsd xmm7, xmm8\n" /* 07308 */
        "    movsd qword ptr [rdx + 0x10], xmm7\n" /* 0730d */
        "    movsd qword ptr [rdx + 0x18], xmm8\n" /* 07312 */
        "    mov rdx, qword ptr [rip + data_rva_24250]\n" /* 07318 */
        "    movsd qword ptr [r14 + rdx*8 - 8], xmm5\n" /* 0731f */
        "    cmp qword ptr [r15 + 0x10], 0\n" /* 07326 */
        S9_JE32(.Lblock_73ce) /* 0732b */
        "    mov rdx, qword ptr [rip + data_rva_22790]\n" /* 07331 */
        "    movsd xmm5, qword ptr [rbp + rdx*8 - 8]\n" /* 07338 */
        "    movapd xmm7, xmm1\n" /* 0733e */
        "    mulsd xmm7, xmm5\n" /* 07342 */
        "    mov r8, qword ptr [rip + data_rva_22778]\n" /* 07346 */
        "    movsd xmm8, qword ptr [rbp + r8*8 - 8]\n" /* 0734d */
        "    mulsd xmm0, xmm1\n" /* 07354 */
        "    mulsd xmm0, qword ptr [rip + data_rva_22468]\n" /* 07358 */
        "    mulsd xmm7, xmm8\n" /* 07360 */
        "    addsd xmm0, xmm7\n" /* 07365 */
        "    movsd xmm7, qword ptr [rip + data_rva_22448]\n" /* 07369 */
        "    mulsd xmm7, xmm1\n" /* 07371 */
        "    mulsd xmm7, qword ptr [rip + data_rva_22560]\n" /* 07375 */
        "    subsd xmm0, xmm7\n" /* 0737d */
        "    mov r9, qword ptr [rip + data_rva_24290]\n" /* 07381 */
        "    mulsd xmm4, qword ptr [rip + data_rva_224e8]\n" /* 07388 */
        "    mulsd xmm4, qword ptr [r12 + r8*8 - 8]\n" /* 07390 */
        "    movsd qword ptr [r14 + r9*8 - 8], xmm0\n" /* 07397 */
        "    mulsd xmm1, xmm5\n" /* 0739e */
        "    mulsd xmm1, xmm8\n" /* 073a2 */
        "    subsd xmm1, xmm4\n" /* 073a7 */
        "    mulsd xmm3, qword ptr [rbx + rdx*8 - 8]\n" /* 073ab */
        "    mulsd xmm3, qword ptr [rbx + r8*8 - 8]\n" /* 073b1 */
        "    addsd xmm3, xmm1\n" /* 073b8 */
        "    subsd xmm3, xmm0\n" /* 073bc */
        "    mov rdx, qword ptr [rip + data_rva_24288]\n" /* 073c0 */
        "    movsd qword ptr [r14 + rdx*8 - 8], xmm3\n" /* 073c7 */
        ".Lblock_73ce:\n"
        "    cmp qword ptr [r15], 4\n" /* 073ce */
        "    mov rsi, qword ptr [rsp + 0x728]\n" /* 073d2 */
        S9_JL32(.Lblock_7884) /* 073da */
        "    subsd xmm6, xmm2\n" /* 073e0 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 073e4 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 073eb */
        "    ucomisd xmm0, qword ptr [rax]\n" /* 073f2 */
        "    movsd qword ptr [rip + data_rva_22440], xmm6\n" /* 073f6 */
        "    movsd xmm0, qword ptr [r14 + rcx*8 - 8]\n" /* 073fe */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 07405 */
        "    mov edx, dword ptr [r13 + 0x20]\n" /* 07411 */
        S9_JB32(.Lblock_7631) /* 07415 */
        "    mov dword ptr [rsp + 0x174], 0x20130\n" /* 0741b */
        "    movsd qword ptr [rsp + 0x300], xmm0\n" /* 07426 */
        "    lea rax, [rip + data_rva_1f83c]\n" /* 0742f */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 07436 */
        "    lea rax, [rsp + 0x300]\n" /* 0743b */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 07443 */
        "    lea rdi, [rsp + 0xd0]\n" /* 07448 */
        "    lea r9, [rsp + 0x174]\n" /* 07450 */
        "    mov rcx, rdi\n" /* 07458 */
        "    movabs r8, 0x801208384ff00\n" /* 0745b */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 07465 */
        "    mov rax, qword ptr [rip + data_rva_24250]\n" /* 0746a */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 07471 */
        "    mov dword ptr [rsp + 0x170], 0x20130\n" /* 07478 */
        "    movsd qword ptr [rsp + 0x2f8], xmm0\n" /* 07483 */
        "    lea rdx, [rsp + 0x170]\n" /* 0748c */
        "    lea r8, [rsp + 0x2f8]\n" /* 07494 */
        "    mov rcx, rdi\n" /* 0749c */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0749f */
        "    mov rax, qword ptr [rip + data_rva_24258]\n" /* 074a4 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 074ab */
        "    mov dword ptr [rsp + 0x16c], 0x20130\n" /* 074b2 */
        "    movsd qword ptr [rsp + 0x2f0], xmm0\n" /* 074bd */
        "    lea rdx, [rsp + 0x16c]\n" /* 074c6 */
        "    lea r8, [rsp + 0x2f0]\n" /* 074ce */
        "    mov rcx, rdi\n" /* 074d6 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 074d9 */
        "    mov rax, qword ptr [rip + data_rva_24260]\n" /* 074de */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 074e5 */
        "    mov dword ptr [rsp + 0x168], 0x20130\n" /* 074ec */
        "    movsd qword ptr [rsp + 0x2e8], xmm0\n" /* 074f7 */
        "    lea rdx, [rsp + 0x168]\n" /* 07500 */
        "    lea r8, [rsp + 0x2e8]\n" /* 07508 */
        "    mov rcx, rdi\n" /* 07510 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 07513 */
        "    mov rax, qword ptr [rip + data_rva_24268]\n" /* 07518 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 0751f */
        "    mov dword ptr [rsp + 0x164], 0x20130\n" /* 07526 */
        "    movsd qword ptr [rsp + 0x2e0], xmm0\n" /* 07531 */
        "    lea rdx, [rsp + 0x164]\n" /* 0753a */
        "    lea r8, [rsp + 0x2e0]\n" /* 07542 */
        "    mov rcx, rdi\n" /* 0754a */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0754d */
        "    mov rax, qword ptr [rip + data_rva_24270]\n" /* 07552 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 07559 */
        "    mov dword ptr [rsp + 0x160], 0x20130\n" /* 07560 */
        "    movsd qword ptr [rsp + 0x2d8], xmm0\n" /* 0756b */
        "    lea rdx, [rsp + 0x160]\n" /* 07574 */
        "    lea r8, [rsp + 0x2d8]\n" /* 0757c */
        "    mov rcx, rdi\n" /* 07584 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 07587 */
        "    mov rax, qword ptr [rip + data_rva_24278]\n" /* 0758c */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 07593 */
        "    mov dword ptr [rsp + 0x15c], 0x20130\n" /* 0759a */
        "    movsd qword ptr [rsp + 0x2d0], xmm0\n" /* 075a5 */
        "    lea rdx, [rsp + 0x15c]\n" /* 075ae */
        "    lea r8, [rsp + 0x2d0]\n" /* 075b6 */
        "    mov rcx, rdi\n" /* 075be */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 075c1 */
        "    mov rax, qword ptr [rip + data_rva_24288]\n" /* 075c6 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 075cd */
        "    mov dword ptr [rsp + 0x158], 0x20130\n" /* 075d4 */
        "    movsd qword ptr [rsp + 0x2c8], xmm0\n" /* 075df */
        "    lea rdx, [rsp + 0x158]\n" /* 075e8 */
        "    lea r8, [rsp + 0x2c8]\n" /* 075f0 */
        "    mov rcx, rdi\n" /* 075f8 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 075fb */
        "    movsd xmm0, qword ptr [rip + data_rva_22440]\n" /* 07600 */
        "    mov dword ptr [rsp + 0x154], 0x10130\n" /* 07608 */
        "    movsd qword ptr [rsp + 0x2c0], xmm0\n" /* 07613 */
        "    lea rdx, [rsp + 0x154]\n" /* 0761c */
        "    lea r8, [rsp + 0x2c0]\n" /* 07624 */
        S9_JMP32(.Lblock_787c) /* 0762c */
        ".Lblock_7631:\n"
        "    mov dword ptr [rsp + 0x150], 0x20130\n" /* 07631 */
        "    movsd qword ptr [rsp + 0x2b8], xmm0\n" /* 0763c */
        "    lea rax, [rip + data_rva_1f6e0]\n" /* 07645 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0764c */
        "    lea rax, [rsp + 0x2b8]\n" /* 07651 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 07659 */
        "    lea rdi, [rsp + 0xd0]\n" /* 0765e */
        "    lea r9, [rsp + 0x150]\n" /* 07666 */
        "    mov rcx, rdi\n" /* 0766e */
        "    movabs r8, 0x801208384ff00\n" /* 07671 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0767b */
        "    mov rax, qword ptr [rip + data_rva_24250]\n" /* 07680 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 07687 */
        "    mov dword ptr [rsp + 0x14c], 0x20130\n" /* 0768e */
        "    movsd qword ptr [rsp + 0x2b0], xmm0\n" /* 07699 */
        "    lea rdx, [rsp + 0x14c]\n" /* 076a2 */
        "    lea r8, [rsp + 0x2b0]\n" /* 076aa */
        "    mov rcx, rdi\n" /* 076b2 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 076b5 */
        "    mov rax, qword ptr [rip + data_rva_24258]\n" /* 076ba */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 076c1 */
        "    mov dword ptr [rsp + 0x148], 0x20130\n" /* 076c8 */
        "    movsd qword ptr [rsp + 0x2a8], xmm0\n" /* 076d3 */
        "    lea rdx, [rsp + 0x148]\n" /* 076dc */
        "    lea r8, [rsp + 0x2a8]\n" /* 076e4 */
        "    mov rcx, rdi\n" /* 076ec */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 076ef */
        "    mov rax, qword ptr [rip + data_rva_24260]\n" /* 076f4 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 076fb */
        "    mov dword ptr [rsp + 0x144], 0x20130\n" /* 07702 */
        "    movsd qword ptr [rsp + 0x2a0], xmm0\n" /* 0770d */
        "    lea rdx, [rsp + 0x144]\n" /* 07716 */
        "    lea r8, [rsp + 0x2a0]\n" /* 0771e */
        "    mov rcx, rdi\n" /* 07726 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 07729 */
        "    mov rax, qword ptr [rip + data_rva_24268]\n" /* 0772e */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 07735 */
        "    mov dword ptr [rsp + 0x140], 0x20130\n" /* 0773c */
        "    movsd qword ptr [rsp + 0x298], xmm0\n" /* 07747 */
        "    lea rdx, [rsp + 0x140]\n" /* 07750 */
        "    lea r8, [rsp + 0x298]\n" /* 07758 */
        "    mov rcx, rdi\n" /* 07760 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 07763 */
        "    mov rax, qword ptr [rip + data_rva_24270]\n" /* 07768 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 0776f */
        "    mov dword ptr [rsp + 0x13c], 0x20130\n" /* 07776 */
        "    movsd qword ptr [rsp + 0x290], xmm0\n" /* 07781 */
        "    lea rdx, [rsp + 0x13c]\n" /* 0778a */
        "    lea r8, [rsp + 0x290]\n" /* 07792 */
        "    mov rcx, rdi\n" /* 0779a */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0779d */
        "    mov rax, qword ptr [rip + data_rva_24278]\n" /* 077a2 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 077a9 */
        "    mov dword ptr [rsp + 0x138], 0x20130\n" /* 077b0 */
        "    movsd qword ptr [rsp + 0x288], xmm0\n" /* 077bb */
        "    lea rdx, [rsp + 0x138]\n" /* 077c4 */
        "    lea r8, [rsp + 0x288]\n" /* 077cc */
        "    mov rcx, rdi\n" /* 077d4 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 077d7 */
        "    mov rax, qword ptr [rip + data_rva_24280]\n" /* 077dc */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 077e3 */
        "    mov dword ptr [rsp + 0x134], 0x20130\n" /* 077ea */
        "    movsd qword ptr [rsp + 0x280], xmm0\n" /* 077f5 */
        "    lea rdx, [rsp + 0x134]\n" /* 077fe */
        "    lea r8, [rsp + 0x280]\n" /* 07806 */
        "    mov rcx, rdi\n" /* 0780e */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 07811 */
        "    mov rax, qword ptr [rip + data_rva_24288]\n" /* 07816 */
        "    movsd xmm0, qword ptr [r14 + rax*8 - 8]\n" /* 0781d */
        "    mov dword ptr [rsp + 0x130], 0x20130\n" /* 07824 */
        "    movsd qword ptr [rsp + 0x278], xmm0\n" /* 0782f */
        "    lea rdx, [rsp + 0x130]\n" /* 07838 */
        "    lea r8, [rsp + 0x278]\n" /* 07840 */
        "    mov rcx, rdi\n" /* 07848 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0784b */
        "    movsd xmm0, qword ptr [rip + data_rva_22440]\n" /* 07850 */
        "    mov dword ptr [rsp + 0x12c], 0x10130\n" /* 07858 */
        "    movsd qword ptr [rsp + 0x270], xmm0\n" /* 07863 */
        "    lea rdx, [rsp + 0x12c]\n" /* 0786c */
        "    lea r8, [rsp + 0x270]\n" /* 07874 */
        ".Lblock_787c:\n"
        "    mov rcx, rdi\n" /* 0787c */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0787f */
        ".Lblock_7884:\n"
        "    cmp qword ptr [r13 + 0x100], 2\n" /* 07884 */
        "    mov r10, qword ptr [rip + iat_atdms_dll_DMS_NCOMP_rva_19218]\n" /* 0788c */
        S9_JL32(.Lblock_58f9) /* 07893 */
        "    movsd xmm0, qword ptr [rip + data_rva_225f8]\n" /* 07899 */
        S9_JMP32(.Lblock_2977) /* 078a1 */
        END);
}
