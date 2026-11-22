#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0x9c40 through 0xb97a (exclusive). */
__asm__(".globl rva_9c40\n.set rva_9c40, sub_180009C40\n");
NAKED void sub_180009C40(void) {
    __asm__(START
        "    push r15\n" /* 09c40 */
        "    push r14\n" /* 09c42 */
        "    push r13\n" /* 09c44 */
        "    push r12\n" /* 09c46 */
        "    push rsi\n" /* 09c48 */
        "    push rdi\n" /* 09c49 */
        "    push rbp\n" /* 09c4a */
        "    push rbx\n" /* 09c4b */
        "    sub rsp, 0x5f8\n" /* 09c4c */
        "    movaps xmmword ptr [rsp + 0x5e0], xmm8\n" /* 09c53 */
        "    movaps xmmword ptr [rsp + 0x5d0], xmm7\n" /* 09c5c */
        "    movaps xmmword ptr [rsp + 0x5c0], xmm6\n" /* 09c64 */
        "    mov r14, r9\n" /* 09c6c */
        "    mov r13, r8\n" /* 09c6f */
        "    mov rdi, rdx\n" /* 09c72 */
        "    mov r12, rcx\n" /* 09c75 */
        "    mov rbp, qword ptr [rsp + 0x6c0]\n" /* 09c78 */
        "    mov rsi, qword ptr [rsp + 0x6b8]\n" /* 09c80 */
        "    mov rbx, qword ptr [rsp + 0x6a8]\n" /* 09c88 */
        "    mov r15, qword ptr [rsp + 0x660]\n" /* 09c90 */
        "    movapd xmm6, xmmword ptr [rsp + 0x680]\n" /* 09c98 */
        "    movaps xmm7, xmmword ptr [rsp + 0x690]\n" /* 09ca1 */
        "    movups xmm8, xmmword ptr [rsp + 0x6c8]\n" /* 09ca9 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_IPOFF4_rva_191c0]\n" /* 09cb2 */
        "    mov rax, qword ptr [rax + 8]\n" /* 09cb9 */
        "    mov qword ptr [rip + data_rva_22ad8], rax\n" /* 09cbd */
        "    mov qword ptr [rip + data_rva_22b28], 0\n" /* 09cc4 */
        "    lea rdx, [rip + data_rva_22ad0]\n" /* 09ccf */
        "    lea r8, [rip + data_rva_22ac8]\n" /* 09cd6 */
        "    lea r9, [rip + data_rva_22ac0]\n" /* 09cdd */
        "    mov rcx, rbp\n" /* 09ce4 */
        /* Locate the report buffer and open the work area. */
        "    call thunk_atdms_dll_DMS_LOCATM_rva_152b6\n" /* 09ce7 */
        "    mov rax, qword ptr [rip + data_rva_22ad0]\n" /* 09cec */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 09cf3 */
        "    lea rcx, [rcx + rax*8]\n" /* 09cfa */
        "    add rcx, 0x118\n" /* 09cfe */
        "    call thunk_atdms_dll_DMS_MBUFR_rva_152bc\n" /* 09d05 */
        "    mov rax, qword ptr [rbx + 0x20]\n" /* 09d0a */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 09d0e */
        "    mov rcx, qword ptr [rcx + 0x38]\n" /* 09d15 */
        "    add rcx, rax\n" /* 09d19 */
        "    sete cl\n" /* 09d1c */
        "    cmp rax, -0x270f\n" /* 09d1f */
        "    sete dl\n" /* 09d25 */
        "    or dl, cl\n" /* 09d28 */
        "    cmp rax, -1\n" /* 09d2a */
        "    sete al\n" /* 09d2e */
        "    or al, dl\n" /* 09d31 */
        "    movzx eax, al\n" /* 09d33 */
        "    mov qword ptr [rip + data_rva_22b20], rax\n" /* 09d36 */
        "    lea rax, [rip + data_rva_22b20]\n" /* 09d3d */
        "    mov qword ptr [rip + data_rva_22b18], 2\n" /* 09d44 */
        "    lea rcx, [rip + data_rva_22b18]\n" /* 09d4f */
        "    mov qword ptr [rip + data_rva_22b10], 6\n" /* 09d56 */
        "    lea rdx, [rip + data_rva_22b10]\n" /* 09d61 */
        "    mov qword ptr [rip + data_rva_22b08], 1\n" /* 09d68 */
        "    lea r8, [rip + data_rva_22b08]\n" /* 09d73 */
        "    mov qword ptr [rsp + 0xb8], r8\n" /* 09d7a */
        "    mov qword ptr [rsp + 0xb0], rdx\n" /* 09d82 */
        "    mov qword ptr [rsp + 0xa8], rcx\n" /* 09d8a */
        "    mov qword ptr [rsp + 0xa0], rax\n" /* 09d92 */
        "    lea rax, [rip + data_rva_20e60]\n" /* 09d9a */
        "    mov qword ptr [rsp + 0x98], rax\n" /* 09da1 */
        "    movups xmmword ptr [rsp + 0x88], xmm8\n" /* 09da9 */
        "    mov rax, qword ptr [rsp + 0x6b0]\n" /* 09db2 */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 09dba */
        "    mov rax, qword ptr [rsp + 0x678]\n" /* 09dbf */
        "    mov rcx, qword ptr [rsp + 0x6a0]\n" /* 09dc7 */
        "    mov qword ptr [rsp + 0x60], rcx\n" /* 09dcf */
        "    mov qword ptr [rsp + 0x80], rbp\n" /* 09dd4 */
        "    mov qword ptr [rsp + 0x78], rsi\n" /* 09ddc */
        "    mov qword ptr [rsp + 0x68], rbx\n" /* 09de1 */
        "    movups xmmword ptr [rsp + 0x50], xmm7\n" /* 09de6 */
        "    movupd xmmword ptr [rsp + 0x40], xmm6\n" /* 09deb */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 09df1 */
        "    mov rcx, qword ptr [rsp + 0x670]\n" /* 09df6 */
        "    mov qword ptr [rsp + 0x30], rcx\n" /* 09dfe */
        "    mov rcx, qword ptr [rsp + 0x668]\n" /* 09e03 */
        "    mov qword ptr [rsp + 0x28], rcx\n" /* 09e0b */
        "    mov qword ptr [rsp + 0x20], r15\n" /* 09e10 */
        "    mov r8, r13\n" /* 09e15 */
        "    mov r9, r14\n" /* 09e18 */
        "    mov r14, rax\n" /* 09e1b */
        "    mov rcx, r12\n" /* 09e1e */
        "    mov rdx, rdi\n" /* 09e21 */
        /* Produce the model report, then check whether its detail path is enabled. */
        "    call thunk_zeuosutl_dll_UU_MODR01_rva_153be\n" /* 09e24 */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 09e29 */
        "    mov rax, qword ptr [rsi + 0x58]\n" /* 09e30 */
        "    dec rax\n" /* 09e34 */
        "    cmp rax, 1\n" /* 09e37 */
        "    ja .Lblock_9e6c\n" /* 09e3b */
        "    cmp qword ptr [rip + data_rva_22b20], 0\n" /* 09e3d */
        "    jne .Lblock_9e6c\n" /* 09e45 */
        "    mov qword ptr [rsp + 0x20], r14\n" /* 09e47 */
        "    mov rcx, rbp\n" /* 09e4c */
        "    mov rdx, qword ptr [rsp + 0x660]\n" /* 09e4f */
        "    mov r8, qword ptr [rsp + 0x668]\n" /* 09e57 */
        "    mov r9, qword ptr [rsp + 0x670]\n" /* 09e5f */
        "    call sub_18000B980_rva_b980\n" /* 09e67 */
        ".Lblock_9e6c:\n"
        "    mov rdi, qword ptr [rsp + 0x6b8]\n" /* 09e6c */
        "    cmp qword ptr [rdi + 0x18], 0\n" /* 09e74 */
        S9_JE32(.Lblock_a91e) /* 09e79 */
        "    mov rcx, qword ptr [rsp + 0x6a8]\n" /* 09e7f */
        "    mov rax, qword ptr [rcx + 0x20]\n" /* 09e87 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 09e8b */
        "    add rax, qword ptr [rdx + 0x38]\n" /* 09e92 */
        S9_JE32(.Lblock_b927) /* 09e96 */
        "    movabs r12, 0x801208384ff00\n" /* 09e9c */
        "    mov rax, qword ptr [rcx + 0x70]\n" /* 09ea6 */
        "    add rax, 0xe\n" /* 09eaa */
        "    mov qword ptr [rip + data_rva_22b00], rax\n" /* 09eae */
        "    lea rcx, [rip + data_rva_22b00]\n" /* 09eb5 */
        "    lea r9, [rsi + 8]\n" /* 09ebc */
        "    lea rdx, [rip + data_rva_22b30]\n" /* 09ec0 */
        "    lea r8, [rip + data_rva_20e40]\n" /* 09ec7 */
        "    call thunk_zereport_dll_ZREP_RPTHDR_rva_15310\n" /* 09ece */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 09ed3 */
        "    mov rbx, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 09edf */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 09ee6 */
        "    mov word ptr [rsp + 0xce], 1\n" /* 09ee9 */
        "    lea rax, [rip + data_rva_2180c]\n" /* 09ef3 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 09efa */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 09eff */
        "    lea r13, [rsp + 0xd0]\n" /* 09f08 */
        "    lea r9, [rsp + 0xce]\n" /* 09f10 */
        "    mov rcx, r13\n" /* 09f18 */
        "    mov r8, r12\n" /* 09f1b */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 09f1e */
        "    mov rax, qword ptr [rip + data_rva_242b8]\n" /* 09f23 */
        "    mov rdx, qword ptr [rsp + 0x668]\n" /* 09f2a */
        "    mov rax, qword ptr [rdx + rax*8 - 8]\n" /* 09f32 */
        "    mov qword ptr [rip + data_rva_22af8], rax\n" /* 09f37 */
        "    mov rcx, qword ptr [rip + data_rva_242c0]\n" /* 09f3e */
        "    mov rcx, qword ptr [rdx + rcx*8 - 8]\n" /* 09f45 */
        "    mov qword ptr [rip + data_rva_22af0], rcx\n" /* 09f4a */
        "    add rax, rax\n" /* 09f51 */
        "    add rax, qword ptr [rip + data_rva_22ad8]\n" /* 09f54 */
        "    mov r15, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 09f5b */
        "    mov rax, qword ptr [r15 + rax*8 - 0x10]\n" /* 09f62 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 09f67 */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 09f73 */
        "    mov dword ptr [rsp + 0x1b4], 0x2010b\n" /* 09f76 */
        "    mov qword ptr [rsp + 0x270], rax\n" /* 09f81 */
        "    lea rax, [rip + data_rva_2178c]\n" /* 09f89 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 09f90 */
        "    lea rax, [rsp + 0x270]\n" /* 09f95 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 09f9d */
        "    lea r9, [rsp + 0x1b4]\n" /* 09fa2 */
        "    mov rcx, r13\n" /* 09faa */
        "    mov r8, r12\n" /* 09fad */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 09fb0 */
        "    mov rax, qword ptr [rip + data_rva_22af8]\n" /* 09fb5 */
        "    add rax, rax\n" /* 09fbc */
        "    add rax, qword ptr [rip + data_rva_22ad8]\n" /* 09fbf */
        "    mov rax, qword ptr [r15 + rax*8 - 8]\n" /* 09fc6 */
        "    mov dword ptr [rsp + 0x1b0], 0x1010b\n" /* 09fcb */
        "    mov qword ptr [rsp + 0x268], rax\n" /* 09fd6 */
        "    lea rdx, [rsp + 0x1b0]\n" /* 09fde */
        "    lea r8, [rsp + 0x268]\n" /* 09fe6 */
        "    mov rcx, r13\n" /* 09fee */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 09ff1 */
        "    mov rax, qword ptr [rip + data_rva_241e8]\n" /* 09ff6 */
        "    lea rdx, [r14 + rax*8]\n" /* 09ffd */
        "    add rdx, -8\n" /* 0a001 */
        "    lea rsi, [rip + data_rva_22b60]\n" /* 0a005 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a00c */
        "    lea rdi, [rip + data_rva_22b28]\n" /* 0a011 */
        "    mov qword ptr [rsp + 0x28], rdi\n" /* 0a018 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0a01d */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a024 */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0a029 */
        "    lea r14, [rip + data_rva_22ae0]\n" /* 0a030 */
        "    lea rbp, [rip + data_rva_22b40]\n" /* 0a037 */
        "    mov r8, r14\n" /* 0a03e */
        "    mov r9, rbp\n" /* 0a041 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a044 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a049 */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 0a055 */
        "    mov dword ptr [rsp + 0x1ac], 0x1070b\n" /* 0a058 */
        "    mov qword ptr [rsp + 0x598], 1\n" /* 0a063 */
        "    mov qword ptr [rsp + 0x5a0], rsi\n" /* 0a06f */
        "    mov qword ptr [rsp + 0x5a8], 1\n" /* 0a077 */
        "    mov qword ptr [rsp + 0x5b0], 5\n" /* 0a083 */
        "    mov qword ptr [rsp + 0x5b8], 8\n" /* 0a08f */
        "    lea rax, [rip + data_rva_216e8]\n" /* 0a09b */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a0a2 */
        "    lea rax, [rsp + 0x598]\n" /* 0a0a7 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a0af */
        "    lea r9, [rsp + 0x1ac]\n" /* 0a0b4 */
        "    mov rcx, r13\n" /* 0a0bc */
        "    mov r8, r12\n" /* 0a0bf */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a0c2 */
        "    mov rax, qword ptr [rip + data_rva_22af0]\n" /* 0a0c7 */
        "    add rax, rax\n" /* 0a0ce */
        "    add rax, qword ptr [rip + data_rva_22ad8]\n" /* 0a0d1 */
        "    mov rax, qword ptr [r15 + rax*8 - 0x10]\n" /* 0a0d8 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a0dd */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 0a0e9 */
        "    mov dword ptr [rsp + 0x1a8], 0x2010b\n" /* 0a0ec */
        "    mov qword ptr [rsp + 0x260], rax\n" /* 0a0f7 */
        "    lea rax, [rip + data_rva_21698]\n" /* 0a0ff */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a106 */
        "    lea rax, [rsp + 0x260]\n" /* 0a10b */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a113 */
        "    lea r9, [rsp + 0x1a8]\n" /* 0a118 */
        "    mov rcx, r13\n" /* 0a120 */
        "    mov r8, r12\n" /* 0a123 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a126 */
        "    mov rax, qword ptr [rip + data_rva_22af0]\n" /* 0a12b */
        "    add rax, rax\n" /* 0a132 */
        "    add rax, qword ptr [rip + data_rva_22ad8]\n" /* 0a135 */
        "    mov rax, qword ptr [r15 + rax*8 - 8]\n" /* 0a13c */
        "    mov dword ptr [rsp + 0x1a4], 0x1010b\n" /* 0a141 */
        "    mov qword ptr [rsp + 0x258], rax\n" /* 0a14c */
        "    lea rdx, [rsp + 0x1a4]\n" /* 0a154 */
        "    lea r8, [rsp + 0x258]\n" /* 0a15c */
        "    mov rcx, r13\n" /* 0a164 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a167 */
        "    mov rax, qword ptr [rip + data_rva_241f0]\n" /* 0a16c */
        "    mov rcx, qword ptr [rsp + 0x678]\n" /* 0a173 */
        "    lea rdx, [rcx + rax*8]\n" /* 0a17b */
        "    add rdx, -8\n" /* 0a17f */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a183 */
        "    mov qword ptr [rsp + 0x28], rdi\n" /* 0a188 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0a18d */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a194 */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0a199 */
        "    mov r8, r14\n" /* 0a1a0 */
        "    mov r9, rbp\n" /* 0a1a3 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a1a6 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a1ab */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 0a1b7 */
        "    mov dword ptr [rsp + 0x1a0], 0x1070b\n" /* 0a1ba */
        "    mov qword ptr [rsp + 0x570], 1\n" /* 0a1c5 */
        "    mov qword ptr [rsp + 0x578], rsi\n" /* 0a1d1 */
        "    mov qword ptr [rsp + 0x580], 1\n" /* 0a1d9 */
        "    mov qword ptr [rsp + 0x588], 5\n" /* 0a1e5 */
        "    mov qword ptr [rsp + 0x590], 8\n" /* 0a1f1 */
        "    lea rax, [rip + data_rva_215f4]\n" /* 0a1fd */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a204 */
        "    lea rax, [rsp + 0x570]\n" /* 0a209 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a211 */
        "    lea r9, [rsp + 0x1a0]\n" /* 0a216 */
        "    mov rcx, r13\n" /* 0a21e */
        "    mov r8, r12\n" /* 0a221 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a224 */
        "    mov rax, qword ptr [rip + data_rva_24200]\n" /* 0a229 */
        "    mov rcx, qword ptr [rsp + 0x678]\n" /* 0a230 */
        "    lea rdx, [rcx + rax*8]\n" /* 0a238 */
        "    add rdx, -8\n" /* 0a23c */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a240 */
        "    mov qword ptr [rsp + 0x28], rdi\n" /* 0a245 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0a24a */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a251 */
        "    lea r15, [rip + rdata_rva_198c0]\n" /* 0a256 */
        "    mov rcx, r15\n" /* 0a25d */
        "    mov r8, r14\n" /* 0a260 */
        "    mov r9, rbp\n" /* 0a263 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a266 */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0a26b */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a272 */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 0a27e */
        "    mov dword ptr [rsp + 0x19c], 0x2010b\n" /* 0a281 */
        "    mov qword ptr [rsp + 0x250], rax\n" /* 0a28c */
        "    lea rax, [rip + data_rva_21548]\n" /* 0a294 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a29b */
        "    lea rax, [rsp + 0x250]\n" /* 0a2a0 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a2a8 */
        "    lea r9, [rsp + 0x19c]\n" /* 0a2ad */
        "    mov rcx, r13\n" /* 0a2b5 */
        "    mov r8, r12\n" /* 0a2b8 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a2bb */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0a2c0 */
        "    mov dword ptr [rsp + 0x198], 0x2010b\n" /* 0a2c7 */
        "    mov qword ptr [rsp + 0x248], rax\n" /* 0a2d2 */
        "    lea rdx, [rsp + 0x198]\n" /* 0a2da */
        "    lea r8, [rsp + 0x248]\n" /* 0a2e2 */
        "    mov rcx, r13\n" /* 0a2ea */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a2ed */
        "    mov dword ptr [rsp + 0x194], 0x1070b\n" /* 0a2f2 */
        "    mov qword ptr [rsp + 0x548], 1\n" /* 0a2fd */
        "    mov qword ptr [rsp + 0x550], rsi\n" /* 0a309 */
        "    mov qword ptr [rsp + 0x558], 1\n" /* 0a311 */
        "    mov qword ptr [rsp + 0x560], 5\n" /* 0a31d */
        "    mov qword ptr [rsp + 0x568], 8\n" /* 0a329 */
        "    lea rdx, [rsp + 0x194]\n" /* 0a335 */
        "    lea r8, [rsp + 0x548]\n" /* 0a33d */
        "    mov rcx, r13\n" /* 0a345 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a348 */
        "    mov rax, qword ptr [rip + data_rva_24208]\n" /* 0a34d */
        "    mov rcx, qword ptr [rsp + 0x678]\n" /* 0a354 */
        "    lea rdx, [rcx + rax*8]\n" /* 0a35c */
        "    add rdx, -8\n" /* 0a360 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a364 */
        "    mov qword ptr [rsp + 0x28], rdi\n" /* 0a369 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0a36e */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a375 */
        "    mov rcx, r15\n" /* 0a37a */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0a37d */
        "    mov r9, rbp\n" /* 0a384 */
        "    mov r14, qword ptr [rsp + 0x678]\n" /* 0a387 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a38f */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0a394 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a39b */
        "    mov edx, dword ptr [rbx + 0x68]\n" /* 0a3a7 */
        "    mov dword ptr [rsp + 0x190], 0x2010b\n" /* 0a3aa */
        "    mov qword ptr [rsp + 0x240], rax\n" /* 0a3b5 */
        "    lea rax, [rip + data_rva_214ec]\n" /* 0a3bd */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a3c4 */
        "    lea rax, [rsp + 0x240]\n" /* 0a3c9 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a3d1 */
        "    lea r9, [rsp + 0x190]\n" /* 0a3d6 */
        "    mov rcx, r13\n" /* 0a3de */
        "    mov r15, r12\n" /* 0a3e1 */
        "    mov r8, r12\n" /* 0a3e4 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a3e7 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0a3ec */
        "    mov dword ptr [rsp + 0x18c], 0x2010b\n" /* 0a3f3 */
        "    mov qword ptr [rsp + 0x238], rax\n" /* 0a3fe */
        "    lea rdx, [rsp + 0x18c]\n" /* 0a406 */
        "    lea r8, [rsp + 0x238]\n" /* 0a40e */
        "    mov rcx, r13\n" /* 0a416 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a419 */
        "    mov dword ptr [rsp + 0x188], 0x1070b\n" /* 0a41e */
        "    mov qword ptr [rsp + 0x520], 1\n" /* 0a429 */
        "    mov qword ptr [rsp + 0x528], rsi\n" /* 0a435 */
        "    mov qword ptr [rsp + 0x530], 1\n" /* 0a43d */
        "    mov qword ptr [rsp + 0x538], 5\n" /* 0a449 */
        "    mov qword ptr [rsp + 0x540], 8\n" /* 0a455 */
        "    lea rdx, [rsp + 0x188]\n" /* 0a461 */
        "    lea r8, [rsp + 0x520]\n" /* 0a469 */
        "    mov rcx, r13\n" /* 0a471 */
        "    lea r13, [rip + rdata_rva_198e8]\n" /* 0a474 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a47b */
        "    mov rax, qword ptr [rip + data_rva_24210]\n" /* 0a480 */
        "    movsd xmm1, qword ptr [r14 + rax*8 - 8]\n" /* 0a487 */
        "    mov rdi, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 0a48e */
        "    movsd xmm0, qword ptr [rdi]\n" /* 0a495 */
        "    ucomisd xmm1, xmm0\n" /* 0a499 */
        S9_JAE32(.Lblock_a569) /* 0a49d */
        "    lea rdx, [r14 + rax*8]\n" /* 0a4a3 */
        "    add rdx, -8\n" /* 0a4a7 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a4ab */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0a4b0 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a4b7 */
        "    mov qword ptr [rsp + 0x20], r13\n" /* 0a4bc */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0a4c1 */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0a4c8 */
        "    lea r9, [rip + data_rva_22b40]\n" /* 0a4cf */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a4d6 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a4db */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a4e7 */
        "    mov edx, dword ptr [rax + 0x68]\n" /* 0a4ee */
        "    mov dword ptr [rsp + 0x184], 0x1070b\n" /* 0a4f1 */
        "    mov qword ptr [rsp + 0x4f8], 1\n" /* 0a4fc */
        "    mov qword ptr [rsp + 0x500], rsi\n" /* 0a508 */
        "    mov qword ptr [rsp + 0x508], 1\n" /* 0a510 */
        "    mov qword ptr [rsp + 0x510], 5\n" /* 0a51c */
        "    mov qword ptr [rsp + 0x518], 8\n" /* 0a528 */
        "    lea rax, [rip + data_rva_214ac]\n" /* 0a534 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a53b */
        "    lea rax, [rsp + 0x4f8]\n" /* 0a540 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a548 */
        "    lea rcx, [rsp + 0xd0]\n" /* 0a54d */
        "    lea r9, [rsp + 0x184]\n" /* 0a555 */
        "    mov r8, r15\n" /* 0a55d */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a560 */
        "    movsd xmm0, qword ptr [rdi]\n" /* 0a565 */
        ".Lblock_a569:\n"
        "    mov rax, qword ptr [rip + data_rva_24218]\n" /* 0a569 */
        "    movsd xmm1, qword ptr [r14 + rax*8 - 8]\n" /* 0a570 */
        "    ucomisd xmm1, xmm0\n" /* 0a577 */
        S9_JAE32(.Lblock_a647) /* 0a57b */
        "    lea rdx, [r14 + rax*8]\n" /* 0a581 */
        "    add rdx, -8\n" /* 0a585 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a589 */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0a58e */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a595 */
        "    mov qword ptr [rsp + 0x20], r13\n" /* 0a59a */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0a59f */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0a5a6 */
        "    lea r9, [rip + data_rva_22b40]\n" /* 0a5ad */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a5b4 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a5b9 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a5c5 */
        "    mov edx, dword ptr [rax + 0x68]\n" /* 0a5cc */
        "    mov dword ptr [rsp + 0x180], 0x1070b\n" /* 0a5cf */
        "    mov qword ptr [rsp + 0x4d0], 1\n" /* 0a5da */
        "    mov qword ptr [rsp + 0x4d8], rsi\n" /* 0a5e6 */
        "    mov qword ptr [rsp + 0x4e0], 1\n" /* 0a5ee */
        "    mov qword ptr [rsp + 0x4e8], 5\n" /* 0a5fa */
        "    mov qword ptr [rsp + 0x4f0], 8\n" /* 0a606 */
        "    lea rax, [rip + data_rva_21460]\n" /* 0a612 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a619 */
        "    lea rax, [rsp + 0x4d0]\n" /* 0a61e */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a626 */
        "    lea rcx, [rsp + 0xd0]\n" /* 0a62b */
        "    lea r9, [rsp + 0x180]\n" /* 0a633 */
        "    mov r8, r15\n" /* 0a63b */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a63e */
        "    movsd xmm0, qword ptr [rdi]\n" /* 0a643 */
        ".Lblock_a647:\n"
        "    mov rax, qword ptr [rip + data_rva_24220]\n" /* 0a647 */
        "    movsd xmm1, qword ptr [r14 + rax*8 - 8]\n" /* 0a64e */
        "    ucomisd xmm1, xmm0\n" /* 0a655 */
        "    mov rbp, qword ptr [rsp + 0x6c0]\n" /* 0a659 */
        S9_JAE32(.Lblock_a790) /* 0a661 */
        "    lea rdx, [r14 + rax*8]\n" /* 0a667 */
        "    add rdx, -8\n" /* 0a66b */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a66f */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0a674 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a67b */
        "    mov qword ptr [rsp + 0x20], r13\n" /* 0a680 */
        "    lea rcx, [rip + rdata_rva_198d0]\n" /* 0a685 */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0a68c */
        "    lea r9, [rip + data_rva_22b40]\n" /* 0a693 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a69a */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0a69f */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a6a6 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a6b2 */
        "    mov edx, dword ptr [rcx + 0x68]\n" /* 0a6b9 */
        "    mov dword ptr [rsp + 0x17c], 0x2010b\n" /* 0a6bc */
        "    mov qword ptr [rsp + 0x230], rax\n" /* 0a6c7 */
        "    lea rax, [rip + data_rva_21408]\n" /* 0a6cf */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a6d6 */
        "    lea rax, [rsp + 0x230]\n" /* 0a6db */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a6e3 */
        "    lea rdi, [rsp + 0xd0]\n" /* 0a6e8 */
        "    lea r9, [rsp + 0x17c]\n" /* 0a6f0 */
        "    mov rcx, rdi\n" /* 0a6f8 */
        "    mov r8, r15\n" /* 0a6fb */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a6fe */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0a703 */
        "    mov dword ptr [rsp + 0x178], 0x2010b\n" /* 0a70a */
        "    mov qword ptr [rsp + 0x228], rax\n" /* 0a715 */
        "    lea rdx, [rsp + 0x178]\n" /* 0a71d */
        "    lea r8, [rsp + 0x228]\n" /* 0a725 */
        "    mov rcx, rdi\n" /* 0a72d */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a730 */
        "    mov dword ptr [rsp + 0x174], 0x1070b\n" /* 0a735 */
        "    mov qword ptr [rsp + 0x4a8], 1\n" /* 0a740 */
        "    mov qword ptr [rsp + 0x4b0], rsi\n" /* 0a74c */
        "    mov qword ptr [rsp + 0x4b8], 1\n" /* 0a754 */
        "    mov qword ptr [rsp + 0x4c0], 5\n" /* 0a760 */
        "    mov qword ptr [rsp + 0x4c8], 8\n" /* 0a76c */
        "    lea rdx, [rsp + 0x174]\n" /* 0a778 */
        "    lea r8, [rsp + 0x4a8]\n" /* 0a780 */
        "    mov rcx, rdi\n" /* 0a788 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0a78b */
        ".Lblock_a790:\n"
        "    mov rax, qword ptr [rip + data_rva_24228]\n" /* 0a790 */
        "    lea rdx, [r14 + rax*8]\n" /* 0a797 */
        "    add rdx, -8\n" /* 0a79b */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a79f */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0a7a4 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a7ab */
        "    mov qword ptr [rsp + 0x20], r13\n" /* 0a7b0 */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0a7b5 */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0a7bc */
        "    lea r9, [rip + data_rva_22b40]\n" /* 0a7c3 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0a7ca */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a7cf */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a7db */
        "    mov edx, dword ptr [rax + 0x68]\n" /* 0a7e2 */
        "    mov dword ptr [rsp + 0x170], 0x1070b\n" /* 0a7e5 */
        "    mov qword ptr [rsp + 0x480], 1\n" /* 0a7f0 */
        "    mov qword ptr [rsp + 0x488], rsi\n" /* 0a7fc */
        "    mov qword ptr [rsp + 0x490], 1\n" /* 0a804 */
        "    mov qword ptr [rsp + 0x498], 5\n" /* 0a810 */
        "    mov qword ptr [rsp + 0x4a0], 8\n" /* 0a81c */
        "    lea rax, [rip + data_rva_213bc]\n" /* 0a828 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a82f */
        "    lea rax, [rsp + 0x480]\n" /* 0a834 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a83c */
        "    lea rcx, [rsp + 0xd0]\n" /* 0a841 */
        "    lea r9, [rsp + 0x170]\n" /* 0a849 */
        "    mov r8, r15\n" /* 0a851 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a854 */
        "    mov rsi, qword ptr [rsp + 0x6a8]\n" /* 0a859 */
        "    mov rax, qword ptr [rsi + 0x70]\n" /* 0a861 */
        "    cmp rax, 1\n" /* 0a865 */
        "    jne .Lblock_a8bc\n" /* 0a869 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a86b */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a877 */
        "    mov edx, dword ptr [rax + 0x68]\n" /* 0a87e */
        "    mov word ptr [rsp + 0xcc], 1\n" /* 0a881 */
        "    lea rax, [rip + data_rva_2138c]\n" /* 0a88b */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a892 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0a897 */
        "    lea rcx, [rsp + 0xd0]\n" /* 0a8a0 */
        "    lea r9, [rsp + 0xcc]\n" /* 0a8a8 */
        "    mov r8, r15\n" /* 0a8b0 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a8b3 */
        "    mov rax, qword ptr [rsi + 0x70]\n" /* 0a8b8 */
        ".Lblock_a8bc:\n"
        "    cmp rax, 2\n" /* 0a8bc */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 0a8c0 */
        "    mov rdi, qword ptr [rsp + 0x6b8]\n" /* 0a8c7 */
        "    jne .Lblock_a91e\n" /* 0a8cf */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a8d1 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a8dd */
        "    mov edx, dword ptr [rax + 0x68]\n" /* 0a8e4 */
        "    mov word ptr [rsp + 0xca], 1\n" /* 0a8e7 */
        "    lea rax, [rip + data_rva_2135c]\n" /* 0a8f1 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a8f8 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0a8fd */
        "    lea rcx, [rsp + 0xd0]\n" /* 0a906 */
        "    lea r9, [rsp + 0xca]\n" /* 0a90e */
        "    mov r8, r15\n" /* 0a916 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a919 */
        ".Lblock_a91e:\n"
        "    cmp qword ptr [rdi + 0x20], 0\n" /* 0a91e */
        S9_JE32(.Lblock_b927) /* 0a923 */
        "    cmp qword ptr [rip + data_rva_22b20], 1\n" /* 0a929 */
        S9_JE32(.Lblock_b927) /* 0a931 */
        "    movabs r15, 0x801208384ff00\n" /* 0a937 */
        "    mov qword ptr [rip + data_rva_22b00], 0xd\n" /* 0a941 */
        "    lea rcx, [rip + data_rva_22b00]\n" /* 0a94c */
        "    lea r9, [rsi + 8]\n" /* 0a953 */
        "    lea rdx, [rip + data_rva_22b30]\n" /* 0a957 */
        "    lea r8, [rip + data_rva_20e40]\n" /* 0a95e */
        "    call thunk_zereport_dll_ZREP_RPTHDR_rva_15310\n" /* 0a965 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0a96a */
        "    mov r12, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0a976 */
        "    mov edx, dword ptr [r12 + 0x68]\n" /* 0a97d */
        "    mov word ptr [rsp + 0xc8], 1\n" /* 0a982 */
        "    lea rax, [rip + data_rva_217dc]\n" /* 0a98c */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a993 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0a998 */
        "    lea rdi, [rsp + 0xd0]\n" /* 0a9a1 */
        "    lea r9, [rsp + 0xc8]\n" /* 0a9a9 */
        "    mov rcx, rdi\n" /* 0a9b1 */
        "    mov r8, r15\n" /* 0a9b4 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0a9b7 */
        "    mov rax, qword ptr [rip + data_rva_24248]\n" /* 0a9bc */
        "    lea rdx, [r14 + rax*8]\n" /* 0a9c3 */
        "    add rdx, -8\n" /* 0a9c7 */
        "    mov rbx, r14\n" /* 0a9cb */
        "    lea rsi, [rip + data_rva_22b60]\n" /* 0a9ce */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0a9d5 */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0a9da */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0a9e1 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0a9e6 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0a9ed */
        "    lea rcx, [rip + rdata_rva_198c8]\n" /* 0a9f2 */
        "    lea r13, [rip + data_rva_22ae0]\n" /* 0a9f9 */
        "    lea rbp, [rip + data_rva_22b40]\n" /* 0aa00 */
        "    mov r8, r13\n" /* 0aa07 */
        "    mov r9, rbp\n" /* 0aa0a */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0aa0d */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0aa12 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0aa19 */
        "    mov edx, dword ptr [r12 + 0x68]\n" /* 0aa25 */
        "    mov r14, r12\n" /* 0aa2a */
        "    mov dword ptr [rsp + 0x16c], 0x2010b\n" /* 0aa2d */
        "    mov qword ptr [rsp + 0x220], rax\n" /* 0aa38 */
        "    lea rax, [rip + data_rva_21304]\n" /* 0aa40 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0aa47 */
        "    lea rax, [rsp + 0x220]\n" /* 0aa4c */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0aa54 */
        "    lea r9, [rsp + 0x16c]\n" /* 0aa59 */
        "    mov rcx, rdi\n" /* 0aa61 */
        "    mov r8, r15\n" /* 0aa64 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0aa67 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0aa6c */
        "    mov dword ptr [rsp + 0x168], 0x2010b\n" /* 0aa73 */
        "    mov qword ptr [rsp + 0x218], rax\n" /* 0aa7e */
        "    lea rdx, [rsp + 0x168]\n" /* 0aa86 */
        "    lea r8, [rsp + 0x218]\n" /* 0aa8e */
        "    mov rcx, rdi\n" /* 0aa96 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0aa99 */
        "    mov dword ptr [rsp + 0x164], 0x1070b\n" /* 0aa9e */
        "    mov qword ptr [rsp + 0x458], 1\n" /* 0aaa9 */
        "    mov qword ptr [rsp + 0x460], rsi\n" /* 0aab5 */
        "    mov qword ptr [rsp + 0x468], 1\n" /* 0aabd */
        "    mov qword ptr [rsp + 0x470], 5\n" /* 0aac9 */
        "    mov qword ptr [rsp + 0x478], 8\n" /* 0aad5 */
        "    lea rdx, [rsp + 0x164]\n" /* 0aae1 */
        "    lea r8, [rsp + 0x458]\n" /* 0aae9 */
        "    mov rcx, rdi\n" /* 0aaf1 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0aaf4 */
        "    mov rax, qword ptr [rip + data_rva_24250]\n" /* 0aaf9 */
        "    lea rdx, [rbx + rax*8]\n" /* 0ab00 */
        "    add rdx, -8\n" /* 0ab04 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0ab08 */
        "    lea r12, [rip + data_rva_22b28]\n" /* 0ab0d */
        "    mov qword ptr [rsp + 0x28], r12\n" /* 0ab14 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0ab19 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0ab20 */
        "    lea rcx, [rip + rdata_rva_198c8]\n" /* 0ab25 */
        "    mov r8, r13\n" /* 0ab2c */
        "    mov r9, rbp\n" /* 0ab2f */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0ab32 */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0ab37 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0ab3e */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0ab4a */
        "    mov dword ptr [rsp + 0x160], 0x2010b\n" /* 0ab4e */
        "    mov qword ptr [rsp + 0x210], rax\n" /* 0ab59 */
        "    lea rax, [rip + data_rva_212b0]\n" /* 0ab61 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0ab68 */
        "    lea rax, [rsp + 0x210]\n" /* 0ab6d */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0ab75 */
        "    lea r9, [rsp + 0x160]\n" /* 0ab7a */
        "    mov rcx, rdi\n" /* 0ab82 */
        "    mov r8, r15\n" /* 0ab85 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0ab88 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0ab8d */
        "    mov dword ptr [rsp + 0x15c], 0x2010b\n" /* 0ab94 */
        "    mov qword ptr [rsp + 0x208], rax\n" /* 0ab9f */
        "    lea rdx, [rsp + 0x15c]\n" /* 0aba7 */
        "    lea r8, [rsp + 0x208]\n" /* 0abaf */
        "    mov rcx, rdi\n" /* 0abb7 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0abba */
        "    mov dword ptr [rsp + 0x158], 0x1070b\n" /* 0abbf */
        "    mov qword ptr [rsp + 0x430], 1\n" /* 0abca */
        "    mov qword ptr [rsp + 0x438], rsi\n" /* 0abd6 */
        "    mov qword ptr [rsp + 0x440], 1\n" /* 0abde */
        "    mov qword ptr [rsp + 0x448], 5\n" /* 0abea */
        "    mov qword ptr [rsp + 0x450], 8\n" /* 0abf6 */
        "    lea rdx, [rsp + 0x158]\n" /* 0ac02 */
        "    lea r8, [rsp + 0x430]\n" /* 0ac0a */
        "    mov rcx, rdi\n" /* 0ac12 */
        "    mov r15, rdi\n" /* 0ac15 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0ac18 */
        "    mov rax, qword ptr [rip + data_rva_24258]\n" /* 0ac1d */
        "    lea rdx, [rbx + rax*8]\n" /* 0ac24 */
        "    add rdx, -8\n" /* 0ac28 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0ac2c */
        "    mov qword ptr [rsp + 0x28], r12\n" /* 0ac31 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0ac36 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0ac3d */
        "    lea rdi, [rip + rdata_rva_198d8]\n" /* 0ac42 */
        "    mov rcx, rdi\n" /* 0ac49 */
        "    mov r8, r13\n" /* 0ac4c */
        "    mov r9, rbp\n" /* 0ac4f */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0ac52 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0ac57 */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0ac63 */
        "    mov dword ptr [rsp + 0x154], 0x1070b\n" /* 0ac67 */
        "    mov qword ptr [rsp + 0x408], 1\n" /* 0ac72 */
        "    mov qword ptr [rsp + 0x410], rsi\n" /* 0ac7e */
        "    mov qword ptr [rsp + 0x418], 1\n" /* 0ac86 */
        "    mov qword ptr [rsp + 0x420], 5\n" /* 0ac92 */
        "    mov qword ptr [rsp + 0x428], 8\n" /* 0ac9e */
        "    lea rax, [rip + data_rva_21268]\n" /* 0acaa */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0acb1 */
        "    lea rax, [rsp + 0x408]\n" /* 0acb6 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0acbe */
        "    lea r9, [rsp + 0x154]\n" /* 0acc3 */
        "    mov rcx, r15\n" /* 0accb */
        "    movabs r8, 0x801208384ff00\n" /* 0acce */
        "    mov r12, r8\n" /* 0acd8 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0acdb */
        "    mov rax, qword ptr [rip + data_rva_24260]\n" /* 0ace0 */
        "    lea rdx, [rbx + rax*8]\n" /* 0ace7 */
        "    add rdx, -8\n" /* 0aceb */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0acef */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0acf4 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0acfb */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0ad00 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0ad07 */
        "    mov rcx, rdi\n" /* 0ad0c */
        "    mov r8, r13\n" /* 0ad0f */
        "    mov r9, rbp\n" /* 0ad12 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0ad15 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0ad1a */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0ad26 */
        "    mov dword ptr [rsp + 0x150], 0x1070b\n" /* 0ad2a */
        "    mov qword ptr [rsp + 0x3e0], 1\n" /* 0ad35 */
        "    mov qword ptr [rsp + 0x3e8], rsi\n" /* 0ad41 */
        "    mov qword ptr [rsp + 0x3f0], 1\n" /* 0ad49 */
        "    mov qword ptr [rsp + 0x3f8], 5\n" /* 0ad55 */
        "    mov qword ptr [rsp + 0x400], 8\n" /* 0ad61 */
        "    lea rax, [rip + data_rva_21220]\n" /* 0ad6d */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0ad74 */
        "    lea rax, [rsp + 0x3e0]\n" /* 0ad79 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0ad81 */
        "    lea r9, [rsp + 0x150]\n" /* 0ad86 */
        "    mov rcx, r15\n" /* 0ad8e */
        "    mov r8, r12\n" /* 0ad91 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0ad94 */
        "    mov rax, qword ptr [rip + data_rva_24268]\n" /* 0ad99 */
        "    lea rdx, [rbx + rax*8]\n" /* 0ada0 */
        "    add rdx, -8\n" /* 0ada4 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0ada8 */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0adad */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0adb4 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0adb9 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0adc0 */
        "    mov rcx, rdi\n" /* 0adc5 */
        "    mov r8, r13\n" /* 0adc8 */
        "    mov r9, rbp\n" /* 0adcb */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0adce */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0add3 */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0addf */
        "    mov rdi, r14\n" /* 0ade3 */
        "    mov dword ptr [rsp + 0x14c], 0x1070b\n" /* 0ade6 */
        "    mov qword ptr [rsp + 0x3b8], 1\n" /* 0adf1 */
        "    mov qword ptr [rsp + 0x3c0], rsi\n" /* 0adfd */
        "    mov qword ptr [rsp + 0x3c8], 1\n" /* 0ae05 */
        "    mov qword ptr [rsp + 0x3d0], 5\n" /* 0ae11 */
        "    mov qword ptr [rsp + 0x3d8], 8\n" /* 0ae1d */
        "    lea rax, [rip + data_rva_211e0]\n" /* 0ae29 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0ae30 */
        "    lea rax, [rsp + 0x3b8]\n" /* 0ae35 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0ae3d */
        "    lea r9, [rsp + 0x14c]\n" /* 0ae42 */
        "    mov rcx, r15\n" /* 0ae4a */
        "    mov r8, r12\n" /* 0ae4d */
        "    mov r14, r12\n" /* 0ae50 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0ae53 */
        "    mov rax, qword ptr [rip + data_rva_24270]\n" /* 0ae58 */
        "    lea rdx, [rbx + rax*8]\n" /* 0ae5f */
        "    add rdx, -8\n" /* 0ae63 */
        "    mov qword ptr [rsp + 0x30], rsi\n" /* 0ae67 */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0ae6c */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0ae73 */
        "    lea r13, [rip + rdata_rva_198e8]\n" /* 0ae78 */
        "    mov qword ptr [rsp + 0x20], r13\n" /* 0ae7f */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0ae84 */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0ae8b */
        "    mov r9, rbp\n" /* 0ae92 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0ae95 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0ae9a */
        "    mov r13, rdi\n" /* 0aea6 */
        "    mov edx, dword ptr [rdi + 0x68]\n" /* 0aea9 */
        "    mov dword ptr [rsp + 0x148], 0x1070b\n" /* 0aeac */
        "    mov qword ptr [rsp + 0x390], 1\n" /* 0aeb7 */
        "    mov r12, rsi\n" /* 0aec3 */
        "    mov qword ptr [rsp + 0x398], rsi\n" /* 0aec6 */
        "    mov qword ptr [rsp + 0x3a0], 1\n" /* 0aece */
        "    mov qword ptr [rsp + 0x3a8], 5\n" /* 0aeda */
        "    mov qword ptr [rsp + 0x3b0], 8\n" /* 0aee6 */
        "    lea rax, [rip + data_rva_21194]\n" /* 0aef2 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0aef9 */
        "    lea rax, [rsp + 0x390]\n" /* 0aefe */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0af06 */
        "    lea r9, [rsp + 0x148]\n" /* 0af0b */
        "    mov rcx, r15\n" /* 0af13 */
        "    mov r8, r14\n" /* 0af16 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0af19 */
        "    mov rax, qword ptr [rip + data_rva_24220]\n" /* 0af1e */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 8]\n" /* 0af25 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 0af2b */
        "    ucomisd xmm0, qword ptr [rax]\n" /* 0af32 */
        S9_JAE32(.Lblock_b077) /* 0af36 */
        "    mov rax, qword ptr [rip + data_rva_24280]\n" /* 0af3c */
        "    lea rdx, [rbx + rax*8]\n" /* 0af43 */
        "    add rdx, -8\n" /* 0af47 */
        "    mov rsi, r12\n" /* 0af4b */
        "    mov qword ptr [rsp + 0x30], r12\n" /* 0af4e */
        "    lea rax, [rip + data_rva_22b28]\n" /* 0af53 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0af5a */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0af5f */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0af66 */
        "    lea rcx, [rip + rdata_rva_198d0]\n" /* 0af6b */
        "    lea r8, [rip + data_rva_22ae0]\n" /* 0af72 */
        "    lea r9, [rip + data_rva_22b40]\n" /* 0af79 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0af80 */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0af85 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0af8c */
        "    mov edx, dword ptr [r13 + 0x68]\n" /* 0af98 */
        "    mov dword ptr [rsp + 0x144], 0x2010b\n" /* 0af9c */
        "    mov qword ptr [rsp + 0x200], rax\n" /* 0afa7 */
        "    lea rax, [rip + data_rva_21148]\n" /* 0afaf */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0afb6 */
        "    lea rax, [rsp + 0x200]\n" /* 0afbb */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0afc3 */
        "    lea rdi, [rsp + 0xd0]\n" /* 0afc8 */
        "    lea r9, [rsp + 0x144]\n" /* 0afd0 */
        "    mov rcx, rdi\n" /* 0afd8 */
        "    movabs r8, 0x801208384ff00\n" /* 0afdb */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0afe5 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0afea */
        "    mov dword ptr [rsp + 0x140], 0x2010b\n" /* 0aff1 */
        "    mov qword ptr [rsp + 0x1f8], rax\n" /* 0affc */
        "    lea rdx, [rsp + 0x140]\n" /* 0b004 */
        "    lea r8, [rsp + 0x1f8]\n" /* 0b00c */
        "    mov rcx, rdi\n" /* 0b014 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b017 */
        "    mov dword ptr [rsp + 0x13c], 0x1070b\n" /* 0b01c */
        "    mov qword ptr [rsp + 0x368], 1\n" /* 0b027 */
        "    mov qword ptr [rsp + 0x370], r12\n" /* 0b033 */
        "    mov qword ptr [rsp + 0x378], 1\n" /* 0b03b */
        "    mov qword ptr [rsp + 0x380], 5\n" /* 0b047 */
        "    mov qword ptr [rsp + 0x388], 8\n" /* 0b053 */
        "    lea rdx, [rsp + 0x13c]\n" /* 0b05f */
        "    lea r8, [rsp + 0x368]\n" /* 0b067 */
        "    mov rcx, rdi\n" /* 0b06f */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b072 */
        ".Lblock_b077:\n"
        "    mov rax, qword ptr [rip + data_rva_24278]\n" /* 0b077 */
        "    lea rdx, [rbx + rax*8]\n" /* 0b07e */
        "    add rdx, -8\n" /* 0b082 */
        "    mov rdi, r12\n" /* 0b086 */
        "    mov qword ptr [rsp + 0x30], r12\n" /* 0b089 */
        "    lea r14, [rip + data_rva_22b28]\n" /* 0b08e */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 0b095 */
        "    lea rsi, [rip + rdata_rva_198e8]\n" /* 0b09a */
        "    mov qword ptr [rsp + 0x20], rsi\n" /* 0b0a1 */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0b0a6 */
        "    lea r15, [rip + data_rva_22ae0]\n" /* 0b0ad */
        "    lea r12, [rip + data_rva_22b40]\n" /* 0b0b4 */
        "    mov r8, r15\n" /* 0b0bb */
        "    mov r9, r12\n" /* 0b0be */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0b0c1 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b0c6 */
        "    mov edx, dword ptr [r13 + 0x68]\n" /* 0b0d2 */
        "    mov dword ptr [rsp + 0x138], 0x1070b\n" /* 0b0d6 */
        "    mov qword ptr [rsp + 0x340], 1\n" /* 0b0e1 */
        "    mov qword ptr [rsp + 0x348], rdi\n" /* 0b0ed */
        "    mov qword ptr [rsp + 0x350], 1\n" /* 0b0f5 */
        "    mov qword ptr [rsp + 0x358], 5\n" /* 0b101 */
        "    mov qword ptr [rsp + 0x360], 8\n" /* 0b10d */
        "    lea rax, [rip + data_rva_210f0]\n" /* 0b119 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b120 */
        "    lea rax, [rsp + 0x340]\n" /* 0b125 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b12d */
        "    lea r13, [rsp + 0xd0]\n" /* 0b132 */
        "    lea r9, [rsp + 0x138]\n" /* 0b13a */
        "    mov rcx, r13\n" /* 0b142 */
        "    movabs rbp, 0x801208384ff00\n" /* 0b145 */
        "    mov r8, rbp\n" /* 0b14f */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b152 */
        "    mov rax, qword ptr [rip + data_rva_242a8]\n" /* 0b157 */
        "    lea rdx, [rbx + rax*8]\n" /* 0b15e */
        "    add rdx, -8\n" /* 0b162 */
        "    mov qword ptr [rsp + 0x30], rdi\n" /* 0b166 */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 0b16b */
        "    mov qword ptr [rsp + 0x20], rsi\n" /* 0b170 */
        "    lea rcx, [rip + rdata_rva_198d8]\n" /* 0b175 */
        "    mov r8, r15\n" /* 0b17c */
        "    mov r9, r12\n" /* 0b17f */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0b182 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b187 */
        "    mov r12, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0b193 */
        "    mov edx, dword ptr [r12 + 0x68]\n" /* 0b19a */
        "    mov dword ptr [rsp + 0x134], 0x1070b\n" /* 0b19f */
        "    mov qword ptr [rsp + 0x318], 1\n" /* 0b1aa */
        "    mov qword ptr [rsp + 0x320], rdi\n" /* 0b1b6 */
        "    mov r15, rdi\n" /* 0b1be */
        "    mov qword ptr [rsp + 0x328], 1\n" /* 0b1c1 */
        "    mov qword ptr [rsp + 0x330], 5\n" /* 0b1cd */
        "    mov qword ptr [rsp + 0x338], 8\n" /* 0b1d9 */
        "    lea rax, [rip + data_rva_210b0]\n" /* 0b1e5 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b1ec */
        "    lea rax, [rsp + 0x318]\n" /* 0b1f1 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b1f9 */
        "    lea r9, [rsp + 0x134]\n" /* 0b1fe */
        "    mov rcx, r13\n" /* 0b206 */
        "    mov r8, rbp\n" /* 0b209 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b20c */
        "    mov rax, qword ptr [rip + data_rva_24290]\n" /* 0b211 */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 8]\n" /* 0b218 */
        "    mov rax, rsi\n" /* 0b21e */
        "    mov rsi, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 0b221 */
        "    mulsd xmm0, qword ptr [rsi + 0x60]\n" /* 0b228 */
        "    movsd qword ptr [rip + data_rva_22ab0], xmm0\n" /* 0b22d */
        "    lea rdx, [rip + data_rva_22ab0]\n" /* 0b235 */
        "    mov qword ptr [rsp + 0x30], rdi\n" /* 0b23c */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 0b241 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b246 */
        "    lea rcx, [rip + rdata_rva_198e0]\n" /* 0b24b */
        "    lea rdi, [rip + data_rva_22ae0]\n" /* 0b252 */
        "    mov r8, rdi\n" /* 0b259 */
        "    lea rbp, [rip + data_rva_22b40]\n" /* 0b25c */
        "    mov r9, rbp\n" /* 0b263 */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0b266 */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0b26b */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b272 */
        "    mov edx, dword ptr [r12 + 0x68]\n" /* 0b27e */
        "    mov dword ptr [rsp + 0x130], 0x2010b\n" /* 0b283 */
        "    mov qword ptr [rsp + 0x1f0], rax\n" /* 0b28e */
        "    lea rax, [rip + data_rva_21054]\n" /* 0b296 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b29d */
        "    lea rax, [rsp + 0x1f0]\n" /* 0b2a2 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b2aa */
        "    lea r9, [rsp + 0x130]\n" /* 0b2af */
        "    mov rcx, r13\n" /* 0b2b7 */
        "    movabs r8, 0x801208384ff00\n" /* 0b2ba */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b2c4 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0b2c9 */
        "    mov dword ptr [rsp + 0x12c], 0x2010b\n" /* 0b2d0 */
        "    mov qword ptr [rsp + 0x1e8], rax\n" /* 0b2db */
        "    lea rdx, [rsp + 0x12c]\n" /* 0b2e3 */
        "    lea r8, [rsp + 0x1e8]\n" /* 0b2eb */
        "    mov rcx, r13\n" /* 0b2f3 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b2f6 */
        "    mov dword ptr [rsp + 0x128], 0x1070b\n" /* 0b2fb */
        "    mov qword ptr [rsp + 0x2f0], 1\n" /* 0b306 */
        "    mov qword ptr [rsp + 0x2f8], r15\n" /* 0b312 */
        "    mov qword ptr [rsp + 0x300], 1\n" /* 0b31a */
        "    mov qword ptr [rsp + 0x308], 5\n" /* 0b326 */
        "    mov qword ptr [rsp + 0x310], 8\n" /* 0b332 */
        "    lea rdx, [rsp + 0x128]\n" /* 0b33e */
        "    lea r8, [rsp + 0x2f0]\n" /* 0b346 */
        "    mov rcx, r13\n" /* 0b34e */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b351 */
        "    mov rax, qword ptr [rip + data_rva_242a0]\n" /* 0b356 */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 8]\n" /* 0b35d */
        "    mulsd xmm0, qword ptr [rsi + 0x60]\n" /* 0b363 */
        "    movsd qword ptr [rip + data_rva_22aa0], xmm0\n" /* 0b368 */
        "    lea rdx, [rip + data_rva_22aa0]\n" /* 0b370 */
        "    mov qword ptr [rsp + 0x30], r15\n" /* 0b377 */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 0b37c */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0b381 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b388 */
        "    lea r12, [rip + rdata_rva_198e0]\n" /* 0b38d */
        "    mov rcx, r12\n" /* 0b394 */
        "    mov r8, rdi\n" /* 0b397 */
        "    mov r9, rbp\n" /* 0b39a */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0b39d */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0b3a2 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b3a9 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0b3b5 */
        "    mov edx, dword ptr [rcx + 0x68]\n" /* 0b3bc */
        "    mov dword ptr [rsp + 0x124], 0x2010b\n" /* 0b3bf */
        "    mov qword ptr [rsp + 0x1e0], rax\n" /* 0b3ca */
        "    lea rax, [rip + data_rva_20ff8]\n" /* 0b3d2 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b3d9 */
        "    lea rax, [rsp + 0x1e0]\n" /* 0b3de */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b3e6 */
        "    lea r9, [rsp + 0x124]\n" /* 0b3eb */
        "    mov rcx, r13\n" /* 0b3f3 */
        "    movabs r8, 0x801208384ff00\n" /* 0b3f6 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b400 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0b405 */
        "    mov dword ptr [rsp + 0x120], 0x2010b\n" /* 0b40c */
        "    mov qword ptr [rsp + 0x1d8], rax\n" /* 0b417 */
        "    lea rdx, [rsp + 0x120]\n" /* 0b41f */
        "    lea r8, [rsp + 0x1d8]\n" /* 0b427 */
        "    mov rcx, r13\n" /* 0b42f */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b432 */
        "    mov dword ptr [rsp + 0x11c], 0x1070b\n" /* 0b437 */
        "    mov qword ptr [rsp + 0x2c8], 1\n" /* 0b442 */
        "    mov qword ptr [rsp + 0x2d0], r15\n" /* 0b44e */
        "    mov qword ptr [rsp + 0x2d8], 1\n" /* 0b456 */
        "    mov qword ptr [rsp + 0x2e0], 5\n" /* 0b462 */
        "    mov qword ptr [rsp + 0x2e8], 8\n" /* 0b46e */
        "    lea rdx, [rsp + 0x11c]\n" /* 0b47a */
        "    lea r8, [rsp + 0x2c8]\n" /* 0b482 */
        "    mov rcx, r13\n" /* 0b48a */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b48d */
        "    mov rax, qword ptr [rip + data_rva_24288]\n" /* 0b492 */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 8]\n" /* 0b499 */
        "    mulsd xmm0, qword ptr [rsi + 0x60]\n" /* 0b49f */
        "    movsd qword ptr [rip + data_rva_22ab8], xmm0\n" /* 0b4a4 */
        "    lea rdx, [rip + data_rva_22ab8]\n" /* 0b4ac */
        "    mov qword ptr [rsp + 0x30], r15\n" /* 0b4b3 */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 0b4b8 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0b4bd */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b4c4 */
        "    mov rcx, r12\n" /* 0b4c9 */
        "    mov r8, rdi\n" /* 0b4cc */
        "    mov r9, rbp\n" /* 0b4cf */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0b4d2 */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0b4d7 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b4de */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0b4ea */
        "    mov edx, dword ptr [rcx + 0x68]\n" /* 0b4f1 */
        "    mov dword ptr [rsp + 0x118], 0x2010b\n" /* 0b4f4 */
        "    mov qword ptr [rsp + 0x1d0], rax\n" /* 0b4ff */
        "    lea rax, [rip + data_rva_20f9c]\n" /* 0b507 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b50e */
        "    lea rax, [rsp + 0x1d0]\n" /* 0b513 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b51b */
        "    lea r9, [rsp + 0x118]\n" /* 0b520 */
        "    mov rcx, r13\n" /* 0b528 */
        "    movabs r8, 0x801208384ff00\n" /* 0b52b */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b535 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0b53a */
        "    mov dword ptr [rsp + 0x114], 0x2010b\n" /* 0b541 */
        "    mov qword ptr [rsp + 0x1c8], rax\n" /* 0b54c */
        "    lea rdx, [rsp + 0x114]\n" /* 0b554 */
        "    lea r8, [rsp + 0x1c8]\n" /* 0b55c */
        "    mov rcx, r13\n" /* 0b564 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b567 */
        "    mov dword ptr [rsp + 0x110], 0x1070b\n" /* 0b56c */
        "    mov qword ptr [rsp + 0x2a0], 1\n" /* 0b577 */
        "    mov qword ptr [rsp + 0x2a8], r15\n" /* 0b583 */
        "    mov qword ptr [rsp + 0x2b0], 1\n" /* 0b58b */
        "    mov qword ptr [rsp + 0x2b8], 5\n" /* 0b597 */
        "    mov qword ptr [rsp + 0x2c0], 8\n" /* 0b5a3 */
        "    lea rdx, [rsp + 0x110]\n" /* 0b5af */
        "    lea r8, [rsp + 0x2a0]\n" /* 0b5b7 */
        "    mov rcx, r13\n" /* 0b5bf */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b5c2 */
        "    mov rax, qword ptr [rip + data_rva_24298]\n" /* 0b5c7 */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 8]\n" /* 0b5ce */
        "    mulsd xmm0, qword ptr [rsi + 0x60]\n" /* 0b5d4 */
        "    movabs rsi, 0x801208384ff00\n" /* 0b5d9 */
        "    movsd qword ptr [rip + data_rva_22aa8], xmm0\n" /* 0b5e3 */
        "    lea rdx, [rip + data_rva_22aa8]\n" /* 0b5eb */
        "    mov qword ptr [rsp + 0x30], r15\n" /* 0b5f2 */
        "    mov qword ptr [rsp + 0x28], r14\n" /* 0b5f7 */
        "    lea rax, [rip + rdata_rva_198e8]\n" /* 0b5fc */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b603 */
        "    mov rcx, r12\n" /* 0b608 */
        "    mov r8, rdi\n" /* 0b60b */
        "    mov r9, rbp\n" /* 0b60e */
        "    call thunk_zereport_dll_ZREP_RCONV1_rva_15334\n" /* 0b611 */
        "    mov rax, qword ptr [rip + data_rva_22b40]\n" /* 0b616 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b61d */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 0b629 */
        "    mov r14, rcx\n" /* 0b630 */
        "    mov edx, dword ptr [rcx + 0x68]\n" /* 0b633 */
        "    mov dword ptr [rsp + 0x10c], 0x2010b\n" /* 0b636 */
        "    mov qword ptr [rsp + 0x1c0], rax\n" /* 0b641 */
        "    lea rax, [rip + data_rva_20f44]\n" /* 0b649 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b650 */
        "    lea rax, [rsp + 0x1c0]\n" /* 0b655 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 0b65d */
        "    lea r9, [rsp + 0x10c]\n" /* 0b662 */
        "    mov rcx, r13\n" /* 0b66a */
        "    mov r8, rsi\n" /* 0b66d */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b670 */
        "    mov rax, qword ptr [rip + data_rva_22b48]\n" /* 0b675 */
        "    mov dword ptr [rsp + 0x108], 0x2010b\n" /* 0b67c */
        "    mov qword ptr [rsp + 0x1b8], rax\n" /* 0b687 */
        "    lea rdx, [rsp + 0x108]\n" /* 0b68f */
        "    lea r8, [rsp + 0x1b8]\n" /* 0b697 */
        "    mov rcx, r13\n" /* 0b69f */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b6a2 */
        "    mov dword ptr [rsp + 0x104], 0x1070b\n" /* 0b6a7 */
        "    mov qword ptr [rsp + 0x278], 1\n" /* 0b6b2 */
        "    mov qword ptr [rsp + 0x280], r15\n" /* 0b6be */
        "    mov qword ptr [rsp + 0x288], 1\n" /* 0b6c6 */
        "    mov qword ptr [rsp + 0x290], 5\n" /* 0b6d2 */
        "    mov qword ptr [rsp + 0x298], 8\n" /* 0b6de */
        "    lea rdx, [rsp + 0x104]\n" /* 0b6ea */
        "    lea r8, [rsp + 0x278]\n" /* 0b6f2 */
        "    mov rcx, r13\n" /* 0b6fa */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_xmit_rva_153fa\n" /* 0b6fd */
        "    mov rax, qword ptr [rip + data_rva_24298]\n" /* 0b702 */
        "    xorpd xmm6, xmm6\n" /* 0b709 */
        "    ucomisd xmm6, qword ptr [rbx + rax*8 - 8]\n" /* 0b70d */
        S9_JBE32(.Lblock_b7a8) /* 0b713 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b719 */
        "    mov r15, r14\n" /* 0b725 */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0b728 */
        "    mov word ptr [rsp + 0xc6], 1\n" /* 0b72c */
        "    lea rax, [rip + data_rva_20f24]\n" /* 0b736 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b73d */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0b742 */
        "    lea rdi, [rsp + 0xd0]\n" /* 0b74b */
        "    lea r9, [rsp + 0xc6]\n" /* 0b753 */
        "    mov rcx, rdi\n" /* 0b75b */
        "    mov r8, rsi\n" /* 0b75e */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b761 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b766 */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0b772 */
        "    mov word ptr [rsp + 0xc4], 1\n" /* 0b776 */
        "    lea rax, [rip + data_rva_20ec8]\n" /* 0b780 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b787 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0b78c */
        "    lea r9, [rsp + 0xc4]\n" /* 0b795 */
        "    mov rcx, rdi\n" /* 0b79d */
        "    mov r8, rsi\n" /* 0b7a0 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b7a3 */
        ".Lblock_b7a8:\n"
        "    mov rax, qword ptr [rip + data_rva_242a0]\n" /* 0b7a8 */
        "    movsd xmm0, qword ptr [rbx + rax*8 - 8]\n" /* 0b7af */
        "    ucomisd xmm0, xmm6\n" /* 0b7b5 */
        "    mov rbp, qword ptr [rsp + 0x6c0]\n" /* 0b7b9 */
        S9_JBE32(.Lblock_b853) /* 0b7c1 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b7c7 */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0b7d3 */
        "    mov word ptr [rsp + 0xc2], 1\n" /* 0b7d7 */
        "    lea rax, [rip + data_rva_20f24]\n" /* 0b7e1 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b7e8 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0b7ed */
        "    lea rdi, [rsp + 0xd0]\n" /* 0b7f6 */
        "    lea r9, [rsp + 0xc2]\n" /* 0b7fe */
        "    mov rcx, rdi\n" /* 0b806 */
        "    mov r8, rsi\n" /* 0b809 */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b80c */
        "    lea rax, [rip + data_rva_20e70]\n" /* 0b811 */
        "    mov qword ptr [rsp + 0xd0], 0\n" /* 0b818 */
        "    mov edx, dword ptr [r14 + 0x68]\n" /* 0b824 */
        "    mov word ptr [rsp + 0xc0], 1\n" /* 0b828 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b832 */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 0b837 */
        "    lea r9, [rsp + 0xc0]\n" /* 0b840 */
        "    mov rcx, rdi\n" /* 0b848 */
        "    mov r8, rsi\n" /* 0b84b */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 0b84e */
        ".Lblock_b853:\n"
        "    mov rax, qword ptr [rip + data_rva_242d8]\n" /* 0b853 */
        "    mov rcx, qword ptr [rsp + 0x668]\n" /* 0b85a */
        "    cmp qword ptr [rcx + rax*8 - 8], 1\n" /* 0b862 */
        S9_JNE32(.Lblock_b927) /* 0b868 */
        "    mov rax, qword ptr [rsp + 0x6e0]\n" /* 0b86e */
        "    mov rdx, qword ptr [rip + data_rva_24310]\n" /* 0b876 */
        "    mov rsi, qword ptr [rcx + rdx*8 - 8]\n" /* 0b87d */
        "    mov qword ptr [rip + data_rva_22ae8], rsi\n" /* 0b882 */
        "    mov rax, qword ptr [rax + 0x78]\n" /* 0b889 */
        "    lea rdx, [rax + rsi]\n" /* 0b88d */
        "    lea r8, [rdx + rsi]\n" /* 0b891 */
        "    lea r9, [r8 + r8]\n" /* 0b895 */
        "    mov r10, qword ptr [rip + iat_atdms_dll_DMS_WORK_rva_191e8]\n" /* 0b899 */
        "    add r9, qword ptr [r10 + 8]\n" /* 0b8a0 */
        "    lea r11, [rip + data_rva_22ae8]\n" /* 0b8a4 */
        "    lea rsi, [rsi + rsi*2]\n" /* 0b8ab */
        "    mov r10, qword ptr [r10]\n" /* 0b8af */
        "    add rax, r10\n" /* 0b8b2 */
        "    mov rdi, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 0b8b5 */
        "    lea rax, [rdi + rax*8]\n" /* 0b8bc */
        "    add rax, -8\n" /* 0b8c0 */
        "    add rdx, r10\n" /* 0b8c4 */
        "    lea rdx, [rdi + rdx*8]\n" /* 0b8c7 */
        "    add rdx, -8\n" /* 0b8cb */
        "    add r10, r8\n" /* 0b8cf */
        "    lea r8, [rdi + r10*8]\n" /* 0b8d2 */
        "    add r8, -8\n" /* 0b8d6 */
        "    lea r10, [rdi + r9*8 + 0xe8]\n" /* 0b8da */
        "    lea r9, [r9 + rsi*2 + 0x1e]\n" /* 0b8e2 */
        "    lea r9, [rdi + r9*8 - 8]\n" /* 0b8e7 */
        "    mov qword ptr [rsp + 0x50], rbp\n" /* 0b8ec */
        "    mov qword ptr [rsp + 0x48], r9\n" /* 0b8f1 */
        "    mov qword ptr [rsp + 0x40], r10\n" /* 0b8f6 */
        "    mov qword ptr [rsp + 0x38], r8\n" /* 0b8fb */
        "    mov qword ptr [rsp + 0x30], rdx\n" /* 0b900 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 0b905 */
        "    mov qword ptr [rsp + 0x20], r11\n" /* 0b90a */
        "    mov rdx, qword ptr [rsp + 0x660]\n" /* 0b90f */
        "    mov r8, rbx\n" /* 0b917 */
        "    mov r9, qword ptr [rsp + 0x670]\n" /* 0b91a */
        /* Pass the selected DMS_PLEX workspace slices to the optional report helper. */
        "    call sub_180001000_rva_1000\n" /* 0b922 */
        ".Lblock_b927:\n"
        "    mov rcx, rbp\n" /* 0b927 */
        /* Finalize the DMS workspace and submit the report buffer. */
        "    call thunk_atdms_dll_DMS_MSTAU_rva_152c2\n" /* 0b92a */
        "    mov rax, qword ptr [rip + data_rva_22ad0]\n" /* 0b92f */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 0b936 */
        "    lea rcx, [rcx + rax*8]\n" /* 0b93d */
        "    add rcx, 0x118\n" /* 0b941 */
        "    call thunk_zereport_dll_ZREP_MBUFS_rva_1533a\n" /* 0b948 */
        "    movaps xmm6, xmmword ptr [rsp + 0x5c0]\n" /* 0b94d */
        "    movaps xmm7, xmmword ptr [rsp + 0x5d0]\n" /* 0b955 */
        "    movaps xmm8, xmmword ptr [rsp + 0x5e0]\n" /* 0b95d */
        "    add rsp, 0x5f8\n" /* 0b966 */
        "    pop rbx\n" /* 0b96d */
        "    pop rbp\n" /* 0b96e */
        "    pop rdi\n" /* 0b96f */
        "    pop rsi\n" /* 0b970 */
        "    pop r12\n" /* 0b971 */
        "    pop r13\n" /* 0b973 */
        "    pop r14\n" /* 0b975 */
        "    pop r15\n" /* 0b977 */
        "    ret\n" /* 0b979 */
        END);
}
