/* Windows AMD64 CRT startup lock release, original RVA 0x15c74. */
__asm__(
    ".intel_syntax noprefix\n"
    ".text\n"
    ".globl release_startup_lock\n"
    "release_startup_lock:\n"
    ".seh_proc release_startup_lock\n"
    "  .byte 0x40\n"
    "  push rbx\n"
    "  .seh_pushreg rbx\n"
    "  sub rsp, 32\n"
    "  .seh_stackalloc 32\n"
    "  .seh_endprologue\n"
    "  .byte 0x8a, 0xd9\n" /* mov bl, cl, using the original MOV encoding. */
    "  call is_ucrt_dll_in_use\n"
    "  .byte 0x33, 0xd2\n" /* xor edx, edx, using the original XOR encoding. */
    "  test eax, eax\n"
    "  je .Lreturn\n"
    "  test bl, bl\n"
    "  jne .Lreturn\n"
    "  xchg qword ptr [rip + startup_lock], rdx\n"
    ".Lreturn:\n"
    "  add rsp, 32\n"
    "  pop rbx\n"
    "  ret\n"
    "release_startup_lock_end:\n"
    ".seh_endproc\n"
    ".att_syntax prefix\n"
);
