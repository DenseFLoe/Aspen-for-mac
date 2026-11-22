/* body 0x249c0 until 0x24a20 */
BODY void ikc_249c0(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rbp\n"
        "mov qword ptr [rsp + 0x18], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "ikc_mov64_load reg_rdi, reg_r9\n"
        "ikc_mov64_load reg_rsi, reg_r8\n"
        "ikc_mov32_load reg_ebx, reg_edx\n"
        "ikc_mov64_load reg_rbp, reg_rcx\n"
        "call rva_253a8\n"
        "test eax, eax\n"
        "jne .Likc_249fe\n"
        "cmp ebx, 1\n"
        "jne .Likc_249fe\n"
        "ikc_mov64_load reg_r8, reg_rsi\n"
        "ikc_xor32_load reg_edx, reg_edx\n"
        "ikc_mov64_load reg_rcx, reg_rbp\n"
        "ikc_mov64_load reg_rax, reg_rdi\n"
        "call qword ptr [rip + rva_26268]\n"
        ".Likc_249fe:\n"
        "mov rdx, qword ptr [rsp + 0x58]\n"
        "mov ecx, dword ptr [rsp + 0x50]\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rbp, qword ptr [rsp + 0x38]\n"
        "mov rsi, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "jmp rva_2547a\n"
        END);
}

/* body 0x24f00 until 0x24f3c */
BODY void ikc_24f00(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "lea rbx, [rip + rva_2a600]\n"
        "lea rdi, [rip + rva_2a600]\n"
        "jmp .Likc_24f2c\n"
        ".Likc_24f1a:\n"
        "mov rax, qword ptr [rbx]\n"
        "test rax, rax\n"
        "je .Likc_24f28\n"
        "call qword ptr [rip + rva_26268]\n"
        ".Likc_24f28:\n"
        "add rbx, 8\n"
        ".Likc_24f2c:\n"
        "ikc_s13_reg 0x3b, 64, reg_rbx, reg_rdi\n"
        "jb .Likc_24f1a\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x24f3c until 0x24f78 */
BODY void ikc_24f3c(void) {
    __asm__(INTEL
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        "lea rbx, [rip + rva_2a610]\n"
        "lea rdi, [rip + rva_2a610]\n"
        "jmp .Likc_24f68\n"
        ".Likc_24f56:\n"
        "mov rax, qword ptr [rbx]\n"
        "test rax, rax\n"
        "je .Likc_24f64\n"
        "call qword ptr [rip + rva_26268]\n"
        ".Likc_24f64:\n"
        "add rbx, 8\n"
        ".Likc_24f68:\n"
        "ikc_s13_reg 0x3b, 64, reg_rbx, reg_rdi\n"
        "jb .Likc_24f56\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "ret\n"
        END);
}

/* body 0x24fc8 until 0x25002 */
BODY void ikc_24fc8(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea r8, [rip + rva_2a100]\n"
        "ikc_mov64_load reg_rax, reg_rcx\n"
        "lea rdx, [rip + rva_2a100]\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_r8\n"
        "ikc_s13_reg 0x2b, 64, reg_rdx, reg_r8\n"
        "ikc_s13_reg 0x3b, 64, reg_rax, reg_rdx\n"
        "ja .Likc_24ffd\n"
        "mov rax, qword ptr [rip + rva_26280]\n"
        "test rax, rax\n"
        "je .Likc_24ffd\n"
        "mov rax, qword ptr [rip + rva_26280]\n"
        "call rax\n"
        ".Likc_24ffd:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x25004 until 0x25022 */
BODY void ikc_25004(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_26280]\n"
        "test rax, rax\n"
        "je .Likc_2501d\n"
        "mov rax, qword ptr [rip + rva_26280]\n"
        "call rax\n"
        ".Likc_2501d:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x25024 until 0x2505b */
BODY void ikc_25024(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "lea r8, [rip + rva_2a100]\n"
        "ikc_mov64_load reg_rax, reg_rcx\n"
        "lea rdx, [rip + rva_2a100]\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_r8\n"
        "ikc_s13_reg 0x2b, 64, reg_rdx, reg_r8\n"
        "ikc_s13_reg 0x3b, 64, reg_rax, reg_rdx\n"
        "ja .Likc_25056\n"
        "mov rax, qword ptr [rip + rva_34980]\n"
        "test rax, rax\n"
        "je .Likc_25056\n"
        "call qword ptr [rip + rva_26268]\n"
        ".Likc_25056:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x2505c until 0x25077 */
BODY void ikc_2505c(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "mov rax, qword ptr [rip + rva_34980]\n"
        "test rax, rax\n"
        "je .Likc_25072\n"
        "call qword ptr [rip + rva_26268]\n"
        ".Likc_25072:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x25118 until 0x2516b */
BODY void ikc_25118(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "ikc_mov64_load reg_rax, reg_rcx\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_rdx\n"
        "lea rdx, [rip + rva_2a080]\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_rdx\n"
        "add rax, -0x80\n"
        "ikc_s13_reg 0x3b, 64, reg_rax, reg_r8\n"
        "jbe .Likc_25166\n"
        "lea r8, [rip + rva_2a100]\n"
        "ikc_mov64_load reg_rdx, reg_rcx\n"
        "lea rax, [rip + rva_2a100]\n"
        "ikc_s13_reg 0x2b, 64, reg_rdx, reg_r8\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_r8\n"
        "ikc_s13_reg 0x3b, 64, reg_rdx, reg_rax\n"
        "ja .Likc_25166\n"
        "mov rax, qword ptr [rip + rva_26280]\n"
        "test rax, rax\n"
        "je .Likc_25166\n"
        "mov rax, qword ptr [rip + rva_26280]\n"
        "call rax\n"
        ".Likc_25166:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x2516c until 0x251bc */
BODY void ikc_2516c(void) {
    __asm__(INTEL
        "sub rsp, 0x28\n"
        "ikc_mov64_load reg_rax, reg_rcx\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_rdx\n"
        "lea rdx, [rip + rva_2a080]\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_rdx\n"
        "add rax, -0x80\n"
        "ikc_s13_reg 0x3b, 64, reg_rax, reg_r8\n"
        "jbe .Likc_251b7\n"
        "lea r8, [rip + rva_2a100]\n"
        "ikc_mov64_load reg_rdx, reg_rcx\n"
        "lea rax, [rip + rva_2a100]\n"
        "ikc_s13_reg 0x2b, 64, reg_rdx, reg_r8\n"
        "ikc_s13_reg 0x2b, 64, reg_rax, reg_r8\n"
        "ikc_s13_reg 0x3b, 64, reg_rdx, reg_rax\n"
        "ja .Likc_251b7\n"
        "mov rax, qword ptr [rip + rva_34980]\n"
        "test rax, rax\n"
        "je .Likc_251b7\n"
        "call qword ptr [rip + rva_26268]\n"
        ".Likc_251b7:\n"
        "add rsp, 0x28\n"
        "ret\n"
        END);
}

/* body 0x25560 until 0x25562 */
BODY void ikc_25560(void) {
    __asm__(INTEL
        "jmp rax\n"
        END);
}

/* body 0x25580 until 0x25586 */
BODY void ikc_25580(void) {
    __asm__(INTEL
        "jmp qword ptr [rip + rva_26268]\n"
        END);
}

