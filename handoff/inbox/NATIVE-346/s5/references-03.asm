0000df50  51  push rcx
0000df53  80 3d 66 2b 01 00 00  cmp byte ptr [rip + 0x12b66], 0
0000df5a  75 05  jne 0xdf61
0000df5c  e8 5f f2 ff ff  call 0xd1c0
0000df68  48 8d 0d 61 2b 01 00  lea rcx, [rip + 0x12b61]
0000df90  50  push rax
0000df91  80 3d 28 2b 01 00 00  cmp byte ptr [rip + 0x12b28], 0
0000df98  75 05  jne 0xdf9f
0000df9a  e8 21 f2 ff ff  call 0xd1c0
0000dfa6  48 8d 15 23 2b 01 00  lea rdx, [rip + 0x12b23]
0000dfc3  78 14  js 0xdfd9
0000dfe0  52  push rdx
0000dfe6  80 3d d3 2a 01 00 00  cmp byte ptr [rip + 0x12ad3], 0
0000dfed  75 05  jne 0xdff4
0000dfef  e8 cc f1 ff ff  call 0xd1c0
0000dffb  48 8d 0d ce 2a 01 00  lea rcx, [rip + 0x12ace]
0000e018  78 13  js 0xe02d
0000e040  57  push rdi
0000e059  48 8d 15 80 0c 00 00  lea rdx, [rip + 0xc80]
0000e06c  77 12  ja 0xe080
0000e078  3e ff e2  notrack jmp rdx
0000e080  48 8d 15 59 03 00 00  lea rdx, [rip + 0x359]
0000e08e  74 23  je 0xe0b3
0000e0a4  3e ff e2  notrack jmp rdx
0000e0ba  0f 8c 30 01 00 00  jl 0xe1f0
0000e0c0  48 8b 0d b9 07 01 00  mov rcx, qword ptr [rip + 0x107b9]
0000e0d4  73 5a  jae 0xe130
0000e11f  7d ba  jge 0xe0db
0000e121  e9 da 00 00 00  jmp 0xe200
0000e13c  e9 af 0f 00 00  jmp 0xf0f0
0000e153  e9 58 ff ff ff  jmp 0xe0b0
0000e164  e9 47 ff ff ff  jmp 0xe0b0
0000e178  e9 33 ff ff ff  jmp 0xe0b0
0000e183  e9 28 ff ff ff  jmp 0xe0b0
0000e197  e9 14 ff ff ff  jmp 0xe0b0
0000e1a3  e9 08 ff ff ff  jmp 0xe0b0
0000e1b7  e9 f4 fe ff ff  jmp 0xe0b0
0000e1c7  e9 e4 fe ff ff  jmp 0xe0b0
0000e1df  e9 cc fe ff ff  jmp 0xe0b0
0000e20a  48 8d 15 cf 02 00 00  lea rdx, [rip + 0x2cf]
0000e215  3e ff e2  notrack jmp rdx
0000e25f  48 8d 15 7a 02 00 00  lea rdx, [rip + 0x27a]
0000e26a  3e ff e2  notrack jmp rdx
0000e273  e9 78 0e 00 00  jmp 0xf0f0
0000e280  e9 6b 0e 00 00  jmp 0xf0f0
0000e294  e9 57 0e 00 00  jmp 0xf0f0
0000e2a8  e9 43 0e 00 00  jmp 0xf0f0
0000e2b3  e9 38 0e 00 00  jmp 0xf0f0
0000e2c7  e9 24 0e 00 00  jmp 0xf0f0
0000e2d3  e9 18 0e 00 00  jmp 0xf0f0
0000e2e7  e9 04 0e 00 00  jmp 0xf0f0
0000e2f5  e9 f6 0d 00 00  jmp 0xf0f0
0000e30a  e9 e1 0d 00 00  jmp 0xf0f0
0000e31a  e9 d1 0d 00 00  jmp 0xf0f0
0000e32f  e9 bc 0d 00 00  jmp 0xf0f0
0000e350  e9 9b 0d 00 00  jmp 0xf0f0
0000e37a  e9 71 0d 00 00  jmp 0xf0f0
0000e39c  e9 4f 0d 00 00  jmp 0xf0f0
0000e3b9  e9 32 0d 00 00  jmp 0xf0f0
0000e3ce  e9 1d 0d 00 00  jmp 0xf0f0
0000f100  48 89 c8  mov rax, rcx
0000f115  48 8d 15 a4 14 00 00  lea rdx, [rip + 0x14a4]
0000f129  7d 0c  jge 0xf137
0000f135  ff e2  jmp rdx
0000f137  48 8d 15 82 02 00 00  lea rdx, [rip + 0x282]
0000f14c  74 12  je 0xf160
0000f15b  ff e2  jmp rdx
0000f167  0f 8c 25 01 00 00  jl 0xf292
0000f16d  4c 3b 05 1c f7 00 00  cmp r8, qword ptr [rip + 0xf71c]
0000f174  73 53  jae 0xf1c9
0000f1c2  7d b2  jge 0xf176
0000f1c4  e9 c9 00 00 00  jmp 0xf292
0000f215  7d b2  jge 0xf1c9
0000f21a  eb 76  jmp 0xf292
0000f21f  e9 39 ff ff ff  jmp 0xf15d
0000f228  e9 30 ff ff ff  jmp 0xf15d
0000f235  e9 23 ff ff ff  jmp 0xf15d
0000f23d  e9 1b ff ff ff  jmp 0xf15d
0000f249  e9 0f ff ff ff  jmp 0xf15d
0000f251  e9 07 ff ff ff  jmp 0xf15d
0000f25d  e9 fb fe ff ff  jmp 0xf15d
0000f266  e9 f2 fe ff ff  jmp 0xf15d
0000f275  e9 e3 fe ff ff  jmp 0xf15d
0000f27e  e9 da fe ff ff  jmp 0xf15d
0000f28d  e9 cb fe ff ff  jmp 0xf15d
0000f29f  48 8d 15 1a 03 00 00  lea rdx, [rip + 0x31a]
0000f2aa  ff e2  jmp rdx
0000f2e4  48 8d 15 d5 02 00 00  lea rdx, [rip + 0x2d5]
0000f2ef  ff e2  jmp rdx
0000f2f4  e9 c7 16 00 00  jmp 0x109c0
0000f2f9  e9 c2 16 00 00  jmp 0x109c0
0000f302  e9 b9 16 00 00  jmp 0x109c0
0000f30f  e9 ac 16 00 00  jmp 0x109c0
0000f317  e9 a4 16 00 00  jmp 0x109c0
0000f323  e9 98 16 00 00  jmp 0x109c0
0000f32b  e9 90 16 00 00  jmp 0x109c0
0000f337  e9 84 16 00 00  jmp 0x109c0
0000f340  e9 7b 16 00 00  jmp 0x109c0
0000f34f  e9 6c 16 00 00  jmp 0x109c0
0000f358  e9 63 16 00 00  jmp 0x109c0
0000f367  e9 54 16 00 00  jmp 0x109c0
0000f372  e9 49 16 00 00  jmp 0x109c0
0000f384  e9 37 16 00 00  jmp 0x109c0
000109d0  56  push rsi
000109df  72 1b  jb 0x109fc
000109e1  83 3d 94 09 01 00 00  cmp dword ptr [rip + 0x10994], 0
000109e8  75 05  jne 0x109ef
000109ea  e8 21 00 00 00  call 0x10a10
000109f2  48 8d 05 77 09 01 00  lea rax, [rip + 0x10977]
00010a10  55  push rbp
00010a2b  48 8b 05 ce dd 00 00  mov rax, qword ptr [rip + 0xddce]
00010a51  74 08  je 0x10a5b
00010a62  0f 84 18 03 00 00  je 0x10d80
00010a70  0f 28 05 79 77 00 00  movaps xmm0, xmmword ptr [rip + 0x7779]
00010a91  75 17  jne 0x10aaa
00010a96  75 12  jne 0x10aaa
00010a9b  75 0d  jne 0x10aaa
00010ab1  89 05 b9 08 01 00  mov dword ptr [rip + 0x108b9], eax
00010aba  89 05 b4 08 01 00  mov dword ptr [rip + 0x108b4], eax
00010ac3  0f 8c e7 00 00 00  jl 0x10bb0
00010af4  74 1d  je 0x10b13
00010b0b  7d 06  jge 0x10b13
00010b11  eb d3  jmp 0x10ae6
00010b22  0f 8e 85 00 00 00  jle 0x10bad
00010b2e  48 8d 15 3b 08 01 00  lea rdx, [rip + 0x1083b]
00010b49  75 59  jne 0x10ba4
00010bab  75 88  jne 0x10b35
00010bb0  83 3d c9 07 01 00 00  cmp dword ptr [rip + 0x107c9], 0
00010bb7  0f 85 c3 01 00 00  jne 0x10d80
00010bc0  0f 8c ba 01 00 00  jl 0x10d80
00010bee  7e 4d  jle 0x10c3d
00010bf2  7e 32  jle 0x10c26
00010bf6  7e 17  jle 0x10c0f
00010c5a  0f 84 20 01 00 00  je 0x10d80
00010c67  48 8d 35 92 75 00 00  lea rsi, [rip + 0x7592]
00010c72  4c 8d 35 f7 06 01 00  lea r14, [rip + 0x106f7]
00010c7f  0f 88 d1 00 00 00  js 0x10d56
00010c94  0f 84 ce 00 00 00  je 0x10d68
00010ca4  0f 84 9f 00 00 00  je 0x10d49
00010cad  75 66  jne 0x10d15
00010cb3  75 60  jne 0x10d15
00010cf6  75 1d  jne 0x10d15
00010d50  0f 85 32 ff ff ff  jne 0x10c88
00010d60  0f 85 13 ff ff ff  jne 0x10c79
00010d66  eb 18  jmp 0x10d80
00010d6b  0f 29 05 0e 06 01 00  movaps xmmword ptr [rip + 0x1060e], xmm0
00010d72  0f 29 05 17 06 01 00  movaps xmmword ptr [rip + 0x10617], xmm0
00010d79  0f 29 05 20 06 01 00  movaps xmmword ptr [rip + 0x10620], xmm0
00010d80  c7 05 f2 05 01 00 01 00 00 00  mov dword ptr [rip + 0x105f2], 1
00010d91  e8 9a 3a 00 00  call 0x14830
00010db0  55  push rbp
00010dbc  48 8b 05 3d da 00 00  mov rax, qword ptr [rip + 0xda3d]
00010dca  83 3d ab 05 01 00 00  cmp dword ptr [rip + 0x105ab], 0
00010dd1  75 05  jne 0x10dd8
00010dd3  e8 38 fc ff ff  call 0x10a10
00010dd8  83 3d 91 05 01 00 00  cmp dword ptr [rip + 0x10591], 0
00010ddf  74 3b  je 0x10e1c
00010de1  83 3d 8c 05 01 00 00  cmp dword ptr [rip + 0x1058c], 0
00010de8  0f 84 4c 01 00 00  je 0x10f3a
00010e17  e9 20 01 00 00  jmp 0x10f3c
00010e55  0f 85 b6 01 00 00  jne 0x11011
00010e62  0f 85 a9 01 00 00  jne 0x11011
00010e6f  0f 85 9c 01 00 00  jne 0x11011
00010edb  0f 82 30 01 00 00  jb 0x11011
00010f13  48 89 05 56 d9 00 00  mov qword ptr [rip + 0xd956], rax
00010f1c  48 89 05 55 d9 00 00  mov qword ptr [rip + 0xd955], rax
00010f23  48 8b 05 56 d9 00 00  mov rax, qword ptr [rip + 0xd956]
00010f2e  48 89 05 5b d9 00 00  mov qword ptr [rip + 0xd95b], rax
00010f35  e9 d7 00 00 00  jmp 0x11011
00010f3c  8b 05 3e 04 01 00  mov eax, dword ptr [rip + 0x1043e]
00010f44  0f 84 b1 00 00 00  je 0x10ffb
00010f4a  8b 0d 48 04 01 00  mov ecx, dword ptr [rip + 0x10448]
00010f50  0f af 0d 3d 04 01 00  imul ecx, dword ptr [rip + 0x1043d]
00010f57  8b 15 33 04 01 00  mov edx, dword ptr [rip + 0x10433]
00010f5d  44 8b 05 24 04 01 00  mov r8d, dword ptr [rip + 0x10424]
00010f64  44 0f af 05 18 04 01 00  imul r8d, dword ptr [rip + 0x10418]
00010f75  8b 0d 2d 04 01 00  mov ecx, dword ptr [rip + 0x1042d]
00010f7b  0f af 0d 22 04 01 00  imul ecx, dword ptr [rip + 0x10422]
00010f82  44 8b 0d 17 04 01 00  mov r9d, dword ptr [rip + 0x10417]
00010f9b  4c 89 05 ce d8 00 00  mov qword ptr [rip + 0xd8ce], r8
00010fa6  48 89 15 cb d8 00 00  mov qword ptr [rip + 0xd8cb], rdx
00010fb0  48 89 05 c9 d8 00 00  mov qword ptr [rip + 0xd8c9], rax
00010fbb  48 89 15 c6 d8 00 00  mov qword ptr [rip + 0xd8c6], rdx
00010fc7  48 89 15 c2 d8 00 00  mov qword ptr [rip + 0xd8c2], rdx
00010fce  48 89 0d e3 03 01 00  mov qword ptr [rip + 0x103e3], rcx
00010fd5  48 c7 05 b8 d8 00 00 00 20 00 00  mov qword ptr [rip + 0xd8b8], 0x2000
00010fe7  48 89 05 b2 d8 00 00  mov qword ptr [rip + 0xd8b2], rax
00010fee  48 c7 05 af d8 00 00 00 08 00 00  mov qword ptr [rip + 0xd8af], 0x800
00010ff9  eb 16  jmp 0x11011
00010ffb  48 8d 0d fe 79 00 00  lea rcx, [rip + 0x79fe]
00011002  e8 e1 37 00 00  call 0x147e8
0001100a  74 05  je 0x11011
0001100f  75 21  jne 0x11032
00011011  89 35 99 03 01 00  mov dword ptr [rip + 0x10399], esi
00011017  89 35 a3 03 01 00  mov dword ptr [rip + 0x103a3], esi
00011024  e8 07 38 00 00  call 0x14830
0001103c  e8 3f 02 00 00  call 0x11280
0001104e  e8 2d 02 00 00  call 0x11280
0001105d  e8 1e 02 00 00  call 0x11280
00011067  e8 82 37 00 00  call 0x147ee
00011070  56  push rsi
00011082  48 8b 05 77 d7 00 00  mov rax, qword ptr [rip + 0xd777]
00011091  e8 6a 00 00 00  call 0x11100
0001109b  7e 3f  jle 0x110dc
000110a7  e8 44 0f 00 00  call 0x11ff0
000110c1  48 8d 3d 08 03 01 00  lea rdi, [rip + 0x10308]
000110d4  e8 1b 37 00 00  call 0x147f4
000110e4  e8 47 37 00 00  call 0x14830
00011100  56  push rsi
00011109  48 8b 05 f0 d6 00 00  mov rax, qword ptr [rip + 0xd6f0]
0001111d  0f 84 fc 00 00 00  je 0x1121f
00011125  80 3d ac 06 01 00 00  cmp byte ptr [rip + 0x106ac], 0
0001112c  75 4c  jne 0x1117a
0001112e  c6 05 a3 06 01 00 01  mov byte ptr [rip + 0x106a3], 1
00011135  ff 15 65 3f 00 00  call qword ptr [rip + 0x3f65]
0001113b  48 8d 15 ca 7c 00 00  lea rdx, [rip + 0x7cca]
00011142  4c 8d 0d b7 7c 00 00  lea r9, [rip + 0x7cb7]
00011154  e8 17 3b 00 00  call 0x14c70
00011161  ff 15 41 3f 00 00  call qword ptr [rip + 0x3f41]
00011167  48 89 05 72 06 01 00  mov qword ptr [rip + 0x10672], rax
00011171  74 07  je 0x1117a
00011173  c6 05 62 06 01 00 01  mov byte ptr [rip + 0x10662], 1
00011181  48 8d 0d 98 78 00 00  lea rcx, [rip + 0x7898]
0001118d  80 3d 48 06 01 00 01  cmp byte ptr [rip + 0x10648], 1
00011194  0f 85 bf 00 00 00  jne 0x11259
000111a0  48 8b 15 39 06 01 00  mov rdx, qword ptr [rip + 0x10639]
000111d0  ff 15 3a 3e 00 00  call qword ptr [rip + 0x3e3a]
000111d8  74 7f  je 0x11259
000111e2  e8 13 36 00 00  call 0x147fa
000111eb  72 3b  jb 0x11228
000111f2  75 34  jne 0x11228
000111f9  75 2d  jne 0x11228
000111ff  48 8d 3d ea 05 01 00  lea rdi, [rip + 0x105ea]
00011212  e8 e9 35 00 00  call 0x14800
0001121d  eb 25  jmp 0x11244
0001121f  48 8d 3d f5 77 00 00  lea rdi, [rip + 0x77f5]
00011226  eb 31  jmp 0x11259
00011228  48 8d 0d c1 05 01 00  lea rcx, [rip + 0x105c1]
00011238  e8 c3 35 00 00  call 0x14800
0001123d  48 8d 05 ab 07 01 00  lea rax, [rip + 0x107ab]
0001124c  ff 15 b6 3d 00 00  call qword ptr [rip + 0x3db6]
00011252  48 8d 3d 97 05 01 00  lea rdi, [rip + 0x10597]
00011264  e8 c7 35 00 00  call 0x14830
00011280  56  push rsi
0001128b  48 8b 05 6e d5 00 00  mov rax, qword ptr [rip + 0xd56e]
0001129c  74 61  je 0x112ff
000112a3  e8 58 fe ff ff  call 0x11100
000112ad  7e 3f  jle 0x112ee
000112b9  e8 32 0d 00 00  call 0x11ff0
000112d3  48 8d 3d f6 02 01 00  lea rdi, [rip + 0x102f6]
000112e6  e8 09 35 00 00  call 0x147f4
000112ee  48 8d 0d 22 77 00 00  lea rcx, [rip + 0x7722]
000112f8  e8 d3 39 00 00  call 0x14cd0
000112fd  eb 0c  jmp 0x1130b
000112ff  48 8d 0d 0f 77 00 00  lea rcx, [rip + 0x770f]
00011306  e8 c5 39 00 00  call 0x14cd0
00011313  e8 18 35 00 00  call 0x14830
00011320  48 83 ec 28  sub rsp, 0x28
00011338  e8 13 3e ff ff  call 0x5150
00011342  ff 25 e8 41 00 00  jmp qword ptr [rip + 0x41e8]
00011348  ff 25 d2 41 00 00  jmp qword ptr [rip + 0x41d2]
0001134e  ff 25 d4 41 00 00  jmp qword ptr [rip + 0x41d4]
00011354  ff 25 ae 41 00 00  jmp qword ptr [rip + 0x41ae]
0001135a  ff 25 a0 41 00 00  jmp qword ptr [rip + 0x41a0]
00011360  ff 25 92 41 00 00  jmp qword ptr [rip + 0x4192]
00011366  ff 25 84 41 00 00  jmp qword ptr [rip + 0x4184]
0001136c  ff 25 76 41 00 00  jmp qword ptr [rip + 0x4176]
00011372  ff 25 68 41 00 00  jmp qword ptr [rip + 0x4168]
00011378  ff 25 5a 41 00 00  jmp qword ptr [rip + 0x415a]
0001137e  ff 25 4c 41 00 00  jmp qword ptr [rip + 0x414c]
00011384  ff 25 3e 41 00 00  jmp qword ptr [rip + 0x413e]
0001138a  ff 25 30 41 00 00  jmp qword ptr [rip + 0x4130]
00011390  ff 25 22 41 00 00  jmp qword ptr [rip + 0x4122]
00011396  ff 25 14 41 00 00  jmp qword ptr [rip + 0x4114]
0001139c  ff 25 06 41 00 00  jmp qword ptr [rip + 0x4106]
000113a2  ff 25 f8 40 00 00  jmp qword ptr [rip + 0x40f8]
000113a8  ff 25 ea 40 00 00  jmp qword ptr [rip + 0x40ea]
000113ae  ff 25 dc 40 00 00  jmp qword ptr [rip + 0x40dc]
000113b4  ff 25 ce 40 00 00  jmp qword ptr [rip + 0x40ce]
000113ba  ff 25 c0 40 00 00  jmp qword ptr [rip + 0x40c0]
000113c0  ff 25 b2 40 00 00  jmp qword ptr [rip + 0x40b2]
000113c6  ff 25 a4 40 00 00  jmp qword ptr [rip + 0x40a4]
000113cc  ff 25 96 40 00 00  jmp qword ptr [rip + 0x4096]
000113d2  ff 25 88 40 00 00  jmp qword ptr [rip + 0x4088]
000113d8  ff 25 7a 40 00 00  jmp qword ptr [rip + 0x407a]
000113de  ff 25 6c 40 00 00  jmp qword ptr [rip + 0x406c]
000113e4  ff 25 5e 40 00 00  jmp qword ptr [rip + 0x405e]
000113ea  ff 25 50 40 00 00  jmp qword ptr [rip + 0x4050]
000113f0  ff 25 42 40 00 00  jmp qword ptr [rip + 0x4042]
000113f6  ff 25 34 40 00 00  jmp qword ptr [rip + 0x4034]
000113fc  ff 25 1e 40 00 00  jmp qword ptr [rip + 0x401e]
00011402  ff 25 20 40 00 00  jmp qword ptr [rip + 0x4020]
00011408  ff 25 0a 40 00 00  jmp qword ptr [rip + 0x400a]
0001140e  ff 25 fc 3f 00 00  jmp qword ptr [rip + 0x3ffc]
00011414  ff 25 ee 3f 00 00  jmp qword ptr [rip + 0x3fee]
0001141a  ff 25 e0 3f 00 00  jmp qword ptr [rip + 0x3fe0]
00011420  ff 25 d2 3f 00 00  jmp qword ptr [rip + 0x3fd2]
00011426  ff 25 c4 3f 00 00  jmp qword ptr [rip + 0x3fc4]
0001142c  ff 25 b6 3f 00 00  jmp qword ptr [rip + 0x3fb6]
00011432  ff 25 a8 3f 00 00  jmp qword ptr [rip + 0x3fa8]
00011438  ff 25 9a 3f 00 00  jmp qword ptr [rip + 0x3f9a]
0001143e  ff 25 8c 3f 00 00  jmp qword ptr [rip + 0x3f8c]
00011444  ff 25 7e 3f 00 00  jmp qword ptr [rip + 0x3f7e]
0001144a  ff 25 70 3f 00 00  jmp qword ptr [rip + 0x3f70]
00011450  ff 25 32 3f 00 00  jmp qword ptr [rip + 0x3f32]
00011456  ff 25 14 3f 00 00  jmp qword ptr [rip + 0x3f14]
0001145c  ff 25 36 3e 00 00  jmp qword ptr [rip + 0x3e36]
00011462  ff 25 50 3f 00 00  jmp qword ptr [rip + 0x3f50]
00011468  ff 25 3a 3f 00 00  jmp qword ptr [rip + 0x3f3a]
0001146e  ff 25 2c 3f 00 00  jmp qword ptr [rip + 0x3f2c]
00011474  ff 25 1e 3f 00 00  jmp qword ptr [rip + 0x3f1e]
0001147a  ff 25 10 3f 00 00  jmp qword ptr [rip + 0x3f10]
00011480  ff 25 fa 3e 00 00  jmp qword ptr [rip + 0x3efa]
00011486  ff 25 14 3e 00 00  jmp qword ptr [rip + 0x3e14]
0001148c  ff 25 e6 3e 00 00  jmp qword ptr [rip + 0x3ee6]
00011492  ff 25 30 3d 00 00  jmp qword ptr [rip + 0x3d30]
00011498  ff 25 32 3d 00 00  jmp qword ptr [rip + 0x3d32]
0001149e  ff 25 34 3d 00 00  jmp qword ptr [rip + 0x3d34]
000114a4  ff 25 36 3d 00 00  jmp qword ptr [rip + 0x3d36]
000114aa  ff 25 38 3d 00 00  jmp qword ptr [rip + 0x3d38]
000114b0  ff 25 3a 3d 00 00  jmp qword ptr [rip + 0x3d3a]
000114b6  ff 25 3c 3d 00 00  jmp qword ptr [rip + 0x3d3c]
000114bc  ff 25 3e 3d 00 00  jmp qword ptr [rip + 0x3d3e]
000114c2  ff 25 40 3d 00 00  jmp qword ptr [rip + 0x3d40]
000114c8  ff 25 42 3d 00 00  jmp qword ptr [rip + 0x3d42]
000114ce  ff 25 44 3d 00 00  jmp qword ptr [rip + 0x3d44]
000114d4  ff 25 46 3d 00 00  jmp qword ptr [rip + 0x3d46]
000114da  ff 25 48 3d 00 00  jmp qword ptr [rip + 0x3d48]
000114e0  ff 25 4a 3d 00 00  jmp qword ptr [rip + 0x3d4a]
000114e6  ff 25 4c 3d 00 00  jmp qword ptr [rip + 0x3d4c]
000114ec  ff 25 4e 3d 00 00  jmp qword ptr [rip + 0x3d4e]
000114f2  ff 25 50 3d 00 00  jmp qword ptr [rip + 0x3d50]
000114f8  ff 25 52 3d 00 00  jmp qword ptr [rip + 0x3d52]
000114fe  ff 25 54 3d 00 00  jmp qword ptr [rip + 0x3d54]
00011504  ff 25 56 3d 00 00  jmp qword ptr [rip + 0x3d56]
0001150a  ff 25 58 3d 00 00  jmp qword ptr [rip + 0x3d58]
00011510  ff 25 5a 3d 00 00  jmp qword ptr [rip + 0x3d5a]
00011516  ff 25 5c 3d 00 00  jmp qword ptr [rip + 0x3d5c]
0001151c  ff 25 5e 3d 00 00  jmp qword ptr [rip + 0x3d5e]
00011522  ff 25 60 3d 00 00  jmp qword ptr [rip + 0x3d60]
00011528  ff 25 62 3d 00 00  jmp qword ptr [rip + 0x3d62]
0001152e  ff 25 dc 3f 00 00  jmp qword ptr [rip + 0x3fdc]
00011534  ff 25 76 3e 00 00  jmp qword ptr [rip + 0x3e76]
0001153a  ff 25 68 3d 00 00  jmp qword ptr [rip + 0x3d68]
00011540  ff 25 6a 3d 00 00  jmp qword ptr [rip + 0x3d6a]
00011546  ff 25 6c 3d 00 00  jmp qword ptr [rip + 0x3d6c]
0001154c  ff 25 6e 3d 00 00  jmp qword ptr [rip + 0x3d6e]
00011552  ff 25 70 3d 00 00  jmp qword ptr [rip + 0x3d70]
00011558  ff 25 72 3d 00 00  jmp qword ptr [rip + 0x3d72]
0001155e  ff 25 74 3d 00 00  jmp qword ptr [rip + 0x3d74]
00011564  ff 25 76 3d 00 00  jmp qword ptr [rip + 0x3d76]
0001156a  ff 25 78 3d 00 00  jmp qword ptr [rip + 0x3d78]
00011570  ff 25 7a 3d 00 00  jmp qword ptr [rip + 0x3d7a]
00011576  ff 25 7c 3d 00 00  jmp qword ptr [rip + 0x3d7c]
0001157c  ff 25 7e 3d 00 00  jmp qword ptr [rip + 0x3d7e]
00011582  ff 25 80 3d 00 00  jmp qword ptr [rip + 0x3d80]
00011588  ff 25 82 3d 00 00  jmp qword ptr [rip + 0x3d82]
0001158e  ff 25 84 3d 00 00  jmp qword ptr [rip + 0x3d84]
00011594  ff 25 86 3d 00 00  jmp qword ptr [rip + 0x3d86]
0001159a  ff 25 88 3d 00 00  jmp qword ptr [rip + 0x3d88]
000115a0  ff 25 8a 3d 00 00  jmp qword ptr [rip + 0x3d8a]
000115a6  ff 25 8c 3d 00 00  jmp qword ptr [rip + 0x3d8c]
000115ac  ff 25 8e 3d 00 00  jmp qword ptr [rip + 0x3d8e]
000115b2  ff 25 90 3d 00 00  jmp qword ptr [rip + 0x3d90]
000115b8  ff 25 92 3d 00 00  jmp qword ptr [rip + 0x3d92]
000115be  ff 25 94 3d 00 00  jmp qword ptr [rip + 0x3d94]
000115c4  ff 25 96 3d 00 00  jmp qword ptr [rip + 0x3d96]
000115ca  ff 25 98 3d 00 00  jmp qword ptr [rip + 0x3d98]
000115d0  ff 25 f2 46 00 00  jmp qword ptr [rip + 0x46f2]
000115d6  ff 25 e4 46 00 00  jmp qword ptr [rip + 0x46e4]
000115dc  ff 25 b6 46 00 00  jmp qword ptr [rip + 0x46b6]
000115e2  ff 25 a8 46 00 00  jmp qword ptr [rip + 0x46a8]
000115e8  ff 25 c2 46 00 00  jmp qword ptr [rip + 0x46c2]
000115ee  ff 25 b4 46 00 00  jmp qword ptr [rip + 0x46b4]
000115f4  ff 25 a6 46 00 00  jmp qword ptr [rip + 0x46a6]
000115fa  ff 25 80 46 00 00  jmp qword ptr [rip + 0x4680]
00011600  ff 25 1a 46 00 00  jmp qword ptr [rip + 0x461a]
00011606  ff 25 1c 46 00 00  jmp qword ptr [rip + 0x461c]
0001160c  ff 25 1e 46 00 00  jmp qword ptr [rip + 0x461e]
00011612  ff 25 20 46 00 00  jmp qword ptr [rip + 0x4620]
00011618  ff 25 42 46 00 00  jmp qword ptr [rip + 0x4642]
0001161e  ff 25 34 46 00 00  jmp qword ptr [rip + 0x4634]
00011624  ff 25 26 46 00 00  jmp qword ptr [rip + 0x4626]
0001162a  ff 25 18 46 00 00  jmp qword ptr [rip + 0x4618]
00011630  ff 25 0a 46 00 00  jmp qword ptr [rip + 0x460a]
00011636  ff 25 d4 3f 00 00  jmp qword ptr [rip + 0x3fd4]
0001163c  ff 25 c6 3f 00 00  jmp qword ptr [rip + 0x3fc6]
00011642  ff 25 b8 3f 00 00  jmp qword ptr [rip + 0x3fb8]
00011648  ff 25 aa 3f 00 00  jmp qword ptr [rip + 0x3faa]
0001164e  ff 25 9c 3f 00 00  jmp qword ptr [rip + 0x3f9c]
00011654  ff 25 8e 3f 00 00  jmp qword ptr [rip + 0x3f8e]
0001165a  ff 25 80 3f 00 00  jmp qword ptr [rip + 0x3f80]
00011660  ff 25 72 3f 00 00  jmp qword ptr [rip + 0x3f72]
00011666  ff 25 64 3f 00 00  jmp qword ptr [rip + 0x3f64]
0001166c  ff 25 56 3f 00 00  jmp qword ptr [rip + 0x3f56]
00011672  ff 25 48 3f 00 00  jmp qword ptr [rip + 0x3f48]
00011678  ff 25 3a 3f 00 00  jmp qword ptr [rip + 0x3f3a]
0001167e  ff 25 2c 3f 00 00  jmp qword ptr [rip + 0x3f2c]
00011684  ff 25 8e 3f 00 00  jmp qword ptr [rip + 0x3f8e]
0001168a  ff 25 08 3f 00 00  jmp qword ptr [rip + 0x3f08]
00011690  ff 25 fa 3e 00 00  jmp qword ptr [rip + 0x3efa]
00011696  ff 25 ec 3e 00 00  jmp qword ptr [rip + 0x3eec]
0001169c  ff 25 de 3e 00 00  jmp qword ptr [rip + 0x3ede]
000116a2  ff 25 f8 3e 00 00  jmp qword ptr [rip + 0x3ef8]
000116a8  ff 25 fa 3e 00 00  jmp qword ptr [rip + 0x3efa]
000116ae  ff 25 c4 41 00 00  jmp qword ptr [rip + 0x41c4]
000116b4  ff 25 b6 41 00 00  jmp qword ptr [rip + 0x41b6]
000116ba  ff 25 50 45 00 00  jmp qword ptr [rip + 0x4550]
000116c0  ff 25 42 45 00 00  jmp qword ptr [rip + 0x4542]
000116c6  ff 25 64 40 00 00  jmp qword ptr [rip + 0x4064]
000116cc  ff 25 66 40 00 00  jmp qword ptr [rip + 0x4066]
000116d2  ff 25 68 40 00 00  jmp qword ptr [rip + 0x4068]
000116d8  ff 25 ca 40 00 00  jmp qword ptr [rip + 0x40ca]
000116de  ff 25 cc 40 00 00  jmp qword ptr [rip + 0x40cc]
000116e4  ff 25 ce 40 00 00  jmp qword ptr [rip + 0x40ce]
000116ea  ff 25 d0 40 00 00  jmp qword ptr [rip + 0x40d0]
000116f0  ff 25 82 3f 00 00  jmp qword ptr [rip + 0x3f82]
000116f6  ff 25 dc 40 00 00  jmp qword ptr [rip + 0x40dc]
000116fc  ff 25 ce 40 00 00  jmp qword ptr [rip + 0x40ce]
00011702  ff 25 c0 40 00 00  jmp qword ptr [rip + 0x40c0]
00011708  ff 25 5a 40 00 00  jmp qword ptr [rip + 0x405a]
0001170e  ff 25 4c 40 00 00  jmp qword ptr [rip + 0x404c]
00011714  ff 25 3e 40 00 00  jmp qword ptr [rip + 0x403e]
0001171a  ff 25 30 40 00 00  jmp qword ptr [rip + 0x4030]
00011720  ff 25 22 40 00 00  jmp qword ptr [rip + 0x4022]
00011726  ff 25 f4 3f 00 00  jmp qword ptr [rip + 0x3ff4]
0001172c  ff 25 e6 3f 00 00  jmp qword ptr [rip + 0x3fe6]
00011732  ff 25 d8 3f 00 00  jmp qword ptr [rip + 0x3fd8]
00011738  ff 25 ca 3f 00 00  jmp qword ptr [rip + 0x3fca]
0001173e  ff 25 bc 3f 00 00  jmp qword ptr [rip + 0x3fbc]
00011744  ff 25 ae 3f 00 00  jmp qword ptr [rip + 0x3fae]
0001174a  ff 25 a0 3f 00 00  jmp qword ptr [rip + 0x3fa0]
00011750  ff 25 92 3f 00 00  jmp qword ptr [rip + 0x3f92]
00011756  ff 25 3c 40 00 00  jmp qword ptr [rip + 0x403c]
0001175c  ff 25 76 3f 00 00  jmp qword ptr [rip + 0x3f76]
00011762  ff 25 68 3f 00 00  jmp qword ptr [rip + 0x3f68]
00011768  ff 25 5a 3f 00 00  jmp qword ptr [rip + 0x3f5a]
0001176e  ff 25 4c 3f 00 00  jmp qword ptr [rip + 0x3f4c]
00011774  ff 25 3e 3f 00 00  jmp qword ptr [rip + 0x3f3e]
0001177a  ff 25 30 3f 00 00  jmp qword ptr [rip + 0x3f30]
00011780  ff 25 22 3f 00 00  jmp qword ptr [rip + 0x3f22]
00011786  ff 25 14 3f 00 00  jmp qword ptr [rip + 0x3f14]
0001178c  ff 25 06 3f 00 00  jmp qword ptr [rip + 0x3f06]
00011792  ff 25 f8 3e 00 00  jmp qword ptr [rip + 0x3ef8]
00011798  ff 25 ea 3e 00 00  jmp qword ptr [rip + 0x3eea]
0001179e  ff 25 dc 3e 00 00  jmp qword ptr [rip + 0x3edc]
000117a4  ff 25 f6 3f 00 00  jmp qword ptr [rip + 0x3ff6]
000117aa  ff 25 e0 3f 00 00  jmp qword ptr [rip + 0x3fe0]
000117b0  ff 25 d2 3f 00 00  jmp qword ptr [rip + 0x3fd2]
000117b6  ff 25 c4 3f 00 00  jmp qword ptr [rip + 0x3fc4]
000117bc  ff 25 b6 3f 00 00  jmp qword ptr [rip + 0x3fb6]
000117c2  ff 25 a8 3f 00 00  jmp qword ptr [rip + 0x3fa8]
000117c8  ff 25 5a 3f 00 00  jmp qword ptr [rip + 0x3f5a]
000117ce  ff 25 0c 3f 00 00  jmp qword ptr [rip + 0x3f0c]
000117d4  ff 25 86 3e 00 00  jmp qword ptr [rip + 0x3e86]
000117da  ff 25 88 3e 00 00  jmp qword ptr [rip + 0x3e88]
000117e0  ff 25 8a 3e 00 00  jmp qword ptr [rip + 0x3e8a]
000117e6  ff 25 f4 3f 00 00  jmp qword ptr [rip + 0x3ff4]
000117ec  ff 25 26 43 00 00  jmp qword ptr [rip + 0x4326]
000117f2  ff 25 18 43 00 00  jmp qword ptr [rip + 0x4318]
000117f8  ff 25 0a 43 00 00  jmp qword ptr [rip + 0x430a]
000117fe  ff 25 24 43 00 00  jmp qword ptr [rip + 0x4324]
00011804  ff 25 56 43 00 00  jmp qword ptr [rip + 0x4356]
0001180a  ff 25 58 43 00 00  jmp qword ptr [rip + 0x4358]
00011810  ff 25 5a 43 00 00  jmp qword ptr [rip + 0x435a]
00011816  ff 25 5c 43 00 00  jmp qword ptr [rip + 0x435c]
0001181c  ff 25 fe 42 00 00  jmp qword ptr [rip + 0x42fe]
00011822  ff 25 08 43 00 00  jmp qword ptr [rip + 0x4308]
00011828  ff 25 0a 43 00 00  jmp qword ptr [rip + 0x430a]
0001182e  ff 25 0c 43 00 00  jmp qword ptr [rip + 0x430c]
00011834  ff 25 0e 43 00 00  jmp qword ptr [rip + 0x430e]
0001183a  ff 25 10 43 00 00  jmp qword ptr [rip + 0x4310]
00011840  ff 25 12 43 00 00  jmp qword ptr [rip + 0x4312]
00011846  ff 25 34 43 00 00  jmp qword ptr [rip + 0x4334]
0001184c  ff 25 9e 3f 00 00  jmp qword ptr [rip + 0x3f9e]
00011852  ff 25 f0 3f 00 00  jmp qword ptr [rip + 0x3ff0]
00011858  ff 25 e2 3f 00 00  jmp qword ptr [rip + 0x3fe2]
0001185e  ff 25 d4 3f 00 00  jmp qword ptr [rip + 0x3fd4]
00011864  ff 25 c6 3f 00 00  jmp qword ptr [rip + 0x3fc6]
0001186a  ff 25 b8 3f 00 00  jmp qword ptr [rip + 0x3fb8]
00011870  ff 25 aa 3f 00 00  jmp qword ptr [rip + 0x3faa]
00011876  ff 25 9c 3f 00 00  jmp qword ptr [rip + 0x3f9c]
0001187c  ff 25 8e 3f 00 00  jmp qword ptr [rip + 0x3f8e]
00011882  ff 25 80 3f 00 00  jmp qword ptr [rip + 0x3f80]
00011888  ff 25 72 3f 00 00  jmp qword ptr [rip + 0x3f72]
0001188e  ff 25 64 3f 00 00  jmp qword ptr [rip + 0x3f64]
00011894  ff 25 d6 41 00 00  jmp qword ptr [rip + 0x41d6]
0001189a  ff 25 d8 41 00 00  jmp qword ptr [rip + 0x41d8]
000118a0  ff 25 da 41 00 00  jmp qword ptr [rip + 0x41da]
000118a6  ff 25 14 42 00 00  jmp qword ptr [rip + 0x4214]
000118ac  ff 25 26 42 00 00  jmp qword ptr [rip + 0x4226]
000118b2  ff 25 18 42 00 00  jmp qword ptr [rip + 0x4218]
000118b8  ff 25 fa 41 00 00  jmp qword ptr [rip + 0x41fa]
000118be  ff 25 ec 41 00 00  jmp qword ptr [rip + 0x41ec]
000118c4  ff 25 de 41 00 00  jmp qword ptr [rip + 0x41de]
000118ca  ff 25 d0 41 00 00  jmp qword ptr [rip + 0x41d0]
000118d0  ff 25 c2 41 00 00  jmp qword ptr [rip + 0x41c2]
000118d6  ff 25 b4 41 00 00  jmp qword ptr [rip + 0x41b4]
000118dc  ff 25 a6 41 00 00  jmp qword ptr [rip + 0x41a6]
000118e2  ff 25 68 41 00 00  jmp qword ptr [rip + 0x4168]
000118e8  ff 25 7a 41 00 00  jmp qword ptr [rip + 0x417a]
000118ee  ff 25 ec 41 00 00  jmp qword ptr [rip + 0x41ec]
000118f4  ff 25 ce 41 00 00  jmp qword ptr [rip + 0x41ce]
000118fa  ff 25 60 41 00 00  jmp qword ptr [rip + 0x4160]
00011900  ff 25 52 41 00 00  jmp qword ptr [rip + 0x4152]
00011906  ff 25 dc 41 00 00  jmp qword ptr [rip + 0x41dc]
0001190c  ff 25 36 41 00 00  jmp qword ptr [rip + 0x4136]
00011912  ff 25 28 41 00 00  jmp qword ptr [rip + 0x4128]
00011918  ff 25 1a 41 00 00  jmp qword ptr [rip + 0x411a]
0001191e  ff 25 0c 41 00 00  jmp qword ptr [rip + 0x410c]
00011924  ff 25 fe 40 00 00  jmp qword ptr [rip + 0x40fe]
0001192a  ff 25 f0 40 00 00  jmp qword ptr [rip + 0x40f0]
00011930  ff 25 e2 40 00 00  jmp qword ptr [rip + 0x40e2]
00011936  ff 25 d4 40 00 00  jmp qword ptr [rip + 0x40d4]
0001193c  ff 25 c6 40 00 00  jmp qword ptr [rip + 0x40c6]
00011942  ff 25 b8 40 00 00  jmp qword ptr [rip + 0x40b8]
00011948  ff 25 aa 40 00 00  jmp qword ptr [rip + 0x40aa]
0001194e  ff 25 9c 40 00 00  jmp qword ptr [rip + 0x409c]
00011954  ff 25 8e 40 00 00  jmp qword ptr [rip + 0x408e]
0001195a  ff 25 80 40 00 00  jmp qword ptr [rip + 0x4080]
00011960  ff 25 72 40 00 00  jmp qword ptr [rip + 0x4072]
00011966  ff 25 64 40 00 00  jmp qword ptr [rip + 0x4064]
0001196c  ff 25 56 40 00 00  jmp qword ptr [rip + 0x4056]
00011972  ff 25 28 42 00 00  jmp qword ptr [rip + 0x4228]
00011978  ff 25 1a 42 00 00  jmp qword ptr [rip + 0x421a]
0001197e  ff 25 0c 42 00 00  jmp qword ptr [rip + 0x420c]
00011984  ff 25 1e 42 00 00  jmp qword ptr [rip + 0x421e]
0001198a  ff 25 20 42 00 00  jmp qword ptr [rip + 0x4220]
00011990  ff 25 22 42 00 00  jmp qword ptr [rip + 0x4222]
00011996  ff 25 5c 42 00 00  jmp qword ptr [rip + 0x425c]
0001199c  ff 25 1e 42 00 00  jmp qword ptr [rip + 0x421e]
000119a2  ff 25 20 42 00 00  jmp qword ptr [rip + 0x4220]
000119a8  ff 25 22 42 00 00  jmp qword ptr [rip + 0x4222]
000119ae  ff 25 24 42 00 00  jmp qword ptr [rip + 0x4224]
000119b4  ff 25 26 42 00 00  jmp qword ptr [rip + 0x4226]
000119ba  ff 25 28 42 00 00  jmp qword ptr [rip + 0x4228]
000119c0  ff 25 2a 42 00 00  jmp qword ptr [rip + 0x422a]
000119c6  ff 25 2c 41 00 00  jmp qword ptr [rip + 0x412c]
000119cc  ff 25 e6 3f 00 00  jmp qword ptr [rip + 0x3fe6]
000119d2  ff 25 68 3f 00 00  jmp qword ptr [rip + 0x3f68]
000119d8  ff 25 6a 3f 00 00  jmp qword ptr [rip + 0x3f6a]
000119de  ff 25 6c 3f 00 00  jmp qword ptr [rip + 0x3f6c]
000119e4  ff 25 6e 3f 00 00  jmp qword ptr [rip + 0x3f6e]
000119ea  ff 25 70 3f 00 00  jmp qword ptr [rip + 0x3f70]
000119f0  ff 25 72 3f 00 00  jmp qword ptr [rip + 0x3f72]
000119f6  ff 25 74 3f 00 00  jmp qword ptr [rip + 0x3f74]
000119fc  ff 25 76 3f 00 00  jmp qword ptr [rip + 0x3f76]
00011a02  ff 25 78 3f 00 00  jmp qword ptr [rip + 0x3f78]
00011a08  ff 25 7a 3f 00 00  jmp qword ptr [rip + 0x3f7a]
00011a0e  ff 25 7c 3f 00 00  jmp qword ptr [rip + 0x3f7c]
00011a14  ff 25 7e 3f 00 00  jmp qword ptr [rip + 0x3f7e]
00011a1a  ff 25 80 3f 00 00  jmp qword ptr [rip + 0x3f80]
00011a20  ff 25 82 3f 00 00  jmp qword ptr [rip + 0x3f82]
00011a26  ff 25 0c 3f 00 00  jmp qword ptr [rip + 0x3f0c]
00011a2c  ff 25 fe 3e 00 00  jmp qword ptr [rip + 0x3efe]
00011a32  ff 25 d8 3e 00 00  jmp qword ptr [rip + 0x3ed8]
00011a38  ff 25 5a 3e 00 00  jmp qword ptr [rip + 0x3e5a]
00011a3e  ff 25 4c 3e 00 00  jmp qword ptr [rip + 0x3e4c]
00011a44  ff 25 de 3e 00 00  jmp qword ptr [rip + 0x3ede]
00011a4a  ff 25 88 3e 00 00  jmp qword ptr [rip + 0x3e88]
00011a50  ff 25 72 3e 00 00  jmp qword ptr [rip + 0x3e72]
00011a56  ff 25 74 3e 00 00  jmp qword ptr [rip + 0x3e74]
00011a5c  ff 25 be 3e 00 00  jmp qword ptr [rip + 0x3ebe]
00011a62  ff 25 20 3e 00 00  jmp qword ptr [rip + 0x3e20]
00011a68  ff 25 32 3e 00 00  jmp qword ptr [rip + 0x3e32]
00011a6e  ff 25 34 3e 00 00  jmp qword ptr [rip + 0x3e34]
00011a74  ff 25 36 3e 00 00  jmp qword ptr [rip + 0x3e36]
00011a7a  ff 25 38 3e 00 00  jmp qword ptr [rip + 0x3e38]
00011a80  ff 25 3a 3e 00 00  jmp qword ptr [rip + 0x3e3a]
00011a86  ff 25 54 3e 00 00  jmp qword ptr [rip + 0x3e54]
00011a8c  ff 25 56 3e 00 00  jmp qword ptr [rip + 0x3e56]
00011a92  ff 25 58 3e 00 00  jmp qword ptr [rip + 0x3e58]
00011a98  ff 25 5a 3e 00 00  jmp qword ptr [rip + 0x3e5a]
00011a9e  ff 25 5c 3e 00 00  jmp qword ptr [rip + 0x3e5c]
00011aa4  ff 25 5e 3e 00 00  jmp qword ptr [rip + 0x3e5e]
00011aaa  ff 25 68 3e 00 00  jmp qword ptr [rip + 0x3e68]
00011ab0  ff 25 22 42 00 00  jmp qword ptr [rip + 0x4222]
00011ab6  ff 25 24 42 00 00  jmp qword ptr [rip + 0x4224]
00011abc  ff 25 86 3a 00 00  jmp qword ptr [rip + 0x3a86]
00011ac2  ff 25 78 3a 00 00  jmp qword ptr [rip + 0x3a78]
00011ac8  ff 25 32 36 00 00  jmp qword ptr [rip + 0x3632]
00011ace  ff 25 24 36 00 00  jmp qword ptr [rip + 0x3624]
00011ad4  ff 25 16 36 00 00  jmp qword ptr [rip + 0x3616]
00011ada  ff 25 90 41 00 00  jmp qword ptr [rip + 0x4190]
00011ae0  ff 25 6a 3b 00 00  jmp qword ptr [rip + 0x3b6a]
00011ae6  ff 25 6c 3d 00 00  jmp qword ptr [rip + 0x3d6c]
00011aec  ff 25 6e 3d 00 00  jmp qword ptr [rip + 0x3d6e]
00011af2  ff 25 48 3b 00 00  jmp qword ptr [rip + 0x3b48]
00011af8  ff 25 2a 3b 00 00  jmp qword ptr [rip + 0x3b2a]
00011afe  ff 25 2c 3b 00 00  jmp qword ptr [rip + 0x3b2c]
00011b04  ff 25 2e 3b 00 00  jmp qword ptr [rip + 0x3b2e]
00011b0a  ff 25 60 3a 00 00  jmp qword ptr [rip + 0x3a60]
00011b10  ff 25 42 3a 00 00  jmp qword ptr [rip + 0x3a42]
00011b16  ff 25 44 3a 00 00  jmp qword ptr [rip + 0x3a44]
00011b1c  ff 25 46 3a 00 00  jmp qword ptr [rip + 0x3a46]
00011b24  48 83 ec 28  sub rsp, 0x28
00011b2a  74 39  je 0x11b65
00011b2f  74 28  je 0x11b59
00011b34  74 16  je 0x11b4c
00011b39  74 0a  je 0x11b45
00011b45  e8 26 06 00 00  call 0x12170
00011b4a  eb 05  jmp 0x11b51
00011b4c  e8 f7 05 00 00  call 0x12148
00011b60  e9 0f 00 00 00  jmp 0x11b74
00011b6f  e9 18 01 00 00  jmp 0x11c8c
00011b74  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00011b91  e8 96 06 00 00  call 0x1222c
00011b98  0f 84 c8 00 00 00  je 0x11c66
00011b9e  e8 1d 05 00 00  call 0x120c0
00011bac  83 3d 7d ee 00 00 00  cmp dword ptr [rip + 0xee7d], 0
00011bb3  0f 85 c5 00 00 00  jne 0x11c7e
00011bb9  c7 05 6d ee 00 00 01 00 00 00  mov dword ptr [rip + 0xee6d], 1
00011bc3  e8 68 05 00 00  call 0x12130
00011bca  74 4f  je 0x11c1b
00011bcc  e8 e3 0a 00 00  call 0x126b4
00011bd1  e8 fe 03 00 00  call 0x11fd4
00011bd6  e8 25 04 00 00  call 0x12000
00011bdb  48 8d 15 66 41 00 00  lea rdx, [rip + 0x4166]
00011be2  48 8d 0d 57 41 00 00  lea rcx, [rip + 0x4157]
00011be9  e8 b8 2b 00 00  call 0x147a6
00011bf0  75 29  jne 0x11c1b
00011bf2  e8 05 05 00 00  call 0x120fc
00011bf9  74 20  je 0x11c1b
00011bfb  48 8d 15 36 41 00 00  lea rdx, [rip + 0x4136]
00011c02  48 8d 0d 1f 41 00 00  lea rcx, [rip + 0x411f]
00011c09  e8 92 2b 00 00  call 0x147a0
00011c0e  c7 05 18 ee 00 00 02 00 00 00  mov dword ptr [rip + 0xee18], 2
00011c1d  e8 6a 07 00 00  call 0x1238c
00011c25  75 3f  jne 0x11c66
00011c27  e8 24 08 00 00  call 0x12450
00011c33  74 24  je 0x11c59
00011c38  e8 b7 06 00 00  call 0x122f4
00011c3f  74 18  je 0x11c59
00011c4f  4c 8b 0d aa 40 00 00  mov r9, qword ptr [rip + 0x40aa]
00011c56  41 ff d1  call r9
00011c59  ff 05 a1 ed 00 00  inc dword ptr [rip + 0xeda1]
00011c64  eb 02  jmp 0x11c68
00011c83  e8 d8 07 00 00  call 0x12460
00011c8c  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00011c99  8b 05 61 ed 00 00  mov eax, dword ptr [rip + 0xed61]
00011ca1  7f 0d  jg 0x11cb0
00011cb2  89 05 48 ed 00 00  mov dword ptr [rip + 0xed48], eax
00011cb8  e8 03 04 00 00  call 0x120c0
00011cc3  83 3d 66 ed 00 00 02  cmp dword ptr [rip + 0xed66], 2
00011cca  75 33  jne 0x11cff
00011ccc  e8 17 05 00 00  call 0x121e8
00011cd1  e8 0e 03 00 00  call 0x11fe4
00011cd6  e8 15 0a 00 00  call 0x126f0
00011cdb  83 25 4e ed 00 00 00  and dword ptr [rip + 0xed4e], 0
00011ce4  e8 a3 06 00 00  call 0x1238c
00011cee  e8 bd 06 00 00  call 0x123b0
00011cf6  e8 1d 05 00 00  call 0x12218
00011cfd  eb a6  jmp 0x11ca5
00011d04  e8 57 07 00 00  call 0x12460
00011d0c  48 8b c4  mov rax, rsp
00011d30  75 0f  jne 0x11d41
00011d32  39 15 c8 ec 00 00  cmp dword ptr [rip + 0xecc8], edx
00011d38  7f 07  jg 0x11d41
00011d3c  e9 e5 00 00 00  jmp 0x11e26
00011d47  77 40  ja 0x11d89
00011d49  48 8b 05 08 5f 00 00  mov rax, qword ptr [rip + 0x5f08]
00011d53  75 05  jne 0x11d5a
00011d58  eb 08  jmp 0x11d62
00011d5a  ff 15 a0 3f 00 00  call qword ptr [rip + 0x3fa0]
00011d68  0f 84 ae 00 00 00  je 0x11e1c
00011d76  e8 a9 fd ff ff  call 0x11b24
00011d83  0f 84 93 00 00 00  je 0x11e1c
00011d91  e8 1a 02 00 00  call 0x11fb0
00011d9f  75 36  jne 0x11dd7
00011da3  75 32  jne 0x11dd7
00011dad  e8 fe 01 00 00  call 0x11fb0
00011db8  e8 cf fe ff ff  call 0x11c8c
00011dbd  48 8b 05 94 5e 00 00  mov rax, qword ptr [rip + 0x5e94]
00011dc7  74 0e  je 0x11dd7
00011dd1  ff 15 29 3f 00 00  call qword ptr [rip + 0x3f29]
00011dd9  74 05  je 0x11de0
00011dde  75 3c  jne 0x11e1c
00011de8  e8 37 fd ff ff  call 0x11b24
00011df5  74 25  je 0x11e1c
00011df7  48 8b 05 5a 5e 00 00  mov rax, qword ptr [rip + 0x5e5a]
00011e01  75 05  jne 0x11e08
00011e06  eb 10  jmp 0x11e18
00011e10  ff 15 ea 3e 00 00  call qword ptr [rip + 0x3eea]
00011e1c  eb 06  jmp 0x11e24
00011e34  48 8b 05 1d 5e 00 00  mov rax, qword ptr [rip + 0x5e1d]
00011e3e  75 06  jne 0x11e46
00011e46  48 ff 25 b3 3e 00 00  jmp qword ptr [rip + 0x3eb3]
00011e50  e9 cf fc ff ff  jmp 0x11b24
00011e58  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00011e72  75 05  jne 0x11e79
00011e74  e8 8b 00 00 00  call 0x11f04
00011e90  e9 77 fe ff ff  jmp 0x11d0c
00011e98  40 55  push rbp
00011eaa  ff 15 90 31 00 00  call qword ptr [rip + 0x3190]
00011eb8  ff 15 7a 31 00 00  call qword ptr [rip + 0x317a]
00011ec4  ff 15 66 31 00 00  call qword ptr [rip + 0x3166]
00011ed4  ff 15 4e 31 00 00  call qword ptr [rip + 0x314e]
00011f04  48 89 5c 24 18  mov qword ptr [rsp + 0x18], rbx
00011f11  48 8b 05 e8 c8 00 00  mov rax, qword ptr [rip + 0xc8e8]
00011f25  75 74  jne 0x11f9b
00011f30  ff 15 0a 31 00 00  call qword ptr [rip + 0x310a]
00011f3e  ff 15 f4 30 00 00  call qword ptr [rip + 0x30f4]
00011f4a  ff 15 e0 30 00 00  call qword ptr [rip + 0x30e0]
00011f5a  ff 15 c8 30 00 00  call qword ptr [rip + 0x30c8]
00011f94  48 89 05 65 c8 00 00  mov qword ptr [rip + 0xc865], rax
00011fa3  48 89 05 96 c8 00 00  mov qword ptr [rip + 0xc896], rax
00011fb0  48 83 ec 28  sub rsp, 0x28
00011fb7  75 10  jne 0x11fc9
00011fb9  48 83 3d 97 5c 00 00 00  cmp qword ptr [rip + 0x5c97], 0
00011fc1  75 06  jne 0x11fc9
00011fc3  ff 15 7f 30 00 00  call qword ptr [rip + 0x307f]
00011fd4  48 8d 0d 35 ea 00 00  lea rcx, [rip + 0xea35]
00011fdb  48 ff 25 6e 30 00 00  jmp qword ptr [rip + 0x306e]
00011fe4  48 8d 0d 25 ea 00 00  lea rcx, [rip + 0xea25]
00011feb  e9 92 27 00 00  jmp 0x14782
00011ff0  48 8d 05 29 ea 00 00  lea rax, [rip + 0xea29]
00011ff8  48 8d 05 29 ea 00 00  lea rax, [rip + 0xea29]
00012000  48 83 ec 28  sub rsp, 0x28
00012004  e8 e7 ff ff ff  call 0x11ff0
0001200d  e8 e6 ff ff ff  call 0x11ff8
0001201c  48 83 ec 28  sub rsp, 0x28
00012020  e8 37 0c 00 00  call 0x12c5c
0001202b  e9 82 27 00 00  jmp 0x147b2
00012030  4c 63 41 3c  movsxd r8, dword ptr [rcx + 0x3c]
00012053  eb 18  jmp 0x1206d
0001205c  72 0b  jb 0x12069
00012067  72 0c  jb 0x12075
00012070  75 e3  jne 0x12055
0001207c  e9 37 27 00 00  jmp 0x147b8
00012084  48 85 c9  test rcx, rcx
00012087  74 26  je 0x120af
00012091  75 1c  jne 0x120af
000120a0  75 0d  jne 0x120af
000120b4  65 48 8b 04 25 30 00 00 00  mov rax, qword ptr gs:[0x30]
000120c0  48 83 ec 28  sub rsp, 0x28
000120c4  e8 9b 0b 00 00  call 0x12c64
000120cb  74 21  je 0x120ee
000120da  eb 05  jmp 0x120e1
000120df  74 14  je 0x120f5
000120e3  f0 48 0f b1 0d 4c e9 00 00  lock cmpxchg qword ptr [rip + 0xe94c], rcx
000120ec  75 ee  jne 0x120dc
000120f7  eb f7  jmp 0x120f0
000120fc  48 83 ec 28  sub rsp, 0x28
00012100  e8 5f 0b 00 00  call 0x12c64
00012107  74 07  je 0x12110
00012109  e8 82 08 00 00  call 0x12990
0001210e  eb 19  jmp 0x12129
00012110  e8 47 0b 00 00  call 0x12c5c
00012117  e8 96 26 00 00  call 0x147b2
0001211e  74 04  je 0x12124
00012122  eb 07  jmp 0x1212b
00012124  e8 8f 26 00 00  call 0x147b8
00012130  48 83 ec 28  sub rsp, 0x28
00012136  e8 2d 01 00 00  call 0x12268
00012148  48 83 ec 28  sub rsp, 0x28
0001214c  e8 bf 2a 00 00  call 0x14c10
00012153  75 04  jne 0x12159
00012157  eb 12  jmp 0x1216b
00012159  e8 b2 2a 00 00  call 0x14c10
00012160  75 07  jne 0x12169
00012162  e8 ad 2a 00 00  call 0x14c14
00012167  eb ec  jmp 0x12155
00012170  48 83 ec 28  sub rsp, 0x28
00012174  e8 9b 2a 00 00  call 0x14c14
00012179  e8 96 2a 00 00  call 0x14c14
00012188  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
000121a7  e8 b8 0a 00 00  call 0x12c64
000121ae  75 16  jne 0x121c6
000121b3  75 11  jne 0x121c6
000121c0  ff 15 3a 3b 00 00  call qword ptr [rip + 0x3b3a]
000121e3  e9 c4 25 00 00  jmp 0x147ac
000121e8  48 83 ec 28  sub rsp, 0x28
000121ec  e8 73 0a 00 00  call 0x12c64
000121f3  74 10  je 0x12205
000121f5  48 8d 0d 4c e8 00 00  lea rcx, [rip + 0xe84c]
00012200  e9 c5 25 00 00  jmp 0x147ca
00012205  e8 16 2a 00 00  call 0x14c20
0001220c  75 05  jne 0x12213
0001220e  e8 c9 25 00 00  call 0x147dc
00012218  48 83 ec 28  sub rsp, 0x28
0001221e  e8 f9 29 00 00  call 0x14c1c
00012227  e9 f0 29 00 00  jmp 0x14c1c
0001222c  48 83 ec 28  sub rsp, 0x28
00012232  75 07  jne 0x1223b
00012234  c6 05 05 e8 00 00 01  mov byte ptr [rip + 0xe805], 1
0001223b  e8 50 07 00 00  call 0x12990
00012240  e8 c7 29 00 00  call 0x14c0c
00012247  75 04  jne 0x1224d
0001224b  eb 14  jmp 0x12261
0001224d  e8 ba 29 00 00  call 0x14c0c
00012254  75 09  jne 0x1225f
00012258  e8 bb 29 00 00  call 0x14c18
0001225d  eb ea  jmp 0x12249
00012268  40 53  push rbx
0001226e  80 3d cc e7 00 00 00  cmp byte ptr [rip + 0xe7cc], 0
00012277  75 67  jne 0x122e0
0001227c  77 6a  ja 0x122e8
0001227e  e8 e1 09 00 00  call 0x12c64
00012285  74 28  je 0x122af
00012289  75 24  jne 0x122af
0001228b  48 8d 0d b6 e7 00 00  lea rcx, [rip + 0xe7b6]
00012292  e8 27 25 00 00  call 0x147be
00012299  75 10  jne 0x122ab
0001229b  48 8d 0d be e7 00 00  lea rcx, [rip + 0xe7be]
000122a2  e8 17 25 00 00  call 0x147be
000122a9  74 2e  je 0x122d9
000122ad  eb 33  jmp 0x122e2
000122af  66 0f 6f 05 a9 59 00 00  movdqa xmm0, xmmword ptr [rip + 0x59a9]
000122bb  f3 0f 7f 05 85 e7 00 00  movdqu xmmword ptr [rip + 0xe785], xmm0
000122c3  48 89 05 8e e7 00 00  mov qword ptr [rip + 0xe78e], rax
000122ca  f3 0f 7f 05 8e e7 00 00  movdqu xmmword ptr [rip + 0xe78e], xmm0
000122d2  48 89 05 97 e7 00 00  mov qword ptr [rip + 0xe797], rax
000122d9  c6 05 61 e7 00 00 01  mov byte ptr [rip + 0xe761], 1
000122ed  e8 6e 01 00 00  call 0x12460
000122f4  48 83 ec 18  sub rsp, 0x18
00012300  66 39 05 f9 dc fe ff  cmp word ptr [rip - 0x12307], ax
00012307  75 78  jne 0x12381
00012309  48 63 0d 2c dd fe ff  movsxd rcx, dword ptr [rip - 0x122d4]
00012310  48 8d 15 e9 dc fe ff  lea rdx, [rip - 0x12317]
00012320  75 5f  jne 0x12381
0001232b  75 54  jne 0x12381
0001234e  74 18  je 0x12368
00012356  72 0a  jb 0x12362
00012360  72 08  jb 0x1236a
00012366  eb df  jmp 0x12347
0001236d  75 04  jne 0x12373
00012371  eb 14  jmp 0x12387
00012377  7d 04  jge 0x1237d
0001237b  eb 0a  jmp 0x12387
0001237f  eb 06  jmp 0x12387
00012383  eb 02  jmp 0x12387
0001238c  40 53  push rbx
00012394  e8 cb 08 00 00  call 0x12c64
0001239d  74 0b  je 0x123aa
000123a1  75 07  jne 0x123aa
000123a3  48 87 15 8e e6 00 00  xchg qword ptr [rip + 0xe68e], rdx
000123b0  40 53  push rbx
000123b6  80 3d 83 e6 00 00 00  cmp byte ptr [rip + 0xe683], 0
000123bf  74 04  je 0x123c5
000123c3  75 0c  jne 0x123d1
000123c5  e8 4e 28 00 00  call 0x14c18
000123cc  e8 47 28 00 00  call 0x14c18
000123dc  40 53  push rbx
000123e2  48 83 3d 5e e6 00 00 ff  cmp qword ptr [rip + 0xe65e], -1
000123ed  75 07  jne 0x123f6
000123ef  e8 dc 23 00 00  call 0x147d0
000123f4  eb 0f  jmp 0x12405
000123f9  48 8d 0d 48 e6 00 00  lea rcx, [rip + 0xe648]
00012400  e8 bf 23 00 00  call 0x147c4
00012418  48 83 3d 40 e6 00 00 ff  cmp qword ptr [rip + 0xe640], -1
00012420  0f 84 b0 23 00 00  je 0x147d6 ; if taken: 0x147d6 ff256c090000 jmp qword ptr [rip + 0x96c]
00012429  48 8d 0d 30 e6 00 00  lea rcx, [rip + 0xe630]
00012430  e9 8f 23 00 00  jmp 0x147c4
00012438  48 83 ec 28  sub rsp, 0x28
0001243c  e8 9b ff ff ff  call 0x123dc
00012450  48 8d 05 f1 fc 00 00  lea rax, [rip + 0xfcf1]
00012458  83 25 19 e6 00 00 00  and dword ptr [rip + 0xe619], 0
00012460  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
0001247c  ff 15 0e 2c 00 00  call qword ptr [rip + 0x2c0e]
00012484  74 04  je 0x1248a
0001248f  e8 c4 ff ff ff  call 0x12458
000124a0  e8 ef 22 00 00  call 0x14794
000124a9  ff 15 a9 2b 00 00  call qword ptr [rip + 0x2ba9]
000124c3  ff 15 97 2b 00 00  call qword ptr [rip + 0x2b97]
000124cc  74 3c  je 0x1250a
00012504  ff 15 5e 2b 00 00  call qword ptr [rip + 0x2b5e]
00012537  e8 58 22 00 00  call 0x14794
00012558  ff 15 12 2b 00 00  call qword ptr [rip + 0x2b12]
00012575  ff 15 05 2b 00 00  call qword ptr [rip + 0x2b05]
00012580  ff 15 f2 2a 00 00  call qword ptr [rip + 0x2af2]
00012588  75 0d  jne 0x12597
0001258d  74 08  je 0x12597
00012592  e8 c1 fe ff ff  call 0x12458
000125a8  48 81 ec 98 00 00 00  sub rsp, 0x98
000125ba  e8 d5 21 00 00  call 0x14794
000125c4  ff 15 be 2a 00 00  call qword ptr [rip + 0x2abe]
000125e4  e9 6b 00 00 00  jmp 0x12654
000125ec  33 c0  xor eax, eax
000125f0  48 83 ec 28  sub rsp, 0x28
000125f6  ff 15 9c 2a 00 00  call qword ptr [rip + 0x2a9c]
000125ff  74 39  je 0x1263a
00012609  75 2f  jne 0x1263a
00012618  75 20  jne 0x1263a
00012623  75 15  jne 0x1263a
0001262c  76 0c  jbe 0x1263a
00012638  eb 02  jmp 0x1263c
00012644  48 8d 0d 0d 00 00 00  lea rcx, [rip + 0xd]
0001264b  48 ff 25 2e 2a 00 00  jmp qword ptr [rip + 0x2a2e]
00012654  33 c0  xor eax, eax
00012658  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
0001266e  75 1c  jne 0x1268c
00012674  75 16  jne 0x1268c
00012682  76 15  jbe 0x12699
0001268a  74 0d  je 0x12699
00012699  e8 ea 20 00 00  call 0x14788
000126a5  e8 e4 20 00 00  call 0x1478e
000126ad  e8 30 21 00 00  call 0x147e2
000126b4  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
000126be  48 8d 1d 3b 79 00 00  lea rbx, [rip + 0x793b]
000126c5  48 8d 3d 34 79 00 00  lea rdi, [rip + 0x7934]
000126cc  eb 12  jmp 0x126e0
000126d4  74 06  je 0x126dc
000126d6  ff 15 24 36 00 00  call qword ptr [rip + 0x3624]
000126e3  72 e9  jb 0x126ce
000126f0  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
000126fa  48 8d 1d 0f 79 00 00  lea rbx, [rip + 0x790f]
00012701  48 8d 3d 08 79 00 00  lea rdi, [rip + 0x7908]
00012708  eb 12  jmp 0x1271c
00012710  74 06  je 0x12718
00012712  ff 15 e8 35 00 00  call qword ptr [rip + 0x35e8]
0001271f  72 e9  jb 0x1270a
0001272c  c2 00 00  ret 0
00012730  48 8b 01  mov rax, qword ptr [rcx]
00012734  48 8b 01  mov rax, qword ptr [rcx]
00012738  48 8d 15 41 74 00 00  lea rdx, [rip + 0x7441]
0001273f  48 8d 05 3a 74 00 00  lea rax, [rip + 0x743a]
0001274f  77 01  ja 0x12752
00012754  48 8d 15 25 74 00 00  lea rdx, [rip + 0x7425]
0001275b  48 8d 05 1e 74 00 00  lea rax, [rip + 0x741e]
0001276b  77 07  ja 0x12774
00012778  c2 00 00  ret 0
0001277c  48 83 ec 28  sub rsp, 0x28
00012780  4c 8d 05 f9 73 00 00  lea r8, [rip + 0x73f9]
0001278a  48 8d 15 ef 73 00 00  lea rdx, [rip + 0x73ef]
0001279a  77 0e  ja 0x127aa
0001279c  48 8b 05 75 35 00 00  mov rax, qword ptr [rip + 0x3575]
000127a6  74 02  je 0x127aa
000127a8  ff d0  call rax
000127b0  48 83 ec 28  sub rsp, 0x28
000127b4  48 8b 05 5d 35 00 00  mov rax, qword ptr [rip + 0x355d]
000127be  74 02  je 0x127c2
000127c0  ff d0  call rax
000127c8  48 83 ec 28  sub rsp, 0x28
000127cc  4c 8d 05 ad 73 00 00  lea r8, [rip + 0x73ad]
000127d6  48 8d 15 a3 73 00 00  lea rdx, [rip + 0x73a3]
000127e6  77 12  ja 0x127fa
000127e8  48 8b 05 91 e2 00 00  mov rax, qword ptr [rip + 0xe291]
000127f2  74 06  je 0x127fa
000127f4  ff 15 06 35 00 00  call qword ptr [rip + 0x3506]
00012800  48 83 ec 28  sub rsp, 0x28
00012804  48 8b 05 75 e2 00 00  mov rax, qword ptr [rip + 0xe275]
0001280e  74 06  je 0x12816
00012810  ff 15 ea 34 00 00  call qword ptr [rip + 0x34ea]
0001281c  48 8d 05 5d 73 00 00  lea rax, [rip + 0x735d]
00012826  48 8d 15 53 73 00 00  lea rdx, [rip + 0x7353]
0001283c  48 87 0d 3d e2 00 00  xchg qword ptr [rip + 0xe23d], rcx
00012848  48 8b c1  mov rax, rcx
0001284e  48 8d 15 ab 72 00 00  lea rdx, [rip + 0x72ab]
0001285f  76 1a  jbe 0x1287b
00012861  48 8d 15 18 73 00 00  lea rdx, [rip + 0x7318]
00012868  48 8d 05 11 73 00 00  lea rax, [rip + 0x7311]
00012878  77 01  ja 0x1287b
0001287c  48 8b c1  mov rax, rcx
00012882  48 8d 15 77 72 00 00  lea rdx, [rip + 0x7277]
00012893  76 20  jbe 0x128b5
00012895  48 8d 15 e4 72 00 00  lea rdx, [rip + 0x72e4]
0001289c  48 8d 05 dd 72 00 00  lea rax, [rip + 0x72dd]
000128ac  77 07  ja 0x128b5
000128b8  c2 00 00  ret 0
000128bc  48 83 ec 28  sub rsp, 0x28
000128c6  48 8d 15 33 72 00 00  lea rdx, [rip + 0x7233]
000128d7  76 2a  jbe 0x12903
000128d9  4c 8d 05 a0 72 00 00  lea r8, [rip + 0x72a0]
000128e3  48 8d 05 96 72 00 00  lea rax, [rip + 0x7296]
000128f3  77 0e  ja 0x12903
000128f5  48 8b 05 1c 34 00 00  mov rax, qword ptr [rip + 0x341c]
000128ff  74 02  je 0x12903
00012901  ff d0  call rax
00012908  48 83 ec 28  sub rsp, 0x28
00012912  48 8d 15 e7 71 00 00  lea rdx, [rip + 0x71e7]
00012923  76 2e  jbe 0x12953
00012925  4c 8d 05 54 72 00 00  lea r8, [rip + 0x7254]
0001292f  48 8d 05 4a 72 00 00  lea rax, [rip + 0x724a]
0001293f  77 12  ja 0x12953
00012941  48 8b 05 38 e1 00 00  mov rax, qword ptr [rip + 0xe138]
0001294b  74 06  je 0x12953
0001294d  ff 15 ad 33 00 00  call qword ptr [rip + 0x33ad]
00012958  48 2b ca  sub rcx, rdx
0001295b  48 8d 05 9e 71 00 00  lea rax, [rip + 0x719e]
00012974  48 8b 0d 75 33 00 00  mov rcx, qword ptr [rip + 0x3375]
0001297b  48 8d 15 aa fd ff ff  lea rdx, [rip - 0x256]
0001298c  33 c0  xor eax, eax
00012990  48 89 5c 24 10  mov qword ptr [rsp + 0x10], rbx
000129e9  75 5b  jne 0x12a46
000129eb  48 83 0d 6d be 00 00 ff  or qword ptr [rip + 0xbe6d], 0xffffffffffffffff
000129f8  48 c7 05 55 be 00 00 00 80 00 00  mov qword ptr [rip + 0xbe55], 0x8000
00012a08  74 28  je 0x12a32
00012a0f  74 21  je 0x12a32
00012a16  74 1a  je 0x12a32
00012a20  77 24  ja 0x12a46
00012a30  73 14  jae 0x12a46
00012a32  44 8b 05 53 e0 00 00  mov r8d, dword ptr [rip + 0xe053]
00012a3d  44 89 05 48 e0 00 00  mov dword ptr [rip + 0xe048], r8d
00012a44  eb 07  jmp 0x12a4d
00012a46  44 8b 05 3f e0 00 00  mov r8d, dword ptr [rip + 0xe03f]
00012a5d  7c 65  jl 0x12ac4
00012a7c  73 0b  jae 0x12a89
00012a82  44 89 05 03 e0 00 00  mov dword ptr [rip + 0xe003], r8d
00012a8c  7c 19  jl 0x12aa7
00012aaf  7c 13  jl 0x12ac4
00012ac4  48 8b 05 7d bd 00 00  mov rax, qword ptr [rip + 0xbd7d]
00012ad4  c7 05 72 bd 00 00 01 00 00 00  mov dword ptr [rip + 0xbd72], 1
00012ade  c7 05 6c bd 00 00 02 00 00 00  mov dword ptr [rip + 0xbd6c], 2
00012ae8  48 89 05 59 bd 00 00  mov qword ptr [rip + 0xbd59], rax
00012af3  73 1b  jae 0x12b10
00012af9  c7 05 4d bd 00 00 02 00 00 00  mov dword ptr [rip + 0xbd4d], 2
00012b03  48 89 05 3e bd 00 00  mov qword ptr [rip + 0xbd3e], rax
00012b0a  89 1d 44 bd 00 00  mov dword ptr [rip + 0xbd44], ebx
00012b14  0f 83 2b 01 00 00  jae 0x12c45
00012b2e  0f 83 f6 00 00 00  jae 0x12c2a
00012b3c  0f 85 e8 00 00 00  jne 0x12c2a
00012b42  8b 05 0c bd 00 00  mov eax, dword ptr [rip + 0xbd0c]
00012b4d  c7 05 f9 bc 00 00 03 00 00 00  mov dword ptr [rip + 0xbcf9], 3
00012b57  89 05 f7 bc 00 00  mov dword ptr [rip + 0xbcf7], eax
00012b61  74 5d  je 0x12bc0
00012b66  c7 05 e0 bc 00 00 05 00 00 00  mov dword ptr [rip + 0xbce0], 5
00012b70  89 05 de bc 00 00  mov dword ptr [rip + 0xbcde], eax
00012b7b  48 8b 05 c6 bc 00 00  mov rax, qword ptr [rip + 0xbcc6]
00012b89  48 89 05 b8 bc 00 00  mov qword ptr [rip + 0xbcb8], rax
00012b93  75 32  jne 0x12bc7
00012b9d  75 21  jne 0x12bc0
00012b9f  48 8b 05 a2 bc 00 00  mov rax, qword ptr [rip + 0xbca2]
00012ba6  83 0d a7 bc 00 00 40  or dword ptr [rip + 0xbca7], 0x40
00012bb1  89 1d 99 bc 00 00  mov dword ptr [rip + 0xbc99], ebx
00012bb7  48 89 05 8a bc 00 00  mov qword ptr [rip + 0xbc8a], rax
00012bbe  eb 07  jmp 0x12bc7
00012bc0  48 8b 05 81 bc 00 00  mov rax, qword ptr [rip + 0xbc81]
00012bcb  73 0c  jae 0x12bd9
00012bd2  48 89 05 6f bc 00 00  mov qword ptr [rip + 0xbc6f], rax
00012bde  73 4a  jae 0x12c2a
00012be8  75 40  jne 0x12c2a
00012bfc  89 05 86 de 00 00  mov dword ptr [rip + 0xde86], eax
00012c0c  48 23 0d 35 bc 00 00  and rcx, qword ptr [rip + 0xbc35]
00012c13  48 89 0d 2e bc 00 00  mov qword ptr [rip + 0xbc2e], rcx
00012c1d  76 0b  jbe 0x12c2a
00012c23  48 89 0d 1e bc 00 00  mov qword ptr [rip + 0xbc1e], rcx
00012c2f  73 14  jae 0x12c45
00012c3a  73 09  jae 0x12c45
00012c3c  48 0f ba 35 03 bc 00 00 07  btr qword ptr [rip + 0xbc03], 7
00012c5c  b8 01 00 00 00  mov eax, 1
00012c64  33 c0  xor eax, eax
00012c66  39 05 44 bc 00 00  cmp dword ptr [rip + 0xbc44], eax
00012c70  49 83 f8 01  cmp r8, 1
00012c77  75 07  jne 0x12c80
00012c80  4c 8d 1d b9 13 01 00  lea r11, [rip + 0x113b9]
00012c8b  7f 13  jg 0x12ca0
00012c93  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
00012ca7  75 1e  jne 0x12cc7
00012ca9  4c 8d 1d 90 13 01 00  lea r11, [rip + 0x11390]
00012cb7  0f 8f 83 08 00 00  jg 0x13540
00012cc3  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
00012cc7  4c 8d 1d 32 13 01 00  lea r11, [rip + 0x11332]
00012cd5  43 ff 24 cb  jmp qword ptr [r11 + r9*8]
00012cfd  eb aa  jmp 0x12ca9
00012d1b  eb 8c  jmp 0x12ca9
00012d37  e9 6d ff ff ff  jmp 0x12ca9
00012d4e  e9 56 ff ff ff  jmp 0x12ca9
00012d6f  e9 35 ff ff ff  jmp 0x12ca9
00012d88  e9 1c ff ff ff  jmp 0x12ca9
00012d9c  e9 08 ff ff ff  jmp 0x12ca9
00012da9  74 12  je 0x12dbd
00012dc4  74 14  je 0x12dda
00012de1  0f 84 c2 fe ff ff  je 0x12ca9
00012df9  e9 ab fe ff ff  jmp 0x12ca9
00013540  83 3d 69 de 00 00 02  cmp dword ptr [rip + 0xde69], 2
00013547  0f 85 33 06 00 00  jne 0x13b80
00013554  0f 85 6e 07 00 00  jne 0x13cc8
0001355d  4c 3b 05 14 b3 00 00  cmp r8, qword ptr [rip + 0xb314]
00013564  0f 8f 26 05 00 00  jg 0x13a90
00013571  0f 84 89 05 00 00  je 0x13b00
00013577  4c 8d 15 82 10 01 00  lea r10, [rip + 0x11082]
000135a0  43 ff 24 da  jmp qword ptr [r10 + r11*8]
000135a4  4c 8d 15 d5 10 01 00  lea r10, [rip + 0x110d5]
000135c3  43 ff 24 ca  jmp qword ptr [r10 + r9*8]
00013617  7d b7  jge 0x135d0
00013619  e9 5b 04 00 00  jmp 0x13a79
00013667  7d b7  jge 0x13620
00013669  e9 0b 04 00 00  jmp 0x13a79
000136b7  7d b7  jge 0x13670
000136b9  e9 bb 03 00 00  jmp 0x13a79
00013707  7d b7  jge 0x136c0
00013709  e9 6b 03 00 00  jmp 0x13a79
00013757  7d b7  jge 0x13710
00013759  e9 1b 03 00 00  jmp 0x13a79
000137a7  7d b7  jge 0x13760
000137a9  e9 cb 02 00 00  jmp 0x13a79
000137f7  7d b7  jge 0x137b0
000137f9  e9 7b 02 00 00  jmp 0x13a79
00013847  7d b7  jge 0x13800
00013849  e9 2b 02 00 00  jmp 0x13a79
00013897  7d b7  jge 0x13850
00013899  e9 db 01 00 00  jmp 0x13a79
000138e7  7d b7  jge 0x138a0
000138e9  e9 8b 01 00 00  jmp 0x13a79
00013937  7d b7  jge 0x138f0
00013939  e9 3b 01 00 00  jmp 0x13a79
00013987  7d b7  jge 0x13940
00013989  e9 eb 00 00 00  jmp 0x13a79
000139d7  7d b7  jge 0x13990
000139d9  e9 9b 00 00 00  jmp 0x13a79
00013a27  7d b7  jge 0x139e0
00013a29  eb 4e  jmp 0x13a79
00013a77  7d b7  jge 0x13a30
00013a79  4c 8d 15 c0 05 01 00  lea r10, [rip + 0x105c0]
00013a89  43 ff 24 c2  jmp qword ptr [r10 + r8*8]
00013acf  7d bf  jge 0x13a90
00013ad1  4c 8d 15 a8 0b 01 00  lea r10, [rip + 0x10ba8]
00013af3  43 ff 24 ca  jmp qword ptr [r10 + r9*8]
00013b67  7d 97  jge 0x13b00
00013b69  4c 8d 15 d0 04 01 00  lea r10, [rip + 0x104d0]
00013b76  43 ff 24 c2  jmp qword ptr [r10 + r8*8]
00013b80  4c 3b 05 f1 ac 00 00  cmp r8, qword ptr [rip + 0xacf1]
00013b87  7f 77  jg 0x13c00
00013b89  eb 05  jmp 0x13b90
00013bde  7f b0  jg 0x13b90
00013be0  4c 8d 15 59 04 01 00  lea r10, [rip + 0x10459]
00013bef  43 ff 24 c2  jmp qword ptr [r10 + r8*8]
00013c5d  7d a1  jge 0x13c00
00013c62  e9 79 ff ff ff  jmp 0x13be0
00013cb7  4c 8d 15 82 03 01 00  lea r10, [rip + 0x10382]
00013cc4  43 ff 24 c2  jmp qword ptr [r10 + r8*8]
00013cda  e9 7b f8 ff ff  jmp 0x1355a
00013d15  e9 40 f8 ff ff  jmp 0x1355a
00013d20  49 83 f8 01  cmp r8, 1
00013d27  75 03  jne 0x13d2c
00013d36  7c 2f  jl 0x13d67
00013d4a  75 24  jne 0x13d70
00013d4c  4c 8d 1d dd 09 01 00  lea r11, [rip + 0x109dd]
00013d5a  0f 8d a7 02 00 00  jge 0x14007
00013d63  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
00013d74  7e d6  jle 0x13d4c
00013d76  4c 8d 1d 73 09 01 00  lea r11, [rip + 0x10973]
00013d91  43 ff 24 cb  jmp qword ptr [r11 + r9*8]
00013da3  eb a7  jmp 0x13d4c
00013dab  eb 9f  jmp 0x13d4c
00013db4  eb 96  jmp 0x13d4c
00013dc0  eb 8a  jmp 0x13d4c
00014007  83 3d a2 d3 00 00 02  cmp dword ptr [rip + 0xd3a2], 2
0001400e  0f 8c 4c 06 00 00  jl 0x14660
0001401d  4c 8d 1d 4c 0b 01 00  lea r11, [rip + 0x10b4c]
0001403f  43 ff 24 d3  jmp qword ptr [r11 + r10*8]
00014043  eb 56  jmp 0x1409b
00014049  eb 50  jmp 0x1409b
00014052  eb 47  jmp 0x1409b
0001405c  eb 3d  jmp 0x1409b
00014069  eb 30  jmp 0x1409b
00014072  eb 27  jmp 0x1409b
0001407e  eb 1b  jmp 0x1409b
0001408b  eb 0e  jmp 0x1409b
0001409b  4c 8d 1d 5e 0b 01 00  lea r11, [rip + 0x10b5e]
000140a9  0f 8d f4 04 00 00  jge 0x145a3
000140b2  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
000140c7  74 d2  je 0x1409b
000140da  74 bf  je 0x1409b
000140e6  eb b3  jmp 0x1409b
000145a3  4c 3b 05 c6 a2 00 00  cmp r8, qword ptr [rip + 0xa2c6]
000145aa  7f 4d  jg 0x145f9
000145ac  eb 02  jmp 0x145b0
000145e9  7d c5  jge 0x145b0
000145eb  4c 8d 1d 0e 06 01 00  lea r11, [rip + 0x1060e]
000145f5  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
000145fd  74 b1  je 0x145b0
000145ff  eb 0f  jmp 0x14610
0001464c  7d c2  jge 0x14610
00014651  4c 8d 1d a8 05 01 00  lea r11, [rip + 0x105a8]
0001465b  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
00014660  4c 3b 05 09 a2 00 00  cmp r8, qword ptr [rip + 0xa209]
00014667  7f 47  jg 0x146b0
00014669  eb 05  jmp 0x14670
0001469b  7f d3  jg 0x14670
0001469d  4c 8d 1d 8c 00 01 00  lea r11, [rip + 0x1008c]
000146a8  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
000146b4  74 ba  je 0x14670
000146b6  eb 08  jmp 0x146c0
000146f3  7d cb  jge 0x146c0
000146f5  4c 8d 1d 34 00 01 00  lea r11, [rip + 0x10034]
00014700  43 ff 24 c3  jmp qword ptr [r11 + r8*8]
00014704  ff 25 16 09 00 00  jmp qword ptr [rip + 0x916]
0001470a  ff 25 18 09 00 00  jmp qword ptr [rip + 0x918]
00014710  ff 25 1a 09 00 00  jmp qword ptr [rip + 0x91a]
00014716  ff 25 1c 09 00 00  jmp qword ptr [rip + 0x91c]
0001471c  ff 25 1e 09 00 00  jmp qword ptr [rip + 0x91e]
00014722  ff 25 20 09 00 00  jmp qword ptr [rip + 0x920]
00014728  ff 25 22 09 00 00  jmp qword ptr [rip + 0x922]
0001472e  ff 25 24 09 00 00  jmp qword ptr [rip + 0x924]
00014734  ff 25 26 09 00 00  jmp qword ptr [rip + 0x926]
0001473a  ff 25 28 09 00 00  jmp qword ptr [rip + 0x928]
00014740  ff 25 2a 09 00 00  jmp qword ptr [rip + 0x92a]
00014746  ff 25 2c 09 00 00  jmp qword ptr [rip + 0x92c]
0001474c  ff 25 2e 09 00 00  jmp qword ptr [rip + 0x92e]
00014752  ff 25 30 09 00 00  jmp qword ptr [rip + 0x930]
00014758  ff 25 32 09 00 00  jmp qword ptr [rip + 0x932]
0001475e  ff 25 34 09 00 00  jmp qword ptr [rip + 0x934]
00014764  ff 25 36 09 00 00  jmp qword ptr [rip + 0x936]
0001476a  ff 25 38 09 00 00  jmp qword ptr [rip + 0x938]
00014770  ff 25 9a 08 00 00  jmp qword ptr [rip + 0x89a]
00014776  ff 25 8c 08 00 00  jmp qword ptr [rip + 0x88c]
0001477c  ff 25 3e 09 00 00  jmp qword ptr [rip + 0x93e]
00014782  ff 25 40 09 00 00  jmp qword ptr [rip + 0x940]
00014788  ff 25 52 09 00 00  jmp qword ptr [rip + 0x952]
0001478e  ff 25 44 09 00 00  jmp qword ptr [rip + 0x944]
00014794  ff 25 36 09 00 00  jmp qword ptr [rip + 0x936]
0001479a  ff 25 18 09 00 00  jmp qword ptr [rip + 0x918]
000147a0  ff 25 d2 09 00 00  jmp qword ptr [rip + 0x9d2]
000147a6  ff 25 d4 09 00 00  jmp qword ptr [rip + 0x9d4]
000147ac  ff 25 ae 09 00 00  jmp qword ptr [rip + 0x9ae]
000147b2  ff 25 88 09 00 00  jmp qword ptr [rip + 0x988]
000147b8  ff 25 62 09 00 00  jmp qword ptr [rip + 0x962]
000147be  ff 25 64 09 00 00  jmp qword ptr [rip + 0x964]
000147c4  ff 25 66 09 00 00  jmp qword ptr [rip + 0x966]
000147ca  ff 25 68 09 00 00  jmp qword ptr [rip + 0x968]
000147d0  ff 25 9a 09 00 00  jmp qword ptr [rip + 0x99a]
000147d6  ff 25 6c 09 00 00  jmp qword ptr [rip + 0x96c]
000147dc  ff 25 6e 09 00 00  jmp qword ptr [rip + 0x96e]
000147e2  ff 25 70 09 00 00  jmp qword ptr [rip + 0x970]
000147e8  ff 25 22 09 00 00  jmp qword ptr [rip + 0x922]
000147ee  ff 25 74 09 00 00  jmp qword ptr [rip + 0x974]
000147f4  ff 25 a6 09 00 00  jmp qword ptr [rip + 0x9a6]
000147fa  ff 25 b8 09 00 00  jmp qword ptr [rip + 0x9b8]
00014800  ff 25 aa 09 00 00  jmp qword ptr [rip + 0x9aa]
00014806  ff 25 84 09 00 00  jmp qword ptr [rip + 0x984]
0001480c  ff 25 86 09 00 00  jmp qword ptr [rip + 0x986]
00014830  48 3b 0d c9 9f 00 00  cmp rcx, qword ptr [rip + 0x9fc9]
00014837  75 10  jne 0x14849
00014842  75 01  jne 0x14845
00014849  e9 36 00 00 00  jmp 0x14884
00014850  40 53  push rbx
0001485b  ff 15 1f 08 00 00  call qword ptr [rip + 0x81f]
00014864  ff 15 0e 08 00 00  call qword ptr [rip + 0x80e]
0001486a  ff 15 a8 07 00 00  call qword ptr [rip + 0x7a8]
0001487d  48 ff 25 7c 07 00 00  jmp qword ptr [rip + 0x77c]
00014884  48 89 4c 24 08  mov qword ptr [rsp + 8], rcx
00014892  ff 15 f8 07 00 00  call qword ptr [rip + 0x7f8]
0001489a  74 07  je 0x148a3
000148a3  48 8d 0d e6 d1 00 00  lea rcx, [rip + 0xd1e6]
000148aa  e8 dd 02 00 00  call 0x14b8c
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
0001494c  e8 ff fe ff ff  call 0x14850
00014958  48 83 ec 28  sub rsp, 0x28
00014961  e8 06 00 00 00  call 0x1496c
0001496c  89 4c 24 08  mov dword ptr [rsp + 8], ecx
00014979  ff 15 11 07 00 00  call qword ptr [rip + 0x711]
00014981  74 08  je 0x1498b
0001498b  48 8d 0d fe d0 00 00  lea rcx, [rip + 0xd0fe]
00014992  e8 85 01 00 00  call 0x14b1c
0001499c  48 89 05 e5 d1 00 00  mov qword ptr [rip + 0xd1e5], rax
000149ac  48 89 05 75 d1 00 00  mov qword ptr [rip + 0xd175], rax
000149b3  48 8b 05 ce d1 00 00  mov rax, qword ptr [rip + 0xd1ce]
000149ba  48 89 05 3f d0 00 00  mov qword ptr [rip + 0xd03f], rax
000149c1  c7 05 25 d0 00 00 09 04 00 c0  mov dword ptr [rip + 0xd025], 0xc0000409
000149cb  c7 05 1f d0 00 00 01 00 00 00  mov dword ptr [rip + 0xd01f], 1
000149d5  c7 05 29 d0 00 00 01 00 00 00  mov dword ptr [rip + 0xd029], 1
000149e8  48 8d 0d 21 d0 00 00  lea rcx, [rip + 0xd021]
000149f7  48 8d 0d 3a 4f 00 00  lea rcx, [rip + 0x4f3a]
000149fe  e8 4d fe ff ff  call 0x14850
00014a0c  4c 89 44 24 18  mov qword ptr [rsp + 0x18], r8
00014a22  ff 15 68 06 00 00  call qword ptr [rip + 0x668]
00014a2a  74 08  je 0x14a34
00014a34  48 8d 0d 55 d0 00 00  lea rcx, [rip + 0xd055]
00014a3b  e8 dc 00 00 00  call 0x14b1c
00014a45  48 89 05 3c d1 00 00  mov qword ptr [rip + 0xd13c], rax
00014a55  48 89 05 cc d0 00 00  mov qword ptr [rip + 0xd0cc], rax
00014a5c  48 8b 05 25 d1 00 00  mov rax, qword ptr [rip + 0xd125]
00014a63  48 89 05 96 cf 00 00  mov qword ptr [rip + 0xcf96], rax
00014a6a  c7 05 7c cf 00 00 09 04 00 c0  mov dword ptr [rip + 0xcf7c], 0xc0000409
00014a74  c7 05 76 cf 00 00 01 00 00 00  mov dword ptr [rip + 0xcf76], 1
00014a83  76 10  jbe 0x14a95
00014a8b  75 08  jne 0x14a95
00014a9a  76 0a  jbe 0x14aa6
00014aac  89 05 56 cf 00 00  mov dword ptr [rip + 0xcf56], eax
00014abb  48 8d 0d 4e cf 00 00  lea rcx, [rip + 0xcf4e]
00014ad2  eb 0a  jmp 0x14ade
00014ae6  73 22  jae 0x14b0a
00014af4  48 8d 15 15 cf 00 00  lea rdx, [rip + 0xcf15]
00014b08  eb ca  jmp 0x14ad4
00014b0a  48 8d 0d 27 4e 00 00  lea rcx, [rip + 0x4e27]
00014b11  e8 3a fd ff ff  call 0x14850
00014b1c  48 89 5c 24 20  mov qword ptr [rsp + 0x20], rbx
00014b29  ff 15 29 05 00 00  call qword ptr [rip + 0x529]
00014b41  ff 15 19 05 00 00  call qword ptr [rip + 0x519]
00014b4a  74 32  je 0x14b7e
00014b78  ff 15 ea 04 00 00  call qword ptr [rip + 0x4ea]
00014b8c  40 53  push rbx
00014b97  ff 15 bb 04 00 00  call qword ptr [rip + 0x4bb]
00014bb1  ff 15 a9 04 00 00  call qword ptr [rip + 0x4a9]
00014bba  74 39  je 0x14bf5
00014be8  ff 15 7a 04 00 00  call qword ptr [rip + 0x47a]
00014bf3  7c b1  jl 0x14ba6
00014bfd  ff 25 15 04 00 00  jmp qword ptr [rip + 0x415]
00014c03  ff 25 f7 03 00 00  jmp qword ptr [rip + 0x3f7]
00014c0c  b0 01  mov al, 1
00014c10  b0 01  mov al, 1
00014c14  b0 01  mov al, 1
00014c18  b0 01  mov al, 1
00014c1c  b0 01  mov al, 1
00014c20  33 c0  xor eax, eax
00014c40  ff e0  jmp rax
00014c60  ff 25 9a 10 00 00  jmp qword ptr [rip + 0x109a]
00014c70  56  push rsi
00014c84  4c 8b 05 75 9b 00 00  mov r8, qword ptr [rip + 0x9b75]
00014caa  e8 91 00 00 00  call 0x14d40
00014cb9  e8 72 fb ff ff  call 0x14830
00014cd0  56  push rsi
00014cea  48 8b 05 0f 9b 00 00  mov rax, qword ptr [rip + 0x9b0f]
00014d03  e8 fe fa ff ff  call 0x14806
00014d0b  e8 e0 d2 ff ff  call 0x11ff0
00014d21  e8 e6 fa ff ff  call 0x1480c
00014d30  e8 fb fa ff ff  call 0x14830
00014d40  41 57  push r15
00014d5f  e8 8c d2 ff ff  call 0x11ff0
00014d7e  e8 71 fa ff ff  call 0x147f4
00014d99  40 55  push rbp
00014daa  e9 dd d5 ff ff  jmp 0x1238c
00014db0  40 55  push rbp
00014dbc  e8 cb d5 ff ff  call 0x1238c
00014dc9  40 55  push rbp
00014dd7  e9 3c d4 ff ff  jmp 0x12218
00014ddd  40 55  push rbp
00014df4  4c 8d 0d 29 cd ff ff  lea r9, [rip - 0x32d7]
00014e06  e8 7d d3 ff ff  call 0x12188
00014e13  40 55  push rbp
