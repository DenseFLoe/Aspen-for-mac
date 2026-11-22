#include "register-forms.h"

/* DSWU_EUDL01: original AMD64 Windows entry RVA 0x2320. */
NAKED void DSWU_EUDL01(void) {
    __asm__(START
        ".Lblock_2320:\n"
        "sub rsp, 0x48\n"
        "mov rax, qword ptr [rcx]\n"
        "lea r10, [rax + 0x44b]\n"
        "cmp r10, 0x62\n"
        "ja .Lblock_234b\n"
        "add rax, 0x3e8\n"
        "mov qword ptr [rsp + 0x40], rax\n"
        "lea rcx, [rsp + 0x40]\n"
        "call rva_15388\n"
        "jmp .Lblock_2374\n"
        ".Lblock_234b:\n"
        "mov qword ptr [rsp + 0x30], r8\n"
        "mov qword ptr [rsp + 0x28], rdx\n"
        "mov qword ptr [rsp + 0x20], r9\n"
        "lea rdx, [rip + rva_1e440]\n"
        "lea r8, [rip + rva_1e3a0]\n"
        "lea r9, [rip + rva_19698]\n"
        "call rva_1538e\n"
        ".Lblock_2374:\n"
        "nop\n"
        "add rsp, 0x48\n"
        "ret\n"
        END);
}
