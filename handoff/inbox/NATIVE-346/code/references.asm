; owner 0x1000 PPEXEC_APLOAD
00001000  41 57  push r15
00001002  41 56  push r14
00001004  41 54  push r12
00001006  56  push rsi
00001007  57  push rdi
00001008  53  push rbx
00001009  48 83 ec 28  sub rsp, 0x28
0000100d  48 8d 0d 6c 4d 01 00  lea rcx, [rip + 0x14d6c]
00001014  e8 3b 03 01 00  call 0x180011354
00001019  48 89 05 50 d9 01 00  mov qword ptr [rip + 0x1d950], rax
00001020  4c 8b 35 d9 44 01 00  mov r14, qword ptr [rip + 0x144d9]
00001027  49 8b 4e 58  mov rcx, qword ptr [r14 + 0x58]
0000102b  48 89 0d c6 d8 01 00  mov qword ptr [rip + 0x1d8c6], rcx
00001032  49 c7 46 58 02 00 00 00  mov qword ptr [r14 + 0x58], 2
0000103a  48 8b 0d cf 45 01 00  mov rcx, qword ptr [rip + 0x145cf]
00001041  48 c7 01 00 00 00 00  mov qword ptr [rcx], 0
00001048  4c 8b 3d a9 44 01 00  mov r15, qword ptr [rip + 0x144a9]
0000104f  49 8b 84 c7 18 01 00 00  mov rax, qword ptr [r15 + rax*8 + 0x118]
00001057  48 89 05 0a d9 01 00  mov qword ptr [rip + 0x1d90a], rax
0000105e  48 8d 0d 03 d9 01 00  lea rcx, [rip + 0x1d903]
00001065  e8 ea 02 01 00  call 0x180011354
0000106a  49 8b 4c c7 f8  mov rcx, qword ptr [r15 + rax*8 - 8]
0000106f  48 8b 15 7a 44 01 00  mov rdx, qword ptr [rip + 0x1447a]
00001076  48 89 0a  mov qword ptr [rdx], rcx
00001079  41 0f 10 04 c7  movups xmm0, xmmword ptr [r15 + rax*8]
0000107e  0f 11 42 08  movups xmmword ptr [rdx + 8], xmm0
00001082  41 0f 10 44 c7 10  movups xmm0, xmmword ptr [r15 + rax*8 + 0x10]
00001088  0f 11 42 18  movups xmmword ptr [rdx + 0x18], xmm0
0000108c  41 0f 10 44 c7 20  movups xmm0, xmmword ptr [r15 + rax*8 + 0x20]
00001092  0f 11 42 28  movups xmmword ptr [rdx + 0x28], xmm0
00001096  41 0f 10 44 c7 30  movups xmm0, xmmword ptr [r15 + rax*8 + 0x30]
0000109c  0f 11 42 38  movups xmmword ptr [rdx + 0x38], xmm0
000010a0  41 0f 10 44 c7 40  movups xmm0, xmmword ptr [r15 + rax*8 + 0x40]
000010a6  0f 11 42 48  movups xmmword ptr [rdx + 0x48], xmm0
000010aa  41 0f 10 44 c7 50  movups xmm0, xmmword ptr [r15 + rax*8 + 0x50]
000010b0  0f 11 42 58  movups xmmword ptr [rdx + 0x58], xmm0
000010b4  41 0f 10 44 c7 60  movups xmm0, xmmword ptr [r15 + rax*8 + 0x60]
000010ba  0f 11 42 68  movups xmmword ptr [rdx + 0x68], xmm0
000010be  4d 8b 44 c7 70  mov r8, qword ptr [r15 + rax*8 + 0x70]
000010c3  4c 89 42 78  mov qword ptr [rdx + 0x78], r8
000010c7  41 0f 10 84 c7 a8 00 00 00  movups xmm0, xmmword ptr [r15 + rax*8 + 0xa8]
000010d0  0f 29 82 b0 00 00 00  movaps xmmword ptr [rdx + 0xb0], xmm0
000010d7  0f 57 c0  xorps xmm0, xmm0
000010da  48 8b 1d 27 45 01 00  mov rbx, qword ptr [rip + 0x14527]
000010e1  0f 29 43 10  movaps xmmword ptr [rbx + 0x10], xmm0
000010e5  0f 29 03  movaps xmmword ptr [rbx], xmm0
000010e8  48 c7 43 20 00 00 00 00  mov qword ptr [rbx + 0x20], 0
000010f0  48 8b 35 f1 43 01 00  mov rsi, qword ptr [rip + 0x143f1]
000010f7  0f 28 06  movaps xmm0, xmmword ptr [rsi]
000010fa  4c 8b 25 df 43 01 00  mov r12, qword ptr [rip + 0x143df]
00001101  41 0f 29 04 24  movaps xmmword ptr [r12], xmm0
00001106  f2 0f 10 46 20  movsd xmm0, qword ptr [rsi + 0x20]
0000110b  f2 41 0f 11 44 24 10  movsd qword ptr [r12 + 0x10], xmm0
00001112  48 8b 3d bf 43 01 00  mov rdi, qword ptr [rip + 0x143bf]
00001119  48 8b 47 20  mov rax, qword ptr [rdi + 0x20]
0000111d  48 8b 57 38  mov rdx, qword ptr [rdi + 0x38]
00001121  49 89 54 24 38  mov qword ptr [r12 + 0x38], rdx
00001126  49 89 44 24 40  mov qword ptr [r12 + 0x40], rax
0000112b  49 89 4c 24 48  mov qword ptr [r12 + 0x48], rcx
00001130  48 8b 05 39 d8 01 00  mov rax, qword ptr [rip + 0x1d839]
00001137  49 8b 84 c7 30 06 00 00  mov rax, qword ptr [r15 + rax*8 + 0x630]
0000113f  48 89 05 ba d7 01 00  mov qword ptr [rip + 0x1d7ba], rax
00001146  48 8d 0d b3 d7 01 00  lea rcx, [rip + 0x1d7b3]
0000114d  e8 02 02 01 00  call 0x180011354
00001152  49 8b 84 c7 e0 02 00 00  mov rax, qword ptr [r15 + rax*8 + 0x2e0]
0000115a  49 89 84 24 e8 4e 00 00  mov qword ptr [r12 + 0x4ee8], rax
00001162  e8 19 1a 00 00  call 0x180002b80
00001167  48 8d 0d 9a d7 01 00  lea rcx, [rip + 0x1d79a]
0000116e  e8 5d 04 01 00  call 0x1800115d0
00001173  48 83 3d 8d d7 01 00 00  cmp qword ptr [rip + 0x1d78d], 0
0000117b  7e 08  jle 0x180001185
0000117d  48 c7 43 20 01 00 00 00  mov qword ptr [rbx + 0x20], 1
00001185  e8 86 44 00 00  call 0x180005610
0000118a  48 8b 05 df d7 01 00  mov rax, qword ptr [rip + 0x1d7df]
00001191  48 8b 0d e0 46 01 00  mov rcx, qword ptr [rip + 0x146e0]
00001198  49 8b 94 c7 68 03 00 00  mov rdx, qword ptr [r15 + rax*8 + 0x368]
000011a0  4d 8b 84 c7 70 03 00 00  mov r8, qword ptr [r15 + rax*8 + 0x370]
000011a8  48 89 11  mov qword ptr [rcx], rdx
000011ab  4c 89 41 08  mov qword ptr [rcx + 8], r8
000011af  48 8b 0d 1a 43 01 00  mov rcx, qword ptr [rip + 0x1431a]
000011b6  f2 0f 10 06  movsd xmm0, qword ptr [rsi]
000011ba  48 03 51 08  add rdx, qword ptr [rcx + 8]
000011be  f2 41 0f 11 44 d7 f8  movsd qword ptr [r15 + rdx*8 - 8], xmm0
000011c5  48 8b 57 38  mov rdx, qword ptr [rdi + 0x38]
000011c9  4c 03 01  add r8, qword ptr [rcx]
000011cc  4b 89 54 c7 f8  mov qword ptr [r15 + r8*8 - 8], rdx
000011d1  49 8b 84 c7 30 01 00 00  mov rax, qword ptr [r15 + rax*8 + 0x130]
000011d9  48 89 05 80 d7 01 00  mov qword ptr [rip + 0x1d780], rax
000011e0  48 8d 15 79 d7 01 00  lea rdx, [rip + 0x1d779]
000011e7  48 8b 0d da 42 01 00  mov rcx, qword ptr [rip + 0x142da]
000011ee  4c 8d 05 93 4b 01 00  lea r8, [rip + 0x14b93]
000011f5  4c 8d 0d 94 4b 01 00  lea r9, [rip + 0x14b94]
000011fc  e8 89 01 01 00  call 0x18001138a
00001201  48 8b 05 68 d7 01 00  mov rax, qword ptr [rip + 0x1d768]
00001208  49 8b 84 c7 c8 03 00 00  mov rax, qword ptr [r15 + rax*8 + 0x3c8]
00001210  48 89 05 41 d7 01 00  mov qword ptr [rip + 0x1d741], rax
00001217  48 85 c0  test rax, rax
0000121a  74 38  je 0x180001254
0000121c  48 8d 0d 35 d7 01 00  lea rcx, [rip + 0x1d735]
00001223  e8 2c 01 01 00  call 0x180011354
00001228  49 83 7c c7 f8 01  cmp qword ptr [r15 + rax*8 - 8], 1
0000122e  75 24  jne 0x180001254
00001230  49 8b 44 c7 08  mov rax, qword ptr [r15 + rax*8 + 8]
00001235  48 89 05 14 d7 01 00  mov qword ptr [rip + 0x1d714], rax
0000123c  48 8d 0d 0d d7 01 00  lea rcx, [rip + 0x1d70d]
00001243  e8 84 07 01 00  call 0x1800119cc
00001248  48 8d 0d 49 4b 01 00  lea rcx, [rip + 0x14b49]
0000124f  e8 40 06 01 00  call 0x180011894
00001254  48 8b 05 15 d7 01 00  mov rax, qword ptr [rip + 0x1d715]
0000125b  49 8b 84 c7 08 05 00 00  mov rax, qword ptr [r15 + rax*8 + 0x508]
00001263  48 89 05 de d6 01 00  mov qword ptr [rip + 0x1d6de], rax
0000126a  48 85 c0  test rax, rax
0000126d  74 23  je 0x180001292
0000126f  48 8d 0d d2 d6 01 00  lea rcx, [rip + 0x1d6d2]
00001276  e8 d9 00 01 00  call 0x180011354
0000127b  49 81 7c c7 20 57 04 00 00  cmp qword ptr [r15 + rax*8 + 0x20], 0x457
00001284  75 0c  jne 0x180001292
00001286  48 8d 0d 0b 4b 01 00  lea rcx, [rip + 0x14b0b]
0000128d  e8 34 07 01 00  call 0x1800119c6
00001292  e8 39 49 00 00  call 0x180005bd0
00001297  49 c7 46 58 1d 00 00 00  mov qword ptr [r14 + 0x58], 0x1d
0000129f  48 8b 05 ca d6 01 00  mov rax, qword ptr [rip + 0x1d6ca]
000012a6  49 8b 84 c7 b0 00 00 00  mov rax, qword ptr [r15 + rax*8 + 0xb0]
000012ae  48 89 05 8b d6 01 00  mov qword ptr [rip + 0x1d68b], rax
000012b5  48 8d 0d 84 d6 01 00  lea rcx, [rip + 0x1d684]
000012bc  e8 93 00 01 00  call 0x180011354
000012c1  48 89 05 70 d6 01 00  mov qword ptr [rip + 0x1d670], rax
000012c8  4d 8b 64 c7 f8  mov r12, qword ptr [r15 + rax*8 - 8]
000012cd  4c 89 25 3c d6 01 00  mov qword ptr [rip + 0x1d63c], r12
000012d4  48 c7 05 51 d6 01 00 01 00 00 00  mov qword ptr [rip + 0x1d651], 1
000012df  4d 85 e4  test r12, r12
000012e2  0f 8e 9d 00 00 00  jle 0x180001385
000012e8  b9 01 00 00 00  mov ecx, 1
000012ed  48 8d 35 34 d6 01 00  lea rsi, [rip + 0x1d634]
000012f4  48 8d 3d 25 d6 01 00  lea rdi, [rip + 0x1d625]
000012fb  48 8d 1d 16 d6 01 00  lea rbx, [rip + 0x1d616]
00001302  4c 89 e2  mov rdx, r12
00001305  eb 1c  jmp 0x180001323
00001310  4c 8d 41 01  lea r8, [rcx + 1]
00001314  4c 89 05 15 d6 01 00  mov qword ptr [rip + 0x1d615], r8
0000131b  4c 39 e1  cmp rcx, r12
0000131e  4c 89 c1  mov rcx, r8
00001321  7d 62  jge 0x180001385
00001323  4c 8d 04 52  lea r8, [rdx + rdx*2]
00001327  49 01 c0  add r8, rax
0000132a  49 01 c8  add r8, rcx
0000132d  4b 83 7c c7 f8 01  cmp qword ptr [r15 + r8*8 - 8], 1
00001333  75 db  jne 0x180001310
00001335  48 8d 0c 49  lea rcx, [rcx + rcx*2]
00001339  48 01 c1  add rcx, rax
0000133c  49 8b 44 cf f8  mov rax, qword ptr [r15 + rcx*8 - 8]
00001341  48 89 05 e0 d5 01 00  mov qword ptr [rip + 0x1d5e0], rax
00001348  49 8b 44 cf e8  mov rax, qword ptr [r15 + rcx*8 - 0x18]
0000134d  49 8b 4c cf f0  mov rcx, qword ptr [r15 + rcx*8 - 0x10]
00001352  48 89 05 c7 d5 01 00  mov qword ptr [rip + 0x1d5c7], rax
00001359  48 89 0d b8 d5 01 00  mov qword ptr [rip + 0x1d5b8], rcx
00001360  48 89 f9  mov rcx, rdi
00001363  48 89 da  mov rdx, rbx
00001366  49 89 f0  mov r8, rsi
00001369  e8 f2 01 00 00  call 0x180001560
0000136e  48 8b 05 c3 d5 01 00  mov rax, qword ptr [rip + 0x1d5c3]
00001375  48 8b 15 94 d5 01 00  mov rdx, qword ptr [rip + 0x1d594]
0000137c  48 8b 0d ad d5 01 00  mov rcx, qword ptr [rip + 0x1d5ad]
00001383  eb 8b  jmp 0x180001310
00001385  e8 06 00 01 00  call 0x180011390
0000138a  0f 57 c0  xorps xmm0, xmm0
0000138d  0f 29 05 4c d5 01 00  movaps xmmword ptr [rip + 0x1d54c], xmm0
00001394  0f 29 05 35 d5 01 00  movaps xmmword ptr [rip + 0x1d535], xmm0
0000139b  0f 29 05 1e d5 01 00  movaps xmmword ptr [rip + 0x1d51e], xmm0
000013a2  c7 05 44 d5 01 00 00 00 00 00  mov dword ptr [rip + 0x1d544], 0
000013ac  48 8b 05 45 d5 01 00  mov rax, qword ptr [rip + 0x1d545]
000013b3  49 89 46 58  mov qword ptr [r14 + 0x58], rax
000013b7  48 83 c4 28  add rsp, 0x28
000013bb  5b  pop rbx
000013bc  5f  pop rdi
000013bd  5e  pop rsi
000013be  41 5c  pop r12
000013c0  41 5e  pop r14
000013c2  41 5f  pop r15
000013c4  e9 e7 06 01 00  jmp 0x180011ab0
; owner 0x13d0 PPEXEC_LDSTW
000013d0  41 56  push r14
000013d2  56  push rsi
000013d3  57  push rdi
000013d4  53  push rbx
000013d5  48 83 ec 28  sub rsp, 0x28
000013d9  48 8d 0d c0 49 01 00  lea rcx, [rip + 0x149c0]
000013e0  e8 6f ff 00 00  call 0x180011354
000013e5  4c 8b 35 0c 41 01 00  mov r14, qword ptr [rip + 0x1410c]
000013ec  49 8b 84 c6 c0 01 00 00  mov rax, qword ptr [r14 + rax*8 + 0x1c0]
000013f4  48 89 05 7d d5 01 00  mov qword ptr [rip + 0x1d57d], rax
000013fb  48 85 c0  test rax, rax
000013fe  0f 84 30 01 00 00  je 0x180001534
00001404  48 8d 0d 6d d5 01 00  lea rcx, [rip + 0x1d56d]
0000140b  e8 44 ff 00 00  call 0x180011354
00001410  48 89 c6  mov rsi, rax
00001413  49 8d 1c c6  lea rbx, [r14 + rax*8]
00001417  48 83 c3 f8  add rbx, -8
0000141b  48 8b 3d 9e 48 01 00  mov rdi, qword ptr [rip + 0x1489e]
00001422  41 b8 70 01 00 00  mov r8d, 0x170
00001428  48 89 f9  mov rcx, rdi
0000142b  48 89 da  mov rdx, rbx
0000142e  e8 ed 78 00 00  call 0x180008d20
00001433  31 c0  xor eax, eax
00001435  66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00001440  48 8b 8c c3 70 01 00 00  mov rcx, qword ptr [rbx + rax*8 + 0x170]
00001448  48 89 8c c7 10 02 00 00  mov qword ptr [rdi + rax*8 + 0x210], rcx
00001450  48 ff c0  inc rax
00001453  48 83 f8 08  cmp rax, 8
00001457  75 e7  jne 0x180001440
00001459  49 8d 04 f6  lea rax, [r14 + rsi*8]
0000145d  48 05 a8 01 00 00  add rax, 0x1a8
00001463  31 c9  xor ecx, ecx
00001465  66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00001470  48 8b 14 c8  mov rdx, qword ptr [rax + rcx*8]
00001474  48 89 94 cf 68 02 00 00  mov qword ptr [rdi + rcx*8 + 0x268], rdx
0000147c  48 ff c1  inc rcx
0000147f  48 83 f9 04  cmp rcx, 4
00001483  75 eb  jne 0x180001470
00001485  49 8d 04 f6  lea rax, [r14 + rsi*8]
00001489  48 05 c8 01 00 00  add rax, 0x1c8
0000148f  31 c9  xor ecx, ecx
00001491  66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
000014a0  48 8b 14 c8  mov rdx, qword ptr [rax + rcx*8]
000014a4  48 89 94 cf a8 02 00 00  mov qword ptr [rdi + rcx*8 + 0x2a8], rdx
000014ac  48 ff c1  inc rcx
000014af  48 83 f9 02  cmp rcx, 2
000014b3  75 eb  jne 0x1800014a0
000014b5  49 8b 84 f6 48 02 00 00  mov rax, qword ptr [r14 + rsi*8 + 0x248]
000014bd  48 89 87 48 03 00 00  mov qword ptr [rdi + 0x348], rax
000014c4  41 0f 10 84 f6 38 02 00 00  movups xmm0, xmmword ptr [r14 + rsi*8 + 0x238]
000014cd  0f 11 87 38 03 00 00  movups xmmword ptr [rdi + 0x338], xmm0
000014d4  41 0f 10 84 f6 28 02 00 00  movups xmm0, xmmword ptr [r14 + rsi*8 + 0x228]
000014dd  0f 11 87 28 03 00 00  movups xmmword ptr [rdi + 0x328], xmm0
000014e4  41 0f 10 84 f6 18 02 00 00  movups xmm0, xmmword ptr [r14 + rsi*8 + 0x218]
000014ed  0f 11 87 18 03 00 00  movups xmmword ptr [rdi + 0x318], xmm0
000014f4  41 0f 10 84 f6 d8 01 00 00  movups xmm0, xmmword ptr [r14 + rsi*8 + 0x1d8]
000014fd  41 0f 10 8c f6 e8 01 00 00  movups xmm1, xmmword ptr [r14 + rsi*8 + 0x1e8]
00001506  41 0f 10 94 f6 f8 01 00 00  movups xmm2, xmmword ptr [r14 + rsi*8 + 0x1f8]
0000150f  41 0f 10 9c f6 08 02 00 00  movups xmm3, xmmword ptr [r14 + rsi*8 + 0x208]
00001518  0f 11 9f 08 03 00 00  movups xmmword ptr [rdi + 0x308], xmm3
0000151f  0f 11 97 f8 02 00 00  movups xmmword ptr [rdi + 0x2f8], xmm2
00001526  0f 11 8f e8 02 00 00  movups xmmword ptr [rdi + 0x2e8], xmm1
0000152d  0f 11 87 d8 02 00 00  movups xmmword ptr [rdi + 0x2d8], xmm0
00001534  48 8b 05 75 3f 01 00  mov rax, qword ptr [rip + 0x13f75]
0000153b  48 c7 40 30 01 00 00 00  mov qword ptr [rax + 0x30], 1
00001543  48 83 c4 28  add rsp, 0x28
00001547  5b  pop rbx
00001548  5f  pop rdi
00001549  5e  pop rsi
0000154a  41 5e  pop r14
0000154c  e9 bf 16 00 00  jmp 0x180002c10
; owner 0x1560 PPEXEC_PHCCIN
00001560  41 57  push r15
00001562  41 56  push r14
00001564  41 55  push r13
00001566  41 54  push r12
00001568  56  push rsi
00001569  57  push rdi
0000156a  55  push rbp
0000156b  53  push rbx
0000156c  48 81 ec c8 03 00 00  sub rsp, 0x3c8
00001573  4c 89 84 24 88 02 00 00  mov qword ptr [rsp + 0x288], r8
0000157b  48 8b 05 26 3f 01 00  mov rax, qword ptr [rip + 0x13f26]
00001582  48 8b 40 08  mov rax, qword ptr [rax + 8]
00001586  48 89 05 33 d6 01 00  mov qword ptr [rip + 0x1d633], rax
0000158d  48 8b 35 0c 3f 01 00  mov rsi, qword ptr [rip + 0x13f0c]
00001594  4c 8b 86 88 09 00 00  mov r8, qword ptr [rsi + 0x988]
0000159b  4c 89 84 24 90 02 00 00  mov qword ptr [rsp + 0x290], r8
000015a3  4c 8b 86 c0 10 00 00  mov r8, qword ptr [rsi + 0x10c0]
000015aa  4c 89 84 24 00 03 00 00  mov qword ptr [rsp + 0x300], r8
000015b2  4c 8b 86 c8 10 00 00  mov r8, qword ptr [rsi + 0x10c8]
000015b9  4c 89 84 24 50 03 00 00  mov qword ptr [rsp + 0x350], r8
000015c1  4c 8b 86 d0 10 00 00  mov r8, qword ptr [rsi + 0x10d0]
000015c8  4c 89 84 24 48 03 00 00  mov qword ptr [rsp + 0x348], r8
000015d0  4c 8b 86 b0 01 00 00  mov r8, qword ptr [rsi + 0x1b0]
000015d7  4c 89 84 24 f0 02 00 00  mov qword ptr [rsp + 0x2f0], r8
000015df  4c 8b 86 18 02 00 00  mov r8, qword ptr [rsi + 0x218]
000015e6  4c 89 84 24 f8 02 00 00  mov qword ptr [rsp + 0x2f8], r8
000015ee  4c 8b 86 e0 10 00 00  mov r8, qword ptr [rsi + 0x10e0]
000015f5  4c 89 84 24 e0 02 00 00  mov qword ptr [rsp + 0x2e0], r8
000015fd  4c 8b 86 e8 10 00 00  mov r8, qword ptr [rsi + 0x10e8]
00001604  4c 89 84 24 e8 02 00 00  mov qword ptr [rsp + 0x2e8], r8
0000160c  4c 8b 86 f0 10 00 00  mov r8, qword ptr [rsi + 0x10f0]
00001613  4c 89 84 24 40 03 00 00  mov qword ptr [rsp + 0x340], r8
0000161b  4c 8b 86 f8 10 00 00  mov r8, qword ptr [rsi + 0x10f8]
00001622  4c 89 84 24 30 03 00 00  mov qword ptr [rsp + 0x330], r8
0000162a  4c 8b 86 60 15 00 00  mov r8, qword ptr [rsi + 0x1560]
00001631  4c 89 84 24 18 03 00 00  mov qword ptr [rsp + 0x318], r8
00001639  4c 8b 86 e8 11 00 00  mov r8, qword ptr [rsi + 0x11e8]
00001640  4c 89 84 24 c8 02 00 00  mov qword ptr [rsp + 0x2c8], r8
00001648  4c 8b 86 f0 11 00 00  mov r8, qword ptr [rsi + 0x11f0]
0000164f  4c 89 84 24 d0 02 00 00  mov qword ptr [rsp + 0x2d0], r8
00001657  4c 8b 86 f8 11 00 00  mov r8, qword ptr [rsi + 0x11f8]
0000165e  4c 89 84 24 d8 02 00 00  mov qword ptr [rsp + 0x2d8], r8
00001666  4c 8b 86 00 12 00 00  mov r8, qword ptr [rsi + 0x1200]
0000166d  4c 89 84 24 28 03 00 00  mov qword ptr [rsp + 0x328], r8
00001675  4c 8b 86 08 12 00 00  mov r8, qword ptr [rsi + 0x1208]
0000167c  4c 89 84 24 20 03 00 00  mov qword ptr [rsp + 0x320], r8
00001684  4c 8b 86 90 12 00 00  mov r8, qword ptr [rsi + 0x1290]
0000168b  4c 89 84 24 38 03 00 00  mov qword ptr [rsp + 0x338], r8
00001693  4c 8b 86 98 12 00 00  mov r8, qword ptr [rsi + 0x1298]
0000169a  4c 89 84 24 10 03 00 00  mov qword ptr [rsp + 0x310], r8
000016a2  4c 8b 86 a0 12 00 00  mov r8, qword ptr [rsi + 0x12a0]
000016a9  4c 89 84 24 08 03 00 00  mov qword ptr [rsp + 0x308], r8
000016b1  4c 8b 86 a8 12 00 00  mov r8, qword ptr [rsi + 0x12a8]
000016b8  4c 89 84 24 a8 02 00 00  mov qword ptr [rsp + 0x2a8], r8
000016c0  4c 8b 86 b0 12 00 00  mov r8, qword ptr [rsi + 0x12b0]
000016c7  4c 89 84 24 b0 02 00 00  mov qword ptr [rsp + 0x2b0], r8
000016cf  4c 8b 86 b8 12 00 00  mov r8, qword ptr [rsi + 0x12b8]
000016d6  4c 89 84 24 c0 02 00 00  mov qword ptr [rsp + 0x2c0], r8
000016de  4c 8b 86 c8 12 00 00  mov r8, qword ptr [rsi + 0x12c8]
000016e5  4c 89 84 24 b8 02 00 00  mov qword ptr [rsp + 0x2b8], r8
000016ed  4c 8b be d0 12 00 00  mov r15, qword ptr [rsi + 0x12d0]
000016f4  4c 8b a6 d8 12 00 00  mov r12, qword ptr [rsi + 0x12d8]
000016fb  4c 8b 8e e0 12 00 00  mov r9, qword ptr [rsi + 0x12e0]
00001702  4c 8b b6 e8 12 00 00  mov r14, qword ptr [rsi + 0x12e8]
00001709  48 8b be f0 12 00 00  mov rdi, qword ptr [rsi + 0x12f0]
00001710  4c 8b 9e a8 15 00 00  mov r11, qword ptr [rsi + 0x15a8]
00001717  48 8b 9e b0 15 00 00  mov rbx, qword ptr [rsi + 0x15b0]
0000171e  48 8b 29  mov rbp, qword ptr [rcx]
00001721  4c 8b 2a  mov r13, qword ptr [rdx]
00001724  49 b8 20 20 20 20 20 20 20 20  movabs r8, 0x2020202020202020
0000172e  4d 8d 90 25 33 10 12  lea r10, [r8 + 0x12103325]
00001735  4c 39 d5  cmp rbp, r10
00001738  75 27  jne 0x180001761
0000173a  4d 39 c5  cmp r13, r8
0000173d  75 22  jne 0x180001761
0000173f  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001747  e8 7a ff 00 00  call 0x1800116c6
0000174c  90  nop
0000174d  48 81 c4 c8 03 00 00  add rsp, 0x3c8
00001754  5b  pop rbx
00001755  5d  pop rbp
00001756  5f  pop rdi
00001757  5e  pop rsi
00001758  41 5c  pop r12
0000175a  41 5d  pop r13
0000175c  41 5e  pop r14
0000175e  41 5f  pop r15
00001760  c3  ret
00001761  4c 8d 15 50 49 01 00  lea r10, [rip + 0x14950]
00001768  45 31 c0  xor r8d, r8d
0000176b  eb 13  jmp 0x180001780
00001770  49 ff c0  inc r8
00001773  49 83 c2 10  add r10, 0x10
00001777  49 81 f8 b3 00 00 00  cmp r8, 0xb3
0000177e  74 36  je 0x1800017b6
00001780  49 3b 6a f8  cmp rbp, qword ptr [r10 - 8]
00001784  75 ea  jne 0x180001770
00001786  4d 3b 2a  cmp r13, qword ptr [r10]
00001789  75 e5  jne 0x180001770
0000178b  41 81 f8 b2 00 00 00  cmp r8d, 0xb2
00001792  77 ab  ja 0x18000173f
00001794  44 89 c1  mov ecx, r8d
00001797  48 8d 15 22 46 01 00  lea rdx, [rip + 0x14622]
0000179e  48 63 0c 8a  movsxd rcx, dword ptr [rdx + rcx*4]
000017a2  48 01 d1  add rcx, rdx
000017a5  ff e1  jmp rcx
000017a7  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000017af  e8 38 00 01 00  call 0x1800117ec
000017b4  eb 96  jmp 0x18000174c
000017b6  4c 8d 0d 0b d4 01 00  lea r9, [rip + 0x1d40b]
000017bd  48 89 ce  mov rsi, rcx
000017c0  48 89 d3  mov rbx, rdx
000017c3  4c 8b 84 24 88 02 00 00  mov r8, qword ptr [rsp + 0x288]
000017cb  e8 ea fe 00 00  call 0x1800116ba
000017d0  48 83 3d f0 d3 01 00 00  cmp qword ptr [rip + 0x1d3f0], 0
000017d8  0f 84 6e ff ff ff  je 0x18000174c
000017de  48 8d 05 0b 54 01 00  lea rax, [rip + 0x1540b]
000017e5  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
000017ea  48 8d 15 f7 53 01 00  lea rdx, [rip + 0x153f7]
000017f1  48 89 54 24 30  mov qword ptr [rsp + 0x30], rdx
000017f6  48 89 54 24 28  mov qword ptr [rsp + 0x28], rdx
000017fb  4c 8b 0d d6 3c 01 00  mov r9, qword ptr [rip + 0x13cd6]
00001802  49 8d 41 38  lea rax, [r9 + 0x38]
00001806  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0000180b  49 83 c1 28  add r9, 0x28
0000180f  48 8d 0d 0a c8 01 00  lea rcx, [rip + 0x1c80a]
00001816  4c 8d 05 c3 53 01 00  lea r8, [rip + 0x153c3]
0000181d  e8 86 fb 00 00  call 0x1800113a8
00001822  48 85 c0  test rax, rax
00001825  0f 84 21 ff ff ff  je 0x18000174c
0000182b  48 8b 06  mov rax, qword ptr [rsi]
0000182e  48 c7 84 24 98 03 00 00 00 00 00 00  mov qword ptr [rsp + 0x398], 0
0000183a  c7 84 24 a2 02 00 00 38 06 0b 01  mov dword ptr [rsp + 0x2a2], 0x10b0638
00001845  66 c7 84 24 a6 02 00 00 02 00  mov word ptr [rsp + 0x2a6], 2
0000184f  48 c7 84 24 78 03 00 00 20 03 00 00  mov qword ptr [rsp + 0x378], 0x320
0000185b  4c 8b 35 2e 3c 01 00  mov r14, qword ptr [rip + 0x13c2e]
00001862  4c 89 b4 24 80 03 00 00  mov qword ptr [rsp + 0x380], r14
0000186a  48 c7 84 24 88 03 00 00 50 00 00 00  mov qword ptr [rsp + 0x388], 0x50
00001876  48 89 84 24 90 03 00 00  mov qword ptr [rsp + 0x390], rax
0000187e  48 8d 05 d7 c7 01 00  lea rax, [rip + 0x1c7d7]
00001885  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0000188a  48 8d b4 24 98 03 00 00  lea rsi, [rsp + 0x398]
00001892  48 bf 00 ff 84 83 20 01 08 00  movabs rdi, 0x801208384ff00
0000189c  4c 8d 84 24 a2 02 00 00  lea r8, [rsp + 0x2a2]
000018a4  4c 8d 8c 24 78 03 00 00  lea r9, [rsp + 0x378]
000018ac  48 89 f1  mov rcx, rsi
000018af  48 89 fa  mov rdx, rdi
000018b2  e8 53 02 01 00  call 0x180011b0a
000018b7  4c 8d 3d 72 c7 01 00  lea r15, [rip + 0x1c772]
000018be  48 8b 03  mov rax, qword ptr [rbx]
000018c1  c7 84 24 9e 02 00 00 0b 01 01 00  mov dword ptr [rsp + 0x29e], 0x1010b
000018cc  48 89 84 24 58 03 00 00  mov qword ptr [rsp + 0x358], rax
000018d4  48 8d 94 24 9e 02 00 00  lea rdx, [rsp + 0x29e]
000018dc  4c 8d 84 24 58 03 00 00  lea r8, [rsp + 0x358]
000018e4  48 89 f1  mov rcx, rsi
000018e7  e8 24 02 01 00  call 0x180011b10
000018ec  48 c7 84 24 98 03 00 00 00 00 00 00  mov qword ptr [rsp + 0x398], 0
000018f8  c7 84 24 9a 02 00 00 38 06 01 00  mov dword ptr [rsp + 0x29a], 0x10638
00001903  48 c7 84 24 60 03 00 00 d0 02 00 00  mov qword ptr [rsp + 0x360], 0x2d0
0000190f  49 83 c6 50  add r14, 0x50
00001913  4c 89 b4 24 68 03 00 00  mov qword ptr [rsp + 0x368], r14
0000191b  48 c7 84 24 70 03 00 00 50 00 00 00  mov qword ptr [rsp + 0x370], 0x50
00001927  4c 89 7c 24 20  mov qword ptr [rsp + 0x20], r15
0000192c  4c 8d 84 24 9a 02 00 00  lea r8, [rsp + 0x29a]
00001934  4c 8d 8c 24 60 03 00 00  lea r9, [rsp + 0x360]
0000193c  48 89 f1  mov rcx, rsi
0000193f  48 89 fa  mov rdx, rdi
00001942  e8 c3 01 01 00  call 0x180011b0a
00001947  48 8d 0d a2 52 01 00  lea rcx, [rip + 0x152a2]
0000194e  e8 61 fa 00 00  call 0x1800113b4
00001953  e9 f4 fd ff ff  jmp 0x18000174c
00001958  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001960  e8 8d fe 00 00  call 0x1800117f2
00001965  e9 e2 fd ff ff  jmp 0x18000174c
0000196a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001972  e8 55 fd 00 00  call 0x1800116cc
00001977  e9 d0 fd ff ff  jmp 0x18000174c
0000197c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001984  e8 11 ff 00 00  call 0x18001189a
00001989  e9 be fd ff ff  jmp 0x18000174c
0000198e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001996  e8 a7 fc 00 00  call 0x180011642
0000199b  e9 ac fd ff ff  jmp 0x18000174c
000019a0  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000019a8  e8 f3 fe 00 00  call 0x1800118a0
000019ad  e9 9a fd ff ff  jmp 0x18000174c
000019b2  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000019ba  e8 e7 fe 00 00  call 0x1800118a6
000019bf  e9 88 fd ff ff  jmp 0x18000174c
000019c4  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000019cc  e8 db fe 00 00  call 0x1800118ac
000019d1  e9 76 fd ff ff  jmp 0x18000174c
000019d6  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000019de  e8 cf fe 00 00  call 0x1800118b2
000019e3  e9 64 fd ff ff  jmp 0x18000174c
000019e8  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000019f0  e8 dd fc 00 00  call 0x1800116d2
000019f5  e9 52 fd ff ff  jmp 0x18000174c
000019fa  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a02  e8 b1 fe 00 00  call 0x1800118b8
00001a07  e9 40 fd ff ff  jmp 0x18000174c
00001a0c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a14  e8 2f fc 00 00  call 0x180011648
00001a19  e9 2e fd ff ff  jmp 0x18000174c
00001a1e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a26  e8 21 fe 00 00  call 0x18001184c
00001a2b  e9 1c fd ff ff  jmp 0x18000174c
00001a30  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a38  e8 9b fc 00 00  call 0x1800116d8
00001a3d  e9 0a fd ff ff  jmp 0x18000174c
00001a42  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a4a  e8 83 ff 00 00  call 0x1800119d2
00001a4f  e9 f8 fc ff ff  jmp 0x18000174c
00001a54  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a5c  e8 7d fc 00 00  call 0x1800116de
00001a61  e9 e6 fc ff ff  jmp 0x18000174c
00001a66  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a6e  e8 4b fe 00 00  call 0x1800118be
00001a73  e9 d4 fc ff ff  jmp 0x18000174c
00001a78  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a80  e8 cd fd 00 00  call 0x180011852
00001a85  e9 c2 fc ff ff  jmp 0x18000174c
00001a8a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001a92  e8 41 ff 00 00  call 0x1800119d8
00001a97  e9 b0 fc ff ff  jmp 0x18000174c
00001a9c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001aa4  e8 3b fc 00 00  call 0x1800116e4
00001aa9  e9 9e fc ff ff  jmp 0x18000174c
00001aae  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001ab6  e8 2f fc 00 00  call 0x1800116ea
00001abb  e9 8c fc ff ff  jmp 0x18000174c
00001ac0  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001ac8  e8 f7 fd 00 00  call 0x1800118c4
00001acd  e9 7a fc ff ff  jmp 0x18000174c
00001ad2  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001ada  e8 eb fd 00 00  call 0x1800118ca
00001adf  e9 68 fc ff ff  jmp 0x18000174c
00001ae4  48 8b 15 0d 3a 01 00  mov rdx, qword ptr [rip + 0x13a0d]
00001aeb  48 8b 8c 24 30 03 00 00  mov rcx, qword ptr [rsp + 0x330]
00001af3  48 8d 0c ca  lea rcx, [rdx + rcx*8]
00001af7  48 8d 14 c2  lea rdx, [rdx + rax*8]
00001afb  e8 de fe 00 00  call 0x1800119de
00001b00  e9 47 fc ff ff  jmp 0x18000174c
00001b05  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001b0d  e8 de fb 00 00  call 0x1800116f0
00001b12  e9 35 fc ff ff  jmp 0x18000174c
00001b17  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001b1f  e8 c0 fe 00 00  call 0x1800119e4
00001b24  e9 23 fc ff ff  jmp 0x18000174c
00001b29  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001b31  e8 18 fb 00 00  call 0x18001164e
00001b36  e9 11 fc ff ff  jmp 0x18000174c
00001b3b  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001b43  e8 b0 fc 00 00  call 0x1800117f8
00001b48  e9 ff fb ff ff  jmp 0x18000174c
00001b4d  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001b55  e8 76 fd 00 00  call 0x1800118d0
00001b5a  e9 ed fb ff ff  jmp 0x18000174c
00001b5f  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001b67  e8 ec fc 00 00  call 0x180011858
00001b6c  e9 db fb ff ff  jmp 0x18000174c
00001b71  4c 8b 15 80 39 01 00  mov r10, qword ptr [rip + 0x13980]
00001b78  48 8b 8c 24 90 02 00 00  mov rcx, qword ptr [rsp + 0x290]
00001b80  49 8d 0c ca  lea rcx, [r10 + rcx*8]
00001b84  48 8b 94 24 10 03 00 00  mov rdx, qword ptr [rsp + 0x310]
00001b8c  49 8d 14 d2  lea rdx, [r10 + rdx*8]
00001b90  4c 8b 84 24 08 03 00 00  mov r8, qword ptr [rsp + 0x308]
00001b98  4f 8d 04 c2  lea r8, [r10 + r8*8]
00001b9c  4c 8b 8c 24 48 03 00 00  mov r9, qword ptr [rsp + 0x348]
00001ba4  4f 8d 0c ca  lea r9, [r10 + r9*8]
00001ba8  4c 8b 9c 24 50 03 00 00  mov r11, qword ptr [rsp + 0x350]
00001bb0  4f 8d 1c da  lea r11, [r10 + r11*8]
00001bb4  49 8d 04 c2  lea rax, [r10 + rax*8]
00001bb8  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00001bbd  4c 89 5c 24 20  mov qword ptr [rsp + 0x20], r11
00001bc2  e8 23 fe 00 00  call 0x1800119ea
00001bc7  e9 80 fb ff ff  jmp 0x18000174c
00001bcc  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001bd4  e8 fd fc 00 00  call 0x1800118d6
00001bd9  e9 6e fb ff ff  jmp 0x18000174c
00001bde  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001be6  e8 73 fc 00 00  call 0x18001185e
00001beb  e9 5c fb ff ff  jmp 0x18000174c
00001bf0  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001bf8  e8 f9 fa 00 00  call 0x1800116f6
00001bfd  e9 4a fb ff ff  jmp 0x18000174c
00001c02  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c0a  e8 ed fa 00 00  call 0x1800116fc
00001c0f  e9 38 fb ff ff  jmp 0x18000174c
00001c14  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c1c  e8 e1 fa 00 00  call 0x180011702
00001c21  e9 26 fb ff ff  jmp 0x18000174c
00001c26  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c2e  e8 d5 fa 00 00  call 0x180011708
00001c33  e9 14 fb ff ff  jmp 0x18000174c
00001c38  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c40  e8 2d fd 00 00  call 0x180011972
00001c45  e9 02 fb ff ff  jmp 0x18000174c
00001c4a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c52  e8 b7 fa 00 00  call 0x18001170e
00001c57  e9 f0 fa ff ff  jmp 0x18000174c
00001c5c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c64  e8 fb fb 00 00  call 0x180011864
00001c69  e9 de fa ff ff  jmp 0x18000174c
00001c6e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c76  e8 61 fc 00 00  call 0x1800118dc
00001c7b  e9 cc fa ff ff  jmp 0x18000174c
00001c80  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c88  e8 87 fa 00 00  call 0x180011714
00001c8d  e9 ba fa ff ff  jmp 0x18000174c
00001c92  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001c9a  e8 43 fc 00 00  call 0x1800118e2
00001c9f  e9 a8 fa ff ff  jmp 0x18000174c
00001ca4  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001cac  e8 4d fb 00 00  call 0x1800117fe
00001cb1  e9 96 fa ff ff  jmp 0x18000174c
00001cb6  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001cbe  e8 57 fa 00 00  call 0x18001171a
00001cc3  e9 84 fa ff ff  jmp 0x18000174c
00001cc8  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001cd0  e8 1b fd 00 00  call 0x1800119f0
00001cd5  e9 72 fa ff ff  jmp 0x18000174c
00001cda  4c 8b 15 17 38 01 00  mov r10, qword ptr [rip + 0x13817]
00001ce1  48 8b 8c 24 90 02 00 00  mov rcx, qword ptr [rsp + 0x290]
00001ce9  49 8d 0c ca  lea rcx, [r10 + rcx*8]
00001ced  48 8b 94 24 b8 02 00 00  mov rdx, qword ptr [rsp + 0x2b8]
00001cf5  49 8d 14 d2  lea rdx, [r10 + rdx*8]
00001cf9  4f 8d 04 fa  lea r8, [r10 + r15*8]
00001cfd  4f 8d 0c e2  lea r9, [r10 + r12*8]
00001d01  4f 8d 1c da  lea r11, [r10 + r11*8]
00001d05  48 8b b4 24 28 03 00 00  mov rsi, qword ptr [rsp + 0x328]
00001d0d  49 8d 34 f2  lea rsi, [r10 + rsi*8]
00001d11  48 8b bc 24 20 03 00 00  mov rdi, qword ptr [rsp + 0x320]
00001d19  49 8d 3c fa  lea rdi, [r10 + rdi*8]
00001d1d  48 8b 9c 24 f8 02 00 00  mov rbx, qword ptr [rsp + 0x2f8]
00001d25  49 8d 1c da  lea rbx, [r10 + rbx*8]
00001d29  49 8d 04 c2  lea rax, [r10 + rax*8]
00001d2d  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
00001d32  48 89 5c 24 38  mov qword ptr [rsp + 0x38], rbx
00001d37  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
00001d3c  48 89 74 24 28  mov qword ptr [rsp + 0x28], rsi
00001d41  4c 89 5c 24 20  mov qword ptr [rsp + 0x20], r11
00001d46  e8 ab fc 00 00  call 0x1800119f6
00001d4b  e9 fc f9 ff ff  jmp 0x18000174c
00001d50  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001d58  e8 0d fb 00 00  call 0x18001186a
00001d5d  e9 ea f9 ff ff  jmp 0x18000174c
00001d62  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001d6a  e8 09 fc 00 00  call 0x180011978
00001d6f  e9 d8 f9 ff ff  jmp 0x18000174c
00001d74  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001d7c  e8 d3 f8 00 00  call 0x180011654
00001d81  e9 c6 f9 ff ff  jmp 0x18000174c
00001d86  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001d8e  e8 8d f9 00 00  call 0x180011720
00001d93  e9 b4 f9 ff ff  jmp 0x18000174c
00001d98  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001da0  e8 81 f9 00 00  call 0x180011726
00001da5  e9 a2 f9 ff ff  jmp 0x18000174c
00001daa  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001db2  e8 4d fa 00 00  call 0x180011804
00001db7  e9 90 f9 ff ff  jmp 0x18000174c
00001dbc  4c 8b 1d 35 37 01 00  mov r11, qword ptr [rip + 0x13735]
00001dc3  48 8b 8c 24 90 02 00 00  mov rcx, qword ptr [rsp + 0x290]
00001dcb  49 8d 0c cb  lea rcx, [r11 + rcx*8]
00001dcf  4b 8d 14 cb  lea rdx, [r11 + r9*8]
00001dd3  4f 8d 04 f3  lea r8, [r11 + r14*8]
00001dd7  4d 8d 14 fb  lea r10, [r11 + rdi*8]
00001ddb  4d 8d 0c db  lea r9, [r11 + rbx*8]
00001ddf  48 8b b4 24 e0 02 00 00  mov rsi, qword ptr [rsp + 0x2e0]
00001de7  49 8d 34 f3  lea rsi, [r11 + rsi*8]
00001deb  48 8b bc 24 e8 02 00 00  mov rdi, qword ptr [rsp + 0x2e8]
00001df3  49 8d 3c fb  lea rdi, [r11 + rdi*8]
00001df7  48 8b 9c 24 f0 02 00 00  mov rbx, qword ptr [rsp + 0x2f0]
00001dff  49 8d 1c db  lea rbx, [r11 + rbx*8]
00001e03  49 8d 04 c3  lea rax, [r11 + rax*8]
00001e07  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
00001e0c  48 89 5c 24 38  mov qword ptr [rsp + 0x38], rbx
00001e11  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
00001e16  48 89 74 24 28  mov qword ptr [rsp + 0x28], rsi
00001e1b  4c 89 4c 24 20  mov qword ptr [rsp + 0x20], r9
00001e20  4d 89 d1  mov r9, r10
00001e23  e8 d4 fb 00 00  call 0x1800119fc
00001e28  e9 1f f9 ff ff  jmp 0x18000174c
00001e2d  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001e35  e8 c8 fb 00 00  call 0x180011a02
00001e3a  e9 0d f9 ff ff  jmp 0x18000174c
00001e3f  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001e47  e8 bc fb 00 00  call 0x180011a08
00001e4c  e9 fb f8 ff ff  jmp 0x18000174c
00001e51  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001e59  e8 8a fa 00 00  call 0x1800118e8
00001e5e  e9 e9 f8 ff ff  jmp 0x18000174c
00001e63  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001e6b  e8 7e fa 00 00  call 0x1800118ee
00001e70  e9 d7 f8 ff ff  jmp 0x18000174c
00001e75  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001e7d  e8 d8 f7 00 00  call 0x18001165a
00001e82  e9 c5 f8 ff ff  jmp 0x18000174c
00001e87  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001e8f  e8 7a fb 00 00  call 0x180011a0e
00001e94  e9 b3 f8 ff ff  jmp 0x18000174c
00001e99  48 8d 0d 50 4d 01 00  lea rcx, [rip + 0x14d50]
00001ea0  e8 af f4 00 00  call 0x180011354
00001ea5  48 8b 3d 4c 36 01 00  mov rdi, qword ptr [rip + 0x1364c]
00001eac  48 8b 84 c7 18 01 00 00  mov rax, qword ptr [rdi + rax*8 + 0x118]
00001eb4  48 89 05 fd cc 01 00  mov qword ptr [rip + 0x1ccfd], rax
00001ebb  48 8d 0d f6 cc 01 00  lea rcx, [rip + 0x1ccf6]
00001ec2  e8 8d f4 00 00  call 0x180011354
00001ec7  48 8b 44 c7 f8  mov rax, qword ptr [rdi + rax*8 - 8]
00001ecc  48 89 05 dd cc 01 00  mov qword ptr [rip + 0x1ccdd], rax
00001ed3  48 8d 0d d6 cc 01 00  lea rcx, [rip + 0x1ccd6]
00001eda  48 8b 86 10 2a 00 00  mov rax, qword ptr [rsi + 0x2a10]
00001ee1  4c 8b 86 18 2a 00 00  mov r8, qword ptr [rsi + 0x2a18]
00001ee8  4c 8b 8e 20 2a 00 00  mov r9, qword ptr [rsi + 0x2a20]
00001eef  48 8d 14 c7  lea rdx, [rdi + rax*8]
00001ef3  4e 8d 04 c7  lea r8, [rdi + r8*8]
00001ef7  4e 8d 0c cf  lea r9, [rdi + r9*8]
00001efb  48 8b 05 be cc 01 00  mov rax, qword ptr [rip + 0x1ccbe]
00001f02  48 8d 04 c7  lea rax, [rdi + rax*8]
00001f06  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00001f0b  e8 04 fb 00 00  call 0x180011a14
00001f10  e9 37 f8 ff ff  jmp 0x18000174c
00001f15  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001f1d  e8 d2 f9 00 00  call 0x1800118f4
00001f22  e9 25 f8 ff ff  jmp 0x18000174c
00001f27  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001f2f  e8 c6 f9 00 00  call 0x1800118fa
00001f34  e9 13 f8 ff ff  jmp 0x18000174c
00001f39  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001f41  e8 e6 f7 00 00  call 0x18001172c
00001f46  e9 01 f8 ff ff  jmp 0x18000174c
00001f4b  48 8b 35 a6 35 01 00  mov rsi, qword ptr [rip + 0x135a6]
00001f52  48 8b 8c 24 90 02 00 00  mov rcx, qword ptr [rsp + 0x290]
00001f5a  48 8d 0c ce  lea rcx, [rsi + rcx*8]
00001f5e  4a 8d 14 ce  lea rdx, [rsi + r9*8]
00001f62  4e 8d 04 f6  lea r8, [rsi + r14*8]
00001f66  4c 8d 14 fe  lea r10, [rsi + rdi*8]
00001f6a  4c 8d 0c de  lea r9, [rsi + rbx*8]
00001f6e  4e 8d 1c de  lea r11, [rsi + r11*8]
00001f72  48 8b bc 24 b8 02 00 00  mov rdi, qword ptr [rsp + 0x2b8]
00001f7a  48 8d 3c fe  lea rdi, [rsi + rdi*8]
00001f7e  48 8b 9c 24 e0 02 00 00  mov rbx, qword ptr [rsp + 0x2e0]
00001f86  48 8d 1c de  lea rbx, [rsi + rbx*8]
00001f8a  4c 8b b4 24 e8 02 00 00  mov r14, qword ptr [rsp + 0x2e8]
00001f92  4e 8d 34 f6  lea r14, [rsi + r14*8]
00001f96  4c 8b bc 24 f0 02 00 00  mov r15, qword ptr [rsp + 0x2f0]
00001f9e  4e 8d 3c fe  lea r15, [rsi + r15*8]
00001fa2  48 8d 04 c6  lea rax, [rsi + rax*8]
00001fa6  4c 8b a4 24 f8 02 00 00  mov r12, qword ptr [rsp + 0x2f8]
00001fae  4a 8d 34 e6  lea rsi, [rsi + r12*8]
00001fb2  48 89 74 24 58  mov qword ptr [rsp + 0x58], rsi
00001fb7  48 89 44 24 50  mov qword ptr [rsp + 0x50], rax
00001fbc  4c 89 7c 24 48  mov qword ptr [rsp + 0x48], r15
00001fc1  4c 89 74 24 40  mov qword ptr [rsp + 0x40], r14
00001fc6  48 89 5c 24 38  mov qword ptr [rsp + 0x38], rbx
00001fcb  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
00001fd0  4c 89 5c 24 28  mov qword ptr [rsp + 0x28], r11
00001fd5  4c 89 4c 24 20  mov qword ptr [rsp + 0x20], r9
00001fda  4d 89 d1  mov r9, r10
00001fdd  e8 38 fa 00 00  call 0x180011a1a
00001fe2  e9 65 f7 ff ff  jmp 0x18000174c
00001fe7  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00001fef  e8 3e f7 00 00  call 0x180011732
00001ff4  e9 53 f7 ff ff  jmp 0x18000174c
00001ff9  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002001  e8 e0 fa 00 00  call 0x180011ae6
00002006  e9 41 f7 ff ff  jmp 0x18000174c
0000200b  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002013  e8 48 f6 00 00  call 0x180011660
00002018  e9 2f f7 ff ff  jmp 0x18000174c
0000201d  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002025  e8 0e f7 00 00  call 0x180011738
0000202a  e9 1d f7 ff ff  jmp 0x18000174c
0000202f  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002037  e8 02 f7 00 00  call 0x18001173e
0000203c  e9 0b f7 ff ff  jmp 0x18000174c
00002041  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002049  e8 d2 f9 00 00  call 0x180011a20
0000204e  e9 f9 f6 ff ff  jmp 0x18000174c
00002053  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000205b  e8 aa f7 00 00  call 0x18001180a
00002060  e9 e7 f6 ff ff  jmp 0x18000174c
00002065  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000206d  e8 8e f8 00 00  call 0x180011900
00002072  e9 d5 f6 ff ff  jmp 0x18000174c
00002077  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000207f  e8 c0 f6 00 00  call 0x180011744
00002084  e9 c3 f6 ff ff  jmp 0x18000174c
00002089  4c 8b 05 68 34 01 00  mov r8, qword ptr [rip + 0x13468]
00002090  48 8b 8c 24 90 02 00 00  mov rcx, qword ptr [rsp + 0x290]
00002098  49 8d 0c c8  lea rcx, [r8 + rcx*8]
0000209c  48 8b 94 24 a8 02 00 00  mov rdx, qword ptr [rsp + 0x2a8]
000020a4  49 8d 14 d0  lea rdx, [r8 + rdx*8]
000020a8  4c 8b 8c 24 b0 02 00 00  mov r9, qword ptr [rsp + 0x2b0]
000020b0  4f 8d 1c c8  lea r11, [r8 + r9*8]
000020b4  4c 8b 8c 24 c0 02 00 00  mov r9, qword ptr [rsp + 0x2c0]
000020bc  4f 8d 0c c8  lea r9, [r8 + r9*8]
000020c0  4c 8b 94 24 c8 02 00 00  mov r10, qword ptr [rsp + 0x2c8]
000020c8  4f 8d 14 d0  lea r10, [r8 + r10*8]
000020cc  48 8b b4 24 d0 02 00 00  mov rsi, qword ptr [rsp + 0x2d0]
000020d4  49 8d 34 f0  lea rsi, [r8 + rsi*8]
000020d8  48 8b bc 24 d8 02 00 00  mov rdi, qword ptr [rsp + 0x2d8]
000020e0  49 8d 3c f8  lea rdi, [r8 + rdi*8]
000020e4  48 8b 9c 24 00 03 00 00  mov rbx, qword ptr [rsp + 0x300]
000020ec  49 8d 1c d8  lea rbx, [r8 + rbx*8]
000020f0  49 8d 04 c0  lea rax, [r8 + rax*8]
000020f4  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
000020f9  48 89 5c 24 38  mov qword ptr [rsp + 0x38], rbx
000020fe  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
00002103  48 89 74 24 28  mov qword ptr [rsp + 0x28], rsi
00002108  4c 89 54 24 20  mov qword ptr [rsp + 0x20], r10
0000210d  4d 89 d8  mov r8, r11
00002110  e8 11 f9 00 00  call 0x180011a26
00002115  e9 32 f6 ff ff  jmp 0x18000174c
0000211a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002122  e8 23 f6 00 00  call 0x18001174a
00002127  e9 20 f6 ff ff  jmp 0x18000174c
0000212c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002134  e8 b9 f9 00 00  call 0x180011af2
00002139  e9 0e f6 ff ff  jmp 0x18000174c
0000213e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002146  e8 e1 f8 00 00  call 0x180011a2c
0000214b  e9 fc f5 ff ff  jmp 0x18000174c
00002150  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002158  e8 a9 f7 00 00  call 0x180011906
0000215d  e9 ea f5 ff ff  jmp 0x18000174c
00002162  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000216a  e8 0f f8 00 00  call 0x18001197e
0000216f  e9 d8 f5 ff ff  jmp 0x18000174c
00002174  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000217c  e8 e5 f4 00 00  call 0x180011666
00002181  e9 c6 f5 ff ff  jmp 0x18000174c
00002186  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000218e  e8 9f f8 00 00  call 0x180011a32
00002193  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000219b  e8 d0 f6 00 00  call 0x180011870
000021a0  e9 a7 f5 ff ff  jmp 0x18000174c
000021a5  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000021ad  e8 9e f5 00 00  call 0x180011750
000021b2  e9 95 f5 ff ff  jmp 0x18000174c
000021b7  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000021bf  e8 74 f8 00 00  call 0x180011a38
000021c4  e9 83 f5 ff ff  jmp 0x18000174c
000021c9  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000021d1  e8 80 f5 00 00  call 0x180011756
000021d6  e9 71 f5 ff ff  jmp 0x18000174c
000021db  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000021e3  e8 56 f8 00 00  call 0x180011a3e
000021e8  e9 5f f5 ff ff  jmp 0x18000174c
000021ed  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000021f5  e8 12 f7 00 00  call 0x18001190c
000021fa  e9 4d f5 ff ff  jmp 0x18000174c
000021ff  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002207  e8 06 f7 00 00  call 0x180011912
0000220c  e9 3b f5 ff ff  jmp 0x18000174c
00002211  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002219  e8 3e f5 00 00  call 0x18001175c
0000221e  e9 29 f5 ff ff  jmp 0x18000174c
00002223  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000222b  e8 e8 f6 00 00  call 0x180011918
00002230  e9 17 f5 ff ff  jmp 0x18000174c
00002235  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000223d  e8 42 f7 00 00  call 0x180011984
00002242  e9 05 f5 ff ff  jmp 0x18000174c
00002247  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000224f  e8 a4 f8 00 00  call 0x180011af8
00002254  e9 f3 f4 ff ff  jmp 0x18000174c
00002259  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002261  e8 aa f5 00 00  call 0x180011810
00002266  e9 e1 f4 ff ff  jmp 0x18000174c
0000226b  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002273  e8 f4 f3 00 00  call 0x18001166c
00002278  e9 cf f4 ff ff  jmp 0x18000174c
0000227d  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002285  e8 e8 f3 00 00  call 0x180011672
0000228a  e9 bd f4 ff ff  jmp 0x18000174c
0000228f  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002297  e8 c6 f4 00 00  call 0x180011762
0000229c  e9 ab f4 ff ff  jmp 0x18000174c
000022a1  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000022a9  e8 96 f7 00 00  call 0x180011a44
000022ae  e9 99 f4 ff ff  jmp 0x18000174c
000022b3  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000022bb  e8 b8 f3 00 00  call 0x180011678
000022c0  e9 87 f4 ff ff  jmp 0x18000174c
000022c5  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000022cd  e8 1a f8 00 00  call 0x180011aec
000022d2  e9 75 f4 ff ff  jmp 0x18000174c
000022d7  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000022df  e8 92 f5 00 00  call 0x180011876
000022e4  e9 63 f4 ff ff  jmp 0x18000174c
000022e9  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000022f1  e8 72 f4 00 00  call 0x180011768
000022f6  e9 51 f4 ff ff  jmp 0x18000174c
000022fb  4c 8b 15 f6 31 01 00  mov r10, qword ptr [rip + 0x131f6]
00002302  48 8b 8c 24 90 02 00 00  mov rcx, qword ptr [rsp + 0x290]
0000230a  49 8d 0c ca  lea rcx, [r10 + rcx*8]
0000230e  48 8b 94 24 a8 02 00 00  mov rdx, qword ptr [rsp + 0x2a8]
00002316  49 8d 14 d2  lea rdx, [r10 + rdx*8]
0000231a  4c 8b 84 24 b0 02 00 00  mov r8, qword ptr [rsp + 0x2b0]
00002322  4f 8d 04 c2  lea r8, [r10 + r8*8]
00002326  4c 8b 8c 24 c0 02 00 00  mov r9, qword ptr [rsp + 0x2c0]
0000232e  4f 8d 0c ca  lea r9, [r10 + r9*8]
00002332  4c 8b 9c 24 c8 02 00 00  mov r11, qword ptr [rsp + 0x2c8]
0000233a  4f 8d 1c da  lea r11, [r10 + r11*8]
0000233e  48 8b b4 24 d0 02 00 00  mov rsi, qword ptr [rsp + 0x2d0]
00002346  49 8d 34 f2  lea rsi, [r10 + rsi*8]
0000234a  48 8b bc 24 d8 02 00 00  mov rdi, qword ptr [rsp + 0x2d8]
00002352  49 8d 3c fa  lea rdi, [r10 + rdi*8]
00002356  48 8b 9c 24 00 03 00 00  mov rbx, qword ptr [rsp + 0x300]
0000235e  49 8d 1c da  lea rbx, [r10 + rbx*8]
00002362  4c 8b b4 24 38 03 00 00  mov r14, qword ptr [rsp + 0x338]
0000236a  4f 8d 34 f2  lea r14, [r10 + r14*8]
0000236e  49 8d 04 c2  lea rax, [r10 + rax*8]
00002372  48 89 44 24 48  mov qword ptr [rsp + 0x48], rax
00002377  4c 89 74 24 40  mov qword ptr [rsp + 0x40], r14
0000237c  48 89 5c 24 38  mov qword ptr [rsp + 0x38], rbx
00002381  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
00002386  48 89 74 24 28  mov qword ptr [rsp + 0x28], rsi
0000238b  4c 89 5c 24 20  mov qword ptr [rsp + 0x20], r11
00002390  e8 b5 f6 00 00  call 0x180011a4a
00002395  e9 b2 f3 ff ff  jmp 0x18000174c
0000239a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000023a2  e8 39 f7 00 00  call 0x180011ae0
000023a7  e9 a0 f3 ff ff  jmp 0x18000174c
000023ac  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000023b4  e8 d1 f5 00 00  call 0x18001198a
000023b9  e9 8e f3 ff ff  jmp 0x18000174c
000023be  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000023c6  e8 33 f7 00 00  call 0x180011afe
000023cb  e9 7c f3 ff ff  jmp 0x18000174c
000023d0  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000023d8  e8 73 f6 00 00  call 0x180011a50
000023dd  e9 6a f3 ff ff  jmp 0x18000174c
000023e2  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000023ea  e8 a1 f5 00 00  call 0x180011990
000023ef  e9 58 f3 ff ff  jmp 0x18000174c
000023f4  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000023fc  e8 95 f5 00 00  call 0x180011996
00002401  e9 46 f3 ff ff  jmp 0x18000174c
00002406  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000240e  e8 5b f3 00 00  call 0x18001176e
00002413  e9 34 f3 ff ff  jmp 0x18000174c
00002418  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002420  e8 df f6 00 00  call 0x180011b04
00002425  e9 22 f3 ff ff  jmp 0x18000174c
0000242a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002432  e8 1f f6 00 00  call 0x180011a56
00002437  e9 10 f3 ff ff  jmp 0x18000174c
0000243c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002444  e8 2b f3 00 00  call 0x180011774
00002449  e9 fe f2 ff ff  jmp 0x18000174c
0000244e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002456  e8 1f f3 00 00  call 0x18001177a
0000245b  e9 ec f2 ff ff  jmp 0x18000174c
00002460  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002468  e8 ef f5 00 00  call 0x180011a5c
0000246d  e9 da f2 ff ff  jmp 0x18000174c
00002472  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000247a  e8 fd f3 00 00  call 0x18001187c
0000247f  e9 c8 f2 ff ff  jmp 0x18000174c
00002484  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000248c  e8 ef f2 00 00  call 0x180011780
00002491  e9 b6 f2 ff ff  jmp 0x18000174c
00002496  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000249e  e8 e3 f2 00 00  call 0x180011786
000024a3  e9 a4 f2 ff ff  jmp 0x18000174c
000024a8  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000024b0  e8 d7 f2 00 00  call 0x18001178c
000024b5  e9 92 f2 ff ff  jmp 0x18000174c
000024ba  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000024c2  e8 57 f4 00 00  call 0x18001191e
000024c7  e9 80 f2 ff ff  jmp 0x18000174c
000024cc  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000024d4  e8 4b f4 00 00  call 0x180011924
000024d9  e9 6e f2 ff ff  jmp 0x18000174c
000024de  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000024e6  e8 3f f4 00 00  call 0x18001192a
000024eb  e9 5c f2 ff ff  jmp 0x18000174c
000024f0  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000024f8  e8 95 f2 00 00  call 0x180011792
000024fd  e9 4a f2 ff ff  jmp 0x18000174c
00002502  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000250a  e8 07 f3 00 00  call 0x180011816
0000250f  e9 38 f2 ff ff  jmp 0x18000174c
00002514  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000251c  e8 77 f2 00 00  call 0x180011798
00002521  e9 26 f2 ff ff  jmp 0x18000174c
00002526  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000252e  e8 6b f2 00 00  call 0x18001179e
00002533  e9 14 f2 ff ff  jmp 0x18000174c
00002538  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002540  e8 5f f2 00 00  call 0x1800117a4
00002545  e9 02 f2 ff ff  jmp 0x18000174c
0000254a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002552  e8 53 f2 00 00  call 0x1800117aa
00002557  e9 f0 f1 ff ff  jmp 0x18000174c
0000255c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002564  e8 47 f2 00 00  call 0x1800117b0
00002569  e9 de f1 ff ff  jmp 0x18000174c
0000256e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002576  e8 3b f2 00 00  call 0x1800117b6
0000257b  e9 cc f1 ff ff  jmp 0x18000174c
00002580  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002588  e8 d5 f4 00 00  call 0x180011a62
0000258d  e9 ba f1 ff ff  jmp 0x18000174c
00002592  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000259a  e8 7d f2 00 00  call 0x18001181c
0000259f  e9 a8 f1 ff ff  jmp 0x18000174c
000025a4  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000025ac  e8 0b f2 00 00  call 0x1800117bc
000025b1  e9 96 f1 ff ff  jmp 0x18000174c
000025b6  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000025be  e8 d9 f3 00 00  call 0x18001199c
000025c3  e9 84 f1 ff ff  jmp 0x18000174c
000025c8  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000025d0  e8 93 f4 00 00  call 0x180011a68
000025d5  e9 72 f1 ff ff  jmp 0x18000174c
000025da  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000025e2  e8 87 f4 00 00  call 0x180011a6e
000025e7  e9 60 f1 ff ff  jmp 0x18000174c
000025ec  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000025f4  e8 7b f4 00 00  call 0x180011a74
000025f9  e9 4e f1 ff ff  jmp 0x18000174c
000025fe  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002606  e8 6f f4 00 00  call 0x180011a7a
0000260b  e9 3c f1 ff ff  jmp 0x18000174c
00002610  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002618  e8 a5 f1 00 00  call 0x1800117c2
0000261d  e9 2a f1 ff ff  jmp 0x18000174c
00002622  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000262a  e8 51 f4 00 00  call 0x180011a80
0000262f  e9 18 f1 ff ff  jmp 0x18000174c
00002634  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000263c  e8 e1 f1 00 00  call 0x180011822
00002641  e9 06 f1 ff ff  jmp 0x18000174c
00002646  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000264e  e8 dd f2 00 00  call 0x180011930
00002653  e9 f4 f0 ff ff  jmp 0x18000174c
00002658  48 8d 0d a1 b9 01 00  lea rcx, [rip + 0x1b9a1]
0000265f  48 8d 35 6a c5 01 00  lea rsi, [rip + 0x1c56a]
00002666  48 89 f2  mov rdx, rsi
00002669  e8 92 ef 00 00  call 0x180011600
0000266e  4c 8b 05 63 2e 01 00  mov r8, qword ptr [rip + 0x12e63]
00002675  49 83 c0 38  add r8, 0x38
00002679  4c 89 84 24 80 02 00 00  mov qword ptr [rsp + 0x280], r8
00002681  4c 89 84 24 78 02 00 00  mov qword ptr [rsp + 0x278], r8
00002689  4c 89 84 24 70 02 00 00  mov qword ptr [rsp + 0x270], r8
00002691  4c 89 84 24 68 02 00 00  mov qword ptr [rsp + 0x268], r8
00002699  4c 89 84 24 60 02 00 00  mov qword ptr [rsp + 0x260], r8
000026a1  4c 89 84 24 58 02 00 00  mov qword ptr [rsp + 0x258], r8
000026a9  4c 89 84 24 50 02 00 00  mov qword ptr [rsp + 0x250], r8
000026b1  4c 89 84 24 48 02 00 00  mov qword ptr [rsp + 0x248], r8
000026b9  4c 89 84 24 40 02 00 00  mov qword ptr [rsp + 0x240], r8
000026c1  4c 89 84 24 38 02 00 00  mov qword ptr [rsp + 0x238], r8
000026c9  4c 89 84 24 30 02 00 00  mov qword ptr [rsp + 0x230], r8
000026d1  4c 89 84 24 28 02 00 00  mov qword ptr [rsp + 0x228], r8
000026d9  4c 89 84 24 20 02 00 00  mov qword ptr [rsp + 0x220], r8
000026e1  4c 89 84 24 18 02 00 00  mov qword ptr [rsp + 0x218], r8
000026e9  4c 89 84 24 10 02 00 00  mov qword ptr [rsp + 0x210], r8
000026f1  4c 89 84 24 08 02 00 00  mov qword ptr [rsp + 0x208], r8
000026f9  4c 89 84 24 00 02 00 00  mov qword ptr [rsp + 0x200], r8
00002701  4c 89 84 24 f8 01 00 00  mov qword ptr [rsp + 0x1f8], r8
00002709  4c 89 84 24 f0 01 00 00  mov qword ptr [rsp + 0x1f0], r8
00002711  4c 89 84 24 e8 01 00 00  mov qword ptr [rsp + 0x1e8], r8
00002719  4c 89 84 24 e0 01 00 00  mov qword ptr [rsp + 0x1e0], r8
00002721  4c 89 84 24 d8 01 00 00  mov qword ptr [rsp + 0x1d8], r8
00002729  4c 89 84 24 d0 01 00 00  mov qword ptr [rsp + 0x1d0], r8
00002731  4c 89 84 24 c8 01 00 00  mov qword ptr [rsp + 0x1c8], r8
00002739  4c 89 84 24 c0 01 00 00  mov qword ptr [rsp + 0x1c0], r8
00002741  4c 89 84 24 b8 01 00 00  mov qword ptr [rsp + 0x1b8], r8
00002749  4c 89 84 24 b0 01 00 00  mov qword ptr [rsp + 0x1b0], r8
00002751  4c 89 84 24 a8 01 00 00  mov qword ptr [rsp + 0x1a8], r8
00002759  4c 89 84 24 a0 01 00 00  mov qword ptr [rsp + 0x1a0], r8
00002761  4c 89 84 24 98 01 00 00  mov qword ptr [rsp + 0x198], r8
00002769  4c 89 84 24 90 01 00 00  mov qword ptr [rsp + 0x190], r8
00002771  4c 89 84 24 88 01 00 00  mov qword ptr [rsp + 0x188], r8
00002779  4c 89 84 24 80 01 00 00  mov qword ptr [rsp + 0x180], r8
00002781  4c 89 84 24 78 01 00 00  mov qword ptr [rsp + 0x178], r8
00002789  4c 89 84 24 70 01 00 00  mov qword ptr [rsp + 0x170], r8
00002791  4c 89 84 24 68 01 00 00  mov qword ptr [rsp + 0x168], r8
00002799  4c 89 84 24 60 01 00 00  mov qword ptr [rsp + 0x160], r8
000027a1  4c 89 84 24 58 01 00 00  mov qword ptr [rsp + 0x158], r8
000027a9  4c 89 84 24 50 01 00 00  mov qword ptr [rsp + 0x150], r8
000027b1  4c 89 84 24 48 01 00 00  mov qword ptr [rsp + 0x148], r8
000027b9  4c 89 84 24 40 01 00 00  mov qword ptr [rsp + 0x140], r8
000027c1  4c 89 84 24 38 01 00 00  mov qword ptr [rsp + 0x138], r8
000027c9  4c 89 84 24 30 01 00 00  mov qword ptr [rsp + 0x130], r8
000027d1  4c 89 84 24 28 01 00 00  mov qword ptr [rsp + 0x128], r8
000027d9  4c 89 84 24 20 01 00 00  mov qword ptr [rsp + 0x120], r8
000027e1  4c 89 84 24 18 01 00 00  mov qword ptr [rsp + 0x118], r8
000027e9  4c 89 84 24 10 01 00 00  mov qword ptr [rsp + 0x110], r8
000027f1  4c 89 84 24 08 01 00 00  mov qword ptr [rsp + 0x108], r8
000027f9  4c 89 84 24 00 01 00 00  mov qword ptr [rsp + 0x100], r8
00002801  4c 89 84 24 f8 00 00 00  mov qword ptr [rsp + 0xf8], r8
00002809  4c 89 84 24 f0 00 00 00  mov qword ptr [rsp + 0xf0], r8
00002811  4c 89 84 24 e8 00 00 00  mov qword ptr [rsp + 0xe8], r8
00002819  4c 89 84 24 e0 00 00 00  mov qword ptr [rsp + 0xe0], r8
00002821  4c 89 84 24 d8 00 00 00  mov qword ptr [rsp + 0xd8], r8
00002829  4c 89 84 24 d0 00 00 00  mov qword ptr [rsp + 0xd0], r8
00002831  4c 89 84 24 c8 00 00 00  mov qword ptr [rsp + 0xc8], r8
00002839  4c 89 84 24 c0 00 00 00  mov qword ptr [rsp + 0xc0], r8
00002841  4c 89 84 24 b8 00 00 00  mov qword ptr [rsp + 0xb8], r8
00002849  4c 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], r8
00002851  4c 89 84 24 a8 00 00 00  mov qword ptr [rsp + 0xa8], r8
00002859  4c 89 84 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], r8
00002861  4c 89 84 24 98 00 00 00  mov qword ptr [rsp + 0x98], r8
00002869  4c 89 84 24 90 00 00 00  mov qword ptr [rsp + 0x90], r8
00002871  4c 89 84 24 88 00 00 00  mov qword ptr [rsp + 0x88], r8
00002879  4c 89 84 24 80 00 00 00  mov qword ptr [rsp + 0x80], r8
00002881  4c 89 44 24 78  mov qword ptr [rsp + 0x78], r8
00002886  4c 89 44 24 70  mov qword ptr [rsp + 0x70], r8
0000288b  4c 89 44 24 68  mov qword ptr [rsp + 0x68], r8
00002890  4c 89 44 24 60  mov qword ptr [rsp + 0x60], r8
00002895  4c 89 44 24 58  mov qword ptr [rsp + 0x58], r8
0000289a  4c 89 44 24 50  mov qword ptr [rsp + 0x50], r8
0000289f  4c 89 44 24 48  mov qword ptr [rsp + 0x48], r8
000028a4  4c 89 44 24 40  mov qword ptr [rsp + 0x40], r8
000028a9  4c 89 44 24 38  mov qword ptr [rsp + 0x38], r8
000028ae  4c 89 44 24 30  mov qword ptr [rsp + 0x30], r8
000028b3  4c 89 44 24 28  mov qword ptr [rsp + 0x28], r8
000028b8  4c 89 44 24 20  mov qword ptr [rsp + 0x20], r8
000028bd  48 89 f1  mov rcx, rsi
000028c0  48 8b 94 24 88 02 00 00  mov rdx, qword ptr [rsp + 0x288]
000028c8  4d 89 c1  mov r9, r8
000028cb  e8 ea ea 00 00  call 0x1800113ba
000028d0  e9 77 ee ff ff  jmp 0x18000174c
000028d5  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000028dd  e8 54 f0 00 00  call 0x180011936
000028e2  e9 65 ee ff ff  jmp 0x18000174c
000028e7  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000028ef  e8 ae f0 00 00  call 0x1800119a2
000028f4  e9 53 ee ff ff  jmp 0x18000174c
000028f9  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002901  e8 22 ef 00 00  call 0x180011828
00002906  e9 41 ee ff ff  jmp 0x18000174c
0000290b  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002913  e8 b0 ee 00 00  call 0x1800117c8
00002918  e9 2f ee ff ff  jmp 0x18000174c
0000291d  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002925  e8 12 f0 00 00  call 0x18001193c
0000292a  e9 1d ee ff ff  jmp 0x18000174c
0000292f  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002937  e8 f2 ee 00 00  call 0x18001182e
0000293c  e9 0b ee ff ff  jmp 0x18000174c
00002941  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002949  e8 80 ee 00 00  call 0x1800117ce
0000294e  e9 f9 ed ff ff  jmp 0x18000174c
00002953  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000295b  e8 d4 ee 00 00  call 0x180011834
00002960  e9 e7 ed ff ff  jmp 0x18000174c
00002965  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000296d  e8 d0 ef 00 00  call 0x180011942
00002972  e9 d5 ed ff ff  jmp 0x18000174c
00002977  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
0000297f  e8 50 ee 00 00  call 0x1800117d4
00002984  e9 c3 ed ff ff  jmp 0x18000174c
00002989  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002991  e8 12 f0 00 00  call 0x1800119a8
00002996  e9 b1 ed ff ff  jmp 0x18000174c
0000299b  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000029a3  e8 06 f0 00 00  call 0x1800119ae
000029a8  e9 9f ed ff ff  jmp 0x18000174c
000029ad  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000029b5  e8 20 ee 00 00  call 0x1800117da
000029ba  e9 8d ed ff ff  jmp 0x18000174c
000029bf  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000029c7  e8 e8 ef 00 00  call 0x1800119b4
000029cc  e9 7b ed ff ff  jmp 0x18000174c
000029d1  48 8b 15 20 2b 01 00  mov rdx, qword ptr [rip + 0x12b20]
000029d8  48 8b 8c 24 40 03 00 00  mov rcx, qword ptr [rsp + 0x340]
000029e0  48 8d 0c ca  lea rcx, [rdx + rcx*8]
000029e4  48 8d 14 c2  lea rdx, [rdx + rax*8]
000029e8  e8 99 f0 00 00  call 0x180011a86
000029ed  e9 5a ed ff ff  jmp 0x18000174c
000029f2  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
000029fa  e8 bb ef 00 00  call 0x1800119ba
000029ff  e9 48 ed ff ff  jmp 0x18000174c
00002a04  48 8b 15 ed 2a 01 00  mov rdx, qword ptr [rip + 0x12aed]
00002a0b  48 8b 8c 24 18 03 00 00  mov rcx, qword ptr [rsp + 0x318]
00002a13  48 8d 0c ca  lea rcx, [rdx + rcx*8]
00002a17  48 8d 14 c2  lea rdx, [rdx + rax*8]
00002a1b  e8 6c f0 00 00  call 0x180011a8c
00002a20  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a28  e8 65 f0 00 00  call 0x180011a92
00002a2d  e9 1a ed ff ff  jmp 0x18000174c
00002a32  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a3a  e8 09 ef 00 00  call 0x180011948
00002a3f  e9 08 ed ff ff  jmp 0x18000174c
00002a44  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a4c  e8 31 ee 00 00  call 0x180011882
00002a51  e9 f6 ec ff ff  jmp 0x18000174c
00002a56  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a5e  e8 5d ef 00 00  call 0x1800119c0
00002a63  e9 e4 ec ff ff  jmp 0x18000174c
00002a68  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a70  e8 d9 ee 00 00  call 0x18001194e
00002a75  e9 d2 ec ff ff  jmp 0x18000174c
00002a7a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a82  e8 01 ee 00 00  call 0x180011888
00002a87  e9 c0 ec ff ff  jmp 0x18000174c
00002a8c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002a94  e8 47 ed 00 00  call 0x1800117e0
00002a99  e9 ae ec ff ff  jmp 0x18000174c
00002a9e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002aa6  e8 a9 ee 00 00  call 0x180011954
00002aab  e9 9c ec ff ff  jmp 0x18000174c
00002ab0  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002ab8  e8 9d ee 00 00  call 0x18001195a
00002abd  e9 8a ec ff ff  jmp 0x18000174c
00002ac2  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002aca  e8 bf ed 00 00  call 0x18001188e
00002acf  e9 78 ec ff ff  jmp 0x18000174c
00002ad4  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002adc  e8 05 ed 00 00  call 0x1800117e6
00002ae1  e9 66 ec ff ff  jmp 0x18000174c
00002ae6  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002aee  e8 47 ed 00 00  call 0x18001183a
00002af3  e9 54 ec ff ff  jmp 0x18000174c
00002af8  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b00  e8 5b ee 00 00  call 0x180011960
00002b05  e9 42 ec ff ff  jmp 0x18000174c
00002b0a  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b12  e8 81 ef 00 00  call 0x180011a98
00002b17  e9 30 ec ff ff  jmp 0x18000174c
00002b1c  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b24  e8 3d ee 00 00  call 0x180011966
00002b29  e9 1e ec ff ff  jmp 0x18000174c
00002b2e  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b36  e8 63 ef 00 00  call 0x180011a9e
00002b3b  e9 0c ec ff ff  jmp 0x18000174c
00002b40  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b48  e8 1f ee 00 00  call 0x18001196c
00002b4d  e9 fa eb ff ff  jmp 0x18000174c
00002b52  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b5a  e8 e1 ec 00 00  call 0x180011840
00002b5f  e9 e8 eb ff ff  jmp 0x18000174c
00002b64  48 8b 8c 24 88 02 00 00  mov rcx, qword ptr [rsp + 0x288]
00002b6c  e8 d5 ec 00 00  call 0x180011846
00002b71  e9 d6 eb ff ff  jmp 0x18000174c
; owner 0x2b80 runtime_2b80
00002b80  56  push rsi
00002b81  57  push rdi
00002b82  53  push rbx
00002b83  48 83 ec 20  sub rsp, 0x20
00002b87  48 c7 05 4e c0 01 00 00 00 04 00  mov qword ptr [rip + 0x1c04e], 0x40000
00002b92  48 8d 35 47 c0 01 00  lea rsi, [rip + 0x1c047]
00002b99  48 8d 3d 60 40 01 00  lea rdi, [rip + 0x14060]
00002ba0  48 8d 1d 31 c0 01 00  lea rbx, [rip + 0x1c031]
00002ba7  48 89 f9  mov rcx, rdi
00002baa  48 89 f2  mov rdx, rsi
00002bad  49 89 d8  mov r8, rbx
00002bb0  49 89 d9  mov r9, rbx
00002bb3  e8 08 e8 00 00  call 0x1800113c0
00002bb8  48 8d 0d 39 40 01 00  lea rcx, [rip + 0x14039]
00002bbf  48 89 f2  mov rdx, rsi
00002bc2  49 89 d8  mov r8, rbx
00002bc5  49 89 d9  mov r9, rbx
00002bc8  e8 f3 e7 00 00  call 0x1800113c0
00002bcd  48 89 f9  mov rcx, rdi
00002bd0  48 89 f2  mov rdx, rsi
00002bd3  49 89 d8  mov r8, rbx
00002bd6  49 89 d9  mov r9, rbx
00002bd9  e8 e2 e7 00 00  call 0x1800113c0
00002bde  e8 e3 e7 00 00  call 0x1800113c6
00002be3  e8 c8 05 00 00  call 0x1800031b0
00002be8  e8 83 12 00 00  call 0x180003e70
00002bed  e8 3e 01 00 00  call 0x180002d30
00002bf2  e8 c9 00 00 00  call 0x180002cc0
00002bf7  e8 64 1b 00 00  call 0x180004760
00002bfc  90  nop
00002bfd  48 83 c4 20  add rsp, 0x20
00002c01  5b  pop rbx
00002c02  5f  pop rdi
00002c03  5e  pop rsi
00002c04  e9 a7 16 00 00  jmp 0x1800042b0
; owner 0x2c10 runtime_2c10
00002c10  48 83 ec 38  sub rsp, 0x38
00002c14  48 c7 05 c1 f4 01 00 01 00 00 00  mov qword ptr [rip + 0x1f4c1], 1
00002c1f  48 c7 05 be f4 01 00 0a 00 00 00  mov qword ptr [rip + 0x1f4be], 0xa
00002c2a  48 c7 05 bb f4 01 00 0a 00 00 00  mov qword ptr [rip + 0x1f4bb], 0xa
00002c35  48 c7 05 b8 f4 01 00 1e 00 00 00  mov qword ptr [rip + 0x1f4b8], 0x1e
00002c40  48 8b 05 91 28 01 00  mov rax, qword ptr [rip + 0x12891]
00002c47  48 8b 40 38  mov rax, qword ptr [rax + 0x38]
00002c4b  48 89 05 ae f4 01 00  mov qword ptr [rip + 0x1f4ae], rax
00002c52  48 c7 05 ab f4 01 00 01 00 00 00  mov qword ptr [rip + 0x1f4ab], 1
00002c5d  0f 57 c0  xorps xmm0, xmm0
00002c60  0f 29 05 a9 f4 01 00  movaps xmmword ptr [rip + 0x1f4a9], xmm0
00002c67  48 c7 05 c6 f4 01 00 00 00 00 00  mov qword ptr [rip + 0x1f4c6], 0
00002c72  48 b8 2d 43 1c eb e2 36 1a 3f  movabs rax, 0x3f1a36e2eb1c432d
00002c7c  48 89 05 fd f3 01 00  mov qword ptr [rip + 0x1f3fd], rax
00002c83  4c 8b 05 de 27 01 00  mov r8, qword ptr [rip + 0x127de]
00002c8a  4c 89 44 24 30  mov qword ptr [rsp + 0x30], r8
00002c8f  49 83 c0 08  add r8, 8
00002c93  4c 89 44 24 28  mov qword ptr [rsp + 0x28], r8
00002c98  48 8d 0d 69 3f 01 00  lea rcx, [rip + 0x13f69]
00002c9f  48 89 4c 24 20  mov qword ptr [rsp + 0x20], rcx
00002ca4  48 89 ca  mov rdx, rcx
00002ca7  4d 89 c1  mov r9, r8
00002caa  e8 b1 1f 00 00  call 0x180004c60
00002caf  90  nop
00002cb0  48 83 c4 38  add rsp, 0x38
00002cb4  c3  ret
; owner 0x2cc0 PPEXEC_PHCBIO
00002cc0  56  push rsi
00002cc1  48 83 ec 20  sub rsp, 0x20
00002cc5  48 8d 0d 44 3f 01 00  lea rcx, [rip + 0x13f44]
00002ccc  e8 83 e6 00 00  call 0x180011354
00002cd1  48 8b 35 20 28 01 00  mov rsi, qword ptr [rip + 0x12820]
00002cd8  48 8b 84 c6 30 06 00 00  mov rax, qword ptr [rsi + rax*8 + 0x630]
00002ce0  48 89 05 09 bf 01 00  mov qword ptr [rip + 0x1bf09], rax
00002ce7  48 8d 0d 02 bf 01 00  lea rcx, [rip + 0x1bf02]
00002cee  e8 61 e6 00 00  call 0x180011354
00002cf3  48 8b 44 c6 50  mov rax, qword ptr [rsi + rax*8 + 0x50]
00002cf8  48 89 05 e9 be 01 00  mov qword ptr [rip + 0x1bee9], rax
00002cff  48 85 c0  test rax, rax
00002d02  7e 19  jle 0x180002d1d
00002d04  48 8d 0d dd be 01 00  lea rcx, [rip + 0x1bedd]
00002d0b  e8 44 e6 00 00  call 0x180011354
00002d10  48 ff c8  dec rax
00002d13  48 8b 0d 46 27 01 00  mov rcx, qword ptr [rip + 0x12746]
00002d1a  48 89 01  mov qword ptr [rcx], rax
00002d1d  48 83 c4 20  add rsp, 0x20
00002d21  5e  pop rsi
00002d22  c3  ret
; owner 0x2d30 PPEXEC_PHCDRS
00002d30  41 57  push r15
00002d32  41 56  push r14
00002d34  41 55  push r13
00002d36  41 54  push r12
00002d38  56  push rsi
00002d39  57  push rdi
00002d3a  55  push rbp
00002d3b  53  push rbx
00002d3c  48 81 ec e8 00 00 00  sub rsp, 0xe8
00002d43  48 8d 0d de 3e 01 00  lea rcx, [rip + 0x13ede]
00002d4a  e8 05 e6 00 00  call 0x180011354
00002d4f  48 89 05 1a bf 01 00  mov qword ptr [rip + 0x1bf1a], rax
00002d56  48 8b 35 9b 27 01 00  mov rsi, qword ptr [rip + 0x1279b]
00002d5d  48 8b 84 c6 f0 04 00 00  mov rax, qword ptr [rsi + rax*8 + 0x4f0]
00002d65  48 89 05 fc be 01 00  mov qword ptr [rip + 0x1befc], rax
00002d6c  48 8d 0d f5 be 01 00  lea rcx, [rip + 0x1bef5]
00002d73  e8 dc e5 00 00  call 0x180011354
00002d78  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
00002d7d  48 89 05 dc be 01 00  mov qword ptr [rip + 0x1bedc], rax
00002d84  48 83 f8 01  cmp rax, 1
00002d88  0f 85 07 04 00 00  jne 0x180003195
00002d8e  48 8b 05 db be 01 00  mov rax, qword ptr [rip + 0x1bedb]
00002d95  48 8b 84 c6 38 02 00 00  mov rax, qword ptr [rsi + rax*8 + 0x238]
00002d9d  48 89 05 b4 be 01 00  mov qword ptr [rip + 0x1beb4], rax
00002da4  48 85 c0  test rax, rax
00002da7  0f 84 e8 03 00 00  je 0x180003195
00002dad  48 8d 0d a4 be 01 00  lea rcx, [rip + 0x1bea4]
00002db4  e8 9b e5 00 00  call 0x180011354
00002db9  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
00002dbe  48 89 05 3b be 01 00  mov qword ptr [rip + 0x1be3b], rax
00002dc5  48 8b 05 a4 be 01 00  mov rax, qword ptr [rip + 0x1bea4]
00002dcc  48 8b 84 c6 e8 04 00 00  mov rax, qword ptr [rsi + rax*8 + 0x4e8]
00002dd4  48 89 05 75 be 01 00  mov qword ptr [rip + 0x1be75], rax
00002ddb  48 8d 0d 6e be 01 00  lea rcx, [rip + 0x1be6e]
00002de2  48 8d 15 5f be 01 00  lea rdx, [rip + 0x1be5f]
00002de9  4c 8d 05 50 be 01 00  lea r8, [rip + 0x1be50]
00002df0  4c 8d 0d 41 be 01 00  lea r9, [rip + 0x1be41]
00002df7  e8 dc e5 00 00  call 0x1800113d8
00002dfc  48 8b 15 45 be 01 00  mov rdx, qword ptr [rip + 0x1be45]
00002e03  48 8b 44 d6 28  mov rax, qword ptr [rsi + rdx*8 + 0x28]
00002e08  48 8b 4c d6 30  mov rcx, qword ptr [rsi + rdx*8 + 0x30]
00002e0d  4c 8d 04 40  lea r8, [rax + rax*2]
00002e11  4c 8b 4c d6 40  mov r9, qword ptr [rsi + rdx*8 + 0x40]
00002e16  4c 0f af c9  imul r9, rcx
00002e1a  4c 8b 15 cf 26 01 00  mov r10, qword ptr [rip + 0x126cf]
00002e21  4d 8b 52 10  mov r10, qword ptr [r10 + 0x10]
00002e25  4c 0f af d0  imul r10, rax
00002e29  48 8b 54 d6 38  mov rdx, qword ptr [rsi + rdx*8 + 0x38]
00002e2e  48 0f af d1  imul rdx, rcx
00002e32  48 c7 05 43 be 01 00 ff ff ff ff  mov qword ptr [rip + 0x1be43], 0xffffffffffffffff
00002e3d  4c 8d 1c 40  lea r11, [rax + rax*2]
00002e41  49 ff cb  dec r11
00002e44  4c 89 1d 3d be 01 00  mov qword ptr [rip + 0x1be3d], r11
00002e4b  4c 8b 1d ae bd 01 00  mov r11, qword ptr [rip + 0x1bdae]
00002e52  49 83 c3 07  add r11, 7
00002e56  4c 0f af d8  imul r11, rax
00002e5a  4d 01 d8  add r8, r11
00002e5d  49 ff c8  dec r8
00002e60  4c 89 05 29 be 01 00  mov qword ptr [rip + 0x1be29], r8
00002e67  4d 01 c1  add r9, r8
00002e6a  4c 89 0d 27 be 01 00  mov qword ptr [rip + 0x1be27], r9
00002e71  4d 01 d1  add r9, r10
00002e74  4c 89 0d 25 be 01 00  mov qword ptr [rip + 0x1be25], r9
00002e7b  49 01 d1  add r9, rdx
00002e7e  4c 89 0d 23 be 01 00  mov qword ptr [rip + 0x1be23], r9
00002e85  49 8d 0c 89  lea rcx, [r9 + rcx*4]
00002e89  48 89 0d 20 be 01 00  mov qword ptr [rip + 0x1be20], rcx
00002e90  48 01 c1  add rcx, rax
00002e93  48 89 0d 1e be 01 00  mov qword ptr [rip + 0x1be1e], rcx
00002e9a  48 01 d1  add rcx, rdx
00002e9d  48 89 0d 8c bd 01 00  mov qword ptr [rip + 0x1bd8c], rcx
00002ea4  74 23  je 0x180002ec9
00002ea6  48 8d 0d 6b 3d 01 00  lea rcx, [rip + 0x13d6b]
00002ead  48 8d 15 7c bd 01 00  lea rdx, [rip + 0x1bd7c]
00002eb4  4c 8d 05 6d bd 01 00  lea r8, [rip + 0x1bd6d]
00002ebb  4c 8d 0d 5e bd 01 00  lea r9, [rip + 0x1bd5e]
00002ec2  e8 f9 e4 00 00  call 0x1800113c0
00002ec7  eb 0b  jmp 0x180002ed4
00002ec9  48 c7 05 54 bd 01 00 00 00 00 00  mov qword ptr [rip + 0x1bd54], 0
00002ed4  48 c7 05 39 bd 01 00 ff ff ff ff  mov qword ptr [rip + 0x1bd39], 0xffffffffffffffff
00002edf  48 c7 05 76 bd 01 00 01 00 00 00  mov qword ptr [rip + 0x1bd76], 1
00002eea  48 8d 2d ef b1 01 00  lea rbp, [rip + 0x1b1ef]
00002ef1  48 8d 1d 10 bd 01 00  lea rbx, [rip + 0x1bd10]
00002ef8  48 8d 3d 21 3d 01 00  lea rdi, [rip + 0x13d21]
00002eff  4c 8b 35 d2 25 01 00  mov r14, qword ptr [rip + 0x125d2]
00002f06  49 8d 76 38  lea rsi, [r14 + 0x38]
00002f0a  49 83 c6 28  add r14, 0x28
00002f0e  4c 8d 3d ab b1 01 00  lea r15, [rip + 0x1b1ab]
00002f15  4c 8d 25 14 3d 01 00  lea r12, [rip + 0x13d14]
00002f1c  4c 8d ac 24 b8 00 00 00  lea r13, [rsp + 0xb8]
00002f24  eb 55  jmp 0x180002f7b
00002f30  48 85 c0  test rax, rax
00002f33  0f 84 77 01 00 00  je 0x1800030b0
00002f39  48 8b 0d 20 bd 01 00  mov rcx, qword ptr [rip + 0x1bd20]
00002f40  48 8d 15 39 bd 01 00  lea rdx, [rip + 0x1bd39]
00002f47  48 8b 4c ca f8  mov rcx, qword ptr [rdx + rcx*8 - 8]
00002f4c  48 03 0d d5 bc 01 00  add rcx, qword ptr [rip + 0x1bcd5]
00002f53  48 8b 15 f6 24 01 00  mov rdx, qword ptr [rip + 0x124f6]
00002f5a  48 89 4c c2 f8  mov qword ptr [rdx + rax*8 - 8], rcx
00002f5f  48 8b 05 fa bc 01 00  mov rax, qword ptr [rip + 0x1bcfa]
00002f66  48 8d 48 01  lea rcx, [rax + 1]
00002f6a  48 89 0d ef bc 01 00  mov qword ptr [rip + 0x1bcef], rcx
00002f71  48 83 f8 08  cmp rax, 8
00002f75  0f 8d 1a 02 00 00  jge 0x180003195
00002f7b  48 8b 05 96 bc 01 00  mov rax, qword ptr [rip + 0x1bc96]
00002f82  48 8d 48 02  lea rcx, [rax + 2]
00002f86  48 89 0d 8b bc 01 00  mov qword ptr [rip + 0x1bc8b], rcx
00002f8d  48 8d 0c c5 08 00 00 00  lea rcx, [rax*8 + 8]
00002f95  48 01 e9  add rcx, rbp
00002f98  48 89 da  mov rdx, rbx
00002f9b  e8 44 e4 00 00  call 0x1800113e4
00002fa0  48 89 05 69 bc 01 00  mov qword ptr [rip + 0x1bc69], rax
00002fa7  48 83 f8 08  cmp rax, 8
00002fab  7e 83  jle 0x180002f30
00002fad  48 8d 05 74 3c 01 00  lea rax, [rip + 0x13c74]
00002fb4  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00002fb9  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
00002fbe  48 89 7c 24 28  mov qword ptr [rsp + 0x28], rdi
00002fc3  48 89 74 24 20  mov qword ptr [rsp + 0x20], rsi
00002fc8  4c 89 f9  mov rcx, r15
00002fcb  4c 89 e2  mov rdx, r12
00002fce  4d 89 e0  mov r8, r12
00002fd1  4d 89 f1  mov r9, r14
00002fd4  e8 cf e3 00 00  call 0x1800113a8
00002fd9  48 85 c0  test rax, rax
00002fdc  74 81  je 0x180002f5f
00002fde  48 8b 05 33 bc 01 00  mov rax, qword ptr [rip + 0x1bc33]
00002fe5  48 8b 44 c5 f8  mov rax, qword ptr [rbp + rax*8 - 8]
00002fea  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
00002ff6  c7 44 24 5a 38 06 0b 01  mov dword ptr [rsp + 0x5a], 0x10b0638
00002ffe  66 c7 44 24 5e 02 00  mov word ptr [rsp + 0x5e], 2
00003005  48 c7 84 24 98 00 00 00 20 03 00 00  mov qword ptr [rsp + 0x98], 0x320
00003011  48 8b 0d 78 24 01 00  mov rcx, qword ptr [rip + 0x12478]
00003018  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
00003020  48 c7 84 24 a8 00 00 00 50 00 00 00  mov qword ptr [rsp + 0xa8], 0x50
0000302c  48 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], rax
00003034  48 8d 05 75 b1 01 00  lea rax, [rip + 0x1b175]
0000303b  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00003040  4c 89 e9  mov rcx, r13
00003043  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
0000304d  4c 8d 44 24 5a  lea r8, [rsp + 0x5a]
00003052  4c 8d 8c 24 98 00 00 00  lea r9, [rsp + 0x98]
0000305a  e8 ab ea 00 00  call 0x180011b0a
0000305f  48 8b 05 b2 bb 01 00  mov rax, qword ptr [rip + 0x1bbb2]
00003066  48 8b 44 c5 00  mov rax, qword ptr [rbp + rax*8]
0000306b  c7 44 24 56 0b 01 02 00  mov dword ptr [rsp + 0x56], 0x2010b
00003073  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
00003078  4c 89 e9  mov rcx, r13
0000307b  48 8d 54 24 56  lea rdx, [rsp + 0x56]
00003080  4c 8d 44 24 70  lea r8, [rsp + 0x70]
00003085  e8 86 ea 00 00  call 0x180011b10
0000308a  48 8b 05 7f bb 01 00  mov rax, qword ptr [rip + 0x1bb7f]
00003091  c7 44 24 52 0b 01 01 00  mov dword ptr [rsp + 0x52], 0x1010b
00003099  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
0000309e  4c 89 e9  mov rcx, r13
000030a1  48 8d 54 24 52  lea rdx, [rsp + 0x52]
000030a6  4c 8d 44 24 68  lea r8, [rsp + 0x68]
000030ab  e9 d3 00 00 00  jmp 0x180003183
000030b0  4c 8d 05 71 3b 01 00  lea r8, [rip + 0x13b71]
000030b7  4c 89 44 24 38  mov qword ptr [rsp + 0x38], r8
000030bc  48 89 7c 24 30  mov qword ptr [rsp + 0x30], rdi
000030c1  48 89 7c 24 28  mov qword ptr [rsp + 0x28], rdi
000030c6  48 89 74 24 20  mov qword ptr [rsp + 0x20], rsi
000030cb  4c 89 f9  mov rcx, r15
000030ce  4c 89 e2  mov rdx, r12
000030d1  4d 89 f1  mov r9, r14
000030d4  e8 cf e2 00 00  call 0x1800113a8
000030d9  48 85 c0  test rax, rax
000030dc  0f 84 7d fe ff ff  je 0x180002f5f
000030e2  48 8b 05 2f bb 01 00  mov rax, qword ptr [rip + 0x1bb2f]
000030e9  48 8b 44 c5 f8  mov rax, qword ptr [rbp + rax*8 - 8]
000030ee  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
000030fa  c7 44 24 4c 38 06 0b 01  mov dword ptr [rsp + 0x4c], 0x10b0638
00003102  66 c7 44 24 50 02 00  mov word ptr [rsp + 0x50], 2
00003109  48 c7 44 24 78 20 03 00 00  mov qword ptr [rsp + 0x78], 0x320
00003112  48 8b 0d 77 23 01 00  mov rcx, qword ptr [rip + 0x12377]
00003119  48 89 8c 24 80 00 00 00  mov qword ptr [rsp + 0x80], rcx
00003121  48 c7 84 24 88 00 00 00 50 00 00 00  mov qword ptr [rsp + 0x88], 0x50
0000312d  48 89 84 24 90 00 00 00  mov qword ptr [rsp + 0x90], rax
00003135  48 8d 05 24 b0 01 00  lea rax, [rip + 0x1b024]
0000313c  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00003141  4c 89 e9  mov rcx, r13
00003144  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
0000314e  4c 8d 44 24 4c  lea r8, [rsp + 0x4c]
00003153  4c 8d 4c 24 78  lea r9, [rsp + 0x78]
00003158  e8 ad e9 00 00  call 0x180011b0a
0000315d  48 8b 05 b4 ba 01 00  mov rax, qword ptr [rip + 0x1bab4]
00003164  48 8b 44 c5 00  mov rax, qword ptr [rbp + rax*8]
00003169  c7 44 24 48 0b 01 01 00  mov dword ptr [rsp + 0x48], 0x1010b
00003171  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
00003176  4c 89 e9  mov rcx, r13
00003179  48 8d 54 24 48  lea rdx, [rsp + 0x48]
0000317e  4c 8d 44 24 60  lea r8, [rsp + 0x60]
00003183  e8 88 e9 00 00  call 0x180011b10
00003188  4c 89 e1  mov rcx, r12
0000318b  e8 24 e2 00 00  call 0x1800113b4
00003190  e9 ca fd ff ff  jmp 0x180002f5f
00003195  48 81 c4 e8 00 00 00  add rsp, 0xe8
0000319c  5b  pop rbx
0000319d  5d  pop rbp
0000319e  5f  pop rdi
0000319f  5e  pop rsi
000031a0  41 5c  pop r12
000031a2  41 5d  pop r13
000031a4  41 5e  pop r14
000031a6  41 5f  pop r15
000031a8  c3  ret
; owner 0x31b0 PPEXEC_PHCLCD
000031b0  41 57  push r15
000031b2  41 56  push r14
000031b4  41 55  push r13
000031b6  41 54  push r12
000031b8  56  push rsi
000031b9  57  push rdi
000031ba  55  push rbp
000031bb  53  push rbx
000031bc  48 81 ec 08 01 00 00  sub rsp, 0x108
000031c3  4c 8b 3d d6 22 01 00  mov r15, qword ptr [rip + 0x122d6]
000031ca  31 f6  xor esi, esi
000031cc  41 b8 20 35 00 00  mov r8d, 0x3520
000031d2  4c 89 f9  mov rcx, r15
000031d5  31 d2  xor edx, edx
000031d7  e8 14 5c 00 00  call 0x180008df0
000031dc  48 8b 15 f5 22 01 00  mov rdx, qword ptr [rip + 0x122f5]
000031e3  48 8b 42 38  mov rax, qword ptr [rdx + 0x38]
000031e7  48 8b 0d 52 22 01 00  mov rcx, qword ptr [rip + 0x12252]
000031ee  66 90  nop
000031f0  48 89 04 f1  mov qword ptr [rcx + rsi*8], rax
000031f4  48 ff c6  inc rsi
000031f7  48 81 fe 5e 01 00 00  cmp rsi, 0x15e
000031fe  75 f0  jne 0x1800031f0
00003200  31 c0  xor eax, eax
00003202  48 8b 0d 9f 22 01 00  mov rcx, qword ptr [rip + 0x1229f]
00003209  0f 1f 80 00 00 00 00  nop dword ptr [rax]
00003210  48 c7 04 c1 00 00 00 00  mov qword ptr [rcx + rax*8], 0
00003218  48 ff c0  inc rax
0000321b  48 83 f8 05  cmp rax, 5
0000321f  75 ef  jne 0x180003210
00003221  48 c7 05 34 c6 01 00 06 00 00 00  mov qword ptr [rip + 0x1c634], 6
0000322c  48 c7 05 31 c6 01 00 00 00 00 00  mov qword ptr [rip + 0x1c631], 0
00003237  48 83 ba b0 00 00 00 05  cmp qword ptr [rdx + 0xb0], 5
0000323f  0f 84 88 00 00 00  je 0x1800032cd
00003245  48 8d 35 3c c6 01 00  lea rsi, [rip + 0x1c63c]
0000324c  48 89 74 24 20  mov qword ptr [rsp + 0x20], rsi
00003251  48 8d 0d 38 44 01 00  lea rcx, [rip + 0x14438]
00003258  48 8d 15 41 c6 01 00  lea rdx, [rip + 0x1c641]
0000325f  4c 8d 05 32 c6 01 00  lea r8, [rip + 0x1c632]
00003266  4c 8d 0d 23 c6 01 00  lea r9, [rip + 0x1c623]
0000326d  e8 7e e1 00 00  call 0x1800113f0
00003272  48 8b 05 1f c6 01 00  mov rax, qword ptr [rip + 0x1c61f]
00003279  48 8b 3d 78 22 01 00  mov rdi, qword ptr [rip + 0x12278]
00003280  48 8b 84 c7 c8 01 00 00  mov rax, qword ptr [rdi + rax*8 + 0x1c8]
00003288  48 89 05 f1 c5 01 00  mov qword ptr [rip + 0x1c5f1], rax
0000328f  48 85 c0  test rax, rax
00003292  74 39  je 0x1800032cd
00003294  48 89 74 24 20  mov qword ptr [rsp + 0x20], rsi
00003299  48 8d 0d e0 c5 01 00  lea rcx, [rip + 0x1c5e0]
000032a0  48 8d 15 d1 c5 01 00  lea rdx, [rip + 0x1c5d1]
000032a7  4c 8d 05 c2 c5 01 00  lea r8, [rip + 0x1c5c2]
000032ae  4c 8d 0d db c5 01 00  lea r9, [rip + 0x1c5db]
000032b5  e8 36 e1 00 00  call 0x1800113f0
000032ba  48 8b 05 af c5 01 00  mov rax, qword ptr [rip + 0x1c5af]
000032c1  48 8b 44 c7 f8  mov rax, qword ptr [rdi + rax*8 - 8]
000032c6  48 89 05 9b c5 01 00  mov qword ptr [rip + 0x1c59b], rax
000032cd  48 8b 3d 5c 21 01 00  mov rdi, qword ptr [rip + 0x1215c]
000032d4  48 83 3f 00  cmp qword ptr [rdi], 0
000032d8  74 2c  je 0x180003306
000032da  48 89 f9  mov rcx, rdi
000032dd  e8 1a e1 00 00  call 0x1800113fc
000032e2  48 c7 47 08 00 00 00 00  mov qword ptr [rdi + 8], 0
000032ea  48 8b 9f f0 15 00 00  mov rbx, qword ptr [rdi + 0x15f0]
000032f1  48 c7 05 64 c5 01 00 01 00 00 00  mov qword ptr [rip + 0x1c564], 1
000032fc  48 83 fb 02  cmp rbx, 2
00003300  0f 8d 01 0b 00 00  jge 0x180003e07
00003306  48 c7 87 f0 15 00 00 00 00 00 00  mov qword ptr [rdi + 0x15f0], 0
00003311  0f 57 c0  xorps xmm0, xmm0
00003314  0f 29 07  movaps xmmword ptr [rdi], xmm0
00003317  48 8d 87 08 16 00 00  lea rax, [rdi + 0x1608]
0000331e  31 c9  xor ecx, ecx
00003320  48 8d 15 b9 39 01 00  lea rdx, [rip + 0x139b9]
00003327  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00003330  0f 11 40 f0  movups xmmword ptr [rax - 0x10], xmm0
00003334  4c 8b 04 11  mov r8, qword ptr [rcx + rdx]
00003338  4c 89 00  mov qword ptr [rax], r8
0000333b  0f 29 44 4f 10  movaps xmmword ptr [rdi + rcx*2 + 0x10], xmm0
00003340  48 83 c1 08  add rcx, 8
00003344  48 83 c0 18  add rax, 0x18
00003348  48 81 f9 70 09 00 00  cmp rcx, 0x970
0000334f  75 df  jne 0x180003330
00003351  48 c7 05 04 c5 01 00 2f 01 00 00  mov qword ptr [rip + 0x1c504], 0x12f
0000335c  4c 8d 35 2d 43 01 00  lea r14, [rip + 0x1432d]
00003363  4c 89 f1  mov rcx, r14
00003366  e8 e9 df 00 00  call 0x180011354
0000336b  48 8b 1d 86 21 01 00  mov rbx, qword ptr [rip + 0x12186]
00003372  48 8b 84 c3 88 01 00 00  mov rax, qword ptr [rbx + rax*8 + 0x188]
0000337a  48 89 05 d7 c4 01 00  mov qword ptr [rip + 0x1c4d7], rax
00003381  48 8d 0d d0 c4 01 00  lea rcx, [rip + 0x1c4d0]
00003388  e8 c7 df 00 00  call 0x180011354
0000338d  48 89 05 bc c4 01 00  mov qword ptr [rip + 0x1c4bc], rax
00003394  48 8d 48 fb  lea rcx, [rax - 5]
00003398  48 89 0d a9 c4 01 00  mov qword ptr [rip + 0x1c4a9], rcx
0000339f  48 c7 05 96 c4 01 00 00 00 00 00  mov qword ptr [rip + 0x1c496], 0
000033aa  48 c7 05 83 c4 01 00 00 00 00 00  mov qword ptr [rip + 0x1c483], 0
000033b5  48 c7 05 70 c4 01 00 00 00 00 00  mov qword ptr [rip + 0x1c470], 0
000033c0  48 c7 05 5d c4 01 00 bf bd f0 ff  mov qword ptr [rip + 0x1c45d], 0xfffffffffff0bdbf
000033cb  48 c7 05 4a c4 01 00 ff ff ff ff  mov qword ptr [rip + 0x1c44a], 0xffffffffffffffff
000033d6  48 8b 74 c3 f8  mov rsi, qword ptr [rbx + rax*8 - 8]
000033db  48 c7 05 7a c4 01 00 01 00 00 00  mov qword ptr [rip + 0x1c47a], 1
000033e6  48 85 f6  test rsi, rsi
000033e9  0f 8e 9a 07 00 00  jle 0x180003b89
000033ef  48 b9 45 20 20 20 20 20 20 20  movabs rcx, 0x2020202020202045
000033f9  4c 8d 25 10 c4 01 00  lea r12, [rip + 0x1c410]
00003400  4c 8d 2d 59 42 01 00  lea r13, [rip + 0x14259]
00003407  48 8b 05 ca 20 01 00  mov rax, qword ptr [rip + 0x120ca]
0000340e  48 8d 50 38  lea rdx, [rax + 0x38]
00003412  48 89 54 24 78  mov qword ptr [rsp + 0x78], rdx
00003417  48 83 c0 28  add rax, 0x28
0000341b  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
00003420  48 8b 05 69 20 01 00  mov rax, qword ptr [rip + 0x12069]
00003427  48 83 c0 50  add rax, 0x50
0000342b  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
00003430  48 8d 81 04 24 38 33  lea rax, [rcx + 0x33382404]
00003437  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
0000343c  48 89 74 24 48  mov qword ptr [rsp + 0x48], rsi
00003441  eb 38  jmp 0x18000347b
00003443  48 8b 0d b6 c3 01 00  mov rcx, qword ptr [rip + 0x1c3b6]
0000344a  48 8b 15 4f 20 01 00  mov rdx, qword ptr [rip + 0x1204f]
00003451  48 89 4c c2 f8  mov qword ptr [rdx + rax*8 - 8], rcx
00003456  66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00003460  48 8b 05 f9 c3 01 00  mov rax, qword ptr [rip + 0x1c3f9]
00003467  48 8d 48 01  lea rcx, [rax + 1]
0000346b  48 89 0d ee c3 01 00  mov qword ptr [rip + 0x1c3ee], rcx
00003472  48 39 f0  cmp rax, rsi
00003475  0f 8d b6 06 00 00  jge 0x180003b31
0000347b  48 8b 05 c6 c3 01 00  mov rax, qword ptr [rip + 0x1c3c6]
00003482  48 8d 48 06  lea rcx, [rax + 6]
00003486  48 89 0d bb c3 01 00  mov qword ptr [rip + 0x1c3bb], rcx
0000348d  48 8d 0c c3  lea rcx, [rbx + rax*8]
00003491  48 83 c1 28  add rcx, 0x28
00003495  4c 89 e2  mov rdx, r12
00003498  e8 47 df 00 00  call 0x1800113e4
0000349d  48 89 05 74 c3 01 00  mov qword ptr [rip + 0x1c374], rax
000034a4  4c 8b 15 65 c3 01 00  mov r10, qword ptr [rip + 0x1c365]
000034ab  49 83 fa 02  cmp r10, 2
000034af  74 af  je 0x180003460
000034b1  4b 3b 44 d5 f8  cmp rax, qword ptr [r13 + r10*8 - 8]
000034b6  0f 8e 94 01 00 00  jle 0x180003650
000034bc  4c 89 74 24 38  mov qword ptr [rsp + 0x38], r14
000034c1  48 8d 05 c0 41 01 00  lea rax, [rip + 0x141c0]
000034c8  48 89 44 24 30  mov qword ptr [rsp + 0x30], rax
000034cd  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
000034d2  48 8b 44 24 78  mov rax, qword ptr [rsp + 0x78]
000034d7  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000034dc  48 8d 0d 3d ad 01 00  lea rcx, [rip + 0x1ad3d]
000034e3  48 8d 15 96 41 01 00  lea rdx, [rip + 0x14196]
000034ea  49 89 d0  mov r8, rdx
000034ed  4c 8b 4c 24 70  mov r9, qword ptr [rsp + 0x70]
000034f2  e8 b1 de 00 00  call 0x1800113a8
000034f7  48 85 c0  test rax, rax
000034fa  0f 84 60 ff ff ff  je 0x180003460
00003500  48 8b 05 41 c3 01 00  mov rax, qword ptr [rip + 0x1c341]
00003507  48 8b 44 c3 f8  mov rax, qword ptr [rbx + rax*8 - 8]
0000350c  48 c7 84 24 d8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xd8], 0
00003518  c7 44 24 5a 38 06 0b 01  mov dword ptr [rsp + 0x5a], 0x10b0638
00003520  66 c7 44 24 5e 02 00  mov word ptr [rsp + 0x5e], 2
00003527  48 c7 84 24 b8 00 00 00 20 03 00 00  mov qword ptr [rsp + 0xb8], 0x320
00003533  48 8b 0d 56 1f 01 00  mov rcx, qword ptr [rip + 0x11f56]
0000353a  48 89 8c 24 c0 00 00 00  mov qword ptr [rsp + 0xc0], rcx
00003542  48 c7 84 24 c8 00 00 00 50 00 00 00  mov qword ptr [rsp + 0xc8], 0x50
0000354e  48 89 84 24 d0 00 00 00  mov qword ptr [rsp + 0xd0], rax
00003556  48 8d 05 4b ad 01 00  lea rax, [rip + 0x1ad4b]
0000355d  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00003562  4c 89 ed  mov rbp, r13
00003565  4d 89 f5  mov r13, r14
00003568  4c 8d b4 24 d8 00 00 00  lea r14, [rsp + 0xd8]
00003570  4c 89 f1  mov rcx, r14
00003573  49 bf 00 ff 84 83 20 01 08 00  movabs r15, 0x801208384ff00
0000357d  4c 89 fa  mov rdx, r15
00003580  4c 8d 44 24 5a  lea r8, [rsp + 0x5a]
00003585  4c 8d 8c 24 b8 00 00 00  lea r9, [rsp + 0xb8]
0000358d  e8 78 e5 00 00  call 0x180011b0a
00003592  48 8b 05 af c2 01 00  mov rax, qword ptr [rip + 0x1c2af]
00003599  48 8b 04 c3  mov rax, qword ptr [rbx + rax*8]
0000359d  c7 44 24 56 0b 01 01 00  mov dword ptr [rsp + 0x56], 0x1010b
000035a5  48 89 84 24 90 00 00 00  mov qword ptr [rsp + 0x90], rax
000035ad  4c 89 f1  mov rcx, r14
000035b0  48 8d 54 24 56  lea rdx, [rsp + 0x56]
000035b5  4c 8d 84 24 90 00 00 00  lea r8, [rsp + 0x90]
000035bd  e8 4e e5 00 00  call 0x180011b10
000035c2  48 8b 05 4f c2 01 00  mov rax, qword ptr [rip + 0x1c24f]
000035c9  48 c7 84 24 d8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xd8], 0
000035d5  c7 44 24 50 38 06 0b 01  mov dword ptr [rsp + 0x50], 0x10b0638
000035dd  66 c7 44 24 54 01 00  mov word ptr [rsp + 0x54], 1
000035e4  48 c7 84 24 98 00 00 00 d0 02 00 00  mov qword ptr [rsp + 0x98], 0x2d0
000035f0  48 8b 4c 24 68  mov rcx, qword ptr [rsp + 0x68]
000035f5  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
000035fd  48 c7 84 24 a8 00 00 00 50 00 00 00  mov qword ptr [rsp + 0xa8], 0x50
00003609  48 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], rax
00003611  48 8d 05 60 ac 01 00  lea rax, [rip + 0x1ac60]
00003618  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0000361d  4c 89 f1  mov rcx, r14
00003620  4d 89 ee  mov r14, r13
00003623  49 89 ed  mov r13, rbp
00003626  4c 89 fa  mov rdx, r15
00003629  4c 8d 44 24 50  lea r8, [rsp + 0x50]
0000362e  4c 8d 8c 24 98 00 00 00  lea r9, [rsp + 0x98]
00003636  e8 cf e4 00 00  call 0x180011b0a
0000363b  4c 89 f1  mov rcx, r14
0000363e  e8 71 dd 00 00  call 0x1800113b4
00003643  e9 18 fe ff ff  jmp 0x180003460
00003650  48 85 c0  test rax, rax
00003653  0f 84 07 fe ff ff  je 0x180003460
00003659  49 83 fa 04  cmp r10, 4
0000365d  0f 94 c2  sete dl
00003660  49 83 fa 03  cmp r10, 3
00003664  41 0f 94 c4  sete r12b
00003668  48 8b 0d d9 c1 01 00  mov rcx, qword ptr [rip + 0x1c1d9]
0000366f  4c 8b 44 cb f8  mov r8, qword ptr [rbx + rcx*8 - 8]
00003674  4c 8b 0c cb  mov r9, qword ptr [rbx + rcx*8]
00003678  4d 89 c3  mov r11, r8
0000367b  4c 33 5c 24 60  xor r11, qword ptr [rsp + 0x60]
00003680  49 be 45 20 20 20 20 20 20 20  movabs r14, 0x2020202020202045
0000368a  49 8d b6 07 34 00 00  lea rsi, [r14 + 0x3407]
00003691  4c 31 ce  xor rsi, r9
00003694  4c 09 de  or rsi, r11
00003697  41 0f 94 c7  sete r15b
0000369b  4d 8d 9e 04 34 32 35  lea r11, [r14 + 0x35323404]
000036a2  4d 31 c3  xor r11, r8
000036a5  4c 89 ce  mov rsi, r9
000036a8  4c 31 f6  xor rsi, r14
000036ab  4c 09 de  or rsi, r11
000036ae  41 0f 94 c5  sete r13b
000036b2  49 83 fa 03  cmp r10, 3
000036b6  75 55  jne 0x18000370d
000036b8  48 c7 05 35 c1 01 00 01 00 00 00  mov qword ptr [rip + 0x1c135], 1
000036c3  bf 02 00 00 00  mov edi, 2
000036c8  48 8d 2d 71 35 01 00  lea rbp, [rip + 0x13571]
000036cf  45 31 f6  xor r14d, r14d
000036d2  66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
000036e0  49 89 fb  mov r11, rdi
000036e3  48 3b 45 00  cmp rax, qword ptr [rbp]
000036e7  40 0f 94 c6  sete sil
000036eb  74 24  je 0x180003711
000036ed  49 8d 7b 01  lea rdi, [r11 + 1]
000036f1  48 83 c5 08  add rbp, 8
000036f5  4d 89 de  mov r14, r11
000036f8  48 83 ff 13  cmp rdi, 0x13
000036fc  75 e2  jne 0x1800036e0
000036fe  48 ff cf  dec rdi
00003701  49 89 fe  mov r14, rdi
00003704  48 8b 3d 25 1d 01 00  mov rdi, qword ptr [rip + 0x11d25]
0000370b  eb 14  jmp 0x180003721
0000370d  31 ed  xor ebp, ebp
0000370f  eb 19  jmp 0x18000372a
00003711  40 b5 01  mov bpl, 1
00003714  49 83 fb 02  cmp r11, 2
00003718  48 8b 3d 11 1d 01 00  mov rdi, qword ptr [rip + 0x11d11]
0000371f  74 09  je 0x18000372a
00003721  4c 89 35 d0 c0 01 00  mov qword ptr [rip + 0x1c0d0], r14
00003728  89 f5  mov ebp, esi
0000372a  45 08 ef  or r15b, r13b
0000372d  45 20 fc  and r12b, r15b
00003730  44 08 e2  or dl, r12b
00003733  4c 8b 7c cb 10  mov r15, qword ptr [rbx + rcx*8 + 0x10]
00003738  4c 89 3d c9 c0 01 00  mov qword ptr [rip + 0x1c0c9], r15
0000373f  4d 85 ff  test r15, r15
00003742  74 47  je 0x18000378b
00003744  84 d2  test dl, dl
00003746  4c 8d 25 c3 c0 01 00  lea r12, [rip + 0x1c0c3]
0000374d  4c 8d 2d 0c 3f 01 00  lea r13, [rip + 0x13f0c]
00003754  0f 84 db 00 00 00  je 0x180003835
0000375a  48 8d 0d a7 c0 01 00  lea rcx, [rip + 0x1c0a7]
00003761  e8 ee db 00 00  call 0x180011354
00003766  48 8b 0d db c0 01 00  mov rcx, qword ptr [rip + 0x1c0db]
0000376d  48 8b 54 cb 20  mov rdx, qword ptr [rbx + rcx*8 + 0x20]
00003772  48 01 d0  add rax, rdx
00003775  48 ff c8  dec rax
00003778  48 89 05 81 c0 01 00  mov qword ptr [rip + 0x1c081], rax
0000377f  4c 8d 35 0a 3f 01 00  lea r14, [rip + 0x13f0a]
00003786  e9 3d 02 00 00  jmp 0x1800039c8
0000378b  49 83 fa 03  cmp r10, 3
0000378f  4c 8d 25 7a c0 01 00  lea r12, [rip + 0x1c07a]
00003796  4c 8d 2d c3 3e 01 00  lea r13, [rip + 0x13ec3]
0000379d  0f 85 95 01 00 00  jne 0x180003938
000037a3  4c 8b 3d be c0 01 00  mov r15, qword ptr [rip + 0x1c0be]
000037aa  4d 85 ff  test r15, r15
000037ad  4c 8d 35 dc 3e 01 00  lea r14, [rip + 0x13edc]
000037b4  0f 84 cf 01 00 00  je 0x180003989
000037ba  4c 8b 15 af c0 01 00  mov r10, qword ptr [rip + 0x1c0af]
000037c1  48 c7 05 2c c0 01 00 01 00 00 00  mov qword ptr [rip + 0x1c02c], 1
000037cc  0f 8e b7 01 00 00  jle 0x180003989
000037d2  49 f7 df  neg r15
000037d5  49 c1 e2 03  shl r10, 3
000037d9  49 01 da  add r10, rbx
000037dc  41 bc 01 00 00 00  mov r12d, 1
000037e2  45 31 ed  xor r13d, r13d
000037e5  31 f6  xor esi, esi
000037e7  eb 26  jmp 0x18000380f
000037f0  4c 8d 6e 02  lea r13, [rsi + 2]
000037f4  48 ff c6  inc rsi
000037f7  4f 8d 1c 27  lea r11, [r15 + r12]
000037fb  49 ff c3  inc r11
000037fe  49 ff c4  inc r12
00003801  49 83 c2 30  add r10, 0x30
00003805  49 83 fb 01  cmp r11, 1
00003809  0f 84 39 02 00 00  je 0x180003a48
0000380f  4d 39 02  cmp qword ptr [r10], r8
00003812  75 dc  jne 0x1800037f0
00003814  4d 39 4a 08  cmp qword ptr [r10 + 8], r9
00003818  75 d6  jne 0x1800037f0
0000381a  49 83 fc 01  cmp r12, 1
0000381e  48 8b 74 24 48  mov rsi, qword ptr [rsp + 0x48]
00003823  74 07  je 0x18000382c
00003825  4c 89 2d cc bf 01 00  mov qword ptr [rip + 0x1bfcc], r13
0000382c  4d 8b 4a 28  mov r9, qword ptr [r10 + 0x28]
00003830  e9 22 02 00 00  jmp 0x180003a57
00003835  48 8b 05 24 c0 01 00  mov rax, qword ptr [rip + 0x1c024]
0000383c  48 83 f8 01  cmp rax, 1
00003840  4c 8d 35 49 3e 01 00  lea r14, [rip + 0x13e49]
00003847  0f 84 56 01 00 00  je 0x1800039a3
0000384d  4c 8b 05 fc bf 01 00  mov r8, qword ptr [rip + 0x1bffc]
00003854  48 8d 50 ff  lea rdx, [rax - 1]
00003858  48 89 15 99 bf 01 00  mov qword ptr [rip + 0x1bf99], rdx
0000385f  48 83 f8 02  cmp rax, 2
00003863  0f 8c 3a 01 00 00  jl 0x1800039a3
00003869  4c 8b 4c cb 20  mov r9, qword ptr [rbx + rcx*8 + 0x20]
0000386e  4e 8d 1c c3  lea r11, [rbx + r8*8]
00003872  49 83 c3 28  add r11, 0x28
00003876  45 31 d2  xor r10d, r10d
00003879  45 31 c0  xor r8d, r8d
0000387c  eb 1c  jmp 0x18000389a
00003880  49 89 c2  mov r10, rax
00003883  4d 29 c2  sub r10, r8
00003886  49 83 c2 fe  add r10, -2
0000388a  49 ff c0  inc r8
0000388d  49 83 c3 30  add r11, 0x30
00003891  4c 39 c2  cmp rdx, r8
00003894  0f 84 fc 00 00 00  je 0x180003996
0000389a  4d 3b 0b  cmp r9, qword ptr [r11]
0000389d  75 e1  jne 0x180003880
0000389f  4d 3b 7b f0  cmp r15, qword ptr [r11 - 0x10]
000038a3  75 db  jne 0x180003880
000038a5  4d 85 c0  test r8, r8
000038a8  74 07  je 0x1800038b1
000038aa  4c 89 15 47 bf 01 00  mov qword ptr [rip + 0x1bf47], r10
000038b1  48 8b 05 70 bf 01 00  mov rax, qword ptr [rip + 0x1bf70]
000038b8  48 89 05 41 bf 01 00  mov qword ptr [rip + 0x1bf41], rax
000038bf  48 2b 44 cb 18  sub rax, qword ptr [rbx + rcx*8 + 0x18]
000038c4  48 89 05 5d bf 01 00  mov qword ptr [rip + 0x1bf5d], rax
000038cb  48 8b 0d 66 bf 01 00  mov rcx, qword ptr [rip + 0x1bf66]
000038d2  48 8d 41 01  lea rax, [rcx + 1]
000038d6  48 89 05 5b bf 01 00  mov qword ptr [rip + 0x1bf5b], rax
000038dd  48 8b 05 4c bf 01 00  mov rax, qword ptr [rip + 0x1bf4c]
000038e4  48 39 c1  cmp rcx, rax
000038e7  48 8b 74 24 48  mov rsi, qword ptr [rsp + 0x48]
000038ec  0f 8c 11 02 00 00  jl 0x180003b03
000038f2  48 8d 48 0a  lea rcx, [rax + 0xa]
000038f6  48 89 0d 33 bf 01 00  mov qword ptr [rip + 0x1bf33], rcx
000038fd  48 83 3d 3b bf 01 00 00  cmp qword ptr [rip + 0x1bf3b], 0
00003905  48 8d 44 00 14  lea rax, [rax + rax + 0x14]
0000390a  0f 84 d0 01 00 00  je 0x180003ae0
00003910  48 89 84 24 80 00 00 00  mov qword ptr [rsp + 0x80], rax
00003918  48 8d 0d 21 bf 01 00  lea rcx, [rip + 0x1bf21]
0000391f  48 8d 94 24 80 00 00 00  lea rdx, [rsp + 0x80]
00003927  4c 8d 05 c2 be 01 00  lea r8, [rip + 0x1bec2]
0000392e  e8 cf da 00 00  call 0x180011402
00003933  e9 cb 01 00 00  jmp 0x180003b03
00003938  4c 8d 35 51 3d 01 00  lea r14, [rip + 0x13d51]
0000393f  48 8b 74 24 48  mov rsi, qword ptr [rsp + 0x48]
00003944  49 83 fa 01  cmp r10, 1
00003948  0f 85 90 00 00 00  jne 0x1800039de
0000394e  48 8b 05 c3 be 01 00  mov rax, qword ptr [rip + 0x1bec3]
00003955  48 8d 90 7c fc ff ff  lea rdx, [rax - 0x384]
0000395c  48 81 fa 2c 01 00 00  cmp rdx, 0x12c
00003963  0f 83 da fa ff ff  jae 0x180003443
00003969  48 8d 0c cb  lea rcx, [rbx + rcx*8]
0000396d  48 83 c1 f8  add rcx, -8
00003971  48 8d 15 88 be 01 00  lea rdx, [rip + 0x1be88]
00003978  e8 43 dd 00 00  call 0x1800116c0
0000397d  48 8b 05 94 be 01 00  mov rax, qword ptr [rip + 0x1be94]
00003984  e9 ba fa ff ff  jmp 0x180003443
00003989  45 31 c9  xor r9d, r9d
0000398c  48 8b 74 24 48  mov rsi, qword ptr [rsp + 0x48]
00003991  e9 cf 00 00 00  jmp 0x180003a65
00003996  49 f7 d0  not r8
00003999  49 01 c0  add r8, rax
0000399c  4c 89 05 55 be 01 00  mov qword ptr [rip + 0x1be55], r8
000039a3  48 8d 0d 5e be 01 00  lea rcx, [rip + 0x1be5e]
000039aa  e8 59 da 00 00  call 0x180011408
000039af  48 8b 0d 92 be 01 00  mov rcx, qword ptr [rip + 0x1be92]
000039b6  48 8b 54 cb 20  mov rdx, qword ptr [rbx + rcx*8 + 0x20]
000039bb  48 01 d0  add rax, rdx
000039be  48 ff c8  dec rax
000039c1  48 89 05 38 be 01 00  mov qword ptr [rip + 0x1be38], rax
000039c8  48 8b 74 24 48  mov rsi, qword ptr [rsp + 0x48]
000039cd  4c 8b 15 3c be 01 00  mov r10, qword ptr [rip + 0x1be3c]
000039d4  49 83 fa 01  cmp r10, 1
000039d8  0f 84 70 ff ff ff  je 0x18000394e
000039de  49 83 fa 03  cmp r10, 3
000039e2  74 29  je 0x180003a0d
000039e4  49 83 fa 04  cmp r10, 4
000039e8  0f 85 72 fa ff ff  jne 0x180003460
000039ee  48 8b 05 0b be 01 00  mov rax, qword ptr [rip + 0x1be0b]
000039f5  48 8b 0d 1c be 01 00  mov rcx, qword ptr [rip + 0x1be1c]
000039fc  48 8b 15 a5 1a 01 00  mov rdx, qword ptr [rip + 0x11aa5]
00003a03  48 89 44 ca f8  mov qword ptr [rdx + rcx*8 - 8], rax
00003a08  e9 53 fa ff ff  jmp 0x180003460
00003a0d  48 8b 05 ec bd 01 00  mov rax, qword ptr [rip + 0x1bdec]
00003a14  48 85 c0  test rax, rax
00003a17  0f 84 43 fa ff ff  je 0x180003460
00003a1d  48 8b 0d f4 bd 01 00  mov rcx, qword ptr [rip + 0x1bdf4]
00003a24  48 8b 15 15 1a 01 00  mov rdx, qword ptr [rip + 0x11a15]
00003a2b  48 89 44 ca f8  mov qword ptr [rdx + rcx*8 - 8], rax
00003a30  48 8b 05 91 b2 01 00  mov rax, qword ptr [rip + 0x1b291]
00003a37  48 8d 15 a2 b2 01 00  lea rdx, [rip + 0x1b2a2]
00003a3e  48 89 44 ca f8  mov qword ptr [rdx + rcx*8 - 8], rax
00003a43  e9 18 fa ff ff  jmp 0x180003460
00003a48  4c 89 25 a9 bd 01 00  mov qword ptr [rip + 0x1bda9], r12
00003a4f  45 31 c9  xor r9d, r9d
00003a52  48 8b 74 24 48  mov rsi, qword ptr [rsp + 0x48]
00003a57  4c 8d 25 b2 bd 01 00  lea r12, [rip + 0x1bdb2]
00003a5e  4c 8d 2d fb 3b 01 00  lea r13, [rip + 0x13bfb]
00003a65  4c 8b 44 cb 18  mov r8, qword ptr [rbx + rcx*8 + 0x18]
00003a6a  4c 89 05 57 b2 01 00  mov qword ptr [rip + 0x1b257], r8
00003a71  48 8d 04 40  lea rax, [rax + rax*2]
00003a75  4c 89 84 c7 e0 15 00 00  mov qword ptr [rdi + rax*8 + 0x15e0], r8
00003a7d  4c 89 8c c7 e8 15 00 00  mov qword ptr [rdi + rax*8 + 0x15e8], r9
00003a85  48 c7 05 70 bd 01 00 00 00 00 00  mov qword ptr [rip + 0x1bd70], 0
00003a90  4d 85 c0  test r8, r8
00003a93  0f 84 34 ff ff ff  je 0x1800039cd
00003a99  84 d2  test dl, dl
00003a9b  74 1d  je 0x180003aba
00003a9d  48 8b 05 7c bd 01 00  mov rax, qword ptr [rip + 0x1bd7c]
00003aa4  48 89 05 55 bd 01 00  mov qword ptr [rip + 0x1bd55], rax
00003aab  4c 29 c0  sub rax, r8
00003aae  48 89 05 6b bd 01 00  mov qword ptr [rip + 0x1bd6b], rax
00003ab5  e9 13 ff ff ff  jmp 0x1800039cd
00003aba  40 84 ed  test bpl, bpl
00003abd  0f 84 0a ff ff ff  je 0x1800039cd
00003ac3  48 8b 05 5e bd 01 00  mov rax, qword ptr [rip + 0x1bd5e]
00003aca  48 89 05 2f bd 01 00  mov qword ptr [rip + 0x1bd2f], rax
00003ad1  4c 29 c0  sub rax, r8
00003ad4  48 89 05 4d bd 01 00  mov qword ptr [rip + 0x1bd4d], rax
00003adb  e9 ed fe ff ff  jmp 0x1800039cd
00003ae0  48 89 84 24 88 00 00 00  mov qword ptr [rsp + 0x88], rax
00003ae8  48 8d 8c 24 88 00 00 00  lea rcx, [rsp + 0x88]
00003af0  48 8d 15 49 bd 01 00  lea rdx, [rip + 0x1bd49]
00003af7  4c 8d 05 f2 bc 01 00  lea r8, [rip + 0x1bcf2]
00003afe  e8 0b d9 00 00  call 0x18001140e
00003b03  48 8b 05 2e bd 01 00  mov rax, qword ptr [rip + 0x1bd2e]
00003b0a  48 01 c0  add rax, rax
00003b0d  48 03 05 dc bc 01 00  add rax, qword ptr [rip + 0x1bcdc]
00003b14  48 8b 0d fd bc 01 00  mov rcx, qword ptr [rip + 0x1bcfd]
00003b1b  48 89 4c c3 e8  mov qword ptr [rbx + rax*8 - 0x18], rcx
00003b20  48 8b 0d 21 bd 01 00  mov rcx, qword ptr [rip + 0x1bd21]
00003b27  48 89 4c c3 f0  mov qword ptr [rbx + rax*8 - 0x10], rcx
00003b2c  e9 9c fe ff ff  jmp 0x1800039cd
00003b31  48 8b 15 f0 bc 01 00  mov rdx, qword ptr [rip + 0x1bcf0]
00003b38  48 8d 8a 3b 42 0f 00  lea rcx, [rdx + 0xf423b]
00003b3f  48 8d 82 3b 42 0f 00  lea rax, [rdx + 0xf423b]
00003b46  48 f7 d8  neg rax
00003b49  48 81 fa c5 bd f0 ff  cmp rdx, -0xf423b
00003b50  4c 8b 05 c9 bc 01 00  mov r8, qword ptr [rip + 0x1bcc9]
00003b57  48 0f 4d c1  cmovge rax, rcx
00003b5b  4d 8d 48 fb  lea r9, [r8 - 5]
00003b5f  49 8d 48 fb  lea rcx, [r8 - 5]
00003b63  48 f7 d9  neg rcx
00003b66  49 83 f8 05  cmp r8, 5
00003b6a  4c 89 0d af bc 01 00  mov qword ptr [rip + 0x1bcaf], r9
00003b71  49 0f 4d c9  cmovge rcx, r9
00003b75  48 83 c2 fb  add rdx, -5
00003b79  48 89 15 a8 bc 01 00  mov qword ptr [rip + 0x1bca8], rdx
00003b80  4c 8b 3d 19 19 01 00  mov r15, qword ptr [rip + 0x11919]
00003b87  eb 20  jmp 0x180003ba9
00003b89  48 c7 05 8c bc 01 00 fa ff ff ff  mov qword ptr [rip + 0x1bc8c], 0xfffffffffffffffa
00003b94  48 c7 05 89 bc 01 00 ba bd f0 ff  mov qword ptr [rip + 0x1bc89], 0xfffffffffff0bdba
00003b9f  b9 06 00 00 00  mov ecx, 6
00003ba4  b8 06 00 00 00  mov eax, 6
00003ba9  48 8b 35 58 18 01 00  mov rsi, qword ptr [rip + 0x11858]
00003bb0  48 0f af 46 08  imul rax, qword ptr [rsi + 8]
00003bb5  48 01 c8  add rax, rcx
00003bb8  48 89 05 29 bc 01 00  mov qword ptr [rip + 0x1bc29], rax
00003bbf  48 8d 15 22 bc 01 00  lea rdx, [rip + 0x1bc22]
00003bc6  48 8d 0d cb 3a 01 00  lea rcx, [rip + 0x13acb]
00003bcd  4c 8d 05 0c bc 01 00  lea r8, [rip + 0x1bc0c]
00003bd4  4c 8d 0d fd bb 01 00  lea r9, [rip + 0x1bbfd]
00003bdb  e8 e0 d7 00 00  call 0x1800113c0
00003be0  48 8b 05 f9 bb 01 00  mov rax, qword ptr [rip + 0x1bbf9]
00003be7  48 8b 0d 32 bc 01 00  mov rcx, qword ptr [rip + 0x1bc32]
00003bee  48 89 ca  mov rdx, rcx
00003bf1  48 f7 da  neg rdx
00003bf4  48 0f 48 d1  cmovs rdx, rcx
00003bf8  48 01 d0  add rax, rdx
00003bfb  48 ff c8  dec rax
00003bfe  48 8b 4e 08  mov rcx, qword ptr [rsi + 8]
00003c02  48 89 c2  mov rdx, rax
00003c05  48 09 ca  or rdx, rcx
00003c08  48 c1 ea 20  shr rdx, 0x20
00003c0c  74 07  je 0x180003c15
00003c0e  48 99  cqo
00003c10  48 f7 f9  idiv rcx
00003c13  eb 04  jmp 0x180003c19
00003c15  31 d2  xor edx, edx
00003c17  f7 f1  div ecx
00003c19  48 ff c0  inc rax
00003c1c  48 89 05 9d b0 01 00  mov qword ptr [rip + 0x1b09d], rax
00003c23  48 8b 3d 0e bc 01 00  mov rdi, qword ptr [rip + 0x1bc0e]
00003c2a  48 85 ff  test rdi, rdi
00003c2d  0f 8e 02 01 00 00  jle 0x180003d35
00003c33  48 8b 05 b6 bb 01 00  mov rax, qword ptr [rip + 0x1bbb6]
00003c3a  48 83 c0 fe  add rax, -2
00003c3e  48 89 05 b3 bb 01 00  mov qword ptr [rip + 0x1bbb3], rax
00003c45  48 c7 05 10 bc 01 00 01 00 00 00  mov qword ptr [rip + 0x1bc10], 1
00003c50  eb 29  jmp 0x180003c7b
00003c60  48 8b 05 f9 bb 01 00  mov rax, qword ptr [rip + 0x1bbf9]
00003c67  48 8d 48 01  lea rcx, [rax + 1]
00003c6b  48 89 0d ee bb 01 00  mov qword ptr [rip + 0x1bbee], rcx
00003c72  48 39 f8  cmp rax, rdi
00003c75  0f 8d ae 00 00 00  jge 0x180003d29
00003c7b  48 8b 05 76 bb 01 00  mov rax, qword ptr [rip + 0x1bb76]
00003c82  48 8d 48 02  lea rcx, [rax + 2]
00003c86  48 89 0d 6b bb 01 00  mov qword ptr [rip + 0x1bb6b], rcx
00003c8d  48 8b 0d 2c b0 01 00  mov rcx, qword ptr [rip + 0x1b02c]
00003c94  48 8b 54 c3 08  mov rdx, qword ptr [rbx + rax*8 + 8]
00003c99  48 8b 44 c3 10  mov rax, qword ptr [rbx + rax*8 + 0x10]
00003c9e  4d 8b 44 d7 f8  mov r8, qword ptr [r15 + rdx*8 - 8]
00003ca3  4d 89 c1  mov r9, r8
00003ca6  49 f7 d9  neg r9
00003ca9  4d 0f 48 c8  cmovs r9, r8
00003cad  4a 8d 8c 09 bf bd f0 ff  lea rcx, [rcx + r9 - 0xf4241]
00003cb5  48 89 0d 14 bb 01 00  mov qword ptr [rip + 0x1bb14], rcx
00003cbc  49 89 4c d7 f8  mov qword ptr [r15 + rdx*8 - 8], rcx
00003cc1  48 89 05 80 bb 01 00  mov qword ptr [rip + 0x1bb80], rax
00003cc8  48 8d 0c c3  lea rcx, [rbx + rax*8]
00003ccc  48 83 c1 10  add rcx, 0x10
00003cd0  e8 33 d7 00 00  call 0x180011408
00003cd5  48 8b 15 6c bb 01 00  mov rdx, qword ptr [rip + 0x1bb6c]
00003cdc  48 8b 4c d3 18  mov rcx, qword ptr [rbx + rdx*8 + 0x18]
00003ce1  48 85 c9  test rcx, rcx
00003ce4  0f 8e 76 ff ff ff  jle 0x180003c60
00003cea  48 03 44 d3 20  add rax, qword ptr [rbx + rdx*8 + 0x20]
00003cef  48 8b 15 da ba 01 00  mov rdx, qword ptr [rip + 0x1bada]
00003cf6  48 8d 04 c3  lea rax, [rbx + rax*8]
00003cfa  48 83 c0 f8  add rax, -8
00003cfe  48 8d 14 d3  lea rdx, [rbx + rdx*8]
00003d02  45 31 c0  xor r8d, r8d
00003d05  66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00003d10  f2 42 0f 10 04 c0  movsd xmm0, qword ptr [rax + r8*8]
00003d16  f2 42 0f 11 04 c2  movsd qword ptr [rdx + r8*8], xmm0
00003d1c  49 ff c0  inc r8
00003d1f  49 39 c8  cmp r8, rcx
00003d22  7c ec  jl 0x180003d10
00003d24  e9 37 ff ff ff  jmp 0x180003c60
00003d29  48 8d 0d 10 bb 01 00  lea rcx, [rip + 0x1bb10]
00003d30  e8 c7 d6 00 00  call 0x1800113fc
00003d35  4c 8b 1d 04 17 01 00  mov r11, qword ptr [rip + 0x11704]
00003d3c  49 8b 8b 40 01 00 00  mov rcx, qword ptr [r11 + 0x140]
00003d43  48 8b 05 8e 17 01 00  mov rax, qword ptr [rip + 0x1178e]
00003d4a  48 8b 40 38  mov rax, qword ptr [rax + 0x38]
00003d4e  48 39 c1  cmp rcx, rax
00003d51  74 1f  je 0x180003d72
00003d53  48 8b 15 86 ba 01 00  mov rdx, qword ptr [rip + 0x1ba86]
00003d5a  49 89 c8  mov r8, rcx
00003d5d  49 f7 d8  neg r8
00003d60  4c 0f 48 c1  cmovs r8, rcx
00003d64  49 8d 0c 10  lea rcx, [r8 + rdx]
00003d68  48 ff c9  dec rcx
00003d6b  49 89 8b 40 01 00 00  mov qword ptr [r11 + 0x140], rcx
00003d72  49 8b 8b 48 01 00 00  mov rcx, qword ptr [r11 + 0x148]
00003d79  48 39 c1  cmp rcx, rax
00003d7c  74 1e  je 0x180003d9c
00003d7e  48 8b 05 5b ba 01 00  mov rax, qword ptr [rip + 0x1ba5b]
00003d85  48 89 ca  mov rdx, rcx
00003d88  48 f7 da  neg rdx
00003d8b  48 0f 48 d1  cmovs rdx, rcx
00003d8f  48 01 d0  add rax, rdx
00003d92  48 ff c8  dec rax
00003d95  49 89 83 48 01 00 00  mov qword ptr [r11 + 0x148], rax
00003d9c  48 c7 c0 bf bd f0 ff  mov rax, 0xfffffffffff0bdbf
00003da3  48 03 05 16 af 01 00  add rax, qword ptr [rip + 0x1af16]
00003daa  31 c9  xor ecx, ecx
00003dac  48 8d 15 8d 2e 01 00  lea rdx, [rip + 0x12e8d]
00003db3  66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00003dc0  4c 8b 04 11  mov r8, qword ptr [rcx + rdx]
00003dc4  4f 8b 4c c3 f8  mov r9, qword ptr [r11 + r8*8 - 8]
00003dc9  4d 89 ca  mov r10, r9
00003dcc  49 f7 da  neg r10
00003dcf  4d 0f 48 d1  cmovs r10, r9
00003dd3  49 01 c2  add r10, rax
00003dd6  4f 89 54 c3 f8  mov qword ptr [r11 + r8*8 - 8], r10
00003ddb  48 83 c1 08  add rcx, 8
00003ddf  48 81 f9 88 00 00 00  cmp rcx, 0x88
00003de6  75 d8  jne 0x180003dc0
00003de8  48 c7 05 6d ba 01 00 12 00 00 00  mov qword ptr [rip + 0x1ba6d], 0x12
00003df3  48 81 c4 08 01 00 00  add rsp, 0x108
00003dfa  5b  pop rbx
00003dfb  5d  pop rbp
00003dfc  5f  pop rdi
00003dfd  5e  pop rsi
00003dfe  41 5c  pop r12
00003e00  41 5d  pop r13
00003e02  41 5e  pop r14
00003e04  41 5f  pop r15
00003e06  c3  ret
00003e07  48 ff cb  dec rbx
00003e0a  b8 01 00 00 00  mov eax, 1
00003e0f  eb 26  jmp 0x180003e37
00003e20  48 8d 48 01  lea rcx, [rax + 1]
00003e24  48 89 0d 35 ba 01 00  mov qword ptr [rip + 0x1ba35], rcx
00003e2b  48 39 d8  cmp rax, rbx
00003e2e  48 89 c8  mov rax, rcx
00003e31  0f 8d cf f4 ff ff  jge 0x180003306
00003e37  48 89 c1  mov rcx, rax
00003e3a  48 c1 e1 04  shl rcx, 4
00003e3e  48 83 7c 39 08 00  cmp qword ptr [rcx + rdi + 8], 0
00003e44  74 da  je 0x180003e20
00003e46  48 01 f9  add rcx, rdi
00003e49  e8 ae d5 00 00  call 0x1800113fc
00003e4e  48 8b 05 0b ba 01 00  mov rax, qword ptr [rip + 0x1ba0b]
00003e55  48 89 c1  mov rcx, rax
00003e58  48 c1 e1 04  shl rcx, 4
00003e5c  48 c7 44 39 08 00 00 00 00  mov qword ptr [rcx + rdi + 8], 0
00003e65  eb b9  jmp 0x180003e20
; owner 0x3e70 PPEXEC_PHCMAT
00003e70  41 57  push r15
00003e72  41 56  push r14
00003e74  41 55  push r13
00003e76  41 54  push r12
00003e78  56  push rsi
00003e79  57  push rdi
00003e7a  55  push rbp
00003e7b  53  push rbx
00003e7c  48 81 ec e8 00 00 00  sub rsp, 0xe8
00003e83  48 8b 35 76 15 01 00  mov rsi, qword ptr [rip + 0x11576]
00003e8a  41 b8 f8 05 00 00  mov r8d, 0x5f8
00003e90  48 89 f1  mov rcx, rsi
00003e93  31 d2  xor edx, edx
00003e95  e8 56 4f 00 00  call 0x180008df0
00003e9a  48 c7 05 53 ba 01 00 c0 00 00 00  mov qword ptr [rip + 0x1ba53], 0xc0
00003ea5  48 8d 3d fc 37 01 00  lea rdi, [rip + 0x137fc]
00003eac  48 89 f9  mov rcx, rdi
00003eaf  e8 a0 d4 00 00  call 0x180011354
00003eb4  48 89 05 35 ba 01 00  mov qword ptr [rip + 0x1ba35], rax
00003ebb  48 8b 1d 36 16 01 00  mov rbx, qword ptr [rip + 0x11636]
00003ec2  48 8b 84 c3 18 01 00 00  mov rax, qword ptr [rbx + rax*8 + 0x118]
00003eca  48 89 05 17 ba 01 00  mov qword ptr [rip + 0x1ba17], rax
00003ed1  48 8d 0d 10 ba 01 00  lea rcx, [rip + 0x1ba10]
00003ed8  e8 77 d4 00 00  call 0x180011354
00003edd  48 83 7c c3 10 00  cmp qword ptr [rbx + rax*8 + 0x10], 0
00003ee3  0f 8e b2 03 00 00  jle 0x18000429b
00003ee9  48 8b 05 00 ba 01 00  mov rax, qword ptr [rip + 0x1ba00]
00003ef0  48 8b 84 c3 d0 00 00 00  mov rax, qword ptr [rbx + rax*8 + 0xd0]
00003ef8  48 89 05 e1 b9 01 00  mov qword ptr [rip + 0x1b9e1], rax
00003eff  48 85 c0  test rax, rax
00003f02  0f 8e 93 03 00 00  jle 0x18000429b
00003f08  48 8d 0d d1 b9 01 00  lea rcx, [rip + 0x1b9d1]
00003f0f  e8 40 d4 00 00  call 0x180011354
00003f14  48 89 05 bd b9 01 00  mov qword ptr [rip + 0x1b9bd], rax
00003f1b  48 8b 44 c3 f8  mov rax, qword ptr [rbx + rax*8 - 8]
00003f20  48 89 05 81 b9 01 00  mov qword ptr [rip + 0x1b981], rax
00003f27  48 85 c0  test rax, rax
00003f2a  0f 8e 6b 03 00 00  jle 0x18000429b
00003f30  48 8b 05 b9 b9 01 00  mov rax, qword ptr [rip + 0x1b9b9]
00003f37  48 8b 84 c3 88 01 00 00  mov rax, qword ptr [rbx + rax*8 + 0x188]
00003f3f  48 89 05 8a b9 01 00  mov qword ptr [rip + 0x1b98a], rax
00003f46  48 8d 0d 83 b9 01 00  lea rcx, [rip + 0x1b983]
00003f4d  e8 02 d4 00 00  call 0x180011354
00003f52  48 8d 48 fb  lea rcx, [rax - 5]
00003f56  48 89 0d 6b b9 01 00  mov qword ptr [rip + 0x1b96b], rcx
00003f5d  4c 8b 64 c3 f8  mov r12, qword ptr [rbx + rax*8 - 8]
00003f62  48 c7 05 8b b9 01 00 01 00 00 00  mov qword ptr [rip + 0x1b98b], 1
00003f6d  4d 85 e4  test r12, r12
00003f70  0f 8e 25 03 00 00  jle 0x18000429b
00003f76  4c 8d 35 3b b9 01 00  lea r14, [rip + 0x1b93b]
00003f7d  4c 8b 3d 54 15 01 00  mov r15, qword ptr [rip + 0x11554]
00003f84  49 8d 47 38  lea rax, [r15 + 0x38]
00003f88  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
00003f8d  49 83 c7 28  add r15, 0x28
00003f91  4c 8d 2d 18 37 01 00  lea r13, [rip + 0x13718]
00003f98  eb 51  jmp 0x180003feb
00003f9a  48 8b 44 c3 18  mov rax, qword ptr [rbx + rax*8 + 0x18]
00003f9f  48 89 05 0a b9 01 00  mov qword ptr [rip + 0x1b90a], rax
00003fa6  48 8d 0d 03 b9 01 00  lea rcx, [rip + 0x1b903]
00003fad  e8 a2 d3 00 00  call 0x180011354
00003fb2  48 8b 0d 0f b9 01 00  mov rcx, qword ptr [rip + 0x1b90f]
00003fb9  48 8b 4c cb 20  mov rcx, qword ptr [rbx + rcx*8 + 0x20]
00003fbe  48 01 c8  add rax, rcx
00003fc1  48 ff c8  dec rax
00003fc4  48 8b 0d f5 b8 01 00  mov rcx, qword ptr [rip + 0x1b8f5]
00003fcb  48 89 44 ce f8  mov qword ptr [rsi + rcx*8 - 8], rax
00003fd0  48 8b 05 21 b9 01 00  mov rax, qword ptr [rip + 0x1b921]
00003fd7  48 8d 48 01  lea rcx, [rax + 1]
00003fdb  48 89 0d 16 b9 01 00  mov qword ptr [rip + 0x1b916], rcx
00003fe2  4c 39 e0  cmp rax, r12
00003fe5  0f 8d b0 02 00 00  jge 0x18000429b
00003feb  48 8b 05 d6 b8 01 00  mov rax, qword ptr [rip + 0x1b8d6]
00003ff2  48 8d 48 06  lea rcx, [rax + 6]
00003ff6  48 89 0d cb b8 01 00  mov qword ptr [rip + 0x1b8cb], rcx
00003ffd  48 83 7c c3 48 00  cmp qword ptr [rbx + rax*8 + 0x48], 0
00004003  7f cb  jg 0x180003fd0
00004005  48 8d 0c c3  lea rcx, [rbx + rax*8]
00004009  48 83 c1 28  add rcx, 0x28
0000400d  4c 89 f2  mov rdx, r14
00004010  e8 cf d3 00 00  call 0x1800113e4
00004015  48 89 05 a4 b8 01 00  mov qword ptr [rip + 0x1b8a4], rax
0000401c  48 83 3d 94 b8 01 00 02  cmp qword ptr [rip + 0x1b894], 2
00004024  75 aa  jne 0x180003fd0
00004026  48 3d bf 00 00 00  cmp rax, 0xbf
0000402c  0f 8e 17 01 00 00  jle 0x180004149
00004032  48 89 7c 24 38  mov qword ptr [rsp + 0x38], rdi
00004037  48 8d 05 62 36 01 00  lea rax, [rip + 0x13662]
0000403e  48 89 44 24 30  mov qword ptr [rsp + 0x30], rax
00004043  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00004048  48 8b 44 24 58  mov rax, qword ptr [rsp + 0x58]
0000404d  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00004052  48 8d 0d a7 a2 01 00  lea rcx, [rip + 0x1a2a7]
00004059  4c 89 ea  mov rdx, r13
0000405c  4d 89 e8  mov r8, r13
0000405f  4d 89 f9  mov r9, r15
00004062  e8 41 d3 00 00  call 0x1800113a8
00004067  48 85 c0  test rax, rax
0000406a  0f 84 60 ff ff ff  je 0x180003fd0
00004070  48 8b 05 51 b8 01 00  mov rax, qword ptr [rip + 0x1b851]
00004077  48 8b 44 c3 f8  mov rax, qword ptr [rbx + rax*8 - 8]
0000407c  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
00004088  c7 44 24 52 38 06 0b 01  mov dword ptr [rsp + 0x52], 0x10b0638
00004090  66 c7 44 24 56 02 00  mov word ptr [rsp + 0x56], 2
00004097  48 c7 84 24 98 00 00 00 20 03 00 00  mov qword ptr [rsp + 0x98], 0x320
000040a3  48 8b 0d e6 13 01 00  mov rcx, qword ptr [rip + 0x113e6]
000040aa  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
000040b2  48 c7 84 24 a8 00 00 00 50 00 00 00  mov qword ptr [rsp + 0xa8], 0x50
000040be  48 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], rax
000040c6  48 8d 05 93 a2 01 00  lea rax, [rip + 0x1a293]
000040cd  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000040d2  48 8d ac 24 b8 00 00 00  lea rbp, [rsp + 0xb8]
000040da  48 89 e9  mov rcx, rbp
000040dd  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
000040e7  4c 8d 44 24 52  lea r8, [rsp + 0x52]
000040ec  4c 8d 8c 24 98 00 00 00  lea r9, [rsp + 0x98]
000040f4  e8 11 da 00 00  call 0x180011b0a
000040f9  48 8b 05 c8 b7 01 00  mov rax, qword ptr [rip + 0x1b7c8]
00004100  48 8b 04 c3  mov rax, qword ptr [rbx + rax*8]
00004104  c7 44 24 4e 0b 01 02 00  mov dword ptr [rsp + 0x4e], 0x2010b
0000410c  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
00004111  48 89 e9  mov rcx, rbp
00004114  48 8d 54 24 4e  lea rdx, [rsp + 0x4e]
00004119  4c 8d 44 24 70  lea r8, [rsp + 0x70]
0000411e  e8 ed d9 00 00  call 0x180011b10
00004123  48 8b 05 96 b7 01 00  mov rax, qword ptr [rip + 0x1b796]
0000412a  c7 44 24 4a 0b 01 01 00  mov dword ptr [rsp + 0x4a], 0x1010b
00004132  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
00004137  48 89 e9  mov rcx, rbp
0000413a  48 8d 54 24 4a  lea rdx, [rsp + 0x4a]
0000413f  4c 8d 44 24 68  lea r8, [rsp + 0x68]
00004144  e9 40 01 00 00  jmp 0x180004289
00004149  48 85 c0  test rax, rax
0000414c  74 55  je 0x1800041a3
0000414e  48 8b 05 83 b7 01 00  mov rax, qword ptr [rip + 0x1b783]
00004155  48 ff c0  inc rax
00004158  48 8b 0d 49 b7 01 00  mov rcx, qword ptr [rip + 0x1b749]
0000415f  48 85 c9  test rcx, rcx
00004162  0f 8e 32 fe ff ff  jle 0x180003f9a
00004168  4c 8b 05 59 b7 01 00  mov r8, qword ptr [rip + 0x1b759]
0000416f  4a 8b 54 c3 f8  mov rdx, qword ptr [rbx + r8*8 - 8]
00004174  4e 8b 04 c3  mov r8, qword ptr [rbx + r8*8]
00004178  45 31 c9  xor r9d, r9d
0000417b  eb 13  jmp 0x180004190
00004180  48 83 c0 05  add rax, 5
00004184  49 ff c1  inc r9
00004187  49 39 c9  cmp r9, rcx
0000418a  0f 8d 0a fe ff ff  jge 0x180003f9a
00004190  48 39 54 c3 08  cmp qword ptr [rbx + rax*8 + 8], rdx
00004195  75 e9  jne 0x180004180
00004197  4c 39 44 c3 10  cmp qword ptr [rbx + rax*8 + 0x10], r8
0000419c  75 e2  jne 0x180004180
0000419e  e9 f7 fd ff ff  jmp 0x180003f9a
000041a3  48 89 7c 24 38  mov qword ptr [rsp + 0x38], rdi
000041a8  48 8d 05 f1 34 01 00  lea rax, [rip + 0x134f1]
000041af  48 89 44 24 30  mov qword ptr [rsp + 0x30], rax
000041b4  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
000041b9  48 8b 44 24 58  mov rax, qword ptr [rsp + 0x58]
000041be  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000041c3  48 8d 0d 36 a1 01 00  lea rcx, [rip + 0x1a136]
000041ca  4c 89 ea  mov rdx, r13
000041cd  49 89 f8  mov r8, rdi
000041d0  4d 89 f9  mov r9, r15
000041d3  e8 d0 d1 00 00  call 0x1800113a8
000041d8  48 85 c0  test rax, rax
000041db  0f 84 ef fd ff ff  je 0x180003fd0
000041e1  48 8b 05 e0 b6 01 00  mov rax, qword ptr [rip + 0x1b6e0]
000041e8  48 8b 44 c3 f8  mov rax, qword ptr [rbx + rax*8 - 8]
000041ed  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
000041f9  c7 44 24 44 38 06 0b 01  mov dword ptr [rsp + 0x44], 0x10b0638
00004201  66 c7 44 24 48 02 00  mov word ptr [rsp + 0x48], 2
00004208  48 c7 44 24 78 20 03 00 00  mov qword ptr [rsp + 0x78], 0x320
00004211  48 8b 0d 78 12 01 00  mov rcx, qword ptr [rip + 0x11278]
00004218  48 89 8c 24 80 00 00 00  mov qword ptr [rsp + 0x80], rcx
00004220  48 c7 84 24 88 00 00 00 50 00 00 00  mov qword ptr [rsp + 0x88], 0x50
0000422c  48 89 84 24 90 00 00 00  mov qword ptr [rsp + 0x90], rax
00004234  48 8d 05 d5 a0 01 00  lea rax, [rip + 0x1a0d5]
0000423b  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00004240  48 8d ac 24 b8 00 00 00  lea rbp, [rsp + 0xb8]
00004248  48 89 e9  mov rcx, rbp
0000424b  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
00004255  4c 8d 44 24 44  lea r8, [rsp + 0x44]
0000425a  4c 8d 4c 24 78  lea r9, [rsp + 0x78]
0000425f  e8 a6 d8 00 00  call 0x180011b0a
00004264  48 8b 05 5d b6 01 00  mov rax, qword ptr [rip + 0x1b65d]
0000426b  48 8b 04 c3  mov rax, qword ptr [rbx + rax*8]
0000426f  c7 44 24 40 0b 01 01 00  mov dword ptr [rsp + 0x40], 0x1010b
00004277  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
0000427c  48 89 e9  mov rcx, rbp
0000427f  48 8d 54 24 40  lea rdx, [rsp + 0x40]
00004284  4c 8d 44 24 60  lea r8, [rsp + 0x60]
00004289  e8 82 d8 00 00  call 0x180011b10
0000428e  4c 89 e9  mov rcx, r13
00004291  e8 1e d1 00 00  call 0x1800113b4
00004296  e9 35 fd ff ff  jmp 0x180003fd0
0000429b  48 81 c4 e8 00 00 00  add rsp, 0xe8
000042a2  5b  pop rbx
000042a3  5d  pop rbp
000042a4  5f  pop rdi
000042a5  5e  pop rsi
000042a6  41 5c  pop r12
000042a8  41 5d  pop r13
000042aa  41 5e  pop r14
000042ac  41 5f  pop r15
000042ae  c3  ret
; owner 0x42b0 PPEXEC_PHCRES
000042b0  41 57  push r15
000042b2  41 56  push r14
000042b4  41 55  push r13
000042b6  41 54  push r12
000042b8  56  push rsi
000042b9  57  push rdi
000042ba  55  push rbp
000042bb  53  push rbx
000042bc  48 81 ec e8 00 00 00  sub rsp, 0xe8
000042c3  31 c0  xor eax, eax
000042c5  48 8d 0d 74 b6 01 00  lea rcx, [rip + 0x1b674]
000042cc  48 8b 3d 25 11 01 00  mov rdi, qword ptr [rip + 0x11125]
000042d3  66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
000042e0  48 c7 04 08 00 00 00 00  mov qword ptr [rax + rcx], 0
000042e8  48 c7 04 07 00 00 00 00  mov qword ptr [rdi + rax], 0
000042f0  48 83 c0 08  add rax, 8
000042f4  48 83 f8 38  cmp rax, 0x38
000042f8  75 e6  jne 0x1800042e0
000042fa  48 c7 05 23 b6 01 00 08 00 00 00  mov qword ptr [rip + 0x1b623], 8
00004305  48 8d 0d b4 33 01 00  lea rcx, [rip + 0x133b4]
0000430c  e8 43 d0 00 00  call 0x180011354
00004311  48 89 05 08 b6 01 00  mov qword ptr [rip + 0x1b608], rax
00004318  48 8b 35 d1 11 01 00  mov rsi, qword ptr [rip + 0x111d1]
0000431f  48 83 3e 00  cmp qword ptr [rsi], 0
00004323  0f 8e b6 00 00 00  jle 0x1800043df
00004329  4c 8b 35 c8 11 01 00  mov r14, qword ptr [rip + 0x111c8]
00004330  49 8b 84 c6 60 01 00 00  mov rax, qword ptr [r14 + rax*8 + 0x160]
00004338  48 89 05 d9 b5 01 00  mov qword ptr [rip + 0x1b5d9], rax
0000433f  48 8d 0d d2 b5 01 00  lea rcx, [rip + 0x1b5d2]
00004346  e8 09 d0 00 00  call 0x180011354
0000434b  48 ff c8  dec rax
0000434e  48 89 05 eb b5 01 00  mov qword ptr [rip + 0x1b5eb], rax
00004355  48 83 7e 20 00  cmp qword ptr [rsi + 0x20], 0
0000435a  7e 57  jle 0x1800043b3
0000435c  48 8b 05 bd b5 01 00  mov rax, qword ptr [rip + 0x1b5bd]
00004363  49 8b 84 c6 68 01 00 00  mov rax, qword ptr [r14 + rax*8 + 0x168]
0000436b  48 89 05 a6 b5 01 00  mov qword ptr [rip + 0x1b5a6], rax
00004372  48 8d 1d 9f b5 01 00  lea rbx, [rip + 0x1b59f]
00004379  48 89 d9  mov rcx, rbx
0000437c  e8 d3 cf 00 00  call 0x180011354
00004381  48 ff c8  dec rax
00004384  48 89 05 bd b5 01 00  mov qword ptr [rip + 0x1b5bd], rax
0000438b  48 8b 05 8e b5 01 00  mov rax, qword ptr [rip + 0x1b58e]
00004392  49 8b 84 c6 40 01 00 00  mov rax, qword ptr [r14 + rax*8 + 0x140]
0000439a  48 89 05 77 b5 01 00  mov qword ptr [rip + 0x1b577], rax
000043a1  48 89 d9  mov rcx, rbx
000043a4  e8 ab cf 00 00  call 0x180011354
000043a9  48 ff c8  dec rax
000043ac  48 89 05 9d b5 01 00  mov qword ptr [rip + 0x1b59d], rax
000043b3  48 8b 05 66 b5 01 00  mov rax, qword ptr [rip + 0x1b566]
000043ba  49 8b 84 c6 50 01 00 00  mov rax, qword ptr [r14 + rax*8 + 0x150]
000043c2  48 89 05 4f b5 01 00  mov qword ptr [rip + 0x1b54f], rax
000043c9  48 8d 0d 48 b5 01 00  lea rcx, [rip + 0x1b548]
000043d0  e8 7f cf 00 00  call 0x180011354
000043d5  48 ff c8  dec rax
000043d8  48 89 05 79 b5 01 00  mov qword ptr [rip + 0x1b579], rax
000043df  48 83 7e 08 00  cmp qword ptr [rsi + 8], 0
000043e4  7e 33  jle 0x180004419
000043e6  48 8b 05 33 b5 01 00  mov rax, qword ptr [rip + 0x1b533]
000043ed  48 8b 0d 04 11 01 00  mov rcx, qword ptr [rip + 0x11104]
000043f4  48 8b 84 c1 48 01 00 00  mov rax, qword ptr [rcx + rax*8 + 0x148]
000043fc  48 89 05 15 b5 01 00  mov qword ptr [rip + 0x1b515], rax
00004403  48 8d 0d 0e b5 01 00  lea rcx, [rip + 0x1b50e]
0000440a  e8 45 cf 00 00  call 0x180011354
0000440f  48 ff c8  dec rax
00004412  48 89 05 47 b5 01 00  mov qword ptr [rip + 0x1b547], rax
00004419  48 83 7e 18 00  cmp qword ptr [rsi + 0x18], 0
0000441e  7e 5e  jle 0x18000447e
00004420  48 8b 05 f9 b4 01 00  mov rax, qword ptr [rip + 0x1b4f9]
00004427  48 8b 35 ca 10 01 00  mov rsi, qword ptr [rip + 0x110ca]
0000442e  48 8b 84 c6 58 01 00 00  mov rax, qword ptr [rsi + rax*8 + 0x158]
00004436  48 89 05 db b4 01 00  mov qword ptr [rip + 0x1b4db], rax
0000443d  48 8d 1d d4 b4 01 00  lea rbx, [rip + 0x1b4d4]
00004444  48 89 d9  mov rcx, rbx
00004447  e8 08 cf 00 00  call 0x180011354
0000444c  48 ff c8  dec rax
0000444f  48 89 05 12 b5 01 00  mov qword ptr [rip + 0x1b512], rax
00004456  48 8b 05 c3 b4 01 00  mov rax, qword ptr [rip + 0x1b4c3]
0000445d  48 8b 84 c6 70 01 00 00  mov rax, qword ptr [rsi + rax*8 + 0x170]
00004465  48 89 05 ac b4 01 00  mov qword ptr [rip + 0x1b4ac], rax
0000446c  48 89 d9  mov rcx, rbx
0000446f  e8 e0 ce 00 00  call 0x180011354
00004474  48 ff c8  dec rax
00004477  48 89 05 f2 b4 01 00  mov qword ptr [rip + 0x1b4f2], rax
0000447e  48 c7 05 87 b4 01 00 ff ff ff ff  mov qword ptr [rip + 0x1b487], 0xffffffffffffffff
00004489  48 c7 05 94 b4 01 00 01 00 00 00  mov qword ptr [rip + 0x1b494], 1
00004494  48 8d 35 45 9f 01 00  lea rsi, [rip + 0x19f45]
0000449b  48 8d 1d 5e b4 01 00  lea rbx, [rip + 0x1b45e]
000044a2  4c 8d 3d 0f 32 01 00  lea r15, [rip + 0x1320f]
000044a9  4c 8b 35 28 10 01 00  mov r14, qword ptr [rip + 0x11028]
000044b0  49 8d 6e 38  lea rbp, [r14 + 0x38]
000044b4  49 83 c6 28  add r14, 0x28
000044b8  4c 8d 25 09 32 01 00  lea r12, [rip + 0x13209]
000044bf  4c 8d ac 24 b8 00 00 00  lea r13, [rsp + 0xb8]
000044c7  eb 30  jmp 0x1800044f9
000044d0  e8 3b d6 00 00  call 0x180011b10
000044d5  4c 89 e1  mov rcx, r12
000044d8  e8 d7 ce 00 00  call 0x1800113b4
000044dd  48 8b 0d 44 b4 01 00  mov rcx, qword ptr [rip + 0x1b444]
000044e4  48 8d 41 01  lea rax, [rcx + 1]
000044e8  48 89 05 39 b4 01 00  mov qword ptr [rip + 0x1b439], rax
000044ef  48 83 f9 07  cmp rcx, 7
000044f3  0f 8d 44 02 00 00  jge 0x18000473d
000044f9  48 8b 05 10 b4 01 00  mov rax, qword ptr [rip + 0x1b410]
00004500  48 8d 48 02  lea rcx, [rax + 2]
00004504  48 89 0d 05 b4 01 00  mov qword ptr [rip + 0x1b405], rcx
0000450b  48 8d 0c c6  lea rcx, [rsi + rax*8]
0000450f  48 83 c1 08  add rcx, 8
00004513  48 89 da  mov rdx, rbx
00004516  e8 c9 ce 00 00  call 0x1800113e4
0000451b  48 89 05 e6 b3 01 00  mov qword ptr [rip + 0x1b3e6], rax
00004522  48 83 f8 07  cmp rax, 7
00004526  0f 8e 14 01 00 00  jle 0x180004640
0000452c  48 8d 05 8d 31 01 00  lea rax, [rip + 0x1318d]
00004533  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00004538  4c 89 7c 24 30  mov qword ptr [rsp + 0x30], r15
0000453d  4c 89 7c 24 28  mov qword ptr [rsp + 0x28], r15
00004542  48 89 6c 24 20  mov qword ptr [rsp + 0x20], rbp
00004547  48 8d 0d 72 9e 01 00  lea rcx, [rip + 0x19e72]
0000454e  4c 89 e2  mov rdx, r12
00004551  4d 89 e0  mov r8, r12
00004554  4d 89 f1  mov r9, r14
00004557  e8 4c ce 00 00  call 0x1800113a8
0000455c  48 85 c0  test rax, rax
0000455f  0f 84 78 ff ff ff  je 0x1800044dd
00004565  48 8b 05 a4 b3 01 00  mov rax, qword ptr [rip + 0x1b3a4]
0000456c  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
00004571  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
0000457d  c7 44 24 5a 38 06 0b 01  mov dword ptr [rsp + 0x5a], 0x10b0638
00004585  66 c7 44 24 5e 02 00  mov word ptr [rsp + 0x5e], 2
0000458c  48 c7 84 24 98 00 00 00 20 03 00 00  mov qword ptr [rsp + 0x98], 0x320
00004598  48 8b 0d f1 0e 01 00  mov rcx, qword ptr [rip + 0x10ef1]
0000459f  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
000045a7  48 c7 84 24 a8 00 00 00 50 00 00 00  mov qword ptr [rsp + 0xa8], 0x50
000045b3  48 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], rax
000045bb  48 8d 05 de 9e 01 00  lea rax, [rip + 0x19ede]
000045c2  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000045c7  4c 89 e9  mov rcx, r13
000045ca  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
000045d4  4c 8d 44 24 5a  lea r8, [rsp + 0x5a]
000045d9  4c 8d 8c 24 98 00 00 00  lea r9, [rsp + 0x98]
000045e1  e8 24 d5 00 00  call 0x180011b0a
000045e6  48 8b 05 23 b3 01 00  mov rax, qword ptr [rip + 0x1b323]
000045ed  48 8b 04 c6  mov rax, qword ptr [rsi + rax*8]
000045f1  c7 44 24 56 0b 01 02 00  mov dword ptr [rsp + 0x56], 0x2010b
000045f9  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
000045fe  4c 89 e9  mov rcx, r13
00004601  48 8d 54 24 56  lea rdx, [rsp + 0x56]
00004606  4c 8d 44 24 70  lea r8, [rsp + 0x70]
0000460b  e8 00 d5 00 00  call 0x180011b10
00004610  48 8b 05 f1 b2 01 00  mov rax, qword ptr [rip + 0x1b2f1]
00004617  c7 44 24 52 0b 01 01 00  mov dword ptr [rsp + 0x52], 0x1010b
0000461f  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
00004624  4c 89 e9  mov rcx, r13
00004627  48 8d 54 24 52  lea rdx, [rsp + 0x52]
0000462c  4c 8d 44 24 68  lea r8, [rsp + 0x68]
00004631  e9 9a fe ff ff  jmp 0x1800044d0
00004640  48 85 c0  test rax, rax
00004643  74 1d  je 0x180004662
00004645  48 8b 0d dc b2 01 00  mov rcx, qword ptr [rip + 0x1b2dc]
0000464c  48 8d 15 ed b2 01 00  lea rdx, [rip + 0x1b2ed]
00004653  48 8b 54 ca f8  mov rdx, qword ptr [rdx + rcx*8 - 8]
00004658  48 89 54 c7 f8  mov qword ptr [rdi + rax*8 - 8], rdx
0000465d  e9 82 fe ff ff  jmp 0x1800044e4
00004662  4c 8d 05 57 30 01 00  lea r8, [rip + 0x13057]
00004669  4c 89 44 24 38  mov qword ptr [rsp + 0x38], r8
0000466e  4c 89 7c 24 30  mov qword ptr [rsp + 0x30], r15
00004673  4c 89 7c 24 28  mov qword ptr [rsp + 0x28], r15
00004678  48 89 6c 24 20  mov qword ptr [rsp + 0x20], rbp
0000467d  48 8d 0d 3c 9d 01 00  lea rcx, [rip + 0x19d3c]
00004684  4c 89 e2  mov rdx, r12
00004687  4d 89 f1  mov r9, r14
0000468a  e8 19 cd 00 00  call 0x1800113a8
0000468f  48 85 c0  test rax, rax
00004692  0f 84 45 fe ff ff  je 0x1800044dd
00004698  48 8b 05 71 b2 01 00  mov rax, qword ptr [rip + 0x1b271]
0000469f  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
000046a4  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
000046b0  c7 44 24 4c 38 06 0b 01  mov dword ptr [rsp + 0x4c], 0x10b0638
000046b8  66 c7 44 24 50 02 00  mov word ptr [rsp + 0x50], 2
000046bf  48 c7 44 24 78 20 03 00 00  mov qword ptr [rsp + 0x78], 0x320
000046c8  48 8b 0d c1 0d 01 00  mov rcx, qword ptr [rip + 0x10dc1]
000046cf  48 89 8c 24 80 00 00 00  mov qword ptr [rsp + 0x80], rcx
000046d7  48 c7 84 24 88 00 00 00 50 00 00 00  mov qword ptr [rsp + 0x88], 0x50
000046e3  48 89 84 24 90 00 00 00  mov qword ptr [rsp + 0x90], rax
000046eb  48 8d 05 5e 9d 01 00  lea rax, [rip + 0x19d5e]
000046f2  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000046f7  4c 89 e9  mov rcx, r13
000046fa  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
00004704  4c 8d 44 24 4c  lea r8, [rsp + 0x4c]
00004709  4c 8d 4c 24 78  lea r9, [rsp + 0x78]
0000470e  e8 f7 d3 00 00  call 0x180011b0a
00004713  48 8b 05 f6 b1 01 00  mov rax, qword ptr [rip + 0x1b1f6]
0000471a  48 8b 04 c6  mov rax, qword ptr [rsi + rax*8]
0000471e  c7 44 24 48 0b 01 01 00  mov dword ptr [rsp + 0x48], 0x1010b
00004726  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
0000472b  4c 89 e9  mov rcx, r13
0000472e  48 8d 54 24 48  lea rdx, [rsp + 0x48]
00004733  4c 8d 44 24 60  lea r8, [rsp + 0x60]
00004738  e9 93 fd ff ff  jmp 0x1800044d0
0000473d  48 81 c4 e8 00 00 00  add rsp, 0xe8
00004744  5b  pop rbx
00004745  5d  pop rbp
00004746  5f  pop rdi
00004747  5e  pop rsi
00004748  41 5c  pop r12
0000474a  41 5d  pop r13
0000474c  41 5e  pop r14
0000474e  41 5f  pop r15
00004750  c3  ret
; owner 0x4760 PPEXEC_PHCTAB
00004760  41 57  push r15
00004762  41 56  push r14
00004764  41 55  push r13
00004766  41 54  push r12
00004768  56  push rsi
00004769  57  push rdi
0000476a  55  push rbp
0000476b  53  push rbx
0000476c  48 81 ec e8 00 00 00  sub rsp, 0xe8
00004773  31 c0  xor eax, eax
00004775  48 8d 2d 84 b2 01 00  lea rbp, [rip + 0x1b284]
0000477c  48 8b 3d 6d 0c 01 00  mov rdi, qword ptr [rip + 0x10c6d]
00004783  66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00004790  48 c7 04 28 00 00 00 00  mov qword ptr [rax + rbp], 0
00004798  48 c7 04 07 00 00 00 00  mov qword ptr [rdi + rax], 0
000047a0  48 83 c0 08  add rax, 8
000047a4  48 83 f8 20  cmp rax, 0x20
000047a8  75 e6  jne 0x180004790
000047aa  48 c7 05 43 b2 01 00 05 00 00 00  mov qword ptr [rip + 0x1b243], 5
000047b5  48 8d 0d 1c 2f 01 00  lea rcx, [rip + 0x12f1c]
000047bc  e8 93 cb 00 00  call 0x180011354
000047c1  48 8b 35 30 0d 01 00  mov rsi, qword ptr [rip + 0x10d30]
000047c8  48 8b 84 c6 c8 03 00 00  mov rax, qword ptr [rsi + rax*8 + 0x3c8]
000047d0  48 89 05 19 b2 01 00  mov qword ptr [rip + 0x1b219], rax
000047d7  48 85 c0  test rax, rax
000047da  0f 84 66 04 00 00  je 0x180004c46
000047e0  48 8d 0d 09 b2 01 00  lea rcx, [rip + 0x1b209]
000047e7  e8 68 cb 00 00  call 0x180011354
000047ec  48 83 7c c6 f8 01  cmp qword ptr [rsi + rax*8 - 8], 1
000047f2  0f 85 4e 04 00 00  jne 0x180004c46
000047f8  48 8b 4c c6 08  mov rcx, qword ptr [rsi + rax*8 + 8]
000047fd  48 8b 54 c6 10  mov rdx, qword ptr [rsi + rax*8 + 0x10]
00004802  48 89 0d 7f b1 01 00  mov qword ptr [rip + 0x1b17f], rcx
00004809  48 89 15 d8 b1 01 00  mov qword ptr [rip + 0x1b1d8], rdx
00004810  48 8b 4c c6 18  mov rcx, qword ptr [rsi + rax*8 + 0x18]
00004815  48 89 0d c4 b1 01 00  mov qword ptr [rip + 0x1b1c4], rcx
0000481c  48 8d 0d bd b1 01 00  lea rcx, [rip + 0x1b1bd]
00004823  48 8b 54 c6 28  mov rdx, qword ptr [rsi + rax*8 + 0x28]
00004828  48 89 15 a9 b1 01 00  mov qword ptr [rip + 0x1b1a9], rdx
0000482f  48 8b 54 c6 40  mov rdx, qword ptr [rsi + rax*8 + 0x40]
00004834  48 89 15 45 b1 01 00  mov qword ptr [rip + 0x1b145], rdx
0000483b  48 8b 54 c6 68  mov rdx, qword ptr [rsi + rax*8 + 0x68]
00004840  48 89 15 89 b1 01 00  mov qword ptr [rip + 0x1b189], rdx
00004847  48 8b 44 c6 70  mov rax, qword ptr [rsi + rax*8 + 0x70]
0000484c  48 89 05 75 b1 01 00  mov qword ptr [rip + 0x1b175], rax
00004853  e8 fc ca 00 00  call 0x180011354
00004858  48 8b 0d 91 0c 01 00  mov rcx, qword ptr [rip + 0x10c91]
0000485f  48 8b 11  mov rdx, qword ptr [rcx]
00004862  48 8b 49 08  mov rcx, qword ptr [rcx + 8]
00004866  48 39 ca  cmp rdx, rcx
00004869  48 0f 4f ca  cmovg rcx, rdx
0000486d  48 0f af 4c c6 f8  imul rcx, qword ptr [rsi + rax*8 - 8]
00004873  48 8d 04 89  lea rax, [rcx + rcx*4]
00004877  48 85 c0  test rax, rax
0000487a  0f 94 c0  sete al
0000487d  48 83 3d 03 b1 01 00 00  cmp qword ptr [rip + 0x1b103], 0
00004885  0f 94 c1  sete cl
00004888  08 c1  or cl, al
0000488a  75 16  jne 0x1800048a2
0000488c  48 8d 0d 45 b1 01 00  lea rcx, [rip + 0x1b145]
00004893  e8 bc ca 00 00  call 0x180011354
00004898  48 ff c8  dec rax
0000489b  48 89 05 5e b1 01 00  mov qword ptr [rip + 0x1b15e], rax
000048a2  48 83 3d 26 b1 01 00 00  cmp qword ptr [rip + 0x1b126], 0
000048aa  7e 16  jle 0x1800048c2
000048ac  48 8d 0d 1d b1 01 00  lea rcx, [rip + 0x1b11d]
000048b3  e8 9c ca 00 00  call 0x180011354
000048b8  48 ff c8  dec rax
000048bb  48 89 05 46 b1 01 00  mov qword ptr [rip + 0x1b146], rax
000048c2  48 83 3d fe b0 01 00 00  cmp qword ptr [rip + 0x1b0fe], 0
000048ca  7e 16  jle 0x1800048e2
000048cc  48 8d 0d f5 b0 01 00  lea rcx, [rip + 0x1b0f5]
000048d3  e8 30 cb 00 00  call 0x180011408
000048d8  48 ff c8  dec rax
000048db  48 89 05 2e b1 01 00  mov qword ptr [rip + 0x1b12e], rax
000048e2  48 83 3d 96 b0 01 00 00  cmp qword ptr [rip + 0x1b096], 0
000048ea  0f 84 a8 00 00 00  je 0x180004998
000048f0  48 8d 1d f1 b0 01 00  lea rbx, [rip + 0x1b0f1]
000048f7  48 89 d9  mov rcx, rbx
000048fa  e8 2d cb 00 00  call 0x18001142c
000048ff  48 89 05 ba b0 01 00  mov qword ptr [rip + 0x1b0ba], rax
00004906  48 89 d9  mov rcx, rbx
00004909  e8 fa ca 00 00  call 0x180011408
0000490e  48 89 05 a3 b0 01 00  mov qword ptr [rip + 0x1b0a3], rax
00004915  48 83 3d 43 d7 01 00 00  cmp qword ptr [rip + 0x1d743], 0
0000491d  74 17  je 0x180004936
0000491f  48 8d 0d 3a d7 01 00  lea rcx, [rip + 0x1d73a]
00004926  e8 07 cb 00 00  call 0x180011432
0000492b  48 c7 05 2a d7 01 00 00 00 00 00  mov qword ptr [rip + 0x1d72a], 0
00004936  48 8d 1d 83 b0 01 00  lea rbx, [rip + 0x1b083]
0000493d  48 8d 15 6c b0 01 00  lea rdx, [rip + 0x1b06c]
00004944  4c 8d 05 5d b0 01 00  lea r8, [rip + 0x1b05d]
0000494b  48 89 d9  mov rcx, rbx
0000494e  e8 e5 ca 00 00  call 0x180011438
00004953  48 8b 05 5e b0 01 00  mov rax, qword ptr [rip + 0x1b05e]
0000495a  48 8d 0c c6  lea rcx, [rsi + rax*8]
0000495e  48 83 c1 f8  add rcx, -8
00004962  48 8b 05 3f b0 01 00  mov rax, qword ptr [rip + 0x1b03f]
00004969  48 8d 14 c6  lea rdx, [rsi + rax*8]
0000496d  48 83 c2 f8  add rdx, -8
00004971  49 89 d8  mov r8, rbx
00004974  e8 c5 ca 00 00  call 0x18001143e
00004979  48 8b 05 28 b0 01 00  mov rax, qword ptr [rip + 0x1b028]
00004980  48 ff c8  dec rax
00004983  48 89 05 8e b0 01 00  mov qword ptr [rip + 0x1b08e], rax
0000498a  48 8b 05 1f b0 01 00  mov rax, qword ptr [rip + 0x1b01f]
00004991  48 89 05 c8 d6 01 00  mov qword ptr [rip + 0x1d6c8], rax
00004998  48 c7 05 fd af 01 00 ff ff ff ff  mov qword ptr [rip + 0x1affd], 0xffffffffffffffff
000049a3  48 c7 05 4a b0 01 00 01 00 00 00  mov qword ptr [rip + 0x1b04a], 1
000049ae  48 8d 35 6b 9b 01 00  lea rsi, [rip + 0x19b6b]
000049b5  4c 8d 3d 14 2d 01 00  lea r15, [rip + 0x12d14]
000049bc  4c 8b 35 15 0b 01 00  mov r14, qword ptr [rip + 0x10b15]
000049c3  49 8d 5e 38  lea rbx, [r14 + 0x38]
000049c7  49 83 c6 28  add r14, 0x28
000049cb  4c 8d 25 0e 2d 01 00  lea r12, [rip + 0x12d0e]
000049d2  4c 8d ac 24 b8 00 00 00  lea r13, [rsp + 0xb8]
000049da  eb 2d  jmp 0x180004a09
000049e0  e8 2b d1 00 00  call 0x180011b10
000049e5  4c 89 e1  mov rcx, r12
000049e8  e8 c7 c9 00 00  call 0x1800113b4
000049ed  48 8b 0d 04 b0 01 00  mov rcx, qword ptr [rip + 0x1b004]
000049f4  48 8d 41 01  lea rax, [rcx + 1]
000049f8  48 89 05 f9 af 01 00  mov qword ptr [rip + 0x1aff9], rax
000049ff  48 83 f9 04  cmp rcx, 4
00004a03  0f 8d 3d 02 00 00  jge 0x180004c46
00004a09  48 8b 05 90 af 01 00  mov rax, qword ptr [rip + 0x1af90]
00004a10  48 8d 48 02  lea rcx, [rax + 2]
00004a14  48 89 0d 85 af 01 00  mov qword ptr [rip + 0x1af85], rcx
00004a1b  48 8d 0c c6  lea rcx, [rsi + rax*8]
00004a1f  48 83 c1 08  add rcx, 8
00004a23  48 8d 15 66 af 01 00  lea rdx, [rip + 0x1af66]
00004a2a  e8 b5 c9 00 00  call 0x1800113e4
00004a2f  48 89 05 62 af 01 00  mov qword ptr [rip + 0x1af62], rax
00004a36  48 83 f8 04  cmp rax, 4
00004a3a  0f 8e 10 01 00 00  jle 0x180004b50
00004a40  48 8d 05 91 2c 01 00  lea rax, [rip + 0x12c91]
00004a47  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00004a4c  4c 89 7c 24 30  mov qword ptr [rsp + 0x30], r15
00004a51  4c 89 7c 24 28  mov qword ptr [rsp + 0x28], r15
00004a56  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
00004a5b  48 8d 0d 9e 9a 01 00  lea rcx, [rip + 0x19a9e]
00004a62  4c 89 e2  mov rdx, r12
00004a65  4d 89 e0  mov r8, r12
00004a68  4d 89 f1  mov r9, r14
00004a6b  e8 38 c9 00 00  call 0x1800113a8
00004a70  48 85 c0  test rax, rax
00004a73  0f 84 74 ff ff ff  je 0x1800049ed
00004a79  48 8b 05 20 af 01 00  mov rax, qword ptr [rip + 0x1af20]
00004a80  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
00004a85  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
00004a91  c7 44 24 5a 38 06 0b 01  mov dword ptr [rsp + 0x5a], 0x10b0638
00004a99  66 c7 44 24 5e 02 00  mov word ptr [rsp + 0x5e], 2
00004aa0  48 c7 84 24 98 00 00 00 20 03 00 00  mov qword ptr [rsp + 0x98], 0x320
00004aac  48 8b 0d dd 09 01 00  mov rcx, qword ptr [rip + 0x109dd]
00004ab3  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
00004abb  48 c7 84 24 a8 00 00 00 50 00 00 00  mov qword ptr [rsp + 0xa8], 0x50
00004ac7  48 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], rax
00004acf  48 8d 05 da 9a 01 00  lea rax, [rip + 0x19ada]
00004ad6  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00004adb  4c 89 e9  mov rcx, r13
00004ade  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
00004ae8  4c 8d 44 24 5a  lea r8, [rsp + 0x5a]
00004aed  4c 8d 8c 24 98 00 00 00  lea r9, [rsp + 0x98]
00004af5  e8 10 d0 00 00  call 0x180011b0a
00004afa  48 8b 05 9f ae 01 00  mov rax, qword ptr [rip + 0x1ae9f]
00004b01  48 8b 04 c6  mov rax, qword ptr [rsi + rax*8]
00004b05  c7 44 24 56 0b 01 02 00  mov dword ptr [rsp + 0x56], 0x2010b
00004b0d  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
00004b12  4c 89 e9  mov rcx, r13
00004b15  48 8d 54 24 56  lea rdx, [rsp + 0x56]
00004b1a  4c 8d 44 24 70  lea r8, [rsp + 0x70]
00004b1f  e8 ec cf 00 00  call 0x180011b10
00004b24  48 8b 05 6d ae 01 00  mov rax, qword ptr [rip + 0x1ae6d]
00004b2b  c7 44 24 52 0b 01 01 00  mov dword ptr [rsp + 0x52], 0x1010b
00004b33  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
00004b38  4c 89 e9  mov rcx, r13
00004b3b  48 8d 54 24 52  lea rdx, [rsp + 0x52]
00004b40  4c 8d 44 24 68  lea r8, [rsp + 0x68]
00004b45  e9 96 fe ff ff  jmp 0x1800049e0
00004b50  48 85 c0  test rax, rax
00004b53  74 16  je 0x180004b6b
00004b55  48 8b 0d 9c ae 01 00  mov rcx, qword ptr [rip + 0x1ae9c]
00004b5c  48 8b 54 cd f8  mov rdx, qword ptr [rbp + rcx*8 - 8]
00004b61  48 89 54 c7 f8  mov qword ptr [rdi + rax*8 - 8], rdx
00004b66  e9 89 fe ff ff  jmp 0x1800049f4
00004b6b  4c 8d 05 66 2b 01 00  lea r8, [rip + 0x12b66]
00004b72  4c 89 44 24 38  mov qword ptr [rsp + 0x38], r8
00004b77  4c 89 7c 24 30  mov qword ptr [rsp + 0x30], r15
00004b7c  4c 89 7c 24 28  mov qword ptr [rsp + 0x28], r15
00004b81  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
00004b86  48 8d 0d 73 99 01 00  lea rcx, [rip + 0x19973]
00004b8d  4c 89 e2  mov rdx, r12
00004b90  4d 89 f1  mov r9, r14
00004b93  e8 10 c8 00 00  call 0x1800113a8
00004b98  48 85 c0  test rax, rax
00004b9b  0f 84 4c fe ff ff  je 0x1800049ed
00004ba1  48 8b 05 f8 ad 01 00  mov rax, qword ptr [rip + 0x1adf8]
00004ba8  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
00004bad  48 c7 84 24 b8 00 00 00 00 00 00 00  mov qword ptr [rsp + 0xb8], 0
00004bb9  c7 44 24 4c 38 06 0b 01  mov dword ptr [rsp + 0x4c], 0x10b0638
00004bc1  66 c7 44 24 50 02 00  mov word ptr [rsp + 0x50], 2
00004bc8  48 c7 44 24 78 20 03 00 00  mov qword ptr [rsp + 0x78], 0x320
00004bd1  48 8b 0d b8 08 01 00  mov rcx, qword ptr [rip + 0x108b8]
00004bd8  48 89 8c 24 80 00 00 00  mov qword ptr [rsp + 0x80], rcx
00004be0  48 c7 84 24 88 00 00 00 50 00 00 00  mov qword ptr [rsp + 0x88], 0x50
00004bec  48 89 84 24 90 00 00 00  mov qword ptr [rsp + 0x90], rax
00004bf4  48 8d 05 65 99 01 00  lea rax, [rip + 0x19965]
00004bfb  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00004c00  4c 89 e9  mov rcx, r13
00004c03  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
00004c0d  4c 8d 44 24 4c  lea r8, [rsp + 0x4c]
00004c12  4c 8d 4c 24 78  lea r9, [rsp + 0x78]
00004c17  e8 ee ce 00 00  call 0x180011b0a
00004c1c  48 8b 05 7d ad 01 00  mov rax, qword ptr [rip + 0x1ad7d]
00004c23  48 8b 04 c6  mov rax, qword ptr [rsi + rax*8]
00004c27  c7 44 24 48 0b 01 01 00  mov dword ptr [rsp + 0x48], 0x1010b
00004c2f  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
00004c34  4c 89 e9  mov rcx, r13
00004c37  48 8d 54 24 48  lea rdx, [rsp + 0x48]
00004c3c  4c 8d 44 24 60  lea r8, [rsp + 0x60]
00004c41  e9 9a fd ff ff  jmp 0x1800049e0
00004c46  48 81 c4 e8 00 00 00  add rsp, 0xe8
00004c4d  5b  pop rbx
00004c4e  5d  pop rbp
00004c4f  5f  pop rdi
00004c50  5e  pop rsi
00004c51  41 5c  pop r12
00004c53  41 5d  pop r13
00004c55  41 5e  pop r14
00004c57  41 5f  pop r15
00004c59  c3  ret
; owner 0x4c60 runtime_4c60
00004c60  56  push rsi
00004c61  48 8b 01  mov rax, qword ptr [rcx]
00004c64  48 a9 fd ff ff ff  test rax, -3
00004c6a  0f 85 9b 00 00 00  jne 0x180004d0b
00004c70  48 8b 0d c9 d4 01 00  mov rcx, qword ptr [rip + 0x1d4c9]
00004c77  48 89 0d c2 d3 01 00  mov qword ptr [rip + 0x1d3c2], rcx
00004c7e  0f 28 05 ab d4 01 00  movaps xmm0, xmmword ptr [rip + 0x1d4ab]
00004c85  0f 29 05 a4 d3 01 00  movaps xmmword ptr [rip + 0x1d3a4], xmm0
00004c8c  0f 28 05 8d d4 01 00  movaps xmm0, xmmword ptr [rip + 0x1d48d]
00004c93  0f 29 05 86 d3 01 00  movaps xmmword ptr [rip + 0x1d386], xmm0
00004c9a  0f 28 05 6f d4 01 00  movaps xmm0, xmmword ptr [rip + 0x1d46f]
00004ca1  0f 29 05 68 d3 01 00  movaps xmmword ptr [rip + 0x1d368], xmm0
00004ca8  0f 28 05 51 d4 01 00  movaps xmm0, xmmword ptr [rip + 0x1d451]
00004caf  0f 29 05 4a d3 01 00  movaps xmmword ptr [rip + 0x1d34a], xmm0
00004cb6  0f 28 05 33 d4 01 00  movaps xmm0, xmmword ptr [rip + 0x1d433]
00004cbd  0f 29 05 2c d3 01 00  movaps xmmword ptr [rip + 0x1d32c], xmm0
00004cc4  0f 28 05 15 d4 01 00  movaps xmm0, xmmword ptr [rip + 0x1d415]
00004ccb  0f 29 05 0e d3 01 00  movaps xmmword ptr [rip + 0x1d30e], xmm0
00004cd2  31 c9  xor ecx, ecx
00004cd4  4c 8d 15 a5 d3 01 00  lea r10, [rip + 0x1d3a5]
00004cdb  4c 8d 1d 3e ad 01 00  lea r11, [rip + 0x1ad3e]
00004ce2  66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00004cf0  f2 42 0f 10 04 11  movsd xmm0, qword ptr [rcx + r10]
00004cf6  f2 42 0f 11 04 19  movsd qword ptr [rcx + r11], xmm0
00004cfc  48 83 c1 08  add rcx, 8
00004d00  48 83 f9 50  cmp rcx, 0x50
00004d04  75 ea  jne 0x180004cf0
00004d06  48 85 c0  test rax, rax
00004d09  74 7e  je 0x180004d89
00004d0b  48 8b 44 24 30  mov rax, qword ptr [rsp + 0x30]
00004d10  48 8b 0a  mov rcx, qword ptr [rdx]
00004d13  48 85 c9  test rcx, rcx
00004d16  7e 2d  jle 0x180004d45
00004d18  31 d2  xor edx, edx
00004d1a  4c 8d 15 bf d2 01 00  lea r10, [rip + 0x1d2bf]
00004d21  66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00004d30  4d 8b 1c d1  mov r11, qword ptr [r9 + rdx*8]
00004d34  49 8b 34 d0  mov rsi, qword ptr [r8 + rdx*8]
00004d38  4d 89 5c f2 10  mov qword ptr [r10 + rsi*8 + 0x10], r11
00004d3d  48 ff c2  inc rdx
00004d40  48 39 ca  cmp rdx, rcx
00004d43  7c eb  jl 0x180004d30
00004d45  48 8b 00  mov rax, qword ptr [rax]
00004d48  48 85 c0  test rax, rax
00004d4b  7e 3c  jle 0x180004d89
00004d4d  48 8b 4c 24 40  mov rcx, qword ptr [rsp + 0x40]
00004d52  48 8b 54 24 38  mov rdx, qword ptr [rsp + 0x38]
00004d57  45 31 c0  xor r8d, r8d
00004d5a  4c 8d 0d bf ac 01 00  lea r9, [rip + 0x1acbf]
00004d61  66 66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00004d70  f2 42 0f 10 04 c1  movsd xmm0, qword ptr [rcx + r8*8]
00004d76  4e 8b 14 c2  mov r10, qword ptr [rdx + r8*8]
00004d7a  f2 43 0f 11 44 d1 f8  movsd qword ptr [r9 + r10*8 - 8], xmm0
00004d81  49 ff c0  inc r8
00004d84  49 39 c0  cmp r8, rax
00004d87  7c e7  jl 0x180004d70
00004d89  5e  pop rsi
00004d8a  c3  ret
; owner 0x4d90 PPEXEC_PPSLAVE3
00004d90  41 57  push r15
00004d92  41 56  push r14
00004d94  41 55  push r13
00004d96  41 54  push r12
00004d98  56  push rsi
00004d99  57  push rdi
00004d9a  55  push rbp
00004d9b  53  push rbx
00004d9c  48 83 ec 78  sub rsp, 0x78
00004da0  4d 89 ca  mov r10, r9
00004da3  4c 89 c3  mov rbx, r8
00004da6  48 89 cf  mov rdi, rcx
00004da9  48 8b 84 24 00 01 00 00  mov rax, qword ptr [rsp + 0x100]
00004db1  48 8b 8c 24 f8 00 00 00  mov rcx, qword ptr [rsp + 0xf8]
00004db9  48 c7 05 ac ae 01 00 00 00 00 00  mov qword ptr [rip + 0x1aeac], 0
00004dc4  0f 28 05 25 29 01 00  movaps xmm0, xmmword ptr [rip + 0x12925]
00004dcb  0f 11 05 9d ad 01 00  movups xmmword ptr [rip + 0x1ad9d], xmm0
00004dd2  0f 11 05 a6 ad 01 00  movups xmmword ptr [rip + 0x1ada6], xmm0
00004dd9  0f 11 05 af ad 01 00  movups xmmword ptr [rip + 0x1adaf], xmm0
00004de0  0f 11 05 b8 ad 01 00  movups xmmword ptr [rip + 0x1adb8], xmm0
00004de7  0f 11 05 c1 ad 01 00  movups xmmword ptr [rip + 0x1adc1], xmm0
00004dee  0f 11 05 ca ad 01 00  movups xmmword ptr [rip + 0x1adca], xmm0
00004df5  0f 11 05 d3 ad 01 00  movups xmmword ptr [rip + 0x1add3], xmm0
00004dfc  0f 11 05 dc ad 01 00  movups xmmword ptr [rip + 0x1addc], xmm0
00004e03  0f 11 05 e5 ad 01 00  movups xmmword ptr [rip + 0x1ade5], xmm0
00004e0a  0f 11 05 ee ad 01 00  movups xmmword ptr [rip + 0x1adee], xmm0
00004e11  0f 11 05 f7 ad 01 00  movups xmmword ptr [rip + 0x1adf7], xmm0
00004e18  0f 11 05 00 ae 01 00  movups xmmword ptr [rip + 0x1ae00], xmm0
00004e1f  0f 11 05 09 ae 01 00  movups xmmword ptr [rip + 0x1ae09], xmm0
00004e26  0f 11 05 12 ae 01 00  movups xmmword ptr [rip + 0x1ae12], xmm0
00004e2d  0f 11 05 1b ae 01 00  movups xmmword ptr [rip + 0x1ae1b], xmm0
00004e34  0f 11 05 23 ae 01 00  movups xmmword ptr [rip + 0x1ae23], xmm0
00004e3b  0f 11 05 2e ac 01 00  movups xmmword ptr [rip + 0x1ac2e], xmm0
00004e42  0f 11 05 37 ac 01 00  movups xmmword ptr [rip + 0x1ac37], xmm0
00004e49  0f 11 05 40 ac 01 00  movups xmmword ptr [rip + 0x1ac40], xmm0
00004e50  0f 11 05 49 ac 01 00  movups xmmword ptr [rip + 0x1ac49], xmm0
00004e57  0f 11 05 52 ac 01 00  movups xmmword ptr [rip + 0x1ac52], xmm0
00004e5e  0f 11 05 5b ac 01 00  movups xmmword ptr [rip + 0x1ac5b], xmm0
00004e65  0f 11 05 64 ac 01 00  movups xmmword ptr [rip + 0x1ac64], xmm0
00004e6c  0f 11 05 6d ac 01 00  movups xmmword ptr [rip + 0x1ac6d], xmm0
00004e73  0f 11 05 76 ac 01 00  movups xmmword ptr [rip + 0x1ac76], xmm0
00004e7a  0f 11 05 7f ac 01 00  movups xmmword ptr [rip + 0x1ac7f], xmm0
00004e81  0f 11 05 88 ac 01 00  movups xmmword ptr [rip + 0x1ac88], xmm0
00004e88  0f 11 05 91 ac 01 00  movups xmmword ptr [rip + 0x1ac91], xmm0
00004e8f  0f 11 05 9a ac 01 00  movups xmmword ptr [rip + 0x1ac9a], xmm0
00004e96  0f 11 05 a3 ac 01 00  movups xmmword ptr [rip + 0x1aca3], xmm0
00004e9d  0f 11 05 ac ac 01 00  movups xmmword ptr [rip + 0x1acac], xmm0
00004ea4  0f 11 05 b4 ac 01 00  movups xmmword ptr [rip + 0x1acb4], xmm0
00004eab  4c 8b 05 16 05 01 00  mov r8, qword ptr [rip + 0x10516]
00004eb2  49 c7 00 01 00 00 00  mov qword ptr [r8], 1
00004eb9  48 8b 09  mov rcx, qword ptr [rcx]
00004ebc  49 89 48 08  mov qword ptr [r8 + 8], rcx
00004ec0  48 8b 00  mov rax, qword ptr [rax]
00004ec3  49 89 40 10  mov qword ptr [r8 + 0x10], rax
00004ec7  4c 8b 22  mov r12, qword ptr [rdx]
00004eca  4d 85 e4  test r12, r12
00004ecd  0f 89 87 00 00 00  jns 0x180004f5a
00004ed3  ba ff 00 00 00  mov edx, 0xff
00004ed8  48 89 f9  mov rcx, rdi
00004edb  4c 89 d6  mov rsi, r10
00004ede  e8 67 c5 00 00  call 0x18001144a
00004ee3  49 89 c6  mov r14, rax
00004ee6  4c 8d 3d 82 ac 01 00  lea r15, [rip + 0x1ac82]
00004eed  41 b8 ff 00 00 00  mov r8d, 0xff
00004ef3  4c 89 f9  mov rcx, r15
00004ef6  48 89 fa  mov rdx, rdi
00004ef9  e8 22 3e 00 00  call 0x180008d20
00004efe  43 c7 04 3e 2e 68 69 73  mov dword ptr [r14 + r15], 0x7369682e
00004f06  4c 89 e0  mov rax, r12
00004f09  48 f7 d8  neg rax
00004f0c  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
00004f11  48 8d 05 f8 27 01 00  lea rax, [rip + 0x127f8]
00004f18  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00004f1d  48 8d 0d e4 27 01 00  lea rcx, [rip + 0x127e4]
00004f24  48 89 4c 24 30  mov qword ptr [rsp + 0x30], rcx
00004f29  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00004f2e  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00004f33  48 c7 44 24 40 ff 00 00 00  mov qword ptr [rsp + 0x40], 0xff
00004f3c  4c 8d 05 bd 27 01 00  lea r8, [rip + 0x127bd]
00004f43  4c 8d 0d 26 ad 01 00  lea r9, [rip + 0x1ad26]
00004f4a  48 8d 54 24 70  lea rdx, [rsp + 0x70]
00004f4f  4c 89 f9  mov rcx, r15
00004f52  e8 f9 c4 00 00  call 0x180011450
00004f57  49 89 f2  mov r10, rsi
00004f5a  4c 8b bc 24 f0 00 00 00  mov r15, qword ptr [rsp + 0xf0]
00004f62  48 8b b4 24 e8 00 00 00  mov rsi, qword ptr [rsp + 0xe8]
00004f6a  48 8b ac 24 e0 00 00 00  mov rbp, qword ptr [rsp + 0xe0]
00004f72  4c 8b 2b  mov r13, qword ptr [rbx]
00004f75  4d 85 ed  test r13, r13
00004f78  0f 89 8b 00 00 00  jns 0x180005009
00004f7e  ba ff 00 00 00  mov edx, 0xff
00004f83  48 89 f9  mov rcx, rdi
00004f86  4c 89 54 24 50  mov qword ptr [rsp + 0x50], r10
00004f8b  e8 ba c4 00 00  call 0x18001144a
00004f90  48 89 c3  mov rbx, rax
00004f93  4c 8d 35 d6 aa 01 00  lea r14, [rip + 0x1aad6]
00004f9a  41 b8 ff 00 00 00  mov r8d, 0xff
00004fa0  4c 89 f1  mov rcx, r14
00004fa3  48 89 fa  mov rdx, rdi
00004fa6  e8 75 3d 00 00  call 0x180008d20
00004fab  42 c7 04 33 2e 72 65 70  mov dword ptr [rbx + r14], 0x7065722e
00004fb3  4c 89 e8  mov rax, r13
00004fb6  48 f7 d8  neg rax
00004fb9  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
00004fbe  48 8d 05 4b 27 01 00  lea rax, [rip + 0x1274b]
00004fc5  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00004fca  48 8d 0d 37 27 01 00  lea rcx, [rip + 0x12737]
00004fd1  48 89 4c 24 30  mov qword ptr [rsp + 0x30], rcx
00004fd6  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00004fdb  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00004fe0  48 c7 44 24 40 ff 00 00 00  mov qword ptr [rsp + 0x40], 0xff
00004fe9  4c 8d 05 10 27 01 00  lea r8, [rip + 0x12710]
00004ff0  4c 8d 0d 79 ac 01 00  lea r9, [rip + 0x1ac79]
00004ff7  48 8d 54 24 68  lea rdx, [rsp + 0x68]
00004ffc  4c 89 f1  mov rcx, r14
00004fff  e8 4c c4 00 00  call 0x180011450
00005004  4c 8b 54 24 50  mov r10, qword ptr [rsp + 0x50]
00005009  48 8b 06  mov rax, qword ptr [rsi]
0000500c  48 8b 0d 5d 03 01 00  mov rcx, qword ptr [rip + 0x1035d]
00005013  48 89 41 38  mov qword ptr [rcx + 0x38], rax
00005017  48 8b 55 00  mov rdx, qword ptr [rbp]
0000501b  48 89 51 40  mov qword ptr [rcx + 0x40], rdx
0000501f  49 8b 17  mov rdx, qword ptr [r15]
00005022  48 c1 ea 3e  shr rdx, 0x3e
00005026  83 e2 fe  and edx, 0xfffffffe
00005029  48 89 11  mov qword ptr [rcx], rdx
0000502c  48 c7 41 60 00 00 00 00  mov qword ptr [rcx + 0x60], 0
00005034  31 c9  xor ecx, ecx
00005036  48 85 c0  test rax, rax
00005039  0f 95 c1  setne cl
0000503c  48 89 0d 35 ac 01 00  mov qword ptr [rip + 0x1ac35], rcx
00005043  48 8d 05 2e ac 01 00  lea rax, [rip + 0x1ac2e]
0000504a  4c 89 e1  mov rcx, r12
0000504d  48 f7 d9  neg rcx
00005050  49 0f 48 cc  cmovs rcx, r12
00005054  4c 89 ea  mov rdx, r13
00005057  48 f7 da  neg rdx
0000505a  49 0f 48 d5  cmovs rdx, r13
0000505e  48 89 4c 24 60  mov qword ptr [rsp + 0x60], rcx
00005063  48 89 54 24 58  mov qword ptr [rsp + 0x58], rdx
00005068  4c 89 7c 24 28  mov qword ptr [rsp + 0x28], r15
0000506d  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00005072  48 c7 44 24 30 ff 00 00 00  mov qword ptr [rsp + 0x30], 0xff
0000507b  48 8d 15 96 26 01 00  lea rdx, [rip + 0x12696]
00005082  48 8d 4c 24 60  lea rcx, [rsp + 0x60]
00005087  4c 8d 4c 24 58  lea r9, [rsp + 0x58]
0000508c  4d 89 d0  mov r8, r10
0000508f  e8 2c 39 00 00  call 0x1800089c0
00005094  90  nop
00005095  48 83 c4 78  add rsp, 0x78
00005099  5b  pop rbx
0000509a  5d  pop rbp
0000509b  5f  pop rdi
0000509c  5e  pop rsi
0000509d  41 5c  pop r12
0000509f  41 5d  pop r13
000050a1  41 5e  pop r14
000050a3  41 5f  pop r15
000050a5  c3  ret
; owner 0x50b0 PPEXEC_PPSLAVE2
000050b0  48 83 ec 58  sub rsp, 0x58
000050b4  0f 28 84 24 80 00 00 00  movaps xmm0, xmmword ptr [rsp + 0x80]
000050bc  0f 28 8c 24 90 00 00 00  movaps xmm1, xmmword ptr [rsp + 0x90]
000050c4  48 c7 05 b1 ab 01 00 00 00 00 00  mov qword ptr [rip + 0x1abb1], 0
000050cf  48 8d 05 aa ab 01 00  lea rax, [rip + 0x1abaa]
000050d6  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
000050db  0f 11 4c 24 30  movups xmmword ptr [rsp + 0x30], xmm1
000050e0  0f 11 44 24 20  movups xmmword ptr [rsp + 0x20], xmm0
000050e5  e8 a6 fc ff ff  call 0x180004d90
000050ea  90  nop
000050eb  48 83 c4 58  add rsp, 0x58
000050ef  c3  ret
; owner 0x50f0 PPEXEC_PPSLAVE
000050f0  48 83 ec 58  sub rsp, 0x58
000050f4  0f 28 84 24 80 00 00 00  movaps xmm0, xmmword ptr [rsp + 0x80]
000050fc  48 8b 84 24 90 00 00 00  mov rax, qword ptr [rsp + 0x90]
00005104  48 c7 05 79 ab 01 00 00 00 00 00  mov qword ptr [rip + 0x1ab79], 0
0000510f  4c 8d 15 72 ab 01 00  lea r10, [rip + 0x1ab72]
00005116  48 c7 05 5f ab 01 00 00 00 00 00  mov qword ptr [rip + 0x1ab5f], 0
00005121  4c 8d 1d 58 ab 01 00  lea r11, [rip + 0x1ab58]
00005128  4c 89 5c 24 40  mov qword ptr [rsp + 0x40], r11
0000512d  4c 89 54 24 38  mov qword ptr [rsp + 0x38], r10
00005132  48 89 44 24 30  mov qword ptr [rsp + 0x30], rax
00005137  0f 11 44 24 20  movups xmmword ptr [rsp + 0x20], xmm0
0000513c  e8 4f fc ff ff  call 0x180004d90
00005141  90  nop
00005142  48 83 c4 58  add rsp, 0x58
00005146  c3  ret
; owner 0x5150 PPEXEC_APCLOSE
00005150  4c 8d 05 c9 94 01 00  lea r8, [rip + 0x194c9]
00005157  e9 04 00 00 00  jmp 0x180005160
; owner 0x5160 PPEXEC_APCLOSE2
00005160  41 57  push r15
00005162  41 56  push r14
00005164  41 55  push r13
00005166  41 54  push r12
00005168  56  push rsi
00005169  57  push rdi
0000516a  55  push rbp
0000516b  53  push rbx
0000516c  48 81 ec 78 01 00 00  sub rsp, 0x178
00005173  4c 89 c3  mov rbx, r8
00005176  48 89 d6  mov rsi, rdx
00005179  48 89 cf  mov rdi, rcx
0000517c  48 c7 05 d9 ac 01 00 00 00 00 00  mov qword ptr [rip + 0x1acd9], 0
00005187  48 c7 05 c6 ac 01 00 00 00 00 00  mov qword ptr [rip + 0x1acc6], 0
00005192  48 c7 05 ab ac 01 00 00 00 00 00  mov qword ptr [rip + 0x1acab], 0
0000519d  48 8b 05 3c 03 01 00  mov rax, qword ptr [rip + 0x1033c]
000051a4  48 83 b8 30 4f 00 00 00  cmp qword ptr [rax + 0x4f30], 0
000051ac  0f 84 c5 01 00 00  je 0x180005377
000051b2  4c 8b 3d df 00 01 00  mov r15, qword ptr [rip + 0x100df]
000051b9  49 83 7f 68 00  cmp qword ptr [r15 + 0x68], 0
000051be  0f 84 8a 01 00 00  je 0x18000534e
000051c4  48 8d 0d 85 25 01 00  lea rcx, [rip + 0x12585]
000051cb  48 8d 15 76 ac 01 00  lea rdx, [rip + 0x1ac76]
000051d2  49 89 d0  mov r8, rdx
000051d5  49 89 d1  mov r9, rdx
000051d8  e8 e3 c1 00 00  call 0x1800113c0
000051dd  e8 c2 c8 00 00  call 0x180011aa4
000051e2  e8 7b c2 00 00  call 0x180011462
000051e7  4c 8b 25 1a 02 01 00  mov r12, qword ptr [rip + 0x1021a]
000051ee  49 83 bc 24 88 20 00 00 00  cmp qword ptr [r12 + 0x2088], 0
000051f7  75 05  jne 0x1800051fe
000051f9  e8 6a c2 00 00  call 0x180011468
000051fe  e8 6b c2 00 00  call 0x18001146e
00005203  48 c7 84 24 48 01 00 00 00 00 00 00  mov qword ptr [rsp + 0x148], 0
0000520f  8b 13  mov edx, dword ptr [rbx]
00005211  49 bd 38 04 0c 00 01 00 00 00  movabs r13, 0x1000c0438
0000521b  4c 89 ac 24 10 01 00 00  mov qword ptr [rsp + 0x110], r13
00005223  48 c7 84 24 38 01 00 00 04 00 00 00  mov qword ptr [rsp + 0x138], 4
0000522f  48 8d 2d ea 24 01 00  lea rbp, [rip + 0x124ea]
00005236  48 89 ac 24 40 01 00 00  mov qword ptr [rsp + 0x140], rbp
0000523e  48 8d 84 24 38 01 00 00  lea rax, [rsp + 0x138]
00005246  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0000524b  4c 8d b4 24 48 01 00 00  lea r14, [rsp + 0x148]
00005253  48 bb 00 ff 84 83 20 01 08 00  movabs rbx, 0x801208384ff00
0000525d  4c 8d 8c 24 10 01 00 00  lea r9, [rsp + 0x110]
00005265  4c 89 f1  mov rcx, r14
00005268  49 89 d8  mov r8, rbx
0000526b  e8 a6 c8 00 00  call 0x180011b16
00005270  48 c7 84 24 48 01 00 00 00 00 00 00  mov qword ptr [rsp + 0x148], 0
0000527c  4c 89 ac 24 08 01 00 00  mov qword ptr [rsp + 0x108], r13
00005284  48 c7 84 24 28 01 00 00 04 00 00 00  mov qword ptr [rsp + 0x128], 4
00005290  48 89 ac 24 30 01 00 00  mov qword ptr [rsp + 0x130], rbp
00005298  48 8d 84 24 28 01 00 00  lea rax, [rsp + 0x128]
000052a0  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000052a5  4c 8d 8c 24 08 01 00 00  lea r9, [rsp + 0x108]
000052ad  4c 89 f1  mov rcx, r14
000052b0  ba 0c 00 00 00  mov edx, 0xc
000052b5  49 89 d8  mov r8, rbx
000052b8  e8 59 c8 00 00  call 0x180011b16
000052bd  48 c7 84 24 48 01 00 00 00 00 00 00  mov qword ptr [rsp + 0x148], 0
000052c9  4c 89 ac 24 00 01 00 00  mov qword ptr [rsp + 0x100], r13
000052d1  48 c7 84 24 18 01 00 00 04 00 00 00  mov qword ptr [rsp + 0x118], 4
000052dd  48 89 ac 24 20 01 00 00  mov qword ptr [rsp + 0x120], rbp
000052e5  48 8d 84 24 18 01 00 00  lea rax, [rsp + 0x118]
000052ed  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000052f2  4c 8d 8c 24 00 01 00 00  lea r9, [rsp + 0x100]
000052fa  4c 89 f1  mov rcx, r14
000052fd  ba 05 00 00 00  mov edx, 5
00005302  49 89 d8  mov r8, rbx
00005305  e8 0c c8 00 00  call 0x180011b16
0000530a  49 83 bc 24 88 20 00 00 00  cmp qword ptr [r12 + 0x2088], 0
00005313  75 13  jne 0x180005328
00005315  48 8d 0d 44 ab 01 00  lea rcx, [rip + 0x1ab44]
0000531c  48 8d 15 35 ab 01 00  lea rdx, [rip + 0x1ab35]
00005323  e8 4c c1 00 00  call 0x180011474
00005328  49 c7 47 68 00 00 00 00  mov qword ptr [r15 + 0x68], 0
00005330  48 8b 05 59 00 01 00  mov rax, qword ptr [rip + 0x10059]
00005337  48 c7 40 08 00 00 00 00  mov qword ptr [rax + 8], 0
0000533f  48 8b 05 3a 00 01 00  mov rax, qword ptr [rip + 0x1003a]
00005346  48 c7 40 38 00 00 00 00  mov qword ptr [rax + 0x38], 0
0000534e  48 8b 05 b3 00 01 00  mov rax, qword ptr [rip + 0x100b3]
00005355  48 83 b8 88 20 00 00 00  cmp qword ptr [rax + 0x2088], 0
0000535d  0f 84 e1 01 00 00  je 0x180005544
00005363  48 81 c4 78 01 00 00  add rsp, 0x178
0000536a  5b  pop rbx
0000536b  5d  pop rbp
0000536c  5f  pop rdi
0000536d  5e  pop rsi
0000536e  41 5c  pop r12
00005370  41 5d  pop r13
00005372  41 5e  pop r14
00005374  41 5f  pop r15
00005376  c3  ret
00005377  48 8d 0d a6 23 01 00  lea rcx, [rip + 0x123a6]
0000537e  e8 81 f3 00 00  call 0x180014704
00005383  48 85 c0  test rax, rax
00005386  0f 84 26 fe ff ff  je 0x1800051b2
0000538c  41 bf d0 00 00 00  mov r15d, 0xd0
00005392  4c 03 3d 07 ff 00 00  add r15, qword ptr [rip + 0xff07]
00005399  4c 89 7c 24 20  mov qword ptr [rsp + 0x20], r15
0000539e  48 8d 0d 03 a9 01 00  lea rcx, [rip + 0x1a903]
000053a5  48 8d 15 d4 92 01 00  lea rdx, [rip + 0x192d4]
000053ac  4c 8d 05 7d 23 01 00  lea r8, [rip + 0x1237d]
000053b3  4c 8d 35 86 23 01 00  lea r14, [rip + 0x12386]
000053ba  4d 89 f1  mov r9, r14
000053bd  e8 ca c0 00 00  call 0x18001148c
000053c2  48 89 05 87 aa 01 00  mov qword ptr [rip + 0x1aa87], rax
000053c9  48 85 c0  test rax, rax
000053cc  0f 85 e0 fd ff ff  jne 0x1800051b2
000053d2  48 8d 05 77 aa 01 00  lea rax, [rip + 0x1aa77]
000053d9  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000053de  48 8d 0d bb a8 01 00  lea rcx, [rip + 0x1a8bb]
000053e5  48 8d 15 54 92 01 00  lea rdx, [rip + 0x19254]
000053ec  4c 8d 05 b5 a8 01 00  lea r8, [rip + 0x1a8b5]
000053f3  4d 89 f9  mov r9, r15
000053f6  e8 97 c0 00 00  call 0x180011492
000053fb  48 83 3d 4d aa 01 00 00  cmp qword ptr [rip + 0x1aa4d], 0
00005403  0f 85 a9 fd ff ff  jne 0x1800051b2
00005409  48 8d 05 a0 a8 01 00  lea rax, [rip + 0x1a8a0]
00005410  48 89 84 24 f0 00 00 00  mov qword ptr [rsp + 0xf0], rax
00005418  48 89 84 24 e8 00 00 00  mov qword ptr [rsp + 0xe8], rax
00005420  48 89 84 24 e0 00 00 00  mov qword ptr [rsp + 0xe0], rax
00005428  48 89 84 24 d8 00 00 00  mov qword ptr [rsp + 0xd8], rax
00005430  48 89 84 24 d0 00 00 00  mov qword ptr [rsp + 0xd0], rax
00005438  48 89 84 24 c8 00 00 00  mov qword ptr [rsp + 0xc8], rax
00005440  48 89 84 24 c0 00 00 00  mov qword ptr [rsp + 0xc0], rax
00005448  48 8d 05 f9 22 01 00  lea rax, [rip + 0x122f9]
0000544f  48 89 84 24 b8 00 00 00  mov qword ptr [rsp + 0xb8], rax
00005457  48 8d 0d 22 a9 01 00  lea rcx, [rip + 0x1a922]
0000545e  48 89 8c 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], rcx
00005466  48 89 84 24 a8 00 00 00  mov qword ptr [rsp + 0xa8], rax
0000546e  48 8d 0d 2b a9 01 00  lea rcx, [rip + 0x1a92b]
00005475  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
0000547d  48 8d 0d 3c a8 01 00  lea rcx, [rip + 0x1a83c]
00005484  48 89 8c 24 98 00 00 00  mov qword ptr [rsp + 0x98], rcx
0000548c  48 8d 0d 4d a8 01 00  lea rcx, [rip + 0x1a84d]
00005493  48 89 8c 24 90 00 00 00  mov qword ptr [rsp + 0x90], rcx
0000549b  48 89 84 24 88 00 00 00  mov qword ptr [rsp + 0x88], rax
000054a3  48 8d 0d 56 a8 01 00  lea rcx, [rip + 0x1a856]
000054aa  48 89 8c 24 80 00 00 00  mov qword ptr [rsp + 0x80], rcx
000054b2  48 8d 0d 87 a8 01 00  lea rcx, [rip + 0x1a887]
000054b9  48 89 4c 24 78  mov qword ptr [rsp + 0x78], rcx
000054be  48 8d 0d 9b a8 01 00  lea rcx, [rip + 0x1a89b]
000054c5  48 89 4c 24 70  mov qword ptr [rsp + 0x70], rcx
000054ca  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
000054cf  48 8d 05 4a a8 01 00  lea rax, [rip + 0x1a84a]
000054d6  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
000054db  48 8d 05 de a8 01 00  lea rax, [rip + 0x1a8de]
000054e2  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
000054e7  48 8d 05 f2 a8 01 00  lea rax, [rip + 0x1a8f2]
000054ee  48 89 44 24 50  mov qword ptr [rsp + 0x50], rax
000054f3  48 8d 05 06 a9 01 00  lea rax, [rip + 0x1a906]
000054fa  48 89 44 24 48  mov qword ptr [rsp + 0x48], rax
000054ff  48 8d 05 1a a9 01 00  lea rax, [rip + 0x1a91a]
00005506  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
0000550b  48 8d 05 2e a9 01 00  lea rax, [rip + 0x1a92e]
00005512  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00005517  4c 89 74 24 30  mov qword ptr [rsp + 0x30], r14
0000551c  4c 89 74 24 28  mov qword ptr [rsp + 0x28], r14
00005521  4c 89 74 24 20  mov qword ptr [rsp + 0x20], r14
00005526  48 8d 0d 73 a7 01 00  lea rcx, [rip + 0x1a773]
0000552d  48 8d 15 04 22 01 00  lea rdx, [rip + 0x12204]
00005534  4d 89 f0  mov r8, r14
00005537  4d 89 f1  mov r9, r14
0000553a  e8 59 bf 00 00  call 0x180011498
0000553f  e9 6e fc ff ff  jmp 0x1800051b2
00005544  48 8b 1d 8d fc 00 00  mov rbx, qword ptr [rip + 0xfc8d]
0000554b  48 83 bb 40 01 00 00 00  cmp qword ptr [rbx + 0x140], 0
00005553  74 31  je 0x180005586
00005555  48 8d 8b a0 00 00 00  lea rcx, [rbx + 0xa0]
0000555c  e8 43 bf 00 00  call 0x1800114a4
00005561  48 89 05 e8 a8 01 00  mov qword ptr [rip + 0x1a8e8], rax
00005568  48 8b 83 40 01 00 00  mov rax, qword ptr [rbx + 0x140]
0000556f  48 c1 e0 08  shl rax, 8
00005573  c6 84 18 88 00 00 00 20  mov byte ptr [rax + rbx + 0x88], 0x20
0000557b  48 c7 83 40 01 00 00 00 00 00 00  mov qword ptr [rbx + 0x140], 0
00005586  48 83 bb 50 01 00 00 00  cmp qword ptr [rbx + 0x150], 0
0000558e  74 31  je 0x1800055c1
00005590  48 8d 8b b0 00 00 00  lea rcx, [rbx + 0xb0]
00005597  e8 08 bf 00 00  call 0x1800114a4
0000559c  48 89 05 ad a8 01 00  mov qword ptr [rip + 0x1a8ad], rax
000055a3  48 8b 83 50 01 00 00  mov rax, qword ptr [rbx + 0x150]
000055aa  48 c1 e0 08  shl rax, 8
000055ae  c6 84 18 88 00 00 00 20  mov byte ptr [rax + rbx + 0x88], 0x20
000055b6  48 c7 83 50 01 00 00 00 00 00 00  mov qword ptr [rbx + 0x150], 0
000055c1  48 83 3f 01  cmp qword ptr [rdi], 1
000055c5  75 0a  jne 0x1800055d1
000055c7  e8 76 bd 00 00  call 0x180011342
000055cc  e8 77 bd 00 00  call 0x180011348
000055d1  48 83 3e 01  cmp qword ptr [rsi], 1
000055d5  0f 85 88 fd ff ff  jne 0x180005363
000055db  48 8b 05 8e fd 00 00  mov rax, qword ptr [rip + 0xfd8e]
000055e2  48 83 38 02  cmp qword ptr [rax], 2
000055e6  0f 85 77 fd ff ff  jne 0x180005363
000055ec  48 81 c4 78 01 00 00  add rsp, 0x178
000055f3  5b  pop rbx
000055f4  5d  pop rbp
000055f5  5f  pop rdi
000055f6  5e  pop rsi
000055f7  41 5c  pop r12
000055f9  41 5d  pop r13
000055fb  41 5e  pop r14
000055fd  41 5f  pop r15
000055ff  e9 a6 be 00 00  jmp 0x1800114aa
; owner 0x5610 PPEXEC_LDCMPTYP
00005610  56  push rsi
00005611  57  push rdi
00005612  53  push rbx
00005613  48 83 ec 20  sub rsp, 0x20
00005617  48 8d 0d 6a a8 01 00  lea rcx, [rip + 0x1a86a]
0000561e  e8 8d be 00 00  call 0x1800114b0
00005623  48 8b 05 76 fe 00 00  mov rax, qword ptr [rip + 0xfe76]
0000562a  48 8b 88 f8 1b 00 00  mov rcx, qword ptr [rax + 0x1bf8]
00005631  48 89 0d 70 a8 01 00  mov qword ptr [rip + 0x1a870], rcx
00005638  48 8b 3d b1 fe 00 00  mov rdi, qword ptr [rip + 0xfeb1]
0000563f  4c 8b 07  mov r8, qword ptr [rdi]
00005642  4d 85 c0  test r8, r8
00005645  7e 39  jle 0x180005680
00005647  48 c1 e1 03  shl rcx, 3
0000564b  48 03 0d a6 fe 00 00  add rcx, qword ptr [rip + 0xfea6]
00005652  49 83 f8 0d  cmp r8, 0xd
00005656  72 0d  jb 0x180005665
00005658  49 c1 e0 03  shl r8, 3
0000565c  31 d2  xor edx, edx
0000565e  e8 8d 37 00 00  call 0x180008df0
00005663  eb 1b  jmp 0x180005680
00005665  31 c0  xor eax, eax
00005667  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00005670  48 c7 04 c1 00 00 00 00  mov qword ptr [rcx + rax*8], 0
00005678  48 ff c0  inc rax
0000567b  49 39 c0  cmp r8, rax
0000567e  75 f0  jne 0x180005670
00005680  48 8d 0d 71 a8 01 00  lea rcx, [rip + 0x1a871]
00005687  e8 44 bf 00 00  call 0x1800115d0
0000568c  48 83 3d 64 a8 01 00 00  cmp qword ptr [rip + 0x1a864], 0
00005694  0f 8e 96 02 00 00  jle 0x180005930
0000569a  48 8d 0d 57 a8 01 00  lea rcx, [rip + 0x1a857]
000056a1  e8 ae bc 00 00  call 0x180011354
000056a6  48 89 05 43 a8 01 00  mov qword ptr [rip + 0x1a843], rax
000056ad  48 8b 35 44 fe 00 00  mov rsi, qword ptr [rip + 0xfe44]
000056b4  48 8b 0c c6  mov rcx, qword ptr [rsi + rax*8]
000056b8  48 8b 54 c6 08  mov rdx, qword ptr [rsi + rax*8 + 8]
000056bd  48 89 0d 14 a8 01 00  mov qword ptr [rip + 0x1a814], rcx
000056c4  48 8d 0d 0d a8 01 00  lea rcx, [rip + 0x1a80d]
000056cb  48 89 15 16 a8 01 00  mov qword ptr [rip + 0x1a816], rdx
000056d2  48 8b 54 c6 20  mov rdx, qword ptr [rsi + rax*8 + 0x20]
000056d7  48 89 15 da a7 01 00  mov qword ptr [rip + 0x1a7da], rdx
000056de  48 8b 54 c6 28  mov rdx, qword ptr [rsi + rax*8 + 0x28]
000056e3  48 89 15 de a7 01 00  mov qword ptr [rip + 0x1a7de], rdx
000056ea  48 8b 44 c6 78  mov rax, qword ptr [rsi + rax*8 + 0x78]
000056ef  48 89 05 a2 a7 01 00  mov qword ptr [rip + 0x1a7a2], rax
000056f6  e8 59 bc 00 00  call 0x180011354
000056fb  48 8b 4c c6 f8  mov rcx, qword ptr [rsi + rax*8 - 8]
00005700  48 89 0d c9 a7 01 00  mov qword ptr [rip + 0x1a7c9], rcx
00005707  48 85 c9  test rcx, rcx
0000570a  7e 38  jle 0x180005744
0000570c  48 8b 15 95 a7 01 00  mov rdx, qword ptr [rip + 0x1a795]
00005713  48 c1 e0 03  shl rax, 3
00005717  48 03 05 da fd 00 00  add rax, qword ptr [rip + 0xfdda]
0000571e  45 31 c0  xor r8d, r8d
00005721  49 b9 00 00 00 00 00 00 f0 3f  movabs r9, 0x3ff0000000000000
0000572b  0f 1f 44 00 00  nop dword ptr [rax + rax]
00005730  4e 8b 14 c0  mov r10, qword ptr [rax + r8*8]
00005734  49 01 d2  add r10, rdx
00005737  4e 89 4c d6 f8  mov qword ptr [rsi + r10*8 - 8], r9
0000573c  49 ff c0  inc r8
0000573f  49 39 c8  cmp r8, rcx
00005742  7c ec  jl 0x180005730
00005744  48 83 3d 9c a7 01 00 00  cmp qword ptr [rip + 0x1a79c], 0
0000574c  7e 56  jle 0x1800057a4
0000574e  48 8d 0d 93 a7 01 00  lea rcx, [rip + 0x1a793]
00005755  e8 fa bb 00 00  call 0x180011354
0000575a  48 8b 4c c6 f8  mov rcx, qword ptr [rsi + rax*8 - 8]
0000575f  48 89 0d 7a a7 01 00  mov qword ptr [rip + 0x1a77a], rcx
00005766  48 85 c9  test rcx, rcx
00005769  7e 39  jle 0x1800057a4
0000576b  48 8b 15 36 a7 01 00  mov rdx, qword ptr [rip + 0x1a736]
00005772  48 c1 e0 03  shl rax, 3
00005776  48 03 05 7b fd 00 00  add rax, qword ptr [rip + 0xfd7b]
0000577d  45 31 c0  xor r8d, r8d
00005780  49 b9 00 00 00 00 00 00 00 40  movabs r9, 0x4000000000000000
0000578a  66 0f 1f 44 00 00  nop word ptr [rax + rax]
00005790  4e 8b 14 c0  mov r10, qword ptr [rax + r8*8]
00005794  49 01 d2  add r10, rdx
00005797  4e 89 4c d6 f8  mov qword ptr [rsi + r10*8 - 8], r9
0000579c  49 ff c0  inc r8
0000579f  49 39 c8  cmp r8, rcx
000057a2  7c ec  jl 0x180005790
000057a4  48 83 3d 0c a7 01 00 00  cmp qword ptr [rip + 0x1a70c], 0
000057ac  7e 56  jle 0x180005804
000057ae  48 8d 0d 03 a7 01 00  lea rcx, [rip + 0x1a703]
000057b5  e8 9a bb 00 00  call 0x180011354
000057ba  48 8b 4c c6 f8  mov rcx, qword ptr [rsi + rax*8 - 8]
000057bf  48 89 0d ea a6 01 00  mov qword ptr [rip + 0x1a6ea], rcx
000057c6  48 85 c9  test rcx, rcx
000057c9  7e 39  jle 0x180005804
000057cb  48 8b 15 d6 a6 01 00  mov rdx, qword ptr [rip + 0x1a6d6]
000057d2  48 c1 e0 03  shl rax, 3
000057d6  48 03 05 1b fd 00 00  add rax, qword ptr [rip + 0xfd1b]
000057dd  45 31 c0  xor r8d, r8d
000057e0  49 b9 00 00 00 00 00 00 08 40  movabs r9, 0x4008000000000000
000057ea  66 0f 1f 44 00 00  nop word ptr [rax + rax]
000057f0  4e 8b 14 c0  mov r10, qword ptr [rax + r8*8]
000057f4  49 01 d2  add r10, rdx
000057f7  4e 89 4c d6 f8  mov qword ptr [rsi + r10*8 - 8], r9
000057fc  49 ff c0  inc r8
000057ff  49 39 c8  cmp r8, rcx
00005802  7c ec  jl 0x1800057f0
00005804  48 83 3d bc a6 01 00 00  cmp qword ptr [rip + 0x1a6bc], 0
0000580c  7e 56  jle 0x180005864
0000580e  48 8d 0d b3 a6 01 00  lea rcx, [rip + 0x1a6b3]
00005815  e8 3a bb 00 00  call 0x180011354
0000581a  48 8b 4c c6 f8  mov rcx, qword ptr [rsi + rax*8 - 8]
0000581f  48 89 0d 9a a6 01 00  mov qword ptr [rip + 0x1a69a], rcx
00005826  48 85 c9  test rcx, rcx
00005829  7e 39  jle 0x180005864
0000582b  48 8b 15 76 a6 01 00  mov rdx, qword ptr [rip + 0x1a676]
00005832  48 c1 e0 03  shl rax, 3
00005836  48 03 05 bb fc 00 00  add rax, qword ptr [rip + 0xfcbb]
0000583d  45 31 c0  xor r8d, r8d
00005840  49 b9 00 00 00 00 00 00 10 40  movabs r9, 0x4010000000000000
0000584a  66 0f 1f 44 00 00  nop word ptr [rax + rax]
00005850  4e 8b 14 c0  mov r10, qword ptr [rax + r8*8]
00005854  49 01 d2  add r10, rdx
00005857  4e 89 4c d6 f8  mov qword ptr [rsi + r10*8 - 8], r9
0000585c  49 ff c0  inc r8
0000585f  49 39 c8  cmp r8, rcx
00005862  7c ec  jl 0x180005850
00005864  48 83 3d 2c a6 01 00 00  cmp qword ptr [rip + 0x1a62c], 0
0000586c  7e 56  jle 0x1800058c4
0000586e  48 8d 0d 23 a6 01 00  lea rcx, [rip + 0x1a623]
00005875  e8 da ba 00 00  call 0x180011354
0000587a  48 8b 4c c6 f8  mov rcx, qword ptr [rsi + rax*8 - 8]
0000587f  48 89 0d 0a a6 01 00  mov qword ptr [rip + 0x1a60a], rcx
00005886  48 85 c9  test rcx, rcx
00005889  7e 39  jle 0x1800058c4
0000588b  48 8b 15 16 a6 01 00  mov rdx, qword ptr [rip + 0x1a616]
00005892  48 c1 e0 03  shl rax, 3
00005896  48 03 05 5b fc 00 00  add rax, qword ptr [rip + 0xfc5b]
0000589d  45 31 c0  xor r8d, r8d
000058a0  49 b9 00 00 00 00 00 00 14 40  movabs r9, 0x4014000000000000
000058aa  66 0f 1f 44 00 00  nop word ptr [rax + rax]
000058b0  4e 8b 14 c0  mov r10, qword ptr [rax + r8*8]
000058b4  49 01 d2  add r10, rdx
000058b7  4e 89 4c d6 f8  mov qword ptr [rsi + r10*8 - 8], r9
000058bc  49 ff c0  inc r8
000058bf  49 39 c8  cmp r8, rcx
000058c2  7c ec  jl 0x1800058b0
000058c4  48 8b 05 25 a6 01 00  mov rax, qword ptr [rip + 0x1a625]
000058cb  48 8b 44 c6 30  mov rax, qword ptr [rsi + rax*8 + 0x30]
000058d0  48 89 05 c9 a5 01 00  mov qword ptr [rip + 0x1a5c9], rax
000058d7  48 8d 0d c2 a5 01 00  lea rcx, [rip + 0x1a5c2]
000058de  e8 71 ba 00 00  call 0x180011354
000058e3  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
000058e8  48 8b 0d f1 a5 01 00  mov rcx, qword ptr [rip + 0x1a5f1]
000058ef  48 89 8f 80 00 00 00  mov qword ptr [rdi + 0x80], rcx
000058f6  48 89 87 98 00 00 00  mov qword ptr [rdi + 0x98], rax
000058fd  48 8b 05 ac a5 01 00  mov rax, qword ptr [rip + 0x1a5ac]
00005904  48 89 87 90 00 00 00  mov qword ptr [rdi + 0x90], rax
0000590b  48 8b 05 be a5 01 00  mov rax, qword ptr [rip + 0x1a5be]
00005912  48 89 87 88 00 00 00  mov qword ptr [rdi + 0x88], rax
00005919  48 8b 05 a0 a5 01 00  mov rax, qword ptr [rip + 0x1a5a0]
00005920  48 89 87 a0 00 00 00  mov qword ptr [rdi + 0xa0], rax
00005927  48 8b 05 62 a5 01 00  mov rax, qword ptr [rip + 0x1a562]
0000592e  eb 1e  jmp 0x18000594e
00005930  0f 57 c0  xorps xmm0, xmm0
00005933  0f 29 87 90 00 00 00  movaps xmmword ptr [rdi + 0x90], xmm0
0000593a  0f 29 87 80 00 00 00  movaps xmmword ptr [rdi + 0x80], xmm0
00005941  48 c7 87 a0 00 00 00 00 00 00 00  mov qword ptr [rdi + 0xa0], 0
0000594c  31 c0  xor eax, eax
0000594e  48 89 87 a8 00 00 00  mov qword ptr [rdi + 0xa8], rax
00005955  48 83 3d 2b a5 01 00 01  cmp qword ptr [rip + 0x1a52b], 1
0000595d  48 8b 35 74 fb 00 00  mov rsi, qword ptr [rip + 0xfb74]
00005964  75 0e  jne 0x180005974
00005966  48 83 be e8 00 00 00 01  cmp qword ptr [rsi + 0xe8], 1
0000596e  0f 84 09 01 00 00  je 0x180005a7d
00005974  48 8d 0d dd 1d 01 00  lea rcx, [rip + 0x11ddd]
0000597b  e8 d4 b9 00 00  call 0x180011354
00005980  48 89 05 f9 a4 01 00  mov qword ptr [rip + 0x1a4f9], rax
00005987  48 8b 1d 6a fb 00 00  mov rbx, qword ptr [rip + 0xfb6a]
0000598e  48 8b 44 c3 10  mov rax, qword ptr [rbx + rax*8 + 0x10]
00005993  48 89 05 de a4 01 00  mov qword ptr [rip + 0x1a4de], rax
0000599a  48 85 c0  test rax, rax
0000599d  74 15  je 0x1800059b4
0000599f  48 8d 0d d2 a4 01 00  lea rcx, [rip + 0x1a4d2]
000059a6  e8 a9 b9 00 00  call 0x180011354
000059ab  48 89 05 be a4 01 00  mov qword ptr [rip + 0x1a4be], rax
000059b2  eb 34  jmp 0x1800059e8
000059b4  48 8d 0d a5 1d 01 00  lea rcx, [rip + 0x11da5]
000059bb  48 8d 15 b6 a4 01 00  lea rdx, [rip + 0x1a4b6]
000059c2  4c 8d 05 a7 a4 01 00  lea r8, [rip + 0x1a4a7]
000059c9  e8 40 ba 00 00  call 0x18001140e
000059ce  48 8b 05 a3 a4 01 00  mov rax, qword ptr [rip + 0x1a4a3]
000059d5  48 8b 0d a4 a4 01 00  mov rcx, qword ptr [rip + 0x1a4a4]
000059dc  48 89 44 cb 10  mov qword ptr [rbx + rcx*8 + 0x10], rax
000059e1  48 8b 05 88 a4 01 00  mov rax, qword ptr [rip + 0x1a488]
000059e8  48 8d 14 c3  lea rdx, [rbx + rax*8]
000059ec  48 83 c2 38  add rdx, 0x38
000059f0  48 83 7c c3 38 00  cmp qword ptr [rbx + rax*8 + 0x38], 0
000059f6  74 11  je 0x180005a09
000059f8  48 89 d1  mov rcx, rdx
000059fb  e8 08 ba 00 00  call 0x180011408
00005a00  48 89 86 80 00 00 00  mov qword ptr [rsi + 0x80], rax
00005a07  eb 2b  jmp 0x180005a34
00005a09  48 8b 47 38  mov rax, qword ptr [rdi + 0x38]
00005a0d  48 03 47 28  add rax, qword ptr [rdi + 0x28]
00005a11  48 8d 0c 00  lea rcx, [rax + rax]
00005a15  48 89 0d 4c a4 01 00  mov qword ptr [rip + 0x1a44c], rcx
00005a1c  48 85 c0  test rax, rax
00005a1f  7e 13  jle 0x180005a34
00005a21  4c 8d 86 80 00 00 00  lea r8, [rsi + 0x80]
00005a28  48 8d 0d 39 a4 01 00  lea rcx, [rip + 0x1a439]
00005a2f  e8 04 ba 00 00  call 0x180011438
00005a34  48 8b 05 35 a4 01 00  mov rax, qword ptr [rip + 0x1a435]
00005a3b  48 8d 14 c3  lea rdx, [rbx + rax*8]
00005a3f  48 83 c2 40  add rdx, 0x40
00005a43  48 83 7c c3 40 00  cmp qword ptr [rbx + rax*8 + 0x40], 0
00005a49  74 0e  je 0x180005a59
00005a4b  48 89 d1  mov rcx, rdx
00005a4e  e8 b5 b9 00 00  call 0x180011408
00005a53  48 89 46 78  mov qword ptr [rsi + 0x78], rax
00005a57  eb 24  jmp 0x180005a7d
00005a59  48 8b 47 40  mov rax, qword ptr [rdi + 0x40]
00005a5d  48 03 47 30  add rax, qword ptr [rdi + 0x30]
00005a61  48 89 05 00 a4 01 00  mov qword ptr [rip + 0x1a400], rax
00005a68  7e 13  jle 0x180005a7d
00005a6a  48 83 c6 78  add rsi, 0x78
00005a6e  48 8d 0d f3 a3 01 00  lea rcx, [rip + 0x1a3f3]
00005a75  49 89 f0  mov r8, rsi
00005a78  e8 bb b9 00 00  call 0x180011438
00005a7d  90  nop
00005a7e  48 83 c4 20  add rsp, 0x20
00005a82  5b  pop rbx
00005a83  5f  pop rdi
00005a84  5e  pop rsi
00005a85  c3  ret
; owner 0x5a90 PPEXEC_INITROUT
00005a90  41 57  push r15
00005a92  41 56  push r14
00005a94  41 54  push r12
00005a96  56  push rsi
00005a97  57  push rdi
00005a98  53  push rbx
00005a99  48 83 ec 28  sub rsp, 0x28
00005a9d  48 8d 0d 3c 1e 01 00  lea rcx, [rip + 0x11e3c]
00005aa4  e8 ab b8 00 00  call 0x180011354
00005aa9  4c 8b 35 48 fa 00 00  mov r14, qword ptr [rip + 0xfa48]
00005ab0  49 8b 84 c6 b0 00 00 00  mov rax, qword ptr [r14 + rax*8 + 0xb0]
00005ab8  48 89 05 71 a4 01 00  mov qword ptr [rip + 0x1a471], rax
00005abf  48 8d 0d 6a a4 01 00  lea rcx, [rip + 0x1a46a]
00005ac6  e8 89 b8 00 00  call 0x180011354
00005acb  48 89 05 56 a4 01 00  mov qword ptr [rip + 0x1a456], rax
00005ad2  4d 8b 7c c6 f8  mov r15, qword ptr [r14 + rax*8 - 8]
00005ad7  4c 89 3d 42 a4 01 00  mov qword ptr [rip + 0x1a442], r15
00005ade  4d 85 ff  test r15, r15
00005ae1  0f 8e d9 00 00 00  jle 0x180005bc0
00005ae7  48 c7 05 16 a4 01 00 01 00 00 00  mov qword ptr [rip + 0x1a416], 1
00005af2  b9 01 00 00 00  mov ecx, 1
00005af7  4c 8d 25 82 1c 01 00  lea r12, [rip + 0x11c82]
00005afe  48 8d 35 fb a3 01 00  lea rsi, [rip + 0x1a3fb]
00005b05  48 8d 3d 0c a4 01 00  lea rdi, [rip + 0x1a40c]
00005b0c  48 8d 1d fd a3 01 00  lea rbx, [rip + 0x1a3fd]
00005b13  4c 89 fa  mov rdx, r15
00005b16  eb 4a  jmp 0x180005b62
00005b20  4b 8b 44 c6 f8  mov rax, qword ptr [r14 + r8*8 - 8]
00005b25  48 89 05 d4 a3 01 00  mov qword ptr [rip + 0x1a3d4], rax
00005b2c  48 89 f9  mov rcx, rdi
00005b2f  48 89 da  mov rdx, rbx
00005b32  49 89 f0  mov r8, rsi
00005b35  e8 26 ba ff ff  call 0x180001560
00005b3a  48 8b 05 e7 a3 01 00  mov rax, qword ptr [rip + 0x1a3e7]
00005b41  48 8b 15 d8 a3 01 00  mov rdx, qword ptr [rip + 0x1a3d8]
00005b48  48 8b 0d b9 a3 01 00  mov rcx, qword ptr [rip + 0x1a3b9]
00005b4f  4c 8d 41 01  lea r8, [rcx + 1]
00005b53  4c 89 05 ae a3 01 00  mov qword ptr [rip + 0x1a3ae], r8
00005b5a  4c 39 f9  cmp rcx, r15
00005b5d  4c 89 c1  mov rcx, r8
00005b60  7d 5e  jge 0x180005bc0
00005b62  4c 8d 04 52  lea r8, [rdx + rdx*2]
00005b66  49 01 c0  add r8, rax
00005b69  49 01 c8  add r8, rcx
00005b6c  4b 83 7c c6 f8 01  cmp qword ptr [r14 + r8*8 - 8], 1
00005b72  75 db  jne 0x180005b4f
00005b74  4c 8d 04 49  lea r8, [rcx + rcx*2]
00005b78  49 01 c0  add r8, rax
00005b7b  4f 8b 4c c6 e8  mov r9, qword ptr [r14 + r8*8 - 0x18]
00005b80  4f 8b 54 c6 f0  mov r10, qword ptr [r14 + r8*8 - 0x10]
00005b85  4c 89 0d 8c a3 01 00  mov qword ptr [rip + 0x1a38c], r9
00005b8c  4c 89 15 7d a3 01 00  mov qword ptr [rip + 0x1a37d], r10
00005b93  41 bb 08 00 00 00  mov r11d, 8
00005b99  eb 16  jmp 0x180005bb1
00005ba0  49 83 c3 10  add r11, 0x10
00005ba4  49 81 fb 68 01 00 00  cmp r11, 0x168
00005bab  0f 84 6f ff ff ff  je 0x180005b20
00005bb1  4f 3b 4c 23 f8  cmp r9, qword ptr [r11 + r12 - 8]
00005bb6  75 e8  jne 0x180005ba0
00005bb8  4f 3b 14 23  cmp r10, qword ptr [r11 + r12]
00005bbc  75 e2  jne 0x180005ba0
00005bbe  eb 8f  jmp 0x180005b4f
00005bc0  48 83 c4 28  add rsp, 0x28
00005bc4  5b  pop rbx
00005bc5  5f  pop rdi
00005bc6  5e  pop rsi
00005bc7  41 5c  pop r12
00005bc9  41 5e  pop r14
00005bcb  41 5f  pop r15
00005bcd  c3  ret
; owner 0x5bd0 runtime_5bd0
00005bd0  48 83 ec 28  sub rsp, 0x28
00005bd4  48 c7 05 69 a3 01 00 00 00 00 00  mov qword ptr [rip + 0x1a369], 0
00005bdf  4c 8d 05 62 a3 01 00  lea r8, [rip + 0x1a362]
00005be6  48 c7 05 4f a3 01 00 00 00 00 00  mov qword ptr [rip + 0x1a34f], 0
00005bf1  48 8d 0d 48 a3 01 00  lea rcx, [rip + 0x1a348]
00005bf8  48 c7 05 35 a3 01 00 00 00 00 00  mov qword ptr [rip + 0x1a335], 0
00005c03  48 8d 15 2e a3 01 00  lea rdx, [rip + 0x1a32e]
00005c0a  e8 a7 b8 00 00  call 0x1800114b6
00005c0f  48 83 3d 31 a3 01 00 00  cmp qword ptr [rip + 0x1a331], 0
00005c17  7e 31  jle 0x180005c4a
00005c19  48 8b 05 20 a3 01 00  mov rax, qword ptr [rip + 0x1a320]
00005c20  48 8b 0d d1 f8 00 00  mov rcx, qword ptr [rip + 0xf8d1]
00005c27  48 8d 14 c1  lea rdx, [rcx + rax*8]
00005c2b  48 83 c2 f8  add rdx, -8
00005c2f  48 8b 05 02 a3 01 00  mov rax, qword ptr [rip + 0x1a302]
00005c36  4c 8d 04 c1  lea r8, [rcx + rax*8]
00005c3a  49 83 c0 f8  add r8, -8
00005c3e  48 8d 0d 03 a3 01 00  lea rcx, [rip + 0x1a303]
00005c45  e8 06 00 00 00  call 0x180005c50
00005c4a  90  nop
00005c4b  48 83 c4 28  add rsp, 0x28
00005c4f  c3  ret
; owner 0x5c50 runtime_5c50
00005c50  41 57  push r15
00005c52  41 56  push r14
00005c54  41 55  push r13
00005c56  41 54  push r12
00005c58  56  push rsi
00005c59  57  push rdi
00005c5a  55  push rbp
00005c5b  53  push rbx
00005c5c  48 81 ec 68 01 00 00  sub rsp, 0x168
00005c63  66 44 0f 29 84 24 50 01 00 00  movapd xmmword ptr [rsp + 0x150], xmm8
00005c6d  66 0f 29 bc 24 40 01 00 00  movapd xmmword ptr [rsp + 0x140], xmm7
00005c76  66 0f 29 b4 24 30 01 00 00  movapd xmmword ptr [rsp + 0x130], xmm6
00005c7f  4c 89 84 24 20 01 00 00  mov qword ptr [rsp + 0x120], r8
00005c87  48 89 94 24 18 01 00 00  mov qword ptr [rsp + 0x118], rdx
00005c8f  48 8b 01  mov rax, qword ptr [rcx]
00005c92  48 89 84 24 10 01 00 00  mov qword ptr [rsp + 0x110], rax
00005c9a  48 85 c0  test rax, rax
00005c9d  0f 8e d3 08 00 00  jle 0x180006576
00005ca3  48 8b 05 f6 f7 00 00  mov rax, qword ptr [rip + 0xf7f6]
00005caa  48 8b 88 f8 0c 00 00  mov rcx, qword ptr [rax + 0xcf8]
00005cb1  48 89 8c 24 08 01 00 00  mov qword ptr [rsp + 0x108], rcx
00005cb9  48 8b 88 28 0a 00 00  mov rcx, qword ptr [rax + 0xa28]
00005cc0  48 89 8c 24 00 01 00 00  mov qword ptr [rsp + 0x100], rcx
00005cc8  48 8b 88 b0 0d 00 00  mov rcx, qword ptr [rax + 0xdb0]
00005ccf  48 89 8c 24 f8 00 00 00  mov qword ptr [rsp + 0xf8], rcx
00005cd7  48 8b 88 f0 0e 00 00  mov rcx, qword ptr [rax + 0xef0]
00005cde  48 89 8c 24 f0 00 00 00  mov qword ptr [rsp + 0xf0], rcx
00005ce6  48 8b 88 e0 0b 00 00  mov rcx, qword ptr [rax + 0xbe0]
00005ced  48 89 8c 24 e8 00 00 00  mov qword ptr [rsp + 0xe8], rcx
00005cf5  48 8b 88 a0 0e 00 00  mov rcx, qword ptr [rax + 0xea0]
00005cfc  48 89 8c 24 e0 00 00 00  mov qword ptr [rsp + 0xe0], rcx
00005d04  48 8b 88 b0 01 00 00  mov rcx, qword ptr [rax + 0x1b0]
00005d0b  48 89 8c 24 d8 00 00 00  mov qword ptr [rsp + 0xd8], rcx
00005d13  48 8b 88 18 02 00 00  mov rcx, qword ptr [rax + 0x218]
00005d1a  48 89 8c 24 d0 00 00 00  mov qword ptr [rsp + 0xd0], rcx
00005d22  48 8b 88 e0 01 00 00  mov rcx, qword ptr [rax + 0x1e0]
00005d29  48 89 8c 24 c8 00 00 00  mov qword ptr [rsp + 0xc8], rcx
00005d31  48 8b 88 78 02 00 00  mov rcx, qword ptr [rax + 0x278]
00005d38  48 89 8c 24 c0 00 00 00  mov qword ptr [rsp + 0xc0], rcx
00005d40  48 8b 90 18 0b 00 00  mov rdx, qword ptr [rax + 0xb18]
00005d47  4c 8b 80 20 31 00 00  mov r8, qword ptr [rax + 0x3120]
00005d4e  4c 8b 88 e8 00 00 00  mov r9, qword ptr [rax + 0xe8]
00005d55  48 8b 0d 8c f7 00 00  mov rcx, qword ptr [rip + 0xf78c]
00005d5c  f2 0f 10 01  movsd xmm0, qword ptr [rcx]
00005d60  48 8b 88 48 01 00 00  mov rcx, qword ptr [rax + 0x148]
00005d67  4c 8b 90 d0 0e 00 00  mov r10, qword ptr [rax + 0xed0]
00005d6e  4c 8b 98 e8 0e 00 00  mov r11, qword ptr [rax + 0xee8]
00005d75  48 8b b0 58 0e 00 00  mov rsi, qword ptr [rax + 0xe58]
00005d7c  48 8b b8 a0 0d 00 00  mov rdi, qword ptr [rax + 0xda0]
00005d83  48 89 bc 24 80 00 00 00  mov qword ptr [rsp + 0x80], rdi
00005d8b  48 8b 98 c0 02 00 00  mov rbx, qword ptr [rax + 0x2c0]
00005d92  48 8b b8 88 09 00 00  mov rdi, qword ptr [rax + 0x988]
00005d99  48 89 7c 24 70  mov qword ptr [rsp + 0x70], rdi
00005d9e  48 8b b8 b0 33 00 00  mov rdi, qword ptr [rax + 0x33b0]
00005da5  48 89 7c 24 08  mov qword ptr [rsp + 8], rdi
00005daa  48 8b b8 b8 33 00 00  mov rdi, qword ptr [rax + 0x33b8]
00005db1  48 89 3c 24  mov qword ptr [rsp], rdi
00005db5  48 8b b8 d8 0e 00 00  mov rdi, qword ptr [rax + 0xed8]
00005dbc  48 89 7c 24 68  mov qword ptr [rsp + 0x68], rdi
00005dc1  48 8b 80 90 0c 00 00  mov rax, qword ptr [rax + 0xc90]
00005dc8  66 0f 28 0d 20 1b 01 00  movapd xmm1, xmmword ptr [rip + 0x11b20]
00005dd0  f2 0f 10 15 38 1b 01 00  movsd xmm2, qword ptr [rip + 0x11b38]
00005dd8  f2 0f 10 1d 38 1b 01 00  movsd xmm3, qword ptr [rip + 0x11b38]
00005de0  66 0f 57 e4  xorpd xmm4, xmm4
00005de4  f2 0f 10 2d 14 1b 01 00  movsd xmm5, qword ptr [rip + 0x11b14]
00005dec  f2 0f 10 35 14 1b 01 00  movsd xmm6, qword ptr [rip + 0x11b14]
00005df4  48 8d 78 f9  lea rdi, [rax - 7]
00005df8  48 89 7c 24 58  mov qword ptr [rsp + 0x58], rdi
00005dfd  48 8b 3d f4 f6 00 00  mov rdi, qword ptr [rip + 0xf6f4]
00005e04  48 89 94 24 b8 00 00 00  mov qword ptr [rsp + 0xb8], rdx
00005e0c  48 8d 54 d7 b8  lea rdx, [rdi + rdx*8 - 0x48]
00005e11  48 89 54 24 50  mov qword ptr [rsp + 0x50], rdx
00005e16  4c 89 84 24 b0 00 00 00  mov qword ptr [rsp + 0xb0], r8
00005e1e  4a 8d 54 c7 b8  lea rdx, [rdi + r8*8 - 0x48]
00005e23  48 89 54 24 48  mov qword ptr [rsp + 0x48], rdx
00005e28  4c 89 8c 24 a8 00 00 00  mov qword ptr [rsp + 0xa8], r9
00005e30  4a 8d 54 cf a8  lea rdx, [rdi + r9*8 - 0x58]
00005e35  48 89 54 24 40  mov qword ptr [rsp + 0x40], rdx
00005e3a  4c 89 94 24 98 00 00 00  mov qword ptr [rsp + 0x98], r10
00005e42  4a 8d 54 d7 d8  lea rdx, [rdi + r10*8 - 0x28]
00005e47  48 89 54 24 38  mov qword ptr [rsp + 0x38], rdx
00005e4c  4c 89 9c 24 90 00 00 00  mov qword ptr [rsp + 0x90], r11
00005e54  4a 8d 54 df d8  lea rdx, [rdi + r11*8 - 0x28]
00005e59  48 89 54 24 30  mov qword ptr [rsp + 0x30], rdx
00005e5e  48 89 8c 24 a0 00 00 00  mov qword ptr [rsp + 0xa0], rcx
00005e66  48 8d 4c cf c0  lea rcx, [rdi + rcx*8 - 0x40]
00005e6b  48 89 4c 24 28  mov qword ptr [rsp + 0x28], rcx
00005e70  48 89 b4 24 88 00 00 00  mov qword ptr [rsp + 0x88], rsi
00005e78  48 8d 4c f7 c8  lea rcx, [rdi + rsi*8 - 0x38]
00005e7d  48 89 4c 24 20  mov qword ptr [rsp + 0x20], rcx
00005e82  48 89 5c 24 78  mov qword ptr [rsp + 0x78], rbx
00005e87  48 8d 4c df d8  lea rcx, [rdi + rbx*8 - 0x28]
00005e8c  48 89 4c 24 18  mov qword ptr [rsp + 0x18], rcx
00005e91  48 89 44 24 60  mov qword ptr [rsp + 0x60], rax
00005e96  48 8d 44 c7 c8  lea rax, [rdi + rax*8 - 0x38]
00005e9b  48 89 44 24 10  mov qword ptr [rsp + 0x10], rax
00005ea0  ba 01 00 00 00  mov edx, 1
00005ea5  4c 8d 35 54 1c 01 00  lea r14, [rip + 0x11c54]
00005eac  4c 8d 25 ad 1b 01 00  lea r12, [rip + 0x11bad]
00005eb3  4c 8d 2d 66 1b 01 00  lea r13, [rip + 0x11b66]
00005eba  48 8d 2d 1f 1b 01 00  lea rbp, [rip + 0x11b1f]
00005ec1  48 8d 05 d8 1a 01 00  lea rax, [rip + 0x11ad8]
00005ec8  4c 8d 15 91 1a 01 00  lea r10, [rip + 0x11a91]
00005ecf  48 8d 35 4a 1a 01 00  lea rsi, [rip + 0x11a4a]
00005ed6  eb 1a  jmp 0x180005ef2
00005ee0  49 8d 51 01  lea rdx, [r9 + 1]
00005ee4  4c 3b 8c 24 10 01 00 00  cmp r9, qword ptr [rsp + 0x110]
00005eec  0f 8d 84 06 00 00  jge 0x180006576
00005ef2  48 8b 8c 24 18 01 00 00  mov rcx, qword ptr [rsp + 0x118]
00005efa  4c 8b 44 d1 f8  mov r8, qword ptr [rcx + rdx*8 - 8]
00005eff  48 8b 4c 24 70  mov rcx, qword ptr [rsp + 0x70]
00005f04  4c 01 c1  add rcx, r8
00005f07  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
00005f0d  48 8b 8c 24 20 01 00 00  mov rcx, qword ptr [rsp + 0x120]
00005f15  48 8b 4c d1 f8  mov rcx, qword ptr [rcx + rdx*8 - 8]
00005f1a  48 83 f9 02  cmp rcx, 2
00005f1e  48 89 94 24 28 01 00 00  mov qword ptr [rsp + 0x128], rdx
00005f26  74 48  je 0x180005f70
00005f28  48 83 f9 03  cmp rcx, 3
00005f2c  0f 85 82 00 00 00  jne 0x180005fb4
00005f32  4c 8b 0c 24  mov r9, qword ptr [rsp]
00005f36  4b 8d 0c 81  lea rcx, [r9 + r8*4]
00005f3a  f2 44 0f 10 44 cf e0  movsd xmm8, qword ptr [rdi + rcx*8 - 0x20]
00005f41  66 44 0f 54 c1  andpd xmm8, xmm1
00005f46  66 44 0f 2e c0  ucomisd xmm8, xmm0
00005f4b  0f 9b c1  setnp cl
00005f4e  0f 94 c2  sete dl
00005f51  4d 85 c9  test r9, r9
00005f54  74 5e  je 0x180005fb4
00005f56  20 ca  and dl, cl
00005f58  74 5a  je 0x180005fb4
00005f5a  48 8b 0c 24  mov rcx, qword ptr [rsp]
00005f5e  4a 8d 0c 81  lea rcx, [rcx + r8*4]
00005f62  48 83 c1 fd  add rcx, -3
00005f66  f2 0f 59 fd  mulsd xmm7, xmm5
00005f6a  f2 0f 58 fe  addsd xmm7, xmm6
00005f6e  eb 3e  jmp 0x180005fae
00005f70  4c 8b 4c 24 08  mov r9, qword ptr [rsp + 8]
00005f75  4b 8d 0c 81  lea rcx, [r9 + r8*4]
00005f79  f2 44 0f 10 44 cf e0  movsd xmm8, qword ptr [rdi + rcx*8 - 0x20]
00005f80  66 44 0f 54 c1  andpd xmm8, xmm1
00005f85  66 44 0f 2e c0  ucomisd xmm8, xmm0
00005f8a  0f 9b c1  setnp cl
00005f8d  0f 94 c2  sete dl
00005f90  4d 85 c9  test r9, r9
00005f93  74 1f  je 0x180005fb4
00005f95  20 ca  and dl, cl
00005f97  74 1b  je 0x180005fb4
00005f99  48 8b 4c 24 08  mov rcx, qword ptr [rsp + 8]
00005f9e  4a 8d 0c 81  lea rcx, [rcx + r8*4]
00005fa2  48 83 c1 fd  add rcx, -3
00005fa6  f2 0f 59 fa  mulsd xmm7, xmm2
00005faa  f2 0f 58 fb  addsd xmm7, xmm3
00005fae  f2 0f 11 7c cf f8  movsd qword ptr [rdi + rcx*8 - 8], xmm7
00005fb4  4c 8b 9c 24 08 01 00 00  mov r11, qword ptr [rsp + 0x108]
00005fbc  4b 8d 0c 03  lea rcx, [r11 + r8]
00005fc0  66 0f 2e 44 cf f8  ucomisd xmm0, qword ptr [rdi + rcx*8 - 8]
00005fc6  0f 9b c2  setnp dl
00005fc9  41 0f 94 c1  sete r9b
00005fcd  4d 85 db  test r11, r11
00005fd0  74 14  je 0x180005fe6
00005fd2  41 20 d1  and r9b, dl
00005fd5  74 0f  je 0x180005fe6
00005fd7  48 ba 00 00 00 00 00 70 a7 40  movabs rdx, 0x40a7700000000000
00005fe1  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
00005fe6  4c 8b 9c 24 00 01 00 00  mov r11, qword ptr [rsp + 0x100]
00005fee  4b 8d 0c 03  lea rcx, [r11 + r8]
00005ff2  66 0f 2e 44 cf f8  ucomisd xmm0, qword ptr [rdi + rcx*8 - 8]
00005ff8  0f 9b c2  setnp dl
00005ffb  41 0f 94 c1  sete r9b
00005fff  4d 85 db  test r11, r11
00006002  74 14  je 0x180006018
00006004  41 20 d1  and r9b, dl
00006007  74 0f  je 0x180006018
00006009  48 ba 00 00 00 00 00 6a 18 41  movabs rdx, 0x41186a0000000000
00006013  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
00006018  4c 8b 9c 24 f8 00 00 00  mov r11, qword ptr [rsp + 0xf8]
00006020  4b 8d 0c 03  lea rcx, [r11 + r8]
00006024  66 0f 2e 44 cf f8  ucomisd xmm0, qword ptr [rdi + rcx*8 - 8]
0000602a  0f 9b c2  setnp dl
0000602d  41 0f 94 c1  sete r9b
00006031  4d 85 db  test r11, r11
00006034  74 14  je 0x18000604a
00006036  41 20 d1  and r9b, dl
00006039  74 0f  je 0x18000604a
0000603b  48 ba 00 00 00 20 b2 8d 4b 40  movabs rdx, 0x404b8db220000000
00006045  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
0000604a  4c 8b bc 24 f0 00 00 00  mov r15, qword ptr [rsp + 0xf0]
00006052  4b 8d 0c 07  lea rcx, [r15 + r8]
00006056  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
0000605c  66 0f 2e c7  ucomisd xmm0, xmm7
00006060  41 0f 9b c3  setnp r11b
00006064  0f 94 c2  sete dl
00006067  66 0f 2e e7  ucomisd xmm4, xmm7
0000606b  0f 9b c3  setnp bl
0000606e  41 0f 94 c1  sete r9b
00006072  4d 85 ff  test r15, r15
00006075  74 1a  je 0x180006091
00006077  44 20 da  and dl, r11b
0000607a  41 20 d9  and r9b, bl
0000607d  41 08 d1  or r9b, dl
00006080  74 0f  je 0x180006091
00006082  48 ba 00 00 00 00 00 42 95 40  movabs rdx, 0x4095420000000000
0000608c  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
00006091  4c 8b 9c 24 e8 00 00 00  mov r11, qword ptr [rsp + 0xe8]
00006099  4b 8d 0c 03  lea rcx, [r11 + r8]
0000609d  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
000060a3  66 0f 54 f9  andpd xmm7, xmm1
000060a7  66 0f 2e f8  ucomisd xmm7, xmm0
000060ab  0f 9b c2  setnp dl
000060ae  41 0f 94 c1  sete r9b
000060b2  4d 85 db  test r11, r11
000060b5  74 14  je 0x1800060cb
000060b7  41 20 d1  and r9b, dl
000060ba  74 0f  je 0x1800060cb
000060bc  48 ba 00 00 00 e0 0b 93 d1 3f  movabs rdx, 0x3fd1930be0000000
000060c6  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
000060cb  4c 8b 9c 24 e0 00 00 00  mov r11, qword ptr [rsp + 0xe0]
000060d3  4b 8d 0c 03  lea rcx, [r11 + r8]
000060d7  66 0f 2e 44 cf f8  ucomisd xmm0, qword ptr [rdi + rcx*8 - 8]
000060dd  0f 9b c2  setnp dl
000060e0  41 0f 94 c1  sete r9b
000060e4  4d 85 db  test r11, r11
000060e7  74 14  je 0x1800060fd
000060e9  41 20 d1  and r9b, dl
000060ec  74 0f  je 0x1800060fd
000060ee  48 ba 00 00 00 40 2a a9 d3 3f  movabs rdx, 0x3fd3a92a40000000
000060f8  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
000060fd  4c 8b bc 24 d8 00 00 00  mov r15, qword ptr [rsp + 0xd8]
00006105  4b 8d 0c 07  lea rcx, [r15 + r8]
00006109  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
0000610f  66 0f 2e c7  ucomisd xmm0, xmm7
00006113  41 0f 9b c3  setnp r11b
00006117  0f 94 c2  sete dl
0000611a  66 0f 2e e7  ucomisd xmm4, xmm7
0000611e  0f 9b c3  setnp bl
00006121  41 0f 94 c1  sete r9b
00006125  4d 85 ff  test r15, r15
00006128  74 1a  je 0x180006144
0000612a  44 20 da  and dl, r11b
0000612d  41 20 d9  and r9b, bl
00006130  41 08 d1  or r9b, dl
00006133  74 0f  je 0x180006144
00006135  48 ba 00 00 00 20 2f 7e c9 c1  movabs rdx, 0xc1c97e2f20000000
0000613f  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
00006144  4c 8b bc 24 d0 00 00 00  mov r15, qword ptr [rsp + 0xd0]
0000614c  4b 8d 0c 07  lea rcx, [r15 + r8]
00006150  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
00006156  66 0f 2e c7  ucomisd xmm0, xmm7
0000615a  41 0f 9b c3  setnp r11b
0000615e  0f 94 c2  sete dl
00006161  66 0f 2e e7  ucomisd xmm4, xmm7
00006165  0f 9b c3  setnp bl
00006168  41 0f 94 c1  sete r9b
0000616c  4d 85 ff  test r15, r15
0000616f  74 1a  je 0x18000618b
00006171  44 20 da  and dl, r11b
00006174  41 20 d9  and r9b, bl
00006177  41 08 d1  or r9b, dl
0000617a  74 0f  je 0x18000618b
0000617c  48 ba 00 00 00 90 34 3a d0 c1  movabs rdx, 0xc1d03a3490000000
00006186  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
0000618b  4c 8b bc 24 c8 00 00 00  mov r15, qword ptr [rsp + 0xc8]
00006193  4b 8d 0c 07  lea rcx, [r15 + r8]
00006197  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
0000619d  66 0f 2e c7  ucomisd xmm0, xmm7
000061a1  41 0f 9b c3  setnp r11b
000061a5  0f 94 c2  sete dl
000061a8  66 0f 2e e7  ucomisd xmm4, xmm7
000061ac  0f 9b c3  setnp bl
000061af  41 0f 94 c1  sete r9b
000061b3  4d 85 ff  test r15, r15
000061b6  74 1a  je 0x1800061d2
000061b8  44 20 da  and dl, r11b
000061bb  41 20 d9  and r9b, bl
000061be  41 08 d1  or r9b, dl
000061c1  74 0f  je 0x1800061d2
000061c3  48 ba 00 00 00 d0 40 10 cb c1  movabs rdx, 0xc1cb1040d0000000
000061cd  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
000061d2  4c 8b bc 24 c0 00 00 00  mov r15, qword ptr [rsp + 0xc0]
000061da  4b 8d 0c 07  lea rcx, [r15 + r8]
000061de  f2 0f 10 7c cf f8  movsd xmm7, qword ptr [rdi + rcx*8 - 8]
000061e4  66 0f 2e c7  ucomisd xmm0, xmm7
000061e8  41 0f 9b c3  setnp r11b
000061ec  0f 94 c2  sete dl
000061ef  66 0f 2e e7  ucomisd xmm4, xmm7
000061f3  0f 9b c3  setnp bl
000061f6  41 0f 94 c1  sete r9b
000061fa  4d 85 ff  test r15, r15
000061fd  74 1a  je 0x180006219
000061ff  44 20 da  and dl, r11b
00006202  41 20 d9  and r9b, bl
00006205  41 08 d1  or r9b, dl
00006208  74 0f  je 0x180006219
0000620a  48 ba 00 00 00 08 41 f9 d2 c1  movabs rdx, 0xc1d2f94108000000
00006214  48 89 54 cf f8  mov qword ptr [rdi + rcx*8 - 8], rdx
00006219  4b 8d 0c c0  lea rcx, [r8 + r8*8]
0000621d  4c 8b 9c 24 b8 00 00 00  mov r11, qword ptr [rsp + 0xb8]
00006225  49 8d 14 0b  lea rdx, [r11 + rcx]
00006229  48 83 c2 f7  add rdx, -9
0000622d  f2 0f 10 3c d7  movsd xmm7, qword ptr [rdi + rdx*8]
00006232  66 0f 54 f9  andpd xmm7, xmm1
00006236  66 0f 2e f8  ucomisd xmm7, xmm0
0000623a  0f 9b c2  setnp dl
0000623d  41 0f 94 c1  sete r9b
00006241  4d 85 db  test r11, r11
00006244  74 30  je 0x180006276
00006246  41 20 d1  and r9b, dl
00006249  74 2b  je 0x180006276
0000624b  48 8b 54 24 50  mov rdx, qword ptr [rsp + 0x50]
00006250  48 8d 14 ca  lea rdx, [rdx + rcx*8]
00006254  45 31 c9  xor r9d, r9d
00006257  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00006260  f2 43 0f 10 3c 31  movsd xmm7, qword ptr [r9 + r14]
00006266  f2 42 0f 11 3c 0a  movsd qword ptr [rdx + r9], xmm7
0000626c  49 83 c1 08  add r9, 8
00006270  49 83 f9 48  cmp r9, 0x48
00006274  75 ea  jne 0x180006260
00006276  4b 8d 14 c0  lea rdx, [r8 + r8*8]
0000627a  48 83 c2 f7  add rdx, -9
0000627e  4c 8b 9c 24 b0 00 00 00  mov r11, qword ptr [rsp + 0xb0]
00006286  4c 01 da  add rdx, r11
00006289  66 0f 2e 04 d7  ucomisd xmm0, qword ptr [rdi + rdx*8]
0000628e  0f 9b c2  setnp dl
00006291  41 0f 94 c1  sete r9b
00006295  4d 85 db  test r11, r11
00006298  74 2b  je 0x1800062c5
0000629a  41 20 d1  and r9b, dl
0000629d  74 26  je 0x1800062c5
0000629f  48 8b 54 24 48  mov rdx, qword ptr [rsp + 0x48]
000062a4  48 8d 0c ca  lea rcx, [rdx + rcx*8]
000062a8  31 d2  xor edx, edx
000062aa  66 0f 1f 44 00 00  nop word ptr [rax + rax]
000062b0  f2 42 0f 10 3c 32  movsd xmm7, qword ptr [rdx + r14]
000062b6  f2 0f 11 3c 11  movsd qword ptr [rcx + rdx], xmm7
000062bb  48 83 c2 08  add rdx, 8
000062bf  48 83 fa 48  cmp rdx, 0x48
000062c3  75 eb  jne 0x1800062b0
000062c5  4b 8d 14 80  lea rdx, [r8 + r8*4]
000062c9  49 8d 0c 50  lea rcx, [r8 + rdx*2]
000062cd  4c 8b 9c 24 a8 00 00 00  mov r11, qword ptr [rsp + 0xa8]
000062d5  4c 01 d9  add rcx, r11
000062d8  66 0f 2e 44 cf a8  ucomisd xmm0, qword ptr [rdi + rcx*8 - 0x58]
000062de  0f 9b c1  setnp cl
000062e1  41 0f 94 c1  sete r9b
000062e5  4d 85 db  test r11, r11
000062e8  4c 8d 1d b1 17 01 00  lea r11, [rip + 0x117b1]
000062ef  74 35  je 0x180006326
000062f1  41 20 c9  and r9b, cl
000062f4  74 30  je 0x180006326
000062f6  49 6b c8 58  imul rcx, r8, 0x58
000062fa  48 03 4c 24 40  add rcx, qword ptr [rsp + 0x40]
000062ff  45 31 c9  xor r9d, r9d
00006302  66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00006310  f2 43 0f 10 3c 19  movsd xmm7, qword ptr [r9 + r11]
00006316  f2 42 0f 11 3c 09  movsd qword ptr [rcx + r9], xmm7
0000631c  49 83 c1 08  add r9, 8
00006320  49 83 f9 58  cmp r9, 0x58
00006324  75 ea  jne 0x180006310
00006326  4c 8b 9c 24 98 00 00 00  mov r11, qword ptr [rsp + 0x98]
0000632e  49 8d 0c 13  lea rcx, [r11 + rdx]
00006332  48 83 c1 fb  add rcx, -5
00006336  66 0f 2e 04 cf  ucomisd xmm0, qword ptr [rdi + rcx*8]
0000633b  0f 9b c1  setnp cl
0000633e  41 0f 94 c1  sete r9b
00006342  4d 85 db  test r11, r11
00006345  74 2f  je 0x180006376
00006347  41 20 c9  and r9b, cl
0000634a  74 2a  je 0x180006376
0000634c  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
00006351  48 8d 0c d1  lea rcx, [rcx + rdx*8]
00006355  45 31 c9  xor r9d, r9d
00006358  0f 1f 84 00 00 00 00 00  nop dword ptr [rax + rax]
00006360  f2 43 0f 10 3c 21  movsd xmm7, qword ptr [r9 + r12]
00006366  f2 42 0f 11 3c 09  movsd qword ptr [rcx + r9], xmm7
0000636c  49 83 c1 08  add r9, 8
00006370  49 83 f9 28  cmp r9, 0x28
00006374  75 ea  jne 0x180006360
00006376  4b 8d 0c 80  lea rcx, [r8 + r8*4]
0000637a  48 83 c1 fb  add rcx, -5
0000637e  4c 8b 9c 24 90 00 00 00  mov r11, qword ptr [rsp + 0x90]
00006386  4c 01 d9  add rcx, r11
00006389  66 0f 2e 04 cf  ucomisd xmm0, qword ptr [rdi + rcx*8]
0000638e  0f 9b c1  setnp cl
00006391  41 0f 94 c1  sete r9b
00006395  4d 85 db  test r11, r11
00006398  74 2c  je 0x1800063c6
0000639a  41 20 c9  and r9b, cl
0000639d  74 27  je 0x1800063c6
0000639f  48 8b 4c 24 30  mov rcx, qword ptr [rsp + 0x30]
000063a4  48 8d 0c d1  lea rcx, [rcx + rdx*8]
000063a8  45 31 c9  xor r9d, r9d
000063ab  0f 1f 44 00 00  nop dword ptr [rax + rax]
000063b0  f2 43 0f 10 3c 29  movsd xmm7, qword ptr [r9 + r13]
000063b6  f2 42 0f 11 3c 09  movsd qword ptr [rcx + r9], xmm7
000063bc  49 83 c1 08  add r9, 8
000063c0  49 83 f9 28  cmp r9, 0x28
000063c4  75 ea  jne 0x1800063b0
000063c6  4c 8b 9c 24 a0 00 00 00  mov r11, qword ptr [rsp + 0xa0]
000063ce  4b 8d 0c c3  lea rcx, [r11 + r8*8]
000063d2  66 0f 2e 44 cf c0  ucomisd xmm0, qword ptr [rdi + rcx*8 - 0x40]
000063d8  0f 9b c1  setnp cl
000063db  41 0f 94 c1  sete r9b
000063df  4d 85 db  test r11, r11
000063e2  74 32  je 0x180006416
000063e4  41 20 c9  and r9b, cl
000063e7  74 2d  je 0x180006416
000063e9  4c 89 c1  mov rcx, r8
000063ec  48 c1 e1 06  shl rcx, 6
000063f0  48 03 4c 24 28  add rcx, qword ptr [rsp + 0x28]
000063f5  45 31 c9  xor r9d, r9d
000063f8  0f 1f 84 00 00 00 00 00  nop dword ptr [rax + rax]
00006400  f2 41 0f 10 3c 29  movsd xmm7, qword ptr [r9 + rbp]
00006406  f2 42 0f 11 3c 09  movsd qword ptr [rcx + r9], xmm7
0000640c  49 83 c1 08  add r9, 8
00006410  49 83 f9 40  cmp r9, 0x40
00006414  75 ea  jne 0x180006400
00006416  4a 8d 0c c5 00 00 00 00  lea rcx, [r8*8]
0000641e  4c 29 c1  sub rcx, r8
00006421  48 8b 9c 24 88 00 00 00  mov rbx, qword ptr [rsp + 0x88]
00006429  4c 8d 0c 19  lea r9, [rcx + rbx]
0000642d  66 42 0f 2e 44 cf c8  ucomisd xmm0, qword ptr [rdi + r9*8 - 0x38]
00006434  41 0f 9b c1  setnp r9b
00006438  41 0f 94 c3  sete r11b
0000643c  48 85 db  test rbx, rbx
0000643f  74 35  je 0x180006476
00006441  45 20 cb  and r11b, r9b
00006444  74 30  je 0x180006476
00006446  4d 6b c8 38  imul r9, r8, 0x38
0000644a  4c 03 4c 24 20  add r9, qword ptr [rsp + 0x20]
0000644f  45 31 db  xor r11d, r11d
00006452  66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00006460  f2 41 0f 10 3c 03  movsd xmm7, qword ptr [r11 + rax]
00006466  f2 43 0f 11 3c 19  movsd qword ptr [r9 + r11], xmm7
0000646c  49 83 c3 08  add r11, 8
00006470  49 83 fb 38  cmp r11, 0x38
00006474  75 ea  jne 0x180006460
00006476  4c 8b bc 24 80 00 00 00  mov r15, qword ptr [rsp + 0x80]
0000647e  4f 8d 0c 07  lea r9, [r15 + r8]
00006482  66 42 0f 2e 44 cf f8  ucomisd xmm0, qword ptr [rdi + r9*8 - 8]
00006489  41 0f 9b c3  setnp r11b
0000648d  0f 94 c3  sete bl
00006490  4d 85 ff  test r15, r15
00006493  74 14  je 0x1800064a9
00006495  44 20 db  and bl, r11b
00006498  74 0f  je 0x1800064a9
0000649a  49 bb 00 00 00 60 bc f4 28 40  movabs r11, 0x4028f4bc60000000
000064a4  4e 89 5c cf f8  mov qword ptr [rdi + r9*8 - 8], r11
000064a9  48 8b 5c 24 78  mov rbx, qword ptr [rsp + 0x78]
000064ae  4c 8d 0c 1a  lea r9, [rdx + rbx]
000064b2  66 42 0f 2e 44 cf d8  ucomisd xmm0, qword ptr [rdi + r9*8 - 0x28]
000064b9  41 0f 9b c1  setnp r9b
000064bd  41 0f 94 c3  sete r11b
000064c1  48 85 db  test rbx, rbx
000064c4  74 30  je 0x1800064f6
000064c6  45 20 cb  and r11b, r9b
000064c9  74 2b  je 0x1800064f6
000064cb  4c 8b 4c 24 18  mov r9, qword ptr [rsp + 0x18]
000064d0  49 8d 14 d1  lea rdx, [r9 + rdx*8]
000064d4  45 31 c9  xor r9d, r9d
000064d7  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
000064e0  f2 43 0f 10 3c 11  movsd xmm7, qword ptr [r9 + r10]
000064e6  f2 42 0f 11 3c 0a  movsd qword ptr [rdx + r9], xmm7
000064ec  49 83 c1 08  add r9, 8
000064f0  49 83 f9 28  cmp r9, 0x28
000064f4  75 ea  jne 0x1800064e0
000064f6  48 03 4c 24 58  add rcx, qword ptr [rsp + 0x58]
000064fb  66 0f 2e 04 cf  ucomisd xmm0, qword ptr [rdi + rcx*8]
00006500  0f 9b c1  setnp cl
00006503  0f 94 c2  sete dl
00006506  48 83 7c 24 60 00  cmp qword ptr [rsp + 0x60], 0
0000650c  74 26  je 0x180006534
0000650e  20 ca  and dl, cl
00006510  74 22  je 0x180006534
00006512  49 6b c8 38  imul rcx, r8, 0x38
00006516  48 03 4c 24 10  add rcx, qword ptr [rsp + 0x10]
0000651b  31 d2  xor edx, edx
0000651d  0f 1f 00  nop dword ptr [rax]
00006520  f2 0f 10 3c 32  movsd xmm7, qword ptr [rdx + rsi]
00006525  f2 0f 11 3c 11  movsd qword ptr [rcx + rdx], xmm7
0000652a  48 83 c2 08  add rdx, 8
0000652e  48 83 fa 38  cmp rdx, 0x38
00006532  75 ec  jne 0x180006520
00006534  4c 8b 4c 24 68  mov r9, qword ptr [rsp + 0x68]
00006539  4d 01 c8  add r8, r9
0000653c  66 42 0f 2e 44 c7 f8  ucomisd xmm0, qword ptr [rdi + r8*8 - 8]
00006543  0f 9b c1  setnp cl
00006546  0f 94 c2  sete dl
00006549  4d 85 c9  test r9, r9
0000654c  4c 8b 8c 24 28 01 00 00  mov r9, qword ptr [rsp + 0x128]
00006554  0f 84 86 f9 ff ff  je 0x180005ee0
0000655a  20 ca  and dl, cl
0000655c  0f 84 7e f9 ff ff  je 0x180005ee0
00006562  48 b9 00 00 00 c0 65 9e 5d c1  movabs rcx, 0xc15d9e65c0000000
0000656c  4a 89 4c c7 f8  mov qword ptr [rdi + r8*8 - 8], rcx
00006571  e9 6a f9 ff ff  jmp 0x180005ee0
00006576  0f 28 b4 24 30 01 00 00  movaps xmm6, xmmword ptr [rsp + 0x130]
0000657e  0f 28 bc 24 40 01 00 00  movaps xmm7, xmmword ptr [rsp + 0x140]
00006586  44 0f 28 84 24 50 01 00 00  movaps xmm8, xmmword ptr [rsp + 0x150]
0000658f  48 81 c4 68 01 00 00  add rsp, 0x168
00006596  5b  pop rbx
00006597  5d  pop rbp
00006598  5f  pop rdi
00006599  5e  pop rsi
0000659a  41 5c  pop r12
0000659c  41 5d  pop r13
0000659e  41 5e  pop r14
000065a0  41 5f  pop r15
000065a2  c3  ret
; owner 0x65b0 PPEXEC_INTPP
000065b0  41 57  push r15
000065b2  41 56  push r14
000065b4  41 55  push r13
000065b6  41 54  push r12
000065b8  56  push rsi
000065b9  57  push rdi
000065ba  55  push rbp
000065bb  53  push rbx
000065bc  48 81 ec d8 00 00 00  sub rsp, 0xd8
000065c3  0f 29 b4 24 c0 00 00 00  movaps xmmword ptr [rsp + 0xc0], xmm6
000065cb  4d 89 c6  mov r14, r8
000065ce  48 89 d7  mov rdi, rdx
000065d1  49 89 cf  mov r15, rcx
000065d4  48 8b b4 24 48 01 00 00  mov rsi, qword ptr [rsp + 0x148]
000065dc  48 8b 9c 24 40 01 00 00  mov rbx, qword ptr [rsp + 0x140]
000065e4  48 8d 0d fd 9b 01 00  lea rcx, [rip + 0x19bfd]
000065eb  e8 c0 ae 00 00  call 0x1800114b0
000065f0  48 c7 06 00 00 00 00  mov qword ptr [rsi], 0
000065f7  4c 8b 25 02 ef 00 00  mov r12, qword ptr [rip + 0xef02]
000065fe  49 c7 84 24 b8 01 00 00 ff ff ff ff  mov qword ptr [r12 + 0x1b8], 0xffffffffffffffff
0000660a  48 8b 05 ef eb 00 00  mov rax, qword ptr [rip + 0xebef]
00006611  48 c7 00 00 00 00 00  mov qword ptr [rax], 0
00006618  48 8b 35 b9 ee 00 00  mov rsi, qword ptr [rip + 0xeeb9]
0000661f  48 c7 86 58 01 00 00 00 00 00 00  mov qword ptr [rsi + 0x158], 0
0000662a  48 8b 05 67 f6 00 00  mov rax, qword ptr [rip + 0xf667]
00006631  48 c7 80 60 01 00 00 00 00 00 00  mov qword ptr [rax + 0x160], 0
0000663c  e8 81 ae 00 00  call 0x1800114c2
00006641  e8 9c af 00 00  call 0x1800115e2
00006646  48 c7 86 b0 00 00 00 09 00 00 00  mov qword ptr [rsi + 0xb0], 9
00006651  48 8b 35 18 ed 00 00  mov rsi, qword ptr [rip + 0xed18]
00006658  48 8b 06  mov rax, qword ptr [rsi]
0000665b  48 89 05 ae 9e 01 00  mov qword ptr [rip + 0x19eae], rax
00006662  48 8d 0d 3f 15 01 00  lea rcx, [rip + 0x1153f]
00006669  e8 5a ae 00 00  call 0x1800114c8
0000666e  48 8d 0d a3 15 01 00  lea rcx, [rip + 0x115a3]
00006675  e8 4e ae 00 00  call 0x1800114c8
0000667a  48 8b 05 8f 9e 01 00  mov rax, qword ptr [rip + 0x19e8f]
00006681  48 89 06  mov qword ptr [rsi], rax
00006684  4c 8b 2d 8d eb 00 00  mov r13, qword ptr [rip + 0xeb8d]
0000668b  49 c7 45 00 00 00 00 00  mov qword ptr [r13], 0
00006693  48 8b 05 e6 f5 00 00  mov rax, qword ptr [rip + 0xf5e6]
0000669a  48 c7 80 d8 01 00 00 00 00 00 00  mov qword ptr [rax + 0x1d8], 0
000066a5  0f 57 c0  xorps xmm0, xmm0
000066a8  41 0f 11 84 24 58 01 00 00  movups xmmword ptr [r12 + 0x158], xmm0
000066b1  49 c7 84 24 b0 00 00 00 00 00 00 00  mov qword ptr [r12 + 0xb0], 0
000066bd  49 c7 84 24 a0 00 00 00 00 00 00 00  mov qword ptr [r12 + 0xa0], 0
000066c9  49 c7 84 24 98 00 00 00 01 00 00 00  mov qword ptr [r12 + 0x98], 1
000066d5  49 c7 44 24 58 01 00 00 00  mov qword ptr [r12 + 0x58], 1
000066de  49 c7 44 24 50 00 00 00 00  mov qword ptr [r12 + 0x50], 0
000066e7  49 c7 84 24 c0 01 00 00 00 00 00 00  mov qword ptr [r12 + 0x1c0], 0
000066f3  b9 01 00 00 00  mov ecx, 1
000066f8  48 8b 15 21 eb 00 00  mov rdx, qword ptr [rip + 0xeb21]
000066ff  90  nop
00006700  49 c7 c0 a0 ff ff ff  mov r8, 0xffffffffffffffa0
00006707  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00006710  4a c7 44 02 60 00 00 00 00  mov qword ptr [rdx + r8 + 0x60], 0
00006719  49 83 c0 20  add r8, 0x20
0000671d  75 f1  jne 0x180006710
0000671f  48 ff c1  inc rcx
00006722  48 83 c2 08  add rdx, 8
00006726  48 83 f9 05  cmp rcx, 5
0000672a  75 d4  jne 0x180006700
0000672c  48 c7 05 f9 9f 01 00 05 00 00 00  mov qword ptr [rip + 0x19ff9], 5
00006737  48 8b 0d e2 ea 00 00  mov rcx, qword ptr [rip + 0xeae2]
0000673e  48 c7 41 60 00 00 00 00  mov qword ptr [rcx + 0x60], 0
00006746  49 c7 44 24 78 fe 00 00 00  mov qword ptr [r12 + 0x78], 0xfe
0000674f  49 c7 84 24 d0 01 00 00 00 00 00 00  mov qword ptr [r12 + 0x1d0], 0
0000675b  48 c7 40 20 00 00 00 00  mov qword ptr [rax + 0x20], 0
00006763  48 c7 05 32 9a 01 00 00 00 00 00  mov qword ptr [rip + 0x19a32], 0
0000676e  48 8b 35 83 ed 00 00  mov rsi, qword ptr [rip + 0xed83]
00006775  48 89 f1  mov rcx, rsi
00006778  48 89 f2  mov rdx, rsi
0000677b  49 89 f0  mov r8, rsi
0000677e  e8 57 b3 00 00  call 0x180011ada
00006783  48 c7 05 32 b8 01 00 01 00 00 00  mov qword ptr [rip + 0x1b832], 1
0000678e  48 8b 05 1b ee 00 00  mov rax, qword ptr [rip + 0xee1b]
00006795  48 b9 fe d4 78 e9 26 b9 54 40  movabs rcx, 0x4054b926e978d4fe
0000679f  48 89 08  mov qword ptr [rax], rcx
000067a2  48 ba e3 20 79 cf f9 12 68 47  movabs rdx, 0x476812f9cf7920e3
000067ac  48 89 50 08  mov qword ptr [rax + 8], rdx
000067b0  48 ba 72 2e 2d 93 84 44 75 38  movabs rdx, 0x38754484932d2e72
000067ba  48 89 50 10  mov qword ptr [rax + 0x10], rdx
000067be  48 ba 00 00 00 00 00 88 c3 40  movabs rdx, 0x40c3880000000000
000067c8  48 89 50 18  mov qword ptr [rax + 0x18], rdx
000067cc  48 ba 00 00 00 00 00 00 24 40  movabs rdx, 0x4024000000000000
000067d6  48 89 50 20  mov qword ptr [rax + 0x20], rdx
000067da  48 ba 00 00 00 a2 94 1a 6d 42  movabs rdx, 0x426d1a94a2000000
000067e4  48 89 50 28  mov qword ptr [rax + 0x28], rdx
000067e8  48 89 48 30  mov qword ptr [rax + 0x30], rcx
000067ec  48 b9 0f 7a f8 b7 a5 95 aa 38  movabs rcx, 0x38aa95a5b7f87a0f
000067f6  48 89 48 38  mov qword ptr [rax + 0x38], rcx
000067fa  48 ba be 30 99 2a 18 95 84 bf  movabs rdx, 0xbf8495182a9930be
00006804  48 89 50 40  mov qword ptr [rax + 0x40], rdx
00006808  48 89 48 48  mov qword ptr [rax + 0x48], rcx
0000680c  48 8b 0d 15 f4 00 00  mov rcx, qword ptr [rip + 0xf415]
00006813  48 b8 3a 8c 30 e2 8e 79 45 3e  movabs rax, 0x3e45798ee2308c3a
0000681d  48 89 01  mov qword ptr [rcx], rax
00006820  0f 57 c0  xorps xmm0, xmm0
00006823  48 8b 05 06 f4 00 00  mov rax, qword ptr [rip + 0xf406]
0000682a  0f 29 00  movaps xmmword ptr [rax], xmm0
0000682d  48 b8 9a 99 99 99 99 99 b9 3f  movabs rax, 0x3fb999999999999a
00006837  48 89 41 08  mov qword ptr [rcx + 8], rax
0000683b  48 c7 05 1a 97 01 00 01 00 00 00  mov qword ptr [rip + 0x1971a], 1
00006846  4c 8b 25 93 ec 00 00  mov r12, qword ptr [rip + 0xec93]
0000684d  49 c7 44 24 50 00 00 00 00  mov qword ptr [r12 + 0x50], 0
00006856  49 c7 44 24 60 01 00 00 00  mov qword ptr [r12 + 0x60], 1
0000685f  49 c7 44 24 68 02 00 00 00  mov qword ptr [r12 + 0x68], 2
00006868  49 c7 44 24 70 01 00 00 00  mov qword ptr [r12 + 0x70], 1
00006871  48 b8 5c 8f c2 f5 28 5c ef 3f  movabs rax, 0x3fef5c28f5c28f5c
0000687b  49 89 44 24 18  mov qword ptr [r12 + 0x18], rax
00006880  49 c7 84 24 80 00 00 00 01 00 00 00  mov qword ptr [r12 + 0x80], 1
0000688c  49 c7 84 24 90 00 00 00 01 00 00 00  mov qword ptr [r12 + 0x90], 1
00006898  49 c7 84 24 d0 4e 00 00 01 00 00 00  mov qword ptr [r12 + 0x4ed0], 1
000068a4  48 b8 66 66 66 66 66 a2 72 40  movabs rax, 0x4072a26666666666
000068ae  49 89 44 24 28  mov qword ptr [r12 + 0x28], rax
000068b3  48 b8 00 00 00 00 d0 bc f8 40  movabs rax, 0x40f8bcd000000000
000068bd  49 89 44 24 30  mov qword ptr [r12 + 0x30], rax
000068c2  49 c7 84 24 38 4f 00 00 01 00 00 00  mov qword ptr [r12 + 0x4f38], 1
000068ce  48 8b 05 43 f0 00 00  mov rax, qword ptr [rip + 0xf043]
000068d5  48 c7 00 00 00 00 00  mov qword ptr [rax], 0
000068dc  48 8b 0d f5 eb 00 00  mov rcx, qword ptr [rip + 0xebf5]
000068e3  48 c7 81 58 02 00 00 00 00 00 00  mov qword ptr [rcx + 0x258], 0
000068ee  48 c7 05 67 b7 01 00 00 00 00 00  mov qword ptr [rip + 0x1b767], 0
000068f9  48 8b 05 18 ed 00 00  mov rax, qword ptr [rip + 0xed18]
00006900  0f 29 40 30  movaps xmmword ptr [rax + 0x30], xmm0
00006904  48 8b 05 8d ec 00 00  mov rax, qword ptr [rip + 0xec8d]
0000690b  48 c7 80 c0 00 00 00 00 00 00 00  mov qword ptr [rax + 0xc0], 0
00006916  48 8b 05 1b f3 00 00  mov rax, qword ptr [rip + 0xf31b]
0000691d  48 c7 40 40 00 00 00 00  mov qword ptr [rax + 0x40], 0
00006925  0f 28 49 40  movaps xmm1, xmmword ptr [rcx + 0x40]
00006929  0f 11 48 58  movups xmmword ptr [rax + 0x58], xmm1
0000692d  49 81 bc 24 00 4f 00 00 83 1f 00 00  cmp qword ptr [r12 + 0x4f00], 0x1f83
00006939  74 0c  je 0x180006947
0000693b  49 c7 84 24 00 4f 00 00 00 00 00 00  mov qword ptr [r12 + 0x4f00], 0
00006947  49 c7 84 24 30 4f 00 00 00 00 00 00  mov qword ptr [r12 + 0x4f30], 0
00006953  0f 29 05 76 96 01 00  movaps xmmword ptr [rip + 0x19676], xmm0
0000695a  48 c7 05 7b 96 01 00 00 00 00 00  mov qword ptr [rip + 0x1967b], 0
00006965  48 8b 05 7c eb 00 00  mov rax, qword ptr [rip + 0xeb7c]
0000696c  f2 0f 10 00  movsd xmm0, qword ptr [rax]
00006970  48 8b 05 f9 ee 00 00  mov rax, qword ptr [rip + 0xeef9]
00006977  f2 0f 11 00  movsd qword ptr [rax], xmm0
0000697b  48 c7 40 08 00 00 00 00  mov qword ptr [rax + 8], 0
00006983  48 8b 2d 9e e8 00 00  mov rbp, qword ptr [rip + 0xe89e]
0000698a  48 8b 45 18  mov rax, qword ptr [rbp + 0x18]
0000698e  48 8b 4d 38  mov rcx, qword ptr [rbp + 0x38]
00006992  ba 01 00 00 00  mov edx, 1
00006997  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
000069a0  48 89 54 d5 f8  mov qword ptr [rbp + rdx*8 - 8], rdx
000069a5  48 ff c2  inc rdx
000069a8  48 83 fa 25  cmp rdx, 0x25
000069ac  75 f2  jne 0x1800069a0
000069ae  48 c7 05 77 9d 01 00 25 00 00 00  mov qword ptr [rip + 0x19d77], 0x25
000069b9  48 c7 45 00 05 00 00 00  mov qword ptr [rbp], 5
000069c1  48 c7 45 40 00 00 00 00  mov qword ptr [rbp + 0x40], 0
000069c9  48 89 45 18  mov qword ptr [rbp + 0x18], rax
000069cd  48 89 4d 38  mov qword ptr [rbp + 0x38], rcx
000069d1  48 c7 45 30 15 00 00 00  mov qword ptr [rbp + 0x30], 0x15
000069d9  48 c7 45 50 1e 00 00 00  mov qword ptr [rbp + 0x50], 0x1e
000069e1  49 8b 07  mov rax, qword ptr [r15]
000069e4  48 89 45 60  mov qword ptr [rbp + 0x60], rax
000069e8  49 8b 06  mov rax, qword ptr [r14]
000069eb  48 89 45 68  mov qword ptr [rbp + 0x68], rax
000069ef  48 c7 85 90 00 00 00 21 00 00 00  mov qword ptr [rbp + 0x90], 0x21
000069fa  48 c7 85 98 00 00 00 22 00 00 00  mov qword ptr [rbp + 0x98], 0x22
00006a05  48 c7 85 e0 00 00 00 20 00 00 00  mov qword ptr [rbp + 0xe0], 0x20
00006a10  48 c7 85 f8 00 00 00 30 00 00 00  mov qword ptr [rbp + 0xf8], 0x30
00006a1b  48 c7 85 00 01 00 00 13 00 00 00  mov qword ptr [rbp + 0x100], 0x13
00006a26  48 c7 85 08 01 00 00 14 00 00 00  mov qword ptr [rbp + 0x108], 0x14
00006a31  48 c7 85 10 01 00 00 12 00 00 00  mov qword ptr [rbp + 0x110], 0x12
00006a3c  48 8b 07  mov rax, qword ptr [rdi]
00006a3f  48 89 85 18 01 00 00  mov qword ptr [rbp + 0x118], rax
00006a46  0f 57 c0  xorps xmm0, xmm0
00006a49  41 0f 29 45 00  movaps xmmword ptr [r13], xmm0
00006a4e  49 c7 45 10 00 00 00 00  mov qword ptr [r13 + 0x10], 0
00006a56  48 8b 05 0b ea 00 00  mov rax, qword ptr [rip + 0xea0b]
00006a5d  48 c7 40 10 dd dd dd dd  mov qword ptr [rax + 0x10], 0xffffffffdddddddd
00006a65  0f 29 00  movaps xmmword ptr [rax], xmm0
00006a68  48 b9 82 4d c7 72 61 42 33 47  movabs rcx, 0x4733426172c74d82
00006a72  48 89 48 18  mov qword ptr [rax + 0x18], rcx
00006a76  48 8b 05 e3 f1 00 00  mov rax, qword ptr [rip + 0xf1e3]
00006a7d  0f 29 00  movaps xmmword ptr [rax], xmm0
00006a80  48 c7 40 10 00 00 00 00  mov qword ptr [rax + 0x10], 0
00006a88  e8 53 aa 00 00  call 0x1800114e0
00006a8d  48 8b 0d 74 e9 00 00  mov rcx, qword ptr [rip + 0xe974]
00006a94  48 c7 81 80 00 00 00 00 e1 f5 05  mov qword ptr [rcx + 0x80], 0x5f5e100
00006a9f  48 c7 41 30 ff e0 f5 05  mov qword ptr [rcx + 0x30], 0x5f5e0ff
00006aa7  48 8b 05 8a e7 00 00  mov rax, qword ptr [rip + 0xe78a]
00006aae  48 c7 40 20 ff e0 f5 05  mov qword ptr [rax + 0x20], 0x5f5e0ff
00006ab6  48 8b 05 83 e7 00 00  mov rax, qword ptr [rip + 0xe783]
00006abd  48 c7 00 01 00 00 00  mov qword ptr [rax], 1
00006ac4  48 c7 41 60 10 27 00 00  mov qword ptr [rcx + 0x60], 0x2710
00006acc  48 c7 41 68 a0 86 01 00  mov qword ptr [rcx + 0x68], 0x186a0
00006ad4  48 8b 0d fd e9 00 00  mov rcx, qword ptr [rip + 0xe9fd]
00006adb  48 c7 41 30 04 00 00 00  mov qword ptr [rcx + 0x30], 4
00006ae3  48 8b 45 60  mov rax, qword ptr [rbp + 0x60]
00006ae7  48 89 41 20  mov qword ptr [rcx + 0x20], rax
00006aeb  48 8d 3d 56 97 01 00  lea rdi, [rip + 0x19756]
00006af2  ba ff 00 00 00  mov edx, 0xff
00006af7  48 89 f9  mov rcx, rdi
00006afa  e8 f3 a9 00 00  call 0x1800114f2
00006aff  ba ff 00 00 00  mov edx, 0xff
00006b04  48 89 f9  mov rcx, rdi
00006b07  e8 3e a9 00 00  call 0x18001144a
00006b0c  48 01 f8  add rax, rdi
00006b0f  48 83 3d d1 96 01 00 02  cmp qword ptr [rip + 0x196d1], 2
00006b17  75 12  jne 0x180006b2b
00006b19  0f 28 05 70 10 01 00  movaps xmm0, xmmword ptr [rip + 0x11070]
00006b20  0f 11 00  movups xmmword ptr [rax], xmm0
00006b23  66 c7 40 10 64 66  mov word ptr [rax + 0x10], 0x6664
00006b29  eb 1b  jmp 0x180006b46
00006b2b  48 b9 66 66 69 6c 2e 73 64 66  movabs rcx, 0x6664732e6c696666
00006b35  48 89 48 07  mov qword ptr [rax + 7], rcx
00006b39  48 b9 2f 78 65 71 2f 73 64 66  movabs rcx, 0x6664732f7165782f
00006b43  48 89 08  mov qword ptr [rax], rcx
00006b46  48 8b 05 8b e6 00 00  mov rax, qword ptr [rip + 0xe68b]
00006b4d  48 83 b8 40 01 00 00 00  cmp qword ptr [rax + 0x140], 0
00006b55  4c 8d 2d 64 99 01 00  lea r13, [rip + 0x19964]
00006b5c  75 34  jne 0x180006b92
00006b5e  4c 89 6c 24 28  mov qword ptr [rsp + 0x28], r13
00006b63  4c 8d 05 86 10 01 00  lea r8, [rip + 0x11086]
00006b6a  4c 89 44 24 20  mov qword ptr [rsp + 0x20], r8
00006b6f  48 c7 44 24 30 ff 00 00 00  mov qword ptr [rsp + 0x30], 0xff
00006b78  48 8d 0d c9 96 01 00  lea rcx, [rip + 0x196c9]
00006b7f  48 8d 15 9a 10 01 00  lea rdx, [rip + 0x1109a]
00006b86  4c 8d 0d 8b 10 01 00  lea r9, [rip + 0x1108b]
00006b8d  e8 66 a9 00 00  call 0x1800114f8
00006b92  48 c7 05 63 99 01 00 01 00 00 00  mov qword ptr [rip + 0x19963], 1
00006b9d  4c 8d 05 5c 99 01 00  lea r8, [rip + 0x1995c]
00006ba4  48 c7 05 59 99 01 00 03 00 00 00  mov qword ptr [rip + 0x19959], 3
00006baf  48 8b 05 12 e8 00 00  mov rax, qword ptr [rip + 0xe812]
00006bb6  48 83 78 08 01  cmp qword ptr [rax + 8], 1
00006bbb  0f 94 c0  sete al
00006bbe  48 8b 1b  mov rbx, qword ptr [rbx]
00006bc1  48 81 fb 6f fe ff ff  cmp rbx, -0x191
00006bc8  0f 9c c1  setl cl
00006bcb  08 c1  or cl, al
00006bcd  0f b6 c1  movzx eax, cl
00006bd0  48 89 05 09 99 01 00  mov qword ptr [rip + 0x19909], rax
00006bd7  4c 8d 0d 02 99 01 00  lea r9, [rip + 0x19902]
00006bde  48 89 05 03 99 01 00  mov qword ptr [rip + 0x19903], rax
00006be5  4c 89 6c 24 28  mov qword ptr [rsp + 0x28], r13
00006bea  48 8d 3d ff 0f 01 00  lea rdi, [rip + 0x10fff]
00006bf1  48 89 7c 24 20  mov qword ptr [rsp + 0x20], rdi
00006bf6  48 c7 44 24 30 00 01 00 00  mov qword ptr [rsp + 0x30], 0x100
00006bff  41 be 00 18 00 00  mov r14d, 0x1800
00006c05  4c 03 35 4c e6 00 00  add r14, qword ptr [rip + 0xe64c]
00006c0c  48 8d 15 0d 10 01 00  lea rdx, [rip + 0x1100d]
00006c13  4c 89 f1  mov rcx, r14
00006c16  e8 dd a8 00 00  call 0x1800114f8
00006c1b  48 89 f9  mov rcx, rdi
00006c1e  e8 31 a7 00 00  call 0x180011354
00006c23  48 89 05 fe 9a 01 00  mov qword ptr [rip + 0x19afe], rax
00006c2a  48 8b 8c c6 48 03 00 00  mov rcx, qword ptr [rsi + rax*8 + 0x348]
00006c32  48 8b 15 27 e6 00 00  mov rdx, qword ptr [rip + 0xe627]
00006c39  48 89 8a f0 00 00 00  mov qword ptr [rdx + 0xf0], rcx
00006c40  0f 10 84 c6 50 03 00 00  movups xmm0, xmmword ptr [rsi + rax*8 + 0x350]
00006c48  0f 11 82 f8 00 00 00  movups xmmword ptr [rdx + 0xf8], xmm0
00006c4f  48 8b 4c c6 18  mov rcx, qword ptr [rsi + rax*8 + 0x18]
00006c54  4c 8b 44 c6 70  mov r8, qword ptr [rsi + rax*8 + 0x70]
00006c59  48 89 4a 60  mov qword ptr [rdx + 0x60], rcx
00006c5d  0f 10 84 c6 18 06 00 00  movups xmm0, xmmword ptr [rsi + rax*8 + 0x618]
00006c65  0f 11 82 18 01 00 00  movups xmmword ptr [rdx + 0x118], xmm0
00006c6c  0f 10 84 c6 68 02 00 00  movups xmm0, xmmword ptr [rsi + rax*8 + 0x268]
00006c74  0f 29 42 20  movaps xmmword ptr [rdx + 0x20], xmm0
00006c78  4c 89 82 a0 00 00 00  mov qword ptr [rdx + 0xa0], r8
00006c7f  4c 8b 3d 82 e7 00 00  mov r15, qword ptr [rip + 0xe782]
00006c86  49 83 bf 88 20 00 00 00  cmp qword ptr [r15 + 0x2088], 0
00006c8e  0f 84 b7 01 00 00  je 0x180006e4b
00006c94  e8 71 a8 00 00  call 0x18001150a
00006c99  48 85 c0  test rax, rax
00006c9c  4c 8b 2d 35 e8 00 00  mov r13, qword ptr [rip + 0xe835]
00006ca3  0f 85 cc 00 00 00  jne 0x180006d75
00006ca9  48 89 7c 24 38  mov qword ptr [rsp + 0x38], rdi
00006cae  48 8d 15 63 0f 01 00  lea rdx, [rip + 0x10f63]
00006cb5  48 89 54 24 30  mov qword ptr [rsp + 0x30], rdx
00006cba  48 89 54 24 28  mov qword ptr [rsp + 0x28], rdx
00006cbf  49 8d 45 38  lea rax, [r13 + 0x38]
00006cc3  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00006cc8  4d 8d 4d 28  lea r9, [r13 + 0x28]
00006ccc  48 8d 0d cd 79 01 00  lea rcx, [rip + 0x179cd]
00006cd3  4c 8d 05 46 0f 01 00  lea r8, [rip + 0x10f46]
00006cda  e8 c9 a6 00 00  call 0x1800113a8
00006cdf  48 85 c0  test rax, rax
00006ce2  0f 84 8d 00 00 00  je 0x180006d75
00006ce8  48 c7 84 24 90 00 00 00 00 00 00 00  mov qword ptr [rsp + 0x90], 0
00006cf4  c7 44 24 4a 38 06 38 04  mov dword ptr [rsp + 0x4a], 0x4380638
00006cfc  66 c7 44 24 4e 01 00  mov word ptr [rsp + 0x4e], 1
00006d03  48 c7 44 24 68 20 03 00 00  mov qword ptr [rsp + 0x68], 0x320
00006d0c  48 8b 05 7d e7 00 00  mov rax, qword ptr [rip + 0xe77d]
00006d13  48 89 44 24 70  mov qword ptr [rsp + 0x70], rax
00006d18  48 c7 44 24 78 50 00 00 00  mov qword ptr [rsp + 0x78], 0x50
00006d21  48 c7 84 24 80 00 00 00 28 00 00 00  mov qword ptr [rsp + 0x80], 0x28
00006d2d  48 8d 05 1c 0e 01 00  lea rax, [rip + 0x10e1c]
00006d34  48 89 84 24 88 00 00 00  mov qword ptr [rsp + 0x88], rax
00006d3c  48 8d 05 fd 79 01 00  lea rax, [rip + 0x179fd]
00006d43  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00006d48  48 8d 8c 24 90 00 00 00  lea rcx, [rsp + 0x90]
00006d50  48 ba 00 ff 84 83 20 01 08 00  movabs rdx, 0x801208384ff00
00006d5a  4c 8d 44 24 4a  lea r8, [rsp + 0x4a]
00006d5f  4c 8d 4c 24 68  lea r9, [rsp + 0x68]
00006d64  e8 a1 ad 00 00  call 0x180011b0a
00006d69  48 8d 0d b0 0e 01 00  lea rcx, [rip + 0x10eb0]
00006d70  e8 3f a6 00 00  call 0x1800113b4
00006d75  e8 96 a7 00 00  call 0x180011510
00006d7a  48 8b 3d 57 e4 00 00  mov rdi, qword ptr [rip + 0xe457]
00006d81  48 c7 87 38 01 00 00 01 00 00 00  mov qword ptr [rdi + 0x138], 1
00006d8c  48 8d 0d 8d 0e 01 00  lea rcx, [rip + 0x10e8d]
00006d93  e8 bc a5 00 00  call 0x180011354
00006d98  48 8b 4c c6 f8  mov rcx, qword ptr [rsi + rax*8 - 8]
00006d9d  48 8b 14 c6  mov rdx, qword ptr [rsi + rax*8]
00006da1  4c 8b 35 60 e6 00 00  mov r14, qword ptr [rip + 0xe660]
00006da8  49 89 4e 50  mov qword ptr [r14 + 0x50], rcx
00006dac  49 89 56 28  mov qword ptr [r14 + 0x28], rdx
00006db0  48 8b 4c c6 08  mov rcx, qword ptr [rsi + rax*8 + 8]
00006db5  49 89 4e 40  mov qword ptr [r14 + 0x40], rcx
00006db9  48 8b 4c c6 10  mov rcx, qword ptr [rsi + rax*8 + 0x10]
00006dbe  49 89 4e 38  mov qword ptr [r14 + 0x38], rcx
00006dc2  48 8b 4c c6 18  mov rcx, qword ptr [rsi + rax*8 + 0x18]
00006dc7  49 89 4e 30  mov qword ptr [r14 + 0x30], rcx
00006dcb  48 8b 4c c6 20  mov rcx, qword ptr [rsi + rax*8 + 0x20]
00006dd0  49 89 4e 48  mov qword ptr [r14 + 0x48], rcx
00006dd4  0f 10 44 c6 28  movups xmm0, xmmword ptr [rsi + rax*8 + 0x28]
00006dd9  41 0f 29 06  movaps xmmword ptr [r14], xmm0
00006ddd  48 8b 4c c6 40  mov rcx, qword ptr [rsi + rax*8 + 0x40]
00006de2  49 89 4e 20  mov qword ptr [r14 + 0x20], rcx
00006de6  48 8b 4c c6 48  mov rcx, qword ptr [rsi + rax*8 + 0x48]
00006deb  49 89 4e 70  mov qword ptr [r14 + 0x70], rcx
00006def  48 8b 0d 82 e4 00 00  mov rcx, qword ptr [rip + 0xe482]
00006df6  0f 10 84 c6 98 00 00 00  movups xmm0, xmmword ptr [rsi + rax*8 + 0x98]
00006dfe  0f 10 8c c6 a8 00 00 00  movups xmm1, xmmword ptr [rsi + rax*8 + 0xa8]
00006e06  0f 10 94 c6 b8 00 00 00  movups xmm2, xmmword ptr [rsi + rax*8 + 0xb8]
00006e0e  0f 10 9c c6 c8 00 00 00  movups xmm3, xmmword ptr [rsi + rax*8 + 0xc8]
00006e16  0f 11 81 98 00 00 00  movups xmmword ptr [rcx + 0x98], xmm0
00006e1d  0f 11 89 a8 00 00 00  movups xmmword ptr [rcx + 0xa8], xmm1
00006e24  0f 11 91 b8 00 00 00  movups xmmword ptr [rcx + 0xb8], xmm2
00006e2b  0f 11 99 c8 00 00 00  movups xmmword ptr [rcx + 0xc8], xmm3
00006e32  49 8b 86 88 20 00 00  mov rax, qword ptr [r14 + 0x2088]
00006e39  48 83 f8 02  cmp rax, 2
00006e3d  4c 8b 3d a4 e6 00 00  mov r15, qword ptr [rip + 0xe6a4]
00006e44  75 5b  jne 0x180006ea1
00006e46  e9 65 19 00 00  jmp 0x1800087b0
00006e4b  4c 89 6c 24 28  mov qword ptr [rsp + 0x28], r13
00006e50  48 8d 05 c1 0d 01 00  lea rax, [rip + 0x10dc1]
00006e57  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00006e5c  48 c7 44 24 30 00 01 00 00  mov qword ptr [rsp + 0x30], 0x100
00006e65  48 8d 15 b4 0d 01 00  lea rdx, [rip + 0x10db4]
00006e6c  4c 8d 05 3d 0d 01 00  lea r8, [rip + 0x10d3d]
00006e73  4c 8d 0d 76 0d 01 00  lea r9, [rip + 0x10d76]
00006e7a  4c 89 f1  mov rcx, r14
00006e7d  e8 76 a6 00 00  call 0x1800114f8
00006e82  49 8b 87 88 20 00 00  mov rax, qword ptr [r15 + 0x2088]
00006e89  4c 8b 2d 48 e6 00 00  mov r13, qword ptr [rip + 0xe648]
00006e90  4d 89 fe  mov r14, r15
00006e93  4c 8b 3d 4e e6 00 00  mov r15, qword ptr [rip + 0xe64e]
00006e9a  48 8b 3d 37 e3 00 00  mov rdi, qword ptr [rip + 0xe337]
00006ea1  48 8b 0d 20 e5 00 00  mov rcx, qword ptr [rip + 0xe520]
00006ea8  48 8b 49 08  mov rcx, qword ptr [rcx + 8]
00006eac  48 89 da  mov rdx, rbx
00006eaf  48 f7 da  neg rdx
00006eb2  48 0f 48 d3  cmovs rdx, rbx
00006eb6  45 31 c0  xor r8d, r8d
00006eb9  48 81 fa 92 01 00 00  cmp rdx, 0x192
00006ec0  41 0f 92 c0  setb r8b
00006ec4  48 83 f9 01  cmp rcx, 1
00006ec8  4b 8d 54 40 01  lea rdx, [r8 + r8*2 + 1]
00006ecd  48 0f 44 d1  cmove rdx, rcx
00006ed1  48 85 c0  test rax, rax
00006ed4  b8 01 00 00 00  mov eax, 1
00006ed9  48 0f 44 c2  cmove rax, rdx
00006edd  48 89 47 30  mov qword ptr [rdi + 0x30], rax
00006ee1  48 8d 0d 08 0d 01 00  lea rcx, [rip + 0x10d08]
00006ee8  e8 67 a4 00 00  call 0x180011354
00006eed  48 89 05 34 98 01 00  mov qword ptr [rip + 0x19834], rax
00006ef4  48 8b 84 c6 30 06 00 00  mov rax, qword ptr [rsi + rax*8 + 0x630]
00006efc  48 89 05 1d 98 01 00  mov qword ptr [rip + 0x1981d], rax
00006f03  49 8b 8e 80 00 00 00  mov rcx, qword ptr [r14 + 0x80]
00006f0a  48 89 c2  mov rdx, rax
00006f0d  48 09 ca  or rdx, rcx
00006f10  48 c1 ea 20  shr rdx, 0x20
00006f14  0f 84 22 02 00 00  je 0x18000713c
00006f1a  48 99  cqo
00006f1c  48 f7 f9  idiv rcx
00006f1f  48 83 fa 03  cmp rdx, 3
00006f23  0f 85 21 02 00 00  jne 0x18000714a
00006f29  48 8d 0d f0 97 01 00  lea rcx, [rip + 0x197f0]
00006f30  e8 1f a4 00 00  call 0x180011354
00006f35  48 89 05 dc 97 01 00  mov qword ptr [rip + 0x197dc], rax
00006f3c  e8 87 ab 00 00  call 0x180011ac8
00006f41  e8 88 ab 00 00  call 0x180011ace
00006f46  48 89 05 a3 92 01 00  mov qword ptr [rip + 0x192a3], rax
00006f4d  48 8d 0d 9c 92 01 00  lea rcx, [rip + 0x1929c]
00006f54  e8 7b ab 00 00  call 0x180011ad4
00006f59  48 8b 05 b8 97 01 00  mov rax, qword ptr [rip + 0x197b8]
00006f60  48 8b 84 c6 70 01 00 00  mov rax, qword ptr [rsi + rax*8 + 0x170]
00006f68  48 89 05 e1 94 01 00  mov qword ptr [rip + 0x194e1], rax
00006f6f  48 85 c0  test rax, rax
00006f72  0f 8e 9e 00 00 00  jle 0x180007016
00006f78  48 8d 0d d1 94 01 00  lea rcx, [rip + 0x194d1]
00006f7f  e8 d0 a3 00 00  call 0x180011354
00006f84  48 8b 3d 6d e5 00 00  mov rdi, qword ptr [rip + 0xe56d]
00006f8b  48 8b 44 c7 08  mov rax, qword ptr [rdi + rax*8 + 8]
00006f90  48 89 05 b1 94 01 00  mov qword ptr [rip + 0x194b1], rax
00006f97  48 85 c0  test rax, rax
00006f9a  7e 7a  jle 0x180007016
00006f9c  48 8d 0d a5 94 01 00  lea rcx, [rip + 0x194a5]
00006fa3  e8 ac a3 00 00  call 0x180011354
00006fa8  48 03 44 c7 f8  add rax, qword ptr [rdi + rax*8 - 8]
00006fad  48 8d 14 c7  lea rdx, [rdi + rax*8]
00006fb1  48 c7 44 24 20 ff 00 00 00  mov qword ptr [rsp + 0x20], 0xff
00006fba  48 8d 0d f7 0b 01 00  lea rcx, [rip + 0x10bf7]
00006fc1  4c 8d 05 78 92 01 00  lea r8, [rip + 0x19278]
00006fc8  48 8d 3d 78 93 01 00  lea rdi, [rip + 0x19378]
00006fcf  49 89 f9  mov r9, rdi
00006fd2  e8 45 a5 00 00  call 0x18001151c
00006fd7  48 8b 1d 7a e2 00 00  mov rbx, qword ptr [rip + 0xe27a]
00006fde  48 8d 8b 00 49 00 00  lea rcx, [rbx + 0x4900]
00006fe5  41 b8 ff 00 00 00  mov r8d, 0xff
00006feb  48 89 fa  mov rdx, rdi
00006fee  e8 2d 1d 00 00  call 0x180008d20
00006ff3  c6 83 ff 49 00 00 20  mov byte ptr [rbx + 0x49ff], 0x20
00006ffa  48 8d 8b 00 55 00 00  lea rcx, [rbx + 0x5500]
00007001  41 b8 ff 00 00 00  mov r8d, 0xff
00007007  48 89 fa  mov rdx, rdi
0000700a  e8 11 1d 00 00  call 0x180008d20
0000700f  c6 83 ff 55 00 00 20  mov byte ptr [rbx + 0x55ff], 0x20
00007016  48 8b 0d fb 96 01 00  mov rcx, qword ptr [rip + 0x196fb]
0000701d  48 c7 84 ce c8 00 00 00 00 00 00 00  mov qword ptr [rsi + rcx*8 + 0xc8], 0
00007029  48 8b 84 ce a8 00 00 00  mov rax, qword ptr [rsi + rcx*8 + 0xa8]
00007031  4d 8b 86 80 00 00 00  mov r8, qword ptr [r14 + 0x80]
00007038  48 89 c2  mov rdx, rax
0000703b  4c 09 c2  or rdx, r8
0000703e  48 c1 ea 20  shr rdx, 0x20
00007042  0f 84 16 01 00 00  je 0x18000715e
00007048  48 99  cqo
0000704a  49 f7 f8  idiv r8
0000704d  48 83 f8 04  cmp rax, 4
00007051  75 13  jne 0x180007066
00007053  48 8b 05 9e e4 00 00  mov rax, qword ptr [rip + 0xe49e]
0000705a  48 c7 84 c8 a8 00 00 00 00 00 00 00  mov qword ptr [rax + rcx*8 + 0xa8], 0
00007066  48 8d 0d 83 0b 01 00  lea rcx, [rip + 0x10b83]
0000706d  e8 e2 a2 00 00  call 0x180011354
00007072  48 89 05 af 96 01 00  mov qword ptr [rip + 0x196af], rax
00007079  48 8b 84 c6 f0 04 00 00  mov rax, qword ptr [rsi + rax*8 + 0x4f0]
00007081  48 89 05 88 96 01 00  mov qword ptr [rip + 0x19688], rax
00007088  48 8d 0d 81 96 01 00  lea rcx, [rip + 0x19681]
0000708f  e8 c0 a2 00 00  call 0x180011354
00007094  48 83 7c c6 10 00  cmp qword ptr [rsi + rax*8 + 0x10], 0
0000709a  74 19  je 0x1800070b5
0000709c  e8 ef a5 00 00  call 0x180011690
000070a1  e8 f0 a5 00 00  call 0x180011696
000070a6  e8 f1 a5 00 00  call 0x18001169c
000070ab  e8 f2 a5 00 00  call 0x1800116a2
000070b0  e8 f3 a5 00 00  call 0x1800116a8
000070b5  48 8b 05 6c 96 01 00  mov rax, qword ptr [rip + 0x1966c]
000070bc  48 8b 44 c6 48  mov rax, qword ptr [rsi + rax*8 + 0x48]
000070c1  48 89 05 40 96 01 00  mov qword ptr [rip + 0x19640], rax
000070c8  4c 8d 35 39 96 01 00  lea r14, [rip + 0x19639]
000070cf  48 8d 15 2a 96 01 00  lea rdx, [rip + 0x1962a]
000070d6  4c 8d 05 1b 96 01 00  lea r8, [rip + 0x1961b]
000070dd  4c 8d 0d 0c 96 01 00  lea r9, [rip + 0x1960c]
000070e4  4c 89 f1  mov rcx, r14
000070e7  e8 ec a2 00 00  call 0x1800113d8
000070ec  48 8d 15 f5 95 01 00  lea rdx, [rip + 0x195f5]
000070f3  4c 8d 05 e6 95 01 00  lea r8, [rip + 0x195e6]
000070fa  4c 89 f1  mov rcx, r14
000070fd  e8 20 a4 00 00  call 0x180011522
00007102  4c 8b 05 df 95 01 00  mov r8, qword ptr [rip + 0x195df]
00007109  4d 85 c0  test r8, r8
0000710c  48 8b 1d f5 e2 00 00  mov rbx, qword ptr [rip + 0xe2f5]
00007113  7e 7c  jle 0x180007191
00007115  48 8b 05 e4 95 01 00  mov rax, qword ptr [rip + 0x195e4]
0000711c  49 83 f8 0c  cmp r8, 0xc
00007120  76 50  jbe 0x180007172
00007122  48 8d 14 c6  lea rdx, [rsi + rax*8]
00007126  48 83 c2 f8  add rdx, -8
0000712a  49 c1 e0 03  shl r8, 3
0000712e  48 8b 0d a3 e3 00 00  mov rcx, qword ptr [rip + 0xe3a3]
00007135  e8 e6 1b 00 00  call 0x180008d20
0000713a  eb 55  jmp 0x180007191
0000713c  31 d2  xor edx, edx
0000713e  f7 f1  div ecx
00007140  48 83 fa 03  cmp rdx, 3
00007144  0f 84 df fd ff ff  je 0x180006f29
0000714a  48 8b 84 24 48 01 00 00  mov rax, qword ptr [rsp + 0x148]
00007152  48 c7 00 01 00 00 00  mov qword ptr [rax], 1
00007159  e9 52 16 00 00  jmp 0x1800087b0
0000715e  31 d2  xor edx, edx
00007160  41 f7 f0  div r8d
00007163  48 83 f8 04  cmp rax, 4
00007167  0f 84 e6 fe ff ff  je 0x180007053
0000716d  e9 f4 fe ff ff  jmp 0x180007066
00007172  48 8d 04 c6  lea rax, [rsi + rax*8]
00007176  48 83 c0 f8  add rax, -8
0000717a  31 c9  xor ecx, ecx
0000717c  0f 1f 40 00  nop dword ptr [rax]
00007180  48 8b 14 c8  mov rdx, qword ptr [rax + rcx*8]
00007184  49 89 54 cd 00  mov qword ptr [r13 + rcx*8], rdx
00007189  48 ff c1  inc rcx
0000718c  49 39 c8  cmp r8, rcx
0000718f  75 ef  jne 0x180007180
00007191  48 8b 3d 48 95 01 00  mov rdi, qword ptr [rip + 0x19548]
00007198  48 c7 05 8d 95 01 00 01 00 00 00  mov qword ptr [rip + 0x1958d], 1
000071a3  48 85 ff  test rdi, rdi
000071a6  7e 55  jle 0x1800071fd
000071a8  48 8b 05 49 95 01 00  mov rax, qword ptr [rip + 0x19549]
000071af  48 83 ff 0c  cmp rdi, 0xc
000071b3  76 1e  jbe 0x1800071d3
000071b5  48 8d 14 c6  lea rdx, [rsi + rax*8]
000071b9  48 83 c2 f8  add rdx, -8
000071bd  4c 8d 04 fd 00 00 00 00  lea r8, [rdi*8]
000071c5  48 8b 0d 1c e3 00 00  mov rcx, qword ptr [rip + 0xe31c]
000071cc  e8 4f 1b 00 00  call 0x180008d20
000071d1  eb 20  jmp 0x1800071f3
000071d3  48 8d 04 c6  lea rax, [rsi + rax*8]
000071d7  48 83 c0 f8  add rax, -8
000071db  31 c9  xor ecx, ecx
000071dd  0f 1f 00  nop dword ptr [rax]
000071e0  f2 0f 10 04 c8  movsd xmm0, qword ptr [rax + rcx*8]
000071e5  f2 41 0f 11 04 cf  movsd qword ptr [r15 + rcx*8], xmm0
000071eb  48 ff c1  inc rcx
000071ee  48 39 cf  cmp rdi, rcx
000071f1  75 ed  jne 0x1800071e0
000071f3  48 ff c7  inc rdi
000071f6  48 89 3d 33 95 01 00  mov qword ptr [rip + 0x19533], rdi
000071fd  49 8b 45 68  mov rax, qword ptr [r13 + 0x68]
00007201  48 8b 0d 78 8d 01 00  mov rcx, qword ptr [rip + 0x18d78]
00007208  48 39 c8  cmp rax, rcx
0000720b  48 0f 4f c8  cmovg rcx, rax
0000720f  49 89 4d 68  mov qword ptr [r13 + 0x68], rcx
00007213  f2 41 0f 10 07  movsd xmm0, qword ptr [r15]
00007218  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007220  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007228  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007230  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007238  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007240  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007248  48 8b 45 60  mov rax, qword ptr [rbp + 0x60]
0000724c  49 89 45 20  mov qword ptr [r13 + 0x20], rax
00007250  49 c7 85 a8 01 00 00 09 00 00 00  mov qword ptr [r13 + 0x1a8], 9
0000725b  49 c7 85 b0 00 00 00 09 00 00 00  mov qword ptr [r13 + 0xb0], 9
00007266  e8 4b a8 00 00  call 0x180011ab6
0000726b  48 8b 3d 06 e0 00 00  mov rdi, qword ptr [rip + 0xe006]
00007272  4c 8d 87 d0 07 00 00  lea r8, [rdi + 0x7d0]
00007279  48 8d 0d 70 09 01 00  lea rcx, [rip + 0x10970]
00007280  48 8d 15 39 09 01 00  lea rdx, [rip + 0x10939]
00007287  e8 9c a2 00 00  call 0x180011528
0000728c  4c 8d 87 f8 07 00 00  lea r8, [rdi + 0x7f8]
00007293  48 8d 0d 2e 09 01 00  lea rcx, [rip + 0x1092e]
0000729a  48 8d 15 47 09 01 00  lea rdx, [rip + 0x10947]
000072a1  e8 82 a2 00 00  call 0x180011528
000072a6  48 83 bb 88 20 00 00 00  cmp qword ptr [rbx + 0x2088], 0
000072ae  75 05  jne 0x1800072b5
000072b0  e8 79 a2 00 00  call 0x18001152e
000072b5  48 8b 05 6c 94 01 00  mov rax, qword ptr [rip + 0x1946c]
000072bc  48 8b 84 c6 30 06 00 00  mov rax, qword ptr [rsi + rax*8 + 0x630]
000072c4  48 89 05 55 94 01 00  mov qword ptr [rip + 0x19455], rax
000072cb  48 8d 0d 4e 94 01 00  lea rcx, [rip + 0x1944e]
000072d2  e8 7d a0 00 00  call 0x180011354
000072d7  48 89 05 3a 94 01 00  mov qword ptr [rip + 0x1943a], rax
000072de  48 8b 84 c6 b8 01 00 00  mov rax, qword ptr [rsi + rax*8 + 0x1b8]
000072e6  48 89 05 f3 8e 01 00  mov qword ptr [rip + 0x18ef3], rax
000072ed  48 85 c0  test rax, rax
000072f0  0f 84 ca 00 00 00  je 0x1800073c0
000072f6  48 8d 0d e3 8e 01 00  lea rcx, [rip + 0x18ee3]
000072fd  48 8d 15 d4 8e 01 00  lea rdx, [rip + 0x18ed4]
00007304  4c 8d 05 c5 8e 01 00  lea r8, [rip + 0x18ec5]
0000730b  4c 8d 0d de 93 01 00  lea r9, [rip + 0x193de]
00007312  e8 c1 a0 00 00  call 0x1800113d8
00007317  48 8b 1d ba 8e 01 00  mov rbx, qword ptr [rip + 0x18eba]
0000731e  48 8d 14 de  lea rdx, [rsi + rbx*8]
00007322  48 83 c2 f8  add rdx, -8
00007326  4c 8b 35 73 df 00 00  mov r14, qword ptr [rip + 0xdf73]
0000732d  49 8d 8e a0 00 00 00  lea rcx, [r14 + 0xa0]
00007334  41 b8 20 03 00 00  mov r8d, 0x320
0000733a  e8 e1 19 00 00  call 0x180008d20
0000733f  48 8b 05 8a 8e 01 00  mov rax, qword ptr [rip + 0x18e8a]
00007346  0f 10 84 de 18 03 00 00  movups xmm0, xmmword ptr [rsi + rbx*8 + 0x318]
0000734e  0f 10 8c de 28 03 00 00  movups xmm1, xmmword ptr [rsi + rbx*8 + 0x328]
00007356  0f 10 94 de 38 03 00 00  movups xmm2, xmmword ptr [rsi + rbx*8 + 0x338]
0000735e  0f 10 9c de 48 03 00 00  movups xmm3, xmmword ptr [rsi + rbx*8 + 0x348]
00007366  41 0f 29 46 50  movaps xmmword ptr [r14 + 0x50], xmm0
0000736b  0f 10 44 c6 f8  movups xmm0, xmmword ptr [rsi + rax*8 - 8]
00007370  0f 10 64 c6 08  movups xmm4, xmmword ptr [rsi + rax*8 + 8]
00007375  0f 10 6c c6 18  movups xmm5, xmmword ptr [rsi + rax*8 + 0x18]
0000737a  0f 10 74 c6 28  movups xmm6, xmmword ptr [rsi + rax*8 + 0x28]
0000737f  41 0f 29 06  movaps xmmword ptr [r14], xmm0
00007383  41 0f 29 4e 60  movaps xmmword ptr [r14 + 0x60], xmm1
00007388  41 0f 29 66 10  movaps xmmword ptr [r14 + 0x10], xmm4
0000738d  41 0f 29 56 70  movaps xmmword ptr [r14 + 0x70], xmm2
00007392  41 0f 29 6e 20  movaps xmmword ptr [r14 + 0x20], xmm5
00007397  41 0f 29 9e 80 00 00 00  movaps xmmword ptr [r14 + 0x80], xmm3
0000739f  41 0f 29 76 30  movaps xmmword ptr [r14 + 0x30], xmm6
000073a4  0f 10 84 de 58 03 00 00  movups xmm0, xmmword ptr [rsi + rbx*8 + 0x358]
000073ac  41 0f 29 86 90 00 00 00  movaps xmmword ptr [r14 + 0x90], xmm0
000073b4  0f 10 44 c6 38  movups xmm0, xmmword ptr [rsi + rax*8 + 0x38]
000073b9  41 0f 29 46 40  movaps xmmword ptr [r14 + 0x40], xmm0
000073be  eb 53  jmp 0x180007413
000073c0  48 8b 1d d9 de 00 00  mov rbx, qword ptr [rip + 0xded9]
000073c7  48 8d 8b a0 00 00 00  lea rcx, [rbx + 0xa0]
000073ce  41 b8 20 03 00 00  mov r8d, 0x320
000073d4  31 d2  xor edx, edx
000073d6  e8 15 1a 00 00  call 0x180008df0
000073db  48 c7 83 28 02 00 00 01 00 00 00  mov qword ptr [rbx + 0x228], 1
000073e6  49 8b 45 38  mov rax, qword ptr [r13 + 0x38]
000073ea  f2 41 0f 10 07  movsd xmm0, qword ptr [r15]
000073ef  48 c7 c1 f6 ff ff ff  mov rcx, 0xfffffffffffffff6
000073f6  66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00007400  48 89 84 cb a0 00 00 00  mov qword ptr [rbx + rcx*8 + 0xa0], rax
00007408  f2 0f 11 44 cb 50  movsd qword ptr [rbx + rcx*8 + 0x50], xmm0
0000740e  48 ff c1  inc rcx
00007411  75 ed  jne 0x180007400
00007413  48 c7 05 12 93 01 00 0b 00 00 00  mov qword ptr [rip + 0x19312], 0xb
0000741e  48 8b 05 03 93 01 00  mov rax, qword ptr [rip + 0x19303]
00007425  48 8b 84 c6 30 06 00 00  mov rax, qword ptr [rsi + rax*8 + 0x630]
0000742d  48 89 05 ec 92 01 00  mov qword ptr [rip + 0x192ec], rax
00007434  48 8d 0d e5 92 01 00  lea rcx, [rip + 0x192e5]
0000743b  e8 14 9f 00 00  call 0x180011354
00007440  48 89 05 d1 92 01 00  mov qword ptr [rip + 0x192d1], rax
00007447  48 8b 0d da 92 01 00  mov rcx, qword ptr [rip + 0x192da]
0000744e  48 c7 84 ce 70 04 00 00 00 00 00 00  mov qword ptr [rsi + rcx*8 + 0x470], 0
0000745a  48 c7 84 ce 78 04 00 00 00 00 00 00  mov qword ptr [rsi + rcx*8 + 0x478], 0
00007466  48 8b 84 c6 d0 00 00 00  mov rax, qword ptr [rsi + rax*8 + 0xd0]
0000746e  48 89 05 63 92 01 00  mov qword ptr [rip + 0x19263], rax
00007475  48 85 c0  test rax, rax
00007478  0f 84 6d 01 00 00  je 0x1800075eb
0000747e  48 8d 0d 53 92 01 00  lea rcx, [rip + 0x19253]
00007485  48 8d 15 44 92 01 00  lea rdx, [rip + 0x19244]
0000748c  4c 8d 05 35 92 01 00  lea r8, [rip + 0x19235]
00007493  4c 8d 0d 56 92 01 00  lea r9, [rip + 0x19256]
0000749a  e8 39 9f 00 00  call 0x1800113d8
0000749f  48 8b 0d 22 92 01 00  mov rcx, qword ptr [rip + 0x19222]
000074a6  48 8b 05 23 92 01 00  mov rax, qword ptr [rip + 0x19223]
000074ad  48 8d 14 c6  lea rdx, [rsi + rax*8]
000074b1  48 83 c2 f8  add rdx, -8
000074b5  4c 8d 04 ce  lea r8, [rsi + rcx*8]
000074b9  49 83 c0 f8  add r8, -8
000074bd  41 b9 01 00 00 00  mov r9d, 1
000074c3  45 31 db  xor r11d, r11d
000074c6  4c 8b 15 8b e7 00 00  mov r10, qword ptr [rip + 0xe78b]
000074cd  eb 10  jmp 0x1800074df
000074d0  4e 8b 34 da  mov r14, qword ptr [rdx + r11*8]
000074d4  4f 89 74 da 68  mov qword ptr [r10 + r11*8 + 0x68], r14
000074d9  49 ff c1  inc r9
000074dc  49 89 db  mov r11, rbx
000074df  49 8d 5b 01  lea rbx, [r11 + 1]
000074e3  f2 43 0f 10 04 d8  movsd xmm0, qword ptr [r8 + r11*8]
000074e9  f2 43 0f 11 04 da  movsd qword ptr [r10 + r11*8], xmm0
000074ef  48 83 fb 07  cmp rbx, 7
000074f3  7e db  jle 0x1800074d0
000074f5  48 83 fb 0c  cmp rbx, 0xc
000074f9  76 de  jbe 0x1800074d9
000074fb  49 83 c3 02  add r11, 2
000074ff  4c 89 1d 2a 92 01 00  mov qword ptr [rip + 0x1922a], r11
00007506  f2 0f 10 4c ce 60  movsd xmm1, qword ptr [rsi + rcx*8 + 0x60]
0000750c  48 8b 15 15 e7 00 00  mov rdx, qword ptr [rip + 0xe715]
00007513  f2 0f 11 4a 08  movsd qword ptr [rdx + 8], xmm1
00007518  f2 41 0f 10 07  movsd xmm0, qword ptr [r15]
0000751d  66 0f 2e c8  ucomisd xmm1, xmm0
00007521  72 0e  jb 0x180007531
00007523  49 b8 9a 99 99 99 99 99 b9 3f  movabs r8, 0x3fb999999999999a
0000752d  4c 89 42 08  mov qword ptr [rdx + 8], r8
00007531  48 8b 54 c6 10  mov rdx, qword ptr [rsi + rax*8 + 0x10]
00007536  4c 8b 44 c6 40  mov r8, qword ptr [rsi + rax*8 + 0x40]
0000753b  48 89 15 1e 8a 01 00  mov qword ptr [rip + 0x18a1e], rdx
00007542  48 8b 15 e7 e6 00 00  mov rdx, qword ptr [rip + 0xe6e7]
00007549  4c 89 42 08  mov qword ptr [rdx + 8], r8
0000754d  48 8b 54 c6 50  mov rdx, qword ptr [rsi + rax*8 + 0x50]
00007552  49 89 54 24 50  mov qword ptr [r12 + 0x50], rdx
00007557  48 8b 54 c6 60  mov rdx, qword ptr [rsi + rax*8 + 0x60]
0000755c  49 89 54 24 60  mov qword ptr [r12 + 0x60], rdx
00007561  0f 10 4c c6 68  movups xmm1, xmmword ptr [rsi + rax*8 + 0x68]
00007566  41 0f 11 4c 24 68  movups xmmword ptr [r12 + 0x68], xmm1
0000756c  f2 0f 10 4c ce 68  movsd xmm1, qword ptr [rsi + rcx*8 + 0x68]
00007572  f2 41 0f 11 4c 24 18  movsd qword ptr [r12 + 0x18], xmm1
00007579  66 0f 2e c8  ucomisd xmm1, xmm0
0000757d  72 0f  jb 0x18000758e
0000757f  48 ba 5c 8f c2 f5 28 5c ef 3f  movabs rdx, 0x3fef5c28f5c28f5c
00007589  49 89 54 24 18  mov qword ptr [r12 + 0x18], rdx
0000758e  48 8b 94 c6 88 00 00 00  mov rdx, qword ptr [rsi + rax*8 + 0x88]
00007596  4c 8b 84 c6 90 00 00 00  mov r8, qword ptr [rsi + rax*8 + 0x90]
0000759e  49 89 94 24 80 00 00 00  mov qword ptr [r12 + 0x80], rdx
000075a6  31 d2  xor edx, edx
000075a8  49 83 f8 01  cmp r8, 1
000075ac  0f 95 c2  setne dl
000075af  49 89 94 24 90 00 00 00  mov qword ptr [r12 + 0x90], rdx
000075b7  48 8b 94 c6 b0 00 00 00  mov rdx, qword ptr [rsi + rax*8 + 0xb0]
000075bf  49 89 94 24 d0 4e 00 00  mov qword ptr [r12 + 0x4ed0], rdx
000075c7  0f 10 84 ce 90 00 00 00  movups xmm0, xmmword ptr [rsi + rcx*8 + 0x90]
000075cf  41 0f 11 44 24 28  movups xmmword ptr [r12 + 0x28], xmm0
000075d5  31 c9  xor ecx, ecx
000075d7  48 83 bc c6 f8 00 00 00 01  cmp qword ptr [rsi + rax*8 + 0xf8], 1
000075e0  0f 95 c1  setne cl
000075e3  49 89 8c 24 38 4f 00 00  mov qword ptr [r12 + 0x4f38], rcx
000075eb  48 c7 05 3a 91 01 00 01 00 00 00  mov qword ptr [rip + 0x1913a], 1
000075f6  41 be 20 01 00 00  mov r14d, 0x120
000075fc  4c 03 35 d5 de 00 00  add r14, qword ptr [rip + 0xded5]
00007603  48 8b 05 f6 de 00 00  mov rax, qword ptr [rip + 0xdef6]
0000760a  4c 8d 78 78  lea r15, [rax + 0x78]
0000760e  4c 8d 25 1b 91 01 00  lea r12, [rip + 0x1911b]
00007615  66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00007620  4c 89 f9  mov rcx, r15
00007623  4c 89 f2  mov rdx, r14
00007626  4d 89 f8  mov r8, r15
00007629  4d 89 e1  mov r9, r12
0000762c  e8 03 9f 00 00  call 0x180011534
00007631  48 8b 05 f8 90 01 00  mov rax, qword ptr [rip + 0x190f8]
00007638  48 8d 48 01  lea rcx, [rax + 1]
0000763c  48 89 0d ed 90 01 00  mov qword ptr [rip + 0x190ed], rcx
00007643  48 83 f8 04  cmp rax, 4
00007647  7c d7  jl 0x180007620
00007649  48 8b 05 b8 dd 00 00  mov rax, qword ptr [rip + 0xddb8]
00007650  48 83 b8 88 20 00 00 00  cmp qword ptr [rax + 0x2088], 0
00007658  49 bc 00 00 00 00 00 00 f0 3f  movabs r12, 0x3ff0000000000000
00007662  0f 85 48 03 00 00  jne 0x1800079b0
00007668  48 8b 05 b9 90 01 00  mov rax, qword ptr [rip + 0x190b9]
0000766f  4c 8b 25 82 de 00 00  mov r12, qword ptr [rip + 0xde82]
00007676  49 8b 8c c4 b0 01 00 00  mov rcx, qword ptr [r12 + rax*8 + 0x1b0]
0000767e  49 8b 84 c4 b8 01 00 00  mov rax, qword ptr [r12 + rax*8 + 0x1b8]
00007686  48 89 05 33 90 01 00  mov qword ptr [rip + 0x19033], rax
0000768d  48 89 0d 24 90 01 00  mov qword ptr [rip + 0x19024], rcx
00007694  48 8d 1d 55 90 01 00  lea rbx, [rip + 0x19055]
0000769b  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
000076a0  48 8d 0d 49 05 01 00  lea rcx, [rip + 0x10549]
000076a7  48 8d 15 7a 8b 01 00  lea rdx, [rip + 0x18b7a]
000076ae  4c 8d 05 6b 8b 01 00  lea r8, [rip + 0x18b6b]
000076b5  4c 8d 35 f4 8f 01 00  lea r14, [rip + 0x18ff4]
000076bc  4d 89 f1  mov r9, r14
000076bf  e8 2c 9d 00 00  call 0x1800113f0
000076c4  48 83 3d f4 8f 01 00 00  cmp qword ptr [rip + 0x18ff4], 0
000076cc  74 35  je 0x180007703
000076ce  ba b8 00 00 00  mov edx, 0xb8
000076d3  48 03 15 d6 e5 00 00  add rdx, qword ptr [rip + 0xe5d6]
000076da  48 8d 0d df 8f 01 00  lea rcx, [rip + 0x18fdf]
000076e1  4c 8d 05 c8 8f 01 00  lea r8, [rip + 0x18fc8]
000076e8  4c 8d 0d 01 90 01 00  lea r9, [rip + 0x19001]
000076ef  e8 e4 9c 00 00  call 0x1800113d8
000076f4  49 bc 00 00 00 00 00 00 f0 3f  movabs r12, 0x3ff0000000000000
000076fe  e9 76 02 00 00  jmp 0x180007979
00007703  48 8b 05 16 8b 01 00  mov rax, qword ptr [rip + 0x18b16]
0000770a  49 8b 84 c4 60 01 00 00  mov rax, qword ptr [r12 + rax*8 + 0x160]
00007712  48 89 05 1f 8b 01 00  mov qword ptr [rip + 0x18b1f], rax
00007719  48 8d 0d 18 8b 01 00  lea rcx, [rip + 0x18b18]
00007720  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
00007725  48 8b 05 84 e5 00 00  mov rax, qword ptr [rip + 0xe584]
0000772c  4c 8d 80 b8 00 00 00  lea r8, [rax + 0xb8]
00007733  48 8d 15 86 8f 01 00  lea rdx, [rip + 0x18f86]
0000773a  4d 89 f1  mov r9, r14
0000773d  e8 f8 9d 00 00  call 0x18001153a
00007742  48 8b 05 77 8f 01 00  mov rax, qword ptr [rip + 0x18f77]
00007749  48 8b 0d d8 8f 01 00  mov rcx, qword ptr [rip + 0x18fd8]
00007750  49 89 84 cc b8 01 00 00  mov qword ptr [r12 + rcx*8 + 0x1b8], rax
00007758  48 8b 05 c1 8a 01 00  mov rax, qword ptr [rip + 0x18ac1]
0000775f  49 8b 84 c4 68 01 00 00  mov rax, qword ptr [r12 + rax*8 + 0x168]
00007767  48 89 05 c2 8a 01 00  mov qword ptr [rip + 0x18ac2], rax
0000776e  48 8d 0d bb 8a 01 00  lea rcx, [rip + 0x18abb]
00007775  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
0000777a  4c 8d 3d 97 8a 01 00  lea r15, [rip + 0x18a97]
00007781  4c 8d 05 88 8a 01 00  lea r8, [rip + 0x18a88]
00007788  4c 89 fa  mov rdx, r15
0000778b  4d 89 f1  mov r9, r14
0000778e  e8 a7 9d 00 00  call 0x18001153a
00007793  48 8b 05 7e 8a 01 00  mov rax, qword ptr [rip + 0x18a7e]
0000779a  48 8b 0d 87 8f 01 00  mov rcx, qword ptr [rip + 0x18f87]
000077a1  49 89 84 cc d8 01 00 00  mov qword ptr [r12 + rcx*8 + 0x1d8], rax
000077a9  48 8d 15 98 8e 01 00  lea rdx, [rip + 0x18e98]
000077b0  4c 8d 2d 89 8e 01 00  lea r13, [rip + 0x18e89]
000077b7  4c 89 f9  mov rcx, r15
000077ba  4d 89 e7  mov r15, r12
000077bd  49 89 d4  mov r12, rdx
000077c0  4d 89 e8  mov r8, r13
000077c3  e8 5a 9d 00 00  call 0x180011522
000077c8  48 89 5c 24 28  mov qword ptr [rsp + 0x28], rbx
000077cd  4c 89 74 24 20  mov qword ptr [rsp + 0x20], r14
000077d2  4c 8d 05 2f 8a 01 00  lea r8, [rip + 0x18a2f]
000077d9  4c 8d 0d 90 8e 01 00  lea r9, [rip + 0x18e90]
000077e0  4c 89 e1  mov rcx, r12
000077e3  4c 89 ea  mov rdx, r13
000077e6  e8 55 9d 00 00  call 0x180011540
000077eb  48 8b 05 16 8a 01 00  mov rax, qword ptr [rip + 0x18a16]
000077f2  48 8b 0d 2f 8f 01 00  mov rcx, qword ptr [rip + 0x18f2f]
000077f9  49 89 84 cf e0 01 00 00  mov qword ptr [r15 + rcx*8 + 0x1e0], rax
00007801  48 8b 05 68 8e 01 00  mov rax, qword ptr [rip + 0x18e68]
00007808  48 89 05 29 8e 01 00  mov qword ptr [rip + 0x18e29], rax
0000780f  48 89 5c 24 28  mov qword ptr [rsp + 0x28], rbx
00007814  48 8b 1d 95 e4 00 00  mov rbx, qword ptr [rip + 0xe495]
0000781b  4c 89 74 24 20  mov qword ptr [rsp + 0x20], r14
00007820  4c 8d 8b c0 00 00 00  lea r9, [rbx + 0xc0]
00007827  4c 8d 05 8a 8e 01 00  lea r8, [rip + 0x18e8a]
0000782e  4c 89 e1  mov rcx, r12
00007831  4c 89 ea  mov rdx, r13
00007834  e8 07 9d 00 00  call 0x180011540
00007839  48 8b 05 78 8e 01 00  mov rax, qword ptr [rip + 0x18e78]
00007840  48 8b 15 e1 8e 01 00  mov rdx, qword ptr [rip + 0x18ee1]
00007847  48 8b 0d ba db 00 00  mov rcx, qword ptr [rip + 0xdbba]
0000784e  4c 8b 41 08  mov r8, qword ptr [rcx + 8]
00007852  48 8b 0d e7 8d 01 00  mov rcx, qword ptr [rip + 0x18de7]
00007859  49 0f af c8  imul rcx, r8
0000785d  48 03 0d e4 8d 01 00  add rcx, qword ptr [rip + 0x18de4]
00007864  49 89 84 d7 b0 01 00 00  mov qword ptr [r15 + rdx*8 + 0x1b0], rax
0000786c  48 89 c8  mov rax, rcx
0000786f  4c 09 c0  or rax, r8
00007872  48 c1 e8 20  shr rax, 0x20
00007876  74 0a  je 0x180007882
00007878  48 89 c8  mov rax, rcx
0000787b  48 99  cqo
0000787d  49 f7 f8  idiv r8
00007880  eb 07  jmp 0x180007889
00007882  89 c8  mov eax, ecx
00007884  31 d2  xor edx, edx
00007886  41 f7 f0  div r8d
00007889  49 29 d0  sub r8, rdx
0000788c  48 85 d2  test rdx, rdx
0000788f  4c 0f 44 c2  cmove r8, rdx
00007893  4c 01 c1  add rcx, r8
00007896  48 89 0d 63 89 01 00  mov qword ptr [rip + 0x18963], rcx
0000789d  4c 8d 35 5c 89 01 00  lea r14, [rip + 0x1895c]
000078a4  48 8b 05 65 89 01 00  mov rax, qword ptr [rip + 0x18965]
000078ab  49 8d 0c c7  lea rcx, [r15 + rax*8]
000078af  48 83 c1 f8  add rcx, -8
000078b3  48 8b 83 c0 00 00 00  mov rax, qword ptr [rbx + 0xc0]
000078ba  49 8d 14 c7  lea rdx, [r15 + rax*8]
000078be  48 83 c2 f8  add rdx, -8
000078c2  4d 89 f0  mov r8, r14
000078c5  e8 7c 9c 00 00  call 0x180011546
000078ca  48 8b 05 3f 89 01 00  mov rax, qword ptr [rip + 0x1893f]
000078d1  49 8d 0c c7  lea rcx, [r15 + rax*8]
000078d5  48 83 c1 f8  add rcx, -8
000078d9  48 8b 05 58 8d 01 00  mov rax, qword ptr [rip + 0x18d58]
000078e0  49 8d 14 c7  lea rdx, [r15 + rax*8]
000078e4  48 83 c2 f8  add rdx, -8
000078e8  4d 89 f0  mov r8, r14
000078eb  e8 56 9c 00 00  call 0x180011546
000078f0  48 8b 83 c0 00 00 00  mov rax, qword ptr [rbx + 0xc0]
000078f7  49 8b 5c c7 08  mov rbx, qword ptr [r15 + rax*8 + 8]
000078fc  48 c7 05 29 8e 01 00 01 00 00 00  mov qword ptr [rip + 0x18e29], 1
00007907  48 85 db  test rbx, rbx
0000790a  49 bc 00 00 00 00 00 00 f0 3f  movabs r12, 0x3ff0000000000000
00007914  7e 63  jle 0x180007979
00007916  4d 89 fd  mov r13, r15
00007919  4c 8d 35 18 8d 01 00  lea r14, [rip + 0x18d18]
00007920  4c 8d 3d 09 8e 01 00  lea r15, [rip + 0x18e09]
00007927  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00007930  4c 89 f1  mov rcx, r14
00007933  4c 89 fa  mov rdx, r15
00007936  4c 8d 05 e3 02 01 00  lea r8, [rip + 0x102e3]
0000793d  e8 0a 9c 00 00  call 0x18001154c
00007942  4d 89 64 c5 f8  mov qword ptr [r13 + rax*8 - 8], r12
00007947  4c 89 f1  mov rcx, r14
0000794a  4c 89 fa  mov rdx, r15
0000794d  4c 8d 05 9c 02 01 00  lea r8, [rip + 0x1029c]
00007954  e8 f3 9b 00 00  call 0x18001154c
00007959  49 c7 44 c5 f8 00 00 00 00  mov qword ptr [r13 + rax*8 - 8], 0
00007962  48 8b 05 c7 8d 01 00  mov rax, qword ptr [rip + 0x18dc7]
00007969  48 8d 48 01  lea rcx, [rax + 1]
0000796d  48 89 0d bc 8d 01 00  mov qword ptr [rip + 0x18dbc], rcx
00007974  48 39 d8  cmp rax, rbx
00007977  7c b7  jl 0x180007930
00007979  48 83 3d 37 8d 01 00 00  cmp qword ptr [rip + 0x18d37], 0
00007981  4c 8b 2d 50 db 00 00  mov r13, qword ptr [rip + 0xdb50]
00007988  74 26  je 0x1800079b0
0000798a  ba c0 00 00 00  mov edx, 0xc0
0000798f  48 03 15 1a e3 00 00  add rdx, qword ptr [rip + 0xe31a]
00007996  48 8d 0d 1b 8d 01 00  lea rcx, [rip + 0x18d1b]
0000799d  4c 8d 05 0c 8d 01 00  lea r8, [rip + 0x18d0c]
000079a4  4c 8d 0d 45 8d 01 00  lea r9, [rip + 0x18d45]
000079ab  e8 28 9a 00 00  call 0x1800113d8
000079b0  49 83 bd a8 01 00 00 01  cmp qword ptr [r13 + 0x1a8], 1
000079b8  4c 8b 35 41 db 00 00  mov r14, qword ptr [rip + 0xdb41]
000079bf  4c 8b 3d 22 db 00 00  mov r15, qword ptr [rip + 0xdb22]
000079c6  74 6f  je 0x180007a37
000079c8  48 8b 9f 48 08 00 00  mov rbx, qword ptr [rdi + 0x848]
000079cf  48 c7 05 56 8d 01 00 01 00 00 00  mov qword ptr [rip + 0x18d56], 1
000079da  48 85 db  test rbx, rbx
000079dd  7e 58  jle 0x180007a37
000079df  48 83 fb 0d  cmp rbx, 0xd
000079e3  72 1c  jb 0x180007a01
000079e5  4c 8d 04 dd 00 00 00 00  lea r8, [rbx*8]
000079ed  48 8b 0d d4 d8 00 00  mov rcx, qword ptr [rip + 0xd8d4]
000079f4  48 83 c1 18  add rcx, 0x18
000079f8  b2 20  mov dl, 0x20
000079fa  e8 f1 13 00 00  call 0x180008df0
000079ff  eb 2c  jmp 0x180007a2d
00007a01  31 c0  xor eax, eax
00007a03  48 8b 0d be d8 00 00  mov rcx, qword ptr [rip + 0xd8be]
00007a0a  48 ba 20 20 20 20 20 20 20 20  movabs rdx, 0x2020202020202020
00007a14  66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00007a20  48 89 54 c1 18  mov qword ptr [rcx + rax*8 + 0x18], rdx
00007a25  48 ff c0  inc rax
00007a28  48 39 c3  cmp rbx, rax
00007a2b  75 f3  jne 0x180007a20
00007a2d  48 ff c3  inc rbx
00007a30  48 89 1d f9 8c 01 00  mov qword ptr [rip + 0x18cf9], rbx
00007a37  49 8b 45 38  mov rax, qword ptr [r13 + 0x38]
00007a3b  49 89 86 c8 01 00 00  mov qword ptr [r14 + 0x1c8], rax
00007a42  f2 41 0f 10 07  movsd xmm0, qword ptr [r15]
00007a47  48 8b 0d 82 d8 00 00  mov rcx, qword ptr [rip + 0xd882]
00007a4e  f2 0f 11 01  movsd qword ptr [rcx], xmm0
00007a52  48 89 41 08  mov qword ptr [rcx + 8], rax
00007a56  49 8b 45 58  mov rax, qword ptr [r13 + 0x58]
00007a5a  48 89 41 10  mov qword ptr [rcx + 0x10], rax
00007a5e  49 8b 85 00 01 00 00  mov rax, qword ptr [r13 + 0x100]
00007a65  48 89 41 18  mov qword ptr [rcx + 0x18], rax
00007a69  49 8b 85 b8 00 00 00  mov rax, qword ptr [r13 + 0xb8]
00007a70  48 89 41 20  mov qword ptr [rcx + 0x20], rax
00007a74  48 c7 41 28 00 00 00 00  mov qword ptr [rcx + 0x28], 0
00007a7c  49 8b 45 28  mov rax, qword ptr [r13 + 0x28]
00007a80  48 89 41 30  mov qword ptr [rcx + 0x30], rax
00007a84  49 8b 45 50  mov rax, qword ptr [r13 + 0x50]
00007a88  48 89 41 38  mov qword ptr [rcx + 0x38], rax
00007a8c  49 8b 45 10  mov rax, qword ptr [r13 + 0x10]
00007a90  49 8b 55 20  mov rdx, qword ptr [r13 + 0x20]
00007a94  48 89 41 40  mov qword ptr [rcx + 0x40], rax
00007a98  48 89 51 48  mov qword ptr [rcx + 0x48], rdx
00007a9c  48 8b 45 68  mov rax, qword ptr [rbp + 0x68]
00007aa0  48 8b 95 18 01 00 00  mov rdx, qword ptr [rbp + 0x118]
00007aa7  48 89 41 50  mov qword ptr [rcx + 0x50], rax
00007aab  48 89 51 58  mov qword ptr [rcx + 0x58], rdx
00007aaf  49 8b 85 08 01 00 00  mov rax, qword ptr [r13 + 0x108]
00007ab6  48 89 41 60  mov qword ptr [rcx + 0x60], rax
00007aba  e8 af 99 00 00  call 0x18001146e
00007abf  49 83 bd 10 01 00 00 03  cmp qword ptr [r13 + 0x110], 3
00007ac7  75 38  jne 0x180007b01
00007ac9  49 83 bd 98 01 00 00 01  cmp qword ptr [r13 + 0x198], 1
00007ad1  75 2e  jne 0x180007b01
00007ad3  48 8d 05 06 01 01 00  lea rax, [rip + 0x10106]
00007ada  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00007adf  4c 8d 05 32 01 01 00  lea r8, [rip + 0x10132]
00007ae6  4c 89 44 24 20  mov qword ptr [rsp + 0x20], r8
00007aeb  48 8d 0d de 00 01 00  lea rcx, [rip + 0x100de]
00007af2  48 8d 15 df 00 01 00  lea rdx, [rip + 0x100df]
00007af9  4d 89 c1  mov r9, r8
00007afc  e8 5d 9a 00 00  call 0x18001155e
00007b01  48 8b 05 48 e1 00 00  mov rax, qword ptr [rip + 0xe148]
00007b08  48 b9 00 00 00 00 d0 bc f8 40  movabs rcx, 0x40f8bcd000000000
00007b12  48 89 08  mov qword ptr [rax], rcx
00007b15  48 b9 66 66 66 66 66 a2 72 40  movabs rcx, 0x4072a26666666666
00007b1f  48 89 48 08  mov qword ptr [rax + 8], rcx
00007b23  48 b9 d7 a3 70 3d 2a 3d c0 40  movabs rcx, 0x40c03d2a3d70a3d7
00007b2d  48 89 48 10  mov qword ptr [rax + 0x10], rcx
00007b31  48 b9 9b b3 18 f0 60 b0 30 3b  movabs rcx, 0x3b30b060f018b39b
00007b3b  48 89 48 18  mov qword ptr [rax + 0x18], rcx
00007b3f  48 8b 05 9a d7 00 00  mov rax, qword ptr [rip + 0xd79a]
00007b46  4c 89 60 60  mov qword ptr [rax + 0x60], r12
00007b4a  31 c0  xor eax, eax
00007b4c  48 8d 0d 0d a4 01 00  lea rcx, [rip + 0x1a40d]
00007b53  66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00007b60  4c 89 24 08  mov qword ptr [rax + rcx], r12
00007b64  48 83 c0 08  add rax, 8
00007b68  48 83 f8 48  cmp rax, 0x48
00007b6c  75 f2  jne 0x180007b60
00007b6e  48 c7 05 b7 8b 01 00 0a 00 00 00  mov qword ptr [rip + 0x18bb7], 0xa
00007b79  48 8b 05 a8 8b 01 00  mov rax, qword ptr [rip + 0x18ba8]
00007b80  48 8b 84 c6 e0 00 00 00  mov rax, qword ptr [rsi + rax*8 + 0xe0]
00007b88  48 89 05 19 8b 01 00  mov qword ptr [rip + 0x18b19], rax
00007b8f  48 85 c0  test rax, rax
00007b92  0f 8e 06 01 00 00  jle 0x180007c9e
00007b98  48 8d 0d 09 8b 01 00  lea rcx, [rip + 0x18b09]
00007b9f  e8 b0 97 00 00  call 0x180011354
00007ba4  48 89 05 f5 8a 01 00  mov qword ptr [rip + 0x18af5], rax
00007bab  4c 8b 6c c6 f8  mov r13, qword ptr [rsi + rax*8 - 8]
00007bb0  4d 85 ed  test r13, r13
00007bb3  0f 8e e5 00 00 00  jle 0x180007c9e
00007bb9  48 c7 05 6c 8b 01 00 01 00 00 00  mov qword ptr [rip + 0x18b6c], 1
00007bc4  b8 01 00 00 00  mov eax, 1
00007bc9  48 8d 1d c8 8a 01 00  lea rbx, [rip + 0x18ac8]
00007bd0  4c 8d 35 11 00 01 00  lea r14, [rip + 0x10011]
00007bd7  4c 8d 3d e2 85 01 00  lea r15, [rip + 0x185e2]
00007bde  4c 8d 25 d3 85 01 00  lea r12, [rip + 0x185d3]
00007be5  0f 57 f6  xorps xmm6, xmm6
00007be8  eb 56  jmp 0x180007c40
00007bf0  4c 89 f1  mov rcx, r14
00007bf3  4c 89 fa  mov rdx, r15
00007bf6  4d 89 e0  mov r8, r12
00007bf9  e8 10 98 00 00  call 0x18001140e
00007bfe  48 8b 05 bb 85 01 00  mov rax, qword ptr [rip + 0x185bb]
00007c05  48 8b 0d 84 8a 01 00  mov rcx, qword ptr [rip + 0x18a84]
00007c0c  48 89 44 ce 30  mov qword ptr [rsi + rcx*8 + 0x30], rax
00007c11  48 8b 05 a0 85 01 00  mov rax, qword ptr [rip + 0x185a0]
00007c18  0f 11 74 c6 f8  movups xmmword ptr [rsi + rax*8 - 8], xmm6
00007c1d  48 83 c0 02  add rax, 2
00007c21  48 c7 04 c6 00 00 00 00  mov qword ptr [rsi + rax*8], 0
00007c29  48 8b 0d 00 8b 01 00  mov rcx, qword ptr [rip + 0x18b00]
00007c30  48 8d 41 01  lea rax, [rcx + 1]
00007c34  48 89 05 f5 8a 01 00  mov qword ptr [rip + 0x18af5], rax
00007c3b  4c 39 e9  cmp rcx, r13
00007c3e  7d 5e  jge 0x180007c9e
00007c40  48 8d 04 40  lea rax, [rax + rax*2]
00007c44  48 03 05 55 8a 01 00  add rax, qword ptr [rip + 0x18a55]
00007c4b  48 8b 44 c6 f8  mov rax, qword ptr [rsi + rax*8 - 8]
00007c50  48 89 05 41 8a 01 00  mov qword ptr [rip + 0x18a41], rax
00007c57  48 89 d9  mov rcx, rbx
00007c5a  e8 f5 96 00 00  call 0x180011354
00007c5f  48 89 05 2a 8a 01 00  mov qword ptr [rip + 0x18a2a], rax
00007c66  48 c7 44 c6 08 00 00 00 00  mov qword ptr [rsi + rax*8 + 8], 0
00007c6f  48 8b 44 c6 30  mov rax, qword ptr [rsi + rax*8 + 0x30]
00007c74  48 89 05 45 85 01 00  mov qword ptr [rip + 0x18545], rax
00007c7b  48 85 c0  test rax, rax
00007c7e  0f 84 6c ff ff ff  je 0x180007bf0
00007c84  4c 89 f9  mov rcx, r15
00007c87  e8 c8 96 00 00  call 0x180011354
00007c8c  48 89 05 25 85 01 00  mov qword ptr [rip + 0x18525], rax
00007c93  48 c7 44 c6 f8 00 00 00 00  mov qword ptr [rsi + rax*8 - 8], 0
00007c9c  eb 83  jmp 0x180007c21
00007c9e  48 8d 05 7b 88 01 00  lea rax, [rip + 0x1887b]
00007ca5  48 89 44 24 38  mov qword ptr [rsp + 0x38], rax
00007caa  48 8d 05 77 88 01 00  lea rax, [rip + 0x18877]
00007cb1  48 89 44 24 30  mov qword ptr [rsp + 0x30], rax
00007cb6  48 8d 05 73 88 01 00  lea rax, [rip + 0x18873]
00007cbd  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00007cc2  4c 8d 25 77 8a 01 00  lea r12, [rip + 0x18a77]
00007cc9  4c 89 64 24 20  mov qword ptr [rsp + 0x20], r12
00007cce  48 8d 0d 4b 89 01 00  lea rcx, [rip + 0x1894b]
00007cd5  4c 8d 35 e4 8a 01 00  lea r14, [rip + 0x18ae4]
00007cdc  48 8d 1d 9d 8a 01 00  lea rbx, [rip + 0x18a9d]
00007ce3  4c 8d 3d 16 89 01 00  lea r15, [rip + 0x18916]
00007cea  4c 89 f2  mov rdx, r14
00007ced  49 89 d8  mov r8, rbx
00007cf0  4d 89 f9  mov r9, r15
00007cf3  e8 72 98 00 00  call 0x18001156a
00007cf8  48 8b 05 31 88 01 00  mov rax, qword ptr [rip + 0x18831]
00007cff  48 89 87 e0 00 00 00  mov qword ptr [rdi + 0xe0], rax
00007d06  48 8b 05 1b 88 01 00  mov rax, qword ptr [rip + 0x1881b]
00007d0d  48 89 87 d8 00 00 00  mov qword ptr [rdi + 0xd8], rax
00007d14  48 8b 05 05 88 01 00  mov rax, qword ptr [rip + 0x18805]
00007d1b  48 89 87 e8 00 00 00  mov qword ptr [rdi + 0xe8], rax
00007d22  48 8b 05 f7 88 01 00  mov rax, qword ptr [rip + 0x188f7]
00007d29  48 89 07  mov qword ptr [rdi], rax
00007d2c  0f 10 05 f5 88 01 00  movups xmm0, xmmword ptr [rip + 0x188f5]
00007d33  0f 11 47 08  movups xmmword ptr [rdi + 8], xmm0
00007d37  31 c9  xor ecx, ecx
00007d39  0f 1f 80 00 00 00 00  nop dword ptr [rax]
00007d40  4a 8b 14 39  mov rdx, qword ptr [rcx + r15]
00007d44  48 89 54 0f 58  mov qword ptr [rdi + rcx + 0x58], rdx
00007d49  4a 8b 14 31  mov rdx, qword ptr [rcx + r14]
00007d4d  48 89 54 0f 18  mov qword ptr [rdi + rcx + 0x18], rdx
00007d52  48 83 c1 08  add rcx, 8
00007d56  48 83 f9 18  cmp rcx, 0x18
00007d5a  75 e4  jne 0x180007d40
00007d5c  31 c9  xor ecx, ecx
00007d5e  4c 8d 2d 8b 89 01 00  lea r13, [rip + 0x1898b]
00007d65  66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00007d70  48 8b 14 19  mov rdx, qword ptr [rcx + rbx]
00007d74  48 89 54 0f 30  mov qword ptr [rdi + rcx + 0x30], rdx
00007d79  4a 8b 14 21  mov rdx, qword ptr [rcx + r12]
00007d7d  48 89 54 0f 70  mov qword ptr [rdi + rcx + 0x70], rdx
00007d82  48 83 c1 08  add rcx, 8
00007d86  48 83 f9 28  cmp rcx, 0x28
00007d8a  75 e4  jne 0x180007d70
00007d8c  48 c7 05 99 89 01 00 06 00 00 00  mov qword ptr [rip + 0x18999], 6
00007d97  4c 8b 35 6a d6 00 00  mov r14, qword ptr [rip + 0xd66a]
00007d9e  49 83 be 88 20 00 00 00  cmp qword ptr [r14 + 0x2088], 0
00007da6  4c 8b 25 2b d7 00 00  mov r12, qword ptr [rip + 0xd72b]
00007dad  74 10  je 0x180007dbf
00007daf  49 89 46 58  mov qword ptr [r14 + 0x58], rax
00007db3  48 8b 3d de de 00 00  mov rdi, qword ptr [rip + 0xdede]
00007dba  e9 ee 03 00 00  jmp 0x1800081ad
00007dbf  48 8d 0d 2a fe 00 00  lea rcx, [rip + 0xfe2a]
00007dc6  e8 89 95 00 00  call 0x180011354
00007dcb  4c 8b 3d 26 d7 00 00  mov r15, qword ptr [rip + 0xd726]
00007dd2  49 8b 84 c7 08 03 00 00  mov rax, qword ptr [r15 + rax*8 + 0x308]
00007dda  48 89 05 a7 88 01 00  mov qword ptr [rip + 0x188a7], rax
00007de1  48 8d 0d a0 88 01 00  lea rcx, [rip + 0x188a0]
00007de8  e8 67 95 00 00  call 0x180011354
00007ded  48 89 c3  mov rbx, rax
00007df0  4d 8b 64 c7 60  mov r12, qword ptr [r15 + rax*8 + 0x60]
00007df5  49 8b 44 c7 20  mov rax, qword ptr [r15 + rax*8 + 0x20]
00007dfa  4d 8b 6c df 38  mov r13, qword ptr [r15 + rbx*8 + 0x38]
00007dff  41 0f 10 44 df 50  movups xmm0, xmmword ptr [r15 + rbx*8 + 0x50]
00007e05  0f 29 87 40 07 00 00  movaps xmmword ptr [rdi + 0x740], xmm0
00007e0c  41 0f 10 44 df f8  movups xmm0, xmmword ptr [r15 + rbx*8 - 8]
00007e12  41 0f 10 4c df 08  movups xmm1, xmmword ptr [r15 + rbx*8 + 8]
00007e18  0f 11 87 a8 07 00 00  movups xmmword ptr [rdi + 0x7a8], xmm0
00007e1f  0f 11 8f b8 07 00 00  movups xmmword ptr [rdi + 0x7b8], xmm1
00007e26  4c 8b b7 48 08 00 00  mov r14, qword ptr [rdi + 0x848]
00007e2d  4d 85 f6  test r14, r14
00007e30  0f 8e 32 01 00 00  jle 0x180007f68
00007e36  49 83 fe 0d  cmp r14, 0xd
00007e3a  72 54  jb 0x180007e90
00007e3c  49 ff cc  dec r12
00007e3f  48 ff c8  dec rax
00007e42  49 ff cd  dec r13
00007e45  48 01 d8  add rax, rbx
00007e48  49 8d 14 c7  lea rdx, [r15 + rax*8]
00007e4c  49 c1 e6 03  shl r14, 3
00007e50  48 8d 8f f0 02 00 00  lea rcx, [rdi + 0x2f0]
00007e57  4d 89 f0  mov r8, r14
00007e5a  e8 c1 0e 00 00  call 0x180008d20
00007e5f  49 01 dd  add r13, rbx
00007e62  4b 8d 14 ef  lea rdx, [r15 + r13*8]
00007e66  48 8d 8f f8 04 00 00  lea rcx, [rdi + 0x4f8]
00007e6d  4d 89 f0  mov r8, r14
00007e70  e8 ab 0e 00 00  call 0x180008d20
00007e75  49 01 dc  add r12, rbx
00007e78  4b 8d 14 e7  lea rdx, [r15 + r12*8]
00007e7c  48 8d 8f f0 00 00 00  lea rcx, [rdi + 0xf0]
00007e83  4d 89 f0  mov r8, r14
00007e86  e8 95 0e 00 00  call 0x180008d20
00007e8b  e9 d8 00 00 00  jmp 0x180007f68
00007e90  4c 89 f1  mov rcx, r14
00007e93  48 83 e1 0e  and rcx, 0xe
00007e97  74 61  je 0x180007efa
00007e99  4a 8d 14 23  lea rdx, [rbx + r12]
00007e9d  49 8d 14 d7  lea rdx, [r15 + rdx*8]
00007ea1  48 83 c2 f8  add rdx, -8
00007ea5  4e 8d 04 2b  lea r8, [rbx + r13]
00007ea9  4f 8d 04 c7  lea r8, [r15 + r8*8]
00007ead  49 83 c0 f8  add r8, -8
00007eb1  4c 8d 0c 03  lea r9, [rbx + rax]
00007eb5  4f 8d 0c cf  lea r9, [r15 + r9*8]
00007eb9  49 83 c1 f8  add r9, -8
00007ebd  45 31 d2  xor r10d, r10d
00007ec0  43 0f 10 04 d1  movups xmm0, xmmword ptr [r9 + r10*8]
00007ec5  42 0f 29 84 d7 f0 02 00 00  movaps xmmword ptr [rdi + r10*8 + 0x2f0], xmm0
00007ece  43 0f 10 04 d0  movups xmm0, xmmword ptr [r8 + r10*8]
00007ed3  42 0f 11 84 d7 f8 04 00 00  movups xmmword ptr [rdi + r10*8 + 0x4f8], xmm0
00007edc  42 0f 10 04 d2  movups xmm0, xmmword ptr [rdx + r10*8]
00007ee1  42 0f 29 84 d7 f0 00 00 00  movaps xmmword ptr [rdi + r10*8 + 0xf0], xmm0
00007eea  49 83 c2 02  add r10, 2
00007eee  49 39 ca  cmp r10, rcx
00007ef1  72 cd  jb 0x180007ec0
00007ef3  49 39 ce  cmp r14, rcx
00007ef6  75 04  jne 0x180007efc
00007ef8  eb 6e  jmp 0x180007f68
00007efa  31 c9  xor ecx, ecx
00007efc  49 29 ce  sub r14, rcx
00007eff  4c 8d 0c 0b  lea r9, [rbx + rcx]
00007f03  4d 01 cc  add r12, r9
00007f06  4b 8d 14 e7  lea rdx, [r15 + r12*8]
00007f0a  48 83 c2 f8  add rdx, -8
00007f0e  48 8d 0c cf  lea rcx, [rdi + rcx*8]
00007f12  48 81 c1 f8 04 00 00  add rcx, 0x4f8
00007f19  4d 01 cd  add r13, r9
00007f1c  4f 8d 04 ef  lea r8, [r15 + r13*8]
00007f20  49 83 c0 f8  add r8, -8
00007f24  4c 01 c8  add rax, r9
00007f27  49 8d 04 c7  lea rax, [r15 + rax*8]
00007f2b  48 83 c0 f8  add rax, -8
00007f2f  45 31 c9  xor r9d, r9d
00007f32  66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00007f40  4e 8b 14 c8  mov r10, qword ptr [rax + r9*8]
00007f44  4e 89 94 c9 f8 fd ff ff  mov qword ptr [rcx + r9*8 - 0x208], r10
00007f4c  4f 8b 14 c8  mov r10, qword ptr [r8 + r9*8]
00007f50  4e 89 14 c9  mov qword ptr [rcx + r9*8], r10
00007f54  4e 8b 14 ca  mov r10, qword ptr [rdx + r9*8]
00007f58  4e 89 94 c9 f8 fb ff ff  mov qword ptr [rcx + r9*8 - 0x408], r10
00007f60  49 ff c1  inc r9
00007f63  4d 39 ce  cmp r14, r9
00007f66  75 d8  jne 0x180007f40
00007f68  49 8b 44 df 18  mov rax, qword ptr [r15 + rbx*8 + 0x18]
00007f6d  49 8b 4c df 30  mov rcx, qword ptr [r15 + rbx*8 + 0x30]
00007f72  48 89 87 c8 07 00 00  mov qword ptr [rdi + 0x7c8], rax
00007f79  48 89 8f f0 04 00 00  mov qword ptr [rdi + 0x4f0], rcx
00007f80  49 8b 44 df 48  mov rax, qword ptr [r15 + rbx*8 + 0x48]
00007f85  48 89 87 f8 06 00 00  mov qword ptr [rdi + 0x6f8], rax
00007f8c  49 8b 44 df 70  mov rax, qword ptr [r15 + rbx*8 + 0x70]
00007f91  48 01 d8  add rax, rbx
00007f94  49 8d 04 c7  lea rax, [r15 + rax*8]
00007f98  48 83 c0 f8  add rax, -8
00007f9c  31 c9  xor ecx, ecx
00007f9e  66 90  nop
00007fa0  48 8b 14 c8  mov rdx, qword ptr [rax + rcx*8]
00007fa4  48 89 94 cf 10 07 00 00  mov qword ptr [rdi + rcx*8 + 0x710], rdx
00007fac  48 ff c1  inc rcx
00007faf  48 83 f9 06  cmp rcx, 6
00007fb3  75 eb  jne 0x180007fa0
00007fb5  4d 8b b4 df 88 00 00 00  mov r14, qword ptr [r15 + rbx*8 + 0x88]
00007fbd  49 8b 8c df 90 00 00 00  mov rcx, qword ptr [r15 + rbx*8 + 0x90]
00007fc5  48 8b 05 fc d2 00 00  mov rax, qword ptr [rip + 0xd2fc]
00007fcc  4c 89 70 10  mov qword ptr [rax + 0x10], r14
00007fd0  48 c7 05 55 87 01 00 01 00 00 00  mov qword ptr [rip + 0x18755], 1
00007fdb  4d 85 f6  test r14, r14
00007fde  4c 8b 25 f3 d4 00 00  mov r12, qword ptr [rip + 0xd4f3]
00007fe5  4c 8d 2d 04 87 01 00  lea r13, [rip + 0x18704]
00007fec  7e 60  jle 0x18000804e
00007fee  48 01 cb  add rbx, rcx
00007ff1  49 83 fe 0c  cmp r14, 0xc
00007ff5  76 23  jbe 0x18000801a
00007ff7  49 8d 14 df  lea rdx, [r15 + rbx*8]
00007ffb  48 83 c2 f8  add rdx, -8
00007fff  4e 8d 04 f5 00 00 00 00  lea r8, [r14*8]
00008007  b9 48 04 00 00  mov ecx, 0x448
0000800c  48 03 0d b5 d2 00 00  add rcx, qword ptr [rip + 0xd2b5]
00008013  e8 08 0d 00 00  call 0x180008d20
00008018  eb 2a  jmp 0x180008044
0000801a  49 8d 0c df  lea rcx, [r15 + rbx*8]
0000801e  48 83 c1 f8  add rcx, -8
00008022  31 d2  xor edx, edx
00008024  66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00008030  4c 8b 04 d1  mov r8, qword ptr [rcx + rdx*8]
00008034  4c 89 84 d0 48 04 00 00  mov qword ptr [rax + rdx*8 + 0x448], r8
0000803c  48 ff c2  inc rdx
0000803f  49 39 d6  cmp r14, rdx
00008042  75 ec  jne 0x180008030
00008044  49 ff c6  inc r14
00008047  4c 89 35 e2 86 01 00  mov qword ptr [rip + 0x186e2], r14
0000804e  48 8b 07  mov rax, qword ptr [rdi]
00008051  4c 8b 35 b0 d3 00 00  mov r14, qword ptr [rip + 0xd3b0]
00008058  49 89 46 58  mov qword ptr [r14 + 0x58], rax
0000805c  49 83 be 88 20 00 00 00  cmp qword ptr [r14 + 0x2088], 0
00008064  48 8b 3d 2d dc 00 00  mov rdi, qword ptr [rip + 0xdc2d]
0000806b  0f 85 3c 01 00 00  jne 0x1800081ad
00008071  48 8b 05 b0 86 01 00  mov rax, qword ptr [rip + 0x186b0]
00008078  49 8b 84 c7 90 04 00 00  mov rax, qword ptr [r15 + rax*8 + 0x490]
00008080  48 89 05 f9 85 01 00  mov qword ptr [rip + 0x185f9], rax
00008087  48 8d 0d f2 85 01 00  lea rcx, [rip + 0x185f2]
0000808e  e8 c1 92 00 00  call 0x180011354
00008093  49 8b 4c c7 f8  mov rcx, qword ptr [r15 + rax*8 - 8]
00008098  48 85 c9  test rcx, rcx
0000809b  7e 36  jle 0x1800080d3
0000809d  49 8b 14 c7  mov rdx, qword ptr [r15 + rax*8]
000080a1  48 01 c2  add rdx, rax
000080a4  49 8d 14 d7  lea rdx, [r15 + rdx*8]
000080a8  48 83 c2 f8  add rdx, -8
000080ac  4c 8d 05 2d 85 01 00  lea r8, [rip + 0x1852d]
000080b3  45 31 c9  xor r9d, r9d
000080b6  66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
000080c0  4e 8b 14 ca  mov r10, qword ptr [rdx + r9*8]
000080c4  4d 89 10  mov qword ptr [r8], r10
000080c7  49 83 c0 08  add r8, 8
000080cb  49 ff c1  inc r9
000080ce  49 39 c9  cmp r9, rcx
000080d1  7c ed  jl 0x1800080c0
000080d3  49 8b 4c c7 08  mov rcx, qword ptr [r15 + rax*8 + 8]
000080d8  48 85 c9  test rcx, rcx
000080db  7e 36  jle 0x180008113
000080dd  49 8b 54 c7 10  mov rdx, qword ptr [r15 + rax*8 + 0x10]
000080e2  48 01 c2  add rdx, rax
000080e5  49 8d 14 d7  lea rdx, [r15 + rdx*8]
000080e9  48 83 c2 f8  add rdx, -8
000080ed  4c 8d 05 cc 84 01 00  lea r8, [rip + 0x184cc]
000080f4  45 31 c9  xor r9d, r9d
000080f7  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00008100  4e 8b 14 ca  mov r10, qword ptr [rdx + r9*8]
00008104  4d 89 10  mov qword ptr [r8], r10
00008107  49 83 c0 08  add r8, 8
0000810b  49 ff c1  inc r9
0000810e  49 39 c9  cmp r9, rcx
00008111  7c ed  jl 0x180008100
00008113  49 8b 4c c7 18  mov rcx, qword ptr [r15 + rax*8 + 0x18]
00008118  48 85 c9  test rcx, rcx
0000811b  7e 36  jle 0x180008153
0000811d  49 8b 54 c7 20  mov rdx, qword ptr [r15 + rax*8 + 0x20]
00008122  48 01 c2  add rdx, rax
00008125  49 8d 14 d7  lea rdx, [r15 + rdx*8]
00008129  48 83 c2 f8  add rdx, -8
0000812d  4c 8d 05 4c 84 01 00  lea r8, [rip + 0x1844c]
00008134  45 31 c9  xor r9d, r9d
00008137  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00008140  4e 8b 14 ca  mov r10, qword ptr [rdx + r9*8]
00008144  4d 89 10  mov qword ptr [r8], r10
00008147  49 83 c0 08  add r8, 8
0000814b  49 ff c1  inc r9
0000814e  49 39 c9  cmp r9, rcx
00008151  7c ed  jl 0x180008140
00008153  49 8b 4c c7 28  mov rcx, qword ptr [r15 + rax*8 + 0x28]
00008158  49 8b 54 c7 30  mov rdx, qword ptr [r15 + rax*8 + 0x30]
0000815d  48 c7 05 c8 85 01 00 01 00 00 00  mov qword ptr [rip + 0x185c8], 1
00008168  48 85 c9  test rcx, rcx
0000816b  7e 40  jle 0x1800081ad
0000816d  48 01 d0  add rax, rdx
00008170  49 8d 04 c7  lea rax, [r15 + rax*8]
00008174  48 83 c0 f8  add rax, -8
00008178  48 8d 15 c1 83 01 00  lea rdx, [rip + 0x183c1]
0000817f  45 31 c0  xor r8d, r8d
00008182  66 66 66 66 66 2e 0f 1f 84 00 00 00 00 00  nop word ptr cs:[rax + rax]
00008190  4e 8b 0c c0  mov r9, qword ptr [rax + r8*8]
00008194  4c 89 0a  mov qword ptr [rdx], r9
00008197  48 83 c2 08  add rdx, 8
0000819b  49 ff c0  inc r8
0000819e  49 39 c8  cmp r8, rcx
000081a1  7c ed  jl 0x180008190
000081a3  48 ff c1  inc rcx
000081a6  48 89 0d 83 85 01 00  mov qword ptr [rip + 0x18583], rcx
000081ad  48 8b 05 74 85 01 00  mov rax, qword ptr [rip + 0x18574]
000081b4  48 8b 84 c6 88 00 00 00  mov rax, qword ptr [rsi + rax*8 + 0x88]
000081bc  48 89 05 b5 84 01 00  mov qword ptr [rip + 0x184b5], rax
000081c3  48 c7 05 a2 84 01 00 01 00 00 00  mov qword ptr [rip + 0x184a2], 1
000081ce  48 85 c0  test rax, rax
000081d1  74 36  je 0x180008209
000081d3  48 8d 1d 9e 84 01 00  lea rbx, [rip + 0x1849e]
000081da  48 89 d9  mov rcx, rbx
000081dd  e8 72 91 00 00  call 0x180011354
000081e2  48 89 05 87 84 01 00  mov qword ptr [rip + 0x18487], rax
000081e9  48 89 d9  mov rcx, rbx
000081ec  e8 7f 93 00 00  call 0x180011570
000081f1  48 8b 0d 78 84 01 00  mov rcx, qword ptr [rip + 0x18478]
000081f8  48 8b 15 f9 d2 00 00  mov rdx, qword ptr [rip + 0xd2f9]
000081ff  48 8d 0c ca  lea rcx, [rdx + rcx*8]
00008203  48 83 c1 f8  add rcx, -8
00008207  eb 05  jmp 0x18000820e
00008209  31 c0  xor eax, eax
0000820b  48 89 f1  mov rcx, rsi
0000820e  49 0f af 44 24 30  imul rax, qword ptr [r12 + 0x30]
00008214  48 89 05 4d 84 01 00  mov qword ptr [rip + 0x1844d], rax
0000821b  48 8d 15 46 84 01 00  lea rdx, [rip + 0x18446]
00008222  4c 8d 47 30  lea r8, [rdi + 0x30]
00008226  4c 8d 0d cb f9 00 00  lea r9, [rip + 0xf9cb]
0000822d  e8 bc 93 00 00  call 0x1800115ee
00008232  48 8b 05 ef 84 01 00  mov rax, qword ptr [rip + 0x184ef]
00008239  48 8b 8c c6 b8 03 00 00  mov rcx, qword ptr [rsi + rax*8 + 0x3b8]
00008241  48 89 0d 18 84 01 00  mov qword ptr [rip + 0x18418], rcx
00008248  48 85 c9  test rcx, rcx
0000824b  74 53  je 0x1800082a0
0000824d  48 8d 0d 0c 84 01 00  lea rcx, [rip + 0x1840c]
00008254  e8 fb 90 00 00  call 0x180011354
00008259  48 8b 0d 98 d2 00 00  mov rcx, qword ptr [rip + 0xd298]
00008260  0f 10 44 c1 f8  movups xmm0, xmmword ptr [rcx + rax*8 - 8]
00008265  0f 10 4c c1 08  movups xmm1, xmmword ptr [rcx + rax*8 + 8]
0000826a  0f 29 07  movaps xmmword ptr [rdi], xmm0
0000826d  0f 29 4f 10  movaps xmmword ptr [rdi + 0x10], xmm1
00008271  48 8b 54 c1 18  mov rdx, qword ptr [rcx + rax*8 + 0x18]
00008276  4c 8b 05 33 da 00 00  mov r8, qword ptr [rip + 0xda33]
0000827d  49 89 90 a8 00 00 00  mov qword ptr [r8 + 0xa8], rdx
00008284  48 8b 54 c1 20  mov rdx, qword ptr [rcx + rax*8 + 0x20]
00008289  48 89 57 28  mov qword ptr [rdi + 0x28], rdx
0000828d  0f 10 44 c1 28  movups xmm0, xmmword ptr [rcx + rax*8 + 0x28]
00008292  0f 29 87 f0 00 00 00  movaps xmmword ptr [rdi + 0xf0], xmm0
00008299  48 8b 05 88 84 01 00  mov rax, qword ptr [rip + 0x18488]
000082a0  48 8b 15 39 d0 00 00  mov rdx, qword ptr [rip + 0xd039]
000082a7  48 c7 42 58 00 00 00 00  mov qword ptr [rdx + 0x58], 0
000082af  48 b9 00 00 00 00 00 00 f0 3f  movabs rcx, 0x3ff0000000000000
000082b9  48 89 4a 60  mov qword ptr [rdx + 0x60], rcx
000082bd  48 8b 3d 34 d2 00 00  mov rdi, qword ptr [rip + 0xd234]
000082c4  48 8d 94 c7 40 05 00 00  lea rdx, [rdi + rax*8 + 0x540]
000082cc  48 8d 0d 2d f9 00 00  lea rcx, [rip + 0xf92d]
000082d3  48 8d 35 96 83 01 00  lea rsi, [rip + 0x18396]
000082da  49 89 f0  mov r8, rsi
000082dd  e8 2c 91 00 00  call 0x18001140e
000082e2  48 8b 05 3f 84 01 00  mov rax, qword ptr [rip + 0x1843f]
000082e9  48 8d 14 c7  lea rdx, [rdi + rax*8]
000082ed  48 81 c2 38 05 00 00  add rdx, 0x538
000082f4  48 8d 0d 0d f9 00 00  lea rcx, [rip + 0xf90d]
000082fb  49 89 f0  mov r8, rsi
000082fe  e8 0b 91 00 00  call 0x18001140e
00008303  48 8b 0d ee cf 00 00  mov rcx, qword ptr [rip + 0xcfee]
0000830a  48 c7 41 08 01 00 00 00  mov qword ptr [rcx + 8], 1
00008312  48 c7 81 e0 06 00 00 10 00 00 00  mov qword ptr [rcx + 0x6e0], 0x10
0000831d  48 c7 81 e8 06 00 00 0f 00 00 00  mov qword ptr [rcx + 0x6e8], 0xf
00008328  48 c7 81 f0 06 00 00 0f 00 00 00  mov qword ptr [rcx + 0x6f0], 0xf
00008333  48 8b 05 ee 83 01 00  mov rax, qword ptr [rip + 0x183ee]
0000833a  48 8b 94 c7 38 05 00 00  mov rdx, qword ptr [rdi + rax*8 + 0x538]
00008342  4c 8b 84 c7 40 05 00 00  mov r8, qword ptr [rdi + rax*8 + 0x540]
0000834a  4c 89 81 a0 06 00 00  mov qword ptr [rcx + 0x6a0], r8
00008351  48 c7 81 a8 06 00 00 01 00 00 00  mov qword ptr [rcx + 0x6a8], 1
0000835c  48 89 91 c0 06 00 00  mov qword ptr [rcx + 0x6c0], rdx
00008363  48 c7 81 c8 06 00 00 01 00 00 00  mov qword ptr [rcx + 0x6c8], 1
0000836e  48 c7 81 b0 06 00 00 00 00 00 00  mov qword ptr [rcx + 0x6b0], 0
00008379  49 83 be 88 20 00 00 00  cmp qword ptr [r14 + 0x2088], 0
00008381  75 0c  jne 0x18000838f
00008383  e8 34 97 00 00  call 0x180011abc
00008388  48 8b 05 99 83 01 00  mov rax, qword ptr [rip + 0x18399]
0000838f  48 8b 84 c7 30 06 00 00  mov rax, qword ptr [rdi + rax*8 + 0x630]
00008397  48 89 05 82 83 01 00  mov qword ptr [rip + 0x18382], rax
0000839e  48 8d 0d 7b 83 01 00  lea rcx, [rip + 0x1837b]
000083a5  e8 aa 8f 00 00  call 0x180011354
000083aa  48 89 05 67 83 01 00  mov qword ptr [rip + 0x18367], rax
000083b1  48 c7 84 c7 b8 00 00 00 00 00 00 00  mov qword ptr [rdi + rax*8 + 0xb8], 0
000083bd  48 8b 05 64 83 01 00  mov rax, qword ptr [rip + 0x18364]
000083c4  48 8b 84 c7 18 01 00 00  mov rax, qword ptr [rdi + rax*8 + 0x118]
000083cc  48 89 05 85 82 01 00  mov qword ptr [rip + 0x18285], rax
000083d3  48 8d 0d 7e 82 01 00  lea rcx, [rip + 0x1827e]
000083da  e8 75 8f 00 00  call 0x180011354
000083df  48 89 05 6a 82 01 00  mov qword ptr [rip + 0x1826a], rax
000083e6  48 8b 44 c7 f8  mov rax, qword ptr [rdi + rax*8 - 8]
000083eb  48 89 05 26 81 01 00  mov qword ptr [rip + 0x18126], rax
000083f2  48 8b 35 f7 d0 00 00  mov rsi, qword ptr [rip + 0xd0f7]
000083f9  48 89 06  mov qword ptr [rsi], rax
000083fc  49 83 be 88 20 00 00 00  cmp qword ptr [r14 + 0x2088], 0
00008404  74 0c  je 0x180008412
00008406  48 8b 0d e3 d0 00 00  mov rcx, qword ptr [rip + 0xd0e3]
0000840d  e8 6a 91 00 00  call 0x18001157c
00008412  48 8d 0d f7 f7 00 00  lea rcx, [rip + 0xf7f7]
00008419  e8 36 8f 00 00  call 0x180011354
0000841e  48 89 05 f3 82 01 00  mov qword ptr [rip + 0x182f3], rax
00008425  48 83 bc c7 d0 03 00 00 00  cmp qword ptr [rdi + rax*8 + 0x3d0], 0
0000842e  74 27  je 0x180008457
00008430  48 8d 0c c7  lea rcx, [rdi + rax*8]
00008434  48 81 c1 d0 03 00 00  add rcx, 0x3d0
0000843b  48 8d 15 2e 82 01 00  lea rdx, [rip + 0x1822e]
00008442  4c 8d 05 67 82 01 00  lea r8, [rip + 0x18267]
00008449  4c 8d 0d a0 82 01 00  lea r9, [rip + 0x182a0]
00008450  e8 83 8f 00 00  call 0x1800113d8
00008455  eb 68  jmp 0x1800084bf
00008457  48 8d 0d c2 f7 00 00  lea rcx, [rip + 0xf7c2]
0000845e  e8 1f 91 00 00  call 0x180011582
00008463  48 8b 06  mov rax, qword ptr [rsi]
00008466  48 8d 0c 40  lea rcx, [rax + rax*2]
0000846a  48 83 c1 03  add rcx, 3
0000846e  48 8d 44 40 0c  lea rax, [rax + rax*2 + 0xc]
00008473  48 8b 15 9e 82 01 00  mov rdx, qword ptr [rip + 0x1829e]
0000847a  4c 8d 84 d7 d0 03 00 00  lea r8, [rdi + rdx*8 + 0x3d0]
00008482  48 89 4c 24 60  mov qword ptr [rsp + 0x60], rcx
00008487  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
0000848c  4c 89 6c 24 28  mov qword ptr [rsp + 0x28], r13
00008491  48 8d 05 18 82 01 00  lea rax, [rip + 0x18218]
00008498  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0000849d  4c 8d 0d cc 81 01 00  lea r9, [rip + 0x181cc]
000084a4  48 8d 4c 24 60  lea rcx, [rsp + 0x60]
000084a9  48 8d 54 24 58  lea rdx, [rsp + 0x58]
000084ae  e8 8d 90 00 00  call 0x180011540
000084b3  48 8d 0d 5e f7 00 00  lea rcx, [rip + 0xf75e]
000084ba  e8 c3 90 00 00  call 0x180011582
000084bf  48 8b 05 82 d7 00 00  mov rax, qword ptr [rip + 0xd782]
000084c6  48 c7 00 ff ff ff ff  mov qword ptr [rax], 0xffffffffffffffff
000084cd  48 8b 0e  mov rcx, qword ptr [rsi]
000084d0  48 89 48 40  mov qword ptr [rax + 0x40], rcx
000084d4  48 c7 40 48 00 00 00 00  mov qword ptr [rax + 0x48], 0
000084dc  48 c7 40 08 01 00 00 00  mov qword ptr [rax + 8], 1
000084e4  48 8d 35 85 81 01 00  lea rsi, [rip + 0x18185]
000084eb  48 8b 15 7e 81 01 00  mov rdx, qword ptr [rip + 0x1817e]
000084f2  48 89 50 10  mov qword ptr [rax + 0x10], rdx
000084f6  4c 8d 44 11 01  lea r8, [rcx + rdx + 1]
000084fb  4c 89 40 18  mov qword ptr [rax + 0x18], r8
000084ff  48 8d 54 4a 02  lea rdx, [rdx + rcx*2 + 2]
00008504  48 89 50 20  mov qword ptr [rax + 0x20], rdx
00008508  48 8d 1d a1 81 01 00  lea rbx, [rip + 0x181a1]
0000850f  48 8b 15 9a 81 01 00  mov rdx, qword ptr [rip + 0x1819a]
00008516  48 89 50 28  mov qword ptr [rax + 0x28], rdx
0000851a  4c 8d 44 11 04  lea r8, [rcx + rdx + 4]
0000851f  4c 89 40 30  mov qword ptr [rax + 0x30], r8
00008523  48 8d 4c 4a 08  lea rcx, [rdx + rcx*2 + 8]
00008528  48 89 48 38  mov qword ptr [rax + 0x38], rcx
0000852c  48 8d 05 25 7f 01 00  lea rax, [rip + 0x17f25]
00008533  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00008538  48 8d 0d 31 7f 01 00  lea rcx, [rip + 0x17f31]
0000853f  48 8d 15 32 7f 01 00  lea rdx, [rip + 0x17f32]
00008546  4c 8d 05 1b 7f 01 00  lea r8, [rip + 0x17f1b]
0000854d  4c 8d 0d 0c 7f 01 00  lea r9, [rip + 0x17f0c]
00008554  e8 2f 90 00 00  call 0x180011588
00008559  48 8b 05 18 7f 01 00  mov rax, qword ptr [rip + 0x17f18]
00008560  48 8b 15 b1 7f 01 00  mov rdx, qword ptr [rip + 0x17fb1]
00008567  48 01 d0  add rax, rdx
0000856a  48 83 c0 06  add rax, 6
0000856e  48 89 05 d3 80 01 00  mov qword ptr [rip + 0x180d3], rax
00008575  48 8d 0d cc 80 01 00  lea rcx, [rip + 0x180cc]
0000857c  48 8b 05 ed 7e 01 00  mov rax, qword ptr [rip + 0x17eed]
00008583  48 c1 e2 04  shl rdx, 4
00008587  48 01 d0  add rax, rdx
0000858a  48 83 c0 1f  add rax, 0x1f
0000858e  48 89 05 ab 80 01 00  mov qword ptr [rip + 0x180ab], rax
00008595  48 8d 15 a4 80 01 00  lea rdx, [rip + 0x180a4]
0000859c  4c 89 6c 24 28  mov qword ptr [rsp + 0x28], r13
000085a1  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
000085a6  4c 8d 05 bb 7b 01 00  lea r8, [rip + 0x17bbb]
000085ad  49 89 f1  mov r9, rsi
000085b0  e8 8b 8f 00 00  call 0x180011540
000085b5  48 8b 0d b4 80 01 00  mov rcx, qword ptr [rip + 0x180b4]
000085bc  48 8d 41 ff  lea rax, [rcx - 1]
000085c0  48 89 05 39 7a 01 00  mov qword ptr [rip + 0x17a39], rax
000085c7  48 8b 05 4a 7f 01 00  mov rax, qword ptr [rip + 0x17f4a]
000085ce  48 8d 4c 08 ff  lea rcx, [rax + rcx - 1]
000085d3  48 89 0d 86 7b 01 00  mov qword ptr [rip + 0x17b86], rcx
000085da  48 8b 0d cf 80 01 00  mov rcx, qword ptr [rip + 0x180cf]
000085e1  48 8d 51 ff  lea rdx, [rcx - 1]
000085e5  48 89 15 34 7a 01 00  mov qword ptr [rip + 0x17a34], rdx
000085ec  48 01 c1  add rcx, rax
000085ef  48 ff c9  dec rcx
000085f2  48 89 0d 47 7a 01 00  mov qword ptr [rip + 0x17a47], rcx
000085f9  48 01 c1  add rcx, rax
000085fc  48 89 0d 5d 7a 01 00  mov qword ptr [rip + 0x17a5d], rcx
00008603  48 01 c1  add rcx, rax
00008606  48 89 0d 73 7a 01 00  mov qword ptr [rip + 0x17a73], rcx
0000860d  48 01 c1  add rcx, rax
00008610  48 89 0d 89 7a 01 00  mov qword ptr [rip + 0x17a89], rcx
00008617  48 01 c1  add rcx, rax
0000861a  48 89 0d 9f 7a 01 00  mov qword ptr [rip + 0x17a9f], rcx
00008621  48 01 c1  add rcx, rax
00008624  48 89 0d b5 7a 01 00  mov qword ptr [rip + 0x17ab5], rcx
0000862b  48 01 c1  add rcx, rax
0000862e  48 89 0d cb 7a 01 00  mov qword ptr [rip + 0x17acb], rcx
00008635  48 01 c1  add rcx, rax
00008638  48 89 0d e1 7a 01 00  mov qword ptr [rip + 0x17ae1], rcx
0000863f  48 01 c1  add rcx, rax
00008642  48 89 0d f7 7a 01 00  mov qword ptr [rip + 0x17af7], rcx
00008649  48 01 c1  add rcx, rax
0000864c  48 89 0d 2d 7b 01 00  mov qword ptr [rip + 0x17b2d], rcx
00008653  48 c7 05 42 7e 01 00 00 00 00 00  mov qword ptr [rip + 0x17e42], 0
0000865e  48 c7 05 2f 7e 01 00 00 00 00 00  mov qword ptr [rip + 0x17e2f], 0
00008669  48 8b 05 b8 80 01 00  mov rax, qword ptr [rip + 0x180b8]
00008670  48 8b 44 c7 10  mov rax, qword ptr [rdi + rax*8 + 0x10]
00008675  48 89 05 4c 7b 01 00  mov qword ptr [rip + 0x17b4c], rax
0000867c  48 85 c0  test rax, rax
0000867f  74 32  je 0x1800086b3
00008681  48 8d 0d 40 7b 01 00  lea rcx, [rip + 0x17b40]
00008688  e8 c7 8c 00 00  call 0x180011354
0000868d  48 8b 4c c7 38  mov rcx, qword ptr [rdi + rax*8 + 0x38]
00008692  48 8b 44 c7 40  mov rax, qword ptr [rdi + rax*8 + 0x40]
00008697  48 89 0d 02 7e 01 00  mov qword ptr [rip + 0x17e02], rcx
0000869e  48 89 05 f3 7d 01 00  mov qword ptr [rip + 0x17df3], rax
000086a5  48 85 c9  test rcx, rcx
000086a8  74 09  je 0x1800086b3
000086aa  48 85 c0  test rax, rax
000086ad  0f 85 8e 00 00 00  jne 0x180008741
000086b3  48 8b 0d 96 7f 01 00  mov rcx, qword ptr [rip + 0x17f96]
000086ba  48 8b 54 cf 20  mov rdx, qword ptr [rdi + rcx*8 + 0x20]
000086bf  48 8b 44 cf 28  mov rax, qword ptr [rdi + rcx*8 + 0x28]
000086c4  48 89 05 c5 7d 01 00  mov qword ptr [rip + 0x17dc5], rax
000086cb  4c 8b 44 cf 38  mov r8, qword ptr [rdi + rcx*8 + 0x38]
000086d0  4c 89 05 b1 7d 01 00  mov qword ptr [rip + 0x17db1], r8
000086d7  48 8b 4c cf 30  mov rcx, qword ptr [rdi + rcx*8 + 0x30]
000086dc  48 01 d1  add rcx, rdx
000086df  48 01 c9  add rcx, rcx
000086e2  48 89 0d 97 7d 01 00  mov qword ptr [rip + 0x17d97], rcx
000086e9  48 85 d2  test rdx, rdx
000086ec  7e 22  jle 0x180008710
000086ee  4d 8d 84 24 80 00 00 00  lea r8, [r12 + 0x80]
000086f6  48 8d 0d 83 7d 01 00  lea rcx, [rip + 0x17d83]
000086fd  48 8d 15 9c 7d 01 00  lea rdx, [rip + 0x17d9c]
00008704  e8 2f 8d 00 00  call 0x180011438
00008709  48 8b 05 80 7d 01 00  mov rax, qword ptr [rip + 0x17d80]
00008710  48 85 c0  test rax, rax
00008713  7e 22  jle 0x180008737
00008715  48 03 05 6c 7d 01 00  add rax, qword ptr [rip + 0x17d6c]
0000871c  48 89 44 24 50  mov qword ptr [rsp + 0x50], rax
00008721  4d 8d 44 24 78  lea r8, [r12 + 0x78]
00008726  48 8d 15 6b 7d 01 00  lea rdx, [rip + 0x17d6b]
0000872d  48 8d 4c 24 50  lea rcx, [rsp + 0x50]
00008732  e8 01 8d 00 00  call 0x180011438
00008737  48 83 3d 61 7d 01 00 00  cmp qword ptr [rip + 0x17d61], 0
0000873f  74 14  je 0x180008755
00008741  48 8d 0d 58 7d 01 00  lea rcx, [rip + 0x17d58]
00008748  e8 bb 8c 00 00  call 0x180011408
0000874d  49 89 84 24 80 00 00 00  mov qword ptr [r12 + 0x80], rax
00008755  48 83 3d 3b 7d 01 00 00  cmp qword ptr [rip + 0x17d3b], 0
0000875d  74 11  je 0x180008770
0000875f  48 8d 0d 32 7d 01 00  lea rcx, [rip + 0x17d32]
00008766  e8 9d 8c 00 00  call 0x180011408
0000876b  49 89 44 24 78  mov qword ptr [r12 + 0x78], rax
00008770  80 3d 81 7a 01 00 00  cmp byte ptr [rip + 0x17a81], 0
00008777  75 23  jne 0x18000879c
00008779  48 c7 45 40 63 00 00 00  mov qword ptr [rbp + 0x40], 0x63
00008781  48 8d 0d 98 f4 00 00  lea rcx, [rip + 0xf498]
00008788  e8 67 8e 00 00  call 0x1800115f4
0000878d  48 c7 45 40 00 00 00 00  mov qword ptr [rbp + 0x40], 0
00008795  c6 05 5c 7a 01 00 01  mov byte ptr [rip + 0x17a5c], 1
0000879c  e8 c1 8c 00 00  call 0x180011462
000087a1  49 83 be 88 20 00 00 00  cmp qword ptr [r14 + 0x2088], 0
000087a9  75 05  jne 0x1800087b0
000087ab  e8 12 93 00 00  call 0x180011ac2
000087b0  0f 28 b4 24 c0 00 00 00  movaps xmm6, xmmword ptr [rsp + 0xc0]
000087b8  48 81 c4 d8 00 00 00  add rsp, 0xd8
000087bf  5b  pop rbx
000087c0  5d  pop rbp
000087c1  5f  pop rdi
000087c2  5e  pop rsi
000087c3  41 5c  pop r12
000087c5  41 5d  pop r13
000087c7  41 5e  pop r14
000087c9  41 5f  pop r15
000087cb  c3  ret
; owner 0x87d0 PPEXEC_UPDRTN
000087d0  48 83 ec 28  sub rsp, 0x28
000087d4  48 8b 05 15 cd 00 00  mov rax, qword ptr [rip + 0xcd15]
000087db  48 8b 00  mov rax, qword ptr [rax]
000087de  48 89 05 f3 7f 01 00  mov qword ptr [rip + 0x17ff3], rax
000087e5  48 8d 0d 7c 79 01 00  lea rcx, [rip + 0x1797c]
000087ec  48 8d 15 fd 7f 01 00  lea rdx, [rip + 0x17ffd]
000087f3  4c 8d 05 ee 7f 01 00  lea r8, [rip + 0x17fee]
000087fa  4c 8d 0d df 7f 01 00  lea r9, [rip + 0x17fdf]
00008801  e8 d2 8b 00 00  call 0x1800113d8
00008806  48 8b 0d e3 7f 01 00  mov rcx, qword ptr [rip + 0x17fe3]
0000880d  48 8d 41 ff  lea rax, [rcx - 1]
00008811  48 89 05 e8 77 01 00  mov qword ptr [rip + 0x177e8], rax
00008818  48 8b 05 b9 7f 01 00  mov rax, qword ptr [rip + 0x17fb9]
0000881f  48 8d 4c 08 ff  lea rcx, [rax + rcx - 1]
00008824  48 89 0d 35 79 01 00  mov qword ptr [rip + 0x17935], rcx
0000882b  48 8b 0d b6 7f 01 00  mov rcx, qword ptr [rip + 0x17fb6]
00008832  48 8d 51 ff  lea rdx, [rcx - 1]
00008836  48 89 15 e3 77 01 00  mov qword ptr [rip + 0x177e3], rdx
0000883d  48 01 c1  add rcx, rax
00008840  48 ff c9  dec rcx
00008843  48 89 0d f6 77 01 00  mov qword ptr [rip + 0x177f6], rcx
0000884a  48 01 c1  add rcx, rax
0000884d  48 89 0d 0c 78 01 00  mov qword ptr [rip + 0x1780c], rcx
00008854  48 01 c1  add rcx, rax
00008857  48 89 0d 22 78 01 00  mov qword ptr [rip + 0x17822], rcx
0000885e  48 01 c1  add rcx, rax
00008861  48 89 0d 38 78 01 00  mov qword ptr [rip + 0x17838], rcx
00008868  48 01 c1  add rcx, rax
0000886b  48 89 0d 4e 78 01 00  mov qword ptr [rip + 0x1784e], rcx
00008872  48 01 c1  add rcx, rax
00008875  48 89 0d 64 78 01 00  mov qword ptr [rip + 0x17864], rcx
0000887c  48 01 c1  add rcx, rax
0000887f  48 89 0d 7a 78 01 00  mov qword ptr [rip + 0x1787a], rcx
00008886  48 01 c1  add rcx, rax
00008889  48 89 0d 90 78 01 00  mov qword ptr [rip + 0x17890], rcx
00008890  48 01 c1  add rcx, rax
00008893  48 89 0d a6 78 01 00  mov qword ptr [rip + 0x178a6], rcx
0000889a  48 01 c1  add rcx, rax
0000889d  48 89 0d dc 78 01 00  mov qword ptr [rip + 0x178dc], rcx
000088a4  48 83 c4 28  add rsp, 0x28
000088a8  c3  ret
; owner 0x88b0 PPEXEC_ALLOCRTN
000088b0  56  push rsi
000088b1  57  push rdi
000088b2  53  push rbx
000088b3  48 83 ec 30  sub rsp, 0x30
000088b7  4c 89 ce  mov rsi, r9
000088ba  48 8b 7c 24 70  mov rdi, qword ptr [rsp + 0x70]
000088bf  48 8b 02  mov rax, qword ptr [rdx]
000088c2  48 8b 1d 27 cc 00 00  mov rbx, qword ptr [rip + 0xcc27]
000088c9  48 8b 13  mov rdx, qword ptr [rbx]
000088cc  48 8d 44 10 06  lea rax, [rax + rdx + 6]
000088d1  48 89 05 40 7f 01 00  mov qword ptr [rip + 0x17f40], rax
000088d8  48 8d 05 39 7f 01 00  lea rax, [rip + 0x17f39]
000088df  48 8b 09  mov rcx, qword ptr [rcx]
000088e2  48 c1 e2 04  shl rdx, 4
000088e6  48 01 d1  add rcx, rdx
000088e9  48 83 c1 1f  add rcx, 0x1f
000088ed  48 89 0d 1c 7f 01 00  mov qword ptr [rip + 0x17f1c], rcx
000088f4  48 8d 15 15 7f 01 00  lea rdx, [rip + 0x17f15]
000088fb  48 8d 0d f6 7e 01 00  lea rcx, [rip + 0x17ef6]
00008902  48 89 4c 24 28  mov qword ptr [rsp + 0x28], rcx
00008907  48 8d 0d f2 7e 01 00  lea rcx, [rip + 0x17ef2]
0000890e  48 89 4c 24 20  mov qword ptr [rsp + 0x20], rcx
00008913  4c 8d 0d ee 7e 01 00  lea r9, [rip + 0x17eee]
0000891a  48 89 c1  mov rcx, rax
0000891d  e8 1e 8c 00 00  call 0x180011540
00008922  48 8b 0d df 7e 01 00  mov rcx, qword ptr [rip + 0x17edf]
00008929  48 8d 41 ff  lea rax, [rcx - 1]
0000892d  48 89 05 cc 76 01 00  mov qword ptr [rip + 0x176cc], rax
00008934  48 8b 03  mov rax, qword ptr [rbx]
00008937  48 8d 4c 08 ff  lea rcx, [rax + rcx - 1]
0000893c  48 89 0f  mov qword ptr [rdi], rcx
0000893f  48 8b 0d ba 7e 01 00  mov rcx, qword ptr [rip + 0x17eba]
00008946  48 8d 51 ff  lea rdx, [rcx - 1]
0000894a  48 89 15 cf 76 01 00  mov qword ptr [rip + 0x176cf], rdx
00008951  48 01 c1  add rcx, rax
00008954  48 ff c9  dec rcx
00008957  48 89 0d e2 76 01 00  mov qword ptr [rip + 0x176e2], rcx
0000895e  48 01 c1  add rcx, rax
00008961  48 89 0d f8 76 01 00  mov qword ptr [rip + 0x176f8], rcx
00008968  48 01 c1  add rcx, rax
0000896b  48 89 0d 0e 77 01 00  mov qword ptr [rip + 0x1770e], rcx
00008972  48 01 c1  add rcx, rax
00008975  48 89 0d 24 77 01 00  mov qword ptr [rip + 0x17724], rcx
0000897c  48 01 c1  add rcx, rax
0000897f  48 89 0d 3a 77 01 00  mov qword ptr [rip + 0x1773a], rcx
00008986  48 01 c1  add rcx, rax
00008989  48 89 0d 50 77 01 00  mov qword ptr [rip + 0x17750], rcx
00008990  48 01 c1  add rcx, rax
00008993  48 89 0d 66 77 01 00  mov qword ptr [rip + 0x17766], rcx
0000899a  48 01 c1  add rcx, rax
0000899d  48 89 0d 7c 77 01 00  mov qword ptr [rip + 0x1777c], rcx
000089a4  48 01 c1  add rcx, rax
000089a7  48 89 0d 92 77 01 00  mov qword ptr [rip + 0x17792], rcx
000089ae  48 01 c1  add rcx, rax
000089b1  48 89 0e  mov qword ptr [rsi], rcx
000089b4  48 83 c4 30  add rsp, 0x30
000089b8  5b  pop rbx
000089b9  5f  pop rdi
000089ba  5e  pop rsi
000089bb  c3  ret
; owner 0x89c0 PPEXEC_APINIT
000089c0  41 57  push r15
000089c2  41 56  push r14
000089c4  41 55  push r13
000089c6  41 54  push r12
000089c8  56  push rsi
000089c9  57  push rdi
000089ca  53  push rbx
000089cb  48 83 ec 60  sub rsp, 0x60
000089cf  4c 89 ce  mov rsi, r9
000089d2  4d 89 c7  mov r15, r8
000089d5  48 89 d7  mov rdi, rdx
000089d8  49 89 ce  mov r14, rcx
000089db  48 8b 9c 24 c0 00 00 00  mov rbx, qword ptr [rsp + 0xc0]
000089e3  4c 8b ac 24 c8 00 00 00  mov r13, qword ptr [rsp + 0xc8]
000089eb  48 8b 05 4e c8 00 00  mov rax, qword ptr [rip + 0xc84e]
000089f2  48 c7 00 01 00 00 00  mov qword ptr [rax], 1
000089f9  48 8b 05 f8 c8 00 00  mov rax, qword ptr [rip + 0xc8f8]
00008a00  48 c7 00 1e 00 00 00  mov qword ptr [rax], 0x1e
00008a07  48 c7 40 08 01 00 00 00  mov qword ptr [rax + 8], 1
00008a0f  48 c7 80 10 07 00 00 32 00 00 00  mov qword ptr [rax + 0x710], 0x32
00008a1a  48 c7 80 18 07 00 00 01 00 00 00  mov qword ptr [rax + 0x718], 1
00008a25  48 8b 05 ec c8 00 00  mov rax, qword ptr [rip + 0xc8ec]
00008a2c  48 c7 00 28 00 00 00  mov qword ptr [rax], 0x28
00008a33  48 c7 40 08 01 00 00 00  mov qword ptr [rax + 8], 1
00008a3b  48 8b 05 96 ca 00 00  mov rax, qword ptr [rip + 0xca96]
00008a42  48 c7 80 58 01 00 00 00 00 00 00  mov qword ptr [rax + 0x158], 0
00008a4d  4c 8b 25 04 c8 00 00  mov r12, qword ptr [rip + 0xc804]
00008a54  49 8d 8c 24 00 18 00 00  lea rcx, [r12 + 0x1800]
00008a5c  41 b8 ff 00 00 00  mov r8d, 0xff
00008a62  4c 89 fa  mov rdx, r15
00008a65  e8 b6 02 00 00  call 0x180008d20
00008a6a  41 c6 84 24 ff 18 00 00 20  mov byte ptr [r12 + 0x18ff], 0x20
00008a73  4c 8d 25 86 7e 01 00  lea r12, [rip + 0x17e86]
00008a7a  41 b8 ff 00 00 00  mov r8d, 0xff
00008a80  4c 89 e1  mov rcx, r12
00008a83  4c 89 fa  mov rdx, r15
00008a86  e8 95 02 00 00  call 0x180008d20
00008a8b  ba ff 00 00 00  mov edx, 0xff
00008a90  4c 89 e1  mov rcx, r12
00008a93  e8 fc 8a 00 00  call 0x180011594
00008a98  ba ff 00 00 00  mov edx, 0xff
00008a9d  4c 89 e1  mov rcx, r12
00008aa0  e8 f5 8a 00 00  call 0x18001159a
00008aa5  4a 8d 0c 20  lea rcx, [rax + r12]
00008aa9  48 83 c1 f9  add rcx, -7
00008aad  48 c7 44 24 20 02 00 00 00  mov qword ptr [rsp + 0x20], 2
00008ab6  4c 8d 05 78 f1 00 00  lea r8, [rip + 0xf178]
00008abd  ba 07 00 00 00  mov edx, 7
00008ac2  41 b9 07 00 00 00  mov r9d, 7
00008ac8  e8 4f 90 00 00  call 0x180011b1c
00008acd  83 e0 01  and eax, 1
00008ad0  48 ff c0  inc rax
00008ad3  48 89 05 56 7d 01 00  mov qword ptr [rip + 0x17d56], rax
00008ada  48 8d 0d 4f 7d 01 00  lea rcx, [rip + 0x17d4f]
00008ae1  e8 ba 8a 00 00  call 0x1800115a0
00008ae6  0f 28 05 03 ec 00 00  movaps xmm0, xmmword ptr [rip + 0xec03]
00008aed  0f 29 05 fc 7d 01 00  movaps xmmword ptr [rip + 0x17dfc], xmm0
00008af4  0f 29 05 e5 7d 01 00  movaps xmmword ptr [rip + 0x17de5], xmm0
00008afb  0f 29 05 ce 7d 01 00  movaps xmmword ptr [rip + 0x17dce], xmm0
00008b02  0f 29 05 b7 7d 01 00  movaps xmmword ptr [rip + 0x17db7], xmm0
00008b09  0f 29 05 a0 7d 01 00  movaps xmmword ptr [rip + 0x17da0], xmm0
00008b10  0f 29 05 89 7d 01 00  movaps xmmword ptr [rip + 0x17d89], xmm0
00008b17  0f 29 05 72 7d 01 00  movaps xmmword ptr [rip + 0x17d72], xmm0
00008b1e  0f 29 05 5b 7d 01 00  movaps xmmword ptr [rip + 0x17d5b], xmm0
00008b25  0f 29 05 44 7d 01 00  movaps xmmword ptr [rip + 0x17d44], xmm0
00008b2c  0f 29 05 2d 7d 01 00  movaps xmmword ptr [rip + 0x17d2d], xmm0
00008b33  4c 8d 05 26 7d 01 00  lea r8, [rip + 0x17d26]
00008b3a  49 8b 45 00  mov rax, qword ptr [r13]
00008b3e  48 89 c1  mov rcx, rax
00008b41  48 c1 e9 3e  shr rcx, 0x3e
00008b45  83 e1 fe  and ecx, 0xfffffffe
00008b48  48 89 0d e9 7c 01 00  mov qword ptr [rip + 0x17ce9], rcx
00008b4f  48 8d 15 e2 7c 01 00  lea rdx, [rip + 0x17ce2]
00008b56  48 89 c1  mov rcx, rax
00008b59  48 f7 d9  neg rcx
00008b5c  48 0f 48 c8  cmovs rcx, rax
00008b60  48 89 4c 24 58  mov qword ptr [rsp + 0x58], rcx
00008b65  48 8d 4c 24 58  lea rcx, [rsp + 0x58]
00008b6a  e8 df 87 00 00  call 0x18001134e
00008b6f  48 c7 05 a6 7c 01 00 00 00 00 00  mov qword ptr [rip + 0x17ca6], 0
00008b7a  48 8d 05 9f 7c 01 00  lea rax, [rip + 0x17c9f]
00008b81  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00008b86  4c 89 6c 24 20  mov qword ptr [rsp + 0x20], r13
00008b8b  4c 89 f1  mov rcx, r14
00008b8e  48 89 fa  mov rdx, rdi
00008b91  49 89 f0  mov r8, rsi
00008b94  49 89 d9  mov r9, rbx
00008b97  e8 14 da ff ff  call 0x1800065b0
00008b9c  48 83 3d 7c 7c 01 00 00  cmp qword ptr [rip + 0x17c7c], 0
00008ba4  0f 85 45 01 00 00  jne 0x180008cef
00008baa  48 8d 35 9f f0 00 00  lea rsi, [rip + 0xf09f]
00008bb1  48 89 f1  mov rcx, rsi
00008bb4  e8 ed 89 00 00  call 0x1800115a6
00008bb9  4c 8b 3d 80 c7 00 00  mov r15, qword ptr [rip + 0xc780]
00008bc0  49 89 47 18  mov qword ptr [r15 + 0x18], rax
00008bc4  49 8d 7f 18  lea rdi, [r15 + 0x18]
00008bc8  48 8d 15 71 f0 00 00  lea rdx, [rip + 0xf071]
00008bcf  48 8d 1d 58 f0 00 00  lea rbx, [rip + 0xf058]
00008bd6  41 b9 07 00 00 00  mov r9d, 7
00008bdc  48 89 f9  mov rcx, rdi
00008bdf  49 89 d8  mov r8, rbx
00008be2  e8 cb 89 00 00  call 0x1800115b2
00008be7  4c 8d 35 5a f0 00 00  lea r14, [rip + 0xf05a]
00008bee  4c 8d 05 33 f0 00 00  lea r8, [rip + 0xf033]
00008bf5  41 b9 06 00 00 00  mov r9d, 6
00008bfb  48 89 f9  mov rcx, rdi
00008bfe  4c 89 f2  mov rdx, r14
00008c01  e8 ac 89 00 00  call 0x1800115b2
00008c06  41 b8 07 00 00 00  mov r8d, 7
00008c0c  48 89 f9  mov rcx, rdi
00008c0f  48 89 da  mov rdx, rbx
00008c12  e8 a1 89 00 00  call 0x1800115b8
00008c17  49 89 47 20  mov qword ptr [r15 + 0x20], rax
00008c1b  48 89 f9  mov rcx, rdi
00008c1e  4c 89 f2  mov rdx, r14
00008c21  4d 89 f0  mov r8, r14
00008c24  e8 95 89 00 00  call 0x1800115be
00008c29  e8 d2 83 ff ff  call 0x180001000
00008c2e  e8 9d 87 ff ff  call 0x1800013d0
00008c33  48 89 f1  mov rcx, rsi
00008c36  e8 19 87 00 00  call 0x180011354
00008c3b  48 8b 35 b6 c8 00 00  mov rsi, qword ptr [rip + 0xc8b6]
00008c42  48 8b 84 c6 28 03 00 00  mov rax, qword ptr [rsi + rax*8 + 0x328]
00008c4a  48 89 05 ef 7b 01 00  mov qword ptr [rip + 0x17bef], rax
00008c51  48 8d 0d e8 7b 01 00  lea rcx, [rip + 0x17be8]
00008c58  e8 f7 86 00 00  call 0x180011354
00008c5d  48 8d 04 c6  lea rax, [rsi + rax*8]
00008c61  48 83 c0 f8  add rax, -8
00008c65  31 c9  xor ecx, ecx
00008c67  48 8b 15 d2 cf 00 00  mov rdx, qword ptr [rip + 0xcfd2]
00008c6e  66 90  nop
00008c70  4c 8b 04 c8  mov r8, qword ptr [rax + rcx*8]
00008c74  4c 89 04 ca  mov qword ptr [rdx + rcx*8], r8
00008c78  48 ff c1  inc rcx
00008c7b  48 83 f9 06  cmp rcx, 6
00008c7f  75 ef  jne 0x180008c70
00008c81  48 83 3d a7 7b 01 00 01  cmp qword ptr [rip + 0x17ba7], 1
00008c89  75 64  jne 0x180008cef
00008c8b  48 c7 05 92 7b 01 00 00 00 00 00  mov qword ptr [rip + 0x17b92], 0
00008c96  48 8d 35 8b 7b 01 00  lea rsi, [rip + 0x17b8b]
00008c9d  48 8d 0d fc 5a 01 00  lea rcx, [rip + 0x15afc]
00008ca4  48 8d 15 b5 5a 01 00  lea rdx, [rip + 0x15ab5]
00008cab  49 89 f0  mov r8, rsi
00008cae  e8 11 89 00 00  call 0x1800115c4
00008cb3  48 8b 15 ae c7 00 00  mov rdx, qword ptr [rip + 0xc7ae]
00008cba  48 83 c2 08  add rdx, 8
00008cbe  48 89 54 24 50  mov qword ptr [rsp + 0x50], rdx
00008cc3  48 89 54 24 48  mov qword ptr [rsp + 0x48], rdx
00008cc8  48 89 54 24 40  mov qword ptr [rsp + 0x40], rdx
00008ccd  48 89 54 24 38  mov qword ptr [rsp + 0x38], rdx
00008cd2  48 89 54 24 30  mov qword ptr [rsp + 0x30], rdx
00008cd7  48 89 54 24 28  mov qword ptr [rsp + 0x28], rdx
00008cdc  48 89 54 24 20  mov qword ptr [rsp + 0x20], rdx
00008ce1  48 89 f1  mov rcx, rsi
00008ce4  49 89 d0  mov r8, rdx
00008ce7  49 89 d1  mov r9, rdx
00008cea  e8 db 88 00 00  call 0x1800115ca
00008cef  90  nop
00008cf0  48 83 c4 60  add rsp, 0x60
00008cf4  5b  pop rbx
00008cf5  5f  pop rdi
00008cf6  5e  pop rsi
00008cf7  41 5c  pop r12
00008cf9  41 5d  pop r13
00008cfb  41 5e  pop r14
00008cfd  41 5f  pop r15
00008cff  c3  ret
; owner 0x8d00 FUN_180008d00
00008d00  48 8d 05 99 01 00 00  lea rax, [rip + 0x199]
; owner 0x8d10 FUN_180008d10
00008d10  48 8d 05 a9 19 00 00  lea rax, [rip + 0x19a9]
; owner 0x8d20 FUN_180008d20
00008d20  48 8b 05 69 7d 01 00  mov rax, qword ptr [rip + 0x17d69]
00008d30  48 ff e0  jmp rax
; owner 0x8d40 runtime_8d40
00008d40  56  push rsi
00008d47  48 8b 05 62 7d 01 00  mov rax, qword ptr [rip + 0x17d62]
00008dab  4c 8d 0d be 9e 00 00  lea r9, [rip + 0x9ebe]
00008db2  48 8d 05 e1 b9 00 00  lea rax, [rip + 0xb9e1]
00008dbd  48 89 05 cc 7c 01 00  mov qword ptr [rip + 0x17ccc], rax
00008dcb  48 ff e0  jmp rax
; owner 0x8dd0 FUN_180008dd0
00008dd0  48 8d 05 69 52 00 00  lea rax, [rip + 0x5269]
; owner 0x8de0 FUN_180008de0
00008de0  48 8d 05 19 63 00 00  lea rax, [rip + 0x6319]
; owner 0x8df0 FUN_180008df0
00008df0  48 8b 05 a1 7c 01 00  mov rax, qword ptr [rip + 0x17ca1]
00008e00  48 ff e0  jmp rax
; owner 0x8e10 runtime_8e10
00008e10  56  push rsi
00008e17  48 8b 05 92 7c 01 00  mov rax, qword ptr [rip + 0x17c92]
00008e78  4c 8d 0d a1 ae 00 00  lea r9, [rip + 0xaea1]
00008e7f  48 8d 05 0e b9 00 00  lea rax, [rip + 0xb90e]
00008e8a  48 89 05 07 7c 01 00  mov qword ptr [rip + 0x17c07], rax
00008e98  48 ff e0  jmp rax
; owner 0x8ea0 runtime_8ea0
00008ea0  41 56  push r14
00008eb4  4c 8d 0d d5 0f 00 00  lea r9, [rip + 0xfd5]
00008ebf  3e 41 ff e1  notrack jmp r9
00008ed0  4c 8d 0d b9 06 00 00  lea r9, [rip + 0x6b9]
00008efa  3e 41 ff e1  notrack jmp r9
00008f13  4c 8b 0d 6e 59 01 00  mov r9, qword ptr [rip + 0x1596e]
00008fd0  4c 3b 05 a1 58 01 00  cmp r8, qword ptr [rip + 0x158a1]
00009199  4c 8d 0d f0 04 00 00  lea r9, [rip + 0x4f0]
000091a4  3e 41 ff e1  notrack jmp r9
0000920f  4c 8d 0d 7a 04 00 00  lea r9, [rip + 0x47a]
0000921d  3e 41 ff e1  notrack jmp r9
; owner 0xa6c0 runtime_a6c0
0000a6c0  56  push rsi
0000a6c4  4c 8d 0d f5 16 00 00  lea r9, [rip + 0x16f5]
0000a6e4  41 ff e1  jmp r9
0000a6e7  4c 8d 0d d2 04 00 00  lea r9, [rip + 0x4d2]
0000a711  41 ff e1  jmp r9
0000a727  4c 3b 05 4a 41 01 00  cmp r8, qword ptr [rip + 0x1414a]
0000aa46  4c 8d 0d 73 03 00 00  lea r9, [rip + 0x373]
0000aa51  41 ff e1  jmp r9
; owner 0xc1d0 runtime_c1d0
0000c1d0  50  push rax
0000c1d1  b8 01 00 00 00  mov eax, 1
0000c1d6  e8 15 00 00 00  call 0x18000c1f0
0000c1db  90  nop
0000c1dc  48 83 c4 08  add rsp, 8
0000c1e0  c3  ret
; owner 0xc1f0 runtime_c1f0
0000c1f0  41 53  push r11
0000c1f2  41 52  push r10
0000c1f4  41 51  push r9
0000c1f6  41 50  push r8
0000c1f8  52  push rdx
0000c1f9  51  push rcx
0000c1fa  41 57  push r15
0000c1fc  41 56  push r14
0000c1fe  41 55  push r13
0000c200  41 54  push r12
0000c202  56  push rsi
0000c203  57  push rdi
0000c204  55  push rbp
0000c205  53  push rbx
0000c206  48 81 ec c8 00 00 00  sub rsp, 0xc8
0000c20d  0f 29 ac 24 b0 00 00 00  movaps xmmword ptr [rsp + 0xb0], xmm5
0000c215  0f 29 a4 24 a0 00 00 00  movaps xmmword ptr [rsp + 0xa0], xmm4
0000c21d  0f 29 9c 24 90 00 00 00  movaps xmmword ptr [rsp + 0x90], xmm3
0000c225  0f 29 94 24 80 00 00 00  movaps xmmword ptr [rsp + 0x80], xmm2
0000c22d  0f 29 4c 24 70  movaps xmmword ptr [rsp + 0x70], xmm1
0000c232  0f 29 44 24 60  movaps xmmword ptr [rsp + 0x60], xmm0
0000c237  89 c6  mov esi, eax
0000c239  48 8b 05 c0 25 01 00  mov rax, qword ptr [rip + 0x125c0]
0000c240  48 31 e0  xor rax, rsp
0000c243  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
0000c248  0f 57 c0  xorps xmm0, xmm0
0000c24b  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c250  0f 29 00  movaps xmmword ptr [rax], xmm0
0000c253  0f 29 44 24 30  movaps xmmword ptr [rsp + 0x30], xmm0
0000c258  b9 01 00 00 00  mov ecx, 1
0000c25d  e8 7e 1d 00 00  call 0x18000dfe0
0000c262  41 89 c6  mov r14d, eax
0000c265  85 c0  test eax, eax
0000c267  0f 85 39 06 00 00  jne 0x18000c8a6
0000c26d  31 c0  xor eax, eax
0000c26f  0f a2  cpuid
0000c271  89 44 24 2c  mov dword ptr [rsp + 0x2c], eax
0000c275  89 5c 24 28  mov dword ptr [rsp + 0x28], ebx
0000c279  89 4c 24 24  mov dword ptr [rsp + 0x24], ecx
0000c27d  89 54 24 20  mov dword ptr [rsp + 0x20], edx
0000c281  83 7c 24 2c 00  cmp dword ptr [rsp + 0x2c], 0
0000c286  0f 84 0b 06 00 00  je 0x18000c897
0000c28c  83 fe 01  cmp esi, 1
0000c28f  75 2a  jne 0x18000c2bb
0000c291  81 7c 24 28 47 65 6e 75  cmp dword ptr [rsp + 0x28], 0x756e6547
0000c299  0f 85 f8 05 00 00  jne 0x18000c897
0000c29f  81 7c 24 20 69 6e 65 49  cmp dword ptr [rsp + 0x20], 0x49656e69
0000c2a7  0f 85 ea 05 00 00  jne 0x18000c897
0000c2ad  81 7c 24 24 6e 74 65 6c  cmp dword ptr [rsp + 0x24], 0x6c65746e
0000c2b5  0f 85 dc 05 00 00  jne 0x18000c897
0000c2bb  b8 01 00 00 00  mov eax, 1
0000c2c0  0f a2  cpuid
0000c2c2  41 89 c8  mov r8d, ecx
0000c2c5  f6 c2 01  test dl, 1
0000c2c8  74 1a  je 0x18000c2e4
0000c2ca  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c2cf  b9 02 00 00 00  mov ecx, 2
0000c2d4  e8 07 1d 00 00  call 0x18000dfe0
0000c2d9  41 89 c6  mov r14d, eax
0000c2dc  85 c0  test eax, eax
0000c2de  0f 85 c2 05 00 00  jne 0x18000c8a6
0000c2e4  66 85 d2  test dx, dx
0000c2e7  79 1a  jns 0x18000c303
0000c2e9  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c2ee  b9 03 00 00 00  mov ecx, 3
0000c2f3  e8 e8 1c 00 00  call 0x18000dfe0
0000c2f8  41 89 c6  mov r14d, eax
0000c2fb  85 c0  test eax, eax
0000c2fd  0f 85 a3 05 00 00  jne 0x18000c8a6
0000c303  0f ba e2 17  bt edx, 0x17
0000c307  73 1a  jae 0x18000c323
0000c309  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c30e  b9 04 00 00 00  mov ecx, 4
0000c313  e8 c8 1c 00 00  call 0x18000dfe0
0000c318  41 89 c6  mov r14d, eax
0000c31b  85 c0  test eax, eax
0000c31d  0f 85 83 05 00 00  jne 0x18000c8a6
0000c323  0f ba e2 18  bt edx, 0x18
0000c327  0f 82 d1 05 00 00  jb 0x18000c8fe
0000c32d  41 0f ba e0 1e  bt r8d, 0x1e
0000c332  73 1a  jae 0x18000c34e
0000c334  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c339  b9 12 00 00 00  mov ecx, 0x12
0000c33e  e8 9d 1c 00 00  call 0x18000dfe0
0000c343  41 89 c6  mov r14d, eax
0000c346  85 c0  test eax, eax
0000c348  0f 85 58 05 00 00  jne 0x18000c8a6
0000c34e  0f ba e2 18  bt edx, 0x18
0000c352  72 10  jb 0x18000c364
0000c354  b8 07 00 00 00  mov eax, 7
0000c359  31 c9  xor ecx, ecx
0000c35b  0f a2  cpuid
0000c35d  89 cd  mov ebp, ecx
0000c35f  89 d7  mov edi, edx
0000c361  41 89 d9  mov r9d, ebx
0000c364  44 89 c8  mov eax, r9d
0000c367  f7 d0  not eax
0000c369  a9 08 01 00 00  test eax, 0x108
0000c36e  75 1a  jne 0x18000c38a
0000c370  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c375  b9 14 00 00 00  mov ecx, 0x14
0000c37a  e8 61 1c 00 00  call 0x18000dfe0
0000c37f  41 89 c6  mov r14d, eax
0000c382  85 c0  test eax, eax
0000c384  0f 85 1c 05 00 00  jne 0x18000c8a6
0000c38a  41 f6 c1 04  test r9b, 4
0000c38e  74 1a  je 0x18000c3aa
0000c390  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c395  b9 36 00 00 00  mov ecx, 0x36
0000c39a  e8 41 1c 00 00  call 0x18000dfe0
0000c39f  41 89 c6  mov r14d, eax
0000c3a2  85 c0  test eax, eax
0000c3a4  0f 85 fc 04 00 00  jne 0x18000c8a6
0000c3aa  41 f6 c1 10  test r9b, 0x10
0000c3ae  74 1a  je 0x18000c3ca
0000c3b0  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c3b5  b9 16 00 00 00  mov ecx, 0x16
0000c3ba  e8 21 1c 00 00  call 0x18000dfe0
0000c3bf  41 89 c6  mov r14d, eax
0000c3c2  85 c0  test eax, eax
0000c3c4  0f 85 dc 04 00 00  jne 0x18000c8a6
0000c3ca  41 0f ba e1 0b  bt r9d, 0xb
0000c3cf  73 1a  jae 0x18000c3eb
0000c3d1  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c3d6  b9 17 00 00 00  mov ecx, 0x17
0000c3db  e8 00 1c 00 00  call 0x18000dfe0
0000c3e0  41 89 c6  mov r14d, eax
0000c3e3  85 c0  test eax, eax
0000c3e5  0f 85 bb 04 00 00  jne 0x18000c8a6
0000c3eb  41 0f ba e1 13  bt r9d, 0x13
0000c3f0  73 1a  jae 0x18000c40c
0000c3f2  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c3f7  b9 1d 00 00 00  mov ecx, 0x1d
0000c3fc  e8 df 1b 00 00  call 0x18000dfe0
0000c401  41 89 c6  mov r14d, eax
0000c404  85 c0  test eax, eax
0000c406  0f 85 9a 04 00 00  jne 0x18000c8a6
0000c40c  41 0f ba e1 12  bt r9d, 0x12
0000c411  73 1a  jae 0x18000c42d
0000c413  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c418  b9 1e 00 00 00  mov ecx, 0x1e
0000c41d  e8 be 1b 00 00  call 0x18000dfe0
0000c422  41 89 c6  mov r14d, eax
0000c425  85 c0  test eax, eax
0000c427  0f 85 79 04 00 00  jne 0x18000c8a6
0000c42d  41 0f ba e1 18  bt r9d, 0x18
0000c432  73 1a  jae 0x18000c44e
0000c434  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c439  b9 32 00 00 00  mov ecx, 0x32
0000c43e  e8 9d 1b 00 00  call 0x18000dfe0
0000c443  41 89 c6  mov r14d, eax
0000c446  85 c0  test eax, eax
0000c448  0f 85 58 04 00 00  jne 0x18000c8a6
0000c44e  b8 01 00 00 80  mov eax, 0x80000001
0000c453  0f a2  cpuid
0000c455  f6 c1 20  test cl, 0x20
0000c458  74 1a  je 0x18000c474
0000c45a  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c45f  b9 15 00 00 00  mov ecx, 0x15
0000c464  e8 77 1b 00 00  call 0x18000dfe0
0000c469  41 89 c6  mov r14d, eax
0000c46c  85 c0  test eax, eax
0000c46e  0f 85 32 04 00 00  jne 0x18000c8a6
0000c474  b8 08 00 00 80  mov eax, 0x80000008
0000c479  0f a2  cpuid
0000c47b  0f ba e3 09  bt ebx, 9
0000c47f  73 1a  jae 0x18000c49b
0000c481  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c486  b9 37 00 00 00  mov ecx, 0x37
0000c48b  e8 50 1b 00 00  call 0x18000dfe0
0000c490  41 89 c6  mov r14d, eax
0000c493  85 c0  test eax, eax
0000c495  0f 85 0b 04 00 00  jne 0x18000c8a6
0000c49b  40 f6 c5 20  test bpl, 0x20
0000c49f  74 1a  je 0x18000c4bb
0000c4a1  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c4a6  b9 3e 00 00 00  mov ecx, 0x3e
0000c4ab  e8 30 1b 00 00  call 0x18000dfe0
0000c4b0  41 89 c6  mov r14d, eax
0000c4b3  85 c0  test eax, eax
0000c4b5  0f 85 eb 03 00 00  jne 0x18000c8a6
0000c4bb  40 84 ed  test bpl, bpl
0000c4be  79 1a  jns 0x18000c4da
0000c4c0  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c4c5  b9 35 00 00 00  mov ecx, 0x35
0000c4ca  e8 11 1b 00 00  call 0x18000dfe0
0000c4cf  41 89 c6  mov r14d, eax
0000c4d2  85 c0  test eax, eax
0000c4d4  0f 85 cc 03 00 00  jne 0x18000c8a6
0000c4da  0f ba e5 08  bt ebp, 8
0000c4de  73 1a  jae 0x18000c4fa
0000c4e0  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c4e5  b9 2e 00 00 00  mov ecx, 0x2e
0000c4ea  e8 f1 1a 00 00  call 0x18000dfe0
0000c4ef  41 89 c6  mov r14d, eax
0000c4f2  85 c0  test eax, eax
0000c4f4  0f 85 ac 03 00 00  jne 0x18000c8a6
0000c4fa  0f ba e5 16  bt ebp, 0x16
0000c4fe  73 1a  jae 0x18000c51a
0000c500  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c505  b9 33 00 00 00  mov ecx, 0x33
0000c50a  e8 d1 1a 00 00  call 0x18000dfe0
0000c50f  41 89 c6  mov r14d, eax
0000c512  85 c0  test eax, eax
0000c514  0f 85 8c 03 00 00  jne 0x18000c8a6
0000c51a  0f ba e5 19  bt ebp, 0x19
0000c51e  73 1a  jae 0x18000c53a
0000c520  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c525  b9 3b 00 00 00  mov ecx, 0x3b
0000c52a  e8 b1 1a 00 00  call 0x18000dfe0
0000c52f  41 89 c6  mov r14d, eax
0000c532  85 c0  test eax, eax
0000c534  0f 85 6c 03 00 00  jne 0x18000c8a6
0000c53a  0f ba e5 1b  bt ebp, 0x1b
0000c53e  73 1a  jae 0x18000c55a
0000c540  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c545  b9 3c 00 00 00  mov ecx, 0x3c
0000c54a  e8 91 1a 00 00  call 0x18000dfe0
0000c54f  41 89 c6  mov r14d, eax
0000c552  85 c0  test eax, eax
0000c554  0f 85 4c 03 00 00  jne 0x18000c8a6
0000c55a  0f ba e5 1c  bt ebp, 0x1c
0000c55e  73 1a  jae 0x18000c57a
0000c560  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c565  b9 3d 00 00 00  mov ecx, 0x3d
0000c56a  e8 71 1a 00 00  call 0x18000dfe0
0000c56f  41 89 c6  mov r14d, eax
0000c572  85 c0  test eax, eax
0000c574  0f 85 2c 03 00 00  jne 0x18000c8a6
0000c57a  0f ba e5 1d  bt ebp, 0x1d
0000c57e  73 1a  jae 0x18000c59a
0000c580  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c585  b9 40 00 00 00  mov ecx, 0x40
0000c58a  e8 51 1a 00 00  call 0x18000dfe0
0000c58f  41 89 c6  mov r14d, eax
0000c592  85 c0  test eax, eax
0000c594  0f 85 0c 03 00 00  jne 0x18000c8a6
0000c59a  0f ba e7 14  bt edi, 0x14
0000c59e  73 1a  jae 0x18000c5ba
0000c5a0  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c5a5  b9 34 00 00 00  mov ecx, 0x34
0000c5aa  e8 31 1a 00 00  call 0x18000dfe0
0000c5af  41 89 c6  mov r14d, eax
0000c5b2  85 c0  test eax, eax
0000c5b4  0f 85 ec 02 00 00  jne 0x18000c8a6
0000c5ba  0f ba e7 12  bt edi, 0x12
0000c5be  73 1a  jae 0x18000c5da
0000c5c0  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c5c5  b9 38 00 00 00  mov ecx, 0x38
0000c5ca  e8 11 1a 00 00  call 0x18000dfe0
0000c5cf  41 89 c6  mov r14d, eax
0000c5d2  85 c0  test eax, eax
0000c5d4  0f 85 cc 02 00 00  jne 0x18000c8a6
0000c5da  b8 14 00 00 00  mov eax, 0x14
0000c5df  31 c9  xor ecx, ecx
0000c5e1  0f a2  cpuid
0000c5e3  f6 c3 10  test bl, 0x10
0000c5e6  74 1a  je 0x18000c602
0000c5e8  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c5ed  b9 1b 00 00 00  mov ecx, 0x1b
0000c5f2  e8 e9 19 00 00  call 0x18000dfe0
0000c5f7  41 89 c6  mov r14d, eax
0000c5fa  85 c0  test eax, eax
0000c5fc  0f 85 a4 02 00 00  jne 0x18000c8a6
0000c602  0f ba e5 17  bt ebp, 0x17
0000c606  0f 82 91 04 00 00  jb 0x18000ca9d
0000c60c  b8 07 00 00 00  mov eax, 7
0000c611  b9 01 00 00 00  mov ecx, 1
0000c616  0f a2  cpuid
0000c618  41 89 d3  mov r11d, edx
0000c61b  41 89 c2  mov r10d, eax
0000c61e  0f ba e0 16  bt eax, 0x16
0000c622  73 1a  jae 0x18000c63e
0000c624  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c629  b9 47 00 00 00  mov ecx, 0x47
0000c62e  e8 ad 19 00 00  call 0x18000dfe0
0000c633  41 89 c6  mov r14d, eax
0000c636  85 c0  test eax, eax
0000c638  0f 85 68 02 00 00  jne 0x18000c8a6
0000c63e  40 f6 c7 20  test dil, 0x20
0000c642  74 1a  je 0x18000c65e
0000c644  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c649  b9 48 00 00 00  mov ecx, 0x48
0000c64e  e8 8d 19 00 00  call 0x18000dfe0
0000c653  41 89 c6  mov r14d, eax
0000c656  85 c0  test eax, eax
0000c658  0f 85 48 02 00 00  jne 0x18000c8a6
0000c65e  41 0f ba e3 0e  bt r11d, 0xe
0000c663  73 1a  jae 0x18000c67f
0000c665  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c66a  b9 49 00 00 00  mov ecx, 0x49
0000c66f  e8 6c 19 00 00  call 0x18000dfe0
0000c674  41 89 c6  mov r14d, eax
0000c677  85 c0  test eax, eax
0000c679  0f 85 27 02 00 00  jne 0x18000c8a6
0000c67f  45 84 d2  test r10b, r10b
0000c682  79 1a  jns 0x18000c69e
0000c684  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c689  b9 4b 00 00 00  mov ecx, 0x4b
0000c68e  e8 4d 19 00 00  call 0x18000dfe0
0000c693  41 89 c6  mov r14d, eax
0000c696  85 c0  test eax, eax
0000c698  0f 85 08 02 00 00  jne 0x18000c8a6
0000c69e  41 f6 c2 08  test r10b, 8
0000c6a2  74 1a  je 0x18000c6be
0000c6a4  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c6a9  b9 4e 00 00 00  mov ecx, 0x4e
0000c6ae  e8 2d 19 00 00  call 0x18000dfe0
0000c6b3  41 89 c6  mov r14d, eax
0000c6b6  85 c0  test eax, eax
0000c6b8  0f 85 e8 01 00 00  jne 0x18000c8a6
0000c6be  66 45 85 db  test r11w, r11w
0000c6c2  79 1a  jns 0x18000c6de
0000c6c4  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c6c9  b9 55 00 00 00  mov ecx, 0x55
0000c6ce  e8 0d 19 00 00  call 0x18000dfe0
0000c6d3  41 89 c6  mov r14d, eax
0000c6d6  85 c0  test eax, eax
0000c6d8  0f 85 c8 01 00 00  jne 0x18000c8a6
0000c6de  41 0f ba e3 15  bt r11d, 0x15
0000c6e3  73 1a  jae 0x18000c6ff
0000c6e5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c6ea  b9 58 00 00 00  mov ecx, 0x58
0000c6ef  e8 ec 18 00 00  call 0x18000dfe0
0000c6f4  41 89 c6  mov r14d, eax
0000c6f7  85 c0  test eax, eax
0000c6f9  0f 85 a7 01 00 00  jne 0x18000c8a6
0000c6ff  41 0f ba e2 1b  bt r10d, 0x1b
0000c704  73 1a  jae 0x18000c720
0000c706  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c70b  b9 59 00 00 00  mov ecx, 0x59
0000c710  e8 cb 18 00 00  call 0x18000dfe0
0000c715  41 89 c6  mov r14d, eax
0000c718  85 c0  test eax, eax
0000c71a  0f 85 86 01 00 00  jne 0x18000c8a6
0000c720  41 0f ba e2 13  bt r10d, 0x13
0000c725  73 1a  jae 0x18000c741
0000c727  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c72c  b9 5a 00 00 00  mov ecx, 0x5a
0000c731  e8 aa 18 00 00  call 0x18000dfe0
0000c736  41 89 c6  mov r14d, eax
0000c739  85 c0  test eax, eax
0000c73b  0f 85 65 01 00 00  jne 0x18000c8a6
0000c741  f6 c3 02  test bl, 2
0000c744  74 1a  je 0x18000c760
0000c746  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c74b  b9 5b 00 00 00  mov ecx, 0x5b
0000c750  e8 8b 18 00 00  call 0x18000dfe0
0000c755  41 89 c6  mov r14d, eax
0000c758  85 c0  test eax, eax
0000c75a  0f 85 46 01 00 00  jne 0x18000c8a6
0000c760  41 0f ba e3 13  bt r11d, 0x13
0000c765  0f 82 9c 03 00 00  jb 0x18000cb07
0000c76b  41 0f ba e0 1b  bt r8d, 0x1b
0000c770  0f 82 fd 03 00 00  jb 0x18000cb73
0000c776  48 8d 0d f3 b4 00 00  lea rcx, [rip + 0xb4f3]
0000c77d  e8 66 80 00 00  call 0x1800147e8
0000c782  48 85 c0  test rax, rax
0000c785  0f 84 81 07 00 00  je 0x18000cf0c
0000c78b  48 89 c7  mov rdi, rax
0000c78e  8a 00  mov al, byte ptr [rax]
0000c790  84 c0  test al, al
0000c792  0f 84 74 07 00 00  je 0x18000cf0c
0000c798  45 31 c0  xor r8d, r8d
0000c79b  4c 8d 0d 2e 43 01 00  lea r9, [rip + 0x1432e]
0000c7a2  48 8d 54 24 30  lea rdx, [rsp + 0x30]
0000c7a7  45 31 d2  xor r10d, r10d
0000c7aa  4c 8d 5f 01  lea r11, [rdi + 1]
0000c7ae  bb 01 00 00 00  mov ebx, 1
0000c7b3  48 29 fb  sub rbx, rdi
0000c7b6  49 89 fe  mov r14, rdi
0000c7b9  3c 2c  cmp al, 0x2c
0000c7bb  75 0f  jne 0x18000c7cc
0000c7bd  41 8a 46 01  mov al, byte ptr [r14 + 1]
0000c7c1  49 ff c6  inc r14
0000c7c4  49 ff c3  inc r11
0000c7c7  48 ff cb  dec rbx
0000c7ca  eb ed  jmp 0x18000c7b9
0000c7cc  0f b6 c0  movzx eax, al
0000c7cf  85 c0  test eax, eax
0000c7d1  0f 84 21 07 00 00  je 0x18000cef8
0000c7d7  4c 89 df  mov rdi, r11
0000c7da  48 89 f8  mov rax, rdi
0000c7dd  0f b6 0f  movzx ecx, byte ptr [rdi]
0000c7e0  48 ff c7  inc rdi
0000c7e3  83 f9 2c  cmp ecx, 0x2c
0000c7e6  74 09  je 0x18000c7f1
0000c7e8  85 c9  test ecx, ecx
0000c7ea  74 05  je 0x18000c7f1
0000c7ec  49 89 c2  mov r10, rax
0000c7ef  eb e9  jmp 0x18000c7da
0000c7f1  4d 89 d7  mov r15, r10
0000c7f4  4d 29 f7  sub r15, r14
0000c7f7  49 ff c7  inc r15
0000c7fa  74 73  je 0x18000c86f
0000c7fc  80 3d bd 42 01 00 00  cmp byte ptr [rip + 0x142bd], 0
0000c803  75 05  jne 0x18000c80a
0000c805  e8 b6 09 00 00  call 0x18000d1c0
0000c80a  4c 89 f8  mov rax, r15
0000c80d  48 83 e0 fe  and rax, 0xfffffffffffffffe
0000c811  4c 01 d3  add rbx, r10
0000c814  48 d1 eb  shr rbx, 1
0000c817  b9 01 00 00 00  mov ecx, 1
0000c81c  4c 8d 24 49  lea r12, [rcx + rcx*2]
0000c820  4f 8b 64 e1 10  mov r12, qword ptr [r9 + r12*8 + 0x10]
0000c825  4d 85 e4  test r12, r12
0000c828  74 3c  je 0x18000c866
0000c82a  4d 39 d6  cmp r14, r10
0000c82d  74 21  je 0x18000c850
0000c82f  45 31 ed  xor r13d, r13d
0000c832  43 8a 6c 6b ff  mov bpl, byte ptr [r11 + r13*2 - 1]
0000c837  43 3a 2c 6c  cmp bpl, byte ptr [r12 + r13*2]
0000c83b  75 29  jne 0x18000c866
0000c83d  43 8a 2c 6b  mov bpl, byte ptr [r11 + r13*2]
0000c841  43 3a 6c 6c 01  cmp bpl, byte ptr [r12 + r13*2 + 1]
0000c846  75 1e  jne 0x18000c866
0000c848  49 ff c5  inc r13
0000c84b  4c 39 eb  cmp rbx, r13
0000c84e  75 e2  jne 0x18000c832
0000c850  49 39 c7  cmp r15, rax
0000c853  74 0a  je 0x18000c85f
0000c855  41 8a 2c 06  mov bpl, byte ptr [r14 + rax]
0000c859  41 3a 2c 04  cmp bpl, byte ptr [r12 + rax]
0000c85d  75 07  jne 0x18000c866
0000c85f  43 80 3c 3c 00  cmp byte ptr [r12 + r15], 0
0000c864  74 1b  je 0x18000c881
0000c866  48 ff c1  inc rcx
0000c869  48 83 f9 5c  cmp rcx, 0x5c
0000c86d  75 ad  jne 0x18000c81c
0000c86f  48 ff cf  dec rdi
0000c872  8a 07  mov al, byte ptr [rdi]
0000c874  84 c0  test al, al
0000c876  0f 85 2e ff ff ff  jne 0x18000c7aa
0000c87c  e9 77 06 00 00  jmp 0x18000cef8
0000c881  83 f9 02  cmp ecx, 2
0000c884  72 e9  jb 0x18000c86f
0000c886  48 89 d0  mov rax, rdx
0000c889  e8 52 17 00 00  call 0x18000dfe0
0000c88e  83 f8 01  cmp eax, 1
0000c891  49 83 d0 00  adc r8, 0
0000c895  eb d8  jmp 0x18000c86f
0000c897  0f 28 44 24 40  movaps xmm0, xmmword ptr [rsp + 0x40]
0000c89c  0f 29 05 fd 41 01 00  movaps xmmword ptr [rip + 0x141fd], xmm0
0000c8a3  45 31 f6  xor r14d, r14d
0000c8a6  48 8b 4c 24 58  mov rcx, qword ptr [rsp + 0x58]
0000c8ab  48 31 e1  xor rcx, rsp
0000c8ae  e8 7d 7f 00 00  call 0x180014830
0000c8b3  44 89 f0  mov eax, r14d
0000c8b6  0f 28 44 24 60  movaps xmm0, xmmword ptr [rsp + 0x60]
0000c8bb  0f 28 4c 24 70  movaps xmm1, xmmword ptr [rsp + 0x70]
0000c8c0  0f 28 94 24 80 00 00 00  movaps xmm2, xmmword ptr [rsp + 0x80]
0000c8c8  0f 28 9c 24 90 00 00 00  movaps xmm3, xmmword ptr [rsp + 0x90]
0000c8d0  0f 28 a4 24 a0 00 00 00  movaps xmm4, xmmword ptr [rsp + 0xa0]
0000c8d8  0f 28 ac 24 b0 00 00 00  movaps xmm5, xmmword ptr [rsp + 0xb0]
0000c8e0  48 81 c4 c8 00 00 00  add rsp, 0xc8
0000c8e7  5b  pop rbx
0000c8e8  5d  pop rbp
0000c8e9  5f  pop rdi
0000c8ea  5e  pop rsi
0000c8eb  41 5c  pop r12
0000c8ed  41 5d  pop r13
0000c8ef  41 5e  pop r14
0000c8f1  41 5f  pop r15
0000c8f3  59  pop rcx
0000c8f4  5a  pop rdx
0000c8f5  41 58  pop r8
0000c8f7  41 59  pop r9
0000c8f9  41 5a  pop r10
0000c8fb  41 5b  pop r11
0000c8fd  c3  ret
0000c8fe  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c903  b9 05 00 00 00  mov ecx, 5
0000c908  e8 d3 16 00 00  call 0x18000dfe0
0000c90d  41 89 c6  mov r14d, eax
0000c910  85 c0  test eax, eax
0000c912  75 92  jne 0x18000c8a6
0000c914  0f ba e2 19  bt edx, 0x19
0000c918  73 1a  jae 0x18000c934
0000c91a  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c91f  b9 06 00 00 00  mov ecx, 6
0000c924  e8 b7 16 00 00  call 0x18000dfe0
0000c929  41 89 c6  mov r14d, eax
0000c92c  85 c0  test eax, eax
0000c92e  0f 85 72 ff ff ff  jne 0x18000c8a6
0000c934  0f ba e2 1a  bt edx, 0x1a
0000c938  73 1a  jae 0x18000c954
0000c93a  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c93f  b9 07 00 00 00  mov ecx, 7
0000c944  e8 97 16 00 00  call 0x18000dfe0
0000c949  41 89 c6  mov r14d, eax
0000c94c  85 c0  test eax, eax
0000c94e  0f 85 52 ff ff ff  jne 0x18000c8a6
0000c954  41 f6 c0 01  test r8b, 1
0000c958  74 1a  je 0x18000c974
0000c95a  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c95f  b9 08 00 00 00  mov ecx, 8
0000c964  e8 77 16 00 00  call 0x18000dfe0
0000c969  41 89 c6  mov r14d, eax
0000c96c  85 c0  test eax, eax
0000c96e  0f 85 32 ff ff ff  jne 0x18000c8a6
0000c974  41 0f ba e0 09  bt r8d, 9
0000c979  73 1a  jae 0x18000c995
0000c97b  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c980  b9 09 00 00 00  mov ecx, 9
0000c985  e8 56 16 00 00  call 0x18000dfe0
0000c98a  41 89 c6  mov r14d, eax
0000c98d  85 c0  test eax, eax
0000c98f  0f 85 11 ff ff ff  jne 0x18000c8a6
0000c995  41 0f ba e0 16  bt r8d, 0x16
0000c99a  73 1a  jae 0x18000c9b6
0000c99c  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c9a1  b9 0c 00 00 00  mov ecx, 0xc
0000c9a6  e8 35 16 00 00  call 0x18000dfe0
0000c9ab  41 89 c6  mov r14d, eax
0000c9ae  85 c0  test eax, eax
0000c9b0  0f 85 f0 fe ff ff  jne 0x18000c8a6
0000c9b6  41 0f ba e0 13  bt r8d, 0x13
0000c9bb  73 1a  jae 0x18000c9d7
0000c9bd  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c9c2  b9 0a 00 00 00  mov ecx, 0xa
0000c9c7  e8 14 16 00 00  call 0x18000dfe0
0000c9cc  41 89 c6  mov r14d, eax
0000c9cf  85 c0  test eax, eax
0000c9d1  0f 85 cf fe ff ff  jne 0x18000c8a6
0000c9d7  41 0f ba e0 14  bt r8d, 0x14
0000c9dc  73 1a  jae 0x18000c9f8
0000c9de  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000c9e3  b9 0b 00 00 00  mov ecx, 0xb
0000c9e8  e8 f3 15 00 00  call 0x18000dfe0
0000c9ed  41 89 c6  mov r14d, eax
0000c9f0  85 c0  test eax, eax
0000c9f2  0f 85 ae fe ff ff  jne 0x18000c8a6
0000c9f8  41 0f ba e0 17  bt r8d, 0x17
0000c9fd  73 1a  jae 0x18000ca19
0000c9ff  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ca04  b9 0d 00 00 00  mov ecx, 0xd
0000ca09  e8 d2 15 00 00  call 0x18000dfe0
0000ca0e  41 89 c6  mov r14d, eax
0000ca11  85 c0  test eax, eax
0000ca13  0f 85 8d fe ff ff  jne 0x18000c8a6
0000ca19  41 f6 c0 02  test r8b, 2
0000ca1d  74 1a  je 0x18000ca39
0000ca1f  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ca24  b9 0e 00 00 00  mov ecx, 0xe
0000ca29  e8 b2 15 00 00  call 0x18000dfe0
0000ca2e  41 89 c6  mov r14d, eax
0000ca31  85 c0  test eax, eax
0000ca33  0f 85 6d fe ff ff  jne 0x18000c8a6
0000ca39  41 0f ba e0 19  bt r8d, 0x19
0000ca3e  73 1a  jae 0x18000ca5a
0000ca40  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ca45  b9 0f 00 00 00  mov ecx, 0xf
0000ca4a  e8 91 15 00 00  call 0x18000dfe0
0000ca4f  41 89 c6  mov r14d, eax
0000ca52  85 c0  test eax, eax
0000ca54  0f 85 4c fe ff ff  jne 0x18000c8a6
0000ca5a  41 89 d2  mov r10d, edx
0000ca5d  b8 07 00 00 00  mov eax, 7
0000ca62  31 c9  xor ecx, ecx
0000ca64  0f a2  cpuid
0000ca66  89 cd  mov ebp, ecx
0000ca68  89 d7  mov edi, edx
0000ca6a  41 89 d9  mov r9d, ebx
0000ca6d  0f ba e3 1d  bt ebx, 0x1d
0000ca71  72 08  jb 0x18000ca7b
0000ca73  44 89 d2  mov edx, r10d
0000ca76  e9 b2 f8 ff ff  jmp 0x18000c32d
0000ca7b  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ca80  b9 24 00 00 00  mov ecx, 0x24
0000ca85  e8 56 15 00 00  call 0x18000dfe0
0000ca8a  41 89 c6  mov r14d, eax
0000ca8d  85 c0  test eax, eax
0000ca8f  44 89 d2  mov edx, r10d
0000ca92  0f 85 0e fe ff ff  jne 0x18000c8a6
0000ca98  e9 90 f8 ff ff  jmp 0x18000c32d
0000ca9d  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000caa2  b9 01 00 00 00  mov ecx, 1
0000caa7  e8 34 15 00 00  call 0x18000dfe0
0000caac  41 89 c6  mov r14d, eax
0000caaf  85 c0  test eax, eax
0000cab1  0f 85 ef fd ff ff  jne 0x18000c8a6
0000cab7  b8 19 00 00 00  mov eax, 0x19
0000cabc  31 c9  xor ecx, ecx
0000cabe  0f a2  cpuid
0000cac0  f6 c3 01  test bl, 1
0000cac3  74 1a  je 0x18000cadf
0000cac5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000caca  b9 45 00 00 00  mov ecx, 0x45
0000cacf  e8 0c 15 00 00  call 0x18000dfe0
0000cad4  41 89 c6  mov r14d, eax
0000cad7  85 c0  test eax, eax
0000cad9  0f 85 c7 fd ff ff  jne 0x18000c8a6
0000cadf  f6 c3 04  test bl, 4
0000cae2  0f 84 24 fb ff ff  je 0x18000c60c
0000cae8  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000caed  b9 46 00 00 00  mov ecx, 0x46
0000caf2  e8 e9 14 00 00  call 0x18000dfe0
0000caf7  41 89 c6  mov r14d, eax
0000cafa  85 c0  test eax, eax
0000cafc  0f 85 a4 fd ff ff  jne 0x18000c8a6
0000cb02  e9 05 fb ff ff  jmp 0x18000c60c
0000cb07  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cb0c  b9 01 00 00 00  mov ecx, 1
0000cb11  e8 ca 14 00 00  call 0x18000dfe0
0000cb16  41 89 c6  mov r14d, eax
0000cb19  85 c0  test eax, eax
0000cb1b  0f 85 85 fd ff ff  jne 0x18000c8a6
0000cb21  b8 24 00 00 00  mov eax, 0x24
0000cb26  31 c9  xor ecx, ecx
0000cb28  0f a2  cpuid
0000cb2a  0f ba e3 11  bt ebx, 0x11
0000cb2e  73 1a  jae 0x18000cb4a
0000cb30  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cb35  b9 56 00 00 00  mov ecx, 0x56
0000cb3a  e8 a1 14 00 00  call 0x18000dfe0
0000cb3f  41 89 c6  mov r14d, eax
0000cb42  85 c0  test eax, eax
0000cb44  0f 85 5c fd ff ff  jne 0x18000c8a6
0000cb4a  0f ba e3 12  bt ebx, 0x12
0000cb4e  0f 83 17 fc ff ff  jae 0x18000c76b
0000cb54  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cb59  b9 57 00 00 00  mov ecx, 0x57
0000cb5e  e8 7d 14 00 00  call 0x18000dfe0
0000cb63  41 89 c6  mov r14d, eax
0000cb66  85 c0  test eax, eax
0000cb68  0f 85 38 fd ff ff  jne 0x18000c8a6
0000cb6e  e9 f8 fb ff ff  jmp 0x18000c76b
0000cb73  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cb78  b9 01 00 00 00  mov ecx, 1
0000cb7d  e8 5e 14 00 00  call 0x18000dfe0
0000cb82  41 89 c6  mov r14d, eax
0000cb85  85 c0  test eax, eax
0000cb87  0f 85 19 fd ff ff  jne 0x18000c8a6
0000cb8d  31 c9  xor ecx, ecx
0000cb8f  0f 01 d0  xgetbv
0000cb92  89 c2  mov edx, eax
0000cb94  f7 d2  not edx
0000cb96  f7 c2 00 00 06 00  test edx, 0x60000
0000cb9c  75 24  jne 0x18000cbc2
0000cb9e  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cba3  b9 01 00 00 00  mov ecx, 1
0000cba8  e8 33 14 00 00  call 0x18000dfe0
0000cbad  41 89 c6  mov r14d, eax
0000cbb0  85 c0  test eax, eax
0000cbb2  0f 85 ee fc ff ff  jne 0x18000c8a6
0000cbb8  0f ba e7 18  bt edi, 0x18
0000cbbc  0f 82 92 03 00 00  jb 0x18000cf54
0000cbc2  f6 c2 06  test dl, 6
0000cbc5  0f 85 ab fb ff ff  jne 0x18000c776
0000cbcb  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cbd0  b9 01 00 00 00  mov ecx, 1
0000cbd5  e8 06 14 00 00  call 0x18000dfe0
0000cbda  41 89 c6  mov r14d, eax
0000cbdd  85 c0  test eax, eax
0000cbdf  0f 85 c1 fc ff ff  jne 0x18000c8a6
0000cbe5  41 0f ba e0 1c  bt r8d, 0x1c
0000cbea  0f 82 09 04 00 00  jb 0x18000cff9
0000cbf0  41 0f ba e0 1d  bt r8d, 0x1d
0000cbf5  73 1a  jae 0x18000cc11
0000cbf7  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cbfc  b9 11 00 00 00  mov ecx, 0x11
0000cc01  e8 da 13 00 00  call 0x18000dfe0
0000cc06  41 89 c6  mov r14d, eax
0000cc09  85 c0  test eax, eax
0000cc0b  0f 85 95 fc ff ff  jne 0x18000c8a6
0000cc11  41 f6 c1 20  test r9b, 0x20
0000cc15  0f 85 61 04 00 00  jne 0x18000d07c
0000cc1b  41 0f ba e0 0c  bt r8d, 0xc
0000cc20  73 1a  jae 0x18000cc3c
0000cc22  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cc27  b9 13 00 00 00  mov ecx, 0x13
0000cc2c  e8 af 13 00 00  call 0x18000dfe0
0000cc31  41 89 c6  mov r14d, eax
0000cc34  85 c0  test eax, eax
0000cc36  0f 85 6a fc ff ff  jne 0x18000c8a6
0000cc3c  f6 c2 18  test dl, 0x18
0000cc3f  75 3b  jne 0x18000cc7c
0000cc41  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cc46  b9 01 00 00 00  mov ecx, 1
0000cc4b  e8 90 13 00 00  call 0x18000dfe0
0000cc50  41 89 c6  mov r14d, eax
0000cc53  85 c0  test eax, eax
0000cc55  0f 85 4b fc ff ff  jne 0x18000c8a6
0000cc5b  41 0f ba e1 0e  bt r9d, 0xe
0000cc60  73 1a  jae 0x18000cc7c
0000cc62  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cc67  b9 25 00 00 00  mov ecx, 0x25
0000cc6c  e8 6f 13 00 00  call 0x18000dfe0
0000cc71  41 89 c6  mov r14d, eax
0000cc74  85 c0  test eax, eax
0000cc76  0f 85 2a fc ff ff  jne 0x18000c8a6
0000cc7c  41 f6 c2 10  test r10b, 0x10
0000cc80  74 1a  je 0x18000cc9c
0000cc82  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cc87  b9 41 00 00 00  mov ecx, 0x41
0000cc8c  e8 4f 13 00 00  call 0x18000dfe0
0000cc91  41 89 c6  mov r14d, eax
0000cc94  85 c0  test eax, eax
0000cc96  0f 85 0a fc ff ff  jne 0x18000c8a6
0000cc9c  f6 c2 e0  test dl, 0xe0
0000cc9f  0f 85 d1 fa ff ff  jne 0x18000c776
0000cca5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ccaa  b9 01 00 00 00  mov ecx, 1
0000ccaf  e8 2c 13 00 00  call 0x18000dfe0
0000ccb4  41 89 c6  mov r14d, eax
0000ccb7  85 c0  test eax, eax
0000ccb9  0f 85 e7 fb ff ff  jne 0x18000c8a6
0000ccbf  41 0f ba e1 10  bt r9d, 0x10
0000ccc4  73 1a  jae 0x18000cce0
0000ccc6  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cccb  b9 19 00 00 00  mov ecx, 0x19
0000ccd0  e8 0b 13 00 00  call 0x18000dfe0
0000ccd5  41 89 c6  mov r14d, eax
0000ccd8  85 c0  test eax, eax
0000ccda  0f 85 c6 fb ff ff  jne 0x18000c8a6
0000cce0  41 0f ba e1 1c  bt r9d, 0x1c
0000cce5  73 1a  jae 0x18000cd01
0000cce7  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ccec  b9 23 00 00 00  mov ecx, 0x23
0000ccf1  e8 ea 12 00 00  call 0x18000dfe0
0000ccf6  41 89 c6  mov r14d, eax
0000ccf9  85 c0  test eax, eax
0000ccfb  0f 85 a5 fb ff ff  jne 0x18000c8a6
0000cd01  41 0f ba e1 1b  bt r9d, 0x1b
0000cd06  73 1a  jae 0x18000cd22
0000cd08  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cd0d  b9 21 00 00 00  mov ecx, 0x21
0000cd12  e8 c9 12 00 00  call 0x18000dfe0
0000cd17  41 89 c6  mov r14d, eax
0000cd1a  85 c0  test eax, eax
0000cd1c  0f 85 84 fb ff ff  jne 0x18000c8a6
0000cd22  41 0f ba e1 1a  bt r9d, 0x1a
0000cd27  73 1a  jae 0x18000cd43
0000cd29  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cd2e  b9 22 00 00 00  mov ecx, 0x22
0000cd33  e8 a8 12 00 00  call 0x18000dfe0
0000cd38  41 89 c6  mov r14d, eax
0000cd3b  85 c0  test eax, eax
0000cd3d  0f 85 63 fb ff ff  jne 0x18000c8a6
0000cd43  41 0f ba e1 11  bt r9d, 0x11
0000cd48  73 1a  jae 0x18000cd64
0000cd4a  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cd4f  b9 1a 00 00 00  mov ecx, 0x1a
0000cd54  e8 87 12 00 00  call 0x18000dfe0
0000cd59  41 89 c6  mov r14d, eax
0000cd5c  85 c0  test eax, eax
0000cd5e  0f 85 42 fb ff ff  jne 0x18000c8a6
0000cd64  41 0f ba e1 1e  bt r9d, 0x1e
0000cd69  73 1a  jae 0x18000cd85
0000cd6b  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cd70  b9 26 00 00 00  mov ecx, 0x26
0000cd75  e8 66 12 00 00  call 0x18000dfe0
0000cd7a  41 89 c6  mov r14d, eax
0000cd7d  85 c0  test eax, eax
0000cd7f  0f 85 21 fb ff ff  jne 0x18000c8a6
0000cd85  45 85 c9  test r9d, r9d
0000cd88  0f 88 d3 03 00 00  js 0x18000d161
0000cd8e  41 0f ba e1 15  bt r9d, 0x15
0000cd93  73 1a  jae 0x18000cdaf
0000cd95  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cd9a  b9 1f 00 00 00  mov ecx, 0x1f
0000cd9f  e8 3c 12 00 00  call 0x18000dfe0
0000cda4  41 89 c6  mov r14d, eax
0000cda7  85 c0  test eax, eax
0000cda9  0f 85 f7 fa ff ff  jne 0x18000c8a6
0000cdaf  40 f6 c5 02  test bpl, 2
0000cdb3  74 1a  je 0x18000cdcf
0000cdb5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cdba  b9 28 00 00 00  mov ecx, 0x28
0000cdbf  e8 1c 12 00 00  call 0x18000dfe0
0000cdc4  41 89 c6  mov r14d, eax
0000cdc7  85 c0  test eax, eax
0000cdc9  0f 85 d7 fa ff ff  jne 0x18000c8a6
0000cdcf  0f ba e5 0e  bt ebp, 0xe
0000cdd3  73 1a  jae 0x18000cdef
0000cdd5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cdda  b9 2b 00 00 00  mov ecx, 0x2b
0000cddf  e8 fc 11 00 00  call 0x18000dfe0
0000cde4  41 89 c6  mov r14d, eax
0000cde7  85 c0  test eax, eax
0000cde9  0f 85 b7 fa ff ff  jne 0x18000c8a6
0000cdef  40 f6 c7 04  test dil, 4
0000cdf3  74 1a  je 0x18000ce0f
0000cdf5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cdfa  b9 2a 00 00 00  mov ecx, 0x2a
0000cdff  e8 dc 11 00 00  call 0x18000dfe0
0000ce04  41 89 c6  mov r14d, eax
0000ce07  85 c0  test eax, eax
0000ce09  0f 85 97 fa ff ff  jne 0x18000c8a6
0000ce0f  40 f6 c7 08  test dil, 8
0000ce13  74 1a  je 0x18000ce2f
0000ce15  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ce1a  b9 29 00 00 00  mov ecx, 0x29
0000ce1f  e8 bc 11 00 00  call 0x18000dfe0
0000ce24  41 89 c6  mov r14d, eax
0000ce27  85 c0  test eax, eax
0000ce29  0f 85 77 fa ff ff  jne 0x18000c8a6
0000ce2f  0f ba e5 0c  bt ebp, 0xc
0000ce33  73 1a  jae 0x18000ce4f
0000ce35  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ce3a  b9 2c 00 00 00  mov ecx, 0x2c
0000ce3f  e8 9c 11 00 00  call 0x18000dfe0
0000ce44  41 89 c6  mov r14d, eax
0000ce47  85 c0  test eax, eax
0000ce49  0f 85 57 fa ff ff  jne 0x18000c8a6
0000ce4f  40 f6 c5 40  test bpl, 0x40
0000ce53  74 1a  je 0x18000ce6f
0000ce55  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ce5a  b9 2d 00 00 00  mov ecx, 0x2d
0000ce5f  e8 7c 11 00 00  call 0x18000dfe0
0000ce64  41 89 c6  mov r14d, eax
0000ce67  85 c0  test eax, eax
0000ce69  0f 85 37 fa ff ff  jne 0x18000c8a6
0000ce6f  0f ba e5 0b  bt ebp, 0xb
0000ce73  73 1a  jae 0x18000ce8f
0000ce75  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ce7a  b9 31 00 00 00  mov ecx, 0x31
0000ce7f  e8 5c 11 00 00  call 0x18000dfe0
0000ce84  41 89 c6  mov r14d, eax
0000ce87  85 c0  test eax, eax
0000ce89  0f 85 17 fa ff ff  jne 0x18000c8a6
0000ce8f  41 f6 c2 20  test r10b, 0x20
0000ce93  74 1a  je 0x18000ceaf
0000ce95  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ce9a  b9 3f 00 00 00  mov ecx, 0x3f
0000ce9f  e8 3c 11 00 00  call 0x18000dfe0
0000cea4  41 89 c6  mov r14d, eax
0000cea7  85 c0  test eax, eax
0000cea9  0f 85 f7 f9 ff ff  jne 0x18000c8a6
0000ceaf  0f ba e7 17  bt edi, 0x17
0000ceb3  73 1a  jae 0x18000cecf
0000ceb5  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000ceba  b9 3a 00 00 00  mov ecx, 0x3a
0000cebf  e8 1c 11 00 00  call 0x18000dfe0
0000cec4  41 89 c6  mov r14d, eax
0000cec7  85 c0  test eax, eax
0000cec9  0f 85 d7 f9 ff ff  jne 0x18000c8a6
0000cecf  0f ba e7 08  bt edi, 8
0000ced3  0f 83 9d f8 ff ff  jae 0x18000c776
0000ced9  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cede  b9 39 00 00 00  mov ecx, 0x39
0000cee3  e8 f8 10 00 00  call 0x18000dfe0
0000cee8  41 89 c6  mov r14d, eax
0000ceeb  85 c0  test eax, eax
0000ceed  0f 85 b3 f9 ff ff  jne 0x18000c8a6
0000cef3  e9 7e f8 ff ff  jmp 0x18000c776
0000cef8  45 85 c0  test r8d, r8d
0000cefb  7e 0f  jle 0x18000cf0c
0000cefd  0f 28 44 24 30  movaps xmm0, xmmword ptr [rsp + 0x30]
0000cf02  0f 55 44 24 40  andnps xmm0, xmmword ptr [rsp + 0x40]
0000cf07  0f 29 44 24 40  movaps xmmword ptr [rsp + 0x40], xmm0
0000cf0c  48 8b 44 24 48  mov rax, qword ptr [rsp + 0x48]
0000cf11  83 fe 01  cmp esi, 1
0000cf14  75 26  jne 0x18000cf3c
0000cf16  48 89 05 8b 3b 01 00  mov qword ptr [rip + 0x13b8b], rax
0000cf1d  48 8b 4c 24 40  mov rcx, qword ptr [rsp + 0x40]
0000cf22  48 89 0d 77 3b 01 00  mov qword ptr [rip + 0x13b77], rcx
0000cf29  48 89 05 88 3b 01 00  mov qword ptr [rip + 0x13b88], rax
0000cf30  48 89 0d 79 3b 01 00  mov qword ptr [rip + 0x13b79], rcx
0000cf37  e9 67 f9 ff ff  jmp 0x18000c8a3
0000cf3c  48 89 05 75 3b 01 00  mov qword ptr [rip + 0x13b75], rax
0000cf43  48 8b 44 24 40  mov rax, qword ptr [rsp + 0x40]
0000cf48  48 89 05 61 3b 01 00  mov qword ptr [rip + 0x13b61], rax
0000cf4f  e9 4f f9 ff ff  jmp 0x18000c8a3
0000cf54  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cf59  b9 42 00 00 00  mov ecx, 0x42
0000cf5e  e8 7d 10 00 00  call 0x18000dfe0
0000cf63  41 89 c6  mov r14d, eax
0000cf66  85 c0  test eax, eax
0000cf68  0f 85 38 f9 ff ff  jne 0x18000c8a6
0000cf6e  41 0f ba e2 15  bt r10d, 0x15
0000cf73  73 1a  jae 0x18000cf8f
0000cf75  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cf7a  b9 4f 00 00 00  mov ecx, 0x4f
0000cf7f  e8 5c 10 00 00  call 0x18000dfe0
0000cf84  41 89 c6  mov r14d, eax
0000cf87  85 c0  test eax, eax
0000cf89  0f 85 17 f9 ff ff  jne 0x18000c8a6
0000cf8f  41 0f ba e3 08  bt r11d, 8
0000cf94  73 1a  jae 0x18000cfb0
0000cf96  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cf9b  b9 50 00 00 00  mov ecx, 0x50
0000cfa0  e8 3b 10 00 00  call 0x18000dfe0
0000cfa5  41 89 c6  mov r14d, eax
0000cfa8  85 c0  test eax, eax
0000cfaa  0f 85 f6 f8 ff ff  jne 0x18000c8a6
0000cfb0  0f ba e7 19  bt edi, 0x19
0000cfb4  73 1a  jae 0x18000cfd0
0000cfb6  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cfbb  b9 43 00 00 00  mov ecx, 0x43
0000cfc0  e8 1b 10 00 00  call 0x18000dfe0
0000cfc5  41 89 c6  mov r14d, eax
0000cfc8  85 c0  test eax, eax
0000cfca  0f 85 d6 f8 ff ff  jne 0x18000c8a6
0000cfd0  0f ba e7 16  bt edi, 0x16
0000cfd4  0f 83 e8 fb ff ff  jae 0x18000cbc2
0000cfda  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cfdf  b9 44 00 00 00  mov ecx, 0x44
0000cfe4  e8 f7 0f 00 00  call 0x18000dfe0
0000cfe9  41 89 c6  mov r14d, eax
0000cfec  85 c0  test eax, eax
0000cfee  0f 85 b2 f8 ff ff  jne 0x18000c8a6
0000cff4  e9 c9 fb ff ff  jmp 0x18000cbc2
0000cff9  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000cffe  b9 10 00 00 00  mov ecx, 0x10
0000d003  e8 d8 0f 00 00  call 0x18000dfe0
0000d008  41 89 c6  mov r14d, eax
0000d00b  85 c0  test eax, eax
0000d00d  0f 85 93 f8 ff ff  jne 0x18000c8a6
0000d013  0f ba e5 09  bt ebp, 9
0000d017  73 1a  jae 0x18000d033
0000d019  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d01e  b9 2f 00 00 00  mov ecx, 0x2f
0000d023  e8 b8 0f 00 00  call 0x18000dfe0
0000d028  41 89 c6  mov r14d, eax
0000d02b  85 c0  test eax, eax
0000d02d  0f 85 73 f8 ff ff  jne 0x18000c8a6
0000d033  0f ba e5 0a  bt ebp, 0xa
0000d037  73 1a  jae 0x18000d053
0000d039  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d03e  b9 30 00 00 00  mov ecx, 0x30
0000d043  e8 98 0f 00 00  call 0x18000dfe0
0000d048  41 89 c6  mov r14d, eax
0000d04b  85 c0  test eax, eax
0000d04d  0f 85 53 f8 ff ff  jne 0x18000c8a6
0000d053  41 f6 c2 02  test r10b, 2
0000d057  0f 84 93 fb ff ff  je 0x18000cbf0
0000d05d  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d062  b9 52 00 00 00  mov ecx, 0x52
0000d067  e8 74 0f 00 00  call 0x18000dfe0
0000d06c  41 89 c6  mov r14d, eax
0000d06f  85 c0  test eax, eax
0000d071  0f 85 2f f8 ff ff  jne 0x18000c8a6
0000d077  e9 74 fb ff ff  jmp 0x18000cbf0
0000d07c  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d081  b9 18 00 00 00  mov ecx, 0x18
0000d086  e8 55 0f 00 00  call 0x18000dfe0
0000d08b  41 89 c6  mov r14d, eax
0000d08e  85 c0  test eax, eax
0000d090  0f 85 10 f8 ff ff  jne 0x18000c8a6
0000d096  41 f6 c3 10  test r11b, 0x10
0000d09a  74 1a  je 0x18000d0b6
0000d09c  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d0a1  b9 4a 00 00 00  mov ecx, 0x4a
0000d0a6  e8 35 0f 00 00  call 0x18000dfe0
0000d0ab  41 89 c6  mov r14d, eax
0000d0ae  85 c0  test eax, eax
0000d0b0  0f 85 f0 f7 ff ff  jne 0x18000c8a6
0000d0b6  41 0f ba e2 17  bt r10d, 0x17
0000d0bb  73 1a  jae 0x18000d0d7
0000d0bd  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d0c2  b9 4c 00 00 00  mov ecx, 0x4c
0000d0c7  e8 14 0f 00 00  call 0x18000dfe0
0000d0cc  41 89 c6  mov r14d, eax
0000d0cf  85 c0  test eax, eax
0000d0d1  0f 85 cf f7 ff ff  jne 0x18000c8a6
0000d0d7  41 f6 c3 20  test r11b, 0x20
0000d0db  74 1a  je 0x18000d0f7
0000d0dd  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d0e2  b9 4d 00 00 00  mov ecx, 0x4d
0000d0e7  e8 f4 0e 00 00  call 0x18000dfe0
0000d0ec  41 89 c6  mov r14d, eax
0000d0ef  85 c0  test eax, eax
0000d0f1  0f 85 af f7 ff ff  jne 0x18000c8a6
0000d0f7  41 f6 c2 01  test r10b, 1
0000d0fb  74 1a  je 0x18000d117
0000d0fd  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d102  b9 51 00 00 00  mov ecx, 0x51
0000d107  e8 d4 0e 00 00  call 0x18000dfe0
0000d10c  41 89 c6  mov r14d, eax
0000d10f  85 c0  test eax, eax
0000d111  0f 85 8f f7 ff ff  jne 0x18000c8a6
0000d117  41 f6 c2 04  test r10b, 4
0000d11b  74 1a  je 0x18000d137
0000d11d  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d122  b9 53 00 00 00  mov ecx, 0x53
0000d127  e8 b4 0e 00 00  call 0x18000dfe0
0000d12c  41 89 c6  mov r14d, eax
0000d12f  85 c0  test eax, eax
0000d131  0f 85 6f f7 ff ff  jne 0x18000c8a6
0000d137  41 0f ba e3 0a  bt r11d, 0xa
0000d13c  0f 83 d9 fa ff ff  jae 0x18000cc1b
0000d142  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d147  b9 54 00 00 00  mov ecx, 0x54
0000d14c  e8 8f 0e 00 00  call 0x18000dfe0
0000d151  41 89 c6  mov r14d, eax
0000d154  85 c0  test eax, eax
0000d156  0f 85 4a f7 ff ff  jne 0x18000c8a6
0000d15c  e9 ba fa ff ff  jmp 0x18000cc1b
0000d161  48 8d 44 24 40  lea rax, [rsp + 0x40]
0000d166  b9 27 00 00 00  mov ecx, 0x27
0000d16b  e8 70 0e 00 00  call 0x18000dfe0
0000d170  41 89 c6  mov r14d, eax
0000d173  85 c0  test eax, eax
0000d175  0f 85 2b f7 ff ff  jne 0x18000c8a6
0000d17b  e9 0e fc ff ff  jmp 0x18000cd8e
; owner 0xd180 runtime_d180
0000d180  50  push rax
0000d181  31 c0  xor eax, eax
0000d183  e8 68 f0 ff ff  call 0x18000c1f0
0000d188  90  nop
0000d189  48 83 c4 08  add rsp, 8
0000d18d  c3  ret
; owner 0xd190 runtime_d190
0000d190  50  push rax
0000d191  80 3d 28 39 01 00 00  cmp byte ptr [rip + 0x13928], 0
0000d198  75 05  jne 0x18000d19f
0000d19a  e8 21 00 00 00  call 0x18000d1c0
0000d19f  48 63 c1  movsxd rax, ecx
0000d1a2  48 8d 04 40  lea rax, [rax + rax*2]
0000d1a6  48 8d 0d 23 39 01 00  lea rcx, [rip + 0x13923]
0000d1ad  48 8b 04 c1  mov rax, qword ptr [rcx + rax*8]
0000d1b1  59  pop rcx
0000d1b2  c3  ret
; owner 0xd1c0 runtime_d1c0
0000d1c0  52  push rdx
0000d1c1  51  push rcx
0000d1c2  80 3d f7 38 01 00 00  cmp byte ptr [rip + 0x138f7], 0
0000d1c9  0f 85 7e 0d 00 00  jne 0x18000df4d
0000d1cf  b8 c8 00 00 00  mov eax, 0xc8
0000d1d4  48 8d 0d f5 38 01 00  lea rcx, [rip + 0x138f5]
0000d1db  ba ff ff ff ff  mov edx, 0xffffffff
0000d1e0  89 94 08 58 ff ff ff  mov dword ptr [rax + rcx - 0xa8], edx
0000d1e7  89 94 08 70 ff ff ff  mov dword ptr [rax + rcx - 0x90], edx
0000d1ee  89 54 08 88  mov dword ptr [rax + rcx - 0x78], edx
0000d1f2  89 54 08 a0  mov dword ptr [rax + rcx - 0x60], edx
0000d1f6  89 54 08 b8  mov dword ptr [rax + rcx - 0x48], edx
0000d1fa  89 54 08 d0  mov dword ptr [rax + rcx - 0x30], edx
0000d1fe  89 54 08 e8  mov dword ptr [rax + rcx - 0x18], edx
0000d202  89 14 08  mov dword ptr [rax + rcx], edx
0000d205  48 05 c0 00 00 00  add rax, 0xc0
0000d20b  48 3d 08 09 00 00  cmp rax, 0x908
0000d211  75 cd  jne 0x18000d1e0
0000d213  b8 ff ff ff ff  mov eax, 0xffffffff
0000d218  89 05 12 41 01 00  mov dword ptr [rip + 0x14112], eax
0000d21e  89 05 24 41 01 00  mov dword ptr [rip + 0x14124], eax
0000d224  89 05 36 41 01 00  mov dword ptr [rip + 0x14136], eax
0000d22a  48 8d 0d 51 aa 00 00  lea rcx, [rip + 0xaa51]
0000d231  48 89 0d b0 38 01 00  mov qword ptr [rip + 0x138b0], rcx
0000d238  c7 05 ae 38 01 00 00 00 00 00  mov dword ptr [rip + 0x138ae], 0
0000d242  48 8d 0d 46 aa 00 00  lea rcx, [rip + 0xaa46]
0000d249  48 89 0d b0 38 01 00  mov qword ptr [rip + 0x138b0], rcx
0000d250  c7 05 ae 38 01 00 01 00 00 00  mov dword ptr [rip + 0x138ae], 1
0000d25a  48 8d 0d 32 aa 00 00  lea rcx, [rip + 0xaa32]
0000d261  48 89 0d b0 38 01 00  mov qword ptr [rip + 0x138b0], rcx
0000d268  c7 05 ae 38 01 00 02 00 00 00  mov dword ptr [rip + 0x138ae], 2
0000d272  c7 05 bc 38 01 00 03 00 00 00  mov dword ptr [rip + 0x138bc], 3
0000d27c  48 8d 0d 15 aa 00 00  lea rcx, [rip + 0xaa15]
0000d283  48 89 0d b6 38 01 00  mov qword ptr [rip + 0x138b6], rcx
0000d28a  48 8d 0d 0b aa 00 00  lea rcx, [rip + 0xaa0b]
0000d291  48 89 0d 98 38 01 00  mov qword ptr [rip + 0x13898], rcx
0000d298  48 8d 0d 01 aa 00 00  lea rcx, [rip + 0xaa01]
0000d29f  48 89 0d a2 38 01 00  mov qword ptr [rip + 0x138a2], rcx
0000d2a6  c7 05 a0 38 01 00 04 00 00 00  mov dword ptr [rip + 0x138a0], 4
0000d2b0  c7 05 ae 38 01 00 05 00 00 00  mov dword ptr [rip + 0x138ae], 5
0000d2ba  48 8d 0d e6 a9 00 00  lea rcx, [rip + 0xa9e6]
0000d2c1  48 89 0d a8 38 01 00  mov qword ptr [rip + 0x138a8], rcx
0000d2c8  48 8d 0d dc a9 00 00  lea rcx, [rip + 0xa9dc]
0000d2cf  48 89 0d 8a 38 01 00  mov qword ptr [rip + 0x1388a], rcx
0000d2d6  c7 05 a0 38 01 00 06 00 00 00  mov dword ptr [rip + 0x138a0], 6
0000d2e0  48 8d 0d c8 a9 00 00  lea rcx, [rip + 0xa9c8]
0000d2e7  48 89 0d 9a 38 01 00  mov qword ptr [rip + 0x1389a], rcx
0000d2ee  48 8d 0d bf a9 00 00  lea rcx, [rip + 0xa9bf]
0000d2f5  48 89 0d 7c 38 01 00  mov qword ptr [rip + 0x1387c], rcx
0000d2fc  c7 05 92 38 01 00 07 00 00 00  mov dword ptr [rip + 0x13892], 7
0000d306  48 8d 0d ac a9 00 00  lea rcx, [rip + 0xa9ac]
0000d30d  48 89 0d 8c 38 01 00  mov qword ptr [rip + 0x1388c], rcx
0000d314  48 8d 0d a3 a9 00 00  lea rcx, [rip + 0xa9a3]
0000d31b  48 89 0d 6e 38 01 00  mov qword ptr [rip + 0x1386e], rcx
0000d322  c7 05 84 38 01 00 08 00 00 00  mov dword ptr [rip + 0x13884], 8
0000d32c  48 8d 0d 90 a9 00 00  lea rcx, [rip + 0xa990]
0000d333  48 89 0d 7e 38 01 00  mov qword ptr [rip + 0x1387e], rcx
0000d33a  48 8d 0d 88 a9 00 00  lea rcx, [rip + 0xa988]
0000d341  48 89 0d 60 38 01 00  mov qword ptr [rip + 0x13860], rcx
0000d348  c7 05 76 38 01 00 09 00 00 00  mov dword ptr [rip + 0x13876], 9
0000d352  48 8d 0d 76 a9 00 00  lea rcx, [rip + 0xa976]
0000d359  48 89 0d 70 38 01 00  mov qword ptr [rip + 0x13870], rcx
0000d360  48 8d 0d 6f a9 00 00  lea rcx, [rip + 0xa96f]
0000d367  48 89 0d 52 38 01 00  mov qword ptr [rip + 0x13852], rcx
0000d36e  c7 05 68 38 01 00 0a 00 00 00  mov dword ptr [rip + 0x13868], 0xa
0000d378  48 8d 0d 5e a9 00 00  lea rcx, [rip + 0xa95e]
0000d37f  48 89 0d 62 38 01 00  mov qword ptr [rip + 0x13862], rcx
0000d386  48 8d 0d 55 a9 00 00  lea rcx, [rip + 0xa955]
0000d38d  48 89 0d 44 38 01 00  mov qword ptr [rip + 0x13844], rcx
0000d394  c7 05 5a 38 01 00 0b 00 00 00  mov dword ptr [rip + 0x1385a], 0xb
0000d39e  48 8d 0d 44 a9 00 00  lea rcx, [rip + 0xa944]
0000d3a5  48 89 0d 54 38 01 00  mov qword ptr [rip + 0x13854], rcx
0000d3ac  48 8d 0d 3c a9 00 00  lea rcx, [rip + 0xa93c]
0000d3b3  48 89 0d 36 38 01 00  mov qword ptr [rip + 0x13836], rcx
0000d3ba  c7 05 4c 38 01 00 0c 00 00 00  mov dword ptr [rip + 0x1384c], 0xc
0000d3c4  48 8d 0d 2a a9 00 00  lea rcx, [rip + 0xa92a]
0000d3cb  48 89 0d 46 38 01 00  mov qword ptr [rip + 0x13846], rcx
0000d3d2  48 8d 0d 23 a9 00 00  lea rcx, [rip + 0xa923]
0000d3d9  48 89 0d 28 38 01 00  mov qword ptr [rip + 0x13828], rcx
0000d3e0  c7 05 3e 38 01 00 0d 00 00 00  mov dword ptr [rip + 0x1383e], 0xd
0000d3ea  48 8d 0d 12 a9 00 00  lea rcx, [rip + 0xa912]
0000d3f1  48 89 0d 38 38 01 00  mov qword ptr [rip + 0x13838], rcx
0000d3f8  48 8d 0d 0b a9 00 00  lea rcx, [rip + 0xa90b]
0000d3ff  48 89 0d 1a 38 01 00  mov qword ptr [rip + 0x1381a], rcx
0000d406  c7 05 30 38 01 00 0e 00 00 00  mov dword ptr [rip + 0x13830], 0xe
0000d410  48 8d 0d fd a8 00 00  lea rcx, [rip + 0xa8fd]
0000d417  48 89 0d 2a 38 01 00  mov qword ptr [rip + 0x1382a], rcx
0000d41e  48 8d 0d f3 a8 00 00  lea rcx, [rip + 0xa8f3]
0000d425  48 89 0d 0c 38 01 00  mov qword ptr [rip + 0x1380c], rcx
0000d42c  c7 05 22 38 01 00 10 00 00 00  mov dword ptr [rip + 0x13822], 0x10
0000d436  48 8d 0d df a8 00 00  lea rcx, [rip + 0xa8df]
0000d43d  48 89 0d 1c 38 01 00  mov qword ptr [rip + 0x1381c], rcx
0000d444  48 8d 0d d5 a8 00 00  lea rcx, [rip + 0xa8d5]
0000d44b  48 89 0d fe 37 01 00  mov qword ptr [rip + 0x137fe], rcx
0000d452  c7 05 14 38 01 00 0f 00 00 00  mov dword ptr [rip + 0x13814], 0xf
0000d45c  48 8d 0d c1 a8 00 00  lea rcx, [rip + 0xa8c1]
0000d463  48 89 0d 0e 38 01 00  mov qword ptr [rip + 0x1380e], rcx
0000d46a  48 8d 0d b8 a8 00 00  lea rcx, [rip + 0xa8b8]
0000d471  48 89 0d f0 37 01 00  mov qword ptr [rip + 0x137f0], rcx
0000d478  c7 05 06 38 01 00 11 00 00 00  mov dword ptr [rip + 0x13806], 0x11
0000d482  48 8d 0d a5 a8 00 00  lea rcx, [rip + 0xa8a5]
0000d489  48 89 0d 00 38 01 00  mov qword ptr [rip + 0x13800], rcx
0000d490  48 8d 0d 9d a8 00 00  lea rcx, [rip + 0xa89d]
0000d497  48 89 0d e2 37 01 00  mov qword ptr [rip + 0x137e2], rcx
0000d49e  c7 05 f8 37 01 00 12 00 00 00  mov dword ptr [rip + 0x137f8], 0x12
0000d4a8  48 8d 0d 8b a8 00 00  lea rcx, [rip + 0xa88b]
0000d4af  48 89 0d f2 37 01 00  mov qword ptr [rip + 0x137f2], rcx
0000d4b6  48 8d 0d 81 a8 00 00  lea rcx, [rip + 0xa881]
0000d4bd  48 89 0d d4 37 01 00  mov qword ptr [rip + 0x137d4], rcx
0000d4c4  c7 05 ea 37 01 00 13 00 00 00  mov dword ptr [rip + 0x137ea], 0x13
0000d4ce  48 8d 0d 6d a8 00 00  lea rcx, [rip + 0xa86d]
0000d4d5  48 89 0d e4 37 01 00  mov qword ptr [rip + 0x137e4], rcx
0000d4dc  48 8d 0d 63 a8 00 00  lea rcx, [rip + 0xa863]
0000d4e3  48 89 0d c6 37 01 00  mov qword ptr [rip + 0x137c6], rcx
0000d4ea  c7 05 dc 37 01 00 14 00 00 00  mov dword ptr [rip + 0x137dc], 0x14
0000d4f4  48 8d 0d 4f a8 00 00  lea rcx, [rip + 0xa84f]
0000d4fb  48 89 0d d6 37 01 00  mov qword ptr [rip + 0x137d6], rcx
0000d502  48 8d 0d 47 a8 00 00  lea rcx, [rip + 0xa847]
0000d509  48 89 0d b8 37 01 00  mov qword ptr [rip + 0x137b8], rcx
0000d510  c7 05 ce 37 01 00 15 00 00 00  mov dword ptr [rip + 0x137ce], 0x15
0000d51a  48 8d 0d 35 a8 00 00  lea rcx, [rip + 0xa835]
0000d521  48 89 0d c8 37 01 00  mov qword ptr [rip + 0x137c8], rcx
0000d528  48 8d 0d 2b a8 00 00  lea rcx, [rip + 0xa82b]
0000d52f  48 89 0d aa 37 01 00  mov qword ptr [rip + 0x137aa], rcx
0000d536  c7 05 c0 37 01 00 16 00 00 00  mov dword ptr [rip + 0x137c0], 0x16
0000d540  48 8d 0d 17 a8 00 00  lea rcx, [rip + 0xa817]
0000d547  48 89 0d ba 37 01 00  mov qword ptr [rip + 0x137ba], rcx
0000d54e  48 8d 0d 0d a8 00 00  lea rcx, [rip + 0xa80d]
0000d555  48 89 0d 9c 37 01 00  mov qword ptr [rip + 0x1379c], rcx
0000d55c  c7 05 b2 37 01 00 17 00 00 00  mov dword ptr [rip + 0x137b2], 0x17
0000d566  48 8d 0d f9 a7 00 00  lea rcx, [rip + 0xa7f9]
0000d56d  48 89 0d ac 37 01 00  mov qword ptr [rip + 0x137ac], rcx
0000d574  48 8d 0d f0 a7 00 00  lea rcx, [rip + 0xa7f0]
0000d57b  48 89 0d 8e 37 01 00  mov qword ptr [rip + 0x1378e], rcx
0000d582  c7 05 a4 37 01 00 1b 00 00 00  mov dword ptr [rip + 0x137a4], 0x1b
0000d58c  48 8d 0d dd a7 00 00  lea rcx, [rip + 0xa7dd]
0000d593  48 89 0d 9e 37 01 00  mov qword ptr [rip + 0x1379e], rcx
0000d59a  48 8d 0d d7 a7 00 00  lea rcx, [rip + 0xa7d7]
0000d5a1  48 89 0d 80 37 01 00  mov qword ptr [rip + 0x13780], rcx
0000d5a8  c7 05 96 37 01 00 18 00 00 00  mov dword ptr [rip + 0x13796], 0x18
0000d5b2  48 8d 0d c7 a7 00 00  lea rcx, [rip + 0xa7c7]
0000d5b9  48 89 0d 90 37 01 00  mov qword ptr [rip + 0x13790], rcx
0000d5c0  48 8d 0d c2 a7 00 00  lea rcx, [rip + 0xa7c2]
0000d5c7  48 89 0d 72 37 01 00  mov qword ptr [rip + 0x13772], rcx
0000d5ce  c7 05 88 37 01 00 19 00 00 00  mov dword ptr [rip + 0x13788], 0x19
0000d5d8  48 8d 0d b3 a7 00 00  lea rcx, [rip + 0xa7b3]
0000d5df  48 89 0d 82 37 01 00  mov qword ptr [rip + 0x13782], rcx
0000d5e6  48 8d 0d ad a7 00 00  lea rcx, [rip + 0xa7ad]
0000d5ed  48 89 0d 64 37 01 00  mov qword ptr [rip + 0x13764], rcx
0000d5f4  48 8d 0d a7 a7 00 00  lea rcx, [rip + 0xa7a7]
0000d5fb  48 89 0d 6e 37 01 00  mov qword ptr [rip + 0x1376e], rcx
0000d602  c7 05 6c 37 01 00 1a 00 00 00  mov dword ptr [rip + 0x1376c], 0x1a
0000d60c  c7 05 7a 37 01 00 1c 00 00 00  mov dword ptr [rip + 0x1377a], 0x1c
0000d616  48 8d 0d 8b a7 00 00  lea rcx, [rip + 0xa78b]
0000d61d  48 89 0d 74 37 01 00  mov qword ptr [rip + 0x13774], rcx
0000d624  48 8d 0d 81 a7 00 00  lea rcx, [rip + 0xa781]
0000d62b  48 89 0d 56 37 01 00  mov qword ptr [rip + 0x13756], rcx
0000d632  c7 05 6c 37 01 00 1d 00 00 00  mov dword ptr [rip + 0x1376c], 0x1d
0000d63c  48 8d 0d 6d a7 00 00  lea rcx, [rip + 0xa76d]
0000d643  48 89 0d 66 37 01 00  mov qword ptr [rip + 0x13766], rcx
0000d64a  48 8d 0d 66 a7 00 00  lea rcx, [rip + 0xa766]
0000d651  48 89 0d 48 37 01 00  mov qword ptr [rip + 0x13748], rcx
0000d658  c7 05 5e 37 01 00 1e 00 00 00  mov dword ptr [rip + 0x1375e], 0x1e
0000d662  48 8d 0d 55 a7 00 00  lea rcx, [rip + 0xa755]
0000d669  48 89 0d 58 37 01 00  mov qword ptr [rip + 0x13758], rcx
0000d670  48 8d 0d 52 a7 00 00  lea rcx, [rip + 0xa752]
0000d677  48 89 0d 3a 37 01 00  mov qword ptr [rip + 0x1373a], rcx
0000d67e  89 05 54 37 01 00  mov dword ptr [rip + 0x13754], eax
0000d684  c7 05 62 37 01 00 20 00 00 00  mov dword ptr [rip + 0x13762], 0x20
0000d68e  48 8d 05 41 a7 00 00  lea rax, [rip + 0xa741]
0000d695  48 89 05 5c 37 01 00  mov qword ptr [rip + 0x1375c], rax
0000d69c  48 8d 05 3c a7 00 00  lea rax, [rip + 0xa73c]
0000d6a3  48 89 05 3e 37 01 00  mov qword ptr [rip + 0x1373e], rax
0000d6aa  c7 05 54 37 01 00 21 00 00 00  mov dword ptr [rip + 0x13754], 0x21
0000d6b4  48 8d 05 2d a7 00 00  lea rax, [rip + 0xa72d]
0000d6bb  48 89 05 4e 37 01 00  mov qword ptr [rip + 0x1374e], rax
0000d6c2  48 8d 05 28 a7 00 00  lea rax, [rip + 0xa728]
0000d6c9  48 89 05 30 37 01 00  mov qword ptr [rip + 0x13730], rax
0000d6d0  c7 05 46 37 01 00 22 00 00 00  mov dword ptr [rip + 0x13746], 0x22
0000d6da  48 8d 05 19 a7 00 00  lea rax, [rip + 0xa719]
0000d6e1  48 89 05 40 37 01 00  mov qword ptr [rip + 0x13740], rax
0000d6e8  48 8d 05 14 a7 00 00  lea rax, [rip + 0xa714]
0000d6ef  48 89 05 22 37 01 00  mov qword ptr [rip + 0x13722], rax
0000d6f6  c7 05 38 37 01 00 23 00 00 00  mov dword ptr [rip + 0x13738], 0x23
0000d700  48 8d 05 05 a7 00 00  lea rax, [rip + 0xa705]
0000d707  48 89 05 32 37 01 00  mov qword ptr [rip + 0x13732], rax
0000d70e  48 8d 05 fb a6 00 00  lea rax, [rip + 0xa6fb]
0000d715  48 89 05 14 37 01 00  mov qword ptr [rip + 0x13714], rax
0000d71c  c7 05 2a 37 01 00 24 00 00 00  mov dword ptr [rip + 0x1372a], 0x24
0000d726  48 8d 05 e7 a6 00 00  lea rax, [rip + 0xa6e7]
0000d72d  48 89 05 24 37 01 00  mov qword ptr [rip + 0x13724], rax
0000d734  48 8d 05 dd a6 00 00  lea rax, [rip + 0xa6dd]
0000d73b  48 89 05 06 37 01 00  mov qword ptr [rip + 0x13706], rax
0000d742  c7 05 1c 37 01 00 25 00 00 00  mov dword ptr [rip + 0x1371c], 0x25
0000d74c  48 8d 05 c9 a6 00 00  lea rax, [rip + 0xa6c9]
0000d753  48 89 05 16 37 01 00  mov qword ptr [rip + 0x13716], rax
0000d75a  48 8d 05 c4 a6 00 00  lea rax, [rip + 0xa6c4]
0000d761  48 89 05 f8 36 01 00  mov qword ptr [rip + 0x136f8], rax
0000d768  c7 05 0e 37 01 00 26 00 00 00  mov dword ptr [rip + 0x1370e], 0x26
0000d772  48 8d 05 b5 a6 00 00  lea rax, [rip + 0xa6b5]
0000d779  48 89 05 08 37 01 00  mov qword ptr [rip + 0x13708], rax
0000d780  48 8d 05 b0 a6 00 00  lea rax, [rip + 0xa6b0]
0000d787  48 89 05 ea 36 01 00  mov qword ptr [rip + 0x136ea], rax
0000d78e  c7 05 00 37 01 00 27 00 00 00  mov dword ptr [rip + 0x13700], 0x27
0000d798  48 8d 05 a1 a6 00 00  lea rax, [rip + 0xa6a1]
0000d79f  48 89 05 fa 36 01 00  mov qword ptr [rip + 0x136fa], rax
0000d7a6  48 8d 05 9e a6 00 00  lea rax, [rip + 0xa69e]
0000d7ad  48 89 05 dc 36 01 00  mov qword ptr [rip + 0x136dc], rax
0000d7b4  c7 05 f2 36 01 00 28 00 00 00  mov dword ptr [rip + 0x136f2], 0x28
0000d7be  48 8d 05 91 a6 00 00  lea rax, [rip + 0xa691]
0000d7c5  48 89 05 ec 36 01 00  mov qword ptr [rip + 0x136ec], rax
0000d7cc  48 8d 05 90 a6 00 00  lea rax, [rip + 0xa690]
0000d7d3  48 89 05 ce 36 01 00  mov qword ptr [rip + 0x136ce], rax
0000d7da  c7 05 e4 36 01 00 29 00 00 00  mov dword ptr [rip + 0x136e4], 0x29
0000d7e4  48 8d 05 86 a6 00 00  lea rax, [rip + 0xa686]
0000d7eb  48 89 05 de 36 01 00  mov qword ptr [rip + 0x136de], rax
0000d7f2  48 8d 05 85 a6 00 00  lea rax, [rip + 0xa685]
0000d7f9  48 89 05 c0 36 01 00  mov qword ptr [rip + 0x136c0], rax
0000d800  c7 05 d6 36 01 00 2a 00 00 00  mov dword ptr [rip + 0x136d6], 0x2a
0000d80a  48 8d 05 7b a6 00 00  lea rax, [rip + 0xa67b]
0000d811  48 89 05 d0 36 01 00  mov qword ptr [rip + 0x136d0], rax
0000d818  48 8d 05 7d a6 00 00  lea rax, [rip + 0xa67d]
0000d81f  48 89 05 b2 36 01 00  mov qword ptr [rip + 0x136b2], rax
0000d826  c7 05 c8 36 01 00 2b 00 00 00  mov dword ptr [rip + 0x136c8], 0x2b
0000d830  48 8d 05 76 a6 00 00  lea rax, [rip + 0xa676]
0000d837  48 89 05 c2 36 01 00  mov qword ptr [rip + 0x136c2], rax
0000d83e  48 8d 05 75 a6 00 00  lea rax, [rip + 0xa675]
0000d845  48 89 05 a4 36 01 00  mov qword ptr [rip + 0x136a4], rax
0000d84c  c7 05 ba 36 01 00 2c 00 00 00  mov dword ptr [rip + 0x136ba], 0x2c
0000d856  48 8d 05 6b a6 00 00  lea rax, [rip + 0xa66b]
0000d85d  48 89 05 b4 36 01 00  mov qword ptr [rip + 0x136b4], rax
0000d864  48 8d 05 69 a6 00 00  lea rax, [rip + 0xa669]
0000d86b  48 89 05 96 36 01 00  mov qword ptr [rip + 0x13696], rax
0000d872  c7 05 ac 36 01 00 2d 00 00 00  mov dword ptr [rip + 0x136ac], 0x2d
0000d87c  48 8d 05 5e a6 00 00  lea rax, [rip + 0xa65e]
0000d883  48 89 05 a6 36 01 00  mov qword ptr [rip + 0x136a6], rax
0000d88a  48 8d 05 55 a6 00 00  lea rax, [rip + 0xa655]
0000d891  48 89 05 88 36 01 00  mov qword ptr [rip + 0x13688], rax
0000d898  c7 05 9e 36 01 00 2e 00 00 00  mov dword ptr [rip + 0x1369e], 0x2e
0000d8a2  48 8d 05 42 a6 00 00  lea rax, [rip + 0xa642]
0000d8a9  48 89 05 98 36 01 00  mov qword ptr [rip + 0x13698], rax
0000d8b0  48 8d 05 39 a6 00 00  lea rax, [rip + 0xa639]
0000d8b7  48 89 05 7a 36 01 00  mov qword ptr [rip + 0x1367a], rax
0000d8be  c7 05 90 36 01 00 2f 00 00 00  mov dword ptr [rip + 0x13690], 0x2f
0000d8c8  48 8d 05 26 a6 00 00  lea rax, [rip + 0xa626]
0000d8cf  48 89 05 8a 36 01 00  mov qword ptr [rip + 0x1368a], rax
0000d8d6  48 8d 05 23 a6 00 00  lea rax, [rip + 0xa623]
0000d8dd  48 89 05 6c 36 01 00  mov qword ptr [rip + 0x1366c], rax
0000d8e4  c7 05 82 36 01 00 30 00 00 00  mov dword ptr [rip + 0x13682], 0x30
0000d8ee  48 8d 05 16 a6 00 00  lea rax, [rip + 0xa616]
0000d8f5  48 89 05 7c 36 01 00  mov qword ptr [rip + 0x1367c], rax
0000d8fc  48 8d 05 13 a6 00 00  lea rax, [rip + 0xa613]
0000d903  48 89 05 5e 36 01 00  mov qword ptr [rip + 0x1365e], rax
0000d90a  c7 05 74 36 01 00 31 00 00 00  mov dword ptr [rip + 0x13674], 0x31
0000d914  48 8d 05 07 a6 00 00  lea rax, [rip + 0xa607]
0000d91b  48 89 05 6e 36 01 00  mov qword ptr [rip + 0x1366e], rax
0000d922  48 8d 05 fe a5 00 00  lea rax, [rip + 0xa5fe]
0000d929  48 89 05 50 36 01 00  mov qword ptr [rip + 0x13650], rax
0000d930  c7 05 66 36 01 00 32 00 00 00  mov dword ptr [rip + 0x13666], 0x32
0000d93a  48 8d 05 eb a5 00 00  lea rax, [rip + 0xa5eb]
0000d941  48 89 05 60 36 01 00  mov qword ptr [rip + 0x13660], rax
0000d948  48 8d 05 e3 a5 00 00  lea rax, [rip + 0xa5e3]
0000d94f  48 89 05 42 36 01 00  mov qword ptr [rip + 0x13642], rax
0000d956  c7 05 58 36 01 00 33 00 00 00  mov dword ptr [rip + 0x13658], 0x33
0000d960  48 8d 05 d1 a5 00 00  lea rax, [rip + 0xa5d1]
0000d967  48 89 05 52 36 01 00  mov qword ptr [rip + 0x13652], rax
0000d96e  48 8d 05 c7 a5 00 00  lea rax, [rip + 0xa5c7]
0000d975  48 89 05 34 36 01 00  mov qword ptr [rip + 0x13634], rax
0000d97c  c7 05 4a 36 01 00 34 00 00 00  mov dword ptr [rip + 0x1364a], 0x34
0000d986  48 8d 05 b3 a5 00 00  lea rax, [rip + 0xa5b3]
0000d98d  48 89 05 44 36 01 00  mov qword ptr [rip + 0x13644], rax
0000d994  48 8d 05 ab a5 00 00  lea rax, [rip + 0xa5ab]
0000d99b  48 89 05 26 36 01 00  mov qword ptr [rip + 0x13626], rax
0000d9a2  c7 05 3c 36 01 00 35 00 00 00  mov dword ptr [rip + 0x1363c], 0x35
0000d9ac  48 8d 05 99 a5 00 00  lea rax, [rip + 0xa599]
0000d9b3  48 89 05 36 36 01 00  mov qword ptr [rip + 0x13636], rax
0000d9ba  48 8d 05 8f a5 00 00  lea rax, [rip + 0xa58f]
0000d9c1  48 89 05 18 36 01 00  mov qword ptr [rip + 0x13618], rax
0000d9c8  c7 05 2e 36 01 00 36 00 00 00  mov dword ptr [rip + 0x1362e], 0x36
0000d9d2  48 8d 05 7b a5 00 00  lea rax, [rip + 0xa57b]
0000d9d9  48 89 05 28 36 01 00  mov qword ptr [rip + 0x13628], rax
0000d9e0  48 8d 05 76 a5 00 00  lea rax, [rip + 0xa576]
0000d9e7  48 89 05 0a 36 01 00  mov qword ptr [rip + 0x1360a], rax
0000d9ee  c7 05 20 36 01 00 37 00 00 00  mov dword ptr [rip + 0x13620], 0x37
0000d9f8  48 8d 05 67 a5 00 00  lea rax, [rip + 0xa567]
0000d9ff  48 89 05 1a 36 01 00  mov qword ptr [rip + 0x1361a], rax
0000da06  48 8d 05 61 a5 00 00  lea rax, [rip + 0xa561]
0000da0d  48 89 05 fc 35 01 00  mov qword ptr [rip + 0x135fc], rax
0000da14  c7 05 12 36 01 00 38 00 00 00  mov dword ptr [rip + 0x13612], 0x38
0000da1e  48 8d 05 51 a5 00 00  lea rax, [rip + 0xa551]
0000da25  48 89 05 0c 36 01 00  mov qword ptr [rip + 0x1360c], rax
0000da2c  48 8d 05 56 a5 00 00  lea rax, [rip + 0xa556]
0000da33  48 89 05 ee 35 01 00  mov qword ptr [rip + 0x135ee], rax
0000da3a  c7 05 04 36 01 00 3c 00 00 00  mov dword ptr [rip + 0x13604], 0x3c
0000da44  48 8d 05 52 a5 00 00  lea rax, [rip + 0xa552]
0000da4b  48 89 05 fe 35 01 00  mov qword ptr [rip + 0x135fe], rax
0000da52  48 8d 05 4f a5 00 00  lea rax, [rip + 0xa54f]
0000da59  48 89 05 e0 35 01 00  mov qword ptr [rip + 0x135e0], rax
0000da60  c7 05 f6 35 01 00 40 00 00 00  mov dword ptr [rip + 0x135f6], 0x40
0000da6a  48 8d 05 43 a5 00 00  lea rax, [rip + 0xa543]
0000da71  48 89 05 f0 35 01 00  mov qword ptr [rip + 0x135f0], rax
0000da78  48 8d 05 3e a5 00 00  lea rax, [rip + 0xa53e]
0000da7f  48 89 05 d2 35 01 00  mov qword ptr [rip + 0x135d2], rax
0000da86  c7 05 e8 35 01 00 41 00 00 00  mov dword ptr [rip + 0x135e8], 0x41
0000da90  48 8d 05 2f a5 00 00  lea rax, [rip + 0xa52f]
0000da97  48 89 05 e2 35 01 00  mov qword ptr [rip + 0x135e2], rax
0000da9e  48 8d 05 29 a5 00 00  lea rax, [rip + 0xa529]
0000daa5  48 89 05 c4 35 01 00  mov qword ptr [rip + 0x135c4], rax
0000daac  c7 05 da 35 01 00 42 00 00 00  mov dword ptr [rip + 0x135da], 0x42
0000dab6  48 8d 05 19 a5 00 00  lea rax, [rip + 0xa519]
0000dabd  48 89 05 d4 35 01 00  mov qword ptr [rip + 0x135d4], rax
0000dac4  48 8d 05 15 a5 00 00  lea rax, [rip + 0xa515]
0000dacb  48 89 05 b6 35 01 00  mov qword ptr [rip + 0x135b6], rax
0000dad2  c7 05 cc 35 01 00 43 00 00 00  mov dword ptr [rip + 0x135cc], 0x43
0000dadc  48 8d 05 07 a5 00 00  lea rax, [rip + 0xa507]
0000dae3  48 89 05 c6 35 01 00  mov qword ptr [rip + 0x135c6], rax
0000daea  48 8d 05 01 a5 00 00  lea rax, [rip + 0xa501]
0000daf1  48 89 05 a8 35 01 00  mov qword ptr [rip + 0x135a8], rax
0000daf8  c7 05 be 35 01 00 44 00 00 00  mov dword ptr [rip + 0x135be], 0x44
0000db02  48 8d 05 f1 a4 00 00  lea rax, [rip + 0xa4f1]
0000db09  48 89 05 b8 35 01 00  mov qword ptr [rip + 0x135b8], rax
0000db10  48 8d 05 ee a4 00 00  lea rax, [rip + 0xa4ee]
0000db17  48 89 05 9a 35 01 00  mov qword ptr [rip + 0x1359a], rax
0000db1e  c7 05 b0 35 01 00 45 00 00 00  mov dword ptr [rip + 0x135b0], 0x45
0000db28  48 8d 05 e2 a4 00 00  lea rax, [rip + 0xa4e2]
0000db2f  48 89 05 aa 35 01 00  mov qword ptr [rip + 0x135aa], rax
0000db36  48 8d 05 db a4 00 00  lea rax, [rip + 0xa4db]
0000db3d  48 89 05 8c 35 01 00  mov qword ptr [rip + 0x1358c], rax
0000db44  c7 05 a2 35 01 00 46 00 00 00  mov dword ptr [rip + 0x135a2], 0x46
0000db4e  48 8d 05 ca a4 00 00  lea rax, [rip + 0xa4ca]
0000db55  48 89 05 9c 35 01 00  mov qword ptr [rip + 0x1359c], rax
0000db5c  48 8d 05 c4 a4 00 00  lea rax, [rip + 0xa4c4]
0000db63  48 89 05 7e 35 01 00  mov qword ptr [rip + 0x1357e], rax
0000db6a  c7 05 94 35 01 00 47 00 00 00  mov dword ptr [rip + 0x13594], 0x47
0000db74  48 8d 05 b5 a4 00 00  lea rax, [rip + 0xa4b5]
0000db7b  48 89 05 8e 35 01 00  mov qword ptr [rip + 0x1358e], rax
0000db82  48 8d 05 b0 a4 00 00  lea rax, [rip + 0xa4b0]
0000db89  48 89 05 70 35 01 00  mov qword ptr [rip + 0x13570], rax
0000db90  c7 05 86 35 01 00 48 00 00 00  mov dword ptr [rip + 0x13586], 0x48
0000db9a  48 8d 05 a1 a4 00 00  lea rax, [rip + 0xa4a1]
0000dba1  48 89 05 80 35 01 00  mov qword ptr [rip + 0x13580], rax
0000dba8  48 8d 05 9c a4 00 00  lea rax, [rip + 0xa49c]
0000dbaf  48 89 05 62 35 01 00  mov qword ptr [rip + 0x13562], rax
0000dbb6  c7 05 78 35 01 00 49 00 00 00  mov dword ptr [rip + 0x13578], 0x49
0000dbc0  48 8d 05 8d a4 00 00  lea rax, [rip + 0xa48d]
0000dbc7  48 89 05 72 35 01 00  mov qword ptr [rip + 0x13572], rax
0000dbce  48 8d 05 88 a4 00 00  lea rax, [rip + 0xa488]
0000dbd5  48 89 05 54 35 01 00  mov qword ptr [rip + 0x13554], rax
0000dbdc  c7 05 6a 35 01 00 4a 00 00 00  mov dword ptr [rip + 0x1356a], 0x4a
0000dbe6  48 8d 05 79 a4 00 00  lea rax, [rip + 0xa479]
0000dbed  48 89 05 64 35 01 00  mov qword ptr [rip + 0x13564], rax
0000dbf4  48 8d 05 6e a4 00 00  lea rax, [rip + 0xa46e]
0000dbfb  48 89 05 46 35 01 00  mov qword ptr [rip + 0x13546], rax
0000dc02  c7 05 5c 35 01 00 4b 00 00 00  mov dword ptr [rip + 0x1355c], 0x4b
0000dc0c  48 8d 05 59 a4 00 00  lea rax, [rip + 0xa459]
0000dc13  48 89 05 56 35 01 00  mov qword ptr [rip + 0x13556], rax
0000dc1a  48 8d 05 53 a4 00 00  lea rax, [rip + 0xa453]
0000dc21  48 89 05 38 35 01 00  mov qword ptr [rip + 0x13538], rax
0000dc28  c7 05 4e 35 01 00 4c 00 00 00  mov dword ptr [rip + 0x1354e], 0x4c
0000dc32  48 8d 05 43 a4 00 00  lea rax, [rip + 0xa443]
0000dc39  48 89 05 48 35 01 00  mov qword ptr [rip + 0x13548], rax
0000dc40  48 8d 05 3c a4 00 00  lea rax, [rip + 0xa43c]
0000dc47  48 89 05 2a 35 01 00  mov qword ptr [rip + 0x1352a], rax
0000dc4e  c7 05 40 35 01 00 4d 00 00 00  mov dword ptr [rip + 0x13540], 0x4d
0000dc58  48 8d 05 2b a4 00 00  lea rax, [rip + 0xa42b]
0000dc5f  48 89 05 3a 35 01 00  mov qword ptr [rip + 0x1353a], rax
0000dc66  48 8d 05 23 a4 00 00  lea rax, [rip + 0xa423]
0000dc6d  48 89 05 1c 35 01 00  mov qword ptr [rip + 0x1351c], rax
0000dc74  c7 05 32 35 01 00 4e 00 00 00  mov dword ptr [rip + 0x13532], 0x4e
0000dc7e  48 8d 05 11 a4 00 00  lea rax, [rip + 0xa411]
0000dc85  48 89 05 2c 35 01 00  mov qword ptr [rip + 0x1352c], rax
0000dc8c  48 8d 05 0d a4 00 00  lea rax, [rip + 0xa40d]
0000dc93  48 89 05 0e 35 01 00  mov qword ptr [rip + 0x1350e], rax
0000dc9a  c7 05 24 35 01 00 4f 00 00 00  mov dword ptr [rip + 0x13524], 0x4f
0000dca4  48 8d 05 ff a3 00 00  lea rax, [rip + 0xa3ff]
0000dcab  48 89 05 1e 35 01 00  mov qword ptr [rip + 0x1351e], rax
0000dcb2  48 8d 05 fd a3 00 00  lea rax, [rip + 0xa3fd]
0000dcb9  48 89 05 00 35 01 00  mov qword ptr [rip + 0x13500], rax
0000dcc0  c7 05 16 35 01 00 50 00 00 00  mov dword ptr [rip + 0x13516], 0x50
0000dcca  48 8d 05 f3 a3 00 00  lea rax, [rip + 0xa3f3]
0000dcd1  48 89 05 10 35 01 00  mov qword ptr [rip + 0x13510], rax
0000dcd8  48 8d 05 ef a3 00 00  lea rax, [rip + 0xa3ef]
0000dcdf  48 89 05 f2 34 01 00  mov qword ptr [rip + 0x134f2], rax
0000dce6  c7 05 08 35 01 00 51 00 00 00  mov dword ptr [rip + 0x13508], 0x51
0000dcf0  48 8d 05 e1 a3 00 00  lea rax, [rip + 0xa3e1]
0000dcf7  48 89 05 02 35 01 00  mov qword ptr [rip + 0x13502], rax
0000dcfe  48 8d 05 db a3 00 00  lea rax, [rip + 0xa3db]
0000dd05  48 89 05 e4 34 01 00  mov qword ptr [rip + 0x134e4], rax
0000dd0c  c7 05 fa 34 01 00 52 00 00 00  mov dword ptr [rip + 0x134fa], 0x52
0000dd16  48 8d 05 cc a3 00 00  lea rax, [rip + 0xa3cc]
0000dd1d  48 89 05 f4 34 01 00  mov qword ptr [rip + 0x134f4], rax
0000dd24  48 8d 05 cb a3 00 00  lea rax, [rip + 0xa3cb]
0000dd2b  48 89 05 d6 34 01 00  mov qword ptr [rip + 0x134d6], rax
0000dd32  c7 05 ec 34 01 00 53 00 00 00  mov dword ptr [rip + 0x134ec], 0x53
0000dd3c  48 8d 05 c2 a3 00 00  lea rax, [rip + 0xa3c2]
0000dd43  48 89 05 e6 34 01 00  mov qword ptr [rip + 0x134e6], rax
0000dd4a  48 8d 05 bb a3 00 00  lea rax, [rip + 0xa3bb]
0000dd51  48 89 05 c8 34 01 00  mov qword ptr [rip + 0x134c8], rax
0000dd58  c7 05 de 34 01 00 54 00 00 00  mov dword ptr [rip + 0x134de], 0x54
0000dd62  48 8d 05 ab a3 00 00  lea rax, [rip + 0xa3ab]
0000dd69  48 89 05 d8 34 01 00  mov qword ptr [rip + 0x134d8], rax
0000dd70  48 8d 05 a6 a3 00 00  lea rax, [rip + 0xa3a6]
0000dd77  48 89 05 ba 34 01 00  mov qword ptr [rip + 0x134ba], rax
0000dd7e  c7 05 d0 34 01 00 55 00 00 00  mov dword ptr [rip + 0x134d0], 0x55
0000dd88  48 8d 05 97 a3 00 00  lea rax, [rip + 0xa397]
0000dd8f  48 89 05 ca 34 01 00  mov qword ptr [rip + 0x134ca], rax
0000dd96  48 8d 05 95 a3 00 00  lea rax, [rip + 0xa395]
0000dd9d  48 89 05 ac 34 01 00  mov qword ptr [rip + 0x134ac], rax
0000dda4  c7 05 c2 34 01 00 56 00 00 00  mov dword ptr [rip + 0x134c2], 0x56
0000ddae  48 8d 05 89 a3 00 00  lea rax, [rip + 0xa389]
0000ddb5  48 89 05 bc 34 01 00  mov qword ptr [rip + 0x134bc], rax
0000ddbc  48 8d 05 82 a3 00 00  lea rax, [rip + 0xa382]
0000ddc3  48 89 05 9e 34 01 00  mov qword ptr [rip + 0x1349e], rax
0000ddca  c7 05 b4 34 01 00 57 00 00 00  mov dword ptr [rip + 0x134b4], 0x57
0000ddd4  48 8d 05 71 a3 00 00  lea rax, [rip + 0xa371]
0000dddb  48 89 05 ae 34 01 00  mov qword ptr [rip + 0x134ae], rax
0000dde2  48 8d 05 67 a3 00 00  lea rax, [rip + 0xa367]
0000dde9  48 89 05 90 34 01 00  mov qword ptr [rip + 0x13490], rax
0000ddf0  c7 05 a6 34 01 00 58 00 00 00  mov dword ptr [rip + 0x134a6], 0x58
0000ddfa  48 8d 05 53 a3 00 00  lea rax, [rip + 0xa353]
0000de01  48 89 05 a0 34 01 00  mov qword ptr [rip + 0x134a0], rax
0000de08  48 8d 05 49 a3 00 00  lea rax, [rip + 0xa349]
0000de0f  48 89 05 82 34 01 00  mov qword ptr [rip + 0x13482], rax
0000de16  c7 05 98 34 01 00 59 00 00 00  mov dword ptr [rip + 0x13498], 0x59
0000de20  48 8d 05 35 a3 00 00  lea rax, [rip + 0xa335]
0000de27  48 89 05 92 34 01 00  mov qword ptr [rip + 0x13492], rax
0000de2e  48 8d 05 34 a3 00 00  lea rax, [rip + 0xa334]
0000de35  48 89 05 74 34 01 00  mov qword ptr [rip + 0x13474], rax
0000de3c  c7 05 8a 34 01 00 5a 00 00 00  mov dword ptr [rip + 0x1348a], 0x5a
0000de46  48 8d 05 2b a3 00 00  lea rax, [rip + 0xa32b]
0000de4d  48 89 05 84 34 01 00  mov qword ptr [rip + 0x13484], rax
0000de54  48 8d 05 25 a3 00 00  lea rax, [rip + 0xa325]
0000de5b  48 89 05 66 34 01 00  mov qword ptr [rip + 0x13466], rax
0000de62  c7 05 7c 34 01 00 5b 00 00 00  mov dword ptr [rip + 0x1347c], 0x5b
0000de6c  48 8d 05 16 a3 00 00  lea rax, [rip + 0xa316]
0000de73  48 89 05 76 34 01 00  mov qword ptr [rip + 0x13476], rax
0000de7a  48 8d 05 14 a3 00 00  lea rax, [rip + 0xa314]
0000de81  48 89 05 58 34 01 00  mov qword ptr [rip + 0x13458], rax
0000de88  c7 05 6e 34 01 00 5c 00 00 00  mov dword ptr [rip + 0x1346e], 0x5c
0000de92  48 8d 05 05 a3 00 00  lea rax, [rip + 0xa305]
0000de99  48 89 05 68 34 01 00  mov qword ptr [rip + 0x13468], rax
0000dea0  48 8d 05 03 a3 00 00  lea rax, [rip + 0xa303]
0000dea7  48 89 05 4a 34 01 00  mov qword ptr [rip + 0x1344a], rax
0000deae  c7 05 60 34 01 00 5d 00 00 00  mov dword ptr [rip + 0x13460], 0x5d
0000deb8  48 8d 05 f8 a2 00 00  lea rax, [rip + 0xa2f8]
0000debf  48 89 05 5a 34 01 00  mov qword ptr [rip + 0x1345a], rax
0000dec6  48 8d 05 ef a2 00 00  lea rax, [rip + 0xa2ef]
0000decd  48 89 05 3c 34 01 00  mov qword ptr [rip + 0x1343c], rax
0000ded4  c7 05 52 34 01 00 5e 00 00 00  mov dword ptr [rip + 0x13452], 0x5e
0000dede  48 8d 05 dc a2 00 00  lea rax, [rip + 0xa2dc]
0000dee5  48 89 05 4c 34 01 00  mov qword ptr [rip + 0x1344c], rax
0000deec  48 8d 05 d6 a2 00 00  lea rax, [rip + 0xa2d6]
0000def3  48 89 05 2e 34 01 00  mov qword ptr [rip + 0x1342e], rax
0000defa  c7 05 44 34 01 00 5f 00 00 00  mov dword ptr [rip + 0x13444], 0x5f
0000df04  48 8d 05 c6 a2 00 00  lea rax, [rip + 0xa2c6]
0000df0b  48 89 05 3e 34 01 00  mov qword ptr [rip + 0x1343e], rax
0000df12  48 8d 05 c0 a2 00 00  lea rax, [rip + 0xa2c0]
0000df19  48 89 05 20 34 01 00  mov qword ptr [rip + 0x13420], rax
0000df20  c7 05 36 34 01 00 60 00 00 00  mov dword ptr [rip + 0x13436], 0x60
0000df2a  48 8d 05 b0 a2 00 00  lea rax, [rip + 0xa2b0]
0000df31  48 89 05 30 34 01 00  mov qword ptr [rip + 0x13430], rax
0000df38  48 8d 05 a9 a2 00 00  lea rax, [rip + 0xa2a9]
0000df3f  48 89 05 12 34 01 00  mov qword ptr [rip + 0x13412], rax
0000df46  c6 05 73 2b 01 00 01  mov byte ptr [rip + 0x12b73], 1
0000df4d  59  pop rcx
0000df4e  5a  pop rdx
0000df4f  c3  ret
; owner 0xdf50 runtime_df50
0000df50  51  push rcx
0000df51  89 c1  mov ecx, eax
0000df53  80 3d 66 2b 01 00 00  cmp byte ptr [rip + 0x12b66], 0
0000df5a  75 05  jne 0x18000df61
0000df5c  e8 5f f2 ff ff  call 0x18000d1c0
0000df61  48 63 c1  movsxd rax, ecx
0000df64  48 8d 04 40  lea rax, [rax + rax*2]
0000df68  48 8d 0d 61 2b 01 00  lea rcx, [rip + 0x12b61]
0000df6f  8b 4c c1 08  mov ecx, dword ptr [rcx + rax*8 + 8]
0000df73  8d 41 80  lea eax, [rcx - 0x80]
0000df76  3d 7f ff ff ff  cmp eax, 0xffffff7f
0000df7b  b8 fd ff ff ff  mov eax, 0xfffffffd
0000df80  0f 43 c1  cmovae eax, ecx
0000df83  59  pop rcx
0000df84  c3  ret
; owner 0xdf90 runtime_df90
0000df90  50  push rax
0000df91  80 3d 28 2b 01 00 00  cmp byte ptr [rip + 0x12b28], 0
0000df98  75 05  jne 0x18000df9f
0000df9a  e8 21 f2 ff ff  call 0x18000d1c0
0000df9f  48 63 c2  movsxd rax, edx
0000dfa2  48 8d 04 40  lea rax, [rax + rax*2]
0000dfa6  48 8d 15 23 2b 01 00  lea rdx, [rip + 0x12b23]
0000dfad  8b 54 c2 08  mov edx, dword ptr [rdx + rax*8 + 8]
0000dfb1  8d 42 80  lea eax, [rdx - 0x80]
0000dfb4  3d 7f ff ff ff  cmp eax, 0xffffff7f
0000dfb9  b8 fd ff ff ff  mov eax, 0xfffffffd
0000dfbe  0f 43 c2  cmovae eax, edx
0000dfc1  85 c0  test eax, eax
0000dfc3  78 14  js 0x18000dfd9
0000dfc5  89 c2  mov edx, eax
0000dfc7  c1 ea 06  shr edx, 6
0000dfca  48 8b 0c d1  mov rcx, qword ptr [rcx + rdx*8]
0000dfce  31 d2  xor edx, edx
0000dfd0  48 0f a3 c1  bt rcx, rax
0000dfd4  0f 92 c2  setb dl
0000dfd7  89 d0  mov eax, edx
0000dfd9  59  pop rcx
0000dfda  c3  ret
; owner 0xdfe0 runtime_dfe0
0000dfe0  52  push rdx
0000dfe1  56  push rsi
0000dfe2  50  push rax
0000dfe3  48 89 c2  mov rdx, rax
0000dfe6  80 3d d3 2a 01 00 00  cmp byte ptr [rip + 0x12ad3], 0
0000dfed  75 05  jne 0x18000dff4
0000dfef  e8 cc f1 ff ff  call 0x18000d1c0
0000dff4  48 63 c1  movsxd rax, ecx
0000dff7  48 8d 04 40  lea rax, [rax + rax*2]
0000dffb  48 8d 0d ce 2a 01 00  lea rcx, [rip + 0x12ace]
0000e002  8b 4c c1 08  mov ecx, dword ptr [rcx + rax*8 + 8]
0000e006  8d 41 80  lea eax, [rcx - 0x80]
0000e009  3d 7f ff ff ff  cmp eax, 0xffffff7f
0000e00e  b8 fd ff ff ff  mov eax, 0xfffffffd
0000e013  0f 43 c1  cmovae eax, ecx
0000e016  85 c0  test eax, eax
0000e018  78 13  js 0x18000e02d
0000e01a  be 01 00 00 00  mov esi, 1
0000e01f  89 c1  mov ecx, eax
0000e021  48 d3 e6  shl rsi, cl
0000e024  c1 e8 06  shr eax, 6
0000e027  48 09 34 c2  or qword ptr [rdx + rax*8], rsi
0000e02b  31 c0  xor eax, eax
0000e02d  48 83 c4 08  add rsp, 8
0000e031  5e  pop rsi
0000e032  5a  pop rdx
0000e033  c3  ret
; owner 0xe040 runtime_e040
0000e040  57  push rdi
0000e059  48 8d 15 80 0c 00 00  lea rdx, [rip + 0xc80]
0000e078  3e ff e2  notrack jmp rdx
0000e080  48 8d 15 59 03 00 00  lea rdx, [rip + 0x359]
0000e0a4  3e ff e2  notrack jmp rdx
0000e0c0  48 8b 0d b9 07 01 00  mov rcx, qword ptr [rip + 0x107b9]
0000e20a  48 8d 15 cf 02 00 00  lea rdx, [rip + 0x2cf]
0000e215  3e ff e2  notrack jmp rdx
0000e25f  48 8d 15 7a 02 00 00  lea rdx, [rip + 0x27a]
0000e26a  3e ff e2  notrack jmp rdx
; owner 0x109d0 runtime_109d0
000109d0  56  push rsi
000109d1  48 83 ec 20  sub rsp, 0x20
000109d5  89 ce  mov esi, ecx
000109d7  8d 4e fc  lea ecx, [rsi - 4]
000109da  31 c0  xor eax, eax
000109dc  83 f9 fd  cmp ecx, -3
000109df  72 1b  jb 0x1800109fc
000109e1  83 3d 94 09 01 00 00  cmp dword ptr [rip + 0x10994], 0
000109e8  75 05  jne 0x1800109ef
000109ea  e8 21 00 00 00  call 0x180010a10
000109ef  c1 e6 02  shl esi, 2
000109f2  48 8d 05 77 09 01 00  lea rax, [rip + 0x10977]
000109f9  8b 04 b0  mov eax, dword ptr [rax + rsi*4]
000109fc  48 83 c4 20  add rsp, 0x20
00010a00  5e  pop rsi
00010a01  c3  ret
; owner 0x10a10 runtime_10a10
00010a10  55  push rbp
00010a11  41 57  push r15
00010a13  41 56  push r14
00010a15  41 55  push r13
00010a17  41 54  push r12
00010a19  56  push rsi
00010a1a  57  push rdi
00010a1b  53  push rbx
00010a1c  48 81 ec c8 00 00 00  sub rsp, 0xc8
00010a23  48 8d ac 24 80 00 00 00  lea rbp, [rsp + 0x80]
00010a2b  48 8b 05 ce dd 00 00  mov rax, qword ptr [rip + 0xddce]
00010a32  48 31 e8  xor rax, rbp
00010a35  48 89 45 40  mov qword ptr [rbp + 0x40], rax
00010a39  c7 45 b0 00 00 00 00  mov dword ptr [rbp - 0x50], 0
00010a40  50  push rax
00010a41  51  push rcx
00010a42  9c  pushfq
00010a43  58  pop rax
00010a44  89 c1  mov ecx, eax
00010a46  35 00 00 20 00  xor eax, 0x200000
00010a4b  50  push rax
00010a4c  9d  popfq
00010a4d  9c  pushfq
00010a4e  58  pop rax
00010a4f  39 c8  cmp eax, ecx
00010a51  74 08  je 0x180010a5b
00010a53  c7 45 b0 01 00 00 00  mov dword ptr [rbp - 0x50], 1
00010a5a  51  push rcx
00010a5b  9d  popfq
00010a5c  59  pop rcx
00010a5d  58  pop rax
00010a5e  83 7d b0 00  cmp dword ptr [rbp - 0x50], 0
00010a62  0f 84 18 03 00 00  je 0x180010d80
00010a68  4c 8d 45 a0  lea r8, [rbp - 0x60]
00010a6c  4c 89 45 30  mov qword ptr [rbp + 0x30], r8
00010a70  0f 28 05 79 77 00 00  movaps xmm0, xmmword ptr [rip + 0x7779]
00010a77  0f 29 45 b0  movaps xmmword ptr [rbp - 0x50], xmm0
00010a7b  31 c0  xor eax, eax
00010a7d  89 45 a8  mov dword ptr [rbp - 0x58], eax
00010a80  41 89 00  mov dword ptr [r8], eax
00010a83  50  push rax
00010a84  53  push rbx
00010a85  51  push rcx
00010a86  52  push rdx
00010a87  b8 00 00 00 00  mov eax, 0
00010a8c  0f a2  cpuid
00010a8e  39 5d b0  cmp dword ptr [rbp - 0x50], ebx
00010a91  75 17  jne 0x180010aaa
00010a93  39 55 b4  cmp dword ptr [rbp - 0x4c], edx
00010a96  75 12  jne 0x180010aaa
00010a98  39 4d b8  cmp dword ptr [rbp - 0x48], ecx
00010a9b  75 0d  jne 0x180010aaa
00010a9d  c7 45 a8 01 00 00 00  mov dword ptr [rbp - 0x58], 1
00010aa4  48 8b 55 30  mov rdx, qword ptr [rbp + 0x30]
00010aa8  89 02  mov dword ptr [rdx], eax
00010aaa  5a  pop rdx
00010aab  59  pop rcx
00010aac  5b  pop rbx
00010aad  58  pop rax
00010aae  8b 45 a8  mov eax, dword ptr [rbp - 0x58]
00010ab1  89 05 b9 08 01 00  mov dword ptr [rip + 0x108b9], eax
00010ab7  41 8b 00  mov eax, dword ptr [r8]
00010aba  89 05 b4 08 01 00  mov dword ptr [rip + 0x108b4], eax
00010ac0  83 f8 04  cmp eax, 4
00010ac3  0f 8c e7 00 00 00  jl 0x180010bb0
00010ac9  48 8d 45 b0  lea rax, [rbp - 0x50]
00010acd  48 89 45 30  mov qword ptr [rbp + 0x30], rax
00010ad1  c7 45 a8 00 00 00 00  mov dword ptr [rbp - 0x58], 0
00010ad8  50  push rax
00010ad9  53  push rbx
00010ada  51  push rcx
00010adb  52  push rdx
00010adc  57  push rdi
00010add  4c 8b 45 30  mov r8, qword ptr [rbp + 0x30]
00010ae1  bf 00 00 00 00  mov edi, 0
00010ae6  89 f9  mov ecx, edi
00010ae8  b8 04 00 00 00  mov eax, 4
00010aed  0f a2  cpuid
00010aef  a9 1f 00 00 00  test eax, 0x1f
00010af4  74 1d  je 0x180010b13
00010af6  41 89 00  mov dword ptr [r8], eax
00010af9  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010afd  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010b01  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010b05  83 c7 01  add edi, 1
00010b08  83 ff 08  cmp edi, 8
00010b0b  7d 06  jge 0x180010b13
00010b0d  49 83 c0 10  add r8, 0x10
00010b11  eb d3  jmp 0x180010ae6
00010b13  89 7d a8  mov dword ptr [rbp - 0x58], edi
00010b16  5f  pop rdi
00010b17  5a  pop rdx
00010b18  59  pop rcx
00010b19  5b  pop rbx
00010b1a  58  pop rax
00010b1b  48 63 45 a8  movsxd rax, dword ptr [rbp - 0x58]
00010b1f  48 85 c0  test rax, rax
00010b22  0f 8e 85 00 00 00  jle 0x180010bad
00010b28  48 c1 e0 04  shl rax, 4
00010b2c  31 c9  xor ecx, ecx
00010b2e  48 8d 15 3b 08 01 00  lea rdx, [rip + 0x1083b]
00010b35  44 8b 44 0d b0  mov r8d, dword ptr [rbp + rcx - 0x50]
00010b3a  45 89 c1  mov r9d, r8d
00010b3d  41 83 c9 02  or r9d, 2
00010b41  41 83 e1 1f  and r9d, 0x1f
00010b45  41 83 f9 03  cmp r9d, 3
00010b49  75 59  jne 0x180010ba4
00010b4b  44 8b 54 0d b4  mov r10d, dword ptr [rbp + rcx - 0x4c]
00010b50  44 8b 4c 0d b8  mov r9d, dword ptr [rbp + rcx - 0x48]
00010b55  45 89 d3  mov r11d, r10d
00010b58  41 81 e3 ff 0f 00 00  and r11d, 0xfff
00010b5f  41 ff c3  inc r11d
00010b62  41 d1 e8  shr r8d, 1
00010b65  41 83 e0 70  and r8d, 0x70
00010b69  46 89 5c 02 04  mov dword ptr [rdx + r8 + 4], r11d
00010b6e  44 89 d6  mov esi, r10d
00010b71  c1 ee 0c  shr esi, 0xc
00010b74  81 e6 ff 03 00 00  and esi, 0x3ff
00010b7a  ff c6  inc esi
00010b7c  42 89 74 02 08  mov dword ptr [rdx + r8 + 8], esi
00010b81  41 c1 ea 16  shr r10d, 0x16
00010b85  41 ff c2  inc r10d
00010b88  46 89 54 02 0c  mov dword ptr [rdx + r8 + 0xc], r10d
00010b8d  41 ff c1  inc r9d
00010b90  45 0f af d3  imul r10d, r11d
00010b94  44 0f af ce  imul r9d, esi
00010b98  45 0f af ca  imul r9d, r10d
00010b9c  41 c1 e9 0a  shr r9d, 0xa
00010ba0  45 89 0c 10  mov dword ptr [r8 + rdx], r9d
00010ba4  48 83 c1 10  add rcx, 0x10
00010ba8  48 39 c8  cmp rax, rcx
00010bab  75 88  jne 0x180010b35
00010bad  8b 45 a0  mov eax, dword ptr [rbp - 0x60]
00010bb0  83 3d c9 07 01 00 00  cmp dword ptr [rip + 0x107c9], 0
00010bb7  0f 85 c3 01 00 00  jne 0x180010d80
00010bbd  83 f8 02  cmp eax, 2
00010bc0  0f 8c ba 01 00 00  jl 0x180010d80
00010bc6  4c 8d 4d b0  lea r9, [rbp - 0x50]
00010bca  4c 89 4d 30  mov qword ptr [rbp + 0x30], r9
00010bce  50  push rax
00010bcf  53  push rbx
00010bd0  51  push rcx
00010bd1  52  push rdx
00010bd2  4c 8b 45 30  mov r8, qword ptr [rbp + 0x30]
00010bd6  b8 02 00 00 00  mov eax, 2
00010bdb  0f a2  cpuid
00010bdd  41 89 00  mov dword ptr [r8], eax
00010be0  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010be4  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010be8  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010bec  3c 01  cmp al, 1
00010bee  7e 4d  jle 0x180010c3d
00010bf0  3c 02  cmp al, 2
00010bf2  7e 32  jle 0x180010c26
00010bf4  3c 03  cmp al, 3
00010bf6  7e 17  jle 0x180010c0f
00010bf8  b8 02 00 00 00  mov eax, 2
00010bfd  0f a2  cpuid
00010bff  41 89 40 30  mov dword ptr [r8 + 0x30], eax
00010c03  41 89 58 34  mov dword ptr [r8 + 0x34], ebx
00010c07  41 89 48 38  mov dword ptr [r8 + 0x38], ecx
00010c0b  41 89 50 3c  mov dword ptr [r8 + 0x3c], edx
00010c0f  b8 02 00 00 00  mov eax, 2
00010c14  0f a2  cpuid
00010c16  41 89 40 20  mov dword ptr [r8 + 0x20], eax
00010c1a  41 89 58 24  mov dword ptr [r8 + 0x24], ebx
00010c1e  41 89 48 28  mov dword ptr [r8 + 0x28], ecx
00010c22  41 89 50 2c  mov dword ptr [r8 + 0x2c], edx
00010c26  b8 02 00 00 00  mov eax, 2
00010c2b  0f a2  cpuid
00010c2d  41 89 40 10  mov dword ptr [r8 + 0x10], eax
00010c31  41 89 58 14  mov dword ptr [r8 + 0x14], ebx
00010c35  41 89 48 18  mov dword ptr [r8 + 0x18], ecx
00010c39  41 89 50 1c  mov dword ptr [r8 + 0x1c], edx
00010c3d  5a  pop rdx
00010c3e  59  pop rcx
00010c3f  5b  pop rbx
00010c40  58  pop rax
00010c41  41 8a 01  mov al, byte ptr [r9]
00010c44  8d 0c 85 00 00 00 00  lea ecx, [rax*4]
00010c4b  3c 05  cmp al, 5
00010c4d  0f b6 c9  movzx ecx, cl
00010c50  b8 10 00 00 00  mov eax, 0x10
00010c55  0f 42 c1  cmovb eax, ecx
00010c58  84 c0  test al, al
00010c5a  0f 84 20 01 00 00  je 0x180010d80
00010c60  44 0f b6 d0  movzx r10d, al
00010c64  45 31 db  xor r11d, r11d
00010c67  48 8d 35 92 75 00 00  lea rsi, [rip + 0x7592]
00010c6e  48 8d 7d 30  lea rdi, [rbp + 0x30]
00010c72  4c 8d 35 f7 06 01 00  lea r14, [rip + 0x106f7]
00010c79  42 80 7c 9d b3 00  cmp byte ptr [rbp + r11*4 - 0x4d], 0
00010c7f  0f 88 d1 00 00 00  js 0x180010d56
00010c85  45 31 ff  xor r15d, r15d
00010c88  47 0f b6 24 39  movzx r12d, byte ptr [r9 + r15]
00010c8d  49 81 fc ff 00 00 00  cmp r12, 0xff
00010c94  0f 84 ce 00 00 00  je 0x180010d68
00010c9a  46 8b 2c e6  mov r13d, dword ptr [rsi + r12*8]
00010c9e  44 89 e8  mov eax, r13d
00010ca1  83 e0 07  and eax, 7
00010ca4  0f 84 9f 00 00 00  je 0x180010d49
00010caa  83 f8 02  cmp eax, 2
00010cad  75 66  jne 0x180010d15
00010caf  41 80 fc 49  cmp r12b, 0x49
00010cb3  75 60  jne 0x180010d15
00010cb5  48 89 7d a8  mov qword ptr [rbp - 0x58], rdi
00010cb9  c7 45 a4 01 00 00 00  mov dword ptr [rbp - 0x5c], 1
00010cc0  50  push rax
00010cc1  53  push rbx
00010cc2  51  push rcx
00010cc3  52  push rdx
00010cc4  4c 8b 45 a8  mov r8, qword ptr [rbp - 0x58]
00010cc8  8b 45 a4  mov eax, dword ptr [rbp - 0x5c]
00010ccb  0f a2  cpuid
00010ccd  41 89 00  mov dword ptr [r8], eax
00010cd0  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010cd4  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010cd8  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010cdc  5a  pop rdx
00010cdd  59  pop rcx
00010cde  5b  pop rbx
00010cdf  58  pop rax
00010ce0  8b 4d 30  mov ecx, dword ptr [rbp + 0x30]
00010ce3  89 ca  mov edx, ecx
00010ce5  81 e2 00 0f 00 0f  and edx, 0xf000f00
00010ceb  b8 02 00 00 00  mov eax, 2
00010cf0  81 fa 00 0f 00 00  cmp edx, 0xf00
00010cf6  75 1d  jne 0x180010d15
00010cf8  89 c8  mov eax, ecx
00010cfa  c1 e8 0c  shr eax, 0xc
00010cfd  25 f0 00 00 00  and eax, 0xf0
00010d02  c1 e9 04  shr ecx, 4
00010d05  83 e1 0f  and ecx, 0xf
00010d08  09 c1  or ecx, eax
00010d0a  31 c0  xor eax, eax
00010d0c  83 f9 06  cmp ecx, 6
00010d0f  0f 94 c0  sete al
00010d12  83 c8 02  or eax, 2
00010d15  44 89 e9  mov ecx, r13d
00010d18  c1 e9 03  shr ecx, 3
00010d1b  81 e1 ff 0f 00 00  and ecx, 0xfff
00010d21  c1 e0 04  shl eax, 4
00010d24  41 89 4c 06 04  mov dword ptr [r14 + rax + 4], ecx
00010d29  44 89 e9  mov ecx, r13d
00010d2c  c1 e9 0f  shr ecx, 0xf
00010d2f  83 e1 7f  and ecx, 0x7f
00010d32  41 89 4c 06 08  mov dword ptr [r14 + rax + 8], ecx
00010d37  41 c1 ed 16  shr r13d, 0x16
00010d3b  45 89 6c 06 0c  mov dword ptr [r14 + rax + 0xc], r13d
00010d40  42 8b 4c e6 04  mov ecx, dword ptr [rsi + r12*8 + 4]
00010d45  42 89 0c 30  mov dword ptr [rax + r14], ecx
00010d49  49 ff c7  inc r15
00010d4c  49 83 ff 04  cmp r15, 4
00010d50  0f 85 32 ff ff ff  jne 0x180010c88
00010d56  49 ff c3  inc r11
00010d59  49 83 c1 04  add r9, 4
00010d5d  4d 39 d3  cmp r11, r10
00010d60  0f 85 13 ff ff ff  jne 0x180010c79
00010d66  eb 18  jmp 0x180010d80
00010d68  0f 57 c0  xorps xmm0, xmm0
00010d6b  0f 29 05 0e 06 01 00  movaps xmmword ptr [rip + 0x1060e], xmm0
00010d72  0f 29 05 17 06 01 00  movaps xmmword ptr [rip + 0x10617], xmm0
00010d79  0f 29 05 20 06 01 00  movaps xmmword ptr [rip + 0x10620], xmm0
00010d80  c7 05 f2 05 01 00 01 00 00 00  mov dword ptr [rip + 0x105f2], 1
00010d8a  48 8b 4d 40  mov rcx, qword ptr [rbp + 0x40]
00010d8e  48 31 e9  xor rcx, rbp
00010d91  e8 9a 3a 00 00  call 0x180014830
00010d96  90  nop
00010d97  48 81 c4 c8 00 00 00  add rsp, 0xc8
00010d9e  5b  pop rbx
00010d9f  5f  pop rdi
00010da0  5e  pop rsi
00010da1  41 5c  pop r12
00010da3  41 5d  pop r13
00010da5  41 5e  pop r14
00010da7  41 5f  pop r15
00010da9  5d  pop rbp
00010daa  c3  ret
; owner 0x10db0 runtime_10db0
00010db0  55  push rbp
00010db1  56  push rsi
00010db2  53  push rbx
00010db3  48 83 ec 50  sub rsp, 0x50
00010db7  48 8d 6c 24 50  lea rbp, [rsp + 0x50]
00010dbc  48 8b 05 3d da 00 00  mov rax, qword ptr [rip + 0xda3d]
00010dc3  48 31 e8  xor rax, rbp
00010dc6  48 89 45 f8  mov qword ptr [rbp - 8], rax
00010dca  83 3d ab 05 01 00 00  cmp dword ptr [rip + 0x105ab], 0
00010dd1  75 05  jne 0x180010dd8
00010dd3  e8 38 fc ff ff  call 0x180010a10
00010dd8  83 3d 91 05 01 00 00  cmp dword ptr [rip + 0x10591], 0
00010ddf  74 3b  je 0x180010e1c
00010de1  83 3d 8c 05 01 00 00  cmp dword ptr [rip + 0x1058c], 0
00010de8  0f 84 4c 01 00 00  je 0x180010f3a
00010dee  53  push rbx
00010def  b8 01 00 00 00  mov eax, 1
00010df4  0f a2  cpuid
00010df6  89 5d e0  mov dword ptr [rbp - 0x20], ebx
00010df9  89 55 d8  mov dword ptr [rbp - 0x28], edx
00010dfc  89 45 d4  mov dword ptr [rbp - 0x2c], eax
00010dff  5b  pop rbx
00010e00  8b 45 d8  mov eax, dword ptr [rbp - 0x28]
00010e03  89 c1  mov ecx, eax
00010e05  c1 e9 17  shr ecx, 0x17
00010e08  83 e1 01  and ecx, 1
00010e0b  0f ba e0 1a  bt eax, 0x1a
00010e0f  be 02 00 00 00  mov esi, 2
00010e14  0f 43 f1  cmovae esi, ecx
00010e17  e9 20 01 00 00  jmp 0x180010f3c
00010e1c  4c 8d 4d e0  lea r9, [rbp - 0x20]
00010e20  4c 89 4d d8  mov qword ptr [rbp - 0x28], r9
00010e24  c7 45 d4 00 00 00 00  mov dword ptr [rbp - 0x2c], 0
00010e2b  50  push rax
00010e2c  53  push rbx
00010e2d  51  push rcx
00010e2e  52  push rdx
00010e2f  4c 8b 45 d8  mov r8, qword ptr [rbp - 0x28]
00010e33  8b 45 d4  mov eax, dword ptr [rbp - 0x2c]
00010e36  0f a2  cpuid
00010e38  41 89 00  mov dword ptr [r8], eax
00010e3b  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010e3f  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010e43  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010e47  5a  pop rdx
00010e48  59  pop rcx
00010e49  5b  pop rbx
00010e4a  58  pop rax
00010e4b  31 f6  xor esi, esi
00010e4d  41 81 79 04 41 75 74 68  cmp dword ptr [r9 + 4], 0x68747541
00010e55  0f 85 b6 01 00 00  jne 0x180011011
00010e5b  81 7d ec 65 6e 74 69  cmp dword ptr [rbp - 0x14], 0x69746e65
00010e62  0f 85 a9 01 00 00  jne 0x180011011
00010e68  81 7d e8 63 41 4d 44  cmp dword ptr [rbp - 0x18], 0x444d4163
00010e6f  0f 85 9c 01 00 00  jne 0x180011011
00010e75  4c 89 4d d8  mov qword ptr [rbp - 0x28], r9
00010e79  c7 45 d4 01 00 00 00  mov dword ptr [rbp - 0x2c], 1
00010e80  50  push rax
00010e81  53  push rbx
00010e82  51  push rcx
00010e83  52  push rdx
00010e84  4c 8b 45 d8  mov r8, qword ptr [rbp - 0x28]
00010e88  8b 45 d4  mov eax, dword ptr [rbp - 0x2c]
00010e8b  0f a2  cpuid
00010e8d  41 89 00  mov dword ptr [r8], eax
00010e90  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010e94  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010e98  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010e9c  5a  pop rdx
00010e9d  59  pop rcx
00010e9e  5b  pop rbx
00010e9f  58  pop rax
00010ea0  8b 75 ec  mov esi, dword ptr [rbp - 0x14]
00010ea3  c1 ee 17  shr esi, 0x17
00010ea6  83 e6 01  and esi, 1
00010ea9  4c 89 4d d8  mov qword ptr [rbp - 0x28], r9
00010ead  c7 45 d4 00 00 00 80  mov dword ptr [rbp - 0x2c], 0x80000000
00010eb4  50  push rax
00010eb5  53  push rbx
00010eb6  51  push rcx
00010eb7  52  push rdx
00010eb8  4c 8b 45 d8  mov r8, qword ptr [rbp - 0x28]
00010ebc  8b 45 d4  mov eax, dword ptr [rbp - 0x2c]
00010ebf  0f a2  cpuid
00010ec1  41 89 00  mov dword ptr [r8], eax
00010ec4  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010ec8  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010ecc  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010ed0  5a  pop rdx
00010ed1  59  pop rcx
00010ed2  5b  pop rbx
00010ed3  58  pop rax
00010ed4  81 7d e0 06 00 00 80  cmp dword ptr [rbp - 0x20], 0x80000006
00010edb  0f 82 30 01 00 00  jb 0x180011011
00010ee1  4c 89 4d d8  mov qword ptr [rbp - 0x28], r9
00010ee5  c7 45 d4 06 00 00 80  mov dword ptr [rbp - 0x2c], 0x80000006
00010eec  50  push rax
00010eed  53  push rbx
00010eee  51  push rcx
00010eef  52  push rdx
00010ef0  4c 8b 45 d8  mov r8, qword ptr [rbp - 0x28]
00010ef4  8b 45 d4  mov eax, dword ptr [rbp - 0x2c]
00010ef7  0f a2  cpuid
00010ef9  41 89 00  mov dword ptr [r8], eax
00010efc  41 89 58 04  mov dword ptr [r8 + 4], ebx
00010f00  41 89 48 08  mov dword ptr [r8 + 8], ecx
00010f04  41 89 50 0c  mov dword ptr [r8 + 0xc], edx
00010f08  5a  pop rdx
00010f09  59  pop rcx
00010f0a  5b  pop rbx
00010f0b  58  pop rax
00010f0c  0f b7 45 ea  movzx eax, word ptr [rbp - 0x16]
00010f10  c1 e0 0a  shl eax, 0xa
00010f13  48 89 05 56 d9 00 00  mov qword ptr [rip + 0xd956], rax
00010f1a  d1 e8  shr eax, 1
00010f1c  48 89 05 55 d9 00 00  mov qword ptr [rip + 0xd955], rax
00010f23  48 8b 05 56 d9 00 00  mov rax, qword ptr [rip + 0xd956]
00010f2a  48 c1 e8 02  shr rax, 2
00010f2e  48 89 05 5b d9 00 00  mov qword ptr [rip + 0xd95b], rax
00010f35  e9 d7 00 00 00  jmp 0x180011011
00010f3a  31 f6  xor esi, esi
00010f3c  8b 05 3e 04 01 00  mov eax, dword ptr [rip + 0x1043e]
00010f42  85 c0  test eax, eax
00010f44  0f 84 b1 00 00 00  je 0x180010ffb
00010f4a  8b 0d 48 04 01 00  mov ecx, dword ptr [rip + 0x10448]
00010f50  0f af 0d 3d 04 01 00  imul ecx, dword ptr [rip + 0x1043d]
00010f57  8b 15 33 04 01 00  mov edx, dword ptr [rip + 0x10433]
00010f5d  44 8b 05 24 04 01 00  mov r8d, dword ptr [rip + 0x10424]
00010f64  44 0f af 05 18 04 01 00  imul r8d, dword ptr [rip + 0x10418]
00010f6c  39 d0  cmp eax, edx
00010f6e  0f 47 d0  cmova edx, eax
00010f71  44 0f 42 c1  cmovb r8d, ecx
00010f75  8b 0d 2d 04 01 00  mov ecx, dword ptr [rip + 0x1042d]
00010f7b  0f af 0d 22 04 01 00  imul ecx, dword ptr [rip + 0x10422]
00010f82  44 8b 0d 17 04 01 00  mov r9d, dword ptr [rip + 0x10417]
00010f89  44 39 ca  cmp edx, r9d
00010f8c  41 0f 43 c8  cmovae ecx, r8d
00010f90  41 0f 46 d1  cmovbe edx, r9d
00010f94  49 89 d0  mov r8, rdx
00010f97  49 c1 e0 0a  shl r8, 0xa
00010f9b  4c 89 05 ce d8 00 00  mov qword ptr [rip + 0xd8ce], r8
00010fa2  48 c1 e2 09  shl rdx, 9
00010fa6  48 89 15 cb d8 00 00  mov qword ptr [rip + 0xd8cb], rdx
00010fad  c1 e0 0a  shl eax, 0xa
00010fb0  48 89 05 c9 d8 00 00  mov qword ptr [rip + 0xd8c9], rax
00010fb7  89 c2  mov edx, eax
00010fb9  d1 ea  shr edx, 1
00010fbb  48 89 15 c6 d8 00 00  mov qword ptr [rip + 0xd8c6], rdx
00010fc2  89 c2  mov edx, eax
00010fc4  c1 ea 02  shr edx, 2
00010fc7  48 89 15 c2 d8 00 00  mov qword ptr [rip + 0xd8c2], rdx
00010fce  48 89 0d e3 03 01 00  mov qword ptr [rip + 0x103e3], rcx
00010fd5  48 c7 05 b8 d8 00 00 00 20 00 00  mov qword ptr [rip + 0xd8b8], 0x2000
00010fe0  48 01 c0  add rax, rax
00010fe3  48 8d 04 40  lea rax, [rax + rax*2]
00010fe7  48 89 05 b2 d8 00 00  mov qword ptr [rip + 0xd8b2], rax
00010fee  48 c7 05 af d8 00 00 00 08 00 00  mov qword ptr [rip + 0xd8af], 0x800
00010ff9  eb 16  jmp 0x180011011
00010ffb  48 8d 0d fe 79 00 00  lea rcx, [rip + 0x79fe]
00011002  e8 e1 37 00 00  call 0x1800147e8
00011007  48 85 c0  test rax, rax
0001100a  74 05  je 0x180011011
0001100c  80 38 00  cmp byte ptr [rax], 0
0001100f  75 21  jne 0x180011032
00011011  89 35 99 03 01 00  mov dword ptr [rip + 0x10399], esi
00011017  89 35 a3 03 01 00  mov dword ptr [rip + 0x103a3], esi
0001101d  48 8b 4d f8  mov rcx, qword ptr [rbp - 8]
00011021  48 31 e9  xor rcx, rbp
00011024  e8 07 38 00 00  call 0x180014830
00011029  90  nop
0001102a  48 83 c4 50  add rsp, 0x50
0001102e  5b  pop rbx
0001102f  5e  pop rsi
00011030  5d  pop rbp
00011031  c3  ret
00011032  b9 01 00 00 00  mov ecx, 1
00011037  31 d2  xor edx, edx
00011039  45 31 c0  xor r8d, r8d
0001103c  e8 3f 02 00 00  call 0x180011280
00011041  b9 01 00 00 00  mov ecx, 1
00011046  ba 3d 00 00 00  mov edx, 0x3d
0001104b  45 31 c0  xor r8d, r8d
0001104e  e8 2d 02 00 00  call 0x180011280
00011053  b9 01 00 00 00  mov ecx, 1
00011058  31 d2  xor edx, edx
0001105a  45 31 c0  xor r8d, r8d
0001105d  e8 1e 02 00 00  call 0x180011280
00011062  b9 01 00 00 00  mov ecx, 1
00011067  e8 82 37 00 00  call 0x1800147ee
0001106c  cc  int3
; owner 0x11070 runtime_11070
00011070  56  push rsi
00011071  57  push rdi
00011072  48 83 ec 48  sub rsp, 0x48
00011076  89 d7  mov edi, edx
00011078  4c 89 44 24 70  mov qword ptr [rsp + 0x70], r8
0001107d  4c 89 4c 24 78  mov qword ptr [rsp + 0x78], r9
00011082  48 8b 05 77 d7 00 00  mov rax, qword ptr [rip + 0xd777]
00011089  48 31 e0  xor rax, rsp
0001108c  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
00011091  e8 6a 00 00 00  call 0x180011100
00011096  48 89 c6  mov rsi, rax
00011099  85 ff  test edi, edi
0001109b  7e 3f  jle 0x1800110dc
0001109d  48 8d 7c 24 70  lea rdi, [rsp + 0x70]
000110a2  48 89 7c 24 38  mov qword ptr [rsp + 0x38], rdi
000110a7  e8 44 0f 00 00  call 0x180011ff0
000110ac  48 8b 08  mov rcx, qword ptr [rax]
000110af  48 83 c9 02  or rcx, 2
000110b3  48 89 7c 24 28  mov qword ptr [rsp + 0x28], rdi
000110b8  48 c7 44 24 20 00 00 00 00  mov qword ptr [rsp + 0x20], 0
000110c1  48 8d 3d 08 03 01 00  lea rdi, [rip + 0x10308]
000110c8  41 b8 00 02 00 00  mov r8d, 0x200
000110ce  48 89 fa  mov rdx, rdi
000110d1  49 89 f1  mov r9, rsi
000110d4  e8 1b 37 00 00  call 0x1800147f4
000110d9  48 89 fe  mov rsi, rdi
000110dc  48 8b 4c 24 40  mov rcx, qword ptr [rsp + 0x40]
000110e1  48 31 e1  xor rcx, rsp
000110e4  e8 47 37 00 00  call 0x180014830
000110e9  48 89 f0  mov rax, rsi
000110ec  48 83 c4 48  add rsp, 0x48
000110f0  5f  pop rdi
000110f1  5e  pop rsi
000110f2  c3  ret
; owner 0x11100 runtime_11100
00011100  56  push rsi
00011101  57  push rdi
00011102  48 81 ec c8 00 00 00  sub rsp, 0xc8
00011109  48 8b 05 f0 d6 00 00  mov rax, qword ptr [rip + 0xd6f0]
00011110  48 31 e0  xor rax, rsp
00011113  48 89 84 24 c0 00 00 00  mov qword ptr [rsp + 0xc0], rax
0001111b  85 c9  test ecx, ecx
0001111d  0f 84 fc 00 00 00  je 0x18001121f
00011123  89 ce  mov esi, ecx
00011125  80 3d ac 06 01 00 00  cmp byte ptr [rip + 0x106ac], 0
0001112c  75 4c  jne 0x18001117a
0001112e  c6 05 a3 06 01 00 01  mov byte ptr [rip + 0x106a3], 1
00011135  ff 15 65 3f 00 00  call qword ptr [rip + 0x3f65]
0001113b  48 8d 15 ca 7c 00 00  lea rdx, [rip + 0x7cca]
00011142  4c 8d 0d b7 7c 00 00  lea r9, [rip + 0x7cb7]
00011149  48 8d 7c 24 40  lea rdi, [rsp + 0x40]
0001114e  48 89 f9  mov rcx, rdi
00011151  41 89 c0  mov r8d, eax
00011154  e8 17 3b 00 00  call 0x180014c70
00011159  48 89 f9  mov rcx, rdi
0001115c  31 d2  xor edx, edx
0001115e  45 31 c0  xor r8d, r8d
00011161  ff 15 41 3f 00 00  call qword ptr [rip + 0x3f41]
00011167  48 89 05 72 06 01 00  mov qword ptr [rip + 0x10672], rax
0001116e  48 85 c0  test rax, rax
00011171  74 07  je 0x18001117a
00011173  c6 05 62 06 01 00 01  mov byte ptr [rip + 0x10662], 1
0001117a  48 63 c6  movsxd rax, esi
0001117d  48 c1 e0 04  shl rax, 4
00011181  48 8d 0d 98 78 00 00  lea rcx, [rip + 0x7898]
00011188  48 8b 7c 08 08  mov rdi, qword ptr [rax + rcx + 8]
0001118d  80 3d 48 06 01 00 01  cmp byte ptr [rip + 0x10648], 1
00011194  0f 85 bf 00 00 00  jne 0x180011259
0001119a  81 c6 00 00 00 80  add esi, 0x80000000
000111a0  48 8b 15 39 06 01 00  mov rdx, qword ptr [rip + 0x10639]
000111a7  48 8d 44 24 40  lea rax, [rsp + 0x40]
000111ac  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000111b1  48 c7 44 24 30 00 00 00 00  mov qword ptr [rsp + 0x30], 0
000111ba  c7 44 24 28 00 02 00 00  mov dword ptr [rsp + 0x28], 0x200
000111c2  b9 00 09 00 00  mov ecx, 0x900
000111c7  41 89 f0  mov r8d, esi
000111ca  41 b9 09 04 00 00  mov r9d, 0x409
000111d0  ff 15 3a 3e 00 00  call qword ptr [rip + 0x3e3a]
000111d6  85 c0  test eax, eax
000111d8  74 7f  je 0x180011259
000111da  48 8b 74 24 40  mov rsi, qword ptr [rsp + 0x40]
000111df  48 89 f1  mov rcx, rsi
000111e2  e8 13 36 00 00  call 0x1800147fa
000111e7  48 83 f8 02  cmp rax, 2
000111eb  72 3b  jb 0x180011228
000111ed  80 7c 06 fe 0d  cmp byte ptr [rsi + rax - 2], 0xd
000111f2  75 34  jne 0x180011228
000111f4  80 7c 30 ff 0a  cmp byte ptr [rax + rsi - 1], 0xa
000111f9  75 2d  jne 0x180011228
000111fb  48 83 c0 fe  add rax, -2
000111ff  48 8d 3d ea 05 01 00  lea rdi, [rip + 0x105ea]
00011206  48 89 f9  mov rcx, rdi
00011209  48 89 f2  mov rdx, rsi
0001120c  49 89 c0  mov r8, rax
0001120f  48 89 c6  mov rsi, rax
00011212  e8 e9 35 00 00  call 0x180014800
00011217  48 89 f0  mov rax, rsi
0001121a  48 01 f8  add rax, rdi
0001121d  eb 25  jmp 0x180011244
0001121f  48 8d 3d f5 77 00 00  lea rdi, [rip + 0x77f5]
00011226  eb 31  jmp 0x180011259
00011228  48 8d 0d c1 05 01 00  lea rcx, [rip + 0x105c1]
0001122f  41 b8 00 02 00 00  mov r8d, 0x200
00011235  48 89 f2  mov rdx, rsi
00011238  e8 c3 35 00 00  call 0x180014800
0001123d  48 8d 05 ab 07 01 00  lea rax, [rip + 0x107ab]
00011244  c6 00 00  mov byte ptr [rax], 0
00011247  48 8b 4c 24 40  mov rcx, qword ptr [rsp + 0x40]
0001124c  ff 15 b6 3d 00 00  call qword ptr [rip + 0x3db6]
00011252  48 8d 3d 97 05 01 00  lea rdi, [rip + 0x10597]
00011259  48 8b 8c 24 c0 00 00 00  mov rcx, qword ptr [rsp + 0xc0]
00011261  48 31 e1  xor rcx, rsp
00011264  e8 c7 35 00 00  call 0x180014830
00011269  48 89 f8  mov rax, rdi
0001126c  48 81 c4 c8 00 00 00  add rsp, 0xc8
00011273  5f  pop rdi
00011274  5e  pop rsi
00011275  c3  ret
; owner 0x11280 runtime_11280
00011280  56  push rsi
00011281  57  push rdi
00011282  48 83 ec 48  sub rsp, 0x48
00011286  4c 89 4c 24 78  mov qword ptr [rsp + 0x78], r9
0001128b  48 8b 05 6e d5 00 00  mov rax, qword ptr [rip + 0xd56e]
00011292  48 31 e0  xor rax, rsp
00011295  48 89 44 24 40  mov qword ptr [rsp + 0x40], rax
0001129a  85 d2  test edx, edx
0001129c  74 61  je 0x1800112ff
0001129e  44 89 c7  mov edi, r8d
000112a1  89 d1  mov ecx, edx
000112a3  e8 58 fe ff ff  call 0x180011100
000112a8  48 89 c6  mov rsi, rax
000112ab  85 ff  test edi, edi
000112ad  7e 3f  jle 0x1800112ee
000112af  48 8d 7c 24 78  lea rdi, [rsp + 0x78]
000112b4  48 89 7c 24 38  mov qword ptr [rsp + 0x38], rdi
000112b9  e8 32 0d 00 00  call 0x180011ff0
000112be  48 8b 08  mov rcx, qword ptr [rax]
000112c1  48 83 c9 02  or rcx, 2
000112c5  48 89 7c 24 28  mov qword ptr [rsp + 0x28], rdi
000112ca  48 c7 44 24 20 00 00 00 00  mov qword ptr [rsp + 0x20], 0
000112d3  48 8d 3d f6 02 01 00  lea rdi, [rip + 0x102f6]
000112da  41 b8 00 02 00 00  mov r8d, 0x200
000112e0  48 89 fa  mov rdx, rdi
000112e3  49 89 f1  mov r9, rsi
000112e6  e8 09 35 00 00  call 0x1800147f4
000112eb  48 89 fe  mov rsi, rdi
000112ee  48 8d 0d 22 77 00 00  lea rcx, [rip + 0x7722]
000112f5  48 89 f2  mov rdx, rsi
000112f8  e8 d3 39 00 00  call 0x180014cd0
000112fd  eb 0c  jmp 0x18001130b
000112ff  48 8d 0d 0f 77 00 00  lea rcx, [rip + 0x770f]
00011306  e8 c5 39 00 00  call 0x180014cd0
0001130b  48 8b 4c 24 40  mov rcx, qword ptr [rsp + 0x40]
00011310  48 31 e1  xor rcx, rsp
00011313  e8 18 35 00 00  call 0x180014830
00011318  90  nop
00011319  48 83 c4 48  add rsp, 0x48
0001131d  5f  pop rdi
0001131e  5e  pop rsi
0001131f  c3  ret
; owner 0x11320 PPEXEC_APCLOSE_C
00011320  48 83 ec 28  sub rsp, 0x28
00011324  48 89 4c 24 38  mov qword ptr [rsp + 0x38], rcx
00011329  48 8d 4c 24 38  lea rcx, [rsp + 0x38]
0001132e  48 89 54 24 30  mov qword ptr [rsp + 0x30], rdx
00011333  48 8d 54 24 30  lea rdx, [rsp + 0x30]
00011338  e8 13 3e ff ff  call 0x180005150
0001133d  48 83 c4 28  add rsp, 0x28
00011341  c3  ret
; owner 0x11342 atdms0.dll!DMS_RTLAYL import thunk
00011342  ff 25 e8 41 00 00  jmp qword ptr [rip + 0x41e8]
; owner 0x11348 atdms0.dll!LM_RETURN_APROP_LICENSE import thunk
00011348  ff 25 d2 41 00 00  jmp qword ptr [rip + 0x41d2]
; owner 0x1134e atdms0.dll!DMS_ASPENC import thunk
0001134e  ff 25 d4 41 00 00  jmp qword ptr [rip + 0x41d4]
; owner 0x11354 atdms.dll!DMS_LOCATI import thunk
00011354  ff 25 ae 41 00 00  jmp qword ptr [rip + 0x41ae]
; owner 0x1138a atdms.dll!DMS_ILOAD import thunk
0001138a  ff 25 30 41 00 00  jmp qword ptr [rip + 0x4130]
; owner 0x11390 atdms.dll!DMS_ICKFPE import thunk
00011390  ff 25 22 41 00 00  jmp qword ptr [rip + 0x4122]
; owner 0x113a8 atdms.dll!DMS_IRRCHK import thunk
000113a8  ff 25 ea 40 00 00  jmp qword ptr [rip + 0x40ea]
; owner 0x113b4 atdms.dll!DMS_ERRPRT import thunk
000113b4  ff 25 ce 40 00 00  jmp qword ptr [rip + 0x40ce]
; owner 0x113ba atdms.dll!DMS_DOCALL import thunk
000113ba  ff 25 c0 40 00 00  jmp qword ptr [rip + 0x40c0]
; owner 0x113c0 atdms.dll!DMS_APCWRK import thunk
000113c0  ff 25 b2 40 00 00  jmp qword ptr [rip + 0x40b2]
; owner 0x113c6 atdms.dll!DMS_PHCWRK import thunk
000113c6  ff 25 a4 40 00 00  jmp qword ptr [rip + 0x40a4]
; owner 0x113d8 atdms.dll!DMS_LOCATM import thunk
000113d8  ff 25 7a 40 00 00  jmp qword ptr [rip + 0x407a]
; owner 0x113e4 atdms.dll!DMS_IPHCFC import thunk
000113e4  ff 25 5e 40 00 00  jmp qword ptr [rip + 0x405e]
; owner 0x113f0 atdms.dll!DMS_TREAD import thunk
000113f0  ff 25 42 40 00 00  jmp qword ptr [rip + 0x4042]
; owner 0x113fc atdms.dll!DMS_ATFREE import thunk
000113fc  ff 25 1e 40 00 00  jmp qword ptr [rip + 0x401e]
; owner 0x11402 atdms.dll!DMS_RALOCI import thunk
00011402  ff 25 20 40 00 00  jmp qword ptr [rip + 0x4020]
; owner 0x11408 atdms.dll!DMS_LOCATR import thunk
00011408  ff 25 0a 40 00 00  jmp qword ptr [rip + 0x400a]
; owner 0x1140e atdms.dll!DMS_ALLOCI import thunk
0001140e  ff 25 fc 3f 00 00  jmp qword ptr [rip + 0x3ffc]
; owner 0x1142c atdms.dll!DMS_LENTHR import thunk
0001142c  ff 25 b6 3f 00 00  jmp qword ptr [rip + 0x3fb6]
; owner 0x11432 atdms.dll!DMS_FREEBD import thunk
00011432  ff 25 a8 3f 00 00  jmp qword ptr [rip + 0x3fa8]
; owner 0x11438 atdms.dll!DMS_ALLOCR import thunk
00011438  ff 25 9a 3f 00 00  jmp qword ptr [rip + 0x3f9a]
; owner 0x1143e atdms.dll!DMS_RCOPY import thunk
0001143e  ff 25 8c 3f 00 00  jmp qword ptr [rip + 0x3f8c]
; owner 0x1144a atdms.dll!DMS_STRLEN import thunk
0001144a  ff 25 70 3f 00 00  jmp qword ptr [rip + 0x3f70]
; owner 0x11450 atdms.dll!DMS_IAPOPN import thunk
00011450  ff 25 32 3f 00 00  jmp qword ptr [rip + 0x3f32]
; owner 0x11462 atdms.dll!DMS_FPULDL import thunk
00011462  ff 25 50 3f 00 00  jmp qword ptr [rip + 0x3f50]
; owner 0x11468 atdms.dll!DMS_UNLVRT import thunk
00011468  ff 25 3a 3f 00 00  jmp qword ptr [rip + 0x3f3a]
; owner 0x1146e atdms.dll!DMS_CLRCMN import thunk
0001146e  ff 25 2c 3f 00 00  jmp qword ptr [rip + 0x3f2c]
; owner 0x11474 atdms.dll!DMS_CLSPDF import thunk
00011474  ff 25 1e 3f 00 00  jmp qword ptr [rip + 0x3f1e]
; owner 0x1148c atdms.dll!DMS_FPLDLB import thunk
0001148c  ff 25 e6 3e 00 00  jmp qword ptr [rip + 0x3ee6]
; owner 0x11492 atdms.dll!DMS_FPFIND import thunk
00011492  ff 25 30 3d 00 00  jmp qword ptr [rip + 0x3d30]
; owner 0x11498 atdms.dll!DMS_DOCALL_30 import thunk
00011498  ff 25 32 3d 00 00  jmp qword ptr [rip + 0x3d32]
; owner 0x114a4 atdms.dll!DMS_CLSBDS import thunk
000114a4  ff 25 36 3d 00 00  jmp qword ptr [rip + 0x3d36]
; owner 0x114aa atdms.dll!DMS_SELF_EXIT import thunk
000114aa  ff 25 38 3d 00 00  jmp qword ptr [rip + 0x3d38]
; owner 0x114b0 atdms.dll!DMS_GET_PRODUCTCODE import thunk
000114b0  ff 25 3a 3d 00 00  jmp qword ptr [rip + 0x3d3a]
; owner 0x114b6 atdms.dll!DMS_BIOCOMPS import thunk
000114b6  ff 25 3c 3d 00 00  jmp qword ptr [rip + 0x3d3c]
; owner 0x114c2 atdms.dll!DMS_WHRAMI import thunk
000114c2  ff 25 40 3d 00 00  jmp qword ptr [rip + 0x3d40]
; owner 0x114c8 atdms.dll!DMS_APOPEN import thunk
000114c8  ff 25 42 3d 00 00  jmp qword ptr [rip + 0x3d42]
; owner 0x114e0 atdms.dll!DMS_INITVMMF import thunk
000114e0  ff 25 4a 3d 00 00  jmp qword ptr [rip + 0x3d4a]
; owner 0x114f2 atdms.dll!DMS_GETASPTOP import thunk
000114f2  ff 25 50 3d 00 00  jmp qword ptr [rip + 0x3d50]
; owner 0x114f8 atdms.dll!DMS_ASGOPN import thunk
000114f8  ff 25 52 3d 00 00  jmp qword ptr [rip + 0x3d52]
; owner 0x1150a atdms.dll!DMS_PCS_INITPLEX import thunk
0001150a  ff 25 58 3d 00 00  jmp qword ptr [rip + 0x3d58]
; owner 0x11510 atdms.dll!DMS_ICKFPE2 import thunk
00011510  ff 25 5a 3d 00 00  jmp qword ptr [rip + 0x3d5a]
; owner 0x1151c atdms.dll!DMS_INT2CS import thunk
0001151c  ff 25 5e 3d 00 00  jmp qword ptr [rip + 0x3d5e]
; owner 0x11522 atdms.dll!DMS_LENTHM import thunk
00011522  ff 25 60 3d 00 00  jmp qword ptr [rip + 0x3d60]
; owner 0x11528 atdms.dll!DMS_GETVER import thunk
00011528  ff 25 62 3d 00 00  jmp qword ptr [rip + 0x3d62]
; owner 0x1152e atdms.dll!DMS_CHKVER import thunk
0001152e  ff 25 dc 3f 00 00  jmp qword ptr [rip + 0x3fdc]
; owner 0x11534 atdms.dll!DMS_MVBYT import thunk
00011534  ff 25 76 3e 00 00  jmp qword ptr [rip + 0x3e76]
; owner 0x1153a atdms.dll!DMS_TCOPY import thunk
0001153a  ff 25 68 3d 00 00  jmp qword ptr [rip + 0x3d68]
; owner 0x11540 atdms.dll!DMS_ALLOCM import thunk
00011540  ff 25 6a 3d 00 00  jmp qword ptr [rip + 0x3d6a]
; owner 0x11546 atdms.dll!DMS_COPY import thunk
00011546  ff 25 6c 3d 00 00  jmp qword ptr [rip + 0x3d6c]
; owner 0x1154c atdms.dll!DMS_IKWTXY import thunk
0001154c  ff 25 6e 3d 00 00  jmp qword ptr [rip + 0x3d6e]
; owner 0x1155e atdms.dll!DMS_ERRSET import thunk
0001155e  ff 25 74 3d 00 00  jmp qword ptr [rip + 0x3d74]
; owner 0x1156a atdms.dll!DMS_CDATE import thunk
0001156a  ff 25 78 3d 00 00  jmp qword ptr [rip + 0x3d78]
; owner 0x11570 atdms.dll!DMS_LENTHI import thunk
00011570  ff 25 7a 3d 00 00  jmp qword ptr [rip + 0x3d7a]
; owner 0x1157c atdms.dll!DMS_SETNCC import thunk
0001157c  ff 25 7e 3d 00 00  jmp qword ptr [rip + 0x3d7e]
; owner 0x11582 atdms.dll!DMS_SIMBEAD import thunk
00011582  ff 25 80 3d 00 00  jmp qword ptr [rip + 0x3d80]
; owner 0x11588 atdms.dll!DMS_STRETN import thunk
00011588  ff 25 82 3d 00 00  jmp qword ptr [rip + 0x3d82]
; owner 0x11594 atdms.dll!DMS_STRUPR import thunk
00011594  ff 25 86 3d 00 00  jmp qword ptr [rip + 0x3d86]
; owner 0x1159a atdms.dll!DMS_CSTRLEN import thunk
0001159a  ff 25 88 3d 00 00  jmp qword ptr [rip + 0x3d88]
; owner 0x115a0 atdms.dll!DMS_SET_PRODUCTCODE import thunk
000115a0  ff 25 8a 3d 00 00  jmp qword ptr [rip + 0x3d8a]
; owner 0x115a6 atdms.dll!DMS_CREATE_BUFFER_LIST import thunk
000115a6  ff 25 8c 3d 00 00  jmp qword ptr [rip + 0x3d8c]
; owner 0x115b2 atdms.dll!DMS_SET_BUFFER_NAME import thunk
000115b2  ff 25 90 3d 00 00  jmp qword ptr [rip + 0x3d90]
; owner 0x115b8 atdms.dll!DMS_SET_CURRENT_BUFFER import thunk
000115b8  ff 25 92 3d 00 00  jmp qword ptr [rip + 0x3d92]
; owner 0x115be atdms.dll!DMS_SET_BUFFER_AS_HEADER_BY_INDEX import thunk
000115be  ff 25 94 3d 00 00  jmp qword ptr [rip + 0x3d94]
; owner 0x115c4 atdms.dll!DMS_GETFNC import thunk
000115c4  ff 25 96 3d 00 00  jmp qword ptr [rip + 0x3d96]
; owner 0x115ca atdms.dll!DMS_DOCALL_10 import thunk
000115ca  ff 25 98 3d 00 00  jmp qword ptr [rip + 0x3d98]
; owner 0x115d0 zeshs.dll!SHS_FIPOLM import thunk
000115d0  ff 25 f2 46 00 00  jmp qword ptr [rip + 0x46f2]
; owner 0x115e2 zereport.dll!ZREP_REPBLK import thunk
000115e2  ff 25 a8 46 00 00  jmp qword ptr [rip + 0x46a8]
; owner 0x115ee zereport.dll!ZREP_CENTER import thunk
000115ee  ff 25 b4 46 00 00  jmp qword ptr [rip + 0x46b4]
; owner 0x115f4 zereport.dll!ZREP_PLOGO import thunk
000115f4  ff 25 a6 46 00 00  jmp qword ptr [rip + 0x46a6]
; owner 0x11600 pputil.dll!PPUTL_PPFUNC import thunk
00011600  ff 25 1a 46 00 00  jmp qword ptr [rip + 0x461a]
; owner 0x11642 ppbase.dll!PPBASE_WATS01 import thunk
00011642  ff 25 b8 3f 00 00  jmp qword ptr [rip + 0x3fb8]
; owner 0x11648 ppbase.dll!PPBASE_GM11 import thunk
00011648  ff 25 aa 3f 00 00  jmp qword ptr [rip + 0x3faa]
; owner 0x1164e ppbase.dll!PPBASE_MUVL02 import thunk
0001164e  ff 25 9c 3f 00 00  jmp qword ptr [rip + 0x3f9c]
; owner 0x11654 ppbase.dll!PPBASE_HRFIGI import thunk
00011654  ff 25 8e 3f 00 00  jmp qword ptr [rip + 0x3f8e]
; owner 0x1165a ppbase.dll!PPBASE_IDLINT import thunk
0001165a  ff 25 80 3f 00 00  jmp qword ptr [rip + 0x3f80]
; owner 0x11660 ppbase.dll!PPBASE_HCS01I import thunk
00011660  ff 25 72 3f 00 00  jmp qword ptr [rip + 0x3f72]
; owner 0x11666 ppbase.dll!PPBASE_GM05I import thunk
00011666  ff 25 64 3f 00 00  jmp qword ptr [rip + 0x3f64]
; owner 0x1166c ppbase.dll!PPBASE_GM11M import thunk
0001166c  ff 25 56 3f 00 00  jmp qword ptr [rip + 0x3f56]
; owner 0x11672 ppbase.dll!PPBASE_GM25II import thunk
00011672  ff 25 48 3f 00 00  jmp qword ptr [rip + 0x3f48]
; owner 0x11678 ppbase.dll!PPBASE_GM05AI import thunk
00011678  ff 25 3a 3f 00 00  jmp qword ptr [rip + 0x3f3a]
; owner 0x11690 ppbase.dll!PPBASE_ES15B1 import thunk
00011690  ff 25 fa 3e 00 00  jmp qword ptr [rip + 0x3efa]
; owner 0x11696 ppbase.dll!PPBASE_ES15B2 import thunk
00011696  ff 25 ec 3e 00 00  jmp qword ptr [rip + 0x3eec]
; owner 0x1169c ppbase.dll!PPBASE_ES15B3 import thunk
0001169c  ff 25 de 3e 00 00  jmp qword ptr [rip + 0x3ede]
; owner 0x116a2 ppbase.dll!PPBASE_ES15B4 import thunk
000116a2  ff 25 f8 3e 00 00  jmp qword ptr [rip + 0x3ef8]
; owner 0x116a8 ppbase.dll!PPBASE_ES15B5 import thunk
000116a8  ff 25 fa 3e 00 00  jmp qword ptr [rip + 0x3efa]
; owner 0x116ba ppuser.dll!PPUSER_PHCCIU import thunk
000116ba  ff 25 50 45 00 00  jmp qword ptr [rip + 0x4550]
; owner 0x116c0 ppuser.dll!PPUSER_PHCLCU import thunk
000116c0  ff 25 42 45 00 00  jmp qword ptr [rip + 0x4542]
; owner 0x116c6 ppeosi.dll!PPESI_ES02 import thunk
000116c6  ff 25 64 40 00 00  jmp qword ptr [rip + 0x4064]
; owner 0x116cc ppeosi.dll!PPESI_ES04 import thunk
000116cc  ff 25 66 40 00 00  jmp qword ptr [rip + 0x4066]
; owner 0x116d2 ppeosi.dll!PPESI_ES19A import thunk
000116d2  ff 25 68 40 00 00  jmp qword ptr [rip + 0x4068]
; owner 0x116d8 ppeosi.dll!PPESI_ES06SA import thunk
000116d8  ff 25 ca 40 00 00  jmp qword ptr [rip + 0x40ca]
; owner 0x116de ppeosi.dll!PPESI_ES13A import thunk
000116de  ff 25 cc 40 00 00  jmp qword ptr [rip + 0x40cc]
; owner 0x116e4 ppeosi.dll!PPESI_ES36I import thunk
000116e4  ff 25 ce 40 00 00  jmp qword ptr [rip + 0x40ce]
; owner 0x116ea ppeosi.dll!PPESI_ES32A import thunk
000116ea  ff 25 d0 40 00 00  jmp qword ptr [rip + 0x40d0]
; owner 0x116f0 ppeosi.dll!PPESI_ES06A import thunk
000116f0  ff 25 82 3f 00 00  jmp qword ptr [rip + 0x3f82]
; owner 0x116f6 ppeosi.dll!PPESI_ESR02I import thunk
000116f6  ff 25 dc 40 00 00  jmp qword ptr [rip + 0x40dc]
; owner 0x116fc ppeosi.dll!PPESI_ES19 import thunk
000116fc  ff 25 ce 40 00 00  jmp qword ptr [rip + 0x40ce]
; owner 0x11702 ppeosi.dll!PPESI_ES36VI import thunk
00011702  ff 25 c0 40 00 00  jmp qword ptr [rip + 0x40c0]
; owner 0x11708 ppeosi.dll!PPESI_ES24I import thunk
00011708  ff 25 5a 40 00 00  jmp qword ptr [rip + 0x405a]
; owner 0x1170e ppeosi.dll!PPESI_ES17 import thunk
0001170e  ff 25 4c 40 00 00  jmp qword ptr [rip + 0x404c]
; owner 0x11714 ppeosi.dll!PPESI_ES30A import thunk
00011714  ff 25 3e 40 00 00  jmp qword ptr [rip + 0x403e]
; owner 0x1171a ppeosi.dll!PPESI_ES21 import thunk
0001171a  ff 25 30 40 00 00  jmp qword ptr [rip + 0x4030]
; owner 0x11720 ppeosi.dll!PPESI_ES32 import thunk
00011720  ff 25 22 40 00 00  jmp qword ptr [rip + 0x4022]
; owner 0x11726 ppeosi.dll!PPESI_ESR05I import thunk
00011726  ff 25 f4 3f 00 00  jmp qword ptr [rip + 0x3ff4]
; owner 0x1172c ppeosi.dll!PPESI_HYSPRI import thunk
0001172c  ff 25 e6 3f 00 00  jmp qword ptr [rip + 0x3fe6]
; owner 0x11732 ppeosi.dll!PPESI_ESR08I import thunk
00011732  ff 25 d8 3f 00 00  jmp qword ptr [rip + 0x3fd8]
; owner 0x11738 ppeosi.dll!PPESI_ES13 import thunk
00011738  ff 25 ca 3f 00 00  jmp qword ptr [rip + 0x3fca]
; owner 0x1173e ppeosi.dll!PPESI_ESR04I import thunk
0001173e  ff 25 bc 3f 00 00  jmp qword ptr [rip + 0x3fbc]
; owner 0x11744 ppeosi.dll!PPESI_ES04A import thunk
00011744  ff 25 ae 3f 00 00  jmp qword ptr [rip + 0x3fae]
; owner 0x1174a ppeosi.dll!PPESI_ESR03I import thunk
0001174a  ff 25 a0 3f 00 00  jmp qword ptr [rip + 0x3fa0]
; owner 0x11750 ppeosi.dll!PPESI_ESPR78AI import thunk
00011750  ff 25 92 3f 00 00  jmp qword ptr [rip + 0x3f92]
; owner 0x11756 ppeosi.dll!PPESI_ES09I import thunk
00011756  ff 25 3c 40 00 00  jmp qword ptr [rip + 0x403c]
; owner 0x1175c ppeosi.dll!PPESI_HYSSRKI import thunk
0001175c  ff 25 76 3f 00 00  jmp qword ptr [rip + 0x3f76]
; owner 0x11762 ppeosi.dll!PPESI_ES35I import thunk
00011762  ff 25 68 3f 00 00  jmp qword ptr [rip + 0x3f68]
; owner 0x11768 ppeosi.dll!PPESI_ES04WA import thunk
00011768  ff 25 5a 3f 00 00  jmp qword ptr [rip + 0x3f5a]
; owner 0x1176e ppeosi.dll!PPESI_ESCPAI import thunk
0001176e  ff 25 4c 3f 00 00  jmp qword ptr [rip + 0x3f4c]
; owner 0x11774 ppeosi.dll!PPESI_ES35VTI import thunk
00011774  ff 25 3e 3f 00 00  jmp qword ptr [rip + 0x3f3e]
; owner 0x1177a ppeosi.dll!PPESI_ESPR78I import thunk
0001177a  ff 25 30 3f 00 00  jmp qword ptr [rip + 0x3f30]
; owner 0x11780 ppeosi.dll!PPESI_ES11 import thunk
00011780  ff 25 22 3f 00 00  jmp qword ptr [rip + 0x3f22]
; owner 0x11786 ppeosi.dll!PPESI_ESR07I import thunk
00011786  ff 25 14 3f 00 00  jmp qword ptr [rip + 0x3f14]
; owner 0x1178c ppeosi.dll!PPESI_ES14 import thunk
0001178c  ff 25 06 3f 00 00  jmp qword ptr [rip + 0x3f06]
; owner 0x11792 ppeosi.dll!PPESI_ES04SA import thunk
00011792  ff 25 f8 3e 00 00  jmp qword ptr [rip + 0x3ef8]
; owner 0x11798 ppeosi.dll!PPESI_ES06S import thunk
00011798  ff 25 ea 3e 00 00  jmp qword ptr [rip + 0x3eea]
; owner 0x1179e ppeosi.dll!PPESI_ES30 import thunk
0001179e  ff 25 dc 3e 00 00  jmp qword ptr [rip + 0x3edc]
; owner 0x117a4 ppeosi.dll!PPESI_ES11A import thunk
000117a4  ff 25 f6 3f 00 00  jmp qword ptr [rip + 0x3ff6]
; owner 0x117aa ppeosi.dll!PPESI_ES21A import thunk
000117aa  ff 25 e0 3f 00 00  jmp qword ptr [rip + 0x3fe0]
; owner 0x117b0 ppeosi.dll!PPESI_ES02A import thunk
000117b0  ff 25 d2 3f 00 00  jmp qword ptr [rip + 0x3fd2]
; owner 0x117b6 ppeosi.dll!PPESI_ES4ML import thunk
000117b6  ff 25 c4 3f 00 00  jmp qword ptr [rip + 0x3fc4]
; owner 0x117bc ppeosi.dll!PPESI_ES04W import thunk
000117bc  ff 25 b6 3f 00 00  jmp qword ptr [rip + 0x3fb6]
; owner 0x117c2 ppeosi.dll!PPESI_ES4MLA import thunk
000117c2  ff 25 a8 3f 00 00  jmp qword ptr [rip + 0x3fa8]
; owner 0x117c8 ppeosi.dll!PPESI_ES06 import thunk
000117c8  ff 25 5a 3f 00 00  jmp qword ptr [rip + 0x3f5a]
; owner 0x117ce ppeosi.dll!PPESI_ESR06I import thunk
000117ce  ff 25 0c 3f 00 00  jmp qword ptr [rip + 0x3f0c]
; owner 0x117d4 ppeosi.dll!PPESI_ES04S import thunk
000117d4  ff 25 86 3e 00 00  jmp qword ptr [rip + 0x3e86]
; owner 0x117da ppeosi.dll!PPESI_ESR01I import thunk
000117da  ff 25 88 3e 00 00  jmp qword ptr [rip + 0x3e88]
; owner 0x117e0 ppeosi.dll!PPESI_ES35VI import thunk
000117e0  ff 25 8a 3e 00 00  jmp qword ptr [rip + 0x3e8a]
; owner 0x117e6 ppeosi.dll!PPESI_ES141 import thunk
000117e6  ff 25 f4 3f 00 00  jmp qword ptr [rip + 0x3ff4]
; owner 0x117ec ppthermoi.dll!PPTHI_PS003 import thunk
000117ec  ff 25 26 43 00 00  jmp qword ptr [rip + 0x4326]
; owner 0x117f2 ppthermoi.dll!PPTHI_DHL302 import thunk
000117f2  ff 25 18 43 00 00  jmp qword ptr [rip + 0x4318]
; owner 0x117f8 ppthermoi.dll!PPTHI_HL003 import thunk
000117f8  ff 25 0a 43 00 00  jmp qword ptr [rip + 0x430a]
; owner 0x117fe ppthermoi.dll!PPTHI_HL002 import thunk
000117fe  ff 25 24 43 00 00  jmp qword ptr [rip + 0x4324]
; owner 0x11804 ppthermoi.dll!PPTHI_HS002I import thunk
00011804  ff 25 56 43 00 00  jmp qword ptr [rip + 0x4356]
; owner 0x1180a ppthermoi.dll!PPTHI_VS001I import thunk
0001180a  ff 25 58 43 00 00  jmp qword ptr [rip + 0x4358]
; owner 0x11810 ppthermoi.dll!PPTHI_VL010I import thunk
00011810  ff 25 5a 43 00 00  jmp qword ptr [rip + 0x435a]
; owner 0x11816 ppthermoi.dll!PPTHI_VLQUAI import thunk
00011816  ff 25 5c 43 00 00  jmp qword ptr [rip + 0x435c]
; owner 0x1181c ppthermoi.dll!PPTHI_VL004I import thunk
0001181c  ff 25 fe 42 00 00  jmp qword ptr [rip + 0x42fe]
; owner 0x11822 ppthermoi.dll!PPTHI_HRFLQI import thunk
00011822  ff 25 08 43 00 00  jmp qword ptr [rip + 0x4308]
; owner 0x11828 ppthermoi.dll!PPTHI_DHV01I import thunk
00011828  ff 25 0a 43 00 00  jmp qword ptr [rip + 0x430a]
; owner 0x1182e ppthermoi.dll!PPTHI_PL001I import thunk
0001182e  ff 25 0c 43 00 00  jmp qword ptr [rip + 0x430c]
; owner 0x11834 ppthermoi.dll!PPTHI_VL208I import thunk
00011834  ff 25 0e 43 00 00  jmp qword ptr [rip + 0x430e]
; owner 0x1183a ppthermoi.dll!PPTHI_PHL004 import thunk
0001183a  ff 25 10 43 00 00  jmp qword ptr [rip + 0x4310]
; owner 0x11840 ppthermoi.dll!PPTHI_VPM03 import thunk
00011840  ff 25 12 43 00 00  jmp qword ptr [rip + 0x4312]
; owner 0x11846 ppthermoi.dll!PPTHI_VL006 import thunk
00011846  ff 25 34 43 00 00  jmp qword ptr [rip + 0x4334]
; owner 0x1184c ppgammai.dll!PPGMI_GM041 import thunk
0001184c  ff 25 9e 3f 00 00  jmp qword ptr [rip + 0x3f9e]
; owner 0x11852 ppgammai.dll!PPGMI_GM07 import thunk
00011852  ff 25 f0 3f 00 00  jmp qword ptr [rip + 0x3ff0]
; owner 0x11858 ppgammai.dll!PPGMI_GM15 import thunk
00011858  ff 25 e2 3f 00 00  jmp qword ptr [rip + 0x3fe2]
; owner 0x1185e ppgammai.dll!PPGMI_GM13G import thunk
0001185e  ff 25 d4 3f 00 00  jmp qword ptr [rip + 0x3fd4]
; owner 0x11864 ppgammai.dll!PPGMI_GM02 import thunk
00011864  ff 25 c6 3f 00 00  jmp qword ptr [rip + 0x3fc6]
; owner 0x1186a ppgammai.dll!PPGMI_GM03I import thunk
0001186a  ff 25 b8 3f 00 00  jmp qword ptr [rip + 0x3fb8]
; owner 0x11870 ppgammai.dll!PPGMI_GM11VT import thunk
00011870  ff 25 aa 3f 00 00  jmp qword ptr [rip + 0x3faa]
; owner 0x11876 ppgammai.dll!PPGMI_GM13L import thunk
00011876  ff 25 9c 3f 00 00  jmp qword ptr [rip + 0x3f9c]
; owner 0x1187c ppgammai.dll!PPGMI_CSMOSI import thunk
0001187c  ff 25 8e 3f 00 00  jmp qword ptr [rip + 0x3f8e]
; owner 0x11882 ppgammai.dll!PPGMI_GM23I import thunk
00011882  ff 25 80 3f 00 00  jmp qword ptr [rip + 0x3f80]
; owner 0x11888 ppgammai.dll!PPGMI_GM11PS import thunk
00011888  ff 25 72 3f 00 00  jmp qword ptr [rip + 0x3f72]
; owner 0x1188e ppgammai.dll!PPGMI_GM20I import thunk
0001188e  ff 25 64 3f 00 00  jmp qword ptr [rip + 0x3f64]
; owner 0x11894 pptabpolyi.dll!PPTBI_HIGTB import thunk
00011894  ff 25 d6 41 00 00  jmp qword ptr [rip + 0x41d6]
; owner 0x1189a pptabpolyi.dll!PPTBI_VSTB import thunk
0001189a  ff 25 d8 41 00 00  jmp qword ptr [rip + 0x41d8]
; owner 0x118a0 pptabpolyi.dll!PPTBI_HLTB import thunk
000118a0  ff 25 da 41 00 00  jmp qword ptr [rip + 0x41da]
; owner 0x118a6 pptabpolyi.dll!PPTBI_VLTB import thunk
000118a6  ff 25 14 42 00 00  jmp qword ptr [rip + 0x4214]
; owner 0x118ac pptabpolyi.dll!PPTBI_DSVTB import thunk
000118ac  ff 25 26 42 00 00  jmp qword ptr [rip + 0x4226]
; owner 0x118b2 pptabpolyi.dll!PPTBI_DSLTB import thunk
000118b2  ff 25 18 42 00 00  jmp qword ptr [rip + 0x4218]
; owner 0x118b8 pptabpolyi.dll!PPTBI_PHVTB import thunk
000118b8  ff 25 fa 41 00 00  jmp qword ptr [rip + 0x41fa]
; owner 0x118be pptabpolyi.dll!PPTBI_PHLTB import thunk
000118be  ff 25 ec 41 00 00  jmp qword ptr [rip + 0x41ec]
; owner 0x118c4 pptabpolyi.dll!PPTBI_HVTB import thunk
000118c4  ff 25 de 41 00 00  jmp qword ptr [rip + 0x41de]
; owner 0x118ca pptabpolyi.dll!PPTBI_DHVLTB import thunk
000118ca  ff 25 d0 41 00 00  jmp qword ptr [rip + 0x41d0]
; owner 0x118d0 pptabpolyi.dll!PPTBI_DHLTB import thunk
000118d0  ff 25 c2 41 00 00  jmp qword ptr [rip + 0x41c2]
; owner 0x118d6 pptabpolyi.dll!PPTBI_DHLSTB import thunk
000118d6  ff 25 b4 41 00 00  jmp qword ptr [rip + 0x41b4]
; owner 0x118dc pptabpolyi.dll!PPTBI_DHVSTB import thunk
000118dc  ff 25 a6 41 00 00  jmp qword ptr [rip + 0x41a6]
; owner 0x118e2 pptabpolyi.dll!PPTBI_DGVTB import thunk
000118e2  ff 25 68 41 00 00  jmp qword ptr [rip + 0x4168]
; owner 0x118e8 pptabpolyi.dll!PPTBI_DGSTB import thunk
000118e8  ff 25 7a 41 00 00  jmp qword ptr [rip + 0x417a]
; owner 0x118ee pptabpolyi.dll!PPTBI_SLTB import thunk
000118ee  ff 25 ec 41 00 00  jmp qword ptr [rip + 0x41ec]
; owner 0x118f4 pptabpolyi.dll!PPTBI_PLTB import thunk
000118f4  ff 25 ce 41 00 00  jmp qword ptr [rip + 0x41ce]
; owner 0x118fa pptabpolyi.dll!PPTBI_MUVTB import thunk
000118fa  ff 25 60 41 00 00  jmp qword ptr [rip + 0x4160]
; owner 0x11900 pptabpolyi.dll!PPTBI_MULTB import thunk
00011900  ff 25 52 41 00 00  jmp qword ptr [rip + 0x4152]
; owner 0x11906 pptabpolyi.dll!PPTBI_KVLTB import thunk
00011906  ff 25 dc 41 00 00  jmp qword ptr [rip + 0x41dc]
; owner 0x1190c pptabpolyi.dll!PPTBI_DHSTB import thunk
0001190c  ff 25 36 41 00 00  jmp qword ptr [rip + 0x4136]
; owner 0x11912 pptabpolyi.dll!PPTBI_SVTB import thunk
00011912  ff 25 28 41 00 00  jmp qword ptr [rip + 0x4128]
; owner 0x11918 pptabpolyi.dll!PPTBI_PHVMTB import thunk
00011918  ff 25 1a 41 00 00  jmp qword ptr [rip + 0x411a]
; owner 0x1191e pptabpolyi.dll!PPTBI_GVTB import thunk
0001191e  ff 25 0c 41 00 00  jmp qword ptr [rip + 0x410c]
; owner 0x11924 pptabpolyi.dll!PPTBI_KLLTB import thunk
00011924  ff 25 fe 40 00 00  jmp qword ptr [rip + 0x40fe]
; owner 0x1192a pptabpolyi.dll!PPTBI_HNRYTB import thunk
0001192a  ff 25 f0 40 00 00  jmp qword ptr [rip + 0x40f0]
; owner 0x11930 pptabpolyi.dll!PPTBI_DSSTB import thunk
00011930  ff 25 e2 40 00 00  jmp qword ptr [rip + 0x40e2]
; owner 0x11936 pptabpolyi.dll!PPTBI_PHSTB import thunk
00011936  ff 25 d4 40 00 00  jmp qword ptr [rip + 0x40d4]
; owner 0x1193c pptabpolyi.dll!PPTBI_PHLMTB import thunk
0001193c  ff 25 c6 40 00 00  jmp qword ptr [rip + 0x40c6]
; owner 0x11942 pptabpolyi.dll!PPTBI_GLTB import thunk
00011942  ff 25 b8 40 00 00  jmp qword ptr [rip + 0x40b8]
; owner 0x11948 pptabpolyi.dll!PPTBI_HSTB import thunk
00011948  ff 25 aa 40 00 00  jmp qword ptr [rip + 0x40aa]
; owner 0x1194e pptabpolyi.dll!PPTBI_PSTB import thunk
0001194e  ff 25 9c 40 00 00  jmp qword ptr [rip + 0x409c]
; owner 0x11954 pptabpolyi.dll!PPTBI_DGLTB import thunk
00011954  ff 25 8e 40 00 00  jmp qword ptr [rip + 0x408e]
; owner 0x1195a pptabpolyi.dll!PPTBI_SSTB import thunk
0001195a  ff 25 80 40 00 00  jmp qword ptr [rip + 0x4080]
; owner 0x11960 pptabpolyi.dll!PPTBI_VVTB import thunk
00011960  ff 25 72 40 00 00  jmp qword ptr [rip + 0x4072]
; owner 0x11966 pptabpolyi.dll!PPTBI_GSTB import thunk
00011966  ff 25 64 40 00 00  jmp qword ptr [rip + 0x4064]
; owner 0x1196c pptabpolyi.dll!PPTBI_DHVTB import thunk
0001196c  ff 25 56 40 00 00  jmp qword ptr [rip + 0x4056]
; owner 0x11972 pptransporti.dll!PPTXI_KVLW1 import thunk
00011972  ff 25 28 42 00 00  jmp qword ptr [rip + 0x4228]
; owner 0x11978 pptransporti.dll!PPTXI_MUASPI import thunk
00011978  ff 25 1a 42 00 00  jmp qword ptr [rip + 0x421a]
; owner 0x1197e pptransporti.dll!PPTXI_KV001I import thunk
0001197e  ff 25 0c 42 00 00  jmp qword ptr [rip + 0x420c]
; owner 0x11984 pptransporti.dll!PPTXI_MUL01I import thunk
00011984  ff 25 1e 42 00 00  jmp qword ptr [rip + 0x421e]
; owner 0x1198a pptransporti.dll!PPTXI_KL002I import thunk
0001198a  ff 25 20 42 00 00  jmp qword ptr [rip + 0x4220]
; owner 0x11990 pptransporti.dll!PPTXI_MUV01I import thunk
00011990  ff 25 22 42 00 00  jmp qword ptr [rip + 0x4222]
; owner 0x11996 pptransporti.dll!PPTXI_MULQUI import thunk
00011996  ff 25 5c 42 00 00  jmp qword ptr [rip + 0x425c]
; owner 0x1199c pptransporti.dll!PPTXI_SIG02I import thunk
0001199c  ff 25 1e 42 00 00  jmp qword ptr [rip + 0x421e]
; owner 0x119a2 pptransporti.dll!PPTXI_MUL207 import thunk
000119a2  ff 25 20 42 00 00  jmp qword ptr [rip + 0x4220]
; owner 0x119a8 pptransporti.dll!PPTXI_KL204I import thunk
000119a8  ff 25 22 42 00 00  jmp qword ptr [rip + 0x4222]
; owner 0x119ae pptransporti.dll!PPTXI_MUVLW1 import thunk
000119ae  ff 25 24 42 00 00  jmp qword ptr [rip + 0x4224]
; owner 0x119b4 pptransporti.dll!PPTXI_MUVLW2 import thunk
000119b4  ff 25 26 42 00 00  jmp qword ptr [rip + 0x4226]
; owner 0x119ba pptransporti.dll!PPTXI_MUVL05 import thunk
000119ba  ff 25 28 42 00 00  jmp qword ptr [rip + 0x4228]
; owner 0x119c0 pptransporti.dll!PPTXI_MUV006 import thunk
000119c0  ff 25 2a 42 00 00  jmp qword ptr [rip + 0x422a]
; owner 0x119c6 ppthermo.dll!PPTH_SLXIN0 import thunk
000119c6  ff 25 2c 41 00 00  jmp qword ptr [rip + 0x412c]
; owner 0x119cc pptabpoly.dll!PPTB_TPUNPK import thunk
000119cc  ff 25 e6 3f 00 00  jmp qword ptr [rip + 0x3fe6]
; owner 0x119d2 ppstub.dll!PPSTUB_VAQ003 import thunk
000119d2  ff 25 68 3f 00 00  jmp qword ptr [rip + 0x3f68]
; owner 0x119d8 ppstub.dll!PPSTUB_GM081E import thunk
000119d8  ff 25 6a 3f 00 00  jmp qword ptr [rip + 0x3f6a]
; owner 0x119de ppstub.dll!PPSTUB_TM001I import thunk
000119de  ff 25 6c 3f 00 00  jmp qword ptr [rip + 0x3f6c]
; owner 0x119e4 ppstub.dll!PPSTUB_BK10IN import thunk
000119e4  ff 25 6e 3f 00 00  jmp qword ptr [rip + 0x3f6e]
; owner 0x119ea ppstub.dll!PPSTUB_CPP01I import thunk
000119ea  ff 25 70 3f 00 00  jmp qword ptr [rip + 0x3f70]
; owner 0x119f0 ppstub.dll!PPSTUB_FH01I import thunk
000119f0  ff 25 72 3f 00 00  jmp qword ptr [rip + 0x3f72]
; owner 0x119f6 ppstub.dll!PPSTUB_HLP01I import thunk
000119f6  ff 25 74 3f 00 00  jmp qword ptr [rip + 0x3f74]
; owner 0x119fc ppstub.dll!PPSTUB_GLP01I import thunk
000119fc  ff 25 76 3f 00 00  jmp qword ptr [rip + 0x3f76]
; owner 0x11a02 ppstub.dll!PPSTUB_MUASP0 import thunk
00011a02  ff 25 78 3f 00 00  jmp qword ptr [rip + 0x3f78]
; owner 0x11a08 ppstub.dll!PPSTUB_ESPSLI import thunk
00011a08  ff 25 7a 3f 00 00  jmp qword ptr [rip + 0x3f7a]
; owner 0x11a0e ppstub.dll!PPSTUB_CM05SI import thunk
00011a0e  ff 25 7c 3f 00 00  jmp qword ptr [rip + 0x3f7c]
; owner 0x11a14 ppstub.dll!PPSTUB_KLVKI import thunk
00011a14  ff 25 7e 3f 00 00  jmp qword ptr [rip + 0x3f7e]
; owner 0x11a1a ppstub.dll!PPSTUB_ESP01I import thunk
00011a1a  ff 25 80 3f 00 00  jmp qword ptr [rip + 0x3f80]
; owner 0x11a20 ppstub.dll!PPSTUB_GM18 import thunk
00011a20  ff 25 82 3f 00 00  jmp qword ptr [rip + 0x3f82]
; owner 0x11a26 ppstub.dll!PPSTUB_VLP01I import thunk
00011a26  ff 25 0c 3f 00 00  jmp qword ptr [rip + 0x3f0c]
; owner 0x11a2c ppstub.dll!PPSTUB_ESPCSI import thunk
00011a2c  ff 25 fe 3e 00 00  jmp qword ptr [rip + 0x3efe]
; owner 0x11a32 ppstub.dll!PPSTUB_ESPSAHI import thunk
00011a32  ff 25 d8 3e 00 00  jmp qword ptr [rip + 0x3ed8]
; owner 0x11a38 ppstub.dll!PPSTUB_EYRIN0 import thunk
00011a38  ff 25 5a 3e 00 00  jmp qword ptr [rip + 0x3e5a]
; owner 0x11a3e ppstub.dll!PPSTUB_MUPOL0 import thunk
00011a3e  ff 25 4c 3e 00 00  jmp qword ptr [rip + 0x3e4c]
; owner 0x11a44 ppstub.dll!PPSTUB_GM081 import thunk
00011a44  ff 25 de 3e 00 00  jmp qword ptr [rip + 0x3ede]
; owner 0x11a4a ppstub.dll!PPSTUB_VLP02I import thunk
00011a4a  ff 25 88 3e 00 00  jmp qword ptr [rip + 0x3e88]
; owner 0x11a50 ppstub.dll!PPSTUB_ESSFTI import thunk
00011a50  ff 25 72 3e 00 00  jmp qword ptr [rip + 0x3e72]
; owner 0x11a56 ppstub.dll!PPSTUB_GM05SR import thunk
00011a56  ff 25 74 3e 00 00  jmp qword ptr [rip + 0x3e74]
; owner 0x11a5c ppstub.dll!PPSTUB_GM05SI import thunk
00011a5c  ff 25 be 3e 00 00  jmp qword ptr [rip + 0x3ebe]
; owner 0x11a62 ppstub.dll!PPSTUB_GM05RK import thunk
00011a62  ff 25 20 3e 00 00  jmp qword ptr [rip + 0x3e20]
; owner 0x11a68 ppstub.dll!PPSTUB_ESPSAI import thunk
00011a68  ff 25 32 3e 00 00  jmp qword ptr [rip + 0x3e32]
; owner 0x11a6e ppstub.dll!PPSTUB_GCHEMI import thunk
00011a6e  ff 25 34 3e 00 00  jmp qword ptr [rip + 0x3e34]
; owner 0x11a74 ppstub.dll!PPSTUB_GM5ASI import thunk
00011a74  ff 25 36 3e 00 00  jmp qword ptr [rip + 0x3e36]
; owner 0x11a7a ppstub.dll!PPSTUB_GM18A import thunk
00011a7a  ff 25 38 3e 00 00  jmp qword ptr [rip + 0x3e38]
; owner 0x11a80 ppstub.dll!PPSTUB_HSEN0I import thunk
00011a80  ff 25 3a 3e 00 00  jmp qword ptr [rip + 0x3e3a]
; owner 0x11a86 ppstub.dll!PPSTUB_TG001I import thunk
00011a86  ff 25 54 3e 00 00  jmp qword ptr [rip + 0x3e54]
; owner 0x11a8c ppstub.dll!PPSTUB_HMU01I import thunk
00011a8c  ff 25 56 3e 00 00  jmp qword ptr [rip + 0x3e56]
; owner 0x11a92 ppstub.dll!PPSTUB_MULMH0 import thunk
00011a92  ff 25 58 3e 00 00  jmp qword ptr [rip + 0x3e58]
; owner 0x11a98 ppstub.dll!PPSTUB_GMSA81 import thunk
00011a98  ff 25 5a 3e 00 00  jmp qword ptr [rip + 0x3e5a]
; owner 0x11a9e ppstub.dll!PPSTUB_VL203 import thunk
00011a9e  ff 25 5c 3e 00 00  jmp qword ptr [rip + 0x3e5c]
; owner 0x11aa4 ppstub.dll!PPSTUB_INIT_IXWRAP import thunk
00011aa4  ff 25 5e 3e 00 00  jmp qword ptr [rip + 0x3e5e]
; owner 0x11ab0 zeusermod.dll!UMOD_PPCHKU import thunk
00011ab0  ff 25 22 42 00 00  jmp qword ptr [rip + 0x4222]
; owner 0x11ab6 zeusermod.dll!UMOD_USRVRN import thunk
00011ab6  ff 25 24 42 00 00  jmp qword ptr [rip + 0x4224]
; owner 0x11abc atdms2.dll!DMS_NEWROY import thunk
00011abc  ff 25 86 3a 00 00  jmp qword ptr [rip + 0x3a86]
; owner 0x11ac2 atdms2.dll!DMS_FPRSLV import thunk
00011ac2  ff 25 78 3a 00 00  jmp qword ptr [rip + 0x3a78]
; owner 0x11ac8 aphier.dll!APHIERSTK_INIT_F import thunk
00011ac8  ff 25 32 36 00 00  jmp qword ptr [rip + 0x3632]
; owner 0x11ace aphier.dll!APHIER_GETTOPCNTR_F import thunk
00011ace  ff 25 24 36 00 00  jmp qword ptr [rip + 0x3624]
; owner 0x11ad4 aphier.dll!APHIERSTK_PUSH_F import thunk
00011ad4  ff 25 16 36 00 00  jmp qword ptr [rip + 0x3616]
; owner 0x11ada rtmalloc.dll!RTO_MALLOC_INIT import thunk
00011ada  ff 25 90 41 00 00  jmp qword ptr [rip + 0x4190]
; owner 0x11ae0 ppeleci.dll!PPELCI_GM051E import thunk
00011ae0  ff 25 6a 3b 00 00  jmp qword ptr [rip + 0x3b6a]
; owner 0x11ae6 pphysysprop.dll!PPHYSP_HYSPRPI import thunk
00011ae6  ff 25 6c 3d 00 00  jmp qword ptr [rip + 0x3d6c]
; owner 0x11aec pphysysprop.dll!PPHYSP_GLYCOLI import thunk
00011aec  ff 25 6e 3d 00 00  jmp qword ptr [rip + 0x3d6e]
; owner 0x11af2 ppedl.dll!PPEDL_ESESFI import thunk
00011af2  ff 25 48 3b 00 00  jmp qword ptr [rip + 0x3b48]
; owner 0x11af8 ppedl.dll!PPEDL_ESELKI import thunk
00011af8  ff 25 2a 3b 00 00  jmp qword ptr [rip + 0x3b2a]
; owner 0x11afe ppedl.dll!PPEDL_EDLPROPI import thunk
00011afe  ff 25 2c 3b 00 00  jmp qword ptr [rip + 0x3b2c]
; owner 0x11b04 ppedl.dll!PPEDL_ESEDLI import thunk
00011b04  ff 25 2e 3b 00 00  jmp qword ptr [rip + 0x3b2e]
; owner 0x11b0a libifcoremd.dll!for_write_int_fmt import thunk
00011b0a  ff 25 60 3a 00 00  jmp qword ptr [rip + 0x3a60]
; owner 0x11b10 libifcoremd.dll!for_write_int_fmt_xmit import thunk
00011b10  ff 25 42 3a 00 00  jmp qword ptr [rip + 0x3a42]
; owner 0x11b16 libifcoremd.dll!for_close import thunk
00011b16  ff 25 44 3a 00 00  jmp qword ptr [rip + 0x3a44]
; owner 0x11b1c libifcoremd.dll!for_cpstr import thunk
00011b1c  ff 25 46 3a 00 00  jmp qword ptr [rip + 0x3a46]
; owner 0x11b24 runtime_11b24
00011b24  48 83 ec 28  sub rsp, 0x28
; owner 0x11b74 runtime_11b74
00011b74  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00011bac  83 3d 7d ee 00 00 00  cmp dword ptr [rip + 0xee7d], 0
00011bb9  c7 05 6d ee 00 00 01 00 00 00  mov dword ptr [rip + 0xee6d], 1
00011bdb  48 8d 15 66 41 00 00  lea rdx, [rip + 0x4166]
00011be2  48 8d 0d 57 41 00 00  lea rcx, [rip + 0x4157]
00011be9  e8 b8 2b 00 00  call 0x1800147a6
00011bfb  48 8d 15 36 41 00 00  lea rdx, [rip + 0x4136]
00011c02  48 8d 0d 1f 41 00 00  lea rcx, [rip + 0x411f]
00011c09  e8 92 2b 00 00  call 0x1800147a0
00011c0e  c7 05 18 ee 00 00 02 00 00 00  mov dword ptr [rip + 0xee18], 2
00011c4f  4c 8b 0d aa 40 00 00  mov r9, qword ptr [rip + 0x40aa]
00011c56  41 ff d1  call r9
00011c59  ff 05 a1 ed 00 00  inc dword ptr [rip + 0xeda1]
; owner 0x11c8c runtime_11c8c
00011c8c  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00011c99  8b 05 61 ed 00 00  mov eax, dword ptr [rip + 0xed61]
00011cb2  89 05 48 ed 00 00  mov dword ptr [rip + 0xed48], eax
00011cc3  83 3d 66 ed 00 00 02  cmp dword ptr [rip + 0xed66], 2
00011cdb  83 25 4e ed 00 00 00  and dword ptr [rip + 0xed4e], 0
; owner 0x11d0c runtime_11d0c
00011d0c  48 8b c4  mov rax, rsp
00011d32  39 15 c8 ec 00 00  cmp dword ptr [rip + 0xecc8], edx
00011d49  48 8b 05 08 5f 00 00  mov rax, qword ptr [rip + 0x5f08]
00011d5a  ff 15 a0 3f 00 00  call qword ptr [rip + 0x3fa0]
00011dbd  48 8b 05 94 5e 00 00  mov rax, qword ptr [rip + 0x5e94]
00011dd1  ff 15 29 3f 00 00  call qword ptr [rip + 0x3f29]
00011df7  48 8b 05 5a 5e 00 00  mov rax, qword ptr [rip + 0x5e5a]
00011e10  ff 15 ea 3e 00 00  call qword ptr [rip + 0x3eea]
; owner 0x11e58 runtime_11e58
00011e58  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
; owner 0x11e98 runtime_11e98
00011e98  40 55  push rbp
00011eaa  ff 15 90 31 00 00  call qword ptr [rip + 0x3190]
00011eb8  ff 15 7a 31 00 00  call qword ptr [rip + 0x317a]
00011ec4  ff 15 66 31 00 00  call qword ptr [rip + 0x3166]
00011ed4  ff 15 4e 31 00 00  call qword ptr [rip + 0x314e]
; owner 0x11f04 runtime_11f04
00011f04  48 89 5c 24 18  mov qword ptr [rsp + 0x18], rbx
00011f11  48 8b 05 e8 c8 00 00  mov rax, qword ptr [rip + 0xc8e8]
00011f30  ff 15 0a 31 00 00  call qword ptr [rip + 0x310a]
00011f3e  ff 15 f4 30 00 00  call qword ptr [rip + 0x30f4]
00011f4a  ff 15 e0 30 00 00  call qword ptr [rip + 0x30e0]
00011f5a  ff 15 c8 30 00 00  call qword ptr [rip + 0x30c8]
00011f94  48 89 05 65 c8 00 00  mov qword ptr [rip + 0xc865], rax
00011fa3  48 89 05 96 c8 00 00  mov qword ptr [rip + 0xc896], rax
; owner 0x11fb0 runtime_11fb0
00011fb0  48 83 ec 28  sub rsp, 0x28
00011fb9  48 83 3d 97 5c 00 00 00  cmp qword ptr [rip + 0x5c97], 0
00011fc3  ff 15 7f 30 00 00  call qword ptr [rip + 0x307f]
; owner 0x11fd4 FUN_180011fd4
00011fd4  48 8d 0d 35 ea 00 00  lea rcx, [rip + 0xea35]
00011fdb  48 ff 25 6e 30 00 00  jmp qword ptr [rip + 0x306e]
; owner 0x11fe4 FUN_180011fe4
00011fe4  48 8d 0d 25 ea 00 00  lea rcx, [rip + 0xea25]
00011feb  e9 92 27 00 00  jmp 0x180014782
; owner 0x11ff0 FUN_180011ff0
00011ff0  48 8d 05 29 ea 00 00  lea rax, [rip + 0xea29]
; owner 0x11ff8 FUN_180011ff8
00011ff8  48 8d 05 29 ea 00 00  lea rax, [rip + 0xea29]
; owner 0x12000 runtime_12000
00012000  48 83 ec 28  sub rsp, 0x28
; owner 0x1201c runtime_1201c
0001201c  48 83 ec 28  sub rsp, 0x28
0001202b  e9 82 27 00 00  jmp 0x1800147b2
; owner 0x120c0 runtime_120c0
000120c0  48 83 ec 28  sub rsp, 0x28
000120e3  f0 48 0f b1 0d 4c e9 00 00  lock cmpxchg qword ptr [rip + 0xe94c], rcx
; owner 0x120fc runtime_120fc
000120fc  48 83 ec 28  sub rsp, 0x28
00012117  e8 96 26 00 00  call 0x1800147b2
00012124  e8 8f 26 00 00  call 0x1800147b8
; owner 0x12130 runtime_12130
00012130  48 83 ec 28  sub rsp, 0x28
; owner 0x12148 runtime_12148
00012148  48 83 ec 28  sub rsp, 0x28
; owner 0x12170 runtime_12170
00012170  48 83 ec 28  sub rsp, 0x28
; owner 0x12188 runtime_12188
00012188  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
000121c0  ff 15 3a 3b 00 00  call qword ptr [rip + 0x3b3a]
000121e3  e9 c4 25 00 00  jmp 0x1800147ac
; owner 0x121e8 runtime_121e8
000121e8  48 83 ec 28  sub rsp, 0x28
000121f5  48 8d 0d 4c e8 00 00  lea rcx, [rip + 0xe84c]
00012200  e9 c5 25 00 00  jmp 0x1800147ca
0001220e  e8 c9 25 00 00  call 0x1800147dc
; owner 0x12218 runtime_12218
00012218  48 83 ec 28  sub rsp, 0x28
; owner 0x1222c runtime_1222c
0001222c  48 83 ec 28  sub rsp, 0x28
00012234  c6 05 05 e8 00 00 01  mov byte ptr [rip + 0xe805], 1
; owner 0x12268 runtime_12268
00012268  40 53  push rbx
0001226e  80 3d cc e7 00 00 00  cmp byte ptr [rip + 0xe7cc], 0
0001228b  48 8d 0d b6 e7 00 00  lea rcx, [rip + 0xe7b6]
00012292  e8 27 25 00 00  call 0x1800147be
0001229b  48 8d 0d be e7 00 00  lea rcx, [rip + 0xe7be]
000122a2  e8 17 25 00 00  call 0x1800147be
000122af  66 0f 6f 05 a9 59 00 00  movdqa xmm0, xmmword ptr [rip + 0x59a9]
000122bb  f3 0f 7f 05 85 e7 00 00  movdqu xmmword ptr [rip + 0xe785], xmm0
000122c3  48 89 05 8e e7 00 00  mov qword ptr [rip + 0xe78e], rax
000122ca  f3 0f 7f 05 8e e7 00 00  movdqu xmmword ptr [rip + 0xe78e], xmm0
000122d2  48 89 05 97 e7 00 00  mov qword ptr [rip + 0xe797], rax
000122d9  c6 05 61 e7 00 00 01  mov byte ptr [rip + 0xe761], 1
; owner 0x122f4 runtime_122f4
000122f4  48 83 ec 18  sub rsp, 0x18
00012300  66 39 05 f9 dc fe ff  cmp word ptr [rip - 0x12307], ax
00012309  48 63 0d 2c dd fe ff  movsxd rcx, dword ptr [rip - 0x122d4]
00012310  48 8d 15 e9 dc fe ff  lea rdx, [rip - 0x12317]
; owner 0x1238c runtime_1238c
0001238c  40 53  push rbx
000123a3  48 87 15 8e e6 00 00  xchg qword ptr [rip + 0xe68e], rdx
; owner 0x123b0 runtime_123b0
000123b0  40 53  push rbx
000123b6  80 3d 83 e6 00 00 00  cmp byte ptr [rip + 0xe683], 0
; owner 0x123dc runtime_123dc
000123dc  40 53  push rbx
000123e2  48 83 3d 5e e6 00 00 ff  cmp qword ptr [rip + 0xe65e], -1
000123ef  e8 dc 23 00 00  call 0x1800147d0
000123f9  48 8d 0d 48 e6 00 00  lea rcx, [rip + 0xe648]
00012400  e8 bf 23 00 00  call 0x1800147c4
; owner 0x12438 runtime_12438
00012438  48 83 ec 28  sub rsp, 0x28
; owner 0x12450 FUN_180012450
00012450  48 8d 05 f1 fc 00 00  lea rax, [rip + 0xfcf1]
; owner 0x12458 FUN_180012458
00012458  83 25 19 e6 00 00 00  and dword ptr [rip + 0xe619], 0
; owner 0x12460 runtime_12460
00012460  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
0001247c  ff 15 0e 2c 00 00  call qword ptr [rip + 0x2c0e]
000124a0  e8 ef 22 00 00  call 0x180014794
000124a9  ff 15 a9 2b 00 00  call qword ptr [rip + 0x2ba9]
000124c3  ff 15 97 2b 00 00  call qword ptr [rip + 0x2b97]
00012504  ff 15 5e 2b 00 00  call qword ptr [rip + 0x2b5e]
00012537  e8 58 22 00 00  call 0x180014794
00012558  ff 15 12 2b 00 00  call qword ptr [rip + 0x2b12]
00012575  ff 15 05 2b 00 00  call qword ptr [rip + 0x2b05]
00012580  ff 15 f2 2a 00 00  call qword ptr [rip + 0x2af2]
; owner 0x125a8 runtime_125a8
000125a8  48 81 ec 98 00 00 00  sub rsp, 0x98
000125ba  e8 d5 21 00 00  call 0x180014794
000125c4  ff 15 be 2a 00 00  call qword ptr [rip + 0x2abe]
; owner 0x125f0 runtime_125f0
000125f0  48 83 ec 28  sub rsp, 0x28
000125f6  ff 15 9c 2a 00 00  call qword ptr [rip + 0x2a9c]
; owner 0x12658 runtime_12658
00012658  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00012699  e8 ea 20 00 00  call 0x180014788
000126a5  e8 e4 20 00 00  call 0x18001478e
000126ad  e8 30 21 00 00  call 0x1800147e2
; owner 0x126b4 runtime_126b4
000126b4  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
000126be  48 8d 1d 3b 79 00 00  lea rbx, [rip + 0x793b]
000126c5  48 8d 3d 34 79 00 00  lea rdi, [rip + 0x7934]
000126d6  ff 15 24 36 00 00  call qword ptr [rip + 0x3624]
; owner 0x126f0 runtime_126f0
000126f0  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
000126fa  48 8d 1d 0f 79 00 00  lea rbx, [rip + 0x790f]
00012701  48 8d 3d 08 79 00 00  lea rdi, [rip + 0x7908]
00012712  ff 15 e8 35 00 00  call qword ptr [rip + 0x35e8]
; owner 0x1272c _guard_check_icall
0001272c  c2 00 00  ret 0
; owner 0x1277c runtime_1277c
0001277c  48 83 ec 28  sub rsp, 0x28
00012780  4c 8d 05 f9 73 00 00  lea r8, [rip + 0x73f9]
0001278a  48 8d 15 ef 73 00 00  lea rdx, [rip + 0x73ef]
0001279c  48 8b 05 75 35 00 00  mov rax, qword ptr [rip + 0x3575]
000127a8  ff d0  call rax
; owner 0x127b0 runtime_127b0
000127b0  48 83 ec 28  sub rsp, 0x28
000127b4  48 8b 05 5d 35 00 00  mov rax, qword ptr [rip + 0x355d]
000127c0  ff d0  call rax
; owner 0x127c8 runtime_127c8
000127c8  48 83 ec 28  sub rsp, 0x28
000127cc  4c 8d 05 ad 73 00 00  lea r8, [rip + 0x73ad]
000127d6  48 8d 15 a3 73 00 00  lea rdx, [rip + 0x73a3]
000127e8  48 8b 05 91 e2 00 00  mov rax, qword ptr [rip + 0xe291]
000127f4  ff 15 06 35 00 00  call qword ptr [rip + 0x3506]
; owner 0x12800 runtime_12800
00012800  48 83 ec 28  sub rsp, 0x28
00012804  48 8b 05 75 e2 00 00  mov rax, qword ptr [rip + 0xe275]
00012810  ff 15 ea 34 00 00  call qword ptr [rip + 0x34ea]
; owner 0x128bc runtime_128bc
000128bc  48 83 ec 28  sub rsp, 0x28
000128c6  48 8d 15 33 72 00 00  lea rdx, [rip + 0x7233]
000128d9  4c 8d 05 a0 72 00 00  lea r8, [rip + 0x72a0]
000128e3  48 8d 05 96 72 00 00  lea rax, [rip + 0x7296]
000128f5  48 8b 05 1c 34 00 00  mov rax, qword ptr [rip + 0x341c]
00012901  ff d0  call rax
; owner 0x12908 runtime_12908
00012908  48 83 ec 28  sub rsp, 0x28
00012912  48 8d 15 e7 71 00 00  lea rdx, [rip + 0x71e7]
00012925  4c 8d 05 54 72 00 00  lea r8, [rip + 0x7254]
0001292f  48 8d 05 4a 72 00 00  lea rax, [rip + 0x724a]
00012941  48 8b 05 38 e1 00 00  mov rax, qword ptr [rip + 0xe138]
0001294d  ff 15 ad 33 00 00  call qword ptr [rip + 0x33ad]
; owner 0x12990 runtime_12990
00012990  48 89 5c 24 10  mov qword ptr [rsp + 0x10], rbx
000129eb  48 83 0d 6d be 00 00 ff  or qword ptr [rip + 0xbe6d], 0xffffffffffffffff
000129f8  48 c7 05 55 be 00 00 00 80 00 00  mov qword ptr [rip + 0xbe55], 0x8000
00012a32  44 8b 05 53 e0 00 00  mov r8d, dword ptr [rip + 0xe053]
00012a3d  44 89 05 48 e0 00 00  mov dword ptr [rip + 0xe048], r8d
00012a46  44 8b 05 3f e0 00 00  mov r8d, dword ptr [rip + 0xe03f]
00012a82  44 89 05 03 e0 00 00  mov dword ptr [rip + 0xe003], r8d
00012ac4  48 8b 05 7d bd 00 00  mov rax, qword ptr [rip + 0xbd7d]
00012ad4  c7 05 72 bd 00 00 01 00 00 00  mov dword ptr [rip + 0xbd72], 1
00012ade  c7 05 6c bd 00 00 02 00 00 00  mov dword ptr [rip + 0xbd6c], 2
00012ae8  48 89 05 59 bd 00 00  mov qword ptr [rip + 0xbd59], rax
00012af9  c7 05 4d bd 00 00 02 00 00 00  mov dword ptr [rip + 0xbd4d], 2
00012b03  48 89 05 3e bd 00 00  mov qword ptr [rip + 0xbd3e], rax
00012b0a  89 1d 44 bd 00 00  mov dword ptr [rip + 0xbd44], ebx
00012b42  8b 05 0c bd 00 00  mov eax, dword ptr [rip + 0xbd0c]
00012b4d  c7 05 f9 bc 00 00 03 00 00 00  mov dword ptr [rip + 0xbcf9], 3
00012b57  89 05 f7 bc 00 00  mov dword ptr [rip + 0xbcf7], eax
00012b66  c7 05 e0 bc 00 00 05 00 00 00  mov dword ptr [rip + 0xbce0], 5
00012b70  89 05 de bc 00 00  mov dword ptr [rip + 0xbcde], eax
00012b7b  48 8b 05 c6 bc 00 00  mov rax, qword ptr [rip + 0xbcc6]
00012b89  48 89 05 b8 bc 00 00  mov qword ptr [rip + 0xbcb8], rax
00012b9f  48 8b 05 a2 bc 00 00  mov rax, qword ptr [rip + 0xbca2]
00012ba6  83 0d a7 bc 00 00 40  or dword ptr [rip + 0xbca7], 0x40
00012bb1  89 1d 99 bc 00 00  mov dword ptr [rip + 0xbc99], ebx
00012bb7  48 89 05 8a bc 00 00  mov qword ptr [rip + 0xbc8a], rax
00012bc0  48 8b 05 81 bc 00 00  mov rax, qword ptr [rip + 0xbc81]
00012bd2  48 89 05 6f bc 00 00  mov qword ptr [rip + 0xbc6f], rax
00012bfc  89 05 86 de 00 00  mov dword ptr [rip + 0xde86], eax
00012c0c  48 23 0d 35 bc 00 00  and rcx, qword ptr [rip + 0xbc35]
00012c13  48 89 0d 2e bc 00 00  mov qword ptr [rip + 0xbc2e], rcx
00012c23  48 89 0d 1e bc 00 00  mov qword ptr [rip + 0xbc1e], rcx
00012c3c  48 0f ba 35 03 bc 00 00 07  btr qword ptr [rip + 0xbc03], 7
; owner 0x12c5c FUN_180012c5c
00012c5c  b8 01 00 00 00  mov eax, 1
; owner 0x12c64 __scrt_is_ucrt_dll_in_use
00012c64  33 c0  xor eax, eax
00012c66  39 05 44 bc 00 00  cmp dword ptr [rip + 0xbc44], eax
; owner 0x14704 KERNEL32.dll!GetModuleHandleA import thunk
00014704  ff 25 16 09 00 00  jmp qword ptr [rip + 0x916]
; owner 0x14782 VCRUNTIME140.dll!__std_type_info_destroy_list import thunk
00014782  ff 25 40 09 00 00  jmp qword ptr [rip + 0x940]
; owner 0x14788 VCRUNTIME140.dll!__current_exception import thunk
00014788  ff 25 52 09 00 00  jmp qword ptr [rip + 0x952]
; owner 0x1478e VCRUNTIME140.dll!__current_exception_context import thunk
0001478e  ff 25 44 09 00 00  jmp qword ptr [rip + 0x944]
; owner 0x14794 VCRUNTIME140.dll!memset import thunk
00014794  ff 25 36 09 00 00  jmp qword ptr [rip + 0x936]
; owner 0x147a0 api-ms-win-crt-runtime-l1-1-0.dll!_initterm import thunk
000147a0  ff 25 d2 09 00 00  jmp qword ptr [rip + 0x9d2]
; owner 0x147a6 api-ms-win-crt-runtime-l1-1-0.dll!_initterm_e import thunk
000147a6  ff 25 d4 09 00 00  jmp qword ptr [rip + 0x9d4]
; owner 0x147ac api-ms-win-crt-runtime-l1-1-0.dll!_seh_filter_dll import thunk
000147ac  ff 25 ae 09 00 00  jmp qword ptr [rip + 0x9ae]
; owner 0x147b2 api-ms-win-crt-runtime-l1-1-0.dll!_configure_narrow_argv import thunk
000147b2  ff 25 88 09 00 00  jmp qword ptr [rip + 0x988]
; owner 0x147b8 api-ms-win-crt-runtime-l1-1-0.dll!_initialize_narrow_environment import thunk
000147b8  ff 25 62 09 00 00  jmp qword ptr [rip + 0x962]
; owner 0x147be api-ms-win-crt-runtime-l1-1-0.dll!_initialize_onexit_table import thunk
000147be  ff 25 64 09 00 00  jmp qword ptr [rip + 0x964]
; owner 0x147c4 api-ms-win-crt-runtime-l1-1-0.dll!_register_onexit_function import thunk
000147c4  ff 25 66 09 00 00  jmp qword ptr [rip + 0x966]
; owner 0x147ca api-ms-win-crt-runtime-l1-1-0.dll!_execute_onexit_table import thunk
000147ca  ff 25 68 09 00 00  jmp qword ptr [rip + 0x968]
; owner 0x147d0 api-ms-win-crt-runtime-l1-1-0.dll!_crt_atexit import thunk
000147d0  ff 25 9a 09 00 00  jmp qword ptr [rip + 0x99a]
; owner 0x147dc api-ms-win-crt-runtime-l1-1-0.dll!_cexit import thunk
000147dc  ff 25 6e 09 00 00  jmp qword ptr [rip + 0x96e]
; owner 0x147e2 api-ms-win-crt-runtime-l1-1-0.dll!terminate import thunk
000147e2  ff 25 70 09 00 00  jmp qword ptr [rip + 0x970]
; owner 0x147e8 api-ms-win-crt-environment-l1-1-0.dll!getenv import thunk
000147e8  ff 25 22 09 00 00  jmp qword ptr [rip + 0x922]
; owner 0x147ee api-ms-win-crt-runtime-l1-1-0.dll!exit import thunk
000147ee  ff 25 74 09 00 00  jmp qword ptr [rip + 0x974]
; owner 0x147f4 api-ms-win-crt-stdio-l1-1-0.dll!__stdio_common_vsprintf import thunk
000147f4  ff 25 a6 09 00 00  jmp qword ptr [rip + 0x9a6]
; owner 0x147fa api-ms-win-crt-string-l1-1-0.dll!strlen import thunk
000147fa  ff 25 b8 09 00 00  jmp qword ptr [rip + 0x9b8]
; owner 0x14800 api-ms-win-crt-string-l1-1-0.dll!strncpy import thunk
00014800  ff 25 aa 09 00 00  jmp qword ptr [rip + 0x9aa]
; owner 0x14806 api-ms-win-crt-stdio-l1-1-0.dll!__acrt_iob_func import thunk
00014806  ff 25 84 09 00 00  jmp qword ptr [rip + 0x984]
; owner 0x1480c api-ms-win-crt-stdio-l1-1-0.dll!__stdio_common_vfprintf import thunk
0001480c  ff 25 86 09 00 00  jmp qword ptr [rip + 0x986]
; owner 0x14830 runtime_14830
00014830  48 3b 0d c9 9f 00 00  cmp rcx, qword ptr [rip + 0x9fc9]
; owner 0x14850 runtime_14850
00014850  40 53  push rbx
0001485b  ff 15 1f 08 00 00  call qword ptr [rip + 0x81f]
00014864  ff 15 0e 08 00 00  call qword ptr [rip + 0x80e]
0001486a  ff 15 a8 07 00 00  call qword ptr [rip + 0x7a8]
0001487d  48 ff 25 7c 07 00 00  jmp qword ptr [rip + 0x77c]
; owner 0x14884 runtime_14884
00014884  48 89 4c 24 08  mov qword ptr [rsp + 8], rcx
00014892  ff 15 f8 07 00 00  call qword ptr [rip + 0x7f8]
000148a3  48 8d 0d e6 d1 00 00  lea rcx, [rip + 0xd1e6]
000148b4  48 89 05 cd d2 00 00  mov qword ptr [rip + 0xd2cd], rax
000148c4  48 89 05 5d d2 00 00  mov qword ptr [rip + 0xd25d], rax
000148cb  48 8b 05 b6 d2 00 00  mov rax, qword ptr [rip + 0xd2b6]
000148d2  48 89 05 27 d1 00 00  mov qword ptr [rip + 0xd127], rax
000148de  48 89 05 2b d2 00 00  mov qword ptr [rip + 0xd22b], rax
000148e5  c7 05 01 d1 00 00 09 04 00 c0  mov dword ptr [rip + 0xd101], 0xc0000409
000148ef  c7 05 fb d0 00 00 01 00 00 00  mov dword ptr [rip + 0xd0fb], 1
000148f9  c7 05 05 d1 00 00 01 00 00 00  mov dword ptr [rip + 0xd105], 1
0001490c  48 8d 0d fd d0 00 00  lea rcx, [rip + 0xd0fd]
00014924  48 8b 0d d5 9e 00 00  mov rcx, qword ptr [rip + 0x9ed5]
00014939  48 8b 0d 00 9f 00 00  mov rcx, qword ptr [rip + 0x9f00]
00014945  48 8d 0d ec 4f 00 00  lea rcx, [rip + 0x4fec]
; owner 0x14958 runtime_14958
00014958  48 83 ec 28  sub rsp, 0x28
; owner 0x1496c runtime_1496c
0001496c  89 4c 24 08  mov dword ptr [rsp + 8], ecx
00014979  ff 15 11 07 00 00  call qword ptr [rip + 0x711]
0001498b  48 8d 0d fe d0 00 00  lea rcx, [rip + 0xd0fe]
0001499c  48 89 05 e5 d1 00 00  mov qword ptr [rip + 0xd1e5], rax
000149ac  48 89 05 75 d1 00 00  mov qword ptr [rip + 0xd175], rax
000149b3  48 8b 05 ce d1 00 00  mov rax, qword ptr [rip + 0xd1ce]
000149ba  48 89 05 3f d0 00 00  mov qword ptr [rip + 0xd03f], rax
000149c1  c7 05 25 d0 00 00 09 04 00 c0  mov dword ptr [rip + 0xd025], 0xc0000409
000149cb  c7 05 1f d0 00 00 01 00 00 00  mov dword ptr [rip + 0xd01f], 1
000149d5  c7 05 29 d0 00 00 01 00 00 00  mov dword ptr [rip + 0xd029], 1
000149e8  48 8d 0d 21 d0 00 00  lea rcx, [rip + 0xd021]
000149f7  48 8d 0d 3a 4f 00 00  lea rcx, [rip + 0x4f3a]
; owner 0x14a0c runtime_14a0c
00014a0c  4c 89 44 24 18  mov qword ptr [rsp + 0x18], r8
00014a22  ff 15 68 06 00 00  call qword ptr [rip + 0x668]
00014a34  48 8d 0d 55 d0 00 00  lea rcx, [rip + 0xd055]
00014a45  48 89 05 3c d1 00 00  mov qword ptr [rip + 0xd13c], rax
00014a55  48 89 05 cc d0 00 00  mov qword ptr [rip + 0xd0cc], rax
00014a5c  48 8b 05 25 d1 00 00  mov rax, qword ptr [rip + 0xd125]
00014a63  48 89 05 96 cf 00 00  mov qword ptr [rip + 0xcf96], rax
00014a6a  c7 05 7c cf 00 00 09 04 00 c0  mov dword ptr [rip + 0xcf7c], 0xc0000409
00014a74  c7 05 76 cf 00 00 01 00 00 00  mov dword ptr [rip + 0xcf76], 1
00014aac  89 05 56 cf 00 00  mov dword ptr [rip + 0xcf56], eax
00014abb  48 8d 0d 4e cf 00 00  lea rcx, [rip + 0xcf4e]
00014af4  48 8d 15 15 cf 00 00  lea rdx, [rip + 0xcf15]
00014b0a  48 8d 0d 27 4e 00 00  lea rcx, [rip + 0x4e27]
; owner 0x14b1c runtime_14b1c
00014b1c  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
00014b29  ff 15 29 05 00 00  call qword ptr [rip + 0x529]
00014b41  ff 15 19 05 00 00  call qword ptr [rip + 0x519]
00014b78  ff 15 ea 04 00 00  call qword ptr [rip + 0x4ea]
; owner 0x14b8c runtime_14b8c
00014b8c  40 53  push rbx
00014b97  ff 15 bb 04 00 00  call qword ptr [rip + 0x4bb]
00014bb1  ff 15 a9 04 00 00  call qword ptr [rip + 0x4a9]
00014be8  ff 15 7a 04 00 00  call qword ptr [rip + 0x47a]
; owner 0x14c0c FUN_180014c0c
00014c0c  b0 01  mov al, 1
; owner 0x14c10 FUN_180014c10
00014c10  b0 01  mov al, 1
; owner 0x14c14 FUN_180014c14
00014c14  b0 01  mov al, 1
; owner 0x14c18 FUN_180014c18
00014c18  b0 01  mov al, 1
; owner 0x14c1c FUN_180014c1c
00014c1c  b0 01  mov al, 1
; owner 0x14c20 FUN_180014c20
00014c20  33 c0  xor eax, eax
; owner 0x14c40 runtime_14c40
00014c40  ff e0  jmp rax
; owner 0x14c60 runtime_14c60
00014c60  ff 25 9a 10 00 00  jmp qword ptr [rip + 0x109a]
; owner 0x14c70 runtime_14c70
00014c70  56  push rsi
00014c84  4c 8b 05 75 9b 00 00  mov r8, qword ptr [rip + 0x9b75]
; owner 0x14cd0 runtime_14cd0
00014cd0  56  push rsi
00014cea  48 8b 05 0f 9b 00 00  mov rax, qword ptr [rip + 0x9b0f]
00014d03  e8 fe fa ff ff  call 0x180014806
00014d21  e8 e6 fa ff ff  call 0x18001480c
; owner 0x14d40 runtime_14d40
00014d40  41 57  push r15
00014d7e  e8 71 fa ff ff  call 0x1800147f4
; owner 0x14d99 runtime_14d99
00014d99  40 55  push rbp
; owner 0x14db0 runtime_14db0
00014db0  40 55  push rbp
; owner 0x14dc9 runtime_14dc9
00014dc9  40 55  push rbp
; owner 0x14ddd runtime_14ddd
00014ddd  40 55  push rbp
00014df4  4c 8d 0d 29 cd ff ff  lea r9, [rip - 0x32d7]
; owner 0x14e13 runtime_14e13
00014e13  40 55  push rbp
