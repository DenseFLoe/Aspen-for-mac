# AMD64 COFF member .\Release\acm_dll.obj
# External reference identifiers encode the original relocation type, COFF symbol index and name.
.intel_syntax noprefix

.section a1,"dr"
# COFF section 1: .drectve
begin_1:
symbol_3:  # .drectve
    .ascii "   /FAILIFMISMATCH:\"_MSC_VER=1900\" /FAILIFMISMATCH:\"_ITERATOR_DEBUG_LEVEL=0\" /FAILIFMISMATCH:\"RuntimeLibrary=MD_DynamicRelease\" /DEFAULTLIB:\"msvcprt\" /FAILIFMISMATCH:\"_CRT_STDIO_ISO_WIDE_SPECIFIERS=0\" /FAILIFMISMATCH:\"annotate_string=0\" /FAILIFMISMATCH:\"annotate_vector=0\" /DEFAULTLIB:\"uuid.lib\" /DEFAULTLIB:\"uuid.lib\" /DEFAULTLIB:\"MSVCRT\" /DEFAULTLIB:\"OLDNAMES\" /EXPORT:LoadDynamicLibrary /EXPORT:DisallowForcibleDLLUnloads /EXPORT:DisallowForcibleDLLUnloadsViaFunctionObject /EXPORT:LoadACMUserDLL /EXPORT:UnloadDynamicLibrary /EXPORT:FindACMFunctionInNamedDLL /EXPORT:FindFunctionInNamedDLL /EXPORT:FindFunctionInNamedDLLEx /EXPORT:FindACMFunctionInDLL /EXPORT:FindFunctionInDLL /EXPORT:ReleaseFunction /EXPORT:GetACMFunctionAddress /EXPORT:GetACM13FunctionAddress /EXPORT:GetFunctionAddress /EXPORT:GetFunctionsDLLFileName /EXPORT:GetDLLFileName /EXPORT:GetLastDLLError /EXPORT:ACMDUMMY /EXPORT:ACM13DUMMY "
end_1:

.section a3,"dr"
# COFF section 3: .rdata
begin_3:
symbol_7:  # .rdata
symbol_9:  # ?_Fake_alloc@std@@3U_Fake_allocator@1@B
    .byte 0x00
end_3:

.section a4,"dr"
# COFF section 4: .text$mn
begin_4:
symbol_10:  # .text$mn
symbol_145:  # ??1XosDynamicFunction@@MEAA@XZ
symbol_182:  # $LN8
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbx, rcx                             # +0x0006
    lea rax, [rip + R04_REL32_S361_7XosDynamicFunction_6B] # +0x0009
    mov qword ptr [rcx], rax                        # +0x0010
    mov rax, qword ptr [rcx + 8]                    # +0x0013
    mov rcx, qword ptr [rcx + 0x10]                 # +0x0017
    test rax, rax                                   # +0x001b
    je .Lbb_4_0026                                  # +0x001e
    mov qword ptr [rax + 0x10], rcx                 # +0x0020
    jmp .Lbb_4_002e                                 # +0x0024
.Lbb_4_0026:
    mov rax, qword ptr [rbx + 0x18]                 # +0x0026
    mov qword ptr [rax + 0x20], rcx                 # +0x002a
.Lbb_4_002e:
    mov rcx, qword ptr [rbx + 0x10]                 # +0x002e
    test rcx, rcx                                   # +0x0032
    je .Lbb_4_003f                                  # +0x0035
    mov rax, qword ptr [rbx + 8]                    # +0x0037
    mov qword ptr [rcx + 8], rax                    # +0x003b
.Lbb_4_003f:
    mov rcx, qword ptr [rbx + 0x20]                 # +0x003f
    call R04_REL32_S127_V_YAXPEAX_Z                 # +0x0043
    mov rcx, qword ptr [rbx + 0x18]                 # +0x0048
    call R04_REL32_S138_Unload_XosDynamicLibrary_QEAAHXZ # +0x004c
    nop                                             # +0x0051
    add rsp, 0x20                                   # +0x0052
    pop rbx                                         # +0x0056
    ret                                             # +0x0057
end_4:

.section a6,"dr"
# COFF section 6: .text$mn
begin_6:
symbol_14:  # .text$mn
symbol_176:  # ??_GACMDynamicFunction@@MEAAPEAXI@Z
symbol_199:  # $LN16
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov edi, edx                             # +0x000a
    {load} mov rbx, rcx                             # +0x000c
    lea rax, [rip + R04_REL32_S361_7XosDynamicFunction_6B] # +0x000f
    mov qword ptr [rcx], rax                        # +0x0016
    mov rax, qword ptr [rcx + 8]                    # +0x0019
    mov rcx, qword ptr [rcx + 0x10]                 # +0x001d
    test rax, rax                                   # +0x0021
    je .Lbb_6_002c                                  # +0x0024
    mov qword ptr [rax + 0x10], rcx                 # +0x0026
    jmp .Lbb_6_0034                                 # +0x002a
.Lbb_6_002c:
    mov rax, qword ptr [rbx + 0x18]                 # +0x002c
    mov qword ptr [rax + 0x20], rcx                 # +0x0030
.Lbb_6_0034:
    mov rcx, qword ptr [rbx + 0x10]                 # +0x0034
    test rcx, rcx                                   # +0x0038
    je .Lbb_6_0045                                  # +0x003b
    mov rax, qword ptr [rbx + 8]                    # +0x003d
    mov qword ptr [rcx + 8], rax                    # +0x0041
.Lbb_6_0045:
    mov rcx, qword ptr [rbx + 0x20]                 # +0x0045
    call R04_REL32_S127_V_YAXPEAX_Z                 # +0x0049
    mov rcx, qword ptr [rbx + 0x18]                 # +0x004e
    call R04_REL32_S138_Unload_XosDynamicLibrary_QEAAHXZ # +0x0052
    nop                                             # +0x0057
    test dil, 1                                     # +0x0058
    je .Lbb_6_006b                                  # +0x005c
    mov edx, 0x30                                   # +0x005e
    {load} mov rcx, rbx                             # +0x0063
    call R04_REL32_S125_3_YAXPEAX_K_Z               # +0x0066
.Lbb_6_006b:
    {load} mov rax, rbx                             # +0x006b
    mov rbx, qword ptr [rsp + 0x30]                 # +0x006e
    add rsp, 0x20                                   # +0x0073
    pop rdi                                         # +0x0077
    ret                                             # +0x0078
end_6:

.section a8,"dr"
# COFF section 8: .text$mn
begin_8:
symbol_18:  # .text$mn
symbol_170:  # ??_GACMDynamicLibrary@@MEAAPEAXI@Z
symbol_197:  # $LN11
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    lea rax, [rip + R04_REL32_S364_7ACMDynamicLibrary_6B] # +0x000a
    {load} mov ebx, edx                             # +0x0011
    mov qword ptr [rcx], rax                        # +0x0013
    {load} mov rdi, rcx                             # +0x0016
    call R04_REL32_S131_1XosDynamicLibrary_MEAA_XZ  # +0x0019
    test bl, 1                                      # +0x001e
    je .Lbb_8_0030                                  # +0x0021
    mov edx, 0x60                                   # +0x0023
    {load} mov rcx, rdi                             # +0x0028
    call R04_REL32_S125_3_YAXPEAX_K_Z               # +0x002b
.Lbb_8_0030:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0030
    {load} mov rax, rdi                             # +0x0035
    add rsp, 0x20                                   # +0x0038
    pop rdi                                         # +0x003c
    ret                                             # +0x003d
end_8:

.section a10,"dr"
# COFF section 10: .text$mn
begin_10:
symbol_22:  # .text$mn
symbol_147:  # ??_GXosDynamicFunction@@MEAAPEAXI@Z
symbol_183:  # $LN13
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov edi, edx                             # +0x000a
    {load} mov rbx, rcx                             # +0x000c
    lea rax, [rip + R04_REL32_S361_7XosDynamicFunction_6B] # +0x000f
    mov qword ptr [rcx], rax                        # +0x0016
    mov rax, qword ptr [rcx + 8]                    # +0x0019
    mov rcx, qword ptr [rcx + 0x10]                 # +0x001d
    test rax, rax                                   # +0x0021
    je .Lbb_10_002c                                 # +0x0024
    mov qword ptr [rax + 0x10], rcx                 # +0x0026
    jmp .Lbb_10_0034                                # +0x002a
.Lbb_10_002c:
    mov rax, qword ptr [rbx + 0x18]                 # +0x002c
    mov qword ptr [rax + 0x20], rcx                 # +0x0030
.Lbb_10_0034:
    mov rcx, qword ptr [rbx + 0x10]                 # +0x0034
    test rcx, rcx                                   # +0x0038
    je .Lbb_10_0045                                 # +0x003b
    mov rax, qword ptr [rbx + 8]                    # +0x003d
    mov qword ptr [rcx + 8], rax                    # +0x0041
.Lbb_10_0045:
    mov rcx, qword ptr [rbx + 0x20]                 # +0x0045
    call R04_REL32_S127_V_YAXPEAX_Z                 # +0x0049
    mov rcx, qword ptr [rbx + 0x18]                 # +0x004e
    call R04_REL32_S138_Unload_XosDynamicLibrary_QEAAHXZ # +0x0052
    nop                                             # +0x0057
    test dil, 1                                     # +0x0058
    je .Lbb_10_006b                                 # +0x005c
    mov edx, 0x30                                   # +0x005e
    {load} mov rcx, rbx                             # +0x0063
    call R04_REL32_S125_3_YAXPEAX_K_Z               # +0x0066
.Lbb_10_006b:
    {load} mov rax, rbx                             # +0x006b
    mov rbx, qword ptr [rsp + 0x30]                 # +0x006e
    add rsp, 0x20                                   # +0x0073
    pop rdi                                         # +0x0077
    ret                                             # +0x0078
end_10:

.section a12,"dr"
# COFF section 12: .text$mn
begin_12:
symbol_26:  # .text$mn
symbol_142:  # ??_GXosDynamicLibrary@@MEAAPEAXI@Z
symbol_181:  # $LN8
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov ebx, edx                             # +0x000a
    {load} mov rdi, rcx                             # +0x000c
    call R04_REL32_S131_1XosDynamicLibrary_MEAA_XZ  # +0x000f
    test bl, 1                                      # +0x0014
    je .Lbb_12_0026                                 # +0x0017
    mov edx, 0x60                                   # +0x0019
    {load} mov rcx, rdi                             # +0x001e
    call R04_REL32_S125_3_YAXPEAX_K_Z               # +0x0021
.Lbb_12_0026:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0026
    {load} mov rax, rdi                             # +0x002b
    add rsp, 0x20                                   # +0x002e
    pop rdi                                         # +0x0032
    ret                                             # +0x0033
end_12:

.section a14,"dr"
# COFF section 14: .text$mn
begin_14:
symbol_30:  # .text$mn
symbol_175:  # ?Find@ACMDynamicFunction@@SAHPEAD0PEAPEAV1@PEAXPEBD@Z
symbol_198:  # $LN7
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    {load} mov rax, rdx                             # +0x000f
    {load} mov rsi, rcx                             # +0x0012
    {load} mov rcx, rax                             # +0x0015
    {load} mov rdx, r9                              # +0x0018
    {load} mov rbx, r8                              # +0x001b
    call R04_REL32_S168_Load_ACMDynamicLibrary_SAPEAVXosDynamicLibrary_PEBDPEAX_Z # +0x001e
    mov qword ptr [rbx], 0                          # +0x0023
    {load} mov rdi, rax                             # +0x002a
    test rax, rax                                   # +0x002d
    je .Lbb_14_0063                                 # +0x0030
    mov r10, qword ptr [rax]                        # +0x0032
    {load} mov r8, rbx                              # +0x0035
    mov r9, qword ptr [rsp + 0x50]                  # +0x0038
    {load} mov rdx, rsi                             # +0x003d
    {load} mov rcx, rax                             # +0x0040
    call qword ptr [r10 + 0x10]                     # +0x0043
    {load} mov rcx, rdi                             # +0x0047
    {load} mov ebx, eax                             # +0x004a
    call R04_REL32_S138_Unload_XosDynamicLibrary_QEAAHXZ # +0x004c
    {load} mov eax, ebx                             # +0x0051
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0053
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0058
    add rsp, 0x20                                   # +0x005d
    pop rdi                                         # +0x0061
    ret                                             # +0x0062
.Lbb_14_0063:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0063
    mov eax, 0xa0000034                             # +0x0068
    mov rsi, qword ptr [rsp + 0x38]                 # +0x006d
    add rsp, 0x20                                   # +0x0072
    pop rdi                                         # +0x0076
    ret                                             # +0x0077
end_14:

.section a16,"dr"
# COFF section 16: .text$mn
begin_16:
symbol_34:  # .text$mn
symbol_169:  # ?FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
symbol_196:  # $LN24
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    push rsi                                        # +0x000a
    push rdi                                        # +0x000b
    push r12                                        # +0x000c
    push r14                                        # +0x000e
    push r15                                        # +0x0010
    sub rsp, 0x30                                   # +0x0012
    {load} mov rbx, r9                              # +0x0016
    {load} mov r15, r8                              # +0x0019
    {load} mov rsi, rdx                             # +0x001c
    {load} mov r14, rcx                             # +0x001f
    mov rcx, qword ptr [r8]                         # +0x0022
    {load} xor ebp, ebp                             # +0x0025
    test rcx, rcx                                   # +0x0027
    je .Lbb_16_0037                                 # +0x002a
    mov rax, qword ptr [rcx]                        # +0x002c
    lea edx, [rbp + 1]                              # +0x002f
    call qword ptr [rax]                            # +0x0032
    mov qword ptr [r15], rbp                        # +0x0034
.Lbb_16_0037:
    mov qword ptr [rsp + 0x70], rbp                 # +0x0037
    lea r9, [rsp + 0x70]                            # +0x003c
    {load} mov r8, rbx                              # +0x0041
    {load} mov rdx, rsi                             # +0x0044
    {load} mov rcx, r14                             # +0x0047
    call R04_REL32_S136_FindFunction_XosDynamicLibrary_QEBAPEAVXosDynamicFunction_PEBD0PEAPEAD_Z # +0x004a
    mov qword ptr [r15], rax                        # +0x004f
    test rax, rax                                   # +0x0052
    {disp32} jne .Lbb_16_0115                       # +0x0055
    mov rax, qword ptr [rsp + 0x70]                 # +0x005b
    test rax, rax                                   # +0x0060
    cmovne rsi, rax                                 # +0x0063
    {load} xor r9d, r9d                             # +0x0067
    {load} xor r8d, r8d                             # +0x006a
    {load} mov rdx, rsi                             # +0x006d
    {load} mov rcx, r14                             # +0x0070
    call R04_REL32_S137_FindCallAddress_XosDynamicLibrary_QEAAPEAXPEBD0PEAPEAD_Z # +0x0073
    {load} mov r12, rax                             # +0x0078
    test rax, rax                                   # +0x007b
    {disp32} je .Lbb_16_0110                        # +0x007e
    mov ecx, 0x30                                   # +0x0084
    call R04_REL32_S124_2_YAPEAX_K_Z                # +0x0089
    {load} mov rdi, rax                             # +0x008e
    mov qword ptr [rsp + 0x20], rax                 # +0x0091
    test rax, rax                                   # +0x0096
    je .Lbb_16_0108                                 # +0x0099
    lea rax, [rip + R04_REL32_S361_7XosDynamicFunction_6B] # +0x009b
    mov qword ptr [rdi], rax                        # +0x00a2
    mov qword ptr [rdi + 0x18], r14                 # +0x00a5
    inc dword ptr [r14 + 0x40]                      # +0x00a9
    mov rbx, 0xffffffffffffffff                     # +0x00ad
.Lbb_16_00b4:
    lea rbx, [rbx + 1]                              # +0x00b4
    cmp byte ptr [rsi + rbx], 0                     # +0x00b8
    jne .Lbb_16_00b4                                # +0x00bc
    lea rcx, [rbx + 1]                              # +0x00be
    call R04_REL32_S126_U_YAPEAX_K_Z                # +0x00c2
    mov qword ptr [rdi + 0x20], rax                 # +0x00c7
    {load} mov r8, rsi                              # +0x00cb
    lea rdx, [rbx + 1]                              # +0x00ce
    {load} mov rcx, rax                             # +0x00d2
    call qword ptr [rip + R04_REL32_S129_imp_strcpy_s] # +0x00d5
    mov qword ptr [rdi + 0x28], r12                 # +0x00db
    mov qword ptr [rdi + 8], rbp                    # +0x00df
    mov rax, qword ptr [r14 + 0x20]                 # +0x00e3
    mov qword ptr [rdi + 0x10], rax                 # +0x00e7
    mov rax, qword ptr [r14 + 0x20]                 # +0x00eb
    test rax, rax                                   # +0x00ef
    je .Lbb_16_00f8                                 # +0x00f2
    mov qword ptr [rax + 8], rdi                    # +0x00f4
.Lbb_16_00f8:
    mov qword ptr [r14 + 0x20], rdi                 # +0x00f8
    lea rax, [rip + R04_REL32_S367_7ACMDynamicFunction_6B] # +0x00fc
    mov qword ptr [rdi], rax                        # +0x0103
    jmp .Lbb_16_010b                                # +0x0106
.Lbb_16_0108:
    {load} mov rdi, rbp                             # +0x0108
.Lbb_16_010b:
    mov qword ptr [r15], rdi                        # +0x010b
    jmp .Lbb_16_0115                                # +0x010e
.Lbb_16_0110:
    mov ebp, 0xa0000033                             # +0x0110
.Lbb_16_0115:
    mov rcx, qword ptr [rsp + 0x70]                 # +0x0115
    call R04_REL32_S127_V_YAXPEAX_Z                 # +0x011a
    {load} mov eax, ebp                             # +0x011f
    mov rbx, qword ptr [rsp + 0x60]                 # +0x0121
    mov rbp, qword ptr [rsp + 0x68]                 # +0x0126
    add rsp, 0x30                                   # +0x012b
    pop r15                                         # +0x012f
    pop r14                                         # +0x0131
    pop r12                                         # +0x0133
    pop rdi                                         # +0x0135
    pop rsi                                         # +0x0136
    ret                                             # +0x0137
end_16:

.section a18,"dr"
# COFF section 18: .text$x
begin_18:
symbol_38:  # .text$x
# Cleanup funclet: release the 0x30-byte allocation via sized operator delete.
symbol_179:  # ?dtor$0@?0??FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z@4HA
    rex push rbp                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbp, rdx                             # +0x0006
    mov edx, 0x30                                   # +0x0009
    mov rcx, qword ptr [rbp + 0x20]                 # +0x000e
    call R04_REL32_S125_3_YAXPEAX_K_Z               # +0x0012
    add rsp, 0x20                                   # +0x0017
    pop rbp                                         # +0x001b
    ret                                             # +0x001c
end_18:

.section a19,"dr"
# COFF section 19: .text$mn
begin_19:
symbol_40:  # .text$mn
symbol_167:  # ?Initialize@ACMDynamicLibrary@@MEAAHPEAX@Z
symbol_194:  # $LN19
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov rdi, rdx                             # +0x000a
    {load} mov rbx, rcx                             # +0x000d
    test rdx, rdx                                   # +0x0010
    je .Lbb_19_0087                                 # +0x0013
    call R04_REL32_S135_Initialize_XosDynamicLibrary_UEAAHPEAX_Z # +0x0015
    test eax, eax                                   # +0x001a
    jne .Lbb_19_0049                                # +0x001c
    {load} xor r9d, r9d                             # +0x001e
    lea rdx, [rip + R04_REL32_S370_C__0BC_EFJNDBE_SputUtilitiesInit] # +0x0021
    {load} xor r8d, r8d                             # +0x0028
    {load} mov rcx, rbx                             # +0x002b
    call R04_REL32_S130_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x002e
    test rax, rax                                   # +0x0033
    je .Lbb_19_0057                                 # +0x0036
    mov rdx, qword ptr [rdi + 0x10]                 # +0x0038
    mov rcx, qword ptr [rdi + 8]                    # +0x003c
    call rax                                        # +0x0040
    mov dword ptr [rbx + 0x44], 1                   # +0x0042
.Lbb_19_0049:
    mov eax, dword ptr [rbx + 0x44]                 # +0x0049
    mov rbx, qword ptr [rsp + 0x30]                 # +0x004c
    add rsp, 0x20                                   # +0x0051
    pop rdi                                         # +0x0055
    ret                                             # +0x0056
.Lbb_19_0057:
    {load} mov rdx, rdi                             # +0x0057
    lea rcx, [rip + R04_REL32_S373_C__0O_EDGNKEMM_atdll_support] # +0x005a
    call R04_REL32_S168_Load_ACMDynamicLibrary_SAPEAVXosDynamicLibrary_PEBDPEAX_Z # +0x0061
    test rax, rax                                   # +0x0066
    je .Lbb_19_0049                                 # +0x0069
    mov ecx, dword ptr [rax + 0x44]                 # +0x006b
    mov dword ptr [rbx + 0x44], ecx                 # +0x006e
    {load} mov rcx, rax                             # +0x0071
    call R04_REL32_S138_Unload_XosDynamicLibrary_QEAAHXZ # +0x0074
    mov eax, dword ptr [rbx + 0x44]                 # +0x0079
    mov rbx, qword ptr [rsp + 0x30]                 # +0x007c
    add rsp, 0x20                                   # +0x0081
    pop rdi                                         # +0x0085
    ret                                             # +0x0086
.Lbb_19_0087:
    mov eax, dword ptr [rcx + 0x44]                 # +0x0087
    mov rbx, qword ptr [rsp + 0x30]                 # +0x008a
    add rsp, 0x20                                   # +0x008f
    pop rdi                                         # +0x0093
    ret                                             # +0x0094
end_19:

.section a21,"dr"
# COFF section 21: .text$mn
begin_21:
symbol_44:  # .text$mn
symbol_168:  # ?Load@ACMDynamicLibrary@@SAPEAVXosDynamicLibrary@@PEBDPEAX@Z
symbol_195:  # $LN18
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x30                                   # +0x0006
    {load} mov rbx, rdx                             # +0x000a
    lea r8, [rsp + 0x50]                            # +0x000d
    {load} xor edi, edi                             # +0x0012
    lea rdx, [rsp + 0x58]                           # +0x0014
    mov qword ptr [rsp + 0x50], rdi                 # +0x0019
    mov qword ptr [rsp + 0x58], rdi                 # +0x001e
    call R04_REL32_S132_FindLibrary_XosDynamicLibrary_KAPEAV1_PEBDAEAPEAD1_Z # +0x0023
    test rax, rax                                   # +0x0028
    {disp32} jne .Lbb_21_00c9                       # +0x002b
    lea ecx, [rdi + 0x60]                           # +0x0031
    call R04_REL32_S124_2_YAPEAX_K_Z                # +0x0034
    mov qword ptr [rsp + 0x20], rax                 # +0x0039
    {load} mov r9, rax                              # +0x003e
    test rax, rax                                   # +0x0041
    je .Lbb_21_00b8                                 # +0x0044
    mov rax, qword ptr [rsp + 0x58]                 # +0x0046
    lea rdx, [rip + R04_REL32_S358_7XosDynamicLibrary_6B] # +0x004b
    mov rcx, qword ptr [rsp + 0x50]                 # +0x0052
    mov qword ptr [r9], rdx                         # +0x0057
    mov qword ptr [r9 + 0x28], rax                  # +0x005a
    mov qword ptr [r9 + 0x30], rcx                  # +0x005e
    mov qword ptr [r9 + 0x50], rdi                  # +0x0062
    mov dword ptr [r9 + 0x58], edi                  # +0x0066
    mov dword ptr [r9 + 0x48], 1                    # +0x006a
    mov qword ptr [r9 + 0x40], 1                    # +0x0072
    mov dword ptr [r9 + 8], edi                     # +0x007a
    mov qword ptr [r9 + 0x38], rdi                  # +0x007e
    mov qword ptr [r9 + 0x10], rdi                  # +0x0082
    mov rax, qword ptr [rip + R04_REL32_S354_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0086
    mov qword ptr [r9 + 0x18], rax                  # +0x008d
    mov rax, qword ptr [rip + R04_REL32_S354_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0091
    test rax, rax                                   # +0x0098
    je .Lbb_21_00a1                                 # +0x009b
    mov qword ptr [rax + 0x10], r9                  # +0x009d
.Lbb_21_00a1:
    mov qword ptr [rip + R04_REL32_S354_m_pDLLs_XosDynamicLibrary_0PEAV1_EA], r9 # +0x00a1
    lea rax, [rip + R04_REL32_S364_7ACMDynamicLibrary_6B] # +0x00a8
    mov qword ptr [r9], rax                         # +0x00af
    mov qword ptr [r9 + 0x20], rdi                  # +0x00b2
    jmp .Lbb_21_00bb                                # +0x00b6
.Lbb_21_00b8:
    {load} mov r9, rdi                              # +0x00b8
.Lbb_21_00bb:
    {load} xor r8d, r8d                             # +0x00bb
    {load} mov rdx, rbx                             # +0x00be
    {load} mov rcx, r9                              # +0x00c1
    call R04_REL32_S133_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z # +0x00c4
.Lbb_21_00c9:
    mov rbx, qword ptr [rsp + 0x40]                 # +0x00c9
    add rsp, 0x30                                   # +0x00ce
    pop rdi                                         # +0x00d2
    ret                                             # +0x00d3
end_21:

.section a23,"dr"
# COFF section 23: .text$mn
begin_23:
symbol_48:  # .text$mn
# ACM13 fallback. Parameter 16 is the iflag pointer on Win64. Store an eight-byte 4.
symbol_174:  # ACM13DUMMY
    mov rax, qword ptr [rsp + 0x80]                 # +0x0000
    mov qword ptr [rax], 4                          # +0x0008
    ret                                             # +0x000f
end_23:

.section a25,"dr"
# COFF section 25: .text$mn
begin_25:
symbol_52:  # .text$mn
# ACM fallback. Parameter 7 is the iflag pointer on Win64. Store an eight-byte 4.
symbol_173:  # ACMDUMMY
    mov rax, qword ptr [rsp + 0x38]                 # +0x0000
    mov qword ptr [rax], 4                          # +0x0005
    ret                                             # +0x000c
end_25:

.section a27,"dr"
# COFF section 27: .text$mn
begin_27:
symbol_56:  # .text$mn
symbol_151:  # DisallowForcibleDLLUnloads
    test rcx, rcx                                   # +0x0000
    je .Lbb_27_000c                                 # +0x0003
    mov dword ptr [rcx + 0x48], 0                   # +0x0005
.Lbb_27_000c:
    ret                                             # +0x000c
end_27:

.section a29,"dr"
# COFF section 29: .text$mn
begin_29:
symbol_60:  # .text$mn
symbol_152:  # DisallowForcibleDLLUnloadsViaFunctionObject
    test rcx, rcx                                   # +0x0000
    je .Lbb_29_0010                                 # +0x0003
    mov rax, qword ptr [rcx + 0x18]                 # +0x0005
    mov dword ptr [rax + 0x48], 0                   # +0x0009
.Lbb_29_0010:
    ret                                             # +0x0010
end_29:

.section a31,"dr"
# COFF section 31: .text$mn
begin_31:
symbol_64:  # .text$mn
symbol_158:  # FindACMFunctionInDLL
symbol_187:  # $LN4
    sub rsp, 0x28                                   # +0x0000
    mov rax, qword ptr [rdx]                        # +0x0004
    lea r9, [rip + R04_REL32_S376_C__0P_FBHPFKIC_DIDIIIIIDIDIII] # +0x0007
    {load} mov r10, rdx                             # +0x000e
    mov qword ptr [rsp + 0x38], 0                   # +0x0011
    {load} mov rdx, rcx                             # +0x001a
    lea r8, [rsp + 0x38]                            # +0x001d
    {load} mov rcx, r10                             # +0x0022
    call qword ptr [rax + 0x10]                     # +0x0025
    mov rax, qword ptr [rsp + 0x38]                 # +0x0028
    add rsp, 0x28                                   # +0x002d
    ret                                             # +0x0031
end_31:

.section a33,"dr"
# COFF section 33: .text$mn
begin_33:
symbol_68:  # .text$mn
symbol_155:  # FindACMFunctionInNamedDLL
symbol_184:  # $LN4
    sub rsp, 0x48                                   # +0x0000
    mov qword ptr [rsp + 0x20], r9                  # +0x0004
    {load} mov r9, r8                               # +0x0009
    lea r8, [rsp + 0x30]                            # +0x000c
    mov qword ptr [rsp + 0x30], 0                   # +0x0011
    call R04_REL32_S175_Find_ACMDynamicFunction_SAHPEAD0PEAPEAV1_PEAXPEBD_Z # +0x001a
    mov rax, qword ptr [rsp + 0x30]                 # +0x001f
    add rsp, 0x48                                   # +0x0024
    ret                                             # +0x0028
end_33:

.section a35,"dr"
# COFF section 35: .text$mn
begin_35:
symbol_72:  # .text$mn
symbol_159:  # FindFunctionInDLL
symbol_188:  # $LN4
    sub rsp, 0x28                                   # +0x0000
    mov rax, qword ptr [rdx]                        # +0x0004
    {load} mov r10, rdx                             # +0x0007
    {load} mov r9, r8                               # +0x000a
    mov qword ptr [rsp + 0x38], 0                   # +0x000d
    {load} mov rdx, rcx                             # +0x0016
    lea r8, [rsp + 0x38]                            # +0x0019
    {load} mov rcx, r10                             # +0x001e
    call qword ptr [rax + 0x10]                     # +0x0021
    mov rax, qword ptr [rsp + 0x38]                 # +0x0024
    add rsp, 0x28                                   # +0x0029
    ret                                             # +0x002d
end_35:

.section a37,"dr"
# COFF section 37: .text$mn
begin_37:
symbol_76:  # .text$mn
symbol_156:  # FindFunctionInNamedDLL
symbol_185:  # $LN4
    sub rsp, 0x48                                   # +0x0000
    mov qword ptr [rsp + 0x20], r9                  # +0x0004
    {load} mov r9, r8                               # +0x0009
    lea r8, [rsp + 0x30]                            # +0x000c
    mov qword ptr [rsp + 0x30], 0                   # +0x0011
    call R04_REL32_S146_Find_XosDynamicFunction_SAHPEAD0PEAPEAV1_PEAXPEBD_Z # +0x001a
    mov rax, qword ptr [rsp + 0x30]                 # +0x001f
    add rsp, 0x48                                   # +0x0024
    ret                                             # +0x0028
end_37:

.section a39,"dr"
# COFF section 39: .text$mn
begin_39:
symbol_80:  # .text$mn
symbol_157:  # FindFunctionInNamedDLLEx
symbol_186:  # $LN4
    sub rsp, 0x48                                   # +0x0000
    mov qword ptr [rsp + 0x20], r9                  # +0x0004
    {load} mov r9, r8                               # +0x0009
    lea r8, [rsp + 0x30]                            # +0x000c
    mov qword ptr [rsp + 0x30], 0                   # +0x0011
    call R04_REL32_S146_Find_XosDynamicFunction_SAHPEAD0PEAPEAV1_PEAXPEBD_Z # +0x001a
    mov rcx, qword ptr [rsp + 0x70]                 # +0x001f
    mov dword ptr [rcx], eax                        # +0x0024
    mov rax, qword ptr [rsp + 0x30]                 # +0x0026
    add rsp, 0x48                                   # +0x002b
    ret                                             # +0x002f
end_39:

.section a41,"dr"
# COFF section 41: .text$mn
begin_41:
symbol_84:  # .text$mn
symbol_162:  # GetACM13FunctionAddress
symbol_190:  # $LN10
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbx, rcx                             # +0x0006
    mov rcx, qword ptr [rcx + 0x18]                 # +0x0009
    cmp dword ptr [rcx + 0x58], 3                   # +0x000d
    jne .Lbb_41_0018                                # +0x0011
    call R04_REL32_S134_Reload_XosDynamicLibrary_IEAAXXZ # +0x0013
.Lbb_41_0018:
    mov rcx, qword ptr [rbx + 0x28]                 # +0x0018
    lea rax, [rip + R04_REL32_S174_ACM13DUMMY]      # +0x001c
    test rcx, rcx                                   # +0x0023
    cmovne rax, rcx                                 # +0x0026
    add rsp, 0x20                                   # +0x002a
    pop rbx                                         # +0x002e
    ret                                             # +0x002f
end_41:

.section a43,"dr"
# COFF section 43: .text$mn
begin_43:
symbol_88:  # .text$mn
symbol_161:  # GetACMFunctionAddress
symbol_189:  # $LN10
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbx, rcx                             # +0x0006
    mov rcx, qword ptr [rcx + 0x18]                 # +0x0009
    cmp dword ptr [rcx + 0x58], 3                   # +0x000d
    jne .Lbb_43_0018                                # +0x0011
    call R04_REL32_S134_Reload_XosDynamicLibrary_IEAAXXZ # +0x0013
.Lbb_43_0018:
    mov rcx, qword ptr [rbx + 0x28]                 # +0x0018
    lea rax, [rip + R04_REL32_S173_ACMDUMMY]        # +0x001c
    test rcx, rcx                                   # +0x0023
    cmovne rax, rcx                                 # +0x0026
    add rsp, 0x20                                   # +0x002a
    pop rbx                                         # +0x002e
    ret                                             # +0x002f
end_43:

.section a45,"dr"
# COFF section 45: .text$mn
begin_45:
symbol_92:  # .text$mn
symbol_165:  # GetDLLFileName
symbol_193:  # $LN9
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    movsxd rdi, r8d                                 # +0x000f
    {load} mov rsi, rdx                             # +0x0012
    call R04_REL32_S141_GetFullPath_XosDynamicLibrary_QEBAPEADXZ # +0x0015
    mov rbx, 0xffffffffffffffff                     # +0x001a
.Lbb_45_0021:
    inc rbx                                         # +0x0021
    cmp byte ptr [rax + rbx], 0                     # +0x0024
    jne .Lbb_45_0021                                # +0x0028
    {load} cmp ebx, edi                             # +0x002a
    jge .Lbb_45_004f                                # +0x002c
    {load} mov rdx, rdi                             # +0x002e
    {load} mov r8, rax                              # +0x0031
    {load} mov rcx, rsi                             # +0x0034
    call qword ptr [rip + R04_REL32_S129_imp_strcpy_s] # +0x0037
    {load} mov eax, ebx                             # +0x003d
    mov rbx, qword ptr [rsp + 0x30]                 # +0x003f
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0044
    add rsp, 0x20                                   # +0x0049
    pop rdi                                         # +0x004d
    ret                                             # +0x004e
.Lbb_45_004f:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x004f
    {load} xor eax, eax                             # +0x0054
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0056
    add rsp, 0x20                                   # +0x005b
    pop rdi                                         # +0x005f
    ret                                             # +0x0060
end_45:

.section a47,"dr"
# COFF section 47: .text$mn
begin_47:
symbol_96:  # .text$mn
symbol_163:  # GetFunctionAddress
symbol_191:  # $LN9
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbx, rcx                             # +0x0006
    mov rcx, qword ptr [rcx + 0x18]                 # +0x0009
    cmp dword ptr [rcx + 0x58], 3                   # +0x000d
    jne .Lbb_47_0018                                # +0x0011
    call R04_REL32_S134_Reload_XosDynamicLibrary_IEAAXXZ # +0x0013
.Lbb_47_0018:
    mov rax, qword ptr [rbx + 0x28]                 # +0x0018
    add rsp, 0x20                                   # +0x001c
    pop rbx                                         # +0x0020
    ret                                             # +0x0021
end_47:

.section a49,"dr"
# COFF section 49: .text$mn
begin_49:
symbol_100:  # .text$mn
symbol_164:  # GetFunctionsDLLFileName
symbol_192:  # $LN11
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    mov rcx, qword ptr [rcx + 0x18]                 # +0x000f
    {load} mov rsi, rdx                             # +0x0013
    movsxd rdi, r8d                                 # +0x0016
    call R04_REL32_S141_GetFullPath_XosDynamicLibrary_QEBAPEADXZ # +0x0019
    mov rbx, 0xffffffffffffffff                     # +0x001e
.Lbb_49_0025:
    inc rbx                                         # +0x0025
    cmp byte ptr [rax + rbx], 0                     # +0x0028
    jne .Lbb_49_0025                                # +0x002c
    {load} cmp ebx, edi                             # +0x002e
    jge .Lbb_49_0053                                # +0x0030
    {load} mov rdx, rdi                             # +0x0032
    {load} mov r8, rax                              # +0x0035
    {load} mov rcx, rsi                             # +0x0038
    call qword ptr [rip + R04_REL32_S129_imp_strcpy_s] # +0x003b
    {load} mov eax, ebx                             # +0x0041
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0043
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0048
    add rsp, 0x20                                   # +0x004d
    pop rdi                                         # +0x0051
    ret                                             # +0x0052
.Lbb_49_0053:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0053
    {load} xor eax, eax                             # +0x0058
    mov rsi, qword ptr [rsp + 0x38]                 # +0x005a
    add rsp, 0x20                                   # +0x005f
    pop rdi                                         # +0x0063
    ret                                             # +0x0064
end_49:

.section a51,"dr"
# COFF section 51: .text$mn
begin_51:
symbol_104:  # .text$mn
symbol_166:  # GetLastDLLError
    mov eax, dword ptr [rip + R04_REL32_S355_m_iStatus_XosDynamicLibrary_0HA] # +0x0000
    ret                                             # +0x0006
end_51:

.section a53,"dr"
# COFF section 53: .text$mn
begin_53:
symbol_108:  # .text$mn
symbol_153:  # LoadACMUserDLL
    jmp R04_REL32_S168_Load_ACMDynamicLibrary_SAPEAVXosDynamicLibrary_PEBDPEAX_Z # +0x0000
end_53:

.section a55,"dr"
# COFF section 55: .text$mn
begin_55:
symbol_112:  # .text$mn
symbol_150:  # LoadDynamicLibrary
    jmp R04_REL32_S139_Load_XosDynamicLibrary_SAPEAV1_PEBDPEAX_Z # +0x0000
end_55:

.section a57,"dr"
# COFF section 57: .text$mn
begin_57:
symbol_116:  # .text$mn
symbol_160:  # ReleaseFunction
    test rcx, rcx                                   # +0x0000
    je .Lbb_57_0010                                 # +0x0003
    mov rax, qword ptr [rcx]                        # +0x0005
    mov edx, 1                                      # +0x0008
    rex.W jmp qword ptr [rax]                       # +0x000d
.Lbb_57_0010:
    ret                                             # +0x0010
end_57:

.section a59,"dr"
# COFF section 59: .text$mn
begin_59:
symbol_120:  # .text$mn
symbol_154:  # UnloadDynamicLibrary
    test rcx, rcx                                   # +0x0000
    jne R04_REL32_S138_Unload_XosDynamicLibrary_QEAAHXZ # +0x0003
    ret                                             # +0x0009
end_59:

.section a61,"dr"
# COFF section 61: .xdata
begin_61:
symbol_200:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_202:  # $unwind$??_GXosDynamicLibrary@@MEAAPEAXI@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_61:

.section a62,"dr"
# COFF section 62: .pdata
begin_62:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_203:  # .pdata
symbol_205:  # $pdata$??_GXosDynamicLibrary@@MEAAPEAXI@Z
    .rva R03_ADDR32NB_S181_LN8  # begin RVA
    .rva R03_ADDR32NB_S181_LN8 + 52  # end RVA (exclusive)
    .rva R03_ADDR32NB_S202_unwind__GXosDynamicLibrary_MEAAPEAXI_Z  # unwind info RVA
end_62:

.section a63,"dr"
# COFF section 63: .xdata
begin_63:
symbol_206:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_208:  # $unwind$??1XosDynamicFunction@@MEAA@XZ
    .byte 0x19, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
    .rva R03_ADDR32NB_S180_CxxFrameHandler4
    .rva R03_ADDR32NB_S214_cppxdata_1XosDynamicFunction_MEAA_XZ
end_63:

.section a64,"dr"
# COFF section 64: .pdata
begin_64:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_209:  # .pdata
symbol_211:  # $pdata$??1XosDynamicFunction@@MEAA@XZ
    .rva R03_ADDR32NB_S182_LN8  # begin RVA
    .rva R03_ADDR32NB_S182_LN8 + 88  # end RVA (exclusive)
    .rva R03_ADDR32NB_S208_unwind_1XosDynamicFunction_MEAA_XZ  # unwind info RVA
end_64:

.section a65,"dr"
# COFF section 65: .xdata
begin_65:
symbol_212:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_214:  # $cppxdata$??1XosDynamicFunction@@MEAA@XZ
    .byte 0x60
    .rva R03_ADDR32NB_S217_ip2state_1XosDynamicFunction_MEAA_XZ
end_65:

.section a66,"dr"
# COFF section 66: .xdata
begin_66:
symbol_215:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_217:  # $ip2state$??1XosDynamicFunction@@MEAA@XZ
    .byte 0x02, 0x98, 0x00
end_66:

.section a67,"dr"
# COFF section 67: .xdata
begin_67:
symbol_218:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_220:  # $unwind$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x19, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
    .rva R03_ADDR32NB_S180_CxxFrameHandler4
    .rva R03_ADDR32NB_S226_cppxdata__GXosDynamicFunction_MEAAPEAXI_Z
end_67:

.section a68,"dr"
# COFF section 68: .pdata
begin_68:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_221:  # .pdata
symbol_223:  # $pdata$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .rva R03_ADDR32NB_S183_LN13  # begin RVA
    .rva R03_ADDR32NB_S183_LN13 + 121  # end RVA (exclusive)
    .rva R03_ADDR32NB_S220_unwind__GXosDynamicFunction_MEAAPEAXI_Z  # unwind info RVA
end_68:

.section a69,"dr"
# COFF section 69: .xdata
begin_69:
symbol_224:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_226:  # $cppxdata$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x68
    .rva R03_ADDR32NB_S229_stateUnwindMap__GXosDynamicFunction_MEAAPEAXI_Z
    .rva R03_ADDR32NB_S232_ip2state__GXosDynamicFunction_MEAAPEAXI_Z
end_69:

.section a70,"dr"
# COFF section 70: .xdata
begin_70:
symbol_227:  # .xdata
# FH4 state unwind map. Fields that address another section carry an RVA relocation.
symbol_229:  # $stateUnwindMap$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x02, 0x0e
    .rva R03_ADDR32NB_S128_std_terminate
end_70:

.section a71,"dr"
# COFF section 71: .xdata
begin_71:
symbol_230:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_232:  # $ip2state$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x02, 0xa4, 0x02
end_71:

.section a72,"dr"
# COFF section 72: .xdata
begin_72:
symbol_233:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 72
symbol_235:  # $unwind$FindACMFunctionInNamedDLL
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x82, 0x00, 0x00
end_72:

.section a73,"dr"
# COFF section 73: .pdata
begin_73:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_236:  # .pdata
symbol_238:  # $pdata$FindACMFunctionInNamedDLL
    .rva R03_ADDR32NB_S184_LN4  # begin RVA
    .rva R03_ADDR32NB_S184_LN4 + 41  # end RVA (exclusive)
    .rva R03_ADDR32NB_S235_unwind_FindACMFunctionInNamedDLL  # unwind info RVA
end_73:

.section a74,"dr"
# COFF section 74: .xdata
begin_74:
symbol_239:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 72
symbol_241:  # $unwind$FindFunctionInNamedDLL
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x82, 0x00, 0x00
end_74:

.section a75,"dr"
# COFF section 75: .pdata
begin_75:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_242:  # .pdata
symbol_244:  # $pdata$FindFunctionInNamedDLL
    .rva R03_ADDR32NB_S185_LN4  # begin RVA
    .rva R03_ADDR32NB_S185_LN4 + 41  # end RVA (exclusive)
    .rva R03_ADDR32NB_S241_unwind_FindFunctionInNamedDLL  # unwind info RVA
end_75:

.section a76,"dr"
# COFF section 76: .xdata
begin_76:
symbol_245:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 72
symbol_247:  # $unwind$FindFunctionInNamedDLLEx
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x82, 0x00, 0x00
end_76:

.section a77,"dr"
# COFF section 77: .pdata
begin_77:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_248:  # .pdata
symbol_250:  # $pdata$FindFunctionInNamedDLLEx
    .rva R03_ADDR32NB_S186_LN4  # begin RVA
    .rva R03_ADDR32NB_S186_LN4 + 48  # end RVA (exclusive)
    .rva R03_ADDR32NB_S247_unwind_FindFunctionInNamedDLLEx  # unwind info RVA
end_77:

.section a78,"dr"
# COFF section 78: .xdata
begin_78:
symbol_251:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 40
symbol_253:  # $unwind$FindACMFunctionInDLL
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x42, 0x00, 0x00
end_78:

.section a79,"dr"
# COFF section 79: .pdata
begin_79:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_254:  # .pdata
symbol_256:  # $pdata$FindACMFunctionInDLL
    .rva R03_ADDR32NB_S187_LN4  # begin RVA
    .rva R03_ADDR32NB_S187_LN4 + 50  # end RVA (exclusive)
    .rva R03_ADDR32NB_S253_unwind_FindACMFunctionInDLL  # unwind info RVA
end_79:

.section a80,"dr"
# COFF section 80: .xdata
begin_80:
symbol_257:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 40
symbol_259:  # $unwind$FindFunctionInDLL
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x42, 0x00, 0x00
end_80:

.section a81,"dr"
# COFF section 81: .pdata
begin_81:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_260:  # .pdata
symbol_262:  # $pdata$FindFunctionInDLL
    .rva R03_ADDR32NB_S188_LN4  # begin RVA
    .rva R03_ADDR32NB_S188_LN4 + 46  # end RVA (exclusive)
    .rva R03_ADDR32NB_S259_unwind_FindFunctionInDLL  # unwind info RVA
end_81:

.section a82,"dr"
# COFF section 82: .xdata
begin_82:
symbol_263:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_265:  # $unwind$GetACMFunctionAddress
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_82:

.section a83,"dr"
# COFF section 83: .pdata
begin_83:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_266:  # .pdata
symbol_268:  # $pdata$GetACMFunctionAddress
    .rva R03_ADDR32NB_S189_LN10  # begin RVA
    .rva R03_ADDR32NB_S189_LN10 + 48  # end RVA (exclusive)
    .rva R03_ADDR32NB_S265_unwind_GetACMFunctionAddress  # unwind info RVA
end_83:

.section a84,"dr"
# COFF section 84: .xdata
begin_84:
symbol_269:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_271:  # $unwind$GetACM13FunctionAddress
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_84:

.section a85,"dr"
# COFF section 85: .pdata
begin_85:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_272:  # .pdata
symbol_274:  # $pdata$GetACM13FunctionAddress
    .rva R03_ADDR32NB_S190_LN10  # begin RVA
    .rva R03_ADDR32NB_S190_LN10 + 48  # end RVA (exclusive)
    .rva R03_ADDR32NB_S271_unwind_GetACM13FunctionAddress  # unwind info RVA
end_85:

.section a86,"dr"
# COFF section 86: .xdata
begin_86:
symbol_275:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_277:  # $unwind$GetFunctionAddress
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_86:

.section a87,"dr"
# COFF section 87: .pdata
begin_87:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_278:  # .pdata
symbol_280:  # $pdata$GetFunctionAddress
    .rva R03_ADDR32NB_S191_LN9  # begin RVA
    .rva R03_ADDR32NB_S191_LN9 + 34  # end RVA (exclusive)
    .rva R03_ADDR32NB_S277_unwind_GetFunctionAddress  # unwind info RVA
end_87:

.section a88,"dr"
# COFF section 88: .xdata
begin_88:
symbol_281:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_283:  # $unwind$GetFunctionsDLLFileName
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x07, 0x00
    .byte 0x0f, 0x34, 0x06, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_88:

.section a89,"dr"
# COFF section 89: .pdata
begin_89:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_284:  # .pdata
symbol_286:  # $pdata$GetFunctionsDLLFileName
    .rva R03_ADDR32NB_S192_LN11  # begin RVA
    .rva R03_ADDR32NB_S192_LN11 + 101  # end RVA (exclusive)
    .rva R03_ADDR32NB_S283_unwind_GetFunctionsDLLFileName  # unwind info RVA
end_89:

.section a90,"dr"
# COFF section 90: .xdata
begin_90:
symbol_287:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_289:  # $unwind$GetDLLFileName
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x07, 0x00
    .byte 0x0f, 0x34, 0x06, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_90:

.section a91,"dr"
# COFF section 91: .pdata
begin_91:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_290:  # .pdata
symbol_292:  # $pdata$GetDLLFileName
    .rva R03_ADDR32NB_S193_LN9  # begin RVA
    .rva R03_ADDR32NB_S193_LN9 + 97  # end RVA (exclusive)
    .rva R03_ADDR32NB_S289_unwind_GetDLLFileName  # unwind info RVA
end_91:

.section a92,"dr"
# COFF section 92: .xdata
begin_92:
symbol_293:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_295:  # $unwind$?Initialize@ACMDynamicLibrary@@MEAAHPEAX@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_92:

.section a93,"dr"
# COFF section 93: .pdata
begin_93:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_296:  # .pdata
symbol_298:  # $pdata$?Initialize@ACMDynamicLibrary@@MEAAHPEAX@Z
    .rva R03_ADDR32NB_S194_LN19  # begin RVA
    .rva R03_ADDR32NB_S194_LN19 + 149  # end RVA (exclusive)
    .rva R03_ADDR32NB_S295_unwind_Initialize_ACMDynamicLibrary_MEAAHPEAX_Z  # unwind info RVA
end_93:

.section a94,"dr"
# COFF section 94: .xdata
begin_94:
symbol_299:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x40
#   prologue +0x0a: ALLOC_SMALL 48
#   prologue +0x06: PUSH_NONVOL RDI
symbol_301:  # $unwind$?Load@ACMDynamicLibrary@@SAPEAVXosDynamicLibrary@@PEBDPEAX@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x08, 0x00
    .byte 0x0a, 0x52, 0x06, 0x70
end_94:

.section a95,"dr"
# COFF section 95: .pdata
begin_95:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_302:  # .pdata
symbol_304:  # $pdata$?Load@ACMDynamicLibrary@@SAPEAVXosDynamicLibrary@@PEBDPEAX@Z
    .rva R03_ADDR32NB_S195_LN18  # begin RVA
    .rva R03_ADDR32NB_S195_LN18 + 212  # end RVA (exclusive)
    .rva R03_ADDR32NB_S301_unwind_Load_ACMDynamicLibrary_SAPEAVXosDynamicLibrary_PEBDPEAX_Z  # unwind info RVA
end_95:

.section a96,"dr"
# COFF section 96: .xdata
begin_96:
symbol_305:  # .xdata
# UNWIND_INFO v1, flags=2, prologue length=22, unwind slots=10, frame register=0, scaled frame offset=0.
#   prologue +0x16: SAVE_NONVOL RBP, rsp+0x68
#   prologue +0x16: SAVE_NONVOL RBX, rsp+0x60
#   prologue +0x16: ALLOC_SMALL 48
#   prologue +0x12: PUSH_NONVOL R15
#   prologue +0x10: PUSH_NONVOL R14
#   prologue +0x0e: PUSH_NONVOL R12
#   prologue +0x0c: PUSH_NONVOL RDI
#   prologue +0x0b: PUSH_NONVOL RSI
symbol_307:  # $unwind$?FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x11, 0x16, 0x0a, 0x00
    .byte 0x16, 0x54, 0x0d, 0x00
    .byte 0x16, 0x34, 0x0c, 0x00
    .byte 0x16, 0x52, 0x12, 0xf0
    .byte 0x10, 0xe0, 0x0e, 0xc0
    .byte 0x0c, 0x70, 0x0b, 0x60
    .rva R03_ADDR32NB_S180_CxxFrameHandler4
    .rva R03_ADDR32NB_S313_cppxdata_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_96:

.section a97,"dr"
# COFF section 97: .pdata
begin_97:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_308:  # .pdata
symbol_310:  # $pdata$?FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .rva R03_ADDR32NB_S196_LN24  # begin RVA
    .rva R03_ADDR32NB_S196_LN24 + 312  # end RVA (exclusive)
    .rva R03_ADDR32NB_S307_unwind_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z  # unwind info RVA
end_97:

.section a98,"dr"
# COFF section 98: .xdata
begin_98:
symbol_311:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_313:  # $cppxdata$?FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x28
    .rva R03_ADDR32NB_S316_stateUnwindMap_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
    .rva R03_ADDR32NB_S319_ip2state_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_98:

.section a99,"dr"
# COFF section 99: .xdata
begin_99:
symbol_314:  # .xdata
# FH4 state unwind map. Fields that address another section carry an RVA relocation.
symbol_316:  # $stateUnwindMap$?FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x02, 0x0e
    .rva R03_ADDR32NB_S179_dtor_0_0_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA
end_99:

.section a100,"dr"
# COFF section 100: .xdata
begin_100:
symbol_317:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_319:  # $ip2state$?FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x06, 0x94, 0x00, 0x98
    .byte 0x02, 0xea, 0x00
end_100:

.section a101,"dr"
# COFF section 101: .xdata
begin_101:
symbol_320:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBP
symbol_322:  # $unwind$?dtor$0@?0??FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z@4HA
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x50
end_101:

.section a102,"dr"
# COFF section 102: .pdata
begin_102:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_323:  # .pdata
symbol_325:  # $pdata$?dtor$0@?0??FindSymbol@ACMDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z@4HA
    .rva R03_ADDR32NB_S179_dtor_0_0_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA  # begin RVA
    .rva R03_ADDR32NB_S179_dtor_0_0_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA + 29  # end RVA (exclusive)
    .rva R03_ADDR32NB_S322_unwind_dtor_0_0_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA  # unwind info RVA
end_102:

.section a103,"dr"
# COFF section 103: .xdata
begin_103:
symbol_326:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_328:  # $unwind$??_GACMDynamicLibrary@@MEAAPEAXI@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_103:

.section a104,"dr"
# COFF section 104: .pdata
begin_104:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_329:  # .pdata
symbol_331:  # $pdata$??_GACMDynamicLibrary@@MEAAPEAXI@Z
    .rva R03_ADDR32NB_S197_LN11  # begin RVA
    .rva R03_ADDR32NB_S197_LN11 + 62  # end RVA (exclusive)
    .rva R03_ADDR32NB_S328_unwind__GACMDynamicLibrary_MEAAPEAXI_Z  # unwind info RVA
end_104:

.section a105,"dr"
# COFF section 105: .xdata
begin_105:
symbol_332:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_334:  # $unwind$?Find@ACMDynamicFunction@@SAHPEAD0PEAPEAV1@PEAXPEBD@Z
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x07, 0x00
    .byte 0x0f, 0x34, 0x06, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_105:

.section a106,"dr"
# COFF section 106: .pdata
begin_106:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_335:  # .pdata
symbol_337:  # $pdata$?Find@ACMDynamicFunction@@SAHPEAD0PEAPEAV1@PEAXPEBD@Z
    .rva R03_ADDR32NB_S198_LN7  # begin RVA
    .rva R03_ADDR32NB_S198_LN7 + 120  # end RVA (exclusive)
    .rva R03_ADDR32NB_S334_unwind_Find_ACMDynamicFunction_SAHPEAD0PEAPEAV1_PEAXPEBD_Z  # unwind info RVA
end_106:

.section a107,"dr"
# COFF section 107: .xdata
begin_107:
symbol_338:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_340:  # $unwind$??_GACMDynamicFunction@@MEAAPEAXI@Z
    .byte 0x19, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
    .rva R03_ADDR32NB_S180_CxxFrameHandler4
    .rva R03_ADDR32NB_S346_cppxdata__GACMDynamicFunction_MEAAPEAXI_Z
end_107:

.section a108,"dr"
# COFF section 108: .pdata
begin_108:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_341:  # .pdata
symbol_343:  # $pdata$??_GACMDynamicFunction@@MEAAPEAXI@Z
    .rva R03_ADDR32NB_S199_LN16  # begin RVA
    .rva R03_ADDR32NB_S199_LN16 + 121  # end RVA (exclusive)
    .rva R03_ADDR32NB_S340_unwind__GACMDynamicFunction_MEAAPEAXI_Z  # unwind info RVA
end_108:

.section a109,"dr"
# COFF section 109: .xdata
begin_109:
symbol_344:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_346:  # $cppxdata$??_GACMDynamicFunction@@MEAAPEAXI@Z
    .byte 0x68
    .rva R03_ADDR32NB_S349_stateUnwindMap__GACMDynamicFunction_MEAAPEAXI_Z
    .rva R03_ADDR32NB_S352_ip2state__GACMDynamicFunction_MEAAPEAXI_Z
end_109:

.section a110,"dr"
# COFF section 110: .xdata
begin_110:
symbol_347:  # .xdata
# FH4 state unwind map. Fields that address another section carry an RVA relocation.
symbol_349:  # $stateUnwindMap$??_GACMDynamicFunction@@MEAAPEAXI@Z
    .byte 0x02, 0x0e
    .rva R03_ADDR32NB_S128_std_terminate
end_110:

.section a111,"dr"
# COFF section 111: .xdata
begin_111:
symbol_350:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_352:  # $ip2state$??_GACMDynamicFunction@@MEAAPEAXI@Z
    .byte 0x02, 0xa4, 0x02
end_111:

.section a112,"dr"
# COFF section 112: .rdata
begin_112:
symbol_356:  # .rdata
    .quad R01_ADDR64_S394_R4XosDynamicLibrary_6B
symbol_358:  # ??_7XosDynamicLibrary@@6B@
    .quad R01_ADDR64_S143_EXosDynamicLibrary_MEAAPEAXI_Z
    .quad R01_ADDR64_S135_Initialize_XosDynamicLibrary_UEAAHPEAX_Z
    .quad R01_ADDR64_S140_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_112:

.section a113,"dr"
# COFF section 113: .rdata
begin_113:
symbol_359:  # .rdata
    .quad R01_ADDR64_S379_R4XosDynamicFunction_6B
symbol_361:  # ??_7XosDynamicFunction@@6B@
    .quad R01_ADDR64_S148_EXosDynamicFunction_MEAAPEAXI_Z
end_113:

.section a114,"dr"
# COFF section 114: .rdata
begin_114:
symbol_362:  # .rdata
    .quad R01_ADDR64_S409_R4ACMDynamicLibrary_6B
symbol_364:  # ??_7ACMDynamicLibrary@@6B@
    .quad R01_ADDR64_S171_EACMDynamicLibrary_MEAAPEAXI_Z
    .quad R01_ADDR64_S167_Initialize_ACMDynamicLibrary_MEAAHPEAX_Z
    .quad R01_ADDR64_S169_FindSymbol_ACMDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_114:

.section a115,"dr"
# COFF section 115: .rdata
begin_115:
symbol_365:  # .rdata
    .quad R01_ADDR64_S424_R4ACMDynamicFunction_6B
symbol_367:  # ??_7ACMDynamicFunction@@6B@
    .quad R01_ADDR64_S177_EACMDynamicFunction_MEAAPEAXI_Z
end_115:

.section a116,"dr"
# COFF section 116: .rdata
begin_116:
symbol_368:  # .rdata
symbol_370:  # ??_C@_0BC@EFJNDBE@SputUtilitiesInit@
    .ascii "SputUtilitiesInit\000"
end_116:

.section a117,"dr"
# COFF section 117: .rdata
begin_117:
symbol_371:  # .rdata
symbol_373:  # ??_C@_0O@EDGNKEMM@atdll_support@
    .ascii "atdll_support\000"
end_117:

.section a118,"dr"
# COFF section 118: .rdata
begin_118:
symbol_374:  # .rdata
symbol_376:  # ??_C@_0P@FBHPFKIC@DIDIIIIIDIDIII@
    .ascii "DIDIIIIIDIDIII\000"
end_118:

.section a119,"dr"
# COFF section 119: .rdata$r
begin_119:
symbol_377:  # .rdata$r
symbol_379:  # ??_R4XosDynamicFunction@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S382_R0_AVXosDynamicFunction_8
    .rva R03_ADDR32NB_S385_R3XosDynamicFunction_8
    .rva R03_ADDR32NB_S379_R4XosDynamicFunction_6B
    .zero 12
end_119:

.section a120,"dr"
# COFF section 120: .data$rs
begin_120:
symbol_380:  # .data$rs
symbol_382:  # ??_R0?AVXosDynamicFunction@@@8
    .quad R01_ADDR64_S353_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "XosDynamicFunction@@\000"
end_120:

.section a121,"dr"
# COFF section 121: .rdata$r
begin_121:
symbol_383:  # .rdata$r
symbol_385:  # ??_R3XosDynamicFunction@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S388_R2XosDynamicFunction_8
    .zero 4
end_121:

.section a122,"dr"
# COFF section 122: .rdata$r
begin_122:
symbol_386:  # .rdata$r
symbol_388:  # ??_R2XosDynamicFunction@@8
    .rva R03_ADDR32NB_S391_R1A_0A_EA_XosDynamicFunction_8
    .zero 8
end_122:

.section a123,"dr"
# COFF section 123: .rdata$r
begin_123:
symbol_389:  # .rdata$r
symbol_391:  # ??_R1A@?0A@EA@XosDynamicFunction@@8
    .rva R03_ADDR32NB_S382_R0_AVXosDynamicFunction_8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S385_R3XosDynamicFunction_8
    .zero 8
end_123:

.section a124,"dr"
# COFF section 124: .rdata$r
begin_124:
symbol_392:  # .rdata$r
symbol_394:  # ??_R4XosDynamicLibrary@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S397_R0_AVXosDynamicLibrary_8
    .rva R03_ADDR32NB_S400_R3XosDynamicLibrary_8
    .rva R03_ADDR32NB_S394_R4XosDynamicLibrary_6B
    .zero 12
end_124:

.section a125,"dr"
# COFF section 125: .data$rs
begin_125:
symbol_395:  # .data$rs
symbol_397:  # ??_R0?AVXosDynamicLibrary@@@8
    .quad R01_ADDR64_S353_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "XosDynamicLibrary@@\000"
end_125:

.section a126,"dr"
# COFF section 126: .rdata$r
begin_126:
symbol_398:  # .rdata$r
symbol_400:  # ??_R3XosDynamicLibrary@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S403_R2XosDynamicLibrary_8
    .zero 4
end_126:

.section a127,"dr"
# COFF section 127: .rdata$r
begin_127:
symbol_401:  # .rdata$r
symbol_403:  # ??_R2XosDynamicLibrary@@8
    .rva R03_ADDR32NB_S406_R1A_0A_EA_XosDynamicLibrary_8
    .zero 8
end_127:

.section a128,"dr"
# COFF section 128: .rdata$r
begin_128:
symbol_404:  # .rdata$r
symbol_406:  # ??_R1A@?0A@EA@XosDynamicLibrary@@8
    .rva R03_ADDR32NB_S397_R0_AVXosDynamicLibrary_8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S400_R3XosDynamicLibrary_8
    .zero 8
end_128:

.section a129,"dr"
# COFF section 129: .rdata$r
begin_129:
symbol_407:  # .rdata$r
symbol_409:  # ??_R4ACMDynamicLibrary@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S412_R0_AVACMDynamicLibrary_8
    .rva R03_ADDR32NB_S415_R3ACMDynamicLibrary_8
    .rva R03_ADDR32NB_S409_R4ACMDynamicLibrary_6B
    .zero 12
end_129:

.section a130,"dr"
# COFF section 130: .data$rs
begin_130:
symbol_410:  # .data$rs
symbol_412:  # ??_R0?AVACMDynamicLibrary@@@8
    .quad R01_ADDR64_S353_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "ACMDynamicLibrary@@\000"
end_130:

.section a131,"dr"
# COFF section 131: .rdata$r
begin_131:
symbol_413:  # .rdata$r
symbol_415:  # ??_R3ACMDynamicLibrary@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S418_R2ACMDynamicLibrary_8
    .zero 4
end_131:

.section a132,"dr"
# COFF section 132: .rdata$r
begin_132:
symbol_416:  # .rdata$r
symbol_418:  # ??_R2ACMDynamicLibrary@@8
    .rva R03_ADDR32NB_S421_R1A_0A_EA_ACMDynamicLibrary_8
    .rva R03_ADDR32NB_S406_R1A_0A_EA_XosDynamicLibrary_8
    .zero 12
end_132:

.section a133,"dr"
# COFF section 133: .rdata$r
begin_133:
symbol_419:  # .rdata$r
symbol_421:  # ??_R1A@?0A@EA@ACMDynamicLibrary@@8
    .rva R03_ADDR32NB_S412_R0_AVACMDynamicLibrary_8
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S415_R3ACMDynamicLibrary_8
    .zero 8
end_133:

.section a134,"dr"
# COFF section 134: .rdata$r
begin_134:
symbol_422:  # .rdata$r
symbol_424:  # ??_R4ACMDynamicFunction@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S427_R0_AVACMDynamicFunction_8
    .rva R03_ADDR32NB_S430_R3ACMDynamicFunction_8
    .rva R03_ADDR32NB_S424_R4ACMDynamicFunction_6B
    .zero 12
end_134:

.section a135,"dr"
# COFF section 135: .data$rs
begin_135:
symbol_425:  # .data$rs
symbol_427:  # ??_R0?AVACMDynamicFunction@@@8
    .quad R01_ADDR64_S353_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "ACMDynamicFunction@@\000"
end_135:

.section a136,"dr"
# COFF section 136: .rdata$r
begin_136:
symbol_428:  # .rdata$r
symbol_430:  # ??_R3ACMDynamicFunction@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S433_R2ACMDynamicFunction_8
    .zero 4
end_136:

.section a137,"dr"
# COFF section 137: .rdata$r
begin_137:
symbol_431:  # .rdata$r
symbol_433:  # ??_R2ACMDynamicFunction@@8
    .rva R03_ADDR32NB_S436_R1A_0A_EA_ACMDynamicFunction_8
    .rva R03_ADDR32NB_S391_R1A_0A_EA_XosDynamicFunction_8
    .zero 12
end_137:

.section a138,"dr"
# COFF section 138: .rdata$r
begin_138:
symbol_434:  # .rdata$r
symbol_436:  # ??_R1A@?0A@EA@ACMDynamicFunction@@8
    .rva R03_ADDR32NB_S427_R0_AVACMDynamicFunction_8
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S430_R3ACMDynamicFunction_8
    .zero 8
end_138:
