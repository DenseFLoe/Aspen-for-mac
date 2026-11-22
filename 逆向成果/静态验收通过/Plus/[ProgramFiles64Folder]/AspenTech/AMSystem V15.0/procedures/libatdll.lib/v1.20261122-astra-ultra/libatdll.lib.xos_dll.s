# AMD64 COFF member .\Release\xos_dll.obj
# External reference identifiers encode the original relocation type, COFF symbol index and name.
.intel_syntax noprefix

.section a1,"dr"
# COFF section 1: .drectve
begin_1:
symbol_3:  # .drectve
    .ascii "   /FAILIFMISMATCH:\"_CRT_STDIO_ISO_WIDE_SPECIFIERS=0\" /DEFAULTLIB:\"uuid.lib\" /DEFAULTLIB:\"uuid.lib\" /FAILIFMISMATCH:\"_MSC_VER=1900\" /FAILIFMISMATCH:\"_ITERATOR_DEBUG_LEVEL=0\" /FAILIFMISMATCH:\"RuntimeLibrary=MD_DynamicRelease\" /DEFAULTLIB:\"msvcprt\" /FAILIFMISMATCH:\"annotate_string=0\" /FAILIFMISMATCH:\"annotate_vector=0\" /DEFAULTLIB:\"MSVCRT\" /DEFAULTLIB:\"OLDNAMES\" /EXPORT:DLLsLoaded /EXPORT:ForceUnload /EXPORT:AddDLLSearchPath /EXPORT:RemoveDLLSearchPath "
end_1:

.section a4,"dr"
# COFF section 4: .rdata
begin_4:
symbol_15:  # .rdata
symbol_17:  # ?_Fake_alloc@std@@3U_Fake_allocator@1@B
    .byte 0x00
end_4:

.section a5,"dr"
# COFF section 5: .text$mn
begin_5:
symbol_18:  # .text$mn
symbol_179:  # ??1XosDynamicFunction@@MEAA@XZ
symbol_215:  # $LN8
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbx, rcx                             # +0x0006
    lea rax, [rip + R04_REL32_S594_7XosDynamicFunction_6B] # +0x0009
    mov qword ptr [rcx], rax                        # +0x0010
    mov rax, qword ptr [rcx + 8]                    # +0x0013
    mov rcx, qword ptr [rcx + 0x10]                 # +0x0017
    test rax, rax                                   # +0x001b
    je .Lbb_5_0026                                  # +0x001e
    mov qword ptr [rax + 0x10], rcx                 # +0x0020
    jmp .Lbb_5_002e                                 # +0x0024
.Lbb_5_0026:
    mov rax, qword ptr [rbx + 0x18]                 # +0x0026
    mov qword ptr [rax + 0x20], rcx                 # +0x002a
.Lbb_5_002e:
    mov rcx, qword ptr [rbx + 0x10]                 # +0x002e
    test rcx, rcx                                   # +0x0032
    je .Lbb_5_003f                                  # +0x0035
    mov rax, qword ptr [rbx + 8]                    # +0x0037
    mov qword ptr [rcx + 8], rax                    # +0x003b
.Lbb_5_003f:
    mov rcx, qword ptr [rbx + 0x20]                 # +0x003f
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0043
    mov rcx, qword ptr [rbx + 0x18]                 # +0x0048
    call R04_REL32_S172_Unload_XosDynamicLibrary_QEAAHXZ # +0x004c
    nop                                             # +0x0051
    add rsp, 0x20                                   # +0x0052
    pop rbx                                         # +0x0056
    ret                                             # +0x0057
end_5:

.section a7,"dr"
# COFF section 7: .text$mn
begin_7:
symbol_22:  # .text$mn
symbol_158:  # ??1XosDynamicLibrary@@MEAA@XZ
symbol_196:  # $LN17
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    lea rax, [rip + R04_REL32_S591_7XosDynamicLibrary_6B] # +0x0006
    {load} mov rbx, rcx                             # +0x000d
    mov qword ptr [rcx], rax                        # +0x0010
    mov rcx, qword ptr [rcx + 0x28]                 # +0x0013
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0017
    mov rcx, qword ptr [rbx + 0x10]                 # +0x001c
    mov rax, qword ptr [rbx + 0x18]                 # +0x0020
    test rcx, rcx                                   # +0x0024
    je .Lbb_7_002f                                  # +0x0027
    mov qword ptr [rcx + 0x18], rax                 # +0x0029
    jmp .Lbb_7_0036                                 # +0x002d
.Lbb_7_002f:
    mov qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA], rax # +0x002f
.Lbb_7_0036:
    mov rcx, qword ptr [rbx + 0x18]                 # +0x0036
    test rcx, rcx                                   # +0x003a
    je .Lbb_7_0047                                  # +0x003d
    mov rax, qword ptr [rbx + 0x10]                 # +0x003f
    mov qword ptr [rcx + 0x10], rax                 # +0x0043
.Lbb_7_0047:
    mov rax, qword ptr [rbx + 0x20]                 # +0x0047
    test rax, rax                                   # +0x004b
    je .Lbb_7_007d                                  # +0x004e
    {load} xor ecx, ecx                             # +0x0050
    {disp8} nop dword ptr [rax]                     # +0x0052
    .byte 0x66  # additional operand-size prefix    # +0x0056
    {disp32} nop word ptr [rax + rax]
.Lbb_7_0060:
    mov qword ptr [rax + 0x18], rcx                 # +0x0060
    mov rax, qword ptr [rbx + 0x20]                 # +0x0064
    mov qword ptr [rax + 0x28], rcx                 # +0x0068
    mov rax, qword ptr [rbx + 0x20]                 # +0x006c
    mov rax, qword ptr [rax + 0x10]                 # +0x0070
    mov qword ptr [rbx + 0x20], rax                 # +0x0074
    test rax, rax                                   # +0x0078
    jne .Lbb_7_0060                                 # +0x007b
.Lbb_7_007d:
    add rsp, 0x20                                   # +0x007d
    pop rbx                                         # +0x0081
    ret                                             # +0x0082
end_7:

.section a9,"dr"
# COFF section 9: .text$mn
begin_9:
symbol_26:  # .text$mn
symbol_181:  # ??_GXosDynamicFunction@@MEAAPEAXI@Z
symbol_217:  # $LN13
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov edi, edx                             # +0x000a
    {load} mov rbx, rcx                             # +0x000c
    lea rax, [rip + R04_REL32_S594_7XosDynamicFunction_6B] # +0x000f
    mov qword ptr [rcx], rax                        # +0x0016
    mov rax, qword ptr [rcx + 8]                    # +0x0019
    mov rcx, qword ptr [rcx + 0x10]                 # +0x001d
    test rax, rax                                   # +0x0021
    je .Lbb_9_002c                                  # +0x0024
    mov qword ptr [rax + 0x10], rcx                 # +0x0026
    jmp .Lbb_9_0034                                 # +0x002a
.Lbb_9_002c:
    mov rax, qword ptr [rbx + 0x18]                 # +0x002c
    mov qword ptr [rax + 0x20], rcx                 # +0x0030
.Lbb_9_0034:
    mov rcx, qword ptr [rbx + 0x10]                 # +0x0034
    test rcx, rcx                                   # +0x0038
    je .Lbb_9_0045                                  # +0x003b
    mov rax, qword ptr [rbx + 8]                    # +0x003d
    mov qword ptr [rcx + 8], rax                    # +0x0041
.Lbb_9_0045:
    mov rcx, qword ptr [rbx + 0x20]                 # +0x0045
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0049
    mov rcx, qword ptr [rbx + 0x18]                 # +0x004e
    call R04_REL32_S172_Unload_XosDynamicLibrary_QEAAHXZ # +0x0052
    nop                                             # +0x0057
    test dil, 1                                     # +0x0058
    je .Lbb_9_006b                                  # +0x005c
    mov edx, 0x30                                   # +0x005e
    {load} mov rcx, rbx                             # +0x0063
    call R04_REL32_S137_3_YAXPEAX_K_Z               # +0x0066
.Lbb_9_006b:
    {load} mov rax, rbx                             # +0x006b
    mov rbx, qword ptr [rsp + 0x30]                 # +0x006e
    add rsp, 0x20                                   # +0x0073
    pop rdi                                         # +0x0077
    ret                                             # +0x0078
end_9:

.section a11,"dr"
# COFF section 11: .text$mn
begin_11:
symbol_30:  # .text$mn
symbol_176:  # ??_GXosDynamicLibrary@@MEAAPEAXI@Z
symbol_214:  # $LN8
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov ebx, edx                             # +0x000a
    {load} mov rdi, rcx                             # +0x000c
    call R04_REL32_S158_1XosDynamicLibrary_MEAA_XZ  # +0x000f
    test bl, 1                                      # +0x0014
    je .Lbb_11_0026                                 # +0x0017
    mov edx, 0x60                                   # +0x0019
    {load} mov rcx, rdi                             # +0x001e
    call R04_REL32_S137_3_YAXPEAX_K_Z               # +0x0021
.Lbb_11_0026:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0026
    {load} mov rax, rdi                             # +0x002b
    add rsp, 0x20                                   # +0x002e
    pop rdi                                         # +0x0032
    ret                                             # +0x0033
end_11:

.section a13,"dr"
# COFF section 13: .text$mn
begin_13:
symbol_34:  # .text$mn
symbol_165:  # ?AddDLLSearchPath@XosDynamicLibrary@@SA_NPEAD@Z
symbol_203:  # $LN51
    mov qword ptr [rsp + 0x18], rbx                 # +0x0000
    push rbp                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    mov rbx, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x000a
    {load} mov rbp, rcx                             # +0x0011
    test rbx, rbx                                   # +0x0014
    je .Lbb_13_0048                                 # +0x0017
    {disp32} nop dword ptr [rax]                    # +0x0019
.Lbb_13_0020:
    {load} xor r9d, r9d                             # +0x0020
    lea rdx, [rip + R04_REL32_S618_C__0BB_OLNKDJGE_AddDLLSearchPath] # +0x0023
    {load} xor r8d, r8d                             # +0x002a
    {load} mov rcx, rbx                             # +0x002d
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x0030
    test rax, rax                                   # +0x0035
    je .Lbb_13_003f                                 # +0x0038
    {load} mov rcx, rbp                             # +0x003a
    call rax                                        # +0x003d
.Lbb_13_003f:
    mov rbx, qword ptr [rbx + 0x18]                 # +0x003f
    test rbx, rbx                                   # +0x0043
    jne .Lbb_13_0020                                # +0x0046
.Lbb_13_0048:
    mov rdx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0048
    mov eax, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x004f
    mov qword ptr [rsp + 0x30], rsi                 # +0x0055
    mov qword ptr [rsp + 0x38], rdi                 # +0x005a
    test rdx, rdx                                   # +0x005f
    {disp32} je .Lbb_13_0101                        # +0x0062
    {load} xor ebx, ebx                             # +0x0068
    test eax, eax                                   # +0x006a
    {disp32} jle .Lbb_13_0101                       # +0x006c
    {load} mov esi, ebx                             # +0x0072
    {disp8} nop dword ptr [rax]                     # +0x0074
    {disp32} nop dword ptr [rax + rax]              # +0x0078
.Lbb_13_0080:
    lea rdi, [rsi*8]                                # +0x0080
    {load} mov rcx, rbp                             # +0x0088
    mov rdx, qword ptr [rdi + rdx]                  # +0x008b
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x008f
    test eax, eax                                   # +0x0095
    je .Lbb_13_00b1                                 # +0x0097
    mov eax, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x0099
    inc ebx                                         # +0x009f
    inc rsi                                         # +0x00a1
    {load} cmp ebx, eax                             # +0x00a4
    jge .Lbb_13_0101                                # +0x00a6
    mov rdx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x00a8
    jmp .Lbb_13_0080                                # +0x00af
.Lbb_13_00b1:
    mov rdx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x00b1
    mov ecx, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x00b8
    movsxd rax, ebx                                 # +0x00be
    mov r8, qword ptr [rdx + rax*8]                 # +0x00c1
    lea eax, [rcx - 1]                              # +0x00c5
    {load} cmp ebx, eax                             # +0x00c8
    jge .Lbb_13_00f3                                # +0x00ca
    {disp8} nop dword ptr [rax]                     # +0x00cc
.Lbb_13_00d0:
    mov rax, qword ptr [rdi + rdx + 8]              # +0x00d0
    inc ebx                                         # +0x00d5
    mov qword ptr [rdi + rdx], rax                  # +0x00d7
    lea rdi, [rdi + 8]                              # +0x00db
    mov ecx, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x00df
    mov rdx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x00e5
    lea eax, [rcx - 1]                              # +0x00ec
    {load} cmp ebx, eax                             # +0x00ef
    jl .Lbb_13_00d0                                 # +0x00f1
.Lbb_13_00f3:
    lea eax, [rcx - 1]                              # +0x00f3
    movsxd rcx, eax                                 # +0x00f6
    {load} xor al, al                               # +0x00f9
    mov qword ptr [rdx + rcx*8], r8                 # +0x00fb
    jmp .Lbb_13_0171                                # +0x00ff
.Lbb_13_0101:
    mov ecx, dword ptr [rip + R04_REL32_S13_m_iMaxSearchPaths_XosDynamicLibrary_0HA] # +0x0101
    {load} cmp eax, ecx                             # +0x0107
    jne .Lbb_13_0113                                # +0x0109
    add ecx, 4                                      # +0x010b
    call R04_REL32_S162_ExtendSearchPaths_XosDynamicLibrary_KAXH_Z # +0x010e
.Lbb_13_0113:
    mov rbx, 0xffffffffffffffff                     # +0x0113
    {disp8} nop word ptr [rax + rax]                # +0x011a
.Lbb_13_0120:
    cmp byte ptr [rbx + rbp + 1], 0                 # +0x0120
    lea rbx, [rbx + 1]                              # +0x0125
    jne .Lbb_13_0120                                # +0x0129
    lea rcx, [rbx + 1]                              # +0x012b
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x012f
    movsxd r8, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x0134
    lea rdx, [rbx + 1]                              # +0x013b
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x013f
    mov qword ptr [rcx + r8*8], rax                 # +0x0146
    movsxd r8, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x014a
    mov rax, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0151
    mov rcx, qword ptr [rax + r8*8]                 # +0x0158
    inc r8d                                         # +0x015c
    mov dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA], r8d # +0x015f
    {load} mov r8, rbp                              # +0x0166
    call qword ptr [rip + R04_REL32_S144_imp_strcpy_s] # +0x0169
    mov al, 1                                       # +0x016f
.Lbb_13_0171:
    mov rdi, qword ptr [rsp + 0x38]                 # +0x0171
    mov rsi, qword ptr [rsp + 0x30]                 # +0x0176
    mov rbx, qword ptr [rsp + 0x40]                 # +0x017b
    add rsp, 0x20                                   # +0x0180
    pop rbp                                         # +0x0184
    ret                                             # +0x0185
end_13:

.section a15,"dr"
# COFF section 15: .text$mn
begin_15:
symbol_38:  # .text$mn
symbol_162:  # ?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
symbol_200:  # $LN8
    sub rsp, 0x28                                   # +0x0000
    cmp ecx, dword ptr [rip + R04_REL32_S13_m_iMaxSearchPaths_XosDynamicLibrary_0HA] # +0x0004
    jle .Lbb_15_0071                                # +0x000a
    mov dword ptr [rip + R04_REL32_S13_m_iMaxSearchPaths_XosDynamicLibrary_0HA], ecx # +0x000c
    mov eax, 8                                      # +0x0012
    movsxd rcx, ecx                                 # +0x0017
    mul rcx                                         # +0x001a
    mov rcx, 0xffffffffffffffff                     # +0x001d
    mov qword ptr [rsp + 0x20], rbx                 # +0x0024
    cmovo rax, rcx                                  # +0x0029
    {load} mov rcx, rax                             # +0x002d
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x0030
    {load} mov rbx, rax                             # +0x0035
    movsxd rax, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x0038
    test eax, eax                                   # +0x003f
    je .Lbb_15_0065                                 # +0x0041
    mov rdx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0043
    {load} mov r8, rax                              # +0x004a
    shl r8, 3                                       # +0x004d
    {load} mov rcx, rbx                             # +0x0051
    call R04_REL32_S192_memcpy                      # +0x0054
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0059
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0060
.Lbb_15_0065:
    mov qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA], rbx # +0x0065
    mov rbx, qword ptr [rsp + 0x20]                 # +0x006c
.Lbb_15_0071:
    add rsp, 0x28                                   # +0x0071
    ret                                             # +0x0075
end_15:

.section a17,"dr"
# COFF section 17: .text$mn
begin_17:
symbol_42:  # .text$mn
symbol_180:  # ?Find@XosDynamicFunction@@SAHPEAD0PEAPEAV1@PEAXPEBD@Z
symbol_216:  # $LN15
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    {load} mov rax, rdx                             # +0x000f
    {load} mov rsi, rcx                             # +0x0012
    {load} mov rcx, rax                             # +0x0015
    {load} mov rdx, r9                              # +0x0018
    {load} mov rbx, r8                              # +0x001b
    call R04_REL32_S173_Load_XosDynamicLibrary_SAPEAV1_PEBDPEAX_Z # +0x001e
    mov qword ptr [rbx], 0                          # +0x0023
    {load} mov rdi, rax                             # +0x002a
    test rax, rax                                   # +0x002d
    je .Lbb_17_0076                                 # +0x0030
    mov r10, qword ptr [rax]                        # +0x0032
    {load} mov r8, rbx                              # +0x0035
    mov r9, qword ptr [rsp + 0x50]                  # +0x0038
    {load} mov rdx, rsi                             # +0x003d
    {load} mov rcx, rax                             # +0x0040
    call qword ptr [r10 + 0x10]                     # +0x0043
    {load} mov rcx, rdi                             # +0x0047
    {load} mov ebx, eax                             # +0x004a
    call R04_REL32_S172_Unload_XosDynamicLibrary_QEAAHXZ # +0x004c
    {load} mov eax, ebx                             # +0x0051
    test ebx, ebx                                   # +0x0053
    jns .Lbb_17_007c                                # +0x0055
    cmp dword ptr [rip + R05_REL32_1_S11_m_bQuietly_XosDynamicLibrary_0HA], 0 # +0x0057
    jne .Lbb_17_007c                                # +0x005e
    mov dword ptr [rip + R04_REL32_S10_m_iStatus_XosDynamicLibrary_0HA], ebx # +0x0060
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0066
    mov rsi, qword ptr [rsp + 0x38]                 # +0x006b
    add rsp, 0x20                                   # +0x0070
    pop rdi                                         # +0x0074
    ret                                             # +0x0075
.Lbb_17_0076:
    mov eax, dword ptr [rip + R04_REL32_S10_m_iStatus_XosDynamicLibrary_0HA] # +0x0076
.Lbb_17_007c:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x007c
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0081
    add rsp, 0x20                                   # +0x0086
    pop rdi                                         # +0x008a
    ret                                             # +0x008b
end_17:

.section a19,"dr"
# COFF section 19: .text$mn
begin_19:
symbol_46:  # .text$mn
symbol_171:  # ?FindCallAddress@XosDynamicLibrary@@QEAAPEAXPEBD0PEAPEAD@Z
symbol_209:  # $LN34
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    push rdi                                        # +0x000f
    sub rsp, 0x20                                   # +0x0010
    cmp qword ptr [rcx + 0x38], 0                   # +0x0014
    {load} mov rdi, r9                              # +0x0019
    {load} mov rsi, r8                              # +0x001c
    {load} mov rbp, rdx                             # +0x001f
    {load} mov rbx, rcx                             # +0x0022
    jne .Lbb_19_0045                                # +0x0025
    cmp dword ptr [rcx + 0x58], 3                   # +0x0027
    jne .Lbb_19_0045                                # +0x002b
    cmp dword ptr [rip + R05_REL32_1_S11_m_bQuietly_XosDynamicLibrary_0HA], 1 # +0x002d
    jne .Lbb_19_0045                                # +0x0034
    mov rdx, qword ptr [rcx + 0x50]                 # +0x0036
    mov r8d, 3                                      # +0x003a
    call R04_REL32_S160_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z # +0x0040
.Lbb_19_0045:
    test rdi, rdi                                   # +0x0045
    je .Lbb_19_0051                                 # +0x0048
    mov qword ptr [rdi], 0                          # +0x004a
.Lbb_19_0051:
    mov rcx, qword ptr [rbx + 0x38]                 # +0x0051
    test rcx, rcx                                   # +0x0055
    je .Lbb_19_00b9                                 # +0x0058
    test rsi, rsi                                   # +0x005a
    je .Lbb_19_0091                                 # +0x005d
    {load} mov rdx, rsi                             # +0x005f
    {load} mov rcx, rbp                             # +0x0062
    call R04_REL32_S156_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z # +0x0065
    mov rcx, qword ptr [rbx + 0x38]                 # +0x006a
    {load} mov rdx, rax                             # +0x006e
    {load} mov rsi, rax                             # +0x0071
    call qword ptr [rip + R04_REL32_S152_imp_GetProcAddress] # +0x0074
    {load} mov rbx, rax                             # +0x007a
    test rdi, rdi                                   # +0x007d
    je .Lbb_19_0087                                 # +0x0080
    mov qword ptr [rdi], rsi                        # +0x0082
    jmp .Lbb_19_009d                                # +0x0085
.Lbb_19_0087:
    {load} mov rcx, rsi                             # +0x0087
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x008a
    jmp .Lbb_19_009d                                # +0x008f
.Lbb_19_0091:
    {load} mov rdx, rbp                             # +0x0091
    call qword ptr [rip + R04_REL32_S152_imp_GetProcAddress] # +0x0094
    {load} mov rbx, rax                             # +0x009a
.Lbb_19_009d:
    {load} mov rax, rbx                             # +0x009d
    test rbx, rbx                                   # +0x00a0
    jne .Lbb_19_00cd                                # +0x00a3
    cmp dword ptr [rip + R04_REL32_S11_m_bQuietly_XosDynamicLibrary_0HA], ebx # +0x00a5
    jne .Lbb_19_00cd                                # +0x00ab
    mov dword ptr [rip + R08_REL32_4_S10_m_iStatus_XosDynamicLibrary_0HA], 0xa0000033 # +0x00ad
    jmp .Lbb_19_00cd                                # +0x00b7
.Lbb_19_00b9:
    {load} xor eax, eax                             # +0x00b9
    cmp dword ptr [rip + R04_REL32_S11_m_bQuietly_XosDynamicLibrary_0HA], eax # +0x00bb
    jne .Lbb_19_00cd                                # +0x00c1
    mov dword ptr [rip + R08_REL32_4_S10_m_iStatus_XosDynamicLibrary_0HA], 0xa0000034 # +0x00c3
.Lbb_19_00cd:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x00cd
    mov rbp, qword ptr [rsp + 0x38]                 # +0x00d2
    mov rsi, qword ptr [rsp + 0x40]                 # +0x00d7
    add rsp, 0x20                                   # +0x00dc
    pop rdi                                         # +0x00e0
    ret                                             # +0x00e1
end_19:

.section a21,"dr"
# COFF section 21: .text$mn
begin_21:
symbol_50:  # .text$mn
symbol_170:  # ?FindFunction@XosDynamicLibrary@@QEBAPEAVXosDynamicFunction@@PEBD0PEAPEAD@Z
symbol_208:  # $LN10
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    mov qword ptr [r9], 0                           # +0x0006
    {load} mov rbx, r9                              # +0x000d
    {load} mov rax, rdx                             # +0x0010
    test r8, r8                                     # +0x0013
    je .Lbb_21_0026                                 # +0x0016
    {load} mov rdx, r8                              # +0x0018
    {load} mov rcx, rax                             # +0x001b
    call R04_REL32_S156_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z # +0x001e
    mov qword ptr [rbx], rax                        # +0x0023
.Lbb_21_0026:
    {load} xor eax, eax                             # +0x0026
    add rsp, 0x20                                   # +0x0028
    pop rbx                                         # +0x002c
    ret                                             # +0x002d
end_21:

.section a23,"dr"
# COFF section 23: .text$mn
begin_23:
symbol_54:  # .text$mn
symbol_159:  # ?FindLibrary@XosDynamicLibrary@@KAPEAV1@PEBDAEAPEAD1@Z
symbol_197:  # $LN15
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    {load} mov rsi, rdx                             # +0x000f
    {load} mov rdi, r8                              # +0x0012
    {load} mov rdx, r8                              # +0x0015
    call R04_REL32_S155_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z # +0x0018
    mov qword ptr [rsi], rax                        # +0x001d
    mov rbx, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0020
    test rbx, rbx                                   # +0x0027
    je .Lbb_23_0068                                 # +0x002a
    {disp8} nop dword ptr [rax]                     # +0x002c
.Lbb_23_0030:
    mov rdx, qword ptr [rbx + 0x30]                 # +0x0030
    mov rcx, qword ptr [rdi]                        # +0x0034
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x0037
    test eax, eax                                   # +0x003d
    je .Lbb_23_005d                                 # +0x003f
    mov rbx, qword ptr [rbx + 0x18]                 # +0x0041
    test rbx, rbx                                   # +0x0045
    jne .Lbb_23_0030                                # +0x0048
    {load} mov rax, rbx                             # +0x004a
    mov rbx, qword ptr [rsp + 0x30]                 # +0x004d
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0052
    add rsp, 0x20                                   # +0x0057
    pop rdi                                         # +0x005b
    ret                                             # +0x005c
.Lbb_23_005d:
    mov rcx, qword ptr [rsi]                        # +0x005d
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0060
    inc dword ptr [rbx + 0x40]                      # +0x0065
.Lbb_23_0068:
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0068
    {load} mov rax, rbx                             # +0x006d
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0070
    add rsp, 0x20                                   # +0x0075
    pop rdi                                         # +0x0079
    ret                                             # +0x007a
end_23:

.section a25,"dr"
# COFF section 25: .text$mn
begin_25:
symbol_58:  # .text$mn
symbol_174:  # ?FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
symbol_212:  # $LN21
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    push rsi                                        # +0x000a
    push rdi                                        # +0x000b
    push r13                                        # +0x000c
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
    je .Lbb_25_0037                                 # +0x002a
    mov rax, qword ptr [rcx]                        # +0x002c
    lea edx, [rbp + 1]                              # +0x002f
    call qword ptr [rax]                            # +0x0032
    mov qword ptr [r15], rbp                        # +0x0034
.Lbb_25_0037:
    mov qword ptr [rsp + 0x70], rbp                 # +0x0037
    lea r9, [rsp + 0x70]                            # +0x003c
    {load} mov r8, rbx                              # +0x0041
    {load} mov rdx, rsi                             # +0x0044
    {load} mov rcx, r14                             # +0x0047
    call R04_REL32_S170_FindFunction_XosDynamicLibrary_QEBAPEAVXosDynamicFunction_PEBD0PEAPEAD_Z # +0x004a
    mov qword ptr [r15], rax                        # +0x004f
    test rax, rax                                   # +0x0052
    {disp32} jne .Lbb_25_010a                       # +0x0055
    cmp qword ptr [rsp + 0x70], rbp                 # +0x005b
    cmovne rsi, qword ptr [rsp + 0x70]              # +0x0060
    {load} xor r9d, r9d                             # +0x0066
    {load} xor r8d, r8d                             # +0x0069
    {load} mov rdx, rsi                             # +0x006c
    {load} mov rcx, r14                             # +0x006f
    call R04_REL32_S171_FindCallAddress_XosDynamicLibrary_QEAAPEAXPEBD0PEAPEAD_Z # +0x0072
    {load} mov r13, rax                             # +0x0077
    test rax, rax                                   # +0x007a
    {disp32} je .Lbb_25_0105                        # +0x007d
    mov ecx, 0x30                                   # +0x0083
    call R04_REL32_S136_2_YAPEAX_K_Z                # +0x0088
    {load} mov rdi, rax                             # +0x008d
    mov qword ptr [rsp + 0x20], rax                 # +0x0090
    test rax, rax                                   # +0x0095
    je .Lbb_25_00fd                                 # +0x0098
    lea rax, [rip + R04_REL32_S594_7XosDynamicFunction_6B] # +0x009a
    mov qword ptr [rdi], rax                        # +0x00a1
    mov qword ptr [rdi + 0x18], r14                 # +0x00a4
    inc dword ptr [r14 + 0x40]                      # +0x00a8
    mov rbx, 0xffffffffffffffff                     # +0x00ac
.Lbb_25_00b3:
    lea rbx, [rbx + 1]                              # +0x00b3
    cmp byte ptr [rsi + rbx], 0                     # +0x00b7
    jne .Lbb_25_00b3                                # +0x00bb
    lea rcx, [rbx + 1]                              # +0x00bd
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x00c1
    mov qword ptr [rdi + 0x20], rax                 # +0x00c6
    {load} mov r8, rsi                              # +0x00ca
    lea rdx, [rbx + 1]                              # +0x00cd
    {load} mov rcx, rax                             # +0x00d1
    call qword ptr [rip + R04_REL32_S144_imp_strcpy_s] # +0x00d4
    mov qword ptr [rdi + 0x28], r13                 # +0x00da
    mov qword ptr [rdi + 8], rbp                    # +0x00de
    mov rax, qword ptr [r14 + 0x20]                 # +0x00e2
    mov qword ptr [rdi + 0x10], rax                 # +0x00e6
    mov rax, qword ptr [r14 + 0x20]                 # +0x00ea
    test rax, rax                                   # +0x00ee
    je .Lbb_25_00f7                                 # +0x00f1
    mov qword ptr [rax + 8], rdi                    # +0x00f3
.Lbb_25_00f7:
    mov qword ptr [r14 + 0x20], rdi                 # +0x00f7
    jmp .Lbb_25_0100                                # +0x00fb
.Lbb_25_00fd:
    {load} mov rdi, rbp                             # +0x00fd
.Lbb_25_0100:
    mov qword ptr [r15], rdi                        # +0x0100
    jmp .Lbb_25_010a                                # +0x0103
.Lbb_25_0105:
    mov ebp, 0xa0000033                             # +0x0105
.Lbb_25_010a:
    mov rcx, qword ptr [rsp + 0x70]                 # +0x010a
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x010f
    {load} mov eax, ebp                             # +0x0114
    mov rbx, qword ptr [rsp + 0x60]                 # +0x0116
    mov rbp, qword ptr [rsp + 0x68]                 # +0x011b
    add rsp, 0x30                                   # +0x0120
    pop r15                                         # +0x0124
    pop r14                                         # +0x0126
    pop r13                                         # +0x0128
    pop rdi                                         # +0x012a
    pop rsi                                         # +0x012b
    ret                                             # +0x012c
end_25:

.section a27,"dr"
# COFF section 27: .text$x
begin_27:
symbol_62:  # .text$x
# Cleanup funclet: release the 0x30-byte allocation via sized operator delete.
symbol_188:  # ?dtor$0@?0??FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z@4HA
    rex push rbp                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbp, rdx                             # +0x0006
    mov edx, 0x30                                   # +0x0009
    mov rcx, qword ptr [rbp + 0x20]                 # +0x000e
    call R04_REL32_S137_3_YAXPEAX_K_Z               # +0x0012
    add rsp, 0x20                                   # +0x0017
    pop rbp                                         # +0x001b
    ret                                             # +0x001c
end_27:

.section a28,"dr"
# COFF section 28: .text$mn
begin_28:
symbol_64:  # .text$mn
symbol_168:  # ?ForceUnload@XosDynamicLibrary@@QEAAHXZ
symbol_206:  # $LN8
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    mov eax, dword ptr [rcx + 0x48]                 # +0x000a
    {load} xor edi, edi                             # +0x000d
    {load} mov rbx, rcx                             # +0x000f
    cmp qword ptr [rcx + 0x38], rdi                 # +0x0012
    je .Lbb_28_0031                                 # +0x0016
    test eax, eax                                   # +0x0018
    je .Lbb_28_0033                                 # +0x001a
    mov dword ptr [rcx + 0x58], 2                   # +0x001c
    call R04_REL32_S172_Unload_XosDynamicLibrary_QEAAHXZ # +0x0023
    cmp dword ptr [rbx + 0x58], 3                   # +0x0028
    {load} mov eax, edi                             # +0x002c
    sete al                                         # +0x002e
.Lbb_28_0031:
    test eax, eax                                   # +0x0031
.Lbb_28_0033:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0033
    setne dil                                       # +0x0038
    {load} mov eax, edi                             # +0x003c
    add rsp, 0x20                                   # +0x003e
    pop rdi                                         # +0x0042
    ret                                             # +0x0043
end_28:

.section a30,"dr"
# COFF section 30: .text$mn
begin_30:
symbol_68:  # .text$mn
symbol_167:  # ?ForceUnload@XosDynamicLibrary@@SAHPEAPEADH@Z
symbol_205:  # $LN38
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    push rdi                                        # +0x000f
    sub rsp, 0x20                                   # +0x0010
    mov rbx, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0014
    {load} xor ebp, ebp                             # +0x001b
    movsxd rsi, edx                                 # +0x001d
    {load} mov rdi, rcx                             # +0x0020
    test rbx, rbx                                   # +0x0023
    je .Lbb_30_005a                                 # +0x0026
.Lbb_30_0028:
    cmp dword ptr [rbx + 0x58], 3                   # +0x0028
    je .Lbb_30_0051                                 # +0x002c
    {load} xor r9d, r9d                             # +0x002e
    lea rdx, [rip + R04_REL32_S615_C__0M_KDBBNFPC_ForceUnload] # +0x0031
    {load} xor r8d, r8d                             # +0x0038
    {load} mov rcx, rbx                             # +0x003b
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x003e
    test rax, rax                                   # +0x0043
    je .Lbb_30_0051                                 # +0x0046
    {load} mov edx, esi                             # +0x0048
    {load} mov rcx, rdi                             # +0x004a
    call rax                                        # +0x004d
    {load} add ebp, eax                             # +0x004f
.Lbb_30_0051:
    mov rbx, qword ptr [rbx + 0x18]                 # +0x0051
    test rbx, rbx                                   # +0x0055
    jne .Lbb_30_0028                                # +0x0058
.Lbb_30_005a:
    test esi, esi                                   # +0x005a
    je .Lbb_30_00b2                                 # +0x005c
    lea rdi, [rdi + rsi*8]                          # +0x005e
    {disp8} nop dword ptr [rax]                     # +0x0062
    .byte 0x66  # additional operand-size prefix    # +0x0066
    {disp32} nop word ptr [rax + rax]
.Lbb_30_0070:
    mov rbx, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0070
    lea rdi, [rdi - 8]                              # +0x0077
    dec esi                                         # +0x007b
    test rbx, rbx                                   # +0x007d
    je .Lbb_30_00ae                                 # +0x0080
.Lbb_30_0082:
    mov rdx, qword ptr [rbx + 0x30]                 # +0x0082
    mov rcx, qword ptr [rdi]                        # +0x0086
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x0089
    test eax, eax                                   # +0x008f
    je .Lbb_30_009e                                 # +0x0091
    mov rbx, qword ptr [rbx + 0x18]                 # +0x0093
    test rbx, rbx                                   # +0x0097
    jne .Lbb_30_0082                                # +0x009a
    jmp .Lbb_30_00ae                                # +0x009c
.Lbb_30_009e:
    cmp dword ptr [rbx + 0x58], 3                   # +0x009e
    je .Lbb_30_00ae                                 # +0x00a2
    {load} mov rcx, rbx                             # +0x00a4
    call R04_REL32_S168_ForceUnload_XosDynamicLibrary_QEAAHXZ # +0x00a7
    {load} add ebp, eax                             # +0x00ac
.Lbb_30_00ae:
    test esi, esi                                   # +0x00ae
    jne .Lbb_30_0070                                # +0x00b0
.Lbb_30_00b2:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x00b2
    {load} mov eax, ebp                             # +0x00b7
    mov rbp, qword ptr [rsp + 0x38]                 # +0x00b9
    mov rsi, qword ptr [rsp + 0x40]                 # +0x00be
    add rsp, 0x20                                   # +0x00c3
    pop rdi                                         # +0x00c7
    ret                                             # +0x00c8
end_30:

.section a32,"dr"
# COFF section 32: .text$mn
begin_32:
symbol_72:  # .text$mn
symbol_175:  # ?GetFullPath@XosDynamicLibrary@@QEBAPEADXZ
symbol_213:  # $LN4
    sub rsp, 0x28                                   # +0x0000
    mov rcx, qword ptr [rcx + 0x38]                 # +0x0004
    lea rdx, [rip + R04_REL32_S633_pFullPathName_1_GetFullPath_XosDynamicLibrary_QEBAPEADXZ_4PADA] # +0x0008
    mov r8d, 0x100                                  # +0x000f
    call qword ptr [rip + R04_REL32_S151_imp_GetModuleFileNameA] # +0x0015
    lea rax, [rip + R04_REL32_S633_pFullPathName_1_GetFullPath_XosDynamicLibrary_QEBAPEADXZ_4PADA] # +0x001b
    add rsp, 0x28                                   # +0x0022
    ret                                             # +0x0026
end_32:

.section a34,"dr"
# COFF section 34: .text$mn
begin_34:
symbol_76:  # .text$mn
symbol_163:  # ?Initialize@XosDynamicLibrary@@UEAAHPEAX@Z
symbol_201:  # $LN18
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    mov qword ptr [rcx + 0x50], rdx                 # +0x000a
    {load} mov rdi, rdx                             # +0x000e
    {load} mov rbx, rcx                             # +0x0011
    test rdx, rdx                                   # +0x0014
    je .Lbb_34_0047                                 # +0x0017
    {load} xor r9d, r9d                             # +0x0019
    lea rdx, [rip + R04_REL32_S624_C__0N_JDJKKOHE_ATInitialize] # +0x001c
    {load} xor r8d, r8d                             # +0x0023
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x0026
    test rax, rax                                   # +0x002b
    je .Lbb_34_0047                                 # +0x002e
    {load} mov rcx, rdi                             # +0x0030
    call rax                                        # +0x0033
    test eax, eax                                   # +0x0035
    mov ecx, 0xffffffff                             # +0x0037
    mov edx, 1                                      # +0x003c
    cmovne ecx, edx                                 # +0x0041
    mov dword ptr [rbx + 0x44], ecx                 # +0x0044
.Lbb_34_0047:
    {load} xor r9d, r9d                             # +0x0047
    lea r8, [rip + R04_REL32_S588_C__00CNPNBAHC]    # +0x004a
    lea rdx, [rip + R04_REL32_S627_C__0O_FIHIBCKH_DLLInitialize] # +0x0051
    {load} mov rcx, rbx                             # +0x0058
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x005b
    test rax, rax                                   # +0x0060
    je .Lbb_34_0081                                 # +0x0063
    call rax                                        # +0x0065
    test eax, eax                                   # +0x0067
    jns .Lbb_34_0081                                # +0x0069
    cmp dword ptr [rip + R05_REL32_1_S11_m_bQuietly_XosDynamicLibrary_0HA], 0 # +0x006b
    jne .Lbb_34_007a                                # +0x0072
    mov dword ptr [rip + R04_REL32_S10_m_iStatus_XosDynamicLibrary_0HA], eax # +0x0074
.Lbb_34_007a:
    mov dword ptr [rbx + 0x44], 0xfffffffe          # +0x007a
.Lbb_34_0081:
    mov eax, dword ptr [rbx + 0x44]                 # +0x0081
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0084
    add rsp, 0x20                                   # +0x0089
    pop rdi                                         # +0x008d
    ret                                             # +0x008e
end_34:

.section a36,"dr"
# COFF section 36: .text$mn
begin_36:
symbol_80:  # .text$mn
symbol_156:  # ?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
symbol_194:  # $LN18
    mov qword ptr [rsp + 0x10], rbx                 # +0x0000
    mov qword ptr [rsp + 0x18], rbp                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    {load} mov rbx, rcx                             # +0x000f
    mov rcx, 0xffffffffffffffff                     # +0x0012
    {disp32} nop dword ptr [rax]                    # +0x0019
.Lbb_36_0020:
    inc rcx                                         # +0x0020
    cmp byte ptr [rbx + rcx], 0                     # +0x0023
    jne .Lbb_36_0020                                # +0x0027
    add rcx, 6                                      # +0x0029
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x002d
    movzx ecx, byte ptr [rbx]                       # +0x0032
    {load} mov rbp, rax                             # +0x0035
    {load} mov rdi, rax                             # +0x0038
    test cl, cl                                     # +0x003b
    je .Lbb_36_008c                                 # +0x003d
    mov qword ptr [rsp + 0x30], rsi                 # +0x003f
.Lbb_36_0044:
    movsx ecx, cl                                   # +0x0044
    call qword ptr [rip + R04_REL32_S141_imp_islower] # +0x0047
    movsx ecx, byte ptr [rbx]                       # +0x004d
    lea rsi, [rdi + 1]                              # +0x0050
    test eax, eax                                   # +0x0054
    je .Lbb_36_0060                                 # +0x0056
    call qword ptr [rip + R04_REL32_S142_imp_toupper] # +0x0058
    jmp .Lbb_36_0063                                # +0x005e
.Lbb_36_0060:
    movzx eax, cl                                   # +0x0060
.Lbb_36_0063:
    inc rbx                                         # +0x0063
    mov byte ptr [rdi], al                          # +0x0066
    {load} mov rdi, rsi                             # +0x0068
    movzx ecx, byte ptr [rbx]                       # +0x006b
    test cl, cl                                     # +0x006e
    jne .Lbb_36_0044                                # +0x0070
    mov byte ptr [rsi], cl                          # +0x0072
    {load} mov rax, rbp                             # +0x0074
    mov rsi, qword ptr [rsp + 0x30]                 # +0x0077
    mov rbx, qword ptr [rsp + 0x38]                 # +0x007c
    mov rbp, qword ptr [rsp + 0x40]                 # +0x0081
    add rsp, 0x20                                   # +0x0086
    pop rdi                                         # +0x008a
    ret                                             # +0x008b
.Lbb_36_008c:
    mov rbx, qword ptr [rsp + 0x38]                 # +0x008c
    mov rbp, qword ptr [rsp + 0x40]                 # +0x0091
    mov byte ptr [rax], 0                           # +0x0096
    add rsp, 0x20                                   # +0x0099
    pop rdi                                         # +0x009d
    ret                                             # +0x009e
end_36:

.section a38,"dr"
# COFF section 38: .text$mn
begin_38:
symbol_84:  # .text$mn
symbol_173:  # ?Load@XosDynamicLibrary@@SAPEAV1@PEBDPEAX@Z
symbol_211:  # $LN16
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x30                                   # +0x0006
    {load} mov rbx, rdx                             # +0x000a
    lea r8, [rsp + 0x58]                            # +0x000d
    {load} xor edi, edi                             # +0x0012
    lea rdx, [rsp + 0x50]                           # +0x0014
    mov qword ptr [rsp + 0x58], rdi                 # +0x0019
    mov qword ptr [rsp + 0x50], rdi                 # +0x001e
    call R04_REL32_S159_FindLibrary_XosDynamicLibrary_KAPEAV1_PEBDAEAPEAD1_Z # +0x0023
    test rax, rax                                   # +0x0028
    {disp32} jne .Lbb_38_00b9                       # +0x002b
    lea ecx, [rdi + 0x60]                           # +0x0031
    call R04_REL32_S136_2_YAPEAX_K_Z                # +0x0034
    mov qword ptr [rsp + 0x20], rax                 # +0x0039
    {load} mov rcx, rax                             # +0x003e
    test rax, rax                                   # +0x0041
    je .Lbb_38_00ab                                 # +0x0044
    lea rax, [rip + R04_REL32_S591_7XosDynamicLibrary_6B] # +0x0046
    mov qword ptr [rcx + 0x50], rdi                 # +0x004d
    mov qword ptr [rcx], rax                        # +0x0051
    mov rax, qword ptr [rsp + 0x50]                 # +0x0054
    mov qword ptr [rcx + 0x28], rax                 # +0x0059
    mov rax, qword ptr [rsp + 0x58]                 # +0x005d
    mov qword ptr [rcx + 0x30], rax                 # +0x0062
    mov dword ptr [rcx + 0x58], edi                 # +0x0066
    mov dword ptr [rcx + 0x48], 1                   # +0x0069
    mov qword ptr [rcx + 0x40], 1                   # +0x0070
    mov dword ptr [rcx + 8], edi                    # +0x0078
    mov qword ptr [rcx + 0x38], rdi                 # +0x007b
    mov qword ptr [rcx + 0x10], rdi                 # +0x007f
    mov rax, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0083
    mov qword ptr [rcx + 0x18], rax                 # +0x008a
    mov rax, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x008e
    test rax, rax                                   # +0x0095
    je .Lbb_38_009e                                 # +0x0098
    mov qword ptr [rax + 0x10], rcx                 # +0x009a
.Lbb_38_009e:
    mov qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA], rcx # +0x009e
    mov qword ptr [rcx + 0x20], rdi                 # +0x00a5
    jmp .Lbb_38_00ae                                # +0x00a9
.Lbb_38_00ab:
    {load} mov rcx, rdi                             # +0x00ab
.Lbb_38_00ae:
    {load} xor r8d, r8d                             # +0x00ae
    {load} mov rdx, rbx                             # +0x00b1
    call R04_REL32_S160_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z # +0x00b4
.Lbb_38_00b9:
    mov rbx, qword ptr [rsp + 0x40]                 # +0x00b9
    add rsp, 0x30                                   # +0x00be
    pop rdi                                         # +0x00c2
    ret                                             # +0x00c3
end_38:

.section a40,"dr"
# COFF section 40: .text$mn
begin_40:
symbol_88:  # .text$mn
symbol_160:  # ?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
symbol_198:  # $LN32
    rex push rbx                                    # +0x0000
    push r14                                        # +0x0002
    push r15                                        # +0x0004
    sub rsp, 0x20                                   # +0x0006
    {load} mov r14d, r8d                            # +0x000a
    {load} mov r15, rdx                             # +0x000d
    {load} mov rbx, rcx                             # +0x0010
    call R04_REL32_S164_LoadLib_XosDynamicLibrary_QEAAHXZ # +0x0013
    test eax, eax                                   # +0x0018
    jns .Lbb_40_003d                                # +0x001a
.Lbb_40_001c:
    cmp r14d, 3                                     # +0x001c
    jne .Lbb_40_0029                                # +0x0020
    mov dword ptr [rbx + 0x58], 2                   # +0x0022
.Lbb_40_0029:
    {load} mov rcx, rbx                             # +0x0029
    call R04_REL32_S172_Unload_XosDynamicLibrary_QEAAHXZ # +0x002c
    {load} xor eax, eax                             # +0x0031
    add rsp, 0x20                                   # +0x0033
    pop r15                                         # +0x0037
    pop r14                                         # +0x0039
    pop rbx                                         # +0x003b
    ret                                             # +0x003c
.Lbb_40_003d:
    cmp qword ptr [rip + R05_REL32_1_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA], 0 # +0x003d
    je .Lbb_40_00c1                                 # +0x0045
    cmp dword ptr [rip + R05_REL32_1_S12_m_iSearchPaths_XosDynamicLibrary_0HA], 0 # +0x0047
    je .Lbb_40_00c1                                 # +0x004e
    {load} xor r9d, r9d                             # +0x0050
    mov qword ptr [rsp + 0x40], rbp                 # +0x0053
    {load} xor r8d, r8d                             # +0x0058
    lea rdx, [rip + R04_REL32_S618_C__0BB_OLNKDJGE_AddDLLSearchPath] # +0x005b
    {load} mov rcx, rbx                             # +0x0062
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x0065
    {load} mov rbp, rax                             # +0x006a
    test rax, rax                                   # +0x006d
    je .Lbb_40_00bc                                 # +0x0070
    mov qword ptr [rsp + 0x50], rdi                 # +0x0072
    {load} xor edi, edi                             # +0x0077
    cmp dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA], edi # +0x0079
    jle .Lbb_40_00b7                                # +0x007f
    mov qword ptr [rsp + 0x48], rsi                 # +0x0081
    {load} xor esi, esi                             # +0x0086
    {disp32} nop dword ptr [rax + rax]              # +0x0088
.Lbb_40_0090:
    mov dword ptr [rbx + 8], 1                      # +0x0090
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0097
    mov rcx, qword ptr [rsi + rcx]                  # +0x009e
    call rbp                                        # +0x00a2
    inc edi                                         # +0x00a4
    lea rsi, [rsi + 8]                              # +0x00a6
    cmp edi, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x00aa
    jl .Lbb_40_0090                                 # +0x00b0
    mov rsi, qword ptr [rsp + 0x48]                 # +0x00b2
.Lbb_40_00b7:
    mov rdi, qword ptr [rsp + 0x50]                 # +0x00b7
.Lbb_40_00bc:
    mov rbp, qword ptr [rsp + 0x40]                 # +0x00bc
.Lbb_40_00c1:
    mov rax, qword ptr [rbx]                        # +0x00c1
    {load} mov rdx, r15                             # +0x00c4
    {load} mov rcx, rbx                             # +0x00c7
    call qword ptr [rax + 8]                        # +0x00ca
    cmp eax, -1                                     # +0x00cd
    {disp32} jl .Lbb_40_001c                        # +0x00d0
    {load} mov rax, rbx                             # +0x00d6
    add rsp, 0x20                                   # +0x00d9
    pop r15                                         # +0x00dd
    pop r14                                         # +0x00df
    pop rbx                                         # +0x00e1
    ret                                             # +0x00e2
end_40:

.section a42,"dr"
# COFF section 42: .text$mn
begin_42:
symbol_92:  # .text$mn
symbol_164:  # ?LoadLib@XosDynamicLibrary@@QEAAHXZ
symbol_202:  # $LN55
    {load} mov r11, rsp                             # +0x0000
    push rdi                                        # +0x0003
    push r14                                        # +0x0004
    push r15                                        # +0x0006
    sub rsp, 0x440                                  # +0x0008
    mov rax, qword ptr [rip + R04_REL32_S667_security_cookie] # +0x000f
    {load} xor rax, rsp                             # +0x0016
    mov qword ptr [rsp + 0x430], rax                # +0x0019
    {load} mov rdi, rcx                             # +0x0021
    mov qword ptr [r11 + 0x10], rbx                 # +0x0024
    lea rcx, [rsp + 0x20]                           # +0x0028
    mov qword ptr [r11 + 0x20], rsi                 # +0x002d
    {load} xor r8d, r8d                             # +0x0031
    {load} xor edx, edx                             # +0x0034
    {load} xor r14d, r14d                           # +0x0036
    call qword ptr [rip + R04_REL32_S154_imp__controlfp_s] # +0x0039
    mov ecx, 0x400                                  # +0x003f
    {load} mov r15d, r14d                           # +0x0044
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x0047
    {load} mov rdx, rax                             # +0x004c
    mov ecx, 0x400                                  # +0x004f
    {load} mov rsi, rax                             # +0x0054
    call qword ptr [rip + R04_REL32_S148_imp_GetCurrentDirectoryA] # +0x0057
    movsxd rbx, eax                                 # +0x005d
    test eax, eax                                   # +0x0060
    jne .Lbb_42_0071                                # +0x0062
    {load} mov rcx, rsi                             # +0x0064
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0067
    {disp32} jmp .Lbb_42_0105                       # +0x006c
.Lbb_42_0071:
    mov qword ptr [rsp + 0x470], rbp                # +0x0071
    lea eax, [rbx + 2]                              # +0x0079
    movsxd rbp, eax                                 # +0x007c
    cmp ebx, 0x400                                  # +0x007f
    jle .Lbb_42_00c1                                # +0x0085
    {load} mov rcx, rsi                             # +0x0087
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x008a
    {load} mov rcx, rbp                             # +0x008f
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x0092
    {load} mov rdx, rax                             # +0x0097
    {load} mov ecx, ebx                             # +0x009a
    {load} mov rsi, rax                             # +0x009c
    call qword ptr [rip + R04_REL32_S148_imp_GetCurrentDirectoryA] # +0x009f
    test eax, eax                                   # +0x00a5
    je .Lbb_42_00f5                                 # +0x00a7
    cmp byte ptr [rbx + rsi - 1], 0x5c              # +0x00a9
    {load} mov r15, rsi                             # +0x00ae
    je .Lbb_42_00bb                                 # +0x00b1
    mov word ptr [rbx + rsi], 0x5c                  # +0x00b3
    jmp .Lbb_42_00fd                                # +0x00b9
.Lbb_42_00bb:
    mov byte ptr [rbx + rsi], r14b                  # +0x00bb
    jmp .Lbb_42_00fd                                # +0x00bf
.Lbb_42_00c1:
    {load} mov rcx, rbp                             # +0x00c1
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x00c4
    {load} mov r9, rbx                              # +0x00c9
    {load} mov r8, rsi                              # +0x00cc
    {load} mov rdx, rbp                             # +0x00cf
    {load} mov rcx, rax                             # +0x00d2
    {load} mov r15, rax                             # +0x00d5
    call qword ptr [rip + R04_REL32_S146_imp_strncpy_s] # +0x00d8
    cmp byte ptr [rbx + r15 - 1], 0x5c              # +0x00de
    je .Lbb_42_00ef                                 # +0x00e4
    mov byte ptr [rbx + r15 + 1], r14b              # +0x00e6
    mov al, 0x5c                                    # +0x00eb
    jmp .Lbb_42_00f1                                # +0x00ed
.Lbb_42_00ef:
    {load} xor al, al                               # +0x00ef
.Lbb_42_00f1:
    mov byte ptr [rbx + r15], al                    # +0x00f1
.Lbb_42_00f5:
    {load} mov rcx, rsi                             # +0x00f5
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x00f8
.Lbb_42_00fd:
    mov rbp, qword ptr [rsp + 0x470]                # +0x00fd
.Lbb_42_0105:
    mov rax, qword ptr [rdi + 0x30]                 # +0x0105
    {load} mov rcx, r14                             # +0x0109
    mov rsi, qword ptr [rsp + 0x478]                # +0x010c
    mov qword ptr [rdi + 0x38], r14                 # +0x0114
    cmp qword ptr [rdi + 0x28], rax                 # +0x0118
    {disp32} jne .Lbb_42_01fb                       # +0x011c
    {load} mov r8, r15                              # +0x0122
    lea rcx, [rsp + 0x30]                           # +0x0125
    mov edx, 0x400                                  # +0x012a
    call qword ptr [rip + R04_REL32_S144_imp_strcpy_s] # +0x012f
    mov r8, qword ptr [rdi + 0x28]                  # +0x0135
    lea rcx, [rsp + 0x30]                           # +0x0139
    mov edx, 0x400                                  # +0x013e
    call qword ptr [rip + R04_REL32_S145_imp_strcat_s] # +0x0143
    lea rcx, [rsp + 0x30]                           # +0x0149
    call qword ptr [rip + R04_REL32_S153_imp_LoadLibraryA] # +0x014e
    mov qword ptr [rdi + 0x38], rax                 # +0x0154
    {load} mov rcx, rax                             # +0x0158
    test rax, rax                                   # +0x015b
    {disp32} jne .Lbb_42_01fb                       # +0x015e
    movsxd rbx, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x0164
    {disp8} nop dword ptr [rax + rax]               # +0x016b
.Lbb_42_0170:
    test rbx, rbx                                   # +0x0170
    {disp32} je .Lbb_42_01fb                        # +0x0173
    mov r8, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0179
    lea rcx, [rsp + 0x30]                           # +0x0180
    dec rbx                                         # +0x0185
    mov edx, 0x400                                  # +0x0188
    mov r8, qword ptr [r8 + rbx*8]                  # +0x018d
    call qword ptr [rip + R04_REL32_S144_imp_strcpy_s] # +0x0191
    lea rcx, [rsp + 0x30]                           # +0x0197
    mov rax, 0xffffffffffffffff                     # +0x019c
.Lbb_42_01a3:
    cmp byte ptr [rcx + rax + 1], r14b              # +0x01a3
    lea rax, [rax + 1]                              # +0x01a8
    jne .Lbb_42_01a3                                # +0x01ac
    cmp byte ptr [rsp + rax + 0x2f], 0x5c           # +0x01ae
    je .Lbb_42_01cc                                 # +0x01b3
    lea r8, [rip + R04_REL32_S630_C__01KICIPPFI_2]  # +0x01b5
    mov edx, 0x400                                  # +0x01bc
    lea rcx, [rsp + 0x30]                           # +0x01c1
    call qword ptr [rip + R04_REL32_S145_imp_strcat_s] # +0x01c6
.Lbb_42_01cc:
    mov r8, qword ptr [rdi + 0x28]                  # +0x01cc
    lea rcx, [rsp + 0x30]                           # +0x01d0
    mov edx, 0x400                                  # +0x01d5
    call qword ptr [rip + R04_REL32_S145_imp_strcat_s] # +0x01da
    lea rcx, [rsp + 0x30]                           # +0x01e0
    call qword ptr [rip + R04_REL32_S153_imp_LoadLibraryA] # +0x01e5
    mov qword ptr [rdi + 0x38], rax                 # +0x01eb
    {load} mov rcx, rax                             # +0x01ef
    test rax, rax                                   # +0x01f2
    {disp32} je .Lbb_42_0170                        # +0x01f5
.Lbb_42_01fb:
    mov rbx, qword ptr [rsp + 0x468]                # +0x01fb
    test rcx, rcx                                   # +0x0203
    jne .Lbb_42_0219                                # +0x0206
    mov rcx, qword ptr [rdi + 0x28]                 # +0x0208
    call qword ptr [rip + R04_REL32_S153_imp_LoadLibraryA] # +0x020c
    {load} mov rcx, rax                             # +0x0212
    mov qword ptr [rdi + 0x38], rax                 # +0x0215
.Lbb_42_0219:
    mov eax, dword ptr [rdi + 0x58]                 # +0x0219
    test eax, eax                                   # +0x021c
    jne .Lbb_42_022c                                # +0x021e
    mov dword ptr [rdi + 0x58], 1                   # +0x0220
    mov eax, 1                                      # +0x0227
.Lbb_42_022c:
    test rcx, rcx                                   # +0x022c
    jne .Lbb_42_025b                                # +0x022f
    call qword ptr [rip + R04_REL32_S149_imp_GetLastError] # +0x0231
    mov ecx, 0xa0000034                             # +0x0237
    mov edx, 0xa000ffff                             # +0x023c
    cmp eax, 0x7e                                   # +0x0241
    cmovne ecx, edx                                 # +0x0244
    cmp dword ptr [rip + R04_REL32_S11_m_bQuietly_XosDynamicLibrary_0HA], r14d # +0x0247
    jne .Lbb_42_0256                                # +0x024e
    mov dword ptr [rip + R04_REL32_S10_m_iStatus_XosDynamicLibrary_0HA], ecx # +0x0250
.Lbb_42_0256:
    {load} mov r14d, ecx                            # +0x0256
    jmp .Lbb_42_0298                                # +0x0259
.Lbb_42_025b:
    cmp eax, 3                                      # +0x025b
    jne .Lbb_42_0267                                # +0x025e
    mov dword ptr [rdi + 0x58], 1                   # +0x0260
.Lbb_42_0267:
    {load} xor r8d, r8d                             # +0x0267
    lea rcx, [rsp + 0x24]                           # +0x026a
    {load} xor edx, edx                             # +0x026f
    call qword ptr [rip + R04_REL32_S154_imp__controlfp_s] # +0x0271
    mov edx, dword ptr [rsp + 0x20]                 # +0x0277
    cmp edx, dword ptr [rsp + 0x24]                 # +0x027b
    je .Lbb_42_0298                                 # +0x027f
    mov r8d, 0x8001f                                # +0x0281
    lea rcx, [rsp + 0x20]                           # +0x0287
    call qword ptr [rip + R04_REL32_S154_imp__controlfp_s] # +0x028c
    mov r14d, 0x50                                  # +0x0292
.Lbb_42_0298:
    {load} mov rcx, r15                             # +0x0298
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x029b
    {load} mov eax, r14d                            # +0x02a0
    mov rcx, qword ptr [rsp + 0x430]                # +0x02a3
    {load} xor rcx, rsp                             # +0x02ab
    call R04_REL32_S191_security_check_cookie       # +0x02ae
    add rsp, 0x440                                  # +0x02b3
    pop r15                                         # +0x02ba
    pop r14                                         # +0x02bc
    pop rdi                                         # +0x02be
    ret                                             # +0x02bf
end_42:

.section a44,"dr"
# COFF section 44: .text$mn
begin_44:
symbol_96:  # .text$mn
symbol_169:  # ?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
symbol_207:  # $LN68
    mov qword ptr [rsp + 0x10], rdx                 # +0x0000
    mov qword ptr [rsp + 8], rcx                    # +0x0005
    push rbx                                        # +0x000a
    push rsi                                        # +0x000b
    push rdi                                        # +0x000c
    push r13                                        # +0x000d
    push r14                                        # +0x000f
    sub rsp, 0x60                                   # +0x0011
    mov r8, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x0015
    {load} xor esi, esi                             # +0x001c
    {load} mov rbx, rdx                             # +0x001e
    {load} mov rdi, rcx                             # +0x0021
    {load} mov r13d, esi                            # +0x0024
    {load} mov r14d, esi                            # +0x0027
    {load} mov r9d, esi                             # +0x002a
    test r8, r8                                     # +0x002d
    {disp32} je .Lbb_44_02e9                        # +0x0030
    .byte 0x66  # additional operand-size prefix    # +0x0036
    {disp32} nop word ptr [rax + rax]
.Lbb_44_0040:
    cmp dword ptr [r8 + 0x58], 3                    # +0x0040
    lea eax, [r13 + 1]                              # +0x0045
    mov r8, qword ptr [r8 + 0x18]                   # +0x0049
    cmove eax, r13d                                 # +0x004d
    movsxd r13, eax                                 # +0x0051
    test r8, r8                                     # +0x0054
    jne .Lbb_44_0040                                # +0x0057
    test eax, eax                                   # +0x0059
    {disp32} je .Lbb_44_02e9                        # +0x005b
    mov qword ptr [rsp + 0x58], rbp                 # +0x0061
    mov eax, 8                                      # +0x0066
    mul r13                                         # +0x006b
    mov qword ptr [rsp + 0x48], r15                 # +0x006e
    {load} mov rbp, r13                             # +0x0073
    mov r15, 0xffffffffffffffff                     # +0x0076
    cmovo rax, r15                                  # +0x007d
    {load} mov rcx, rax                             # +0x0081
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x0084
    {load} mov r14, rax                             # +0x0089
    mov eax, 4                                      # +0x008c
    mul r13                                         # +0x0091
    cmovo rax, r15                                  # +0x0094
    {load} mov rcx, rax                             # +0x0098
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x009b
    mov r15, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x00a0
    {load} mov r9, rax                              # +0x00a7
    mov qword ptr [rsp + 0x28], rax                 # +0x00aa
    mov qword ptr [rsp + 0x20], r15                 # +0x00af
    test r15, r15                                   # +0x00b4
    {disp32} je .Lbb_44_02df                        # +0x00b7
    {load} mov rcx, r14                             # +0x00bd
    {load} mov rdx, rax                             # +0x00c0
.Lbb_44_00c3:
    cmp dword ptr [r15 + 0x58], 3                   # +0x00c3
    je .Lbb_44_00e0                                 # +0x00c8
    {load} mov eax, esi                             # +0x00ca
    cmp dword ptr [r15 + 0x48], eax                 # +0x00cc
    sete al                                         # +0x00d0
    mov dword ptr [rdx], eax                        # +0x00d3
    add rdx, 4                                      # +0x00d5
    mov qword ptr [rcx], r15                        # +0x00d9
    add rcx, 8                                      # +0x00dc
.Lbb_44_00e0:
    mov r15, qword ptr [r15 + 0x18]                 # +0x00e0
    test r15, r15                                   # +0x00e4
    jne .Lbb_44_00c3                                # +0x00e7
    mov r15, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x00e9
    mov qword ptr [rsp + 0x20], r15                 # +0x00f0
    test r15, r15                                   # +0x00f5
    {disp32} je .Lbb_44_02df                        # +0x00f8
    mov qword ptr [rsp + 0x50], r12                 # +0x00fe
.Lbb_44_0103:
    cmp dword ptr [r15 + 0x58], 3                   # +0x0103
    {disp32} je .Lbb_44_02c3                        # +0x0108
    {load} xor r9d, r9d                             # +0x010e
    lea rdx, [rip + R04_REL32_S612_C__0L_EJIEJOHD_DLLsLoaded] # +0x0111
    {load} xor r8d, r8d                             # +0x0118
    {load} mov rcx, r15                             # +0x011b
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x011e
    mov qword ptr [rsp + 0x30], rax                 # +0x0123
    test rax, rax                                   # +0x0128
    {disp32} je .Lbb_44_02c3                        # +0x012b
    lea rdx, [rsp + 0xa0]                           # +0x0131
    mov qword ptr [rsp + 0xa8], rsi                 # +0x0139
    lea rcx, [rsp + 0xa8]                           # +0x0141
    mov qword ptr [rsp + 0xa0], rsi                 # +0x0149
    call rax                                        # +0x0151
    test eax, eax                                   # +0x0153
    {disp32} je .Lbb_44_02c3                        # +0x0155
    {load} xor esi, esi                             # +0x015b
    movsxd r12, eax                                 # +0x015d
    test eax, eax                                   # +0x0160
    {disp32} jle .Lbb_44_02ad                       # +0x0162
    mov r15, qword ptr [rsp + 0x28]                 # +0x0168
    nop dword ptr [rax]                             # +0x016d
.Lbb_44_0170:
    {load} xor edi, edi                             # +0x0170
    {load} xor ebx, ebx                             # +0x0172
    test rbp, rbp                                   # +0x0174
    jle .Lbb_44_01bd                                # +0x0177
    {disp32} nop dword ptr [rax]                    # +0x0179
.Lbb_44_0180:
    mov rax, qword ptr [rsp + 0xa8]                 # +0x0180
    mov rcx, qword ptr [r14 + rbx*8]                # +0x0188
    mov rdx, qword ptr [rax + rsi*8]                # +0x018c
    mov rcx, qword ptr [rcx + 0x30]                 # +0x0190
    mov rdx, qword ptr [rdx + 0x30]                 # +0x0194
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x0198
    test eax, eax                                   # +0x019e
    je .Lbb_44_01ae                                 # +0x01a0
    inc edi                                         # +0x01a2
    inc rbx                                         # +0x01a4
    {load} cmp rbx, rbp                             # +0x01a7
    jl .Lbb_44_0180                                 # +0x01aa
    jmp .Lbb_44_01bd                                # +0x01ac
.Lbb_44_01ae:
    mov rax, qword ptr [rsp + 0xa0]                 # +0x01ae
    mov ecx, dword ptr [rax + rsi*4]                # +0x01b6
    or dword ptr [r15 + rbx*4], ecx                 # +0x01b9
.Lbb_44_01bd:
    {load} cmp edi, r13d                            # +0x01bd
    {disp32} jne .Lbb_44_0287                       # +0x01c0
    mov rax, qword ptr [rsp + 0x90]                 # +0x01c6
    mov qword ptr [rax], r14                        # +0x01ce
    mov rax, qword ptr [rsp + 0x98]                 # +0x01d1
    mov qword ptr [rax], r15                        # +0x01d9
    lea eax, [rdi + 1]                              # +0x01dc
    movsxd rbx, eax                                 # +0x01df
    mov rdi, 0xffffffffffffffff                     # +0x01e2
    mov eax, 8                                      # +0x01e9
    mul rbx                                         # +0x01ee
    cmovo rax, rdi                                  # +0x01f1
    {load} mov rcx, rax                             # +0x01f5
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x01f8
    {load} mov r14, rax                             # +0x01fd
    mov eax, 4                                      # +0x0200
    mul rbx                                         # +0x0205
    cmovo rax, rdi                                  # +0x0208
    {load} mov rcx, rax                             # +0x020c
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x020f
    mov rdi, qword ptr [rsp + 0x90]                 # +0x0214
    {load} mov rcx, r14                             # +0x021c
    movsxd rbx, r13d                                # +0x021f
    {load} mov r15, rax                             # +0x0222
    mov rdx, qword ptr [rdi]                        # +0x0225
    lea r8, [rbx*8]                                 # +0x0228
    call R04_REL32_S192_memcpy                      # +0x0230
    lea r8, [rbx*4]                                 # +0x0235
    {load} mov rcx, r15                             # +0x023d
    mov rbx, qword ptr [rsp + 0x98]                 # +0x0240
    mov rdx, qword ptr [rbx]                        # +0x0248
    call R04_REL32_S192_memcpy                      # +0x024b
    mov rax, qword ptr [rsp + 0xa0]                 # +0x0250
    inc r13d                                        # +0x0258
    mov ecx, dword ptr [rax + rsi*4]                # +0x025b
    mov dword ptr [r15 + rbp*4], ecx                # +0x025e
    mov rax, qword ptr [rsp + 0xa8]                 # +0x0262
    mov rcx, qword ptr [rax + rsi*8]                # +0x026a
    mov qword ptr [r14 + rbp*8], rcx                # +0x026e
    inc rbp                                         # +0x0272
    mov rcx, qword ptr [rdi]                        # +0x0275
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0278
    mov rcx, qword ptr [rbx]                        # +0x027d
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0280
    jmp .Lbb_44_0297                                # +0x0285
.Lbb_44_0287:
    mov rbx, qword ptr [rsp + 0x98]                 # +0x0287
    mov rdi, qword ptr [rsp + 0x90]                 # +0x028f
.Lbb_44_0297:
    inc rsi                                         # +0x0297
    {load} cmp rsi, r12                             # +0x029a
    {disp32} jl .Lbb_44_0170                        # +0x029d
    mov qword ptr [rsp + 0x28], r15                 # +0x02a3
    mov r15, qword ptr [rsp + 0x20]                 # +0x02a8
.Lbb_44_02ad:
    lea rdx, [rsp + 0xa0]                           # +0x02ad
    lea rcx, [rsp + 0xa8]                           # +0x02b5
    call qword ptr [rsp + 0x30]                     # +0x02bd
    {load} xor esi, esi                             # +0x02c1
.Lbb_44_02c3:
    mov r15, qword ptr [r15 + 0x18]                 # +0x02c3
    mov qword ptr [rsp + 0x20], r15                 # +0x02c7
    test r15, r15                                   # +0x02cc
    {disp32} jne .Lbb_44_0103                       # +0x02cf
    mov r12, qword ptr [rsp + 0x50]                 # +0x02d5
    mov r9, qword ptr [rsp + 0x28]                  # +0x02da
.Lbb_44_02df:
    mov rbp, qword ptr [rsp + 0x58]                 # +0x02df
    mov r15, qword ptr [rsp + 0x48]                 # +0x02e4
.Lbb_44_02e9:
    mov qword ptr [rdi], r14                        # +0x02e9
    {load} mov eax, r13d                            # +0x02ec
    mov qword ptr [rbx], r9                         # +0x02ef
    add rsp, 0x60                                   # +0x02f2
    pop r14                                         # +0x02f6
    pop r13                                         # +0x02f8
    pop rdi                                         # +0x02fa
    pop rsi                                         # +0x02fb
    pop rbx                                         # +0x02fc
    ret                                             # +0x02fd
end_44:

.section a46,"dr"
# COFF section 46: .text$mn
begin_46:
symbol_100:  # .text$mn
symbol_157:  # ?QuietlyFindCallAddress@XosDynamicLibrary@@IEAAPEAXPEBD0PEAPEAD@Z
symbol_195:  # $LN4
    sub rsp, 0x28                                   # +0x0000
    inc dword ptr [rip + R04_REL32_S11_m_bQuietly_XosDynamicLibrary_0HA] # +0x0004
    call R04_REL32_S171_FindCallAddress_XosDynamicLibrary_QEAAPEAXPEBD0PEAPEAD_Z # +0x000a
    dec dword ptr [rip + R04_REL32_S11_m_bQuietly_XosDynamicLibrary_0HA] # +0x000f
    add rsp, 0x28                                   # +0x0015
    ret                                             # +0x0019
end_46:

.section a48,"dr"
# COFF section 48: .text$mn
begin_48:
symbol_104:  # .text$mn
symbol_161:  # ?Reload@XosDynamicLibrary@@IEAAXXZ
symbol_199:  # $LN11
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    mov rbx, qword ptr [rcx + 0x20]                 # +0x000a
    {load} mov rdi, rcx                             # +0x000e
    test rbx, rbx                                   # +0x0011
    je .Lbb_48_003f                                 # +0x0014
    .byte 0x66  # additional operand-size prefix    # +0x0016
    {disp32} nop word ptr [rax + rax]
.Lbb_48_0020:
    mov rdx, qword ptr [rbx + 0x20]                 # +0x0020
    {load} xor r9d, r9d                             # +0x0024
    {load} xor r8d, r8d                             # +0x0027
    {load} mov rcx, rdi                             # +0x002a
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x002d
    mov qword ptr [rbx + 0x28], rax                 # +0x0032
    mov rbx, qword ptr [rbx + 0x10]                 # +0x0036
    test rbx, rbx                                   # +0x003a
    jne .Lbb_48_0020                                # +0x003d
.Lbb_48_003f:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x003f
    add rsp, 0x20                                   # +0x0044
    pop rdi                                         # +0x0048
    ret                                             # +0x0049
end_48:

.section a50,"dr"
# COFF section 50: .text$mn
begin_50:
symbol_108:  # .text$mn
symbol_166:  # ?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
symbol_204:  # $LN45
    mov qword ptr [rsp + 0x18], rbx                 # +0x0000
    push rbp                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    mov rbx, qword ptr [rip + R04_REL32_S9_m_pDLLs_XosDynamicLibrary_0PEAV1_EA] # +0x000a
    {load} mov rbp, rcx                             # +0x0011
    test rbx, rbx                                   # +0x0014
    je .Lbb_50_0048                                 # +0x0017
    {disp32} nop dword ptr [rax]                    # +0x0019
.Lbb_50_0020:
    {load} xor r9d, r9d                             # +0x0020
    lea rdx, [rip + R04_REL32_S621_C__0BE_MEINDEKP_RemoveDLLSearchPath] # +0x0023
    {load} xor r8d, r8d                             # +0x002a
    {load} mov rcx, rbx                             # +0x002d
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x0030
    test rax, rax                                   # +0x0035
    je .Lbb_50_003f                                 # +0x0038
    {load} mov rcx, rbp                             # +0x003a
    call rax                                        # +0x003d
.Lbb_50_003f:
    mov rbx, qword ptr [rbx + 0x18]                 # +0x003f
    test rbx, rbx                                   # +0x0043
    jne .Lbb_50_0020                                # +0x0046
.Lbb_50_0048:
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0048
    test rcx, rcx                                   # +0x004f
    {disp32} je .Lbb_50_0125                        # +0x0052
    {load} xor ebx, ebx                             # +0x0058
    mov qword ptr [rsp + 0x30], rsi                 # +0x005a
    cmp dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA], ebx # +0x005f
    mov qword ptr [rsp + 0x38], rdi                 # +0x0065
    {disp32} jle .Lbb_50_00fe                       # +0x006a
    {load} xor esi, esi                             # +0x0070
.Lbb_50_0072:
    lea rdi, [rsi*8]                                # +0x0072
    test rbp, rbp                                   # +0x007a
    je .Lbb_50_00dd                                 # +0x007d
    mov rdx, qword ptr [rdi + rcx]                  # +0x007f
    {load} mov rcx, rbp                             # +0x0083
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x0086
    test eax, eax                                   # +0x008c
    jne .Lbb_50_00e6                                # +0x008e
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x0090
    mov rcx, qword ptr [rdi + rcx]                  # +0x0097
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x009b
    mov ecx, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x00a0
    lea eax, [rcx - 1]                              # +0x00a6
    {load} cmp ebx, eax                             # +0x00a9
    jge .Lbb_50_00d3                                # +0x00ab
    nop dword ptr [rax]                             # +0x00ad
.Lbb_50_00b0:
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x00b0
    lea rdi, [rdi + 8]                              # +0x00b7
    inc ebx                                         # +0x00bb
    mov rax, qword ptr [rcx + rdi]                  # +0x00bd
    mov qword ptr [rcx + rdi - 8], rax              # +0x00c1
    mov ecx, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x00c6
    lea eax, [rcx - 1]                              # +0x00cc
    {load} cmp ebx, eax                             # +0x00cf
    jl .Lbb_50_00b0                                 # +0x00d1
.Lbb_50_00d3:
    dec ecx                                         # +0x00d3
    mov dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA], ecx # +0x00d5
    jmp .Lbb_50_011b                                # +0x00db
.Lbb_50_00dd:
    mov rcx, qword ptr [rdi + rcx]                  # +0x00dd
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x00e1
.Lbb_50_00e6:
    mov rcx, qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA] # +0x00e6
    inc ebx                                         # +0x00ed
    inc rsi                                         # +0x00ef
    cmp ebx, dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA] # +0x00f2
    {disp32} jl .Lbb_50_0072                        # +0x00f8
.Lbb_50_00fe:
    test rbp, rbp                                   # +0x00fe
    jne .Lbb_50_011b                                # +0x0101
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0103
    mov qword ptr [rip + R04_REL32_S14_m_ppSearchPaths_XosDynamicLibrary_0PEAPEADEA], rbp # +0x0108
    mov dword ptr [rip + R04_REL32_S12_m_iSearchPaths_XosDynamicLibrary_0HA], ebp # +0x010f
    mov dword ptr [rip + R04_REL32_S13_m_iMaxSearchPaths_XosDynamicLibrary_0HA], ebp # +0x0115
.Lbb_50_011b:
    mov rsi, qword ptr [rsp + 0x30]                 # +0x011b
    mov rdi, qword ptr [rsp + 0x38]                 # +0x0120
.Lbb_50_0125:
    mov rbx, qword ptr [rsp + 0x40]                 # +0x0125
    add rsp, 0x20                                   # +0x012a
    pop rbp                                         # +0x012e
    ret                                             # +0x012f
end_50:

.section a52,"dr"
# COFF section 52: .text$mn
begin_52:
symbol_112:  # .text$mn
symbol_172:  # ?Unload@XosDynamicLibrary@@QEAAHXZ
symbol_210:  # $LN51
    mov qword ptr [rsp + 0x10], rbx                 # +0x0000
    mov qword ptr [rsp + 0x18], rsi                 # +0x0005
    mov qword ptr [rsp + 0x20], rdi                 # +0x000a
    push r14                                        # +0x000f
    sub rsp, 0x20                                   # +0x0011
    mov eax, dword ptr [rcx + 0x58]                 # +0x0015
    lea rsi, [rcx + 0x58]                           # +0x0018
    {load} xor edi, edi                             # +0x001c
    {load} mov rbx, rcx                             # +0x001e
    cmp eax, 2                                      # +0x0021
    je .Lbb_52_0036                                 # +0x0024
    dec dword ptr [rcx + 0x40]                      # +0x0026
    cmp dword ptr [rcx + 0x40], edi                 # +0x0029
    {disp32} jg .Lbb_52_013b                        # +0x002c
    lea rsi, [rcx + 0x58]                           # +0x0032
.Lbb_52_0036:
    cmp qword ptr [rcx + 0x38], rdi                 # +0x0036
    {disp32} je .Lbb_52_012c                        # +0x003a
    {load} xor eax, eax                             # +0x0040
    mov qword ptr [rsp + 0x30], rbp                 # +0x0042
    cmp dword ptr [rcx + 0x44], -2                  # +0x0047
    je .Lbb_52_0063                                 # +0x004b
    {load} xor r9d, r9d                             # +0x004d
    lea r8, [rip + R04_REL32_S588_C__00CNPNBAHC]    # +0x0050
    lea rdx, [rip + R04_REL32_S636_C__0M_MOJGKDOC_DLLFinalize] # +0x0057
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x005e
.Lbb_52_0063:
    {load} xor ebp, ebp                             # +0x0063
    test rax, rax                                   # +0x0065
    je .Lbb_52_0085                                 # +0x0068
    call rax                                        # +0x006a
    {load} mov ebp, eax                             # +0x006c
    test eax, eax                                   # +0x006e
    jle .Lbb_52_0085                                # +0x0070
    cmp dword ptr [rsi], 2                          # +0x0072
    {load} mov eax, edi                             # +0x0075
    {disp32} jne .Lbb_52_0101                       # +0x0077
    mov dword ptr [rsi], 1                          # +0x007d
    jmp .Lbb_52_0101                                # +0x0083
.Lbb_52_0085:
    cmp dword ptr [rbx + 8], edi                    # +0x0085
    je .Lbb_52_00a3                                 # +0x0088
    {load} xor r9d, r9d                             # +0x008a
    lea rdx, [rip + R04_REL32_S621_C__0BE_MEINDEKP_RemoveDLLSearchPath] # +0x008d
    {load} xor r8d, r8d                             # +0x0094
    {load} mov rcx, rbx                             # +0x0097
    call R04_REL32_S157_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z # +0x009a
    {load} xor ecx, ecx                             # +0x009f
    call rax                                        # +0x00a1
.Lbb_52_00a3:
    test ebp, ebp                                   # +0x00a3
    jns .Lbb_52_00b5                                # +0x00a5
    cmp dword ptr [rip + R04_REL32_S11_m_bQuietly_XosDynamicLibrary_0HA], edi # +0x00a7
    jne .Lbb_52_00b5                                # +0x00ad
    mov dword ptr [rip + R04_REL32_S10_m_iStatus_XosDynamicLibrary_0HA], ebp # +0x00af
.Lbb_52_00b5:
    mov rcx, qword ptr [rbx + 0x38]                 # +0x00b5
    call qword ptr [rip + R04_REL32_S150_imp_FreeLibrary] # +0x00b9
    mov qword ptr [rbx + 0x38], rdi                 # +0x00bf
    test eax, eax                                   # +0x00c3
    jne .Lbb_52_00ec                                # +0x00c5
    call qword ptr [rip + R04_REL32_S149_imp_GetLastError] # +0x00c7
    mov edi, 0x80000015                             # +0x00cd
    mov ecx, 0x8000ffff                             # +0x00d2
    cmp eax, 0x7e                                   # +0x00d7
    cmovne edi, ecx                                 # +0x00da
    cmp dword ptr [rip + R05_REL32_1_S11_m_bQuietly_XosDynamicLibrary_0HA], 0 # +0x00dd
    jne .Lbb_52_00ec                                # +0x00e4
    mov dword ptr [rip + R04_REL32_S10_m_iStatus_XosDynamicLibrary_0HA], ecx # +0x00e6
.Lbb_52_00ec:
    cmp dword ptr [rbx + 0x58], 2                   # +0x00ec
    je .Lbb_52_011c                                 # +0x00f0
    mov rax, qword ptr [rbx]                        # +0x00f2
    mov edx, 1                                      # +0x00f5
    {load} mov rcx, rbx                             # +0x00fa
    call qword ptr [rax]                            # +0x00fd
.Lbb_52_00ff:
    {load} mov eax, edi                             # +0x00ff
.Lbb_52_0101:
    mov rbp, qword ptr [rsp + 0x30]                 # +0x0101
.Lbb_52_0106:
    mov rbx, qword ptr [rsp + 0x38]                 # +0x0106
    mov rsi, qword ptr [rsp + 0x40]                 # +0x010b
    mov rdi, qword ptr [rsp + 0x48]                 # +0x0110
    add rsp, 0x20                                   # +0x0115
    pop r14                                         # +0x0119
    ret                                             # +0x011b
.Lbb_52_011c:
    mov dword ptr [rbx + 0x58], 3                   # +0x011c
    mov dword ptr [rbx + 0x44], 0                   # +0x0123
    jmp .Lbb_52_00ff                                # +0x012a
.Lbb_52_012c:
    cmp eax, 2                                      # +0x012c
    je .Lbb_52_013f                                 # +0x012f
    mov rax, qword ptr [rcx]                        # +0x0131
    mov edx, 1                                      # +0x0134
    call qword ptr [rax]                            # +0x0139
.Lbb_52_013b:
    {load} mov eax, edi                             # +0x013b
    jmp .Lbb_52_0106                                # +0x013d
.Lbb_52_013f:
    mov dword ptr [rsi], 3                          # +0x013f
    {load} mov eax, edi                             # +0x0145
    jmp .Lbb_52_0106                                # +0x0147
end_52:

.section a54,"dr"
# COFF section 54: .text$mn
begin_54:
symbol_116:  # .text$mn
symbol_155:  # ?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
symbol_193:  # $LN42
    rex push rbx                                    # +0x0000
    push rbp                                        # +0x0002
    push r14                                        # +0x0003
    sub rsp, 0x20                                   # +0x0005
    {load} mov r14, rdx                             # +0x0009
    {load} mov rbx, rcx                             # +0x000c
    test rcx, rcx                                   # +0x000f
    {disp32} je .Lbb_54_013a                        # +0x0012
    cmp byte ptr [rcx], 0                           # +0x0018
    {disp32} je .Lbb_54_013a                        # +0x001b
    mov qword ptr [rsp + 0x40], rsi                 # +0x0021
    mov edx, 0x2e                                   # +0x0026
    mov qword ptr [rsp + 0x48], rdi                 # +0x002b
    mov qword ptr [rsp + 0x50], r15                 # +0x0030
    call R04_REL32_S143_strrchr                     # +0x0035
    {load} mov rsi, rax                             # +0x003a
    test rax, rax                                   # +0x003d
    je .Lbb_54_005a                                 # +0x0040
    mov rdx, qword ptr [rip + R04_REL32_S597_pDLL_EXTS_6_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z_4PAPEADA] # +0x0042
    {load} mov rcx, rax                             # +0x0049
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x004c
    test eax, eax                                   # +0x0052
    jne .Lbb_54_005a                                # +0x0054
    {load} xor ebp, ebp                             # +0x0056
    jmp .Lbb_54_005f                                # +0x0058
.Lbb_54_005a:
    mov ebp, 1                                      # +0x005a
.Lbb_54_005f:
    mov rcx, 0xffffffffffffffff                     # +0x005f
.Lbb_54_0066:
    inc rcx                                         # +0x0066
    cmp byte ptr [rbx + rcx], 0                     # +0x0069
    jne .Lbb_54_0066                                # +0x006d
    {load} mov eax, ebp                             # +0x006f
    lea r15, [rax*4 + 1]                            # +0x0071
    {load} add r15, rcx                             # +0x0079
    {load} mov rcx, r15                             # +0x007c
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x007f
    {load} mov r8, rbx                              # +0x0084
    {load} mov rdx, r15                             # +0x0087
    {load} mov rcx, rax                             # +0x008a
    {load} mov rdi, rax                             # +0x008d
    call qword ptr [rip + R04_REL32_S144_imp_strcpy_s] # +0x0090
    test ebp, ebp                                   # +0x0096
    je .Lbb_54_00e0                                 # +0x0098
    test rsi, rsi                                   # +0x009a
    je .Lbb_54_00cd                                 # +0x009d
    lea rbx, [rip + 8 + R04_REL32_S597_pDLL_EXTS_6_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z_4PAPEADA] # +0x009f
.Lbb_54_00a6:
    mov rdx, qword ptr [rbx]                        # +0x00a6
    test rdx, rdx                                   # +0x00a9
    je .Lbb_54_00cd                                 # +0x00ac
    {load} mov rcx, rsi                             # +0x00ae
    call qword ptr [rip + R04_REL32_S147_imp__stricmp] # +0x00b1
    add rbx, 8                                      # +0x00b7
    test eax, eax                                   # +0x00bb
    jne .Lbb_54_00a6                                # +0x00bd
    lea edx, [rax + 0x2e]                           # +0x00bf
    {load} mov rcx, rdi                             # +0x00c2
    call R04_REL32_S143_strrchr                     # +0x00c5
    mov byte ptr [rax], 0                           # +0x00ca
.Lbb_54_00cd:
    mov r8, qword ptr [rip + R04_REL32_S597_pDLL_EXTS_6_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z_4PAPEADA] # +0x00cd
    {load} mov rdx, r15                             # +0x00d4
    {load} mov rcx, rdi                             # +0x00d7
    call qword ptr [rip + R04_REL32_S145_imp_strcat_s] # +0x00da
.Lbb_54_00e0:
    mov edx, 0x5c                                   # +0x00e0
    {load} mov rcx, rdi                             # +0x00e5
    call R04_REL32_S143_strrchr                     # +0x00e8
    mov r15, qword ptr [rsp + 0x50]                 # +0x00ed
    mov rsi, qword ptr [rsp + 0x40]                 # +0x00f2
    mov qword ptr [r14], rax                        # +0x00f7
    test rax, rax                                   # +0x00fa
    jne .Lbb_54_0123                                # +0x00fd
    lea edx, [rax + 0x3a]                           # +0x00ff
    {load} mov rcx, rdi                             # +0x0102
    call R04_REL32_S143_strrchr                     # +0x0105
    test rax, rax                                   # +0x010a
    jne .Lbb_54_0123                                # +0x010d
    mov qword ptr [r14], rdi                        # +0x010f
    {load} mov rax, rdi                             # +0x0112
    mov rdi, qword ptr [rsp + 0x48]                 # +0x0115
    add rsp, 0x20                                   # +0x011a
    pop r14                                         # +0x011e
    pop rbp                                         # +0x0120
    pop rbx                                         # +0x0121
    ret                                             # +0x0122
.Lbb_54_0123:
    inc rax                                         # +0x0123
    mov qword ptr [r14], rax                        # +0x0126
    {load} mov rax, rdi                             # +0x0129
    mov rdi, qword ptr [rsp + 0x48]                 # +0x012c
    add rsp, 0x20                                   # +0x0131
    pop r14                                         # +0x0135
    pop rbp                                         # +0x0137
    pop rbx                                         # +0x0138
    ret                                             # +0x0139
.Lbb_54_013a:
    mov ecx, 1                                      # +0x013a
    call R04_REL32_S138_U_YAPEAX_K_Z                # +0x013f
    mov qword ptr [r14], rax                        # +0x0144
    mov byte ptr [rax], 0                           # +0x0147
    add rsp, 0x20                                   # +0x014a
    pop r14                                         # +0x014e
    pop rbp                                         # +0x0150
    pop rbx                                         # +0x0151
    ret                                             # +0x0152
end_54:

.section a56,"dr"
# COFF section 56: .text$mn
begin_56:
symbol_120:  # .text$mn
symbol_186:  # AddDLLSearchPath
    jmp R04_REL32_S165_AddDLLSearchPath_XosDynamicLibrary_SA_NPEAD_Z # +0x0000
end_56:

.section a58,"dr"
# COFF section 58: .text$mn
begin_58:
symbol_124:  # .text$mn
symbol_184:  # DLLsLoaded
symbol_218:  # $LN7
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rax, rcx                             # +0x0006
    {load} mov rbx, rdx                             # +0x0009
    mov rcx, qword ptr [rcx]                        # +0x000c
    test rcx, rcx                                   # +0x000f
    je .Lbb_58_0029                                 # +0x0012
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x0014
    mov rcx, qword ptr [rbx]                        # +0x0019
    call R04_REL32_S139_V_YAXPEAX_Z                 # +0x001c
    {load} xor eax, eax                             # +0x0021
    add rsp, 0x20                                   # +0x0023
    pop rbx                                         # +0x0027
    ret                                             # +0x0028
.Lbb_58_0029:
    {load} mov rcx, rax                             # +0x0029
    add rsp, 0x20                                   # +0x002c
    pop rbx                                         # +0x0030
    jmp R04_REL32_S169_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z # +0x0031
end_58:

.section a60,"dr"
# COFF section 60: .text$mn
begin_60:
symbol_128:  # .text$mn
symbol_185:  # ForceUnload
    jmp R04_REL32_S167_ForceUnload_XosDynamicLibrary_SAHPEAPEADH_Z # +0x0000
end_60:

.section a62,"dr"
# COFF section 62: .text$mn
begin_62:
symbol_132:  # .text$mn
symbol_187:  # RemoveDLLSearchPath
    jmp R04_REL32_S166_RemoveDLLSearchPath_XosDynamicLibrary_SAXPEAD_Z # +0x0000
end_62:

.section a64,"dr"
# COFF section 64: .xdata
begin_64:
symbol_219:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=9, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x09: ALLOC_SMALL 32
#   prologue +0x05: PUSH_NONVOL R14
#   prologue +0x03: PUSH_NONVOL RBP
#   prologue +0x02: PUSH_NONVOL RBX
symbol_221:  # $unwind$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .byte 0x01, 0x09, 0x04, 0x00
    .byte 0x09, 0x32, 0x05, 0xe0
    .byte 0x03, 0x50, 0x02, 0x30
end_64:

.section a65,"dr"
# COFF section 65: .pdata
begin_65:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_222:  # .pdata
symbol_224:  # $pdata$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .rva R03_ADDR32NB_S193_LN42  # begin RVA
    .rva R03_ADDR32NB_S193_LN42 + 33  # end RVA (exclusive)
    .rva R03_ADDR32NB_S221_unwind_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z  # unwind info RVA
end_65:

.section a66,"dr"
# COFF section 66: .xdata
begin_66:
symbol_225:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=20, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x14: SAVE_NONVOL R15, rsp+0x50
#   prologue +0x0f: SAVE_NONVOL RDI, rsp+0x48
#   prologue +0x05: SAVE_NONVOL RSI, rsp+0x40
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_227:  # $chain$2$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .byte 0x21, 0x14, 0x06, 0x00
    .byte 0x14, 0xf4, 0x0a, 0x00
    .byte 0x0f, 0x74, 0x09, 0x00
    .byte 0x05, 0x64, 0x08, 0x00
    .rva R03_ADDR32NB_S193_LN42
    .rva R03_ADDR32NB_S193_LN42 + 33
    .rva R03_ADDR32NB_S221_unwind_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z
end_66:

.section a67,"dr"
# COFF section 67: .pdata
begin_67:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_228:  # .pdata
symbol_230:  # $pdata$2$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .rva R03_ADDR32NB_S193_LN42 + 33  # begin RVA
    .rva R03_ADDR32NB_S193_LN42 + 255  # end RVA (exclusive)
    .rva R03_ADDR32NB_S227_chain_2_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z  # unwind info RVA
end_67:

.section a68,"dr"
# COFF section 68: .xdata
begin_68:
symbol_231:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x00: SAVE_NONVOL RDI, rsp+0x48
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_233:  # $chain$3$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .byte 0x21, 0x00, 0x02, 0x00
    .byte 0x00, 0x74, 0x09, 0x00
    .rva R03_ADDR32NB_S193_LN42
    .rva R03_ADDR32NB_S193_LN42 + 33
    .rva R03_ADDR32NB_S221_unwind_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z
end_68:

.section a69,"dr"
# COFF section 69: .pdata
begin_69:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_234:  # .pdata
symbol_236:  # $pdata$3$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .rva R03_ADDR32NB_S193_LN42 + 255  # begin RVA
    .rva R03_ADDR32NB_S193_LN42 + 291  # end RVA (exclusive)
    .rva R03_ADDR32NB_S233_chain_3_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z  # unwind info RVA
end_69:

.section a70,"dr"
# COFF section 70: .xdata
begin_70:
symbol_237:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x00: SAVE_NONVOL RDI, rsp+0x48
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_239:  # $chain$5$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .byte 0x21, 0x00, 0x02, 0x00
    .byte 0x00, 0x74, 0x09, 0x00
    .rva R03_ADDR32NB_S193_LN42
    .rva R03_ADDR32NB_S193_LN42 + 33
    .rva R03_ADDR32NB_S221_unwind_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z
end_70:

.section a71,"dr"
# COFF section 71: .pdata
begin_71:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_240:  # .pdata
symbol_242:  # $pdata$5$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .rva R03_ADDR32NB_S193_LN42 + 291  # begin RVA
    .rva R03_ADDR32NB_S193_LN42 + 314  # end RVA (exclusive)
    .rva R03_ADDR32NB_S239_chain_5_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z  # unwind info RVA
end_71:

.section a72,"dr"
# COFF section 72: .xdata
begin_72:
symbol_243:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_245:  # $chain$6$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S193_LN42
    .rva R03_ADDR32NB_S193_LN42 + 33
    .rva R03_ADDR32NB_S221_unwind_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z
end_72:

.section a73,"dr"
# COFF section 73: .pdata
begin_73:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_246:  # .pdata
symbol_248:  # $pdata$6$?VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z
    .rva R03_ADDR32NB_S193_LN42 + 314  # begin RVA
    .rva R03_ADDR32NB_S193_LN42 + 339  # end RVA (exclusive)
    .rva R03_ADDR32NB_S245_chain_6_VerifyName_XosDynamicLibrary_CAPEADPEBDAEAPEAD_Z  # unwind info RVA
end_73:

.section a74,"dr"
# COFF section 74: .xdata
begin_74:
symbol_249:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RBP, rsp+0x40
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x38
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_251:  # $unwind$?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x54, 0x08, 0x00
    .byte 0x0f, 0x34, 0x07, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_74:

.section a75,"dr"
# COFF section 75: .pdata
begin_75:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_252:  # .pdata
symbol_254:  # $pdata$?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
    .rva R03_ADDR32NB_S194_LN18  # begin RVA
    .rva R03_ADDR32NB_S194_LN18 + 63  # end RVA (exclusive)
    .rva R03_ADDR32NB_S251_unwind_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z  # unwind info RVA
end_75:

.section a76,"dr"
# COFF section 76: .xdata
begin_76:
symbol_255:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RSI, rsp+0x30
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_257:  # $chain$0$?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x64, 0x06, 0x00
    .rva R03_ADDR32NB_S194_LN18
    .rva R03_ADDR32NB_S194_LN18 + 63
    .rva R03_ADDR32NB_S251_unwind_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z
end_76:

.section a77,"dr"
# COFF section 77: .pdata
begin_77:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_258:  # .pdata
symbol_260:  # $pdata$0$?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
    .rva R03_ADDR32NB_S194_LN18 + 63  # begin RVA
    .rva R03_ADDR32NB_S194_LN18 + 140  # end RVA (exclusive)
    .rva R03_ADDR32NB_S257_chain_0_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z  # unwind info RVA
end_77:

.section a78,"dr"
# COFF section 78: .xdata
begin_78:
symbol_261:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_263:  # $chain$1$?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S194_LN18
    .rva R03_ADDR32NB_S194_LN18 + 63
    .rva R03_ADDR32NB_S251_unwind_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z
end_78:

.section a79,"dr"
# COFF section 79: .pdata
begin_79:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_264:  # .pdata
symbol_266:  # $pdata$1$?LinkLoadSymbol@XosDynamicLibrary@@CAPEADPEBD0@Z
    .rva R03_ADDR32NB_S194_LN18 + 140  # begin RVA
    .rva R03_ADDR32NB_S194_LN18 + 159  # end RVA (exclusive)
    .rva R03_ADDR32NB_S263_chain_1_LinkLoadSymbol_XosDynamicLibrary_CAPEADPEBD0_Z  # unwind info RVA
end_79:

.section a80,"dr"
# COFF section 80: .xdata
begin_80:
symbol_267:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 40
symbol_269:  # $unwind$?QuietlyFindCallAddress@XosDynamicLibrary@@IEAAPEAXPEBD0PEAPEAD@Z
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x42, 0x00, 0x00
end_80:

.section a81,"dr"
# COFF section 81: .pdata
begin_81:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_270:  # .pdata
symbol_272:  # $pdata$?QuietlyFindCallAddress@XosDynamicLibrary@@IEAAPEAXPEBD0PEAPEAD@Z
    .rva R03_ADDR32NB_S195_LN4  # begin RVA
    .rva R03_ADDR32NB_S195_LN4 + 26  # end RVA (exclusive)
    .rva R03_ADDR32NB_S269_unwind_QuietlyFindCallAddress_XosDynamicLibrary_IEAAPEAXPEBD0PEAPEAD_Z  # unwind info RVA
end_81:

.section a82,"dr"
# COFF section 82: .xdata
begin_82:
symbol_273:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_275:  # $unwind$??1XosDynamicLibrary@@MEAA@XZ
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_82:

.section a83,"dr"
# COFF section 83: .pdata
begin_83:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_276:  # .pdata
symbol_278:  # $pdata$??1XosDynamicLibrary@@MEAA@XZ
    .rva R03_ADDR32NB_S196_LN17  # begin RVA
    .rva R03_ADDR32NB_S196_LN17 + 131  # end RVA (exclusive)
    .rva R03_ADDR32NB_S275_unwind_1XosDynamicLibrary_MEAA_XZ  # unwind info RVA
end_83:

.section a84,"dr"
# COFF section 84: .xdata
begin_84:
symbol_279:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_281:  # $unwind$?FindLibrary@XosDynamicLibrary@@KAPEAV1@PEBDAEAPEAD1@Z
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x07, 0x00
    .byte 0x0f, 0x34, 0x06, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_84:

.section a85,"dr"
# COFF section 85: .pdata
begin_85:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_282:  # .pdata
symbol_284:  # $pdata$?FindLibrary@XosDynamicLibrary@@KAPEAV1@PEBDAEAPEAD1@Z
    .rva R03_ADDR32NB_S197_LN15  # begin RVA
    .rva R03_ADDR32NB_S197_LN15 + 123  # end RVA (exclusive)
    .rva R03_ADDR32NB_S281_unwind_FindLibrary_XosDynamicLibrary_KAPEAV1_PEBDAEAPEAD1_Z  # unwind info RVA
end_85:

.section a86,"dr"
# COFF section 86: .xdata
begin_86:
symbol_285:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL R15
#   prologue +0x04: PUSH_NONVOL R14
#   prologue +0x02: PUSH_NONVOL RBX
symbol_287:  # $unwind$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x32, 0x06, 0xf0
    .byte 0x04, 0xe0, 0x02, 0x30
end_86:

.section a87,"dr"
# COFF section 87: .pdata
begin_87:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_288:  # .pdata
symbol_290:  # $pdata$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 83  # end RVA (exclusive)
    .rva R03_ADDR32NB_S287_unwind_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_87:

.section a88,"dr"
# COFF section 88: .xdata
begin_88:
symbol_291:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RBP, rsp+0x40
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_293:  # $chain$0$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x54, 0x08, 0x00
    .rva R03_ADDR32NB_S198_LN32
    .rva R03_ADDR32NB_S198_LN32 + 83
    .rva R03_ADDR32NB_S287_unwind_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z
end_88:

.section a89,"dr"
# COFF section 89: .pdata
begin_89:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_294:  # .pdata
symbol_296:  # $pdata$0$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32 + 83  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 114  # end RVA (exclusive)
    .rva R03_ADDR32NB_S293_chain_0_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_89:

.section a90,"dr"
# COFF section 90: .xdata
begin_90:
symbol_297:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RDI, rsp+0x50
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_299:  # $chain$1$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x74, 0x0a, 0x00
    .rva R03_ADDR32NB_S198_LN32 + 83
    .rva R03_ADDR32NB_S198_LN32 + 114
    .rva R03_ADDR32NB_S293_chain_0_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z
end_90:

.section a91,"dr"
# COFF section 91: .pdata
begin_91:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_300:  # .pdata
symbol_302:  # $pdata$1$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32 + 114  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 129  # end RVA (exclusive)
    .rva R03_ADDR32NB_S299_chain_1_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_91:

.section a92,"dr"
# COFF section 92: .xdata
begin_92:
symbol_303:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RSI, rsp+0x48
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_305:  # $chain$2$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x64, 0x09, 0x00
    .rva R03_ADDR32NB_S198_LN32 + 114
    .rva R03_ADDR32NB_S198_LN32 + 129
    .rva R03_ADDR32NB_S299_chain_1_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z
end_92:

.section a93,"dr"
# COFF section 93: .pdata
begin_93:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_306:  # .pdata
symbol_308:  # $pdata$2$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32 + 129  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 183  # end RVA (exclusive)
    .rva R03_ADDR32NB_S305_chain_2_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_93:

.section a94,"dr"
# COFF section 94: .xdata
begin_94:
symbol_309:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_311:  # $chain$3$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S198_LN32 + 114
    .rva R03_ADDR32NB_S198_LN32 + 129
    .rva R03_ADDR32NB_S299_chain_1_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z
end_94:

.section a95,"dr"
# COFF section 95: .pdata
begin_95:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_312:  # .pdata
symbol_314:  # $pdata$3$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32 + 183  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 188  # end RVA (exclusive)
    .rva R03_ADDR32NB_S311_chain_3_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_95:

.section a96,"dr"
# COFF section 96: .xdata
begin_96:
symbol_315:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_317:  # $chain$4$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S198_LN32 + 83
    .rva R03_ADDR32NB_S198_LN32 + 114
    .rva R03_ADDR32NB_S293_chain_0_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z
end_96:

.section a97,"dr"
# COFF section 97: .pdata
begin_97:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_318:  # .pdata
symbol_320:  # $pdata$4$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32 + 188  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 193  # end RVA (exclusive)
    .rva R03_ADDR32NB_S317_chain_4_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_97:

.section a98,"dr"
# COFF section 98: .xdata
begin_98:
symbol_321:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_323:  # $chain$5$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S198_LN32
    .rva R03_ADDR32NB_S198_LN32 + 83
    .rva R03_ADDR32NB_S287_unwind_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z
end_98:

.section a99,"dr"
# COFF section 99: .pdata
begin_99:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_324:  # .pdata
symbol_326:  # $pdata$5$?LoadAndInitialize@XosDynamicLibrary@@IEAAPEAV1@PEAXW4ELoadState@1@@Z
    .rva R03_ADDR32NB_S198_LN32 + 193  # begin RVA
    .rva R03_ADDR32NB_S198_LN32 + 227  # end RVA (exclusive)
    .rva R03_ADDR32NB_S323_chain_5_LoadAndInitialize_XosDynamicLibrary_IEAAPEAV1_PEAXW4ELoadState_1_Z  # unwind info RVA
end_99:

.section a100,"dr"
# COFF section 100: .xdata
begin_100:
symbol_327:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_329:  # $unwind$?Reload@XosDynamicLibrary@@IEAAXXZ
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_100:

.section a101,"dr"
# COFF section 101: .pdata
begin_101:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_330:  # .pdata
symbol_332:  # $pdata$?Reload@XosDynamicLibrary@@IEAAXXZ
    .rva R03_ADDR32NB_S199_LN11  # begin RVA
    .rva R03_ADDR32NB_S199_LN11 + 74  # end RVA (exclusive)
    .rva R03_ADDR32NB_S329_unwind_Reload_XosDynamicLibrary_IEAAXXZ  # unwind info RVA
end_101:

.section a102,"dr"
# COFF section 102: .xdata
begin_102:
symbol_333:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 40
symbol_335:  # $unwind$?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x42, 0x00, 0x00
end_102:

.section a103,"dr"
# COFF section 103: .pdata
begin_103:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_336:  # .pdata
symbol_338:  # $pdata$?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
    .rva R03_ADDR32NB_S200_LN8  # begin RVA
    .rva R03_ADDR32NB_S200_LN8 + 36  # end RVA (exclusive)
    .rva R03_ADDR32NB_S335_unwind_ExtendSearchPaths_XosDynamicLibrary_KAXH_Z  # unwind info RVA
end_103:

.section a104,"dr"
# COFF section 104: .xdata
begin_104:
symbol_339:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RBX, rsp+0x20
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_341:  # $chain$0$?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x34, 0x04, 0x00
    .rva R03_ADDR32NB_S200_LN8
    .rva R03_ADDR32NB_S200_LN8 + 36
    .rva R03_ADDR32NB_S335_unwind_ExtendSearchPaths_XosDynamicLibrary_KAXH_Z
end_104:

.section a105,"dr"
# COFF section 105: .pdata
begin_105:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_342:  # .pdata
symbol_344:  # $pdata$0$?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
    .rva R03_ADDR32NB_S200_LN8 + 36  # begin RVA
    .rva R03_ADDR32NB_S200_LN8 + 113  # end RVA (exclusive)
    .rva R03_ADDR32NB_S341_chain_0_ExtendSearchPaths_XosDynamicLibrary_KAXH_Z  # unwind info RVA
end_105:

.section a106,"dr"
# COFF section 106: .xdata
begin_106:
symbol_345:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_347:  # $chain$1$?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S200_LN8
    .rva R03_ADDR32NB_S200_LN8 + 36
    .rva R03_ADDR32NB_S335_unwind_ExtendSearchPaths_XosDynamicLibrary_KAXH_Z
end_106:

.section a107,"dr"
# COFF section 107: .pdata
begin_107:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_348:  # .pdata
symbol_350:  # $pdata$1$?ExtendSearchPaths@XosDynamicLibrary@@KAXH@Z
    .rva R03_ADDR32NB_S200_LN8 + 113  # begin RVA
    .rva R03_ADDR32NB_S200_LN8 + 118  # end RVA (exclusive)
    .rva R03_ADDR32NB_S347_chain_1_ExtendSearchPaths_XosDynamicLibrary_KAXH_Z  # unwind info RVA
end_107:

.section a108,"dr"
# COFF section 108: .xdata
begin_108:
symbol_351:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_353:  # $unwind$?Initialize@XosDynamicLibrary@@UEAAHPEAX@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_108:

.section a109,"dr"
# COFF section 109: .pdata
begin_109:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_354:  # .pdata
symbol_356:  # $pdata$?Initialize@XosDynamicLibrary@@UEAAHPEAX@Z
    .rva R03_ADDR32NB_S201_LN18  # begin RVA
    .rva R03_ADDR32NB_S201_LN18 + 143  # end RVA (exclusive)
    .rva R03_ADDR32NB_S353_unwind_Initialize_XosDynamicLibrary_UEAAHPEAX_Z  # unwind info RVA
end_109:

.section a110,"dr"
# COFF section 110: .xdata
begin_110:
symbol_357:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=33, unwind slots=5, frame register=0, scaled frame offset=0.
#   prologue +0x0f: ALLOC_LARGE 1088
#   prologue +0x08: PUSH_NONVOL R15
#   prologue +0x06: PUSH_NONVOL R14
#   prologue +0x04: PUSH_NONVOL RDI
symbol_359:  # $unwind$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x19, 0x21, 0x05, 0x00
    .byte 0x0f, 0x01, 0x88, 0x00
    .byte 0x08, 0xf0, 0x06, 0xe0
    .byte 0x04, 0x70, 0x00, 0x00
    .rva R03_ADDR32NB_S190_GSHandlerCheck
    .byte 0x30, 0x04, 0x00, 0x00
end_110:

.section a111,"dr"
# COFF section 111: .pdata
begin_111:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_360:  # .pdata
symbol_362:  # $pdata$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 36  # end RVA (exclusive)
    .rva R03_ADDR32NB_S359_unwind_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_111:

.section a112,"dr"
# COFF section 112: .xdata
begin_112:
symbol_363:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=4, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x04: SAVE_NONVOL RBX, rsp+0x468
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_365:  # $chain$0$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x04, 0x02, 0x00
    .byte 0x04, 0x34, 0x8d, 0x00
    .rva R03_ADDR32NB_S202_LN55
    .rva R03_ADDR32NB_S202_LN55 + 36
    .rva R03_ADDR32NB_S359_unwind_LoadLib_XosDynamicLibrary_QEAAHXZ
end_112:

.section a113,"dr"
# COFF section 113: .pdata
begin_113:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_366:  # .pdata
symbol_368:  # $pdata$0$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55 + 36  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 45  # end RVA (exclusive)
    .rva R03_ADDR32NB_S365_chain_0_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_113:

.section a114,"dr"
# COFF section 114: .xdata
begin_114:
symbol_369:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=4, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x04: SAVE_NONVOL RSI, rsp+0x478
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_371:  # $chain$1$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x04, 0x02, 0x00
    .byte 0x04, 0x64, 0x8f, 0x00
    .rva R03_ADDR32NB_S202_LN55 + 36
    .rva R03_ADDR32NB_S202_LN55 + 45
    .rva R03_ADDR32NB_S365_chain_0_LoadLib_XosDynamicLibrary_QEAAHXZ
end_114:

.section a115,"dr"
# COFF section 115: .pdata
begin_115:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_372:  # .pdata
symbol_374:  # $pdata$1$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55 + 45  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 113  # end RVA (exclusive)
    .rva R03_ADDR32NB_S371_chain_1_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_115:

.section a116,"dr"
# COFF section 116: .xdata
begin_116:
symbol_375:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=8, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x08: SAVE_NONVOL RBP, rsp+0x470
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_377:  # $chain$2$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x08, 0x02, 0x00
    .byte 0x08, 0x54, 0x8e, 0x00
    .rva R03_ADDR32NB_S202_LN55 + 45
    .rva R03_ADDR32NB_S202_LN55 + 113
    .rva R03_ADDR32NB_S371_chain_1_LoadLib_XosDynamicLibrary_QEAAHXZ
end_116:

.section a117,"dr"
# COFF section 117: .pdata
begin_117:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_378:  # .pdata
symbol_380:  # $pdata$2$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55 + 113  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 261  # end RVA (exclusive)
    .rva R03_ADDR32NB_S377_chain_2_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_117:

.section a118,"dr"
# COFF section 118: .xdata
begin_118:
symbol_381:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_383:  # $chain$3$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S202_LN55 + 45
    .rva R03_ADDR32NB_S202_LN55 + 113
    .rva R03_ADDR32NB_S371_chain_1_LoadLib_XosDynamicLibrary_QEAAHXZ
end_118:

.section a119,"dr"
# COFF section 119: .pdata
begin_119:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_384:  # .pdata
symbol_386:  # $pdata$3$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55 + 261  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 290  # end RVA (exclusive)
    .rva R03_ADDR32NB_S383_chain_3_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_119:

.section a120,"dr"
# COFF section 120: .xdata
begin_120:
symbol_387:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_389:  # $chain$4$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S202_LN55 + 36
    .rva R03_ADDR32NB_S202_LN55 + 45
    .rva R03_ADDR32NB_S365_chain_0_LoadLib_XosDynamicLibrary_QEAAHXZ
end_120:

.section a121,"dr"
# COFF section 121: .pdata
begin_121:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_390:  # .pdata
symbol_392:  # $pdata$4$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55 + 290  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 520  # end RVA (exclusive)
    .rva R03_ADDR32NB_S389_chain_4_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_121:

.section a122,"dr"
# COFF section 122: .xdata
begin_122:
symbol_393:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_395:  # $chain$5$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S202_LN55
    .rva R03_ADDR32NB_S202_LN55 + 36
    .rva R03_ADDR32NB_S359_unwind_LoadLib_XosDynamicLibrary_QEAAHXZ
end_122:

.section a123,"dr"
# COFF section 123: .pdata
begin_123:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_396:  # .pdata
symbol_398:  # $pdata$5$?LoadLib@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S202_LN55 + 520  # begin RVA
    .rva R03_ADDR32NB_S202_LN55 + 704  # end RVA (exclusive)
    .rva R03_ADDR32NB_S395_chain_5_LoadLib_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_123:

.section a124,"dr"
# COFF section 124: .xdata
begin_124:
symbol_399:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=95, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x5f: SAVE_NONVOL RDI, rsp+0x38
#   prologue +0x5a: SAVE_NONVOL RSI, rsp+0x30
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x40
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RBP
symbol_401:  # $unwind$?AddDLLSearchPath@XosDynamicLibrary@@SA_NPEAD@Z
    .byte 0x01, 0x5f, 0x08, 0x00
    .byte 0x5f, 0x74, 0x07, 0x00
    .byte 0x5a, 0x64, 0x06, 0x00
    .byte 0x0a, 0x34, 0x08, 0x00
    .byte 0x0a, 0x32, 0x06, 0x50
end_124:

.section a125,"dr"
# COFF section 125: .pdata
begin_125:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_402:  # .pdata
symbol_404:  # $pdata$?AddDLLSearchPath@XosDynamicLibrary@@SA_NPEAD@Z
    .rva R03_ADDR32NB_S203_LN51  # begin RVA
    .rva R03_ADDR32NB_S203_LN51 + 390  # end RVA (exclusive)
    .rva R03_ADDR32NB_S401_unwind_AddDLLSearchPath_XosDynamicLibrary_SA_NPEAD_Z  # unwind info RVA
end_125:

.section a126,"dr"
# COFF section 126: .xdata
begin_126:
symbol_405:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x40
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RBP
symbol_407:  # $unwind$?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x08, 0x00
    .byte 0x0a, 0x32, 0x06, 0x50
end_126:

.section a127,"dr"
# COFF section 127: .pdata
begin_127:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_408:  # .pdata
symbol_410:  # $pdata$?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
    .rva R03_ADDR32NB_S204_LN45  # begin RVA
    .rva R03_ADDR32NB_S204_LN45 + 90  # end RVA (exclusive)
    .rva R03_ADDR32NB_S407_unwind_RemoveDLLSearchPath_XosDynamicLibrary_SAXPEAD_Z  # unwind info RVA
end_127:

.section a128,"dr"
# COFF section 128: .xdata
begin_128:
symbol_411:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=16, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x10: SAVE_NONVOL RDI, rsp+0x38
#   prologue +0x05: SAVE_NONVOL RSI, rsp+0x30
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_413:  # $chain$1$?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
    .byte 0x21, 0x10, 0x04, 0x00
    .byte 0x10, 0x74, 0x07, 0x00
    .byte 0x05, 0x64, 0x06, 0x00
    .rva R03_ADDR32NB_S204_LN45
    .rva R03_ADDR32NB_S204_LN45 + 90
    .rva R03_ADDR32NB_S407_unwind_RemoveDLLSearchPath_XosDynamicLibrary_SAXPEAD_Z
end_128:

.section a129,"dr"
# COFF section 129: .pdata
begin_129:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_414:  # .pdata
symbol_416:  # $pdata$1$?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
    .rva R03_ADDR32NB_S204_LN45 + 90  # begin RVA
    .rva R03_ADDR32NB_S204_LN45 + 293  # end RVA (exclusive)
    .rva R03_ADDR32NB_S413_chain_1_RemoveDLLSearchPath_XosDynamicLibrary_SAXPEAD_Z  # unwind info RVA
end_129:

.section a130,"dr"
# COFF section 130: .xdata
begin_130:
symbol_417:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_419:  # $chain$2$?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S204_LN45
    .rva R03_ADDR32NB_S204_LN45 + 90
    .rva R03_ADDR32NB_S407_unwind_RemoveDLLSearchPath_XosDynamicLibrary_SAXPEAD_Z
end_130:

.section a131,"dr"
# COFF section 131: .pdata
begin_131:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_420:  # .pdata
symbol_422:  # $pdata$2$?RemoveDLLSearchPath@XosDynamicLibrary@@SAXPEAD@Z
    .rva R03_ADDR32NB_S204_LN45 + 293  # begin RVA
    .rva R03_ADDR32NB_S204_LN45 + 304  # end RVA (exclusive)
    .rva R03_ADDR32NB_S419_chain_2_RemoveDLLSearchPath_XosDynamicLibrary_SAXPEAD_Z  # unwind info RVA
end_131:

.section a132,"dr"
# COFF section 132: .xdata
begin_132:
symbol_423:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=20, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x14: SAVE_NONVOL RSI, rsp+0x40
#   prologue +0x14: SAVE_NONVOL RBP, rsp+0x38
#   prologue +0x14: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x14: ALLOC_SMALL 32
#   prologue +0x10: PUSH_NONVOL RDI
symbol_425:  # $unwind$?ForceUnload@XosDynamicLibrary@@SAHPEAPEADH@Z
    .byte 0x01, 0x14, 0x08, 0x00
    .byte 0x14, 0x64, 0x08, 0x00
    .byte 0x14, 0x54, 0x07, 0x00
    .byte 0x14, 0x34, 0x06, 0x00
    .byte 0x14, 0x32, 0x10, 0x70
end_132:

.section a133,"dr"
# COFF section 133: .pdata
begin_133:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_426:  # .pdata
symbol_428:  # $pdata$?ForceUnload@XosDynamicLibrary@@SAHPEAPEADH@Z
    .rva R03_ADDR32NB_S205_LN38  # begin RVA
    .rva R03_ADDR32NB_S205_LN38 + 201  # end RVA (exclusive)
    .rva R03_ADDR32NB_S425_unwind_ForceUnload_XosDynamicLibrary_SAHPEAPEADH_Z  # unwind info RVA
end_133:

.section a134,"dr"
# COFF section 134: .xdata
begin_134:
symbol_429:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_431:  # $unwind$?ForceUnload@XosDynamicLibrary@@QEAAHXZ
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_134:

.section a135,"dr"
# COFF section 135: .pdata
begin_135:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_432:  # .pdata
symbol_434:  # $pdata$?ForceUnload@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S206_LN8  # begin RVA
    .rva R03_ADDR32NB_S206_LN8 + 68  # end RVA (exclusive)
    .rva R03_ADDR32NB_S431_unwind_ForceUnload_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_135:

.section a136,"dr"
# COFF section 136: .xdata
begin_136:
symbol_435:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=21, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x15: ALLOC_SMALL 96
#   prologue +0x11: PUSH_NONVOL R14
#   prologue +0x0f: PUSH_NONVOL R13
#   prologue +0x0d: PUSH_NONVOL RDI
#   prologue +0x0c: PUSH_NONVOL RSI
#   prologue +0x0b: PUSH_NONVOL RBX
symbol_437:  # $unwind$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .byte 0x01, 0x15, 0x06, 0x00
    .byte 0x15, 0xb2, 0x11, 0xe0
    .byte 0x0f, 0xd0, 0x0d, 0x70
    .byte 0x0c, 0x60, 0x0b, 0x30
end_136:

.section a137,"dr"
# COFF section 137: .pdata
begin_137:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_438:  # .pdata
symbol_440:  # $pdata$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .rva R03_ADDR32NB_S207_LN68  # begin RVA
    .rva R03_ADDR32NB_S207_LN68 + 97  # end RVA (exclusive)
    .rva R03_ADDR32NB_S437_unwind_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z  # unwind info RVA
end_137:

.section a138,"dr"
# COFF section 138: .xdata
begin_138:
symbol_441:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=18, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x12: SAVE_NONVOL R15, rsp+0x48
#   prologue +0x05: SAVE_NONVOL RBP, rsp+0x58
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_443:  # $chain$1$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .byte 0x21, 0x12, 0x04, 0x00
    .byte 0x12, 0xf4, 0x09, 0x00
    .byte 0x05, 0x54, 0x0b, 0x00
    .rva R03_ADDR32NB_S207_LN68
    .rva R03_ADDR32NB_S207_LN68 + 97
    .rva R03_ADDR32NB_S437_unwind_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z
end_138:

.section a139,"dr"
# COFF section 139: .pdata
begin_139:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_444:  # .pdata
symbol_446:  # $pdata$1$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .rva R03_ADDR32NB_S207_LN68 + 97  # begin RVA
    .rva R03_ADDR32NB_S207_LN68 + 254  # end RVA (exclusive)
    .rva R03_ADDR32NB_S443_chain_1_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z  # unwind info RVA
end_139:

.section a140,"dr"
# COFF section 140: .xdata
begin_140:
symbol_447:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL R12, rsp+0x50
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_449:  # $chain$2$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0xc4, 0x0a, 0x00
    .rva R03_ADDR32NB_S207_LN68 + 97
    .rva R03_ADDR32NB_S207_LN68 + 254
    .rva R03_ADDR32NB_S443_chain_1_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z
end_140:

.section a141,"dr"
# COFF section 141: .pdata
begin_141:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_450:  # .pdata
symbol_452:  # $pdata$2$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .rva R03_ADDR32NB_S207_LN68 + 254  # begin RVA
    .rva R03_ADDR32NB_S207_LN68 + 735  # end RVA (exclusive)
    .rva R03_ADDR32NB_S449_chain_2_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z  # unwind info RVA
end_141:

.section a142,"dr"
# COFF section 142: .xdata
begin_142:
symbol_453:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_455:  # $chain$3$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S207_LN68 + 97
    .rva R03_ADDR32NB_S207_LN68 + 254
    .rva R03_ADDR32NB_S443_chain_1_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z
end_142:

.section a143,"dr"
# COFF section 143: .pdata
begin_143:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_456:  # .pdata
symbol_458:  # $pdata$3$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .rva R03_ADDR32NB_S207_LN68 + 735  # begin RVA
    .rva R03_ADDR32NB_S207_LN68 + 745  # end RVA (exclusive)
    .rva R03_ADDR32NB_S455_chain_3_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z  # unwind info RVA
end_143:

.section a144,"dr"
# COFF section 144: .xdata
begin_144:
symbol_459:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_461:  # $chain$4$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S207_LN68
    .rva R03_ADDR32NB_S207_LN68 + 97
    .rva R03_ADDR32NB_S437_unwind_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z
end_144:

.section a145,"dr"
# COFF section 145: .pdata
begin_145:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_462:  # .pdata
symbol_464:  # $pdata$4$?LoadedDLLs@XosDynamicLibrary@@SAHPEAPEAPEAV1@PEAPEAH@Z
    .rva R03_ADDR32NB_S207_LN68 + 745  # begin RVA
    .rva R03_ADDR32NB_S207_LN68 + 766  # end RVA (exclusive)
    .rva R03_ADDR32NB_S461_chain_4_LoadedDLLs_XosDynamicLibrary_SAHPEAPEAPEAV1_PEAPEAH_Z  # unwind info RVA
end_145:

.section a146,"dr"
# COFF section 146: .xdata
begin_146:
symbol_465:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_467:  # $unwind$?FindFunction@XosDynamicLibrary@@QEBAPEAVXosDynamicFunction@@PEBD0PEAPEAD@Z
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_146:

.section a147,"dr"
# COFF section 147: .pdata
begin_147:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_468:  # .pdata
symbol_470:  # $pdata$?FindFunction@XosDynamicLibrary@@QEBAPEAVXosDynamicFunction@@PEBD0PEAPEAD@Z
    .rva R03_ADDR32NB_S208_LN10  # begin RVA
    .rva R03_ADDR32NB_S208_LN10 + 46  # end RVA (exclusive)
    .rva R03_ADDR32NB_S467_unwind_FindFunction_XosDynamicLibrary_QEBAPEAVXosDynamicFunction_PEBD0PEAPEAD_Z  # unwind info RVA
end_147:

.section a148,"dr"
# COFF section 148: .xdata
begin_148:
symbol_471:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=20, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x14: SAVE_NONVOL RSI, rsp+0x40
#   prologue +0x14: SAVE_NONVOL RBP, rsp+0x38
#   prologue +0x14: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x14: ALLOC_SMALL 32
#   prologue +0x10: PUSH_NONVOL RDI
symbol_473:  # $unwind$?FindCallAddress@XosDynamicLibrary@@QEAAPEAXPEBD0PEAPEAD@Z
    .byte 0x01, 0x14, 0x08, 0x00
    .byte 0x14, 0x64, 0x08, 0x00
    .byte 0x14, 0x54, 0x07, 0x00
    .byte 0x14, 0x34, 0x06, 0x00
    .byte 0x14, 0x32, 0x10, 0x70
end_148:

.section a149,"dr"
# COFF section 149: .pdata
begin_149:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_474:  # .pdata
symbol_476:  # $pdata$?FindCallAddress@XosDynamicLibrary@@QEAAPEAXPEBD0PEAPEAD@Z
    .rva R03_ADDR32NB_S209_LN34  # begin RVA
    .rva R03_ADDR32NB_S209_LN34 + 226  # end RVA (exclusive)
    .rva R03_ADDR32NB_S473_unwind_FindCallAddress_XosDynamicLibrary_QEAAPEAXPEBD0PEAPEAD_Z  # unwind info RVA
end_149:

.section a150,"dr"
# COFF section 150: .xdata
begin_150:
symbol_477:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=21, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x15: SAVE_NONVOL RDI, rsp+0x48
#   prologue +0x15: SAVE_NONVOL RSI, rsp+0x40
#   prologue +0x15: SAVE_NONVOL RBX, rsp+0x38
#   prologue +0x15: ALLOC_SMALL 32
#   prologue +0x11: PUSH_NONVOL R14
symbol_479:  # $unwind$?Unload@XosDynamicLibrary@@QEAAHXZ
    .byte 0x01, 0x15, 0x08, 0x00
    .byte 0x15, 0x74, 0x09, 0x00
    .byte 0x15, 0x64, 0x08, 0x00
    .byte 0x15, 0x34, 0x07, 0x00
    .byte 0x15, 0x32, 0x11, 0xe0
end_150:

.section a151,"dr"
# COFF section 151: .pdata
begin_151:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_480:  # .pdata
symbol_482:  # $pdata$?Unload@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S210_LN51  # begin RVA
    .rva R03_ADDR32NB_S210_LN51 + 66  # end RVA (exclusive)
    .rva R03_ADDR32NB_S479_unwind_Unload_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_151:

.section a152,"dr"
# COFF section 152: .xdata
begin_152:
symbol_483:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RBP, rsp+0x30
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_485:  # $chain$0$?Unload@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x54, 0x06, 0x00
    .rva R03_ADDR32NB_S210_LN51
    .rva R03_ADDR32NB_S210_LN51 + 66
    .rva R03_ADDR32NB_S479_unwind_Unload_XosDynamicLibrary_QEAAHXZ
end_152:

.section a153,"dr"
# COFF section 153: .pdata
begin_153:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_486:  # .pdata
symbol_488:  # $pdata$0$?Unload@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S210_LN51 + 66  # begin RVA
    .rva R03_ADDR32NB_S210_LN51 + 262  # end RVA (exclusive)
    .rva R03_ADDR32NB_S485_chain_0_Unload_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_153:

.section a154,"dr"
# COFF section 154: .xdata
begin_154:
symbol_489:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_491:  # $chain$1$?Unload@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S210_LN51
    .rva R03_ADDR32NB_S210_LN51 + 66
    .rva R03_ADDR32NB_S479_unwind_Unload_XosDynamicLibrary_QEAAHXZ
end_154:

.section a155,"dr"
# COFF section 155: .pdata
begin_155:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_492:  # .pdata
symbol_494:  # $pdata$1$?Unload@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S210_LN51 + 262  # begin RVA
    .rva R03_ADDR32NB_S210_LN51 + 284  # end RVA (exclusive)
    .rva R03_ADDR32NB_S491_chain_1_Unload_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_155:

.section a156,"dr"
# COFF section 156: .xdata
begin_156:
symbol_495:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x00: SAVE_NONVOL RBP, rsp+0x30
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_497:  # $chain$2$?Unload@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x00, 0x02, 0x00
    .byte 0x00, 0x54, 0x06, 0x00
    .rva R03_ADDR32NB_S210_LN51
    .rva R03_ADDR32NB_S210_LN51 + 66
    .rva R03_ADDR32NB_S479_unwind_Unload_XosDynamicLibrary_QEAAHXZ
end_156:

.section a157,"dr"
# COFF section 157: .pdata
begin_157:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_498:  # .pdata
symbol_500:  # $pdata$2$?Unload@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S210_LN51 + 284  # begin RVA
    .rva R03_ADDR32NB_S210_LN51 + 300  # end RVA (exclusive)
    .rva R03_ADDR32NB_S497_chain_2_Unload_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_157:

.section a158,"dr"
# COFF section 158: .xdata
begin_158:
symbol_501:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_503:  # $chain$3$?Unload@XosDynamicLibrary@@QEAAHXZ
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S210_LN51
    .rva R03_ADDR32NB_S210_LN51 + 66
    .rva R03_ADDR32NB_S479_unwind_Unload_XosDynamicLibrary_QEAAHXZ
end_158:

.section a159,"dr"
# COFF section 159: .pdata
begin_159:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_504:  # .pdata
symbol_506:  # $pdata$3$?Unload@XosDynamicLibrary@@QEAAHXZ
    .rva R03_ADDR32NB_S210_LN51 + 300  # begin RVA
    .rva R03_ADDR32NB_S210_LN51 + 329  # end RVA (exclusive)
    .rva R03_ADDR32NB_S503_chain_3_Unload_XosDynamicLibrary_QEAAHXZ  # unwind info RVA
end_159:

.section a160,"dr"
# COFF section 160: .xdata
begin_160:
symbol_507:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x40
#   prologue +0x0a: ALLOC_SMALL 48
#   prologue +0x06: PUSH_NONVOL RDI
symbol_509:  # $unwind$?Load@XosDynamicLibrary@@SAPEAV1@PEBDPEAX@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x08, 0x00
    .byte 0x0a, 0x52, 0x06, 0x70
end_160:

.section a161,"dr"
# COFF section 161: .pdata
begin_161:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_510:  # .pdata
symbol_512:  # $pdata$?Load@XosDynamicLibrary@@SAPEAV1@PEBDPEAX@Z
    .rva R03_ADDR32NB_S211_LN16  # begin RVA
    .rva R03_ADDR32NB_S211_LN16 + 196  # end RVA (exclusive)
    .rva R03_ADDR32NB_S509_unwind_Load_XosDynamicLibrary_SAPEAV1_PEBDPEAX_Z  # unwind info RVA
end_161:

.section a162,"dr"
# COFF section 162: .xdata
begin_162:
symbol_513:  # .xdata
# UNWIND_INFO v1, flags=2, prologue length=22, unwind slots=10, frame register=0, scaled frame offset=0.
#   prologue +0x16: SAVE_NONVOL RBP, rsp+0x68
#   prologue +0x16: SAVE_NONVOL RBX, rsp+0x60
#   prologue +0x16: ALLOC_SMALL 48
#   prologue +0x12: PUSH_NONVOL R15
#   prologue +0x10: PUSH_NONVOL R14
#   prologue +0x0e: PUSH_NONVOL R13
#   prologue +0x0c: PUSH_NONVOL RDI
#   prologue +0x0b: PUSH_NONVOL RSI
symbol_515:  # $unwind$?FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x11, 0x16, 0x0a, 0x00
    .byte 0x16, 0x54, 0x0d, 0x00
    .byte 0x16, 0x34, 0x0c, 0x00
    .byte 0x16, 0x52, 0x12, 0xf0
    .byte 0x10, 0xe0, 0x0e, 0xd0
    .byte 0x0c, 0x70, 0x0b, 0x60
    .rva R03_ADDR32NB_S189_CxxFrameHandler4
    .rva R03_ADDR32NB_S521_cppxdata_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_162:

.section a163,"dr"
# COFF section 163: .pdata
begin_163:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_516:  # .pdata
symbol_518:  # $pdata$?FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .rva R03_ADDR32NB_S212_LN21  # begin RVA
    .rva R03_ADDR32NB_S212_LN21 + 301  # end RVA (exclusive)
    .rva R03_ADDR32NB_S515_unwind_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z  # unwind info RVA
end_163:

.section a164,"dr"
# COFF section 164: .xdata
begin_164:
symbol_519:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_521:  # $cppxdata$?FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x28
    .rva R03_ADDR32NB_S524_stateUnwindMap_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
    .rva R03_ADDR32NB_S527_ip2state_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_164:

.section a165,"dr"
# COFF section 165: .xdata
begin_165:
symbol_522:  # .xdata
# FH4 state unwind map. Fields that address another section carry an RVA relocation.
symbol_524:  # $stateUnwindMap$?FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x02, 0x0e
    .rva R03_ADDR32NB_S188_dtor_0_0_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA
end_165:

.section a166,"dr"
# COFF section 166: .xdata
begin_166:
symbol_525:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_527:  # $ip2state$?FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z
    .byte 0x06, 0x94, 0x00, 0x96
    .byte 0x02, 0xd6, 0x00
end_166:

.section a167,"dr"
# COFF section 167: .xdata
begin_167:
symbol_528:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBP
symbol_530:  # $unwind$?dtor$0@?0??FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z@4HA
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x50
end_167:

.section a168,"dr"
# COFF section 168: .pdata
begin_168:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_531:  # .pdata
symbol_533:  # $pdata$?dtor$0@?0??FindSymbol@XosDynamicLibrary@@UEAAHPEADPEAPEAVXosDynamicFunction@@PEBD@Z@4HA
    .rva R03_ADDR32NB_S188_dtor_0_0_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA  # begin RVA
    .rva R03_ADDR32NB_S188_dtor_0_0_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA + 29  # end RVA (exclusive)
    .rva R03_ADDR32NB_S530_unwind_dtor_0_0_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z_4HA  # unwind info RVA
end_168:

.section a169,"dr"
# COFF section 169: .xdata
begin_169:
symbol_534:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 40
symbol_536:  # $unwind$?GetFullPath@XosDynamicLibrary@@QEBAPEADXZ
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x42, 0x00, 0x00
end_169:

.section a170,"dr"
# COFF section 170: .pdata
begin_170:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_537:  # .pdata
symbol_539:  # $pdata$?GetFullPath@XosDynamicLibrary@@QEBAPEADXZ
    .rva R03_ADDR32NB_S213_LN4  # begin RVA
    .rva R03_ADDR32NB_S213_LN4 + 39  # end RVA (exclusive)
    .rva R03_ADDR32NB_S536_unwind_GetFullPath_XosDynamicLibrary_QEBAPEADXZ  # unwind info RVA
end_170:

.section a171,"dr"
# COFF section 171: .xdata
begin_171:
symbol_540:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_542:  # $unwind$??_GXosDynamicLibrary@@MEAAPEAXI@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_171:

.section a172,"dr"
# COFF section 172: .pdata
begin_172:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_543:  # .pdata
symbol_545:  # $pdata$??_GXosDynamicLibrary@@MEAAPEAXI@Z
    .rva R03_ADDR32NB_S214_LN8  # begin RVA
    .rva R03_ADDR32NB_S214_LN8 + 52  # end RVA (exclusive)
    .rva R03_ADDR32NB_S542_unwind__GXosDynamicLibrary_MEAAPEAXI_Z  # unwind info RVA
end_172:

.section a173,"dr"
# COFF section 173: .xdata
begin_173:
symbol_546:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_548:  # $unwind$??1XosDynamicFunction@@MEAA@XZ
    .byte 0x19, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
    .rva R03_ADDR32NB_S189_CxxFrameHandler4
    .rva R03_ADDR32NB_S554_cppxdata_1XosDynamicFunction_MEAA_XZ
end_173:

.section a174,"dr"
# COFF section 174: .pdata
begin_174:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_549:  # .pdata
symbol_551:  # $pdata$??1XosDynamicFunction@@MEAA@XZ
    .rva R03_ADDR32NB_S215_LN8  # begin RVA
    .rva R03_ADDR32NB_S215_LN8 + 88  # end RVA (exclusive)
    .rva R03_ADDR32NB_S548_unwind_1XosDynamicFunction_MEAA_XZ  # unwind info RVA
end_174:

.section a175,"dr"
# COFF section 175: .xdata
begin_175:
symbol_552:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_554:  # $cppxdata$??1XosDynamicFunction@@MEAA@XZ
    .byte 0x60
    .rva R03_ADDR32NB_S557_ip2state_1XosDynamicFunction_MEAA_XZ
end_175:

.section a176,"dr"
# COFF section 176: .xdata
begin_176:
symbol_555:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_557:  # $ip2state$??1XosDynamicFunction@@MEAA@XZ
    .byte 0x02, 0x98, 0x00
end_176:

.section a177,"dr"
# COFF section 177: .xdata
begin_177:
symbol_558:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_560:  # $unwind$?Find@XosDynamicFunction@@SAHPEAD0PEAPEAV1@PEAXPEBD@Z
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x07, 0x00
    .byte 0x0f, 0x34, 0x06, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_177:

.section a178,"dr"
# COFF section 178: .pdata
begin_178:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_561:  # .pdata
symbol_563:  # $pdata$?Find@XosDynamicFunction@@SAHPEAD0PEAPEAV1@PEAXPEBD@Z
    .rva R03_ADDR32NB_S216_LN15  # begin RVA
    .rva R03_ADDR32NB_S216_LN15 + 140  # end RVA (exclusive)
    .rva R03_ADDR32NB_S560_unwind_Find_XosDynamicFunction_SAHPEAD0PEAPEAV1_PEAXPEBD_Z  # unwind info RVA
end_178:

.section a179,"dr"
# COFF section 179: .xdata
begin_179:
symbol_564:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_566:  # $unwind$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x19, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
    .rva R03_ADDR32NB_S189_CxxFrameHandler4
    .rva R03_ADDR32NB_S572_cppxdata__GXosDynamicFunction_MEAAPEAXI_Z
end_179:

.section a180,"dr"
# COFF section 180: .pdata
begin_180:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_567:  # .pdata
symbol_569:  # $pdata$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .rva R03_ADDR32NB_S217_LN13  # begin RVA
    .rva R03_ADDR32NB_S217_LN13 + 121  # end RVA (exclusive)
    .rva R03_ADDR32NB_S566_unwind__GXosDynamicFunction_MEAAPEAXI_Z  # unwind info RVA
end_180:

.section a181,"dr"
# COFF section 181: .xdata
begin_181:
symbol_570:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_572:  # $cppxdata$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x68
    .rva R03_ADDR32NB_S575_stateUnwindMap__GXosDynamicFunction_MEAAPEAXI_Z
    .rva R03_ADDR32NB_S578_ip2state__GXosDynamicFunction_MEAAPEAXI_Z
end_181:

.section a182,"dr"
# COFF section 182: .xdata
begin_182:
symbol_573:  # .xdata
# FH4 state unwind map. Fields that address another section carry an RVA relocation.
symbol_575:  # $stateUnwindMap$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x02, 0x0e
    .rva R03_ADDR32NB_S140_std_terminate
end_182:

.section a183,"dr"
# COFF section 183: .xdata
begin_183:
symbol_576:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_578:  # $ip2state$??_GXosDynamicFunction@@MEAAPEAXI@Z
    .byte 0x02, 0xa4, 0x02
end_183:

.section a184,"dr"
# COFF section 184: .xdata
begin_184:
symbol_579:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_581:  # $unwind$DLLsLoaded
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_184:

.section a185,"dr"
# COFF section 185: .pdata
begin_185:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_582:  # .pdata
symbol_584:  # $pdata$DLLsLoaded
    .rva R03_ADDR32NB_S218_LN7  # begin RVA
    .rva R03_ADDR32NB_S218_LN7 + 54  # end RVA (exclusive)
    .rva R03_ADDR32NB_S581_unwind_DLLsLoaded  # unwind info RVA
end_185:

.section a186,"dr"
# COFF section 186: .rdata
begin_186:
symbol_586:  # .rdata
symbol_588:  # ??_C@_00CNPNBAHC@@
    .byte 0x00
end_186:

.section a187,"dr"
# COFF section 187: .rdata
begin_187:
symbol_589:  # .rdata
    .quad R01_ADDR64_S654_R4XosDynamicLibrary_6B
symbol_591:  # ??_7XosDynamicLibrary@@6B@
    .quad R01_ADDR64_S177_EXosDynamicLibrary_MEAAPEAXI_Z
    .quad R01_ADDR64_S163_Initialize_XosDynamicLibrary_UEAAHPEAX_Z
    .quad R01_ADDR64_S174_FindSymbol_XosDynamicLibrary_UEAAHPEADPEAPEAVXosDynamicFunction_PEBD_Z
end_187:

.section a188,"dr"
# COFF section 188: .rdata
begin_188:
symbol_592:  # .rdata
    .quad R01_ADDR64_S639_R4XosDynamicFunction_6B
symbol_594:  # ??_7XosDynamicFunction@@6B@
    .quad R01_ADDR64_S182_EXosDynamicFunction_MEAAPEAXI_Z
end_188:

.section a189,"dr"
# COFF section 189: .data
begin_189:
symbol_595:  # .data
symbol_597:  # ?pDLL_EXTS@?6??VerifyName@XosDynamicLibrary@@CAPEADPEBDAEAPEAD@Z@4PAPEADA
    .quad R01_ADDR64_S600_C__04HLONOPDM_4dll
    .quad R01_ADDR64_S603_C__03CKIEFJIP_4so
    .quad R01_ADDR64_S606_C__04GFGLBHBJ_4shr
    .quad R01_ADDR64_S609_C__04JLMDILM_4exe
    .zero 8
end_189:

.section a190,"dr"
# COFF section 190: .rdata
begin_190:
symbol_598:  # .rdata
symbol_600:  # ??_C@_04HLONOPDM@?4dll@
    .ascii ".dll\000"
end_190:

.section a191,"dr"
# COFF section 191: .rdata
begin_191:
symbol_601:  # .rdata
symbol_603:  # ??_C@_03CKIEFJIP@?4so@
    .ascii ".so\000"
end_191:

.section a192,"dr"
# COFF section 192: .rdata
begin_192:
symbol_604:  # .rdata
symbol_606:  # ??_C@_04GFGLBHBJ@?4shr@
    .ascii ".shr\000"
end_192:

.section a193,"dr"
# COFF section 193: .rdata
begin_193:
symbol_607:  # .rdata
symbol_609:  # ??_C@_04JLMDILM@?4exe@
    .ascii ".exe\000"
end_193:

.section a194,"dr"
# COFF section 194: .rdata
begin_194:
symbol_610:  # .rdata
symbol_612:  # ??_C@_0L@EJIEJOHD@DLLsLoaded@
    .ascii "DLLsLoaded\000"
end_194:

.section a195,"dr"
# COFF section 195: .rdata
begin_195:
symbol_613:  # .rdata
symbol_615:  # ??_C@_0M@KDBBNFPC@ForceUnload@
    .ascii "ForceUnload\000"
end_195:

.section a196,"dr"
# COFF section 196: .rdata
begin_196:
symbol_616:  # .rdata
symbol_618:  # ??_C@_0BB@OLNKDJGE@AddDLLSearchPath@
    .ascii "AddDLLSearchPath\000"
end_196:

.section a197,"dr"
# COFF section 197: .rdata
begin_197:
symbol_619:  # .rdata
symbol_621:  # ??_C@_0BE@MEINDEKP@RemoveDLLSearchPath@
    .ascii "RemoveDLLSearchPath\000"
end_197:

.section a198,"dr"
# COFF section 198: .rdata
begin_198:
symbol_622:  # .rdata
symbol_624:  # ??_C@_0N@JDJKKOHE@ATInitialize@
    .ascii "ATInitialize\000"
end_198:

.section a199,"dr"
# COFF section 199: .rdata
begin_199:
symbol_625:  # .rdata
symbol_627:  # ??_C@_0O@FIHIBCKH@DLLInitialize@
    .ascii "DLLInitialize\000"
end_199:

.section a200,"dr"
# COFF section 200: .rdata
begin_200:
symbol_628:  # .rdata
symbol_630:  # ??_C@_01KICIPPFI@?2@
    .byte 0x5c, 0x00
end_200:

.section a202,"dr"
# COFF section 202: .rdata
begin_202:
symbol_634:  # .rdata
symbol_636:  # ??_C@_0M@MOJGKDOC@DLLFinalize@
    .ascii "DLLFinalize\000"
end_202:

.section a203,"dr"
# COFF section 203: .rdata$r
begin_203:
symbol_637:  # .rdata$r
symbol_639:  # ??_R4XosDynamicFunction@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S642_R0_AVXosDynamicFunction_8
    .rva R03_ADDR32NB_S645_R3XosDynamicFunction_8
    .rva R03_ADDR32NB_S639_R4XosDynamicFunction_6B
    .zero 12
end_203:

.section a204,"dr"
# COFF section 204: .data$rs
begin_204:
symbol_640:  # .data$rs
symbol_642:  # ??_R0?AVXosDynamicFunction@@@8
    .quad R01_ADDR64_S585_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "XosDynamicFunction@@\000"
end_204:

.section a205,"dr"
# COFF section 205: .rdata$r
begin_205:
symbol_643:  # .rdata$r
symbol_645:  # ??_R3XosDynamicFunction@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S648_R2XosDynamicFunction_8
    .zero 4
end_205:

.section a206,"dr"
# COFF section 206: .rdata$r
begin_206:
symbol_646:  # .rdata$r
symbol_648:  # ??_R2XosDynamicFunction@@8
    .rva R03_ADDR32NB_S651_R1A_0A_EA_XosDynamicFunction_8
    .zero 8
end_206:

.section a207,"dr"
# COFF section 207: .rdata$r
begin_207:
symbol_649:  # .rdata$r
symbol_651:  # ??_R1A@?0A@EA@XosDynamicFunction@@8
    .rva R03_ADDR32NB_S642_R0_AVXosDynamicFunction_8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S645_R3XosDynamicFunction_8
    .zero 8
end_207:

.section a208,"dr"
# COFF section 208: .rdata$r
begin_208:
symbol_652:  # .rdata$r
symbol_654:  # ??_R4XosDynamicLibrary@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S657_R0_AVXosDynamicLibrary_8
    .rva R03_ADDR32NB_S660_R3XosDynamicLibrary_8
    .rva R03_ADDR32NB_S654_R4XosDynamicLibrary_6B
    .zero 12
end_208:

.section a209,"dr"
# COFF section 209: .data$rs
begin_209:
symbol_655:  # .data$rs
symbol_657:  # ??_R0?AVXosDynamicLibrary@@@8
    .quad R01_ADDR64_S585_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "XosDynamicLibrary@@\000"
end_209:

.section a210,"dr"
# COFF section 210: .rdata$r
begin_210:
symbol_658:  # .rdata$r
symbol_660:  # ??_R3XosDynamicLibrary@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S663_R2XosDynamicLibrary_8
    .zero 4
end_210:

.section a211,"dr"
# COFF section 211: .rdata$r
begin_211:
symbol_661:  # .rdata$r
symbol_663:  # ??_R2XosDynamicLibrary@@8
    .rva R03_ADDR32NB_S666_R1A_0A_EA_XosDynamicLibrary_8
    .zero 8
end_211:

.section a212,"dr"
# COFF section 212: .rdata$r
begin_212:
symbol_664:  # .rdata$r
symbol_666:  # ??_R1A@?0A@EA@XosDynamicLibrary@@8
    .rva R03_ADDR32NB_S657_R0_AVXosDynamicLibrary_8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S660_R3XosDynamicLibrary_8
    .zero 8
end_212:
