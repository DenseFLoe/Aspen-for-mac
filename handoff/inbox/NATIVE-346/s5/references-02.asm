00005a90  41 57  push r15
00005a9d  48 8d 0d 3c 1e 01 00  lea rcx, [rip + 0x11e3c]
00005aa4  e8 ab b8 00 00  call 0x11354
00005aa9  4c 8b 35 48 fa 00 00  mov r14, qword ptr [rip + 0xfa48]
00005ab8  48 89 05 71 a4 01 00  mov qword ptr [rip + 0x1a471], rax
00005abf  48 8d 0d 6a a4 01 00  lea rcx, [rip + 0x1a46a]
00005ac6  e8 89 b8 00 00  call 0x11354
00005acb  48 89 05 56 a4 01 00  mov qword ptr [rip + 0x1a456], rax
00005ad7  4c 89 3d 42 a4 01 00  mov qword ptr [rip + 0x1a442], r15
00005ae1  0f 8e d9 00 00 00  jle 0x5bc0
00005ae7  48 c7 05 16 a4 01 00 01 00 00 00  mov qword ptr [rip + 0x1a416], 1
00005af7  4c 8d 25 82 1c 01 00  lea r12, [rip + 0x11c82]
00005afe  48 8d 35 fb a3 01 00  lea rsi, [rip + 0x1a3fb]
00005b05  48 8d 3d 0c a4 01 00  lea rdi, [rip + 0x1a40c]
00005b0c  48 8d 1d fd a3 01 00  lea rbx, [rip + 0x1a3fd]
00005b16  eb 4a  jmp 0x5b62
00005b25  48 89 05 d4 a3 01 00  mov qword ptr [rip + 0x1a3d4], rax
00005b35  e8 26 ba ff ff  call 0x1560
00005b3a  48 8b 05 e7 a3 01 00  mov rax, qword ptr [rip + 0x1a3e7]
00005b41  48 8b 15 d8 a3 01 00  mov rdx, qword ptr [rip + 0x1a3d8]
00005b48  48 8b 0d b9 a3 01 00  mov rcx, qword ptr [rip + 0x1a3b9]
00005b53  4c 89 05 ae a3 01 00  mov qword ptr [rip + 0x1a3ae], r8
00005b60  7d 5e  jge 0x5bc0
00005b72  75 db  jne 0x5b4f
00005b85  4c 89 0d 8c a3 01 00  mov qword ptr [rip + 0x1a38c], r9
00005b8c  4c 89 15 7d a3 01 00  mov qword ptr [rip + 0x1a37d], r10
00005b99  eb 16  jmp 0x5bb1
00005bab  0f 84 6f ff ff ff  je 0x5b20
00005bb6  75 e8  jne 0x5ba0
00005bbc  75 e2  jne 0x5ba0
00005bbe  eb 8f  jmp 0x5b4f
00005bd0  48 83 ec 28  sub rsp, 0x28
00005bd4  48 c7 05 69 a3 01 00 00 00 00 00  mov qword ptr [rip + 0x1a369], 0
00005bdf  4c 8d 05 62 a3 01 00  lea r8, [rip + 0x1a362]
00005be6  48 c7 05 4f a3 01 00 00 00 00 00  mov qword ptr [rip + 0x1a34f], 0
00005bf1  48 8d 0d 48 a3 01 00  lea rcx, [rip + 0x1a348]
00005bf8  48 c7 05 35 a3 01 00 00 00 00 00  mov qword ptr [rip + 0x1a335], 0
00005c03  48 8d 15 2e a3 01 00  lea rdx, [rip + 0x1a32e]
00005c0a  e8 a7 b8 00 00  call 0x114b6
00005c0f  48 83 3d 31 a3 01 00 00  cmp qword ptr [rip + 0x1a331], 0
00005c17  7e 31  jle 0x5c4a
00005c19  48 8b 05 20 a3 01 00  mov rax, qword ptr [rip + 0x1a320]
00005c20  48 8b 0d d1 f8 00 00  mov rcx, qword ptr [rip + 0xf8d1]
00005c2f  48 8b 05 02 a3 01 00  mov rax, qword ptr [rip + 0x1a302]
00005c3e  48 8d 0d 03 a3 01 00  lea rcx, [rip + 0x1a303]
00005c45  e8 06 00 00 00  call 0x5c50
00005c50  41 57  push r15
00005c9d  0f 8e d3 08 00 00  jle 0x6576
00005ca3  48 8b 05 f6 f7 00 00  mov rax, qword ptr [rip + 0xf7f6]
00005d55  48 8b 0d 8c f7 00 00  mov rcx, qword ptr [rip + 0xf78c]
00005dc8  66 0f 28 0d 20 1b 01 00  movapd xmm1, xmmword ptr [rip + 0x11b20]
00005dd0  f2 0f 10 15 38 1b 01 00  movsd xmm2, qword ptr [rip + 0x11b38]
00005dd8  f2 0f 10 1d 38 1b 01 00  movsd xmm3, qword ptr [rip + 0x11b38]
00005de4  f2 0f 10 2d 14 1b 01 00  movsd xmm5, qword ptr [rip + 0x11b14]
00005dec  f2 0f 10 35 14 1b 01 00  movsd xmm6, qword ptr [rip + 0x11b14]
00005dfd  48 8b 3d f4 f6 00 00  mov rdi, qword ptr [rip + 0xf6f4]
00005ea5  4c 8d 35 54 1c 01 00  lea r14, [rip + 0x11c54]
00005eac  4c 8d 25 ad 1b 01 00  lea r12, [rip + 0x11bad]
00005eb3  4c 8d 2d 66 1b 01 00  lea r13, [rip + 0x11b66]
00005eba  48 8d 2d 1f 1b 01 00  lea rbp, [rip + 0x11b1f]
00005ec1  48 8d 05 d8 1a 01 00  lea rax, [rip + 0x11ad8]
00005ec8  4c 8d 15 91 1a 01 00  lea r10, [rip + 0x11a91]
00005ecf  48 8d 35 4a 1a 01 00  lea rsi, [rip + 0x11a4a]
00005ed6  eb 1a  jmp 0x5ef2
00005eec  0f 8d 84 06 00 00  jge 0x6576
00005f26  74 48  je 0x5f70
00005f2c  0f 85 82 00 00 00  jne 0x5fb4
00005f54  74 5e  je 0x5fb4
00005f58  74 5a  je 0x5fb4
00005f6e  eb 3e  jmp 0x5fae
00005f93  74 1f  je 0x5fb4
00005f97  74 1b  je 0x5fb4
00005fd0  74 14  je 0x5fe6
00005fd5  74 0f  je 0x5fe6
00006002  74 14  je 0x6018
00006007  74 0f  je 0x6018
00006034  74 14  je 0x604a
00006039  74 0f  je 0x604a
00006075  74 1a  je 0x6091
00006080  74 0f  je 0x6091
000060b5  74 14  je 0x60cb
000060ba  74 0f  je 0x60cb
000060e7  74 14  je 0x60fd
000060ec  74 0f  je 0x60fd
00006128  74 1a  je 0x6144
00006133  74 0f  je 0x6144
0000616f  74 1a  je 0x618b
0000617a  74 0f  je 0x618b
000061b6  74 1a  je 0x61d2
000061c1  74 0f  je 0x61d2
000061fd  74 1a  je 0x6219
00006208  74 0f  je 0x6219
00006244  74 30  je 0x6276
00006249  74 2b  je 0x6276
00006274  75 ea  jne 0x6260
00006298  74 2b  je 0x62c5
0000629d  74 26  je 0x62c5
000062c3  75 eb  jne 0x62b0
000062e8  4c 8d 1d b1 17 01 00  lea r11, [rip + 0x117b1]
000062ef  74 35  je 0x6326
000062f4  74 30  je 0x6326
00006324  75 ea  jne 0x6310
00006345  74 2f  je 0x6376
0000634a  74 2a  je 0x6376
00006374  75 ea  jne 0x6360
00006398  74 2c  je 0x63c6
0000639d  74 27  je 0x63c6
000063c4  75 ea  jne 0x63b0
000063e2  74 32  je 0x6416
000063e7  74 2d  je 0x6416
00006414  75 ea  jne 0x6400
0000643f  74 35  je 0x6476
00006444  74 30  je 0x6476
00006474  75 ea  jne 0x6460
00006493  74 14  je 0x64a9
00006498  74 0f  je 0x64a9
000064c4  74 30  je 0x64f6
000064c9  74 2b  je 0x64f6
000064f4  75 ea  jne 0x64e0
0000650c  74 26  je 0x6534
00006510  74 22  je 0x6534
00006532  75 ec  jne 0x6520
00006554  0f 84 86 f9 ff ff  je 0x5ee0
0000655c  0f 84 7e f9 ff ff  je 0x5ee0
00006571  e9 6a f9 ff ff  jmp 0x5ee0
000065b0  41 57  push r15
000065e4  48 8d 0d fd 9b 01 00  lea rcx, [rip + 0x19bfd]
000065eb  e8 c0 ae 00 00  call 0x114b0
000065f7  4c 8b 25 02 ef 00 00  mov r12, qword ptr [rip + 0xef02]
0000660a  48 8b 05 ef eb 00 00  mov rax, qword ptr [rip + 0xebef]
00006618  48 8b 35 b9 ee 00 00  mov rsi, qword ptr [rip + 0xeeb9]
0000662a  48 8b 05 67 f6 00 00  mov rax, qword ptr [rip + 0xf667]
0000663c  e8 81 ae 00 00  call 0x114c2
00006641  e8 9c af 00 00  call 0x115e2
00006651  48 8b 35 18 ed 00 00  mov rsi, qword ptr [rip + 0xed18]
0000665b  48 89 05 ae 9e 01 00  mov qword ptr [rip + 0x19eae], rax
00006662  48 8d 0d 3f 15 01 00  lea rcx, [rip + 0x1153f]
00006669  e8 5a ae 00 00  call 0x114c8
0000666e  48 8d 0d a3 15 01 00  lea rcx, [rip + 0x115a3]
00006675  e8 4e ae 00 00  call 0x114c8
0000667a  48 8b 05 8f 9e 01 00  mov rax, qword ptr [rip + 0x19e8f]
00006684  4c 8b 2d 8d eb 00 00  mov r13, qword ptr [rip + 0xeb8d]
00006693  48 8b 05 e6 f5 00 00  mov rax, qword ptr [rip + 0xf5e6]
000066f8  48 8b 15 21 eb 00 00  mov rdx, qword ptr [rip + 0xeb21]
0000671d  75 f1  jne 0x6710
0000672a  75 d4  jne 0x6700
0000672c  48 c7 05 f9 9f 01 00 05 00 00 00  mov qword ptr [rip + 0x19ff9], 5
00006737  48 8b 0d e2 ea 00 00  mov rcx, qword ptr [rip + 0xeae2]
00006763  48 c7 05 32 9a 01 00 00 00 00 00  mov qword ptr [rip + 0x19a32], 0
0000676e  48 8b 35 83 ed 00 00  mov rsi, qword ptr [rip + 0xed83]
0000677e  e8 57 b3 00 00  call 0x11ada
00006783  48 c7 05 32 b8 01 00 01 00 00 00  mov qword ptr [rip + 0x1b832], 1
0000678e  48 8b 05 1b ee 00 00  mov rax, qword ptr [rip + 0xee1b]
0000680c  48 8b 0d 15 f4 00 00  mov rcx, qword ptr [rip + 0xf415]
00006823  48 8b 05 06 f4 00 00  mov rax, qword ptr [rip + 0xf406]
0000683b  48 c7 05 1a 97 01 00 01 00 00 00  mov qword ptr [rip + 0x1971a], 1
00006846  4c 8b 25 93 ec 00 00  mov r12, qword ptr [rip + 0xec93]
000068ce  48 8b 05 43 f0 00 00  mov rax, qword ptr [rip + 0xf043]
000068dc  48 8b 0d f5 eb 00 00  mov rcx, qword ptr [rip + 0xebf5]
000068ee  48 c7 05 67 b7 01 00 00 00 00 00  mov qword ptr [rip + 0x1b767], 0
000068f9  48 8b 05 18 ed 00 00  mov rax, qword ptr [rip + 0xed18]
00006904  48 8b 05 8d ec 00 00  mov rax, qword ptr [rip + 0xec8d]
00006916  48 8b 05 1b f3 00 00  mov rax, qword ptr [rip + 0xf31b]
00006939  74 0c  je 0x6947
00006953  0f 29 05 76 96 01 00  movaps xmmword ptr [rip + 0x19676], xmm0
0000695a  48 c7 05 7b 96 01 00 00 00 00 00  mov qword ptr [rip + 0x1967b], 0
00006965  48 8b 05 7c eb 00 00  mov rax, qword ptr [rip + 0xeb7c]
00006970  48 8b 05 f9 ee 00 00  mov rax, qword ptr [rip + 0xeef9]
00006983  48 8b 2d 9e e8 00 00  mov rbp, qword ptr [rip + 0xe89e]
000069ac  75 f2  jne 0x69a0
000069ae  48 c7 05 77 9d 01 00 25 00 00 00  mov qword ptr [rip + 0x19d77], 0x25
00006a56  48 8b 05 0b ea 00 00  mov rax, qword ptr [rip + 0xea0b]
00006a76  48 8b 05 e3 f1 00 00  mov rax, qword ptr [rip + 0xf1e3]
00006a88  e8 53 aa 00 00  call 0x114e0
00006a8d  48 8b 0d 74 e9 00 00  mov rcx, qword ptr [rip + 0xe974]
00006aa7  48 8b 05 8a e7 00 00  mov rax, qword ptr [rip + 0xe78a]
00006ab6  48 8b 05 83 e7 00 00  mov rax, qword ptr [rip + 0xe783]
00006ad4  48 8b 0d fd e9 00 00  mov rcx, qword ptr [rip + 0xe9fd]
00006aeb  48 8d 3d 56 97 01 00  lea rdi, [rip + 0x19756]
00006afa  e8 f3 a9 00 00  call 0x114f2
00006b07  e8 3e a9 00 00  call 0x1144a
00006b0f  48 83 3d d1 96 01 00 02  cmp qword ptr [rip + 0x196d1], 2
00006b17  75 12  jne 0x6b2b
00006b19  0f 28 05 70 10 01 00  movaps xmm0, xmmword ptr [rip + 0x11070]
00006b29  eb 1b  jmp 0x6b46
00006b46  48 8b 05 8b e6 00 00  mov rax, qword ptr [rip + 0xe68b]
00006b55  4c 8d 2d 64 99 01 00  lea r13, [rip + 0x19964]
00006b5c  75 34  jne 0x6b92
00006b63  4c 8d 05 86 10 01 00  lea r8, [rip + 0x11086]
00006b78  48 8d 0d c9 96 01 00  lea rcx, [rip + 0x196c9]
00006b7f  48 8d 15 9a 10 01 00  lea rdx, [rip + 0x1109a]
00006b86  4c 8d 0d 8b 10 01 00  lea r9, [rip + 0x1108b]
00006b8d  e8 66 a9 00 00  call 0x114f8
00006b92  48 c7 05 63 99 01 00 01 00 00 00  mov qword ptr [rip + 0x19963], 1
00006b9d  4c 8d 05 5c 99 01 00  lea r8, [rip + 0x1995c]
00006ba4  48 c7 05 59 99 01 00 03 00 00 00  mov qword ptr [rip + 0x19959], 3
00006baf  48 8b 05 12 e8 00 00  mov rax, qword ptr [rip + 0xe812]
00006bd0  48 89 05 09 99 01 00  mov qword ptr [rip + 0x19909], rax
00006bd7  4c 8d 0d 02 99 01 00  lea r9, [rip + 0x19902]
00006bde  48 89 05 03 99 01 00  mov qword ptr [rip + 0x19903], rax
00006bea  48 8d 3d ff 0f 01 00  lea rdi, [rip + 0x10fff]
00006c05  4c 03 35 4c e6 00 00  add r14, qword ptr [rip + 0xe64c]
00006c0c  48 8d 15 0d 10 01 00  lea rdx, [rip + 0x1100d]
00006c16  e8 dd a8 00 00  call 0x114f8
00006c1e  e8 31 a7 00 00  call 0x11354
00006c23  48 89 05 fe 9a 01 00  mov qword ptr [rip + 0x19afe], rax
00006c32  48 8b 15 27 e6 00 00  mov rdx, qword ptr [rip + 0xe627]
00006c7f  4c 8b 3d 82 e7 00 00  mov r15, qword ptr [rip + 0xe782]
00006c8e  0f 84 b7 01 00 00  je 0x6e4b
00006c94  e8 71 a8 00 00  call 0x1150a
00006c9c  4c 8b 2d 35 e8 00 00  mov r13, qword ptr [rip + 0xe835]
00006ca3  0f 85 cc 00 00 00  jne 0x6d75
00006cae  48 8d 15 63 0f 01 00  lea rdx, [rip + 0x10f63]
00006ccc  48 8d 0d cd 79 01 00  lea rcx, [rip + 0x179cd]
00006cd3  4c 8d 05 46 0f 01 00  lea r8, [rip + 0x10f46]
00006cda  e8 c9 a6 00 00  call 0x113a8
00006ce2  0f 84 8d 00 00 00  je 0x6d75
00006d0c  48 8b 05 7d e7 00 00  mov rax, qword ptr [rip + 0xe77d]
00006d2d  48 8d 05 1c 0e 01 00  lea rax, [rip + 0x10e1c]
00006d3c  48 8d 05 fd 79 01 00  lea rax, [rip + 0x179fd]
00006d64  e8 a1 ad 00 00  call 0x11b0a
00006d69  48 8d 0d b0 0e 01 00  lea rcx, [rip + 0x10eb0]
00006d70  e8 3f a6 00 00  call 0x113b4
00006d75  e8 96 a7 00 00  call 0x11510
00006d7a  48 8b 3d 57 e4 00 00  mov rdi, qword ptr [rip + 0xe457]
00006d8c  48 8d 0d 8d 0e 01 00  lea rcx, [rip + 0x10e8d]
00006d93  e8 bc a5 00 00  call 0x11354
00006da1  4c 8b 35 60 e6 00 00  mov r14, qword ptr [rip + 0xe660]
00006def  48 8b 0d 82 e4 00 00  mov rcx, qword ptr [rip + 0xe482]
00006e3d  4c 8b 3d a4 e6 00 00  mov r15, qword ptr [rip + 0xe6a4]
00006e44  75 5b  jne 0x6ea1
00006e46  e9 65 19 00 00  jmp 0x87b0
00006e50  48 8d 05 c1 0d 01 00  lea rax, [rip + 0x10dc1]
00006e65  48 8d 15 b4 0d 01 00  lea rdx, [rip + 0x10db4]
00006e6c  4c 8d 05 3d 0d 01 00  lea r8, [rip + 0x10d3d]
00006e73  4c 8d 0d 76 0d 01 00  lea r9, [rip + 0x10d76]
00006e7d  e8 76 a6 00 00  call 0x114f8
00006e89  4c 8b 2d 48 e6 00 00  mov r13, qword ptr [rip + 0xe648]
00006e93  4c 8b 3d 4e e6 00 00  mov r15, qword ptr [rip + 0xe64e]
00006e9a  48 8b 3d 37 e3 00 00  mov rdi, qword ptr [rip + 0xe337]
00006ea1  48 8b 0d 20 e5 00 00  mov rcx, qword ptr [rip + 0xe520]
00006ee1  48 8d 0d 08 0d 01 00  lea rcx, [rip + 0x10d08]
00006ee8  e8 67 a4 00 00  call 0x11354
00006eed  48 89 05 34 98 01 00  mov qword ptr [rip + 0x19834], rax
00006efc  48 89 05 1d 98 01 00  mov qword ptr [rip + 0x1981d], rax
00006f14  0f 84 22 02 00 00  je 0x713c
00006f23  0f 85 21 02 00 00  jne 0x714a
00006f29  48 8d 0d f0 97 01 00  lea rcx, [rip + 0x197f0]
00006f30  e8 1f a4 00 00  call 0x11354
00006f35  48 89 05 dc 97 01 00  mov qword ptr [rip + 0x197dc], rax
00006f3c  e8 87 ab 00 00  call 0x11ac8
00006f41  e8 88 ab 00 00  call 0x11ace
00006f46  48 89 05 a3 92 01 00  mov qword ptr [rip + 0x192a3], rax
00006f4d  48 8d 0d 9c 92 01 00  lea rcx, [rip + 0x1929c]
00006f54  e8 7b ab 00 00  call 0x11ad4
00006f59  48 8b 05 b8 97 01 00  mov rax, qword ptr [rip + 0x197b8]
00006f68  48 89 05 e1 94 01 00  mov qword ptr [rip + 0x194e1], rax
00006f72  0f 8e 9e 00 00 00  jle 0x7016
00006f78  48 8d 0d d1 94 01 00  lea rcx, [rip + 0x194d1]
00006f7f  e8 d0 a3 00 00  call 0x11354
00006f84  48 8b 3d 6d e5 00 00  mov rdi, qword ptr [rip + 0xe56d]
00006f90  48 89 05 b1 94 01 00  mov qword ptr [rip + 0x194b1], rax
00006f9a  7e 7a  jle 0x7016
00006f9c  48 8d 0d a5 94 01 00  lea rcx, [rip + 0x194a5]
00006fa3  e8 ac a3 00 00  call 0x11354
00006fba  48 8d 0d f7 0b 01 00  lea rcx, [rip + 0x10bf7]
00006fc1  4c 8d 05 78 92 01 00  lea r8, [rip + 0x19278]
00006fc8  48 8d 3d 78 93 01 00  lea rdi, [rip + 0x19378]
00006fd2  e8 45 a5 00 00  call 0x1151c
00006fd7  48 8b 1d 7a e2 00 00  mov rbx, qword ptr [rip + 0xe27a]
00006fee  e8 2d 1d 00 00  call 0x8d20
0000700a  e8 11 1d 00 00  call 0x8d20
00007016  48 8b 0d fb 96 01 00  mov rcx, qword ptr [rip + 0x196fb]
00007042  0f 84 16 01 00 00  je 0x715e
00007051  75 13  jne 0x7066
00007053  48 8b 05 9e e4 00 00  mov rax, qword ptr [rip + 0xe49e]
00007066  48 8d 0d 83 0b 01 00  lea rcx, [rip + 0x10b83]
0000706d  e8 e2 a2 00 00  call 0x11354
00007072  48 89 05 af 96 01 00  mov qword ptr [rip + 0x196af], rax
00007081  48 89 05 88 96 01 00  mov qword ptr [rip + 0x19688], rax
00007088  48 8d 0d 81 96 01 00  lea rcx, [rip + 0x19681]
0000708f  e8 c0 a2 00 00  call 0x11354
0000709a  74 19  je 0x70b5
0000709c  e8 ef a5 00 00  call 0x11690
000070a1  e8 f0 a5 00 00  call 0x11696
000070a6  e8 f1 a5 00 00  call 0x1169c
000070ab  e8 f2 a5 00 00  call 0x116a2
000070b0  e8 f3 a5 00 00  call 0x116a8
000070b5  48 8b 05 6c 96 01 00  mov rax, qword ptr [rip + 0x1966c]
000070c1  48 89 05 40 96 01 00  mov qword ptr [rip + 0x19640], rax
000070c8  4c 8d 35 39 96 01 00  lea r14, [rip + 0x19639]
000070cf  48 8d 15 2a 96 01 00  lea rdx, [rip + 0x1962a]
000070d6  4c 8d 05 1b 96 01 00  lea r8, [rip + 0x1961b]
000070dd  4c 8d 0d 0c 96 01 00  lea r9, [rip + 0x1960c]
000070e7  e8 ec a2 00 00  call 0x113d8
000070ec  48 8d 15 f5 95 01 00  lea rdx, [rip + 0x195f5]
000070f3  4c 8d 05 e6 95 01 00  lea r8, [rip + 0x195e6]
000070fd  e8 20 a4 00 00  call 0x11522
00007102  4c 8b 05 df 95 01 00  mov r8, qword ptr [rip + 0x195df]
0000710c  48 8b 1d f5 e2 00 00  mov rbx, qword ptr [rip + 0xe2f5]
00007113  7e 7c  jle 0x7191
00007115  48 8b 05 e4 95 01 00  mov rax, qword ptr [rip + 0x195e4]
00007120  76 50  jbe 0x7172
0000712e  48 8b 0d a3 e3 00 00  mov rcx, qword ptr [rip + 0xe3a3]
00007135  e8 e6 1b 00 00  call 0x8d20
0000713a  eb 55  jmp 0x7191
00007144  0f 84 df fd ff ff  je 0x6f29
00007159  e9 52 16 00 00  jmp 0x87b0
00007167  0f 84 e6 fe ff ff  je 0x7053
0000716d  e9 f4 fe ff ff  jmp 0x7066
0000718f  75 ef  jne 0x7180
00007191  48 8b 3d 48 95 01 00  mov rdi, qword ptr [rip + 0x19548]
00007198  48 c7 05 8d 95 01 00 01 00 00 00  mov qword ptr [rip + 0x1958d], 1
000071a6  7e 55  jle 0x71fd
000071a8  48 8b 05 49 95 01 00  mov rax, qword ptr [rip + 0x19549]
000071b3  76 1e  jbe 0x71d3
000071c5  48 8b 0d 1c e3 00 00  mov rcx, qword ptr [rip + 0xe31c]
000071cc  e8 4f 1b 00 00  call 0x8d20
000071d1  eb 20  jmp 0x71f3
000071f1  75 ed  jne 0x71e0
000071f6  48 89 3d 33 95 01 00  mov qword ptr [rip + 0x19533], rdi
00007201  48 8b 0d 78 8d 01 00  mov rcx, qword ptr [rip + 0x18d78]
00007218  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007220  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007228  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007230  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007238  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007240  f2 0f 11 05 80 8d 01 00  movsd qword ptr [rip + 0x18d80], xmm0
00007266  e8 4b a8 00 00  call 0x11ab6
0000726b  48 8b 3d 06 e0 00 00  mov rdi, qword ptr [rip + 0xe006]
00007279  48 8d 0d 70 09 01 00  lea rcx, [rip + 0x10970]
00007280  48 8d 15 39 09 01 00  lea rdx, [rip + 0x10939]
00007287  e8 9c a2 00 00  call 0x11528
00007293  48 8d 0d 2e 09 01 00  lea rcx, [rip + 0x1092e]
0000729a  48 8d 15 47 09 01 00  lea rdx, [rip + 0x10947]
000072a1  e8 82 a2 00 00  call 0x11528
000072ae  75 05  jne 0x72b5
000072b0  e8 79 a2 00 00  call 0x1152e
000072b5  48 8b 05 6c 94 01 00  mov rax, qword ptr [rip + 0x1946c]
000072c4  48 89 05 55 94 01 00  mov qword ptr [rip + 0x19455], rax
000072cb  48 8d 0d 4e 94 01 00  lea rcx, [rip + 0x1944e]
000072d2  e8 7d a0 00 00  call 0x11354
000072d7  48 89 05 3a 94 01 00  mov qword ptr [rip + 0x1943a], rax
000072e6  48 89 05 f3 8e 01 00  mov qword ptr [rip + 0x18ef3], rax
000072f0  0f 84 ca 00 00 00  je 0x73c0
000072f6  48 8d 0d e3 8e 01 00  lea rcx, [rip + 0x18ee3]
000072fd  48 8d 15 d4 8e 01 00  lea rdx, [rip + 0x18ed4]
00007304  4c 8d 05 c5 8e 01 00  lea r8, [rip + 0x18ec5]
0000730b  4c 8d 0d de 93 01 00  lea r9, [rip + 0x193de]
00007312  e8 c1 a0 00 00  call 0x113d8
00007317  48 8b 1d ba 8e 01 00  mov rbx, qword ptr [rip + 0x18eba]
00007326  4c 8b 35 73 df 00 00  mov r14, qword ptr [rip + 0xdf73]
0000733a  e8 e1 19 00 00  call 0x8d20
0000733f  48 8b 05 8a 8e 01 00  mov rax, qword ptr [rip + 0x18e8a]
000073be  eb 53  jmp 0x7413
000073c0  48 8b 1d d9 de 00 00  mov rbx, qword ptr [rip + 0xded9]
000073d6  e8 15 1a 00 00  call 0x8df0
00007411  75 ed  jne 0x7400
00007413  48 c7 05 12 93 01 00 0b 00 00 00  mov qword ptr [rip + 0x19312], 0xb
0000741e  48 8b 05 03 93 01 00  mov rax, qword ptr [rip + 0x19303]
0000742d  48 89 05 ec 92 01 00  mov qword ptr [rip + 0x192ec], rax
00007434  48 8d 0d e5 92 01 00  lea rcx, [rip + 0x192e5]
0000743b  e8 14 9f 00 00  call 0x11354
00007440  48 89 05 d1 92 01 00  mov qword ptr [rip + 0x192d1], rax
00007447  48 8b 0d da 92 01 00  mov rcx, qword ptr [rip + 0x192da]
0000746e  48 89 05 63 92 01 00  mov qword ptr [rip + 0x19263], rax
00007478  0f 84 6d 01 00 00  je 0x75eb
0000747e  48 8d 0d 53 92 01 00  lea rcx, [rip + 0x19253]
00007485  48 8d 15 44 92 01 00  lea rdx, [rip + 0x19244]
0000748c  4c 8d 05 35 92 01 00  lea r8, [rip + 0x19235]
00007493  4c 8d 0d 56 92 01 00  lea r9, [rip + 0x19256]
0000749a  e8 39 9f 00 00  call 0x113d8
0000749f  48 8b 0d 22 92 01 00  mov rcx, qword ptr [rip + 0x19222]
000074a6  48 8b 05 23 92 01 00  mov rax, qword ptr [rip + 0x19223]
000074c6  4c 8b 15 8b e7 00 00  mov r10, qword ptr [rip + 0xe78b]
000074cd  eb 10  jmp 0x74df
000074f3  7e db  jle 0x74d0
000074f9  76 de  jbe 0x74d9
000074ff  4c 89 1d 2a 92 01 00  mov qword ptr [rip + 0x1922a], r11
0000750c  48 8b 15 15 e7 00 00  mov rdx, qword ptr [rip + 0xe715]
00007521  72 0e  jb 0x7531
0000753b  48 89 15 1e 8a 01 00  mov qword ptr [rip + 0x18a1e], rdx
00007542  48 8b 15 e7 e6 00 00  mov rdx, qword ptr [rip + 0xe6e7]
0000757d  72 0f  jb 0x758e
000075eb  48 c7 05 3a 91 01 00 01 00 00 00  mov qword ptr [rip + 0x1913a], 1
000075fc  4c 03 35 d5 de 00 00  add r14, qword ptr [rip + 0xded5]
00007603  48 8b 05 f6 de 00 00  mov rax, qword ptr [rip + 0xdef6]
0000760e  4c 8d 25 1b 91 01 00  lea r12, [rip + 0x1911b]
0000762c  e8 03 9f 00 00  call 0x11534
00007631  48 8b 05 f8 90 01 00  mov rax, qword ptr [rip + 0x190f8]
0000763c  48 89 0d ed 90 01 00  mov qword ptr [rip + 0x190ed], rcx
00007647  7c d7  jl 0x7620
00007649  48 8b 05 b8 dd 00 00  mov rax, qword ptr [rip + 0xddb8]
00007662  0f 85 48 03 00 00  jne 0x79b0
00007668  48 8b 05 b9 90 01 00  mov rax, qword ptr [rip + 0x190b9]
0000766f  4c 8b 25 82 de 00 00  mov r12, qword ptr [rip + 0xde82]
00007686  48 89 05 33 90 01 00  mov qword ptr [rip + 0x19033], rax
0000768d  48 89 0d 24 90 01 00  mov qword ptr [rip + 0x19024], rcx
00007694  48 8d 1d 55 90 01 00  lea rbx, [rip + 0x19055]
000076a0  48 8d 0d 49 05 01 00  lea rcx, [rip + 0x10549]
000076a7  48 8d 15 7a 8b 01 00  lea rdx, [rip + 0x18b7a]
000076ae  4c 8d 05 6b 8b 01 00  lea r8, [rip + 0x18b6b]
000076b5  4c 8d 35 f4 8f 01 00  lea r14, [rip + 0x18ff4]
000076bf  e8 2c 9d 00 00  call 0x113f0
000076c4  48 83 3d f4 8f 01 00 00  cmp qword ptr [rip + 0x18ff4], 0
000076cc  74 35  je 0x7703
000076d3  48 03 15 d6 e5 00 00  add rdx, qword ptr [rip + 0xe5d6]
000076da  48 8d 0d df 8f 01 00  lea rcx, [rip + 0x18fdf]
000076e1  4c 8d 05 c8 8f 01 00  lea r8, [rip + 0x18fc8]
000076e8  4c 8d 0d 01 90 01 00  lea r9, [rip + 0x19001]
000076ef  e8 e4 9c 00 00  call 0x113d8
000076fe  e9 76 02 00 00  jmp 0x7979
00007703  48 8b 05 16 8b 01 00  mov rax, qword ptr [rip + 0x18b16]
00007712  48 89 05 1f 8b 01 00  mov qword ptr [rip + 0x18b1f], rax
00007719  48 8d 0d 18 8b 01 00  lea rcx, [rip + 0x18b18]
00007725  48 8b 05 84 e5 00 00  mov rax, qword ptr [rip + 0xe584]
00007733  48 8d 15 86 8f 01 00  lea rdx, [rip + 0x18f86]
0000773d  e8 f8 9d 00 00  call 0x1153a
00007742  48 8b 05 77 8f 01 00  mov rax, qword ptr [rip + 0x18f77]
00007749  48 8b 0d d8 8f 01 00  mov rcx, qword ptr [rip + 0x18fd8]
00007758  48 8b 05 c1 8a 01 00  mov rax, qword ptr [rip + 0x18ac1]
00007767  48 89 05 c2 8a 01 00  mov qword ptr [rip + 0x18ac2], rax
0000776e  48 8d 0d bb 8a 01 00  lea rcx, [rip + 0x18abb]
0000777a  4c 8d 3d 97 8a 01 00  lea r15, [rip + 0x18a97]
00007781  4c 8d 05 88 8a 01 00  lea r8, [rip + 0x18a88]
0000778e  e8 a7 9d 00 00  call 0x1153a
00007793  48 8b 05 7e 8a 01 00  mov rax, qword ptr [rip + 0x18a7e]
0000779a  48 8b 0d 87 8f 01 00  mov rcx, qword ptr [rip + 0x18f87]
000077a9  48 8d 15 98 8e 01 00  lea rdx, [rip + 0x18e98]
000077b0  4c 8d 2d 89 8e 01 00  lea r13, [rip + 0x18e89]
000077c3  e8 5a 9d 00 00  call 0x11522
000077d2  4c 8d 05 2f 8a 01 00  lea r8, [rip + 0x18a2f]
000077d9  4c 8d 0d 90 8e 01 00  lea r9, [rip + 0x18e90]
000077e6  e8 55 9d 00 00  call 0x11540
000077eb  48 8b 05 16 8a 01 00  mov rax, qword ptr [rip + 0x18a16]
000077f2  48 8b 0d 2f 8f 01 00  mov rcx, qword ptr [rip + 0x18f2f]
00007801  48 8b 05 68 8e 01 00  mov rax, qword ptr [rip + 0x18e68]
00007808  48 89 05 29 8e 01 00  mov qword ptr [rip + 0x18e29], rax
00007814  48 8b 1d 95 e4 00 00  mov rbx, qword ptr [rip + 0xe495]
00007827  4c 8d 05 8a 8e 01 00  lea r8, [rip + 0x18e8a]
00007834  e8 07 9d 00 00  call 0x11540
00007839  48 8b 05 78 8e 01 00  mov rax, qword ptr [rip + 0x18e78]
00007840  48 8b 15 e1 8e 01 00  mov rdx, qword ptr [rip + 0x18ee1]
00007847  48 8b 0d ba db 00 00  mov rcx, qword ptr [rip + 0xdbba]
00007852  48 8b 0d e7 8d 01 00  mov rcx, qword ptr [rip + 0x18de7]
0000785d  48 03 0d e4 8d 01 00  add rcx, qword ptr [rip + 0x18de4]
00007876  74 0a  je 0x7882
00007880  eb 07  jmp 0x7889
00007896  48 89 0d 63 89 01 00  mov qword ptr [rip + 0x18963], rcx
0000789d  4c 8d 35 5c 89 01 00  lea r14, [rip + 0x1895c]
000078a4  48 8b 05 65 89 01 00  mov rax, qword ptr [rip + 0x18965]
000078c5  e8 7c 9c 00 00  call 0x11546
000078ca  48 8b 05 3f 89 01 00  mov rax, qword ptr [rip + 0x1893f]
000078d9  48 8b 05 58 8d 01 00  mov rax, qword ptr [rip + 0x18d58]
000078eb  e8 56 9c 00 00  call 0x11546
000078fc  48 c7 05 29 8e 01 00 01 00 00 00  mov qword ptr [rip + 0x18e29], 1
00007914  7e 63  jle 0x7979
00007919  4c 8d 35 18 8d 01 00  lea r14, [rip + 0x18d18]
00007920  4c 8d 3d 09 8e 01 00  lea r15, [rip + 0x18e09]
00007936  4c 8d 05 e3 02 01 00  lea r8, [rip + 0x102e3]
0000793d  e8 0a 9c 00 00  call 0x1154c
0000794d  4c 8d 05 9c 02 01 00  lea r8, [rip + 0x1029c]
00007954  e8 f3 9b 00 00  call 0x1154c
00007962  48 8b 05 c7 8d 01 00  mov rax, qword ptr [rip + 0x18dc7]
0000796d  48 89 0d bc 8d 01 00  mov qword ptr [rip + 0x18dbc], rcx
00007977  7c b7  jl 0x7930
00007979  48 83 3d 37 8d 01 00 00  cmp qword ptr [rip + 0x18d37], 0
00007981  4c 8b 2d 50 db 00 00  mov r13, qword ptr [rip + 0xdb50]
00007988  74 26  je 0x79b0
0000798f  48 03 15 1a e3 00 00  add rdx, qword ptr [rip + 0xe31a]
00007996  48 8d 0d 1b 8d 01 00  lea rcx, [rip + 0x18d1b]
0000799d  4c 8d 05 0c 8d 01 00  lea r8, [rip + 0x18d0c]
000079a4  4c 8d 0d 45 8d 01 00  lea r9, [rip + 0x18d45]
000079ab  e8 28 9a 00 00  call 0x113d8
000079b8  4c 8b 35 41 db 00 00  mov r14, qword ptr [rip + 0xdb41]
000079bf  4c 8b 3d 22 db 00 00  mov r15, qword ptr [rip + 0xdb22]
000079c6  74 6f  je 0x7a37
000079cf  48 c7 05 56 8d 01 00 01 00 00 00  mov qword ptr [rip + 0x18d56], 1
000079dd  7e 58  jle 0x7a37
000079e3  72 1c  jb 0x7a01
000079ed  48 8b 0d d4 d8 00 00  mov rcx, qword ptr [rip + 0xd8d4]
000079fa  e8 f1 13 00 00  call 0x8df0
000079ff  eb 2c  jmp 0x7a2d
00007a03  48 8b 0d be d8 00 00  mov rcx, qword ptr [rip + 0xd8be]
00007a2b  75 f3  jne 0x7a20
00007a30  48 89 1d f9 8c 01 00  mov qword ptr [rip + 0x18cf9], rbx
00007a47  48 8b 0d 82 d8 00 00  mov rcx, qword ptr [rip + 0xd882]
00007aba  e8 af 99 00 00  call 0x1146e
00007ac7  75 38  jne 0x7b01
00007ad1  75 2e  jne 0x7b01
00007ad3  48 8d 05 06 01 01 00  lea rax, [rip + 0x10106]
00007adf  4c 8d 05 32 01 01 00  lea r8, [rip + 0x10132]
00007aeb  48 8d 0d de 00 01 00  lea rcx, [rip + 0x100de]
00007af2  48 8d 15 df 00 01 00  lea rdx, [rip + 0x100df]
00007afc  e8 5d 9a 00 00  call 0x1155e
00007b01  48 8b 05 48 e1 00 00  mov rax, qword ptr [rip + 0xe148]
00007b3f  48 8b 05 9a d7 00 00  mov rax, qword ptr [rip + 0xd79a]
00007b4c  48 8d 0d 0d a4 01 00  lea rcx, [rip + 0x1a40d]
00007b6c  75 f2  jne 0x7b60
00007b6e  48 c7 05 b7 8b 01 00 0a 00 00 00  mov qword ptr [rip + 0x18bb7], 0xa
00007b79  48 8b 05 a8 8b 01 00  mov rax, qword ptr [rip + 0x18ba8]
00007b88  48 89 05 19 8b 01 00  mov qword ptr [rip + 0x18b19], rax
00007b92  0f 8e 06 01 00 00  jle 0x7c9e
00007b98  48 8d 0d 09 8b 01 00  lea rcx, [rip + 0x18b09]
00007b9f  e8 b0 97 00 00  call 0x11354
00007ba4  48 89 05 f5 8a 01 00  mov qword ptr [rip + 0x18af5], rax
00007bb3  0f 8e e5 00 00 00  jle 0x7c9e
00007bb9  48 c7 05 6c 8b 01 00 01 00 00 00  mov qword ptr [rip + 0x18b6c], 1
00007bc9  48 8d 1d c8 8a 01 00  lea rbx, [rip + 0x18ac8]
00007bd0  4c 8d 35 11 00 01 00  lea r14, [rip + 0x10011]
00007bd7  4c 8d 3d e2 85 01 00  lea r15, [rip + 0x185e2]
00007bde  4c 8d 25 d3 85 01 00  lea r12, [rip + 0x185d3]
00007be8  eb 56  jmp 0x7c40
00007bf9  e8 10 98 00 00  call 0x1140e
00007bfe  48 8b 05 bb 85 01 00  mov rax, qword ptr [rip + 0x185bb]
00007c05  48 8b 0d 84 8a 01 00  mov rcx, qword ptr [rip + 0x18a84]
00007c11  48 8b 05 a0 85 01 00  mov rax, qword ptr [rip + 0x185a0]
00007c29  48 8b 0d 00 8b 01 00  mov rcx, qword ptr [rip + 0x18b00]
00007c34  48 89 05 f5 8a 01 00  mov qword ptr [rip + 0x18af5], rax
00007c3e  7d 5e  jge 0x7c9e
00007c44  48 03 05 55 8a 01 00  add rax, qword ptr [rip + 0x18a55]
00007c50  48 89 05 41 8a 01 00  mov qword ptr [rip + 0x18a41], rax
00007c5a  e8 f5 96 00 00  call 0x11354
00007c5f  48 89 05 2a 8a 01 00  mov qword ptr [rip + 0x18a2a], rax
00007c74  48 89 05 45 85 01 00  mov qword ptr [rip + 0x18545], rax
00007c7e  0f 84 6c ff ff ff  je 0x7bf0
00007c87  e8 c8 96 00 00  call 0x11354
00007c8c  48 89 05 25 85 01 00  mov qword ptr [rip + 0x18525], rax
00007c9c  eb 83  jmp 0x7c21
00007c9e  48 8d 05 7b 88 01 00  lea rax, [rip + 0x1887b]
00007caa  48 8d 05 77 88 01 00  lea rax, [rip + 0x18877]
00007cb6  48 8d 05 73 88 01 00  lea rax, [rip + 0x18873]
00007cc2  4c 8d 25 77 8a 01 00  lea r12, [rip + 0x18a77]
00007cce  48 8d 0d 4b 89 01 00  lea rcx, [rip + 0x1894b]
00007cd5  4c 8d 35 e4 8a 01 00  lea r14, [rip + 0x18ae4]
00007cdc  48 8d 1d 9d 8a 01 00  lea rbx, [rip + 0x18a9d]
00007ce3  4c 8d 3d 16 89 01 00  lea r15, [rip + 0x18916]
00007cf3  e8 72 98 00 00  call 0x1156a
00007cf8  48 8b 05 31 88 01 00  mov rax, qword ptr [rip + 0x18831]
00007d06  48 8b 05 1b 88 01 00  mov rax, qword ptr [rip + 0x1881b]
00007d14  48 8b 05 05 88 01 00  mov rax, qword ptr [rip + 0x18805]
00007d22  48 8b 05 f7 88 01 00  mov rax, qword ptr [rip + 0x188f7]
00007d2c  0f 10 05 f5 88 01 00  movups xmm0, xmmword ptr [rip + 0x188f5]
00007d5a  75 e4  jne 0x7d40
00007d5e  4c 8d 2d 8b 89 01 00  lea r13, [rip + 0x1898b]
00007d8a  75 e4  jne 0x7d70
00007d8c  48 c7 05 99 89 01 00 06 00 00 00  mov qword ptr [rip + 0x18999], 6
00007d97  4c 8b 35 6a d6 00 00  mov r14, qword ptr [rip + 0xd66a]
00007da6  4c 8b 25 2b d7 00 00  mov r12, qword ptr [rip + 0xd72b]
00007dad  74 10  je 0x7dbf
00007db3  48 8b 3d de de 00 00  mov rdi, qword ptr [rip + 0xdede]
00007dba  e9 ee 03 00 00  jmp 0x81ad
00007dbf  48 8d 0d 2a fe 00 00  lea rcx, [rip + 0xfe2a]
00007dc6  e8 89 95 00 00  call 0x11354
00007dcb  4c 8b 3d 26 d7 00 00  mov r15, qword ptr [rip + 0xd726]
00007dda  48 89 05 a7 88 01 00  mov qword ptr [rip + 0x188a7], rax
00007de1  48 8d 0d a0 88 01 00  lea rcx, [rip + 0x188a0]
00007de8  e8 67 95 00 00  call 0x11354
00007e30  0f 8e 32 01 00 00  jle 0x7f68
00007e3a  72 54  jb 0x7e90
00007e5a  e8 c1 0e 00 00  call 0x8d20
00007e70  e8 ab 0e 00 00  call 0x8d20
00007e86  e8 95 0e 00 00  call 0x8d20
00007e8b  e9 d8 00 00 00  jmp 0x7f68
00007e97  74 61  je 0x7efa
00007ef1  72 cd  jb 0x7ec0
00007ef6  75 04  jne 0x7efc
00007ef8  eb 6e  jmp 0x7f68
00007f66  75 d8  jne 0x7f40
00007fb3  75 eb  jne 0x7fa0
00007fc5  48 8b 05 fc d2 00 00  mov rax, qword ptr [rip + 0xd2fc]
00007fd0  48 c7 05 55 87 01 00 01 00 00 00  mov qword ptr [rip + 0x18755], 1
00007fde  4c 8b 25 f3 d4 00 00  mov r12, qword ptr [rip + 0xd4f3]
00007fe5  4c 8d 2d 04 87 01 00  lea r13, [rip + 0x18704]
00007fec  7e 60  jle 0x804e
00007ff5  76 23  jbe 0x801a
0000800c  48 03 0d b5 d2 00 00  add rcx, qword ptr [rip + 0xd2b5]
00008013  e8 08 0d 00 00  call 0x8d20
00008018  eb 2a  jmp 0x8044
00008042  75 ec  jne 0x8030
00008047  4c 89 35 e2 86 01 00  mov qword ptr [rip + 0x186e2], r14
00008051  4c 8b 35 b0 d3 00 00  mov r14, qword ptr [rip + 0xd3b0]
00008064  48 8b 3d 2d dc 00 00  mov rdi, qword ptr [rip + 0xdc2d]
0000806b  0f 85 3c 01 00 00  jne 0x81ad
00008071  48 8b 05 b0 86 01 00  mov rax, qword ptr [rip + 0x186b0]
00008080  48 89 05 f9 85 01 00  mov qword ptr [rip + 0x185f9], rax
00008087  48 8d 0d f2 85 01 00  lea rcx, [rip + 0x185f2]
0000808e  e8 c1 92 00 00  call 0x11354
0000809b  7e 36  jle 0x80d3
000080ac  4c 8d 05 2d 85 01 00  lea r8, [rip + 0x1852d]
000080d1  7c ed  jl 0x80c0
000080db  7e 36  jle 0x8113
000080ed  4c 8d 05 cc 84 01 00  lea r8, [rip + 0x184cc]
00008111  7c ed  jl 0x8100
0000811b  7e 36  jle 0x8153
0000812d  4c 8d 05 4c 84 01 00  lea r8, [rip + 0x1844c]
00008151  7c ed  jl 0x8140
0000815d  48 c7 05 c8 85 01 00 01 00 00 00  mov qword ptr [rip + 0x185c8], 1
0000816b  7e 40  jle 0x81ad
00008178  48 8d 15 c1 83 01 00  lea rdx, [rip + 0x183c1]
000081a1  7c ed  jl 0x8190
000081a6  48 89 0d 83 85 01 00  mov qword ptr [rip + 0x18583], rcx
000081ad  48 8b 05 74 85 01 00  mov rax, qword ptr [rip + 0x18574]
000081bc  48 89 05 b5 84 01 00  mov qword ptr [rip + 0x184b5], rax
000081c3  48 c7 05 a2 84 01 00 01 00 00 00  mov qword ptr [rip + 0x184a2], 1
000081d1  74 36  je 0x8209
000081d3  48 8d 1d 9e 84 01 00  lea rbx, [rip + 0x1849e]
000081dd  e8 72 91 00 00  call 0x11354
000081e2  48 89 05 87 84 01 00  mov qword ptr [rip + 0x18487], rax
000081ec  e8 7f 93 00 00  call 0x11570
000081f1  48 8b 0d 78 84 01 00  mov rcx, qword ptr [rip + 0x18478]
000081f8  48 8b 15 f9 d2 00 00  mov rdx, qword ptr [rip + 0xd2f9]
00008207  eb 05  jmp 0x820e
00008214  48 89 05 4d 84 01 00  mov qword ptr [rip + 0x1844d], rax
0000821b  48 8d 15 46 84 01 00  lea rdx, [rip + 0x18446]
00008226  4c 8d 0d cb f9 00 00  lea r9, [rip + 0xf9cb]
0000822d  e8 bc 93 00 00  call 0x115ee
00008232  48 8b 05 ef 84 01 00  mov rax, qword ptr [rip + 0x184ef]
00008241  48 89 0d 18 84 01 00  mov qword ptr [rip + 0x18418], rcx
0000824b  74 53  je 0x82a0
0000824d  48 8d 0d 0c 84 01 00  lea rcx, [rip + 0x1840c]
00008254  e8 fb 90 00 00  call 0x11354
00008259  48 8b 0d 98 d2 00 00  mov rcx, qword ptr [rip + 0xd298]
00008276  4c 8b 05 33 da 00 00  mov r8, qword ptr [rip + 0xda33]
00008299  48 8b 05 88 84 01 00  mov rax, qword ptr [rip + 0x18488]
000082a0  48 8b 15 39 d0 00 00  mov rdx, qword ptr [rip + 0xd039]
000082bd  48 8b 3d 34 d2 00 00  mov rdi, qword ptr [rip + 0xd234]
000082cc  48 8d 0d 2d f9 00 00  lea rcx, [rip + 0xf92d]
000082d3  48 8d 35 96 83 01 00  lea rsi, [rip + 0x18396]
000082dd  e8 2c 91 00 00  call 0x1140e
000082e2  48 8b 05 3f 84 01 00  mov rax, qword ptr [rip + 0x1843f]
000082f4  48 8d 0d 0d f9 00 00  lea rcx, [rip + 0xf90d]
000082fe  e8 0b 91 00 00  call 0x1140e
00008303  48 8b 0d ee cf 00 00  mov rcx, qword ptr [rip + 0xcfee]
00008333  48 8b 05 ee 83 01 00  mov rax, qword ptr [rip + 0x183ee]
00008381  75 0c  jne 0x838f
00008383  e8 34 97 00 00  call 0x11abc
00008388  48 8b 05 99 83 01 00  mov rax, qword ptr [rip + 0x18399]
00008397  48 89 05 82 83 01 00  mov qword ptr [rip + 0x18382], rax
0000839e  48 8d 0d 7b 83 01 00  lea rcx, [rip + 0x1837b]
000083a5  e8 aa 8f 00 00  call 0x11354
000083aa  48 89 05 67 83 01 00  mov qword ptr [rip + 0x18367], rax
000083bd  48 8b 05 64 83 01 00  mov rax, qword ptr [rip + 0x18364]
000083cc  48 89 05 85 82 01 00  mov qword ptr [rip + 0x18285], rax
000083d3  48 8d 0d 7e 82 01 00  lea rcx, [rip + 0x1827e]
000083da  e8 75 8f 00 00  call 0x11354
000083df  48 89 05 6a 82 01 00  mov qword ptr [rip + 0x1826a], rax
000083eb  48 89 05 26 81 01 00  mov qword ptr [rip + 0x18126], rax
000083f2  48 8b 35 f7 d0 00 00  mov rsi, qword ptr [rip + 0xd0f7]
00008404  74 0c  je 0x8412
00008406  48 8b 0d e3 d0 00 00  mov rcx, qword ptr [rip + 0xd0e3]
0000840d  e8 6a 91 00 00  call 0x1157c
00008412  48 8d 0d f7 f7 00 00  lea rcx, [rip + 0xf7f7]
00008419  e8 36 8f 00 00  call 0x11354
0000841e  48 89 05 f3 82 01 00  mov qword ptr [rip + 0x182f3], rax
0000842e  74 27  je 0x8457
0000843b  48 8d 15 2e 82 01 00  lea rdx, [rip + 0x1822e]
00008442  4c 8d 05 67 82 01 00  lea r8, [rip + 0x18267]
00008449  4c 8d 0d a0 82 01 00  lea r9, [rip + 0x182a0]
00008450  e8 83 8f 00 00  call 0x113d8
00008455  eb 68  jmp 0x84bf
00008457  48 8d 0d c2 f7 00 00  lea rcx, [rip + 0xf7c2]
0000845e  e8 1f 91 00 00  call 0x11582
00008473  48 8b 15 9e 82 01 00  mov rdx, qword ptr [rip + 0x1829e]
00008491  48 8d 05 18 82 01 00  lea rax, [rip + 0x18218]
0000849d  4c 8d 0d cc 81 01 00  lea r9, [rip + 0x181cc]
000084ae  e8 8d 90 00 00  call 0x11540
000084b3  48 8d 0d 5e f7 00 00  lea rcx, [rip + 0xf75e]
000084ba  e8 c3 90 00 00  call 0x11582
000084bf  48 8b 05 82 d7 00 00  mov rax, qword ptr [rip + 0xd782]
000084e4  48 8d 35 85 81 01 00  lea rsi, [rip + 0x18185]
000084eb  48 8b 15 7e 81 01 00  mov rdx, qword ptr [rip + 0x1817e]
00008508  48 8d 1d a1 81 01 00  lea rbx, [rip + 0x181a1]
0000850f  48 8b 15 9a 81 01 00  mov rdx, qword ptr [rip + 0x1819a]
0000852c  48 8d 05 25 7f 01 00  lea rax, [rip + 0x17f25]
00008538  48 8d 0d 31 7f 01 00  lea rcx, [rip + 0x17f31]
0000853f  48 8d 15 32 7f 01 00  lea rdx, [rip + 0x17f32]
00008546  4c 8d 05 1b 7f 01 00  lea r8, [rip + 0x17f1b]
0000854d  4c 8d 0d 0c 7f 01 00  lea r9, [rip + 0x17f0c]
00008554  e8 2f 90 00 00  call 0x11588
00008559  48 8b 05 18 7f 01 00  mov rax, qword ptr [rip + 0x17f18]
00008560  48 8b 15 b1 7f 01 00  mov rdx, qword ptr [rip + 0x17fb1]
0000856e  48 89 05 d3 80 01 00  mov qword ptr [rip + 0x180d3], rax
00008575  48 8d 0d cc 80 01 00  lea rcx, [rip + 0x180cc]
0000857c  48 8b 05 ed 7e 01 00  mov rax, qword ptr [rip + 0x17eed]
0000858e  48 89 05 ab 80 01 00  mov qword ptr [rip + 0x180ab], rax
00008595  48 8d 15 a4 80 01 00  lea rdx, [rip + 0x180a4]
000085a6  4c 8d 05 bb 7b 01 00  lea r8, [rip + 0x17bbb]
000085b0  e8 8b 8f 00 00  call 0x11540
000085b5  48 8b 0d b4 80 01 00  mov rcx, qword ptr [rip + 0x180b4]
000085c0  48 89 05 39 7a 01 00  mov qword ptr [rip + 0x17a39], rax
000085c7  48 8b 05 4a 7f 01 00  mov rax, qword ptr [rip + 0x17f4a]
000085d3  48 89 0d 86 7b 01 00  mov qword ptr [rip + 0x17b86], rcx
000085da  48 8b 0d cf 80 01 00  mov rcx, qword ptr [rip + 0x180cf]
000085e5  48 89 15 34 7a 01 00  mov qword ptr [rip + 0x17a34], rdx
000085f2  48 89 0d 47 7a 01 00  mov qword ptr [rip + 0x17a47], rcx
000085fc  48 89 0d 5d 7a 01 00  mov qword ptr [rip + 0x17a5d], rcx
00008606  48 89 0d 73 7a 01 00  mov qword ptr [rip + 0x17a73], rcx
00008610  48 89 0d 89 7a 01 00  mov qword ptr [rip + 0x17a89], rcx
0000861a  48 89 0d 9f 7a 01 00  mov qword ptr [rip + 0x17a9f], rcx
00008624  48 89 0d b5 7a 01 00  mov qword ptr [rip + 0x17ab5], rcx
0000862e  48 89 0d cb 7a 01 00  mov qword ptr [rip + 0x17acb], rcx
00008638  48 89 0d e1 7a 01 00  mov qword ptr [rip + 0x17ae1], rcx
00008642  48 89 0d f7 7a 01 00  mov qword ptr [rip + 0x17af7], rcx
0000864c  48 89 0d 2d 7b 01 00  mov qword ptr [rip + 0x17b2d], rcx
00008653  48 c7 05 42 7e 01 00 00 00 00 00  mov qword ptr [rip + 0x17e42], 0
0000865e  48 c7 05 2f 7e 01 00 00 00 00 00  mov qword ptr [rip + 0x17e2f], 0
00008669  48 8b 05 b8 80 01 00  mov rax, qword ptr [rip + 0x180b8]
00008675  48 89 05 4c 7b 01 00  mov qword ptr [rip + 0x17b4c], rax
0000867f  74 32  je 0x86b3
00008681  48 8d 0d 40 7b 01 00  lea rcx, [rip + 0x17b40]
00008688  e8 c7 8c 00 00  call 0x11354
00008697  48 89 0d 02 7e 01 00  mov qword ptr [rip + 0x17e02], rcx
0000869e  48 89 05 f3 7d 01 00  mov qword ptr [rip + 0x17df3], rax
000086a8  74 09  je 0x86b3
000086ad  0f 85 8e 00 00 00  jne 0x8741
000086b3  48 8b 0d 96 7f 01 00  mov rcx, qword ptr [rip + 0x17f96]
000086c4  48 89 05 c5 7d 01 00  mov qword ptr [rip + 0x17dc5], rax
000086d0  4c 89 05 b1 7d 01 00  mov qword ptr [rip + 0x17db1], r8
000086e2  48 89 0d 97 7d 01 00  mov qword ptr [rip + 0x17d97], rcx
000086ec  7e 22  jle 0x8710
000086f6  48 8d 0d 83 7d 01 00  lea rcx, [rip + 0x17d83]
000086fd  48 8d 15 9c 7d 01 00  lea rdx, [rip + 0x17d9c]
00008704  e8 2f 8d 00 00  call 0x11438
00008709  48 8b 05 80 7d 01 00  mov rax, qword ptr [rip + 0x17d80]
00008713  7e 22  jle 0x8737
00008715  48 03 05 6c 7d 01 00  add rax, qword ptr [rip + 0x17d6c]
00008726  48 8d 15 6b 7d 01 00  lea rdx, [rip + 0x17d6b]
00008732  e8 01 8d 00 00  call 0x11438
00008737  48 83 3d 61 7d 01 00 00  cmp qword ptr [rip + 0x17d61], 0
0000873f  74 14  je 0x8755
00008741  48 8d 0d 58 7d 01 00  lea rcx, [rip + 0x17d58]
00008748  e8 bb 8c 00 00  call 0x11408
00008755  48 83 3d 3b 7d 01 00 00  cmp qword ptr [rip + 0x17d3b], 0
0000875d  74 11  je 0x8770
0000875f  48 8d 0d 32 7d 01 00  lea rcx, [rip + 0x17d32]
00008766  e8 9d 8c 00 00  call 0x11408
00008770  80 3d 81 7a 01 00 00  cmp byte ptr [rip + 0x17a81], 0
00008777  75 23  jne 0x879c
00008781  48 8d 0d 98 f4 00 00  lea rcx, [rip + 0xf498]
00008788  e8 67 8e 00 00  call 0x115f4
00008795  c6 05 5c 7a 01 00 01  mov byte ptr [rip + 0x17a5c], 1
0000879c  e8 c1 8c 00 00  call 0x11462
000087a9  75 05  jne 0x87b0
000087ab  e8 12 93 00 00  call 0x11ac2
000087d0  48 83 ec 28  sub rsp, 0x28
000087d4  48 8b 05 15 cd 00 00  mov rax, qword ptr [rip + 0xcd15]
000087de  48 89 05 f3 7f 01 00  mov qword ptr [rip + 0x17ff3], rax
000087e5  48 8d 0d 7c 79 01 00  lea rcx, [rip + 0x1797c]
000087ec  48 8d 15 fd 7f 01 00  lea rdx, [rip + 0x17ffd]
000087f3  4c 8d 05 ee 7f 01 00  lea r8, [rip + 0x17fee]
000087fa  4c 8d 0d df 7f 01 00  lea r9, [rip + 0x17fdf]
00008801  e8 d2 8b 00 00  call 0x113d8
00008806  48 8b 0d e3 7f 01 00  mov rcx, qword ptr [rip + 0x17fe3]
00008811  48 89 05 e8 77 01 00  mov qword ptr [rip + 0x177e8], rax
00008818  48 8b 05 b9 7f 01 00  mov rax, qword ptr [rip + 0x17fb9]
00008824  48 89 0d 35 79 01 00  mov qword ptr [rip + 0x17935], rcx
0000882b  48 8b 0d b6 7f 01 00  mov rcx, qword ptr [rip + 0x17fb6]
00008836  48 89 15 e3 77 01 00  mov qword ptr [rip + 0x177e3], rdx
00008843  48 89 0d f6 77 01 00  mov qword ptr [rip + 0x177f6], rcx
0000884d  48 89 0d 0c 78 01 00  mov qword ptr [rip + 0x1780c], rcx
00008857  48 89 0d 22 78 01 00  mov qword ptr [rip + 0x17822], rcx
00008861  48 89 0d 38 78 01 00  mov qword ptr [rip + 0x17838], rcx
0000886b  48 89 0d 4e 78 01 00  mov qword ptr [rip + 0x1784e], rcx
00008875  48 89 0d 64 78 01 00  mov qword ptr [rip + 0x17864], rcx
0000887f  48 89 0d 7a 78 01 00  mov qword ptr [rip + 0x1787a], rcx
00008889  48 89 0d 90 78 01 00  mov qword ptr [rip + 0x17890], rcx
00008893  48 89 0d a6 78 01 00  mov qword ptr [rip + 0x178a6], rcx
0000889d  48 89 0d dc 78 01 00  mov qword ptr [rip + 0x178dc], rcx
000088b0  56  push rsi
000088c2  48 8b 1d 27 cc 00 00  mov rbx, qword ptr [rip + 0xcc27]
000088d1  48 89 05 40 7f 01 00  mov qword ptr [rip + 0x17f40], rax
000088d8  48 8d 05 39 7f 01 00  lea rax, [rip + 0x17f39]
000088ed  48 89 0d 1c 7f 01 00  mov qword ptr [rip + 0x17f1c], rcx
000088f4  48 8d 15 15 7f 01 00  lea rdx, [rip + 0x17f15]
000088fb  48 8d 0d f6 7e 01 00  lea rcx, [rip + 0x17ef6]
00008907  48 8d 0d f2 7e 01 00  lea rcx, [rip + 0x17ef2]
00008913  4c 8d 0d ee 7e 01 00  lea r9, [rip + 0x17eee]
0000891d  e8 1e 8c 00 00  call 0x11540
00008922  48 8b 0d df 7e 01 00  mov rcx, qword ptr [rip + 0x17edf]
0000892d  48 89 05 cc 76 01 00  mov qword ptr [rip + 0x176cc], rax
0000893f  48 8b 0d ba 7e 01 00  mov rcx, qword ptr [rip + 0x17eba]
0000894a  48 89 15 cf 76 01 00  mov qword ptr [rip + 0x176cf], rdx
00008957  48 89 0d e2 76 01 00  mov qword ptr [rip + 0x176e2], rcx
00008961  48 89 0d f8 76 01 00  mov qword ptr [rip + 0x176f8], rcx
0000896b  48 89 0d 0e 77 01 00  mov qword ptr [rip + 0x1770e], rcx
00008975  48 89 0d 24 77 01 00  mov qword ptr [rip + 0x17724], rcx
0000897f  48 89 0d 3a 77 01 00  mov qword ptr [rip + 0x1773a], rcx
00008989  48 89 0d 50 77 01 00  mov qword ptr [rip + 0x17750], rcx
00008993  48 89 0d 66 77 01 00  mov qword ptr [rip + 0x17766], rcx
0000899d  48 89 0d 7c 77 01 00  mov qword ptr [rip + 0x1777c], rcx
000089a7  48 89 0d 92 77 01 00  mov qword ptr [rip + 0x17792], rcx
000089c0  41 57  push r15
000089eb  48 8b 05 4e c8 00 00  mov rax, qword ptr [rip + 0xc84e]
000089f9  48 8b 05 f8 c8 00 00  mov rax, qword ptr [rip + 0xc8f8]
00008a25  48 8b 05 ec c8 00 00  mov rax, qword ptr [rip + 0xc8ec]
00008a3b  48 8b 05 96 ca 00 00  mov rax, qword ptr [rip + 0xca96]
00008a4d  4c 8b 25 04 c8 00 00  mov r12, qword ptr [rip + 0xc804]
00008a65  e8 b6 02 00 00  call 0x8d20
00008a73  4c 8d 25 86 7e 01 00  lea r12, [rip + 0x17e86]
00008a86  e8 95 02 00 00  call 0x8d20
00008a93  e8 fc 8a 00 00  call 0x11594
00008aa0  e8 f5 8a 00 00  call 0x1159a
00008ab6  4c 8d 05 78 f1 00 00  lea r8, [rip + 0xf178]
00008ac8  e8 4f 90 00 00  call 0x11b1c
00008ad3  48 89 05 56 7d 01 00  mov qword ptr [rip + 0x17d56], rax
00008ada  48 8d 0d 4f 7d 01 00  lea rcx, [rip + 0x17d4f]
00008ae1  e8 ba 8a 00 00  call 0x115a0
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
00008b48  48 89 0d e9 7c 01 00  mov qword ptr [rip + 0x17ce9], rcx
00008b4f  48 8d 15 e2 7c 01 00  lea rdx, [rip + 0x17ce2]
00008b6a  e8 df 87 00 00  call 0x1134e
00008b6f  48 c7 05 a6 7c 01 00 00 00 00 00  mov qword ptr [rip + 0x17ca6], 0
00008b7a  48 8d 05 9f 7c 01 00  lea rax, [rip + 0x17c9f]
00008b97  e8 14 da ff ff  call 0x65b0
00008b9c  48 83 3d 7c 7c 01 00 00  cmp qword ptr [rip + 0x17c7c], 0
00008ba4  0f 85 45 01 00 00  jne 0x8cef
00008baa  48 8d 35 9f f0 00 00  lea rsi, [rip + 0xf09f]
00008bb4  e8 ed 89 00 00  call 0x115a6
00008bb9  4c 8b 3d 80 c7 00 00  mov r15, qword ptr [rip + 0xc780]
00008bc8  48 8d 15 71 f0 00 00  lea rdx, [rip + 0xf071]
00008bcf  48 8d 1d 58 f0 00 00  lea rbx, [rip + 0xf058]
00008be2  e8 cb 89 00 00  call 0x115b2
00008be7  4c 8d 35 5a f0 00 00  lea r14, [rip + 0xf05a]
00008bee  4c 8d 05 33 f0 00 00  lea r8, [rip + 0xf033]
00008c01  e8 ac 89 00 00  call 0x115b2
00008c12  e8 a1 89 00 00  call 0x115b8
00008c24  e8 95 89 00 00  call 0x115be
00008c29  e8 d2 83 ff ff  call 0x1000
00008c2e  e8 9d 87 ff ff  call 0x13d0
00008c36  e8 19 87 00 00  call 0x11354
00008c3b  48 8b 35 b6 c8 00 00  mov rsi, qword ptr [rip + 0xc8b6]
00008c4a  48 89 05 ef 7b 01 00  mov qword ptr [rip + 0x17bef], rax
00008c51  48 8d 0d e8 7b 01 00  lea rcx, [rip + 0x17be8]
00008c58  e8 f7 86 00 00  call 0x11354
00008c67  48 8b 15 d2 cf 00 00  mov rdx, qword ptr [rip + 0xcfd2]
00008c7f  75 ef  jne 0x8c70
00008c81  48 83 3d a7 7b 01 00 01  cmp qword ptr [rip + 0x17ba7], 1
00008c89  75 64  jne 0x8cef
00008c8b  48 c7 05 92 7b 01 00 00 00 00 00  mov qword ptr [rip + 0x17b92], 0
00008c96  48 8d 35 8b 7b 01 00  lea rsi, [rip + 0x17b8b]
00008c9d  48 8d 0d fc 5a 01 00  lea rcx, [rip + 0x15afc]
00008ca4  48 8d 15 b5 5a 01 00  lea rdx, [rip + 0x15ab5]
00008cae  e8 11 89 00 00  call 0x115c4
00008cb3  48 8b 15 ae c7 00 00  mov rdx, qword ptr [rip + 0xc7ae]
00008cea  e8 db 88 00 00  call 0x115ca
00008d00  48 8d 05 99 01 00 00  lea rax, [rip + 0x199]
00008d10  48 8d 05 a9 19 00 00  lea rax, [rip + 0x19a9]
00008d20  48 8b 05 69 7d 01 00  mov rax, qword ptr [rip + 0x17d69]
00008d2a  0f 84 10 00 00 00  je 0x8d40
00008d30  48 ff e0  jmp rax
00008d40  56  push rsi
00008d47  48 8b 05 62 7d 01 00  mov rax, qword ptr [rip + 0x17d62]
00008d51  75 07  jne 0x8d5a
00008d53  e8 28 44 00 00  call 0xd180
00008d58  eb ed  jmp 0x8d47
00008d6d  75 10  jne 0x8d7f
00008d78  e8 93 ff ff ff  call 0x8d10
00008d7d  eb 1d  jmp 0x8d9c
00008d8c  75 19  jne 0x8da7
00008d97  e8 64 ff ff ff  call 0x8d00
00008da5  eb 16  jmp 0x8dbd
00008dab  4c 8d 0d be 9e 00 00  lea r9, [rip + 0x9ebe]
00008db2  48 8d 05 e1 b9 00 00  lea rax, [rip + 0xb9e1]
00008dbd  48 89 05 cc 7c 01 00  mov qword ptr [rip + 0x17ccc], rax
00008dcb  48 ff e0  jmp rax
00008dd0  48 8d 05 69 52 00 00  lea rax, [rip + 0x5269]
00008de0  48 8d 05 19 63 00 00  lea rax, [rip + 0x6319]
00008df0  48 8b 05 a1 7c 01 00  mov rax, qword ptr [rip + 0x17ca1]
00008dfa  0f 84 10 00 00 00  je 0x8e10
00008e00  48 ff e0  jmp rax
00008e10  56  push rsi
00008e17  48 8b 05 92 7c 01 00  mov rax, qword ptr [rip + 0x17c92]
00008e21  75 07  jne 0x8e2a
00008e23  e8 58 43 00 00  call 0xd180
00008e28  eb ed  jmp 0x8e17
00008e3d  75 0f  jne 0x8e4e
00008e47  e8 94 ff ff ff  call 0x8de0
00008e4c  eb 1c  jmp 0x8e6a
00008e5b  75 17  jne 0x8e74
00008e65  e8 66 ff ff ff  call 0x8dd0
00008e72  eb 16  jmp 0x8e8a
00008e78  4c 8d 0d a1 ae 00 00  lea r9, [rip + 0xaea1]
00008e7f  48 8d 05 0e b9 00 00  lea rax, [rip + 0xb90e]
00008e8a  48 89 05 07 7c 01 00  mov qword ptr [rip + 0x17c07], rax
00008e98  48 ff e0  jmp rax
00008ea0  41 56  push r14
00008eb2  77 1c  ja 0x8ed0
00008eb4  4c 8d 0d d5 0f 00 00  lea r9, [rip + 0xfd5]
00008ebf  3e 41 ff e1  notrack jmp r9
00008ed0  4c 8d 0d b9 06 00 00  lea r9, [rip + 0x6b9]
00008ede  74 26  je 0x8f06
00008efa  3e 41 ff e1  notrack jmp r9
00008f0d  0f 8c 6d 02 00 00  jl 0x9180
00008f13  4c 8b 0d 6e 59 01 00  mov r9, qword ptr [rip + 0x1596e]
00008f27  0f 83 a3 00 00 00  jae 0x8fd0
00008fba  0f 83 70 ff ff ff  jae 0x8f30
00008fc0  e9 bb 01 00 00  jmp 0x9180
00008fd0  4c 3b 05 a1 58 01 00  cmp r8, qword ptr [rip + 0x158a1]
00008fd7  73 17  jae 0x8ff0
00008feb  e9 b0 16 00 00  jmp 0xa6a0
00009096  0f 8d 54 ff ff ff  jge 0x8ff0
0000909f  e9 8c fe ff ff  jmp 0x8f30
000090b6  e9 45 fe ff ff  jmp 0x8f00
000090c8  e9 33 fe ff ff  jmp 0x8f00
000090e0  e9 1b fe ff ff  jmp 0x8f00
000090f6  e9 05 fe ff ff  jmp 0x8f00
0000910e  e9 ed fd ff ff  jmp 0x8f00
00009126  e9 d5 fd ff ff  jmp 0x8f00
0000913e  e9 bd fd ff ff  jmp 0x8f00
00009159  e9 a2 fd ff ff  jmp 0x8f00
00009174  e9 87 fd ff ff  jmp 0x8f00
00009199  4c 8d 0d f0 04 00 00  lea r9, [rip + 0x4f0]
000091a4  3e 41 ff e1  notrack jmp r9
0000920f  4c 8d 0d 7a 04 00 00  lea r9, [rip + 0x47a]
0000921d  3e 41 ff e1  notrack jmp r9
00009236  e9 65 14 00 00  jmp 0xa6a0
00009240  e9 5b 14 00 00  jmp 0xa6a0
00009258  e9 43 14 00 00  jmp 0xa6a0
00009270  e9 2b 14 00 00  jmp 0xa6a0
00009286  e9 15 14 00 00  jmp 0xa6a0
000092a0  e9 fb 13 00 00  jmp 0xa6a0
000092b6  e9 e5 13 00 00  jmp 0xa6a0
000092d0  e9 cb 13 00 00  jmp 0xa6a0
000092e9  e9 b2 13 00 00  jmp 0xa6a0
00009307  e9 94 13 00 00  jmp 0xa6a0
00009327  e9 74 13 00 00  jmp 0xa6a0
00009352  e9 49 13 00 00  jmp 0xa6a0
0000938d  e9 0e 13 00 00  jmp 0xa6a0
000093d8  e9 c3 12 00 00  jmp 0xa6a0
00009429  e9 72 12 00 00  jmp 0xa6a0
0000948a  e9 11 12 00 00  jmp 0xa6a0
000094fb  e9 a0 11 00 00  jmp 0xa6a0
00009588  e9 13 11 00 00  jmp 0xa6a0
0000a6c0  56  push rsi
0000a6c4  4c 8d 0d f5 16 00 00  lea r9, [rip + 0x16f5]
0000a6d2  7d 13  jge 0xa6e7
0000a6e4  41 ff e1  jmp r9
0000a6e7  4c 8d 0d d2 04 00 00  lea r9, [rip + 0x4d2]
0000a6fc  74 1c  je 0xa71a
0000a711  41 ff e1  jmp r9
0000a721  0f 8c 00 03 00 00  jl 0xaa27
0000a727  4c 3b 05 4a 41 01 00  cmp r8, qword ptr [rip + 0x1414a]
0000a72e  0f 83 cd 00 00 00  jae 0xa801
0000a7f6  0f 8d 38 ff ff ff  jge 0xa734
0000a7fc  e9 26 02 00 00  jmp 0xaa27
0000a964  0f 8d 38 ff ff ff  jge 0xa8a2
0000a96d  e9 b5 00 00 00  jmp 0xaa27
0000a978  e9 97 fd ff ff  jmp 0xa714
0000a985  e9 8a fd ff ff  jmp 0xa714
0000a99a  e9 75 fd ff ff  jmp 0xa714
0000a9a5  e9 6a fd ff ff  jmp 0xa714
0000a9b8  e9 57 fd ff ff  jmp 0xa714
0000a9c3  e9 4c fd ff ff  jmp 0xa714
0000a9d6  e9 39 fd ff ff  jmp 0xa714
0000a9e3  e9 2c fd ff ff  jmp 0xa714
0000a9fc  e9 13 fd ff ff  jmp 0xa714
0000aa09  e9 06 fd ff ff  jmp 0xa714
0000aa22  e9 ed fc ff ff  jmp 0xa714
0000aa46  4c 8d 0d 73 03 00 00  lea r9, [rip + 0x373]
0000aa51  41 ff e1  jmp r9
0000aab6  4c 8d 0d 03 03 00 00  lea r9, [rip + 0x303]
0000aac1  41 ff e1  jmp r9
0000aaca  e9 f1 16 00 00  jmp 0xc1c0
0000aacf  e9 ec 16 00 00  jmp 0xc1c0
0000aadc  e9 df 16 00 00  jmp 0xc1c0
0000aaf1  e9 ca 16 00 00  jmp 0xc1c0
0000aafc  e9 bf 16 00 00  jmp 0xc1c0
0000ab0f  e9 ac 16 00 00  jmp 0xc1c0
0000ab1a  e9 a1 16 00 00  jmp 0xc1c0
0000ab2d  e9 8e 16 00 00  jmp 0xc1c0
0000ab3a  e9 81 16 00 00  jmp 0xc1c0
0000ab53  e9 68 16 00 00  jmp 0xc1c0
0000ab60  e9 5b 16 00 00  jmp 0xc1c0
0000ab79  e9 42 16 00 00  jmp 0xc1c0
0000ab8a  e9 31 16 00 00  jmp 0xc1c0
0000aba9  e9 12 16 00 00  jmp 0xc1c0
0000c1d0  50  push rax
0000c1d6  e8 15 00 00 00  call 0xc1f0
0000c1f0  41 53  push r11
0000c239  48 8b 05 c0 25 01 00  mov rax, qword ptr [rip + 0x125c0]
0000c25d  e8 7e 1d 00 00  call 0xdfe0
0000c267  0f 85 39 06 00 00  jne 0xc8a6
0000c286  0f 84 0b 06 00 00  je 0xc897
0000c28f  75 2a  jne 0xc2bb
0000c299  0f 85 f8 05 00 00  jne 0xc897
0000c2a7  0f 85 ea 05 00 00  jne 0xc897
0000c2b5  0f 85 dc 05 00 00  jne 0xc897
0000c2c8  74 1a  je 0xc2e4
0000c2d4  e8 07 1d 00 00  call 0xdfe0
0000c2de  0f 85 c2 05 00 00  jne 0xc8a6
0000c2e7  79 1a  jns 0xc303
0000c2f3  e8 e8 1c 00 00  call 0xdfe0
0000c2fd  0f 85 a3 05 00 00  jne 0xc8a6
0000c307  73 1a  jae 0xc323
0000c313  e8 c8 1c 00 00  call 0xdfe0
0000c31d  0f 85 83 05 00 00  jne 0xc8a6
0000c327  0f 82 d1 05 00 00  jb 0xc8fe
0000c332  73 1a  jae 0xc34e
0000c33e  e8 9d 1c 00 00  call 0xdfe0
0000c348  0f 85 58 05 00 00  jne 0xc8a6
0000c352  72 10  jb 0xc364
0000c36e  75 1a  jne 0xc38a
0000c37a  e8 61 1c 00 00  call 0xdfe0
0000c384  0f 85 1c 05 00 00  jne 0xc8a6
0000c38e  74 1a  je 0xc3aa
0000c39a  e8 41 1c 00 00  call 0xdfe0
0000c3a4  0f 85 fc 04 00 00  jne 0xc8a6
0000c3ae  74 1a  je 0xc3ca
0000c3ba  e8 21 1c 00 00  call 0xdfe0
0000c3c4  0f 85 dc 04 00 00  jne 0xc8a6
0000c3cf  73 1a  jae 0xc3eb
0000c3db  e8 00 1c 00 00  call 0xdfe0
0000c3e5  0f 85 bb 04 00 00  jne 0xc8a6
0000c3f0  73 1a  jae 0xc40c
0000c3fc  e8 df 1b 00 00  call 0xdfe0
0000c406  0f 85 9a 04 00 00  jne 0xc8a6
0000c411  73 1a  jae 0xc42d
0000c41d  e8 be 1b 00 00  call 0xdfe0
0000c427  0f 85 79 04 00 00  jne 0xc8a6
0000c432  73 1a  jae 0xc44e
0000c43e  e8 9d 1b 00 00  call 0xdfe0
0000c448  0f 85 58 04 00 00  jne 0xc8a6
0000c458  74 1a  je 0xc474
0000c464  e8 77 1b 00 00  call 0xdfe0
0000c46e  0f 85 32 04 00 00  jne 0xc8a6
0000c47f  73 1a  jae 0xc49b
0000c48b  e8 50 1b 00 00  call 0xdfe0
0000c495  0f 85 0b 04 00 00  jne 0xc8a6
0000c49f  74 1a  je 0xc4bb
0000c4ab  e8 30 1b 00 00  call 0xdfe0
0000c4b5  0f 85 eb 03 00 00  jne 0xc8a6
0000c4be  79 1a  jns 0xc4da
0000c4ca  e8 11 1b 00 00  call 0xdfe0
0000c4d4  0f 85 cc 03 00 00  jne 0xc8a6
0000c4de  73 1a  jae 0xc4fa
0000c4ea  e8 f1 1a 00 00  call 0xdfe0
0000c4f4  0f 85 ac 03 00 00  jne 0xc8a6
0000c4fe  73 1a  jae 0xc51a
0000c50a  e8 d1 1a 00 00  call 0xdfe0
0000c514  0f 85 8c 03 00 00  jne 0xc8a6
0000c51e  73 1a  jae 0xc53a
0000c52a  e8 b1 1a 00 00  call 0xdfe0
0000c534  0f 85 6c 03 00 00  jne 0xc8a6
0000c53e  73 1a  jae 0xc55a
0000c54a  e8 91 1a 00 00  call 0xdfe0
0000c554  0f 85 4c 03 00 00  jne 0xc8a6
0000c55e  73 1a  jae 0xc57a
0000c56a  e8 71 1a 00 00  call 0xdfe0
0000c574  0f 85 2c 03 00 00  jne 0xc8a6
0000c57e  73 1a  jae 0xc59a
0000c58a  e8 51 1a 00 00  call 0xdfe0
0000c594  0f 85 0c 03 00 00  jne 0xc8a6
0000c59e  73 1a  jae 0xc5ba
0000c5aa  e8 31 1a 00 00  call 0xdfe0
0000c5b4  0f 85 ec 02 00 00  jne 0xc8a6
0000c5be  73 1a  jae 0xc5da
0000c5ca  e8 11 1a 00 00  call 0xdfe0
0000c5d4  0f 85 cc 02 00 00  jne 0xc8a6
0000c5e6  74 1a  je 0xc602
0000c5f2  e8 e9 19 00 00  call 0xdfe0
0000c5fc  0f 85 a4 02 00 00  jne 0xc8a6
0000c606  0f 82 91 04 00 00  jb 0xca9d
0000c622  73 1a  jae 0xc63e
0000c62e  e8 ad 19 00 00  call 0xdfe0
0000c638  0f 85 68 02 00 00  jne 0xc8a6
0000c642  74 1a  je 0xc65e
0000c64e  e8 8d 19 00 00  call 0xdfe0
0000c658  0f 85 48 02 00 00  jne 0xc8a6
0000c663  73 1a  jae 0xc67f
0000c66f  e8 6c 19 00 00  call 0xdfe0
0000c679  0f 85 27 02 00 00  jne 0xc8a6
0000c682  79 1a  jns 0xc69e
0000c68e  e8 4d 19 00 00  call 0xdfe0
0000c698  0f 85 08 02 00 00  jne 0xc8a6
0000c6a2  74 1a  je 0xc6be
0000c6ae  e8 2d 19 00 00  call 0xdfe0
0000c6b8  0f 85 e8 01 00 00  jne 0xc8a6
0000c6c2  79 1a  jns 0xc6de
0000c6ce  e8 0d 19 00 00  call 0xdfe0
0000c6d8  0f 85 c8 01 00 00  jne 0xc8a6
0000c6e3  73 1a  jae 0xc6ff
0000c6ef  e8 ec 18 00 00  call 0xdfe0
0000c6f9  0f 85 a7 01 00 00  jne 0xc8a6
0000c704  73 1a  jae 0xc720
0000c710  e8 cb 18 00 00  call 0xdfe0
0000c71a  0f 85 86 01 00 00  jne 0xc8a6
0000c725  73 1a  jae 0xc741
0000c731  e8 aa 18 00 00  call 0xdfe0
0000c73b  0f 85 65 01 00 00  jne 0xc8a6
0000c744  74 1a  je 0xc760
0000c750  e8 8b 18 00 00  call 0xdfe0
0000c75a  0f 85 46 01 00 00  jne 0xc8a6
0000c765  0f 82 9c 03 00 00  jb 0xcb07
0000c770  0f 82 fd 03 00 00  jb 0xcb73
0000c776  48 8d 0d f3 b4 00 00  lea rcx, [rip + 0xb4f3]
0000c77d  e8 66 80 00 00  call 0x147e8
0000c785  0f 84 81 07 00 00  je 0xcf0c
0000c792  0f 84 74 07 00 00  je 0xcf0c
0000c79b  4c 8d 0d 2e 43 01 00  lea r9, [rip + 0x1432e]
0000c7bb  75 0f  jne 0xc7cc
0000c7ca  eb ed  jmp 0xc7b9
0000c7d1  0f 84 21 07 00 00  je 0xcef8
0000c7e6  74 09  je 0xc7f1
0000c7ea  74 05  je 0xc7f1
0000c7ef  eb e9  jmp 0xc7da
0000c7fa  74 73  je 0xc86f
0000c7fc  80 3d bd 42 01 00 00  cmp byte ptr [rip + 0x142bd], 0
0000c803  75 05  jne 0xc80a
0000c805  e8 b6 09 00 00  call 0xd1c0
0000c828  74 3c  je 0xc866
0000c82d  74 21  je 0xc850
0000c83b  75 29  jne 0xc866
0000c846  75 1e  jne 0xc866
0000c84e  75 e2  jne 0xc832
0000c853  74 0a  je 0xc85f
0000c85d  75 07  jne 0xc866
0000c864  74 1b  je 0xc881
0000c86d  75 ad  jne 0xc81c
0000c876  0f 85 2e ff ff ff  jne 0xc7aa
0000c87c  e9 77 06 00 00  jmp 0xcef8
0000c884  72 e9  jb 0xc86f
0000c889  e8 52 17 00 00  call 0xdfe0
0000c895  eb d8  jmp 0xc86f
0000c89c  0f 29 05 fd 41 01 00  movaps xmmword ptr [rip + 0x141fd], xmm0
0000c8ae  e8 7d 7f 00 00  call 0x14830
0000c908  e8 d3 16 00 00  call 0xdfe0
0000c912  75 92  jne 0xc8a6
0000c918  73 1a  jae 0xc934
0000c924  e8 b7 16 00 00  call 0xdfe0
0000c92e  0f 85 72 ff ff ff  jne 0xc8a6
0000c938  73 1a  jae 0xc954
0000c944  e8 97 16 00 00  call 0xdfe0
0000c94e  0f 85 52 ff ff ff  jne 0xc8a6
0000c958  74 1a  je 0xc974
0000c964  e8 77 16 00 00  call 0xdfe0
0000c96e  0f 85 32 ff ff ff  jne 0xc8a6
0000c979  73 1a  jae 0xc995
0000c985  e8 56 16 00 00  call 0xdfe0
0000c98f  0f 85 11 ff ff ff  jne 0xc8a6
0000c99a  73 1a  jae 0xc9b6
0000c9a6  e8 35 16 00 00  call 0xdfe0
0000c9b0  0f 85 f0 fe ff ff  jne 0xc8a6
0000c9bb  73 1a  jae 0xc9d7
0000c9c7  e8 14 16 00 00  call 0xdfe0
0000c9d1  0f 85 cf fe ff ff  jne 0xc8a6
0000c9dc  73 1a  jae 0xc9f8
0000c9e8  e8 f3 15 00 00  call 0xdfe0
0000c9f2  0f 85 ae fe ff ff  jne 0xc8a6
0000c9fd  73 1a  jae 0xca19
0000ca09  e8 d2 15 00 00  call 0xdfe0
0000ca13  0f 85 8d fe ff ff  jne 0xc8a6
0000ca1d  74 1a  je 0xca39
0000ca29  e8 b2 15 00 00  call 0xdfe0
0000ca33  0f 85 6d fe ff ff  jne 0xc8a6
0000ca3e  73 1a  jae 0xca5a
0000ca4a  e8 91 15 00 00  call 0xdfe0
0000ca54  0f 85 4c fe ff ff  jne 0xc8a6
0000ca71  72 08  jb 0xca7b
0000ca76  e9 b2 f8 ff ff  jmp 0xc32d
0000ca85  e8 56 15 00 00  call 0xdfe0
0000ca92  0f 85 0e fe ff ff  jne 0xc8a6
0000ca98  e9 90 f8 ff ff  jmp 0xc32d
0000caa7  e8 34 15 00 00  call 0xdfe0
0000cab1  0f 85 ef fd ff ff  jne 0xc8a6
0000cac3  74 1a  je 0xcadf
0000cacf  e8 0c 15 00 00  call 0xdfe0
0000cad9  0f 85 c7 fd ff ff  jne 0xc8a6
0000cae2  0f 84 24 fb ff ff  je 0xc60c
0000caf2  e8 e9 14 00 00  call 0xdfe0
0000cafc  0f 85 a4 fd ff ff  jne 0xc8a6
0000cb02  e9 05 fb ff ff  jmp 0xc60c
0000cb11  e8 ca 14 00 00  call 0xdfe0
0000cb1b  0f 85 85 fd ff ff  jne 0xc8a6
0000cb2e  73 1a  jae 0xcb4a
0000cb3a  e8 a1 14 00 00  call 0xdfe0
0000cb44  0f 85 5c fd ff ff  jne 0xc8a6
0000cb4e  0f 83 17 fc ff ff  jae 0xc76b
0000cb5e  e8 7d 14 00 00  call 0xdfe0
0000cb68  0f 85 38 fd ff ff  jne 0xc8a6
0000cb6e  e9 f8 fb ff ff  jmp 0xc76b
0000cb7d  e8 5e 14 00 00  call 0xdfe0
0000cb87  0f 85 19 fd ff ff  jne 0xc8a6
0000cb9c  75 24  jne 0xcbc2
0000cba8  e8 33 14 00 00  call 0xdfe0
0000cbb2  0f 85 ee fc ff ff  jne 0xc8a6
0000cbbc  0f 82 92 03 00 00  jb 0xcf54
0000cbc5  0f 85 ab fb ff ff  jne 0xc776
0000cbd5  e8 06 14 00 00  call 0xdfe0
0000cbdf  0f 85 c1 fc ff ff  jne 0xc8a6
0000cbea  0f 82 09 04 00 00  jb 0xcff9
0000cbf5  73 1a  jae 0xcc11
0000cc01  e8 da 13 00 00  call 0xdfe0
0000cc0b  0f 85 95 fc ff ff  jne 0xc8a6
0000cc15  0f 85 61 04 00 00  jne 0xd07c
0000cc20  73 1a  jae 0xcc3c
0000cc2c  e8 af 13 00 00  call 0xdfe0
0000cc36  0f 85 6a fc ff ff  jne 0xc8a6
0000cc3f  75 3b  jne 0xcc7c
0000cc4b  e8 90 13 00 00  call 0xdfe0
0000cc55  0f 85 4b fc ff ff  jne 0xc8a6
0000cc60  73 1a  jae 0xcc7c
0000cc6c  e8 6f 13 00 00  call 0xdfe0
0000cc76  0f 85 2a fc ff ff  jne 0xc8a6
0000cc80  74 1a  je 0xcc9c
0000cc8c  e8 4f 13 00 00  call 0xdfe0
0000cc96  0f 85 0a fc ff ff  jne 0xc8a6
0000cc9f  0f 85 d1 fa ff ff  jne 0xc776
0000ccaf  e8 2c 13 00 00  call 0xdfe0
0000ccb9  0f 85 e7 fb ff ff  jne 0xc8a6
0000ccc4  73 1a  jae 0xcce0
0000ccd0  e8 0b 13 00 00  call 0xdfe0
0000ccda  0f 85 c6 fb ff ff  jne 0xc8a6
0000cce5  73 1a  jae 0xcd01
0000ccf1  e8 ea 12 00 00  call 0xdfe0
0000ccfb  0f 85 a5 fb ff ff  jne 0xc8a6
0000cd06  73 1a  jae 0xcd22
0000cd12  e8 c9 12 00 00  call 0xdfe0
0000cd1c  0f 85 84 fb ff ff  jne 0xc8a6
0000cd27  73 1a  jae 0xcd43
0000cd33  e8 a8 12 00 00  call 0xdfe0
0000cd3d  0f 85 63 fb ff ff  jne 0xc8a6
0000cd48  73 1a  jae 0xcd64
0000cd54  e8 87 12 00 00  call 0xdfe0
0000cd5e  0f 85 42 fb ff ff  jne 0xc8a6
0000cd69  73 1a  jae 0xcd85
0000cd75  e8 66 12 00 00  call 0xdfe0
0000cd7f  0f 85 21 fb ff ff  jne 0xc8a6
0000cd88  0f 88 d3 03 00 00  js 0xd161
0000cd93  73 1a  jae 0xcdaf
0000cd9f  e8 3c 12 00 00  call 0xdfe0
0000cda9  0f 85 f7 fa ff ff  jne 0xc8a6
0000cdb3  74 1a  je 0xcdcf
0000cdbf  e8 1c 12 00 00  call 0xdfe0
0000cdc9  0f 85 d7 fa ff ff  jne 0xc8a6
0000cdd3  73 1a  jae 0xcdef
0000cddf  e8 fc 11 00 00  call 0xdfe0
0000cde9  0f 85 b7 fa ff ff  jne 0xc8a6
0000cdf3  74 1a  je 0xce0f
0000cdff  e8 dc 11 00 00  call 0xdfe0
0000ce09  0f 85 97 fa ff ff  jne 0xc8a6
0000ce13  74 1a  je 0xce2f
0000ce1f  e8 bc 11 00 00  call 0xdfe0
0000ce29  0f 85 77 fa ff ff  jne 0xc8a6
0000ce33  73 1a  jae 0xce4f
0000ce3f  e8 9c 11 00 00  call 0xdfe0
0000ce49  0f 85 57 fa ff ff  jne 0xc8a6
0000ce53  74 1a  je 0xce6f
0000ce5f  e8 7c 11 00 00  call 0xdfe0
0000ce69  0f 85 37 fa ff ff  jne 0xc8a6
0000ce73  73 1a  jae 0xce8f
0000ce7f  e8 5c 11 00 00  call 0xdfe0
0000ce89  0f 85 17 fa ff ff  jne 0xc8a6
0000ce93  74 1a  je 0xceaf
0000ce9f  e8 3c 11 00 00  call 0xdfe0
0000cea9  0f 85 f7 f9 ff ff  jne 0xc8a6
0000ceb3  73 1a  jae 0xcecf
0000cebf  e8 1c 11 00 00  call 0xdfe0
0000cec9  0f 85 d7 f9 ff ff  jne 0xc8a6
0000ced3  0f 83 9d f8 ff ff  jae 0xc776
0000cee3  e8 f8 10 00 00  call 0xdfe0
0000ceed  0f 85 b3 f9 ff ff  jne 0xc8a6
0000cef3  e9 7e f8 ff ff  jmp 0xc776
0000cefb  7e 0f  jle 0xcf0c
0000cf14  75 26  jne 0xcf3c
0000cf16  48 89 05 8b 3b 01 00  mov qword ptr [rip + 0x13b8b], rax
0000cf22  48 89 0d 77 3b 01 00  mov qword ptr [rip + 0x13b77], rcx
0000cf29  48 89 05 88 3b 01 00  mov qword ptr [rip + 0x13b88], rax
0000cf30  48 89 0d 79 3b 01 00  mov qword ptr [rip + 0x13b79], rcx
0000cf37  e9 67 f9 ff ff  jmp 0xc8a3
0000cf3c  48 89 05 75 3b 01 00  mov qword ptr [rip + 0x13b75], rax
0000cf48  48 89 05 61 3b 01 00  mov qword ptr [rip + 0x13b61], rax
0000cf4f  e9 4f f9 ff ff  jmp 0xc8a3
0000cf5e  e8 7d 10 00 00  call 0xdfe0
0000cf68  0f 85 38 f9 ff ff  jne 0xc8a6
0000cf73  73 1a  jae 0xcf8f
0000cf7f  e8 5c 10 00 00  call 0xdfe0
0000cf89  0f 85 17 f9 ff ff  jne 0xc8a6
0000cf94  73 1a  jae 0xcfb0
0000cfa0  e8 3b 10 00 00  call 0xdfe0
0000cfaa  0f 85 f6 f8 ff ff  jne 0xc8a6
0000cfb4  73 1a  jae 0xcfd0
0000cfc0  e8 1b 10 00 00  call 0xdfe0
0000cfca  0f 85 d6 f8 ff ff  jne 0xc8a6
0000cfd4  0f 83 e8 fb ff ff  jae 0xcbc2
0000cfe4  e8 f7 0f 00 00  call 0xdfe0
0000cfee  0f 85 b2 f8 ff ff  jne 0xc8a6
0000cff4  e9 c9 fb ff ff  jmp 0xcbc2
0000d003  e8 d8 0f 00 00  call 0xdfe0
0000d00d  0f 85 93 f8 ff ff  jne 0xc8a6
0000d017  73 1a  jae 0xd033
0000d023  e8 b8 0f 00 00  call 0xdfe0
0000d02d  0f 85 73 f8 ff ff  jne 0xc8a6
0000d037  73 1a  jae 0xd053
0000d043  e8 98 0f 00 00  call 0xdfe0
0000d04d  0f 85 53 f8 ff ff  jne 0xc8a6
0000d057  0f 84 93 fb ff ff  je 0xcbf0
0000d067  e8 74 0f 00 00  call 0xdfe0
0000d071  0f 85 2f f8 ff ff  jne 0xc8a6
0000d077  e9 74 fb ff ff  jmp 0xcbf0
0000d086  e8 55 0f 00 00  call 0xdfe0
0000d090  0f 85 10 f8 ff ff  jne 0xc8a6
0000d09a  74 1a  je 0xd0b6
0000d0a6  e8 35 0f 00 00  call 0xdfe0
0000d0b0  0f 85 f0 f7 ff ff  jne 0xc8a6
0000d0bb  73 1a  jae 0xd0d7
0000d0c7  e8 14 0f 00 00  call 0xdfe0
0000d0d1  0f 85 cf f7 ff ff  jne 0xc8a6
0000d0db  74 1a  je 0xd0f7
0000d0e7  e8 f4 0e 00 00  call 0xdfe0
0000d0f1  0f 85 af f7 ff ff  jne 0xc8a6
0000d0fb  74 1a  je 0xd117
0000d107  e8 d4 0e 00 00  call 0xdfe0
0000d111  0f 85 8f f7 ff ff  jne 0xc8a6
0000d11b  74 1a  je 0xd137
0000d127  e8 b4 0e 00 00  call 0xdfe0
0000d131  0f 85 6f f7 ff ff  jne 0xc8a6
0000d13c  0f 83 d9 fa ff ff  jae 0xcc1b
0000d14c  e8 8f 0e 00 00  call 0xdfe0
0000d156  0f 85 4a f7 ff ff  jne 0xc8a6
0000d15c  e9 ba fa ff ff  jmp 0xcc1b
0000d16b  e8 70 0e 00 00  call 0xdfe0
0000d175  0f 85 2b f7 ff ff  jne 0xc8a6
0000d17b  e9 0e fc ff ff  jmp 0xcd8e
0000d180  50  push rax
0000d183  e8 68 f0 ff ff  call 0xc1f0
0000d190  50  push rax
0000d191  80 3d 28 39 01 00 00  cmp byte ptr [rip + 0x13928], 0
0000d198  75 05  jne 0xd19f
0000d19a  e8 21 00 00 00  call 0xd1c0
0000d1a6  48 8d 0d 23 39 01 00  lea rcx, [rip + 0x13923]
0000d1c0  52  push rdx
0000d1c2  80 3d f7 38 01 00 00  cmp byte ptr [rip + 0x138f7], 0
0000d1c9  0f 85 7e 0d 00 00  jne 0xdf4d
0000d1d4  48 8d 0d f5 38 01 00  lea rcx, [rip + 0x138f5]
0000d211  75 cd  jne 0xd1e0
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
