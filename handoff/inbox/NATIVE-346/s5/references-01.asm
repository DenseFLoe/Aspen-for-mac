00001000  41 57  push r15
0000100d  48 8d 0d 6c 4d 01 00  lea rcx, [rip + 0x14d6c]
00001014  e8 3b 03 01 00  call 0x11354
00001019  48 89 05 50 d9 01 00  mov qword ptr [rip + 0x1d950], rax
00001020  4c 8b 35 d9 44 01 00  mov r14, qword ptr [rip + 0x144d9]
0000102b  48 89 0d c6 d8 01 00  mov qword ptr [rip + 0x1d8c6], rcx
0000103a  48 8b 0d cf 45 01 00  mov rcx, qword ptr [rip + 0x145cf]
00001048  4c 8b 3d a9 44 01 00  mov r15, qword ptr [rip + 0x144a9]
00001057  48 89 05 0a d9 01 00  mov qword ptr [rip + 0x1d90a], rax
0000105e  48 8d 0d 03 d9 01 00  lea rcx, [rip + 0x1d903]
00001065  e8 ea 02 01 00  call 0x11354
0000106f  48 8b 15 7a 44 01 00  mov rdx, qword ptr [rip + 0x1447a]
000010da  48 8b 1d 27 45 01 00  mov rbx, qword ptr [rip + 0x14527]
000010f0  48 8b 35 f1 43 01 00  mov rsi, qword ptr [rip + 0x143f1]
000010fa  4c 8b 25 df 43 01 00  mov r12, qword ptr [rip + 0x143df]
00001112  48 8b 3d bf 43 01 00  mov rdi, qword ptr [rip + 0x143bf]
00001130  48 8b 05 39 d8 01 00  mov rax, qword ptr [rip + 0x1d839]
0000113f  48 89 05 ba d7 01 00  mov qword ptr [rip + 0x1d7ba], rax
00001146  48 8d 0d b3 d7 01 00  lea rcx, [rip + 0x1d7b3]
0000114d  e8 02 02 01 00  call 0x11354
00001162  e8 19 1a 00 00  call 0x2b80
00001167  48 8d 0d 9a d7 01 00  lea rcx, [rip + 0x1d79a]
0000116e  e8 5d 04 01 00  call 0x115d0
00001173  48 83 3d 8d d7 01 00 00  cmp qword ptr [rip + 0x1d78d], 0
0000117b  7e 08  jle 0x1185
00001185  e8 86 44 00 00  call 0x5610
0000118a  48 8b 05 df d7 01 00  mov rax, qword ptr [rip + 0x1d7df]
00001191  48 8b 0d e0 46 01 00  mov rcx, qword ptr [rip + 0x146e0]
000011af  48 8b 0d 1a 43 01 00  mov rcx, qword ptr [rip + 0x1431a]
000011d9  48 89 05 80 d7 01 00  mov qword ptr [rip + 0x1d780], rax
000011e0  48 8d 15 79 d7 01 00  lea rdx, [rip + 0x1d779]
000011e7  48 8b 0d da 42 01 00  mov rcx, qword ptr [rip + 0x142da]
000011ee  4c 8d 05 93 4b 01 00  lea r8, [rip + 0x14b93]
000011f5  4c 8d 0d 94 4b 01 00  lea r9, [rip + 0x14b94]
000011fc  e8 89 01 01 00  call 0x1138a
00001201  48 8b 05 68 d7 01 00  mov rax, qword ptr [rip + 0x1d768]
00001210  48 89 05 41 d7 01 00  mov qword ptr [rip + 0x1d741], rax
0000121a  74 38  je 0x1254
0000121c  48 8d 0d 35 d7 01 00  lea rcx, [rip + 0x1d735]
00001223  e8 2c 01 01 00  call 0x11354
0000122e  75 24  jne 0x1254
00001235  48 89 05 14 d7 01 00  mov qword ptr [rip + 0x1d714], rax
0000123c  48 8d 0d 0d d7 01 00  lea rcx, [rip + 0x1d70d]
00001243  e8 84 07 01 00  call 0x119cc
00001248  48 8d 0d 49 4b 01 00  lea rcx, [rip + 0x14b49]
0000124f  e8 40 06 01 00  call 0x11894
00001254  48 8b 05 15 d7 01 00  mov rax, qword ptr [rip + 0x1d715]
00001263  48 89 05 de d6 01 00  mov qword ptr [rip + 0x1d6de], rax
0000126d  74 23  je 0x1292
0000126f  48 8d 0d d2 d6 01 00  lea rcx, [rip + 0x1d6d2]
00001276  e8 d9 00 01 00  call 0x11354
00001284  75 0c  jne 0x1292
00001286  48 8d 0d 0b 4b 01 00  lea rcx, [rip + 0x14b0b]
0000128d  e8 34 07 01 00  call 0x119c6
00001292  e8 39 49 00 00  call 0x5bd0
0000129f  48 8b 05 ca d6 01 00  mov rax, qword ptr [rip + 0x1d6ca]
000012ae  48 89 05 8b d6 01 00  mov qword ptr [rip + 0x1d68b], rax
000012b5  48 8d 0d 84 d6 01 00  lea rcx, [rip + 0x1d684]
000012bc  e8 93 00 01 00  call 0x11354
000012c1  48 89 05 70 d6 01 00  mov qword ptr [rip + 0x1d670], rax
000012cd  4c 89 25 3c d6 01 00  mov qword ptr [rip + 0x1d63c], r12
000012d4  48 c7 05 51 d6 01 00 01 00 00 00  mov qword ptr [rip + 0x1d651], 1
000012e2  0f 8e 9d 00 00 00  jle 0x1385
000012ed  48 8d 35 34 d6 01 00  lea rsi, [rip + 0x1d634]
000012f4  48 8d 3d 25 d6 01 00  lea rdi, [rip + 0x1d625]
000012fb  48 8d 1d 16 d6 01 00  lea rbx, [rip + 0x1d616]
00001305  eb 1c  jmp 0x1323
00001314  4c 89 05 15 d6 01 00  mov qword ptr [rip + 0x1d615], r8
00001321  7d 62  jge 0x1385
00001333  75 db  jne 0x1310
00001341  48 89 05 e0 d5 01 00  mov qword ptr [rip + 0x1d5e0], rax
00001352  48 89 05 c7 d5 01 00  mov qword ptr [rip + 0x1d5c7], rax
00001359  48 89 0d b8 d5 01 00  mov qword ptr [rip + 0x1d5b8], rcx
00001369  e8 f2 01 00 00  call 0x1560
0000136e  48 8b 05 c3 d5 01 00  mov rax, qword ptr [rip + 0x1d5c3]
00001375  48 8b 15 94 d5 01 00  mov rdx, qword ptr [rip + 0x1d594]
0000137c  48 8b 0d ad d5 01 00  mov rcx, qword ptr [rip + 0x1d5ad]
00001383  eb 8b  jmp 0x1310
00001385  e8 06 00 01 00  call 0x11390
0000138d  0f 29 05 4c d5 01 00  movaps xmmword ptr [rip + 0x1d54c], xmm0
00001394  0f 29 05 35 d5 01 00  movaps xmmword ptr [rip + 0x1d535], xmm0
0000139b  0f 29 05 1e d5 01 00  movaps xmmword ptr [rip + 0x1d51e], xmm0
000013a2  c7 05 44 d5 01 00 00 00 00 00  mov dword ptr [rip + 0x1d544], 0
000013ac  48 8b 05 45 d5 01 00  mov rax, qword ptr [rip + 0x1d545]
000013c4  e9 e7 06 01 00  jmp 0x11ab0
000013d0  41 56  push r14
000013d9  48 8d 0d c0 49 01 00  lea rcx, [rip + 0x149c0]
000013e0  e8 6f ff 00 00  call 0x11354
000013e5  4c 8b 35 0c 41 01 00  mov r14, qword ptr [rip + 0x1410c]
000013f4  48 89 05 7d d5 01 00  mov qword ptr [rip + 0x1d57d], rax
000013fe  0f 84 30 01 00 00  je 0x1534
00001404  48 8d 0d 6d d5 01 00  lea rcx, [rip + 0x1d56d]
0000140b  e8 44 ff 00 00  call 0x11354
0000141b  48 8b 3d 9e 48 01 00  mov rdi, qword ptr [rip + 0x1489e]
0000142e  e8 ed 78 00 00  call 0x8d20
00001457  75 e7  jne 0x1440
00001483  75 eb  jne 0x1470
000014b3  75 eb  jne 0x14a0
00001534  48 8b 05 75 3f 01 00  mov rax, qword ptr [rip + 0x13f75]
0000154c  e9 bf 16 00 00  jmp 0x2c10
00001560  41 57  push r15
0000157b  48 8b 05 26 3f 01 00  mov rax, qword ptr [rip + 0x13f26]
00001586  48 89 05 33 d6 01 00  mov qword ptr [rip + 0x1d633], rax
0000158d  48 8b 35 0c 3f 01 00  mov rsi, qword ptr [rip + 0x13f0c]
00001738  75 27  jne 0x1761
0000173d  75 22  jne 0x1761
00001747  e8 7a ff 00 00  call 0x116c6
00001761  4c 8d 15 50 49 01 00  lea r10, [rip + 0x14950]
0000176b  eb 13  jmp 0x1780
0000177e  74 36  je 0x17b6
00001784  75 ea  jne 0x1770
00001789  75 e5  jne 0x1770
00001792  77 ab  ja 0x173f
00001797  48 8d 15 22 46 01 00  lea rdx, [rip + 0x14622]
000017a5  ff e1  jmp rcx
000017af  e8 38 00 01 00  call 0x117ec
000017b4  eb 96  jmp 0x174c
000017b6  4c 8d 0d 0b d4 01 00  lea r9, [rip + 0x1d40b]
000017cb  e8 ea fe 00 00  call 0x116ba
000017d0  48 83 3d f0 d3 01 00 00  cmp qword ptr [rip + 0x1d3f0], 0
000017d8  0f 84 6e ff ff ff  je 0x174c
000017de  48 8d 05 0b 54 01 00  lea rax, [rip + 0x1540b]
000017ea  48 8d 15 f7 53 01 00  lea rdx, [rip + 0x153f7]
000017fb  4c 8b 0d d6 3c 01 00  mov r9, qword ptr [rip + 0x13cd6]
0000180f  48 8d 0d 0a c8 01 00  lea rcx, [rip + 0x1c80a]
00001816  4c 8d 05 c3 53 01 00  lea r8, [rip + 0x153c3]
0000181d  e8 86 fb 00 00  call 0x113a8
00001825  0f 84 21 ff ff ff  je 0x174c
0000185b  4c 8b 35 2e 3c 01 00  mov r14, qword ptr [rip + 0x13c2e]
0000187e  48 8d 05 d7 c7 01 00  lea rax, [rip + 0x1c7d7]
000018b2  e8 53 02 01 00  call 0x11b0a
000018b7  4c 8d 3d 72 c7 01 00  lea r15, [rip + 0x1c772]
000018e7  e8 24 02 01 00  call 0x11b10
00001942  e8 c3 01 01 00  call 0x11b0a
00001947  48 8d 0d a2 52 01 00  lea rcx, [rip + 0x152a2]
0000194e  e8 61 fa 00 00  call 0x113b4
00001953  e9 f4 fd ff ff  jmp 0x174c
00001960  e8 8d fe 00 00  call 0x117f2
00001965  e9 e2 fd ff ff  jmp 0x174c
00001972  e8 55 fd 00 00  call 0x116cc
00001977  e9 d0 fd ff ff  jmp 0x174c
00001984  e8 11 ff 00 00  call 0x1189a
00001989  e9 be fd ff ff  jmp 0x174c
00001996  e8 a7 fc 00 00  call 0x11642
0000199b  e9 ac fd ff ff  jmp 0x174c
000019a8  e8 f3 fe 00 00  call 0x118a0
000019ad  e9 9a fd ff ff  jmp 0x174c
000019ba  e8 e7 fe 00 00  call 0x118a6
000019bf  e9 88 fd ff ff  jmp 0x174c
000019cc  e8 db fe 00 00  call 0x118ac
000019d1  e9 76 fd ff ff  jmp 0x174c
000019de  e8 cf fe 00 00  call 0x118b2
000019e3  e9 64 fd ff ff  jmp 0x174c
000019f0  e8 dd fc 00 00  call 0x116d2
000019f5  e9 52 fd ff ff  jmp 0x174c
00001a02  e8 b1 fe 00 00  call 0x118b8
00001a07  e9 40 fd ff ff  jmp 0x174c
00001a14  e8 2f fc 00 00  call 0x11648
00001a19  e9 2e fd ff ff  jmp 0x174c
00001a26  e8 21 fe 00 00  call 0x1184c
00001a2b  e9 1c fd ff ff  jmp 0x174c
00001a38  e8 9b fc 00 00  call 0x116d8
00001a3d  e9 0a fd ff ff  jmp 0x174c
00001a4a  e8 83 ff 00 00  call 0x119d2
00001a4f  e9 f8 fc ff ff  jmp 0x174c
00001a5c  e8 7d fc 00 00  call 0x116de
00001a61  e9 e6 fc ff ff  jmp 0x174c
00001a6e  e8 4b fe 00 00  call 0x118be
00001a73  e9 d4 fc ff ff  jmp 0x174c
00001a80  e8 cd fd 00 00  call 0x11852
00001a85  e9 c2 fc ff ff  jmp 0x174c
00001a92  e8 41 ff 00 00  call 0x119d8
00001a97  e9 b0 fc ff ff  jmp 0x174c
00001aa4  e8 3b fc 00 00  call 0x116e4
00001aa9  e9 9e fc ff ff  jmp 0x174c
00001ab6  e8 2f fc 00 00  call 0x116ea
00001abb  e9 8c fc ff ff  jmp 0x174c
00001ac8  e8 f7 fd 00 00  call 0x118c4
00001acd  e9 7a fc ff ff  jmp 0x174c
00001ada  e8 eb fd 00 00  call 0x118ca
00001adf  e9 68 fc ff ff  jmp 0x174c
00001ae4  48 8b 15 0d 3a 01 00  mov rdx, qword ptr [rip + 0x13a0d]
00001afb  e8 de fe 00 00  call 0x119de
00001b00  e9 47 fc ff ff  jmp 0x174c
00001b0d  e8 de fb 00 00  call 0x116f0
00001b12  e9 35 fc ff ff  jmp 0x174c
00001b1f  e8 c0 fe 00 00  call 0x119e4
00001b24  e9 23 fc ff ff  jmp 0x174c
00001b31  e8 18 fb 00 00  call 0x1164e
00001b36  e9 11 fc ff ff  jmp 0x174c
00001b43  e8 b0 fc 00 00  call 0x117f8
00001b48  e9 ff fb ff ff  jmp 0x174c
00001b55  e8 76 fd 00 00  call 0x118d0
00001b5a  e9 ed fb ff ff  jmp 0x174c
00001b67  e8 ec fc 00 00  call 0x11858
00001b6c  e9 db fb ff ff  jmp 0x174c
00001b71  4c 8b 15 80 39 01 00  mov r10, qword ptr [rip + 0x13980]
00001bc2  e8 23 fe 00 00  call 0x119ea
00001bc7  e9 80 fb ff ff  jmp 0x174c
00001bd4  e8 fd fc 00 00  call 0x118d6
00001bd9  e9 6e fb ff ff  jmp 0x174c
00001be6  e8 73 fc 00 00  call 0x1185e
00001beb  e9 5c fb ff ff  jmp 0x174c
00001bf8  e8 f9 fa 00 00  call 0x116f6
00001bfd  e9 4a fb ff ff  jmp 0x174c
00001c0a  e8 ed fa 00 00  call 0x116fc
00001c0f  e9 38 fb ff ff  jmp 0x174c
00001c1c  e8 e1 fa 00 00  call 0x11702
00001c21  e9 26 fb ff ff  jmp 0x174c
00001c2e  e8 d5 fa 00 00  call 0x11708
00001c33  e9 14 fb ff ff  jmp 0x174c
00001c40  e8 2d fd 00 00  call 0x11972
00001c45  e9 02 fb ff ff  jmp 0x174c
00001c52  e8 b7 fa 00 00  call 0x1170e
00001c57  e9 f0 fa ff ff  jmp 0x174c
00001c64  e8 fb fb 00 00  call 0x11864
00001c69  e9 de fa ff ff  jmp 0x174c
00001c76  e8 61 fc 00 00  call 0x118dc
00001c7b  e9 cc fa ff ff  jmp 0x174c
00001c88  e8 87 fa 00 00  call 0x11714
00001c8d  e9 ba fa ff ff  jmp 0x174c
00001c9a  e8 43 fc 00 00  call 0x118e2
00001c9f  e9 a8 fa ff ff  jmp 0x174c
00001cac  e8 4d fb 00 00  call 0x117fe
00001cb1  e9 96 fa ff ff  jmp 0x174c
00001cbe  e8 57 fa 00 00  call 0x1171a
00001cc3  e9 84 fa ff ff  jmp 0x174c
00001cd0  e8 1b fd 00 00  call 0x119f0
00001cd5  e9 72 fa ff ff  jmp 0x174c
00001cda  4c 8b 15 17 38 01 00  mov r10, qword ptr [rip + 0x13817]
00001d46  e8 ab fc 00 00  call 0x119f6
00001d4b  e9 fc f9 ff ff  jmp 0x174c
00001d58  e8 0d fb 00 00  call 0x1186a
00001d5d  e9 ea f9 ff ff  jmp 0x174c
00001d6a  e8 09 fc 00 00  call 0x11978
00001d6f  e9 d8 f9 ff ff  jmp 0x174c
00001d7c  e8 d3 f8 00 00  call 0x11654
00001d81  e9 c6 f9 ff ff  jmp 0x174c
00001d8e  e8 8d f9 00 00  call 0x11720
00001d93  e9 b4 f9 ff ff  jmp 0x174c
00001da0  e8 81 f9 00 00  call 0x11726
00001da5  e9 a2 f9 ff ff  jmp 0x174c
00001db2  e8 4d fa 00 00  call 0x11804
00001db7  e9 90 f9 ff ff  jmp 0x174c
00001dbc  4c 8b 1d 35 37 01 00  mov r11, qword ptr [rip + 0x13735]
00001e23  e8 d4 fb 00 00  call 0x119fc
00001e28  e9 1f f9 ff ff  jmp 0x174c
00001e35  e8 c8 fb 00 00  call 0x11a02
00001e3a  e9 0d f9 ff ff  jmp 0x174c
00001e47  e8 bc fb 00 00  call 0x11a08
00001e4c  e9 fb f8 ff ff  jmp 0x174c
00001e59  e8 8a fa 00 00  call 0x118e8
00001e5e  e9 e9 f8 ff ff  jmp 0x174c
00001e6b  e8 7e fa 00 00  call 0x118ee
00001e70  e9 d7 f8 ff ff  jmp 0x174c
00001e7d  e8 d8 f7 00 00  call 0x1165a
00001e82  e9 c5 f8 ff ff  jmp 0x174c
00001e8f  e8 7a fb 00 00  call 0x11a0e
00001e94  e9 b3 f8 ff ff  jmp 0x174c
00001e99  48 8d 0d 50 4d 01 00  lea rcx, [rip + 0x14d50]
00001ea0  e8 af f4 00 00  call 0x11354
00001ea5  48 8b 3d 4c 36 01 00  mov rdi, qword ptr [rip + 0x1364c]
00001eb4  48 89 05 fd cc 01 00  mov qword ptr [rip + 0x1ccfd], rax
00001ebb  48 8d 0d f6 cc 01 00  lea rcx, [rip + 0x1ccf6]
00001ec2  e8 8d f4 00 00  call 0x11354
00001ecc  48 89 05 dd cc 01 00  mov qword ptr [rip + 0x1ccdd], rax
00001ed3  48 8d 0d d6 cc 01 00  lea rcx, [rip + 0x1ccd6]
00001efb  48 8b 05 be cc 01 00  mov rax, qword ptr [rip + 0x1ccbe]
00001f0b  e8 04 fb 00 00  call 0x11a14
00001f10  e9 37 f8 ff ff  jmp 0x174c
00001f1d  e8 d2 f9 00 00  call 0x118f4
00001f22  e9 25 f8 ff ff  jmp 0x174c
00001f2f  e8 c6 f9 00 00  call 0x118fa
00001f34  e9 13 f8 ff ff  jmp 0x174c
00001f41  e8 e6 f7 00 00  call 0x1172c
00001f46  e9 01 f8 ff ff  jmp 0x174c
00001f4b  48 8b 35 a6 35 01 00  mov rsi, qword ptr [rip + 0x135a6]
00001fdd  e8 38 fa 00 00  call 0x11a1a
00001fe2  e9 65 f7 ff ff  jmp 0x174c
00001fef  e8 3e f7 00 00  call 0x11732
00001ff4  e9 53 f7 ff ff  jmp 0x174c
00002001  e8 e0 fa 00 00  call 0x11ae6
00002006  e9 41 f7 ff ff  jmp 0x174c
00002013  e8 48 f6 00 00  call 0x11660
00002018  e9 2f f7 ff ff  jmp 0x174c
00002025  e8 0e f7 00 00  call 0x11738
0000202a  e9 1d f7 ff ff  jmp 0x174c
00002037  e8 02 f7 00 00  call 0x1173e
0000203c  e9 0b f7 ff ff  jmp 0x174c
00002049  e8 d2 f9 00 00  call 0x11a20
0000204e  e9 f9 f6 ff ff  jmp 0x174c
0000205b  e8 aa f7 00 00  call 0x1180a
00002060  e9 e7 f6 ff ff  jmp 0x174c
0000206d  e8 8e f8 00 00  call 0x11900
00002072  e9 d5 f6 ff ff  jmp 0x174c
0000207f  e8 c0 f6 00 00  call 0x11744
00002084  e9 c3 f6 ff ff  jmp 0x174c
00002089  4c 8b 05 68 34 01 00  mov r8, qword ptr [rip + 0x13468]
00002110  e8 11 f9 00 00  call 0x11a26
00002115  e9 32 f6 ff ff  jmp 0x174c
00002122  e8 23 f6 00 00  call 0x1174a
00002127  e9 20 f6 ff ff  jmp 0x174c
00002134  e8 b9 f9 00 00  call 0x11af2
00002139  e9 0e f6 ff ff  jmp 0x174c
00002146  e8 e1 f8 00 00  call 0x11a2c
0000214b  e9 fc f5 ff ff  jmp 0x174c
00002158  e8 a9 f7 00 00  call 0x11906
0000215d  e9 ea f5 ff ff  jmp 0x174c
0000216a  e8 0f f8 00 00  call 0x1197e
0000216f  e9 d8 f5 ff ff  jmp 0x174c
0000217c  e8 e5 f4 00 00  call 0x11666
00002181  e9 c6 f5 ff ff  jmp 0x174c
0000218e  e8 9f f8 00 00  call 0x11a32
0000219b  e8 d0 f6 00 00  call 0x11870
000021a0  e9 a7 f5 ff ff  jmp 0x174c
000021ad  e8 9e f5 00 00  call 0x11750
000021b2  e9 95 f5 ff ff  jmp 0x174c
000021bf  e8 74 f8 00 00  call 0x11a38
000021c4  e9 83 f5 ff ff  jmp 0x174c
000021d1  e8 80 f5 00 00  call 0x11756
000021d6  e9 71 f5 ff ff  jmp 0x174c
000021e3  e8 56 f8 00 00  call 0x11a3e
000021e8  e9 5f f5 ff ff  jmp 0x174c
000021f5  e8 12 f7 00 00  call 0x1190c
000021fa  e9 4d f5 ff ff  jmp 0x174c
00002207  e8 06 f7 00 00  call 0x11912
0000220c  e9 3b f5 ff ff  jmp 0x174c
00002219  e8 3e f5 00 00  call 0x1175c
0000221e  e9 29 f5 ff ff  jmp 0x174c
0000222b  e8 e8 f6 00 00  call 0x11918
00002230  e9 17 f5 ff ff  jmp 0x174c
0000223d  e8 42 f7 00 00  call 0x11984
00002242  e9 05 f5 ff ff  jmp 0x174c
0000224f  e8 a4 f8 00 00  call 0x11af8
00002254  e9 f3 f4 ff ff  jmp 0x174c
00002261  e8 aa f5 00 00  call 0x11810
00002266  e9 e1 f4 ff ff  jmp 0x174c
00002273  e8 f4 f3 00 00  call 0x1166c
00002278  e9 cf f4 ff ff  jmp 0x174c
00002285  e8 e8 f3 00 00  call 0x11672
0000228a  e9 bd f4 ff ff  jmp 0x174c
00002297  e8 c6 f4 00 00  call 0x11762
0000229c  e9 ab f4 ff ff  jmp 0x174c
000022a9  e8 96 f7 00 00  call 0x11a44
000022ae  e9 99 f4 ff ff  jmp 0x174c
000022bb  e8 b8 f3 00 00  call 0x11678
000022c0  e9 87 f4 ff ff  jmp 0x174c
000022cd  e8 1a f8 00 00  call 0x11aec
000022d2  e9 75 f4 ff ff  jmp 0x174c
000022df  e8 92 f5 00 00  call 0x11876
000022e4  e9 63 f4 ff ff  jmp 0x174c
000022f1  e8 72 f4 00 00  call 0x11768
000022f6  e9 51 f4 ff ff  jmp 0x174c
000022fb  4c 8b 15 f6 31 01 00  mov r10, qword ptr [rip + 0x131f6]
00002390  e8 b5 f6 00 00  call 0x11a4a
00002395  e9 b2 f3 ff ff  jmp 0x174c
000023a2  e8 39 f7 00 00  call 0x11ae0
000023a7  e9 a0 f3 ff ff  jmp 0x174c
000023b4  e8 d1 f5 00 00  call 0x1198a
000023b9  e9 8e f3 ff ff  jmp 0x174c
000023c6  e8 33 f7 00 00  call 0x11afe
000023cb  e9 7c f3 ff ff  jmp 0x174c
000023d8  e8 73 f6 00 00  call 0x11a50
000023dd  e9 6a f3 ff ff  jmp 0x174c
000023ea  e8 a1 f5 00 00  call 0x11990
000023ef  e9 58 f3 ff ff  jmp 0x174c
000023fc  e8 95 f5 00 00  call 0x11996
00002401  e9 46 f3 ff ff  jmp 0x174c
0000240e  e8 5b f3 00 00  call 0x1176e
00002413  e9 34 f3 ff ff  jmp 0x174c
00002420  e8 df f6 00 00  call 0x11b04
00002425  e9 22 f3 ff ff  jmp 0x174c
00002432  e8 1f f6 00 00  call 0x11a56
00002437  e9 10 f3 ff ff  jmp 0x174c
00002444  e8 2b f3 00 00  call 0x11774
00002449  e9 fe f2 ff ff  jmp 0x174c
00002456  e8 1f f3 00 00  call 0x1177a
0000245b  e9 ec f2 ff ff  jmp 0x174c
00002468  e8 ef f5 00 00  call 0x11a5c
0000246d  e9 da f2 ff ff  jmp 0x174c
0000247a  e8 fd f3 00 00  call 0x1187c
0000247f  e9 c8 f2 ff ff  jmp 0x174c
0000248c  e8 ef f2 00 00  call 0x11780
00002491  e9 b6 f2 ff ff  jmp 0x174c
0000249e  e8 e3 f2 00 00  call 0x11786
000024a3  e9 a4 f2 ff ff  jmp 0x174c
000024b0  e8 d7 f2 00 00  call 0x1178c
000024b5  e9 92 f2 ff ff  jmp 0x174c
000024c2  e8 57 f4 00 00  call 0x1191e
000024c7  e9 80 f2 ff ff  jmp 0x174c
000024d4  e8 4b f4 00 00  call 0x11924
000024d9  e9 6e f2 ff ff  jmp 0x174c
000024e6  e8 3f f4 00 00  call 0x1192a
000024eb  e9 5c f2 ff ff  jmp 0x174c
000024f8  e8 95 f2 00 00  call 0x11792
000024fd  e9 4a f2 ff ff  jmp 0x174c
0000250a  e8 07 f3 00 00  call 0x11816
0000250f  e9 38 f2 ff ff  jmp 0x174c
0000251c  e8 77 f2 00 00  call 0x11798
00002521  e9 26 f2 ff ff  jmp 0x174c
0000252e  e8 6b f2 00 00  call 0x1179e
00002533  e9 14 f2 ff ff  jmp 0x174c
00002540  e8 5f f2 00 00  call 0x117a4
00002545  e9 02 f2 ff ff  jmp 0x174c
00002552  e8 53 f2 00 00  call 0x117aa
00002557  e9 f0 f1 ff ff  jmp 0x174c
00002564  e8 47 f2 00 00  call 0x117b0
00002569  e9 de f1 ff ff  jmp 0x174c
00002576  e8 3b f2 00 00  call 0x117b6
0000257b  e9 cc f1 ff ff  jmp 0x174c
00002588  e8 d5 f4 00 00  call 0x11a62
0000258d  e9 ba f1 ff ff  jmp 0x174c
0000259a  e8 7d f2 00 00  call 0x1181c
0000259f  e9 a8 f1 ff ff  jmp 0x174c
000025ac  e8 0b f2 00 00  call 0x117bc
000025b1  e9 96 f1 ff ff  jmp 0x174c
000025be  e8 d9 f3 00 00  call 0x1199c
000025c3  e9 84 f1 ff ff  jmp 0x174c
000025d0  e8 93 f4 00 00  call 0x11a68
000025d5  e9 72 f1 ff ff  jmp 0x174c
000025e2  e8 87 f4 00 00  call 0x11a6e
000025e7  e9 60 f1 ff ff  jmp 0x174c
000025f4  e8 7b f4 00 00  call 0x11a74
000025f9  e9 4e f1 ff ff  jmp 0x174c
00002606  e8 6f f4 00 00  call 0x11a7a
0000260b  e9 3c f1 ff ff  jmp 0x174c
00002618  e8 a5 f1 00 00  call 0x117c2
0000261d  e9 2a f1 ff ff  jmp 0x174c
0000262a  e8 51 f4 00 00  call 0x11a80
0000262f  e9 18 f1 ff ff  jmp 0x174c
0000263c  e8 e1 f1 00 00  call 0x11822
00002641  e9 06 f1 ff ff  jmp 0x174c
0000264e  e8 dd f2 00 00  call 0x11930
00002653  e9 f4 f0 ff ff  jmp 0x174c
00002658  48 8d 0d a1 b9 01 00  lea rcx, [rip + 0x1b9a1]
0000265f  48 8d 35 6a c5 01 00  lea rsi, [rip + 0x1c56a]
00002669  e8 92 ef 00 00  call 0x11600
0000266e  4c 8b 05 63 2e 01 00  mov r8, qword ptr [rip + 0x12e63]
000028cb  e8 ea ea 00 00  call 0x113ba
000028d0  e9 77 ee ff ff  jmp 0x174c
000028dd  e8 54 f0 00 00  call 0x11936
000028e2  e9 65 ee ff ff  jmp 0x174c
000028ef  e8 ae f0 00 00  call 0x119a2
000028f4  e9 53 ee ff ff  jmp 0x174c
00002901  e8 22 ef 00 00  call 0x11828
00002906  e9 41 ee ff ff  jmp 0x174c
00002913  e8 b0 ee 00 00  call 0x117c8
00002918  e9 2f ee ff ff  jmp 0x174c
00002925  e8 12 f0 00 00  call 0x1193c
0000292a  e9 1d ee ff ff  jmp 0x174c
00002937  e8 f2 ee 00 00  call 0x1182e
0000293c  e9 0b ee ff ff  jmp 0x174c
00002949  e8 80 ee 00 00  call 0x117ce
0000294e  e9 f9 ed ff ff  jmp 0x174c
0000295b  e8 d4 ee 00 00  call 0x11834
00002960  e9 e7 ed ff ff  jmp 0x174c
0000296d  e8 d0 ef 00 00  call 0x11942
00002972  e9 d5 ed ff ff  jmp 0x174c
0000297f  e8 50 ee 00 00  call 0x117d4
00002984  e9 c3 ed ff ff  jmp 0x174c
00002991  e8 12 f0 00 00  call 0x119a8
00002996  e9 b1 ed ff ff  jmp 0x174c
000029a3  e8 06 f0 00 00  call 0x119ae
000029a8  e9 9f ed ff ff  jmp 0x174c
000029b5  e8 20 ee 00 00  call 0x117da
000029ba  e9 8d ed ff ff  jmp 0x174c
000029c7  e8 e8 ef 00 00  call 0x119b4
000029cc  e9 7b ed ff ff  jmp 0x174c
000029d1  48 8b 15 20 2b 01 00  mov rdx, qword ptr [rip + 0x12b20]
000029e8  e8 99 f0 00 00  call 0x11a86
000029ed  e9 5a ed ff ff  jmp 0x174c
000029fa  e8 bb ef 00 00  call 0x119ba
000029ff  e9 48 ed ff ff  jmp 0x174c
00002a04  48 8b 15 ed 2a 01 00  mov rdx, qword ptr [rip + 0x12aed]
00002a1b  e8 6c f0 00 00  call 0x11a8c
00002a28  e8 65 f0 00 00  call 0x11a92
00002a2d  e9 1a ed ff ff  jmp 0x174c
00002a3a  e8 09 ef 00 00  call 0x11948
00002a3f  e9 08 ed ff ff  jmp 0x174c
00002a4c  e8 31 ee 00 00  call 0x11882
00002a51  e9 f6 ec ff ff  jmp 0x174c
00002a5e  e8 5d ef 00 00  call 0x119c0
00002a63  e9 e4 ec ff ff  jmp 0x174c
00002a70  e8 d9 ee 00 00  call 0x1194e
00002a75  e9 d2 ec ff ff  jmp 0x174c
00002a82  e8 01 ee 00 00  call 0x11888
00002a87  e9 c0 ec ff ff  jmp 0x174c
00002a94  e8 47 ed 00 00  call 0x117e0
00002a99  e9 ae ec ff ff  jmp 0x174c
00002aa6  e8 a9 ee 00 00  call 0x11954
00002aab  e9 9c ec ff ff  jmp 0x174c
00002ab8  e8 9d ee 00 00  call 0x1195a
00002abd  e9 8a ec ff ff  jmp 0x174c
00002aca  e8 bf ed 00 00  call 0x1188e
00002acf  e9 78 ec ff ff  jmp 0x174c
00002adc  e8 05 ed 00 00  call 0x117e6
00002ae1  e9 66 ec ff ff  jmp 0x174c
00002aee  e8 47 ed 00 00  call 0x1183a
00002af3  e9 54 ec ff ff  jmp 0x174c
00002b00  e8 5b ee 00 00  call 0x11960
00002b05  e9 42 ec ff ff  jmp 0x174c
00002b12  e8 81 ef 00 00  call 0x11a98
00002b17  e9 30 ec ff ff  jmp 0x174c
00002b24  e8 3d ee 00 00  call 0x11966
00002b29  e9 1e ec ff ff  jmp 0x174c
00002b36  e8 63 ef 00 00  call 0x11a9e
00002b3b  e9 0c ec ff ff  jmp 0x174c
00002b48  e8 1f ee 00 00  call 0x1196c
00002b4d  e9 fa eb ff ff  jmp 0x174c
00002b5a  e8 e1 ec 00 00  call 0x11840
00002b5f  e9 e8 eb ff ff  jmp 0x174c
00002b6c  e8 d5 ec 00 00  call 0x11846
00002b71  e9 d6 eb ff ff  jmp 0x174c
00002b80  56  push rsi
00002b87  48 c7 05 4e c0 01 00 00 00 04 00  mov qword ptr [rip + 0x1c04e], 0x40000
00002b92  48 8d 35 47 c0 01 00  lea rsi, [rip + 0x1c047]
00002b99  48 8d 3d 60 40 01 00  lea rdi, [rip + 0x14060]
00002ba0  48 8d 1d 31 c0 01 00  lea rbx, [rip + 0x1c031]
00002bb3  e8 08 e8 00 00  call 0x113c0
00002bb8  48 8d 0d 39 40 01 00  lea rcx, [rip + 0x14039]
00002bc8  e8 f3 e7 00 00  call 0x113c0
00002bd9  e8 e2 e7 00 00  call 0x113c0
00002bde  e8 e3 e7 00 00  call 0x113c6
00002be3  e8 c8 05 00 00  call 0x31b0
00002be8  e8 83 12 00 00  call 0x3e70
00002bed  e8 3e 01 00 00  call 0x2d30
00002bf2  e8 c9 00 00 00  call 0x2cc0
00002bf7  e8 64 1b 00 00  call 0x4760
00002c04  e9 a7 16 00 00  jmp 0x42b0
00002c10  48 83 ec 38  sub rsp, 0x38
00002c14  48 c7 05 c1 f4 01 00 01 00 00 00  mov qword ptr [rip + 0x1f4c1], 1
00002c1f  48 c7 05 be f4 01 00 0a 00 00 00  mov qword ptr [rip + 0x1f4be], 0xa
00002c2a  48 c7 05 bb f4 01 00 0a 00 00 00  mov qword ptr [rip + 0x1f4bb], 0xa
00002c35  48 c7 05 b8 f4 01 00 1e 00 00 00  mov qword ptr [rip + 0x1f4b8], 0x1e
00002c40  48 8b 05 91 28 01 00  mov rax, qword ptr [rip + 0x12891]
00002c4b  48 89 05 ae f4 01 00  mov qword ptr [rip + 0x1f4ae], rax
00002c52  48 c7 05 ab f4 01 00 01 00 00 00  mov qword ptr [rip + 0x1f4ab], 1
00002c60  0f 29 05 a9 f4 01 00  movaps xmmword ptr [rip + 0x1f4a9], xmm0
00002c67  48 c7 05 c6 f4 01 00 00 00 00 00  mov qword ptr [rip + 0x1f4c6], 0
00002c7c  48 89 05 fd f3 01 00  mov qword ptr [rip + 0x1f3fd], rax
00002c83  4c 8b 05 de 27 01 00  mov r8, qword ptr [rip + 0x127de]
00002c98  48 8d 0d 69 3f 01 00  lea rcx, [rip + 0x13f69]
00002caa  e8 b1 1f 00 00  call 0x4c60
00002cc0  56  push rsi
00002cc5  48 8d 0d 44 3f 01 00  lea rcx, [rip + 0x13f44]
00002ccc  e8 83 e6 00 00  call 0x11354
00002cd1  48 8b 35 20 28 01 00  mov rsi, qword ptr [rip + 0x12820]
00002ce0  48 89 05 09 bf 01 00  mov qword ptr [rip + 0x1bf09], rax
00002ce7  48 8d 0d 02 bf 01 00  lea rcx, [rip + 0x1bf02]
00002cee  e8 61 e6 00 00  call 0x11354
00002cf8  48 89 05 e9 be 01 00  mov qword ptr [rip + 0x1bee9], rax
00002d02  7e 19  jle 0x2d1d
00002d04  48 8d 0d dd be 01 00  lea rcx, [rip + 0x1bedd]
00002d0b  e8 44 e6 00 00  call 0x11354
00002d13  48 8b 0d 46 27 01 00  mov rcx, qword ptr [rip + 0x12746]
00002d30  41 57  push r15
00002d43  48 8d 0d de 3e 01 00  lea rcx, [rip + 0x13ede]
00002d4a  e8 05 e6 00 00  call 0x11354
00002d4f  48 89 05 1a bf 01 00  mov qword ptr [rip + 0x1bf1a], rax
00002d56  48 8b 35 9b 27 01 00  mov rsi, qword ptr [rip + 0x1279b]
00002d65  48 89 05 fc be 01 00  mov qword ptr [rip + 0x1befc], rax
00002d6c  48 8d 0d f5 be 01 00  lea rcx, [rip + 0x1bef5]
00002d73  e8 dc e5 00 00  call 0x11354
00002d7d  48 89 05 dc be 01 00  mov qword ptr [rip + 0x1bedc], rax
00002d88  0f 85 07 04 00 00  jne 0x3195
00002d8e  48 8b 05 db be 01 00  mov rax, qword ptr [rip + 0x1bedb]
00002d9d  48 89 05 b4 be 01 00  mov qword ptr [rip + 0x1beb4], rax
00002da7  0f 84 e8 03 00 00  je 0x3195
00002dad  48 8d 0d a4 be 01 00  lea rcx, [rip + 0x1bea4]
00002db4  e8 9b e5 00 00  call 0x11354
00002dbe  48 89 05 3b be 01 00  mov qword ptr [rip + 0x1be3b], rax
00002dc5  48 8b 05 a4 be 01 00  mov rax, qword ptr [rip + 0x1bea4]
00002dd4  48 89 05 75 be 01 00  mov qword ptr [rip + 0x1be75], rax
00002ddb  48 8d 0d 6e be 01 00  lea rcx, [rip + 0x1be6e]
00002de2  48 8d 15 5f be 01 00  lea rdx, [rip + 0x1be5f]
00002de9  4c 8d 05 50 be 01 00  lea r8, [rip + 0x1be50]
00002df0  4c 8d 0d 41 be 01 00  lea r9, [rip + 0x1be41]
00002df7  e8 dc e5 00 00  call 0x113d8
00002dfc  48 8b 15 45 be 01 00  mov rdx, qword ptr [rip + 0x1be45]
00002e1a  4c 8b 15 cf 26 01 00  mov r10, qword ptr [rip + 0x126cf]
00002e32  48 c7 05 43 be 01 00 ff ff ff ff  mov qword ptr [rip + 0x1be43], 0xffffffffffffffff
00002e44  4c 89 1d 3d be 01 00  mov qword ptr [rip + 0x1be3d], r11
00002e4b  4c 8b 1d ae bd 01 00  mov r11, qword ptr [rip + 0x1bdae]
00002e60  4c 89 05 29 be 01 00  mov qword ptr [rip + 0x1be29], r8
00002e6a  4c 89 0d 27 be 01 00  mov qword ptr [rip + 0x1be27], r9
00002e74  4c 89 0d 25 be 01 00  mov qword ptr [rip + 0x1be25], r9
00002e7e  4c 89 0d 23 be 01 00  mov qword ptr [rip + 0x1be23], r9
00002e89  48 89 0d 20 be 01 00  mov qword ptr [rip + 0x1be20], rcx
00002e93  48 89 0d 1e be 01 00  mov qword ptr [rip + 0x1be1e], rcx
00002e9d  48 89 0d 8c bd 01 00  mov qword ptr [rip + 0x1bd8c], rcx
00002ea4  74 23  je 0x2ec9
00002ea6  48 8d 0d 6b 3d 01 00  lea rcx, [rip + 0x13d6b]
00002ead  48 8d 15 7c bd 01 00  lea rdx, [rip + 0x1bd7c]
00002eb4  4c 8d 05 6d bd 01 00  lea r8, [rip + 0x1bd6d]
00002ebb  4c 8d 0d 5e bd 01 00  lea r9, [rip + 0x1bd5e]
00002ec2  e8 f9 e4 00 00  call 0x113c0
00002ec7  eb 0b  jmp 0x2ed4
00002ec9  48 c7 05 54 bd 01 00 00 00 00 00  mov qword ptr [rip + 0x1bd54], 0
00002ed4  48 c7 05 39 bd 01 00 ff ff ff ff  mov qword ptr [rip + 0x1bd39], 0xffffffffffffffff
00002edf  48 c7 05 76 bd 01 00 01 00 00 00  mov qword ptr [rip + 0x1bd76], 1
00002eea  48 8d 2d ef b1 01 00  lea rbp, [rip + 0x1b1ef]
00002ef1  48 8d 1d 10 bd 01 00  lea rbx, [rip + 0x1bd10]
00002ef8  48 8d 3d 21 3d 01 00  lea rdi, [rip + 0x13d21]
00002eff  4c 8b 35 d2 25 01 00  mov r14, qword ptr [rip + 0x125d2]
00002f0e  4c 8d 3d ab b1 01 00  lea r15, [rip + 0x1b1ab]
00002f15  4c 8d 25 14 3d 01 00  lea r12, [rip + 0x13d14]
00002f24  eb 55  jmp 0x2f7b
00002f33  0f 84 77 01 00 00  je 0x30b0
00002f39  48 8b 0d 20 bd 01 00  mov rcx, qword ptr [rip + 0x1bd20]
00002f40  48 8d 15 39 bd 01 00  lea rdx, [rip + 0x1bd39]
00002f4c  48 03 0d d5 bc 01 00  add rcx, qword ptr [rip + 0x1bcd5]
00002f53  48 8b 15 f6 24 01 00  mov rdx, qword ptr [rip + 0x124f6]
00002f5f  48 8b 05 fa bc 01 00  mov rax, qword ptr [rip + 0x1bcfa]
00002f6a  48 89 0d ef bc 01 00  mov qword ptr [rip + 0x1bcef], rcx
00002f75  0f 8d 1a 02 00 00  jge 0x3195
00002f7b  48 8b 05 96 bc 01 00  mov rax, qword ptr [rip + 0x1bc96]
00002f86  48 89 0d 8b bc 01 00  mov qword ptr [rip + 0x1bc8b], rcx
00002f9b  e8 44 e4 00 00  call 0x113e4
00002fa0  48 89 05 69 bc 01 00  mov qword ptr [rip + 0x1bc69], rax
00002fab  7e 83  jle 0x2f30
00002fad  48 8d 05 74 3c 01 00  lea rax, [rip + 0x13c74]
00002fd4  e8 cf e3 00 00  call 0x113a8
00002fdc  74 81  je 0x2f5f
00002fde  48 8b 05 33 bc 01 00  mov rax, qword ptr [rip + 0x1bc33]
00003011  48 8b 0d 78 24 01 00  mov rcx, qword ptr [rip + 0x12478]
00003034  48 8d 05 75 b1 01 00  lea rax, [rip + 0x1b175]
0000305a  e8 ab ea 00 00  call 0x11b0a
0000305f  48 8b 05 b2 bb 01 00  mov rax, qword ptr [rip + 0x1bbb2]
00003085  e8 86 ea 00 00  call 0x11b10
0000308a  48 8b 05 7f bb 01 00  mov rax, qword ptr [rip + 0x1bb7f]
000030ab  e9 d3 00 00 00  jmp 0x3183
000030b0  4c 8d 05 71 3b 01 00  lea r8, [rip + 0x13b71]
000030d4  e8 cf e2 00 00  call 0x113a8
000030dc  0f 84 7d fe ff ff  je 0x2f5f
000030e2  48 8b 05 2f bb 01 00  mov rax, qword ptr [rip + 0x1bb2f]
00003112  48 8b 0d 77 23 01 00  mov rcx, qword ptr [rip + 0x12377]
00003135  48 8d 05 24 b0 01 00  lea rax, [rip + 0x1b024]
00003158  e8 ad e9 00 00  call 0x11b0a
0000315d  48 8b 05 b4 ba 01 00  mov rax, qword ptr [rip + 0x1bab4]
00003183  e8 88 e9 00 00  call 0x11b10
0000318b  e8 24 e2 00 00  call 0x113b4
00003190  e9 ca fd ff ff  jmp 0x2f5f
000031b0  41 57  push r15
000031c3  4c 8b 3d d6 22 01 00  mov r15, qword ptr [rip + 0x122d6]
000031d7  e8 14 5c 00 00  call 0x8df0
000031dc  48 8b 15 f5 22 01 00  mov rdx, qword ptr [rip + 0x122f5]
000031e7  48 8b 0d 52 22 01 00  mov rcx, qword ptr [rip + 0x12252]
000031fe  75 f0  jne 0x31f0
00003202  48 8b 0d 9f 22 01 00  mov rcx, qword ptr [rip + 0x1229f]
0000321f  75 ef  jne 0x3210
00003221  48 c7 05 34 c6 01 00 06 00 00 00  mov qword ptr [rip + 0x1c634], 6
0000322c  48 c7 05 31 c6 01 00 00 00 00 00  mov qword ptr [rip + 0x1c631], 0
0000323f  0f 84 88 00 00 00  je 0x32cd
00003245  48 8d 35 3c c6 01 00  lea rsi, [rip + 0x1c63c]
00003251  48 8d 0d 38 44 01 00  lea rcx, [rip + 0x14438]
00003258  48 8d 15 41 c6 01 00  lea rdx, [rip + 0x1c641]
0000325f  4c 8d 05 32 c6 01 00  lea r8, [rip + 0x1c632]
00003266  4c 8d 0d 23 c6 01 00  lea r9, [rip + 0x1c623]
0000326d  e8 7e e1 00 00  call 0x113f0
00003272  48 8b 05 1f c6 01 00  mov rax, qword ptr [rip + 0x1c61f]
00003279  48 8b 3d 78 22 01 00  mov rdi, qword ptr [rip + 0x12278]
00003288  48 89 05 f1 c5 01 00  mov qword ptr [rip + 0x1c5f1], rax
00003292  74 39  je 0x32cd
00003299  48 8d 0d e0 c5 01 00  lea rcx, [rip + 0x1c5e0]
000032a0  48 8d 15 d1 c5 01 00  lea rdx, [rip + 0x1c5d1]
000032a7  4c 8d 05 c2 c5 01 00  lea r8, [rip + 0x1c5c2]
000032ae  4c 8d 0d db c5 01 00  lea r9, [rip + 0x1c5db]
000032b5  e8 36 e1 00 00  call 0x113f0
000032ba  48 8b 05 af c5 01 00  mov rax, qword ptr [rip + 0x1c5af]
000032c6  48 89 05 9b c5 01 00  mov qword ptr [rip + 0x1c59b], rax
000032cd  48 8b 3d 5c 21 01 00  mov rdi, qword ptr [rip + 0x1215c]
000032d8  74 2c  je 0x3306
000032dd  e8 1a e1 00 00  call 0x113fc
000032f1  48 c7 05 64 c5 01 00 01 00 00 00  mov qword ptr [rip + 0x1c564], 1
00003300  0f 8d 01 0b 00 00  jge 0x3e07
00003320  48 8d 15 b9 39 01 00  lea rdx, [rip + 0x139b9]
0000334f  75 df  jne 0x3330
00003351  48 c7 05 04 c5 01 00 2f 01 00 00  mov qword ptr [rip + 0x1c504], 0x12f
0000335c  4c 8d 35 2d 43 01 00  lea r14, [rip + 0x1432d]
00003366  e8 e9 df 00 00  call 0x11354
0000336b  48 8b 1d 86 21 01 00  mov rbx, qword ptr [rip + 0x12186]
0000337a  48 89 05 d7 c4 01 00  mov qword ptr [rip + 0x1c4d7], rax
00003381  48 8d 0d d0 c4 01 00  lea rcx, [rip + 0x1c4d0]
00003388  e8 c7 df 00 00  call 0x11354
0000338d  48 89 05 bc c4 01 00  mov qword ptr [rip + 0x1c4bc], rax
00003398  48 89 0d a9 c4 01 00  mov qword ptr [rip + 0x1c4a9], rcx
0000339f  48 c7 05 96 c4 01 00 00 00 00 00  mov qword ptr [rip + 0x1c496], 0
000033aa  48 c7 05 83 c4 01 00 00 00 00 00  mov qword ptr [rip + 0x1c483], 0
000033b5  48 c7 05 70 c4 01 00 00 00 00 00  mov qword ptr [rip + 0x1c470], 0
000033c0  48 c7 05 5d c4 01 00 bf bd f0 ff  mov qword ptr [rip + 0x1c45d], 0xfffffffffff0bdbf
000033cb  48 c7 05 4a c4 01 00 ff ff ff ff  mov qword ptr [rip + 0x1c44a], 0xffffffffffffffff
000033db  48 c7 05 7a c4 01 00 01 00 00 00  mov qword ptr [rip + 0x1c47a], 1
000033e9  0f 8e 9a 07 00 00  jle 0x3b89
000033f9  4c 8d 25 10 c4 01 00  lea r12, [rip + 0x1c410]
00003400  4c 8d 2d 59 42 01 00  lea r13, [rip + 0x14259]
00003407  48 8b 05 ca 20 01 00  mov rax, qword ptr [rip + 0x120ca]
00003420  48 8b 05 69 20 01 00  mov rax, qword ptr [rip + 0x12069]
00003441  eb 38  jmp 0x347b
00003443  48 8b 0d b6 c3 01 00  mov rcx, qword ptr [rip + 0x1c3b6]
0000344a  48 8b 15 4f 20 01 00  mov rdx, qword ptr [rip + 0x1204f]
00003460  48 8b 05 f9 c3 01 00  mov rax, qword ptr [rip + 0x1c3f9]
0000346b  48 89 0d ee c3 01 00  mov qword ptr [rip + 0x1c3ee], rcx
00003475  0f 8d b6 06 00 00  jge 0x3b31
0000347b  48 8b 05 c6 c3 01 00  mov rax, qword ptr [rip + 0x1c3c6]
00003486  48 89 0d bb c3 01 00  mov qword ptr [rip + 0x1c3bb], rcx
00003498  e8 47 df 00 00  call 0x113e4
0000349d  48 89 05 74 c3 01 00  mov qword ptr [rip + 0x1c374], rax
000034a4  4c 8b 15 65 c3 01 00  mov r10, qword ptr [rip + 0x1c365]
000034af  74 af  je 0x3460
000034b6  0f 8e 94 01 00 00  jle 0x3650
000034c1  48 8d 05 c0 41 01 00  lea rax, [rip + 0x141c0]
000034dc  48 8d 0d 3d ad 01 00  lea rcx, [rip + 0x1ad3d]
000034e3  48 8d 15 96 41 01 00  lea rdx, [rip + 0x14196]
000034f2  e8 b1 de 00 00  call 0x113a8
000034fa  0f 84 60 ff ff ff  je 0x3460
00003500  48 8b 05 41 c3 01 00  mov rax, qword ptr [rip + 0x1c341]
00003533  48 8b 0d 56 1f 01 00  mov rcx, qword ptr [rip + 0x11f56]
00003556  48 8d 05 4b ad 01 00  lea rax, [rip + 0x1ad4b]
0000358d  e8 78 e5 00 00  call 0x11b0a
00003592  48 8b 05 af c2 01 00  mov rax, qword ptr [rip + 0x1c2af]
000035bd  e8 4e e5 00 00  call 0x11b10
000035c2  48 8b 05 4f c2 01 00  mov rax, qword ptr [rip + 0x1c24f]
00003611  48 8d 05 60 ac 01 00  lea rax, [rip + 0x1ac60]
00003636  e8 cf e4 00 00  call 0x11b0a
0000363e  e8 71 dd 00 00  call 0x113b4
00003643  e9 18 fe ff ff  jmp 0x3460
00003653  0f 84 07 fe ff ff  je 0x3460
00003668  48 8b 0d d9 c1 01 00  mov rcx, qword ptr [rip + 0x1c1d9]
000036b6  75 55  jne 0x370d
000036b8  48 c7 05 35 c1 01 00 01 00 00 00  mov qword ptr [rip + 0x1c135], 1
000036c8  48 8d 2d 71 35 01 00  lea rbp, [rip + 0x13571]
000036eb  74 24  je 0x3711
000036fc  75 e2  jne 0x36e0
00003704  48 8b 3d 25 1d 01 00  mov rdi, qword ptr [rip + 0x11d25]
0000370b  eb 14  jmp 0x3721
0000370f  eb 19  jmp 0x372a
00003718  48 8b 3d 11 1d 01 00  mov rdi, qword ptr [rip + 0x11d11]
0000371f  74 09  je 0x372a
00003721  4c 89 35 d0 c0 01 00  mov qword ptr [rip + 0x1c0d0], r14
00003738  4c 89 3d c9 c0 01 00  mov qword ptr [rip + 0x1c0c9], r15
00003742  74 47  je 0x378b
00003746  4c 8d 25 c3 c0 01 00  lea r12, [rip + 0x1c0c3]
0000374d  4c 8d 2d 0c 3f 01 00  lea r13, [rip + 0x13f0c]
00003754  0f 84 db 00 00 00  je 0x3835
0000375a  48 8d 0d a7 c0 01 00  lea rcx, [rip + 0x1c0a7]
00003761  e8 ee db 00 00  call 0x11354
00003766  48 8b 0d db c0 01 00  mov rcx, qword ptr [rip + 0x1c0db]
00003778  48 89 05 81 c0 01 00  mov qword ptr [rip + 0x1c081], rax
0000377f  4c 8d 35 0a 3f 01 00  lea r14, [rip + 0x13f0a]
00003786  e9 3d 02 00 00  jmp 0x39c8
0000378f  4c 8d 25 7a c0 01 00  lea r12, [rip + 0x1c07a]
00003796  4c 8d 2d c3 3e 01 00  lea r13, [rip + 0x13ec3]
0000379d  0f 85 95 01 00 00  jne 0x3938
000037a3  4c 8b 3d be c0 01 00  mov r15, qword ptr [rip + 0x1c0be]
000037ad  4c 8d 35 dc 3e 01 00  lea r14, [rip + 0x13edc]
000037b4  0f 84 cf 01 00 00  je 0x3989
000037ba  4c 8b 15 af c0 01 00  mov r10, qword ptr [rip + 0x1c0af]
000037c1  48 c7 05 2c c0 01 00 01 00 00 00  mov qword ptr [rip + 0x1c02c], 1
000037cc  0f 8e b7 01 00 00  jle 0x3989
000037e7  eb 26  jmp 0x380f
00003809  0f 84 39 02 00 00  je 0x3a48
00003812  75 dc  jne 0x37f0
00003818  75 d6  jne 0x37f0
00003823  74 07  je 0x382c
00003825  4c 89 2d cc bf 01 00  mov qword ptr [rip + 0x1bfcc], r13
00003830  e9 22 02 00 00  jmp 0x3a57
00003835  48 8b 05 24 c0 01 00  mov rax, qword ptr [rip + 0x1c024]
00003840  4c 8d 35 49 3e 01 00  lea r14, [rip + 0x13e49]
00003847  0f 84 56 01 00 00  je 0x39a3
0000384d  4c 8b 05 fc bf 01 00  mov r8, qword ptr [rip + 0x1bffc]
00003858  48 89 15 99 bf 01 00  mov qword ptr [rip + 0x1bf99], rdx
00003863  0f 8c 3a 01 00 00  jl 0x39a3
0000387c  eb 1c  jmp 0x389a
00003894  0f 84 fc 00 00 00  je 0x3996
0000389d  75 e1  jne 0x3880
000038a3  75 db  jne 0x3880
000038a8  74 07  je 0x38b1
000038aa  4c 89 15 47 bf 01 00  mov qword ptr [rip + 0x1bf47], r10
000038b1  48 8b 05 70 bf 01 00  mov rax, qword ptr [rip + 0x1bf70]
000038b8  48 89 05 41 bf 01 00  mov qword ptr [rip + 0x1bf41], rax
000038c4  48 89 05 5d bf 01 00  mov qword ptr [rip + 0x1bf5d], rax
000038cb  48 8b 0d 66 bf 01 00  mov rcx, qword ptr [rip + 0x1bf66]
000038d6  48 89 05 5b bf 01 00  mov qword ptr [rip + 0x1bf5b], rax
000038dd  48 8b 05 4c bf 01 00  mov rax, qword ptr [rip + 0x1bf4c]
000038ec  0f 8c 11 02 00 00  jl 0x3b03
000038f6  48 89 0d 33 bf 01 00  mov qword ptr [rip + 0x1bf33], rcx
000038fd  48 83 3d 3b bf 01 00 00  cmp qword ptr [rip + 0x1bf3b], 0
0000390a  0f 84 d0 01 00 00  je 0x3ae0
00003918  48 8d 0d 21 bf 01 00  lea rcx, [rip + 0x1bf21]
00003927  4c 8d 05 c2 be 01 00  lea r8, [rip + 0x1bec2]
0000392e  e8 cf da 00 00  call 0x11402
00003933  e9 cb 01 00 00  jmp 0x3b03
00003938  4c 8d 35 51 3d 01 00  lea r14, [rip + 0x13d51]
00003948  0f 85 90 00 00 00  jne 0x39de
0000394e  48 8b 05 c3 be 01 00  mov rax, qword ptr [rip + 0x1bec3]
00003963  0f 83 da fa ff ff  jae 0x3443
00003971  48 8d 15 88 be 01 00  lea rdx, [rip + 0x1be88]
00003978  e8 43 dd 00 00  call 0x116c0
0000397d  48 8b 05 94 be 01 00  mov rax, qword ptr [rip + 0x1be94]
00003984  e9 ba fa ff ff  jmp 0x3443
00003991  e9 cf 00 00 00  jmp 0x3a65
0000399c  4c 89 05 55 be 01 00  mov qword ptr [rip + 0x1be55], r8
000039a3  48 8d 0d 5e be 01 00  lea rcx, [rip + 0x1be5e]
000039aa  e8 59 da 00 00  call 0x11408
000039af  48 8b 0d 92 be 01 00  mov rcx, qword ptr [rip + 0x1be92]
000039c1  48 89 05 38 be 01 00  mov qword ptr [rip + 0x1be38], rax
000039cd  4c 8b 15 3c be 01 00  mov r10, qword ptr [rip + 0x1be3c]
000039d8  0f 84 70 ff ff ff  je 0x394e
000039e2  74 29  je 0x3a0d
000039e8  0f 85 72 fa ff ff  jne 0x3460
000039ee  48 8b 05 0b be 01 00  mov rax, qword ptr [rip + 0x1be0b]
000039f5  48 8b 0d 1c be 01 00  mov rcx, qword ptr [rip + 0x1be1c]
000039fc  48 8b 15 a5 1a 01 00  mov rdx, qword ptr [rip + 0x11aa5]
00003a08  e9 53 fa ff ff  jmp 0x3460
00003a0d  48 8b 05 ec bd 01 00  mov rax, qword ptr [rip + 0x1bdec]
00003a17  0f 84 43 fa ff ff  je 0x3460
00003a1d  48 8b 0d f4 bd 01 00  mov rcx, qword ptr [rip + 0x1bdf4]
00003a24  48 8b 15 15 1a 01 00  mov rdx, qword ptr [rip + 0x11a15]
00003a30  48 8b 05 91 b2 01 00  mov rax, qword ptr [rip + 0x1b291]
00003a37  48 8d 15 a2 b2 01 00  lea rdx, [rip + 0x1b2a2]
00003a43  e9 18 fa ff ff  jmp 0x3460
00003a48  4c 89 25 a9 bd 01 00  mov qword ptr [rip + 0x1bda9], r12
00003a57  4c 8d 25 b2 bd 01 00  lea r12, [rip + 0x1bdb2]
00003a5e  4c 8d 2d fb 3b 01 00  lea r13, [rip + 0x13bfb]
00003a6a  4c 89 05 57 b2 01 00  mov qword ptr [rip + 0x1b257], r8
00003a85  48 c7 05 70 bd 01 00 00 00 00 00  mov qword ptr [rip + 0x1bd70], 0
00003a93  0f 84 34 ff ff ff  je 0x39cd
00003a9b  74 1d  je 0x3aba
00003a9d  48 8b 05 7c bd 01 00  mov rax, qword ptr [rip + 0x1bd7c]
00003aa4  48 89 05 55 bd 01 00  mov qword ptr [rip + 0x1bd55], rax
00003aae  48 89 05 6b bd 01 00  mov qword ptr [rip + 0x1bd6b], rax
00003ab5  e9 13 ff ff ff  jmp 0x39cd
00003abd  0f 84 0a ff ff ff  je 0x39cd
00003ac3  48 8b 05 5e bd 01 00  mov rax, qword ptr [rip + 0x1bd5e]
00003aca  48 89 05 2f bd 01 00  mov qword ptr [rip + 0x1bd2f], rax
00003ad4  48 89 05 4d bd 01 00  mov qword ptr [rip + 0x1bd4d], rax
00003adb  e9 ed fe ff ff  jmp 0x39cd
00003af0  48 8d 15 49 bd 01 00  lea rdx, [rip + 0x1bd49]
00003af7  4c 8d 05 f2 bc 01 00  lea r8, [rip + 0x1bcf2]
00003afe  e8 0b d9 00 00  call 0x1140e
00003b03  48 8b 05 2e bd 01 00  mov rax, qword ptr [rip + 0x1bd2e]
00003b0d  48 03 05 dc bc 01 00  add rax, qword ptr [rip + 0x1bcdc]
00003b14  48 8b 0d fd bc 01 00  mov rcx, qword ptr [rip + 0x1bcfd]
00003b20  48 8b 0d 21 bd 01 00  mov rcx, qword ptr [rip + 0x1bd21]
00003b2c  e9 9c fe ff ff  jmp 0x39cd
00003b31  48 8b 15 f0 bc 01 00  mov rdx, qword ptr [rip + 0x1bcf0]
00003b50  4c 8b 05 c9 bc 01 00  mov r8, qword ptr [rip + 0x1bcc9]
00003b6a  4c 89 0d af bc 01 00  mov qword ptr [rip + 0x1bcaf], r9
00003b79  48 89 15 a8 bc 01 00  mov qword ptr [rip + 0x1bca8], rdx
00003b80  4c 8b 3d 19 19 01 00  mov r15, qword ptr [rip + 0x11919]
00003b87  eb 20  jmp 0x3ba9
00003b89  48 c7 05 8c bc 01 00 fa ff ff ff  mov qword ptr [rip + 0x1bc8c], 0xfffffffffffffffa
00003b94  48 c7 05 89 bc 01 00 ba bd f0 ff  mov qword ptr [rip + 0x1bc89], 0xfffffffffff0bdba
00003ba9  48 8b 35 58 18 01 00  mov rsi, qword ptr [rip + 0x11858]
00003bb8  48 89 05 29 bc 01 00  mov qword ptr [rip + 0x1bc29], rax
00003bbf  48 8d 15 22 bc 01 00  lea rdx, [rip + 0x1bc22]
00003bc6  48 8d 0d cb 3a 01 00  lea rcx, [rip + 0x13acb]
00003bcd  4c 8d 05 0c bc 01 00  lea r8, [rip + 0x1bc0c]
00003bd4  4c 8d 0d fd bb 01 00  lea r9, [rip + 0x1bbfd]
00003bdb  e8 e0 d7 00 00  call 0x113c0
00003be0  48 8b 05 f9 bb 01 00  mov rax, qword ptr [rip + 0x1bbf9]
00003be7  48 8b 0d 32 bc 01 00  mov rcx, qword ptr [rip + 0x1bc32]
00003c0c  74 07  je 0x3c15
00003c13  eb 04  jmp 0x3c19
00003c1c  48 89 05 9d b0 01 00  mov qword ptr [rip + 0x1b09d], rax
00003c23  48 8b 3d 0e bc 01 00  mov rdi, qword ptr [rip + 0x1bc0e]
00003c2d  0f 8e 02 01 00 00  jle 0x3d35
00003c33  48 8b 05 b6 bb 01 00  mov rax, qword ptr [rip + 0x1bbb6]
00003c3e  48 89 05 b3 bb 01 00  mov qword ptr [rip + 0x1bbb3], rax
00003c45  48 c7 05 10 bc 01 00 01 00 00 00  mov qword ptr [rip + 0x1bc10], 1
00003c50  eb 29  jmp 0x3c7b
00003c60  48 8b 05 f9 bb 01 00  mov rax, qword ptr [rip + 0x1bbf9]
00003c6b  48 89 0d ee bb 01 00  mov qword ptr [rip + 0x1bbee], rcx
00003c75  0f 8d ae 00 00 00  jge 0x3d29
00003c7b  48 8b 05 76 bb 01 00  mov rax, qword ptr [rip + 0x1bb76]
00003c86  48 89 0d 6b bb 01 00  mov qword ptr [rip + 0x1bb6b], rcx
00003c8d  48 8b 0d 2c b0 01 00  mov rcx, qword ptr [rip + 0x1b02c]
00003cb5  48 89 0d 14 bb 01 00  mov qword ptr [rip + 0x1bb14], rcx
00003cc1  48 89 05 80 bb 01 00  mov qword ptr [rip + 0x1bb80], rax
00003cd0  e8 33 d7 00 00  call 0x11408
00003cd5  48 8b 15 6c bb 01 00  mov rdx, qword ptr [rip + 0x1bb6c]
00003ce4  0f 8e 76 ff ff ff  jle 0x3c60
00003cef  48 8b 15 da ba 01 00  mov rdx, qword ptr [rip + 0x1bada]
00003d22  7c ec  jl 0x3d10
00003d24  e9 37 ff ff ff  jmp 0x3c60
00003d29  48 8d 0d 10 bb 01 00  lea rcx, [rip + 0x1bb10]
00003d30  e8 c7 d6 00 00  call 0x113fc
00003d35  4c 8b 1d 04 17 01 00  mov r11, qword ptr [rip + 0x11704]
00003d43  48 8b 05 8e 17 01 00  mov rax, qword ptr [rip + 0x1178e]
00003d51  74 1f  je 0x3d72
00003d53  48 8b 15 86 ba 01 00  mov rdx, qword ptr [rip + 0x1ba86]
00003d7c  74 1e  je 0x3d9c
00003d7e  48 8b 05 5b ba 01 00  mov rax, qword ptr [rip + 0x1ba5b]
00003da3  48 03 05 16 af 01 00  add rax, qword ptr [rip + 0x1af16]
00003dac  48 8d 15 8d 2e 01 00  lea rdx, [rip + 0x12e8d]
00003de6  75 d8  jne 0x3dc0
00003de8  48 c7 05 6d ba 01 00 12 00 00 00  mov qword ptr [rip + 0x1ba6d], 0x12
00003e0f  eb 26  jmp 0x3e37
00003e24  48 89 0d 35 ba 01 00  mov qword ptr [rip + 0x1ba35], rcx
00003e31  0f 8d cf f4 ff ff  jge 0x3306
00003e44  74 da  je 0x3e20
00003e49  e8 ae d5 00 00  call 0x113fc
00003e4e  48 8b 05 0b ba 01 00  mov rax, qword ptr [rip + 0x1ba0b]
00003e65  eb b9  jmp 0x3e20
00003e70  41 57  push r15
00003e83  48 8b 35 76 15 01 00  mov rsi, qword ptr [rip + 0x11576]
00003e95  e8 56 4f 00 00  call 0x8df0
00003e9a  48 c7 05 53 ba 01 00 c0 00 00 00  mov qword ptr [rip + 0x1ba53], 0xc0
00003ea5  48 8d 3d fc 37 01 00  lea rdi, [rip + 0x137fc]
00003eaf  e8 a0 d4 00 00  call 0x11354
00003eb4  48 89 05 35 ba 01 00  mov qword ptr [rip + 0x1ba35], rax
00003ebb  48 8b 1d 36 16 01 00  mov rbx, qword ptr [rip + 0x11636]
00003eca  48 89 05 17 ba 01 00  mov qword ptr [rip + 0x1ba17], rax
00003ed1  48 8d 0d 10 ba 01 00  lea rcx, [rip + 0x1ba10]
00003ed8  e8 77 d4 00 00  call 0x11354
00003ee3  0f 8e b2 03 00 00  jle 0x429b
00003ee9  48 8b 05 00 ba 01 00  mov rax, qword ptr [rip + 0x1ba00]
00003ef8  48 89 05 e1 b9 01 00  mov qword ptr [rip + 0x1b9e1], rax
00003f02  0f 8e 93 03 00 00  jle 0x429b
00003f08  48 8d 0d d1 b9 01 00  lea rcx, [rip + 0x1b9d1]
00003f0f  e8 40 d4 00 00  call 0x11354
00003f14  48 89 05 bd b9 01 00  mov qword ptr [rip + 0x1b9bd], rax
00003f20  48 89 05 81 b9 01 00  mov qword ptr [rip + 0x1b981], rax
00003f2a  0f 8e 6b 03 00 00  jle 0x429b
00003f30  48 8b 05 b9 b9 01 00  mov rax, qword ptr [rip + 0x1b9b9]
00003f3f  48 89 05 8a b9 01 00  mov qword ptr [rip + 0x1b98a], rax
00003f46  48 8d 0d 83 b9 01 00  lea rcx, [rip + 0x1b983]
00003f4d  e8 02 d4 00 00  call 0x11354
00003f56  48 89 0d 6b b9 01 00  mov qword ptr [rip + 0x1b96b], rcx
00003f62  48 c7 05 8b b9 01 00 01 00 00 00  mov qword ptr [rip + 0x1b98b], 1
00003f70  0f 8e 25 03 00 00  jle 0x429b
00003f76  4c 8d 35 3b b9 01 00  lea r14, [rip + 0x1b93b]
00003f7d  4c 8b 3d 54 15 01 00  mov r15, qword ptr [rip + 0x11554]
00003f91  4c 8d 2d 18 37 01 00  lea r13, [rip + 0x13718]
00003f98  eb 51  jmp 0x3feb
00003f9f  48 89 05 0a b9 01 00  mov qword ptr [rip + 0x1b90a], rax
00003fa6  48 8d 0d 03 b9 01 00  lea rcx, [rip + 0x1b903]
00003fad  e8 a2 d3 00 00  call 0x11354
00003fb2  48 8b 0d 0f b9 01 00  mov rcx, qword ptr [rip + 0x1b90f]
00003fc4  48 8b 0d f5 b8 01 00  mov rcx, qword ptr [rip + 0x1b8f5]
00003fd0  48 8b 05 21 b9 01 00  mov rax, qword ptr [rip + 0x1b921]
00003fdb  48 89 0d 16 b9 01 00  mov qword ptr [rip + 0x1b916], rcx
00003fe5  0f 8d b0 02 00 00  jge 0x429b
00003feb  48 8b 05 d6 b8 01 00  mov rax, qword ptr [rip + 0x1b8d6]
00003ff6  48 89 0d cb b8 01 00  mov qword ptr [rip + 0x1b8cb], rcx
00004003  7f cb  jg 0x3fd0
00004010  e8 cf d3 00 00  call 0x113e4
00004015  48 89 05 a4 b8 01 00  mov qword ptr [rip + 0x1b8a4], rax
0000401c  48 83 3d 94 b8 01 00 02  cmp qword ptr [rip + 0x1b894], 2
00004024  75 aa  jne 0x3fd0
0000402c  0f 8e 17 01 00 00  jle 0x4149
00004037  48 8d 05 62 36 01 00  lea rax, [rip + 0x13662]
00004052  48 8d 0d a7 a2 01 00  lea rcx, [rip + 0x1a2a7]
00004062  e8 41 d3 00 00  call 0x113a8
0000406a  0f 84 60 ff ff ff  je 0x3fd0
00004070  48 8b 05 51 b8 01 00  mov rax, qword ptr [rip + 0x1b851]
000040a3  48 8b 0d e6 13 01 00  mov rcx, qword ptr [rip + 0x113e6]
000040c6  48 8d 05 93 a2 01 00  lea rax, [rip + 0x1a293]
000040f4  e8 11 da 00 00  call 0x11b0a
000040f9  48 8b 05 c8 b7 01 00  mov rax, qword ptr [rip + 0x1b7c8]
0000411e  e8 ed d9 00 00  call 0x11b10
00004123  48 8b 05 96 b7 01 00  mov rax, qword ptr [rip + 0x1b796]
00004144  e9 40 01 00 00  jmp 0x4289
0000414c  74 55  je 0x41a3
0000414e  48 8b 05 83 b7 01 00  mov rax, qword ptr [rip + 0x1b783]
00004158  48 8b 0d 49 b7 01 00  mov rcx, qword ptr [rip + 0x1b749]
00004162  0f 8e 32 fe ff ff  jle 0x3f9a
00004168  4c 8b 05 59 b7 01 00  mov r8, qword ptr [rip + 0x1b759]
0000417b  eb 13  jmp 0x4190
0000418a  0f 8d 0a fe ff ff  jge 0x3f9a
00004195  75 e9  jne 0x4180
0000419c  75 e2  jne 0x4180
0000419e  e9 f7 fd ff ff  jmp 0x3f9a
000041a8  48 8d 05 f1 34 01 00  lea rax, [rip + 0x134f1]
000041c3  48 8d 0d 36 a1 01 00  lea rcx, [rip + 0x1a136]
000041d3  e8 d0 d1 00 00  call 0x113a8
000041db  0f 84 ef fd ff ff  je 0x3fd0
000041e1  48 8b 05 e0 b6 01 00  mov rax, qword ptr [rip + 0x1b6e0]
00004211  48 8b 0d 78 12 01 00  mov rcx, qword ptr [rip + 0x11278]
00004234  48 8d 05 d5 a0 01 00  lea rax, [rip + 0x1a0d5]
0000425f  e8 a6 d8 00 00  call 0x11b0a
00004264  48 8b 05 5d b6 01 00  mov rax, qword ptr [rip + 0x1b65d]
00004289  e8 82 d8 00 00  call 0x11b10
00004291  e8 1e d1 00 00  call 0x113b4
00004296  e9 35 fd ff ff  jmp 0x3fd0
000042b0  41 57  push r15
000042c5  48 8d 0d 74 b6 01 00  lea rcx, [rip + 0x1b674]
000042cc  48 8b 3d 25 11 01 00  mov rdi, qword ptr [rip + 0x11125]
000042f8  75 e6  jne 0x42e0
000042fa  48 c7 05 23 b6 01 00 08 00 00 00  mov qword ptr [rip + 0x1b623], 8
00004305  48 8d 0d b4 33 01 00  lea rcx, [rip + 0x133b4]
0000430c  e8 43 d0 00 00  call 0x11354
00004311  48 89 05 08 b6 01 00  mov qword ptr [rip + 0x1b608], rax
00004318  48 8b 35 d1 11 01 00  mov rsi, qword ptr [rip + 0x111d1]
00004323  0f 8e b6 00 00 00  jle 0x43df
00004329  4c 8b 35 c8 11 01 00  mov r14, qword ptr [rip + 0x111c8]
00004338  48 89 05 d9 b5 01 00  mov qword ptr [rip + 0x1b5d9], rax
0000433f  48 8d 0d d2 b5 01 00  lea rcx, [rip + 0x1b5d2]
00004346  e8 09 d0 00 00  call 0x11354
0000434e  48 89 05 eb b5 01 00  mov qword ptr [rip + 0x1b5eb], rax
0000435a  7e 57  jle 0x43b3
0000435c  48 8b 05 bd b5 01 00  mov rax, qword ptr [rip + 0x1b5bd]
0000436b  48 89 05 a6 b5 01 00  mov qword ptr [rip + 0x1b5a6], rax
00004372  48 8d 1d 9f b5 01 00  lea rbx, [rip + 0x1b59f]
0000437c  e8 d3 cf 00 00  call 0x11354
00004384  48 89 05 bd b5 01 00  mov qword ptr [rip + 0x1b5bd], rax
0000438b  48 8b 05 8e b5 01 00  mov rax, qword ptr [rip + 0x1b58e]
0000439a  48 89 05 77 b5 01 00  mov qword ptr [rip + 0x1b577], rax
000043a4  e8 ab cf 00 00  call 0x11354
000043ac  48 89 05 9d b5 01 00  mov qword ptr [rip + 0x1b59d], rax
000043b3  48 8b 05 66 b5 01 00  mov rax, qword ptr [rip + 0x1b566]
000043c2  48 89 05 4f b5 01 00  mov qword ptr [rip + 0x1b54f], rax
000043c9  48 8d 0d 48 b5 01 00  lea rcx, [rip + 0x1b548]
000043d0  e8 7f cf 00 00  call 0x11354
000043d8  48 89 05 79 b5 01 00  mov qword ptr [rip + 0x1b579], rax
000043e4  7e 33  jle 0x4419
000043e6  48 8b 05 33 b5 01 00  mov rax, qword ptr [rip + 0x1b533]
000043ed  48 8b 0d 04 11 01 00  mov rcx, qword ptr [rip + 0x11104]
000043fc  48 89 05 15 b5 01 00  mov qword ptr [rip + 0x1b515], rax
00004403  48 8d 0d 0e b5 01 00  lea rcx, [rip + 0x1b50e]
0000440a  e8 45 cf 00 00  call 0x11354
00004412  48 89 05 47 b5 01 00  mov qword ptr [rip + 0x1b547], rax
0000441e  7e 5e  jle 0x447e
00004420  48 8b 05 f9 b4 01 00  mov rax, qword ptr [rip + 0x1b4f9]
00004427  48 8b 35 ca 10 01 00  mov rsi, qword ptr [rip + 0x110ca]
00004436  48 89 05 db b4 01 00  mov qword ptr [rip + 0x1b4db], rax
0000443d  48 8d 1d d4 b4 01 00  lea rbx, [rip + 0x1b4d4]
00004447  e8 08 cf 00 00  call 0x11354
0000444f  48 89 05 12 b5 01 00  mov qword ptr [rip + 0x1b512], rax
00004456  48 8b 05 c3 b4 01 00  mov rax, qword ptr [rip + 0x1b4c3]
00004465  48 89 05 ac b4 01 00  mov qword ptr [rip + 0x1b4ac], rax
0000446f  e8 e0 ce 00 00  call 0x11354
00004477  48 89 05 f2 b4 01 00  mov qword ptr [rip + 0x1b4f2], rax
0000447e  48 c7 05 87 b4 01 00 ff ff ff ff  mov qword ptr [rip + 0x1b487], 0xffffffffffffffff
00004489  48 c7 05 94 b4 01 00 01 00 00 00  mov qword ptr [rip + 0x1b494], 1
00004494  48 8d 35 45 9f 01 00  lea rsi, [rip + 0x19f45]
0000449b  48 8d 1d 5e b4 01 00  lea rbx, [rip + 0x1b45e]
000044a2  4c 8d 3d 0f 32 01 00  lea r15, [rip + 0x1320f]
000044a9  4c 8b 35 28 10 01 00  mov r14, qword ptr [rip + 0x11028]
000044b8  4c 8d 25 09 32 01 00  lea r12, [rip + 0x13209]
000044c7  eb 30  jmp 0x44f9
000044d0  e8 3b d6 00 00  call 0x11b10
000044d8  e8 d7 ce 00 00  call 0x113b4
000044dd  48 8b 0d 44 b4 01 00  mov rcx, qword ptr [rip + 0x1b444]
000044e8  48 89 05 39 b4 01 00  mov qword ptr [rip + 0x1b439], rax
000044f3  0f 8d 44 02 00 00  jge 0x473d
000044f9  48 8b 05 10 b4 01 00  mov rax, qword ptr [rip + 0x1b410]
00004504  48 89 0d 05 b4 01 00  mov qword ptr [rip + 0x1b405], rcx
00004516  e8 c9 ce 00 00  call 0x113e4
0000451b  48 89 05 e6 b3 01 00  mov qword ptr [rip + 0x1b3e6], rax
00004526  0f 8e 14 01 00 00  jle 0x4640
0000452c  48 8d 05 8d 31 01 00  lea rax, [rip + 0x1318d]
00004547  48 8d 0d 72 9e 01 00  lea rcx, [rip + 0x19e72]
00004557  e8 4c ce 00 00  call 0x113a8
0000455f  0f 84 78 ff ff ff  je 0x44dd
00004565  48 8b 05 a4 b3 01 00  mov rax, qword ptr [rip + 0x1b3a4]
00004598  48 8b 0d f1 0e 01 00  mov rcx, qword ptr [rip + 0x10ef1]
000045bb  48 8d 05 de 9e 01 00  lea rax, [rip + 0x19ede]
000045e1  e8 24 d5 00 00  call 0x11b0a
000045e6  48 8b 05 23 b3 01 00  mov rax, qword ptr [rip + 0x1b323]
0000460b  e8 00 d5 00 00  call 0x11b10
00004610  48 8b 05 f1 b2 01 00  mov rax, qword ptr [rip + 0x1b2f1]
00004631  e9 9a fe ff ff  jmp 0x44d0
00004643  74 1d  je 0x4662
00004645  48 8b 0d dc b2 01 00  mov rcx, qword ptr [rip + 0x1b2dc]
0000464c  48 8d 15 ed b2 01 00  lea rdx, [rip + 0x1b2ed]
0000465d  e9 82 fe ff ff  jmp 0x44e4
00004662  4c 8d 05 57 30 01 00  lea r8, [rip + 0x13057]
0000467d  48 8d 0d 3c 9d 01 00  lea rcx, [rip + 0x19d3c]
0000468a  e8 19 cd 00 00  call 0x113a8
00004692  0f 84 45 fe ff ff  je 0x44dd
00004698  48 8b 05 71 b2 01 00  mov rax, qword ptr [rip + 0x1b271]
000046c8  48 8b 0d c1 0d 01 00  mov rcx, qword ptr [rip + 0x10dc1]
000046eb  48 8d 05 5e 9d 01 00  lea rax, [rip + 0x19d5e]
0000470e  e8 f7 d3 00 00  call 0x11b0a
00004713  48 8b 05 f6 b1 01 00  mov rax, qword ptr [rip + 0x1b1f6]
00004738  e9 93 fd ff ff  jmp 0x44d0
00004760  41 57  push r15
00004775  48 8d 2d 84 b2 01 00  lea rbp, [rip + 0x1b284]
0000477c  48 8b 3d 6d 0c 01 00  mov rdi, qword ptr [rip + 0x10c6d]
000047a8  75 e6  jne 0x4790
000047aa  48 c7 05 43 b2 01 00 05 00 00 00  mov qword ptr [rip + 0x1b243], 5
000047b5  48 8d 0d 1c 2f 01 00  lea rcx, [rip + 0x12f1c]
000047bc  e8 93 cb 00 00  call 0x11354
000047c1  48 8b 35 30 0d 01 00  mov rsi, qword ptr [rip + 0x10d30]
000047d0  48 89 05 19 b2 01 00  mov qword ptr [rip + 0x1b219], rax
000047da  0f 84 66 04 00 00  je 0x4c46
000047e0  48 8d 0d 09 b2 01 00  lea rcx, [rip + 0x1b209]
000047e7  e8 68 cb 00 00  call 0x11354
000047f2  0f 85 4e 04 00 00  jne 0x4c46
00004802  48 89 0d 7f b1 01 00  mov qword ptr [rip + 0x1b17f], rcx
00004809  48 89 15 d8 b1 01 00  mov qword ptr [rip + 0x1b1d8], rdx
00004815  48 89 0d c4 b1 01 00  mov qword ptr [rip + 0x1b1c4], rcx
0000481c  48 8d 0d bd b1 01 00  lea rcx, [rip + 0x1b1bd]
00004828  48 89 15 a9 b1 01 00  mov qword ptr [rip + 0x1b1a9], rdx
00004834  48 89 15 45 b1 01 00  mov qword ptr [rip + 0x1b145], rdx
00004840  48 89 15 89 b1 01 00  mov qword ptr [rip + 0x1b189], rdx
0000484c  48 89 05 75 b1 01 00  mov qword ptr [rip + 0x1b175], rax
00004853  e8 fc ca 00 00  call 0x11354
00004858  48 8b 0d 91 0c 01 00  mov rcx, qword ptr [rip + 0x10c91]
0000487d  48 83 3d 03 b1 01 00 00  cmp qword ptr [rip + 0x1b103], 0
0000488a  75 16  jne 0x48a2
0000488c  48 8d 0d 45 b1 01 00  lea rcx, [rip + 0x1b145]
00004893  e8 bc ca 00 00  call 0x11354
0000489b  48 89 05 5e b1 01 00  mov qword ptr [rip + 0x1b15e], rax
000048a2  48 83 3d 26 b1 01 00 00  cmp qword ptr [rip + 0x1b126], 0
000048aa  7e 16  jle 0x48c2
000048ac  48 8d 0d 1d b1 01 00  lea rcx, [rip + 0x1b11d]
000048b3  e8 9c ca 00 00  call 0x11354
000048bb  48 89 05 46 b1 01 00  mov qword ptr [rip + 0x1b146], rax
000048c2  48 83 3d fe b0 01 00 00  cmp qword ptr [rip + 0x1b0fe], 0
000048ca  7e 16  jle 0x48e2
000048cc  48 8d 0d f5 b0 01 00  lea rcx, [rip + 0x1b0f5]
000048d3  e8 30 cb 00 00  call 0x11408
000048db  48 89 05 2e b1 01 00  mov qword ptr [rip + 0x1b12e], rax
000048e2  48 83 3d 96 b0 01 00 00  cmp qword ptr [rip + 0x1b096], 0
000048ea  0f 84 a8 00 00 00  je 0x4998
000048f0  48 8d 1d f1 b0 01 00  lea rbx, [rip + 0x1b0f1]
000048fa  e8 2d cb 00 00  call 0x1142c
000048ff  48 89 05 ba b0 01 00  mov qword ptr [rip + 0x1b0ba], rax
00004909  e8 fa ca 00 00  call 0x11408
0000490e  48 89 05 a3 b0 01 00  mov qword ptr [rip + 0x1b0a3], rax
00004915  48 83 3d 43 d7 01 00 00  cmp qword ptr [rip + 0x1d743], 0
0000491d  74 17  je 0x4936
0000491f  48 8d 0d 3a d7 01 00  lea rcx, [rip + 0x1d73a]
00004926  e8 07 cb 00 00  call 0x11432
0000492b  48 c7 05 2a d7 01 00 00 00 00 00  mov qword ptr [rip + 0x1d72a], 0
00004936  48 8d 1d 83 b0 01 00  lea rbx, [rip + 0x1b083]
0000493d  48 8d 15 6c b0 01 00  lea rdx, [rip + 0x1b06c]
00004944  4c 8d 05 5d b0 01 00  lea r8, [rip + 0x1b05d]
0000494e  e8 e5 ca 00 00  call 0x11438
00004953  48 8b 05 5e b0 01 00  mov rax, qword ptr [rip + 0x1b05e]
00004962  48 8b 05 3f b0 01 00  mov rax, qword ptr [rip + 0x1b03f]
00004974  e8 c5 ca 00 00  call 0x1143e
00004979  48 8b 05 28 b0 01 00  mov rax, qword ptr [rip + 0x1b028]
00004983  48 89 05 8e b0 01 00  mov qword ptr [rip + 0x1b08e], rax
0000498a  48 8b 05 1f b0 01 00  mov rax, qword ptr [rip + 0x1b01f]
00004991  48 89 05 c8 d6 01 00  mov qword ptr [rip + 0x1d6c8], rax
00004998  48 c7 05 fd af 01 00 ff ff ff ff  mov qword ptr [rip + 0x1affd], 0xffffffffffffffff
000049a3  48 c7 05 4a b0 01 00 01 00 00 00  mov qword ptr [rip + 0x1b04a], 1
000049ae  48 8d 35 6b 9b 01 00  lea rsi, [rip + 0x19b6b]
000049b5  4c 8d 3d 14 2d 01 00  lea r15, [rip + 0x12d14]
000049bc  4c 8b 35 15 0b 01 00  mov r14, qword ptr [rip + 0x10b15]
000049cb  4c 8d 25 0e 2d 01 00  lea r12, [rip + 0x12d0e]
000049da  eb 2d  jmp 0x4a09
000049e0  e8 2b d1 00 00  call 0x11b10
000049e8  e8 c7 c9 00 00  call 0x113b4
000049ed  48 8b 0d 04 b0 01 00  mov rcx, qword ptr [rip + 0x1b004]
000049f8  48 89 05 f9 af 01 00  mov qword ptr [rip + 0x1aff9], rax
00004a03  0f 8d 3d 02 00 00  jge 0x4c46
00004a09  48 8b 05 90 af 01 00  mov rax, qword ptr [rip + 0x1af90]
00004a14  48 89 0d 85 af 01 00  mov qword ptr [rip + 0x1af85], rcx
00004a23  48 8d 15 66 af 01 00  lea rdx, [rip + 0x1af66]
00004a2a  e8 b5 c9 00 00  call 0x113e4
00004a2f  48 89 05 62 af 01 00  mov qword ptr [rip + 0x1af62], rax
00004a3a  0f 8e 10 01 00 00  jle 0x4b50
00004a40  48 8d 05 91 2c 01 00  lea rax, [rip + 0x12c91]
00004a5b  48 8d 0d 9e 9a 01 00  lea rcx, [rip + 0x19a9e]
00004a6b  e8 38 c9 00 00  call 0x113a8
00004a73  0f 84 74 ff ff ff  je 0x49ed
00004a79  48 8b 05 20 af 01 00  mov rax, qword ptr [rip + 0x1af20]
00004aac  48 8b 0d dd 09 01 00  mov rcx, qword ptr [rip + 0x109dd]
00004acf  48 8d 05 da 9a 01 00  lea rax, [rip + 0x19ada]
00004af5  e8 10 d0 00 00  call 0x11b0a
00004afa  48 8b 05 9f ae 01 00  mov rax, qword ptr [rip + 0x1ae9f]
00004b1f  e8 ec cf 00 00  call 0x11b10
00004b24  48 8b 05 6d ae 01 00  mov rax, qword ptr [rip + 0x1ae6d]
00004b45  e9 96 fe ff ff  jmp 0x49e0
00004b53  74 16  je 0x4b6b
00004b55  48 8b 0d 9c ae 01 00  mov rcx, qword ptr [rip + 0x1ae9c]
00004b66  e9 89 fe ff ff  jmp 0x49f4
00004b6b  4c 8d 05 66 2b 01 00  lea r8, [rip + 0x12b66]
00004b86  48 8d 0d 73 99 01 00  lea rcx, [rip + 0x19973]
00004b93  e8 10 c8 00 00  call 0x113a8
00004b9b  0f 84 4c fe ff ff  je 0x49ed
00004ba1  48 8b 05 f8 ad 01 00  mov rax, qword ptr [rip + 0x1adf8]
00004bd1  48 8b 0d b8 08 01 00  mov rcx, qword ptr [rip + 0x108b8]
00004bf4  48 8d 05 65 99 01 00  lea rax, [rip + 0x19965]
00004c17  e8 ee ce 00 00  call 0x11b0a
00004c1c  48 8b 05 7d ad 01 00  mov rax, qword ptr [rip + 0x1ad7d]
00004c41  e9 9a fd ff ff  jmp 0x49e0
00004c60  56  push rsi
00004c6a  0f 85 9b 00 00 00  jne 0x4d0b
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
00004cd4  4c 8d 15 a5 d3 01 00  lea r10, [rip + 0x1d3a5]
00004cdb  4c 8d 1d 3e ad 01 00  lea r11, [rip + 0x1ad3e]
00004d04  75 ea  jne 0x4cf0
00004d09  74 7e  je 0x4d89
00004d16  7e 2d  jle 0x4d45
00004d1a  4c 8d 15 bf d2 01 00  lea r10, [rip + 0x1d2bf]
00004d43  7c eb  jl 0x4d30
00004d4b  7e 3c  jle 0x4d89
00004d5a  4c 8d 0d bf ac 01 00  lea r9, [rip + 0x1acbf]
00004d87  7c e7  jl 0x4d70
00004d90  41 57  push r15
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
00004ecd  0f 89 87 00 00 00  jns 0x4f5a
00004ede  e8 67 c5 00 00  call 0x1144a
00004ee6  4c 8d 3d 82 ac 01 00  lea r15, [rip + 0x1ac82]
00004ef9  e8 22 3e 00 00  call 0x8d20
00004f11  48 8d 05 f8 27 01 00  lea rax, [rip + 0x127f8]
00004f1d  48 8d 0d e4 27 01 00  lea rcx, [rip + 0x127e4]
00004f3c  4c 8d 05 bd 27 01 00  lea r8, [rip + 0x127bd]
00004f43  4c 8d 0d 26 ad 01 00  lea r9, [rip + 0x1ad26]
00004f52  e8 f9 c4 00 00  call 0x11450
00004f78  0f 89 8b 00 00 00  jns 0x5009
00004f8b  e8 ba c4 00 00  call 0x1144a
00004f93  4c 8d 35 d6 aa 01 00  lea r14, [rip + 0x1aad6]
00004fa6  e8 75 3d 00 00  call 0x8d20
00004fbe  48 8d 05 4b 27 01 00  lea rax, [rip + 0x1274b]
00004fca  48 8d 0d 37 27 01 00  lea rcx, [rip + 0x12737]
00004fe9  4c 8d 05 10 27 01 00  lea r8, [rip + 0x12710]
00004ff0  4c 8d 0d 79 ac 01 00  lea r9, [rip + 0x1ac79]
00004fff  e8 4c c4 00 00  call 0x11450
0000500c  48 8b 0d 5d 03 01 00  mov rcx, qword ptr [rip + 0x1035d]
0000503c  48 89 0d 35 ac 01 00  mov qword ptr [rip + 0x1ac35], rcx
00005043  48 8d 05 2e ac 01 00  lea rax, [rip + 0x1ac2e]
0000507b  48 8d 15 96 26 01 00  lea rdx, [rip + 0x12696]
0000508f  e8 2c 39 00 00  call 0x89c0
000050b0  48 83 ec 58  sub rsp, 0x58
000050c4  48 c7 05 b1 ab 01 00 00 00 00 00  mov qword ptr [rip + 0x1abb1], 0
000050cf  48 8d 05 aa ab 01 00  lea rax, [rip + 0x1abaa]
000050e5  e8 a6 fc ff ff  call 0x4d90
000050f0  48 83 ec 58  sub rsp, 0x58
00005104  48 c7 05 79 ab 01 00 00 00 00 00  mov qword ptr [rip + 0x1ab79], 0
0000510f  4c 8d 15 72 ab 01 00  lea r10, [rip + 0x1ab72]
00005116  48 c7 05 5f ab 01 00 00 00 00 00  mov qword ptr [rip + 0x1ab5f], 0
00005121  4c 8d 1d 58 ab 01 00  lea r11, [rip + 0x1ab58]
0000513c  e8 4f fc ff ff  call 0x4d90
00005150  4c 8d 05 c9 94 01 00  lea r8, [rip + 0x194c9]
00005157  e9 04 00 00 00  jmp 0x5160
00005160  41 57  push r15
0000517c  48 c7 05 d9 ac 01 00 00 00 00 00  mov qword ptr [rip + 0x1acd9], 0
00005187  48 c7 05 c6 ac 01 00 00 00 00 00  mov qword ptr [rip + 0x1acc6], 0
00005192  48 c7 05 ab ac 01 00 00 00 00 00  mov qword ptr [rip + 0x1acab], 0
0000519d  48 8b 05 3c 03 01 00  mov rax, qword ptr [rip + 0x1033c]
000051ac  0f 84 c5 01 00 00  je 0x5377
000051b2  4c 8b 3d df 00 01 00  mov r15, qword ptr [rip + 0x100df]
000051be  0f 84 8a 01 00 00  je 0x534e
000051c4  48 8d 0d 85 25 01 00  lea rcx, [rip + 0x12585]
000051cb  48 8d 15 76 ac 01 00  lea rdx, [rip + 0x1ac76]
000051d8  e8 e3 c1 00 00  call 0x113c0
000051dd  e8 c2 c8 00 00  call 0x11aa4
000051e2  e8 7b c2 00 00  call 0x11462
000051e7  4c 8b 25 1a 02 01 00  mov r12, qword ptr [rip + 0x1021a]
000051f7  75 05  jne 0x51fe
000051f9  e8 6a c2 00 00  call 0x11468
000051fe  e8 6b c2 00 00  call 0x1146e
0000522f  48 8d 2d ea 24 01 00  lea rbp, [rip + 0x124ea]
0000526b  e8 a6 c8 00 00  call 0x11b16
000052b8  e8 59 c8 00 00  call 0x11b16
00005305  e8 0c c8 00 00  call 0x11b16
00005313  75 13  jne 0x5328
00005315  48 8d 0d 44 ab 01 00  lea rcx, [rip + 0x1ab44]
0000531c  48 8d 15 35 ab 01 00  lea rdx, [rip + 0x1ab35]
00005323  e8 4c c1 00 00  call 0x11474
00005330  48 8b 05 59 00 01 00  mov rax, qword ptr [rip + 0x10059]
0000533f  48 8b 05 3a 00 01 00  mov rax, qword ptr [rip + 0x1003a]
0000534e  48 8b 05 b3 00 01 00  mov rax, qword ptr [rip + 0x100b3]
0000535d  0f 84 e1 01 00 00  je 0x5544
00005377  48 8d 0d a6 23 01 00  lea rcx, [rip + 0x123a6]
0000537e  e8 81 f3 00 00  call 0x14704
00005386  0f 84 26 fe ff ff  je 0x51b2
00005392  4c 03 3d 07 ff 00 00  add r15, qword ptr [rip + 0xff07]
0000539e  48 8d 0d 03 a9 01 00  lea rcx, [rip + 0x1a903]
000053a5  48 8d 15 d4 92 01 00  lea rdx, [rip + 0x192d4]
000053ac  4c 8d 05 7d 23 01 00  lea r8, [rip + 0x1237d]
000053b3  4c 8d 35 86 23 01 00  lea r14, [rip + 0x12386]
000053bd  e8 ca c0 00 00  call 0x1148c
000053c2  48 89 05 87 aa 01 00  mov qword ptr [rip + 0x1aa87], rax
000053cc  0f 85 e0 fd ff ff  jne 0x51b2
000053d2  48 8d 05 77 aa 01 00  lea rax, [rip + 0x1aa77]
000053de  48 8d 0d bb a8 01 00  lea rcx, [rip + 0x1a8bb]
000053e5  48 8d 15 54 92 01 00  lea rdx, [rip + 0x19254]
000053ec  4c 8d 05 b5 a8 01 00  lea r8, [rip + 0x1a8b5]
000053f6  e8 97 c0 00 00  call 0x11492
000053fb  48 83 3d 4d aa 01 00 00  cmp qword ptr [rip + 0x1aa4d], 0
00005403  0f 85 a9 fd ff ff  jne 0x51b2
00005409  48 8d 05 a0 a8 01 00  lea rax, [rip + 0x1a8a0]
00005448  48 8d 05 f9 22 01 00  lea rax, [rip + 0x122f9]
00005457  48 8d 0d 22 a9 01 00  lea rcx, [rip + 0x1a922]
0000546e  48 8d 0d 2b a9 01 00  lea rcx, [rip + 0x1a92b]
0000547d  48 8d 0d 3c a8 01 00  lea rcx, [rip + 0x1a83c]
0000548c  48 8d 0d 4d a8 01 00  lea rcx, [rip + 0x1a84d]
000054a3  48 8d 0d 56 a8 01 00  lea rcx, [rip + 0x1a856]
000054b2  48 8d 0d 87 a8 01 00  lea rcx, [rip + 0x1a887]
000054be  48 8d 0d 9b a8 01 00  lea rcx, [rip + 0x1a89b]
000054cf  48 8d 05 4a a8 01 00  lea rax, [rip + 0x1a84a]
000054db  48 8d 05 de a8 01 00  lea rax, [rip + 0x1a8de]
000054e7  48 8d 05 f2 a8 01 00  lea rax, [rip + 0x1a8f2]
000054f3  48 8d 05 06 a9 01 00  lea rax, [rip + 0x1a906]
000054ff  48 8d 05 1a a9 01 00  lea rax, [rip + 0x1a91a]
0000550b  48 8d 05 2e a9 01 00  lea rax, [rip + 0x1a92e]
00005526  48 8d 0d 73 a7 01 00  lea rcx, [rip + 0x1a773]
0000552d  48 8d 15 04 22 01 00  lea rdx, [rip + 0x12204]
0000553a  e8 59 bf 00 00  call 0x11498
0000553f  e9 6e fc ff ff  jmp 0x51b2
00005544  48 8b 1d 8d fc 00 00  mov rbx, qword ptr [rip + 0xfc8d]
00005553  74 31  je 0x5586
0000555c  e8 43 bf 00 00  call 0x114a4
00005561  48 89 05 e8 a8 01 00  mov qword ptr [rip + 0x1a8e8], rax
0000558e  74 31  je 0x55c1
00005597  e8 08 bf 00 00  call 0x114a4
0000559c  48 89 05 ad a8 01 00  mov qword ptr [rip + 0x1a8ad], rax
000055c5  75 0a  jne 0x55d1
000055c7  e8 76 bd 00 00  call 0x11342
000055cc  e8 77 bd 00 00  call 0x11348
000055d5  0f 85 88 fd ff ff  jne 0x5363
000055db  48 8b 05 8e fd 00 00  mov rax, qword ptr [rip + 0xfd8e]
000055e6  0f 85 77 fd ff ff  jne 0x5363
000055ff  e9 a6 be 00 00  jmp 0x114aa
00005610  56  push rsi
00005617  48 8d 0d 6a a8 01 00  lea rcx, [rip + 0x1a86a]
0000561e  e8 8d be 00 00  call 0x114b0
00005623  48 8b 05 76 fe 00 00  mov rax, qword ptr [rip + 0xfe76]
00005631  48 89 0d 70 a8 01 00  mov qword ptr [rip + 0x1a870], rcx
00005638  48 8b 3d b1 fe 00 00  mov rdi, qword ptr [rip + 0xfeb1]
00005645  7e 39  jle 0x5680
0000564b  48 03 0d a6 fe 00 00  add rcx, qword ptr [rip + 0xfea6]
00005656  72 0d  jb 0x5665
0000565e  e8 8d 37 00 00  call 0x8df0
00005663  eb 1b  jmp 0x5680
0000567e  75 f0  jne 0x5670
00005680  48 8d 0d 71 a8 01 00  lea rcx, [rip + 0x1a871]
00005687  e8 44 bf 00 00  call 0x115d0
0000568c  48 83 3d 64 a8 01 00 00  cmp qword ptr [rip + 0x1a864], 0
00005694  0f 8e 96 02 00 00  jle 0x5930
0000569a  48 8d 0d 57 a8 01 00  lea rcx, [rip + 0x1a857]
000056a1  e8 ae bc 00 00  call 0x11354
000056a6  48 89 05 43 a8 01 00  mov qword ptr [rip + 0x1a843], rax
000056ad  48 8b 35 44 fe 00 00  mov rsi, qword ptr [rip + 0xfe44]
000056bd  48 89 0d 14 a8 01 00  mov qword ptr [rip + 0x1a814], rcx
000056c4  48 8d 0d 0d a8 01 00  lea rcx, [rip + 0x1a80d]
000056cb  48 89 15 16 a8 01 00  mov qword ptr [rip + 0x1a816], rdx
000056d7  48 89 15 da a7 01 00  mov qword ptr [rip + 0x1a7da], rdx
000056e3  48 89 15 de a7 01 00  mov qword ptr [rip + 0x1a7de], rdx
000056ef  48 89 05 a2 a7 01 00  mov qword ptr [rip + 0x1a7a2], rax
000056f6  e8 59 bc 00 00  call 0x11354
00005700  48 89 0d c9 a7 01 00  mov qword ptr [rip + 0x1a7c9], rcx
0000570a  7e 38  jle 0x5744
0000570c  48 8b 15 95 a7 01 00  mov rdx, qword ptr [rip + 0x1a795]
00005717  48 03 05 da fd 00 00  add rax, qword ptr [rip + 0xfdda]
00005742  7c ec  jl 0x5730
00005744  48 83 3d 9c a7 01 00 00  cmp qword ptr [rip + 0x1a79c], 0
0000574c  7e 56  jle 0x57a4
0000574e  48 8d 0d 93 a7 01 00  lea rcx, [rip + 0x1a793]
00005755  e8 fa bb 00 00  call 0x11354
0000575f  48 89 0d 7a a7 01 00  mov qword ptr [rip + 0x1a77a], rcx
00005769  7e 39  jle 0x57a4
0000576b  48 8b 15 36 a7 01 00  mov rdx, qword ptr [rip + 0x1a736]
00005776  48 03 05 7b fd 00 00  add rax, qword ptr [rip + 0xfd7b]
000057a2  7c ec  jl 0x5790
000057a4  48 83 3d 0c a7 01 00 00  cmp qword ptr [rip + 0x1a70c], 0
000057ac  7e 56  jle 0x5804
000057ae  48 8d 0d 03 a7 01 00  lea rcx, [rip + 0x1a703]
000057b5  e8 9a bb 00 00  call 0x11354
000057bf  48 89 0d ea a6 01 00  mov qword ptr [rip + 0x1a6ea], rcx
000057c9  7e 39  jle 0x5804
000057cb  48 8b 15 d6 a6 01 00  mov rdx, qword ptr [rip + 0x1a6d6]
000057d6  48 03 05 1b fd 00 00  add rax, qword ptr [rip + 0xfd1b]
00005802  7c ec  jl 0x57f0
00005804  48 83 3d bc a6 01 00 00  cmp qword ptr [rip + 0x1a6bc], 0
0000580c  7e 56  jle 0x5864
0000580e  48 8d 0d b3 a6 01 00  lea rcx, [rip + 0x1a6b3]
00005815  e8 3a bb 00 00  call 0x11354
0000581f  48 89 0d 9a a6 01 00  mov qword ptr [rip + 0x1a69a], rcx
00005829  7e 39  jle 0x5864
0000582b  48 8b 15 76 a6 01 00  mov rdx, qword ptr [rip + 0x1a676]
00005836  48 03 05 bb fc 00 00  add rax, qword ptr [rip + 0xfcbb]
00005862  7c ec  jl 0x5850
00005864  48 83 3d 2c a6 01 00 00  cmp qword ptr [rip + 0x1a62c], 0
0000586c  7e 56  jle 0x58c4
0000586e  48 8d 0d 23 a6 01 00  lea rcx, [rip + 0x1a623]
00005875  e8 da ba 00 00  call 0x11354
0000587f  48 89 0d 0a a6 01 00  mov qword ptr [rip + 0x1a60a], rcx
00005889  7e 39  jle 0x58c4
0000588b  48 8b 15 16 a6 01 00  mov rdx, qword ptr [rip + 0x1a616]
00005896  48 03 05 5b fc 00 00  add rax, qword ptr [rip + 0xfc5b]
000058c2  7c ec  jl 0x58b0
000058c4  48 8b 05 25 a6 01 00  mov rax, qword ptr [rip + 0x1a625]
000058d0  48 89 05 c9 a5 01 00  mov qword ptr [rip + 0x1a5c9], rax
000058d7  48 8d 0d c2 a5 01 00  lea rcx, [rip + 0x1a5c2]
000058de  e8 71 ba 00 00  call 0x11354
000058e8  48 8b 0d f1 a5 01 00  mov rcx, qword ptr [rip + 0x1a5f1]
000058fd  48 8b 05 ac a5 01 00  mov rax, qword ptr [rip + 0x1a5ac]
0000590b  48 8b 05 be a5 01 00  mov rax, qword ptr [rip + 0x1a5be]
00005919  48 8b 05 a0 a5 01 00  mov rax, qword ptr [rip + 0x1a5a0]
00005927  48 8b 05 62 a5 01 00  mov rax, qword ptr [rip + 0x1a562]
0000592e  eb 1e  jmp 0x594e
00005955  48 83 3d 2b a5 01 00 01  cmp qword ptr [rip + 0x1a52b], 1
0000595d  48 8b 35 74 fb 00 00  mov rsi, qword ptr [rip + 0xfb74]
00005964  75 0e  jne 0x5974
0000596e  0f 84 09 01 00 00  je 0x5a7d
00005974  48 8d 0d dd 1d 01 00  lea rcx, [rip + 0x11ddd]
0000597b  e8 d4 b9 00 00  call 0x11354
00005980  48 89 05 f9 a4 01 00  mov qword ptr [rip + 0x1a4f9], rax
00005987  48 8b 1d 6a fb 00 00  mov rbx, qword ptr [rip + 0xfb6a]
00005993  48 89 05 de a4 01 00  mov qword ptr [rip + 0x1a4de], rax
0000599d  74 15  je 0x59b4
0000599f  48 8d 0d d2 a4 01 00  lea rcx, [rip + 0x1a4d2]
000059a6  e8 a9 b9 00 00  call 0x11354
000059ab  48 89 05 be a4 01 00  mov qword ptr [rip + 0x1a4be], rax
000059b2  eb 34  jmp 0x59e8
000059b4  48 8d 0d a5 1d 01 00  lea rcx, [rip + 0x11da5]
000059bb  48 8d 15 b6 a4 01 00  lea rdx, [rip + 0x1a4b6]
000059c2  4c 8d 05 a7 a4 01 00  lea r8, [rip + 0x1a4a7]
000059c9  e8 40 ba 00 00  call 0x1140e
000059ce  48 8b 05 a3 a4 01 00  mov rax, qword ptr [rip + 0x1a4a3]
000059d5  48 8b 0d a4 a4 01 00  mov rcx, qword ptr [rip + 0x1a4a4]
000059e1  48 8b 05 88 a4 01 00  mov rax, qword ptr [rip + 0x1a488]
000059f6  74 11  je 0x5a09
000059fb  e8 08 ba 00 00  call 0x11408
00005a07  eb 2b  jmp 0x5a34
00005a15  48 89 0d 4c a4 01 00  mov qword ptr [rip + 0x1a44c], rcx
00005a1f  7e 13  jle 0x5a34
00005a28  48 8d 0d 39 a4 01 00  lea rcx, [rip + 0x1a439]
00005a2f  e8 04 ba 00 00  call 0x11438
00005a34  48 8b 05 35 a4 01 00  mov rax, qword ptr [rip + 0x1a435]
00005a49  74 0e  je 0x5a59
00005a4e  e8 b5 b9 00 00  call 0x11408
00005a57  eb 24  jmp 0x5a7d
00005a61  48 89 05 00 a4 01 00  mov qword ptr [rip + 0x1a400], rax
00005a68  7e 13  jle 0x5a7d
00005a6e  48 8d 0d f3 a3 01 00  lea rcx, [rip + 0x1a3f3]
00005a78  e8 bb b9 00 00  call 0x11438
