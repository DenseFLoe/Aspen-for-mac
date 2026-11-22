0x11f0  4053                    push rbx
0x11f2  4883ec20                sub rsp, 0x20
0x11f6  488d05e32e0500          lea rax, [rip + 0x52ee3]
0x11fd  4533c0                  xor r8d, r8d
0x1200  33d2                    xor edx, edx
0x1202  488905c7220500          mov qword ptr [rip + 0x522c7], rax
0x1209  488d0de82e0500          lea rcx, [rip + 0x52ee8]
0x1210  ff15b2900300            call qword ptr [rip + 0x390b2]
0x1216  85c0                    test eax, eax
0x1218  751f                    jne 0x1239
0x121a  ff1530910300            call qword ptr [rip + 0x39130]
0x1220  85c0                    test eax, eax
0x1222  7e0a                    jle 0x122e
0x1224  0fb7c0                  movzx eax, ax
0x1227  0d00000780              or eax, 0x80070000
0x122c  85c0                    test eax, eax
0x122e  7909                    jns 0x1239
0x1230  c6057922050001          mov byte ptr [rip + 0x52279], 1
0x1237  eb0a                    jmp 0x1243
0x1239  c705a52e050038000000    mov dword ptr [rip + 0x52ea5], 0x38
0x1243  0f10057e170400          movups xmm0, xmmword ptr [rip + 0x4177e]
0x124a  488b1d5f150500          mov rbx, qword ptr [rip + 0x5155f]
0x1251  488b0d60150500          mov rcx, qword ptr [rip + 0x51560]
0x1258  0f1105712e0500          movups xmmword ptr [rip + 0x52e71], xmm0
0x125f  483bd9                  cmp rbx, rcx
0x1262  731d                    jae 0x1281
0x1264  488b03                  mov rax, qword ptr [rbx]
0x1267  4885c0                  test rax, rax
0x126a  740c                    je 0x1278
0x126c  b101                    mov cl, 1
0x126e  ff5038                  call qword ptr [rax + 0x38]
0x1271  488b0d40150500          mov rcx, qword ptr [rip + 0x51540]
0x1278  4883c308                add rbx, 8
0x127c  483bd9                  cmp rbx, rcx
0x127f  72e3                    jb 0x1264
0x1281  488d0508170400          lea rax, [rip + 0x41708]
0x1288  488d0d31850300          lea rcx, [rip + 0x38531]
0x128f  4889054a2e0500          mov qword ptr [rip + 0x52e4a], rax
0x1296  4883c420                add rsp, 0x20
0x129a  5b                      pop rbx
0x129b  e904420300              jmp 0x354a4
0x1570  48895c2410              mov qword ptr [rsp + 0x10], rbx
0x1575  56                      push rsi
0x1576  4881ec20040000          sub rsp, 0x420
0x157d  488b0504130500          mov rax, qword ptr [rip + 0x51304]
0x1584  4833c4                  xor rax, rsp
0x1587  4889842410040000        mov qword ptr [rsp + 0x410], rax
0x158f  488d0d8af30300          lea rcx, [rip + 0x3f38a]
0x1596  ff156c8d0300            call qword ptr [rip + 0x38d6c]
0x159c  488bf0                  mov rsi, rax
0x159f  4885c0                  test rax, rax
0x15a2  7452                    je 0x15f6
0x15a4  488d1585f30300          lea rdx, [rip + 0x3f385]
0x15ab  4889bc2430040000        mov qword ptr [rsp + 0x430], rdi
0x15b3  488bc8                  mov rcx, rax
0x15b6  ff15448d0300            call qword ptr [rip + 0x38d44]
0x15bc  488d1585f30300          lea rdx, [rip + 0x3f385]
0x15c3  488bce                  mov rcx, rsi
0x15c6  488bf8                  mov rdi, rax
0x15c9  ff15318d0300            call qword ptr [rip + 0x38d31]
0x15cf  488d1582f30300          lea rdx, [rip + 0x3f382]
0x15d6  488bce                  mov rcx, rsi
0x15d9  488bd8                  mov rbx, rax
0x15dc  ff151e8d0300            call qword ptr [rip + 0x38d1e]
0x15e2  ffd0                    call rax
0x15e4  8bf0                    mov esi, eax
0x15e6  ffd3                    call rbx
0x15e8  8bd8                    mov ebx, eax
0x15ea  ffd7                    call rdi
0x15ec  488bbc2430040000        mov rdi, qword ptr [rsp + 0x430]
0x15f4  eb3e                    jmp 0x1634
0x15f6  41b90b070000            mov r9d, 0x70b
0x15fc  4c8d0565f30300          lea r8, [rip + 0x3f365]
0x1603  488d1596f30300          lea rdx, [rip + 0x3f396]
0x160a  488d4c2420              lea rcx, [rsp + 0x20]
0x160f  e8cc060000              call 0x1ce0
0x1614  ba02000000              mov edx, 2
0x1619  488d4c2420              lea rcx, [rsp + 0x20]
0x161e  448d42ff                lea r8d, [rdx - 1]
0x1622  ff15888f0300            call qword ptr [rip + 0x38f88]
0x1628  33f6                    xor esi, esi
0x162a  b801000000              mov eax, 1
0x162f  bb29000000              mov ebx, 0x29
0x1634  c705b21e050001000000    mov dword ptr [rip + 0x51eb2], 1
0x163e  890554110500            mov dword ptr [rip + 0x51154], eax
0x1644  891d52110500            mov dword ptr [rip + 0x51152], ebx
0x164a  8935a41e0500            mov dword ptr [rip + 0x51ea4], esi
0x1650  488b8c2410040000        mov rcx, qword ptr [rsp + 0x410]
0x1658  4833cc                  xor rcx, rsp
0x165b  e8d03f0300              call 0x35630
0x1660  488b9c2438040000        mov rbx, qword ptr [rsp + 0x438]
0x1668  4881c420040000          add rsp, 0x420
0x166f  5e                      pop rsi
0x1670  c3                      ret
