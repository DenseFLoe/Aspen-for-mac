; RVA 0x1520
00001520  8b 05 76 12 05 00  mov eax, dword ptr [rip + 0x51276]
00001526  c3  ret 
; RVA 0x1530
00001530  8b 05 be 1f 05 00  mov eax, dword ptr [rip + 0x51fbe]
00001536  c3  ret 
; RVA 0x1540
00001540  8b 05 52 12 05 00  mov eax, dword ptr [rip + 0x51252]
00001546  c3  ret 
; RVA 0x1cd0
00001cd0  48 8d 05 01 18 05 00  lea rax, [rip + 0x51801]
00001cd7  c3  ret 
; RVA 0x1d40
00001d40  33 c0  xor eax, eax
00001d42  c3  ret 
; RVA 0x1f80
00001f80  b8 01 00 00 00  mov eax, 1
00001f85  c3  ret 
; RVA 0x235c0
000235c0  48 8b c4  mov rax, rsp
000235c3  48 89 58 10  mov qword ptr [rax + 0x10], rbx
000235c7  48 89 70 18  mov qword ptr [rax + 0x18], rsi
000235cb  48 89 78 20  mov qword ptr [rax + 0x20], rdi
000235cf  55  push rbp
000235d0  41 54  push r12
000235d2  41 55  push r13
000235d4  41 56  push r14
000235d6  41 57  push r15
000235d8  48 8d a8 e8 fc ff ff  lea rbp, [rax - 0x318]
000235df  48 81 ec f0 03 00 00  sub rsp, 0x3f0
000235e6  0f 29 70 c8  movaps xmmword ptr [rax - 0x38], xmm6
000235ea  0f 29 78 b8  movaps xmmword ptr [rax - 0x48], xmm7
000235ee  48 8b 05 93 f2 02 00  mov rax, qword ptr [rip + 0x2f293]
000235f5  48 33 c4  xor rax, rsp
000235f8  48 89 85 c0 02 00 00  mov qword ptr [rbp + 0x2c0], rax
000235ff  0f b6 da  movzx ebx, dl
00023602  4c 8b e9  mov r13, rcx
00023605  45 33 e4  xor r12d, r12d
00023608  41 b8 04 01 00 00  mov r8d, 0x104
0002360e  48 8d 95 b0 01 00 00  lea rdx, [rbp + 0x1b0]
00023615  33 c9  xor ecx, ecx
00023617  ff 15 f3 6c 01 00  call qword ptr [rip + 0x16cf3]
0002361d  48 8d 8d b0 01 00 00  lea rcx, [rbp + 0x1b0]
00023624  ff 15 7e 72 01 00  call qword ptr [rip + 0x1727e]
0002362a  48 8d 15 7f ea 01 00  lea rdx, [rip + 0x1ea7f]
00023631  48 8b c8  mov rcx, rax
00023634  e8 a1 2c 01 00  call 0x1800362da
00023639  48 85 c0  test rax, rax
0002363c  74 0a  je 0x180023648
0002363e  41 8d 4c 24 02  lea ecx, [r12 + 2]
00023643  e8 c8 05 01 00  call 0x180033c10
00023648  84 db  test bl, bl
0002364a  74 0a  je 0x180023656
0002364c  b9 02 00 00 00  mov ecx, 2
00023651  e8 ba 05 01 00  call 0x180033c10
00023656  c7 44 24 30 ff 00 00 00  mov dword ptr [rsp + 0x30], 0xff
0002365e  4c 89 64 24 38  mov qword ptr [rsp + 0x38], r12
00023663  e8 98 05 01 00  call 0x180033c00
00023668  0f 57 c0  xorps xmm0, xmm0
0002366b  0f 11 45 e8  movups xmmword ptr [rbp - 0x18], xmm0
0002366f  4c 89 65 f8  mov qword ptr [rbp - 8], r12
00023673  4c 89 65 00  mov qword ptr [rbp], r12
00023677  48 c7 c6 ff ff ff ff  mov rsi, 0xffffffffffffffff
0002367e  4c 8b c6  mov r8, rsi
00023681  49 ff c0  inc r8
00023684  46 38 24 00  cmp byte ptr [rax + r8], r12b
00023688  75 f7  jne 0x180023681
0002368a  48 8b d0  mov rdx, rax
0002368d  48 8d 4d e8  lea rcx, [rbp - 0x18]
00023691  e8 fa 37 fe ff  call 0x180006e90
00023696  90  nop 
00023697  0f 57 c0  xorps xmm0, xmm0
0002369a  0f 11 45 68  movups xmmword ptr [rbp + 0x68], xmm0
0002369e  4c 89 65 78  mov qword ptr [rbp + 0x78], r12
000236a2  48 c7 85 80 00 00 00 0f 00 00 00  mov qword ptr [rbp + 0x80], 0xf
000236ad  ba 20 00 00 00  mov edx, 0x20
000236b2  48 8d 4d 68  lea rcx, [rbp + 0x68]
000236b6  e8 55 9b ff ff  call 0x18001d210
000236bb  48 8b d0  mov rdx, rax
000236be  48 89 45 68  mov qword ptr [rbp + 0x68], rax
000236c2  48 c7 45 78 1d 00 00 00  mov qword ptr [rbp + 0x78], 0x1d
000236ca  48 c7 85 80 00 00 00 1f 00 00 00  mov qword ptr [rbp + 0x80], 0x1f
000236d5  0f 10 05 24 d3 01 00  movups xmm0, xmmword ptr [rip + 0x1d324]
000236dc  0f 11 00  movups xmmword ptr [rax], xmm0
000236df  f2 0f 10 05 29 d3 01 00  movsd xmm0, qword ptr [rip + 0x1d329]
000236e7  f2 0f 11 40 10  movsd qword ptr [rax + 0x10], xmm0
000236ec  8b 0d 26 d3 01 00  mov ecx, dword ptr [rip + 0x1d326]
000236f2  89 48 18  mov dword ptr [rax + 0x18], ecx
000236f5  0f b6 05 20 d3 01 00  movzx eax, byte ptr [rip + 0x1d320]
000236fc  88 42 1c  mov byte ptr [rdx + 0x1c], al
000236ff  c6 42 1d 00  mov byte ptr [rdx + 0x1d], 0
00023703  48 8d 55 e8  lea rdx, [rbp - 0x18]
00023707  48 83 7d 00 10  cmp qword ptr [rbp], 0x10
0002370c  48 0f 43 55 e8  cmovae rdx, qword ptr [rbp - 0x18]
00023711  4c 8b 45 f8  mov r8, qword ptr [rbp - 8]
00023715  48 8d 4d 68  lea rcx, [rbp + 0x68]
00023719  e8 22 17 00 00  call 0x180024e40
0002371e  0f 57 c0  xorps xmm0, xmm0
00023721  0f 11 45 08  movups xmmword ptr [rbp + 8], xmm0
00023725  0f 57 c9  xorps xmm1, xmm1
00023728  f3 0f 7f 4d 18  movdqu xmmword ptr [rbp + 0x18], xmm1
0002372d  0f 10 00  movups xmm0, xmmword ptr [rax]
00023730  0f 11 45 08  movups xmmword ptr [rbp + 8], xmm0
00023734  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
00023738  0f 11 4d 18  movups xmmword ptr [rbp + 0x18], xmm1
0002373c  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00023740  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00023748  c6 00 00  mov byte ptr [rax], 0
0002374b  48 8b 4d 18  mov rcx, qword ptr [rbp + 0x18]
0002374f  48 8b 55 20  mov rdx, qword ptr [rbp + 0x20]
00023753  48 8b c2  mov rax, rdx
00023756  48 2b c1  sub rax, rcx
00023759  48 83 f8 06  cmp rax, 6
0002375d  72 37  jb 0x180023796
0002375f  48 8d 41 06  lea rax, [rcx + 6]
00023763  48 89 45 18  mov qword ptr [rbp + 0x18], rax
00023767  48 8d 5d 08  lea rbx, [rbp + 8]
0002376b  48 83 fa 10  cmp rdx, 0x10
0002376f  48 0f 43 5d 08  cmovae rbx, qword ptr [rbp + 8]
00023774  48 03 d9  add rbx, rcx
00023777  41 b8 06 00 00 00  mov r8d, 6
0002377d  48 8d 15 58 d2 01 00  lea rdx, [rip + 0x1d258]
00023784  48 8b cb  mov rcx, rbx
00023787  e8 48 2b 01 00  call 0x1800362d4
0002378c  c6 43 06 00  mov byte ptr [rbx + 6], 0
00023790  48 8d 45 08  lea rax, [rbp + 8]
00023794  eb 20  jmp 0x1800237b6
00023796  48 c7 44 24 20 06 00 00 00  mov qword ptr [rsp + 0x20], 6
0002379f  4c 8d 0d 36 d2 01 00  lea r9, [rip + 0x1d236]
000237a6  45 33 c0  xor r8d, r8d
000237a9  41 8d 50 06  lea edx, [r8 + 6]
000237ad  48 8d 4d 08  lea rcx, [rbp + 8]
000237b1  e8 8a 46 fe ff  call 0x180007e40
000237b6  0f 57 c0  xorps xmm0, xmm0
000237b9  0f 11 45 88  movups xmmword ptr [rbp - 0x78], xmm0
000237bd  0f 57 c9  xorps xmm1, xmm1
000237c0  f3 0f 7f 4d 98  movdqu xmmword ptr [rbp - 0x68], xmm1
000237c5  0f 10 00  movups xmm0, xmmword ptr [rax]
000237c8  0f 11 45 88  movups xmmword ptr [rbp - 0x78], xmm0
000237cc  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
000237d0  0f 11 4d 98  movups xmmword ptr [rbp - 0x68], xmm1
000237d4  4c 89 60 10  mov qword ptr [rax + 0x10], r12
000237d8  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
000237e0  c6 00 00  mov byte ptr [rax], 0
000237e3  48 8b 55 20  mov rdx, qword ptr [rbp + 0x20]
000237e7  48 83 fa 10  cmp rdx, 0x10
000237eb  72 34  jb 0x180023821
000237ed  48 ff c2  inc rdx
000237f0  48 8b 4d 08  mov rcx, qword ptr [rbp + 8]
000237f4  48 8b c1  mov rax, rcx
000237f7  48 81 fa 00 10 00 00  cmp rdx, 0x1000
000237fe  72 1c  jb 0x18002381c
00023800  48 83 c2 27  add rdx, 0x27
00023804  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023808  48 2b c1  sub rax, rcx
0002380b  48 83 c0 f8  add rax, -8
0002380f  48 83 f8 1f  cmp rax, 0x1f
00023813  76 07  jbe 0x18002381c
00023815  ff 15 9d 6f 01 00  call qword ptr [rip + 0x16f9d]
0002381b  cc  int3 
0002381c  e8 13 19 01 00  call 0x180035134
00023821  66 0f 6f 05 47 e7 01 00  movdqa xmm0, xmmword ptr [rip + 0x1e747]
00023829  f3 0f 7f 45 18  movdqu xmmword ptr [rbp + 0x18], xmm0
0002382e  c6 45 08 00  mov byte ptr [rbp + 8], 0
00023832  48 8b 95 80 00 00 00  mov rdx, qword ptr [rbp + 0x80]
00023839  48 83 fa 10  cmp rdx, 0x10
0002383d  72 34  jb 0x180023873
0002383f  48 ff c2  inc rdx
00023842  48 8b 4d 68  mov rcx, qword ptr [rbp + 0x68]
00023846  48 8b c1  mov rax, rcx
00023849  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023850  72 1c  jb 0x18002386e
00023852  48 83 c2 27  add rdx, 0x27
00023856  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
0002385a  48 2b c1  sub rax, rcx
0002385d  48 83 c0 f8  add rax, -8
00023861  48 83 f8 1f  cmp rax, 0x1f
00023865  76 07  jbe 0x18002386e
00023867  ff 15 4b 6f 01 00  call qword ptr [rip + 0x16f4b]
0002386d  cc  int3 
0002386e  e8 c1 18 01 00  call 0x180035134
00023873  4c 89 65 78  mov qword ptr [rbp + 0x78], r12
00023877  48 c7 85 80 00 00 00 0f 00 00 00  mov qword ptr [rbp + 0x80], 0xf
00023882  c6 45 68 00  mov byte ptr [rbp + 0x68], 0
00023886  48 8d 55 88  lea rdx, [rbp - 0x78]
0002388a  48 83 7d a0 10  cmp qword ptr [rbp - 0x60], 0x10
0002388f  48 0f 43 55 88  cmovae rdx, qword ptr [rbp - 0x78]
00023894  48 8d 44 24 38  lea rax, [rsp + 0x38]
00023899  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0002389e  41 b9 19 00 02 00  mov r9d, 0x20019
000238a4  45 33 c0  xor r8d, r8d
000238a7  48 c7 c1 02 00 00 80  mov rcx, 0xffffffff80000002
000238ae  ff 15 6c 67 01 00  call qword ptr [rip + 0x1676c]
000238b4  85 c0  test eax, eax
000238b6  0f 85 ac 03 00 00  jne 0x180023c68
000238bc  48 8d 44 24 30  lea rax, [rsp + 0x30]
000238c1  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
000238c6  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
000238cd  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000238d2  4c 8d 4c 24 40  lea r9, [rsp + 0x40]
000238d7  45 33 c0  xor r8d, r8d
000238da  48 8d 15 03 d1 01 00  lea rdx, [rip + 0x1d103]
000238e1  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
000238e6  ff 15 3c 67 01 00  call qword ptr [rip + 0x1673c]
000238ec  85 c0  test eax, eax
000238ee  0f 85 69 03 00 00  jne 0x180023c5d
000238f4  0f 57 c0  xorps xmm0, xmm0
000238f7  0f 11 45 28  movups xmmword ptr [rbp + 0x28], xmm0
000238fb  66 0f 6f 0d 6d e6 01 00  movdqa xmm1, xmmword ptr [rip + 0x1e66d]
00023903  f3 0f 7f 4d 38  movdqu xmmword ptr [rbp + 0x38], xmm1
00023908  88 45 28  mov byte ptr [rbp + 0x28], al
0002390b  45 33 c0  xor r8d, r8d
0002390e  33 d2  xor edx, edx
00023910  48 8d 0d a5 e8 01 00  lea rcx, [rip + 0x1e8a5]
00023917  ff 15 fb 69 01 00  call qword ptr [rip + 0x169fb]
0002391d  48 63 f8  movsxd rdi, eax
00023920  48 8d 4f 01  lea rcx, [rdi + 1]
00023924  e8 63 16 01 00  call 0x180034f8c
00023929  4c 8b f0  mov r14, rax
0002392c  c6 04 07 00  mov byte ptr [rdi + rax], 0
00023930  44 8b c7  mov r8d, edi
00023933  48 8b d0  mov rdx, rax
00023936  48 8d 0d 7f e8 01 00  lea rcx, [rip + 0x1e87f]
0002393d  ff 15 d5 69 01 00  call qword ptr [rip + 0x169d5]
00023943  0f 57 c0  xorps xmm0, xmm0
00023946  0f 11 45 a8  movups xmmword ptr [rbp - 0x58], xmm0
0002394a  0f 57 c9  xorps xmm1, xmm1
0002394d  f3 0f 7f 4d b8  movdqu xmmword ptr [rbp - 0x48], xmm1
00023952  4c 8b c6  mov r8, rsi
00023955  49 ff c0  inc r8
00023958  43 80 3c 06 00  cmp byte ptr [r14 + r8], 0
0002395d  75 f6  jne 0x180023955
0002395f  49 8b d6  mov rdx, r14
00023962  48 8d 4d a8  lea rcx, [rbp - 0x58]
00023966  e8 25 35 fe ff  call 0x180006e90
0002396b  90  nop 
0002396c  0f 57 c0  xorps xmm0, xmm0
0002396f  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
00023974  0f 57 c9  xorps xmm1, xmm1
00023977  f3 0f 7f 4c 24 78  movdqu xmmword ptr [rsp + 0x78], xmm1
0002397d  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
00023984  4c 8b c6  mov r8, rsi
00023987  66 0f 1f 84 00 00 00 00 00  nop word ptr [rax + rax]
00023990  49 ff c0  inc r8
00023993  42 80 3c 00 00  cmp byte ptr [rax + r8], 0
00023998  75 f6  jne 0x180023990
0002399a  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
000239a1  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
000239a6  e8 e5 34 fe ff  call 0x180006e90
000239ab  90  nop 
000239ac  41 b8 05 00 00 00  mov r8d, 5
000239b2  48 8d 15 0b e8 01 00  lea rdx, [rip + 0x1e80b]
000239b9  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
000239be  e8 7d 14 00 00  call 0x180024e40
000239c3  0f 10 38  movups xmm7, xmmword ptr [rax]
000239c6  0f 11 7d c8  movups xmmword ptr [rbp - 0x38], xmm7
000239ca  0f 10 70 10  movups xmm6, xmmword ptr [rax + 0x10]
000239ce  0f 11 75 d8  movups xmmword ptr [rbp - 0x28], xmm6
000239d2  4c 89 60 10  mov qword ptr [rax + 0x10], r12
000239d6  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
000239de  c6 00 00  mov byte ptr [rax], 0
000239e1  45 33 c0  xor r8d, r8d
000239e4  48 8d 55 c8  lea rdx, [rbp - 0x38]
000239e8  48 8d 4d a8  lea rcx, [rbp - 0x58]
000239ec  e8 1f 15 00 00  call 0x180024f10
000239f1  48 8b d8  mov rbx, rax
000239f4  66 0f 73 de 08  psrldq xmm6, 8
000239f9  66 48 0f 7e f2  movq rdx, xmm6
000239fe  48 83 fa 10  cmp rdx, 0x10
00023a02  72 36  jb 0x180023a3a
00023a04  48 ff c2  inc rdx
00023a07  66 48 0f 7e f9  movq rcx, xmm7
00023a0c  48 8b c1  mov rax, rcx
00023a0f  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023a16  72 1c  jb 0x180023a34
00023a18  48 83 c2 27  add rdx, 0x27
00023a1c  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023a20  48 2b c1  sub rax, rcx
00023a23  48 83 c0 f8  add rax, -8
00023a27  48 83 f8 1f  cmp rax, 0x1f
00023a2b  76 07  jbe 0x180023a34
00023a2d  ff 15 85 6d 01 00  call qword ptr [rip + 0x16d85]
00023a33  cc  int3 
00023a34  e8 fb 16 01 00  call 0x180035134
00023a39  90  nop 
00023a3a  48 8b 55 80  mov rdx, qword ptr [rbp - 0x80]
00023a3e  48 83 fa 10  cmp rdx, 0x10
00023a42  72 35  jb 0x180023a79
00023a44  48 ff c2  inc rdx
00023a47  48 8b 4c 24 68  mov rcx, qword ptr [rsp + 0x68]
00023a4c  48 8b c1  mov rax, rcx
00023a4f  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023a56  72 1c  jb 0x180023a74
00023a58  48 83 c2 27  add rdx, 0x27
00023a5c  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023a60  48 2b c1  sub rax, rcx
00023a63  48 83 c0 f8  add rax, -8
00023a67  48 83 f8 1f  cmp rax, 0x1f
00023a6b  76 07  jbe 0x180023a74
00023a6d  ff 15 45 6d 01 00  call qword ptr [rip + 0x16d45]
00023a73  cc  int3 
00023a74  e8 bb 16 01 00  call 0x180035134
00023a79  48 83 fb ff  cmp rbx, -1
00023a7d  0f 85 44 01 00 00  jne 0x180023bc7
00023a83  0f 57 c0  xorps xmm0, xmm0
00023a86  0f 11 45 c8  movups xmmword ptr [rbp - 0x38], xmm0
00023a8a  0f 57 c9  xorps xmm1, xmm1
00023a8d  f3 0f 7f 4d d8  movdqu xmmword ptr [rbp - 0x28], xmm1
00023a92  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
00023a99  4c 8b c6  mov r8, rsi
00023a9c  0f 1f 40 00  nop dword ptr [rax]
00023aa0  49 ff c0  inc r8
00023aa3  42 80 3c 00 00  cmp byte ptr [rax + r8], 0
00023aa8  75 f6  jne 0x180023aa0
00023aaa  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
00023ab1  48 8d 4d c8  lea rcx, [rbp - 0x38]
00023ab5  e8 d6 33 fe ff  call 0x180006e90
00023aba  90  nop 
00023abb  41 b8 05 00 00 00  mov r8d, 5
00023ac1  48 8d 15 fc e6 01 00  lea rdx, [rip + 0x1e6fc]
00023ac8  48 8d 4d c8  lea rcx, [rbp - 0x38]
00023acc  e8 6f 13 00 00  call 0x180024e40
00023ad1  0f 57 c0  xorps xmm0, xmm0
00023ad4  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
00023ad9  0f 57 c9  xorps xmm1, xmm1
00023adc  f3 0f 7f 4c 24 78  movdqu xmmword ptr [rsp + 0x78], xmm1
00023ae2  0f 10 00  movups xmm0, xmmword ptr [rax]
00023ae5  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
00023aea  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
00023aee  0f 11 4c 24 78  movups xmmword ptr [rsp + 0x78], xmm1
00023af3  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00023af7  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00023aff  c6 00 00  mov byte ptr [rax], 0
00023b02  4d 8b c6  mov r8, r14
00023b05  48 8d 54 24 68  lea rdx, [rsp + 0x68]
00023b0a  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
00023b0f  e8 ac b7 ff ff  call 0x18001f2c0
00023b14  48 8b d8  mov rbx, rax
00023b17  48 8d 45 28  lea rax, [rbp + 0x28]
00023b1b  48 3b c3  cmp rax, rbx
00023b1e  74 6d  je 0x180023b8d
00023b20  48 8b 55 40  mov rdx, qword ptr [rbp + 0x40]
00023b24  48 83 fa 10  cmp rdx, 0x10
00023b28  72 34  jb 0x180023b5e
00023b2a  48 ff c2  inc rdx
00023b2d  48 8b 4d 28  mov rcx, qword ptr [rbp + 0x28]
00023b31  48 8b c1  mov rax, rcx
00023b34  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023b3b  72 1c  jb 0x180023b59
00023b3d  48 83 c2 27  add rdx, 0x27
00023b41  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023b45  48 2b c1  sub rax, rcx
00023b48  48 83 c0 f8  add rax, -8
00023b4c  48 83 f8 1f  cmp rax, 0x1f
00023b50  76 07  jbe 0x180023b59
00023b52  ff 15 60 6c 01 00  call qword ptr [rip + 0x16c60]
00023b58  cc  int3 
00023b59  e8 d6 15 01 00  call 0x180035134
00023b5e  66 0f 6f 05 0a e4 01 00  movdqa xmm0, xmmword ptr [rip + 0x1e40a]
00023b66  f3 0f 7f 45 38  movdqu xmmword ptr [rbp + 0x38], xmm0
00023b6b  c6 45 28 00  mov byte ptr [rbp + 0x28], 0
00023b6f  0f 10 03  movups xmm0, xmmword ptr [rbx]
00023b72  0f 11 45 28  movups xmmword ptr [rbp + 0x28], xmm0
00023b76  0f 10 4b 10  movups xmm1, xmmword ptr [rbx + 0x10]
00023b7a  0f 11 4d 38  movups xmmword ptr [rbp + 0x38], xmm1
00023b7e  4c 89 63 10  mov qword ptr [rbx + 0x10], r12
00023b82  48 c7 43 18 0f 00 00 00  mov qword ptr [rbx + 0x18], 0xf
00023b8a  c6 03 00  mov byte ptr [rbx], 0
00023b8d  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
00023b92  e8 f9 4e fe ff  call 0x180008a90
00023b97  90  nop 
00023b98  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
00023b9d  e8 ee 4e fe ff  call 0x180008a90
00023ba2  90  nop 
00023ba3  48 8d 4d c8  lea rcx, [rbp - 0x38]
00023ba7  e8 e4 4e fe ff  call 0x180008a90
00023bac  48 8d 55 28  lea rdx, [rbp + 0x28]
00023bb0  48 83 7d 40 10  cmp qword ptr [rbp + 0x40], 0x10
00023bb5  48 0f 43 55 28  cmovae rdx, qword ptr [rbp + 0x28]
00023bba  48 8d 0d fb e5 01 00  lea rcx, [rip + 0x1e5fb]
00023bc1  ff 15 59 67 01 00  call qword ptr [rip + 0x16759]
00023bc7  49 8b ce  mov rcx, r14
00023bca  e8 c3 13 01 00  call 0x180034f92
00023bcf  90  nop 
00023bd0  48 8b 55 c0  mov rdx, qword ptr [rbp - 0x40]
00023bd4  48 83 fa 10  cmp rdx, 0x10
00023bd8  72 34  jb 0x180023c0e
00023bda  48 ff c2  inc rdx
00023bdd  48 8b 4d a8  mov rcx, qword ptr [rbp - 0x58]
00023be1  48 8b c1  mov rax, rcx
00023be4  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023beb  72 1c  jb 0x180023c09
00023bed  48 83 c2 27  add rdx, 0x27
00023bf1  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023bf5  48 2b c1  sub rax, rcx
00023bf8  48 83 c0 f8  add rax, -8
00023bfc  48 83 f8 1f  cmp rax, 0x1f
00023c00  76 07  jbe 0x180023c09
00023c02  ff 15 b0 6b 01 00  call qword ptr [rip + 0x16bb0]
00023c08  cc  int3 
00023c09  e8 26 15 01 00  call 0x180035134
00023c0e  66 0f 6f 05 5a e3 01 00  movdqa xmm0, xmmword ptr [rip + 0x1e35a]
00023c16  f3 0f 7f 45 b8  movdqu xmmword ptr [rbp - 0x48], xmm0
00023c1b  c6 45 a8 00  mov byte ptr [rbp - 0x58], 0
00023c1f  48 8b 55 40  mov rdx, qword ptr [rbp + 0x40]
00023c23  48 83 fa 10  cmp rdx, 0x10
00023c27  72 34  jb 0x180023c5d
00023c29  48 ff c2  inc rdx
00023c2c  48 8b 4d 28  mov rcx, qword ptr [rbp + 0x28]
00023c30  48 8b c1  mov rax, rcx
00023c33  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023c3a  72 1c  jb 0x180023c58
00023c3c  48 83 c2 27  add rdx, 0x27
00023c40  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023c44  48 2b c1  sub rax, rcx
00023c47  48 83 c0 f8  add rax, -8
00023c4b  48 83 f8 1f  cmp rax, 0x1f
00023c4f  76 07  jbe 0x180023c58
00023c51  ff 15 61 6b 01 00  call qword ptr [rip + 0x16b61]
00023c57  cc  int3 
00023c58  e8 d7 14 01 00  call 0x180035134
00023c5d  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
00023c62  ff 15 e0 63 01 00  call qword ptr [rip + 0x163e0]
00023c68  0f 57 c0  xorps xmm0, xmm0
00023c6b  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
00023c70  4c 89 64 24 78  mov qword ptr [rsp + 0x78], r12
00023c75  48 c7 45 80 0f 00 00 00  mov qword ptr [rbp - 0x80], 0xf
00023c7d  ba 20 00 00 00  mov edx, 0x20
00023c82  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
00023c87  e8 84 95 ff ff  call 0x18001d210
00023c8c  48 8b d0  mov rdx, rax
00023c8f  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
00023c94  48 c7 44 24 78 1d 00 00 00  mov qword ptr [rsp + 0x78], 0x1d
00023c9d  48 c7 45 80 1f 00 00 00  mov qword ptr [rbp - 0x80], 0x1f
00023ca5  0f 10 05 54 cd 01 00  movups xmm0, xmmword ptr [rip + 0x1cd54]
00023cac  0f 11 00  movups xmmword ptr [rax], xmm0
00023caf  f2 0f 10 05 59 cd 01 00  movsd xmm0, qword ptr [rip + 0x1cd59]
00023cb7  f2 0f 11 40 10  movsd qword ptr [rax + 0x10], xmm0
00023cbc  8b 0d 56 cd 01 00  mov ecx, dword ptr [rip + 0x1cd56]
00023cc2  89 48 18  mov dword ptr [rax + 0x18], ecx
00023cc5  0f b6 05 50 cd 01 00  movzx eax, byte ptr [rip + 0x1cd50]
00023ccc  88 42 1c  mov byte ptr [rdx + 0x1c], al
00023ccf  c6 42 1d 00  mov byte ptr [rdx + 0x1d], 0
00023cd3  48 8d 55 e8  lea rdx, [rbp - 0x18]
00023cd7  48 83 7d 00 10  cmp qword ptr [rbp], 0x10
00023cdc  48 0f 43 55 e8  cmovae rdx, qword ptr [rbp - 0x18]
00023ce1  4c 8b 45 f8  mov r8, qword ptr [rbp - 8]
00023ce5  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
00023cea  e8 51 11 00 00  call 0x180024e40
00023cef  0f 57 c0  xorps xmm0, xmm0
00023cf2  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00023cf7  0f 57 c9  xorps xmm1, xmm1
00023cfa  f3 0f 7f 4c 24 58  movdqu xmmword ptr [rsp + 0x58], xmm1
00023d00  0f 10 00  movups xmm0, xmmword ptr [rax]
00023d03  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00023d08  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
00023d0c  0f 11 4c 24 58  movups xmmword ptr [rsp + 0x58], xmm1
00023d11  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00023d15  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00023d1d  c6 00 00  mov byte ptr [rax], 0
00023d20  48 8b 4c 24 58  mov rcx, qword ptr [rsp + 0x58]
00023d25  48 8b 54 24 60  mov rdx, qword ptr [rsp + 0x60]
00023d2a  48 8b c2  mov rax, rdx
00023d2d  48 2b c1  sub rax, rcx
00023d30  48 83 f8 03  cmp rax, 3
00023d34  72 3b  jb 0x180023d71
00023d36  48 8d 41 03  lea rax, [rcx + 3]
00023d3a  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
00023d3f  48 8d 5c 24 48  lea rbx, [rsp + 0x48]
00023d44  48 83 fa 10  cmp rdx, 0x10
00023d48  48 0f 43 5c 24 48  cmovae rbx, qword ptr [rsp + 0x48]
00023d4e  48 03 d9  add rbx, rcx
00023d51  41 b8 03 00 00 00  mov r8d, 3
00023d57  48 8d 15 9e cc 01 00  lea rdx, [rip + 0x1cc9e]
00023d5e  48 8b cb  mov rcx, rbx
00023d61  e8 6e 25 01 00  call 0x1800362d4
00023d66  c6 43 03 00  mov byte ptr [rbx + 3], 0
00023d6a  48 8d 44 24 48  lea rax, [rsp + 0x48]
00023d6f  eb 21  jmp 0x180023d92
00023d71  48 c7 44 24 20 03 00 00 00  mov qword ptr [rsp + 0x20], 3
00023d7a  4c 8d 0d 7b cc 01 00  lea r9, [rip + 0x1cc7b]
00023d81  45 33 c0  xor r8d, r8d
00023d84  41 8d 50 03  lea edx, [r8 + 3]
00023d88  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
00023d8d  e8 ae 40 fe ff  call 0x180007e40
00023d92  0f 10 30  movups xmm6, xmmword ptr [rax]
00023d95  0f 10 78 10  movups xmm7, xmmword ptr [rax + 0x10]
00023d99  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00023d9d  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00023da5  c6 00 00  mov byte ptr [rax], 0
00023da8  48 8b 55 a0  mov rdx, qword ptr [rbp - 0x60]
00023dac  48 83 fa 10  cmp rdx, 0x10
00023db0  72 34  jb 0x180023de6
00023db2  48 ff c2  inc rdx
00023db5  48 8b 4d 88  mov rcx, qword ptr [rbp - 0x78]
00023db9  48 8b c1  mov rax, rcx
00023dbc  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023dc3  72 1c  jb 0x180023de1
00023dc5  48 83 c2 27  add rdx, 0x27
00023dc9  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023dcd  48 2b c1  sub rax, rcx
00023dd0  48 83 c0 f8  add rax, -8
00023dd4  48 83 f8 1f  cmp rax, 0x1f
00023dd8  76 07  jbe 0x180023de1
00023dda  ff 15 d8 69 01 00  call qword ptr [rip + 0x169d8]
00023de0  cc  int3 
00023de1  e8 4e 13 01 00  call 0x180035134
00023de6  0f 11 75 88  movups xmmword ptr [rbp - 0x78], xmm6
00023dea  0f 11 7d 98  movups xmmword ptr [rbp - 0x68], xmm7
00023dee  48 8b 54 24 60  mov rdx, qword ptr [rsp + 0x60]
00023df3  48 83 fa 10  cmp rdx, 0x10
00023df7  72 35  jb 0x180023e2e
00023df9  48 ff c2  inc rdx
00023dfc  48 8b 4c 24 48  mov rcx, qword ptr [rsp + 0x48]
00023e01  48 8b c1  mov rax, rcx
00023e04  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023e0b  72 1c  jb 0x180023e29
00023e0d  48 83 c2 27  add rdx, 0x27
00023e11  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023e15  48 2b c1  sub rax, rcx
00023e18  48 83 c0 f8  add rax, -8
00023e1c  48 83 f8 1f  cmp rax, 0x1f
00023e20  76 07  jbe 0x180023e29
00023e22  ff 15 90 69 01 00  call qword ptr [rip + 0x16990]
00023e28  cc  int3 
00023e29  e8 06 13 01 00  call 0x180035134
00023e2e  66 0f 6f 05 3a e1 01 00  movdqa xmm0, xmmword ptr [rip + 0x1e13a]
00023e36  f3 0f 7f 44 24 58  movdqu xmmword ptr [rsp + 0x58], xmm0
00023e3c  c6 44 24 48 00  mov byte ptr [rsp + 0x48], 0
00023e41  48 8b 55 80  mov rdx, qword ptr [rbp - 0x80]
00023e45  48 83 fa 10  cmp rdx, 0x10
00023e49  72 35  jb 0x180023e80
00023e4b  48 ff c2  inc rdx
00023e4e  48 8b 4c 24 68  mov rcx, qword ptr [rsp + 0x68]
00023e53  48 8b c1  mov rax, rcx
00023e56  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00023e5d  72 1c  jb 0x180023e7b
00023e5f  48 83 c2 27  add rdx, 0x27
00023e63  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00023e67  48 2b c1  sub rax, rcx
00023e6a  48 83 c0 f8  add rax, -8
00023e6e  48 83 f8 1f  cmp rax, 0x1f
00023e72  76 07  jbe 0x180023e7b
00023e74  ff 15 3e 69 01 00  call qword ptr [rip + 0x1693e]
00023e7a  cc  int3 
00023e7b  e8 b4 12 01 00  call 0x180035134
00023e80  48 8d 55 88  lea rdx, [rbp - 0x78]
00023e84  48 83 7d a0 10  cmp qword ptr [rbp - 0x60], 0x10
00023e89  48 0f 43 55 88  cmovae rdx, qword ptr [rbp - 0x78]
00023e8e  48 8d 44 24 38  lea rax, [rsp + 0x38]
00023e93  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00023e98  41 b9 19 00 02 00  mov r9d, 0x20019
00023e9e  45 33 c0  xor r8d, r8d
00023ea1  48 c7 c1 02 00 00 80  mov rcx, 0xffffffff80000002
00023ea8  ff 15 72 61 01 00  call qword ptr [rip + 0x16172]
00023eae  85 c0  test eax, eax
00023eb0  0f 85 bb 03 00 00  jne 0x180024271
00023eb6  c7 44 24 30 ff 00 00 00  mov dword ptr [rsp + 0x30], 0xff
00023ebe  48 8d 44 24 30  lea rax, [rsp + 0x30]
00023ec3  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00023ec8  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
00023ecf  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
00023ed4  4c 8d 4c 24 40  lea r9, [rsp + 0x40]
00023ed9  45 33 c0  xor r8d, r8d
00023edc  48 8d 15 0d cb 01 00  lea rdx, [rip + 0x1cb0d]
00023ee3  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
00023ee8  ff 15 3a 61 01 00  call qword ptr [rip + 0x1613a]
00023eee  85 c0  test eax, eax
00023ef0  0f 85 70 03 00 00  jne 0x180024266
00023ef6  0f 57 c0  xorps xmm0, xmm0
00023ef9  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
00023efe  66 0f 6f 0d 6a e0 01 00  movdqa xmm1, xmmword ptr [rip + 0x1e06a]
00023f06  f3 0f 7f 4c 24 78  movdqu xmmword ptr [rsp + 0x78], xmm1
00023f0c  88 44 24 68  mov byte ptr [rsp + 0x68], al
00023f10  45 33 c0  xor r8d, r8d
00023f13  33 d2  xor edx, edx
00023f15  48 8d 0d a0 e2 01 00  lea rcx, [rip + 0x1e2a0]
00023f1c  ff 15 f6 63 01 00  call qword ptr [rip + 0x163f6]
00023f22  48 63 f8  movsxd rdi, eax
00023f25  48 8d 4f 01  lea rcx, [rdi + 1]
00023f29  e8 5e 10 01 00  call 0x180034f8c
00023f2e  4c 8b f8  mov r15, rax
00023f31  c6 04 07 00  mov byte ptr [rdi + rax], 0
00023f35  44 8b c7  mov r8d, edi
00023f38  48 8b d0  mov rdx, rax
00023f3b  48 8d 0d 7a e2 01 00  lea rcx, [rip + 0x1e27a]
00023f42  ff 15 d0 63 01 00  call qword ptr [rip + 0x163d0]
00023f48  0f 57 c0  xorps xmm0, xmm0
00023f4b  0f 11 45 a8  movups xmmword ptr [rbp - 0x58], xmm0
00023f4f  0f 57 c9  xorps xmm1, xmm1
00023f52  f3 0f 7f 4d b8  movdqu xmmword ptr [rbp - 0x48], xmm1
00023f57  4c 8b c6  mov r8, rsi
00023f5a  66 0f 1f 44 00 00  nop word ptr [rax + rax]
00023f60  49 ff c0  inc r8
00023f63  43 80 3c 07 00  cmp byte ptr [r15 + r8], 0
00023f68  75 f6  jne 0x180023f60
00023f6a  49 8b d7  mov rdx, r15
00023f6d  48 8d 4d a8  lea rcx, [rbp - 0x58]
00023f71  e8 1a 2f fe ff  call 0x180006e90
00023f76  90  nop 
00023f77  0f 57 c0  xorps xmm0, xmm0
00023f7a  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00023f7f  4c 89 64 24 58  mov qword ptr [rsp + 0x58], r12
00023f84  4c 89 64 24 60  mov qword ptr [rsp + 0x60], r12
00023f89  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
00023f90  48 8b fe  mov rdi, rsi
00023f93  48 ff c7  inc rdi
00023f96  80 3c 38 00  cmp byte ptr [rax + rdi], 0
00023f9a  75 f7  jne 0x180023f93
00023f9c  49 be ff ff ff ff ff ff ff 7f  movabs r14, 0x7fffffffffffffff
00023fa6  49 3b fe  cmp rdi, r14
00023fa9  0f 87 d9 0c 00 00  ja 0x180024c88
00023faf  48 c7 44 24 60 0f 00 00 00  mov qword ptr [rsp + 0x60], 0xf
00023fb8  48 83 ff 10  cmp rdi, 0x10
00023fbc  73 20  jae 0x180023fde
00023fbe  48 89 7c 24 58  mov qword ptr [rsp + 0x58], rdi
00023fc3  4c 8b c7  mov r8, rdi
00023fc6  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
00023fcd  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
00023fd2  e8 cd 22 01 00  call 0x1800362a4
00023fd7  c6 44 3c 48 00  mov byte ptr [rsp + rdi + 0x48], 0
00023fdc  eb 51  jmp 0x18002402f
00023fde  48 8b c7  mov rax, rdi
00023fe1  48 83 c8 0f  or rax, 0xf
00023fe5  49 3b c6  cmp rax, r14
00023fe8  77 0f  ja 0x180023ff9
00023fea  4c 8b f0  mov r14, rax
00023fed  b9 16 00 00 00  mov ecx, 0x16
00023ff2  48 3b c1  cmp rax, rcx
00023ff5  4c 0f 42 f1  cmovb r14, rcx
00023ff9  49 8d 56 01  lea rdx, [r14 + 1]
00023ffd  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
00024002  e8 09 92 ff ff  call 0x18001d210
00024007  48 8b d8  mov rbx, rax
0002400a  48 89 44 24 48  mov qword ptr [rsp + 0x48], rax
0002400f  48 89 7c 24 58  mov qword ptr [rsp + 0x58], rdi
00024014  4c 89 74 24 60  mov qword ptr [rsp + 0x60], r14
00024019  4c 8b c7  mov r8, rdi
0002401c  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
00024023  48 8b c8  mov rcx, rax
00024026  e8 79 22 01 00  call 0x1800362a4
0002402b  c6 04 3b 00  mov byte ptr [rbx + rdi], 0
0002402f  41 b8 01 00 00 00  mov r8d, 1
00024035  48 8d 15 18 ca 01 00  lea rdx, [rip + 0x1ca18]
0002403c  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
00024041  e8 fa 0d 00 00  call 0x180024e40
00024046  0f 10 38  movups xmm7, xmmword ptr [rax]
00024049  0f 11 7d c8  movups xmmword ptr [rbp - 0x38], xmm7
0002404d  0f 10 70 10  movups xmm6, xmmword ptr [rax + 0x10]
00024051  0f 11 75 d8  movups xmmword ptr [rbp - 0x28], xmm6
00024055  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00024059  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00024061  c6 00 00  mov byte ptr [rax], 0
00024064  45 33 c0  xor r8d, r8d
00024067  48 8d 55 c8  lea rdx, [rbp - 0x38]
0002406b  48 8d 4d a8  lea rcx, [rbp - 0x58]
0002406f  e8 9c 0e 00 00  call 0x180024f10
00024074  48 8b d8  mov rbx, rax
00024077  66 0f 73 de 08  psrldq xmm6, 8
0002407c  66 48 0f 7e f2  movq rdx, xmm6
00024081  48 83 fa 10  cmp rdx, 0x10
00024085  72 36  jb 0x1800240bd
00024087  48 ff c2  inc rdx
0002408a  66 48 0f 7e f9  movq rcx, xmm7
0002408f  48 8b c1  mov rax, rcx
00024092  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024099  72 1c  jb 0x1800240b7
0002409b  48 83 c2 27  add rdx, 0x27
0002409f  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
000240a3  48 2b c1  sub rax, rcx
000240a6  48 83 c0 f8  add rax, -8
000240aa  48 83 f8 1f  cmp rax, 0x1f
000240ae  76 07  jbe 0x1800240b7
000240b0  ff 15 02 67 01 00  call qword ptr [rip + 0x16702]
000240b6  cc  int3 
000240b7  e8 78 10 01 00  call 0x180035134
000240bc  90  nop 
000240bd  48 8b 54 24 60  mov rdx, qword ptr [rsp + 0x60]
000240c2  48 83 fa 10  cmp rdx, 0x10
000240c6  72 35  jb 0x1800240fd
000240c8  48 ff c2  inc rdx
000240cb  48 8b 4c 24 48  mov rcx, qword ptr [rsp + 0x48]
000240d0  48 8b c1  mov rax, rcx
000240d3  48 81 fa 00 10 00 00  cmp rdx, 0x1000
000240da  72 1c  jb 0x1800240f8
000240dc  48 83 c2 27  add rdx, 0x27
000240e0  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
000240e4  48 2b c1  sub rax, rcx
000240e7  48 83 c0 f8  add rax, -8
000240eb  48 83 f8 1f  cmp rax, 0x1f
000240ef  76 07  jbe 0x1800240f8
000240f1  ff 15 c1 66 01 00  call qword ptr [rip + 0x166c1]
000240f7  cc  int3 
000240f8  e8 37 10 01 00  call 0x180035134
000240fd  48 83 fb ff  cmp rbx, -1
00024101  0f 85 0f 01 00 00  jne 0x180024216
00024107  0f 57 c0  xorps xmm0, xmm0
0002410a  0f 11 45 c8  movups xmmword ptr [rbp - 0x38], xmm0
0002410e  0f 57 c9  xorps xmm1, xmm1
00024111  f3 0f 7f 4d d8  movdqu xmmword ptr [rbp - 0x28], xmm1
00024116  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
0002411d  4c 8b c6  mov r8, rsi
00024120  49 ff c0  inc r8
00024123  42 80 3c 00 00  cmp byte ptr [rax + r8], 0
00024128  75 f6  jne 0x180024120
0002412a  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
00024131  48 8d 4d c8  lea rcx, [rbp - 0x38]
00024135  e8 56 2d fe ff  call 0x180006e90
0002413a  90  nop 
0002413b  41 b8 01 00 00 00  mov r8d, 1
00024141  48 8d 15 0c c9 01 00  lea rdx, [rip + 0x1c90c]
00024148  48 8d 4d c8  lea rcx, [rbp - 0x38]
0002414c  e8 ef 0c 00 00  call 0x180024e40
00024151  0f 57 c0  xorps xmm0, xmm0
00024154  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00024159  0f 57 c9  xorps xmm1, xmm1
0002415c  f3 0f 7f 4c 24 58  movdqu xmmword ptr [rsp + 0x58], xmm1
00024162  0f 10 00  movups xmm0, xmmword ptr [rax]
00024165  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
0002416a  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
0002416e  0f 11 4c 24 58  movups xmmword ptr [rsp + 0x58], xmm1
00024173  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00024177  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
0002417f  c6 00 00  mov byte ptr [rax], 0
00024182  4d 8b c7  mov r8, r15
00024185  48 8d 54 24 48  lea rdx, [rsp + 0x48]
0002418a  48 8d 8d 88 00 00 00  lea rcx, [rbp + 0x88]
00024191  e8 2a b1 ff ff  call 0x18001f2c0
00024196  48 8b d0  mov rdx, rax
00024199  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
0002419e  e8 fd b2 ff ff  call 0x18001f4a0
000241a3  48 8d 8d 88 00 00 00  lea rcx, [rbp + 0x88]
000241aa  e8 e1 48 fe ff  call 0x180008a90
000241af  90  nop 
000241b0  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
000241b5  e8 d6 48 fe ff  call 0x180008a90
000241ba  90  nop 
000241bb  48 8b 55 e0  mov rdx, qword ptr [rbp - 0x20]
000241bf  48 83 fa 10  cmp rdx, 0x10
000241c3  72 34  jb 0x1800241f9
000241c5  48 ff c2  inc rdx
000241c8  48 8b 4d c8  mov rcx, qword ptr [rbp - 0x38]
000241cc  48 8b c1  mov rax, rcx
000241cf  48 81 fa 00 10 00 00  cmp rdx, 0x1000
000241d6  72 1c  jb 0x1800241f4
000241d8  48 83 c2 27  add rdx, 0x27
000241dc  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
000241e0  48 2b c1  sub rax, rcx
000241e3  48 83 c0 f8  add rax, -8
000241e7  48 83 f8 1f  cmp rax, 0x1f
000241eb  76 07  jbe 0x1800241f4
000241ed  ff 15 c5 65 01 00  call qword ptr [rip + 0x165c5]
000241f3  cc  int3 
000241f4  e8 3b 0f 01 00  call 0x180035134
000241f9  48 8d 54 24 68  lea rdx, [rsp + 0x68]
000241fe  48 83 7d 80 10  cmp qword ptr [rbp - 0x80], 0x10
00024203  48 0f 43 54 24 68  cmovae rdx, qword ptr [rsp + 0x68]
00024209  48 8d 0d ac df 01 00  lea rcx, [rip + 0x1dfac]
00024210  ff 15 0a 61 01 00  call qword ptr [rip + 0x1610a]
00024216  49 8b cf  mov rcx, r15
00024219  e8 74 0d 01 00  call 0x180034f92
0002421e  90  nop 
0002421f  4c 8b 45 c0  mov r8, qword ptr [rbp - 0x40]
00024223  49 83 f8 10  cmp r8, 0x10
00024227  72 10  jb 0x180024239
00024229  49 ff c0  inc r8
0002422c  48 8b 55 a8  mov rdx, qword ptr [rbp - 0x58]
00024230  48 8d 4d a8  lea rcx, [rbp - 0x58]
00024234  e8 97 0c 00 00  call 0x180024ed0
00024239  66 0f 6f 05 2f dd 01 00  movdqa xmm0, xmmword ptr [rip + 0x1dd2f]
00024241  f3 0f 7f 45 b8  movdqu xmmword ptr [rbp - 0x48], xmm0
00024246  c6 45 a8 00  mov byte ptr [rbp - 0x58], 0
0002424a  4c 8b 45 80  mov r8, qword ptr [rbp - 0x80]
0002424e  49 83 f8 10  cmp r8, 0x10
00024252  72 12  jb 0x180024266
00024254  49 ff c0  inc r8
00024257  48 8b 54 24 68  mov rdx, qword ptr [rsp + 0x68]
0002425c  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
00024261  e8 6a 0c 00 00  call 0x180024ed0
00024266  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
0002426b  ff 15 d7 5d 01 00  call qword ptr [rip + 0x15dd7]
00024271  e8 5a f9 00 00  call 0x180033bd0
00024276  0f 57 c0  xorps xmm0, xmm0
00024279  83 f8 02  cmp eax, 2
0002427c  0f 85 22 02 00 00  jne 0x1800244a4
00024282  0f 11 85 88 00 00 00  movups xmmword ptr [rbp + 0x88], xmm0
00024289  4c 89 a5 98 00 00 00  mov qword ptr [rbp + 0x98], r12
00024290  48 c7 85 a0 00 00 00 0f 00 00 00  mov qword ptr [rbp + 0xa0], 0xf
0002429b  8d 50 2e  lea edx, [rax + 0x2e]
0002429e  48 8d 8d 88 00 00 00  lea rcx, [rbp + 0x88]
000242a5  e8 66 8f ff ff  call 0x18001d210
000242aa  48 89 85 88 00 00 00  mov qword ptr [rbp + 0x88], rax
000242b1  48 c7 85 98 00 00 00 24 00 00 00  mov qword ptr [rbp + 0x98], 0x24
000242bc  48 c7 85 a0 00 00 00 2f 00 00 00  mov qword ptr [rbp + 0xa0], 0x2f
000242c7  0f 10 05 02 df 01 00  movups xmm0, xmmword ptr [rip + 0x1df02]
000242ce  0f 11 00  movups xmmword ptr [rax], xmm0
000242d1  0f 10 0d 08 df 01 00  movups xmm1, xmmword ptr [rip + 0x1df08]
000242d8  0f 11 48 10  movups xmmword ptr [rax + 0x10], xmm1
000242dc  8b 0d 0e df 01 00  mov ecx, dword ptr [rip + 0x1df0e]
000242e2  89 48 20  mov dword ptr [rax + 0x20], ecx
000242e5  c6 40 24 00  mov byte ptr [rax + 0x24], 0
000242e9  48 8d 55 e8  lea rdx, [rbp - 0x18]
000242ed  48 83 7d 00 10  cmp qword ptr [rbp], 0x10
000242f2  48 0f 43 55 e8  cmovae rdx, qword ptr [rbp - 0x18]
000242f7  4c 8b 45 f8  mov r8, qword ptr [rbp - 8]
000242fb  48 8d 8d 88 00 00 00  lea rcx, [rbp + 0x88]
00024302  e8 39 0b 00 00  call 0x180024e40
00024307  0f 57 c0  xorps xmm0, xmm0
0002430a  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
0002430f  0f 57 c9  xorps xmm1, xmm1
00024312  f3 0f 7f 4c 24 58  movdqu xmmword ptr [rsp + 0x58], xmm1
00024318  0f 10 00  movups xmm0, xmmword ptr [rax]
0002431b  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00024320  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
00024324  0f 11 4c 24 58  movups xmmword ptr [rsp + 0x58], xmm1
00024329  4c 89 60 10  mov qword ptr [rax + 0x10], r12
0002432d  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00024335  c6 00 00  mov byte ptr [rax], 0
00024338  48 8b 4c 24 58  mov rcx, qword ptr [rsp + 0x58]
0002433d  4c 8b 44 24 60  mov r8, qword ptr [rsp + 0x60]
00024342  49 8b c0  mov rax, r8
00024345  48 2b c1  sub rax, rcx
00024348  48 83 f8 03  cmp rax, 3
0002434c  72 3b  jb 0x180024389
0002434e  48 8d 41 03  lea rax, [rcx + 3]
00024352  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
00024357  48 8d 5c 24 48  lea rbx, [rsp + 0x48]
0002435c  49 83 f8 10  cmp r8, 0x10
00024360  48 0f 43 5c 24 48  cmovae rbx, qword ptr [rsp + 0x48]
00024366  48 03 d9  add rbx, rcx
00024369  41 b8 03 00 00 00  mov r8d, 3
0002436f  48 8d 15 86 c6 01 00  lea rdx, [rip + 0x1c686]
00024376  48 8b cb  mov rcx, rbx
00024379  e8 56 1f 01 00  call 0x1800362d4
0002437e  c6 43 03 00  mov byte ptr [rbx + 3], 0
00024382  48 8d 44 24 48  lea rax, [rsp + 0x48]
00024387  eb 21  jmp 0x1800243aa
00024389  48 c7 44 24 20 03 00 00 00  mov qword ptr [rsp + 0x20], 3
00024392  4c 8d 0d 63 c6 01 00  lea r9, [rip + 0x1c663]
00024399  45 33 c0  xor r8d, r8d
0002439c  41 8d 50 03  lea edx, [r8 + 3]
000243a0  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
000243a5  e8 96 3a fe ff  call 0x180007e40
000243aa  0f 10 30  movups xmm6, xmmword ptr [rax]
000243ad  0f 10 78 10  movups xmm7, xmmword ptr [rax + 0x10]
000243b1  4c 89 60 10  mov qword ptr [rax + 0x10], r12
000243b5  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
000243bd  c6 00 00  mov byte ptr [rax], 0
000243c0  48 8b 55 a0  mov rdx, qword ptr [rbp - 0x60]
000243c4  48 83 fa 10  cmp rdx, 0x10
000243c8  72 34  jb 0x1800243fe
000243ca  48 ff c2  inc rdx
000243cd  48 8b 4d 88  mov rcx, qword ptr [rbp - 0x78]
000243d1  48 8b c1  mov rax, rcx
000243d4  48 81 fa 00 10 00 00  cmp rdx, 0x1000
000243db  72 1c  jb 0x1800243f9
000243dd  48 83 c2 27  add rdx, 0x27
000243e1  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
000243e5  48 2b c1  sub rax, rcx
000243e8  48 83 c0 f8  add rax, -8
000243ec  48 83 f8 1f  cmp rax, 0x1f
000243f0  76 07  jbe 0x1800243f9
000243f2  ff 15 c0 63 01 00  call qword ptr [rip + 0x163c0]
000243f8  cc  int3 
000243f9  e8 36 0d 01 00  call 0x180035134
000243fe  0f 11 75 88  movups xmmword ptr [rbp - 0x78], xmm6
00024402  0f 11 7d 98  movups xmmword ptr [rbp - 0x68], xmm7
00024406  48 8b 54 24 60  mov rdx, qword ptr [rsp + 0x60]
0002440b  48 83 fa 10  cmp rdx, 0x10
0002440f  72 35  jb 0x180024446
00024411  48 ff c2  inc rdx
00024414  48 8b 4c 24 48  mov rcx, qword ptr [rsp + 0x48]
00024419  48 8b c1  mov rax, rcx
0002441c  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024423  72 1c  jb 0x180024441
00024425  48 83 c2 27  add rdx, 0x27
00024429  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
0002442d  48 2b c1  sub rax, rcx
00024430  48 83 c0 f8  add rax, -8
00024434  48 83 f8 1f  cmp rax, 0x1f
00024438  76 07  jbe 0x180024441
0002443a  ff 15 78 63 01 00  call qword ptr [rip + 0x16378]
00024440  cc  int3 
00024441  e8 ee 0c 01 00  call 0x180035134
00024446  66 0f 6f 05 22 db 01 00  movdqa xmm0, xmmword ptr [rip + 0x1db22]
0002444e  f3 0f 7f 44 24 58  movdqu xmmword ptr [rsp + 0x58], xmm0
00024454  c6 44 24 48 00  mov byte ptr [rsp + 0x48], 0
00024459  48 8b 95 a0 00 00 00  mov rdx, qword ptr [rbp + 0xa0]
00024460  48 83 fa 10  cmp rdx, 0x10
00024464  0f 82 50 02 00 00  jb 0x1800246ba
0002446a  48 ff c2  inc rdx
0002446d  48 8b 8d 88 00 00 00  mov rcx, qword ptr [rbp + 0x88]
00024474  48 8b c1  mov rax, rcx
00024477  48 81 fa 00 10 00 00  cmp rdx, 0x1000
0002447e  0f 82 31 02 00 00  jb 0x1800246b5
00024484  48 83 c2 27  add rdx, 0x27
00024488  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
0002448c  48 2b c1  sub rax, rcx
0002448f  48 83 c0 f8  add rax, -8
00024493  48 83 f8 1f  cmp rax, 0x1f
00024497  0f 86 18 02 00 00  jbe 0x1800246b5
0002449d  ff 15 15 63 01 00  call qword ptr [rip + 0x16315]
000244a3  cc  int3 
000244a4  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
000244a9  4c 89 64 24 78  mov qword ptr [rsp + 0x78], r12
000244ae  48 c7 45 80 0f 00 00 00  mov qword ptr [rbp - 0x80], 0xf
000244b6  ba 20 00 00 00  mov edx, 0x20
000244bb  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
000244c0  e8 4b 8d ff ff  call 0x18001d210
000244c5  48 8b d0  mov rdx, rax
000244c8  48 89 44 24 68  mov qword ptr [rsp + 0x68], rax
000244cd  48 c7 44 24 78 1e 00 00 00  mov qword ptr [rsp + 0x78], 0x1e
000244d6  48 c7 45 80 1f 00 00 00  mov qword ptr [rbp - 0x80], 0x1f
000244de  0f 10 05 13 dd 01 00  movups xmm0, xmmword ptr [rip + 0x1dd13]
000244e5  0f 11 00  movups xmmword ptr [rax], xmm0
000244e8  f2 0f 10 05 18 dd 01 00  movsd xmm0, qword ptr [rip + 0x1dd18]
000244f0  f2 0f 11 40 10  movsd qword ptr [rax + 0x10], xmm0
000244f5  8b 0d 15 dd 01 00  mov ecx, dword ptr [rip + 0x1dd15]
000244fb  89 48 18  mov dword ptr [rax + 0x18], ecx
000244fe  0f b7 05 0f dd 01 00  movzx eax, word ptr [rip + 0x1dd0f]
00024505  66 89 42 1c  mov word ptr [rdx + 0x1c], ax
00024509  c6 42 1e 00  mov byte ptr [rdx + 0x1e], 0
0002450d  48 8d 55 e8  lea rdx, [rbp - 0x18]
00024511  48 83 7d 00 10  cmp qword ptr [rbp], 0x10
00024516  48 0f 43 55 e8  cmovae rdx, qword ptr [rbp - 0x18]
0002451b  4c 8b 45 f8  mov r8, qword ptr [rbp - 8]
0002451f  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
00024524  e8 17 09 00 00  call 0x180024e40
00024529  0f 57 c0  xorps xmm0, xmm0
0002452c  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00024531  0f 57 c9  xorps xmm1, xmm1
00024534  f3 0f 7f 4c 24 58  movdqu xmmword ptr [rsp + 0x58], xmm1
0002453a  0f 10 00  movups xmm0, xmmword ptr [rax]
0002453d  0f 11 44 24 48  movups xmmword ptr [rsp + 0x48], xmm0
00024542  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
00024546  0f 11 4c 24 58  movups xmmword ptr [rsp + 0x58], xmm1
0002454b  4c 89 60 10  mov qword ptr [rax + 0x10], r12
0002454f  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00024557  c6 00 00  mov byte ptr [rax], 0
0002455a  48 8b 4c 24 58  mov rcx, qword ptr [rsp + 0x58]
0002455f  48 8b 54 24 60  mov rdx, qword ptr [rsp + 0x60]
00024564  48 8b c2  mov rax, rdx
00024567  48 2b c1  sub rax, rcx
0002456a  48 83 f8 03  cmp rax, 3
0002456e  72 3b  jb 0x1800245ab
00024570  48 8d 41 03  lea rax, [rcx + 3]
00024574  48 89 44 24 58  mov qword ptr [rsp + 0x58], rax
00024579  48 8d 5c 24 48  lea rbx, [rsp + 0x48]
0002457e  48 83 fa 10  cmp rdx, 0x10
00024582  48 0f 43 5c 24 48  cmovae rbx, qword ptr [rsp + 0x48]
00024588  48 03 d9  add rbx, rcx
0002458b  41 b8 03 00 00 00  mov r8d, 3
00024591  48 8d 15 64 c4 01 00  lea rdx, [rip + 0x1c464]
00024598  48 8b cb  mov rcx, rbx
0002459b  e8 34 1d 01 00  call 0x1800362d4
000245a0  c6 43 03 00  mov byte ptr [rbx + 3], 0
000245a4  48 8d 44 24 48  lea rax, [rsp + 0x48]
000245a9  eb 21  jmp 0x1800245cc
000245ab  48 c7 44 24 20 03 00 00 00  mov qword ptr [rsp + 0x20], 3
000245b4  4c 8d 0d 41 c4 01 00  lea r9, [rip + 0x1c441]
000245bb  45 33 c0  xor r8d, r8d
000245be  41 8d 50 03  lea edx, [r8 + 3]
000245c2  48 8d 4c 24 48  lea rcx, [rsp + 0x48]
000245c7  e8 74 38 fe ff  call 0x180007e40
000245cc  0f 10 30  movups xmm6, xmmword ptr [rax]
000245cf  0f 10 78 10  movups xmm7, xmmword ptr [rax + 0x10]
000245d3  4c 89 60 10  mov qword ptr [rax + 0x10], r12
000245d7  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
000245df  c6 00 00  mov byte ptr [rax], 0
000245e2  48 8b 55 a0  mov rdx, qword ptr [rbp - 0x60]
000245e6  48 83 fa 10  cmp rdx, 0x10
000245ea  72 34  jb 0x180024620
000245ec  48 ff c2  inc rdx
000245ef  48 8b 4d 88  mov rcx, qword ptr [rbp - 0x78]
000245f3  48 8b c1  mov rax, rcx
000245f6  48 81 fa 00 10 00 00  cmp rdx, 0x1000
000245fd  72 1c  jb 0x18002461b
000245ff  48 83 c2 27  add rdx, 0x27
00024603  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024607  48 2b c1  sub rax, rcx
0002460a  48 83 c0 f8  add rax, -8
0002460e  48 83 f8 1f  cmp rax, 0x1f
00024612  76 07  jbe 0x18002461b
00024614  ff 15 9e 61 01 00  call qword ptr [rip + 0x1619e]
0002461a  cc  int3 
0002461b  e8 14 0b 01 00  call 0x180035134
00024620  0f 11 75 88  movups xmmword ptr [rbp - 0x78], xmm6
00024624  0f 11 7d 98  movups xmmword ptr [rbp - 0x68], xmm7
00024628  48 8b 54 24 60  mov rdx, qword ptr [rsp + 0x60]
0002462d  48 83 fa 10  cmp rdx, 0x10
00024631  72 35  jb 0x180024668
00024633  48 ff c2  inc rdx
00024636  48 8b 4c 24 48  mov rcx, qword ptr [rsp + 0x48]
0002463b  48 8b c1  mov rax, rcx
0002463e  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024645  72 1c  jb 0x180024663
00024647  48 83 c2 27  add rdx, 0x27
0002464b  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
0002464f  48 2b c1  sub rax, rcx
00024652  48 83 c0 f8  add rax, -8
00024656  48 83 f8 1f  cmp rax, 0x1f
0002465a  76 07  jbe 0x180024663
0002465c  ff 15 56 61 01 00  call qword ptr [rip + 0x16156]
00024662  cc  int3 
00024663  e8 cc 0a 01 00  call 0x180035134
00024668  66 0f 6f 05 00 d9 01 00  movdqa xmm0, xmmword ptr [rip + 0x1d900]
00024670  f3 0f 7f 44 24 58  movdqu xmmword ptr [rsp + 0x58], xmm0
00024676  c6 44 24 48 00  mov byte ptr [rsp + 0x48], 0
0002467b  48 8b 55 80  mov rdx, qword ptr [rbp - 0x80]
0002467f  48 83 fa 10  cmp rdx, 0x10
00024683  72 35  jb 0x1800246ba
00024685  48 ff c2  inc rdx
00024688  48 8b 4c 24 68  mov rcx, qword ptr [rsp + 0x68]
0002468d  48 8b c1  mov rax, rcx
00024690  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024697  72 1c  jb 0x1800246b5
00024699  48 83 c2 27  add rdx, 0x27
0002469d  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
000246a1  48 2b c1  sub rax, rcx
000246a4  48 83 c0 f8  add rax, -8
000246a8  48 83 f8 1f  cmp rax, 0x1f
000246ac  76 07  jbe 0x1800246b5
000246ae  ff 15 04 61 01 00  call qword ptr [rip + 0x16104]
000246b4  cc  int3 
000246b5  e8 7a 0a 01 00  call 0x180035134
000246ba  48 8d 55 88  lea rdx, [rbp - 0x78]
000246be  48 83 7d a0 10  cmp qword ptr [rbp - 0x60], 0x10
000246c3  48 0f 43 55 88  cmovae rdx, qword ptr [rbp - 0x78]
000246c8  48 8d 44 24 38  lea rax, [rsp + 0x38]
000246cd  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
000246d2  41 b9 19 00 02 00  mov r9d, 0x20019
000246d8  45 33 c0  xor r8d, r8d
000246db  48 c7 c1 02 00 00 80  mov rcx, 0xffffffff80000002
000246e2  ff 15 38 59 01 00  call qword ptr [rip + 0x15938]
000246e8  85 c0  test eax, eax
000246ea  0f 85 26 04 00 00  jne 0x180024b16
000246f0  c7 44 24 30 ff 00 00 00  mov dword ptr [rsp + 0x30], 0xff
000246f8  48 8d 44 24 30  lea rax, [rsp + 0x30]
000246fd  48 89 44 24 28  mov qword ptr [rsp + 0x28], rax
00024702  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
00024709  48 89 44 24 20  mov qword ptr [rsp + 0x20], rax
0002470e  4c 8d 4c 24 40  lea r9, [rsp + 0x40]
00024713  45 33 c0  xor r8d, r8d
00024716  48 8d 15 0f c3 01 00  lea rdx, [rip + 0x1c30f]
0002471d  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
00024722  ff 15 00 59 01 00  call qword ptr [rip + 0x15900]
00024728  85 c0  test eax, eax
0002472a  0f 85 da 03 00 00  jne 0x180024b0a
00024730  0f 57 c0  xorps xmm0, xmm0
00024733  0f 11 45 48  movups xmmword ptr [rbp + 0x48], xmm0
00024737  66 0f 6f 0d 31 d8 01 00  movdqa xmm1, xmmword ptr [rip + 0x1d831]
0002473f  f3 0f 7f 4d 58  movdqu xmmword ptr [rbp + 0x58], xmm1
00024744  88 45 48  mov byte ptr [rbp + 0x48], al
00024747  45 33 c0  xor r8d, r8d
0002474a  33 d2  xor edx, edx
0002474c  48 8d 0d 69 da 01 00  lea rcx, [rip + 0x1da69]
00024753  ff 15 bf 5b 01 00  call qword ptr [rip + 0x15bbf]
00024759  48 63 f8  movsxd rdi, eax
0002475c  48 8d 4f 01  lea rcx, [rdi + 1]
00024760  e8 27 08 01 00  call 0x180034f8c
00024765  4c 8b f0  mov r14, rax
00024768  c6 04 07 00  mov byte ptr [rdi + rax], 0
0002476c  44 8b c7  mov r8d, edi
0002476f  48 8b d0  mov rdx, rax
00024772  48 8d 0d 43 da 01 00  lea rcx, [rip + 0x1da43]
00024779  ff 15 99 5b 01 00  call qword ptr [rip + 0x15b99]
0002477f  0f 57 c0  xorps xmm0, xmm0
00024782  0f 11 44 24 68  movups xmmword ptr [rsp + 0x68], xmm0
00024787  0f 57 c9  xorps xmm1, xmm1
0002478a  f3 0f 7f 4c 24 78  movdqu xmmword ptr [rsp + 0x78], xmm1
00024790  4c 8b c6  mov r8, rsi
00024793  49 ff c0  inc r8
00024796  43 80 3c 06 00  cmp byte ptr [r14 + r8], 0
0002479b  75 f6  jne 0x180024793
0002479d  49 8b d6  mov rdx, r14
000247a0  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
000247a5  e8 e6 26 fe ff  call 0x180006e90
000247aa  90  nop 
000247ab  0f 57 c0  xorps xmm0, xmm0
000247ae  0f 11 45 c8  movups xmmword ptr [rbp - 0x38], xmm0
000247b2  0f 57 c9  xorps xmm1, xmm1
000247b5  f3 0f 7f 4d d8  movdqu xmmword ptr [rbp - 0x28], xmm1
000247ba  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
000247c1  4c 8b c6  mov r8, rsi
000247c4  49 ff c0  inc r8
000247c7  42 80 3c 00 00  cmp byte ptr [rax + r8], 0
000247cc  75 f6  jne 0x1800247c4
000247ce  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
000247d5  48 8d 4d c8  lea rcx, [rbp - 0x38]
000247d9  e8 b2 26 fe ff  call 0x180006e90
000247de  90  nop 
000247df  41 b8 01 00 00 00  mov r8d, 1
000247e5  48 8d 15 68 c2 01 00  lea rdx, [rip + 0x1c268]
000247ec  48 8d 4d c8  lea rcx, [rbp - 0x38]
000247f0  e8 4b 06 00 00  call 0x180024e40
000247f5  0f 10 38  movups xmm7, xmmword ptr [rax]
000247f8  0f 11 7d a8  movups xmmword ptr [rbp - 0x58], xmm7
000247fc  0f 10 70 10  movups xmm6, xmmword ptr [rax + 0x10]
00024800  0f 11 75 b8  movups xmmword ptr [rbp - 0x48], xmm6
00024804  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00024808  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
00024810  c6 00 00  mov byte ptr [rax], 0
00024813  45 33 c0  xor r8d, r8d
00024816  48 8d 55 a8  lea rdx, [rbp - 0x58]
0002481a  48 8d 4c 24 68  lea rcx, [rsp + 0x68]
0002481f  e8 ec 06 00 00  call 0x180024f10
00024824  48 8b d8  mov rbx, rax
00024827  66 0f 73 de 08  psrldq xmm6, 8
0002482c  66 48 0f 7e f2  movq rdx, xmm6
00024831  48 83 fa 10  cmp rdx, 0x10
00024835  72 36  jb 0x18002486d
00024837  48 ff c2  inc rdx
0002483a  66 48 0f 7e f9  movq rcx, xmm7
0002483f  48 8b c1  mov rax, rcx
00024842  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024849  72 1c  jb 0x180024867
0002484b  48 83 c2 27  add rdx, 0x27
0002484f  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024853  48 2b c1  sub rax, rcx
00024856  48 83 c0 f8  add rax, -8
0002485a  48 83 f8 1f  cmp rax, 0x1f
0002485e  76 07  jbe 0x180024867
00024860  ff 15 52 5f 01 00  call qword ptr [rip + 0x15f52]
00024866  cc  int3 
00024867  e8 c8 08 01 00  call 0x180035134
0002486c  90  nop 
0002486d  48 8b 55 e0  mov rdx, qword ptr [rbp - 0x20]
00024871  48 83 fa 10  cmp rdx, 0x10
00024875  72 34  jb 0x1800248ab
00024877  48 ff c2  inc rdx
0002487a  48 8b 4d c8  mov rcx, qword ptr [rbp - 0x38]
0002487e  48 8b c1  mov rax, rcx
00024881  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024888  72 1c  jb 0x1800248a6
0002488a  48 83 c2 27  add rdx, 0x27
0002488e  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024892  48 2b c1  sub rax, rcx
00024895  48 83 c0 f8  add rax, -8
00024899  48 83 f8 1f  cmp rax, 0x1f
0002489d  76 07  jbe 0x1800248a6
0002489f  ff 15 13 5f 01 00  call qword ptr [rip + 0x15f13]
000248a5  cc  int3 
000248a6  e8 89 08 01 00  call 0x180035134
000248ab  48 83 fb ff  cmp rbx, -1
000248af  0f 85 bc 01 00 00  jne 0x180024a71
000248b5  0f 57 c0  xorps xmm0, xmm0
000248b8  0f 11 45 c8  movups xmmword ptr [rbp - 0x38], xmm0
000248bc  0f 57 c9  xorps xmm1, xmm1
000248bf  f3 0f 7f 4d d8  movdqu xmmword ptr [rbp - 0x28], xmm1
000248c4  48 8d 85 b0 00 00 00  lea rax, [rbp + 0xb0]
000248cb  0f 1f 44 00 00  nop dword ptr [rax + rax]
000248d0  48 ff c6  inc rsi
000248d3  80 3c 30 00  cmp byte ptr [rax + rsi], 0
000248d7  75 f7  jne 0x1800248d0
000248d9  4c 8b c6  mov r8, rsi
000248dc  48 8d 95 b0 00 00 00  lea rdx, [rbp + 0xb0]
000248e3  48 8d 4d c8  lea rcx, [rbp - 0x38]
000248e7  e8 a4 25 fe ff  call 0x180006e90
000248ec  90  nop 
000248ed  41 b8 01 00 00 00  mov r8d, 1
000248f3  48 8d 15 5a c1 01 00  lea rdx, [rip + 0x1c15a]
000248fa  48 8d 4d c8  lea rcx, [rbp - 0x38]
000248fe  e8 3d 05 00 00  call 0x180024e40
00024903  0f 57 c0  xorps xmm0, xmm0
00024906  0f 11 45 a8  movups xmmword ptr [rbp - 0x58], xmm0
0002490a  0f 57 c9  xorps xmm1, xmm1
0002490d  f3 0f 7f 4d b8  movdqu xmmword ptr [rbp - 0x48], xmm1
00024912  0f 10 00  movups xmm0, xmmword ptr [rax]
00024915  0f 11 45 a8  movups xmmword ptr [rbp - 0x58], xmm0
00024919  0f 10 48 10  movups xmm1, xmmword ptr [rax + 0x10]
0002491d  0f 11 4d b8  movups xmmword ptr [rbp - 0x48], xmm1
00024921  4c 89 60 10  mov qword ptr [rax + 0x10], r12
00024925  48 c7 40 18 0f 00 00 00  mov qword ptr [rax + 0x18], 0xf
0002492d  c6 00 00  mov byte ptr [rax], 0
00024930  4d 8b c6  mov r8, r14
00024933  48 8d 55 a8  lea rdx, [rbp - 0x58]
00024937  48 8d 8d 88 00 00 00  lea rcx, [rbp + 0x88]
0002493e  e8 7d a9 ff ff  call 0x18001f2c0
00024943  48 8b d8  mov rbx, rax
00024946  48 8d 45 48  lea rax, [rbp + 0x48]
0002494a  48 3b c3  cmp rax, rbx
0002494d  74 6d  je 0x1800249bc
0002494f  48 8b 55 60  mov rdx, qword ptr [rbp + 0x60]
00024953  48 83 fa 10  cmp rdx, 0x10
00024957  72 34  jb 0x18002498d
00024959  48 ff c2  inc rdx
0002495c  48 8b 4d 48  mov rcx, qword ptr [rbp + 0x48]
00024960  48 8b c1  mov rax, rcx
00024963  48 81 fa 00 10 00 00  cmp rdx, 0x1000
0002496a  72 1c  jb 0x180024988
0002496c  48 83 c2 27  add rdx, 0x27
00024970  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024974  48 2b c1  sub rax, rcx
00024977  48 83 c0 f8  add rax, -8
0002497b  48 83 f8 1f  cmp rax, 0x1f
0002497f  76 07  jbe 0x180024988
00024981  ff 15 31 5e 01 00  call qword ptr [rip + 0x15e31]
00024987  cc  int3 
00024988  e8 a7 07 01 00  call 0x180035134
0002498d  66 0f 6f 05 db d5 01 00  movdqa xmm0, xmmword ptr [rip + 0x1d5db]
00024995  f3 0f 7f 45 58  movdqu xmmword ptr [rbp + 0x58], xmm0
0002499a  c6 45 48 00  mov byte ptr [rbp + 0x48], 0
0002499e  0f 10 03  movups xmm0, xmmword ptr [rbx]
000249a1  0f 11 45 48  movups xmmword ptr [rbp + 0x48], xmm0
000249a5  0f 10 4b 10  movups xmm1, xmmword ptr [rbx + 0x10]
000249a9  0f 11 4d 58  movups xmmword ptr [rbp + 0x58], xmm1
000249ad  4c 89 63 10  mov qword ptr [rbx + 0x10], r12
000249b1  48 c7 43 18 0f 00 00 00  mov qword ptr [rbx + 0x18], 0xf
000249b9  c6 03 00  mov byte ptr [rbx], 0
000249bc  48 8d 8d 88 00 00 00  lea rcx, [rbp + 0x88]
000249c3  e8 c8 40 fe ff  call 0x180008a90
000249c8  90  nop 
000249c9  48 8b 55 c0  mov rdx, qword ptr [rbp - 0x40]
000249cd  48 83 fa 10  cmp rdx, 0x10
000249d1  72 34  jb 0x180024a07
000249d3  48 ff c2  inc rdx
000249d6  48 8b 4d a8  mov rcx, qword ptr [rbp - 0x58]
000249da  48 8b c1  mov rax, rcx
000249dd  48 81 fa 00 10 00 00  cmp rdx, 0x1000
000249e4  72 1c  jb 0x180024a02
000249e6  48 83 c2 27  add rdx, 0x27
000249ea  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
000249ee  48 2b c1  sub rax, rcx
000249f1  48 83 c0 f8  add rax, -8
000249f5  48 83 f8 1f  cmp rax, 0x1f
000249f9  76 07  jbe 0x180024a02
000249fb  ff 15 b7 5d 01 00  call qword ptr [rip + 0x15db7]
00024a01  cc  int3 
00024a02  e8 2d 07 01 00  call 0x180035134
00024a07  66 0f 6f 05 61 d5 01 00  movdqa xmm0, xmmword ptr [rip + 0x1d561]
00024a0f  f3 0f 7f 45 b8  movdqu xmmword ptr [rbp - 0x48], xmm0
00024a14  c6 45 a8 00  mov byte ptr [rbp - 0x58], 0
00024a18  48 8b 55 e0  mov rdx, qword ptr [rbp - 0x20]
00024a1c  48 83 fa 10  cmp rdx, 0x10
00024a20  72 34  jb 0x180024a56
00024a22  48 ff c2  inc rdx
00024a25  48 8b 4d c8  mov rcx, qword ptr [rbp - 0x38]
00024a29  48 8b c1  mov rax, rcx
00024a2c  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024a33  72 1c  jb 0x180024a51
00024a35  48 83 c2 27  add rdx, 0x27
00024a39  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024a3d  48 2b c1  sub rax, rcx
00024a40  48 83 c0 f8  add rax, -8
00024a44  48 83 f8 1f  cmp rax, 0x1f
00024a48  76 07  jbe 0x180024a51
00024a4a  ff 15 68 5d 01 00  call qword ptr [rip + 0x15d68]
00024a50  cc  int3 
00024a51  e8 de 06 01 00  call 0x180035134
00024a56  48 8d 55 48  lea rdx, [rbp + 0x48]
00024a5a  48 83 7d 60 10  cmp qword ptr [rbp + 0x60], 0x10
00024a5f  48 0f 43 55 48  cmovae rdx, qword ptr [rbp + 0x48]
00024a64  48 8d 0d 51 d7 01 00  lea rcx, [rip + 0x1d751]
00024a6b  ff 15 af 58 01 00  call qword ptr [rip + 0x158af]
00024a71  49 8b ce  mov rcx, r14
00024a74  e8 19 05 01 00  call 0x180034f92
00024a79  90  nop 
00024a7a  48 8b 55 80  mov rdx, qword ptr [rbp - 0x80]
00024a7e  48 83 fa 10  cmp rdx, 0x10
00024a82  72 35  jb 0x180024ab9
00024a84  48 ff c2  inc rdx
00024a87  48 8b 4c 24 68  mov rcx, qword ptr [rsp + 0x68]
00024a8c  48 8b c1  mov rax, rcx
00024a8f  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024a96  72 1c  jb 0x180024ab4
00024a98  48 83 c2 27  add rdx, 0x27
00024a9c  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024aa0  48 2b c1  sub rax, rcx
00024aa3  48 83 c0 f8  add rax, -8
00024aa7  48 83 f8 1f  cmp rax, 0x1f
00024aab  76 07  jbe 0x180024ab4
00024aad  ff 15 05 5d 01 00  call qword ptr [rip + 0x15d05]
00024ab3  cc  int3 
00024ab4  e8 7b 06 01 00  call 0x180035134
00024ab9  66 0f 6f 05 af d4 01 00  movdqa xmm0, xmmword ptr [rip + 0x1d4af]
00024ac1  f3 0f 7f 44 24 78  movdqu xmmword ptr [rsp + 0x78], xmm0
00024ac7  c6 44 24 68 00  mov byte ptr [rsp + 0x68], 0
00024acc  48 8b 55 60  mov rdx, qword ptr [rbp + 0x60]
00024ad0  48 83 fa 10  cmp rdx, 0x10
00024ad4  72 34  jb 0x180024b0a
00024ad6  48 ff c2  inc rdx
00024ad9  48 8b 4d 48  mov rcx, qword ptr [rbp + 0x48]
00024add  48 8b c1  mov rax, rcx
00024ae0  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024ae7  72 1c  jb 0x180024b05
00024ae9  48 83 c2 27  add rdx, 0x27
00024aed  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024af1  48 2b c1  sub rax, rcx
00024af4  48 83 c0 f8  add rax, -8
00024af8  48 83 f8 1f  cmp rax, 0x1f
00024afc  76 07  jbe 0x180024b05
00024afe  ff 15 b4 5c 01 00  call qword ptr [rip + 0x15cb4]
00024b04  cc  int3 
00024b05  e8 2a 06 01 00  call 0x180035134
00024b0a  48 8b 4c 24 38  mov rcx, qword ptr [rsp + 0x38]
00024b0f  ff 15 33 55 01 00  call qword ptr [rip + 0x15533]
00024b15  90  nop 
00024b16  48 8b 55 a0  mov rdx, qword ptr [rbp - 0x60]
00024b1a  48 83 fa 10  cmp rdx, 0x10
00024b1e  72 34  jb 0x180024b54
00024b20  48 ff c2  inc rdx
00024b23  48 8b 4d 88  mov rcx, qword ptr [rbp - 0x78]
00024b27  48 8b c1  mov rax, rcx
00024b2a  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024b31  72 1c  jb 0x180024b4f
00024b33  48 83 c2 27  add rdx, 0x27
00024b37  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024b3b  48 2b c1  sub rax, rcx
00024b3e  48 83 c0 f8  add rax, -8
00024b42  48 83 f8 1f  cmp rax, 0x1f
00024b46  76 07  jbe 0x180024b4f
00024b48  ff 15 6a 5c 01 00  call qword ptr [rip + 0x15c6a]
00024b4e  cc  int3 
00024b4f  e8 e0 05 01 00  call 0x180035134
00024b54  66 0f 6f 05 14 d4 01 00  movdqa xmm0, xmmword ptr [rip + 0x1d414]
00024b5c  f3 0f 7f 45 98  movdqu xmmword ptr [rbp - 0x68], xmm0
00024b61  c6 45 88 00  mov byte ptr [rbp - 0x78], 0
00024b65  48 8b 55 00  mov rdx, qword ptr [rbp]
00024b69  48 83 fa 10  cmp rdx, 0x10
00024b6d  72 34  jb 0x180024ba3
00024b6f  48 ff c2  inc rdx
00024b72  48 8b 4d e8  mov rcx, qword ptr [rbp - 0x18]
00024b76  48 8b c1  mov rax, rcx
00024b79  48 81 fa 00 10 00 00  cmp rdx, 0x1000
00024b80  72 1c  jb 0x180024b9e
00024b82  48 83 c2 27  add rdx, 0x27
00024b86  48 8b 49 f8  mov rcx, qword ptr [rcx - 8]
00024b8a  48 2b c1  sub rax, rcx
00024b8d  48 83 c0 f8  add rax, -8
00024b91  48 83 f8 1f  cmp rax, 0x1f
00024b95  76 07  jbe 0x180024b9e
00024b97  ff 15 1b 5c 01 00  call qword ptr [rip + 0x15c1b]
00024b9d  cc  int3 
00024b9e  e8 91 05 01 00  call 0x180035134
00024ba3  e8 28 f0 00 00  call 0x180033bd0
00024ba8  83 f8 02  cmp eax, 2
00024bab  48 8d 0d 66 d6 01 00  lea rcx, [rip + 0x1d666]
00024bb2  74 07  je 0x180024bbb
00024bb4  48 8d 0d 6d d6 01 00  lea rcx, [rip + 0x1d66d]
00024bbb  ff 15 f7 e5 02 00  call qword ptr [rip + 0x2e5f7]
00024bc1  0f 57 c0  xorps xmm0, xmm0
00024bc4  33 c0  xor eax, eax
00024bc6  41 0f 11 45 24  movups xmmword ptr [r13 + 0x24], xmm0
00024bcb  41 0f 11 45 34  movups xmmword ptr [r13 + 0x34], xmm0
00024bd0  41 0f 11 45 44  movups xmmword ptr [r13 + 0x44], xmm0
00024bd5  41 0f 11 45 54  movups xmmword ptr [r13 + 0x54], xmm0
00024bda  41 0f 11 45 64  movups xmmword ptr [r13 + 0x64], xmm0
00024bdf  41 0f 11 45 74  movups xmmword ptr [r13 + 0x74], xmm0
00024be4  41 0f 11 85 84 00 00 00  movups xmmword ptr [r13 + 0x84], xmm0
00024bec  41 0f 11 85 94 00 00 00  movups xmmword ptr [r13 + 0x94], xmm0
00024bf4  41 0f 11 85 a4 00 00 00  movups xmmword ptr [r13 + 0xa4], xmm0
00024bfc  49 89 85 b4 00 00 00  mov qword ptr [r13 + 0xb4], rax
00024c03  41 c7 45 20 9c 00 00 00  mov dword ptr [r13 + 0x20], 0x9c
00024c0b  49 8d 4d 20  lea rcx, [r13 + 0x20]
00024c0f  ff 15 f3 55 01 00  call qword ptr [rip + 0x155f3]
00024c15  85 c0  test eax, eax
00024c17  75 12  jne 0x180024c2b
00024c19  41 c7 45 20 94 00 00 00  mov dword ptr [r13 + 0x20], 0x94
00024c21  49 8d 4d 20  lea rcx, [r13 + 0x20]
00024c25  ff 15 dd 55 01 00  call qword ptr [rip + 0x155dd]
00024c2b  41 b8 01 00 00 00  mov r8d, 1
00024c31  49 8d 55 20  lea rdx, [r13 + 0x20]
00024c35  48 8d 0d f4 d5 01 00  lea rcx, [rip + 0x1d5f4]
00024c3c  e8 de f3 00 00  call 0x18003401f
00024c41  49 8b cd  mov rcx, r13
00024c44  e8 77 c3 ff ff  call 0x180020fc0
00024c49  84 c0  test al, al
00024c4b  0f 95 c0  setne al
00024c4e  48 8b 8d c0 02 00 00  mov rcx, qword ptr [rbp + 0x2c0]
00024c55  48 33 cc  xor rcx, rsp
00024c58  e8 d3 09 01 00  call 0x180035630
00024c5d  4c 8d 9c 24 f0 03 00 00  lea r11, [rsp + 0x3f0]
00024c65  49 8b 5b 38  mov rbx, qword ptr [r11 + 0x38]
00024c69  49 8b 73 40  mov rsi, qword ptr [r11 + 0x40]
00024c6d  49 8b 7b 48  mov rdi, qword ptr [r11 + 0x48]
00024c71  41 0f 28 73 f0  movaps xmm6, xmmword ptr [r11 - 0x10]
00024c76  41 0f 28 7b e0  movaps xmm7, xmmword ptr [r11 - 0x20]
00024c7b  49 8b e3  mov rsp, r11
00024c7e  41 5f  pop r15
00024c80  41 5e  pop r14
00024c82  41 5d  pop r13
00024c84  41 5c  pop r12
00024c86  5d  pop rbp
00024c87  c3  ret 
00024c88  e8 23 85 ff ff  call 0x18001d1b0
00024c8d  90  nop 
; RVA 0x33bb0
00033bb0  48 8d 05 09 ee 00 00  lea rax, [rip + 0xee09]
00033bb7  c3  ret 
; RVA 0x33bc0
00033bc0  48 8d 05 9d e8 00 00  lea rax, [rip + 0xe89d]
00033bc7  c3  ret 
; RVA 0x33bd0
00033bd0  8b 05 7a ec 01 00  mov eax, dword ptr [rip + 0x1ec7a]
00033bd6  c3  ret 
; RVA 0x33c00
00033c00  48 8d 05 35 71 00 00  lea rax, [rip + 0x7135]
00033c07  c3  ret 
; RVA 0x360a8
000360a8  48 8d 05 01 e7 01 00  lea rax, [rip + 0x1e701]
000360af  c3  ret 
; RVA 0x360cc
000360cc  48 8d 05 9d e7 01 00  lea rax, [rip + 0x1e79d]
000360d3  c3  ret 
; Indirect call in runtime range 0x11f0
0000126e  ff 50 38  call qword ptr [rax + 0x38]
; Indirect call in runtime range 0x15ab
000015e2  ff d0  call rax
; Indirect call in runtime range 0x15ab
000015e6  ff d3  call rbx
; Indirect call in runtime range 0x15ab
000015ea  ff d7  call rdi
; Indirect call in runtime range 0x18f0
0000195f  ff d0  call rax
; Indirect call in runtime range 0x1a30
00001abe  41 ff d2  call r10
; Indirect call in runtime range 0x1dd0
00001df4  ff 50 10  call qword ptr [rax + 0x10]
; Indirect call in runtime range 0x1dd0
00001e06  ff 50 10  call qword ptr [rax + 0x10]
