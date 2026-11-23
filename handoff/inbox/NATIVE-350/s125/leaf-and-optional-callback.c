#if PART == 0
/* Return with a zero-sized callee stack adjustment and preserve RAX. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl zed_0\n"
    ".def zed_0; .scl 2; .type 32; .endef\n"
    "zed_0:\n"
    "ret 0\n"
    ".att_syntax prefix\n"
);
#endif

#if PART == 1
/* Read and return the first qword of the object passed in RCX. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl zed_1\n"
    ".def zed_1; .scl 2; .type 32; .endef\n"
    "zed_1:\n"
    "mov rax, qword ptr [rcx]\n"
    "ret\n"
    ".att_syntax prefix\n"
);
#endif

#if PART == 2
/* Separate leaf entry with the same first-qword accessor ABI. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl zed_2\n"
    ".def zed_2; .scl 2; .type 32; .endef\n"
    "zed_2:\n"
    "mov rax, qword ptr [rcx]\n"
    "ret\n"
    ".att_syntax prefix\n"
);
#endif

#if PART == 3
/* Separate zero-adjustment return entry with no RAX definition. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl zed_3\n"
    ".def zed_3; .scl 2; .type 32; .endef\n"
    "zed_3:\n"
    "ret 0\n"
    ".att_syntax prefix\n"
);
#endif

#if PART == 4
/* Call the optional handler when RCX matches the linked bound. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl zed_4\n"
    ".def zed_4; .scl 2; .type 32; .endef\n"
    ".seh_proc zed_4\n"
    "zed_4:\n"
    "sub rsp, 0x28\n"
    ".seh_stackalloc 0x28\n"
    ".seh_endprologue\n"
    "lea r8, [rip + rva_1bb00]\n"
    ".byte 0x48, 0x8b, 0xc1 # mov rax, rcx\n"
    "lea rdx, [rip + rva_1bb00]\n"
    ".byte 0x49, 0x2b, 0xc0 # sub rax, r8\n"
    ".byte 0x49, 0x2b, 0xd0 # sub rdx, r8\n"
    ".byte 0x48, 0x3b, 0xc2 # cmp rax, rdx\n"
    "ja .Lreturn\n"
    "mov rax, qword ptr [rip + rva_194d0]\n"
    "test rax, rax\n"
    "je .Lreturn\n"
    "call rax\n"
    ".Lreturn:\n"
    "add rsp, 0x28\n"
    "ret\n"
    ".seh_endproc\n"
    ".att_syntax prefix\n"
);
#endif
