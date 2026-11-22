/* zedstwu.dll, Windows AMD64. The labels and table entries may be edited and reassembled. */
#include "copy-encoding.h"

/* Size-dependent copy selected by the feature mask 0x9d9fee. */
__attribute__((naked,used)) void *copy_avx(void *dst, const void *src, unsigned long long size) {
    __asm__(".intel_syntax noprefix\n"
        /* Source and destination arrive in RDX and RCX. R8 is the byte count. Preserve the return pointer in RAX. */
        ".Lcopy_avx:\n"
        "push r14\n" /* cd80 */
        "push rsi\n" /* cd82 */
        "push rdi\n" /* cd83 */
        "push rbx\n" /* cd84 */
        "mov rax, rcx\n" /* cd85 */
        "mov r10, rcx\n" /* cd88 */
        "cmp r8, 0x100\n" /* cd8b */
        "ja .Lalign_destination\n" /* cd92 */
        "lea r9, [rip + .Lsmall_offsets]\n" /* cd94 */
        "sub r9, qword ptr [r9 + r8*8]\n" /* cd9b */
        "notrack jmp r9\n" /* cd9f */
        PAD_666666662E0F1F840000000000 /* cda3 */
        /* For copies over 256 bytes, copy the prefix required for a 32-byte-aligned destination. */
        ".Lalign_destination:\n"
        "lea r9, [rip + .Lprefix_offsets]\n" /* cdb0 */
        "mov r14, r10\n" /* cdb7 */
        "and r14, 0x1f\n" /* cdba */
        "je .Lselect_bulk_copy\n" /* cdbe */
        "neg r14\n" /* cdc0 */
        "add r14, 0x20\n" /* cdc3 */
        "sub r8, r14\n" /* cdc7 */
        "mov r11, r10\n" /* cdca */
        "add r11, r14\n" /* cdcd */
        "mov rbx, rdx\n" /* cdd0 */
        "add rbx, r14\n" /* cdd3 */
        "sub r9, qword ptr [r9 + r14*8]\n" /* cdd6 */
        "notrack jmp r9\n" /* cdda */
        PAD_6690 /* cdde */
        ".Ladvance_prefix:\n"
        "add r10, r14\n" /* cde0 */
        "add rdx, r14\n" /* cde3 */
        /* Compare remaining bytes against 256, then against three quarters of the shared size value. */
        ".Lselect_bulk_copy:\n"
        "cmp r8, 0x100\n" /* cde6 */
        LONG_JL(.Lselect_tail) /* cded */
        "mov r9, qword ptr [rip + shared_size_rva_22248]\n" /* cdf3 */
        "mov r14, r9\n" /* cdfa */
        "shr r9, 2\n" /* cdfd */
        "sub r14, r9\n" /* ce01 */
        "cmp r8, r14\n" /* ce04 */
        LONG_JAE(.Lcase_ceb0) /* ce07 */
        PAD_0F1F00 /* ce0d */
        /* Copy eight 32-byte vectors per iteration with cached aligned stores. */
        ".Lcopy_cached_256:\n"
        "vmovdqu ymm1, ymmword ptr [rdx]\n" /* ce10 */
        "vmovdqu ymm2, ymmword ptr [rdx + 0x20]\n" /* ce14 */
        "vmovdqu ymm3, ymmword ptr [rdx + 0x40]\n" /* ce19 */
        "vmovdqu ymm4, ymmword ptr [rdx + 0x60]\n" /* ce1e */
        "vmovdqa ymmword ptr [r10], ymm1\n" /* ce23 */
        "vmovdqa ymmword ptr [r10 + 0x20], ymm2\n" /* ce28 */
        "vmovdqa ymmword ptr [r10 + 0x40], ymm3\n" /* ce2e */
        "vmovdqa ymmword ptr [r10 + 0x60], ymm4\n" /* ce34 */
        "vmovdqu ymm1, ymmword ptr [rdx + 0x80]\n" /* ce3a */
        "vmovdqu ymm2, ymmword ptr [rdx + 0xa0]\n" /* ce42 */
        "vmovdqu ymm3, ymmword ptr [rdx + 0xc0]\n" /* ce4a */
        "vmovdqu ymm4, ymmword ptr [rdx + 0xe0]\n" /* ce52 */
        "vmovdqa ymmword ptr [r10 + 0x80], ymm1\n" /* ce5a */
        "vmovdqa ymmword ptr [r10 + 0xa0], ymm2\n" /* ce63 */
        "vmovdqa ymmword ptr [r10 + 0xc0], ymm3\n" /* ce6c */
        "vmovdqa ymmword ptr [r10 + 0xe0], ymm4\n" /* ce75 */
        "add r10, 0x100\n" /* ce7e */
        "add rdx, 0x100\n" /* ce85 */
        "sub r8, 0x100\n" /* ce8c */
        "cmp r8, 0x100\n" /* ce93 */
        LONG_JAE(.Lcopy_cached_256) /* ce9a */
        LONG_JMP(.Lselect_tail) /* cea0 */
        PAD_66662E0F1F840000000000 /* cea5 */
        /* Use REP MOVSB below the second shared threshold. Otherwise enter the streaming store loop. */
        ".Lcase_ceb0:\n"
        "cmp r8, qword ptr [rip + stream_threshold_rva_22238]\n" /* ceb0 */
        "jae .Lcopy_streaming_256\n" /* ceb7 */
        PAD_0F1F8000000000 /* ceb9 */
        "mov rdi, r10\n" /* cec0 */
        "mov rsi, rdx\n" /* cec3 */
        "mov rcx, r8\n" /* cec6 */
        "rep movsb byte ptr [rdi], byte ptr [rsi]\n" /* cec9 */
        LONG_JMP(.Lcopy_return) /* cecb */
        /* Prefetch 512 to 704 bytes ahead. Issue non-temporal stores and fence before returning to cached stores. */
        ".Lcopy_streaming_256:\n"
        "prefetcht0 byte ptr [rdx + 0x200]\n" /* ced0 */
        "prefetcht0 byte ptr [rdx + 0x240]\n" /* ced7 */
        "prefetcht0 byte ptr [rdx + 0x280]\n" /* cede */
        "prefetcht0 byte ptr [rdx + 0x2c0]\n" /* cee5 */
        "vmovdqu ymm1, ymmword ptr [rdx]\n" /* ceec */
        "vmovdqu ymm2, ymmword ptr [rdx + 0x20]\n" /* cef0 */
        "vmovdqu ymm3, ymmword ptr [rdx + 0x40]\n" /* cef5 */
        "vmovdqu ymm4, ymmword ptr [rdx + 0x60]\n" /* cefa */
        "vmovntdq ymmword ptr [r10], ymm1\n" /* ceff */
        "vmovntdq ymmword ptr [r10 + 0x20], ymm2\n" /* cf04 */
        "vmovntdq ymmword ptr [r10 + 0x40], ymm3\n" /* cf0a */
        "vmovntdq ymmword ptr [r10 + 0x60], ymm4\n" /* cf10 */
        "sub r8, 0x100\n" /* cf16 */
        "vmovdqu ymm1, ymmword ptr [rdx + 0x80]\n" /* cf1d */
        "vmovdqu ymm2, ymmword ptr [rdx + 0xa0]\n" /* cf25 */
        "vmovdqu ymm3, ymmword ptr [rdx + 0xc0]\n" /* cf2d */
        "vmovdqu ymm4, ymmword ptr [rdx + 0xe0]\n" /* cf35 */
        "vmovntdq ymmword ptr [r10 + 0x80], ymm1\n" /* cf3d */
        "vmovntdq ymmword ptr [r10 + 0xa0], ymm2\n" /* cf46 */
        "vmovntdq ymmword ptr [r10 + 0xc0], ymm3\n" /* cf4f */
        "vmovntdq ymmword ptr [r10 + 0xe0], ymm4\n" /* cf58 */
        "lea r10, [r10 + 0x100]\n" /* cf61 */
        "lea rdx, [rdx + 0x100]\n" /* cf68 */
        "cmp r8, 0x300\n" /* cf6f */
        LONG_JGE(.Lcopy_streaming_256) /* cf76 */
        "sfence\n" /* cf7c */
        LONG_JMP(.Lcopy_cached_256) /* cf7f */
        PAD_6666662E0F1F840000000000 /* cf84 */
        ".Lcase_cf90:\n"
        "mov r9b, byte ptr [rdx]\n" /* cf90 */
        "mov byte ptr [r10], r9b\n" /* cf93 */
        ".Lcase_cf96:\n"
        LONG_JMP(.Ladvance_prefix) /* cf96 */
        PAD_0F1F440000 /* cf9b */
        ".Lcase_cfa0:\n"
        "mov r9w, word ptr [rdx]\n" /* cfa0 */
        "mov word ptr [r10], r9w\n" /* cfa4 */
        LONG_JMP(.Ladvance_prefix) /* cfa8 */
        PAD_0F1F00 /* cfad */
        ".Lcase_cfb0:\n"
        "mov r9w, word ptr [rdx]\n" /* cfb0 */
        "mov word ptr [r10], r9w\n" /* cfb4 */
        "mov r9b, byte ptr [rdx + 2]\n" /* cfb8 */
        "mov byte ptr [r10 + 2], r9b\n" /* cfbc */
        LONG_JMP(.Ladvance_prefix) /* cfc0 */
        PAD_66662E0F1F840000000000 /* cfc5 */
        ".Lcase_cfd0:\n"
        "mov r9d, dword ptr [rdx]\n" /* cfd0 */
        "mov dword ptr [r10], r9d\n" /* cfd3 */
        LONG_JMP(.Ladvance_prefix) /* cfd6 */
        PAD_0F1F440000 /* cfdb */
        ".Lcase_cfe0:\n"
        "mov r9d, dword ptr [rdx]\n" /* cfe0 */
        "mov dword ptr [r10], r9d\n" /* cfe3 */
        "mov r9d, dword ptr [rbx - 4]\n" /* cfe6 */
        "mov dword ptr [r11 - 4], r9d\n" /* cfea */
        LONG_JMP(.Ladvance_prefix) /* cfee */
        PAD_666666662E0F1F840000000000 /* cff3 */
        ".Lcase_d000:\n"
        "mov r9, qword ptr [rdx]\n" /* d000 */
        "mov qword ptr [r10], r9\n" /* d003 */
        LONG_JMP(.Ladvance_prefix) /* d006 */
        PAD_0F1F440000 /* d00b */
        ".Lcase_d010:\n"
        "mov r9, qword ptr [rdx]\n" /* d010 */
        "mov qword ptr [r10], r9\n" /* d013 */
        "mov r9, qword ptr [rbx - 8]\n" /* d016 */
        "mov qword ptr [r11 - 8], r9\n" /* d01a */
        LONG_JMP(.Ladvance_prefix) /* d01e */
        PAD_666666662E0F1F840000000000 /* d023 */
        ".Lcase_d030:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* d030 */
        "vmovups xmmword ptr [r10], xmm0\n" /* d034 */
        LONG_JMP(.Ladvance_prefix) /* d039 */
        PAD_6690 /* d03e */
        ".Lcase_d040:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* d040 */
        "vmovups xmmword ptr [r10], xmm0\n" /* d044 */
        "vmovups xmm0, xmmword ptr [rbx - 0x10]\n" /* d049 */
        "vmovups xmmword ptr [r11 - 0x10], xmm0\n" /* d04e */
        LONG_JMP(.Ladvance_prefix) /* d054 */
        PAD_0F1F8000000000 /* d059 */
        /* Move both pointers to the end, align the destination backwards, then dispatch the remainder. */
        ".Lselect_tail:\n"
        "add r10, r8\n" /* d060 */
        "mov r11, r10\n" /* d063 */
        "mov r14, r11\n" /* d066 */
        "and r10, 0xffffffffffffffe0\n" /* d069 */
        "add rdx, r8\n" /* d06d */
        "mov rbx, rdx\n" /* d070 */
        "sub r14, r10\n" /* d073 */
        "sub rdx, r14\n" /* d076 */
        "lea r9, [rip + .Ltail_offsets]\n" /* d079 */
        "sub r9, qword ptr [r9 + r8*8]\n" /* d080 */
        "notrack jmp r9\n" /* d084 */
        PAD_0F1F840000000000 /* d088 */
        ".Lcase_d090:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0xe0]\n" /* d090 */
        "vmovaps ymmword ptr [r10 - 0xe0], ymm0\n" /* d098 */
        ".Lcase_d0a1:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0xc0]\n" /* d0a1 */
        "vmovaps ymmword ptr [r10 - 0xc0], ymm0\n" /* d0a9 */
        ".Lcase_d0b2:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0xa0]\n" /* d0b2 */
        "vmovaps ymmword ptr [r10 - 0xa0], ymm0\n" /* d0ba */
        ".Lcase_d0c3:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0x80]\n" /* d0c3 */
        "vmovaps ymmword ptr [r10 - 0x80], ymm0\n" /* d0c8 */
        ".Lcase_d0ce:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0x60]\n" /* d0ce */
        "vmovaps ymmword ptr [r10 - 0x60], ymm0\n" /* d0d3 */
        ".Lcase_d0d9:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0x40]\n" /* d0d9 */
        "vmovaps ymmword ptr [r10 - 0x40], ymm0\n" /* d0de */
        ".Lcase_d0e4:\n"
        "vmovups ymm0, ymmword ptr [rdx - 0x20]\n" /* d0e4 */
        "vmovaps ymmword ptr [r10 - 0x20], ymm0\n" /* d0e9 */
        "lea r9, [rip + .Ltail_offsets]\n" /* d0ef */
        "mov r8, r14\n" /* d0f6 */
        "sub r9, qword ptr [r9 + r14*8]\n" /* d0f9 */
        "notrack jmp r9\n" /* d0fd */
        PAD_6666666666662E0F1F840000000000 /* d101 */
        /* Small copy cases share endings. First and last loads may overlap. */
        ".Lcase_d110:\n"
        "mov r9b, byte ptr [rdx]\n" /* d110 */
        "mov byte ptr [r10], r9b\n" /* d113 */
        LONG_JMP(.Lcopy_return) /* d116 */
        PAD_0F1F440000 /* d11b */
        ".Lcase_d120:\n"
        LONG_JMP(.Lcopy_return) /* d120 */
        PAD_66662E0F1F840000000000 /* d125 */
        ".Lcase_d130:\n"
        "mov r9w, word ptr [rdx]\n" /* d130 */
        "mov word ptr [r10], r9w\n" /* d134 */
        LONG_JMP(.Lcopy_return) /* d138 */
        PAD_0F1F00 /* d13d */
        ".Lcase_d140:\n"
        "mov r9w, word ptr [rdx]\n" /* d140 */
        "mov word ptr [r10], r9w\n" /* d144 */
        "mov r9b, byte ptr [rdx + 2]\n" /* d148 */
        "mov byte ptr [r10 + 2], r9b\n" /* d14c */
        LONG_JMP(.Lcopy_return) /* d150 */
        PAD_66662E0F1F840000000000 /* d155 */
        ".Lcase_d160:\n"
        "mov r9d, dword ptr [rdx]\n" /* d160 */
        "mov dword ptr [r10], r9d\n" /* d163 */
        LONG_JMP(.Lcopy_return) /* d166 */
        PAD_0F1F440000 /* d16b */
        ".Lcase_d170:\n"
        "mov r9d, dword ptr [rdx]\n" /* d170 */
        "mov dword ptr [r10], r9d\n" /* d173 */
        "mov r9d, dword ptr [rdx + r8 - 4]\n" /* d176 */
        "mov dword ptr [r10 + r8 - 4], r9d\n" /* d17b */
        LONG_JMP(.Lcopy_return) /* d180 */
        PAD_66662E0F1F840000000000 /* d185 */
        ".Lcase_d190:\n"
        "mov r9, qword ptr [rdx]\n" /* d190 */
        "mov qword ptr [r10], r9\n" /* d193 */
        LONG_JMP(.Lcopy_return) /* d196 */
        PAD_0F1F440000 /* d19b */
        ".Lcase_d1a0:\n"
        "mov r9, qword ptr [rdx]\n" /* d1a0 */
        "mov qword ptr [r10], r9\n" /* d1a3 */
        "mov r9, qword ptr [rdx + r8 - 8]\n" /* d1a6 */
        "mov qword ptr [r10 + r8 - 8], r9\n" /* d1ab */
        LONG_JMP(.Lcopy_return) /* d1b0 */
        PAD_66662E0F1F840000000000 /* d1b5 */
        ".Lcase_d1c0:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* d1c0 */
        "vmovups xmmword ptr [r10], xmm0\n" /* d1c4 */
        LONG_JMP(.Lcopy_return) /* d1c9 */
        PAD_6690 /* d1ce */
        ".Lcase_d1d0:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* d1d0 */
        "vmovups xmmword ptr [r10], xmm0\n" /* d1d4 */
        "vmovups xmm0, xmmword ptr [rdx + r8 - 0x10]\n" /* d1d9 */
        "vmovups xmmword ptr [r10 + r8 - 0x10], xmm0\n" /* d1e0 */
        LONG_JMP(.Lcopy_return) /* d1e7 */
        PAD_0F1F4000 /* d1ec */
        ".Lcase_d1f0:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d1f0 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d1f4 */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d1f9 */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d200 */
        LONG_JMP(.Lcopy_return) /* d207 */
        PAD_0F1F4000 /* d20c */
        ".Lcase_d210:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d210 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d214 */
        "vmovups ymm0, ymmword ptr [rdx + 0x20]\n" /* d219 */
        "vmovups ymmword ptr [r10 + 0x20], ymm0\n" /* d21e */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d224 */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d22b */
        LONG_JMP(.Lcopy_return) /* d232 */
        PAD_660F1F840000000000 /* d237 */
        ".Lcase_d240:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d240 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d244 */
        "vmovups ymm0, ymmword ptr [rdx + 0x20]\n" /* d249 */
        "vmovups ymmword ptr [r10 + 0x20], ymm0\n" /* d24e */
        "vmovups ymm0, ymmword ptr [rdx + 0x40]\n" /* d254 */
        "vmovups ymmword ptr [r10 + 0x40], ymm0\n" /* d259 */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d25f */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d266 */
        LONG_JMP(.Lcopy_return) /* d26d */
        PAD_66666666662E0F1F840000000000 /* d272 */
        ".Lcase_d280:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d280 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d284 */
        "vmovups ymm0, ymmword ptr [rdx + 0x20]\n" /* d289 */
        "vmovups ymmword ptr [r10 + 0x20], ymm0\n" /* d28e */
        "vmovups ymm0, ymmword ptr [rdx + 0x40]\n" /* d294 */
        "vmovups ymmword ptr [r10 + 0x40], ymm0\n" /* d299 */
        "vmovups ymm0, ymmword ptr [rdx + 0x60]\n" /* d29f */
        "vmovups ymmword ptr [r10 + 0x60], ymm0\n" /* d2a4 */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d2aa */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d2b1 */
        LONG_JMP(.Lcopy_return) /* d2b8 */
        PAD_0F1F00 /* d2bd */
        ".Lcase_d2c0:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d2c0 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d2c4 */
        "vmovups ymm0, ymmword ptr [rdx + 0x20]\n" /* d2c9 */
        "vmovups ymmword ptr [r10 + 0x20], ymm0\n" /* d2ce */
        "vmovups ymm0, ymmword ptr [rdx + 0x40]\n" /* d2d4 */
        "vmovups ymmword ptr [r10 + 0x40], ymm0\n" /* d2d9 */
        "vmovups ymm0, ymmword ptr [rdx + 0x60]\n" /* d2df */
        "vmovups ymmword ptr [r10 + 0x60], ymm0\n" /* d2e4 */
        "vmovups ymm0, ymmword ptr [rdx + 0x80]\n" /* d2ea */
        "vmovups ymmword ptr [r10 + 0x80], ymm0\n" /* d2f2 */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d2fb */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d302 */
        LONG_JMP(.Lcopy_return) /* d309 */
        PAD_6690 /* d30e */
        ".Lcase_d310:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d310 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d314 */
        "vmovups ymm0, ymmword ptr [rdx + 0x20]\n" /* d319 */
        "vmovups ymmword ptr [r10 + 0x20], ymm0\n" /* d31e */
        "vmovups ymm0, ymmword ptr [rdx + 0x40]\n" /* d324 */
        "vmovups ymmword ptr [r10 + 0x40], ymm0\n" /* d329 */
        "vmovups ymm0, ymmword ptr [rdx + 0x60]\n" /* d32f */
        "vmovups ymmword ptr [r10 + 0x60], ymm0\n" /* d334 */
        "vmovups ymm0, ymmword ptr [rdx + 0x80]\n" /* d33a */
        "vmovups ymmword ptr [r10 + 0x80], ymm0\n" /* d342 */
        "vmovups ymm0, ymmword ptr [rdx + 0xa0]\n" /* d34b */
        "vmovups ymmword ptr [r10 + 0xa0], ymm0\n" /* d353 */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d35c */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d363 */
        LONG_JMP(.Lcopy_return) /* d36a */
        PAD_90 /* d36f */
        ".Lcase_d370:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* d370 */
        "vmovups ymmword ptr [r10], ymm0\n" /* d374 */
        "vmovups ymm0, ymmword ptr [rdx + 0x20]\n" /* d379 */
        "vmovups ymmword ptr [r10 + 0x20], ymm0\n" /* d37e */
        "vmovups ymm0, ymmword ptr [rdx + 0x40]\n" /* d384 */
        "vmovups ymmword ptr [r10 + 0x40], ymm0\n" /* d389 */
        "vmovups ymm0, ymmword ptr [rdx + 0x60]\n" /* d38f */
        "vmovups ymmword ptr [r10 + 0x60], ymm0\n" /* d394 */
        "vmovups ymm0, ymmword ptr [rdx + 0x80]\n" /* d39a */
        "vmovups ymmword ptr [r10 + 0x80], ymm0\n" /* d3a2 */
        "vmovups ymm0, ymmword ptr [rdx + 0xa0]\n" /* d3ab */
        "vmovups ymmword ptr [r10 + 0xa0], ymm0\n" /* d3b3 */
        "vmovups ymm0, ymmword ptr [rdx + 0xc0]\n" /* d3bc */
        "vmovups ymmword ptr [r10 + 0xc0], ymm0\n" /* d3c4 */
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d3cd */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d3d4 */
        LONG_JMP(.Lcopy_return) /* d3db */
        ".Lcase_d3e0:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x100]\n" /* d3e0 */
        "vmovups ymmword ptr [r10 + r8 - 0x100], ymm0\n" /* d3ea */
        ".Lcase_d3f4:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0xe0]\n" /* d3f4 */
        "vmovups ymmword ptr [r10 + r8 - 0xe0], ymm0\n" /* d3fe */
        ".Lcase_d408:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0xc0]\n" /* d408 */
        "vmovups ymmword ptr [r10 + r8 - 0xc0], ymm0\n" /* d412 */
        ".Lcase_d41c:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0xa0]\n" /* d41c */
        "vmovups ymmword ptr [r10 + r8 - 0xa0], ymm0\n" /* d426 */
        ".Lcase_d430:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x80]\n" /* d430 */
        "vmovups ymmword ptr [r10 + r8 - 0x80], ymm0\n" /* d437 */
        ".Lcase_d43e:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x60]\n" /* d43e */
        "vmovups ymmword ptr [r10 + r8 - 0x60], ymm0\n" /* d445 */
        ".Lcase_d44c:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x40]\n" /* d44c */
        "vmovups ymmword ptr [r10 + r8 - 0x40], ymm0\n" /* d453 */
        ".Lcase_d45a:\n"
        "vmovups ymm0, ymmword ptr [rdx + r8 - 0x20]\n" /* d45a */
        "vmovups ymmword ptr [r10 + r8 - 0x20], ymm0\n" /* d461 */
        LONG_JMP(.Lcopy_return) /* d468 */
        PAD_0F1F00 /* d46d */
        /* 32 offsets. The dispatcher subtracts the indexed entry from the table base. */
        ".Lprefix_offsets:\n"
        ".quad .Lprefix_offsets - .Lcase_cf96\n" /* indices 0..0 */
        ".quad .Lprefix_offsets - .Lcase_cf90\n" /* indices 1..1 */
        ".quad .Lprefix_offsets - .Lcase_cfa0\n" /* indices 2..2 */
        ".quad .Lprefix_offsets - .Lcase_cfb0\n" /* indices 3..3 */
        ".quad .Lprefix_offsets - .Lcase_cfd0\n" /* indices 4..4 */
        ".rept 3\n.quad .Lprefix_offsets - .Lcase_cfe0\n.endr\n" /* indices 5..7 */
        ".quad .Lprefix_offsets - .Lcase_d000\n" /* indices 8..8 */
        ".rept 7\n.quad .Lprefix_offsets - .Lcase_d010\n.endr\n" /* indices 9..15 */
        ".quad .Lprefix_offsets - .Lcase_d030\n" /* indices 16..16 */
        ".rept 15\n.quad .Lprefix_offsets - .Lcase_d040\n.endr\n" /* indices 17..31 */
        /* 256 offsets. The dispatcher subtracts the indexed entry from the table base. */
        ".Ltail_offsets:\n"
        ".quad .Ltail_offsets - .Lcase_d120\n" /* indices 0..0 */
        ".quad .Ltail_offsets - .Lcase_d110\n" /* indices 1..1 */
        ".quad .Ltail_offsets - .Lcase_d130\n" /* indices 2..2 */
        ".quad .Ltail_offsets - .Lcase_d140\n" /* indices 3..3 */
        ".quad .Ltail_offsets - .Lcase_d160\n" /* indices 4..4 */
        ".rept 3\n.quad .Ltail_offsets - .Lcase_d170\n.endr\n" /* indices 5..7 */
        ".quad .Ltail_offsets - .Lcase_d190\n" /* indices 8..8 */
        ".rept 7\n.quad .Ltail_offsets - .Lcase_d1a0\n.endr\n" /* indices 9..15 */
        ".quad .Ltail_offsets - .Lcase_d1c0\n" /* indices 16..16 */
        ".rept 15\n.quad .Ltail_offsets - .Lcase_d1d0\n.endr\n" /* indices 17..31 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d0e4\n.endr\n" /* indices 32..63 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d0d9\n.endr\n" /* indices 64..95 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d0ce\n.endr\n" /* indices 96..127 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d0c3\n.endr\n" /* indices 128..159 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d0b2\n.endr\n" /* indices 160..191 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d0a1\n.endr\n" /* indices 192..223 */
        ".rept 32\n.quad .Ltail_offsets - .Lcase_d090\n.endr\n" /* indices 224..255 */
        /* 257 offsets. The dispatcher subtracts the indexed entry from the table base. */
        ".Lsmall_offsets:\n"
        ".quad .Lsmall_offsets - .Lcase_d120\n" /* indices 0..0 */
        ".quad .Lsmall_offsets - .Lcase_d110\n" /* indices 1..1 */
        ".quad .Lsmall_offsets - .Lcase_d130\n" /* indices 2..2 */
        ".quad .Lsmall_offsets - .Lcase_d140\n" /* indices 3..3 */
        ".quad .Lsmall_offsets - .Lcase_d160\n" /* indices 4..4 */
        ".rept 3\n.quad .Lsmall_offsets - .Lcase_d170\n.endr\n" /* indices 5..7 */
        ".quad .Lsmall_offsets - .Lcase_d190\n" /* indices 8..8 */
        ".rept 7\n.quad .Lsmall_offsets - .Lcase_d1a0\n.endr\n" /* indices 9..15 */
        ".quad .Lsmall_offsets - .Lcase_d1c0\n" /* indices 16..16 */
        ".rept 15\n.quad .Lsmall_offsets - .Lcase_d1d0\n.endr\n" /* indices 17..31 */
        ".quad .Lsmall_offsets - .Lcase_d45a\n" /* indices 32..32 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d1f0\n.endr\n" /* indices 33..63 */
        ".quad .Lsmall_offsets - .Lcase_d44c\n" /* indices 64..64 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d210\n.endr\n" /* indices 65..95 */
        ".quad .Lsmall_offsets - .Lcase_d43e\n" /* indices 96..96 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d240\n.endr\n" /* indices 97..127 */
        ".quad .Lsmall_offsets - .Lcase_d430\n" /* indices 128..128 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d280\n.endr\n" /* indices 129..159 */
        ".quad .Lsmall_offsets - .Lcase_d41c\n" /* indices 160..160 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d2c0\n.endr\n" /* indices 161..191 */
        ".quad .Lsmall_offsets - .Lcase_d408\n" /* indices 192..192 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d310\n.endr\n" /* indices 193..223 */
        ".quad .Lsmall_offsets - .Lcase_d3f4\n" /* indices 224..224 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_d370\n.endr\n" /* indices 225..255 */
        ".quad .Lsmall_offsets - .Lcase_d3e0\n" /* indices 256..256 */
        PAD_0F1F840000000000 /* e578 */
        /* Clear upper vector lanes, restore the four nonvolatile registers and return the original destination. */
        ".Lcopy_return:\n"
        "vzeroupper\n" /* e580 */
        "pop rbx\n" /* e583 */
        "pop rdi\n" /* e584 */
        "pop rsi\n" /* e585 */
        "pop r14\n" /* e586 */
        "ret\n" /* e588 */
        ".att_syntax prefix\n");
}
