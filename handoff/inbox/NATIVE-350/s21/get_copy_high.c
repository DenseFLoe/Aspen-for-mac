/* zedstwu.dll, Windows AMD64. The labels and table entries may be edited and reassembled. */
#include "copy-encoding.h"

/* Return the selected implementation address in RAX without touching the arguments. */
__attribute__((naked,used)) void *get_copy_high(void) {
    __asm__(".intel_syntax noprefix\n"
        "lea rax, [rip + copy_high_rva_e5c0]\n" /* cbf0 */
        "ret\n" /* cbf7 */
        ".att_syntax prefix\n");
}
