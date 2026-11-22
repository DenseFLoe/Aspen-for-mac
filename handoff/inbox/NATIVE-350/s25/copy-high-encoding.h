#pragma once
/* Retain near-branch widths while resolving destination labels in the assembler. */
#define STRING_I(x) #x
#define STRING(x) STRING_I(x)
#define LONG_JAE(dst) ".byte 0x0f, 0x83\n.long " STRING(dst) " - . - 4\n"
#define LONG_JGE(dst) ".byte 0x0f, 0x8d\n.long " STRING(dst) " - . - 4\n"
#define LONG_JL(dst) ".byte 0x0f, 0x8c\n.long " STRING(dst) " - . - 4\n"
#define LONG_JMP(dst) ".byte 0xe9\n.long " STRING(dst) " - . - 4\n"

/* Alignment encodings decode as NOP at their original widths. */
#define PAD_0F1F00 ".byte 0x0f, 0x1f, 0x00\n"
#define PAD_6666666666662E0F1F840000000000 ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00\n"
