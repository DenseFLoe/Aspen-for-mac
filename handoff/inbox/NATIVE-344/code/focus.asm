; begin RVA 0x1360
00001360  b8 01 00 00 00  mov eax, 1
00001365  c3  ret 
; begin RVA 0x19e0
000019e0  33 c0  xor eax, eax
000019e2  c3  ret 
; begin RVA 0x1b20
00001b20  48 8d 05 f1 ff 04 00  lea rax, [rip + 0x4fff1]
00001b27  c3  ret 
; begin RVA 0x1b30
00001b30  48 8d 05 e9 ff 04 00  lea rax, [rip + 0x4ffe9]
00001b37  c3  ret 
; begin RVA 0x63a0
000063a0  0f b6 c1  movzx eax, cl
000063a3  89 05 37 aa 04 00  mov dword ptr [rip + 0x4aa37], eax
000063a9  c3  ret 
; begin RVA 0x8b40
00008b40  8b 05 7a 90 04 00  mov eax, dword ptr [rip + 0x4907a]
00008b46  89 0d 74 90 04 00  mov dword ptr [rip + 0x49074], ecx
00008b4c  c3  ret 
; begin RVA 0x9fe0
00009fe0  48 8d 05 11 62 03 00  lea rax, [rip + 0x36211]
00009fe7  c3  ret 
; begin RVA 0x9ff0
00009ff0  48 8d 05 d9 63 03 00  lea rax, [rip + 0x363d9]
00009ff7  c3  ret 
; begin RVA 0xc510
0000c510  48 8b 05 09 57 04 00  mov rax, qword ptr [rip + 0x45709]
0000c517  c3  ret 
; begin RVA 0xc730
0000c730  88 0d e7 54 04 00  mov byte ptr [rip + 0x454e7], cl
0000c736  c3  ret 
; begin RVA 0xc740
0000c740  88 0d d6 54 04 00  mov byte ptr [rip + 0x454d6], cl
0000c746  c3  ret 
; begin RVA 0xf570
0000f570  8b 05 5a 28 04 00  mov eax, dword ptr [rip + 0x4285a]
0000f576  c3  ret 
; begin RVA 0xfd20
0000fd20  8b 05 f2 1e 04 00  mov eax, dword ptr [rip + 0x41ef2]
0000fd26  c3  ret 
; begin RVA 0xfd60
0000fd60  8b 05 ba f9 03 00  mov eax, dword ptr [rip + 0x3f9ba]
0000fd66  c3  ret 
; begin RVA 0x109c0
000109c0  48 83 ec 28  sub rsp, 0x28
000109c4  33 c9  xor ecx, ecx
000109c6  c7 05 30 12 04 00 01 00 00 00  mov dword ptr [rip + 0x41230], 1
000109d0  e8 6b 0b 02 00  call 0x180031540
000109d5  ba 01 00 00 00  mov edx, 1
000109da  45 33 c9  xor r9d, r9d
000109dd  8b ca  mov ecx, edx
000109df  45 33 c0  xor r8d, r8d
000109e2  e8 69 20 01 00  call 0x180022a50
000109e7  85 c0  test eax, eax
000109e9  75 1d  jne 0x180010a08
000109eb  e8 42 a3 02 00  call 0x18003ad32
000109f0  33 d2  xor edx, edx
000109f2  8d 4a 09  lea ecx, [rdx + 9]
000109f5  e8 16 50 00 00  call 0x180015a10
000109fa  33 c9  xor ecx, ecx
000109fc  85 c0  test eax, eax
000109fe  0f 94 c1  sete cl
00010a01  8b c1  mov eax, ecx
00010a03  48 83 c4 28  add rsp, 0x28
00010a07  c3  ret 
00010a08  33 c0  xor eax, eax
00010a0a  48 83 c4 28  add rsp, 0x28
00010a0e  c3  ret 
; begin RVA 0x14f90
00014f90  48 8b 41 18  mov rax, qword ptr [rcx + 0x18]
00014f94  c3  ret 
; begin RVA 0x14fa0
00014fa0  48 8d 05 d1 b9 03 00  lea rax, [rip + 0x3b9d1]
00014fa7  c3  ret 
; begin RVA 0x14fb0
00014fb0  48 8d 05 f1 b9 03 00  lea rax, [rip + 0x3b9f1]
00014fb7  c3  ret 
; begin RVA 0x19fd0
00019fd0  48 8b 05 39 4b 02 00  mov rax, qword ptr [rip + 0x24b39]
00019fd7  c3  ret 
; begin RVA 0x22a50
00022a50  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00022a55  48 89 6c 24 10  mov qword ptr [rsp + 0x10], rbp
00022a5a  48 89 74 24 18  mov qword ptr [rsp + 0x18], rsi
00022a5f  57  push rdi
00022a60  48 83 ec 20  sub rsp, 0x20
00022a64  33 db  xor ebx, ebx
00022a66  49 8b e9  mov rbp, r9
00022a69  ff c9  dec ecx
00022a6b  41 8b f0  mov esi, r8d
00022a6e  8b fa  mov edi, edx
00022a70  83 f9 12  cmp ecx, 0x12
00022a73  0f 87 b9 00 00 00  ja 0x180022b32
00022a79  48 63 c1  movsxd rax, ecx
00022a7c  48 8d 15 7d d5 fd ff  lea rdx, [rip - 0x22a83]
00022a83  8b 8c 82 4c 2b 02 00  mov ecx, dword ptr [rdx + rax*4 + 0x22b4c]
00022a8a  48 03 ca  add rcx, rdx
00022a8d  ff e1  jmp rcx
00022a8f  8b cf  mov ecx, edi
00022a91  e8 1a e6 ff ff  call 0x1800210b0
00022a96  e9 95 00 00 00  jmp 0x180022b30
00022a9b  8b d6  mov edx, esi
00022a9d  8b cf  mov ecx, edi
00022a9f  e8 6c e3 ff ff  call 0x180020e10
00022aa4  e9 87 00 00 00  jmp 0x180022b30
00022aa9  41 b8 01 00 00 00  mov r8d, 1
00022aaf  8b d6  mov edx, esi
00022ab1  8b cf  mov ecx, edi
00022ab3  e8 b8 f3 ff ff  call 0x180021e70
00022ab8  eb 76  jmp 0x180022b30
00022aba  8b d6  mov edx, esi
00022abc  8b cf  mov ecx, edi
00022abe  e8 1d e0 ff ff  call 0x180020ae0
00022ac3  eb 6b  jmp 0x180022b30
00022ac5  8b cf  mov ecx, edi
00022ac7  e8 a4 e1 ff ff  call 0x180020c70
00022acc  eb 62  jmp 0x180022b30
00022ace  33 d2  xor edx, edx
00022ad0  48 8d 0d 21 ec 01 00  lea rcx, [rip + 0x1ec21]
00022ad7  e8 6c 81 01 00  call 0x18003ac48
00022adc  48 85 c0  test rax, rax
00022adf  74 0b  je 0x180022aec
00022ae1  39 18  cmp dword ptr [rax], ebx
00022ae3  74 07  je 0x180022aec
00022ae5  e8 c4 87 01 00  call 0x18003b2ae
00022aea  eb 46  jmp 0x180022b32
00022aec  4c 8b c5  mov r8, rbp
00022aef  8b d6  mov edx, esi
00022af1  8b cf  mov ecx, edi
00022af3  e8 88 f0 ff ff  call 0x180021b80
00022af8  eb 36  jmp 0x180022b30
00022afa  8b d6  mov edx, esi
00022afc  8b cf  mov ecx, edi
00022afe  e8 ed ed ff ff  call 0x1800218f0
00022b03  eb 2b  jmp 0x180022b30
00022b05  8b d6  mov edx, esi
00022b07  8b cf  mov ecx, edi
00022b09  e8 f2 ea ff ff  call 0x180021600
00022b0e  eb 20  jmp 0x180022b30
00022b10  8b d6  mov edx, esi
00022b12  8b cf  mov ecx, edi
00022b14  e8 87 f4 ff ff  call 0x180021fa0
00022b19  eb 15  jmp 0x180022b30
00022b1b  8b d6  mov edx, esi
00022b1d  8b cf  mov ecx, edi
00022b1f  e8 ec df ff ff  call 0x180020b10
00022b24  eb 0a  jmp 0x180022b30
00022b26  48 8b d5  mov rdx, rbp
00022b29  8b ce  mov ecx, esi
00022b2b  e8 30 f5 ff ff  call 0x180022060
00022b30  8b d8  mov ebx, eax
00022b32  48 8b 6c 24 38  mov rbp, qword ptr [rsp + 0x38]
00022b37  8b c3  mov eax, ebx
00022b39  48 8b 5c 24 30  mov rbx, qword ptr [rsp + 0x30]
00022b3e  48 8b 74 24 40  mov rsi, qword ptr [rsp + 0x40]
00022b43  48 83 c4 20  add rsp, 0x20
00022b47  5f  pop rdi
00022b48  c3  ret 
; begin RVA 0x39c00
00039c00  48 89 5c 24 08  mov qword ptr [rsp + 8], rbx
00039c05  48 89 6c 24 10  mov qword ptr [rsp + 0x10], rbp
00039c0a  48 89 74 24 18  mov qword ptr [rsp + 0x18], rsi
00039c0f  57  push rdi
00039c10  41 56  push r14
00039c12  41 57  push r15
00039c14  48 83 ec 20  sub rsp, 0x20
00039c18  e8 b3 15 00 00  call 0x18003b1d0
00039c1d  48 8b 05 14 55 00 00  mov rax, qword ptr [rip + 0x5514]
00039c24  41 be 01 00 00 00  mov r14d, 1
00039c2a  44 89 30  mov dword ptr [rax], r14d
00039c2d  48 8b 05 8c 53 00 00  mov rax, qword ptr [rip + 0x538c]
00039c34  48 8b 08  mov rcx, qword ptr [rax]
00039c37  83 b9 5c 01 00 00 00  cmp dword ptr [rcx + 0x15c], 0
00039c3e  44 8b b9 80 03 00 00  mov r15d, dword ptr [rcx + 0x380]
00039c45  75 0c  jne 0x180039c53
00039c47  e8 7a 10 00 00  call 0x18003acc6
00039c4c  85 c0  test eax, eax
00039c4e  74 03  je 0x180039c53
00039c50  45 33 f6  xor r14d, r14d
00039c53  48 8b 05 66 53 00 00  mov rax, qword ptr [rip + 0x5366]
00039c5a  48 8b 10  mov rdx, qword ptr [rax]
00039c5d  8b 9a 5c 01 00 00  mov ebx, dword ptr [rdx + 0x15c]
00039c63  8b ba 08 07 00 00  mov edi, dword ptr [rdx + 0x708]
00039c69  8b aa 50 01 00 00  mov ebp, dword ptr [rdx + 0x150]
00039c6f  c7 82 80 03 00 00 d9 02 00 00  mov dword ptr [rdx + 0x380], 0x2d9
00039c79  e8 42 6d fd ff  call 0x1800109c0
00039c7e  48 8b 15 3b 53 00 00  mov rdx, qword ptr [rip + 0x533b]
00039c85  41 8b ce  mov ecx, r14d
00039c88  8b f0  mov esi, eax
00039c8a  4c 8b 02  mov r8, qword ptr [rdx]
00039c8d  45 89 b8 80 03 00 00  mov dword ptr [r8 + 0x380], r15d
00039c94  e8 29 11 00 00  call 0x18003adc2
00039c99  48 8b 15 20 53 00 00  mov rdx, qword ptr [rip + 0x5320]
00039ca0  8b cf  mov ecx, edi
00039ca2  4c 8b 02  mov r8, qword ptr [rdx]
00039ca5  41 89 98 5c 01 00 00  mov dword ptr [r8 + 0x15c], ebx
00039cac  e8 79 12 00 00  call 0x18003af2a
00039cb1  8b cd  mov ecx, ebp
00039cb3  e8 2c 13 00 00  call 0x18003afe4
00039cb8  48 8b 5c 24 40  mov rbx, qword ptr [rsp + 0x40]
00039cbd  8b c6  mov eax, esi
00039cbf  48 8b 74 24 50  mov rsi, qword ptr [rsp + 0x50]
00039cc4  48 8b 6c 24 48  mov rbp, qword ptr [rsp + 0x48]
00039cc9  48 83 c4 20  add rsp, 0x20
00039ccd  41 5f  pop r15
00039ccf  41 5e  pop r14
00039cd1  5f  pop rdi
00039cd2  c3  ret 
; begin RVA 0x3c674
0003c674  48 8d 05 3d 72 01 00  lea rax, [rip + 0x1723d]
0003c67b  c3  ret 
