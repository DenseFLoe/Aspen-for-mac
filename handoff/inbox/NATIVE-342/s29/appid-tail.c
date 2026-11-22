/* Windows AMD64 APPID dispatch on the receiver supplied in entry RDX. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl apw_33a20\n"
    ".def apw_33a20; .scl 2; .type 32; .endef\n"
    "apw_33a20:\n"
    "    mov rax, qword ptr [rdx]\n"
    "    lea r8, [rip + rva_40e20]\n"
    "    .byte 0x48, 0x8b, 0xca     # mov rcx, rdx, original reg/rm form\n"
    "    lea rdx, [rip + rva_40e70]\n"
    "    .byte 0x48                 # original redundant REX.W on near jmp\n"
    "    jmp qword ptr [rax + 0x18]\n"
    ".att_syntax prefix\n"
);
