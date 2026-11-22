#include "s5-registers.h"

/* 0xe040..0xf0f8, Windows AMD64. */
NAKED void internal_e040(void) {
    __asm__(START
        ".Ls5_e040:\n"
        "push rdi\n"
        "mov r10, rcx\n"
        "mov r11, rcx\n"
        "movabs rax, 0x101010101010101\n"
        "movzx r9, dl\n"
        "imul r9, rax\n"
        "lea rdx, [rip + rva_ece0]\n"
        "vmovq xmm0, r9\n"
        "cmp r8, 0x80\n"
        "ja .Ls5_e080\n"
        "mov rdi, r11\n"
        "add rdi, r8\n"
        "sub rdx, qword ptr [rdx + r8*8]\n"
        "notrack jmp rdx\n"
        ".byte 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e080:\n"
        "lea rdx, [rip + rva_e3e0]\n"
        "mov rcx, r11\n"
        "and rcx, 0x1f\n"
        "je .Ls5_e0b3\n"
        "neg rcx\n"
        "add rcx, 0x20\n"
        "sub r8, rcx\n"
        "mov rdi, r11\n"
        "add rdi, rcx\n"
        "sub rdx, qword ptr [rdx + rcx*8]\n"
        "notrack jmp rdx\n"
        ".byte 0x66, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        "add r11, rcx\n"
        ".Ls5_e0b3:\n"
        "cmp r8, 0x100\n"
        "jl rva_e1f0\n"
        "mov rcx, qword ptr [rip + rva_1e880]\n"
        "mov rdi, rcx\n"
        "shr rcx, 4\n"
        "sub rdi, rcx\n"
        "cmp r8, rdi\n"
        "jae .Ls5_e130\n"
        "vpbroadcastd ymm0, xmm0\n"
        ".Ls5_e0db:\n"
        "vmovdqa ymmword ptr [r11], ymm0\n"
        "vmovdqa ymmword ptr [r11 + 0x20], ymm0\n"
        "vmovdqa ymmword ptr [r11 + 0x40], ymm0\n"
        "vmovdqa ymmword ptr [r11 + 0x60], ymm0\n"
        "add r11, 0x100\n"
        "sub r8, 0x100\n"
        "vmovdqa ymmword ptr [r11 - 0x80], ymm0\n"
        "vmovdqa ymmword ptr [r11 - 0x60], ymm0\n"
        "vmovdqa ymmword ptr [r11 - 0x40], ymm0\n"
        "vmovdqa ymmword ptr [r11 - 0x20], ymm0\n"
        "cmp r8, 0x100\n"
        "jge .Ls5_e0db\n"
        "jmp rva_e200\n"
        ".byte 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e130:\n"
        "mov rdi, r11\n"
        "mov rax, r9\n"
        "mov rcx, r8\n"
        "cld\n"
        "rep stosb byte ptr [rdi], al\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e150:\n"
        "mov byte ptr [r11], r9b\n"
        ".Ls5_e153:\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e160:\n"
        "mov word ptr [r11], r9w\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x80, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e170:\n"
        "mov word ptr [r11], r9w\n"
        "mov byte ptr [r11 + 2], r9b\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x0 # alignment nop\n"
        ".Ls5_e180:\n"
        "mov dword ptr [r11], r9d\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e190:\n"
        "mov dword ptr [r11], r9d\n"
        "mov dword ptr [rdi - 4], r9d\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x40, 0x0 # alignment nop\n"
        ".Ls5_e1a0:\n"
        "mov qword ptr [r11], r9\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e1b0:\n"
        "mov qword ptr [r11], r9\n"
        "mov qword ptr [rdi - 8], r9\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x40, 0x0 # alignment nop\n"
        ".Ls5_e1c0:\n"
        "mov qword ptr [r11], r9\n"
        "mov qword ptr [r11 + 8], r9\n"
        "jmp rva_e0b0\n"
        ".byte 0xf, 0x1f, 0x40, 0x0 # alignment nop\n"
        ".Ls5_e1d0:\n"
        "mov qword ptr [r11], r9\n"
        "mov qword ptr [r11 + 8], r9\n"
        "mov qword ptr [rdi - 0x10], r9\n"
        "mov qword ptr [rdi - 8], r9\n"
        "jmp rva_e0b0\n"
        ".byte 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        "vpbroadcastd ymm0, xmm0\n"
        ".byte 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        "add r11, r8\n"
        "mov rdi, r11\n"
        "and r11, 0xffffffffffffffe0\n"
        "lea rdx, [rip + rva_e4e0]\n"
        "sub rdx, qword ptr [rdx + r8*8]\n"
        "notrack jmp rdx\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e220:\n"
        "vmovaps ymmword ptr [r11 - 0xe0], ymm0\n"
        ".Ls5_e229:\n"
        "vmovaps ymmword ptr [r11 - 0xc0], ymm0\n"
        ".Ls5_e232:\n"
        "vmovaps ymmword ptr [r11 - 0xa0], ymm0\n"
        ".byte 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e240:\n"
        "vmovaps ymmword ptr [r11 - 0x80], ymm0\n"
        ".Ls5_e246:\n"
        "vmovaps ymmword ptr [r11 - 0x60], ymm0\n"
        ".Ls5_e24c:\n"
        "vmovaps ymmword ptr [r11 - 0x40], ymm0\n"
        ".Ls5_e252:\n"
        "vmovaps ymmword ptr [r11 - 0x20], ymm0\n"
        "mov r8, rdi\n"
        "and r8, 0x1f\n"
        "lea rdx, [rip + rva_e4e0]\n"
        "sub rdx, qword ptr [rdx + r8*8]\n"
        "notrack jmp rdx\n"
        ".byte 0xf, 0x1f, 0x0 # alignment nop\n"
        ".Ls5_e270:\n"
        "mov byte ptr [r11], r9b\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e280:\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e290:\n"
        "mov word ptr [r11], r9w\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x80, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e2a0:\n"
        "mov word ptr [r11], r9w\n"
        "mov byte ptr [r11 + 2], r9b\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x0 # alignment nop\n"
        ".Ls5_e2b0:\n"
        "mov dword ptr [r11], r9d\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e2c0:\n"
        "mov dword ptr [r11], r9d\n"
        "mov dword ptr [rdi - 4], r9d\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x40, 0x0 # alignment nop\n"
        ".Ls5_e2d0:\n"
        "mov qword ptr [r11], r9\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e2e0:\n"
        "mov qword ptr [r11], r9\n"
        "mov qword ptr [rdi - 8], r9\n"
        "jmp rva_f0f0\n"
        ".byte 0xf, 0x1f, 0x40, 0x0 # alignment nop\n"
        ".Ls5_e2f0:\n"
        "vmovups xmmword ptr [r11], xmm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0xf, 0x1f, 0x44, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e300:\n"
        "vmovups xmmword ptr [r11], xmm0\n"
        "vmovups xmmword ptr [rdi - 0x10], xmm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x90 # alignment nop\n"
        ".Ls5_e310:\n"
        "vpbroadcastd ymm0, xmm0\n"
        "vmovups ymmword ptr [r11], ymm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x90 # alignment nop\n"
        ".Ls5_e320:\n"
        "vpbroadcastd ymm0, xmm0\n"
        "vmovups ymmword ptr [r11], ymm0\n"
        "vmovups ymmword ptr [rdi - 0x20], ymm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e340:\n"
        "vpbroadcastd ymm0, xmm0\n"
        "vmovups ymmword ptr [r11], ymm0\n"
        "vmovups ymmword ptr [r11 + 0x20], ymm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e360:\n"
        "vpbroadcastd ymm0, xmm0\n"
        "vmovups ymmword ptr [r11], ymm0\n"
        "vmovups ymmword ptr [r11 + 0x20], ymm0\n"
        "vmovups ymmword ptr [rdi - 0x20], ymm0\n"
        "vmovups ymmword ptr [rdi - 0x40], ymm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x90 # alignment nop\n"
        ".Ls5_e380:\n"
        "vpbroadcastd ymm0, xmm0\n"
        "vmovups ymmword ptr [r11], ymm0\n"
        "vmovups ymmword ptr [r11 + 0x20], ymm0\n"
        "vmovups ymmword ptr [r11 + 0x40], ymm0\n"
        "vmovups ymmword ptr [r11 + 0x60], ymm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_e3b0:\n"
        "punpcklqdq xmm0, xmm0\n"
        "vmovups xmmword ptr [r11], xmm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x90 # alignment nop\n"
        ".Ls5_e3c0:\n"
        "punpcklqdq xmm0, xmm0\n"
        "vmovups xmmword ptr [r11], xmm0\n"
        "vmovups xmmword ptr [rdi - 0x10], xmm0\n"
        "jmp rva_f0f0\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_table_e3e0:\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e153\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e150\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e160\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e170\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e180\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e190\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e190\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e190\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1a0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1b0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1c0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".quad .Ls5_table_e3e0 - .Ls5_e1d0\n"
        ".Ls5_table_e4e0:\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e280\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e270\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e290\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2a0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2b0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2c0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2c0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2c0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2d0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e2f0\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e300\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e252\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e24c\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e246\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e240\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e232\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e229\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".quad .Ls5_table_e4e0 - .Ls5_e220\n"
        ".Ls5_table_ece0:\n"
        ".quad .Ls5_table_ece0 - .Ls5_e280\n"
        ".quad .Ls5_table_ece0 - .Ls5_e270\n"
        ".quad .Ls5_table_ece0 - .Ls5_e290\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2a0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2b0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2d0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e2e0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3b0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e3c0\n"
        ".quad .Ls5_table_ece0 - .Ls5_e310\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e320\n"
        ".quad .Ls5_table_ece0 - .Ls5_e340\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e360\n"
        ".quad .Ls5_table_ece0 - .Ls5_e380\n"
        ".quad 0x960\n" /* Adjacent word after the 129-entry bounded table. */
        "vzeroupper\n"
        "mov rax, r10\n"
        "pop rdi\n"
        "ret\n" END);
}

/* 0xf100..0x109c1, Windows AMD64. */
NAKED void internal_f100(void) {
    __asm__(START
        ".Ls5_f100:\n"
        "mov rax, rcx\n"
        "movabs r10, 0x101010101010101\n"
        "movzx r9, dl\n"
        "imul r9, r10\n"
        "lea rdx, [rip + rva_105c0]\n"
        "vpbroadcastd zmm0, r9d\n"
        "cmp r8, 0x80\n"
        "jge .Ls5_f137\n"
        "mov r10, rcx\n"
        "add r10, r8\n"
        "sub rdx, qword ptr [rdx + r8*8]\n"
        "jmp rdx\n"
        ".Ls5_f137:\n"
        "lea rdx, [rip + rva_f3c0]\n"
        "mov r11, rcx\n"
        "neg r11\n"
        "add r11, 0x40\n"
        "and r11, 0x3f\n"
        "je .Ls5_f160\n"
        "sub r8, r11\n"
        "mov r10, rcx\n"
        "add r10, r11\n"
        "sub rdx, qword ptr [rdx + r11*8]\n"
        "jmp rdx\n"
        "add rcx, r11\n"
        ".Ls5_f160:\n"
        "cmp r8, 0x200\n"
        "jl rva_f292\n"
        "cmp r8, qword ptr [rip + rva_1e890]\n"
        "jae .Ls5_f1c9\n"
        ".Ls5_f176:\n"
        "vmovaps zmmword ptr [rcx], zmm0\n"
        "vmovaps zmmword ptr [rcx + 0x40], zmm0\n"
        "vmovaps zmmword ptr [rcx + 0x80], zmm0\n"
        "vmovaps zmmword ptr [rcx + 0xc0], zmm0\n"
        "lea rcx, [rcx + 0x200]\n"
        "sub r8, 0x200\n"
        "vmovaps zmmword ptr [rcx - 0x100], zmm0\n"
        "vmovaps zmmword ptr [rcx - 0xc0], zmm0\n"
        "vmovaps zmmword ptr [rcx - 0x80], zmm0\n"
        "vmovaps zmmword ptr [rcx - 0x40], zmm0\n"
        "cmp r8, 0x200\n"
        "jge .Ls5_f176\n"
        "jmp rva_f292\n"
        ".Ls5_f1c9:\n"
        "vmovntdq zmmword ptr [rcx], zmm0\n"
        "vmovntdq zmmword ptr [rcx + 0x40], zmm0\n"
        "vmovntdq zmmword ptr [rcx + 0x80], zmm0\n"
        "vmovntdq zmmword ptr [rcx + 0xc0], zmm0\n"
        "lea rcx, [rcx + 0x200]\n"
        "sub r8, 0x200\n"
        "vmovntdq zmmword ptr [rcx - 0x100], zmm0\n"
        "vmovntdq zmmword ptr [rcx - 0xc0], zmm0\n"
        "vmovntdq zmmword ptr [rcx - 0x80], zmm0\n"
        "vmovntdq zmmword ptr [rcx - 0x40], zmm0\n"
        "cmp r8, 0x200\n"
        "jge .Ls5_f1c9\n"
        "sfence\n"
        "jmp .Ls5_f292\n"
        ".Ls5_f21c:\n"
        "mov byte ptr [rcx], r9b\n"
        ".Ls5_f21f:\n"
        "jmp rva_f15d\n"
        ".Ls5_f224:\n"
        "mov word ptr [rcx], r9w\n"
        "jmp rva_f15d\n"
        ".Ls5_f22d:\n"
        "mov word ptr [rcx], r9w\n"
        "mov byte ptr [rcx + 2], r9b\n"
        "jmp rva_f15d\n"
        ".Ls5_f23a:\n"
        "mov dword ptr [rcx], r9d\n"
        "jmp rva_f15d\n"
        ".Ls5_f242:\n"
        "mov dword ptr [rcx], r9d\n"
        "mov dword ptr [r10 - 4], r9d\n"
        "jmp rva_f15d\n"
        ".Ls5_f24e:\n"
        "mov qword ptr [rcx], r9\n"
        "jmp rva_f15d\n"
        ".Ls5_f256:\n"
        "mov qword ptr [rcx], r9\n"
        "mov qword ptr [r10 - 8], r9\n"
        "jmp rva_f15d\n"
        ".Ls5_f262:\n"
        "vmovups xmmword ptr [rcx], xmm0\n"
        "jmp rva_f15d\n"
        ".Ls5_f26b:\n"
        "vmovups xmmword ptr [rcx], xmm0\n"
        "vmovups xmmword ptr [r10 - 0x10], xmm0\n"
        "jmp rva_f15d\n"
        ".Ls5_f27a:\n"
        "vmovups ymmword ptr [rcx], ymm0\n"
        "jmp rva_f15d\n"
        ".Ls5_f283:\n"
        "vmovups ymmword ptr [rcx], ymm0\n"
        "vmovups ymmword ptr [r10 - 0x20], ymm0\n"
        "jmp rva_f15d\n"
        ".Ls5_f292:\n"
        "mov r10, rcx\n"
        "add r10, r8\n"
        "add rcx, r8\n"
        "and rcx, 0xffffffffffffffc0\n"
        "lea rdx, [rip + rva_f5c0]\n"
        "sub rdx, qword ptr [rdx + r8*8]\n"
        "jmp rdx\n"
        ".Ls5_f2ac:\n"
        "vmovaps zmmword ptr [rcx - 0x1c0], zmm0\n"
        ".Ls5_f2b3:\n"
        "vmovaps zmmword ptr [rcx - 0x180], zmm0\n"
        ".Ls5_f2ba:\n"
        "vmovaps zmmword ptr [rcx - 0x140], zmm0\n"
        ".Ls5_f2c1:\n"
        "vmovaps zmmword ptr [rcx - 0x100], zmm0\n"
        ".Ls5_f2c8:\n"
        "vmovaps zmmword ptr [rcx - 0xc0], zmm0\n"
        ".Ls5_f2cf:\n"
        "vmovaps zmmword ptr [rcx - 0x80], zmm0\n"
        ".Ls5_f2d6:\n"
        "vmovaps zmmword ptr [rcx - 0x40], zmm0\n"
        "mov r8, r10\n"
        "and r8, 0x3f\n"
        "lea rdx, [rip + rva_f5c0]\n"
        "sub rdx, qword ptr [rdx + r8*8]\n"
        "jmp rdx\n"
        ".Ls5_f2f1:\n"
        "mov byte ptr [rcx], r9b\n"
        "jmp rva_109c0\n"
        ".Ls5_f2f9:\n"
        "jmp rva_109c0\n"
        ".Ls5_f2fe:\n"
        "mov word ptr [rcx], r9w\n"
        "jmp rva_109c0\n"
        ".Ls5_f307:\n"
        "mov word ptr [rcx], r9w\n"
        "mov byte ptr [rcx + 2], r9b\n"
        "jmp rva_109c0\n"
        ".Ls5_f314:\n"
        "mov dword ptr [rcx], r9d\n"
        "jmp rva_109c0\n"
        ".Ls5_f31c:\n"
        "mov dword ptr [rcx], r9d\n"
        "mov dword ptr [r10 - 4], r9d\n"
        "jmp rva_109c0\n"
        ".Ls5_f328:\n"
        "mov qword ptr [rcx], r9\n"
        "jmp rva_109c0\n"
        ".Ls5_f330:\n"
        "mov qword ptr [rcx], r9\n"
        "mov qword ptr [r10 - 8], r9\n"
        "jmp rva_109c0\n"
        ".Ls5_f33c:\n"
        "vmovups xmmword ptr [rcx], xmm0\n"
        "jmp rva_109c0\n"
        ".Ls5_f345:\n"
        "vmovups xmmword ptr [rcx], xmm0\n"
        "vmovups xmmword ptr [r10 - 0x10], xmm0\n"
        "jmp rva_109c0\n"
        ".Ls5_f354:\n"
        "vmovups ymmword ptr [rcx], ymm0\n"
        "jmp rva_109c0\n"
        ".Ls5_f35d:\n"
        "vmovups ymmword ptr [rcx], ymm0\n"
        "vmovups ymmword ptr [r10 - 0x20], ymm0\n"
        "jmp rva_109c0\n"
        ".Ls5_f36c:\n"
        "vmovups zmmword ptr [rcx], zmm0\n"
        "jmp rva_109c0\n"
        ".Ls5_f377:\n"
        "vmovups zmmword ptr [rcx], zmm0\n"
        "vmovups zmmword ptr [r10 - 0x40], zmm0\n"
        "jmp rva_109c0\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".byte 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".byte 0x66, 0x2e, 0xf, 0x1f, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0 # alignment nop\n"
        ".Ls5_table_f3c0:\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f21f\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f21c\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f224\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f22d\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f23a\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f242\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f242\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f242\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f24e\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f256\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f262\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f26b\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f27a\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".quad .Ls5_table_f3c0 - .Ls5_f283\n"
        ".Ls5_table_f5c0:\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2f9\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2f1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2fe\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f307\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f314\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f31c\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f31c\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f31c\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f328\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f330\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f33c\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f345\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f354\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2d6\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2cf\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c8\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2c1\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ba\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2b3\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".quad .Ls5_table_f5c0 - .Ls5_f2ac\n"
        ".Ls5_table_105c0:\n"
        ".quad .Ls5_table_105c0 - .Ls5_f2f9\n"
        ".quad .Ls5_table_105c0 - .Ls5_f2f1\n"
        ".quad .Ls5_table_105c0 - .Ls5_f2fe\n"
        ".quad .Ls5_table_105c0 - .Ls5_f307\n"
        ".quad .Ls5_table_105c0 - .Ls5_f314\n"
        ".quad .Ls5_table_105c0 - .Ls5_f31c\n"
        ".quad .Ls5_table_105c0 - .Ls5_f31c\n"
        ".quad .Ls5_table_105c0 - .Ls5_f31c\n"
        ".quad .Ls5_table_105c0 - .Ls5_f328\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f330\n"
        ".quad .Ls5_table_105c0 - .Ls5_f33c\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f345\n"
        ".quad .Ls5_table_105c0 - .Ls5_f354\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f35d\n"
        ".quad .Ls5_table_105c0 - .Ls5_f36c\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        ".quad .Ls5_table_105c0 - .Ls5_f377\n"
        "ret\n" END);
}

/* 0x1135a..0x11360, Windows AMD64. */
NAKED void internal_1135a(void) {
    __asm__(START
        ".Ls5_1135a:\n"
        "jmp qword ptr [rip + rva_15500]\n" END);
}

/* 0x11360..0x11366, Windows AMD64. */
NAKED void internal_11360(void) {
    __asm__(START
        ".Ls5_11360:\n"
        "jmp qword ptr [rip + rva_154f8]\n" END);
}

/* 0x11366..0x1136c, Windows AMD64. */
NAKED void internal_11366(void) {
    __asm__(START
        ".Ls5_11366:\n"
        "jmp qword ptr [rip + rva_154f0]\n" END);
}

/* 0x1136c..0x11372, Windows AMD64. */
NAKED void internal_1136c(void) {
    __asm__(START
        ".Ls5_1136c:\n"
        "jmp qword ptr [rip + rva_154e8]\n" END);
}

/* 0x11372..0x11378, Windows AMD64. */
NAKED void internal_11372(void) {
    __asm__(START
        ".Ls5_11372:\n"
        "jmp qword ptr [rip + rva_154e0]\n" END);
}

/* 0x11378..0x1137e, Windows AMD64. */
NAKED void internal_11378(void) {
    __asm__(START
        ".Ls5_11378:\n"
        "jmp qword ptr [rip + rva_154d8]\n" END);
}

/* 0x1137e..0x11384, Windows AMD64. */
NAKED void internal_1137e(void) {
    __asm__(START
        ".Ls5_1137e:\n"
        "jmp qword ptr [rip + rva_154d0]\n" END);
}

/* 0x11384..0x1138a, Windows AMD64. */
NAKED void internal_11384(void) {
    __asm__(START
        ".Ls5_11384:\n"
        "jmp qword ptr [rip + rva_154c8]\n" END);
}

/* 0x11396..0x1139c, Windows AMD64. */
NAKED void internal_11396(void) {
    __asm__(START
        ".Ls5_11396:\n"
        "jmp qword ptr [rip + rva_154b0]\n" END);
}

/* 0x1139c..0x113a2, Windows AMD64. */
NAKED void internal_1139c(void) {
    __asm__(START
        ".Ls5_1139c:\n"
        "jmp qword ptr [rip + rva_154a8]\n" END);
}

/* 0x113a2..0x113a8, Windows AMD64. */
NAKED void internal_113a2(void) {
    __asm__(START
        ".Ls5_113a2:\n"
        "jmp qword ptr [rip + rva_154a0]\n" END);
}

/* 0x113ae..0x113b4, Windows AMD64. */
NAKED void internal_113ae(void) {
    __asm__(START
        ".Ls5_113ae:\n"
        "jmp qword ptr [rip + rva_15490]\n" END);
}

/* 0x113cc..0x113d2, Windows AMD64. */
NAKED void internal_113cc(void) {
    __asm__(START
        ".Ls5_113cc:\n"
        "jmp qword ptr [rip + rva_15468]\n" END);
}

/* 0x113d2..0x113d8, Windows AMD64. */
NAKED void internal_113d2(void) {
    __asm__(START
        ".Ls5_113d2:\n"
        "jmp qword ptr [rip + rva_15460]\n" END);
}

/* 0x113de..0x113e4, Windows AMD64. */
NAKED void internal_113de(void) {
    __asm__(START
        ".Ls5_113de:\n"
        "jmp qword ptr [rip + rva_15450]\n" END);
}

/* 0x113ea..0x113f0, Windows AMD64. */
NAKED void internal_113ea(void) {
    __asm__(START
        ".Ls5_113ea:\n"
        "jmp qword ptr [rip + rva_15440]\n" END);
}

/* 0x113f6..0x113fc, Windows AMD64. */
NAKED void internal_113f6(void) {
    __asm__(START
        ".Ls5_113f6:\n"
        "jmp qword ptr [rip + rva_15430]\n" END);
}

/* 0x11414..0x1141a, Windows AMD64. */
NAKED void internal_11414(void) {
    __asm__(START
        ".Ls5_11414:\n"
        "jmp qword ptr [rip + rva_15408]\n" END);
}

/* 0x1141a..0x11420, Windows AMD64. */
NAKED void internal_1141a(void) {
    __asm__(START
        ".Ls5_1141a:\n"
        "jmp qword ptr [rip + rva_15400]\n" END);
}

/* 0x11420..0x11426, Windows AMD64. */
NAKED void internal_11420(void) {
    __asm__(START
        ".Ls5_11420:\n"
        "jmp qword ptr [rip + rva_153f8]\n" END);
}

/* 0x11426..0x1142c, Windows AMD64. */
NAKED void internal_11426(void) {
    __asm__(START
        ".Ls5_11426:\n"
        "jmp qword ptr [rip + rva_153f0]\n" END);
}

/* 0x11444..0x1144a, Windows AMD64. */
NAKED void internal_11444(void) {
    __asm__(START
        ".Ls5_11444:\n"
        "jmp qword ptr [rip + rva_153c8]\n" END);
}

/* 0x11456..0x1145c, Windows AMD64. */
NAKED void internal_11456(void) {
    __asm__(START
        ".Ls5_11456:\n"
        "jmp qword ptr [rip + rva_15370]\n" END);
}

/* 0x1145c..0x11462, Windows AMD64. */
NAKED void internal_1145c(void) {
    __asm__(START
        ".Ls5_1145c:\n"
        "jmp qword ptr [rip + rva_15298]\n" END);
}

/* 0x1147a..0x11480, Windows AMD64. */
NAKED void internal_1147a(void) {
    __asm__(START
        ".Ls5_1147a:\n"
        "jmp qword ptr [rip + rva_15390]\n" END);
}

/* 0x11480..0x11486, Windows AMD64. */
NAKED void internal_11480(void) {
    __asm__(START
        ".Ls5_11480:\n"
        "jmp qword ptr [rip + rva_15380]\n" END);
}

/* 0x11486..0x1148c, Windows AMD64. */
NAKED void internal_11486(void) {
    __asm__(START
        ".Ls5_11486:\n"
        "jmp qword ptr [rip + rva_152a0]\n" END);
}

/* 0x1149e..0x114a4, Windows AMD64. */
NAKED void internal_1149e(void) {
    __asm__(START
        ".Ls5_1149e:\n"
        "jmp qword ptr [rip + rva_151d8]\n" END);
}

/* 0x114bc..0x114c2, Windows AMD64. */
NAKED void internal_114bc(void) {
    __asm__(START
        ".Ls5_114bc:\n"
        "jmp qword ptr [rip + rva_15200]\n" END);
}

/* 0x114ce..0x114d4, Windows AMD64. */
NAKED void internal_114ce(void) {
    __asm__(START
        ".Ls5_114ce:\n"
        "jmp qword ptr [rip + rva_15218]\n" END);
}

/* 0x114d4..0x114da, Windows AMD64. */
NAKED void internal_114d4(void) {
    __asm__(START
        ".Ls5_114d4:\n"
        "jmp qword ptr [rip + rva_15220]\n" END);
}

/* 0x114da..0x114e0, Windows AMD64. */
NAKED void internal_114da(void) {
    __asm__(START
        ".Ls5_114da:\n"
        "jmp qword ptr [rip + rva_15228]\n" END);
}

/* 0x114e6..0x114ec, Windows AMD64. */
NAKED void internal_114e6(void) {
    __asm__(START
        ".Ls5_114e6:\n"
        "jmp qword ptr [rip + rva_15238]\n" END);
}

/* 0x114ec..0x114f2, Windows AMD64. */
NAKED void internal_114ec(void) {
    __asm__(START
        ".Ls5_114ec:\n"
        "jmp qword ptr [rip + rva_15240]\n" END);
}

/* 0x114fe..0x11504, Windows AMD64. */
NAKED void internal_114fe(void) {
    __asm__(START
        ".Ls5_114fe:\n"
        "jmp qword ptr [rip + rva_15258]\n" END);
}

/* 0x11504..0x1150a, Windows AMD64. */
NAKED void internal_11504(void) {
    __asm__(START
        ".Ls5_11504:\n"
        "jmp qword ptr [rip + rva_15260]\n" END);
}

/* 0x11516..0x1151c, Windows AMD64. */
NAKED void internal_11516(void) {
    __asm__(START
        ".Ls5_11516:\n"
        "jmp qword ptr [rip + rva_15278]\n" END);
}

/* 0x11552..0x11558, Windows AMD64. */
NAKED void internal_11552(void) {
    __asm__(START
        ".Ls5_11552:\n"
        "jmp qword ptr [rip + rva_152c8]\n" END);
}

/* 0x11558..0x1155e, Windows AMD64. */
NAKED void internal_11558(void) {
    __asm__(START
        ".Ls5_11558:\n"
        "jmp qword ptr [rip + rva_152d0]\n" END);
}

/* 0x11564..0x1156a, Windows AMD64. */
NAKED void internal_11564(void) {
    __asm__(START
        ".Ls5_11564:\n"
        "jmp qword ptr [rip + rva_152e0]\n" END);
}

/* 0x11576..0x1157c, Windows AMD64. */
NAKED void internal_11576(void) {
    __asm__(START
        ".Ls5_11576:\n"
        "jmp qword ptr [rip + rva_152f8]\n" END);
}

/* 0x1158e..0x11594, Windows AMD64. */
NAKED void internal_1158e(void) {
    __asm__(START
        ".Ls5_1158e:\n"
        "jmp qword ptr [rip + rva_15318]\n" END);
}

/* 0x115ac..0x115b2, Windows AMD64. */
NAKED void internal_115ac(void) {
    __asm__(START
        ".Ls5_115ac:\n"
        "jmp qword ptr [rip + rva_15340]\n" END);
}

/* 0x115d6..0x115dc, Windows AMD64. */
NAKED void internal_115d6(void) {
    __asm__(START
        ".Ls5_115d6:\n"
        "jmp qword ptr [rip + rva_15cc0]\n" END);
}

/* 0x115dc..0x115e2, Windows AMD64. */
NAKED void internal_115dc(void) {
    __asm__(START
        ".Ls5_115dc:\n"
        "jmp qword ptr [rip + rva_15c98]\n" END);
}

/* 0x115e8..0x115ee, Windows AMD64. */
NAKED void internal_115e8(void) {
    __asm__(START
        ".Ls5_115e8:\n"
        "jmp qword ptr [rip + rva_15cb0]\n" END);
}

/* 0x115fa..0x11600, Windows AMD64. */
NAKED void internal_115fa(void) {
    __asm__(START
        ".Ls5_115fa:\n"
        "jmp qword ptr [rip + rva_15c80]\n" END);
}

/* 0x11606..0x1160c, Windows AMD64. */
NAKED void internal_11606(void) {
    __asm__(START
        ".Ls5_11606:\n"
        "jmp qword ptr [rip + rva_15c28]\n" END);
}

/* 0x1160c..0x11612, Windows AMD64. */
NAKED void internal_1160c(void) {
    __asm__(START
        ".Ls5_1160c:\n"
        "jmp qword ptr [rip + rva_15c30]\n" END);
}

/* 0x11612..0x11618, Windows AMD64. */
NAKED void internal_11612(void) {
    __asm__(START
        ".Ls5_11612:\n"
        "jmp qword ptr [rip + rva_15c38]\n" END);
}

/* 0x11618..0x1161e, Windows AMD64. */
NAKED void internal_11618(void) {
    __asm__(START
        ".Ls5_11618:\n"
        "jmp qword ptr [rip + rva_15c60]\n" END);
}

/* 0x1161e..0x11624, Windows AMD64. */
NAKED void internal_1161e(void) {
    __asm__(START
        ".Ls5_1161e:\n"
        "jmp qword ptr [rip + rva_15c58]\n" END);
}

/* 0x11624..0x1162a, Windows AMD64. */
NAKED void internal_11624(void) {
    __asm__(START
        ".Ls5_11624:\n"
        "jmp qword ptr [rip + rva_15c50]\n" END);
}

/* 0x1162a..0x11630, Windows AMD64. */
NAKED void internal_1162a(void) {
    __asm__(START
        ".Ls5_1162a:\n"
        "jmp qword ptr [rip + rva_15c48]\n" END);
}

/* 0x11630..0x11636, Windows AMD64. */
NAKED void internal_11630(void) {
    __asm__(START
        ".Ls5_11630:\n"
        "jmp qword ptr [rip + rva_15c40]\n" END);
}

/* 0x11636..0x1163c, Windows AMD64. */
NAKED void internal_11636(void) {
    __asm__(START
        ".Ls5_11636:\n"
        "jmp qword ptr [rip + rva_15610]\n" END);
}

/* 0x1163c..0x11642, Windows AMD64. */
NAKED void internal_1163c(void) {
    __asm__(START
        ".Ls5_1163c:\n"
        "jmp qword ptr [rip + rva_15608]\n" END);
}

/* 0x1167e..0x11684, Windows AMD64. */
NAKED void internal_1167e(void) {
    __asm__(START
        ".Ls5_1167e:\n"
        "jmp qword ptr [rip + rva_155b0]\n" END);
}

/* 0x11684..0x1168a, Windows AMD64. */
NAKED void internal_11684(void) {
    __asm__(START
        ".Ls5_11684:\n"
        "jmp qword ptr [rip + rva_15618]\n" END);
}

/* 0x1168a..0x11690, Windows AMD64. */
NAKED void internal_1168a(void) {
    __asm__(START
        ".Ls5_1168a:\n"
        "jmp qword ptr [rip + rva_15598]\n" END);
}

/* 0x116ae..0x116b4, Windows AMD64. */
NAKED void internal_116ae(void) {
    __asm__(START
        ".Ls5_116ae:\n"
        "jmp qword ptr [rip + rva_15878]\n" END);
}

/* 0x116b4..0x116ba, Windows AMD64. */
NAKED void internal_116b4(void) {
    __asm__(START
        ".Ls5_116b4:\n"
        "jmp qword ptr [rip + rva_15870]\n" END);
}

/* 0x11aaa..0x11ab0, Windows AMD64. */
NAKED void internal_11aaa(void) {
    __asm__(START
        ".Ls5_11aaa:\n"
        "jmp qword ptr [rip + rva_15918]\n" END);
}

/* 0x11b24..0x11b74, Windows AMD64. */
NAKED void internal_11b24(void) {
    __asm__(START
        ".Ls5_11b24:\n"
        "sub rsp, 0x28\n"
        "test edx, edx\n"
        "je .Ls5_11b65\n"
        "sub edx, 1\n"
        "je .Ls5_11b59\n"
        "sub edx, 1\n"
        "je .Ls5_11b4c\n"
        "cmp edx, 1\n"
        "je .Ls5_11b45\n"
        "mov eax, 1\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".Ls5_11b45:\n"
        "call rva_12170\n"
        "jmp .Ls5_11b51\n"
        ".Ls5_11b4c:\n"
        "call rva_12148\n"
        ".Ls5_11b51:\n"
        "movzx eax, al\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".Ls5_11b59:\n"
        S5_MOV64(rdx, r8)
        "add rsp, 0x28\n"
        "jmp rva_11b74\n"
        ".Ls5_11b65:\n"
        "test r8, r8\n"
        "setne cl\n"
        "add rsp, 0x28\n"
        "jmp rva_11c8c\n" END);
}

/* 0x11b74..0x11c8a, Windows AMD64. */
NAKED void internal_11b74(void) {
    __asm__(START
        ".Ls5_11b74:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "mov qword ptr [rsp + 0x20], rdi\n"
        "push r14\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rsi, rdx)
        S5_MOV64(r14, rcx)
        S5_XOR32(ecx, ecx)
        "call rva_1222c\n"
        "test al, al\n"
        "je rva_11c66\n"
        "call rva_120c0\n"
        S5_MOV8(bl, al)
        "mov byte ptr [rsp + 0x40], al\n"
        "mov dil, 1\n"
        "cmp dword ptr [rip + rva_20a30], 0\n"
        "jne rva_11c7e\n"
        "mov dword ptr [rip + rva_20a30], 1\n"
        "call rva_12130\n"
        "test al, al\n"
        "je .Ls5_11c1b\n"
        "call rva_126b4\n"
        "call rva_11fd4\n"
        "call rva_12000\n"
        "lea rdx, [rip + rva_15d48]\n"
        "lea rcx, [rip + rva_15d40]\n"
        "call rva_147a6\n"
        "test eax, eax\n"
        "jne .Ls5_11c1b\n"
        "call rva_120fc\n"
        "test al, al\n"
        "je .Ls5_11c1b\n"
        "lea rdx, [rip + rva_15d38]\n"
        "lea rcx, [rip + rva_15d28]\n"
        "call rva_147a0\n"
        "mov dword ptr [rip + rva_20a30], 2\n"
        S5_XOR8(dil, dil)
        ".Ls5_11c1b:\n"
        S5_MOV8(cl, bl)
        "call rva_1238c\n"
        "test dil, dil\n"
        "jne .Ls5_11c66\n"
        "call rva_12450\n"
        S5_MOV64(rbx, rax)
        "cmp qword ptr [rax], 0\n"
        "je .Ls5_11c59\n"
        S5_MOV64(rcx, rax)
        "call rva_122f4\n"
        "test al, al\n"
        "je .Ls5_11c59\n"
        S5_MOV64(r8, rsi)
        "mov edx, 2\n"
        S5_MOV64(rcx, r14)
        "mov rax, qword ptr [rbx]\n"
        "mov r9, qword ptr [rip + rva_15d00]\n"
        "call r9\n"
        ".Ls5_11c59:\n"
        "inc dword ptr [rip + rva_20a00]\n"
        "mov eax, 1\n"
        "jmp .Ls5_11c68\n"
        ".Ls5_11c66:\n"
        S5_XOR32(eax, eax)
        ".Ls5_11c68:\n"
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "mov rdi, qword ptr [rsp + 0x48]\n"
        "add rsp, 0x20\n"
        "pop r14\n"
        "ret\n"
        "mov ecx, 7\n"
        "call rva_12460\n"
        ".byte 0x90 # alignment nop\n"
        "int3\n" END);
}

/* 0x11c8c..0x11d0c, Windows AMD64. */
NAKED void internal_11c8c(void) {
    __asm__(START
        ".Ls5_11c8c:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "push rdi\n"
        "sub rsp, 0x30\n"
        S5_MOV8(dil, cl)
        "mov eax, dword ptr [rip + rva_20a00]\n"
        "test eax, eax\n"
        "jg .Ls5_11cb0\n"
        S5_XOR32(eax, eax)
        ".Ls5_11ca5:\n"
        "mov rbx, qword ptr [rsp + 0x40]\n"
        "add rsp, 0x30\n"
        "pop rdi\n"
        "ret\n"
        ".Ls5_11cb0:\n"
        "dec eax\n"
        "mov dword ptr [rip + rva_20a00], eax\n"
        "call rva_120c0\n"
        S5_MOV8(bl, al)
        "mov byte ptr [rsp + 0x20], al\n"
        "cmp dword ptr [rip + rva_20a30], 2\n"
        "jne .Ls5_11cff\n"
        "call rva_121e8\n"
        "call rva_11fe4\n"
        "call rva_126f0\n"
        "and dword ptr [rip + rva_20a30], 0\n"
        S5_MOV8(cl, bl)
        "call rva_1238c\n"
        S5_XOR32(edx, edx)
        S5_MOV8(cl, dil)
        "call rva_123b0\n"
        "movzx ebx, al\n"
        "call rva_12218\n"
        S5_MOV32(eax, ebx)
        "jmp .Ls5_11ca5\n"
        ".Ls5_11cff:\n"
        "mov ecx, 7\n"
        "call rva_12460\n"
        ".byte 0x90 # alignment nop\n"
        ".byte 0x90 # alignment nop\n"
        "int3\n" END);
}

/* 0x11d0c..0x11e34, Windows AMD64. */
NAKED void internal_11d0c(void) {
    __asm__(START
        ".Ls5_11d0c:\n"
        S5_MOV64(rax, rsp)
        "mov qword ptr [rax + 0x20], rbx\n"
        "mov qword ptr [rax + 0x18], r8\n"
        "mov dword ptr [rax + 0x10], edx\n"
        "mov qword ptr [rax + 8], rcx\n"
        "push rsi\n"
        "push rdi\n"
        "push r14\n"
        "sub rsp, 0x40\n"
        S5_MOV64(rsi, r8)
        S5_MOV32(edi, edx)
        S5_MOV64(r14, rcx)
        "test edx, edx\n"
        "jne .Ls5_11d41\n"
        "cmp dword ptr [rip + rva_20a00], edx\n"
        "jg .Ls5_11d41\n"
        S5_XOR32(eax, eax)
        "jmp rva_11e26\n"
        ".Ls5_11d41:\n"
        "lea eax, [rdx - 1]\n"
        "cmp eax, 1\n"
        "ja .Ls5_11d89\n"
        "mov rax, qword ptr [rip + rva_17c58]\n"
        "test rax, rax\n"
        "jne .Ls5_11d5a\n"
        "lea ebx, [rax + 1]\n"
        "jmp .Ls5_11d62\n"
        ".Ls5_11d5a:\n"
        "call qword ptr [rip + rva_15d00]\n"
        S5_MOV32(ebx, eax)
        ".Ls5_11d62:\n"
        "mov dword ptr [rsp + 0x30], ebx\n"
        "test ebx, ebx\n"
        "je rva_11e1c\n"
        S5_MOV64(r8, rsi)
        S5_MOV32(edx, edi)
        S5_MOV64(rcx, r14)
        "call rva_11b24\n"
        S5_MOV32(ebx, eax)
        "mov dword ptr [rsp + 0x30], eax\n"
        "test eax, eax\n"
        "je rva_11e1c\n"
        ".Ls5_11d89:\n"
        S5_MOV64(r8, rsi)
        S5_MOV32(edx, edi)
        S5_MOV64(rcx, r14)
        "call rva_11fb0\n"
        S5_MOV32(ebx, eax)
        "mov dword ptr [rsp + 0x30], eax\n"
        "cmp edi, 1\n"
        "jne .Ls5_11dd7\n"
        "test eax, eax\n"
        "jne .Ls5_11dd7\n"
        S5_MOV64(r8, rsi)
        S5_XOR32(edx, edx)
        S5_MOV64(rcx, r14)
        "call rva_11fb0\n"
        "test rsi, rsi\n"
        "setne cl\n"
        "call rva_11c8c\n"
        "mov rax, qword ptr [rip + rva_17c58]\n"
        "test rax, rax\n"
        "je .Ls5_11dd7\n"
        S5_MOV64(r8, rsi)
        S5_XOR32(edx, edx)
        S5_MOV64(rcx, r14)
        "call qword ptr [rip + rva_15d00]\n"
        ".Ls5_11dd7:\n"
        "test edi, edi\n"
        "je .Ls5_11de0\n"
        "cmp edi, 3\n"
        "jne .Ls5_11e1c\n"
        ".Ls5_11de0:\n"
        S5_MOV64(r8, rsi)
        S5_MOV32(edx, edi)
        S5_MOV64(rcx, r14)
        "call rva_11b24\n"
        S5_MOV32(ebx, eax)
        "mov dword ptr [rsp + 0x30], eax\n"
        "test eax, eax\n"
        "je .Ls5_11e1c\n"
        "mov rax, qword ptr [rip + rva_17c58]\n"
        "test rax, rax\n"
        "jne .Ls5_11e08\n"
        "lea ebx, [rax + 1]\n"
        "jmp .Ls5_11e18\n"
        ".Ls5_11e08:\n"
        S5_MOV64(r8, rsi)
        S5_MOV32(edx, edi)
        S5_MOV64(rcx, r14)
        "call qword ptr [rip + rva_15d00]\n"
        S5_MOV32(ebx, eax)
        ".Ls5_11e18:\n"
        "mov dword ptr [rsp + 0x30], ebx\n"
        ".Ls5_11e1c:\n"
        "jmp .Ls5_11e24\n"
        S5_XOR32(ebx, ebx)
        "mov dword ptr [rsp + 0x30], ebx\n"
        ".Ls5_11e24:\n"
        S5_MOV32(eax, ebx)
        "mov rbx, qword ptr [rsp + 0x78]\n"
        "add rsp, 0x40\n"
        "pop r14\n"
        "pop rdi\n"
        "pop rsi\n"
        "ret\n" END);
}

/* 0x11e34..0x11e4d, Windows AMD64. */
NAKED void internal_11e34(void) {
    __asm__(START
        ".Ls5_11e34:\n"
        "mov rax, qword ptr [rip + rva_17c58]\n"
        "test rax, rax\n"
        "jne .Ls5_11e46\n"
        "mov eax, 1\n"
        "ret\n"
        ".Ls5_11e46:\n"
        ".byte 0x48\njmp qword ptr [rip + rva_15d00]\n" END);
}

/* 0x11e50..0x11e55, Windows AMD64. */
NAKED void internal_11e50(void) {
    __asm__(START
        ".Ls5_11e50:\n"
        "jmp rva_11b24\n" END);
}

/* 0x11e58..0x11e95, Windows AMD64. */
NAKED void internal_11e58(void) {
    __asm__(START
        ".Ls5_11e58:\n"
        "mov qword ptr [rsp + 8], rbx\n"
        "mov qword ptr [rsp + 0x10], rsi\n"
        "push rdi\n"
        "sub rsp, 0x20\n"
        S5_MOV64(rdi, r8)
        S5_MOV32(ebx, edx)
        S5_MOV64(rsi, rcx)
        "cmp edx, 1\n"
        "jne .Ls5_11e79\n"
        "call rva_11f04\n"
        ".Ls5_11e79:\n"
        S5_MOV64(r8, rdi)
        S5_MOV32(edx, ebx)
        S5_MOV64(rcx, rsi)
        "mov rbx, qword ptr [rsp + 0x30]\n"
        "mov rsi, qword ptr [rsp + 0x38]\n"
        "add rsp, 0x20\n"
        "pop rdi\n"
        "jmp rva_11d0c\n" END);
}

/* 0x11e98..0x11f03, Windows AMD64. */
NAKED void internal_11e98(void) {
    __asm__(START
        ".Ls5_11e98:\n"
        ".byte 0x40\npush rbp\n"
        S5_MOV64(rbp, rsp)
        "sub rsp, 0x20\n"
        "and qword ptr [rbp + 0x18], 0\n"
        "lea rcx, [rbp + 0x18]\n"
        "call qword ptr [rip + rva_15040]\n"
        "mov rax, qword ptr [rbp + 0x18]\n"
        "mov qword ptr [rbp + 0x10], rax\n"
        "call qword ptr [rip + rva_15038]\n"
        S5_MOV32(eax, eax)
        "xor qword ptr [rbp + 0x10], rax\n"
        "call qword ptr [rip + rva_15030]\n"
        S5_MOV32(eax, eax)
        "lea rcx, [rbp + 0x20]\n"
        "xor qword ptr [rbp + 0x10], rax\n"
        "call qword ptr [rip + rva_15028]\n"
        "mov eax, dword ptr [rbp + 0x20]\n"
        "lea rcx, [rbp + 0x10]\n"
        "shl rax, 0x20\n"
        "xor rax, qword ptr [rbp + 0x20]\n"
        "xor rax, qword ptr [rbp + 0x10]\n"
        S5_XOR64(rax, rcx)
        "movabs rcx, 0xffffffffffff\n"
        S5_AND64(rax, rcx)
        "add rsp, 0x20\n"
        "pop rbp\n"
        "ret\n" END);
}

/* 0x11f04..0x11fb0, Windows AMD64. */
NAKED void internal_11f04(void) {
    __asm__(START
        ".Ls5_11f04:\n"
        "mov qword ptr [rsp + 0x18], rbx\n"
        "push rbp\n"
        S5_MOV64(rbp, rsp)
        "sub rsp, 0x30\n"
        "mov rax, qword ptr [rip + rva_1e800]\n"
        "movabs rbx, 0x2b992ddfa232\n"
        S5_CMP64(rax, rbx)
        "jne .Ls5_11f9b\n"
        "and qword ptr [rbp + 0x10], 0\n"
        "lea rcx, [rbp + 0x10]\n"
        "call qword ptr [rip + rva_15040]\n"
        "mov rax, qword ptr [rbp + 0x10]\n"
        "mov qword ptr [rbp - 0x10], rax\n"
        "call qword ptr [rip + rva_15038]\n"
        S5_MOV32(eax, eax)
        "xor qword ptr [rbp - 0x10], rax\n"
        "call qword ptr [rip + rva_15030]\n"
        S5_MOV32(eax, eax)
        "lea rcx, [rbp + 0x18]\n"
        "xor qword ptr [rbp - 0x10], rax\n"
        "call qword ptr [rip + rva_15028]\n"
        "mov eax, dword ptr [rbp + 0x18]\n"
        "lea rcx, [rbp - 0x10]\n"
        "shl rax, 0x20\n"
        "xor rax, qword ptr [rbp + 0x18]\n"
        "xor rax, qword ptr [rbp - 0x10]\n"
        S5_XOR64(rax, rcx)
        "movabs rcx, 0xffffffffffff\n"
        S5_AND64(rax, rcx)
        "movabs rcx, 0x2b992ddfa233\n"
        S5_CMP64(rax, rbx)
        "cmove rax, rcx\n"
        "mov qword ptr [rip + rva_1e800], rax\n"
        ".Ls5_11f9b:\n"
        "mov rbx, qword ptr [rsp + 0x50]\n"
        "not rax\n"
        "mov qword ptr [rip + rva_1e840], rax\n"
        "add rsp, 0x30\n"
        "pop rbp\n"
        "ret\n" END);
}

/* 0x11fb0..0x11fd3, Windows AMD64. */
NAKED void internal_11fb0(void) {
    __asm__(START
        ".Ls5_11fb0:\n"
        "sub rsp, 0x28\n"
        "cmp edx, 1\n"
        "jne .Ls5_11fc9\n"
        "cmp qword ptr [rip + rva_17c58], 0\n"
        "jne .Ls5_11fc9\n"
        "call qword ptr [rip + rva_15048]\n"
        ".Ls5_11fc9:\n"
        "mov eax, 1\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x11fd4..0x11fe2, Windows AMD64. */
NAKED void internal_11fd4(void) {
    __asm__(START
        ".Ls5_11fd4:\n"
        "lea rcx, [rip + rva_20a10]\n"
        ".byte 0x48\njmp qword ptr [rip + rva_15050]\n" END);
}

/* 0x11fe4..0x11ff0, Windows AMD64. */
NAKED void internal_11fe4(void) {
    __asm__(START
        ".Ls5_11fe4:\n"
        "lea rcx, [rip + rva_20a10]\n"
        "jmp rva_14782\n" END);
}

/* 0x11ff0..0x11ff8, Windows AMD64. */
NAKED void internal_11ff0(void) {
    __asm__(START
        ".Ls5_11ff0:\n"
        "lea rax, [rip + rva_20a20]\n"
        "ret\n" END);
}

/* 0x11ff8..0x12000, Windows AMD64. */
NAKED void internal_11ff8(void) {
    __asm__(START
        ".Ls5_11ff8:\n"
        "lea rax, [rip + rva_20a28]\n"
        "ret\n" END);
}

/* 0x12000..0x1201b, Windows AMD64. */
NAKED void internal_12000(void) {
    __asm__(START
        ".Ls5_12000:\n"
        "sub rsp, 0x28\n"
        "call rva_11ff0\n"
        "or qword ptr [rax], 0x24\n"
        "call rva_11ff8\n"
        "or qword ptr [rax], 2\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x1201c..0x12030, Windows AMD64. */
NAKED void internal_1201c(void) {
    __asm__(START
        ".Ls5_1201c:\n"
        "sub rsp, 0x28\n"
        "call rva_12c5c\n"
        S5_MOV32(ecx, eax)
        "add rsp, 0x28\n"
        "jmp rva_147b2\n" END);
}

/* 0x12030..0x12079, Windows AMD64. */
NAKED void internal_12030(void) {
    __asm__(START
        ".Ls5_12030:\n"
        "movsxd r8, dword ptr [rcx + 0x3c]\n"
        "movzx eax, word ptr [r8 + rcx + 0x14]\n"
        "lea r9, [r8 + rcx]\n"
        "add rax, 0x18\n"
        S5_ADD64(r9, rax)
        "movzx eax, word ptr [r8 + rcx + 6]\n"
        "lea rcx, [rax + rax*4]\n"
        "lea r8, [r9 + rcx*8]\n"
        "jmp .Ls5_1206d\n"
        ".Ls5_12055:\n"
        "mov ecx, dword ptr [r9 + 0xc]\n"
        S5_CMP64(rdx, rcx)
        "jb .Ls5_12069\n"
        "mov eax, dword ptr [r9 + 8]\n"
        S5_ADD32(eax, ecx)
        S5_CMP64(rdx, rax)
        "jb .Ls5_12075\n"
        ".Ls5_12069:\n"
        "add r9, 0x28\n"
        ".Ls5_1206d:\n"
        S5_CMP64(r9, r8)
        "jne .Ls5_12055\n"
        S5_XOR32(eax, eax)
        "ret\n"
        ".Ls5_12075:\n"
        S5_MOV64(rax, r9)
        "ret\n" END);
}

/* 0x1207c..0x12081, Windows AMD64. */
NAKED void internal_1207c(void) {
    __asm__(START
        ".Ls5_1207c:\n"
        "jmp rva_147b8\n" END);
}

/* 0x12084..0x120b2, Windows AMD64. */
NAKED void internal_12084(void) {
    __asm__(START
        ".Ls5_12084:\n"
        "test rcx, rcx\n"
        "je .Ls5_120af\n"
        "mov eax, 0x5a4d\n"
        "cmp word ptr [rcx], ax\n"
        "jne .Ls5_120af\n"
        "movsxd rax, dword ptr [rcx + 0x3c]\n"
        S5_ADD64(rax, rcx)
        "cmp dword ptr [rax], 0x4550\n"
        "jne .Ls5_120af\n"
        "mov ecx, 0x20b\n"
        "cmp word ptr [rax + 0x18], cx\n"
        "sete al\n"
        "ret\n"
        ".Ls5_120af:\n"
        S5_XOR8(al, al)
        "ret\n" END);
}

/* 0x120b4..0x120be, Windows AMD64. */
NAKED void internal_120b4(void) {
    __asm__(START
        ".Ls5_120b4:\n"
        "mov rax, qword ptr gs:[0x30]\n"
        "ret\n" END);
}

/* 0x120c0..0x120f9, Windows AMD64. */
NAKED void internal_120c0(void) {
    __asm__(START
        ".Ls5_120c0:\n"
        "sub rsp, 0x28\n"
        "call rva_12c64\n"
        "test eax, eax\n"
        "je .Ls5_120ee\n"
        "mov rax, qword ptr gs:[0x30]\n"
        "mov rcx, qword ptr [rax + 8]\n"
        "jmp .Ls5_120e1\n"
        ".Ls5_120dc:\n"
        S5_CMP64(rcx, rax)
        "je .Ls5_120f5\n"
        ".Ls5_120e1:\n"
        S5_XOR32(eax, eax)
        "lock cmpxchg qword ptr [rip + rva_20a38], rcx\n"
        "jne .Ls5_120dc\n"
        ".Ls5_120ee:\n"
        S5_XOR8(al, al)
        ".Ls5_120f0:\n"
        "add rsp, 0x28\n"
        "ret\n"
        ".Ls5_120f5:\n"
        "mov al, 1\n"
        "jmp .Ls5_120f0\n" END);
}

/* 0x120fc..0x12130, Windows AMD64. */
NAKED void internal_120fc(void) {
    __asm__(START
        ".Ls5_120fc:\n"
        "sub rsp, 0x28\n"
        "call rva_12c64\n"
        "test eax, eax\n"
        "je .Ls5_12110\n"
        "call rva_12990\n"
        "jmp .Ls5_12129\n"
        ".Ls5_12110:\n"
        "call rva_12c5c\n"
        S5_MOV32(ecx, eax)
        "call rva_147b2\n"
        "test eax, eax\n"
        "je .Ls5_12124\n"
        S5_XOR8(al, al)
        "jmp .Ls5_1212b\n"
        ".Ls5_12124:\n"
        "call rva_147b8\n"
        ".Ls5_12129:\n"
        "mov al, 1\n"
        ".Ls5_1212b:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12130..0x12145, Windows AMD64. */
NAKED void internal_12130(void) {
    __asm__(START
        ".Ls5_12130:\n"
        "sub rsp, 0x28\n"
        S5_XOR32(ecx, ecx)
        "call rva_12268\n"
        "test al, al\n"
        "setne al\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12148..0x12170, Windows AMD64. */
NAKED void internal_12148(void) {
    __asm__(START
        ".Ls5_12148:\n"
        "sub rsp, 0x28\n"
        "call rva_14c10\n"
        "test al, al\n"
        "jne .Ls5_12159\n"
        ".Ls5_12155:\n"
        S5_XOR8(al, al)
        "jmp .Ls5_1216b\n"
        ".Ls5_12159:\n"
        "call rva_14c10\n"
        "test al, al\n"
        "jne .Ls5_12169\n"
        "call rva_14c14\n"
        "jmp .Ls5_12155\n"
        ".Ls5_12169:\n"
        "mov al, 1\n"
        ".Ls5_1216b:\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}

/* 0x12170..0x12185, Windows AMD64. */
NAKED void internal_12170(void) {
    __asm__(START
        ".Ls5_12170:\n"
        "sub rsp, 0x28\n"
        "call rva_14c14\n"
        "call rva_14c14\n"
        "mov al, 1\n"
        "add rsp, 0x28\n"
        "ret\n" END);
}
