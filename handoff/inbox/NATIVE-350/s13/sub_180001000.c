#include "host-encoding.h"

/* zedstwu.dll, Windows AMD64 host RVA 0x1000 through 0x1f1e (exclusive). */
__asm__(".globl rva_1000\n.set rva_1000, sub_180001000\n");
NAKED void sub_180001000(void) {
    __asm__(START
        "    push r15\n" /* 01000 */
        "    push r14\n" /* 01002 */
        "    push r13\n" /* 01004 */
        "    push r12\n" /* 01006 */
        "    push rsi\n" /* 01008 */
        "    push rdi\n" /* 01009 */
        "    push rbp\n" /* 0100a */
        "    push rbx\n" /* 0100b */
        "    sub rsp, 0x238\n" /* 0100c */
        "    movapd xmmword ptr [rsp + 0x220], xmm14\n" /* 01013 */
        "    movapd xmmword ptr [rsp + 0x210], xmm13\n" /* 0101d */
        "    movapd xmmword ptr [rsp + 0x200], xmm12\n" /* 01027 */
        "    movapd xmmword ptr [rsp + 0x1f0], xmm11\n" /* 01031 */
        "    movapd xmmword ptr [rsp + 0x1e0], xmm10\n" /* 0103b */
        "    movapd xmmword ptr [rsp + 0x1d0], xmm9\n" /* 01045 */
        "    movapd xmmword ptr [rsp + 0x1c0], xmm8\n" /* 0104f */
        "    movapd xmmword ptr [rsp + 0x1b0], xmm7\n" /* 01059 */
        "    movapd xmmword ptr [rsp + 0x1a0], xmm6\n" /* 01062 */
        "    mov rdi, r8\n" /* 0106b */
        "    mov rbx, rcx\n" /* 0106e */
        "    mov rax, qword ptr [rip + data_rva_24378]\n" /* 01071 */
        "    mov rax, qword ptr [rcx + rax*8 - 8]\n" /* 01078 */
        "    mov qword ptr [rip + data_rva_22360], rax\n" /* 0107d */
        "    lea rdx, [rip + data_rva_22360]\n" /* 01084 */
        "    mov rax, qword ptr [rip + data_rva_24380]\n" /* 0108b */
        "    mov rax, qword ptr [rcx + rax*8 - 8]\n" /* 01092 */
        "    mov qword ptr [rip + data_rva_22358], rax\n" /* 01097 */
        "    lea r9, [rip + data_rva_22358]\n" /* 0109e */
        "    mov rax, qword ptr [rip + data_rva_24398]\n" /* 010a5 */
        "    mov rax, qword ptr [rcx + rax*8 - 8]\n" /* 010ac */
        "    mov qword ptr [rip + data_rva_22350], rax\n" /* 010b1 */
        "    lea rax, [rip + data_rva_22350]\n" /* 010b8 */
        "    mov rcx, qword ptr [rip + data_rva_243a0]\n" /* 010bf */
        "    mov rcx, qword ptr [rbx + rcx*8 - 8]\n" /* 010c6 */
        "    mov qword ptr [rip + data_rva_22348], rcx\n" /* 010cb */
        "    lea rcx, [rip + data_rva_22348]\n" /* 010d2 */
        "    mov r8, qword ptr [rip + data_rva_243a8]\n" /* 010d9 */
        "    mov r8, qword ptr [rbx + r8*8 - 8]\n" /* 010e0 */
        "    mov qword ptr [rip + data_rva_22340], r8\n" /* 010e5 */
        "    lea r8, [rip + data_rva_22340]\n" /* 010ec */
        "    mov r10, qword ptr [rip + data_rva_243b0]\n" /* 010f3 */
        "    mov r10, qword ptr [rbx + r10*8 - 8]\n" /* 010fa */
        "    mov qword ptr [rip + data_rva_22338], r10\n" /* 010ff */
        "    lea r10, [rip + data_rva_22338]\n" /* 01106 */
        "    lea r11, [rip + data_rva_222b8]\n" /* 0110d */
        "    mov qword ptr [rsp + 0x70], r11\n" /* 01114 */
        "    lea r11, [rip + data_rva_222c0]\n" /* 01119 */
        "    mov qword ptr [rsp + 0x68], r11\n" /* 01120 */
        "    lea r11, [rip + data_rva_22368]\n" /* 01125 */
        "    mov qword ptr [rsp + 0x60], r11\n" /* 0112c */
        "    mov qword ptr [rsp + 0x58], r10\n" /* 01131 */
        "    lea r10, [rip + data_rva_223d0]\n" /* 01136 */
        "    mov qword ptr [rsp + 0x50], r10\n" /* 0113d */
        "    mov qword ptr [rsp + 0x48], r8\n" /* 01142 */
        "    lea r8, [rip + data_rva_223d8]\n" /* 01147 */
        "    mov qword ptr [rsp + 0x40], r8\n" /* 0114e */
        "    mov qword ptr [rsp + 0x38], rcx\n" /* 01153 */
        "    lea rcx, [rip + data_rva_223e0]\n" /* 01158 */
        "    mov qword ptr [rsp + 0x30], rcx\n" /* 0115f */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 01164 */
        "    lea rax, [rip + data_rva_223e8]\n" /* 01169 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 01170 */
        "    lea rcx, [rip + data_rva_223f8]\n" /* 01175 */
        "    lea r8, [rip + data_rva_223f0]\n" /* 0117c */
        "    call thunk_zereport_dll_ZREP_PLLOGN_rva_15304\n" /* 01183 */
        "    mov eax, dword ptr [rip + data_rva_223f0]\n" /* 01188 */
        "    or eax, dword ptr [rip + data_rva_223f8]\n" /* 0118e */
        "    or eax, dword ptr [rip + data_rva_223d0]\n" /* 01194 */
        "    test al, 1\n" /* 0119a */
        S9_JE32(.Lblock_1ebb) /* 0119c */
        "    mov rax, qword ptr [rip + data_rva_223e0]\n" /* 011a2 */
        "    and eax, 1\n" /* 011a9 */
        "    mov qword ptr [rip + data_rva_22330], rax\n" /* 011ac */
        "    mov rax, qword ptr [rip + data_rva_243b8]\n" /* 011b3 */
        "    mov rax, qword ptr [rbx + rax*8 - 8]\n" /* 011ba */
        "    inc rax\n" /* 011bf */
        "    mov qword ptr [rip + data_rva_22328], rax\n" /* 011c2 */
        "    mov rax, qword ptr [rip + data_rva_24258]\n" /* 011c9 */
        "    movsd xmm2, qword ptr [rdi + rax*8 - 8]\n" /* 011d0 */
        "    movsd qword ptr [rip + data_rva_22288], xmm2\n" /* 011d6 */
        "    mov rax, qword ptr [rip + data_rva_24260]\n" /* 011de */
        "    movsd xmm1, qword ptr [rdi + rax*8 - 8]\n" /* 011e5 */
        "    mov rax, qword ptr [rip + data_rva_24268]\n" /* 011eb */
        "    movsd xmm0, qword ptr [rdi + rax*8 - 8]\n" /* 011f2 */
        "    movsd qword ptr [rip + data_rva_222b0], xmm0\n" /* 011f8 */
        "    mov rax, qword ptr [rip + data_rva_24270]\n" /* 01200 */
        "    movsd xmm3, qword ptr [rdi + rax*8 - 8]\n" /* 01207 */
        "    mov rax, qword ptr [rip + data_rva_24310]\n" /* 0120d */
        "    mov r8, qword ptr [rbx + rax*8 - 8]\n" /* 01214 */
        "    mov rax, qword ptr [rip + data_rva_24318]\n" /* 01219 */
        "    mov rcx, qword ptr [rbx + rax*8 - 8]\n" /* 01220 */
        "    mov qword ptr [rip + data_rva_22320], rcx\n" /* 01225 */
        "    mov rax, qword ptr [rip + data_rva_24320]\n" /* 0122c */
        "    mov r9, qword ptr [rbx + rax*8 - 8]\n" /* 01233 */
        "    mov rax, qword ptr [rip + data_rva_24328]\n" /* 01238 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 0123f */
        "    mov r11, qword ptr [rdx + 0x38]\n" /* 01246 */
        "    cmp r8, r11\n" /* 0124a */
        "    mov edx, 0xb\n" /* 0124d */
        "    cmovne rdx, r8\n" /* 01252 */
        "    mov r10, qword ptr [rbx + rax*8 - 8]\n" /* 01256 */
        "    test r10, r10\n" /* 0125b */
        "    cmove r8, rdx\n" /* 0125e */
        "    mov qword ptr [rip + data_rva_22298], r9\n" /* 01262 */
        "    test r9, r9\n" /* 01269 */
        "    cmove r8, rdx\n" /* 0126c */
        "    je .Lblock_1281\n" /* 01270 */
        "    test r10, r10\n" /* 01272 */
        "    je .Lblock_129e\n" /* 01275 */
        ".Lblock_1277:\n"
        "    cmp r9, r11\n" /* 01277 */
        "    jne .Lblock_12b8\n" /* 0127a */
        S9_JMP32(.Lblock_134f) /* 0127c */
        ".Lblock_1281:\n"
        "    movsd xmm4, qword ptr [rip + rdata_rva_19540]\n" /* 01281 */
        "    addsd xmm4, xmm0\n" /* 01289 */
        "    cvttsd2si r9, xmm4\n" /* 0128d */
        "    mov qword ptr [rip + data_rva_22298], r9\n" /* 01292 */
        "    test r10, r10\n" /* 01299 */
        "    jne .Lblock_1277\n" /* 0129c */
        ".Lblock_129e:\n"
        "    movsd xmm4, qword ptr [rip + rdata_rva_19540]\n" /* 0129e */
        "    addsd xmm4, xmm0\n" /* 012a6 */
        "    cvttsd2si r10, xmm4\n" /* 012aa */
        "    cmp r9, r11\n" /* 012af */
        S9_JE32(.Lblock_134f) /* 012b2 */
        ".Lblock_12b8:\n"
        "    cmp r10, r11\n" /* 012b8 */
        S9_JE32(.Lblock_134f) /* 012bb */
        "    mov rdx, rcx\n" /* 012c1 */
        "    neg rdx\n" /* 012c4 */
        "    cmovs rdx, rcx\n" /* 012c7 */
        "    mov rcx, rdx\n" /* 012cb */
        "    neg rcx\n" /* 012ce */
        "    mov rax, r10\n" /* 012d1 */
        "    sub rax, r9\n" /* 012d4 */
        "    cmovge rcx, rdx\n" /* 012d7 */
        "    mov qword ptr [rip + data_rva_22320], rcx\n" /* 012db */
        "    cmp r8, r11\n" /* 012e2 */
        "    jne .Lblock_1300\n" /* 012e5 */
        "    mov rdx, rax\n" /* 012e7 */
        "    or rdx, rcx\n" /* 012ea */
        "    shr rdx, 0x20\n" /* 012ed */
        "    je .Lblock_1336\n" /* 012f1 */
        "    cqo\n" /* 012f3 */
        "    idiv rcx\n" /* 012f5 */
        "    mov r8, rax\n" /* 012f8 */
        "    inc r8\n" /* 012fb */
        "    jmp .Lblock_134f\n" /* 012fe */
        ".Lblock_1300:\n"
        "    cmp r8, 1\n" /* 01300 */
        "    jle .Lblock_1327\n" /* 01304 */
        "    lea rcx, [r8 - 1]\n" /* 01306 */
        "    mov rdx, rax\n" /* 0130a */
        "    or rdx, rcx\n" /* 0130d */
        "    shr rdx, 0x20\n" /* 01310 */
        "    je .Lblock_1342\n" /* 01314 */
        "    cqo\n" /* 01316 */
        "    idiv rcx\n" /* 01318 */
        "    mov rcx, rax\n" /* 0131b */
        "    mov qword ptr [rip + data_rva_22320], rax\n" /* 0131e */
        "    jmp .Lblock_134f\n" /* 01325 */
        ".Lblock_1327:\n"
        "    mov qword ptr [rip + data_rva_22320], 0\n" /* 01327 */
        "    xor ecx, ecx\n" /* 01332 */
        "    jmp .Lblock_134f\n" /* 01334 */
        ".Lblock_1336:\n"
        "    xor edx, edx\n" /* 01336 */
        "    div ecx\n" /* 01338 */
        "    mov r8d, eax\n" /* 0133a */
        "    inc r8\n" /* 0133d */
        "    jmp .Lblock_134f\n" /* 01340 */
        ".Lblock_1342:\n"
        "    xor edx, edx\n" /* 01342 */
        "    div ecx\n" /* 01344 */
        "    mov ecx, eax\n" /* 01346 */
        "    mov qword ptr [rip + data_rva_22320], rcx\n" /* 01348 */
        ".Lblock_134f:\n"
        "    mov rax, qword ptr [rsp + 0x2a0]\n" /* 0134f */
        "    cmp r8, r11\n" /* 01357 */
        "    mov edx, 0xb\n" /* 0135a */
        "    cmovne rdx, r8\n" /* 0135f */
        "    cmp r9, r11\n" /* 01363 */
        "    jne .Lblock_13b9\n" /* 01366 */
        "    cmp r10, r11\n" /* 01368 */
        "    jne .Lblock_13b9\n" /* 0136b */
        "    movsd xmm4, qword ptr [rip + rdata_rva_19540]\n" /* 0136d */
        "    addsd xmm4, xmm3\n" /* 01375 */
        "    cvttsd2si r9, xmm4\n" /* 01379 */
        "    lea r8, [rdx - 1]\n" /* 0137e */
        "    mov r10d, 1\n" /* 01382 */
        "    mov r11d, 1\n" /* 01388 */
        "    sub r11, rdx\n" /* 0138e */
        "    test rcx, rcx\n" /* 01391 */
        "    cmovns r11, r8\n" /* 01394 */
        "    mov r8, r11\n" /* 01398 */
        "    shr r8, 0x3f\n" /* 0139b */
        "    add r8, r11\n" /* 0139f */
        "    sar r8, 1\n" /* 013a2 */
        "    sub r9, r8\n" /* 013a5 */
        "    cmp r9, 2\n" /* 013a8 */
        "    cmovl r9, r10\n" /* 013ac */
        "    mov qword ptr [rip + data_rva_22298], r9\n" /* 013b0 */
        "    jmp .Lblock_1404\n" /* 013b7 */
        ".Lblock_13b9:\n"
        "    cmp r9, r11\n" /* 013b9 */
        "    jne .Lblock_1404\n" /* 013bc */
        "    lea r8, [rdx - 1]\n" /* 013be */
        "    imul r8, rcx\n" /* 013c2 */
        "    mov r9, r10\n" /* 013c6 */
        "    sub r9, r8\n" /* 013c9 */
        "    mov qword ptr [rip + data_rva_22298], r9\n" /* 013cc */
        "    jg .Lblock_1404\n" /* 013d3 */
        "    mov qword ptr [rip + data_rva_22298], 1\n" /* 013d5 */
        "    mov rdx, rcx\n" /* 013e0 */
        "    neg rdx\n" /* 013e3 */
        "    cmovns rcx, rdx\n" /* 013e6 */
        "    mov qword ptr [rip + data_rva_22320], rcx\n" /* 013ea */
        "    dec r10\n" /* 013f1 */
        "    imul r10, rcx\n" /* 013f4 */
        "    inc r10\n" /* 013f8 */
        "    mov r9d, 1\n" /* 013fb */
        "    mov rdx, r10\n" /* 01401 */
        ".Lblock_1404:\n"
        "    mov rsi, qword ptr [rax]\n" /* 01404 */
        "    cmp rdx, rsi\n" /* 01407 */
        "    cmovl rsi, rdx\n" /* 0140a */
        "    mov qword ptr [rip + data_rva_22318], 0\n" /* 0140e */
        "    test rsi, rsi\n" /* 01419 */
        S9_JLE32(.Lblock_1a70) /* 0141c */
        "    mov r13, qword ptr [rsp + 0x2b8]\n" /* 01422 */
        "    addsd xmm3, qword ptr [rip + rdata_rva_19540]\n" /* 0142a */
        "    cvttsd2si rax, xmm3\n" /* 01432 */
        "    sub rax, r9\n" /* 01437 */
        "    mov rdx, rax\n" /* 0143a */
        "    neg rdx\n" /* 0143d */
        "    cmovs rdx, rax\n" /* 01440 */
        "    cmp rdx, 0xa\n" /* 01444 */
        "    mov qword ptr [rsp + 0x138], rbx\n" /* 01448 */
        "    ja .Lblock_1468\n" /* 01450 */
        "    movapd xmm3, xmm1\n" /* 01452 */
        "    subsd xmm3, xmm2\n" /* 01456 */
        "    addsd xmm1, qword ptr [rip + rdata_rva_19550]\n" /* 0145a */
        "    divsd xmm3, xmm1\n" /* 01462 */
        "    jmp .Lblock_1470\n" /* 01466 */
        ".Lblock_1468:\n"
        "    movsd xmm3, qword ptr [rip + rdata_rva_19548]\n" /* 01468 */
        ".Lblock_1470:\n"
        "    movsd qword ptr [rip + data_rva_222a8], xmm3\n" /* 01470 */
        "    movabs rax, 0x3eb0c6f7a0b5ed8d\n" /* 01478 */
        "    mov qword ptr [r13], rax\n" /* 01482 */
        "    movabs rax, 0x3ff0000000000000\n" /* 01486 */
        "    movsd xmm6, qword ptr [rip + rdata_rva_19550]\n" /* 01490 */
        "    movapd xmm1, xmm6\n" /* 01498 */
        "    subsd xmm1, qword ptr [rip + rdata_rva_19558]\n" /* 0149c */
        "    mulsd xmm1, qword ptr [rip + rdata_rva_19560]\n" /* 014a4 */
        "    mov qword ptr [r13 + 8], rax\n" /* 014ac */
        "    movsd qword ptr [r13 + 0x10], xmm1\n" /* 014b0 */
        "    movabs rdx, 0x3f0a36e2eb1c432d\n" /* 014b6 */
        "    mov qword ptr [r13 + 0x20], rdx\n" /* 014c0 */
        "    mov qword ptr [r13 + 0x28], rax\n" /* 014c4 */
        "    mov qword ptr [rip + data_rva_22310], 1\n" /* 014c8 */
        "    xor eax, eax\n" /* 014d3 */
        "    lea r12, [rip + data_rva_222a8]\n" /* 014d5 */
        "    movsd xmm7, qword ptr [rip + rdata_rva_19568]\n" /* 014dc */
        "    movsd xmm8, qword ptr [rip + rdata_rva_19570]\n" /* 014e4 */
        "    movsd xmm9, qword ptr [rip + rdata_rva_19578]\n" /* 014ed */
        "    movsd xmm10, qword ptr [rip + rdata_rva_19580]\n" /* 014f6 */
        "    movsd xmm11, qword ptr [rip + rdata_rva_19588]\n" /* 014ff */
        "    movsd xmm12, qword ptr [rip + rdata_rva_19590]\n" /* 01508 */
        "    movsd xmm13, qword ptr [rip + rdata_rva_19598]\n" /* 01511 */
        "    movsd xmm14, qword ptr [rip + rdata_rva_195a0]\n" /* 0151a */
        "    lea r15, [rip + data_rva_222a0]\n" /* 01523 */
        "    lea r14, [rip + rdata_rva_19600]\n" /* 0152a */
        "    lea rdi, [rip + data_rva_22300]\n" /* 01531 */
        "    mov rdx, qword ptr [rip + iat_atdms_dll_DMS_INITV_rva_19290]\n" /* 01538 */
        "    add rdx, 8\n" /* 0153f */
        "    mov qword ptr [rsp + 0x140], rdx\n" /* 01543 */
        "    xor edx, edx\n" /* 0154b */
        "    jmp .Lblock_1585\n" /* 0154d */
        "    nop\n" /* 0154f */
        ".Lblock_1550:\n"
        "    mov qword ptr [rdx + rax*8 - 8], 1\n" /* 01550 */
        "    movabs rdx, 0x3fe0000000000000\n" /* 01559 */
        "    mov qword ptr [rip + data_rva_222a8], rdx\n" /* 01563 */
        ".Lblock_156a:\n"
        "    mov rdx, qword ptr [rip + data_rva_22310]\n" /* 0156a */
        "    lea r8, [rdx + 1]\n" /* 01571 */
        "    mov qword ptr [rip + data_rva_22310], r8\n" /* 01575 */
        "    cmp rdx, rsi\n" /* 0157c */
        S9_JGE32(.Lblock_1788) /* 0157f */
        ".Lblock_1585:\n"
        "    imul rdx, rcx\n" /* 01585 */
        "    add rdx, r9\n" /* 01589 */
        "    xorps xmm1, xmm1\n" /* 0158c */
        "    cvtsi2sd xmm1, rdx\n" /* 0158f */
        "    mov qword ptr [rip + data_rva_22308], rdx\n" /* 01594 */
        "    movsd qword ptr [rip + data_rva_22280], xmm1\n" /* 0159b */
        "    ucomisd xmm1, xmm0\n" /* 015a3 */
        "    jbe .Lblock_156a\n" /* 015a7 */
        "    inc rax\n" /* 015a9 */
        "    mov qword ptr [rip + data_rva_22318], rax\n" /* 015ac */
        "    movapd xmm2, xmm1\n" /* 015b3 */
        "    subsd xmm2, xmm0\n" /* 015b7 */
        "    addsd xmm1, xmm6\n" /* 015bb */
        "    divsd xmm2, xmm1\n" /* 015bf */
        "    movsd qword ptr [r13 + 0x18], xmm2\n" /* 015c3 */
        "    mov qword ptr [rip + data_rva_22300], 1\n" /* 015c9 */
        S9_NOP12 /* 015d4 */
        ".Lblock_15e0:\n"
        "    movsd xmm0, qword ptr [rip + data_rva_222a8]\n" /* 015e0 */
        "    movapd xmm1, xmm0\n" /* 015e8 */
        "    mulsd xmm1, xmm7\n" /* 015ec */
        "    addsd xmm1, xmm8\n" /* 015f0 */
        "    mulsd xmm1, xmm0\n" /* 015f5 */
        "    addsd xmm1, xmm9\n" /* 015f9 */
        "    mulsd xmm1, xmm0\n" /* 015fe */
        "    addsd xmm1, xmm10\n" /* 01602 */
        "    mulsd xmm1, xmm0\n" /* 01607 */
        "    addsd xmm1, xmm11\n" /* 0160b */
        "    mulsd xmm1, xmm0\n" /* 01610 */
        "    addsd xmm1, xmm12\n" /* 01614 */
        "    mulsd xmm1, xmm0\n" /* 01619 */
        "    addsd xmm1, xmm13\n" /* 0161d */
        "    mulsd xmm1, xmm0\n" /* 01622 */
        "    addsd xmm1, xmm14\n" /* 01626 */
        "    movsd qword ptr [rip + data_rva_222a0], xmm1\n" /* 0162b */
        "    mov qword ptr [rsp + 0x20], r14\n" /* 01633 */
        "    mov rcx, rdi\n" /* 01638 */
        "    mov rdx, r12\n" /* 0163b */
        "    mov r8, r15\n" /* 0163e */
        "    mov r9, r13\n" /* 01641 */
        "    call thunk_zemath_dll_ZMTH_ARCONS_rva_15346\n" /* 01644 */
        "    cmp qword ptr [rip + data_rva_22300], 0\n" /* 01649 */
        "    jg .Lblock_15e0\n" /* 01651 */
        "    movsd xmm1, qword ptr [rip + data_rva_22280]\n" /* 01653 */
        "    mov rax, qword ptr [rip + data_rva_22318]\n" /* 0165b */
        "    movsd xmm0, qword ptr [rip + data_rva_222a8]\n" /* 01662 */
        "    ucomisd xmm0, xmm6\n" /* 0166a */
        "    mov rcx, qword ptr [rsp + 0x2a8]\n" /* 0166e */
        "    movsd qword ptr [rcx + rax*8 - 8], xmm1\n" /* 01676 */
        "    setp cl\n" /* 0167c */
        "    setne dl\n" /* 0167f */
        "    or dl, cl\n" /* 01682 */
        "    je .Lblock_16a0\n" /* 01684 */
        "    movsd xmm1, qword ptr [rip + data_rva_22288]\n" /* 01686 */
        "    addsd xmm1, xmm0\n" /* 0168e */
        "    movapd xmm2, xmm6\n" /* 01692 */
        "    subsd xmm2, xmm0\n" /* 01696 */
        "    divsd xmm1, xmm2\n" /* 0169a */
        "    jmp .Lblock_16ab\n" /* 0169e */
        ".Lblock_16a0:\n"
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 016a0 */
        "    movsd xmm1, qword ptr [rcx]\n" /* 016a7 */
        ".Lblock_16ab:\n"
        "    mov rbp, qword ptr [rsp + 0x2b0]\n" /* 016ab */
        "    movsd qword ptr [rbp + rax*8 - 8], xmm1\n" /* 016b3 */
        "    dec rax\n" /* 016b9 */
        "    mov rcx, qword ptr [rip + data_rva_1e050]\n" /* 016bc */
        "    lea rax, [rax + rax*2]\n" /* 016c3 */
        "    shl rax, 4\n" /* 016c7 */
        "    mov rbx, qword ptr [rsp + 0x2c0]\n" /* 016cb */
        "    mov qword ptr [rbx + rax], rcx\n" /* 016d3 */
        "    mov qword ptr [rbx + rax + 0x10], rcx\n" /* 016d7 */
        "    lea r9, [rbx + rax]\n" /* 016dc */
        "    add r9, 8\n" /* 016e0 */
        "    lea rcx, [rip + data_rva_22308]\n" /* 016e4 */
        "    lea rdx, [rip + rdata_rva_19628]\n" /* 016eb */
        "    lea r8, [rip + data_rva_1e050]\n" /* 016f2 */
        "    call thunk_atdms_dll_DMS_NUM2CH_rva_15232\n" /* 016f9 */
        "    mov rax, qword ptr [rip + data_rva_22318]\n" /* 016fe */
        "    lea rcx, [rax*8 - 8]\n" /* 01705 */
        "    add rcx, rbp\n" /* 0170d */
        "    mov rdx, qword ptr [rip + data_rva_22328]\n" /* 01710 */
        "    lea r8, [rip + data_rva_1e020]\n" /* 01717 */
        "    lea rdx, [r8 + rdx*8]\n" /* 0171e */
        "    add rdx, -8\n" /* 01722 */
        "    lea rax, [rax + rax*2]\n" /* 01726 */
        "    add rax, -3\n" /* 0172a */
        "    shl rax, 4\n" /* 0172e */
        "    lea r9, [rbx + rax]\n" /* 01732 */
        "    add r9, 0x18\n" /* 01736 */
        "    mov r8, qword ptr [rsp + 0x140]\n" /* 0173a */
        "    call thunk_atdms_dll_DMS_FMTCNV_rva_15238\n" /* 01742 */
        "    cmp qword ptr [rip + data_rva_22300], 0\n" /* 01747 */
        "    mov r9, qword ptr [rip + data_rva_22298]\n" /* 0174f */
        "    mov rcx, qword ptr [rip + data_rva_22320]\n" /* 01756 */
        "    movsd xmm0, qword ptr [rip + data_rva_222b0]\n" /* 0175d */
        "    mov rax, qword ptr [rip + data_rva_22318]\n" /* 01765 */
        "    mov rdx, qword ptr [rsp + 0x2c8]\n" /* 0176c */
        S9_JNE32(.Lblock_1550) /* 01774 */
        "    mov qword ptr [rdx + rax*8 - 8], 0\n" /* 0177a */
        S9_JMP32(.Lblock_156a) /* 01783 */
        ".Lblock_1788:\n"
        "    test rax, rax\n" /* 01788 */
        "    lea rsi, [rip + data_rva_223e0]\n" /* 0178b */
        "    lea rbx, [rip + data_rva_223d8]\n" /* 01792 */
        "    lea r14, [rip + data_rva_223e8]\n" /* 01799 */
        "    mov r15, qword ptr [rsp + 0x138]\n" /* 017a0 */
        S9_JE32(.Lblock_1a70) /* 017a8 */
        "    xorps xmm1, xmm1\n" /* 017ae */
        "    cvtsi2sd xmm1, r9\n" /* 017b1 */
        "    ucomisd xmm0, xmm1\n" /* 017b6 */
        S9_JBE32(.Lblock_18f3) /* 017ba */
        "    addsd xmm0, qword ptr [rip + rdata_rva_195a8]\n" /* 017c0 */
        "    cvttsd2si rax, xmm0\n" /* 017c8 */
        "    mov qword ptr [rip + data_rva_22290], rax\n" /* 017cd */
        "    lea rax, [rip + rdata_rva_19630]\n" /* 017d4 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 017db */
        "    lea rax, [rip + rdata_rva_19628]\n" /* 017e0 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 017e7 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 017ec */
        "    mov r9, qword ptr [rip + iat_atdms_dll_DMS_GLOBAL_rva_19250]\n" /* 017f1 */
        "    lea rax, [r9 + 0x38]\n" /* 017f8 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 017fc */
        "    add r9, 0x28\n" /* 01801 */
        "    lea rcx, [rip + data_rva_1e040]\n" /* 01805 */
        "    lea rdx, [rip + rdata_rva_19610]\n" /* 0180c */
        "    lea r8, [rip + rdata_rva_19608]\n" /* 01813 */
        "    call thunk_atdms_dll_DMS_IRRCHK_rva_1523e\n" /* 0181a */
        "    test rax, rax\n" /* 0181f */
        S9_JE32(.Lblock_18f3) /* 01822 */
        "    mov rax, qword ptr [rip + data_rva_22298]\n" /* 01828 */
        "    mov qword ptr [rsp + 0x170], 0\n" /* 0182f */
        "    mov dword ptr [rsp + 0x132], 0x10b0638\n" /* 0183b */
        "    mov word ptr [rsp + 0x136], 2\n" /* 01846 */
        "    mov qword ptr [rsp + 0x150], 0x320\n" /* 01850 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_ERROUT_rva_19260]\n" /* 0185c */
        "    mov qword ptr [rsp + 0x158], rcx\n" /* 01863 */
        "    mov qword ptr [rsp + 0x160], 0x50\n" /* 0186b */
        "    mov qword ptr [rsp + 0x168], rax\n" /* 01877 */
        "    lea rax, [rip + data_rva_1e140]\n" /* 0187f */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 01886 */
        "    lea rdi, [rsp + 0x170]\n" /* 0188b */
        "    movabs rdx, 0x801208384ff00\n" /* 01893 */
        "    lea r8, [rsp + 0x132]\n" /* 0189d */
        "    lea r9, [rsp + 0x150]\n" /* 018a5 */
        "    mov rcx, rdi\n" /* 018ad */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_rva_153e8\n" /* 018b0 */
        "    mov rax, qword ptr [rip + data_rva_22290]\n" /* 018b5 */
        "    mov dword ptr [rsp + 0x12e], 0x1010b\n" /* 018bc */
        "    mov qword ptr [rsp + 0x148], rax\n" /* 018c7 */
        "    lea rdx, [rsp + 0x12e]\n" /* 018cf */
        "    lea r8, [rsp + 0x148]\n" /* 018d7 */
        "    mov rcx, rdi\n" /* 018df */
        "    call thunk_libifcoremd_dll_for_write_int_fmt_xmit_rva_153ee\n" /* 018e2 */
        "    lea rcx, [rip + rdata_rva_19610]\n" /* 018e7 */
        "    call thunk_atdms_dll_DMS_ERRPRT_rva_1524a\n" /* 018ee */
        ".Lblock_18f3:\n"
        "    mov rdi, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 018f3 */
        "    cmp qword ptr [rdi + 0x58], 2\n" /* 018fa */
        "    jne .Lblock_1925\n" /* 018ff */
        "    lea r8, [rip + data_rva_22318]\n" /* 01901 */
        "    mov rcx, qword ptr [rsp + 0x2a8]\n" /* 01908 */
        "    mov rdx, qword ptr [rsp + 0x2b0]\n" /* 01910 */
        "    mov r9, qword ptr [rsp + 0x2d0]\n" /* 01918 */
        "    call sub_180001F20_rva_1f20\n" /* 01920 */
        ".Lblock_1925:\n"
        "    test byte ptr [rip + data_rva_223d0], 1\n" /* 01925 */
        S9_JE32(.Lblock_1b6e) /* 0192c */
        "    mov rax, qword ptr [rip + data_rva_22318]\n" /* 01932 */
        "    mov qword ptr [rip + data_rva_222f8], rax\n" /* 01939 */
        "    mov qword ptr [rip + data_rva_222f0], 2\n" /* 01940 */
        "    mov qword ptr [rip + data_rva_222e8], 1\n" /* 0194b */
        "    mov rax, qword ptr [rip + data_rva_24398]\n" /* 01956 */
        "    mov rax, qword ptr [r15 + rax*8 - 8]\n" /* 0195d */
        "    mov qword ptr [rip + data_rva_222e0], rax\n" /* 01962 */
        "    lea rcx, [rip + rdata_rva_19618]\n" /* 01969 */
        "    lea rdx, [rip + data_rva_222d8]\n" /* 01970 */
        "    lea r8, [rip + data_rva_222d0]\n" /* 01977 */
        "    call thunk_atdms_dll_DMS_ALLOCI_rva_15256\n" /* 0197e */
        "    mov rax, qword ptr [rip + data_rva_222d0]\n" /* 01983 */
        "    mov rcx, qword ptr [rip + iat_atdms_dll_DMS_PLEX_rva_19238]\n" /* 0198a */
        "    lea rax, [rcx + rax*8]\n" /* 01991 */
        "    add rax, -8\n" /* 01995 */
        "    xor ecx, ecx\n" /* 01999 */
        "    lea rdx, [rip + rdata_rva_195c0]\n" /* 0199b */
        S9_NOP14 /* 019a2 */
        ".Lblock_19b0:\n"
        "    mov r8, qword ptr [rcx + rdx]\n" /* 019b0 */
        "    mov qword ptr [rax + rcx], r8\n" /* 019b4 */
        "    add rcx, 8\n" /* 019b8 */
        "    cmp rcx, 0x40\n" /* 019bc */
        "    jne .Lblock_19b0\n" /* 019c0 */
        "    mov qword ptr [rip + data_rva_22310], 9\n" /* 019c2 */
        "    mov qword ptr [rip + data_rva_222c8], 1\n" /* 019cd */
        "    mov rax, qword ptr [rip + data_rva_243b8]\n" /* 019d8 */
        "    cmp qword ptr [r15 + rax*8 - 8], 0\n" /* 019df */
        S9_JE32(.Lblock_1aee) /* 019e5 */
        "    lea rax, [rdi + 8]\n" /* 019eb */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 019ef */
        "    lea rax, [rip + data_rva_1e010]\n" /* 019f4 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 019fb */
        "    mov rax, qword ptr [rsp + 0x2c8]\n" /* 01a00 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 01a08 */
        "    mov rax, qword ptr [rsp + 0x2c0]\n" /* 01a0d */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 01a15 */
        "    lea rax, [rip + data_rva_1e080]\n" /* 01a1a */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 01a21 */
        "    lea rax, [rip + data_rva_222c8]\n" /* 01a26 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 01a2d */
        "    lea rax, [rip + data_rva_222e8]\n" /* 01a32 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 01a39 */
        "    lea rax, [rip + data_rva_222f0]\n" /* 01a3e */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 01a45 */
        "    lea rcx, [rip + data_rva_22330]\n" /* 01a4a */
        "    lea rdx, [rip + data_rva_222e0]\n" /* 01a51 */
        "    lea r8, [rip + data_rva_222d8]\n" /* 01a58 */
        "    lea r9, [rip + data_rva_222f8]\n" /* 01a5f */
        "    call thunk_zereport_dll_ZREP_PRTAB2_rva_1530a\n" /* 01a66 */
        S9_JMP32(.Lblock_1b6e) /* 01a6b */
        ".Lblock_1a70:\n"
        "    mov r9, qword ptr [rip + iat_atdms_dll_DMS_RPTGLB_rva_19248]\n" /* 01a70 */
        "    add r9, 8\n" /* 01a77 */
        "    lea rcx, [rip + rdata_rva_19610]\n" /* 01a7b */
        "    lea rdx, [rip + rdata_rva_19628]\n" /* 01a82 */
        "    lea r8, [rip + data_rva_1e010]\n" /* 01a89 */
        "    call thunk_zereport_dll_ZREP_RPTHDR_rva_15310\n" /* 01a90 */
        "    mov qword ptr [rsp + 0x170], 0\n" /* 01a95 */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 01aa1 */
        "    mov edx, dword ptr [rax + 0x68]\n" /* 01aa8 */
        "    mov word ptr [rsp + 0x12c], 1\n" /* 01aab */
        "    lea rax, [rip + data_rva_1e244]\n" /* 01ab5 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 01abc */
        "    mov qword ptr [rsp + 0x20], 0\n" /* 01ac1 */
        "    lea rcx, [rsp + 0x170]\n" /* 01aca */
        "    movabs r8, 0x801208384ff00\n" /* 01ad2 */
        "    lea r9, [rsp + 0x12c]\n" /* 01adc */
        "    call thunk_libifcoremd_dll_for_write_seq_fmt_rva_153f4\n" /* 01ae4 */
        S9_JMP32(.Lblock_1ebb) /* 01ae9 */
        ".Lblock_1aee:\n"
        "    lea rax, [rdi + 8]\n" /* 01aee */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 01af2 */
        "    lea rax, [rip + data_rva_1e010]\n" /* 01af7 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 01afe */
        "    mov rax, qword ptr [rsp + 0x2c8]\n" /* 01b03 */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 01b0b */
        "    mov rax, qword ptr [rsp + 0x2c0]\n" /* 01b10 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 01b18 */
        "    lea rax, [rip + data_rva_1e080]\n" /* 01b1d */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 01b24 */
        "    lea rax, [rip + data_rva_222c8]\n" /* 01b29 */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 01b30 */
        "    lea rax, [rip + data_rva_222e8]\n" /* 01b35 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 01b3c */
        "    lea rax, [rip + data_rva_222f0]\n" /* 01b41 */
        "    mov qword ptr [rsp + 0x20], rax\n" /* 01b48 */
        "    lea rcx, [rip + data_rva_22330]\n" /* 01b4d */
        "    lea rdx, [rip + data_rva_222e0]\n" /* 01b54 */
        "    lea r8, [rip + data_rva_222d8]\n" /* 01b5b */
        "    lea r9, [rip + data_rva_222f8]\n" /* 01b62 */
        "    call thunk_zereport_dll_ZREP_PRTAB1_rva_15316\n" /* 01b69 */
        ".Lblock_1b6e:\n"
        "    mov rcx, qword ptr [rip + data_rva_223f8]\n" /* 01b6e */
        "    mov rax, qword ptr [rip + data_rva_223f0]\n" /* 01b75 */
        "    mov edx, eax\n" /* 01b7c */
        "    or edx, ecx\n" /* 01b7e */
        "    test dl, 1\n" /* 01b80 */
        S9_JE32(.Lblock_1ebb) /* 01b83 */
        "    mov rdx, qword ptr [rip + data_rva_24388]\n" /* 01b89 */
        "    mov rdx, qword ptr [r15 + rdx*8 - 8]\n" /* 01b90 */
        "    mov r8, qword ptr [rip + data_rva_24390]\n" /* 01b95 */
        "    mov r8, qword ptr [r15 + r8*8 - 8]\n" /* 01b9c */
        "    xor r9d, r9d\n" /* 01ba1 */
        "    cmp rdx, 3\n" /* 01ba4 */
        "    sete r9b\n" /* 01ba8 */
        "    neg r9\n" /* 01bac */
        "    mov qword ptr [rip + data_rva_223c0], r9\n" /* 01baf */
        "    xor r9d, r9d\n" /* 01bb6 */
        "    cmp rdx, 2\n" /* 01bb9 */
        "    sete r9b\n" /* 01bbd */
        "    neg r9\n" /* 01bc1 */
        "    mov qword ptr [rip + data_rva_223a8], r9\n" /* 01bc4 */
        "    xor edx, edx\n" /* 01bcb */
        "    cmp r8, 2\n" /* 01bcd */
        "    sete dl\n" /* 01bd1 */
        "    neg rdx\n" /* 01bd4 */
        "    mov qword ptr [rip + data_rva_223a0], rdx\n" /* 01bd7 */
        "    test cl, 1\n" /* 01bde */
        S9_JE32(.Lblock_1dba) /* 01be1 */
        "    add rdi, 8\n" /* 01be7 */
        "    lea rcx, [rip + rdata_rva_19620]\n" /* 01beb */
        "    lea rdx, [rip + rdata_rva_19628]\n" /* 01bf2 */
        "    lea r8, [rip + data_rva_1e010]\n" /* 01bf9 */
        "    mov r9, rdi\n" /* 01c00 */
        "    call thunk_zereport_dll_ZREP_RPTHDR_rva_15310\n" /* 01c03 */
        "    lea rax, [rip + data_rva_223c8]\n" /* 01c08 */
        "    mov qword ptr [rsp + 0x118], rax\n" /* 01c0f */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_RGLOB_rva_19288]\n" /* 01c17 */
        "    mov qword ptr [rsp + 0x110], rax\n" /* 01c1e */
        "    lea rax, [rip + data_rva_223a8]\n" /* 01c26 */
        "    mov qword ptr [rsp + 0x108], rax\n" /* 01c2d */
        "    lea rax, [rip + data_rva_223a0]\n" /* 01c35 */
        "    mov qword ptr [rsp + 0x100], rax\n" /* 01c3c */
        "    mov rax, qword ptr [rip + iat_atdms_dll_DMS_FLES_rva_19230]\n" /* 01c44 */
        "    add rax, 0x68\n" /* 01c4b */
        "    mov qword ptr [rsp + 0xf8], rax\n" /* 01c4f */
        "    lea rax, [rip + data_rva_22398]\n" /* 01c57 */
        "    mov qword ptr [rsp + 0xf0], rax\n" /* 01c5e */
        "    lea rax, [rip + data_rva_1e070]\n" /* 01c66 */
        "    mov qword ptr [rsp + 0xe8], rax\n" /* 01c6d */
        "    lea rax, [rip + data_rva_22370]\n" /* 01c75 */
        "    mov qword ptr [rsp + 0xe0], rax\n" /* 01c7c */
        "    lea rcx, [rip + data_rva_1e050]\n" /* 01c84 */
        "    mov qword ptr [rsp + 0xd8], rcx\n" /* 01c8b */
        "    lea rax, [rip + data_rva_22378]\n" /* 01c93 */
        "    mov qword ptr [rsp + 0xd0], rax\n" /* 01c9a */
        "    mov qword ptr [rsp + 0xc8], rcx\n" /* 01ca2 */
        "    lea rax, [rip + data_rva_22380]\n" /* 01caa */
        "    mov qword ptr [rsp + 0xc0], rax\n" /* 01cb1 */
        "    mov qword ptr [rsp + 0xb8], rcx\n" /* 01cb9 */
        "    lea rax, [rip + data_rva_22388]\n" /* 01cc1 */
        "    mov qword ptr [rsp + 0xb0], rax\n" /* 01cc8 */
        "    mov qword ptr [rsp + 0xa8], rcx\n" /* 01cd0 */
        "    lea rax, [rip + data_rva_22390]\n" /* 01cd8 */
        "    mov qword ptr [rsp + 0xa0], rax\n" /* 01cdf */
        "    mov qword ptr [rsp + 0x98], rcx\n" /* 01ce7 */
        "    lea rax, [rip + rdata_rva_19638]\n" /* 01cef */
        "    mov qword ptr [rsp + 0x90], rax\n" /* 01cf6 */
        "    lea rax, [rip + data_rva_1e0c0]\n" /* 01cfe */
        "    mov qword ptr [rsp + 0x88], rax\n" /* 01d05 */
        "    lea rax, [rip + rdata_rva_19630]\n" /* 01d0d */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 01d14 */
        "    lea rcx, [rip + data_rva_1e080]\n" /* 01d1c */
        "    mov qword ptr [rsp + 0x78], rcx\n" /* 01d23 */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 01d28 */
        "    lea rax, [rip + data_rva_1e0a0]\n" /* 01d2d */
        "    mov qword ptr [rsp + 0x68], rax\n" /* 01d34 */
        "    lea rax, [rip + data_rva_1e058]\n" /* 01d39 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 01d40 */
        "    lea rax, [rip + data_rva_1e060]\n" /* 01d45 */
        "    mov qword ptr [rsp + 0x58], rax\n" /* 01d4c */
        "    lea rax, [rip + data_rva_1e068]\n" /* 01d51 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 01d58 */
        "    lea rax, [rip + data_rva_223b0]\n" /* 01d5d */
        "    mov qword ptr [rsp + 0x48], rax\n" /* 01d64 */
        "    lea rax, [rip + data_rva_223b8]\n" /* 01d69 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 01d70 */
        "    mov qword ptr [rsp + 0x38], rbx\n" /* 01d75 */
        "    mov qword ptr [rsp + 0x30], r14\n" /* 01d7a */
        "    lea rax, [rip + data_rva_223c0]\n" /* 01d7f */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 01d86 */
        "    mov qword ptr [rsp + 0x20], rsi\n" /* 01d8b */
        "    lea r8, [rip + data_rva_22318]\n" /* 01d90 */
        "    lea r9, [rip + data_rva_1e018]\n" /* 01d97 */
        "    mov rcx, qword ptr [rsp + 0x2a8]\n" /* 01d9e */
        "    mov rdx, qword ptr [rsp + 0x2b0]\n" /* 01da6 */
        "    call thunk_zereport_dll_ZREP_PLEXEC_rva_1531c\n" /* 01dae */
        "    mov rax, qword ptr [rip + data_rva_223f0]\n" /* 01db3 */
        ".Lblock_1dba:\n"
        "    test al, 1\n" /* 01dba */
        S9_JE32(.Lblock_1ebb) /* 01dbc */
        "    lea rax, [rip + data_rva_223c8]\n" /* 01dc2 */
        "    mov qword ptr [rsp + 0xb0], rax\n" /* 01dc9 */
        "    lea rax, [rip + data_rva_1e008]\n" /* 01dd1 */
        "    mov qword ptr [rsp + 0xa8], rax\n" /* 01dd8 */
        "    lea rax, [rip + data_rva_1e000]\n" /* 01de0 */
        "    mov qword ptr [rsp + 0xa0], rax\n" /* 01de7 */
        "    mov rax, qword ptr [rsp + 0x2b0]\n" /* 01def */
        "    mov qword ptr [rsp + 0x98], rax\n" /* 01df7 */
        "    mov rax, qword ptr [rsp + 0x2a8]\n" /* 01dff */
        "    mov qword ptr [rsp + 0x90], rax\n" /* 01e07 */
        "    lea rcx, [rip + data_rva_1e050]\n" /* 01e0f */
        "    mov qword ptr [rsp + 0x88], rcx\n" /* 01e16 */
        "    lea rax, [rip + data_rva_22370]\n" /* 01e1e */
        "    mov qword ptr [rsp + 0x80], rax\n" /* 01e25 */
        "    mov qword ptr [rsp + 0x78], rcx\n" /* 01e2d */
        "    lea rax, [rip + data_rva_22378]\n" /* 01e32 */
        "    mov qword ptr [rsp + 0x70], rax\n" /* 01e39 */
        "    mov qword ptr [rsp + 0x68], rcx\n" /* 01e3e */
        "    lea rax, [rip + data_rva_22380]\n" /* 01e43 */
        "    mov qword ptr [rsp + 0x60], rax\n" /* 01e4a */
        "    mov qword ptr [rsp + 0x58], rcx\n" /* 01e4f */
        "    lea rax, [rip + data_rva_22388]\n" /* 01e54 */
        "    mov qword ptr [rsp + 0x50], rax\n" /* 01e5b */
        "    mov qword ptr [rsp + 0x48], rcx\n" /* 01e60 */
        "    lea rax, [rip + data_rva_22390]\n" /* 01e65 */
        "    mov qword ptr [rsp + 0x40], rax\n" /* 01e6c */
        "    lea rax, [rip + data_rva_1e0c0]\n" /* 01e71 */
        "    mov qword ptr [rsp + 0x38], rax\n" /* 01e78 */
        "    lea rax, [rip + rdata_rva_19638]\n" /* 01e7d */
        "    mov qword ptr [rsp + 0x30], rax\n" /* 01e84 */
        "    lea rax, [rip + data_rva_1e080]\n" /* 01e89 */
        "    mov qword ptr [rsp + 0x28], rax\n" /* 01e90 */
        "    lea r8, [rip + rdata_rva_19630]\n" /* 01e95 */
        "    mov qword ptr [rsp + 0x20], r8\n" /* 01e9c */
        "    lea rcx, [rip + data_rva_1e018]\n" /* 01ea1 */
        "    lea rdx, [rip + data_rva_22318]\n" /* 01ea8 */
        "    lea r9, [rip + data_rva_1e0a0]\n" /* 01eaf */
        "    call thunk_zereport_dll_ZREP_PLFILE_rva_15322\n" /* 01eb6 */
        ".Lblock_1ebb:\n"
        "    movaps xmm6, xmmword ptr [rsp + 0x1a0]\n" /* 01ebb */
        "    movaps xmm7, xmmword ptr [rsp + 0x1b0]\n" /* 01ec3 */
        "    movaps xmm8, xmmword ptr [rsp + 0x1c0]\n" /* 01ecb */
        "    movaps xmm9, xmmword ptr [rsp + 0x1d0]\n" /* 01ed4 */
        "    movaps xmm10, xmmword ptr [rsp + 0x1e0]\n" /* 01edd */
        "    movaps xmm11, xmmword ptr [rsp + 0x1f0]\n" /* 01ee6 */
        "    movaps xmm12, xmmword ptr [rsp + 0x200]\n" /* 01eef */
        "    movaps xmm13, xmmword ptr [rsp + 0x210]\n" /* 01ef8 */
        "    movaps xmm14, xmmword ptr [rsp + 0x220]\n" /* 01f01 */
        "    add rsp, 0x238\n" /* 01f0a */
        "    pop rbx\n" /* 01f11 */
        "    pop rbp\n" /* 01f12 */
        "    pop rdi\n" /* 01f13 */
        "    pop rsi\n" /* 01f14 */
        "    pop r12\n" /* 01f15 */
        "    pop r13\n" /* 01f17 */
        "    pop r14\n" /* 01f19 */
        "    pop r15\n" /* 01f1b */
        "    ret\n" /* 01f1d */
        END);
}
