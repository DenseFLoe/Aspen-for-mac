#if PART == 0
/* Preserve incoming argument registers and call the optional pointer when nonzero. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl scope_0\n"
    ".def scope_0; .scl 2; .type 32; .endef\n"
    ".seh_proc scope_0\n"
    "scope_0:\n"
    "sub rsp, 0x28\n"
    ".seh_stackalloc 0x28\n"
    ".seh_endprologue\n"
    "mov rax, qword ptr [rip + rva_194d0]\n"
    "test rax, rax\n"
    "je .Lskip_call\n"
    "call rax\n"
    ".Lskip_call:\n"
    "add rsp, 0x28\n"
    "ret\n"
    ".seh_endproc\n"
    ".att_syntax prefix\n"
);
#endif

#if PART == 1
/* For the degenerate linked interval, only the endpoint can reach Guard CF dispatch. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl scope_1\n"
    ".def scope_1; .scl 2; .type 32; .endef\n"
    ".seh_proc scope_1\n"
    "scope_1:\n"
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
    "mov rax, qword ptr [rip + rva_22d00]\n"
    "test rax, rax\n"
    "je .Lreturn\n"
    "call qword ptr [rip + rva_194b8]\n"
    ".Lreturn:\n"
    "add rsp, 0x28\n"
    "ret\n"
    ".seh_endproc\n"
    ".att_syntax prefix\n"
);
#endif
