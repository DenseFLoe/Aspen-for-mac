# apdelayload.lib / delaylod.obj (Windows AMD64)
# GNU as, Intel syntax. COFF layout and symbol declarations follow the contributions.
# ref_ denotes a PC-relative link-time reference, rva_ an image-relative address,
# and tail1_ a PC-relative field followed by one immediate byte.
# Direct branches, jump tables, unwind ranges and prologue offsets use symbolic labels.
.intel_syntax noprefix


# Contribution 1: .drectve
.section .ap01,"d"
section_1:
    .ascii "   /DEFAULTLIB:\"delayimp\" /FAILIFMISMATCH:\"_CRT_STDIO_ISO_WIDE_SPECIFIERS=0\" /DEFAULTLIB:\"MSVCRT\" /DEFAULTLIB:\"OLDNAMES\" "
end_ap01:

# Contribution 2: .debug$S
.section .ap02,"d"
section_2:
    .long 4                         # CV_SIGNATURE_C13
    .long 0xf1                      # DEBUG_S_SYMBOLS
    .long .Lcv_end - .Lcv_symbols
.Lcv_symbols:
    .short .Lcv_compile - .Lcv_object
.Lcv_object:
    .short 0x1101                   # S_OBJNAME
    .long 0
    .asciz "g:\\agent\\work\\3\\s\\src\\apbinrel\\source\\apdelayload\\nt\\delaylod.obj"
.Lcv_compile:
    .short .Lcv_end - .Lcv_compiler
.Lcv_compiler:
    .short 0x113c                   # S_COMPILE3
    .long 0x6201
    .short 0xd0                     # x64
    .short 19, 40, 33812, 0         # front end
    .short 19, 40, 33812, 0         # back end
    .asciz "Microsoft (R) Optimizing Compiler"
.Lcv_end:
    .zero 2
end_ap02:

# Contribution 3: .rdata
.section .ap03,"d"
section_3:
release_1:
    .asciz "41.0"
    .zero 3
release_2:
    .asciz "41.0"
    .zero 3
space_1:
    .asciz " "
    .zero 2
space_2:
    .asciz " "
    .zero 2
space_3:
    .asciz " "
    .zero 6
properties_key:
    .asciz "SOFTWARE\\AspenTech\\Aspen Properties\\41.0"
    .zero 7
plus_key:
    .asciz "SOFTWARE\\AspenTech\\Aspen Plus\\41.0"
    .zero 1
patch_level:
    .asciz "0"
    .zero 2
build_number:
    .asciz "609"
    .zero 4
build_date:
    .asciz "April 07 2025"
    .zero 2
release_7:
    .asciz "41.0"
    .zero 3
space_4:
    .asciz " "
    .zero 2
space_5:
    .asciz " "
    .zero 2
space_6:
    .asciz " "
    .zero 6
build_prefix:
    .asciz " Build "
build_number_7:
    .asciz "609"
patch_1:
    .asciz "0"
    .zero 2
patch_2:
    .asciz "0"
    .zero 6
patch_prefix:
    .asciz " Patchlevel "
    .zero 3
patch_3:
    .asciz "0"
    .zero 6
system_key:
    .asciz "SOFTWARE\\AspenTech\\APrSystem\\41.0"
    .zero 6
invalid_code_format:
    .asciz "ZEVER_GET_VSTRINGS: bad string_code: %d"
product_aplus:
    .asciz "\\aplus"
    .zero 1
product_asptop:
    .asciz "asptop"
    .zero 1
system_aplus:
    .asciz "\\aplus"
    .zero 1
system_asptop:
    .asciz "asptop"
    .zero 1
oomf_key:
    .asciz "SOFTWARE\\AspenTech\\OOMF\\41.0"
    .zero 3
oomftop:
    .asciz "oomftop"
token_delimiters:
    .asciz " \t\r\n"
    .zero 3
env_path_size:
    .asciz "path"
    .zero 3
path_separator:
    .asciz ";"
    .zero 2
env_path_read:
    .asciz "path"
    .zero 3
env_path_write:
    .asciz "path"
    .zero 7
aos_key_format:
    .asciz "SOFTWARE\\AspenTech\\AOS\\%s"
    .zero 2
aostop:
    .asciz "aostop"
    .zero 1
bin_suffix:
    .asciz "\\bin"
    .zero 3
xeq_suffix:
    .asciz "\\xeq"
    .zero 7
shared_suffix:
    .asciz "\\AspenTech Shared"
    .zero 2
hook_path_size:
    .asciz "path"
    .zero 3
hook_path_read:
    .asciz "path"
    .zero 3
hook_separator1:
    .asciz ";"
    .zero 2
hook_separator2:
    .asciz ";"
    .zero 6
common_files_value:
    .asciz "CommonFilesDir"
    .zero 1
current_version_key:
    .asciz "SOFTWARE\\Microsoft\\Windows\\CurrentVersion"
    .zero 2
aos_release:
    .asciz "41.0"
end_ap03:

# Contribution 4: .text$mn
.section .ap04,"x"
section_4:

# Store up to two user-version characters, stopping at a space. Keep the range-check edge.
zever_set_uversion:
set_uversion_begin:
    rex push rbx
.Lzever_set_uversion_0002:
    sub rsp, 0x20
.Lzever_set_uversion_0006:
    {load} mov rdx, rcx
    lea rbx, [rip + ref_user_version]
    {load} mov rcx, rbx
    mov r8d, 2
    call qword ptr [rip + ref___imp_strncpy]
    {load} xor ecx, ecx
    {load} mov eax, ecx
.Lzever_set_uversion_0023:
    cmp byte ptr [rax + rbx], 0x20
    je .Lzever_set_uversion_0034
    inc ecx
    inc rax
    cmp rax, 2
    jl .Lzever_set_uversion_0023
.Lzever_set_uversion_0034:
    movsxd rax, ecx
    cmp rax, 3
    jae .Lzever_set_uversion_0047
    mov byte ptr [rax + rbx], 0
    add rsp, 0x20
    pop rbx
    ret
.Lzever_set_uversion_0047:
    call ref___report_rangecheckfailure
    int3
set_uversion_end:
    int3
    .fill 16, 1, 0xcc
    .balign 16, 0xcc  # align next entry

# Dispatch version requests 1..8, with a formatted fallback outside that range.
zever_apversion:
apversion_begin:
    mov qword ptr [rsp + 8], rbx
    push rdi
.Lzever_apversion_0066:
    sub rsp, 0x20
.Lzever_apversion_006a:
    lea eax, [rcx - 1]
    {load} mov rdi, rdx
    cmp eax, 7
    ja .Lzever_apversion_02f5
    lea rdx, [rip + ref___ImageBase]
    cdqe
    mov r8d, dword ptr [rdx + rax*4 + rva_version_dispatch]
    {load} add r8, rdx
    jmp r8
version_case_1:
    cmp byte ptr [rip + tail1_user_version], 0
    lea rbx, [rip + ref_str]
    mov eax, dword ptr [rip + ref_release_1]
    mov dword ptr [rip + ref_str], eax
    movzx eax, byte ptr [rip + ref_release_1 + 4]
    mov byte ptr [rip + ref_str + 4], al
    je .Lzever_apversion_030e
    lea rcx, [rbx - 1]
.Lzever_apversion_00c1:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_00c1
    lea r8, [rip + ref_user_version]
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
    {disp32} nop dword ptr [rax + rax]
.Lzever_apversion_00e0:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .Lzever_apversion_00e0
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_2:
    cmp byte ptr [rip + tail1_user_version], 0
    lea rbx, [rip + ref_str]
    mov eax, dword ptr [rip + ref_release_2]
    mov dword ptr [rip + ref_str], eax
    movzx eax, byte ptr [rip + ref_release_2 + 4]
    mov byte ptr [rip + ref_str + 4], al
    je .Lzever_apversion_0160
    lea rcx, [rbx - 1]
    {disp8} nop dword ptr [rax + rax]
.Lzever_apversion_0130:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_0130
    lea r8, [rip + ref_user_version]
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
    {disp32} nop word ptr [rax + rax]
.Lzever_apversion_0150:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .Lzever_apversion_0150
.Lzever_apversion_0160:
    lea rcx, [rbx - 1]
.Lzever_apversion_0164:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_0164
    movzx eax, word ptr [rip + ref_space_2]
    mov word ptr [rcx], ax
    lea rcx, [rbx - 1]
    {disp8} nop dword ptr [rax]
.Lzever_apversion_0180:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_0180
    movzx eax, word ptr [rip + ref_space_3]
    mov word ptr [rcx], ax
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_3:
    cmp dword ptr [rip + tail1_static_ProductCode], 2
    lea rbx, [rip + ref_properties_key]
    lea rax, [rip + ref_plus_key]
    cmovne rbx, rax
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_4:
    lea rbx, [rip + ref_patch_level]
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_5:
    lea rbx, [rip + ref_build_number]
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_6:
    lea rbx, [rip + ref_build_date]
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_7:
    cmp byte ptr [rip + tail1_user_version], 0
    lea rbx, [rip + ref_str]
    mov eax, dword ptr [rip + ref_release_7]
    mov dword ptr [rip + ref_str], eax
    movzx eax, byte ptr [rip + ref_release_7 + 4]
    mov byte ptr [rip + ref_str + 4], al
    je .Lzever_apversion_0260
    lea rcx, [rbx - 1]
.Lzever_apversion_0235:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_0235
    lea r8, [rip + ref_user_version]
    {load} xor edx, edx
    {disp32} nop dword ptr [rax + rax]
.Lzever_apversion_0250:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .Lzever_apversion_0250
.Lzever_apversion_0260:
    lea rcx, [rbx - 1]
.Lzever_apversion_0264:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_0264
    movzx eax, word ptr [rip + ref_space_5]
    mov word ptr [rcx], ax
    lea rcx, [rbx - 1]
    {disp8} nop dword ptr [rax]
.Lzever_apversion_0280:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_0280
    movzx eax, word ptr [rip + ref_space_6]
    mov word ptr [rcx], ax
    lea rax, [rbx - 1]
    {disp32} nop dword ptr [rax + rax]
.Lzever_apversion_02a0:
    cmp byte ptr [rax + 1], 0
    lea rax, [rax + 1]
    jne .Lzever_apversion_02a0
    movsd xmm0, qword ptr [rip + ref_build_prefix]
    lea rcx, [rbx - 1]
    movsd qword ptr [rax], xmm0
    {disp8} nop word ptr [rax + rax]
.Lzever_apversion_02c0:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .Lzever_apversion_02c0
    mov eax, dword ptr [rip + ref_build_number_7]
    mov dword ptr [rcx], eax
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_case_8:
    lea rbx, [rip + ref_system_key]
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
.Lzever_apversion_02f5:
    {load} mov r8d, ecx
    lea rbx, [rip + ref_str]
    {load} mov rcx, rbx
    lea rdx, [rip + ref_invalid_code_format]
    call ref_sprintf
.Lzever_apversion_030e:
    mov qword ptr [rdi], rbx
    mov rbx, qword ptr [rsp + 0x30]
    add rsp, 0x20
    pop rdi
    ret
version_dispatch:
    .long rva_version_case_1  # version 1
    .long rva_version_case_2  # version 2
    .long rva_version_case_3  # version 3
    .long rva_version_case_4  # version 4
    .long rva_version_case_5  # version 5
    .long rva_version_case_6  # version 6
    .long rva_version_case_7  # version 7
    .long rva_version_case_8  # version 8
.Lzever_apversion_033c:
    .fill 16, 1, 0xcc
    .balign 16, 0xcc  # align next entry

# Normalize the product selector to 1 or 2.
zever_set_productcode:
    {load} xor eax, eax
    cmp ecx, 2
    sete al
    inc eax
    mov dword ptr [rip + ref_static_ProductCode], eax
    ret
    .balign 16, 0xcc  # align next entry

# Return the process-local product selector through the output pointer.
zever_get_productcode:
    mov eax, dword ptr [rip + ref_static_ProductCode]
    mov dword ptr [rcx], eax
    ret
    .balign 16, 0xcc  # align next entry

# Read the selected product registry key, append the aplus subkey and query asptop.
Get_AspTop:
asptop_begin:
    mov qword ptr [rsp + 0x18], rbx
    push rdi
.LGet_AspTop_0386:
    sub rsp, 0xd0
.LGet_AspTop_038d:
    mov rax, qword ptr [rip + ref___security_cookie]
    {load} xor rax, rsp
    mov qword ptr [rsp + 0xc0], rax
.LGet_AspTop_039f:
    {load} xor edi, edi
    mov dword ptr [rsp + 0x30], edx
    cmp dword ptr [rip + tail1_static_ProductCode], 2
    lea rax, [rip + ref_properties_key]
    mov byte ptr [rcx], dil
    lea rdx, [rsp + 0x40]
    {load} mov rbx, rcx
    mov qword ptr [rsp + 0x38], rdi
    lea rcx, [rip + ref_plus_key]
    cmovne rax, rcx
    {load} sub rdx, rax
.LGet_AspTop_03d1:
    movzx ecx, byte ptr [rax]
    mov byte ptr [rdx + rax], cl
    lea rax, [rax + 1]
    test cl, cl
    jne .LGet_AspTop_03d1
    lea rcx, [rsp + 0x40]
    dec rcx
    {disp32} nop word ptr [rax + rax]
.LGet_AspTop_03f0:
    cmp byte ptr [rcx + 1], dil
    lea rcx, [rcx + 1]
    jne .LGet_AspTop_03f0
    mov eax, dword ptr [rip + ref_product_aplus]
    lea rdx, [rsp + 0x40]
    mov dword ptr [rcx], eax
    mov r9d, 0x20019
    movzx eax, word ptr [rip + ref_product_aplus + 4]
    {load} xor r8d, r8d
    mov word ptr [rcx + 4], ax
    movzx eax, byte ptr [rip + ref_product_aplus + 6]
    mov byte ptr [rcx + 6], al
    lea rax, [rsp + 0x38]
    mov rcx, 0xffffffff80000002
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LGet_AspTop_047e
    mov rcx, qword ptr [rsp + 0x38]
    lea rax, [rsp + 0x30]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_product_asptop]
    {load} xor r9d, r9d
    mov qword ptr [rsp + 0x20], rbx
    {load} xor r8d, r8d
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x38]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    setne dil
    {load} mov eax, edi
    jmp .LGet_AspTop_0483
.LGet_AspTop_047e:
    mov eax, 1
.LGet_AspTop_0483:
    mov rcx, qword ptr [rsp + 0xc0]
    {load} xor rcx, rsp
    call ref___security_check_cookie
    mov rbx, qword ptr [rsp + 0xf0]
    add rsp, 0xd0
    pop rdi
    ret
.LGet_AspTop_04a4:
    .balign 16, 0xcc  # align next entry

# Read the APrSystem aplus subkey and query asptop.
Get_APrSystem_Top:
aprsystem_begin:
    mov qword ptr [rsp + 0x18], rbx
    push rdi
.LGet_APrSystem_Top_04b6:
    sub rsp, 0xd0
.LGet_APrSystem_Top_04bd:
    mov rax, qword ptr [rip + ref___security_cookie]
    {load} xor rax, rsp
    mov qword ptr [rsp + 0xc0], rax
.LGet_APrSystem_Top_04cf:
    {load} xor edi, edi
    mov dword ptr [rsp + 0x30], edx
    mov byte ptr [rcx], dil
    {load} mov rbx, rcx
    lea rcx, [rip + ref_system_key]
    mov qword ptr [rsp + 0x38], rdi
    {load} mov edx, edi
    {disp32} nop dword ptr [rax]
.LGet_APrSystem_Top_04f0:
    movzx eax, byte ptr [rdx + rcx]
    mov byte ptr [rsp + rdx + 0x40], al
    lea rdx, [rdx + 1]
    test al, al
    jne .LGet_APrSystem_Top_04f0
    lea rax, [rsp + 0x40]
    dec rax
    {disp32} nop dword ptr [rax + rax]
.LGet_APrSystem_Top_0510:
    cmp byte ptr [rax + 1], dil
    lea rax, [rax + 1]
    jne .LGet_APrSystem_Top_0510
    mov ecx, dword ptr [rip + ref_system_aplus]
    lea rdx, [rsp + 0x40]
    mov dword ptr [rax], ecx
    mov r9d, 0x20019
    movzx ecx, word ptr [rip + ref_system_aplus + 4]
    {load} xor r8d, r8d
    mov word ptr [rax + 4], cx
    movzx ecx, byte ptr [rip + ref_system_aplus + 6]
    mov byte ptr [rax + 6], cl
    lea rax, [rsp + 0x38]
    mov rcx, 0xffffffff80000002
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LGet_APrSystem_Top_059e
    mov rcx, qword ptr [rsp + 0x38]
    lea rax, [rsp + 0x30]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_system_asptop]
    {load} xor r9d, r9d
    mov qword ptr [rsp + 0x20], rbx
    {load} xor r8d, r8d
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x38]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    setne dil
    {load} mov eax, edi
    jmp .LGet_APrSystem_Top_05a3
.LGet_APrSystem_Top_059e:
    mov eax, 1
.LGet_APrSystem_Top_05a3:
    mov rcx, qword ptr [rsp + 0xc0]
    {load} xor rcx, rsp
    call ref___security_check_cookie
    mov rbx, qword ptr [rsp + 0xf0]
    add rsp, 0xd0
    pop rdi
    ret
.LGet_APrSystem_Top_05c4:
    .balign 16, 0xcc  # align next entry

# Read oomftop and try the Windows short-path conversion.
GetOOMFTop:
oomftop_begin:
    rex push rdi
.LGetOOMFTop_05d2:
    sub rsp, 0x1d0
.LGetOOMFTop_05d9:
    mov rax, qword ptr [rip + ref___security_cookie]
    {load} xor rax, rsp
    mov qword ptr [rsp + 0x1c0], rax
.LGetOOMFTop_05eb:
    {load} xor r8d, r8d
    mov dword ptr [rsp + 0x30], edx
    mov byte ptr [rcx], r8b
    {load} mov rdi, rcx
    lea rcx, [rip + ref_oomf_key]
    mov qword ptr [rsp + 0x38], r8
    {disp8} nop dword ptr [rax]
    {disp32} nop dword ptr [rax + rax]
.LGetOOMFTop_0610:
    movzx eax, byte ptr [r8 + rcx]
    mov byte ptr [rsp + r8 + 0x40], al
    lea r8, [r8 + 1]
    test al, al
    jne .LGetOOMFTop_0610
    lea rax, [rsp + 0x38]
    mov r9d, 1
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    lea rdx, [rsp + 0x40]
    mov rcx, 0xffffffff80000002
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LGetOOMFTop_06e2
    mov rcx, qword ptr [rsp + 0x38]
    lea rax, [rsp + 0x30]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_oomftop]
    {load} xor r9d, r9d
    mov qword ptr [rsp + 0x20], rdi
    {load} xor r8d, r8d
.LGetOOMFTop_0670:
    mov qword ptr [rsp + 0x1f0], rbx
.LGetOOMFTop_0678:
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x38]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    mov rbx, qword ptr [rsp + 0x1f0]
    jne .LGetOOMFTop_06e2
.LGetOOMFTop_0697:
    mov r8d, 0x100
    lea rdx, [rsp + 0xc0]
    {load} mov rcx, rdi
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    test eax, eax
    je .LGetOOMFTop_06de
    lea rcx, [rsp + 0xc0]
    {load} sub rdi, rcx
    lea rax, [rsp + 0xc0]
    .byte 0x66, 0x66  # redundant operand-size prefix
     {disp32} nop word ptr [rax + rax]
.LGetOOMFTop_06d0:
    movzx ecx, byte ptr [rax]
    mov byte ptr [rdi + rax], cl
    lea rax, [rax + 1]
    test cl, cl
    jne .LGetOOMFTop_06d0
.LGetOOMFTop_06de:
    {load} xor eax, eax
    jmp .LGetOOMFTop_06e7
.LGetOOMFTop_06e2:
    mov eax, 1
.LGetOOMFTop_06e7:
    mov rcx, qword ptr [rsp + 0x1c0]
    {load} xor rcx, rsp
    call ref___security_check_cookie
    add rsp, 0x1d0
    pop rdi
    ret
.LGetOOMFTop_0700:
    .fill 16, 1, 0xcc
    .balign 16, 0xcc  # align next entry

# Count or populate the argument vector and strings, preserving quote/backslash rules.
parse_line:
    mov qword ptr [rsp + 8], rbx
    mov qword ptr [rsp + 0x10], rbp
    mov qword ptr [rsp + 0x18], rsi
    push rdi
.Lparse_line_0720:
    push r12
.Lparse_line_0722:
    push r13
.Lparse_line_0724:
    push r14
.Lparse_line_0726:
    push r15
.Lparse_line_0728:
    sub rsp, 0x20
.Lparse_line_072c:
    {load} xor ebx, ebx
    lea r15, [rip + ref_token_delimiters]
    test rdx, rdx
    {load} mov r13, r9
    {load} mov r12, r8
    {load} mov rdi, rcx
    cmovne r15, rdx
    test r8, r8
    je .Lparse_line_0751
    movsxd rax, dword ptr [r9]
    lea rbx, [r8 + rax*8]
.Lparse_line_0751:
    mov rsi, qword ptr [rsp + 0x70]
    {load} xor r14d, r14d
    mov dword ptr [rsi], 0
    mov dword ptr [r9], 0
.Lparse_line_0766:
    movzx eax, byte ptr [rdi]
    test al, al
    je .Lparse_line_078b
    nop dword ptr [rax]
.Lparse_line_0770:
    movsx edx, al
    {load} mov rcx, r15
    call ref_strchr
    test rax, rax
    je .Lparse_line_07c6
    movzx eax, byte ptr [rdi + 1]
    inc rdi
    test al, al
    jne .Lparse_line_0770
.Lparse_line_078b:
    test r12, r12
    je .Lparse_line_0798
    mov qword ptr [r12], 0
.Lparse_line_0798:
    {disp8} inc dword ptr [r13]
    {disp8} mov eax, dword ptr [r13]
    mov rbx, qword ptr [rsp + 0x50]
    mov rbp, qword ptr [rsp + 0x58]
    {disp8} lea eax, [rax*8]
    add dword ptr [rsi], eax
    mov rsi, qword ptr [rsp + 0x60]
    add rsp, 0x20
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    ret
.Lparse_line_07c6:
    cmp byte ptr [rdi], 0
    je .Lparse_line_078b
    test r12, r12
    je .Lparse_line_07d8
    mov qword ptr [r12], rbx
    add r12, 8
.Lparse_line_07d8:
    {disp8} inc dword ptr [r13]
    {disp8} nop dword ptr [rax]
.Lparse_line_07e0:
    movzx ecx, byte ptr [rdi]
    {load} xor eax, eax
    mov ebp, 1
    cmp cl, 0x5c
    jne .Lparse_line_07fe
    nop
.Lparse_line_07f0:
    movzx ecx, byte ptr [rdi + 1]
    inc rdi
    inc eax
    cmp cl, 0x5c
    je .Lparse_line_07f0
.Lparse_line_07fe:
    cmp cl, 0x22
    jne .Lparse_line_0833
    test bpl, al
    jne .Lparse_line_0831
    test r14d, r14d
    je .Lparse_line_0824
    cmp byte ptr [rdi + 1], 0x22
    lea rcx, [rdi + 1]
    cmove rdi, rcx
    {load} xor ebp, ebp
    cmp byte ptr [rcx], 0x22
    sete bpl
    jmp .Lparse_line_0826
.Lparse_line_0824:
    {load} xor ebp, ebp
.Lparse_line_0826:
    {load} xor ecx, ecx
    test r14d, r14d
    sete cl
    {load} mov r14d, ecx
.Lparse_line_0831:
    shr eax, 1
.Lparse_line_0833:
    test eax, eax
    je .Lparse_line_084a
.Lparse_line_0837:
    dec eax
    test rbx, rbx
    je .Lparse_line_0844
    mov byte ptr [rbx], 0x5c
    inc rbx
.Lparse_line_0844:
    inc dword ptr [rsi]
    test eax, eax
    jne .Lparse_line_0837
.Lparse_line_084a:
    movsx eax, byte ptr [rdi]
    test al, al
    je .Lparse_line_0880
    test r14d, r14d
    jne .Lparse_line_0865
    {load} mov edx, eax
    {load} mov rcx, r15
    call ref_strchr
    test rax, rax
    jne .Lparse_line_0880
.Lparse_line_0865:
    test ebp, ebp
    je .Lparse_line_0878
    test rbx, rbx
    je .Lparse_line_0876
    movzx eax, byte ptr [rdi]
    mov byte ptr [rbx], al
    inc rbx
.Lparse_line_0876:
    inc dword ptr [rsi]
.Lparse_line_0878:
    inc rdi
    jmp .Lparse_line_07e0
.Lparse_line_0880:
    test rbx, rbx
    je .Lparse_line_088b
    mov byte ptr [rbx], 0
    inc rbx
.Lparse_line_088b:
    inc dword ptr [rsi]
    jmp .Lparse_line_0766
.Lparse_line_0892:
    .balign 16, 0xcc  # align next entry

# Open HKLM with query permission, read the value and close the handle.
GetRegistryValue:
    mov qword ptr [rsp + 8], rbx
    mov dword ptr [rsp + 0x20], r9d
    push rdi
.LGetRegistryValue_08ab:
    sub rsp, 0x30
.LGetRegistryValue_08af:
    {load} mov rdi, rdx
    mov byte ptr [r8], 0
    {load} mov rdx, rcx
    lea rax, [rsp + 0x50]
    {load} mov rbx, r8
    mov qword ptr [rsp + 0x20], rax
    mov rcx, 0xffffffff80000002
    mov r9d, 1
    {load} xor r8d, r8d
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    je .LGetRegistryValue_08ed
    {load} xor al, al
    mov rbx, qword ptr [rsp + 0x40]
    add rsp, 0x30
    pop rdi
    ret
.LGetRegistryValue_08ed:
    mov rcx, qword ptr [rsp + 0x50]
    lea rax, [rsp + 0x58]
    mov qword ptr [rsp + 0x28], rax
    {load} xor r9d, r9d
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rbx
    {load} mov rdx, rdi
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x50]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    mov rbx, qword ptr [rsp + 0x40]
    sete al
    add rsp, 0x30
    pop rdi
    ret
.LGetRegistryValue_092d:
    .fill 16, 1, 0xcc
    .balign 16, 0xcc  # align next entry

# Prepend one path and a semicolon to the current process environment value.
AddToPath:
    mov qword ptr [rsp + 8], rbx
    mov qword ptr [rsp + 0x10], rbp
    mov qword ptr [rsp + 0x18], rsi
    push rdi
.LAddToPath_0950:
    sub rsp, 0x20
.LAddToPath_0954:
    {load} mov rbx, rcx
    {load} xor r8d, r8d
    lea rcx, [rip + ref_env_path_size]
    {load} xor edx, edx
    call qword ptr [rip + ref___imp_GetEnvironmentVariableA]
    mov rdi, 0xffffffffffffffff
    movsxd rbp, eax
    {load} mov rcx, rdi
.LAddToPath_0976:
    inc rcx
    cmp byte ptr [rbx + rcx], 0
    jne .LAddToPath_0976
    lea rax, [rbp + 2]
    {load} add rcx, rax
    call qword ptr [rip + ref___imp_malloc]
    {load} mov rsi, rax
    test rax, rax
    je .LAddToPath_0a08
    {load} sub rax, rbx
    {disp32} nop word ptr [rax + rax]
.LAddToPath_09a0:
    movzx ecx, byte ptr [rbx]
    mov byte ptr [rax + rbx], cl
    lea rbx, [rbx + 1]
    test cl, cl
    jne .LAddToPath_09a0
    lea rcx, [rsi - 1]
.LAddToPath_09b2:
    cmp byte ptr [rcx + 1], 0
    lea rcx, [rcx + 1]
    jne .LAddToPath_09b2
    movzx eax, word ptr [rip + ref_path_separator]
    mov word ptr [rcx], ax
    .byte 0x66  # redundant operand-size prefix
     {disp32} nop word ptr [rax + rax]
.LAddToPath_09d0:
    cmp byte ptr [rsi + rdi + 1], 0
    lea rdi, [rdi + 1]
    jne .LAddToPath_09d0
    lea rdx, [rsi + rdi]
    {load} mov r8d, ebp
    lea rcx, [rip + ref_env_path_read]
    call qword ptr [rip + ref___imp_GetEnvironmentVariableA]
    {load} mov rdx, rsi
    lea rcx, [rip + ref_env_path_write]
    call qword ptr [rip + ref___imp_SetEnvironmentVariableA]
    {load} mov rcx, rsi
    call qword ptr [rip + ref___imp_free]
.LAddToPath_0a08:
    mov rbx, qword ptr [rsp + 0x30]
    mov rbp, qword ptr [rsp + 0x38]
    mov rsi, qword ptr [rsp + 0x40]
    add rsp, 0x20
    pop rdi
    ret
.LAddToPath_0a1d:
    .fill 16, 1, 0xcc
    .balign 16, 0xcc  # align next entry

# Search non-null path entries using a case-insensitive comparison.
searchargs:
searchargs_begin:
    mov qword ptr [rsp + 8], rbx
    mov qword ptr [rsp + 0x10], rbp
    mov qword ptr [rsp + 0x18], rsi
    push rdi
.Lsearchargs_0a40:
    sub rsp, 0x20
.Lsearchargs_0a44:
    {load} xor ebx, ebx
    {load} mov esi, r8d
    {load} mov rdi, rdx
    {load} mov rbp, rcx
    test r8d, r8d
    jle .Lsearchargs_0a73
.Lsearchargs_0a54:
    mov rdx, qword ptr [rdi]
    test rdx, rdx
    je .Lsearchargs_0a69
    {load} mov rcx, rbp
    call qword ptr [rip + ref___imp__stricmp]
    test eax, eax
    je .Lsearchargs_0a8a
.Lsearchargs_0a69:
    inc ebx
    add rdi, 8
    {load} cmp ebx, esi
    jl .Lsearchargs_0a54
.Lsearchargs_0a73:
    {load} xor al, al
.Lsearchargs_0a75:
    mov rbx, qword ptr [rsp + 0x30]
    mov rbp, qword ptr [rsp + 0x38]
    mov rsi, qword ptr [rsp + 0x40]
    add rsp, 0x20
    pop rdi
    ret
.Lsearchargs_0a8a:
    mov al, 1
    jmp .Lsearchargs_0a75
.Lsearchargs_0a8e:
    .fill 16, 1, 0xcc
    .balign 16, 0xcc  # align next entry

# Resolve a full path, request its short name and strip trailing backslashes.
GetShortName:
shortname_begin:
    mov qword ptr [rsp + 0x20], rbx
    push rdi
.LGetShortName_0aa6:
    sub rsp, 0x150
.LGetShortName_0aad:
    mov rax, qword ptr [rip + ref___security_cookie]
    {load} xor rax, rsp
    mov qword ptr [rsp + 0x140], rax
.LGetShortName_0abf:
    {load} mov ebx, r8d
    mov qword ptr [rsp + 0x20], 0
    {load} mov rdi, rdx
    lea r8, [rsp + 0x30]
    mov edx, 0x104
    lea r9, [rsp + 0x20]
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    {load} mov r8d, ebx
    lea rcx, [rsp + 0x30]
    {load} mov rdx, rdi
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    movsxd r8, eax
    test eax, eax
    jle .LGetShortName_0b1e
    lea rcx, [r8 + rdi]
    nop
.LGetShortName_0b00:
    cmp byte ptr [rcx - 1], 0x5c
    lea rdx, [rcx - 1]
    {load} mov rcx, rdx
    jne .LGetShortName_0b1e
    {load} mov rax, rdx
    mov byte ptr [rdx], 0
    {load} sub rax, rdi
    dec r8d
    test rax, rax
    jg .LGetShortName_0b00
.LGetShortName_0b1e:
    {load} mov eax, r8d
    mov rcx, qword ptr [rsp + 0x140]
    {load} xor rcx, rsp
    call ref___security_check_cookie
    mov rbx, qword ptr [rsp + 0x178]
    add rsp, 0x150
    pop rdi
    ret
.LGetShortName_0b42:
    .balign 16, 0xcc  # align next entry

# Size or fill a pointer vector and its converted short-path strings.
ConvertPathsToShortName:
convertpaths_begin:
    rex push rbp
.LConvertPathsToShortName_0b52:
    push rsi
.LConvertPathsToShortName_0b53:
    push rdi
.LConvertPathsToShortName_0b54:
    push r12
.LConvertPathsToShortName_0b56:
    push r14
.LConvertPathsToShortName_0b58:
    push r15
.LConvertPathsToShortName_0b5a:
    sub rsp, 0x268
.LConvertPathsToShortName_0b61:
    mov rax, qword ptr [rip + ref___security_cookie]
    {load} xor rax, rsp
    mov qword ptr [rsp + 0x250], rax
.LConvertPathsToShortName_0b73:
    {load} xor r12d, r12d
    movsxd r14, r8d
    test rcx, rcx
    {disp8} lea ebp, [r8*8 + 8]
    {load} mov eax, r12d
    {load} mov r15, rdx
    cmovne eax, ebp
    {load} mov rsi, rcx
    movsxd rdi, eax
    {load} add rdi, rcx
    test r8d, r8d
    jle .LConvertPathsToShortName_0c85
.LConvertPathsToShortName_0b9f:
    mov qword ptr [rsp + 0x260], rbx
.LConvertPathsToShortName_0ba7:
    {load} sub r15, rcx
    {load} mov rbx, rcx
    nop dword ptr [rax]
.LConvertPathsToShortName_0bb0:
    mov rcx, qword ptr [r15 + rbx]
    test rcx, rcx
    je .LConvertPathsToShortName_0c67
    cmp byte ptr [rcx], r12b
    je .LConvertPathsToShortName_0c67
    lea r9, [rsp + 0x20]
    mov qword ptr [rsp + 0x20], r12
    lea r8, [rsp + 0x140]
    mov edx, 0x104
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    mov r8d, 0x104
    lea rdx, [rsp + 0x30]
    lea rcx, [rsp + 0x140]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    cdqe
    test rax, rax
    jle .LConvertPathsToShortName_0c17
.LConvertPathsToShortName_0c03:
    cmp byte ptr [rsp + rax + 0x2f], 0x5c
    jne .LConvertPathsToShortName_0c17
    dec rax
    mov byte ptr [rsp + rax + 0x30], r12b
    test rax, rax
    jg .LConvertPathsToShortName_0c03
.LConvertPathsToShortName_0c17:
    lea rax, [rsp + 0x30]
    mov rdx, 0xffffffffffffffff
.LConvertPathsToShortName_0c23:
    inc rdx
    cmp byte ptr [rax + rdx], r12b
    jne .LConvertPathsToShortName_0c23
    inc edx
    {load} add ebp, edx
    test rsi, rsi
    je .LConvertPathsToShortName_0c6f
    lea rax, [rsp + 0x30]
    mov qword ptr [rbx], rdi
    {load} mov r8, rdi
    lea rcx, [rsp + 0x30]
    {load} sub r8, rax
    {disp32} nop dword ptr [rax + rax]
.LConvertPathsToShortName_0c50:
    movzx eax, byte ptr [rcx]
    mov byte ptr [r8 + rcx], al
    lea rcx, [rcx + 1]
    test al, al
    jne .LConvertPathsToShortName_0c50
    movsxd rax, edx
    {load} add rdi, rax
    jmp .LConvertPathsToShortName_0c6f
.LConvertPathsToShortName_0c67:
    test rsi, rsi
    je .LConvertPathsToShortName_0c6f
    mov qword ptr [rbx], r12
.LConvertPathsToShortName_0c6f:
    add rbx, 8
    sub r14, 1
    jne .LConvertPathsToShortName_0bb0
    mov rbx, qword ptr [rsp + 0x260]
.LConvertPathsToShortName_0c85:
    {load} mov eax, ebp
    mov rcx, qword ptr [rsp + 0x250]
    {load} xor rcx, rsp
    call ref___security_check_cookie
    add rsp, 0x268
    pop r15
    pop r14
    pop r12
    pop rdi
    pop rsi
    pop rbp
    ret
.LConvertPathsToShortName_0ca8:
    .balign 16, 0xcc  # align next entry

# Handle the first start-processing notification. Check Common Files, AOS, OOMF, APrSystem and the selected product.
NotifyHook:
hook_begin:
    rex push rbp
.LNotifyHook_0cb2:
    lea rbp, [rsp - 0x550]
    sub rsp, 0x650
.LNotifyHook_0cc1:
    mov rax, qword ptr [rip + ref___security_cookie]
    {load} xor rax, rsp
    mov qword ptr [rbp + 0x520], rax
.LNotifyHook_0cd2:
    cmp ecx, 5
    ja notification_return
    {load} mov eax, ecx
    lea rcx, [rip + ref___ImageBase]
    mov eax, dword ptr [rcx + rax*4 + rva_notification_dispatch]
    {load} add rax, rcx
    jmp rax
notification_start:
    cmp byte ptr [rip + tail1_PathProcessed], 0
    jne notification_return
.LNotifyHook_0cfd:
    mov qword ptr [rsp + 0x660], rbx
.LNotifyHook_0d05:
    lea rcx, [rip + ref_hook_path_size]
    mov qword ptr [rsp + 0x668], rsi
.LNotifyHook_0d14:
    {load} xor r8d, r8d
.LNotifyHook_0d17:
    mov qword ptr [rsp + 0x670], rdi
.LNotifyHook_0d1f:
    {load} xor edx, edx
    mov qword ptr [rsp + 0x648], r12
.LNotifyHook_0d29:
    mov qword ptr [rsp + 0x640], r13
.LNotifyHook_0d31:
    mov qword ptr [rsp + 0x638], r14
.LNotifyHook_0d39:
    mov qword ptr [rsp + 0x630], r15
.LNotifyHook_0d41:
    mov byte ptr [rip + tail1_PathProcessed], 1
    call qword ptr [rip + ref___imp_GetEnvironmentVariableA]
    {load} mov ebx, eax
    lea rcx, [rbx + 1]
    call qword ptr [rip + ref___imp_malloc]
    {load} mov r8d, ebx
    lea rcx, [rip + ref_hook_path_read]
    {load} mov rdx, rax
    mov qword ptr [rsp + 0x30], rax
    {load} mov r12, rax
    call qword ptr [rip + ref___imp_GetEnvironmentVariableA]
    {load} xor esi, esi
    {load} mov rbx, r12
    {load} mov r13d, esi
    {load} mov edi, esi
    {load} mov r15d, esi
    {load} mov r14d, esi
    {load} mov r12d, esi
.LNotifyHook_0d88:
    movzx eax, byte ptr [rbx]
    test al, al
    je .LNotifyHook_0db3
    nop
.LNotifyHook_0d90:
    movsx edx, al
    lea rcx, [rip + ref_hook_separator1]
    call ref_strchr
    test rax, rax
    je .LNotifyHook_174c
    movzx eax, byte ptr [rbx + 1]
    inc rbx
    test al, al
    jne .LNotifyHook_0d90
.LNotifyHook_0db3:
    test r13, r13
    je .LNotifyHook_0dbc
    {disp8} mov qword ptr [r13], rsi
.LNotifyHook_0dbc:
    inc r14d
    lea eax, [r15 + r14*8]
    movsxd rcx, eax
    call qword ptr [rip + ref___imp_malloc]
    mov qword ptr [rsp + 0x40], rax
    {load} mov r12, rax
    {load} mov rdi, rsi
    test rax, rax
    je .LNotifyHook_0de3
    movsxd rcx, r14d
    lea rdi, [rax + rcx*8]
.LNotifyHook_0de3:
    mov rbx, qword ptr [rsp + 0x30]
    {load} mov r14d, esi
    {load} mov r15d, esi
    xchg ax, ax
.LNotifyHook_0df0:
    movzx eax, byte ptr [rbx]
    movsxd r13, r14d
    test al, al
    je .LNotifyHook_0e23
    {disp8} nop word ptr [rax + rax]
.LNotifyHook_0e00:
    movsx edx, al
    lea rcx, [rip + ref_hook_separator2]
    call ref_strchr
    test rax, rax
    je .LNotifyHook_1829
    movzx eax, byte ptr [rbx + 1]
    inc rbx
    test al, al
    jne .LNotifyHook_0e00
.LNotifyHook_0e23:
    test r12, r12
    je .LNotifyHook_0e2c
    mov qword ptr [r12], rsi
.LNotifyHook_0e2c:
    mov rbx, qword ptr [rsp + 0x40]
    inc r14d
    {load} mov r8d, r14d
    mov dword ptr [rsp + 0x38], r14d
    {load} mov rdx, rbx
    {load} xor ecx, ecx
    call ref_ConvertPathsToShortName
    movsxd rdx, eax
    mov ecx, 1
    call qword ptr [rip + ref___imp_calloc]
    mov r12d, dword ptr [rsp + 0x38]
    {load} mov rdx, rbx
    {load} mov rcx, rax
    {load} mov r8d, r12d
    {load} mov r14, rax
    call ref_ConvertPathsToShortName
    {load} mov rcx, rbx
    call qword ptr [rip + ref___imp_free]
    mov rcx, qword ptr [rsp + 0x30]
    call qword ptr [rip + ref___imp_free]
    lea rax, [rsp + 0x30]
    mov dword ptr [rsp + 0x40], 0x104
    mov r9d, 1
    mov qword ptr [rsp + 0x20], rax
    {load} xor r8d, r8d
    mov byte ptr [rsp + 0x50], sil
    lea rdx, [rip + ref_current_version_key]
    mov rcx, 0xffffffff80000002
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    mov r15, 0xffffffffffffffff
    test eax, eax
    jne .LNotifyHook_0fea
    mov rcx, qword ptr [rsp + 0x30]
    lea rax, [rsp + 0x40]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_common_files_value]
    lea rax, [rsp + 0x50]
    {load} xor r9d, r9d
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x30]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    jne .LNotifyHook_0fea
    lea rcx, [rsp + 0x50]
    {load} mov rax, r15
    {disp8} nop word ptr [rax + rax]
.LNotifyHook_0f10:
    inc rax
    cmp byte ptr [rcx + rax], sil
    jne .LNotifyHook_0f10
    test rax, rax
    je .LNotifyHook_0f2c
    cmp byte ptr [rsp + rax + 0x4f], 0x5c
    lea r8, [rip + ref_shared_suffix + 1]
    je .LNotifyHook_0f33
.LNotifyHook_0f2c:
    lea r8, [rip + ref_shared_suffix]
.LNotifyHook_0f33:
    lea rcx, [rsp + 0x50]
    dec rcx
    {disp8} nop dword ptr [rax + rax]
.LNotifyHook_0f40:
    cmp byte ptr [rcx + 1], sil
    lea rcx, [rcx + 1]
    jne .LNotifyHook_0f40
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
.LNotifyHook_0f50:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .LNotifyHook_0f50
    lea r9, [rsp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea r8, [rbp + 0x1f0]
    mov edx, 0x104
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    mov r8d, 0x104
    lea rdx, [rbp + 0x60]
    lea rcx, [rbp + 0x1f0]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    movsxd rcx, eax
    test eax, eax
    jle .LNotifyHook_0fb4
    nop
.LNotifyHook_0fa0:
    cmp byte ptr [rbp + rcx + 0x5f], 0x5c
    jne .LNotifyHook_0fb4
    dec rcx
    mov byte ptr [rbp + rcx + 0x60], sil
    test rcx, rcx
    jg .LNotifyHook_0fa0
.LNotifyHook_0fb4:
    test r12d, r12d
    jle .LNotifyHook_0fe0
    lea rdi, [r13 + 1]
    {load} mov rbx, rsi
.LNotifyHook_0fc0:
    mov rdx, qword ptr [r14 + rbx*8]
    test rdx, rdx
    je .LNotifyHook_0fd8
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp__stricmp]
    test eax, eax
    je .LNotifyHook_0fea
.LNotifyHook_0fd8:
    inc rbx
    {load} cmp rbx, rdi
    jl .LNotifyHook_0fc0
.LNotifyHook_0fe0:
    lea rcx, [rsp + 0x50]
    call ref_AddToPath
.LNotifyHook_0fea:
    mov eax, dword ptr [rip + ref_aos_release]
    lea r8, [rbp + 0x300]
    mov dword ptr [rbp + 0x300], eax
    lea rdx, [rip + ref_aos_key_format]
    movzx eax, byte ptr [rip + ref_aos_release + 4]
    lea rcx, [rbp + 0x410]
    mov byte ptr [rbp + 0x304], al
    call ref_sprintf
    lea rax, [rsp + 0x30]
    mov dword ptr [rsp + 0x40], 0x104
    mov r9d, 1
    mov qword ptr [rsp + 0x20], rax
    {load} xor r8d, r8d
    mov byte ptr [rsp + 0x50], sil
    lea rdx, [rbp + 0x410]
    mov rcx, 0xffffffff80000002
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LNotifyHook_1178
    mov rcx, qword ptr [rsp + 0x30]
    lea rax, [rsp + 0x40]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_aostop]
    lea rax, [rsp + 0x50]
    {load} xor r9d, r9d
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x30]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    jne .LNotifyHook_1178
    lea rcx, [rsp + 0x50]
    {load} mov rax, r15
.LNotifyHook_10a2:
    inc rax
    cmp byte ptr [rcx + rax], sil
    jne .LNotifyHook_10a2
    test rax, rax
    je .LNotifyHook_10be
    cmp byte ptr [rsp + rax + 0x4f], 0x5c
    lea r8, [rip + ref_bin_suffix + 1]
    je .LNotifyHook_10c5
.LNotifyHook_10be:
    lea r8, [rip + ref_bin_suffix]
.LNotifyHook_10c5:
    lea rcx, [rsp + 0x50]
    dec rcx
    nop dword ptr [rax]
.LNotifyHook_10d0:
    cmp byte ptr [rcx + 1], sil
    lea rcx, [rcx + 1]
    jne .LNotifyHook_10d0
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
.LNotifyHook_10e0:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .LNotifyHook_10e0
    lea r9, [rsp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea r8, [rbp + 0x1f0]
    mov edx, 0x104
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    mov r8d, 0x104
    lea rdx, [rbp + 0x60]
    lea rcx, [rbp + 0x1f0]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    movsxd rcx, eax
    test eax, eax
    jle .LNotifyHook_1144
    nop
.LNotifyHook_1130:
    cmp byte ptr [rbp + rcx + 0x5f], 0x5c
    jne .LNotifyHook_1144
    dec rcx
    mov byte ptr [rbp + rcx + 0x60], sil
    test rcx, rcx
    jg .LNotifyHook_1130
.LNotifyHook_1144:
    test r12d, r12d
    jle .LNotifyHook_116f
    lea rdi, [r13 + 1]
    {load} mov rbx, rsi
.LNotifyHook_1150:
    mov rdx, qword ptr [r14 + rbx*8]
    test rdx, rdx
    je .LNotifyHook_1167
    lea rcx, [rbp + 0x60]
    call qword ptr [rip + ref___imp__stricmp]
    test eax, eax
    je .LNotifyHook_1178
.LNotifyHook_1167:
    inc rbx
    {load} cmp rbx, rdi
    jl .LNotifyHook_1150
.LNotifyHook_116f:
    lea rcx, [rbp + 0x60]
    call ref_AddToPath
.LNotifyHook_1178:
    mov qword ptr [rsp + 0x30], rsi
    lea rdx, [rip + ref___ImageBase]
    mov dword ptr [rsp + 0x40], 0x100
    {load} mov rcx, rsi
    mov byte ptr [rsp + 0x50], sil
    {disp8} nop dword ptr [rax]
    {disp32} nop dword ptr [rax + rax]
.LNotifyHook_11a0:
    movzx eax, byte ptr [rcx + rdx + rva_oomf_key]
    mov byte ptr [rbp + rcx + 0x170], al
    lea rcx, [rcx + 1]
    test al, al
    jne .LNotifyHook_11a0
    lea rax, [rsp + 0x30]
    mov r9d, 1
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    lea rdx, [rbp + 0x170]
    mov rcx, 0xffffffff80000002
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LNotifyHook_1254
    mov rcx, qword ptr [rsp + 0x30]
    lea rax, [rsp + 0x40]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_oomftop]
    lea rax, [rsp + 0x50]
    {load} xor r9d, r9d
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x30]
    {load} mov ebx, eax
    call qword ptr [rip + ref___imp_RegCloseKey]
    test ebx, ebx
    jne .LNotifyHook_1254
    mov r8d, 0x100
    lea rdx, [rbp + 0x1f0]
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    test eax, eax
    je .LNotifyHook_1254
    {load} mov rcx, rsi
    xchg ax, ax
.LNotifyHook_1240:
    movzx eax, byte ptr [rbp + rcx + 0x1f0]
    mov byte ptr [rsp + rcx + 0x50], al
    lea rcx, [rcx + 1]
    test al, al
    jne .LNotifyHook_1240
.LNotifyHook_1254:
    lea rcx, [rsp + 0x50]
    {load} mov rax, r15
    {disp8} nop dword ptr [rax]
.LNotifyHook_1260:
    inc rax
    cmp byte ptr [rcx + rax], sil
    jne .LNotifyHook_1260
    lea r12, [rip + ref_xeq_suffix + 1]
    test rax, rax
    je .LNotifyHook_127f
    cmp byte ptr [rsp + rax + 0x4f], 0x5c
    {load} mov r8, r12
    je .LNotifyHook_1286
.LNotifyHook_127f:
    lea r8, [rip + ref_xeq_suffix]
.LNotifyHook_1286:
    lea rcx, [rsp + 0x50]
    dec rcx
    xchg ax, ax
.LNotifyHook_1290:
    cmp byte ptr [rcx + 1], sil
    lea rcx, [rcx + 1]
    jne .LNotifyHook_1290
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
.LNotifyHook_12a0:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .LNotifyHook_12a0
    {load} xor edx, edx
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp__access]
    {load} cmp eax, r15d
    je .LNotifyHook_134e
    lea r9, [rsp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea r8, [rbp + 0x1f0]
    mov edx, 0x104
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    mov r8d, 0x104
    lea rdx, [rbp + 0x60]
    lea rcx, [rbp + 0x1f0]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    movsxd rcx, eax
    test eax, eax
    jle .LNotifyHook_1319
.LNotifyHook_1305:
    cmp byte ptr [rbp + rcx + 0x5f], 0x5c
    jne .LNotifyHook_1319
    dec rcx
    mov byte ptr [rbp + rcx + 0x60], sil
    test rcx, rcx
    jg .LNotifyHook_1305
.LNotifyHook_1319:
    cmp dword ptr [rsp + 0x38], esi
    jle .LNotifyHook_1345
    lea rdi, [r13 + 1]
    {load} mov rbx, rsi
.LNotifyHook_1326:
    mov rdx, qword ptr [r14 + rbx*8]
    test rdx, rdx
    je .LNotifyHook_133d
    lea rcx, [rbp + 0x60]
    call qword ptr [rip + ref___imp__stricmp]
    test eax, eax
    je .LNotifyHook_134e
.LNotifyHook_133d:
    inc rbx
    {load} cmp rbx, rdi
    jl .LNotifyHook_1326
.LNotifyHook_1345:
    lea rcx, [rbp + 0x60]
    call ref_AddToPath
.LNotifyHook_134e:
    mov qword ptr [rsp + 0x30], rsi
    lea r15, [rip + ref___ImageBase]
    mov dword ptr [rsp + 0x40], 0x100
    {load} mov rcx, rsi
    mov byte ptr [rsp + 0x50], sil
    {disp8} nop word ptr [rax + rax]
.LNotifyHook_1370:
    movzx eax, byte ptr [rcx + r15 + rva_system_key]
    mov byte ptr [rbp + rcx + 0x170], al
    lea rcx, [rcx + 1]
    test al, al
    jne .LNotifyHook_1370
    lea rcx, [rbp + 0x170]
    mov r15, 0xffffffffffffffff
    dec rcx
    {disp32} nop dword ptr [rax]
.LNotifyHook_13a0:
    cmp byte ptr [rcx + 1], sil
    lea rcx, [rcx + 1]
    jne .LNotifyHook_13a0
    mov eax, dword ptr [rip + ref_system_aplus]
    lea rdx, [rbp + 0x170]
    mov dword ptr [rcx], eax
    mov r9d, 0x20019
    movzx eax, word ptr [rip + ref_system_aplus + 4]
    {load} xor r8d, r8d
    mov word ptr [rcx + 4], ax
    movzx eax, byte ptr [rip + ref_system_aplus + 6]
    mov byte ptr [rcx + 6], al
    lea rax, [rsp + 0x30]
    mov rcx, 0xffffffff80000002
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LNotifyHook_1429
    mov rcx, qword ptr [rsp + 0x30]
    lea rax, [rsp + 0x40]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_system_asptop]
    lea rax, [rsp + 0x50]
    {load} xor r9d, r9d
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x30]
    call qword ptr [rip + ref___imp_RegCloseKey]
.LNotifyHook_1429:
    lea rcx, [rsp + 0x50]
    {load} mov rax, r15
.LNotifyHook_1431:
    inc rax
    cmp byte ptr [rcx + rax], sil
    jne .LNotifyHook_1431
    test rax, rax
    je .LNotifyHook_1449
    cmp byte ptr [rsp + rax + 0x4f], 0x5c
    {load} mov r8, r12
    je .LNotifyHook_1450
.LNotifyHook_1449:
    lea r8, [rip + ref_xeq_suffix]
.LNotifyHook_1450:
    lea rcx, [rsp + 0x50]
    dec rcx
    {disp32} nop dword ptr [rax + rax]
.LNotifyHook_1460:
    cmp byte ptr [rcx + 1], sil
    lea rcx, [rcx + 1]
    jne .LNotifyHook_1460
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
.LNotifyHook_1470:
    movzx eax, byte ptr [r8 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .LNotifyHook_1470
    {load} xor edx, edx
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp__access]
    {load} cmp eax, r15d
    je .LNotifyHook_151e
    lea r9, [rsp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea r8, [rbp + 0x1f0]
    mov edx, 0x104
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    mov r8d, 0x104
    lea rdx, [rbp + 0x60]
    lea rcx, [rbp + 0x1f0]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    movsxd rcx, eax
    test eax, eax
    jle .LNotifyHook_14e9
.LNotifyHook_14d5:
    cmp byte ptr [rbp + rcx + 0x5f], 0x5c
    jne .LNotifyHook_14e9
    dec rcx
    mov byte ptr [rbp + rcx + 0x60], sil
    test rcx, rcx
    jg .LNotifyHook_14d5
.LNotifyHook_14e9:
    cmp dword ptr [rsp + 0x38], esi
    jle .LNotifyHook_1515
    lea rdi, [r13 + 1]
    {load} mov rbx, rsi
.LNotifyHook_14f6:
    mov rdx, qword ptr [r14 + rbx*8]
    test rdx, rdx
    je .LNotifyHook_150d
    lea rcx, [rbp + 0x60]
    call qword ptr [rip + ref___imp__stricmp]
    test eax, eax
    je .LNotifyHook_151e
.LNotifyHook_150d:
    inc rbx
    {load} cmp rbx, rdi
    jl .LNotifyHook_14f6
.LNotifyHook_1515:
    lea rcx, [rbp + 0x60]
    call ref_AddToPath
.LNotifyHook_151e:
    cmp dword ptr [rip + tail1_static_ProductCode], 2
    lea rcx, [rip + ref_properties_key]
    mov rdi, qword ptr [rsp + 0x670]
    lea rax, [rip + ref_plus_key]
    cmovne rcx, rax
    mov qword ptr [rsp + 0x30], rsi
    lea rdx, [rbp + 0x170]
    mov dword ptr [rsp + 0x40], 0x100
    {load} sub rdx, rcx
    mov byte ptr [rsp + 0x50], sil
    {disp8} nop dword ptr [rax + rax]
.LNotifyHook_1560:
    movzx eax, byte ptr [rcx]
    mov byte ptr [rcx + rdx], al
    lea rcx, [rcx + 1]
    test al, al
    jne .LNotifyHook_1560
    lea rdx, [rbp + 0x170]
    dec rdx
    {disp32} nop dword ptr [rax + rax]
.LNotifyHook_1580:
    cmp byte ptr [rdx + 1], sil
    lea rdx, [rdx + 1]
    jne .LNotifyHook_1580
    mov eax, dword ptr [rip + ref_product_aplus]
    mov r9d, 0x20019
    mov dword ptr [rdx], eax
    {load} xor r8d, r8d
    movzx eax, word ptr [rip + ref_product_aplus + 4]
    mov rcx, 0xffffffff80000002
    mov word ptr [rdx + 4], ax
    movzx eax, byte ptr [rip + ref_product_aplus + 6]
    mov byte ptr [rdx + 6], al
    lea rax, [rsp + 0x30]
    lea rdx, [rbp + 0x170]
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegOpenKeyExA]
    test eax, eax
    jne .LNotifyHook_1609
    mov rcx, qword ptr [rsp + 0x30]
    lea rax, [rsp + 0x40]
    mov qword ptr [rsp + 0x28], rax
    lea rdx, [rip + ref_product_asptop]
    lea rax, [rsp + 0x50]
    {load} xor r9d, r9d
    {load} xor r8d, r8d
    mov qword ptr [rsp + 0x20], rax
    call qword ptr [rip + ref___imp_RegQueryValueExA]
    mov rcx, qword ptr [rsp + 0x30]
    call qword ptr [rip + ref___imp_RegCloseKey]
.LNotifyHook_1609:
    lea rax, [rsp + 0x50]
    xchg ax, ax
.LNotifyHook_1610:
    inc r15
    cmp byte ptr [rax + r15], sil
    jne .LNotifyHook_1610
    test r15, r15
    je .LNotifyHook_1626
    cmp byte ptr [rsp + r15 + 0x4f], 0x5c
    je .LNotifyHook_162d
.LNotifyHook_1626:
    lea r12, [rip + ref_xeq_suffix]
.LNotifyHook_162d:
    mov r15, qword ptr [rsp + 0x630]
    lea rcx, [rsp + 0x50]
    dec rcx
    nop dword ptr [rax]
.LNotifyHook_1640:
    cmp byte ptr [rcx + 1], sil
    lea rcx, [rcx + 1]
    jne .LNotifyHook_1640
    {load} xor edx, edx
    {disp8} nop dword ptr [rax]
.LNotifyHook_1650:
    movzx eax, byte ptr [r12 + rdx]
    mov byte ptr [rcx + rdx], al
    lea rdx, [rdx + 1]
    test al, al
    jne .LNotifyHook_1650
    mov r12, qword ptr [rsp + 0x648]
    lea rcx, [rsp + 0x50]
    {load} xor edx, edx
    call qword ptr [rip + ref___imp__access]
    cmp eax, -1
    je .LNotifyHook_1709
.LNotifyHook_167e:
    lea r9, [rsp + 0x30]
    mov qword ptr [rsp + 0x30], rsi
    lea r8, [rbp + 0x1f0]
    mov edx, 0x104
    lea rcx, [rsp + 0x50]
    call qword ptr [rip + ref___imp_GetFullPathNameA]
    mov r8d, 0x104
    lea rdx, [rbp + 0x60]
    lea rcx, [rbp + 0x1f0]
    call qword ptr [rip + ref___imp_GetShortPathNameA]
    movsxd rcx, eax
    test eax, eax
    jle .LNotifyHook_16d4
    nop dword ptr [rax]
.LNotifyHook_16c0:
    cmp byte ptr [rbp + rcx + 0x5f], 0x5c
    jne .LNotifyHook_16d4
    dec rcx
    mov byte ptr [rbp + rcx + 0x60], sil
    test rcx, rcx
    jg .LNotifyHook_16c0
.LNotifyHook_16d4:
    cmp dword ptr [rsp + 0x38], esi
    jle .LNotifyHook_16ff
    lea rbx, [r13 + 1]
    xchg ax, ax
.LNotifyHook_16e0:
    mov rdx, qword ptr [r14 + rsi*8]
    test rdx, rdx
    je .LNotifyHook_16f7
    lea rcx, [rbp + 0x60]
    call qword ptr [rip + ref___imp__stricmp]
    test eax, eax
    je .LNotifyHook_1709
.LNotifyHook_16f7:
    inc rsi
    {load} cmp rsi, rbx
    jl .LNotifyHook_16e0
.LNotifyHook_16ff:
    lea rcx, [rsp + 0x50]
    call ref_AddToPath
.LNotifyHook_1709:
    {load} mov rcx, r14
    call qword ptr [rip + ref___imp_free]
    mov r14, qword ptr [rsp + 0x638]
    mov r13, qword ptr [rsp + 0x640]
    mov rsi, qword ptr [rsp + 0x668]
    mov rbx, qword ptr [rsp + 0x660]
notification_return:
    {load} xor eax, eax
    mov rcx, qword ptr [rbp + 0x520]
    {load} xor rcx, rsp
    call ref___security_check_cookie
    add rsp, 0x650
    pop rbp
    ret
.LNotifyHook_174c:
    cmp byte ptr [rbx], sil
    je .LNotifyHook_0db3
    test r13, r13
    je .LNotifyHook_1762
    {disp8} mov qword ptr [r13], rdi
    add r13, 8
.LNotifyHook_1762:
    inc r14d
    mov dword ptr [rsp + 0x38], r14d
    {disp8} nop word ptr [rax + rax]
.LNotifyHook_1770:
    movzx ecx, byte ptr [rbx]
    mov r14d, 1
    {load} mov eax, esi
    cmp cl, 0x5c
    jne .LNotifyHook_178e
.LNotifyHook_1780:
    movzx ecx, byte ptr [rbx + 1]
    inc rbx
    inc eax
    cmp cl, 0x5c
    je .LNotifyHook_1780
.LNotifyHook_178e:
    cmp cl, 0x22
    jne .LNotifyHook_17bd
    test r14b, al
    jne .LNotifyHook_17bb
    {load} mov r14d, esi
    test r12d, r12d
    je .LNotifyHook_17b0
    cmp byte ptr [rbx + 1], 0x22
    lea rcx, [rbx + 1]
    cmove rbx, rcx
    sete r14b
.LNotifyHook_17b0:
    test r12d, r12d
    {load} mov ecx, esi
    sete cl
    {load} mov r12d, ecx
.LNotifyHook_17bb:
    shr eax, 1
.LNotifyHook_17bd:
    test eax, eax
    je .LNotifyHook_17d5
    {load} add r15d, eax
.LNotifyHook_17c4:
    dec eax
    test rdi, rdi
    je .LNotifyHook_17d1
    mov byte ptr [rdi], 0x5c
    inc rdi
.LNotifyHook_17d1:
    test eax, eax
    jne .LNotifyHook_17c4
.LNotifyHook_17d5:
    movsx eax, byte ptr [rbx]
    test al, al
    je .LNotifyHook_1811
    test r12d, r12d
    jne .LNotifyHook_17f4
    {load} mov edx, eax
    lea rcx, [rip + ref_hook_separator1]
    call ref_strchr
    test rax, rax
    jne .LNotifyHook_1811
.LNotifyHook_17f4:
    test r14d, r14d
    je .LNotifyHook_1809
    test rdi, rdi
    je .LNotifyHook_1806
    movzx eax, byte ptr [rbx]
    mov byte ptr [rdi], al
    inc rdi
.LNotifyHook_1806:
    inc r15d
.LNotifyHook_1809:
    inc rbx
    jmp .LNotifyHook_1770
.LNotifyHook_1811:
    test rdi, rdi
    je .LNotifyHook_181c
    mov byte ptr [rdi], sil
    inc rdi
.LNotifyHook_181c:
    mov r14d, dword ptr [rsp + 0x38]
    inc r15d
    jmp .LNotifyHook_0d88
.LNotifyHook_1829:
    cmp byte ptr [rbx], sil
    je .LNotifyHook_0e23
    test r12, r12
    je .LNotifyHook_183f
    mov qword ptr [r12], rdi
    add r12, 8
.LNotifyHook_183f:
    inc r14d
    mov dword ptr [rsp + 0x38], r14d
    {disp32} nop word ptr [rax + rax]
.LNotifyHook_1850:
    movzx eax, byte ptr [rbx]
    mov r14d, 1
    {load} mov edx, esi
    cmp al, 0x5c
    jne .LNotifyHook_186d
    nop
.LNotifyHook_1860:
    movzx eax, byte ptr [rbx + 1]
    inc rbx
    inc edx
    cmp al, 0x5c
    je .LNotifyHook_1860
.LNotifyHook_186d:
    cmp al, 0x22
    jne .LNotifyHook_189b
    test r14b, dl
    jne .LNotifyHook_1899
    {load} mov r14d, esi
    test r15d, r15d
    je .LNotifyHook_188e
    cmp byte ptr [rbx + 1], 0x22
    lea rax, [rbx + 1]
    cmove rbx, rax
    sete r14b
.LNotifyHook_188e:
    test r15d, r15d
    {load} mov eax, esi
    sete al
    {load} mov r15d, eax
.LNotifyHook_1899:
    shr edx, 1
.LNotifyHook_189b:
    test edx, edx
    je .LNotifyHook_18b1
    nop
.LNotifyHook_18a0:
    dec edx
    test rdi, rdi
    je .LNotifyHook_18ad
    mov byte ptr [rdi], 0x5c
    inc rdi
.LNotifyHook_18ad:
    test edx, edx
    jne .LNotifyHook_18a0
.LNotifyHook_18b1:
    movsx eax, byte ptr [rbx]
    test al, al
    je .LNotifyHook_18ea
    test r15d, r15d
    jne .LNotifyHook_18d0
    {load} mov edx, eax
    lea rcx, [rip + ref_hook_separator2]
    call ref_strchr
    test rax, rax
    jne .LNotifyHook_18ea
.LNotifyHook_18d0:
    test r14d, r14d
    je .LNotifyHook_18e2
    test rdi, rdi
    je .LNotifyHook_18e2
    movzx eax, byte ptr [rbx]
    mov byte ptr [rdi], al
    inc rdi
.LNotifyHook_18e2:
    inc rbx
    jmp .LNotifyHook_1850
.LNotifyHook_18ea:
    mov r14d, dword ptr [rsp + 0x38]
    test rdi, rdi
    je .LNotifyHook_0df0
    mov byte ptr [rdi], sil
    inc rdi
    jmp .LNotifyHook_0df0
    nop
notification_dispatch:
    .long rva_notification_start  # notification 0
    .long rva_notification_return  # notification 1
    .long rva_notification_return  # notification 2
    .long rva_notification_return  # notification 3
    .long rva_notification_return  # notification 4
    .long rva_notification_return  # notification 5
.LNotifyHook_191c:
end_ap04:

# Contribution 5: .text$mn
.section .ap05,"x"
section_5:

# Return the address of the local UCRT printf option word.
__local_stdio_printf_options:
    lea rax, [rip + ref_OptionsStorage]
    ret
end_ap05:

# Contribution 6: .text$mn
.section .ap06,"x"
section_6:

# Forward bounded formatting options and normalize negative results.
_vsnprintf_l:
vsnprintf_begin:
    mov qword ptr [rsp + 8], rbx
    mov qword ptr [rsp + 0x10], rbp
    mov qword ptr [rsp + 0x18], rsi
    push rdi
.L_vsnprintf_l_0010:
    sub rsp, 0x30
.L_vsnprintf_l_0014:
    {load} mov rbx, r9
    {load} mov rdi, r8
    {load} mov rsi, rdx
    {load} mov rbp, rcx
    call ref___local_stdio_printf_options
    {load} mov r9, rdi
    {load} mov r8, rsi
    {load} mov rdx, rbp
    mov rcx, qword ptr [rax]
    mov rax, qword ptr [rsp + 0x60]
    or rcx, 1
    mov qword ptr [rsp + 0x28], rax
    mov qword ptr [rsp + 0x20], rbx
    call qword ptr [rip + ref___imp___stdio_common_vsprintf]
    mov rbx, qword ptr [rsp + 0x40]
    mov ecx, 0xffffffff
    mov rbp, qword ptr [rsp + 0x48]
    test eax, eax
    mov rsi, qword ptr [rsp + 0x50]
    cmovs eax, ecx
    add rsp, 0x30
    pop rdi
    ret
.L_vsnprintf_l_0069:
end_ap06:

# Contribution 7: .text$mn
.section .ap07,"x"
section_7:

# Forward unbounded formatting options and normalize negative results.
_vsprintf_l:
vsprintf_begin:
    mov qword ptr [rsp + 8], rbx
    mov qword ptr [rsp + 0x10], rbp
    mov qword ptr [rsp + 0x18], rsi
    push rdi
.L_vsprintf_l_0010:
    sub rsp, 0x30
.L_vsprintf_l_0014:
    {load} mov rbx, r9
    {load} mov rdi, r8
    {load} mov rsi, rdx
    {load} mov rbp, rcx
    call ref___local_stdio_printf_options
    mov qword ptr [rsp + 0x28], rbx
    {load} mov r9, rsi
    mov rbx, 0xffffffffffffffff
    mov qword ptr [rsp + 0x20], rdi
    {load} mov r8, rbx
    {load} mov rdx, rbp
    mov rcx, qword ptr [rax]
    or rcx, 1
    call qword ptr [rip + ref___imp___stdio_common_vsprintf]
    mov rbp, qword ptr [rsp + 0x48]
    test eax, eax
    mov rsi, qword ptr [rsp + 0x50]
    cmovs eax, ebx
    mov rbx, qword ptr [rsp + 0x40]
    add rsp, 0x30
    pop rdi
    ret
.L_vsprintf_l_0066:
end_ap07:

# Contribution 8: .text$mn
.section .ap08,"x"
section_8:

# Capture the Win64 variable argument area and dispatch to the UCRT formatter.
sprintf:
sprintf_begin:
    mov qword ptr [rsp + 0x10], rdx
    mov qword ptr [rsp + 0x18], r8
    mov qword ptr [rsp + 0x20], r9
    push rbx
.Lsprintf_0010:
    push rsi
.Lsprintf_0011:
    push rdi
.Lsprintf_0012:
    sub rsp, 0x30
.Lsprintf_0016:
    {load} mov rbx, rdx
    lea rsi, [rsp + 0x60]
    {load} mov rdi, rcx
    call ref___local_stdio_printf_options
    {load} mov r9, rbx
    mov qword ptr [rsp + 0x28], rsi
    mov rbx, 0xffffffffffffffff
    mov qword ptr [rsp + 0x20], 0
    {load} mov r8, rbx
    {load} mov rdx, rdi
    mov rcx, qword ptr [rax]
    or rcx, 1
    call qword ptr [rip + ref___imp___stdio_common_vsprintf]
    test eax, eax
    cmovs eax, ebx
    add rsp, 0x30
    pop rdi
    pop rsi
    pop rbx
    ret
.Lsprintf_005e:
end_ap08:

# Contribution 9: .xdata
.section .ap09,"d"
section_9:
unwind__vsnprintf_l:
    .byte 1 | (0 << 3), .L_vsnprintf_l_0014 - _vsnprintf_l, (.Lcodes_end_9_0 - .Lcodes_9_0) / 2, 0
.Lcodes_9_0:
    .byte .L_vsnprintf_l_0014 - _vsnprintf_l, 4 | (6 << 4)  # save rsi
    .short 80 / 8
    .byte .L_vsnprintf_l_0014 - _vsnprintf_l, 4 | (5 << 4)  # save rbp
    .short 72 / 8
    .byte .L_vsnprintf_l_0014 - _vsnprintf_l, 4 | (3 << 4)  # save rbx
    .short 64 / 8
    .byte .L_vsnprintf_l_0014 - _vsnprintf_l, 2 | (5 << 4)  # allocate 48 bytes
    .byte .L_vsnprintf_l_0010 - _vsnprintf_l, 0 | (7 << 4)  # push rdi
.Lcodes_end_9_0:
end_ap09:

# Contribution 10: .pdata
.section .ap10,"d"
section_10:
pdata__vsnprintf_l:
    .long rva_vsnprintf_begin, rva_vsnprintf_begin + (.L_vsnprintf_l_0069 - vsnprintf_begin), rva_unwind__vsnprintf_l
end_ap10:

# Contribution 11: .xdata
.section .ap11,"d"
section_11:
unwind__vsprintf_l:
    .byte 1 | (0 << 3), .L_vsprintf_l_0014 - _vsprintf_l, (.Lcodes_end_11_0 - .Lcodes_11_0) / 2, 0
.Lcodes_11_0:
    .byte .L_vsprintf_l_0014 - _vsprintf_l, 4 | (6 << 4)  # save rsi
    .short 80 / 8
    .byte .L_vsprintf_l_0014 - _vsprintf_l, 4 | (5 << 4)  # save rbp
    .short 72 / 8
    .byte .L_vsprintf_l_0014 - _vsprintf_l, 4 | (3 << 4)  # save rbx
    .short 64 / 8
    .byte .L_vsprintf_l_0014 - _vsprintf_l, 2 | (5 << 4)  # allocate 48 bytes
    .byte .L_vsprintf_l_0010 - _vsprintf_l, 0 | (7 << 4)  # push rdi
.Lcodes_end_11_0:
end_ap11:

# Contribution 12: .pdata
.section .ap12,"d"
section_12:
pdata__vsprintf_l:
    .long rva_vsprintf_begin, rva_vsprintf_begin + (.L_vsprintf_l_0066 - vsprintf_begin), rva_unwind__vsprintf_l
end_ap12:

# Contribution 13: .xdata
.section .ap13,"d"
section_13:
unwind_sprintf:
    .byte 1 | (0 << 3), .Lsprintf_0016 - sprintf, (.Lcodes_end_13_0 - .Lcodes_13_0) / 2, 0
.Lcodes_13_0:
    .byte .Lsprintf_0016 - sprintf, 2 | (5 << 4)  # allocate 48 bytes
    .byte .Lsprintf_0012 - sprintf, 0 | (7 << 4)  # push rdi
    .byte .Lsprintf_0011 - sprintf, 0 | (6 << 4)  # push rsi
    .byte .Lsprintf_0010 - sprintf, 0 | (3 << 4)  # push rbx
.Lcodes_end_13_0:
end_ap13:

# Contribution 14: .pdata
.section .ap14,"d"
section_14:
pdata_sprintf:
    .long rva_sprintf_begin, rva_sprintf_begin + (.Lsprintf_005e - sprintf_begin), rva_unwind_sprintf
end_ap14:

# Contribution 15: .xdata
.section .ap15,"d"
section_15:
unwind__zever_set_uversion:
    .byte 1 | (0 << 3), .Lzever_set_uversion_0006 - zever_set_uversion, (.Lcodes_end_15_0 - .Lcodes_15_0) / 2, 0
.Lcodes_15_0:
    .byte .Lzever_set_uversion_0006 - zever_set_uversion, 2 | (3 << 4)  # allocate 32 bytes
    .byte .Lzever_set_uversion_0002 - zever_set_uversion, 0 | (3 << 4)  # push rbx
.Lcodes_end_15_0:
unwind__zever_apversion:
    .byte 1 | (0 << 3), .Lzever_apversion_006a - zever_apversion, (.Lcodes_end_15_8 - .Lcodes_15_8) / 2, 0
.Lcodes_15_8:
    .byte .Lzever_apversion_006a - zever_apversion, 4 | (3 << 4)  # save rbx
    .short 48 / 8
    .byte .Lzever_apversion_006a - zever_apversion, 2 | (3 << 4)  # allocate 32 bytes
    .byte .Lzever_apversion_0066 - zever_apversion, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_8:
unwind__Get_AspTop:
    .byte 1 | (3 << 3), .LGet_AspTop_039f - Get_AspTop, (.Lcodes_end_15_20 - .Lcodes_15_20) / 2, 0
.Lcodes_15_20:
    .byte .LGet_AspTop_038d - Get_AspTop, 4 | (3 << 4)  # save rbx
    .short 240 / 8
    .byte .LGet_AspTop_038d - Get_AspTop, 1 | (0 << 4)  # allocate large stack frame
    .short 208 / 8
    .byte .LGet_AspTop_0386 - Get_AspTop, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_20:
    .short 0
    .long rva___GSHandlerCheck  # exception and unwind handler
    .long 0xc0  # GS cookie frame offset and flags
unwind__Get_APrSystem_Top:
    .byte 1 | (3 << 3), .LGet_APrSystem_Top_04cf - Get_APrSystem_Top, (.Lcodes_end_15_44 - .Lcodes_15_44) / 2, 0
.Lcodes_15_44:
    .byte .LGet_APrSystem_Top_04bd - Get_APrSystem_Top, 4 | (3 << 4)  # save rbx
    .short 240 / 8
    .byte .LGet_APrSystem_Top_04bd - Get_APrSystem_Top, 1 | (0 << 4)  # allocate large stack frame
    .short 208 / 8
    .byte .LGet_APrSystem_Top_04b6 - Get_APrSystem_Top, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_44:
    .short 0
    .long rva___GSHandlerCheck  # exception and unwind handler
    .long 0xc0  # GS cookie frame offset and flags
unwind__GetOOMFTop:
    .byte 1 | (3 << 3), .LGetOOMFTop_05eb - GetOOMFTop, (.Lcodes_end_15_68 - .Lcodes_15_68) / 2, 0
.Lcodes_15_68:
    .byte .LGetOOMFTop_05d9 - GetOOMFTop, 1 | (0 << 4)  # allocate large stack frame
    .short 464 / 8
    .byte .LGetOOMFTop_05d2 - GetOOMFTop, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_68:
    .short 0
    .long rva___GSHandlerCheck  # exception and unwind handler
    .long 0x1c0  # GS cookie frame offset and flags
chain_0__GetOOMFTop:
    .byte 1 | (4 << 3), .LGetOOMFTop_0678 - .LGetOOMFTop_0670, (.Lcodes_end_15_88 - .Lcodes_15_88) / 2, 0
.Lcodes_15_88:
    .byte .LGetOOMFTop_0678 - .LGetOOMFTop_0670, 4 | (3 << 4)  # save rbx
    .short 496 / 8
.Lcodes_end_15_88:
    .long rva_oomftop_begin, rva_oomftop_begin + (.LGetOOMFTop_0670 - oomftop_begin), rva_unwind__GetOOMFTop  # chained parent range
chain_1__GetOOMFTop:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_108 - .Lcodes_15_108) / 2, 0
.Lcodes_15_108:
.Lcodes_end_15_108:
    .long rva_oomftop_begin, rva_oomftop_begin + (.LGetOOMFTop_0670 - oomftop_begin), rva_unwind__GetOOMFTop  # chained parent range
unwind__parse_line:
    .byte 1 | (0 << 3), .Lparse_line_072c - parse_line, (.Lcodes_end_15_124 - .Lcodes_15_124) / 2, 0
.Lcodes_15_124:
    .byte .Lparse_line_072c - parse_line, 4 | (6 << 4)  # save rsi
    .short 96 / 8
    .byte .Lparse_line_072c - parse_line, 4 | (5 << 4)  # save rbp
    .short 88 / 8
    .byte .Lparse_line_072c - parse_line, 4 | (3 << 4)  # save rbx
    .short 80 / 8
    .byte .Lparse_line_072c - parse_line, 2 | (3 << 4)  # allocate 32 bytes
    .byte .Lparse_line_0728 - parse_line, 0 | (15 << 4)  # push r15
    .byte .Lparse_line_0726 - parse_line, 0 | (14 << 4)  # push r14
    .byte .Lparse_line_0724 - parse_line, 0 | (13 << 4)  # push r13
    .byte .Lparse_line_0722 - parse_line, 0 | (12 << 4)  # push r12
    .byte .Lparse_line_0720 - parse_line, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_124:
unwind__GetRegistryValue:
    .byte 1 | (0 << 3), .LGetRegistryValue_08af - GetRegistryValue, (.Lcodes_end_15_152 - .Lcodes_15_152) / 2, 0
.Lcodes_15_152:
    .byte .LGetRegistryValue_08af - GetRegistryValue, 4 | (3 << 4)  # save rbx
    .short 64 / 8
    .byte .LGetRegistryValue_08af - GetRegistryValue, 2 | (5 << 4)  # allocate 48 bytes
    .byte .LGetRegistryValue_08ab - GetRegistryValue, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_152:
unwind__AddToPath:
    .byte 1 | (0 << 3), .LAddToPath_0954 - AddToPath, (.Lcodes_end_15_164 - .Lcodes_15_164) / 2, 0
.Lcodes_15_164:
    .byte .LAddToPath_0954 - AddToPath, 4 | (6 << 4)  # save rsi
    .short 64 / 8
    .byte .LAddToPath_0954 - AddToPath, 4 | (5 << 4)  # save rbp
    .short 56 / 8
    .byte .LAddToPath_0954 - AddToPath, 4 | (3 << 4)  # save rbx
    .short 48 / 8
    .byte .LAddToPath_0954 - AddToPath, 2 | (3 << 4)  # allocate 32 bytes
    .byte .LAddToPath_0950 - AddToPath, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_164:
unwind__searchargs:
    .byte 1 | (0 << 3), .Lsearchargs_0a44 - searchargs, (.Lcodes_end_15_184 - .Lcodes_15_184) / 2, 0
.Lcodes_15_184:
    .byte .Lsearchargs_0a44 - searchargs, 4 | (6 << 4)  # save rsi
    .short 64 / 8
    .byte .Lsearchargs_0a44 - searchargs, 4 | (5 << 4)  # save rbp
    .short 56 / 8
    .byte .Lsearchargs_0a44 - searchargs, 4 | (3 << 4)  # save rbx
    .short 48 / 8
    .byte .Lsearchargs_0a44 - searchargs, 2 | (3 << 4)  # allocate 32 bytes
    .byte .Lsearchargs_0a40 - searchargs, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_184:
unwind__GetShortName:
    .byte 1 | (3 << 3), .LGetShortName_0abf - GetShortName, (.Lcodes_end_15_204 - .Lcodes_15_204) / 2, 0
.Lcodes_15_204:
    .byte .LGetShortName_0aad - GetShortName, 4 | (3 << 4)  # save rbx
    .short 376 / 8
    .byte .LGetShortName_0aad - GetShortName, 1 | (0 << 4)  # allocate large stack frame
    .short 336 / 8
    .byte .LGetShortName_0aa6 - GetShortName, 0 | (7 << 4)  # push rdi
.Lcodes_end_15_204:
    .short 0
    .long rva___GSHandlerCheck  # exception and unwind handler
    .long 0x140  # GS cookie frame offset and flags
unwind__ConvertPathsToShortName:
    .byte 1 | (3 << 3), .LConvertPathsToShortName_0b73 - ConvertPathsToShortName, (.Lcodes_end_15_228 - .Lcodes_15_228) / 2, 0
.Lcodes_15_228:
    .byte .LConvertPathsToShortName_0b61 - ConvertPathsToShortName, 1 | (0 << 4)  # allocate large stack frame
    .short 616 / 8
    .byte .LConvertPathsToShortName_0b5a - ConvertPathsToShortName, 0 | (15 << 4)  # push r15
    .byte .LConvertPathsToShortName_0b58 - ConvertPathsToShortName, 0 | (14 << 4)  # push r14
    .byte .LConvertPathsToShortName_0b56 - ConvertPathsToShortName, 0 | (12 << 4)  # push r12
    .byte .LConvertPathsToShortName_0b54 - ConvertPathsToShortName, 0 | (7 << 4)  # push rdi
    .byte .LConvertPathsToShortName_0b53 - ConvertPathsToShortName, 0 | (6 << 4)  # push rsi
    .byte .LConvertPathsToShortName_0b52 - ConvertPathsToShortName, 0 | (5 << 4)  # push rbp
.Lcodes_end_15_228:
    .long rva___GSHandlerCheck  # exception and unwind handler
    .long 0x250  # GS cookie frame offset and flags
chain_0__ConvertPathsToShortName:
    .byte 1 | (4 << 3), .LConvertPathsToShortName_0ba7 - .LConvertPathsToShortName_0b9f, (.Lcodes_end_15_256 - .Lcodes_15_256) / 2, 0
.Lcodes_15_256:
    .byte .LConvertPathsToShortName_0ba7 - .LConvertPathsToShortName_0b9f, 4 | (3 << 4)  # save rbx
    .short 608 / 8
.Lcodes_end_15_256:
    .long rva_convertpaths_begin, rva_convertpaths_begin + (.LConvertPathsToShortName_0b9f - convertpaths_begin), rva_unwind__ConvertPathsToShortName  # chained parent range
chain_1__ConvertPathsToShortName:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_276 - .Lcodes_15_276) / 2, 0
.Lcodes_15_276:
.Lcodes_end_15_276:
    .long rva_convertpaths_begin, rva_convertpaths_begin + (.LConvertPathsToShortName_0b9f - convertpaths_begin), rva_unwind__ConvertPathsToShortName  # chained parent range
unwind_NotifyHook:
    .byte 1 | (3 << 3), .LNotifyHook_0cd2 - NotifyHook, (.Lcodes_end_15_292 - .Lcodes_15_292) / 2, 0
.Lcodes_15_292:
    .byte .LNotifyHook_0cc1 - NotifyHook, 1 | (0 << 4)  # allocate large stack frame
    .short 1616 / 8
    .byte .LNotifyHook_0cb2 - NotifyHook, 0 | (5 << 4)  # push rbp
.Lcodes_end_15_292:
    .short 0
    .long rva___GSHandlerCheck  # exception and unwind handler
    .long 0x620  # GS cookie frame offset and flags
chain_1_NotifyHook:
    .byte 1 | (4 << 3), .LNotifyHook_0d14 - .LNotifyHook_0cfd, (.Lcodes_end_15_312 - .Lcodes_15_312) / 2, 0
.Lcodes_15_312:
    .byte .LNotifyHook_0d14 - .LNotifyHook_0cfd, 4 | (6 << 4)  # save rsi
    .short 1640 / 8
    .byte .LNotifyHook_0d05 - .LNotifyHook_0cfd, 4 | (3 << 4)  # save rbx
    .short 1632 / 8
.Lcodes_end_15_312:
    .long rva_hook_begin, rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_unwind_NotifyHook  # chained parent range
chain_6_NotifyHook:
    .byte 1 | (4 << 3), .LNotifyHook_0d41 - .LNotifyHook_0d17, (.Lcodes_end_15_336 - .Lcodes_15_336) / 2, 0
.Lcodes_15_336:
    .byte .LNotifyHook_0d41 - .LNotifyHook_0d17, 4 | (15 << 4)  # save r15
    .short 1584 / 8
    .byte .LNotifyHook_0d39 - .LNotifyHook_0d17, 4 | (14 << 4)  # save r14
    .short 1592 / 8
    .byte .LNotifyHook_0d31 - .LNotifyHook_0d17, 4 | (13 << 4)  # save r13
    .short 1600 / 8
    .byte .LNotifyHook_0d29 - .LNotifyHook_0d17, 4 | (12 << 4)  # save r12
    .short 1608 / 8
    .byte .LNotifyHook_0d1f - .LNotifyHook_0d17, 4 | (7 << 4)  # save rdi
    .short 1648 / 8
.Lcodes_end_15_336:
    .long rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_hook_begin + (.LNotifyHook_0d17 - hook_begin), rva_chain_1_NotifyHook  # chained parent range
chain_7_NotifyHook:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_372 - .Lcodes_15_372) / 2, 0
.Lcodes_15_372:
    .byte 0, 4 | (15 << 4)  # save r15
    .short 1584 / 8
    .byte 0, 4 | (14 << 4)  # save r14
    .short 1592 / 8
    .byte 0, 4 | (13 << 4)  # save r13
    .short 1600 / 8
    .byte 0, 4 | (12 << 4)  # save r12
    .short 1608 / 8
.Lcodes_end_15_372:
    .long rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_hook_begin + (.LNotifyHook_0d17 - hook_begin), rva_chain_1_NotifyHook  # chained parent range
chain_8_NotifyHook:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_404 - .Lcodes_15_404) / 2, 0
.Lcodes_15_404:
    .byte 0, 4 | (14 << 4)  # save r14
    .short 1592 / 8
    .byte 0, 4 | (13 << 4)  # save r13
    .short 1600 / 8
    .byte 0, 4 | (12 << 4)  # save r12
    .short 1608 / 8
.Lcodes_end_15_404:
    .long rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_hook_begin + (.LNotifyHook_0d17 - hook_begin), rva_chain_1_NotifyHook  # chained parent range
chain_9_NotifyHook:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_432 - .Lcodes_15_432) / 2, 0
.Lcodes_15_432:
    .byte 0, 4 | (14 << 4)  # save r14
    .short 1592 / 8
    .byte 0, 4 | (13 << 4)  # save r13
    .short 1600 / 8
.Lcodes_end_15_432:
    .long rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_hook_begin + (.LNotifyHook_0d17 - hook_begin), rva_chain_1_NotifyHook  # chained parent range
chain_10_NotifyHook:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_456 - .Lcodes_15_456) / 2, 0
.Lcodes_15_456:
.Lcodes_end_15_456:
    .long rva_hook_begin, rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_unwind_NotifyHook  # chained parent range
chain_11_NotifyHook:
    .byte 1 | (4 << 3), 0, (.Lcodes_end_15_472 - .Lcodes_15_472) / 2, 0
.Lcodes_15_472:
    .byte 0, 4 | (15 << 4)  # save r15
    .short 1584 / 8
    .byte 0, 4 | (14 << 4)  # save r14
    .short 1592 / 8
    .byte 0, 4 | (13 << 4)  # save r13
    .short 1600 / 8
    .byte 0, 4 | (12 << 4)  # save r12
    .short 1608 / 8
    .byte 0, 4 | (7 << 4)  # save rdi
    .short 1648 / 8
    .byte 0, 4 | (6 << 4)  # save rsi
    .short 1640 / 8
    .byte 0, 4 | (3 << 4)  # save rbx
    .short 1632 / 8
.Lcodes_end_15_472:
    .long rva_hook_begin, rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_unwind_NotifyHook  # chained parent range
end_ap15:

# Contribution 16: .pdata
.section .ap16,"d"
section_16:
pdata__zever_set_uversion:
    .long rva_set_uversion_begin, rva_set_uversion_begin + (set_uversion_end - set_uversion_begin), rva_unwind__zever_set_uversion
pdata__zever_apversion:
    .long rva_apversion_begin, rva_apversion_begin + (.Lzever_apversion_033c - apversion_begin), rva_unwind__zever_apversion
pdata__Get_AspTop:
    .long rva_asptop_begin, rva_asptop_begin + (.LGet_AspTop_04a4 - asptop_begin), rva_unwind__Get_AspTop
pdata__Get_APrSystem_Top:
    .long rva_aprsystem_begin, rva_aprsystem_begin + (.LGet_APrSystem_Top_05c4 - aprsystem_begin), rva_unwind__Get_APrSystem_Top
pdata__GetOOMFTop:
    .long rva_oomftop_begin, rva_oomftop_begin + (.LGetOOMFTop_0670 - oomftop_begin), rva_unwind__GetOOMFTop
pdata_0__GetOOMFTop:
    .long rva_oomftop_begin + (.LGetOOMFTop_0670 - oomftop_begin), rva_oomftop_begin + (.LGetOOMFTop_0697 - oomftop_begin), rva_chain_0__GetOOMFTop
pdata_1__GetOOMFTop:
    .long rva_oomftop_begin + (.LGetOOMFTop_0697 - oomftop_begin), rva_oomftop_begin + (.LGetOOMFTop_0700 - oomftop_begin), rva_chain_1__GetOOMFTop
pdata__parse_line:
    .long rva_parse_line, rva_parse_line + (.Lparse_line_0892 - parse_line), rva_unwind__parse_line
pdata__GetRegistryValue:
    .long rva_GetRegistryValue, rva_GetRegistryValue + (.LGetRegistryValue_092d - GetRegistryValue), rva_unwind__GetRegistryValue
pdata__AddToPath:
    .long rva_AddToPath, rva_AddToPath + (.LAddToPath_0a1d - AddToPath), rva_unwind__AddToPath
pdata__searchargs:
    .long rva_searchargs_begin, rva_searchargs_begin + (.Lsearchargs_0a8e - searchargs_begin), rva_unwind__searchargs
pdata__GetShortName:
    .long rva_shortname_begin, rva_shortname_begin + (.LGetShortName_0b42 - shortname_begin), rva_unwind__GetShortName
pdata__ConvertPathsToShortName:
    .long rva_convertpaths_begin, rva_convertpaths_begin + (.LConvertPathsToShortName_0b9f - convertpaths_begin), rva_unwind__ConvertPathsToShortName
pdata_0__ConvertPathsToShortName:
    .long rva_convertpaths_begin + (.LConvertPathsToShortName_0b9f - convertpaths_begin), rva_convertpaths_begin + (.LConvertPathsToShortName_0c85 - convertpaths_begin), rva_chain_0__ConvertPathsToShortName
pdata_1__ConvertPathsToShortName:
    .long rva_convertpaths_begin + (.LConvertPathsToShortName_0c85 - convertpaths_begin), rva_convertpaths_begin + (.LConvertPathsToShortName_0ca8 - convertpaths_begin), rva_chain_1__ConvertPathsToShortName
pdata_NotifyHook:
    .long rva_hook_begin, rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_unwind_NotifyHook
pdata_1_NotifyHook:
    .long rva_hook_begin + (.LNotifyHook_0cfd - hook_begin), rva_hook_begin + (.LNotifyHook_0d17 - hook_begin), rva_chain_1_NotifyHook
pdata_6_NotifyHook:
    .long rva_hook_begin + (.LNotifyHook_0d17 - hook_begin), rva_hook_begin + (.LNotifyHook_1560 - hook_begin), rva_chain_6_NotifyHook
pdata_7_NotifyHook:
    .long rva_hook_begin + (.LNotifyHook_1560 - hook_begin), rva_hook_begin + (.LNotifyHook_1640 - hook_begin), rva_chain_7_NotifyHook
pdata_8_NotifyHook:
    .long rva_hook_begin + (.LNotifyHook_1640 - hook_begin), rva_hook_begin + (.LNotifyHook_167e - hook_begin), rva_chain_8_NotifyHook
pdata_9_NotifyHook:
    .long rva_hook_begin + (.LNotifyHook_167e - hook_begin), rva_hook_begin + (notification_return - hook_begin), rva_chain_9_NotifyHook
pdata_10_NotifyHook:
    .long rva_hook_begin + (notification_return - hook_begin), rva_hook_begin + (.LNotifyHook_174c - hook_begin), rva_chain_10_NotifyHook
pdata_11_NotifyHook:
    .long rva_hook_begin + (.LNotifyHook_174c - hook_begin), rva_hook_begin + (.LNotifyHook_191c - hook_begin), rva_chain_11_NotifyHook
end_ap16:

# Contribution 17: .bss
.section .ap17,"d"
section_17:
OptionsStorage:
    .zero 8
end_ap17:

# Contribution 18: .bss
.section .ap18,"d"
section_18:
user_version:
    .zero 3
end_ap18:

# Contribution 19: .data
.section .ap19,"d"
section_19:
static_ProductCode:
    .long 1  # default product code
end_ap19:

# Contribution 20: .bss
.section .ap20,"d"
section_20:
str:
    .zero 128
end_ap20:

# Contribution 21: .bss
.section .ap21,"d"
section_21:
PathProcessed:
    .zero 1
end_ap21:

# Contribution 22: .chks64
.section .ap22,"d"
# build.py derives the section table of 64-bit SHA-256 prefixes after assembly.
section_22:
end_ap22:

# Microsoft COFF declarations. Columns for a section are index, COFF name,
# characteristics, associative parent and COMDAT selection. A symbol row gives
# its assembler label, COFF name, section index, type and storage class.
# Negative section indices are absolute symbols. Section labels carry auxiliary records.
#@timestamp 1744053129
#@member g:\agent\work\3\s\src\apbinrel\source\apdelayload\nt\delaylod.obj
#@section 1 .drectve 0x00100a00 0 0
#@section 2 .debug$S 0x42100040 0 0
#@section 3 .rdata 0x40400040 0 0
#@section 4 .text$mn 0x60500020 0 0
#@section 5 .text$mn 0x60501020 0 2
#@section 6 .text$mn 0x60501020 0 2
#@section 7 .text$mn 0x60501020 0 2
#@section 8 .text$mn 0x60501020 0 2
#@section 9 .xdata 0x40301040 6 5
#@section 10 .pdata 0x40301040 6 5
#@section 11 .xdata 0x40301040 7 5
#@section 12 .pdata 0x40301040 7 5
#@section 13 .xdata 0x40301040 8 5
#@section 14 .pdata 0x40301040 8 5
#@section 15 .xdata 0x40300040 0 0
#@section 16 .pdata 0x40300040 0 0
#@section 17 .bss 0xc0401080 0 2
#@section 18 .bss 0xc0300080 0 0
#@section 19 .data 0xc0300040 0 0
#@section 20 .bss 0xc0501080 0 2
#@section 21 .bss 0xc0101080 0 2
#@section 22 .chks64 0x00000a00 0 0
#@symbol ms_comp_id @comp.id -1 0 3 0x1058414
#@symbol ms_feat_00 @feat.00 -1 0 3 0x80010190
#@symbol ms_vol_md @vol.md -1 0 3 0x3
#@symbol section_1 .drectve 1 0 3
#@symbol section_2 .debug$S 2 0 3
#@symbol section_3 .rdata 3 0 3
#@symbol release_1 $SG43678 3 0 3
#@symbol release_2 $SG43681 3 0 3
#@symbol space_1 $SG43684 3 0 3
#@symbol space_2 $SG43685 3 0 3
#@symbol space_3 $SG43686 3 0 3
#@symbol properties_key $SG43690 3 0 3
#@symbol plus_key $SG43691 3 0 3
#@symbol patch_level $SG43693 3 0 3
#@symbol build_number $SG43695 3 0 3
#@symbol build_date $SG43697 3 0 3
#@symbol release_7 $SG43699 3 0 3
#@symbol space_4 $SG43702 3 0 3
#@symbol space_5 $SG43703 3 0 3
#@symbol space_6 $SG43704 3 0 3
#@symbol build_prefix $SG43705 3 0 3
#@symbol build_number_7 $SG43706 3 0 3
#@symbol patch_1 $SG43708 3 0 3
#@symbol patch_2 $SG43709 3 0 3
#@symbol patch_prefix $SG43710 3 0 3
#@symbol patch_3 $SG43711 3 0 3
#@symbol system_key $SG43713 3 0 3
#@symbol invalid_code_format $SG43715 3 0 3
#@symbol product_aplus $SG48691 3 0 3
#@symbol product_asptop $SG48693 3 0 3
#@symbol system_aplus $SG48716 3 0 3
#@symbol system_asptop $SG48718 3 0 3
#@symbol oomf_key $SG48737 3 0 3
#@symbol oomftop $SG48739 3 0 3
#@symbol token_delimiters $SG48775 3 0 3
#@symbol env_path_size $SG48812 3 0 3
#@symbol path_separator $SG48814 3 0 3
#@symbol env_path_read $SG48815 3 0 3
#@symbol env_path_write $SG48816 3 0 3
#@symbol aos_key_format $SG48903 3 0 3
#@symbol aostop $SG48904 3 0 3
#@symbol bin_suffix $SG48905 3 0 3
#@symbol xeq_suffix $SG48906 3 0 3
#@symbol shared_suffix $SG48907 3 0 3
#@symbol hook_path_size $SG48910 3 0 3
#@symbol hook_path_read $SG48911 3 0 3
#@symbol hook_separator1 $SG48912 3 0 3
#@symbol hook_separator2 $SG48913 3 0 3
#@symbol common_files_value $SG48915 3 0 3
#@symbol current_version_key $SG48916 3 0 3
#@symbol aos_release $SG48918 3 0 3
#@symbol section_4 .text$mn 4 0 3
#@symbol section_5 .text$mn 5 0 3
#@symbol section_6 .text$mn 6 0 3
#@symbol section_7 .text$mn 7 0 3
#@symbol section_8 .text$mn 8 0 3
#@symbol __report_rangecheckfailure __report_rangecheckfailure 0 32 2
#@symbol strchr strchr 0 32 2
#@symbol __imp__stricmp __imp__stricmp 0 0 2
#@symbol __imp_strncpy __imp_strncpy 0 0 2
#@symbol __imp_GetEnvironmentVariableA __imp_GetEnvironmentVariableA 0 0 2
#@symbol __imp_SetEnvironmentVariableA __imp_SetEnvironmentVariableA 0 0 2
#@symbol __imp_GetFullPathNameA __imp_GetFullPathNameA 0 0 2
#@symbol __imp_GetShortPathNameA __imp_GetShortPathNameA 0 0 2
#@symbol __imp_RegCloseKey __imp_RegCloseKey 0 0 2
#@symbol __imp_RegOpenKeyExA __imp_RegOpenKeyExA 0 0 2
#@symbol __imp_RegQueryValueExA __imp_RegQueryValueExA 0 0 2
#@symbol __imp__access __imp__access 0 0 2
#@symbol __local_stdio_printf_options __local_stdio_printf_options 5 32 2
#@symbol __imp___stdio_common_vsprintf __imp___stdio_common_vsprintf 0 0 2
#@symbol _vsnprintf_l _vsnprintf_l 6 32 2
#@symbol _vsprintf_l _vsprintf_l 7 32 2
#@symbol sprintf sprintf 8 32 2
#@symbol __imp_calloc __imp_calloc 0 0 2
#@symbol __imp_free __imp_free 0 0 2
#@symbol __imp_malloc __imp_malloc 0 0 2
#@symbol zever_set_uversion ?zever_set_uversion@@YAXPEAD@Z 4 32 2
#@symbol zever_apversion ?zever_apversion@@YAXHPEAPEAD@Z 4 32 2
#@symbol zever_set_productcode ?zever_set_productcode@@YAXH@Z 4 32 2
#@symbol zever_get_productcode ?zever_get_productcode@@YAXPEAH@Z 4 32 2
#@symbol Get_AspTop ?Get_AspTop@@YAHPEADH@Z 4 32 2
#@symbol Get_APrSystem_Top ?Get_APrSystem_Top@@YAHPEADH@Z 4 32 2
#@symbol GetOOMFTop ?GetOOMFTop@@YAHPEADH@Z 4 32 2
#@symbol parse_line ?parse_line@@YAXPEBD0PEAPEADPEAH2@Z 4 32 3
#@symbol GetRegistryValue ?GetRegistryValue@@YA_NPEBD0PEADK@Z 4 32 3
#@symbol AddToPath ?AddToPath@@YAXPEAD@Z 4 32 3
#@symbol searchargs ?searchargs@@YA_NPEBDPEAPEBDH@Z 4 32 2
#@symbol GetShortName ?GetShortName@@YAHPEBDPEADH@Z 4 32 2
#@symbol ConvertPathsToShortName ?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 4 32 2
#@symbol NotifyHook NotifyHook 4 32 2
#@symbol __GSHandlerCheck __GSHandlerCheck 0 32 2
#@symbol __security_check_cookie __security_check_cookie 0 32 2
#@symbol vsnprintf_begin $LN4 6 0 6
#@symbol vsprintf_begin $LN6 7 0 6
#@symbol sprintf_begin $LN8 8 0 6
#@symbol set_uversion_end $LN14 4 0 6
#@symbol set_uversion_begin $LN16 4 0 6
#@symbol version_dispatch $LN34 4 0 3
#@symbol version_case_1 $LN4 4 0 6
#@symbol version_case_2 $LN6 4 0 6
#@symbol version_case_3 $LN9 4 0 6
#@symbol version_case_4 $LN12 4 0 6
#@symbol version_case_5 $LN13 4 0 6
#@symbol version_case_6 $LN14 4 0 6
#@symbol version_case_7 $LN15 4 0 6
#@symbol version_case_8 $LN19 4 0 6
#@symbol apversion_begin $LN49 4 0 6
#@symbol asptop_begin $LN37 4 0 6
#@symbol aprsystem_begin $LN37 4 0 6
#@symbol oomftop_begin $LN21 4 0 6
#@symbol searchargs_begin $LN16 4 0 6
#@symbol shortname_begin $LN15 4 0 6
#@symbol convertpaths_begin $LN42 4 0 6
#@symbol notification_dispatch $LN349 4 0 3
#@symbol notification_start $LN4 4 0 6
#@symbol notification_return $LN21 4 0 6
#@symbol hook_begin $LN482 4 0 6
#@symbol section_9 .xdata 9 0 3
#@symbol unwind__vsnprintf_l $unwind$_vsnprintf_l 9 0 3
#@symbol section_10 .pdata 10 0 3
#@symbol pdata__vsnprintf_l $pdata$_vsnprintf_l 10 0 3
#@symbol section_11 .xdata 11 0 3
#@symbol unwind__vsprintf_l $unwind$_vsprintf_l 11 0 3
#@symbol section_12 .pdata 12 0 3
#@symbol pdata__vsprintf_l $pdata$_vsprintf_l 12 0 3
#@symbol section_13 .xdata 13 0 3
#@symbol unwind_sprintf $unwind$sprintf 13 0 3
#@symbol section_14 .pdata 14 0 3
#@symbol pdata_sprintf $pdata$sprintf 14 0 3
#@symbol section_15 .xdata 15 0 3
#@symbol unwind__zever_set_uversion $unwind$?zever_set_uversion@@YAXPEAD@Z 15 0 3
#@symbol section_16 .pdata 16 0 3
#@symbol pdata__zever_set_uversion $pdata$?zever_set_uversion@@YAXPEAD@Z 16 0 3
#@symbol unwind__zever_apversion $unwind$?zever_apversion@@YAXHPEAPEAD@Z 15 0 3
#@symbol pdata__zever_apversion $pdata$?zever_apversion@@YAXHPEAPEAD@Z 16 0 3
#@symbol unwind__Get_AspTop $unwind$?Get_AspTop@@YAHPEADH@Z 15 0 3
#@symbol pdata__Get_AspTop $pdata$?Get_AspTop@@YAHPEADH@Z 16 0 3
#@symbol unwind__Get_APrSystem_Top $unwind$?Get_APrSystem_Top@@YAHPEADH@Z 15 0 3
#@symbol pdata__Get_APrSystem_Top $pdata$?Get_APrSystem_Top@@YAHPEADH@Z 16 0 3
#@symbol unwind__GetOOMFTop $unwind$?GetOOMFTop@@YAHPEADH@Z 15 0 3
#@symbol pdata__GetOOMFTop $pdata$?GetOOMFTop@@YAHPEADH@Z 16 0 3
#@symbol chain_0__GetOOMFTop $chain$0$?GetOOMFTop@@YAHPEADH@Z 15 0 3
#@symbol pdata_0__GetOOMFTop $pdata$0$?GetOOMFTop@@YAHPEADH@Z 16 0 3
#@symbol chain_1__GetOOMFTop $chain$1$?GetOOMFTop@@YAHPEADH@Z 15 0 3
#@symbol pdata_1__GetOOMFTop $pdata$1$?GetOOMFTop@@YAHPEADH@Z 16 0 3
#@symbol unwind__parse_line $unwind$?parse_line@@YAXPEBD0PEAPEADPEAH2@Z 15 0 3
#@symbol pdata__parse_line $pdata$?parse_line@@YAXPEBD0PEAPEADPEAH2@Z 16 0 3
#@symbol unwind__GetRegistryValue $unwind$?GetRegistryValue@@YA_NPEBD0PEADK@Z 15 0 3
#@symbol pdata__GetRegistryValue $pdata$?GetRegistryValue@@YA_NPEBD0PEADK@Z 16 0 3
#@symbol unwind__AddToPath $unwind$?AddToPath@@YAXPEAD@Z 15 0 3
#@symbol pdata__AddToPath $pdata$?AddToPath@@YAXPEAD@Z 16 0 3
#@symbol unwind__searchargs $unwind$?searchargs@@YA_NPEBDPEAPEBDH@Z 15 0 3
#@symbol pdata__searchargs $pdata$?searchargs@@YA_NPEBDPEAPEBDH@Z 16 0 3
#@symbol unwind__GetShortName $unwind$?GetShortName@@YAHPEBDPEADH@Z 15 0 3
#@symbol pdata__GetShortName $pdata$?GetShortName@@YAHPEBDPEADH@Z 16 0 3
#@symbol unwind__ConvertPathsToShortName $unwind$?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 15 0 3
#@symbol pdata__ConvertPathsToShortName $pdata$?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 16 0 3
#@symbol chain_0__ConvertPathsToShortName $chain$0$?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 15 0 3
#@symbol pdata_0__ConvertPathsToShortName $pdata$0$?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 16 0 3
#@symbol chain_1__ConvertPathsToShortName $chain$1$?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 15 0 3
#@symbol pdata_1__ConvertPathsToShortName $pdata$1$?ConvertPathsToShortName@@YAHPEADPEAPEBDH@Z 16 0 3
#@symbol unwind_NotifyHook $unwind$NotifyHook 15 0 3
#@symbol pdata_NotifyHook $pdata$NotifyHook 16 0 3
#@symbol chain_1_NotifyHook $chain$1$NotifyHook 15 0 3
#@symbol pdata_1_NotifyHook $pdata$1$NotifyHook 16 0 3
#@symbol chain_6_NotifyHook $chain$6$NotifyHook 15 0 3
#@symbol pdata_6_NotifyHook $pdata$6$NotifyHook 16 0 3
#@symbol chain_7_NotifyHook $chain$7$NotifyHook 15 0 3
#@symbol pdata_7_NotifyHook $pdata$7$NotifyHook 16 0 3
#@symbol chain_8_NotifyHook $chain$8$NotifyHook 15 0 3
#@symbol pdata_8_NotifyHook $pdata$8$NotifyHook 16 0 3
#@symbol chain_9_NotifyHook $chain$9$NotifyHook 15 0 3
#@symbol pdata_9_NotifyHook $pdata$9$NotifyHook 16 0 3
#@symbol chain_10_NotifyHook $chain$10$NotifyHook 15 0 3
#@symbol pdata_10_NotifyHook $pdata$10$NotifyHook 16 0 3
#@symbol chain_11_NotifyHook $chain$11$NotifyHook 15 0 3
#@symbol pdata_11_NotifyHook $pdata$11$NotifyHook 16 0 3
#@symbol section_17 .bss 17 0 3
#@symbol OptionsStorage ?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA 17 0 2
#@symbol section_18 .bss 18 0 3
#@symbol user_version ?user_version@@3PADA 18 0 3
#@symbol section_19 .data 19 0 3
#@symbol static_ProductCode ?static_ProductCode@@3HA 19 0 3
#@symbol section_20 .bss 20 0 3
#@symbol str ?str@?1??zever_apversion@@YAXHPEAPEAD@Z@4PADA 20 0 3
#@symbol section_21 .bss 21 0 3
#@symbol PathProcessed ?PathProcessed@?1??NotifyHook@@9@4_NA 21 0 3
#@symbol __ImageBase __ImageBase 0 0 2
#@symbol __security_cookie __security_cookie 0 0 2
#@symbol section_22 .chks64 22 0 3
