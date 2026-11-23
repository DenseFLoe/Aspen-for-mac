#if PART == 0
/* Dispatch to the target held in RAX under the Windows x64 ABI. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl dispatch_0\n"
    ".def dispatch_0; .scl 2; .type 32; .endef\n"
    "dispatch_0:\n"
    "jmp rax\n"
    ".Lend:\n"
    ".section .xdata,\"dr\"\n"
    ".balign 4\n"
    ".Lunwind:\n"
    ".byte 1, 0, 0, 0\n"
    ".section .pdata,\"dr\"\n"
    ".balign 4\n"
    ".rva dispatch_0, .Lend, .Lunwind\n"
    ".text\n"
    ".att_syntax prefix\n"
);
#endif

#if PART == 1
/* Tail-transfer through the Guard CF dispatch pointer. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl dispatch_1\n"
    ".def dispatch_1; .scl 2; .type 32; .endef\n"
    "dispatch_1:\n"
    "jmp qword ptr [rip + rva_3ac20]\n"
    ".Lend:\n"
    ".section .xdata,\"dr\"\n"
    ".balign 4\n"
    ".Lunwind:\n"
    ".byte 1, 0, 0, 0\n"
    ".section .pdata,\"dr\"\n"
    ".balign 4\n"
    ".rva dispatch_1, .Lend, .Lunwind\n"
    ".text\n"
    ".att_syntax prefix\n"
);
#endif
