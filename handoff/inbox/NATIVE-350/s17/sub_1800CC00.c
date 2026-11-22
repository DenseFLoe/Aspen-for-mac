#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0xcc00 through 0xcc13 (exclusive). */
__asm__(".globl rva_cc00\n.set rva_cc00, sub_1800CC00\n");
NAKED void sub_1800CC00(void) {
    __asm__(START
        "    mov rax, qword ptr [rip + data_rva_22d10]\n" /* 0cc00 */
        "    test rax, rax\n" /* 0cc07 */
        "    je sub_18000CC20_rva_cc20\n" /* 0cc0a */
        ".byte 0x48\n        jmp rax\n" /* 0cc10 */
        END);
}
