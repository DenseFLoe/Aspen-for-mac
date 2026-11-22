; Windows AMD64 original instruction bytes. Addresses are image RVAs.
000180e4  ff 25 be 10 00 00  jmp qword ptr [191A8h]
000180ea  ff 25 c0 10 00 00  jmp qword ptr [191B0h]
000180f0  ff 25 a2 10 00 00  jmp qword ptr [19198h]
000180f6  ff 25 94 10 00 00  jmp qword ptr [19190h]
00018110  48 3b 0d a9 a0 00 00  cmp rcx,[221C0h]
00018130  40 53  push rbx
0001813b  ff 15 2f 0f 00 00  call qword ptr [19070h]
00018144  ff 15 1e 0f 00 00  call qword ptr [19068h]
0001814a  ff 15 b8 0e 00 00  call qword ptr [19008h]
0001815d  48 ff 25 9c 0e 00 00  jmp qword ptr [19000h]
00018164  48 89 4c 24 08  mov [rsp+8],rcx
00018172  ff 15 08 0f 00 00  call qword ptr [19080h]
00018183  48 8d 0d 86 bb 00 00  lea rcx,[23D10h]
00018194  48 89 05 6d bc 00 00  mov [23E08h],rax
000181a4  48 89 05 fd bb 00 00  mov [23DA8h],rax
000181ab  48 8b 05 56 bc 00 00  mov rax,[23E08h]
000181b2  48 89 05 c7 ba 00 00  mov [23C80h],rax
000181be  48 89 05 cb bb 00 00  mov [23D90h],rax
000181c5  c7 05 a1 ba 00 00 09 04 00 c0  mov dword ptr [23C70h],0C0000409h
000181cf  c7 05 9b ba 00 00 01 00 00 00  mov dword ptr [23C74h],1
000181d9  c7 05 a5 ba 00 00 01 00 00 00  mov dword ptr [23C88h],1
000181ec  48 8d 0d 9d ba 00 00  lea rcx,[23C90h]
00018204  48 8b 0d b5 9f 00 00  mov rcx,[221C0h]
00018219  48 8b 0d e0 9f 00 00  mov rcx,[22200h]
00018225  48 8d 0d 7c 36 00 00  lea rcx,[1B8A8h]
00018238  48 83 ec 28  sub rsp,28h
0001824c  89 4c 24 08  mov [rsp+8],ecx
00018259  ff 15 21 0e 00 00  call qword ptr [19080h]
0001826b  48 8d 0d 9e ba 00 00  lea rcx,[23D10h]
0001827c  48 89 05 85 bb 00 00  mov [23E08h],rax
0001828c  48 89 05 15 bb 00 00  mov [23DA8h],rax
00018293  48 8b 05 6e bb 00 00  mov rax,[23E08h]
0001829a  48 89 05 df b9 00 00  mov [23C80h],rax
000182a1  c7 05 c5 b9 00 00 09 04 00 c0  mov dword ptr [23C70h],0C0000409h
000182ab  c7 05 bf b9 00 00 01 00 00 00  mov dword ptr [23C74h],1
000182b5  c7 05 c9 b9 00 00 01 00 00 00  mov dword ptr [23C88h],1
000182c8  48 8d 0d c1 b9 00 00  lea rcx,[23C90h]
000182d7  48 8d 0d ca 35 00 00  lea rcx,[1B8A8h]
000182ec  4c 89 44 24 18  mov [rsp+18h],r8
00018302  ff 15 78 0d 00 00  call qword ptr [19080h]
00018314  48 8d 0d f5 b9 00 00  lea rcx,[23D10h]
00018325  48 89 05 dc ba 00 00  mov [23E08h],rax
00018335  48 89 05 6c ba 00 00  mov [23DA8h],rax
0001833c  48 8b 05 c5 ba 00 00  mov rax,[23E08h]
00018343  48 89 05 36 b9 00 00  mov [23C80h],rax
0001834a  c7 05 1c b9 00 00 09 04 00 c0  mov dword ptr [23C70h],0C0000409h
00018354  c7 05 16 b9 00 00 01 00 00 00  mov dword ptr [23C74h],1
0001838c  89 05 f6 b8 00 00  mov [23C88h],eax
0001839b  48 8d 0d ee b8 00 00  lea rcx,[23C90h]
000183d4  48 8d 15 b5 b8 00 00  lea rdx,[23C90h]
000183ea  48 8d 0d b7 34 00 00  lea rcx,[1B8A8h]
000183fc  48 89 5c 24 20  mov [rsp+20h],rbx
00018409  ff 15 39 0c 00 00  call qword ptr [19048h]
00018421  ff 15 29 0c 00 00  call qword ptr [19050h]
00018458  ff 15 fa 0b 00 00  call qword ptr [19058h]
0001846c  40 53  push rbx
00018477  ff 15 cb 0b 00 00  call qword ptr [19048h]
00018491  ff 15 b9 0b 00 00  call qword ptr [19050h]
000184c8  ff 15 8a 0b 00 00  call qword ptr [19058h]
000184dd  ff 25 25 0b 00 00  jmp qword ptr [19008h]
000184e3  ff 25 17 0b 00 00  jmp qword ptr [19000h]
000184ec  b0 01  mov al,1
000184f0  b0 01  mov al,1
000184f4  b0 01  mov al,1
000184f8  b0 01  mov al,1
000184fc  b0 01  mov al,1
00018500  33 c0  xor eax,eax
00018520  ff e0  jmp rax
00018540  ff 25 72 0f 00 00  jmp qword ptr [194B8h]
00018550  56  push rsi
00018564  4c 8b 05 55 9c 00 00  mov r8,[221C0h]
000185b0  56  push rsi
000185ca  48 8b 05 ef 9b 00 00  mov rax,[221C0h]
000185e3  e8 08 fb ff ff  call 00000000000180F0h
00018601  e8 f0 fa ff ff  call 00000000000180F6h
00018620  41 57  push r15
0001865e  e8 7b fa ff ff  call 00000000000180DEh
00018679  40 55  push rbp
00018690  40 55  push rbp
000186a9  40 55  push rbp
000186bd  40 55  push rbp
000186d4  4c 8d 0d 31 cd ff ff  lea r9,[1540Ch]
000186f3  40 55  push rbp
