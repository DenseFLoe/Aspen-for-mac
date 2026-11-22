# AMD64 COFF member .\Release\ACMException.obj
# External reference identifiers encode the original relocation type, COFF symbol index and name.
.intel_syntax noprefix

.section a1,"dr"
# COFF section 1: .drectve
begin_1:
symbol_3:  # .drectve
    .ascii "   /DEFAULTLIB:\"uuid.lib\" /DEFAULTLIB:\"uuid.lib\" /DEFAULTLIB:\"MSVCRT\" /DEFAULTLIB:\"OLDNAMES\" "
end_1:

.section a3,"dr"
# COFF section 3: .text$mn
begin_3:
symbol_7:  # .text$mn
symbol_35:  # ??0CACMException@@QEAA@AEBV0@@Z
symbol_42:  # $LN6
    mov qword ptr [rsp + 8], rbx                    # +0x0000
    mov qword ptr [rsp + 0x10], rsi                 # +0x0005
    mov qword ptr [rsp + 0x18], rdi                 # +0x000a
    push r14                                        # +0x000f
    sub rsp, 0x20                                   # +0x0011
    mov eax, dword ptr [rdx]                        # +0x0015
    {load} mov r14, rcx                             # +0x0017
    mov dword ptr [rcx], eax                        # +0x001a
    {load} mov rsi, rdx                             # +0x001c
    {load} mov rcx, rdx                             # +0x001f
    call R04_REL32_S37_GetText_CACMException_QEBAQEADXZ # +0x0022
    mov rbx, 0xffffffffffffffff                     # +0x0027
    xchg ax, ax                                     # +0x002e
.Lbb_3_0030:
    cmp byte ptr [rax + rbx + 1], 0                 # +0x0030
    lea rbx, [rbx + 1]                              # +0x0035
    jne .Lbb_3_0030                                 # +0x0039
    lea rcx, [rbx + 1]                              # +0x003b
    call R04_REL32_S31_U_YAPEAX_K_Z                 # +0x003f
    {load} mov rcx, rsi                             # +0x0044
    mov qword ptr [r14 + 8], rax                    # +0x0047
    {load} mov rdi, rax                             # +0x004b
    call R04_REL32_S37_GetText_CACMException_QEBAQEADXZ # +0x004e
    {load} mov r8, rax                              # +0x0053
    lea rdx, [rbx + 1]                              # +0x0056
    {load} mov rcx, rdi                             # +0x005a
    call qword ptr [rip + R04_REL32_S33_imp_strcpy_s] # +0x005d
    mov rbx, qword ptr [rsp + 0x30]                 # +0x0063
    {load} mov rax, r14                             # +0x0068
    mov rsi, qword ptr [rsp + 0x38]                 # +0x006b
    mov rdi, qword ptr [rsp + 0x40]                 # +0x0070
    add rsp, 0x20                                   # +0x0075
    pop r14                                         # +0x0079
    ret                                             # +0x007b
end_3:

.section a5,"dr"
# COFF section 5: .text$mn
begin_5:
symbol_11:  # .text$mn
symbol_34:  # ??0CACMException@@QEAA@KPEAD@Z
symbol_41:  # $LN10
    mov qword ptr [rsp + 0x10], rsi                 # +0x0000
    push rdi                                        # +0x0005
    sub rsp, 0x20                                   # +0x0006
    mov dword ptr [rcx], edx                        # +0x000a
    {load} mov rdi, r8                              # +0x000c
    {load} mov rsi, rcx                             # +0x000f
    test r8, r8                                     # +0x0012
    je .Lbb_5_005f                                  # +0x0015
    mov qword ptr [rsp + 0x30], rbx                 # +0x0017
    mov rbx, 0xffffffffffffffff                     # +0x001c
.Lbb_5_0023:
    cmp byte ptr [r8 + rbx + 1], 0                  # +0x0023
    lea rbx, [rbx + 1]                              # +0x0029
    jne .Lbb_5_0023                                 # +0x002d
    lea rcx, [rbx + 1]                              # +0x002f
    call R04_REL32_S31_U_YAPEAX_K_Z                 # +0x0033
    {load} mov r8, rdi                              # +0x0038
    mov qword ptr [rsi + 8], rax                    # +0x003b
    lea rdx, [rbx + 1]                              # +0x003f
    {load} mov rcx, rax                             # +0x0043
    call qword ptr [rip + R04_REL32_S33_imp_strcpy_s] # +0x0046
    mov rbx, qword ptr [rsp + 0x30]                 # +0x004c
    {load} mov rax, rsi                             # +0x0051
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0054
    add rsp, 0x20                                   # +0x0059
    pop rdi                                         # +0x005d
    ret                                             # +0x005e
.Lbb_5_005f:
    mov ecx, 1                                      # +0x005f
    call R04_REL32_S31_U_YAPEAX_K_Z                 # +0x0064
    mov qword ptr [rsi + 8], rax                    # +0x0069
    mov byte ptr [rax], 0                           # +0x006d
    {load} mov rax, rsi                             # +0x0070
    mov rsi, qword ptr [rsp + 0x38]                 # +0x0073
    add rsp, 0x20                                   # +0x0078
    pop rdi                                         # +0x007c
    ret                                             # +0x007d
end_5:

.section a7,"dr"
# COFF section 7: .text$mn
begin_7:
symbol_15:  # .text$mn
symbol_36:  # ??1CACMException@@QEAA@XZ
    mov rcx, qword ptr [rcx + 8]                    # +0x0000
    jmp R04_REL32_S32_V_YAXPEAX_Z                   # +0x0004
end_7:

.section a9,"dr"
# COFF section 9: .text$mn
begin_9:
symbol_19:  # .text$mn
symbol_37:  # ?GetText@CACMException@@QEBAQEADXZ
    mov rax, qword ptr [rcx + 8]                    # +0x0000
    ret                                             # +0x0004
end_9:

.section a11,"dr"
# COFF section 11: .text$mn
begin_11:
symbol_23:  # .text$mn
symbol_38:  # ACMThrowException
symbol_44:  # $LN4
    sub rsp, 0x38                                   # +0x0000
    {load} mov r8, rdx                              # +0x0004
    {load} mov edx, ecx                             # +0x0007
    lea rcx, [rsp + 0x20]                           # +0x0009
    call R04_REL32_S34_0CACMException_QEAA_KPEAD_Z  # +0x000e
    lea rdx, [rip + R04_REL32_S85_TI1_AVCACMException] # +0x0013
    lea rcx, [rsp + 0x20]                           # +0x001a
    call R04_REL32_S40_CxxThrowException            # +0x001f
    int3                                            # +0x0024
symbol_43:  # $LN3
end_11:

.section a13,"dr"
# COFF section 13: .text$mn
begin_13:
symbol_27:  # .text$mn
symbol_39:  # ACM_THROWEXCEPTION
symbol_46:  # $LN4
    sub rsp, 0x38                                   # +0x0000
    {load} mov r8, rdx                              # +0x0004
    mov edx, dword ptr [rcx]                        # +0x0007
    lea rcx, [rsp + 0x20]                           # +0x0009
    call R04_REL32_S34_0CACMException_QEAA_KPEAD_Z  # +0x000e
    lea rdx, [rip + R04_REL32_S85_TI1_AVCACMException] # +0x0013
    lea rcx, [rsp + 0x20]                           # +0x001a
    call R04_REL32_S40_CxxThrowException            # +0x001f
    int3                                            # +0x0024
symbol_45:  # $LN3
end_13:

.section a15,"dr"
# COFF section 15: .xdata
begin_15:
symbol_47:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=10, unwind slots=4, frame register=0, scaled frame offset=0.
#   prologue +0x0a: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x0a: ALLOC_SMALL 32
#   prologue +0x06: PUSH_NONVOL RDI
symbol_49:  # $unwind$??0CACMException@@QEAA@KPEAD@Z
    .byte 0x01, 0x0a, 0x04, 0x00
    .byte 0x0a, 0x64, 0x07, 0x00
    .byte 0x0a, 0x32, 0x06, 0x70
end_15:

.section a16,"dr"
# COFF section 16: .pdata
begin_16:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_50:  # .pdata
symbol_52:  # $pdata$??0CACMException@@QEAA@KPEAD@Z
    .rva R03_ADDR32NB_S41_LN10  # begin RVA
    .rva R03_ADDR32NB_S41_LN10 + 23  # end RVA (exclusive)
    .rva R03_ADDR32NB_S49_unwind_0CACMException_QEAA_KPEAD_Z  # unwind info RVA
end_16:

.section a17,"dr"
# COFF section 17: .xdata
begin_17:
symbol_53:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=5, unwind slots=2, frame register=0, scaled frame offset=0.
#   prologue +0x05: SAVE_NONVOL RBX, rsp+0x30
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_55:  # $chain$0$??0CACMException@@QEAA@KPEAD@Z
    .byte 0x21, 0x05, 0x02, 0x00
    .byte 0x05, 0x34, 0x06, 0x00
    .rva R03_ADDR32NB_S41_LN10
    .rva R03_ADDR32NB_S41_LN10 + 23
    .rva R03_ADDR32NB_S49_unwind_0CACMException_QEAA_KPEAD_Z
end_17:

.section a18,"dr"
# COFF section 18: .pdata
begin_18:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_56:  # .pdata
symbol_58:  # $pdata$0$??0CACMException@@QEAA@KPEAD@Z
    .rva R03_ADDR32NB_S41_LN10 + 23  # begin RVA
    .rva R03_ADDR32NB_S41_LN10 + 95  # end RVA (exclusive)
    .rva R03_ADDR32NB_S55_chain_0_0CACMException_QEAA_KPEAD_Z  # unwind info RVA
end_18:

.section a19,"dr"
# COFF section 19: .xdata
begin_19:
symbol_59:  # .xdata
# UNWIND_INFO v1, flags=4, prologue length=0, unwind slots=0, frame register=0, scaled frame offset=0.
# CHAININFO is followed by a RUNTIME_FUNCTION triple for the parent range.
symbol_61:  # $chain$1$??0CACMException@@QEAA@KPEAD@Z
    .byte 0x21, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S41_LN10
    .rva R03_ADDR32NB_S41_LN10 + 23
    .rva R03_ADDR32NB_S49_unwind_0CACMException_QEAA_KPEAD_Z
end_19:

.section a20,"dr"
# COFF section 20: .pdata
begin_20:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_62:  # .pdata
symbol_64:  # $pdata$1$??0CACMException@@QEAA@KPEAD@Z
    .rva R03_ADDR32NB_S41_LN10 + 95  # begin RVA
    .rva R03_ADDR32NB_S41_LN10 + 126  # end RVA (exclusive)
    .rva R03_ADDR32NB_S61_chain_1_0CACMException_QEAA_KPEAD_Z  # unwind info RVA
end_20:

.section a21,"dr"
# COFF section 21: .xdata
begin_21:
symbol_65:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=21, unwind slots=8, frame register=0, scaled frame offset=0.
#   prologue +0x15: SAVE_NONVOL RDI, rsp+0x40
#   prologue +0x15: SAVE_NONVOL RSI, rsp+0x38
#   prologue +0x15: SAVE_NONVOL RBX, rsp+0x30
#   prologue +0x15: ALLOC_SMALL 32
#   prologue +0x11: PUSH_NONVOL R14
symbol_67:  # $unwind$??0CACMException@@QEAA@AEBV0@@Z
    .byte 0x01, 0x15, 0x08, 0x00
    .byte 0x15, 0x74, 0x08, 0x00
    .byte 0x15, 0x64, 0x07, 0x00
    .byte 0x15, 0x34, 0x06, 0x00
    .byte 0x15, 0x32, 0x11, 0xe0
end_21:

.section a22,"dr"
# COFF section 22: .pdata
begin_22:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_68:  # .pdata
symbol_70:  # $pdata$??0CACMException@@QEAA@AEBV0@@Z
    .rva R03_ADDR32NB_S42_LN6  # begin RVA
    .rva R03_ADDR32NB_S42_LN6 + 124  # end RVA (exclusive)
    .rva R03_ADDR32NB_S67_unwind_0CACMException_QEAA_AEBV0_Z  # unwind info RVA
end_22:

.section a23,"dr"
# COFF section 23: .xdata
begin_23:
symbol_71:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 56
symbol_73:  # $unwind$ACMThrowException
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x62, 0x00, 0x00
end_23:

.section a24,"dr"
# COFF section 24: .pdata
begin_24:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_74:  # .pdata
symbol_76:  # $pdata$ACMThrowException
    .rva R03_ADDR32NB_S44_LN4  # begin RVA
    .rva R03_ADDR32NB_S44_LN4 + 37  # end RVA (exclusive)
    .rva R03_ADDR32NB_S73_unwind_ACMThrowException  # unwind info RVA
end_24:

.section a25,"dr"
# COFF section 25: .xdata
begin_25:
symbol_77:  # .xdata
# UNWIND_INFO v1, flags=0, prologue length=4, unwind slots=1, frame register=0, scaled frame offset=0.
#   prologue +0x04: ALLOC_SMALL 56
symbol_79:  # $unwind$ACM_THROWEXCEPTION
    .byte 0x01, 0x04, 0x01, 0x00
    .byte 0x04, 0x62, 0x00, 0x00
end_25:

.section a26,"dr"
# COFF section 26: .pdata
begin_26:
    # RUNTIME_FUNCTION: BeginAddress, EndAddress, UnwindInfoAddress
symbol_80:  # .pdata
symbol_82:  # $pdata$ACM_THROWEXCEPTION
    .rva R03_ADDR32NB_S46_LN4  # begin RVA
    .rva R03_ADDR32NB_S46_LN4 + 37  # end RVA (exclusive)
    .rva R03_ADDR32NB_S79_unwind_ACM_THROWEXCEPTION  # unwind info RVA
end_26:

.section a27,"dr"
# COFF section 27: .xdata$x
begin_27:
symbol_83:  # .xdata$x
symbol_85:  # _TI1?AVCACMException@@
    .zero 4
    .rva R03_ADDR32NB_S36_1CACMException_QEAA_XZ
    .zero 4
    .rva R03_ADDR32NB_S88_CTA1_AVCACMException
    .zero 12
end_27:

.section a28,"dr"
# COFF section 28: .xdata$x
begin_28:
symbol_86:  # .xdata$x
symbol_88:  # _CTA1?AVCACMException@@
    .byte 0x01, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S94_CT__R0_AVCACMException_8_0CACMException_QEAA_AEBV0_Z16
    .zero 4
end_28:

.section a29,"dr"
# COFF section 29: .data$r
begin_29:
symbol_89:  # .data$r
symbol_91:  # ??_R0?AVCACMException@@@8
    .quad R01_ADDR64_S95_7type_info_6B
    .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x3f, 0x41, 0x56
    .ascii "CACMException@@\000"
end_29:

.section a30,"dr"
# COFF section 30: .xdata$x
begin_30:
symbol_92:  # .xdata$x
symbol_94:  # _CT??_R0?AVCACMException@@@8??0CACMException@@QEAA@AEBV0@@Z16
    .zero 4
    .rva R03_ADDR32NB_S91_R0_AVCACMException_8
    .byte 0x00, 0x00, 0x00, 0x00
    .byte 0xff, 0xff, 0xff, 0xff
    .byte 0x00, 0x00, 0x00, 0x00
    .byte 0x10, 0x00, 0x00, 0x00
    .rva R03_ADDR32NB_S35_0CACMException_QEAA_AEBV0_Z
    .zero 8
end_30:
