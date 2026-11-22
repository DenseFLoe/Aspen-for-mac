#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0xccd0 through 0xcce3 (exclusive). */
__asm__(".globl rva_ccd0\n.set rva_ccd0, sub_1800CCD0\n");
NAKED void sub_1800CCD0(void) {
    __asm__(START
        "    mov rax, qword ptr [rip + data_rva_22d18]\n" /* 0ccd0 */
        "    test rax, rax\n" /* 0ccd7 */
        "    je sub_18000CCF0_rva_ccf0\n" /* 0ccda */
        ".byte 0x48\n        jmp rax\n" /* 0cce0 */
        END);
}
