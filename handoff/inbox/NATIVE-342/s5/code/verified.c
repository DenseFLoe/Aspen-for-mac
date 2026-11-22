/* Editable AMD64 bodies. External code and data symbols are linked to their original RVAs.
   Reassemble with reassemble.py on the Windows x86-64 target. */
#define BODY __attribute__((naked, used))
#define INTEL ".intel_syntax noprefix\n"
#define END ".att_syntax prefix\n"
/* LLVM normally selects the store-direction encoding for register-register operations.
   These macros retain the equivalent load-direction encoding and register operands. */
__asm__(
    ".set reg_al, 0\n"
    ".set reg_cl, 1\n"
    ".set reg_dl, 2\n"
    ".set reg_bl, 3\n"
    ".set reg_spl, 4\n"
    ".set reg_bpl, 5\n"
    ".set reg_sil, 6\n"
    ".set reg_dil, 7\n"
    ".set reg_r8b, 8\n"
    ".set reg_r9b, 9\n"
    ".set reg_r10b, 10\n"
    ".set reg_r11b, 11\n"
    ".set reg_r12b, 12\n"
    ".set reg_r13b, 13\n"
    ".set reg_r14b, 14\n"
    ".set reg_r15b, 15\n"
    ".set reg_ax, 0\n"
    ".set reg_cx, 1\n"
    ".set reg_dx, 2\n"
    ".set reg_bx, 3\n"
    ".set reg_sp, 4\n"
    ".set reg_bp, 5\n"
    ".set reg_si, 6\n"
    ".set reg_di, 7\n"
    ".set reg_r8w, 8\n"
    ".set reg_r9w, 9\n"
    ".set reg_r10w, 10\n"
    ".set reg_r11w, 11\n"
    ".set reg_r12w, 12\n"
    ".set reg_r13w, 13\n"
    ".set reg_r14w, 14\n"
    ".set reg_r15w, 15\n"
    ".set reg_eax, 0\n"
    ".set reg_ecx, 1\n"
    ".set reg_edx, 2\n"
    ".set reg_ebx, 3\n"
    ".set reg_esp, 4\n"
    ".set reg_ebp, 5\n"
    ".set reg_esi, 6\n"
    ".set reg_edi, 7\n"
    ".set reg_r8d, 8\n"
    ".set reg_r9d, 9\n"
    ".set reg_r10d, 10\n"
    ".set reg_r11d, 11\n"
    ".set reg_r12d, 12\n"
    ".set reg_r13d, 13\n"
    ".set reg_r14d, 14\n"
    ".set reg_r15d, 15\n"
    ".set reg_rax, 0\n"
    ".set reg_rcx, 1\n"
    ".set reg_rdx, 2\n"
    ".set reg_rbx, 3\n"
    ".set reg_rsp, 4\n"
    ".set reg_rbp, 5\n"
    ".set reg_rsi, 6\n"
    ".set reg_rdi, 7\n"
    ".set reg_r8, 8\n"
    ".set reg_r9, 9\n"
    ".set reg_r10, 10\n"
    ".set reg_r11, 11\n"
    ".set reg_r12, 12\n"
    ".set reg_r13, 13\n"
    ".set reg_r14, 14\n"
    ".set reg_r15, 15\n"
    ".macro apw_add8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 2, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_add16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 3, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_add32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 3, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_add64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 3, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_or8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 10, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_or16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 11, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_or32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 11, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_or64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 11, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_adc8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 18, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_adc16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 19, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_adc32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 19, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_adc64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 19, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sbb8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 26, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sbb16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 27, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sbb32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 27, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sbb64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 27, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_and8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 34, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_and16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 35, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_and32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 35, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_and64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 35, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sub8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 42, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sub16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 43, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sub32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 43, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_sub64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 43, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_xor8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 50, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_xor16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 51, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_xor32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 51, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_xor64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 51, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_cmp8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 58, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_cmp16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 59, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_cmp32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 59, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_cmp64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 59, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_mov8_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8) || (\\dst >= 4) || (\\src >= 4)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 138, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_mov16_load dst, src\n"
    ".byte 0x66\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 139, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_mov32_load dst, src\n"
    ".if 0 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 0 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 139, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
    ".macro apw_mov64_load dst, src\n"
    ".if 1 || (\\dst >= 8) || (\\src >= 8)\n"
    ".byte 0x40 | 8 | ((\\dst >> 3) << 2) | (\\src >> 3)\n"
    ".endif\n"
    ".byte 139, 0xc0 | ((\\dst & 7) << 3) | (\\src & 7)\n"
    ".endm\n"
);

/* body 0x1000 until 0x105e */
BODY void apw_1000(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rip + rva_527c0]\n"
        "call qword ptr [rip + rva_3a358]\n"
        "test eax, eax\n"
        "jne .L_1000_1044\n"
        "call qword ptr [rip + rva_3a350]\n"
        "test eax, eax\n"
        "jle .L_1000_102b\n"
        "movzx eax, ax\n"
        "or eax, 0x80070000\n"
        "test eax, eax\n"
        ".L_1000_102b:\n"
        "jns .L_1000_1044\n"
        "lea rcx, [rip + rva_39630]\n"
        "mov byte ptr [rip + rva_534b0], 1\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        ".L_1000_1044:\n"
        "lea rcx, [rip + rva_39630]\n"
        "mov dword ptr [rip + rva_527a0], 0x48\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x1060 until 0x10d3 */
BODY void apw_1060(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov ecx, dword ptr [rip + rva_54218]\n"
        "mov rax, qword ptr gs:[0x58]\n"
        "mov edx, 4\n"
        "mov rax, qword ptr [rax + rcx*8]\n"
        "mov eax, dword ptr [rdx + rax]\n"
        "cmp dword ptr [rip + rva_53528], eax\n"
        "jg .L_1060_109a\n"
        ".L_1060_1087:\n"
        "lea rax, [rip + rva_53518]\n"
        "mov qword ptr [rip + rva_53540], rax\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_1060_109a:\n"
        "lea rcx, [rip + rva_53528]\n"
        "call rva_35090\n"
        "cmp dword ptr [rip + rva_53528], -1\n"
        "jne .L_1060_1087\n"
        "lea rcx, [rip + rva_53528]\n"
        "mov qword ptr [rip + rva_53518], 8\n"
        "mov qword ptr [rip + rva_53520], 0xffffffffffffffff\n"
        "call rva_35024\n"
        "jmp .L_1060_1087\n"
        END);
}

/* body 0x10e0 until 0x1101 */
BODY void apw_10e0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rcx, [rip + rva_540c0]\n"
        "call qword ptr [rip + rva_3a920]\n"
        "lea rcx, [rip + rva_396d0]\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x1110 until 0x1131 */
BODY void apw_1110(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rcx, [rip + rva_540b0]\n"
        "call qword ptr [rip + rva_3a920]\n"
        "lea rcx, [rip + rva_396e0]\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x1140 until 0x1161 */
BODY void apw_1140(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rcx, [rip + rva_54088]\n"
        "call qword ptr [rip + rva_3a920]\n"
        "lea rcx, [rip + rva_396f0]\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x1170 until 0x1191 */
BODY void apw_1170(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rcx, [rip + rva_540b8]\n"
        "call qword ptr [rip + rva_3a920]\n"
        "lea rcx, [rip + rva_39700]\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x11a0 until 0x11c8 */
BODY void apw_11a0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rdx, [rip + rva_42464]\n"
        "lea rcx, [rip + rva_540a8]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        "lea rcx, [rip + rva_39710]\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x12ac until 0x12cc */
BODY void apw_12ac(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rcx, [rip + rva_547c0]\n"
        "call rva_36158\n"
        "lea rcx, [rip + rva_39820]\n"
        "add rsp, 0x28\n"
        "jmp rva_354a4\n"
        END);
}

/* body 0x12e0 until 0x12e3 */
BODY void apw_12e0(void) {
    __asm__(INTEL
        "ret 0\n"
        END);
}

/* body 0x12f0 until 0x1320 */
BODY void apw_12f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov rcx, qword ptr [rcx]\n"
        "test rcx, rcx\n"
        "je .L_12f0_1315\n"
        "call qword ptr [rip + rva_3a048]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov qword ptr [rbx], rax\n"
        "mov dword ptr [rbx + 8], eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        ".L_12f0_1315:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov dword ptr [rbx + 8], eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1320 until 0x1390 */
BODY void apw_1320(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "mov dword ptr [rsp + 0x30], 0\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rsp + 0x30], 1\n"
        "mov r9, qword ptr [rbx]\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov eax, dword ptr [r9 - 0x10]\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "mov r8d, dword ptr [rdx - 0x10]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3a928]\n"
        "apw_mov64_load reg_rax, reg_rsi\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x13a0 until 0x142b */
BODY void apw_13a0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "push r14\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "apw_mov64_load reg_r14, reg_rdx\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "apw_xor32_load reg_ebx, reg_ebx\n"
        "mov dword ptr [rsp + 0x30], ebx\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rsp + 0x30], 1\n"
        "test rdi, rdi\n"
        "je .L_13a0_13fb\n"
        "mov rbx, 0xffffffffffffffff\n"
        ".L_13a0_13f2:\n"
        "inc rbx\n"
        "cmp byte ptr [rdi + rbx], 0\n"
        "jne .L_13a0_13f2\n"
        ".L_13a0_13fb:\n"
        "mov rdx, qword ptr [r14]\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "mov r8d, dword ptr [rdx - 0x10]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3a928]\n"
        "apw_mov64_load reg_rax, reg_rsi\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "mov rdi, qword ptr [rsp + 0x68]\n"
        "add rsp, 0x40\n"
        "pop r14\n"
        "ret\n"
        END);
}

/* body 0x1430 until 0x14c4 */
BODY void apw_1430(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rbp\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_rbp, reg_rcx\n"
        "apw_xor32_load reg_ebx, reg_ebx\n"
        "mov dword ptr [rsp + 0x30], ebx\n"
        "apw_mov64_load reg_rcx, reg_r8\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rsp + 0x30], 1\n"
        "mov r9, qword ptr [rdi]\n"
        "mov eax, dword ptr [r9 - 0x10]\n"
        "test rsi, rsi\n"
        "je .L_1430_1499\n"
        "mov rbx, 0xffffffffffffffff\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1430_1490:\n"
        "inc rbx\n"
        "cmp byte ptr [rsi + rbx], 0\n"
        "jne .L_1430_1490\n"
        ".L_1430_1499:\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "apw_mov32_load reg_r8d, reg_ebx\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "call qword ptr [rip + rva_3a928]\n"
        "apw_mov64_load reg_rax, reg_rbp\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rbp, qword ptr [rsp + 0x60]\n"
        "mov rsi, qword ptr [rsp + 0x68]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x14d0 until 0x1519 */
BODY void apw_14d0(void) {
    __asm__(INTEL
        "movsxd r10, dword ptr [rcx]\n"
        "apw_mov64_load reg_r11, reg_r9\n"
        "test r10d, r10d\n"
        "js .L_14d0_1516\n"
        "cmp r10, 0x33\n"
        "jae .L_14d0_1516\n"
        "lea rax, [r10 + r10*2]\n"
        "lea r9, [rip + rva_3f050]\n"
        "lea r9, [r9 + rax*8]\n"
        "lea eax, [r10 + 1]\n"
        "mov dword ptr [rcx], eax\n"
        "cmp dword ptr [r9 + 4], 0\n"
        "je .L_14d0_1516\n"
        "mov eax, dword ptr [r9]\n"
        "mov dword ptr [rdx], eax\n"
        "mov eax, dword ptr [r9 + 4]\n"
        "mov dword ptr [r8], eax\n"
        "mov eax, dword ptr [r9 + 8]\n"
        "mov dword ptr [r11], eax\n"
        "mov eax, 1\n"
        "ret\n"
        ".L_14d0_1516:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "ret\n"
        END);
}

/* body 0x1520 until 0x1527 */
BODY void apw_1520(void) {
    __asm__(INTEL
        "mov eax, dword ptr [rip + rva_5279c]\n"
        "ret\n"
        END);
}

/* body 0x1530 until 0x1537 */
BODY void apw_1530(void) {
    __asm__(INTEL
        "mov eax, dword ptr [rip + rva_534f4]\n"
        "ret\n"
        END);
}

/* body 0x1540 until 0x1547 */
BODY void apw_1540(void) {
    __asm__(INTEL
        "mov eax, dword ptr [rip + rva_52798]\n"
        "ret\n"
        END);
}

/* body 0x1550 until 0x156e */
BODY void apw_1550(void) {
    __asm__(INTEL
        "mov dword ptr [rip + rva_534f0], 1\n"
        "mov dword ptr [rip + rva_52798], ecx\n"
        "mov dword ptr [rip + rva_5279c], edx\n"
        "mov dword ptr [rip + rva_534f4], r8d\n"
        "ret\n"
        END);
}

/* body 0x1680 until 0x18bd */
BODY void apw_1680(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "sub rsp, 0x420\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x410], rax\n"
        "cmp dword ptr [rip + rva_534f0], 0\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "jne .L_1680_16c3\n"
        "call rva_1570\n"
        "cmp dword ptr [rip + rva_534f0], 0\n"
        "jne .L_1680_16c3\n"
        "call rva_1570\n"
        ".L_1680_16c3:\n"
        "apw_xor32_load reg_edi, reg_edi\n"
        "lea rax, [rip + rva_3f050]\n"
        "cmp qword ptr [rip + rva_3f060], rdi\n"
        "je .L_1680_1705\n"
        "mov ecx, dword ptr [rip + rva_52798]\n"
        "mov edx, dword ptr [rip + rva_5279c]\n"
        "mov r8d, dword ptr [rip + rva_534f4]\n"
        ".L_1680_16e8:\n"
        "cmp dword ptr [rax], ecx\n"
        "jne .L_1680_16fb\n"
        "cmp dword ptr [rax + 4], edx\n"
        "jne .L_1680_16fb\n"
        "cmp dword ptr [rax + 8], r8d\n"
        "je .L_1680_189f\n"
        ".L_1680_16fb:\n"
        "add rax, 0x18\n"
        "cmp qword ptr [rax + 0x10], rdi\n"
        "jne .L_1680_16e8\n"
        ".L_1680_1705:\n"
        "mov r9d, 0x71e\n"
        "lea r8, [rip + rva_40968]\n"
        "lea rdx, [rip + rva_409a0]\n"
        "lea rcx, [rsp + 0x20]\n"
        "call rva_1ce0\n"
        "mov edx, 2\n"
        "lea rcx, [rsp + 0x20]\n"
        "lea r8d, [rdx - 1]\n"
        "call qword ptr [rip + rva_3a5b0]\n"
        "mov ecx, dword ptr [rip + rva_52798]\n"
        "apw_mov64_load reg_rbx, reg_rdi\n"
        ".L_1680_1740:\n"
        "mov rax, qword ptr [rbx]\n"
        "test rax, rax\n"
        "je .L_1680_1777\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1680_1750:\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a2e0]\n"
        "test eax, eax\n"
        "je .L_1680_18a8\n"
        "mov rax, qword ptr [rbx + 0x10]\n"
        "add rbx, 0x10\n"
        "test rax, rax\n"
        "jne .L_1680_1750\n"
        "mov ecx, dword ptr [rip + rva_52798]\n"
        ".L_1680_1777:\n"
        "cmp dword ptr [rip + rva_534f0], edi\n"
        "jne .L_1680_178a\n"
        "call rva_1570\n"
        "mov ecx, dword ptr [rip + rva_52798]\n"
        ".L_1680_178a:\n"
        "cmp qword ptr [rip + rva_3f530], rdi\n"
        "lea rax, [rip + rva_3f520]\n"
        "je .L_1680_17b2\n"
        ".byte 0x66,0xf,0x1f,0x44,0x0,0x0 # alignment NOP\n"
        ".L_1680_17a0:\n"
        "cmp dword ptr [rax], ecx\n"
        "je .L_1680_18ae\n"
        "add rax, 0x18\n"
        "cmp qword ptr [rax + 0x10], rdi\n"
        "jne .L_1680_17a0\n"
        ".L_1680_17b2:\n"
        "mov r9d, 0x72b\n"
        "lea r8, [rip + rva_40968]\n"
        "lea rdx, [rip + rva_409a0]\n"
        "lea rcx, [rsp + 0x20]\n"
        "call rva_1ce0\n"
        "mov edx, 2\n"
        "lea rcx, [rsp + 0x20]\n"
        "lea r8d, [rdx - 1]\n"
        "call qword ptr [rip + rva_3a5b0]\n"
        ".L_1680_17e4:\n"
        "mov rax, qword ptr [rdi]\n"
        "test rax, rax\n"
        "je .L_1680_1811\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".L_1680_17f0:\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a2e0]\n"
        "test eax, eax\n"
        "je .L_1680_18b7\n"
        "mov rax, qword ptr [rdi + 0x10]\n"
        "add rdi, 0x10\n"
        "test rax, rax\n"
        "jne .L_1680_17f0\n"
        ".L_1680_1811:\n"
        "mov rax, qword ptr [rip + rva_4e000]\n"
        "lea rbx, [rip + rva_4e000]\n"
        "test rax, rax\n"
        "je .L_1680_1841\n"
        ".L_1680_1824:\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a2e0]\n"
        "test eax, eax\n"
        "je .L_1680_18a8\n"
        "mov rax, qword ptr [rbx + 0x10]\n"
        "add rbx, 0x10\n"
        "test rax, rax\n"
        "jne .L_1680_1824\n"
        ".L_1680_1841:\n"
        "mov r9d, 0x743\n"
        "lea r8, [rip + rva_40968]\n"
        "lea rdx, [rip + rva_409a0]\n"
        "lea rcx, [rsp + 0x20]\n"
        "call rva_1ce0\n"
        "mov edx, 2\n"
        "lea rcx, [rsp + 0x20]\n"
        "lea r8d, [rdx - 1]\n"
        "call qword ptr [rip + rva_3a5b0]\n"
        "lea rax, [rip + rva_3ad3b]\n"
        ".L_1680_187a:\n"
        "mov rcx, qword ptr [rsp + 0x410]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x420]\n"
        "mov rbx, qword ptr [r11 + 0x18]\n"
        "mov rsi, qword ptr [r11 + 0x20]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop rdi\n"
        "ret\n"
        ".L_1680_189f:\n"
        "mov rbx, qword ptr [rax + 0x10]\n"
        "jmp .L_1680_1740\n"
        ".L_1680_18a8:\n"
        "mov rax, qword ptr [rbx + 8]\n"
        "jmp .L_1680_187a\n"
        ".L_1680_18ae:\n"
        "mov rdi, qword ptr [rax + 0x10]\n"
        "jmp .L_1680_17e4\n"
        ".L_1680_18b7:\n"
        "mov rax, qword ptr [rdi + 8]\n"
        "jmp .L_1680_187a\n"
        END);
}

/* body 0x18c0 until 0x18cb */
BODY void apw_18c0(void) {
    __asm__(INTEL
        "mov dword ptr [rip + rva_534f0], 0\n"
        "ret\n"
        END);
}

/* body 0x1a20 until 0x1a2c */
BODY void apw_1a20(void) {
    __asm__(INTEL
        "lea rcx, [rip + rva_3b638]\n"
        "jmp rva_1680\n"
        END);
}

/* body 0x1b30 until 0x1cbd */
BODY void apw_1b30(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "push r14\n"
        "push r15\n"
        "lea rbp, [rsp - 0x80]\n"
        "sub rsp, 0x180\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x70], rax\n"
        "mov edi, dword ptr [rcx + 8]\n"
        "lea rax, [rsp + 0x60]\n"
        "apw_xor32_load reg_r15d, reg_r15d\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "mov qword ptr [rsp + 0x48], r15\n"
        "mov rcx, qword ptr [rcx]\n"
        "or edi, 0x2001f\n"
        "apw_mov32_load reg_r9d, reg_edi\n"
        "mov dword ptr [rsp + 0x50], r15d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov qword ptr [rsp + 0x58], r15\n"
        "apw_mov64_load reg_r14, reg_rdx\n"
        "mov qword ptr [rsp + 0x60], r15\n"
        "call qword ptr [rip + rva_3a020]\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "test eax, eax\n"
        "jne .L_1b30_1bc4\n"
        "apw_mov32_load reg_ebx, reg_r15d\n"
        "test rcx, rcx\n"
        "je .L_1b30_1bb0\n"
        "call qword ptr [rip + rva_3a048]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        ".L_1b30_1bb0:\n"
        "mov rcx, qword ptr [rsp + 0x60]\n"
        "and edi, 0x300\n"
        "mov qword ptr [rsp + 0x48], rcx\n"
        "mov dword ptr [rsp + 0x50], edi\n"
        ".L_1b30_1bc4:\n"
        "test ebx, ebx\n"
        "jne .L_1b30_1c8d\n"
        "lea rax, [rsp + 0x68]\n"
        "mov dword ptr [rsp + 0x40], 0x100\n"
        "mov qword ptr [rsp + 0x38], rax\n"
        "lea r9, [rsp + 0x40]\n"
        "mov qword ptr [rsp + 0x30], r15\n"
        "lea r8, [rsp + 0x70]\n"
        "mov qword ptr [rsp + 0x28], r15\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov qword ptr [rsp + 0x20], r15\n"
        "call qword ptr [rip + rva_3a018]\n"
        "test eax, eax\n"
        "jne .L_1b30_1c61\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1b30_1c10:\n"
        "lea rdx, [rsp + 0x70]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call rva_1b30\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "test eax, eax\n"
        "jne .L_1b30_1c8d\n"
        "lea rax, [rsp + 0x68]\n"
        "mov dword ptr [rsp + 0x40], 0x100\n"
        "mov qword ptr [rsp + 0x38], rax\n"
        "lea r9, [rsp + 0x40]\n"
        "mov qword ptr [rsp + 0x30], r15\n"
        "lea r8, [rsp + 0x70]\n"
        "mov qword ptr [rsp + 0x28], r15\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov qword ptr [rsp + 0x20], r15\n"
        "call qword ptr [rip + rva_3a018]\n"
        "test eax, eax\n"
        "je .L_1b30_1c10\n"
        ".L_1b30_1c61:\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "test rcx, rcx\n"
        "je .L_1b30_1c76\n"
        "call qword ptr [rip + rva_3a048]\n"
        "mov qword ptr [rsp + 0x48], r15\n"
        ".L_1b30_1c76:\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "mov dword ptr [rsp + 0x50], r15d\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_18f0\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        ".L_1b30_1c8d:\n"
        "test rcx, rcx\n"
        "je .L_1b30_1c98\n"
        "call qword ptr [rip + rva_3a048]\n"
        ".L_1b30_1c98:\n"
        "apw_mov32_load reg_eax, reg_ebx\n"
        "mov rcx, qword ptr [rbp + 0x70]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x1c0]\n"
        "add rsp, 0x180\n"
        "pop r15\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x1cc0 until 0x1cc7 */
BODY void apw_1cc0(void) {
    __asm__(INTEL
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a358]\n"
        END);
}

/* body 0x1cd0 until 0x1cd8 */
BODY void apw_1cd0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_534d8]\n"
        "ret\n"
        END);
}

/* body 0x1ce0 until 0x1d3e */
BODY void apw_1ce0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "mov qword ptr [rsp + 0x18], r8\n"
        "mov qword ptr [rsp + 0x20], r9\n"
        "push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "lea rsi, [rsp + 0x60]\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "call rva_1cd0\n"
        "apw_mov64_load reg_r9, reg_rbx\n"
        "mov qword ptr [rsp + 0x28], rsi\n"
        "mov rbx, 0xffffffffffffffff\n"
        "mov qword ptr [rsp + 0x20], 0\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "mov rcx, qword ptr [rax]\n"
        "or rcx, 1\n"
        "call qword ptr [rip + rva_3a830]\n"
        "test eax, eax\n"
        "cmovs eax, ebx\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1d40 until 0x1d43 */
BODY void apw_1d40(void) {
    __asm__(INTEL
        "apw_xor32_load reg_eax, reg_eax\n"
        "ret\n"
        END);
}

/* body 0x1d50 until 0x1d66 */
BODY void apw_1d50(void) {
    __asm__(INTEL
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_mov32_load reg_r8d, reg_ecx\n"
        "mov rcx, qword ptr [rip + rva_534d0]\n"
        "lea edx, [r9 + 0x66]\n"
        "jmp rva_5e20\n"
        END);
}

/* body 0x1d70 until 0x1d9e */
BODY void apw_1d70(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "test rax, rax\n"
        "je .L_1d70_1d98\n"
        ".L_1d70_1d81:\n"
        "mov rdx, qword ptr [rax]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov qword ptr [rbx], rdx\n"
        "call qword ptr [rip + rva_3a728]\n"
        "mov rax, qword ptr [rbx]\n"
        "test rax, rax\n"
        "jne .L_1d70_1d81\n"
        ".L_1d70_1d98:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1da0 until 0x1dbe */
BODY void apw_1da0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov rcx, qword ptr [rcx]\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx], 0\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1ec0 until 0x1f4c */
BODY void apw_1ec0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov32_load reg_esi, reg_edx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "lea rax, [rip + rva_40b48]\n"
        "mov qword ptr [rcx], rax\n"
        "add rcx, 8\n"
        "call rva_3b40\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rdi + 8]\n"
        "call rva_3b40\n"
        "mov rcx, qword ptr [rdi + 8]\n"
        "test rcx, rcx\n"
        "je .L_1ec0_1f08\n"
        "call qword ptr [rip + rva_3a728]\n"
        "mov qword ptr [rdi + 8], 0\n"
        ".L_1ec0_1f08:\n"
        "mov rcx, qword ptr [rdi + 0x10]\n"
        "test rcx, rcx\n"
        "je .L_1ec0_1f1f\n"
        "call qword ptr [rip + rva_3a728]\n"
        "mov qword ptr [rdi + 0x10], 0\n"
        ".L_1ec0_1f1f:\n"
        "mov dword ptr [rdi + 0x18], 0\n"
        "test sil, 1\n"
        "je .L_1ec0_1f39\n"
        "mov edx, 0x28\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        ".L_1ec0_1f39:\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1f50 until 0x1f59 */
BODY void apw_1f50(void) {
    __asm__(INTEL
        "mov eax, dword ptr [rcx + 0x18]\n"
        "inc eax\n"
        "mov dword ptr [rcx + 0x18], eax\n"
        "ret\n"
        END);
}

/* body 0x1f5c until 0x1f65 */
BODY void apw_1f5c(void) {
    __asm__(INTEL
        "sub rcx, 8\n"
        "jmp rva_1f50\n"
        END);
}

/* body 0x1f68 until 0x1f71 */
BODY void apw_1f68(void) {
    __asm__(INTEL
        "sub rcx, 0x10\n"
        "jmp rva_1f50\n"
        END);
}

/* body 0x1f80 until 0x1f86 */
BODY void apw_1f80(void) {
    __asm__(INTEL
        "mov eax, 1\n"
        "ret\n"
        END);
}

/* body 0x2c90 until 0x2cab */
BODY void apw_2c90(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call qword ptr [rip + rva_3a350]\n"
        "test eax, eax\n"
        "jle .L_2c90_2ca6\n"
        "movzx eax, ax\n"
        "or eax, 0x80070000\n"
        ".L_2c90_2ca6:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x2cb0 until 0x2cc0 */
BODY void apw_2cb0(void) {
    __asm__(INTEL
        "test ecx, ecx\n"
        "jg .L_2cb0_2cb7\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "ret\n"
        ".L_2cb0_2cb7:\n"
        "movzx eax, cx\n"
        "or eax, 0x80070000\n"
        "ret\n"
        END);
}

/* body 0x3bf0 until 0x3bf9 */
BODY void apw_3bf0(void) {
    __asm__(INTEL
        "add rcx, 8\n"
        "jmp rva_3b40\n"
        END);
}

/* body 0x3da0 until 0x3daa */
BODY void apw_3da0(void) {
    __asm__(INTEL
        "mov rcx, qword ptr [rcx]\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a728]\n"
        END);
}

/* body 0x4674 until 0x467d */
BODY void apw_4674(void) {
    __asm__(INTEL
        "sub rcx, 8\n"
        "jmp rva_4540\n"
        END);
}

/* body 0x4680 until 0x4689 */
BODY void apw_4680(void) {
    __asm__(INTEL
        "sub rcx, 0x10\n"
        "jmp rva_4540\n"
        END);
}

/* body 0x4690 until 0x4696 */
BODY void apw_4690(void) {
    __asm__(INTEL
        "mov eax, 0x80004001\n"
        "ret\n"
        END);
}

/* body 0x5d48 until 0x5d51 */
BODY void apw_5d48(void) {
    __asm__(INTEL
        "sub rcx, 8\n"
        "jmp rva_5cf0\n"
        END);
}

/* body 0x5d54 until 0x5d5d */
BODY void apw_5d54(void) {
    __asm__(INTEL
        "sub rcx, 0x10\n"
        "jmp rva_5cf0\n"
        END);
}

/* body 0x5d60 until 0x5e12 */
BODY void apw_5d60(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "push rdi\n"
        "mov eax, 0x1030\n"
        "call rva_355d0\n"
        "apw_sub64_load reg_rsp, reg_rax\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x1020], rax\n"
        "cmp byte ptr [rdx], 0x3d\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "jne .L_5d60_5def\n"
        "call rva_3db0\n"
        "test eax, eax\n"
        "js .L_5d60_5df1\n"
        ".byte 0xf,0x1f,0x80,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_5d60_5da0:\n"
        "mov rdx, qword ptr [rbx]\n"
        "movsx eax, byte ptr [rdx]\n"
        "sub eax, 9\n"
        "je .L_5d60_5dba\n"
        "sub eax, 1\n"
        "je .L_5d60_5dba\n"
        "sub eax, 3\n"
        "je .L_5d60_5dba\n"
        "cmp eax, 0x13\n"
        "jne .L_5d60_5dc8\n"
        ".L_5d60_5dba:\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "call qword ptr [rip + rva_3a5c0]\n"
        "mov qword ptr [rbx], rax\n"
        "jmp .L_5d60_5da0\n"
        ".L_5d60_5dc8:\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_3db0\n"
        "test eax, eax\n"
        "js .L_5d60_5df1\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_3db0\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "test eax, eax\n"
        "cmovs ecx, eax\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "jmp .L_5d60_5df1\n"
        ".L_5d60_5def:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_5d60_5df1:\n"
        "mov rcx, qword ptr [rsp + 0x1020]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x1050]\n"
        "add rsp, 0x1030\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x6e80 until 0x6e8d */
BODY void apw_6e80(void) {
    __asm__(INTEL
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "je .L_6e80_6e8c\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a728]\n"
        ".L_6e80_6e8c:\n"
        "ret\n"
        END);
}

/* body 0x7020 until 0x7051 */
BODY void apw_7020(void) {
    __asm__(INTEL
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "je .L_7020_7050\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        ".L_7020_7035:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_8b00\n"
        "add rbx, 0x40\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "jne .L_7020_7035\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        ".L_7020_7050:\n"
        "ret\n"
        END);
}

/* body 0x70f0 until 0x72b1 */
BODY void apw_70f0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "sub rsp, 0x50\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "apw_mov64_load reg_r15, reg_rdx\n"
        "apw_mov64_load reg_r12, reg_rcx\n"
        "mov r13, qword ptr [rcx]\n"
        "mov rbx, qword ptr [r13 + 8]\n"
        "mov qword ptr [rsp + 0x30], rbx\n"
        "mov dword ptr [rsp + 0x38], 0\n"
        "apw_mov64_load reg_r14, reg_r13\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "jne .L_70f0_71a5\n"
        "mov rbp, qword ptr [r8 + 0x10]\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_70f0_7130:\n"
        "mov qword ptr [rsp + 0x30], rbx\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "cmp qword ptr [rsi + 0x18], 0x10\n"
        "jb .L_70f0_7142\n"
        "mov rdx, qword ptr [rsi]\n"
        ".L_70f0_7142:\n"
        "lea rcx, [rbx + 0x20]\n"
        "cmp qword ptr [rbx + 0x38], 0x10\n"
        "jb .L_70f0_7151\n"
        "mov rcx, qword ptr [rbx + 0x20]\n"
        ".L_70f0_7151:\n"
        "mov rdi, qword ptr [rbx + 0x30]\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_cmp64_load reg_rbp, reg_rdi\n"
        "cmovb r8, rbp\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "jne .L_70f0_717c\n"
        "apw_cmp64_load reg_rdi, reg_rbp\n"
        "jae .L_70f0_7174\n"
        "mov eax, 0xffffffff\n"
        "jmp .L_70f0_717c\n"
        ".L_70f0_7174:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "apw_cmp64_load reg_rdi, reg_rbp\n"
        "seta al\n"
        ".L_70f0_717c:\n"
        "shr eax, 0x1f\n"
        "test al, al\n"
        "je .L_70f0_7191\n"
        "mov dword ptr [rsp + 0x38], 0\n"
        "mov rbx, qword ptr [rbx + 0x10]\n"
        "jmp .L_70f0_719f\n"
        ".L_70f0_7191:\n"
        "mov dword ptr [rsp + 0x38], 1\n"
        "apw_mov64_load reg_r14, reg_rbx\n"
        "mov rbx, qword ptr [rbx]\n"
        ".L_70f0_719f:\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "je .L_70f0_7130\n"
        ".L_70f0_71a5:\n"
        "cmp byte ptr [r14 + 0x19], 0\n"
        "jne .L_70f0_71cb\n"
        "lea r8, [r14 + 0x20]\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call rva_9190\n"
        "test al, al\n"
        "jne .L_70f0_71cb\n"
        "mov qword ptr [r15], r14\n"
        "mov byte ptr [r15 + 8], al\n"
        "jmp .L_70f0_7290\n"
        ".L_70f0_71cb:\n"
        "movabs rax, 0x276276276276276\n"
        "cmp qword ptr [r12 + 8], rax\n"
        "je .L_70f0_72ab\n"
        "mov qword ptr [rsp + 0x20], r12\n"
        "apw_xor32_load reg_ebp, reg_ebp\n"
        "mov qword ptr [rsp + 0x28], rbp\n"
        "lea ecx, [rbp + 0x68]\n"
        "call rva_34f86\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "mov qword ptr [rsp + 0x28], rax\n"
        "lea rbx, [rax + 0x20]\n"
        "mov qword ptr [rsp + 0x90], rbx\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_8630\n"
        ".byte 0x90 # alignment NOP\n"
        "add rsi, 0x20\n"
        "add rbx, 0x20\n"
        "mov qword ptr [rsp + 0xa0], rbx\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbx], xmm0\n"
        "mov qword ptr [rbx + 0x10], rbp\n"
        "mov qword ptr [rbx + 0x18], 0xf\n"
        "mov byte ptr [rbx], bpl\n"
        "apw_cmp64_load reg_rbx, reg_rsi\n"
        "je .L_70f0_7257\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "cmp qword ptr [rsi + 0x18], 0x10\n"
        "jb .L_70f0_724b\n"
        "mov rdx, qword ptr [rsi]\n"
        ".L_70f0_724b:\n"
        "mov r8, qword ptr [rsi + 0x10]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_1d350\n"
        ".L_70f0_7257:\n"
        "mov eax, dword ptr [rsi + 0x20]\n"
        "mov dword ptr [rbx + 0x20], eax\n"
        "mov qword ptr [rdi], r13\n"
        "mov qword ptr [rdi + 8], r13\n"
        "mov qword ptr [rdi + 0x10], r13\n"
        "mov word ptr [rdi + 0x18], 0\n"
        "movups xmm0, xmmword ptr [rsp + 0x30]\n"
        "movaps xmmword ptr [rsp + 0x20], xmm0\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call rva_1cd40\n"
        "mov qword ptr [r15], rax\n"
        "mov byte ptr [r15 + 8], 1\n"
        ".L_70f0_7290:\n"
        "apw_mov64_load reg_rax, reg_r15\n"
        "mov rbx, qword ptr [rsp + 0x98]\n"
        "add rsp, 0x50\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".L_70f0_72ab:\n"
        "call rva_1d100\n"
        "int3\n"
        END);
}

/* body 0x78e0 until 0x7a5f */
BODY void apw_78e0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "sub rsp, 0x20\n"
        "mov r13, qword ptr [rcx]\n"
        "lea rbp, [r8 + 0x18]\n"
        "apw_mov64_load reg_r14, reg_r8\n"
        "mov qword ptr [rsp + 0x60], r13\n"
        "apw_mov64_load reg_r15, reg_rdx\n"
        "lea rax, [r8 + 0x10]\n"
        "apw_mov64_load reg_r12, reg_r13\n"
        "mov rdi, qword ptr [r13 + 8]\n"
        "apw_mov64_load reg_rbx, reg_rdi\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "jne .L_78e0_79dc\n"
        "mov r15, qword ptr [rax]\n"
        ".byte 0x66,0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_78e0_7930:\n"
        "cmp qword ptr [r14 + 0x18], 0x10\n"
        "lea rsi, [rbx + 0x20]\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "jb .L_78e0_7941\n"
        "mov rdx, qword ptr [r14]\n"
        ".L_78e0_7941:\n"
        "mov r13, qword ptr [rsi + 0x18]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "cmp r13, 0x10\n"
        "jb .L_78e0_7951\n"
        "mov rcx, qword ptr [rsi]\n"
        ".L_78e0_7951:\n"
        "mov rbp, qword ptr [rbx + 0x30]\n"
        "apw_cmp64_load reg_r15, reg_rbp\n"
        "apw_mov64_load reg_r8, reg_rbp\n"
        "cmovb r8, r15\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "je .L_78e0_79a2\n"
        "js .L_78e0_79a7\n"
        ".L_78e0_796a:\n"
        "cmp byte ptr [r12 + 0x19], 0\n"
        "je .L_78e0_79ba\n"
        "cmp r13, 0x10\n"
        "jb .L_78e0_797b\n"
        "mov rsi, qword ptr [rsi]\n"
        ".L_78e0_797b:\n"
        "cmp qword ptr [r14 + 0x18], 0x10\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "jb .L_78e0_7988\n"
        "mov rcx, qword ptr [r14]\n"
        ".L_78e0_7988:\n"
        "apw_cmp64_load reg_rbp, reg_r15\n"
        "apw_mov64_load reg_r8, reg_r15\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "cmovb r8, rbp\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "je .L_78e0_79b2\n"
        "jns .L_78e0_79ba\n"
        "jmp .L_78e0_79b7\n"
        ".L_78e0_79a2:\n"
        "apw_cmp64_load reg_rbp, reg_r15\n"
        "jae .L_78e0_796a\n"
        ".L_78e0_79a7:\n"
        "mov rbx, qword ptr [rbx + 0x10]\n"
        "mov r13, qword ptr [rsp + 0x60]\n"
        "jmp .L_78e0_79c5\n"
        ".L_78e0_79b2:\n"
        "apw_cmp64_load reg_r15, reg_rbp\n"
        "jae .L_78e0_79ba\n"
        ".L_78e0_79b7:\n"
        "apw_mov64_load reg_r12, reg_rbx\n"
        ".L_78e0_79ba:\n"
        "apw_mov64_load reg_r13, reg_rbx\n"
        "mov qword ptr [rsp + 0x60], rbx\n"
        "mov rbx, qword ptr [rbx]\n"
        ".L_78e0_79c5:\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "je .L_78e0_7930\n"
        "mov r15, qword ptr [rsp + 0x68]\n"
        "lea rbp, [r14 + 0x18]\n"
        "lea rax, [r14 + 0x10]\n"
        ".L_78e0_79dc:\n"
        "cmp byte ptr [r12 + 0x19], 0\n"
        "jne .L_78e0_79e8\n"
        "mov rdi, qword ptr [r12]\n"
        ".L_78e0_79e8:\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "jne .L_78e0_7a33\n"
        "mov rbp, qword ptr [rbp]\n"
        "mov rsi, qword ptr [rax]\n"
        ".L_78e0_79f5:\n"
        "cmp qword ptr [rdi + 0x38], 0x10\n"
        "lea rdx, [rdi + 0x20]\n"
        "jb .L_78e0_7a04\n"
        "mov rdx, qword ptr [rdi + 0x20]\n"
        ".L_78e0_7a04:\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "cmp rbp, 0x10\n"
        "jb .L_78e0_7a10\n"
        "mov rcx, qword ptr [r14]\n"
        ".L_78e0_7a10:\n"
        "mov rbx, qword ptr [rdi + 0x30]\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_cmp64_load reg_rbx, reg_rsi\n"
        "cmovb r8, rbx\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "je .L_78e0_7a52\n"
        "js .L_78e0_7a57\n"
        ".L_78e0_7a29:\n"
        "mov rdi, qword ptr [rdi + 0x10]\n"
        ".L_78e0_7a2d:\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "je .L_78e0_79f5\n"
        ".L_78e0_7a33:\n"
        "mov rbx, qword ptr [rsp + 0x70]\n"
        "apw_mov64_load reg_rax, reg_r15\n"
        "mov qword ptr [r15], r13\n"
        "mov qword ptr [r15 + 8], r12\n"
        "add rsp, 0x20\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".L_78e0_7a52:\n"
        "apw_cmp64_load reg_rsi, reg_rbx\n"
        "jae .L_78e0_7a29\n"
        ".L_78e0_7a57:\n"
        "apw_mov64_load reg_r12, reg_rdi\n"
        "mov rdi, qword ptr [rdi]\n"
        "jmp .L_78e0_7a2d\n"
        END);
}

/* body 0x7a60 until 0x7ad6 */
BODY void apw_7a60(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rbp\n"
        "push rsi\n"
        "sub rsp, 0x20\n"
        "cmp byte ptr [r8 + 0x19], 0\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_rbp, reg_rcx\n"
        "jne .L_7a60_7ac6\n"
        "mov qword ptr [rsp + 0x30], rdi\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_7a60_7a90:\n"
        "mov r8, qword ptr [rbx + 0x10]\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "call rva_7a60\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        "mov rbx, qword ptr [rbx]\n"
        "lea rcx, [rdi + 0x20]\n"
        "call rva_8b00\n"
        "mov edx, 0x68\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "je .L_7a60_7a90\n"
        "mov rdi, qword ptr [rsp + 0x30]\n"
        ".L_7a60_7ac6:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rsi\n"
        "ret\n"
        END);
}

/* body 0x7ba0 until 0x7c55 */
BODY void apw_7ba0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "push rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_r14, reg_r8\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "mov dword ptr [rdx + 8], 0\n"
        "mov qword ptr [rdx + 0x10], rax\n"
        "mov rbx, qword ptr [rax + 8]\n"
        "mov qword ptr [rdx], rbx\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "jne .L_7ba0_7c3c\n"
        "mov qword ptr [rsp + 0x40], rbp\n"
        "mov rbp, qword ptr [r8 + 0x10]\n"
        "mov qword ptr [rsp + 0x48], rsi\n"
        "mov qword ptr [rsp + 0x50], r15\n"
        "mov r15, qword ptr [r8 + 0x18]\n"
        ".L_7ba0_7be1:\n"
        "mov qword ptr [rdi], rbx\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "cmp r15, 0x10\n"
        "jb .L_7ba0_7bf0\n"
        "mov rdx, qword ptr [r14]\n"
        ".L_7ba0_7bf0:\n"
        "cmp qword ptr [rbx + 0x38], 0x10\n"
        "lea rcx, [rbx + 0x20]\n"
        "jb .L_7ba0_7bff\n"
        "mov rcx, qword ptr [rbx + 0x20]\n"
        ".L_7ba0_7bff:\n"
        "mov rsi, qword ptr [rbx + 0x30]\n"
        "apw_cmp64_load reg_rbp, reg_rsi\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "cmovb r8, rbp\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "je .L_7ba0_7c48\n"
        "js .L_7ba0_7c4d\n"
        ".L_7ba0_7c18:\n"
        "mov qword ptr [rdi + 0x10], rbx\n"
        "mov eax, 1\n"
        "mov rbx, qword ptr [rbx]\n"
        ".L_7ba0_7c24:\n"
        "mov dword ptr [rdi + 8], eax\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "je .L_7ba0_7be1\n"
        "mov r15, qword ptr [rsp + 0x50]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        ".L_7ba0_7c3c:\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rbx\n"
        "ret\n"
        ".L_7ba0_7c48:\n"
        "apw_cmp64_load reg_rsi, reg_rbp\n"
        "jae .L_7ba0_7c18\n"
        ".L_7ba0_7c4d:\n"
        "mov rbx, qword ptr [rbx + 0x10]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "jmp .L_7ba0_7c24\n"
        END);
}

/* body 0x8120 until 0x81bc */
BODY void apw_8120(void) {
    __asm__(INTEL
        "apw_mov64_load reg_rax, reg_r8\n"
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "je .L_8120_81bb\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "lea r8, [rcx + 0x38]\n"
        "apw_sub64_load reg_r9, reg_rcx\n"
        "apw_xor32_load reg_r10d, reg_r10d\n"
        ".byte 0xf,0x1f,0x80,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_8120_8140:\n"
        "xorps xmm0, xmm0\n"
        "lea r8, [r8 + 0x40]\n"
        "movups xmmword ptr [rax], xmm0\n"
        "mov qword ptr [r9 + r8 - 0x68], r10\n"
        "lea rcx, [r8 - 0x38]\n"
        "mov qword ptr [r9 + r8 - 0x60], r10\n"
        "movups xmm0, xmmword ptr [r8 - 0x78]\n"
        "movups xmmword ptr [rax], xmm0\n"
        "movups xmm1, xmmword ptr [r8 - 0x68]\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rax + 0x10], xmm1\n"
        "mov qword ptr [r8 - 0x68], r10\n"
        "add rax, 0x40\n"
        "mov qword ptr [r8 - 0x60], 0xf\n"
        "mov byte ptr [r8 - 0x78], r10b\n"
        "movups xmmword ptr [r9 + r8 - 0x58], xmm0\n"
        "mov qword ptr [r9 + r8 - 0x48], r10\n"
        "mov qword ptr [r8 + r9 - 0x40], r10\n"
        "movups xmm0, xmmword ptr [r8 - 0x58]\n"
        "movups xmmword ptr [r9 + r8 - 0x58], xmm0\n"
        "movups xmm1, xmmword ptr [r8 - 0x48]\n"
        "movups xmmword ptr [r9 + r8 - 0x48], xmm1\n"
        "mov qword ptr [r8 - 0x48], r10\n"
        "mov qword ptr [r8 - 0x40], 0xf\n"
        "mov byte ptr [r8 - 0x58], r10b\n"
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "jne .L_8120_8140\n"
        ".L_8120_81bb:\n"
        "ret\n"
        END);
}

/* body 0x81c0 until 0x8239 */
BODY void apw_81c0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "je .L_81c0_8222\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "lea r8, [rcx + 0x18]\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "apw_xor32_load reg_r10d, reg_r10d\n"
        ".byte 0xf,0x1f,0x44,0x0,0x0 # alignment NOP\n"
        ".L_81c0_81e0:\n"
        "xorps xmm0, xmm0\n"
        "lea r8, [r8 + 0x20]\n"
        "movups xmmword ptr [rbx], xmm0\n"
        "mov qword ptr [rax + r8 - 0x28], r10\n"
        "lea rcx, [r8 - 0x18]\n"
        "mov qword ptr [r8 + rax - 0x20], r10\n"
        "movups xmm0, xmmword ptr [r8 - 0x38]\n"
        "movups xmmword ptr [rbx], xmm0\n"
        "movups xmm1, xmmword ptr [r8 - 0x28]\n"
        "movups xmmword ptr [rbx + 0x10], xmm1\n"
        "mov qword ptr [r8 - 0x28], r10\n"
        "add rbx, 0x20\n"
        "mov qword ptr [r8 - 0x20], 0xf\n"
        "mov byte ptr [r8 - 0x38], r10b\n"
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "jne .L_81c0_81e0\n"
        ".L_81c0_8222:\n"
        "apw_mov64_load reg_r8, reg_r9\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_7060\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x8240 until 0x834d */
BODY void apw_8240(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rbp\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "push r14\n"
        "push r15\n"
        "sub rsp, 0x70\n"
        "apw_mov64_load reg_rbp, reg_r8\n"
        "apw_mov64_load reg_r14, reg_rdx\n"
        "apw_mov64_load reg_r15, reg_rcx\n"
        "lea rdx, [rsp + 0x50]\n"
        "call rva_7ba0\n"
        "movups xmm0, xmmword ptr [rax]\n"
        "movups xmmword ptr [rsp + 0x40], xmm0\n"
        "movsd xmm0, qword ptr [rax + 0x10]\n"
        "movsd qword ptr [rsp + 0x30], xmm0\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "cmp byte ptr [rbx + 0x19], 0\n"
        "jne .L_8240_82a0\n"
        "lea r8, [rbx + 0x20]\n"
        "apw_mov64_load reg_rdx, reg_rbp\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call rva_9190\n"
        "test al, al\n"
        "je .L_8240_8323\n"
        ".L_8240_82a0:\n"
        "movabs rax, 0x333333333333333\n"
        "cmp qword ptr [r15 + 8], rax\n"
        "je .L_8240_8347\n"
        "mov rsi, qword ptr [r15]\n"
        "mov qword ptr [rsp + 0x20], r15\n"
        "mov qword ptr [rsp + 0x28], 0\n"
        "mov ecx, 0x50\n"
        "call rva_34f86\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "mov qword ptr [rsp + 0x28], rax\n"
        "apw_mov64_load reg_rdx, reg_rbp\n"
        "lea rcx, [rax + 0x20]\n"
        "call rva_8630\n"
        "mov rcx, qword ptr [rbp + 0x20]\n"
        "mov qword ptr [rdi + 0x40], rcx\n"
        "mov rcx, qword ptr [rbp + 0x28]\n"
        "mov qword ptr [rdi + 0x48], rcx\n"
        "mov qword ptr [rdi], rsi\n"
        "mov qword ptr [rdi + 8], rsi\n"
        "mov qword ptr [rdi + 0x10], rsi\n"
        "mov word ptr [rdi + 0x18], 0\n"
        "movups xmm0, xmmword ptr [rsp + 0x40]\n"
        "movaps xmmword ptr [rsp + 0x40], xmm0\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "lea rdx, [rsp + 0x40]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call rva_1cd40\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "mov al, 1\n"
        ".L_8240_8323:\n"
        "mov qword ptr [r14], rbx\n"
        "mov byte ptr [r14 + 8], al\n"
        "apw_mov64_load reg_rax, reg_r14\n"
        "lea r11, [rsp + 0x70]\n"
        "mov rbx, qword ptr [r11 + 0x20]\n"
        "mov rbp, qword ptr [r11 + 0x28]\n"
        "mov rsi, qword ptr [r11 + 0x30]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop r15\n"
        "pop r14\n"
        "pop rdi\n"
        "ret\n"
        ".L_8240_8347:\n"
        "call rva_1d100\n"
        "int3\n"
        END);
}

/* body 0x8840 until 0x887c */
BODY void apw_8840(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "xorps xmm0, xmm0\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rax + 8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "lea rax, [rip + rva_41388]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x8880 until 0x88bc */
BODY void apw_8880(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "xorps xmm0, xmm0\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rax + 8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "lea rax, [rip + rva_413a0]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x88c0 until 0x88e1 */
BODY void apw_88c0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_413b0]\n"
        "mov qword ptr [rcx + 0x10], 0\n"
        "mov qword ptr [rcx + 8], rax\n"
        "lea rax, [rip + rva_413a0]\n"
        "mov qword ptr [rcx], rax\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "ret\n"
        END);
}

/* body 0x88f0 until 0x892c */
BODY void apw_88f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "xorps xmm0, xmm0\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rax + 8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "lea rax, [rip + rva_415f8]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x8930 until 0x8951 */
BODY void apw_8930(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_41608]\n"
        "mov qword ptr [rcx + 0x10], 0\n"
        "mov qword ptr [rcx + 8], rax\n"
        "lea rax, [rip + rva_415f8]\n"
        "mov qword ptr [rcx], rax\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "ret\n"
        END);
}

/* body 0x8960 until 0x8992 */
BODY void apw_8960(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "xorps xmm0, xmm0\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rax + 8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x8a20 until 0x8a83 */
BODY void apw_8a20(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "lea rax, [rip + rva_41b18]\n"
        "mov qword ptr [rcx], rax\n"
        "cmp qword ptr [rcx + 0x80], 0\n"
        "je .L_8a20_8a66\n"
        "call qword ptr [rip + rva_3a450]\n"
        "lea rdx, [rbx + 0x70]\n"
        "apw_cmp64_load reg_rax, reg_rdx\n"
        "jne .L_8a20_8a66\n"
        "mov rdx, qword ptr [rbx + 0x88]\n"
        "mov r9, qword ptr [rbx + 0x90]\n"
        "apw_mov64_load reg_r8, reg_rdx\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a428]\n"
        ".L_8a20_8a66:\n"
        "cmp byte ptr [rbx + 0x7c], 0\n"
        "je .L_8a20_8a74\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_1d4c0\n"
        ".L_8a20_8a74:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a460]\n"
        END);
}

/* body 0x8ee0 until 0x8f20 */
BODY void apw_8ee0(void) {
    __asm__(INTEL
        "sub rsp, 0x258\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x240], rax\n"
        "call rva_34f9e\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "call rva_34faa\n"
        ".byte 0x90 # alignment NOP\n"
        "mov rcx, qword ptr [rsp + 0x240]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x258\n"
        "ret\n"
        END);
}

/* body 0x8f40 until 0x8f45 */
BODY void apw_8f40(void) {
    __asm__(INTEL
        "jmp rva_1ccd0\n"
        END);
}

/* body 0x8f50 until 0x8f7f */
BODY void apw_8f50(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "mov r8, qword ptr [rcx + 8]\n"
        "lea rbx, [rcx + 8]\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov r8, qword ptr [r8 + 8]\n"
        "call rva_7a60\n"
        "mov rcx, qword ptr [rbx]\n"
        "mov edx, 0x68\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "jmp rva_35134\n"
        END);
}

/* body 0x9190 until 0x91fd */
BODY void apw_9190(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [r8 + 0x18], 0x10\n"
        "apw_mov64_load reg_rax, reg_r8\n"
        "jb .L_9190_91a7\n"
        "mov rax, qword ptr [r8]\n"
        ".L_9190_91a7:\n"
        "cmp qword ptr [rdx + 0x18], 0x10\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "jb .L_9190_91b4\n"
        "mov rcx, qword ptr [rdx]\n"
        ".L_9190_91b4:\n"
        "mov rdi, qword ptr [r8 + 0x10]\n"
        "mov rbx, qword ptr [rdx + 0x10]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_cmp64_load reg_rdi, reg_rbx\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "cmovb r8, rdi\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "jne .L_9190_91ef\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "jae .L_9190_91e7\n"
        "mov eax, 1\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        ".L_9190_91e7:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "seta al\n"
        ".L_9190_91ef:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "shr eax, 0x1f\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x9200 until 0x9261 */
BODY void apw_9200(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [rcx]\n"
        "lea rbx, [rcx + 0xb0]\n"
        "movsxd rdx, dword ptr [rax + 4]\n"
        "lea rax, [rip + rva_41b98]\n"
        "mov qword ptr [rdx + rbx - 0xb0], rax\n"
        "mov rax, qword ptr [rcx]\n"
        "lea rcx, [rbx - 0xa0]\n"
        "movsxd rdx, dword ptr [rax + 4]\n"
        "lea r8d, [rdx - 0xb0]\n"
        "mov dword ptr [rdx + rbx - 0xb4], r8d\n"
        "call rva_8a20\n"
        "lea rcx, [rbx - 0x98]\n"
        "call qword ptr [rip + rva_3a3a8]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a3c8]\n"
        END);
}

/* body 0x9264 until 0x9270 */
BODY void apw_9264(void) {
    __asm__(INTEL
        "movsxd rax, dword ptr [rcx - 4]\n"
        "apw_sub64_load reg_rcx, reg_rax\n"
        "jmp rva_92b0\n"
        END);
}

/* body 0x9270 until 0x92a4 */
BODY void apw_9270(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov32_load reg_ebx, reg_edx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "call rva_8a20\n"
        "test bl, 1\n"
        "je .L_9270_9296\n"
        "mov edx, 0x98\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        ".L_9270_9296:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x92b0 until 0x92eb */
BODY void apw_92b0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "lea rdi, [rcx - 0xb0]\n"
        "apw_mov32_load reg_ebx, reg_edx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_9200\n"
        "test bl, 1\n"
        "je .L_92b0_92dd\n"
        "mov edx, 0x110\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        ".L_92b0_92dd:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x92f0 until 0x9332 */
BODY void apw_92f0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "lea rax, [rip + rva_41358]\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "mov qword ptr [rcx], rax\n"
        "apw_mov32_load reg_ebx, reg_edx\n"
        "add rcx, 8\n"
        "call rva_362bc\n"
        "test bl, 1\n"
        "je .L_92f0_9324\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        ".L_92f0_9324:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x9360 until 0x93be */
BODY void apw_9360(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call qword ptr [rip + rva_53140]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "lea rcx, [rbx + 0x60]\n"
        "cmp qword ptr [rcx + 0x18], 0x10\n"
        "jb .L_9360_9397\n"
        "mov rcx, qword ptr [rcx]\n"
        ".L_9360_9397:\n"
        "mov rdx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_532d8]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_bfd0\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov al, 1\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x99b0 until 0x9be9 */
BODY void apw_99b0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x18], rdi\n"
        "push rbp\n"
        "lea rbp, [rsp - 0x1a0]\n"
        "sub rsp, 0x2a0\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x190], rax\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "mov qword ptr [rsp + 0x38], rdx\n"
        "mov dl, 0x2e\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_r8d, reg_eax\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        "mov r8d, 0x104\n"
        "mov rdx, qword ptr [rax]\n"
        "lea rcx, [rbp + 0x80]\n"
        "call qword ptr [rip + rva_3a8c0]\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov r8d, 0x104\n"
        "lea rdx, [rip + rva_41680]\n"
        "lea rcx, [rbp + 0x80]\n"
        "call qword ptr [rip + rva_3a8d0]\n"
        "mov byte ptr [rbp + 0x184], 0\n"
        "mov dl, 0x5c\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "lea ebx, [rax + 1]\n"
        "apw_mov32_load reg_r8d, reg_ebx\n"
        "lea rdx, [rsp + 0x30]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rip + rva_41614]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aa98]\n"
        "apw_mov32_load reg_r8d, reg_ebx\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa50]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov dl, 0x2e\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_r8d, reg_eax\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "lea rdx, [rsp + 0x40]\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a330]\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "cmp rax, -1\n"
        "je .L_99b0_9b7d\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_99b0_9af0:\n"
        "lea rdx, [rsp + 0x6c]\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov dl, 0x2e\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_r8d, reg_eax\n"
        "lea rdx, [rsp + 0x20]\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov rdx, qword ptr [rdi]\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aa80]\n"
        "test eax, eax\n"
        "jne .L_99b0_9b3f\n"
        "mov rcx, qword ptr [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3a278]\n"
        ".L_99b0_9b3f:\n"
        "lea rdx, [rsp + 0x40]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a338]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x20]\n"
        "test eax, eax\n"
        "je .L_99b0_9b6b\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "jmp .L_99b0_9af0\n"
        ".L_99b0_9b6b:\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_99b0_9b7d:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a328]\n"
        "call qword ptr [rip + rva_53158]\n"
        "test rax, rax\n"
        "je .L_99b0_9bb0\n"
        "call qword ptr [rip + rva_53158]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_53160]\n"
        "mov dl, 1\n"
        "lea rcx, [rbp + 0x80]\n"
        "call qword ptr [rip + rva_532d0]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_99b0_9bb0:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rcx, qword ptr [rbp + 0x190]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x2a0]\n"
        "mov rbx, qword ptr [r11 + 0x10]\n"
        "mov rdi, qword ptr [r11 + 0x20]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x9bf0 until 0xa4de */
BODY void apw_9bf0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "lea rbp, [rsp - 0x720]\n"
        "sub rsp, 0x820\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x710], rax\n"
        "apw_mov64_load reg_r14, reg_r9\n"
        "apw_mov32_load reg_edi, reg_r8d\n"
        "apw_mov32_load reg_esi, reg_edx\n"
        "mov qword ptr [rbp - 0x78], rcx\n"
        "mov r13, qword ptr [rbp + 0x780]\n"
        "cmp dword ptr [rcx + 0xc4], 0\n"
        "jne .L_9bf0_a142\n"
        "mov dword ptr [rcx + 0xc4], 1\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_53300]\n"
        "lea r15, [rip + rva_3ad3b]\n"
        "apw_mov64_load reg_r12, reg_r15\n"
        "mov ecx, dword ptr [rip + rva_54218]\n"
        "mov rax, qword ptr gs:[0x58]\n"
        "mov edx, 4\n"
        "mov rbx, qword ptr [rax + rcx*8]\n"
        "apw_add64_load reg_rbx, reg_rdx\n"
        "mov eax, dword ptr [rbx]\n"
        "cmp dword ptr [rip + rva_53558], eax\n"
        "jg .L_9bf0_a466\n"
        ".L_9bf0_9c85:\n"
        "mov eax, dword ptr [rbx]\n"
        "cmp dword ptr [rip + rva_53568], eax\n"
        "jg .L_9bf0_a4a2\n"
        ".L_9bf0_9c93:\n"
        "mov eax, dword ptr [rbx]\n"
        "cmp dword ptr [rip + rva_53578], eax\n"
        "jg .L_9bf0_a42a\n"
        ".L_9bf0_9ca1:\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call qword ptr [rip + rva_3a950]\n"
        "mov byte ptr [rbp + 0x1c0], 0\n"
        "test edi, edi\n"
        "jne .L_9bf0_9d52\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_3a700]\n"
        "test eax, eax\n"
        "je .L_9bf0_9cea\n"
        "lea rdx, [rip + rva_41650]\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_3a860]\n"
        "test rax, rax\n"
        "je .L_9bf0_a142\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a7d8]\n"
        ".L_9bf0_9cea:\n"
        "mov r8d, 0x104\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "lea rcx, [rbp + 0x1c0]\n"
        "call qword ptr [rip + rva_3a8c0]\n"
        "mov edx, 0x2e\n"
        "lea rcx, [rbp + 0x1c0]\n"
        "call rva_362b0\n"
        "test rax, rax\n"
        "je .L_9bf0_9d1b\n"
        "mov byte ptr [rax], 0\n"
        "jmp .L_9bf0_9d22\n"
        ".L_9bf0_9d1b:\n"
        "mov byte ptr [rbp + 0x1c0], 0\n"
        ".L_9bf0_9d22:\n"
        "mov edx, 0x5c\n"
        "lea rcx, [rbp + 0x1c0]\n"
        "call rva_362b0\n"
        "test rax, rax\n"
        "jne .L_9bf0_9d44\n"
        "lea r15, [rbp + 0x1c0]\n"
        "apw_xor32_load reg_r12d, reg_r12d\n"
        "jmp .L_9bf0_9d52\n"
        ".L_9bf0_9d44:\n"
        "lea r15, [rax + 1]\n"
        "mov byte ptr [rax], 0\n"
        "lea r12, [rbp + 0x1c0]\n"
        ".L_9bf0_9d52:\n"
        "call rva_33bd0\n"
        "mov dword ptr [rsp + 0x20], 0x104\n"
        "lea r9, [rbp - 0x60]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_a16e\n"
        "lea r8, [rip + rva_41654]\n"
        "call qword ptr [rip + rva_53258]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rbp - 0x60]\n"
        "call qword ptr [rip + rva_3a700]\n"
        "test eax, eax\n"
        "jne .L_9bf0_a142\n"
        "mov dword ptr [rsp + 0x20], 0x104\n"
        "lea r9, [rbp + 0x2d0]\n"
        "lea r8, [rip + rva_41658]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_53258]\n"
        "lea r8, [rbp + 0x1c0]\n"
        "lea rdx, [rip + rva_41660]\n"
        "lea rcx, [rbp + 0x2d0]\n"
        "call rva_1ce0\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_532c8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8d, 0x104\n"
        "lea rcx, [rbp + 0x600]\n"
        "call qword ptr [rip + rva_3a8c0]\n"
        "test esi, esi\n"
        "jne .L_9bf0_a113\n"
        "mov rdx, qword ptr [rip + rva_53570]\n"
        "lea rcx, [rbp - 0x70]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "mov rdx, qword ptr [rip + rva_53560]\n"
        "lea rcx, [rsp + 0x68]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "mov rdx, qword ptr [rip + rva_53550]\n"
        "lea rcx, [rsp + 0x60]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "call rva_33be0\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x58]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov r9, qword ptr [rbx]\n"
        "test r9, r9\n"
        "je .L_9bf0_9e54\n"
        "mov r9, qword ptr [r9]\n"
        ".L_9bf0_9e54:\n"
        "mov rax, qword ptr [rdi]\n"
        "test rax, rax\n"
        "je .L_9bf0_9e61\n"
        "mov r8, qword ptr [rax]\n"
        "jmp .L_9bf0_9e64\n"
        ".L_9bf0_9e61:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        ".L_9bf0_9e64:\n"
        "mov rax, qword ptr [rsi]\n"
        "apw_xor32_load reg_esi, reg_esi\n"
        "test rax, rax\n"
        "je .L_9bf0_9e73\n"
        "mov rdx, qword ptr [rax]\n"
        "jmp .L_9bf0_9e76\n"
        ".L_9bf0_9e73:\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        ".L_9bf0_9e76:\n"
        "mov rax, qword ptr [rcx]\n"
        "test rax, rax\n"
        "je .L_9bf0_9e83\n"
        "mov rcx, qword ptr [rax]\n"
        "jmp .L_9bf0_9e86\n"
        ".L_9bf0_9e83:\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        ".L_9bf0_9e86:\n"
        "mov dword ptr [rsp + 0x48], esi\n"
        "mov dword ptr [rsp + 0x40], 0xffffffff\n"
        "mov dword ptr [rsp + 0x38], 2\n"
        "mov qword ptr [rsp + 0x30], rsi\n"
        "mov qword ptr [rsp + 0x28], rsi\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "call rva_10cc0\n"
        "apw_mov32_load reg_edi, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9f03\n"
        "mov ecx, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], ecx\n"
        "cmp ecx, 1\n"
        "jne .L_9bf0_9efe\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9efe\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9edf\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], rsi\n"
        ".L_9bf0_9edf:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9ef1\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], rsi\n"
        ".L_9bf0_9ef1:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_9efe:\n"
        "mov qword ptr [rsp + 0x58], rsi\n"
        ".L_9bf0_9f03:\n"
        "mov rbx, qword ptr [rsp + 0x60]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9f56\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_9f51\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9f51\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9f32\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], rsi\n"
        ".L_9bf0_9f32:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9f44\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], rsi\n"
        ".L_9bf0_9f44:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_9f51:\n"
        "mov qword ptr [rsp + 0x60], rsi\n"
        ".L_9bf0_9f56:\n"
        "mov rbx, qword ptr [rsp + 0x68]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9fa9\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_9fa4\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9fa4\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9f85\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], rsi\n"
        ".L_9bf0_9f85:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9f97\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], rsi\n"
        ".L_9bf0_9f97:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_9fa4:\n"
        "mov qword ptr [rsp + 0x68], rsi\n"
        ".L_9bf0_9fa9:\n"
        "mov rbx, qword ptr [rbp - 0x70]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9ff6\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_9ff6\n"
        "test rbx, rbx\n"
        "je .L_9bf0_9ff6\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9fd7\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], rsi\n"
        ".L_9bf0_9fd7:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_9fe9\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], rsi\n"
        ".L_9bf0_9fe9:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_9ff6:\n"
        "cmp edi, -1\n"
        "jne .L_9bf0_a014\n"
        "lea ecx, [rdi + 2]\n"
        "call qword ptr [rip + rva_53270]\n"
        "lea ecx, [rdi + 4]\n"
        "call qword ptr [rip + rva_53300]\n"
        "apw_mov32_load reg_eax, reg_edi\n"
        "jmp .L_9bf0_a144\n"
        ".L_9bf0_a014:\n"
        "cmp edi, 1\n"
        "je .L_9bf0_a113\n"
        "mov rax, qword ptr [rbp - 0x78]\n"
        "mov byte ptr [rax + 0xa8], 1\n"
        "mov dword ptr [rsp + 0x20], 0x104\n"
        "lea r9, [rbp + 0xb0]\n"
        "lea r8, [rip + rva_41670]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_53260]\n"
        "mov dword ptr [rsp + 0x20], 0x104\n"
        "lea r9, [rbp + 0x3e0]\n"
        "lea r8, [rip + rva_41678]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_53260]\n"
        "mov dword ptr [rsp + 0x20], 0x104\n"
        "lea r9, [rbp + 0x4f0]\n"
        "lea r8, [rip + rva_41680]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_53260]\n"
        "lea rcx, [rbp + 0xb0]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "lea rcx, [rbp + 0x3e0]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rbp + 0x4f0]\n"
        "call qword ptr [rip + rva_532d0]\n"
        "lea rdx, [rbp + 0xb0]\n"
        "lea rcx, [rbp - 0x60]\n"
        "call qword ptr [rip + rva_3a268]\n"
        "test eax, eax\n"
        "je .L_9bf0_a142\n"
        "lea rdx, [rbp - 0x60]\n"
        "lea rcx, [rbp + 0xb0]\n"
        "call qword ptr [rip + rva_532e8]\n"
        "lea rdx, [rbp + 0x3e0]\n"
        "lea rcx, [rbp + 0x2d0]\n"
        "call qword ptr [rip + rva_3a268]\n"
        "lea rdx, [rbp + 0xb0]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "mov ecx, 1\n"
        "call qword ptr [rip + rva_53300]\n"
        "mov eax, 1\n"
        "jmp .L_9bf0_a144\n"
        ".L_9bf0_a113:\n"
        "lea rcx, [rbp - 0x60]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "lea rcx, [rbp + 0x2d0]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "lea rdx, [rbp - 0x60]\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_532d8]\n"
        "mov ecx, 2\n"
        "call qword ptr [rip + rva_53300]\n"
        ".L_9bf0_a142:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_9bf0_a144:\n"
        "mov rcx, qword ptr [rbp + 0x710]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x868]\n"
        "add rsp, 0x820\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".L_9bf0_a16e:\n"
        "lea r8, [rip + rva_41688]\n"
        "call qword ptr [rip + rva_53258]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rbp - 0x60]\n"
        "call qword ptr [rip + rva_3a700]\n"
        "test eax, eax\n"
        "jne .L_9bf0_a142\n"
        "test esi, esi\n"
        "jne .L_9bf0_a3bd\n"
        "mov rdx, qword ptr [rip + rva_53570]\n"
        "lea rcx, [rbp - 0x68]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "mov rdx, qword ptr [rip + rva_53560]\n"
        "lea rcx, [rbp - 0x80]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "mov rdx, qword ptr [rip + rva_53550]\n"
        "lea rcx, [rsp + 0x78]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "call rva_33be0\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x70]\n"
        "call rva_87d0\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov r9, qword ptr [rbx]\n"
        "apw_xor32_load reg_r14d, reg_r14d\n"
        "test r9, r9\n"
        "je .L_9bf0_a1f2\n"
        "mov r9, qword ptr [r9]\n"
        "jmp .L_9bf0_a1f5\n"
        ".L_9bf0_a1f2:\n"
        "apw_mov64_load reg_r9, reg_r14\n"
        ".L_9bf0_a1f5:\n"
        "mov rax, qword ptr [rdi]\n"
        "test rax, rax\n"
        "je .L_9bf0_a202\n"
        "mov r8, qword ptr [rax]\n"
        "jmp .L_9bf0_a205\n"
        ".L_9bf0_a202:\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        ".L_9bf0_a205:\n"
        "mov rax, qword ptr [rsi]\n"
        "test rax, rax\n"
        "je .L_9bf0_a212\n"
        "mov rdx, qword ptr [rax]\n"
        "jmp .L_9bf0_a215\n"
        ".L_9bf0_a212:\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        ".L_9bf0_a215:\n"
        "mov rax, qword ptr [rcx]\n"
        "test rax, rax\n"
        "je .L_9bf0_a222\n"
        "mov rcx, qword ptr [rax]\n"
        "jmp .L_9bf0_a225\n"
        ".L_9bf0_a222:\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        ".L_9bf0_a225:\n"
        "mov dword ptr [rsp + 0x48], r14d\n"
        "mov dword ptr [rsp + 0x40], 0xffffffff\n"
        "mov dword ptr [rsp + 0x38], 2\n"
        "mov qword ptr [rsp + 0x30], r14\n"
        "mov qword ptr [rsp + 0x28], r14\n"
        "mov qword ptr [rsp + 0x20], r14\n"
        "call rva_10cc0\n"
        "apw_mov32_load reg_edi, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x70]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a2a3\n"
        "mov ecx, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], ecx\n"
        "cmp ecx, 1\n"
        "jne .L_9bf0_a29e\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a29e\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a27f\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], r14\n"
        ".L_9bf0_a27f:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a291\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], r14\n"
        ".L_9bf0_a291:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_a29e:\n"
        "mov qword ptr [rsp + 0x70], r14\n"
        ".L_9bf0_a2a3:\n"
        "mov rbx, qword ptr [rsp + 0x78]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a2f6\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_a2f1\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a2f1\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a2d2\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], r14\n"
        ".L_9bf0_a2d2:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a2e4\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], r14\n"
        ".L_9bf0_a2e4:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_a2f1:\n"
        "mov qword ptr [rsp + 0x78], r14\n"
        ".L_9bf0_a2f6:\n"
        "mov rbx, qword ptr [rbp - 0x80]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a347\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_a343\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a343\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a324\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], r14\n"
        ".L_9bf0_a324:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a336\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], r14\n"
        ".L_9bf0_a336:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_a343:\n"
        "mov qword ptr [rbp - 0x80], r14\n"
        ".L_9bf0_a347:\n"
        "mov rbx, qword ptr [rbp - 0x68]\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a394\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_9bf0_a394\n"
        "test rbx, rbx\n"
        "je .L_9bf0_a394\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a375\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], r14\n"
        ".L_9bf0_a375:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_9bf0_a387\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], r14\n"
        ".L_9bf0_a387:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_9bf0_a394:\n"
        "cmp edi, -1\n"
        "jne .L_9bf0_a3a9\n"
        "lea ecx, [rdi + 2]\n"
        "call qword ptr [rip + rva_53270]\n"
        "apw_mov32_load reg_eax, reg_edi\n"
        "jmp .L_9bf0_a144\n"
        ".L_9bf0_a3a9:\n"
        "cmp edi, 1\n"
        "jne .L_9bf0_a3bd\n"
        "lea rcx, [rbp - 0x60]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "jmp .L_9bf0_a142\n"
        ".L_9bf0_a3bd:\n"
        "mov rax, qword ptr [rbp - 0x78]\n"
        "mov byte ptr [rax + 0xa8], 1\n"
        "mov dword ptr [rsp + 0x20], 0x104\n"
        "lea r9, [rbp + 0xb0]\n"
        "lea r8, [rip + rva_41690]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_53260]\n"
        "lea rcx, [rbp + 0xb0]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "lea rdx, [rbp + 0xb0]\n"
        "lea rcx, [rbp - 0x60]\n"
        "call qword ptr [rip + rva_3a268]\n"
        "test eax, eax\n"
        "je .L_9bf0_a142\n"
        "lea rdx, [rbp + 0xb0]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "mov eax, 1\n"
        "jmp .L_9bf0_a144\n"
        ".L_9bf0_a42a:\n"
        "lea rcx, [rip + rva_53578]\n"
        "call rva_35090\n"
        "cmp dword ptr [rip + rva_53578], -1\n"
        "jne .L_9bf0_9ca1\n"
        "mov ecx, 0xa409\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "mov qword ptr [rip + rva_53570], rax\n"
        "lea rcx, [rip + rva_53578]\n"
        "call rva_35024\n"
        "jmp .L_9bf0_9ca1\n"
        ".L_9bf0_a466:\n"
        "lea rcx, [rip + rva_53558]\n"
        "call rva_35090\n"
        "cmp dword ptr [rip + rva_53558], -1\n"
        "jne .L_9bf0_9c85\n"
        "mov ecx, 0x569\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "mov qword ptr [rip + rva_53550], rax\n"
        "lea rcx, [rip + rva_53558]\n"
        "call rva_35024\n"
        "jmp .L_9bf0_9c85\n"
        ".L_9bf0_a4a2:\n"
        "lea rcx, [rip + rva_53568]\n"
        "call rva_35090\n"
        "cmp dword ptr [rip + rva_53568], -1\n"
        "jne .L_9bf0_9c93\n"
        "mov ecx, 0xa408\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "mov qword ptr [rip + rva_53560], rax\n"
        "lea rcx, [rip + rva_53568]\n"
        "call rva_35024\n"
        "jmp .L_9bf0_9c93\n"
        END);
}

/* body 0xab20 until 0xab49 */
BODY void apw_ab20(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41840]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "je .L_ab20_ab42\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_33dfc\n"
        ".L_ab20_ab42:\n"
        "mov al, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0xbe70 until 0xbf1a */
BODY void apw_be70(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov32_load reg_edi, reg_r8d\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea r9, [rsp + 0x58]\n"
        "apw_mov32_load reg_r8d, reg_edi\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_dad0\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "mov rcx, qword ptr [rsp + 0x58]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "je .L_be70_bef1\n"
        "lea rdx, [rip + rva_41aa0]\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aa88]\n"
        "test eax, eax\n"
        "je .L_be70_bef1\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "lea edx, [r9 + 0x30]\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rsp + 0x58]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_be70_bef1:\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov32_load reg_eax, reg_ebx\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0xbf20 until 0xbfcf */
BODY void apw_bf20(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x20], rbx\n"
        "push rdi\n"
        "sub rsp, 0x460\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x450], rax\n"
        "apw_mov64_load reg_r10, reg_rdx\n"
        "mov qword ptr [rsp + 0x38], rcx\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "lea rax, [rsp + 0x350]\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_mov64_load reg_rcx, reg_r10\n"
        "lea r9, [rsp + 0x40]\n"
        "lea r8, [rsp + 0x140]\n"
        "lea rdx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "lea r9, [rsp + 0x40]\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "lea r8, [rsp + 0x140]\n"
        "lea rdx, [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x240]\n"
        "call qword ptr [rip + rva_3a6d0]\n"
        "lea rdx, [rsp + 0x240]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aac0]\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "mov rcx, qword ptr [rsp + 0x450]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x488]\n"
        "add rsp, 0x460\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0xbfd0 until 0xc178 */
BODY void apw_bfd0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rdi\n"
        "sub rsp, 0x150\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x140], rax\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "lea rdx, [rsp + 0x30]\n"
        "mov ecx, 0x104\n"
        "call qword ptr [rip + rva_3a280]\n"
        "lea rdx, [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "call rva_33bd0\n"
        "lea rcx, [rsp + 0x28]\n"
        "cmp eax, 1\n"
        "lea rdx, [rip + rva_41948]\n"
        "je .L_bfd0_c030\n"
        "lea rdx, [rip + rva_41958]\n"
        ".L_bfd0_c030:\n"
        "call qword ptr [rip + rva_3aa98]\n"
        "call rva_33d00\n"
        "test rax, rax\n"
        "je .L_bfd0_c05e\n"
        "mov r8d, 0x104\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a8c0]\n"
        "mov byte ptr [rsp + 0x133], 0\n"
        "jmp .L_bfd0_c063\n"
        ".L_bfd0_c05e:\n"
        "mov byte ptr [rsp + 0x30], 0\n"
        ".L_bfd0_c063:\n"
        "mov rcx, qword ptr [rsp + 0x28]\n"
        "call rva_33dfc\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "cmp byte ptr [rsp + 0x30], 0\n"
        "je .L_bfd0_c087\n"
        "lea rdx, [rsp + 0x30]\n"
        "jmp .L_bfd0_c0a0\n"
        ".L_bfd0_c087:\n"
        "cmp qword ptr [rbx + 0x70], 0\n"
        "lea rdx, [rbx + 0x40]\n"
        "je .L_bfd0_c096\n"
        "lea rdx, [rbx + 0x60]\n"
        ".L_bfd0_c096:\n"
        "cmp qword ptr [rdx + 0x18], 0x10\n"
        "jb .L_bfd0_c0a0\n"
        "mov rdx, qword ptr [rdx]\n"
        ".L_bfd0_c0a0:\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "mov rcx, qword ptr [rsp + 0x20]\n"
        "call rva_33dfc\n"
        "call rva_33bd0\n"
        "lea rdi, [rip + rva_41978]\n"
        "lea rdx, [rip + rva_41968]\n"
        "cmp eax, 1\n"
        "cmovne rdx, rdi\n"
        "mov ecx, 0xb\n"
        "call rva_33dd8\n"
        "cmp eax, -1\n"
        "je .L_bfd0_c140\n"
        "add rbx, 0x60\n"
        "call rva_33bd0\n"
        "cmp eax, 1\n"
        "jne .L_bfd0_c0fb\n"
        "call qword ptr [rip + rva_53200]\n"
        "lea rcx, [rip + rva_41968]\n"
        "jmp .L_bfd0_c104\n"
        ".L_bfd0_c0fb:\n"
        "call qword ptr [rip + rva_53128]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        ".L_bfd0_c104:\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "call qword ptr [rip + rva_3a6e0]\n"
        "cmp qword ptr [rbx + 0x18], 0x10\n"
        "jb .L_bfd0_c117\n"
        "mov rbx, qword ptr [rbx]\n"
        ".L_bfd0_c117:\n"
        "call qword ptr [rip + rva_53140]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_532e0]\n"
        "call qword ptr [rip + rva_53120]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rip + rva_41988]\n"
        "call qword ptr [rip + rva_3a268]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_bfd0_c140:\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rcx, qword ptr [rsp + 0x140]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x168]\n"
        "add rsp, 0x150\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0xc750 until 0xc891 */
BODY void apw_c750(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x430\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x420], rax\n"
        "mov ecx, dword ptr [rip + rva_54218]\n"
        "mov rax, qword ptr gs:[0x58]\n"
        "mov edx, 4\n"
        "mov rax, qword ptr [rax + rcx*8]\n"
        "mov eax, dword ptr [rdx + rax]\n"
        "cmp dword ptr [rip + rva_53590], eax\n"
        "jg .L_c750_c859\n"
        ".L_c750_c79b:\n"
        "call rva_33bd0\n"
        "cmp eax, 2\n"
        "jne .L_c750_c82d\n"
        "call rva_1a20\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3aa28]\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "lea rcx, [rsp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "lea rsi, [rip + rva_53580]\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3ab88]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "test ebx, ebx\n"
        "je .L_c750_c828\n"
        "mov r9d, 0x171\n"
        "lea r8, [rip + rva_41618]\n"
        "lea rdx, [rip + rva_409a0]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_1ce0\n"
        "mov edx, 2\n"
        "lea r8d, [rdx - 1]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a5b0]\n"
        ".L_c750_c828:\n"
        "apw_mov64_load reg_rax, reg_rsi\n"
        "jmp .L_c750_c834\n"
        ".L_c750_c82d:\n"
        "lea rax, [rip + rva_53580]\n"
        ".L_c750_c834:\n"
        "mov rcx, qword ptr [rsp + 0x420]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x430]\n"
        "mov rbx, qword ptr [r11 + 0x10]\n"
        "mov rsi, qword ptr [r11 + 0x18]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop rdi\n"
        "ret\n"
        ".L_c750_c859:\n"
        "lea rcx, [rip + rva_53590]\n"
        "call rva_35090\n"
        "cmp dword ptr [rip + rva_53590], -1\n"
        "jne .L_c750_c79b\n"
        "movups xmm0, xmmword ptr [rip + rva_41fe0]\n"
        "movups xmmword ptr [rip + rva_53580], xmm0\n"
        "lea rcx, [rip + rva_53590]\n"
        "call rva_35024\n"
        "jmp .L_c750_c79b\n"
        END);
}

/* body 0xcaa0 until 0xcc04 */
BODY void apw_caa0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x18], r8\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "mov dword ptr [rdx], 0xffffffff\n"
        "mov rax, qword ptr [r8]\n"
        "mov ebx, dword ptr [rax - 0x10]\n"
        "mov dl, 0x7c\n"
        "apw_mov64_load reg_rcx, reg_r8\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_ebp, reg_eax\n"
        "lea ecx, [rbx - 2]\n"
        "apw_cmp32_load reg_eax, reg_ecx\n"
        "jne .L_caa0_cb2b\n"
        "mov r8d, 1\n"
        "lea rdx, [rsp + 0x58]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa40]\n"
        "mov rcx, qword ptr [rax]\n"
        "call qword ptr [rip + rva_3a6a0]\n"
        "mov dword ptr [rsi], eax\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov32_load reg_r8d, reg_ebp\n"
        "lea rdx, [rsp + 0x58]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_caa0_cb2b:\n"
        "mov dl, 0x3e\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "test eax, eax\n"
        "jle .L_caa0_cb64\n"
        "apw_mov32_load reg_r8d, reg_eax\n"
        "lea rdx, [rsp + 0x58]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_caa0_cb64:\n"
        "cmp dword ptr [rsi], -1\n"
        "jne .L_caa0_cb73\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_c180\n"
        "mov dword ptr [rsi], eax\n"
        ".L_caa0_cb73:\n"
        "lea rcx, [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea r8, [rsp + 0x48]\n"
        "mov edx, dword ptr [rsi]\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_eab0\n"
        "test eax, eax\n"
        "jne .L_caa0_cbe0\n"
        "mov rax, qword ptr [rsp + 0x48]\n"
        "cmp dword ptr [rax - 0x10], 0\n"
        "jne .L_caa0_cba8\n"
        "mov ecx, 0x572\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        ".L_caa0_cba8:\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "lea edx, [r9 + 0x40]\n"
        "lea r8d, [r9 - 1]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_xor8_load reg_al, reg_al\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".L_caa0_cbe0:\n"
        "lea rcx, [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov al, 1\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0xcc10 until 0xccd1 */
BODY void apw_cc10(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x50\n"
        "lea rbp, [rsp + 0x30]\n"
        "mov qword ptr [rbp + 0x30], rbx\n"
        "mov qword ptr [rbp + 0x38], rdi\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rbp\n"
        "mov qword ptr [rbp + 0x18], rax\n"
        "mov eax, dword ptr [rsp]\n"
        "sub rsp, 0x60\n"
        "lea rbx, [rsp + 0x30]\n"
        "mov eax, dword ptr [rbx]\n"
        "apw_xor32_load reg_edi, reg_edi\n"
        "test rbx, rbx\n"
        "je .L_cc10_cc73\n"
        "mov dword ptr [rsp + 0x28], 0x2f\n"
        "lea r9d, [rdi - 1]\n"
        "lea r8, [rip + rva_414d0]\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov word ptr [rbx], di\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a2d8]\n"
        "test eax, eax\n"
        "cmove rbx, rdi\n"
        "jmp .L_cc10_cc76\n"
        ".L_cc10_cc73:\n"
        "apw_mov64_load reg_rbx, reg_rdi\n"
        ".L_cc10_cc76:\n"
        "lea rdx, [rbp + 8]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3abf0]\n"
        "test eax, eax\n"
        "js .L_cc10_ccb5\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov qword ptr [rbp], rdi\n"
        "lea rax, [rbp]\n"
        "lea r9, [rip + rva_42b28]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea rcx, [rbp + 8]\n"
        "lea r8d, [rdx + 1]\n"
        "call qword ptr [rip + rva_3ab68]\n"
        "test eax, eax\n"
        "js .L_cc10_ccb5\n"
        "mov rax, qword ptr [rbp]\n"
        "jmp .L_cc10_ccb7\n"
        ".L_cc10_ccb5:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_cc10_ccb7:\n"
        "mov rcx, qword ptr [rbp + 0x18]\n"
        "apw_xor64_load reg_rcx, reg_rbp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rbp + 0x30]\n"
        "mov rdi, qword ptr [rbp + 0x38]\n"
        "lea rsp, [rbp + 0x20]\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0xcce0 until 0xcda1 */
BODY void apw_cce0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x50\n"
        "lea rbp, [rsp + 0x30]\n"
        "mov qword ptr [rbp + 0x30], rbx\n"
        "mov qword ptr [rbp + 0x38], rdi\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rbp\n"
        "mov qword ptr [rbp + 0x18], rax\n"
        "mov eax, dword ptr [rsp]\n"
        "sub rsp, 0x70\n"
        "lea rbx, [rsp + 0x30]\n"
        "mov eax, dword ptr [rbx]\n"
        "apw_xor32_load reg_edi, reg_edi\n"
        "test rbx, rbx\n"
        "je .L_cce0_cd43\n"
        "mov dword ptr [rsp + 0x28], 0x31\n"
        "lea r9d, [rdi - 1]\n"
        "lea r8, [rip + rva_41528]\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov word ptr [rbx], di\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a2d8]\n"
        "test eax, eax\n"
        "cmove rbx, rdi\n"
        "jmp .L_cce0_cd46\n"
        ".L_cce0_cd43:\n"
        "apw_mov64_load reg_rbx, reg_rdi\n"
        ".L_cce0_cd46:\n"
        "lea rdx, [rbp + 8]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3abf0]\n"
        "test eax, eax\n"
        "js .L_cce0_cd85\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov qword ptr [rbp], rdi\n"
        "lea rax, [rbp]\n"
        "lea r9, [rip + rva_42b28]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea rcx, [rbp + 8]\n"
        "lea r8d, [rdx + 1]\n"
        "call qword ptr [rip + rva_3ab68]\n"
        "test eax, eax\n"
        "js .L_cce0_cd85\n"
        "mov rax, qword ptr [rbp]\n"
        "jmp .L_cce0_cd87\n"
        ".L_cce0_cd85:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_cce0_cd87:\n"
        "mov rcx, qword ptr [rbp + 0x18]\n"
        "apw_xor64_load reg_rcx, reg_rbp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rbp + 0x30]\n"
        "mov rdi, qword ptr [rbp + 0x38]\n"
        "lea rsp, [rbp + 0x20]\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0xd4d0 until 0xd5a2 */
BODY void apw_d4d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x150\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x140], rax\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "mov qword ptr [rsp + 0x28], rdx\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "lea rdx, [rsp + 0x30]\n"
        "mov ecx, 0x104\n"
        "call qword ptr [rip + rva_3a280]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "mov edx, 2\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a700]\n"
        "test eax, eax\n"
        "jne .L_d4d0_d565\n"
        "mov edx, 0x104\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a960]\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_40a74]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a270]\n"
        "mov edx, 0xffffffff\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3ab48]\n"
        ".L_d4d0_d565:\n"
        "mov rcx, qword ptr [rbx]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "jne .L_d4d0_d586\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "lea edx, [r9 + 0x40]\n"
        "lea r8d, [r9 - 1]\n"
        "lea rcx, [rip + rva_41ce8]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_d4d0_d586:\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "mov rcx, qword ptr [rsp + 0x140]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x150\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x10820 until 0x109d5 */
BODY void apw_10820(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "sub rsp, 0x60\n"
        "lea rbp, [rsp + 0x40]\n"
        "mov qword ptr [rbp + 0x50], rbx\n"
        "mov qword ptr [rbp + 0x58], rsi\n"
        "mov qword ptr [rbp + 0x60], rdi\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rbp\n"
        "mov qword ptr [rbp + 0x18], rax\n"
        "apw_mov64_load reg_rsi, reg_r9\n"
        "apw_mov64_load reg_r14, reg_r8\n"
        "apw_mov64_load reg_r15, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_xor32_load reg_r12d, reg_r12d\n"
        "call rva_33bd0\n"
        "apw_mov32_load reg_r13d, reg_eax\n"
        "call rva_1520\n"
        "mov dword ptr [rbp + 8], eax\n"
        "call rva_1530\n"
        "lea rdx, [rbp + 0x10]\n"
        "mov dword ptr [rbp + 4], eax\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov qword ptr [rbp + 0x10], r12\n"
        "call qword ptr [rip + rva_3ac00]\n"
        "test eax, eax\n"
        "jne .L_10820_109ad\n"
        "mov rdx, qword ptr [rbp + 0x10]\n"
        "test rdx, rdx\n"
        "je .L_10820_109ad\n"
        "mov rax, 0xffffffffffffffff\n"
        ".L_10820_108a1:\n"
        "inc rax\n"
        "cmp word ptr [rdx + rax*2], r12w\n"
        "jne .L_10820_108a1\n"
        "lea r8d, [rax + 1]\n"
        "cmp r8d, 0x3fffffff\n"
        "jg .L_10820_10927\n"
        "cdqe\n"
        "lea rax, [rax*2 + 2]\n"
        "lea rcx, [rax + 0xf]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "ja .L_10820_108d5\n"
        "movabs rcx, 0xffffffffffffff0\n"
        ".L_10820_108d5:\n"
        "and rcx, 0xfffffffffffffff0\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "call rva_355d0\n"
        "apw_sub64_load reg_rsp, reg_rcx\n"
        "lea rdi, [rsp + 0x40]\n"
        "test rdi, rdi\n"
        "je .L_10820_10927\n"
        "lea eax, [r8 + r8]\n"
        "mov qword ptr [rsp + 0x38], r12\n"
        "mov qword ptr [rsp + 0x30], r12\n"
        "apw_mov64_load reg_r8, reg_rdx\n"
        "mov dword ptr [rsp + 0x28], eax\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r9d, 0xffffffff\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "mov byte ptr [rdi], r12b\n"
        "call qword ptr [rip + rva_3a2d0]\n"
        "mov rdx, qword ptr [rbp + 0x10]\n"
        "test eax, eax\n"
        "cmove rdi, r12\n"
        "jmp .L_10820_1092a\n"
        ".L_10820_10927:\n"
        "apw_mov64_load reg_rdi, reg_r12\n"
        ".L_10820_1092a:\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "call qword ptr [rip + rva_3ab60]\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "mov dword ptr [rbp], r12d\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "lea rcx, [rbp]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "call rva_14d0\n"
        "test eax, eax\n"
        "je .L_10820_10999\n"
        ".byte 0xf,0x1f,0x0 # alignment NOP\n"
        ".L_10820_10950:\n"
        "mov r8d, dword ptr [rsi]\n"
        "mov edx, dword ptr [r14]\n"
        "mov ecx, dword ptr [r15]\n"
        "call rva_1550\n"
        "call rva_1a20\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "call rva_18c0\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a880]\n"
        "test eax, eax\n"
        "je .L_10820_10993\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "lea rcx, [rbp]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "call rva_14d0\n"
        "test eax, eax\n"
        "jne .L_10820_10950\n"
        "jmp .L_10820_10999\n"
        ".L_10820_10993:\n"
        "mov r12d, 1\n"
        ".L_10820_10999:\n"
        "mov r8d, dword ptr [rbp + 4]\n"
        "apw_mov32_load reg_ecx, reg_r13d\n"
        "mov edx, dword ptr [rbp + 8]\n"
        "call rva_1550\n"
        "apw_mov32_load reg_eax, reg_r12d\n"
        "jmp .L_10820_109af\n"
        ".L_10820_109ad:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_10820_109af:\n"
        "mov rcx, qword ptr [rbp + 0x18]\n"
        "apw_xor64_load reg_rcx, reg_rbp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rbp + 0x50]\n"
        "mov rsi, qword ptr [rbp + 0x58]\n"
        "mov rdi, qword ptr [rbp + 0x60]\n"
        "lea rsp, [rbp + 0x20]\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x1a540 until 0x1a65c */
BODY void apw_1a540(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push rdi\n"
        "sub rsp, 0x490\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x480], rax\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call rva_33bd0\n"
        "cmp eax, 1\n"
        "jne .L_1a540_1a637\n"
        "lea rax, [rsp + 0x380]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rsp + 0x70]\n"
        "lea r8, [rsp + 0x170]\n"
        "lea rdx, [rsp + 0x30]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "lea rax, [rip + rva_41ae8]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rsp + 0x70]\n"
        "lea r8, [rsp + 0x170]\n"
        "lea rdx, [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x270]\n"
        "call qword ptr [rip + rva_3a6d0]\n"
        "lea rdx, [rsp + 0x270]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rsp + 0x40]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a6f8]\n"
        "cmp eax, -1\n"
        "je .L_1a540_1a62c\n"
        "cmp dword ptr [rsp + 0x54], 0\n"
        "je .L_1a540_1a62c\n"
        "lea rdx, [rip + rva_417b4]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a860]\n"
        "test rax, rax\n"
        "je .L_1a540_1a62c\n"
        "lea r9, [rip + rva_41c4c]\n"
        "apw_mov64_load reg_r8, reg_rax\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_1a980\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_1a540_1a62c:\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_1a540_1a637:\n"
        "mov rcx, qword ptr [rsp + 0x480]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x490]\n"
        "mov rbx, qword ptr [r11 + 0x10]\n"
        "mov rsi, qword ptr [r11 + 0x28]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1ac00 until 0x1ad3e */
BODY void apw_1ac00(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rdi\n"
        "sub rsp, 0x170\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x160], rax\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "movzx ebx, dl\n"
        "call qword ptr [rip + rva_53158]\n"
        "test rax, rax\n"
        "je .L_1ac00_1ad1d\n"
        "mov qword ptr [rsp + 0x180], rsi\n"
        "apw_xor32_load reg_esi, reg_esi\n"
        "mov qword ptr [rsp + 0x48], rsi\n"
        "call qword ptr [rip + rva_53158]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "test bl, bl\n"
        "je .L_1ac00_1ac65\n"
        "lea r9, [rsp + 0x48]\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea r8, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_53178]\n"
        "jmp .L_1ac00_1ac75\n"
        ".L_1ac00_1ac65:\n"
        "lea r8, [rsp + 0x48]\n"
        "lea rdx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_53170]\n"
        ".L_1ac00_1ac75:\n"
        "cmp dword ptr [rsp + 0x40], esi\n"
        "jne .L_1ac00_1acc4\n"
        "mov r8, qword ptr [rsp + 0x48]\n"
        "test r8, r8\n"
        "je .L_1ac00_1acd9\n"
        "mov qword ptr [rsp + 0x38], rsi\n"
        "lea rax, [rsp + 0x60]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov qword ptr [rsp + 0x30], rsi\n"
        "mov dword ptr [rsp + 0x28], 0x100\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9d, [rdx - 1]\n"
        "call qword ptr [rip + rva_3a2d0]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "lea rcx, [rsp + 0x60]\n"
        "lea edx, [r9 + 0x30]\n"
        "lea r8d, [r9 - 1]\n"
        "call rva_33f83\n"
        ".L_1ac00_1acc4:\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "test rcx, rcx\n"
        "je .L_1ac00_1acd9\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rsp + 0x48], rsi\n"
        ".L_1ac00_1acd9:\n"
        "mov qword ptr [rsp + 0x50], rsi\n"
        "call qword ptr [rip + rva_53158]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "lea r8, [rsp + 0x50]\n"
        "lea rdx, [rip + rva_53548]\n"
        "call qword ptr [rip + rva_53168]\n"
        "mov ecx, dword ptr [rip + rva_53548]\n"
        "call qword ptr [rip + rva_53150]\n"
        "mov rcx, qword ptr [rsp + 0x50]\n"
        "mov rsi, qword ptr [rsp + 0x180]\n"
        "test rcx, rcx\n"
        "je .L_1ac00_1ad1d\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        ".L_1ac00_1ad1d:\n"
        "mov rcx, qword ptr [rsp + 0x160]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x188]\n"
        "add rsp, 0x170\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1ad40 until 0x1b0ac */
BODY void apw_1ad40(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "sub rsp, 0x9c0\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x9b0], rax\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "mov qword ptr [rsp + 0x50], rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov qword ptr [rsp + 0x58], rcx\n"
        "apw_xor32_load reg_edi, reg_edi\n"
        "apw_mov32_load reg_r13d, reg_edi\n"
        "mov dword ptr [rsp + 0x30], edi\n"
        "call rva_33bd0\n"
        "cmp eax, 1\n"
        "jne .L_1ad40_1b07f\n"
        "mov qword ptr [rsp + 0x38], rdi\n"
        "mov dword ptr [rsp + 0x30], edi\n"
        "lea rdx, [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_53190]\n"
        "cmp dword ptr [rsp + 0x30], edi\n"
        "jle .L_1ad40_1b070\n"
        "lea rdx, [rip + rva_41c50]\n"
        "mov rcx, qword ptr [rip + rva_527e8]\n"
        "call qword ptr [rip + rva_3a860]\n"
        "apw_mov64_load reg_r15, reg_rax\n"
        "apw_xor8_load reg_r12b, reg_r12b\n"
        ".L_1ad40_1add0:\n"
        "cmp edi, dword ptr [rsp + 0x30]\n"
        "jge .L_1ad40_1b01f\n"
        "movsxd rcx, edi\n"
        "lea r14, [rcx*8]\n"
        "lea rdx, [rip + rva_417b4]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "mov rcx, qword ptr [r14 + rcx]\n"
        "call qword ptr [rip + rva_3a860]\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "test rax, rax\n"
        "jne .L_1ad40_1af17\n"
        "lea rax, [rsp + 0x3a0]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea edx, [rsi + 0x1c]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a570]\n"
        "test eax, eax\n"
        "js .L_1ad40_1b013\n"
        "lea rdx, [rip + rva_41c58]\n"
        "lea rcx, [rsp + 0x3a0]\n"
        "call qword ptr [rip + rva_3a598]\n"
        "mov rax, qword ptr [rsp + 0x38]\n"
        "mov rbx, qword ptr [r14 + rax]\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "lea r8, [rsp + 0x6b0]\n"
        "lea rdx, [rsp + 0x40]\n"
        "lea rcx, [rsp + 0x3a0]\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "lea rax, [rsp + 0x4b0]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rsp + 0x5b0]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "lea rax, [rsp + 0x4b0]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rsp + 0x5b0]\n"
        "lea r8, [rsp + 0x6b0]\n"
        "lea rdx, [rsp + 0x40]\n"
        "lea rcx, [rsp + 0x190]\n"
        "call qword ptr [rip + rva_3a6d0]\n"
        "lea rdx, [rsp + 0x190]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        "or r13d, 1\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3a700]\n"
        "test eax, eax\n"
        "jne .L_1ad40_1aefe\n"
        "lea rdx, [rip + rva_417b4]\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3a860]\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        ".L_1ad40_1aefe:\n"
        "lea rcx, [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "test rsi, rsi\n"
        "je .L_1ad40_1b013\n"
        ".L_1ad40_1af17:\n"
        "lea rax, [rsp + 0x2a0]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rsp + 0x7b0]\n"
        "lea r8, [rsp + 0x8b0]\n"
        "lea rdx, [rsp + 0x60]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "mov rcx, qword ptr [r14 + rcx]\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "lea rax, [rsp + 0x2a0]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rsp + 0x7b0]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rsp + 0x190]\n"
        "call qword ptr [rip + rva_3a6d0]\n"
        "mov r8d, 0xa\n"
        "lea rdx, [rsp + 0x80]\n"
        "apw_mov32_load reg_ecx, reg_edi\n"
        "call qword ptr [rip + rva_3a698]\n"
        "lea rax, [rsp + 0x80]\n"
        "dec rax\n"
        ".L_1ad40_1af91:\n"
        "lea rax, [rax + 1]\n"
        "cmp byte ptr [rax], 0\n"
        "jne .L_1ad40_1af91\n"
        "lea r8, [rsp + 0x2a0]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1ad40_1afb0:\n"
        "movzx ecx, byte ptr [r8 + rdx]\n"
        "mov byte ptr [rax + rdx], cl\n"
        "lea rdx, [rdx + 1]\n"
        "test cl, cl\n"
        "jne .L_1ad40_1afb0\n"
        "lea r8, [rsp + 0x80]\n"
        "lea rdx, [rip + rva_417a4]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call rva_1f210\n"
        "lea r8, [rsp + 0x190]\n"
        "lea rdx, [rip + rva_417a4]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call rva_1f210\n"
        "mov r12b, 1\n"
        "lea r9, [rsp + 0x80]\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "mov rsi, qword ptr [rsp + 0x50]\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_1a980\n"
        "inc edi\n"
        "jmp .L_1ad40_1add0\n"
        ".L_1ad40_1b013:\n"
        "mov rsi, qword ptr [rsp + 0x50]\n"
        "inc edi\n"
        "jmp .L_1ad40_1add0\n"
        ".L_1ad40_1b01f:\n"
        "test r12b, r12b\n"
        "je .L_1ad40_1b059\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rip + rva_3a7d8]\n"
        "lea rdx, [rip + rva_41c7c]\n"
        "mov rcx, qword ptr [rip + rva_527e8]\n"
        "call qword ptr [rip + rva_3a860]\n"
        "apw_mov64_load reg_r15, reg_rax\n"
        "mov r9, qword ptr [rip + rva_527e8]\n"
        "apw_mov64_load reg_r8, reg_rax\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_1a980\n"
        ".L_1ad40_1b059:\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rip + rva_3a7d8]\n"
        "mov rcx, qword ptr [rip + rva_527e8]\n"
        "call qword ptr [rip + rva_3a6c8]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_1ad40_1b070:\n"
        "mov edx, dword ptr [rsp + 0x30]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_53188]\n"
        ".L_1ad40_1b07f:\n"
        "mov rcx, qword ptr [rsp + 0x9b0]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x9c0]\n"
        "mov rbx, qword ptr [r11 + 0x30]\n"
        "mov rsi, qword ptr [r11 + 0x40]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1c5a0 until 0x1c5c3 */
BODY void apw_1c5a0(void) {
    __asm__(INTEL
        "mov r8, 0xffffffffffffffff\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1c5a0_1c5b0:\n"
        "inc r8\n"
        "cmp byte ptr [rdx + r8], 0\n"
        "jne .L_1c5a0_1c5b0\n"
        "add rcx, 0x40\n"
        "jmp rva_1d350\n"
        END);
}

/* body 0x1c760 until 0x1c8f6 */
BODY void apw_1c760(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rbp\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "mov rbx, qword ptr [rdx]\n"
        "apw_xor32_load reg_ebp, reg_ebp\n"
        "mov rdi, qword ptr [rdx + 8]\n"
        "apw_mov64_load reg_r14, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "je .L_1c760_1c7e4\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_1c760_1c790:\n"
        "mov rdx, qword ptr [rax + 0x10]\n"
        "inc rbp\n"
        "cmp byte ptr [rdx + 0x19], 0\n"
        "je .L_1c760_1c7bf\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c760_1c7ba\n"
        ".L_1c760_1c7a7:\n"
        "cmp rax, qword ptr [rcx + 0x10]\n"
        "jne .L_1c760_1c7ba\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "mov rcx, qword ptr [rcx + 8]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "je .L_1c760_1c7a7\n"
        ".L_1c760_1c7ba:\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "jmp .L_1c760_1c7df\n"
        ".L_1c760_1c7bf:\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "mov rdx, qword ptr [rdx]\n"
        "cmp byte ptr [rdx + 0x19], 0\n"
        "jne .L_1c760_1c7df\n"
        ".byte 0xf,0x1f,0x44,0x0,0x0 # alignment NOP\n"
        ".L_1c760_1c7d0:\n"
        "mov rcx, qword ptr [rdx]\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "apw_mov64_load reg_rdx, reg_rcx\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "je .L_1c760_1c7d0\n"
        ".L_1c760_1c7df:\n"
        "apw_cmp64_load reg_rax, reg_rdi\n"
        "jne .L_1c760_1c790\n"
        ".L_1c760_1c7e4:\n"
        "mov rsi, qword ptr [r14]\n"
        "cmp rbx, qword ptr [rsi]\n"
        "jne .L_1c760_1c819\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "je .L_1c760_1c819\n"
        "mov r8, qword ptr [rsi + 8]\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call rva_7ae0\n"
        "mov qword ptr [rsi + 8], rsi\n"
        "mov qword ptr [rsi], rsi\n"
        "mov qword ptr [rsi + 0x10], rsi\n"
        "mov qword ptr [r14 + 8], 0\n"
        "jmp .L_1c760_1c8d8\n"
        ".L_1c760_1c819:\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "je .L_1c760_1c8d8\n"
        ".L_1c760_1c822:\n"
        "mov r8, qword ptr [rbx + 0x10]\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "cmp byte ptr [r8 + 0x19], 0\n"
        "je .L_1c760_1c877\n"
        "mov rax, qword ptr [rbx + 8]\n"
        "lea rcx, [rbx + 8]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1c760_1c853\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_1c760_1c840:\n"
        "cmp rbx, qword ptr [rax + 0x10]\n"
        "jne .L_1c760_1c853\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "mov rax, qword ptr [rax + 8]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c760_1c840\n"
        ".L_1c760_1c853:\n"
        "mov rcx, qword ptr [rcx]\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c760_1c8bc\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        ".L_1c760_1c862:\n"
        "cmp rax, qword ptr [rcx + 0x10]\n"
        "jne .L_1c760_1c8bc\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "mov rcx, qword ptr [rcx + 8]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "je .L_1c760_1c862\n"
        "jmp .L_1c760_1c8bc\n"
        ".L_1c760_1c877:\n"
        "mov rcx, qword ptr [r8]\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c760_1c89f\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1c760_1c890:\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c760_1c890\n"
        ".L_1c760_1c89f:\n"
        "mov rcx, qword ptr [r8]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c760_1c8bc\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1c760_1c8b0:\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c760_1c8b0\n"
        ".L_1c760_1c8bc:\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call rva_1c900\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call rva_7c60\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "jne .L_1c760_1c822\n"
        ".L_1c760_1c8d8:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rbp\n"
        "mov rbp, qword ptr [rsp + 0x38]\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "mov rdi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        END);
}

/* body 0x1c900 until 0x1ccce */
BODY void apw_1c900(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [rdx + 0x10]\n"
        "lea r9, [rdx + 0x10]\n"
        "mov qword ptr [rsp + 0x38], rdi\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "apw_mov64_load reg_r14, reg_rdx\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c900_1c947\n"
        "mov rax, qword ptr [rdx + 8]\n"
        "lea r8, [rdx + 8]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1c900_1c963\n"
        ".L_1c900_1c932:\n"
        "cmp rdx, qword ptr [rax + 0x10]\n"
        "jne .L_1c900_1c963\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov rax, qword ptr [rax + 8]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c900_1c932\n"
        "jmp .L_1c900_1c963\n"
        ".L_1c900_1c947:\n"
        "mov rdx, qword ptr [rax]\n"
        "cmp byte ptr [rdx + 0x19], 0\n"
        "jne .L_1c900_1c95f\n"
        ".L_1c900_1c950:\n"
        "mov rcx, qword ptr [rdx]\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "apw_mov64_load reg_rdx, reg_rcx\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "je .L_1c900_1c950\n"
        ".L_1c900_1c95f:\n"
        "lea r8, [r14 + 8]\n"
        ".L_1c900_1c963:\n"
        "mov rcx, qword ptr [r14]\n"
        "mov rdi, qword ptr [r9]\n"
        "mov qword ptr [rsp + 0x30], rbx\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c900_1c98c\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "je .L_1c900_1c97f\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "jmp .L_1c900_1c98c\n"
        ".L_1c900_1c97f:\n"
        "mov rdi, qword ptr [rax + 0x10]\n"
        "apw_cmp64_load reg_rax, reg_r14\n"
        "jne .L_1c900_1ca33\n"
        ".L_1c900_1c98c:\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "mov rbx, qword ptr [r8]\n"
        "jne .L_1c900_1c999\n"
        "mov qword ptr [rdi + 8], rbx\n"
        ".L_1c900_1c999:\n"
        "mov rax, qword ptr [rsi]\n"
        "cmp qword ptr [rax + 8], r14\n"
        "jne .L_1c900_1c9a8\n"
        "mov qword ptr [rax + 8], rdi\n"
        "jmp .L_1c900_1c9b6\n"
        ".L_1c900_1c9a8:\n"
        "cmp qword ptr [rbx], r14\n"
        "jne .L_1c900_1c9b2\n"
        "mov qword ptr [rbx], rdi\n"
        "jmp .L_1c900_1c9b6\n"
        ".L_1c900_1c9b2:\n"
        "mov qword ptr [rbx + 0x10], rdi\n"
        ".L_1c900_1c9b6:\n"
        "mov r8, qword ptr [rsi]\n"
        "cmp qword ptr [r8], r14\n"
        "jne .L_1c900_1c9f2\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "je .L_1c900_1c9c9\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "jmp .L_1c900_1c9ef\n"
        ".L_1c900_1c9c9:\n"
        "mov rcx, qword ptr [rdi]\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c900_1c9ef\n"
        ".byte 0x66,0x66,0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1c900_1c9e0:\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_rdx, reg_rcx\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c900_1c9e0\n"
        ".L_1c900_1c9ef:\n"
        "mov qword ptr [r8], rdx\n"
        ".L_1c900_1c9f2:\n"
        "mov rdx, qword ptr [rsi]\n"
        "cmp qword ptr [rdx + 0x10], r14\n"
        "jne .L_1c900_1ca9d\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "je .L_1c900_1ca11\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov qword ptr [rdx + 0x10], rbx\n"
        "jmp .L_1c900_1ca9d\n"
        ".L_1c900_1ca11:\n"
        "mov rax, qword ptr [rdi + 0x10]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1c900_1ca2d\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_1c900_1ca20:\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov rax, qword ptr [rax + 0x10]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "je .L_1c900_1ca20\n"
        ".L_1c900_1ca2d:\n"
        "mov qword ptr [rdx + 0x10], rcx\n"
        "jmp .L_1c900_1ca9d\n"
        ".L_1c900_1ca33:\n"
        "mov qword ptr [rcx + 8], rax\n"
        "mov rcx, qword ptr [r14]\n"
        "mov qword ptr [rax], rcx\n"
        "cmp rax, qword ptr [r9]\n"
        "jne .L_1c900_1ca47\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "jmp .L_1c900_1ca66\n"
        ".L_1c900_1ca47:\n"
        "cmp byte ptr [rdi + 0x19], 0\n"
        "mov rbx, qword ptr [rax + 8]\n"
        "jne .L_1c900_1ca55\n"
        "mov qword ptr [rdi + 8], rbx\n"
        ".L_1c900_1ca55:\n"
        "mov qword ptr [rbx], rdi\n"
        "mov rcx, qword ptr [r9]\n"
        "mov qword ptr [rax + 0x10], rcx\n"
        "mov rcx, qword ptr [r9]\n"
        "mov qword ptr [rcx + 8], rax\n"
        ".L_1c900_1ca66:\n"
        "mov rcx, qword ptr [rsi]\n"
        "cmp qword ptr [rcx + 8], r14\n"
        "jne .L_1c900_1ca75\n"
        "mov qword ptr [rcx + 8], rax\n"
        "jmp .L_1c900_1ca86\n"
        ".L_1c900_1ca75:\n"
        "mov rcx, qword ptr [r8]\n"
        "cmp qword ptr [rcx], r14\n"
        "jne .L_1c900_1ca82\n"
        "mov qword ptr [rcx], rax\n"
        "jmp .L_1c900_1ca86\n"
        ".L_1c900_1ca82:\n"
        "mov qword ptr [rcx + 0x10], rax\n"
        ".L_1c900_1ca86:\n"
        "mov rcx, qword ptr [r8]\n"
        "movzx edx, byte ptr [rax + 0x18]\n"
        "mov qword ptr [rax + 8], rcx\n"
        "movzx ecx, byte ptr [r14 + 0x18]\n"
        "mov byte ptr [rax + 0x18], cl\n"
        "mov byte ptr [r14 + 0x18], dl\n"
        ".L_1c900_1ca9d:\n"
        "cmp byte ptr [r14 + 0x18], 1\n"
        "jne .L_1c900_1cca5\n"
        "mov rax, qword ptr [rsi]\n"
        "cmp rdi, qword ptr [rax + 8]\n"
        "je .L_1c900_1cca1\n"
        ".byte 0x66,0x66,0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1c900_1cac0:\n"
        "cmp byte ptr [rdi + 0x18], 1\n"
        "apw_mov64_load reg_r10, reg_rbx\n"
        "jne .L_1c900_1cca1\n"
        "mov rcx, qword ptr [rbx]\n"
        "apw_cmp64_load reg_rdi, reg_rcx\n"
        "jne .L_1c900_1cbba\n"
        "mov rcx, qword ptr [rbx + 0x10]\n"
        "cmp byte ptr [rcx + 0x18], 0\n"
        "jne .L_1c900_1cb4f\n"
        "mov byte ptr [rcx + 0x18], 1\n"
        "mov rcx, qword ptr [rbx + 0x10]\n"
        "mov byte ptr [rbx + 0x18], 0\n"
        "mov rax, qword ptr [rcx]\n"
        "mov qword ptr [rbx + 0x10], rax\n"
        "mov rax, qword ptr [rcx]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1c900_1cb03\n"
        "mov qword ptr [rax + 8], rbx\n"
        ".L_1c900_1cb03:\n"
        "mov rax, qword ptr [rbx + 8]\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rcx + 8], rax\n"
        "mov rax, qword ptr [rsi]\n"
        "cmp rbx, qword ptr [rax + 8]\n"
        "jne .L_1c900_1cb28\n"
        "mov qword ptr [rax + 8], rcx\n"
        "mov qword ptr [rcx], rbx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [rbx + 0x10]\n"
        "jmp .L_1c900_1cb53\n"
        ".L_1c900_1cb28:\n"
        "mov rax, qword ptr [rdx]\n"
        "cmp rbx, qword ptr [rax]\n"
        "jne .L_1c900_1cb3f\n"
        "mov qword ptr [rax], rcx\n"
        "mov qword ptr [rcx], rbx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [rbx + 0x10]\n"
        "jmp .L_1c900_1cb53\n"
        ".L_1c900_1cb3f:\n"
        "mov qword ptr [rax + 0x10], rcx\n"
        "mov qword ptr [rcx], rbx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [rbx + 0x10]\n"
        "jmp .L_1c900_1cb53\n"
        ".L_1c900_1cb4f:\n"
        "lea rdx, [rbx + 8]\n"
        ".L_1c900_1cb53:\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c900_1cc4f\n"
        "mov r9, qword ptr [rcx]\n"
        "cmp byte ptr [r9 + 0x18], 1\n"
        "jne .L_1c900_1cb75\n"
        "mov rax, qword ptr [rcx + 0x10]\n"
        "cmp byte ptr [rax + 0x18], 1\n"
        "je .L_1c900_1cc4b\n"
        ".L_1c900_1cb75:\n"
        "mov rax, qword ptr [rcx + 0x10]\n"
        "cmp byte ptr [rax + 0x18], 1\n"
        "jne .L_1c900_1cb97\n"
        "mov byte ptr [r9 + 0x18], 1\n"
        "apw_mov64_load reg_rdx, reg_rcx\n"
        "mov byte ptr [rcx + 0x18], 0\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_1d060\n"
        "mov rcx, qword ptr [rbx + 0x10]\n"
        ".L_1c900_1cb97:\n"
        "movzx eax, byte ptr [rbx + 0x18]\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "mov byte ptr [rcx + 0x18], al\n"
        "mov byte ptr [rbx + 0x18], 1\n"
        "mov rax, qword ptr [rcx + 0x10]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "mov byte ptr [rax + 0x18], 1\n"
        "call rva_1cfc0\n"
        "jmp .L_1c900_1cca1\n"
        ".L_1c900_1cbba:\n"
        "cmp byte ptr [rcx + 0x18], 0\n"
        "jne .L_1c900_1cc2d\n"
        "mov byte ptr [rcx + 0x18], 1\n"
        "mov rcx, qword ptr [rbx]\n"
        "mov byte ptr [rbx + 0x18], 0\n"
        "mov rax, qword ptr [rcx + 0x10]\n"
        "mov qword ptr [rbx], rax\n"
        "mov rax, qword ptr [rcx + 0x10]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1c900_1cbe0\n"
        "mov qword ptr [rax + 8], rbx\n"
        ".L_1c900_1cbe0:\n"
        "mov rax, qword ptr [rbx + 8]\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rcx + 8], rax\n"
        "mov rax, qword ptr [rsi]\n"
        "cmp rbx, qword ptr [rax + 8]\n"
        "jne .L_1c900_1cc05\n"
        "mov qword ptr [rax + 8], rcx\n"
        "mov qword ptr [rcx + 0x10], rbx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [rbx]\n"
        "jmp .L_1c900_1cc31\n"
        ".L_1c900_1cc05:\n"
        "mov rax, qword ptr [rdx]\n"
        "cmp rbx, qword ptr [rax + 0x10]\n"
        "jne .L_1c900_1cc1e\n"
        "mov qword ptr [rax + 0x10], rcx\n"
        "mov qword ptr [rcx + 0x10], rbx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [rbx]\n"
        "jmp .L_1c900_1cc31\n"
        ".L_1c900_1cc1e:\n"
        "mov qword ptr [rax], rcx\n"
        "mov qword ptr [rcx + 0x10], rbx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [rbx]\n"
        "jmp .L_1c900_1cc31\n"
        ".L_1c900_1cc2d:\n"
        "lea rdx, [rbx + 8]\n"
        ".L_1c900_1cc31:\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1c900_1cc4f\n"
        "mov r8, qword ptr [rcx + 0x10]\n"
        "cmp byte ptr [r8 + 0x18], 1\n"
        "jne .L_1c900_1cc64\n"
        "mov rax, qword ptr [rcx]\n"
        "cmp byte ptr [rax + 0x18], 1\n"
        "jne .L_1c900_1cc64\n"
        ".L_1c900_1cc4b:\n"
        "mov byte ptr [rcx + 0x18], 0\n"
        ".L_1c900_1cc4f:\n"
        "mov rax, qword ptr [rsi]\n"
        "apw_mov64_load reg_rdi, reg_r10\n"
        "mov rbx, qword ptr [rdx]\n"
        "cmp r10, qword ptr [rax + 8]\n"
        "jne .L_1c900_1cac0\n"
        "jmp .L_1c900_1cca1\n"
        ".L_1c900_1cc64:\n"
        "mov rax, qword ptr [rcx]\n"
        "cmp byte ptr [rax + 0x18], 1\n"
        "jne .L_1c900_1cc84\n"
        "mov byte ptr [r8 + 0x18], 1\n"
        "apw_mov64_load reg_rdx, reg_rcx\n"
        "mov byte ptr [rcx + 0x18], 0\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_1cfc0\n"
        "mov rcx, qword ptr [rbx]\n"
        ".L_1c900_1cc84:\n"
        "movzx eax, byte ptr [rbx + 0x18]\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "mov byte ptr [rcx + 0x18], al\n"
        "mov byte ptr [rbx + 0x18], 1\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "mov byte ptr [rax + 0x18], 1\n"
        "call rva_1d060\n"
        ".L_1c900_1cca1:\n"
        "mov byte ptr [rdi + 0x18], 1\n"
        ".L_1c900_1cca5:\n"
        "mov rcx, qword ptr [rsi + 8]\n"
        "apw_mov64_load reg_rax, reg_r14\n"
        "mov rdi, qword ptr [rsp + 0x38]\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "test rcx, rcx\n"
        "je .L_1c900_1ccc2\n"
        "dec rcx\n"
        "mov qword ptr [rsi + 8], rcx\n"
        ".L_1c900_1ccc2:\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        END);
}

/* body 0x1ccd0 until 0x1cd3e */
BODY void apw_1ccd0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "mov rbx, qword ptr [rcx]\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "test rbx, rbx\n"
        "je .L_1ccd0_1cd33\n"
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rbx + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_1ccd0_1cd2c\n"
        "mov rcx, qword ptr [rbx]\n"
        "test rcx, rcx\n"
        "je .L_1ccd0_1cd09\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], 0\n"
        ".L_1ccd0_1cd09:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_1ccd0_1cd1f\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], 0\n"
        ".L_1ccd0_1cd1f:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_35134\n"
        ".L_1ccd0_1cd2c:\n"
        "mov qword ptr [rdi], 0\n"
        ".L_1ccd0_1cd33:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1cd40 until 0x1cf9b */
BODY void apw_1cd40(void) {
    __asm__(INTEL
        "inc qword ptr [rcx + 8]\n"
        "apw_mov64_load reg_r9, reg_r8\n"
        "mov r11, qword ptr [rcx]\n"
        "apw_mov64_load reg_r10, reg_rcx\n"
        "mov rax, qword ptr [rdx]\n"
        "mov qword ptr [r8 + 8], rax\n"
        "apw_cmp64_load reg_rax, reg_r11\n"
        "jne .L_1cd40_1cd6d\n"
        "mov qword ptr [r11], r8\n"
        "apw_mov64_load reg_rax, reg_r8\n"
        "mov qword ptr [r11 + 8], r8\n"
        "mov qword ptr [r11 + 0x10], r8\n"
        "mov byte ptr [r8 + 0x18], 1\n"
        "ret\n"
        ".L_1cd40_1cd6d:\n"
        "cmp dword ptr [rdx + 8], 0\n"
        "jne .L_1cd40_1cd83\n"
        "mov qword ptr [rax + 0x10], r9\n"
        "cmp rax, qword ptr [r11 + 0x10]\n"
        "jne .L_1cd40_1cd8e\n"
        "mov qword ptr [r11 + 0x10], r9\n"
        "jmp .L_1cd40_1cd8e\n"
        ".L_1cd40_1cd83:\n"
        "mov qword ptr [rax], r9\n"
        "cmp rax, qword ptr [r11]\n"
        "jne .L_1cd40_1cd8e\n"
        "mov qword ptr [r11], r9\n"
        ".L_1cd40_1cd8e:\n"
        "mov rcx, qword ptr [r8 + 8]\n"
        "apw_mov64_load reg_rax, reg_r9\n"
        "cmp byte ptr [rcx + 0x18], 0\n"
        "jne .L_1cd40_1cf8f\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_1cd40_1cda0:\n"
        "mov rdx, qword ptr [rax + 8]\n"
        "mov r8, qword ptr [rdx + 8]\n"
        "mov rcx, qword ptr [r8]\n"
        "apw_cmp64_load reg_rdx, reg_rcx\n"
        "jne .L_1cd40_1cea4\n"
        "mov rcx, qword ptr [r8 + 0x10]\n"
        "cmp byte ptr [rcx + 0x18], 0\n"
        "jne .L_1cd40_1cddf\n"
        "mov byte ptr [rdx + 0x18], 1\n"
        "mov byte ptr [rcx + 0x18], 1\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "mov byte ptr [rdx + 0x18], 0\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rax, qword ptr [rcx + 8]\n"
        "jmp .L_1cd40_1cf81\n"
        ".L_1cd40_1cddf:\n"
        "mov r8, qword ptr [rdx + 0x10]\n"
        "apw_cmp64_load reg_rax, reg_r8\n"
        "jne .L_1cd40_1ce2f\n"
        "mov rcx, qword ptr [r8]\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "mov qword ptr [rdx + 0x10], rcx\n"
        "mov rcx, qword ptr [r8]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1cd40_1cdff\n"
        "mov qword ptr [rcx + 8], rdx\n"
        ".L_1cd40_1cdff:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "mov qword ptr [r8 + 8], rcx\n"
        "mov rcx, qword ptr [r10]\n"
        "cmp rdx, qword ptr [rcx + 8]\n"
        "jne .L_1cd40_1ce16\n"
        "mov qword ptr [rcx + 8], r8\n"
        "jmp .L_1cd40_1ce28\n"
        ".L_1cd40_1ce16:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "cmp rdx, qword ptr [rcx]\n"
        "jne .L_1cd40_1ce24\n"
        "mov qword ptr [rcx], r8\n"
        "jmp .L_1cd40_1ce28\n"
        ".L_1cd40_1ce24:\n"
        "mov qword ptr [rcx + 0x10], r8\n"
        ".L_1cd40_1ce28:\n"
        "mov qword ptr [r8], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        ".L_1cd40_1ce2f:\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov byte ptr [rcx + 0x18], 1\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "mov byte ptr [rdx + 0x18], 0\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "mov r8, qword ptr [rdx]\n"
        "mov rcx, qword ptr [r8 + 0x10]\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [r8 + 0x10]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1cd40_1ce63\n"
        "mov qword ptr [rcx + 8], rdx\n"
        ".L_1cd40_1ce63:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "mov qword ptr [r8 + 8], rcx\n"
        "mov rcx, qword ptr [r10]\n"
        "cmp rdx, qword ptr [rcx + 8]\n"
        "jne .L_1cd40_1ce81\n"
        "mov qword ptr [rcx + 8], r8\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "jmp .L_1cd40_1cf7d\n"
        ".L_1cd40_1ce81:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "cmp rdx, qword ptr [rcx + 0x10]\n"
        "jne .L_1cd40_1ce98\n"
        "mov qword ptr [rcx + 0x10], r8\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "jmp .L_1cd40_1cf7d\n"
        ".L_1cd40_1ce98:\n"
        "mov qword ptr [rcx], r8\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "jmp .L_1cd40_1cf7d\n"
        ".L_1cd40_1cea4:\n"
        "cmp byte ptr [rcx + 0x18], 0\n"
        "jne .L_1cd40_1cecb\n"
        "mov byte ptr [rdx + 0x18], 1\n"
        "mov byte ptr [rcx + 0x18], 1\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "mov byte ptr [rdx + 0x18], 0\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rax, qword ptr [rcx + 8]\n"
        "jmp .L_1cd40_1cf81\n"
        ".L_1cd40_1cecb:\n"
        "mov r8, qword ptr [rdx]\n"
        "apw_cmp64_load reg_rax, reg_r8\n"
        "jne .L_1cd40_1cf1d\n"
        "mov rcx, qword ptr [r8 + 0x10]\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "mov qword ptr [rdx], rcx\n"
        "mov rcx, qword ptr [r8 + 0x10]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1cd40_1ceeb\n"
        "mov qword ptr [rcx + 8], rdx\n"
        ".L_1cd40_1ceeb:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "mov qword ptr [r8 + 8], rcx\n"
        "mov rcx, qword ptr [r10]\n"
        "cmp rdx, qword ptr [rcx + 8]\n"
        "jne .L_1cd40_1cf02\n"
        "mov qword ptr [rcx + 8], r8\n"
        "jmp .L_1cd40_1cf15\n"
        ".L_1cd40_1cf02:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "cmp rdx, qword ptr [rcx + 0x10]\n"
        "jne .L_1cd40_1cf12\n"
        "mov qword ptr [rcx + 0x10], r8\n"
        "jmp .L_1cd40_1cf15\n"
        ".L_1cd40_1cf12:\n"
        "mov qword ptr [rcx], r8\n"
        ".L_1cd40_1cf15:\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        ".L_1cd40_1cf1d:\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov byte ptr [rcx + 0x18], 1\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "mov byte ptr [rdx + 0x18], 0\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "mov r8, qword ptr [rdx + 0x10]\n"
        "mov rcx, qword ptr [r8]\n"
        "mov qword ptr [rdx + 0x10], rcx\n"
        "mov rcx, qword ptr [r8]\n"
        "cmp byte ptr [rcx + 0x19], 0\n"
        "jne .L_1cd40_1cf51\n"
        "mov qword ptr [rcx + 8], rdx\n"
        ".L_1cd40_1cf51:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "mov qword ptr [r8 + 8], rcx\n"
        "mov rcx, qword ptr [r10]\n"
        "cmp rdx, qword ptr [rcx + 8]\n"
        "jne .L_1cd40_1cf68\n"
        "mov qword ptr [rcx + 8], r8\n"
        "jmp .L_1cd40_1cf7a\n"
        ".L_1cd40_1cf68:\n"
        "mov rcx, qword ptr [rdx + 8]\n"
        "cmp rdx, qword ptr [rcx]\n"
        "jne .L_1cd40_1cf76\n"
        "mov qword ptr [rcx], r8\n"
        "jmp .L_1cd40_1cf7a\n"
        ".L_1cd40_1cf76:\n"
        "mov qword ptr [rcx + 0x10], r8\n"
        ".L_1cd40_1cf7a:\n"
        "mov qword ptr [r8], rdx\n"
        ".L_1cd40_1cf7d:\n"
        "mov qword ptr [rdx + 8], r8\n"
        ".L_1cd40_1cf81:\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "cmp byte ptr [rcx + 0x18], 0\n"
        "je .L_1cd40_1cda0\n"
        ".L_1cd40_1cf8f:\n"
        "mov rax, qword ptr [r11 + 8]\n"
        "mov byte ptr [rax + 0x18], 1\n"
        "apw_mov64_load reg_rax, reg_r9\n"
        "ret\n"
        END);
}

/* body 0x1cfa0 until 0x1cfb4 */
BODY void apw_1cfa0(void) {
    __asm__(INTEL
        "mov rcx, qword ptr [rcx + 0x80]\n"
        "test rcx, rcx\n"
        "je .L_1cfa0_1cfb3\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a6d8]\n"
        ".L_1cfa0_1cfb3:\n"
        "ret\n"
        END);
}

/* body 0x1cfc0 until 0x1d015 */
BODY void apw_1cfc0(void) {
    __asm__(INTEL
        "mov r8, qword ptr [rdx + 0x10]\n"
        "mov rax, qword ptr [r8]\n"
        "mov qword ptr [rdx + 0x10], rax\n"
        "mov rax, qword ptr [r8]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1cfc0_1cfd8\n"
        "mov qword ptr [rax + 8], rdx\n"
        ".L_1cfc0_1cfd8:\n"
        "mov rax, qword ptr [rdx + 8]\n"
        "mov qword ptr [r8 + 8], rax\n"
        "mov rax, qword ptr [rcx]\n"
        "cmp rdx, qword ptr [rax + 8]\n"
        "jne .L_1cfc0_1cff5\n"
        "mov qword ptr [rax + 8], r8\n"
        "mov qword ptr [r8], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        "ret\n"
        ".L_1cfc0_1cff5:\n"
        "mov rax, qword ptr [rdx + 8]\n"
        "cmp rdx, qword ptr [rax]\n"
        "jne .L_1cfc0_1d009\n"
        "mov qword ptr [rax], r8\n"
        "mov qword ptr [r8], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        "ret\n"
        ".L_1cfc0_1d009:\n"
        "mov qword ptr [rax + 0x10], r8\n"
        "mov qword ptr [r8], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        "ret\n"
        END);
}

/* body 0x1d020 until 0x1d05e */
BODY void apw_1d020(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call qword ptr [rip + rva_3a450]\n"
        "lea rdx, [rbx + 0x70]\n"
        "apw_cmp64_load reg_rax, reg_rdx\n"
        "jne .L_1d020_1d058\n"
        "mov rdx, qword ptr [rbx + 0x88]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov r9, qword ptr [rbx + 0x90]\n"
        "apw_mov64_load reg_r8, reg_rdx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a428]\n"
        ".L_1d020_1d058:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1d060 until 0x1d0b9 */
BODY void apw_1d060(void) {
    __asm__(INTEL
        "mov r8, qword ptr [rdx]\n"
        "mov rax, qword ptr [r8 + 0x10]\n"
        "mov qword ptr [rdx], rax\n"
        "mov rax, qword ptr [r8 + 0x10]\n"
        "cmp byte ptr [rax + 0x19], 0\n"
        "jne .L_1d060_1d078\n"
        "mov qword ptr [rax + 8], rdx\n"
        ".L_1d060_1d078:\n"
        "mov rax, qword ptr [rdx + 8]\n"
        "mov qword ptr [r8 + 8], rax\n"
        "mov rax, qword ptr [rcx]\n"
        "cmp rdx, qword ptr [rax + 8]\n"
        "jne .L_1d060_1d096\n"
        "mov qword ptr [rax + 8], r8\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        "ret\n"
        ".L_1d060_1d096:\n"
        "mov rax, qword ptr [rdx + 8]\n"
        "cmp rdx, qword ptr [rax + 0x10]\n"
        "jne .L_1d060_1d0ad\n"
        "mov qword ptr [rax + 0x10], r8\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        "ret\n"
        ".L_1d060_1d0ad:\n"
        "mov qword ptr [rax], r8\n"
        "mov qword ptr [r8 + 0x10], rdx\n"
        "mov qword ptr [rdx + 8], r8\n"
        "ret\n"
        END);
}

/* body 0x1d190 until 0x1d1a4 */
BODY void apw_1d190(void) {
    __asm__(INTEL
        "mov rcx, qword ptr [rcx + 0x80]\n"
        "test rcx, rcx\n"
        "je .L_1d190_1d1a3\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a6f0]\n"
        ".L_1d190_1d1a3:\n"
        "ret\n"
        END);
}

/* body 0x1d1f0 until 0x1d201 */
BODY void apw_1d1f0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea rcx, [rip + rva_41f38]\n"
        "call rva_36240\n"
        "int3\n"
        END);
}

/* body 0x1d4c0 until 0x1d570 */
BODY void apw_1d4c0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [rcx + 0x80], 0\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "je .L_1d4c0_1d531\n"
        "mov qword ptr [rsp + 0x30], rbx\n"
        "call qword ptr [rip + rva_3a450]\n"
        "lea rdx, [rdi + 0x70]\n"
        "apw_cmp64_load reg_rax, reg_rdx\n"
        "jne .L_1d4c0_1d505\n"
        "mov rdx, qword ptr [rdi + 0x88]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov r9, qword ptr [rdi + 0x90]\n"
        "apw_mov64_load reg_r8, reg_rdx\n"
        "call qword ptr [rip + rva_3a428]\n"
        ".L_1d4c0_1d505:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_1c670\n"
        "mov rcx, qword ptr [rdi + 0x80]\n"
        "apw_xor32_load reg_ebx, reg_ebx\n"
        "test al, al\n"
        "cmovne rbx, rdi\n"
        "call qword ptr [rip + rva_3a7d8]\n"
        "apw_xor32_load reg_esi, reg_esi\n"
        "test eax, eax\n"
        "cmove rsi, rbx\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "jmp .L_1d4c0_1d533\n"
        ".L_1d4c0_1d531:\n"
        "apw_xor32_load reg_esi, reg_esi\n"
        ".L_1d4c0_1d533:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov byte ptr [rdi + 0x7c], 0\n"
        "mov byte ptr [rdi + 0x71], 0\n"
        "call qword ptr [rip + rva_3a3e8]\n"
        "mov qword ptr [rdi + 0x80], 0\n"
        "apw_mov64_load reg_rax, reg_rsi\n"
        "mov rcx, qword ptr [rip + rva_53598]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "mov qword ptr [rdi + 0x74], rcx\n"
        "mov qword ptr [rdi + 0x68], 0\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1d790 until 0x1d7e0 */
BODY void apw_1d790(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "call rva_8350\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "call qword ptr [rip + rva_3a498]\n"
        "test al, al\n"
        "je .L_1d790_1d7c8\n"
        "mov qword ptr [rbx + 0x68], 0\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        ".L_1d790_1d7c8:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov qword ptr [rbx + 0x68], rdi\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a3e8]\n"
        END);
}

/* body 0x1d7e0 until 0x1d994 */
BODY void apw_1d7e0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push rdi\n"
        "sub rsp, 0x80\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x78], rax\n"
        "apw_mov32_load reg_esi, reg_edx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "cmp edx, -1\n"
        "jne .L_1d7e0_1d80d\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "jmp .L_1d7e0_1d976\n"
        ".L_1d7e0_1d80d:\n"
        "mov qword ptr [rsp + 0xa0], rbx\n"
        "call qword ptr [rip + rva_3a440]\n"
        "test rax, rax\n"
        "je .L_1d7e0_1d84d\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a420]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "call qword ptr [rip + rva_3a440]\n"
        "apw_cmp64_load reg_rax, reg_rbx\n"
        "jae .L_1d7e0_1d84d\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a3f8]\n"
        "mov byte ptr [rax], sil\n"
        "apw_mov32_load reg_eax, reg_esi\n"
        "jmp .L_1d7e0_1d96e\n"
        ".L_1d7e0_1d84d:\n"
        "cmp qword ptr [rdi + 0x80], 0\n"
        "je .L_1d7e0_1d969\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a450]\n"
        "lea rcx, [rdi + 0x70]\n"
        "apw_cmp64_load reg_rax, reg_rcx\n"
        "jne .L_1d7e0_1d887\n"
        "mov rdx, qword ptr [rdi + 0x88]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov r9, qword ptr [rdi + 0x90]\n"
        "apw_mov64_load reg_r8, reg_rdx\n"
        "call qword ptr [rip + rva_3a428]\n"
        ".L_1d7e0_1d887:\n"
        "mov rcx, qword ptr [rdi + 0x68]\n"
        "test rcx, rcx\n"
        "jne .L_1d7e0_1d8b2\n"
        "mov rdx, qword ptr [rdi + 0x80]\n"
        "movsx ecx, sil\n"
        "call qword ptr [rip + rva_3a808]\n"
        "mov ecx, 0xffffffff\n"
        "apw_cmp32_load reg_eax, reg_ecx\n"
        "cmovne ecx, esi\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "jmp .L_1d7e0_1d96e\n"
        ".L_1d7e0_1d8b2:\n"
        "lea rax, [rsp + 0x48]\n"
        "mov byte ptr [rsp + 0x40], sil\n"
        "mov qword ptr [rsp + 0x38], rax\n"
        "lea rdx, [rdi + 0x74]\n"
        "lea rax, [rsp + 0x78]\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "lea r9, [rsp + 0x41]\n"
        "lea rax, [rsp + 0x58]\n"
        "mov qword ptr [rsp + 0x28], rax\n"
        "lea r8, [rsp + 0x40]\n"
        "lea rax, [rsp + 0x50]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "call qword ptr [rip + rva_3a488]\n"
        "test eax, eax\n"
        "je .L_1d7e0_1d921\n"
        "sub eax, 1\n"
        "je .L_1d7e0_1d921\n"
        "cmp eax, 2\n"
        "jne .L_1d7e0_1d969\n"
        "movsx ecx, byte ptr [rsp + 0x40]\n"
        "mov rdx, qword ptr [rdi + 0x80]\n"
        "call qword ptr [rip + rva_3a808]\n"
        "mov ecx, 0xffffffff\n"
        "apw_cmp32_load reg_eax, reg_ecx\n"
        "cmovne ecx, esi\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "jmp .L_1d7e0_1d96e\n"
        ".L_1d7e0_1d921:\n"
        "mov rbx, qword ptr [rsp + 0x48]\n"
        "lea rax, [rsp + 0x58]\n"
        "apw_sub64_load reg_rbx, reg_rax\n"
        "je .L_1d7e0_1d94f\n"
        "mov r9, qword ptr [rdi + 0x80]\n"
        "lea rcx, [rsp + 0x58]\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "mov edx, 1\n"
        "call qword ptr [rip + rva_3a828]\n"
        "apw_cmp64_load reg_rbx, reg_rax\n"
        "jne .L_1d7e0_1d969\n"
        ".L_1d7e0_1d94f:\n"
        "lea rax, [rsp + 0x40]\n"
        "mov byte ptr [rdi + 0x71], 1\n"
        "cmp qword ptr [rsp + 0x50], rax\n"
        "mov ecx, 0xffffffff\n"
        "cmovne ecx, esi\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "jmp .L_1d7e0_1d96e\n"
        ".L_1d7e0_1d969:\n"
        "mov eax, 0xffffffff\n"
        ".L_1d7e0_1d96e:\n"
        "mov rbx, qword ptr [rsp + 0xa0]\n"
        ".L_1d7e0_1d976:\n"
        "mov rcx, qword ptr [rsp + 0x78]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rsi, qword ptr [rsp + 0xa8]\n"
        "add rsp, 0x80\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1d9a0 until 0x1daba */
BODY void apw_1d9a0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov32_load reg_esi, reg_edx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "call qword ptr [rip + rva_3a448]\n"
        "test rax, rax\n"
        "je .L_1d9a0_1da12\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a450]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "call qword ptr [rip + rva_3a448]\n"
        "apw_cmp64_load reg_rbx, reg_rax\n"
        "jae .L_1d9a0_1da12\n"
        "cmp esi, -1\n"
        "je .L_1d9a0_1d9ef\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a448]\n"
        "movzx eax, byte ptr [rax - 1]\n"
        "apw_cmp32_load reg_eax, reg_esi\n"
        "jne .L_1d9a0_1da12\n"
        ".L_1d9a0_1d9ef:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a418]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "cmp esi, -1\n"
        "cmove esi, eax\n"
        ".L_1d9a0_1da00:\n"
        "apw_mov32_load reg_eax, reg_esi\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        ".L_1d9a0_1da12:\n"
        "mov rdx, qword ptr [rdi + 0x80]\n"
        "test rdx, rdx\n"
        "je .L_1d9a0_1daa5\n"
        "cmp esi, -1\n"
        "je .L_1d9a0_1daa5\n"
        "cmp qword ptr [rdi + 0x68], 0\n"
        "jne .L_1d9a0_1da3d\n"
        "movzx ecx, sil\n"
        "call qword ptr [rip + rva_3a840]\n"
        "cmp eax, -1\n"
        "jne .L_1d9a0_1da00\n"
        ".L_1d9a0_1da3d:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "lea rbx, [rdi + 0x70]\n"
        "call qword ptr [rip + rva_3a448]\n"
        "apw_cmp64_load reg_rax, reg_rbx\n"
        "je .L_1d9a0_1daa5\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov byte ptr [rbx], sil\n"
        "call qword ptr [rip + rva_3a450]\n"
        "apw_cmp64_load reg_rax, reg_rbx\n"
        "je .L_1d9a0_1da80\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a450]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov qword ptr [rdi + 0x88], rax\n"
        "call qword ptr [rip + rva_3a438]\n"
        "mov qword ptr [rdi + 0x90], rax\n"
        ".L_1d9a0_1da80:\n"
        "lea r9, [rdi + 0x71]\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a428]\n"
        "apw_mov32_load reg_eax, reg_esi\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        ".L_1d9a0_1daa5:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov eax, 0xffffffff\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1dac0 until 0x1db8e */
BODY void apw_1dac0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rbp\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov32_load reg_ebp, reg_r9d\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "call qword ptr [rip + rva_3a448]\n"
        "lea r10, [rdi + 0x70]\n"
        "apw_cmp64_load reg_rax, reg_r10\n"
        "jne .L_1dac0_1dafe\n"
        "cmp ebp, 1\n"
        "jne .L_1dac0_1dafe\n"
        "cmp qword ptr [rdi + 0x68], 0\n"
        "jne .L_1dac0_1dafe\n"
        "dec rsi\n"
        ".L_1dac0_1dafe:\n"
        "cmp qword ptr [rdi + 0x80], 0\n"
        "je .L_1dac0_1db61\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_1c670\n"
        "test al, al\n"
        "je .L_1dac0_1db61\n"
        "test rsi, rsi\n"
        "jne .L_1dac0_1db1e\n"
        "cmp ebp, 1\n"
        "je .L_1dac0_1db35\n"
        ".L_1dac0_1db1e:\n"
        "mov rcx, qword ptr [rdi + 0x80]\n"
        "apw_mov32_load reg_r8d, reg_ebp\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "call qword ptr [rip + rva_3a820]\n"
        "test eax, eax\n"
        "jne .L_1dac0_1db61\n"
        ".L_1dac0_1db35:\n"
        "mov rcx, qword ptr [rdi + 0x80]\n"
        "lea rdx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a7f8]\n"
        "test eax, eax\n"
        "jne .L_1dac0_1db61\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_1d020\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "mov rax, qword ptr [rdi + 0x74]\n"
        "mov qword ptr [rbx], rcx\n"
        "jmp .L_1dac0_1db6a\n"
        ".L_1dac0_1db61:\n"
        "mov qword ptr [rbx], 0xffffffffffffffff\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_1dac0_1db6a:\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "mov qword ptr [rbx + 8], 0\n"
        "mov qword ptr [rbx + 0x10], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1db90 until 0x1dc23 */
BODY void apw_1db90(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [r8 + 8]\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "add rax, qword ptr [r8]\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "cmp qword ptr [rcx + 0x80], 0\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "je .L_1db90_1dbfb\n"
        "call rva_1c670\n"
        "test al, al\n"
        "je .L_1db90_1dbfb\n"
        "mov rcx, qword ptr [rdi + 0x80]\n"
        "lea rdx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a818]\n"
        "test eax, eax\n"
        "jne .L_1db90_1dbfb\n"
        "mov rax, qword ptr [rsi + 0x10]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov qword ptr [rdi + 0x74], rax\n"
        "call rva_1d020\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "mov rax, qword ptr [rdi + 0x74]\n"
        "mov qword ptr [rbx], rcx\n"
        "jmp .L_1db90_1dc04\n"
        ".L_1db90_1dbfb:\n"
        "mov qword ptr [rbx], 0xffffffffffffffff\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_1db90_1dc04:\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "mov qword ptr [rbx + 8], 0\n"
        "mov qword ptr [rbx + 0x10], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1dc30 until 0x1dd0c */
BODY void apw_1dc30(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "push rsi\n"
        "sub rsp, 0x48\n"
        "apw_xor32_load reg_esi, reg_esi\n"
        "apw_mov64_load reg_r9, reg_r8\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "test rdx, rdx\n"
        "jne .L_1dc30_1dc4d\n"
        "test r8, r8\n"
        "lea r8d, [rsi + 4]\n"
        "je .L_1dc30_1dc50\n"
        ".L_1dc30_1dc4d:\n"
        "apw_mov32_load reg_r8d, reg_esi\n"
        ".L_1dc30_1dc50:\n"
        "mov rcx, qword ptr [rcx + 0x80]\n"
        "test rcx, rcx\n"
        "je .L_1dc30_1dd03\n"
        "call qword ptr [rip + rva_3a838]\n"
        "test eax, eax\n"
        "jne .L_1dc30_1dd03\n"
        "mov qword ptr [rsp + 0x40], rdi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov rdi, qword ptr [rbx + 0x80]\n"
        "mov byte ptr [rbx + 0x7c], 1\n"
        "mov byte ptr [rbx + 0x71], sil\n"
        "call qword ptr [rip + rva_3a3e8]\n"
        "test rdi, rdi\n"
        "je .L_1dc30_1dcde\n"
        "lea r9, [rsp + 0x60]\n"
        "mov qword ptr [rsp + 0x70], rsi\n"
        "lea r8, [rsp + 0x68]\n"
        "mov qword ptr [rsp + 0x68], rsi\n"
        "lea rdx, [rsp + 0x70]\n"
        "mov qword ptr [rsp + 0x60], rsi\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a7d0]\n"
        "mov r9, qword ptr [rsp + 0x60]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov r8, qword ptr [rsp + 0x68]\n"
        "mov rdx, qword ptr [rsp + 0x70]\n"
        "mov qword ptr [rsp + 0x30], r9\n"
        "mov qword ptr [rsp + 0x28], r8\n"
        "mov qword ptr [rsp + 0x20], rdx\n"
        "call qword ptr [rip + rva_3a3e0]\n"
        ".L_1dc30_1dcde:\n"
        "mov qword ptr [rbx + 0x80], rdi\n"
        "mov rax, qword ptr [rip + rva_53598]\n"
        "mov rdi, qword ptr [rsp + 0x40]\n"
        "mov qword ptr [rbx + 0x74], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "mov qword ptr [rbx + 0x68], rsi\n"
        "add rsp, 0x48\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        ".L_1dc30_1dd03:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x48\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1e0a0 until 0x1e0b3 */
BODY void apw_1e0a0(void) {
    __asm__(INTEL
        "mov rdx, qword ptr [rcx + 8]\n"
        "lea rax, [rip + rva_41368]\n"
        "test rdx, rdx\n"
        "cmovne rax, rdx\n"
        "ret\n"
        END);
}

/* body 0x1e0c0 until 0x1e1f7 */
BODY void apw_1e0c0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbp\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "apw_mov64_load reg_r14, reg_rdx\n"
        "apw_mov64_load reg_rbp, reg_rcx\n"
        "test r8, r8\n"
        "jg .L_1e0c0_1e0f1\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        ".L_1e0c0_1e0f1:\n"
        "cmp qword ptr [rcx + 0x68], 0\n"
        "je .L_1e0c0_1e10f\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a3d8]\n"
        ".L_1e0c0_1e10f:\n"
        "mov qword ptr [rsp + 0x30], rbx\n"
        "apw_mov64_load reg_rbx, reg_rsi\n"
        "mov qword ptr [rsp + 0x38], rdi\n"
        "call qword ptr [rip + rva_3a408]\n"
        "test rax, rax\n"
        "je .L_1e0c0_1e159\n"
        "apw_cmp64_load reg_rax, reg_rsi\n"
        "apw_mov64_load reg_rdi, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "cmovb rdi, rax\n"
        "call qword ptr [rip + rva_3a448]\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "call rva_362a4\n"
        "apw_mov32_load reg_edx, reg_edi\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "apw_add64_load reg_r14, reg_rdi\n"
        "apw_sub64_load reg_rbx, reg_rdi\n"
        "call qword ptr [rip + rva_3a430]\n"
        ".L_1e0c0_1e159:\n"
        "cmp qword ptr [rbp + 0x80], 0\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        "je .L_1e0c0_1e1d1\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "call rva_1d020\n"
        "cmp rbx, 0xfff\n"
        "jbe .L_1e0c0_1e1b1\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_1e0c0_1e180:\n"
        "mov r9, qword ptr [rbp + 0x80]\n"
        "mov edx, 1\n"
        "mov r8d, 0xfff\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_3a810]\n"
        "apw_sub64_load reg_rbx, reg_rax\n"
        "apw_add64_load reg_r14, reg_rax\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        "cmp rax, 0xfff\n"
        "jne .L_1e0c0_1e1f2\n"
        "apw_cmp64_load reg_rbx, reg_rax\n"
        "ja .L_1e0c0_1e180\n"
        ".L_1e0c0_1e1b1:\n"
        "test rdi, rdi\n"
        "je .L_1e0c0_1e1d1\n"
        "mov r9, qword ptr [rbp + 0x80]\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "mov edx, 1\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_3a810]\n"
        "apw_sub64_load reg_rdi, reg_rax\n"
        ".L_1e0c0_1e1d1:\n"
        "apw_sub64_load reg_rsi, reg_rdi\n"
        ".L_1e0c0_1e1d4:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rsi\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "mov rdi, qword ptr [rsp + 0x38]\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        ".L_1e0c0_1e1f2:\n"
        "apw_sub64_load reg_rsi, reg_rbx\n"
        "jmp .L_1e0c0_1e1d4\n"
        END);
}

/* body 0x1e200 until 0x1e2b5 */
BODY void apw_1e200(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "push rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [rcx + 0x68], 0\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "apw_mov64_load reg_r14, reg_rdx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "je .L_1e200_1e228\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a3d0]\n"
        ".L_1e200_1e228:\n"
        "mov qword ptr [rsp + 0x40], rbp\n"
        "mov qword ptr [rsp + 0x48], rsi\n"
        "apw_mov64_load reg_rsi, reg_rbx\n"
        "call qword ptr [rip + rva_3a3f0]\n"
        "apw_mov64_load reg_rbp, reg_rax\n"
        "test rbx, rbx\n"
        "jle .L_1e200_1e29c\n"
        "test rax, rax\n"
        "jle .L_1e200_1e27c\n"
        "apw_cmp64_load reg_rbx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "cmovl rbp, rbx\n"
        "call qword ptr [rip + rva_3a440]\n"
        "apw_mov64_load reg_r8, reg_rbp\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_362a4\n"
        "apw_mov32_load reg_edx, reg_ebp\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "apw_add64_load reg_r14, reg_rbp\n"
        "apw_sub64_load reg_rbx, reg_rbp\n"
        "call qword ptr [rip + rva_3a400]\n"
        "test rbx, rbx\n"
        "jle .L_1e200_1e29c\n"
        ".L_1e200_1e27c:\n"
        "mov r9, qword ptr [rdi + 0x80]\n"
        "test r9, r9\n"
        "je .L_1e200_1e29c\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "mov edx, 1\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_3a828]\n"
        "apw_sub64_load reg_rbx, reg_rax\n"
        ".L_1e200_1e29c:\n"
        "mov rbp, qword ptr [rsp + 0x40]\n"
        "apw_sub64_load reg_rsi, reg_rbx\n"
        "apw_mov64_load reg_rax, reg_rsi\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1f210 until 0x1f255 */
BODY void apw_1f210(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "mov qword ptr [rsp + 0x18], r8\n"
        "mov qword ptr [rsp + 0x20], r9\n"
        "push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "lea rsi, [rsp + 0x60]\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call rva_1cd0\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "mov rcx, qword ptr [rax]\n"
        "call qword ptr [rip + rva_3a848]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1f260 until 0x1f2b5 */
BODY void apw_1f260(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rcx\n"
        "mov qword ptr [rsp + 0x10], rdx\n"
        "mov qword ptr [rsp + 0x18], r8\n"
        "mov qword ptr [rsp + 0x20], r9\n"
        "push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "lea rsi, [rsp + 0x58]\n"
        "mov ecx, 1\n"
        "call qword ptr [rip + rva_3a850]\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "call rva_1cd0\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "mov rcx, qword ptr [rax]\n"
        "call qword ptr [rip + rva_3a848]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1f2c0 until 0x1f32d */
BODY void apw_1f2c0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rax, reg_r8\n"
        "apw_mov64_load reg_r9, reg_rdx\n"
        "mov r8, 0xffffffffffffffff\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_xor32_load reg_edi, reg_edi\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".L_1f2c0_1f2e0:\n"
        "inc r8\n"
        "cmp byte ptr [rax + r8], dil\n"
        "jne .L_1f2c0_1f2e0\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_r9\n"
        "call rva_24e40\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbx], xmm0\n"
        "mov qword ptr [rbx + 0x10], rdi\n"
        "mov qword ptr [rbx + 0x18], rdi\n"
        "movups xmm0, xmmword ptr [rax]\n"
        "movups xmmword ptr [rbx], xmm0\n"
        "movups xmm1, xmmword ptr [rax + 0x10]\n"
        "movups xmmword ptr [rbx + 0x10], xmm1\n"
        "mov qword ptr [rax + 0x10], rdi\n"
        "mov qword ptr [rax + 0x18], 0xf\n"
        "mov byte ptr [rax], dil\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1f330 until 0x1f46e */
BODY void apw_1f330(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "lea rax, [rip + rva_41408]\n"
        "mov qword ptr [rcx], rax\n"
        "apw_xor32_load reg_esi, reg_esi\n"
        "mov qword ptr [rcx + 8], rsi\n"
        "mov qword ptr [rcx + 0x10], rsi\n"
        "mov qword ptr [rcx + 0x18], rsi\n"
        "mov qword ptr [rcx + 0x20], rsi\n"
        "mov qword ptr [rcx + 0x28], rsi\n"
        "mov qword ptr [rcx + 0x30], rsi\n"
        "mov qword ptr [rcx + 0x38], rsi\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rcx + 0x40], xmm0\n"
        "mov qword ptr [rcx + 0x50], rsi\n"
        "mov qword ptr [rcx + 0x58], 0xf\n"
        "mov byte ptr [rcx + 0x40], sil\n"
        "movups xmmword ptr [rcx + 0x60], xmm0\n"
        "mov qword ptr [rcx + 0x70], rsi\n"
        "mov qword ptr [rcx + 0x78], 0xf\n"
        "mov byte ptr [rcx + 0x60], sil\n"
        "movups xmmword ptr [rcx + 0x80], xmm0\n"
        "mov qword ptr [rcx + 0x90], rsi\n"
        "mov qword ptr [rcx + 0x98], 0xf\n"
        "mov byte ptr [rcx + 0x80], sil\n"
        "add rcx, 0xa0\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov dword ptr [rdi + 0xa8], esi\n"
        "mov byte ptr [rdi + 0xac], sil\n"
        "mov qword ptr [rdi + 0xb0], rsi\n"
        "mov dword ptr [rdi + 0xbc], esi\n"
        "mov dword ptr [rdi + 0xc4], esi\n"
        "mov byte ptr [rdi + 0xc8], sil\n"
        "lea rbx, [rdi + 0xd0]\n"
        "mov qword ptr [rsp + 0x38], rbx\n"
        "mov qword ptr [rbx], rsi\n"
        "mov qword ptr [rbx + 8], rsi\n"
        "lea ecx, [rsi + 0x50]\n"
        "call rva_34f86\n"
        "mov qword ptr [rax], rax\n"
        "mov qword ptr [rax + 8], rax\n"
        "mov qword ptr [rax + 0x10], rax\n"
        "mov word ptr [rax + 0x18], 0x101\n"
        "mov qword ptr [rbx], rax\n"
        "lea rbx, [rdi + 0xe0]\n"
        "mov qword ptr [rsp + 0x38], rbx\n"
        "mov qword ptr [rbx], rsi\n"
        "mov qword ptr [rbx + 8], rsi\n"
        "lea ecx, [rsi + 0x50]\n"
        "call rva_34f86\n"
        "mov qword ptr [rax], rax\n"
        "mov qword ptr [rax + 8], rax\n"
        "mov qword ptr [rax + 0x10], rax\n"
        "mov word ptr [rax + 0x18], 0x101\n"
        "mov qword ptr [rbx], rax\n"
        "lea rcx, [rdi + 0xf0]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x1f470 until 0x1f49a */
BODY void apw_1f470(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "mov r8, qword ptr [rcx]\n"
        "apw_mov64_load reg_rdx, reg_rcx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov r8, qword ptr [r8 + 8]\n"
        "call rva_7ae0\n"
        "mov rcx, qword ptr [rbx]\n"
        "mov edx, 0x50\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "jmp rva_35134\n"
        END);
}

/* body 0x1f770 until 0x1f842 */
BODY void apw_1f770(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x160\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x150], rax\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov32_load reg_ebx, reg_r8d\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "apw_mov32_load reg_edx, reg_r8d\n"
        "call qword ptr [rip + rva_3a700]\n"
        "test eax, eax\n"
        "jne .L_1f770_1f807\n"
        "cmp ebx, 2\n"
        "jne .L_1f770_1f807\n"
        "lea r9, [rsp + 0x40]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_40a74]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a270]\n"
        "mov qword ptr [rsp + 0x30], 0\n"
        "lea rcx, [rsp + 0x40]\n"
        "mov dword ptr [rsp + 0x28], 0x100\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "mov edx, 0x40000000\n"
        "call qword ptr [rip + rva_3a248]\n"
        "cmp rax, -1\n"
        "jne .L_1f770_1f82a\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a238]\n"
        "lea rcx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_3a278]\n"
        ".L_1f770_1f807:\n"
        "mov al, 1\n"
        ".L_1f770_1f809:\n"
        "mov rcx, qword ptr [rsp + 0x150]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x170]\n"
        "add rsp, 0x160\n"
        "pop rdi\n"
        "ret\n"
        ".L_1f770_1f82a:\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a238]\n"
        "lea rcx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "apw_xor8_load reg_al, reg_al\n"
        "jmp .L_1f770_1f809\n"
        END);
}

/* body 0x1f850 until 0x1f876 */
BODY void apw_1f850(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "jne .L_1f850_1f86a\n"
        "mov eax, 0x80004005\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_1f850_1f86a:\n"
        "call rva_9360\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x1f880 until 0x1f948 */
BODY void apw_1f880(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "mov r8d, 1\n"
        "lea rdx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aa40]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rip + rva_409c4]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3aa88]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "test ebx, ebx\n"
        "jne .L_1f880_1f8f6\n"
        "mov rax, qword ptr [rdi]\n"
        "mov r8d, dword ptr [rax - 0x10]\n"
        "dec r8d\n"
        "lea rdx, [rsp + 0x38]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_1f880_1f8f6:\n"
        "mov rcx, qword ptr [rdi]\n"
        "call qword ptr [rip + rva_3a240]\n"
        "cmp eax, -1\n"
        "jne .L_1f880_1f934\n"
        "mov dl, 0x5c\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_r8d, reg_eax\n"
        "lea rdx, [rsp + 0x38]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_1f880\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov rcx, qword ptr [rdi]\n"
        "call qword ptr [rip + rva_3a250]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_1f880_1f934:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3aab8]\n"
        END);
}

/* body 0x1f9f0 until 0x1f9fa */
BODY void apw_1f9f0(void) {
    __asm__(INTEL
        "mov byte ptr [rcx + 0x374], 1\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "ret\n"
        END);
}

/* body 0x1fa00 until 0x1fa5d */
BODY void apw_1fa00(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "cmp qword ptr [rcx + 0xc8], 0\n"
        "jne .L_1fa00_1fa1e\n"
        "mov eax, 0x80004005\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        ".L_1fa00_1fa1e:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a9b0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_3aac8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "call rva_bd10\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1fa60 until 0x1fa99 */
BODY void apw_1fa60(void) {
    __asm__(INTEL
        "sub rsp, 0x38\n"
        "mov rcx, qword ptr [rcx + 0xc0]\n"
        "test rcx, rcx\n"
        "je .L_1fa60_1fa8f\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ff\n"
        "call rva_3433f\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x38\n"
        "ret\n"
        ".L_1fa60_1fa8f:\n"
        "mov eax, 0x80004005\n"
        "add rsp, 0x38\n"
        "ret\n"
        END);
}

/* body 0x1faa0 until 0x1facd */
BODY void apw_1faa0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_1faa0_1fac3\n"
        "call rva_119a0\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "test al, al\n"
        "sete cl\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_1faa0_1fac3:\n"
        "mov eax, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x1fad0 until 0x1fb2e */
BODY void apw_1fad0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [rip + rva_54050], 0\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "jne .L_1fad0_1fb26\n"
        "call rva_20c90\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov qword ptr [rip + rva_54050], rbx\n"
        "call rva_33eb0\n"
        "call qword ptr [rip + rva_3a068]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov qword ptr [rip + rva_54048], rax\n"
        "call rva_34fe0\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "call rva_34954\n"
        "call rva_3418d\n"
        "call rva_349df\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_34fe0\n"
        ".L_1fad0_1fb26:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1fc40 until 0x1fdec */
BODY void apw_1fc40(void) {
    __asm__(INTEL
        "apw_mov64_load reg_r11, reg_rsp\n"
        "push rbx\n"
        "sub rsp, 0x170\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x160], rax\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_1fc40_1fdd1\n"
        "mov rcx, qword ptr [rcx + 0xb0]\n"
        "mov qword ptr [r11 + 0x10], rsi\n"
        "mov qword ptr [r11 + 0x18], rdi\n"
        "call rva_3493c\n"
        "cmp qword ptr [rbx + 0xd0], 0\n"
        "je .L_1fc40_1fcf5\n"
        "mov byte ptr [rbx + 0x37c], 0\n"
        "call rva_343dc\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "mov r8d, 0x3f4\n"
        "call rva_3433f\n"
        "cmp byte ptr [rbx + 0x37c], 0\n"
        "jne .L_1fc40_1fcf5\n"
        ".L_1fc40_1fcc2:\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rcx, [rsp + 0x30]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "call qword ptr [rip + rva_3a5f0]\n"
        "test eax, eax\n"
        "je .L_1fc40_1fcec\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a5e8]\n"
        ".L_1fc40_1fcec:\n"
        "cmp byte ptr [rbx + 0x37c], 0\n"
        "je .L_1fc40_1fcc2\n"
        ".L_1fc40_1fcf5:\n"
        "call rva_343dc\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "add rcx, 0x60\n"
        "cmp qword ptr [rcx + 0x18], 0x10\n"
        "jb .L_1fc40_1fd0f\n"
        "mov rcx, qword ptr [rcx]\n"
        ".L_1fc40_1fd0f:\n"
        "call qword ptr [rip + rva_3a8b0]\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "call rva_118b0\n"
        "mov rdi, qword ptr [rbx + 0xc8]\n"
        "test rdi, rdi\n"
        "je .L_1fc40_1fd45\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_8cd0\n"
        "mov edx, 0xf8\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        ".L_1fc40_1fd45:\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "mov qword ptr [rbx + 0xc8], 0\n"
        "je .L_1fc40_1fdb8\n"
        "cmp byte ptr [rbx + 0xe9], 0\n"
        "je .L_1fc40_1fdb8\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov qword ptr [rsp + 0x20], 0\n"
        "lea r8, [rsp + 0x60]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "lea rdx, [rbx + 0x1ef]\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "mov r8d, 0x100\n"
        "lea rdx, [rsp + 0x60]\n"
        "lea rcx, [rbx + 0x1ef]\n"
        "call qword ptr [rip + rva_3a8d0]\n"
        "mov rax, 0xffffffffffffffff\n"
        ".L_1fc40_1fda2:\n"
        "cmp byte ptr [rbx + rax + 0x1f0], 0\n"
        "lea rax, [rax + 1]\n"
        "jne .L_1fc40_1fda2\n"
        "mov byte ptr [rax + rbx + 0x1ee], 0\n"
        ".L_1fc40_1fdb8:\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3a728]\n"
        "mov rdi, qword ptr [rsp + 0x190]\n"
        "mov rsi, qword ptr [rsp + 0x188]\n"
        ".L_1fc40_1fdd1:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rcx, qword ptr [rsp + 0x160]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x170\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x1fdf0 until 0x1fdfa */
BODY void apw_1fdf0(void) {
    __asm__(INTEL
        "apw_mov32_load reg_ecx, reg_edx\n"
        "apw_mov64_load reg_rdx, reg_r8\n"
        "jmp rva_3490c\n"
        END);
}

/* body 0x202d0 until 0x203d0 */
BODY void apw_202d0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rbp\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "cmp qword ptr [rcx + 0xc8], 0\n"
        "je .L_202d0_202fb\n"
        "mov eax, 0x80004005\n"
        "jmp .L_202d0_203bb\n"
        ".L_202d0_202fb:\n"
        "call qword ptr [rip + rva_3a080]\n"
        "mov ecx, 0xf8\n"
        "call rva_34f86\n"
        "mov qword ptr [rsp + 0x40], rax\n"
        "apw_xor32_load reg_ebp, reg_ebp\n"
        "test rax, rax\n"
        "je .L_202d0_20321\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_1f330\n"
        "jmp .L_202d0_20324\n"
        ".L_202d0_20321:\n"
        "apw_mov64_load reg_rax, reg_rbp\n"
        ".L_202d0_20324:\n"
        "mov qword ptr [rbx + 0xc8], rax\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_128b0\n"
        "mov edi, 0x80004005\n"
        "test al, al\n"
        "cmovne edi, ebp\n"
        "jne .L_202d0_20375\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "call rva_118b0\n"
        "mov rsi, qword ptr [rbx + 0xc8]\n"
        "test rsi, rsi\n"
        "je .L_202d0_2036c\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_8cd0\n"
        "mov edx, 0xf8\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_35134\n"
        ".L_202d0_2036c:\n"
        "mov qword ptr [rbx + 0xc8], rbp\n"
        "jmp .L_202d0_203b9\n"
        ".L_202d0_20375:\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "je .L_202d0_203b9\n"
        "cmp dword ptr [rbx + 0xe4], 0\n"
        "jne .L_202d0_203b9\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_202d0_203b9\n"
        "mov r9, qword ptr [rbx + 0xc8]\n"
        "add r9, 0x40\n"
        "cmp qword ptr [r9 + 0x18], 0x10\n"
        "jb .L_202d0_203a8\n"
        "mov r9, qword ptr [r9]\n"
        ".L_202d0_203a8:\n"
        "mov dword ptr [rsp + 0x20], ebp\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f6\n"
        "call rva_3433f\n"
        ".L_202d0_203b9:\n"
        "apw_mov32_load reg_eax, reg_edi\n"
        ".L_202d0_203bb:\n"
        "mov rbx, qword ptr [rsp + 0x48]\n"
        "mov rbp, qword ptr [rsp + 0x50]\n"
        "mov rsi, qword ptr [rsp + 0x58]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x203d0 until 0x2067e */
BODY void apw_203d0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push rdi\n"
        "sub rsp, 0x270\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x260], rax\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "cmp qword ptr [rcx + 0xc8], 0\n"
        "je .L_203d0_2040e\n"
        "mov eax, 0x80004005\n"
        "jmp .L_203d0_20659\n"
        ".L_203d0_2040e:\n"
        "call qword ptr [rip + rva_3a080]\n"
        "mov ecx, 0xf8\n"
        "call rva_34f86\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "test rax, rax\n"
        "je .L_203d0_20431\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_1f330\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_203d0_20431:\n"
        "mov qword ptr [rbx + 0xc8], rax\n"
        "test rdi, rdi\n"
        "jne .L_203d0_20447\n"
        "mov eax, 0x80070057\n"
        "jmp .L_203d0_20659\n"
        ".L_203d0_20447:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a8b0]\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "mov byte ptr [rbx + 0xe9], 0\n"
        "mov byte ptr [rsp + 0x40], 0\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "je .L_203d0_20543\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_c180\n"
        "cmp eax, 8\n"
        "jne .L_203d0_204f8\n"
        "mov byte ptr [rbx + 0xe9], 1\n"
        "lea rcx, [rbx + 0xea]\n"
        "mov r8d, 0x104\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "call qword ptr [rip + rva_3a8c0]\n"
        "mov byte ptr [rbx + 0x1ee], 0\n"
        "mov byte ptr [rsp + 0x150], 0\n"
        "lea r9, [rsp + 0x40]\n"
        "lea r8, [rsp + 0x150]\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "movzx ecx, byte ptr [rbx + 0xe0]\n"
        "call rva_30d60\n"
        "test eax, eax\n"
        "jne .L_203d0_20659\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_34f92\n"
        "lea rcx, [rsp + 0x150]\n"
        "call qword ptr [rip + rva_3a8b0]\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "lea rcx, [rip + rva_41840]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "jne .L_203d0_2051a\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "jmp .L_203d0_2050b\n"
        ".L_203d0_204f8:\n"
        "lea rcx, [rip + rva_41840]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "je .L_203d0_2051a\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        ".L_203d0_2050b:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rcx, [rip + rva_41840]\n"
        "call rva_3401f\n"
        ".L_203d0_2051a:\n"
        "lea rcx, [rip + rva_42058]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "jne .L_203d0_20543\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "cmp byte ptr [rbx + 0xe9], al\n"
        "lea rdx, [rsp + 0x40]\n"
        "jne .L_203d0_2053e\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        ".L_203d0_2053e:\n"
        "call rva_230a0\n"
        ".L_203d0_20543:\n"
        "lea rcx, [rip + rva_41840]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "je .L_203d0_20576\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "jne .L_203d0_20576\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_29cb0\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "movzx ecx, byte ptr [rbx + 0xe0]\n"
        "call rva_32500\n"
        ".L_203d0_20576:\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "call rva_12bc0\n"
        "test al, al\n"
        "jne .L_203d0_205cb\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "call rva_118b0\n"
        "mov rdi, qword ptr [rbx + 0xc8]\n"
        "test rdi, rdi\n"
        "je .L_203d0_205b6\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_8cd0\n"
        "mov edx, 0xf8\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        ".L_203d0_205b6:\n"
        "mov qword ptr [rbx + 0xc8], 0\n"
        "mov eax, 0xffffffff\n"
        "jmp .L_203d0_20659\n"
        ".L_203d0_205cb:\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "je .L_203d0_2064a\n"
        "cmp dword ptr [rbx + 0xe4], 0\n"
        "jne .L_203d0_2064a\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_203d0_2064a\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f6\n"
        "call rva_3433f\n"
        "cmp byte ptr [rbx + 0xe9], 0\n"
        "je .L_203d0_2064a\n"
        "mov dword ptr [rsp + 0x20], 2\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f6\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "call rva_3433f\n"
        "mov dword ptr [rsp + 0x20], 3\n"
        "lea r9, [rsp + 0x40]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f6\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "call rva_3433f\n"
        ".L_203d0_2064a:\n"
        "mov edx, 1\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call rva_35134\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_203d0_20659:\n"
        "mov rcx, qword ptr [rsp + 0x260]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x270]\n"
        "mov rbx, qword ptr [r11 + 0x20]\n"
        "mov rsi, qword ptr [r11 + 0x28]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x20680 until 0x207cc */
BODY void apw_20680(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "mov rcx, qword ptr [rcx + 0xd0]\n"
        "apw_mov32_load reg_edi, reg_edx\n"
        "test rcx, rcx\n"
        "je .L_20680_207b7\n"
        "cmp edx, 0x78\n"
        "jne .L_20680_206c5\n"
        "mov byte ptr [rbx + 0xe8], 1\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        ".L_20680_206c5:\n"
        "cmp edi, 0x79\n"
        "jne .L_20680_206e3\n"
        "mov byte ptr [rbx + 0xe8], 0\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        ".L_20680_206e3:\n"
        "cmp edi, 0x67\n"
        "jne .L_20680_2071b\n"
        "cmp byte ptr [rbx + 0xe8], 0\n"
        "jne .L_20680_207a5\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "call rva_3433f\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        ".L_20680_2071b:\n"
        "lea eax, [rdx - 0x66]\n"
        "cmp eax, 0x14\n"
        "ja .L_20680_20768\n"
        "mov edx, 0x10000d\n"
        "bt edx, eax\n"
        "jae .L_20680_20768\n"
        "call rva_343dc\n"
        "cmp byte ptr [rbx + 0xe8], 0\n"
        "jne .L_20680_207a5\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3ed\n"
        "call rva_3433f\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        ".L_20680_20768:\n"
        "cmp edi, 0x7b\n"
        "jne .L_20680_207a5\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "je .L_20680_207a5\n"
        "cmp dword ptr [rbx + 0xe4], 0\n"
        "je .L_20680_207a5\n"
        "lea rax, [rsp + 0x50]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov dword ptr [rsp + 0x28], 0\n"
        "mov r8d, 0x3ed\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "call rva_343ca\n"
        ".L_20680_207a5:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        ".L_20680_207b7:\n"
        "mov rbx, qword ptr [rsp + 0x58]\n"
        "mov eax, 0x80004005\n"
        "mov rsi, qword ptr [rsp + 0x60]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x207d0 until 0x208c1 */
BODY void apw_207d0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rbp\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov32_load reg_edi, reg_r9d\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "cmp qword ptr [rcx + 0xc8], 0\n"
        "je .L_207d0_20801\n"
        "mov eax, 0x80004005\n"
        "jmp .L_207d0_208ac\n"
        ".L_207d0_20801:\n"
        "call qword ptr [rip + rva_3a080]\n"
        "mov ecx, 0xf8\n"
        "call rva_34f86\n"
        "mov qword ptr [rsp + 0x40], rax\n"
        "apw_xor32_load reg_ebp, reg_ebp\n"
        "test rax, rax\n"
        "je .L_207d0_20827\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_1f330\n"
        "jmp .L_207d0_2082a\n"
        ".L_207d0_20827:\n"
        "apw_mov64_load reg_rax, reg_rbp\n"
        ".L_207d0_2082a:\n"
        "mov qword ptr [rbx + 0xc8], rax\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "je .L_207d0_20856\n"
        "lea rcx, [rip + rva_42058]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "jne .L_207d0_20856\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_230a0\n"
        ".L_207d0_20856:\n"
        "apw_mov32_load reg_r8d, reg_edi\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "call rva_13b10\n"
        "mov edi, 0x80004005\n"
        "test al, al\n"
        "cmovne edi, ebp\n"
        "je .L_207d0_208aa\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "je .L_207d0_208aa\n"
        "cmp dword ptr [rbx + 0xe4], 0\n"
        "jne .L_207d0_208aa\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_207d0_208aa\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f6\n"
        "call rva_3433f\n"
        ".L_207d0_208aa:\n"
        "apw_mov32_load reg_eax, reg_edi\n"
        ".L_207d0_208ac:\n"
        "mov rbx, qword ptr [rsp + 0x48]\n"
        "mov rbp, qword ptr [rsp + 0x50]\n"
        "mov rsi, qword ptr [rsp + 0x58]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x208d0 until 0x209df */
BODY void apw_208d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "push rsi\n"
        "sub rsp, 0x48\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "jne .L_208d0_208f5\n"
        "mov eax, 0x80004005\n"
        "add rsp, 0x48\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        ".L_208d0_208f5:\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "mov qword ptr [rsp + 0x68], rbp\n"
        "mov qword ptr [rsp + 0x70], rdi\n"
        "je .L_208d0_20932\n"
        "cmp byte ptr [rbx + 0xe9], 0\n"
        "je .L_208d0_20932\n"
        "test rsi, rsi\n"
        "jne .L_208d0_2091d\n"
        "lea rdx, [rbx + 0xea]\n"
        ".L_208d0_2091d:\n"
        "call rva_b2c0\n"
        "apw_xor32_load reg_ebp, reg_ebp\n"
        "mov ecx, 0x80004005\n"
        "test eax, eax\n"
        "apw_mov32_load reg_edi, reg_ebp\n"
        "cmove edi, ecx\n"
        "jmp .L_208d0_20991\n"
        ".L_208d0_20932:\n"
        "mov qword ptr [rsp + 0x40], r14\n"
        "call rva_33f71\n"
        "cmp byte ptr [rbx + 0xe0], 0\n"
        "apw_mov32_load reg_r14d, reg_eax\n"
        "je .L_208d0_20958\n"
        "cmp dword ptr [rbx + 0xe4], 0\n"
        "jne .L_208d0_20958\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_33ed4\n"
        ".L_208d0_20958:\n"
        "mov rcx, qword ptr [rbx + 0xc8]\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "call rva_18d40\n"
        "apw_xor32_load reg_ebp, reg_ebp\n"
        "mov edi, 0x80004005\n"
        "test al, al\n"
        "cmovne edi, ebp\n"
        "cmp byte ptr [rbx + 0xe0], bpl\n"
        "je .L_208d0_2098c\n"
        "cmp dword ptr [rbx + 0xe4], ebp\n"
        "jne .L_208d0_2098c\n"
        "apw_mov32_load reg_ecx, reg_r14d\n"
        "call rva_33ed4\n"
        ".L_208d0_2098c:\n"
        "mov r14, qword ptr [rsp + 0x40]\n"
        ".L_208d0_20991:\n"
        "test edi, edi\n"
        "jne .L_208d0_209cc\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_208d0_209cc\n"
        "cmp byte ptr [rbx + 0xe8], dil\n"
        "jne .L_208d0_209cc\n"
        "lea rax, [rsp + 0x60]\n"
        "apw_mov64_load reg_r9, reg_rsi\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov dword ptr [rsp + 0x28], ebp\n"
        "mov r8d, 0x3f7\n"
        "mov dword ptr [rsp + 0x20], ebp\n"
        "call rva_343ca\n"
        ".L_208d0_209cc:\n"
        "mov rbp, qword ptr [rsp + 0x68]\n"
        "apw_mov32_load reg_eax, reg_edi\n"
        "mov rdi, qword ptr [rsp + 0x70]\n"
        "add rsp, 0x48\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x209e0 until 0x209ed */
BODY void apw_209e0(void) {
    __asm__(INTEL
        "mov rax, qword ptr [rcx + 0xc0]\n"
        "mov qword ptr [rdx], rax\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "ret\n"
        END);
}

/* body 0x209f0 until 0x20a0a */
BODY void apw_209f0(void) {
    __asm__(INTEL
        "test rdx, rdx\n"
        "jne .L_209f0_209fb\n"
        "mov eax, 0x80070057\n"
        "ret\n"
        ".L_209f0_209fb:\n"
        "mov eax, dword ptr [rcx + 0xe4]\n"
        "neg eax\n"
        "apw_sbb32_load reg_ecx, reg_ecx\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov dword ptr [rdx], ecx\n"
        "ret\n"
        END);
}

/* body 0x20a10 until 0x20a3d */
BODY void apw_20a10(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_20a10_20a33\n"
        "call rva_124b0\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "test al, al\n"
        "sete cl\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_20a10_20a33:\n"
        "mov eax, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x20c90 until 0x20fb6 */
BODY void apw_20c90(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rdi\n"
        "sub rsp, 0x1c0\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x1b0], rax\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "call rva_235c0\n"
        "mov r8d, 0x104\n"
        "lea rdx, [rsp + 0xa0]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a310]\n"
        "lea rcx, [rsp + 0xa0]\n"
        "call qword ptr [rip + rva_3a8a8]\n"
        "lea rax, [rsp + 0xa0]\n"
        "mov rbx, 0xffffffffffffffff\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".L_20c90_20cf0:\n"
        "inc rbx\n"
        "cmp byte ptr [rax + rbx], 0\n"
        "jne .L_20c90_20cf0\n"
        "mov byte ptr [rdi + 0x37d], 1\n"
        "cmp rbx, 0xe\n"
        "jbe .L_20c90_20d4c\n"
        "lea rcx, [rsp + rbx + 0x93]\n"
        "lea rdx, [rip + rva_420a0]\n"
        "call rva_362f8\n"
        "test eax, eax\n"
        "jne .L_20c90_20d26\n"
        "mov byte ptr [rdi + 0x37d], al\n"
        "jmp .L_20c90_20d52\n"
        ".L_20c90_20d26:\n"
        "cmp rbx, 0x14\n"
        "jbe .L_20c90_20d4c\n"
        "lea rcx, [rsp + rbx + 0x8d]\n"
        "lea rdx, [rip + rva_420b0]\n"
        "call rva_362f8\n"
        "test eax, eax\n"
        "jne .L_20c90_20d4c\n"
        "mov byte ptr [rdi + 0x37d], al\n"
        "jmp .L_20c90_20d52\n"
        ".L_20c90_20d4c:\n"
        "call qword ptr [rip + rva_53368]\n"
        ".L_20c90_20d52:\n"
        "mov edx, 1\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_mov32_load reg_r8d, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a230]\n"
        "mov r8d, 1\n"
        "lea rcx, [rip + rva_420c8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov qword ptr [rip + rva_54058], rax\n"
        "call rva_3401f\n"
        "mov edx, 1\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_mov32_load reg_r8d, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a230]\n"
        "mov r8d, 1\n"
        "lea rcx, [rip + rva_420d8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov qword ptr [rip + rva_54060], rax\n"
        "call rva_3401f\n"
        "mov rcx, qword ptr [rip + rva_54060]\n"
        "call rva_34260\n"
        "call qword ptr [rip + rva_3a210]\n"
        "mov dword ptr [rdi + 0x378], eax\n"
        "call qword ptr [rip + rva_3a218]\n"
        "mov r8d, 1\n"
        "lea rcx, [rip + rva_420e8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "call rva_3401f\n"
        "mov edx, 1\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_mov32_load reg_r8d, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a230]\n"
        "mov r8d, 1\n"
        "lea rcx, [rip + rva_420f8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov qword ptr [rip + rva_54068], rax\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_25070]\n"
        "lea rcx, [rip + rva_42108]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_25350]\n"
        "lea rcx, [rip + rva_42118]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_25390]\n"
        "lea rcx, [rip + rva_42128]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_252a0]\n"
        "lea rcx, [rip + rva_42138]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_25230]\n"
        "lea rcx, [rip + rva_42148]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_25260]\n"
        "lea rcx, [rip + rva_42158]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_25310]\n"
        "lea rcx, [rip + rva_42168]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_24db0]\n"
        "lea rcx, [rip + rva_42178]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_1d40]\n"
        "lea rcx, [rip + rva_42188]\n"
        "call rva_3401f\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_24de0]\n"
        "lea rcx, [rip + rva_42198]\n"
        "call rva_3401f\n"
        "lea rcx, [rip + rva_421a8]\n"
        "call qword ptr [rip + rva_3a5d0]\n"
        "apw_mov32_load reg_edx, reg_eax\n"
        "lea rcx, [rip + rva_421a8]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "call rva_3401f\n"
        "mov ecx, 1\n"
        "call rva_33ed4\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_347cd\n"
        "call rva_33bd0\n"
        "cmp eax, 2\n"
        "lea rdx, [rip + rva_42010]\n"
        "lea rcx, [rip + rva_41ff0]\n"
        "mov r8d, 0x28\n"
        "cmove rcx, rdx\n"
        "lea rdx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3ab70]\n"
        "lea rax, [rsp + 0x28]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rsp + 0x50]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea rcx, [rsp + 0x20]\n"
        "call rva_20a40\n"
        "mov rcx, qword ptr [rsp + 0x20]\n"
        "call rva_34272\n"
        "mov rcx, qword ptr [rsp + 0x20]\n"
        "lea rax, [rsp + 0x28]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "je .L_20c90_20f83\n"
        "call qword ptr [rip + rva_3a728]\n"
        ".L_20c90_20f83:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "lea rcx, [rdi + 8]\n"
        "test rdi, rdi\n"
        "cmove rcx, rax\n"
        "call rva_34109\n"
        "mov rcx, qword ptr [rsp + 0x1b0]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x1d8]\n"
        "add rsp, 0x1c0\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x22f10 until 0x22f4e */
BODY void apw_22f10(void) {
    __asm__(INTEL
        "sub rsp, 0x38\n"
        "mov rcx, qword ptr [rcx + 0xc0]\n"
        "test rcx, rcx\n"
        "je .L_22f10_22f44\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "mov r8d, 0x3fa\n"
        "lea rdx, [rip + rva_42450]\n"
        "call rva_3433f\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x38\n"
        "ret\n"
        ".L_22f10_22f44:\n"
        "mov eax, 0x80004005\n"
        "add rsp, 0x38\n"
        "ret\n"
        END);
}

/* body 0x23000 until 0x23041 */
BODY void apw_23000(void) {
    __asm__(INTEL
        "sub rsp, 0x38\n"
        "test edx, edx\n"
        "jne .L_23000_23012\n"
        "mov eax, 0x80004001\n"
        "add rsp, 0x38\n"
        "ret\n"
        ".L_23000_23012:\n"
        "mov rcx, qword ptr [rcx + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_23000_2303a\n"
        "lea r9, [rip + rva_42080]\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f8\n"
        "call rva_3433f\n"
        ".L_23000_2303a:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x38\n"
        "ret\n"
        END);
}

/* body 0x23050 until 0x2309b */
BODY void apw_23050(void) {
    __asm__(INTEL
        "sub rsp, 0x38\n"
        "test edx, edx\n"
        "jne .L_23050_23062\n"
        "mov eax, 0x80004001\n"
        "add rsp, 0x38\n"
        "ret\n"
        ".L_23050_23062:\n"
        "mov rcx, qword ptr [rcx + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_23050_23091\n"
        "lea r9, [rip + rva_42070]\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f8\n"
        "call rva_3433f\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x38\n"
        "ret\n"
        ".L_23050_23091:\n"
        "mov eax, 0x80004005\n"
        "add rsp, 0x38\n"
        "ret\n"
        END);
}

/* body 0x230a0 until 0x234c0 */
BODY void apw_230a0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x18], rdi\n"
        "push rbp\n"
        "lea rbp, [rsp - 0x3b0]\n"
        "sub rsp, 0x4b0\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x3a0], rax\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea r9, [rsp + 0x40]\n"
        "lea r8, [rsp + 0x60]\n"
        "mov edx, 0x104\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a340]\n"
        "test eax, eax\n"
        "jne .L_230a0_2310f\n"
        "lea rcx, [rsp + 0x60]\n"
        "apw_sub64_load reg_rcx, reg_rbx\n"
        ".L_230a0_23101:\n"
        "movzx eax, byte ptr [rbx]\n"
        "mov byte ptr [rcx + rbx], al\n"
        "lea rbx, [rbx + 1]\n"
        "test al, al\n"
        "jne .L_230a0_23101\n"
        ".L_230a0_2310f:\n"
        "cmp byte ptr [rsp + 0x60], 0\n"
        "je .L_230a0_2332e\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3a240]\n"
        "test al, 0x10\n"
        "jne .L_230a0_23184\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        ".byte 0xf,0x1f,0x44,0x0,0x0 # alignment NOP\n"
        ".L_230a0_23130:\n"
        "movzx eax, byte ptr [rsp + rcx + 0x60]\n"
        "mov byte ptr [rbp + rcx + 0x180], al\n"
        "lea rcx, [rcx + 1]\n"
        "test al, al\n"
        "jne .L_230a0_23130\n"
        "lea r9, [rsp + 0x40]\n"
        "lea r8, [rsp + 0x60]\n"
        "mov edx, 0x104\n"
        "lea rcx, [rbp + 0x180]\n"
        "call qword ptr [rip + rva_3a340]\n"
        "test eax, eax\n"
        "je .L_230a0_23171\n"
        "mov rax, qword ptr [rsp + 0x40]\n"
        "test rax, rax\n"
        "je .L_230a0_23171\n"
        "mov byte ptr [rax], 0\n"
        ".L_230a0_23171:\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3a240]\n"
        "test al, 0x10\n"
        "je .L_230a0_23204\n"
        ".L_230a0_23184:\n"
        "mov r8d, 2\n"
        "lea rdx, [rsp + 0x60]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_1f770\n"
        "test al, al\n"
        "jne .L_230a0_23204\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_53248]\n"
        "test eax, eax\n"
        "jne .L_230a0_23204\n"
        "lea r8d, [rax + 2]\n"
        "lea rdx, [rip + rva_42448]\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3a8e8]\n"
        "test eax, eax\n"
        "je .L_230a0_2348c\n"
        "mov r8d, 2\n"
        "lea rdx, [rip + rva_4244c]\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3a8e8]\n"
        "test eax, eax\n"
        "je .L_230a0_2348c\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3a258]\n"
        "test eax, eax\n"
        "je .L_230a0_2332e\n"
        "mov bl, 1\n"
        "jmp .L_230a0_2348e\n"
        ".L_230a0_23204:\n"
        "lea r8, [rip + rva_3ad3b]\n"
        "lea rdx, [rip + rva_41e70]\n"
        "lea rcx, [rip + rva_41bf0]\n"
        "call qword ptr [rip + rva_53448]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3ab20]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3ab30]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_53388]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "jne .L_230a0_232b9\n"
        "lea rax, [rbp + 0x70]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea edx, [r9 + 5]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a570]\n"
        "test eax, eax\n"
        "js .L_230a0_232ae\n"
        "call rva_33bc0\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "lea r8, [rbp + 0x70]\n"
        "lea rdx, [rip + rva_42298]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "lea rdx, [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aac8]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_1f880\n"
        ".L_230a0_232ae:\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "je .L_230a0_2332e\n"
        ".L_230a0_232b9:\n"
        "lea r9, [rsp + 0x40]\n"
        "lea r8, [rsp + 0x60]\n"
        "mov edx, 0x104\n"
        "call qword ptr [rip + rva_3a340]\n"
        "test eax, eax\n"
        "je .L_230a0_232e2\n"
        "lea rdx, [rsp + 0x60]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        ".L_230a0_232e2:\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a240]\n"
        "test al, 0x10\n"
        "je .L_230a0_2332e\n"
        "mov r8d, 2\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_1f770\n"
        "test al, al\n"
        "jne .L_230a0_2332e\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_53248]\n"
        "test eax, eax\n"
        "jne .L_230a0_2332e\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a258]\n"
        "test eax, eax\n"
        "setne bl\n"
        "jmp .L_230a0_2348e\n"
        ".L_230a0_2332e:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea r8, [rip + rva_3ad3b]\n"
        "lea rdx, [rip + rva_41e70]\n"
        "lea rcx, [rip + rva_41bf0]\n"
        "call qword ptr [rip + rva_53448]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "je .L_230a0_2339a\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3ab20]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3ab30]\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_53388]\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "jne .L_230a0_233ff\n"
        ".L_230a0_2339a:\n"
        "lea rax, [rbp + 0x70]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov edx, 0x8005\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a570]\n"
        "test eax, eax\n"
        "js .L_230a0_233f0\n"
        "call rva_33bc0\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "lea r8, [rbp + 0x70]\n"
        "lea rdx, [rip + rva_42298]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "lea rdx, [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call qword ptr [rip + rva_3aac8]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_1f880\n"
        ".L_230a0_233f0:\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "je .L_230a0_23481\n"
        ".L_230a0_233ff:\n"
        "lea r9, [rsp + 0x50]\n"
        "lea r8, [rbp + 0x290]\n"
        "mov edx, 0x104\n"
        "call qword ptr [rip + rva_3a340]\n"
        "test eax, eax\n"
        "je .L_230a0_2342c\n"
        "lea rdx, [rbp + 0x290]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        ".L_230a0_2342c:\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a240]\n"
        "test al, 0x10\n"
        "je .L_230a0_23481\n"
        "mov r8d, 2\n"
        "mov rdx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_1f770\n"
        "test al, al\n"
        "jne .L_230a0_23481\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_53248]\n"
        "test eax, eax\n"
        "jne .L_230a0_23481\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a258]\n"
        "test eax, eax\n"
        "je .L_230a0_23481\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov bl, 1\n"
        "jmp .L_230a0_2348e\n"
        ".L_230a0_23481:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_230a0_2348c:\n"
        "apw_xor8_load reg_bl, reg_bl\n"
        ".L_230a0_2348e:\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "movzx eax, bl\n"
        "mov rcx, qword ptr [rbp + 0x3a0]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "lea r11, [rsp + 0x4b0]\n"
        "mov rbx, qword ptr [r11 + 0x10]\n"
        "mov rdi, qword ptr [r11 + 0x20]\n"
        "apw_mov64_load reg_rsp, reg_r11\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x234c0 until 0x235b2 */
BODY void apw_234c0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rdi\n"
        "sub rsp, 0x70\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov32_load reg_edi, reg_edx\n"
        "mov rcx, qword ptr [rcx + 0xd0]\n"
        "test rcx, rcx\n"
        "jne .L_234c0_234ee\n"
        "mov eax, 0x80004005\n"
        "mov rbx, qword ptr [rsp + 0x88]\n"
        "add rsp, 0x70\n"
        "pop rdi\n"
        "ret\n"
        ".L_234c0_234ee:\n"
        "mov eax, dword ptr [rbx + 0xe4]\n"
        "test edi, edi\n"
        "je .L_234c0_2354a\n"
        "test eax, eax\n"
        "jne .L_234c0_23570\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f5\n"
        "call rva_3433f\n"
        "mov rcx, qword ptr [rbx + 0xd0]\n"
        "lea rax, [rsp + 0x80]\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov dword ptr [rsp + 0x28], 0\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "mov dword ptr [rsp + 0x20], 0x7b\n"
        "call rva_343ca\n"
        "jmp .L_234c0_23570\n"
        ".L_234c0_2354a:\n"
        "test eax, eax\n"
        "je .L_234c0_23570\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov byte ptr [rbx + 0xe1], 1\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "mov r8d, 0x3f5\n"
        "call rva_3433f\n"
        ".byte 0xf,0x1f,0x0 # alignment NOP\n"
        ".L_234c0_23570:\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov dword ptr [rsp + 0x20], 1\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rcx, [rsp + 0x40]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "call qword ptr [rip + rva_3a5f0]\n"
        "test eax, eax\n"
        "je .L_234c0_2359a\n"
        "lea rcx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_3a5e8]\n"
        ".L_234c0_2359a:\n"
        "cmp dword ptr [rbx + 0xe4], edi\n"
        "jne .L_234c0_23570\n"
        "mov rbx, qword ptr [rsp + 0x88]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x70\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x24de0 until 0x24e35 */
BODY void apw_24de0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_54050]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "mov dword ptr [rax + 0xe4], 0\n"
        "mov byte ptr [rax + 0xe0], 1\n"
        "call rva_33ed4\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_527f4]\n"
        "lea rcx, [rip + rva_42438]\n"
        "call rva_3401f\n"
        "mov ecx, 1\n"
        "call rva_347cd\n"
        "call rva_33e8c\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "add rsp, 0x28\n"
        "jmp rva_33e9e\n"
        END);
}

/* body 0x24e40 until 0x24ec3 */
BODY void apw_24e40(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "mov rcx, qword ptr [rcx + 0x10]\n"
        "mov r8, qword ptr [rdi + 0x18]\n"
        "apw_mov64_load reg_rax, reg_r8\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "apw_cmp64_load reg_rsi, reg_rax\n"
        "ja .L_24e40_24ea2\n"
        "mov qword ptr [rsp + 0x40], rbx\n"
        "lea rax, [rcx + rsi]\n"
        "mov qword ptr [rdi + 0x10], rax\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "cmp r8, 0x10\n"
        "jb .L_24e40_24e7c\n"
        "mov rax, qword ptr [rdi]\n"
        ".L_24e40_24e7c:\n"
        "lea rbx, [rax + rcx]\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_362d4\n"
        "mov byte ptr [rbx + rsi], 0\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        ".L_24e40_24ea2:\n"
        "apw_mov64_load reg_r9, reg_rdx\n"
        "mov qword ptr [rsp + 0x20], rsi\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_7e40\n"
        "mov rsi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x24f10 until 0x25006 */
BODY void apw_24f10(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rsi\n"
        "push rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [rdx + 0x18], 0x10\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "jb .L_24f10_24f26\n"
        "mov rsi, qword ptr [rdx]\n"
        ".L_24f10_24f26:\n"
        "cmp qword ptr [rcx + 0x18], 0x10\n"
        "apw_mov64_load reg_r14, reg_rcx\n"
        "jb .L_24f10_24f33\n"
        "mov r14, qword ptr [rcx]\n"
        ".L_24f10_24f33:\n"
        "mov rdi, qword ptr [rdx + 0x10]\n"
        "mov rdx, qword ptr [rcx + 0x10]\n"
        "apw_cmp64_load reg_rdi, reg_rdx\n"
        "ja .L_24f10_24ff6\n"
        "apw_sub64_load reg_rdx, reg_rdi\n"
        "apw_cmp64_load reg_r8, reg_rdx\n"
        "ja .L_24f10_24ff6\n"
        "test rdi, rdi\n"
        "jne .L_24f10_24f61\n"
        "apw_mov64_load reg_rax, reg_r8\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rsi\n"
        "ret\n"
        ".L_24f10_24f61:\n"
        "lea rcx, [r14 + r8]\n"
        "mov qword ptr [rsp + 0x40], rbx\n"
        "mov qword ptr [rsp + 0x48], rbp\n"
        "lea rbp, [rdx + r14]\n"
        "mov qword ptr [rsp + 0x50], r15\n"
        "lea r8, [rbp + 1]\n"
        "movsx r15d, byte ptr [rsi]\n"
        "apw_sub64_load reg_r8, reg_rcx\n"
        "apw_mov32_load reg_edx, reg_r15d\n"
        "call rva_362c8\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "test rax, rax\n"
        "je .L_24f10_24fcf\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_24f10_24fa0:\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_362ce\n"
        "test eax, eax\n"
        "je .L_24f10_24fee\n"
        "inc rbx\n"
        "lea r8, [rbp + 1]\n"
        "apw_sub64_load reg_r8, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "apw_mov32_load reg_edx, reg_r15d\n"
        "call rva_362c8\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "test rax, rax\n"
        "jne .L_24f10_24fa0\n"
        ".L_24f10_24fcf:\n"
        "mov rax, 0xffffffffffffffff\n"
        ".L_24f10_24fd6:\n"
        "mov rbp, qword ptr [rsp + 0x48]\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "mov r15, qword ptr [rsp + 0x50]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rsi\n"
        "ret\n"
        ".L_24f10_24fee:\n"
        "apw_sub64_load reg_rbx, reg_r14\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "jmp .L_24f10_24fd6\n"
        ".L_24f10_24ff6:\n"
        "mov rax, 0xffffffffffffffff\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rsi\n"
        "ret\n"
        END);
}

/* body 0x25010 until 0x2502a */
BODY void apw_25010(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "call qword ptr [rip + rva_3a220]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x25030 until 0x25066 */
BODY void apw_25030(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "test rdx, rdx\n"
        "je .L_25030_2505e\n"
        "call rva_33bd0\n"
        "cmp eax, 2\n"
        "lea rdx, [rip + rva_42000]\n"
        "lea rcx, [rip + rva_41fe0]\n"
        "cmove rcx, rdx\n"
        "movups xmm0, xmmword ptr [rcx]\n"
        "movups xmmword ptr [rbx], xmm0\n"
        ".L_25030_2505e:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x25260 until 0x25299 */
BODY void apw_25260(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_54050]\n"
        "apw_mov32_load reg_edx, reg_ecx\n"
        "test rax, rax\n"
        "je .L_25260_25292\n"
        "mov rcx, qword ptr [rax + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_25260_25292\n"
        "mov rcx, qword ptr [rcx + 0xb0]\n"
        "call rva_34924\n"
        "movzx eax, al\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_25260_25292:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x252a0 until 0x25306 */
BODY void apw_252a0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [rip + rva_54050]\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "test rax, rax\n"
        "je .L_252a0_25300\n"
        "cmp qword ptr [rax + 0xc8], 0\n"
        "je .L_252a0_25300\n"
        "call qword ptr [rip + rva_3a210]\n"
        "mov rcx, qword ptr [rip + rva_54050]\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "cmp dword ptr [rcx + 0x378], eax\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "mov rcx, qword ptr [rcx + 0xb0]\n"
        "jne .L_252a0_252ef\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "jmp rva_34930\n"
        ".L_252a0_252ef:\n"
        "mov r8, qword ptr [rip + rva_54068]\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "jmp rva_3492a\n"
        ".L_252a0_25300:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x25310 until 0x2534e */
BODY void apw_25310(void) {
    __asm__(INTEL
        "sub rsp, 0x38\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "mov rcx, qword ptr [rip + rva_54050]\n"
        "test rcx, rcx\n"
        "je .L_25310_25349\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_25310_25349\n"
        "mov rcx, qword ptr [rcx + 0xb0]\n"
        "mov qword ptr [rsp + 0x20], r9\n"
        "apw_mov64_load reg_r9, reg_r8\n"
        "apw_mov64_load reg_r8, reg_rdx\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "call rva_34936\n"
        ".L_25310_25349:\n"
        "add rsp, 0x38\n"
        "ret\n"
        END);
}

/* body 0x25350 until 0x25389 */
BODY void apw_25350(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_54050]\n"
        "apw_mov32_load reg_edx, reg_ecx\n"
        "test rax, rax\n"
        "je .L_25350_25382\n"
        "mov rcx, qword ptr [rax + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_25350_25382\n"
        "mov rcx, qword ptr [rcx + 0xb0]\n"
        "call rva_34912\n"
        "movzx eax, al\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_25350_25382:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x253c0 until 0x253f2 */
BODY void apw_253c0(void) {
    __asm__(INTEL
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "je .L_253c0_253f1\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        ".L_253c0_253d5:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "add rbx, 8\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "jne .L_253c0_253d5\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        ".L_253c0_253f1:\n"
        "ret\n"
        END);
}

/* body 0x25630 until 0x25691 */
BODY void apw_25630(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov qword ptr [rsp + 0x20], r8\n"
        "mov qword ptr [rsp + 0x28], r8\n"
        "mov qword ptr [rsp + 0x30], r9\n"
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "je .L_25630_2567e\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".L_25630_25660:\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aac8]\n"
        "add rdi, 8\n"
        "mov qword ptr [rsp + 0x28], rdi\n"
        "add rbx, 8\n"
        "apw_cmp64_load reg_rbx, reg_rsi\n"
        "jne .L_25630_25660\n"
        ".L_25630_2567e:\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "mov rbx, qword ptr [rsp + 0x50]\n"
        "mov rsi, qword ptr [rsp + 0x58]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x256a0 until 0x256d7 */
BODY void apw_256a0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rcx], xmm0\n"
        "mov qword ptr [rcx + 0x10], rax\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov qword ptr [rcx + 0x18], rax\n"
        "mov r8, 0xffffffffffffffff\n"
        ".L_256a0_256c0:\n"
        "inc r8\n"
        "cmp byte ptr [rdx + r8], al\n"
        "jne .L_256a0_256c0\n"
        "call rva_6e90\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x25840 until 0x2587c */
BODY void apw_25840(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "xorps xmm0, xmm0\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rax + 8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "lea rax, [rip + rva_424b8]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x25880 until 0x258c7 */
BODY void apw_25880(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov byte ptr [rsp + 0x28], 1\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "xorps xmm0, xmm0\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rsp + 0x20]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "lea rax, [rip + rva_424b8]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x30\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x258d0 until 0x2590c */
BODY void apw_258d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "lea rcx, [rip + rva_41358]\n"
        "xorps xmm0, xmm0\n"
        "lea rdx, [rbx + 8]\n"
        "mov qword ptr [rbx], rcx\n"
        "lea rcx, [rax + 8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "call rva_362b6\n"
        "lea rax, [rip + rva_424a0]\n"
        "mov qword ptr [rbx], rax\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x25910 until 0x25943 */
BODY void apw_25910(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "mov rdi, qword ptr [rcx + 8]\n"
        "mov rbx, qword ptr [rcx]\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "je .L_25910_25938\n"
        ".L_25910_25926:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "add rbx, 8\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "jne .L_25910_25926\n"
        ".L_25910_25938:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x260d0 until 0x2614e */
BODY void apw_260d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov edx, 0x102\n"
        "lea r8d, [rdx + 0x7e]\n"
        "call qword ptr [rip + rva_3a868]\n"
        "test eax, eax\n"
        "jg .L_260d0_2613b\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x597\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rsp + 0x38]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        ".L_260d0_2613b:\n"
        "apw_mov32_load reg_ecx, reg_eax\n"
        "call qword ptr [rip + rva_3a858]\n"
        "mov eax, 1\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x26330 until 0x26564 */
BODY void apw_26330(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rdi\n"
        "sub rsp, 0x390\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x380], rax\n"
        "lea rdx, [rsp + 0x270]\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "apw_sub64_load reg_rdx, reg_rcx\n"
        ".byte 0xf,0x1f,0x0 # alignment NOP\n"
        ".L_26330_26360:\n"
        "movzx eax, byte ptr [rcx]\n"
        "mov byte ptr [rdx + rcx], al\n"
        "lea rcx, [rcx + 1]\n"
        "test al, al\n"
        "jne .L_26330_26360\n"
        "lea rcx, [rsp + 0x270]\n"
        "dec rcx\n"
        ".byte 0xf,0x1f,0x80,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_26380:\n"
        "cmp byte ptr [rcx + 1], 0\n"
        "lea rcx, [rcx + 1]\n"
        "jne .L_26330_26380\n"
        "movzx eax, word ptr [rip + rva_41ed0]\n"
        "lea rdx, [rsp + 0x160]\n"
        "mov word ptr [rcx], ax\n"
        "apw_sub64_load reg_rdx, reg_rdi\n"
        "movzx eax, byte ptr [rip + rva_41ed2]\n"
        "mov byte ptr [rcx + 2], al\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".L_26330_263b0:\n"
        "movzx eax, byte ptr [rcx]\n"
        "mov byte ptr [rdx + rcx], al\n"
        "lea rcx, [rcx + 1]\n"
        "test al, al\n"
        "jne .L_26330_263b0\n"
        "lea rcx, [rsp + 0x160]\n"
        "dec rcx\n"
        ".byte 0xf,0x1f,0x80,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_263d0:\n"
        "cmp byte ptr [rcx + 1], 0\n"
        "lea rcx, [rcx + 1]\n"
        "jne .L_26330_263d0\n"
        "movzx eax, word ptr [rip + rva_409c4]\n"
        "lea rdx, [rsp + 0x20]\n"
        "mov word ptr [rcx], ax\n"
        "lea rcx, [rsp + 0x270]\n"
        "call qword ptr [rip + rva_3a330]\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "cmp rax, -1\n"
        "je .L_26330_26541\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        ".byte 0x66,0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_26410:\n"
        "movzx eax, byte ptr [rsp + rcx + 0x160]\n"
        "mov byte ptr [rsp + rcx + 0x270], al\n"
        "lea rcx, [rcx + 1]\n"
        "test al, al\n"
        "jne .L_26330_26410\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_26430:\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a338]\n"
        "test eax, eax\n"
        "je .L_26330_2651c\n"
        "movzx ecx, byte ptr [rsp + 0x4c]\n"
        "movzx eax, byte ptr [rsp + 0x4d]\n"
        "cmp cl, 0x2e\n"
        "jne .L_26330_26468\n"
        "test al, al\n"
        "je .L_26330_26430\n"
        "apw_cmp8_load reg_cl, reg_cl\n"
        "jne .L_26330_26468\n"
        "apw_cmp8_load reg_al, reg_cl\n"
        "jne .L_26330_26468\n"
        "cmp byte ptr [rsp + 0x4e], 0\n"
        "je .L_26330_26430\n"
        ".L_26330_26468:\n"
        "lea rax, [rsp + 0x160]\n"
        "dec rax\n"
        ".L_26330_26473:\n"
        "cmp byte ptr [rax + 1], 0\n"
        "lea rax, [rax + 1]\n"
        "jne .L_26330_26473\n"
        "lea r8, [rsp + 0x4c]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_26490:\n"
        "movzx ecx, byte ptr [r8 + rdx]\n"
        "mov byte ptr [rax + rdx], cl\n"
        "lea rdx, [rdx + 1]\n"
        "test cl, cl\n"
        "jne .L_26330_26490\n"
        "test byte ptr [rsp + 0x20], 0x10\n"
        "lea rcx, [rsp + 0x160]\n"
        "je .L_26330_264ec\n"
        "call rva_26330\n"
        "lea rcx, [rsp + 0x160]\n"
        "call qword ptr [rip + rva_3a1f8]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_264d0:\n"
        "movzx eax, byte ptr [rsp + rcx + 0x270]\n"
        "mov byte ptr [rsp + rcx + 0x160], al\n"
        "lea rcx, [rcx + 1]\n"
        "test al, al\n"
        "jne .L_26330_264d0\n"
        "jmp .L_26330_26430\n"
        ".L_26330_264ec:\n"
        "call qword ptr [rip + rva_3a278]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        ".byte 0xf,0x1f,0x40,0x0 # alignment NOP\n"
        ".byte 0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_26330_26500:\n"
        "movzx eax, byte ptr [rsp + rcx + 0x270]\n"
        "mov byte ptr [rsp + rcx + 0x160], al\n"
        "lea rcx, [rcx + 1]\n"
        "test al, al\n"
        "jne .L_26330_26500\n"
        "jmp .L_26330_26430\n"
        ".L_26330_2651c:\n"
        "call qword ptr [rip + rva_3a350]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "cmp eax, 0x12\n"
        "jne .L_26330_2653b\n"
        "call qword ptr [rip + rva_3a328]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a1f8]\n"
        "jmp .L_26330_26543\n"
        ".L_26330_2653b:\n"
        "call qword ptr [rip + rva_3a328]\n"
        ".L_26330_26541:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_26330_26543:\n"
        "mov rcx, qword ptr [rsp + 0x380]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x3a8]\n"
        "add rsp, 0x390\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x265e0 until 0x265fb */
BODY void apw_265e0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov edx, 1\n"
        "lea rcx, [rip + rva_26c60]\n"
        "call rva_347f1\n"
        ".byte 0x90 # alignment NOP\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x29940 until 0x29c13 */
BODY void apw_29940(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "mov qword ptr [rsp + 8], rcx\n"
        "push rbp\n"
        "push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "push r14\n"
        "apw_mov64_load reg_rbp, reg_rsp\n"
        "sub rsp, 0x70\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "mov dword ptr [rbp - 0x40], 0\n"
        "lea rdx, [rip + rva_3ad3b]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        "mov dword ptr [rbp - 0x40], 1\n"
        "lea rdx, [rip + rva_3ad3b]\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rip + rva_3ad3b]\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "mov ecx, 0x400\n"
        "call qword ptr [rip + rva_3a720]\n"
        "mov qword ptr [rbp + 0x48], rax\n"
        "lea r9, [rbp + 0x48]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rip + rva_42ad8]\n"
        "call rva_36150\n"
        "test eax, eax\n"
        "jne .L_29940_29bf1\n"
        "mov rdx, qword ptr [rbp + 0x48]\n"
        "lea rcx, [rbp - 0x28]\n"
        "call qword ptr [rip + rva_3a9b0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rbp - 0x28]\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rax, qword ptr [rbp + 0x40]\n"
        "cmp dword ptr [rax - 0x10], 0\n"
        "je .L_29940_29bf1\n"
        "lea rdx, [rip + rva_424e8]\n"
        "lea rcx, [rbp - 0x10]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rbp - 0x40], 3\n"
        "lea r14, [rip + rva_409c4]\n"
        "mov rbx, 0xffffffffffffffff\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_29940_29a40:\n"
        "inc rax\n"
        "cmp byte ptr [r14 + rax], 0\n"
        "jne .L_29940_29a40\n"
        "mov rdx, qword ptr [rbp + 0x40]\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "apw_mov64_load reg_r9, reg_r14\n"
        "mov r8d, dword ptr [rdx - 0x10]\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3a928]\n"
        "lea r8, [rbp - 0x10]\n"
        "lea rdx, [rbp + 0x48]\n"
        "lea rcx, [rbp - 0x28]\n"
        "call rva_1320\n"
        ".byte 0x90 # alignment NOP\n"
        "mov dword ptr [rbp - 0x40], 1\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "lea rdx, [rip + rva_424f8]\n"
        "lea rcx, [rbp - 0x18]\n"
        "call rva_1430\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x28]\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rbp - 0x40], 0x11\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        ".byte 0xf,0x1f,0x44,0x0,0x0 # alignment NOP\n"
        ".L_29940_29ac0:\n"
        "inc rax\n"
        "cmp byte ptr [r14 + rax], 0\n"
        "jne .L_29940_29ac0\n"
        "mov rdx, qword ptr [rbp - 0x28]\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "apw_mov64_load reg_r9, reg_r14\n"
        "mov r8d, dword ptr [rdx - 0x10]\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3a928]\n"
        "lea r8, [rbp - 0x18]\n"
        "lea rdx, [rbp + 0x48]\n"
        "lea rcx, [rbp - 0x30]\n"
        "call rva_1320\n"
        ".byte 0x90 # alignment NOP\n"
        "mov dword ptr [rbp - 0x40], 1\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "lea rdx, [rip + rva_42508]\n"
        "lea rcx, [rbp - 0x20]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x30]\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rbp - 0x40], 0x41\n"
        ".L_29940_29b36:\n"
        "inc rbx\n"
        "cmp byte ptr [r14 + rbx], 0\n"
        "jne .L_29940_29b36\n"
        "mov rdx, qword ptr [rbp - 0x30]\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_mov64_load reg_r9, reg_r14\n"
        "mov r8d, dword ptr [rdx - 0x10]\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3a928]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3aa90]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rbp - 0x38]\n"
        "call qword ptr [rip + rva_3ab08]\n"
        "mov dword ptr [rbp - 0x40], 0xc1\n"
        "mov r9, qword ptr [rbp - 0x20]\n"
        "mov eax, dword ptr [r9 - 0x10]\n"
        "mov rdx, qword ptr [rbp + 0x48]\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "mov r8d, dword ptr [rdx - 0x10]\n"
        "lea rcx, [rbp - 0x38]\n"
        "call qword ptr [rip + rva_3a928]\n"
        "lea rdx, [rbp - 0x38]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x18]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x10]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_29940_29bf1:\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "add rsp, 0x70\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x2e010 until 0x2e1e2 */
BODY void apw_2e010(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x20], rbx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "lea rbp, [rsp - 0x30]\n"
        "sub rsp, 0x130\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x20], rax\n"
        "apw_mov64_load reg_rsi, reg_r8\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0xfc\n"
        "lea rcx, [rsp + 0x24]\n"
        "call rva_3629e\n"
        "lea rcx, [rip + rva_41bb8]\n"
        "call rva_29600\n"
        "test eax, eax\n"
        "jne .L_2e010_2e075\n"
        "mov eax, dword ptr [rip + rva_425e8]\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "movzx eax, word ptr [rip + rva_425ec]\n"
        "mov word ptr [rsp + 0x24], ax\n"
        "jmp .L_2e010_2e0ed\n"
        ".L_2e010_2e075:\n"
        "lea rcx, [rip + rva_41bb8]\n"
        "call rva_29600\n"
        "cmp eax, 1\n"
        "jne .L_2e010_2e0a1\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x706b62\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        ".L_2e010_2e0a1:\n"
        "mov eax, dword ptr [rip + rva_425f0]\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "movzx eax, word ptr [rip + rva_425f4]\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "mov word ptr [rsp + 0x24], ax\n"
        "call rva_25ad0\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x666470\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "mov dword ptr [rsp + 0x20], 0x726f66\n"
        ".L_2e010_2e0ed:\n"
        "lea r9, [rsp + 0x20]\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x736461\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x736264\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x686368\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x6c6d78\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "lea rcx, [rip + rva_42600]\n"
        "call rva_34043\n"
        "test rax, rax\n"
        "je .L_2e010_2e198\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x62646d\n"
        "apw_mov64_load reg_r8, reg_rax\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        ".L_2e010_2e198:\n"
        "lea r9, [rsp + 0x20]\n"
        "mov dword ptr [rsp + 0x20], 0x70697a\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_25ad0\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_2e1f0\n"
        "mov eax, 1\n"
        "mov rcx, qword ptr [rbp + 0x20]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x168]\n"
        "add rsp, 0x130\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x323f0 until 0x32464 */
BODY void apw_323f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x60\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rsp + 0x58], rax\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov qword ptr [rsp + 0x20], rcx\n"
        "mov rcx, qword ptr [rcx]\n"
        "lea rdx, [rsp + 0x28]\n"
        "call qword ptr [rip + rva_3a6f8]\n"
        "test eax, eax\n"
        "jne .L_323f0_32443\n"
        "cmp dword ptr [rsp + 0x3c], eax\n"
        "je .L_323f0_32443\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rcx, qword ptr [rsp + 0x58]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x60\n"
        "pop rbx\n"
        "ret\n"
        ".L_323f0_32443:\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov eax, 1\n"
        "mov rcx, qword ptr [rsp + 0x58]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x60\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x32470 until 0x324b7 */
BODY void apw_32470(void) {
    __asm__(INTEL
        "apw_mov64_load reg_r8, reg_rdx\n"
        "mov rdx, qword ptr [rcx + 8]\n"
        "cmp rdx, qword ptr [rcx + 0x10]\n"
        "je .L_32470_324b2\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "mov qword ptr [rdx + 0x10], rax\n"
        "mov qword ptr [rdx + 0x18], rax\n"
        "movups xmm0, xmmword ptr [r8]\n"
        "movups xmmword ptr [rdx], xmm0\n"
        "movups xmm1, xmmword ptr [r8 + 0x10]\n"
        "movups xmmword ptr [rdx + 0x10], xmm1\n"
        "mov qword ptr [r8 + 0x10], rax\n"
        "mov qword ptr [r8 + 0x18], 0xf\n"
        "mov byte ptr [r8], al\n"
        "add qword ptr [rcx + 8], 0x20\n"
        "ret\n"
        ".L_32470_324b2:\n"
        "jmp rva_77a0\n"
        END);
}

/* body 0x324c0 until 0x324fa */
BODY void apw_324c0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov rcx, qword ptr [rcx]\n"
        "test rcx, rcx\n"
        "je .L_324c0_324de\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rbx], 0\n"
        ".L_324c0_324de:\n"
        "mov rcx, qword ptr [rbx + 8]\n"
        "test rcx, rcx\n"
        "je .L_324c0_324f4\n"
        "call rva_34f92\n"
        "mov qword ptr [rbx + 8], 0\n"
        ".L_324c0_324f4:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x33970 until 0x3397d */
BODY void apw_33970(void) {
    __asm__(INTEL
        "mov eax, 1\n"
        "lock xadd dword ptr [rcx + 0xc], eax\n"
        "inc eax\n"
        "ret\n"
        END);
}

/* body 0x33980 until 0x3398d */
BODY void apw_33980(void) {
    __asm__(INTEL
        "mov eax, 0xffffffff\n"
        "lock xadd dword ptr [rcx + 0xc], eax\n"
        "dec eax\n"
        "ret\n"
        END);
}

/* body 0x33990 until 0x33994 */
BODY void apw_33990(void) {
    __asm__(INTEL
        "mov eax, dword ptr [rcx + 0xc]\n"
        "ret\n"
        END);
}

/* body 0x33b80 until 0x33b8d */
BODY void apw_33b80(void) {
    __asm__(INTEL
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a1d0]\n"
        END);
}

/* body 0x33b90 until 0x33ba7 */
BODY void apw_33b90(void) {
    __asm__(INTEL
        "cmp edx, 1\n"
        "jne .L_33b90_33ba1\n"
        "cmp byte ptr [rip + rva_534b0], 0\n"
        "je .L_33b90_33ba1\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "ret\n"
        ".L_33b90_33ba1:\n"
        "mov eax, 1\n"
        "ret\n"
        END);
}

/* body 0x33bb0 until 0x33bb8 */
BODY void apw_33bb0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_429c0]\n"
        "ret\n"
        END);
}

/* body 0x33bc0 until 0x33bc8 */
BODY void apw_33bc0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_42464]\n"
        "ret\n"
        END);
}

/* body 0x33bd0 until 0x33bd7 */
BODY void apw_33bd0(void) {
    __asm__(INTEL
        "mov eax, dword ptr [rip + rva_52850]\n"
        "ret\n"
        END);
}

/* body 0x33be0 until 0x33bfa */
BODY void apw_33be0(void) {
    __asm__(INTEL
        "cmp dword ptr [rip + rva_52850], 2\n"
        "lea rcx, [rip + rva_3f5a0]\n"
        "lea rax, [rip + rva_3b3e8]\n"
        "cmove rax, rcx\n"
        "ret\n"
        END);
}

/* body 0x33c00 until 0x33c08 */
BODY void apw_33c00(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_3ad3c]\n"
        "ret\n"
        END);
}

/* body 0x33c10 until 0x33c21 */
BODY void apw_33c10(void) {
    __asm__(INTEL
        "apw_xor32_load reg_eax, reg_eax\n"
        "cmp ecx, 2\n"
        "sete al\n"
        "inc eax\n"
        "mov dword ptr [rip + rva_52850], eax\n"
        "ret\n"
        END);
}

/* body 0x33c21 until 0x33c2d */
BODY void apw_33c21(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53070]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33c2d until 0x33c33 */
BODY void apw_33c2d(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53070]\n"
        END);
}

/* body 0x33cac until 0x33cb8 */
BODY void apw_33cac(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52f80]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33cb8 until 0x33cbe */
BODY void apw_33cb8(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52f80]\n"
        END);
}

/* body 0x33cbe until 0x33cca */
BODY void apw_33cbe(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52f88]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33cca until 0x33cd0 */
BODY void apw_33cca(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52f88]\n"
        END);
}

/* body 0x33cd0 until 0x33cdc */
BODY void apw_33cd0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52f90]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33cdc until 0x33ce2 */
BODY void apw_33cdc(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52f90]\n"
        END);
}

/* body 0x33ce2 until 0x33cee */
BODY void apw_33ce2(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52f98]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33cee until 0x33cf4 */
BODY void apw_33cee(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52f98]\n"
        END);
}

/* body 0x33cf4 until 0x33d00 */
BODY void apw_33cf4(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fa0]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d00 until 0x33d06 */
BODY void apw_33d00(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fa0]\n"
        END);
}

/* body 0x33d06 until 0x33d12 */
BODY void apw_33d06(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fa8]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d12 until 0x33d18 */
BODY void apw_33d12(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fa8]\n"
        END);
}

/* body 0x33d18 until 0x33d24 */
BODY void apw_33d18(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fb0]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d24 until 0x33d2a */
BODY void apw_33d24(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fb0]\n"
        END);
}

/* body 0x33d2a until 0x33d36 */
BODY void apw_33d2a(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fb8]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d36 until 0x33d3c */
BODY void apw_33d36(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fb8]\n"
        END);
}

/* body 0x33d3c until 0x33d48 */
BODY void apw_33d3c(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fc0]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d48 until 0x33d4e */
BODY void apw_33d48(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fc0]\n"
        END);
}

/* body 0x33d4e until 0x33d5a */
BODY void apw_33d4e(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fc8]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d5a until 0x33d60 */
BODY void apw_33d5a(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fc8]\n"
        END);
}

/* body 0x33d60 until 0x33d6c */
BODY void apw_33d60(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fd0]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d6c until 0x33d72 */
BODY void apw_33d6c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fd0]\n"
        END);
}

/* body 0x33d72 until 0x33d7e */
BODY void apw_33d72(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fd8]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d7e until 0x33d84 */
BODY void apw_33d7e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fd8]\n"
        END);
}

/* body 0x33d84 until 0x33d90 */
BODY void apw_33d84(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fe0]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33d90 until 0x33d96 */
BODY void apw_33d90(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fe0]\n"
        END);
}

/* body 0x33d96 until 0x33da2 */
BODY void apw_33d96(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52fe8]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33da2 until 0x33da8 */
BODY void apw_33da2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52fe8]\n"
        END);
}

/* body 0x33da8 until 0x33db4 */
BODY void apw_33da8(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52ff0]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33db4 until 0x33dba */
BODY void apw_33db4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52ff0]\n"
        END);
}

/* body 0x33dba until 0x33dc6 */
BODY void apw_33dba(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52ff8]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33dc6 until 0x33dcc */
BODY void apw_33dc6(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52ff8]\n"
        END);
}

/* body 0x33dcc until 0x33dd8 */
BODY void apw_33dcc(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53000]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33dd8 until 0x33dde */
BODY void apw_33dd8(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53000]\n"
        END);
}

/* body 0x33dde until 0x33dea */
BODY void apw_33dde(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53008]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33dea until 0x33df0 */
BODY void apw_33dea(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53008]\n"
        END);
}

/* body 0x33df0 until 0x33dfc */
BODY void apw_33df0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53010]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33dfc until 0x33e02 */
BODY void apw_33dfc(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53010]\n"
        END);
}

/* body 0x33e02 until 0x33e0e */
BODY void apw_33e02(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53018]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e0e until 0x33e14 */
BODY void apw_33e0e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53018]\n"
        END);
}

/* body 0x33e14 until 0x33e20 */
BODY void apw_33e14(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53020]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e20 until 0x33e26 */
BODY void apw_33e20(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53020]\n"
        END);
}

/* body 0x33e26 until 0x33e32 */
BODY void apw_33e26(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53028]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e32 until 0x33e38 */
BODY void apw_33e32(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53028]\n"
        END);
}

/* body 0x33e38 until 0x33e44 */
BODY void apw_33e38(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53030]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e44 until 0x33e4a */
BODY void apw_33e44(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53030]\n"
        END);
}

/* body 0x33e4a until 0x33e56 */
BODY void apw_33e4a(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53038]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e56 until 0x33e5c */
BODY void apw_33e56(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53038]\n"
        END);
}

/* body 0x33e5c until 0x33e68 */
BODY void apw_33e5c(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53040]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e68 until 0x33e6e */
BODY void apw_33e68(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53040]\n"
        END);
}

/* body 0x33e6e until 0x33e7a */
BODY void apw_33e6e(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53048]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e7a until 0x33e80 */
BODY void apw_33e7a(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53048]\n"
        END);
}

/* body 0x33e80 until 0x33e8c */
BODY void apw_33e80(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53050]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e8c until 0x33e92 */
BODY void apw_33e8c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53050]\n"
        END);
}

/* body 0x33e92 until 0x33e9e */
BODY void apw_33e92(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53058]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33e9e until 0x33ea4 */
BODY void apw_33e9e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53058]\n"
        END);
}

/* body 0x33ea4 until 0x33eb0 */
BODY void apw_33ea4(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53060]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33eb0 until 0x33eb6 */
BODY void apw_33eb0(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53060]\n"
        END);
}

/* body 0x33eb6 until 0x33ec2 */
BODY void apw_33eb6(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53068]\n"
        "jmp rva_33c33\n"
        END);
}

/* body 0x33ec2 until 0x33ec8 */
BODY void apw_33ec2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53068]\n"
        END);
}

/* body 0x33ec8 until 0x33ed4 */
BODY void apw_33ec8(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53450]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33ed4 until 0x33eda */
BODY void apw_33ed4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53450]\n"
        END);
}

/* body 0x33f53 until 0x33f5f */
BODY void apw_33f53(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53458]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33f5f until 0x33f65 */
BODY void apw_33f5f(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53458]\n"
        END);
}

/* body 0x33f65 until 0x33f71 */
BODY void apw_33f65(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53338]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33f71 until 0x33f77 */
BODY void apw_33f71(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53338]\n"
        END);
}

/* body 0x33f77 until 0x33f83 */
BODY void apw_33f77(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53460]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33f83 until 0x33f89 */
BODY void apw_33f83(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53460]\n"
        END);
}

/* body 0x33f89 until 0x33f95 */
BODY void apw_33f89(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53448]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33f95 until 0x33fa1 */
BODY void apw_33f95(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53440]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33fa1 until 0x33fa7 */
BODY void apw_33fa1(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53440]\n"
        END);
}

/* body 0x33fa7 until 0x33fb3 */
BODY void apw_33fa7(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53438]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33fb3 until 0x33fb9 */
BODY void apw_33fb3(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53438]\n"
        END);
}

/* body 0x33fb9 until 0x33fc5 */
BODY void apw_33fb9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53430]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33fc5 until 0x33fcb */
BODY void apw_33fc5(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53430]\n"
        END);
}

/* body 0x33fcb until 0x33fd7 */
BODY void apw_33fcb(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53428]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33fd7 until 0x33fdd */
BODY void apw_33fd7(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53428]\n"
        END);
}

/* body 0x33fdd until 0x33fe9 */
BODY void apw_33fdd(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53420]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33fe9 until 0x33fef */
BODY void apw_33fe9(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53420]\n"
        END);
}

/* body 0x33fef until 0x33ffb */
BODY void apw_33fef(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53418]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x33ffb until 0x34001 */
BODY void apw_33ffb(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53418]\n"
        END);
}

/* body 0x34001 until 0x3400d */
BODY void apw_34001(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53410]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3400d until 0x34013 */
BODY void apw_3400d(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53410]\n"
        END);
}

/* body 0x34013 until 0x3401f */
BODY void apw_34013(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53408]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3401f until 0x34025 */
BODY void apw_3401f(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53408]\n"
        END);
}

/* body 0x34025 until 0x34031 */
BODY void apw_34025(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53400]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34031 until 0x34037 */
BODY void apw_34031(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53400]\n"
        END);
}

/* body 0x34037 until 0x34043 */
BODY void apw_34037(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533f8]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34043 until 0x34049 */
BODY void apw_34043(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533f8]\n"
        END);
}

/* body 0x34049 until 0x34055 */
BODY void apw_34049(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533f0]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34055 until 0x3405b */
BODY void apw_34055(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533f0]\n"
        END);
}

/* body 0x3405b until 0x34067 */
BODY void apw_3405b(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533e8]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34067 until 0x3406d */
BODY void apw_34067(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533e8]\n"
        END);
}

/* body 0x3406d until 0x34079 */
BODY void apw_3406d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533e0]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34079 until 0x3407f */
BODY void apw_34079(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533e0]\n"
        END);
}

/* body 0x3407f until 0x3408b */
BODY void apw_3407f(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533d8]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3408b until 0x34091 */
BODY void apw_3408b(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533d8]\n"
        END);
}

/* body 0x34091 until 0x3409d */
BODY void apw_34091(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533d0]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3409d until 0x340a3 */
BODY void apw_3409d(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533d0]\n"
        END);
}

/* body 0x340a3 until 0x340af */
BODY void apw_340a3(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533c8]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x340af until 0x340b5 */
BODY void apw_340af(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533c8]\n"
        END);
}

/* body 0x340b5 until 0x340c1 */
BODY void apw_340b5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533c0]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x340c1 until 0x340c7 */
BODY void apw_340c1(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533c0]\n"
        END);
}

/* body 0x340c7 until 0x340d3 */
BODY void apw_340c7(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533b8]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x340d3 until 0x340d9 */
BODY void apw_340d3(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533b8]\n"
        END);
}

/* body 0x340d9 until 0x340e5 */
BODY void apw_340d9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533b0]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x340e5 until 0x340eb */
BODY void apw_340e5(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533b0]\n"
        END);
}

/* body 0x340eb until 0x340f7 */
BODY void apw_340eb(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533a8]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x340f7 until 0x340fd */
BODY void apw_340f7(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533a8]\n"
        END);
}

/* body 0x340fd until 0x34109 */
BODY void apw_340fd(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_533a0]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34109 until 0x3410f */
BODY void apw_34109(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_533a0]\n"
        END);
}

/* body 0x3410f until 0x3411b */
BODY void apw_3410f(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53398]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3411b until 0x34127 */
BODY void apw_3411b(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53390]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34127 until 0x34133 */
BODY void apw_34127(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53388]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34133 until 0x3413f */
BODY void apw_34133(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53380]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3413f until 0x34145 */
BODY void apw_3413f(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53380]\n"
        END);
}

/* body 0x34145 until 0x34151 */
BODY void apw_34145(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53378]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34151 until 0x34157 */
BODY void apw_34151(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53378]\n"
        END);
}

/* body 0x34157 until 0x34163 */
BODY void apw_34157(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53370]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34163 until 0x34169 */
BODY void apw_34163(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53370]\n"
        END);
}

/* body 0x34169 until 0x34175 */
BODY void apw_34169(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53368]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34175 until 0x34181 */
BODY void apw_34175(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53360]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x34181 until 0x3418d */
BODY void apw_34181(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53358]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3418d until 0x34193 */
BODY void apw_3418d(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53358]\n"
        END);
}

/* body 0x34193 until 0x3419f */
BODY void apw_34193(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53350]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x3419f until 0x341a5 */
BODY void apw_3419f(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53350]\n"
        END);
}

/* body 0x341a5 until 0x341b1 */
BODY void apw_341a5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53348]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x341b1 until 0x341b7 */
BODY void apw_341b1(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53348]\n"
        END);
}

/* body 0x341b7 until 0x341c3 */
BODY void apw_341b7(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53340]\n"
        "jmp rva_33eda\n"
        END);
}

/* body 0x341c3 until 0x341c9 */
BODY void apw_341c3(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53340]\n"
        END);
}

/* body 0x341c9 until 0x341d5 */
BODY void apw_341c9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530b8]\n"
        "jmp rva_341db\n"
        END);
}

/* body 0x341d5 until 0x341db */
BODY void apw_341d5(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530b8]\n"
        END);
}

/* body 0x34254 until 0x34260 */
BODY void apw_34254(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53098]\n"
        "jmp rva_341db\n"
        END);
}

/* body 0x34260 until 0x34266 */
BODY void apw_34260(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53098]\n"
        END);
}

/* body 0x34266 until 0x34272 */
BODY void apw_34266(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530a0]\n"
        "jmp rva_341db\n"
        END);
}

/* body 0x34272 until 0x34278 */
BODY void apw_34272(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530a0]\n"
        END);
}

/* body 0x34278 until 0x34284 */
BODY void apw_34278(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530a8]\n"
        "jmp rva_341db\n"
        END);
}

/* body 0x34284 until 0x3428a */
BODY void apw_34284(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530a8]\n"
        END);
}

/* body 0x3428a until 0x34296 */
BODY void apw_3428a(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53090]\n"
        "jmp rva_341db\n"
        END);
}

/* body 0x34296 until 0x342a2 */
BODY void apw_34296(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530b0]\n"
        "jmp rva_341db\n"
        END);
}

/* body 0x342a2 until 0x342a8 */
BODY void apw_342a2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530b0]\n"
        END);
}

/* body 0x342a8 until 0x342b4 */
BODY void apw_342a8(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530c8]\n"
        "jmp rva_342ba\n"
        END);
}

/* body 0x342b4 until 0x342ba */
BODY void apw_342b4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530c8]\n"
        END);
}

/* body 0x34333 until 0x3433f */
BODY void apw_34333(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530e0]\n"
        "jmp rva_34345\n"
        END);
}

/* body 0x3433f until 0x34345 */
BODY void apw_3433f(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530e0]\n"
        END);
}

/* body 0x343be until 0x343ca */
BODY void apw_343be(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530e8]\n"
        "jmp rva_34345\n"
        END);
}

/* body 0x343ca until 0x343d0 */
BODY void apw_343ca(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530e8]\n"
        END);
}

/* body 0x343d0 until 0x343dc */
BODY void apw_343d0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530d8]\n"
        "jmp rva_34345\n"
        END);
}

/* body 0x343dc until 0x343e2 */
BODY void apw_343dc(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530d8]\n"
        END);
}

/* body 0x3445b until 0x34467 */
BODY void apw_3445b(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53220]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34467 until 0x34473 */
BODY void apw_34467(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53228]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34473 until 0x3447f */
BODY void apw_34473(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53230]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3447f until 0x3448b */
BODY void apw_3447f(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53238]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3448b until 0x34497 */
BODY void apw_3448b(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53240]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34497 until 0x344a3 */
BODY void apw_34497(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53248]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344a3 until 0x344af */
BODY void apw_344a3(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53250]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344af until 0x344bb */
BODY void apw_344af(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53258]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344bb until 0x344c7 */
BODY void apw_344bb(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53260]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344c7 until 0x344d3 */
BODY void apw_344c7(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53268]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344d3 until 0x344d9 */
BODY void apw_344d3(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53268]\n"
        END);
}

/* body 0x344d9 until 0x344e5 */
BODY void apw_344d9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53270]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344e5 until 0x344f1 */
BODY void apw_344e5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53278]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344f1 until 0x344fd */
BODY void apw_344f1(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53280]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x344fd until 0x34509 */
BODY void apw_344fd(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53288]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34509 until 0x34515 */
BODY void apw_34509(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53290]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34515 until 0x34521 */
BODY void apw_34515(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53298]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34521 until 0x3452d */
BODY void apw_34521(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53208]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3452d until 0x34533 */
BODY void apw_3452d(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53208]\n"
        END);
}

/* body 0x34533 until 0x3453f */
BODY void apw_34533(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532a0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3453f until 0x34545 */
BODY void apw_3453f(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_532a0]\n"
        END);
}

/* body 0x34545 until 0x34551 */
BODY void apw_34545(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532a8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34551 until 0x3455d */
BODY void apw_34551(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532b0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3455d until 0x34569 */
BODY void apw_3455d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532b8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34569 until 0x34575 */
BODY void apw_34569(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532c0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34575 until 0x34581 */
BODY void apw_34575(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532c8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34581 until 0x3458d */
BODY void apw_34581(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532d0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3458d until 0x34599 */
BODY void apw_3458d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532d8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34599 until 0x345a5 */
BODY void apw_34599(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532e0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345a5 until 0x345b1 */
BODY void apw_345a5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532e8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345b1 until 0x345bd */
BODY void apw_345b1(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532f0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345bd until 0x345c9 */
BODY void apw_345bd(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_532f8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345c9 until 0x345d5 */
BODY void apw_345c9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53300]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345d5 until 0x345e1 */
BODY void apw_345d5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53308]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345e1 until 0x345ed */
BODY void apw_345e1(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53310]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345ed until 0x345f9 */
BODY void apw_345ed(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53318]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x345f9 until 0x34605 */
BODY void apw_345f9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53320]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34605 until 0x34611 */
BODY void apw_34605(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53328]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34611 until 0x3461d */
BODY void apw_34611(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53218]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3461d until 0x34629 */
BODY void apw_3461d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53210]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34629 until 0x34635 */
BODY void apw_34629(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531a0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34635 until 0x34641 */
BODY void apw_34635(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53198]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34641 until 0x3464d */
BODY void apw_34641(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53190]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3464d until 0x34659 */
BODY void apw_3464d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53188]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34659 until 0x34665 */
BODY void apw_34659(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53180]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34665 until 0x34671 */
BODY void apw_34665(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53178]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34671 until 0x3467d */
BODY void apw_34671(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53170]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3467d until 0x34689 */
BODY void apw_3467d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53168]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34689 until 0x34695 */
BODY void apw_34689(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53160]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34695 until 0x346a1 */
BODY void apw_34695(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53158]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346a1 until 0x346ad */
BODY void apw_346a1(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53150]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346ad until 0x346b9 */
BODY void apw_346ad(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53200]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346b9 until 0x346c5 */
BODY void apw_346b9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53140]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346c5 until 0x346d1 */
BODY void apw_346c5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53138]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346d1 until 0x346d7 */
BODY void apw_346d1(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53138]\n"
        END);
}

/* body 0x346d7 until 0x346e3 */
BODY void apw_346d7(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53130]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346e3 until 0x346e9 */
BODY void apw_346e3(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53130]\n"
        END);
}

/* body 0x346e9 until 0x346f5 */
BODY void apw_346e9(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53128]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x346f5 until 0x34701 */
BODY void apw_346f5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53120]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34701 until 0x3470d */
BODY void apw_34701(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53118]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3470d until 0x34719 */
BODY void apw_3470d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53110]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34719 until 0x34725 */
BODY void apw_34719(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53108]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34725 until 0x3472b */
BODY void apw_34725(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53108]\n"
        END);
}

/* body 0x3472b until 0x34737 */
BODY void apw_3472b(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53100]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34737 until 0x3473d */
BODY void apw_34737(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53100]\n"
        END);
}

/* body 0x3473d until 0x34749 */
BODY void apw_3473d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_530f8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34749 until 0x3474f */
BODY void apw_34749(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_530f8]\n"
        END);
}

/* body 0x3474f until 0x3475b */
BODY void apw_3474f(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531f8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3475b until 0x34767 */
BODY void apw_3475b(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53148]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34767 until 0x3476d */
BODY void apw_34767(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53148]\n"
        END);
}

/* body 0x3476d until 0x34779 */
BODY void apw_3476d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531a8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34779 until 0x3477f */
BODY void apw_34779(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531a8]\n"
        END);
}

/* body 0x3477f until 0x3478b */
BODY void apw_3477f(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531b0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3478b until 0x34791 */
BODY void apw_3478b(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531b0]\n"
        END);
}

/* body 0x34791 until 0x3479d */
BODY void apw_34791(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531b8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x3479d until 0x347a9 */
BODY void apw_3479d(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531c0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x347a9 until 0x347af */
BODY void apw_347a9(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531c0]\n"
        END);
}

/* body 0x347af until 0x347bb */
BODY void apw_347af(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531c8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x347bb until 0x347c1 */
BODY void apw_347bb(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531c8]\n"
        END);
}

/* body 0x347c1 until 0x347cd */
BODY void apw_347c1(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531d0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x347cd until 0x347d3 */
BODY void apw_347cd(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531d0]\n"
        END);
}

/* body 0x347d3 until 0x347df */
BODY void apw_347d3(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531d8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x347df until 0x347e5 */
BODY void apw_347df(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531d8]\n"
        END);
}

/* body 0x347e5 until 0x347f1 */
BODY void apw_347e5(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531e0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x347f1 until 0x347f7 */
BODY void apw_347f1(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531e0]\n"
        END);
}

/* body 0x347f7 until 0x34803 */
BODY void apw_347f7(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531e8]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34803 until 0x34809 */
BODY void apw_34803(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_531e8]\n"
        END);
}

/* body 0x34809 until 0x34815 */
BODY void apw_34809(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_531f0]\n"
        "jmp rva_343e2\n"
        END);
}

/* body 0x34815 until 0x34821 */
BODY void apw_34815(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53480]\n"
        "jmp rva_34827\n"
        END);
}

/* body 0x34821 until 0x34827 */
BODY void apw_34821(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53480]\n"
        END);
}

/* body 0x348a0 until 0x348ac */
BODY void apw_348a0(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53498]\n"
        "jmp rva_34827\n"
        END);
}

/* body 0x348ac until 0x348b2 */
BODY void apw_348ac(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53498]\n"
        END);
}

/* body 0x348b2 until 0x348be */
BODY void apw_348b2(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53490]\n"
        "jmp rva_34827\n"
        END);
}

/* body 0x348be until 0x348c4 */
BODY void apw_348be(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53490]\n"
        END);
}

/* body 0x348c4 until 0x348d0 */
BODY void apw_348c4(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53488]\n"
        "jmp rva_34827\n"
        END);
}

/* body 0x348d0 until 0x348d6 */
BODY void apw_348d0(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53488]\n"
        END);
}

/* body 0x348d6 until 0x348e2 */
BODY void apw_348d6(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53470]\n"
        "jmp rva_34827\n"
        END);
}

/* body 0x348e2 until 0x348e8 */
BODY void apw_348e2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53470]\n"
        END);
}

/* body 0x348e8 until 0x348f4 */
BODY void apw_348e8(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53478]\n"
        "jmp rva_34827\n"
        END);
}

/* body 0x348f4 until 0x348fa */
BODY void apw_348f4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53478]\n"
        END);
}

/* body 0x348fa until 0x34900 */
BODY void apw_348fa(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a088]\n"
        END);
}

/* body 0x34900 until 0x34906 */
BODY void apw_34900(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a090]\n"
        END);
}

/* body 0x34906 until 0x3490c */
BODY void apw_34906(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a098]\n"
        END);
}

/* body 0x3490c until 0x34912 */
BODY void apw_3490c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0a0]\n"
        END);
}

/* body 0x34912 until 0x34918 */
BODY void apw_34912(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0a8]\n"
        END);
}

/* body 0x34924 until 0x3492a */
BODY void apw_34924(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0c0]\n"
        END);
}

/* body 0x3492a until 0x34930 */
BODY void apw_3492a(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0c8]\n"
        END);
}

/* body 0x34930 until 0x34936 */
BODY void apw_34930(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0d0]\n"
        END);
}

/* body 0x34936 until 0x3493c */
BODY void apw_34936(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0d8]\n"
        END);
}

/* body 0x3493c until 0x34942 */
BODY void apw_3493c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0e0]\n"
        END);
}

/* body 0x34942 until 0x34948 */
BODY void apw_34942(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a0e8]\n"
        END);
}

/* body 0x34948 until 0x34954 */
BODY void apw_34948(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_52f70]\n"
        "jmp rva_3495a\n"
        END);
}

/* body 0x34954 until 0x3495a */
BODY void apw_34954(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_52f70]\n"
        END);
}

/* body 0x349d3 until 0x349df */
BODY void apw_349d3(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_53080]\n"
        "jmp rva_349e5\n"
        END);
}

/* body 0x349df until 0x349e5 */
BODY void apw_349df(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_53080]\n"
        END);
}

/* body 0x34f68 until 0x34f6e */
BODY void apw_34f68(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3ab38]\n"
        END);
}

/* body 0x34f6e until 0x34f74 */
BODY void apw_34f6e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a930]\n"
        END);
}

/* body 0x34f74 until 0x34f7a */
BODY void apw_34f74(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a938]\n"
        END);
}

/* body 0x34f80 until 0x34f86 */
BODY void apw_34f80(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9e0]\n"
        END);
}

/* body 0x34f86 until 0x34f8c */
BODY void apw_34f86(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9d8]\n"
        END);
}

/* body 0x34f8c until 0x34f92 */
BODY void apw_34f8c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9d0]\n"
        END);
}

/* body 0x34f92 until 0x34f98 */
BODY void apw_34f92(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9c8]\n"
        END);
}

/* body 0x34f98 until 0x34f9e */
BODY void apw_34f98(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9c0]\n"
        END);
}

/* body 0x34f9e until 0x34fa4 */
BODY void apw_34f9e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a998]\n"
        END);
}

/* body 0x34fa4 until 0x34faa */
BODY void apw_34fa4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a990]\n"
        END);
}

/* body 0x34faa until 0x34fb0 */
BODY void apw_34faa(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a988]\n"
        END);
}

/* body 0x34fb0 until 0x34fb6 */
BODY void apw_34fb0(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a978]\n"
        END);
}

/* body 0x34fb6 until 0x34fbc */
BODY void apw_34fb6(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a970]\n"
        END);
}

/* body 0x34fbc until 0x34fc2 */
BODY void apw_34fbc(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aa00]\n"
        END);
}

/* body 0x34fc2 until 0x34fc8 */
BODY void apw_34fc2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aae8]\n"
        END);
}

/* body 0x34fc8 until 0x34fce */
BODY void apw_34fc8(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3ab28]\n"
        END);
}

/* body 0x34fce until 0x34fd4 */
BODY void apw_34fce(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a980]\n"
        END);
}

/* body 0x34fd4 until 0x34fda */
BODY void apw_34fd4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9e8]\n"
        END);
}

/* body 0x34fda until 0x34fe0 */
BODY void apw_34fda(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9f0]\n"
        END);
}

/* body 0x34fe0 until 0x34fe6 */
BODY void apw_34fe0(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3ab10]\n"
        END);
}

/* body 0x34fe6 until 0x34fec */
BODY void apw_34fe6(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aaf0]\n"
        END);
}

/* body 0x34fec until 0x34ff2 */
BODY void apw_34fec(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aae0]\n"
        END);
}

/* body 0x34ff2 until 0x34ff8 */
BODY void apw_34ff2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aad8]\n"
        END);
}

/* body 0x34ff8 until 0x34ffe */
BODY void apw_34ff8(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aad0]\n"
        END);
}

/* body 0x34ffe until 0x35004 */
BODY void apw_34ffe(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aa20]\n"
        END);
}

/* body 0x35004 until 0x3500a */
BODY void apw_35004(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aa18]\n"
        END);
}

/* body 0x3500a until 0x35010 */
BODY void apw_3500a(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aa10]\n"
        END);
}

/* body 0x35010 until 0x35016 */
BODY void apw_35010(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3aa08]\n"
        END);
}

/* body 0x35016 until 0x3501c */
BODY void apw_35016(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a9f8]\n"
        END);
}

/* body 0x3501c until 0x35022 */
BODY void apw_3501c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a958]\n"
        END);
}

/* body 0x35024 until 0x3508d */
BODY void apw_35024(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "lea rcx, [rip + rva_541c8]\n"
        "call qword ptr [rip + rva_3a1c0]\n"
        "mov eax, dword ptr [rip + rva_52878]\n"
        "lea rcx, [rip + rva_541c8]\n"
        "mov edx, dword ptr [rip + rva_54218]\n"
        "inc eax\n"
        "mov dword ptr [rip + rva_52878], eax\n"
        "mov dword ptr [rbx], eax\n"
        "mov rax, qword ptr gs:[0x58]\n"
        "mov r9d, 4\n"
        "mov r8, qword ptr [rax + rdx*8]\n"
        "mov eax, dword ptr [rip + rva_52878]\n"
        "mov dword ptr [r9 + r8], eax\n"
        "call qword ptr [rip + rva_3a1c8]\n"
        "lea rcx, [rip + rva_541c0]\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a1b8]\n"
        END);
}

/* body 0x35090 until 0x35108 */
BODY void apw_35090(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "lea rcx, [rip + rva_541c8]\n"
        "call qword ptr [rip + rva_3a1c0]\n"
        ".L_35090_350a6:\n"
        "cmp dword ptr [rbx], 0\n"
        "jne .L_35090_350cd\n"
        "or dword ptr [rbx], 0xffffffff\n"
        "jmp .L_35090_350f5\n"
        ".L_35090_350b0:\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "lea rdx, [rip + rva_541c8]\n"
        "or r8d, 0xffffffff\n"
        "lea rcx, [rip + rva_541c0]\n"
        "call qword ptr [rip + rva_3a1b0]\n"
        "jmp .L_35090_350a6\n"
        ".L_35090_350cd:\n"
        "cmp dword ptr [rbx], -1\n"
        "je .L_35090_350b0\n"
        "mov rax, qword ptr gs:[0x58]\n"
        "mov ecx, dword ptr [rip + rva_54218]\n"
        "mov r8d, 4\n"
        "mov rdx, qword ptr [rax + rcx*8]\n"
        "mov eax, dword ptr [rip + rva_52878]\n"
        "mov dword ptr [r8 + rdx], eax\n"
        ".L_35090_350f5:\n"
        "lea rcx, [rip + rva_541c8]\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a1c8]\n"
        END);
}

/* body 0x35108 until 0x35133 */
BODY void apw_35108(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "lea rax, [rip + rva_42aa0]\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov qword ptr [rcx], rax\n"
        "test dl, 1\n"
        "je .L_35108_3512a\n"
        "mov edx, 0x18\n"
        "call rva_35134\n"
        ".L_35108_3512a:\n"
        "apw_mov64_load reg_rax, reg_rbx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x35134 until 0x35139 */
BODY void apw_35134(void) {
    __asm__(INTEL
        "jmp rva_34f80\n"
        END);
}

/* body 0x3513c until 0x35175 */
BODY void apw_3513c(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_35e80\n"
        "test eax, eax\n"
        "je .L_3513c_3516a\n"
        "mov rax, qword ptr gs:[0x30]\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "jmp .L_3513c_3515d\n"
        ".L_3513c_35158:\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "je .L_3513c_35171\n"
        ".L_3513c_3515d:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "lock cmpxchg qword ptr [rip + rva_541d8], rcx\n"
        "jne .L_3513c_35158\n"
        ".L_3513c_3516a:\n"
        "apw_xor8_load reg_al, reg_al\n"
        ".L_3513c_3516c:\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_3513c_35171:\n"
        "mov al, 1\n"
        "jmp .L_3513c_3516c\n"
        END);
}

/* body 0x35178 until 0x351ac */
BODY void apw_35178(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_35e80\n"
        "test eax, eax\n"
        "je .L_35178_3518c\n"
        "call rva_35cd4\n"
        "jmp .L_35178_351a5\n"
        ".L_35178_3518c:\n"
        "call rva_1f80\n"
        "apw_mov32_load reg_ecx, reg_eax\n"
        "call rva_36304\n"
        "test eax, eax\n"
        "je .L_35178_351a0\n"
        "apw_xor8_load reg_al, reg_al\n"
        "jmp .L_35178_351a7\n"
        ".L_35178_351a0:\n"
        "call rva_3630a\n"
        ".L_35178_351a5:\n"
        "mov al, 1\n"
        ".L_35178_351a7:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x351ac until 0x351c1 */
BODY void apw_351ac(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_352f4\n"
        "test al, al\n"
        "setne al\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x351c4 until 0x351ec */
BODY void apw_351c4(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_36ac8\n"
        "test al, al\n"
        "jne .L_351c4_351d5\n"
        ".L_351c4_351d1:\n"
        "apw_xor8_load reg_al, reg_al\n"
        "jmp .L_351c4_351e7\n"
        ".L_351c4_351d5:\n"
        "call rva_36ac8\n"
        "test al, al\n"
        "jne .L_351c4_351e5\n"
        "call rva_36ac8\n"
        "jmp .L_351c4_351d1\n"
        ".L_351c4_351e5:\n"
        "mov al, 1\n"
        ".L_351c4_351e7:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x351ec until 0x35201 */
BODY void apw_351ec(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_36ac8\n"
        "call rva_36ac8\n"
        "mov al, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x35264 until 0x35294 */
BODY void apw_35264(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_35e80\n"
        "test eax, eax\n"
        "je .L_35264_35281\n"
        "lea rcx, [rip + rva_541e8]\n"
        "add rsp, 0x28\n"
        "jmp rva_3631c\n"
        ".L_35264_35281:\n"
        "call rva_1d40\n"
        "test eax, eax\n"
        "jne .L_35264_3528f\n"
        "call rva_36328\n"
        ".L_35264_3528f:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x35294 until 0x352a8 */
BODY void apw_35294(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_36ac8\n"
        "add rsp, 0x28\n"
        "jmp rva_36ac8\n"
        END);
}

/* body 0x352a8 until 0x352f1 */
BODY void apw_352a8(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "movzx eax, byte ptr [rip + rva_541e0]\n"
        "test ecx, ecx\n"
        "mov ebx, 1\n"
        "cmove eax, ebx\n"
        "mov byte ptr [rip + rva_541e0], al\n"
        "call rva_35cd4\n"
        "call rva_36ac8\n"
        "test al, al\n"
        "jne .L_352a8_352d7\n"
        ".L_352a8_352d3:\n"
        "apw_xor8_load reg_al, reg_al\n"
        "jmp .L_352a8_352eb\n"
        ".L_352a8_352d7:\n"
        "call rva_36ac8\n"
        "test al, al\n"
        "jne .L_352a8_352e9\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_36ac8\n"
        "jmp .L_352a8_352d3\n"
        ".L_352a8_352e9:\n"
        "apw_mov8_load reg_al, reg_bl\n"
        ".L_352a8_352eb:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x35418 until 0x3543c */
BODY void apw_35418(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov8_load reg_bl, reg_cl\n"
        "call rva_35e80\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "test eax, eax\n"
        "je .L_35418_35436\n"
        "test bl, bl\n"
        "jne .L_35418_35436\n"
        "xchg qword ptr [rip + rva_541d8], rdx\n"
        ".L_35418_35436:\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x3543c until 0x35465 */
BODY void apw_3543c(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "cmp byte ptr [rip + rva_541e0], 0\n"
        "apw_mov8_load reg_bl, reg_cl\n"
        "je .L_3543c_35451\n"
        "test dl, dl\n"
        "jne .L_3543c_3545d\n"
        ".L_3543c_35451:\n"
        "call rva_36ac8\n"
        "apw_mov8_load reg_cl, reg_bl\n"
        "call rva_36ac8\n"
        ".L_3543c_3545d:\n"
        "mov al, 1\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x35468 until 0x354a2 */
BODY void apw_35468(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "cmp qword ptr [rip + rva_541e8], -1\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "jne .L_35468_35482\n"
        "call rva_36322\n"
        "jmp .L_35468_35491\n"
        ".L_35468_35482:\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rip + rva_541e8]\n"
        "call rva_36316\n"
        ".L_35468_35491:\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "test eax, eax\n"
        "cmove rdx, rbx\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x354a4 until 0x354bb */
BODY void apw_354a4(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_35468\n"
        "neg rax\n"
        "apw_sbb32_load reg_eax, reg_eax\n"
        "neg eax\n"
        "dec eax\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x354bc until 0x354d9 */
BODY void apw_354bc(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov r8, qword ptr [r9 + 0x38]\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        "apw_mov64_load reg_rdx, reg_r9\n"
        "call rva_354dc\n"
        "mov eax, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x354dc until 0x35537 */
BODY void apw_354dc(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "mov r11d, dword ptr [r8]\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "and r11d, 0xfffffff8\n"
        "apw_mov64_load reg_r9, reg_rcx\n"
        "test byte ptr [r8], 4\n"
        "apw_mov64_load reg_r10, reg_rcx\n"
        "je .L_354dc_35507\n"
        "mov eax, dword ptr [r8 + 8]\n"
        "movsxd r10, dword ptr [r8 + 4]\n"
        "neg eax\n"
        "apw_add64_load reg_r10, reg_rcx\n"
        "movsxd rcx, eax\n"
        "apw_and64_load reg_r10, reg_rcx\n"
        ".L_354dc_35507:\n"
        "movsxd rax, r11d\n"
        "mov rdx, qword ptr [rax + r10]\n"
        "mov rax, qword ptr [rbx + 0x10]\n"
        "mov ecx, dword ptr [rax + 8]\n"
        "mov rax, qword ptr [rbx + 8]\n"
        "test byte ptr [rcx + rax + 3], 0xf\n"
        "je .L_354dc_3552b\n"
        "movzx eax, byte ptr [rcx + rax + 3]\n"
        "and eax, 0xfffffff0\n"
        "apw_add64_load reg_r9, reg_rax\n"
        ".L_354dc_3552b:\n"
        "apw_xor64_load reg_r9, reg_rdx\n"
        "apw_mov64_load reg_rcx, reg_r9\n"
        "pop rbx\n"
        "jmp rva_35630\n"
        END);
}

/* body 0x35538 until 0x355b7 */
BODY void apw_35538(void) {
    __asm__(INTEL
        "apw_mov64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rax + 8], rbx\n"
        "mov qword ptr [rax + 0x10], rbp\n"
        "mov qword ptr [rax + 0x18], rsi\n"
        "mov qword ptr [rax + 0x20], rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "mov rbx, qword ptr [r9 + 0x38]\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_r14, reg_r8\n"
        "apw_mov64_load reg_rbp, reg_rcx\n"
        "apw_mov64_load reg_rdx, reg_r9\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "apw_mov64_load reg_rdi, reg_r9\n"
        "lea r8, [rbx + 4]\n"
        "call rva_354dc\n"
        "mov eax, dword ptr [rbp + 4]\n"
        "and al, 0x66\n"
        "neg al\n"
        "mov eax, 1\n"
        "apw_sbb32_load reg_r8d, reg_r8d\n"
        "neg r8d\n"
        "apw_add32_load reg_r8d, reg_eax\n"
        "test dword ptr [rbx + 4], r8d\n"
        "je .L_35538_3559c\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "call rva_36298\n"
        ".L_35538_3559c:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rbp, qword ptr [rsp + 0x38]\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "mov rdi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        END);
}

/* body 0x355d0 until 0x3561e */
BODY void apw_355d0(void) {
    __asm__(INTEL
        "sub rsp, 0x10\n"
        "mov qword ptr [rsp], r10\n"
        "mov qword ptr [rsp + 8], r11\n"
        "apw_xor64_load reg_r11, reg_r11\n"
        "lea r10, [rsp + 0x18]\n"
        "apw_sub64_load reg_r10, reg_rax\n"
        "cmovb r10, r11\n"
        "mov r11, qword ptr gs:[0x10]\n"
        "apw_cmp64_load reg_r10, reg_r11\n"
        "jae .L_355d0_35610\n"
        "and r10w, 0xf000\n"
        ".L_355d0_35600:\n"
        "lea r11, [r11 - 0x1000]\n"
        "mov byte ptr [r11], 0\n"
        "apw_cmp64_load reg_r10, reg_r11\n"
        "jne .L_355d0_35600\n"
        ".L_355d0_35610:\n"
        "mov r10, qword ptr [rsp]\n"
        "mov r11, qword ptr [rsp + 8]\n"
        "add rsp, 0x10\n"
        "ret\n"
        END);
}

/* body 0x35630 until 0x3564e */
BODY void apw_35630(void) {
    __asm__(INTEL
        "cmp rcx, qword ptr [rip + rva_52888]\n"
        "jne .L_35630_35649\n"
        "rol rcx, 0x10\n"
        "test cx, 0xffff\n"
        "jne .L_35630_35645\n"
        "ret\n"
        ".L_35630_35645:\n"
        "ror rcx, 0x10\n"
        ".L_35630_35649:\n"
        "jmp rva_35684\n"
        END);
}

/* body 0x35650 until 0x35684 */
BODY void apw_35650(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a188]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a190]\n"
        "call qword ptr [rip + rva_3a220]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov edx, 0xc0000409\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a368]\n"
        END);
}

/* body 0x35684 until 0x35756 */
BODY void apw_35684(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rcx\n"
        "sub rsp, 0x38\n"
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_3a180]\n"
        "test eax, eax\n"
        "je .L_35684_356a3\n"
        "mov ecx, 2\n"
        "int 0x29\n"
        ".L_35684_356a3:\n"
        "lea rcx, [rip + rva_542c0]\n"
        "call rva_35878\n"
        "mov rax, qword ptr [rsp + 0x38]\n"
        "mov qword ptr [rip + rva_543b8], rax\n"
        "lea rax, [rsp + 0x38]\n"
        "add rax, 8\n"
        "mov qword ptr [rip + rva_54358], rax\n"
        "mov rax, qword ptr [rip + rva_543b8]\n"
        "mov qword ptr [rip + rva_54230], rax\n"
        "mov rax, qword ptr [rsp + 0x40]\n"
        "mov qword ptr [rip + rva_54340], rax\n"
        "mov dword ptr [rip + rva_54220], 0xc0000409\n"
        "mov dword ptr [rip + rva_54224], 1\n"
        "mov dword ptr [rip + rva_54238], 1\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "lea rcx, [rip + rva_54240]\n"
        "mov qword ptr [rcx + rax], 2\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "mov rcx, qword ptr [rip + rva_52888]\n"
        "mov qword ptr [rsp + rax + 0x20], rcx\n"
        "mov eax, 8\n"
        "imul rax, rax, 1\n"
        "mov rcx, qword ptr [rip + rva_52880]\n"
        "mov qword ptr [rsp + rax + 0x20], rcx\n"
        "lea rcx, [rip + rva_42ac0]\n"
        "call rva_35650\n"
        "add rsp, 0x38\n"
        "ret\n"
        END);
}

/* body 0x35758 until 0x3576b */
BODY void apw_35758(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov ecx, 8\n"
        "call rva_3576c\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x3576c until 0x35808 */
BODY void apw_3576c(void) {
    __asm__(INTEL
        "mov dword ptr [rsp + 8], ecx\n"
        "sub rsp, 0x28\n"
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_3a180]\n"
        "test eax, eax\n"
        "je .L_3576c_3578b\n"
        "mov eax, dword ptr [rsp + 0x30]\n"
        "apw_mov32_load reg_ecx, reg_eax\n"
        "int 0x29\n"
        ".L_3576c_3578b:\n"
        "lea rcx, [rip + rva_542c0]\n"
        "call rva_35808\n"
        "mov rax, qword ptr [rsp + 0x28]\n"
        "mov qword ptr [rip + rva_543b8], rax\n"
        "lea rax, [rsp + 0x28]\n"
        "add rax, 8\n"
        "mov qword ptr [rip + rva_54358], rax\n"
        "mov rax, qword ptr [rip + rva_543b8]\n"
        "mov qword ptr [rip + rva_54230], rax\n"
        "mov dword ptr [rip + rva_54220], 0xc0000409\n"
        "mov dword ptr [rip + rva_54224], 1\n"
        "mov dword ptr [rip + rva_54238], 1\n"
        "mov eax, 8\n"
        "imul rax, rax, 0\n"
        "lea rcx, [rip + rva_54240]\n"
        "mov edx, dword ptr [rsp + 0x30]\n"
        "mov qword ptr [rcx + rax], rdx\n"
        "lea rcx, [rip + rva_42ac0]\n"
        "call rva_35650\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x35808 until 0x35875 */
BODY void apw_35808(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x20], rbx\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call qword ptr [rip + rva_3a1a8]\n"
        "mov rdi, qword ptr [rbx + 0xf8]\n"
        "lea rdx, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "call qword ptr [rip + rva_3a1a0]\n"
        "test rax, rax\n"
        "je .L_35808_3586a\n"
        "and qword ptr [rsp + 0x38], 0\n"
        "lea rcx, [rsp + 0x58]\n"
        "mov rdx, qword ptr [rsp + 0x50]\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "mov qword ptr [rsp + 0x30], rcx\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "lea rcx, [rsp + 0x60]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "call qword ptr [rip + rva_3a198]\n"
        ".L_35808_3586a:\n"
        "mov rbx, qword ptr [rsp + 0x68]\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x35878 until 0x358e9 */
BODY void apw_35878(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call qword ptr [rip + rva_3a1a8]\n"
        "mov rsi, qword ptr [rbx + 0xf8]\n"
        "apw_xor32_load reg_edi, reg_edi\n"
        ".L_35878_35892:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rsp + 0x60]\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3a1a0]\n"
        "test rax, rax\n"
        "je .L_35878_358e1\n"
        "and qword ptr [rsp + 0x38], 0\n"
        "lea rcx, [rsp + 0x68]\n"
        "mov rdx, qword ptr [rsp + 0x60]\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "mov qword ptr [rsp + 0x30], rcx\n"
        "apw_mov64_load reg_r8, reg_rsi\n"
        "lea rcx, [rsp + 0x70]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "mov qword ptr [rsp + 0x20], rbx\n"
        "call qword ptr [rip + rva_3a198]\n"
        "inc edi\n"
        "cmp edi, 2\n"
        "jl .L_35878_35892\n"
        ".L_35878_358e1:\n"
        "add rsp, 0x40\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x358ec until 0x35971 */
BODY void apw_358ec(void) {
    __asm__(INTEL
        "apw_mov64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rax + 8], rbx\n"
        "mov qword ptr [rax + 0x10], rbp\n"
        "mov qword ptr [rax + 0x18], rsi\n"
        "mov qword ptr [rax + 0x20], rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        "mov r10, qword ptr [r9 + 0x38]\n"
        "apw_mov64_load reg_rsi, reg_rdx\n"
        "apw_mov64_load reg_r14, reg_r8\n"
        "apw_mov64_load reg_rbp, reg_rcx\n"
        "apw_mov64_load reg_rdx, reg_r9\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "apw_mov64_load reg_rdi, reg_r9\n"
        "mov ebx, dword ptr [r10]\n"
        "shl rbx, 4\n"
        "apw_add64_load reg_rbx, reg_r10\n"
        "lea r8, [rbx + 4]\n"
        "call rva_354dc\n"
        "mov eax, dword ptr [rbp + 4]\n"
        "and al, 0x66\n"
        "neg al\n"
        "mov eax, 1\n"
        "apw_sbb32_load reg_edx, reg_edx\n"
        "neg edx\n"
        "apw_add32_load reg_edx, reg_eax\n"
        "test dword ptr [rbx + 4], edx\n"
        "je .L_358ec_35956\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_mov64_load reg_rcx, reg_rbp\n"
        "call rva_362e0\n"
        ".L_358ec_35956:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rbp, qword ptr [rsp + 0x38]\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "mov rdi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        END);
}

/* body 0x35974 until 0x359c4 */
BODY void apw_35974(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "test edx, edx\n"
        "je .L_35974_359b5\n"
        "sub edx, 1\n"
        "je .L_35974_359a9\n"
        "sub edx, 1\n"
        "je .L_35974_3599c\n"
        "cmp edx, 1\n"
        "je .L_35974_35995\n"
        "mov eax, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_35974_35995:\n"
        "call rva_351ec\n"
        "jmp .L_35974_359a1\n"
        ".L_35974_3599c:\n"
        "call rva_351c4\n"
        ".L_35974_359a1:\n"
        "movzx eax, al\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".L_35974_359a9:\n"
        "apw_mov64_load reg_rdx, reg_r8\n"
        "add rsp, 0x28\n"
        "jmp rva_359c4\n"
        ".L_35974_359b5:\n"
        "test r8, r8\n"
        "setne cl\n"
        "add rsp, 0x28\n"
        "jmp rva_35adc\n"
        END);
}

/* body 0x35c94 until 0x35cd1 */
BODY void apw_35c94(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "apw_mov32_load reg_ebx, reg_edx\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        "cmp edx, 1\n"
        "jne .L_35c94_35cb5\n"
        "call rva_35fe0\n"
        ".L_35c94_35cb5:\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov32_load reg_edx, reg_ebx\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "jmp rva_35b60\n"
        END);
}

/* body 0x35cd4 until 0x35e80 */
BODY void apw_35cd4(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "sub rsp, 0x10\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "cpuid\n"
        "apw_mov32_load reg_r8d, reg_ecx\n"
        "apw_xor32_load reg_r11d, reg_r11d\n"
        "apw_mov32_load reg_r10d, reg_edx\n"
        "xor r8d, 0x6c65746e\n"
        "xor r10d, 0x49656e69\n"
        "apw_mov32_load reg_r9d, reg_ebx\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "lea eax, [r11 + 1]\n"
        "apw_or32_load reg_r10d, reg_r8d\n"
        "cpuid\n"
        "xor r9d, 0x756e6547\n"
        "mov dword ptr [rsp], eax\n"
        "apw_or32_load reg_r10d, reg_r9d\n"
        "mov dword ptr [rsp + 4], ebx\n"
        "apw_mov32_load reg_edi, reg_ecx\n"
        "mov dword ptr [rsp + 8], ecx\n"
        "mov dword ptr [rsp + 0xc], edx\n"
        "jne .L_35cd4_35d88\n"
        "or qword ptr [rip + rva_528a8], 0xffffffffffffffff\n"
        "and eax, 0xfff3ff0\n"
        "mov qword ptr [rip + rva_528a0], 0x8000\n"
        "cmp eax, 0x106c0\n"
        "je .L_35cd4_35d74\n"
        "cmp eax, 0x20660\n"
        "je .L_35cd4_35d74\n"
        "cmp eax, 0x20670\n"
        "je .L_35cd4_35d74\n"
        "add eax, 0xfffcf9b0\n"
        "cmp eax, 0x20\n"
        "ja .L_35cd4_35d88\n"
        "movabs rcx, 0x100010001\n"
        "bt rcx, rax\n"
        "jae .L_35cd4_35d88\n"
        ".L_35cd4_35d74:\n"
        "mov r8d, dword ptr [rip + rva_54794]\n"
        "or r8d, 1\n"
        "mov dword ptr [rip + rva_54794], r8d\n"
        "jmp .L_35cd4_35d8f\n"
        ".L_35cd4_35d88:\n"
        "mov r8d, dword ptr [rip + rva_54794]\n"
        ".L_35cd4_35d8f:\n"
        "mov eax, 7\n"
        "lea r9d, [rax - 5]\n"
        "apw_cmp32_load reg_esi, reg_eax\n"
        "jl .L_35cd4_35dc2\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "cpuid\n"
        "mov dword ptr [rsp], eax\n"
        "apw_mov32_load reg_r11d, reg_ebx\n"
        "mov dword ptr [rsp + 4], ebx\n"
        "mov dword ptr [rsp + 8], ecx\n"
        "mov dword ptr [rsp + 0xc], edx\n"
        "bt ebx, 9\n"
        "jae .L_35cd4_35dc2\n"
        "apw_or32_load reg_r8d, reg_r9d\n"
        "mov dword ptr [rip + rva_54794], r8d\n"
        ".L_35cd4_35dc2:\n"
        "mov dword ptr [rip + rva_52898], 1\n"
        "mov dword ptr [rip + rva_5289c], r9d\n"
        "bt edi, 0x14\n"
        "jae .L_35cd4_35e6e\n"
        "mov dword ptr [rip + rva_52898], r9d\n"
        "mov ebx, 6\n"
        "mov dword ptr [rip + rva_5289c], ebx\n"
        "bt edi, 0x1b\n"
        "jae .L_35cd4_35e6e\n"
        "bt edi, 0x1c\n"
        "jae .L_35cd4_35e6e\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "xgetbv\n"
        "shl rdx, 0x20\n"
        "apw_or64_load reg_rdx, reg_rax\n"
        "mov qword ptr [rsp + 0x20], rdx\n"
        "mov rax, qword ptr [rsp + 0x20]\n"
        "apw_and8_load reg_al, reg_bl\n"
        "apw_cmp8_load reg_al, reg_bl\n"
        "jne .L_35cd4_35e6e\n"
        "mov eax, dword ptr [rip + rva_5289c]\n"
        "or eax, 8\n"
        "mov dword ptr [rip + rva_52898], 3\n"
        "mov dword ptr [rip + rva_5289c], eax\n"
        "test r11b, 0x20\n"
        "je .L_35cd4_35e6e\n"
        "or eax, 0x20\n"
        "mov dword ptr [rip + rva_52898], 5\n"
        "mov dword ptr [rip + rva_5289c], eax\n"
        "mov eax, 0xd0030000\n"
        "apw_and32_load reg_r11d, reg_eax\n"
        "apw_cmp32_load reg_r11d, reg_eax\n"
        "jne .L_35cd4_35e6e\n"
        "mov rax, qword ptr [rsp + 0x20]\n"
        "and al, 0xe0\n"
        "cmp al, 0xe0\n"
        "jne .L_35cd4_35e6e\n"
        "or dword ptr [rip + rva_5289c], 0x40\n"
        "mov dword ptr [rip + rva_52898], ebx\n"
        ".L_35cd4_35e6e:\n"
        "mov rbx, qword ptr [rsp + 0x28]\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rsi, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x10\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x35e80 until 0x35e8c */
BODY void apw_35e80(void) {
    __asm__(INTEL
        "apw_xor32_load reg_eax, reg_eax\n"
        "cmp dword ptr [rip + rva_528b0], eax\n"
        "setne al\n"
        "ret\n"
        END);
}

/* body 0x35e8c until 0x35e94 */
BODY void apw_35e8c(void) {
    __asm__(INTEL
        "and dword ptr [rip + rva_54798], 0\n"
        "ret\n"
        END);
}

/* body 0x35e94 until 0x35fdf */
BODY void apw_35e94(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rbp\n"
        "lea rbp, [rsp - 0x4c0]\n"
        "sub rsp, 0x5c0\n"
        "apw_mov32_load reg_ebx, reg_ecx\n"
        "mov ecx, 0x17\n"
        "call qword ptr [rip + rva_3a180]\n"
        "test eax, eax\n"
        "je .L_35e94_35ebe\n"
        "apw_mov32_load reg_ecx, reg_ebx\n"
        "int 0x29\n"
        ".L_35e94_35ebe:\n"
        "mov ecx, 3\n"
        "call rva_35e8c\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rbp - 0x10]\n"
        "mov r8d, 0x4d0\n"
        "call rva_3629e\n"
        "lea rcx, [rbp - 0x10]\n"
        "call qword ptr [rip + rva_3a1a8]\n"
        "mov rbx, qword ptr [rbp + 0xe8]\n"
        "lea rdx, [rbp + 0x4d8]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "call qword ptr [rip + rva_3a1a0]\n"
        "test rax, rax\n"
        "je .L_35e94_35f3e\n"
        "and qword ptr [rsp + 0x38], 0\n"
        "lea rcx, [rbp + 0x4e0]\n"
        "mov rdx, qword ptr [rbp + 0x4d8]\n"
        "apw_mov64_load reg_r9, reg_rax\n"
        "mov qword ptr [rsp + 0x30], rcx\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "lea rcx, [rbp + 0x4e8]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "lea rcx, [rbp - 0x10]\n"
        "mov qword ptr [rsp + 0x20], rcx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a198]\n"
        ".L_35e94_35f3e:\n"
        "mov rax, qword ptr [rbp + 0x4c8]\n"
        "lea rcx, [rsp + 0x50]\n"
        "mov qword ptr [rbp + 0xe8], rax\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rax, [rbp + 0x4c8]\n"
        "mov r8d, 0x98\n"
        "add rax, 8\n"
        "mov qword ptr [rbp + 0x88], rax\n"
        "call rva_3629e\n"
        "mov rax, qword ptr [rbp + 0x4c8]\n"
        "mov qword ptr [rsp + 0x60], rax\n"
        "mov dword ptr [rsp + 0x50], 0x40000015\n"
        "mov dword ptr [rsp + 0x54], 1\n"
        "call qword ptr [rip + rva_3a178]\n"
        "cmp eax, 1\n"
        "lea rax, [rsp + 0x50]\n"
        "mov qword ptr [rsp + 0x40], rax\n"
        "lea rax, [rbp - 0x10]\n"
        "sete bl\n"
        "mov qword ptr [rsp + 0x48], rax\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a188]\n"
        "lea rcx, [rsp + 0x40]\n"
        "call qword ptr [rip + rva_3a190]\n"
        "test eax, eax\n"
        "jne .L_35e94_35fce\n"
        "test bl, bl\n"
        "jne .L_35e94_35fce\n"
        "lea ecx, [rax + 3]\n"
        "call rva_35e8c\n"
        ".L_35e94_35fce:\n"
        "mov rbx, qword ptr [rsp + 0x5d0]\n"
        "add rsp, 0x5c0\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x35fe0 until 0x3608c */
BODY void apw_35fe0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "push rbp\n"
        "apw_mov64_load reg_rbp, reg_rsp\n"
        "sub rsp, 0x30\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "movabs rbx, 0x2b992ddfa232\n"
        "apw_cmp64_load reg_rax, reg_rbx\n"
        "jne .L_35fe0_36077\n"
        "and qword ptr [rbp + 0x10], 0\n"
        "lea rcx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_3a160]\n"
        "mov rax, qword ptr [rbp + 0x10]\n"
        "mov qword ptr [rbp - 0x10], rax\n"
        "call qword ptr [rip + rva_3a210]\n"
        "apw_mov32_load reg_eax, reg_eax\n"
        "xor qword ptr [rbp - 0x10], rax\n"
        "call qword ptr [rip + rva_3a168]\n"
        "apw_mov32_load reg_eax, reg_eax\n"
        "lea rcx, [rbp + 0x18]\n"
        "xor qword ptr [rbp - 0x10], rax\n"
        "call qword ptr [rip + rva_3a170]\n"
        "mov eax, dword ptr [rbp + 0x18]\n"
        "lea rcx, [rbp - 0x10]\n"
        "shl rax, 0x20\n"
        "xor rax, qword ptr [rbp + 0x18]\n"
        "xor rax, qword ptr [rbp - 0x10]\n"
        "apw_xor64_load reg_rax, reg_rcx\n"
        "movabs rcx, 0xffffffffffff\n"
        "apw_and64_load reg_rax, reg_rcx\n"
        "movabs rcx, 0x2b992ddfa233\n"
        "apw_cmp64_load reg_rax, reg_rbx\n"
        "cmove rax, rcx\n"
        "mov qword ptr [rip + rva_52888], rax\n"
        ".L_35fe0_36077:\n"
        "mov rbx, qword ptr [rsp + 0x50]\n"
        "not rax\n"
        "mov qword ptr [rip + rva_52880], rax\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x3608c until 0x3609a */
BODY void apw_3608c(void) {
    __asm__(INTEL
        "lea rcx, [rip + rva_547a0]\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a158]\n"
        END);
}

/* body 0x3609c until 0x360a8 */
BODY void apw_3609c(void) {
    __asm__(INTEL
        "lea rcx, [rip + rva_547a0]\n"
        "jmp rva_362e6\n"
        END);
}

/* body 0x360a8 until 0x360b0 */
BODY void apw_360a8(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_547b0]\n"
        "ret\n"
        END);
}

/* body 0x360b0 until 0x360cb */
BODY void apw_360b0(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "call rva_1cd0\n"
        "or qword ptr [rax], 0x24\n"
        "call rva_360a8\n"
        "or qword ptr [rax], 2\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x360cc until 0x360d4 */
BODY void apw_360cc(void) {
    __asm__(INTEL
        "lea rax, [rip + rva_54870]\n"
        "ret\n"
        END);
}

/* body 0x36150 until 0x36156 */
BODY void apw_36150(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a580]\n"
        END);
}

/* body 0x36158 until 0x361fd */
BODY void apw_36158(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "lea r8d, [rdx + 0x28]\n"
        "apw_add64_load reg_rcx, reg_r8\n"
        "call rva_3629e\n"
        "and qword ptr [rdi + 0x50], 0\n"
        "lea rax, [rip + rva_0]\n"
        "and dword ptr [rdi + 0x58], 0\n"
        "lea rcx, [rdi + 0x28]\n"
        "and dword ptr [rdi + 0x5c], 0\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov qword ptr [rdi + 0x10], rax\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov qword ptr [rdi + 8], rax\n"
        "lea rax, [rip + rva_42b48]\n"
        "mov qword ptr [rdi + 0x20], rax\n"
        "mov dword ptr [rdi], 0x60\n"
        "mov dword ptr [rdi + 0x18], 0xe00\n"
        "call rva_1cc0\n"
        "test eax, eax\n"
        "jne .L_36158_361ef\n"
        "call qword ptr [rip + rva_3a350]\n"
        "movzx ecx, ax\n"
        "or ecx, 0x80070000\n"
        "test eax, eax\n"
        "cmovle ecx, eax\n"
        "test ecx, ecx\n"
        "jns .L_36158_361ef\n"
        "call qword ptr [rip + rva_3a178]\n"
        "test eax, eax\n"
        "je .L_36158_361e8\n"
        "lea rcx, [rip + rva_42b60]\n"
        "call qword ptr [rip + rva_3a150]\n"
        ".L_36158_361e8:\n"
        "mov byte ptr [rip + rva_534b0], 1\n"
        ".L_36158_361ef:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x36200 until 0x36234 */
BODY void apw_36200(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "add rcx, 0x28\n"
        "call qword ptr [rip + rva_3a360]\n"
        "mov rcx, qword ptr [rbx + 0x50]\n"
        "test rcx, rcx\n"
        "je .L_36200_36226\n"
        "call rva_362ec\n"
        "and qword ptr [rbx + 0x50], 0\n"
        ".L_36200_36226:\n"
        "and dword ptr [rbx + 0x58], 0\n"
        "and dword ptr [rbx + 0x5c], 0\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x3623a until 0x36240 */
BODY void apw_3623a(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a4b8]\n"
        END);
}

/* body 0x36240 until 0x36246 */
BODY void apw_36240(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a4b0]\n"
        END);
}

/* body 0x36248 until 0x36280 */
BODY void apw_36248(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbx\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "mov ecx, 0x10\n"
        "call rva_34f86\n"
        "mov qword ptr [rsp + 0x38], rax\n"
        "test rax, rax\n"
        "je .L_36248_36273\n"
        "mov rdx, qword ptr [rip + rva_54828]\n"
        "mov qword ptr [rax], rdx\n"
        "mov qword ptr [rax + 8], rbx\n"
        ".L_36248_36273:\n"
        "mov qword ptr [rip + rva_54828], rax\n"
        "add rsp, 0x20\n"
        "pop rbx\n"
        "ret\n"
        END);
}

/* body 0x36280 until 0x36286 */
BODY void apw_36280(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a4a0]\n"
        END);
}

/* body 0x36286 until 0x3628c */
BODY void apw_36286(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a3a0]\n"
        END);
}

/* body 0x3628c until 0x36292 */
BODY void apw_3628c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a398]\n"
        END);
}

/* body 0x36298 until 0x3629e */
BODY void apw_36298(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a688]\n"
        END);
}

/* body 0x3629e until 0x362a4 */
BODY void apw_3629e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a670]\n"
        END);
}

/* body 0x362a4 until 0x362aa */
BODY void apw_362a4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a668]\n"
        END);
}

/* body 0x362aa until 0x362b0 */
BODY void apw_362aa(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a660]\n"
        END);
}

/* body 0x362b0 until 0x362b6 */
BODY void apw_362b0(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a658]\n"
        END);
}

/* body 0x362b6 until 0x362bc */
BODY void apw_362b6(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a650]\n"
        END);
}

/* body 0x362bc until 0x362c2 */
BODY void apw_362bc(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a648]\n"
        END);
}

/* body 0x362c2 until 0x362c8 */
BODY void apw_362c2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a640]\n"
        END);
}

/* body 0x362c8 until 0x362ce */
BODY void apw_362c8(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a620]\n"
        END);
}

/* body 0x362ce until 0x362d4 */
BODY void apw_362ce(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a618]\n"
        END);
}

/* body 0x362d4 until 0x362da */
BODY void apw_362d4(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a628]\n"
        END);
}

/* body 0x362da until 0x362e0 */
BODY void apw_362da(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a638]\n"
        END);
}

/* body 0x362e0 until 0x362e6 */
BODY void apw_362e0(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a630]\n"
        END);
}

/* body 0x362e6 until 0x362ec */
BODY void apw_362e6(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a610]\n"
        END);
}

/* body 0x362ec until 0x362f2 */
BODY void apw_362ec(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a728]\n"
        END);
}

/* body 0x362f2 until 0x362f8 */
BODY void apw_362f2(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a720]\n"
        END);
}

/* body 0x362f8 until 0x362fe */
BODY void apw_362f8(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a8a0]\n"
        END);
}

/* body 0x362fe until 0x36304 */
BODY void apw_362fe(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a778]\n"
        END);
}

/* body 0x36304 until 0x3630a */
BODY void apw_36304(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a760]\n"
        END);
}

/* body 0x3630a until 0x36310 */
BODY void apw_3630a(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a768]\n"
        END);
}

/* body 0x36310 until 0x36316 */
BODY void apw_36310(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a770]\n"
        END);
}

/* body 0x36316 until 0x3631c */
BODY void apw_36316(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a7b0]\n"
        END);
}

/* body 0x3631c until 0x36322 */
BODY void apw_3631c(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a788]\n"
        END);
}

/* body 0x36322 until 0x36328 */
BODY void apw_36322(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a790]\n"
        END);
}

/* body 0x36328 until 0x3632e */
BODY void apw_36328(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a780]\n"
        END);
}

/* body 0x3632e until 0x36334 */
BODY void apw_3632e(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a7a8]\n"
        END);
}

/* body 0x36334 until 0x3633a */
BODY void apw_36334(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_3a758]\n"
        END);
}

/* body 0x363e8 until 0x36486 */
BODY void apw_363e8(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "mov rax, qword ptr [rip + rva_54838]\n"
        "mov edi, 1\n"
        "apw_cmp64_load reg_rax, reg_rdi\n"
        "je .L_363e8_36479\n"
        "test rax, rax\n"
        "jne .L_363e8_36474\n"
        "lea rcx, [rip + rva_42be8]\n"
        "call qword ptr [rip + rva_3a2c0]\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "test rax, rax\n"
        "jne .L_363e8_36422\n"
        ".L_363e8_3641d:\n"
        "apw_mov64_load reg_rbx, reg_rdi\n"
        "jmp .L_363e8_3645a\n"
        ".L_363e8_36422:\n"
        "lea rdx, [rip + rva_42c08]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a300]\n"
        "test rax, rax\n"
        "je .L_363e8_3641d\n"
        "lea rdx, [rip + rva_42c20]\n"
        "mov qword ptr [rip + rva_54840], rax\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a300]\n"
        "test rax, rax\n"
        "je .L_363e8_3641d\n"
        "mov qword ptr [rip + rva_54848], rax\n"
        ".L_363e8_3645a:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "lock cmpxchg qword ptr [rip + rva_54838], rbx\n"
        "jne .L_363e8_3646c\n"
        "apw_cmp64_load reg_rbx, reg_rdi\n"
        "je .L_363e8_36479\n"
        ".L_363e8_3646c:\n"
        "apw_cmp64_load reg_rax, reg_rdi\n"
        "setne al\n"
        "jmp .L_363e8_3647b\n"
        ".L_363e8_36474:\n"
        "apw_mov8_load reg_al, reg_dil\n"
        "jmp .L_363e8_3647b\n"
        ".L_363e8_36479:\n"
        "apw_xor8_load reg_al, reg_al\n"
        ".L_363e8_3647b:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x36488 until 0x36520 */
BODY void apw_36488(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x80\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "mov r8d, 0x30\n"
        "lea rdx, [rsp + 0x20]\n"
        "apw_mov64_load reg_rbx, reg_rcx\n"
        "call qword ptr [rip + rva_3a140]\n"
        "test rax, rax\n"
        "jne .L_36488_364b6\n"
        "lea ecx, [rax + 0x19]\n"
        "int 0x29\n"
        ".L_36488_364b6:\n"
        "test byte ptr [rsp + 0x44], 0x44\n"
        "je .L_36488_3650f\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3a138]\n"
        "mov r9d, dword ptr [rsp + 0x54]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_mov32_load reg_r8d, reg_r9d\n"
        "neg r8\n"
        "apw_and64_load reg_r8, reg_rbx\n"
        "lea ecx, [r9 - 1]\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "apw_and32_load reg_ecx, reg_ebx\n"
        "apw_and32_load reg_eax, reg_edi\n"
        "apw_add32_load reg_eax, reg_ecx\n"
        "dec rax\n"
        "apw_add64_load reg_rax, reg_r9\n"
        "div r9\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "div r9\n"
        "apw_add64_load reg_rcx, reg_rax\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "test ecx, ecx\n"
        "je .L_36488_3650f\n"
        ".L_36488_36501:\n"
        "lock or dword ptr [r8], 0\n"
        "apw_add64_load reg_r8, reg_r9\n"
        "sub rax, 1\n"
        "jne .L_36488_36501\n"
        ".L_36488_3650f:\n"
        "mov rbx, qword ptr [rsp + 0x90]\n"
        "add rsp, 0x80\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x36520 until 0x365b9 */
BODY void apw_36520(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "mov qword ptr [rsp + 0x18], rdi\n"
        "movsxd r8, dword ptr [rip + rva_3c]\n"
        "lea rsi, [rip + rva_0]\n"
        "apw_add64_load reg_r8, reg_rsi\n"
        "apw_mov64_load reg_rbx, reg_rdx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "cmp dword ptr [r8 + 0x84], 0xd\n"
        "jbe .L_36520_36598\n"
        "mov r10d, dword ptr [r8 + 0xf0]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "test r10d, r10d\n"
        "je .L_36520_36598\n"
        "movzx ecx, word ptr [r8 + 0x14]\n"
        "movzx r11d, word ptr [r8 + 6]\n"
        "add rcx, 0x18\n"
        "mov r10d, dword ptr [r10 + rsi + 0xc]\n"
        "apw_add64_load reg_rcx, reg_r8\n"
        "test r11d, r11d\n"
        "je .L_36520_36598\n"
        ".L_36520_3657a:\n"
        "mov eax, dword ptr [rcx + 0xc]\n"
        "apw_cmp32_load reg_r10d, reg_eax\n"
        "jb .L_36520_3658c\n"
        "mov edx, dword ptr [rcx + 8]\n"
        "apw_add32_load reg_eax, reg_edx\n"
        "apw_cmp32_load reg_r10d, reg_eax\n"
        "jb .L_36520_365aa\n"
        ".L_36520_3658c:\n"
        "inc r9d\n"
        "add rcx, 0x28\n"
        "apw_cmp32_load reg_r9d, reg_r11d\n"
        "jb .L_36520_3657a\n"
        ".L_36520_36598:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_36520_3659a:\n"
        "mov rbx, qword ptr [rsp + 8]\n"
        "mov rsi, qword ptr [rsp + 0x10]\n"
        "mov rdi, qword ptr [rsp + 0x18]\n"
        "ret\n"
        ".L_36520_365aa:\n"
        "mov dword ptr [rdi], edx\n"
        "mov eax, dword ptr [rcx + 0x24]\n"
        "mov dword ptr [rbx], eax\n"
        "mov eax, dword ptr [rcx + 0xc]\n"
        "apw_add64_load reg_rax, reg_rsi\n"
        "jmp .L_36520_3659a\n"
        END);
}

/* body 0x365bc until 0x3664a */
BODY void apw_365bc(void) {
    __asm__(INTEL
        "apw_mov64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rax + 8], rbx\n"
        "mov qword ptr [rax + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov32_load reg_esi, reg_ecx\n"
        "lea rdx, [rax + 0x20]\n"
        "lea rcx, [rax + 0x18]\n"
        "call rva_36520\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "test rax, rax\n"
        "jne .L_365bc_365ee\n"
        "mov dword ptr [rdi], 4\n"
        "jmp .L_365bc_3663a\n"
        ".L_365bc_365ee:\n"
        "cmp dword ptr [rip + rva_54860], 0\n"
        "jne .L_365bc_3661e\n"
        "test dword ptr [rsp + 0x48], 0x80000000\n"
        "mov dword ptr [rip + rva_54860], 1\n"
        "jne .L_365bc_36612\n"
        "mov ecx, 0x19\n"
        "int 0x29\n"
        ".L_365bc_36612:\n"
        "mov edx, dword ptr [rsp + 0x40]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_36488\n"
        ".L_365bc_3661e:\n"
        "mov edx, dword ptr [rsp + 0x40]\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "apw_mov32_load reg_r8d, reg_esi\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a148]\n"
        "test eax, eax\n"
        "jne .L_365bc_3663a\n"
        "lea ecx, [rax + 0x19]\n"
        "int 0x29\n"
        ".L_365bc_3663a:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x36ac8 until 0x36acb */
BODY void apw_36ac8(void) {
    __asm__(INTEL
        "mov al, 1\n"
        "ret\n"
        END);
}

/* body 0x36b10 until 0x36b37 */
BODY void apw_36b10(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_36b10_36b31\n"
        "and dword ptr [rbp + 0x30], 0xfffffffe\n"
        "mov rcx, qword ptr [rbp + 0x50]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_36b10_36b31:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36ba0 until 0x36bc8 */
BODY void apw_36ba0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "lea rbp, [rdx + 0x30]\n"
        "mov rcx, qword ptr [rbp + 0x40]\n"
        "call rva_34f98\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36bd0 until 0x36bf8 */
BODY void apw_36bd0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "lea rbp, [rdx + 0x30]\n"
        "mov rcx, qword ptr [rbp + 0x48]\n"
        "call rva_34f98\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36c00 until 0x36c1d */
BODY void apw_36c00(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x380\n"
        "mov rcx, qword ptr [rbp + 0x28]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36c30 until 0x36c57 */
BODY void apw_36c30(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "call rva_34f98\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36c80 until 0x36ca8 */
BODY void apw_36c80(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "call rva_34f98\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36cd0 until 0x36cf0 */
BODY void apw_36cd0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x20]\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "cmp dword ptr [rax], 0xc00000fd\n"
        "sete cl\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36e30 until 0x36e61 */
BODY void apw_36e30(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_36e30_36e5b\n"
        "and dword ptr [rbp + 0x40], 0xfffffffe\n"
        "mov rcx, qword ptr [rbp + 0x90]\n"
        "add rcx, 0xb0\n"
        "call qword ptr [rip + rva_3a3c8]\n"
        ".L_36e30_36e5b:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x36eb0 until 0x36ecd */
BODY void apw_36eb0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x370e0 until 0x37108 */
BODY void apw_370e0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x30]\n"
        "mov eax, dword ptr [rbp + 8]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_370e0_37102\n"
        "and dword ptr [rbp + 8], 0xfffffffe\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_370e0_37102:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37110 until 0x37138 */
BODY void apw_37110(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x30]\n"
        "mov eax, dword ptr [rbp + 8]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_37110_37132\n"
        "and dword ptr [rbp + 8], 0xfffffffd\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37110_37132:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37140 until 0x37168 */
BODY void apw_37140(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x30]\n"
        "mov eax, dword ptr [rbp + 8]\n"
        "and eax, 4\n"
        "test eax, eax\n"
        "je .L_37140_37162\n"
        "and dword ptr [rbp + 8], 0xfffffffb\n"
        "lea rcx, [rbp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37140_37162:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37170 until 0x37198 */
BODY void apw_37170(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x30]\n"
        "mov eax, dword ptr [rbp + 8]\n"
        "and eax, 8\n"
        "test eax, eax\n"
        "je .L_37170_37192\n"
        "and dword ptr [rbp + 8], 0xfffffff7\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37170_37192:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x371d0 until 0x371ed */
BODY void apw_371d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x38]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37240 until 0x37267 */
BODY void apw_37240(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x48]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_37240_37261\n"
        "and dword ptr [rbp + 0x48], 0xfffffffe\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37240_37261:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37270 until 0x37297 */
BODY void apw_37270(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x48]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_37270_37291\n"
        "and dword ptr [rbp + 0x48], 0xfffffffd\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37270_37291:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x372a0 until 0x372c7 */
BODY void apw_372a0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x48]\n"
        "and eax, 4\n"
        "test eax, eax\n"
        "je .L_372a0_372c1\n"
        "and dword ptr [rbp + 0x48], 0xfffffffb\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_372a0_372c1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x372d0 until 0x372f7 */
BODY void apw_372d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x48]\n"
        "and eax, 8\n"
        "test eax, eax\n"
        "je .L_372d0_372f1\n"
        "and dword ptr [rbp + 0x48], 0xfffffff7\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_372d0_372f1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37380 until 0x373a7 */
BODY void apw_37380(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x20]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_37380_373a1\n"
        "and dword ptr [rbp + 0x20], 0xfffffffe\n"
        "mov rcx, qword ptr [rbp + 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37380_373a1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37700 until 0x37728 */
BODY void apw_37700(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_37700_37722\n"
        "and dword ptr [rbp + 0x30], 0xfffffffd\n"
        "lea rcx, [rbp + 8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37700_37722:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37830 until 0x3784d */
BODY void apw_37830(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37870 until 0x3788d */
BODY void apw_37870(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x58]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x378c0 until 0x378e7 */
BODY void apw_378c0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x48]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_378c0_378e1\n"
        "and dword ptr [rbp + 0x48], 0xfffffffe\n"
        "lea rcx, [rbp + 0x50]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_378c0_378e1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x378f0 until 0x37917 */
BODY void apw_378f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x48]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_378f0_37911\n"
        "and dword ptr [rbp + 0x48], 0xfffffffd\n"
        "lea rcx, [rbp + 0x68]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_378f0_37911:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37930 until 0x37962 */
BODY void apw_37930(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "lea rax, [rip + rva_41358]\n"
        "mov qword ptr [rbp + 0x68], rax\n"
        "lea rcx, [rbp + 0x70]\n"
        "call rva_362bc\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37ac0 until 0x37add */
BODY void apw_37ac0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "movabs rax, 0\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37af0 until 0x37b0d */
BODY void apw_37af0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0xf8\n"
        "mov rcx, qword ptr [rbp + 0x40]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37b10 until 0x37b2d */
BODY void apw_37b10(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0xf8\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37b30 until 0x37b57 */
BODY void apw_37b30(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x50]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_37b30_37b51\n"
        "and dword ptr [rbp + 0x50], 0xfffffffe\n"
        "lea rcx, [rbp + 0x68]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37b30_37b51:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37b60 until 0x37b8a */
BODY void apw_37b60(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x50]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_37b60_37b84\n"
        "and dword ptr [rbp + 0x50], 0xfffffffd\n"
        "lea rcx, [rbp + 0xd8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37b60_37b84:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37bb0 until 0x37bcd */
BODY void apw_37bb0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x68]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37cd0 until 0x37cf6 */
BODY void apw_37cd0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x20]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_37cd0_37cf0\n"
        "and dword ptr [rbp + 0x20], 0xfffffffe\n"
        "mov rcx, qword ptr [rbp + 0x48]\n"
        "call rva_8f40\n"
        ".L_37cd0_37cf0:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37d00 until 0x37d1d */
BODY void apw_37d00(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x40]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37d50 until 0x37db5 */
BODY void apw_37d50(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea r8, [rbp + 0x310]\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x38]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37e20 until 0x37e3d */
BODY void apw_37e20(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x70]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37e60 until 0x37e87 */
BODY void apw_37e60(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_37e60_37e81\n"
        "and dword ptr [rbp + 0x40], 0xfffffffe\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37e60_37e81:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37e90 until 0x37eb7 */
BODY void apw_37e90(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_37e90_37eb1\n"
        "and dword ptr [rbp + 0x40], 0xfffffffd\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37e90_37eb1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37ec0 until 0x37ee7 */
BODY void apw_37ec0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 4\n"
        "test eax, eax\n"
        "je .L_37ec0_37ee1\n"
        "and dword ptr [rbp + 0x40], 0xfffffffb\n"
        "lea rcx, [rbp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37ec0_37ee1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37ef0 until 0x37f17 */
BODY void apw_37ef0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 8\n"
        "test eax, eax\n"
        "je .L_37ef0_37f11\n"
        "and dword ptr [rbp + 0x40], 0xfffffff7\n"
        "lea rcx, [rbp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37ef0_37f11:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37f20 until 0x37f47 */
BODY void apw_37f20(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x10\n"
        "test eax, eax\n"
        "je .L_37f20_37f41\n"
        "and dword ptr [rbp + 0x40], 0xffffffef\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37f20_37f41:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37f50 until 0x37f77 */
BODY void apw_37f50(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x20\n"
        "test eax, eax\n"
        "je .L_37f50_37f71\n"
        "and dword ptr [rbp + 0x40], 0xffffffdf\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37f50_37f71:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37f80 until 0x37fa7 */
BODY void apw_37f80(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x40\n"
        "test eax, eax\n"
        "je .L_37f80_37fa1\n"
        "and dword ptr [rbp + 0x40], 0xffffffbf\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37f80_37fa1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37fb0 until 0x37fdc */
BODY void apw_37fb0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x80\n"
        "test eax, eax\n"
        "je .L_37fb0_37fd6\n"
        "and dword ptr [rbp + 0x40], 0xffffff7f\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37fb0_37fd6:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x37fe0 until 0x3800c */
BODY void apw_37fe0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x100\n"
        "test eax, eax\n"
        "je .L_37fe0_38006\n"
        "and dword ptr [rbp + 0x40], 0xfffffeff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_37fe0_38006:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38010 until 0x3803c */
BODY void apw_38010(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x200\n"
        "test eax, eax\n"
        "je .L_38010_38036\n"
        "and dword ptr [rbp + 0x40], 0xfffffdff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38010_38036:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38040 until 0x3806c */
BODY void apw_38040(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x400\n"
        "test eax, eax\n"
        "je .L_38040_38066\n"
        "and dword ptr [rbp + 0x40], 0xfffffbff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38040_38066:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38070 until 0x3809c */
BODY void apw_38070(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x800\n"
        "test eax, eax\n"
        "je .L_38070_38096\n"
        "and dword ptr [rbp + 0x40], 0xfffff7ff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38070_38096:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x380a0 until 0x380cc */
BODY void apw_380a0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x1000\n"
        "test eax, eax\n"
        "je .L_380a0_380c6\n"
        "and dword ptr [rbp + 0x40], 0xffffefff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_380a0_380c6:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x380d0 until 0x380fc */
BODY void apw_380d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x2000\n"
        "test eax, eax\n"
        "je .L_380d0_380f6\n"
        "and dword ptr [rbp + 0x40], 0xffffdfff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_380d0_380f6:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38100 until 0x3812c */
BODY void apw_38100(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x8000\n"
        "test eax, eax\n"
        "je .L_38100_38126\n"
        "and dword ptr [rbp + 0x40], 0xffff7fff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38100_38126:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38130 until 0x3815c */
BODY void apw_38130(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x10000\n"
        "test eax, eax\n"
        "je .L_38130_38156\n"
        "and dword ptr [rbp + 0x40], 0xfffeffff\n"
        "lea rcx, [rbp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38130_38156:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38160 until 0x3818c */
BODY void apw_38160(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x20000\n"
        "test eax, eax\n"
        "je .L_38160_38186\n"
        "and dword ptr [rbp + 0x40], 0xfffdffff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38160_38186:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38190 until 0x381bc */
BODY void apw_38190(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x40000\n"
        "test eax, eax\n"
        "je .L_38190_381b6\n"
        "and dword ptr [rbp + 0x40], 0xfffbffff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38190_381b6:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x381c0 until 0x381ec */
BODY void apw_381c0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x80000\n"
        "test eax, eax\n"
        "je .L_381c0_381e6\n"
        "and dword ptr [rbp + 0x40], 0xfff7ffff\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_381c0_381e6:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x381f0 until 0x3821c */
BODY void apw_381f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x100000\n"
        "test eax, eax\n"
        "je .L_381f0_38216\n"
        "and dword ptr [rbp + 0x40], 0xffefffff\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_381f0_38216:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38220 until 0x3824c */
BODY void apw_38220(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 0x200000\n"
        "test eax, eax\n"
        "je .L_38220_38246\n"
        "and dword ptr [rbp + 0x40], 0xffdfffff\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38220_38246:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38250 until 0x38277 */
BODY void apw_38250(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x38]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_38250_38271\n"
        "and dword ptr [rbp + 0x38], 0xfffffffe\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38250_38271:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38280 until 0x382a7 */
BODY void apw_38280(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x38]\n"
        "and eax, 8\n"
        "test eax, eax\n"
        "je .L_38280_382a1\n"
        "and dword ptr [rbp + 0x38], 0xfffffff7\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38280_382a1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x382b0 until 0x382d7 */
BODY void apw_382b0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x38]\n"
        "and eax, 0x20\n"
        "test eax, eax\n"
        "je .L_382b0_382d1\n"
        "and dword ptr [rbp + 0x38], 0xffffffdf\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_382b0_382d1:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x382e0 until 0x3830c */
BODY void apw_382e0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x38]\n"
        "and eax, 0x80\n"
        "test eax, eax\n"
        "je .L_382e0_38306\n"
        "and dword ptr [rbp + 0x38], 0xffffff7f\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_382e0_38306:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38350 until 0x38377 */
BODY void apw_38350(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_38350_38371\n"
        "and dword ptr [rbp + 0x30], 0xfffffffe\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38350_38371:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38390 until 0x383ba */
BODY void apw_38390(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_38390_383b4\n"
        "and dword ptr [rbp + 0x30], 0xfffffffe\n"
        "mov rcx, qword ptr [rbp + 0xa0]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38390_383b4:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x383d0 until 0x383fa */
BODY void apw_383d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_383d0_383f4\n"
        "and dword ptr [rbp + 0x30], 0xfffffffd\n"
        "lea rcx, [rbp + 0xb8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_383d0_383f4:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38400 until 0x3842a */
BODY void apw_38400(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 0x10\n"
        "test eax, eax\n"
        "je .L_38400_38424\n"
        "and dword ptr [rbp + 0x30], 0xffffffef\n"
        "lea rcx, [rbp + 0xb8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38400_38424:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38430 until 0x3845a */
BODY void apw_38430(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 0x40\n"
        "test eax, eax\n"
        "je .L_38430_38454\n"
        "and dword ptr [rbp + 0x30], 0xffffffbf\n"
        "lea rcx, [rbp + 0xb8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38430_38454:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38460 until 0x3848c */
BODY void apw_38460(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x30]\n"
        "and eax, 0x80\n"
        "test eax, eax\n"
        "je .L_38460_38486\n"
        "and dword ptr [rbp + 0x30], 0xffffff7f\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38460_38486:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38490 until 0x384ad */
BODY void apw_38490(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x50]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x387a0 until 0x387c8 */
BODY void apw_387a0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_387a0_387c2\n"
        "and dword ptr [rbp], 0xfffffffe\n"
        "lea rcx, [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_387a0_387c2:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x387d0 until 0x387f8 */
BODY void apw_387d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_387d0_387f2\n"
        "and dword ptr [rbp], 0xfffffffd\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_387d0_387f2:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38800 until 0x3882b */
BODY void apw_38800(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 4\n"
        "test eax, eax\n"
        "je .L_38800_38825\n"
        "and dword ptr [rbp], 0xfffffffb\n"
        "lea rcx, [rbp + 0x90]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38800_38825:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38830 until 0x38858 */
BODY void apw_38830(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 8\n"
        "test eax, eax\n"
        "je .L_38830_38852\n"
        "and dword ptr [rbp], 0xfffffff7\n"
        "lea rcx, [rbp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38830_38852:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38860 until 0x38888 */
BODY void apw_38860(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x10\n"
        "test eax, eax\n"
        "je .L_38860_38882\n"
        "and dword ptr [rbp], 0xffffffef\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38860_38882:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38890 until 0x388bb */
BODY void apw_38890(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x20\n"
        "test eax, eax\n"
        "je .L_38890_388b5\n"
        "and dword ptr [rbp], 0xffffffdf\n"
        "lea rcx, [rbp + 0x1e8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38890_388b5:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x388c0 until 0x388e8 */
BODY void apw_388c0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x40\n"
        "test eax, eax\n"
        "je .L_388c0_388e2\n"
        "and dword ptr [rbp], 0xffffffbf\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_388c0_388e2:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x388f0 until 0x38920 */
BODY void apw_388f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x80\n"
        "test eax, eax\n"
        "je .L_388f0_3891a\n"
        "and dword ptr [rbp], 0xffffff7f\n"
        "lea rcx, [rbp + 0x210]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_388f0_3891a:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38920 until 0x3894d */
BODY void apw_38920(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x100\n"
        "test eax, eax\n"
        "je .L_38920_38947\n"
        "and dword ptr [rbp], 0xfffffeff\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38920_38947:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38950 until 0x3897d */
BODY void apw_38950(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x200\n"
        "test eax, eax\n"
        "je .L_38950_38977\n"
        "and dword ptr [rbp], 0xfffffdff\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38950_38977:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38980 until 0x389ad */
BODY void apw_38980(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x400\n"
        "test eax, eax\n"
        "je .L_38980_389a7\n"
        "and dword ptr [rbp], 0xfffffbff\n"
        "lea rcx, [rbp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38980_389a7:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x389b0 until 0x389dd */
BODY void apw_389b0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x800\n"
        "test eax, eax\n"
        "je .L_389b0_389d7\n"
        "and dword ptr [rbp], 0xfffff7ff\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_389b0_389d7:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x389e0 until 0x38a0d */
BODY void apw_389e0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x1000\n"
        "test eax, eax\n"
        "je .L_389e0_38a07\n"
        "and dword ptr [rbp], 0xffffefff\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_389e0_38a07:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38a10 until 0x38a3d */
BODY void apw_38a10(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x2000\n"
        "test eax, eax\n"
        "je .L_38a10_38a37\n"
        "and dword ptr [rbp], 0xffffdfff\n"
        "lea rcx, [rbp + 0x40]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38a10_38a37:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38a40 until 0x38a6d */
BODY void apw_38a40(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x4000\n"
        "test eax, eax\n"
        "je .L_38a40_38a67\n"
        "and dword ptr [rbp], 0xffffbfff\n"
        "lea rcx, [rbp + 0x20]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38a40_38a67:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38a70 until 0x38a9d */
BODY void apw_38a70(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp]\n"
        "and eax, 0x8000\n"
        "test eax, eax\n"
        "je .L_38a70_38a97\n"
        "and dword ptr [rbp], 0xffff7fff\n"
        "lea rcx, [rbp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_38a70_38a97:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38ba0 until 0x38bc1 */
BODY void apw_38ba0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x198]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38bf0 until 0x38c11 */
BODY void apw_38bf0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x168]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38c20 until 0x38c41 */
BODY void apw_38c20(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x180]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38c50 until 0x38c6e */
BODY void apw_38c50(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x40]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38c70 until 0x38c91 */
BODY void apw_38c70(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x170]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38ca0 until 0x38d0f */
BODY void apw_38ca0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "lea rbp, [rdx + 0x40]\n"
        "lea rcx, [rbp + 0x108]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0x78]\n"
        "lea rcx, [rbp + 0x108]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x108]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x108]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38d10 until 0x38d89 */
BODY void apw_38d10(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "lea rbp, [rdx + 0x40]\n"
        "lea rcx, [rbp + 0x118]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0x48]\n"
        "lea rcx, [rbp + 0x118]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "mov rcx, qword ptr [rbp + 0x48]\n"
        "call qword ptr [rip + rva_3a278]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x118]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x118]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38db0 until 0x38e15 */
BODY void apw_38db0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "lea rcx, [rbp + 0x70]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea r8, [rbp + 0x300]\n"
        "lea rcx, [rbp + 0x70]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x70]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x70]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38ec0 until 0x38edd */
BODY void apw_38ec0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x48]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38ee0 until 0x38f00 */
BODY void apw_38ee0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x90]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38f20 until 0x38f40 */
BODY void apw_38f20(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x110]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38f40 until 0x38f60 */
BODY void apw_38f40(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0xa8]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38f80 until 0x38fe5 */
BODY void apw_38f80(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0x120]\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x38ff0 until 0x3907c */
BODY void apw_38ff0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41760]\n"
        "lea rdx, [rip + rva_41768]\n"
        "cmp eax, 1\n"
        "cmove rdx, rcx\n"
        "lea rcx, [rbp + 0x128]\n"
        "call qword ptr [rip + rva_3aa98]\n"
        "mov ecx, 0x593\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0x128]\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39090 until 0x390b0 */
BODY void apw_39090(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x80]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x390d0 until 0x390fa */
BODY void apw_390d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov eax, dword ptr [rbp + 0x40]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_390d0_390f4\n"
        "and dword ptr [rbp + 0x40], 0xfffffffd\n"
        "lea rcx, [rbp + 0xa8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_390d0_390f4:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39100 until 0x3914c */
BODY void apw_39100(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0x38]\n"
        "lea rcx, [rbp + 0x60]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x60]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39150 until 0x39178 */
BODY void apw_39150(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp + 0xc]\n"
        "and eax, 1\n"
        "test eax, eax\n"
        "je .L_39150_39172\n"
        "and dword ptr [rbp + 0xc], 0xfffffffe\n"
        "lea rcx, [rbp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_39150_39172:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39180 until 0x391a8 */
BODY void apw_39180(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp + 0xc]\n"
        "and eax, 2\n"
        "test eax, eax\n"
        "je .L_39180_391a2\n"
        "and dword ptr [rbp + 0xc], 0xfffffffd\n"
        "lea rcx, [rbp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_39180_391a2:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x391b0 until 0x391ce */
BODY void apw_391b0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x70]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x391e0 until 0x391fe */
BODY void apw_391e0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x38]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39200 until 0x39228 */
BODY void apw_39200(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov eax, dword ptr [rbp + 0xc]\n"
        "and eax, 8\n"
        "test eax, eax\n"
        "je .L_39200_39222\n"
        "and dword ptr [rbp + 0xc], 0xfffffff7\n"
        "lea rcx, [rbp + 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_39200_39222:\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39230 until 0x39280 */
BODY void apw_39230(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov ecx, 0x592\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0xe8]\n"
        "lea rcx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x10]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39290 until 0x392ae */
BODY void apw_39290(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x20]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x392b0 until 0x392ce */
BODY void apw_392b0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x48]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x392d0 until 0x392ee */
BODY void apw_392d0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "lea rbp, [rdx + 0x40]\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x392f0 until 0x39310 */
BODY void apw_392f0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x98]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39320 until 0x39385 */
BODY void apw_39320(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "lea rcx, [rbp + 0x68]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea r8, [rbp + 0x1f0]\n"
        "lea rcx, [rbp + 0x68]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x68]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x68]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39420 until 0x3943e */
BODY void apw_39420(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp + 0x28]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x394d0 until 0x394ee */
BODY void apw_394d0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "lea rbp, [rdx + 0x40]\n"
        "mov edx, 0x18\n"
        "mov rcx, qword ptr [rbp]\n"
        "call rva_35134\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39510 until 0x39573 */
BODY void apw_39510(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "lea rbp, [rdx + 0x40]\n"
        "lea rcx, [rbp + 0x50]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov ecx, 0x595\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "mov r8, qword ptr [rbp + 0x30]\n"
        "lea rcx, [rbp + 0x50]\n"
        "call qword ptr [rip + rva_3aa30]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r8d, [r9 - 1]\n"
        "mov rcx, qword ptr [rbp + 0x50]\n"
        "call rva_33f83\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x50]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39580 until 0x3959d */
BODY void apw_39580(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rdx\n"
        "push rbp\n"
        "sub rsp, 0x40\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "movabs rax, 0\n"
        "add rsp, 0x40\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x3959e until 0x395b5 */
BODY void apw_3959e(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "cmp dword ptr [rax], 0xc0000005\n"
        "sete cl\n"
        "apw_mov32_load reg_eax, reg_ecx\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x395b6 until 0x395cc */
BODY void apw_395b6(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov cl, byte ptr [rbp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "jmp rva_35418\n"
        END);
}

/* body 0x395cd until 0x395e5 */
BODY void apw_395cd(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov cl, byte ptr [rbp + 0x20]\n"
        "call rva_35418\n"
        ".byte 0x90 # alignment NOP\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x395e6 until 0x395f9 */
BODY void apw_395e6(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x20\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "add rsp, 0x20\n"
        "pop rbp\n"
        "jmp rva_35294\n"
        END);
}

/* body 0x395fa until 0x3962f */
BODY void apw_395fa(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "sub rsp, 0x30\n"
        "apw_mov64_load reg_rbp, reg_rdx\n"
        "mov rax, qword ptr [rcx]\n"
        "mov edx, dword ptr [rax]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "mov dword ptr [rsp + 0x20], edx\n"
        "lea r9, [rip + rva_35974]\n"
        "mov r8, qword ptr [rbp + 0x70]\n"
        "mov edx, dword ptr [rbp + 0x68]\n"
        "mov rcx, qword ptr [rbp + 0x60]\n"
        "call rva_35204\n"
        ".byte 0x90 # alignment NOP\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n"
        END);
}

/* body 0x39810 until 0x3981e */
BODY void apw_39810(void) {
    __asm__(INTEL
        "lea rcx, [rip + rva_52860]\n"
        ".byte 0x48 # original REX.W on near transfer\n        jmp qword ptr [rip + rva_3a510]\n"
        END);
}

/* body 0xdad0 until 0xeab0 */
BODY void apw_dad0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "lea rbp, [rsp - 0x4b8]\n"
        "sub rsp, 0x5b8\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x4a0], rax\n"
        "apw_mov64_load reg_r12, reg_r9\n"
        "mov dword ptr [rsp + 0x40], r8d\n"
        "apw_mov64_load reg_rdi, reg_rdx\n"
        "apw_mov64_load reg_r13, reg_rcx\n"
        "apw_xor32_load reg_r15d, reg_r15d\n"
        "lea esi, [r15 + 1]\n"
        "lea rcx, [rip + rva_419a8]\n"
        "call rva_34043\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [r13 + 0xf0]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "lea r14, [rip + rva_3ad3b]\n"
        "lea rdx, [rip + rva_419c0]\n"
        "lea rcx, [r13 + 0xf0]\n"
        "call qword ptr [rip + rva_3aa88]\n"
        "test eax, eax\n"
        "je .L_dad0_db54\n"
        "mov r14, qword ptr [r13 + 0xf0]\n"
        ".L_dad0_db54:\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aac8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rip + rva_3ad3b]\n"
        "lea rcx, [rsp + 0x68]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "mov dl, 0x2e\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "mov rax, qword ptr [rdi]\n"
        "mov ecx, dword ptr [rax - 0x10]\n"
        "dec ecx\n"
        "apw_cmp32_load reg_ebx, reg_ecx\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "jne .L_dad0_dbb0\n"
        "apw_mov32_load reg_r8d, reg_ebx\n"
        "lea rdx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "jmp .L_dad0_dbe4\n"
        ".L_dad0_dbb0:\n"
        "mov dl, 0x5c\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_cmp32_load reg_ebx, reg_eax\n"
        "jle .L_dad0_dbef\n"
        "mov rax, qword ptr [rdi]\n"
        "mov r8d, dword ptr [rax - 0x10]\n"
        "apw_sub32_load reg_r8d, reg_ebx\n"
        "lea rdx, [rsp + 0x30]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa40]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x68]\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_dad0_dbe4:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_dad0_dbef:\n"
        "mov rcx, qword ptr [rdi]\n"
        "cmp dword ptr [rcx - 0x10], 0\n"
        "je .L_dad0_dc0b\n"
        "mov edx, 2\n"
        "call qword ptr [rip + rva_53248]\n"
        "test eax, eax\n"
        "jne .L_dad0_ea09\n"
        ".L_dad0_dc0b:\n"
        "call rva_33f5f\n"
        "apw_mov32_load reg_edx, reg_r15d\n"
        "test eax, eax\n"
        "sete dl\n"
        "movsxd rbx, dword ptr [rsp + 0x40]\n"
        "apw_mov32_load reg_ecx, reg_ebx\n"
        "call qword ptr [rip + rva_53250]\n"
        "test eax, eax\n"
        "jne .L_dad0_ea09\n"
        "call rva_33cdc\n"
        "mov qword ptr [rsp + 0x70], rax\n"
        "lea rdx, [rip + rva_419d0]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x70]\n"
        "call rva_21b30\n"
        "mov qword ptr [rsp + 0x48], rax\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rcx, qword ptr [rsp + 0x70]\n"
        "mov rax, qword ptr [rcx]\n"
        "call qword ptr [rax + 0x10]\n"
        "lea rcx, [rbp - 0x80]\n"
        "call rva_34fda\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x80]\n"
        "call qword ptr [rip + rva_3a510]\n"
        "cmp qword ptr [rsp + 0x48], 0\n"
        "je .L_dad0_dce7\n"
        "lea rcx, [rbp - 0x38]\n"
        "call qword ptr [rip + rva_3a518]\n"
        "lea rcx, [rbp - 0x68]\n"
        "call qword ptr [rip + rva_3a518]\n"
        "movups xmm0, xmmword ptr [rbp - 0x38]\n"
        "movaps xmmword ptr [rbp - 0x20], xmm0\n"
        "movsd xmm1, qword ptr [rbp - 0x28]\n"
        "movsd qword ptr [rbp - 0x10], xmm1\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea r9, [rbp - 0x68]\n"
        "lea r8, [rbp - 0x20]\n"
        "call qword ptr [rax + 0x98]\n"
        "test eax, eax\n"
        "js .L_dad0_dce7\n"
        "lea rdx, [rbp - 0x68]\n"
        "lea rcx, [rbp - 0x80]\n"
        "call rva_34fd4\n"
        "lea rcx, [rbp - 0x68]\n"
        "call qword ptr [rip + rva_3a510]\n"
        ".L_dad0_dce7:\n"
        "mov r8d, 8\n"
        "lea rdx, [rip + rva_419f0]\n"
        "lea rcx, [rbp - 0x50]\n"
        "call rva_34fc2\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rax, [rbp + 8]\n"
        "mov qword ptr [rbp], rax\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov rdx, qword ptr [rbp - 0x78]\n"
        "lea rcx, [rbp]\n"
        "call rva_d880\n"
        ".byte 0x90 # alignment NOP\n"
        "mov rdx, qword ptr [rbp]\n"
        "lea rcx, [rsp + 0x78]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rax, [rbp + 8]\n"
        "mov rcx, qword ptr [rbp]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "je .L_dad0_dd3a\n"
        "call qword ptr [rip + rva_3a728]\n"
        ".L_dad0_dd3a:\n"
        "cmp ebx, 0x19\n"
        "ja .L_dad0_e9e7\n"
        "lea rdx, [rip + rva_0]\n"
        "mov ecx, dword ptr [rdx + rbx*4 + 0xea48]\n"
        "apw_add64_load reg_rcx, reg_rdx\n"
        "jmp rcx\n"
        ".L_dad0_dd56:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41670]\n"
        "lea r8, [rip + rva_41690]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_33dfc\n"
        "cmp qword ptr [r13 + 0x70], 0\n"
        "jne .L_dad0_ddbe\n"
        "lea rcx, [r13 + 0x40]\n"
        "cmp qword ptr [rcx + 0x18], 0x10\n"
        "jb .L_dad0_ddb8\n"
        "mov rcx, qword ptr [rcx]\n"
        ".L_dad0_ddb8:\n"
        "add r13, 0x60\n"
        "jmp .L_dad0_ddcf\n"
        ".L_dad0_ddbe:\n"
        "lea rcx, [r13 + 0x60]\n"
        "apw_mov64_load reg_r13, reg_rcx\n"
        "cmp qword ptr [rcx + 0x18], 0x10\n"
        "jb .L_dad0_ddcf\n"
        "mov rcx, qword ptr [rcx]\n"
        ".L_dad0_ddcf:\n"
        "call rva_33dfc\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "apw_mov32_load reg_ecx, reg_esi\n"
        "call rva_33dea\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "cmp byte ptr [r14], 0\n"
        "jne .L_dad0_e951\n"
        "cmp qword ptr [r13 + 0x18], 0x10\n"
        "jb .L_dad0_ddf8\n"
        "mov r13, qword ptr [r13]\n"
        ".L_dad0_ddf8:\n"
        "mov rdx, qword ptr [rdi]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call qword ptr [rip + rva_532f8]\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_de09:\n"
        "lea rdx, [rip + rva_419f8]\n"
        "lea rcx, [rsp + 0x78]\n"
        "call qword ptr [rip + rva_3aa80]\n"
        "test eax, eax\n"
        "jne .L_dad0_de2d\n"
        "lea rdx, [rbp - 0x50]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call rva_117d0\n"
        ".L_dad0_de2d:\n"
        "apw_mov32_load reg_ecx, reg_esi\n"
        "call rva_34749\n"
        "lea r8, [rip + rva_41690]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_33dfc\n"
        "cmp qword ptr [r13 + 0x70], 0\n"
        "lea rcx, [r13 + 0x40]\n"
        "je .L_dad0_de7a\n"
        "lea rcx, [r13 + 0x60]\n"
        ".L_dad0_de7a:\n"
        "cmp qword ptr [rcx + 0x18], 0x10\n"
        "jb .L_dad0_de84\n"
        "mov rcx, qword ptr [rcx]\n"
        ".L_dad0_de84:\n"
        "call rva_33dfc\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "apw_mov32_load reg_ecx, reg_esi\n"
        "call rva_33dea\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "lea rdx, [rbp - 0x80]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call rva_117d0\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_deab:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41a04]\n"
        "lea r8, [rip + rva_41a10]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 3\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_defa:\n"
        "apw_mov32_load reg_ecx, reg_esi\n"
        "call rva_34749\n"
        "lea r8, [rip + rva_41a10]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 3\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_df3a:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41750]\n"
        "lea r8, [rip + rva_41758]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 7\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_df89:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_4173c]\n"
        "lea r8, [rip + rva_41748]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 2\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_dfd8:\n"
        "lea r8, [rip + rva_41748]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 2\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e011:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_4173c]\n"
        "lea r8, [rip + rva_41748]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0x11\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e060:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_4173c]\n"
        "lea r8, [rip + rva_41748]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov ecx, 4\n"
        "call rva_33dea\n"
        "lea r8, [rip + rva_41678]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0xe\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e0ee:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_4173c]\n"
        "lea r8, [rip + rva_41748]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov ecx, 2\n"
        "call rva_33dea\n"
        "lea r8, [rip + rva_41678]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0xe\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e17c:\n"
        "lea r8, [rip + rva_41a18]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 5\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e1b5:\n"
        "lea r8, [rip + rva_41a20]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0x10\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e1ee:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_4173c]\n"
        "lea r8, [rip + rva_41748]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov ecx, 2\n"
        "call rva_33dea\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41a04]\n"
        "lea r8, [rip + rva_41a10]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_dad0_e27f:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov ecx, 3\n"
        "call rva_33dea\n"
        "apw_and32_load reg_esi, reg_eax\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e2a1:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41750]\n"
        "lea r8, [rip + rva_41758]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov ecx, 7\n"
        "call rva_33dea\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41a04]\n"
        "lea r8, [rip + rva_41a10]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "jmp .L_dad0_e27f\n"
        ".L_dad0_e337:\n"
        "apw_mov32_load reg_r13d, reg_r15d\n"
        "cmp ebx, 9\n"
        "setne r13b\n"
        "lea rcx, [rip + rva_41a28]\n"
        "call rva_34043\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "test rax, rax\n"
        "jne .L_dad0_e360\n"
        "lea ecx, [rax + 4]\n"
        "call rva_34f8c\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        ".L_dad0_e360:\n"
        "mov dword ptr [rbx], esi\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rip + rva_41a28]\n"
        "call rva_3401f\n"
        "mov rax, qword ptr [rsp + 0x68]\n"
        "cmp dword ptr [rax - 0x10], 0\n"
        "jne .L_dad0_e392\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "lea ecx, [r13 + 9]\n"
        "call rva_33dea\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "jmp .L_dad0_e3cb\n"
        ".L_dad0_e392:\n"
        "mov dl, 0x2e\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa60]\n"
        "apw_mov32_load reg_r8d, reg_eax\n"
        "lea rdx, [rsp + 0x30]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aa38]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rax]\n"
        "lea ecx, [r13 + 9]\n"
        "call rva_33dea\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_dad0_e3cb:\n"
        "lea r8, [rip + rva_41a3c]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov dword ptr [rbx], r15d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rip + rva_41a28]\n"
        "call rva_3401f\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e414:\n"
        "lea r8, [rip + rva_41a44]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "call rva_33bd0\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e44d:\n"
        "lea r8, [rip + rva_41a4c]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0xc\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e486:\n"
        "call rva_33bd0\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "cmp eax, 1\n"
        "jne .L_dad0_e4c9\n"
        "lea r8, [rip + rva_41a54]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0xd\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e4c9:\n"
        "lea r8, [rip + rva_41a60]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0xd\n"
        "jmp .L_dad0_e944\n"
        ".L_dad0_e4f8:\n"
        "apw_mov32_load reg_esi, reg_r15d\n"
        "lea r8, [rip + rva_41a68]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "call rva_33bd0\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e534:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41a70]\n"
        "lea r8, [rip + rva_41a78]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "call rva_33cca\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "apw_mov64_load reg_rbx, reg_r15\n"
        "mov qword ptr [rsp + 0x40], rbx\n"
        "test rax, rax\n"
        "je .L_dad0_e5af\n"
        "mov rax, qword ptr [rax]\n"
        "lea r8, [rsp + 0x40]\n"
        "lea rdx, [rip + rva_41998]\n"
        "call qword ptr [rax]\n"
        "test eax, eax\n"
        "jns .L_dad0_e5aa\n"
        "mov qword ptr [rsp + 0x40], rbx\n"
        "jmp .L_dad0_e5af\n"
        ".L_dad0_e5aa:\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        ".L_dad0_e5af:\n"
        "test rbx, rbx\n"
        "je .L_dad0_e5e8\n"
        "mov rdx, qword ptr [rdi]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_8700\n"
        "mov rdx, qword ptr [rax]\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x38]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "test ebx, ebx\n"
        "cmovne esi, r15d\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        ".L_dad0_e5e8:\n"
        "test rbx, rbx\n"
        "je .L_dad0_e951\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x10]\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e5ff:\n"
        "lea rdx, [rbp - 0x50]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call rva_117d0\n"
        "apw_mov32_load reg_ecx, reg_esi\n"
        "call rva_34749\n"
        "lea r8, [rip + rva_41a78]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "call rva_33cca\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "apw_mov64_load reg_rbx, reg_r15\n"
        "mov qword ptr [rsp + 0x40], rbx\n"
        "test rax, rax\n"
        "je .L_dad0_e679\n"
        "mov rax, qword ptr [rax]\n"
        "lea r8, [rsp + 0x40]\n"
        "lea rdx, [rip + rva_41998]\n"
        "call qword ptr [rax]\n"
        "test eax, eax\n"
        "jns .L_dad0_e674\n"
        "mov qword ptr [rsp + 0x40], rbx\n"
        "jmp .L_dad0_e679\n"
        ".L_dad0_e674:\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        ".L_dad0_e679:\n"
        "test rbx, rbx\n"
        "je .L_dad0_e6b2\n"
        "mov rdx, qword ptr [rdi]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_8700\n"
        "mov rdx, qword ptr [rax]\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x38]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "mov rcx, qword ptr [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "test ebx, ebx\n"
        "cmovne esi, r15d\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        ".L_dad0_e6b2:\n"
        "test rbx, rbx\n"
        "je .L_dad0_e6c0\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_dad0_e6c0:\n"
        "lea rdx, [rbp - 0x80]\n"
        "lea rcx, [rsp + 0x48]\n"
        "call rva_117d0\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e6d3:\n"
        "call qword ptr [rip + rva_531f8]\n"
        "apw_mov32_load reg_edi, reg_eax\n"
        "test eax, eax\n"
        "je .L_dad0_e951\n"
        "call rva_34f9e\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "call rva_34fa4\n"
        ".byte 0x90 # alignment NOP\n"
        "call rva_33f71\n"
        "apw_mov32_load reg_r14d, reg_eax\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_33ed4\n"
        "apw_mov32_load reg_ebx, reg_r15d\n"
        ".L_dad0_e704:\n"
        "bt edi, ebx\n"
        "jae .L_dad0_e819\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3aab0]\n"
        "lea r9, [rsp + 0x30]\n"
        "apw_mov32_load reg_r8d, reg_ebx\n"
        "lea rdx, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_dad0\n"
        "apw_and32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "jne .L_dad0_e802\n"
        "mov rax, qword ptr [r12]\n"
        "cmp dword ptr [rax - 0x10], 0\n"
        "jne .L_dad0_e775\n"
        "mov ecx, 0x579\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        ".L_dad0_e775:\n"
        "lea rax, [rbp + 0x90]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rbp + 0x190]\n"
        "lea r8, [rbp + 0x3a0]\n"
        "lea rdx, [rsp + 0x40]\n"
        "mov rcx, qword ptr [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3a6e8]\n"
        "lea rax, [rbp + 0x90]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "lea r9, [rbp + 0x190]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "lea rcx, [rbp + 0x290]\n"
        "call qword ptr [rip + rva_3a6d0]\n"
        "lea rdx, [rbp + 0x290]\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rsp + 0x60]\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3aaa0]\n"
        "lea rdx, [rip + rva_41a80]\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3aa98]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_dad0_e802:\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_dad0_e819:\n"
        "inc ebx\n"
        "cmp ebx, 0x1f\n"
        "jb .L_dad0_e704\n"
        "apw_mov32_load reg_ecx, reg_r14d\n"
        "call rva_33ed4\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x58]\n"
        "call rva_8ee0\n"
        "jmp .L_dad0_e951\n"
        ".L_dad0_e83c:\n"
        "lea r8, [rip + rva_41a84]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov32_load reg_edx, reg_esi\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_348d0\n"
        "jmp .L_dad0_e94f\n"
        ".L_dad0_e87a:\n"
        "lea r8, [rip + rva_41a8c]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov edx, 3\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_348d0\n"
        "jmp .L_dad0_e94f\n"
        ".L_dad0_e8bb:\n"
        "mov rbx, qword ptr [rsp + 0x38]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41750]\n"
        "lea r8, [rip + rva_41758]\n"
        "cmp eax, 1\n"
        "cmove r8, rcx\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rsp + 0x30]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "mov ecx, 7\n"
        "call rva_33dea\n"
        "lea r8, [rip + rva_41a94]\n"
        "mov rdx, qword ptr [rsp + 0x38]\n"
        "lea rcx, [rsp + 0x60]\n"
        "call rva_bf20\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "mov ecx, 0x12\n"
        ".L_dad0_e944:\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "mov rdx, qword ptr [rdi]\n"
        "call rva_33dea\n"
        ".L_dad0_e94f:\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        ".L_dad0_e951:\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "test rcx, rcx\n"
        "je .L_dad0_e961\n"
        "mov rax, qword ptr [rcx]\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_dad0_e961:\n"
        "test esi, esi\n"
        ".byte 0x0f, 0x85 # jne rel32 (original long encoding)\n"
        ".long .L_dad0_e9e4 - . - 4\n"
        "mov qword ptr [rsp + 0x48], r15\n"
        "lea rdx, [rsp + 0x48]\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a508]\n"
        "test eax, eax\n"
        "jne .L_dad0_e9e4\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "test rcx, rcx\n"
        "je .L_dad0_e9e4\n"
        "mov rax, qword ptr [rcx]\n"
        "lea rdx, [rsp + 0x30]\n"
        "call qword ptr [rax + 0x28]\n"
        "test eax, eax\n"
        "js .L_dad0_e9d9\n"
        "mov rdx, qword ptr [rsp + 0x30]\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3a9b0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdx, [rip + rva_41aa0]\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3aa88]\n"
        "test eax, eax\n"
        "je .L_dad0_e9ce\n"
        "lea rdx, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3aab0]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_dad0_e9ce:\n"
        "lea rcx, [rsp + 0x50]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_dad0_e9d9:\n"
        "mov rcx, qword ptr [rsp + 0x48]\n"
        "mov rax, qword ptr [rcx]\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_dad0_e9e4:\n"
        "apw_mov32_load reg_r15d, reg_esi\n"
        ".L_dad0_e9e7:\n"
        "lea rcx, [rsp + 0x78]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x50]\n"
        "call qword ptr [rip + rva_3a510]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x80]\n"
        "call qword ptr [rip + rva_3a510]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_dad0_ea09:\n"
        "lea rcx, [rsp + 0x68]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "apw_mov32_load reg_eax, reg_r15d\n"
        "mov rcx, qword ptr [rbp + 0x4a0]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x5b8\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "pop rbp\n"
        "ret\n"
        ".byte 0x66,0x90 # padding outside reachable blocks\n"
        ".long 0xdad0 + (.L_dad0_e6d3 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_dd56 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_deab - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_df3a - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_df89 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e0ee - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e17c - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e1ee - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e2a1 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e337 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e337 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e414 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e44d - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e486 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e4f8 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e534 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e83c - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e87a - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e060 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_de09 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e5ff - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_defa - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e1b5 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e011 - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_e8bb - apw_dad0) # switch target RVA\n"
        ".long 0xdad0 + (.L_dad0_dfd8 - apw_dad0) # switch target RVA\n"
        END);
}

/* body 0x12bc0 until 0x13514 */
BODY void apw_12bc0(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "sub rsp, 0x140\n"
        "lea rbp, [rsp + 0x40]\n"
        "mov qword ptr [rbp + 0x150], rbx\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rbp\n"
        "mov qword ptr [rbp + 0xf0], rax\n"
        "apw_mov64_load reg_r15, reg_rdx\n"
        "mov qword ptr [rbp + 8], rdx\n"
        "apw_mov64_load reg_r13, reg_rcx\n"
        "apw_xor32_load reg_r12d, reg_r12d\n"
        "mov sil, 1\n"
        "mov qword ptr [rbp + 0x28], rcx\n"
        "test rcx, rcx\n"
        "je .L_12bc0_12c15\n"
        "movzx eax, byte ptr [rcx + 0xc8]\n"
        "mov byte ptr [rbp + 0x20], al\n"
        "jmp .L_12bc0_12c19\n"
        ".L_12bc0_12c15:\n"
        "movzx eax, byte ptr [rbp + 0x20]\n"
        ".L_12bc0_12c19:\n"
        "mov byte ptr [rbp + 1], al\n"
        "mov r14, 0xffffffffffffffff\n"
        "apw_mov32_load reg_ebx, reg_r14d\n"
        "mov dword ptr [rbp + 4], ebx\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbp + 0x50], xmm0\n"
        "movdqa xmm1, xmmword ptr [rip + rva_41f70]\n"
        "movdqu xmmword ptr [rbp + 0x60], xmm1\n"
        "mov byte ptr [rbp + 0x50], 0\n"
        "movups xmmword ptr [rbp + 0xb0], xmm0\n"
        "movdqu xmmword ptr [rbp + 0xc0], xmm1\n"
        "mov byte ptr [rbp + 0xb0], 0\n"
        "movabs rdi, 0xffffffffffffff0\n"
        "test r15, r15\n"
        "je .L_12bc0_12cd8\n"
        "apw_mov64_load reg_rax, reg_r14\n"
        ".byte 0xf,0x1f,0x80,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_12bc0_12c70:\n"
        "inc rax\n"
        "cmp byte ptr [rdx + rax], 0\n"
        "jne .L_12bc0_12c70\n"
        "lea edx, [rax + 1]\n"
        "cmp edx, 0x3fffffff\n"
        "jg .L_12bc0_12cd8\n"
        "cdqe\n"
        "lea rax, [rax*2 + 2]\n"
        "lea rcx, [rax + 0xf]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "ja .L_12bc0_12c9a\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        ".L_12bc0_12c9a:\n"
        "and rcx, 0xfffffffffffffff0\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "call rva_355d0\n"
        "apw_sub64_load reg_rsp, reg_rcx\n"
        "lea rdi, [rsp + 0x40]\n"
        "test rdi, rdi\n"
        "je .L_12bc0_12cd8\n"
        "mov word ptr [rdi], r12w\n"
        "mov dword ptr [rsp + 0x28], edx\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "apw_mov32_load reg_r9d, reg_r14d\n"
        "apw_mov64_load reg_r8, reg_r15\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a2d8]\n"
        "test eax, eax\n"
        "cmove rdi, r12\n"
        "jmp .L_12bc0_12cdb\n"
        ".L_12bc0_12cd8:\n"
        "apw_mov64_load reg_rdi, reg_r12\n"
        ".L_12bc0_12cdb:\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbp + 0x30], xmm0\n"
        "mov qword ptr [rbp + 0x40], r12\n"
        "mov qword ptr [rbp + 0x48], r12\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        ".byte 0xf,0x1f,0x0 # alignment NOP\n"
        ".L_12bc0_12cf0:\n"
        "inc r8\n"
        "cmp word ptr [rdi + r8*2], 0\n"
        "jne .L_12bc0_12cf0\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rbp + 0x30]\n"
        "call rva_6f50\n"
        ".byte 0x90 # alignment NOP\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbp + 0xd0], xmm0\n"
        "movdqa xmm1, xmmword ptr [rip + rva_41f60]\n"
        "movdqu xmmword ptr [rbp + 0xe0], xmm1\n"
        "mov word ptr [rbp + 0xd0], r12w\n"
        "lea rcx, [rbp + 0x30]\n"
        "mov r11, qword ptr [rbp + 0x30]\n"
        "mov r9, qword ptr [rbp + 0x48]\n"
        "cmp r9, 8\n"
        "cmovae rcx, r11\n"
        "mov rdx, qword ptr [rbp + 0x40]\n"
        "test rdx, rdx\n"
        "je .L_12bc0_13091\n"
        "apw_mov64_load reg_rax, reg_rdx\n"
        "apw_mov64_load reg_rsi, reg_rcx\n"
        ".L_12bc0_12d51:\n"
        "cmp word ptr [rsi], 0x7c\n"
        "je .L_12bc0_12d66\n"
        "add rsi, 2\n"
        "sub rax, 1\n"
        "jne .L_12bc0_12d51\n"
        "jmp .L_12bc0_1308e\n"
        ".L_12bc0_12d66:\n"
        "test rsi, rsi\n"
        "je .L_12bc0_1308e\n"
        "apw_sub64_load reg_rsi, reg_rcx\n"
        "sar rsi, 1\n"
        "cmp rsi, -1\n"
        "je .L_12bc0_1308e\n"
        "lea rax, [rdx - 2]\n"
        "apw_cmp64_load reg_rsi, reg_rax\n"
        "jne .L_12bc0_1308e\n"
        "lea rcx, [rsi + 1]\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbp + 0x70], xmm0\n"
        "mov qword ptr [rbp + 0x80], r12\n"
        "mov qword ptr [rbp + 0x88], r12\n"
        "apw_cmp64_load reg_rdx, reg_rcx\n"
        "jb .L_12bc0_134ee\n"
        "apw_sub64_load reg_rdx, reg_rcx\n"
        "apw_mov64_load reg_rdi, reg_r14\n"
        "apw_cmp64_load reg_rdx, reg_r14\n"
        "cmovb rdi, rdx\n"
        "lea rax, [rbp + 0x30]\n"
        "cmp r9, 8\n"
        "cmovae rax, r11\n"
        "lea r12, [rax + rcx*2]\n"
        "movabs r15, 0x7ffffffffffffffe\n"
        "apw_cmp64_load reg_rdi, reg_r15\n"
        "ja .L_12bc0_134e8\n"
        "mov qword ptr [rbp + 0x88], 7\n"
        "cmp rdi, 8\n"
        "jae .L_12bc0_12e13\n"
        "mov qword ptr [rbp + 0x80], rdi\n"
        "apw_add64_load reg_rdi, reg_rdi\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "lea rcx, [rbp + 0x70]\n"
        "call rva_362a4\n"
        "apw_xor32_load reg_r12d, reg_r12d\n"
        "mov word ptr [rbp + rdi + 0x70], r12w\n"
        "jmp .L_12bc0_12e69\n"
        ".L_12bc0_12e13:\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "or rax, 7\n"
        "apw_cmp64_load reg_rax, reg_r15\n"
        "ja .L_12bc0_12e2e\n"
        "apw_mov64_load reg_r15, reg_rax\n"
        "mov ecx, 0xa\n"
        "apw_cmp64_load reg_rax, reg_rcx\n"
        "cmovb r15, rcx\n"
        ".L_12bc0_12e2e:\n"
        "lea rdx, [r15 + 1]\n"
        "lea rcx, [rbp + 0x70]\n"
        "call rva_1d2e0\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "mov qword ptr [rbp + 0x70], rax\n"
        "mov qword ptr [rbp + 0x80], rdi\n"
        "mov qword ptr [rbp + 0x88], r15\n"
        "apw_add64_load reg_rdi, reg_rdi\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call rva_362a4\n"
        "apw_xor32_load reg_r12d, reg_r12d\n"
        "mov word ptr [rbx + rdi], r12w\n"
        ".L_12bc0_12e69:\n"
        "lea r8, [rbp + 0x70]\n"
        "cmp qword ptr [rbp + 0x88], 8\n"
        "jb .L_12bc0_12e84\n"
        "mov r8, qword ptr [rbp + 0x70]\n"
        "test r8, r8\n"
        "je .L_12bc0_12f0a\n"
        ".L_12bc0_12e84:\n"
        "apw_mov64_load reg_rax, reg_r14\n"
        ".byte 0x66,0xf,0x1f,0x84,0x0,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_12bc0_12e90:\n"
        "inc rax\n"
        "cmp word ptr [r8 + rax*2], 0\n"
        "jne .L_12bc0_12e90\n"
        "lea edx, [rax + 1]\n"
        "cmp edx, 0x3fffffff\n"
        "jg .L_12bc0_12f0a\n"
        "cdqe\n"
        "lea rax, [rax*2 + 2]\n"
        "lea rcx, [rax + 0xf]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "ja .L_12bc0_12ec3\n"
        "movabs rcx, 0xffffffffffffff0\n"
        ".L_12bc0_12ec3:\n"
        "and rcx, 0xfffffffffffffff0\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "call rva_355d0\n"
        "apw_sub64_load reg_rsp, reg_rcx\n"
        "lea rdi, [rsp + 0x40]\n"
        "test rdi, rdi\n"
        "je .L_12bc0_12f0a\n"
        "mov byte ptr [rdi], 0\n"
        "lea eax, [rdx + rdx]\n"
        "mov qword ptr [rsp + 0x38], r12\n"
        "mov qword ptr [rsp + 0x30], r12\n"
        "mov dword ptr [rsp + 0x28], eax\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "apw_mov32_load reg_r9d, reg_r14d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a2d0]\n"
        "test eax, eax\n"
        "cmove rdi, r12\n"
        "jmp .L_12bc0_12f0d\n"
        ".L_12bc0_12f0a:\n"
        "apw_mov64_load reg_rdi, reg_r12\n"
        ".L_12bc0_12f0d:\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbp + 0x90], xmm0\n"
        "xorps xmm1, xmm1\n"
        "movdqu xmmword ptr [rbp + 0xa0], xmm1\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        ".L_12bc0_12f25:\n"
        "inc r8\n"
        "cmp byte ptr [rdi + r8], 0\n"
        "jne .L_12bc0_12f25\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rbp + 0x90]\n"
        "call rva_6e90\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x90]\n"
        "cmp qword ptr [rbp + 0xa8], 0x10\n"
        "cmovae rcx, qword ptr [rbp + 0x90]\n"
        "call qword ptr [rip + rva_3a6a0]\n"
        "apw_mov32_load reg_ebx, reg_eax\n"
        "mov dword ptr [rbp + 4], eax\n"
        "mov r8, qword ptr [rbp + 0x40]\n"
        "apw_cmp64_load reg_rsi, reg_r8\n"
        "ja .L_12bc0_12f83\n"
        "mov qword ptr [rbp + 0x40], rsi\n"
        "lea rcx, [rbp + 0x30]\n"
        "cmp qword ptr [rbp + 0x48], 8\n"
        "cmovae rcx, qword ptr [rbp + 0x30]\n"
        "mov word ptr [rcx + rsi*2], r12w\n"
        "jmp .L_12bc0_12fdd\n"
        ".L_12bc0_12f83:\n"
        "apw_mov64_load reg_rdx, reg_rsi\n"
        "apw_sub64_load reg_rdx, reg_r8\n"
        "mov rcx, qword ptr [rbp + 0x48]\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "apw_sub64_load reg_rax, reg_r8\n"
        "apw_cmp64_load reg_rdx, reg_rax\n"
        "ja .L_12bc0_12fc7\n"
        "mov qword ptr [rbp + 0x40], rsi\n"
        "lea r9, [rbp + 0x30]\n"
        "cmp rcx, 8\n"
        "cmovae r9, qword ptr [rbp + 0x30]\n"
        "lea rdi, [r9 + r8*2]\n"
        "test rdx, rdx\n"
        "je .L_12bc0_12fbc\n"
        "movzx eax, r12w\n"
        "apw_mov64_load reg_rcx, reg_rdx\n"
        ".byte 0x66 # word-sized REP STOS, operand-size prefix precedes REP\n"
        "rep stosd\n"
        ".L_12bc0_12fbc:\n"
        "lea rax, [rdx + r8]\n"
        "mov word ptr [r9 + rax*2], r12w\n"
        "jmp .L_12bc0_12fdd\n"
        ".L_12bc0_12fc7:\n"
        "mov word ptr [rsp + 0x20], r12w\n"
        "apw_mov64_load reg_r9, reg_rdx\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rcx, [rbp + 0x30]\n"
        "call rva_7fd0\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_12bc0_12fdd:\n"
        "mov rdx, qword ptr [rbp + 0xa8]\n"
        "cmp rdx, 0x10\n"
        "jb .L_12bc0_13021\n"
        "inc rdx\n"
        "mov rcx, qword ptr [rbp + 0x90]\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "cmp rdx, 0x1000\n"
        "jb .L_12bc0_1301c\n"
        "add rdx, 0x27\n"
        "mov rcx, qword ptr [rcx - 8]\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "add rax, -8\n"
        "cmp rax, 0x1f\n"
        "jbe .L_12bc0_1301c\n"
        "call qword ptr [rip + rva_3a7b8]\n"
        "int3\n"
        ".L_12bc0_1301c:\n"
        "call rva_35134\n"
        ".L_12bc0_13021:\n"
        "movdqa xmm0, xmmword ptr [rip + rva_41f70]\n"
        "movdqu xmmword ptr [rbp + 0xa0], xmm0\n"
        "mov byte ptr [rbp + 0x90], 0\n"
        "mov rdx, qword ptr [rbp + 0x88]\n"
        "cmp rdx, 8\n"
        "jb .L_12bc0_1307e\n"
        "lea rdx, [rdx*2 + 2]\n"
        "mov rcx, qword ptr [rbp + 0x70]\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "cmp rdx, 0x1000\n"
        "jb .L_12bc0_13079\n"
        "add rdx, 0x27\n"
        "mov rcx, qword ptr [rcx - 8]\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "add rax, -8\n"
        "cmp rax, 0x1f\n"
        "jbe .L_12bc0_13079\n"
        "call qword ptr [rip + rva_3a7b8]\n"
        "int3\n"
        ".L_12bc0_13079:\n"
        "call rva_35134\n"
        ".L_12bc0_1307e:\n"
        "mov r15, qword ptr [rbp + 8]\n"
        "mov r11, qword ptr [rbp + 0x30]\n"
        "mov rdx, qword ptr [rbp + 0x40]\n"
        "mov r9, qword ptr [rbp + 0x48]\n"
        ".L_12bc0_1308e:\n"
        "mov sil, 1\n"
        ".L_12bc0_13091:\n"
        "lea rdi, [rbp + 0x30]\n"
        "cmp r9, 8\n"
        "cmovae rdi, r11\n"
        "test rdx, rdx\n"
        "je .L_12bc0_1315a\n"
        "lea rcx, [rdx - 1]\n"
        "apw_mov64_load reg_rax, reg_r14\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "cmovb rax, rcx\n"
        "lea rcx, [rdi + rax*2]\n"
        "cmp word ptr [rcx], 0x3e\n"
        "je .L_12bc0_130d3\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_12bc0_130c0:\n"
        "apw_cmp64_load reg_rcx, reg_rdi\n"
        "je .L_12bc0_1315a\n"
        "sub rcx, 2\n"
        "cmp word ptr [rcx], 0x3e\n"
        "jne .L_12bc0_130c0\n"
        ".L_12bc0_130d3:\n"
        "apw_sub64_load reg_rcx, reg_rdi\n"
        "sar rcx, 1\n"
        "cmp rcx, -1\n"
        "je .L_12bc0_1315a\n"
        "apw_cmp64_load reg_rcx, reg_rdx\n"
        "ja .L_12bc0_130fb\n"
        "mov qword ptr [rbp + 0x40], rcx\n"
        "lea rax, [rbp + 0x30]\n"
        "cmp r9, 8\n"
        "cmovae rax, r11\n"
        "mov word ptr [rax + rcx*2], r12w\n"
        "jmp .L_12bc0_13152\n"
        ".L_12bc0_130fb:\n"
        "apw_mov64_load reg_r10, reg_rcx\n"
        "apw_sub64_load reg_r10, reg_rdx\n"
        "apw_mov64_load reg_rax, reg_r9\n"
        "apw_sub64_load reg_rax, reg_rdx\n"
        "apw_cmp64_load reg_r10, reg_rax\n"
        "ja .L_12bc0_1313a\n"
        "mov qword ptr [rbp + 0x40], rcx\n"
        "lea r8, [rbp + 0x30]\n"
        "cmp r9, 8\n"
        "cmovae r8, r11\n"
        "lea rdi, [r8 + rdx*2]\n"
        "test r10, r10\n"
        "je .L_12bc0_1312f\n"
        "movzx eax, r12w\n"
        "apw_mov64_load reg_rcx, reg_r10\n"
        ".byte 0x66 # word-sized REP STOS, operand-size prefix precedes REP\n"
        "rep stosd\n"
        ".L_12bc0_1312f:\n"
        "lea rax, [r10 + rdx]\n"
        "mov word ptr [r8 + rax*2], r12w\n"
        "jmp .L_12bc0_13152\n"
        ".L_12bc0_1313a:\n"
        "mov word ptr [rsp + 0x20], r12w\n"
        "apw_mov64_load reg_r9, reg_r10\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rdx, reg_r10\n"
        "lea rcx, [rbp + 0x30]\n"
        "call rva_7fd0\n"
        ".L_12bc0_13152:\n"
        "mov r9, qword ptr [rbp + 0x48]\n"
        "mov r11, qword ptr [rbp + 0x30]\n"
        ".L_12bc0_1315a:\n"
        "lea r8, [rbp + 0x30]\n"
        "cmp r9, 8\n"
        "jb .L_12bc0_13170\n"
        "apw_mov64_load reg_r8, reg_r11\n"
        "test r11, r11\n"
        ".byte 0x0f, 0x84 # je rel32 (original long encoding)\n"
        ".long .L_12bc0_131ed - . - 4\n"
        ".L_12bc0_13170:\n"
        "apw_mov64_load reg_rax, reg_r14\n"
        ".L_12bc0_13173:\n"
        "inc rax\n"
        "cmp word ptr [r8 + rax*2], 0\n"
        "jne .L_12bc0_13173\n"
        "lea edx, [rax + 1]\n"
        "cmp edx, 0x3fffffff\n"
        "jg .L_12bc0_131ed\n"
        "cdqe\n"
        "lea rax, [rax*2 + 2]\n"
        "lea rcx, [rax + 0xf]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "ja .L_12bc0_131a6\n"
        "movabs rcx, 0xffffffffffffff0\n"
        ".L_12bc0_131a6:\n"
        "and rcx, 0xfffffffffffffff0\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "call rva_355d0\n"
        "apw_sub64_load reg_rsp, reg_rcx\n"
        "lea rdi, [rsp + 0x40]\n"
        "test rdi, rdi\n"
        "je .L_12bc0_131ed\n"
        "mov byte ptr [rdi], 0\n"
        "lea eax, [rdx + rdx]\n"
        "mov qword ptr [rsp + 0x38], r12\n"
        "mov qword ptr [rsp + 0x30], r12\n"
        "mov dword ptr [rsp + 0x28], eax\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "apw_mov32_load reg_r9d, reg_r14d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a2d0]\n"
        "test eax, eax\n"
        "cmove rdi, r12\n"
        "jmp .L_12bc0_131f0\n"
        ".L_12bc0_131ed:\n"
        "apw_mov64_load reg_rdi, reg_r12\n"
        ".L_12bc0_131f0:\n"
        "xorps xmm0, xmm0\n"
        "movups xmmword ptr [rbp + 0x90], xmm0\n"
        "xorps xmm1, xmm1\n"
        "movdqu xmmword ptr [rbp + 0xa0], xmm1\n"
        ".L_12bc0_13205:\n"
        "inc r14\n"
        "cmp byte ptr [rdi + r14], 0\n"
        "jne .L_12bc0_13205\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rbp + 0x90]\n"
        "call rva_6e90\n"
        "mov rdx, qword ptr [rbp + 0x68]\n"
        "cmp rdx, 0x10\n"
        "jb .L_12bc0_1325f\n"
        "inc rdx\n"
        "mov rcx, qword ptr [rbp + 0x50]\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "cmp rdx, 0x1000\n"
        "jb .L_12bc0_1325a\n"
        "add rdx, 0x27\n"
        "mov rcx, qword ptr [rcx - 8]\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "add rax, -8\n"
        "cmp rax, 0x1f\n"
        "jbe .L_12bc0_1325a\n"
        "call qword ptr [rip + rva_3a7b8]\n"
        "int3\n"
        ".L_12bc0_1325a:\n"
        "call rva_35134\n"
        ".L_12bc0_1325f:\n"
        "movups xmm0, xmmword ptr [rbp + 0x90]\n"
        "movups xmmword ptr [rbp + 0x50], xmm0\n"
        "movups xmm1, xmmword ptr [rbp + 0xa0]\n"
        "movups xmmword ptr [rbp + 0x60], xmm1\n"
        "call rva_33cee\n"
        "test eax, eax\n"
        "jne .L_12bc0_133af\n"
        "lea rcx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_3a920]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rdi, [rbp + 0x50]\n"
        "cmp qword ptr [rbp + 0x68], 0x10\n"
        "cmovae rdi, qword ptr [rbp + 0x50]\n"
        "call rva_33f5f\n"
        "apw_mov32_load reg_edx, reg_eax\n"
        "lea rax, [rbp + 0x10]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_9bf0\n"
        "cmp eax, -1\n"
        "je .L_12bc0_133fc\n"
        "cmp eax, 1\n"
        "je .L_12bc0_133d7\n"
        "lea rdx, [rbp + 0x50]\n"
        "cmp qword ptr [rbp + 0x68], 0x10\n"
        "cmovae rdx, qword ptr [rbp + 0x50]\n"
        "lea rcx, [rbp + 8]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "cmp ebx, -1\n"
        "jne .L_12bc0_13312\n"
        "lea rdx, [rbp + 8]\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_3aac8]\n"
        "apw_mov64_load reg_r8, reg_rax\n"
        "lea rdx, [rbp + 4]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_caa0\n"
        "test al, al\n"
        "jne .L_12bc0_1330f\n"
        "mov byte ptr [rbp], al\n"
        "jmp .L_12bc0_1332a\n"
        ".L_12bc0_1330f:\n"
        "mov ebx, dword ptr [rbp + 4]\n"
        ".L_12bc0_13312:\n"
        "cmp ebx, 3\n"
        "jne .L_12bc0_1334e\n"
        "lea rdx, [rbp + 8]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_a4e0\n"
        "test eax, eax\n"
        "jne .L_12bc0_13339\n"
        "mov byte ptr [rbp], al\n"
        ".L_12bc0_1332a:\n"
        "lea rcx, [rbp + 8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "jmp .L_12bc0_13401\n"
        ".L_12bc0_13339:\n"
        "mov ecx, 0x578\n"
        "call qword ptr [rip + rva_3a5a8]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_34821\n"
        ".L_12bc0_1334e:\n"
        "cmp ebx, 7\n"
        "ja .L_12bc0_13395\n"
        "movsxd rax, ebx\n"
        "lea rdx, [rip + rva_0]\n"
        "mov ecx, dword ptr [rdx + rax*4 + 0x134f4]\n"
        "apw_add64_load reg_rcx, reg_rdx\n"
        "jmp rcx\n"
        ".L_12bc0_13369:\n"
        "lea rdx, [rbp + 0x50]\n"
        "cmp qword ptr [rbp + 0x68], 0x10\n"
        "cmovae rdx, qword ptr [rbp + 0x50]\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_15030\n"
        "jmp .L_12bc0_13392\n"
        ".L_12bc0_13384:\n"
        "apw_mov32_load reg_r8d, reg_ebx\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_13b10\n"
        ".L_12bc0_13392:\n"
        "movzx esi, al\n"
        ".L_12bc0_13395:\n"
        "lea rcx, [rbp + 8]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "test sil, sil\n"
        "je .L_12bc0_13418\n"
        ".L_12bc0_133af:\n"
        "call qword ptr [rip + rva_53308]\n"
        "apw_mov32_load reg_edi, reg_eax\n"
        "cmp eax, 1\n"
        "je .L_12bc0_13411\n"
        "mov ecx, 1\n"
        "call qword ptr [rip + rva_53310]\n"
        "call qword ptr [rip + rva_53318]\n"
        "apw_mov32_load reg_ecx, reg_edi\n"
        "call qword ptr [rip + rva_53310]\n"
        "jmp .L_12bc0_13418\n"
        ".L_12bc0_133d7:\n"
        "lea rcx, [r13 + 0xa0]\n"
        "lea rdx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_3aab0]\n"
        "mov r8d, 1\n"
        "mov rdx, qword ptr [rbp + 0x10]\n"
        "apw_mov64_load reg_rcx, reg_r13\n"
        "call rva_13b10\n"
        "jmp .L_12bc0_133fe\n"
        ".L_12bc0_133fc:\n"
        "apw_xor8_load reg_al, reg_al\n"
        ".L_12bc0_133fe:\n"
        "mov byte ptr [rbp], al\n"
        ".L_12bc0_13401:\n"
        "lea rcx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "movzx esi, byte ptr [rbp]\n"
        "jmp .L_12bc0_13418\n"
        ".L_12bc0_13411:\n"
        "call qword ptr [rip + rva_53318]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_12bc0_13418:\n"
        "mov rdx, qword ptr [rbp + 0x48]\n"
        "cmp rdx, 8\n"
        "jb .L_12bc0_1345b\n"
        "lea rdx, [rdx*2 + 2]\n"
        "mov rcx, qword ptr [rbp + 0x30]\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "cmp rdx, 0x1000\n"
        "jb .L_12bc0_13456\n"
        "add rdx, 0x27\n"
        "mov rcx, qword ptr [rcx - 8]\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "add rax, -8\n"
        "cmp rax, 0x1f\n"
        "jbe .L_12bc0_13456\n"
        "call qword ptr [rip + rva_3a7b8]\n"
        "int3\n"
        ".L_12bc0_13456:\n"
        "call rva_35134\n"
        ".L_12bc0_1345b:\n"
        "mov qword ptr [rbp + 0x40], r12\n"
        "mov qword ptr [rbp + 0x48], 7\n"
        "mov word ptr [rbp + 0x30], r12w\n"
        "mov rdx, qword ptr [rbp + 0x68]\n"
        "cmp rdx, 0x10\n"
        "jb .L_12bc0_134ab\n"
        "inc rdx\n"
        "mov rcx, qword ptr [rbp + 0x50]\n"
        "apw_mov64_load reg_rax, reg_rcx\n"
        "cmp rdx, 0x1000\n"
        "jb .L_12bc0_134a5\n"
        "add rdx, 0x27\n"
        "mov rcx, qword ptr [rcx - 8]\n"
        "apw_sub64_load reg_rax, reg_rcx\n"
        "add rax, -8\n"
        "cmp rax, 0x1f\n"
        "jbe .L_12bc0_134a5\n"
        "call qword ptr [rip + rva_3a7b8]\n"
        "int3\n"
        ".L_12bc0_134a5:\n"
        "call rva_35134\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_12bc0_134ab:\n"
        "test r13, r13\n"
        "je .L_12bc0_134bb\n"
        "movzx eax, byte ptr [rbp + 1]\n"
        "mov byte ptr [r13 + 0xc8], al\n"
        ".L_12bc0_134bb:\n"
        "movzx eax, sil\n"
        "mov rcx, qword ptr [rbp + 0xf0]\n"
        "apw_xor64_load reg_rcx, reg_rbp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rbp + 0x150]\n"
        "lea rsp, [rbp + 0x100]\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".L_12bc0_134e8:\n"
        "call rva_1d1b0\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_12bc0_134ee:\n"
        "call rva_1d1f0\n"
        "int3\n"
        ".long 0x12bc0 + (.L_12bc0_13369 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13384 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13384 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13384 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13395 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13395 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13384 - apw_12bc0) # switch target RVA\n"
        ".long 0x12bc0 + (.L_12bc0_13384 - apw_12bc0) # switch target RVA\n"
        END);
}

/* body 0x1fe50 until 0x202c8 */
BODY void apw_1fe50(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x10], rbx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "lea rbp, [rsp - 0x4c0]\n"
        "sub rsp, 0x5c0\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0x4b0], rax\n"
        "apw_mov64_load reg_rbx, reg_r8\n"
        "movzx esi, dx\n"
        "apw_mov64_load reg_rdi, reg_rcx\n"
        "mov ecx, dword ptr [rip + rva_54218]\n"
        "mov rax, qword ptr gs:[0x58]\n"
        "mov edx, 4\n"
        "mov rax, qword ptr [rax + rcx*8]\n"
        "mov eax, dword ptr [rdx + rax]\n"
        "cmp dword ptr [rip + rva_54078], eax\n"
        "jg .L_1fe50_20233\n"
        ".L_1fe50_1fea8:\n"
        "mov r8, qword ptr [rdi + 0xc8]\n"
        "test r8, r8\n"
        "jne .L_1fe50_1febe\n"
        "mov eax, 0x80004005\n"
        "jmp .L_1fe50_20211\n"
        ".L_1fe50_1febe:\n"
        "lea eax, [rsi - 0xf]\n"
        "cmp eax, 0x13\n"
        "ja .L_1fe50_2020f\n"
        "cdqe\n"
        "lea rdx, [rip + rva_0]\n"
        "mov ecx, dword ptr [rdx + rax*4 + 0x20278]\n"
        "apw_add64_load reg_rcx, reg_rdx\n"
        "jmp rcx\n"
        ".L_1fe50_1fedf:\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "lea rcx, [rip + rva_54070]\n"
        "call qword ptr [rip + rva_3aaa8]\n"
        "jmp .L_1fe50_2020f\n"
        ".L_1fe50_1fef4:\n"
        "mov r8d, 0x400\n"
        "lea rdx, [rbp + 0xb0]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call rva_3478b\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x4fc\n"
        "lea rdx, [rbp + 0xb0]\n"
        "mov rcx, qword ptr [rdi + 0xd0]\n"
        "call rva_3433f\n"
        "jmp .L_1fe50_2020f\n"
        ".L_1fe50_1ff32:\n"
        "test rbx, rbx\n"
        "je .L_1fe50_2020f\n"
        "cmp qword ptr [rdi + 0xd0], 0\n"
        "je .L_1fe50_2020f\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_r8\n"
        "call rva_13520\n"
        "lea rcx, [rsp + 0x70]\n"
        "call qword ptr [rip + rva_3a518]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a518]\n"
        "movups xmm0, xmmword ptr [rsp + 0x70]\n"
        "movaps xmmword ptr [rsp + 0x50], xmm0\n"
        "movsd xmm1, qword ptr [rbp - 0x80]\n"
        "movsd qword ptr [rsp + 0x60], xmm1\n"
        "mov rax, qword ptr [rbx]\n"
        "mov edx, 0x3f\n"
        "lea r9, [rsp + 0x38]\n"
        "lea r8, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x98]\n"
        "test eax, eax\n"
        "js .L_1fe50_2020f\n"
        "cmp word ptr [rsp + 0x38], 3\n"
        "jne .L_1fe50_2020f\n"
        "cmp dword ptr [rsp + 0x40], 0\n"
        "je .L_1fe50_2020f\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a510]\n"
        "movups xmm0, xmmword ptr [rsp + 0x70]\n"
        "movaps xmmword ptr [rsp + 0x50], xmm0\n"
        "movsd xmm1, qword ptr [rbp - 0x80]\n"
        "movsd qword ptr [rsp + 0x60], xmm1\n"
        "mov rax, qword ptr [rbx]\n"
        "mov edx, 0x41\n"
        "lea r9, [rsp + 0x38]\n"
        "lea r8, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x98]\n"
        "test eax, eax\n"
        "js .L_1fe50_2020f\n"
        "lea rax, [rbp - 0x68]\n"
        "mov qword ptr [rbp - 0x70], rax\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov rdx, qword ptr [rsp + 0x40]\n"
        "lea rcx, [rbp - 0x70]\n"
        "call rva_d880\n"
        ".byte 0x90 # alignment NOP\n"
        "mov rdx, qword ptr [rbp - 0x70]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rax, [rbp - 0x68]\n"
        "mov rcx, qword ptr [rbp - 0x70]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "je .L_1fe50_20039\n"
        "call qword ptr [rip + rva_3a728]\n"
        ".L_1fe50_20039:\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "mov r9, qword ptr [rsp + 0x30]\n"
        "mov r8d, 0x4fb\n"
        "mov rdx, qword ptr [rip + rva_54070]\n"
        "mov rcx, qword ptr [rdi + 0xd0]\n"
        "call rva_3433f\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x10]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "jmp .L_1fe50_2020f\n"
        ".L_1fe50_20079:\n"
        "test rbx, rbx\n"
        "je .L_1fe50_2020f\n"
        "cmp qword ptr [rdi + 0xd0], 0\n"
        "je .L_1fe50_2020f\n"
        "lea rcx, [rsp + 0x70]\n"
        "call qword ptr [rip + rva_3a518]\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a518]\n"
        "movups xmm0, xmmword ptr [rsp + 0x70]\n"
        "movaps xmmword ptr [rsp + 0x50], xmm0\n"
        "movsd xmm1, qword ptr [rbp - 0x80]\n"
        "movsd qword ptr [rsp + 0x60], xmm1\n"
        "mov rax, qword ptr [rbx]\n"
        "mov edx, 0x3f\n"
        "lea r9, [rsp + 0x38]\n"
        "lea r8, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x98]\n"
        "test eax, eax\n"
        "js .L_1fe50_2020f\n"
        "cmp word ptr [rsp + 0x38], 3\n"
        "jne .L_1fe50_2020f\n"
        "cmp dword ptr [rsp + 0x40], 0\n"
        "je .L_1fe50_2020f\n"
        "lea rcx, [rsp + 0x38]\n"
        "call qword ptr [rip + rva_3a510]\n"
        "movups xmm0, xmmword ptr [rsp + 0x70]\n"
        "movaps xmmword ptr [rsp + 0x50], xmm0\n"
        "movsd xmm1, qword ptr [rbp - 0x80]\n"
        "movsd qword ptr [rsp + 0x60], xmm1\n"
        "mov rax, qword ptr [rbx]\n"
        "mov edx, 0x41\n"
        "lea r9, [rsp + 0x38]\n"
        "lea r8, [rsp + 0x50]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x98]\n"
        "test eax, eax\n"
        "js .L_1fe50_2020f\n"
        "lea rax, [rbp + 0x28]\n"
        "mov qword ptr [rbp + 0x20], rax\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov rdx, qword ptr [rsp + 0x40]\n"
        "lea rcx, [rbp + 0x20]\n"
        "call rva_d880\n"
        ".byte 0x90 # alignment NOP\n"
        "mov rdx, qword ptr [rbp + 0x20]\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rax, [rbp + 0x28]\n"
        "mov rcx, qword ptr [rbp + 0x20]\n"
        "apw_cmp64_load reg_rcx, reg_rax\n"
        "je .L_1fe50_20175\n"
        "call qword ptr [rip + rva_3a728]\n"
        ".L_1fe50_20175:\n"
        "cmp esi, 0x20\n"
        "jne .L_1fe50_2018b\n"
        "mov rdx, qword ptr [rsp + 0x40]\n"
        "mov rcx, qword ptr [rdi + 0xc8]\n"
        "call rva_11b60\n"
        ".L_1fe50_2018b:\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x4f1\n"
        "mov rdx, qword ptr [rsp + 0x30]\n"
        "mov rcx, qword ptr [rdi + 0xd0]\n"
        "call rva_3433f\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x10]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x30]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "jmp .L_1fe50_2020f\n"
        ".L_1fe50_201c4:\n"
        "test rbx, rbx\n"
        "je .L_1fe50_2020f\n"
        "mov rcx, qword ptr [rdi + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_1fe50_2020f\n"
        "mov r8d, 0x4f2\n"
        "jmp .L_1fe50_201f4\n"
        ".L_1fe50_201dd:\n"
        "test rbx, rbx\n"
        "je .L_1fe50_2020f\n"
        "mov rcx, qword ptr [rdi + 0xd0]\n"
        "test rcx, rcx\n"
        "je .L_1fe50_2020f\n"
        "mov r8d, 0x4f6\n"
        ".L_1fe50_201f4:\n"
        "mov dword ptr [rsp + 0x20], 0\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "call rva_3433f\n"
        "mov rax, qword ptr [rbx]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_1fe50_2020f:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        ".L_1fe50_20211:\n"
        "mov rcx, qword ptr [rbp + 0x4b0]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0x5e8]\n"
        "add rsp, 0x5c0\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".L_1fe50_20233:\n"
        "lea rcx, [rip + rva_54078]\n"
        "call rva_35090\n"
        "cmp dword ptr [rip + rva_54078], -1\n"
        "jne .L_1fe50_1fea8\n"
        "lea rcx, [rip + rva_54070]\n"
        "call qword ptr [rip + rva_3a920]\n"
        "lea rcx, [rip + rva_396c0]\n"
        "call rva_354a4\n"
        "lea rcx, [rip + rva_54078]\n"
        "call rva_35024\n"
        "jmp .L_1fe50_1fea8\n"
        ".byte 0x66,0x90 # padding outside reachable blocks\n"
        ".long 0x1fe50 + (.L_1fe50_1fef4 - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_20079 - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_1ff32 - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_2020f - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_201c4 - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_20079 - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_201dd - apw_1fe50) # switch target RVA\n"
        ".long 0x1fe50 + (.L_1fe50_1fedf - apw_1fe50) # switch target RVA\n"
        END);
}

/* body 0x21b90 until 0x22ac3 */
BODY void apw_21b90(void) {
    __asm__(INTEL
        ".byte 0x40 # original redundant REX prefix\n        push rbp\n"
        "push rbx\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r14\n"
        "push r15\n"
        "lea rbp, [rsp - 0x100]\n"
        "sub rsp, 0x200\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp + 0xf0], rax\n"
        "apw_mov64_load reg_r12, reg_r9\n"
        "apw_mov64_load reg_rdi, reg_r8\n"
        "apw_mov64_load reg_r15, reg_rcx\n"
        "mov rsi, qword ptr [rbp + 0x160]\n"
        "apw_xor32_load reg_ebx, reg_ebx\n"
        "mov dword ptr [rsp + 0x50], ebx\n"
        "mov qword ptr [rsi], rbx\n"
        "cmp edx, 0x4ce\n"
        "ja .L_21b90_21d03\n"
        "je .L_21b90_21ce4\n"
        "cmp edx, 0x111\n"
        "jne .L_21b90_22892\n"
        "cmp r8, 0x9094\n"
        "ja .L_21b90_21c23\n"
        "je .L_21b90_21c0a\n"
        "cmp r8, 0x80d2\n"
        "jne .L_21b90_22892\n"
        ".L_21b90_21c0a:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_21c23:\n"
        "cmp rdi, 0xdae3\n"
        "ja .L_21b90_21c78\n"
        "je .L_21b90_21ca6\n"
        "lea rax, [r8 - 0x9095]\n"
        "cmp rax, 0x2c\n"
        "ja .L_21b90_22892\n"
        "lea r8, [rip + rva_0]\n"
        "movzx eax, byte ptr [r8 + rax + 0x228d8]\n"
        "mov ecx, dword ptr [r8 + rax*4 + 0x228cc]\n"
        "apw_add64_load reg_rcx, reg_r8\n"
        "jmp rcx\n"
        ".L_21b90_21c5c:\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_21c78:\n"
        "lea rax, [r8 - 0xdae4]\n"
        "cmp rax, 0x74\n"
        "ja .L_21b90_22892\n"
        "lea r8, [rip + rva_0]\n"
        "movzx eax, byte ptr [r8 + rax + 0x22918]\n"
        "mov ecx, dword ptr [r8 + rax*4 + 0x22908]\n"
        "apw_add64_load reg_rcx, reg_r8\n"
        "jmp rcx\n"
        ".L_21b90_21ca6:\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3ea\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_21cc5:\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3fe\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_21ce4:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3ed\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_21d03:\n"
        "add edx, 0xfffffb2d\n"
        "cmp edx, 0x92\n"
        "ja .L_21b90_22892\n"
        "lea r8, [rip + rva_0]\n"
        "movzx eax, byte ptr [r8 + rdx + 0x22a30]\n"
        "mov edx, dword ptr [r8 + rax*4 + 0x22990]\n"
        "apw_add64_load reg_rdx, reg_r8\n"
        "jmp rdx\n"
        ".L_21b90_21d32:\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x55c\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_21d48:\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "call rva_33cdc\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "test rax, rax\n"
        "je .L_21b90_21da3\n"
        "mov qword ptr [rsp + 0x60], rbx\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aa28]\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "mov r9, qword ptr [rdi]\n"
        "lea r8, [rsp + 0x60]\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [r9 + 0x110]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov rbx, qword ptr [rsp + 0x60]\n"
        "mov rax, qword ptr [rdi]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_21b90_21da3:\n"
        "mov qword ptr [rsi], rbx\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21db6:\n"
        "test rdi, rdi\n"
        "je .L_21b90_22892\n"
        "call rva_342b4\n"
        "apw_mov64_load reg_rbx, reg_rax\n"
        "call qword ptr [rip + rva_3a070]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "mov r9d, dword ptr [rdi + 8]\n"
        "apw_mov64_load reg_r8, reg_rbx\n"
        "mov rdx, qword ptr [rdi]\n"
        "call qword ptr [rip + rva_3a5c8]\n"
        "movsxd rcx, eax\n"
        "mov qword ptr [rdi + 0x10], rcx\n"
        ".L_21b90_21de7:\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "apw_mov64_load reg_r9, reg_r12\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3e8\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "call rva_3433f\n"
        "test r12, r12\n"
        "je .L_21b90_22892\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3a200]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21e19:\n"
        "mov dword ptr [r9], ebx\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "apw_mov32_load reg_ecx, reg_edi\n"
        "call rva_33e0e\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21e2b:\n"
        "mov rcx, qword ptr [rcx + 0xc0]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "call rva_bfd0\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21e45:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], 0xffffffff\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ec\n"
        "call rva_3433f\n"
        "test r12, r12\n"
        "je .L_21b90_22892\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3a728]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21e81:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_3ad3b]\n"
        "mov ecx, 0xeb\n"
        "call rva_33e44\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21e9a:\n"
        "cmp r12d, 1\n"
        "jne .L_21b90_21ed6\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_21ec1\n"
        "mov dword ptr [rsp + 0x20], r12d\n"
        "apw_mov64_load reg_r9, reg_rdi\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3f0\n"
        "call rva_3433f\n"
        ".L_21b90_21ec1:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "mov ecx, 0x133\n"
        "call rva_33e44\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21ed6:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov ecx, 0x134\n"
        "call rva_33e44\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "mov r8d, 0x3f0\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_21f04:\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_34942\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21f14:\n"
        "cmp rdi, 1\n"
        "je .L_21b90_21f38\n"
        "cmp rdi, 5\n"
        "je .L_21b90_21f38\n"
        "cmp rdi, 0x22\n"
        "je .L_21b90_21f38\n"
        "lea rax, [rdi - 0x1f]\n"
        "test rax, -0xb\n"
        "jne .L_21b90_21f5b\n"
        "cmp rdi, 0x29\n"
        "je .L_21b90_21f5b\n"
        ".L_21b90_21f38:\n"
        "cmp rdi, 0x1f\n"
        "je .L_21b90_21f44\n"
        "cmp rdi, 0x22\n"
        "jne .L_21b90_21f5b\n"
        ".L_21b90_21f44:\n"
        "mov edx, dword ptr [rcx + 0x2ec]\n"
        "cmp edx, -1\n"
        "je .L_21b90_21f5b\n"
        "add rcx, 0x2f0\n"
        "call rva_348f4\n"
        ".L_21b90_21f5b:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rip + rva_3ad3b]\n"
        "mov ecx, 0xec\n"
        "call rva_33e44\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_21f74:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3f8\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_21f93:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3f1\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_21fb2:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3f2\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_21fd1:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3f3\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_21ff0:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], 0xffffffff\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ee\n"
        "call rva_3433f\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3a728]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_22023:\n"
        "inc dword ptr [rip + rva_536bc]\n"
        "cmp edi, 1\n"
        "jne .L_21b90_220e4\n"
        "lea rcx, [rip + rva_423c8]\n"
        "call qword ptr [rip + rva_3a6b0]\n"
        "test rax, rax\n"
        "jne .L_21b90_2210b\n"
        "mov qword ptr [rsp + 0x78], rbx\n"
        "mov qword ptr [rbp - 0x80], 7\n"
        "mov qword ptr [rbp - 0x78], 0xf\n"
        "mov rax, qword ptr [rip + rva_423d0]\n"
        "mov dword ptr [rsp + 0x70], eax\n"
        "movzx eax, word ptr [rip + rva_423d4]\n"
        "mov word ptr [rsp + 0x74], ax\n"
        "movzx eax, byte ptr [rip + rva_423d6]\n"
        "mov byte ptr [rsp + 0x76], al\n"
        "mov byte ptr [rsp + 0x77], bl\n"
        "lea rcx, [rsp + 0x70]\n"
        "call rva_1f530\n"
        "apw_mov64_load reg_rsi, reg_rax\n"
        "lea rdx, [rip + rva_423d8]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rip + rva_3a300]\n"
        "apw_mov64_load reg_r14, reg_rax\n"
        "apw_mov64_load reg_rcx, reg_rsi\n"
        "call qword ptr [rip + rva_3a370]\n"
        "call rva_33bd0\n"
        "lea rcx, [rip + rva_41750]\n"
        "lea r9, [rip + rva_41758]\n"
        "apw_cmp32_load reg_eax, reg_edi\n"
        "cmove r9, rcx\n"
        "apw_mov64_load reg_r8, reg_r14\n"
        "lea rdx, [rip + rva_423e4]\n"
        "lea rcx, [rbp - 0x20]\n"
        "call rva_1ce0\n"
        "lea rcx, [rbp - 0x20]\n"
        "call qword ptr [rip + rva_3a6c8]\n"
        "jmp .L_21b90_2210b\n"
        ".L_21b90_220e4:\n"
        "cmp edi, 0x101f\n"
        "je .L_21b90_220f4\n"
        "cmp edi, 0x1022\n"
        "jne .L_21b90_2210b\n"
        ".L_21b90_220f4:\n"
        "mov edx, dword ptr [rcx + 0x2ec]\n"
        "cmp edx, -1\n"
        "je .L_21b90_2210b\n"
        "add rcx, 0x2f0\n"
        "call rva_348f4\n"
        ".L_21b90_2210b:\n"
        "cmp dword ptr [rip + rva_536bc], 2\n"
        "jge .L_21b90_22121\n"
        "apw_mov64_load reg_r8, reg_rdi\n"
        "apw_mov32_load reg_edx, reg_r12d\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call rva_348e2\n"
        ".L_21b90_22121:\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_221b1\n"
        "mov dword ptr [rsp + 0x20], 0x6f\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "call rva_3433f\n"
        "mov dword ptr [rsp + 0x20], 0x75\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "call rva_3433f\n"
        "cmp byte ptr [r15 + 0xd8], bl\n"
        "je .L_21b90_221b1\n"
        "cmp dword ptr [r15 + 0xdc], ebx\n"
        "je .L_21b90_221b1\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_221b1\n"
        "cmp edi, 0xc\n"
        "jge .L_21b90_221b1\n"
        "lea rax, [rsp + 0x50]\n"
        "mov qword ptr [rsp + 0x30], rax\n"
        "mov dword ptr [rsp + 0x28], ebx\n"
        "mov dword ptr [rsp + 0x20], 0x7b\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "call rva_343ca\n"
        ".L_21b90_221b1:\n"
        "call rva_347bb\n"
        "test eax, eax\n"
        "je .L_21b90_221cf\n"
        "call rva_33e20\n"
        "call rva_33e7a\n"
        "dec dword ptr [rip + rva_536bc]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_221cf:\n"
        "call rva_33e32\n"
        "call rva_33e7a\n"
        "dec dword ptr [rip + rva_536bc]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_221e4:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], 0x76\n"
        "mov r8d, 0x3ed\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_22207:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "cmp r12, 4\n"
        "jne .L_21b90_22235\n"
        "mov dword ptr [rsp + 0x20], 0x6d\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "call rva_3433f\n"
        ".L_21b90_22235:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov32_load reg_edx, reg_r12d\n"
        "lea ecx, [r8 + 3]\n"
        "call rva_348e2\n"
        "mov dword ptr [rsp + 0x20], 0x75\n"
        "mov r8d, 0x3ed\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_2225e:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "lea r9, [rip + rva_423f0]\n"
        "mov r8d, 0x3f8\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "jmp .L_21b90_2288d\n"
        ".L_21b90_22287:\n"
        "test rdi, rdi\n"
        "je .L_21b90_222a2\n"
        "mov r8d, 5\n"
        "lea rdx, [rip + rva_42400]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a8c8]\n"
        ".L_21b90_222a2:\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov32_load reg_edx, reg_r12d\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_53090]\n"
        "movsxd rcx, eax\n"
        "mov qword ptr [rsi], rcx\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_222bc:\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aac0]\n"
        ".byte 0x90 # alignment NOP\n"
        "apw_mov32_load reg_esi, reg_ebx\n"
        ".byte 0xf,0x1f,0x0 # alignment NOP\n"
        ".L_21b90_222d0:\n"
        "apw_mov32_load reg_r8d, reg_esi\n"
        "mov dl, 0x2c\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aa70]\n"
        "apw_mov32_load reg_r14d, reg_eax\n"
        "apw_mov32_load reg_r8d, reg_esi\n"
        "lea rcx, [rsp + 0x58]\n"
        "test eax, eax\n"
        "jle .L_21b90_22306\n"
        "apw_mov32_load reg_r9d, reg_eax\n"
        "apw_sub32_load reg_r9d, reg_esi\n"
        "lea rdx, [rsp + 0x68]\n"
        "call qword ptr [rip + rva_3aa48]\n"
        ".byte 0x90 # alignment NOP\n"
        "or ebx, 1\n"
        "jmp .L_21b90_22314\n"
        ".L_21b90_22306:\n"
        "lea rdx, [rbp - 0x28]\n"
        "call qword ptr [rip + rva_3aa50]\n"
        ".byte 0x90 # alignment NOP\n"
        "or ebx, 2\n"
        ".L_21b90_22314:\n"
        "mov dword ptr [rsp + 0x50], ebx\n"
        "apw_mov64_load reg_rdx, reg_rax\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3aac8]\n"
        ".byte 0x90 # alignment NOP\n"
        "test bl, 2\n"
        "je .L_21b90_2233e\n"
        "and ebx, 0xfffffffd\n"
        "mov dword ptr [rsp + 0x50], ebx\n"
        "lea rcx, [rbp - 0x28]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_21b90_2233e:\n"
        "test bl, 1\n"
        "je .L_21b90_22355\n"
        "and ebx, 0xfffffffe\n"
        "mov dword ptr [rsp + 0x50], ebx\n"
        "lea rcx, [rsp + 0x68]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        ".L_21b90_22355:\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3ab18]\n"
        "apw_mov32_load reg_edx, reg_edi\n"
        "mov rcx, qword ptr [rax]\n"
        "call rva_34163\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x60]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "test r14d, r14d\n"
        "js .L_21b90_22384\n"
        "lea esi, [r14 + 1]\n"
        "jmp .L_21b90_222d0\n"
        ".L_21b90_22384:\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_223a5\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "apw_mov64_load reg_r9, reg_r12\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x54e\n"
        "call rva_3433f\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_21b90_223a5:\n"
        "lea rcx, [rsp + 0x58]\n"
        "call qword ptr [rip + rva_3aab8]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_223b5:\n"
        "xorps xmm0, xmm0\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "movups xmmword ptr [rbp - 0x58], xmm0\n"
        "mov qword ptr [rbp - 0x48], rax\n"
        "lea rcx, [rbp - 0x58]\n"
        "call qword ptr [rip + rva_3a518]\n"
        ".byte 0x90 # alignment NOP\n"
        "xorps xmm0, xmm0\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "movups xmmword ptr [rbp - 0x70], xmm0\n"
        "mov qword ptr [rbp - 0x60], rax\n"
        "lea rcx, [rbp - 0x70]\n"
        "call qword ptr [rip + rva_3a518]\n"
        ".byte 0x90 # alignment NOP\n"
        "xorps xmm0, xmm0\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "movups xmmword ptr [rsp + 0x70], xmm0\n"
        "mov qword ptr [rbp - 0x80], rax\n"
        "lea rcx, [rsp + 0x70]\n"
        "call qword ptr [rip + rva_3a518]\n"
        ".byte 0x90 # alignment NOP\n"
        "xorps xmm0, xmm0\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "movups xmmword ptr [rbp - 0x40], xmm0\n"
        "mov qword ptr [rbp - 0x30], rax\n"
        "lea rcx, [rbp - 0x40]\n"
        "call qword ptr [rip + rva_3a518]\n"
        ".byte 0x90 # alignment NOP\n"
        "test rdi, rdi\n"
        "je .L_21b90_22451\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_mov64_load reg_r9, reg_rbx\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rbp - 0x58]\n"
        "call rva_22ad0\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_mov64_load reg_r9, reg_rbx\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "lea rcx, [rbp - 0x70]\n"
        "call rva_22ad0\n"
        "mov rax, qword ptr [rdi]\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_21b90_22451:\n"
        "mov r9d, 8\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rbp - 0x58]\n"
        "lea rcx, [rsp + 0x70]\n"
        "call qword ptr [rip + rva_3a500]\n"
        "mov r9d, 8\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "lea rdx, [rbp - 0x70]\n"
        "lea rcx, [rbp - 0x40]\n"
        "call qword ptr [rip + rva_3a500]\n"
        "mov rcx, qword ptr [rbp - 0x38]\n"
        "call qword ptr [rip + rva_3a548]\n"
        "apw_mov32_load reg_edi, reg_eax\n"
        "movzx esi, word ptr [rbp - 0x70]\n"
        "mov rcx, qword ptr [rsp + 0x78]\n"
        "call qword ptr [rip + rva_3a548]\n"
        "movzx r9d, word ptr [rbp - 0x58]\n"
        "mov rcx, qword ptr [rbp - 0x38]\n"
        "mov qword ptr [rsp + 0x40], rcx\n"
        "mov dword ptr [rsp + 0x38], edi\n"
        "mov dword ptr [rsp + 0x30], esi\n"
        "mov rcx, qword ptr [rsp + 0x78]\n"
        "mov qword ptr [rsp + 0x28], rcx\n"
        "mov dword ptr [rsp + 0x20], eax\n"
        "apw_mov64_load reg_r8, reg_r12\n"
        "lea rdx, [rip + rva_42408]\n"
        "lea rcx, [rbp - 0x20]\n"
        "call rva_1ce0\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_224f5\n"
        "mov dword ptr [rsp + 0x20], r12d\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x12f\n"
        "lea rdx, [rbp - 0x20]\n"
        "call rva_3433f\n"
        ".L_21b90_224f5:\n"
        "sub r12, 6\n"
        "je .L_21b90_22621\n"
        "cmp r12, 1\n"
        "jne .L_21b90_2263d\n"
        "lea esi, [r12 - 2]\n"
        "cmp word ptr [rbp - 0x58], 8\n"
        "jne .L_21b90_225dc\n"
        "mov r14, qword ptr [rbp - 0x50]\n"
        "lea ecx, [rsi + 0x19]\n"
        "call rva_34f86\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "mov qword ptr [rsp + 0x68], rax\n"
        "test rax, rax\n"
        "je .L_21b90_22556\n"
        "mov qword ptr [rax + 8], rbx\n"
        "mov dword ptr [rax + 0x10], r12d\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call qword ptr [rip + rva_3a550]\n"
        "mov qword ptr [rdi], rax\n"
        "test rax, rax\n"
        "jne .L_21b90_22559\n"
        "test r14, r14\n"
        "jne .L_21b90_228c0\n"
        "jmp .L_21b90_22559\n"
        ".L_21b90_22556:\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        ".L_21b90_22559:\n"
        "mov qword ptr [rsp + 0x68], rdi\n"
        "test rdi, rdi\n"
        "je .L_21b90_228b5\n"
        "mov rax, qword ptr [rdi + 8]\n"
        "test rax, rax\n"
        "jne .L_21b90_2257c\n"
        "mov rcx, qword ptr [rdi]\n"
        "call rva_34b30\n"
        "mov qword ptr [rdi + 8], rax\n"
        ".L_21b90_2257c:\n"
        "lea r14, [r15 + 0x2f0]\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "apw_sub64_load reg_rdx, reg_rax\n"
        ".byte 0xf,0x1f,0x80,0x0,0x0,0x0,0x0 # alignment NOP\n"
        ".L_21b90_22590:\n"
        "movzx ecx, byte ptr [rax]\n"
        "mov byte ptr [rax + rdx], cl\n"
        "lea rax, [rax + 1]\n"
        "test cl, cl\n"
        "jne .L_21b90_22590\n"
        "apw_mov32_load reg_eax, reg_esi\n"
        "lock xadd dword ptr [rdi + 0x10], eax\n"
        "cmp eax, 1\n"
        "jne .L_21b90_225e7\n"
        "mov rcx, qword ptr [rdi]\n"
        "test rcx, rcx\n"
        "je .L_21b90_225bb\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "mov qword ptr [rdi], rbx\n"
        ".L_21b90_225bb:\n"
        "mov rcx, qword ptr [rdi + 8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_225cd\n"
        "call rva_34f92\n"
        "mov qword ptr [rdi + 8], rbx\n"
        ".L_21b90_225cd:\n"
        "mov edx, 0x18\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call rva_35134\n"
        "jmp .L_21b90_225e7\n"
        ".L_21b90_225dc:\n"
        "lea r14, [r15 + 0x2f0]\n"
        "mov byte ptr [r14], 0\n"
        ".L_21b90_225e7:\n"
        "lea rdx, [rip + rva_42420]\n"
        "apw_mov64_load reg_rcx, reg_r14\n"
        "call rva_362f8\n"
        "test eax, eax\n"
        "jne .L_21b90_2260f\n"
        "mov eax, dword ptr [rip + rva_42430]\n"
        "mov dword ptr [r14], eax\n"
        "movzx eax, word ptr [rip + rva_42434]\n"
        "mov word ptr [r14 + 4], ax\n"
        ".L_21b90_2260f:\n"
        "cmp word ptr [rbp - 0x70], 3\n"
        "cmove esi, dword ptr [rbp - 0x68]\n"
        "mov dword ptr [r15 + 0x2ec], esi\n"
        "jmp .L_21b90_2263d\n"
        ".L_21b90_22621:\n"
        "mov dword ptr [r15 + 0x2ec], 7\n"
        "movabs rax, 0x6e776f6e6b6e75\n"
        "mov qword ptr [r15 + 0x2f0], rax\n"
        ".L_21b90_2263d:\n"
        "lea rcx, [rbp - 0x40]\n"
        "call qword ptr [rip + rva_3a510]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rsp + 0x70]\n"
        "call qword ptr [rip + rva_3a510]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x70]\n"
        "call qword ptr [rip + rva_3a510]\n"
        ".byte 0x90 # alignment NOP\n"
        "lea rcx, [rbp - 0x58]\n"
        "call qword ptr [rip + rva_3a510]\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_2266e:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_2268e\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x3ed\n"
        "call rva_3433f\n"
        ".L_21b90_2268e:\n"
        "mov rcx, qword ptr [r15 + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "cmp rdi, 0x13\n"
        "jne .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], 0x75\n"
        "mov r8d, 0x3ed\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_226bb:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3ef\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_226da:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x4ed\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_226f9:\n"
        "mov rcx, qword ptr [rcx + 0xc0]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "apw_mov64_load reg_r8, reg_r12\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "call rva_1b0b0\n"
        "movsxd rcx, eax\n"
        "mov qword ptr [rsi], rcx\n"
        "jmp .L_21b90_22892\n"
        ".L_21b90_2271f:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "mov r8d, 0x4f3\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_2273e:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov rax, qword ptr [r15 + 0xc0]\n"
        "test rax, rax\n"
        "je .L_21b90_22892\n"
        "cmp byte ptr [rax + 0xc8], bl\n"
        "jne .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "mov r8d, 0x4f4\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_22779:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "mov r8d, 0x4f5\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_22798:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x4fa\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "jmp .L_21b90_2288d\n"
        ".L_21b90_227bd:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "mov r8d, 0x565\n"
        "jmp .L_21b90_2288b\n"
        ".L_21b90_227dc:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x3fa\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "jmp .L_21b90_2288d\n"
        ".L_21b90_22801:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x4fd\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "jmp .L_21b90_2288d\n"
        ".L_21b90_22823:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], ebx\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "mov r8d, 0x4fe\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "jmp .L_21b90_2288d\n"
        ".L_21b90_22841:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x3fc\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_22859:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], edi\n"
        "mov r8d, 0x4f9\n"
        "jmp .L_21b90_22888\n"
        ".L_21b90_22871:\n"
        "mov rcx, qword ptr [rcx + 0xc8]\n"
        "test rcx, rcx\n"
        "je .L_21b90_22892\n"
        "mov dword ptr [rsp + 0x20], r12d\n"
        "mov r8d, 0x55d\n"
        ".L_21b90_22888:\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        ".L_21b90_2288b:\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        ".L_21b90_2288d:\n"
        "call rva_3433f\n"
        ".L_21b90_22892:\n"
        "apw_xor32_load reg_eax, reg_eax\n"
        "mov rcx, qword ptr [rbp + 0xf0]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "add rsp, 0x200\n"
        "pop r15\n"
        "pop r14\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbx\n"
        "pop rbp\n"
        "ret\n"
        ".L_21b90_228b5:\n"
        "mov ecx, 0x8007000e\n"
        "call rva_34a60\n"
        ".byte 0x90 # alignment NOP\n"
        ".L_21b90_228c0:\n"
        "mov ecx, 0x8007000e\n"
        "call rva_34a60\n"
        "int3\n"
        ".byte 0x90 # padding outside reachable blocks\n"
        ".long 0x21b90 + (.L_21b90_21c5c - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21ca6 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22892 - apw_21b90) # switch target RVA\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0xf,0x1f,0x0 # padding outside reachable blocks\n"
        ".long 0x21b90 + (.L_21b90_21ca6 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21cc5 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21c5c - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22892 - apw_21b90) # switch target RVA\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 0xf,0x1f,0x0 # padding outside reachable blocks\n"
        ".long 0x21b90 + (.L_21b90_22892 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_2266e - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21d48 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_226f9 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21db6 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_226da - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_226bb - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_2271f - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_2273e - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22779 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_227dc - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22841 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22859 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22798 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22801 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22823 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22207 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21de7 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21e81 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21f14 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21e45 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21f93 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21fb2 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21fd1 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22023 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21e2b - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21f04 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22287 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21f74 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_2225e - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_223b5 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_222bc - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21e19 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21e9a - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21ff0 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_221e4 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_21d32 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22871 - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_227bd - apw_21b90) # switch target RVA\n"
        ".long 0x21b90 + (.L_21b90_22892 - apw_21b90) # switch target RVA\n"
        ".byte 0 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 4 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 5 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 6 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 7 # case group index\n"
        ".byte 8 # case group index\n"
        ".byte 9 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 10 # case group index\n"
        ".byte 11 # case group index\n"
        ".byte 12 # case group index\n"
        ".byte 13 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 14 # case group index\n"
        ".byte 15 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 16 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 17 # case group index\n"
        ".byte 18 # case group index\n"
        ".byte 19 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 20 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 21 # case group index\n"
        ".byte 22 # case group index\n"
        ".byte 23 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 24 # case group index\n"
        ".byte 25 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 26 # case group index\n"
        ".byte 27 # case group index\n"
        ".byte 28 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 29 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 30 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 31 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 32 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 33 # case group index\n"
        ".byte 34 # case group index\n"
        ".byte 35 # case group index\n"
        ".byte 36 # case group index\n"
        ".byte 37 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 39 # case group index\n"
        ".byte 38 # case group index\n"
        END);
}

/* body 0x22ad0 until 0x22f0a */
BODY void apw_22ad0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 0x18], rbx\n"
        "push rbp\n"
        "push rsi\n"
        "push rdi\n"
        "push r12\n"
        "push r13\n"
        "push r14\n"
        "push r15\n"
        "apw_mov64_load reg_rbp, reg_rsp\n"
        "sub rsp, 0x80\n"
        "mov rax, qword ptr [rip + rva_52888]\n"
        "apw_xor64_load reg_rax, reg_rsp\n"
        "mov qword ptr [rbp - 0x10], rax\n"
        "apw_mov64_load reg_rdi, reg_r9\n"
        "movzx r14d, r8w\n"
        "apw_mov64_load reg_r15, reg_rdx\n"
        "apw_mov64_load reg_r12, reg_rcx\n"
        "test rdx, rdx\n"
        "jne .L_22ad0_22b14\n"
        "mov eax, 0x80070057\n"
        "jmp .L_22ad0_22eb5\n"
        ".L_22ad0_22b14:\n"
        "call qword ptr [rip + rva_3a510]\n"
        "test eax, eax\n"
        "js .L_22ad0_22eb5\n"
        "apw_xor32_load reg_ebx, reg_ebx\n"
        "mov word ptr [rbp - 0x40], bx\n"
        "mov dword ptr [rbp - 0x50], ebx\n"
        "mov rax, qword ptr [r15]\n"
        "lea r9, [rbp - 0x50]\n"
        "lea r8d, [rbx + 2]\n"
        "lea rdx, [rbp - 0x40]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x18]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "cmp eax, 1\n"
        "je .L_22ad0_22eae\n"
        "cmp dword ptr [rbp - 0x50], 2\n"
        "je .L_22ad0_22b59\n"
        "test eax, eax\n"
        "je .L_22ad0_22eae\n"
        ".L_22ad0_22b59:\n"
        "test eax, eax\n"
        "js .L_22ad0_22eb3\n"
        "movzx edx, word ptr [rbp - 0x40]\n"
        "test r14w, r14w\n"
        "je .L_22ad0_22b7b\n"
        "apw_cmp16_load reg_dx, reg_r14w\n"
        "je .L_22ad0_22b7b\n"
        "mov eax, 0x80004005\n"
        "jmp .L_22ad0_22eb5\n"
        ".L_22ad0_22b7b:\n"
        "mov word ptr [r12], dx\n"
        "mov dword ptr [rbp - 0x50], ebx\n"
        "lea eax, [rdx - 2]\n"
        "cmp eax, 0x15\n"
        "ja .L_22ad0_22d2b\n"
        "cdqe\n"
        "lea r8, [rip + rva_0]\n"
        "movzx eax, byte ptr [r8 + rax + 0x22ef4]\n"
        "mov ecx, dword ptr [r8 + rax*4 + 0x22edc]\n"
        "apw_add64_load reg_rcx, reg_r8\n"
        "jmp rcx\n"
        ".L_22ad0_22bae:\n"
        "lea rax, [rip + rva_41330]\n"
        "lea r14, [rip + rva_42020]\n"
        "cmp edx, 0xd\n"
        "cmove r14, rax\n"
        "mov qword ptr [r12 + 8], rbx\n"
        "lea rdx, [rbp - 0x20]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rip + rva_3ab98]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "js .L_22ad0_22cd5\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov qword ptr [rbp - 0x48], rbx\n"
        "mov r8d, dword ptr [rbp + 0x60]\n"
        "test r8d, r8d\n"
        "je .L_22ad0_22c1e\n"
        "mov esi, 0x80070005\n"
        "apw_mov32_load reg_edx, reg_ebx\n"
        "mov r9, qword ptr [rbp - 0x18]\n"
        "mov r10, qword ptr [rbp - 0x20]\n"
        ".byte 0x66,0x90 # alignment NOP\n"
        ".L_22ad0_22c00:\n"
        "apw_mov32_load reg_eax, reg_edx\n"
        "apw_add64_load reg_rax, reg_rax\n"
        "cmp r10, qword ptr [rdi + rax*8]\n"
        "jne .L_22ad0_22c12\n"
        "cmp r9, qword ptr [rdi + rax*8 + 8]\n"
        "je .L_22ad0_22c43\n"
        ".L_22ad0_22c12:\n"
        "inc edx\n"
        "apw_cmp32_load reg_edx, reg_r8d\n"
        "jb .L_22ad0_22c00\n"
        "jmp .L_22ad0_22cca\n"
        ".L_22ad0_22c1e:\n"
        "test rdi, rdi\n"
        "je .L_22ad0_22c3e\n"
        "lea r8, [rbp - 0x48]\n"
        "apw_mov64_load reg_rdx, reg_r14\n"
        "lea rcx, [rbp - 0x20]\n"
        "call rdi\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "mov rcx, qword ptr [rbp - 0x48]\n"
        "test eax, eax\n"
        "js .L_22ad0_22cca\n"
        ".L_22ad0_22c3e:\n"
        "test rcx, rcx\n"
        "jne .L_22ad0_22c71\n"
        ".L_22ad0_22c43:\n"
        "lea rax, [rbp - 0x48]\n"
        "mov qword ptr [rsp + 0x20], rax\n"
        "apw_mov64_load reg_r9, reg_r14\n"
        "apw_xor32_load reg_edx, reg_edx\n"
        "mov r8d, 0x415\n"
        "lea rcx, [rbp - 0x20]\n"
        "call qword ptr [rip + rva_3ab68]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "jns .L_22ad0_22c6d\n"
        "mov rcx, qword ptr [rbp - 0x48]\n"
        "jmp .L_22ad0_22cca\n"
        ".L_22ad0_22c6d:\n"
        "mov rcx, qword ptr [rbp - 0x48]\n"
        ".L_22ad0_22c71:\n"
        "mov qword ptr [rbp - 0x38], rbx\n"
        "mov rax, qword ptr [rcx]\n"
        "lea r8, [rbp - 0x38]\n"
        "lea rdx, [rip + rva_42030]\n"
        "call qword ptr [rax]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "js .L_22ad0_22cb0\n"
        "mov rcx, qword ptr [rbp - 0x38]\n"
        "mov rax, qword ptr [rcx]\n"
        "apw_mov64_load reg_rdx, reg_r15\n"
        "call qword ptr [rax + 0x28]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "js .L_22ad0_22cb0\n"
        "mov rax, qword ptr [rbp - 0x48]\n"
        "apw_mov64_load reg_rcx, reg_rbx\n"
        "mov qword ptr [rbp - 0x48], rbx\n"
        "mov qword ptr [r12 + 8], rax\n"
        "jmp .L_22ad0_22cb4\n"
        ".L_22ad0_22cb0:\n"
        "mov rcx, qword ptr [rbp - 0x48]\n"
        ".L_22ad0_22cb4:\n"
        "mov rax, qword ptr [rbp - 0x38]\n"
        "test rax, rax\n"
        "je .L_22ad0_22cca\n"
        "mov rdx, qword ptr [rax]\n"
        "apw_mov64_load reg_rcx, reg_rax\n"
        "call qword ptr [rdx + 0x10]\n"
        "mov rcx, qword ptr [rbp - 0x48]\n"
        ".L_22ad0_22cca:\n"
        "test rcx, rcx\n"
        "je .L_22ad0_22cd5\n"
        "mov rax, qword ptr [rcx]\n"
        "call qword ptr [rax + 0x10]\n"
        ".L_22ad0_22cd5:\n"
        "cmp esi, 0x80040154\n"
        "cmovne ebx, esi\n"
        "apw_mov32_load reg_eax, reg_ebx\n"
        "jmp .L_22ad0_22eb5\n"
        ".L_22ad0_22ce5:\n"
        "mov r14d, 1\n"
        "jmp .L_22ad0_22d03\n"
        ".L_22ad0_22ced:\n"
        "mov r14d, 2\n"
        "jmp .L_22ad0_22d03\n"
        ".L_22ad0_22cf5:\n"
        "mov r14d, 4\n"
        "jmp .L_22ad0_22d03\n"
        ".L_22ad0_22cfd:\n"
        "mov r14d, 8\n"
        ".L_22ad0_22d03:\n"
        "mov dword ptr [rbp - 0x50], r14d\n"
        "mov rax, qword ptr [r15]\n"
        "lea rdx, [r12 + 8]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_mov32_load reg_r8d, reg_r14d\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x18]\n"
        "mov esi, 0x80004005\n"
        "cmp eax, 1\n"
        "cmove eax, esi\n"
        "jmp .L_22ad0_22eb5\n"
        ".L_22ad0_22d2b:\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        "mov qword ptr [rbp - 0x28], rbx\n"
        "mov rax, qword ptr [r15]\n"
        "lea r9, [rbp - 0x20]\n"
        "mov r14d, 1\n"
        "apw_mov32_load reg_r8d, reg_r14d\n"
        "apw_mov64_load reg_rdx, reg_rbx\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x28]\n"
        "apw_mov32_load reg_r13d, reg_eax\n"
        "mov dword ptr [rbp - 0x38], ebx\n"
        "mov dword ptr [rbp - 0x48], ebx\n"
        "mov r10, qword ptr [r15]\n"
        "lea r9, [rbp - 0x38]\n"
        "lea r8d, [r14 + 3]\n"
        "lea rdx, [rbp - 0x48]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [r10 + 0x18]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "js .L_22ad0_22e3e\n"
        "cmp dword ptr [rbp - 0x38], 4\n"
        "je .L_22ad0_22d8c\n"
        "mov esi, 0x80004005\n"
        "jmp .L_22ad0_22e3e\n"
        ".L_22ad0_22d8c:\n"
        "mov edx, dword ptr [rbp - 0x48]\n"
        "test edx, edx\n"
        "je .L_22ad0_22e3a\n"
        "cmp edx, 2\n"
        "jae .L_22ad0_22da6\n"
        "mov esi, 0x80004005\n"
        "jmp .L_22ad0_22e3e\n"
        ".L_22ad0_22da6:\n"
        "cmp edx, 0x100000\n"
        "jbe .L_22ad0_22db8\n"
        "mov esi, 0x80070005\n"
        "jmp .L_22ad0_22e3e\n"
        ".L_22ad0_22db8:\n"
        "add edx, -2\n"
        "mov dword ptr [rbp - 0x48], edx\n"
        "apw_xor32_load reg_ecx, reg_ecx\n"
        "call qword ptr [rip + rva_3a520]\n"
        "apw_mov64_load reg_rdi, reg_rax\n"
        "mov qword ptr [rbp - 0x28], rax\n"
        "test rax, rax\n"
        "jne .L_22ad0_22dd9\n"
        "mov esi, 0x8007000e\n"
        "jmp .L_22ad0_22e3e\n"
        ".L_22ad0_22dd9:\n"
        "mov rax, qword ptr [r15]\n"
        "lea r9, [rbp - 0x38]\n"
        "mov r8d, dword ptr [rbp - 0x48]\n"
        "apw_mov64_load reg_rdx, reg_rdi\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x18]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "js .L_22ad0_22e2a\n"
        "mov eax, dword ptr [rbp - 0x48]\n"
        "cmp dword ptr [rbp - 0x38], eax\n"
        "jne .L_22ad0_22e25\n"
        "mov rax, qword ptr [r15]\n"
        "lea r9, [rbp - 0x38]\n"
        "mov r8d, 2\n"
        "lea rdx, [rbp - 0x30]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x18]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        "test eax, eax\n"
        "js .L_22ad0_22e2a\n"
        "cmp dword ptr [rbp - 0x38], 2\n"
        "jne .L_22ad0_22e25\n"
        "cmp word ptr [rbp - 0x30], 0\n"
        "je .L_22ad0_22e56\n"
        ".L_22ad0_22e25:\n"
        "mov esi, 0x80004005\n"
        ".L_22ad0_22e2a:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        "mov qword ptr [rbp - 0x28], rbx\n"
        ".L_22ad0_22e3a:\n"
        "test esi, esi\n"
        "jns .L_22ad0_22e74\n"
        ".L_22ad0_22e3e:\n"
        "test r13d, r13d\n"
        "js .L_22ad0_22e56\n"
        "mov rax, qword ptr [r15]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "mov rdx, qword ptr [rbp - 0x20]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x28]\n"
        ".L_22ad0_22e56:\n"
        "test esi, esi\n"
        "jns .L_22ad0_22e74\n"
        "mov rax, qword ptr [r15]\n"
        "apw_xor32_load reg_r9d, reg_r9d\n"
        "apw_mov32_load reg_r8d, reg_r14d\n"
        "lea rdx, [r9 - 2]\n"
        "apw_mov64_load reg_rcx, reg_r15\n"
        "call qword ptr [rax + 0x28]\n"
        "mov word ptr [r12], bx\n"
        "jmp .L_22ad0_22ea3\n"
        ".L_22ad0_22e74:\n"
        "mov word ptr [r12], 8\n"
        "apw_mov64_load reg_rax, reg_rdi\n"
        "apw_mov64_load reg_rdi, reg_rbx\n"
        "mov qword ptr [r12 + 8], rax\n"
        "movzx r9d, word ptr [rbp - 0x40]\n"
        "cmp r9w, 8\n"
        "je .L_22ad0_22ea3\n"
        "apw_xor32_load reg_r8d, reg_r8d\n"
        "apw_mov64_load reg_rdx, reg_r12\n"
        "apw_mov64_load reg_rcx, reg_r12\n"
        "call qword ptr [rip + rva_3a500]\n"
        "apw_mov32_load reg_esi, reg_eax\n"
        ".L_22ad0_22ea3:\n"
        "apw_mov64_load reg_rcx, reg_rdi\n"
        "call qword ptr [rip + rva_3a4d0]\n"
        "jmp .L_22ad0_22eb3\n"
        ".L_22ad0_22eae:\n"
        "mov esi, 0x80004005\n"
        ".L_22ad0_22eb3:\n"
        "apw_mov32_load reg_eax, reg_esi\n"
        ".L_22ad0_22eb5:\n"
        "mov rcx, qword ptr [rbp - 0x10]\n"
        "apw_xor64_load reg_rcx, reg_rsp\n"
        "call rva_35630\n"
        "mov rbx, qword ptr [rsp + 0xd0]\n"
        "add rsp, 0x80\n"
        "pop r15\n"
        "pop r14\n"
        "pop r13\n"
        "pop r12\n"
        "pop rdi\n"
        "pop rsi\n"
        "pop rbp\n"
        "ret\n"
        ".long 0x22ad0 + (.L_22ad0_22ced - apw_22ad0) # switch target RVA\n"
        ".long 0x22ad0 + (.L_22ad0_22cf5 - apw_22ad0) # switch target RVA\n"
        ".long 0x22ad0 + (.L_22ad0_22cfd - apw_22ad0) # switch target RVA\n"
        ".long 0x22ad0 + (.L_22ad0_22bae - apw_22ad0) # switch target RVA\n"
        ".long 0x22ad0 + (.L_22ad0_22ce5 - apw_22ad0) # switch target RVA\n"
        ".long 0x22ad0 + (.L_22ad0_22d2b - apw_22ad0) # switch target RVA\n"
        ".byte 0 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 5 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 5 # case group index\n"
        ".byte 3 # case group index\n"
        ".byte 5 # case group index\n"
        ".byte 5 # case group index\n"
        ".byte 4 # case group index\n"
        ".byte 4 # case group index\n"
        ".byte 0 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 2 # case group index\n"
        ".byte 1 # case group index\n"
        ".byte 1 # case group index\n"
        END);
}

