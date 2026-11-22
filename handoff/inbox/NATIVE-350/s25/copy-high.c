/* zedstwu.dll high-capability Windows AMD64 copy with editable instructions and table expressions. */
#include "copy-high-encoding.h"

__attribute__((naked,used)) void *copy_high(void *dst, const void *src, unsigned long long size) {
    __asm__(".intel_syntax noprefix\n"
        /* Windows AMD64: destination RCX, source RDX and length R8. Return the original destination in RAX. */
        ".Lcopy_high:\n"
        "push rsi\n" /* e5c0 */
        "mov rax, rcx\n" /* e5c1 */
        "lea r9, [rip + .Lsmall_offsets]\n" /* e5c4 */
        "cmp r8, 0x80\n" /* e5cb */
        "jge .Lalign_destination\n" /* e5d2 */
        "mov r10, rcx\n" /* e5d4 */
        "add r10, r8\n" /* e5d7 */
        "mov r11, rdx\n" /* e5da */
        "add r11, r8\n" /* e5dd */
        "sub r9, qword ptr [r9 + r8*8]\n" /* e5e0 */
        "jmp r9\n" /* e5e4 */
        /* Compute the 0–63 byte prefix needed for a 64-byte-aligned destination. */
        ".Lalign_destination:\n"
        "lea r9, [rip + .Lprefix_offsets]\n" /* e5e7 */
        "mov rsi, rcx\n" /* e5ee */
        "neg rsi\n" /* e5f1 */
        "add rsi, 0x40\n" /* e5f4 */
        "and rsi, 0x3f\n" /* e5f8 */
        "je .Lcheck_bulk_size\n" /* e5fc */
        "sub r8, rsi\n" /* e5fe */
        "mov r10, rcx\n" /* e601 */
        "add r10, rsi\n" /* e604 */
        "mov r11, rdx\n" /* e607 */
        "add r11, rsi\n" /* e60a */
        "sub r9, qword ptr [r9 + rsi*8]\n" /* e60d */
        "jmp r9\n" /* e611 */
        ".Ladvance_prefix:\n"
        "add rcx, rsi\n" /* e614 */
        "add rdx, rsi\n" /* e617 */
        /* Skip the bulk loops for a remainder below 512 bytes. The shared threshold selects the store path. */
        ".Lcheck_bulk_size:\n"
        "cmp r8, 0x200\n" /* e61a */
        LONG_JL(.Lprepare_tail) /* e621 */
        "cmp r8, qword ptr [rip + stream_threshold_rva_22238]\n" /* e627 */
        LONG_JAE(.Lprepare_streaming) /* e62e */
        /* Eight 64-byte loads and cached aligned stores per iteration. */
        ".Lcopy_cached_512:\n"
        "vmovdqu64 zmm0, zmmword ptr [rdx]\n" /* e634 */
        "prefetcht1 byte ptr [rdx + 0x600]\n" /* e63a */
        "vmovaps zmmword ptr [rcx], zmm0\n" /* e641 */
        "vmovdqu64 zmm0, zmmword ptr [rdx + 0x40]\n" /* e647 */
        "prefetcht1 byte ptr [rdx + 0x640]\n" /* e64e */
        "vmovaps zmmword ptr [rcx + 0x40], zmm0\n" /* e655 */
        "vmovdqu64 zmm0, zmmword ptr [rdx + 0x80]\n" /* e65c */
        "prefetcht1 byte ptr [rdx + 0x680]\n" /* e663 */
        "vmovaps zmmword ptr [rcx + 0x80], zmm0\n" /* e66a */
        "vmovdqu64 zmm0, zmmword ptr [rdx + 0xc0]\n" /* e671 */
        "prefetcht1 byte ptr [rdx + 0x6c0]\n" /* e678 */
        "vmovaps zmmword ptr [rcx + 0xc0], zmm0\n" /* e67f */
        "lea rcx, [rcx + 0x200]\n" /* e686 */
        "lea rdx, [rdx + 0x200]\n" /* e68d */
        "sub r8, 0x200\n" /* e694 */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0x100]\n" /* e69b */
        "prefetcht1 byte ptr [rdx + 0x500]\n" /* e6a2 */
        "vmovaps zmmword ptr [rcx - 0x100], zmm0\n" /* e6a9 */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0xc0]\n" /* e6b0 */
        "prefetcht1 byte ptr [rdx + 0x540]\n" /* e6b7 */
        "vmovaps zmmword ptr [rcx - 0xc0], zmm0\n" /* e6be */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0x80]\n" /* e6c5 */
        "prefetcht1 byte ptr [rdx + 0x580]\n" /* e6cc */
        "vmovaps zmmword ptr [rcx - 0x80], zmm0\n" /* e6d3 */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0x40]\n" /* e6da */
        "prefetcht1 byte ptr [rdx + 0x5c0]\n" /* e6e1 */
        "vmovaps zmmword ptr [rcx - 0x40], zmm0\n" /* e6e8 */
        "cmp r8, 0x200\n" /* e6ef */
        LONG_JGE(.Lcopy_cached_512) /* e6f6 */
        LONG_JMP(.Lprepare_tail) /* e6fc */
        /* Warm the source cache before the non-temporal store loop. */
        ".Lprepare_streaming:\n"
        "prefetcht1 byte ptr [rdx]\n" /* e701 */
        "prefetcht1 byte ptr [rdx + 0x40]\n" /* e704 */
        "prefetcht1 byte ptr [rdx + 0x80]\n" /* e708 */
        "prefetcht1 byte ptr [rdx + 0xc0]\n" /* e70f */
        "prefetcht1 byte ptr [rdx + 0x100]\n" /* e716 */
        "prefetcht1 byte ptr [rdx + 0x140]\n" /* e71d */
        "prefetcht1 byte ptr [rdx + 0x180]\n" /* e724 */
        "prefetcht1 byte ptr [rdx + 0x1c0]\n" /* e72b */
        "prefetcht1 byte ptr [rdx + 0x200]\n" /* e732 */
        "prefetcht1 byte ptr [rdx + 0x240]\n" /* e739 */
        "prefetcht1 byte ptr [rdx + 0x280]\n" /* e740 */
        "prefetcht1 byte ptr [rdx + 0x2c0]\n" /* e747 */
        "prefetcht1 byte ptr [rdx + 0x300]\n" /* e74e */
        "prefetcht1 byte ptr [rdx + 0x340]\n" /* e755 */
        "prefetcht1 byte ptr [rdx + 0x380]\n" /* e75c */
        "prefetcht1 byte ptr [rdx + 0x3c0]\n" /* e763 */
        "prefetcht1 byte ptr [rdx + 0x400]\n" /* e76a */
        "prefetcht1 byte ptr [rdx + 0x440]\n" /* e771 */
        "prefetcht1 byte ptr [rdx + 0x480]\n" /* e778 */
        "prefetcht1 byte ptr [rdx + 0x4c0]\n" /* e77f */
        "prefetcht1 byte ptr [rdx + 0x500]\n" /* e786 */
        "prefetcht1 byte ptr [rdx + 0x540]\n" /* e78d */
        "prefetcht1 byte ptr [rdx + 0x580]\n" /* e794 */
        "prefetcht1 byte ptr [rdx + 0x5c0]\n" /* e79b */
        /* Eight 64-byte non-temporal stores per iteration. SFENCE precedes the tail. */
        ".Lcopy_streaming_512:\n"
        "vmovdqu64 zmm0, zmmword ptr [rdx]\n" /* e7a2 */
        "prefetcht1 byte ptr [rdx + 0x600]\n" /* e7a8 */
        "vmovntdq zmmword ptr [rcx], zmm0\n" /* e7af */
        "vmovdqu64 zmm0, zmmword ptr [rdx + 0x40]\n" /* e7b5 */
        "prefetcht1 byte ptr [rdx + 0x640]\n" /* e7bc */
        "vmovntdq zmmword ptr [rcx + 0x40], zmm0\n" /* e7c3 */
        "vmovdqu64 zmm0, zmmword ptr [rdx + 0x80]\n" /* e7ca */
        "prefetcht1 byte ptr [rdx + 0x680]\n" /* e7d1 */
        "vmovntdq zmmword ptr [rcx + 0x80], zmm0\n" /* e7d8 */
        "vmovdqu64 zmm0, zmmword ptr [rdx + 0xc0]\n" /* e7df */
        "prefetcht1 byte ptr [rdx + 0x6c0]\n" /* e7e6 */
        "vmovntdq zmmword ptr [rcx + 0xc0], zmm0\n" /* e7ed */
        "lea rcx, [rcx + 0x200]\n" /* e7f4 */
        "lea rdx, [rdx + 0x200]\n" /* e7fb */
        "sub r8, 0x200\n" /* e802 */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0x100]\n" /* e809 */
        "prefetcht1 byte ptr [rdx + 0x500]\n" /* e810 */
        "vmovntdq zmmword ptr [rcx - 0x100], zmm0\n" /* e817 */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0xc0]\n" /* e81e */
        "prefetcht1 byte ptr [rdx + 0x540]\n" /* e825 */
        "vmovntdq zmmword ptr [rcx - 0xc0], zmm0\n" /* e82c */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0x80]\n" /* e833 */
        "prefetcht1 byte ptr [rdx + 0x580]\n" /* e83a */
        "vmovntdq zmmword ptr [rcx - 0x80], zmm0\n" /* e841 */
        "vmovdqu64 zmm0, zmmword ptr [rdx - 0x40]\n" /* e848 */
        "prefetcht1 byte ptr [rdx + 0x5c0]\n" /* e84f */
        "vmovntdq zmmword ptr [rcx - 0x40], zmm0\n" /* e856 */
        "cmp r8, 0x200\n" /* e85d */
        LONG_JGE(.Lcopy_streaming_512) /* e864 */
        "sfence\n" /* e86a */
        LONG_JMP(.Lprepare_tail) /* e86d */
        /* Prefix cases copy differently sized heads or heads and tails, then advance to aligned pointers. */
        ".Lcopy_prefix:\n"
        "mov r9b, byte ptr [rdx]\n" /* e872 */
        "mov byte ptr [rcx], r9b\n" /* e875 */
        ".Lcase_e878:\n"
        LONG_JMP(.Ladvance_prefix) /* e878 */
        ".Lcase_e87d:\n"
        "mov r9w, word ptr [rdx]\n" /* e87d */
        "mov word ptr [rcx], r9w\n" /* e881 */
        LONG_JMP(.Ladvance_prefix) /* e885 */
        ".Lcase_e88a:\n"
        "mov r9w, word ptr [rdx]\n" /* e88a */
        "mov word ptr [rcx], r9w\n" /* e88e */
        "mov r9b, byte ptr [rdx + 2]\n" /* e892 */
        "mov byte ptr [rcx + 2], r9b\n" /* e896 */
        LONG_JMP(.Ladvance_prefix) /* e89a */
        ".Lcase_e89f:\n"
        "mov r9d, dword ptr [rdx]\n" /* e89f */
        "mov dword ptr [rcx], r9d\n" /* e8a2 */
        LONG_JMP(.Ladvance_prefix) /* e8a5 */
        ".Lcase_e8aa:\n"
        "mov r9d, dword ptr [rdx]\n" /* e8aa */
        "mov dword ptr [rcx], r9d\n" /* e8ad */
        "mov r9d, dword ptr [r11 - 4]\n" /* e8b0 */
        "mov dword ptr [r10 - 4], r9d\n" /* e8b4 */
        LONG_JMP(.Ladvance_prefix) /* e8b8 */
        ".Lcase_e8bd:\n"
        "mov r9, qword ptr [rdx]\n" /* e8bd */
        "mov qword ptr [rcx], r9\n" /* e8c0 */
        LONG_JMP(.Ladvance_prefix) /* e8c3 */
        ".Lcase_e8c8:\n"
        "mov r9, qword ptr [rdx]\n" /* e8c8 */
        "mov qword ptr [rcx], r9\n" /* e8cb */
        "mov r9, qword ptr [r11 - 8]\n" /* e8ce */
        "mov qword ptr [r10 - 8], r9\n" /* e8d2 */
        LONG_JMP(.Ladvance_prefix) /* e8d6 */
        ".Lcase_e8db:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* e8db */
        "vmovups xmmword ptr [rcx], xmm0\n" /* e8df */
        LONG_JMP(.Ladvance_prefix) /* e8e3 */
        ".Lcase_e8e8:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* e8e8 */
        "vmovups xmmword ptr [rcx], xmm0\n" /* e8ec */
        "vmovups xmm0, xmmword ptr [r11 - 0x10]\n" /* e8f0 */
        "vmovups xmmword ptr [r10 - 0x10], xmm0\n" /* e8f6 */
        LONG_JMP(.Ladvance_prefix) /* e8fc */
        ".Lcase_e901:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* e901 */
        "vmovups ymmword ptr [rcx], ymm0\n" /* e905 */
        LONG_JMP(.Ladvance_prefix) /* e909 */
        ".Lcase_e90e:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* e90e */
        "vmovups ymmword ptr [rcx], ymm0\n" /* e912 */
        "vmovups ymm0, ymmword ptr [r11 - 0x20]\n" /* e916 */
        "vmovups ymmword ptr [r10 - 0x20], ymm0\n" /* e91c */
        LONG_JMP(.Ladvance_prefix) /* e922 */
        /* Compute the aligned end and residual byte count for the two tail dispatches. */
        ".Lprepare_tail:\n"
        "mov r10, rcx\n" /* e927 */
        "add r10, r8\n" /* e92a */
        "mov rsi, r10\n" /* e92d */
        "add rcx, r8\n" /* e930 */
        "and rcx, 0xffffffffffffffc0\n" /* e933 */
        "mov r11, rdx\n" /* e937 */
        "add r11, r8\n" /* e93a */
        "sub rsi, rcx\n" /* e93d */
        "mov rdx, r11\n" /* e940 */
        "sub rdx, rsi\n" /* e943 */
        "lea r9, [rip + .Ltail_offsets]\n" /* e946 */
        "sub r9, qword ptr [r9 + r8*8]\n" /* e94d */
        "jmp r9\n" /* e951 */
        /* Each table-selected case falls through the remaining full 64-byte vector copies. */
        ".Lcopy_tail_blocks:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0x1c0]\n" /* e954 */
        "vmovaps zmmword ptr [rcx - 0x1c0], zmm0\n" /* e95b */
        ".Lcase_e962:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0x180]\n" /* e962 */
        "vmovaps zmmword ptr [rcx - 0x180], zmm0\n" /* e969 */
        ".Lcase_e970:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0x140]\n" /* e970 */
        "vmovaps zmmword ptr [rcx - 0x140], zmm0\n" /* e977 */
        ".Lcase_e97e:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0x100]\n" /* e97e */
        "vmovaps zmmword ptr [rcx - 0x100], zmm0\n" /* e985 */
        ".Lcase_e98c:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0xc0]\n" /* e98c */
        "vmovaps zmmword ptr [rcx - 0xc0], zmm0\n" /* e993 */
        ".Lcase_e99a:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0x80]\n" /* e99a */
        "vmovaps zmmword ptr [rcx - 0x80], zmm0\n" /* e9a1 */
        ".Lcase_e9a8:\n"
        "vmovups zmm0, zmmword ptr [rdx - 0x40]\n" /* e9a8 */
        "vmovaps zmmword ptr [rcx - 0x40], zmm0\n" /* e9af */
        /* Reuse the tail table for the residual 0–63 bytes. */
        ".Lcopy_final_bytes:\n"
        "lea r9, [rip + .Ltail_offsets]\n" /* e9b6 */
        "sub r9, qword ptr [r9 + rsi*8]\n" /* e9bd */
        "jmp r9\n" /* e9c1 */
        ".Lcase_e9c4:\n"
        "mov r9b, byte ptr [rdx]\n" /* e9c4 */
        "mov byte ptr [rcx], r9b\n" /* e9c7 */
        LONG_JMP(.Lcopy_return) /* e9ca */
        ".Lcase_e9cf:\n"
        LONG_JMP(.Lcopy_return) /* e9cf */
        ".Lcase_e9d4:\n"
        "mov r9w, word ptr [rdx]\n" /* e9d4 */
        "mov word ptr [rcx], r9w\n" /* e9d8 */
        LONG_JMP(.Lcopy_return) /* e9dc */
        ".Lcase_e9e1:\n"
        "mov r9w, word ptr [rdx]\n" /* e9e1 */
        "mov word ptr [rcx], r9w\n" /* e9e5 */
        "mov r9b, byte ptr [rdx + 2]\n" /* e9e9 */
        "mov byte ptr [rcx + 2], r9b\n" /* e9ed */
        LONG_JMP(.Lcopy_return) /* e9f1 */
        ".Lcase_e9f6:\n"
        "mov r9d, dword ptr [rdx]\n" /* e9f6 */
        "mov dword ptr [rcx], r9d\n" /* e9f9 */
        LONG_JMP(.Lcopy_return) /* e9fc */
        ".Lcase_ea01:\n"
        "mov r9d, dword ptr [rdx]\n" /* ea01 */
        "mov dword ptr [rcx], r9d\n" /* ea04 */
        "mov r9d, dword ptr [r11 - 4]\n" /* ea07 */
        "mov dword ptr [r10 - 4], r9d\n" /* ea0b */
        LONG_JMP(.Lcopy_return) /* ea0f */
        ".Lcase_ea14:\n"
        "mov r9, qword ptr [rdx]\n" /* ea14 */
        "mov qword ptr [rcx], r9\n" /* ea17 */
        LONG_JMP(.Lcopy_return) /* ea1a */
        ".Lcase_ea1f:\n"
        "mov r9, qword ptr [rdx]\n" /* ea1f */
        "mov qword ptr [rcx], r9\n" /* ea22 */
        "mov r9, qword ptr [r11 - 8]\n" /* ea25 */
        "mov qword ptr [r10 - 8], r9\n" /* ea29 */
        LONG_JMP(.Lcopy_return) /* ea2d */
        ".Lcase_ea32:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* ea32 */
        "vmovups xmmword ptr [rcx], xmm0\n" /* ea36 */
        LONG_JMP(.Lcopy_return) /* ea3a */
        ".Lcase_ea3f:\n"
        "vmovups xmm0, xmmword ptr [rdx]\n" /* ea3f */
        "vmovups xmmword ptr [rcx], xmm0\n" /* ea43 */
        "vmovups xmm0, xmmword ptr [r11 - 0x10]\n" /* ea47 */
        "vmovups xmmword ptr [r10 - 0x10], xmm0\n" /* ea4d */
        LONG_JMP(.Lcopy_return) /* ea53 */
        ".Lcase_ea58:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* ea58 */
        "vmovups ymmword ptr [rcx], ymm0\n" /* ea5c */
        LONG_JMP(.Lcopy_return) /* ea60 */
        ".Lcase_ea65:\n"
        "vmovups ymm0, ymmword ptr [rdx]\n" /* ea65 */
        "vmovups ymmword ptr [rcx], ymm0\n" /* ea69 */
        "vmovups ymm0, ymmword ptr [r11 - 0x20]\n" /* ea6d */
        "vmovups ymmword ptr [r10 - 0x20], ymm0\n" /* ea73 */
        LONG_JMP(.Lcopy_return) /* ea79 */
        ".Lcase_ea7e:\n"
        "vmovups zmm0, zmmword ptr [rdx]\n" /* ea7e */
        "vmovups zmmword ptr [rcx], zmm0\n" /* ea84 */
        LONG_JMP(.Lcopy_return) /* ea8a */
        ".Lcase_ea8f:\n"
        "vmovups zmm0, zmmword ptr [rdx]\n" /* ea8f */
        "vmovups zmmword ptr [rcx], zmm0\n" /* ea95 */
        "vmovups zmm0, zmmword ptr [r11 - 0x40]\n" /* ea9b */
        "vmovups zmmword ptr [r10 - 0x40], zmm0\n" /* eaa2 */
        LONG_JMP(.Lcopy_return) /* eaa9 */
        PAD_6666666666662E0F1F840000000000 /* eaae */
        PAD_0F1F00 /* eabd */
        /* 64 table entries: subtract an indexed difference from the table base. */
        ".Lprefix_offsets:\n"
        ".quad .Lprefix_offsets - .Lcase_e878\n" /* indices 0–0 */
        ".quad .Lprefix_offsets - .Lcopy_prefix\n" /* indices 1–1 */
        ".quad .Lprefix_offsets - .Lcase_e87d\n" /* indices 2–2 */
        ".quad .Lprefix_offsets - .Lcase_e88a\n" /* indices 3–3 */
        ".quad .Lprefix_offsets - .Lcase_e89f\n" /* indices 4–4 */
        ".rept 3\n.quad .Lprefix_offsets - .Lcase_e8aa\n.endr\n" /* indices 5–7 */
        ".quad .Lprefix_offsets - .Lcase_e8bd\n" /* indices 8–8 */
        ".rept 7\n.quad .Lprefix_offsets - .Lcase_e8c8\n.endr\n" /* indices 9–15 */
        ".quad .Lprefix_offsets - .Lcase_e8db\n" /* indices 16–16 */
        ".rept 15\n.quad .Lprefix_offsets - .Lcase_e8e8\n.endr\n" /* indices 17–31 */
        ".quad .Lprefix_offsets - .Lcase_e901\n" /* indices 32–32 */
        ".rept 31\n.quad .Lprefix_offsets - .Lcase_e90e\n.endr\n" /* indices 33–63 */
        /* 512 table entries: subtract an indexed difference from the table base. */
        ".Ltail_offsets:\n"
        ".quad .Ltail_offsets - .Lcase_e9cf\n" /* indices 0–0 */
        ".quad .Ltail_offsets - .Lcase_e9c4\n" /* indices 1–1 */
        ".quad .Ltail_offsets - .Lcase_e9d4\n" /* indices 2–2 */
        ".quad .Ltail_offsets - .Lcase_e9e1\n" /* indices 3–3 */
        ".quad .Ltail_offsets - .Lcase_e9f6\n" /* indices 4–4 */
        ".rept 3\n.quad .Ltail_offsets - .Lcase_ea01\n.endr\n" /* indices 5–7 */
        ".quad .Ltail_offsets - .Lcase_ea14\n" /* indices 8–8 */
        ".rept 7\n.quad .Ltail_offsets - .Lcase_ea1f\n.endr\n" /* indices 9–15 */
        ".quad .Ltail_offsets - .Lcase_ea32\n" /* indices 16–16 */
        ".rept 15\n.quad .Ltail_offsets - .Lcase_ea3f\n.endr\n" /* indices 17–31 */
        ".quad .Ltail_offsets - .Lcase_ea58\n" /* indices 32–32 */
        ".rept 31\n.quad .Ltail_offsets - .Lcase_ea65\n.endr\n" /* indices 33–63 */
        ".rept 64\n.quad .Ltail_offsets - .Lcase_e9a8\n.endr\n" /* indices 64–127 */
        ".rept 64\n.quad .Ltail_offsets - .Lcase_e99a\n.endr\n" /* indices 128–191 */
        ".rept 64\n.quad .Ltail_offsets - .Lcase_e98c\n.endr\n" /* indices 192–255 */
        ".rept 64\n.quad .Ltail_offsets - .Lcase_e97e\n.endr\n" /* indices 256–319 */
        ".rept 64\n.quad .Ltail_offsets - .Lcase_e970\n.endr\n" /* indices 320–383 */
        ".rept 64\n.quad .Ltail_offsets - .Lcase_e962\n.endr\n" /* indices 384–447 */
        ".rept 64\n.quad .Ltail_offsets - .Lcopy_tail_blocks\n.endr\n" /* indices 448–511 */
        /* 128 table entries: subtract an indexed difference from the table base. */
        ".Lsmall_offsets:\n"
        ".quad .Lsmall_offsets - .Lcase_e9cf\n" /* indices 0–0 */
        ".quad .Lsmall_offsets - .Lcase_e9c4\n" /* indices 1–1 */
        ".quad .Lsmall_offsets - .Lcase_e9d4\n" /* indices 2–2 */
        ".quad .Lsmall_offsets - .Lcase_e9e1\n" /* indices 3–3 */
        ".quad .Lsmall_offsets - .Lcase_e9f6\n" /* indices 4–4 */
        ".rept 3\n.quad .Lsmall_offsets - .Lcase_ea01\n.endr\n" /* indices 5–7 */
        ".quad .Lsmall_offsets - .Lcase_ea14\n" /* indices 8–8 */
        ".rept 7\n.quad .Lsmall_offsets - .Lcase_ea1f\n.endr\n" /* indices 9–15 */
        ".quad .Lsmall_offsets - .Lcase_ea32\n" /* indices 16–16 */
        ".rept 15\n.quad .Lsmall_offsets - .Lcase_ea3f\n.endr\n" /* indices 17–31 */
        ".quad .Lsmall_offsets - .Lcase_ea58\n" /* indices 32–32 */
        ".rept 31\n.quad .Lsmall_offsets - .Lcase_ea65\n.endr\n" /* indices 33–63 */
        ".quad .Lsmall_offsets - .Lcase_ea7e\n" /* indices 64–64 */
        ".rept 63\n.quad .Lsmall_offsets - .Lcase_ea8f\n.endr\n" /* indices 65–127 */
        /* Restore RSI and return RAX. */
        ".Lcopy_return:\n"
        "pop rsi\n" /* 100c0 */
        "ret\n" /* 100c1 */
        ".att_syntax prefix\n");
}
