; NATIVE-340 native disassembly (IDA 9.5, imagebase 0x180000000)
; RVA  bytes  instruction

; FUNC 00001DD8-00001E03 sub_180001DD8 (43 bytes)
00001DD8  40 53  push    rbx
00001DDA  48 83 EC 20  sub     rsp, 20h
00001DDE  48 8D 05 F3 44 00 00  lea     rax, const type_info::`vftable'
00001DE5  48 8B D9  mov     rbx, rcx
00001DE8  48 89 01  mov     [rcx], rax
00001DEB  F6 C2 01  test    dl, 1
00001DEE  74 0A  jz      short loc_180001DFA
00001DF0  BA 18 00 00 00  mov     edx, 18h
00001DF5  E8 06 06 00 00  call    j_j_free
00001DFA  48 8B C3  mov     rax, rbx
00001DFD  48 83 C4 20  add     rsp, 20h
00001E01  5B  pop     rbx
00001E02  C3  retn

; FUNC 00001E04-00001E1B sub_180001E04 (23 bytes)
00001E04  48 83 61 10 00  and     qword ptr [rcx+10h], 0
00001E09  48 8D 05 30 72 01 00  lea     rax, const std::bad_alloc::`vftable'
00001E10  48 89 01  mov     [rcx], rax
00001E13  48 8B C1  mov     rax, rcx
00001E16  48 89 51 08  mov     [rcx+8], rdx
00001E1A  C3  retn

; FUNC 00001E1C-00001E58 sub_180001E1C (60 bytes)
00001E1C  40 53  push    rbx
00001E1E  48 83 EC 20  sub     rsp, 20h
00001E22  48 8B D9  mov     rbx, rcx
00001E25  48 8B C2  mov     rax, rdx
00001E28  48 8D 0D D9 71 01 00  lea     rcx, const std::exception::`vftable'
00001E2F  0F 57 C0  xorps   xmm0, xmm0
00001E32  48 89 0B  mov     [rbx], rcx
00001E35  48 8D 53 08  lea     rdx, [rbx+8]
00001E39  48 8D 48 08  lea     rcx, [rax+8]
00001E3D  0F 11 02  movups  xmmword ptr [rdx], xmm0
00001E40  E8 26 29 00 00  call    __std_exception_copy
00001E45  48 8D 05 F4 71 01 00  lea     rax, const std::bad_alloc::`vftable'
00001E4C  48 89 03  mov     [rbx], rax
00001E4F  48 8B C3  mov     rax, rbx
00001E52  48 83 C4 20  add     rsp, 20h
00001E56  5B  pop     rbx
00001E57  C3  retn

; FUNC 00001E58-00001E76 sub_180001E58 (30 bytes)
00001E58  48 83 61 10 00  and     qword ptr [rcx+10h], 0
00001E5D  48 8D 05 7C 44 00 00  lea     rax, aBadAllocation; "bad allocation"
00001E64  48 89 41 08  mov     [rcx+8], rax
00001E68  48 8D 05 D1 71 01 00  lea     rax, const std::bad_alloc::`vftable'
00001E6F  48 89 01  mov     [rcx], rax
00001E72  48 8B C1  mov     rax, rcx
00001E75  C3  retn

; FUNC 00001E78-00001EB4 sub_180001E78 (60 bytes)
00001E78  40 53  push    rbx
00001E7A  48 83 EC 20  sub     rsp, 20h
00001E7E  48 8B D9  mov     rbx, rcx
00001E81  48 8B C2  mov     rax, rdx
00001E84  48 8D 0D 7D 71 01 00  lea     rcx, const std::exception::`vftable'
00001E8B  0F 57 C0  xorps   xmm0, xmm0
00001E8E  48 89 0B  mov     [rbx], rcx
00001E91  48 8D 53 08  lea     rdx, [rbx+8]
00001E95  48 8D 48 08  lea     rcx, [rax+8]
00001E99  0F 11 02  movups  xmmword ptr [rdx], xmm0
00001E9C  E8 CA 28 00 00  call    __std_exception_copy
00001EA1  48 8D 05 C0 71 01 00  lea     rax, const std::bad_array_new_length::`vftable'
00001EA8  48 89 03  mov     [rbx], rax
00001EAB  48 8B C3  mov     rax, rbx
00001EAE  48 83 C4 20  add     rsp, 20h
00001EB2  5B  pop     rbx
00001EB3  C3  retn

; FUNC 00001EB4-00001ED2 sub_180001EB4 (30 bytes)
00001EB4  48 83 61 10 00  and     qword ptr [rcx+10h], 0
00001EB9  48 8D 05 30 44 00 00  lea     rax, aBadArrayNewLen; "bad array new length"
00001EC0  48 89 41 08  mov     [rcx+8], rax
00001EC4  48 8D 05 9D 71 01 00  lea     rax, const std::bad_array_new_length::`vftable'
00001ECB  48 89 01  mov     [rcx], rax
00001ECE  48 8B C1  mov     rax, rcx
00001ED1  C3  retn

; FUNC 00001ED4-00001F06 sub_180001ED4 (50 bytes)
00001ED4  40 53  push    rbx
00001ED6  48 83 EC 20  sub     rsp, 20h
00001EDA  48 8B D9  mov     rbx, rcx
00001EDD  48 8B C2  mov     rax, rdx
00001EE0  48 8D 0D 21 71 01 00  lea     rcx, const std::exception::`vftable'
00001EE7  0F 57 C0  xorps   xmm0, xmm0
00001EEA  48 89 0B  mov     [rbx], rcx
00001EED  48 8D 53 08  lea     rdx, [rbx+8]
00001EF1  48 8D 48 08  lea     rcx, [rax+8]
00001EF5  0F 11 02  movups  xmmword ptr [rdx], xmm0
00001EF8  E8 6E 28 00 00  call    __std_exception_copy
00001EFD  48 8B C3  mov     rax, rbx
00001F00  48 83 C4 20  add     rsp, 20h
00001F04  5B  pop     rbx
00001F05  C3  retn

; FUNC 00001F08-00001F1F sub_180001F08 (23 bytes)
00001F08  48 8D 05 F9 70 01 00  lea     rax, const std::exception::`vftable'
00001F0F  48 89 01  mov     [rcx], rax
00001F12  48 8B C1  mov     rax, rcx
00001F15  48 83 61 10 00  and     qword ptr [rcx+10h], 0
00001F1A  48 89 51 08  mov     [rcx+8], rdx
00001F1E  C3  retn

; FUNC 00001F20-00001F33 sub_180001F20 (19 bytes)
00001F20  48 8D 05 E1 70 01 00  lea     rax, const std::exception::`vftable'
00001F27  48 89 01  mov     [rcx], rax
00001F2A  48 83 C1 08  add     rcx, 8
00001F2E  E9 3E 28 00 00  jmp     __std_exception_destroy

; FUNC 00001F34-00001F47 sub_180001F34 (19 bytes)
00001F34  48 8D 05 CD 70 01 00  lea     rax, const std::exception::`vftable'
00001F3B  48 89 01  mov     [rcx], rax
00001F3E  48 83 C1 08  add     rcx, 8
00001F42  E9 2A 28 00 00  jmp     __std_exception_destroy

; FUNC 00001F48-00001F5B sub_180001F48 (19 bytes)
00001F48  48 8D 05 B9 70 01 00  lea     rax, const std::exception::`vftable'
00001F4F  48 89 01  mov     [rcx], rax
00001F52  48 83 C1 08  add     rcx, 8
00001F56  E9 16 28 00 00  jmp     __std_exception_destroy

; FUNC 00001F5C-00001F9E sub_180001F5C (66 bytes)
00001F5C  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001F61  57  push    rdi
00001F62  48 83 EC 20  sub     rsp, 20h
00001F66  48 8D 05 9B 70 01 00  lea     rax, const std::exception::`vftable'
00001F6D  48 8B F9  mov     rdi, rcx
00001F70  48 89 01  mov     [rcx], rax
00001F73  8B DA  mov     ebx, edx
00001F75  48 83 C1 08  add     rcx, 8
00001F79  E8 F3 27 00 00  call    __std_exception_destroy
00001F7E  F6 C3 01  test    bl, 1
00001F81  74 0D  jz      short loc_180001F90
00001F83  BA 18 00 00 00  mov     edx, 18h
00001F88  48 8B CF  mov     rcx, rdi; Block
00001F8B  E8 70 04 00 00  call    j_j_free
00001F90  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00001F95  48 8B C7  mov     rax, rdi
00001F98  48 83 C4 20  add     rsp, 20h
00001F9C  5F  pop     rdi
00001F9D  C3  retn

; FUNC 00001FA0-00001FE2 sub_180001FA0 (66 bytes)
00001FA0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001FA5  57  push    rdi
00001FA6  48 83 EC 20  sub     rsp, 20h
00001FAA  48 8D 05 57 70 01 00  lea     rax, const std::exception::`vftable'
00001FB1  48 8B F9  mov     rdi, rcx
00001FB4  48 89 01  mov     [rcx], rax
00001FB7  8B DA  mov     ebx, edx
00001FB9  48 83 C1 08  add     rcx, 8
00001FBD  E8 AF 27 00 00  call    __std_exception_destroy
00001FC2  F6 C3 01  test    bl, 1
00001FC5  74 0D  jz      short loc_180001FD4
00001FC7  BA 18 00 00 00  mov     edx, 18h
00001FCC  48 8B CF  mov     rcx, rdi; Block
00001FCF  E8 2C 04 00 00  call    j_j_free
00001FD4  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00001FD9  48 8B C7  mov     rax, rdi
00001FDC  48 83 C4 20  add     rsp, 20h
00001FE0  5F  pop     rdi
00001FE1  C3  retn

; FUNC 00001FE4-00002026 sub_180001FE4 (66 bytes)
00001FE4  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001FE9  57  push    rdi
00001FEA  48 83 EC 20  sub     rsp, 20h
00001FEE  48 8D 05 13 70 01 00  lea     rax, const std::exception::`vftable'
00001FF5  48 8B F9  mov     rdi, rcx
00001FF8  48 89 01  mov     [rcx], rax
00001FFB  8B DA  mov     ebx, edx
00001FFD  48 83 C1 08  add     rcx, 8
00002001  E8 6B 27 00 00  call    __std_exception_destroy
00002006  F6 C3 01  test    bl, 1
00002009  74 0D  jz      short loc_180002018
0000200B  BA 18 00 00 00  mov     edx, 18h
00002010  48 8B CF  mov     rcx, rdi; Block
00002013  E8 E8 03 00 00  call    j_j_free
00002018  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
0000201D  48 8B C7  mov     rax, rdi
00002020  48 83 C4 20  add     rsp, 20h
00002024  5F  pop     rdi
00002025  C3  retn

; FUNC 00002028-00002048 sub_180002028 (32 bytes)
00002028  48 83 EC 48  sub     rsp, 48h
0000202C  48 8D 4C 24 20  lea     rcx, [rsp+48h+pExceptionObject]
00002031  E8 22 FE FF FF  call    sub_180001E58
00002036  48 8D 15 1B 58 01 00  lea     rdx, __TI2?AVbad_alloc@std@@; pThrowInfo
0000203D  48 8D 4C 24 20  lea     rcx, [rsp+48h+pExceptionObject]; pExceptionObject
00002042  E8 30 27 00 00  call    _CxxThrowException
00002047  CC  align 8

; FUNC 00002048-00002068 sub_180002048 (32 bytes)
00002048  48 83 EC 48  sub     rsp, 48h
0000204C  48 8D 4C 24 20  lea     rcx, [rsp+48h+pExceptionObject]
00002051  E8 5E FE FF FF  call    sub_180001EB4
00002056  48 8D 15 83 58 01 00  lea     rdx, __TI3?AVbad_array_new_length@std@@; pThrowInfo
0000205D  48 8D 4C 24 20  lea     rcx, [rsp+48h+pExceptionObject]; pExceptionObject
00002062  E8 10 27 00 00  call    _CxxThrowException
00002067  CC  align 8

; FUNC 00002068-0000207A sub_180002068 (18 bytes)
00002068  48 83 79 08 00  cmp     qword ptr [rcx+8], 0
0000206D  48 8D 05 1C 42 00 00  lea     rax, aUnknownExcepti; "Unknown exception"
00002074  48 0F 45 41 08  cmovnz  rax, [rcx+8]
00002079  C3  retn

; FUNC 0000207C-000020CC sub_18000207C (80 bytes)
0000207C  48 83 EC 28  sub     rsp, 28h
00002080  85 D2  test    edx, edx
00002082  74 39  jz      short loc_1800020BD
00002084  83 EA 01  sub     edx, 1
00002087  74 28  jz      short loc_1800020B1
00002089  83 EA 01  sub     edx, 1
0000208C  74 16  jz      short loc_1800020A4
0000208E  83 FA 01  cmp     edx, 1
00002091  74 0A  jz      short loc_18000209D
00002093  B8 01 00 00 00  mov     eax, 1
00002098  48 83 C4 28  add     rsp, 28h
0000209C  C3  retn
0000209D  E8 3E 06 00 00  call    sub_1800026E0
000020A2  EB 05  jmp     short loc_1800020A9
000020A4  E8 0F 06 00 00  call    sub_1800026B8
000020A9  0F B6 C0  movzx   eax, al
000020AC  48 83 C4 28  add     rsp, 28h
000020B0  C3  retn
000020B1  49 8B D0  mov     rdx, r8
000020B4  48 83 C4 28  add     rsp, 28h
000020B8  E9 0F 00 00 00  jmp     sub_1800020CC
000020BD  4D 85 C0  test    r8, r8
000020C0  0F 95 C1  setnz   cl
000020C3  48 83 C4 28  add     rsp, 28h
000020C7  E9 18 01 00 00  jmp     sub_1800021E4

; FUNC 000020CC-000021E2 sub_1800020CC (278 bytes)
000020CC  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000020D1  48 89 74 24 10  mov     [rsp+arg_8], rsi
000020D6  48 89 7C 24 20  mov     [rsp+arg_18], rdi
000020DB  41 56  push    r14
000020DD  48 83 EC 20  sub     rsp, 20h
000020E1  48 8B F2  mov     rsi, rdx
000020E4  4C 8B F1  mov     r14, rcx
000020E7  33 C9  xor     ecx, ecx
000020E9  E8 AE 06 00 00  call    sub_18000279C
000020EE  84 C0  test    al, al
000020F0  0F 84 C8 00 00 00  jz      loc_1800021BE
000020F6  E8 35 05 00 00  call    sub_180002630
000020FB  8A D8  mov     bl, al
000020FD  88 44 24 40  mov     [rsp+28h+arg_10], al
00002101  40 B7 01  mov     dil, 1
00002104  83 3D 85 78 01 00 00  cmp     cs:dword_180019990, 0
0000210B  0F 85 C5 00 00 00  jnz     loc_1800021D6
00002111  C7 05 75 78 01 00 01 00 00 00  mov     cs:dword_180019990, 1
0000211B  E8 80 05 00 00  call    sub_1800026A0
00002120  84 C0  test    al, al
00002122  74 4F  jz      short loc_180002173
00002124  E8 0F 0B 00 00  call    sub_180002C38
00002129  E8 16 04 00 00  call    sub_180002544
0000212E  E8 3D 04 00 00  call    sub_180002570
00002133  48 8D 15 BE 40 00 00  lea     rdx, Last; Last
0000213A  48 8D 0D AF 40 00 00  lea     rcx, First; First
00002141  E8 5B 26 00 00  call    _initterm_e
00002146  85 C0  test    eax, eax
00002148  75 29  jnz     short loc_180002173
0000214A  E8 1D 05 00 00  call    sub_18000266C
0000214F  84 C0  test    al, al
00002151  74 20  jz      short loc_180002173
00002153  48 8D 15 8E 40 00 00  lea     rdx, qword_1800061E8; Last
0000215A  48 8D 0D 7F 40 00 00  lea     rcx, qword_1800061E0; First
00002161  E8 35 26 00 00  call    _initterm
00002166  C7 05 20 78 01 00 02 00 00 00  mov     cs:dword_180019990, 2
00002170  40 32 FF  xor     dil, dil
00002173  8A CB  mov     cl, bl
00002175  E8 92 07 00 00  call    sub_18000290C
0000217A  40 84 FF  test    dil, dil
0000217D  75 3F  jnz     short loc_1800021BE
0000217F  E8 4C 08 00 00  call    sub_1800029D0
00002184  48 8B D8  mov     rbx, rax
00002187  48 83 38 00  cmp     qword ptr [rax], 0
0000218B  74 24  jz      short loc_1800021B1
0000218D  48 8B C8  mov     rcx, rax
00002190  E8 DF 06 00 00  call    sub_180002874
00002195  84 C0  test    al, al
00002197  74 18  jz      short loc_1800021B1
00002199  4C 8B C6  mov     r8, rsi
0000219C  BA 02 00 00 00  mov     edx, 2
000021A1  49 8B CE  mov     rcx, r14
000021A4  48 8B 03  mov     rax, [rbx]
000021A7  4C 8B 0D 0A 40 00 00  mov     r9, cs:__guard_dispatch_icall_fptr
000021AE  41 FF D1  call    r9 ; _guard_dispatch_icall_nop
000021B1  FF 05 AD 77 01 00  inc     cs:dword_180019964
000021B7  B8 01 00 00 00  mov     eax, 1
000021BC  EB 02  jmp     short loc_1800021C0
000021BE  33 C0  xor     eax, eax
000021C0  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
000021C5  48 8B 74 24 38  mov     rsi, [rsp+28h+arg_8]
000021CA  48 8B 7C 24 48  mov     rdi, [rsp+28h+arg_18]
000021CF  48 83 C4 20  add     rsp, 20h
000021D3  41 5E  pop     r14
000021D5  C3  retn
000021D6  B9 07 00 00 00  mov     ecx, 7
000021DB  E8 00 08 00 00  call    sub_1800029E0
000021E0  90  nop
000021E1  CC  int     3; Trap to Debugger

; FUNC 000021E4-00002268 sub_1800021E4 (132 bytes)
000021E4  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000021E9  57  push    rdi
000021EA  48 83 EC 30  sub     rsp, 30h
000021EE  40 8A F9  mov     dil, cl
000021F1  8B 05 6D 77 01 00  mov     eax, cs:dword_180019964
000021F7  85 C0  test    eax, eax
000021F9  7F 0D  jg      short loc_180002208
000021FB  33 C0  xor     eax, eax
000021FD  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00002202  48 83 C4 30  add     rsp, 30h
00002206  5F  pop     rdi
00002207  C3  retn
00002208  FF C8  dec     eax
0000220A  89 05 54 77 01 00  mov     cs:dword_180019964, eax
00002210  E8 1B 04 00 00  call    sub_180002630
00002215  8A D8  mov     bl, al
00002217  88 44 24 20  mov     [rsp+38h+var_18], al
0000221B  83 3D 6E 77 01 00 02  cmp     cs:dword_180019990, 2
00002222  75 37  jnz     short loc_18000225B
00002224  E8 2F 05 00 00  call    sub_180002758
00002229  E8 26 03 00 00  call    sub_180002554
0000222E  E8 41 0A 00 00  call    sub_180002C74
00002233  83 25 56 77 01 00 00  and     cs:dword_180019990, 0
0000223A  8A CB  mov     cl, bl
0000223C  E8 CB 06 00 00  call    sub_18000290C
00002241  33 D2  xor     edx, edx
00002243  40 8A CF  mov     cl, dil
00002246  E8 E5 06 00 00  call    sub_180002930
0000224B  F6 D8  neg     al
0000224D  1B DB  sbb     ebx, ebx
0000224F  83 E3 01  and     ebx, 1
00002252  E8 31 05 00 00  call    sub_180002788
00002257  8B C3  mov     eax, ebx
00002259  EB A2  jmp     short loc_1800021FD
0000225B  B9 07 00 00 00  mov     ecx, 7
00002260  E8 7B 07 00 00  call    sub_1800029E0
00002265  90  nop
00002266  90  nop
00002267  CC  int     3; Trap to Debugger

; FUNC 00002268-00002399 sub_180002268 (305 bytes)
00002268  48 8B C4  mov     rax, rsp
0000226B  48 89 58 20  mov     [rax+20h], rbx
0000226F  4C 89 40 18  mov     [rax+18h], r8
00002273  89 50 10  mov     [rax+10h], edx
00002276  48 89 48 08  mov     [rax+8], rcx
0000227A  56  push    rsi
0000227B  57  push    rdi
0000227C  41 56  push    r14
0000227E  48 83 EC 40  sub     rsp, 40h
00002282  49 8B F0  mov     rsi, r8
00002285  8B FA  mov     edi, edx
00002287  4C 8B F1  mov     r14, rcx
0000228A  85 D2  test    edx, edx
0000228C  75 0F  jnz     short loc_18000229D
0000228E  39 15 D0 76 01 00  cmp     cs:dword_180019964, edx
00002294  7F 07  jg      short loc_18000229D
00002296  33 C0  xor     eax, eax
00002298  E9 EE 00 00 00  jmp     loc_18000238B
0000229D  8D 42 FF  lea     eax, [rdx-1]
000022A0  83 F8 01  cmp     eax, 1
000022A3  77 45  ja      short loc_1800022EA
000022A5  48 8B 05 5C 40 00 00  mov     rax, cs:qword_180006308
000022AC  48 85 C0  test    rax, rax
000022AF  75 0A  jnz     short loc_1800022BB
000022B1  C7 44 24 30 01 00 00 00  mov     [rsp+58h+var_28], 1
000022B9  EB 14  jmp     short loc_1800022CF
000022BB  FF 15 F7 3E 00 00  call    cs:__guard_dispatch_icall_fptr
000022C1  8B D8  mov     ebx, eax
000022C3  89 44 24 30  mov     [rsp+58h+var_28], eax
000022C7  85 C0  test    eax, eax
000022C9  0F 84 B2 00 00 00  jz      loc_180002381
000022CF  4C 8B C6  mov     r8, rsi
000022D2  8B D7  mov     edx, edi
000022D4  49 8B CE  mov     rcx, r14
000022D7  E8 A0 FD FF FF  call    sub_18000207C
000022DC  8B D8  mov     ebx, eax
000022DE  89 44 24 30  mov     [rsp+58h+var_28], eax
000022E2  85 C0  test    eax, eax
000022E4  0F 84 97 00 00 00  jz      loc_180002381
000022EA  4C 8B C6  mov     r8, rsi
000022ED  8B D7  mov     edx, edi
000022EF  49 8B CE  mov     rcx, r14
000022F2  E8 29 02 00 00  call    sub_180002520
000022F7  8B D8  mov     ebx, eax
000022F9  89 44 24 30  mov     [rsp+58h+var_28], eax
000022FD  83 FF 01  cmp     edi, 1
00002300  75 36  jnz     short loc_180002338
00002302  85 C0  test    eax, eax
00002304  75 32  jnz     short loc_180002338
00002306  4C 8B C6  mov     r8, rsi
00002309  33 D2  xor     edx, edx
0000230B  49 8B CE  mov     rcx, r14
0000230E  E8 0D 02 00 00  call    sub_180002520
00002313  48 85 F6  test    rsi, rsi
00002316  0F 95 C1  setnz   cl
00002319  E8 C6 FE FF FF  call    sub_1800021E4
0000231E  48 8B 05 E3 3F 00 00  mov     rax, cs:qword_180006308
00002325  48 85 C0  test    rax, rax
00002328  74 0E  jz      short loc_180002338
0000232A  4C 8B C6  mov     r8, rsi
0000232D  33 D2  xor     edx, edx
0000232F  49 8B CE  mov     rcx, r14
00002332  FF 15 80 3E 00 00  call    cs:__guard_dispatch_icall_fptr
00002338  85 FF  test    edi, edi
0000233A  74 05  jz      short loc_180002341
0000233C  83 FF 03  cmp     edi, 3
0000233F  75 40  jnz     short loc_180002381
00002341  4C 8B C6  mov     r8, rsi
00002344  8B D7  mov     edx, edi
00002346  49 8B CE  mov     rcx, r14
00002349  E8 2E FD FF FF  call    sub_18000207C
0000234E  8B D8  mov     ebx, eax
00002350  89 44 24 30  mov     [rsp+58h+var_28], eax
00002354  85 C0  test    eax, eax
00002356  74 29  jz      short loc_180002381
00002358  48 8B 05 A9 3F 00 00  mov     rax, cs:qword_180006308
0000235F  48 85 C0  test    rax, rax
00002362  75 09  jnz     short loc_18000236D
00002364  8D 58 01  lea     ebx, [rax+1]
00002367  89 5C 24 30  mov     [rsp+58h+var_28], ebx
0000236B  EB 14  jmp     short loc_180002381
0000236D  4C 8B C6  mov     r8, rsi
00002370  8B D7  mov     edx, edi
00002372  49 8B CE  mov     rcx, r14
00002375  FF 15 3D 3E 00 00  call    cs:__guard_dispatch_icall_fptr
0000237B  8B D8  mov     ebx, eax
0000237D  89 44 24 30  mov     [rsp+58h+var_28], eax
00002381  EB 06  jmp     short loc_180002389
00002383  33 DB  xor     ebx, ebx
00002385  89 5C 24 30  mov     [rsp+58h+var_28], ebx
00002389  8B C3  mov     eax, ebx
0000238B  48 8B 5C 24 78  mov     rbx, [rsp+58h+arg_18]
00002390  48 83 C4 40  add     rsp, 40h
00002394  41 5E  pop     r14
00002396  5F  pop     rdi
00002397  5E  pop     rsi
00002398  C3  retn

; FUNC 000023B8-000023BD sub_1800023B8 (5 bytes)
000023B8  E9 BF FC FF FF  jmp     sub_18000207C

; FUNC 000023C0-000023FD sub_1800023C0 (61 bytes)
000023C0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000023C5  48 89 74 24 10  mov     [rsp+arg_8], rsi
000023CA  57  push    rdi
000023CB  48 83 EC 20  sub     rsp, 20h
000023CF  49 8B F8  mov     rdi, r8
000023D2  8B DA  mov     ebx, edx
000023D4  48 8B F1  mov     rsi, rcx
000023D7  83 FA 01  cmp     edx, 1
000023DA  75 05  jnz     short loc_1800023E1
000023DC  E8 93 00 00 00  call    __security_init_cookie
000023E1  4C 8B C7  mov     r8, rdi
000023E4  8B D3  mov     edx, ebx
000023E6  48 8B CE  mov     rcx, rsi
000023E9  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
000023EE  48 8B 74 24 38  mov     rsi, [rsp+28h+arg_8]
000023F3  48 83 C4 20  add     rsp, 20h
000023F7  5F  pop     rdi
000023F8  E9 6B FE FF FF  jmp     sub_180002268

; FUNC 00002400-00002405 j_j_free (5 bytes)
00002400  E9 27 0B 00 00  jmp     j_free

; FUNC 00002408-00002473 sub_180002408 (107 bytes)
00002408  40 55  push    rbp
0000240A  48 8B EC  mov     rbp, rsp
0000240D  48 83 EC 20  sub     rsp, 20h
00002411  48 83 65 18 00  and     qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime], 0
00002416  48 8D 4D 18  lea     rcx, [rbp+SystemTimeAsFileTime]; lpSystemTimeAsFileTime
0000241A  FF 15 F8 3B 00 00  call    cs:GetSystemTimeAsFileTime; KERNEL32
00002420  48 8B 45 18  mov     rax, qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime]
00002424  48 89 45 10  mov     [rbp+arg_0], rax
00002428  FF 15 E2 3B 00 00  call    cs:GetCurrentThreadId; KERNEL32
0000242E  8B C0  mov     eax, eax
00002430  48 31 45 10  xor     [rbp+arg_0], rax
00002434  FF 15 CE 3B 00 00  call    cs:GetCurrentProcessId; KERNEL32
0000243A  8B C0  mov     eax, eax
0000243C  48 8D 4D 20  lea     rcx, [rbp+PerformanceCount]; lpPerformanceCount
00002440  48 31 45 10  xor     [rbp+arg_0], rax
00002444  FF 15 B6 3B 00 00  call    cs:QueryPerformanceCounter; KERNEL32
0000244A  8B 45 20  mov     eax, dword ptr [rbp+PerformanceCount]
0000244D  48 8D 4D 10  lea     rcx, [rbp+arg_0]
00002451  48 C1 E0 20  shl     rax, 20h
00002455  48 33 45 20  xor     rax, qword ptr [rbp+PerformanceCount]
00002459  48 33 45 10  xor     rax, [rbp+arg_0]
0000245D  48 33 C1  xor     rax, rcx
00002460  48 B9 FF FF FF FF FF FF 00 00  mov     rcx, 0FFFFFFFFFFFFh
0000246A  48 23 C1  and     rax, rcx
0000246D  48 83 C4 20  add     rsp, 20h
00002471  5D  pop     rbp
00002472  C3  retn

; FUNC 00002474-00002520 __security_init_cookie (172 bytes)
00002474  48 89 5C 24 18  mov     [rsp-8+arg_10], rbx
00002479  55  push    rbp
0000247A  48 8B EC  mov     rbp, rsp
0000247D  48 83 EC 30  sub     rsp, 30h
00002481  48 8B 05 D8 6E 01 00  mov     rax, cs:__security_cookie
00002488  48 BB 32 A2 DF 2D 99 2B 00 00  mov     rbx, 2B992DDFA232h
00002492  48 3B C3  cmp     rax, rbx
00002495  75 74  jnz     short loc_18000250B
00002497  48 83 65 10 00  and     qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime], 0
0000249C  48 8D 4D 10  lea     rcx, [rbp+SystemTimeAsFileTime]; lpSystemTimeAsFileTime
000024A0  FF 15 72 3B 00 00  call    cs:GetSystemTimeAsFileTime; KERNEL32
000024A6  48 8B 45 10  mov     rax, qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime]
000024AA  48 89 45 F0  mov     [rbp+var_10], rax
000024AE  FF 15 5C 3B 00 00  call    cs:GetCurrentThreadId; KERNEL32
000024B4  8B C0  mov     eax, eax
000024B6  48 31 45 F0  xor     [rbp+var_10], rax
000024BA  FF 15 48 3B 00 00  call    cs:GetCurrentProcessId; KERNEL32
000024C0  8B C0  mov     eax, eax
000024C2  48 8D 4D 18  lea     rcx, [rbp+PerformanceCount]; lpPerformanceCount
000024C6  48 31 45 F0  xor     [rbp+var_10], rax
000024CA  FF 15 30 3B 00 00  call    cs:QueryPerformanceCounter; KERNEL32
000024D0  8B 45 18  mov     eax, dword ptr [rbp+PerformanceCount]
000024D3  48 8D 4D F0  lea     rcx, [rbp+var_10]
000024D7  48 C1 E0 20  shl     rax, 20h
000024DB  48 33 45 18  xor     rax, qword ptr [rbp+PerformanceCount]
000024DF  48 33 45 F0  xor     rax, [rbp+var_10]
000024E3  48 33 C1  xor     rax, rcx
000024E6  48 B9 FF FF FF FF FF FF 00 00  mov     rcx, 0FFFFFFFFFFFFh
000024F0  48 23 C1  and     rax, rcx
000024F3  48 B9 33 A2 DF 2D 99 2B 00 00  mov     rcx, 2B992DDFA233h
000024FD  48 3B C3  cmp     rax, rbx
00002500  48 0F 44 C1  cmovz   rax, rcx
00002504  48 89 05 55 6E 01 00  mov     cs:__security_cookie, rax
0000250B  48 8B 5C 24 50  mov     rbx, [rsp+30h+arg_10]
00002510  48 F7 D0  not     rax
00002513  48 89 05 3E 6E 01 00  mov     cs:__security_cookie_complement, rax
0000251A  48 83 C4 30  add     rsp, 30h
0000251E  5D  pop     rbp
0000251F  C3  retn

; FUNC 00002520-00002543 sub_180002520 (35 bytes)
00002520  48 83 EC 28  sub     rsp, 28h
00002524  83 FA 01  cmp     edx, 1
00002527  75 10  jnz     short loc_180002539
00002529  48 83 3D D7 3D 00 00 00  cmp     cs:qword_180006308, 0
00002531  75 06  jnz     short loc_180002539
00002533  FF 15 E7 3A 00 00  call    cs:DisableThreadLibraryCalls; KERNEL32
00002539  B8 01 00 00 00  mov     eax, 1
0000253E  48 83 C4 28  add     rsp, 28h
00002542  C3  retn

; FUNC 00002544-00002552 sub_180002544 (14 bytes)
00002544  48 8D 0D 25 74 01 00  lea     rcx, stru_180019970
0000254B  48 FF 25 D6 3A 00 00  jmp     cs:InitializeSListHead; KERNEL32

; FUNC 00002554-00002560 sub_180002554 (12 bytes)
00002554  48 8D 0D 15 74 01 00  lea     rcx, stru_180019970
0000255B  E9 23 22 00 00  jmp     __std_type_info_destroy_list

; FUNC 00002560-00002568 sub_180002560 (8 bytes)
00002560  48 8D 05 19 74 01 00  lea     rax, unk_180019980
00002567  C3  retn

; FUNC 00002568-00002570 sub_180002568 (8 bytes)
00002568  48 8D 05 19 74 01 00  lea     rax, unk_180019988
0000256F  C3  retn

; FUNC 00002570-0000258B sub_180002570 (27 bytes)
00002570  48 83 EC 28  sub     rsp, 28h
00002574  E8 E7 FF FF FF  call    sub_180002560
00002579  48 83 08 24  or      qword ptr [rax], 24h
0000257D  E8 E6 FF FF FF  call    sub_180002568
00002582  48 83 08 02  or      qword ptr [rax], 2
00002586  48 83 C4 28  add     rsp, 28h
0000258A  C3  retn

; FUNC 0000258C-000025A0 sub_18000258C (20 bytes)
0000258C  48 83 EC 28  sub     rsp, 28h
00002590  E8 4B 0B 00 00  call    sub_1800030E0
00002595  8B C8  mov     ecx, eax; mode
00002597  48 83 C4 28  add     rsp, 28h
0000259B  E9 0D 22 00 00  jmp     _configure_narrow_argv

; FUNC 000025A0-000025E9 sub_1800025A0 (73 bytes)
000025A0  4C 63 41 3C  movsxd  r8, dword ptr [rcx+3Ch]
000025A4  41 0F B7 44 08 14  movzx   eax, word ptr [r8+rcx+14h]
000025AA  4D 8D 0C 08  lea     r9, [r8+rcx]
000025AE  48 83 C0 18  add     rax, 18h
000025B2  4C 03 C8  add     r9, rax
000025B5  41 0F B7 44 08 06  movzx   eax, word ptr [r8+rcx+6]
000025BB  48 8D 0C 80  lea     rcx, [rax+rax*4]
000025BF  4D 8D 04 C9  lea     r8, [r9+rcx*8]
000025C3  4D 3B C8  cmp     r9, r8
000025C6  74 1E  jz      short loc_1800025E6
000025C8  41 8B 49 0C  mov     ecx, [r9+0Ch]
000025CC  48 3B D1  cmp     rdx, rcx
000025CF  72 0B  jb      short loc_1800025DC
000025D1  41 8B 41 08  mov     eax, [r9+8]
000025D5  03 C1  add     eax, ecx
000025D7  48 3B D0  cmp     rdx, rax
000025DA  72 06  jb      short loc_1800025E2
000025DC  49 83 C1 28  add     r9, 28h ; '('
000025E0  EB E1  jmp     short loc_1800025C3
000025E2  49 8B C1  mov     rax, r9
000025E5  C3  retn
000025E6  33 C0  xor     eax, eax
000025E8  C3  retn

; FUNC 000025EC-000025F1 j__initialize_narrow_environment (5 bytes)
000025EC  E9 C2 21 00 00  jmp     _initialize_narrow_environment

; FUNC 00002628-0000262E sub_180002628 (6 bytes)
00002628  25 30 00 00 00  and     eax, 30h
0000262D  C3  retn

; FUNC 00002630-00002669 sub_180002630 (57 bytes)
00002630  48 83 EC 28  sub     rsp, 28h
00002634  E8 AF 0A 00 00  call    sub_1800030E8
00002639  85 C0  test    eax, eax
0000263B  74 21  jz      short loc_18000265E
0000263D  65 48 8B 04 25 30 00 00 00  mov     rax, gs:30h
00002646  48 8B 48 08  mov     rcx, [rax+8]
0000264A  EB 05  jmp     short loc_180002651
0000264C  48 3B C8  cmp     rcx, rax
0000264F  74 14  jz      short loc_180002665
00002651  33 C0  xor     eax, eax
00002653  F0 48 0F B1 0D 3C 73 01 00  lock cmpxchg cs:qword_180019998, rcx
0000265C  75 EE  jnz     short loc_18000264C
0000265E  32 C0  xor     al, al
00002660  48 83 C4 28  add     rsp, 28h
00002664  C3  retn
00002665  B0 01  mov     al, 1
00002667  EB F7  jmp     short loc_180002660

; FUNC 0000266C-000026A0 sub_18000266C (52 bytes)
0000266C  48 83 EC 28  sub     rsp, 28h
00002670  E8 73 0A 00 00  call    sub_1800030E8
00002675  85 C0  test    eax, eax
00002677  74 07  jz      short loc_180002680
00002679  E8 B6 08 00 00  call    sub_180002F34
0000267E  EB 19  jmp     short loc_180002699
00002680  E8 5B 0A 00 00  call    sub_1800030E0
00002685  8B C8  mov     ecx, eax; mode
00002687  E8 21 21 00 00  call    _configure_narrow_argv
0000268C  85 C0  test    eax, eax
0000268E  74 04  jz      short loc_180002694
00002690  32 C0  xor     al, al
00002692  EB 07  jmp     short loc_18000269B
00002694  E8 1A 21 00 00  call    _initialize_narrow_environment
00002699  B0 01  mov     al, 1
0000269B  48 83 C4 28  add     rsp, 28h
0000269F  C3  retn

; FUNC 000026A0-000026B5 sub_1800026A0 (21 bytes)
000026A0  48 83 EC 28  sub     rsp, 28h
000026A4  33 C9  xor     ecx, ecx
000026A6  E8 3D 01 00 00  call    sub_1800027E8
000026AB  84 C0  test    al, al
000026AD  0F 95 C0  setnz   al
000026B0  48 83 C4 28  add     rsp, 28h
000026B4  C3  retn

; FUNC 000026B8-000026E0 sub_1800026B8 (40 bytes)
000026B8  48 83 EC 28  sub     rsp, 28h
000026BC  E8 2F 21 00 00  call    sub_1800047F0
000026C1  84 C0  test    al, al
000026C3  75 04  jnz     short loc_1800026C9
000026C5  32 C0  xor     al, al
000026C7  EB 12  jmp     short loc_1800026DB
000026C9  E8 22 21 00 00  call    sub_1800047F0
000026CE  84 C0  test    al, al
000026D0  75 07  jnz     short loc_1800026D9
000026D2  E8 1D 21 00 00  call    sub_1800047F4
000026D7  EB EC  jmp     short loc_1800026C5
000026D9  B0 01  mov     al, 1
000026DB  48 83 C4 28  add     rsp, 28h
000026DF  C3  retn

; FUNC 000026E0-000026F5 sub_1800026E0 (21 bytes)
000026E0  48 83 EC 28  sub     rsp, 28h
000026E4  E8 0B 21 00 00  call    sub_1800047F4
000026E9  E8 06 21 00 00  call    sub_1800047F4
000026EE  B0 01  mov     al, 1
000026F0  48 83 C4 28  add     rsp, 28h
000026F4  C3  retn

; FUNC 000026F8-00002758 sub_1800026F8 (96 bytes)
000026F8  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000026FD  48 89 6C 24 10  mov     [rsp+arg_8], rbp
00002702  48 89 74 24 18  mov     [rsp+arg_10], rsi
00002707  57  push    rdi
00002708  48 83 EC 20  sub     rsp, 20h
0000270C  49 8B F9  mov     rdi, r9
0000270F  49 8B F0  mov     rsi, r8
00002712  8B DA  mov     ebx, edx
00002714  48 8B E9  mov     rbp, rcx
00002717  E8 CC 09 00 00  call    sub_1800030E8
0000271C  85 C0  test    eax, eax
0000271E  75 16  jnz     short loc_180002736
00002720  83 FB 01  cmp     ebx, 1
00002723  75 11  jnz     short loc_180002736
00002725  4C 8B C6  mov     r8, rsi
00002728  33 D2  xor     edx, edx
0000272A  48 8B CD  mov     rcx, rbp
0000272D  48 8B C7  mov     rax, rdi
00002730  FF 15 82 3A 00 00  call    cs:__guard_dispatch_icall_fptr
00002736  48 8B 54 24 58  mov     rdx, [rsp+28h+ExceptionPtr]; ExceptionPtr
0000273B  8B 4C 24 50  mov     ecx, [rsp+28h+ExceptionNum]; ExceptionNum
0000273F  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00002744  48 8B 6C 24 38  mov     rbp, [rsp+28h+arg_8]
00002749  48 8B 74 24 40  mov     rsi, [rsp+28h+arg_10]
0000274E  48 83 C4 20  add     rsp, 20h
00002752  5F  pop     rdi
00002753  E9 4F 20 00 00  jmp     _seh_filter_dll

; FUNC 00002758-00002788 sub_180002758 (48 bytes)
00002758  48 83 EC 28  sub     rsp, 28h
0000275C  E8 87 09 00 00  call    sub_1800030E8
00002761  85 C0  test    eax, eax
00002763  74 10  jz      short loc_180002775
00002765  48 8D 0D 3C 72 01 00  lea     rcx, Table; Table
0000276C  48 83 C4 28  add     rsp, 28h
00002770  E9 50 20 00 00  jmp     _execute_onexit_table
00002775  E8 86 20 00 00  call    sub_180004800
0000277A  85 C0  test    eax, eax
0000277C  75 05  jnz     short loc_180002783
0000277E  E8 54 20 00 00  call    _cexit
00002783  48 83 C4 28  add     rsp, 28h
00002787  C3  retn

; FUNC 00002788-0000279C sub_180002788 (20 bytes)
00002788  48 83 EC 28  sub     rsp, 28h
0000278C  33 C9  xor     ecx, ecx
0000278E  E8 69 20 00 00  call    sub_1800047FC
00002793  48 83 C4 28  add     rsp, 28h
00002797  E9 60 20 00 00  jmp     sub_1800047FC

; FUNC 0000279C-000027E5 sub_18000279C (73 bytes)
0000279C  40 53  push    rbx
0000279E  48 83 EC 20  sub     rsp, 20h
000027A2  0F B6 05 F7 71 01 00  movzx   eax, cs:byte_1800199A0
000027A9  85 C9  test    ecx, ecx
000027AB  BB 01 00 00 00  mov     ebx, 1
000027B0  0F 44 C3  cmovz   eax, ebx
000027B3  88 05 E7 71 01 00  mov     cs:byte_1800199A0, al
000027B9  E8 76 07 00 00  call    sub_180002F34
000027BE  E8 29 20 00 00  call    sub_1800047EC
000027C3  84 C0  test    al, al
000027C5  75 04  jnz     short loc_1800027CB
000027C7  32 C0  xor     al, al
000027C9  EB 14  jmp     short loc_1800027DF
000027CB  E8 1C 20 00 00  call    sub_1800047EC
000027D0  84 C0  test    al, al
000027D2  75 09  jnz     short loc_1800027DD
000027D4  33 C9  xor     ecx, ecx
000027D6  E8 1D 20 00 00  call    sub_1800047F8
000027DB  EB EA  jmp     short loc_1800027C7
000027DD  8A C3  mov     al, bl
000027DF  48 83 C4 20  add     rsp, 20h
000027E3  5B  pop     rbx
000027E4  C3  retn

; FUNC 000027E8-00002873 sub_1800027E8 (139 bytes)
000027E8  40 53  push    rbx
000027EA  48 83 EC 20  sub     rsp, 20h
000027EE  80 3D AC 71 01 00 00  cmp     cs:byte_1800199A1, 0
000027F5  8B D9  mov     ebx, ecx
000027F7  75 67  jnz     short loc_180002860
000027F9  83 F9 01  cmp     ecx, 1
000027FC  77 6A  ja      short loc_180002868
000027FE  E8 E5 08 00 00  call    sub_1800030E8
00002803  85 C0  test    eax, eax
00002805  74 28  jz      short loc_18000282F
00002807  85 DB  test    ebx, ebx
00002809  75 24  jnz     short loc_18000282F
0000280B  48 8D 0D 96 71 01 00  lea     rcx, Table; Table
00002812  E8 A2 1F 00 00  call    _initialize_onexit_table
00002817  85 C0  test    eax, eax
00002819  75 10  jnz     short loc_18000282B
0000281B  48 8D 0D 9E 71 01 00  lea     rcx, stru_1800199C0; Table
00002822  E8 92 1F 00 00  call    _initialize_onexit_table
00002827  85 C0  test    eax, eax
00002829  74 2E  jz      short loc_180002859
0000282B  32 C0  xor     al, al
0000282D  EB 33  jmp     short loc_180002862
0000282F  66 0F 6F 05 D9 3A 00 00  movdqa  xmm0, cs:xmmword_180006310
00002837  48 83 C8 FF  or      rax, 0FFFFFFFFFFFFFFFFh
0000283B  F3 0F 7F 05 65 71 01 00  movdqu  xmmword ptr cs:Table._first, xmm0
00002843  48 89 05 6E 71 01 00  mov     cs:Table._end, rax
0000284A  F3 0F 7F 05 6E 71 01 00  movdqu  xmmword ptr cs:stru_1800199C0._first, xmm0
00002852  48 89 05 77 71 01 00  mov     cs:stru_1800199C0._end, rax
00002859  C6 05 41 71 01 00 01  mov     cs:byte_1800199A1, 1
00002860  B0 01  mov     al, 1
00002862  48 83 C4 20  add     rsp, 20h
00002866  5B  pop     rbx
00002867  C3  retn
00002868  B9 05 00 00 00  mov     ecx, 5
0000286D  E8 6E 01 00 00  call    sub_1800029E0
00002872  CC  db 0CCh

; FUNC 00002874-0000290C sub_180002874 (152 bytes)
00002874  48 83 EC 18  sub     rsp, 18h
00002878  4C 8B C1  mov     r8, rcx
0000287B  B8 4D 5A 00 00  mov     eax, 5A4Dh
00002880  66 39 05 79 D7 FF FF  cmp     cs:180000000h, ax
00002887  75 78  jnz     short loc_180002901
00002889  48 63 0D AC D7 FF FF  movsxd  rcx, dword ptr cs:18000003Ch
00002890  48 8D 15 69 D7 FF FF  lea     rdx, cs:180000000h
00002897  48 03 CA  add     rcx, rdx
0000289A  81 39 50 45 00 00  cmp     dword ptr [rcx], 4550h
000028A0  75 5F  jnz     short loc_180002901
000028A2  B8 0B 02 00 00  mov     eax, 20Bh
000028A7  66 39 41 18  cmp     [rcx+18h], ax
000028AB  75 54  jnz     short loc_180002901
000028AD  4C 2B C2  sub     r8, rdx
000028B0  0F B7 51 14  movzx   edx, word ptr [rcx+14h]
000028B4  48 83 C2 18  add     rdx, 18h
000028B8  48 03 D1  add     rdx, rcx
000028BB  0F B7 41 06  movzx   eax, word ptr [rcx+6]
000028BF  48 8D 0C 80  lea     rcx, [rax+rax*4]
000028C3  4C 8D 0C CA  lea     r9, [rdx+rcx*8]
000028C7  48 89 14 24  mov     [rsp+18h+var_18], rdx
000028CB  49 3B D1  cmp     rdx, r9
000028CE  74 18  jz      short loc_1800028E8
000028D0  8B 4A 0C  mov     ecx, [rdx+0Ch]
000028D3  4C 3B C1  cmp     r8, rcx
000028D6  72 0A  jb      short loc_1800028E2
000028D8  8B 42 08  mov     eax, [rdx+8]
000028DB  03 C1  add     eax, ecx
000028DD  4C 3B C0  cmp     r8, rax
000028E0  72 08  jb      short loc_1800028EA
000028E2  48 83 C2 28  add     rdx, 28h ; '('
000028E6  EB DF  jmp     short loc_1800028C7
000028E8  33 D2  xor     edx, edx
000028EA  48 85 D2  test    rdx, rdx
000028ED  75 04  jnz     short loc_1800028F3
000028EF  32 C0  xor     al, al
000028F1  EB 14  jmp     short loc_180002907
000028F3  83 7A 24 00  cmp     dword ptr [rdx+24h], 0
000028F7  7D 04  jge     short loc_1800028FD
000028F9  32 C0  xor     al, al
000028FB  EB 0A  jmp     short loc_180002907
000028FD  B0 01  mov     al, 1
000028FF  EB 06  jmp     short loc_180002907
00002901  32 C0  xor     al, al
00002903  EB 02  jmp     short loc_180002907
00002905  32 C0  xor     al, al
00002907  48 83 C4 18  add     rsp, 18h
0000290B  C3  retn

; FUNC 0000290C-00002930 sub_18000290C (36 bytes)
0000290C  40 53  push    rbx
0000290E  48 83 EC 20  sub     rsp, 20h
00002912  8A D9  mov     bl, cl
00002914  E8 CF 07 00 00  call    sub_1800030E8
00002919  33 D2  xor     edx, edx
0000291B  85 C0  test    eax, eax
0000291D  74 0B  jz      short loc_18000292A
0000291F  84 DB  test    bl, bl
00002921  75 07  jnz     short loc_18000292A
00002923  48 87 15 6E 70 01 00  xchg    rdx, cs:qword_180019998
0000292A  48 83 C4 20  add     rsp, 20h
0000292E  5B  pop     rbx
0000292F  C3  retn

; FUNC 00002930-00002959 sub_180002930 (41 bytes)
00002930  40 53  push    rbx
00002932  48 83 EC 20  sub     rsp, 20h
00002936  80 3D 63 70 01 00 00  cmp     cs:byte_1800199A0, 0
0000293D  8A D9  mov     bl, cl
0000293F  74 04  jz      short loc_180002945
00002941  84 D2  test    dl, dl
00002943  75 0C  jnz     short loc_180002951
00002945  E8 AE 1E 00 00  call    sub_1800047F8
0000294A  8A CB  mov     cl, bl
0000294C  E8 A7 1E 00 00  call    sub_1800047F8
00002951  B0 01  mov     al, 1
00002953  48 83 C4 20  add     rsp, 20h
00002957  5B  pop     rbx
00002958  C3  retn

; FUNC 0000295C-00002996 sub_18000295C (58 bytes)
0000295C  40 53  push    rbx
0000295E  48 83 EC 20  sub     rsp, 20h
00002962  48 83 3D 3E 70 01 00 FF  cmp     cs:Table._first, 0FFFFFFFFFFFFFFFFh
0000296A  48 8B D9  mov     rbx, rcx
0000296D  75 07  jnz     short loc_180002976
0000296F  E8 57 1E 00 00  call    _crt_atexit
00002974  EB 0F  jmp     short loc_180002985
00002976  48 8B D3  mov     rdx, rbx; Function
00002979  48 8D 0D 28 70 01 00  lea     rcx, Table; Table
00002980  E8 3A 1E 00 00  call    _register_onexit_function
00002985  33 D2  xor     edx, edx
00002987  85 C0  test    eax, eax
00002989  48 0F 44 D3  cmovz   rdx, rbx
0000298D  48 8B C2  mov     rax, rdx
00002990  48 83 C4 20  add     rsp, 20h
00002994  5B  pop     rbx
00002995  C3  retn

; FUNC 000029B8-000029CF sub_1800029B8 (23 bytes)
000029B8  48 83 EC 28  sub     rsp, 28h
000029BC  E8 9B FF FF FF  call    sub_18000295C
000029C1  48 F7 D8  neg     rax
000029C4  1B C0  sbb     eax, eax
000029C6  F7 D8  neg     eax
000029C8  FF C8  dec     eax
000029CA  48 83 C4 28  add     rsp, 28h
000029CE  C3  retn

; FUNC 000029D0-000029D8 sub_1800029D0 (8 bytes)
000029D0  48 8D 05 A1 71 01 00  lea     rax, unk_180019B78
000029D7  C3  retn

; FUNC 000029D8-000029E0 sub_1800029D8 (8 bytes)
000029D8  83 25 F9 6F 01 00 00  and     cs:dword_1800199D8, 0
000029DF  C3  retn

; FUNC 000029E0-00002B2B sub_1800029E0 (331 bytes)
000029E0  48 89 5C 24 08  mov     [rsp-8+arg_0], rbx
000029E5  55  push    rbp
000029E6  48 8D AC 24 40 FB FF FF  lea     rbp, [rsp-4C0h]
000029EE  48 81 EC C0 05 00 00  sub     rsp, 5C0h
000029F5  8B D9  mov     ebx, ecx
000029F7  B9 17 00 00 00  mov     ecx, 17h; ProcessorFeature
000029FC  FF 15 66 36 00 00  call    cs:IsProcessorFeaturePresent; KERNEL32
00002A02  85 C0  test    eax, eax
00002A04  74 04  jz      short loc_180002A0A
00002A06  8B CB  mov     ecx, ebx
00002A08  CD 29  int     29h; Win8: RtlFailFast(ecx)
00002A0A  B9 03 00 00 00  mov     ecx, 3
00002A0F  E8 C4 FF FF FF  call    sub_1800029D8
00002A14  33 D2  xor     edx, edx; Val
00002A16  48 8D 4D F0  lea     rcx, [rbp+4C0h+ContextRecord]; void *
00002A1A  41 B8 D0 04 00 00  mov     r8d, 4D0h; Size
00002A20  E8 70 1D 00 00  call    memset
00002A25  48 8D 4D F0  lea     rcx, [rbp+4C0h+ContextRecord]; ContextRecord
00002A29  FF 15 01 36 00 00  call    cs:RtlCaptureContext; KERNEL32
00002A2F  48 8B 9D E8 00 00 00  mov     rbx, [rbp+4C0h+ContextRecord.Rip]
00002A36  48 8D 95 D8 04 00 00  lea     rdx, [rbp+4C0h+ImageBase]; ImageBase
00002A3D  48 8B CB  mov     rcx, rbx; ControlPc
00002A40  45 33 C0  xor     r8d, r8d; HistoryTable
00002A43  FF 15 EF 35 00 00  call    cs:RtlLookupFunctionEntry; KERNEL32
00002A49  48 85 C0  test    rax, rax
00002A4C  74 3C  jz      short loc_180002A8A
00002A4E  48 83 64 24 38 00  and     [rsp+5C0h+var_588], 0
00002A54  48 8D 8D E0 04 00 00  lea     rcx, [rbp+4C0h+arg_10]
00002A5B  48 8B 95 D8 04 00 00  mov     rdx, [rbp+4C0h+ImageBase]; ImageBase
00002A62  4C 8B C8  mov     r9, rax; FunctionEntry
00002A65  48 89 4C 24 30  mov     [rsp+5C0h+EstablisherFrame], rcx; EstablisherFrame
00002A6A  4C 8B C3  mov     r8, rbx; ControlPc
00002A6D  48 8D 8D E8 04 00 00  lea     rcx, [rbp+4C0h+arg_18]
00002A74  48 89 4C 24 28  mov     [rsp+5C0h+HandlerData], rcx; HandlerData
00002A79  48 8D 4D F0  lea     rcx, [rbp+4C0h+ContextRecord]
00002A7D  48 89 4C 24 20  mov     [rsp+5C0h+var_5A0], rcx; ContextRecord
00002A82  33 C9  xor     ecx, ecx; HandlerType
00002A84  FF 15 B6 35 00 00  call    cs:RtlVirtualUnwind; KERNEL32
00002A8A  48 8B 85 C8 04 00 00  mov     rax, [rbp+4C8h]
00002A91  48 8D 4C 24 50  lea     rcx, [rsp+5C0h+var_570]; void *
00002A96  48 89 85 E8 00 00 00  mov     [rbp+4C0h+ContextRecord.Rip], rax
00002A9D  33 D2  xor     edx, edx; Val
00002A9F  48 8D 85 C8 04 00 00  lea     rax, [rbp+4C8h]
00002AA6  41 B8 98 00 00 00  mov     r8d, 98h; Size
00002AAC  48 83 C0 08  add     rax, 8
00002AB0  48 89 85 88 00 00 00  mov     [rbp+4C0h+ContextRecord.Rsp], rax
00002AB7  E8 D9 1C 00 00  call    memset
00002ABC  48 8B 85 C8 04 00 00  mov     rax, [rbp+4C8h]
00002AC3  48 89 44 24 60  mov     [rsp+5C0h+var_560], rax
00002AC8  C7 44 24 50 15 00 00 40  mov     [rsp+5C0h+var_570], 40000015h
00002AD0  C7 44 24 54 01 00 00 00  mov     [rsp+5C0h+var_56C], 1
00002AD8  FF 15 6A 35 00 00  call    cs:IsDebuggerPresent; KERNEL32
00002ADE  83 F8 01  cmp     eax, 1
00002AE1  48 8D 44 24 50  lea     rax, [rsp+5C0h+var_570]
00002AE6  48 89 44 24 40  mov     [rsp+5C0h+ExceptionInfo.ExceptionRecord], rax
00002AEB  48 8D 45 F0  lea     rax, [rbp+4C0h+ContextRecord]
00002AEF  0F 94 C3  setz    bl
00002AF2  48 89 44 24 48  mov     [rsp+5C0h+ExceptionInfo.ContextRecord], rax
00002AF7  33 C9  xor     ecx, ecx; lpTopLevelExceptionFilter
00002AF9  FF 15 59 35 00 00  call    cs:SetUnhandledExceptionFilter; KERNEL32
00002AFF  48 8D 4C 24 40  lea     rcx, [rsp+5C0h+ExceptionInfo]; ExceptionInfo
00002B04  FF 15 46 35 00 00  call    cs:UnhandledExceptionFilter; KERNEL32
00002B0A  85 C0  test    eax, eax
00002B0C  75 0C  jnz     short loc_180002B1A
00002B0E  84 DB  test    bl, bl
00002B10  75 08  jnz     short loc_180002B1A
00002B12  8D 48 03  lea     ecx, [rax+3]
00002B15  E8 BE FE FF FF  call    sub_1800029D8
00002B1A  48 8B 9C 24 D0 05 00 00  mov     rbx, [rsp+5C0h+arg_0]
00002B22  48 81 C4 C0 05 00 00  add     rsp, 5C0h
00002B29  5D  pop     rbp
00002B2A  C3  retn

; FUNC 00002B2C-00002B66 sub_180002B2C (58 bytes)
00002B2C  48 81 EC 98 00 00 00  sub     rsp, 98h
00002B33  33 D2  xor     edx, edx; Val
00002B35  48 8D 4C 24 20  lea     rcx, [rsp+98h+StartupInfo]; void *
00002B3A  44 8D 42 68  lea     r8d, [rdx+68h]; Size
00002B3E  E8 52 1C 00 00  call    memset
00002B43  48 8D 4C 24 20  lea     rcx, [rsp+98h+StartupInfo]; lpStartupInfo
00002B48  FF 15 12 35 00 00  call    cs:GetStartupInfoW; KERNEL32
00002B4E  F6 44 24 5C 01  test    byte ptr [rsp+98h+StartupInfo.dwFlags], 1
00002B53  B8 0A 00 00 00  mov     eax, 0Ah
00002B58  66 0F 45 44 24 60  cmovnz  ax, [rsp+98h+StartupInfo.wShowWindow]
00002B5E  48 81 C4 98 00 00 00  add     rsp, 98h
00002B65  C3  retn

; FUNC 00002B70-00002B73 sub_180002B70 (3 bytes)
00002B70  33 C0  xor     eax, eax
00002B72  C3  retn

; FUNC 00002B74-00002BC5 sub_180002B74 (81 bytes)
00002B74  48 83 EC 28  sub     rsp, 28h
00002B78  33 C9  xor     ecx, ecx; lpModuleName
00002B7A  FF 15 F0 34 00 00  call    cs:GetModuleHandleW; KERNEL32
00002B80  48 85 C0  test    rax, rax
00002B83  74 39  jz      short loc_180002BBE
00002B85  B9 4D 5A 00 00  mov     ecx, 5A4Dh
00002B8A  66 39 08  cmp     [rax], cx
00002B8D  75 2F  jnz     short loc_180002BBE
00002B8F  48 63 48 3C  movsxd  rcx, dword ptr [rax+3Ch]
00002B93  48 03 C8  add     rcx, rax
00002B96  81 39 50 45 00 00  cmp     dword ptr [rcx], 4550h
00002B9C  75 20  jnz     short loc_180002BBE
00002B9E  B8 0B 02 00 00  mov     eax, 20Bh
00002BA3  66 39 41 18  cmp     [rcx+18h], ax
00002BA7  75 15  jnz     short loc_180002BBE
00002BA9  83 B9 84 00 00 00 0E  cmp     dword ptr [rcx+84h], 0Eh
00002BB0  76 0C  jbe     short loc_180002BBE
00002BB2  83 B9 F8 00 00 00 00  cmp     dword ptr [rcx+0F8h], 0
00002BB9  0F 95 C0  setnz   al
00002BBC  EB 02  jmp     short loc_180002BC0
00002BBE  32 C0  xor     al, al
00002BC0  48 83 C4 28  add     rsp, 28h
00002BC4  C3  retn

; FUNC 00002BC8-00002BD6 sub_180002BC8 (14 bytes)
00002BC8  48 8D 0D 0D 00 00 00  lea     rcx, sub_180002BDC
00002BCF  48 FF 25 82 34 00 00  jmp     cs:SetUnhandledExceptionFilter; KERNEL32

; FUNC 00002BDC-00002C37 sub_180002BDC (91 bytes)
00002BDC  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00002BE1  57  push    rdi
00002BE2  48 83 EC 20  sub     rsp, 20h
00002BE6  48 8B 19  mov     rbx, [rcx]
00002BE9  48 8B F9  mov     rdi, rcx
00002BEC  81 3B 63 73 6D E0  cmp     dword ptr [rbx], 0E06D7363h
00002BF2  75 1C  jnz     short loc_180002C10
00002BF4  83 7B 18 04  cmp     dword ptr [rbx+18h], 4
00002BF8  75 16  jnz     short loc_180002C10
00002BFA  8B 53 20  mov     edx, [rbx+20h]
00002BFD  8D 82 E0 FA 6C E6  lea     eax, [rdx-19930520h]
00002C03  83 F8 02  cmp     eax, 2
00002C06  76 15  jbe     short loc_180002C1D
00002C08  81 FA 00 40 99 01  cmp     edx, 1994000h
00002C0E  74 0D  jz      short loc_180002C1D
00002C10  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00002C15  33 C0  xor     eax, eax
00002C17  48 83 C4 20  add     rsp, 20h
00002C1B  5F  pop     rdi
00002C1C  C3  retn
00002C1D  E8 67 1B 00 00  call    __current_exception
00002C22  48 89 18  mov     [rax], rbx
00002C25  48 8B 5F 08  mov     rbx, [rdi+8]
00002C29  E8 61 1B 00 00  call    __current_exception_context
00002C2E  48 89 18  mov     [rax], rbx
00002C31  E8 A7 1B 00 00  call    terminate
00002C36  CC  db 0CCh

; FUNC 00002C38-00002C74 sub_180002C38 (60 bytes)
00002C38  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00002C3D  57  push    rdi
00002C3E  48 83 EC 20  sub     rsp, 20h
00002C42  48 8D 1D 47 49 01 00  lea     rbx, qword_180017590
00002C49  48 8D 3D 40 49 01 00  lea     rdi, qword_180017590
00002C50  EB 12  jmp     short loc_180002C64
00002C52  48 8B 03  mov     rax, [rbx]
00002C55  48 85 C0  test    rax, rax
00002C58  74 06  jz      short loc_180002C60
00002C5A  FF 15 58 35 00 00  call    cs:__guard_dispatch_icall_fptr
00002C60  48 83 C3 08  add     rbx, 8
00002C64  48 3B DF  cmp     rbx, rdi
00002C67  72 E9  jb      short loc_180002C52
00002C69  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00002C6E  48 83 C4 20  add     rsp, 20h
00002C72  5F  pop     rdi
00002C73  C3  retn

; FUNC 00002C74-00002CB0 sub_180002C74 (60 bytes)
00002C74  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00002C79  57  push    rdi
00002C7A  48 83 EC 20  sub     rsp, 20h
00002C7E  48 8D 1D 1B 49 01 00  lea     rbx, qword_1800175A0
00002C85  48 8D 3D 14 49 01 00  lea     rdi, qword_1800175A0
00002C8C  EB 12  jmp     short loc_180002CA0
00002C8E  48 8B 03  mov     rax, [rbx]
00002C91  48 85 C0  test    rax, rax
00002C94  74 06  jz      short loc_180002C9C
00002C96  FF 15 1C 35 00 00  call    cs:__guard_dispatch_icall_fptr
00002C9C  48 83 C3 08  add     rbx, 8
00002CA0  48 3B DF  cmp     rbx, rdi
00002CA3  72 E9  jb      short loc_180002C8E
00002CA5  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00002CAA  48 83 C4 20  add     rsp, 20h
00002CAE  5F  pop     rdi
00002CAF  C3  retn

; FUNC 00002CB0-00002CB3 _guard_check_icall_nop (3 bytes)
00002CB0  C2 00 00  retn    0

; FUNC 00002CB4-00002CB8 sub_180002CB4 (4 bytes)
00002CB4  48 8B 01  mov     rax, [rcx]
00002CB7  C3  retn

; FUNC 00002CB8-00002CBC sub_180002CB8 (4 bytes)
00002CB8  48 8B 01  mov     rax, [rcx]
00002CBB  C3  retn

; FUNC 00002CFC-00002CFF nullsub_1 (3 bytes)
00002CFC  C2 00 00  retn    0

; FUNC 00002D00-00002D3A sub_180002D00 (58 bytes)
00002D00  48 83 EC 28  sub     rsp, 28h
00002D04  4C 8D 05 75 38 01 00  lea     r8, unk_180016580
00002D0B  48 8B C1  mov     rax, rcx
00002D0E  48 8D 15 6B 38 01 00  lea     rdx, unk_180016580
00002D15  49 2B C0  sub     rax, r8
00002D18  49 2B D0  sub     rdx, r8
00002D1B  48 3B C2  cmp     rax, rdx
00002D1E  77 15  ja      short loc_180002D35
00002D20  48 8B 05 A9 34 00 00  mov     rax, cs:__castguard_check_failure_os_handled_fptr
00002D27  48 85 C0  test    rax, rax
00002D2A  74 09  jz      short loc_180002D35
00002D2C  48 8B 05 9D 34 00 00  mov     rax, cs:__castguard_check_failure_os_handled_fptr
00002D33  FF D0  call    rax ; __castguard_check_failure_os_handled_fptr
00002D35  48 83 C4 28  add     rsp, 28h
00002D39  C3  retn

; FUNC 00002D3C-00002D5A sub_180002D3C (30 bytes)
00002D3C  48 83 EC 28  sub     rsp, 28h
00002D40  48 8B 05 89 34 00 00  mov     rax, cs:__castguard_check_failure_os_handled_fptr
00002D47  48 85 C0  test    rax, rax
00002D4A  74 09  jz      short loc_180002D55
00002D4C  48 8B 05 7D 34 00 00  mov     rax, cs:__castguard_check_failure_os_handled_fptr
00002D53  FF D0  call    rax ; __castguard_check_failure_os_handled_fptr
00002D55  48 83 C4 28  add     rsp, 28h
00002D59  C3  retn

; FUNC 00002D5C-00002D93 sub_180002D5C (55 bytes)
00002D5C  48 83 EC 28  sub     rsp, 28h
00002D60  4C 8D 05 19 38 01 00  lea     r8, unk_180016580
00002D67  48 8B C1  mov     rax, rcx
00002D6A  48 8D 15 0F 38 01 00  lea     rdx, unk_180016580
00002D71  49 2B C0  sub     rax, r8
00002D74  49 2B D0  sub     rdx, r8
00002D77  48 3B C2  cmp     rax, rdx
00002D7A  77 12  ja      short loc_180002D8E
00002D7C  48 8B 05 5D 6C 01 00  mov     rax, cs:qword_1800199E0
00002D83  48 85 C0  test    rax, rax
00002D86  74 06  jz      short loc_180002D8E
00002D88  FF 15 2A 34 00 00  call    cs:__guard_dispatch_icall_fptr
00002D8E  48 83 C4 28  add     rsp, 28h
00002D92  C3  retn

; FUNC 00002D94-00002DAF sub_180002D94 (27 bytes)
00002D94  48 83 EC 28  sub     rsp, 28h
00002D98  48 8B 05 41 6C 01 00  mov     rax, cs:qword_1800199E0
00002D9F  48 85 C0  test    rax, rax
00002DA2  74 06  jz      short loc_180002DAA
00002DA4  FF 15 0E 34 00 00  call    cs:__guard_dispatch_icall_fptr
00002DAA  48 83 C4 28  add     rsp, 28h
00002DAE  C3  retn

; FUNC 00002DD0-00002DDB sub_180002DD0 (11 bytes)
00002DD0  48 87 0D 09 6C 01 00  xchg    rcx, cs:qword_1800199E0
00002DD7  48 8B C1  mov     rax, rcx
00002DDA  C3  retn

; FUNC 00002E4C-00002E4F nullsub_2 (3 bytes)
00002E4C  C2 00 00  retn    0

; FUNC 00002E50-00002EA3 sub_180002E50 (83 bytes)
00002E50  48 83 EC 28  sub     rsp, 28h
00002E54  48 8B C1  mov     rax, rcx
00002E57  48 2B C2  sub     rax, rdx
00002E5A  48 8D 15 9F 36 01 00  lea     rdx, unk_180016500
00002E61  48 2B C2  sub     rax, rdx
00002E64  48 83 C0 80  add     rax, 0FFFFFFFFFFFFFF80h
00002E68  49 3B C0  cmp     rax, r8
00002E6B  76 31  jbe     short loc_180002E9E
00002E6D  4C 8D 05 0C 37 01 00  lea     r8, unk_180016580
00002E74  48 8B D1  mov     rdx, rcx
00002E77  48 8D 05 02 37 01 00  lea     rax, unk_180016580
00002E7E  49 2B D0  sub     rdx, r8
00002E81  49 2B C0  sub     rax, r8
00002E84  48 3B D0  cmp     rdx, rax
00002E87  77 15  ja      short loc_180002E9E
00002E89  48 8B 05 40 33 00 00  mov     rax, cs:__castguard_check_failure_os_handled_fptr
00002E90  48 85 C0  test    rax, rax
00002E93  74 09  jz      short loc_180002E9E
00002E95  48 8B 05 34 33 00 00  mov     rax, cs:__castguard_check_failure_os_handled_fptr
00002E9C  FF D0  call    rax ; __castguard_check_failure_os_handled_fptr
00002E9E  48 83 C4 28  add     rsp, 28h
00002EA2  C3  retn

; FUNC 00002EA4-00002EF4 sub_180002EA4 (80 bytes)
00002EA4  48 83 EC 28  sub     rsp, 28h
00002EA8  48 8B C1  mov     rax, rcx
00002EAB  48 2B C2  sub     rax, rdx
00002EAE  48 8D 15 4B 36 01 00  lea     rdx, unk_180016500
00002EB5  48 2B C2  sub     rax, rdx
00002EB8  48 83 C0 80  add     rax, 0FFFFFFFFFFFFFF80h
00002EBC  49 3B C0  cmp     rax, r8
00002EBF  76 2E  jbe     short loc_180002EEF
00002EC1  4C 8D 05 B8 36 01 00  lea     r8, unk_180016580
00002EC8  48 8B D1  mov     rdx, rcx
00002ECB  48 8D 05 AE 36 01 00  lea     rax, unk_180016580
00002ED2  49 2B D0  sub     rdx, r8
00002ED5  49 2B C0  sub     rax, r8
00002ED8  48 3B D0  cmp     rdx, rax
00002EDB  77 12  ja      short loc_180002EEF
00002EDD  48 8B 05 FC 6A 01 00  mov     rax, cs:qword_1800199E0
00002EE4  48 85 C0  test    rax, rax
00002EE7  74 06  jz      short loc_180002EEF
00002EE9  FF 15 C9 32 00 00  call    cs:__guard_dispatch_icall_fptr
00002EEF  48 83 C4 28  add     rsp, 28h
00002EF3  C3  retn

; FUNC 00002EF4-00002F0E sub_180002EF4 (26 bytes)
00002EF4  48 2B CA  sub     rcx, rdx
00002EF7  48 8D 05 02 36 01 00  lea     rax, unk_180016500
00002EFE  48 2B C8  sub     rcx, rax
00002F01  33 C0  xor     eax, eax
00002F03  48 83 C1 80  add     rcx, 0FFFFFFFFFFFFFF80h
00002F07  49 3B C8  cmp     rcx, r8
00002F0A  0F 97 C0  setnbe  al
00002F0D  C3  retn

; FUNC 00002F28-00002F2B sub_180002F28 (3 bytes)
00002F28  33 C0  xor     eax, eax
00002F2A  C3  retn

; FUNC 00002F2C-00002F31 j_free (5 bytes)
00002F2C  E9 B2 18 00 00  jmp     free

; FUNC 00002F34-000030E0 sub_180002F34 (428 bytes)
00002F34  48 89 5C 24 10  mov     [rsp+arg_8], rbx
00002F39  48 89 74 24 18  mov     [rsp+arg_10], rsi
00002F3E  57  push    rdi
00002F3F  48 83 EC 10  sub     rsp, 10h
00002F43  33 C0  xor     eax, eax
00002F45  33 C9  xor     ecx, ecx
00002F47  0F A2  cpuid
00002F49  44 8B C1  mov     r8d, ecx
00002F4C  45 33 DB  xor     r11d, r11d
00002F4F  44 8B D2  mov     r10d, edx
00002F52  41 81 F0 6E 74 65 6C  xor     r8d, 6C65746Eh
00002F59  41 81 F2 69 6E 65 49  xor     r10d, 49656E69h
00002F60  44 8B CB  mov     r9d, ebx
00002F63  8B F0  mov     esi, eax
00002F65  33 C9  xor     ecx, ecx
00002F67  41 8D 43 01  lea     eax, [r11+1]
00002F6B  45 0B D0  or      r10d, r8d
00002F6E  0F A2  cpuid
00002F70  41 81 F1 47 65 6E 75  xor     r9d, 756E6547h
00002F77  89 04 24  mov     [rsp+18h+var_18], eax
00002F7A  45 0B D1  or      r10d, r9d
00002F7D  89 5C 24 04  mov     [rsp+18h+var_14], ebx
00002F81  8B F9  mov     edi, ecx
00002F83  89 4C 24 08  mov     [rsp+18h+var_10], ecx
00002F87  89 54 24 0C  mov     [rsp+18h+var_C], edx
00002F8B  75 5B  jnz     short loc_180002FE8
00002F8D  48 83 0D E3 63 01 00 FF  or      cs:qword_180019378, 0FFFFFFFFFFFFFFFFh
00002F95  25 F0 3F FF 0F  and     eax, 0FFF3FF0h
00002F9A  48 C7 05 CB 63 01 00 00 80 00 00  mov     cs:qword_180019370, 8000h
00002FA5  3D C0 06 01 00  cmp     eax, 106C0h
00002FAA  74 28  jz      short loc_180002FD4
00002FAC  3D 60 06 02 00  cmp     eax, 20660h
00002FB1  74 21  jz      short loc_180002FD4
00002FB3  3D 70 06 02 00  cmp     eax, 20670h
00002FB8  74 1A  jz      short loc_180002FD4
00002FBA  05 B0 F9 FC FF  add     eax, 0FFFCF9B0h
00002FBF  83 F8 20  cmp     eax, 20h ; ' '
00002FC2  77 24  ja      short loc_180002FE8
00002FC4  48 B9 01 00 01 00 01 00 00 00  mov     rcx, 100010001h
00002FCE  48 0F A3 C1  bt      rcx, rax
00002FD2  73 14  jnb     short loc_180002FE8
00002FD4  44 8B 05 0D 6A 01 00  mov     r8d, cs:dword_1800199E8
00002FDB  41 83 C8 01  or      r8d, 1
00002FDF  44 89 05 02 6A 01 00  mov     cs:dword_1800199E8, r8d
00002FE6  EB 07  jmp     short loc_180002FEF
00002FE8  44 8B 05 F9 69 01 00  mov     r8d, cs:dword_1800199E8
00002FEF  B8 07 00 00 00  mov     eax, 7
00002FF4  44 8D 48 FB  lea     r9d, [rax-5]
00002FF8  3B F0  cmp     esi, eax
00002FFA  7C 26  jl      short loc_180003022
00002FFC  33 C9  xor     ecx, ecx
00002FFE  0F A2  cpuid
00003000  89 04 24  mov     [rsp+18h+var_18], eax
00003003  44 8B DB  mov     r11d, ebx
00003006  89 5C 24 04  mov     [rsp+18h+var_14], ebx
0000300A  89 4C 24 08  mov     [rsp+18h+var_10], ecx
0000300E  89 54 24 0C  mov     [rsp+18h+var_C], edx
00003012  0F BA E3 09  bt      ebx, 9
00003016  73 0A  jnb     short loc_180003022
00003018  45 0B C1  or      r8d, r9d
0000301B  44 89 05 C6 69 01 00  mov     cs:dword_1800199E8, r8d
00003022  C7 05 3C 63 01 00 01 00 00 00  mov     cs:dword_180019368, 1
0000302C  44 89 0D 39 63 01 00  mov     cs:dword_18001936C, r9d
00003033  0F BA E7 14  bt      edi, 14h
00003037  0F 83 91 00 00 00  jnb     loc_1800030CE
0000303D  44 89 0D 24 63 01 00  mov     cs:dword_180019368, r9d
00003044  BB 06 00 00 00  mov     ebx, 6
00003049  89 1D 1D 63 01 00  mov     cs:dword_18001936C, ebx
0000304F  0F BA E7 1B  bt      edi, 1Bh
00003053  73 79  jnb     short loc_1800030CE
00003055  0F BA E7 1C  bt      edi, 1Ch
00003059  73 73  jnb     short loc_1800030CE
0000305B  33 C9  xor     ecx, ecx
0000305D  0F 01 D0  xgetbv
00003060  48 C1 E2 20  shl     rdx, 20h
00003064  48 0B D0  or      rdx, rax
00003067  48 89 54 24 20  mov     [rsp+18h+arg_0], rdx
0000306C  48 8B 44 24 20  mov     rax, [rsp+18h+arg_0]
00003071  22 C3  and     al, bl
00003073  3A C3  cmp     al, bl
00003075  75 57  jnz     short loc_1800030CE
00003077  8B 05 EF 62 01 00  mov     eax, cs:dword_18001936C
0000307D  83 C8 08  or      eax, 8
00003080  C7 05 DE 62 01 00 03 00 00 00  mov     cs:dword_180019368, 3
0000308A  89 05 DC 62 01 00  mov     cs:dword_18001936C, eax
00003090  41 F6 C3 20  test    r11b, 20h
00003094  74 38  jz      short loc_1800030CE
00003096  83 C8 20  or      eax, 20h
00003099  C7 05 C5 62 01 00 05 00 00 00  mov     cs:dword_180019368, 5
000030A3  89 05 C3 62 01 00  mov     cs:dword_18001936C, eax
000030A9  B8 00 00 03 D0  mov     eax, 0D0030000h
000030AE  44 23 D8  and     r11d, eax
000030B1  44 3B D8  cmp     r11d, eax
000030B4  75 18  jnz     short loc_1800030CE
000030B6  48 8B 44 24 20  mov     rax, [rsp+18h+arg_0]
000030BB  24 E0  and     al, 0E0h
000030BD  3C E0  cmp     al, 0E0h
000030BF  75 0D  jnz     short loc_1800030CE
000030C1  83 0D A4 62 01 00 40  or      cs:dword_18001936C, 40h
000030C8  89 1D 9A 62 01 00  mov     cs:dword_180019368, ebx
000030CE  48 8B 5C 24 28  mov     rbx, [rsp+18h+arg_8]
000030D3  33 C0  xor     eax, eax
000030D5  48 8B 74 24 30  mov     rsi, [rsp+18h+arg_10]
000030DA  48 83 C4 10  add     rsp, 10h
000030DE  5F  pop     rdi
000030DF  C3  retn

; FUNC 000030E0-000030E6 sub_1800030E0 (6 bytes)
000030E0  B8 01 00 00 00  mov     eax, 1
000030E5  C3  retn

; FUNC 000030E8-000030F4 sub_1800030E8 (12 bytes)
000030E8  33 C0  xor     eax, eax
000030EA  39 05 40 67 01 00  cmp     cs:dword_180019830, eax
000030F0  0F 95 C0  setnz   al
000030F3  C3  retn

; FUNC 00003660-0000366E sub_180003660_manual (14 bytes)
00003660  65 48 8B 04 25 30 00 00 00  mov     rax, gs:[30h]
00003669  48 8B 40 08  mov     rax, [rax+8]
0000366D  C3  retn

; FUNC 0000476B-00004771 __std_exception_copy (6 bytes)
0000476B  FF 25 87 19 00 00  jmp     cs:__imp___std_exception_copy; VCRUNTIME140

; FUNC 00004771-00004777 __std_exception_destroy (6 bytes)
00004771  FF 25 79 19 00 00  jmp     cs:__imp___std_exception_destroy; VCRUNTIME140

; FUNC 00004777-0000477D _CxxThrowException (6 bytes)
00004777  FF 25 63 19 00 00  jmp     cs:__imp__CxxThrowException; VCRUNTIME140

; FUNC 0000477D-00004783 __C_specific_handler (6 bytes)
0000477D  FF 25 55 19 00 00  jmp     cs:__imp___C_specific_handler; VCRUNTIME140

; FUNC 00004783-00004789 __std_type_info_destroy_list (6 bytes)
00004783  FF 25 3F 19 00 00  jmp     cs:__imp___std_type_info_destroy_list; VCRUNTIME140

; FUNC 00004789-0000478F __current_exception (6 bytes)
00004789  FF 25 59 19 00 00  jmp     cs:__imp___current_exception; VCRUNTIME140

; FUNC 0000478F-00004795 __current_exception_context (6 bytes)
0000478F  FF 25 1B 19 00 00  jmp     cs:__imp___current_exception_context; VCRUNTIME140

; FUNC 00004795-0000479B memset (6 bytes)
00004795  FF 25 1D 19 00 00  jmp     cs:__imp_memset; VCRUNTIME140

; FUNC 0000479B-000047A1 _initterm (6 bytes)
0000479B  FF 25 C7 19 00 00  jmp     cs:__imp__initterm; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047A1-000047A7 _initterm_e (6 bytes)
000047A1  FF 25 E1 19 00 00  jmp     cs:__imp__initterm_e; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047A7-000047AD _seh_filter_dll (6 bytes)
000047A7  FF 25 B3 19 00 00  jmp     cs:__imp__seh_filter_dll; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047AD-000047B3 _configure_narrow_argv (6 bytes)
000047AD  FF 25 A5 19 00 00  jmp     cs:__imp__configure_narrow_argv; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047B3-000047B9 _initialize_narrow_environment (6 bytes)
000047B3  FF 25 97 19 00 00  jmp     cs:__imp__initialize_narrow_environment; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047B9-000047BF _initialize_onexit_table (6 bytes)
000047B9  FF 25 89 19 00 00  jmp     cs:__imp__initialize_onexit_table; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047BF-000047C5 _register_onexit_function (6 bytes)
000047BF  FF 25 7B 19 00 00  jmp     cs:__imp__register_onexit_function; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047C5-000047CB _execute_onexit_table (6 bytes)
000047C5  FF 25 B5 19 00 00  jmp     cs:__imp__execute_onexit_table; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047CB-000047D1 _crt_atexit (6 bytes)
000047CB  FF 25 67 19 00 00  jmp     cs:__imp__crt_atexit; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047D7-000047DD _cexit (6 bytes)
000047D7  FF 25 4B 19 00 00  jmp     cs:__imp__cexit; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047DD-000047E3 terminate (6 bytes)
000047DD  FF 25 8D 19 00 00  jmp     cs:__imp_terminate; api-ms-win-crt-runtime-l1-1-0

; FUNC 000047E3-000047E9 free (6 bytes)
000047E3  FF 25 2F 19 00 00  jmp     cs:__imp_free; api-ms-win-crt-heap-l1-1-0

; FUNC 000047EC-000047EF sub_1800047EC (3 bytes)
000047EC  B0 01  mov     al, 1
000047EE  C3  retn

; FUNC 000047F0-000047F3 sub_1800047F0 (3 bytes)
000047F0  B0 01  mov     al, 1
000047F2  C3  retn

; FUNC 000047F4-000047F7 sub_1800047F4 (3 bytes)
000047F4  B0 01  mov     al, 1
000047F6  C3  retn

; FUNC 000047F8-000047FB sub_1800047F8 (3 bytes)
000047F8  B0 01  mov     al, 1
000047FA  C3  retn

; FUNC 000047FC-000047FF sub_1800047FC (3 bytes)
000047FC  B0 01  mov     al, 1
000047FE  C3  retn

; FUNC 00004800-00004803 sub_180004800 (3 bytes)
00004800  33 C0  xor     eax, eax
00004802  C3  retn

; FUNC 00004804-00004809 j_j_free_0 (5 bytes)
00004804  E9 23 E7 FF FF  jmp     j_free

; FUNC 0000480C-00004811 sub_18000480C (5 bytes)
0000480C  E9 0B 00 00 00  jmp     sub_18000481C

; FUNC 00004814-00004819 j_j_j_free_0 (5 bytes)
00004814  E9 EB FF FF FF  jmp     j_j_free_0

; FUNC 0000481C-00004858 sub_18000481C (60 bytes)
0000481C  40 53  push    rbx
0000481E  48 83 EC 20  sub     rsp, 20h
00004822  48 8B D9  mov     rbx, rcx
00004825  EB 0F  jmp     short loc_180004836
00004827  48 8B CB  mov     rcx, rbx; Size
0000482A  E8 53 00 00 00  call    _callnewh
0000482F  85 C0  test    eax, eax
00004831  74 13  jz      short loc_180004846
00004833  48 8B CB  mov     rcx, rbx; Size
00004836  E8 4D 00 00 00  call    malloc
0000483B  48 85 C0  test    rax, rax
0000483E  74 E7  jz      short loc_180004827
00004840  48 83 C4 20  add     rsp, 20h
00004844  5B  pop     rbx
00004845  C3  retn
00004846  48 83 FB FF  cmp     rbx, 0FFFFFFFFFFFFFFFFh
0000484A  74 06  jz      short loc_180004852
0000484C  E8 D7 D7 FF FF  call    sub_180002028
00004851  CC  align 2
00004852  E8 F1 D7 FF FF  call    sub_180002048
00004857  CC  align 8

; FUNC 00004858-0000485E ?__ExceptionPtrDestroy@@YAXPEAX@Z (6 bytes)
00004858  FF 25 3A 18 00 00  jmp     cs:__ExceptionPtrDestroy(void *); MSVCP140

; FUNC 0000485E-00004864 ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z (6 bytes)
0000485E  FF 25 3C 18 00 00  jmp     cs:__ExceptionPtrCopy(void *,void const *); MSVCP140

; FUNC 00004864-0000486A WideCharToMultiByte (6 bytes)
00004864  FF 25 16 18 00 00  jmp     cs:__imp_WideCharToMultiByte; KERNEL32

; FUNC 0000486A-00004870 MultiByteToWideChar (6 bytes)
0000486A  FF 25 08 18 00 00  jmp     cs:__imp_MultiByteToWideChar; KERNEL32

; FUNC 00004870-00004876 Sleep (6 bytes)
00004870  FF 25 12 18 00 00  jmp     cs:__imp_Sleep; KERNEL32

; FUNC 00004876-0000487C __FrameUnwindFilter (6 bytes)
00004876  FF 25 44 18 00 00  jmp     cs:__imp___FrameUnwindFilter; VCRUNTIME140

; FUNC 0000487C-00004882 abort (6 bytes)
0000487C  FF 25 F6 18 00 00  jmp     cs:__imp_abort; api-ms-win-crt-runtime-l1-1-0

; FUNC 00004882-00004888 _callnewh (6 bytes)
00004882  FF 25 80 18 00 00  jmp     cs:__imp__callnewh; api-ms-win-crt-heap-l1-1-0

; FUNC 00004888-0000488E malloc (6 bytes)
00004888  FF 25 82 18 00 00  jmp     cs:__imp_malloc; api-ms-win-crt-heap-l1-1-0

; FUNC 0000488E-00004894 DllEntryPoint (6 bytes)
0000488E  FF 25 04 19 00 00  jmp     cs:_CorDllMain; mscoree

; FUNC 00004894-0000489A memcpy (6 bytes)
00004894  FF 25 36 18 00 00  jmp     cs:__imp_memcpy; VCRUNTIME140

; FUNC 000048B0-000048B2 _guard_dispatch_icall_nop (2 bytes)
000048B0  FF E0  jmp     rax

; FUNC 000048D0-000048D6 _guard_xfg_dispatch_icall_nop (6 bytes)
000048D0  FF 25 E2 18 00 00  jmp     cs:__guard_dispatch_icall_fptr

; FUNC 000048D6-000048ED sub_1800048D6 (23 bytes)
000048D6  40 55  push    rbp
000048D8  48 83 EC 20  sub     rsp, 20h
000048DC  48 8B EA  mov     rbp, rdx
000048DF  8A 4D 40  mov     cl, [rbp+40h]
000048E2  48 83 C4 20  add     rsp, 20h
000048E6  5D  pop     rbp
000048E7  E9 20 E0 FF FF  jmp     sub_18000290C
000048EC  CC  db 0CCh

; FUNC 000048ED-00004906 sub_1800048ED (25 bytes)
000048ED  40 55  push    rbp
000048EF  48 83 EC 20  sub     rsp, 20h
000048F3  48 8B EA  mov     rbp, rdx
000048F6  8A 4D 20  mov     cl, [rbp+20h]
000048F9  E8 0E E0 FF FF  call    sub_18000290C
000048FE  90  nop
000048FF  48 83 C4 20  add     rsp, 20h
00004903  5D  pop     rbp
00004904  C3  retn
00004905  CC  align 2

; FUNC 00004906-0000491A sub_180004906 (20 bytes)
00004906  40 55  push    rbp
00004908  48 83 EC 20  sub     rsp, 20h
0000490C  48 8B EA  mov     rbp, rdx
0000490F  48 83 C4 20  add     rsp, 20h
00004913  5D  pop     rbp
00004914  E9 6F DE FF FF  jmp     sub_180002788
00004919  CC  align 2

; FUNC 0000491A-00004950 sub_18000491A (54 bytes)
0000491A  40 55  push    rbp
0000491C  48 83 EC 30  sub     rsp, 30h
00004920  48 8B EA  mov     rbp, rdx
00004923  48 8B 01  mov     rax, [rcx]
00004926  8B 10  mov     edx, [rax]
00004928  48 89 4C 24 28  mov     [rsp+38h+ExceptionPtr], rcx; ExceptionPtr
0000492D  89 54 24 20  mov     [rsp+38h+ExceptionNum], edx; ExceptionNum
00004931  4C 8D 0D 44 D7 FF FF  lea     r9, sub_18000207C; int
00004938  4C 8B 45 70  mov     r8, [rbp+70h]; int
0000493C  8B 55 68  mov     edx, [rbp+68h]; int
0000493F  48 8B 4D 60  mov     rcx, [rbp+60h]; int
00004943  E8 B0 DD FF FF  call    sub_1800026F8
00004948  90  nop
00004949  48 83 C4 30  add     rsp, 30h
0000494D  5D  pop     rbp
0000494E  C3  retn
0000494F  CC  align 10h

; FUNC 00004950-00004968 sub_180004950 (24 bytes)
00004950  40 55  push    rbp
00004952  48 8B EA  mov     rbp, rdx
00004955  48 8B 01  mov     rax, [rcx]
00004958  33 C9  xor     ecx, ecx
0000495A  81 38 05 00 00 C0  cmp     dword ptr [rax], 0C0000005h
00004960  0F 94 C1  setz    cl
00004963  8B C1  mov     eax, ecx
00004965  5D  pop     rbp
00004966  C3  retn
00004967  CC  db 0CCh

; FUNC 00005004-0000500A sub_180005004 (6 bytes)
00005004  FF 25 0E 40 01 00  jmp     cs:qword_180019018

; FUNC 00005014-0000501A sub_180005014 (6 bytes)
00005014  FF 25 0E 40 01 00  jmp     cs:qword_180019028

; FUNC 00005024-0000502A sub_180005024 (6 bytes)
00005024  FF 25 26 40 01 00  jmp     cs:qword_180019050

; FUNC 00005034-0000503A sub_180005034 (6 bytes)
00005034  FF 25 3E 40 01 00  jmp     cs:qword_180019078

; FUNC 00005044-0000504A sub_180005044 (6 bytes)
00005044  FF 25 3E 40 01 00  jmp     cs:qword_180019088

; FUNC 00005054-0000505A sub_180005054 (6 bytes)
00005054  FF 25 3E 40 01 00  jmp     cs:qword_180019098

; FUNC 00005064-0000506A sub_180005064 (6 bytes)
00005064  FF 25 56 40 01 00  jmp     cs:qword_1800190C0

; FUNC 00005074-0000507A sub_180005074 (6 bytes)
00005074  FF 25 6E 40 01 00  jmp     cs:qword_1800190E8

; FUNC 00005084-0000508A sub_180005084 (6 bytes)
00005084  FF 25 86 40 01 00  jmp     cs:qword_180019110

; FUNC 00005094-0000509A sub_180005094 (6 bytes)
00005094  FF 25 86 40 01 00  jmp     cs:qword_180019120

; FUNC 000050A0-000050B0 ?SaveMergennFiles@@YAXPEAD0@Z (16 bytes)
000050A0  EB 08  jmp     short loc_1800050AA
000050A2  0F 0B  ud2
000050A4  FF 25 86 40 01 00  jmp     cs:qword_180019130
000050AA  FF 25 88 40 01 00  jmp     cs:qword_180019138

; FUNC 000050B4-000050BA sub_1800050B4 (6 bytes)
000050B4  FF 25 86 40 01 00  jmp     cs:qword_180019140

; FUNC 000050C0-000050C2 sub_1800050C0 (2 bytes)
000050C0  EB 08  jmp     short sub_1800050CA

; FUNC 000050C4-000050CA sub_1800050C4 (6 bytes)
000050C4  FF 25 86 40 01 00  jmp     cs:qword_180019150

; FUNC 000050CA-000050D0 sub_1800050CA (6 bytes)
000050CA  FF 25 88 40 01 00  jmp     cs:qword_180019158

; FUNC 000050D4-000050DA sub_1800050D4 (6 bytes)
000050D4  FF 25 86 40 01 00  jmp     cs:qword_180019160

; FUNC 000050E4-000050EA sub_1800050E4 (6 bytes)
000050E4  FF 25 86 40 01 00  jmp     cs:qword_180019170

; FUNC 000050F4-000050FA sub_1800050F4 (6 bytes)
000050F4  FF 25 86 40 01 00  jmp     cs:qword_180019180

; FUNC 00005104-0000510A sub_180005104 (6 bytes)
00005104  FF 25 86 40 01 00  jmp     cs:qword_180019190

; FUNC 00005110-00005112 sub_180005110 (2 bytes)
00005110  EB 08  jmp     short sub_18000511A

; FUNC 00005114-0000511A sub_180005114 (6 bytes)
00005114  FF 25 86 40 01 00  jmp     cs:qword_1800191A0

; FUNC 0000511A-00005120 sub_18000511A (6 bytes)
0000511A  FF 25 88 40 01 00  jmp     cs:qword_1800191A8

; FUNC 00005120-00005122 sub_180005120 (2 bytes)
00005120  EB 08  jmp     short sub_18000512A

; FUNC 00005124-0000512A sub_180005124 (6 bytes)
00005124  FF 25 86 40 01 00  jmp     cs:qword_1800191B0

; FUNC 0000512A-00005130 sub_18000512A (6 bytes)
0000512A  FF 25 88 40 01 00  jmp     cs:qword_1800191B8

; FUNC 00005134-0000513A sub_180005134 (6 bytes)
00005134  FF 25 86 40 01 00  jmp     cs:qword_1800191C0

; FUNC 00005144-0000514A sub_180005144 (6 bytes)
00005144  FF 25 86 40 01 00  jmp     cs:qword_1800191D0

; FUNC 00005154-0000515A sub_180005154 (6 bytes)
00005154  FF 25 86 40 01 00  jmp     cs:qword_1800191E0

; FUNC 00005164-0000516A sub_180005164 (6 bytes)
00005164  FF 25 86 40 01 00  jmp     cs:qword_1800191F0

; FUNC 00005174-0000517A sub_180005174 (6 bytes)
00005174  FF 25 86 40 01 00  jmp     cs:qword_180019200

; FUNC 00005184-0000518A sub_180005184 (6 bytes)
00005184  FF 25 86 40 01 00  jmp     cs:qword_180019210

; FUNC 00005194-0000519A sub_180005194 (6 bytes)
00005194  FF 25 86 40 01 00  jmp     cs:qword_180019220

; FUNC 000051A4-000051AA sub_1800051A4 (6 bytes)
000051A4  FF 25 86 40 01 00  jmp     cs:qword_180019230

; FUNC 000051B4-000051BA sub_1800051B4 (6 bytes)
000051B4  FF 25 86 40 01 00  jmp     cs:qword_180019240

; FUNC 000051C4-000051CA sub_1800051C4 (6 bytes)
000051C4  FF 25 86 40 01 00  jmp     cs:qword_180019250

; FUNC 000051D4-000051DA sub_1800051D4 (6 bytes)
000051D4  FF 25 86 40 01 00  jmp     cs:qword_180019260

; FUNC 000051E4-000051EA sub_1800051E4 (6 bytes)
000051E4  FF 25 86 40 01 00  jmp     cs:qword_180019270

; FUNC 000051F4-000051FA sub_1800051F4 (6 bytes)
000051F4  FF 25 86 40 01 00  jmp     cs:qword_180019280

; FUNC 00005204-0000520A sub_180005204 (6 bytes)
00005204  FF 25 86 40 01 00  jmp     cs:qword_180019290

; FUNC 00005214-0000521A sub_180005214 (6 bytes)
00005214  FF 25 86 40 01 00  jmp     cs:qword_1800192A0

; FUNC 00005224-0000522A sub_180005224 (6 bytes)
00005224  FF 25 86 40 01 00  jmp     cs:qword_1800192B0

; FUNC 00005234-0000523A sub_180005234 (6 bytes)
00005234  FF 25 86 40 01 00  jmp     cs:qword_1800192C0

; FUNC 00005244-0000524A sub_180005244 (6 bytes)
00005244  FF 25 86 40 01 00  jmp     cs:qword_1800192D0

; FUNC 00005254-0000525A sub_180005254 (6 bytes)
00005254  FF 25 86 40 01 00  jmp     cs:qword_1800192E0

; FUNC 00005264-0000526A sub_180005264 (6 bytes)
00005264  FF 25 86 40 01 00  jmp     cs:qword_1800192F0

; FUNC 00005274-0000527A sub_180005274 (6 bytes)
00005274  FF 25 86 40 01 00  jmp     cs:qword_180019300

; FUNC 00005284-0000528A sub_180005284 (6 bytes)
00005284  FF 25 86 40 01 00  jmp     cs:qword_180019310

; FUNC 00005294-0000529A sub_180005294 (6 bytes)
00005294  FF 25 86 40 01 00  jmp     cs:qword_180019320

; FUNC 000052A4-000052AA sub_1800052A4 (6 bytes)
000052A4  FF 25 86 40 01 00  jmp     cs:qword_180019330

; FUNC 000052B4-000052BA sub_1800052B4 (6 bytes)
000052B4  FF 25 86 40 01 00  jmp     cs:qword_180019340

; FUNC 000052C4-000052CA sub_1800052C4 (6 bytes)
000052C4  FF 25 BE 40 01 00  jmp     cs:qword_180019388

; FUNC 000052D4-000052DA sub_1800052D4 (6 bytes)
000052D4  FF 25 BE 40 01 00  jmp     cs:qword_180019398

; FUNC 000052E4-000052EA sub_1800052E4 (6 bytes)
000052E4  FF 25 BE 40 01 00  jmp     cs:qword_1800193A8

; FUNC 000052F4-000052FA sub_1800052F4 (6 bytes)
000052F4  FF 25 BE 40 01 00  jmp     cs:qword_1800193B8

; FUNC 00005304-0000530A sub_180005304 (6 bytes)
00005304  FF 25 BE 40 01 00  jmp     cs:qword_1800193C8

; FUNC 00005314-0000531A sub_180005314 (6 bytes)
00005314  FF 25 BE 40 01 00  jmp     cs:qword_1800193D8

; FUNC 00005324-0000532A sub_180005324 (6 bytes)
00005324  FF 25 BE 40 01 00  jmp     cs:qword_1800193E8

; FUNC 00005334-0000533A sub_180005334 (6 bytes)
00005334  FF 25 BE 40 01 00  jmp     cs:qword_1800193F8

; FUNC 00005344-0000534A sub_180005344 (6 bytes)
00005344  FF 25 BE 40 01 00  jmp     cs:qword_180019408

; FUNC 00005354-0000535A sub_180005354 (6 bytes)
00005354  FF 25 BE 40 01 00  jmp     cs:qword_180019418

; FUNC 00005364-0000536A sub_180005364 (6 bytes)
00005364  FF 25 BE 40 01 00  jmp     cs:qword_180019428

; FUNC 00005374-0000537A sub_180005374 (6 bytes)
00005374  FF 25 BE 40 01 00  jmp     cs:qword_180019438

; FUNC 00005384-0000538A sub_180005384 (6 bytes)
00005384  FF 25 BE 40 01 00  jmp     cs:qword_180019448

; FUNC 00005394-0000539A sub_180005394 (6 bytes)
00005394  FF 25 BE 40 01 00  jmp     cs:qword_180019458

; FUNC 000053A4-000053AA sub_1800053A4 (6 bytes)
000053A4  FF 25 BE 40 01 00  jmp     cs:qword_180019468

; FUNC 000053B4-000053BA sub_1800053B4 (6 bytes)
000053B4  FF 25 BE 40 01 00  jmp     cs:qword_180019478

; FUNC 000053C4-000053CA sub_1800053C4 (6 bytes)
000053C4  FF 25 BE 40 01 00  jmp     cs:qword_180019488

; FUNC 000053D4-000053DA sub_1800053D4 (6 bytes)
000053D4  FF 25 BE 40 01 00  jmp     cs:qword_180019498

; FUNC 000053E4-000053EA sub_1800053E4 (6 bytes)
000053E4  FF 25 BE 40 01 00  jmp     cs:qword_1800194A8

; FUNC 000053F4-000053FA sub_1800053F4 (6 bytes)
000053F4  FF 25 BE 40 01 00  jmp     cs:qword_1800194B8

; FUNC 00005404-0000540A sub_180005404 (6 bytes)
00005404  FF 25 BE 40 01 00  jmp     cs:qword_1800194C8

; FUNC 00005414-0000541A sub_180005414 (6 bytes)
00005414  FF 25 BE 40 01 00  jmp     cs:qword_1800194D8

; FUNC 00005424-0000542A sub_180005424 (6 bytes)
00005424  FF 25 BE 40 01 00  jmp     cs:qword_1800194E8

; FUNC 00005434-0000543A sub_180005434 (6 bytes)
00005434  FF 25 BE 40 01 00  jmp     cs:qword_1800194F8

; FUNC 00005444-0000544A sub_180005444 (6 bytes)
00005444  FF 25 BE 40 01 00  jmp     cs:qword_180019508

; FUNC 00005454-0000545A sub_180005454 (6 bytes)
00005454  FF 25 BE 40 01 00  jmp     cs:qword_180019518

; FUNC 00005464-0000546A sub_180005464 (6 bytes)
00005464  FF 25 BE 40 01 00  jmp     cs:qword_180019528

; FUNC 00005474-0000547A sub_180005474 (6 bytes)
00005474  FF 25 BE 40 01 00  jmp     cs:qword_180019538

; FUNC 00005484-0000548A sub_180005484 (6 bytes)
00005484  FF 25 BE 40 01 00  jmp     cs:qword_180019548

; FUNC 00005494-0000549A sub_180005494 (6 bytes)
00005494  FF 25 BE 40 01 00  jmp     cs:qword_180019558

; FUNC 000054A4-000054AA sub_1800054A4 (6 bytes)
000054A4  FF 25 BE 40 01 00  jmp     cs:qword_180019568

; FUNC 000054B4-000054BA sub_1800054B4 (6 bytes)
000054B4  FF 25 BE 40 01 00  jmp     cs:qword_180019578

; FUNC 000054C4-000054CA sub_1800054C4 (6 bytes)
000054C4  FF 25 BE 40 01 00  jmp     cs:qword_180019588

; FUNC 000054D4-000054DA sub_1800054D4 (6 bytes)
000054D4  FF 25 BE 40 01 00  jmp     cs:qword_180019598

; FUNC 000054E4-000054EA sub_1800054E4 (6 bytes)
000054E4  FF 25 BE 40 01 00  jmp     cs:qword_1800195A8

; FUNC 000054F4-000054FA sub_1800054F4 (6 bytes)
000054F4  FF 25 BE 40 01 00  jmp     cs:qword_1800195B8

; FUNC 00005500-00005506 sub_180005500 (6 bytes)
00005500  FF 25 C2 40 01 00  jmp     cs:qword_1800195C8

; FUNC 00005510-00005516 sub_180005510 (6 bytes)
00005510  FF 25 BA 40 01 00  jmp     cs:qword_1800195D0

; FUNC 00005520-00005526 sub_180005520 (6 bytes)
00005520  FF 25 B2 40 01 00  jmp     cs:qword_1800195D8

; FUNC 00005530-00005536 sub_180005530 (6 bytes)
00005530  FF 25 AA 40 01 00  jmp     cs:qword_1800195E0

; FUNC 00005540-00005546 sub_180005540 (6 bytes)
00005540  FF 25 A2 40 01 00  jmp     cs:qword_1800195E8

; FUNC 00005550-00005556 sub_180005550 (6 bytes)
00005550  FF 25 9A 40 01 00  jmp     cs:qword_1800195F0

; FUNC 00005560-00005566 sub_180005560 (6 bytes)
00005560  FF 25 92 40 01 00  jmp     cs:qword_1800195F8

; FUNC 00005574-0000557A sub_180005574 (6 bytes)
00005574  FF 25 86 40 01 00  jmp     cs:qword_180019600

; FUNC 00005584-0000558A sub_180005584 (6 bytes)
00005584  FF 25 86 40 01 00  jmp     cs:qword_180019610

; FUNC 00005594-0000559A sub_180005594 (6 bytes)
00005594  FF 25 86 40 01 00  jmp     cs:qword_180019620

; FUNC 000055A4-000055AA sub_1800055A4 (6 bytes)
000055A4  FF 25 86 40 01 00  jmp     cs:qword_180019630

; FUNC 000055B4-000055BA sub_1800055B4 (6 bytes)
000055B4  FF 25 86 40 01 00  jmp     cs:qword_180019640

; FUNC 000055C4-000055CA sub_1800055C4 (6 bytes)
000055C4  FF 25 86 40 01 00  jmp     cs:qword_180019650

; FUNC 000055D4-000055DA sub_1800055D4 (6 bytes)
000055D4  FF 25 86 40 01 00  jmp     cs:qword_180019660

; FUNC 000055E4-000055EA sub_1800055E4 (6 bytes)
000055E4  FF 25 86 40 01 00  jmp     cs:qword_180019670

; FUNC 000055F4-000055FA sub_1800055F4 (6 bytes)
000055F4  FF 25 86 40 01 00  jmp     cs:qword_180019680

; FUNC 00005604-0000560A sub_180005604 (6 bytes)
00005604  FF 25 86 40 01 00  jmp     cs:qword_180019690

; FUNC 00005614-0000561A sub_180005614 (6 bytes)
00005614  FF 25 86 40 01 00  jmp     cs:qword_1800196A0

; FUNC 00005624-0000562A sub_180005624 (6 bytes)
00005624  FF 25 86 40 01 00  jmp     cs:qword_1800196B0

; FUNC 00005634-0000563A sub_180005634 (6 bytes)
00005634  FF 25 86 40 01 00  jmp     cs:qword_1800196C0

; FUNC 00005644-0000564A sub_180005644 (6 bytes)
00005644  FF 25 86 40 01 00  jmp     cs:qword_1800196D0

; FUNC 00005654-0000565A sub_180005654 (6 bytes)
00005654  FF 25 86 40 01 00  jmp     cs:qword_1800196E0

; FUNC 00005664-0000566A sub_180005664 (6 bytes)
00005664  FF 25 86 40 01 00  jmp     cs:qword_1800196F0

; FUNC 00005674-0000567A sub_180005674 (6 bytes)
00005674  FF 25 86 40 01 00  jmp     cs:qword_180019700

; FUNC 00005684-0000568A sub_180005684 (6 bytes)
00005684  FF 25 86 40 01 00  jmp     cs:qword_180019710

; FUNC 00005694-0000569A sub_180005694 (6 bytes)
00005694  FF 25 86 40 01 00  jmp     cs:qword_180019720

; FUNC 000056A4-000056AA sub_1800056A4 (6 bytes)
000056A4  FF 25 86 40 01 00  jmp     cs:qword_180019730

; FUNC 000056B4-000056BA sub_1800056B4 (6 bytes)
000056B4  FF 25 86 40 01 00  jmp     cs:qword_180019740

; FUNC 000056C4-000056CA sub_1800056C4 (6 bytes)
000056C4  FF 25 86 40 01 00  jmp     cs:qword_180019750

; FUNC 000056D4-000056DA sub_1800056D4 (6 bytes)
000056D4  FF 25 86 40 01 00  jmp     cs:qword_180019760

; FUNC 000056E4-000056EA sub_1800056E4 (6 bytes)
000056E4  FF 25 86 40 01 00  jmp     cs:qword_180019770

; FUNC 000056F4-000056FA sub_1800056F4 (6 bytes)
000056F4  FF 25 86 40 01 00  jmp     cs:qword_180019780

; FUNC 00005704-0000570A sub_180005704 (6 bytes)
00005704  FF 25 86 40 01 00  jmp     cs:qword_180019790

; FUNC 00005714-0000571A sub_180005714 (6 bytes)
00005714  FF 25 86 40 01 00  jmp     cs:qword_1800197A0

; FUNC 00005724-0000572A sub_180005724 (6 bytes)
00005724  FF 25 86 40 01 00  jmp     cs:qword_1800197B0

; FUNC 00005734-0000573A sub_180005734 (6 bytes)
00005734  FF 25 86 40 01 00  jmp     cs:qword_1800197C0

; FUNC 00005744-0000574A sub_180005744 (6 bytes)
00005744  FF 25 86 40 01 00  jmp     cs:qword_1800197D0

; FUNC 00005754-0000575A sub_180005754 (6 bytes)
00005754  FF 25 86 40 01 00  jmp     cs:qword_1800197E0

; FUNC 00005764-0000576A sub_180005764 (6 bytes)
00005764  FF 25 86 40 01 00  jmp     cs:qword_1800197F0

; FUNC 00005774-0000577A sub_180005774 (6 bytes)
00005774  FF 25 86 40 01 00  jmp     cs:qword_180019800

; FUNC 00005784-0000578A sub_180005784 (6 bytes)
00005784  FF 25 86 40 01 00  jmp     cs:qword_180019810

; FUNC 00005794-0000579A sub_180005794 (6 bytes)
00005794  FF 25 86 40 01 00  jmp     cs:qword_180019820
