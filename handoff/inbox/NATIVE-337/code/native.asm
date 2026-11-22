; NATIVE-337 native disassembly (IDA 9.5, imagebase 0x180000000)
; RVA  bytes  instruction

; FUNC 00001000-00001028 sub_180001000 (40 bytes)
00001000  48 83 EC 28  sub     rsp, 28h
00001004  48 8D 15 2D 67 00 00  lea     rdx, byte_180007738
0000100B  48 8D 0D 16 A7 00 00  lea     rcx, unk_18000B728
00001012  FF 15 A0 65 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(char const *)
00001018  48 8D 0D 11 52 00 00  lea     rcx, sub_180006230; void (__cdecl *)()
0000101F  48 83 C4 28  add     rsp, 28h
00001023  E9 F4 40 00 00  jmp     atexit

; FUNC 00001028-00001048 sub_180001028 (32 bytes)
00001028  48 83 EC 28  sub     rsp, 28h
0000102C  48 8D 0D 0D AD 00 00  lea     rcx, unk_18000BD40
00001033  E8 E8 4B 00 00  call    sub_180005C20
00001038  48 8D 0D 01 52 00 00  lea     rcx, sub_180006240; void (__cdecl *)()
0000103F  48 83 C4 28  add     rsp, 28h
00001043  E9 D4 40 00 00  jmp     atexit

; FUNC 00001050-0000105C sub_180001050 (12 bytes)
00001050  48 8D 0D F9 51 00 00  lea     rcx, sub_180006250; void (__cdecl *)()
00001057  E9 C0 40 00 00  jmp     atexit

; FUNC 00001060-00001078 sub_180001060 (24 bytes)
00001060  48 83 EC 28  sub     rsp, 28h
00001064  81 F9 0E 00 07 80  cmp     ecx, 8007000Eh
0000106A  75 06  jnz     short loc_180001072
0000106C  E8 32 3A 00 00  call    AfxThrowMemoryException(void)
00001071  CC  align 2
00001072  E8 32 3A 00 00  call    AfxThrowOleException(long)
00001077  CC  db 0CCh

; FUNC 00001080-00001087 InitializeCriticalSectionEx (7 bytes)
00001080  48 FF 25 A9 5F 00 00  jmp     cs:__imp_InitializeCriticalSectionEx; KERNEL32

; FUNC 00001090-00001093 _guard_check_icall_nop (3 bytes)
00001090  C2 00 00  retn    0

; FUNC 000010A0-000010A7 gxSetRefState (7 bytes)
000010A0  89 0D FE A4 00 00  mov     cs:dword_18000B5A4, ecx
000010A6  C3  retn

; FUNC 000010B0-000010E2 sub_1800010B0 (50 bytes)
000010B0  48 83 EC 28  sub     rsp, 28h
000010B4  83 FA 01  cmp     edx, 1
000010B7  75 1F  jnz     short loc_1800010D8
000010B9  E8 09 3A 00 00  call    AfxGetModuleState(void)
000010BE  48 8B 48 38  mov     rcx, [rax+38h]
000010C2  48 89 48 30  mov     [rax+30h], rcx
000010C6  48 8B 48 50  mov     rcx, [rax+50h]
000010CA  48 89 48 48  mov     [rax+48h], rcx
000010CE  33 C9  xor     ecx, ecx
000010D0  48 89 48 38  mov     [rax+38h], rcx
000010D4  48 89 48 50  mov     [rax+50h], rcx
000010D8  B8 01 00 00 00  mov     eax, 1
000010DD  48 83 C4 28  add     rsp, 28h
000010E1  C3  retn

; FUNC 000010F0-000011B1 sub_1800010F0 (193 bytes)
000010F0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000010F5  48 89 6C 24 10  mov     [rsp+arg_8], rbp
000010FA  48 89 74 24 18  mov     [rsp+arg_10], rsi
000010FF  41 56  push    r14
00001101  48 83 EC 30  sub     rsp, 30h
00001105  48 8B EA  mov     rbp, rdx
00001108  48 8B D9  mov     rbx, rcx
0000110B  48 85 D2  test    rdx, rdx
0000110E  74 66  jz      short loc_180001176
00001110  4C 8B C2  mov     r8, rdx; lpMultiByteStr
00001113  C7 44 24 28 00 00 00 00  mov     [rsp+38h+cchWideChar], 0; cchWideChar
0000111B  33 D2  xor     edx, edx; dwFlags
0000111D  48 C7 44 24 20 00 00 00 00  mov     [rsp+38h+lpWideCharStr], 0; lpWideCharStr
00001126  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
0000112C  33 C9  xor     ecx, ecx; CodePage
0000112E  FF 15 1C 5F 00 00  call    cs:MultiByteToWideChar; KERNEL32
00001134  33 C9  xor     ecx, ecx; strIn
00001136  44 8B F0  mov     r14d, eax
00001139  8D 50 FF  lea     edx, [rax-1]; ui
0000113C  FF 15 96 5F 00 00  call    cs:SysAllocStringLen
00001142  48 8B F0  mov     rsi, rax
00001145  48 85 C0  test    rax, rax
00001148  74 22  jz      short loc_18000116C
0000114A  44 89 74 24 28  mov     [rsp+38h+cchWideChar], r14d; cchWideChar
0000114F  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00001155  4C 8B C5  mov     r8, rbp; lpMultiByteStr
00001158  48 89 44 24 20  mov     [rsp+38h+lpWideCharStr], rax; lpWideCharStr
0000115D  33 D2  xor     edx, edx; dwFlags
0000115F  33 C9  xor     ecx, ecx; CodePage
00001161  FF 15 E9 5E 00 00  call    cs:MultiByteToWideChar; KERNEL32
00001167  41 3B C6  cmp     eax, r14d
0000116A  75 2A  jnz     short loc_180001196
0000116C  48 89 33  mov     [rbx], rsi
0000116F  48 85 F6  test    rsi, rsi
00001172  74 32  jz      short loc_1800011A6
00001174  EB 07  jmp     short loc_18000117D
00001176  48 C7 01 00 00 00 00  mov     qword ptr [rcx], 0
0000117D  48 8B 6C 24 48  mov     rbp, [rsp+38h+arg_8]
00001182  48 8B C3  mov     rax, rbx
00001185  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
0000118A  48 8B 74 24 50  mov     rsi, [rsp+38h+arg_10]
0000118F  48 83 C4 30  add     rsp, 30h
00001193  41 5E  pop     r14
00001195  C3  retn
00001196  48 8B CE  mov     rcx, rsi; bstrString
00001199  FF 15 41 5F 00 00  call    cs:SysFreeString
0000119F  48 C7 03 00 00 00 00  mov     qword ptr [rbx], 0
000011A6  B9 0E 00 07 80  mov     ecx, 8007000Eh
000011AB  E8 B0 FE FF FF  call    sub_180001060
000011B0  CC  db 0CCh

; FUNC 000011C0-000011CA sub_1800011C0 (10 bytes)
000011C0  48 8B 09  mov     rcx, [rcx]
000011C3  48 FF 25 16 5F 00 00  jmp     cs:SysFreeString

; FUNC 000011D0-000011D7 VariantClear (7 bytes)
000011D0  48 FF 25 F9 5E 00 00  jmp     cs:__imp_VariantClear

; FUNC 000011E0-00001319 sub_1800011E0 (313 bytes)
000011E0  48 89 4C 24 08  mov     [rsp+arg_0], rcx
000011E5  53  push    rbx
000011E6  56  push    rsi
000011E7  57  push    rdi
000011E8  41 56  push    r14
000011EA  41 57  push    r15
000011EC  48 83 EC 40  sub     rsp, 40h
000011F0  4C 8B F2  mov     r14, rdx
000011F3  48 8B F1  mov     rsi, rcx
000011F6  48 85 D2  test    rdx, rdx
000011F9  75 0E  jnz     short loc_180001209
000011FB  33 C0  xor     eax, eax
000011FD  48 83 C4 40  add     rsp, 40h
00001201  41 5F  pop     r15
00001203  41 5E  pop     r14
00001205  5F  pop     rdi
00001206  5E  pop     rsi
00001207  5B  pop     rbx
00001208  C3  retn
00001209  33 C9  xor     ecx, ecx; bstrString
0000120B  FF 15 CF 5E 00 00  call    cs:SysFreeString
00001211  33 FF  xor     edi, edi
00001213  89 7C 24 28  mov     [rsp+68h+cchWideChar], edi; cchWideChar
00001217  48 89 7C 24 20  mov     [rsp+68h+lpWideCharStr], rdi; lpWideCharStr
0000121C  44 8D 4F FF  lea     r9d, [rdi-1]; cbMultiByte
00001220  4D 8B C6  mov     r8, r14; lpMultiByteStr
00001223  33 D2  xor     edx, edx; dwFlags
00001225  33 C9  xor     ecx, ecx; CodePage
00001227  FF 15 23 5E 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000122D  44 8B F8  mov     r15d, eax
00001230  8D 50 FF  lea     edx, [rax-1]; ui
00001233  33 C9  xor     ecx, ecx; strIn
00001235  FF 15 9D 5E 00 00  call    cs:SysAllocStringLen
0000123B  48 8B D8  mov     rbx, rax
0000123E  48 85 C0  test    rax, rax
00001241  74 3B  jz      short loc_18000127E
00001243  44 89 7C 24 28  mov     [rsp+68h+cchWideChar], r15d; cchWideChar
00001248  48 89 44 24 20  mov     [rsp+68h+lpWideCharStr], rax; lpWideCharStr
0000124D  44 8D 4F FF  lea     r9d, [rdi-1]; cbMultiByte
00001251  4D 8B C6  mov     r8, r14; lpMultiByteStr
00001254  33 D2  xor     edx, edx; dwFlags
00001256  33 C9  xor     ecx, ecx; CodePage
00001258  FF 15 F2 5D 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000125E  41 3B C7  cmp     eax, r15d
00001261  74 1B  jz      short loc_18000127E
00001263  48 8B CB  mov     rcx, rbx; bstrString
00001266  FF 15 74 5E 00 00  call    cs:SysFreeString
0000126C  48 89 7C 24 78  mov     [rsp+68h+pbstrResult], rdi
00001271  48 89 BC 24 80 00 00 00  mov     [rsp+68h+arg_10], rdi
00001279  E9 8F 00 00 00  jmp     loc_18000130D
0000127E  48 89 5C 24 78  mov     [rsp+68h+pbstrResult], rbx
00001283  48 89 9C 24 80 00 00 00  mov     [rsp+68h+arg_10], rbx
0000128B  48 85 DB  test    rbx, rbx
0000128E  74 7D  jz      short loc_18000130D
00001290  EB 2B  jmp     short loc_1800012BD
00001292  48 8B 5C 24 78  mov     rbx, [rsp+68h+pbstrResult]
00001297  48 85 DB  test    rbx, rbx
0000129A  75 1A  jnz     short loc_1800012B6
0000129C  48 8B CB  mov     rcx, rbx; bstrString
0000129F  FF 15 3B 5E 00 00  call    cs:SysFreeString
000012A5  B8 0E 00 07 80  mov     eax, 8007000Eh
000012AA  48 83 C4 40  add     rsp, 40h
000012AE  41 5F  pop     r15
000012B0  41 5E  pop     r14
000012B2  5F  pop     rdi
000012B3  5E  pop     rsi
000012B4  5B  pop     rbx
000012B5  C3  retn
000012B6  33 FF  xor     edi, edi
000012B8  48 8B 74 24 70  mov     rsi, [rsp+68h+arg_0]
000012BD  48 8B CB  mov     rcx, rbx; pbstr
000012C0  FF 15 22 5E 00 00  call    cs:SysStringLen
000012C6  85 C0  test    eax, eax
000012C8  74 2C  jz      short loc_1800012F6
000012CA  48 89 7C 24 78  mov     [rsp+68h+pbstrResult], rdi
000012CF  4C 8D 44 24 78  lea     r8, [rsp+68h+pbstrResult]; pbstrResult
000012D4  48 8B D3  mov     rdx, rbx; bstrRight
000012D7  48 8B 0E  mov     rcx, [rsi]; bstrLeft
000012DA  E8 1D 4A 00 00  call    VarBstrCat
000012DF  8B F8  mov     edi, eax
000012E1  85 C0  test    eax, eax
000012E3  78 11  js      short loc_1800012F6
000012E5  48 8B 0E  mov     rcx, [rsi]; bstrString
000012E8  FF 15 F2 5D 00 00  call    cs:SysFreeString
000012EE  48 8B 44 24 78  mov     rax, [rsp+68h+pbstrResult]
000012F3  48 89 06  mov     [rsi], rax
000012F6  48 8B CB  mov     rcx, rbx; bstrString
000012F9  FF 15 E1 5D 00 00  call    cs:SysFreeString
000012FF  8B C7  mov     eax, edi
00001301  48 83 C4 40  add     rsp, 40h
00001305  41 5F  pop     r15
00001307  41 5E  pop     r14
00001309  5F  pop     rdi
0000130A  5E  pop     rsi
0000130B  5B  pop     rbx
0000130C  C3  retn
0000130D  B9 0E 00 07 80  mov     ecx, 8007000Eh
00001312  E8 49 FD FF FF  call    sub_180001060
00001317  CC  align 8
00001318  CC  db 0CCh

; FUNC 00001320-00001483 sub_180001320 (355 bytes)
00001320  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001325  48 89 6C 24 20  mov     [rsp+arg_18], rbp
0000132A  56  push    rsi
0000132B  57  push    rdi
0000132C  41 56  push    r14
0000132E  48 81 EC A0 00 00 00  sub     rsp, 0A0h
00001335  48 8B E9  mov     rbp, rcx
00001338  E8 F3 0F 00 00  call    sub_180002330
0000133D  48 8B F8  mov     rdi, rax
00001340  48 85 C0  test    rax, rax
00001343  74 54  jz      short loc_180001399
00001345  48 8D 05 D4 64 00 00  lea     rax, aShowdialog; "ShowDialog"
0000134C  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
00001354  48 8B 1F  mov     rbx, [rdi]
00001357  FF 15 03 5D 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000135D  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
00001365  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
0000136A  89 44 24 20  mov     [rsp+0B8h+var_98], eax
0000136E  41 BE 01 00 00 00  mov     r14d, 1
00001374  45 8B CE  mov     r9d, r14d
00001377  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
0000137F  48 8D 15 72 6F 00 00  lea     rdx, unk_1800082F8
00001386  48 8B CF  mov     rcx, rdi
00001389  FF 53 28  call    qword ptr [rbx+28h]
0000138C  85 C0  test    eax, eax
0000138E  79 10  jns     short loc_1800013A0
00001390  48 8B 07  mov     rax, [rdi]
00001393  48 8B CF  mov     rcx, rdi
00001396  FF 50 10  call    qword ptr [rax+10h]
00001399  33 C0  xor     eax, eax
0000139B  E9 CB 00 00 00  jmp     loc_18000146B
000013A0  33 F6  xor     esi, esi
000013A2  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
000013A7  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
000013AC  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
000013B1  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
000013B6  8B DE  mov     ebx, esi
000013B8  0F 1F 84 00 00 00 00 00  nop     dword ptr [rax+rax+00000000h]
000013C0  8B C3  mov     eax, ebx
000013C2  48 8D 0C 40  lea     rcx, [rax+rax*2]
000013C6  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
000013CB  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
000013CF  FF 15 1B 5D 00 00  call    cs:VariantInit
000013D5  FF C3  inc     ebx
000013D7  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
000013DB  72 E3  jb      short loc_1800013C0
000013DD  B8 08 00 00 00  mov     eax, 8
000013E2  66 89 44 24 68  mov     [rsp+0B8h+var_50], ax
000013E7  48 89 6C 24 70  mov     [rsp+0B8h+var_48], rbp
000013EC  33 D2  xor     edx, edx; int
000013EE  44 8D 40 FB  lea     r8d, [rax-5]; unsigned __int16
000013F2  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
000013FA  E8 F8 36 00 00  call    COleVariant::COleVariant(long,ushort)
000013FF  90  nop
00001400  48 8B 1F  mov     rbx, [rdi]
00001403  FF 15 57 5C 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001409  44 8B C8  mov     r9d, eax
0000140C  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
00001411  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
00001416  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
0000141E  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
00001423  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
00001428  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
0000142D  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
00001433  4C 8D 05 BE 6E 00 00  lea     r8, unk_1800082F8
0000143A  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
00001441  48 8B CF  mov     rcx, rdi
00001444  FF 53 30  call    qword ptr [rbx+30h]
00001447  85 C0  test    eax, eax
00001449  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
00001451  48 8B 17  mov     rdx, [rdi]
00001454  48 8B CF  mov     rcx, rdi
00001457  FF 52 10  call    qword ptr [rdx+10h]
0000145A  90  nop
0000145B  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
00001463  FF 15 67 5C 00 00  call    cs:__imp_VariantClear
00001469  8B C6  mov     eax, esi
0000146B  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
00001473  49 8B 5B 20  mov     rbx, [r11+20h]
00001477  49 8B 6B 38  mov     rbp, [r11+38h]
0000147B  49 8B E3  mov     rsp, r11
0000147E  41 5E  pop     r14
00001480  5F  pop     rdi
00001481  5E  pop     rsi
00001482  C3  retn

; FUNC 00001490-000015F0 sub_180001490 (352 bytes)
00001490  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001495  48 89 6C 24 20  mov     [rsp+arg_18], rbp
0000149A  56  push    rsi
0000149B  57  push    rdi
0000149C  41 56  push    r14
0000149E  48 81 EC A0 00 00 00  sub     rsp, 0A0h
000014A5  8B E9  mov     ebp, ecx
000014A7  E8 84 0E 00 00  call    sub_180002330
000014AC  48 8B F8  mov     rdi, rax
000014AF  48 85 C0  test    rax, rax
000014B2  74 54  jz      short loc_180001508
000014B4  48 8D 05 2D 64 00 00  lea     rax, aShowelecwizard; "ShowElecWizard"
000014BB  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
000014C3  48 8B 1F  mov     rbx, [rdi]
000014C6  FF 15 94 5B 00 00  call    cs:GetUserDefaultLCID; KERNEL32
000014CC  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
000014D4  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
000014D9  89 44 24 20  mov     [rsp+0B8h+var_98], eax
000014DD  41 BE 01 00 00 00  mov     r14d, 1
000014E3  45 8B CE  mov     r9d, r14d
000014E6  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
000014EE  48 8D 15 03 6E 00 00  lea     rdx, unk_1800082F8
000014F5  48 8B CF  mov     rcx, rdi
000014F8  FF 53 28  call    qword ptr [rbx+28h]
000014FB  85 C0  test    eax, eax
000014FD  79 10  jns     short loc_18000150F
000014FF  48 8B 07  mov     rax, [rdi]
00001502  48 8B CF  mov     rcx, rdi
00001505  FF 50 10  call    qword ptr [rax+10h]
00001508  33 C0  xor     eax, eax
0000150A  E9 C9 00 00 00  jmp     loc_1800015D8
0000150F  33 F6  xor     esi, esi
00001511  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
00001516  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
0000151B  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001520  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
00001525  8B DE  mov     ebx, esi
00001527  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00001530  8B C3  mov     eax, ebx
00001532  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001536  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
0000153B  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000153F  FF 15 AB 5B 00 00  call    cs:VariantInit
00001545  FF C3  inc     ebx
00001547  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
0000154B  72 E3  jb      short loc_180001530
0000154D  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00001553  66 44 89 44 24 68  mov     [rsp+0B8h+var_50], r8w
00001559  89 6C 24 70  mov     [rsp+0B8h+var_48], ebp
0000155D  33 D2  xor     edx, edx; int
0000155F  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
00001567  E8 8B 35 00 00  call    COleVariant::COleVariant(long,ushort)
0000156C  90  nop
0000156D  48 8B 1F  mov     rbx, [rdi]
00001570  FF 15 EA 5A 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001576  44 8B C8  mov     r9d, eax
00001579  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
0000157E  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
00001583  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
0000158B  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
00001590  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
00001595  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
0000159A  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
000015A0  4C 8D 05 51 6D 00 00  lea     r8, unk_1800082F8
000015A7  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
000015AE  48 8B CF  mov     rcx, rdi
000015B1  FF 53 30  call    qword ptr [rbx+30h]
000015B4  85 C0  test    eax, eax
000015B6  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
000015BE  48 8B 17  mov     rdx, [rdi]
000015C1  48 8B CF  mov     rcx, rdi
000015C4  FF 52 10  call    qword ptr [rdx+10h]
000015C7  90  nop
000015C8  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
000015D0  FF 15 FA 5A 00 00  call    cs:__imp_VariantClear
000015D6  8B C6  mov     eax, esi
000015D8  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
000015E0  49 8B 5B 20  mov     rbx, [r11+20h]
000015E4  49 8B 6B 38  mov     rbp, [r11+38h]
000015E8  49 8B E3  mov     rsp, r11
000015EB  41 5E  pop     r14
000015ED  5F  pop     rdi
000015EE  5E  pop     rsi
000015EF  C3  retn

; FUNC 000015F0-0000177F sub_1800015F0 (399 bytes)
000015F0  40 53  push    rbx
000015F2  55  push    rbp
000015F3  56  push    rsi
000015F4  57  push    rdi
000015F5  41 56  push    r14
000015F7  48 81 EC A0 00 00 00  sub     rsp, 0A0h
000015FE  4C 8B F1  mov     r14, rcx
00001601  E8 2A 0D 00 00  call    sub_180002330
00001606  48 8B F8  mov     rdi, rax
00001609  48 85 C0  test    rax, rax
0000160C  74 53  jz      short loc_180001661
0000160E  48 8D 05 73 63 00 00  lea     rax, aShownewpurecom; "ShowNewPureCompParam"
00001615  48 89 84 24 E8 00 00 00  mov     [rsp+0C8h+arg_18], rax
0000161D  48 8B 1F  mov     rbx, [rdi]
00001620  FF 15 3A 5A 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001626  48 8D 8C 24 D8 00 00 00  lea     rcx, [rsp+0C8h+arg_8]
0000162E  48 89 4C 24 28  mov     [rsp+0C8h+var_A0], rcx
00001633  89 44 24 20  mov     [rsp+0C8h+var_A8], eax
00001637  BD 01 00 00 00  mov     ebp, 1
0000163C  44 8B CD  mov     r9d, ebp
0000163F  4C 8D 84 24 E8 00 00 00  lea     r8, [rsp+0C8h+arg_18]
00001647  48 8D 15 AA 6C 00 00  lea     rdx, unk_1800082F8
0000164E  48 8B CF  mov     rcx, rdi
00001651  FF 53 28  call    qword ptr [rbx+28h]
00001654  85 C0  test    eax, eax
00001656  79 19  jns     short loc_180001671
00001658  48 8B 07  mov     rax, [rdi]
0000165B  48 8B CF  mov     rcx, rdi
0000165E  FF 50 10  call    qword ptr [rax+10h]
00001661  33 C0  xor     eax, eax
00001663  48 81 C4 A0 00 00 00  add     rsp, 0A0h
0000166A  41 5E  pop     r14
0000166C  5F  pop     rdi
0000166D  5E  pop     rsi
0000166E  5D  pop     rbp
0000166F  5B  pop     rbx
00001670  C3  retn
00001671  33 F6  xor     esi, esi
00001673  48 89 74 24 58  mov     [rsp+0C8h+var_70], rsi
00001678  48 89 6C 24 60  mov     [rsp+0C8h+var_68], rbp
0000167D  48 8D 44 24 68  lea     rax, [rsp+0C8h+var_60]
00001682  48 89 44 24 50  mov     [rsp+0C8h+var_78], rax
00001687  8B DE  mov     ebx, esi
00001689  0F 1F 80 00 00 00 00  nop     dword ptr [rax+00000000h]
00001690  8B C3  mov     eax, ebx
00001692  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001696  48 8D 44 24 68  lea     rax, [rsp+0C8h+var_60]
0000169B  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000169F  FF 15 4B 5A 00 00  call    cs:VariantInit
000016A5  FF C3  inc     ebx
000016A7  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0C8h+var_68]
000016AB  72 E3  jb      short loc_180001690
000016AD  48 8D 0D 84 61 00 00  lea     rcx, psz; psz
000016B4  FF 15 3E 5A 00 00  call    cs:SysAllocString
000016BA  48 89 84 24 E0 00 00 00  mov     [rsp+0C8h+bstrString], rax
000016C2  B8 08 40 00 00  mov     eax, 4008h
000016C7  66 89 44 24 68  mov     [rsp+0C8h+var_60], ax
000016CC  48 8D 84 24 E0 00 00 00  lea     rax, [rsp+0C8h+bstrString]
000016D4  48 89 44 24 70  mov     [rsp+0C8h+var_58], rax
000016D9  33 D2  xor     edx, edx; int
000016DB  44 8D 42 03  lea     r8d, [rdx+3]; unsigned __int16
000016DF  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0C8h+pvarg]; this
000016E7  E8 0B 34 00 00  call    COleVariant::COleVariant(long,ushort)
000016EC  90  nop
000016ED  48 8B 1F  mov     rbx, [rdi]
000016F0  FF 15 6A 59 00 00  call    cs:GetUserDefaultLCID; KERNEL32
000016F6  44 8B C8  mov     r9d, eax
000016F9  48 89 74 24 40  mov     [rsp+0C8h+var_88], rsi
000016FE  48 89 74 24 38  mov     [rsp+0C8h+var_90], rsi
00001703  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0C8h+pvarg]
0000170B  48 89 44 24 30  mov     [rsp+0C8h+var_98], rax
00001710  48 8D 44 24 50  lea     rax, [rsp+0C8h+var_78]
00001715  48 89 44 24 28  mov     [rsp+0C8h+var_A0], rax
0000171A  66 89 6C 24 20  mov     word ptr [rsp+0C8h+var_A8], bp
0000171F  4C 8D 05 D2 6B 00 00  lea     r8, unk_1800082F8
00001726  8B 94 24 D8 00 00 00  mov     edx, [rsp+0C8h+arg_8]
0000172D  48 8B CF  mov     rcx, rdi
00001730  FF 53 30  call    qword ptr [rbx+30h]
00001733  85 C0  test    eax, eax
00001735  78 12  js      short loc_180001749
00001737  8B B4 24 88 00 00 00  mov     esi, dword ptr [rsp+0C8h+pvarg+8]
0000173E  48 8B 8C 24 E0 00 00 00  mov     rcx, [rsp+0C8h+bstrString]
00001746  49 89 0E  mov     [r14], rcx
00001749  48 8B 17  mov     rdx, [rdi]
0000174C  48 8B CF  mov     rcx, rdi
0000174F  FF 52 10  call    qword ptr [rdx+10h]
00001752  48 8B 8C 24 E0 00 00 00  mov     rcx, [rsp+0C8h+bstrString]; bstrString
0000175A  FF 15 80 59 00 00  call    cs:SysFreeString
00001760  90  nop
00001761  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0C8h+pvarg]; pvarg
00001769  FF 15 61 59 00 00  call    cs:__imp_VariantClear
0000176F  8B C6  mov     eax, esi
00001771  48 81 C4 A0 00 00 00  add     rsp, 0A0h
00001778  41 5E  pop     r14
0000177A  5F  pop     rdi
0000177B  5E  pop     rsi
0000177C  5D  pop     rbp
0000177D  5B  pop     rbx
0000177E  C3  retn

; FUNC 00001780-000018E0 sub_180001780 (352 bytes)
00001780  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001785  48 89 6C 24 20  mov     [rsp+arg_18], rbp
0000178A  56  push    rsi
0000178B  57  push    rdi
0000178C  41 56  push    r14
0000178E  48 81 EC A0 00 00 00  sub     rsp, 0A0h
00001795  8B E9  mov     ebp, ecx
00001797  E8 94 0B 00 00  call    sub_180002330
0000179C  48 8B F8  mov     rdi, rax
0000179F  48 85 C0  test    rax, rax
000017A2  74 54  jz      short loc_1800017F8
000017A4  48 8D 05 5D 61 00 00  lea     rax, aShowsfeassista; "ShowSFEAssistant"
000017AB  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
000017B3  48 8B 1F  mov     rbx, [rdi]
000017B6  FF 15 A4 58 00 00  call    cs:GetUserDefaultLCID; KERNEL32
000017BC  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
000017C4  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
000017C9  89 44 24 20  mov     [rsp+0B8h+var_98], eax
000017CD  41 BE 01 00 00 00  mov     r14d, 1
000017D3  45 8B CE  mov     r9d, r14d
000017D6  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
000017DE  48 8D 15 13 6B 00 00  lea     rdx, unk_1800082F8
000017E5  48 8B CF  mov     rcx, rdi
000017E8  FF 53 28  call    qword ptr [rbx+28h]
000017EB  85 C0  test    eax, eax
000017ED  79 10  jns     short loc_1800017FF
000017EF  48 8B 07  mov     rax, [rdi]
000017F2  48 8B CF  mov     rcx, rdi
000017F5  FF 50 10  call    qword ptr [rax+10h]
000017F8  33 C0  xor     eax, eax
000017FA  E9 C9 00 00 00  jmp     loc_1800018C8
000017FF  33 F6  xor     esi, esi
00001801  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
00001806  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
0000180B  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001810  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
00001815  8B DE  mov     ebx, esi
00001817  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00001820  8B C3  mov     eax, ebx
00001822  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001826  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
0000182B  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000182F  FF 15 BB 58 00 00  call    cs:VariantInit
00001835  FF C3  inc     ebx
00001837  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
0000183B  72 E3  jb      short loc_180001820
0000183D  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00001843  66 44 89 44 24 68  mov     [rsp+0B8h+var_50], r8w
00001849  89 6C 24 70  mov     [rsp+0B8h+var_48], ebp
0000184D  33 D2  xor     edx, edx; int
0000184F  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
00001857  E8 9B 32 00 00  call    COleVariant::COleVariant(long,ushort)
0000185C  90  nop
0000185D  48 8B 1F  mov     rbx, [rdi]
00001860  FF 15 FA 57 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001866  44 8B C8  mov     r9d, eax
00001869  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
0000186E  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
00001873  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
0000187B  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
00001880  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
00001885  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
0000188A  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
00001890  4C 8D 05 61 6A 00 00  lea     r8, unk_1800082F8
00001897  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
0000189E  48 8B CF  mov     rcx, rdi
000018A1  FF 53 30  call    qword ptr [rbx+30h]
000018A4  85 C0  test    eax, eax
000018A6  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
000018AE  48 8B 17  mov     rdx, [rdi]
000018B1  48 8B CF  mov     rcx, rdi
000018B4  FF 52 10  call    qword ptr [rdx+10h]
000018B7  90  nop
000018B8  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
000018C0  FF 15 0A 58 00 00  call    cs:__imp_VariantClear
000018C6  8B C6  mov     eax, esi
000018C8  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
000018D0  49 8B 5B 20  mov     rbx, [r11+20h]
000018D4  49 8B 6B 38  mov     rbp, [r11+38h]
000018D8  49 8B E3  mov     rsp, r11
000018DB  41 5E  pop     r14
000018DD  5F  pop     rdi
000018DE  5E  pop     rsi
000018DF  C3  retn

; FUNC 000018E0-00001A40 sub_1800018E0 (352 bytes)
000018E0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000018E5  48 89 6C 24 20  mov     [rsp+arg_18], rbp
000018EA  56  push    rsi
000018EB  57  push    rdi
000018EC  41 56  push    r14
000018EE  48 81 EC A0 00 00 00  sub     rsp, 0A0h
000018F5  8B E9  mov     ebp, ecx
000018F7  E8 34 0A 00 00  call    sub_180002330
000018FC  48 8B F8  mov     rdi, rax
000018FF  48 85 C0  test    rax, rax
00001902  74 54  jz      short loc_180001958
00001904  48 8D 05 25 60 00 00  lea     rax, aShowsfeassista_0; "ShowSFEAssistantMain"
0000190B  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
00001913  48 8B 1F  mov     rbx, [rdi]
00001916  FF 15 44 57 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000191C  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
00001924  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
00001929  89 44 24 20  mov     [rsp+0B8h+var_98], eax
0000192D  41 BE 01 00 00 00  mov     r14d, 1
00001933  45 8B CE  mov     r9d, r14d
00001936  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
0000193E  48 8D 15 B3 69 00 00  lea     rdx, unk_1800082F8
00001945  48 8B CF  mov     rcx, rdi
00001948  FF 53 28  call    qword ptr [rbx+28h]
0000194B  85 C0  test    eax, eax
0000194D  79 10  jns     short loc_18000195F
0000194F  48 8B 07  mov     rax, [rdi]
00001952  48 8B CF  mov     rcx, rdi
00001955  FF 50 10  call    qword ptr [rax+10h]
00001958  33 C0  xor     eax, eax
0000195A  E9 C9 00 00 00  jmp     loc_180001A28
0000195F  33 F6  xor     esi, esi
00001961  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
00001966  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
0000196B  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001970  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
00001975  8B DE  mov     ebx, esi
00001977  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00001980  8B C3  mov     eax, ebx
00001982  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001986  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
0000198B  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000198F  FF 15 5B 57 00 00  call    cs:VariantInit
00001995  FF C3  inc     ebx
00001997  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
0000199B  72 E3  jb      short loc_180001980
0000199D  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
000019A3  66 44 89 44 24 68  mov     [rsp+0B8h+var_50], r8w
000019A9  89 6C 24 70  mov     [rsp+0B8h+var_48], ebp
000019AD  33 D2  xor     edx, edx; int
000019AF  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
000019B7  E8 3B 31 00 00  call    COleVariant::COleVariant(long,ushort)
000019BC  90  nop
000019BD  48 8B 1F  mov     rbx, [rdi]
000019C0  FF 15 9A 56 00 00  call    cs:GetUserDefaultLCID; KERNEL32
000019C6  44 8B C8  mov     r9d, eax
000019C9  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
000019CE  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
000019D3  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
000019DB  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
000019E0  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
000019E5  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
000019EA  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
000019F0  4C 8D 05 01 69 00 00  lea     r8, unk_1800082F8
000019F7  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
000019FE  48 8B CF  mov     rcx, rdi
00001A01  FF 53 30  call    qword ptr [rbx+30h]
00001A04  85 C0  test    eax, eax
00001A06  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
00001A0E  48 8B 17  mov     rdx, [rdi]
00001A11  48 8B CF  mov     rcx, rdi
00001A14  FF 52 10  call    qword ptr [rdx+10h]
00001A17  90  nop
00001A18  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
00001A20  FF 15 AA 56 00 00  call    cs:__imp_VariantClear
00001A26  8B C6  mov     eax, esi
00001A28  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
00001A30  49 8B 5B 20  mov     rbx, [r11+20h]
00001A34  49 8B 6B 38  mov     rbp, [r11+38h]
00001A38  49 8B E3  mov     rsp, r11
00001A3B  41 5E  pop     r14
00001A3D  5F  pop     rdi
00001A3E  5E  pop     rsi
00001A3F  C3  retn

; FUNC 00001A40-00001BF9 sub_180001A40 (441 bytes)
00001A40  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001A45  48 89 6C 24 10  mov     [rsp+arg_8], rbp
00001A4A  48 89 74 24 18  mov     [rsp+arg_10], rsi
00001A4F  57  push    rdi
00001A50  41 54  push    r12
00001A52  41 55  push    r13
00001A54  41 56  push    r14
00001A56  41 57  push    r15
00001A58  48 81 EC F0 00 00 00  sub     rsp, 0F0h
00001A5F  48 8B 05 82 99 00 00  mov     rax, cs:__security_cookie
00001A66  48 33 C4  xor     rax, rsp
00001A69  48 89 84 24 E0 00 00 00  mov     [rsp+118h+var_38], rax
00001A71  49 8B E8  mov     rbp, r8
00001A74  44 8B F2  mov     r14d, edx
00001A77  4C 8B F9  mov     r15, rcx
00001A7A  E8 B1 08 00 00  call    sub_180002330
00001A7F  48 8B F8  mov     rdi, rax
00001A82  48 85 C0  test    rax, rax
00001A85  74 4B  jz      short loc_180001AD2
00001A87  48 8D 05 D2 5E 00 00  lea     rax, aShowsearchcomp; "ShowSearchComponent"
00001A8E  48 89 44 24 58  mov     [rsp+118h+var_C0], rax
00001A93  48 8B 1F  mov     rbx, [rdi]
00001A96  FF 15 C4 55 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001A9C  48 8D 4C 24 50  lea     rcx, [rsp+118h+var_C8]
00001AA1  48 89 4C 24 28  mov     [rsp+118h+var_F0], rcx
00001AA6  89 44 24 20  mov     [rsp+118h+var_F8], eax
00001AAA  41 BD 01 00 00 00  mov     r13d, 1
00001AB0  45 8B CD  mov     r9d, r13d
00001AB3  4C 8D 44 24 58  lea     r8, [rsp+118h+var_C0]
00001AB8  48 8D 15 39 68 00 00  lea     rdx, unk_1800082F8
00001ABF  48 8B CF  mov     rcx, rdi
00001AC2  FF 53 28  call    qword ptr [rbx+28h]
00001AC5  85 C0  test    eax, eax
00001AC7  79 10  jns     short loc_180001AD9
00001AC9  48 8B 07  mov     rax, [rdi]
00001ACC  48 8B CF  mov     rcx, rdi
00001ACF  FF 50 10  call    qword ptr [rax+10h]
00001AD2  33 C0  xor     eax, eax
00001AD4  E9 EF 00 00 00  jmp     loc_180001BC8
00001AD9  33 F6  xor     esi, esi
00001ADB  48 89 74 24 68  mov     [rsp+118h+var_B0], rsi
00001AE0  48 C7 44 24 70 03 00 00 00  mov     [rsp+118h+var_A8], 3
00001AE9  48 8D 84 24 90 00 00 00  lea     rax, [rsp+118h+var_88]
00001AF1  48 89 44 24 60  mov     [rsp+118h+var_B8], rax
00001AF6  44 8D 66 03  lea     r12d, [rsi+3]
00001AFA  8B DE  mov     ebx, esi
00001AFC  0F 1F 40 00  nop     dword ptr [rax+00h]
00001B00  8B C3  mov     eax, ebx
00001B02  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001B06  48 8D 84 24 90 00 00 00  lea     rax, [rsp+118h+var_88]
00001B0E  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00001B12  FF 15 D8 55 00 00  call    cs:VariantInit
00001B18  FF C3  inc     ebx
00001B1A  3B 5C 24 70  cmp     ebx, dword ptr [rsp+118h+var_A8]
00001B1E  72 E0  jb      short loc_180001B00
00001B20  B8 08 00 00 00  mov     eax, 8
00001B25  66 89 84 24 C0 00 00 00  mov     [rsp+118h+var_58], ax
00001B2D  4C 89 BC 24 C8 00 00 00  mov     [rsp+118h+var_50], r15
00001B35  66 44 89 A4 24 A8 00 00 00  mov     [rsp+118h+var_70], r12w
00001B3E  44 89 B4 24 B0 00 00 00  mov     [rsp+118h+var_68], r14d
00001B46  66 89 84 24 90 00 00 00  mov     [rsp+118h+var_88], ax
00001B4E  48 89 AC 24 98 00 00 00  mov     [rsp+118h+var_80], rbp
00001B56  45 8B C4  mov     r8d, r12d; unsigned __int16
00001B59  33 D2  xor     edx, edx; int
00001B5B  48 8D 4C 24 78  lea     rcx, [rsp+118h+pvarg]; this
00001B60  E8 92 2F 00 00  call    COleVariant::COleVariant(long,ushort)
00001B65  90  nop
00001B66  48 8B 1F  mov     rbx, [rdi]
00001B69  FF 15 F1 54 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001B6F  44 8B C8  mov     r9d, eax
00001B72  48 89 74 24 40  mov     [rsp+118h+var_D8], rsi
00001B77  48 89 74 24 38  mov     [rsp+118h+var_E0], rsi
00001B7C  48 8D 44 24 78  lea     rax, [rsp+118h+pvarg]
00001B81  48 89 44 24 30  mov     [rsp+118h+var_E8], rax
00001B86  48 8D 44 24 60  lea     rax, [rsp+118h+var_B8]
00001B8B  48 89 44 24 28  mov     [rsp+118h+var_F0], rax
00001B90  66 44 89 6C 24 20  mov     word ptr [rsp+118h+var_F8], r13w
00001B96  4C 8D 05 5B 67 00 00  lea     r8, unk_1800082F8
00001B9D  8B 54 24 50  mov     edx, [rsp+118h+var_C8]
00001BA1  48 8B CF  mov     rcx, rdi
00001BA4  FF 53 30  call    qword ptr [rbx+30h]
00001BA7  85 C0  test    eax, eax
00001BA9  0F 49 B4 24 80 00 00 00  cmovns  esi, dword ptr [rsp+118h+pvarg+8]
00001BB1  48 8B 17  mov     rdx, [rdi]
00001BB4  48 8B CF  mov     rcx, rdi
00001BB7  FF 52 10  call    qword ptr [rdx+10h]
00001BBA  90  nop
00001BBB  48 8D 4C 24 78  lea     rcx, [rsp+118h+pvarg]; pvarg
00001BC0  FF 15 0A 55 00 00  call    cs:__imp_VariantClear
00001BC6  8B C6  mov     eax, esi
00001BC8  48 8B 8C 24 E0 00 00 00  mov     rcx, [rsp+118h+var_38]
00001BD0  48 33 CC  xor     rcx, rsp; StackCookie
00001BD3  E8 C8 36 00 00  call    __security_check_cookie
00001BD8  4C 8D 9C 24 F0 00 00 00  lea     r11, [rsp+118h+var_28]
00001BE0  49 8B 5B 30  mov     rbx, [r11+30h]
00001BE4  49 8B 6B 38  mov     rbp, [r11+38h]
00001BE8  49 8B 73 40  mov     rsi, [r11+40h]
00001BEC  49 8B E3  mov     rsp, r11
00001BEF  41 5F  pop     r15
00001BF1  41 5E  pop     r14
00001BF3  41 5D  pop     r13
00001BF5  41 5C  pop     r12
00001BF7  5F  pop     rdi
00001BF8  C3  retn

; FUNC 00001C00-00001D63 sub_180001C00 (355 bytes)
00001C00  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001C05  48 89 6C 24 20  mov     [rsp+arg_18], rbp
00001C0A  56  push    rsi
00001C0B  57  push    rdi
00001C0C  41 56  push    r14
00001C0E  48 81 EC A0 00 00 00  sub     rsp, 0A0h
00001C15  48 8B E9  mov     rbp, rcx
00001C18  E8 13 07 00 00  call    sub_180002330
00001C1D  48 8B F8  mov     rdi, rax
00001C20  48 85 C0  test    rax, rax
00001C23  74 54  jz      short loc_180001C79
00001C25  48 8D 05 8C 5D 00 00  lea     rax, aShowsearchprop; "ShowSearchProperty"
00001C2C  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
00001C34  48 8B 1F  mov     rbx, [rdi]
00001C37  FF 15 23 54 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001C3D  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
00001C45  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
00001C4A  89 44 24 20  mov     [rsp+0B8h+var_98], eax
00001C4E  41 BE 01 00 00 00  mov     r14d, 1
00001C54  45 8B CE  mov     r9d, r14d
00001C57  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
00001C5F  48 8D 15 92 66 00 00  lea     rdx, unk_1800082F8
00001C66  48 8B CF  mov     rcx, rdi
00001C69  FF 53 28  call    qword ptr [rbx+28h]
00001C6C  85 C0  test    eax, eax
00001C6E  79 10  jns     short loc_180001C80
00001C70  48 8B 07  mov     rax, [rdi]
00001C73  48 8B CF  mov     rcx, rdi
00001C76  FF 50 10  call    qword ptr [rax+10h]
00001C79  33 C0  xor     eax, eax
00001C7B  E9 CB 00 00 00  jmp     loc_180001D4B
00001C80  33 F6  xor     esi, esi
00001C82  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
00001C87  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
00001C8C  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001C91  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
00001C96  8B DE  mov     ebx, esi
00001C98  0F 1F 84 00 00 00 00 00  nop     dword ptr [rax+rax+00000000h]
00001CA0  8B C3  mov     eax, ebx
00001CA2  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001CA6  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001CAB  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00001CAF  FF 15 3B 54 00 00  call    cs:VariantInit
00001CB5  FF C3  inc     ebx
00001CB7  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
00001CBB  72 E3  jb      short loc_180001CA0
00001CBD  B8 08 00 00 00  mov     eax, 8
00001CC2  66 89 44 24 68  mov     [rsp+0B8h+var_50], ax
00001CC7  48 89 6C 24 70  mov     [rsp+0B8h+var_48], rbp
00001CCC  33 D2  xor     edx, edx; int
00001CCE  44 8D 40 FB  lea     r8d, [rax-5]; unsigned __int16
00001CD2  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
00001CDA  E8 18 2E 00 00  call    COleVariant::COleVariant(long,ushort)
00001CDF  90  nop
00001CE0  48 8B 1F  mov     rbx, [rdi]
00001CE3  FF 15 77 53 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001CE9  44 8B C8  mov     r9d, eax
00001CEC  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
00001CF1  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
00001CF6  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
00001CFE  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
00001D03  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
00001D08  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
00001D0D  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
00001D13  4C 8D 05 DE 65 00 00  lea     r8, unk_1800082F8
00001D1A  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
00001D21  48 8B CF  mov     rcx, rdi
00001D24  FF 53 30  call    qword ptr [rbx+30h]
00001D27  85 C0  test    eax, eax
00001D29  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
00001D31  48 8B 17  mov     rdx, [rdi]
00001D34  48 8B CF  mov     rcx, rdi
00001D37  FF 52 10  call    qword ptr [rdx+10h]
00001D3A  90  nop
00001D3B  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
00001D43  FF 15 87 53 00 00  call    cs:__imp_VariantClear
00001D49  8B C6  mov     eax, esi
00001D4B  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
00001D53  49 8B 5B 20  mov     rbx, [r11+20h]
00001D57  49 8B 6B 38  mov     rbp, [r11+38h]
00001D5B  49 8B E3  mov     rsp, r11
00001D5E  41 5E  pop     r14
00001D60  5F  pop     rdi
00001D61  5E  pop     rsi
00001D62  C3  retn

; FUNC 00001D70-00001EFF sub_180001D70 (399 bytes)
00001D70  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001D75  55  push    rbp
00001D76  56  push    rsi
00001D77  57  push    rdi
00001D78  41 56  push    r14
00001D7A  41 57  push    r15
00001D7C  48 81 EC C0 00 00 00  sub     rsp, 0C0h
00001D83  4C 8B F2  mov     r14, rdx
00001D86  8B E9  mov     ebp, ecx
00001D88  E8 A3 05 00 00  call    sub_180002330
00001D8D  48 8B F8  mov     rdi, rax
00001D90  48 85 C0  test    rax, rax
00001D93  74 4E  jz      short loc_180001DE3
00001D95  48 8D 05 B4 5C 00 00  lea     rax, aShowupgraderet; "ShowUpgradeRetired"
00001D9C  48 89 44 24 50  mov     [rsp+0E8h+var_98], rax
00001DA1  48 8B 1F  mov     rbx, [rdi]
00001DA4  FF 15 B6 52 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001DAA  48 8D 8C 24 08 01 00 00  lea     rcx, [rsp+0E8h+arg_18]
00001DB2  48 89 4C 24 28  mov     [rsp+0E8h+var_C0], rcx
00001DB7  89 44 24 20  mov     [rsp+0E8h+var_C8], eax
00001DBB  41 BF 01 00 00 00  mov     r15d, 1
00001DC1  45 8B CF  mov     r9d, r15d
00001DC4  4C 8D 44 24 50  lea     r8, [rsp+0E8h+var_98]
00001DC9  48 8D 15 28 65 00 00  lea     rdx, unk_1800082F8
00001DD0  48 8B CF  mov     rcx, rdi
00001DD3  FF 53 28  call    qword ptr [rbx+28h]
00001DD6  85 C0  test    eax, eax
00001DD8  79 10  jns     short loc_180001DEA
00001DDA  48 8B 07  mov     rax, [rdi]
00001DDD  48 8B CF  mov     rcx, rdi
00001DE0  FF 50 10  call    qword ptr [rax+10h]
00001DE3  33 C0  xor     eax, eax
00001DE5  E9 FE 00 00 00  jmp     loc_180001EE8
00001DEA  33 F6  xor     esi, esi
00001DEC  48 89 74 24 60  mov     [rsp+0E8h+var_88], rsi
00001DF1  48 C7 44 24 68 02 00 00 00  mov     [rsp+0E8h+var_80], 2
00001DFA  48 8D 84 24 88 00 00 00  lea     rax, [rsp+0E8h+var_60]
00001E02  48 89 44 24 58  mov     [rsp+0E8h+var_90], rax
00001E07  8B DE  mov     ebx, esi
00001E09  0F 1F 80 00 00 00 00  nop     dword ptr [rax+00000000h]
00001E10  8B C3  mov     eax, ebx
00001E12  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001E16  48 8D 84 24 88 00 00 00  lea     rax, [rsp+0E8h+var_60]
00001E1E  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00001E22  FF 15 C8 52 00 00  call    cs:VariantInit
00001E28  FF C3  inc     ebx
00001E2A  3B 5C 24 68  cmp     ebx, dword ptr [rsp+0E8h+var_80]
00001E2E  72 E0  jb      short loc_180001E10
00001E30  C7 84 24 00 01 00 00 FF FF FF FF  mov     [rsp+0E8h+arg_10], 0FFFFFFFFh
00001E3B  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00001E41  66 44 89 84 24 A0 00 00 00  mov     [rsp+0E8h+var_48], r8w
00001E4A  89 AC 24 A8 00 00 00  mov     [rsp+0E8h+var_40], ebp
00001E51  B8 03 40 00 00  mov     eax, 4003h
00001E56  66 89 84 24 88 00 00 00  mov     [rsp+0E8h+var_60], ax
00001E5E  48 8D 84 24 00 01 00 00  lea     rax, [rsp+0E8h+arg_10]
00001E66  48 89 84 24 90 00 00 00  mov     [rsp+0E8h+var_58], rax
00001E6E  33 D2  xor     edx, edx; int
00001E70  48 8D 4C 24 70  lea     rcx, [rsp+0E8h+pvarg]; this
00001E75  E8 7D 2C 00 00  call    COleVariant::COleVariant(long,ushort)
00001E7A  90  nop
00001E7B  48 8B 1F  mov     rbx, [rdi]
00001E7E  FF 15 DC 51 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001E84  44 8B C8  mov     r9d, eax
00001E87  48 89 74 24 40  mov     [rsp+0E8h+var_A8], rsi
00001E8C  48 89 74 24 38  mov     [rsp+0E8h+var_B0], rsi
00001E91  48 8D 44 24 70  lea     rax, [rsp+0E8h+pvarg]
00001E96  48 89 44 24 30  mov     [rsp+0E8h+var_B8], rax
00001E9B  48 8D 44 24 58  lea     rax, [rsp+0E8h+var_90]
00001EA0  48 89 44 24 28  mov     [rsp+0E8h+var_C0], rax
00001EA5  66 44 89 7C 24 20  mov     word ptr [rsp+0E8h+var_C8], r15w
00001EAB  4C 8D 05 46 64 00 00  lea     r8, unk_1800082F8
00001EB2  8B 94 24 08 01 00 00  mov     edx, [rsp+0E8h+arg_18]
00001EB9  48 8B CF  mov     rcx, rdi
00001EBC  FF 53 30  call    qword ptr [rbx+30h]
00001EBF  85 C0  test    eax, eax
00001EC1  78 0E  js      short loc_180001ED1
00001EC3  8B 74 24 78  mov     esi, dword ptr [rsp+0E8h+pvarg+8]
00001EC7  8B 8C 24 00 01 00 00  mov     ecx, [rsp+0E8h+arg_10]
00001ECE  41 89 0E  mov     [r14], ecx
00001ED1  48 8B 17  mov     rdx, [rdi]
00001ED4  48 8B CF  mov     rcx, rdi
00001ED7  FF 52 10  call    qword ptr [rdx+10h]
00001EDA  90  nop
00001EDB  48 8D 4C 24 70  lea     rcx, [rsp+0E8h+pvarg]; pvarg
00001EE0  FF 15 EA 51 00 00  call    cs:__imp_VariantClear
00001EE6  8B C6  mov     eax, esi
00001EE8  48 8B 9C 24 F0 00 00 00  mov     rbx, [rsp+0E8h+arg_0]
00001EF0  48 81 C4 C0 00 00 00  add     rsp, 0C0h
00001EF7  41 5F  pop     r15
00001EF9  41 5E  pop     r14
00001EFB  5F  pop     rdi
00001EFC  5E  pop     rsi
00001EFD  5D  pop     rbp
00001EFE  C3  retn

; FUNC 00001F00-00002060 sub_180001F00 (352 bytes)
00001F00  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00001F05  48 89 6C 24 20  mov     [rsp+arg_18], rbp
00001F0A  56  push    rsi
00001F0B  57  push    rdi
00001F0C  41 56  push    r14
00001F0E  48 81 EC A0 00 00 00  sub     rsp, 0A0h
00001F15  8B E9  mov     ebp, ecx
00001F17  E8 14 04 00 00  call    sub_180002330
00001F1C  48 8B F8  mov     rdi, rax
00001F1F  48 85 C0  test    rax, rax
00001F22  74 54  jz      short loc_180001F78
00001F24  48 8D 05 D5 5A 00 00  lea     rax, aShowupwardcomp; "ShowUpwardComp1"
00001F2B  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
00001F33  48 8B 1F  mov     rbx, [rdi]
00001F36  FF 15 24 51 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001F3C  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
00001F44  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
00001F49  89 44 24 20  mov     [rsp+0B8h+var_98], eax
00001F4D  41 BE 01 00 00 00  mov     r14d, 1
00001F53  45 8B CE  mov     r9d, r14d
00001F56  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
00001F5E  48 8D 15 93 63 00 00  lea     rdx, unk_1800082F8
00001F65  48 8B CF  mov     rcx, rdi
00001F68  FF 53 28  call    qword ptr [rbx+28h]
00001F6B  85 C0  test    eax, eax
00001F6D  79 10  jns     short loc_180001F7F
00001F6F  48 8B 07  mov     rax, [rdi]
00001F72  48 8B CF  mov     rcx, rdi
00001F75  FF 50 10  call    qword ptr [rax+10h]
00001F78  33 C0  xor     eax, eax
00001F7A  E9 C9 00 00 00  jmp     loc_180002048
00001F7F  33 F6  xor     esi, esi
00001F81  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
00001F86  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
00001F8B  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001F90  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
00001F95  8B DE  mov     ebx, esi
00001F97  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00001FA0  8B C3  mov     eax, ebx
00001FA2  48 8D 0C 40  lea     rcx, [rax+rax*2]
00001FA6  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00001FAB  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00001FAF  FF 15 3B 51 00 00  call    cs:VariantInit
00001FB5  FF C3  inc     ebx
00001FB7  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
00001FBB  72 E3  jb      short loc_180001FA0
00001FBD  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00001FC3  66 44 89 44 24 68  mov     [rsp+0B8h+var_50], r8w
00001FC9  89 6C 24 70  mov     [rsp+0B8h+var_48], ebp
00001FCD  33 D2  xor     edx, edx; int
00001FCF  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
00001FD7  E8 1B 2B 00 00  call    COleVariant::COleVariant(long,ushort)
00001FDC  90  nop
00001FDD  48 8B 1F  mov     rbx, [rdi]
00001FE0  FF 15 7A 50 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00001FE6  44 8B C8  mov     r9d, eax
00001FE9  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
00001FEE  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
00001FF3  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
00001FFB  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
00002000  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
00002005  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
0000200A  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
00002010  4C 8D 05 E1 62 00 00  lea     r8, unk_1800082F8
00002017  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
0000201E  48 8B CF  mov     rcx, rdi
00002021  FF 53 30  call    qword ptr [rbx+30h]
00002024  85 C0  test    eax, eax
00002026  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
0000202E  48 8B 17  mov     rdx, [rdi]
00002031  48 8B CF  mov     rcx, rdi
00002034  FF 52 10  call    qword ptr [rdx+10h]
00002037  90  nop
00002038  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
00002040  FF 15 8A 50 00 00  call    cs:__imp_VariantClear
00002046  8B C6  mov     eax, esi
00002048  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
00002050  49 8B 5B 20  mov     rbx, [r11+20h]
00002054  49 8B 6B 38  mov     rbp, [r11+38h]
00002058  49 8B E3  mov     rsp, r11
0000205B  41 5E  pop     r14
0000205D  5F  pop     rdi
0000205E  5E  pop     rsi
0000205F  C3  retn

; FUNC 00002060-000021CD sub_180002060 (365 bytes)
00002060  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00002065  55  push    rbp
00002066  56  push    rsi
00002067  57  push    rdi
00002068  41 56  push    r14
0000206A  41 57  push    r15
0000206C  48 81 EC B0 00 00 00  sub     rsp, 0B0h
00002073  8B EA  mov     ebp, edx
00002075  44 8B F1  mov     r14d, ecx
00002078  E8 B3 02 00 00  call    sub_180002330
0000207D  48 8B F8  mov     rdi, rax
00002080  48 85 C0  test    rax, rax
00002083  74 54  jz      short loc_1800020D9
00002085  48 8D 05 54 59 00 00  lea     rax, aShowupwardcomp_0; "ShowUpwardComp"
0000208C  48 89 84 24 F8 00 00 00  mov     [rsp+0D8h+arg_18], rax
00002094  48 8B 1F  mov     rbx, [rdi]
00002097  FF 15 C3 4F 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000209D  48 8D 8C 24 F0 00 00 00  lea     rcx, [rsp+0D8h+arg_10]
000020A5  48 89 4C 24 28  mov     [rsp+0D8h+var_B0], rcx
000020AA  89 44 24 20  mov     [rsp+0D8h+var_B8], eax
000020AE  41 BF 01 00 00 00  mov     r15d, 1
000020B4  45 8B CF  mov     r9d, r15d
000020B7  4C 8D 84 24 F8 00 00 00  lea     r8, [rsp+0D8h+arg_18]
000020BF  48 8D 15 32 62 00 00  lea     rdx, unk_1800082F8
000020C6  48 8B CF  mov     rcx, rdi
000020C9  FF 53 28  call    qword ptr [rbx+28h]
000020CC  85 C0  test    eax, eax
000020CE  79 10  jns     short loc_1800020E0
000020D0  48 8B 07  mov     rax, [rdi]
000020D3  48 8B CF  mov     rcx, rdi
000020D6  FF 50 10  call    qword ptr [rax+10h]
000020D9  33 C0  xor     eax, eax
000020DB  E9 D6 00 00 00  jmp     loc_1800021B6
000020E0  33 F6  xor     esi, esi
000020E2  48 89 74 24 58  mov     [rsp+0D8h+var_80], rsi
000020E7  48 C7 44 24 60 02 00 00 00  mov     [rsp+0D8h+var_78], 2
000020F0  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0D8h+var_58]
000020F8  48 89 44 24 50  mov     [rsp+0D8h+var_88], rax
000020FD  8B DE  mov     ebx, esi
000020FF  90  nop
00002100  8B C3  mov     eax, ebx
00002102  48 8D 0C 40  lea     rcx, [rax+rax*2]
00002106  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0D8h+var_58]
0000210E  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00002112  FF 15 D8 4F 00 00  call    cs:VariantInit
00002118  FF C3  inc     ebx
0000211A  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0D8h+var_78]
0000211E  72 E0  jb      short loc_180002100
00002120  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00002126  66 44 89 84 24 98 00 00 00  mov     [rsp+0D8h+var_40], r8w
0000212F  44 89 B4 24 A0 00 00 00  mov     [rsp+0D8h+var_38], r14d
00002137  66 44 89 84 24 80 00 00 00  mov     [rsp+0D8h+var_58], r8w
00002140  89 AC 24 88 00 00 00  mov     [rsp+0D8h+var_50], ebp
00002147  33 D2  xor     edx, edx; int
00002149  48 8D 4C 24 68  lea     rcx, [rsp+0D8h+pvarg]; this
0000214E  E8 A4 29 00 00  call    COleVariant::COleVariant(long,ushort)
00002153  90  nop
00002154  48 8B 1F  mov     rbx, [rdi]
00002157  FF 15 03 4F 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000215D  44 8B C8  mov     r9d, eax
00002160  48 89 74 24 40  mov     [rsp+0D8h+var_98], rsi
00002165  48 89 74 24 38  mov     [rsp+0D8h+var_A0], rsi
0000216A  48 8D 44 24 68  lea     rax, [rsp+0D8h+pvarg]
0000216F  48 89 44 24 30  mov     [rsp+0D8h+var_A8], rax
00002174  48 8D 44 24 50  lea     rax, [rsp+0D8h+var_88]
00002179  48 89 44 24 28  mov     [rsp+0D8h+var_B0], rax
0000217E  66 44 89 7C 24 20  mov     word ptr [rsp+0D8h+var_B8], r15w
00002184  4C 8D 05 6D 61 00 00  lea     r8, unk_1800082F8
0000218B  8B 94 24 F0 00 00 00  mov     edx, [rsp+0D8h+arg_10]
00002192  48 8B CF  mov     rcx, rdi
00002195  FF 53 30  call    qword ptr [rbx+30h]
00002198  85 C0  test    eax, eax
0000219A  0F 49 74 24 70  cmovns  esi, dword ptr [rsp+0D8h+pvarg+8]
0000219F  48 8B 17  mov     rdx, [rdi]
000021A2  48 8B CF  mov     rcx, rdi
000021A5  FF 52 10  call    qword ptr [rdx+10h]
000021A8  90  nop
000021A9  48 8D 4C 24 68  lea     rcx, [rsp+0D8h+pvarg]; pvarg
000021AE  FF 15 1C 4F 00 00  call    cs:__imp_VariantClear
000021B4  8B C6  mov     eax, esi
000021B6  48 8B 9C 24 E0 00 00 00  mov     rbx, [rsp+0D8h+arg_0]
000021BE  48 81 C4 B0 00 00 00  add     rsp, 0B0h
000021C5  41 5F  pop     r15
000021C7  41 5E  pop     r14
000021C9  5F  pop     rdi
000021CA  5E  pop     rsi
000021CB  5D  pop     rbp
000021CC  C3  retn

; FUNC 000021D0-00002330 sub_1800021D0 (352 bytes)
000021D0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000021D5  48 89 6C 24 20  mov     [rsp+arg_18], rbp
000021DA  56  push    rsi
000021DB  57  push    rdi
000021DC  41 56  push    r14
000021DE  48 81 EC A0 00 00 00  sub     rsp, 0A0h
000021E5  8B E9  mov     ebp, ecx
000021E7  E8 44 01 00 00  call    sub_180002330
000021EC  48 8B F8  mov     rdi, rax
000021EF  48 85 C0  test    rax, rax
000021F2  74 54  jz      short loc_180002248
000021F4  48 8D 05 25 58 00 00  lea     rax, aShowuserdefine; "ShowUserDefinedWizard"
000021FB  48 89 84 24 D0 00 00 00  mov     [rsp+0B8h+arg_10], rax
00002203  48 8B 1F  mov     rbx, [rdi]
00002206  FF 15 54 4E 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000220C  48 8D 8C 24 C8 00 00 00  lea     rcx, [rsp+0B8h+arg_8]
00002214  48 89 4C 24 28  mov     [rsp+0B8h+var_90], rcx
00002219  89 44 24 20  mov     [rsp+0B8h+var_98], eax
0000221D  41 BE 01 00 00 00  mov     r14d, 1
00002223  45 8B CE  mov     r9d, r14d
00002226  4C 8D 84 24 D0 00 00 00  lea     r8, [rsp+0B8h+arg_10]
0000222E  48 8D 15 C3 60 00 00  lea     rdx, unk_1800082F8
00002235  48 8B CF  mov     rcx, rdi
00002238  FF 53 28  call    qword ptr [rbx+28h]
0000223B  85 C0  test    eax, eax
0000223D  79 10  jns     short loc_18000224F
0000223F  48 8B 07  mov     rax, [rdi]
00002242  48 8B CF  mov     rcx, rdi
00002245  FF 50 10  call    qword ptr [rax+10h]
00002248  33 C0  xor     eax, eax
0000224A  E9 C9 00 00 00  jmp     loc_180002318
0000224F  33 F6  xor     esi, esi
00002251  48 89 74 24 58  mov     [rsp+0B8h+var_60], rsi
00002256  4C 89 74 24 60  mov     [rsp+0B8h+var_58], r14
0000225B  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
00002260  48 89 44 24 50  mov     [rsp+0B8h+var_68], rax
00002265  8B DE  mov     ebx, esi
00002267  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00002270  8B C3  mov     eax, ebx
00002272  48 8D 0C 40  lea     rcx, [rax+rax*2]
00002276  48 8D 44 24 68  lea     rax, [rsp+0B8h+var_50]
0000227B  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000227F  FF 15 6B 4E 00 00  call    cs:VariantInit
00002285  FF C3  inc     ebx
00002287  3B 5C 24 60  cmp     ebx, dword ptr [rsp+0B8h+var_58]
0000228B  72 E3  jb      short loc_180002270
0000228D  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00002293  66 44 89 44 24 68  mov     [rsp+0B8h+var_50], r8w
00002299  89 6C 24 70  mov     [rsp+0B8h+var_48], ebp
0000229D  33 D2  xor     edx, edx; int
0000229F  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; this
000022A7  E8 4B 28 00 00  call    COleVariant::COleVariant(long,ushort)
000022AC  90  nop
000022AD  48 8B 1F  mov     rbx, [rdi]
000022B0  FF 15 AA 4D 00 00  call    cs:GetUserDefaultLCID; KERNEL32
000022B6  44 8B C8  mov     r9d, eax
000022B9  48 89 74 24 40  mov     [rsp+0B8h+var_78], rsi
000022BE  48 89 74 24 38  mov     [rsp+0B8h+var_80], rsi
000022C3  48 8D 84 24 80 00 00 00  lea     rax, [rsp+0B8h+pvarg]
000022CB  48 89 44 24 30  mov     [rsp+0B8h+var_88], rax
000022D0  48 8D 44 24 50  lea     rax, [rsp+0B8h+var_68]
000022D5  48 89 44 24 28  mov     [rsp+0B8h+var_90], rax
000022DA  66 44 89 74 24 20  mov     word ptr [rsp+0B8h+var_98], r14w
000022E0  4C 8D 05 11 60 00 00  lea     r8, unk_1800082F8
000022E7  8B 94 24 C8 00 00 00  mov     edx, [rsp+0B8h+arg_8]
000022EE  48 8B CF  mov     rcx, rdi
000022F1  FF 53 30  call    qword ptr [rbx+30h]
000022F4  85 C0  test    eax, eax
000022F6  0F 49 B4 24 88 00 00 00  cmovns  esi, dword ptr [rsp+0B8h+pvarg+8]
000022FE  48 8B 17  mov     rdx, [rdi]
00002301  48 8B CF  mov     rcx, rdi
00002304  FF 52 10  call    qword ptr [rdx+10h]
00002307  90  nop
00002308  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0B8h+pvarg]; pvarg
00002310  FF 15 BA 4D 00 00  call    cs:__imp_VariantClear
00002316  8B C6  mov     eax, esi
00002318  4C 8D 9C 24 A0 00 00 00  lea     r11, [rsp+0B8h+var_18]
00002320  49 8B 5B 20  mov     rbx, [r11+20h]
00002324  49 8B 6B 38  mov     rbp, [r11+38h]
00002328  49 8B E3  mov     rsp, r11
0000232B  41 5E  pop     r14
0000232D  5F  pop     rdi
0000232E  5E  pop     rsi
0000232F  C3  retn

; FUNC 00002330-000023F4 sub_180002330 (196 bytes)
00002330  40 55  push    rbp
00002332  48 83 EC 50  sub     rsp, 50h
00002336  48 8D 6C 24 30  lea     rbp, [rsp+30h]
0000233B  48 89 5D 30  mov     [rbp+20h+arg_0], rbx
0000233F  48 89 7D 38  mov     [rbp+20h+arg_8], rdi
00002343  48 8B 05 9E 90 00 00  mov     rax, cs:__security_cookie
0000234A  48 33 C5  xor     rax, rbp
0000234D  48 89 45 18  mov     [rbp+20h+var_8], rax
00002351  8B 04 24  mov     eax, [rsp+50h+var_50]
00002354  48 81 EC 80 00 00 00  sub     rsp, 80h
0000235B  48 8D 5C 24 30  lea     rbx, [rsp+0D0h+WideCharStr]
00002360  8B 03  mov     eax, [rbx]
00002362  33 FF  xor     edi, edi
00002364  48 85 DB  test    rbx, rbx
00002367  74 2D  jz      short loc_180002396
00002369  C7 44 24 28 3D 00 00 00  mov     [rsp+0D0h+cchWideChar], 3Dh ; '='; cchWideChar
00002371  44 8D 4F FF  lea     r9d, [rdi-1]; cbMultiByte
00002375  4C 8D 05 2C 55 00 00  lea     r8, MultiByteStr; "AspenTech.AspenPlus.WpfFindComponent.Fi"...
0000237C  48 89 5C 24 20  mov     [rsp+0D0h+lpWideCharStr], rbx; lpWideCharStr
00002381  33 D2  xor     edx, edx; dwFlags
00002383  66 89 3B  mov     [rbx], di
00002386  33 C9  xor     ecx, ecx; CodePage
00002388  FF 15 C2 4C 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000238E  85 C0  test    eax, eax
00002390  48 0F 44 DF  cmovz   rbx, rdi
00002394  EB 03  jmp     short loc_180002399
00002396  48 8B DF  mov     rbx, rdi
00002399  48 8D 55 08  lea     rdx, [rbp+20h+clsid]; lpclsid
0000239D  48 8B CB  mov     rcx, rbx; lpszProgID
000023A0  FF 15 A2 52 00 00  call    cs:CLSIDFromProgID; ole32
000023A6  85 C0  test    eax, eax
000023A8  78 2E  js      short loc_1800023D8
000023AA  33 D2  xor     edx, edx; pUnkOuter
000023AC  48 89 7D 00  mov     [rbp+20h+ppv], rdi
000023B0  48 8D 45 00  lea     rax, [rbp+20h+ppv]
000023B4  4C 8D 0D 4D 5F 00 00  lea     r9, riid; riid
000023BB  48 89 44 24 20  mov     [rsp+0D0h+lpWideCharStr], rax; ppv
000023C0  48 8D 4D 08  lea     rcx, [rbp+20h+clsid]; rclsid
000023C4  44 8D 42 01  lea     r8d, [rdx+1]; dwClsContext
000023C8  FF 15 82 52 00 00  call    cs:CoCreateInstance; ole32
000023CE  85 C0  test    eax, eax
000023D0  78 06  js      short loc_1800023D8
000023D2  48 8B 45 00  mov     rax, [rbp+20h+ppv]
000023D6  EB 02  jmp     short loc_1800023DA
000023D8  33 C0  xor     eax, eax
000023DA  48 8B 4D 18  mov     rcx, [rbp+20h+var_8]
000023DE  48 33 CD  xor     rcx, rbp; StackCookie
000023E1  E8 BA 2E 00 00  call    __security_check_cookie
000023E6  48 8B 5D 30  mov     rbx, [rbp+20h+arg_0]
000023EA  48 8B 7D 38  mov     rdi, [rbp+20h+arg_8]
000023EE  48 8D 65 20  lea     rsp, [rbp+20h]
000023F2  5D  pop     rbp
000023F3  C3  retn

; FUNC 00002400-00002407 sub_180002400 (7 bytes)
00002400  8B 05 AE 91 00 00  mov     eax, cs:dword_18000B5B4
00002406  C3  retn

; FUNC 00002410-000024D1 sub_180002410 (193 bytes)
00002410  40 55  push    rbp
00002412  48 83 EC 50  sub     rsp, 50h
00002416  48 8D 6C 24 30  lea     rbp, [rsp+30h]
0000241B  48 89 5D 30  mov     [rbp+20h+arg_0], rbx
0000241F  48 89 7D 38  mov     [rbp+20h+arg_8], rdi
00002423  48 8B 05 BE 8F 00 00  mov     rax, cs:__security_cookie
0000242A  48 33 C5  xor     rax, rbp
0000242D  48 89 45 18  mov     [rbp+20h+var_8], rax
00002431  8B 04 24  mov     eax, [rsp+50h+var_50]
00002434  48 83 EC 60  sub     rsp, 60h
00002438  48 8D 5C 24 30  lea     rbx, [rsp+0B0h+WideCharStr]
0000243D  8B 03  mov     eax, [rbx]
0000243F  33 FF  xor     edi, edi
00002441  48 85 DB  test    rbx, rbx
00002444  74 2D  jz      short loc_180002473
00002446  C7 44 24 28 2F 00 00 00  mov     [rsp+0B0h+cchWideChar], 2Fh ; '/'; cchWideChar
0000244E  44 8D 4F FF  lea     r9d, [rdi-1]; cbMultiByte
00002452  4C 8D 05 E7 52 00 00  lea     r8, aAspentechAspen_0; "AspenTech.AspenPlus.WpfMMDialog.Message"...
00002459  48 89 5C 24 20  mov     [rsp+0B0h+lpWideCharStr], rbx; lpWideCharStr
0000245E  33 D2  xor     edx, edx; dwFlags
00002460  66 89 3B  mov     [rbx], di
00002463  33 C9  xor     ecx, ecx; CodePage
00002465  FF 15 E5 4B 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000246B  85 C0  test    eax, eax
0000246D  48 0F 44 DF  cmovz   rbx, rdi
00002471  EB 03  jmp     short loc_180002476
00002473  48 8B DF  mov     rbx, rdi
00002476  48 8D 55 08  lea     rdx, [rbp+20h+clsid]; lpclsid
0000247A  48 8B CB  mov     rcx, rbx; lpszProgID
0000247D  FF 15 C5 51 00 00  call    cs:CLSIDFromProgID; ole32
00002483  85 C0  test    eax, eax
00002485  78 2E  js      short loc_1800024B5
00002487  33 D2  xor     edx, edx; pUnkOuter
00002489  48 89 7D 00  mov     [rbp+20h+ppv], rdi
0000248D  48 8D 45 00  lea     rax, [rbp+20h+ppv]
00002491  4C 8D 0D 70 5E 00 00  lea     r9, riid; riid
00002498  48 89 44 24 20  mov     [rsp+0B0h+lpWideCharStr], rax; ppv
0000249D  48 8D 4D 08  lea     rcx, [rbp+20h+clsid]; rclsid
000024A1  44 8D 42 01  lea     r8d, [rdx+1]; dwClsContext
000024A5  FF 15 A5 51 00 00  call    cs:CoCreateInstance; ole32
000024AB  85 C0  test    eax, eax
000024AD  78 06  js      short loc_1800024B5
000024AF  48 8B 45 00  mov     rax, [rbp+20h+ppv]
000024B3  EB 02  jmp     short loc_1800024B7
000024B5  33 C0  xor     eax, eax
000024B7  48 8B 4D 18  mov     rcx, [rbp+20h+var_8]
000024BB  48 33 CD  xor     rcx, rbp; StackCookie
000024BE  E8 DD 2D 00 00  call    __security_check_cookie
000024C3  48 8B 5D 30  mov     rbx, [rbp+20h+arg_0]
000024C7  48 8B 7D 38  mov     rdi, [rbp+20h+arg_8]
000024CB  48 8D 65 20  lea     rsp, [rbp+20h]
000024CF  5D  pop     rbp
000024D0  C3  retn

; FUNC 000024E0-000025A1 sub_1800024E0 (193 bytes)
000024E0  40 55  push    rbp
000024E2  48 83 EC 50  sub     rsp, 50h
000024E6  48 8D 6C 24 30  lea     rbp, [rsp+30h]
000024EB  48 89 5D 30  mov     [rbp+20h+arg_0], rbx
000024EF  48 89 7D 38  mov     [rbp+20h+arg_8], rdi
000024F3  48 8B 05 EE 8E 00 00  mov     rax, cs:__security_cookie
000024FA  48 33 C5  xor     rax, rbp
000024FD  48 89 45 18  mov     [rbp+20h+var_8], rax
00002501  8B 04 24  mov     eax, [rsp+50h+var_50]
00002504  48 83 EC 70  sub     rsp, 70h
00002508  48 8D 5C 24 30  lea     rbx, [rsp+0C0h+WideCharStr]
0000250D  8B 03  mov     eax, [rbx]
0000250F  33 FF  xor     edi, edi
00002511  48 85 DB  test    rbx, rbx
00002514  74 2D  jz      short loc_180002543
00002516  C7 44 24 28 31 00 00 00  mov     [rsp+0C0h+cchWideChar], 31h ; '1'; cchWideChar
0000251E  44 8D 4F FF  lea     r9d, [rdi-1]; cbMultiByte
00002522  4C 8D 05 BF 52 00 00  lea     r8, aAspentechAspen_1; "AspenTech.AspenPlus.WpfMMDialog.DialogD"...
00002529  48 89 5C 24 20  mov     [rsp+0C0h+lpWideCharStr], rbx; lpWideCharStr
0000252E  33 D2  xor     edx, edx; dwFlags
00002530  66 89 3B  mov     [rbx], di
00002533  33 C9  xor     ecx, ecx; CodePage
00002535  FF 15 15 4B 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000253B  85 C0  test    eax, eax
0000253D  48 0F 44 DF  cmovz   rbx, rdi
00002541  EB 03  jmp     short loc_180002546
00002543  48 8B DF  mov     rbx, rdi
00002546  48 8D 55 08  lea     rdx, [rbp+20h+clsid]; lpclsid
0000254A  48 8B CB  mov     rcx, rbx; lpszProgID
0000254D  FF 15 F5 50 00 00  call    cs:CLSIDFromProgID; ole32
00002553  85 C0  test    eax, eax
00002555  78 2E  js      short loc_180002585
00002557  33 D2  xor     edx, edx; pUnkOuter
00002559  48 89 7D 00  mov     [rbp+20h+ppv], rdi
0000255D  48 8D 45 00  lea     rax, [rbp+20h+ppv]
00002561  4C 8D 0D A0 5D 00 00  lea     r9, riid; riid
00002568  48 89 44 24 20  mov     [rsp+0C0h+lpWideCharStr], rax; ppv
0000256D  48 8D 4D 08  lea     rcx, [rbp+20h+clsid]; rclsid
00002571  44 8D 42 01  lea     r8d, [rdx+1]; dwClsContext
00002575  FF 15 D5 50 00 00  call    cs:CoCreateInstance; ole32
0000257B  85 C0  test    eax, eax
0000257D  78 06  js      short loc_180002585
0000257F  48 8B 45 00  mov     rax, [rbp+20h+ppv]
00002583  EB 02  jmp     short loc_180002587
00002585  33 C0  xor     eax, eax
00002587  48 8B 4D 18  mov     rcx, [rbp+20h+var_8]
0000258B  48 33 CD  xor     rcx, rbp; StackCookie
0000258E  E8 0D 2D 00 00  call    __security_check_cookie
00002593  48 8B 5D 30  mov     rbx, [rbp+20h+arg_0]
00002597  48 8B 7D 38  mov     rdi, [rbp+20h+arg_8]
0000259B  48 8D 65 20  lea     rsp, [rbp+20h]
0000259F  5D  pop     rbp
000025A0  C3  retn

; FUNC 000025B0-000027AE sub_1800025B0 (510 bytes)
000025B0  48 89 5C 24 08  mov     [rsp-8+arg_0], rbx
000025B5  48 89 74 24 10  mov     [rsp-8+arg_8], rsi
000025BA  48 89 7C 24 18  mov     [rsp-8+arg_10], rdi
000025BF  55  push    rbp
000025C0  41 54  push    r12
000025C2  41 55  push    r13
000025C4  41 56  push    r14
000025C6  41 57  push    r15
000025C8  48 8D AC 24 40 FF FF FF  lea     rbp, [rsp-0C0h]
000025D0  48 81 EC C0 01 00 00  sub     rsp, 1C0h
000025D7  48 8B 05 0A 8E 00 00  mov     rax, cs:__security_cookie
000025DE  48 33 C4  xor     rax, rsp
000025E1  48 89 85 B0 00 00 00  mov     [rbp+0E0h+var_30], rax
000025E8  4D 8B F1  mov     r14, r9
000025EB  4D 8B F8  mov     r15, r8
000025EE  4C 8B E2  mov     r12, rdx
000025F1  4C 8B E9  mov     r13, rcx
000025F4  E8 17 FE FF FF  call    sub_180002410
000025F9  48 8B F8  mov     rdi, rax
000025FC  48 85 C0  test    rax, rax
000025FF  74 48  jz      short loc_180002649
00002601  48 8D 05 78 51 00 00  lea     rax, aShowopenmessag; "ShowOpenMessageBox"
00002608  48 89 44 24 58  mov     [rsp+1E0h+var_188], rax
0000260D  48 8B 1F  mov     rbx, [rdi]
00002610  FF 15 4A 4A 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002616  48 8D 4C 24 50  lea     rcx, [rsp+1E0h+var_190]
0000261B  48 89 4C 24 28  mov     [rsp+1E0h+var_1B8], rcx
00002620  89 44 24 20  mov     [rsp+1E0h+var_1C0], eax
00002624  41 B9 01 00 00 00  mov     r9d, 1
0000262A  4C 8D 44 24 58  lea     r8, [rsp+1E0h+var_188]
0000262F  48 8D 15 C2 5C 00 00  lea     rdx, unk_1800082F8
00002636  48 8B CF  mov     rcx, rdi
00002639  FF 53 28  call    qword ptr [rbx+28h]
0000263C  85 C0  test    eax, eax
0000263E  79 10  jns     short loc_180002650
00002640  48 8B 07  mov     rax, [rdi]
00002643  48 8B CF  mov     rcx, rdi
00002646  FF 50 10  call    qword ptr [rax+10h]
00002649  33 C0  xor     eax, eax
0000264B  E9 2E 01 00 00  jmp     loc_18000277E
00002650  33 F6  xor     esi, esi
00002652  48 89 74 24 68  mov     [rsp+1E0h+var_178], rsi
00002657  48 C7 44 24 70 09 00 00 00  mov     [rsp+1E0h+var_170], 9
00002660  48 8D 45 D0  lea     rax, [rbp+0E0h+var_110]
00002664  48 89 44 24 60  mov     [rsp+1E0h+var_180], rax
00002669  8B DE  mov     ebx, esi
0000266B  0F 1F 44 00 00  nop     dword ptr [rax+rax+00h]
00002670  8B C3  mov     eax, ebx
00002672  48 8D 0C 40  lea     rcx, [rax+rax*2]
00002676  48 8D 45 D0  lea     rax, [rbp+0E0h+var_110]
0000267A  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000267E  FF 15 6C 4A 00 00  call    cs:VariantInit
00002684  FF C3  inc     ebx
00002686  3B 5C 24 70  cmp     ebx, dword ptr [rsp+1E0h+var_170]
0000268A  72 E4  jb      short loc_180002670
0000268C  B9 08 00 00 00  mov     ecx, 8
00002691  66 89 8D 90 00 00 00  mov     [rbp+0E0h+var_50], cx
00002698  4C 89 AD 98 00 00 00  mov     [rbp+0E0h+var_48], r13
0000269F  66 89 4D 78  mov     [rbp+0E0h+var_68], cx
000026A3  4C 89 A5 80 00 00 00  mov     [rbp+0E0h+var_60], r12
000026AA  66 89 4D 60  mov     [rbp+0E0h+var_80], cx
000026AE  4C 89 7D 68  mov     [rbp+0E0h+var_78], r15
000026B2  66 89 4D 48  mov     [rbp+0E0h+var_98], cx
000026B6  4C 89 75 50  mov     [rbp+0E0h+var_90], r14
000026BA  66 89 4D 30  mov     [rbp+0E0h+var_B0], cx
000026BE  48 8B 85 10 01 00 00  mov     rax, [rbp+0E0h+arg_20]
000026C5  48 89 45 38  mov     [rbp+0E0h+var_A8], rax
000026C9  66 89 4D 18  mov     [rbp+0E0h+var_C8], cx
000026CD  48 8B 85 18 01 00 00  mov     rax, [rbp+0E0h+arg_28]
000026D4  48 89 45 20  mov     [rbp+0E0h+var_C0], rax
000026D8  66 89 4D 00  mov     [rbp+0E0h+var_E0], cx
000026DC  48 8B 85 20 01 00 00  mov     rax, [rbp+0E0h+arg_30]
000026E3  48 89 45 08  mov     [rbp+0E0h+var_D8], rax
000026E7  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
000026ED  66 44 89 45 E8  mov     [rbp+0E0h+var_F8], r8w
000026F2  8B 85 28 01 00 00  mov     eax, [rbp+0E0h+arg_38]
000026F8  89 45 F0  mov     [rbp+0E0h+var_F0], eax
000026FB  66 44 89 45 D0  mov     [rbp+0E0h+var_110], r8w
00002700  8B 85 30 01 00 00  mov     eax, [rbp+0E0h+arg_40]
00002706  89 45 D8  mov     [rbp+0E0h+var_108], eax
00002709  33 D2  xor     edx, edx; int
0000270B  48 8D 4C 24 78  lea     rcx, [rsp+1E0h+pvarg]; this
00002710  E8 E2 23 00 00  call    COleVariant::COleVariant(long,ushort)
00002715  90  nop
00002716  48 8B 1F  mov     rbx, [rdi]
00002719  FF 15 41 49 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000271F  44 8B C8  mov     r9d, eax
00002722  48 8D 44 24 54  lea     rax, [rsp+1E0h+var_18C]
00002727  48 89 44 24 40  mov     [rsp+1E0h+var_1A0], rax
0000272C  48 8D 45 90  lea     rax, [rbp+0E0h+var_150]
00002730  48 89 44 24 38  mov     [rsp+1E0h+var_1A8], rax
00002735  48 8D 44 24 78  lea     rax, [rsp+1E0h+pvarg]
0000273A  48 89 44 24 30  mov     [rsp+1E0h+var_1B0], rax
0000273F  48 8D 44 24 60  lea     rax, [rsp+1E0h+var_180]
00002744  48 89 44 24 28  mov     [rsp+1E0h+var_1B8], rax
00002749  66 C7 44 24 20 01 00  mov     word ptr [rsp+1E0h+var_1C0], 1
00002750  4C 8D 05 A1 5B 00 00  lea     r8, unk_1800082F8
00002757  8B 54 24 50  mov     edx, [rsp+1E0h+var_190]
0000275B  48 8B CF  mov     rcx, rdi
0000275E  FF 53 30  call    qword ptr [rbx+30h]
00002761  85 C0  test    eax, eax
00002763  0F 49 75 80  cmovns  esi, dword ptr [rbp+0E0h+pvarg+8]
00002767  48 8B 17  mov     rdx, [rdi]
0000276A  48 8B CF  mov     rcx, rdi
0000276D  FF 52 10  call    qword ptr [rdx+10h]
00002770  90  nop
00002771  48 8D 4C 24 78  lea     rcx, [rsp+1E0h+pvarg]; pvarg
00002776  FF 15 54 49 00 00  call    cs:__imp_VariantClear
0000277C  8B C6  mov     eax, esi
0000277E  48 8B 8D B0 00 00 00  mov     rcx, [rbp+0E0h+var_30]
00002785  48 33 CC  xor     rcx, rsp; StackCookie
00002788  E8 13 2B 00 00  call    __security_check_cookie
0000278D  4C 8D 9C 24 C0 01 00 00  lea     r11, [rsp+1E0h+var_20]
00002795  49 8B 5B 30  mov     rbx, [r11+30h]
00002799  49 8B 73 38  mov     rsi, [r11+38h]
0000279D  49 8B 7B 40  mov     rdi, [r11+40h]
000027A1  49 8B E3  mov     rsp, r11
000027A4  41 5F  pop     r15
000027A6  41 5E  pop     r14
000027A8  41 5D  pop     r13
000027AA  41 5C  pop     r12
000027AC  5D  pop     rbp
000027AD  C3  retn

; FUNC 000027B0-000029EA sub_1800027B0 (570 bytes)
000027B0  48 89 5C 24 08  mov     [rsp-8+arg_0], rbx
000027B5  48 89 74 24 10  mov     [rsp-8+arg_8], rsi
000027BA  48 89 7C 24 18  mov     [rsp-8+arg_10], rdi
000027BF  55  push    rbp
000027C0  41 54  push    r12
000027C2  41 55  push    r13
000027C4  41 56  push    r14
000027C6  41 57  push    r15
000027C8  48 8D AC 24 20 FF FF FF  lea     rbp, [rsp-0E0h]
000027D0  48 81 EC E0 01 00 00  sub     rsp, 1E0h
000027D7  48 8B 05 0A 8C 00 00  mov     rax, cs:__security_cookie
000027DE  48 33 C4  xor     rax, rsp
000027E1  48 89 85 D0 00 00 00  mov     [rbp+100h+var_30], rax
000027E8  4D 8B F9  mov     r15, r9
000027EB  4D 8B E0  mov     r12, r8
000027EE  4C 8B EA  mov     r13, rdx
000027F1  48 89 4C 24 68  mov     [rsp+200h+var_198], rcx
000027F6  4C 8B B5 50 01 00 00  mov     r14, [rbp+100h+arg_40]
000027FD  E8 0E FC FF FF  call    sub_180002410
00002802  48 8B F8  mov     rdi, rax
00002805  48 85 C0  test    rax, rax
00002808  74 48  jz      short loc_180002852
0000280A  48 8D 05 97 4F 00 00  lea     rax, aShowopenmessag_0; "ShowOpenMessageBoxWithCheckBox"
00002811  48 89 44 24 60  mov     [rsp+200h+var_1A0], rax
00002816  48 8B 1F  mov     rbx, [rdi]
00002819  FF 15 41 48 00 00  call    cs:GetUserDefaultLCID; KERNEL32
0000281F  48 8D 4C 24 54  lea     rcx, [rsp+200h+var_1AC]
00002824  48 89 4C 24 28  mov     [rsp+200h+var_1D8], rcx
00002829  89 44 24 20  mov     [rsp+200h+var_1E0], eax
0000282D  41 B9 01 00 00 00  mov     r9d, 1
00002833  4C 8D 44 24 60  lea     r8, [rsp+200h+var_1A0]
00002838  48 8D 15 B9 5A 00 00  lea     rdx, unk_1800082F8
0000283F  48 8B CF  mov     rcx, rdi
00002842  FF 53 28  call    qword ptr [rbx+28h]
00002845  85 C0  test    eax, eax
00002847  79 10  jns     short loc_180002859
00002849  48 8B 07  mov     rax, [rdi]
0000284C  48 8B CF  mov     rcx, rdi
0000284F  FF 50 10  call    qword ptr [rax+10h]
00002852  33 C0  xor     eax, eax
00002854  E9 61 01 00 00  jmp     loc_1800029BA
00002859  33 F6  xor     esi, esi
0000285B  48 89 74 24 78  mov     [rsp+200h+var_188], rsi
00002860  48 C7 45 80 0A 00 00 00  mov     [rbp+100h+var_180], 0Ah
00002868  48 8D 45 E0  lea     rax, [rbp+100h+var_120]
0000286C  48 89 44 24 70  mov     [rsp+200h+var_190], rax
00002871  8B DE  mov     ebx, esi
00002873  0F 1F 40 00  nop     dword ptr [rax+00h]
00002877  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00002880  8B C3  mov     eax, ebx
00002882  48 8D 0C 40  lea     rcx, [rax+rax*2]
00002886  48 8D 45 E0  lea     rax, [rbp+100h+var_120]
0000288A  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
0000288E  FF 15 5C 48 00 00  call    cs:VariantInit
00002894  FF C3  inc     ebx
00002896  3B 5D 80  cmp     ebx, dword ptr [rbp+100h+var_180]
00002899  72 E5  jb      short loc_180002880
0000289B  C7 44 24 50 FF FF FF FF  mov     [rsp+200h+var_1B0], 0FFFFFFFFh
000028A3  B9 08 00 00 00  mov     ecx, 8
000028A8  66 89 8D B8 00 00 00  mov     [rbp+100h+var_48], cx
000028AF  48 8B 44 24 68  mov     rax, [rsp+200h+var_198]
000028B4  48 89 85 C0 00 00 00  mov     [rbp+100h+var_40], rax
000028BB  66 89 8D A0 00 00 00  mov     [rbp+100h+var_60], cx
000028C2  4C 89 AD A8 00 00 00  mov     [rbp+100h+var_58], r13
000028C9  66 89 8D 88 00 00 00  mov     [rbp+100h+var_78], cx
000028D0  4C 89 A5 90 00 00 00  mov     [rbp+100h+var_70], r12
000028D7  66 89 4D 70  mov     [rbp+100h+var_90], cx
000028DB  4C 89 7D 78  mov     [rbp+100h+var_88], r15
000028DF  66 89 4D 58  mov     [rbp+100h+var_A8], cx
000028E3  48 8B 85 30 01 00 00  mov     rax, [rbp+100h+arg_20]
000028EA  48 89 45 60  mov     [rbp+100h+var_A0], rax
000028EE  66 89 4D 40  mov     [rbp+100h+var_C0], cx
000028F2  48 8B 85 38 01 00 00  mov     rax, [rbp+100h+arg_28]
000028F9  48 89 45 48  mov     [rbp+100h+var_B8], rax
000028FD  66 89 4D 28  mov     [rbp+100h+var_D8], cx
00002901  48 8B 85 40 01 00 00  mov     rax, [rbp+100h+arg_30]
00002908  48 89 45 30  mov     [rbp+100h+var_D0], rax
0000290C  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00002912  66 44 89 45 10  mov     [rbp+100h+var_F0], r8w
00002917  8B 85 48 01 00 00  mov     eax, [rbp+100h+arg_38]
0000291D  89 45 18  mov     [rbp+100h+var_E8], eax
00002920  B8 16 40 00 00  mov     eax, 4016h
00002925  66 89 45 F8  mov     [rbp+100h+var_108], ax
00002929  48 8D 44 24 50  lea     rax, [rsp+200h+var_1B0]
0000292E  48 89 45 00  mov     [rbp+100h+var_100], rax
00002932  66 44 89 45 E0  mov     [rbp+100h+var_120], r8w
00002937  8B 85 58 01 00 00  mov     eax, [rbp+100h+arg_48]
0000293D  89 45 E8  mov     [rbp+100h+var_118], eax
00002940  33 D2  xor     edx, edx; int
00002942  48 8D 4D 88  lea     rcx, [rbp+100h+pvarg]; this
00002946  E8 AC 21 00 00  call    COleVariant::COleVariant(long,ushort)
0000294B  90  nop
0000294C  48 8B 1F  mov     rbx, [rdi]
0000294F  FF 15 0B 47 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002955  44 8B C8  mov     r9d, eax
00002958  48 8D 44 24 58  lea     rax, [rsp+200h+var_1A8]
0000295D  48 89 44 24 40  mov     [rsp+200h+var_1C0], rax
00002962  48 8D 45 A0  lea     rax, [rbp+100h+var_160]
00002966  48 89 44 24 38  mov     [rsp+200h+var_1C8], rax
0000296B  48 8D 45 88  lea     rax, [rbp+100h+pvarg]
0000296F  48 89 44 24 30  mov     [rsp+200h+var_1D0], rax
00002974  48 8D 44 24 70  lea     rax, [rsp+200h+var_190]
00002979  48 89 44 24 28  mov     [rsp+200h+var_1D8], rax
0000297E  66 C7 44 24 20 01 00  mov     word ptr [rsp+200h+var_1E0], 1
00002985  4C 8D 05 6C 59 00 00  lea     r8, unk_1800082F8
0000298C  8B 54 24 54  mov     edx, [rsp+200h+var_1AC]
00002990  48 8B CF  mov     rcx, rdi
00002993  FF 53 30  call    qword ptr [rbx+30h]
00002996  85 C0  test    eax, eax
00002998  78 0A  js      short loc_1800029A4
0000299A  8B 75 90  mov     esi, dword ptr [rbp+100h+pvarg+8]
0000299D  8B 4C 24 50  mov     ecx, [rsp+200h+var_1B0]
000029A1  41 89 0E  mov     [r14], ecx
000029A4  48 8B 17  mov     rdx, [rdi]
000029A7  48 8B CF  mov     rcx, rdi
000029AA  FF 52 10  call    qword ptr [rdx+10h]
000029AD  90  nop
000029AE  48 8D 4D 88  lea     rcx, [rbp+100h+pvarg]; pvarg
000029B2  FF 15 18 47 00 00  call    cs:__imp_VariantClear
000029B8  8B C6  mov     eax, esi
000029BA  48 8B 8D D0 00 00 00  mov     rcx, [rbp+100h+var_30]
000029C1  48 33 CC  xor     rcx, rsp; StackCookie
000029C4  E8 D7 28 00 00  call    __security_check_cookie
000029C9  4C 8D 9C 24 E0 01 00 00  lea     r11, [rsp+200h+var_20]
000029D1  49 8B 5B 30  mov     rbx, [r11+30h]
000029D5  49 8B 73 38  mov     rsi, [r11+38h]
000029D9  49 8B 7B 40  mov     rdi, [r11+40h]
000029DD  49 8B E3  mov     rsp, r11
000029E0  41 5F  pop     r15
000029E2  41 5E  pop     r14
000029E4  41 5D  pop     r13
000029E6  41 5C  pop     r12
000029E8  5D  pop     rbp
000029E9  C3  retn

; FUNC 000029F0-00002B09 sub_1800029F0 (281 bytes)
000029F0  48 89 5C 24 18  mov     [rsp+arg_10], rbx
000029F5  55  push    rbp
000029F6  56  push    rsi
000029F7  57  push    rdi
000029F8  48 81 EC 80 00 00 00  sub     rsp, 80h
000029FF  E8 DC FA FF FF  call    sub_1800024E0
00002A04  48 8B F0  mov     rsi, rax
00002A07  48 85 C0  test    rax, rax
00002A0A  74 53  jz      short loc_180002A5F
00002A0C  48 8D 05 2D 4E 00 00  lea     rax, aShowresultsinc; "ShowResultsInconsistentDlg"
00002A13  48 89 84 24 A8 00 00 00  mov     [rsp+98h+arg_8], rax
00002A1B  48 8B 1E  mov     rbx, [rsi]
00002A1E  FF 15 3C 46 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002A24  48 8D 8C 24 A0 00 00 00  lea     rcx, [rsp+98h+arg_0]
00002A2C  48 89 4C 24 28  mov     [rsp+98h+var_70], rcx
00002A31  89 44 24 20  mov     [rsp+98h+var_78], eax
00002A35  BD 01 00 00 00  mov     ebp, 1
00002A3A  44 8B CD  mov     r9d, ebp
00002A3D  4C 8D 84 24 A8 00 00 00  lea     r8, [rsp+98h+arg_8]
00002A45  48 8D 15 AC 58 00 00  lea     rdx, unk_1800082F8
00002A4C  48 8B CE  mov     rcx, rsi
00002A4F  FF 53 28  call    qword ptr [rbx+28h]
00002A52  85 C0  test    eax, eax
00002A54  79 10  jns     short loc_180002A66
00002A56  48 8B 06  mov     rax, [rsi]
00002A59  48 8B CE  mov     rcx, rsi
00002A5C  FF 50 10  call    qword ptr [rax+10h]
00002A5F  33 C0  xor     eax, eax
00002A61  E9 90 00 00 00  jmp     loc_180002AF6
00002A66  0F 57 C0  xorps   xmm0, xmm0
00002A69  33 C0  xor     eax, eax
00002A6B  0F 11 44 24 68  movups  [rsp+98h+var_30], xmm0
00002A70  48 89 44 24 78  mov     [rsp+98h+var_20], rax
00002A75  48 8D 0D BC 4D 00 00  lea     rcx, psz; psz
00002A7C  FF 15 76 46 00 00  call    cs:SysAllocString
00002A82  33 FF  xor     edi, edi
00002A84  33 D2  xor     edx, edx; int
00002A86  44 8D 47 03  lea     r8d, [rdi+3]; unsigned __int16
00002A8A  48 8D 4C 24 50  lea     rcx, [rsp+98h+pvarg]; this
00002A8F  E8 63 20 00 00  call    COleVariant::COleVariant(long,ushort)
00002A94  90  nop
00002A95  48 8B 1E  mov     rbx, [rsi]
00002A98  FF 15 C2 45 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002A9E  44 8B C8  mov     r9d, eax
00002AA1  48 89 7C 24 40  mov     [rsp+98h+var_58], rdi
00002AA6  48 89 7C 24 38  mov     [rsp+98h+var_60], rdi
00002AAB  48 8D 44 24 50  lea     rax, [rsp+98h+pvarg]
00002AB0  48 89 44 24 30  mov     [rsp+98h+var_68], rax
00002AB5  48 8D 44 24 68  lea     rax, [rsp+98h+var_30]
00002ABA  48 89 44 24 28  mov     [rsp+98h+var_70], rax
00002ABF  66 89 6C 24 20  mov     word ptr [rsp+98h+var_78], bp
00002AC4  4C 8D 05 2D 58 00 00  lea     r8, unk_1800082F8
00002ACB  8B 94 24 A0 00 00 00  mov     edx, [rsp+98h+arg_0]
00002AD2  48 8B CE  mov     rcx, rsi
00002AD5  FF 53 30  call    qword ptr [rbx+30h]
00002AD8  85 C0  test    eax, eax
00002ADA  0F 49 7C 24 58  cmovns  edi, dword ptr [rsp+98h+pvarg+8]
00002ADF  48 8B 16  mov     rdx, [rsi]
00002AE2  48 8B CE  mov     rcx, rsi
00002AE5  FF 52 10  call    qword ptr [rdx+10h]
00002AE8  90  nop
00002AE9  48 8D 4C 24 50  lea     rcx, [rsp+98h+pvarg]; pvarg
00002AEE  FF 15 DC 45 00 00  call    cs:__imp_VariantClear
00002AF4  8B C7  mov     eax, edi
00002AF6  48 8B 9C 24 B0 00 00 00  mov     rbx, [rsp+98h+arg_10]
00002AFE  48 81 C4 80 00 00 00  add     rsp, 80h
00002B05  5F  pop     rdi
00002B06  5E  pop     rsi
00002B07  5D  pop     rbp
00002B08  C3  retn

; FUNC 00002B10-00002DF7 sub_180002B10 (743 bytes)
00002B10  48 89 5C 24 18  mov     [rsp-8+arg_10], rbx
00002B15  55  push    rbp
00002B16  56  push    rsi
00002B17  57  push    rdi
00002B18  41 54  push    r12
00002B1A  41 55  push    r13
00002B1C  41 56  push    r14
00002B1E  41 57  push    r15
00002B20  48 8D AC 24 70 FF FF FF  lea     rbp, [rsp-90h]
00002B28  48 81 EC 90 01 00 00  sub     rsp, 190h
00002B2F  48 8B 05 B2 88 00 00  mov     rax, cs:__security_cookie
00002B36  48 33 C4  xor     rax, rsp
00002B39  48 89 85 80 00 00 00  mov     [rbp+0C0h+var_40], rax
00002B40  45 8B E9  mov     r13d, r9d
00002B43  44 89 44 24 50  mov     [rsp+1C0h+var_170], r8d
00002B48  4C 8B E2  mov     r12, rdx
00002B4B  48 8B F1  mov     rsi, rcx
00002B4E  E8 BD F8 FF FF  call    sub_180002410
00002B53  4C 8B F8  mov     r15, rax
00002B56  48 85 C0  test    rax, rax
00002B59  74 48  jz      short loc_180002BA3
00002B5B  48 8D 05 0E 4C 00 00  lea     rax, aShow3; "Show_3"
00002B62  48 89 44 24 70  mov     [rsp+1C0h+var_150], rax
00002B67  49 8B 1F  mov     rbx, [r15]
00002B6A  FF 15 F0 44 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002B70  48 8D 4C 24 54  lea     rcx, [rsp+1C0h+var_16C]
00002B75  48 89 4C 24 28  mov     qword ptr [rsp+1C0h+cchWideChar], rcx
00002B7A  89 44 24 20  mov     dword ptr [rsp+1C0h+lpWideCharStr], eax
00002B7E  41 B9 01 00 00 00  mov     r9d, 1
00002B84  4C 8D 44 24 70  lea     r8, [rsp+1C0h+var_150]
00002B89  48 8D 15 68 57 00 00  lea     rdx, unk_1800082F8
00002B90  49 8B CF  mov     rcx, r15
00002B93  FF 53 28  call    qword ptr [rbx+28h]
00002B96  85 C0  test    eax, eax
00002B98  79 10  jns     short loc_180002BAA
00002B9A  49 8B 07  mov     rax, [r15]
00002B9D  49 8B CF  mov     rcx, r15
00002BA0  FF 50 10  call    qword ptr [rax+10h]
00002BA3  33 C0  xor     eax, eax
00002BA5  E9 FB 01 00 00  jmp     loc_180002DA5
00002BAA  45 33 F6  xor     r14d, r14d
00002BAD  4C 89 75 80  mov     [rbp+0C0h+var_140], r14
00002BB1  48 C7 45 88 06 00 00 00  mov     [rbp+0C0h+var_138], 6
00002BB9  48 8D 45 F0  lea     rax, [rbp+0C0h+var_D0]
00002BBD  48 89 44 24 78  mov     [rsp+1C0h+var_148], rax
00002BC2  41 8B DE  mov     ebx, r14d
00002BC5  66 66 66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00002BD0  8B C3  mov     eax, ebx
00002BD2  48 8D 0C 40  lea     rcx, [rax+rax*2]
00002BD6  48 8D 45 F0  lea     rax, [rbp+0C0h+var_D0]
00002BDA  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00002BDE  FF 15 0C 45 00 00  call    cs:VariantInit
00002BE4  FF C3  inc     ebx
00002BE6  3B 5D 88  cmp     ebx, dword ptr [rbp+0C0h+var_138]
00002BE9  72 E5  jb      short loc_180002BD0
00002BEB  48 85 F6  test    rsi, rsi
00002BEE  74 66  jz      short loc_180002C56
00002BF0  44 89 74 24 28  mov     [rsp+1C0h+cchWideChar], r14d; cchWideChar
00002BF5  4C 89 74 24 20  mov     [rsp+1C0h+lpWideCharStr], r14; lpWideCharStr
00002BFA  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00002C00  4C 8B C6  mov     r8, rsi; lpMultiByteStr
00002C03  33 D2  xor     edx, edx; dwFlags
00002C05  33 C9  xor     ecx, ecx; CodePage
00002C07  FF 15 43 44 00 00  call    cs:MultiByteToWideChar; KERNEL32
00002C0D  8B D8  mov     ebx, eax
00002C0F  8D 50 FF  lea     edx, [rax-1]; ui
00002C12  33 C9  xor     ecx, ecx; strIn
00002C14  FF 15 BE 44 00 00  call    cs:SysAllocStringLen
00002C1A  48 8B F8  mov     rdi, rax
00002C1D  48 85 C0  test    rax, rax
00002C20  74 24  jz      short loc_180002C46
00002C22  89 5C 24 28  mov     [rsp+1C0h+cchWideChar], ebx; cchWideChar
00002C26  48 89 44 24 20  mov     [rsp+1C0h+lpWideCharStr], rax; lpWideCharStr
00002C2B  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00002C31  4C 8B C6  mov     r8, rsi; lpMultiByteStr
00002C34  33 D2  xor     edx, edx; dwFlags
00002C36  33 C9  xor     ecx, ecx; CodePage
00002C38  FF 15 12 44 00 00  call    cs:MultiByteToWideChar; KERNEL32
00002C3E  3B C3  cmp     eax, ebx
00002C40  0F 85 89 01 00 00  jnz     loc_180002DCF
00002C46  48 89 7C 24 58  mov     [rsp+1C0h+var_168], rdi
00002C4B  48 85 FF  test    rdi, rdi
00002C4E  0F 84 84 01 00 00  jz      loc_180002DD8
00002C54  EB 08  jmp     short loc_180002C5E
00002C56  49 8B FE  mov     rdi, r14
00002C59  4C 89 74 24 58  mov     [rsp+1C0h+var_168], r14
00002C5E  4D 85 E4  test    r12, r12
00002C61  74 66  jz      short loc_180002CC9
00002C63  44 89 74 24 28  mov     [rsp+1C0h+cchWideChar], r14d; cchWideChar
00002C68  4C 89 74 24 20  mov     [rsp+1C0h+lpWideCharStr], r14; lpWideCharStr
00002C6D  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00002C73  4D 8B C4  mov     r8, r12; lpMultiByteStr
00002C76  33 D2  xor     edx, edx; dwFlags
00002C78  33 C9  xor     ecx, ecx; CodePage
00002C7A  FF 15 D0 43 00 00  call    cs:MultiByteToWideChar; KERNEL32
00002C80  8B F0  mov     esi, eax
00002C82  8D 50 FF  lea     edx, [rax-1]; ui
00002C85  33 C9  xor     ecx, ecx; strIn
00002C87  FF 15 4B 44 00 00  call    cs:SysAllocStringLen
00002C8D  48 8B D8  mov     rbx, rax
00002C90  48 85 C0  test    rax, rax
00002C93  74 24  jz      short loc_180002CB9
00002C95  89 74 24 28  mov     [rsp+1C0h+cchWideChar], esi; cchWideChar
00002C99  48 89 44 24 20  mov     [rsp+1C0h+lpWideCharStr], rax; lpWideCharStr
00002C9E  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00002CA4  4D 8B C4  mov     r8, r12; lpMultiByteStr
00002CA7  33 D2  xor     edx, edx; dwFlags
00002CA9  33 C9  xor     ecx, ecx; CodePage
00002CAB  FF 15 9F 43 00 00  call    cs:MultiByteToWideChar; KERNEL32
00002CB1  3B C6  cmp     eax, esi
00002CB3  0F 85 2A 01 00 00  jnz     loc_180002DE3
00002CB9  48 89 5C 24 60  mov     [rsp+1C0h+var_160], rbx
00002CBE  48 85 DB  test    rbx, rbx
00002CC1  0F 84 25 01 00 00  jz      loc_180002DEC
00002CC7  EB 08  jmp     short loc_180002CD1
00002CC9  49 8B DE  mov     rbx, r14
00002CCC  48 89 5C 24 60  mov     [rsp+1C0h+var_160], rbx
00002CD1  B8 08 00 00 00  mov     eax, 8
00002CD6  66 89 45 68  mov     [rbp+0C0h+var_58], ax
00002CDA  48 89 7D 70  mov     [rbp+0C0h+var_50], rdi
00002CDE  66 89 45 50  mov     [rbp+0C0h+var_70], ax
00002CE2  48 89 5D 58  mov     [rbp+0C0h+var_68], rbx
00002CE6  41 B8 03 00 00 00  mov     r8d, 3; unsigned __int16
00002CEC  66 44 89 45 38  mov     [rbp+0C0h+var_88], r8w
00002CF1  8B 44 24 50  mov     eax, [rsp+1C0h+var_170]
00002CF5  89 45 40  mov     [rbp+0C0h+var_80], eax
00002CF8  66 44 89 45 20  mov     [rbp+0C0h+var_A0], r8w
00002CFD  44 89 6D 28  mov     [rbp+0C0h+var_98], r13d
00002D01  66 44 89 45 08  mov     [rbp+0C0h+var_B8], r8w
00002D06  8B 85 F0 00 00 00  mov     eax, [rbp+0C0h+arg_20]
00002D0C  89 45 10  mov     [rbp+0C0h+var_B0], eax
00002D0F  66 44 89 45 F0  mov     [rbp+0C0h+var_D0], r8w
00002D14  8B 85 F8 00 00 00  mov     eax, [rbp+0C0h+arg_28]
00002D1A  89 45 F8  mov     [rbp+0C0h+var_C8], eax
00002D1D  33 D2  xor     edx, edx; int
00002D1F  48 8D 4D 90  lea     rcx, [rbp+0C0h+pvarg]; this
00002D23  E8 CF 1D 00 00  call    COleVariant::COleVariant(long,ushort)
00002D28  90  nop
00002D29  49 8B 37  mov     rsi, [r15]
00002D2C  FF 15 2E 43 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002D32  44 8B C8  mov     r9d, eax
00002D35  48 8D 44 24 68  lea     rax, [rsp+1C0h+var_158]
00002D3A  48 89 44 24 40  mov     [rsp+1C0h+var_180], rax
00002D3F  48 8D 45 B0  lea     rax, [rbp+0C0h+var_110]
00002D43  48 89 44 24 38  mov     [rsp+1C0h+var_188], rax
00002D48  48 8D 45 90  lea     rax, [rbp+0C0h+pvarg]
00002D4C  48 89 44 24 30  mov     [rsp+1C0h+var_190], rax
00002D51  48 8D 44 24 78  lea     rax, [rsp+1C0h+var_148]
00002D56  48 89 44 24 28  mov     qword ptr [rsp+1C0h+cchWideChar], rax
00002D5B  66 C7 44 24 20 01 00  mov     word ptr [rsp+1C0h+lpWideCharStr], 1
00002D62  4C 8D 05 8F 55 00 00  lea     r8, unk_1800082F8
00002D69  8B 54 24 54  mov     edx, [rsp+1C0h+var_16C]
00002D6D  49 8B CF  mov     rcx, r15
00002D70  FF 56 30  call    qword ptr [rsi+30h]
00002D73  85 C0  test    eax, eax
00002D75  44 0F 49 75 98  cmovns  r14d, dword ptr [rbp+0C0h+pvarg+8]
00002D7A  49 8B 17  mov     rdx, [r15]
00002D7D  49 8B CF  mov     rcx, r15
00002D80  FF 52 10  call    qword ptr [rdx+10h]
00002D83  90  nop
00002D84  48 8D 4D 90  lea     rcx, [rbp+0C0h+pvarg]; pvarg
00002D88  FF 15 42 43 00 00  call    cs:__imp_VariantClear
00002D8E  90  nop
00002D8F  48 8B CB  mov     rcx, rbx; bstrString
00002D92  FF 15 48 43 00 00  call    cs:SysFreeString
00002D98  90  nop
00002D99  48 8B CF  mov     rcx, rdi; bstrString
00002D9C  FF 15 3E 43 00 00  call    cs:SysFreeString
00002DA2  41 8B C6  mov     eax, r14d
00002DA5  48 8B 8D 80 00 00 00  mov     rcx, [rbp+0C0h+var_40]
00002DAC  48 33 CC  xor     rcx, rsp; StackCookie
00002DAF  E8 EC 24 00 00  call    __security_check_cookie
00002DB4  48 8B 9C 24 E0 01 00 00  mov     rbx, [rsp+1C0h+arg_10]
00002DBC  48 81 C4 90 01 00 00  add     rsp, 190h
00002DC3  41 5F  pop     r15
00002DC5  41 5E  pop     r14
00002DC7  41 5D  pop     r13
00002DC9  41 5C  pop     r12
00002DCB  5F  pop     rdi
00002DCC  5E  pop     rsi
00002DCD  5D  pop     rbp
00002DCE  C3  retn
00002DCF  48 8B CF  mov     rcx, rdi; bstrString
00002DD2  FF 15 08 43 00 00  call    cs:SysFreeString
00002DD8  B9 0E 00 07 80  mov     ecx, 8007000Eh
00002DDD  E8 7E E2 FF FF  call    sub_180001060
00002DE2  90  db 90h
00002DE3  48 8B CB  mov     rcx, rbx; bstrString
00002DE6  FF 15 F4 42 00 00  call    cs:SysFreeString
00002DEC  B9 0E 00 07 80  mov     ecx, 8007000Eh
00002DF1  E8 6A E2 FF FF  call    sub_180001060
00002DF6  CC  db 0CCh

; FUNC 00002E00-00002F86 sub_180002E00 (390 bytes)
00002E00  40 53  push    rbx
00002E02  55  push    rbp
00002E03  56  push    rsi
00002E04  57  push    rdi
00002E05  41 56  push    r14
00002E07  48 81 EC E0 00 00 00  sub     rsp, 0E0h
00002E0E  4C 8B F1  mov     r14, rcx
00002E11  E8 CA F6 FF FF  call    sub_1800024E0
00002E16  48 8B F8  mov     rdi, rax
00002E19  48 85 C0  test    rax, rax
00002E1C  74 4D  jz      short loc_180002E6B
00002E1E  48 8D 05 53 4A 00 00  lea     rax, aShowtpsarupgra; "ShowTPSARUpgradeDialog"
00002E25  48 89 44 24 50  mov     [rsp+108h+var_B8], rax
00002E2A  48 8B 1F  mov     rbx, [rdi]
00002E2D  FF 15 2D 42 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002E33  48 8D 8C 24 20 01 00 00  lea     rcx, [rsp+108h+arg_10]
00002E3B  48 89 4C 24 28  mov     [rsp+108h+var_E0], rcx
00002E40  89 44 24 20  mov     [rsp+108h+var_E8], eax
00002E44  BD 01 00 00 00  mov     ebp, 1
00002E49  44 8B CD  mov     r9d, ebp
00002E4C  4C 8D 44 24 50  lea     r8, [rsp+108h+var_B8]
00002E51  48 8D 15 A0 54 00 00  lea     rdx, unk_1800082F8
00002E58  48 8B CF  mov     rcx, rdi
00002E5B  FF 53 28  call    qword ptr [rbx+28h]
00002E5E  85 C0  test    eax, eax
00002E60  79 19  jns     short loc_180002E7B
00002E62  48 8B 07  mov     rax, [rdi]
00002E65  48 8B CF  mov     rcx, rdi
00002E68  FF 50 10  call    qword ptr [rax+10h]
00002E6B  33 C0  xor     eax, eax
00002E6D  48 81 C4 E0 00 00 00  add     rsp, 0E0h
00002E74  41 5E  pop     r14
00002E76  5F  pop     rdi
00002E77  5E  pop     rsi
00002E78  5D  pop     rbp
00002E79  5B  pop     rbx
00002E7A  C3  retn
00002E7B  33 F6  xor     esi, esi
00002E7D  48 89 74 24 60  mov     [rsp+108h+var_A8], rsi
00002E82  48 89 6C 24 68  mov     [rsp+108h+var_A0], rbp
00002E87  48 8D 44 24 70  lea     rax, [rsp+108h+var_98]
00002E8C  48 89 44 24 58  mov     [rsp+108h+var_B0], rax
00002E91  8B DE  mov     ebx, esi
00002E93  0F 1F 40 00  nop     dword ptr [rax+00h]
00002E97  66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00002EA0  8B C3  mov     eax, ebx
00002EA2  48 8D 0C 40  lea     rcx, [rax+rax*2]
00002EA6  48 8D 44 24 70  lea     rax, [rsp+108h+var_98]
00002EAB  48 8D 0C C8  lea     rcx, [rax+rcx*8]; pvarg
00002EAF  FF 15 3B 42 00 00  call    cs:VariantInit
00002EB5  FF C3  inc     ebx
00002EB7  3B 5C 24 68  cmp     ebx, dword ptr [rsp+108h+var_A0]
00002EBB  72 E3  jb      short loc_180002EA0
00002EBD  C7 84 24 18 01 00 00 FF FF FF FF  mov     [rsp+108h+arg_8], 0FFFFFFFFh
00002EC8  B8 03 40 00 00  mov     eax, 4003h
00002ECD  66 89 44 24 70  mov     [rsp+108h+var_98], ax
00002ED2  48 8D 84 24 18 01 00 00  lea     rax, [rsp+108h+arg_8]
00002EDA  48 89 44 24 78  mov     [rsp+108h+var_90], rax
00002EDF  33 D2  xor     edx, edx; int
00002EE1  44 8D 42 03  lea     r8d, [rdx+3]; unsigned __int16
00002EE5  48 8D 8C 24 88 00 00 00  lea     rcx, [rsp+108h+pvarg]; this
00002EED  E8 05 1C 00 00  call    COleVariant::COleVariant(long,ushort)
00002EF2  90  nop
00002EF3  48 8B 1F  mov     rbx, [rdi]
00002EF6  FF 15 64 41 00 00  call    cs:GetUserDefaultLCID; KERNEL32
00002EFC  44 8B C8  mov     r9d, eax
00002EFF  48 8D 84 24 28 01 00 00  lea     rax, [rsp+108h+arg_18]
00002F07  48 89 44 24 40  mov     [rsp+108h+var_C8], rax
00002F0C  48 8D 84 24 A0 00 00 00  lea     rax, [rsp+108h+var_68]
00002F14  48 89 44 24 38  mov     [rsp+108h+var_D0], rax
00002F19  48 8D 84 24 88 00 00 00  lea     rax, [rsp+108h+pvarg]
00002F21  48 89 44 24 30  mov     [rsp+108h+var_D8], rax
00002F26  48 8D 44 24 58  lea     rax, [rsp+108h+var_B0]
00002F2B  48 89 44 24 28  mov     [rsp+108h+var_E0], rax
00002F30  66 89 6C 24 20  mov     word ptr [rsp+108h+var_E8], bp
00002F35  4C 8D 05 BC 53 00 00  lea     r8, unk_1800082F8
00002F3C  8B 94 24 20 01 00 00  mov     edx, [rsp+108h+arg_10]
00002F43  48 8B CF  mov     rcx, rdi
00002F46  FF 53 30  call    qword ptr [rbx+30h]
00002F49  85 C0  test    eax, eax
00002F4B  78 11  js      short loc_180002F5E
00002F4D  8B B4 24 90 00 00 00  mov     esi, dword ptr [rsp+108h+pvarg+8]
00002F54  8B 8C 24 18 01 00 00  mov     ecx, [rsp+108h+arg_8]
00002F5B  41 89 0E  mov     [r14], ecx
00002F5E  48 8B 17  mov     rdx, [rdi]
00002F61  48 8B CF  mov     rcx, rdi
00002F64  FF 52 10  call    qword ptr [rdx+10h]
00002F67  90  nop
00002F68  48 8D 8C 24 88 00 00 00  lea     rcx, [rsp+108h+pvarg]; pvarg
00002F70  FF 15 5A 41 00 00  call    cs:__imp_VariantClear
00002F76  8B C6  mov     eax, esi
00002F78  48 81 C4 E0 00 00 00  add     rsp, 0E0h
00002F7F  41 5E  pop     r14
00002F81  5F  pop     rdi
00002F82  5E  pop     rsi
00002F83  5D  pop     rbp
00002F84  5B  pop     rbx
00002F85  C3  retn

; FUNC 00002F90-00002FB1 sub_180002F90 (33 bytes)
00002F90  48 83 EC 28  sub     rsp, 28h
00002F94  48 8D 0D 05 4B 00 00  lea     rcx, aDontshowupward; "DontShowUpward"
00002F9B  E8 F1 1A 00 00  call    GetGlobalPointer
00002FA0  48 85 C0  test    rax, rax
00002FA3  75 05  jnz     short loc_180002FAA
00002FA5  48 83 C4 28  add     rsp, 28h
00002FA9  C3  retn
00002FAA  8B 00  mov     eax, [rax]
00002FAC  48 83 C4 28  add     rsp, 28h
00002FB0  C3  retn

; FUNC 00002FC0-00002FEF DllMain (47 bytes)
00002FC0  40 53  push    rbx
00002FC2  48 83 EC 20  sub     rsp, 20h
00002FC6  48 8B D9  mov     rbx, rcx
00002FC9  83 FA 01  cmp     edx, 1
00002FCC  75 16  jnz     short loc_180002FE4
00002FCE  48 8B D1  mov     rdx, rcx; HINSTANCE
00002FD1  48 8D 0D E0 85 00 00  lea     rcx, unk_18000B5B8; struct AFX_EXTENSION_MODULE *
00002FD8  E8 14 1B 00 00  call    AfxInitExtensionModule(AFX_EXTENSION_MODULE &,HINSTANCE__ *)
00002FDD  48 89 1D C4 85 00 00  mov     cs:qword_18000B5A8, rbx
00002FE4  B8 01 00 00 00  mov     eax, 1
00002FE9  48 83 C4 20  add     rsp, 20h
00002FED  5B  pop     rbx
00002FEE  C3  retn

; FUNC 00002FF0-00003026 FindComponentInitExtDLL (54 bytes)
00002FF0  48 83 EC 28  sub     rsp, 28h
00002FF4  B9 80 00 00 00  mov     ecx, 80h; unsigned __int64
00002FF9  E8 B7 1A 00 00  call    operator new(unsigned __int64)
00002FFE  48 85 C0  test    rax, rax
00003001  74 12  jz      short loc_180003015
00003003  45 33 C0  xor     r8d, r8d; int
00003006  48 8D 15 AB 85 00 00  lea     rdx, unk_18000B5B8; struct AFX_EXTENSION_MODULE *
0000300D  48 8B C8  mov     rcx, rax; this
00003010  E8 D6 1A 00 00  call    CDynLinkLibrary::CDynLinkLibrary(AFX_EXTENSION_MODULE &,int)
00003015  E8 AD 1A 00 00  call    AfxGetModuleState(void)
0000301A  48 89 05 BF 85 00 00  mov     cs:qword_18000B5E0, rax
00003021  48 83 C4 28  add     rsp, 28h
00003025  C3  retn

; FUNC 00003030-00003038 __local_stdio_printf_options (8 bytes)
00003030  48 8D 05 D1 85 00 00  lea     rax, unsigned __int64 `__local_stdio_printf_options'::`2'::_OptionsStorage
00003037  C3  retn

; FUNC 00003040-000031D0 gxAskReconcile (400 bytes)
00003040  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003045  48 89 6C 24 18  mov     [rsp+arg_10], rbp
0000304A  48 89 74 24 20  mov     [rsp+arg_18], rsi
0000304F  57  push    rdi
00003050  48 83 EC 40  sub     rsp, 40h
00003054  48 8B E9  mov     rbp, rcx
00003057  48 8B 15 82 85 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
0000305E  48 85 D2  test    rdx, rdx
00003061  75 08  jnz     short loc_18000306B
00003063  8D 42 01  lea     eax, [rdx+1]
00003066  E9 3C 01 00 00  jmp     loc_1800031A7
0000306B  48 8D 4C 24 30  lea     rcx, [rsp+48h+var_18]; this
00003070  E8 58 1A 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003075  48 8B 1D 2C 85 00 00  mov     rbx, cs:qword_18000B5A8
0000307C  E8 46 1A 00 00  call    AfxGetModuleState(void)
00003081  48 8B 78 18  mov     rdi, [rax+18h]
00003085  E8 3D 1A 00 00  call    AfxGetModuleState(void)
0000308A  48 89 58 18  mov     [rax+18h], rbx
0000308E  E8 52 1A 00 00  call    AfxGetThread(void)
00003093  48 85 C0  test    rax, rax
00003096  0F 84 F1 00 00 00  jz      loc_18000318D
0000309C  48 8B 10  mov     rdx, [rax]
0000309F  48 8B C8  mov     rcx, rax
000030A2  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
000030A8  48 85 C0  test    rax, rax
000030AB  0F 84 DC 00 00 00  jz      loc_18000318D
000030B1  33 C0  xor     eax, eax
000030B3  89 44 24 28  mov     [rsp+48h+cchWideChar], eax; cchWideChar
000030B7  48 89 44 24 20  mov     [rsp+48h+lpWideCharStr], rax; lpWideCharStr
000030BC  44 8D 48 FF  lea     r9d, [rax-1]; cbMultiByte
000030C0  4C 8D 05 F9 49 00 00  lea     r8, aBlock; "Block "
000030C7  33 D2  xor     edx, edx; dwFlags
000030C9  33 C9  xor     ecx, ecx; CodePage
000030CB  FF 15 7F 3F 00 00  call    cs:MultiByteToWideChar; KERNEL32
000030D1  8B F0  mov     esi, eax
000030D3  8D 50 FF  lea     edx, [rax-1]; ui
000030D6  33 C9  xor     ecx, ecx; strIn
000030D8  FF 15 FA 3F 00 00  call    cs:SysAllocStringLen
000030DE  48 8B D8  mov     rbx, rax
000030E1  48 85 C0  test    rax, rax
000030E4  74 28  jz      short loc_18000310E
000030E6  89 74 24 28  mov     [rsp+48h+cchWideChar], esi; cchWideChar
000030EA  48 89 44 24 20  mov     [rsp+48h+lpWideCharStr], rax; lpWideCharStr
000030EF  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
000030F5  4C 8D 05 C4 49 00 00  lea     r8, aBlock; "Block "
000030FC  33 D2  xor     edx, edx; dwFlags
000030FE  33 C9  xor     ecx, ecx; CodePage
00003100  FF 15 4A 3F 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003106  3B C6  cmp     eax, esi
00003108  0F 85 AE 00 00 00  jnz     loc_1800031BC
0000310E  48 89 5C 24 58  mov     [rsp+48h+bstrString], rbx
00003113  48 85 DB  test    rbx, rbx
00003116  0F 84 A9 00 00 00  jz      loc_1800031C5
0000311C  48 8B D5  mov     rdx, rbp
0000311F  48 8D 4C 24 58  lea     rcx, [rsp+48h+bstrString]
00003124  E8 B7 E0 FF FF  call    sub_1800011E0
00003129  48 8D 15 98 49 00 00  lea     rdx, aHasErrorsOrWar; " has errors or warnings. Do you wish to"...
00003130  48 8D 4C 24 58  lea     rcx, [rsp+48h+bstrString]
00003135  E8 A6 E0 FF FF  call    sub_1800011E0
0000313A  48 8B 5C 24 58  mov     rbx, [rsp+48h+bstrString]
0000313F  48 8B D3  mov     rdx, rbx
00003142  48 8D 4C 24 58  lea     rcx, [rsp+48h+bstrString]
00003147  FF 15 63 44 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(wchar_t const *)
0000314D  C7 44 24 28 02 00 00 00  mov     [rsp+48h+cchWideChar], 2; int
00003155  C7 44 24 20 20 00 00 00  mov     dword ptr [rsp+48h+lpWideCharStr], 20h ; ' '; int
0000315D  41 B9 0E 00 00 00  mov     r9d, 0Eh
00003163  45 33 C0  xor     r8d, r8d
00003166  48 8D 15 93 49 00 00  lea     rdx, aReconcileBlock; "Reconcile blocks with errors or warning"...
0000316D  48 8B 08  mov     rcx, [rax]; lpMultiByteStr
00003170  E8 9B F9 FF FF  call    sub_180002B10
00003175  8B F0  mov     esi, eax
00003177  48 8D 4C 24 58  lea     rcx, [rsp+48h+bstrString]
0000317C  FF 15 26 44 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(void)
00003182  48 8B CB  mov     rcx, rbx; bstrString
00003185  FF 15 55 3F 00 00  call    cs:SysFreeString
0000318B  EB 05  jmp     short loc_180003192
0000318D  BE 01 00 00 00  mov     esi, 1
00003192  E8 30 19 00 00  call    AfxGetModuleState(void)
00003197  48 89 78 18  mov     [rax+18h], rdi
0000319B  48 8D 4C 24 30  lea     rcx, [rsp+48h+var_18]; this
000031A0  E8 2E 19 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
000031A5  8B C6  mov     eax, esi
000031A7  48 8B 5C 24 50  mov     rbx, [rsp+48h+arg_0]
000031AC  48 8B 6C 24 60  mov     rbp, [rsp+48h+arg_10]
000031B1  48 8B 74 24 68  mov     rsi, [rsp+48h+arg_18]
000031B6  48 83 C4 40  add     rsp, 40h
000031BA  5F  pop     rdi
000031BB  C3  retn
000031BC  48 8B CB  mov     rcx, rbx; bstrString
000031BF  FF 15 1B 3F 00 00  call    cs:SysFreeString
000031C5  B9 0E 00 07 80  mov     ecx, 8007000Eh
000031CA  E8 91 DE FF FF  call    sub_180001060
000031CF  CC  align 10h

; FUNC 000031D0-0000325B gxElectrolyteWizard (139 bytes)
000031D0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000031D5  57  push    rdi
000031D6  48 83 EC 30  sub     rsp, 30h
000031DA  48 8B 15 FF 83 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
000031E1  48 85 D2  test    rdx, rdx
000031E4  74 68  jz      short loc_18000324E
000031E6  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
000031EB  E8 DD 18 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
000031F0  48 8B 3D B1 83 00 00  mov     rdi, cs:qword_18000B5A8
000031F7  E8 CB 18 00 00  call    AfxGetModuleState(void)
000031FC  48 8B 58 18  mov     rbx, [rax+18h]
00003200  E8 C2 18 00 00  call    AfxGetModuleState(void)
00003205  48 89 78 18  mov     [rax+18h], rdi
00003209  E8 D7 18 00 00  call    AfxGetThread(void)
0000320E  48 85 C0  test    rax, rax
00003211  74 28  jz      short loc_18000323B
00003213  48 8B 10  mov     rdx, [rax]
00003216  48 8B C8  mov     rcx, rax
00003219  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
0000321F  48 85 C0  test    rax, rax
00003222  74 17  jz      short loc_18000323B
00003224  C7 05 BE 83 00 00 00 00 00 00  mov     cs:dword_18000B5EC, 0
0000322E  E8 CD F1 FF FF  call    sub_180002400
00003233  8B C8  mov     ecx, eax
00003235  E8 56 E2 FF FF  call    sub_180001490
0000323A  90  nop
0000323B  E8 87 18 00 00  call    AfxGetModuleState(void)
00003240  48 89 58 18  mov     [rax+18h], rbx
00003244  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003249  E8 85 18 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
0000324E  33 C0  xor     eax, eax
00003250  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00003255  48 83 C4 30  add     rsp, 30h
00003259  5F  pop     rdi
0000325A  C3  retn

; FUNC 00003260-00003323 gxFindTemplate (195 bytes)
00003260  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003265  48 89 6C 24 10  mov     [rsp+arg_8], rbp
0000326A  48 89 74 24 18  mov     [rsp+arg_10], rsi
0000326F  57  push    rdi
00003270  48 81 EC 70 02 00 00  sub     rsp, 270h
00003277  48 8B F2  mov     rsi, rdx
0000327A  48 8B E9  mov     rbp, rcx
0000327D  48 8B 15 5C 83 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003284  48 85 D2  test    rdx, rdx
00003287  75 04  jnz     short loc_18000328D
00003289  33 C0  xor     eax, eax
0000328B  EB 7D  jmp     short loc_18000330A
0000328D  48 8D 4C 24 20  lea     rcx, [rsp+278h+var_258]; this
00003292  E8 36 18 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003297  48 8B 3D 0A 83 00 00  mov     rdi, cs:qword_18000B5A8
0000329E  E8 24 18 00 00  call    AfxGetModuleState(void)
000032A3  48 8B 58 18  mov     rbx, [rax+18h]
000032A7  E8 1B 18 00 00  call    AfxGetModuleState(void)
000032AC  48 89 78 18  mov     [rax+18h], rdi
000032B0  48 C7 06 00 00 00 00  mov     qword ptr [rsi], 0
000032B7  45 33 C0  xor     r8d, r8d
000032BA  48 8B D5  mov     rdx, rbp
000032BD  48 8D 4C 24 30  lea     rcx, [rsp+278h+var_248]
000032C2  E8 F9 10 00 00  call    sub_1800043C0
000032C7  48 8D 4C 24 30  lea     rcx, [rsp+278h+var_248]; this
000032CC  E8 BA 17 00 00  call    CMMDialog::DoModal(void)
000032D1  48 8B 8C 24 78 01 00 00  mov     rcx, [rsp+278h+var_100]
000032D9  48 89 0E  mov     [rsi], rcx
000032DC  BF FF FF FF FF  mov     edi, 0FFFFFFFFh
000032E1  48 3D FF FF FF 7F  cmp     rax, 7FFFFFFFh
000032E7  0F 46 F8  cmovbe  edi, eax
000032EA  48 8D 4C 24 30  lea     rcx, [rsp+278h+var_248]; this
000032EF  E8 6C 11 00 00  call    sub_180004460
000032F4  90  nop
000032F5  E8 CD 17 00 00  call    AfxGetModuleState(void)
000032FA  48 89 58 18  mov     [rax+18h], rbx
000032FE  48 8D 4C 24 20  lea     rcx, [rsp+278h+var_258]; this
00003303  E8 CB 17 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003308  8B C7  mov     eax, edi
0000330A  4C 8D 9C 24 70 02 00 00  lea     r11, [rsp+278h+var_8]
00003312  49 8B 5B 10  mov     rbx, [r11+10h]
00003316  49 8B 6B 18  mov     rbp, [r11+18h]
0000331A  49 8B 73 20  mov     rsi, [r11+20h]
0000331E  49 8B E3  mov     rsp, r11
00003321  5F  pop     rdi
00003322  C3  retn

; FUNC 00003330-00003374 gxOpen_message_box (68 bytes)
00003330  48 83 EC 58  sub     rsp, 58h
00003334  8B 84 24 98 00 00 00  mov     eax, [rsp+58h+arg_38]
0000333B  89 44 24 40  mov     [rsp+58h+var_18], eax
0000333F  89 44 24 38  mov     [rsp+58h+var_20], eax
00003343  48 8B 84 24 90 00 00 00  mov     rax, [rsp+58h+arg_30]
0000334B  48 89 44 24 30  mov     [rsp+58h+var_28], rax
00003350  48 8B 84 24 88 00 00 00  mov     rax, [rsp+58h+arg_28]
00003358  48 89 44 24 28  mov     [rsp+58h+var_30], rax
0000335D  48 8B 84 24 80 00 00 00  mov     rax, [rsp+58h+arg_20]
00003365  48 89 44 24 20  mov     [rsp+58h+var_38], rax
0000336A  E8 11 00 00 00  call    gxOpen_message_box2
0000336F  48 83 C4 58  add     rsp, 58h
00003373  C3  retn

; FUNC 00003380-00003843 gxOpen_message_box2 (1219 bytes)
00003380  4C 89 44 24 18  mov     [rsp+arg_10], r8
00003385  48 89 54 24 10  mov     [rsp+arg_8], rdx
0000338A  48 89 4C 24 08  mov     [rsp+arg_0], rcx
0000338F  56  push    rsi
00003390  48 81 EC A0 00 00 00  sub     rsp, 0A0h
00003397  48 8B 15 42 82 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
0000339E  49 8B F1  mov     rsi, r9
000033A1  48 85 D2  test    rdx, rdx
000033A4  75 0B  jnz     short loc_1800033B1
000033A6  33 C0  xor     eax, eax
000033A8  48 81 C4 A0 00 00 00  add     rsp, 0A0h
000033AF  5E  pop     rsi
000033B0  C3  retn
000033B1  48 89 9C 24 C8 00 00 00  mov     [rsp+0A8h+arg_18], rbx
000033B9  48 8D 4C 24 58  lea     rcx, [rsp+0A8h+var_50]; this
000033BE  48 89 AC 24 98 00 00 00  mov     [rsp+0A8h+var_10], rbp
000033C6  48 89 BC 24 90 00 00 00  mov     [rsp+0A8h+var_18], rdi
000033CE  4C 89 A4 24 88 00 00 00  mov     [rsp+0A8h+var_20], r12
000033D6  4C 89 AC 24 80 00 00 00  mov     [rsp+0A8h+var_28], r13
000033DE  4C 89 74 24 78  mov     [rsp+0A8h+var_30], r14
000033E3  4C 89 7C 24 70  mov     [rsp+0A8h+var_38], r15
000033E8  E8 E0 16 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
000033ED  E8 93 16 00 00  call    MMGetSuppress
000033F2  85 C0  test    eax, eax
000033F4  0F 85 E7 03 00 00  jnz     loc_1800037E1
000033FA  48 8B 9C 24 E0 00 00 00  mov     rbx, [rsp+0A8h+lpMultiByteStr]
00003402  45 33 ED  xor     r13d, r13d
00003405  48 85 DB  test    rbx, rbx
00003408  74 5D  jz      short loc_180003467
0000340A  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
0000340F  44 8D 48 FF  lea     r9d, [rax-1]; cbMultiByte
00003413  4C 8B C3  mov     r8, rbx; lpMultiByteStr
00003416  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
0000341B  33 D2  xor     edx, edx; dwFlags
0000341D  33 C9  xor     ecx, ecx; CodePage
0000341F  FF 15 2B 3C 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003425  33 C9  xor     ecx, ecx; strIn
00003427  8B F8  mov     edi, eax
00003429  8D 50 FF  lea     edx, [rax-1]; ui
0000342C  FF 15 A6 3C 00 00  call    cs:SysAllocStringLen
00003432  4C 8B E0  mov     r12, rax
00003435  48 85 C0  test    rax, rax
00003438  74 22  jz      short loc_18000345C
0000343A  89 7C 24 28  mov     [rsp+0A8h+cchWideChar], edi; cchWideChar
0000343E  45 8D 4D FF  lea     r9d, [r13-1]; cbMultiByte
00003442  4C 8B C3  mov     r8, rbx; lpMultiByteStr
00003445  48 89 44 24 20  mov     [rsp+0A8h+lpWideCharStr], rax; lpWideCharStr
0000344A  33 D2  xor     edx, edx; dwFlags
0000344C  33 C9  xor     ecx, ecx; CodePage
0000344E  FF 15 FC 3B 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003454  3B C7  cmp     eax, edi
00003456  0F 85 D3 03 00 00  jnz     loc_18000382F
0000345C  4D 85 E4  test    r12, r12
0000345F  0F 84 D3 03 00 00  jz      loc_180003838
00003465  EB 03  jmp     short loc_18000346A
00003467  4D 8B E5  mov     r12, r13
0000346A  48 8B 9C 24 D8 00 00 00  mov     rbx, [rsp+0A8h+arg_28]
00003472  48 85 DB  test    rbx, rbx
00003475  74 6B  jz      short loc_1800034E2
00003477  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
0000347C  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00003482  4C 8B C3  mov     r8, rbx; lpMultiByteStr
00003485  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
0000348A  33 D2  xor     edx, edx; dwFlags
0000348C  33 C9  xor     ecx, ecx; CodePage
0000348E  FF 15 BC 3B 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003494  33 C9  xor     ecx, ecx; strIn
00003496  8B F8  mov     edi, eax
00003498  8D 50 FF  lea     edx, [rax-1]; ui
0000349B  FF 15 37 3C 00 00  call    cs:SysAllocStringLen
000034A1  4C 8B F8  mov     r15, rax
000034A4  48 85 C0  test    rax, rax
000034A7  74 2E  jz      short loc_1800034D7
000034A9  89 7C 24 28  mov     [rsp+0A8h+cchWideChar], edi; cchWideChar
000034AD  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
000034B3  4C 8B C3  mov     r8, rbx; lpMultiByteStr
000034B6  48 89 44 24 20  mov     [rsp+0A8h+lpWideCharStr], rax; lpWideCharStr
000034BB  33 D2  xor     edx, edx; dwFlags
000034BD  33 C9  xor     ecx, ecx; CodePage
000034BF  FF 15 8B 3B 00 00  call    cs:MultiByteToWideChar; KERNEL32
000034C5  3B C7  cmp     eax, edi
000034C7  74 0E  jz      short loc_1800034D7
000034C9  49 8B CF  mov     rcx, r15; bstrString
000034CC  FF 15 0E 3C 00 00  call    cs:SysFreeString
000034D2  E9 61 03 00 00  jmp     loc_180003838
000034D7  4D 85 FF  test    r15, r15
000034DA  0F 84 58 03 00 00  jz      loc_180003838
000034E0  EB 03  jmp     short loc_1800034E5
000034E2  4D 8B FD  mov     r15, r13
000034E5  48 8B 9C 24 D0 00 00 00  mov     rbx, [rsp+0A8h+arg_20]
000034ED  48 85 DB  test    rbx, rbx
000034F0  74 6B  jz      short loc_18000355D
000034F2  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
000034F7  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
000034FD  4C 8B C3  mov     r8, rbx; lpMultiByteStr
00003500  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
00003505  33 D2  xor     edx, edx; dwFlags
00003507  33 C9  xor     ecx, ecx; CodePage
00003509  FF 15 41 3B 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000350F  33 C9  xor     ecx, ecx; strIn
00003511  8B F8  mov     edi, eax
00003513  8D 50 FF  lea     edx, [rax-1]; ui
00003516  FF 15 BC 3B 00 00  call    cs:SysAllocStringLen
0000351C  4C 8B F0  mov     r14, rax
0000351F  48 85 C0  test    rax, rax
00003522  74 2E  jz      short loc_180003552
00003524  89 7C 24 28  mov     [rsp+0A8h+cchWideChar], edi; cchWideChar
00003528  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
0000352E  4C 8B C3  mov     r8, rbx; lpMultiByteStr
00003531  48 89 44 24 20  mov     [rsp+0A8h+lpWideCharStr], rax; lpWideCharStr
00003536  33 D2  xor     edx, edx; dwFlags
00003538  33 C9  xor     ecx, ecx; CodePage
0000353A  FF 15 10 3B 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003540  3B C7  cmp     eax, edi
00003542  74 0E  jz      short loc_180003552
00003544  49 8B CE  mov     rcx, r14; bstrString
00003547  FF 15 93 3B 00 00  call    cs:SysFreeString
0000354D  E9 E6 02 00 00  jmp     loc_180003838
00003552  4D 85 F6  test    r14, r14
00003555  0F 84 DD 02 00 00  jz      loc_180003838
0000355B  EB 03  jmp     short loc_180003560
0000355D  4D 8B F5  mov     r14, r13
00003560  48 85 F6  test    rsi, rsi
00003563  74 6B  jz      short loc_1800035D0
00003565  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
0000356A  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00003570  4C 8B C6  mov     r8, rsi; lpMultiByteStr
00003573  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
00003578  33 D2  xor     edx, edx; dwFlags
0000357A  33 C9  xor     ecx, ecx; CodePage
0000357C  FF 15 CE 3A 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003582  33 C9  xor     ecx, ecx; strIn
00003584  8B D8  mov     ebx, eax
00003586  8D 50 FF  lea     edx, [rax-1]; ui
00003589  FF 15 49 3B 00 00  call    cs:SysAllocStringLen
0000358F  48 8B E8  mov     rbp, rax
00003592  48 85 C0  test    rax, rax
00003595  74 2E  jz      short loc_1800035C5
00003597  89 5C 24 28  mov     [rsp+0A8h+cchWideChar], ebx; cchWideChar
0000359B  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
000035A1  4C 8B C6  mov     r8, rsi; lpMultiByteStr
000035A4  48 89 44 24 20  mov     [rsp+0A8h+lpWideCharStr], rax; lpWideCharStr
000035A9  33 D2  xor     edx, edx; dwFlags
000035AB  33 C9  xor     ecx, ecx; CodePage
000035AD  FF 15 9D 3A 00 00  call    cs:MultiByteToWideChar; KERNEL32
000035B3  3B C3  cmp     eax, ebx
000035B5  74 0E  jz      short loc_1800035C5
000035B7  48 8B CD  mov     rcx, rbp; bstrString
000035BA  FF 15 20 3B 00 00  call    cs:SysFreeString
000035C0  E9 73 02 00 00  jmp     loc_180003838
000035C5  48 85 ED  test    rbp, rbp
000035C8  0F 84 6A 02 00 00  jz      loc_180003838
000035CE  EB 03  jmp     short loc_1800035D3
000035D0  49 8B ED  mov     rbp, r13
000035D3  48 8B BC 24 C0 00 00 00  mov     rdi, [rsp+0A8h+arg_10]
000035DB  48 85 FF  test    rdi, rdi
000035DE  74 6B  jz      short loc_18000364B
000035E0  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
000035E5  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
000035EB  4C 8B C7  mov     r8, rdi; lpMultiByteStr
000035EE  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
000035F3  33 D2  xor     edx, edx; dwFlags
000035F5  33 C9  xor     ecx, ecx; CodePage
000035F7  FF 15 53 3A 00 00  call    cs:MultiByteToWideChar; KERNEL32
000035FD  33 C9  xor     ecx, ecx; strIn
000035FF  8B D8  mov     ebx, eax
00003601  8D 50 FF  lea     edx, [rax-1]; ui
00003604  FF 15 CE 3A 00 00  call    cs:SysAllocStringLen
0000360A  48 8B F0  mov     rsi, rax
0000360D  48 85 C0  test    rax, rax
00003610  74 2E  jz      short loc_180003640
00003612  89 5C 24 28  mov     [rsp+0A8h+cchWideChar], ebx; cchWideChar
00003616  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
0000361C  4C 8B C7  mov     r8, rdi; lpMultiByteStr
0000361F  48 89 44 24 20  mov     [rsp+0A8h+lpWideCharStr], rax; lpWideCharStr
00003624  33 D2  xor     edx, edx; dwFlags
00003626  33 C9  xor     ecx, ecx; CodePage
00003628  FF 15 22 3A 00 00  call    cs:MultiByteToWideChar; KERNEL32
0000362E  3B C3  cmp     eax, ebx
00003630  74 0E  jz      short loc_180003640
00003632  48 8B CE  mov     rcx, rsi; bstrString
00003635  FF 15 A5 3A 00 00  call    cs:SysFreeString
0000363B  E9 F8 01 00 00  jmp     loc_180003838
00003640  48 85 F6  test    rsi, rsi
00003643  0F 84 EF 01 00 00  jz      loc_180003838
00003649  EB 03  jmp     short loc_18000364E
0000364B  49 8B F5  mov     rsi, r13
0000364E  48 8B 84 24 B8 00 00 00  mov     rax, [rsp+0A8h+arg_8]
00003656  48 85 C0  test    rax, rax
00003659  74 70  jz      short loc_1800036CB
0000365B  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
00003660  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00003666  4C 8B C0  mov     r8, rax; lpMultiByteStr
00003669  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
0000366E  33 D2  xor     edx, edx; dwFlags
00003670  33 C9  xor     ecx, ecx; CodePage
00003672  FF 15 D8 39 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003678  33 C9  xor     ecx, ecx; strIn
0000367A  8B D8  mov     ebx, eax
0000367C  8D 50 FF  lea     edx, [rax-1]; ui
0000367F  FF 15 53 3A 00 00  call    cs:SysAllocStringLen
00003685  48 8B F8  mov     rdi, rax
00003688  48 85 C0  test    rax, rax
0000368B  74 33  jz      short loc_1800036C0
0000368D  4C 8B 84 24 B8 00 00 00  mov     r8, [rsp+0A8h+arg_8]; lpMultiByteStr
00003695  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
0000369B  89 5C 24 28  mov     [rsp+0A8h+cchWideChar], ebx; cchWideChar
0000369F  33 D2  xor     edx, edx; dwFlags
000036A1  33 C9  xor     ecx, ecx; CodePage
000036A3  48 89 44 24 20  mov     [rsp+0A8h+lpWideCharStr], rax; lpWideCharStr
000036A8  FF 15 A2 39 00 00  call    cs:MultiByteToWideChar; KERNEL32
000036AE  3B C3  cmp     eax, ebx
000036B0  74 0E  jz      short loc_1800036C0
000036B2  48 8B CF  mov     rcx, rdi; bstrString
000036B5  FF 15 25 3A 00 00  call    cs:SysFreeString
000036BB  E9 78 01 00 00  jmp     loc_180003838
000036C0  48 85 FF  test    rdi, rdi
000036C3  0F 84 6F 01 00 00  jz      loc_180003838
000036C9  EB 03  jmp     short loc_1800036CE
000036CB  49 8B FD  mov     rdi, r13
000036CE  48 8B 84 24 B0 00 00 00  mov     rax, [rsp+0A8h+arg_0]
000036D6  48 85 C0  test    rax, rax
000036D9  74 78  jz      short loc_180003753
000036DB  44 89 6C 24 28  mov     [rsp+0A8h+cchWideChar], r13d; cchWideChar
000036E0  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
000036E6  4C 8B C0  mov     r8, rax; lpMultiByteStr
000036E9  4C 89 6C 24 20  mov     [rsp+0A8h+lpWideCharStr], r13; lpWideCharStr
000036EE  33 D2  xor     edx, edx; dwFlags
000036F0  33 C9  xor     ecx, ecx; CodePage
000036F2  FF 15 58 39 00 00  call    cs:MultiByteToWideChar; KERNEL32
000036F8  33 C9  xor     ecx, ecx; strIn
000036FA  89 44 24 50  mov     [rsp+0A8h+var_58], eax
000036FE  8D 50 FF  lea     edx, [rax-1]; ui
00003701  FF 15 D1 39 00 00  call    cs:SysAllocStringLen
00003707  48 8B D8  mov     rbx, rax
0000370A  48 85 C0  test    rax, rax
0000370D  74 39  jz      short loc_180003748
0000370F  8B 44 24 50  mov     eax, [rsp+0A8h+var_58]
00003713  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00003719  4C 8B 84 24 B0 00 00 00  mov     r8, [rsp+0A8h+arg_0]; lpMultiByteStr
00003721  33 D2  xor     edx, edx; dwFlags
00003723  89 44 24 28  mov     [rsp+0A8h+cchWideChar], eax; cchWideChar
00003727  33 C9  xor     ecx, ecx; CodePage
00003729  48 89 5C 24 20  mov     [rsp+0A8h+lpWideCharStr], rbx; lpWideCharStr
0000372E  FF 15 1C 39 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003734  3B 44 24 50  cmp     eax, [rsp+0A8h+var_58]
00003738  74 0E  jz      short loc_180003748
0000373A  48 8B CB  mov     rcx, rbx; bstrString
0000373D  FF 15 9D 39 00 00  call    cs:SysFreeString
00003743  E9 F0 00 00 00  jmp     loc_180003838
00003748  48 85 DB  test    rbx, rbx
0000374B  0F 84 E7 00 00 00  jz      loc_180003838
00003751  EB 03  jmp     short loc_180003756
00003753  49 8B DD  mov     rbx, r13
00003756  8B 84 24 F0 00 00 00  mov     eax, [rsp+0A8h+arg_40]
0000375D  4C 8B CD  mov     r9, rbp
00003760  44 89 6C 24 48  mov     [rsp+0A8h+var_60], r13d
00003765  4C 8B C6  mov     r8, rsi
00003768  89 44 24 40  mov     [rsp+0A8h+var_68], eax
0000376C  48 8B D7  mov     rdx, rdi
0000376F  8B 84 24 E8 00 00 00  mov     eax, [rsp+0A8h+arg_38]
00003776  48 8B CB  mov     rcx, rbx
00003779  89 44 24 38  mov     [rsp+0A8h+var_70], eax
0000377D  4C 89 64 24 30  mov     [rsp+0A8h+var_78], r12
00003782  4C 89 7C 24 28  mov     qword ptr [rsp+0A8h+cchWideChar], r15
00003787  4C 89 74 24 20  mov     [rsp+0A8h+lpWideCharStr], r14
0000378C  E8 1F EE FF FF  call    sub_1800025B0
00003791  48 8B CB  mov     rcx, rbx; bstrString
00003794  89 44 24 50  mov     [rsp+0A8h+var_58], eax
00003798  FF 15 42 39 00 00  call    cs:SysFreeString
0000379E  48 8B CF  mov     rcx, rdi; bstrString
000037A1  FF 15 39 39 00 00  call    cs:SysFreeString
000037A7  48 8B CE  mov     rcx, rsi; bstrString
000037AA  FF 15 30 39 00 00  call    cs:SysFreeString
000037B0  48 8B CD  mov     rcx, rbp; bstrString
000037B3  FF 15 27 39 00 00  call    cs:SysFreeString
000037B9  49 8B CE  mov     rcx, r14; bstrString
000037BC  FF 15 1E 39 00 00  call    cs:SysFreeString
000037C2  49 8B CF  mov     rcx, r15; bstrString
000037C5  FF 15 15 39 00 00  call    cs:SysFreeString
000037CB  49 8B CC  mov     rcx, r12; bstrString
000037CE  FF 15 0C 39 00 00  call    cs:SysFreeString
000037D4  8B 5C 24 50  mov     ebx, [rsp+0A8h+var_58]
000037D8  83 FB FF  cmp     ebx, 0FFFFFFFFh
000037DB  41 0F 44 DD  cmovz   ebx, r13d
000037DF  EB 07  jmp     short loc_1800037E8
000037E1  8B 9C 24 E8 00 00 00  mov     ebx, [rsp+0A8h+arg_38]
000037E8  48 8D 4C 24 58  lea     rcx, [rsp+0A8h+var_50]; this
000037ED  E8 E1 12 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
000037F2  4C 8B 74 24 78  mov     r14, [rsp+0A8h+var_30]
000037F7  8B C3  mov     eax, ebx
000037F9  48 8B 9C 24 C8 00 00 00  mov     rbx, [rsp+0A8h+arg_18]
00003801  4C 8B AC 24 80 00 00 00  mov     r13, [rsp+0A8h+var_28]
00003809  4C 8B A4 24 88 00 00 00  mov     r12, [rsp+0A8h+var_20]
00003811  48 8B BC 24 90 00 00 00  mov     rdi, [rsp+0A8h+var_18]
00003819  48 8B AC 24 98 00 00 00  mov     rbp, [rsp+0A8h+var_10]
00003821  4C 8B 7C 24 70  mov     r15, [rsp+0A8h+var_38]
00003826  48 81 C4 A0 00 00 00  add     rsp, 0A0h
0000382D  5E  pop     rsi
0000382E  C3  retn
0000382F  49 8B CC  mov     rcx, r12; bstrString
00003832  FF 15 A8 38 00 00  call    cs:SysFreeString
00003838  B9 0E 00 07 80  mov     ecx, 8007000Eh
0000383D  E8 1E D8 FF FF  call    sub_180001060
00003842  CC  db 0CCh

; FUNC 00003850-00003B08 gxOpen_message_box_wcheck (696 bytes)
00003850  48 89 5C 24 20  mov     [rsp+arg_18], rbx
00003855  4C 89 44 24 18  mov     [rsp+arg_10], r8
0000385A  48 89 54 24 10  mov     [rsp+arg_8], rdx
0000385F  48 89 4C 24 08  mov     [rsp+arg_0], rcx
00003864  55  push    rbp
00003865  56  push    rsi
00003866  57  push    rdi
00003867  41 54  push    r12
00003869  41 55  push    r13
0000386B  41 56  push    r14
0000386D  41 57  push    r15
0000386F  48 81 EC B0 00 00 00  sub     rsp, 0B0h
00003876  49 8B E9  mov     rbp, r9
00003879  E8 07 12 00 00  call    MMGetSuppress
0000387E  85 C0  test    eax, eax
00003880  74 0C  jz      short loc_18000388E
00003882  8B 84 24 28 01 00 00  mov     eax, [rsp+0E8h+arg_38]
00003889  E9 5F 02 00 00  jmp     loc_180003AED
0000388E  48 8B 15 4B 7D 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003895  48 85 D2  test    rdx, rdx
00003898  75 07  jnz     short loc_1800038A1
0000389A  33 C0  xor     eax, eax
0000389C  E9 4C 02 00 00  jmp     loc_180003AED
000038A1  48 8D 8C 24 A0 00 00 00  lea     rcx, [rsp+0E8h+var_48]; this
000038A9  E8 1F 12 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
000038AE  48 8B 3D F3 7C 00 00  mov     rdi, cs:qword_18000B5A8
000038B5  E8 0D 12 00 00  call    AfxGetModuleState(void)
000038BA  48 8B 58 18  mov     rbx, [rax+18h]
000038BE  E8 04 12 00 00  call    AfxGetModuleState(void)
000038C3  48 89 78 18  mov     [rax+18h], rdi
000038C7  E8 19 12 00 00  call    AfxGetThread(void)
000038CC  48 85 C0  test    rax, rax
000038CF  0F 84 FE 01 00 00  jz      loc_180003AD3
000038D5  48 8B 10  mov     rdx, [rax]
000038D8  48 8B C8  mov     rcx, rax
000038DB  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
000038E1  48 8B F0  mov     rsi, rax
000038E4  48 85 C0  test    rax, rax
000038E7  0F 84 E6 01 00 00  jz      loc_180003AD3
000038ED  FF 15 25 38 00 00  call    cs:GetForegroundWindow; USER32
000038F3  48 8B C8  mov     rcx, rax; HWND
000038F6  E8 E4 11 00 00  call    CWnd::FromHandle(HWND__ *)
000038FB  48 8B F8  mov     rdi, rax
000038FE  48 3B C6  cmp     rax, rsi
00003901  0F 84 85 01 00 00  jz      loc_180003A8C
00003907  48 85 C0  test    rax, rax
0000390A  75 04  jnz     short loc_180003910
0000390C  33 D2  xor     edx, edx
0000390E  EB 04  jmp     short loc_180003914
00003910  48 8B 50 40  mov     rdx, [rax+40h]; hWnd
00003914  48 83 C0 40  add     rax, 40h ; '@'
00003918  41 BE 40 00 00 00  mov     r14d, 40h ; '@'
0000391E  48 85 FF  test    rdi, rdi
00003921  4C 0F 45 F0  cmovnz  r14, rax
00003925  48 8B 4E 40  mov     rcx, [rsi+40h]; hWndParent
00003929  FF 15 E1 37 00 00  call    cs:IsChild; USER32
0000392F  85 C0  test    eax, eax
00003931  0F 85 59 01 00 00  jnz     loc_180003A90
00003937  C7 44 24 60 01 00 00 00  mov     [rsp+0E8h+var_88], 1
0000393F  4C 8B 6E 40  mov     r13, [rsi+40h]
00003943  48 8B 94 24 20 01 00 00  mov     rdx, [rsp+0E8h+arg_30]
0000394B  48 8D 8C 24 98 00 00 00  lea     rcx, [rsp+0E8h+var_50]
00003953  E8 98 D7 FF FF  call    sub_1800010F0
00003958  4C 8B 20  mov     r12, [rax]
0000395B  48 8B 94 24 18 01 00 00  mov     rdx, [rsp+0E8h+arg_28]
00003963  48 8D 8C 24 90 00 00 00  lea     rcx, [rsp+0E8h+var_58]
0000396B  E8 80 D7 FF FF  call    sub_1800010F0
00003970  4C 8B 38  mov     r15, [rax]
00003973  48 8B 94 24 10 01 00 00  mov     rdx, [rsp+0E8h+arg_20]
0000397B  48 8D 8C 24 88 00 00 00  lea     rcx, [rsp+0E8h+var_60]
00003983  E8 68 D7 FF FF  call    sub_1800010F0
00003988  4C 8B 30  mov     r14, [rax]
0000398B  48 8B D5  mov     rdx, rbp
0000398E  48 8D 8C 24 80 00 00 00  lea     rcx, [rsp+0E8h+var_68]
00003996  E8 55 D7 FF FF  call    sub_1800010F0
0000399B  48 8B 28  mov     rbp, [rax]
0000399E  48 8B 94 24 00 01 00 00  mov     rdx, [rsp+0E8h+arg_10]
000039A6  48 8D 4C 24 78  lea     rcx, [rsp+0E8h+var_70]
000039AB  E8 40 D7 FF FF  call    sub_1800010F0
000039B0  48 8B 30  mov     rsi, [rax]
000039B3  48 8B 94 24 F8 00 00 00  mov     rdx, [rsp+0E8h+arg_8]
000039BB  48 8D 4C 24 70  lea     rcx, [rsp+0E8h+var_78]
000039C0  E8 2B D7 FF FF  call    sub_1800010F0
000039C5  48 8B 38  mov     rdi, [rax]
000039C8  48 8B 94 24 F0 00 00 00  mov     rdx, [rsp+0E8h+arg_0]
000039D0  48 8D 4C 24 68  lea     rcx, [rsp+0E8h+bstrString]
000039D5  E8 16 D7 FF FF  call    sub_1800010F0
000039DA  48 8B 08  mov     rcx, [rax]
000039DD  4C 89 6C 24 50  mov     [rsp+0E8h+var_98], r13
000039E2  C7 44 24 48 FF FF FF FF  mov     [rsp+0E8h+var_A0], 0FFFFFFFFh
000039EA  48 8D 44 24 60  lea     rax, [rsp+0E8h+var_88]
000039EF  48 89 44 24 40  mov     [rsp+0E8h+var_A8], rax
000039F4  8B 84 24 28 01 00 00  mov     eax, [rsp+0E8h+arg_38]
000039FB  89 44 24 38  mov     [rsp+0E8h+var_B0], eax
000039FF  4C 89 64 24 30  mov     [rsp+0E8h+var_B8], r12
00003A04  4C 89 7C 24 28  mov     [rsp+0E8h+var_C0], r15
00003A09  4C 89 74 24 20  mov     [rsp+0E8h+var_C8], r14
00003A0E  4C 8B CD  mov     r9, rbp
00003A11  4C 8B C6  mov     r8, rsi
00003A14  48 8B D7  mov     rdx, rdi
00003A17  E8 94 ED FF FF  call    sub_1800027B0
00003A1C  8B F8  mov     edi, eax
00003A1E  48 8B 4C 24 68  mov     rcx, [rsp+0E8h+bstrString]; bstrString
00003A23  FF 15 B7 36 00 00  call    cs:SysFreeString
00003A29  48 8B 4C 24 70  mov     rcx, [rsp+0E8h+var_78]; bstrString
00003A2E  FF 15 AC 36 00 00  call    cs:SysFreeString
00003A34  48 8B 4C 24 78  mov     rcx, [rsp+0E8h+var_70]; bstrString
00003A39  FF 15 A1 36 00 00  call    cs:SysFreeString
00003A3F  48 8B 8C 24 80 00 00 00  mov     rcx, [rsp+0E8h+var_68]; bstrString
00003A47  FF 15 93 36 00 00  call    cs:SysFreeString
00003A4D  48 8B 8C 24 88 00 00 00  mov     rcx, [rsp+0E8h+var_60]; bstrString
00003A55  FF 15 85 36 00 00  call    cs:SysFreeString
00003A5B  48 8B 8C 24 90 00 00 00  mov     rcx, [rsp+0E8h+var_58]; bstrString
00003A63  FF 15 77 36 00 00  call    cs:SysFreeString
00003A69  48 8B 8C 24 98 00 00 00  mov     rcx, [rsp+0E8h+var_50]; bstrString
00003A71  FF 15 69 36 00 00  call    cs:SysFreeString
00003A77  83 FF FF  cmp     edi, 0FFFFFFFFh
00003A7A  74 57  jz      short loc_180003AD3
00003A7C  48 8B 8C 24 30 01 00 00  mov     rcx, [rsp+0E8h+arg_40]
00003A84  8B 44 24 60  mov     eax, [rsp+0E8h+var_88]
00003A88  89 01  mov     [rcx], eax
00003A8A  EB 49  jmp     short loc_180003AD5
00003A8C  4C 8D 70 40  lea     r14, [rax+40h]
00003A90  48 85 FF  test    rdi, rdi
00003A93  75 04  jnz     short loc_180003A99
00003A95  33 C9  xor     ecx, ecx
00003A97  EB 03  jmp     short loc_180003A9C
00003A99  49 8B 0E  mov     rcx, [r14]; hWnd
00003A9C  C7 44 24 60 01 00 00 00  mov     [rsp+0E8h+var_88], 1
00003AA4  45 33 C9  xor     r9d, r9d; lParam
00003AA7  45 33 C0  xor     r8d, r8d; wParam
00003AAA  BA D2 04 00 00  mov     edx, 4D2h; Msg
00003AAF  FF 15 53 36 00 00  call    cs:SendMessageA; USER32
00003AB5  48 83 F8 01  cmp     rax, 1
00003AB9  0F 84 80 FE FF FF  jz      loc_18000393F
00003ABF  48 8B F7  mov     rsi, rdi
00003AC2  48 85 FF  test    rdi, rdi
00003AC5  0F 85 74 FE FF FF  jnz     loc_18000393F
00003ACB  45 33 ED  xor     r13d, r13d
00003ACE  E9 70 FE FF FF  jmp     loc_180003943
00003AD3  33 FF  xor     edi, edi
00003AD5  E8 ED 0F 00 00  call    AfxGetModuleState(void)
00003ADA  48 89 58 18  mov     [rax+18h], rbx
00003ADE  48 8D 8C 24 A0 00 00 00  lea     rcx, [rsp+0E8h+var_48]; this
00003AE6  E8 E8 0F 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003AEB  8B C7  mov     eax, edi
00003AED  48 8B 9C 24 08 01 00 00  mov     rbx, [rsp+0E8h+arg_18]
00003AF5  48 81 C4 B0 00 00 00  add     rsp, 0B0h
00003AFC  41 5F  pop     r15
00003AFE  41 5E  pop     r14
00003B00  41 5D  pop     r13
00003B02  41 5C  pop     r12
00003B04  5F  pop     rdi
00003B05  5E  pop     rsi
00003B06  5D  pop     rbp
00003B07  C3  retn

; FUNC 00003B10-00003BF0 gxPure_component_param (224 bytes)
00003B10  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003B15  48 89 74 24 18  mov     [rsp+arg_10], rsi
00003B1A  57  push    rdi
00003B1B  48 83 EC 30  sub     rsp, 30h
00003B1F  48 8B F1  mov     rsi, rcx
00003B22  48 8B 15 B7 7A 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003B29  48 85 D2  test    rdx, rdx
00003B2C  75 12  jnz     short loc_180003B40
00003B2E  33 C0  xor     eax, eax
00003B30  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00003B35  48 8B 74 24 50  mov     rsi, [rsp+38h+arg_10]
00003B3A  48 83 C4 30  add     rsp, 30h
00003B3E  5F  pop     rdi
00003B3F  C3  retn
00003B40  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003B45  E8 83 0F 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003B4A  48 8B 3D 57 7A 00 00  mov     rdi, cs:qword_18000B5A8
00003B51  E8 71 0F 00 00  call    AfxGetModuleState(void)
00003B56  48 8B 58 18  mov     rbx, [rax+18h]
00003B5A  E8 68 0F 00 00  call    AfxGetModuleState(void)
00003B5F  48 89 78 18  mov     [rax+18h], rdi
00003B63  E8 7D 0F 00 00  call    AfxGetThread(void)
00003B68  48 85 C0  test    rax, rax
00003B6B  74 5C  jz      short loc_180003BC9
00003B6D  48 8B 10  mov     rdx, [rax]
00003B70  48 8B C8  mov     rcx, rax
00003B73  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00003B79  48 85 C0  test    rax, rax
00003B7C  74 4B  jz      short loc_180003BC9
00003B7E  33 FF  xor     edi, edi
00003B80  48 89 7C 24 48  mov     [rsp+38h+lpWideCharStr], rdi
00003B85  48 8D 4C 24 48  lea     rcx, [rsp+38h+lpWideCharStr]
00003B8A  E8 61 DA FF FF  call    sub_1800015F0
00003B8F  83 F8 01  cmp     eax, 1
00003B92  75 2B  jnz     short loc_180003BBF
00003B94  48 8B 4C 24 48  mov     rcx, [rsp+38h+lpWideCharStr]; lpWideCharStr
00003B99  48 85 C9  test    rcx, rcx
00003B9C  74 21  jz      short loc_180003BBF
00003B9E  48 85 F6  test    rsi, rsi
00003BA1  74 15  jz      short loc_180003BB8
00003BA3  E8 68 21 00 00  call    sub_180005D10
00003BA8  48 8B D0  mov     rdx, rax; Source
00003BAB  44 8D 47 20  lea     r8d, [rdi+20h]; Count
00003BAF  48 8B CE  mov     rcx, rsi; Destination
00003BB2  FF 15 38 36 00 00  call    cs:strncpy; api-ms-win-crt-string-l1-1-0
00003BB8  BF 01 00 00 00  mov     edi, 1
00003BBD  EB 0C  jmp     short loc_180003BCB
00003BBF  48 85 F6  test    rsi, rsi
00003BC2  74 07  jz      short loc_180003BCB
00003BC4  40 88 3E  mov     [rsi], dil
00003BC7  EB 02  jmp     short loc_180003BCB
00003BC9  33 FF  xor     edi, edi
00003BCB  E8 F7 0E 00 00  call    AfxGetModuleState(void)
00003BD0  48 89 58 18  mov     [rax+18h], rbx
00003BD4  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003BD9  E8 F5 0E 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003BDE  8B C7  mov     eax, edi
00003BE0  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00003BE5  48 8B 74 24 50  mov     rsi, [rsp+38h+arg_10]
00003BEA  48 83 C4 30  add     rsp, 30h
00003BEE  5F  pop     rdi
00003BEF  C3  retn

; FUNC 00003BF0-00003C96 gxReorderComp (166 bytes)
00003BF0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003BF5  57  push    rdi
00003BF6  48 83 EC 30  sub     rsp, 30h
00003BFA  48 8B 15 DF 79 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003C01  48 85 D2  test    rdx, rdx
00003C04  74 78  jz      short loc_180003C7E
00003C06  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003C0B  E8 BD 0E 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003C10  48 8B 1D 91 79 00 00  mov     rbx, cs:qword_18000B5A8
00003C17  E8 AB 0E 00 00  call    AfxGetModuleState(void)
00003C1C  48 8B 78 18  mov     rdi, [rax+18h]
00003C20  E8 A2 0E 00 00  call    AfxGetModuleState(void)
00003C25  48 89 58 18  mov     [rax+18h], rbx
00003C29  E8 B7 0E 00 00  call    AfxGetThread(void)
00003C2E  48 85 C0  test    rax, rax
00003C31  74 38  jz      short loc_180003C6B
00003C33  48 8B 10  mov     rdx, [rax]
00003C36  48 8B C8  mov     rcx, rax
00003C39  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00003C3F  48 85 C0  test    rax, rax
00003C42  74 27  jz      short loc_180003C6B
00003C44  48 8D 0D 3D 3E 00 00  lea     rcx, aReordercomp; "ReorderComp"
00003C4B  FF 15 A7 34 00 00  call    cs:SysAllocString
00003C51  48 8B D8  mov     rbx, rax
00003C54  48 85 C0  test    rax, rax
00003C57  74 32  jz      short loc_180003C8B
00003C59  48 8B C8  mov     rcx, rax
00003C5C  E8 BF D6 FF FF  call    sub_180001320
00003C61  48 8B CB  mov     rcx, rbx; bstrString
00003C64  FF 15 76 34 00 00  call    cs:SysFreeString
00003C6A  90  nop
00003C6B  E8 57 0E 00 00  call    AfxGetModuleState(void)
00003C70  48 89 78 18  mov     [rax+18h], rdi
00003C74  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003C79  E8 55 0E 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003C7E  33 C0  xor     eax, eax
00003C80  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00003C85  48 83 C4 30  add     rsp, 30h
00003C89  5F  pop     rdi
00003C8A  C3  retn
00003C8B  B9 0E 00 07 80  mov     ecx, 8007000Eh
00003C90  E8 CB D3 FF FF  call    sub_180001060
00003C95  CC  db 0CCh

; FUNC 00003CA0-00003CFA gxResults_inconsistent_dialog (90 bytes)
00003CA0  48 83 EC 38  sub     rsp, 38h
00003CA4  48 8B 15 35 79 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003CAB  48 85 D2  test    rdx, rdx
00003CAE  75 07  jnz     short loc_180003CB7
00003CB0  33 C0  xor     eax, eax
00003CB2  48 83 C4 38  add     rsp, 38h
00003CB6  C3  retn
00003CB7  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003CBC  48 89 5C 24 30  mov     [rsp+38h+var_8], rbx
00003CC1  E8 07 0E 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003CC6  E8 BA 0D 00 00  call    MMGetSuppress
00003CCB  85 C0  test    eax, eax
00003CCD  75 11  jnz     short loc_180003CE0
00003CCF  E8 1C ED FF FF  call    sub_1800029F0
00003CD4  8B D8  mov     ebx, eax
00003CD6  33 C0  xor     eax, eax
00003CD8  83 FB FF  cmp     ebx, 0FFFFFFFFh
00003CDB  0F 44 D8  cmovz   ebx, eax
00003CDE  EB 04  jmp     short loc_180003CE4
00003CE0  33 C0  xor     eax, eax
00003CE2  8B D8  mov     ebx, eax
00003CE4  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003CE9  E8 E5 0D 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003CEE  8B C3  mov     eax, ebx
00003CF0  48 8B 5C 24 30  mov     rbx, [rsp+38h+var_8]
00003CF5  48 83 C4 38  add     rsp, 38h
00003CF9  C3  retn

; FUNC 00003D00-00003D81 gxSFEAssistant (129 bytes)
00003D00  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003D05  57  push    rdi
00003D06  48 83 EC 30  sub     rsp, 30h
00003D0A  48 8B 15 CF 78 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003D11  48 85 D2  test    rdx, rdx
00003D14  74 5E  jz      short loc_180003D74
00003D16  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003D1B  E8 AD 0D 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003D20  48 8B 3D 81 78 00 00  mov     rdi, cs:qword_18000B5A8
00003D27  E8 9B 0D 00 00  call    AfxGetModuleState(void)
00003D2C  48 8B 58 18  mov     rbx, [rax+18h]
00003D30  E8 92 0D 00 00  call    AfxGetModuleState(void)
00003D35  48 89 78 18  mov     [rax+18h], rdi
00003D39  E8 A7 0D 00 00  call    AfxGetThread(void)
00003D3E  48 85 C0  test    rax, rax
00003D41  74 1E  jz      short loc_180003D61
00003D43  48 8B 10  mov     rdx, [rax]
00003D46  48 8B C8  mov     rcx, rax
00003D49  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00003D4F  48 85 C0  test    rax, rax
00003D52  74 0D  jz      short loc_180003D61
00003D54  E8 A7 E6 FF FF  call    sub_180002400
00003D59  8B C8  mov     ecx, eax
00003D5B  E8 20 DA FF FF  call    sub_180001780
00003D60  90  nop
00003D61  E8 61 0D 00 00  call    AfxGetModuleState(void)
00003D66  48 89 58 18  mov     [rax+18h], rbx
00003D6A  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003D6F  E8 5F 0D 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003D74  33 C0  xor     eax, eax
00003D76  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00003D7B  48 83 C4 30  add     rsp, 30h
00003D7F  5F  pop     rdi
00003D80  C3  retn

; FUNC 00003D90-00003E11 gxSFEAssistantMain (129 bytes)
00003D90  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003D95  57  push    rdi
00003D96  48 83 EC 30  sub     rsp, 30h
00003D9A  48 8B 15 3F 78 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003DA1  48 85 D2  test    rdx, rdx
00003DA4  74 5E  jz      short loc_180003E04
00003DA6  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003DAB  E8 1D 0D 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003DB0  48 8B 3D F1 77 00 00  mov     rdi, cs:qword_18000B5A8
00003DB7  E8 0B 0D 00 00  call    AfxGetModuleState(void)
00003DBC  48 8B 58 18  mov     rbx, [rax+18h]
00003DC0  E8 02 0D 00 00  call    AfxGetModuleState(void)
00003DC5  48 89 78 18  mov     [rax+18h], rdi
00003DC9  E8 17 0D 00 00  call    AfxGetThread(void)
00003DCE  48 85 C0  test    rax, rax
00003DD1  74 1E  jz      short loc_180003DF1
00003DD3  48 8B 10  mov     rdx, [rax]
00003DD6  48 8B C8  mov     rcx, rax
00003DD9  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00003DDF  48 85 C0  test    rax, rax
00003DE2  74 0D  jz      short loc_180003DF1
00003DE4  E8 17 E6 FF FF  call    sub_180002400
00003DE9  8B C8  mov     ecx, eax
00003DEB  E8 F0 DA FF FF  call    sub_1800018E0
00003DF0  90  nop
00003DF1  E8 D1 0C 00 00  call    AfxGetModuleState(void)
00003DF6  48 89 58 18  mov     [rax+18h], rbx
00003DFA  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00003DFF  E8 CF 0C 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003E04  33 C0  xor     eax, eax
00003E06  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00003E0B  48 83 C4 30  add     rsp, 30h
00003E0F  5F  pop     rdi
00003E10  C3  retn

; FUNC 00003E20-00003F14 gxSearchComponents (244 bytes)
00003E20  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003E25  48 89 6C 24 10  mov     [rsp+arg_8], rbp
00003E2A  56  push    rsi
00003E2B  57  push    rdi
00003E2C  41 56  push    r14
00003E2E  48 83 EC 30  sub     rsp, 30h
00003E32  4D 8B F0  mov     r14, r8
00003E35  8B EA  mov     ebp, edx
00003E37  48 8B 15 A2 77 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003E3E  48 85 D2  test    rdx, rdx
00003E41  75 07  jnz     short loc_180003E4A
00003E43  33 C0  xor     eax, eax
00003E45  E9 AC 00 00 00  jmp     loc_180003EF6
00003E4A  48 8D 4C 24 20  lea     rcx, [rsp+48h+var_28]; this
00003E4F  E8 79 0C 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003E54  48 8B 1D 4D 77 00 00  mov     rbx, cs:qword_18000B5A8
00003E5B  E8 67 0C 00 00  call    AfxGetModuleState(void)
00003E60  48 8B 78 18  mov     rdi, [rax+18h]
00003E64  E8 5E 0C 00 00  call    AfxGetModuleState(void)
00003E69  48 89 58 18  mov     [rax+18h], rbx
00003E6D  E8 73 0C 00 00  call    AfxGetThread(void)
00003E72  48 85 C0  test    rax, rax
00003E75  74 68  jz      short loc_180003EDF
00003E77  48 8B 10  mov     rdx, [rax]
00003E7A  48 8B C8  mov     rcx, rax
00003E7D  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00003E83  48 85 C0  test    rax, rax
00003E86  74 57  jz      short loc_180003EDF
00003E88  33 F6  xor     esi, esi
00003E8A  E8 F6 0B 00 00  call    MMGetSuppress
00003E8F  85 C0  test    eax, eax
00003E91  75 4E  jnz     short loc_180003EE1
00003E93  85 ED  test    ebp, ebp
00003E95  0F 49 F5  cmovns  esi, ebp
00003E98  48 8D 0D D9 3B 00 00  lea     rcx, aHapp; "Happ"
00003E9F  FF 15 53 32 00 00  call    cs:SysAllocString
00003EA5  48 8B D8  mov     rbx, rax
00003EA8  48 85 C0  test    rax, rax
00003EAB  74 5C  jz      short loc_180003F09
00003EAD  49 8B D6  mov     rdx, r14
00003EB0  48 8D 4C 24 68  lea     rcx, [rsp+48h+bstrString]
00003EB5  E8 36 D2 FF FF  call    sub_1800010F0
00003EBA  4C 8B 00  mov     r8, [rax]
00003EBD  8B D6  mov     edx, esi
00003EBF  48 8B CB  mov     rcx, rbx
00003EC2  E8 79 DB FF FF  call    sub_180001A40
00003EC7  8B F0  mov     esi, eax
00003EC9  48 8B CB  mov     rcx, rbx; bstrString
00003ECC  FF 15 0E 32 00 00  call    cs:SysFreeString
00003ED2  48 8B 4C 24 68  mov     rcx, [rsp+48h+bstrString]; bstrString
00003ED7  FF 15 03 32 00 00  call    cs:SysFreeString
00003EDD  EB 02  jmp     short loc_180003EE1
00003EDF  33 F6  xor     esi, esi
00003EE1  E8 E1 0B 00 00  call    AfxGetModuleState(void)
00003EE6  48 89 78 18  mov     [rax+18h], rdi
00003EEA  48 8D 4C 24 20  lea     rcx, [rsp+48h+var_28]; this
00003EEF  E8 DF 0B 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00003EF4  8B C6  mov     eax, esi
00003EF6  48 8B 5C 24 50  mov     rbx, [rsp+48h+arg_0]
00003EFB  48 8B 6C 24 58  mov     rbp, [rsp+48h+arg_8]
00003F00  48 83 C4 30  add     rsp, 30h
00003F04  41 5E  pop     r14
00003F06  5F  pop     rdi
00003F07  5E  pop     rsi
00003F08  C3  retn
00003F09  B9 0E 00 07 80  mov     ecx, 8007000Eh
00003F0E  E8 4D D1 FF FF  call    sub_180001060
00003F13  CC  db 0CCh

; FUNC 00003F20-00004030 gxSearchProperty (272 bytes)
00003F20  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00003F25  48 89 6C 24 10  mov     [rsp+arg_8], rbp
00003F2A  48 89 74 24 18  mov     [rsp+arg_10], rsi
00003F2F  57  push    rdi
00003F30  48 83 EC 40  sub     rsp, 40h
00003F34  48 8B F1  mov     rsi, rcx
00003F37  48 8B 15 A2 76 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
00003F3E  48 85 D2  test    rdx, rdx
00003F41  0F 84 BE 00 00 00  jz      loc_180004005
00003F47  48 8D 4C 24 30  lea     rcx, [rsp+48h+var_18]; this
00003F4C  E8 7C 0B 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
00003F51  48 8B 1D 50 76 00 00  mov     rbx, cs:qword_18000B5A8
00003F58  E8 6A 0B 00 00  call    AfxGetModuleState(void)
00003F5D  48 8B 78 18  mov     rdi, [rax+18h]
00003F61  E8 61 0B 00 00  call    AfxGetModuleState(void)
00003F66  48 89 58 18  mov     [rax+18h], rbx
00003F6A  E8 76 0B 00 00  call    AfxGetThread(void)
00003F6F  48 85 C0  test    rax, rax
00003F72  74 7E  jz      short loc_180003FF2
00003F74  48 8B 10  mov     rdx, [rax]
00003F77  48 8B C8  mov     rcx, rax
00003F7A  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00003F80  48 85 C0  test    rax, rax
00003F83  74 6D  jz      short loc_180003FF2
00003F85  33 DB  xor     ebx, ebx
00003F87  48 85 F6  test    rsi, rsi
00003F8A  74 54  jz      short loc_180003FE0
00003F8C  89 5C 24 28  mov     [rsp+48h+cchWideChar], ebx; cchWideChar
00003F90  48 89 5C 24 20  mov     [rsp+48h+lpWideCharStr], rbx; lpWideCharStr
00003F95  44 8D 4B FF  lea     r9d, [rbx-1]; cbMultiByte
00003F99  4C 8B C6  mov     r8, rsi; lpMultiByteStr
00003F9C  33 D2  xor     edx, edx; dwFlags
00003F9E  33 C9  xor     ecx, ecx; CodePage
00003FA0  FF 15 AA 30 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003FA6  8B E8  mov     ebp, eax
00003FA8  8D 50 FF  lea     edx, [rax-1]; ui
00003FAB  33 C9  xor     ecx, ecx; strIn
00003FAD  FF 15 25 31 00 00  call    cs:SysAllocStringLen
00003FB3  48 8B D8  mov     rbx, rax
00003FB6  48 85 C0  test    rax, rax
00003FB9  74 20  jz      short loc_180003FDB
00003FBB  89 6C 24 28  mov     [rsp+48h+cchWideChar], ebp; cchWideChar
00003FBF  48 89 44 24 20  mov     [rsp+48h+lpWideCharStr], rax; lpWideCharStr
00003FC4  41 B9 FF FF FF FF  mov     r9d, 0FFFFFFFFh; cbMultiByte
00003FCA  4C 8B C6  mov     r8, rsi; lpMultiByteStr
00003FCD  33 D2  xor     edx, edx; dwFlags
00003FCF  33 C9  xor     ecx, ecx; CodePage
00003FD1  FF 15 79 30 00 00  call    cs:MultiByteToWideChar; KERNEL32
00003FD7  3B C5  cmp     eax, ebp
00003FD9  75 41  jnz     short loc_18000401C
00003FDB  48 85 DB  test    rbx, rbx
00003FDE  74 45  jz      short loc_180004025
00003FE0  48 8B CB  mov     rcx, rbx
00003FE3  E8 18 DC FF FF  call    sub_180001C00
00003FE8  48 8B CB  mov     rcx, rbx; bstrString
00003FEB  FF 15 EF 30 00 00  call    cs:SysFreeString
00003FF1  90  nop
00003FF2  E8 D0 0A 00 00  call    AfxGetModuleState(void)
00003FF7  48 89 78 18  mov     [rax+18h], rdi
00003FFB  48 8D 4C 24 30  lea     rcx, [rsp+48h+var_18]; this
00004000  E8 CE 0A 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00004005  33 C0  xor     eax, eax
00004007  48 8B 5C 24 50  mov     rbx, [rsp+48h+arg_0]
0000400C  48 8B 6C 24 58  mov     rbp, [rsp+48h+arg_8]
00004011  48 8B 74 24 60  mov     rsi, [rsp+48h+arg_10]
00004016  48 83 C4 40  add     rsp, 40h
0000401A  5F  pop     rdi
0000401B  C3  retn
0000401C  48 8B CB  mov     rcx, rbx; bstrString
0000401F  FF 15 BB 30 00 00  call    cs:SysFreeString
00004025  B9 0E 00 07 80  mov     ecx, 8007000Eh
0000402A  E8 31 D0 FF FF  call    sub_180001060
0000402F  CC  align 10h

; FUNC 00004030-00004037 gxSetApedFlag (7 bytes)
00004030  89 0D 7E 75 00 00  mov     cs:dword_18000B5B4, ecx
00004036  C3  retn

; FUNC 00004040-00004078 gxShowTPSARUpgradeDialog (56 bytes)
00004040  40 53  push    rbx
00004042  48 83 EC 20  sub     rsp, 20h
00004046  48 8B D9  mov     rbx, rcx
00004049  E8 37 0A 00 00  call    MMGetSuppress
0000404E  85 C0  test    eax, eax
00004050  74 08  jz      short loc_18000405A
00004052  33 C0  xor     eax, eax
00004054  48 83 C4 20  add     rsp, 20h
00004058  5B  pop     rbx
00004059  C3  retn
0000405A  48 8D 4C 24 38  lea     rcx, [rsp+28h+arg_8]
0000405F  C7 44 24 38 00 00 00 00  mov     [rsp+28h+arg_8], 0
00004067  E8 94 ED FF FF  call    sub_180002E00
0000406C  8B 4C 24 38  mov     ecx, [rsp+28h+arg_8]
00004070  89 0B  mov     [rbx], ecx
00004072  48 83 C4 20  add     rsp, 20h
00004076  5B  pop     rbx
00004077  C3  retn

; FUNC 00004080-000041FD gxUpgradeRetired (381 bytes)
00004080  48 89 5C 24 10  mov     [rsp+arg_8], rbx
00004085  48 89 74 24 18  mov     [rsp+arg_10], rsi
0000408A  48 89 7C 24 20  mov     [rsp+arg_18], rdi
0000408F  41 56  push    r14
00004091  48 81 EC 50 04 00 00  sub     rsp, 450h
00004098  48 8B 05 49 73 00 00  mov     rax, cs:__security_cookie
0000409F  48 33 C4  xor     rax, rsp
000040A2  48 89 84 24 40 04 00 00  mov     [rsp+458h+var_18], rax
000040AA  4C 8B F1  mov     r14, rcx
000040AD  48 8B 15 2C 75 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
000040B4  48 85 D2  test    rdx, rdx
000040B7  75 07  jnz     short loc_1800040C0
000040B9  33 C0  xor     eax, eax
000040BB  E9 13 01 00 00  jmp     loc_1800041D3
000040C0  48 8D 4C 24 28  lea     rcx, [rsp+458h+var_430]; this
000040C5  E8 03 0A 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
000040CA  48 8B 3D D7 74 00 00  mov     rdi, cs:qword_18000B5A8
000040D1  E8 F1 09 00 00  call    AfxGetModuleState(void)
000040D6  48 8B 58 18  mov     rbx, [rax+18h]
000040DA  E8 E8 09 00 00  call    AfxGetModuleState(void)
000040DF  48 89 78 18  mov     [rax+18h], rdi
000040E3  E8 FD 09 00 00  call    AfxGetThread(void)
000040E8  48 85 C0  test    rax, rax
000040EB  0F 84 CB 00 00 00  jz      loc_1800041BC
000040F1  48 8B 10  mov     rdx, [rax]
000040F4  48 8B C8  mov     rcx, rax
000040F7  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
000040FD  48 85 C0  test    rax, rax
00004100  0F 84 B6 00 00 00  jz      loc_1800041BC
00004106  E8 85 EE FF FF  call    sub_180002F90
0000410B  85 C0  test    eax, eax
0000410D  74 16  jz      short loc_180004125
0000410F  BE 01 00 00 00  mov     esi, 1
00004114  4D 85 F6  test    r14, r14
00004117  0F 84 A1 00 00 00  jz      loc_1800041BE
0000411D  41 89 36  mov     [r14], esi
00004120  E9 99 00 00 00  jmp     loc_1800041BE
00004125  FF 15 1D 2F 00 00  call    cs:GetTickCount; KERNEL32
0000412B  8B F8  mov     edi, eax
0000412D  FF 15 15 2F 00 00  call    cs:GetTickCount; KERNEL32
00004133  2B C7  sub     eax, edi
00004135  44 8B C0  mov     r8d, eax
00004138  48 8D 15 F1 39 00 00  lea     rdx, Format; "\n+++++++++++++ CComPtr<AspenTech_Aspen"...
0000413F  48 8D 4C 24 40  lea     rcx, [rsp+458h+OutputString]; Buffer
00004144  E8 17 02 00 00  call    sub_180004360
00004149  48 8D 4C 24 40  lea     rcx, [rsp+458h+OutputString]; lpOutputString
0000414E  FF 15 EC 2E 00 00  call    cs:OutputDebugStringA; KERNEL32
00004154  FF 15 EE 2E 00 00  call    cs:GetTickCount; KERNEL32
0000415A  8B F8  mov     edi, eax
0000415C  E8 9F E2 FF FF  call    sub_180002400
00004161  33 F6  xor     esi, esi
00004163  89 74 24 20  mov     [rsp+458h+var_438], esi
00004167  48 8D 54 24 20  lea     rdx, [rsp+458h+var_438]
0000416C  8B C8  mov     ecx, eax
0000416E  E8 FD DB FF FF  call    sub_180001D70
00004173  8B 4C 24 20  mov     ecx, [rsp+458h+var_438]
00004177  41 89 0E  mov     [r14], ecx
0000417A  E8 48 09 00 00  call    AfxGetModuleState(void)
0000417F  48 8B 48 08  mov     rcx, [rax+8]; this
00004183  E8 51 09 00 00  call    CCmdTarget::RestoreWaitCursor(void)
00004188  FF 15 BA 2E 00 00  call    cs:GetTickCount; KERNEL32
0000418E  2B C7  sub     eax, edi
00004190  44 8B C0  mov     r8d, eax
00004193  48 8D 15 EE 39 00 00  lea     rdx, aShowupgraderet_0; "\n+++++++++++++ ShowUpgradeRetired %d\n"
0000419A  48 8D 4C 24 40  lea     rcx, [rsp+458h+OutputString]; Buffer
0000419F  E8 BC 01 00 00  call    sub_180004360
000041A4  48 8D 4C 24 40  lea     rcx, [rsp+458h+OutputString]; lpOutputString
000041A9  FF 15 91 2E 00 00  call    cs:OutputDebugStringA; KERNEL32
000041AF  FF 15 93 2E 00 00  call    cs:GetTickCount; KERNEL32
000041B5  BE 01 00 00 00  mov     esi, 1
000041BA  EB 02  jmp     short loc_1800041BE
000041BC  33 F6  xor     esi, esi
000041BE  E8 04 09 00 00  call    AfxGetModuleState(void)
000041C3  48 89 58 18  mov     [rax+18h], rbx
000041C7  48 8D 4C 24 28  lea     rcx, [rsp+458h+var_430]; this
000041CC  E8 02 09 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
000041D1  8B C6  mov     eax, esi
000041D3  48 8B 8C 24 40 04 00 00  mov     rcx, [rsp+458h+var_18]
000041DB  48 33 CC  xor     rcx, rsp; StackCookie
000041DE  E8 BD 10 00 00  call    __security_check_cookie
000041E3  4C 8D 9C 24 50 04 00 00  lea     r11, [rsp+458h+var_8]
000041EB  49 8B 5B 18  mov     rbx, [r11+18h]
000041EF  49 8B 73 20  mov     rsi, [r11+20h]
000041F3  49 8B 7B 28  mov     rdi, [r11+28h]
000041F7  49 8B E3  mov     rsp, r11
000041FA  41 5E  pop     r14
000041FC  C3  retn

; FUNC 00004200-00004268 gxUpwardComp (104 bytes)
00004200  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00004205  57  push    rdi
00004206  48 83 EC 20  sub     rsp, 20h
0000420A  8B DA  mov     ebx, edx
0000420C  8B F9  mov     edi, ecx
0000420E  E8 7D ED FF FF  call    sub_180002F90
00004213  85 C0  test    eax, eax
00004215  74 38  jz      short loc_18000424F
00004217  48 8D 0D 92 38 00 00  lea     rcx, aUpwardoption; "UpwardOption"
0000421E  E8 6E 08 00 00  call    GetGlobalPointer
00004223  48 85 C0  test    rax, rax
00004226  75 10  jnz     short loc_180004238
00004228  B8 FF FF FF FF  mov     eax, 0FFFFFFFFh
0000422D  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004232  48 83 C4 20  add     rsp, 20h
00004236  5F  pop     rdi
00004237  C3  retn
00004238  8B 00  mov     eax, [rax]
0000423A  B9 FF FF FF FF  mov     ecx, 0FFFFFFFFh
0000423F  85 C0  test    eax, eax
00004241  0F 44 C1  cmovz   eax, ecx
00004244  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004249  48 83 C4 20  add     rsp, 20h
0000424D  5F  pop     rdi
0000424E  C3  retn
0000424F  8B D7  mov     edx, edi
00004251  89 1D 91 73 00 00  mov     cs:dword_18000B5E8, ebx
00004257  8B CB  mov     ecx, ebx
00004259  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
0000425E  48 83 C4 20  add     rsp, 20h
00004262  5F  pop     rdi
00004263  E9 F8 DD FF FF  jmp     sub_180002060

; FUNC 00004270-000042C1 gxUpwardComp1 (81 bytes)
00004270  40 53  push    rbx
00004272  48 83 EC 20  sub     rsp, 20h
00004276  8B D9  mov     ebx, ecx
00004278  E8 13 ED FF FF  call    sub_180002F90
0000427D  85 C0  test    eax, eax
0000427F  74 2E  jz      short loc_1800042AF
00004281  48 8D 0D 28 38 00 00  lea     rcx, aUpwardoption; "UpwardOption"
00004288  E8 04 08 00 00  call    GetGlobalPointer
0000428D  48 85 C0  test    rax, rax
00004290  75 0B  jnz     short loc_18000429D
00004292  B8 FF FF FF FF  mov     eax, 0FFFFFFFFh
00004297  48 83 C4 20  add     rsp, 20h
0000429B  5B  pop     rbx
0000429C  C3  retn
0000429D  8B 00  mov     eax, [rax]
0000429F  B9 FF FF FF FF  mov     ecx, 0FFFFFFFFh
000042A4  85 C0  test    eax, eax
000042A6  0F 44 C1  cmovz   eax, ecx
000042A9  48 83 C4 20  add     rsp, 20h
000042AD  5B  pop     rbx
000042AE  C3  retn
000042AF  8B CB  mov     ecx, ebx
000042B1  89 1D 31 73 00 00  mov     cs:dword_18000B5E8, ebx
000042B7  48 83 C4 20  add     rsp, 20h
000042BB  5B  pop     rbx
000042BC  E9 3F DC FF FF  jmp     sub_180001F00

; FUNC 000042D0-00004358 gxUserDefWizard (136 bytes)
000042D0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000042D5  48 89 74 24 10  mov     [rsp+arg_8], rsi
000042DA  57  push    rdi
000042DB  48 83 EC 30  sub     rsp, 30h
000042DF  8B F1  mov     esi, ecx
000042E1  48 8B 15 F8 72 00 00  mov     rdx, cs:qword_18000B5E0; struct AFX_MODULE_STATE *
000042E8  48 85 D2  test    rdx, rdx
000042EB  74 59  jz      short loc_180004346
000042ED  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
000042F2  E8 D6 07 00 00  call    AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)
000042F7  48 8B 3D AA 72 00 00  mov     rdi, cs:qword_18000B5A8
000042FE  E8 C4 07 00 00  call    AfxGetModuleState(void)
00004303  48 8B 58 18  mov     rbx, [rax+18h]
00004307  E8 BB 07 00 00  call    AfxGetModuleState(void)
0000430C  48 89 78 18  mov     [rax+18h], rdi
00004310  E8 D0 07 00 00  call    AfxGetThread(void)
00004315  48 85 C0  test    rax, rax
00004318  74 19  jz      short loc_180004333
0000431A  48 8B 10  mov     rdx, [rax]
0000431D  48 8B C8  mov     rcx, rax
00004320  FF 92 F8 00 00 00  call    qword ptr [rdx+0F8h]
00004326  48 85 C0  test    rax, rax
00004329  74 08  jz      short loc_180004333
0000432B  8B CE  mov     ecx, esi
0000432D  E8 9E DE FF FF  call    sub_1800021D0
00004332  90  nop
00004333  E8 8F 07 00 00  call    AfxGetModuleState(void)
00004338  48 89 58 18  mov     [rax+18h], rbx
0000433C  48 8D 4C 24 20  lea     rcx, [rsp+38h+var_18]; this
00004341  E8 8D 07 00 00  call    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)
00004346  33 C0  xor     eax, eax
00004348  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
0000434D  48 8B 74 24 48  mov     rsi, [rsp+38h+arg_8]
00004352  48 83 C4 30  add     rsp, 30h
00004356  5F  pop     rdi
00004357  C3  retn

; FUNC 00004360-000043BE sub_180004360 (94 bytes)
00004360  48 89 54 24 10  mov     [rsp+arg_8], rdx
00004365  4C 89 44 24 18  mov     qword ptr [rsp+arg_10], r8
0000436A  4C 89 4C 24 20  mov     [rsp+arg_18], r9
0000436F  53  push    rbx
00004370  56  push    rsi
00004371  57  push    rdi
00004372  48 83 EC 30  sub     rsp, 30h
00004376  48 8B DA  mov     rbx, rdx
00004379  48 8D 74 24 60  lea     rsi, [rsp+48h+arg_10]
0000437E  48 8B F9  mov     rdi, rcx
00004381  E8 AA EC FF FF  call    __local_stdio_printf_options
00004386  4C 8B CB  mov     r9, rbx; Format
00004389  48 89 74 24 28  mov     [rsp+48h+ArgList], rsi; ArgList
0000438E  48 C7 C3 FF FF FF FF  mov     rbx, 0FFFFFFFFFFFFFFFFh
00004395  48 C7 44 24 20 00 00 00 00  mov     [rsp+48h+Locale], 0; Locale
0000439E  4C 8B C3  mov     r8, rbx; BufferCount
000043A1  48 8B D7  mov     rdx, rdi; Buffer
000043A4  48 8B 08  mov     rcx, [rax]
000043A7  48 83 C9 01  or      rcx, 1; Options
000043AB  FF 15 2F 2E 00 00  call    cs:__stdio_common_vsprintf; api-ms-win-crt-stdio-l1-1-0
000043B1  85 C0  test    eax, eax
000043B3  0F 48 C3  cmovs   eax, ebx
000043B6  48 83 C4 30  add     rsp, 30h
000043BA  5F  pop     rdi
000043BB  5E  pop     rsi
000043BC  5B  pop     rbx
000043BD  C3  retn

; FUNC 000043C0-0000445F sub_1800043C0 (159 bytes)
000043C0  48 89 5C 24 18  mov     [rsp+arg_10], rbx
000043C5  48 89 74 24 20  mov     [rsp+arg_18], rsi
000043CA  48 89 4C 24 08  mov     [rsp+arg_0], rcx
000043CF  57  push    rdi
000043D0  48 83 EC 20  sub     rsp, 20h
000043D4  48 8B F2  mov     rsi, rdx
000043D7  48 8B F9  mov     rdi, rcx
000043DA  BA 70 31 00 00  mov     edx, 3170h; unsigned int
000043DF  E8 B3 06 00 00  call    CMMDialog::CMMDialog(uint,CWnd *)
000043E4  90  nop
000043E5  48 8D 05 AC 3A 00 00  lea     rax, const CFindTemplateDlg::`vftable'
000043EC  48 89 07  mov     [rdi], rax
000043EF  48 8D 9F 50 01 00 00  lea     rbx, [rdi+150h]
000043F6  48 89 5C 24 38  mov     [rsp+28h+arg_8], rbx
000043FB  48 8B CB  mov     rcx, rbx; this
000043FE  E8 54 07 00 00  call    CWnd::CWnd(void)
00004403  48 8D 05 AE 37 00 00  lea     rax, const CTreeCtrl::`vftable'
0000440A  48 89 03  mov     [rbx], rax
0000440D  C7 87 30 01 00 00 02 00 00 00  mov     dword ptr [rdi+130h], 2
00004417  48 8D 8F 38 01 00 00  lea     rcx, [rdi+138h]
0000441E  48 8D 15 AB 3D 00 00  lea     rdx, aSelectTemplate; "Select Template dialog is not shown whe"...
00004425  FF 15 75 31 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::operator=(char const *)
0000442B  48 C7 87 48 01 00 00 00 00 00 00  mov     qword ptr [rdi+148h], 0
00004436  48 89 B7 38 02 00 00  mov     [rdi+238h], rsi
0000443D  48 85 F6  test    rsi, rsi
00004440  74 0A  jz      short loc_18000444C
00004442  48 8B 06  mov     rax, [rsi]
00004445  48 8B CE  mov     rcx, rsi
00004448  FF 50 08  call    qword ptr [rax+8]
0000444B  90  nop
0000444C  48 8B C7  mov     rax, rdi
0000444F  48 8B 5C 24 40  mov     rbx, [rsp+28h+arg_10]
00004454  48 8B 74 24 48  mov     rsi, [rsp+28h+arg_18]
00004459  48 83 C4 20  add     rsp, 20h
0000445D  5F  pop     rdi
0000445E  C3  retn

; FUNC 00004460-000044B8 sub_180004460 (88 bytes)
00004460  40 53  push    rbx
00004462  48 83 EC 20  sub     rsp, 20h
00004466  48 8B D9  mov     rbx, rcx
00004469  48 8D 05 28 3A 00 00  lea     rax, const CFindTemplateDlg::`vftable'
00004470  48 89 01  mov     [rcx], rax
00004473  48 8B 89 38 02 00 00  mov     rcx, [rcx+238h]
0000447A  48 85 C9  test    rcx, rcx
0000447D  74 06  jz      short loc_180004485
0000447F  48 8B 01  mov     rax, [rcx]
00004482  FF 50 10  call    qword ptr [rax+10h]
00004485  48 8D 8B 50 01 00 00  lea     rcx, [rbx+150h]; this
0000448C  E8 E2 08 00 00  call    CTreeCtrl::~CTreeCtrl(void)
00004491  48 8D 8B 40 01 00 00  lea     rcx, [rbx+140h]
00004498  FF 15 0A 31 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(void)
0000449E  48 8D 8B 38 01 00 00  lea     rcx, [rbx+138h]
000044A5  FF 15 FD 30 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(void)
000044AB  48 8B CB  mov     rcx, rbx; this
000044AE  48 83 C4 20  add     rsp, 20h
000044B2  5B  pop     rbx
000044B3  E9 79 08 00 00  jmp     CDialog::~CDialog(void)

; FUNC 000044C0-000044F0 sub_1800044C0 (48 bytes)
000044C0  40 53  push    rbx
000044C2  48 83 EC 20  sub     rsp, 20h
000044C6  48 8B D9  mov     rbx, rcx
000044C9  48 81 C1 40 01 00 00  add     rcx, 140h
000044D0  FF 15 D2 30 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(void)
000044D6  48 8D 8B 38 01 00 00  lea     rcx, [rbx+138h]
000044DD  FF 15 C5 30 00 00  call    cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(void)
000044E3  48 8B CB  mov     rcx, rbx; this
000044E6  48 83 C4 20  add     rsp, 20h
000044EA  5B  pop     rbx
000044EB  E9 41 08 00 00  jmp     CDialog::~CDialog(void)

; FUNC 000044F0-0000453E sub_1800044F0 (78 bytes)
000044F0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000044F5  57  push    rdi
000044F6  48 83 EC 20  sub     rsp, 20h
000044FA  8B FA  mov     edi, edx
000044FC  48 8B D9  mov     rbx, rcx
000044FF  E8 5C FF FF FF  call    sub_180004460
00004504  40 F6 C7 01  test    dil, 1
00004508  74 26  jz      short loc_180004530
0000450A  48 8B CB  mov     rcx, rbx; void *
0000450D  40 F6 C7 04  test    dil, 4
00004511  75 13  jnz     short loc_180004526
00004513  E8 97 05 00 00  call    operator delete(void *)
00004518  48 8B C3  mov     rax, rbx
0000451B  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004520  48 83 C4 20  add     rsp, 20h
00004524  5F  pop     rdi
00004525  C3  retn
00004526  BA 40 02 00 00  mov     edx, 240h
0000452B  E8 60 CB FF FF  call    _guard_check_icall_nop
00004530  48 8B C3  mov     rax, rbx
00004533  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004538  48 83 C4 20  add     rsp, 20h
0000453C  5F  pop     rdi
0000453D  C3  retn

; FUNC 00004540-0000458E sub_180004540 (78 bytes)
00004540  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00004545  57  push    rdi
00004546  48 83 EC 20  sub     rsp, 20h
0000454A  8B FA  mov     edi, edx
0000454C  48 8B D9  mov     rbx, rcx
0000454F  E8 1F 08 00 00  call    CTreeCtrl::~CTreeCtrl(void)
00004554  40 F6 C7 01  test    dil, 1
00004558  74 26  jz      short loc_180004580
0000455A  48 8B CB  mov     rcx, rbx; void *
0000455D  40 F6 C7 04  test    dil, 4
00004561  75 13  jnz     short loc_180004576
00004563  E8 47 05 00 00  call    operator delete(void *)
00004568  48 8B C3  mov     rax, rbx
0000456B  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004570  48 83 C4 20  add     rsp, 20h
00004574  5F  pop     rdi
00004575  C3  retn
00004576  BA E8 00 00 00  mov     edx, 0E8h
0000457B  E8 10 CB FF FF  call    _guard_check_icall_nop
00004580  48 8B C3  mov     rax, rbx
00004583  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004588  48 83 C4 20  add     rsp, 20h
0000458C  5F  pop     rdi
0000458D  C3  retn

; FUNC 00004590-0000459D sub_180004590 (13 bytes)
00004590  48 8B 49 40  mov     rcx, [rcx+40h]
00004594  33 D2  xor     edx, edx
00004596  48 FF 25 83 2B 00 00  jmp     cs:EnableWindow; USER32

; FUNC 000045A0-000045A8 sub_1800045A0 (8 bytes)
000045A0  0F B7 D2  movzx   edx, dx; char *
000045A3  E9 5F 07 00 00  jmp     CDialog::Create(char const *,CWnd *)

; FUNC 000045B0-000045C7 sub_1800045B0 (23 bytes)
000045B0  48 8B C2  mov     rax, rdx
000045B3  4C 8D 81 50 01 00 00  lea     r8, [rcx+150h]; struct CWnd *
000045BA  48 8B C8  mov     rcx, rax; struct CDataExchange *
000045BD  BA 71 31 00 00  mov     edx, 3171h; int
000045C2  E9 36 05 00 00  jmp     DDX_Control(CDataExchange *,int,CWnd &)

; FUNC 000045D0-000045E0 sub_1800045D0 (16 bytes)
000045D0  48 8B 49 40  mov     rcx, [rcx+40h]
000045D4  BA 01 00 00 00  mov     edx, 1
000045D9  48 FF 25 40 2B 00 00  jmp     cs:EnableWindow; USER32

; FUNC 000045E0-000045E5 sub_1800045E0 (5 bytes)
000045E0  E9 0B 00 00 00  jmp     sub_1800045F0

; FUNC 000045F0-000045F8 sub_1800045F0 (8 bytes)
000045F0  48 8D 05 A9 3C 00 00  lea     rax, off_1800082A0
000045F7  C3  retn

; FUNC 00004600-00004633 sub_180004600 (51 bytes)
00004600  40 53  push    rbx
00004602  48 83 EC 20  sub     rsp, 20h
00004606  48 8B D9  mov     rbx, rcx
00004609  48 8B 89 48 01 00 00  mov     rcx, [rcx+148h]
00004610  48 85 C9  test    rcx, rcx
00004613  74 11  jz      short loc_180004626
00004615  48 8B 01  mov     rax, [rcx]
00004618  FF 50 10  call    qword ptr [rax+10h]
0000461B  48 C7 83 48 01 00 00 00 00 00 00  mov     qword ptr [rbx+148h], 0
00004626  48 8B CB  mov     rcx, rbx; this
00004629  48 83 C4 20  add     rsp, 20h
0000462D  5B  pop     rbx
0000462E  E9 F8 06 00 00  jmp     CDialog::OnCancel(void)

; FUNC 00004640-00004648 sub_180004640 (8 bytes)
00004640  49 C7 00 00 00 00 00  mov     qword ptr [r8], 0
00004647  C3  retn

; FUNC 00004650-00004682 sub_180004650 (50 bytes)
00004650  40 53  push    rbx
00004652  48 83 EC 20  sub     rsp, 20h
00004656  48 8B 4A 50  mov     rcx, [rdx+50h]
0000465A  49 8B D8  mov     rbx, r8
0000465D  48 85 C9  test    rcx, rcx
00004660  74 13  jz      short loc_180004675
00004662  48 8B 01  mov     rax, [rcx]
00004665  FF 50 10  call    qword ptr [rax+10h]
00004668  48 C7 03 00 00 00 00  mov     qword ptr [rbx], 0
0000466F  48 83 C4 20  add     rsp, 20h
00004673  5B  pop     rbx
00004674  C3  retn
00004675  49 C7 00 00 00 00 00  mov     qword ptr [r8], 0
0000467C  48 83 C4 20  add     rsp, 20h
00004680  5B  pop     rbx
00004681  C3  retn

; FUNC 00004690-000049C9 sub_180004690 (825 bytes)
00004690  48 89 5C 24 20  mov     [rsp-8+arg_18], rbx
00004695  55  push    rbp
00004696  57  push    rdi
00004697  41 54  push    r12
00004699  41 55  push    r13
0000469B  41 57  push    r15
0000469D  48 8D 6C 24 C9  lea     rbp, [rsp-37h]
000046A2  48 81 EC D0 00 00 00  sub     rsp, 0D0h
000046A9  48 8B 05 38 6D 00 00  mov     rax, cs:__security_cookie
000046B0  48 33 C4  xor     rax, rsp
000046B3  48 89 45 27  mov     [rbp+57h+var_30], rax
000046B7  4C 8B F9  mov     r15, rcx
000046BA  E8 5A 06 00 00  call    CDialog::OnInitDialog(void)
000046BF  BA 01 00 00 00  mov     edx, 1; int
000046C4  49 8B CF  mov     rcx, r15; this
000046C7  E8 BB 04 00 00  call    CWnd::GetDlgItem(int)
000046CC  48 8B C8  mov     rcx, rax; this
000046CF  33 D2  xor     edx, edx; int
000046D1  E8 C9 04 00 00  call    CWnd::EnableWindow(int)
000046D6  33 FF  xor     edi, edi
000046D8  8B DF  mov     ebx, edi
000046DA  44 8D 6F 01  lea     r13d, [rdi+1]
000046DE  49 39 9F 38 02 00 00  cmp     [r15+238h], rbx
000046E5  75 13  jnz     short loc_1800046FA
000046E7  48 8B 0D 32 2F 00 00  mov     rcx, cs:CApwnLibraries * g_pApwnLibs; mmstruct
000046EE  48 8B 09  mov     rcx, [rcx]
000046F1  FF 15 39 2F 00 00  call    cs:CApwnLibraries::CountLibraries(void); mmstruct
000046F7  44 8B E8  mov     r13d, eax
000046FA  44 8B E7  mov     r12d, edi
000046FD  45 85 ED  test    r13d, r13d
00004700  0F 8E 9A 02 00 00  jle     loc_1800049A0
00004706  48 89 B4 24 08 01 00 00  mov     [rsp+0F0h+arg_8], rsi
0000470E  4C 89 B4 24 10 01 00 00  mov     [rsp+0F0h+arg_10], r14
00004716  66 66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00004720  4D 8B B7 38 02 00 00  mov     r14, [r15+238h]
00004727  4D 85 F6  test    r14, r14
0000472A  74 0B  jz      short loc_180004737
0000472C  49 8B 06  mov     rax, [r14]
0000472F  49 8B CE  mov     rcx, r14
00004732  FF 50 08  call    qword ptr [rax+8]
00004735  EB 1F  jmp     short loc_180004756
00004737  48 8B 0D E2 2E 00 00  mov     rcx, cs:CApwnLibraries * g_pApwnLibs; mmstruct
0000473E  41 8B D4  mov     edx, r12d
00004741  48 8B 09  mov     rcx, [rcx]
00004744  FF 15 C6 2E 00 00  call    cs:CApwnLibraries::GetLibrary(int); mmstruct
0000474A  4C 8B F0  mov     r14, rax
0000474D  48 85 C0  test    rax, rax
00004750  0F 84 11 02 00 00  jz      loc_180004967
00004756  49 8B 06  mov     rax, [r14]
00004759  48 8D 55 B7  lea     rdx, [rbp+57h+var_A0]
0000475D  49 8B CE  mov     rcx, r14
00004760  C7 45 B7 01 00 00 00  mov     [rbp+57h+var_A0], 1
00004767  FF 50 30  call    qword ptr [rax+30h]
0000476A  83 7D B7 00  cmp     [rbp+57h+var_A0], 0
0000476E  0F 85 EA 01 00 00  jnz     loc_18000495E
00004774  49 8B 06  mov     rax, [r14]
00004777  48 8D 55 E7  lea     rdx, [rbp+57h+var_70]
0000477B  41 B8 40 00 00 00  mov     r8d, 40h ; '@'
00004781  49 8B CE  mov     rcx, r14
00004784  FF 50 38  call    qword ptr [rax+38h]
00004787  49 8B 06  mov     rax, [r14]
0000478A  4C 8D 45 D7  lea     r8, [rbp+57h+var_80]
0000478E  48 8D 15 6B 2F 00 00  lea     rdx, unk_180007700
00004795  48 89 7D D7  mov     [rbp+57h+var_80], rdi
00004799  49 8B CE  mov     rcx, r14
0000479C  48 8B F7  mov     rsi, rdi
0000479F  FF 10  call    qword ptr [rax]
000047A1  85 C0  test    eax, eax
000047A3  0F 88 B5 01 00 00  js      loc_18000495E
000047A9  48 8B 4D D7  mov     rcx, [rbp+57h+var_80]
000047AD  48 8D 55 C7  lea     rdx, [rbp+57h+var_90]
000047B1  48 89 7D C7  mov     [rbp+57h+var_90], rdi
000047B5  48 8B 01  mov     rax, [rcx]
000047B8  FF 50 40  call    qword ptr [rax+40h]
000047BB  85 C0  test    eax, eax
000047BD  0F 88 71 01 00 00  js      loc_180004934
000047C3  48 8B 4D C7  mov     rcx, [rbp+57h+var_90]
000047C7  4C 8D 45 BF  lea     r8, [rbp+57h+var_98]
000047CB  45 33 C9  xor     r9d, r9d
000047CE  48 8B 01  mov     rax, [rcx]
000047D1  41 8D 51 01  lea     edx, [r9+1]
000047D5  FF 50 18  call    qword ptr [rax+18h]
000047D8  85 C0  test    eax, eax
000047DA  0F 85 4A 01 00 00  jnz     loc_18000492A
000047E0  48 8B 4D BF  mov     rcx, [rbp+57h+var_98]
000047E4  4C 8D 45 CF  lea     r8, [rbp+57h+var_88]
000047E8  48 89 7D CF  mov     [rbp+57h+var_88], rdi
000047EC  48 8D 15 1D 2F 00 00  lea     rdx, unk_180007710
000047F3  48 8B 01  mov     rax, [rcx]
000047F6  FF 10  call    qword ptr [rax]
000047F8  85 C0  test    eax, eax
000047FA  0F 88 03 01 00 00  js      loc_180004903
00004800  48 8B 4D CF  mov     rcx, [rbp+57h+var_88]
00004804  48 8D 55 BB  lea     rdx, [rbp+57h+var_9C]
00004808  89 7D BB  mov     [rbp+57h+var_9C], edi
0000480B  48 8B 01  mov     rax, [rcx]
0000480E  FF 50 20  call    qword ptr [rax+20h]
00004811  48 8B 4D CF  mov     rcx, [rbp+57h+var_88]
00004815  48 8B 01  mov     rax, [rcx]
00004818  FF 50 10  call    qword ptr [rax+10h]
0000481B  83 7D BB 00  cmp     [rbp+57h+var_9C], 0
0000481F  0F 84 DE 00 00 00  jz      loc_180004903
00004825  48 85 F6  test    rsi, rsi
00004828  75 43  jnz     short loc_18000486D
0000482A  48 C7 44 24 48 02 00 FF FF  mov     [rsp+0F0h+var_A8], 0FFFFFFFFFFFF0002h; _TREEITEM *
00004833  49 8D 8F 50 01 00 00  lea     rcx, [r15+150h]; this
0000483A  48 C7 44 24 40 00 00 FF FF  mov     [rsp+0F0h+var_B0], 0FFFFFFFFFFFF0000h; _TREEITEM *
00004843  4C 8D 45 E7  lea     r8, [rbp+57h+var_70]; char *
00004847  48 89 7C 24 38  mov     qword ptr [rsp+0F0h+var_B8], rdi; __int64
0000484C  8D 56 01  lea     edx, [rsi+1]; unsigned int
0000484F  89 7C 24 30  mov     [rsp+0F0h+var_C0], edi; unsigned int
00004853  45 33 C9  xor     r9d, r9d; int
00004856  89 7C 24 28  mov     [rsp+0F0h+var_C8], edi; unsigned int
0000485A  89 7C 24 20  mov     [rsp+0F0h+var_D0], edi; int
0000485E  E8 0A 05 00 00  call    CTreeCtrl::InsertItem(uint,char const *,int,int,uint,uint,__int64,_TREEITEM *,_TREEITEM *)
00004863  48 85 DB  test    rbx, rbx
00004866  48 8B F0  mov     rsi, rax
00004869  48 0F 44 D8  cmovz   rbx, rax
0000486D  48 8B 4D BF  mov     rcx, [rbp+57h+var_98]
00004871  48 8D 55 E7  lea     rdx, [rbp+57h+var_70]
00004875  41 B8 40 00 00 00  mov     r8d, 40h ; '@'
0000487B  48 8B 01  mov     rax, [rcx]
0000487E  FF 50 18  call    qword ptr [rax+18h]
00004881  48 8B 4D BF  mov     rcx, [rbp+57h+var_98]
00004885  4C 8D 45 DF  lea     r8, [rbp+57h+var_78]
00004889  48 89 7D DF  mov     [rbp+57h+var_78], rdi
0000488D  48 8D 15 8C 2E 00 00  lea     rdx, unk_180007720
00004894  48 8B 01  mov     rax, [rcx]
00004897  FF 10  call    qword ptr [rax]
00004899  33 C0  xor     eax, eax
0000489B  48 C7 44 24 48 02 00 FF FF  mov     [rsp+0F0h+var_A8], 0FFFFFFFFFFFF0002h; _TREEITEM *
000048A4  48 89 74 24 40  mov     [rsp+0F0h+var_B0], rsi; _TREEITEM *
000048A9  4C 8D 45 E7  lea     r8, [rbp+57h+var_70]; char *
000048AD  48 89 44 24 38  mov     qword ptr [rsp+0F0h+var_B8], rax; __int64
000048B2  49 8D 8F 50 01 00 00  lea     rcx, [r15+150h]; this
000048B9  89 44 24 30  mov     [rsp+0F0h+var_C0], eax; unsigned int
000048BD  45 33 C9  xor     r9d, r9d; int
000048C0  89 44 24 28  mov     [rsp+0F0h+var_C8], eax; unsigned int
000048C4  8D 50 01  lea     edx, [rax+1]; unsigned int
000048C7  89 44 24 20  mov     [rsp+0F0h+var_D0], eax; int
000048CB  E8 9D 04 00 00  call    CTreeCtrl::InsertItem(uint,char const *,int,int,uint,uint,__int64,_TREEITEM *,_TREEITEM *)
000048D0  48 8B D0  mov     rdx, rax; _TREEITEM *
000048D3  49 8D 8F 50 01 00 00  lea     rcx, [r15+150h]; this
000048DA  48 8B 45 DF  mov     rax, [rbp+57h+var_78]
000048DE  45 33 C9  xor     r9d, r9d; char *
000048E1  48 89 44 24 40  mov     [rsp+0F0h+var_B0], rax; __int64
000048E6  33 C0  xor     eax, eax
000048E8  89 44 24 38  mov     [rsp+0F0h+var_B8], eax; unsigned int
000048EC  89 44 24 30  mov     [rsp+0F0h+var_C0], eax; unsigned int
000048F0  89 44 24 28  mov     [rsp+0F0h+var_C8], eax; int
000048F4  44 8D 40 04  lea     r8d, [rax+4]; unsigned int
000048F8  89 44 24 20  mov     [rsp+0F0h+var_D0], eax; int
000048FC  E8 66 04 00 00  call    CTreeCtrl::SetItem(_TREEITEM *,uint,char const *,int,int,uint,uint,__int64)
00004901  33 FF  xor     edi, edi
00004903  48 8B 4D BF  mov     rcx, [rbp+57h+var_98]
00004907  48 8B 01  mov     rax, [rcx]
0000490A  FF 50 10  call    qword ptr [rax+10h]
0000490D  48 8B 4D C7  mov     rcx, [rbp+57h+var_90]
00004911  4C 8D 45 BF  lea     r8, [rbp+57h+var_98]
00004915  45 33 C9  xor     r9d, r9d
00004918  48 8B 01  mov     rax, [rcx]
0000491B  41 8D 51 01  lea     edx, [r9+1]
0000491F  FF 50 18  call    qword ptr [rax+18h]
00004922  85 C0  test    eax, eax
00004924  0F 84 B6 FE FF FF  jz      loc_1800047E0
0000492A  48 8B 4D C7  mov     rcx, [rbp+57h+var_90]
0000492E  48 8B 01  mov     rax, [rcx]
00004931  FF 50 10  call    qword ptr [rax+10h]
00004934  48 8B 4D D7  mov     rcx, [rbp+57h+var_80]
00004938  48 8B 01  mov     rax, [rcx]
0000493B  FF 50 10  call    qword ptr [rax+10h]
0000493E  48 85 F6  test    rsi, rsi
00004941  74 1B  jz      short loc_18000495E
00004943  49 8B 8F 90 01 00 00  mov     rcx, [r15+190h]; hWnd
0000494A  4C 8B CE  mov     r9, rsi; lParam
0000494D  BA 02 11 00 00  mov     edx, 1102h; Msg
00004952  41 B8 02 00 00 00  mov     r8d, 2; wParam
00004958  FF 15 AA 27 00 00  call    cs:SendMessageA; USER32
0000495E  49 8B 06  mov     rax, [r14]
00004961  49 8B CE  mov     rcx, r14
00004964  FF 50 10  call    qword ptr [rax+10h]
00004967  41 FF C4  inc     r12d
0000496A  45 3B E5  cmp     r12d, r13d
0000496D  0F 8C AD FD FF FF  jl      loc_180004720
00004973  4C 8B B4 24 10 01 00 00  mov     r14, [rsp+0F0h+arg_10]
0000497B  48 8B B4 24 08 01 00 00  mov     rsi, [rsp+0F0h+arg_8]
00004983  48 85 DB  test    rbx, rbx
00004986  74 18  jz      short loc_1800049A0
00004988  49 8B 8F 90 01 00 00  mov     rcx, [r15+190h]; hWnd
0000498F  4C 8B CB  mov     r9, rbx; lParam
00004992  45 33 C0  xor     r8d, r8d; wParam
00004995  BA 14 11 00 00  mov     edx, 1114h; Msg
0000499A  FF 15 68 27 00 00  call    cs:SendMessageA; USER32
000049A0  B8 01 00 00 00  mov     eax, 1
000049A5  48 8B 4D 27  mov     rcx, [rbp+57h+var_30]
000049A9  48 33 CC  xor     rcx, rsp; StackCookie
000049AC  E8 EF 08 00 00  call    __security_check_cookie
000049B1  48 8B 9C 24 18 01 00 00  mov     rbx, [rsp+0F0h+arg_18]
000049B9  48 81 C4 D0 00 00 00  add     rsp, 0D0h
000049C0  41 5F  pop     r15
000049C2  41 5D  pop     r13
000049C4  41 5C  pop     r12
000049C6  5F  pop     rdi
000049C7  5D  pop     rbp
000049C8  C3  retn

; FUNC 000049D0-00004A55 sub_1800049D0 (133 bytes)
000049D0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000049D5  48 89 74 24 10  mov     [rsp+arg_8], rsi
000049DA  57  push    rdi
000049DB  48 83 EC 20  sub     rsp, 20h
000049DF  48 8B D9  mov     rbx, rcx
000049E2  49 8B F0  mov     rsi, r8
000049E5  48 8B 89 48 01 00 00  mov     rcx, [rcx+148h]
000049EC  48 8B FA  mov     rdi, rdx
000049EF  48 85 C9  test    rcx, rcx
000049F2  74 11  jz      short loc_180004A05
000049F4  48 8B 01  mov     rax, [rcx]
000049F7  FF 50 10  call    qword ptr [rax+10h]
000049FA  48 C7 83 48 01 00 00 00 00 00 00  mov     qword ptr [rbx+148h], 0
00004A05  48 8B 8F 88 00 00 00  mov     rcx, [rdi+88h]
00004A0C  48 89 8B 48 01 00 00  mov     [rbx+148h], rcx
00004A13  48 85 C9  test    rcx, rcx
00004A16  74 0F  jz      short loc_180004A27
00004A18  48 8B 01  mov     rax, [rcx]
00004A1B  FF 50 08  call    qword ptr [rax+8]
00004A1E  BA 01 00 00 00  mov     edx, 1
00004A23  8B FA  mov     edi, edx
00004A25  EB 05  jmp     short loc_180004A2C
00004A27  33 FF  xor     edi, edi
00004A29  8D 57 01  lea     edx, [rdi+1]; int
00004A2C  48 8B CB  mov     rcx, rbx; this
00004A2F  E8 53 01 00 00  call    CWnd::GetDlgItem(int)
00004A34  48 8B C8  mov     rcx, rax; this
00004A37  8B D7  mov     edx, edi; int
00004A39  E8 61 01 00 00  call    CWnd::EnableWindow(int)
00004A3E  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004A43  48 C7 06 00 00 00 00  mov     qword ptr [rsi], 0
00004A4A  48 8B 74 24 38  mov     rsi, [rsp+28h+arg_8]
00004A4F  48 83 C4 20  add     rsp, 20h
00004A53  5F  pop     rdi
00004A54  C3  retn

; FUNC 00004A60-00004A85 gxDelStruct (37 bytes)
00004A60  48 83 EC 28  sub     rsp, 28h
00004A64  48 8B 05 8D 6C 00 00  mov     rax, cs:qword_18000B6F8
00004A6B  48 85 C0  test    rax, rax
00004A6E  74 0E  jz      short loc_180004A7E
00004A70  48 8B 0D A1 6B 00 00  mov     rcx, cs:qword_18000B618
00004A77  48 85 C9  test    rcx, rcx
00004A7A  74 02  jz      short loc_180004A7E
00004A7C  FF D0  call    rax ; qword_18000B6F8
00004A7E  33 C0  xor     eax, eax
00004A80  48 83 C4 28  add     rsp, 28h
00004A84  C3  retn

; FUNC 00004A85-00004A8B MMGetSuppress (6 bytes)
00004A85  FF 25 9D 2B 00 00  jmp     cs:__imp_MMGetSuppress; mmstruct

; FUNC 00004A8B-00004A91 ?DoModal@CMMDialog@@UEAA_JXZ (6 bytes)
00004A8B  FF 25 77 2B 00 00  jmp     cs:CMMDialog::DoModal(void); mmstruct

; FUNC 00004A91-00004A97 GetGlobalPointer (6 bytes)
00004A91  FF 25 69 2B 00 00  jmp     cs:__imp_GetGlobalPointer; mmstruct

; FUNC 00004A97-00004A9D ??0CMMDialog@@QEAA@IPEAVCWnd@@@Z (6 bytes)
00004A97  FF 25 7B 2B 00 00  jmp     cs:CMMDialog::CMMDialog(uint,CWnd *); mmstruct

; FUNC 00004A9D-00004AA3 ?InitSuppressed@CMMDialog@@MEAAXXZ (6 bytes)
00004A9D  FF 25 95 2B 00 00  jmp     cs:CMMDialog::InitSuppressed(void); mmstruct

; FUNC 00004AA3-00004AA9 ?AfxThrowMemoryException@@YAXXZ (6 bytes)
00004AA3  FF 25 3F 2B 00 00  jmp     cs:AfxThrowMemoryException(void)

; FUNC 00004AA9-00004AAF ?AfxThrowOleException@@YAXJ@Z (6 bytes)
00004AA9  FF 25 31 2B 00 00  jmp     cs:AfxThrowOleException(long)

; FUNC 00004AAF-00004AB5 ??3@YAXPEAX@Z (6 bytes)
00004AAF  FF 25 23 2B 00 00  jmp     cs:operator delete(void *)

; FUNC 00004AB5-00004ABB ??2@YAPEAX_K@Z (6 bytes)
00004AB5  FF 25 15 2B 00 00  jmp     cs:operator new(unsigned __int64)

; FUNC 00004ABB-00004AC1 ??_V@YAXPEAX@Z (6 bytes)
00004ABB  FF 25 07 2B 00 00  jmp     cs:operator delete[](void *)

; FUNC 00004AC1-00004AC7 ?Delete@CException@@QEAAXXZ (6 bytes)
00004AC1  FF 25 F9 2A 00 00  jmp     cs:CException::Delete(void)

; FUNC 00004AC7-00004ACD ?AfxGetModuleState@@YAPEAVAFX_MODULE_STATE@@XZ (6 bytes)
00004AC7  FF 25 CB 2A 00 00  jmp     cs:AfxGetModuleState(void)

; FUNC 00004ACD-00004AD3 ??0AFX_MAINTAIN_STATE2@@QEAA@PEAVAFX_MODULE_STATE@@@Z (6 bytes)
00004ACD  FF 25 BD 2A 00 00  jmp     cs:AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(AFX_MODULE_STATE *)

; FUNC 00004AD3-00004AD9 ??1AFX_MAINTAIN_STATE2@@QEAA@XZ (6 bytes)
00004AD3  FF 25 AF 2A 00 00  jmp     cs:AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(void)

; FUNC 00004AD9-00004ADF ?RestoreWaitCursor@CCmdTarget@@QEAAXXZ (6 bytes)
00004AD9  FF 25 A1 2A 00 00  jmp     cs:CCmdTarget::RestoreWaitCursor(void)

; FUNC 00004ADF-00004AE5 ?FromHandle@CWnd@@SAPEAV1@PEAUHWND__@@@Z (6 bytes)
00004ADF  FF 25 7B 2A 00 00  jmp     cs:CWnd::FromHandle(HWND__ *)

; FUNC 00004AE5-00004AEB ?AfxGetThread@@YAPEAVCWinThread@@XZ (6 bytes)
00004AE5  FF 25 5D 2A 00 00  jmp     cs:AfxGetThread(void)

; FUNC 00004AEB-00004AF1 ??0CDynLinkLibrary@@QEAA@AEAUAFX_EXTENSION_MODULE@@H@Z (6 bytes)
00004AEB  FF 25 4F 2A 00 00  jmp     cs:CDynLinkLibrary::CDynLinkLibrary(AFX_EXTENSION_MODULE &,int)

; FUNC 00004AF1-00004AF7 ?AfxInitExtensionModule@@YAHAEAUAFX_EXTENSION_MODULE@@PEAUHINSTANCE__@@@Z (6 bytes)
00004AF1  FF 25 41 2A 00 00  jmp     cs:AfxInitExtensionModule(AFX_EXTENSION_MODULE &,HINSTANCE__ *)

; FUNC 00004AF7-00004AFD ??0COleVariant@@QEAA@JG@Z (6 bytes)
00004AF7  FF 25 33 2A 00 00  jmp     cs:COleVariant::COleVariant(long,ushort)

; FUNC 00004AFD-00004B03 ?DDX_Control@@YAXPEAVCDataExchange@@HAEAVCWnd@@@Z (6 bytes)
00004AFD  FF 25 25 2A 00 00  jmp     cs:DDX_Control(CDataExchange *,int,CWnd &)

; FUNC 00004B03-00004B09 ?OnCmdMsg@CCmdTarget@@UEAAHIHPEAXPEAUAFX_CMDHANDLERINFO@@@Z (6 bytes)
00004B03  FF 25 17 2A 00 00  jmp     cs:CCmdTarget::OnCmdMsg(uint,int,void *,AFX_CMDHANDLERINFO *)

; FUNC 00004B09-00004B0F ?IsInvokeAllowed@CCmdTarget@@UEAAHJ@Z (6 bytes)
00004B09  FF 25 09 2A 00 00  jmp     cs:CCmdTarget::IsInvokeAllowed(long)

; FUNC 00004B0F-00004B15 ?GetDispatchIID@CCmdTarget@@UEAAHPEAU_GUID@@@Z (6 bytes)
00004B0F  FF 25 FB 29 00 00  jmp     cs:CCmdTarget::GetDispatchIID(_GUID *)

; FUNC 00004B15-00004B1B ?GetTypeInfoCount@CCmdTarget@@UEAAIXZ (6 bytes)
00004B15  FF 25 ED 29 00 00  jmp     cs:CCmdTarget::GetTypeInfoCount(void)

; FUNC 00004B1B-00004B21 ?GetTypeLibCache@CCmdTarget@@UEAAPEAVCTypeLibCache@@XZ (6 bytes)
00004B1B  FF 25 DF 29 00 00  jmp     cs:CCmdTarget::GetTypeLibCache(void)

; FUNC 00004B21-00004B27 ?GetTypeLib@CCmdTarget@@UEAAJKPEAPEAUITypeLib@@@Z (6 bytes)
00004B21  FF 25 D1 29 00 00  jmp     cs:CCmdTarget::GetTypeLib(ulong,ITypeLib * *)

; FUNC 00004B27-00004B2D ?GetCommandMap@CCmdTarget@@MEBAPEBUAFX_OLECMDMAP@@XZ (6 bytes)
00004B27  FF 25 C3 29 00 00  jmp     cs:CCmdTarget::GetCommandMap(void)

; FUNC 00004B2D-00004B33 ?GetDispatchMap@CCmdTarget@@MEBAPEBUAFX_DISPMAP@@XZ (6 bytes)
00004B2D  FF 25 B5 29 00 00  jmp     cs:CCmdTarget::GetDispatchMap(void)

; FUNC 00004B33-00004B39 ?GetConnectionMap@CCmdTarget@@MEBAPEBUAFX_CONNECTIONMAP@@XZ (6 bytes)
00004B33  FF 25 A7 29 00 00  jmp     cs:CCmdTarget::GetConnectionMap(void)

; FUNC 00004B39-00004B3F ?GetEventSinkMap@CCmdTarget@@MEBAPEBUAFX_EVENTSINKMAP@@XZ (6 bytes)
00004B39  FF 25 99 29 00 00  jmp     cs:CCmdTarget::GetEventSinkMap(void)

; FUNC 00004B3F-00004B45 ?OnCreateAggregates@CCmdTarget@@UEAAHXZ (6 bytes)
00004B3F  FF 25 8B 29 00 00  jmp     cs:CCmdTarget::OnCreateAggregates(void)

; FUNC 00004B45-00004B4B ?GetInterfaceHook@CCmdTarget@@UEAAPEAUIUnknown@@PEBX@Z (6 bytes)
00004B45  FF 25 7D 29 00 00  jmp     cs:CCmdTarget::GetInterfaceHook(void const *)

; FUNC 00004B4B-00004B51 ?GetExtraConnectionPoints@CCmdTarget@@MEAAHPEAVCPtrArray@@@Z (6 bytes)
00004B4B  FF 25 6F 29 00 00  jmp     cs:CCmdTarget::GetExtraConnectionPoints(CPtrArray *)

; FUNC 00004B51-00004B57 ?GetConnectionHook@CCmdTarget@@MEAAPEAUIConnectionPoint@@AEBU_GUID@@@Z (6 bytes)
00004B51  FF 25 61 29 00 00  jmp     cs:CCmdTarget::GetConnectionHook(_GUID const &)

; FUNC 00004B57-00004B5D ??0CWnd@@QEAA@XZ (6 bytes)
00004B57  FF 25 53 29 00 00  jmp     cs:CWnd::CWnd(void)

; FUNC 00004B5D-00004B63 ?PreSubclassWindow@CWnd@@UEAAXXZ (6 bytes)
00004B5D  FF 25 45 29 00 00  jmp     cs:CWnd::PreSubclassWindow(void)

; FUNC 00004B63-00004B69 ?Create@CWnd@@UEAAHPEBD0KAEBUtagRECT@@PEAV1@IPEAUCCreateContext@@@Z (6 bytes)
00004B63  FF 25 37 29 00 00  jmp     cs:CWnd::Create(char const *,char const *,ulong,tagRECT const &,CWnd *,uint,CCreateContext *)

; FUNC 00004B69-00004B6F ?CreateEx@CWnd@@UEAAHKPEBD0KHHHHPEAUHWND__@@PEAUHMENU__@@PEAX@Z (6 bytes)
00004B69  FF 25 29 29 00 00  jmp     cs:CWnd::CreateEx(ulong,char const *,char const *,ulong,int,int,int,int,HWND__ *,HMENU__ *,void *)

; FUNC 00004B6F-00004B75 ?CreateEx@CWnd@@UEAAHKPEBD0KAEBUtagRECT@@PEAV1@IPEAX@Z (6 bytes)
00004B6F  FF 25 1B 29 00 00  jmp     cs:CWnd::CreateEx(ulong,char const *,char const *,ulong,tagRECT const &,CWnd *,uint,void *)

; FUNC 00004B75-00004B7B ?DestroyWindow@CWnd@@UEAAHXZ (6 bytes)
00004B75  FF 25 0D 29 00 00  jmp     cs:CWnd::DestroyWindow(void)

; FUNC 00004B7B-00004B81 ?PreCreateWindow@CWnd@@UEAAHAEAUtagCREATESTRUCTA@@@Z (6 bytes)
00004B7B  FF 25 FF 28 00 00  jmp     cs:CWnd::PreCreateWindow(tagCREATESTRUCTA &)

; FUNC 00004B81-00004B87 ?CalcWindowRect@CWnd@@UEAAXPEAUtagRECT@@I@Z (6 bytes)
00004B81  FF 25 D9 28 00 00  jmp     cs:CWnd::CalcWindowRect(tagRECT *,uint)

; FUNC 00004B87-00004B8D ?GetDlgItem@CWnd@@QEBAPEAV1@H@Z (6 bytes)
00004B87  FF 25 CB 28 00 00  jmp     cs:CWnd::GetDlgItem(int)

; FUNC 00004B8D-00004B93 ?GetMenu@CWnd@@UEBAPEAVCMenu@@XZ (6 bytes)
00004B8D  FF 25 BD 28 00 00  jmp     cs:CWnd::GetMenu(void)

; FUNC 00004B93-00004B99 ?SetMenu@CWnd@@UEAAHPEAVCMenu@@@Z (6 bytes)
00004B93  FF 25 AF 28 00 00  jmp     cs:CWnd::SetMenu(CMenu *)

; FUNC 00004B99-00004B9F ?OnToolHitTest@CWnd@@UEBA_JVCPoint@@PEAUtagTOOLINFOA@@@Z (6 bytes)
00004B99  FF 25 A1 28 00 00  jmp     cs:CWnd::OnToolHitTest(CPoint,tagTOOLINFOA *)

; FUNC 00004B9F-00004BA5 ?EnableWindow@CWnd@@QEAAHH@Z (6 bytes)
00004B9F  FF 25 93 28 00 00  jmp     cs:CWnd::EnableWindow(int)

; FUNC 00004BA5-00004BAB ?GetScrollBarCtrl@CWnd@@UEBAPEAVCScrollBar@@H@Z (6 bytes)
00004BA5  FF 25 85 28 00 00  jmp     cs:CWnd::GetScrollBarCtrl(int)

; FUNC 00004BAB-00004BB1 ?WinHelpA@CWnd@@UEAAX_KI@Z (6 bytes)
00004BAB  FF 25 77 28 00 00  jmp     cs:CWnd::WinHelpA(unsigned __int64,uint)

; FUNC 00004BB1-00004BB7 ?HtmlHelpA@CWnd@@UEAAX_KI@Z (6 bytes)
00004BB1  FF 25 69 28 00 00  jmp     cs:CWnd::HtmlHelpA(unsigned __int64,uint)

; FUNC 00004BB7-00004BBD ?WinHelpInternal@CWnd@@UEAAX_KI@Z (6 bytes)
00004BB7  FF 25 5B 28 00 00  jmp     cs:CWnd::WinHelpInternal(unsigned __int64,uint)

; FUNC 00004BBD-00004BC3 ?ContinueModal@CWnd@@UEAAHXZ (6 bytes)
00004BBD  FF 25 4D 28 00 00  jmp     cs:CWnd::ContinueModal(void)

; FUNC 00004BC3-00004BC9 ?EndModalLoop@CWnd@@UEAAXH@Z (6 bytes)
00004BC3  FF 25 3F 28 00 00  jmp     cs:CWnd::EndModalLoop(int)

; FUNC 00004BC9-00004BCF ?OnDrawIconicThumbnailOrLivePreview@CWnd@@UEAAXAEAVCDC@@VCRect@@VCSize@@HAEAH@Z (6 bytes)
00004BC9  FF 25 31 28 00 00  jmp     cs:CWnd::OnDrawIconicThumbnailOrLivePreview(CDC &,CRect,CSize,int,int &)

; FUNC 00004BCF-00004BD5 ?GetInterfaceMap@CWnd@@MEBAPEBUAFX_INTERFACEMAP@@XZ (6 bytes)
00004BCF  FF 25 23 28 00 00  jmp     cs:CWnd::GetInterfaceMap(void)

; FUNC 00004BD5-00004BDB ?EnsureStdObj@CWnd@@UEAAJXZ (6 bytes)
00004BD5  FF 25 15 28 00 00  jmp     cs:CWnd::EnsureStdObj(void)

; FUNC 00004BDB-00004BE1 ?get_accParent@CWnd@@UEAAJPEAPEAUIDispatch@@@Z (6 bytes)
00004BDB  FF 25 07 28 00 00  jmp     cs:CWnd::get_accParent(IDispatch * *)

; FUNC 00004BE1-00004BE7 ?get_accChildCount@CWnd@@UEAAJPEAJ@Z (6 bytes)
00004BE1  FF 25 F9 27 00 00  jmp     cs:CWnd::get_accChildCount(long *)

; FUNC 00004BE7-00004BED ?get_accChild@CWnd@@UEAAJUtagVARIANT@@PEAPEAUIDispatch@@@Z (6 bytes)
00004BE7  FF 25 EB 27 00 00  jmp     cs:CWnd::get_accChild(tagVARIANT,IDispatch * *)

; FUNC 00004BED-00004BF3 ?get_accName@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z (6 bytes)
00004BED  FF 25 DD 27 00 00  jmp     cs:CWnd::get_accName(tagVARIANT,wchar_t * *)

; FUNC 00004BF3-00004BF9 ?get_accValue@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z (6 bytes)
00004BF3  FF 25 CF 27 00 00  jmp     cs:CWnd::get_accValue(tagVARIANT,wchar_t * *)

; FUNC 00004BF9-00004BFF ?get_accDescription@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z (6 bytes)
00004BF9  FF 25 C1 27 00 00  jmp     cs:CWnd::get_accDescription(tagVARIANT,wchar_t * *)

; FUNC 00004BFF-00004C05 ?get_accRole@CWnd@@UEAAJUtagVARIANT@@PEAU2@@Z (6 bytes)
00004BFF  FF 25 B3 27 00 00  jmp     cs:CWnd::get_accRole(tagVARIANT,tagVARIANT *)

; FUNC 00004C05-00004C0B ?get_accState@CWnd@@UEAAJUtagVARIANT@@PEAU2@@Z (6 bytes)
00004C05  FF 25 A5 27 00 00  jmp     cs:CWnd::get_accState(tagVARIANT,tagVARIANT *)

; FUNC 00004C0B-00004C11 ?get_accHelp@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z (6 bytes)
00004C0B  FF 25 97 27 00 00  jmp     cs:CWnd::get_accHelp(tagVARIANT,wchar_t * *)

; FUNC 00004C11-00004C17 ?get_accHelpTopic@CWnd@@UEAAJPEAPEA_WUtagVARIANT@@PEAJ@Z (6 bytes)
00004C11  FF 25 89 27 00 00  jmp     cs:CWnd::get_accHelpTopic(wchar_t * *,tagVARIANT,long *)

; FUNC 00004C17-00004C1D ?get_accKeyboardShortcut@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z (6 bytes)
00004C17  FF 25 7B 27 00 00  jmp     cs:CWnd::get_accKeyboardShortcut(tagVARIANT,wchar_t * *)

; FUNC 00004C1D-00004C23 ?get_accFocus@CWnd@@UEAAJPEAUtagVARIANT@@@Z (6 bytes)
00004C1D  FF 25 6D 27 00 00  jmp     cs:CWnd::get_accFocus(tagVARIANT *)

; FUNC 00004C23-00004C29 ?get_accSelection@CWnd@@UEAAJPEAUtagVARIANT@@@Z (6 bytes)
00004C23  FF 25 47 29 00 00  jmp     cs:CWnd::get_accSelection(tagVARIANT *)

; FUNC 00004C29-00004C2F ?get_accDefaultAction@CWnd@@UEAAJUtagVARIANT@@PEAPEA_W@Z (6 bytes)
00004C29  FF 25 51 27 00 00  jmp     cs:CWnd::get_accDefaultAction(tagVARIANT,wchar_t * *)

; FUNC 00004C2F-00004C35 ?accSelect@CWnd@@UEAAJJUtagVARIANT@@@Z (6 bytes)
00004C2F  FF 25 43 27 00 00  jmp     cs:CWnd::accSelect(long,tagVARIANT)

; FUNC 00004C35-00004C3B ?accLocation@CWnd@@UEAAJPEAJ000UtagVARIANT@@@Z (6 bytes)
00004C35  FF 25 35 27 00 00  jmp     cs:CWnd::accLocation(long *,long *,long *,long *,tagVARIANT)

; FUNC 00004C3B-00004C41 ?accNavigate@CWnd@@UEAAJJUtagVARIANT@@PEAU2@@Z (6 bytes)
00004C3B  FF 25 27 27 00 00  jmp     cs:CWnd::accNavigate(long,tagVARIANT,tagVARIANT *)

; FUNC 00004C41-00004C47 ?accHitTest@CWnd@@UEAAJJJPEAUtagVARIANT@@@Z (6 bytes)
00004C41  FF 25 19 27 00 00  jmp     cs:CWnd::accHitTest(long,long,tagVARIANT *)

; FUNC 00004C47-00004C4D ?accDoDefaultAction@CWnd@@UEAAJUtagVARIANT@@@Z (6 bytes)
00004C47  FF 25 0B 27 00 00  jmp     cs:CWnd::accDoDefaultAction(tagVARIANT)

; FUNC 00004C4D-00004C53 ?put_accName@CWnd@@UEAAJUtagVARIANT@@PEA_W@Z (6 bytes)
00004C4D  FF 25 FD 26 00 00  jmp     cs:CWnd::put_accName(tagVARIANT,wchar_t *)

; FUNC 00004C53-00004C59 ?put_accValue@CWnd@@UEAAJUtagVARIANT@@PEA_W@Z (6 bytes)
00004C53  FF 25 EF 26 00 00  jmp     cs:CWnd::put_accValue(tagVARIANT,wchar_t *)

; FUNC 00004C59-00004C5F ?SetProxy@CWnd@@UEAAJPEAUIAccessibleProxy@@@Z (6 bytes)
00004C59  FF 25 E1 26 00 00  jmp     cs:CWnd::SetProxy(IAccessibleProxy *)

; FUNC 00004C5F-00004C65 ?CreateAccessibleProxy@CWnd@@UEAAJ_K_JPEA_J@Z (6 bytes)
00004C5F  FF 25 D3 26 00 00  jmp     cs:CWnd::CreateAccessibleProxy(unsigned __int64,__int64,__int64 *)

; FUNC 00004C65-00004C6B ?OnCommand@CWnd@@MEAAH_K_J@Z (6 bytes)
00004C65  FF 25 C5 26 00 00  jmp     cs:CWnd::OnCommand(unsigned __int64,__int64)

; FUNC 00004C6B-00004C71 ?OnNotify@CWnd@@MEAAH_K_JPEA_J@Z (6 bytes)
00004C6B  FF 25 B7 26 00 00  jmp     cs:CWnd::OnNotify(unsigned __int64,__int64,__int64 *)

; FUNC 00004C71-00004C77 ?GetSuperWndProcAddr@CWnd@@MEAAPEAP6A_JPEAUHWND__@@I_K_J@ZXZ (6 bytes)
00004C71  FF 25 A9 26 00 00  jmp     cs:CWnd::GetSuperWndProcAddr(void)

; FUNC 00004C77-00004C7D ?PreTranslateMessage@CWnd@@UEAAHPEAUtagMSG@@@Z (6 bytes)
00004C77  FF 25 9B 26 00 00  jmp     cs:CWnd::PreTranslateMessage(tagMSG *)

; FUNC 00004C7D-00004C83 ?OnAmbientProperty@CWnd@@UEAAHPEAVCOleControlSite@@JPEAUtagVARIANT@@@Z (6 bytes)
00004C7D  FF 25 8D 26 00 00  jmp     cs:CWnd::OnAmbientProperty(COleControlSite *,long,tagVARIANT *)

; FUNC 00004C83-00004C89 ?WindowProc@CWnd@@MEAA_JI_K_J@Z (6 bytes)
00004C83  FF 25 7F 26 00 00  jmp     cs:CWnd::WindowProc(uint,unsigned __int64,__int64)

; FUNC 00004C89-00004C8F ?OnWndMsg@CWnd@@MEAAHI_K_JPEA_J@Z (6 bytes)
00004C89  FF 25 71 26 00 00  jmp     cs:CWnd::OnWndMsg(uint,unsigned __int64,__int64,__int64 *)

; FUNC 00004C8F-00004C95 ?DefWindowProcA@CWnd@@MEAA_JI_K_J@Z (6 bytes)
00004C8F  FF 25 63 26 00 00  jmp     cs:CWnd::DefWindowProcA(uint,unsigned __int64,__int64)

; FUNC 00004C95-00004C9B ?PostNcDestroy@CWnd@@MEAAXXZ (6 bytes)
00004C95  FF 25 55 26 00 00  jmp     cs:CWnd::PostNcDestroy(void)

; FUNC 00004C9B-00004CA1 ?OnChildNotify@CWnd@@MEAAHI_K_JPEA_J@Z (6 bytes)
00004C9B  FF 25 47 26 00 00  jmp     cs:CWnd::OnChildNotify(uint,unsigned __int64,__int64,__int64 *)

; FUNC 00004CA1-00004CA7 ?OnTouchInputs@CWnd@@MEAAHIPEAUtagTOUCHINPUT@@@Z (6 bytes)
00004CA1  FF 25 39 26 00 00  jmp     cs:CWnd::OnTouchInputs(uint,tagTOUCHINPUT *)

; FUNC 00004CA7-00004CAD ?OnTouchInput@CWnd@@MEAAHVCPoint@@HHPEAUtagTOUCHINPUT@@@Z (6 bytes)
00004CA7  FF 25 2B 26 00 00  jmp     cs:CWnd::OnTouchInput(CPoint,int,int,tagTOUCHINPUT *)

; FUNC 00004CAD-00004CB3 ?GetGestureStatus@CWnd@@MEAAKVCPoint@@@Z (6 bytes)
00004CAD  FF 25 1D 26 00 00  jmp     cs:CWnd::GetGestureStatus(CPoint)

; FUNC 00004CB3-00004CB9 ?OnGestureZoom@CWnd@@MEAAHVCPoint@@J@Z (6 bytes)
00004CB3  FF 25 0F 26 00 00  jmp     cs:CWnd::OnGestureZoom(CPoint,long)

; FUNC 00004CB9-00004CBF ?OnGesturePan@CWnd@@MEAAHVCPoint@@0@Z (6 bytes)
00004CB9  FF 25 01 26 00 00  jmp     cs:CWnd::OnGesturePan(CPoint,CPoint)

; FUNC 00004CBF-00004CC5 ?OnGestureRotate@CWnd@@MEAAHVCPoint@@N@Z (6 bytes)
00004CBF  FF 25 F3 25 00 00  jmp     cs:CWnd::OnGestureRotate(CPoint,double)

; FUNC 00004CC5-00004CCB ?OnGestureTwoFingerTap@CWnd@@MEAAHVCPoint@@@Z (6 bytes)
00004CC5  FF 25 E5 25 00 00  jmp     cs:CWnd::OnGestureTwoFingerTap(CPoint)

; FUNC 00004CCB-00004CD1 ?OnGesturePressAndTap@CWnd@@MEAAHVCPoint@@J@Z (6 bytes)
00004CCB  FF 25 D7 25 00 00  jmp     cs:CWnd::OnGesturePressAndTap(CPoint,long)

; FUNC 00004CD1-00004CD7 ?ResizeDynamicLayout@CWnd@@MEAAXXZ (6 bytes)
00004CD1  FF 25 C9 25 00 00  jmp     cs:CWnd::ResizeDynamicLayout(void)

; FUNC 00004CD7-00004CDD ?CheckAutoCenter@CWnd@@UEAAHXZ (6 bytes)
00004CD7  FF 25 BB 25 00 00  jmp     cs:CWnd::CheckAutoCenter(void)

; FUNC 00004CDD-00004CE3 ?IsFrameWnd@CWnd@@UEBAHXZ (6 bytes)
00004CDD  FF 25 AD 25 00 00  jmp     cs:CWnd::IsFrameWnd(void)

; FUNC 00004CE3-00004CE9 ?OnFinalRelease@CWnd@@UEAAXXZ (6 bytes)
00004CE3  FF 25 57 25 00 00  jmp     cs:CWnd::OnFinalRelease(void)

; FUNC 00004CE9-00004CEF ?CreateControlContainer@CWnd@@MEAAHPEAPEAVCOleControlContainer@@@Z (6 bytes)
00004CE9  FF 25 89 28 00 00  jmp     cs:CWnd::CreateControlContainer(COleControlContainer * *)

; FUNC 00004CEF-00004CF5 ?CreateControlSite@CWnd@@MEAAHPEAVCOleControlContainer@@PEAPEAVCOleControlSite@@IAEBU_GUID@@@Z (6 bytes)
00004CEF  FF 25 73 28 00 00  jmp     cs:CWnd::CreateControlSite(COleControlContainer *,COleControlSite * *,uint,_GUID const &)

; FUNC 00004CF5-00004CFB ?SetOccDialogInfo@CWnd@@MEAAHPEAU_AFX_OCC_DIALOG_INFO@@@Z (6 bytes)
00004CF5  FF 25 5D 28 00 00  jmp     cs:CWnd::SetOccDialogInfo(_AFX_OCC_DIALOG_INFO *)

; FUNC 00004CFB-00004D01 ?GetOccDialogInfo@CWnd@@MEAAPEAU_AFX_OCC_DIALOG_INFO@@XZ (6 bytes)
00004CFB  FF 25 4F 28 00 00  jmp     cs:CWnd::GetOccDialogInfo(void)

; FUNC 00004D01-00004D07 ?GetRuntimeClass@CDialog@@UEBAPEAUCRuntimeClass@@XZ (6 bytes)
00004D01  FF 25 69 27 00 00  jmp     cs:CDialog::GetRuntimeClass(void)

; FUNC 00004D07-00004D0D ?Create@CDialog@@UEAAHPEBDPEAVCWnd@@@Z (6 bytes)
00004D07  FF 25 7B 26 00 00  jmp     cs:CDialog::Create(char const *,CWnd *)

; FUNC 00004D0D-00004D13 ?CreateIndirect@CDialog@@UEAAHPEBUDLGTEMPLATE@@PEAVCWnd@@PEAX@Z (6 bytes)
00004D0D  FF 25 65 27 00 00  jmp     cs:CDialog::CreateIndirect(DLGTEMPLATE const *,CWnd *,void *)

; FUNC 00004D13-00004D19 ?CreateIndirect@CDialog@@UEAAHPEAXPEAVCWnd@@@Z (6 bytes)
00004D13  FF 25 E7 24 00 00  jmp     cs:CDialog::CreateIndirect(void *,CWnd *)

; FUNC 00004D19-00004D1F ?OnInitDialog@CDialog@@UEAAHXZ (6 bytes)
00004D19  FF 25 E9 24 00 00  jmp     cs:CDialog::OnInitDialog(void)

; FUNC 00004D1F-00004D25 ?OnSetFont@CDialog@@UEAAXPEAVCFont@@@Z (6 bytes)
00004D1F  FF 25 EB 24 00 00  jmp     cs:CDialog::OnSetFont(CFont *)

; FUNC 00004D25-00004D2B ?OnOK@CDialog@@MEAAXXZ (6 bytes)
00004D25  FF 25 ED 24 00 00  jmp     cs:CDialog::OnOK(void)

; FUNC 00004D2B-00004D31 ?OnCancel@CDialog@@MEAAXXZ (6 bytes)
00004D2B  FF 25 EF 24 00 00  jmp     cs:CDialog::OnCancel(void)

; FUNC 00004D31-00004D37 ??1CDialog@@UEAA@XZ (6 bytes)
00004D31  FF 25 F1 24 00 00  jmp     cs:CDialog::~CDialog(void)

; FUNC 00004D37-00004D3D ?PreTranslateMessage@CDialog@@UEAAHPEAUtagMSG@@@Z (6 bytes)
00004D37  FF 25 F3 24 00 00  jmp     cs:CDialog::PreTranslateMessage(tagMSG *)

; FUNC 00004D3D-00004D43 ?OnCmdMsg@CDialog@@UEAAHIHPEAXPEAUAFX_CMDHANDLERINFO@@@Z (6 bytes)
00004D3D  FF 25 F5 24 00 00  jmp     cs:CDialog::OnCmdMsg(uint,int,void *,AFX_CMDHANDLERINFO *)

; FUNC 00004D43-00004D49 ?CheckAutoCenter@CDialog@@UEAAHXZ (6 bytes)
00004D43  FF 25 A7 28 00 00  jmp     cs:CDialog::CheckAutoCenter(void)

; FUNC 00004D49-00004D4F ?SetOccDialogInfo@CDialog@@MEAAHPEAU_AFX_OCC_DIALOG_INFO@@@Z (6 bytes)
00004D49  FF 25 F9 24 00 00  jmp     cs:CDialog::SetOccDialogInfo(_AFX_OCC_DIALOG_INFO *)

; FUNC 00004D4F-00004D55 ?GetOccDialogInfo@CDialog@@MEAAPEAU_AFX_OCC_DIALOG_INFO@@XZ (6 bytes)
00004D4F  FF 25 FB 24 00 00  jmp     cs:CDialog::GetOccDialogInfo(void)

; FUNC 00004D55-00004D5B ?PreInitDialog@CDialog@@MEAAXXZ (6 bytes)
00004D55  FF 25 FD 24 00 00  jmp     cs:CDialog::PreInitDialog(void)

; FUNC 00004D5B-00004D61 ?GetThisMessageMap@CDialog@@KAPEBUAFX_MSGMAP@@XZ (6 bytes)
00004D5B  FF 25 FF 24 00 00  jmp     cs:CDialog::GetThisMessageMap(void)

; FUNC 00004D61-00004D67 ?GetRuntimeClass@CTreeCtrl@@UEBAPEAUCRuntimeClass@@XZ (6 bytes)
00004D61  FF 25 01 25 00 00  jmp     cs:CTreeCtrl::GetRuntimeClass(void)

; FUNC 00004D67-00004D6D ?SetItem@CTreeCtrl@@QEAAHPEAU_TREEITEM@@IPEBDHHII_J@Z (6 bytes)
00004D67  FF 25 03 25 00 00  jmp     cs:CTreeCtrl::SetItem(_TREEITEM *,uint,char const *,int,int,uint,uint,__int64)

; FUNC 00004D6D-00004D73 ?InsertItem@CTreeCtrl@@QEAAPEAU_TREEITEM@@IPEBDHHII_JPEAU2@2@Z (6 bytes)
00004D6D  FF 25 05 25 00 00  jmp     cs:CTreeCtrl::InsertItem(uint,char const *,int,int,uint,uint,__int64,_TREEITEM *,_TREEITEM *)

; FUNC 00004D73-00004D79 ??1CTreeCtrl@@UEAA@XZ (6 bytes)
00004D73  FF 25 07 25 00 00  jmp     cs:CTreeCtrl::~CTreeCtrl(void)

; FUNC 00004D79-00004D7F ?GetMessageMap@CTreeCtrl@@MEBAPEBUAFX_MSGMAP@@XZ (6 bytes)
00004D79  FF 25 09 25 00 00  jmp     cs:CTreeCtrl::GetMessageMap(void)

; FUNC 00004D80-00004DAB ??_Gtype_info@@UEAAPEAXI@Z (43 bytes)
00004D80  40 53  push    rbx
00004D82  48 83 EC 20  sub     rsp, 20h
00004D86  48 8D 05 33 35 00 00  lea     rax, const type_info::`vftable'
00004D8D  48 8B D9  mov     rbx, rcx
00004D90  48 89 01  mov     [rcx], rax
00004D93  F6 C2 01  test    dl, 1
00004D96  74 0A  jz      short loc_180004DA2
00004D98  BA 18 00 00 00  mov     edx, 18h
00004D9D  E8 0A 00 00 00  call    operator delete(void *)
00004DA2  48 8B C3  mov     rax, rbx
00004DA5  48 83 C4 20  add     rsp, 20h
00004DA9  5B  pop     rbx
00004DAA  C3  retn

; FUNC 00004DAC-00004DB1 j_??3@YAXPEAX@Z (5 bytes)
00004DAC  E9 FE FC FF FF  jmp     operator delete(void *)

; FUNC 00004DB4-00004DED __scrt_acquire_startup_lock (57 bytes)
00004DB4  48 83 EC 28  sub     rsp, 28h
00004DB8  E8 17 0A 00 00  call    __scrt_is_ucrt_dll_in_use
00004DBD  85 C0  test    eax, eax
00004DBF  74 21  jz      short loc_180004DE2
00004DC1  65 48 8B 04 25 30 00 00 00  mov     rax, gs:30h
00004DCA  48 8B 48 08  mov     rcx, [rax+8]
00004DCE  EB 05  jmp     short loc_180004DD5
00004DD0  48 3B C8  cmp     rcx, rax
00004DD3  74 14  jz      short loc_180004DE9
00004DD5  33 C0  xor     eax, eax
00004DD7  F0 48 0F B1 0D 78 69 00 00  lock cmpxchg cs:__scrt_native_startup_lock, rcx
00004DE0  75 EE  jnz     short loc_180004DD0
00004DE2  32 C0  xor     al, al
00004DE4  48 83 C4 28  add     rsp, 28h
00004DE8  C3  retn
00004DE9  B0 01  mov     al, 1
00004DEB  EB F7  jmp     short loc_180004DE4

; FUNC 00004DF0-00004E24 __scrt_dllmain_after_initialize_c (52 bytes)
00004DF0  48 83 EC 28  sub     rsp, 28h
00004DF4  E8 DB 09 00 00  call    __scrt_is_ucrt_dll_in_use
00004DF9  85 C0  test    eax, eax
00004DFB  74 07  jz      short loc_180004E04
00004DFD  E8 1E 08 00 00  call    __isa_available_init
00004E02  EB 19  jmp     short loc_180004E1D
00004E04  E8 C3 09 00 00  call    _get_startup_argv_mode
00004E09  8B C8  mov     ecx, eax; mode
00004E0B  E8 D8 11 00 00  call    _configure_narrow_argv
00004E10  85 C0  test    eax, eax
00004E12  74 04  jz      short loc_180004E18
00004E14  32 C0  xor     al, al
00004E16  EB 07  jmp     short loc_180004E1F
00004E18  E8 D1 11 00 00  call    _initialize_narrow_environment
00004E1D  B0 01  mov     al, 1
00004E1F  48 83 C4 28  add     rsp, 28h
00004E23  C3  retn

; FUNC 00004E24-00004E39 __scrt_dllmain_before_initialize_c (21 bytes)
00004E24  48 83 EC 28  sub     rsp, 28h
00004E28  33 C9  xor     ecx, ecx
00004E2A  E8 3D 01 00 00  call    __scrt_initialize_onexit_tables
00004E2F  84 C0  test    al, al
00004E31  0F 95 C0  setnz   al
00004E34  48 83 C4 28  add     rsp, 28h
00004E38  C3  retn

; FUNC 00004E3C-00004E64 __scrt_dllmain_crt_thread_attach (40 bytes)
00004E3C  48 83 EC 28  sub     rsp, 28h
00004E40  E8 DF 11 00 00  call    __vcrt_thread_detach
00004E45  84 C0  test    al, al
00004E47  75 04  jnz     short loc_180004E4D
00004E49  32 C0  xor     al, al
00004E4B  EB 12  jmp     short loc_180004E5F
00004E4D  E8 D2 11 00 00  call    __vcrt_thread_detach
00004E52  84 C0  test    al, al
00004E54  75 07  jnz     short loc_180004E5D
00004E56  E8 C9 11 00 00  call    __vcrt_thread_detach
00004E5B  EB EC  jmp     short loc_180004E49
00004E5D  B0 01  mov     al, 1
00004E5F  48 83 C4 28  add     rsp, 28h
00004E63  C3  retn

; FUNC 00004E64-00004E79 __scrt_dllmain_crt_thread_detach (21 bytes)
00004E64  48 83 EC 28  sub     rsp, 28h
00004E68  E8 B7 11 00 00  call    __vcrt_thread_detach
00004E6D  E8 B2 11 00 00  call    __vcrt_thread_detach
00004E72  B0 01  mov     al, 1
00004E74  48 83 C4 28  add     rsp, 28h
00004E78  C3  retn

; FUNC 00004E7C-00004EDC __scrt_dllmain_exception_filter (96 bytes)
00004E7C  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00004E81  48 89 6C 24 10  mov     [rsp+arg_8], rbp
00004E86  48 89 74 24 18  mov     [rsp+arg_10], rsi
00004E8B  57  push    rdi
00004E8C  48 83 EC 20  sub     rsp, 20h
00004E90  49 8B F9  mov     rdi, r9
00004E93  49 8B F0  mov     rsi, r8
00004E96  8B DA  mov     ebx, edx
00004E98  48 8B E9  mov     rbp, rcx
00004E9B  E8 34 09 00 00  call    __scrt_is_ucrt_dll_in_use
00004EA0  85 C0  test    eax, eax
00004EA2  75 16  jnz     short loc_180004EBA
00004EA4  83 FB 01  cmp     ebx, 1
00004EA7  75 11  jnz     short loc_180004EBA
00004EA9  4C 8B C6  mov     r8, rsi
00004EAC  33 D2  xor     edx, edx
00004EAE  48 8B CD  mov     rcx, rbp
00004EB1  48 8B C7  mov     rax, rdi
00004EB4  FF 15 B6 27 00 00  call    cs:__guard_dispatch_icall_fptr
00004EBA  48 8B 54 24 58  mov     rdx, [rsp+28h+ExceptionPtr]; ExceptionPtr
00004EBF  8B 4C 24 50  mov     ecx, [rsp+28h+ExceptionNum]; ExceptionNum
00004EC3  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00004EC8  48 8B 6C 24 38  mov     rbp, [rsp+28h+arg_8]
00004ECD  48 8B 74 24 40  mov     rsi, [rsp+28h+arg_10]
00004ED2  48 83 C4 20  add     rsp, 20h
00004ED6  5F  pop     rdi
00004ED7  E9 06 11 00 00  jmp     _seh_filter_dll

; FUNC 00004EDC-00004F0C __scrt_dllmain_uninitialize_c (48 bytes)
00004EDC  48 83 EC 28  sub     rsp, 28h
00004EE0  E8 EF 08 00 00  call    __scrt_is_ucrt_dll_in_use
00004EE5  85 C0  test    eax, eax
00004EE7  74 10  jz      short loc_180004EF9
00004EE9  48 8D 0D 78 68 00 00  lea     rcx, _onexit_table_t module_local_atexit_table; Table
00004EF0  48 83 C4 28  add     rsp, 28h
00004EF4  E9 07 11 00 00  jmp     _execute_onexit_table
00004EF9  E8 2A 11 00 00  call    _is_c_termination_complete
00004EFE  85 C0  test    eax, eax
00004F00  75 05  jnz     short loc_180004F07
00004F02  E8 05 11 00 00  call    _cexit
00004F07  48 83 C4 28  add     rsp, 28h
00004F0B  C3  retn

; FUNC 00004F0C-00004F20 __scrt_dllmain_uninitialize_critical (20 bytes)
00004F0C  48 83 EC 28  sub     rsp, 28h
00004F10  33 C9  xor     ecx, ecx
00004F12  E8 0D 11 00 00  call    __vcrt_thread_detach
00004F17  48 83 C4 28  add     rsp, 28h
00004F1B  E9 04 11 00 00  jmp     __vcrt_thread_detach

; FUNC 00004F20-00004F69 __scrt_initialize_crt (73 bytes)
00004F20  40 53  push    rbx
00004F22  48 83 EC 20  sub     rsp, 20h
00004F26  0F B6 05 33 68 00 00  movzx   eax, cs:bool is_initialized_as_dll
00004F2D  85 C9  test    ecx, ecx
00004F2F  BB 01 00 00 00  mov     ebx, 1
00004F34  0F 44 C3  cmovz   eax, ebx
00004F37  88 05 23 68 00 00  mov     cs:bool is_initialized_as_dll, al
00004F3D  E8 DE 06 00 00  call    __isa_available_init
00004F42  E8 DD 10 00 00  call    __vcrt_thread_detach
00004F47  84 C0  test    al, al
00004F49  75 04  jnz     short loc_180004F4F
00004F4B  32 C0  xor     al, al
00004F4D  EB 14  jmp     short loc_180004F63
00004F4F  E8 D0 10 00 00  call    __vcrt_thread_detach
00004F54  84 C0  test    al, al
00004F56  75 09  jnz     short loc_180004F61
00004F58  33 C9  xor     ecx, ecx
00004F5A  E8 C5 10 00 00  call    __vcrt_thread_detach
00004F5F  EB EA  jmp     short loc_180004F4B
00004F61  8A C3  mov     al, bl
00004F63  48 83 C4 20  add     rsp, 20h
00004F67  5B  pop     rbx
00004F68  C3  retn

; FUNC 00004F6C-00004FF7 __scrt_initialize_onexit_tables (139 bytes)
00004F6C  40 53  push    rbx
00004F6E  48 83 EC 20  sub     rsp, 20h
00004F72  80 3D E8 67 00 00 00  cmp     cs:bool module_local_atexit_table_initialized, 0
00004F79  8B D9  mov     ebx, ecx
00004F7B  75 67  jnz     short loc_180004FE4
00004F7D  83 F9 01  cmp     ecx, 1
00004F80  77 6A  ja      short loc_180004FEC
00004F82  E8 4D 08 00 00  call    __scrt_is_ucrt_dll_in_use
00004F87  85 C0  test    eax, eax
00004F89  74 28  jz      short loc_180004FB3
00004F8B  85 DB  test    ebx, ebx
00004F8D  75 24  jnz     short loc_180004FB3
00004F8F  48 8D 0D D2 67 00 00  lea     rcx, _onexit_table_t module_local_atexit_table; Table
00004F96  E8 59 10 00 00  call    _initialize_onexit_table
00004F9B  85 C0  test    eax, eax
00004F9D  75 10  jnz     short loc_180004FAF
00004F9F  48 8D 0D DA 67 00 00  lea     rcx, _onexit_table_t module_local_at_quick_exit_table; Table
00004FA6  E8 49 10 00 00  call    _initialize_onexit_table
00004FAB  85 C0  test    eax, eax
00004FAD  74 2E  jz      short loc_180004FDD
00004FAF  32 C0  xor     al, al
00004FB1  EB 33  jmp     short loc_180004FE6
00004FB3  66 0F 6F 05 15 33 00 00  movdqa  xmm0, cs:__xmm@ffffffffffffffffffffffffffffffff
00004FBB  48 83 C8 FF  or      rax, 0FFFFFFFFFFFFFFFFh
00004FBF  F3 0F 7F 05 A1 67 00 00  movdqu  xmmword ptr cs:_onexit_table_t module_local_atexit_table._first, xmm0
00004FC7  48 89 05 AA 67 00 00  mov     cs:_onexit_table_t module_local_atexit_table._end, rax
00004FCE  F3 0F 7F 05 AA 67 00 00  movdqu  xmmword ptr cs:_onexit_table_t module_local_at_quick_exit_table._first, xmm0
00004FD6  48 89 05 B3 67 00 00  mov     cs:_onexit_table_t module_local_at_quick_exit_table._end, rax
00004FDD  C6 05 7D 67 00 00 01  mov     cs:bool module_local_atexit_table_initialized, 1
00004FE4  B0 01  mov     al, 1
00004FE6  48 83 C4 20  add     rsp, 20h
00004FEA  5B  pop     rbx
00004FEB  C3  retn
00004FEC  B9 05 00 00 00  mov     ecx, 5
00004FF1  E8 F2 07 00 00  call    __scrt_fastfail
00004FF6  CC  db 0CCh

; FUNC 00004FF8-00005090 __scrt_is_nonwritable_in_current_image (152 bytes)
00004FF8  48 83 EC 18  sub     rsp, 18h
00004FFC  4C 8B C1  mov     r8, rcx
00004FFF  B8 4D 5A 00 00  mov     eax, 5A4Dh
00005004  66 39 05 F5 AF FF FF  cmp     cs:180000000h, ax
0000500B  75 78  jnz     short loc_180005085
0000500D  48 63 0D 28 B0 FF FF  movsxd  rcx, dword ptr cs:18000003Ch
00005014  48 8D 15 E5 AF FF FF  lea     rdx, cs:180000000h
0000501B  48 03 CA  add     rcx, rdx
0000501E  81 39 50 45 00 00  cmp     dword ptr [rcx], 4550h
00005024  75 5F  jnz     short loc_180005085
00005026  B8 0B 02 00 00  mov     eax, 20Bh
0000502B  66 39 41 18  cmp     [rcx+18h], ax
0000502F  75 54  jnz     short loc_180005085
00005031  4C 2B C2  sub     r8, rdx
00005034  0F B7 51 14  movzx   edx, word ptr [rcx+14h]
00005038  48 83 C2 18  add     rdx, 18h
0000503C  48 03 D1  add     rdx, rcx
0000503F  0F B7 41 06  movzx   eax, word ptr [rcx+6]
00005043  48 8D 0C 80  lea     rcx, [rax+rax*4]
00005047  4C 8D 0C CA  lea     r9, [rdx+rcx*8]
0000504B  48 89 14 24  mov     [rsp+18h+var_18], rdx
0000504F  49 3B D1  cmp     rdx, r9
00005052  74 18  jz      short loc_18000506C
00005054  8B 4A 0C  mov     ecx, [rdx+0Ch]
00005057  4C 3B C1  cmp     r8, rcx
0000505A  72 0A  jb      short loc_180005066
0000505C  8B 42 08  mov     eax, [rdx+8]
0000505F  03 C1  add     eax, ecx
00005061  4C 3B C0  cmp     r8, rax
00005064  72 08  jb      short loc_18000506E
00005066  48 83 C2 28  add     rdx, 28h ; '('
0000506A  EB DF  jmp     short loc_18000504B
0000506C  33 D2  xor     edx, edx
0000506E  48 85 D2  test    rdx, rdx
00005071  75 04  jnz     short loc_180005077
00005073  32 C0  xor     al, al
00005075  EB 14  jmp     short loc_18000508B
00005077  83 7A 24 00  cmp     dword ptr [rdx+24h], 0
0000507B  7D 04  jge     short loc_180005081
0000507D  32 C0  xor     al, al
0000507F  EB 0A  jmp     short loc_18000508B
00005081  B0 01  mov     al, 1
00005083  EB 06  jmp     short loc_18000508B
00005085  32 C0  xor     al, al
00005087  EB 02  jmp     short loc_18000508B
00005089  32 C0  xor     al, al
0000508B  48 83 C4 18  add     rsp, 18h
0000508F  C3  retn

; FUNC 00005090-000050B4 __scrt_release_startup_lock (36 bytes)
00005090  40 53  push    rbx
00005092  48 83 EC 20  sub     rsp, 20h
00005096  8A D9  mov     bl, cl
00005098  E8 37 07 00 00  call    __scrt_is_ucrt_dll_in_use
0000509D  33 D2  xor     edx, edx
0000509F  85 C0  test    eax, eax
000050A1  74 0B  jz      short loc_1800050AE
000050A3  84 DB  test    bl, bl
000050A5  75 07  jnz     short loc_1800050AE
000050A7  48 87 15 AA 66 00 00  xchg    rdx, cs:__scrt_native_startup_lock
000050AE  48 83 C4 20  add     rsp, 20h
000050B2  5B  pop     rbx
000050B3  C3  retn

; FUNC 000050B4-000050DD __scrt_uninitialize_crt (41 bytes)
000050B4  40 53  push    rbx
000050B6  48 83 EC 20  sub     rsp, 20h
000050BA  80 3D 9F 66 00 00 00  cmp     cs:bool is_initialized_as_dll, 0
000050C1  8A D9  mov     bl, cl
000050C3  74 04  jz      short loc_1800050C9
000050C5  84 D2  test    dl, dl
000050C7  75 0C  jnz     short loc_1800050D5
000050C9  E8 56 0F 00 00  call    __vcrt_thread_detach
000050CE  8A CB  mov     cl, bl
000050D0  E8 4F 0F 00 00  call    __vcrt_thread_detach
000050D5  B0 01  mov     al, 1
000050D7  48 83 C4 20  add     rsp, 20h
000050DB  5B  pop     rbx
000050DC  C3  retn

; FUNC 000050E0-0000511A _onexit (58 bytes)
000050E0  40 53  push    rbx
000050E2  48 83 EC 20  sub     rsp, 20h
000050E6  48 83 3D 7A 66 00 00 FF  cmp     cs:_onexit_table_t module_local_atexit_table._first, 0FFFFFFFFFFFFFFFFh
000050EE  48 8B D9  mov     rbx, rcx
000050F1  75 07  jnz     short loc_1800050FA
000050F3  E8 0E 0F 00 00  call    _crt_atexit
000050F8  EB 0F  jmp     short loc_180005109
000050FA  48 8B D3  mov     rdx, rbx; Function
000050FD  48 8D 0D 64 66 00 00  lea     rcx, _onexit_table_t module_local_atexit_table; Table
00005104  E8 F1 0E 00 00  call    _register_onexit_function
00005109  33 D2  xor     edx, edx
0000510B  85 C0  test    eax, eax
0000510D  48 0F 44 D3  cmovz   rdx, rbx
00005111  48 8B C2  mov     rax, rdx
00005114  48 83 C4 20  add     rsp, 20h
00005118  5B  pop     rbx
00005119  C3  retn

; FUNC 0000511C-00005133 atexit (23 bytes)
0000511C  48 83 EC 28  sub     rsp, 28h
00005120  E8 BB FF FF FF  call    _onexit
00005125  48 F7 D8  neg     rax
00005128  1B C0  sbb     eax, eax
0000512A  F7 D8  neg     eax
0000512C  FF C8  dec     eax
0000512E  48 83 C4 28  add     rsp, 28h
00005132  C3  retn

; FUNC 00005134-00005151 __GSHandlerCheck (29 bytes)
00005134  48 83 EC 28  sub     rsp, 28h
00005138  4D 8B 41 38  mov     r8, [r9+38h]
0000513C  48 8B CA  mov     rcx, rdx
0000513F  49 8B D1  mov     rdx, r9
00005142  E8 0D 00 00 00  call    __GSHandlerCheckCommon
00005147  B8 01 00 00 00  mov     eax, 1
0000514C  48 83 C4 28  add     rsp, 28h
00005150  C3  retn

; FUNC 00005154-000051AF __GSHandlerCheckCommon (91 bytes)
00005154  40 53  push    rbx
00005156  45 8B 18  mov     r11d, [r8]
00005159  48 8B DA  mov     rbx, rdx
0000515C  41 83 E3 F8  and     r11d, 0FFFFFFF8h
00005160  4C 8B C9  mov     r9, rcx
00005163  41 F6 00 04  test    byte ptr [r8], 4
00005167  4C 8B D1  mov     r10, rcx
0000516A  74 13  jz      short loc_18000517F
0000516C  41 8B 40 08  mov     eax, [r8+8]
00005170  4D 63 50 04  movsxd  r10, dword ptr [r8+4]
00005174  F7 D8  neg     eax
00005176  4C 03 D1  add     r10, rcx
00005179  48 63 C8  movsxd  rcx, eax
0000517C  4C 23 D1  and     r10, rcx
0000517F  49 63 C3  movsxd  rax, r11d
00005182  4A 8B 14 10  mov     rdx, [rax+r10]
00005186  48 8B 43 10  mov     rax, [rbx+10h]
0000518A  8B 48 08  mov     ecx, [rax+8]
0000518D  48 8B 43 08  mov     rax, [rbx+8]
00005191  F6 44 01 03 0F  test    byte ptr [rcx+rax+3], 0Fh
00005196  74 0B  jz      short loc_1800051A3
00005198  0F B6 44 01 03  movzx   eax, byte ptr [rcx+rax+3]
0000519D  83 E0 F0  and     eax, 0FFFFFFF0h
000051A0  4C 03 C8  add     r9, rax
000051A3  4C 33 CA  xor     r9, rdx
000051A6  49 8B C9  mov     rcx, r9; StackCookie
000051A9  5B  pop     rbx
000051AA  E9 F1 00 00 00  jmp     __security_check_cookie

; FUNC 000051B0-0000522F __GSHandlerCheck_EH4 (127 bytes)
000051B0  48 8B C4  mov     rax, rsp
000051B3  48 89 58 08  mov     [rax+8], rbx
000051B7  48 89 68 10  mov     [rax+10h], rbp
000051BB  48 89 70 18  mov     [rax+18h], rsi
000051BF  48 89 78 20  mov     [rax+20h], rdi
000051C3  41 56  push    r14
000051C5  48 83 EC 20  sub     rsp, 20h
000051C9  49 8B 59 38  mov     rbx, [r9+38h]
000051CD  48 8B F2  mov     rsi, rdx
000051D0  4D 8B F0  mov     r14, r8
000051D3  48 8B E9  mov     rbp, rcx
000051D6  49 8B D1  mov     rdx, r9
000051D9  48 8B CE  mov     rcx, rsi
000051DC  49 8B F9  mov     rdi, r9
000051DF  4C 8D 43 04  lea     r8, [rbx+4]
000051E3  E8 6C FF FF FF  call    __GSHandlerCheckCommon
000051E8  8B 45 04  mov     eax, [rbp+4]
000051EB  24 66  and     al, 66h
000051ED  F6 D8  neg     al
000051EF  B8 01 00 00 00  mov     eax, 1
000051F4  45 1B C0  sbb     r8d, r8d
000051F7  41 F7 D8  neg     r8d
000051FA  44 03 C0  add     r8d, eax
000051FD  44 85 43 04  test    [rbx+4], r8d
00005201  74 11  jz      short loc_180005214
00005203  4C 8B CF  mov     r9, rdi
00005206  4D 8B C6  mov     r8, r14
00005209  48 8B D6  mov     rdx, rsi
0000520C  48 8B CD  mov     rcx, rbp
0000520F  E8 AA 0D 00 00  call    __CxxFrameHandler4
00005214  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00005219  48 8B 6C 24 38  mov     rbp, [rsp+28h+arg_8]
0000521E  48 8B 74 24 40  mov     rsi, [rsp+28h+arg_10]
00005223  48 8B 7C 24 48  mov     rdi, [rsp+28h+arg_18]
00005228  48 83 C4 20  add     rsp, 20h
0000522C  41 5E  pop     r14
0000522E  C3  retn

; FUNC 00005240-0000528E __alloca_probe (78 bytes)
00005240  48 83 EC 10  sub     rsp, 10h
00005244  4C 89 14 24  mov     [rsp+10h+var_10], r10
00005248  4C 89 5C 24 08  mov     [rsp+10h+var_8], r11
0000524D  4D 33 DB  xor     r11, r11
00005250  4C 8D 54 24 18  lea     r10, [rsp+10h+arg_0]
00005255  4C 2B D0  sub     r10, rax
00005258  4D 0F 42 D3  cmovb   r10, r11
0000525C  65 4C 8B 1C 25 10 00 00 00  mov     r11, gs:10h
00005265  4D 3B D3  cmp     r10, r11
00005268  73 16  jnb     short cs20
0000526A  66 41 81 E2 00 F0  and     r10w, 0F000h
00005270  4D 8D 9B 00 F0 FF FF  lea     r11, [r11-1000h]
00005277  41 C6 03 00  mov     byte ptr [r11], 0
0000527B  4D 3B D3  cmp     r10, r11
0000527E  75 F0  jnz     short cs10
00005280  4C 8B 14 24  mov     r10, [rsp+10h+var_10]
00005284  4C 8B 5C 24 08  mov     r11, [rsp+10h+var_8]
00005289  48 83 C4 10  add     rsp, 10h
0000528D  C3  retn

; FUNC 000052A0-000052BE __security_check_cookie (30 bytes)
000052A0  48 3B 0D 41 61 00 00  cmp     rcx, cs:__security_cookie
000052A7  75 10  jnz     short ReportFailure
000052A9  48 C1 C1 10  rol     rcx, 10h
000052AD  66 F7 C1 FF FF  test    cx, 0FFFFh
000052B2  75 01  jnz     short RestoreRcx
000052B4  C3  retn
000052B5  48 C1 C9 10  ror     rcx, 10h; StackCookie
000052B9  E9 AA 06 00 00  jmp     __report_gsfailure

; FUNC 000052C0-00005310 ?dllmain_crt_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z (80 bytes)
000052C0  48 83 EC 28  sub     rsp, 28h
000052C4  85 D2  test    edx, edx
000052C6  74 39  jz      short loc_180005301
000052C8  83 EA 01  sub     edx, 1
000052CB  74 28  jz      short loc_1800052F5
000052CD  83 EA 01  sub     edx, 1
000052D0  74 16  jz      short loc_1800052E8
000052D2  83 FA 01  cmp     edx, 1
000052D5  74 0A  jz      short loc_1800052E1
000052D7  B8 01 00 00 00  mov     eax, 1
000052DC  48 83 C4 28  add     rsp, 28h
000052E0  C3  retn
000052E1  E8 7E FB FF FF  call    __scrt_dllmain_crt_thread_detach
000052E6  EB 05  jmp     short loc_1800052ED
000052E8  E8 4F FB FF FF  call    __scrt_dllmain_crt_thread_attach
000052ED  0F B6 C0  movzx   eax, al
000052F0  48 83 C4 28  add     rsp, 28h
000052F4  C3  retn
000052F5  49 8B D0  mov     rdx, r8; void *
000052F8  48 83 C4 28  add     rsp, 28h
000052FC  E9 0F 00 00 00  jmp     dllmain_crt_process_attach(HINSTANCE__ * const,void * const)
00005301  4D 85 C0  test    r8, r8
00005304  0F 95 C1  setnz   cl; bool
00005307  48 83 C4 28  add     rsp, 28h
0000530B  E9 18 01 00 00  jmp     dllmain_crt_process_detach(bool)

; FUNC 00005310-00005426 ?dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z (278 bytes)
00005310  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00005315  48 89 74 24 10  mov     [rsp+arg_8], rsi
0000531A  48 89 7C 24 20  mov     [rsp+arg_18], rdi
0000531F  41 56  push    r14
00005321  48 83 EC 20  sub     rsp, 20h
00005325  48 8B F2  mov     rsi, rdx
00005328  4C 8B F1  mov     r14, rcx
0000532B  33 C9  xor     ecx, ecx
0000532D  E8 EE FB FF FF  call    __scrt_initialize_crt
00005332  84 C0  test    al, al
00005334  0F 84 C8 00 00 00  jz      loc_180005402
0000533A  E8 75 FA FF FF  call    __scrt_acquire_startup_lock
0000533F  8A D8  mov     bl, al
00005341  88 44 24 40  mov     [rsp+28h+arg_10], al
00005345  40 B7 01  mov     dil, 1
00005348  83 3D 01 64 00 00 00  cmp     cs:__scrt_current_native_startup_state, 0
0000534F  0F 85 C5 00 00 00  jnz     loc_18000541A
00005355  C7 05 F1 63 00 00 01 00 00 00  mov     cs:__scrt_current_native_startup_state, 1
0000535F  E8 C0 FA FF FF  call    __scrt_dllmain_before_initialize_c
00005364  84 C0  test    al, al
00005366  74 4F  jz      short loc_1800053B7
00005368  E8 37 08 00 00  call    _RTC_Initialize
0000536D  E8 EA 07 00 00  call    __scrt_initialize_type_info(void)
00005372  E8 09 08 00 00  call    __scrt_initialize_default_local_stdio_options
00005377  48 8D 15 4A 23 00 00  lea     rdx, __xi_z; Last
0000537E  48 8D 0D 3B 23 00 00  lea     rcx, __xi_a; First
00005385  E8 8E 0C 00 00  call    _initterm_e
0000538A  85 C0  test    eax, eax
0000538C  75 29  jnz     short loc_1800053B7
0000538E  E8 5D FA FF FF  call    __scrt_dllmain_after_initialize_c
00005393  84 C0  test    al, al
00005395  74 20  jz      short loc_1800053B7
00005397  48 8D 15 1A 23 00 00  lea     rdx, __xc_z; Last
0000539E  48 8D 0D F3 22 00 00  lea     rcx, __xc_a; First
000053A5  E8 68 0C 00 00  call    _initterm
000053AA  C7 05 9C 63 00 00 02 00 00 00  mov     cs:__scrt_current_native_startup_state, 2
000053B4  40 32 FF  xor     dil, dil
000053B7  8A CB  mov     cl, bl
000053B9  E8 D2 FC FF FF  call    __scrt_release_startup_lock
000053BE  40 84 FF  test    dil, dil
000053C1  75 3F  jnz     short loc_180005402
000053C3  E8 D4 07 00 00  call    __scrt_get_dyn_tls_init_callback
000053C8  48 8B D8  mov     rbx, rax
000053CB  48 83 38 00  cmp     qword ptr [rax], 0
000053CF  74 24  jz      short loc_1800053F5
000053D1  48 8B C8  mov     rcx, rax
000053D4  E8 1F FC FF FF  call    __scrt_is_nonwritable_in_current_image
000053D9  84 C0  test    al, al
000053DB  74 18  jz      short loc_1800053F5
000053DD  4C 8B C6  mov     r8, rsi
000053E0  BA 02 00 00 00  mov     edx, 2
000053E5  49 8B CE  mov     rcx, r14
000053E8  48 8B 03  mov     rax, [rbx]
000053EB  4C 8B 0D 7E 22 00 00  mov     r9, cs:__guard_dispatch_icall_fptr
000053F2  41 FF D1  call    r9 ; _guard_dispatch_icall_nop
000053F5  FF 05 A1 63 00 00  inc     cs:int __proc_attached
000053FB  B8 01 00 00 00  mov     eax, 1
00005400  EB 02  jmp     short loc_180005404
00005402  33 C0  xor     eax, eax
00005404  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00005409  48 8B 74 24 38  mov     rsi, [rsp+28h+arg_8]
0000540E  48 8B 7C 24 48  mov     rdi, [rsp+28h+arg_18]
00005413  48 83 C4 20  add     rsp, 20h
00005417  41 5E  pop     r14
00005419  C3  retn
0000541A  B9 07 00 00 00  mov     ecx, 7
0000541F  E8 C4 03 00 00  call    __scrt_fastfail
00005424  90  nop
00005425  CC  int     3; Trap to Debugger

; FUNC 00005428-000054AC ?dllmain_crt_process_detach@@YAH_N@Z (132 bytes)
00005428  48 89 5C 24 08  mov     [rsp+arg_0], rbx
0000542D  57  push    rdi
0000542E  48 83 EC 30  sub     rsp, 30h
00005432  40 8A F9  mov     dil, cl
00005435  8B 05 61 63 00 00  mov     eax, cs:int __proc_attached
0000543B  85 C0  test    eax, eax
0000543D  7F 0D  jg      short loc_18000544C
0000543F  33 C0  xor     eax, eax
00005441  48 8B 5C 24 40  mov     rbx, [rsp+38h+arg_0]
00005446  48 83 C4 30  add     rsp, 30h
0000544A  5F  pop     rdi
0000544B  C3  retn
0000544C  FF C8  dec     eax
0000544E  89 05 48 63 00 00  mov     cs:int __proc_attached, eax
00005454  E8 5B F9 FF FF  call    __scrt_acquire_startup_lock
00005459  8A D8  mov     bl, al
0000545B  88 44 24 20  mov     [rsp+38h+var_18], al
0000545F  83 3D EA 62 00 00 02  cmp     cs:__scrt_current_native_startup_state, 2
00005466  75 37  jnz     short loc_18000549F
00005468  E8 6F FA FF FF  call    __scrt_dllmain_uninitialize_c
0000546D  E8 FA 06 00 00  call    __scrt_uninitialize_type_info(void)
00005472  E8 69 07 00 00  call    _RTC_Terminate
00005477  83 25 D2 62 00 00 00  and     cs:__scrt_current_native_startup_state, 0
0000547E  8A CB  mov     cl, bl
00005480  E8 0B FC FF FF  call    __scrt_release_startup_lock
00005485  33 D2  xor     edx, edx
00005487  40 8A CF  mov     cl, dil
0000548A  E8 25 FC FF FF  call    __scrt_uninitialize_crt
0000548F  F6 D8  neg     al
00005491  1B DB  sbb     ebx, ebx
00005493  83 E3 01  and     ebx, 1
00005496  E8 71 FA FF FF  call    __scrt_dllmain_uninitialize_critical
0000549B  8B C3  mov     eax, ebx
0000549D  EB A2  jmp     short loc_180005441
0000549F  B9 07 00 00 00  mov     ecx, 7
000054A4  E8 3F 03 00 00  call    __scrt_fastfail
000054A9  90  nop
000054AA  90  nop
000054AB  CC  int     3; Trap to Debugger

; FUNC 000054AC-000055DD ?dllmain_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z (305 bytes)
000054AC  48 8B C4  mov     rax, rsp
000054AF  48 89 58 20  mov     [rax+20h], rbx
000054B3  4C 89 40 18  mov     [rax+18h], r8
000054B7  89 50 10  mov     [rax+10h], edx
000054BA  48 89 48 08  mov     [rax+8], rcx
000054BE  56  push    rsi
000054BF  57  push    rdi
000054C0  41 56  push    r14
000054C2  48 83 EC 40  sub     rsp, 40h
000054C6  49 8B F0  mov     rsi, r8
000054C9  8B FA  mov     edi, edx
000054CB  4C 8B F1  mov     r14, rcx
000054CE  85 D2  test    edx, edx
000054D0  75 0F  jnz     short loc_1800054E1
000054D2  39 15 C4 62 00 00  cmp     cs:int __proc_attached, edx
000054D8  7F 07  jg      short loc_1800054E1
000054DA  33 C0  xor     eax, eax
000054DC  E9 EE 00 00 00  jmp     loc_1800055CF
000054E1  8D 42 FF  lea     eax, [rdx-1]
000054E4  83 F8 01  cmp     eax, 1
000054E7  77 45  ja      short loc_18000552E
000054E9  48 8B 05 40 22 00 00  mov     rax, cs:_pRawDllMain
000054F0  48 85 C0  test    rax, rax
000054F3  75 0A  jnz     short loc_1800054FF
000054F5  C7 44 24 30 01 00 00 00  mov     [rsp+58h+var_28], 1
000054FD  EB 14  jmp     short loc_180005513
000054FF  FF 15 6B 21 00 00  call    cs:__guard_dispatch_icall_fptr
00005505  8B D8  mov     ebx, eax
00005507  89 44 24 30  mov     [rsp+58h+var_28], eax
0000550B  85 C0  test    eax, eax
0000550D  0F 84 B2 00 00 00  jz      loc_1800055C5
00005513  4C 8B C6  mov     r8, rsi; void *
00005516  8B D7  mov     edx, edi; unsigned int
00005518  49 8B CE  mov     rcx, r14; HINSTANCE
0000551B  E8 A0 FD FF FF  call    dllmain_crt_dispatch(HINSTANCE__ * const,ulong,void * const)
00005520  8B D8  mov     ebx, eax
00005522  89 44 24 30  mov     [rsp+58h+var_28], eax
00005526  85 C0  test    eax, eax
00005528  0F 84 97 00 00 00  jz      loc_1800055C5
0000552E  4C 8B C6  mov     r8, rsi; lpvReserved
00005531  8B D7  mov     edx, edi; fdwReason
00005533  49 8B CE  mov     rcx, r14; hinstDLL
00005536  E8 85 DA FF FF  call    DllMain
0000553B  8B D8  mov     ebx, eax
0000553D  89 44 24 30  mov     [rsp+58h+var_28], eax
00005541  83 FF 01  cmp     edi, 1
00005544  75 36  jnz     short loc_18000557C
00005546  85 C0  test    eax, eax
00005548  75 32  jnz     short loc_18000557C
0000554A  4C 8B C6  mov     r8, rsi; lpvReserved
0000554D  33 D2  xor     edx, edx; fdwReason
0000554F  49 8B CE  mov     rcx, r14; hinstDLL
00005552  E8 69 DA FF FF  call    DllMain
00005557  48 85 F6  test    rsi, rsi
0000555A  0F 95 C1  setnz   cl; bool
0000555D  E8 C6 FE FF FF  call    dllmain_crt_process_detach(bool)
00005562  48 8B 05 C7 21 00 00  mov     rax, cs:_pRawDllMain
00005569  48 85 C0  test    rax, rax
0000556C  74 0E  jz      short loc_18000557C
0000556E  4C 8B C6  mov     r8, rsi
00005571  33 D2  xor     edx, edx
00005573  49 8B CE  mov     rcx, r14
00005576  FF 15 F4 20 00 00  call    cs:__guard_dispatch_icall_fptr
0000557C  85 FF  test    edi, edi
0000557E  74 05  jz      short loc_180005585
00005580  83 FF 03  cmp     edi, 3
00005583  75 40  jnz     short loc_1800055C5
00005585  4C 8B C6  mov     r8, rsi; void *
00005588  8B D7  mov     edx, edi; unsigned int
0000558A  49 8B CE  mov     rcx, r14; HINSTANCE
0000558D  E8 2E FD FF FF  call    dllmain_crt_dispatch(HINSTANCE__ * const,ulong,void * const)
00005592  8B D8  mov     ebx, eax
00005594  89 44 24 30  mov     [rsp+58h+var_28], eax
00005598  85 C0  test    eax, eax
0000559A  74 29  jz      short loc_1800055C5
0000559C  48 8B 05 8D 21 00 00  mov     rax, cs:_pRawDllMain
000055A3  48 85 C0  test    rax, rax
000055A6  75 09  jnz     short loc_1800055B1
000055A8  8D 58 01  lea     ebx, [rax+1]
000055AB  89 5C 24 30  mov     [rsp+58h+var_28], ebx
000055AF  EB 14  jmp     short loc_1800055C5
000055B1  4C 8B C6  mov     r8, rsi
000055B4  8B D7  mov     edx, edi
000055B6  49 8B CE  mov     rcx, r14
000055B9  FF 15 B1 20 00 00  call    cs:__guard_dispatch_icall_fptr
000055BF  8B D8  mov     ebx, eax
000055C1  89 44 24 30  mov     [rsp+58h+var_28], eax
000055C5  EB 06  jmp     short loc_1800055CD
000055C7  33 DB  xor     ebx, ebx
000055C9  89 5C 24 30  mov     [rsp+58h+var_28], ebx
000055CD  8B C3  mov     eax, ebx
000055CF  48 8B 5C 24 78  mov     rbx, [rsp+58h+arg_18]
000055D4  48 83 C4 40  add     rsp, 40h
000055D8  41 5E  pop     r14
000055DA  5F  pop     rdi
000055DB  5E  pop     rsi
000055DC  C3  retn

; FUNC 000055E0-0000561D DllEntryPoint (61 bytes)
000055E0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
000055E5  48 89 74 24 10  mov     [rsp+arg_8], rsi
000055EA  57  push    rdi
000055EB  48 83 EC 20  sub     rsp, 20h
000055EF  49 8B F8  mov     rdi, r8
000055F2  8B DA  mov     ebx, edx
000055F4  48 8B F1  mov     rsi, rcx
000055F7  83 FA 01  cmp     edx, 1
000055FA  75 05  jnz     short loc_180005601
000055FC  E8 AF 04 00 00  call    __security_init_cookie
00005601  4C 8B C7  mov     r8, rdi; void *
00005604  8B D3  mov     edx, ebx; unsigned int
00005606  48 8B CE  mov     rcx, rsi; HINSTANCE
00005609  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
0000560E  48 8B 74 24 38  mov     rsi, [rsp+28h+arg_8]
00005613  48 83 C4 20  add     rsp, 20h
00005617  5F  pop     rdi
00005618  E9 8F FE FF FF  jmp     dllmain_dispatch(HINSTANCE__ * const,ulong,void * const)

; FUNC 00005620-000057CC __isa_available_init (428 bytes)
00005620  48 89 5C 24 10  mov     [rsp+arg_8], rbx
00005625  48 89 74 24 18  mov     [rsp+arg_10], rsi
0000562A  57  push    rdi
0000562B  48 83 EC 10  sub     rsp, 10h
0000562F  33 C0  xor     eax, eax
00005631  33 C9  xor     ecx, ecx
00005633  0F A2  cpuid
00005635  44 8B C1  mov     r8d, ecx
00005638  45 33 DB  xor     r11d, r11d
0000563B  44 8B D2  mov     r10d, edx
0000563E  41 81 F0 6E 74 65 6C  xor     r8d, 6C65746Eh
00005645  41 81 F2 69 6E 65 49  xor     r10d, 49656E69h
0000564C  44 8B CB  mov     r9d, ebx
0000564F  8B F0  mov     esi, eax
00005651  33 C9  xor     ecx, ecx
00005653  41 8D 43 01  lea     eax, [r11+1]
00005657  45 0B D0  or      r10d, r8d
0000565A  0F A2  cpuid
0000565C  41 81 F1 47 65 6E 75  xor     r9d, 756E6547h
00005663  89 04 24  mov     [rsp+18h+var_18], eax
00005666  45 0B D1  or      r10d, r9d
00005669  89 5C 24 04  mov     [rsp+18h+var_14], ebx
0000566D  8B F9  mov     edi, ecx
0000566F  89 4C 24 08  mov     [rsp+18h+var_10], ecx
00005673  89 54 24 0C  mov     [rsp+18h+var_C], edx
00005677  75 5B  jnz     short loc_1800056D4
00005679  48 83 0D 7F 5D 00 00 FF  or      cs:__memset_nt_threshold, 0FFFFFFFFFFFFFFFFh
00005681  25 F0 3F FF 0F  and     eax, 0FFF3FF0h
00005686  48 C7 05 67 5D 00 00 00 80 00 00  mov     cs:__memset_fast_string_threshold, 8000h
00005691  3D C0 06 01 00  cmp     eax, 106C0h
00005696  74 28  jz      short loc_1800056C0
00005698  3D 60 06 02 00  cmp     eax, 20660h
0000569D  74 21  jz      short loc_1800056C0
0000569F  3D 70 06 02 00  cmp     eax, 20670h
000056A4  74 1A  jz      short loc_1800056C0
000056A6  05 B0 F9 FC FF  add     eax, 0FFFCF9B0h
000056AB  83 F8 20  cmp     eax, 20h ; ' '
000056AE  77 24  ja      short loc_1800056D4
000056B0  48 B9 01 00 01 00 01 00 00 00  mov     rcx, 100010001h
000056BA  48 0F A3 C1  bt      rcx, rax
000056BE  73 14  jnb     short loc_1800056D4
000056C0  44 8B 05 D9 60 00 00  mov     r8d, cs:__favor
000056C7  41 83 C8 01  or      r8d, 1
000056CB  44 89 05 CE 60 00 00  mov     cs:__favor, r8d
000056D2  EB 07  jmp     short loc_1800056DB
000056D4  44 8B 05 C5 60 00 00  mov     r8d, cs:__favor
000056DB  B8 07 00 00 00  mov     eax, 7
000056E0  44 8D 48 FB  lea     r9d, [rax-5]
000056E4  3B F0  cmp     esi, eax
000056E6  7C 26  jl      short loc_18000570E
000056E8  33 C9  xor     ecx, ecx
000056EA  0F A2  cpuid
000056EC  89 04 24  mov     [rsp+18h+var_18], eax
000056EF  44 8B DB  mov     r11d, ebx
000056F2  89 5C 24 04  mov     [rsp+18h+var_14], ebx
000056F6  89 4C 24 08  mov     [rsp+18h+var_10], ecx
000056FA  89 54 24 0C  mov     [rsp+18h+var_C], edx
000056FE  0F BA E3 09  bt      ebx, 9
00005702  73 0A  jnb     short loc_18000570E
00005704  45 0B C1  or      r8d, r9d
00005707  44 89 05 92 60 00 00  mov     cs:__favor, r8d
0000570E  C7 05 D8 5C 00 00 01 00 00 00  mov     cs:__isa_available, 1
00005718  44 89 0D D5 5C 00 00  mov     cs:__isa_enabled, r9d
0000571F  0F BA E7 14  bt      edi, 14h
00005723  0F 83 91 00 00 00  jnb     loc_1800057BA
00005729  44 89 0D C0 5C 00 00  mov     cs:__isa_available, r9d
00005730  BB 06 00 00 00  mov     ebx, 6
00005735  89 1D B9 5C 00 00  mov     cs:__isa_enabled, ebx
0000573B  0F BA E7 1B  bt      edi, 1Bh
0000573F  73 79  jnb     short loc_1800057BA
00005741  0F BA E7 1C  bt      edi, 1Ch
00005745  73 73  jnb     short loc_1800057BA
00005747  33 C9  xor     ecx, ecx
00005749  0F 01 D0  xgetbv
0000574C  48 C1 E2 20  shl     rdx, 20h
00005750  48 0B D0  or      rdx, rax
00005753  48 89 54 24 20  mov     [rsp+18h+arg_0], rdx
00005758  48 8B 44 24 20  mov     rax, [rsp+18h+arg_0]
0000575D  22 C3  and     al, bl
0000575F  3A C3  cmp     al, bl
00005761  75 57  jnz     short loc_1800057BA
00005763  8B 05 8B 5C 00 00  mov     eax, cs:__isa_enabled
00005769  83 C8 08  or      eax, 8
0000576C  C7 05 7A 5C 00 00 03 00 00 00  mov     cs:__isa_available, 3
00005776  89 05 78 5C 00 00  mov     cs:__isa_enabled, eax
0000577C  41 F6 C3 20  test    r11b, 20h
00005780  74 38  jz      short loc_1800057BA
00005782  83 C8 20  or      eax, 20h
00005785  C7 05 61 5C 00 00 05 00 00 00  mov     cs:__isa_available, 5
0000578F  89 05 5F 5C 00 00  mov     cs:__isa_enabled, eax
00005795  B8 00 00 03 D0  mov     eax, 0D0030000h
0000579A  44 23 D8  and     r11d, eax
0000579D  44 3B D8  cmp     r11d, eax
000057A0  75 18  jnz     short loc_1800057BA
000057A2  48 8B 44 24 20  mov     rax, [rsp+18h+arg_0]
000057A7  24 E0  and     al, 0E0h
000057A9  3C E0  cmp     al, 0E0h
000057AB  75 0D  jnz     short loc_1800057BA
000057AD  83 0D 40 5C 00 00 40  or      cs:__isa_enabled, 40h
000057B4  89 1D 36 5C 00 00  mov     cs:__isa_available, ebx
000057BA  48 8B 5C 24 28  mov     rbx, [rsp+18h+arg_8]
000057BF  33 C0  xor     eax, eax
000057C1  48 8B 74 24 30  mov     rsi, [rsp+18h+arg_10]
000057C6  48 83 C4 10  add     rsp, 10h
000057CA  5F  pop     rdi
000057CB  C3  retn

; FUNC 000057CC-000057D2 _get_startup_argv_mode (6 bytes)
000057CC  B8 01 00 00 00  mov     eax, 1
000057D1  C3  retn

; FUNC 000057D4-000057E0 __scrt_is_ucrt_dll_in_use (12 bytes)
000057D4  33 C0  xor     eax, eax
000057D6  39 05 58 5C 00 00  cmp     cs:dword_18000B434, eax
000057DC  0F 95 C0  setnz   al
000057DF  C3  retn

; FUNC 000057E0-000057E8 __crt_debugger_hook (8 bytes)
000057E0  83 25 BD 5F 00 00 00  and     cs:dword_18000B7A4, 0
000057E7  C3  retn

; FUNC 000057E8-00005933 __scrt_fastfail (331 bytes)
000057E8  48 89 5C 24 08  mov     [rsp-8+arg_0], rbx
000057ED  55  push    rbp
000057EE  48 8D AC 24 40 FB FF FF  lea     rbp, [rsp-4C0h]
000057F6  48 81 EC C0 05 00 00  sub     rsp, 5C0h
000057FD  8B D9  mov     ebx, ecx
000057FF  B9 17 00 00 00  mov     ecx, 17h; ProcessorFeature
00005804  FF 15 66 18 00 00  call    cs:IsProcessorFeaturePresent; KERNEL32
0000580A  85 C0  test    eax, eax
0000580C  74 04  jz      short loc_180005812
0000580E  8B CB  mov     ecx, ebx
00005810  CD 29  int     29h; Win8: RtlFailFast(ecx)
00005812  B9 03 00 00 00  mov     ecx, 3
00005817  E8 C4 FF FF FF  call    __crt_debugger_hook
0000581C  33 D2  xor     edx, edx; Val
0000581E  48 8D 4D F0  lea     rcx, [rbp+4C0h+ContextRecord]; void *
00005822  41 B8 D0 04 00 00  mov     r8d, 4D0h; Size
00005828  E8 9D 07 00 00  call    memset
0000582D  48 8D 4D F0  lea     rcx, [rbp+4C0h+ContextRecord]; ContextRecord
00005831  FF 15 31 18 00 00  call    cs:RtlCaptureContext; KERNEL32
00005837  48 8B 9D E8 00 00 00  mov     rbx, [rbp+4C0h+ContextRecord.Rip]
0000583E  48 8D 95 D8 04 00 00  lea     rdx, [rbp+4C0h+ImageBase]; ImageBase
00005845  48 8B CB  mov     rcx, rbx; ControlPc
00005848  45 33 C0  xor     r8d, r8d; HistoryTable
0000584B  FF 15 5F 18 00 00  call    cs:RtlLookupFunctionEntry; KERNEL32
00005851  48 85 C0  test    rax, rax
00005854  74 3C  jz      short loc_180005892
00005856  48 83 64 24 38 00  and     [rsp+5C0h+var_588], 0
0000585C  48 8D 8D E0 04 00 00  lea     rcx, [rbp+4C0h+arg_10]
00005863  48 8B 95 D8 04 00 00  mov     rdx, [rbp+4C0h+ImageBase]; ImageBase
0000586A  4C 8B C8  mov     r9, rax; FunctionEntry
0000586D  48 89 4C 24 30  mov     [rsp+5C0h+EstablisherFrame], rcx; EstablisherFrame
00005872  4C 8B C3  mov     r8, rbx; ControlPc
00005875  48 8D 8D E8 04 00 00  lea     rcx, [rbp+4C0h+arg_18]
0000587C  48 89 4C 24 28  mov     [rsp+5C0h+HandlerData], rcx; HandlerData
00005881  48 8D 4D F0  lea     rcx, [rbp+4C0h+ContextRecord]
00005885  48 89 4C 24 20  mov     [rsp+5C0h+var_5A0], rcx; ContextRecord
0000588A  33 C9  xor     ecx, ecx; HandlerType
0000588C  FF 15 26 18 00 00  call    cs:RtlVirtualUnwind; KERNEL32
00005892  48 8B 85 C8 04 00 00  mov     rax, [rbp+4C8h]
00005899  48 8D 4C 24 50  lea     rcx, [rsp+5C0h+var_570]; void *
0000589E  48 89 85 E8 00 00 00  mov     [rbp+4C0h+ContextRecord.Rip], rax
000058A5  33 D2  xor     edx, edx; Val
000058A7  48 8D 85 C8 04 00 00  lea     rax, [rbp+4C8h]
000058AE  41 B8 98 00 00 00  mov     r8d, 98h; Size
000058B4  48 83 C0 08  add     rax, 8
000058B8  48 89 85 88 00 00 00  mov     [rbp+4C0h+ContextRecord.Rsp], rax
000058BF  E8 06 07 00 00  call    memset
000058C4  48 8B 85 C8 04 00 00  mov     rax, [rbp+4C8h]
000058CB  48 89 44 24 60  mov     [rsp+5C0h+var_560], rax
000058D0  C7 44 24 50 15 00 00 40  mov     [rsp+5C0h+var_570], 40000015h
000058D8  C7 44 24 54 01 00 00 00  mov     [rsp+5C0h+var_56C], 1
000058E0  FF 15 22 17 00 00  call    cs:IsDebuggerPresent; KERNEL32
000058E6  83 F8 01  cmp     eax, 1
000058E9  48 8D 44 24 50  lea     rax, [rsp+5C0h+var_570]
000058EE  48 89 44 24 40  mov     [rsp+5C0h+ExceptionInfo.ExceptionRecord], rax
000058F3  48 8D 45 F0  lea     rax, [rbp+4C0h+ContextRecord]
000058F7  0F 94 C3  setz    bl
000058FA  48 89 44 24 48  mov     [rsp+5C0h+ExceptionInfo.ContextRecord], rax
000058FF  33 C9  xor     ecx, ecx; lpTopLevelExceptionFilter
00005901  FF 15 11 17 00 00  call    cs:SetUnhandledExceptionFilter; KERNEL32
00005907  48 8D 4C 24 40  lea     rcx, [rsp+5C0h+ExceptionInfo]; ExceptionInfo
0000590C  FF 15 FE 16 00 00  call    cs:UnhandledExceptionFilter; KERNEL32
00005912  85 C0  test    eax, eax
00005914  75 0C  jnz     short loc_180005922
00005916  84 DB  test    bl, bl
00005918  75 08  jnz     short loc_180005922
0000591A  8D 48 03  lea     ecx, [rax+3]
0000591D  E8 BE FE FF FF  call    __crt_debugger_hook
00005922  48 8B 9C 24 D0 05 00 00  mov     rbx, [rsp+5C0h+arg_0]
0000592A  48 81 C4 C0 05 00 00  add     rsp, 5C0h
00005931  5D  pop     rbp
00005932  C3  retn

; FUNC 00005934-00005968 __raise_securityfailure (52 bytes)
00005934  40 53  push    rbx
00005936  48 83 EC 20  sub     rsp, 20h
0000593A  48 8B D9  mov     rbx, rcx
0000593D  33 C9  xor     ecx, ecx; lpTopLevelExceptionFilter
0000593F  FF 15 D3 16 00 00  call    cs:SetUnhandledExceptionFilter; KERNEL32
00005945  48 8B CB  mov     rcx, rbx; ExceptionInfo
00005948  FF 15 C2 16 00 00  call    cs:UnhandledExceptionFilter; KERNEL32
0000594E  FF 15 24 17 00 00  call    cs:GetCurrentProcess; KERNEL32
00005954  48 8B C8  mov     rcx, rax
00005957  BA 09 04 00 C0  mov     edx, 0C0000409h
0000595C  48 83 C4 20  add     rsp, 20h
00005960  5B  pop     rbx
00005961  48 FF 25 18 17 00 00  jmp     cs:TerminateProcess; KERNEL32

; FUNC 00005968-00005A3A __report_gsfailure (210 bytes)
00005968  48 89 4C 24 08  mov     [rsp+arg_0], rcx
0000596D  48 83 EC 38  sub     rsp, 38h
00005971  B9 17 00 00 00  mov     ecx, 17h; ProcessorFeature
00005976  FF 15 F4 16 00 00  call    cs:IsProcessorFeaturePresent; KERNEL32
0000597C  85 C0  test    eax, eax
0000597E  74 07  jz      short loc_180005987
00005980  B9 02 00 00 00  mov     ecx, 2
00005985  CD 29  int     29h; Win8: RtlFailFast(ecx)
00005987  48 8D 0D C2 5E 00 00  lea     rcx, GS_ContextRecord; ContextRecord
0000598E  E8 A9 00 00 00  call    capture_previous_context
00005993  48 8B 44 24 38  mov     rax, [rsp+38h]
00005998  48 89 05 A9 5F 00 00  mov     cs:GS_ContextRecord.Rip, rax
0000599F  48 8D 44 24 38  lea     rax, [rsp+38h]
000059A4  48 83 C0 08  add     rax, 8
000059A8  48 89 05 39 5F 00 00  mov     cs:GS_ContextRecord.Rsp, rax
000059AF  48 8B 05 92 5F 00 00  mov     rax, cs:GS_ContextRecord.Rip
000059B6  48 89 05 03 5E 00 00  mov     cs:qword_18000B7C0, rax
000059BD  48 8B 44 24 40  mov     rax, [rsp+38h+arg_0]
000059C2  48 89 05 07 5F 00 00  mov     cs:GS_ContextRecord.Rcx, rax
000059C9  C7 05 DD 5D 00 00 09 04 00 C0  mov     cs:GS_ExceptionRecord, 0C0000409h
000059D3  C7 05 D7 5D 00 00 01 00 00 00  mov     cs:dword_18000B7B4, 1
000059DD  C7 05 E1 5D 00 00 01 00 00 00  mov     cs:dword_18000B7C8, 1
000059E7  B8 08 00 00 00  mov     eax, 8
000059EC  48 6B C0 00  imul    rax, 0
000059F0  48 8D 0D D9 5D 00 00  lea     rcx, unk_18000B7D0
000059F7  48 C7 04 01 02 00 00 00  mov     qword ptr [rcx+rax], 2
000059FF  B8 08 00 00 00  mov     eax, 8
00005A04  48 6B C0 00  imul    rax, 0
00005A08  48 8B 0D D9 59 00 00  mov     rcx, cs:__security_cookie
00005A0F  48 89 4C 04 20  mov     [rsp+rax+38h+var_18], rcx
00005A14  B8 08 00 00 00  mov     eax, 8
00005A19  48 6B C0 01  imul    rax, 1
00005A1D  48 8B 0D BC 59 00 00  mov     rcx, cs:__security_cookie_complement
00005A24  48 89 4C 04 20  mov     [rsp+rax+38h+var_18], rcx
00005A29  48 8D 0D B8 28 00 00  lea     rcx, GS_ExceptionPointers; ExceptionInfo
00005A30  E8 FF FE FF FF  call    __raise_securityfailure
00005A35  48 83 C4 38  add     rsp, 38h
00005A39  C3  retn

; FUNC 00005A3C-00005AAD capture_previous_context (113 bytes)
00005A3C  40 53  push    rbx
00005A3E  56  push    rsi
00005A3F  57  push    rdi
00005A40  48 83 EC 40  sub     rsp, 40h
00005A44  48 8B D9  mov     rbx, rcx
00005A47  FF 15 1B 16 00 00  call    cs:RtlCaptureContext; KERNEL32
00005A4D  48 8B B3 F8 00 00 00  mov     rsi, [rbx+0F8h]
00005A54  33 FF  xor     edi, edi
00005A56  45 33 C0  xor     r8d, r8d; HistoryTable
00005A59  48 8D 54 24 60  lea     rdx, [rsp+58h+ImageBase]; ImageBase
00005A5E  48 8B CE  mov     rcx, rsi; ControlPc
00005A61  FF 15 49 16 00 00  call    cs:RtlLookupFunctionEntry; KERNEL32
00005A67  48 85 C0  test    rax, rax
00005A6A  74 39  jz      short loc_180005AA5
00005A6C  48 83 64 24 38 00  and     [rsp+58h+var_20], 0
00005A72  48 8D 4C 24 68  lea     rcx, [rsp+58h+arg_8]
00005A77  48 8B 54 24 60  mov     rdx, [rsp+58h+ImageBase]; ImageBase
00005A7C  4C 8B C8  mov     r9, rax; FunctionEntry
00005A7F  48 89 4C 24 30  mov     [rsp+58h+EstablisherFrame], rcx; EstablisherFrame
00005A84  4C 8B C6  mov     r8, rsi; ControlPc
00005A87  48 8D 4C 24 70  lea     rcx, [rsp+58h+arg_10]
00005A8C  48 89 4C 24 28  mov     [rsp+58h+HandlerData], rcx; HandlerData
00005A91  33 C9  xor     ecx, ecx; HandlerType
00005A93  48 89 5C 24 20  mov     [rsp+58h+ContextRecord], rbx; ContextRecord
00005A98  FF 15 1A 16 00 00  call    cs:RtlVirtualUnwind; KERNEL32
00005A9E  FF C7  inc     edi
00005AA0  83 FF 02  cmp     edi, 2
00005AA3  7C B1  jl      short loc_180005A56
00005AA5  48 83 C4 40  add     rsp, 40h
00005AA9  5F  pop     rdi
00005AAA  5E  pop     rsi
00005AAB  5B  pop     rbx
00005AAC  C3  retn

; FUNC 00005AB0-00005B5C __security_init_cookie (172 bytes)
00005AB0  48 89 5C 24 18  mov     [rsp-8+arg_10], rbx
00005AB5  55  push    rbp
00005AB6  48 8B EC  mov     rbp, rsp
00005AB9  48 83 EC 30  sub     rsp, 30h
00005ABD  48 8B 05 24 59 00 00  mov     rax, cs:__security_cookie
00005AC4  48 BB 32 A2 DF 2D 99 2B 00 00  mov     rbx, 2B992DDFA232h
00005ACE  48 3B C3  cmp     rax, rbx
00005AD1  75 74  jnz     short loc_180005B47
00005AD3  48 83 65 10 00  and     qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime], 0
00005AD8  48 8D 4D 10  lea     rcx, [rbp+SystemTimeAsFileTime]; lpSystemTimeAsFileTime
00005ADC  FF 15 BE 15 00 00  call    cs:GetSystemTimeAsFileTime; KERNEL32
00005AE2  48 8B 45 10  mov     rax, qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime]
00005AE6  48 89 45 F0  mov     [rbp+var_10], rax
00005AEA  FF 15 A8 15 00 00  call    cs:GetCurrentThreadId; KERNEL32
00005AF0  8B C0  mov     eax, eax
00005AF2  48 31 45 F0  xor     [rbp+var_10], rax
00005AF6  FF 15 94 15 00 00  call    cs:GetCurrentProcessId; KERNEL32
00005AFC  8B C0  mov     eax, eax
00005AFE  48 8D 4D 18  lea     rcx, [rbp+PerformanceCount]; lpPerformanceCount
00005B02  48 31 45 F0  xor     [rbp+var_10], rax
00005B06  FF 15 7C 15 00 00  call    cs:QueryPerformanceCounter; KERNEL32
00005B0C  8B 45 18  mov     eax, dword ptr [rbp+PerformanceCount]
00005B0F  48 8D 4D F0  lea     rcx, [rbp+var_10]
00005B13  48 C1 E0 20  shl     rax, 20h
00005B17  48 33 45 18  xor     rax, qword ptr [rbp+PerformanceCount]
00005B1B  48 33 45 F0  xor     rax, [rbp+var_10]
00005B1F  48 33 C1  xor     rax, rcx
00005B22  48 B9 FF FF FF FF FF FF 00 00  mov     rcx, 0FFFFFFFFFFFFh
00005B2C  48 23 C1  and     rax, rcx
00005B2F  48 B9 33 A2 DF 2D 99 2B 00 00  mov     rcx, 2B992DDFA233h
00005B39  48 3B C3  cmp     rax, rbx
00005B3C  48 0F 44 C1  cmovz   rax, rcx
00005B40  48 89 05 A1 58 00 00  mov     cs:__security_cookie, rax
00005B47  48 8B 5C 24 50  mov     rbx, [rsp+30h+arg_10]
00005B4C  48 F7 D0  not     rax
00005B4F  48 89 05 8A 58 00 00  mov     cs:__security_cookie_complement, rax
00005B56  48 83 C4 30  add     rsp, 30h
00005B5A  5D  pop     rbp
00005B5B  C3  retn

; FUNC 00005B5C-00005B6A ?__scrt_initialize_type_info@@YAXXZ (14 bytes)
00005B5C  48 8D 0D BD 61 00 00  lea     rcx, __type_info_node __type_info_root_node
00005B63  48 FF 25 3E 15 00 00  jmp     cs:InitializeSListHead; KERNEL32

; FUNC 00005B6C-00005B78 ?__scrt_uninitialize_type_info@@YAXXZ (12 bytes)
00005B6C  48 8D 0D AD 61 00 00  lea     rcx, __type_info_node __type_info_root_node
00005B73  E9 5E 04 00 00  jmp     __std_type_info_destroy_list

; FUNC 00005B78-00005B80 __local_stdio_scanf_options (8 bytes)
00005B78  48 8D 05 B1 61 00 00  lea     rax, unsigned __int64 `__local_stdio_scanf_options'::`2'::_OptionsStorage
00005B7F  C3  retn

; FUNC 00005B80-00005B9B __scrt_initialize_default_local_stdio_options (27 bytes)
00005B80  48 83 EC 28  sub     rsp, 28h
00005B84  E8 A7 D4 FF FF  call    __local_stdio_printf_options
00005B89  48 83 08 24  or      qword ptr [rax], 24h
00005B8D  E8 E6 FF FF FF  call    __local_stdio_scanf_options
00005B92  48 83 08 02  or      qword ptr [rax], 2
00005B96  48 83 C4 28  add     rsp, 28h
00005B9A  C3  retn

; FUNC 00005B9C-00005BA4 __scrt_get_dyn_tls_init_callback (8 bytes)
00005B9C  48 8D 05 05 62 00 00  lea     rax, __dyn_tls_init_callback
00005BA3  C3  retn

; FUNC 00005BA4-00005BE0 _RTC_Initialize (60 bytes)
00005BA4  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00005BA9  57  push    rdi
00005BAA  48 83 EC 20  sub     rsp, 20h
00005BAE  48 8D 1D D3 31 00 00  lea     rbx, __rtc_izz
00005BB5  48 8D 3D CC 31 00 00  lea     rdi, __rtc_izz
00005BBC  EB 12  jmp     short loc_180005BD0
00005BBE  48 8B 03  mov     rax, [rbx]
00005BC1  48 85 C0  test    rax, rax
00005BC4  74 06  jz      short loc_180005BCC
00005BC6  FF 15 A4 1A 00 00  call    cs:__guard_dispatch_icall_fptr
00005BCC  48 83 C3 08  add     rbx, 8
00005BD0  48 3B DF  cmp     rbx, rdi
00005BD3  72 E9  jb      short loc_180005BBE
00005BD5  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00005BDA  48 83 C4 20  add     rsp, 20h
00005BDE  5F  pop     rdi
00005BDF  C3  retn

; FUNC 00005BE0-00005C1C _RTC_Terminate (60 bytes)
00005BE0  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00005BE5  57  push    rdi
00005BE6  48 83 EC 20  sub     rsp, 20h
00005BEA  48 8D 1D A7 31 00 00  lea     rbx, __rtc_tzz
00005BF1  48 8D 3D A0 31 00 00  lea     rdi, __rtc_tzz
00005BF8  EB 12  jmp     short loc_180005C0C
00005BFA  48 8B 03  mov     rax, [rbx]
00005BFD  48 85 C0  test    rax, rax
00005C00  74 06  jz      short loc_180005C08
00005C02  FF 15 68 1A 00 00  call    cs:__guard_dispatch_icall_fptr
00005C08  48 83 C3 08  add     rbx, 8
00005C0C  48 3B DF  cmp     rbx, rdi
00005C0F  72 E9  jb      short loc_180005BFA
00005C11  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00005C16  48 83 C4 20  add     rsp, 20h
00005C1A  5F  pop     rdi
00005C1B  C3  retn

; FUNC 00005C20-00005CC5 sub_180005C20 (165 bytes)
00005C20  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00005C25  57  push    rdi
00005C26  48 83 EC 20  sub     rsp, 20h
00005C2A  33 D2  xor     edx, edx; Val
00005C2C  48 8B F9  mov     rdi, rcx
00005C2F  44 8D 42 28  lea     r8d, [rdx+28h]; Size
00005C33  49 03 C8  add     rcx, r8; void *
00005C36  E8 8F 03 00 00  call    memset
00005C3B  48 83 67 50 00  and     qword ptr [rdi+50h], 0
00005C40  48 8D 05 B9 A3 FF FF  lea     rax, cs:180000000h
00005C47  83 67 58 00  and     dword ptr [rdi+58h], 0
00005C4B  48 8D 4F 28  lea     rcx, [rdi+28h]; lpCriticalSection
00005C4F  83 67 5C 00  and     dword ptr [rdi+5Ch], 0
00005C53  45 33 C0  xor     r8d, r8d; Flags
00005C56  48 89 47 10  mov     [rdi+10h], rax
00005C5A  33 D2  xor     edx, edx; dwSpinCount
00005C5C  48 89 47 08  mov     [rdi+8], rax
00005C60  48 8D 05 B1 26 00 00  lea     rax, unk_180008318
00005C67  48 89 47 20  mov     [rdi+20h], rax
00005C6B  C7 07 60 00 00 00  mov     dword ptr [rdi], 60h ; '`'
00005C71  C7 47 18 00 0E 00 00  mov     dword ptr [rdi+18h], 0E00h
00005C78  E8 03 B4 FF FF  call    InitializeCriticalSectionEx
00005C7D  85 C0  test    eax, eax
00005C7F  75 36  jnz     short loc_180005CB7
00005C81  FF 15 A1 13 00 00  call    cs:GetLastError; KERNEL32
00005C87  0F B7 C8  movzx   ecx, ax
00005C8A  81 C9 00 00 07 80  or      ecx, 80070000h
00005C90  85 C0  test    eax, eax
00005C92  0F 4E C8  cmovle  ecx, eax
00005C95  85 C9  test    ecx, ecx
00005C97  79 1E  jns     short loc_180005CB7
00005C99  FF 15 69 13 00 00  call    cs:IsDebuggerPresent; KERNEL32
00005C9F  85 C0  test    eax, eax
00005CA1  74 0D  jz      short loc_180005CB0
00005CA3  48 8D 0D 86 26 00 00  lea     rcx, OutputString; "ERROR : Unable to initialize critical s"...
00005CAA  FF 15 50 13 00 00  call    cs:OutputDebugStringW; KERNEL32
00005CB0  C6 05 E9 58 00 00 01  mov     cs:byte_18000B5A0, 1
00005CB7  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00005CBC  48 8B C7  mov     rax, rdi
00005CBF  48 83 C4 20  add     rsp, 20h
00005CC3  5F  pop     rdi
00005CC4  C3  retn

; FUNC 00005CC8-00005CFC sub_180005CC8 (52 bytes)
00005CC8  40 53  push    rbx
00005CCA  48 83 EC 20  sub     rsp, 20h
00005CCE  48 8B D9  mov     rbx, rcx
00005CD1  48 83 C1 28  add     rcx, 28h ; '('; lpCriticalSection
00005CD5  FF 15 5D 13 00 00  call    cs:DeleteCriticalSection; KERNEL32
00005CDB  48 8B 4B 50  mov     rcx, [rbx+50h]; Block
00005CDF  48 85 C9  test    rcx, rcx
00005CE2  74 0A  jz      short loc_180005CEE
00005CE4  E8 F3 02 00 00  call    free
00005CE9  48 83 63 50 00  and     qword ptr [rbx+50h], 0
00005CEE  83 63 58 00  and     dword ptr [rbx+58h], 0
00005CF2  83 63 5C 00  and     dword ptr [rbx+5Ch], 0
00005CF6  48 83 C4 20  add     rsp, 20h
00005CFA  5B  pop     rbx
00005CFB  C3  retn

; FUNC 00005CFC-00005D02 VarBstrCat (6 bytes)
00005CFC  FF 25 C6 13 00 00  jmp     cs:__imp_VarBstrCat

; FUNC 00005D10-00005E22 sub_180005D10 (274 bytes)
00005D10  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00005D15  48 89 74 24 10  mov     [rsp+arg_8], rsi
00005D1A  48 89 7C 24 18  mov     [rsp+arg_10], rdi
00005D1F  4C 89 74 24 20  mov     [rsp+arg_18], r14
00005D24  41 57  push    r15
00005D26  48 83 EC 40  sub     rsp, 40h
00005D2A  48 8B F9  mov     rdi, rcx
00005D2D  48 85 C9  test    rcx, rcx
00005D30  75 1D  jnz     short loc_180005D4F
00005D32  33 C0  xor     eax, eax
00005D34  48 8B 5C 24 50  mov     rbx, [rsp+48h+arg_0]
00005D39  48 8B 74 24 58  mov     rsi, [rsp+48h+arg_8]
00005D3E  48 8B 7C 24 60  mov     rdi, [rsp+48h+arg_10]
00005D43  4C 8B 74 24 68  mov     r14, [rsp+48h+arg_18]
00005D48  48 83 C4 40  add     rsp, 40h
00005D4C  41 5F  pop     r15
00005D4E  C3  retn
00005D4F  48 C7 C3 FF FF FF FF  mov     rbx, 0FFFFFFFFFFFFFFFFh
00005D56  66 66 0F 1F 84 00 00 00 00 00  nop     word ptr [rax+rax+00000000h]
00005D60  48 8D 5B 01  lea     rbx, [rbx+1]
00005D64  66 83 3C 59 00  cmp     word ptr [rcx+rbx*2], 0
00005D69  75 F5  jnz     short loc_180005D60
00005D6B  45 33 FF  xor     r15d, r15d
00005D6E  4C 89 7C 24 38  mov     [rsp+48h+lpUsedDefaultChar], r15; lpUsedDefaultChar
00005D73  4C 89 7C 24 30  mov     [rsp+48h+lpDefaultChar], r15; lpDefaultChar
00005D78  44 89 7C 24 28  mov     [rsp+48h+cbMultiByte], r15d; cbMultiByte
00005D7D  4C 89 7C 24 20  mov     [rsp+48h+lpMultiByteStr], r15; lpMultiByteStr
00005D82  44 8D 4B 01  lea     r9d, [rbx+1]; cchWideChar
00005D86  4C 8B C7  mov     r8, rdi; lpWideCharStr
00005D89  33 D2  xor     edx, edx; dwFlags
00005D8B  33 C9  xor     ecx, ecx; CodePage
00005D8D  FF 15 C5 12 00 00  call    cs:WideCharToMultiByte; KERNEL32
00005D93  4C 63 F0  movsxd  r14, eax
00005D96  85 C0  test    eax, eax
00005D98  74 4C  jz      short loc_180005DE6
00005D9A  49 8B CE  mov     rcx, r14; unsigned __int64
00005D9D  E8 7C 02 00 00  call    operator new[](unsigned __int64)
00005DA2  48 8B F0  mov     rsi, rax
00005DA5  48 85 F6  test    rsi, rsi
00005DA8  74 31  jz      short loc_180005DDB
00005DAA  4C 89 7C 24 38  mov     [rsp+48h+lpUsedDefaultChar], r15; lpUsedDefaultChar
00005DAF  4C 89 7C 24 30  mov     [rsp+48h+lpDefaultChar], r15; lpDefaultChar
00005DB4  44 89 74 24 28  mov     [rsp+48h+cbMultiByte], r14d; cbMultiByte
00005DB9  48 89 74 24 20  mov     [rsp+48h+lpMultiByteStr], rsi; lpMultiByteStr
00005DBE  44 8D 4B 01  lea     r9d, [rbx+1]; cchWideChar
00005DC2  4C 8B C7  mov     r8, rdi; lpWideCharStr
00005DC5  33 D2  xor     edx, edx; dwFlags
00005DC7  33 C9  xor     ecx, ecx; CodePage
00005DC9  FF 15 89 12 00 00  call    cs:WideCharToMultiByte; KERNEL32
00005DCF  85 C0  test    eax, eax
00005DD1  74 2D  jz      short loc_180005E00
00005DD3  48 8B C6  mov     rax, rsi
00005DD6  E9 59 FF FF FF  jmp     loc_180005D34
00005DDB  B9 0E 00 07 80  mov     ecx, 8007000Eh
00005DE0  E8 4B 00 00 00  call    sub_180005E30
00005DE5  CC  int     3; Trap to Debugger
00005DE6  FF 15 3C 12 00 00  call    cs:GetLastError; KERNEL32
00005DEC  85 C0  test    eax, eax
00005DEE  7E 08  jle     short loc_180005DF8
00005DF0  0F B7 C0  movzx   eax, ax
00005DF3  0D 00 00 07 80  or      eax, 80070000h
00005DF8  8B C8  mov     ecx, eax
00005DFA  E8 31 00 00 00  call    sub_180005E30
00005DFF  CC  int     3; Trap to Debugger
00005E00  48 8B CE  mov     rcx, rsi; void *
00005E03  E8 B3 EC FF FF  call    operator delete[](void *)
00005E08  FF 15 1A 12 00 00  call    cs:GetLastError; KERNEL32
00005E0E  85 C0  test    eax, eax
00005E10  7E 08  jle     short loc_180005E1A
00005E12  0F B7 C0  movzx   eax, ax
00005E15  0D 00 00 07 80  or      eax, 80070000h
00005E1A  8B C8  mov     ecx, eax
00005E1C  E8 0F 00 00 00  call    sub_180005E30
00005E21  CC  db 0CCh

; FUNC 00005E30-00005E40 sub_180005E30 (16 bytes)
00005E30  48 8B 05 F1 55 00 00  mov     rax, cs:off_18000B428
00005E37  33 D2  xor     edx, edx
00005E39  48 FF 25 30 18 00 00  jmp     cs:__guard_dispatch_icall_fptr

; FUNC 00005E40-00005E84 sub_180005E40 (68 bytes)
00005E40  40 53  push    rbx
00005E42  48 83 EC 20  sub     rsp, 20h
00005E46  48 8B D9  mov     rbx, rcx
00005E49  48 8D 05 68 25 00 00  lea     rax, off_1800083B8
00005E50  48 89 01  mov     [rcx], rax
00005E53  8B 42 08  mov     eax, [rdx+8]
00005E56  89 41 08  mov     [rcx+8], eax
00005E59  48 8B 4A 10  mov     rcx, [rdx+10h]
00005E5D  48 89 4B 10  mov     [rbx+10h], rcx
00005E61  48 C7 43 18 00 00 00 00  mov     qword ptr [rbx+18h], 0
00005E69  48 85 C9  test    rcx, rcx
00005E6C  74 0D  jz      short loc_180005E7B
00005E6E  48 8B 01  mov     rax, [rcx]
00005E71  48 8B 40 08  mov     rax, [rax+8]
00005E75  FF 15 F5 17 00 00  call    cs:__guard_dispatch_icall_fptr
00005E7B  48 8B C3  mov     rax, rbx
00005E7E  48 83 C4 20  add     rsp, 20h
00005E82  5B  pop     rbx
00005E83  C3  retn

; FUNC 00005E90-00005ED5 sub_180005E90 (69 bytes)
00005E90  40 53  push    rbx
00005E92  48 83 EC 20  sub     rsp, 20h
00005E96  89 51 08  mov     [rcx+8], edx
00005E99  48 8D 05 18 25 00 00  lea     rax, off_1800083B8
00005EA0  48 89 01  mov     [rcx], rax
00005EA3  48 8B D9  mov     rbx, rcx
00005EA6  4C 89 41 10  mov     [rcx+10h], r8
00005EAA  48 C7 41 18 00 00 00 00  mov     qword ptr [rcx+18h], 0
00005EB2  4D 85 C0  test    r8, r8
00005EB5  74 15  jz      short loc_180005ECC
00005EB7  45 84 C9  test    r9b, r9b
00005EBA  74 10  jz      short loc_180005ECC
00005EBC  49 8B 00  mov     rax, [r8]
00005EBF  49 8B C8  mov     rcx, r8
00005EC2  48 8B 40 08  mov     rax, [rax+8]
00005EC6  FF 15 A4 17 00 00  call    cs:__guard_dispatch_icall_fptr
00005ECC  48 8B C3  mov     rax, rbx
00005ECF  48 83 C4 20  add     rsp, 20h
00005ED3  5B  pop     rbx
00005ED4  C3  retn

; FUNC 00005EE0-00005F24 sub_180005EE0 (68 bytes)
00005EE0  40 53  push    rbx
00005EE2  48 83 EC 20  sub     rsp, 20h
00005EE6  48 8D 05 CB 24 00 00  lea     rax, off_1800083B8
00005EED  48 8B D9  mov     rbx, rcx
00005EF0  48 89 01  mov     [rcx], rax
00005EF3  48 8B 49 10  mov     rcx, [rcx+10h]
00005EF7  48 85 C9  test    rcx, rcx
00005EFA  74 0D  jz      short loc_180005F09
00005EFC  48 8B 01  mov     rax, [rcx]
00005EFF  48 8B 40 10  mov     rax, [rax+10h]
00005F03  FF 15 67 17 00 00  call    cs:__guard_dispatch_icall_fptr
00005F09  48 8B 4B 18  mov     rcx, [rbx+18h]
00005F0D  48 85 C9  test    rcx, rcx
00005F10  74 0C  jz      short loc_180005F1E
00005F12  48 83 C4 20  add     rsp, 20h
00005F16  5B  pop     rbx
00005F17  48 FF 25 02 11 00 00  jmp     cs:LocalFree; KERNEL32
00005F1E  48 83 C4 20  add     rsp, 20h
00005F22  5B  pop     rbx
00005F23  C3  retn

; FUNC 00005F30-00005F8F sub_180005F30 (95 bytes)
00005F30  48 89 5C 24 08  mov     [rsp+arg_0], rbx
00005F35  57  push    rdi
00005F36  48 83 EC 20  sub     rsp, 20h
00005F3A  48 8D 05 77 24 00 00  lea     rax, off_1800083B8
00005F41  48 8B D9  mov     rbx, rcx
00005F44  48 89 01  mov     [rcx], rax
00005F47  8B FA  mov     edi, edx
00005F49  48 8B 49 10  mov     rcx, [rcx+10h]
00005F4D  48 85 C9  test    rcx, rcx
00005F50  74 0D  jz      short loc_180005F5F
00005F52  48 8B 01  mov     rax, [rcx]
00005F55  48 8B 40 10  mov     rax, [rax+10h]
00005F59  FF 15 11 17 00 00  call    cs:__guard_dispatch_icall_fptr
00005F5F  48 8B 4B 18  mov     rcx, [rbx+18h]; hMem
00005F63  48 85 C9  test    rcx, rcx
00005F66  74 06  jz      short loc_180005F6E
00005F68  FF 15 B2 10 00 00  call    cs:LocalFree; KERNEL32
00005F6E  40 F6 C7 01  test    dil, 1
00005F72  74 0D  jz      short loc_180005F81
00005F74  BA 20 00 00 00  mov     edx, 20h ; ' '
00005F79  48 8B CB  mov     rcx, rbx; void *
00005F7C  E8 2B EE FF FF  call    operator delete(void *)
00005F81  48 8B C3  mov     rax, rbx
00005F84  48 8B 5C 24 30  mov     rbx, [rsp+28h+arg_0]
00005F89  48 83 C4 20  add     rsp, 20h
00005F8D  5F  pop     rdi
00005F8E  C3  retn

; FUNC 00005F90-00005FB8 _guard_dispatch_icall_nop_0 (40 bytes)
00005F90  48 83 EC 48  sub     rsp, 48h
00005F94  4C 8B C2  mov     r8, rdx
00005F97  45 33 C9  xor     r9d, r9d
00005F9A  8B D1  mov     edx, ecx
00005F9C  48 8D 4C 24 20  lea     rcx, [rsp+48h+pExceptionObject]
00005FA1  E8 EA FE FF FF  call    sub_180005E90
00005FA6  48 8D 15 43 36 00 00  lea     rdx, __TI1?AV_com_error@@; pThrowInfo
00005FAD  48 8D 4C 24 20  lea     rcx, [rsp+48h+pExceptionObject]; pExceptionObject
00005FB2  E8 0D 00 00 00  call    _CxxThrowException
00005FB7  CC  align 8

; FUNC 00005FB8-00005FBE __std_terminate (6 bytes)
00005FB8  FF 25 72 11 00 00  jmp     cs:__imp___std_terminate; VCRUNTIME140

; FUNC 00005FBE-00005FC4 __CxxFrameHandler4 (6 bytes)
00005FBE  FF 25 A4 11 00 00  jmp     cs:__imp___CxxFrameHandler4; VCRUNTIME140_1

; FUNC 00005FC4-00005FCA _CxxThrowException (6 bytes)
00005FC4  FF 25 76 11 00 00  jmp     cs:__imp__CxxThrowException; VCRUNTIME140

; FUNC 00005FCA-00005FD0 memset (6 bytes)
00005FCA  FF 25 78 11 00 00  jmp     cs:__imp_memset; VCRUNTIME140

; FUNC 00005FD0-00005FD6 __C_specific_handler (6 bytes)
00005FD0  FF 25 7A 11 00 00  jmp     cs:__imp___C_specific_handler; VCRUNTIME140

; FUNC 00005FD6-00005FDC __std_type_info_destroy_list (6 bytes)
00005FD6  FF 25 7C 11 00 00  jmp     cs:__imp___std_type_info_destroy_list; VCRUNTIME140

; FUNC 00005FDC-00005FE2 free (6 bytes)
00005FDC  FF 25 96 11 00 00  jmp     cs:__imp_free; api-ms-win-crt-heap-l1-1-0

; FUNC 00005FE2-00005FE8 _seh_filter_dll (6 bytes)
00005FE2  FF 25 C0 11 00 00  jmp     cs:__imp__seh_filter_dll; api-ms-win-crt-runtime-l1-1-0

; FUNC 00005FE8-00005FEE _configure_narrow_argv (6 bytes)
00005FE8  FF 25 DA 11 00 00  jmp     cs:__imp__configure_narrow_argv; api-ms-win-crt-runtime-l1-1-0

; FUNC 00005FEE-00005FF4 _initialize_narrow_environment (6 bytes)
00005FEE  FF 25 94 11 00 00  jmp     cs:__imp__initialize_narrow_environment; api-ms-win-crt-runtime-l1-1-0

; FUNC 00005FF4-00005FFA _initialize_onexit_table (6 bytes)
00005FF4  FF 25 96 11 00 00  jmp     cs:__imp__initialize_onexit_table; api-ms-win-crt-runtime-l1-1-0

; FUNC 00005FFA-00006000 _register_onexit_function (6 bytes)
00005FFA  FF 25 98 11 00 00  jmp     cs:__imp__register_onexit_function; api-ms-win-crt-runtime-l1-1-0

; FUNC 00006000-00006006 _execute_onexit_table (6 bytes)
00006000  FF 25 9A 11 00 00  jmp     cs:__imp__execute_onexit_table; api-ms-win-crt-runtime-l1-1-0

; FUNC 00006006-0000600C _crt_atexit (6 bytes)
00006006  FF 25 C4 11 00 00  jmp     cs:__imp__crt_atexit; api-ms-win-crt-runtime-l1-1-0

; FUNC 0000600C-00006012 _cexit (6 bytes)
0000600C  FF 25 9E 11 00 00  jmp     cs:__imp__cexit; api-ms-win-crt-runtime-l1-1-0

; FUNC 00006012-00006018 _initterm (6 bytes)
00006012  FF 25 A0 11 00 00  jmp     cs:__imp__initterm; api-ms-win-crt-runtime-l1-1-0

; FUNC 00006018-0000601E _initterm_e (6 bytes)
00006018  FF 25 A2 11 00 00  jmp     cs:__imp__initterm_e; api-ms-win-crt-runtime-l1-1-0

; FUNC 0000601E-00006024 ??_U@YAPEAX_K@Z (6 bytes)
0000601E  FF 25 44 14 00 00  jmp     cs:operator new[](unsigned __int64)

; FUNC 00006024-00006027 __vcrt_thread_detach (3 bytes)
00006024  B0 01  mov     al, 1
00006026  C3  retn

; FUNC 00006028-0000602B _is_c_termination_complete (3 bytes)
00006028  33 C0  xor     eax, eax
0000602A  C3  retn

; FUNC 0000602B-00006031 memcpy (6 bytes)
0000602B  FF 25 07 11 00 00  jmp     cs:__imp_memcpy; VCRUNTIME140

; FUNC 00006050-00006052 _guard_dispatch_icall_nop (2 bytes)
00006050  FF E0  jmp     rax

; FUNC 00006070-00006076 _guard_xfg_dispatch_icall_nop (6 bytes)
00006070  FF 25 FA 15 00 00  jmp     cs:__guard_dispatch_icall_fptr

; FUNC 00006080-0000608C sub_180006080 (12 bytes)
00006080  48 8D 8A 80 00 00 00  lea     rcx, [rdx+80h]
00006087  E9 34 B1 FF FF  jmp     sub_1800011C0

; FUNC 00006090-000060B8 sub_180006090 (40 bytes)
00006090  48 89 54 24 10  mov     [rsp+arg_8], rdx
00006095  55  push    rbp
00006096  48 83 EC 30  sub     rsp, 30h
0000609A  48 8B EA  mov     rbp, rdx
0000609D  48 8B 4D 30  mov     rcx, [rbp+30h]; this
000060A1  E8 1B EA FF FF  call    CException::Delete(void)
000060A6  90  nop
000060A7  48 B8 00 00 00 00 00 00 00 00  mov     rax, 0
000060B1  48 83 C4 30  add     rsp, 30h
000060B5  5D  pop     rbp
000060B6  C3  retn
000060B7  CC  db 0CCh

; FUNC 000060C0-000060CC sub_1800060C0 (12 bytes)
000060C0  48 8D 8A 80 00 00 00  lea     rcx, [rdx+80h]
000060C7  E9 04 B1 FF FF  jmp     VariantClear

; FUNC 000060D0-000060DC sub_1800060D0 (12 bytes)
000060D0  48 8D 8A 78 00 00 00  lea     rcx, [rdx+78h]
000060D7  E9 F4 B0 FF FF  jmp     VariantClear

; FUNC 000060E0-000060EC sub_1800060E0 (12 bytes)
000060E0  48 8D 8A 70 00 00 00  lea     rcx, [rdx+70h]
000060E7  E9 E4 B0 FF FF  jmp     VariantClear

; FUNC 000060F0-000060FC sub_1800060F0 (12 bytes)
000060F0  48 8D 8A 68 00 00 00  lea     rcx, [rdx+68h]
000060F7  E9 D4 B0 FF FF  jmp     VariantClear

; FUNC 00006100-0000610C sub_180006100 (12 bytes)
00006100  48 8D 8A 88 00 00 00  lea     rcx, [rdx+88h]
00006107  E9 C4 B0 FF FF  jmp     VariantClear

; FUNC 00006110-0000611C sub_180006110 (12 bytes)
00006110  48 8D 8A 50 00 00 00  lea     rcx, [rdx+50h]
00006117  E9 B4 B0 FF FF  jmp     VariantClear

; FUNC 00006140-0000614C sub_180006140 (12 bytes)
00006140  48 8D 8A 90 00 00 00  lea     rcx, [rdx+90h]
00006147  E9 84 B0 FF FF  jmp     VariantClear

; FUNC 00006150-0000615C sub_180006150 (12 bytes)
00006150  48 8B 8A 30 00 00 00  mov     rcx, [rdx+30h]; this
00006157  E9 64 E3 FF FF  jmp     sub_1800044C0

; FUNC 00006160-00006173 sub_180006160 (19 bytes)
00006160  48 8B 8A 30 00 00 00  mov     rcx, [rdx+30h]
00006167  48 81 C1 50 01 00 00  add     rcx, 150h; this
0000616E  E9 00 EC FF FF  jmp     CTreeCtrl::~CTreeCtrl(void)

; FUNC 00006173-0000618B __scrt_is_nonwritable_in_current_image$filt$0 (24 bytes)
00006173  40 55  push    rbp
00006175  48 8B EA  mov     rbp, rdx
00006178  48 8B 01  mov     rax, [rcx]
0000617B  33 C9  xor     ecx, ecx
0000617D  81 38 05 00 00 C0  cmp     dword ptr [rax], 0C0000005h
00006183  0F 94 C1  setz    cl
00006186  8B C1  mov     eax, ecx
00006188  5D  pop     rbp
00006189  C3  retn
0000618A  CC  db 0CCh

; FUNC 0000618B-000061A2 ?fin$0@?0??dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z@4HA (23 bytes)
0000618B  40 55  push    rbp
0000618D  48 83 EC 20  sub     rsp, 20h
00006191  48 8B EA  mov     rbp, rdx
00006194  8A 4D 40  mov     cl, [rbp+40h]
00006197  48 83 C4 20  add     rsp, 20h
0000619B  5D  pop     rbp
0000619C  E9 EF EE FF FF  jmp     __scrt_release_startup_lock
000061A1  CC  align 2

; FUNC 000061A2-000061BB ?fin$0@?0??dllmain_crt_process_detach@@YAH_N@Z@4HA (25 bytes)
000061A2  40 55  push    rbp
000061A4  48 83 EC 20  sub     rsp, 20h
000061A8  48 8B EA  mov     rbp, rdx
000061AB  8A 4D 20  mov     cl, [rbp+20h]
000061AE  E8 DD EE FF FF  call    __scrt_release_startup_lock
000061B3  90  nop
000061B4  48 83 C4 20  add     rsp, 20h
000061B8  5D  pop     rbp
000061B9  C3  retn
000061BA  CC  db 0CCh

; FUNC 000061BB-000061CF ?fin$1@?0??dllmain_crt_process_detach@@YAH_N@Z@4HA (20 bytes)
000061BB  40 55  push    rbp
000061BD  48 83 EC 20  sub     rsp, 20h
000061C1  48 8B EA  mov     rbp, rdx
000061C4  48 83 C4 20  add     rsp, 20h
000061C8  5D  pop     rbp
000061C9  E9 3E ED FF FF  jmp     __scrt_dllmain_uninitialize_critical
000061CE  CC  db 0CCh

; FUNC 000061CF-00006205 ?filt$0@?0??dllmain_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z@4HA (54 bytes)
000061CF  40 55  push    rbp
000061D1  48 83 EC 30  sub     rsp, 30h
000061D5  48 8B EA  mov     rbp, rdx
000061D8  48 8B 01  mov     rax, [rcx]
000061DB  8B 10  mov     edx, [rax]
000061DD  48 89 4C 24 28  mov     [rsp+38h+ExceptionPtr], rcx; ExceptionPtr
000061E2  89 54 24 20  mov     [rsp+38h+ExceptionNum], edx; ExceptionNum
000061E6  4C 8D 0D D3 F0 FF FF  lea     r9, dllmain_crt_dispatch(HINSTANCE__ * const,ulong,void * const); int
000061ED  4C 8B 45 70  mov     r8, [rbp+70h]; int
000061F1  8B 55 68  mov     edx, [rbp+68h]; int
000061F4  48 8B 4D 60  mov     rcx, [rbp+60h]; int
000061F8  E8 7F EC FF FF  call    __scrt_dllmain_exception_filter
000061FD  90  nop
000061FE  48 83 C4 30  add     rsp, 30h
00006202  5D  pop     rbp
00006203  C3  retn
00006204  CC  db 0CCh

; FUNC 00006210-0000622E sub_180006210 (30 bytes)
00006210  48 89 54 24 10  mov     [rsp+arg_8], rdx
00006215  55  push    rbp
00006216  48 83 EC 40  sub     rsp, 40h
0000621A  48 8B EA  mov     rbp, rdx
0000621D  48 B8 00 00 00 00 00 00 00 00  mov     rax, 0
00006227  48 83 C4 40  add     rsp, 40h
0000622B  5D  pop     rbp
0000622C  C3  retn
0000622D  CC  db 0CCh

; FUNC 00006230-0000623E sub_180006230 (14 bytes)
00006230  48 8D 0D F1 54 00 00  lea     rcx, unk_18000B728
00006237  48 FF 25 6A 13 00 00  jmp     cs:ATL::CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC_DLL<char,ATL::ChTraitsCRT<char>>>(void)

; FUNC 00006240-0000624C sub_180006240 (12 bytes)
00006240  48 8D 0D F9 5A 00 00  lea     rcx, unk_18000BD40
00006247  E9 7C FA FF FF  jmp     sub_180005CC8

; FUNC 00006250-0000625E sub_180006250 (14 bytes)
00006250  48 8D 0D B9 51 00 00  lea     rcx, stru_18000B410
00006257  48 FF 25 72 0E 00 00  jmp     cs:__imp_VariantClear
