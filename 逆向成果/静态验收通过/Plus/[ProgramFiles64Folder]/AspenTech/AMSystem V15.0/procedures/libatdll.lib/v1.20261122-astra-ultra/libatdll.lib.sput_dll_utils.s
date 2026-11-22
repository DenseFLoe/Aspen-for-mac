# AMD64 COFF member .\Release\sput_dll_utils.obj
# External reference identifiers encode the original relocation type, COFF symbol index and name.
.intel_syntax noprefix

.section a1,"dr"
# COFF section 1: .drectve
begin_1:
symbol_3:  # .drectve
    .ascii "   -nodefaultlib:msvcirt /FAILIFMISMATCH:\"_CRT_STDIO_ISO_WIDE_SPECIFIERS=0\" /DEFAULTLIB:\"uuid.lib\" /DEFAULTLIB:\"uuid.lib\" /FAILIFMISMATCH:\"_MSC_VER=1900\" /FAILIFMISMATCH:\"_ITERATOR_DEBUG_LEVEL=0\" /FAILIFMISMATCH:\"RuntimeLibrary=MD_DynamicRelease\" /DEFAULTLIB:\"msvcprt\" /FAILIFMISMATCH:\"annotate_string=0\" /FAILIFMISMATCH:\"annotate_vector=0\" /DEFAULTLIB:\"MSVCRT\" /DEFAULTLIB:\"OLDNAMES\" /EXPORT:GetDLLInitializationData /EXPORT:RegisterDummyOptionsHandler /EXPORT:ATInitialize "
end_1:

.section a3,"dr"
# COFF section 3: .rdata
begin_3:
symbol_9:  # .rdata
    .quad R01_ADDR64_S17_R4ACMOptionsHandler_6B
symbol_11:  # ??_7ACMOptionsHandler@@6B@
    .quad R01_ADDR64_S7_purecall
end_3:

.section a4,"dr"
# COFF section 4: .rdata
begin_4:
symbol_12:  # .rdata
symbol_14:  # ?_Fake_alloc@std@@3U_Fake_allocator@1@B
    .byte 0x00
end_4:

.section a5,"dr"
# COFF section 5: .rdata$r
begin_5:
symbol_15:  # .rdata$r
symbol_17:  # ??_R4ACMOptionsHandler@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S20_R0_AVACMOptionsHandler_8
    .rva R03_ADDR32NB_S23_R3ACMOptionsHandler_8
    .rva R03_ADDR32NB_S17_R4ACMOptionsHandler_6B
    .zero 12
end_5:

.section a6,"dr"
# COFF section 6: .data$rs
begin_6:
symbol_18:  # .data$rs
symbol_20:  # ??_R0?AVACMOptionsHandler@@@8
    .quad R01_ADDR64_S8_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "ACMOptionsHandler@@\000"
end_6:

.section a7,"dr"
# COFF section 7: .rdata$r
begin_7:
symbol_21:  # .rdata$r
symbol_23:  # ??_R3ACMOptionsHandler@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S26_R2ACMOptionsHandler_8
    .zero 4
end_7:

.section a8,"dr"
# COFF section 8: .rdata$r
begin_8:
symbol_24:  # .rdata$r
symbol_26:  # ??_R2ACMOptionsHandler@@8
    .rva R03_ADDR32NB_S29_R1A_0A_EA_ACMOptionsHandler_8
    .zero 8
end_8:

.section a9,"dr"
# COFF section 9: .rdata$r
begin_9:
symbol_27:  # .rdata$r
symbol_29:  # ??_R1A@?0A@EA@ACMOptionsHandler@@8
    .rva R03_ADDR32NB_S20_R0_AVACMOptionsHandler_8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S23_R3ACMOptionsHandler_8
    .zero 8
end_9:

.section a10,"dr"
# COFF section 10: .rdata$r
begin_10:
symbol_30:  # .rdata$r
symbol_32:  # ??_R4ProxyOptionsHandler@@6B@
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S35_R0_AVProxyOptionsHandler_8
    .rva R03_ADDR32NB_S38_R3ProxyOptionsHandler_8
    .rva R03_ADDR32NB_S32_R4ProxyOptionsHandler_6B
    .zero 12
end_10:

.section a11,"dr"
# COFF section 11: .data$rs
begin_11:
symbol_33:  # .data$rs
symbol_35:  # ??_R0?AVProxyOptionsHandler@@@8
    .quad R01_ADDR64_S8_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "ProxyOptionsHandler@@\000"
end_11:

.section a12,"dr"
# COFF section 12: .rdata$r
begin_12:
symbol_36:  # .rdata$r
symbol_38:  # ??_R3ProxyOptionsHandler@@8
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S41_R2ProxyOptionsHandler_8
    .zero 4
end_12:

.section a13,"dr"
# COFF section 13: .rdata$r
begin_13:
symbol_39:  # .rdata$r
symbol_41:  # ??_R2ProxyOptionsHandler@@8
    .rva R03_ADDR32NB_S44_R1A_0A_EA_ProxyOptionsHandler_8
    .rva R03_ADDR32NB_S29_R1A_0A_EA_ACMOptionsHandler_8
    .zero 12
end_13:

.section a14,"dr"
# COFF section 14: .rdata$r
begin_14:
symbol_42:  # .rdata$r
symbol_44:  # ??_R1A@?0A@EA@ProxyOptionsHandler@@8
    .rva R03_ADDR32NB_S35_R0_AVProxyOptionsHandler_8
    .byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S38_R3ProxyOptionsHandler_8
    .zero 8
end_14:

.section a15,"dr"
# COFF section 15: .rdata
begin_15:
symbol_45:  # .rdata
symbol_47:  # IID_IACMPropertiesManager
    .byte 0x17, 0xde, 0x68, 0xaa, 0x5f, 0x49, 0xd4, 0x4e, 0xa5, 0x7a, 0x30, 0xbf
    .byte 0xfb, 0x20, 0xab, 0xc7
end_15:

.section a16,"dr"
# COFF section 16: .text$mn
begin_16:
symbol_48:  # .text$mn
symbol_50:  # ?OptionRequest@ProxyOptionsHandler@@UEAAHHPEAHPEANPEAPEAD@Z
symbol_233:  # $LN13
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    mov qword ptr [rsp + 0x20], rdi                 # +0x000f
    push r14                                        # +0x0014
    sub rsp, 0x30                                   # +0x0016
    mov r14, qword ptr [rsp + 0x60]                 # +0x001a
    {load} mov rbx, rcx                             # +0x001f
    mov rcx, qword ptr [rcx + 0x10]                 # +0x0022
    {load} mov rdi, r9                              # +0x0026
    {load} mov rsi, r8                              # +0x0029
    {load} mov ebp, edx                             # +0x002c
    test rcx, rcx                                   # +0x002e
    je .Lbb_16_0044                                 # +0x0031
    mov rax, qword ptr [rcx]                        # +0x0033
    mov qword ptr [rsp + 0x20], r14                 # +0x0036
    call qword ptr [rax]                            # +0x003b
    cmp eax, -1                                     # +0x003d
    je .Lbb_16_0049                                 # +0x0040
    jmp .Lbb_16_0064                                # +0x0042
.Lbb_16_0044:
    mov eax, 0xffffffff                             # +0x0044
.Lbb_16_0049:
    mov rcx, qword ptr [rbx + 8]                    # +0x0049
    test rcx, rcx                                   # +0x004d
    je .Lbb_16_0064                                 # +0x0050
    mov rax, qword ptr [rcx]                        # +0x0052
    {load} mov r9, rdi                              # +0x0055
    {load} mov r8, rsi                              # +0x0058
    mov qword ptr [rsp + 0x20], r14                 # +0x005b
    {load} mov edx, ebp                             # +0x0060
    call qword ptr [rax]                            # +0x0062
.Lbb_16_0064:
    mov rbx, qword ptr [rsp + 0x40]                 # +0x0064
    mov rbp, qword ptr [rsp + 0x48]                 # +0x0069
    mov rsi, qword ptr [rsp + 0x50]                 # +0x006e
    mov rdi, qword ptr [rsp + 0x58]                 # +0x0073
    add rsp, 0x30                                   # +0x0078
    pop r14                                         # +0x007c
    ret                                             # +0x007e
end_16:

.section a17,"dr"
# COFF section 17: .rdata
begin_17:
symbol_51:  # .rdata
    .quad R01_ADDR64_S32_R4ProxyOptionsHandler_6B
symbol_53:  # ??_7ProxyOptionsHandler@@6B@
    .quad R01_ADDR64_S50_OptionRequest_ProxyOptionsHandler_UEAAHHPEAHPEANPEAPEAD_Z
end_17:

.section a18,"dr"
# COFF section 18: .text$di
begin_18:
symbol_54:  # .text$di
symbol_195:  # ??__Eg_ProxyOptionsHandler@@YAXXZ
    lea rcx, [rip + R04_REL32_S196_Fg_ProxyOptionsHandler_YAXXZ] # +0x0000
    jmp R04_REL32_S168_atexit                       # +0x0007
end_18:

.section a20,"dr"
# COFF section 20: .text$yd
begin_20:
symbol_58:  # .text$yd
symbol_196:  # ??__Fg_ProxyOptionsHandler@@YAXXZ
    lea rax, [rip + R04_REL32_S53_7ProxyOptionsHandler_6B] # +0x0000
    mov qword ptr [rip + R04_REL32_S407_g_ProxyOptionsHandler_3VProxyOptionsHandler_A], rax # +0x0007
    ret                                             # +0x000e
end_20:

.section a22,"dr"
# COFF section 22: .text$mn
begin_22:
symbol_62:  # .text$mn
symbol_202:  # ?LineSplit@@YAXPEAVACMMessagesHandler@@@Z
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    push rdi                                        # +0x000f
    push r12                                        # +0x0010
    push r13                                        # +0x0012
    push r14                                        # +0x0014
    push r15                                        # +0x0016
    sub rsp, 0x20                                   # +0x0018
    {load} xor esi, esi                             # +0x001c
    lea r13, [rip + R04_REL32_S415_g_szLineBuffer_DLL_VSN_3PADA] # +0x001e
    {load} xor ebp, ebp                             # +0x0025
    {load} xor r15d, r15d                           # +0x0027
    {load} xor ebx, ebx                             # +0x002a
    {load} mov r14, r13                             # +0x002c
    {load} mov r12, rcx                             # +0x002f
.Lbb_22_0032:
    movsx edi, byte ptr [r14]                       # +0x0032
    test esi, esi                                   # +0x0036
    je .Lbb_22_0047                                 # +0x0038
    {load} xor eax, eax                             # +0x003a
    cmp dil, 0x22                                   # +0x003c
    cmovne eax, esi                                 # +0x0040
    {load} mov esi, eax                             # +0x0043
    jmp .Lbb_22_006a                                # +0x0045
.Lbb_22_0047:
    cmp dil, 0x22                                   # +0x0047
    jne .Lbb_22_0054                                # +0x004b
    mov esi, 1                                      # +0x004d
    jmp .Lbb_22_006a                                # +0x0052
.Lbb_22_0054:
    {load} mov ecx, edi                             # +0x0054
    call qword ptr [rip + R04_REL32_S172_imp_isalnum] # +0x0056
    test eax, eax                                   # +0x005c
    jne .Lbb_22_006a                                # +0x005e
    cmp dil, 0x20                                   # +0x0060
    {load} mov r15d, ebx                            # +0x0064
    cmove ebp, ebx                                  # +0x0067
.Lbb_22_006a:
    inc ebx                                         # +0x006a
    inc r14                                         # +0x006c
    cmp ebx, 0x100                                  # +0x006f
    jl .Lbb_22_0032                                 # +0x0075
    test r15d, r15d                                 # +0x0077
    mov esi, 0x100                                  # +0x007a
    {load} mov rcx, r12                             # +0x007f
    cmove r15d, esi                                 # +0x0082
    test ebp, ebp                                   # +0x0086
    cmove ebp, r15d                                 # +0x0088
    movsxd rdi, ebp                                 # +0x008c
    mov dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA], ebp # +0x008f
    movzx ebx, byte ptr [rdi + r13]                 # +0x0095
    call R04_REL32_S201_writeBuffer_YAXPEAVACMMessagesHandler_Z # +0x009a
    mov eax, dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA] # +0x009f
    mov byte ptr [rdi + r13], bl                    # +0x00a5
    {load} cmp rdi, rsi                             # +0x00a9
    jge .Lbb_22_00d0                                # +0x00ac
    xchg ax, ax                                     # +0x00ae
.Lbb_22_00b0:
    movzx edx, byte ptr [rdi + r13]                 # +0x00b0
    test dl, dl                                     # +0x00b5
    je .Lbb_22_00d0                                 # +0x00b7
    movsxd rcx, eax                                 # +0x00b9
    inc rdi                                         # +0x00bc
    inc eax                                         # +0x00bf
    mov dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA], eax # +0x00c1
    mov byte ptr [rcx + r13], dl                    # +0x00c7
    {load} cmp rdi, rsi                             # +0x00cb
    jl .Lbb_22_00b0                                 # +0x00ce
.Lbb_22_00d0:
    mov rbx, qword ptr [rsp + 0x50]                 # +0x00d0
    mov rbp, qword ptr [rsp + 0x58]                 # +0x00d5
    mov rsi, qword ptr [rsp + 0x60]                 # +0x00da
    mov dword ptr [rip + R04_REL32_S416_g_bOutputLine_DLL_VSN_3HA], eax # +0x00df
    add rsp, 0x20                                   # +0x00e5
    pop r15                                         # +0x00e9
    pop r14                                         # +0x00eb
    pop r13                                         # +0x00ed
    pop r12                                         # +0x00ef
    pop rdi                                         # +0x00f1
    ret                                             # +0x00f2
end_22:

.section a25,"dr"
# COFF section 25: .text$mn
begin_25:
symbol_68:  # .text$mn
symbol_204:  # ?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    mov qword ptr [rsp + 0x10], rbx                 # +0x0000
    mov qword ptr [rsp + 0x18], rsi                 # +0x0005
    push rdi                                        # +0x000a
    push r14                                        # +0x000b
    push r15                                        # +0x000d
    sub rsp, 0x20                                   # +0x000f
    mov byte ptr [rcx], 0x25                        # +0x0013
    lea rdi, [rcx + 1]                              # +0x0016
    mov rax, qword ptr [r9]                         # +0x001a
    lea rcx, [rip + R04_REL32_S424_C__05DFNBJPIB_9_CL0_5_CD] # +0x001d
    {load} mov r14, rdx                             # +0x0024
    {load} mov rbx, r9                              # +0x0027
    {load} mov r15, r8                              # +0x002a
    {load} xor esi, esi                             # +0x002d
    movsx edx, byte ptr [rax]                       # +0x002f
    call R04_REL32_S180_strchr                      # +0x0032
    test rax, rax                                   # +0x0037
    je .Lbb_25_0065                                 # +0x003a
    {disp8} nop dword ptr [rax]                     # +0x003c
.Lbb_25_0040:
    mov rax, qword ptr [rbx]                        # +0x0040
    movzx ecx, byte ptr [rax]                       # +0x0043
    mov byte ptr [rdi], cl                          # +0x0046
    lea rcx, [rip + R04_REL32_S424_C__05DFNBJPIB_9_CL0_5_CD] # +0x0048
    inc qword ptr [rbx]                             # +0x004f
    inc rdi                                         # +0x0052
    mov rax, qword ptr [rbx]                        # +0x0055
    movsx edx, byte ptr [rax]                       # +0x0058
    call R04_REL32_S180_strchr                      # +0x005b
    test rax, rax                                   # +0x0060
    jne .Lbb_25_0040                                # +0x0063
.Lbb_25_0065:
    mov rax, qword ptr [rbx]                        # +0x0065
    movsx ecx, byte ptr [rax]                       # +0x0068
    call qword ptr [rip + R04_REL32_S171_imp_isdigit] # +0x006b
    test eax, eax                                   # +0x0071
    je .Lbb_25_00e2                                 # +0x0073
    mov rax, qword ptr [rbx]                        # +0x0075
    mov qword ptr [rsp + 0x40], rbp                 # +0x0078
    {load} mov rbp, rdi                             # +0x007d
    movsx ecx, byte ptr [rax]                       # +0x0080
    call qword ptr [rip + R04_REL32_S171_imp_isdigit] # +0x0083
    test eax, eax                                   # +0x0089
    je .Lbb_25_00ae                                 # +0x008b
    nop dword ptr [rax]                             # +0x008d
.Lbb_25_0090:
    mov rax, qword ptr [rbx]                        # +0x0090
    movzx edx, byte ptr [rax]                       # +0x0093
    mov byte ptr [rdi], dl                          # +0x0096
    inc rdi                                         # +0x0098
    inc qword ptr [rbx]                             # +0x009b
    mov rax, qword ptr [rbx]                        # +0x009e
    movsx ecx, byte ptr [rax]                       # +0x00a1
    call qword ptr [rip + R04_REL32_S171_imp_isdigit] # +0x00a4
    test eax, eax                                   # +0x00aa
    jne .Lbb_25_0090                                # +0x00ac
.Lbb_25_00ae:
    {load} mov rcx, rbp                             # +0x00ae
    mov byte ptr [rdi], sil                         # +0x00b1
    call qword ptr [rip + R04_REL32_S170_imp_atoi]  # +0x00b4
    mov rbp, qword ptr [rsp + 0x40]                 # +0x00ba
    lea rcx, [rip + R04_REL32_S427_C__0DB_IDCMHCHC_BAD_5FORMATTING_5_CIwidth_5exceeds_55] # +0x00bf
    cmp eax, 0x200                                  # +0x00c6
    mov dword ptr [r14], eax                        # +0x00cb
    cmovle rcx, rsi                                 # +0x00ce
    {load} mov rsi, rcx                             # +0x00d2
    test rcx, rcx                                   # +0x00d5
    je .Lbb_25_00e9                                 # +0x00d8
    {load} mov rax, rcx                             # +0x00da
    {disp32} jmp .Lbb_25_0201                       # +0x00dd
.Lbb_25_00e2:
    mov dword ptr [r14], 0x28                       # +0x00e2
.Lbb_25_00e9:
    mov rax, qword ptr [rbx]                        # +0x00e9
    movzx ecx, byte ptr [rax]                       # +0x00ec
    cmp cl, 0x2a                                    # +0x00ef
    jne .Lbb_25_0100                                # +0x00f2
    lea rax, [rip + R04_REL32_S430_C__0CK_MDKJFNJN_BAD_5FORMATTING_5_CIwidth_5digits_5ex] # +0x00f4
    {disp32} jmp .Lbb_25_0201                       # +0x00fb
.Lbb_25_0100:
    cmp cl, 0x2e                                    # +0x0100
    jne .Lbb_25_015e                                # +0x0103
    mov byte ptr [rdi], cl                          # +0x0105
    inc rdi                                         # +0x0107
    inc qword ptr [rbx]                             # +0x010a
    mov rax, qword ptr [rbx]                        # +0x010d
    movsx ecx, byte ptr [rax]                       # +0x0110
    call qword ptr [rip + R04_REL32_S171_imp_isdigit] # +0x0113
    test eax, eax                                   # +0x0119
    jne .Lbb_25_0129                                # +0x011b
    lea rax, [rip + R04_REL32_S433_C__0CO_IPJAOOJD_BAD_5FORMATTING_5_CIprecision_5digit] # +0x011d
    {disp32} jmp .Lbb_25_0201                       # +0x0124
.Lbb_25_0129:
    mov rax, qword ptr [rbx]                        # +0x0129
    movsx ecx, byte ptr [rax]                       # +0x012c
    call qword ptr [rip + R04_REL32_S171_imp_isdigit] # +0x012f
    test eax, eax                                   # +0x0135
    je .Lbb_25_015e                                 # +0x0137
    {disp32} nop dword ptr [rax]                    # +0x0139
.Lbb_25_0140:
    mov rax, qword ptr [rbx]                        # +0x0140
    movzx ecx, byte ptr [rax]                       # +0x0143
    mov byte ptr [rdi], cl                          # +0x0146
    inc rdi                                         # +0x0148
    inc qword ptr [rbx]                             # +0x014b
    mov rax, qword ptr [rbx]                        # +0x014e
    movsx ecx, byte ptr [rax]                       # +0x0151
    call qword ptr [rip + R04_REL32_S171_imp_isdigit] # +0x0154
    test eax, eax                                   # +0x015a
    jne .Lbb_25_0140                                # +0x015c
.Lbb_25_015e:
    mov rax, qword ptr [rbx]                        # +0x015e
    lea rcx, [rip + R04_REL32_S436_C__03DNCIMNEC_hlL] # +0x0161
    movsx edx, byte ptr [rax]                       # +0x0168
    call R04_REL32_S180_strchr                      # +0x016b
    mov rcx, qword ptr [rbx]                        # +0x0170
    test rax, rax                                   # +0x0173
    je .Lbb_25_018b                                 # +0x0176
    movzx eax, byte ptr [rcx]                       # +0x0178
    mov byte ptr [r15], al                          # +0x017b
    mov rax, qword ptr [rbx]                        # +0x017e
    movzx ecx, byte ptr [rax]                       # +0x0181
    mov byte ptr [rdi], cl                          # +0x0184
    inc rdi                                         # +0x0186
    jmp .Lbb_25_01cf                                # +0x0189
.Lbb_25_018b:
    mov r8d, 3                                      # +0x018b
    lea rdx, [rip + R04_REL32_S439_C__03KDGLFNIB_I64] # +0x0191
    call qword ptr [rip + R04_REL32_S182_imp_strncmp] # +0x0198
    test eax, eax                                   # +0x019e
    jne .Lbb_25_01d2                                # +0x01a0
    mov rax, qword ptr [rbx]                        # +0x01a2
    movzx ecx, byte ptr [rax]                       # +0x01a5
    mov byte ptr [r15], cl                          # +0x01a8
    mov rax, qword ptr [rbx]                        # +0x01ab
    movzx ecx, byte ptr [rax]                       # +0x01ae
    mov byte ptr [rdi], cl                          # +0x01b1
    inc qword ptr [rbx]                             # +0x01b3
    mov rax, qword ptr [rbx]                        # +0x01b6
    movzx ecx, byte ptr [rax]                       # +0x01b9
    mov byte ptr [rdi + 1], cl                      # +0x01bc
    inc qword ptr [rbx]                             # +0x01bf
    mov rax, qword ptr [rbx]                        # +0x01c2
    movzx ecx, byte ptr [rax]                       # +0x01c5
    mov byte ptr [rdi + 2], cl                      # +0x01c8
    add rdi, 3                                      # +0x01cb
.Lbb_25_01cf:
    inc qword ptr [rbx]                             # +0x01cf
.Lbb_25_01d2:
    mov rax, qword ptr [rbx]                        # +0x01d2
    lea rcx, [rip + R04_REL32_S442_C__0BA_DCHJBDJG_cdiouxXfeEgGps_CG] # +0x01d5
    movsx edx, byte ptr [rax]                       # +0x01dc
    call R04_REL32_S180_strchr                      # +0x01df
    test rax, rax                                   # +0x01e4
    je .Lbb_25_01fa                                 # +0x01e7
    mov rax, qword ptr [rbx]                        # +0x01e9
    movzx ecx, byte ptr [rax]                       # +0x01ec
    {load} mov rax, rsi                             # +0x01ef
    mov byte ptr [rdi], cl                          # +0x01f2
    mov byte ptr [rdi + 1], 0                       # +0x01f4
    jmp .Lbb_25_0201                                # +0x01f8
.Lbb_25_01fa:
    lea rax, [rip + R04_REL32_S445_C__0DA_LEBIJPNO_BAD_5FORMATTING_5_CIunrecognized_5ty] # +0x01fa
.Lbb_25_0201:
    mov rbx, qword ptr [rsp + 0x48]                 # +0x0201
    mov rsi, qword ptr [rsp + 0x50]                 # +0x0206
    add rsp, 0x20                                   # +0x020b
    pop r15                                         # +0x020f
    pop r14                                         # +0x0211
    pop rdi                                         # +0x0213
    ret                                             # +0x0214
end_25:

.section a27,"dr"
# COFF section 27: .text$mn
begin_27:
symbol_72:  # .text$mn
symbol_201:  # ?writeBuffer@@YAXPEAVACMMessagesHandler@@@Z
    sub rsp, 0x28                                   # +0x0000
    movsxd rax, dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA] # +0x0004
    cmp rax, 0x101                                  # +0x000b
    jae .Lbb_27_006e                                # +0x0011
    lea rdx, [rip + R04_REL32_S415_g_szLineBuffer_DLL_VSN_3PADA] # +0x0013
    mov byte ptr [rax + rdx], 0                     # +0x001a
    test rcx, rcx                                   # +0x001e
    je .Lbb_27_003b                                 # +0x0021
    mov rax, qword ptr [rcx]                        # +0x0023
    call qword ptr [rax]                            # +0x0026
    {load} xor eax, eax                             # +0x0028
    mov dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA], eax # +0x002a
    mov dword ptr [rip + R04_REL32_S416_g_bOutputLine_DLL_VSN_3HA], eax # +0x0030
    add rsp, 0x28                                   # +0x0036
    ret                                             # +0x003a
.Lbb_27_003b:
    lea rcx, [rip + R04_REL32_S421_C__03OFAPEBGM_CFs_6] # +0x003b
    call R04_REL32_S177_printf                      # +0x0042
    mov ecx, 1                                      # +0x0047
    call qword ptr [rip + R04_REL32_S174_imp___acrt_iob_func] # +0x004c
    {load} mov rcx, rax                             # +0x0052
    call qword ptr [rip + R04_REL32_S175_imp_fflush] # +0x0055
    {load} xor eax, eax                             # +0x005b
    mov dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA], eax # +0x005d
    mov dword ptr [rip + R04_REL32_S416_g_bOutputLine_DLL_VSN_3HA], eax # +0x0063
    add rsp, 0x28                                   # +0x0069
    ret                                             # +0x006d
.Lbb_27_006e:
    call R04_REL32_S169_report_rangecheckfailure    # +0x006e
    int3                                            # +0x0073
symbol_236:  # $LN7
end_27:

.section a29,"dr"
# COFF section 29: .text$mn
begin_29:
symbol_76:  # .text$mn
symbol_203:  # ?writeChar@@YAXDPEAVACMMessagesHandler@@@Z
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    movzx ebx, cl                                   # +0x0006
    cmp cl, 0xa                                     # +0x0009
    jne .Lbb_29_001b                                # +0x000c
    {load} mov rcx, rdx                             # +0x000e
    add rsp, 0x20                                   # +0x0011
    pop rbx                                         # +0x0015
    jmp R04_REL32_S201_writeBuffer_YAXPEAVACMMessagesHandler_Z # +0x0016
.Lbb_29_001b:
    mov ecx, dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA] # +0x001b
    cmp ecx, 0x100                                  # +0x0021
    jne .Lbb_29_0037                                # +0x0027
    {load} mov rcx, rdx                             # +0x0029
    call R04_REL32_S202_LineSplit_YAXPEAVACMMessagesHandler_Z # +0x002c
    mov ecx, dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA] # +0x0031
.Lbb_29_0037:
    movsxd rax, ecx                                 # +0x0037
    lea rdx, [rip + R04_REL32_S415_g_szLineBuffer_DLL_VSN_3PADA] # +0x003a
    inc ecx                                         # +0x0041
    mov dword ptr [rip + R08_REL32_4_S416_g_bOutputLine_DLL_VSN_3HA], 1 # +0x0043
    mov dword ptr [rip + R04_REL32_S414_g_iLineOffset_DLL_VSN_3HA], ecx # +0x004d
    mov byte ptr [rax + rdx], bl                    # +0x0053
    add rsp, 0x20                                   # +0x0056
    pop rbx                                         # +0x005a
    ret                                             # +0x005b
end_29:

.section a31,"dr"
# COFF section 31: .text$mn
begin_31:
symbol_80:  # .text$mn
symbol_207:  # ACM_ABORT
    ret 0                                           # +0x0000
end_31:

.section a33,"dr"
# COFF section 33: .text$mn
begin_33:
symbol_84:  # .text$mn
symbol_198:  # ACM_GETCOMPONENTS
symbol_234:  # $LN22
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    push rdi                                        # +0x000f
    push r12                                        # +0x0010
    push r13                                        # +0x0012
    push r14                                        # +0x0014
    push r15                                        # +0x0016
    sub rsp, 0x20                                   # +0x0018
    movsxd r10, dword ptr [rdx]                     # +0x001c
    {load} mov r12, rcx                             # +0x001f
    {load} mov rsi, rdx                             # +0x0022
    mov rcx, 0xffffffffffffffff                     # +0x0025
    mov eax, 8                                      # +0x002c
    {load} mov r14, r9                              # +0x0031
    mul r10                                         # +0x0034
    {load} mov r13, r8                              # +0x0037
    cmovo rax, rcx                                  # +0x003a
    {load} mov rcx, rax                             # +0x003e
    call R04_REL32_S166_U_YAPEAX_K_Z                # +0x0041
    mov edx, dword ptr [rsi]                        # +0x0046
    {load} xor ebp, ebp                             # +0x0048
    {load} mov r15, rax                             # +0x004a
    {load} mov edi, ebp                             # +0x004d
    test edx, edx                                   # +0x004f
    jle .Lbb_33_006f                                # +0x0051
    {load} mov rbx, rax                             # +0x0053
.Lbb_33_0056:
    mov ecx, 0x29                                   # +0x0056
    call R04_REL32_S166_U_YAPEAX_K_Z                # +0x005b
    mov qword ptr [rbx], rax                        # +0x0060
    lea rbx, [rbx + 8]                              # +0x0063
    mov edx, dword ptr [rsi]                        # +0x0067
    inc edi                                         # +0x0069
    {load} cmp edi, edx                             # +0x006b
    jl .Lbb_33_0056                                 # +0x006d
.Lbb_33_006f:
    mov ecx, dword ptr [r12]                        # +0x006f
    {load} mov r8, r15                              # +0x0073
    call R04_REL32_S192_ACM_GetComponents           # +0x0076
    mov dword ptr [r14], eax                        # +0x007b
    test eax, eax                                   # +0x007e
    js .Lbb_33_00c2                                 # +0x0080
    cmp dword ptr [rsi], ebp                        # +0x0082
    jle .Lbb_33_00c2                                # +0x0084
    movsxd r14, dword ptr [rsp + 0x70]              # +0x0086
    {load} mov edi, ebp                             # +0x008b
    {load} mov rbx, r15                             # +0x008d
.Lbb_33_0090:
    mov rdx, qword ptr [rbx]                        # +0x0090
    {load} mov r8, r14                              # +0x0093
    movsxd rcx, edi                                 # +0x0096
    {load} add rcx, r13                             # +0x0099
    call qword ptr [rip + R04_REL32_S183_imp_strncpy] # +0x009c
    {load} mov rcx, rax                             # +0x00a2
    {load} mov edx, r14d                            # +0x00a5
    call R04_REL32_S184_atutctof_str                # +0x00a8
    mov rcx, qword ptr [rbx]                        # +0x00ad
    call R04_REL32_S167_V_YAXPEAX_Z                 # +0x00b0
    inc ebp                                         # +0x00b5
    lea rbx, [rbx + 8]                              # +0x00b7
    {load} add edi, r14d                            # +0x00bb
    cmp ebp, dword ptr [rsi]                        # +0x00be
    jl .Lbb_33_0090                                 # +0x00c0
.Lbb_33_00c2:
    {load} mov rcx, r15                             # +0x00c2
    mov rbx, qword ptr [rsp + 0x50]                 # +0x00c5
    mov rbp, qword ptr [rsp + 0x58]                 # +0x00ca
    mov rsi, qword ptr [rsp + 0x60]                 # +0x00cf
    add rsp, 0x20                                   # +0x00d4
    pop r15                                         # +0x00d8
    pop r14                                         # +0x00da
    pop r13                                         # +0x00dc
    pop r12                                         # +0x00de
    pop rdi                                         # +0x00e0
    jmp R04_REL32_S167_V_YAXPEAX_Z                  # +0x00e1
end_33:

.section a35,"dr"
# COFF section 35: .text$mn
begin_35:
symbol_88:  # .text$mn
symbol_192:  # ACM_GetComponents
symbol_231:  # $LN10
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    cmp dword ptr [rip + R05_REL32_1_S404_g_InitializationData_3UACMDLLInitializationData_A], 3 # +0x000f
    {load} mov rbx, r8                              # +0x0016
    {load} mov edi, edx                             # +0x0019
    {load} mov esi, ecx                             # +0x001b
    jl .Lbb_35_006d                                 # +0x001d
    mov rcx, qword ptr [rip + 0x18 + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A] # +0x001f
    lea r8, [rsp + 0x48]                            # +0x0026
    lea rdx, [rip + R04_REL32_S47_IID_IACMPropertiesManager] # +0x002b
    mov rax, qword ptr [rcx]                        # +0x0032
    call qword ptr [rax]                            # +0x0035
    test eax, eax                                   # +0x0037
    js .Lbb_35_0072                                 # +0x0039
    mov rcx, qword ptr [rsp + 0x48]                 # +0x003b
    {load} mov r9, rbx                              # +0x0040
    {load} mov r8d, edi                             # +0x0043
    {load} mov edx, esi                             # +0x0046
    mov rax, qword ptr [rcx]                        # +0x0048
    call qword ptr [rax + 0x18]                     # +0x004b
    mov rcx, qword ptr [rsp + 0x48]                 # +0x004e
    {load} mov ebx, eax                             # +0x0053
    mov rax, qword ptr [rcx]                        # +0x0055
    call qword ptr [rax + 0x10]                     # +0x0058
    {load} mov eax, ebx                             # +0x005b
    mov rbx, qword ptr [rsp + 0x30]                 # +0x005d
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0062
    add rsp, 0x20                                   # +0x0067
    pop rdi                                         # +0x006b
    ret                                             # +0x006c
.Lbb_35_006d:
    mov eax, 0x80004005                             # +0x006d
.Lbb_35_0072:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0072
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0077
    add rsp, 0x20                                   # +0x007c
    pop rdi                                         # +0x0080
    ret                                             # +0x0081
end_35:

.section a37,"dr"
# COFF section 37: .text$mn
begin_37:
symbol_92:  # .text$mn
symbol_190:  # ACM_GetProblemHandle
    mov rax, qword ptr [rip + R04_REL32_S403_g_pACMProblemHandle_3PEAXEA] # +0x0000
    ret                                             # +0x0007
end_37:

.section a39,"dr"
# COFF section 39: .text$mn
begin_39:
symbol_96:  # .text$mn
symbol_205:  # ACM_PRINT
symbol_237:  # $LN9
    rex push rbx                                    # +0x0000
    push rbp                                        # +0x0002
    push rsi                                        # +0x0003
    push rdi                                        # +0x0004
    push r14                                        # +0x0005
    push r15                                        # +0x0007
    sub rsp, 0x458                                  # +0x0009
    mov rax, qword ptr [rip + R04_REL32_S474_security_cookie] # +0x0010
    {load} xor rax, rsp                             # +0x0017
    mov qword ptr [rsp + 0x440], rax                # +0x001a
    mov rbp, qword ptr [rsp + 0x4b0]                # +0x0022
    {load} mov rax, rdx                             # +0x002a
    mov edx, dword ptr [rsp + 0x4c8]                # +0x002d
    {load} mov rbx, rcx                             # +0x0034
    mov r14, qword ptr [rsp + 0x4b8]                # +0x0037
    {load} mov rcx, rax                             # +0x003f
    mov r15, qword ptr [rsp + 0x4c0]                # +0x0042
    {load} mov rsi, r9                              # +0x004a
    {load} mov rdi, r8                              # +0x004d
    call R04_REL32_S186_atutextract_c_str           # +0x0050
    lea r10, [rsp + 0x40]                           # +0x0055
    {load} sub r10, rax                             # +0x005a
    nop dword ptr [rax]                             # +0x005d
.Lbb_39_0060:
    movzx edx, byte ptr [rax]                       # +0x0060
    mov byte ptr [r10 + rax], dl                    # +0x0063
    lea rax, [rax + 1]                              # +0x0067
    test dl, dl                                     # +0x006b
    jne .Lbb_39_0060                                # +0x006d
    mov ecx, dword ptr [rbx]                        # +0x006f
    lea rdx, [rsp + 0x40]                           # +0x0071
    mov qword ptr [rsp + 0x30], r15                 # +0x0076
    {load} mov r9, rsi                              # +0x007b
    mov qword ptr [rsp + 0x28], r14                 # +0x007e
    {load} mov r8, rdi                              # +0x0083
    mov qword ptr [rsp + 0x20], rbp                 # +0x0086
    mov dword ptr [rip + R08_REL32_4_S417_g_bCalledFromFortran_DLL_VSN_3HA], 1 # +0x008b
    call R04_REL32_S188_ACM_Print                   # +0x0095
    mov dword ptr [rip + R08_REL32_4_S417_g_bCalledFromFortran_DLL_VSN_3HA], 0 # +0x009a
    mov rcx, qword ptr [rsp + 0x440]                # +0x00a4
    {load} xor rcx, rsp                             # +0x00ac
    call R04_REL32_S211_security_check_cookie       # +0x00af
    add rsp, 0x458                                  # +0x00b4
    pop r15                                         # +0x00bb
    pop r14                                         # +0x00bd
    pop rdi                                         # +0x00bf
    pop rsi                                         # +0x00c0
    pop rbp                                         # +0x00c1
    pop rbx                                         # +0x00c2
    ret                                             # +0x00c3
end_39:

.section a41,"dr"
# COFF section 41: .text$mn
begin_41:
symbol_100:  # .text$mn
symbol_206:  # ACM_PRINTPP
symbol_238:  # $LN24
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    mov qword ptr [rsp + 0x20], rdi                 # +0x000f
    push r14                                        # +0x0014
    sub rsp, 0x20                                   # +0x0016
    {load} mov rbp, r9                              # +0x001a
    {load} mov r14, r8                              # +0x001d
    {load} mov rsi, rdx                             # +0x0020
    {load} mov rdi, rcx                             # +0x0023
    test rcx, rcx                                   # +0x0026
    jne .Lbb_41_0030                                # +0x0029
    call R04_REL32_S197_ATInitialize                # +0x002b
.Lbb_41_0030:
    {load} xor ebx, ebx                             # +0x0030
    cmp dword ptr [rsi], ebx                        # +0x0032
    jle .Lbb_41_009f                                # +0x0034
    .byte 0x66  # additional operand-size prefix    # +0x0036
    {disp32} nop word ptr [rax + rax]
.Lbb_41_0040:
    {load} mov r8d, ebp                             # +0x0040
    {load} mov edx, ebx                             # +0x0043
    {load} mov rcx, r14                             # +0x0045
    call R04_REL32_S187_atutextract_c_substr        # +0x0048
    mov rcx, qword ptr [rip + R04_REL32_S401_g_pACMMessageCollector_3PEAVACMMessagesHandler_EA] # +0x004d
    test rcx, rcx                                   # +0x0054
    je .Lbb_41_0064                                 # +0x0057
    mov r8, qword ptr [rcx]                         # +0x0059
    {load} mov rdx, rax                             # +0x005c
    call qword ptr [r8]                             # +0x005f
    jmp .Lbb_41_0099                                # +0x0062
.Lbb_41_0064:
    test rdi, rdi                                   # +0x0064
    je .Lbb_41_0076                                 # +0x0067
    cmp qword ptr [rdi], 0                          # +0x0069
    lea rcx, [rip + R04_REL32_S472_C__0L_DCCGFMBN_Error_3_5_CFs_6] # +0x006d
    jl .Lbb_41_007d                                 # +0x0074
.Lbb_41_0076:
    lea rcx, [rip + R04_REL32_S421_C__03OFAPEBGM_CFs_6] # +0x0076
.Lbb_41_007d:
    {load} mov rdx, rax                             # +0x007d
    call R04_REL32_S177_printf                      # +0x0080
    mov ecx, 1                                      # +0x0085
    call qword ptr [rip + R04_REL32_S174_imp___acrt_iob_func] # +0x008a
    {load} mov rcx, rax                             # +0x0090
    call qword ptr [rip + R04_REL32_S175_imp_fflush] # +0x0093
.Lbb_41_0099:
    inc ebx                                         # +0x0099
    cmp ebx, dword ptr [rsi]                        # +0x009b
    jl .Lbb_41_0040                                 # +0x009d
.Lbb_41_009f:
    mov rcx, qword ptr [rip + R04_REL32_S401_g_pACMMessageCollector_3PEAVACMMessagesHandler_EA] # +0x009f
    test rcx, rcx                                   # +0x00a6
    je .Lbb_41_00b3                                 # +0x00a9
    mov rax, qword ptr [rcx]                        # +0x00ab
    mov edx, dword ptr [rdi]                        # +0x00ae
    call qword ptr [rax + 8]                        # +0x00b0
.Lbb_41_00b3:
    mov rbx, qword ptr [rsp + 0x30]                 # +0x00b3
    mov rbp, qword ptr [rsp + 0x38]                 # +0x00b8
    mov rsi, qword ptr [rsp + 0x40]                 # +0x00bd
    mov rdi, qword ptr [rsp + 0x48]                 # +0x00c2
    add rsp, 0x20                                   # +0x00c7
    pop r14                                         # +0x00cb
    ret                                             # +0x00cd
end_41:

.section a43,"dr"
# COFF section 43: .text$mn
begin_43:
symbol_104:  # .text$mn
# Varargs entry: ECX is status, RDX is format; save R8 and R9 in the home area.
symbol_188:  # ACM_Print
symbol_229:  # $LN132
    mov qword ptr [rsp + 0x10], rdx                 # +0x0000
    mov qword ptr [rsp + 0x18], r8                  # +0x0005
    mov qword ptr [rsp + 0x20], r9                  # +0x000a
    push rbx                                        # +0x000f
    push rsi                                        # +0x0010
    push rdi                                        # +0x0011
    push r12                                        # +0x0012
    push r13                                        # +0x0014
    push r14                                        # +0x0016
    push r15                                        # +0x0018
    sub rsp, 0xb0                                   # +0x001a
    mov rax, qword ptr [rip + R04_REL32_S474_security_cookie] # +0x0021
    {load} xor rax, rsp                             # +0x0028
    mov qword ptr [rsp + 0xa0], rax                 # +0x002b
    mov dword ptr [rsp + 0x40], ecx                 # +0x0033
    mov dword ptr [rsp + 0x48], ecx                 # +0x0037
    mov r15, qword ptr [rip + R04_REL32_S401_g_pACMMessageCollector_3PEAVACMMessagesHandler_EA] # +0x003b
    mov qword ptr [rsp + 0x50], r15                 # +0x0042
    test r15, r15                                   # +0x0047
    jne .Lbb_43_005c                                # +0x004a
    test ecx, ecx                                   # +0x004c
    jns .Lbb_43_005c                                # +0x004e
    lea rcx, [rip + R04_REL32_S454_C__07KAJBENLI_Error_3_5] # +0x0050
    call R04_REL32_S177_printf                      # +0x0057
.Lbb_43_005c:
    cmp qword ptr [rsp + 0xf8], 0                   # +0x005c
    jne .Lbb_43_006e                                # +0x0065
    {load} xor ecx, ecx                             # +0x0067
    call R04_REL32_S197_ATInitialize                # +0x0069
.Lbb_43_006e:
    mov eax, 5                                      # +0x006e
    mov r12d, 0x270f                                # +0x0073
    cmp dword ptr [rip + R05_REL32_1_S417_g_bCalledFromFortran_DLL_VSN_3HA], 0 # +0x0079
    cmovne r12d, eax                                # +0x0080
    mov esi, 1                                      # +0x0084
    {load} mov edx, esi                             # +0x0089
    mov dword ptr [rsp + 0x30], edx                 # +0x008b
    mov dword ptr [rip + R04_REL32_S416_g_bOutputLine_DLL_VSN_3HA], esi # +0x008f
    lea r14, [rsp + 0x100]                          # +0x0095
    mov qword ptr [rsp + 0x28], r14                 # +0x009d
    {disp8} nop dword ptr [rax]                     # +0x00a2
    .byte 0x66  # additional operand-size prefix    # +0x00a6
    {disp32} nop word ptr [rax + rax]
.Lbb_43_00b0:
    {load} mov r13d, r12d                           # +0x00b0
    mov rax, qword ptr [rsp + 0xf8]                 # +0x00b3
    movzx ecx, byte ptr [rax]                       # +0x00bb
    test cl, cl                                     # +0x00be
    {disp32} je .Lbb_43_0606                        # +0x00c0
    cmp cl, 0x5c                                    # +0x00c6
    jne .Lbb_43_00ee                                # +0x00c9
    cmp byte ptr [rax + 1], 0x6e                    # +0x00cb
    {disp32} jne .Lbb_43_05ed                       # +0x00cf
    {load} mov rdx, r15                             # +0x00d5
    mov cl, 0xa                                     # +0x00d8
    call R04_REL32_S203_writeChar_YAXDPEAVACMMessagesHandler_Z # +0x00da
    add qword ptr [rsp + 0xf8], 2                   # +0x00df
    mov edx, dword ptr [rsp + 0x30]                 # +0x00e8
    jmp .Lbb_43_00b0                                # +0x00ec
.Lbb_43_00ee:
    cmp cl, 0x25                                    # +0x00ee
    {disp32} jne .Lbb_43_05ed                       # +0x00f1
    test edx, edx                                   # +0x00f7
    {disp32} je .Lbb_43_05ed                        # +0x00f9
    mov rax, qword ptr [rsp + 0xf8]                 # +0x00ff
    inc rax                                         # +0x0107
    cmp byte ptr [rax], cl                          # +0x010a
    jne .Lbb_43_0135                                # +0x010c
    mov qword ptr [rsp + 0xf8], rax                 # +0x010e
    movzx ecx, byte ptr [rax]                       # +0x0116
    inc rax                                         # +0x0119
    mov qword ptr [rsp + 0xf8], rax                 # +0x011c
    {load} mov rdx, r15                             # +0x0124
    call R04_REL32_S203_writeChar_YAXDPEAVACMMessagesHandler_Z # +0x0127
    mov edx, dword ptr [rsp + 0x30]                 # +0x012c
    {disp32} jmp .Lbb_43_00b0                       # +0x0130
.Lbb_43_0135:
    mov byte ptr [rsp + 0x20], 0x20                 # +0x0135
    mov dword ptr [rsp + 0x34], 0                   # +0x013a
    mov rbx, qword ptr [rsp + 0xf8]                 # +0x0142
    mov qword ptr [rsp + 0x38], rbx                 # +0x014a
    mov qword ptr [rsp + 0xf8], rax                 # +0x014f
    lea r9, [rsp + 0xf8]                            # +0x0157
    lea r8, [rsp + 0x20]                            # +0x015f
    lea rdx, [rsp + 0x34]                           # +0x0164
    lea rcx, [rsp + 0x60]                           # +0x0169
    call R04_REL32_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z # +0x016e
    {load} mov rdi, rax                             # +0x0173
    test rax, rax                                   # +0x0176
    {disp32} jne .Lbb_43_05b4                       # +0x0179
    mov ecx, dword ptr [rsp + 0x34]                 # +0x017f
    add ecx, 0x14                                   # +0x0183
    mov r8d, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x0186
    {load} cmp r8d, ecx                             # +0x018d
    jge .Lbb_43_01c3                                # +0x0190
    mov dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA], ecx # +0x0192
    mov rcx, qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA] # +0x0198
    call R04_REL32_S167_V_YAXPEAX_Z                 # +0x019f
    movsxd rcx, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x01a4
    call R04_REL32_S166_U_YAPEAX_K_Z                # +0x01ab
    {load} mov rbx, rax                             # +0x01b0
    mov qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA], rax # +0x01b3
    mov r8d, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x01ba
    jmp .Lbb_43_01ca                                # +0x01c1
.Lbb_43_01c3:
    mov rbx, qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA] # +0x01c3
.Lbb_43_01ca:
    {load} xor edx, edx                             # +0x01ca
    mov dword ptr [rsp + 0x24], edx                 # +0x01cc
    mov rax, qword ptr [rsp + 0xf8]                 # +0x01d0
    movsx ecx, byte ptr [rax]                       # +0x01d8
    cmp cl, 0x26                                    # +0x01db
    jne .Lbb_43_01f5                                # +0x01de
    mov dword ptr [rip + R04_REL32_S416_g_bOutputLine_DLL_VSN_3HA], edx # +0x01e0
    mov byte ptr [rbx], dl                          # +0x01e6
    inc qword ptr [rsp + 0xf8]                      # +0x01e8
    {disp32} jmp .Lbb_43_0549                       # +0x01f0
.Lbb_43_01f5:
    {load} mov eax, r12d                            # +0x01f5
    dec r12d                                        # +0x01f8
    mov dword ptr [rsp + 0x34], r12d                # +0x01fb
    test eax, eax                                   # +0x0200
    {disp32} je .Lbb_43_0583                        # +0x0202
    # selector = format character - 0x45
    lea eax, [rcx - 0x45]                           # +0x0208
    # last selector 0x33
    cmp eax, 0x33                                   # +0x020b
    {disp32} ja .Lbb_43_0514                        # +0x020e
    # index within the byte selector table
    cdqe                                            # +0x0214
    # R9 = image base
    lea r9, [rip + R04_REL32_S473_ImageBase]        # +0x0216
    # table of 52 selectors
    movzx eax, byte ptr [r9 + rax + R03_ADDR32NB_S219_LN119] # +0x021d
    # table of six case RVAs
    mov ecx, dword ptr [r9 + rax*4 + R03_ADDR32NB_S220_LN120] # +0x0226
    # convert RVA to VA
    {load} add rcx, r9                              # +0x022e
    # dispatch to case body
    jmp rcx                                         # +0x0231
symbol_221:  # $LN26
    movzx eax, byte ptr [rsp + 0x20]                # +0x0233
    sub al, 0x4c                                    # +0x0238
    add r14, 8                                      # +0x023a
    movsxd rdx, r8d                                 # +0x023e
    {load} mov rcx, rbx                             # +0x0241
    mov qword ptr [rsp + 0x28], r14                 # +0x0244
    lea r8, [rsp + 0x60]                            # +0x0249
    test al, 0xdf                                   # +0x024e
    mov rax, qword ptr [r14 - 8]                    # +0x0250
    je .Lbb_43_0279                                 # +0x0254
    movsx r14d, byte ptr [rax]                      # +0x0256
    {load} mov r9d, r14d                            # +0x025a
    call R04_REL32_S179_sprintf_s                   # +0x025d
    {load} mov edx, eax                             # +0x0262
    mov dword ptr [rsp + 0x24], eax                 # +0x0264
    mov rcx, qword ptr [rsp + 0x28]                 # +0x0268
    {load} mov rax, rcx                             # +0x026d
    test edx, edx                                   # +0x0270
    jne .Lbb_43_02a6                                # +0x0272
    test r14b, r14b                                 # +0x0274
    jmp .Lbb_43_029b                                # +0x0277
.Lbb_43_0279:
    movzx r14d, word ptr [rax]                      # +0x0279
    {load} mov r9d, r14d                            # +0x027d
    call R04_REL32_S179_sprintf_s                   # +0x0280
    {load} mov edx, eax                             # +0x0285
    mov dword ptr [rsp + 0x24], eax                 # +0x0287
    mov rcx, qword ptr [rsp + 0x28]                 # +0x028b
    {load} mov rax, rcx                             # +0x0290
    test edx, edx                                   # +0x0293
    jne .Lbb_43_02a6                                # +0x0295
    test r14w, r14w                                 # +0x0297
.Lbb_43_029b:
    jne .Lbb_43_02a6                                # +0x029b
    mov edx, 1                                      # +0x029d
    mov dword ptr [rsp + 0x24], edx                 # +0x02a2
.Lbb_43_02a6:
    cmp dword ptr [rip + R05_REL32_1_S417_g_bCalledFromFortran_DLL_VSN_3HA], 0 # +0x02a6
    {disp32} je .Lbb_43_050d                        # +0x02ad
    lea rcx, [rax + 8]                              # +0x02b3
    mov qword ptr [rsp + 0x28], rcx                 # +0x02b7
    test r12d, r12d                                 # +0x02bc
    cmove r12d, r13d                                # +0x02bf
    dec r12d                                        # +0x02c3
    mov dword ptr [rsp + 0x34], r12d                # +0x02c6
    {disp32} jmp .Lbb_43_050d                       # +0x02cb
symbol_222:  # $LN35
    movzx ecx, byte ptr [rsp + 0x20]                # +0x02d0
    lea eax, [rcx - 0x4c]                           # +0x02d5
    add r14, 8                                      # +0x02d8
    movsxd rdx, r8d                                 # +0x02dc
    mov qword ptr [rsp + 0x28], r14                 # +0x02df
    test al, 0xdf                                   # +0x02e4
    je .Lbb_43_0344                                 # +0x02e6
    cmp cl, 0x68                                    # +0x02e8
    jne .Lbb_43_030d                                # +0x02eb
    mov rax, qword ptr [r14 - 8]                    # +0x02ed
    movsx r9d, word ptr [rax]                       # +0x02f1
.Lbb_43_02f5:
    lea r8, [rsp + 0x60]                            # +0x02f5
    {load} mov rcx, rbx                             # +0x02fa
    call R04_REL32_S179_sprintf_s                   # +0x02fd
    {load} mov edx, eax                             # +0x0302
    mov dword ptr [rsp + 0x24], eax                 # +0x0304
    {disp32} jmp .Lbb_43_050d                       # +0x0308
.Lbb_43_030d:
    mov r9, qword ptr [r14 - 8]                     # +0x030d
    lea r8, [rsp + 0x60]                            # +0x0311
    cmp cl, 0x49                                    # +0x0316
    {load} mov rcx, rbx                             # +0x0319
    jne .Lbb_43_0331                                # +0x031c
    mov r9, qword ptr [r9]                          # +0x031e
    call R04_REL32_S179_sprintf_s                   # +0x0321
    {load} mov edx, eax                             # +0x0326
    mov dword ptr [rsp + 0x24], eax                 # +0x0328
    {disp32} jmp .Lbb_43_050d                       # +0x032c
.Lbb_43_0331:
    mov r9d, dword ptr [r9]                         # +0x0331
    call R04_REL32_S179_sprintf_s                   # +0x0334
    {load} mov edx, eax                             # +0x0339
    mov dword ptr [rsp + 0x24], eax                 # +0x033b
    {disp32} jmp .Lbb_43_050d                       # +0x033f
.Lbb_43_0344:
    mov r9, qword ptr [r14 - 8]                     # +0x0344
    mov r9d, dword ptr [r9]                         # +0x0348
    jmp .Lbb_43_02f5                                # +0x034b
symbol_223:  # $LN48
    add r14, 8                                      # +0x034d
    mov qword ptr [rsp + 0x28], r14                 # +0x0351
    mov rax, qword ptr [r14 - 8]                    # +0x0356
    movsxd rdx, r8d                                 # +0x035a
    movsd xmm3, qword ptr [rax]                     # +0x035d
    movq r9, xmm3                                   # +0x0361
    lea r8, [rsp + 0x60]                            # +0x0366
    {load} mov rcx, rbx                             # +0x036b
    call R04_REL32_S179_sprintf_s                   # +0x036e
    {load} mov edx, eax                             # +0x0373
    mov dword ptr [rsp + 0x24], eax                 # +0x0375
    {disp32} jmp .Lbb_43_050d                       # +0x0379
symbol_224:  # $LN53
    add r14, 8                                      # +0x037e
    mov qword ptr [rsp + 0x28], r14                 # +0x0382
    movsxd rdx, r8d                                 # +0x0387
    mov r9, qword ptr [r14 - 8]                     # +0x038a
    lea r8, [rsp + 0x60]                            # +0x038e
    {load} mov rcx, rbx                             # +0x0393
    call R04_REL32_S179_sprintf_s                   # +0x0396
    {load} mov edx, eax                             # +0x039b
    mov dword ptr [rsp + 0x24], eax                 # +0x039d
    {disp32} jmp .Lbb_43_050d                       # +0x03a1
symbol_225:  # $LN54
    add r14, 8                                      # +0x03a6
    mov qword ptr [rsp + 0x28], r14                 # +0x03aa
    mov r14, qword ptr [r14 - 8]                    # +0x03af
    {load} xor eax, eax                             # +0x03b3
    test r14, r14                                   # +0x03b5
    je .Lbb_43_03cb                                 # +0x03b8
    mov rax, 0xffffffffffffffff                     # +0x03ba
.Lbb_43_03c1:
    inc rax                                         # +0x03c1
    cmp byte ptr [r14 + rax], 0                     # +0x03c4
    jne .Lbb_43_03c1                                # +0x03c9
.Lbb_43_03cb:
    mov edx, 0x28                                   # +0x03cb
    {load} cmp eax, edx                             # +0x03d0
    jle .Lbb_43_03d7                                # +0x03d2
    lea edx, [rax + 1]                              # +0x03d4
.Lbb_43_03d7:
    mov ecx, dword ptr [rip + R04_REL32_S417_g_bCalledFromFortran_DLL_VSN_3HA] # +0x03d7
    test ecx, ecx                                   # +0x03dd
    je .Lbb_43_03ef                                 # +0x03df
    test r12d, r12d                                 # +0x03e1
    je .Lbb_43_03ef                                 # +0x03e4
    lea r12d, [r13 - 2]                             # +0x03e6
    mov dword ptr [rsp + 0x34], r12d                # +0x03ea
.Lbb_43_03ef:
    movzx eax, byte ptr [rsp + 0x20]                # +0x03ef
    sub al, 0x4c                                    # +0x03f4
    test al, 0xdf                                   # +0x03f6
    {disp32} je .Lbb_43_0497                        # +0x03f8
    test ecx, ecx                                   # +0x03fe
    je .Lbb_43_0425                                 # +0x0400
    mov eax, 0x3ff                                  # +0x0402
    {load} cmp edx, eax                             # +0x0407
    cmovg edx, eax                                  # +0x0409
    {load} mov rcx, r14                             # +0x040c
    call R04_REL32_S186_atutextract_c_str           # +0x040f
    {load} mov r14, rax                             # +0x0414
    mov r8d, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x0417
    mov rbx, qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA] # +0x041e
.Lbb_43_0425:
    mov rsi, 0xffffffffffffffff                     # +0x0425
    {disp8} nop dword ptr [rax]                     # +0x042c
.Lbb_43_0430:
    inc rsi                                         # +0x0430
    cmp byte ptr [r14 + rsi], 0                     # +0x0433
    jne .Lbb_43_0430                                # +0x0438
    lea eax, [rsi + 1]                              # +0x043a
    {load} cmp r8d, eax                             # +0x043d
    jge .Lbb_43_046d                                # +0x0440
    mov dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA], eax # +0x0442
    {load} mov rcx, rbx                             # +0x0448
    call R04_REL32_S167_V_YAXPEAX_Z                 # +0x044b
    movsxd rcx, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x0450
    call R04_REL32_S166_U_YAPEAX_K_Z                # +0x0457
    {load} mov rbx, rax                             # +0x045c
    mov qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA], rax # +0x045f
    mov r8d, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x0466
.Lbb_43_046d:
    movsxd rdx, r8d                                 # +0x046d
    {load} mov r9, r14                              # +0x0470
    lea r8, [rsp + 0x60]                            # +0x0473
    {load} mov rcx, rbx                             # +0x0478
    call R04_REL32_S179_sprintf_s                   # +0x047b
    {load} mov edx, eax                             # +0x0480
    mov dword ptr [rsp + 0x24], eax                 # +0x0482
    test eax, eax                                   # +0x0486
    {disp32} jne .Lbb_43_050d                       # +0x0488
    test esi, esi                                   # +0x048e
    jne .Lbb_43_050d                                # +0x0490
    lea edx, [rax + 1]                              # +0x0492
    jmp .Lbb_43_0509                                # +0x0495
.Lbb_43_0497:
    mov rsi, 0xffffffffffffffff                     # +0x0497
    xchg ax, ax                                     # +0x049e
.Lbb_43_04a0:
    inc rsi                                         # +0x04a0
    cmp word ptr [r14 + rsi*2], 0                   # +0x04a3
    jne .Lbb_43_04a0                                # +0x04a9
    lea eax, [rsi*2 + 1]                            # +0x04ab
    {load} cmp r8d, eax                             # +0x04b2
    jge .Lbb_43_04e2                                # +0x04b5
    mov dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA], eax # +0x04b7
    {load} mov rcx, rbx                             # +0x04bd
    call R04_REL32_S167_V_YAXPEAX_Z                 # +0x04c0
    movsxd rcx, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x04c5
    call R04_REL32_S166_U_YAPEAX_K_Z                # +0x04cc
    {load} mov rbx, rax                             # +0x04d1
    mov qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA], rax # +0x04d4
    mov r8d, dword ptr [rip + R04_REL32_S451_iFormattedTextLength_DLL_1_ACM_Print_9_4HA] # +0x04db
.Lbb_43_04e2:
    movsxd rdx, r8d                                 # +0x04e2
    {load} mov r9, r14                              # +0x04e5
    lea r8, [rsp + 0x60]                            # +0x04e8
    {load} mov rcx, rbx                             # +0x04ed
    call R04_REL32_S179_sprintf_s                   # +0x04f0
    {load} mov edx, eax                             # +0x04f5
    mov dword ptr [rsp + 0x24], eax                 # +0x04f7
    test eax, eax                                   # +0x04fb
    jne .Lbb_43_050d                                # +0x04fd
    test esi, esi                                   # +0x04ff
    mov eax, 1                                      # +0x0501
    cmove edx, eax                                  # +0x0506
.Lbb_43_0509:
    mov dword ptr [rsp + 0x24], edx                 # +0x0509
.Lbb_43_050d:
    mov rbx, qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA] # +0x050d
symbol_227:  # $LN63
.Lbb_43_0514:
    inc qword ptr [rsp + 0xf8]                      # +0x0514
    jmp .Lbb_43_0540                                # +0x051c
symbol_226:  # $LN99
    mov r15, qword ptr [rsp + 0x50]                 # +0x051e
    mov r12d, dword ptr [rsp + 0x34]                # +0x0523
    mov rdi, qword ptr [rsp + 0x40]                 # +0x0528
    mov edx, dword ptr [rsp + 0x24]                 # +0x052d
    mov eax, dword ptr [rsp + 0x48]                 # +0x0531
    mov dword ptr [rsp + 0x40], eax                 # +0x0535
    mov rbx, qword ptr [rip + R04_REL32_S448_pszFormattedText_DLL_1_ACM_Print_9_4PEADEA] # +0x0539
.Lbb_43_0540:
    test edx, edx                                   # +0x0540
    jle .Lbb_43_0575                                # +0x0542
    mov r14, qword ptr [rsp + 0x28]                 # +0x0544
.Lbb_43_0549:
    movzx eax, byte ptr [rbx]                       # +0x0549
    test al, al                                     # +0x054c
    je .Lbb_43_0566                                 # +0x054e
.Lbb_43_0550:
    lea rbx, [rbx + 1]                              # +0x0550
    {load} mov rdx, r15                             # +0x0554
    movzx ecx, al                                   # +0x0557
    call R04_REL32_S203_writeChar_YAXDPEAVACMMessagesHandler_Z # +0x055a
    movzx eax, byte ptr [rbx]                       # +0x055f
    test al, al                                     # +0x0562
    jne .Lbb_43_0550                                # +0x0564
.Lbb_43_0566:
    test rdi, rdi                                   # +0x0566
    mov edx, dword ptr [rsp + 0x30]                 # +0x0569
    {disp32} je .Lbb_43_00b0                        # +0x056d
    jmp .Lbb_43_05af                                # +0x0573
.Lbb_43_0575:
    test rdi, rdi                                   # +0x0575
    jne .Lbb_43_05af                                # +0x0578
    lea rdi, [rip + R04_REL32_S469_C__0CI_MFJNBOMC_BAD_5FORMATTING_5_CIcheck_5format_5st] # +0x057a
    jmp .Lbb_43_05af                                # +0x0581
.Lbb_43_0583:
    lea rdi, [rip + R04_REL32_S463_C__0CP_CGDDAJKF_BAD_5FORMATTING_5_CItoo_5many_5format] # +0x0583
    mov edx, 0x2b3                                  # +0x058a
    lea rcx, [rip + R04_REL32_S466_C__0CB_LLCHLDHM_SuPrint_CI_CJ_5Bad_5format_5at_5line_5_CFd] # +0x058f
    call R04_REL32_S177_printf                      # +0x0596
    mov ecx, 1                                      # +0x059b
    call qword ptr [rip + R04_REL32_S174_imp___acrt_iob_func] # +0x05a0
    {load} mov rcx, rax                             # +0x05a6
    call qword ptr [rip + R04_REL32_S175_imp_fflush] # +0x05a9
.Lbb_43_05af:
    mov rbx, qword ptr [rsp + 0x38]                 # +0x05af
.Lbb_43_05b4:
    {load} xor edx, edx                             # +0x05b4
    mov dword ptr [rsp + 0x30], edx                 # +0x05b6
    movzx eax, byte ptr [rdi]                       # +0x05ba
    test al, al                                     # +0x05bd
    je .Lbb_43_05db                                 # +0x05bf
.Lbb_43_05c1:
    lea rdi, [rdi + 1]                              # +0x05c1
    {load} mov rdx, r15                             # +0x05c5
    movzx ecx, al                                   # +0x05c8
    call R04_REL32_S203_writeChar_YAXDPEAVACMMessagesHandler_Z # +0x05cb
    movzx eax, byte ptr [rdi]                       # +0x05d0
    test al, al                                     # +0x05d3
    jne .Lbb_43_05c1                                # +0x05d5
    mov edx, dword ptr [rsp + 0x30]                 # +0x05d7
.Lbb_43_05db:
    mov qword ptr [rsp + 0xf8], rbx                 # +0x05db
    mov r14, qword ptr [rsp + 0x28]                 # +0x05e3
    {disp32} jmp .Lbb_43_00b0                       # +0x05e8
.Lbb_43_05ed:
    inc qword ptr [rsp + 0xf8]                      # +0x05ed
    {load} mov rdx, r15                             # +0x05f5
    call R04_REL32_S203_writeChar_YAXDPEAVACMMessagesHandler_Z # +0x05f8
    mov edx, dword ptr [rsp + 0x30]                 # +0x05fd
    {disp32} jmp .Lbb_43_00b0                       # +0x0601
.Lbb_43_0606:
    cmp dword ptr [rip + R05_REL32_1_S416_g_bOutputLine_DLL_VSN_3HA], 0 # +0x0606
    je .Lbb_43_0617                                 # +0x060d
    {load} mov rcx, r15                             # +0x060f
    call R04_REL32_S201_writeBuffer_YAXPEAVACMMessagesHandler_Z # +0x0612
.Lbb_43_0617:
    test r15, r15                                   # +0x0617
    je .Lbb_43_0629                                 # +0x061a
    mov rax, qword ptr [r15]                        # +0x061c
    mov edx, dword ptr [rsp + 0x40]                 # +0x061f
    {load} mov rcx, r15                             # +0x0623
    call qword ptr [rax + 8]                        # +0x0626
.Lbb_43_0629:
    mov dword ptr [rip + R08_REL32_4_S417_g_bCalledFromFortran_DLL_VSN_3HA], 0 # +0x0629
    mov rcx, qword ptr [rsp + 0xa0]                 # +0x0633
    {load} xor rcx, rsp                             # +0x063b
    call R04_REL32_S211_security_check_cookie       # +0x063e
    add rsp, 0xb0                                   # +0x0643
    pop r15                                         # +0x064a
    pop r14                                         # +0x064c
    pop r13                                         # +0x064e
    pop r12                                         # +0x0650
    pop rdi                                         # +0x0652
    pop rsi                                         # +0x0653
    pop rbx                                         # +0x0654
    ret                                             # +0x0655
    # two-byte alignment NOP before the tables
    xchg ax, ax                                     # +0x0656
    # Six image-relative case addresses, then 52 byte-sized case selectors for ASCII 0x45..0x78.
symbol_220:  # $LN120
    .rva R03_ADDR32NB_S223_LN48  # ACM_Print switch
    .rva R03_ADDR32NB_S222_LN35  # ACM_Print switch
    .rva R03_ADDR32NB_S221_LN26  # ACM_Print switch
    .rva R03_ADDR32NB_S224_LN53  # ACM_Print switch
    .rva R03_ADDR32NB_S225_LN54  # ACM_Print switch
    .rva R03_ADDR32NB_S227_LN63  # ACM_Print switch
symbol_219:  # $LN119
    .byte 0x00, 0x05, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05
    .byte 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x01, 0x05, 0x05, 0x05, 0x05
    .byte 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x02, 0x01, 0x00, 0x00, 0x00, 0x05
    .byte 0x01, 0x05, 0x05, 0x05, 0x05, 0x05, 0x01, 0x03, 0x05, 0x05, 0x04, 0x05
    .byte 0x01, 0x05, 0x05, 0x01
end_43:

.section a45,"dr"
# COFF section 45: .text$x
begin_45:
symbol_108:  # .text$x
# Start of the separately unwound catch funclet. RDX supplies the establisher frame.
symbol_208:  # ACM_Print$catch$0
    mov qword ptr [rsp + 0x10], rdx                 # +0x0000
    push rbp                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    {load} mov rbp, rdx                             # +0x000a
# Secondary label after the catch prologue, inside the same runtime function.
symbol_228:  # __catch$ACM_Print$0
    lea rax, [rip + R04_REL32_S457_C__0BH_LHFKCBLN_Exception_5in_5SuPrint_CI_CJ] # +0x000d
    mov qword ptr [rbp + 0x40], rax                 # +0x0014
    mov edx, 0x2a8                                  # +0x0018
    lea rcx, [rip + R04_REL32_S460_C__0CH_KHLIAMHM_SuPrint_CI_CJ_5Exception_5caught_5at_5l] # +0x001d
    call R04_REL32_S177_printf                      # +0x0024
    mov ecx, 1                                      # +0x0029
    call qword ptr [rip + R04_REL32_S174_imp___acrt_iob_func] # +0x002e
    {load} mov rcx, rax                             # +0x0034
    call qword ptr [rip + R04_REL32_S175_imp_fflush] # +0x0037
    nop                                             # +0x003d
    movabs rax, 0                                   # +0x003e
    add rsp, 0x20                                   # +0x0048
    pop rbp                                         # +0x004c
    ret                                             # +0x004d
    # One-byte INT3 padding after RET.
    int3                                            # +0x004e
end_45:

.section a46,"dr"
# COFF section 46: .text$mn
begin_46:
symbol_110:  # .text$mn
symbol_191:  # ACM_QueryInterface
    cmp dword ptr [rip + R05_REL32_1_S404_g_InitializationData_3UACMDLLInitializationData_A], 3 # +0x0000
    {load} mov r9, rcx                              # +0x0007
    jl .Lbb_46_001f                                 # +0x000a
    mov rcx, qword ptr [rip + 0x18 + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A] # +0x000c
    {load} mov r8, rdx                              # +0x0013
    {load} mov rdx, r9                              # +0x0016
    mov rax, qword ptr [rcx]                        # +0x0019
    rex.W jmp qword ptr [rax]                       # +0x001c
.Lbb_46_001f:
    mov eax, 0x80004005                             # +0x001f
    ret                                             # +0x0024
end_46:

.section a48,"dr"
# COFF section 48: .text$mn
begin_48:
symbol_114:  # .text$mn
symbol_199:  # ACM_RQST
symbol_235:  # $LN15
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    push rdi                                        # +0x000a
    sub rsp, 0x40                                   # +0x000b
    {load} mov rsi, rdx                             # +0x000f
    {load} mov rdi, rcx                             # +0x0012
    mov rcx, qword ptr [rip + R04_REL32_S402_g_pACMOptionsMgr_3PEAVACMOptionsHandler_EA] # +0x0015
    {load} xor edx, edx                             # +0x001c
    mov qword ptr [rsp + 0x30], rdx                 # +0x001e
    {load} mov rbx, r9                              # +0x0023
    test rcx, rcx                                   # +0x0026
    je .Lbb_48_008e                                 # +0x0029
    mov rax, qword ptr [rcx]                        # +0x002b
    {load} mov r9, r8                               # +0x002e
    mov dword ptr [rsp + 0x68], edx                 # +0x0031
    lea r8, [rsp + 0x68]                            # +0x0035
    lea rdx, [rsp + 0x30]                           # +0x003a
    mov qword ptr [rsp + 0x20], rdx                 # +0x003f
    mov edx, dword ptr [rdi]                        # +0x0044
    call qword ptr [rax]                            # +0x0046
    movsxd rcx, eax                                 # +0x0048
    mov rax, qword ptr [rsp + 0x70]                 # +0x004b
    mov qword ptr [rax], rcx                        # +0x0050
    mov rcx, qword ptr [rsp + 0x30]                 # +0x0053
    movsxd rax, dword ptr [rsp + 0x68]              # +0x0058
    mov qword ptr [rsi], rax                        # +0x005d
    test rcx, rcx                                   # +0x0060
    je .Lbb_48_00c0                                 # +0x0063
    {load} sub rbx, rcx                             # +0x0065
    {disp32} nop dword ptr [rax + rax]              # +0x0068
.Lbb_48_0070:
    movzx eax, byte ptr [rcx]                       # +0x0070
    mov byte ptr [rbx + rcx], al                    # +0x0073
    lea rcx, [rcx + 1]                              # +0x0076
    test al, al                                     # +0x007a
    jne .Lbb_48_0070                                # +0x007c
    mov rbx, qword ptr [rsp + 0x50]                 # +0x007e
    mov rsi, qword ptr [rsp + 0x58]                 # +0x0083
    add rsp, 0x40                                   # +0x0088
    pop rdi                                         # +0x008c
    ret                                             # +0x008d
.Lbb_48_008e:
    mov rax, qword ptr [rsp + 0x70]                 # +0x008e
    mov ecx, 0xa000ffff                             # +0x0093
    mov qword ptr [rax], 0xffffffffffffffff         # +0x0098
    mov qword ptr [rsi], rdx                        # +0x009f
    mov qword ptr [r8], rdx                         # +0x00a2
    {load} mov r8, rdi                              # +0x00a5
    lea rdx, [rip + R04_REL32_S410_C__0DJ_DBCOIJIF_ACM_5Solver_5options_5not_5availabl] # +0x00a8
    call R04_REL32_S188_ACM_Print                   # +0x00af
    test rdi, rdi                                   # +0x00b4
    jne .Lbb_48_00c0                                # +0x00b7
    {load} xor ecx, ecx                             # +0x00b9
    call R04_REL32_S197_ATInitialize                # +0x00bb
.Lbb_48_00c0:
    mov rbx, qword ptr [rsp + 0x50]                 # +0x00c0
    mov rsi, qword ptr [rsp + 0x58]                 # +0x00c5
    add rsp, 0x40                                   # +0x00ca
    pop rdi                                         # +0x00ce
    ret                                             # +0x00cf
end_48:

.section a50,"dr"
# COFF section 50: .text$mn
begin_50:
symbol_118:  # .text$mn
symbol_189:  # ACM_Rqst
symbol_230:  # $LN25
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rbp                 # +0x0005
    mov qword ptr [rsp + 0x18], rsi                 # +0x000a
    push rdi                                        # +0x000f
    sub rsp, 0x40                                   # +0x0010
    {load} xor ebp, ebp                             # +0x0014
    {load} mov rdi, rcx                             # +0x0016
    mov rcx, qword ptr [rip + R04_REL32_S402_g_pACMOptionsMgr_3PEAVACMOptionsHandler_EA] # +0x0019
    {load} mov rsi, r9                              # +0x0020
    mov qword ptr [rsp + 0x30], rbp                 # +0x0023
    test rcx, rcx                                   # +0x0028
    {disp32} je .Lbb_50_00ae                        # +0x002b
    mov rax, qword ptr [rcx]                        # +0x0031
    lea r9, [rsp + 0x30]                            # +0x0034
    mov qword ptr [rsp + 0x20], r9                  # +0x0039
    {load} mov r9, r8                               # +0x003e
    {load} mov r8, rdx                              # +0x0041
    mov edx, dword ptr [rdi]                        # +0x0044
    call qword ptr [rax]                            # +0x0046
    {load} mov edi, eax                             # +0x0048
    test rsi, rsi                                   # +0x004a
    {disp32} je .Lbb_50_00dc                        # +0x004d
    cmp eax, 3                                      # +0x0053
    {disp32} jl .Lbb_50_00dc                        # +0x0056
    mov rcx, qword ptr [rsp + 0x30]                 # +0x005c
    test rcx, rcx                                   # +0x0061
    je .Lbb_50_00a9                                 # +0x0064
    mov rbx, 0xffffffffffffffff                     # +0x0066
    nop dword ptr [rax]                             # +0x006d
.Lbb_50_0070:
    cmp byte ptr [rcx + rbx + 1], bpl               # +0x0070
    lea rbx, [rbx + 1]                              # +0x0075
    jne .Lbb_50_0070                                # +0x0079
    lea rcx, [rbx + 1]                              # +0x007b
    call R04_REL32_S166_U_YAPEAX_K_Z                # +0x007f
    mov rdx, qword ptr [rsp + 0x30]                 # +0x0084
    {load} mov r8, rax                              # +0x0089
    {disp8} nop dword ptr [rax]                     # +0x008c
.Lbb_50_0090:
    movzx ecx, byte ptr [rdx]                       # +0x0090
    lea rdx, [rdx + 1]                              # +0x0093
    mov byte ptr [r8], cl                           # +0x0097
    lea r8, [r8 + 1]                                # +0x009a
    test cl, cl                                     # +0x009e
    jne .Lbb_50_0090                                # +0x00a0
    mov qword ptr [rsi], rax                        # +0x00a2
    {load} mov eax, edi                             # +0x00a5
    jmp .Lbb_50_00dc                                # +0x00a7
.Lbb_50_00a9:
    mov qword ptr [rsi], rbp                        # +0x00a9
    jmp .Lbb_50_00dc                                # +0x00ac
.Lbb_50_00ae:
    mov dword ptr [rdx], ebp                        # +0x00ae
    mov ecx, 0xa000ffff                             # +0x00b0
    mov qword ptr [r8], rbp                         # +0x00b5
    lea rdx, [rip + R04_REL32_S413_C__0DH_KPCFCGDO_ACM_5Solver_5options_5not_5availabl] # +0x00b8
    {load} mov r8, rdi                              # +0x00bf
    mov rbx, 0xffffffffffffffff                     # +0x00c2
    call R04_REL32_S188_ACM_Print                   # +0x00c9
    test rdi, rdi                                   # +0x00ce
    jne .Lbb_50_00da                                # +0x00d1
    {load} xor ecx, ecx                             # +0x00d3
    call R04_REL32_S197_ATInitialize                # +0x00d5
.Lbb_50_00da:
    {load} mov eax, ebx                             # +0x00da
.Lbb_50_00dc:
    mov rbx, qword ptr [rsp + 0x50]                 # +0x00dc
    mov rbp, qword ptr [rsp + 0x58]                 # +0x00e1
    mov rsi, qword ptr [rsp + 0x60]                 # +0x00e6
    add rsp, 0x40                                   # +0x00eb
    pop rdi                                         # +0x00ef
    ret                                             # +0x00f0
end_50:

.section a52,"dr"
# COFF section 52: .text$mn
begin_52:
symbol_122:  # .text$mn
# RCX points to the initialization record. The tag is at +0.
symbol_197:  # ATInitialize
    # Null record returns 0.
    test rcx, rcx                                   # +0x0000
    je .Lbb_52_0061                                 # +0x0003
    # Read the 32-bit type tag.
    mov r8d, dword ptr [rcx]                        # +0x0005
    # Clear global problem handle before testing the non-null record type.
    mov qword ptr [rip + R08_REL32_4_S403_g_pACMProblemHandle_3PEAXEA], 0 # +0x0008
    sub r8d, 1                                      # +0x0013
    je .Lbb_52_0030                                 # +0x0017
    sub r8d, 1                                      # +0x0019
    je .Lbb_52_0025                                 # +0x001d
    cmp r8d, 1                                      # +0x001f
    jne .Lbb_52_0061                                # +0x0023
.Lbb_52_0025:
    # Types 2 and 3 publish the supplied problem handle at +0x18.
    mov rax, qword ptr [rcx + 0x18]                 # +0x0025
    mov qword ptr [rip + R04_REL32_S403_g_pACMProblemHandle_3PEAXEA], rax # +0x0029
.Lbb_52_0030:
    # Types 1, 2, 3 copy message/options pointers and the 32-byte descriptor.
    mov rax, qword ptr [rcx + 8]                    # +0x0030
    movups xmm0, xmmword ptr [rcx]                  # +0x0034
    mov qword ptr [rip + R04_REL32_S401_g_pACMMessageCollector_3PEAVACMMessagesHandler_EA], rax # +0x0037
    mov rax, qword ptr [rcx + 0x10]                 # +0x003e
    movups xmmword ptr [rip + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A], xmm0 # +0x0042
    mov qword ptr [rip + R04_REL32_S402_g_pACMOptionsMgr_3PEAVACMOptionsHandler_EA], rax # +0x0049
    # Return 1 for accepted versions.
    mov eax, 1                                      # +0x0050
    movups xmm1, xmmword ptr [rcx + 0x10]           # +0x0055
    movups xmmword ptr [rip + 0x10 + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A], xmm1 # +0x0059
    ret                                             # +0x0060
.Lbb_52_0061:
    # Null or unsupported version returns 0.
    {load} xor eax, eax                             # +0x0061
    ret                                             # +0x0063
end_52:

.section a54,"dr"
# COFF section 54: .text$mn
begin_54:
symbol_126:  # .text$mn
symbol_193:  # GetDLLInitializationData
    lea rax, [rip + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A] # +0x0000
    ret                                             # +0x0007
end_54:

.section a56,"dr"
# COFF section 56: .text$mn
begin_56:
symbol_130:  # .text$mn
symbol_194:  # RegisterDummyOptionsHandler
symbol_232:  # $LN10
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    mov rax, qword ptr [rip + R04_REL32_S402_g_pACMOptionsMgr_3PEAVACMOptionsHandler_EA] # +0x0006
    {load} xor ebx, ebx                             # +0x000d
    test rax, rax                                   # +0x000f
    mov qword ptr [rip + 0x10 + R04_REL32_S407_g_ProxyOptionsHandler_3VProxyOptionsHandler_A], rax # +0x0012
    lea rax, [rip + R04_REL32_S407_g_ProxyOptionsHandler_3VProxyOptionsHandler_A] # +0x0019
    mov qword ptr [rip + 8 + R04_REL32_S407_g_ProxyOptionsHandler_3VProxyOptionsHandler_A], rcx # +0x0020
    setne bl                                        # +0x0027
    mov qword ptr [rip + R04_REL32_S402_g_pACMOptionsMgr_3PEAVACMOptionsHandler_EA], rax # +0x002a
    mov qword ptr [rip + 0x10 + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A], rax # +0x0031
    test ebx, ebx                                   # +0x0038
    jne .Lbb_56_004e                                # +0x003a
    cmp dword ptr [rip + R04_REL32_S404_g_InitializationData_3UACMDLLInitializationData_A], ebx # +0x003c
    jne .Lbb_56_004e                                # +0x0042
    mov dword ptr [rip + R08_REL32_4_S404_g_InitializationData_3UACMDLLInitializationData_A], 1 # +0x0044
.Lbb_56_004e:
    cmp rcx, 1                                      # +0x004e
    jne .Lbb_56_005b                                # +0x0052
    {load} xor ecx, ecx                             # +0x0054
    call R04_REL32_S197_ATInitialize                # +0x0056
.Lbb_56_005b:
    xor ebx, 1                                      # +0x005b
    {load} mov eax, ebx                             # +0x005e
    add rsp, 0x20                                   # +0x0060
    pop rbx                                         # +0x0064
    ret                                             # +0x0065
end_56:

.section a58,"dr"
# COFF section 58: .text$mn
begin_58:
symbol_134:  # .text$mn
symbol_200:  # SuSkipPrint
    mov dword ptr [rip + R04_REL32_S418_g_bSkipPrint_3HA], ecx # +0x0000
    ret                                             # +0x0006
end_58:

.section a60,"dr"
# COFF section 60: .text$mn
begin_60:
symbol_138:  # .text$mn
symbol_173:  # __local_stdio_printf_options
    lea rax, [rip + R04_REL32_S397_OptionsStorage_1___local_stdio_printf_options_9_4_KA] # +0x0000
    ret                                             # +0x0007
end_60:

.section a62,"dr"
# COFF section 62: .text$mn
begin_62:
symbol_142:  # .text$mn
symbol_185:  # atutctof_array_str
symbol_216:  # $LN15
    mov qword ptr [rsp + 0x18], rbx                 # +0x0000
    mov qword ptr [rsp + 0x20], rbp                 # +0x0005
    push rsi                                        # +0x000a
    sub rsp, 0x20                                   # +0x000b
    {load} mov ebx, r8d                             # +0x000f
    {load} mov esi, edx                             # +0x0012
    {load} mov rbp, rcx                             # +0x0014
    test r8d, r8d                                   # +0x0017
    je .Lbb_62_005c                                 # +0x001a
    mov qword ptr [rsp + 0x30], rdi                 # +0x001c
    {load} mov eax, edx                             # +0x0021
    neg eax                                         # +0x0023
    mov qword ptr [rsp + 0x38], r14                 # +0x0025
    movsxd r14, eax                                 # +0x002a
    {load} mov eax, edx                             # +0x002d
    imul eax, ebx                                   # +0x002f
    movsxd rdi, eax                                 # +0x0032
    {load} add rdi, rcx                             # +0x0035
    {disp32} nop dword ptr [rax + rax]              # +0x0038
.Lbb_62_0040:
    {load} add rdi, r14                             # +0x0040
    {load} mov edx, esi                             # +0x0043
    {load} mov rcx, rdi                             # +0x0045
    call R04_REL32_S184_atutctof_str                # +0x0048
    sub ebx, 1                                      # +0x004d
    jne .Lbb_62_0040                                # +0x0050
    mov r14, qword ptr [rsp + 0x38]                 # +0x0052
    mov rdi, qword ptr [rsp + 0x30]                 # +0x0057
.Lbb_62_005c:
    mov rbx, qword ptr [rsp + 0x40]                 # +0x005c
    {load} mov rax, rbp                             # +0x0061
    mov rbp, qword ptr [rsp + 0x48]                 # +0x0064
    add rsp, 0x20                                   # +0x0069
    pop rsi                                         # +0x006d
    ret                                             # +0x006e
end_62:

.section a64,"dr"
# COFF section 64: .text$mn
begin_64:
symbol_146:  # .text$mn
symbol_184:  # atutctof_str
symbol_215:  # $LN22
    rex push rbx                                    # +0x0000
    sub rsp, 0x20                                   # +0x0002
    {load} mov rbx, rcx                             # +0x0006
    test edx, edx                                   # +0x0009
    je .Lbb_64_001f                                 # +0x000b
    nop dword ptr [rax]                             # +0x000d
.Lbb_64_0010:
    movzx eax, byte ptr [rcx]                       # +0x0010
    inc rcx                                         # +0x0013
    test al, al                                     # +0x0016
    je .Lbb_64_001f                                 # +0x0018
    sub edx, 1                                      # +0x001a
    jne .Lbb_64_0010                                # +0x001d
.Lbb_64_001f:
    dec rcx                                         # +0x001f
    test edx, edx                                   # +0x0022
    je .Lbb_64_0030                                 # +0x0024
    {load} mov r8d, edx                             # +0x0026
    mov dl, 0x20                                    # +0x0029
    call R04_REL32_S212_memset                      # +0x002b
.Lbb_64_0030:
    {load} mov rax, rbx                             # +0x0030
    add rsp, 0x20                                   # +0x0033
    pop rbx                                         # +0x0037
    ret                                             # +0x0038
end_64:

.section a66,"dr"
# COFF section 66: .text$mn
begin_66:
symbol_150:  # .text$mn
symbol_186:  # atutextract_c_str
symbol_218:  # $LN17
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    movsxd rax, edx                                 # +0x000a
    nop dword ptr [rax]                             # +0x000d
.Lbb_66_0010:
    movsxd r9, edx                                  # +0x0010
    dec edx                                         # +0x0013
    sub rax, 1                                      # +0x0015
    js .Lbb_66_002b                                 # +0x0019
    movzx r8d, byte ptr [rax + rcx]                 # +0x001b
    test r8b, r8b                                   # +0x0020
    je .Lbb_66_002b                                 # +0x0023
    cmp r8b, 0x20                                   # +0x0025
    je .Lbb_66_0010                                 # +0x0029
.Lbb_66_002b:
    {load} mov r8, rcx                              # +0x002b
    lea rdi, [rip + R04_REL32_S400_copy_buffer_3PADA] # +0x002e
    {load} mov rcx, rdi                             # +0x0035
    mov edx, 0x400                                  # +0x0038
    {load} mov rbx, r9                              # +0x003d
    call qword ptr [rip + R04_REL32_S181_imp_strncpy_s] # +0x0040
    cmp rbx, 0x400                                  # +0x0046
    jae .Lbb_66_0061                                # +0x004d
    mov byte ptr [rbx + rdi], 0                     # +0x004f
    {load} mov rax, rdi                             # +0x0053
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0056
    add rsp, 0x20                                   # +0x005b
    pop rdi                                         # +0x005f
    ret                                             # +0x0060
.Lbb_66_0061:
    call R04_REL32_S169_report_rangecheckfailure    # +0x0061
    int3                                            # +0x0066
symbol_217:  # $LN15
end_66:

.section a68,"dr"
# COFF section 68: .text$mn
begin_68:
symbol_154:  # .text$mn
symbol_187:  # atutextract_c_substr
    imul edx, r8d                                   # +0x0000
    {load} mov rax, rcx                             # +0x0004
    movsxd rcx, edx                                 # +0x0007
    {load} mov edx, r8d                             # +0x000a
    {load} add rcx, rax                             # +0x000d
    jmp R04_REL32_S186_atutextract_c_str            # +0x0010
end_68:

.section a70,"dr"
# COFF section 70: .text$mn
begin_70:
symbol_158:  # .text$mn
symbol_177:  # printf
symbol_213:  # $LN6
    mov qword ptr [rsp + 8], rcx                    # +0x0000
    mov qword ptr [rsp + 0x10], rdx                 # +0x0005
    mov qword ptr [rsp + 0x18], r8                  # +0x000a
    mov qword ptr [rsp + 0x20], r9                  # +0x000f
    push rbx                                        # +0x0014
    push rsi                                        # +0x0015
    push rdi                                        # +0x0016
    sub rsp, 0x30                                   # +0x0017
    {load} mov rdi, rcx                             # +0x001b
    lea rsi, [rsp + 0x58]                           # +0x001e
    mov ecx, 1                                      # +0x0023
    call qword ptr [rip + R04_REL32_S174_imp___acrt_iob_func] # +0x0028
    {load} mov rbx, rax                             # +0x002e
    call R04_REL32_S173_local_stdio_printf_options  # +0x0031
    {load} xor r9d, r9d                             # +0x0036
    mov qword ptr [rsp + 0x20], rsi                 # +0x0039
    {load} mov r8, rdi                              # +0x003e
    {load} mov rdx, rbx                             # +0x0041
    mov rcx, qword ptr [rax]                        # +0x0044
    call qword ptr [rip + R04_REL32_S176_imp___stdio_common_vfprintf] # +0x0047
    add rsp, 0x30                                   # +0x004d
    pop rdi                                         # +0x0051
    pop rsi                                         # +0x0052
    pop rbx                                         # +0x0053
    ret                                             # +0x0054
end_70:

.section a72,"dr"
# COFF section 72: .text$mn
begin_72:
symbol_162:  # .text$mn
symbol_179:  # sprintf_s
symbol_214:  # $LN6
    mov qword ptr [rsp + 0x18], r8                  # +0x0000
    mov qword ptr [rsp + 0x20], r9                  # +0x0005
    push rbx                                        # +0x000a
    push rbp                                        # +0x000b
    push rsi                                        # +0x000c
    push rdi                                        # +0x000d
    sub rsp, 0x38                                   # +0x000e
    {load} mov rsi, r8                              # +0x0012
    lea rbp, [rsp + 0x78]                           # +0x0015
    {load} mov rbx, rdx                             # +0x001a
    {load} mov rdi, rcx                             # +0x001d
    call R04_REL32_S173_local_stdio_printf_options  # +0x0020
    mov qword ptr [rsp + 0x28], rbp                 # +0x0025
    {load} mov r9, rsi                              # +0x002a
    {load} mov r8, rbx                              # +0x002d
    mov qword ptr [rsp + 0x20], 0                   # +0x0030
    {load} mov rdx, rdi                             # +0x0039
    mov rcx, qword ptr [rax]                        # +0x003c
    call qword ptr [rip + R04_REL32_S178_imp___stdio_common_vsprintf_s] # +0x003f
    test eax, eax                                   # +0x0045
    mov ecx, 0xffffffff                             # +0x0047
    cmovs eax, ecx                                  # +0x004c
    add rsp, 0x38                                   # +0x004f
    pop rdi                                         # +0x0053
    pop rsi                                         # +0x0054
    pop rbp                                         # +0x0055
    pop rbx                                         # +0x0056
    ret                                             # +0x0057
end_72:

.section a74,"dr"
# COFF section 74: .xdata
begin_74:
symbol_239:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=27, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x1b: ALLOC_SMALL 48
#   prologue +0x17: PUSH_NONVOL RDI
#   prologue +0x16: PUSH_NONVOL RSI
#   prologue +0x15: PUSH_NONVOL RBX
symbol_241:  # $unwind$printf
    .byte 0x01, 0x1b, 0x04, 0x00
    .byte 0x1b, 0x52, 0x17, 0x70
    .byte 0x16, 0x60, 0x15, 0x30
end_74:

.section a75,"dr"
# COFF section 75: .pdata
begin_75:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_242:  # .pdata
symbol_244:  # $pdata$printf
    .rva R03_ADDR32NB_S213_LN6  # begin RVA
    .rva R03_ADDR32NB_S213_LN6 + 85  # end RVA (exclusive)
    .rva R03_ADDR32NB_S241_unwind_printf  # unwind info RVA
end_75:

.section a76,"dr"
# COFF section 76: .xdata
begin_76:
symbol_245:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=18, unwind slots=5, frame register=0, scaled frame offset=0.
#   prologue +0x12: ALLOC_SMALL 56
#   prologue +0x0e: PUSH_NONVOL RDI
#   prologue +0x0d: PUSH_NONVOL RSI
#   prologue +0x0c: PUSH_NONVOL RBP
#   prologue +0x0b: PUSH_NONVOL RBX
symbol_247:  # $unwind$sprintf_s
    .byte 0x01, 0x12, 0x05, 0x00
    .byte 0x12, 0x62, 0x0e, 0x70
    .byte 0x0d, 0x60, 0x0c, 0x50
    .byte 0x0b, 0x30, 0x00, 0x00
end_76:

.section a77,"dr"
# COFF section 77: .pdata
begin_77:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_248:  # .pdata
symbol_250:  # $pdata$sprintf_s
    .rva R03_ADDR32NB_S214_LN6  # begin RVA
    .rva R03_ADDR32NB_S214_LN6 + 88  # end RVA (exclusive)
    .rva R03_ADDR32NB_S247_unwind_sprintf_s  # unwind info RVA
end_77:

.section a78,"dr"
# COFF section 78: .xdata
begin_78:
symbol_251:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_253:  # $unwind$atutctof_str
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_78:

.section a79,"dr"
# COFF section 79: .pdata
begin_79:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_254:  # .pdata
symbol_256:  # $pdata$atutctof_str
    .rva R03_ADDR32NB_S215_LN22  # begin RVA
    .rva R03_ADDR32NB_S215_LN22 + 57  # end RVA (exclusive)
    .rva R03_ADDR32NB_S253_unwind_atutctof_str  # unwind info RVA
end_79:

.section a80,"dr"
# COFF section 80: .xdata
begin_80:
symbol_257:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RBP, rsp+0x48
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x40
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RSI
symbol_259:  # $unwind$atutctof_array_str
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x54, 0x09, 0x00
    .byte 0x0f, 0x34, 0x08, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x60
end_80:

.section a81,"dr"
# COFF section 81: .pdata
begin_81:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_260:  # .pdata
symbol_262:  # $pdata$atutctof_array_str
    .rva R03_ADDR32NB_S216_LN15  # begin RVA
    .rva R03_ADDR32NB_S216_LN15 + 28  # end RVA (exclusive)
    .rva R03_ADDR32NB_S259_unwind_atutctof_array_str  # unwind info RVA
end_81:

.section a82,"dr"
# COFF section 82: .xdata
begin_82:
symbol_263:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=14, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0e: SAVE_NONVOL R14, rsp+0x38
#   prologue +0x05: SAVE_NONVOL RDI, rsp+0x30
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_265:  # $chain$1$atutctof_array_str
    .byte 0x21, 0x0e, 0x04, 0x00
    .byte 0x0e, 0xe4, 0x07, 0x00
    .byte 0x05, 0x74, 0x06, 0x00
    .rva R03_ADDR32NB_S216_LN15
    .rva R03_ADDR32NB_S216_LN15 + 28
    .rva R03_ADDR32NB_S259_unwind_atutctof_array_str
end_82:

.section a83,"dr"
# COFF section 83: .pdata
begin_83:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_266:  # .pdata
symbol_268:  # $pdata$1$atutctof_array_str
    .rva R03_ADDR32NB_S216_LN15 + 28  # begin RVA
    .rva R03_ADDR32NB_S216_LN15 + 92  # end RVA (exclusive)
    .rva R03_ADDR32NB_S265_chain_1_atutctof_array_str  # unwind info RVA
end_83:

.section a84,"dr"
# COFF section 84: .xdata
begin_84:
symbol_269:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_271:  # $chain$2$atutctof_array_str
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S216_LN15
    .rva R03_ADDR32NB_S216_LN15 + 28
    .rva R03_ADDR32NB_S259_unwind_atutctof_array_str
end_84:

.section a85,"dr"
# COFF section 85: .pdata
begin_85:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_272:  # .pdata
symbol_274:  # $pdata$2$atutctof_array_str
    .rva R03_ADDR32NB_S216_LN15 + 92  # begin RVA
    .rva R03_ADDR32NB_S216_LN15 + 111  # end RVA (exclusive)
    .rva R03_ADDR32NB_S271_chain_2_atutctof_array_str  # unwind info RVA
end_85:

.section a86,"dr"
# COFF section 86: .xdata
begin_86:
symbol_275:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_277:  # $unwind$atutextract_c_str
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x34, 0x06, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_86:

.section a87,"dr"
# COFF section 87: .pdata
begin_87:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_278:  # .pdata
symbol_280:  # $pdata$atutextract_c_str
    .rva R03_ADDR32NB_S218_LN17  # begin RVA
    .rva R03_ADDR32NB_S218_LN17 + 103  # end RVA (exclusive)
    .rva R03_ADDR32NB_S277_unwind_atutextract_c_str  # unwind info RVA
end_87:

.section a88,"dr"
# COFF section 88: .xdata
begin_88:
symbol_281:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=51, unwind slots=9, frame register=0, scaled frame offset=0.
#   prologue +0x21: ALLOC_LARGE 176
#   prologue +0x1a: PUSH_NONVOL R15
#   prologue +0x18: PUSH_NONVOL R14
#   prologue +0x16: PUSH_NONVOL R13
#   prologue +0x14: PUSH_NONVOL R12
#   prologue +0x12: PUSH_NONVOL RDI
#   prologue +0x11: PUSH_NONVOL RSI
#   prologue +0x10: PUSH_NONVOL RBX
symbol_283:  # $unwind$ACM_Print
    .byte 0x19, 0x33, 0x09, 0x00
    .byte 0x21, 0x01, 0x16, 0x00
    .byte 0x1a, 0xf0, 0x18, 0xe0
    .byte 0x16, 0xd0, 0x14, 0xc0
    .byte 0x12, 0x70, 0x11, 0x60
    .byte 0x10, 0x30, 0x00, 0x00
    .rva R03_ADDR32NB_S210_GSHandlerCheck_EH4
    .rva R03_ADDR32NB_S289_cppxdata_ACM_Print
    .byte 0xa3, 0x00, 0x00, 0x00
end_88:

.section a89,"dr"
# COFF section 89: .pdata
begin_89:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_284:  # .pdata
symbol_286:  # $pdata$ACM_Print
    .rva R03_ADDR32NB_S229_LN132  # begin RVA
    .rva R03_ADDR32NB_S229_LN132 + 1700  # end RVA (exclusive)
    .rva R03_ADDR32NB_S283_unwind_ACM_Print  # unwind info RVA
end_89:

.section a90,"dr"
# COFF section 90: .xdata
begin_90:
symbol_287:  # .xdata
# FH4 function descriptor. Fields that address another section carry an RVA relocation.
symbol_289:  # $cppxdata$ACM_Print
    .byte 0x38
    .rva R03_ADDR32NB_S292_stateUnwindMap_ACM_Print
    .rva R03_ADDR32NB_S295_tryMap_ACM_Print
    .rva R03_ADDR32NB_S301_ip2state_ACM_Print
end_90:

.section a91,"dr"
# COFF section 91: .xdata
begin_91:
symbol_290:  # .xdata
# FH4 state unwind map. Fields that address another section carry an RVA relocation.
symbol_292:  # $stateUnwindMap$ACM_Print
    .byte 0x04, 0x08, 0x10
end_91:

.section a92,"dr"
# COFF section 92: .xdata
begin_92:
symbol_293:  # .xdata
# FH4 try block map. Fields that address another section carry an RVA relocation.
symbol_295:  # $tryMap$ACM_Print
    .byte 0x02, 0x00, 0x00, 0x02
    .rva R03_ADDR32NB_S298_handlerMap_ACM_Print
end_92:

.section a93,"dr"
# COFF section 93: .xdata
begin_93:
symbol_296:  # .xdata
# FH4 catch handler map. Fields that address another section carry an RVA relocation.
symbol_298:  # $handlerMap$ACM_Print
    .byte 0x02, 0x11, 0x80
    .rva R03_ADDR32NB_S208_ACM_Print_catch_0
    .byte 0x79, 0x14
end_93:

.section a94,"dr"
# COFF section 94: .xdata
begin_94:
symbol_299:  # .xdata
# FH4 IP-to-state map. Fields that address another section carry an RVA relocation.
symbol_301:  # $ip2state$ACM_Print
    .byte 0x08, 0x69, 0x03, 0x00
    .byte 0xb9, 0x04, 0x02, 0x51
    .byte 0x0c, 0x00, 0xf1, 0x04
    .byte 0x02
end_94:

.section a95,"dr"
# COFF section 95: .xdata
begin_95:
symbol_302:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RBP
symbol_304:  # $unwind$ACM_Print$catch$0
    .byte 0x01, 0x0a, 0x02, 0x00
    .byte 0x0a, 0x32, 0x06, 0x50
end_95:

.section a96,"dr"
# COFF section 96: .pdata
begin_96:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_305:  # .pdata
symbol_307:  # $pdata$ACM_Print$catch$0
    .rva R03_ADDR32NB_S208_ACM_Print_catch_0  # begin RVA
    .rva R03_ADDR32NB_S208_ACM_Print_catch_0 + 79  # end RVA (exclusive)
    .rva R03_ADDR32NB_S304_unwind_ACM_Print_catch_0  # unwind info RVA
end_96:

.section a97,"dr"
# COFF section 97: .voltbl
begin_97:
symbol_308:  # .voltbl
symbol_310:  # _volmd
    .byte 0x00
end_97:

.section a98,"dr"
# COFF section 98: .xdata
begin_98:
symbol_311:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=20, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x14: SAVE_NONVOL RSI, rsp+0x60
#   prologue +0x14: SAVE_NONVOL RBP, rsp+0x58
#   prologue +0x14: SAVE_NONVOL RBX, rsp+0x50
#   prologue +0x14: ALLOC_SMALL 64
#   prologue +0x10: PUSH_NONVOL RDI
symbol_313:  # $unwind$ACM_Rqst
    .byte 0x01, 0x14, 0x08, 0x00
    .byte 0x14, 0x64, 0x0c, 0x00
    .byte 0x14, 0x54, 0x0b, 0x00
    .byte 0x14, 0x34, 0x0a, 0x00
    .byte 0x14, 0x72, 0x10, 0x70
end_98:

.section a99,"dr"
# COFF section 99: .pdata
begin_99:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_314:  # .pdata
symbol_316:  # $pdata$ACM_Rqst
    .rva R03_ADDR32NB_S230_LN25  # begin RVA
    .rva R03_ADDR32NB_S230_LN25 + 241  # end RVA (exclusive)
    .rva R03_ADDR32NB_S313_unwind_ACM_Rqst  # unwind info RVA
end_99:

.section a100,"dr"
# COFF section 100: .xdata
begin_100:
symbol_317:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x0f: ALLOC_SMALL 32
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_319:  # $unwind$ACM_GetComponents
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x07, 0x00
    .byte 0x0f, 0x34, 0x06, 0x00
    .byte 0x0f, 0x32, 0x0b, 0x70
end_100:

.section a101,"dr"
# COFF section 101: .pdata
begin_101:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_320:  # .pdata
symbol_322:  # $pdata$ACM_GetComponents
    .rva R03_ADDR32NB_S231_LN10  # begin RVA
    .rva R03_ADDR32NB_S231_LN10 + 130  # end RVA (exclusive)
    .rva R03_ADDR32NB_S319_unwind_ACM_GetComponents  # unwind info RVA
end_101:

.section a102,"dr"
# COFF section 102: .xdata
begin_102:
symbol_323:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_325:  # $unwind$RegisterDummyOptionsHandler
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_102:

.section a103,"dr"
# COFF section 103: .pdata
begin_103:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_326:  # .pdata
symbol_328:  # $pdata$RegisterDummyOptionsHandler
    .rva R03_ADDR32NB_S232_LN10  # begin RVA
    .rva R03_ADDR32NB_S232_LN10 + 102  # end RVA (exclusive)
    .rva R03_ADDR32NB_S325_unwind_RegisterDummyOptionsHandler  # unwind info RVA
end_103:

.section a104,"dr"
# COFF section 104: .xdata
begin_104:
symbol_329:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=26, unwind slots=10, frame register=0, scaled frame offset=0.
#   prologue +0x1a: SAVE_NONVOL RDI, rsp+0x58
#   prologue +0x1a: SAVE_NONVOL RSI, rsp+0x50
#   prologue +0x1a: SAVE_NONVOL RBP, rsp+0x48
#   prologue +0x1a: SAVE_NONVOL RBX, rsp+0x40
#   prologue +0x1a: ALLOC_SMALL 48
#   prologue +0x16: PUSH_NONVOL R14
symbol_331:  # $unwind$?OptionRequest@ProxyOptionsHandler@@UEAAHHPEAHPEANPEAPEAD@Z
    .byte 0x01, 0x1a, 0x0a, 0x00
    .byte 0x1a, 0x74, 0x0b, 0x00
    .byte 0x1a, 0x64, 0x0a, 0x00
    .byte 0x1a, 0x54, 0x09, 0x00
    .byte 0x1a, 0x34, 0x08, 0x00
    .byte 0x1a, 0x52, 0x16, 0xe0
end_104:

.section a105,"dr"
# COFF section 105: .pdata
begin_105:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_332:  # .pdata
symbol_334:  # $pdata$?OptionRequest@ProxyOptionsHandler@@UEAAHHPEAHPEANPEAPEAD@Z
    .rva R03_ADDR32NB_S233_LN13  # begin RVA
    .rva R03_ADDR32NB_S233_LN13 + 127  # end RVA (exclusive)
    .rva R03_ADDR32NB_S331_unwind_OptionRequest_ProxyOptionsHandler_UEAAHHPEAHPEANPEAPEAD_Z  # unwind info RVA
end_105:

.section a106,"dr"
# COFF section 106: .xdata
begin_106:
symbol_335:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=28, unwind slots=12, frame register=0, scaled frame offset=0.
#   prologue +0x1c: SAVE_NONVOL RSI, rsp+0x60
#   prologue +0x1c: SAVE_NONVOL RBP, rsp+0x58
#   prologue +0x1c: SAVE_NONVOL RBX, rsp+0x50
#   prologue +0x1c: ALLOC_SMALL 32
#   prologue +0x18: PUSH_NONVOL R15
#   prologue +0x16: PUSH_NONVOL R14
#   prologue +0x14: PUSH_NONVOL R13
#   prologue +0x12: PUSH_NONVOL R12
#   prologue +0x10: PUSH_NONVOL RDI
symbol_337:  # $unwind$ACM_GETCOMPONENTS
    .byte 0x01, 0x1c, 0x0c, 0x00
    .byte 0x1c, 0x64, 0x0c, 0x00
    .byte 0x1c, 0x54, 0x0b, 0x00
    .byte 0x1c, 0x34, 0x0a, 0x00
    .byte 0x1c, 0x32, 0x18, 0xf0
    .byte 0x16, 0xe0, 0x14, 0xd0
    .byte 0x12, 0xc0, 0x10, 0x70
end_106:

.section a107,"dr"
# COFF section 107: .pdata
begin_107:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_338:  # .pdata
symbol_340:  # $pdata$ACM_GETCOMPONENTS
    .rva R03_ADDR32NB_S234_LN22  # begin RVA
    .rva R03_ADDR32NB_S234_LN22 + 230  # end RVA (exclusive)
    .rva R03_ADDR32NB_S337_unwind_ACM_GETCOMPONENTS  # unwind info RVA
end_107:

.section a108,"dr"
# COFF section 108: .xdata
begin_108:
symbol_341:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=15, unwind slots=6, frame register=0, scaled frame offset=0.
#   prologue +0x0f: SAVE_NONVOL RSI, rsp+0x58
#   prologue +0x0f: SAVE_NONVOL RBX, rsp+0x50
#   prologue +0x0f: ALLOC_SMALL 64
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_343:  # $unwind$ACM_RQST
    .byte 0x01, 0x0f, 0x06, 0x00
    .byte 0x0f, 0x64, 0x0b, 0x00
    .byte 0x0f, 0x34, 0x0a, 0x00
    .byte 0x0f, 0x72, 0x0b, 0x70
end_108:

.section a109,"dr"
# COFF section 109: .pdata
begin_109:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_344:  # .pdata
symbol_346:  # $pdata$ACM_RQST
    .rva R03_ADDR32NB_S235_LN15  # begin RVA
    .rva R03_ADDR32NB_S235_LN15 + 208  # end RVA (exclusive)
    .rva R03_ADDR32NB_S343_unwind_ACM_RQST  # unwind info RVA
end_109:

.section a110,"dr"
# COFF section 110: .xdata
begin_110:
symbol_347:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 40
symbol_349:  # $unwind$?writeBuffer@@YAXPEAVACMMessagesHandler@@@Z
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x42, 0x00, 0x00
end_110:

.section a111,"dr"
# COFF section 111: .pdata
begin_111:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_350:  # .pdata
symbol_352:  # $pdata$?writeBuffer@@YAXPEAVACMMessagesHandler@@@Z
    .rva R03_ADDR32NB_S201_writeBuffer_YAXPEAVACMMessagesHandler_Z  # begin RVA
    .rva R03_ADDR32NB_S201_writeBuffer_YAXPEAVACMMessagesHandler_Z + 116  # end RVA (exclusive)
    .rva R03_ADDR32NB_S349_unwind_writeBuffer_YAXPEAVACMMessagesHandler_Z  # unwind info RVA
end_111:

.section a112,"dr"
# COFF section 112: .xdata
begin_112:
symbol_353:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=28, unwind slots=12, frame register=0, scaled frame offset=0.
#   prologue +0x1c: SAVE_NONVOL RSI, rsp+0x60
#   prologue +0x1c: SAVE_NONVOL RBP, rsp+0x58
#   prologue +0x1c: SAVE_NONVOL RBX, rsp+0x50
#   prologue +0x1c: ALLOC_SMALL 32
#   prologue +0x18: PUSH_NONVOL R15
#   prologue +0x16: PUSH_NONVOL R14
#   prologue +0x14: PUSH_NONVOL R13
#   prologue +0x12: PUSH_NONVOL R12
#   prologue +0x10: PUSH_NONVOL RDI
symbol_355:  # $unwind$?LineSplit@@YAXPEAVACMMessagesHandler@@@Z
    .byte 0x01, 0x1c, 0x0c, 0x00
    .byte 0x1c, 0x64, 0x0c, 0x00
    .byte 0x1c, 0x54, 0x0b, 0x00
    .byte 0x1c, 0x34, 0x0a, 0x00
    .byte 0x1c, 0x32, 0x18, 0xf0
    .byte 0x16, 0xe0, 0x14, 0xd0
    .byte 0x12, 0xc0, 0x10, 0x70
end_112:

.section a113,"dr"
# COFF section 113: .pdata
begin_113:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_356:  # .pdata
symbol_358:  # $pdata$?LineSplit@@YAXPEAVACMMessagesHandler@@@Z
    .rva R03_ADDR32NB_S202_LineSplit_YAXPEAVACMMessagesHandler_Z  # begin RVA
    .rva R03_ADDR32NB_S202_LineSplit_YAXPEAVACMMessagesHandler_Z + 243  # end RVA (exclusive)
    .rva R03_ADDR32NB_S355_unwind_LineSplit_YAXPEAVACMMessagesHandler_Z  # unwind info RVA
end_113:

.section a114,"dr"
# COFF section 114: .xdata
begin_114:
symbol_359:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=6, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x06: ALLOC_SMALL 32
#   prologue +0x02: PUSH_NONVOL RBX
symbol_361:  # $unwind$?writeChar@@YAXDPEAVACMMessagesHandler@@@Z
    .byte 0x01, 0x06, 0x02, 0x00
    .byte 0x06, 0x32, 0x02, 0x30
end_114:

.section a115,"dr"
# COFF section 115: .pdata
begin_115:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_362:  # .pdata
symbol_364:  # $pdata$?writeChar@@YAXDPEAVACMMessagesHandler@@@Z
    .rva R03_ADDR32NB_S203_writeChar_YAXDPEAVACMMessagesHandler_Z  # begin RVA
    .rva R03_ADDR32NB_S203_writeChar_YAXDPEAVACMMessagesHandler_Z + 92  # end RVA (exclusive)
    .rva R03_ADDR32NB_S361_unwind_writeChar_YAXDPEAVACMMessagesHandler_Z  # unwind info RVA
end_115:

.section a116,"dr"
# COFF section 116: .xdata
begin_116:
symbol_365:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=19, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x13: SAVE_NONVOL RSI, rsp+0x50
#   prologue +0x13: SAVE_NONVOL RBX, rsp+0x48
#   prologue +0x13: ALLOC_SMALL 32
#   prologue +0x0f: PUSH_NONVOL R15
#   prologue +0x0d: PUSH_NONVOL R14
#   prologue +0x0b: PUSH_NONVOL RDI
symbol_367:  # $unwind$?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    .byte 0x01, 0x13, 0x08, 0x00
    .byte 0x13, 0x64, 0x0a, 0x00
    .byte 0x13, 0x34, 0x09, 0x00
    .byte 0x13, 0x32, 0x0f, 0xf0
    .byte 0x0d, 0xe0, 0x0b, 0x70
end_116:

.section a117,"dr"
# COFF section 117: .pdata
begin_117:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_368:  # .pdata
symbol_370:  # $pdata$?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z  # begin RVA
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 120  # end RVA (exclusive)
    .rva R03_ADDR32NB_S367_unwind_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z  # unwind info RVA
end_117:

.section a118,"dr"
# COFF section 118: .xdata
begin_118:
symbol_371:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RBP, rsp+0x40
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_373:  # $chain$0$?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x54, 0x08, 0x00
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 120
    .rva R03_ADDR32NB_S367_unwind_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z
end_118:

.section a119,"dr"
# COFF section 119: .pdata
begin_119:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_374:  # .pdata
symbol_376:  # $pdata$0$?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 120  # begin RVA
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 218  # end RVA (exclusive)
    .rva R03_ADDR32NB_S373_chain_0_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z  # unwind info RVA
end_119:

.section a120,"dr"
# COFF section 120: .xdata
begin_120:
symbol_377:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_379:  # $chain$1$?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 120
    .rva R03_ADDR32NB_S367_unwind_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z
end_120:

.section a121,"dr"
# COFF section 121: .pdata
begin_121:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_380:  # .pdata
symbol_382:  # $pdata$1$?ParseFormat@@YAPEBDPEADAEAHAEADAEAPEAD@Z
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 218  # begin RVA
    .rva R03_ADDR32NB_S204_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z + 533  # end RVA (exclusive)
    .rva R03_ADDR32NB_S379_chain_1_ParseFormat_YAPEBDPEADAEAHAEADAEAPEAD_Z  # unwind info RVA
end_121:

.section a122,"dr"
# COFF section 122: .xdata
begin_122:
symbol_383:  # .xdata
# UNWIND_INFO v1, flags=3, prologue length=34, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x10: ALLOC_LARGE 1112
#   prologue +0x09: PUSH_NONVOL R15
#   prologue +0x07: PUSH_NONVOL R14
#   prologue +0x05: PUSH_NONVOL RDI
#   prologue +0x04: PUSH_NONVOL RSI
#   prologue +0x03: PUSH_NONVOL RBP
#   prologue +0x02: PUSH_NONVOL RBX
symbol_385:  # $unwind$ACM_PRINT
    .byte 0x19, 0x22, 0x08, 0x00
    .byte 0x10, 0x01, 0x8b, 0x00
    .byte 0x09, 0xf0, 0x07, 0xe0
    .byte 0x05, 0x70, 0x04, 0x60
    .byte 0x03, 0x50, 0x02, 0x30
    .rva R03_ADDR32NB_S209_GSHandlerCheck
    .byte 0x40, 0x04, 0x00, 0x00
end_122:

.section a123,"dr"
# COFF section 123: .pdata
begin_123:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_386:  # .pdata
symbol_388:  # $pdata$ACM_PRINT
    .rva R03_ADDR32NB_S237_LN9  # begin RVA
    .rva R03_ADDR32NB_S237_LN9 + 196  # end RVA (exclusive)
    .rva R03_ADDR32NB_S385_unwind_ACM_PRINT  # unwind info RVA
end_123:

.section a124,"dr"
# COFF section 124: .xdata
begin_124:
symbol_389:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=26, unwind slots=10, frame register=0, scaled frame offset=0.
#   prologue +0x1a: SAVE_NONVOL RDI, rsp+0x48
#   prologue +0x1a: SAVE_NONVOL RSI, rsp+0x40
#   prologue +0x1a: SAVE_NONVOL RBP, rsp+0x38
#   prologue +0x1a: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x1a: ALLOC_SMALL 32
#   prologue +0x16: PUSH_NONVOL R14
symbol_391:  # $unwind$ACM_PRINTPP
    .byte 0x01, 0x1a, 0x0a, 0x00
    .byte 0x1a, 0x74, 0x09, 0x00
    .byte 0x1a, 0x64, 0x08, 0x00
    .byte 0x1a, 0x54, 0x07, 0x00
    .byte 0x1a, 0x34, 0x06, 0x00
    .byte 0x1a, 0x32, 0x16, 0xe0
end_124:

.section a125,"dr"
# COFF section 125: .pdata
begin_125:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_392:  # .pdata
symbol_394:  # $pdata$ACM_PRINTPP
    .rva R03_ADDR32NB_S238_LN24  # begin RVA
    .rva R03_ADDR32NB_S238_LN24 + 206  # end RVA (exclusive)
    .rva R03_ADDR32NB_S391_unwind_ACM_PRINTPP  # unwind info RVA
end_125:

.section a128,"dr"
# COFF section 128: .data
begin_128:
symbol_405:  # .data
symbol_407:  # ?g_ProxyOptionsHandler@@3VProxyOptionsHandler@@A
    .quad R01_ADDR64_S53_7ProxyOptionsHandler_6B
    .zero 16
end_128:

.section a129,"dr"
# COFF section 129: .rdata
begin_129:
symbol_408:  # .rdata
symbol_410:  # ??_C@_0DJ@DBCOIJIF@ACM?5Solver?5options?5not?5availabl@
    .ascii "ACM Solver options not available, ACM_RQST_F %d refused"
    .byte 0x0a, 0x00
end_129:

.section a130,"dr"
# COFF section 130: .rdata
begin_130:
symbol_411:  # .rdata
symbol_413:  # ??_C@_0DH@KPCFCGDO@ACM?5Solver?5options?5not?5availabl@
    .ascii "ACM Solver options not available, ACM_Rqst %d refused"
    .byte 0x0a, 0x00
end_130:

.section a131,"dr"
# COFF section 131: .rdata
begin_131:
symbol_419:  # .rdata
symbol_421:  # ??_C@_03OFAPEBGM@?$CFs?6@
    .byte 0x25, 0x73, 0x0a, 0x00
end_131:

.section a132,"dr"
# COFF section 132: .rdata
begin_132:
symbol_422:  # .rdata
symbol_424:  # ??_C@_05DFNBJPIB@?9?$CL0?5?$CD@
    .ascii "-+0 #\000"
end_132:

.section a133,"dr"
# COFF section 133: .rdata
begin_133:
symbol_425:  # .rdata
symbol_427:  # ??_C@_0DB@IDCMHCHC@BAD?5FORMATTING?5?$CIwidth?5exceeds?55@
    .ascii "BAD FORMATTING (width exceeds 512 characters)>>>\000"
end_133:

.section a134,"dr"
# COFF section 134: .rdata
begin_134:
symbol_428:  # .rdata
symbol_430:  # ??_C@_0CK@MDKJFNJN@BAD?5FORMATTING?5?$CIwidth?5digits?5ex@
    .ascii "BAD FORMATTING (width digits expected)>>>\000"
end_134:

.section a135,"dr"
# COFF section 135: .rdata
begin_135:
symbol_431:  # .rdata
symbol_433:  # ??_C@_0CO@IPJAOOJD@BAD?5FORMATTING?5?$CIprecision?5digit@
    .ascii "BAD FORMATTING (precision digits expected)>>>\000"
end_135:

.section a136,"dr"
# COFF section 136: .rdata
begin_136:
symbol_434:  # .rdata
symbol_436:  # ??_C@_03DNCIMNEC@hlL@
    .ascii "hlL\000"
end_136:

.section a137,"dr"
# COFF section 137: .rdata
begin_137:
symbol_437:  # .rdata
symbol_439:  # ??_C@_03KDGLFNIB@I64@
    .ascii "I64\000"
end_137:

.section a138,"dr"
# COFF section 138: .rdata
begin_138:
symbol_440:  # .rdata
symbol_442:  # ??_C@_0BA@DCHJBDJG@cdiouxXfeEgGps?$CG@
    .ascii "cdiouxXfeEgGps&\000"
end_138:

.section a139,"dr"
# COFF section 139: .rdata
begin_139:
symbol_443:  # .rdata
symbol_445:  # ??_C@_0DA@LEBIJPNO@BAD?5FORMATTING?5?$CIunrecognized?5ty@
    .ascii "BAD FORMATTING (unrecognized type specifier)>>>\000"
end_139:

.section a142,"dr"
# COFF section 142: .rdata
begin_142:
symbol_452:  # .rdata
symbol_454:  # ??_C@_07KAJBENLI@Error?3?5@
    .ascii "Error: \000"
end_142:

.section a143,"dr"
# COFF section 143: .rdata
begin_143:
symbol_455:  # .rdata
symbol_457:  # ??_C@_0BH@LHFKCBLN@Exception?5in?5SuPrint?$CI?$CJ@
    .ascii "Exception in SuPrint()\000"
end_143:

.section a144,"dr"
# COFF section 144: .rdata
begin_144:
symbol_458:  # .rdata
symbol_460:  # ??_C@_0CH@KHLIAMHM@SuPrint?$CI?$CJ?5Exception?5caught?5at?5l@
    .ascii "SuPrint() Exception caught at line %d"
    .byte 0x0a, 0x00
end_144:

.section a145,"dr"
# COFF section 145: .rdata
begin_145:
symbol_461:  # .rdata
symbol_463:  # ??_C@_0CP@CGDDAJKF@BAD?5FORMATTING?5?$CItoo?5many?5format@
    .ascii "BAD FORMATTING (too many format specifiers)>>>\000"
end_145:

.section a146,"dr"
# COFF section 146: .rdata
begin_146:
symbol_464:  # .rdata
symbol_466:  # ??_C@_0CB@LLCHLDHM@SuPrint?$CI?$CJ?5Bad?5format?5at?5line?5?$CFd@
    .ascii "SuPrint() Bad format at line %d"
    .byte 0x0a, 0x00
end_146:

.section a147,"dr"
# COFF section 147: .rdata
begin_147:
symbol_467:  # .rdata
symbol_469:  # ??_C@_0CI@MFJNBOMC@BAD?5FORMATTING?5?$CIcheck?5format?5st@
    .ascii "BAD FORMATTING (check format string)>>>\000"
end_147:

.section a148,"dr"
# COFF section 148: .rdata
begin_148:
symbol_470:  # .rdata
symbol_472:  # ??_C@_0L@DCCGFMBN@Error?3?5?$CFs?6@
    .ascii "Error: %s"
    .byte 0x0a, 0x00
end_148:

.section a149,"dr"
# COFF section 149: .CRT$XCU
begin_149:
symbol_476:  # .CRT$XCU
symbol_478:  # ?g_ProxyOptionsHandler$initializer$@@3P6AXXZEA
    .quad R01_ADDR64_S195_Eg_ProxyOptionsHandler_YAXXZ
end_149:
