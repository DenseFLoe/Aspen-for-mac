# nl2sol.lib | AMD64, Intel syntax. Each # MEMBER line starts a GAS translation unit.
# def_ labels locate original symbols. ref_ operands retain their exact COFF symbol identity.
# Machine instructions assemble normally. See the companion build script and layout declarations.

# MEMBER ssqjac.obj
# Entry points: SSQJAC
.intel_syntax noprefix
# Jacobian dispatch: problem codes 2..27 select the signed 32-bit offsets in the read-only table.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_72_SSQJAC:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbx
at_1_000b:
    sub    rsp,0x120
at_1_0012:
    movapd XMMWORD PTR [rsp+0x110],xmm15
at_1_001c:
    movapd XMMWORD PTR [rsp+0x100],xmm14
at_1_0026:
    movapd XMMWORD PTR [rsp+0xf0],xmm13
at_1_0030:
    movapd XMMWORD PTR [rsp+0xe0],xmm12
at_1_003a:
    movapd XMMWORD PTR [rsp+0xd0],xmm11
at_1_0044:
    movapd XMMWORD PTR [rsp+0xc0],xmm10
at_1_004e:
    movapd XMMWORD PTR [rsp+0xb0],xmm9
at_1_0058:
    movapd XMMWORD PTR [rsp+0xa0],xmm8
at_1_0062:
    movapd XMMWORD PTR [rsp+0x90],xmm7
at_1_006b:
    movapd XMMWORD PTR [rsp+0x80],xmm6
at_1_0074:
    mov    rsi,r9
    mov    rax,QWORD PTR [rsp+0x188]
    mov    r9,QWORD PTR [rsp+0x180]
    mov    rdi,QWORD PTR [r9]
    lea    r14,[rdi*8+0x0]
    mov    eax,DWORD PTR [rax]
    add    eax,0xfffffffe
    cmp    eax,0x19
    {disp32} ja     at_1_14c2
    lea    r9,[rip + ref_63_rdata]
    movsxd rax,DWORD PTR [r9+rax*4]
    add    rax,r9
    jmp    rax
at_1_00b0:
    mov    rax,QWORD PTR [rdx]
    test   rax,rax
    {disp32} jle    at_1_15f5
    mov    rcx,QWORD PTR [rcx]
    mov    rdx,rcx
    neg    rdx
    mov    r8d,0x1
    jmp    at_1_00e3
    nop    DWORD PTR [rax]
at_1_00d0:
    lea    r9,[r8+0x1]
    add    rsi,r14
    cmp    r8,rax
    mov    r8,r9
    {disp32} je     at_1_15f5
at_1_00e3:
    test   rcx,rcx
    jle    at_1_00d0
    mov    r9d,0x1
    xchg   ax,ax
at_1_00f0:
    xorps  xmm0,xmm0
    cvtsi2sd xmm0,r9
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,r8
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm1
    lea    r10,[rdx+r9*1]
    inc    r10
    inc    r9
    cmp    r10,0x1
    jne    at_1_00f0
    jmp    at_1_00d0
at_1_011d:
    movsd  xmm0,QWORD PTR [r8+0x20]
    movsd  QWORD PTR [rsp+0x78],xmm0
    movsd  xmm0,QWORD PTR [r8+0x28]
    movsd  QWORD PTR [rsp+0x28],xmm0
    movsd  xmm0,QWORD PTR [r8+0x40]
    movsd  QWORD PTR [rsp+0x60],xmm0
    movsd  xmm0,QWORD PTR [r8+0x30]
    movsd  QWORD PTR [rsp+0x70],xmm0
    movsd  xmm0,QWORD PTR [r8+0x48]
    movsd  QWORD PTR [rsp+0x58],xmm0
    movsd  xmm0,QWORD PTR [r8+0x38]
    movsd  QWORD PTR [rsp+0x68],xmm0
    movsd  xmm0,QWORD PTR [r8+0x50]
    movsd  QWORD PTR [rsp+0x50],xmm0
    movsd  xmm0,QWORD PTR [r8]
    movsd  QWORD PTR [rsp+0x48],xmm0
    movsd  xmm0,QWORD PTR [r8+0x8]
    movsd  QWORD PTR [rsp+0x40],xmm0
    movsd  xmm0,QWORD PTR [r8+0x10]
    movsd  QWORD PTR [rsp+0x38],xmm0
    movsd  xmm0,QWORD PTR [r8+0x18]
    movsd  QWORD PTR [rsp+0x30],xmm0
    xor    edi,edi
    movapd xmm14,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movsd  xmm13,QWORD PTR [rsp+0x60]
    movsd  xmm15,QWORD PTR [rsp+0x58]
    movsd  xmm12,QWORD PTR [rsp+0x70]
    movsd  xmm10,QWORD PTR [rsp+0x50]
    movsd  xmm11,QWORD PTR [rsp+0x68]
    xchg   ax,ax
at_1_01d0:
    xorps  xmm9,xmm9
    cvtsi2sd xmm9,rdi
    divsd  xmm9,QWORD PTR [rip + ref_50_real_4024000000000000]
    movsd  xmm0,QWORD PTR [rsp+0x78]
    mulsd  xmm0,xmm9
    xorpd  xmm0,xmm14
    call   ref_73_exp
    movapd xmm8,xmm0
    movapd xmm0,xmm9
    subsd  xmm0,xmm13
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rsp+0x28]
    xorpd  xmm0,xmm14
    call   ref_73_exp
    movapd xmm6,xmm0
    movapd xmm0,xmm9
    subsd  xmm0,xmm15
    mulsd  xmm0,xmm0
    mulsd  xmm0,xmm12
    xorpd  xmm0,xmm14
    call   ref_73_exp
    movapd xmm7,xmm0
    movapd xmm0,xmm9
    subsd  xmm0,xmm10
    mulsd  xmm0,xmm0
    mulsd  xmm0,xmm11
    xorpd  xmm0,xmm14
    call   ref_73_exp
    movapd xmm1,xmm8
    xorpd  xmm1,xmm14
    lea    rax,[rsi+rdi*8]
    movlpd QWORD PTR [rsi+rdi*8],xmm1
    movapd xmm1,xmm6
    xorpd  xmm1,xmm14
    movlpd QWORD PTR [r14+rax*1],xmm1
    add    rax,r14
    movapd xmm1,xmm7
    xorpd  xmm1,xmm14
    movlpd QWORD PTR [r14+rax*1],xmm1
    add    rax,r14
    movsd  xmm2,QWORD PTR [rsp+0x30]
    movapd xmm1,xmm2
    mulsd  xmm1,xmm0
    mulsd  xmm2,xmm11
    mulsd  xmm2,xmm0
    xorpd  xmm0,xmm14
    movlpd QWORD PTR [r14+rax*1],xmm0
    add    rax,r14
    mulsd  xmm8,QWORD PTR [rsp+0x48]
    mulsd  xmm8,xmm9
    movsd  QWORD PTR [r14+rax*1],xmm8
    add    rax,r14
    movapd xmm0,xmm9
    subsd  xmm0,xmm13
    mulsd  xmm0,xmm0
    movsd  xmm4,QWORD PTR [rsp+0x40]
    movapd xmm3,xmm4
    mulsd  xmm3,xmm6
    mulsd  xmm3,xmm0
    movsd  QWORD PTR [r14+rax*1],xmm3
    movapd xmm0,xmm9
    subsd  xmm0,xmm15
    mulsd  xmm0,xmm0
    movsd  xmm5,QWORD PTR [rsp+0x38]
    movapd xmm3,xmm5
    mulsd  xmm3,xmm7
    mulsd  xmm3,xmm0
    add    rax,r14
    movsd  QWORD PTR [r14+rax*1],xmm3
    movapd xmm0,xmm9
    subsd  xmm0,xmm10
    mulsd  xmm0,xmm0
    mulsd  xmm1,xmm0
    add    rax,r14
    movsd  QWORD PTR [r14+rax*1],xmm1
    movapd xmm0,xmm4
    mulsd  xmm0,QWORD PTR [rsp+0x28]
    mulsd  xmm0,xmm6
    movapd xmm1,xmm9
    subsd  xmm1,xmm13
    movsd  xmm3,QWORD PTR [rip + ref_11_real_4000000000000000]
    mulsd  xmm1,xmm3
    mulsd  xmm0,xmm1
    add    rax,r14
    xorpd  xmm0,xmm14
    movlpd QWORD PTR [r14+rax*1],xmm0
    movapd xmm0,xmm5
    mulsd  xmm0,xmm12
    mulsd  xmm0,xmm7
    movapd xmm1,xmm9
    subsd  xmm1,xmm15
    mulsd  xmm1,xmm3
    mulsd  xmm0,xmm1
    add    rax,r14
    xorpd  xmm0,xmm14
    movlpd QWORD PTR [r14+rax*1],xmm0
    subsd  xmm9,xmm10
    mulsd  xmm9,xmm3
    mulsd  xmm2,xmm9
    add    rax,r14
    xorpd  xmm2,xmm14
    movlpd QWORD PTR [r14+rax*1],xmm2
    inc    rdi
    cmp    rdi,0x41
    {disp32} jne    at_1_01d0
    {disp32} jmp    at_1_15f5
at_1_03c9:
    mov    rax,QWORD PTR [rdx]
    test   rax,rax
    {disp32} jle    at_1_15f5
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    edx,0x1
    movabs rcx,0x3ff0000000000000
    movabs r9,0x4000000000000000
    mov    r10,rsi
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0400:
    mulsd  xmm0,QWORD PTR [r8+rdx*8-0x8]
    lea    r11,[rdx-0x1]
    imul   r11,r14
    add    r11,rsi
    xor    edi,edi
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0420:
    mov    QWORD PTR [r10+rdi*8],rcx
    inc    rdi
    cmp    rax,rdi
    jne    at_1_0420
    mov    QWORD PTR [r11+rdx*8-0x8],r9
    lea    r11,[rdx+0x1]
    add    r10,r14
    cmp    rdx,rax
    mov    rdx,r11
    jne    at_1_0400
    mov    edx,0x1
    xor    ecx,ecx
    xorpd  xmm1,xmm1
    movsd  xmm2,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    jmp    at_1_0491
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0460:
    movapd xmm3,xmm2
at_1_0464:
    lea    r9,[rdx-0x1]
    movapd xmm4,xmm0
    divsd  xmm4,xmm3
    imul   r9,r14
    add    r9,rsi
    movsd  QWORD PTR [r9+rax*8-0x8],xmm4
    lea    r9,[rdx+0x1]
    inc    rcx
    cmp    rdx,rax
    mov    rdx,r9
    {disp32} je     at_1_15f5
at_1_0491:
    movsd  xmm3,QWORD PTR [r8+rdx*8-0x8]
    ucomisd xmm1,xmm3
    setp   r9b
    setne  r10b
    or     r10b,r9b
    jne    at_1_0464
    xor    r9d,r9d
    movapd xmm0,xmm2
    jmp    at_1_04c8
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_04c0:
    inc    r9
    cmp    rax,r9
    je     at_1_0460
at_1_04c8:
    cmp    rcx,r9
    je     at_1_04c0
    mulsd  xmm0,QWORD PTR [r8+r9*8]
    jmp    at_1_04c0
at_1_04d5:
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    {disp32} jle    at_1_15f5
    movsd  xmm6,QWORD PTR [r8]
    movsd  xmm7,QWORD PTR [r8+0x8]
    add    r14,rsi
    neg    rdi
    mov    ebx,0x1
    movapd xmm8,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
at_1_0500:
    xorps  xmm9,xmm9
    cvtsi2sd xmm9,rbx
    movapd xmm0,xmm9
    mulsd  xmm0,xmm6
    call   ref_73_exp
    mulsd  xmm0,xmm9
    xorpd  xmm0,xmm8
    movlpd QWORD PTR [rsi+rbx*8-0x8],xmm0
    movapd xmm0,xmm9
    mulsd  xmm0,xmm7
    call   ref_73_exp
    mulsd  xmm0,xmm9
    xorpd  xmm0,xmm8
    movlpd QWORD PTR [r14+rbx*8-0x8],xmm0
    lea    rax,[rdi+rbx*1]
    inc    rax
    inc    rbx
    cmp    rax,0x1
    jne    at_1_0500
    {disp32} jmp    at_1_15f5
at_1_055b:
    mov    eax,0x1
    mov    rcx,rsi
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0570:
    xor    edx,edx
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0580:
    mov    QWORD PTR [rcx+rdx*8],0x0
    inc    rdx
    cmp    rdx,0x4
    jne    at_1_0580
    inc    rax
    add    rcx,r14
    cmp    rax,0x5
    jne    at_1_0570
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rsi],rax
    movabs rax,0x4024000000000000
    mov    QWORD PTR [rsi+rdi*8],rax
    movsd  xmm0,QWORD PTR [rip + ref_26_real_4014000000000000]
    sqrtsd xmm0,xmm0
    mov    rax,rdi
    shl    rax,0x4
    movsd  QWORD PTR [rsi+rax*1+0x8],xmm0
    movapd xmm1,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    xorpd  xmm0,xmm1
    lea    rcx,[rdi+rdi*2]
    movlpd QWORD PTR [rsi+rcx*8+0x8],xmm0
    movsd  xmm0,QWORD PTR [r8+0x8]
    movsd  xmm2,QWORD PTR [rip + ref_11_real_4000000000000000]
    movsd  xmm3,QWORD PTR [r8+0x10]
    mulsd  xmm3,xmm2
    subsd  xmm0,xmm3
    mulsd  xmm0,xmm2
    movsd  QWORD PTR [rsi+rdi*8+0x10],xmm0
    mulsd  xmm0,xmm2
    xorpd  xmm0,xmm1
    movlpd QWORD PTR [rsi+rax*1+0x10],xmm0
    movsd  xmm0,QWORD PTR [rip + ref_50_real_4024000000000000]
    sqrtsd xmm0,xmm0
    movsd  xmm3,QWORD PTR [r8]
    subsd  xmm3,QWORD PTR [r8+0x18]
    mulsd  xmm3,xmm2
    mulsd  xmm3,xmm0
    movsd  QWORD PTR [rsi+0x18],xmm3
    xorpd  xmm3,xmm1
    movlpd QWORD PTR [rsi+rcx*8+0x18],xmm3
    {disp32} jmp    at_1_15f5
at_1_064e:
    mov    rbx,QWORD PTR [rcx]
    test   rbx,rbx
    {disp32} jle    at_1_15f5
    movsd  xmm8,QWORD PTR [r8]
    movsd  xmm9,QWORD PTR [r8+0x8]
    movsd  xmm10,QWORD PTR [r8+0x10]
    movsd  xmm11,QWORD PTR [r8+0x18]
    shl    rdi,0x4
    lea    r15,[r14+r14*2]
    mov    r12d,0x1
    movsd  xmm12,QWORD PTR [rip + ref_26_real_4014000000000000]
    movsd  xmm13,QWORD PTR [rip + ref_11_real_4000000000000000]
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_06a0:
    xorps  xmm6,xmm6
    cvtsi2sd xmm6,r12
    divsd  xmm6,xmm12
    movapd xmm0,xmm6
    call   ref_74_sin
    movapd xmm7,xmm0
    movapd xmm14,xmm6
    mulsd  xmm14,xmm9
    addsd  xmm14,xmm8
    movapd xmm0,xmm6
    call   ref_73_exp
    subsd  xmm14,xmm0
    movapd xmm15,xmm7
    mulsd  xmm15,xmm11
    addsd  xmm15,xmm10
    movapd xmm0,xmm6
    call   ref_75_cos
    subsd  xmm15,xmm0
    mulsd  xmm14,xmm13
    movsd  QWORD PTR [rsi],xmm14
    mulsd  xmm14,xmm6
    movsd  QWORD PTR [rsi+r14*1],xmm14
    mulsd  xmm15,xmm13
    movsd  QWORD PTR [rsi+rdi*1],xmm15
    mulsd  xmm15,xmm7
    movsd  QWORD PTR [rsi+r15*1],xmm15
    inc    r12
    add    rsi,0x8
    dec    rbx
    {disp32} jne    at_1_06a0
    {disp32} jmp    at_1_15f5
at_1_0734:
    mov    rax,QWORD PTR [rdx]
    mov    ecx,0x1
    movsd  xmm1,QWORD PTR [rip + ref_53_real_403d000000000000]
    movsd  xmm0,QWORD PTR [rip + ref_11_real_4000000000000000]
    xorpd  xmm2,xmm2
    movsd  xmm3,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    rdx,rsi
    jmp    at_1_0785
    nop    DWORD PTR [rax]
at_1_0760:
    movapd xmm5,xmm4
    mulsd  xmm5,xmm0
    mulsd  xmm5,xmm2
    movapd xmm5,xmm3
    divsd  xmm5,xmm4
at_1_0774:
    inc    rcx
    add    rdx,0x8
    cmp    rcx,0x1e
    {disp32} je     at_1_0819
at_1_0785:
    xorps  xmm4,xmm4
    cvtsi2sd xmm4,rcx
    divsd  xmm4,xmm1
    test   rax,rax
    jle    at_1_0760
    xorpd  xmm6,xmm6
    xor    r9d,r9d
    movapd xmm5,xmm3
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07b0:
    movsd  xmm7,QWORD PTR [r8+r9*8]
    mulsd  xmm7,xmm5
    addsd  xmm6,xmm7
    mulsd  xmm5,xmm4
    inc    r9
    cmp    rax,r9
    jne    at_1_07b0
    movapd xmm5,xmm4
    mulsd  xmm5,xmm0
    mulsd  xmm5,xmm6
    movapd xmm6,xmm3
    divsd  xmm6,xmm4
    mov    r9,rdx
    xor    r10d,r10d
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07f0:
    xorps  xmm7,xmm7
    cvtsi2sd xmm7,r10
    subsd  xmm7,xmm5
    mulsd  xmm7,xmm6
    movsd  QWORD PTR [r9],xmm7
    mulsd  xmm6,xmm4
    inc    r10
    add    r9,r14
    cmp    rax,r10
    jne    at_1_07f0
    {disp32} jmp    at_1_0774
at_1_0819:
    test   rax,rax
    jle    at_1_0860
    lea    rcx,[rsi+0xe8]
    mov    edx,0x1
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0830:
    xor    r9d,r9d
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0840:
    mov    QWORD PTR [rcx+r9*8],0x0
    inc    r9
    cmp    r9,0x2
    jne    at_1_0840
    lea    r9,[rdx+0x1]
    add    rcx,r14
    cmp    rdx,rax
    mov    rdx,r9
    jne    at_1_0830
at_1_0860:
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rsi+0xe8],rax
    mulsd  xmm0,QWORD PTR [r8]
    xorpd  xmm0,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movlpd QWORD PTR [rsi+0xf0],xmm0
    mov    QWORD PTR [rsi+r14*1+0xf0],rax
    {disp32} jmp    at_1_15f5
at_1_0893:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm6,QWORD PTR [r8+0x8]
    movsd  xmm1,QWORD PTR [rip + ref_11_real_4000000000000000]
    movapd xmm2,xmm1
    mulsd  xmm2,xmm0
    addsd  xmm2,xmm6
    movsd  QWORD PTR [rsi],xmm2
    mulsd  xmm1,xmm6
    addsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+r14*1],xmm1
    call   ref_75_cos
    movsd  QWORD PTR [rsi+0x8],xmm0
    mov    QWORD PTR [rsi+r14*1+0x8],0x0
    mov    QWORD PTR [rsi+0x10],0x0
    movapd xmm0,xmm6
    call   ref_74_sin
    xorpd  xmm0,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movlpd QWORD PTR [rsi+r14*1+0x10],xmm0
    {disp32} jmp    at_1_15f5
at_1_08fc:
    mov    rcx,QWORD PTR [rcx]
    mov    rax,QWORD PTR [rdx]
    cmp    rcx,0x2
    {disp32} jge    at_1_1550
at_1_090c:
    movabs rdx,0x3ff0000000000000
    mov    QWORD PTR [rsi+rcx*8-0x8],rdx
    cmp    rax,0x2
    {disp32} jl     at_1_15f5
    dec    rax
    lea    rcx,[r14+rcx*8]
    add    rcx,rsi
    add    rcx,0xfffffffffffffff8
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0940:
    mov    QWORD PTR [rcx],0x0
    add    rcx,r14
    dec    rax
    jne    at_1_0940
    {disp32} jmp    at_1_15f5
at_1_0954:
    movsd  xmm0,QWORD PTR [rip + ref_32_real_4034000000000000]
    mulsd  xmm0,QWORD PTR [r8]
    xorpd  xmm0,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movlpd QWORD PTR [rsi],xmm0
    movabs rax,0x4024000000000000
    mov    QWORD PTR [rsi+r14*1],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rsi+0x8],rax
    mov    QWORD PTR [rsi+r14*1+0x8],0x0
    {disp32} jmp    at_1_15f5
at_1_0997:
    movsd  xmm7,QWORD PTR [r8+0x18]
    movsd  xmm8,QWORD PTR [r8+0x20]
    movsd  xmm9,QWORD PTR [r8+0x8]
    movsd  xmm10,QWORD PTR [r8+0x10]
    xor    edi,edi
    movsd  xmm11,QWORD PTR [rip + ref_50_real_4024000000000000]
    movapd xmm12,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movabs rbx,0xbff0000000000000
    nop    DWORD PTR [rax]
at_1_09d0:
    xorps  xmm13,xmm13
    cvtsi2sd xmm13,rdi
    mulsd  xmm13,xmm11
    movapd xmm0,xmm7
    mulsd  xmm0,xmm13
    xorpd  xmm0,xmm12
    call   ref_73_exp
    movapd xmm6,xmm0
    movapd xmm0,xmm8
    mulsd  xmm0,xmm13
    xorpd  xmm0,xmm12
    call   ref_73_exp
    lea    rax,[rsi+rdi*8]
    mov    QWORD PTR [rsi+rdi*8],rbx
    movapd xmm1,xmm6
    xorpd  xmm1,xmm12
    movlpd QWORD PTR [r14+rax*1],xmm1
    add    rax,r14
    mulsd  xmm6,xmm9
    mulsd  xmm6,xmm13
    mulsd  xmm13,xmm10
    mulsd  xmm13,xmm0
    xorpd  xmm0,xmm12
    movlpd QWORD PTR [r14+rax*1],xmm0
    add    rax,r14
    movsd  QWORD PTR [r14+rax*1],xmm6
    add    rax,r14
    movsd  QWORD PTR [r14+rax*1],xmm13
    inc    rdi
    cmp    rdi,0x21
    {disp32} jne    at_1_09d0
    {disp32} jmp    at_1_15f5
at_1_0a66:
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    rbx,r8
    call   ref_76_atan
    movsd  xmm1,QWORD PTR [rbx]
    movsd  xmm3,QWORD PTR [rbx+0x8]
    movapd xmm2,xmm1
    mulsd  xmm2,xmm1
    movsd  xmm4,QWORD PTR [rip + ref_47_real_4059000000000000]
    movapd xmm5,xmm4
    mulsd  xmm5,xmm3
    mulsd  xmm4,xmm1
    movsd  xmm6,QWORD PTR [rip + ref_50_real_4024000000000000]
    mulsd  xmm1,xmm6
    mulsd  xmm6,xmm3
    mulsd  xmm3,xmm3
    addsd  xmm3,xmm2
    mulsd  xmm0,QWORD PTR [rip + ref_62_real_4020000000000000]
    mulsd  xmm0,xmm3
    xorps  xmm2,xmm2
    sqrtsd xmm2,xmm3
    divsd  xmm5,xmm0
    movsd  QWORD PTR [rsi],xmm5
    divsd  xmm4,xmm0
    xorpd  xmm4,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movlpd QWORD PTR [rsi+rdi*8],xmm4
    mov    rax,rdi
    shl    rax,0x4
    movabs rcx,0x4024000000000000
    mov    QWORD PTR [rsi+rax*1],rcx
    divsd  xmm1,xmm2
    movsd  QWORD PTR [rsi+0x8],xmm1
    divsd  xmm6,xmm2
    movsd  QWORD PTR [rsi+rdi*8+0x8],xmm6
    mov    QWORD PTR [rsi+rax*1+0x8],0x0
    mov    QWORD PTR [rsi+0x10],0x0
    mov    QWORD PTR [rsi+rdi*8+0x10],0x0
    movabs rcx,0x3ff0000000000000
    mov    QWORD PTR [rsi+rax*1+0x10],rcx
    {disp32} jmp    at_1_15f5
at_1_0b35:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm1,QWORD PTR [r8+0x8]
    movsd  xmm2,QWORD PTR [r8+0x10]
    movsd  xmm3,QWORD PTR [r8+0x18]
    add    r14,rsi
    lea    rax,[rdi+rdi*2]
    shl    rdi,0x4
    add    rdi,rsi
    lea    rax,[rsi+rax*8]
    xor    ecx,ecx
    lea    rdx,[rip + ref_77_SSQJAC_V]
    movapd xmm4,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    nop
at_1_0b70:
    movsd  xmm5,QWORD PTR [rcx+rdx*1]
    movapd xmm6,xmm5
    addsd  xmm6,xmm1
    mulsd  xmm6,xmm5
    movapd xmm7,xmm5
    addsd  xmm7,xmm2
    mulsd  xmm7,xmm5
    addsd  xmm7,xmm3
    divsd  xmm6,xmm7
    xorpd  xmm6,xmm4
    movlpd QWORD PTR [rsi+rcx*1],xmm6
    movapd xmm8,xmm5
    mulsd  xmm8,xmm0
    divsd  xmm8,xmm7
    xorpd  xmm8,xmm4
    movlpd QWORD PTR [r14+rcx*1],xmm8
    mulsd  xmm8,xmm6
    movsd  QWORD PTR [rdi+rcx*1],xmm8
    divsd  xmm8,xmm5
    movsd  QWORD PTR [rax+rcx*1],xmm8
    add    rcx,0x8
    cmp    rcx,0x58
    jne    at_1_0b70
    {disp32} jmp    at_1_15f5
at_1_0bdd:
    mov    r15,QWORD PTR [rdx]
    test   r15,r15
    {disp32} jle    at_1_15f5
    mov    r12,QWORD PTR [rcx]
    test   r12,r12
    {disp32} jle    at_1_15ef
    cmp    r12,0xd
    {disp32} jb     at_1_15b3
    lea    rdi,[r12*8+0x0]
    mov    rbx,rsi
    mov    r13,r15
    nop    DWORD PTR [rax]
at_1_0c10:
    mov    rcx,rbx
    xor    edx,edx
    mov    r8,rdi
    call   ref_78_intel_fast_memset
    add    rbx,r14
    dec    r13
    jne    at_1_0c10
    {disp32} jmp    at_1_15ef
at_1_0c2a:
    movsd  xmm1,QWORD PTR [r8]
    movsd  xmm0,QWORD PTR [r8+0x8]
    movapd xmm2,xmm1
    mulsd  xmm2,xmm1
    movapd xmm3,xmm0
    mulsd  xmm3,xmm0
    addsd  xmm3,xmm2
    movsd  xmm2,QWORD PTR [rip + ref_44_real_401921fb54442d18]
    mulsd  xmm2,xmm3
    movsd  xmm4,QWORD PTR [rip + ref_47_real_4059000000000000]
    divsd  xmm4,xmm2
    movapd xmm2,xmm4
    mulsd  xmm2,xmm0
    movsd  QWORD PTR [rsi],xmm2
    xorps  xmm2,xmm2
    sqrtsd xmm2,xmm3
    movsd  xmm3,QWORD PTR [rip + ref_50_real_4024000000000000]
    divsd  xmm3,xmm2
    mulsd  xmm4,xmm1
    mulsd  xmm1,xmm3
    movsd  QWORD PTR [rsi+0x8],xmm1
    mov    QWORD PTR [rsi+0x10],0x0
    xorpd  xmm4,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movlpd QWORD PTR [rsi+rdi*8],xmm4
    mulsd  xmm3,xmm0
    movsd  QWORD PTR [rsi+rdi*8+0x8],xmm3
    mov    QWORD PTR [rsi+rdi*8+0x10],0x0
    shl    rdi,0x4
    movabs rax,0x4024000000000000
    mov    QWORD PTR [rsi+rdi*1],rax
    mov    QWORD PTR [rsi+rdi*1+0x8],0x0
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rsi+rdi*1+0x10],rax
    {disp32} jmp    at_1_15f5
at_1_0ce4:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm3,QWORD PTR [rip + ref_11_real_4000000000000000]
    movapd xmm4,xmm3
    movsd  xmm1,QWORD PTR [r8+0x10]
    movapd xmm5,xmm3
    mulsd  xmm5,xmm1
    movapd xmm6,xmm1
    subsd  xmm6,xmm3
    mulsd  xmm6,xmm3
    movsd  xmm2,QWORD PTR [rip + ref_26_real_4014000000000000]
    mulsd  xmm1,xmm2
    subsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mulsd  xmm1,xmm3
    mulsd  xmm3,xmm0
    movsd  QWORD PTR [rsi],xmm3
    movsd  xmm3,QWORD PTR [r8+0x8]
    mulsd  xmm4,xmm3
    movsd  QWORD PTR [rsi+rdi*8],xmm4
    mov    rax,rdi
    shl    rax,0x4
    movsd  QWORD PTR [rsi+rax*1],xmm5
    movsd  xmm4,QWORD PTR [rsi]
    movsd  QWORD PTR [rsi+0x8],xmm4
    movsd  xmm4,QWORD PTR [rsi+rdi*8]
    movsd  QWORD PTR [rsi+rdi*8+0x8],xmm4
    movsd  QWORD PTR [rsi+rax*1+0x8],xmm6
    movabs rcx,0x3ff0000000000000
    mov    QWORD PTR [rsi+0x10],rcx
    mov    QWORD PTR [rsi+rdi*8+0x10],rcx
    mov    QWORD PTR [rsi+rax*1+0x10],rcx
    mov    QWORD PTR [rsi+0x18],rcx
    mov    QWORD PTR [rsi+rdi*8+0x18],rcx
    movabs rcx,0xbff0000000000000
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_23_real_4008000000000000]
    mov    QWORD PTR [rsi+rax*1+0x18],rcx
    subsd  xmm0,xmm1
    mulsd  xmm3,QWORD PTR [rip + ref_29_real_4018000000000000]
    movsd  QWORD PTR [rsi+0x20],xmm0
    movsd  QWORD PTR [rsi+rdi*8+0x20],xmm3
    mulsd  xmm1,xmm2
    movsd  QWORD PTR [rsi+rax*1+0x20],xmm1
    {disp32} jmp    at_1_15f5
at_1_0dca:
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rsi],rax
    movsd  xmm0,QWORD PTR [r8+0x8]
    movsd  xmm1,QWORD PTR [rip + ref_23_real_4008000000000000]
    movapd xmm2,xmm1
    mulsd  xmm2,xmm0
    movsd  xmm3,QWORD PTR [rip + ref_50_real_4024000000000000]
    subsd  xmm3,xmm2
    mulsd  xmm3,xmm0
    movsd  xmm2,QWORD PTR [rip + ref_11_real_4000000000000000]
    subsd  xmm3,xmm2
    movsd  QWORD PTR [rsi+r14*1],xmm3
    mov    QWORD PTR [rsi+0x8],rax
    mulsd  xmm1,xmm0
    addsd  xmm1,xmm2
    mulsd  xmm1,xmm0
    subsd  xmm1,QWORD PTR [rip + ref_59_real_402c000000000000]
    movsd  QWORD PTR [rsi+r14*1+0x8],xmm1
    {disp32} jmp    at_1_15f5
at_1_0e33:
    movabs rax,0x4010000000000000
    mov    QWORD PTR [rsi],rax
    mov    QWORD PTR [rsi+r14*1],rax
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm2,QWORD PTR [r8+0x8]
    movsd  xmm1,QWORD PTR [rip + ref_11_real_4000000000000000]
    movapd xmm3,xmm0
    subsd  xmm3,xmm1
    movsd  xmm4,QWORD PTR [rip + ref_23_real_4008000000000000]
    movapd xmm5,xmm2
    mulsd  xmm5,xmm2
    addsd  xmm5,xmm4
    mulsd  xmm4,xmm0
    movapd xmm6,xmm1
    mulsd  xmm6,xmm2
    subsd  xmm4,xmm6
    subsd  xmm4,xmm1
    mulsd  xmm4,xmm3
    addsd  xmm5,xmm4
    movapd xmm3,xmm1
    mulsd  xmm3,xmm0
    subsd  xmm0,xmm2
    mulsd  xmm2,xmm2
    subsd  xmm3,xmm2
    mulsd  xmm3,xmm1
    addsd  xmm3,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movsd  QWORD PTR [rsi+0x8],xmm5
    mulsd  xmm0,xmm0
    subsd  xmm3,xmm0
    movsd  QWORD PTR [rsi+r14*1+0x8],xmm3
    {disp32} jmp    at_1_15f5
at_1_0ec8:
    mov    rax,QWORD PTR [rdx]
    cvtsi2sd xmm2,rax
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movapd xmm1,xmm0
    divsd  xmm1,xmm2
    test   rax,rax
    {disp32} jle    at_1_15f5
    mov    rcx,QWORD PTR [rcx]
    mov    edx,0x1
    movsd  xmm2,QWORD PTR [rip + ref_11_real_4000000000000000]
    movsd  xmm3,QWORD PTR [rip + ref_20_real_4010000000000000]
    jmp    at_1_0f23
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0f10:
    lea    r9,[rdx+0x1]
    add    rsi,r14
    cmp    rdx,rax
    mov    rdx,r9
    {disp32} je     at_1_15f5
at_1_0f23:
    movsd  xmm5,QWORD PTR [r8+rdx*8-0x8]
    mulsd  xmm5,xmm2
    subsd  xmm5,xmm0
    movapd xmm4,xmm2
    mulsd  xmm4,xmm5
    test   rcx,rcx
    jle    at_1_0f10
    xorpd  xmm6,xmm6
    xor    r9d,r9d
    movapd xmm8,xmm0
    movapd xmm7,xmm2
    nop
at_1_0f50:
    movapd xmm9,xmm1
    mulsd  xmm9,xmm7
    movsd  QWORD PTR [rsi+r9*8],xmm9
    movapd xmm9,xmm4
    mulsd  xmm9,xmm5
    subsd  xmm9,xmm8
    movapd xmm8,xmm5
    mulsd  xmm5,xmm3
    movapd xmm10,xmm4
    mulsd  xmm10,xmm7
    addsd  xmm10,xmm5
    subsd  xmm10,xmm6
    inc    r9
    movapd xmm5,xmm9
    movapd xmm6,xmm7
    movapd xmm7,xmm10
    cmp    rcx,r9
    jne    at_1_0f50
    {disp32} jmp    at_1_0f10
at_1_0fa7:
    movsd  xmm0,QWORD PTR [r8+0x8]
    movsd  xmm1,QWORD PTR [r8+0x10]
    shl    rdi,0x4
    mov    eax,0x1
    mov    ecx,0xf
    movabs rdx,0xbff0000000000000
    jmp    at_1_101a
    nop    DWORD PTR [rax]
at_1_0fd0:
    movapd xmm5,xmm0
    mulsd  xmm5,xmm3
    movapd xmm6,xmm1
    mulsd  xmm6,xmm4
    addsd  xmm6,xmm5
    mulsd  xmm6,xmm6
    mov    QWORD PTR [rsi],rdx
    mulsd  xmm3,xmm2
    divsd  xmm3,xmm6
    movsd  QWORD PTR [rsi+r14*1],xmm3
    mulsd  xmm2,xmm4
    divsd  xmm2,xmm6
    movsd  QWORD PTR [rsi+rdi*1],xmm2
    inc    rax
    add    rsi,0x8
    dec    rcx
    cmp    rax,0x10
    {disp32} je     at_1_15f5
at_1_101a:
    xorps  xmm2,xmm2
    cvtsi2sd xmm2,rax
    xorps  xmm3,xmm3
    cvtsi2sd xmm3,rcx
    movapd xmm4,xmm3
    cmp    rax,0x9
    jae    at_1_0fd0
    movapd xmm4,xmm2
    jmp    at_1_0fd0
at_1_103a:
    mov    eax,0x1
    mov    rcx,rsi
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1050:
    xor    edx,edx
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1060:
    mov    QWORD PTR [rcx+rdx*8],0x0
    inc    rdx
    cmp    rdx,0x7
    jne    at_1_1060
    inc    rax
    add    rcx,r14
    cmp    rax,0x5
    jne    at_1_1050
    movsd  xmm0,QWORD PTR [rip + ref_32_real_4034000000000000]
    mulsd  xmm0,QWORD PTR [r8]
    movapd xmm1,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    xorpd  xmm0,xmm1
    movlpd QWORD PTR [rsi],xmm0
    movabs rax,0x4024000000000000
    mov    QWORD PTR [rsi+rdi*8],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rsi+0x8],rax
    movsd  xmm0,QWORD PTR [rip + ref_35_real_4056800000000000]
    sqrtsd xmm0,xmm0
    lea    rcx,[rdi+rdi*2]
    movsd  QWORD PTR [rsi+rcx*8+0x10],xmm0
    movsd  xmm2,QWORD PTR [rip + ref_11_real_4000000000000000]
    mulsd  xmm2,QWORD PTR [r8+0x10]
    mulsd  xmm2,xmm0
    xorpd  xmm2,xmm1
    mov    rdx,rdi
    shl    rdx,0x4
    movlpd QWORD PTR [rsi+rdx*1+0x10],xmm2
    mov    QWORD PTR [rsi+rdx*1+0x18],rax
    movsd  xmm0,QWORD PTR [rip + ref_38_real_4023cccccccccccd]
    sqrtsd xmm0,xmm0
    movsd  QWORD PTR [rsi+rdi*8+0x20],xmm0
    movsd  QWORD PTR [rsi+rcx*8+0x20],xmm0
    movsd  xmm0,QWORD PTR [rip + ref_41_real_3fc999999999999a]
    sqrtsd xmm0,xmm0
    movsd  QWORD PTR [rsi+rdi*8+0x28],xmm0
    movsd  QWORD PTR [rsi+rcx*8+0x30],xmm0
    {disp32} jmp    at_1_15f5
at_1_1129:
    mov    rbx,QWORD PTR [rcx]
    test   rbx,rbx
    {disp32} jle    at_1_15f5
    movsd  xmm8,QWORD PTR [r8]
    movsd  xmm9,QWORD PTR [r8+0x8]
    add    r14,rsi
    shl    rdi,0x4
    add    rdi,rsi
    neg    rbx
    mov    r15d,0x1
    movsd  xmm10,QWORD PTR [rip + ref_50_real_4024000000000000]
    movapd xmm11,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1170:
    xorps  xmm7,xmm7
    cvtsi2sd xmm7,r15
    movapd xmm6,xmm7
    divsd  xmm6,xmm10
    movapd xmm0,xmm6
    mulsd  xmm0,xmm8
    xorpd  xmm0,xmm11
    call   ref_73_exp
    mulsd  xmm0,xmm6
    xorpd  xmm0,xmm11
    movlpd QWORD PTR [rsi+r15*8-0x8],xmm0
    movapd xmm0,xmm6
    mulsd  xmm0,xmm9
    xorpd  xmm0,xmm11
    call   ref_73_exp
    mulsd  xmm0,xmm6
    movsd  QWORD PTR [r14+r15*8-0x8],xmm0
    xorpd  xmm7,xmm11
    movapd xmm0,xmm7
    call   ref_73_exp
    movapd xmm7,xmm0
    xorpd  xmm6,xmm11
    movapd xmm0,xmm6
    call   ref_73_exp
    subsd  xmm7,xmm0
    movsd  QWORD PTR [rdi+r15*8-0x8],xmm7
    lea    rax,[rbx+r15*1]
    inc    rax
    inc    r15
    cmp    rax,0x1
    {disp32} jne    at_1_1170
    {disp32} jmp    at_1_15f5
at_1_1206:
    movsd  xmm7,QWORD PTR [r8+0x10]
    movsd  xmm8,QWORD PTR [r8]
    movsd  xmm9,QWORD PTR [r8+0x8]
    shl    rdi,0x4
    mov    ebx,0x1
    movsd  xmm10,QWORD PTR [rip + ref_26_real_4014000000000000]
    movsd  xmm11,QWORD PTR [rip + ref_56_real_4046800000000000]
    movapd xmm12,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_1240:
    xorps  xmm13,xmm13
    cvtsi2sd xmm13,rbx
    mulsd  xmm13,xmm10
    addsd  xmm13,xmm11
    addsd  xmm13,xmm7
    movapd xmm6,xmm9
    divsd  xmm6,xmm13
    movapd xmm0,xmm6
    call   ref_73_exp
    movsd  QWORD PTR [rsi],xmm0
    mulsd  xmm0,xmm8
    divsd  xmm0,xmm13
    movsd  QWORD PTR [rsi+r14*1],xmm0
    mulsd  xmm0,xmm6
    xorpd  xmm0,xmm12
    movlpd QWORD PTR [rsi+rdi*1],xmm0
    inc    rbx
    add    rsi,0x8
    cmp    rbx,0x11
    jne    at_1_1240
    {disp32} jmp    at_1_15f5
at_1_129f:
    movsd  xmm6,QWORD PTR [r8+0x8]
    movsd  xmm7,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movapd xmm0,xmm6
    subsd  xmm0,xmm7
    movsd  QWORD PTR [rsi],xmm0
    movsd  xmm8,QWORD PTR [r8]
    movsd  QWORD PTR [rsi+r14*1],xmm8
    movapd xmm0,xmm6
    mulsd  xmm0,xmm6
    subsd  xmm0,xmm7
    movsd  QWORD PTR [rsi+0x8],xmm0
    movsd  xmm0,QWORD PTR [rip + ref_11_real_4000000000000000]
    mulsd  xmm0,xmm8
    mulsd  xmm0,xmm6
    movsd  QWORD PTR [rsi+r14*1+0x8],xmm0
    mov    edx,0x3
    movapd xmm0,xmm6
    call   ref_79_powr8i8
    subsd  xmm0,xmm7
    mulsd  xmm8,QWORD PTR [rip + ref_23_real_4008000000000000]
    movsd  QWORD PTR [rsi+0x10],xmm0
    mulsd  xmm6,xmm6
    mulsd  xmm6,xmm8
    movsd  QWORD PTR [rsi+r14*1+0x10],xmm6
    {disp32} jmp    at_1_15f5
at_1_1322:
    mov    eax,0x1
    movabs rcx,0x3ff0000000000000
    mov    rdx,rsi
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1340:
    xor    r8d,r8d
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1350:
    mov    QWORD PTR [rdx+r8*8],rcx
    inc    r8
    cmp    r8,0x3
    jne    at_1_1350
    inc    rax
    add    rdx,r14
    cmp    rax,0x4
    jne    at_1_1340
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rsi+rdi*8],rax
    mov    QWORD PTR [rsi+0x8],rax
    shl    rdi,0x4
    mov    QWORD PTR [rsi+rdi*1+0x10],rax
    {disp32} jmp    at_1_15f5
at_1_1389:
    mov    eax,0x1
    mov    rcx,rsi
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_13a0:
    mov    edx,0x4
    mov    r9,rcx
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_13b0:
    mov    QWORD PTR [r9],0x0
    add    r9,r14
    dec    rdx
    jne    at_1_13b0
    inc    rax
    add    rcx,0x8
    cmp    rax,0x6
    jne    at_1_13a0
    movsd  xmm6,QWORD PTR [r8]
    movsd  xmm8,QWORD PTR [r8+0x8]
    movapd xmm0,xmm6
    mov    rbx,r8
    call   ref_73_exp
    movapd xmm1,xmm0
    subsd  xmm1,xmm8
    movsd  xmm10,QWORD PTR [rip + ref_11_real_4000000000000000]
    mulsd  xmm1,xmm10
    movapd xmm9,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    xorpd  xmm1,xmm9
    movlpd QWORD PTR [rsi+rdi*8],xmm1
    mulsd  xmm1,xmm0
    xorpd  xmm1,xmm9
    movsd  xmm7,QWORD PTR [rbx+0x10]
    subsd  xmm8,xmm7
    mulsd  xmm8,xmm8
    mulsd  xmm8,QWORD PTR [rip + ref_17_real_403e000000000000]
    movlpd QWORD PTR [rsi],xmm1
    movsd  QWORD PTR [rsi+rdi*8+0x8],xmm8
    xorpd  xmm8,xmm9
    mov    r14,rdi
    shl    r14,0x4
    movlpd QWORD PTR [rsi+r14*1+0x8],xmm8
    subsd  xmm7,QWORD PTR [rbx+0x18]
    movapd xmm0,xmm7
    call   ref_74_sin
    movapd xmm8,xmm0
    mulsd  xmm8,xmm10
    movapd xmm0,xmm7
    call   ref_75_cos
    mov    edx,0x3
    call   ref_79_powr8i8
    divsd  xmm8,xmm0
    movsd  QWORD PTR [rsi+r14*1+0x10],xmm8
    xorpd  xmm8,xmm9
    lea    rdi,[rdi+rdi*2]
    movlpd QWORD PTR [rsi+rdi*8+0x10],xmm8
    mov    edx,0x3
    movapd xmm0,xmm6
    call   ref_79_powr8i8
    mulsd  xmm0,QWORD PTR [rip + ref_20_real_4010000000000000]
    movsd  QWORD PTR [rsi+0x18],xmm0
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rsi+rdi*8+0x20],rax
    {disp32} jmp    at_1_15f5
at_1_14c2:
    mov    rax,QWORD PTR [rcx]
    cvtsi2sd xmm1,rax
    movsd  xmm0,QWORD PTR [rip + ref_11_real_4000000000000000]
    divsd  xmm0,xmm1
    mov    rcx,QWORD PTR [rdx]
    test   rcx,rcx
    {disp32} jle    at_1_15f5
    xorpd  xmm0,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    mov    edx,0x1
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    r8,rsi
    jmp    at_1_1530
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_1500:
    lea    r9,[rdx-0x1]
    imul   r9,r14
    add    r9,rsi
    movsd  xmm2,QWORD PTR [r9+rdx*8-0x8]
    addsd  xmm2,xmm1
    movsd  QWORD PTR [r9+rdx*8-0x8],xmm2
    lea    r9,[rdx+0x1]
    add    r8,r14
    cmp    rdx,rcx
    mov    rdx,r9
    {disp32} je     at_1_15f5
at_1_1530:
    test   rax,rax
    jle    at_1_1500
    xor    r9d,r9d
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_1540:
    movsd  QWORD PTR [r8+r9*8],xmm0
    inc    r9
    cmp    rax,r9
    jne    at_1_1540
    jmp    at_1_1500
at_1_1550:
    mov    edx,0x1
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    r8,rsi
    jmp    at_1_1580
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1570:
    inc    rdx
    add    r8,0x8
    cmp    rdx,rcx
    {disp32} je     at_1_090c
at_1_1580:
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,rdx
    test   rax,rax
    jle    at_1_1570
    mov    r9,r8
    mov    r10,rax
    movapd xmm2,xmm0
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_15a0:
    movsd  QWORD PTR [r9],xmm2
    mulsd  xmm2,xmm1
    add    r9,r14
    dec    r10
    jne    at_1_15a0
    jmp    at_1_1570
at_1_15b3:
    lea    rax,[r15-0x1]
    xor    edx,edx
    mov    rcx,rsi
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_15c0:
    xor    r8d,r8d
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_15d0:
    mov    QWORD PTR [rcx+r8*8],0x0
    inc    r8
    cmp    r12,r8
    jne    at_1_15d0
    lea    r8,[rdx+0x1]
    add    rcx,r14
    cmp    rdx,rax
    mov    rdx,r8
    jne    at_1_15c0
at_1_15ef:
    cmp    r15,0x3
    jge    at_1_1660
at_1_15f5:
    movaps xmm6,XMMWORD PTR [rsp+0x80]
    movaps xmm7,XMMWORD PTR [rsp+0x90]
    movaps xmm8,XMMWORD PTR [rsp+0xa0]
    movaps xmm9,XMMWORD PTR [rsp+0xb0]
    movaps xmm10,XMMWORD PTR [rsp+0xc0]
    movaps xmm11,XMMWORD PTR [rsp+0xd0]
    movaps xmm12,XMMWORD PTR [rsp+0xe0]
    movaps xmm13,XMMWORD PTR [rsp+0xf0]
    movaps xmm14,XMMWORD PTR [rsp+0x100]
    movaps xmm15,XMMWORD PTR [rsp+0x110]
    add    rsp,0x120
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_1660:
    add    rsi,r14
    mov    eax,0x2
    mov    ecx,0x2
    sub    rcx,r12
    jmp    at_1_168f
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1680:
    inc    rax
    add    rsi,r14
    cmp    rax,r15
    {disp32} je     at_1_15f5
at_1_168f:
    cmp    r12,0x3
    jl     at_1_1680
    mov    edx,0x1
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_16a0:
    xorps  xmm0,xmm0
    cvtsi2sd xmm0,rdx
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,rax
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+rdx*8],xmm1
    lea    r8,[rcx+rdx*1]
    inc    r8
    inc    rdx
    cmp    r8,0x1
    jne    at_1_16a0
    jmp    at_1_1680
at_1_16cb:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_4000000000000000:
at_5_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_xmm_80000000000000008000000000000000:
at_6_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_6_0010:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_real_403e000000000000:
at_7_0000:
    .quad 0x403e000000000000    # binary64 30.0
at_7_0008:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_4010000000000000:
at_8_0000:
    .quad 0x4010000000000000    # binary64 4.0
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_4008000000000000:
at_9_0000:
    .quad 0x4008000000000000    # binary64 3.0
at_9_0008:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_24_rdata:
def_26_real_4014000000000000:
at_10_0000:
    .quad 0x4014000000000000    # binary64 5.0
at_10_0008:
end_s10:

# .rdata  (COFF section 11)
.section .s11,"dr"
def_27_rdata:
def_29_real_4018000000000000:
at_11_0000:
    .quad 0x4018000000000000    # binary64 6.0
at_11_0008:
end_s11:

# .rdata  (COFF section 12)
.section .s12,"dr"
def_30_rdata:
def_32_real_4034000000000000:
at_12_0000:
    .quad 0x4034000000000000    # binary64 20.0
at_12_0008:
end_s12:

# .rdata  (COFF section 13)
.section .s13,"dr"
def_33_rdata:
def_35_real_4056800000000000:
at_13_0000:
    .quad 0x4056800000000000    # binary64 90.0
at_13_0008:
end_s13:

# .rdata  (COFF section 14)
.section .s14,"dr"
def_36_rdata:
def_38_real_4023cccccccccccd:
at_14_0000:
    .quad 0x4023cccccccccccd    # binary64 9.9
at_14_0008:
end_s14:

# .rdata  (COFF section 15)
.section .s15,"dr"
def_39_rdata:
def_41_real_3fc999999999999a:
at_15_0000:
    .quad 0x3fc999999999999a    # binary64 0.2
at_15_0008:
end_s15:

# .rdata  (COFF section 16)
.section .s16,"dr"
def_42_rdata:
def_44_real_401921fb54442d18:
at_16_0000:
    .quad 0x401921fb54442d18    # binary64 6.283185307179586
at_16_0008:
end_s16:

# .rdata  (COFF section 17)
.section .s17,"dr"
def_45_rdata:
def_47_real_4059000000000000:
at_17_0000:
    .quad 0x4059000000000000    # binary64 100.0
at_17_0008:
end_s17:

# .rdata  (COFF section 18)
.section .s18,"dr"
def_48_rdata:
def_50_real_4024000000000000:
at_18_0000:
    .quad 0x4024000000000000    # binary64 10.0
at_18_0008:
end_s18:

# .rdata  (COFF section 19)
.section .s19,"dr"
def_51_rdata:
def_53_real_403d000000000000:
at_19_0000:
    .quad 0x403d000000000000    # binary64 29.0
at_19_0008:
end_s19:

# .rdata  (COFF section 20)
.section .s20,"dr"
def_54_rdata:
def_56_real_4046800000000000:
at_20_0000:
    .quad 0x4046800000000000    # binary64 45.0
at_20_0008:
end_s20:

# .rdata  (COFF section 21)
.section .s21,"dr"
def_57_rdata:
def_59_real_402c000000000000:
at_21_0000:
    .quad 0x402c000000000000    # binary64 14.0
at_21_0008:
end_s21:

# .rdata  (COFF section 22)
.section .s22,"dr"
def_60_rdata:
def_62_real_4020000000000000:
at_22_0000:
    .quad 0x4020000000000000    # binary64 8.0
at_22_0008:
end_s22:

# .rdata  (COFF section 23)
.section .s23,"dr"
def_63_rdata:
at_23_0000:
    .long ref_0_text + (at_1_00b0 - at_1_0000) + (. - at_23_0000) + 4    # problem 2 -> at_1_00b0
    .long ref_0_text + (at_1_0bdd - at_1_0000) + (. - at_23_0000) + 4    # problem 3 -> at_1_0bdd
    .long ref_0_text + (at_1_0954 - at_1_0000) + (. - at_23_0000) + 4    # problem 4 -> at_1_0954
    .long ref_0_text + (at_1_0a66 - at_1_0000) + (. - at_23_0000) + 4    # problem 5 -> at_1_0a66
    .long ref_0_text + (at_1_055b - at_1_0000) + (. - at_23_0000) + 4    # problem 6 -> at_1_055b
    .long ref_0_text + (at_1_0dca - at_1_0000) + (. - at_23_0000) + 4    # problem 7 -> at_1_0dca
    .long ref_0_text + (at_1_0fa7 - at_1_0000) + (. - at_23_0000) + 4    # problem 8 -> at_1_0fa7
    .long ref_0_text + (at_1_0b35 - at_1_0000) + (. - at_23_0000) + 4    # problem 9 -> at_1_0b35
    .long ref_0_text + (at_1_1206 - at_1_0000) + (. - at_23_0000) + 4    # problem 10 -> at_1_1206
    .long ref_0_text + (at_1_0734 - at_1_0000) + (. - at_23_0000) + 4    # problem 11 -> at_1_0734
    .long ref_0_text + (at_1_1129 - at_1_0000) + (. - at_23_0000) + 4    # problem 12 -> at_1_1129
    .long ref_0_text + (at_1_04d5 - at_1_0000) + (. - at_23_0000) + 4    # problem 13 -> at_1_04d5
    .long ref_0_text + (at_1_064e - at_1_0000) + (. - at_23_0000) + 4    # problem 14 -> at_1_064e
    .long ref_0_text + (at_1_0ec8 - at_1_0000) + (. - at_23_0000) + 4    # problem 15 -> at_1_0ec8
    .long ref_0_text + (at_1_03c9 - at_1_0000) + (. - at_23_0000) + 4    # problem 16 -> at_1_03c9
    .long ref_0_text + (at_1_0997 - at_1_0000) + (. - at_23_0000) + 4    # problem 17 -> at_1_0997
    .long ref_0_text + (at_1_011d - at_1_0000) + (. - at_23_0000) + 4    # problem 18 -> at_1_011d
    .long ref_0_text + (at_1_0c2a - at_1_0000) + (. - at_23_0000) + 4    # problem 19 -> at_1_0c2a
    .long ref_0_text + (at_1_103a - at_1_0000) + (. - at_23_0000) + 4    # problem 20 -> at_1_103a
    .long ref_0_text + (at_1_1322 - at_1_0000) + (. - at_23_0000) + 4    # problem 21 -> at_1_1322
    .long ref_0_text + (at_1_0ce4 - at_1_0000) + (. - at_23_0000) + 4    # problem 22 -> at_1_0ce4
    .long ref_0_text + (at_1_0e33 - at_1_0000) + (. - at_23_0000) + 4    # problem 23 -> at_1_0e33
    .long ref_0_text + (at_1_129f - at_1_0000) + (. - at_23_0000) + 4    # problem 24 -> at_1_129f
    .long ref_0_text + (at_1_1389 - at_1_0000) + (. - at_23_0000) + 4    # problem 25 -> at_1_1389
    .long ref_0_text + (at_1_08fc - at_1_0000) + (. - at_23_0000) + 4    # problem 26 -> at_1_08fc
    .long ref_0_text + (at_1_0893 - at_1_0000) + (. - at_23_0000) + 4    # problem 27 -> at_1_0893
    .zero 24
def_77_SSQJAC_V:
at_23_0080:
    .quad 0x4010000000000000    # binary64 4.0
    .quad 0x4000000000000000    # binary64 2.0
    .quad 0x3ff0000000000000    # binary64 1.0
    .quad 0x3fe0000000000000    # binary64 0.5
    .quad 0x3fd0000000000000    # binary64 0.25
    .quad 0x3fc5604189374bc7    # binary64 0.167
    .quad 0x3fc0000000000000    # binary64 0.125
    .quad 0x3fb999999999999a    # binary64 0.1
    .quad 0x3fb5532617c1bda5    # binary64 0.0833
    .quad 0x3fb2474538ef34d7    # binary64 0.0714
    .quad 0x3fb0000000000000    # binary64 0.0625
at_23_00d8:
end_s23:

# .xdata  (COFF section 24)
.section .s24,"dr"
def_65_xdata:
at_24_0000:
    .byte 0x01    # version 1
    .byte at_1_0074 - at_1_0000    # prologue size
    .byte 0x1d    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0074 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x08
    .byte 0x00
    .byte at_1_006b - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x09
    .byte 0x00
    .byte at_1_0062 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x0a
    .byte 0x00
    .byte at_1_0058 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x0b
    .byte 0x00
    .byte at_1_004e - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x0c
    .byte 0x00
    .byte at_1_0044 - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x0d
    .byte 0x00
    .byte at_1_003a - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x0e
    .byte 0x00
    .byte at_1_0030 - at_1_0000    # SAVE_XMM128
    .byte 0xd8
    .byte 0x0f
    .byte 0x00
    .byte at_1_0026 - at_1_0000    # SAVE_XMM128
    .byte 0xe8
    .byte 0x10
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0xf8
    .byte 0x11
    .byte 0x00
    .byte at_1_0012 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x24
    .byte 0x00
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_24_0040:
end_s24:

# .drectve  (COFF section 25)
.section .s25,"dr"
def_67_drectve:
at_25_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_25_00b9:
end_s25:

# .pdata  (COFF section 26)
.section .s26,"dr"
def_69_pdata:
at_26_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_16cb - def_0_text)    # image-relative end
    .long ref_65_xdata    # image-relative unwind info
at_26_000c:
end_s26:

# MEMBER ssqfcn.obj
# Entry points: SSQFCN
.intel_syntax noprefix
# Residual dispatch: problem codes 2..27 select the signed 32-bit offsets in the read-only table.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_93_SSQFCN:
at_1_0000:
    push   r14
at_1_0002:
    push   rsi
at_1_0003:
    push   rdi
at_1_0004:
    push   rbx
at_1_0005:
    sub    rsp,0xf8
at_1_000c:
    movapd XMMWORD PTR [rsp+0xe0],xmm15
at_1_0016:
    movapd XMMWORD PTR [rsp+0xd0],xmm14
at_1_0020:
    movapd XMMWORD PTR [rsp+0xc0],xmm13
at_1_002a:
    movapd XMMWORD PTR [rsp+0xb0],xmm12
at_1_0034:
    movapd XMMWORD PTR [rsp+0xa0],xmm11
at_1_003e:
    movapd XMMWORD PTR [rsp+0x90],xmm10
at_1_0048:
    movapd XMMWORD PTR [rsp+0x80],xmm9
at_1_0052:
    movapd XMMWORD PTR [rsp+0x70],xmm8
at_1_0059:
    movapd XMMWORD PTR [rsp+0x60],xmm7
at_1_005f:
    movapd XMMWORD PTR [rsp+0x50],xmm6
at_1_0065:
    mov    rsi,r9
    mov    rax,QWORD PTR [rsp+0x140]
    mov    eax,DWORD PTR [rax]
    add    eax,0xfffffffe
    cmp    eax,0x19
    {disp32} ja     at_1_0e1b
    lea    r9,[rip + ref_84_rdata]
    movsxd rax,DWORD PTR [r9+rax*4]
    add    rax,r9
    jmp    rax
at_1_008e:
    mov    rax,QWORD PTR [rdx]
    test   rax,rax
    {disp32} jle    at_1_1029
    neg    rax
    xorpd  xmm0,xmm0
    mov    edx,0x1
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_00b0:
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,rdx
    mulsd  xmm1,QWORD PTR [r8+rdx*8-0x8]
    addsd  xmm0,xmm1
    lea    r9,[rax+rdx*1]
    inc    r9
    inc    rdx
    cmp    r9,0x1
    jne    at_1_00b0
    {disp32} jmp    at_1_102d
at_1_00d8:
    movsd  xmm0,QWORD PTR [r8+0x20]
    movsd  QWORD PTR [rsp+0x48],xmm0
    movsd  xmm0,QWORD PTR [r8+0x28]
    movsd  QWORD PTR [rsp+0x40],xmm0
    movsd  xmm0,QWORD PTR [r8+0x40]
    movsd  QWORD PTR [rsp+0x38],xmm0
    movsd  xmm0,QWORD PTR [r8+0x30]
    movsd  QWORD PTR [rsp+0x30],xmm0
    movsd  xmm0,QWORD PTR [r8+0x48]
    movsd  QWORD PTR [rsp+0x28],xmm0
    movsd  xmm0,QWORD PTR [r8+0x38]
    movsd  QWORD PTR [rsp+0x20],xmm0
    movsd  xmm11,QWORD PTR [r8+0x50]
    movsd  xmm10,QWORD PTR [r8]
    movsd  xmm12,QWORD PTR [r8+0x8]
    movsd  xmm13,QWORD PTR [r8+0x10]
    movsd  xmm14,QWORD PTR [r8+0x18]
    lea    rdi,[rip + ref_94_SSQFCN_Y5]
    xor    ebx,ebx
    movapd xmm15,XMMWORD PTR [rip + ref_53_xmm_80000000000000008000000000000000]
    nop
at_1_0150:
    xorps  xmm6,xmm6
    cvtsi2sd xmm6,rbx
    divsd  xmm6,QWORD PTR [rip + ref_11_real_4024000000000000]
    movsd  xmm0,QWORD PTR [rsp+0x48]
    mulsd  xmm0,xmm6
    xorpd  xmm0,xmm15
    call   ref_95_exp
    movapd xmm7,xmm0
    movapd xmm0,xmm6
    subsd  xmm0,QWORD PTR [rsp+0x38]
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rsp+0x40]
    xorpd  xmm0,xmm15
    call   ref_95_exp
    movapd xmm8,xmm0
    movapd xmm0,xmm6
    subsd  xmm0,QWORD PTR [rsp+0x28]
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rsp+0x30]
    xorpd  xmm0,xmm15
    call   ref_95_exp
    movapd xmm9,xmm0
    subsd  xmm6,xmm11
    mulsd  xmm6,xmm6
    mulsd  xmm6,QWORD PTR [rsp+0x20]
    xorpd  xmm6,xmm15
    movapd xmm0,xmm6
    call   ref_95_exp
    movsd  xmm1,QWORD PTR [rdi]
    mulsd  xmm7,xmm10
    mulsd  xmm8,xmm12
    addsd  xmm8,xmm7
    mulsd  xmm9,xmm13
    mulsd  xmm0,xmm14
    addsd  xmm0,xmm9
    addsd  xmm0,xmm8
    subsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+rbx*8],xmm1
    inc    rbx
    add    rdi,0x8
    cmp    rbx,0x41
    {disp32} jne    at_1_0150
    {disp32} jmp    at_1_0fcd
at_1_0221:
    mov    rdi,QWORD PTR [rdx]
    lea    rax,[rdi+0x1]
    cvtsi2sd xmm0,rax
    test   rdi,rdi
    {disp32} jle    at_1_0fb5
    xorpd  xmm0,XMMWORD PTR [rip + ref_53_xmm_80000000000000008000000000000000]
    movsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    xor    eax,eax
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0250:
    movsd  xmm1,QWORD PTR [r8+rax*8]
    addsd  xmm0,xmm1
    mulsd  xmm6,xmm1
    inc    rax
    cmp    rdi,rax
    jne    at_1_0250
    xor    eax,eax
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0270:
    movsd  xmm1,QWORD PTR [r8+rax*8]
    addsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+rax*8],xmm1
    inc    rax
    cmp    rdi,rax
    jne    at_1_0270
    {disp32} jmp    at_1_0fbd
at_1_028c:
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    {disp32} jle    at_1_0fcd
    movsd  xmm7,QWORD PTR [r8]
    movsd  xmm8,QWORD PTR [r8+0x8]
    neg    rdi
    mov    ebx,0x1
    movsd  xmm9,QWORD PTR [rip + ref_26_real_4000000000000000]
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_02c0:
    xorps  xmm6,xmm6
    cvtsi2sd xmm6,rbx
    movapd xmm10,xmm9
    mulsd  xmm10,xmm6
    addsd  xmm10,xmm9
    movapd xmm0,xmm6
    mulsd  xmm0,xmm7
    call   ref_95_exp
    subsd  xmm10,xmm0
    mulsd  xmm6,xmm8
    movapd xmm0,xmm6
    call   ref_95_exp
    subsd  xmm10,xmm0
    movsd  QWORD PTR [rsi+rbx*8-0x8],xmm10
    lea    rax,[rdi+rbx*1]
    inc    rax
    inc    rbx
    cmp    rax,0x1
    jne    at_1_02c0
    {disp32} jmp    at_1_0fcd
at_1_0318:
    movsd  xmm6,QWORD PTR [r8]
    movsd  xmm0,QWORD PTR [r8+0x8]
    movsd  xmm1,QWORD PTR [rip + ref_11_real_4024000000000000]
    sqrtsd xmm2,xmm1
    mulsd  xmm1,xmm0
    addsd  xmm1,xmm6
    movsd  QWORD PTR [rsi],xmm1
    movsd  xmm1,QWORD PTR [rip + ref_35_real_4014000000000000]
    sqrtsd xmm1,xmm1
    movsd  xmm3,QWORD PTR [r8+0x10]
    movsd  xmm4,QWORD PTR [r8+0x18]
    movapd xmm5,xmm3
    subsd  xmm5,xmm4
    mulsd  xmm5,xmm1
    mulsd  xmm3,QWORD PTR [rip + ref_26_real_4000000000000000]
    movsd  QWORD PTR [rsi+0x8],xmm5
    subsd  xmm0,xmm3
    mulsd  xmm0,xmm0
    movsd  QWORD PTR [rsi+0x10],xmm0
    subsd  xmm6,xmm4
    mulsd  xmm6,xmm6
    mulsd  xmm6,xmm2
    mov    edi,0x3
    {disp32} jmp    at_1_0fc8
at_1_038f:
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    {disp32} jle    at_1_0fcd
    movsd  xmm8,QWORD PTR [r8]
    movsd  xmm9,QWORD PTR [r8+0x8]
    movsd  xmm10,QWORD PTR [r8+0x10]
    movsd  xmm11,QWORD PTR [r8+0x18]
    neg    rdi
    mov    ebx,0x1
    movsd  xmm12,QWORD PTR [rip + ref_35_real_4014000000000000]
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_03d0:
    xorps  xmm6,xmm6
    cvtsi2sd xmm6,rbx
    divsd  xmm6,xmm12
    movapd xmm13,xmm6
    mulsd  xmm13,xmm9
    addsd  xmm13,xmm8
    movapd xmm0,xmm6
    call   ref_95_exp
    subsd  xmm13,xmm0
    movapd xmm0,xmm6
    call   ref_96_sin
    movapd xmm7,xmm0
    mulsd  xmm7,xmm11
    addsd  xmm7,xmm10
    movapd xmm0,xmm6
    call   ref_97_cos
    subsd  xmm7,xmm0
    mulsd  xmm13,xmm13
    mulsd  xmm7,xmm7
    addsd  xmm7,xmm13
    movsd  QWORD PTR [rsi+rbx*8-0x8],xmm7
    lea    rax,[rdi+rbx*1]
    inc    rax
    inc    rbx
    cmp    rax,0x1
    jne    at_1_03d0
    {disp32} jmp    at_1_0fcd
at_1_0447:
    mov    rax,QWORD PTR [rdx]
    mov    ecx,0x1
    movsd  xmm0,QWORD PTR [rip + ref_56_real_403d000000000000]
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    jmp    at_1_048f
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0470:
    mulsd  xmm3,xmm3
    subsd  xmm2,xmm3
    subsd  xmm2,xmm1
    movsd  QWORD PTR [rsi+rcx*8-0x8],xmm2
    inc    rcx
    cmp    rcx,0x1e
    {disp32} je     at_1_051f
at_1_048f:
    xorps  xmm4,xmm4
    cvtsi2sd xmm4,rcx
    divsd  xmm4,xmm0
    xorpd  xmm3,xmm3
    xorpd  xmm2,xmm2
    cmp    rax,0x2
    jl     at_1_04e2
    mov    edx,0x1
    movapd xmm5,xmm1
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_04c0:
    xorps  xmm6,xmm6
    cvtsi2sd xmm6,rdx
    mulsd  xmm6,xmm5
    mulsd  xmm6,QWORD PTR [r8+rdx*8]
    addsd  xmm2,xmm6
    mulsd  xmm5,xmm4
    inc    rdx
    cmp    rax,rdx
    jne    at_1_04c0
at_1_04e2:
    test   rax,rax
    jle    at_1_0470
    xorpd  xmm3,xmm3
    xor    edx,edx
    movapd xmm5,xmm1
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0500:
    movsd  xmm6,QWORD PTR [r8+rdx*8]
    mulsd  xmm6,xmm5
    addsd  xmm3,xmm6
    mulsd  xmm5,xmm4
    inc    rdx
    cmp    rax,rdx
    jne    at_1_0500
    {disp32} jmp    at_1_0470
at_1_051f:
    movsd  xmm0,QWORD PTR [r8]
    movsd  QWORD PTR [rsi+0xe8],xmm0
    movsd  xmm6,QWORD PTR [r8+0x8]
    mulsd  xmm0,xmm0
    subsd  xmm6,xmm0
    subsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    edi,0x1e
    {disp32} jmp    at_1_0fc8
at_1_054c:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm6,QWORD PTR [r8+0x8]
    movapd xmm1,xmm0
    mulsd  xmm1,xmm0
    movapd xmm2,xmm6
    mulsd  xmm2,xmm6
    addsd  xmm2,xmm1
    movapd xmm1,xmm0
    mulsd  xmm1,xmm6
    addsd  xmm1,xmm2
    movsd  QWORD PTR [rsi],xmm1
    call   ref_96_sin
    movsd  QWORD PTR [rsi+0x8],xmm0
    movapd xmm0,xmm6
    call   ref_97_cos
    movapd xmm6,xmm0
    mov    edi,0x2
    movsd  QWORD PTR [rsi+rdi*8],xmm0
    {disp32} jmp    at_1_0fcd
at_1_05a1:
    mov    rdi,QWORD PTR [rcx]
    cmp    rdi,0x2
    {disp32} jge    at_1_0eb0
at_1_05ae:
    movsd  xmm6,QWORD PTR [r8]
    {disp32} jmp    at_1_0fbd
at_1_05b8:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm1,QWORD PTR [r8+0x8]
    movsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    subsd  xmm6,xmm0
    mulsd  xmm0,xmm0
    subsd  xmm1,xmm0
    mulsd  xmm1,QWORD PTR [rip + ref_11_real_4024000000000000]
    movsd  QWORD PTR [rsi],xmm1
    {disp32} jmp    at_1_09ee
at_1_05e8:
    movsd  xmm8,QWORD PTR [r8+0x18]
    movsd  xmm9,QWORD PTR [r8+0x20]
    movsd  xmm10,QWORD PTR [r8]
    movsd  xmm11,QWORD PTR [r8+0x8]
    movsd  xmm12,QWORD PTR [r8+0x10]
    lea    rdi,[rip + ref_98_SSQFCN_Y4]
    xor    ebx,ebx
    movsd  xmm13,QWORD PTR [rip + ref_11_real_4024000000000000]
    movapd xmm14,XMMWORD PTR [rip + ref_53_xmm_80000000000000008000000000000000]
at_1_0620:
    xorps  xmm6,xmm6
    cvtsi2sd xmm6,rbx
    mulsd  xmm6,xmm13
    movapd xmm0,xmm8
    mulsd  xmm0,xmm6
    xorpd  xmm0,xmm14
    call   ref_95_exp
    movapd xmm7,xmm0
    mulsd  xmm6,xmm9
    xorpd  xmm6,xmm14
    movapd xmm0,xmm6
    call   ref_95_exp
    movsd  xmm1,QWORD PTR [rdi]
    mulsd  xmm7,xmm11
    addsd  xmm7,xmm10
    mulsd  xmm0,xmm12
    addsd  xmm0,xmm7
    subsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+rbx*8],xmm1
    inc    rbx
    add    rdi,0x8
    cmp    rbx,0x21
    jne    at_1_0620
    {disp32} jmp    at_1_0fcd
at_1_0689:
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    rdi,r8
    call   ref_99_atan
    mov    rax,rdi
    movapd xmm6,xmm0
    mulsd  xmm6,QWORD PTR [rip + ref_71_real_4020000000000000]
    movsd  xmm7,QWORD PTR [rdi]
    movsd  xmm8,QWORD PTR [rdi+0x8]
    xorpd  xmm0,xmm0
    cvtss2sd xmm0,xmm0
    ucomisd xmm0,xmm8
    {disp32} ja     at_1_0f1c
    movsd  xmm0,QWORD PTR [rip + ref_77_real_3fd0000000000000]
    {disp32} jmp    at_1_0f24
at_1_06d2:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm1,QWORD PTR [r8+0x8]
    movsd  xmm2,QWORD PTR [r8+0x10]
    movsd  xmm3,QWORD PTR [r8+0x18]
    xor    eax,eax
    lea    rcx,[rip + ref_100_SSQFCN_V]
    lea    rdx,[rip + ref_101_SSQFCN_Y2]
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0700:
    movsd  xmm4,QWORD PTR [rax+rcx*1]
    movapd xmm5,xmm4
    addsd  xmm5,xmm1
    movapd xmm6,xmm4
    addsd  xmm6,xmm2
    mulsd  xmm6,xmm4
    addsd  xmm6,xmm3
    movsd  xmm7,QWORD PTR [rax+rdx*1]
    mulsd  xmm4,xmm0
    mulsd  xmm4,xmm5
    divsd  xmm4,xmm6
    subsd  xmm7,xmm4
    movsd  QWORD PTR [rsi+rax*1],xmm7
    add    rax,0x8
    cmp    rax,0x58
    jne    at_1_0700
    {disp32} jmp    at_1_0fcd
at_1_0746:
    mov    rax,QWORD PTR [rdx]
    xorpd  xmm0,xmm0
    cmp    rax,0x3
    jl     at_1_077b
    mov    edx,0x2
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0760:
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,rdx
    mulsd  xmm1,QWORD PTR [r8+rdx*8-0x8]
    addsd  xmm0,xmm1
    inc    rdx
    cmp    rax,rdx
    jne    at_1_0760
at_1_077b:
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    jle    at_1_07ad
    xor    eax,eax
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    nop    DWORD PTR [rax]
at_1_0790:
    xorps  xmm2,xmm2
    cvtsi2sd xmm2,rax
    mulsd  xmm2,xmm0
    subsd  xmm2,xmm1
    movsd  QWORD PTR [rsi+rax*8],xmm2
    inc    rax
    cmp    rdi,rax
    jne    at_1_0790
at_1_07ad:
    dec    rdi
    movsd  xmm6,QWORD PTR [rip + ref_83_real_bff0000000000000]
    {disp32} jmp    at_1_0fc8
at_1_07bd:
    movsd  xmm7,QWORD PTR [r8]
    mov    rdi,r8
    movsd  xmm8,QWORD PTR [r8+0x8]
    movapd xmm0,xmm8
    movapd xmm1,xmm7
    call   ref_102_atan2
    divsd  xmm0,QWORD PTR [rip + ref_50_real_401921fb54442d18]
    xorpd  xmm1,xmm1
    ucomisd xmm1,xmm8
    setae  al
    ucomisd xmm1,xmm7
    jb     at_1_07ff
    test   al,al
    je     at_1_07ff
    addsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
at_1_07ff:
    movsd  xmm6,QWORD PTR [rdi+0x10]
    movsd  xmm1,QWORD PTR [rip + ref_11_real_4024000000000000]
    mulsd  xmm0,xmm1
    movapd xmm2,xmm6
    subsd  xmm2,xmm0
    mulsd  xmm2,xmm1
    mulsd  xmm7,xmm7
    mulsd  xmm8,xmm8
    addsd  xmm8,xmm7
    xorps  xmm0,xmm0
    sqrtsd xmm0,xmm8
    subsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movsd  QWORD PTR [rsi],xmm2
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [rsi+0x8],xmm0
    {disp32} jmp    at_1_0fae
at_1_084c:
    movsd  xmm7,QWORD PTR [r8]
    movsd  xmm8,QWORD PTR [r8+0x8]
    movapd xmm0,xmm7
    mulsd  xmm0,xmm7
    movapd xmm1,xmm8
    mulsd  xmm1,xmm8
    addsd  xmm1,xmm0
    movsd  xmm6,QWORD PTR [r8+0x10]
    movapd xmm0,xmm6
    mulsd  xmm0,xmm6
    addsd  xmm0,xmm1
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    subsd  xmm0,xmm1
    movsd  QWORD PTR [rsi],xmm0
    movapd xmm0,xmm7
    mulsd  xmm0,xmm7
    movapd xmm2,xmm8
    mulsd  xmm2,xmm8
    addsd  xmm2,xmm0
    movapd xmm0,xmm6
    subsd  xmm0,QWORD PTR [rip + ref_26_real_4000000000000000]
    mulsd  xmm0,xmm0
    addsd  xmm0,xmm2
    subsd  xmm0,xmm1
    movsd  QWORD PTR [rsi+0x8],xmm0
    movapd xmm0,xmm7
    addsd  xmm0,xmm8
    addsd  xmm0,xmm6
    subsd  xmm0,xmm1
    movsd  QWORD PTR [rsi+0x10],xmm0
    movapd xmm0,xmm7
    addsd  xmm0,xmm8
    subsd  xmm0,xmm6
    addsd  xmm0,xmm1
    movsd  QWORD PTR [rsi+0x18],xmm0
    mov    edx,0x3
    movapd xmm0,xmm7
    call   ref_103_powr8i8
    mulsd  xmm8,xmm8
    mulsd  xmm8,QWORD PTR [rip + ref_32_real_4008000000000000]
    addsd  xmm8,xmm0
    mulsd  xmm6,QWORD PTR [rip + ref_35_real_4014000000000000]
    subsd  xmm6,xmm7
    addsd  xmm6,QWORD PTR [rip + ref_29_real_40915c0000000000]
    mulsd  xmm6,xmm6
    addsd  xmm6,xmm8
    subsd  xmm6,QWORD PTR [rip + ref_38_real_4042000000000000]
    mov    edi,0x4
    {disp32} jmp    at_1_0fc8
at_1_093e:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm1,QWORD PTR [r8+0x8]
    movsd  xmm2,QWORD PTR [rip + ref_62_real_c02a000000000000]
    addsd  xmm2,xmm0
    movsd  xmm3,QWORD PTR [rip + ref_35_real_4014000000000000]
    subsd  xmm3,xmm1
    mulsd  xmm3,xmm1
    subsd  xmm3,QWORD PTR [rip + ref_26_real_4000000000000000]
    mulsd  xmm3,xmm1
    addsd  xmm3,xmm2
    addsd  xmm0,QWORD PTR [rip + ref_65_real_c03d000000000000]
    movsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    addsd  xmm6,xmm1
    mulsd  xmm6,xmm1
    subsd  xmm6,QWORD PTR [rip + ref_68_real_402c000000000000]
    movsd  QWORD PTR [rsi],xmm3
    mulsd  xmm6,xmm1
    addsd  xmm6,xmm0
    jmp    at_1_09ee
at_1_09a3:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm6,QWORD PTR [r8+0x8]
    movapd xmm1,xmm0
    addsd  xmm1,xmm6
    mulsd  xmm1,QWORD PTR [rip + ref_23_real_4010000000000000]
    movapd xmm2,xmm0
    subsd  xmm2,xmm6
    subsd  xmm0,QWORD PTR [rip + ref_26_real_4000000000000000]
    mulsd  xmm0,xmm0
    mulsd  xmm6,xmm6
    addsd  xmm6,xmm0
    subsd  xmm6,QWORD PTR [rip + ref_29_real_40915c0000000000]
    movsd  QWORD PTR [rsi],xmm1
    mulsd  xmm6,xmm2
    addsd  xmm6,xmm1
at_1_09ee:
    mov    edi,0x1
    {disp32} jmp    at_1_0fc8
at_1_09f8:
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    {disp32} jle    at_1_1090
    cmp    rdi,0xc
    {disp32} jbe    at_1_107b
    lea    rax,[rdi*8+0x0]
    mov    rcx,rsi
    mov    rbx,rdx
    xor    edx,edx
    mov    r14,r8
    mov    r8,rax
    call   ref_104_intel_fast_memset
    mov    rdx,rbx
    mov    r8,r14
    {disp32} jmp    at_1_1090
at_1_0a34:
    movsd  xmm0,QWORD PTR [r8]
    movsd  xmm1,QWORD PTR [r8+0x8]
    movsd  xmm2,QWORD PTR [r8+0x10]
    mov    eax,0x1
    lea    rcx,[rip + ref_105_SSQFCN_Y1]
    mov    edx,0xf
    jmp    at_1_0a96
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0a60:
    movsd  xmm6,QWORD PTR [rcx]
    mulsd  xmm4,xmm1
    mulsd  xmm5,xmm2
    addsd  xmm5,xmm4
    divsd  xmm3,xmm5
    addsd  xmm3,xmm0
    subsd  xmm6,xmm3
    movsd  QWORD PTR [rsi+rax*8-0x8],xmm6
    inc    rax
    add    rcx,0x8
    dec    rdx
    cmp    rax,0x10
    {disp32} je     at_1_0fcd
at_1_0a96:
    xorps  xmm3,xmm3
    cvtsi2sd xmm3,rax
    xorps  xmm4,xmm4
    cvtsi2sd xmm4,rdx
    movapd xmm5,xmm4
    cmp    rax,0x9
    jae    at_1_0a60
    movapd xmm5,xmm3
    jmp    at_1_0a60
at_1_0ab6:
    movsd  xmm1,QWORD PTR [r8]
    movsd  xmm0,QWORD PTR [r8+0x8]
    movapd xmm2,xmm0
    movsd  xmm7,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movsd  xmm6,QWORD PTR [r8+0x18]
    movapd xmm3,xmm6
    movapd xmm4,xmm7
    movapd xmm5,xmm0
    addsd  xmm5,xmm6
    subsd  xmm0,xmm7
    subsd  xmm6,xmm7
    subsd  xmm7,xmm1
    mulsd  xmm1,xmm1
    subsd  xmm2,xmm1
    mulsd  xmm2,QWORD PTR [rip + ref_11_real_4024000000000000]
    movsd  QWORD PTR [rsi],xmm2
    movsd  QWORD PTR [rsi+0x8],xmm7
    movsd  xmm1,QWORD PTR [rip + ref_41_real_4056800000000000]
    sqrtsd xmm1,xmm1
    movsd  xmm2,QWORD PTR [r8+0x10]
    subsd  xmm4,xmm2
    mulsd  xmm2,xmm2
    subsd  xmm3,xmm2
    mulsd  xmm3,xmm1
    movsd  QWORD PTR [rsi+0x10],xmm3
    movsd  QWORD PTR [rsi+0x18],xmm4
    movsd  xmm1,QWORD PTR [rip + ref_44_real_4023cccccccccccd]
    sqrtsd xmm1,xmm1
    subsd  xmm5,QWORD PTR [rip + ref_26_real_4000000000000000]
    mulsd  xmm5,xmm1
    movsd  QWORD PTR [rsi+0x20],xmm5
    movsd  xmm1,QWORD PTR [rip + ref_47_real_3fc999999999999a]
    sqrtsd xmm1,xmm1
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [rsi+0x28],xmm0
    mulsd  xmm6,xmm1
    mov    edi,0x6
    {disp32} jmp    at_1_0fc8
at_1_0b74:
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    {disp32} jle    at_1_0fcd
    movsd  xmm9,QWORD PTR [r8]
    movsd  xmm10,QWORD PTR [r8+0x8]
    movsd  xmm11,QWORD PTR [r8+0x10]
    neg    rdi
    mov    ebx,0x1
    movsd  xmm12,QWORD PTR [rip + ref_11_real_4024000000000000]
    movapd xmm13,XMMWORD PTR [rip + ref_53_xmm_80000000000000008000000000000000]
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0bb0:
    xorps  xmm8,xmm8
    cvtsi2sd xmm8,rbx
    movapd xmm6,xmm8
    divsd  xmm6,xmm12
    movapd xmm0,xmm6
    mulsd  xmm0,xmm9
    xorpd  xmm0,xmm13
    call   ref_95_exp
    movapd xmm7,xmm0
    movapd xmm0,xmm6
    mulsd  xmm0,xmm10
    xorpd  xmm0,xmm13
    call   ref_95_exp
    subsd  xmm7,xmm0
    xorpd  xmm8,xmm13
    movapd xmm0,xmm8
    call   ref_95_exp
    movapd xmm8,xmm0
    xorpd  xmm6,xmm13
    movapd xmm0,xmm6
    call   ref_95_exp
    subsd  xmm8,xmm0
    mulsd  xmm8,xmm11
    addsd  xmm8,xmm7
    movsd  QWORD PTR [rsi+rbx*8-0x8],xmm8
    lea    rax,[rdi+rbx*1]
    inc    rax
    inc    rbx
    cmp    rax,0x1
    {disp32} jne    at_1_0bb0
    {disp32} jmp    at_1_0fcd
at_1_0c42:
    movsd  xmm6,QWORD PTR [r8+0x10]
    movsd  xmm7,QWORD PTR [r8]
    movsd  xmm8,QWORD PTR [r8+0x8]
    mov    edi,0x1
    lea    rbx,[rip + ref_106_SSQFCN_Y3]
    movsd  xmm9,QWORD PTR [rip + ref_35_real_4014000000000000]
    movsd  xmm10,QWORD PTR [rip + ref_59_real_4046800000000000]
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0c80:
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,rdi
    mulsd  xmm1,xmm9
    addsd  xmm1,xmm10
    addsd  xmm1,xmm6
    movapd xmm0,xmm8
    divsd  xmm0,xmm1
    call   ref_95_exp
    mulsd  xmm0,xmm7
    subsd  xmm0,QWORD PTR [rbx]
    movsd  QWORD PTR [rsi+rdi*8-0x8],xmm0
    inc    rdi
    add    rbx,0x8
    cmp    rdi,0x11
    jne    at_1_0c80
    {disp32} jmp    at_1_0fcd
at_1_0cc4:
    movsd  xmm6,QWORD PTR [r8]
    movsd  xmm0,QWORD PTR [r8+0x8]
    movsd  xmm7,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movapd xmm1,xmm7
    subsd  xmm1,xmm0
    mulsd  xmm1,xmm6
    movsd  xmm2,QWORD PTR [rip + ref_14_real_3ff8000000000000]
    subsd  xmm2,xmm1
    movsd  QWORD PTR [rsi],xmm2
    movapd xmm1,xmm0
    mulsd  xmm1,xmm0
    movapd xmm2,xmm7
    subsd  xmm2,xmm1
    mulsd  xmm2,xmm6
    movsd  xmm1,QWORD PTR [rip + ref_17_real_4002000000000000]
    subsd  xmm1,xmm2
    movsd  QWORD PTR [rsi+0x8],xmm1
    mov    edx,0x3
    call   ref_103_powr8i8
    subsd  xmm7,xmm0
    mulsd  xmm7,xmm6
    movsd  xmm6,QWORD PTR [rip + ref_20_real_4005000000000000]
    subsd  xmm6,xmm7
    {disp32} jmp    at_1_0fae
at_1_0d3b:
    movsd  xmm6,QWORD PTR [r8]
    movsd  xmm0,QWORD PTR [r8+0x8]
    movapd xmm1,xmm6
    subsd  xmm1,xmm0
    movsd  xmm2,QWORD PTR [r8+0x10]
    addsd  xmm1,xmm2
    movsd  QWORD PTR [rsi],xmm1
    movapd xmm1,xmm0
    subsd  xmm1,xmm6
    addsd  xmm1,xmm2
    movsd  QWORD PTR [rsi+0x8],xmm1
    addsd  xmm6,xmm0
    subsd  xmm6,xmm2
    {disp32} jmp    at_1_0fae
at_1_0d7a:
    movsd  xmm7,QWORD PTR [r8]
    movsd  xmm6,QWORD PTR [r8+0x8]
    movapd xmm0,xmm7
    mov    rdi,r8
    call   ref_95_exp
    subsd  xmm0,xmm6
    mulsd  xmm0,xmm0
    movsd  QWORD PTR [rsi],xmm0
    movsd  xmm8,QWORD PTR [rdi+0x10]
    subsd  xmm6,xmm8
    mov    edx,0x3
    movapd xmm0,xmm6
    call   ref_103_powr8i8
    mulsd  xmm0,QWORD PTR [rip + ref_11_real_4024000000000000]
    movsd  QWORD PTR [rsi+0x8],xmm0
    movsd  xmm6,QWORD PTR [rdi+0x18]
    subsd  xmm8,xmm6
    movapd xmm0,xmm8
    call   ref_96_sin
    movapd xmm9,xmm0
    movapd xmm0,xmm8
    call   ref_97_cos
    divsd  xmm9,xmm0
    mulsd  xmm9,xmm9
    movsd  QWORD PTR [rsi+0x10],xmm9
    mov    edi,0x4
    mov    edx,0x4
    movapd xmm0,xmm7
    call   ref_103_powr8i8
    movsd  QWORD PTR [rsi+0x18],xmm0
    subsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    {disp32} jmp    at_1_0fc8
at_1_0e1b:
    mov    rax,QWORD PTR [rdx]
    xorpd  xmm0,xmm0
    test   rax,rax
    jle    at_1_0e3e
    xor    edx,edx
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0e30:
    addsd  xmm0,QWORD PTR [r8+rdx*8]
    inc    rdx
    cmp    rax,rdx
    jne    at_1_0e30
at_1_0e3e:
    mulsd  xmm0,QWORD PTR [rip + ref_26_real_4000000000000000]
    mov    rcx,QWORD PTR [rcx]
    cvtsi2sd xmm1,rcx
    divsd  xmm0,xmm1
    addsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    test   rcx,rcx
    {disp32} jle    at_1_0fcd
    xorpd  xmm0,XMMWORD PTR [rip + ref_53_xmm_80000000000000008000000000000000]
    neg    rcx
    mov    edx,0x1
    jmp    at_1_0e9a
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0e80:
    movsd  QWORD PTR [rsi+rdx*8-0x8],xmm1
    lea    r9,[rcx+rdx*1]
    inc    r9
    inc    rdx
    cmp    r9,0x1
    {disp32} je     at_1_0fcd
at_1_0e9a:
    movapd xmm1,xmm0
    cmp    rdx,rax
    jg     at_1_0e80
    movsd  xmm1,QWORD PTR [r8+rdx*8-0x8]
    addsd  xmm1,xmm0
    jmp    at_1_0e80
at_1_0eb0:
    mov    rax,QWORD PTR [rdx]
    mov    ecx,0x1
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    jmp    at_1_0ee2
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0ed0:
    movsd  QWORD PTR [rsi+rcx*8-0x8],xmm1
    inc    rcx
    cmp    rcx,rdi
    {disp32} je     at_1_05ae
at_1_0ee2:
    xorps  xmm2,xmm2
    cvtsi2sd xmm2,rcx
    xorpd  xmm1,xmm1
    test   rax,rax
    jle    at_1_0ed0
    xor    edx,edx
    movapd xmm3,xmm0
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0f00:
    movsd  xmm4,QWORD PTR [r8+rdx*8]
    mulsd  xmm4,xmm3
    addsd  xmm1,xmm4
    mulsd  xmm3,xmm2
    inc    rdx
    cmp    rax,rdx
    jne    at_1_0f00
    jmp    at_1_0ed0
at_1_0f1c:
    movsd  xmm0,QWORD PTR [rip + ref_74_real_bfd0000000000000]
at_1_0f24:
    xorpd  xmm9,xmm9
    ucomisd xmm7,xmm9
    jbe    at_1_0f45
    movapd xmm0,xmm8
    divsd  xmm0,xmm7
    call   ref_99_atan
    mov    rax,rdi
    divsd  xmm0,xmm6
at_1_0f45:
    ucomisd xmm9,xmm7
    jbe    at_1_0f69
    movapd xmm0,xmm8
    divsd  xmm0,xmm7
    call   ref_99_atan
    mov    rax,rdi
    divsd  xmm0,xmm6
    addsd  xmm0,QWORD PTR [rip + ref_80_real_3fe0000000000000]
at_1_0f69:
    mulsd  xmm7,xmm7
    mulsd  xmm8,xmm8
    addsd  xmm8,xmm7
    sqrtsd xmm1,xmm8
    movsd  xmm6,QWORD PTR [rax+0x10]
    movsd  xmm2,QWORD PTR [rip + ref_11_real_4024000000000000]
    mulsd  xmm0,xmm2
    movapd xmm3,xmm6
    subsd  xmm3,xmm0
    mulsd  xmm3,xmm2
    subsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movsd  QWORD PTR [rsi],xmm3
    mulsd  xmm1,xmm2
    movsd  QWORD PTR [rsi+0x8],xmm1
at_1_0fae:
    mov    edi,0x2
    jmp    at_1_0fc8
at_1_0fb5:
    movsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
at_1_0fbd:
    subsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    dec    rdi
at_1_0fc8:
    movsd  QWORD PTR [rsi+rdi*8],xmm6
at_1_0fcd:
    movaps xmm6,XMMWORD PTR [rsp+0x50]
    movaps xmm7,XMMWORD PTR [rsp+0x60]
    movaps xmm8,XMMWORD PTR [rsp+0x70]
    movaps xmm9,XMMWORD PTR [rsp+0x80]
    movaps xmm10,XMMWORD PTR [rsp+0x90]
    movaps xmm11,XMMWORD PTR [rsp+0xa0]
    movaps xmm12,XMMWORD PTR [rsp+0xb0]
    movaps xmm13,XMMWORD PTR [rsp+0xc0]
    movaps xmm14,XMMWORD PTR [rsp+0xd0]
    movaps xmm15,XMMWORD PTR [rsp+0xe0]
    add    rsp,0xf8
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r14
    ret
at_1_1029:
    xorpd  xmm0,xmm0
at_1_102d:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_0fcd
    neg    rax
    mov    ecx,0x1
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1050:
    xorps  xmm2,xmm2
    cvtsi2sd xmm2,rcx
    mulsd  xmm2,xmm0
    subsd  xmm2,xmm1
    movsd  QWORD PTR [rsi+rcx*8-0x8],xmm2
    lea    rdx,[rax+rcx*1]
    inc    rdx
    inc    rcx
    cmp    rdx,0x1
    jne    at_1_1050
    {disp32} jmp    at_1_0fcd
at_1_107b:
    xor    eax,eax
    nop    DWORD PTR [rax]
at_1_1080:
    mov    QWORD PTR [rsi+rax*8],0x0
    inc    rax
    cmp    rdi,rax
    jne    at_1_1080
at_1_1090:
    mov    rax,QWORD PTR [rdx]
    test   rax,rax
    jle    at_1_110c
    mov    ecx,0x1
    movsd  xmm0,QWORD PTR [rip + ref_26_real_4000000000000000]
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    jmp    at_1_10bc
    nop
at_1_10b0:
    lea    rdx,[rcx+0x1]
    cmp    rcx,rax
    mov    rcx,rdx
    je     at_1_110c
at_1_10bc:
    movsd  xmm2,QWORD PTR [r8+rcx*8-0x8]
    mulsd  xmm2,xmm0
    subsd  xmm2,xmm1
    movapd xmm3,xmm0
    mulsd  xmm3,xmm2
    test   rdi,rdi
    jle    at_1_10b0
    xor    edx,edx
    movapd xmm4,xmm1
    xchg   ax,ax
at_1_10e0:
    movsd  xmm5,QWORD PTR [rsi+rdx*8]
    addsd  xmm5,xmm2
    movsd  QWORD PTR [rsi+rdx*8],xmm5
    movapd xmm5,xmm3
    mulsd  xmm5,xmm2
    subsd  xmm5,xmm4
    inc    rdx
    movapd xmm4,xmm2
    movapd xmm2,xmm5
    cmp    rdi,rdx
    jne    at_1_10e0
    jmp    at_1_10b0
at_1_110c:
    xorps  xmm2,xmm2
    cvtsi2sd xmm2,rax
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movapd xmm1,xmm0
    divsd  xmm1,xmm2
    test   rdi,rdi
    {disp32} jle    at_1_0fcd
    neg    rdi
    mov    rax,0xffffffffffffffff
    mov    ecx,0x1
    jmp    at_1_115d
    xchg   ax,ax
at_1_1140:
    movsd  QWORD PTR [rsi+rcx*8-0x8],xmm2
    neg    rax
    lea    rdx,[rdi+rcx*1]
    inc    rdx
    inc    rcx
    cmp    rdx,0x1
    {disp32} je     at_1_0fcd
at_1_115d:
    movsd  xmm2,QWORD PTR [rsi+rcx*8-0x8]
    mulsd  xmm2,xmm1
    test   rax,rax
    jle    at_1_1140
    xorps  xmm3,xmm3
    cvtsi2sd xmm3,rcx
    mulsd  xmm3,xmm3
    subsd  xmm3,xmm0
    movapd xmm4,xmm0
    divsd  xmm4,xmm3
    addsd  xmm2,xmm4
    jmp    at_1_1140
at_1_118a:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_4024000000000000:
at_5_0000:
    .quad 0x4024000000000000    # binary64 10.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3ff8000000000000:
at_6_0000:
    .quad 0x3ff8000000000000    # binary64 1.5
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_real_4002000000000000:
at_7_0000:
    .quad 0x4002000000000000    # binary64 2.25
at_7_0008:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_4005000000000000:
at_8_0000:
    .quad 0x4005000000000000    # binary64 2.625
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_4010000000000000:
at_9_0000:
    .quad 0x4010000000000000    # binary64 4.0
at_9_0008:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_24_rdata:
def_26_real_4000000000000000:
at_10_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_10_0008:
end_s10:

# .rdata  (COFF section 11)
.section .s11,"dr"
def_27_rdata:
def_29_real_40915c0000000000:
at_11_0000:
    .quad 0x40915c0000000000    # binary64 1111.0
at_11_0008:
end_s11:

# .rdata  (COFF section 12)
.section .s12,"dr"
def_30_rdata:
def_32_real_4008000000000000:
at_12_0000:
    .quad 0x4008000000000000    # binary64 3.0
at_12_0008:
end_s12:

# .rdata  (COFF section 13)
.section .s13,"dr"
def_33_rdata:
def_35_real_4014000000000000:
at_13_0000:
    .quad 0x4014000000000000    # binary64 5.0
at_13_0008:
end_s13:

# .rdata  (COFF section 14)
.section .s14,"dr"
def_36_rdata:
def_38_real_4042000000000000:
at_14_0000:
    .quad 0x4042000000000000    # binary64 36.0
at_14_0008:
end_s14:

# .rdata  (COFF section 15)
.section .s15,"dr"
def_39_rdata:
def_41_real_4056800000000000:
at_15_0000:
    .quad 0x4056800000000000    # binary64 90.0
at_15_0008:
end_s15:

# .rdata  (COFF section 16)
.section .s16,"dr"
def_42_rdata:
def_44_real_4023cccccccccccd:
at_16_0000:
    .quad 0x4023cccccccccccd    # binary64 9.9
at_16_0008:
end_s16:

# .rdata  (COFF section 17)
.section .s17,"dr"
def_45_rdata:
def_47_real_3fc999999999999a:
at_17_0000:
    .quad 0x3fc999999999999a    # binary64 0.2
at_17_0008:
end_s17:

# .rdata  (COFF section 18)
.section .s18,"dr"
def_48_rdata:
def_50_real_401921fb54442d18:
at_18_0000:
    .quad 0x401921fb54442d18    # binary64 6.283185307179586
at_18_0008:
end_s18:

# .rdata  (COFF section 19)
.section .s19,"dr"
def_51_rdata:
def_53_xmm_80000000000000008000000000000000:
at_19_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_19_0010:
end_s19:

# .rdata  (COFF section 20)
.section .s20,"dr"
def_54_rdata:
def_56_real_403d000000000000:
at_20_0000:
    .quad 0x403d000000000000    # binary64 29.0
at_20_0008:
end_s20:

# .rdata  (COFF section 21)
.section .s21,"dr"
def_57_rdata:
def_59_real_4046800000000000:
at_21_0000:
    .quad 0x4046800000000000    # binary64 45.0
at_21_0008:
end_s21:

# .rdata  (COFF section 22)
.section .s22,"dr"
def_60_rdata:
def_62_real_c02a000000000000:
at_22_0000:
    .quad 0xc02a000000000000    # binary64 -13.0
at_22_0008:
end_s22:

# .rdata  (COFF section 23)
.section .s23,"dr"
def_63_rdata:
def_65_real_c03d000000000000:
at_23_0000:
    .quad 0xc03d000000000000    # binary64 -29.0
at_23_0008:
end_s23:

# .rdata  (COFF section 24)
.section .s24,"dr"
def_66_rdata:
def_68_real_402c000000000000:
at_24_0000:
    .quad 0x402c000000000000    # binary64 14.0
at_24_0008:
end_s24:

# .rdata  (COFF section 25)
.section .s25,"dr"
def_69_rdata:
def_71_real_4020000000000000:
at_25_0000:
    .quad 0x4020000000000000    # binary64 8.0
at_25_0008:
end_s25:

# .rdata  (COFF section 26)
.section .s26,"dr"
def_72_rdata:
def_74_real_bfd0000000000000:
at_26_0000:
    .quad 0xbfd0000000000000    # binary64 -0.25
at_26_0008:
end_s26:

# .rdata  (COFF section 27)
.section .s27,"dr"
def_75_rdata:
def_77_real_3fd0000000000000:
at_27_0000:
    .quad 0x3fd0000000000000    # binary64 0.25
at_27_0008:
end_s27:

# .rdata  (COFF section 28)
.section .s28,"dr"
def_78_rdata:
def_80_real_3fe0000000000000:
at_28_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_28_0008:
end_s28:

# .rdata  (COFF section 29)
.section .s29,"dr"
def_81_rdata:
def_83_real_bff0000000000000:
at_29_0000:
    .quad 0xbff0000000000000    # binary64 -1.0
at_29_0008:
end_s29:

# .rdata  (COFF section 30)
.section .s30,"dr"
def_84_rdata:
at_30_0000:
    .long ref_0_text + (at_1_008e - at_1_0000) + (. - at_30_0000) + 4    # problem 2 -> at_1_008e
    .long ref_0_text + (at_1_0746 - at_1_0000) + (. - at_30_0000) + 4    # problem 3 -> at_1_0746
    .long ref_0_text + (at_1_05b8 - at_1_0000) + (. - at_30_0000) + 4    # problem 4 -> at_1_05b8
    .long ref_0_text + (at_1_0689 - at_1_0000) + (. - at_30_0000) + 4    # problem 5 -> at_1_0689
    .long ref_0_text + (at_1_0318 - at_1_0000) + (. - at_30_0000) + 4    # problem 6 -> at_1_0318
    .long ref_0_text + (at_1_093e - at_1_0000) + (. - at_30_0000) + 4    # problem 7 -> at_1_093e
    .long ref_0_text + (at_1_0a34 - at_1_0000) + (. - at_30_0000) + 4    # problem 8 -> at_1_0a34
    .long ref_0_text + (at_1_06d2 - at_1_0000) + (. - at_30_0000) + 4    # problem 9 -> at_1_06d2
    .long ref_0_text + (at_1_0c42 - at_1_0000) + (. - at_30_0000) + 4    # problem 10 -> at_1_0c42
    .long ref_0_text + (at_1_0447 - at_1_0000) + (. - at_30_0000) + 4    # problem 11 -> at_1_0447
    .long ref_0_text + (at_1_0b74 - at_1_0000) + (. - at_30_0000) + 4    # problem 12 -> at_1_0b74
    .long ref_0_text + (at_1_028c - at_1_0000) + (. - at_30_0000) + 4    # problem 13 -> at_1_028c
    .long ref_0_text + (at_1_038f - at_1_0000) + (. - at_30_0000) + 4    # problem 14 -> at_1_038f
    .long ref_0_text + (at_1_09f8 - at_1_0000) + (. - at_30_0000) + 4    # problem 15 -> at_1_09f8
    .long ref_0_text + (at_1_0221 - at_1_0000) + (. - at_30_0000) + 4    # problem 16 -> at_1_0221
    .long ref_0_text + (at_1_05e8 - at_1_0000) + (. - at_30_0000) + 4    # problem 17 -> at_1_05e8
    .long ref_0_text + (at_1_00d8 - at_1_0000) + (. - at_30_0000) + 4    # problem 18 -> at_1_00d8
    .long ref_0_text + (at_1_07bd - at_1_0000) + (. - at_30_0000) + 4    # problem 19 -> at_1_07bd
    .long ref_0_text + (at_1_0ab6 - at_1_0000) + (. - at_30_0000) + 4    # problem 20 -> at_1_0ab6
    .long ref_0_text + (at_1_0d3b - at_1_0000) + (. - at_30_0000) + 4    # problem 21 -> at_1_0d3b
    .long ref_0_text + (at_1_084c - at_1_0000) + (. - at_30_0000) + 4    # problem 22 -> at_1_084c
    .long ref_0_text + (at_1_09a3 - at_1_0000) + (. - at_30_0000) + 4    # problem 23 -> at_1_09a3
    .long ref_0_text + (at_1_0cc4 - at_1_0000) + (. - at_30_0000) + 4    # problem 24 -> at_1_0cc4
    .long ref_0_text + (at_1_0d7a - at_1_0000) + (. - at_30_0000) + 4    # problem 25 -> at_1_0d7a
    .long ref_0_text + (at_1_05a1 - at_1_0000) + (. - at_30_0000) + 4    # problem 26 -> at_1_05a1
    .long ref_0_text + (at_1_054c - at_1_0000) + (. - at_30_0000) + 4    # problem 27 -> at_1_054c
    .zero 24
def_94_SSQFCN_Y5:
at_30_0080:
    .quad 0x3ff5db22d0e56042    # binary64 1.366
    .quad 0x3ff30e5604189375    # binary64 1.191
    .quad 0x3ff1cac083126e98    # binary64 1.112
    .quad 0x3ff0353f7ced9168    # binary64 1.013
    .quad 0x3fefb645a1cac083    # binary64 0.991
    .quad 0x3fec51eb851eb852    # binary64 0.885
    .quad 0x3fea978d4fdf3b64    # binary64 0.831
    .quad 0x3feb1a9fbe76c8b4    # binary64 0.847
    .quad 0x3fe926e978d4fdf4    # binary64 0.786
    .quad 0x3fe7333333333333    # binary64 0.725
    .quad 0x3fe7df3b645a1cac    # binary64 0.746
    .quad 0x3fe5ba5e353f7cee    # binary64 0.679
    .quad 0x3fe374bc6a7ef9db    # binary64 0.608
    .quad 0x3fe4f5c28f5c28f6    # binary64 0.655
    .quad 0x3fe3b645a1cac083    # binary64 0.616
    .quad 0x3fe3645a1cac0831    # binary64 0.606
    .quad 0x3fe34395810624dd    # binary64 0.602
    .quad 0x3fe4083126e978d5    # binary64 0.626
    .quad 0x3fe4d4fdf3b645a2    # binary64 0.651
    .quad 0x3fe72b020c49ba5e    # binary64 0.724
    .quad 0x3fe4c49ba5e353f8    # binary64 0.649
    .quad 0x3fe4c49ba5e353f8    # binary64 0.649
    .quad 0x3fe6353f7ced9168    # binary64 0.694
    .quad 0x3fe49ba5e353f7cf    # binary64 0.644
    .quad 0x3fe3f7ced916872b    # binary64 0.624
    .quad 0x3fe526e978d4fdf4    # binary64 0.661
    .quad 0x3fe395810624dd2f    # binary64 0.612
    .quad 0x3fe1db22d0e56042    # binary64 0.558
    .quad 0x3fe10e5604189375    # binary64 0.533
    .quad 0x3fdfae147ae147ae    # binary64 0.495
    .quad 0x3fe0000000000000    # binary64 0.5
    .quad 0x3fdb126e978d4fdf    # binary64 0.423
    .quad 0x3fd947ae147ae148    # binary64 0.395
    .quad 0x3fd8000000000000    # binary64 0.375
    .quad 0x3fd7ced916872b02    # binary64 0.372
    .quad 0x3fd90624dd2f1aa0    # binary64 0.391
    .quad 0x3fd95810624dd2f2    # binary64 0.396
    .quad 0x3fd9eb851eb851ec    # binary64 0.405
    .quad 0x3fdb645a1cac0831    # binary64 0.428
    .quad 0x3fdb74bc6a7ef9db    # binary64 0.429
    .quad 0x3fe0bc6a7ef9db23    # binary64 0.523
    .quad 0x3fe1fbe76c8b4396    # binary64 0.562
    .quad 0x3fe36c8b43958106    # binary64 0.607
    .quad 0x3fe4e5604189374c    # binary64 0.653
    .quad 0x3fe5810624dd2f1b    # binary64 0.672
    .quad 0x3fe6a7ef9db22d0e    # binary64 0.708
    .quad 0x3fe44189374bc6a8    # binary64 0.633
    .quad 0x3fe5604189374bc7    # binary64 0.668
    .quad 0x3fe4a3d70a3d70a4    # binary64 0.645
    .quad 0x3fe4395810624dd3    # binary64 0.632
    .quad 0x3fe2e978d4fdf3b6    # binary64 0.591
    .quad 0x3fe1e353f7ced917    # binary64 0.559
    .quad 0x3fe31a9fbe76c8b4    # binary64 0.597
    .quad 0x3fe4000000000000    # binary64 0.625
    .quad 0x3fe7a5e353f7ced9    # binary64 0.739
    .quad 0x3fe6b851eb851eb8    # binary64 0.71
    .quad 0x3fe753f7ced91687    # binary64 0.729
    .quad 0x3fe70a3d70a3d70a    # binary64 0.72
    .quad 0x3fe45a1cac083127    # binary64 0.636
    .quad 0x3fe2978d4fdf3b64    # binary64 0.581
    .quad 0x3fdb645a1cac0831    # binary64 0.428
    .quad 0x3fd2b020c49ba5e3    # binary64 0.292
    .quad 0x3fc4bc6a7ef9db23    # binary64 0.162
    .quad 0x3fb916872b020c4a    # binary64 0.098
    .quad 0x3faba5e353f7ced9    # binary64 0.054
    .quad 0x0000000000000000
    .quad 0x0000000000000000
    .quad 0x0000000000000000
def_98_SSQFCN_Y4:
at_30_02a0:
    .quad 0x3feb020c49ba5e35    # binary64 0.844
    .quad 0x3fed0e5604189375    # binary64 0.908
    .quad 0x3fedd2f1a9fbe76d    # binary64 0.932
    .quad 0x3fedf3b645a1cac1    # binary64 0.936
    .quad 0x3fed99999999999a    # binary64 0.925
    .quad 0x3fed0e5604189375    # binary64 0.908
    .quad 0x3fec3126e978d4fe    # binary64 0.881
    .quad 0x3feb333333333333    # binary64 0.85
    .quad 0x3fea2d0e56041893    # binary64 0.818
    .quad 0x3fe916872b020c4a    # binary64 0.784
    .quad 0x3fe8083126e978d5    # binary64 0.751
    .quad 0x3fe6f9db22d0e560    # binary64 0.718
    .quad 0x3fe5eb851eb851ec    # binary64 0.685
    .quad 0x3fe50e5604189375    # binary64 0.658
    .quad 0x3fe4189374bc6a7f    # binary64 0.628
    .quad 0x3fe34bc6a7ef9db2    # binary64 0.603
    .quad 0x3fe28f5c28f5c28f    # binary64 0.58
    .quad 0x3fe1db22d0e56042    # binary64 0.558
    .quad 0x3fe1374bc6a7ef9e    # binary64 0.538
    .quad 0x3fe0b4395810624e    # binary64 0.522
    .quad 0x3fe03126e978d4fe    # binary64 0.506
    .quad 0x3fdf5c28f5c28f5c    # binary64 0.49
    .quad 0x3fde978d4fdf3b64    # binary64 0.478
    .quad 0x3fdde353f7ced917    # binary64 0.467
    .quad 0x3fdd3f7ced916873    # binary64 0.457
    .quad 0x3fdcac083126e979    # binary64 0.448
    .quad 0x3fdc083126e978d5    # binary64 0.438
    .quad 0x3fdb95810624dd2f    # binary64 0.431
    .quad 0x3fdb22d0e5604189    # binary64 0.424
    .quad 0x3fdae147ae147ae1    # binary64 0.42
    .quad 0x3fda7ef9db22d0e5    # binary64 0.414
    .quad 0x3fda4dd2f1a9fbe7    # binary64 0.411
    .quad 0x3fd9fbe76c8b4396    # binary64 0.406
    .quad 0x0000000000000000
    .quad 0x0000000000000000
    .quad 0x0000000000000000
def_106_SSQFCN_Y3:
at_30_03c0:
    .quad 0x40e0fb8000000000    # binary64 34780.0
    .quad 0x40dbf08000000000    # binary64 28610.0
    .quad 0x40d7188000000000    # binary64 23650.0
    .quad 0x40d32b8000000000    # binary64 19630.0
    .quad 0x40cff90000000000    # binary64 16370.0
    .quad 0x40cacc0000000000    # binary64 13720.0
    .quad 0x40c68a0000000000    # binary64 11540.0
    .quad 0x40c3080000000000    # binary64 9744.0
    .quad 0x40c0228000000000    # binary64 8261.0
    .quad 0x40bb760000000000    # binary64 7030.0
    .quad 0x40b7750000000000    # binary64 6005.0
    .quad 0x40b41b0000000000    # binary64 5147.0
    .quad 0x40b14b0000000000    # binary64 4427.0
    .quad 0x40add80000000000    # binary64 3820.0
    .quad 0x40a9d60000000000    # binary64 3307.0
    .quad 0x40a6700000000000    # binary64 2872.0
def_101_SSQFCN_Y2:
at_30_0440:
    .quad 0x3fc90cb295e9e1b1    # binary64 0.1957
    .quad 0x3fc8ebedfa43fe5d    # binary64 0.1947
    .quad 0x3fc6353f7ced9168    # binary64 0.1735
    .quad 0x3fc47ae147ae147b    # binary64 0.16
    .quad 0x3fb59b3d07c84b5e    # binary64 0.0844
    .quad 0x3fb00d1b71758e22    # binary64 0.0627
    .quad 0x3fa758e219652bd4    # binary64 0.0456
    .quad 0x3fa182a9930be0df    # binary64 0.0342
    .quad 0x3fa089a027525461    # binary64 0.0323
    .quad 0x3f9810624dd2f1aa    # binary64 0.0235
    .quad 0x3f9930be0ded288d    # binary64 0.0246
    .quad 0x0000000000000000
def_105_SSQFCN_Y1:
at_30_04a0:
    .quad 0x3fc1eb851eb851ec    # binary64 0.14
    .quad 0x3fc70a3d70a3d70a    # binary64 0.18
    .quad 0x3fcc28f5c28f5c29    # binary64 0.22
    .quad 0x3fd0000000000000    # binary64 0.25
    .quad 0x3fd28f5c28f5c28f    # binary64 0.29
    .quad 0x3fd47ae147ae147b    # binary64 0.32
    .quad 0x3fd6666666666666    # binary64 0.35
    .quad 0x3fd8f5c28f5c28f6    # binary64 0.39
    .quad 0x3fd7ae147ae147ae    # binary64 0.37
    .quad 0x3fe28f5c28f5c28f    # binary64 0.58
    .quad 0x3fe75c28f5c28f5c    # binary64 0.73
    .quad 0x3feeb851eb851eb8    # binary64 0.96
    .quad 0x3ff570a3d70a3d71    # binary64 1.34
    .quad 0x4000cccccccccccd    # binary64 2.1
    .quad 0x40118f5c28f5c28f    # binary64 4.39
    .quad 0x0000000000000000
def_100_SSQFCN_V:
at_30_0520:
    .quad 0x4010000000000000    # binary64 4.0
    .quad 0x4000000000000000    # binary64 2.0
    .quad 0x3ff0000000000000    # binary64 1.0
    .quad 0x3fe0000000000000    # binary64 0.5
    .quad 0x3fd0000000000000    # binary64 0.25
    .quad 0x3fc5604189374bc7    # binary64 0.167
    .quad 0x3fc0000000000000    # binary64 0.125
    .quad 0x3fb999999999999a    # binary64 0.1
    .quad 0x3fb5532617c1bda5    # binary64 0.0833
    .quad 0x3fb2474538ef34d7    # binary64 0.0714
    .quad 0x3fb0000000000000    # binary64 0.0625
at_30_0578:
end_s30:

# .xdata  (COFF section 31)
.section .s31,"dr"
def_86_xdata:
at_31_0000:
    .byte 0x01    # version 1
    .byte at_1_0065 - at_1_0000    # prologue size
    .byte 0x1a    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0065 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x05
    .byte 0x00
    .byte at_1_005f - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x06
    .byte 0x00
    .byte at_1_0059 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x07
    .byte 0x00
    .byte at_1_0052 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x08
    .byte 0x00
    .byte at_1_0048 - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x09
    .byte 0x00
    .byte at_1_003e - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x0a
    .byte 0x00
    .byte at_1_0034 - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x0b
    .byte 0x00
    .byte at_1_002a - at_1_0000    # SAVE_XMM128
    .byte 0xd8
    .byte 0x0c
    .byte 0x00
    .byte at_1_0020 - at_1_0000    # SAVE_XMM128
    .byte 0xe8
    .byte 0x0d
    .byte 0x00
    .byte at_1_0016 - at_1_0000    # SAVE_XMM128
    .byte 0xf8
    .byte 0x0e
    .byte 0x00
    .byte at_1_000c - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x1f
    .byte 0x00
    .byte at_1_0005 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
at_31_0038:
end_s31:

# .drectve  (COFF section 32)
.section .s32,"dr"
def_88_drectve:
at_32_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_32_00b9:
end_s32:

# .pdata  (COFF section 33)
.section .s33,"dr"
def_90_pdata:
at_33_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_118a - def_0_text)    # image-relative end
    .long ref_86_xdata    # image-relative unwind info
at_33_000c:
end_s33:

# MEMBER lmdipt.obj
# Entry points: INITPT
.intel_syntax noprefix
# Initial-point dispatch: problem codes 4..27 select the table entries below.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_18_INITPT:
at_1_0000:
    push   r14
at_1_0002:
    push   rsi
at_1_0003:
    push   rdi
at_1_0004:
    push   rbx
at_1_0005:
    sub    rsp,0x28
at_1_0009:
    mov    rsi,QWORD PTR [r8]
    lea    eax,[rsi-0x4]
    cmp    eax,0x17
    {disp32} ja     at_1_0461
    lea    r8,[rip + ref_9_rdata]
    movsxd rax,DWORD PTR [r8+rax*4]
    add    rax,r8
    jmp    rax
at_1_0028:
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rdx],rax
    xorpd  xmm0,xmm0
    movupd XMMWORD PTR [rdx+0x8],xmm0
    {disp32} jmp    at_1_04a0
at_1_0043:
    movabs rax,0xc008000000000000
    mov    QWORD PTR [rdx],rax
    movabs r8,0xbff0000000000000
    mov    QWORD PTR [rdx+0x8],r8
    mov    QWORD PTR [rdx+0x10],rax
    mov    QWORD PTR [rdx+0x18],r8
    {disp32} jmp    at_1_04a0
at_1_006b:
    movabs rax,0x3fe0000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0x3ff8000000000000
    mov    QWORD PTR [rdx+0x8],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rdx+0x10],rax
    movabs rax,0x3f847ae147ae147b
    mov    QWORD PTR [rdx+0x18],rax
    movabs rax,0x3f947ae147ae147b
    mov    QWORD PTR [rdx+0x20],rax
    {disp32} jmp    at_1_04a0
at_1_00b5:
    movabs rax,0x4039000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0x4014000000000000
    mov    QWORD PTR [rdx+0x8],rax
    movabs rax,0xc014000000000000
    mov    QWORD PTR [rdx+0x10],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rdx+0x18],rax
    {disp32} jmp    at_1_04a0
at_1_00f1:
    movabs rax,0x3fe0000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0xc000000000000000
    mov    QWORD PTR [rdx+0x8],rax
    {disp32} jmp    at_1_04a0
at_1_0111:
    mov    rax,QWORD PTR [rcx]
    lea    r8,[rax+0x1]
    cvtsi2sd xmm1,r8
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    divsd  xmm0,xmm1
    test   rax,rax
    {disp32} jle    at_1_04a0
    neg    rax
    mov    r8d,0x1
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0140:
    xorps  xmm1,xmm1
    cvtsi2sd xmm1,r8
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rdx+r8*8-0x8],xmm1
    lea    r10,[rax+r8*1]
    inc    r10
    inc    r8
    cmp    r10,0x1
    jne    at_1_0140
    {disp32} jmp    at_1_04a0
at_1_0168:
    mov    QWORD PTR [rdx],0x0
    movabs rax,0x4024000000000000
    mov    QWORD PTR [rdx+0x8],rax
    movabs rax,0x4034000000000000
    mov    QWORD PTR [rdx+0x10],rax
    {disp32} jmp    at_1_04a0
at_1_0190:
    movabs rax,0xbff3333333333333
    {disp32} jmp    at_1_044e
at_1_019f:
    movabs rax,0x3ff4cccccccccccd
    mov    QWORD PTR [rdx],rax
    movabs rax,0x3fe4cccccccccccd
    mov    QWORD PTR [rdx+0x8],rax
    mov    QWORD PTR [rdx+0x10],rax
    movabs rax,0x3fe6666666666666
    mov    QWORD PTR [rdx+0x18],rax
    movabs rax,0x3fe3333333333333
    mov    QWORD PTR [rdx+0x20],rax
    movabs rax,0x4008000000000000
    mov    QWORD PTR [rdx+0x28],rax
    movabs rax,0x4014000000000000
    mov    QWORD PTR [rdx+0x30],rax
    movabs rax,0x401c000000000000
    mov    QWORD PTR [rdx+0x38],rax
    movabs rax,0x4000000000000000
    mov    QWORD PTR [rdx+0x40],rax
    movabs rax,0x4012000000000000
    mov    QWORD PTR [rdx+0x48],rax
    movabs rax,0x4016000000000000
    mov    QWORD PTR [rdx+0x50],rax
    {disp32} jmp    at_1_04a0
at_1_0233:
    movabs rax,0x4008000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rdx+0x8],rax
    mov    QWORD PTR [rdx+0x10],0x0
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rdx+0x18],rax
    {disp32} jmp    at_1_04a0
at_1_0269:
    movabs rax,0x3f947ae147ae147b
    mov    QWORD PTR [rdx],rax
    movabs rax,0x40af400000000000
    mov    QWORD PTR [rdx+0x8],rax
    movabs rax,0x406f400000000000
    mov    QWORD PTR [rdx+0x10],rax
    {disp32} jmp    at_1_04a0
at_1_0297:
    movabs rax,0x4059000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rdx+0x8],rax
    movabs rax,0x4004000000000000
    mov    QWORD PTR [rdx+0x10],rax
    {disp32} jmp    at_1_04a0
at_1_02c5:
    movabs rax,0x3fb999999999999a
    mov    QWORD PTR [rdx],rax
    mov    QWORD PTR [rdx+0x8],rax
    {disp32} jmp    at_1_04a0
at_1_02db:
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rdx],rax
    mov    QWORD PTR [rdx+0x8],rax
    mov    QWORD PTR [rdx+0x10],rax
    {disp32} jmp    at_1_04a0
at_1_02f5:
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0x4000000000000000
    mov    QWORD PTR [rdx+0x8],rax
    mov    QWORD PTR [rdx+0x10],rax
    mov    QWORD PTR [rdx+0x18],rax
    {disp32} jmp    at_1_04a0
at_1_031d:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    {disp32} jle    at_1_04a0
    xor    r8d,r8d
    movabs r10,0x3fe0000000000000
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0340:
    mov    QWORD PTR [rdx+r8*8],r10
    inc    r8
    cmp    rax,r8
    jne    at_1_0340
    {disp32} jmp    at_1_04a0
at_1_0351:
    movabs rax,0x3fd0000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0x3fd8f5c28f5c28f6
    mov    QWORD PTR [rdx+0x8],rax
    movabs r8,0x3fda8f5c28f5c28f
    mov    QWORD PTR [rdx+0x10],r8
    mov    QWORD PTR [rdx+0x18],rax
    {disp32} jmp    at_1_04a0
at_1_0383:
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rdx],rax
    movabs rax,0x4000000000000000
    mov    QWORD PTR [rdx+0x8],rax
    mov    QWORD PTR [rdx+0x10],0x0
    {disp32} jmp    at_1_04a0
at_1_03ab:
    movabs rax,0x3fd3333333333333
    mov    QWORD PTR [rdx],rax
    movabs rax,0x3fd999999999999a
    mov    QWORD PTR [rdx+0x8],rax
    {disp32} jmp    at_1_04a0
at_1_03cb:
    mov    r8,QWORD PTR [rcx]
    test   r8,r8
    {disp32} jle    at_1_04a0
    cmp    r8,0xc
    ja     at_1_040b
    xor    eax,eax
    nop
at_1_03e0:
    mov    QWORD PTR [rdx+rax*8],0x0
    inc    rax
    cmp    r8,rax
    jne    at_1_03e0
    {disp32} jmp    at_1_04a0
at_1_03f5:
    mov    r8,QWORD PTR [rcx]
    test   r8,r8
    {disp32} jle    at_1_04a0
    cmp    r8,0xc
    {disp32} jbe    at_1_048e
at_1_040b:
    shl    r8,0x3
    mov    rdi,rcx
    mov    rcx,rdx
    mov    rbx,rdx
    xor    edx,edx
    mov    r14,r9
    call   ref_19_intel_fast_memset
    mov    r9,r14
    mov    rcx,rdi
    mov    rdx,rbx
    jmp    at_1_04a0
at_1_042d:
    movabs rax,0x4000000000000000
    mov    QWORD PTR [rdx],rax
    mov    QWORD PTR [rdx+0x8],0x0
    jmp    at_1_04a0
at_1_0444:
    movabs rax,0x4008000000000000
at_1_044e:
    mov    QWORD PTR [rdx],rax
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rdx+0x8],rax
    jmp    at_1_04a0
at_1_0461:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_04a0
    xor    r8d,r8d
    movabs r10,0x3ff0000000000000
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0480:
    mov    QWORD PTR [rdx+r8*8],r10
    inc    r8
    cmp    rax,r8
    jne    at_1_0480
    jmp    at_1_04a0
at_1_048e:
    xor    eax,eax
at_1_0490:
    mov    QWORD PTR [rdx+rax*8],0x0
    inc    rax
    cmp    r8,rax
    jne    at_1_0490
at_1_04a0:
    movsd  xmm0,QWORD PTR [r9]
    ucomisd xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    setnp  al
    sete   r8b
    test   r8b,al
    jne    at_1_0506
    mov    rax,QWORD PTR [rcx]
    cmp    rsi,0xb
    jne    at_1_04df
    test   rax,rax
    jle    at_1_0506
    xor    ecx,ecx
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_04d0:
    movsd  QWORD PTR [rdx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_04d0
    jmp    at_1_0506
at_1_04df:
    test   rax,rax
    jle    at_1_0506
    xor    ecx,ecx
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_04f0:
    movsd  xmm1,QWORD PTR [rdx+rcx*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rdx+rcx*8],xmm1
    inc    rcx
    cmp    rax,rcx
    jne    at_1_04f0
at_1_0506:
    add    rsp,0x28
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r14
    ret
at_1_0510:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
at_5_0000:
    .long ref_0_text + (at_1_0190 - at_1_0000) + (. - at_5_0000) + 4    # problem 4 -> at_1_0190
    .long ref_0_text + (at_1_0028 - at_1_0000) + (. - at_5_0000) + 4    # problem 5 -> at_1_0028
    .long ref_0_text + (at_1_0233 - at_1_0000) + (. - at_5_0000) + 4    # problem 6 -> at_1_0233
    .long ref_0_text + (at_1_00f1 - at_1_0000) + (. - at_5_0000) + 4    # problem 7 -> at_1_00f1
    .long ref_0_text + (at_1_02db - at_1_0000) + (. - at_5_0000) + 4    # problem 8 -> at_1_02db
    .long ref_0_text + (at_1_0351 - at_1_0000) + (. - at_5_0000) + 4    # problem 9 -> at_1_0351
    .long ref_0_text + (at_1_0269 - at_1_0000) + (. - at_5_0000) + 4    # problem 10 -> at_1_0269
    .long ref_0_text + (at_1_03cb - at_1_0000) + (. - at_5_0000) + 4    # problem 11 -> at_1_03cb
    .long ref_0_text + (at_1_0168 - at_1_0000) + (. - at_5_0000) + 4    # problem 12 -> at_1_0168
    .long ref_0_text + (at_1_03ab - at_1_0000) + (. - at_5_0000) + 4    # problem 13 -> at_1_03ab
    .long ref_0_text + (at_1_00b5 - at_1_0000) + (. - at_5_0000) + 4    # problem 14 -> at_1_00b5
    .long ref_0_text + (at_1_0111 - at_1_0000) + (. - at_5_0000) + 4    # problem 15 -> at_1_0111
    .long ref_0_text + (at_1_031d - at_1_0000) + (. - at_5_0000) + 4    # problem 16 -> at_1_031d
    .long ref_0_text + (at_1_006b - at_1_0000) + (. - at_5_0000) + 4    # problem 17 -> at_1_006b
    .long ref_0_text + (at_1_019f - at_1_0000) + (. - at_5_0000) + 4    # problem 18 -> at_1_019f
    .long ref_0_text + (at_1_0028 - at_1_0000) + (. - at_5_0000) + 4    # problem 19 -> at_1_0028
    .long ref_0_text + (at_1_0043 - at_1_0000) + (. - at_5_0000) + 4    # problem 20 -> at_1_0043
    .long ref_0_text + (at_1_0297 - at_1_0000) + (. - at_5_0000) + 4    # problem 21 -> at_1_0297
    .long ref_0_text + (at_1_0383 - at_1_0000) + (. - at_5_0000) + 4    # problem 22 -> at_1_0383
    .long ref_0_text + (at_1_042d - at_1_0000) + (. - at_5_0000) + 4    # problem 23 -> at_1_042d
    .long ref_0_text + (at_1_02c5 - at_1_0000) + (. - at_5_0000) + 4    # problem 24 -> at_1_02c5
    .long ref_0_text + (at_1_02f5 - at_1_0000) + (. - at_5_0000) + 4    # problem 25 -> at_1_02f5
    .long ref_0_text + (at_1_03f5 - at_1_0000) + (. - at_5_0000) + 4    # problem 26 -> at_1_03f5
    .long ref_0_text + (at_1_0444 - at_1_0000) + (. - at_5_0000) + 4    # problem 27 -> at_1_0444
at_5_0060:
end_s5:

# .xdata  (COFF section 6)
.section .s6,"dr"
def_11_xdata:
at_6_0000:
    .byte 0x01    # version 1
    .byte at_1_0009 - at_1_0000    # prologue size
    .byte 0x05    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0009 - at_1_0000    # ALLOC_SMALL
    .byte 0x42
    .byte at_1_0005 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte 0x00
    .byte 0x00
at_6_0010:
end_s6:

# .drectve  (COFF section 7)
.section .s7,"dr"
def_13_drectve:
at_7_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_7_00b9:
end_s7:

# .pdata  (COFF section 8)
.section .s8,"dr"
def_15_pdata:
at_8_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0510 - def_0_text)    # image-relative end
    .long ref_11_xdata    # image-relative unwind info
at_8_000c:
end_s8:

# MEMBER writeline.obj
# Entry points: WRITELINE
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_WRITELINE:
at_1_0000:
    sub    rsp,0x78
at_1_0004:
    mov    rax,r8
    movabs r8,0x801208384ff00
    mov    rdx,QWORD PTR [rdx]
    test   rdx,rdx
    je     at_1_0062
    xor    r9d,r9d
    test   rdx,rdx
    cmovg  r9,rdx
    mov    QWORD PTR [rsp+0x48],0x0
    mov    edx,DWORD PTR [rcx]
    mov    DWORD PTR [rsp+0x34],0x10438
    mov    QWORD PTR [rsp+0x38],r9
    mov    QWORD PTR [rsp+0x40],rax
    lea    rax,[rip + ref_14_WRITELINE_format_pack]
    mov    QWORD PTR [rsp+0x28],rax
    lea    rax,[rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x48]
    lea    r9,[rsp+0x34]
    jmp    at_1_0093
at_1_0062:
    mov    QWORD PTR [rsp+0x48],0x0
    mov    edx,DWORD PTR [rcx]
    mov    WORD PTR [rsp+0x32],0x1
    lea    rax,[rip + ref_14_WRITELINE_format_pack + (at_2_000c - def_14_WRITELINE_format_pack)]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],0x0
    lea    rcx,[rsp+0x48]
    lea    r9,[rsp+0x32]
at_1_0093:
    call   ref_15_for_write_seq_fmt
    nop
    add    rsp,0x78
    ret
at_1_009e:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_14_WRITELINE_format_pack:
at_2_0000:
    .quad 0x0001004800000036
    .long 0x00000037
at_2_000c:
    .quad 0x0000003700000036
at_2_0014:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0004 - at_1_0000    # prologue size
    .byte 0x01    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0004 - at_1_0000    # ALLOC_SMALL
    .byte 0xe2
    .byte 0x00
    .byte 0x00
at_4_0008:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_009e - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER stopx.obj
# Entry points: STOPX
.intel_syntax noprefix
# Return false in EAX.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_STOPX:
at_1_0000:
    xor    eax,eax
    ret
at_1_0003:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER writelines.obj
# Entry points: WRITELINES
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_WRITELINES:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x88
at_1_0013:
    mov    rsi,rdx
    mov    rdi,QWORD PTR [rsp+0xf8]
    mov    rbx,QWORD PTR [r8]
    cmp    rbx,0xffffffffffffffff
    {disp32} je     at_1_0112
    test   rbx,rbx
    {disp32} je     at_1_0167
    mov    rbp,QWORD PTR [rcx]
    test   rbp,rbp
    {disp32} jle    at_1_0167
    movabs r14,0x801208384ff00
    xor    r12d,r12d
    lea    r15,[rsp+0x58]
    lea    r13,[rsp+0x34]
    jmp    at_1_00d0
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0060:
    cdqe
    test   rax,rax
    mov    ecx,0x0
    cmovg  rcx,rax
    cmp    rax,0x2
    mov    edx,0x1
    cmovl  rax,rdx
    mov    QWORD PTR [rsp+0x58],0x0
    mov    DWORD PTR [rsp+0x34],0x10638
    mov    QWORD PTR [rsp+0x40],rax
    mov    QWORD PTR [rsp+0x48],rsi
    mov    QWORD PTR [rsp+0x50],rcx
    lea    rax,[rip + ref_14_WRITELINES_format_pack]
    mov    QWORD PTR [rsp+0x28],rax
    lea    rax,[rsp+0x40]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,r15
    mov    edx,ebx
    mov    r8,r14
    mov    r9,r13
at_1_00bc:
    call   ref_15_for_write_seq_fmt
    inc    r12
    add    rsi,rdi
    cmp    r12,rbp
    {disp32} jge    at_1_0167
at_1_00d0:
    mov    rcx,rsi
    mov    edx,edi
    call   ref_16_for_len_trim
    test   eax,eax
    jne    at_1_0060
    mov    QWORD PTR [rsp+0x58],0x0
    mov    WORD PTR [rsp+0x32],0x1
    lea    rax,[rip + ref_14_WRITELINES_format_pack + (at_2_000c - def_14_WRITELINES_format_pack)]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],0x0
    mov    rcx,r15
    mov    edx,ebx
    mov    r8,r14
    lea    r9,[rsp+0x32]
    jmp    at_1_00bc
at_1_0112:
    mov    r12,QWORD PTR [rcx]
    test   r12,r12
    jle    at_1_0167
    mov    r14,r9
    mov    r15,r8
    mov    r13,QWORD PTR [rsp+0xf0]
    xor    ebp,ebp
    lea    rbx,[rsp+0x38]
    nop
at_1_0130:
    mov    rcx,rsi
    mov    edx,edi
    call   ref_16_for_len_trim
    cdqe
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x28],rdi
    mov    QWORD PTR [rsp+0x20],r13
    mov    rcx,r15
    mov    rdx,rbx
    mov    r8,rsi
    mov    r9,r14
    call   ref_17_WRITELINE
    inc    rbp
    add    rsi,rdi
    cmp    rbp,r12
    jl     at_1_0130
at_1_0167:
    add    rsp,0x88
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_017b:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_14_WRITELINES_format_pack:
at_2_0000:
    .quad 0x0001004800000036
    .long 0x00000037
at_2_000c:
    .quad 0x0000003700000036
at_2_0014:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0013 - at_1_0000    # prologue size
    .byte 0x0a    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x11
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0018:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_017b - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER i7shft.obj
# Entry points: I7SHFT
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_I7SHFT:
at_1_0000:
    mov    rax,QWORD PTR [rdx]
    test   rax,rax
    js     at_1_003d
    mov    rdx,QWORD PTR [rcx]
    cmp    rax,rdx
    jge    at_1_0079
    mov    rcx,QWORD PTR [r8+rax*8-0x8]
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0020:
    mov    r9,QWORD PTR [r8+rax*8]
    mov    QWORD PTR [r8+rax*8-0x8],r9
    lea    r9,[rax+0x1]
    mov    rax,r9
    cmp    rdx,r9
    jne    at_1_0020
    dec    rdx
    mov    rax,rdx
    jmp    at_1_0075
at_1_003d:
    mov    rdx,rax
    neg    rdx
    mov    r9,QWORD PTR [rcx]
    cmp    r9,rdx
    jle    at_1_0079
    mov    rcx,QWORD PTR [r8+r9*8-0x8]
    mov    r10,r9
    add    r10,rax
    jle    at_1_0072
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0060:
    mov    r10,QWORD PTR [r8+r9*8-0x10]
    mov    QWORD PTR [r8+r9*8-0x8],r10
    dec    r9
    cmp    rdx,r9
    jne    at_1_0060
at_1_0072:
    not    rax
at_1_0075:
    mov    QWORD PTR [r8+rax*8],rcx
at_1_0079:
    ret
at_1_007a:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER i7pnvr.obj
# Entry points: I7PNVR
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_I7PNVR:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_002a
    neg    rax
    mov    ecx,0x1
at_1_0010:
    mov    r9,QWORD PTR [r8+rcx*8-0x8]
    mov    QWORD PTR [rdx+r9*8-0x8],rcx
    lea    r9,[rax+rcx*1]
    inc    r9
    inc    rcx
    cmp    r9,0x1
    jne    at_1_0010
at_1_002a:
    ret
at_1_002b:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER i7mdcn.obj
# Entry points: I7MDCN
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_I7MDCN:
at_1_0000:
    sub    rsp,0x28
at_1_0004:
    mov    rax,QWORD PTR [rcx]
    lea    rcx,[rip + ref_14_I7MDCN_MDPERM]
    lea    rcx,[rcx+rax*8]
    add    rcx,0xfffffffffffffff8
    call   ref_15_I1MACH
    nop
    add    rsp,0x28
    ret
at_1_0021:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_14_I7MDCN_MDPERM:
at_2_0000:
    .quad 0x0000000000000002
    .quad 0x0000000000000004
    .quad 0x0000000000000001
at_2_0018:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0004 - at_1_0000    # prologue size
    .byte 0x01    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0004 - at_1_0000    # ALLOC_SMALL
    .byte 0x42
    .byte 0x00
    .byte 0x00
at_4_0008:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0021 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER i7copy.obj
# Entry points: I7COPY
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_I7COPY:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_0040
    cmp    rax,0xc
    jbe    at_1_0020
    shl    rax,0x3
    mov    rcx,rdx
    mov    rdx,r8
    mov    r8,rax
    jmp    ref_10_intel_fast_memcpy
at_1_0020:
    xor    ecx,ecx
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0030:
    mov    r9,QWORD PTR [r8+rcx*8]
    mov    QWORD PTR [rdx+rcx*8],r9
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0030
at_1_0040:
    ret
at_1_0041:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER i1mach.obj
# Entry points: I1MACH, I1MCR1
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_24_I1MACH:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    push   rbx
at_1_0003:
    sub    rsp,0xa0
at_1_000a:
    cmp    BYTE PTR [rip + ref_25_I1MACH_SC],0x0
    jne    at_1_0066
    movaps xmm0,XMMWORD PTR [rip + ref_8_xmm_0000003500000080ffffff8300000018]
    movups XMMWORD PTR [rip + ref_26_T2 + (at_3_0048 - def_26_T2)],xmm0
    movabs rax,0x400fffffc03
    mov    QWORD PTR [rip + ref_26_T2 + (at_3_0058 - def_26_T2)],rax
    movaps xmm0,XMMWORD PTR [rip + ref_11_xmm_00000006000000070000000600000005]
    movaps XMMWORD PTR [rip + ref_26_T2],xmm0
    movaps xmm0,XMMWORD PTR [rip + ref_14_xmm_0000001f000000020000000400000020]
    movaps XMMWORD PTR [rip + ref_26_T2 + (at_3_0030 - def_26_T2)],xmm0
    movabs rax,0x27fffffff
    mov    QWORD PTR [rip + ref_26_T2 + (at_3_0040 - def_26_T2)],rax
    mov    BYTE PTR [rip + ref_25_I1MACH_SC],0x1
at_1_0066:
    mov    rbx,QWORD PTR [rcx]
    lea    rax,[rbx-0x11]
    cmp    rax,0xffffffffffffffef
    {disp32} ja     at_1_013f
    mov    QWORD PTR [rsp+0x70],0x0
    mov    DWORD PTR [rsp+0x44],0x20438
    mov    QWORD PTR [rsp+0x60],0xe
    lea    rax,[rip + ref_27_strlit_1]
    mov    QWORD PTR [rsp+0x68],rax
    lea    rax,[rsp+0x60]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rdi,[rsp+0x70]
    movabs rsi,0x801208384ff00
    lea    r9,[rsp+0x44]
    mov    rcx,rdi
    mov    edx,0xffffffff
    mov    r8,rsi
    call   ref_28_for_write_seq_lis
    mov    DWORD PTR [rsp+0x40],0x2010b
    mov    QWORD PTR [rsp+0x48],rbx
    lea    rdx,[rsp+0x40]
    lea    r8,[rsp+0x48]
    mov    rcx,rdi
    call   ref_29_for_write_seq_lis_xmit
    mov    DWORD PTR [rsp+0x3c],0x10438
    mov    QWORD PTR [rsp+0x50],0x12
    lea    rax,[rip + ref_30_strlit]
    mov    QWORD PTR [rsp+0x58],rax
    lea    rdx,[rsp+0x3c]
    lea    r8,[rsp+0x50]
    mov    rcx,rdi
    call   ref_29_for_write_seq_lis_xmit
    mov    DWORD PTR [rsp+0x28],0x0
    mov    DWORD PTR [rsp+0x20],0x0
    lea    rcx,[rip + ref_31_strlit_11]
    xor    edx,edx
    xor    r8d,r8d
    mov    r9,rsi
    call   ref_32_for_stop_core_quiet
    jmp    at_1_014b
at_1_013f:
    lea    rax,[rip + ref_26_T2]
    movsxd rax,DWORD PTR [rax+rbx*4-0x4]
at_1_014b:
    add    rsp,0xa0
    pop    rbx
    pop    rdi
    pop    rsi
    ret
at_1_0156:
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
def_33_I1MCR1:
at_1_0160:
    mov    rax,QWORD PTR [rsp+0x28]
    mov    r8,QWORD PTR [r8]
    shl    r8,0x18
    add    r8,QWORD PTR [r9]
    mov    QWORD PTR [rdx],r8
    shl    r8,0x18
    add    r8,QWORD PTR [rax]
    mov    QWORD PTR [rcx],r8
    ret
at_1_017d:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_25_I1MACH_SC:
at_3_0000:
    .zero 32
def_26_T2:
at_3_0020:
    .zero 16
at_3_0030:
    .zero 16
at_3_0040:
    .zero 8
at_3_0048:
    .zero 16
at_3_0058:
    .zero 8
at_3_0060:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_0000003500000080ffffff8300000018:
at_4_0000:
    .quad 0xffffff8300000018
    .quad 0x0000003500000080
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_00000006000000070000000600000005:
at_5_0000:
    .quad 0x0000000600000005
    .quad 0x0000000600000007
at_5_0010:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_xmm_0000001f000000020000000400000020:
at_6_0000:
    .quad 0x0000000400000020
    .quad 0x0000001f00000002
at_6_0010:
end_s6:

# .xdata  (COFF section 7)
.section .s7,"dr"
def_15_xdata:
at_7_0000:
    .byte 0x01    # version 1
    .byte at_1_000a - at_1_0000    # prologue size
    .byte 0x05    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000a - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x14
    .byte 0x00
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte 0x00
    .byte 0x00
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_17_rdata:
def_30_strlit:
at_8_0000:
    .quad 0x2074756f20736920    # binary64 2.44141049951849e-152
    .quad 0x646e756f6220666f    # binary64 6.026696098525067e+175
    .short 0x2e73
def_27_strlit_1:
at_8_0012:
    .quad 0x49284843414d3149    # binary64 2.707564275355158e+44
    .long 0x49203a29
    .short 0x3d20
def_31_strlit_11:
at_8_0020:
end_s8:

# .drectve  (COFF section 9)
.section .s9,"dr"
def_19_drectve:
at_9_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_9_00b9:
end_s9:

# .pdata  (COFF section 10)
.section .s10,"dr"
def_21_pdata:
at_10_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0156 - def_0_text)    # image-relative end
    .long ref_15_xdata    # image-relative unwind info
at_10_000c:
end_s10:

# MEMBER dv7vmp.obj
# Entry points: DV7VMP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV7VMP:
at_1_0000:
    mov    rax,QWORD PTR [rsp+0x28]
    cmp    QWORD PTR [rax],0x0
    mov    rax,QWORD PTR [rcx]
    js     at_1_003b
    test   rax,rax
    jle    at_1_0069
    xor    ecx,ecx
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0020:
    movsd  xmm0,QWORD PTR [r8+rcx*8]
    mulsd  xmm0,QWORD PTR [r9+rcx*8]
    movsd  QWORD PTR [rdx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0020
    jmp    at_1_0069
at_1_003b:
    test   rax,rax
    jle    at_1_0069
    xor    ecx,ecx
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0050:
    movsd  xmm0,QWORD PTR [r8+rcx*8]
    divsd  xmm0,QWORD PTR [r9+rcx*8]
    movsd  QWORD PTR [rdx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0050
at_1_0069:
    ret
at_1_006a:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER dv7shf.obj
# Entry points: DV7SHF
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV7SHF:
at_1_0000:
    mov    rdx,QWORD PTR [rdx]
    mov    rax,QWORD PTR [rcx]
    cmp    rdx,rax
    jge    at_1_0040
    movsd  xmm0,QWORD PTR [r8+rdx*8-0x8]
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0020:
    movsd  xmm1,QWORD PTR [r8+rdx*8]
    movsd  QWORD PTR [r8+rdx*8-0x8],xmm1
    lea    rcx,[rdx+0x1]
    mov    rdx,rcx
    cmp    rax,rcx
    jne    at_1_0020
    movsd  QWORD PTR [r8+rax*8-0x8],xmm0
at_1_0040:
    ret
at_1_0041:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER dv7scp.obj
# Entry points: DV7SCP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV7SCP:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_001d
    movsd  xmm0,QWORD PTR [r8]
    xor    ecx,ecx
    nop
at_1_0010:
    movsd  QWORD PTR [rdx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0010
at_1_001d:
    ret
at_1_001e:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER dv7scl.obj
# Entry points: DV7SCL
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV7SCL:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_0027
    movsd  xmm0,QWORD PTR [r8]
    xor    ecx,ecx
    nop
at_1_0010:
    movsd  xmm1,QWORD PTR [r9+rcx*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rdx+rcx*8],xmm1
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0010
at_1_0027:
    ret
at_1_0028:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER dv7ipr.obj
# Entry points: DV7IPR
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV7IPR:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_0082
    mov    ecx,0x1
    jmp    at_1_002c
at_1_000f:
    neg    r9
    mov    QWORD PTR [rdx+rcx*8-0x8],r9
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0020:
    lea    r9,[rcx+0x1]
    cmp    rcx,rax
    mov    rcx,r9
    je     at_1_0082
at_1_002c:
    mov    r9,QWORD PTR [rdx+rcx*8-0x8]
    cmp    r9,rcx
    je     at_1_0020
    test   r9,r9
    jle    at_1_000f
    movsd  xmm0,QWORD PTR [r8+rcx*8-0x8]
    mov    r10,rcx
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0050:
    mov    r11,r10
    mov    r10,r9
    movsd  xmm1,QWORD PTR [r8+r9*8-0x8]
    movsd  QWORD PTR [r8+r11*8-0x8],xmm1
    mov    r9,QWORD PTR [rdx+r9*8-0x8]
    mov    r11,r9
    neg    r11
    mov    QWORD PTR [rdx+r10*8-0x8],r11
    cmp    r9,rcx
    jg     at_1_0050
    movsd  QWORD PTR [r8+r10*8-0x8],xmm0
    jmp    at_1_0020
at_1_0082:
    ret
at_1_0083:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER dv7dfl.obj
# Entry points: DV7DFL
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_36_DV7DFL:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    push   rbx
at_1_0003:
    sub    rsp,0x40
at_1_0007:
    movaps XMMWORD PTR [rsp+0x30],xmm7
at_1_000c:
    movaps XMMWORD PTR [rsp+0x20],xmm6
at_1_0011:
    mov    rsi,r8
    mov    rdi,rcx
    lea    rcx,[rip + ref_37_unnamed_1]
    call   ref_38_DR7MDC
    movapd xmm6,xmm0
    movabs rax,0x3bc79ca10c924223
    mov    QWORD PTR [rsi+0xf0],rax
    ucomisd xmm0,QWORD PTR [rip + ref_8_real_3ddb7cdfd9d7bdbb]
    jbe    at_1_0052
    movapd xmm0,xmm6
    mulsd  xmm0,xmm6
    movsd  QWORD PTR [rsi+0xf0],xmm0
at_1_0052:
    movabs rbx,0x3fe0000000000000
    mov    QWORD PTR [rsi+0xa8],rbx
    lea    rcx,[rip + ref_39_unnamed_2]
    call   ref_38_DR7MDC
    movapd xmm7,xmm0
    movabs rax,0x3fe3333333333333
    mov    QWORD PTR [rsi+0x140],rax
    movabs rax,0x3eb0c6f7a0b5ed8d
    mov    QWORD PTR [rsi+0x130],rax
    movsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    divsd  xmm1,QWORD PTR [rip + ref_14_real_4008000000000000]
    movapd xmm0,xmm6
    call   ref_40_pow
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rsi+0x138],rax
    movabs rcx,0x3fb999999999999a
    mov    QWORD PTR [rsi+0x90],rcx
    movabs rdx,0x4000000000000000
    mov    QWORD PTR [rsi+0xb0],rdx
    mov    QWORD PTR [rsi+0x110],rax
    mov    QWORD PTR [rsi+0x118],rax
    movabs rax,0xbfb999999999999a
    mov    QWORD PTR [rsi+0x98],rax
    mov    QWORD PTR [rsi+0xa0],rcx
    mov    QWORD PTR [rsi+0xb8],rcx
    movabs rax,0x4010000000000000
    movapd xmm1,xmm0
    mulsd  xmm1,xmm0
    maxsd  xmm1,QWORD PTR [rip + ref_8_real_3ddb7cdfd9d7bdbb]
    mov    QWORD PTR [rsi+0xc0],rax
    movsd  QWORD PTR [rsi+0xf8],xmm1
    movsd  QWORD PTR [rsi+0x120],xmm1
    mov    QWORD PTR [rsi+0xc8],rcx
    movabs rax,0x3f1a36e2eb1c432d
    mov    QWORD PTR [rsi+0xd0],rax
    movabs rax,0x3fe8000000000000
    mov    QWORD PTR [rsi+0xd8],rax
    mov    QWORD PTR [rsi+0xe0],rbx
    mov    QWORD PTR [rsi+0xe8],rax
    movsd  QWORD PTR [rsi+0x100],xmm7
    movsd  xmm1,QWORD PTR [rip + ref_17_real_4059000000000000]
    mulsd  xmm1,xmm6
    movsd  QWORD PTR [rsi+0x108],xmm1
    cmp    QWORD PTR [rdi],0x2
    jl     at_1_01d0
    movabs rax,0x3fe999999999999a
    mov    QWORD PTR [rsi+0x150],rax
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rsi+0x128],rax
    movsd  xmm0,QWORD PTR [rip + ref_26_real_408f400000000000]
    mulsd  xmm0,xmm6
    mov    eax,0x29
    {disp32} jmp    at_1_0263
at_1_01d0:
    movsd  xmm1,QWORD PTR [rip + ref_17_real_4059000000000000]
    mulsd  xmm1,xmm6
    maxsd  xmm1,QWORD PTR [rip + ref_20_real_3eb0c6f7a0b5ed8d]
    movsd  QWORD PTR [rsi+0x170],xmm1
    mov    QWORD PTR [rsi+0x128],0x0
    movsd  QWORD PTR [rsi+0x158],xmm7
    movsd  QWORD PTR [rsi+0x148],xmm0
    movsd  QWORD PTR [rsi+0x150],xmm7
    movabs rax,0x3ff8000000000000
    mov    QWORD PTR [rsi+0x160],rax
    movabs rax,0x3fe6666666666666
    mov    QWORD PTR [rsi+0x178],rax
    lea    rcx,[rip + ref_41_unnamed_3]
    call   ref_38_DR7MDC
    movsd  QWORD PTR [rsi+0x168],xmm0
    movabs rax,0x3f50624dd2f1a9fc
    mov    QWORD PTR [rsi+0x180],rax
    movsd  xmm0,QWORD PTR [rip + ref_23_real_3f1a36e2eb1c432d]
    mov    eax,0x31
at_1_0263:
    movsd  QWORD PTR [rsi+rax*8],xmm0
    movaps xmm6,XMMWORD PTR [rsp+0x20]
    movaps xmm7,XMMWORD PTR [rsp+0x30]
    add    rsp,0x40
    pop    rbx
    pop    rdi
    pop    rsi
    ret
at_1_027a:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ddb7cdfd9d7bdbb:
at_4_0000:
    .quad 0x3ddb7cdfd9d7bdbb    # binary64 1e-10
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_4008000000000000:
at_6_0000:
    .quad 0x4008000000000000    # binary64 3.0
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_real_4059000000000000:
at_7_0000:
    .quad 0x4059000000000000    # binary64 100.0
at_7_0008:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_3eb0c6f7a0b5ed8d:
at_8_0000:
    .quad 0x3eb0c6f7a0b5ed8d    # binary64 1e-06
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_3f1a36e2eb1c432d:
at_9_0000:
    .quad 0x3f1a36e2eb1c432d    # binary64 0.0001
at_9_0008:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_24_rdata:
def_26_real_408f400000000000:
at_10_0000:
    .quad 0x408f400000000000    # binary64 1000.0
at_10_0008:
end_s10:

# .xdata  (COFF section 11)
.section .s11,"dr"
def_27_xdata:
at_11_0000:
    .byte 0x01    # version 1
    .byte at_1_0011 - at_1_0000    # prologue size
    .byte 0x08    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0011 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x02
    .byte 0x00
    .byte at_1_000c - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x03
    .byte 0x00
    .byte at_1_0007 - at_1_0000    # ALLOC_SMALL
    .byte 0x72
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
at_11_0014:
end_s11:

# .rdata  (COFF section 12)
.section .s12,"dr"
def_29_rdata:
def_37_unnamed_1:
at_12_0000:
    .quad 0x0000000000000003
def_39_unnamed_2:
at_12_0008:
    .quad 0x0000000000000004
def_41_unnamed_3:
at_12_0010:
    .quad 0x0000000000000005
at_12_0018:
end_s12:

# .drectve  (COFF section 13)
.section .s13,"dr"
def_31_drectve:
at_13_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_13_00b9:
end_s13:

# .pdata  (COFF section 14)
.section .s14,"dr"
def_33_pdata:
at_14_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_027a - def_0_text)    # image-relative end
    .long ref_27_xdata    # image-relative unwind info
at_14_000c:
end_s14:

# MEMBER dv7cpy.obj
# Entry points: DV7CPY
.intel_syntax noprefix
# Copy doubles. Counts above 12 take the Intel memcpy path.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV7CPY:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_0043
    cmp    rax,0xc
    jbe    at_1_0020
    shl    rax,0x3
    mov    rcx,rdx
    mov    rdx,r8
    mov    r8,rax
    jmp    ref_10_intel_fast_memcpy
at_1_0020:
    xor    ecx,ecx
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0030:
    movsd  xmm0,QWORD PTR [r8+rcx*8]
    movsd  QWORD PTR [rdx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0030
at_1_0043:
    ret
at_1_0044:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER dv2nrm.obj
# Entry points: DV2NRM
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_21_DV2NRM:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    push   rbx
at_1_0003:
    sub    rsp,0x30
at_1_0007:
    movapd XMMWORD PTR [rsp+0x20],xmm6
at_1_000d:
    mov    rsi,QWORD PTR [rcx]
    test   rsi,rsi
    jle    at_1_003b
    xor    edi,edi
    xorpd  xmm1,xmm1
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0020:
    movsd  xmm0,QWORD PTR [rdx+rdi*8]
    inc    rdi
    ucomisd xmm1,xmm0
    setnp  al
    sete   cl
    test   cl,al
    je     at_1_004c
    cmp    rdi,rsi
    jl     at_1_0020
at_1_003b:
    xorpd  xmm0,xmm0
at_1_003f:
    movaps xmm6,XMMWORD PTR [rsp+0x20]
    add    rsp,0x30
    pop    rbx
    pop    rdi
    pop    rsi
    ret
at_1_004c:
    andpd  xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    cmp    rdi,rsi
    jge    at_1_003f
    movsd  xmm1,QWORD PTR [rip + ref_22_DV2NRM_SQTETA]
    xorpd  xmm2,xmm2
    ucomisd xmm2,xmm1
    setp   al
    setne  cl
    or     cl,al
    jne    at_1_0099
    lea    rcx,[rip + ref_23_unnamed_1]
    mov    rbx,rdx
    movapd xmm6,xmm0
    call   ref_24_DR7MDC
    mov    rdx,rbx
    movapd xmm1,xmm0
    movapd xmm0,xmm6
    movsd  QWORD PTR [rip + ref_22_DV2NRM_SQTETA],xmm1
at_1_0099:
    movsd  xmm2,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    movapd xmm3,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    movapd xmm4,xmm2
    jmp    at_1_00c8
    nop
at_1_00b0:
    mulsd  xmm4,xmm6
    mulsd  xmm4,xmm6
    addsd  xmm4,xmm2
    movapd xmm0,xmm5
at_1_00c0:
    inc    rdi
    cmp    rdi,rsi
    jge    at_1_0104
at_1_00c8:
    movsd  xmm5,QWORD PTR [rdx+rdi*8]
    andpd  xmm5,xmm3
    ucomisd xmm5,xmm0
    jbe    at_1_00f0
    divsd  xmm0,xmm5
    ucomisd xmm1,xmm0
    xorpd  xmm6,xmm6
    jae    at_1_00b0
    movapd xmm6,xmm0
    jmp    at_1_00b0
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_00f0:
    divsd  xmm5,xmm0
    ucomisd xmm5,xmm1
    jbe    at_1_00c0
    mulsd  xmm5,xmm5
    addsd  xmm4,xmm5
    jmp    at_1_00c0
at_1_0104:
    xorps  xmm1,xmm1
    sqrtsd xmm1,xmm4
    mulsd  xmm0,xmm1
    {disp32} jmp    at_1_003f
at_1_0114:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_22_DV2NRM_SQTETA:
at_3_0000:
    .zero 8
at_3_0008:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .xdata  (COFF section 6)
.section .s6,"dr"
def_12_xdata:
at_6_0000:
    .byte 0x01    # version 1
    .byte at_1_000d - at_1_0000    # prologue size
    .byte 0x06    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000d - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x02
    .byte 0x00
    .byte at_1_0007 - at_1_0000    # ALLOC_SMALL
    .byte 0x52
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
at_6_0010:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_14_rdata:
def_23_unnamed_1:
at_7_0000:
    .quad 0x0000000000000002
at_7_0008:
end_s7:

# .drectve  (COFF section 8)
.section .s8,"dr"
def_16_drectve:
at_8_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_8_00b9:
end_s8:

# .pdata  (COFF section 9)
.section .s9,"dr"
def_18_pdata:
at_9_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0114 - def_0_text)    # image-relative end
    .long ref_12_xdata    # image-relative unwind info
at_9_000c:
end_s9:

# MEMBER dv2axy.obj
# Entry points: DV2AXY
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_9_DV2AXY:
at_1_0000:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_003e
    mov    rcx,QWORD PTR [rsp+0x28]
    movsd  xmm0,QWORD PTR [r8]
    xor    r8d,r8d
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0020:
    movsd  xmm1,QWORD PTR [r9+r8*8]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rcx+r8*8]
    movsd  QWORD PTR [rdx+r8*8],xmm1
    inc    r8
    cmp    rax,r8
    jne    at_1_0020
at_1_003e:
    ret
at_1_003f:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .drectve  (COFF section 4)
.section .s4,"dr"
def_6_drectve:
at_4_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_4_00b9:
end_s4:

# MEMBER ds7lvm.obj
# Entry points: DS7LVM
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DS7LVM:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r12
at_1_0006:
    push   rsi
at_1_0007:
    push   rdi
at_1_0008:
    push   rbx
at_1_0009:
    sub    rsp,0x28
at_1_000d:
    mov    r15,QWORD PTR [rcx]
    mov    QWORD PTR [rsp+0x20],0x1
    test   r15,r15
    {disp32} jle    at_1_00d4
    mov    rsi,r9
    mov    rdi,r8
    mov    rbx,rdx
    mov    r12d,0x1
    lea    r14,[rsp+0x20]
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0040:
    lea    rdx,[rdi+r12*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    mov    r8,rsi
    call   ref_14_DD7TPR
    mov    rax,QWORD PTR [rsp+0x20]
    movsd  QWORD PTR [rbx+rax*8-0x8],xmm0
    add    r12,rax
    lea    rcx,[rax+0x1]
    mov    QWORD PTR [rsp+0x20],rcx
    cmp    rax,r15
    jl     at_1_0040
    cmp    r15,0x1
    je     at_1_00d4
    add    rdi,0x8
    mov    edx,0x2
    mov    eax,0x10
    mov    ecx,0x1
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0090:
    movsd  xmm0,QWORD PTR [rsi+rdx*8-0x8]
    xor    r8d,r8d
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_00a0:
    movsd  xmm1,QWORD PTR [rdi+r8*8]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rbx+r8*8]
    movsd  QWORD PTR [rbx+r8*8],xmm1
    inc    r8
    cmp    rcx,r8
    jne    at_1_00a0
    lea    r8,[rdx+0x1]
    add    rdi,rax
    add    rax,0x8
    inc    rcx
    cmp    rdx,r15
    mov    rdx,r8
    jne    at_1_0090
at_1_00d4:
    add    rsp,0x28
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r12
    pop    r14
    pop    r15
    ret
at_1_00e2:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000d - at_1_0000    # prologue size
    .byte 0x07    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000d - at_1_0000    # ALLOC_SMALL
    .byte 0x42
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0007 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_4_0014:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00e2 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER ds7lup.obj
# Entry points: DS7LUP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_22_DS7LUP:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x58
at_1_0010:
    movaps XMMWORD PTR [rsp+0x40],xmm8
at_1_0016:
    movaps XMMWORD PTR [rsp+0x30],xmm7
at_1_001b:
    movaps XMMWORD PTR [rsp+0x20],xmm6
at_1_0020:
    mov    r15,r9
    mov    rbx,r8
    mov    rdi,rdx
    mov    rsi,rcx
    mov    r13,QWORD PTR [rsp+0xe0]
    mov    r12,QWORD PTR [rsp+0xd8]
    mov    r14,QWORD PTR [rsp+0xc0]
    mov    rcx,r8
    mov    rdx,r14
    mov    r8,r12
    call   ref_23_DD7TPR
    movapd xmm6,xmm0
    movsd  xmm8,QWORD PTR [rdi]
    mov    rcx,rbx
    mov    rdx,r14
    call   ref_24_DV2NRM
    movapd xmm7,xmm0
    mulsd  xmm7,xmm8
    mov    rcx,rbx
    mov    rdx,r12
    call   ref_24_DV2NRM
    mulsd  xmm0,xmm7
    movabs rax,0x3ff0000000000000
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    mov    QWORD PTR [r13+0x0],rax
    setnp  al
    sete   cl
    test   cl,al
    jne    at_1_00be
    movapd xmm2,xmm6
    divsd  xmm2,xmm0
    andpd  xmm2,XMMWORD PTR [rip + ref_11_xmm_7fffffffffffffff7fffffffffffffff]
    minsd  xmm2,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movsd  QWORD PTR [r13+0x0],xmm2
    jmp    at_1_00c6
at_1_00be:
    movsd  xmm2,QWORD PTR [rip + ref_8_real_3ff0000000000000]
at_1_00c6:
    ucomisd xmm6,xmm1
    setnp  al
    sete   cl
    test   cl,al
    jne    at_1_00dc
    divsd  xmm2,xmm6
    movapd xmm1,xmm2
at_1_00dc:
    mov    r13,QWORD PTR [rsp+0xe8]
    mov    rbp,QWORD PTR [rsp+0xd0]
    mov    rdi,QWORD PTR [rsp+0xc8]
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_0118
    xor    ecx,ecx
    xchg   ax,ax
at_1_0100:
    movsd  xmm0,QWORD PTR [r12+rcx*8]
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [rbp+rcx*8+0x0],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0100
at_1_0118:
    mov    rcx,rbx
    mov    rdx,rdi
    mov    r8,rsi
    mov    r9,r14
    call   ref_25_DS7LVM
    movsd  xmm7,QWORD PTR [r15]
    mov    rcx,rbx
    mov    rdx,r14
    mov    r8,rdi
    call   ref_23_DD7TPR
    movapd xmm6,xmm0
    mulsd  xmm6,xmm7
    mov    rcx,rbx
    mov    rdx,r14
    mov    r8,r13
    call   ref_23_DD7TPR
    subsd  xmm6,xmm0
    mulsd  xmm6,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    {disp32} jle    at_1_020b
    xor    ecx,ecx
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_0170:
    movsd  xmm0,QWORD PTR [rbp+rcx*8+0x0]
    mulsd  xmm0,xmm6
    addsd  xmm0,QWORD PTR [r13+rcx*8+0x0]
    movsd  xmm1,QWORD PTR [rdi+rcx*8]
    mulsd  xmm1,xmm7
    subsd  xmm0,xmm1
    movsd  QWORD PTR [rdi+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0170
    inc    rax
    mov    ecx,0x1
    mov    r8d,0x2
    mov    edx,0x8
    xchg   ax,ax
at_1_01b0:
    movsd  xmm0,QWORD PTR [rdi+rcx*8-0x8]
    movsd  xmm1,QWORD PTR [rbp+rcx*8-0x8]
    xor    r9d,r9d
    nop
at_1_01c0:
    movsd  xmm2,QWORD PTR [rsi+r9*8]
    mulsd  xmm2,xmm7
    movsd  xmm3,QWORD PTR [rbp+r9*8+0x0]
    mulsd  xmm3,xmm0
    addsd  xmm3,xmm2
    movsd  xmm2,QWORD PTR [rdi+r9*8]
    mulsd  xmm2,xmm1
    addsd  xmm2,xmm3
    movsd  QWORD PTR [rsi+r9*8],xmm2
    inc    r9
    cmp    rcx,r9
    jne    at_1_01c0
    inc    rcx
    lea    r9,[r8+0x1]
    add    rsi,rdx
    add    rdx,0x8
    cmp    r8,rax
    mov    r8,r9
    jne    at_1_01b0
at_1_020b:
    movaps xmm6,XMMWORD PTR [rsp+0x20]
    movaps xmm7,XMMWORD PTR [rsp+0x30]
    movaps xmm8,XMMWORD PTR [rsp+0x40]
    add    rsp,0x58
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_022c:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_7fffffffffffffff7fffffffffffffff:
at_5_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_5_0010:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fe0000000000000:
at_6_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_6_0008:
end_s6:

# .xdata  (COFF section 7)
.section .s7,"dr"
def_15_xdata:
at_7_0000:
    .byte 0x01    # version 1
    .byte at_1_0020 - at_1_0000    # prologue size
    .byte 0x0f    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0020 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x02
    .byte 0x00
    .byte at_1_001b - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x03
    .byte 0x00
    .byte at_1_0016 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x04
    .byte 0x00
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0xa2
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_7_0024:
end_s7:

# .drectve  (COFF section 8)
.section .s8,"dr"
def_17_drectve:
at_8_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_8_00b9:
end_s8:

# .pdata  (COFF section 9)
.section .s9,"dr"
def_19_pdata:
at_9_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_022c - def_0_text)    # image-relative end
    .long ref_15_xdata    # image-relative unwind info
at_9_000c:
end_s9:

# MEMBER ds7ipr.obj
# Entry points: DS7IPR
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DS7IPR:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    {disp32} jle    at_1_01c9
    mov    rcx,rax
    neg    rcx
    mov    r9d,0x1
    jmp    at_1_0040
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0030:
    lea    r10,[r9+0x1]
    cmp    r9,rax
    mov    r9,r10
    {disp32} je     at_1_01c9
at_1_0040:
    mov    r10,QWORD PTR [rdx+r9*8-0x8]
    cmp    r10,r9
    je     at_1_0030
    mov    r11,r10
    neg    r11
    cmovs  r11,r10
    mov    QWORD PTR [rdx+r9*8-0x8],r11
    test   r10,r10
    js     at_1_0030
    mov    r11,r9
    jmp    at_1_008b
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0070:
    mov    rsi,QWORD PTR [rdx+r10*8-0x8]
    mov    r11,rsi
    neg    r11
    mov    QWORD PTR [rdx+r10*8-0x8],r11
    mov    r11,r10
    mov    r10,rsi
    cmp    rsi,r9
    jle    at_1_0030
at_1_008b:
    mov    rdi,r10
    sub    rdi,r11
    neg    rdi
    mov    rsi,r10
    sub    rsi,r11
    cmovle rsi,rdi
    mov    r15,r11
    cmovl  r15,r10
    cmovg  r11,r10
    lea    rbx,[r15-0x1]
    mov    r12,rbx
    imul   r12,r15
    shr    r12,1
    lea    rdi,[r11-0x1]
    mov    r14,rdi
    imul   r14,r11
    shr    r14,1
    cmp    r15,0x2
    jge    at_1_00d0
    mov    r15,r12
    jmp    at_1_0105
at_1_00d0:
    lea    r15,[rbx+r12*1]
    lea    r12,[r8+r12*8]
    lea    r13,[r8+r14*8]
    xor    ebp,ebp
    xchg   ax,ax
at_1_00e0:
    movsd  xmm0,QWORD PTR [r12+rbp*8]
    movsd  xmm1,QWORD PTR [r13+rbp*8+0x0]
    movsd  QWORD PTR [r12+rbp*8],xmm1
    movsd  QWORD PTR [r13+rbp*8+0x0],xmm0
    inc    rbp
    cmp    rbx,rbp
    jne    at_1_00e0
    add    r14,rbx
at_1_0105:
    movsd  xmm0,QWORD PTR [r8+r15*8]
    lea    r12,[r14+rsi*1]
    movsd  xmm1,QWORD PTR [r8+r12*8]
    movsd  QWORD PTR [r8+r15*8],xmm1
    movsd  QWORD PTR [r8+r12*8],xmm0
    cmp    rsi,0x2
    jl     at_1_0168
    inc    r15
    lea    r12,[r8+r14*8]
    mov    r13d,0x1
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0140:
    add    r15,rbx
    add    r15,r13
    movsd  xmm0,QWORD PTR [r8+r15*8-0x8]
    movsd  xmm1,QWORD PTR [r12+r13*8]
    movsd  QWORD PTR [r8+r15*8-0x8],xmm1
    movsd  QWORD PTR [r12+r13*8],xmm0
    inc    r13
    cmp    rsi,r13
    jne    at_1_0140
at_1_0168:
    cmp    r11,rax
    {disp32} jge    at_1_0070
    lea    rbx,[r14+rsi*1]
    inc    rbx
    not    rsi
    add    r11,rcx
    mov    r14d,0x1
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0190:
    add    rbx,rdi
    add    rbx,r14
    lea    r15,[rbx+rsi*1]
    movsd  xmm0,QWORD PTR [r8+r15*8]
    movsd  xmm1,QWORD PTR [r8+rbx*8-0x8]
    movsd  QWORD PTR [r8+r15*8],xmm1
    movsd  QWORD PTR [r8+rbx*8-0x8],xmm0
    lea    r15,[r11+r14*1]
    inc    r15
    inc    r14
    cmp    r15,0x1
    jne    at_1_0190
    {disp32} jmp    at_1_0070
at_1_01c9:
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_01d6:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000c - at_1_0000    # prologue size
    .byte 0x08    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0014:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_01d6 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER ds7dmp.obj
# Entry points: DS7DMP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_16_DS7DMP:
at_1_0000:
    push   rsi
at_1_0001:
    mov    rax,QWORD PTR [rsp+0x30]
    cmp    QWORD PTR [rax],0x0
    mov    rax,QWORD PTR [rcx]
    js     at_1_0078
    test   rax,rax
    {disp32} jle    at_1_00e6
    inc    rax
    mov    ecx,0x1
    mov    r10d,0x2
    mov    r11d,0x8
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_0030:
    movsd  xmm0,QWORD PTR [r9+rcx*8-0x8]
    xor    esi,esi
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0040:
    movsd  xmm1,QWORD PTR [r8+rsi*8]
    mulsd  xmm1,xmm0
    mulsd  xmm1,QWORD PTR [r9+rsi*8]
    movsd  QWORD PTR [rdx+rsi*8],xmm1
    inc    rsi
    cmp    rcx,rsi
    jne    at_1_0040
    inc    rcx
    lea    rsi,[r10+0x1]
    add    r8,r11
    add    rdx,r11
    add    r11,0x8
    cmp    r10,rax
    mov    r10,rsi
    jne    at_1_0030
    jmp    at_1_00e6
at_1_0078:
    test   rax,rax
    jle    at_1_00e6
    inc    rax
    mov    ecx,0x1
    mov    r10d,0x2
    mov    r11d,0x8
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_00a0:
    movapd xmm1,xmm0
    divsd  xmm1,QWORD PTR [r9+rcx*8-0x8]
    xor    esi,esi
    nop    DWORD PTR [rax]
at_1_00b0:
    movsd  xmm2,QWORD PTR [r8+rsi*8]
    mulsd  xmm2,xmm1
    divsd  xmm2,QWORD PTR [r9+rsi*8]
    movsd  QWORD PTR [rdx+rsi*8],xmm2
    inc    rsi
    cmp    rcx,rsi
    jne    at_1_00b0
    inc    rcx
    lea    rsi,[r10+0x1]
    add    r8,r11
    add    rdx,r11
    add    r11,0x8
    cmp    r10,rax
    mov    r10,rsi
    jne    at_1_00a0
at_1_00e6:
    pop    rsi
    ret
at_1_00e8:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_0001 - at_1_0000    # prologue size
    .byte 0x01    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte 0x00
    .byte 0x00
at_5_0008:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_11_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_13_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00e8 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER ds7bqn.obj
# Entry points: DS7BQN
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_30_DS7BQN:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x118
at_1_0013:
    movapd XMMWORD PTR [rsp+0x100],xmm15
at_1_001d:
    movaps XMMWORD PTR [rsp+0xf0],xmm14
at_1_0026:
    movaps XMMWORD PTR [rsp+0xe0],xmm13
at_1_002f:
    movaps XMMWORD PTR [rsp+0xd0],xmm12
at_1_0038:
    movaps XMMWORD PTR [rsp+0xc0],xmm11
at_1_0041:
    movaps XMMWORD PTR [rsp+0xb0],xmm10
at_1_004a:
    movaps XMMWORD PTR [rsp+0xa0],xmm9
at_1_0053:
    movaps XMMWORD PTR [rsp+0x90],xmm8
at_1_005c:
    movapd XMMWORD PTR [rsp+0x80],xmm7
at_1_0065:
    movaps XMMWORD PTR [rsp+0x70],xmm6
at_1_006a:
    mov    rdi,r9
    mov    rbx,r8
    mov    rbp,rdx
    mov    r14,rcx
    mov    rax,QWORD PTR [rsp+0x1d8]
    mov    r11,QWORD PTR [rsp+0x1b0]
    movsd  xmm8,QWORD PTR [rip + ref_31_DS7BQN_ONE]
    movsd  xmm9,QWORD PTR [rax+0xa0]
    addsd  xmm9,xmm8
    mulsd  xmm9,QWORD PTR [rip + ref_8_real_3ff00068db8bac71]
    movsd  xmm0,QWORD PTR [rax+0x38]
    mulsd  xmm9,xmm0
    addsd  xmm8,QWORD PTR [rax+0x98]
    mulsd  xmm8,xmm0
    movsd  xmm14,QWORD PTR [rip + ref_32_DS7BQN_ZERO]
    ucomisd xmm14,QWORD PTR [rip + ref_33_DS7BQN_MEPS2]
    jb     at_1_00f4
    lea    rcx,[rip + ref_34_unnamed_1]
    mov    rsi,r11
    call   ref_35_DR7MDC
    mov    r11,rsi
    mulsd  xmm0,QWORD PTR [rip + ref_11_real_4000000000000000]
    movsd  QWORD PTR [rip + ref_33_DS7BQN_MEPS2],xmm0
at_1_00f4:
    mov    r10,QWORD PTR [rsp+0x188]
    mov    r8,QWORD PTR [rsp+0x180]
    mov    rax,QWORD PTR [rsp+0x1b8]
    mov    r9,QWORD PTR [rax]
    mov    QWORD PTR [rsp+0x68],r9
    mov    rax,QWORD PTR [rsp+0x1a8]
    mov    QWORD PTR [rax],0x0
    mov    rax,QWORD PTR [r11]
    test   rax,rax
    jle    at_1_015a
    neg    rax
    mov    ecx,0x1
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0140:
    mov    QWORD PTR [r8+rcx*8-0x8],rcx
    mov    QWORD PTR [r10+rcx*8-0x8],rcx
    lea    rdx,[rax+rcx*1]
    inc    rdx
    inc    rcx
    cmp    rdx,0x1
    jne    at_1_0140
at_1_015a:
    mov    r13,QWORD PTR [rsp+0x1e0]
    mov    rcx,QWORD PTR [rsp+0x1c8]
    mov    rdx,QWORD PTR [rsp+0x1c0]
    mov    r8,QWORD PTR [rsp+0x190]
    test   r9,r9
    jle    at_1_01ad
    xor    eax,eax
    movapd xmm0,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0190:
    movsd  xmm1,QWORD PTR [rdx+rax*8]
    mulsd  xmm1,QWORD PTR [rcx+rax*8]
    xorpd  xmm1,xmm0
    movlpd QWORD PTR [r13+rax*8+0x0],xmm1
    inc    rax
    cmp    r9,rax
    jne    at_1_0190
at_1_01ad:
    mov    QWORD PTR [rsp+0x40],r9
    mov    rax,QWORD PTR [rsp+0x1d8]
    movsd  xmm6,QWORD PTR [rax+0x18]
    movsd  xmm10,QWORD PTR [rax+0x20]
    andpd  xmm10,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm11,QWORD PTR [rip + ref_32_DS7BQN_ZERO]
    movsd  QWORD PTR [rax+0x30],xmm11
    xorpd  xmm6,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    cmp    QWORD PTR [r8],0x0
    jns    at_1_0209
    mov    rsi,r8
    lea    r8,[rip + ref_32_DS7BQN_ZERO]
    mov    rcx,r11
    mov    rdx,rbx
    mov    r15,r11
    call   ref_36_DV7SCP
    mov    r11,r15
    mov    r8,rsi
at_1_0209:
    mov    QWORD PTR [rsp+0x30],rbx
    mov    r10,QWORD PTR [rsp+0x1e8]
    mov    r15,QWORD PTR [rsp+0x1d0]
    mov    QWORD PTR [r8],0x1
    xor    eax,eax
    mov    QWORD PTR [rsp+0x38],rax
    movapd xmm12,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movsd  xmm13,QWORD PTR [rip + ref_20_real_3fe0000000000000]
    mov    rbx,QWORD PTR [rsp+0x1b8]
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0250:
    movsd  xmm15,QWORD PTR [rip + ref_31_DS7BQN_ONE]
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    {disp32} jle    at_1_0340
    mov    rcx,rax
    neg    rcx
    mov    edx,0x1
    xor    r12d,r12d
    mov    rsi,QWORD PTR [rsp+0x30]
    jmp    at_1_0294
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0280:
    lea    r9,[rcx+rdx*1]
    inc    r9
    inc    rdx
    cmp    r9,0x1
    {disp32} je     at_1_0330
at_1_0294:
    mov    r8,QWORD PTR [rdi+rdx*8-0x8]
    movsd  xmm1,QWORD PTR [r13+rdx*8-0x8]
    divsd  xmm1,QWORD PTR [rbp+r8*8-0x8]
    lea    r9,[r8-0x1]
    movsd  xmm0,QWORD PTR [r10+r8*8-0x8]
    movapd xmm2,xmm0
    subsd  xmm2,xmm1
    shl    r9,0x4
    movsd  xmm3,QWORD PTR [r14+r9*1]
    ucomisd xmm3,xmm2
    jbe    at_1_02f0
    subsd  xmm0,xmm3
    divsd  xmm0,xmm1
    mov    r12,rdx
    neg    r12
    ucomisd xmm0,xmm15
    jae    at_1_0280
    jmp    at_1_031f
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_02f0:
    lea    r9,[r8*2-0x2]
    movsd  xmm3,QWORD PTR [r14+r9*8+0x8]
    ucomisd xmm3,xmm2
    {disp32} jae    at_1_0280
    subsd  xmm0,xmm3
    divsd  xmm0,xmm1
    mov    r12,rdx
    ucomisd xmm0,xmm15
    {disp32} jae    at_1_0280
at_1_031f:
    movapd xmm15,xmm0
    {disp32} jmp    at_1_0280
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0330:
    mov    QWORD PTR [rsp+0x48],r8
    jmp    at_1_0348
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0340:
    xor    r12d,r12d
    mov    rsi,QWORD PTR [rsp+0x30]
at_1_0348:
    mov    rcx,QWORD PTR [r11]
    sub    rcx,rax
    jle    at_1_036f
    mov    rdx,QWORD PTR [rsp+0x1c0]
    lea    rdx,[rdx+rax*8]
    lea    r8,[rsi+rax*8]
    mov    QWORD PTR [rsp+0x60],rcx
    lea    rcx,[rsp+0x60]
    call   ref_37_DV7CPY
at_1_036f:
    movapd xmm0,xmm15
    xorpd  xmm0,xmm12
    movlpd QWORD PTR [rsp+0x58],xmm0
    mov    QWORD PTR [rsp+0x20],rsi
    mov    rbx,QWORD PTR [rsp+0x1b8]
    mov    rcx,rbx
    mov    r13,QWORD PTR [rsp+0x1c0]
    mov    rdx,r13
    lea    r8,[rsp+0x58]
    mov    r9,QWORD PTR [rsp+0x1e0]
    call   ref_38_DV2AXY
    mov    rcx,QWORD PTR [rsp+0x1b0]
    mov    rdx,r13
    call   ref_39_DV2NRM
    movapd xmm7,xmm0
    ucomisd xmm9,xmm0
    jae    at_1_03e5
    mov    rax,QWORD PTR [rsp+0x40]
    cmp    QWORD PTR [rbx],rax
    {disp32} jl     at_1_0636
    xor    r12d,r12d
    mov    r13,QWORD PTR [rsp+0x1c0]
    mov    rsi,QWORD PTR [rsp+0x30]
at_1_03e5:
    mov    rax,QWORD PTR [rsp+0x1d8]
    movsd  QWORD PTR [rax+0x8],xmm7
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,r13
    call   ref_37_DV7CPY
    movsd  xmm14,QWORD PTR [rip + ref_31_DS7BQN_ONE]
    movapd xmm0,xmm14
    subsd  xmm0,xmm15
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_0438
    xor    ecx,ecx
    nop    DWORD PTR [rax]
at_1_0420:
    movsd  xmm1,QWORD PTR [r15+rcx*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [r15+rcx*8],xmm1
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0420
at_1_0438:
    ucomisd xmm10,QWORD PTR [rip + ref_32_DS7BQN_ZERO]
    mov    rsi,QWORD PTR [rsp+0x1e0]
    jbe    at_1_047c
    movapd xmm0,xmm15
    mulsd  xmm0,xmm10
    movsd  QWORD PTR [rsp+0x50],xmm0
    mov    QWORD PTR [rsp+0x20],r15
    mov    rcx,rbx
    mov    rdx,r15
    lea    r8,[rsp+0x50]
    mov    r9,rsi
    call   ref_38_DV2AXY
    movsd  xmm14,QWORD PTR [rip + ref_31_DS7BQN_ONE]
at_1_047c:
    movapd xmm0,xmm13
    mulsd  xmm0,xmm15
    subsd  xmm14,xmm0
    mulsd  xmm14,xmm6
    movapd xmm6,xmm10
    mulsd  xmm6,xmm15
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,rsi
    call   ref_40_DD7TPR
    mulsd  xmm0,xmm6
    mulsd  xmm0,xmm13
    addsd  xmm0,xmm14
    mulsd  xmm0,xmm15
    addsd  xmm11,xmm0
    mov    rax,QWORD PTR [rsp+0x1d8]
    movsd  QWORD PTR [rax+0x30],xmm11
    test   r12,r12
    {disp32} je     at_1_0605
    mov    r13,QWORD PTR [rbx]
    mov    rax,r12
    neg    rax
    cmovs  rax,r12
    mov    QWORD PTR [rsp+0x48],rax
    cmp    rax,r13
    {disp32} je     at_1_058a
    mov    r8,QWORD PTR [rsp+0x38]
    inc    r8
    mov    rcx,QWORD PTR [rsp+0x1a8]
    mov    QWORD PTR [rsp+0x38],r8
    mov    QWORD PTR [rcx],r8
    mov    rcx,QWORD PTR [rsp+0x188]
    mov    QWORD PTR [rcx+r13*8-0x8],rax
    mov    rax,QWORD PTR [rsp+0x1e0]
    mov    QWORD PTR [rsp+0x28],rax
    mov    rax,QWORD PTR [rsp+0x198]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rsi,[rsp+0x48]
    mov    rcx,rsi
    mov    rdx,rbx
    lea    r8,[rip + ref_41_unnamed_2]
    mov    r9,r15
    call   ref_42_DQ7RSH
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,rdi
    call   ref_43_I7SHFT
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,QWORD PTR [rsp+0x180]
    call   ref_43_I7SHFT
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,r15
    call   ref_44_DV7SHF
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,QWORD PTR [rsp+0x30]
    call   ref_44_DV7SHF
at_1_058a:
    test   r12,r12
    jns    at_1_0597
    mov    rax,QWORD PTR [rbx]
    neg    QWORD PTR [rdi+rax*8-0x8]
at_1_0597:
    lea    rax,[r13-0x1]
    mov    QWORD PTR [rbx],rax
    cmp    r13,0x2
    jl     at_1_0605
    mov    rcx,rbx
    mov    rsi,QWORD PTR [rsp+0x1e0]
    mov    rdx,rsi
    mov    r12,QWORD PTR [rsp+0x198]
    mov    r8,r12
    mov    r9,r15
    call   ref_45_DL7IVM
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,rsi
    call   ref_40_DD7TPR
    movapd xmm6,xmm0
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,r12
    mov    r9,rsi
    call   ref_46_DL7ITV
    movapd xmm14,xmm7
    mov    r11,QWORD PTR [rsp+0x1b0]
    mov    r13,rsi
    mov    r10,QWORD PTR [rsp+0x1e8]
    {disp32} jmp    at_1_0250
at_1_0605:
    mov    r13,QWORD PTR [rsp+0x1b0]
    mov    r10,QWORD PTR [rsp+0x40]
    mov    r9,QWORD PTR [rsp+0x1c0]
    mov    r11,QWORD PTR [rsp+0x30]
    mov    rdx,QWORD PTR [rsp+0x1e8]
    mov    r14,QWORD PTR [rsp+0x38]
    mov    r15,QWORD PTR [rsp+0x1f0]
    jmp    at_1_067b
at_1_0636:
    ucomisd xmm8,xmm14
    jbe    at_1_064c
    mov    rax,QWORD PTR [rsp+0x190]
    mov    QWORD PTR [rax],0x0
at_1_064c:
    mov    r10,QWORD PTR [rsp+0x40]
    mov    r9,QWORD PTR [rsp+0x1c0]
    mov    r11,QWORD PTR [rsp+0x30]
    mov    rdx,QWORD PTR [rsp+0x1e8]
    mov    r14,QWORD PTR [rsp+0x38]
    mov    r15,QWORD PTR [rsp+0x1f0]
    mov    r13,QWORD PTR [rsp+0x1b0]
at_1_067b:
    mov    r12,r13
    mov    rax,QWORD PTR [r13+0x0]
    test   rax,rax
    jle    at_1_06be
    xor    ecx,ecx
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0690:
    mov    r8,QWORD PTR [rdi+rcx*8]
    mov    rsi,r8
    neg    rsi
    cmovs  rsi,r8
    movsd  xmm0,QWORD PTR [r11+rcx*8]
    divsd  xmm0,QWORD PTR [rbp+rsi*8-0x8]
    movsd  QWORD PTR [r9+rsi*8-0x8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0690
    mov    QWORD PTR [rsp+0x48],rsi
at_1_06be:
    mov    rax,QWORD PTR [rbx]
    cmp    rax,r10
    mov    rcx,r12
    jge    at_1_0743
    movsd  xmm0,QWORD PTR [rip + ref_33_DS7BQN_MEPS2]
    movapd xmm1,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    xorpd  xmm1,xmm0
    movapd xmm2,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    jmp    at_1_0728
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_06f0:
    movapd xmm3,xmm0
at_1_06f4:
    inc    rax
    movsd  xmm4,QWORD PTR [rdx+r8*8-0x8]
    andpd  xmm4,xmm2
    movsd  xmm5,QWORD PTR [r15+r8*8-0x8]
    andpd  xmm5,xmm2
    maxsd  xmm4,xmm5
    mulsd  xmm4,xmm3
    addsd  xmm4,QWORD PTR [r9+r8*8-0x8]
    movsd  QWORD PTR [r9+r8*8-0x8],xmm4
    cmp    r10,rax
    je     at_1_073e
at_1_0728:
    mov    r8,QWORD PTR [rdi+rax*8]
    test   r8,r8
    jg     at_1_06f0
    neg    r8
    mov    QWORD PTR [rdi+rax*8],r8
    movapd xmm3,xmm1
    jmp    at_1_06f4
at_1_073e:
    mov    QWORD PTR [rsp+0x48],r8
at_1_0743:
    mov    QWORD PTR [rsp+0x20],r15
    lea    r8,[rip + ref_31_DS7BQN_ONE]
    call   ref_38_DV2AXY
    test   r14,r14
    jle    at_1_0773
    lea    rcx,[rsp+0x68]
    mov    rdx,QWORD PTR [rsp+0x180]
    mov    r8,QWORD PTR [rsp+0x1c8]
    call   ref_47_DV7IPR
at_1_0773:
    movaps xmm6,XMMWORD PTR [rsp+0x70]
    movaps xmm7,XMMWORD PTR [rsp+0x80]
    movaps xmm8,XMMWORD PTR [rsp+0x90]
    movaps xmm9,XMMWORD PTR [rsp+0xa0]
    movaps xmm10,XMMWORD PTR [rsp+0xb0]
    movaps xmm11,XMMWORD PTR [rsp+0xc0]
    movaps xmm12,XMMWORD PTR [rsp+0xd0]
    movaps xmm13,XMMWORD PTR [rsp+0xe0]
    movaps xmm14,XMMWORD PTR [rsp+0xf0]
    movaps xmm15,XMMWORD PTR [rsp+0x100]
    add    rsp,0x118
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_07dc:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_31_DS7BQN_ONE:
at_2_0000:
    .quad 0x3ff0000000000000
at_2_0008:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_32_DS7BQN_ZERO:
at_3_0000:
    .zero 8
def_33_DS7BQN_MEPS2:
at_3_0008:
    .zero 8
at_3_0010:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff00068db8bac71:
at_4_0000:
    .quad 0x3ff00068db8bac71    # binary64 1.0001
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_4000000000000000:
at_5_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_xmm_80000000000000008000000000000000:
at_6_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_6_0010:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_7fffffffffffffff7fffffffffffffff:
at_7_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_3fe0000000000000:
at_8_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_8_0008:
end_s8:

# .xdata  (COFF section 9)
.section .s9,"dr"
def_21_xdata:
at_9_0000:
    .byte 0x01    # version 1
    .byte at_1_006a - at_1_0000    # prologue size
    .byte 0x1e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_006a - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x07
    .byte 0x00
    .byte at_1_0065 - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x08
    .byte 0x00
    .byte at_1_005c - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x09
    .byte 0x00
    .byte at_1_0053 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x0a
    .byte 0x00
    .byte at_1_004a - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x0b
    .byte 0x00
    .byte at_1_0041 - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x0c
    .byte 0x00
    .byte at_1_0038 - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x0d
    .byte 0x00
    .byte at_1_002f - at_1_0000    # SAVE_XMM128
    .byte 0xd8
    .byte 0x0e
    .byte 0x00
    .byte at_1_0026 - at_1_0000    # SAVE_XMM128
    .byte 0xe8
    .byte 0x0f
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xf8
    .byte 0x10
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x23
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_9_0040:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_23_rdata:
def_34_unnamed_1:
at_10_0000:
    .quad 0x0000000000000003
def_41_unnamed_2:
at_10_0008:
    .zero 8
at_10_0010:
end_s10:

# .drectve  (COFF section 11)
.section .s11,"dr"
def_25_drectve:
at_11_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_11_00b9:
end_s11:

# .pdata  (COFF section 12)
.section .s12,"dr"
def_27_pdata:
at_12_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_07dc - def_0_text)    # image-relative end
    .long ref_21_xdata    # image-relative unwind info
at_12_000c:
end_s12:

# MEMBER drn2gb.obj
# Entry points: DRN2GB
.intel_syntax noprefix
# Bound-constrained driver; calls DG7ITB, QR updates and DITSUM.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_18_DRN2GB:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0xb8
at_1_0013:
    movapd XMMWORD PTR [rsp+0xa0],xmm6
at_1_001c:
    mov    rdi,r9
    mov    r15,r8
    mov    QWORD PTR [rsp+0x60],rdx
    mov    QWORD PTR [rsp+0x70],rcx
    mov    r10,QWORD PTR [rsp+0x168]
    mov    r14,QWORD PTR [rsp+0x150]
    mov    rbx,QWORD PTR [rsp+0x138]
    mov    r9,QWORD PTR [rsp+0x120]
    mov    r12,QWORD PTR [rbx]
    mov    rax,QWORD PTR [r14]
    lea    rbp,[rax+0x1]
    imul   rbp,rax
    shr    rbp,1
    mov    QWORD PTR [rsp+0x98],rbp
    mov    rsi,QWORD PTR [rdi]
    test   rsi,rsi
    jne    at_1_00a1
    mov    QWORD PTR [rsp+0x20],r10
    lea    rcx,[rip + ref_19_unnamed_1]
    mov    rdx,rdi
    mov    r8,r9
    mov    r13,rbx
    mov    rbx,r9
    mov    r9,QWORD PTR [rsp+0x128]
    mov    rsi,r10
    call   ref_20_DIVSET
    mov    r9,rbx
    mov    rbx,r13
    mov    r10,rsi
    mov    rsi,QWORD PTR [rdi]
at_1_00a1:
    mov    rdx,QWORD PTR [rsp+0x158]
    mov    r13,QWORD PTR [rsp+0x148]
    mov    r8,QWORD PTR [rsp+0x140]
    mov    r11,QWORD PTR [rsp+0x130]
    cmp    rsi,0x3
    {disp32} jl     at_1_028d
    cmp    QWORD PTR [rbx],0x0
    {disp32} jle    at_1_0419
    mov    rax,QWORD PTR [r14]
    test   rax,rax
    {disp32} jle    at_1_0419
    cmp    QWORD PTR [r11],0x0
    {disp32} jle    at_1_0419
    cmp    rsi,0xe
    {disp32} jne    at_1_04c8
    mov    r12,QWORD PTR [rdi+0x1d0]
at_1_00fc:
    mov    rbx,r9
    movsd  xmm0,QWORD PTR [r10+0x128]
    xorpd  xmm6,xmm6
    ucomisd xmm0,xmm6
    jb     at_1_012c
    lea    r8,[r10+0x128]
    mov    rcx,r14
    mov    rdx,QWORD PTR [rsp+0x60]
    mov    rsi,r10
    call   ref_21_DV7SCP
    mov    r10,rsi
at_1_012c:
    movsd  xmm0,QWORD PTR [r10+0x130]
    ucomisd xmm0,xmm6
    jbe    at_1_0158
    lea    r8,[r10+0x130]
    lea    rdx,[r10+r12*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    mov    rsi,r10
    call   ref_21_DV7SCP
    mov    r10,rsi
at_1_0158:
    movsd  xmm0,QWORD PTR [r10+0x138]
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    jbe    at_1_018b
    lea    r8,[r10+0x138]
    add    r12,QWORD PTR [r14]
    lea    rdx,[r10+r12*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    mov    rsi,r10
    call   ref_21_DV7SCP
    mov    r10,rsi
at_1_018b:
    xorpd  xmm0,xmm0
    movupd XMMWORD PTR [rdi+0x218],xmm0
    mov    rax,QWORD PTR [rsp+0x138]
    mov    rax,QWORD PTR [rax]
    mov    rcx,QWORD PTR [rsp+0x130]
    cmp    rax,QWORD PTR [rcx]
    mov    r9,rbx
    {disp32} jge    at_1_02c6
    mov    rax,QWORD PTR [rdi+0xd8]
    mov    r14,QWORD PTR [rsp+0x150]
    mov    rcx,QWORD PTR [r14]
    add    rcx,rax
    lea    r15,[r10+rax*8]
    add    r15,0xfffffffffffffff8
    lea    rsi,[r10+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x50],rsi
    mov    rax,QWORD PTR [rsp+0x170]
    mov    QWORD PTR [rsp+0x48],rax
    mov    QWORD PTR [rsp+0x40],r10
    mov    QWORD PTR [rsp+0x38],r14
    mov    QWORD PTR [rsp+0x30],r14
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r9
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,QWORD PTR [rsp+0x60]
    mov    r8,r15
    mov    r9,rdi
    mov    rbp,r10
    call   ref_22_DG7ITB
    cmp    QWORD PTR [rdi],0x1
    {disp32} jne    at_1_07de
    mov    QWORD PTR [rbp+0x48],0x0
    lea    rbx,[rip + ref_23_unnamed_2]
    mov    rcx,r14
    mov    rdx,r15
    mov    r8,rbx
    call   ref_21_DV7SCP
    mov    QWORD PTR [rdi],0xffffffffffffffff
    mov    rax,QWORD PTR [rdi+0x260]
    lea    rdx,[rax*8-0x8]
    add    rdx,rbp
    mov    rcx,r14
    mov    r8,rbx
    call   ref_21_DV7SCP
    mov    QWORD PTR [rdi+0x210],0x0
    mov    rbp,QWORD PTR [rdi+0x268]
    mov    rbx,QWORD PTR [rsp+0x138]
    {disp32} jmp    at_1_0be1
at_1_028d:
    mov    rax,QWORD PTR [r13+0x0]
    mov    rbp,QWORD PTR [r8]
    mov    rcx,rax
    sub    rcx,rbp
    inc    rcx
    mov    QWORD PTR [rsp+0x68],rcx
    mov    QWORD PTR [rdi+0x40],0x0
    add    rsi,0x4
    cmp    QWORD PTR [rdi+0x8],0x0
    {disp32} je     at_1_0425
at_1_02b9:
    cmp    rsi,0x5
    je     at_1_02c6
    mov    QWORD PTR [rdi],0x2
at_1_02c6:
    mov    r14,r13
    lea    r12,[rdi+0xd8]
    mov    rax,QWORD PTR [rdi+0xd8]
    mov    rdx,QWORD PTR [rsp+0x150]
    mov    rcx,QWORD PTR [rdx]
    add    rcx,rax
    lea    rbp,[r10+rax*8]
    add    rbp,0xfffffffffffffff8
    lea    rsi,[r10+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x50],rsi
    mov    rax,QWORD PTR [rsp+0x170]
    mov    QWORD PTR [rsp+0x48],rax
    mov    QWORD PTR [rsp+0x40],r10
    mov    QWORD PTR [rsp+0x38],rdx
    mov    QWORD PTR [rsp+0x30],rdx
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x28],rax
    mov    rbx,r9
    mov    QWORD PTR [rsp+0x20],r9
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,QWORD PTR [rsp+0x60]
    mov    r8,rbp
    mov    r9,rdi
    mov    r13,r10
    call   ref_22_DG7ITB
    cmp    QWORD PTR [rdi],0x2
    jge    at_1_03b3
    mov    QWORD PTR [r13+0x48],0x0
    mov    rax,QWORD PTR [rdi+0x220]
    test   rax,rax
    mov    r11,QWORD PTR [rsp+0x130]
    mov    r13,r14
    mov    rbx,QWORD PTR [rsp+0x138]
    {disp32} je     at_1_0c1f
    cmp    QWORD PTR [rdi+0x40],0x2
    {disp32} jne    at_1_0c1f
    mov    QWORD PTR [rdi+0x218],rax
    mov    rcx,r11
    mov    rdx,QWORD PTR [rsp+0x160]
    mov    r8,QWORD PTR [rsp+0x158]
    call   ref_24_DV7CPY
    mov    r11,QWORD PTR [rsp+0x130]
    mov    QWORD PTR [rdi+0x210],0x0
    {disp32} jmp    at_1_0c1f
at_1_03b3:
    mov    r10,r13
    {disp32} jne    at_1_07e8
    lea    r8,[rip + ref_23_unnamed_2]
    mov    r12,QWORD PTR [rsp+0x150]
    mov    rcx,r12
    mov    rdx,rbp
    call   ref_21_DV7SCP
    cmp    QWORD PTR [rdi+0x110],0x0
    {disp32} jle    at_1_067e
    inc    QWORD PTR [rdi+0x198]
    mov    rax,QWORD PTR [rdi+0x28]
    inc    rax
    mov    QWORD PTR [rdi+0x28],rax
    mov    QWORD PTR [rdi+0x30],rax
    mov    QWORD PTR [rdi],0xffffffffffffffff
    mov    r11,QWORD PTR [rsp+0x130]
    mov    r13,r14
    mov    rbx,QWORD PTR [rsp+0x138]
    {disp32} jmp    at_1_0c1f
at_1_0419:
    mov    QWORD PTR [rdi],0x42
    {disp32} jmp    at_1_07fa
at_1_0425:
    cmp    esi,0x6
    {disp32} ja     at_1_02b9
    shl    r12,0x3
    mov    ecx,0x4a
    bt     ecx,esi
    {disp32} jb     at_1_05c1
    mov    ecx,0x30
    bt     ecx,esi
    {disp32} jae    at_1_0721
    mov    rbx,r9
    mov    rsi,r11
    lea    rcx,[rsp+0x68]
    mov    r14,r10
    call   ref_25_DV2NRM
    mov    r10,r14
    ucomisd xmm0,QWORD PTR [r14+0x168]
    {disp32} ja     at_1_085a
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_8_real_3fe0000000000000]
    addsd  xmm0,QWORD PTR [r10+0x48]
    movsd  QWORD PTR [r10+0x48],xmm0
    mov    rax,QWORD PTR [r13+0x0]
    mov    rcx,QWORD PTR [rsi]
    cmp    rax,rcx
    mov    r8,QWORD PTR [rsp+0x140]
    mov    r9,rbx
    mov    rbx,QWORD PTR [rsp+0x138]
    {disp32} jl     at_1_0c2c
    cmp    rbp,0x1
    {disp32} jne    at_1_02c6
    mov    rax,QWORD PTR [rdi+0x28]
    mov    QWORD PTR [rdi+0x220],rax
    {disp32} jmp    at_1_02c6
at_1_04c8:
    cmp    rsi,0x10
    {disp32} ja     at_1_07fa
    cmp    rsi,0xc
    {disp32} jb     at_1_02c6
    cmp    rsi,0xd
    mov    r14,QWORD PTR [rsp+0x150]
    je     at_1_04f7
    cmp    rsi,0xc
    jne    at_1_0506
    mov    QWORD PTR [rdi],0xd
at_1_04f7:
    lea    rcx,[rax+0xf]
    imul   rcx,rax
    shr    rcx,1
    add    QWORD PTR [rdi+0x18],rcx
at_1_0506:
    mov    r8,QWORD PTR [rsp+0x170]
    mov    QWORD PTR [rsp+0x50],r8
    mov    QWORD PTR [rsp+0x48],r8
    mov    QWORD PTR [rsp+0x40],r10
    mov    QWORD PTR [rsp+0x38],r14
    mov    QWORD PTR [rsp+0x30],r14
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r9
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,QWORD PTR [rsp+0x60]
    mov    rbx,r9
    mov    r9,rdi
    mov    r12,r10
    call   ref_22_DG7ITB
    cmp    QWORD PTR [rdi],0xe
    {disp32} jne    at_1_0c41
    mov    r9,rbx
    mov    r10,r12
    mov    rax,QWORD PTR [rdi+0x170]
    mov    QWORD PTR [rdi+0xd8],rax
    mov    rcx,QWORD PTR [r14]
    lea    rax,[rax+rcx*2]
    mov    QWORD PTR [rdi+0x208],rax
    add    rax,rcx
    mov    QWORD PTR [rdi+0x268],rax
    add    rax,rbp
    mov    QWORD PTR [rdi+0x260],rax
    lea    r12,[rax+rcx*2]
    mov    QWORD PTR [rdi+0x1d0],r12
    lea    rax,[r12+rcx*2]
    mov    QWORD PTR [rdi+0x170],rax
    mov    QWORD PTR [rdi+0x1c0],0x0
    cmp    rsi,0xd
    {disp32} jne    at_1_00fc
    {disp32} jmp    at_1_0c41
at_1_05c1:
    mov    rsi,QWORD PTR [rdi+0xd8]
    mov    rcx,QWORD PTR [rdi+0x110]
    mov    QWORD PTR [rsp+0x88],rcx
    test   rcx,rcx
    mov    QWORD PTR [rsp+0x80],rsi
    {disp32} js     at_1_0834
    {disp32} je     at_1_08a2
    mov    rcx,r13
    mov    QWORD PTR [rdi],0x2
    mov    r13,QWORD PTR [r14]
    test   r13,r13
    {disp32} jle    at_1_086a
    lea    rbx,[r10+rsi*8]
    add    rbx,0xfffffffffffffff8
    xor    r14d,r14d
    mov    rbp,r15
    mov    rsi,rdx
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0620:
    movsd  xmm6,QWORD PTR [rbx+r14*8]
    lea    rcx,[rsp+0x68]
    mov    rdx,rsi
    mov    r8,rbp
    call   ref_26_DD7TPR
    addsd  xmm0,xmm6
    movsd  QWORD PTR [rbx+r14*8],xmm0
    inc    r14
    add    rbp,r12
    cmp    r14,r13
    jl     at_1_0620
    mov    r14,QWORD PTR [rsp+0x148]
    mov    rax,QWORD PTR [r14]
    mov    rbx,QWORD PTR [rsp+0x138]
    mov    r8,QWORD PTR [rsp+0x140]
    mov    r13,r14
    mov    r11,QWORD PTR [rsp+0x130]
    mov    r10,QWORD PTR [rsp+0x168]
    {disp32} jmp    at_1_09fc
at_1_067e:
    mov    r13,QWORD PTR [rdi+0x260]
    mov    rbp,QWORD PTR [rdi+0x268]
    mov    rax,QWORD PTR [rsp+0x168]
    lea    rdx,[rax+r13*8]
    add    rdx,0xfffffffffffffff8
    add    r13,QWORD PTR [r12]
    lea    r8,[rip + ref_23_unnamed_2]
    mov    rcx,r12
    call   ref_21_DV7SCP
    mov    QWORD PTR [rdi+0x210],0x0
    mov    rbx,QWORD PTR [rsp+0x138]
    mov    rdx,QWORD PTR [rbx]
    mov    rax,QWORD PTR [rdi+0x110]
    mov    rcx,QWORD PTR [rsp+0x130]
    cmp    rdx,QWORD PTR [rcx]
    {disp32} jl     at_1_0bcb
    mov    rdx,QWORD PTR [rsp+0x140]
    cmp    QWORD PTR [rdx],0x1
    {disp32} jne    at_1_0bcb
    test   rax,rax
    {disp32} js     at_1_0bd6
    mov    rdx,QWORD PTR [rdi+0x30]
    cmp    QWORD PTR [rdi+0x220],rdx
    {disp32} jne    at_1_0b17
    mov    r12,QWORD PTR [rsp+0x160]
    mov    rdx,r12
    mov    r8,QWORD PTR [rsp+0x158]
    {disp32} jmp    at_1_0b37
at_1_0721:
    cmp    esi,0x2
    {disp32} jne    at_1_02b9
    mov    r14,QWORD PTR [r14]
    test   r14,r14
    jle    at_1_07b1
    mov    QWORD PTR [rsp+0x60],rbp
    mov    rax,QWORD PTR [rdi+0xd8]
    add    rax,r14
    lea    rbx,[r10+rax*8]
    add    rbx,0xfffffffffffffff8
    xor    r13d,r13d
    lea    rsi,[rsp+0x68]
    mov    rbp,rdx
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0760:
    movsd  xmm6,QWORD PTR [rbx+r13*8]
    mov    rcx,rsi
    mov    rdx,r15
    mov    r8,rbp
    call   ref_26_DD7TPR
    addsd  xmm0,xmm6
    movsd  QWORD PTR [rbx+r13*8],xmm0
    inc    r13
    add    r15,r12
    cmp    r13,r14
    jl     at_1_0760
    mov    rax,QWORD PTR [rsp+0x148]
    mov    rax,QWORD PTR [rax]
    mov    rbx,QWORD PTR [rsp+0x138]
    mov    r8,QWORD PTR [rsp+0x140]
    mov    r11,QWORD PTR [rsp+0x130]
    mov    rbp,QWORD PTR [rsp+0x60]
at_1_07b1:
    mov    rcx,QWORD PTR [r11]
    cmp    rax,rcx
    mov    r13,QWORD PTR [rsp+0x148]
    {disp32} jl     at_1_0c2c
    xor    eax,eax
    cmp    rbp,0x2
    setl   al
    lea    rax,[rax+rax*4]
    add    rax,0xfffffffffffffffd
    mov    QWORD PTR [rdi],rax
    {disp32} jmp    at_1_0c1f
at_1_07de:
    lea    r12,[rdi+0xd8]
    mov    r10,rbp
at_1_07e8:
    mov    rcx,QWORD PTR [r12]
    dec    rcx
    mov    r14,QWORD PTR [rsp+0x150]
    mov    r9,rbx
at_1_07fa:
    lea    rdx,[r10+rcx*8]
    mov    rax,QWORD PTR [rsp+0x170]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],r10
    mov    QWORD PTR [rsp+0x28],r14
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x60]
    mov    r8,rdi
    call   ref_27_DITSUM
    {disp32} jmp    at_1_0c41
at_1_0834:
    mov    rax,QWORD PTR [r11]
    cmp    rax,QWORD PTR [rbx]
    jle    at_1_08a2
    mov    rbx,r9
    lea    rcx,[rsp+0x68]
    mov    r14,r10
    call   ref_25_DV2NRM
    mov    r10,r14
    ucomisd xmm0,QWORD PTR [r14+0x168]
    jbe    at_1_0872
at_1_085a:
    mov    QWORD PTR [rdi+0x8],0x1
    mov    r9,rbx
    {disp32} jmp    at_1_02c6
at_1_086a:
    mov    r13,rcx
    {disp32} jmp    at_1_0a04
at_1_0872:
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_8_real_3fe0000000000000]
    addsd  xmm0,QWORD PTR [r10+0x48]
    movsd  QWORD PTR [r10+0x48],xmm0
    mov    r14,QWORD PTR [rsp+0x150]
    mov    rdx,QWORD PTR [rsp+0x158]
    mov    rbx,QWORD PTR [rsp+0x138]
at_1_08a2:
    cmp    QWORD PTR [rdi+0x78],0x0
    jle    at_1_0905
    mov    QWORD PTR [rsp+0x50],r10
    mov    QWORD PTR [rsp+0x48],r14
    mov    QWORD PTR [rsp+0x40],r13
    lea    rax,[rsp+0x68]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],rbx
    mov    rax,QWORD PTR [rsp+0x130]
    mov    QWORD PTR [rsp+0x28],rax
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x60]
    mov    r12,rdx
    mov    rdx,r15
    mov    r8,rdi
    mov    r9,QWORD PTR [rsp+0x120]
    mov    rsi,r10
    call   ref_28_DD7UPD
    mov    rdx,r12
    mov    r10,rsi
at_1_0905:
    mov    rax,QWORD PTR [rdi+0x260]
    mov    rsi,QWORD PTR [rdi+0x268]
    mov    QWORD PTR [rsp+0x78],rax
    lea    r9,[r10+rax*8]
    add    r9,0xfffffffffffffff8
    mov    r12,r10
    lea    rax,[r10+rsi*8-0x8]
    mov    QWORD PTR [rsp+0x38],rdx
    mov    QWORD PTR [rsp+0x30],r15
    mov    QWORD PTR [rsp+0x28],rax
    lea    rax,[rip + ref_29_unnamed_3]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x68]
    mov    rdx,rbx
    mov    r8,r14
    call   ref_30_DQ7RAD
    mov    QWORD PTR [rdi+0x220],0x0
    mov    rax,QWORD PTR [r13+0x0]
    mov    r11,QWORD PTR [rsp+0x130]
    cmp    rbp,0x1
    jle    at_1_0975
    mov    r10,r12
    jmp    at_1_09f4
at_1_0975:
    mov    rcx,QWORD PTR [r11]
    cmp    rax,rcx
    mov    r8,QWORD PTR [rsp+0x140]
    mov    r9,QWORD PTR [rsp+0x120]
    {disp32} jl     at_1_0c2c
    mov    rcx,QWORD PTR [rsp+0x150]
    mov    rcx,QWORD PTR [rcx]
    test   rcx,rcx
    {disp32} jle    at_1_0c5d
    lea    rdx,[rsi-0x1]
    mov    r8,QWORD PTR [rsp+0x78]
    add    r8,rcx
    neg    rcx
    mov    r10,r12
    lea    r8,[r12+r8*8]
    mov    r9d,0x1
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_09d0:
    add    rdx,r9
    movsd  xmm0,QWORD PTR [r10+rdx*8-0x8]
    movsd  QWORD PTR [r8+r9*8-0x10],xmm0
    lea    r10,[rcx+r9*1]
    inc    r10
    inc    r9
    cmp    r10,0x1
    mov    r10,r12
    jne    at_1_09d0
at_1_09f4:
    mov    r8,QWORD PTR [rsp+0x140]
at_1_09fc:
    mov    r9,QWORD PTR [rsp+0x120]
at_1_0a04:
    mov    rcx,QWORD PTR [r11]
    cmp    rax,rcx
    {disp32} jl     at_1_0c2c
    mov    rax,QWORD PTR [rsp+0x88]
    test   rax,rax
    {disp32} jg     at_1_02c6
    mov    r12,rax
    mov    rax,QWORD PTR [rdi+0x30]
    mov    QWORD PTR [rdi+0x280],rax
    mov    rax,QWORD PTR [rsp+0x80]
    lea    rbp,[r10+rax*8]
    add    rbp,0xfffffffffffffff8
    lea    r8,[r10+rsi*8-0x8]
    mov    rbx,r9
    mov    rax,QWORD PTR [rsp+0x78]
    lea    r9,[r10+rax*8-0x8]
    mov    rcx,QWORD PTR [rsp+0x150]
    mov    rdx,rbp
    mov    rsi,r11
    mov    r14,r10
    call   ref_31_DL7VML
    mov    r9,rbx
    mov    r10,r14
    mov    QWORD PTR [rdi],0x2
    test   r12,r12
    {disp32} je     at_1_02c6
    mov    rax,QWORD PTR [rsi]
    mov    rcx,QWORD PTR [rsp+0x138]
    cmp    rax,QWORD PTR [rcx]
    {disp32} jle    at_1_02c6
    mov    rcx,QWORD PTR [rsp+0x150]
    mov    rax,QWORD PTR [rsp+0x80]
    add    rax,QWORD PTR [rcx]
    mov    QWORD PTR [rdi],0x1
    lea    rax,[r10+rax*8]
    add    rax,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x50],rax
    mov    rax,QWORD PTR [rsp+0x170]
    mov    QWORD PTR [rsp+0x48],rax
    mov    QWORD PTR [rsp+0x40],r10
    mov    QWORD PTR [rsp+0x38],rcx
    mov    QWORD PTR [rsp+0x30],rcx
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r9
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,QWORD PTR [rsp+0x60]
    mov    r8,rbp
    mov    r9,rdi
    call   ref_22_DG7ITB
    mov    r9,rbx
    mov    r10,r14
    cmp    QWORD PTR [rdi],0x2
    {disp32} je     at_1_02c6
    lea    r12,[rdi+0xd8]
    {disp32} jmp    at_1_07e8
at_1_0b17:
    cmp    QWORD PTR [rdi+0x218],rdx
    {disp32} jne    at_1_0bcb
    mov    rdx,QWORD PTR [rsp+0x158]
    mov    r12,QWORD PTR [rsp+0x160]
    mov    r8,r12
at_1_0b37:
    call   ref_24_DV7CPY
    lea    rax,[rip + ref_32_unnamed_4]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r12
    mov    rcx,rbx
    mov    rdx,QWORD PTR [rsp+0x130]
    mov    r12,QWORD PTR [rsp+0x150]
    mov    r8,r12
    mov    r9,r15
    call   ref_33_DQ7APL
    mov    rax,QWORD PTR [rsp+0x130]
    mov    rax,QWORD PTR [rax]
    mov    rcx,QWORD PTR [r12]
    cmp    rax,rcx
    cmovl  rcx,rax
    mov    rax,QWORD PTR [rsp+0x168]
    lea    r9,[rax+r13*8-0x8]
    mov    QWORD PTR [rsp+0x90],rcx
    mov    rax,QWORD PTR [rsp+0x160]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r15
    lea    rdx,[rsp+0x90]
    mov    rcx,rbx
    mov    r8,rsi
    call   ref_34_DR7TVM
    mov    QWORD PTR [rdi+0x210],0x0
    mov    r13,r14
    jmp    at_1_0bf3
at_1_0bcb:
    sar    rax,0x3f
    add    rax,0xfffffffffffffffe
    mov    QWORD PTR [rdi],rax
at_1_0bd6:
    mov    r13,r14
    mov    r14,QWORD PTR [rsp+0x150]
at_1_0be1:
    lea    r8,[rip + ref_23_unnamed_2]
    mov    rcx,r14
    mov    rdx,rsi
    call   ref_21_DV7SCP
at_1_0bf3:
    mov    rax,QWORD PTR [rsp+0x168]
    lea    rdx,[rax+rbp*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[rip + ref_23_unnamed_2]
    lea    rcx,[rsp+0x98]
    call   ref_21_DV7SCP
    mov    r11,QWORD PTR [rsp+0x130]
at_1_0c1f:
    mov    rcx,QWORD PTR [r11]
    xor    eax,eax
    mov    r8,QWORD PTR [rsp+0x140]
at_1_0c2c:
    lea    rdx,[rax+0x1]
    mov    QWORD PTR [r8],rdx
    add    rax,QWORD PTR [rbx]
    cmp    rax,rcx
    cmovge rax,rcx
    mov    QWORD PTR [r13+0x0],rax
at_1_0c41:
    movaps xmm6,XMMWORD PTR [rsp+0xa0]
    add    rsp,0xb8
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0c5d:
    mov    r10,r12
    {disp32} jmp    at_1_0a04
at_1_0c65:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3fe0000000000000:
at_4_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_001c - at_1_0000    # prologue size
    .byte 0x0c    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0a
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x17
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_5_001c:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_11_rdata:
def_19_unnamed_1:
at_6_0000:
    .quad 0x0000000000000001
def_32_unnamed_4:
at_6_0008:
    .zero 8
def_23_unnamed_2:
at_6_0010:
    .zero 8
def_29_unnamed_3:
at_6_0018:
    .quad 0xffffffffffffffff
at_6_0020:
end_s6:

# .drectve  (COFF section 7)
.section .s7,"dr"
def_13_drectve:
at_7_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_7_00b9:
end_s7:

# .pdata  (COFF section 8)
.section .s8,"dr"
def_15_pdata:
at_8_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0c65 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_8_000c:
end_s8:

# MEMBER drn2g.obj
# Entry points: DRN2G
.intel_syntax noprefix
# Unconstrained reverse-communication driver; calls DG7LIT, QR updates and the reporting routines.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_18_DRN2G:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0xb8
at_1_0013:
    movapd XMMWORD PTR [rsp+0xa0],xmm6
at_1_001c:
    mov    r15,r9
    mov    rdi,r8
    mov    rbp,rdx
    mov    QWORD PTR [rsp+0x70],rcx
    mov    r10,QWORD PTR [rsp+0x160]
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r12,QWORD PTR [rsp+0x130]
    mov    rbx,QWORD PTR [r12]
    mov    rax,QWORD PTR [r11]
    lea    rsi,[rax+0x1]
    imul   rsi,rax
    shr    rsi,1
    mov    QWORD PTR [rsp+0x78],rsi
    mov    r13,QWORD PTR [r8]
    test   r13,r13
    jne    at_1_0093
    mov    QWORD PTR [rsp+0x20],r10
    lea    rcx,[rip + ref_19_unnamed_1]
    mov    rdx,rdi
    mov    r8,r15
    mov    r9,QWORD PTR [rsp+0x120]
    call   ref_20_DIVSET
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
    mov    r13,QWORD PTR [rdi]
at_1_0093:
    mov    r9,QWORD PTR [rsp+0x168]
    mov    rdx,QWORD PTR [rsp+0x150]
    mov    r8,QWORD PTR [rsp+0x140]
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    r14,QWORD PTR [rsp+0x128]
    cmp    r13,0x3
    {disp32} jl     at_1_02c0
    cmp    QWORD PTR [r12],0x0
    {disp32} jle    at_1_03ce
    mov    rax,QWORD PTR [r11]
    test   rax,rax
    {disp32} jle    at_1_03ce
    cmp    QWORD PTR [r14],0x0
    {disp32} jle    at_1_03ce
    cmp    r13,0xe
    {disp32} jne    at_1_04ae
    mov    rsi,QWORD PTR [rdi+0x1d0]
at_1_00f7:
    mov    r10,QWORD PTR [rsp+0x160]
    movsd  xmm0,QWORD PTR [r10+0x128]
    xorpd  xmm6,xmm6
    ucomisd xmm0,xmm6
    jb     at_1_0139
    lea    r8,[r10+0x128]
    mov    rcx,QWORD PTR [rsp+0x148]
    mov    rdx,QWORD PTR [rsp+0x70]
    mov    rbx,r9
    call   ref_21_DV7SCP
    mov    r9,rbx
    mov    r10,QWORD PTR [rsp+0x160]
at_1_0139:
    movsd  xmm0,QWORD PTR [r10+0x130]
    ucomisd xmm0,xmm6
    mov    r11,QWORD PTR [rsp+0x148]
    jbe    at_1_017d
    lea    r8,[r10+0x130]
    lea    rdx,[r10+rsi*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r11
    mov    rbx,r9
    call   ref_21_DV7SCP
    mov    r9,rbx
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
at_1_017d:
    mov    r12,r15
    movsd  xmm0,QWORD PTR [r10+0x138]
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    jbe    at_1_01c3
    lea    r8,[r10+0x138]
    add    rsi,QWORD PTR [r11]
    lea    rdx,[r10+rsi*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r11
    mov    rsi,r9
    call   ref_21_DV7SCP
    mov    r9,rsi
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
at_1_01c3:
    xorpd  xmm0,xmm0
    movupd XMMWORD PTR [rdi+0x218],xmm0
    mov    rax,QWORD PTR [rsp+0x130]
    mov    rax,QWORD PTR [rax]
    cmp    rax,QWORD PTR [r14]
    {disp32} jge    at_1_0303
    mov    rax,QWORD PTR [rdi+0xd8]
    mov    rcx,QWORD PTR [rdi+0x178]
    lea    rsi,[r10+rax*8]
    add    rsi,0xfffffffffffffff8
    lea    rbx,[r10+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x48],rbx
    mov    QWORD PTR [rsp+0x40],r9
    mov    QWORD PTR [rsp+0x38],r10
    mov    QWORD PTR [rsp+0x30],r11
    mov    QWORD PTR [rsp+0x28],r11
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,rsi
    mov    r8,rdi
    mov    r15,r9
    mov    r9,r12
    call   ref_22_DG7LIT
    mov    r9,r15
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
    mov    rax,QWORD PTR [rdi]
    cmp    rax,0x1
    {disp32} jne    at_1_0c9b
    mov    QWORD PTR [r10+0x48],0x0
    lea    r15,[rip + ref_23_unnamed_2]
    mov    rcx,r11
    mov    rdx,rsi
    mov    r8,r15
    mov    r13,r10
    mov    rbp,r11
    call   ref_21_DV7SCP
    mov    QWORD PTR [rdi],0xffffffffffffffff
    mov    rax,QWORD PTR [rdi+0x260]
    lea    rdx,[rax*8-0x8]
    add    rdx,r13
    mov    rcx,rbp
    mov    r8,r15
    call   ref_21_DV7SCP
    mov    QWORD PTR [rdi+0x210],0x0
    mov    rsi,QWORD PTR [rdi+0x268]
    mov    r12,QWORD PTR [rsp+0x130]
    {disp32} jmp    at_1_0af8
at_1_02c0:
    mov    rax,QWORD PTR [r8]
    mov    r14,QWORD PTR [rcx]
    mov    rcx,rax
    sub    rcx,r14
    inc    rcx
    mov    QWORD PTR [rsp+0x68],rcx
    mov    QWORD PTR [rdi+0x40],0x0
    add    r13,0x4
    cmp    QWORD PTR [rdi+0x8],0x0
    {disp32} je     at_1_043b
at_1_02eb:
    mov    r12,r15
    cmp    r13,0x5
    mov    r14,QWORD PTR [rsp+0x128]
    je     at_1_0303
    mov    QWORD PTR [rdi],0x2
at_1_0303:
    mov    rax,QWORD PTR [rdi+0xd8]
    mov    rcx,QWORD PTR [rdi+0x178]
    lea    rsi,[r10+rax*8]
    add    rsi,0xfffffffffffffff8
    lea    rbx,[r10+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x48],rbx
    mov    r15,r9
    mov    QWORD PTR [rsp+0x40],r9
    mov    QWORD PTR [rsp+0x38],r10
    mov    QWORD PTR [rsp+0x30],r11
    mov    QWORD PTR [rsp+0x28],r11
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,rsi
    mov    r8,rdi
    mov    r9,r12
    mov    r13,r10
    call   ref_22_DG7LIT
    mov    rax,QWORD PTR [rdi]
    cmp    rax,0x2
    jge    at_1_03da
    mov    QWORD PTR [r13+0x48],0x0
    mov    rax,QWORD PTR [rdi+0x220]
    test   rax,rax
    mov    r8,QWORD PTR [rsp+0x140]
    mov    r12,QWORD PTR [rsp+0x130]
    {disp32} je     at_1_0b2e
    cmp    QWORD PTR [rdi+0x40],0x2
    {disp32} jne    at_1_0b2e
    mov    QWORD PTR [rdi+0x218],rax
    mov    rcx,r14
    mov    rdx,QWORD PTR [rsp+0x158]
    mov    rsi,r8
    mov    r8,QWORD PTR [rsp+0x150]
    call   ref_24_DV7CPY
    mov    r8,rsi
    mov    QWORD PTR [rdi+0x210],0x0
    {disp32} jmp    at_1_0b2e
at_1_03ce:
    mov    QWORD PTR [rdi],0x42
    {disp32} jmp    at_1_0cc0
at_1_03da:
    mov    r10,r13
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r9,r15
    {disp32} jne    at_1_0c9b
    lea    r8,[rip + ref_23_unnamed_2]
    mov    rcx,r11
    mov    rdx,rsi
    mov    r15,r11
    call   ref_21_DV7SCP
    cmp    QWORD PTR [rdi+0x110],0x0
    mov    r12,QWORD PTR [rsp+0x130]
    {disp32} jle    at_1_071b
at_1_0419:
    inc    QWORD PTR [rdi+0x198]
    mov    rax,QWORD PTR [rdi+0x28]
    inc    rax
    mov    QWORD PTR [rdi+0x28],rax
    mov    QWORD PTR [rdi+0x30],rax
    mov    QWORD PTR [rdi],0xffffffffffffffff
    {disp32} jmp    at_1_0b26
at_1_043b:
    cmp    r13d,0x6
    {disp32} ja     at_1_02eb
    shl    rbx,0x3
    mov    ecx,0x4a
    bt     ecx,r13d
    {disp32} jb     at_1_05b4
    mov    ecx,0x30
    bt     ecx,r13d
    {disp32} jae    at_1_07ae
    mov    rsi,r9
    lea    rcx,[rsp+0x68]
    call   ref_25_DV2NRM
    mov    r10,QWORD PTR [rsp+0x160]
    ucomisd xmm0,QWORD PTR [r10+0x168]
    {disp32} jbe    at_1_08d5
at_1_048b:
    mov    r12,r15
    mov    QWORD PTR [rdi+0x8],0x1
    mov    r14,QWORD PTR [rsp+0x128]
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r9,rsi
    {disp32} jmp    at_1_0303
at_1_04ae:
    cmp    r13,0x10
    {disp32} ja     at_1_0cc0
    mov    r12,r15
    cmp    r13,0xc
    {disp32} jb     at_1_0303
    cmp    r13,0xd
    mov    r15,r12
    je     at_1_04db
    cmp    r13,0xc
    jne    at_1_04ee
    mov    QWORD PTR [rdi],0xd
at_1_04db:
    add    QWORD PTR [rdi+0x10],rax
    lea    rcx,[rax+0xd]
    imul   rcx,rax
    shr    rcx,1
    add    QWORD PTR [rdi+0x18],rcx
at_1_04ee:
    mov    QWORD PTR [rsp+0x48],r9
    mov    QWORD PTR [rsp+0x40],r9
    mov    QWORD PTR [rsp+0x38],r10
    mov    QWORD PTR [rsp+0x30],r11
    mov    QWORD PTR [rsp+0x28],r11
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,r9
    mov    r8,rdi
    mov    rbx,r9
    mov    r9,r15
    call   ref_22_DG7LIT
    cmp    QWORD PTR [rdi],0xe
    {disp32} jne    at_1_0d28
    mov    r9,rbx
    mov    rax,QWORD PTR [rdi+0x168]
    mov    rcx,QWORD PTR [rdi+0x170]
    mov    QWORD PTR [rdi+0x258],rax
    mov    rdx,QWORD PTR [rsp+0x148]
    mov    rdx,QWORD PTR [rdx]
    add    rax,rdx
    mov    QWORD PTR [rdi+0x168],rax
    mov    QWORD PTR [rdi+0x178],rcx
    add    rcx,rdx
    mov    QWORD PTR [rdi+0xd8],rcx
    add    rcx,rdx
    mov    QWORD PTR [rdi+0x208],rcx
    add    rcx,rdx
    mov    QWORD PTR [rdi+0x268],rcx
    add    rsi,rcx
    mov    QWORD PTR [rdi+0x260],rsi
    add    rsi,rdx
    mov    QWORD PTR [rdi+0x1d0],rsi
    lea    rax,[rsi+rdx*2]
    mov    QWORD PTR [rdi+0x170],rax
    cmp    r13,0xd
    {disp32} jne    at_1_00f7
    {disp32} jmp    at_1_0d28
at_1_05b4:
    mov    rax,QWORD PTR [rdi+0x110]
    mov    r13,QWORD PTR [r11]
    cmp    rax,r13
    {disp32} jle    at_1_0853
    mov    rbx,r9
    mov    rax,QWORD PTR [rdi+0x148]
    mov    rsi,r8
    lea    r8,[r10+rax*8]
    add    r8,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x58],r10
    mov    rax,QWORD PTR [rsp+0x158]
    mov    QWORD PTR [rsp+0x50],rax
    mov    r13,rdx
    mov    QWORD PTR [rsp+0x48],rdx
    mov    QWORD PTR [rsp+0x40],r11
    lea    rax,[rsp+0x68]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],r12
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r15
    lea    r9,[rsp+0x78]
    mov    rcx,rbp
    mov    rdx,rdi
    call   ref_26_DN2LRD
    mov    r10,QWORD PTR [rsp+0x160]
    mov    r8,rsi
    mov    rax,QWORD PTR [rsi]
    mov    rcx,QWORD PTR [rsp+0x128]
    mov    rcx,QWORD PTR [rcx]
    cmp    rax,rcx
    {disp32} jl     at_1_0b33
    cmp    r14,0x1
    mov    r14,QWORD PTR [rsp+0x128]
    jg     at_1_06c5
    mov    rax,QWORD PTR [rdi+0x268]
    lea    rsi,[r10+rax*8]
    add    rsi,0xfffffffffffffff8
    lea    r8,[rip + ref_23_unnamed_2]
    lea    rcx,[rsp+0x78]
    mov    rdx,rsi
    call   ref_21_DV7SCP
    mov    r9,r13
    mov    QWORD PTR [rsp+0x38],r13
    mov    QWORD PTR [rsp+0x30],rbp
    mov    QWORD PTR [rsp+0x28],rsi
    lea    rax,[rip + ref_27_unnamed_3]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x68]
    mov    rdx,r12
    mov    r8,QWORD PTR [rsp+0x148]
    call   ref_28_DQ7RAD
    mov    r10,QWORD PTR [rsp+0x160]
    mov    QWORD PTR [rdi+0x220],0x0
at_1_06c5:
    mov    rax,QWORD PTR [rdi+0x148]
    lea    rdx,[r10+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x38],r10
    mov    rsi,QWORD PTR [rsp+0x148]
    mov    QWORD PTR [rsp+0x30],rsi
    mov    QWORD PTR [rsp+0x28],r14
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rsp+0x78]
    mov    rcx,rdi
    mov    r9,r15
    call   ref_29_DC7VFN
    mov    r11,rsi
    mov    r10,QWORD PTR [rsp+0x160]
    mov    r9,rbx
    {disp32} jmp    at_1_0cb6
at_1_071b:
    mov    rax,QWORD PTR [rdi+0x260]
    mov    rsi,QWORD PTR [rdi+0x268]
    mov    rcx,QWORD PTR [rsp+0x160]
    lea    rdx,[rcx+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[rip + ref_23_unnamed_2]
    mov    rcx,r15
    call   ref_21_DV7SCP
    mov    QWORD PTR [rdi+0x210],0x0
    mov    rcx,QWORD PTR [r12]
    mov    rax,QWORD PTR [rdi+0x110]
    cmp    rcx,QWORD PTR [r14]
    {disp32} jl     at_1_0adb
    mov    rcx,QWORD PTR [rsp+0x138]
    cmp    QWORD PTR [rcx],0x1
    {disp32} jne    at_1_0adb
    test   rax,rax
    {disp32} js     at_1_0ae8
    mov    rcx,QWORD PTR [rdi+0x30]
    cmp    QWORD PTR [rdi+0x220],rcx
    {disp32} jne    at_1_0a67
    mov    rcx,r14
    mov    r15,QWORD PTR [rsp+0x158]
    mov    rdx,r15
    mov    r8,QWORD PTR [rsp+0x150]
    {disp32} jmp    at_1_0a86
at_1_07ae:
    cmp    r13d,0x2
    {disp32} jne    at_1_02eb
    mov    r15,QWORD PTR [r11]
    test   r15,r15
    jle    at_1_081e
    mov    rax,QWORD PTR [rdi+0x178]
    lea    r12,[r10+rax*8]
    add    r12,0xfffffffffffffff8
    xor    r13d,r13d
    mov    rsi,rdx
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07e0:
    movsd  xmm6,QWORD PTR [r12+r13*8]
    lea    rcx,[rsp+0x68]
    mov    rdx,rbp
    mov    r8,rsi
    call   ref_30_DD7TPR
    addsd  xmm0,xmm6
    movsd  QWORD PTR [r12+r13*8],xmm0
    inc    r13
    add    rbp,rbx
    cmp    r13,r15
    jl     at_1_07e0
    mov    r8,QWORD PTR [rsp+0x140]
    mov    rax,QWORD PTR [r8]
    mov    r12,QWORD PTR [rsp+0x130]
at_1_081e:
    mov    rcx,QWORD PTR [rsp+0x128]
    mov    rcx,QWORD PTR [rcx]
    cmp    rax,rcx
    {disp32} jl     at_1_0b33
    xor    eax,eax
    cmp    r14,0x2
    setl   al
    lea    rax,[rax+rax*4]
    add    rax,0xfffffffffffffffd
    mov    QWORD PTR [rdi],rax
    mov    r14,QWORD PTR [rsp+0x128]
    {disp32} jmp    at_1_0b2e
at_1_0853:
    mov    r14,QWORD PTR [rdi+0xd8]
    mov    QWORD PTR [rsp+0x98],rax
    test   rax,rax
    mov    QWORD PTR [rsp+0x90],r14
    mov    rcx,QWORD PTR [rsp+0x128]
    {disp32} js     at_1_093c
    {disp32} je     at_1_0999
    mov    QWORD PTR [rdi],0x2
    test   r13,r13
    {disp32} jle    at_1_0b55
    lea    r14,[r10+r14*8]
    add    r14,0xfffffffffffffff8
    xor    r12d,r12d
    mov    rsi,rbp
    nop
at_1_08a0:
    movsd  xmm6,QWORD PTR [r14+r12*8]
    lea    rcx,[rsp+0x68]
    mov    rdx,QWORD PTR [rsp+0x150]
    mov    r8,rsi
    call   ref_30_DD7TPR
    addsd  xmm0,xmm6
    movsd  QWORD PTR [r14+r12*8],xmm0
    inc    r12
    add    rsi,rbx
    cmp    r12,r13
    jl     at_1_08a0
    {disp32} jmp    at_1_0b55
at_1_08d5:
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_8_real_3fe0000000000000]
    addsd  xmm0,QWORD PTR [r10+0x48]
    movsd  QWORD PTR [r10+0x48],xmm0
    mov    r8,QWORD PTR [rsp+0x140]
    mov    rax,QWORD PTR [r8]
    mov    rcx,QWORD PTR [rsp+0x128]
    mov    rcx,QWORD PTR [rcx]
    cmp    rax,rcx
    {disp32} jl     at_1_0b33
    mov    r12,r15
    cmp    r14,0x1
    mov    r14,QWORD PTR [rsp+0x128]
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r9,rsi
    {disp32} jne    at_1_0303
    mov    rax,QWORD PTR [rdi+0x28]
    mov    QWORD PTR [rdi+0x220],rax
    {disp32} jmp    at_1_0303
at_1_093c:
    mov    rax,QWORD PTR [rcx]
    cmp    rax,QWORD PTR [r12]
    jle    at_1_0999
    mov    rsi,r9
    lea    rcx,[rsp+0x68]
    call   ref_25_DV2NRM
    mov    r10,QWORD PTR [rsp+0x160]
    ucomisd xmm0,QWORD PTR [r10+0x168]
    {disp32} ja     at_1_048b
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_8_real_3fe0000000000000]
    addsd  xmm0,QWORD PTR [r10+0x48]
    movsd  QWORD PTR [r10+0x48],xmm0
    mov    rcx,QWORD PTR [rsp+0x128]
    mov    r11,QWORD PTR [rsp+0x148]
    mov    rdx,QWORD PTR [rsp+0x150]
at_1_0999:
    cmp    QWORD PTR [rdi+0x78],0x0
    jle    at_1_0a01
    mov    QWORD PTR [rsp+0x50],r10
    mov    QWORD PTR [rsp+0x48],r11
    mov    rax,QWORD PTR [rsp+0x140]
    mov    QWORD PTR [rsp+0x40],rax
    lea    rax,[rsp+0x68]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],r12
    mov    QWORD PTR [rsp+0x28],rcx
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rsi,rdx
    mov    rdx,rbp
    mov    r8,rdi
    mov    r9,r15
    call   ref_31_DD7UPD
    mov    rdx,rsi
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
at_1_0a01:
    mov    rax,QWORD PTR [rdi+0x260]
    mov    rcx,QWORD PTR [rdi+0x268]
    mov    QWORD PTR [rsp+0x88],rax
    lea    r9,[r10+rax*8]
    add    r9,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x80],rcx
    lea    rax,[r10+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x38],rdx
    mov    QWORD PTR [rsp+0x30],rbp
    mov    QWORD PTR [rsp+0x28],rax
    lea    rax,[rip + ref_32_unnamed_4]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x68]
    mov    rdx,r12
    mov    r8,r11
    call   ref_28_DQ7RAD
    mov    QWORD PTR [rdi+0x220],0x0
    {disp32} jmp    at_1_0b55
at_1_0a67:
    cmp    QWORD PTR [rdi+0x218],rcx
    jne    at_1_0adb
    mov    rcx,r14
    mov    rdx,QWORD PTR [rsp+0x150]
    mov    r15,QWORD PTR [rsp+0x158]
    mov    r8,r15
at_1_0a86:
    call   ref_24_DV7CPY
    lea    rax,[rip + ref_27_unnamed_3]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r15
    mov    rcx,r12
    mov    rdx,r14
    mov    rdi,QWORD PTR [rsp+0x148]
    mov    r8,rdi
    mov    r9,rbp
    call   ref_33_DQ7APL
    mov    rax,QWORD PTR [rsp+0x160]
    lea    rsi,[rax+rsi*8]
    add    rsi,0xfffffffffffffff8
    mov    rcx,rdi
    mov    rdx,rbx
    mov    r8,rsi
    mov    r9,r15
    call   ref_34_DL7VML
    mov    rdx,rsi
    jmp    at_1_0b15
at_1_0adb:
    not    rax
    shr    rax,0x3f
    not    rax
    mov    QWORD PTR [rdi],rax
at_1_0ae8:
    mov    r13,QWORD PTR [rsp+0x160]
    mov    rbp,QWORD PTR [rsp+0x148]
at_1_0af8:
    lea    r8,[rip + ref_23_unnamed_2]
    mov    rcx,rbp
    mov    rdx,rbx
    call   ref_21_DV7SCP
    lea    rdx,[rsi*8-0x8]
    add    rdx,r13
at_1_0b15:
    lea    r8,[rip + ref_23_unnamed_2]
    lea    rcx,[rsp+0x78]
    call   ref_21_DV7SCP
at_1_0b26:
    mov    r8,QWORD PTR [rsp+0x140]
at_1_0b2e:
    mov    rcx,QWORD PTR [r14]
    xor    eax,eax
at_1_0b33:
    lea    rdx,[rax+0x1]
    mov    r9,QWORD PTR [rsp+0x138]
    mov    QWORD PTR [r9],rdx
    add    rax,QWORD PTR [r12]
    cmp    rax,rcx
    cmovge rax,rcx
    mov    QWORD PTR [r8],rax
    {disp32} jmp    at_1_0d28
at_1_0b55:
    mov    r8,QWORD PTR [rsp+0x140]
    mov    rax,QWORD PTR [r8]
    mov    rcx,QWORD PTR [rsp+0x128]
    mov    rcx,QWORD PTR [rcx]
    cmp    rax,rcx
    mov    r12,QWORD PTR [rsp+0x130]
    mov    r10,QWORD PTR [rsp+0x160]
    jl     at_1_0b33
    mov    r12,r15
    mov    rax,QWORD PTR [rsp+0x98]
    test   rax,rax
    mov    r14,QWORD PTR [rsp+0x128]
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r9,QWORD PTR [rsp+0x168]
    {disp32} jg     at_1_0303
    mov    r15,rax
    mov    rax,QWORD PTR [rdi+0x30]
    mov    QWORD PTR [rdi+0x280],rax
    mov    rax,QWORD PTR [rsp+0x90]
    lea    rbx,[r10+rax*8]
    add    rbx,0xfffffffffffffff8
    mov    rax,QWORD PTR [rsp+0x80]
    lea    r8,[r10+rax*8-0x8]
    mov    rsi,r9
    mov    rax,QWORD PTR [rsp+0x88]
    lea    r9,[r10+rax*8]
    add    r9,0xfffffffffffffff8
    mov    rcx,r11
    mov    rdx,rbx
    call   ref_34_DL7VML
    mov    r9,rsi
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
    mov    QWORD PTR [rdi],0x2
    test   r15,r15
    {disp32} je     at_1_0303
    mov    rax,QWORD PTR [r14]
    mov    rcx,QWORD PTR [rsp+0x130]
    cmp    rax,QWORD PTR [rcx]
    {disp32} jle    at_1_0303
    mov    rax,QWORD PTR [rdi+0x178]
    mov    QWORD PTR [rdi],0x1
    lea    rax,[r10+rax*8]
    add    rax,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x48],rax
    mov    QWORD PTR [rsp+0x40],r9
    mov    QWORD PTR [rsp+0x38],r10
    mov    QWORD PTR [rsp+0x30],r11
    mov    QWORD PTR [rsp+0x28],r11
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rdx,rbx
    mov    r8,rdi
    mov    r9,r12
    call   ref_22_DG7LIT
    mov    r9,rsi
    mov    r11,QWORD PTR [rsp+0x148]
    mov    r10,QWORD PTR [rsp+0x160]
    mov    rax,QWORD PTR [rdi]
    cmp    rax,0x2
    {disp32} je     at_1_0303
at_1_0c9b:
    cmp    QWORD PTR [rdi+0xc8],0x0
    mov    r15,r12
    jne    at_1_0cb6
    cmp    QWORD PTR [rdi+0x210],0x0
    {disp32} je     at_1_0d44
at_1_0cb6:
    mov    rcx,QWORD PTR [rdi+0xd8]
    dec    rcx
at_1_0cc0:
    lea    rdx,[r10+rcx*8]
    mov    QWORD PTR [rsp+0x38],r9
    mov    QWORD PTR [rsp+0x30],r10
    mov    QWORD PTR [rsp+0x28],r11
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    r8,rdi
    mov    r9,r15
    call   ref_35_DITSUM
    cmp    QWORD PTR [rdi],0x6
    jg     at_1_0d28
    cmp    QWORD PTR [rdi+0x1c0],0x0
    jle    at_1_0d28
    mov    rax,QWORD PTR [rsp+0x160]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rdi
    mov    rdx,r15
    mov    r8,QWORD PTR [rsp+0x120]
    mov    r9,QWORD PTR [rsp+0x148]
    call   ref_36_DN2CVP
at_1_0d28:
    movaps xmm6,XMMWORD PTR [rsp+0xa0]
    add    rsp,0xb8
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0d44:
    mov    rcx,QWORD PTR [rdi+0x248]
    test   rcx,rcx
    jle    at_1_0d94
    mov    rdx,QWORD PTR [rdi+0x1c0]
    test   rdx,rdx
    {disp32} jle    at_1_0cb6
    mov    rbx,r9
    mov    ecx,edx
    shr    ecx,1
    and    ecx,0x1
    mov    r9,QWORD PTR [rdi+0x70]
    mov    r8,r9
    neg    r8
    cmovs  r8,r9
    test   dl,0x1
    je     at_1_0da7
    cmp    r8,0x1
    ja     at_1_0da7
    or     rcx,0x2
    mov    rdx,rcx
    mov    r12,QWORD PTR [rsp+0x130]
    jmp    at_1_0dbd
at_1_0d94:
    mov    QWORD PTR [rdi+0xc8],rcx
    mov    QWORD PTR [rdi+0x210],rcx
    {disp32} jmp    at_1_0cb6
at_1_0da7:
    mov    edx,0x1
    test   rcx,rcx
    mov    r12,QWORD PTR [rsp+0x130]
    {disp32} je     at_1_06c5
at_1_0dbd:
    mov    rcx,QWORD PTR [rsp+0x148]
    mov    rcx,QWORD PTR [rcx]
    add    rcx,rdx
    mov    QWORD PTR [rdi+0x110],rcx
    inc    QWORD PTR [rdi+0xe8]
    inc    QWORD PTR [rdi+0x1a0]
    mov    QWORD PTR [rdi+0x1b0],rax
    cmp    rdx,0x2
    {disp32} jb     at_1_0419
    mov    rax,QWORD PTR [rdi+0x1b8]
    mov    rcx,rax
    neg    rcx
    cmovs  rcx,rax
    mov    rax,QWORD PTR [rsp+0x160]
    lea    rdx,[rax+rcx*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[rip + ref_23_unnamed_2]
    lea    rcx,[rsp+0x78]
    call   ref_21_DV7SCP
    {disp32} jmp    at_1_0419
at_1_0e28:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3fe0000000000000:
at_4_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_001c - at_1_0000    # prologue size
    .byte 0x0c    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0a
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x17
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_5_001c:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_11_rdata:
def_19_unnamed_1:
at_6_0000:
    .quad 0x0000000000000001
def_32_unnamed_4:
at_6_0008:
    .quad 0xffffffffffffffff
def_23_unnamed_2:
at_6_0010:
    .zero 8
def_27_unnamed_3:
at_6_0018:
    .zero 8
at_6_0020:
end_s6:

# .drectve  (COFF section 7)
.section .s7,"dr"
def_13_drectve:
at_7_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_7_00b9:
end_s7:

# .pdata  (COFF section 8)
.section .s8,"dr"
def_15_pdata:
at_8_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0e28 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_8_000c:
end_s8:

# MEMBER drldst.obj
# Entry points: DRLDST
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_16_DRLDST:
at_1_0000:
    sub    rsp,0x28
at_1_0004:
    movapd XMMWORD PTR [rsp+0x10],xmm7
at_1_000a:
    movapd XMMWORD PTR [rsp],xmm6
at_1_000f:
    mov    rax,QWORD PTR [rcx]
    xorpd  xmm1,xmm1
    xorpd  xmm0,xmm0
    xorpd  xmm2,xmm2
    test   rax,rax
    jle    at_1_0097
    xorpd  xmm5,xmm5
    xor    ecx,ecx
    movapd xmm3,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    xorpd  xmm4,xmm4
    jmp    at_1_0050
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0040:
    inc    rcx
    movapd xmm5,xmm0
    movapd xmm4,xmm2
    cmp    rax,rcx
    je     at_1_0097
at_1_0050:
    movsd  xmm2,QWORD PTR [rdx+rcx*8]
    movsd  xmm7,QWORD PTR [r8+rcx*8]
    movsd  xmm6,QWORD PTR [r9+rcx*8]
    movapd xmm0,xmm7
    subsd  xmm0,xmm6
    mulsd  xmm0,xmm2
    andpd  xmm0,xmm3
    ucomisd xmm0,xmm5
    ja     at_1_007b
    movapd xmm0,xmm5
at_1_007b:
    andpd  xmm7,xmm3
    andpd  xmm6,xmm3
    addsd  xmm6,xmm7
    mulsd  xmm2,xmm6
    ucomisd xmm2,xmm4
    ja     at_1_0040
    movapd xmm2,xmm4
    jmp    at_1_0040
at_1_0097:
    ucomisd xmm2,xmm1
    jbe    at_1_00a3
    divsd  xmm0,xmm2
    jmp    at_1_00a7
at_1_00a3:
    xorpd  xmm0,xmm0
at_1_00a7:
    movaps xmm6,XMMWORD PTR [rsp]
    movaps xmm7,XMMWORD PTR [rsp+0x10]
    add    rsp,0x28
    ret
at_1_00b5:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_000f - at_1_0000    # prologue size
    .byte 0x05    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000f - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x00
    .byte 0x00
    .byte at_1_000a - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x01
    .byte 0x00
    .byte at_1_0004 - at_1_0000    # ALLOC_SMALL
    .byte 0x42
    .byte 0x00
    .byte 0x00
at_5_0010:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_11_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_13_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00b5 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dr7tvm.obj
# Entry points: DR7TVM
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DR7TVM:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x48
at_1_0010:
    movapd XMMWORD PTR [rsp+0x30],xmm6
at_1_0016:
    mov    r12,QWORD PTR [rcx]
    mov    r13,QWORD PTR [rdx]
    cmp    r12,r13
    cmovl  r13,r12
    test   r13,r13
    jle    at_1_00a2
    mov    rsi,r9
    mov    rdi,r8
    mov    rbx,QWORD PTR [rsp+0xb8]
    mov    rax,QWORD PTR [rsp+0xb0]
    lea    rbp,[r13-0x1]
    mov    rcx,r12
    imul   rcx,rbp
    lea    r14,[rax+rcx*8]
    shl    r12,0x3
    neg    r12
    xor    r15d,r15d
    jmp    at_1_0073
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0060:
    movsd  QWORD PTR [rdi+rbp*8],xmm6
    inc    r15
    dec    rbp
    add    r14,r12
    cmp    r15,r13
    jge    at_1_00a2
at_1_0073:
    lea    rax,[rbp+0x1]
    movsd  xmm6,QWORD PTR [rbx+rbp*8]
    mulsd  xmm6,QWORD PTR [rsi+rbp*8]
    cmp    rax,0x2
    jl     at_1_0060
    mov    QWORD PTR [rsp+0x28],rbp
    lea    rcx,[rsp+0x28]
    mov    rdx,r14
    mov    r8,rbx
    call   ref_14_DD7TPR
    addsd  xmm6,xmm0
    jmp    at_1_0060
at_1_00a2:
    movaps xmm6,XMMWORD PTR [rsp+0x30]
    add    rsp,0x48
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_00b8:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0016 - at_1_0000    # prologue size
    .byte 0x0b    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0016 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x03
    .byte 0x00
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0x82
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_4_001c:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00b8 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dr7mdc.obj
# Entry points: DR7MDC
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_21_DR7MDC:
at_1_0000:
    push   rsi
at_1_0001:
    sub    rsp,0x20
at_1_0005:
    mov    rsi,rcx
    movsd  xmm0,QWORD PTR [rip + ref_22_DR7MDC_BIG]
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    ja     at_1_0056
    lea    rcx,[rip + ref_23_unnamed_1]
    call   ref_24_D1MACH
    movsd  QWORD PTR [rip + ref_22_DR7MDC_BIG],xmm0
    lea    rcx,[rip + ref_25_unnamed_2]
    call   ref_24_D1MACH
    movsd  QWORD PTR [rip + ref_26_DR7MDC_ETA],xmm0
    lea    rcx,[rip + ref_27_unnamed_3]
    call   ref_24_D1MACH
    movsd  QWORD PTR [rip + ref_28_DR7MDC_MACHEP],xmm0
at_1_0056:
    mov    eax,DWORD PTR [rsi]
    add    eax,0xfffffffe
    cmp    eax,0x4
    ja     at_1_00ce
    lea    rcx,[rip + ref_12_rdata]
    movsxd rax,DWORD PTR [rcx+rax*4]
    add    rax,rcx
    jmp    rax
at_1_0070:
    movsd  xmm0,QWORD PTR [rip + ref_8_real_4070000000000000]
    mulsd  xmm0,QWORD PTR [rip + ref_26_DR7MDC_ETA]
    sqrtsd xmm0,xmm0
    divsd  xmm0,QWORD PTR [rip + ref_11_real_4030000000000000]
    jmp    at_1_00d6
at_1_008e:
    movsd  xmm0,QWORD PTR [rip + ref_22_DR7MDC_BIG]
    jmp    at_1_00d6
at_1_0098:
    movsd  xmm0,QWORD PTR [rip + ref_28_DR7MDC_MACHEP]
    sqrtsd xmm0,xmm0
    jmp    at_1_00d6
at_1_00a6:
    movsd  xmm0,QWORD PTR [rip + ref_22_DR7MDC_BIG]
    divsd  xmm0,QWORD PTR [rip + ref_8_real_4070000000000000]
    sqrtsd xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_11_real_4030000000000000]
    jmp    at_1_00d6
at_1_00c4:
    movsd  xmm0,QWORD PTR [rip + ref_28_DR7MDC_MACHEP]
    jmp    at_1_00d6
at_1_00ce:
    movsd  xmm0,QWORD PTR [rip + ref_26_DR7MDC_ETA]
at_1_00d6:
    add    rsp,0x20
    pop    rsi
    ret
at_1_00dc:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_28_DR7MDC_MACHEP:
at_3_0000:
    .zero 8
def_26_DR7MDC_ETA:
at_3_0008:
    .zero 8
def_22_DR7MDC_BIG:
at_3_0010:
    .zero 8
at_3_0018:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_4070000000000000:
at_4_0000:
    .quad 0x4070000000000000    # binary64 256.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_4030000000000000:
at_5_0000:
    .quad 0x4030000000000000    # binary64 16.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
at_6_0000:
    .long ref_0_text + (at_1_0070 - at_1_0000) + (. - at_6_0000) + 4    # slot 0 -> at_1_0070
    .long ref_0_text + (at_1_00c4 - at_1_0000) + (. - at_6_0000) + 4    # slot 1 -> at_1_00c4
    .long ref_0_text + (at_1_0098 - at_1_0000) + (. - at_6_0000) + 4    # slot 2 -> at_1_0098
    .long ref_0_text + (at_1_00a6 - at_1_0000) + (. - at_6_0000) + 4    # slot 3 -> at_1_00a6
    .long ref_0_text + (at_1_008e - at_1_0000) + (. - at_6_0000) + 4    # slot 4 -> at_1_008e
    .zero 4
def_23_unnamed_1:
at_6_0018:
    .quad 0x0000000000000002
def_25_unnamed_2:
at_6_0020:
    .quad 0x0000000000000001
def_27_unnamed_3:
at_6_0028:
    .quad 0x0000000000000004
at_6_0030:
end_s6:

# .xdata  (COFF section 7)
.section .s7,"dr"
def_14_xdata:
at_7_0000:
    .byte 0x01    # version 1
    .byte at_1_0005 - at_1_0000    # prologue size
    .byte 0x02    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0005 - at_1_0000    # ALLOC_SMALL
    .byte 0x32
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
at_7_0008:
end_s7:

# .drectve  (COFF section 8)
.section .s8,"dr"
def_16_drectve:
at_8_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_8_00b9:
end_s8:

# .pdata  (COFF section 9)
.section .s9,"dr"
def_18_pdata:
at_9_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00dc - def_0_text)    # image-relative end
    .long ref_14_xdata    # image-relative unwind info
at_9_000c:
end_s9:

# MEMBER dq7rsh.obj
# Entry points: DQ7RSH
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DQ7RSH:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0xd8
at_1_0013:
    movapd XMMWORD PTR [rsp+0xc0],xmm7
at_1_001c:
    movapd XMMWORD PTR [rsp+0xb0],xmm6
at_1_0025:
    mov    QWORD PTR [rsp+0x70],r9
    mov    rbx,QWORD PTR [rcx]
    mov    r12,QWORD PTR [rdx]
    cmp    rbx,r12
    {disp32} jge    at_1_02d7
    mov    rbp,rdx
    mov    QWORD PTR [rsp+0x38],r8
    mov    r13,QWORD PTR [rsp+0x148]
    mov    rdi,QWORD PTR [rsp+0x140]
    lea    rsi,[rbx-0x1]
    imul   rbx,rsi
    shr    rbx,1
    lea    r14,[rdi+rbx*8]
    mov    r15,rcx
    mov    rdx,r13
    mov    r8,r14
    call   ref_16_DV7CPY
    mov    rax,QWORD PTR [r15]
    movsd  xmm6,QWORD PTR [r13+rax*8-0x8]
    cmp    r12,rax
    {disp32} jle    at_1_02bd
    mov    rcx,rax
    mov    QWORD PTR [rsp+0x68],rbp
    mov    QWORD PTR [rsp+0x48],r12
    lea    r15,[r12-0x1]
    add    rsi,rbx
    mov    rax,QWORD PTR [rsp+0x38]
    mov    rax,QWORD PTR [rax]
    mov    QWORD PTR [rsp+0x78],rax
    xorpd  xmm7,xmm7
    lea    r14,[rsp+0x60]
    lea    r13,[rsp+0x58]
    lea    rbp,[rsp+0xa8]
    mov    rdx,rsi
    mov    r12,rcx
    jmp    at_1_0118
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_00d0:
    movsd  QWORD PTR [rdi+rbx*8-0x8],xmm0
    mov    QWORD PTR [rsp+0x58],0x0
    mov    QWORD PTR [rsp+0x60],0x0
at_1_00e8:
    movsd  xmm0,QWORD PTR [rsp+0x58]
    mulsd  xmm0,xmm6
    addsd  xmm6,xmm0
    mov    rax,QWORD PTR [rsp+0x148]
    movsd  QWORD PTR [rax+r8*8-0x8],xmm6
    movapd xmm6,xmm0
    mulsd  xmm6,QWORD PTR [rsp+0x60]
    cmp    r8,r15
    {disp32} jge    at_1_02af
at_1_0118:
    mov    rsi,rdx
    mov    r8,r12
    lea    rcx,[r12-0x1]
    mov    rax,rcx
    mov    QWORD PTR [rsp+0x88],rcx
    mov    QWORD PTR [rsp+0x90],rcx
    cmp    r12,0x2
    jl     at_1_015b
    lea    rdx,[rdi+rbx*8]
    mov    r12,r8
    lea    r8,[rdi+rsi*8]
    add    r8,0x8
    lea    rcx,[rsp+0x90]
    call   ref_16_DV7CPY
    mov    r8,r12
at_1_015b:
    lea    r12,[r8+0x1]
    lea    rdx,[rsi+r12*1]
    add    rbx,r8
    add    rsi,r8
    movsd  xmm0,QWORD PTR [rdi+rsi*8]
    movsd  QWORD PTR [rsp+0x98],xmm0
    movsd  xmm1,QWORD PTR [rdi+rdx*8]
    ucomisd xmm7,xmm1
    movsd  QWORD PTR [rsp+0xa0],xmm1
    setnp  al
    sete   cl
    test   cl,al
    {disp32} jne    at_1_00d0
    mov    QWORD PTR [rsp+0x50],r12
    mov    QWORD PTR [rsp+0x40],rdx
    mov    QWORD PTR [rsp+0x20],r14
    lea    rcx,[rsp+0x98]
    lea    rdx,[rsp+0xa0]
    mov    rsi,r8
    mov    r8,r13
    mov    r9,rbp
    call   ref_17_DH2RFG
    mov    QWORD PTR [rsp+0x80],rbx
    movsd  QWORD PTR [rdi+rbx*8-0x8],xmm0
    mov    rax,rsi
    mov    QWORD PTR [rsp+0x38],rsi
    cmp    rsi,r15
    mov    r12,r15
    mov    r15,rbp
    mov    rbp,r13
    mov    r13,r14
    lea    r14,[rip + ref_18_unnamed_1]
    je     at_1_023f
    mov    rbx,QWORD PTR [rsp+0x38]
    mov    rsi,QWORD PTR [rsp+0x40]
    mov    rax,QWORD PTR [rsp+0x50]
    cmp    QWORD PTR [rsp+0x48],rax
    jle    at_1_023f
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0210:
    add    rsi,rbx
    inc    rsi
    inc    rbx
    lea    rdx,[rdi+rsi*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[rdi+rsi*8]
    mov    QWORD PTR [rsp+0x28],r13
    mov    QWORD PTR [rsp+0x20],r15
    mov    rcx,r14
    mov    r9,rbp
    call   ref_19_DH2RFA
    cmp    rbx,r12
    jl     at_1_0210
at_1_023f:
    test   BYTE PTR [rsp+0x78],0x1
    mov    rbx,QWORD PTR [rsp+0x80]
    mov    rdx,QWORD PTR [rsp+0x40]
    mov    r14,r13
    mov    r13,rbp
    mov    rbp,r15
    mov    r15,r12
    mov    r12,QWORD PTR [rsp+0x50]
    mov    r8,QWORD PTR [rsp+0x38]
    {disp32} je     at_1_00e8
    mov    rax,QWORD PTR [rsp+0x70]
    mov    rcx,QWORD PTR [rsp+0x88]
    lea    rdx,[rax+rcx*8]
    mov    rcx,QWORD PTR [rsp+0x38]
    lea    r8,[rax+rcx*8]
    mov    QWORD PTR [rsp+0x28],r14
    mov    QWORD PTR [rsp+0x20],rbp
    lea    rcx,[rip + ref_18_unnamed_1]
    mov    r9,r13
    call   ref_19_DH2RFA
    mov    r8,QWORD PTR [rsp+0x38]
    mov    rdx,QWORD PTR [rsp+0x40]
    {disp32} jmp    at_1_00e8
at_1_02af:
    lea    r14,[rdi+rbx*8]
    mov    rbp,QWORD PTR [rsp+0x68]
    mov    r12,QWORD PTR [rsp+0x48]
at_1_02bd:
    mov    r8,QWORD PTR [rsp+0x148]
    movsd  QWORD PTR [r8+r12*8-0x8],xmm6
    mov    rcx,rbp
    mov    rdx,r14
    call   ref_16_DV7CPY
at_1_02d7:
    movaps xmm6,XMMWORD PTR [rsp+0xb0]
    movaps xmm7,XMMWORD PTR [rsp+0xc0]
    add    rsp,0xd8
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_02fb:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0025 - at_1_0000    # prologue size
    .byte 0x0e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0025 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0b
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x0c
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x1b
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0020:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_18_unnamed_1:
at_5_0000:
    .quad 0x0000000000000001
at_5_0008:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_02fb - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dq7rad.obj
# Entry points: DQ7RAD
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_24_DQ7RAD:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x128
at_1_0013:
    movapd XMMWORD PTR [rsp+0x110],xmm12
at_1_001d:
    movapd XMMWORD PTR [rsp+0x100],xmm11
at_1_0027:
    movapd XMMWORD PTR [rsp+0xf0],xmm10
at_1_0031:
    movapd XMMWORD PTR [rsp+0xe0],xmm9
at_1_003b:
    movapd XMMWORD PTR [rsp+0xd0],xmm8
at_1_0045:
    movapd XMMWORD PTR [rsp+0xc0],xmm7
at_1_004e:
    movapd XMMWORD PTR [rsp+0xb0],xmm6
at_1_0057:
    mov    QWORD PTR [rsp+0x58],r9
    mov    rdi,r8
    mov    rsi,rcx
    mov    rbx,QWORD PTR [rdx]
    movsd  xmm0,QWORD PTR [rip + ref_25_DQ7RAD_TINY]
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    ja     at_1_00bd
    lea    rcx,[rip + ref_26_unnamed_1]
    call   ref_27_DR7MDC
    movsd  QWORD PTR [rip + ref_25_DQ7RAD_TINY],xmm0
    lea    rcx,[rip + ref_28_unnamed_2]
    call   ref_27_DR7MDC
    movsd  xmm2,QWORD PTR [rip + ref_25_DQ7RAD_TINY]
    mulsd  xmm2,xmm0
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    ucomisd xmm1,xmm2
    jbe    at_1_00bd
    divsd  xmm1,xmm0
    movsd  QWORD PTR [rip + ref_25_DQ7RAD_TINY],xmm1
at_1_00bd:
    mov    rax,QWORD PTR [rsi]
    mov    QWORD PTR [rsp+0x28],rax
    mov    r10,QWORD PTR [rdi]
    test   r10,r10
    {disp32} jle    at_1_07e7
    mov    rdx,QWORD PTR [rsp+0x1a0]
    mov    rsi,QWORD PTR [rsp+0x198]
    mov    rcx,QWORD PTR [rsp+0x190]
    shl    rbx,0x3
    mov    rcx,QWORD PTR [rcx]
    mov    QWORD PTR [rsp+0x60],rcx
    lea    rcx,[rdx-0x8]
    mov    QWORD PTR [rsp+0x88],rcx
    lea    rcx,[rdx+rbx*1]
    add    rcx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x68],rcx
    mov    r14d,0x1
    xor    edi,edi
    movapd xmm6,XMMWORD PTR [rip + ref_11_xmm_7fffffffffffffff7fffffffffffffff]
    xorpd  xmm7,xmm7
    movsd  xmm8,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movapd xmm9,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    movapd xmm10,XMMWORD PTR [rip + ref_14_xmm_80000000000000008000000000000000]
    lea    r15,[rsp+0x30]
    xor    r8d,r8d
    mov    r9d,0x1
    mov    QWORD PTR [rsp+0x70],rbx
    mov    QWORD PTR [rsp+0x50],r10
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0160:
    lea    r13,[r14-0x1]
    imul   r13,rbx
    add    r13,QWORD PTR [rsp+0x1a0]
    lea    rdx,[r9*8-0x8]
    add    rdx,r13
    cmp    rax,0x1
    mov    QWORD PTR [rsp+0x40],r9
    mov    QWORD PTR [rsp+0x38],rdx
    jg     at_1_01a0
    movsd  xmm0,QWORD PTR [rdx]
    andpd  xmm0,xmm6
    jmp    at_1_01bb
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_01a0:
    lea    rcx,[rsp+0x28]
    mov    r12,r8
    mov    rbp,r10
    call   ref_29_DV2NRM
    mov    r10,rbp
    mov    r8,r12
    mov    r9,QWORD PTR [rsp+0x40]
at_1_01bb:
    add    r8,r14
    movsd  QWORD PTR [rsp+0x30],xmm0
    movsd  xmm1,QWORD PTR [rip + ref_25_DQ7RAD_TINY]
    ucomisd xmm1,xmm0
    {disp32} ja     at_1_076c
    lea    r12,[r8+r14*1]
    movsd  xmm1,QWORD PTR [rsi+r8*8-0x8]
    ucomisd xmm7,xmm1
    lea    rbp,[r9-0x1]
    setnp  al
    sete   cl
    test   cl,al
    mov    QWORD PTR [rsp+0x80],r8
    jne    at_1_0220
    movapd xmm2,xmm1
    andpd  xmm2,xmm6
    ucomisd xmm2,xmm0
    jbe    at_1_0255
    divsd  xmm0,xmm2
    mulsd  xmm0,xmm0
    movapd xmm3,xmm0
    jmp    at_1_0265
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0220:
    cmp    QWORD PTR [rsp+0x28],0x1
    {disp32} jle    at_1_078e
    mov    rax,QWORD PTR [rsp+0x38]
    movsd  xmm11,QWORD PTR [rax]
    movsd  xmm1,QWORD PTR [rip + ref_30_DQ7RAD_BIGRT]
    ucomisd xmm1,xmm7
    {disp32} jbe    at_1_033d
    movsd  xmm1,QWORD PTR [rip + ref_31_DQ7RAD_TINYRT]
    {disp32} jmp    at_1_036f
at_1_0255:
    divsd  xmm2,xmm0
    mulsd  xmm2,xmm2
    movapd xmm3,xmm2
    movapd xmm2,xmm0
at_1_0265:
    lea    r13,[rsp+0x28]
    addsd  xmm3,xmm8
    xorps  xmm0,xmm0
    sqrtsd xmm0,xmm3
    mulsd  xmm0,xmm2
    movsd  QWORD PTR [rsp+0x30],xmm0
    ucomisd xmm7,xmm1
    jbe    at_1_0291
    xorpd  xmm0,xmm9
    movlpd QWORD PTR [rsp+0x30],xmm0
at_1_0291:
    addsd  xmm1,xmm0
    movapd xmm2,xmm0
    xorpd  xmm2,xmm10
    movlpd QWORD PTR [rsi+r8*8-0x8],xmm2
    movapd xmm11,xmm1
    divsd  xmm11,xmm0
    xorpd  xmm11,xmm10
    cmp    QWORD PTR [rsp+0x28],0x1
    jg     at_1_02e8
    mov    rbp,QWORD PTR [rsp+0x38]
    movsd  xmm0,QWORD PTR [rbp+0x0]
    divsd  xmm0,xmm1
    movsd  QWORD PTR [rbp+0x0],xmm0
    test   BYTE PTR [rsp+0x60],0x1
    {disp32} jne    at_1_03d6
    cmp    r14,r10
    {disp32} jl     at_1_0433
    {disp32} jmp    at_1_07e7
at_1_02e8:
    mov    QWORD PTR [rsp+0x48],rbp
    movapd xmm0,xmm8
    divsd  xmm0,xmm1
    movsd  QWORD PTR [rsp+0x90],xmm0
    mov    rcx,r13
    mov    rbp,QWORD PTR [rsp+0x38]
    mov    rdx,rbp
    lea    r8,[rsp+0x90]
    mov    r9,rbp
    call   ref_32_DV7SCL
    test   BYTE PTR [rsp+0x60],0x1
    {disp32} jne    at_1_0493
    mov    rcx,QWORD PTR [rsp+0x50]
    cmp    r14,rcx
    mov    rax,QWORD PTR [rsp+0x40]
    {disp32} jl     at_1_050c
    {disp32} jmp    at_1_07e7
at_1_033d:
    lea    rcx,[rip + ref_33_unnamed_3]
    call   ref_27_DR7MDC
    movsd  QWORD PTR [rip + ref_30_DQ7RAD_BIGRT],xmm0
    lea    rcx,[rip + ref_34_unnamed_4]
    call   ref_27_DR7MDC
    movapd xmm1,xmm0
    movsd  QWORD PTR [rip + ref_31_DQ7RAD_TINYRT],xmm0
    movsd  xmm0,QWORD PTR [rsp+0x30]
at_1_036f:
    lea    rcx,[rsp+0x28]
    ucomisd xmm1,xmm0
    jae    at_1_0388
    ucomisd xmm0,QWORD PTR [rip + ref_30_DQ7RAD_BIGRT]
    {disp32} jb     at_1_05bb
at_1_0388:
    xorps  xmm1,xmm1
    sqrtsd xmm1,xmm0
    ucomisd xmm7,xmm11
    jbe    at_1_03bd
    mov    r15,rbp
    movapd xmm2,xmm0
    xorpd  xmm2,xmm10
    movlpd QWORD PTR [rsp+0x30],xmm2
    subsd  xmm11,xmm0
    movapd xmm0,xmm11
    xorpd  xmm0,xmm10
    sqrtsd xmm0,xmm0
    jmp    at_1_03cd
at_1_03bd:
    mov    r15,rbp
    addsd  xmm11,xmm0
    xorps  xmm0,xmm0
    sqrtsd xmm0,xmm11
at_1_03cd:
    mulsd  xmm1,xmm0
    {disp32} jmp    at_1_05e1
at_1_03d6:
    mov    rax,QWORD PTR [rsp+0x58]
    movsd  xmm3,QWORD PTR [rax+r14*8-0x8]
    mov    rcx,QWORD PTR [rsp+0x1a8]
    movsd  xmm1,QWORD PTR [rcx+r9*8-0x8]
    movapd xmm2,xmm1
    mulsd  xmm2,xmm0
    addsd  xmm2,xmm3
    mulsd  xmm2,xmm11
    movsd  QWORD PTR [rsp+0x30],xmm2
    addsd  xmm3,xmm2
    movsd  QWORD PTR [rax+r14*8-0x8],xmm3
    cmp    r14,r10
    {disp32} jge    at_1_07e7
    mulsd  xmm2,xmm0
    addsd  xmm2,xmm1
    mov    rax,QWORD PTR [rsp+0x1a8]
    movsd  QWORD PTR [rax+r9*8-0x8],xmm2
at_1_0433:
    mov    rax,QWORD PTR [rsp+0x68]
    lea    rax,[rax+r9*8]
    mov    rcx,r14
    nop
at_1_0440:
    movsd  xmm2,QWORD PTR [rsi+r12*8-0x8]
    movsd  xmm3,QWORD PTR [rax]
    movapd xmm1,xmm3
    mulsd  xmm1,xmm0
    addsd  xmm1,xmm2
    mulsd  xmm1,xmm11
    movapd xmm4,xmm1
    mulsd  xmm4,xmm0
    addsd  xmm4,xmm3
    movsd  QWORD PTR [rax],xmm4
    addsd  xmm2,xmm1
    movsd  QWORD PTR [rsi+r12*8-0x8],xmm2
    add    r12,rcx
    inc    r12
    inc    rcx
    add    rax,rbx
    cmp    rcx,r10
    jl     at_1_0440
    movsd  QWORD PTR [rsp+0x30],xmm1
    {disp32} jmp    at_1_076c
at_1_0493:
    mov    rcx,r13
    mov    rsi,QWORD PTR [rsp+0x58]
    movsd  xmm12,QWORD PTR [rsi+r14*8-0x8]
    mov    rax,QWORD PTR [rsp+0x1a8]
    mov    rdx,QWORD PTR [rsp+0x48]
    lea    r13,[rax+rdx*8]
    mov    rdx,r13
    mov    r8,rbp
    call   ref_35_DD7TPR
    addsd  xmm0,xmm12
    mulsd  xmm0,xmm11
    movsd  QWORD PTR [rsp+0x30],xmm0
    addsd  xmm0,xmm12
    movsd  QWORD PTR [rsi+r14*8-0x8],xmm0
    mov    rsi,QWORD PTR [rsp+0x198]
    cmp    r14,QWORD PTR [rsp+0x50]
    {disp32} jge    at_1_07e7
    mov    r8,r15
    mov    QWORD PTR [rsp+0x20],r13
    lea    rcx,[rsp+0x28]
    mov    rdx,r13
    mov    r9,QWORD PTR [rsp+0x38]
    call   ref_36_DV2AXY
    mov    rax,QWORD PTR [rsp+0x40]
at_1_050c:
    mov    QWORD PTR [rsp+0x78],rdi
    mov    rcx,QWORD PTR [rsp+0x68]
    lea    r13,[rcx+rax*8]
    mov    QWORD PTR [rsp+0x48],r14
    mov    rdi,rsi
    mov    rsi,r14
    lea    rbx,[rsp+0x28]
    mov    rbp,QWORD PTR [rsp+0x38]
    nop
at_1_0530:
    lea    r14,[rsi+0x1]
    movsd  xmm12,QWORD PTR [rdi+r12*8-0x8]
    mov    rcx,rbx
    mov    rdx,r13
    mov    r8,rbp
    call   ref_35_DD7TPR
    addsd  xmm0,xmm12
    mulsd  xmm0,xmm11
    movsd  QWORD PTR [rsp+0x30],xmm0
    mov    QWORD PTR [rsp+0x20],r13
    mov    rcx,rbx
    mov    rdx,r13
    mov    r8,r15
    mov    r9,rbp
    call   ref_36_DV2AXY
    addsd  xmm12,QWORD PTR [rsp+0x30]
    movsd  QWORD PTR [rdi+r12*8-0x8],xmm12
    add    r12,rsi
    inc    r12
    add    r13,QWORD PTR [rsp+0x70]
    mov    rsi,r14
    cmp    r14,QWORD PTR [rsp+0x50]
    jl     at_1_0530
    mov    r14,QWORD PTR [rsp+0x48]
    mov    rsi,rdi
    mov    rdi,QWORD PTR [rsp+0x78]
    mov    r9,QWORD PTR [rsp+0x40]
    mov    r8,QWORD PTR [rsp+0x80]
    mov    r10,QWORD PTR [rsp+0x50]
    mov    rbx,QWORD PTR [rsp+0x70]
    {disp32} jmp    at_1_076c
at_1_05bb:
    ucomisd xmm7,xmm11
    jbe    at_1_05cd
    xorpd  xmm0,xmm9
    movlpd QWORD PTR [rsp+0x30],xmm0
at_1_05cd:
    mov    r15,rbp
    addsd  xmm11,xmm0
    mulsd  xmm0,xmm11
    xorps  xmm1,xmm1
    sqrtsd xmm1,xmm0
at_1_05e1:
    mov    rdx,QWORD PTR [rsp+0x38]
    movsd  QWORD PTR [rdx],xmm11
    movapd xmm0,xmm8
    divsd  xmm0,xmm1
    movsd  QWORD PTR [rsp+0xa8],xmm0
    lea    r8,[rsp+0xa8]
    mov    rbp,rdx
    mov    r9,rdx
    call   ref_32_DV7SCL
    movsd  xmm0,QWORD PTR [rsp+0x30]
    xorpd  xmm0,xmm9
    mov    rax,QWORD PTR [rsp+0x80]
    movlpd QWORD PTR [rsi+rax*8-0x8],xmm0
    test   BYTE PTR [rsp+0x60],0x1
    je     at_1_069d
    mov    rax,QWORD PTR [rsp+0x1a8]
    lea    r13,[rax+r15*8]
    lea    rbx,[rsp+0x28]
    mov    rcx,rbx
    mov    rdx,r13
    mov    rsi,rbp
    mov    r8,rbp
    call   ref_35_DD7TPR
    xorpd  xmm0,xmm9
    movlpd QWORD PTR [rsp+0xa0],xmm0
    mov    QWORD PTR [rsp+0x20],r13
    mov    rcx,rbx
    mov    rdx,r13
    lea    r8,[rsp+0xa0]
    mov    r9,rbp
    call   ref_36_DV2AXY
    mov    rax,QWORD PTR [rsp+0x1a8]
    movsd  xmm0,QWORD PTR [rax+r15*8]
    mov    rsi,QWORD PTR [rsp+0x198]
    mov    rax,QWORD PTR [rsp+0x58]
    movsd  QWORD PTR [rax+r14*8-0x8],xmm0
at_1_069d:
    mov    r15,QWORD PTR [rsp+0x50]
    cmp    r14,r15
    mov    rax,QWORD PTR [rsp+0x40]
    {disp32} jge    at_1_07e7
    mov    QWORD PTR [rsp+0x78],rdi
    mov    rcx,QWORD PTR [rsp+0x68]
    lea    r13,[rcx+rax*8]
    mov    QWORD PTR [rsp+0x48],r14
    mov    rdi,rsi
    mov    rsi,r14
    lea    rbx,[rsp+0x28]
    xchg   ax,ax
at_1_06d0:
    lea    r14,[rsi+0x1]
    mov    rcx,rbx
    mov    rdx,r13
    mov    r8,rbp
    call   ref_35_DD7TPR
    xorpd  xmm0,xmm9
    movlpd QWORD PTR [rsp+0x98],xmm0
    mov    QWORD PTR [rsp+0x20],r13
    mov    rcx,rbx
    mov    rdx,r13
    lea    r8,[rsp+0x98]
    mov    r9,rbp
    call   ref_36_DV2AXY
    movsd  xmm0,QWORD PTR [r13+0x0]
    movsd  QWORD PTR [rdi+r12*8-0x8],xmm0
    add    r12,rsi
    inc    r12
    add    r13,QWORD PTR [rsp+0x70]
    mov    rsi,r14
    cmp    r14,r15
    jl     at_1_06d0
    mov    rax,QWORD PTR [rsp+0x28]
    cmp    rax,0x2
    mov    r14,QWORD PTR [rsp+0x48]
    mov    rsi,rdi
    mov    rdi,QWORD PTR [rsp+0x78]
    mov    r9,QWORD PTR [rsp+0x40]
    mov    r8,QWORD PTR [rsp+0x80]
    mov    r10,r15
    mov    rbx,QWORD PTR [rsp+0x70]
    lea    r15,[rsp+0x30]
    {disp32} jl     at_1_07e7
    inc    r9
    dec    rax
    mov    QWORD PTR [rsp+0x28],rax
at_1_076c:
    cmp    r14,r10
    je     at_1_07e7
    inc    r14
    mov    rax,QWORD PTR [rsp+0x28]
    inc    rdi
    add    QWORD PTR [rsp+0x88],rbx
    add    QWORD PTR [rsp+0x68],rbx
    {disp32} jmp    at_1_0160
at_1_078e:
    mov    rax,QWORD PTR [rsp+0x88]
    lea    rax,[rax+r9*8]
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_07a0:
    movsd  xmm0,QWORD PTR [rax]
    movsd  QWORD PTR [rsi+r8*8-0x8],xmm0
    add    r8,rdi
    inc    r8
    inc    rdi
    add    rax,rbx
    cmp    rdi,r10
    jl     at_1_07a0
    test   BYTE PTR [rsp+0x60],0x1
    je     at_1_07de
    mov    rax,QWORD PTR [rsp+0x1a8]
    movsd  xmm0,QWORD PTR [rax+r9*8-0x8]
    mov    rax,QWORD PTR [rsp+0x58]
    movsd  QWORD PTR [rax+r14*8-0x8],xmm0
at_1_07de:
    mov    QWORD PTR [r13+r9*8-0x8],0x0
at_1_07e7:
    movaps xmm6,XMMWORD PTR [rsp+0xb0]
    movaps xmm7,XMMWORD PTR [rsp+0xc0]
    movaps xmm8,XMMWORD PTR [rsp+0xd0]
    movaps xmm9,XMMWORD PTR [rsp+0xe0]
    movaps xmm10,XMMWORD PTR [rsp+0xf0]
    movaps xmm11,XMMWORD PTR [rsp+0x100]
    movaps xmm12,XMMWORD PTR [rsp+0x110]
    add    rsp,0x128
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0838:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_30_DQ7RAD_BIGRT:
at_2_0000:
    .quad 0xbff0000000000000
at_2_0008:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_31_DQ7RAD_TINYRT:
at_3_0000:
    .zero 8
def_25_DQ7RAD_TINY:
at_3_0008:
    .zero 8
at_3_0010:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_7fffffffffffffff7fffffffffffffff:
at_5_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_5_0010:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_xmm_80000000000000008000000000000000:
at_6_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_6_0010:
end_s6:

# .xdata  (COFF section 7)
.section .s7,"dr"
def_15_xdata:
at_7_0000:
    .byte 0x01    # version 1
    .byte at_1_0057 - at_1_0000    # prologue size
    .byte 0x18    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0057 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0b
    .byte 0x00
    .byte at_1_004e - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x0c
    .byte 0x00
    .byte at_1_0045 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x0d
    .byte 0x00
    .byte at_1_003b - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x0e
    .byte 0x00
    .byte at_1_0031 - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x0f
    .byte 0x00
    .byte at_1_0027 - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x10
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x11
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x25
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_7_0034:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_17_rdata:
def_26_unnamed_1:
at_8_0000:
    .quad 0x0000000000000001
def_28_unnamed_2:
at_8_0008:
    .quad 0x0000000000000006
def_33_unnamed_3:
at_8_0010:
    .quad 0x0000000000000005
def_34_unnamed_4:
at_8_0018:
    .quad 0x0000000000000002
at_8_0020:
end_s8:

# .drectve  (COFF section 9)
.section .s9,"dr"
def_19_drectve:
at_9_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_9_00b9:
end_s9:

# .pdata  (COFF section 10)
.section .s10,"dr"
def_21_pdata:
at_10_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0838 - def_0_text)    # image-relative end
    .long ref_15_xdata    # image-relative unwind info
at_10_000c:
end_s10:

# MEMBER dq7apl.obj
# Entry points: DQ7APL
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_16_DQ7APL:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x58
at_1_0010:
    movaps XMMWORD PTR [rsp+0x40],xmm6
at_1_0015:
    mov    rsi,r9
    mov    rax,QWORD PTR [rsp+0xc8]
    mov    rax,QWORD PTR [rax]
    test   rax,rax
    je     at_1_003c
    mov    r15,rax
    neg    r15
    cmovs  r15,rax
    dec    r15
    test   r15,r15
    jg     at_1_0044
    jmp    at_1_00b3
at_1_003c:
    mov    r15,QWORD PTR [r8]
    test   r15,r15
    jle    at_1_00b3
at_1_0044:
    mov    r12,QWORD PTR [rcx]
    mov    rdi,QWORD PTR [rsp+0xc0]
    shl    r12,0x3
    mov    r13,QWORD PTR [rdx]
    add    r12,0x8
    xor    ebp,ebp
    lea    rbx,[rsp+0x38]
    movaps xmm6,XMMWORD PTR [rip + ref_8_xmm_80000000000000008000000000000000]
    lea    r14,[rsp+0x30]
    nop    DWORD PTR [rax]
at_1_0070:
    mov    QWORD PTR [rsp+0x38],r13
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,rdi
    call   ref_17_DD7TPR
    xorps  xmm0,xmm6
    movlps QWORD PTR [rsp+0x30],xmm0
    mov    QWORD PTR [rsp+0x20],rdi
    mov    rcx,rbx
    mov    rdx,rdi
    mov    r8,r14
    mov    r9,rsi
    call   ref_18_DV2AXY
    inc    rbp
    add    rdi,0x8
    add    rsi,r12
    dec    r13
    cmp    rbp,r15
    jl     at_1_0070
at_1_00b3:
    movaps xmm6,XMMWORD PTR [rsp+0x40]
    add    rsp,0x58
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_00c9:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_80000000000000008000000000000000:
at_4_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_4_0010:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_0015 - at_1_0000    # prologue size
    .byte 0x0b    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0015 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x04
    .byte 0x00
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0xa2
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_5_001c:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_11_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_13_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00c9 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dparck.obj
# Entry points: DPARCK
.intel_syntax noprefix
# Parameter checks and formatted diagnostics use DIVSET, DV7DFL and the Intel Fortran I/O interface.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DPARCK:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x688
at_1_0013:
    movapd XMMWORD PTR [rsp+0x670],xmm7
at_1_001c:
    movapd XMMWORD PTR [rsp+0x660],xmm6
at_1_0025:
    mov    rdi,r8
    mov    QWORD PTR [rsp+0x30],0x0
    mov    rax,QWORD PTR [r9]
    cmp    rax,0x15
    {disp32} jl     at_1_0107
    mov    rbp,QWORD PTR [rdi+0xa0]
    mov    QWORD PTR [rsp+0x30],rbp
    mov    r13,QWORD PTR [rcx]
    cmp    rax,0x33
    jb     at_1_0060
    cmp    r13,QWORD PTR [rdi+0x190]
    {disp32} jne    at_1_02ee
at_1_0060:
    mov    r8,r13
    add    r8,0xfffffffffffffffb
    cmp    r8,0xfffffffffffffffc
    {disp32} jae    at_1_011a
    mov    QWORD PTR [rdi],0x43
    test   rbp,rbp
    {disp32} je     at_1_1023
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x9a],0x10b0638
    mov    WORD PTR [rsp+0x9e],0x1
    mov    QWORD PTR [rsp+0x230],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x238],rbx
    mov    QWORD PTR [rsp+0x240],0x50
    mov    QWORD PTR [rsp+0x248],r13
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_03d4 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x9a]
    lea    r9,[rsp+0x230]
at_1_00fd:
    call   ref_17_for_write_int_fmt
    {disp32} jmp    at_1_0ffe
at_1_0107:
    mov    r13,QWORD PTR [rcx]
    lea    r8,[r13-0x5]
    cmp    r8,0xfffffffffffffffb
    {disp32} jbe    at_1_03d2
    xor    ebp,ebp
at_1_011a:
    lea    r8,[rip + ref_18_DPARCK_MINIV]
    mov    r12,QWORD PTR [r8+r13*8-0x8]
    add    r12,0xa
    mov    r14,QWORD PTR [rdi]
    cmp    r14,0xf
    {disp32} jne    at_1_023e
    test   rbp,rbp
    {disp32} je     at_1_0217
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x94],0x10b0638
    mov    WORD PTR [rsp+0x98],0x2
    mov    QWORD PTR [rsp+0x210],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x218],rbx
    mov    QWORD PTR [rsp+0x220],0x50
    mov    QWORD PTR [rsp+0x228],rax
    lea    rax,[rip + ref_16_DPARCK_format_pack]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x94]
    lea    r9,[rsp+0x210]
    mov    rcx,r14
    call   ref_17_for_write_int_fmt
    mov    DWORD PTR [rsp+0x90],0x1010b
    mov    QWORD PTR [rsp+0x158],r12
    lea    rdx,[rsp+0x90]
    lea    r8,[rsp+0x158]
    mov    rcx,r14
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rsi
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_20_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,rdi
    call   ref_21_WRITELINES
    mov    rax,QWORD PTR [rsi]
at_1_0217:
    cmp    rax,0x2c
    {disp32} jl     at_1_1023
    mov    QWORD PTR [rdi+0x158],r12
    {disp32} je     at_1_1023
    mov    QWORD PTR [rdi+0x160],0x0
    {disp32} jmp    at_1_1023
at_1_023e:
    mov    QWORD PTR [rsp+0x78],rdx
    mov    r11,QWORD PTR [rsp+0x700]
    lea    rax,[r13-0x1]
    add    r13,0xfffffffffffffffd
    cmp    rax,0x2
    cmovb  r13,rax
    mov    r15,QWORD PTR [rsp+0x6f0]
    lea    rsi,[r13+0x1]
    mov    QWORD PTR [rsp+0x40],rsi
    test   r14,r14
    jne    at_1_0295
    mov    QWORD PTR [rsp+0x20],r11
    mov    rdx,rdi
    mov    r8,r9
    mov    rbx,r9
    mov    r9,r15
    call   ref_22_DIVSET
    mov    r11,QWORD PTR [rsp+0x700]
    mov    r9,rbx
    mov    r14,QWORD PTR [rdi]
at_1_0295:
    mov    rax,QWORD PTR [rsp+0x6f8]
    lea    rcx,[r14-0xe]
    cmp    rcx,0xfffffffffffffffe
    {disp32} jae    at_1_03de
    lea    rcx,[r14-0xf]
    mov    rax,QWORD PTR [rax]
    cmp    rcx,0xfffffffffffffffc
    {disp32} ja     at_1_0401
    mov    r15,rax
    cmp    rax,QWORD PTR [rdi+0x128]
    {disp32} jne    at_1_0a02
    lea    rax,[r14-0x1]
    cmp    rax,0xb
    {disp32} jae    at_1_0e5d
    mov    eax,0x56204445
    mov    ecx,0x474e4148
    mov    edx,0x432d2d2d
    {disp32} jmp    at_1_047e
at_1_02ee:
    test   rbp,rbp
    {disp32} je     at_1_03d2
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x132],0x10b0638
    mov    WORD PTR [rsp+0x136],0x2
    mov    QWORD PTR [rsp+0x310],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x318],rbx
    mov    QWORD PTR [rsp+0x320],0x50
    mov    QWORD PTR [rsp+0x328],r13
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_07c4 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x132]
    lea    r9,[rsp+0x310]
    mov    rcx,r14
    call   ref_17_for_write_int_fmt
    mov    rax,QWORD PTR [rdi+0x190]
    mov    DWORD PTR [rsp+0x12e],0x1010b
    mov    QWORD PTR [rsp+0x1d8],rax
    lea    rdx,[rsp+0x12e]
    lea    r8,[rsp+0x1d8]
    mov    rcx,r14
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rsi
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_23_unnamed_2]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,rdi
    call   ref_21_WRITELINES
at_1_03d2:
    mov    QWORD PTR [rdi],0x43
    {disp32} jmp    at_1_1023
at_1_03de:
    mov    rcx,QWORD PTR [r9]
    cmp    rcx,0x3a
    {disp32} jl     at_1_088f
    mov    rdx,QWORD PTR [rdi+0x1c8]
    dec    rdx
    cmp    r12,rdx
    cmovle r12,rdx
    {disp32} jmp    at_1_0895
at_1_0401:
    mov    rcx,r15
    mov    r15,rax
    test   rax,rax
    {disp32} jle    at_1_0f1d
    mov    rcx,QWORD PTR [rcx]
at_1_0413:
    mov    rax,QWORD PTR [rdi+0x180]
    sub    rcx,rax
    add    rcx,0x13
    lea    r8,[r11+rax*8]
    add    r8,0xffffffffffffff68
    mov    QWORD PTR [rsp+0x1c8],rcx
    lea    rcx,[rsp+0x40]
    lea    rdx,[rsp+0x1c8]
    mov    rsi,r9
    call   ref_24_DV7DFL
    mov    r11,QWORD PTR [rsp+0x700]
    mov    r9,rsi
    mov    rsi,QWORD PTR [rsp+0x40]
    mov    eax,0x2
    sub    rax,rsi
    mov    QWORD PTR [rdi+0x1a8],rax
    mov    QWORD PTR [rdi+0x128],r15
    mov    eax,0x5620544c
    mov    ecx,0x55414645
    mov    edx,0x444e4f4e
at_1_047e:
    mov    QWORD PTR [rsp+0x150],r15
    mov    DWORD PTR [rsp+0x138],edx
    mov    DWORD PTR [rsp+0x13c],ecx
    mov    DWORD PTR [rsp+0x140],eax
    cmp    r14,0xe
    mov    eax,0xc
    cmovne rax,r14
    mov    QWORD PTR [rsp+0x148],rax
    movsd  xmm0,QWORD PTR [rip + ref_25_DPARCK_BIG]
    ucomisd xmm0,QWORD PTR [rip + ref_26_DPARCK_TINY]
    {disp32} ja     at_1_05d1
    lea    rcx,[rip + ref_27_unnamed_3]
    mov    rsi,r9
    call   ref_28_DR7MDC
    movsd  QWORD PTR [rip + ref_26_DPARCK_TINY],xmm0
    lea    rcx,[rip + ref_29_unnamed_4]
    call   ref_28_DR7MDC
    movsd  QWORD PTR [rip + ref_30_DPARCK_MACHEP],xmm0
    lea    rcx,[rip + ref_31_unnamed_5]
    call   ref_28_DR7MDC
    movsd  QWORD PTR [rip + ref_25_DPARCK_BIG],xmm0
    movsd  xmm1,QWORD PTR [rip + ref_30_DPARCK_MACHEP]
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_0178 - def_32_DPARCK_VM)],xmm1
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_0058 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_0060 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_0188 - def_32_DPARCK_VM)],xmm1
    movsd  xmm2,QWORD PTR [rip + ref_26_DPARCK_TINY]
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_01a0 - def_32_DPARCK_VM)],xmm2
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_0080 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_01a8 - def_32_DPARCK_VM)],xmm2
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_0088 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_0098 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_00a0 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_00a8 - def_33_DPARCK_VX)],xmm0
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_01d8 - def_32_DPARCK_VM)],xmm1
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_01e0 - def_32_DPARCK_VM)],xmm1
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_01e8 - def_32_DPARCK_VM)],xmm1
    lea    rcx,[rip + ref_20_unnamed_1]
    call   ref_28_DR7MDC
    mov    r11,QWORD PTR [rsp+0x700]
    mov    r9,rsi
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_00d8 - def_33_DPARCK_VX)],xmm0
    movsd  xmm0,QWORD PTR [rip + ref_30_DPARCK_MACHEP]
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_0200 - def_32_DPARCK_VM)],xmm0
    movsd  xmm1,QWORD PTR [rip + ref_25_DPARCK_BIG]
    movsd  QWORD PTR [rip + ref_33_DPARCK_VX + (at_2_00e8 - def_33_DPARCK_VX)],xmm1
    movsd  QWORD PTR [rip + ref_32_DPARCK_VM + (at_2_0220 - def_32_DPARCK_VM)],xmm0
    mov    rsi,QWORD PTR [rsp+0x40]
at_1_05d1:
    mov    QWORD PTR [rsp+0x80],r9
    mov    QWORD PTR [rsp+0x38],rdi
    lea    rax,[rip + ref_34_DPARCK_JLIM]
    lea    rcx,[rip + ref_35_DPARCK_NDFLT]
    mov    r13,QWORD PTR [rcx+rsi*8-0x8]
    test   r13,r13
    {disp32} jle    at_1_0be1
    mov    rdx,QWORD PTR [rax+rsi*8-0x8]
    mov    r12d,0x1
    xor    r15d,r15d
    lea    rdi,[rip + ref_32_DPARCK_VM]
    lea    rsi,[rip + ref_33_DPARCK_VX]
    mov    ecx,0x21
    xor    r14d,r14d
    mov    QWORD PTR [rsp+0x88],rdx
    jmp    at_1_0646
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0630:
    inc    r12
    cmp    r12,rdx
    cmove  r12,rcx
    inc    r15
    cmp    r15,r13
    {disp32} jge    at_1_0be4
at_1_0646:
    movsd  xmm6,QWORD PTR [r11+r15*8+0x90]
    movsd  xmm0,QWORD PTR [rsi+r12*8-0x8]
    ucomisd xmm0,xmm6
    setae  al
    ucomisd xmm6,QWORD PTR [rdi+r12*8-0x8]
    jb     at_1_066b
    test   al,al
    jne    at_1_0630
at_1_066b:
    lea    r14,[r15+0x13]
    cmp    QWORD PTR [rsp+0x30],0x0
    je     at_1_0630
    mov    rbp,r14
    mov    r14,rsi
    mov    rsi,rdi
    lea    rdi,[r12-0x1]
    lea    rax,[rip + ref_36_DPARCK_VN]
    lea    rax,[rax+rdi*8]
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x10a],0x6380638
    mov    WORD PTR [rsp+0x10e],0x2
    mov    QWORD PTR [rsp+0x3f0],0x1e0
    lea    rcx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x3f8],rcx
    mov    QWORD PTR [rsp+0x400],0x50
    mov    QWORD PTR [rsp+0x408],0x4
    mov    QWORD PTR [rsp+0x410],rax
    mov    QWORD PTR [rsp+0x418],0x4
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_065c - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rbx,[rsp+0x48]
    mov    rcx,rbx
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x10a]
    lea    r9,[rsp+0x3f0]
    call   ref_17_for_write_int_fmt
    lea    rax,[rip + ref_36_DPARCK_VN]
    lea    rax,[rax+rdi*8]
    add    rax,0x4
    mov    rdi,rsi
    mov    rsi,r14
    mov    r14,rbp
    mov    DWORD PTR [rsp+0x106],0x20638
    mov    QWORD PTR [rsp+0x1f8],0x4
    mov    QWORD PTR [rsp+0x200],rax
    mov    QWORD PTR [rsp+0x208],0x4
    mov    rcx,rbx
    lea    rdx,[rsp+0x106]
    lea    r8,[rsp+0x1f8]
    call   ref_19_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x102],0x2010b
    mov    QWORD PTR [rsp+0x1b0],rbp
    mov    rcx,rbx
    lea    rdx,[rsp+0x102]
    lea    r8,[rsp+0x1b0]
    call   ref_19_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0xfe],0x20130
    movsd  QWORD PTR [rsp+0x1a8],xmm6
    mov    rcx,rbx
    lea    rdx,[rsp+0xfe]
    lea    r8,[rsp+0x1a8]
    call   ref_19_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [rdi+r12*8-0x8]
    mov    DWORD PTR [rsp+0xfa],0x20130
    movsd  QWORD PTR [rsp+0x1a0],xmm0
    mov    rcx,rbx
    lea    rdx,[rsp+0xfa]
    lea    r8,[rsp+0x1a0]
    call   ref_19_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [rsi+r12*8-0x8]
    mov    DWORD PTR [rsp+0xf6],0x10130
    movsd  QWORD PTR [rsp+0x198],xmm0
    mov    rcx,rbx
    lea    rdx,[rsp+0xf6]
    lea    r8,[rsp+0x198]
    call   ref_19_for_write_int_fmt_xmit
    mov    rax,QWORD PTR [rsp+0x80]
    mov    QWORD PTR [rsp+0x20],rax
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_20_unnamed_1]
    lea    rdx,[rsp+0x480]
    lea    r8,[rsp+0x30]
    mov    r9,QWORD PTR [rsp+0x38]
    call   ref_21_WRITELINES
    mov    rdx,QWORD PTR [rsp+0x88]
    mov    ecx,0x21
    mov    r11,QWORD PTR [rsp+0x700]
    {disp32} jmp    at_1_0630
at_1_088f:
    cmp    rcx,0x3
    jl     at_1_08b2
at_1_0895:
    mov    rdx,QWORD PTR [rdi+0x10]
    xor    esi,esi
    test   rdx,rdx
    cmovg  rsi,rdx
    add    rsi,r12
    cmp    rcx,0x2c
    jb     at_1_08b2
    mov    QWORD PTR [rdi+0x158],rsi
at_1_08b2:
    cmp    rcx,r12
    jl     at_1_08f2
    xorpd  xmm0,xmm0
    mov    r8,QWORD PTR [rdi+0x18]
    mov    rdx,QWORD PTR [rdi+0x148]
    mov    r10,r9
    xor    r9d,r9d
    test   r8,r8
    cmovg  r9,r8
    movupd XMMWORD PTR [rdi+0x10],xmm0
    lea    r8,[rdx+r9*1]
    dec    r8
    mov    r9,r10
    mov    QWORD PTR [rdi+0x160],r8
    cmp    rcx,rsi
    {disp32} jge    at_1_0b12
at_1_08f2:
    mov    QWORD PTR [rdi],0xf
    test   rbp,rbp
    {disp32} je     at_1_1023
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xae],0x10b0638
    mov    WORD PTR [rsp+0xb2],0x2
    mov    QWORD PTR [rsp+0x270],0x1e0
    mov    r14,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x278],rbx
    mov    QWORD PTR [rsp+0x280],0x50
    mov    QWORD PTR [rsp+0x288],rcx
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_0464 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    mov    r13,r15
    lea    r15,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xae]
    lea    r9,[rsp+0x270]
    mov    rcx,r15
    call   ref_17_for_write_int_fmt
    mov    DWORD PTR [rsp+0xaa],0x1010b
    mov    QWORD PTR [rsp+0x168],rsi
    lea    rdx,[rsp+0xaa]
    lea    r8,[rsp+0x168]
    mov    rcx,r15
    mov    rsi,r13
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],r14
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_20_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,rdi
    call   ref_21_WRITELINES
    cmp    QWORD PTR [r14],r12
    {disp32} jl     at_1_1023
    mov    rcx,QWORD PTR [rsi]
    cmp    rcx,QWORD PTR [rdi+0x160]
    {disp32} jge    at_1_1023
    mov    r9,r14
    mov    rbp,QWORD PTR [rsp+0x30]
    {disp32} jmp    at_1_0b1e
at_1_0a02:
    mov    QWORD PTR [rdi],0x11
    test   rbp,rbp
    {disp32} je     at_1_1023
    lea    rax,[rip + ref_37_DPARCK_VARNM]
    add    rax,r13
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x11e],0x6380638
    mov    WORD PTR [rsp+0x122],0x2
    mov    QWORD PTR [rsp+0x420],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x428],rbx
    mov    QWORD PTR [rsp+0x430],0x50
    mov    QWORD PTR [rsp+0x438],0x1
    mov    QWORD PTR [rsp+0x440],rax
    mov    QWORD PTR [rsp+0x448],0x1
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_0734 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x11e]
    lea    r9,[rsp+0x420]
    mov    rcx,r14
    call   ref_17_for_write_int_fmt
    mov    rax,QWORD PTR [rdi+0x128]
    mov    DWORD PTR [rsp+0x11a],0x2010b
    mov    QWORD PTR [rsp+0x1c0],rax
    lea    rdx,[rsp+0x11a]
    lea    r8,[rsp+0x1c0]
    mov    rcx,r14
    call   ref_19_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x116],0x1010b
    mov    QWORD PTR [rsp+0x1b8],r15
    lea    rdx,[rsp+0x116]
    lea    r8,[rsp+0x1b8]
    {disp32} jmp    at_1_0ff6
at_1_0b12:
    mov    rcx,QWORD PTR [r15]
    cmp    rcx,r8
    {disp32} jge    at_1_0eee
at_1_0b1e:
    mov    QWORD PTR [rdi],0x10
    test   rbp,rbp
    {disp32} je     at_1_1023
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xa4],0x10b0638
    mov    WORD PTR [rsp+0xa8],0x2
    mov    QWORD PTR [rsp+0x250],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x258],rbx
    mov    QWORD PTR [rsp+0x260],0x50
    mov    QWORD PTR [rsp+0x268],rcx
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_0418 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xa4]
    lea    r9,[rsp+0x250]
    mov    rcx,r14
    call   ref_17_for_write_int_fmt
    mov    rax,QWORD PTR [rdi+0x160]
    mov    DWORD PTR [rsp+0xa0],0x1010b
    mov    QWORD PTR [rsp+0x160],rax
    lea    rdx,[rsp+0xa0]
    lea    r8,[rsp+0x160]
    {disp32} jmp    at_1_0ff6
at_1_0be1:
    xor    r14d,r14d
at_1_0be4:
    mov    r15,QWORD PTR [rsp+0x38]
    mov    rax,QWORD PTR [r15+0x188]
    cmp    rax,r13
    {disp32} jne    at_1_0d5d
    cmp    QWORD PTR [r15+0x78],0x0
    setg   al
    movsd  xmm0,QWORD PTR [r11+0x128]
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    seta   cl
    or     cl,al
    cmp    QWORD PTR [rsp+0x148],0xc
    sete   al
    test   cl,al
    mov    rbx,QWORD PTR [rsp+0x80]
    {disp32} jne    at_1_0e4c
    mov    rbp,QWORD PTR [rsp+0x150]
    test   rbp,rbp
    {disp32} jle    at_1_0e4c
    xor    esi,esi
    xorpd  xmm6,xmm6
    lea    r13,[rsp+0x480]
    lea    rdi,[rip + ref_16_DPARCK_format_pack + (at_2_05c0 - def_16_DPARCK_format_pack)]
    lea    r12,[rsp+0x48]
    mov    rax,QWORD PTR [rsp+0x78]
    jmp    at_1_0c79
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0c70:
    cmp    rsi,rbp
    {disp32} jge    at_1_0e4c
at_1_0c79:
    movsd  xmm7,QWORD PTR [rax+rsi*8]
    inc    rsi
    ucomisd xmm7,xmm6
    ja     at_1_0c70
    mov    r14d,0x12
    cmp    QWORD PTR [rsp+0x30],0x0
    je     at_1_0c70
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xe6],0x10b0638
    mov    WORD PTR [rsp+0xea],0x2
    mov    QWORD PTR [rsp+0x2b0],0x1e0
    mov    QWORD PTR [rsp+0x2b8],r13
    mov    QWORD PTR [rsp+0x2c0],0x50
    mov    QWORD PTR [rsp+0x2c8],rsi
    mov    QWORD PTR [rsp+0x20],rdi
    mov    rcx,r12
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xe6]
    lea    r9,[rsp+0x2b0]
    call   ref_17_for_write_int_fmt
    mov    DWORD PTR [rsp+0xe2],0x10130
    movsd  QWORD PTR [rsp+0x188],xmm7
    mov    rcx,r12
    lea    rdx,[rsp+0xe2]
    lea    r8,[rsp+0x188]
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_20_unnamed_1]
    mov    rdx,r13
    lea    r8,[rsp+0x30]
    mov    r9,r15
    call   ref_21_WRITELINES
    mov    rax,QWORD PTR [rsp+0x78]
    {disp32} jmp    at_1_0c70
at_1_0d5d:
    mov    QWORD PTR [r15],0x33
    cmp    QWORD PTR [rsp+0x30],0x0
    mov    rcx,QWORD PTR [rsp+0x80]
    {disp32} je     at_1_1023
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xf0],0x10b0638
    mov    WORD PTR [rsp+0xf4],0x2
    mov    QWORD PTR [rsp+0x2d0],0x1e0
    mov    rsi,rcx
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x2d8],rbx
    mov    QWORD PTR [rsp+0x2e0],0x50
    mov    QWORD PTR [rsp+0x2e8],rax
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_0610 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0x48]
    lea    r8,[rsp+0xf0]
    lea    r9,[rsp+0x2d0]
    mov    rcx,r14
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    DWORD PTR [rsp+0xec],0x1010b
    mov    QWORD PTR [rsp+0x190],r13
    lea    rdx,[rsp+0xec]
    lea    r8,[rsp+0x190]
    mov    rcx,r14
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rsi
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_23_unnamed_2]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,r15
    {disp32} jmp    at_1_101e
at_1_0e4c:
    test   r14,r14
    {disp32} je     at_1_1047
    mov    QWORD PTR [r15],r14
    {disp32} jmp    at_1_1023
at_1_0e5d:
    mov    QWORD PTR [rdi],0x50
    test   rbp,rbp
    {disp32} je     at_1_1023
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x110],0x10b0638
    mov    WORD PTR [rsp+0x114],0x1
    mov    QWORD PTR [rsp+0x2f0],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x2f8],rbx
    mov    QWORD PTR [rsp+0x300],0x50
    mov    QWORD PTR [rsp+0x308],r14
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_06e8 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x110]
    lea    r9,[rsp+0x2f0]
    {disp32} jmp    at_1_00fd
at_1_0eee:
    mov    rax,QWORD PTR [rax]
    mov    r15,rax
    test   rax,rax
    jle    at_1_0f1d
    mov    rax,QWORD PTR [rdi+0x1c8]
    mov    QWORD PTR [rdi+0x168],rax
    mov    QWORD PTR [rdi+0x170],rdx
    cmp    r14,0xd
    {disp32} jne    at_1_0413
    {disp32} jmp    at_1_1023
at_1_0f1d:
    mov    QWORD PTR [rdi],0x51
    test   rbp,rbp
    {disp32} je     at_1_1023
    lea    rax,[rip + ref_37_DPARCK_VARNM]
    add    rax,r13
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0x128],0x6380638
    mov    WORD PTR [rsp+0x12c],0x2
    mov    QWORD PTR [rsp+0x450],0x1e0
    mov    rsi,r9
    lea    rbx,[rsp+0x480]
    mov    QWORD PTR [rsp+0x458],rbx
    mov    QWORD PTR [rsp+0x460],0x50
    mov    QWORD PTR [rsp+0x468],0x1
    mov    QWORD PTR [rsp+0x470],rax
    mov    QWORD PTR [rsp+0x478],0x1
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_078c - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x128]
    lea    r9,[rsp+0x450]
    mov    rcx,r14
    call   ref_17_for_write_int_fmt
    mov    DWORD PTR [rsp+0x124],0x1010b
    mov    QWORD PTR [rsp+0x1d0],r15
    lea    rdx,[rsp+0x124]
    lea    r8,[rsp+0x1d0]
at_1_0ff6:
    mov    rcx,r14
    call   ref_19_for_write_int_fmt_xmit
at_1_0ffe:
    mov    QWORD PTR [rsp+0x20],rsi
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_20_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,rdi
at_1_101e:
    call   ref_21_WRITELINES
at_1_1023:
    movaps xmm6,XMMWORD PTR [rsp+0x660]
    movaps xmm7,XMMWORD PTR [rsp+0x670]
    add    rsp,0x688
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_1047:
    cmp    QWORD PTR [rsp+0x30],0x0
    je     at_1_1023
    cmp    QWORD PTR [r15+0x98],0x0
    je     at_1_1023
    cmp    QWORD PTR [rsp+0x148],0xc
    {disp32} jne    at_1_11a3
    mov    rax,QWORD PTR [rsp+0x40]
    dec    rax
    cmp    QWORD PTR [r15+0xc0],rax
    {disp32} je     at_1_11a3
    lea    rcx,[rip + ref_38_DPARCK_SH]
    add    rcx,rax
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xdc],0x6380638
    mov    WORD PTR [rsp+0xe0],0x2
    mov    QWORD PTR [rsp+0x3c0],0x1e0
    lea    r14,[rsp+0x480]
    mov    QWORD PTR [rsp+0x3c8],r14
    mov    QWORD PTR [rsp+0x3d0],0x50
    mov    QWORD PTR [rsp+0x3d8],0x1
    mov    QWORD PTR [rsp+0x3e0],rcx
    mov    QWORD PTR [rsp+0x3e8],0x1
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_055c - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r15,[rsp+0x48]
    lea    r8,[rsp+0xdc]
    lea    r9,[rsp+0x3c0]
    mov    rcx,r15
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    rax,QWORD PTR [rsp+0x38]
    mov    rax,QWORD PTR [rax+0xc0]
    mov    DWORD PTR [rsp+0xd8],0x1010b
    mov    QWORD PTR [rsp+0x180],rax
    lea    rdx,[rsp+0xd8]
    lea    r8,[rsp+0x180]
    mov    rcx,r15
    mov    r15,QWORD PTR [rsp+0x38]
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_29_unnamed_4]
    lea    r8,[rsp+0x30]
    mov    rdx,r14
    mov    r9,r15
    call   ref_21_WRITELINES
    mov    rcx,QWORD PTR [r15+0x78]
    mov    eax,0x1
    cmp    rcx,QWORD PTR [r15+0x1a8]
    lea    rsi,[rip + ref_35_DPARCK_NDFLT]
    {disp32} jne    at_1_1285
    {disp32} jmp    at_1_132d
at_1_11a3:
    mov    rax,QWORD PTR [r15+0x78]
    cmp    rax,QWORD PTR [r15+0x1a8]
    lea    rsi,[rip + ref_35_DPARCK_NDFLT]
    jne    at_1_11be
    xor    eax,eax
    {disp32} jmp    at_1_132d
at_1_11be:
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xd2],0x6380638
    mov    WORD PTR [rsp+0xd6],0x1
    mov    QWORD PTR [rsp+0x390],0x1e0
    lea    r14,[rsp+0x480]
    mov    QWORD PTR [rsp+0x398],r14
    mov    QWORD PTR [rsp+0x3a0],0x50
    mov    QWORD PTR [rsp+0x3a8],0xc
    lea    rax,[rsp+0x138]
    mov    QWORD PTR [rsp+0x3b0],rax
    mov    QWORD PTR [rsp+0x3b8],0x4
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_04fc - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x48]
    lea    r8,[rsp+0xd2]
    lea    r9,[rsp+0x390]
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_29_unnamed_4]
    lea    r8,[rsp+0x30]
    mov    rdx,r14
    mov    r9,r15
    call   ref_21_WRITELINES
    mov    rcx,QWORD PTR [r15+0x78]
at_1_1285:
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xcc],0x10b0638
    mov    WORD PTR [rsp+0xd0],0x1
    mov    QWORD PTR [rsp+0x290],0x1e0
    lea    r14,[rsp+0x480]
    mov    QWORD PTR [rsp+0x298],r14
    mov    QWORD PTR [rsp+0x2a0],0x50
    mov    QWORD PTR [rsp+0x2a8],rcx
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_0530 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x48]
    lea    r8,[rsp+0xcc]
    lea    r9,[rsp+0x290]
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_27_unnamed_3]
    lea    r8,[rsp+0x30]
    mov    rdx,r14
    mov    r9,r15
    call   ref_21_WRITELINES
    mov    eax,0x1
at_1_132d:
    lea    rcx,[r15+0x188]
    mov    QWORD PTR [rsp+0x88],rcx
    mov    rcx,QWORD PTR [rsp+0x40]
    mov    r13,QWORD PTR [rsi+rcx*8-0x8]
    test   r13,r13
    mov    rdi,QWORD PTR [rsp+0x700]
    {disp32} jle    at_1_1633
    lea    rdx,[rip + ref_34_DPARCK_JLIM]
    mov    rsi,QWORD PTR [rdx+rcx*8-0x8]
    mov    rcx,QWORD PTR [rsp+0x38]
    mov    rcx,QWORD PTR [rcx+0x180]
    lea    rbp,[rdi+rcx*8]
    add    rbp,0xfffffffffffffff8
    mov    r12d,0x1
    xor    r14d,r14d
    mov    r9d,0x21
    mov    QWORD PTR [rsp+0x78],r13
    {disp32} jmp    at_1_1545
at_1_1390:
    lea    rbx,[r14+0x13]
    lea    rdi,[rip + ref_36_DPARCK_VN]
    lea    rax,[rdi+r12*8]
    add    rax,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xc0],0x6380638
    mov    WORD PTR [rsp+0xc4],0x2
    mov    QWORD PTR [rsp+0x330],0x1e0
    lea    r13,[rsp+0x480]
    mov    QWORD PTR [rsp+0x338],r13
    mov    QWORD PTR [rsp+0x340],0x50
    mov    QWORD PTR [rsp+0x348],0x4
    mov    QWORD PTR [rsp+0x350],rax
    mov    QWORD PTR [rsp+0x358],0x4
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_04b0 - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r15,[rsp+0x48]
    mov    rcx,r15
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xc0]
    lea    r9,[rsp+0x330]
    call   ref_17_for_write_int_fmt
    lea    rax,[rdi+r12*8]
    add    rax,0xfffffffffffffffc
    mov    DWORD PTR [rsp+0xbc],0x20638
    mov    QWORD PTR [rsp+0x1e0],0x4
    mov    QWORD PTR [rsp+0x1e8],rax
    mov    QWORD PTR [rsp+0x1f0],0x4
    mov    rcx,r15
    lea    rdx,[rsp+0xbc]
    lea    r8,[rsp+0x1e0]
    call   ref_19_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0xb8],0x2010b
    mov    QWORD PTR [rsp+0x178],rbx
    mov    rbx,QWORD PTR [rsp+0x80]
    mov    rcx,r15
    lea    rdx,[rsp+0xb8]
    lea    r8,[rsp+0x178]
    call   ref_19_for_write_int_fmt_xmit
    mov    rdi,QWORD PTR [rsp+0x700]
    movsd  xmm0,QWORD PTR [rdi+r14*8+0x90]
    mov    DWORD PTR [rsp+0xb4],0x10130
    movsd  QWORD PTR [rsp+0x170],xmm0
    mov    rcx,r15
    lea    rdx,[rsp+0xb4]
    lea    r8,[rsp+0x170]
    call   ref_19_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_27_unnamed_3]
    mov    rdx,r13
    lea    r8,[rsp+0x30]
    mov    r9,QWORD PTR [rsp+0x38]
    call   ref_21_WRITELINES
    mov    eax,0x1
    mov    r9d,0x21
    mov    r13,QWORD PTR [rsp+0x78]
at_1_152f:
    inc    r12
    cmp    r12,rsi
    cmove  r12,r9
    inc    r14
    cmp    r14,r13
    {disp32} jge    at_1_1633
at_1_1545:
    movsd  xmm0,QWORD PTR [rdi+r14*8+0x90]
    ucomisd xmm0,QWORD PTR [rbp+r14*8+0x0]
    setnp  cl
    sete   dl
    test   dl,cl
    jne    at_1_152f
    test   rax,rax
    {disp32} jne    at_1_1390
    mov    QWORD PTR [rsp+0x48],0x0
    mov    DWORD PTR [rsp+0xc6],0x6380638
    mov    WORD PTR [rsp+0xca],0x1
    mov    QWORD PTR [rsp+0x360],0x1e0
    lea    rdi,[rsp+0x480]
    mov    QWORD PTR [rsp+0x368],rdi
    mov    QWORD PTR [rsp+0x370],0x50
    mov    QWORD PTR [rsp+0x378],0xc
    lea    rax,[rsp+0x138]
    mov    QWORD PTR [rsp+0x380],rax
    mov    QWORD PTR [rsp+0x388],0x4
    lea    rax,[rip + ref_16_DPARCK_format_pack + (at_2_04fc - def_16_DPARCK_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x48]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xc6]
    lea    r9,[rsp+0x360]
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_29_unnamed_4]
    mov    rdx,rdi
    lea    r8,[rsp+0x30]
    mov    r9,QWORD PTR [rsp+0x38]
    call   ref_21_WRITELINES
    {disp32} jmp    at_1_1390
at_1_1633:
    mov    rdx,QWORD PTR [rsp+0x38]
    mov    rax,QWORD PTR [rdx+0x78]
    mov    rcx,QWORD PTR [rdx+0x180]
    mov    QWORD PTR [rdx+0x1a8],rax
    lea    rdx,[rdi+rcx*8]
    add    rdx,0xfffffffffffffff8
    add    rdi,0x90
    mov    rcx,QWORD PTR [rsp+0x88]
    mov    r8,rdi
    call   ref_39_DV7CPY
    {disp32} jmp    at_1_1023
at_1_166e:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_33_DPARCK_VX:
at_2_0000:
    .quad 0x3feccccccccccccd
    .quad 0xbf50624dd2f1a9fc
    .quad 0x4024000000000000
    .quad 0x3fe999999999999a
    .quad 0x4059000000000000
    .quad 0x3fe999999999999a
    .quad 0x4059000000000000
    .quad 0x3fe0000000000000
    .quad 0x3fe0000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
at_2_0058:
    .zero 8
at_2_0060:
    .quad 0x0000000000000000
    .quad 0x3fb999999999999a
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
at_2_0080:
    .zero 8
at_2_0088:
    .quad 0x0000000000000000
    .quad 0x3ff0000000000000
at_2_0098:
    .zero 8
at_2_00a0:
    .zero 8
at_2_00a8:
    .quad 0x0000000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
    .quad 0x4202a05f20000000
at_2_00d8:
    .quad 0x0000000000000000
    .quad 0x3ff0000000000000
at_2_00e8:
    .quad 0x0000000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
    .quad 0x3ff0000000000000
    .quad 0x0000000000000000
    .quad 0x0000000000000000
def_32_DPARCK_VM:
at_2_0120:
    .long 0xd2f1a9fc
    .ascii "MbP?"
    .quad 0xbfefae147ae147ae
    .long 0xd2f1a9fc
    .ascii "MbP?{"
    .long 0xe147ae14
    .short 0x847a
    .ascii "?333333"
    .quad 0x7ae147ae147b3ff3
    .byte 0x84
    .ascii "?333333"
    .quad 0x0000000000003ff3
    .quad 0x0000000000000000
    .long 0xa9fc0000
    .short 0xd2f1
    .ascii "MbP?"
    .quad 0xbff0000000000000
at_2_0178:
    .zero 16
at_2_0188:
    .zero 24
at_2_01a0:
    .zero 8
at_2_01a8:
    .quad 0x0000000000000000
    .quad 0x0000000000000000
    .quad 0xc024000000000000
    .quad 0x0000000000000000
    .quad 0x0000000000000000
    .quad 0x0000000000000000
at_2_01d8:
    .zero 8
at_2_01e0:
    .zero 8
at_2_01e8:
    .quad 0x0000000000000000
    .quad 0x3ff028f5c28f5c29
    .quad 0x4202a05f20000000
at_2_0200:
    .zero 32
at_2_0220:
    .zero 16
def_26_DPARCK_TINY:
at_2_0230:
    .quad 0x3ff0000000000000
def_30_DPARCK_MACHEP:
at_2_0238:
    .quad 0xbff0000000000000
def_36_DPARCK_VN:
at_2_0240:
    .ascii "EPSLON..PHMNFC..PHMXFC..DECFAC..INCFAC..RDFCMN..RDFCMX..TUNER1..TUNER2..TUNER3..TUNER4..TUNER5..AFCTOL..RFCTOL..XCTOL...XFTOL...LMAX0...LMAXS...SCTOL...DINIT...DTINIT..D0INIT..DFAC....DLTFDC..DLTFDJ..DELTA0..FUZZ....RLIMIT..COSMIN..HUBERC..RSPTOL..SIGMIN..ETA0....BIAS...."
def_38_DPARCK_SH:
at_2_0350:
    .quad 0x0000000000004853
def_37_DPARCK_VARNM:
at_2_0358:
    .long 0x00005050
def_16_DPARCK_format_pack:
at_2_035c:
    .quad 0x0001004700000036
    .long 0x000a001c
    .ascii " /// LIV ="
    .quad 0x0001000000240000
    .quad 0x001c000000050000
    .short 0x0011
    .ascii " MUST BE AT LEAST"
    .quad 0x0100000024000000
    .quad 0x1c00000005000000
    .short 0x2500
    .byte 0x00
    .ascii " TO COMPUTE TRUE MIN. LIV AND MIN. LV"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_03d4:
    .quad 0x0001004700000036
    .long 0x000a001c
    .ascii " /// ALG ="
    .quad 0x0001000000240000
    .quad 0x001c000000050000
    .short 0x0015
    .ascii " MUST BE 1 2, 3, OR 4"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_0418:
    .quad 0x0001004700000036
    .long 0x0009001c
    .ascii " /// LV ="
    .quad 0x0100000024000000
    .quad 0x1c00000005000000
    .short 0x1100
    .byte 0x00
    .ascii " MUST BE AT LEAST"
    .quad 0x0100000024000000
    .quad 0x3700000005000000
    .short 0x0000
    .byte 0x00
at_2_0464:
    .quad 0x0001004700000036
    .long 0x000a001c
    .ascii " /// LIV ="
    .quad 0x0001000000240000
    .quad 0x001c000000050000
    .short 0x0011
    .ascii " MUST BE AT LEAST"
    .quad 0x0100000024000000
    .quad 0x3700000005000000
    .short 0x0000
    .byte 0x00
at_2_04b0:
    .quad 0x0000000e00000036
    .quad 0x0000000100000001
    .quad 0x000000020000001d
    .quad 0x0005001c00000004
    .ascii ".. V("
    .quad 0x0100000024000000
    .quad 0x1c00000002000000
    .quad 0x1e003d2029000300
    .quad 0x0f00000001070000
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_04fc:
    .quad 0x0001004700000036
    .quad 0x000000200001001c
    .quad 0x000000030000001d
    .quad 0x0009001c00000004
    .ascii "ALUES...."
    .quad 0x3700010047000000
    .short 0x0000
    .byte 0x00
at_2_0530:
    .quad 0x0014001c00000036
    .ascii " DTYPE..... IV(16) =$"
    .quad 0x0300000001000000
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_055c:
    .quad 0x0001004700000036
    .long 0x0016001c
    .ascii " NONDEFAULT VALUES...."
    .quad 0x001c000100470000
    .short 0x0005
    .ascii " INIT"
    .quad 0x010000001d000000
    .quad 0x1c00000001000000
    .short 0x0e00
    .byte 0x00
    .ascii "..... IV(25) ="
    .quad 0x0001000000240000
    .quad 0x0037000000030000
    .short 0x0000
at_2_05c0:
    .quad 0x0001004700000036
    .long 0x0008001c
    .ascii " ///  D($"
    .quad 0x0300000001000000
    .quad 0x290003001c000000
    .quad 0x010300001e003d20
    .quad 0x1c0000000b000000
    .short 0x1300
    .byte 0x00
    .ascii " SHOULD BE POSITIVE"
    .long 0x00003700
    .byte 0x00
at_2_0610:
    .quad 0x0001004700000036
    .long 0x000d001c
    .ascii " IV(NVDFLT) ="
    .quad 0x0100000024000000
    .quad 0x1c00000005000000
    .short 0x0d00
    .byte 0x00
    .ascii " RATHER THAN "
    .quad 0x0100000024000000
    .quad 0x3700000005000000
    .short 0x0000
    .byte 0x00
at_2_065c:
    .quad 0x0001004700000036
    .long 0x0006001c
    .ascii " ///  "
    .quad 0x00020000001d0000
    .quad 0x001c000000040000
    .short 0x0005
    .ascii ".. V("
    .quad 0x0100000024000000
    .quad 0x1c00000002000000
    .quad 0x1e003d2029000300
    .quad 0x0b00000001030000
    .long 0x1c000000
    .short 0x0700
    .byte 0x00
    .ascii " SHOULD"
    .long 0x0b001c00
    .byte 0x00
    .ascii " BE BETWEEN"
    .quad 0x0000010300001e00
    .quad 0x04001c0000000b00
    .byte 0x00
    .ascii " AND"
    .quad 0x000000010300001e
    .quad 0x000000370000000b
at_2_06e8:
    .quad 0x0001004700000036
    .long 0x000d001c
    .ascii " ///  IV(1) ="
    .quad 0x0100000024000000
    .quad 0x1c00000005000000
    .short 0x1c00
    .byte 0x00
    .ascii " SHOULD BE BETWEEN 0 AND 14.7"
    .zero 3
at_2_0734:
    .quad 0x0001004700000036
    .long 0x0005001c
    .ascii " /// "
    .quad 0x010000001d000000
    .quad 0x1c00000001000000
    .short 0x0e00
    .byte 0x00
    .ascii " CHANGED FROM "
    .quad 0x0001000000240000
    .quad 0x001c000000050000
    .short 0x0004
    .ascii " TO $"
    .quad 0x0500000001000000
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_078c:
    .quad 0x0001004700000036
    .long 0x0008001c
    .ascii " /// BAD"
    .quad 0x000000010000001d
    .quad 0x0002001c00000001
    .quad 0x0000002400003d20
    .quad 0x0000000500000001
    .long 0x00000037
at_2_07c4:
    .quad 0x0001004700000036
    .long 0x0028001c
    .ascii " THE FIRST PARAMETER TO DIVSET SHOULD BE$"
    .quad 0x0300000001000000
    .long 0x1c000000
    .short 0x0c00
    .byte 0x00
    .ascii " RATHER THAN$"
    .quad 0x0300000001000000
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_0824:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_25_DPARCK_BIG:
at_3_0000:
    .zero 8
at_3_0008:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0025 - at_1_0000    # prologue size
    .byte 0x0e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0025 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x66
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x67
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0xd1
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0020:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_35_DPARCK_NDFLT:
at_5_0000:
    .quad 0x0000000000000020
    .quad 0x0000000000000019
    .quad 0x0000000000000020
    .quad 0x0000000000000019
def_18_DPARCK_MINIV:
at_5_0020:
    .quad 0x0000000000000052
    .quad 0x000000000000003b
    .quad 0x0000000000000067
    .quad 0x0000000000000067
def_34_DPARCK_JLIM:
at_5_0040:
    .quad 0x0000000000000000
    .quad 0x0000000000000018
    .quad 0x0000000000000000
    .quad 0x0000000000000018
def_31_unnamed_5:
at_5_0060:
    .quad 0x0000000000000006
def_23_unnamed_2:
at_5_0068:
    .quad 0x0000000000000002
def_29_unnamed_4:
at_5_0070:
    .quad 0x0000000000000003
def_27_unnamed_3:
at_5_0078:
    .quad 0x0000000000000001
def_20_unnamed_1:
at_5_0080:
    .quad 0x0000000000000005
at_5_0088:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_166e - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER do7prd.obj
# Entry points: DO7PRD
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DO7PRD:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    {disp32} jle    at_1_00e8
    mov    rcx,QWORD PTR [rsp+0x78]
    mov    rdx,QWORD PTR [rsp+0x70]
    mov    r10,QWORD PTR [rsp+0x68]
    mov    r8,QWORD PTR [r8]
    lea    r11,[r8*8+0x0]
    lea    rsi,[r8+0x1]
    mov    edi,0x1
    xorpd  xmm0,xmm0
    jmp    at_1_0063
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0050:
    lea    rbx,[rdi+0x1]
    add    rcx,r11
    cmp    rdi,rax
    mov    rdi,rbx
    {disp32} je     at_1_00e8
at_1_0063:
    movsd  xmm1,QWORD PTR [r10+rdi*8-0x8]
    ucomisd xmm0,xmm1
    setnp  bl
    sete   bpl
    test   bpl,bl
    jne    at_1_0050
    test   r8,r8
    jle    at_1_0050
    lea    rbx,[rdi-0x1]
    imul   rbx,r11
    add    rbx,rdx
    mov    r14d,0x1
    mov    r13d,0x2
    mov    r15d,0x8
    mov    r12,r9
    nop
at_1_00a0:
    movsd  xmm2,QWORD PTR [rbx+r14*8-0x8]
    mulsd  xmm2,xmm1
    xor    ebp,ebp
    nop    DWORD PTR [rax]
at_1_00b0:
    movsd  xmm3,QWORD PTR [rcx+rbp*8]
    mulsd  xmm3,xmm2
    addsd  xmm3,QWORD PTR [r12+rbp*8]
    movsd  QWORD PTR [r12+rbp*8],xmm3
    inc    rbp
    cmp    r14,rbp
    jne    at_1_00b0
    inc    r14
    lea    rbp,[r13+0x1]
    add    r12,r15
    add    r15,0x8
    cmp    r13,rsi
    mov    r13,rbp
    jne    at_1_00a0
    {disp32} jmp    at_1_0050
at_1_00e8:
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_00f5:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000c - at_1_0000    # prologue size
    .byte 0x08    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0014:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00f5 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dn2rdp.obj
# Entry points: DN2RDP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DN2RDP:
at_1_0000:
    sub    rsp,0x88
at_1_0007:
    mov    rdx,QWORD PTR [rcx+0xa0]
    test   rdx,rdx
    {disp32} je     at_1_00f0
    cmp    QWORD PTR [rcx+0x68],0x2
    {disp32} jl     at_1_00f0
    cmp    QWORD PTR [rcx+0x210],0x0
    {disp32} jle    at_1_00f0
    xor    eax,eax
    cvtsi2sd xmm0,eax
    mov    r8,QWORD PTR [rsp+0xb8]
    ucomisd xmm0,QWORD PTR [r8+0x48]
    mov    r10,QWORD PTR [rsp+0xb0]
    mov    r8,QWORD PTR [r9]
    setnp  r9b
    sete   r11b
    test   r8,r8
    cmovg  rax,r8
    movabs r8,0x801208384ff00
    mov    QWORD PTR [rcx+0x118],0x1
    shl    rax,0x3
    mov    QWORD PTR [rsp+0x58],0x0
    test   r11b,r9b
    jne    at_1_00b9
    mov    DWORD PTR [rsp+0x34],0x10530
    mov    QWORD PTR [rsp+0x48],rax
    mov    QWORD PTR [rsp+0x50],r10
    lea    rax,[rip + ref_14_DN2RDP_format_pack + (at_2_0068 - def_14_DN2RDP_format_pack)]
    mov    QWORD PTR [rsp+0x28],rax
    lea    rax,[rsp+0x48]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x58]
    lea    r9,[rsp+0x34]
    jmp    at_1_00eb
at_1_00b9:
    mov    DWORD PTR [rsp+0x30],0x10530
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x40],r10
    lea    rax,[rip + ref_14_DN2RDP_format_pack]
    mov    QWORD PTR [rsp+0x28],rax
    lea    rax,[rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x58]
    lea    r9,[rsp+0x30]
at_1_00eb:
    call   ref_15_for_write_seq_fmt
at_1_00f0:
    nop
    add    rsp,0x88
    ret
at_1_00f9:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_14_DN2RDP_format_pack:
at_2_0000:
    .quad 0x0001004700000036
    .long 0x003d001c
    .ascii " REGRESSION DIAGNOSTIC = SQRT( G(I)**T * H(I)**-1 * G(I) )..."
    .quad 0x3800010047000000
    .quad 0x060300001e000100
    .quad 0x390000000c000000
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_0068:
    .quad 0x0001004700000036
    .long 0x0046001c
    .ascii " REGRESSION DIAGNOSTIC = SQRT( G(I)**T * H(I)**-1 * G(I) / ABS(F) )..."
    .quad 0x0038000100470000
    .quad 0x00060300001e0001
    .quad 0x00390000000c0000
    .long 0x00370000
    .short 0x0000
at_2_00d8:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0007 - at_1_0000    # prologue size
    .byte 0x02    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0007 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x11
    .byte 0x00
at_4_0008:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00f9 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dn2lrd.obj
# Entry points: DN2LRD
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_21_DN2LRD:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x98
at_1_0013:
    movapd XMMWORD PTR [rsp+0x80],xmm9
at_1_001d:
    movapd XMMWORD PTR [rsp+0x70],xmm8
at_1_0024:
    movapd XMMWORD PTR [rsp+0x60],xmm7
at_1_002a:
    movapd XMMWORD PTR [rsp+0x50],xmm6
at_1_0030:
    mov    QWORD PTR [rsp+0x48],r9
    mov    rax,QWORD PTR [rdx+0x1c0]
    test   rax,rax
    {disp32} jle    at_1_02ca
    mov    rdi,r8
    mov    r13,rcx
    mov    r14,QWORD PTR [rsp+0x120]
    mov    rcx,QWORD PTR [rsp+0x110]
    mov    rsi,QWORD PTR [rcx]
    shl    rsi,0x3
    mov    QWORD PTR [rsp+0x40],rdx
    mov    rcx,QWORD PTR [rdx+0x138]
    mov    QWORD PTR [rsp+0x38],rcx
    test   al,0x2
    {disp32} je     at_1_01d1
    mov    rax,QWORD PTR [rsp+0x138]
    movsd  xmm0,QWORD PTR [rax+0x48]
    xorpd  xmm1,xmm1
    ucomisd xmm1,xmm0
    setnp  al
    sete   cl
    test   cl,al
    jne    at_1_00b4
    andpd  xmm0,XMMWORD PTR [rip + ref_11_xmm_7fffffffffffffff7fffffffffffffff]
    sqrtsd xmm0,xmm0
    movsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    divsd  xmm6,xmm0
    jmp    at_1_00bc
at_1_00b4:
    movsd  xmm6,QWORD PTR [rip + ref_8_real_3ff0000000000000]
at_1_00bc:
    lea    r8,[rip + ref_22_unnamed_1]
    mov    rbx,QWORD PTR [rsp+0x118]
    mov    rcx,rbx
    mov    rdx,QWORD PTR [rsp+0x130]
    call   ref_23_DV7SCP
    mov    r12,QWORD PTR [rbx]
    test   r12,r12
    {disp32} jle    at_1_01d1
    mov    rax,QWORD PTR [rsp+0x138]
    mov    rcx,QWORD PTR [rsp+0x38]
    lea    rbp,[rax+rcx*8]
    add    rbp,0xfffffffffffffff8
    mov    r15d,0x1
    movsd  xmm7,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    xorpd  xmm8,xmm8
    mov    rbx,r13
    jmp    at_1_0134
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0120:
    lea    rax,[r15+0x1]
    add    rbx,0x8
    cmp    r15,r12
    mov    r15,rax
    {disp32} jge    at_1_01d1
at_1_0134:
    mov    rax,QWORD PTR [rsp+0x128]
    movsd  xmm9,QWORD PTR [rax+r15*8-0x8]
    mulsd  xmm9,xmm9
    mov    rax,QWORD PTR [r14]
    test   rax,rax
    jle    at_1_0175
    mov    rcx,rbx
    xor    edx,edx
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0160:
    movsd  xmm0,QWORD PTR [rcx]
    movsd  QWORD PTR [rbp+rdx*8+0x0],xmm0
    inc    rdx
    add    rcx,rsi
    cmp    rax,rdx
    jne    at_1_0160
at_1_0175:
    mov    rcx,r14
    mov    rdx,rbp
    mov    r8,rdi
    mov    r9,rbp
    call   ref_24_DL7IVM
    mov    rcx,r14
    mov    rdx,rbp
    mov    r8,rbp
    call   ref_25_DD7TPR
    movapd xmm1,xmm7
    subsd  xmm1,xmm0
    ucomisd xmm8,xmm1
    {disp32} jae    at_1_0120
    mulsd  xmm9,xmm0
    divsd  xmm9,xmm1
    xorps  xmm0,xmm0
    sqrtsd xmm0,xmm9
    mulsd  xmm0,xmm6
    mov    rax,QWORD PTR [rsp+0x130]
    movsd  QWORD PTR [rax+r15*8-0x8],xmm0
    {disp32} jmp    at_1_0120
at_1_01d1:
    mov    rcx,QWORD PTR [rsp+0x40]
    mov    rax,QWORD PTR [rcx+0x110]
    sub    rax,QWORD PTR [r14]
    cmp    rax,0x2
    {disp32} jl     at_1_02ca
    mov    rax,QWORD PTR [rsp+0x118]
    mov    rbp,QWORD PTR [rax]
    test   rbp,rbp
    {disp32} jle    at_1_02ca
    mov    rax,QWORD PTR [rcx+0x1b8]
    mov    rcx,rax
    neg    rcx
    cmovs  rcx,rax
    mov    rax,QWORD PTR [rsp+0x138]
    mov    rdx,QWORD PTR [rsp+0x38]
    lea    r15,[rax+rdx*8]
    add    r15,0xfffffffffffffff8
    lea    r12,[rax+rcx*8]
    add    r12,0xfffffffffffffff8
    mov    ebx,0x1
    jmp    at_1_029f
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0240:
    mov    rcx,r14
    mov    rdx,r15
    mov    r8,rdi
    mov    r9,r15
    call   ref_24_DL7IVM
    mov    rcx,r14
    mov    rdx,r15
    mov    r8,rdi
    mov    r9,r15
    call   ref_26_DL7ITV
    mov    QWORD PTR [rsp+0x30],r15
    mov    QWORD PTR [rsp+0x28],r15
    lea    rax,[rip + ref_27_DN2LRD_ONEV]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rip + ref_28_unnamed_2]
    mov    rdx,QWORD PTR [rsp+0x48]
    mov    r8,r14
    mov    r9,r12
    call   ref_29_DO7PRD
    lea    rax,[rbx+0x1]
    add    r13,0x8
    cmp    rbx,rbp
    mov    rbx,rax
    jge    at_1_02ca
at_1_029f:
    mov    rax,QWORD PTR [r14]
    test   rax,rax
    jle    at_1_0240
    mov    rcx,r13
    xor    edx,edx
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_02b0:
    movsd  xmm0,QWORD PTR [rcx]
    movsd  QWORD PTR [r15+rdx*8],xmm0
    inc    rdx
    add    rcx,rsi
    cmp    rax,rdx
    jne    at_1_02b0
    {disp32} jmp    at_1_0240
at_1_02ca:
    movaps xmm6,XMMWORD PTR [rsp+0x50]
    movaps xmm7,XMMWORD PTR [rsp+0x60]
    movaps xmm8,XMMWORD PTR [rsp+0x70]
    movaps xmm9,XMMWORD PTR [rsp+0x80]
    add    rsp,0x98
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_02f7:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_27_DN2LRD_ONEV:
at_2_0000:
    .quad 0x3ff0000000000000
at_2_0008:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_7fffffffffffffff7fffffffffffffff:
at_5_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_5_0010:
end_s5:

# .xdata  (COFF section 6)
.section .s6,"dr"
def_12_xdata:
at_6_0000:
    .byte 0x01    # version 1
    .byte at_1_0030 - at_1_0000    # prologue size
    .byte 0x12    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0030 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x05
    .byte 0x00
    .byte at_1_002a - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x06
    .byte 0x00
    .byte at_1_0024 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x07
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x08
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x13
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_6_0028:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_14_rdata:
def_22_unnamed_1:
at_7_0000:
    .quad 0xbff0000000000000    # binary64 -1.0
def_28_unnamed_2:
at_7_0008:
    .quad 0x0000000000000001
at_7_0010:
end_s7:

# .drectve  (COFF section 8)
.section .s8,"dr"
def_16_drectve:
at_8_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_8_00b9:
end_s8:

# .pdata  (COFF section 9)
.section .s9,"dr"
def_18_pdata:
at_9_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_02f7 - def_0_text)    # image-relative end
    .long ref_12_xdata    # image-relative unwind info
at_9_000c:
end_s9:

# MEMBER dn2g.obj
# Entry points: DN2G
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DN2G:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x98
at_1_0013:
    mov    QWORD PTR [rsp+0x80],r9
    mov    r13,r8
    mov    rbp,rdx
    mov    rsi,rcx
    mov    r8,QWORD PTR [rsp+0x108]
    mov    rdi,QWORD PTR [r8]
    test   rdi,rdi
    je     at_1_003f
    cmp    rdi,0xe
    jne    at_1_0080
    {disp32} jmp    at_1_0181
at_1_003f:
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rip + ref_16_unnamed_1]
    mov    rdx,r8
    mov    r8,QWORD PTR [rsp+0x110]
    mov    r9,QWORD PTR [rsp+0x118]
    call   ref_17_DIVSET
    mov    r8,QWORD PTR [rsp+0x108]
    mov    rdi,QWORD PTR [r8]
    cmp    rdi,0xe
    {disp32} je     at_1_0181
at_1_0080:
    lea    rax,[rdi-0x3]
    cmp    rax,0x8
    {disp32} jbe    at_1_0181
    cmp    rdi,0xd
    je     at_1_00a1
    cmp    rdi,0xc
    jne    at_1_00bb
    mov    QWORD PTR [r8],0xd
at_1_00a1:
    mov    rax,QWORD PTR [rbp+0x0]
    mov    rcx,QWORD PTR [r8+0x18]
    add    rcx,rax
    add    rax,0x2
    imul   rax,QWORD PTR [rsi]
    add    rax,rcx
    mov    QWORD PTR [r8+0x18],rax
at_1_00bb:
    mov    QWORD PTR [rsp+0x68],r13
    mov    rdx,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x60],rdx
    mov    QWORD PTR [rsp+0x58],rdx
    mov    QWORD PTR [rsp+0x50],rdx
    mov    QWORD PTR [rsp+0x48],rbp
    lea    rax,[rsp+0x90]
    mov    QWORD PTR [rsp+0x40],rax
    lea    rax,[rsp+0x88]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],rsi
    mov    QWORD PTR [rsp+0x28],rsi
    mov    rax,QWORD PTR [rsp+0x118]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,r13
    mov    r9,QWORD PTR [rsp+0x110]
    call   ref_18_DRN2G
    mov    r10,QWORD PTR [rsp+0x108]
    cmp    QWORD PTR [r10],0xe
    {disp32} jne    at_1_0359
    mov    rax,QWORD PTR [r10+0x170]
    mov    QWORD PTR [r10+0xd0],rax
    mov    r8,QWORD PTR [rbp+0x0]
    lea    rcx,[r8+rax*1]
    mov    QWORD PTR [r10+0x1e0],rcx
    mov    r9,QWORD PTR [rsi]
    lea    r11,[r9+rcx*1]
    mov    QWORD PTR [r10+0x288],r11
    lea    rdx,[r11+r9*1]
    mov    QWORD PTR [r10+0x228],rdx
    imul   r9,r8
    mov    r8,r10
    add    r9,rdx
    mov    QWORD PTR [r10+0x170],r9
    cmp    rdi,0xd
    jne    at_1_019d
    {disp32} jmp    at_1_0359
at_1_0181:
    mov    rax,QWORD PTR [r8+0xd0]
    mov    rcx,QWORD PTR [r8+0x1e0]
    mov    rdx,QWORD PTR [r8+0x228]
    mov    r11,QWORD PTR [r8+0x288]
at_1_019d:
    mov    r9,r8
    mov    r8,QWORD PTR [rsp+0x120]
    lea    rdi,[r8+rax*8]
    add    rdi,0xfffffffffffffff8
    lea    rbx,[r8+rdx*8-0x8]
    lea    r15,[r8+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x78],r11
    lea    r14,[r8+r11*8]
    add    r14,0xfffffffffffffff8
    mov    r8,r9
    lea    r12,[r9+0x30]
    jmp    at_1_01d8
at_1_01d0:
    mov    QWORD PTR [r8+0x8],0x1
at_1_01d8:
    mov    QWORD PTR [rsp+0x68],r13
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x60],rax
    mov    QWORD PTR [rsp+0x58],r14
    mov    QWORD PTR [rsp+0x50],r15
    mov    QWORD PTR [rsp+0x48],rbp
    lea    rax,[rsp+0x90]
    mov    QWORD PTR [rsp+0x40],rax
    lea    rax,[rsp+0x88]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],rsi
    mov    QWORD PTR [rsp+0x28],rsi
    mov    rax,QWORD PTR [rsp+0x118]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rdi
    mov    rdx,rbx
    mov    r9,QWORD PTR [rsp+0x110]
    call   ref_18_DRN2G
    mov    rcx,QWORD PTR [rsp+0x108]
    cmp    QWORD PTR [rcx],0x2
    jge    at_1_02c0
    mov    rax,QWORD PTR [rcx+0x28]
    mov    QWORD PTR [rsp+0x70],rax
    mov    rax,QWORD PTR [rsp+0x138]
    mov    QWORD PTR [rsp+0x38],rax
    mov    rax,QWORD PTR [rsp+0x130]
    mov    QWORD PTR [rsp+0x30],rax
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r15
    mov    rcx,rsi
    mov    rdx,rbp
    mov    r8,r13
    lea    r9,[rsp+0x70]
    call   QWORD PTR [rsp+0x80]
    mov    r8,QWORD PTR [rsp+0x108]
    cmp    QWORD PTR [rsp+0x70],0x0
    {disp32} jle    at_1_01d0
    cmp    QWORD PTR [r8],0x0
    {disp32} jg     at_1_01d8
    jmp    at_1_02c2
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_02c0:
    jne    at_1_0319
at_1_02c2:
    mov    rax,QWORD PTR [rsp+0x138]
    mov    QWORD PTR [rsp+0x38],rax
    mov    rax,QWORD PTR [rsp+0x130]
    mov    QWORD PTR [rsp+0x30],rax
    mov    rax,QWORD PTR [rsp+0x128]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],rbx
    mov    rcx,rsi
    mov    rdx,rbp
    mov    r8,r13
    mov    r9,r12
    call   QWORD PTR [rsp+0x100]
    mov    r8,QWORD PTR [rsp+0x108]
    cmp    QWORD PTR [r12],0x0
    {disp32} jne    at_1_01d8
    {disp32} jmp    at_1_01d0
at_1_0319:
    cmp    QWORD PTR [rcx+0x210],0x0
    jle    at_1_032f
    mov    rax,QWORD PTR [rsp+0x78]
    mov    QWORD PTR [rcx+0x210],rax
at_1_032f:
    mov    rax,QWORD PTR [rsp+0x120]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r14
    mov    rdx,QWORD PTR [rsp+0x110]
    mov    r8,QWORD PTR [rsp+0x118]
    mov    r9,rsi
    call   ref_19_DN2RDP
at_1_0359:
    nop
    add    rsp,0x98
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_036e:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0013 - at_1_0000    # prologue size
    .byte 0x0a    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x13
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0018:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_16_unnamed_1:
at_5_0000:
    .quad 0x0000000000000001
at_5_0008:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_036e - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dn2f.obj
# Entry points: DN2F
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_24_DN2F:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x168
at_1_0013:
    movapd XMMWORD PTR [rsp+0x150],xmm12
at_1_001d:
    movapd XMMWORD PTR [rsp+0x140],xmm11
at_1_0027:
    movapd XMMWORD PTR [rsp+0x130],xmm10
at_1_0031:
    movapd XMMWORD PTR [rsp+0x120],xmm9
at_1_003b:
    movapd XMMWORD PTR [rsp+0x110],xmm8
at_1_0045:
    movapd XMMWORD PTR [rsp+0x100],xmm7
at_1_004e:
    movapd XMMWORD PTR [rsp+0xf0],xmm6
at_1_0057:
    mov    QWORD PTR [rsp+0x88],r9
    mov    r13,r8
    mov    rbp,rdx
    mov    rsi,rcx
    mov    r14,QWORD PTR [rsp+0x1e8]
    mov    r12,QWORD PTR [rsp+0x1d0]
    mov    rdi,QWORD PTR [r12]
    test   rdi,rdi
    jne    at_1_00a9
    mov    QWORD PTR [rsp+0x20],r14
    lea    rcx,[rip + ref_25_unnamed_1]
    mov    rdx,r12
    mov    r8,QWORD PTR [rsp+0x1d8]
    mov    r9,QWORD PTR [rsp+0x1e0]
    call   ref_26_DIVSET
    mov    rdi,QWORD PTR [r12]
at_1_00a9:
    mov    rax,QWORD PTR [r12+0x70]
    mov    rcx,rax
    neg    rcx
    cmovns rcx,rax
    mov    QWORD PTR [r12+0x70],rcx
    cmp    rdi,0xe
    {disp32} je     at_1_01c5
    lea    rax,[rdi-0x3]
    cmp    rax,0x8
    {disp32} jbe    at_1_01c5
    cmp    rdi,0xd
    je     at_1_00e9
    cmp    rdi,0xc
    jne    at_1_0105
    mov    QWORD PTR [r12],0xd
at_1_00e9:
    mov    rax,QWORD PTR [rbp+0x0]
    mov    rcx,QWORD PTR [r12+0x18]
    add    rcx,rax
    add    rax,0x2
    imul   rax,QWORD PTR [rsi]
    add    rax,rcx
    mov    QWORD PTR [r12+0x18],rax
at_1_0105:
    mov    QWORD PTR [rsp+0x68],r13
    mov    QWORD PTR [rsp+0x60],r14
    mov    QWORD PTR [rsp+0x58],r14
    mov    QWORD PTR [rsp+0x50],r14
    mov    QWORD PTR [rsp+0x48],rbp
    lea    rax,[rsp+0xe8]
    mov    QWORD PTR [rsp+0x40],rax
    lea    rax,[rsp+0xe0]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],rsi
    mov    QWORD PTR [rsp+0x28],rsi
    mov    rax,QWORD PTR [rsp+0x1e0]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,r13
    mov    rdx,r14
    mov    r8,r12
    mov    r9,QWORD PTR [rsp+0x1d8]
    call   ref_27_DRN2G
    cmp    QWORD PTR [r12],0xe
    {disp32} jne    at_1_05c9
    mov    rdx,QWORD PTR [r12+0x170]
    mov    QWORD PTR [r12+0xd0],rdx
    mov    rcx,QWORD PTR [rbp+0x0]
    lea    rax,[rcx+rdx*1]
    mov    QWORD PTR [r12+0x1e0],rax
    mov    r9,QWORD PTR [rsi]
    lea    r8,[r9+rax*1]
    mov    QWORD PTR [r12+0x288],r8
    lea    r10,[r8+r9*1]
    mov    QWORD PTR [r12+0x228],r10
    imul   rcx,r9
    add    rcx,r10
    mov    QWORD PTR [r12+0x170],rcx
    cmp    rdi,0xd
    jne    at_1_01e8
    {disp32} jmp    at_1_05c9
at_1_01c5:
    mov    r9,QWORD PTR [rsi]
    mov    rdx,QWORD PTR [r12+0xd0]
    mov    rax,QWORD PTR [r12+0x1e0]
    mov    r10,QWORD PTR [r12+0x228]
    mov    r8,QWORD PTR [r12+0x288]
at_1_01e8:
    lea    rcx,[rax-0x1]
    mov    QWORD PTR [rsp+0xa0],rcx
    mov    QWORD PTR [rsp+0xb0],r9
    lea    rcx,[rax+r9*1]
    dec    rcx
    mov    QWORD PTR [rsp+0x98],rcx
    mov    QWORD PTR [rsp+0xb8],rdx
    lea    rcx,[r14+rdx*8-0x8]
    mov    QWORD PTR [rsp+0x80],rcx
    mov    QWORD PTR [rsp+0xa8],r10
    lea    rcx,[r14+r10*8-0x8]
    mov    QWORD PTR [rsp+0xd0],rcx
    lea    rax,[r14+rax*8-0x8]
    mov    QWORD PTR [rsp+0xc8],rax
    mov    QWORD PTR [rsp+0x90],r8
    lea    rax,[r14+r8*8-0x8]
    mov    QWORD PTR [rsp+0x78],rax
    xorpd  xmm6,xmm6
    movapd xmm7,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm8,QWORD PTR [rip + ref_11_real_bfe0000000000000]
    movsd  xmm9,QWORD PTR [rip + ref_14_real_3fb999999999999a]
    jmp    at_1_029a
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0280:
    mov    r12,r14
    mov    QWORD PTR [r14+0x8],0x1
    mov    QWORD PTR [r14+0xe8],rdi
    mov    r14,QWORD PTR [rsp+0x1e8]
at_1_029a:
    mov    QWORD PTR [rsp+0x68],r13
    mov    QWORD PTR [rsp+0x60],r14
    mov    rax,QWORD PTR [rsp+0x78]
    mov    QWORD PTR [rsp+0x58],rax
    mov    rdi,QWORD PTR [rsp+0xc8]
    mov    QWORD PTR [rsp+0x50],rdi
    mov    QWORD PTR [rsp+0x48],rbp
    lea    rax,[rsp+0xe8]
    mov    QWORD PTR [rsp+0x40],rax
    lea    rax,[rsp+0xe0]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],rsi
    mov    QWORD PTR [rsp+0x28],rsi
    mov    rax,QWORD PTR [rsp+0x1e0]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,QWORD PTR [rsp+0x80]
    mov    rdx,QWORD PTR [rsp+0xd0]
    mov    r8,r12
    mov    r9,QWORD PTR [rsp+0x1d8]
    call   ref_27_DRN2G
    cmp    QWORD PTR [r12],0x2
    jge    at_1_0380
    mov    rax,QWORD PTR [r12+0x28]
    mov    QWORD PTR [rsp+0x70],rax
    mov    rax,QWORD PTR [rsp+0x200]
    mov    QWORD PTR [rsp+0x38],rax
    mov    rax,QWORD PTR [rsp+0x1f8]
    mov    QWORD PTR [rsp+0x30],rax
    mov    rax,QWORD PTR [rsp+0x1f0]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],rdi
    mov    rcx,rsi
    mov    rdx,rbp
    mov    r8,r13
    lea    r9,[rsp+0x70]
    call   QWORD PTR [rsp+0x88]
    cmp    QWORD PTR [rsp+0x70],0x0
    {disp32} jle    at_1_0576
    mov    rax,QWORD PTR [r12]
    test   rax,rax
    {disp32} jg     at_1_029a
    jmp    at_1_038b
    xchg   ax,ax
at_1_0380:
    mov    eax,0x2
    {disp32} jne    at_1_0584
at_1_038b:
    ucomisd xmm6,QWORD PTR [r14+0x128]
    setnp  cl
    sete   dl
    cmp    QWORD PTR [r12+0x110],0x0
    jns    at_1_03c4
    and    dl,cl
    je     at_1_03c4
    mov    rcx,rbp
    mov    rdx,QWORD PTR [rsp+0x80]
    lea    r8,[rip + ref_28_DN2F_ONE]
    call   ref_29_DV7SCP
    mov    rax,QWORD PTR [r12]
at_1_03c4:
    mov    rdi,QWORD PTR [r12+0xe8]
    cmp    rax,0xffffffffffffffff
    jne    at_1_03da
    dec    QWORD PTR [r12+0x1a0]
at_1_03da:
    mov    rax,QWORD PTR [rbp+0x0]
    mov    QWORD PTR [rsp+0xc0],rax
    test   rax,rax
    {disp32} jle    at_1_029a
    dec    rdi
    mov    r15d,0x1
    mov    rcx,QWORD PTR [rsp+0xb8]
    mov    rbx,QWORD PTR [rsp+0xa8]
at_1_0408:
    mov    rax,r14
    mov    r14,r12
    movsd  xmm11,QWORD PTR [r13+r15*8-0x8]
    movapd xmm12,xmm11
    movsd  xmm0,QWORD PTR [rip + ref_28_DN2F_ONE]
    divsd  xmm0,QWORD PTR [rax+rcx*8-0x8]
    andpd  xmm12,xmm7
    maxsd  xmm12,xmm0
    mulsd  xmm12,QWORD PTR [rax+0x150]
    inc    rcx
    mov    QWORD PTR [rsp+0xd8],rcx
    lea    r12,[rax+rbx*8]
    add    r12,0xfffffffffffffff8
    movapd xmm10,xmm12
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0460:
    movapd xmm0,xmm11
    addsd  xmm0,xmm10
    movsd  QWORD PTR [r13+r15*8-0x8],xmm0
    mov    rax,QWORD PTR [r14+0x30]
    mov    QWORD PTR [rsp+0x70],rax
    mov    rax,QWORD PTR [rsp+0x200]
    mov    QWORD PTR [rsp+0x38],rax
    mov    rax,QWORD PTR [rsp+0x1f8]
    mov    QWORD PTR [rsp+0x30],rax
    mov    rax,QWORD PTR [rsp+0x1f0]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],r12
    mov    rcx,rsi
    mov    rdx,rbp
    mov    r8,r13
    lea    r9,[rsp+0x70]
    call   QWORD PTR [rsp+0x88]
    cmp    QWORD PTR [rsp+0x70],0x0
    jg     at_1_04f0
    mulsd  xmm10,xmm8
    movapd xmm0,xmm10
    divsd  xmm0,xmm12
    andpd  xmm0,xmm7
    inc    rdi
    ucomisd xmm0,xmm9
    jae    at_1_0460
    {disp32} jmp    at_1_0280
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_04f0:
    inc    rdi
    movsd  QWORD PTR [r13+r15*8-0x8],xmm11
    mov    r12,r14
    mov    QWORD PTR [r14+0xe8],rdi
    mov    rax,QWORD PTR [rsp+0xa0]
    cmp    QWORD PTR [rsp+0xb0],0x0
    mov    r14,QWORD PTR [rsp+0x1e8]
    mov    rcx,QWORD PTR [rsp+0x98]
    jle    at_1_0554
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0530:
    movsd  xmm0,QWORD PTR [r14+rbx*8-0x8]
    subsd  xmm0,QWORD PTR [r14+rax*8]
    divsd  xmm0,xmm10
    movsd  QWORD PTR [r14+rbx*8-0x8],xmm0
    inc    rbx
    inc    rax
    cmp    rax,rcx
    jl     at_1_0530
at_1_0554:
    lea    rax,[r15+0x1]
    cmp    r15,QWORD PTR [rsp+0xc0]
    mov    r15,rax
    mov    rcx,QWORD PTR [rsp+0xd8]
    {disp32} jl     at_1_0408
    {disp32} jmp    at_1_029a
at_1_0576:
    mov    QWORD PTR [r12+0x8],0x1
    {disp32} jmp    at_1_029a
at_1_0584:
    cmp    QWORD PTR [r12+0x210],0x0
    jle    at_1_059f
    mov    rax,QWORD PTR [rsp+0x90]
    mov    QWORD PTR [r12+0x210],rax
at_1_059f:
    mov    QWORD PTR [rsp+0x28],r14
    mov    rax,QWORD PTR [rsp+0x78]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,r12
    mov    rdx,QWORD PTR [rsp+0x1d8]
    mov    r8,QWORD PTR [rsp+0x1e0]
    mov    r9,rsi
    call   ref_30_DN2RDP
at_1_05c9:
    movaps xmm6,XMMWORD PTR [rsp+0xf0]
    movaps xmm7,XMMWORD PTR [rsp+0x100]
    movaps xmm8,XMMWORD PTR [rsp+0x110]
    movaps xmm9,XMMWORD PTR [rsp+0x120]
    movaps xmm10,XMMWORD PTR [rsp+0x130]
    movaps xmm11,XMMWORD PTR [rsp+0x140]
    movaps xmm12,XMMWORD PTR [rsp+0x150]
    add    rsp,0x168
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_061a:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_28_DN2F_ONE:
at_2_0000:
    .quad 0x3ff0000000000000
at_2_0008:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_bfe0000000000000:
at_5_0000:
    .quad 0xbfe0000000000000    # binary64 -0.5
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fb999999999999a:
at_6_0000:
    .quad 0x3fb999999999999a    # binary64 0.1
at_6_0008:
end_s6:

# .xdata  (COFF section 7)
.section .s7,"dr"
def_15_xdata:
at_7_0000:
    .byte 0x01    # version 1
    .byte at_1_0057 - at_1_0000    # prologue size
    .byte 0x18    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0057 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0f
    .byte 0x00
    .byte at_1_004e - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x10
    .byte 0x00
    .byte at_1_0045 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x11
    .byte 0x00
    .byte at_1_003b - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x12
    .byte 0x00
    .byte at_1_0031 - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x13
    .byte 0x00
    .byte at_1_0027 - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x14
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x15
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x2d
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_7_0034:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_17_rdata:
def_25_unnamed_1:
at_8_0000:
    .quad 0x0000000000000001
at_8_0008:
end_s8:

# .drectve  (COFF section 9)
.section .s9,"dr"
def_19_drectve:
at_9_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_9_00b9:
end_s9:

# .pdata  (COFF section 10)
.section .s10,"dr"
def_21_pdata:
at_10_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_061a - def_0_text)    # image-relative end
    .long ref_15_xdata    # image-relative unwind info
at_10_000c:
end_s10:

# MEMBER dn2cvp.obj
# Entry points: DN2CVP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DN2CVP:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x528
at_1_0013:
    cmp    QWORD PTR [rcx],0x8
    {disp32} jg     at_1_074a
    mov    rsi,rcx
    mov    rax,QWORD PTR [rcx+0xa0]
    mov    QWORD PTR [rsp+0x30],rax
    test   rax,rax
    {disp32} je     at_1_074a
    mov    r15,rdx
    cmp    QWORD PTR [rsi+0xb0],0x0
    {disp32} je     at_1_01ac
    mov    rax,QWORD PTR [rsi+0x198]
    test   rax,rax
    {disp32} jle    at_1_00f9
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x72],0x10b0638
    mov    WORD PTR [rsp+0x76],0x1
    mov    QWORD PTR [rsp+0x1c0],0x320
    lea    rbx,[rsp+0x208]
    mov    QWORD PTR [rsp+0x1c8],rbx
    mov    QWORD PTR [rsp+0x1d0],0x50
    mov    QWORD PTR [rsp+0x1d8],rax
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_02f0 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x72]
    lea    rax,[rsp+0x1c0]
    movabs rdx,0x801208384ff00
    mov    r14,r9
    mov    r9,rax
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_18_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,rsi
    call   ref_19_WRITELINES
    mov    r9,r14
at_1_00f9:
    mov    rax,QWORD PTR [rsi+0x1a0]
    test   rax,rax
    {disp32} jle    at_1_01ac
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x6c],0x10b0638
    mov    WORD PTR [rsp+0x70],0x1
    mov    QWORD PTR [rsp+0x1a0],0x320
    lea    rbx,[rsp+0x208]
    mov    QWORD PTR [rsp+0x1a8],rbx
    mov    QWORD PTR [rsp+0x1b0],0x50
    mov    QWORD PTR [rsp+0x1b8],rax
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_0298 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x6c]
    lea    rax,[rsp+0x1a0]
    movabs rdx,0x801208384ff00
    mov    r14,r9
    mov    r9,rax
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_18_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rbx
    mov    r9,rsi
    call   ref_19_WRITELINES
    mov    r9,r14
at_1_01ac:
    cmp    QWORD PTR [rsi+0x68],0x0
    {disp32} jle    at_1_074a
    mov    r12,QWORD PTR [rsi+0xc8]
    cmp    QWORD PTR [rsi+0x210],0x0
    jg     at_1_01d1
    test   r12,r12
    {disp32} jle    at_1_030a
at_1_01d1:
    mov    r14,r9
    mov    QWORD PTR [rsi+0x118],0x1
    mov    rax,QWORD PTR [rsp+0x590]
    movsd  xmm0,QWORD PTR [rax+0x1a0]
    mulsd  xmm0,xmm0
    mov    rax,QWORD PTR [rsi+0x70]
    mov    rcx,rax
    neg    rcx
    cmovs  rcx,rax
    mov    QWORD PTR [rsp+0x78],0x0
    cmp    rcx,0x3
    jb     at_1_0270
    mov    DWORD PTR [rsp+0x60],0x1300638
    mov    WORD PTR [rsp+0x64],0x1
    mov    QWORD PTR [rsp+0x160],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0x168],rax
    mov    QWORD PTR [rsp+0x170],0x50
    movsd  QWORD PTR [rsp+0x178],xmm0
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_0204 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x60]
    lea    r9,[rsp+0x160]
    jmp    at_1_02ce
at_1_0270:
    mov    DWORD PTR [rsp+0x66],0x1300638
    mov    WORD PTR [rsp+0x6a],0x1
    mov    QWORD PTR [rsp+0x180],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0x188],rax
    mov    QWORD PTR [rsp+0x190],0x50
    movsd  QWORD PTR [rsp+0x198],xmm0
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_024c - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x66]
    lea    r9,[rsp+0x180]
at_1_02ce:
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_18_unnamed_1]
    lea    rdx,[rsp+0x208]
    lea    r8,[rsp+0x30]
    mov    r9,rsi
    call   ref_19_WRITELINES
    mov    r9,r14
at_1_030a:
    test   BYTE PTR [rsi+0x68],0x1
    {disp32} je     at_1_074a
    mov    QWORD PTR [rsi+0x118],0x1
    test   r12,r12
    {disp32} js     at_1_03af
    {disp32} je     at_1_041f
    mov    r14,QWORD PTR [r9]
    cmp    r14,0x32
    {disp32} jg     at_1_074a
    mov    rcx,QWORD PTR [rsi+0x70]
    mov    rax,rcx
    neg    rax
    cmovs  rax,rcx
    cmp    rax,0x1
    {disp32} ja     at_1_050d
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x50],0x10638
    mov    QWORD PTR [rsp+0xe0],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0xe8],rax
    mov    QWORD PTR [rsp+0xf0],0x50
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_00e0 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x50]
    lea    r9,[rsp+0xe0]
    {disp32} jmp    at_1_05ba
at_1_03af:
    cmp    r12,0xfffffffffffffffe
    {disp32} je     at_1_0478
    cmp    r12,0xffffffffffffffff
    {disp32} jne    at_1_074a
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x5c],0x10638
    mov    QWORD PTR [rsp+0x128],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0x130],rax
    mov    QWORD PTR [rsp+0x138],0x50
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_01c8 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x5c]
    lea    r9,[rsp+0x128]
    {disp32} jmp    at_1_04cf
at_1_041f:
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x54],0x10638
    mov    QWORD PTR [rsp+0xf8],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0x100],rax
    mov    QWORD PTR [rsp+0x108],0x50
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_0144 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x54]
    lea    r9,[rsp+0xf8]
    jmp    at_1_04cf
at_1_0478:
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x58],0x10638
    mov    QWORD PTR [rsp+0x110],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0x118],rax
    mov    QWORD PTR [rsp+0x120],0x50
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_0184 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x58]
    lea    r9,[rsp+0x110]
at_1_04cf:
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_18_unnamed_1]
    lea    rdx,[rsp+0x208]
    lea    r8,[rsp+0x30]
    mov    r9,rsi
    call   ref_19_WRITELINES
    {disp32} jmp    at_1_074a
at_1_050d:
    mov    QWORD PTR [rsp+0x78],0x0
    cmp    rax,0x2
    jne    at_1_056c
    mov    DWORD PTR [rsp+0x4c],0x10638
    mov    QWORD PTR [rsp+0xc8],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0xd0],rax
    mov    QWORD PTR [rsp+0xd8],0x50
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_0094 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x4c]
    lea    r9,[rsp+0xc8]
    jmp    at_1_05ba
at_1_056c:
    mov    DWORD PTR [rsp+0x48],0x10638
    mov    QWORD PTR [rsp+0xb0],0x320
    lea    rax,[rsp+0x208]
    mov    QWORD PTR [rsp+0xb8],rax
    mov    QWORD PTR [rsp+0xc0],0x50
    lea    rax,[rip + ref_16_DN2CVP_format_pack + (at_2_0060 - def_16_DN2CVP_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x78]
    lea    r8,[rsp+0x48]
    lea    r9,[rsp+0xb0]
at_1_05ba:
    movabs rdx,0x801208384ff00
    call   ref_17_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_20_unnamed_2]
    lea    rdx,[rsp+0x208]
    lea    r8,[rsp+0x30]
    mov    r9,rsi
    call   ref_19_WRITELINES
    test   r14,r14
    {disp32} jle    at_1_074a
    dec    r12
    xor    ebp,ebp
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0610:
    lea    r13,[rbp+0x1]
    lea    rbx,[r12+rbp*1]
    inc    rbx
    mov    QWORD PTR [rsp+0x78],0x0
    mov    DWORD PTR [rsp+0x42],0x10b0638
    mov    WORD PTR [rsp+0x46],0x2
    mov    QWORD PTR [rsp+0x140],0x320
    lea    rdi,[rsp+0x208]
    mov    QWORD PTR [rsp+0x148],rdi
    mov    QWORD PTR [rsp+0x150],0x50
    mov    QWORD PTR [rsp+0x158],r13
    lea    rax,[rip + ref_16_DN2CVP_format_pack]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rdi,[rsp+0x78]
    mov    rcx,rdi
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x42]
    lea    r9,[rsp+0x140]
    call   ref_17_for_write_int_fmt
    mov    rax,QWORD PTR [rsp+0x590]
    lea    rax,[rax+r12*8]
    mov    DWORD PTR [rsp+0x3e],0x10730
    mov    QWORD PTR [rsp+0x1e0],0x1
    mov    QWORD PTR [rsp+0x1e8],rax
    mov    QWORD PTR [rsp+0x1f0],0x1
    mov    QWORD PTR [rsp+0x1f8],r13
    mov    QWORD PTR [rsp+0x200],0x8
    mov    rcx,rdi
    lea    rdx,[rsp+0x3e]
    lea    r8,[rsp+0x1e0]
    call   ref_21_for_write_int_fmt_xmit
    add    rbp,0x4
    mov    rax,rbp
    movabs rcx,0xcccccccccccccccd
    mul    rcx
    shr    rdx,0x2
    mov    QWORD PTR [rsp+0xa8],rdx
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rsp+0xa8]
    lea    rdx,[rsp+0x208]
    lea    r8,[rsp+0x30]
    mov    r9,rsi
    call   ref_19_WRITELINES
    mov    rbp,r13
    mov    r12,rbx
    cmp    r13,r14
    {disp32} jl     at_1_0610
at_1_074a:
    add    rsp,0x528
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_075e:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_16_DN2CVP_format_pack:
at_2_0000:
    .quad 0x0004001c00000036
    .ascii " ROW$"
    .quad 0x0300000001000000
    .quad 0x010000000e000000
    .quad 0x1e00000002000000
    .quad 0x0c00000005030000
    .quad 0x4700000046000000
    .quad 0x0e00010038000100
    .quad 0x0900000001000000
    .quad 0x050300001e000000
    .quad 0x460000000c000000
    .quad 0x3700000039000000
    .short 0x0000
    .byte 0x00
at_2_0060:
    .quad 0x0001004700000036
    .long 0x001e001c
    .ascii " COVARIANCE = SCALE * J**T * J"
    .quad 0x0037000100470000
    .short 0x0000
at_2_0094:
    .quad 0x0001004700000036
    .long 0x0038001c
    .ascii " COVARIANCE = H**-1, WHERE H = FINITE-DIFFERENCE HESSIANG"
    .long 0x37000100
    .short 0x0000
    .byte 0x00
at_2_00e0:
    .quad 0x0001004700000036
    .long 0x0030001c
    .ascii " COVARIANCE = SCALE * H**-1 * (J**T * J) * H**-1G"
    .long 0x1c000100
    .short 0x1700
    .byte 0x00
    .ascii " WHERE H = F.D. HESSIAN"
    .quad 0x0000370001004700
    .byte 0x00
at_2_0144:
    .quad 0x0001004700000036
    .long 0x002d001c
    .ascii " ++++++ COVARIANCE MATRIX NOT COMPUTED ++++++"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_0184:
    .quad 0x0001004700000036
    .long 0x0034001c
    .ascii " ++++++ OVERSIZE STEPS IN COMPUTING COVARIANCE +++++7"
    .zero 3
at_2_01c8:
    .quad 0x0001004700000036
    .long 0x002b001c
    .ascii " ++++++ INDEFINITE COVARIANCE MATRIX ++++++"
    .long 0x00003700
    .byte 0x00
at_2_0204:
    .quad 0x0001004700000036
    .long 0x002c001c
    .ascii " RECIPROCAL CONDITION OF (J**T)*J = AT LEAST"
    .quad 0x000000010200001e
    .quad 0x000000370000000a
at_2_024c:
    .quad 0x0001004700000036
    .long 0x002f001c
    .ascii " RECIPROCAL CONDITION OF F.D. HESSIAN = AT MOST"
    .quad 0x0000010200001e00
    .quad 0x0000370000000a00
    .byte 0x00
at_2_0298:
    .quad 0x0000000e00000036
    .quad 0x0000000100000001
    .quad 0x0000000100000024
    .quad 0x0032001c00000004
    .ascii " EXTRA GRAD. EVALS FOR COVARIANCE AND DIAGNOSTICS."
    .long 0x00370000
    .short 0x0000
at_2_02f0:
    .quad 0x0001004700000036
    .quad 0x000000010000000e
    .quad 0x0000002400000001
    .quad 0x0000000400000001
    .long 0x0032001c
    .ascii " EXTRA FUNC. EVALS FOR COVARIANCE AND DIAGNOSTICS."
    .long 0x00370000
    .short 0x0000
at_2_034c:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0013 - at_1_0000    # prologue size
    .byte 0x0a    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0xa5
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0018:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_18_unnamed_1:
at_5_0000:
    .quad 0x0000000000000002
def_20_unnamed_2:
at_5_0008:
    .quad 0x0000000000000003
at_5_0010:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_075e - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dl7vml.obj
# Entry points: DL7VML
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7VML:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    {disp32} jle    at_1_008a
    lea    rcx,[rax+0x1]
    mov    r10,rcx
    imul   r10,rax
    and    r10,0xfffffffffffffffe
    shl    r10,0x2
    lea    r11,[rax*8+0x0]
    sub    r10,r11
    add    r8,r10
    mov    r10d,0x8
    sub    r10,r11
    mov    r11d,0x1
    jmp    at_1_0059
at_1_0040:
    movsd  QWORD PTR [rdx+rsi*8-0x8],xmm0
    lea    rsi,[r11+0x1]
    add    r8,r10
    add    r10,0x8
    cmp    r11,rax
    mov    r11,rsi
    je     at_1_008a
at_1_0059:
    mov    rsi,rcx
    xorpd  xmm0,xmm0
    sub    rsi,r11
    jle    at_1_0040
    xor    edi,edi
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0070:
    movsd  xmm1,QWORD PTR [r8+rdi*8]
    mulsd  xmm1,QWORD PTR [r9+rdi*8]
    addsd  xmm0,xmm1
    inc    rdi
    cmp    rdi,rsi
    jl     at_1_0070
    jmp    at_1_0040
at_1_008a:
    pop    rdi
    pop    rsi
    ret
at_1_008d:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0002 - at_1_0000    # prologue size
    .byte 0x02    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
at_4_0008:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_008d - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dl7tvm.obj
# Entry points: DL7TVM
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7TVM:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    push   rbx
at_1_0003:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    {disp32} jle    at_1_0115
    dec    rax
    mov    ecx,0x8
    mov    r10d,0x1
    xor    r11d,r11d
    jmp    at_1_0046
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0030:
    add    r8,rcx
    add    rcx,0x8
    inc    r10
    cmp    r11,rax
    mov    r11,rsi
    {disp32} je     at_1_0115
at_1_0046:
    movsd  xmm0,QWORD PTR [r9+r11*8]
    mov    QWORD PTR [rdx+r11*8],0x0
    lea    rsi,[r11+0x1]
    cmp    rsi,0x4
    jb     at_1_00d2
    mov    rdi,r10
    shr    rdi,0x2
    mov    ebx,0x18
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0070:
    movsd  xmm1,QWORD PTR [r8+rbx*1-0x18]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rdx+rbx*1-0x18]
    movsd  QWORD PTR [rdx+rbx*1-0x18],xmm1
    movsd  xmm1,QWORD PTR [r8+rbx*1-0x10]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rdx+rbx*1-0x10]
    movsd  QWORD PTR [rdx+rbx*1-0x10],xmm1
    movsd  xmm1,QWORD PTR [r8+rbx*1-0x8]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rdx+rbx*1-0x8]
    movsd  QWORD PTR [rdx+rbx*1-0x8],xmm1
    movsd  xmm1,QWORD PTR [r8+rbx*1]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rdx+rbx*1]
    movsd  QWORD PTR [rdx+rbx*1],xmm1
    add    rbx,0x20
    dec    rdi
    jne    at_1_0070
at_1_00d2:
    mov    rdi,rsi
    and    rdi,0xfffffffffffffffc
    cmp    rdi,rsi
    {disp32} je     at_1_0030
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_00f0:
    movsd  xmm1,QWORD PTR [r8+rdi*8]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [rdx+rdi*8]
    movsd  QWORD PTR [rdx+rdi*8],xmm1
    lea    rbx,[rdi+0x1]
    mov    rdi,rbx
    cmp    r10,rbx
    jne    at_1_00f0
    {disp32} jmp    at_1_0030
at_1_0115:
    pop    rbx
    pop    rdi
    pop    rsi
    ret
at_1_0119:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0003 - at_1_0000    # prologue size
    .byte 0x03    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte 0x00
    .byte 0x00
at_4_000c:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0119 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dl7tsq.obj
# Entry points: DL7TSQ
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7TSQ:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    {disp32} jle    at_1_00ec
    lea    rcx,[rdx-0x8]
    mov    r9d,0x1
    mov    r11d,0x8
    xor    esi,esi
    mov    r10,r8
    nop    DWORD PTR [rax]
at_1_0030:
    lea    rdi,[rsi+r9*1]
    cmp    r9,0x1
    jne    at_1_0090
at_1_003a:
    movsd  xmm0,QWORD PTR [r8+rdi*8-0x8]
    xor    ebx,ebx
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0050:
    movsd  xmm1,QWORD PTR [r10+rbx*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rdx+rbx*8],xmm1
    lea    r14,[rsi+rbx*1]
    inc    r14
    inc    rbx
    cmp    r14,rdi
    jb     at_1_0050
    lea    rbx,[r9+0x1]
    add    r10,r11
    add    rdx,r11
    add    r11,0x8
    mov    rsi,rdi
    cmp    r9,rax
    mov    r9,rbx
    jne    at_1_0030
    jmp    at_1_00ec
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0090:
    lea    r14,[rsi+0x1]
    lea    rbx,[rdi-0x1]
    mov    r15d,0x1
    jmp    at_1_00ac
at_1_00a0:
    lea    r12,[r14+0x1]
    cmp    r14,rbx
    mov    r14,r12
    jge    at_1_003a
at_1_00ac:
    cmp    r14,rsi
    jbe    at_1_00a0
    movsd  xmm0,QWORD PTR [r8+r14*8-0x8]
    lea    r13,[rcx+r15*8]
    xor    r12d,r12d
    nop
at_1_00c0:
    movsd  xmm1,QWORD PTR [r10+r12*8]
    mulsd  xmm1,xmm0
    addsd  xmm1,QWORD PTR [r13+r12*8+0x0]
    movsd  QWORD PTR [r13+r12*8+0x0],xmm1
    lea    rbp,[rsi+r12*1]
    inc    rbp
    inc    r12
    cmp    rbp,r14
    jb     at_1_00c0
    add    r15,r12
    jmp    at_1_00a0
at_1_00ec:
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_00f9:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000c - at_1_0000    # prologue size
    .byte 0x08    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0014:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00f9 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dl7svx.obj
# Entry points: DL7SVX
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_28_DL7SVX:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0xb8
at_1_0013:
    movapd XMMWORD PTR [rsp+0xa0],xmm10
at_1_001d:
    movapd XMMWORD PTR [rsp+0x90],xmm9
at_1_0027:
    movapd XMMWORD PTR [rsp+0x80],xmm8
at_1_0031:
    movapd XMMWORD PTR [rsp+0x70],xmm7
at_1_0037:
    movapd XMMWORD PTR [rsp+0x60],xmm6
at_1_003d:
    mov    QWORD PTR [rsp+0x50],r9
    mov    rsi,r8
    mov    QWORD PTR [rsp+0x48],rcx
    mov    r13,QWORD PTR [rcx]
    lea    rbp,[r13-0x1]
    mov    rax,rbp
    imul   rax,r13
    shr    rax,1
    mov    ecx,0x1ad0
    cvtsi2ss xmm0,ecx
    cvtss2sd xmm0,xmm0
    divsd  xmm0,QWORD PTR [rip + ref_8_real_40c37a8000000000]
    addsd  xmm0,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    lea    rcx,[rax+r13*1]
    mulsd  xmm0,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    movsd  QWORD PTR [rsp+0x40],xmm0
    mov    QWORD PTR [rsp+0x28],rdx
    movsd  xmm1,QWORD PTR [rdx+rcx*8-0x8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [r8+r13*8-0x8],xmm1
    cmp    r13,0x2
    {disp32} jge    at_1_0225
at_1_00aa:
    mov    rdi,QWORD PTR [rsp+0x48]
    mov    rcx,rdi
    mov    rdx,rsi
    call   ref_29_DV2NRM
    xorpd  xmm1,xmm1
    ucomisd xmm1,xmm0
    {disp32} jae    at_1_01e8
    movsd  xmm6,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    movapd xmm1,xmm6
    divsd  xmm1,xmm0
    mov    rdi,QWORD PTR [rdi]
    test   rdi,rdi
    mov    rbp,QWORD PTR [rsp+0x50]
    mov    r12,QWORD PTR [rsp+0x28]
    jle    at_1_0156
    xor    eax,eax
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_00f0:
    movsd  xmm0,QWORD PTR [rsi+rax*8]
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [rsi+rax*8],xmm0
    inc    rax
    cmp    rax,rdi
    jl     at_1_00f0
    xor    ebx,ebx
    lea    r15,[rsp+0x38]
    mov    r12,QWORD PTR [rsp+0x28]
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0120:
    mov    QWORD PTR [rsp+0x38],r13
    lea    r14,[r13-0x1]
    imul   r13,r14
    and    r13,0xfffffffffffffffe
    lea    rdx,[r12+r13*4]
    mov    rcx,r15
    mov    r8,rsi
    call   ref_30_DD7TPR
    mov    rax,QWORD PTR [rsp+0x38]
    movsd  QWORD PTR [rbp+rax*8-0x8],xmm0
    inc    rbx
    mov    r13,r14
    cmp    rbx,rdi
    jl     at_1_0120
at_1_0156:
    mov    r14,QWORD PTR [rsp+0x48]
    mov    rcx,r14
    mov    rdx,rbp
    call   ref_29_DV2NRM
    divsd  xmm6,xmm0
    mov    rdi,QWORD PTR [r14]
    mov    QWORD PTR [rsp+0x30],0x1
    test   rdi,rdi
    jle    at_1_01d9
    mov    ebx,0x1
    xor    eax,eax
    lea    r15,[rsp+0x30]
    lea    r13,[rsp+0x58]
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_0190:
    movsd  xmm0,QWORD PTR [rbp+rax*8+0x0]
    mulsd  xmm0,xmm6
    movsd  QWORD PTR [rsp+0x58],xmm0
    mov    QWORD PTR [rsi+rax*8],0x0
    lea    r9,[r12+rbx*8]
    add    r9,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x20],rsi
    mov    rcx,r15
    mov    rdx,rsi
    mov    r8,r13
    call   ref_31_DV2AXY
    mov    rax,QWORD PTR [rsp+0x30]
    add    rbx,rax
    lea    rcx,[rax+0x1]
    mov    QWORD PTR [rsp+0x30],rcx
    cmp    rax,rdi
    jl     at_1_0190
at_1_01d9:
    mov    rcx,r14
    mov    rdx,rsi
    call   ref_29_DV2NRM
    movapd xmm1,xmm0
at_1_01e8:
    movapd xmm0,xmm1
    movaps xmm6,XMMWORD PTR [rsp+0x60]
    movaps xmm7,XMMWORD PTR [rsp+0x70]
    movaps xmm8,XMMWORD PTR [rsp+0x80]
    movaps xmm9,XMMWORD PTR [rsp+0x90]
    movaps xmm10,XMMWORD PTR [rsp+0xa0]
    add    rsp,0xb8
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0225:
    mov    QWORD PTR [rsp+0x30],0x1
    mov    rcx,QWORD PTR [rsp+0x28]
    lea    rax,[rcx+rax*8]
    xor    ecx,ecx
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0240:
    movsd  xmm1,QWORD PTR [rax+rcx*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rsi+rcx*8],xmm1
    inc    rcx
    cmp    rbp,rcx
    jne    at_1_0240
    lea    rbx,[r13-0x2]
    imul   rbx,rbp
    mov    r15d,0x4
    sub    r15,r13
    sub    r15,r13
    mov    r12d,0x1ad0
    mov    rdi,0xffffffffffffffff
    movsd  xmm6,QWORD PTR [rip + ref_8_real_40c37a8000000000]
    movsd  xmm7,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    movsd  xmm8,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    movapd xmm9,XMMWORD PTR [rip + ref_20_xmm_80000000000000008000000000000000]
    movapd xmm10,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    mov    r14d,0x1
    jmp    at_1_02f9
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_02b0:
    lea    rcx,[rax-0x1]
    imul   rcx,rax
    shr    rcx,1
    mov    QWORD PTR [rsi+rax*8-0x8],0x0
    lea    r9,[r9+rcx*8]
    mov    QWORD PTR [rsp+0x20],rsi
    lea    rcx,[rsp+0x38]
    mov    rdx,rsi
    lea    r8,[rsp+0x40]
    call   ref_31_DV2AXY
    lea    rax,[r14+0x1]
    dec    rdi
    add    rbx,r15
    add    r15,0x2
    cmp    r14,rbp
    mov    r14,rax
    {disp32} jge    at_1_00aa
at_1_02f9:
    mov    rax,r13
    imul   r12d,r12d,0xd68
    mov    rcx,r12
    mov    edx,0xd2487055
    imul   rcx,rdx
    shr    rcx,0x2d
    imul   ecx,ecx,0x26f5
    sub    r12d,ecx
    xorps  xmm0,xmm0
    cvtsi2ss xmm0,r12d
    sub    rax,r14
    mov    QWORD PTR [rsp+0x38],rax
    cvtss2sd xmm0,xmm0
    divsd  xmm0,xmm6
    addsd  xmm0,xmm7
    mulsd  xmm0,xmm8
    movsd  QWORD PTR [rsp+0x40],xmm0
    test   rax,rax
    {disp32} jle    at_1_03d0
    mov    rdx,rbx
    and    rdx,0xfffffffffffffffe
    lea    rcx,[rdi+r13*1]
    cmp    rcx,0x2
    mov    r8d,0x1
    cmovl  rcx,r8
    mov    r9,QWORD PTR [rsp+0x28]
    lea    rdx,[r9+rdx*4]
    xorpd  xmm1,xmm1
    xor    r8d,r8d
    xorpd  xmm2,xmm2
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0380:
    movsd  xmm3,QWORD PTR [rdx+r8*8]
    mulsd  xmm3,xmm0
    movsd  xmm4,QWORD PTR [rsi+r8*8]
    movapd xmm5,xmm3
    addsd  xmm5,xmm4
    andpd  xmm5,xmm10
    addsd  xmm2,xmm5
    subsd  xmm3,xmm4
    andpd  xmm3,xmm10
    addsd  xmm1,xmm3
    inc    r8
    cmp    r8,rax
    jl     at_1_0380
    inc    rcx
    mov    QWORD PTR [rsp+0x30],rcx
    ucomisd xmm1,xmm2
    {disp32} jbe    at_1_02b0
    jmp    at_1_03e7
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_03d0:
    xorpd  xmm1,xmm1
    xorpd  xmm2,xmm2
    mov    r9,QWORD PTR [rsp+0x28]
    ucomisd xmm1,xmm2
    {disp32} jbe    at_1_02b0
at_1_03e7:
    xorpd  xmm0,xmm9
    movlpd QWORD PTR [rsp+0x40],xmm0
    {disp32} jmp    at_1_02b0
at_1_03f7:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_40c37a8000000000:
at_4_0000:
    .quad 0x40c37a8000000000    # binary64 9973.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fe0000000000000:
at_6_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_7fffffffffffffff7fffffffffffffff:
at_7_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_xmm_80000000000000008000000000000000:
at_8_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_8_0010:
end_s8:

# .xdata  (COFF section 9)
.section .s9,"dr"
def_21_xdata:
at_9_0000:
    .byte 0x01    # version 1
    .byte at_1_003d - at_1_0000    # prologue size
    .byte 0x14    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_003d - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x06
    .byte 0x00
    .byte at_1_0037 - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x07
    .byte 0x00
    .byte at_1_0031 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x08
    .byte 0x00
    .byte at_1_0027 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x09
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x0a
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x17
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_9_002c:
end_s9:

# .drectve  (COFF section 10)
.section .s10,"dr"
def_23_drectve:
at_10_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_10_00b9:
end_s10:

# .pdata  (COFF section 11)
.section .s11,"dr"
def_25_pdata:
at_11_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_03f7 - def_0_text)    # image-relative end
    .long ref_21_xdata    # image-relative unwind info
at_11_000c:
end_s11:

# MEMBER dl7svn.obj
# Entry points: DL7SVN
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_28_DL7SVN:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0xb8
at_1_0013:
    movapd XMMWORD PTR [rsp+0xa0],xmm11
at_1_001d:
    movapd XMMWORD PTR [rsp+0x90],xmm10
at_1_0027:
    movapd XMMWORD PTR [rsp+0x80],xmm9
at_1_0031:
    movapd XMMWORD PTR [rsp+0x70],xmm8
at_1_0038:
    movapd XMMWORD PTR [rsp+0x60],xmm7
at_1_003e:
    movapd XMMWORD PTR [rsp+0x50],xmm6
at_1_0044:
    mov    QWORD PTR [rsp+0x28],r9
    mov    rbx,rdx
    mov    QWORD PTR [rsp+0x40],rcx
    mov    r10,QWORD PTR [rcx]
    lea    r11,[r10-0x1]
    mov    rax,r11
    imul   rax,r10
    shr    rax,1
    lea    rcx,[rax+r10*1]
    movsd  xmm2,QWORD PTR [rdx+rcx*8-0x8]
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm2
    setnp  cl
    sete   dl
    test   dl,cl
    {disp32} jne    at_1_01a7
    mov    r14,r8
    mov    ecx,0x1ad0
    xorps  xmm0,xmm0
    cvtsi2ss xmm0,ecx
    cvtss2sd xmm1,xmm0
    divsd  xmm1,QWORD PTR [rip + ref_8_real_40c37a8000000000]
    addsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    mulsd  xmm1,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    divsd  xmm1,xmm2
    movsd  QWORD PTR [rsp+0x38],xmm1
    movsd  QWORD PTR [r8+r10*8-0x8],xmm1
    cmp    r10,0x2
    {disp32} jge    at_1_01e6
at_1_00c8:
    mov    rsi,QWORD PTR [rsp+0x40]
    mov    rcx,rsi
    mov    rdx,r14
    call   ref_29_DV2NRM
    movsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    movapd xmm6,xmm1
    divsd  xmm1,xmm0
    mov    rsi,QWORD PTR [rsi]
    test   rsi,rsi
    mov    rdx,QWORD PTR [rsp+0x28]
    {disp32} jle    at_1_0191
    xor    eax,eax
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0100:
    movsd  xmm0,QWORD PTR [r14+rax*8]
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [r14+rax*8],xmm0
    inc    rax
    cmp    rsi,rax
    jne    at_1_0100
    mov    edi,0x2
    xor    r12d,r12d
    lea    r15,[rsp+0x30]
    xor    ebp,ebp
    jmp    at_1_015c
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0130:
    mov    rax,r12
    shr    rax,1
    movsd  xmm1,QWORD PTR [r14+rbp*8]
    subsd  xmm1,xmm0
    add    rax,rbp
    divsd  xmm1,QWORD PTR [rbx+rax*8]
    movsd  QWORD PTR [rdx+rbp*8],xmm1
    add    r12,rdi
    add    rdi,0x2
    mov    rbp,r13
    cmp    r13,rsi
    jge    at_1_0191
at_1_015c:
    lea    r13,[rbp+0x1]
    mov    QWORD PTR [rsp+0x30],rbp
    xorpd  xmm0,xmm0
    cmp    r13,0x2
    jb     at_1_0130
    mov    rax,rbp
    imul   rax,r13
    shr    rax,1
    lea    rdx,[rbx+rax*8]
    mov    rcx,r15
    mov    r8,QWORD PTR [rsp+0x28]
    call   ref_30_DD7TPR
    mov    rdx,QWORD PTR [rsp+0x28]
    jmp    at_1_0130
at_1_0191:
    mov    rcx,QWORD PTR [rsp+0x40]
    call   ref_29_DV2NRM
    movapd xmm1,xmm0
    movapd xmm0,xmm6
    divsd  xmm0,xmm1
at_1_01a7:
    movaps xmm6,XMMWORD PTR [rsp+0x50]
    movaps xmm7,XMMWORD PTR [rsp+0x60]
    movaps xmm8,XMMWORD PTR [rsp+0x70]
    movaps xmm9,XMMWORD PTR [rsp+0x80]
    movaps xmm10,XMMWORD PTR [rsp+0x90]
    movaps xmm11,XMMWORD PTR [rsp+0xa0]
    add    rsp,0xb8
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_01e6:
    lea    rax,[rbx+rax*8]
    xor    ecx,ecx
    xor    edx,edx
    xchg   ax,ax
at_1_01f0:
    lea    r8,[rcx+rdx*1]
    xorps  xmm0,xmm0
    ucomisd xmm0,QWORD PTR [rbx+r8*8]
    setnp  r8b
    sete   r9b
    test   r9b,r8b
    jne    at_1_01a7
    add    rdx,rcx
    inc    rdx
    movsd  xmm0,QWORD PTR [rax+rcx*8]
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [r14+rcx*8],xmm0
    inc    rcx
    cmp    rcx,r11
    jl     at_1_01f0
    lea    r15,[r10-0x2]
    mov    rbp,r11
    imul   rbp,r15
    mov    edi,0x4
    sub    rdi,r10
    sub    rdi,r10
    mov    r12d,0x1ad0
    mov    r13d,0x1
    mov    esi,0xd2487055
    movsd  xmm6,QWORD PTR [rip + ref_8_real_40c37a8000000000]
    movsd  xmm7,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    movsd  xmm8,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    movapd xmm9,XMMWORD PTR [rip + ref_17_xmm_80000000000000008000000000000000]
    movapd xmm10,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    jmp    at_1_029a
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0280:
    lea    rax,[r13+0x1]
    dec    r15
    add    rbp,rdi
    add    rdi,0x2
    cmp    r13,r11
    mov    r13,rax
    {disp32} jge    at_1_00c8
at_1_029a:
    cmp    r15,0x2
    mov    ecx,0x1
    cmovge rcx,r15
    mov    rax,r10
    imul   r12d,r12d,0xd68
    mov    rdx,r12
    imul   rdx,rsi
    shr    rdx,0x2d
    imul   edx,edx,0x26f5
    sub    r12d,edx
    xorps  xmm0,xmm0
    cvtsi2ss xmm0,r12d
    sub    rax,r13
    cvtss2sd xmm0,xmm0
    divsd  xmm0,xmm6
    addsd  xmm0,xmm7
    mulsd  xmm0,xmm8
    lea    rdx,[rax-0x1]
    movsd  xmm2,QWORD PTR [r14+rax*8-0x8]
    movapd xmm1,xmm0
    subsd  xmm1,xmm2
    xorpd  xmm0,xmm9
    subsd  xmm0,xmm2
    movapd xmm2,xmm1
    andpd  xmm2,xmm10
    movapd xmm3,xmm0
    andpd  xmm3,xmm10
    mov    QWORD PTR [rsp+0x30],rdx
    imul   rdx,rax
    shr    rdx,1
    lea    r8,[rdx+rax*1]
    movsd  xmm4,QWORD PTR [rbx+r8*8-0x8]
    divsd  xmm1,xmm4
    movsd  QWORD PTR [rsp+0x38],xmm1
    divsd  xmm0,xmm4
    cmp    rax,0x2
    jl     at_1_038e
    mov    r8,rbp
    and    r8,0xfffffffffffffffe
    lea    r8,[rbx+r8*4]
    xor    r9d,r9d
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0350:
    movsd  xmm4,QWORD PTR [r14+r9*8]
    movsd  xmm5,QWORD PTR [r8+r9*8]
    movapd xmm11,xmm5
    mulsd  xmm11,xmm1
    addsd  xmm11,xmm4
    andpd  xmm11,xmm10
    addsd  xmm2,xmm11
    mulsd  xmm5,xmm0
    addsd  xmm5,xmm4
    andpd  xmm5,xmm10
    addsd  xmm3,xmm5
    inc    r9
    cmp    rcx,r9
    jne    at_1_0350
at_1_038e:
    ucomisd xmm3,xmm2
    jbe    at_1_039e
    movsd  QWORD PTR [rsp+0x38],xmm0
    movapd xmm1,xmm0
at_1_039e:
    movsd  QWORD PTR [r14+rax*8-0x8],xmm1
    cmp    rax,0x2
    {disp32} jl     at_1_0280
    lea    r9,[rbx+rdx*8]
    mov    QWORD PTR [rsp+0x20],r14
    lea    rcx,[rsp+0x30]
    mov    rdx,r14
    lea    r8,[rsp+0x38]
    mov    rsi,r12
    mov    r12,r10
    mov    QWORD PTR [rsp+0x48],rbp
    mov    rbp,r13
    mov    r13,rbx
    mov    rbx,r11
    call   ref_31_DV2AXY
    mov    r11,rbx
    mov    rbx,r13
    mov    r13,rbp
    mov    rbp,QWORD PTR [rsp+0x48]
    mov    r10,r12
    mov    r12,rsi
    mov    esi,0xd2487055
    {disp32} jmp    at_1_0280
at_1_03fc:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_40c37a8000000000:
at_4_0000:
    .quad 0x40c37a8000000000    # binary64 9973.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fe0000000000000:
at_6_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_80000000000000008000000000000000:
at_7_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_xmm_7fffffffffffffff7fffffffffffffff:
at_8_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_8_0010:
end_s8:

# .xdata  (COFF section 9)
.section .s9,"dr"
def_21_xdata:
at_9_0000:
    .byte 0x01    # version 1
    .byte at_1_0044 - at_1_0000    # prologue size
    .byte 0x16    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0044 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x05
    .byte 0x00
    .byte at_1_003e - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x06
    .byte 0x00
    .byte at_1_0038 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x07
    .byte 0x00
    .byte at_1_0031 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x08
    .byte 0x00
    .byte at_1_0027 - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x09
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x0a
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x17
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_9_0030:
end_s9:

# .drectve  (COFF section 10)
.section .s10,"dr"
def_23_drectve:
at_10_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_10_00b9:
end_s10:

# .pdata  (COFF section 11)
.section .s11,"dr"
def_25_pdata:
at_11_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_03fc - def_0_text)    # image-relative end
    .long ref_21_xdata    # image-relative unwind info
at_11_000c:
end_s11:

# MEMBER dl7srt.obj
# Entry points: DL7SRT
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7SRT:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbx
at_1_000b:
    mov    rax,QWORD PTR [rsp+0x60]
    mov    rcx,QWORD PTR [rcx]
    mov    rdx,QWORD PTR [rdx]
    cmp    rdx,rcx
    jge    at_1_0022
at_1_001b:
    xor    ecx,ecx
    {disp32} jmp    at_1_0121
at_1_0022:
    lea    r10,[rcx-0x1]
    imul   r10,rcx
    shr    r10,1
    lea    r11,[r8+r10*8]
    lea    rsi,[rcx*8+0x0]
    xorpd  xmm0,xmm0
    nop    DWORD PTR [rax]
at_1_0040:
    xorpd  xmm1,xmm1
    cmp    rcx,0x2
    jge    at_1_0090
at_1_004a:
    add    r10,rcx
    movsd  xmm2,QWORD PTR [r9+r10*8-0x8]
    subsd  xmm2,xmm1
    ucomisd xmm0,xmm2
    {disp32} jae    at_1_011a
    xorps  xmm1,xmm1
    sqrtsd xmm1,xmm2
    movsd  QWORD PTR [r8+r10*8-0x8],xmm1
    lea    rdi,[rcx+0x1]
    add    r11,rsi
    add    rsi,0x8
    cmp    rcx,rdx
    mov    rcx,rdi
    jl     at_1_0040
    jmp    at_1_001b
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0090:
    mov    edi,0x1
    mov    ebx,0x8
    mov    r14,r8
    xor    r15d,r15d
    xor    r12d,r12d
    jmp    at_1_00ee
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_00b0:
    lea    r13,[rdi+r10*1]
    add    r12,rdi
    movsd  xmm3,QWORD PTR [r9+r13*8-0x8]
    subsd  xmm3,xmm2
    divsd  xmm3,QWORD PTR [r8+r12*8-0x8]
    movsd  QWORD PTR [r8+r13*8-0x8],xmm3
    mulsd  xmm3,xmm3
    addsd  xmm1,xmm3
    inc    rdi
    inc    r15
    add    r14,rbx
    add    rbx,0x8
    cmp    rdi,rcx
    {disp32} je     at_1_004a
at_1_00ee:
    xorpd  xmm2,xmm2
    cmp    rdi,0x1
    je     at_1_00b0
    xor    r13d,r13d
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0100:
    movsd  xmm3,QWORD PTR [r11+r13*8]
    mulsd  xmm3,QWORD PTR [r14+r13*8]
    addsd  xmm2,xmm3
    inc    r13
    cmp    r15,r13
    jne    at_1_0100
    jmp    at_1_00b0
at_1_011a:
    movsd  QWORD PTR [r8+r10*8-0x8],xmm2
at_1_0121:
    mov    QWORD PTR [rax],rcx
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0130:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000b - at_1_0000    # prologue size
    .byte 0x07    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_4_0014:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0130 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dl7sqr.obj
# Entry points: DL7SQR
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7SQR:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x18
at_1_0010:
    mov    QWORD PTR [rsp],r8
    mov    rax,QWORD PTR [rcx]
    mov    QWORD PTR [rsp+0x8],rax
    test   rax,rax
    {disp32} jle    at_1_0119
    mov    rax,QWORD PTR [rsp+0x8]
    lea    r9,[rax+0x1]
    mov    QWORD PTR [rsp+0x10],r9
    imul   r9,rax
    mov    r10,r9
    shr    r10,1
    mov    r11,rax
    neg    r11
    lea    rsi,[rax+rax*1]
    neg    rsi
    lea    rax,[rax*8+0x0]
    mov    edi,0x8
    sub    rdi,rax
    lea    rbx,[r10*8+0x0]
    sub    rbx,rax
    add    rbx,QWORD PTR [rsp]
    mov    r14d,0x1
    jmp    at_1_009f
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0080:
    lea    rax,[r14+0x1]
    inc    r11
    add    r9,rsi
    add    rsi,0x2
    add    rbx,rdi
    add    rdi,0x8
    cmp    r14,QWORD PTR [rsp+0x8]
    mov    r14,rax
    je     at_1_0119
at_1_009f:
    mov    r15,QWORD PTR [rsp+0x10]
    sub    r15,r14
    sub    r10,r15
    test   r15,r15
    jle    at_1_0080
    mov    rax,r9
    shr    rax,1
    add    rax,r11
    mov    rcx,QWORD PTR [rsp]
    lea    r12,[rcx+rax*8]
    lea    r8,[r15+0x1]
    mov    ecx,0x1
    mov    rbp,rdi
    jmp    at_1_00ed
    xchg   ax,ax
at_1_00d0:
    add    r13,r10
    movsd  QWORD PTR [rdx+r13*8-0x8],xmm0
    lea    rax,[rcx+0x1]
    add    r12,rbp
    add    rbp,0x8
    cmp    rcx,r15
    mov    rcx,rax
    jge    at_1_0080
at_1_00ed:
    mov    r13,r8
    xorpd  xmm0,xmm0
    sub    r13,rcx
    jle    at_1_00d0
    xor    eax,eax
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0100:
    movsd  xmm1,QWORD PTR [rbx+rax*8]
    mulsd  xmm1,QWORD PTR [r12+rax*8]
    addsd  xmm0,xmm1
    inc    rax
    cmp    rax,r13
    jl     at_1_0100
    jmp    at_1_00d0
at_1_0119:
    add    rsp,0x18
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_012a:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0010 - at_1_0000    # prologue size
    .byte 0x09    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0x22
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_4_0018:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_012a - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dl7nvr.obj
# Entry points: DL7NVR
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_16_DL7NVR:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x30
at_1_0010:
    mov    rax,QWORD PTR [rcx]
    mov    QWORD PTR [rsp],rax
    test   rax,rax
    {disp32} jle    at_1_018c
    mov    rax,QWORD PTR [rsp]
    lea    r9,[rax+0x1]
    imul   r9,rax
    shr    r9,1
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movapd xmm1,xmm0
    divsd  xmm1,QWORD PTR [r8+r9*8-0x8]
    movsd  QWORD PTR [rdx+r9*8-0x8],xmm1
    cmp    rax,0x1
    {disp32} je     at_1_018c
    mov    rcx,QWORD PTR [rsp]
    lea    rax,[rcx-0x2]
    mov    QWORD PTR [rsp+0x10],rax
    lea    rax,[rcx*8+0x0]
    lea    r11,[r8+rcx*8]
    add    r11,0xfffffffffffffff8
    mov    rsi,rcx
    not    rsi
    mov    r10d,0x8
    sub    r10,rax
    mov    QWORD PTR [rsp+0x8],r10
    mov    r10d,0x1
    sub    r10,rcx
    xor    eax,eax
    nop
at_1_0090:
    mov    QWORD PTR [rsp+0x18],rax
    mov    r15,rax
    not    r15
    add    r15,QWORD PTR [rsp]
    cmp    r15,0x2
    mov    eax,0x1
    cmovl  r15,rax
    dec    r15
    lea    r12,[rdx+r9*8]
    mov    QWORD PTR [rsp+0x20],rsi
    lea    rax,[r9+rsi*1]
    mov    QWORD PTR [rsp+0x28],r11
    lea    rax,[r11+rax*8]
    xor    ecx,ecx
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_00d0:
    mov    r11,r9
    mov    rbp,r9
    sub    rbp,rcx
    lea    r9,[rbp-0x1]
    xorpd  xmm1,xmm1
    mov    r14d,0x1
    mov    rbx,r10
    mov    r13,rax
    mov    rsi,QWORD PTR [rsp+0x8]
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0100:
    movsd  xmm2,QWORD PTR [r8+r9*8-0x8]
    mulsd  xmm2,QWORD PTR [r12+r14*8-0x10]
    subsd  xmm1,xmm2
    add    r9,rbx
    dec    r14
    add    r13,rsi
    add    rsi,0x8
    inc    rbx
    mov    rdi,rcx
    add    rdi,r14
    jne    at_1_0100
    divsd  xmm1,QWORD PTR [r13+0x0]
    movsd  QWORD PTR [rdx+rbp*8-0x10],xmm1
    lea    r9,[rcx+0x1]
    add    rax,0xfffffffffffffff8
    cmp    rcx,r15
    mov    rcx,r9
    mov    r9,r11
    jne    at_1_00d0
    lea    r9,[rbp-0x2]
    movapd xmm1,xmm0
    divsd  xmm1,QWORD PTR [r8+rbp*8-0x18]
    movsd  QWORD PTR [rdx+rbp*8-0x18],xmm1
    mov    rcx,QWORD PTR [rsp+0x18]
    lea    rax,[rcx+0x1]
    mov    r11,QWORD PTR [rsp+0x28]
    add    r11,0xfffffffffffffff8
    mov    rsi,QWORD PTR [rsp+0x20]
    inc    rsi
    add    QWORD PTR [rsp+0x8],0x8
    inc    r10
    cmp    rcx,QWORD PTR [rsp+0x10]
    {disp32} jne    at_1_0090
at_1_018c:
    add    rsp,0x30
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_019d:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_0010 - at_1_0000    # prologue size
    .byte 0x09    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0x52
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_5_0018:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_11_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_13_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_019d - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dl7mst.obj
# Entry points: DL7MST
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_48_DL7MST:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x168
at_1_0013:
    movapd XMMWORD PTR [rsp+0x150],xmm15
at_1_001d:
    movapd XMMWORD PTR [rsp+0x140],xmm14
at_1_0027:
    movapd XMMWORD PTR [rsp+0x130],xmm13
at_1_0031:
    movapd XMMWORD PTR [rsp+0x120],xmm12
at_1_003b:
    movapd XMMWORD PTR [rsp+0x110],xmm11
at_1_0045:
    movaps XMMWORD PTR [rsp+0x100],xmm10
at_1_004e:
    movapd XMMWORD PTR [rsp+0xf0],xmm9
at_1_0058:
    movapd XMMWORD PTR [rsp+0xe0],xmm8
at_1_0062:
    movapd XMMWORD PTR [rsp+0xd0],xmm7
at_1_006b:
    movapd XMMWORD PTR [rsp+0xc0],xmm6
at_1_0074:
    mov    rbp,r9
    mov    QWORD PTR [rsp+0x30],rdx
    mov    r12,rcx
    mov    rax,QWORD PTR [rsp+0x1f8]
    mov    rbx,QWORD PTR [rsp+0x1d8]
    mov    rdx,QWORD PTR [rbx]
    lea    r9,[rdx+0x1]
    mov    rcx,rdx
    mov    QWORD PTR [rsp+0x20],rdx
    imul   r9,rdx
    shr    r9,1
    mov    rcx,r9
    mov    QWORD PTR [rsp+0x48],r9
    mov    QWORD PTR [rsp+0xa8],r9
    movsd  xmm10,QWORD PTR [rax+0x38]
    xorpd  xmm0,xmm0
    ucomisd xmm10,xmm0
    jbe    at_1_0106
    movsd  xmm3,QWORD PTR [rax+0x90]
    movsd  xmm1,QWORD PTR [rax+0x98]
    addsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mulsd  xmm1,QWORD PTR [rip + ref_11_real_4020000000000000]
    addsd  xmm1,QWORD PTR [rip + ref_14_real_4008000000000000]
    movapd xmm2,xmm10
    mulsd  xmm2,xmm10
    mulsd  xmm2,xmm1
    divsd  xmm3,xmm2
    movsd  QWORD PTR [rsp+0x68],xmm3
at_1_0106:
    mov    r15,QWORD PTR [rsp+0x1d0]
    ucomisd xmm0,QWORD PTR [rip + ref_49_DL7MST_BIG]
    jb     at_1_0132
    lea    rcx,[rip + ref_50_unnamed_1]
    mov    rsi,r8
    call   ref_51_DR7MDC
    mov    r8,rsi
    movsd  QWORD PTR [rip + ref_49_DL7MST_BIG],xmm0
at_1_0132:
    mov    rsi,QWORD PTR [rsp+0x200]
    mov    r14,QWORD PTR [rsp+0x1f0]
    mov    rax,QWORD PTR [rsp+0x20]
    lea    rdi,[rax+0x4]
    mov    rcx,QWORD PTR [rsp+0x48]
    lea    rax,[rcx+rax*1+0x4]
    mov    QWORD PTR [rsp+0x58],rax
    mov    rax,QWORD PTR [rsp+0x1f8]
    movsd  xmm0,QWORD PTR [rax+0xa0]
    mulsd  xmm0,xmm10
    movsd  QWORD PTR [rsp+0x40],xmm0
    movsd  xmm0,QWORD PTR [rax+0x98]
    mulsd  xmm0,xmm10
    movsd  QWORD PTR [rsp+0x70],xmm0
    mov    rax,QWORD PTR [r15]
    test   rax,rax
    mov    rdx,QWORD PTR [rsp+0x30]
    movsd  QWORD PTR [rsp+0x78],xmm10
    mov    QWORD PTR [rsp+0xa0],r12
    {disp32} js     at_1_0294
    {disp32} je     at_1_030f
    mov    r13,rax
    add    rax,0xc
    mov    QWORD PTR [rsp+0x38],rax
    mov    rax,QWORD PTR [rsp+0x20]
    movsd  xmm11,QWORD PTR [rsi+rax*8]
    movsd  xmm12,QWORD PTR [rsi+rax*8+0x10]
    mov    rax,QWORD PTR [rsp+0x1f8]
    movsd  xmm1,QWORD PTR [rax+0x10]
    movapd xmm0,xmm1
    subsd  xmm0,xmm10
    movsd  xmm2,QWORD PTR [rsp+0x40]
    ucomisd xmm2,xmm0
    setae  al
    xorpd  xmm2,xmm2
    ucomisd xmm1,xmm2
    jbe    at_1_0201
    test   al,al
    {disp32} jne    at_1_0326
at_1_0201:
    mov    rcx,QWORD PTR [rsp+0x1f8]
    movsd  xmm13,QWORD PTR [rcx+0x20]
    andpd  xmm13,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    mov    rax,QWORD PTR [rsp+0x20]
    movsd  xmm7,QWORD PTR [rsi+rax*8+0x18]
    movapd xmm9,xmm7
    subsd  xmm9,xmm10
    movsd  xmm0,QWORD PTR [rcx]
    divsd  xmm0,xmm10
    ucomisd xmm2,xmm13
    setae  al
    ucomisd xmm10,QWORD PTR [rcx+0x40]
    {disp32} jbe    at_1_053a
    ucomisd xmm12,xmm0
    movapd xmm2,xmm0
    ja     at_1_025a
    movapd xmm2,xmm12
at_1_025a:
    test   al,al
    jne    at_1_0262
    movapd xmm0,xmm2
at_1_0262:
    xorpd  xmm11,xmm11
    ucomisd xmm1,xmm11
    {disp32} jbe    at_1_0566
    subsd  xmm1,xmm10
    mov    rax,QWORD PTR [rsp+0x20]
    mulsd  xmm1,QWORD PTR [rsi+rax*8+0x8]
    xorpd  xmm2,xmm2
    maxsd  xmm1,xmm2
    movapd xmm11,xmm1
    {disp32} jmp    at_1_0566
at_1_0294:
    mov    QWORD PTR [r15],0x0
    mov    rax,QWORD PTR [rbx]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x50],r8
    mov    rax,QWORD PTR [r8]
    test   rax,rax
    je     at_1_02c2
    mov    rcx,rax
    neg    rcx
    cmovs  rcx,rax
    dec    rcx
    mov    QWORD PTR [rsp+0x28],rcx
at_1_02c2:
    lea    rcx,[rsp+0x28]
    mov    rdx,QWORD PTR [rsp+0x1e0]
    mov    r8,rdx
    call   ref_52_DD7TPR
    mulsd  xmm0,QWORD PTR [rip + ref_20_real_3fe0000000000000]
    mov    rcx,QWORD PTR [rsp+0x1f8]
    movsd  QWORD PTR [rcx+0x28],xmm0
    xorpd  xmm11,xmm11
    mov    eax,0xc
    mov    QWORD PTR [rsp+0x38],rax
    xor    r13d,r13d
    xorpd  xmm12,xmm12
    mov    rdx,QWORD PTR [rsp+0x30]
    mov    r8,QWORD PTR [rsp+0x50]
    jmp    at_1_032e
at_1_030f:
    xorpd  xmm11,xmm11
    mov    eax,0xc
    mov    QWORD PTR [rsp+0x38],rax
    xor    r13d,r13d
    xorpd  xmm12,xmm12
at_1_0326:
    mov    rcx,QWORD PTR [rsp+0x1f8]
at_1_032e:
    movabs rax,0xbff0000000000000
    mov    QWORD PTR [rcx+0x10],rax
    cmp    QWORD PTR [r8],0x0
    {disp32} je     at_1_0400
at_1_0346:
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_0368
    xor    ecx,ecx
at_1_0350:
    movsd  xmm0,QWORD PTR [rdx+rcx*8]
    divsd  xmm0,QWORD PTR [r12+rcx*8]
    movsd  QWORD PTR [rsi+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0350
at_1_0368:
    mov    rcx,rbx
    mov    rdx,rsi
    call   ref_53_DV2NRM
    movapd xmm12,xmm0
    mov    rax,QWORD PTR [rsp+0x1f8]
    movsd  QWORD PTR [rax],xmm0
    divsd  xmm12,xmm10
    xorpd  xmm8,xmm8
    ucomisd xmm8,xmm12
    jb     at_1_03d6
    xorpd  xmm0,xmm0
    movupd XMMWORD PTR [rax+0x18],xmm0
    mov    QWORD PTR [rax+0x30],0x0
    mov    r8,QWORD PTR [rbx]
    xorpd  xmm7,xmm7
    test   r8,r8
    mov    rdi,rax
    {disp32} jle    at_1_05a0
    cmp    r8,0xc
    {disp32} jbe    at_1_0585
    shl    r8,0x3
    mov    rcx,r14
    xor    edx,edx
    call   ref_54_intel_fast_memset
    {disp32} jmp    at_1_05a0
at_1_03d6:
    movsd  xmm0,QWORD PTR [rax+0x20]
    andpd  xmm0,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    mulsd  xmm0,QWORD PTR [rax+0x40]
    divsd  xmm0,xmm10
    maxsd  xmm0,xmm11
    movapd xmm6,xmm12
    minsd  xmm6,xmm0
    {disp32} jmp    at_1_064d
at_1_0400:
    mov    rax,QWORD PTR [rsp+0x58]
    lea    r9,[rsi+rax*8]
    mov    rcx,rbx
    mov    rdx,QWORD PTR [rsp+0x1e8]
    mov    r8,r14
    call   ref_55_DL7SVN
    ucomisd xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    jae    at_1_044c
    movapd xmm7,xmm0
    mov    rcx,rbx
    mov    rdx,QWORD PTR [rsp+0x1e0]
    call   ref_53_DV2NRM
    mulsd  xmm7,QWORD PTR [rip + ref_49_DL7MST_BIG]
    ucomisd xmm0,xmm7
    {disp32} jae    at_1_0643
at_1_044c:
    mov    rcx,rbx
    mov    rdx,rsi
    mov    r8,QWORD PTR [rsp+0x1e8]
    mov    r9,QWORD PTR [rsp+0x1e0]
    call   ref_56_DL7ITV
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_049f
    xor    ecx,ecx
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0480:
    mov    rdx,QWORD PTR [rbp+rcx*8+0x0]
    movsd  xmm0,QWORD PTR [r12+rdx*8-0x8]
    mulsd  xmm0,QWORD PTR [rsi+rcx*8]
    movsd  QWORD PTR [r14+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0480
at_1_049f:
    mov    rcx,rbx
    mov    rdx,r14
    call   ref_53_DV2NRM
    movapd xmm7,xmm0
    mov    rax,QWORD PTR [rsp+0x1f8]
    movsd  QWORD PTR [rax+0x10],xmm0
    movapd xmm8,xmm0
    subsd  xmm8,xmm10
    movsd  xmm0,QWORD PTR [rsp+0x40]
    ucomisd xmm0,xmm8
    jb     at_1_0527
    mov    rax,QWORD PTR [rbx]
    xorpd  xmm0,xmm0
    test   rax,rax
    {disp32} jle    at_1_05af
    xor    ecx,ecx
    movapd xmm1,XMMWORD PTR [rip + ref_29_xmm_80000000000000008000000000000000]
    mov    rdi,QWORD PTR [rsp+0x1f8]
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0500:
    mov    rdx,QWORD PTR [rbp+rcx*8+0x0]
    movsd  xmm2,QWORD PTR [rsi+rcx*8]
    xorpd  xmm2,xmm1
    movlpd QWORD PTR [r14+rdx*8-0x8],xmm2
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0500
    xorpd  xmm13,xmm13
    {disp32} jmp    at_1_0e2d
at_1_0527:
    test   r13,r13
    {disp32} jle    at_1_05b9
    xorpd  xmm8,xmm8
    {disp32} jmp    at_1_064d
at_1_053a:
    xorpd  xmm3,xmm3
    test   al,al
    jne    at_1_0547
    movapd xmm2,xmm11
at_1_0547:
    ucomisd xmm1,xmm3
    jbe    at_1_0561
    subsd  xmm1,xmm10
    mov    rax,QWORD PTR [rsp+0x20]
    mulsd  xmm1,QWORD PTR [rsi+rax*8+0x8]
    maxsd  xmm2,xmm1
at_1_0561:
    movapd xmm11,xmm2
at_1_0566:
    xorpd  xmm8,xmm8
    ucomisd xmm8,xmm9
    movapd xmm12,xmm0
    minsd  xmm12,xmm13
    {disp32} jbe    at_1_0d19
    {disp32} jmp    at_1_0d1e
at_1_0585:
    xor    eax,eax
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0590:
    mov    QWORD PTR [r14+rax*8],0x0
    inc    rax
    cmp    r8,rax
    jne    at_1_0590
at_1_05a0:
    xorpd  xmm11,xmm11
    xorpd  xmm12,xmm12
    {disp32} jmp    at_1_0e6d
at_1_05af:
    xorpd  xmm13,xmm13
    {disp32} jmp    at_1_0e25
at_1_05b9:
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_05f4
    xor    ecx,ecx
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_05d0:
    mov    rdx,QWORD PTR [rbp+rcx*8+0x0]
    movsd  xmm0,QWORD PTR [r14+rcx*8]
    divsd  xmm0,xmm7
    mulsd  xmm0,QWORD PTR [r12+rdx*8-0x8]
    movsd  QWORD PTR [r14+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_05d0
at_1_05f4:
    mov    rcx,rbx
    mov    rdx,r14
    mov    r8,QWORD PTR [rsp+0x1e8]
    mov    r9,r14
    call   ref_57_DL7IVM
    mov    rcx,rbx
    mov    rdx,r14
    call   ref_53_DV2NRM
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    divsd  xmm1,xmm0
    movapd xmm0,xmm1
    divsd  xmm0,xmm10
    mulsd  xmm0,xmm1
    mov    rax,QWORD PTR [rsp+0x20]
    movsd  QWORD PTR [rsi+rax*8+0x8],xmm0
    mulsd  xmm8,xmm0
    movapd xmm11,xmm8
at_1_0643:
    mov    rdx,QWORD PTR [rsp+0x30]
    {disp32} jmp    at_1_0346
at_1_064d:
    inc    r13
    mov    QWORD PTR [r15],r13
    lea    rdx,[rsi+rdi*8]
    lea    rcx,[rsp+0xa8]
    mov    QWORD PTR [rsp+0x50],rdx
    mov    r8,QWORD PTR [rsp+0x1e8]
    call   ref_58_DV7CPY
    mov    rax,QWORD PTR [rsp+0x58]
    lea    r15,[rsi+rax*8]
    mov    rcx,rbx
    mov    rdx,r15
    mov    r8,QWORD PTR [rsp+0x1e0]
    call   ref_58_DV7CPY
    ucomisd xmm11,xmm6
    seta   cl
    ucomisd xmm6,xmm12
    setae  al
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm6
    jae    at_1_06af
    test   cl,cl
    jne    at_1_06af
    test   al,al
    je     at_1_06cd
at_1_06af:
    movapd xmm0,xmm11
    divsd  xmm0,xmm12
    xorps  xmm6,xmm6
    sqrtsd xmm6,xmm0
    maxsd  xmm6,QWORD PTR [rip + ref_23_real_3f50624dd2f1a9fc]
    mulsd  xmm6,xmm12
at_1_06cd:
    mov    QWORD PTR [rsp+0x88],r15
    movsd  QWORD PTR [rsp+0x80],xmm8
    mov    QWORD PTR [rsp+0x90],r13
    movsd  QWORD PTR [rsp+0x98],xmm11
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm6
    jb     at_1_0708
    movsd  xmm6,QWORD PTR [rip + ref_20_real_3fe0000000000000]
    mulsd  xmm6,xmm12
at_1_0708:
    movsd  QWORD PTR [rsp+0x60],xmm12
    movapd XMMWORD PTR [rsp+0xb0],xmm6
    xorps  xmm0,xmm0
    sqrtsd xmm0,xmm6
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    {disp32} jle    at_1_0ba8
    lea    rcx,[rax+0x1]
    xor    edx,edx
    movabs r8,0x3ff0000000000000
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0740:
    mov    QWORD PTR [rsi+rdx*8],r8
    inc    rdx
    cmp    rax,rdx
    jne    at_1_0740
    mov    r13d,0x1
    xor    edx,edx
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    movsd  xmm3,QWORD PTR [rip + ref_26_real_4004000000000000]
    movapd xmm4,XMMWORD PTR [rip + ref_29_xmm_80000000000000008000000000000000]
    xorpd  xmm5,xmm5
    movsd  xmm7,QWORD PTR [rip + ref_32_real_3f70000000000000]
    movapd xmm15,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm9,QWORD PTR [rip + ref_35_real_40f0000000000000]
    movsd  xmm11,QWORD PTR [rip + ref_38_real_4070000000000000]
    jmp    at_1_07ba
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07a0:
    inc    rdx
    cmp    rax,r13
    mov    r13,r15
    mov    rbp,r12
    mov    r12,QWORD PTR [rsp+0xa0]
    {disp32} jle    at_1_0ba8
at_1_07ba:
    lea    r15,[r13+0x1]
    mov    r9,r15
    imul   r9,r13
    shr    r9,1
    add    r9,rdi
    movsd  xmm2,QWORD PTR [rsi+r9*8-0x8]
    movsd  xmm8,QWORD PTR [rsi+r13*8-0x8]
    mov    r8,QWORD PTR [rbp+r13*8-0x8]
    movsd  xmm10,QWORD PTR [r12+r8*8-0x8]
    mulsd  xmm10,xmm0
    movapd xmm6,xmm2
    andpd  xmm6,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    ucomisd xmm10,xmm6
    jae    at_1_082a
at_1_07fd:
    movapd xmm6,xmm10
    divsd  xmm6,xmm2
    movapd xmm12,xmm1
    mulsd  xmm12,xmm6
    divsd  xmm12,xmm8
    mulsd  xmm12,xmm6
    addsd  xmm12,xmm1
    ucomisd xmm12,xmm3
    {disp32} jbe    at_1_08c0
at_1_082a:
    movapd xmm12,xmm2
    divsd  xmm12,xmm10
    movapd xmm6,xmm8
    mulsd  xmm6,xmm12
    divsd  xmm6,xmm1
    mulsd  xmm12,xmm6
    addsd  xmm12,xmm1
    ucomisd xmm12,xmm3
    ja     at_1_07fd
    movapd xmm2,xmm1
    divsd  xmm2,xmm12
    movsd  QWORD PTR [rsi+r13*8-0x8],xmm2
    divsd  xmm8,xmm12
    mulsd  xmm10,xmm12
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm10
    cmp    rax,r13
    {disp32} jl     at_1_0913
    mov    r8,rdx
at_1_0880:
    add    r9,r8
    inc    r9
    movsd  xmm2,QWORD PTR [rsi+r9*8-0x8]
    movapd xmm10,xmm2
    xorpd  xmm10,xmm4
    movlpd QWORD PTR [r14+r8*8],xmm10
    lea    r10,[r8+0x1]
    mulsd  xmm2,xmm6
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm2
    mov    r8,r10
    cmp    r10,rax
    jl     at_1_0880
    jmp    at_1_0913
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_08c0:
    divsd  xmm8,xmm12
    movsd  QWORD PTR [rsi+r13*8-0x8],xmm8
    movapd xmm8,xmm1
    divsd  xmm8,xmm12
    mulsd  xmm2,xmm12
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm2
    cmp    rax,r13
    jl     at_1_0913
    xorpd  xmm6,xmm4
    mov    r8,rdx
    xchg   ax,ax
at_1_08f0:
    add    r9,r8
    inc    r9
    movsd  xmm2,QWORD PTR [rsi+r9*8-0x8]
    mulsd  xmm2,xmm6
    movsd  QWORD PTR [r14+r8*8],xmm2
    lea    r10,[r8+0x1]
    mov    r8,r10
    cmp    r10,rax
    jl     at_1_08f0
at_1_0913:
    cmp    r13,rax
    {disp32} je     at_1_0ba8
    {disp32} jge    at_1_0ba8
    mov    r12,rbp
    mov    rbp,r13
    mov    rbx,r15
    jmp    at_1_0946
    nop    DWORD PTR [rax]
at_1_0930:
    movapd xmm2,xmm8
at_1_0935:
    inc    rbp
    movapd xmm8,xmm2
    cmp    r11,rax
    {disp32} jge    at_1_07a0
at_1_0946:
    mov    r11,rbx
    movsd  xmm13,QWORD PTR [r14+rbx*8-0x10]
    ucomisd xmm5,xmm13
    setnp  r8b
    sete   r9b
    inc    rbx
    test   r9b,r8b
    jne    at_1_0930
    mov    r9,rbx
    imul   r9,r11
    shr    r9,1
    add    r9,rdi
    movsd  xmm12,QWORD PTR [rsi+r9*8-0x8]
    movsd  xmm2,QWORD PTR [rsi+r11*8-0x8]
    ucomisd xmm2,xmm7
    jae    at_1_09c6
    mulsd  xmm2,xmm9
    divsd  xmm12,xmm11
    mov    QWORD PTR [rsp+0x28],r9
    cmp    rax,r11
    jl     at_1_09c6
    mov    r8,rbp
    mov    r10,r9
at_1_09a0:
    add    r10,r8
    inc    r10
    inc    r8
    movsd  xmm6,QWORD PTR [rsi+r10*8-0x8]
    divsd  xmm6,xmm11
    movsd  QWORD PTR [rsi+r10*8-0x8],xmm6
    cmp    r8,rax
    jl     at_1_09a0
    mov    QWORD PTR [rsp+0x28],r10
at_1_09c6:
    movapd xmm6,xmm13
    andpd  xmm6,xmm15
    movapd xmm10,xmm12
    andpd  xmm10,xmm15
    ucomisd xmm6,xmm10
    ja     at_1_0a14
at_1_09e1:
    movapd xmm6,xmm13
    divsd  xmm6,xmm12
    movapd xmm10,xmm8
    mulsd  xmm10,xmm6
    divsd  xmm10,xmm2
    movapd xmm14,xmm6
    mulsd  xmm14,xmm10
    addsd  xmm14,xmm1
    ucomisd xmm14,xmm3
    {disp32} jbe    at_1_0b10
at_1_0a14:
    movapd xmm14,xmm12
    divsd  xmm14,xmm13
    movapd xmm10,xmm2
    mulsd  xmm10,xmm14
    divsd  xmm10,xmm8
    movapd xmm6,xmm10
    mulsd  xmm6,xmm14
    addsd  xmm6,xmm1
    ucomisd xmm6,xmm3
    ja     at_1_09e1
    divsd  xmm8,xmm6
    movsd  QWORD PTR [rsi+r11*8-0x8],xmm8
    divsd  xmm2,xmm6
    mulsd  xmm13,xmm6
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm13
    cmp    rax,r11
    jl     at_1_0ab5
    mov    r10,rbp
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0a70:
    add    r9,r10
    inc    r9
    movsd  xmm6,QWORD PTR [rsi+r9*8-0x8]
    movsd  xmm8,QWORD PTR [r14+r10*8]
    movapd xmm12,xmm10
    mulsd  xmm12,xmm6
    addsd  xmm12,xmm8
    mulsd  xmm8,xmm14
    subsd  xmm8,xmm6
    movsd  QWORD PTR [r14+r10*8],xmm8
    lea    r8,[r10+0x1]
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm12
    mov    r10,r8
    cmp    r8,rax
    jl     at_1_0a70
at_1_0ab5:
    ucomisd xmm2,xmm7
    {disp32} jae    at_1_0935
at_1_0abf:
    mulsd  xmm2,xmm9
    mov    QWORD PTR [rsp+0x28],r11
    cmp    rax,r11
    {disp32} jl     at_1_0935
    mov    r8,rbp
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0ae0:
    movsd  xmm6,QWORD PTR [r14+r8*8]
    divsd  xmm6,xmm11
    movsd  QWORD PTR [r14+r8*8],xmm6
    inc    r8
    cmp    r8,rax
    jl     at_1_0ae0
    mov    QWORD PTR [rsp+0x28],rcx
    {disp32} jmp    at_1_0935
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0b10:
    mulsd  xmm12,xmm14
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm12
    divsd  xmm2,xmm14
    movsd  QWORD PTR [rsi+r11*8-0x8],xmm2
    divsd  xmm8,xmm14
    cmp    rax,r11
    jge    at_1_0b46
    movapd xmm2,xmm8
    ucomisd xmm2,xmm7
    {disp32} jae    at_1_0935
    {disp32} jmp    at_1_0abf
at_1_0b46:
    mov    r10,rbp
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0b50:
    add    r9,r10
    inc    r9
    movsd  xmm2,QWORD PTR [rsi+r9*8-0x8]
    movsd  xmm12,QWORD PTR [r14+r10*8]
    movapd xmm13,xmm10
    mulsd  xmm13,xmm12
    addsd  xmm13,xmm2
    mulsd  xmm2,xmm6
    subsd  xmm12,xmm2
    movsd  QWORD PTR [r14+r10*8],xmm12
    lea    r8,[r10+0x1]
    movsd  QWORD PTR [rsi+r9*8-0x8],xmm13
    mov    r10,r8
    cmp    r8,rax
    jl     at_1_0b50
    movapd xmm2,xmm8
    ucomisd xmm2,xmm7
    {disp32} jae    at_1_0935
    {disp32} jmp    at_1_0abf
at_1_0ba8:
    mov    rbx,QWORD PTR [rsp+0x1d8]
    mov    rcx,rbx
    mov    r15,QWORD PTR [rsp+0x88]
    mov    rdx,r15
    mov    r8,QWORD PTR [rsp+0x50]
    mov    r9,r15
    call   ref_56_DL7ITV
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    movsd  xmm10,QWORD PTR [rsp+0x78]
    jle    at_1_0c38
    mov    rcx,QWORD PTR [rsp+0x20]
    mov    rdx,QWORD PTR [rsp+0x48]
    add    rcx,rdx
    lea    rdx,[rsi+rcx*8]
    add    rdx,0x20
    add    rcx,rax
    xor    r8d,r8d
    movapd xmm0,XMMWORD PTR [rip + ref_29_xmm_80000000000000008000000000000000]
    nop    DWORD PTR [rax]
at_1_0c00:
    mov    r9,QWORD PTR [rbp+r8*8+0x0]
    movsd  xmm1,QWORD PTR [rdx+r8*8]
    movapd xmm2,xmm1
    xorpd  xmm2,xmm0
    mulsd  xmm1,QWORD PTR [r12+r9*8-0x8]
    movlpd QWORD PTR [r14+r9*8-0x8],xmm2
    movsd  QWORD PTR [rdx+r8*8],xmm1
    inc    r8
    cmp    rax,r8
    jne    at_1_0c00
    add    rcx,0x4
    mov    QWORD PTR [rsp+0x28],rcx
at_1_0c38:
    mov    rcx,rbx
    mov    rdx,r15
    call   ref_53_DV2NRM
    movapd xmm7,xmm0
    movapd xmm8,xmm0
    subsd  xmm8,xmm10
    ucomisd xmm8,QWORD PTR [rsp+0x70]
    setae  al
    movsd  xmm0,QWORD PTR [rsp+0x40]
    ucomisd xmm0,xmm8
    movsd  xmm11,QWORD PTR [rsp+0x98]
    mov    r13,QWORD PTR [rsp+0x90]
    movapd xmm13,XMMWORD PTR [rsp+0xb0]
    jb     at_1_0c8c
    test   al,al
    {disp32} jne    at_1_0e02
at_1_0c8c:
    movsd  xmm0,QWORD PTR [rsp+0x80]
    ucomisd xmm0,xmm8
    setnp  al
    sete   cl
    test   cl,al
    movsd  xmm12,QWORD PTR [rsp+0x60]
    {disp32} jne    at_1_0dfb
    xorpd  xmm6,xmm6
    ucomisd xmm8,xmm6
    mov    r15,QWORD PTR [rsp+0x1d0]
    ja     at_1_0d03
    cmp    r13,QWORD PTR [rsp+0x38]
    {disp32} jge    at_1_0dfb
    movapd xmm9,xmm13
    mulsd  xmm9,xmm7
    mulsd  xmm9,xmm7
    mov    rcx,rbx
    mov    rdx,r14
    mov    r8,QWORD PTR [rsp+0x30]
    call   ref_52_DD7TPR
    subsd  xmm9,xmm0
    mulsd  xmm9,QWORD PTR [rsp+0x68]
    ucomisd xmm13,xmm9
    {disp32} jb     at_1_0e18
at_1_0d03:
    ucomisd xmm6,xmm8
    movapd xmm0,xmm13
    ja     at_1_0d14
    movapd xmm0,xmm12
at_1_0d14:
    movapd xmm9,xmm8
at_1_0d19:
    movapd xmm12,xmm0
at_1_0d1e:
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_0d7d
    mov    rcx,QWORD PTR [rsp+0x20]
    mov    rdx,QWORD PTR [rsp+0x48]
    add    rcx,rdx
    lea    rdx,[rsi+rcx*8]
    add    rdx,0x20
    add    rcx,rax
    xor    r8d,r8d
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0d50:
    mov    r9,QWORD PTR [rbp+r8*8+0x0]
    movsd  xmm0,QWORD PTR [rdx+r8*8]
    divsd  xmm0,xmm7
    mulsd  xmm0,QWORD PTR [r12+r9*8-0x8]
    movsd  QWORD PTR [r14+r8*8],xmm0
    inc    r8
    cmp    rax,r8
    jne    at_1_0d50
    add    rcx,0x4
    mov    QWORD PTR [rsp+0x28],rcx
at_1_0d7d:
    lea    r8,[rsi+rdi*8]
    mov    rcx,rbx
    mov    rdx,r14
    mov    r9,r14
    call   ref_57_DL7IVM
    mov    rax,QWORD PTR [rbx]
    test   rax,rax
    jle    at_1_0dc1
    xor    ecx,ecx
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0da0:
    movsd  xmm0,QWORD PTR [r14+rcx*8]
    movsd  xmm1,QWORD PTR [rsi+rcx*8]
    sqrtsd xmm1,xmm1
    divsd  xmm0,xmm1
    movsd  QWORD PTR [r14+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0da0
at_1_0dc1:
    mov    rcx,rbx
    mov    rdx,r14
    call   ref_53_DV2NRM
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    divsd  xmm1,xmm0
    mulsd  xmm9,xmm1
    mulsd  xmm9,xmm1
    divsd  xmm9,xmm10
    addsd  xmm13,xmm9
    maxsd  xmm11,xmm13
    movapd xmm6,xmm11
    {disp32} jmp    at_1_064d
at_1_0dfb:
    movapd xmm0,xmm13
    jmp    at_1_0e25
at_1_0e02:
    movapd xmm0,xmm13
    mov    rdi,QWORD PTR [rsp+0x1f8]
    movsd  xmm12,QWORD PTR [rsp+0x60]
    jmp    at_1_0e2d
at_1_0e18:
    movapd xmm0,XMMWORD PTR [rip + ref_29_xmm_80000000000000008000000000000000]
    xorpd  xmm0,xmm13
at_1_0e25:
    mov    rdi,QWORD PTR [rsp+0x1f8]
at_1_0e2d:
    movsd  QWORD PTR [rdi+0x20],xmm0
    mov    rcx,rbx
    mov    rdx,r14
    mov    r8,QWORD PTR [rsp+0x30]
    call   ref_52_DD7TPR
    xorpd  xmm1,xmm1
    minsd  xmm0,xmm1
    movsd  QWORD PTR [rdi+0x18],xmm0
    movapd xmm1,xmm7
    mulsd  xmm1,xmm7
    mulsd  xmm1,xmm13
    subsd  xmm1,xmm0
    mulsd  xmm1,QWORD PTR [rip + ref_20_real_3fe0000000000000]
    movsd  QWORD PTR [rdi+0x30],xmm1
at_1_0e6d:
    movsd  QWORD PTR [rdi+0x8],xmm7
    mov    rax,QWORD PTR [rsp+0x20]
    movsd  QWORD PTR [rsi+rax*8+0x18],xmm7
    movsd  QWORD PTR [rsi+rax*8],xmm11
    movsd  QWORD PTR [rsi+rax*8+0x10],xmm12
    movsd  QWORD PTR [rdi+0x40],xmm10
    movaps xmm6,XMMWORD PTR [rsp+0xc0]
    movaps xmm7,XMMWORD PTR [rsp+0xd0]
    movaps xmm8,XMMWORD PTR [rsp+0xe0]
    movaps xmm9,XMMWORD PTR [rsp+0xf0]
    movaps xmm10,XMMWORD PTR [rsp+0x100]
    movaps xmm11,XMMWORD PTR [rsp+0x110]
    movaps xmm12,XMMWORD PTR [rsp+0x120]
    movaps xmm13,XMMWORD PTR [rsp+0x130]
    movaps xmm14,XMMWORD PTR [rsp+0x140]
    movaps xmm15,XMMWORD PTR [rsp+0x150]
    add    rsp,0x168
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0efc:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_49_DL7MST_BIG:
at_3_0000:
    .zero 8
at_3_0008:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_4020000000000000:
at_5_0000:
    .quad 0x4020000000000000    # binary64 8.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_4008000000000000:
at_6_0000:
    .quad 0x4008000000000000    # binary64 3.0
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_7fffffffffffffff7fffffffffffffff:
at_7_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_3fe0000000000000:
at_8_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_3f50624dd2f1a9fc:
at_9_0000:
    .quad 0x3f50624dd2f1a9fc    # binary64 0.001
at_9_0008:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_24_rdata:
def_26_real_4004000000000000:
at_10_0000:
    .quad 0x4004000000000000    # binary64 2.5
at_10_0008:
end_s10:

# .rdata  (COFF section 11)
.section .s11,"dr"
def_27_rdata:
def_29_xmm_80000000000000008000000000000000:
at_11_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_11_0010:
end_s11:

# .rdata  (COFF section 12)
.section .s12,"dr"
def_30_rdata:
def_32_real_3f70000000000000:
at_12_0000:
    .quad 0x3f70000000000000    # binary64 0.00390625
at_12_0008:
end_s12:

# .rdata  (COFF section 13)
.section .s13,"dr"
def_33_rdata:
def_35_real_40f0000000000000:
at_13_0000:
    .quad 0x40f0000000000000    # binary64 65536.0
at_13_0008:
end_s13:

# .rdata  (COFF section 14)
.section .s14,"dr"
def_36_rdata:
def_38_real_4070000000000000:
at_14_0000:
    .quad 0x4070000000000000    # binary64 256.0
at_14_0008:
end_s14:

# .xdata  (COFF section 15)
.section .s15,"dr"
def_39_xdata:
at_15_0000:
    .byte 0x01    # version 1
    .byte at_1_0074 - at_1_0000    # prologue size
    .byte 0x1e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0074 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0c
    .byte 0x00
    .byte at_1_006b - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x0d
    .byte 0x00
    .byte at_1_0062 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x0e
    .byte 0x00
    .byte at_1_0058 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x0f
    .byte 0x00
    .byte at_1_004e - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x10
    .byte 0x00
    .byte at_1_0045 - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x11
    .byte 0x00
    .byte at_1_003b - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x12
    .byte 0x00
    .byte at_1_0031 - at_1_0000    # SAVE_XMM128
    .byte 0xd8
    .byte 0x13
    .byte 0x00
    .byte at_1_0027 - at_1_0000    # SAVE_XMM128
    .byte 0xe8
    .byte 0x14
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xf8
    .byte 0x15
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x2d
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_15_0040:
end_s15:

# .rdata  (COFF section 16)
.section .s16,"dr"
def_41_rdata:
def_50_unnamed_1:
at_16_0000:
    .quad 0x0000000000000006
at_16_0008:
end_s16:

# .drectve  (COFF section 17)
.section .s17,"dr"
def_43_drectve:
at_17_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_17_00b9:
end_s17:

# .pdata  (COFF section 18)
.section .s18,"dr"
def_45_pdata:
at_18_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0efc - def_0_text)    # image-relative end
    .long ref_39_xdata    # image-relative unwind info
at_18_000c:
end_s18:

# MEMBER dl7msb.obj
# Entry points: DL7MSB
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DL7MSB:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x168
at_1_0013:
    movaps XMMWORD PTR [rsp+0x150],xmm10
at_1_001c:
    movaps XMMWORD PTR [rsp+0x140],xmm9
at_1_0025:
    movaps XMMWORD PTR [rsp+0x130],xmm8
at_1_002e:
    movaps XMMWORD PTR [rsp+0x120],xmm7
at_1_0036:
    movaps XMMWORD PTR [rsp+0x110],xmm6
at_1_003e:
    mov    QWORD PTR [rsp+0xf8],r9
    mov    QWORD PTR [rsp+0xc0],r8
    mov    rsi,rdx
    mov    QWORD PTR [rsp+0xf0],rcx
    mov    r14,QWORD PTR [rsp+0x240]
    mov    rbx,QWORD PTR [rsp+0x230]
    mov    r12,QWORD PTR [rsp+0x228]
    mov    rcx,QWORD PTR [rsp+0x208]
    mov    rdi,QWORD PTR [rsp+0x200]
    mov    rdx,QWORD PTR [rsp+0x1e8]
    mov    r15,QWORD PTR [rsp+0x1d0]
    mov    rax,QWORD PTR [rsp+0x210]
    mov    rax,QWORD PTR [rax]
    mov    r13,rax
    mov    QWORD PTR [rsp+0xa0],rax
    mov    rbp,QWORD PTR [rdi]
    mov    rax,QWORD PTR [rdx]
    mov    QWORD PTR [rsp+0xb8],rax
    test   rax,rax
    js     at_1_00d3
    movsd  xmm7,QWORD PTR [r14+0x10]
    movsd  xmm6,QWORD PTR [r14+0x28]
    mov    rax,QWORD PTR [rcx]
    mov    QWORD PTR [rsp+0xb0],rax
    jmp    at_1_00f7
at_1_00d3:
    mov    QWORD PTR [rcx],0x0
    mov    QWORD PTR [rdx],0xffffffffffffffff
    mov    QWORD PTR [rsp+0xb8],0xffffffffffffffff
    xor    eax,eax
    mov    QWORD PTR [rsp+0xb0],rax
at_1_00f7:
    mov    rcx,rdi
    mov    rdx,QWORD PTR [rsp+0x258]
    mov    r8,QWORD PTR [rsp+0x260]
    call   ref_16_DV7CPY
    mov    rcx,rdi
    mov    rdx,rbx
    mov    r8,rsi
    call   ref_16_DV7CPY
    mov    rdx,rbp
    shl    rdx,0x4
    add    rdx,r12
    mov    rcx,rdi
    mov    QWORD PTR [rsp+0xd0],rdx
    mov    r8,QWORD PTR [rsp+0x218]
    call   ref_16_DV7CPY
    mov    rcx,rdi
    mov    rdx,r15
    mov    r8,rbx
    call   ref_17_DV7IPR
    movsd  xmm10,QWORD PTR [rip + ref_18_DL7MSB_ZERO]
    movsd  xmm8,QWORD PTR [r14+0x38]
    mov    QWORD PTR [rsp+0xd8],0xffffffffffffffff
    movsd  QWORD PTR [r14+0x8],xmm10
    test   r13,r13
    {disp32} jle    at_1_0654
    mov    r9,rsi
    mov    rcx,rdi
    mov    rdi,QWORD PTR [rsp+0x248]
    mov    rdx,QWORD PTR [rsp+0x238]
    mov    r15,QWORD PTR [rsp+0x1d8]
    shl    rbp,0x3
    cmp    QWORD PTR [rsp+0xb0],r13
    mov    rsi,0xffffffffffffffff
    cmove  rsi,QWORD PTR [rsp+0xb8]
    lea    rax,[rip + ref_19_unnamed_1]
    mov    QWORD PTR [rsp+0x20],rax
    mov    r8,QWORD PTR [rsp+0xc0]
    mov    QWORD PTR [rsp+0xe8],r9
    call   ref_20_DV7VMP
    mov    rcx,QWORD PTR [rsp+0x200]
    mov    rdx,QWORD PTR [rsp+0x1d0]
    mov    r8,QWORD PTR [rsp+0x238]
    call   ref_17_DV7IPR
    mov    QWORD PTR [rsp+0xe0],r13
    add    rbp,r12
    mov    QWORD PTR [rsp+0xb0],rbp
    movapd xmm9,xmm10
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0210:
    mov    QWORD PTR [rsp+0xa8],rsi
    movapd xmm0,xmm8
    subsd  xmm0,xmm10
    movsd  QWORD PTR [r14+0x38],xmm0
    lea    rax,[rip + ref_21_unnamed_2]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0xa0]
    mov    rdx,QWORD PTR [rsp+0x238]
    mov    r8,rdx
    mov    rbp,rbx
    mov    r9,rbx
    call   ref_20_DV7VMP
    mov    rax,QWORD PTR [rsp+0xa0]
    mov    QWORD PTR [rsp+0xc8],0x1
    test   rax,rax
    jle    at_1_028b
    xor    ecx,ecx
    nop    DWORD PTR [rax]
at_1_0270:
    lea    rdx,[rcx+0x1]
    mov    QWORD PTR [r15+rcx*8],rdx
    mov    rcx,rdx
    cmp    rdx,rax
    jl     at_1_0270
    inc    rax
    mov    QWORD PTR [rsp+0xc8],rax
at_1_028b:
    mov    r13,rdi
    mov    rsi,QWORD PTR [rsp+0xa8]
    test   rsi,rsi
    mov    eax,0x0
    cmovle rsi,rax
    mov    rax,QWORD PTR [rsp+0x250]
    mov    QWORD PTR [rsp+0x50],rax
    mov    QWORD PTR [rsp+0x48],r14
    mov    QWORD PTR [rsp+0x40],r12
    mov    rax,QWORD PTR [rsp+0x220]
    mov    QWORD PTR [rsp+0x38],rax
    mov    rax,QWORD PTR [rsp+0xd0]
    mov    QWORD PTR [rsp+0x30],rax
    lea    rdi,[rsp+0xa0]
    mov    QWORD PTR [rsp+0x28],rdi
    lea    rax,[rsp+0xa8]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rbx,rbp
    mov    rcx,rbp
    mov    r12,QWORD PTR [rsp+0x238]
    mov    rdx,r12
    mov    r8,QWORD PTR [rsp+0xf8]
    mov    r9,r15
    call   ref_22_DL7MST
    lea    rax,[rip + ref_19_unnamed_1]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rdi
    mov    rdx,r12
    mov    r8,r12
    mov    r9,rbp
    call   ref_20_DV7VMP
    mov    rax,r14
    mov    r14,QWORD PTR [rsp+0xa0]
    mov    rcx,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rcx],r14
    cmp    QWORD PTR [rsp+0xb8],0x0
    jns    at_1_0356
    movsd  xmm7,QWORD PTR [rax+0x10]
    movsd  xmm6,QWORD PTR [rax+0x28]
at_1_0356:
    mov    rdx,QWORD PTR [rsp+0xa8]
    mov    rcx,QWORD PTR [rsp+0x1e8]
    mov    QWORD PTR [rcx],rdx
    mov    r12,rax
    movsd  QWORD PTR [rax+0x38],xmm8
    mov    rax,rdx
    mov    QWORD PTR [rsp+0xb8],rdx
    cmp    rdx,rsi
    mov    rbx,QWORD PTR [rsp+0x218]
    mov    rdi,r13
    jg     at_1_03c1
    lea    rax,[rip + ref_19_unnamed_1]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0xa0]
    mov    rdx,QWORD PTR [rsp+0x1f0]
    mov    r8,rbp
    mov    r9,QWORD PTR [rsp+0x220]
    call   ref_23_DD7MLP
    mov    rax,QWORD PTR [rsp+0xa8]
at_1_03c1:
    cmp    rax,rsi
    mov    r13,QWORD PTR [rsp+0x1e0]
    jle    at_1_0402
    mov    rax,QWORD PTR [rsp+0x250]
    lea    r9,[rax+r14*8]
    add    r9,0x20
    lea    rax,[rip + ref_19_unnamed_1]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0xa0]
    mov    rdx,QWORD PTR [rsp+0x1f0]
    mov    r8,rbp
    call   ref_23_DD7MLP
at_1_0402:
    mov    rax,QWORD PTR [rsp+0x260]
    mov    QWORD PTR [rsp+0x90],rax
    mov    rax,QWORD PTR [rsp+0x258]
    mov    QWORD PTR [rsp+0x88],rax
    mov    QWORD PTR [rsp+0x80],rdi
    mov    rsi,r12
    mov    QWORD PTR [rsp+0x78],r12
    mov    rax,QWORD PTR [rsp+0x238]
    mov    QWORD PTR [rsp+0x70],rax
    mov    QWORD PTR [rsp+0x68],rbp
    mov    rax,QWORD PTR [rsp+0x228]
    mov    QWORD PTR [rsp+0x60],rax
    lea    rax,[rsp+0xa0]
    mov    QWORD PTR [rsp+0x58],rax
    mov    rax,QWORD PTR [rsp+0x200]
    mov    QWORD PTR [rsp+0x50],rax
    lea    rax,[rsp+0x108]
    mov    QWORD PTR [rsp+0x48],rax
    mov    rax,QWORD PTR [rsp+0x1f8]
    mov    QWORD PTR [rsp+0x40],rax
    mov    rax,QWORD PTR [rsp+0x1f0]
    mov    QWORD PTR [rsp+0x38],rax
    lea    rax,[rsp+0xd8]
    mov    QWORD PTR [rsp+0x30],rax
    mov    QWORD PTR [rsp+0x28],r13
    mov    QWORD PTR [rsp+0x20],r15
    mov    rcx,QWORD PTR [rsp+0xf0]
    mov    rdx,QWORD PTR [rsp+0xe8]
    mov    r8,QWORD PTR [rsp+0xb0]
    mov    r9,QWORD PTR [rsp+0x1d0]
    call   ref_24_DS7BQN
    addsd  xmm9,QWORD PTR [r12+0x30]
    cmp    QWORD PTR [rsp+0x108],0x0
    {disp32} je     at_1_05a0
    mov    rax,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rax],0x0
    mov    rcx,QWORD PTR [rsp+0xa0]
    lea    rax,[rcx+0x1]
    mov    rsi,QWORD PTR [rsp+0xe0]
    mov    QWORD PTR [rsp+0xa8],rax
    cmp    rsi,rcx
    {disp32} jle    at_1_05a0
    lea    r14,[rsi+rcx*1]
    inc    r14
    jmp    at_1_0544
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0530:
    lea    rcx,[rax+0x1]
    mov    QWORD PTR [rsp+0xa8],rcx
    cmp    rax,rsi
    mov    rax,rcx
    jge    at_1_05a0
at_1_0544:
    mov    rcx,r14
    sub    rcx,rax
    mov    QWORD PTR [rsp+0x100],rcx
    mov    rdx,QWORD PTR [r13+rcx*8-0x8]
    mov    QWORD PTR [rsp+0xc8],rdx
    cmp    rdx,rcx
    jge    at_1_0530
    mov    QWORD PTR [rsp+0x28],rdi
    mov    rax,QWORD PTR [rsp+0x220]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0xc8]
    lea    rdx,[rsp+0x100]
    lea    r8,[rip + ref_19_unnamed_1]
    mov    r9,rbx
    call   ref_25_DQ7RSH
    mov    rax,QWORD PTR [rsp+0xa8]
    jmp    at_1_0530
    nop
at_1_05a0:
    cmp    QWORD PTR [rsp+0xd8],0x0
    {disp32} jg     at_1_0632
    lea    rax,[rip + ref_19_unnamed_1]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r14,[rsp+0xe0]
    mov    rcx,r14
    mov    rdx,rdi
    mov    r8,QWORD PTR [rsp+0xb0]
    mov    rsi,rbx
    mov    rbx,rbp
    mov    r9,rbp
    call   ref_20_DV7VMP
    mov    rcx,r14
    mov    rdx,rdi
    mov    r8,QWORD PTR [rsp+0x1f0]
    mov    r9,rdi
    call   ref_26_DL7TVM
    mov    QWORD PTR [rsp+0x20],rsi
    mov    rcx,r14
    mov    rdx,QWORD PTR [rsp+0xd0]
    lea    r8,[rip + ref_27_DL7MSB_ONE]
    mov    r9,rdi
    call   ref_28_DV2AXY
    mov    r14,r12
    movsd  xmm10,QWORD PTR [r12+0x8]
    mov    rsi,0xffffffffffffffff
    mov    r12,QWORD PTR [rsp+0x228]
    {disp32} jmp    at_1_0210
at_1_0632:
    movapd xmm10,xmm7
    mov    rdx,QWORD PTR [rsp+0xc0]
    mov    r14,r12
    mov    r12,QWORD PTR [rsp+0x228]
    mov    rdi,QWORD PTR [rsp+0x200]
    jmp    at_1_0678
at_1_0654:
    lea    r8,[rip + ref_18_DL7MSB_ZERO]
    mov    rcx,rdi
    mov    rdx,r12
    call   ref_29_DV7SCP
    movapd xmm6,xmm10
    movapd xmm9,xmm10
    mov    rdx,QWORD PTR [rsp+0xc0]
at_1_0678:
    movsd  QWORD PTR [r14+0x10],xmm10
    movsd  QWORD PTR [r14+0x28],xmm6
    movsd  QWORD PTR [r14+0x30],xmm9
    mov    rcx,rdi
    mov    r8,r12
    call   ref_30_DD7TPR
    movsd  QWORD PTR [r14+0x18],xmm0
    movaps xmm6,XMMWORD PTR [rsp+0x110]
    movaps xmm7,XMMWORD PTR [rsp+0x120]
    movaps xmm8,XMMWORD PTR [rsp+0x130]
    movaps xmm9,XMMWORD PTR [rsp+0x140]
    movaps xmm10,XMMWORD PTR [rsp+0x150]
    add    rsp,0x168
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_06da:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_27_DL7MSB_ONE:
at_2_0000:
    .quad 0x3ff0000000000000
at_2_0008:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_18_DL7MSB_ZERO:
at_3_0000:
    .zero 8
at_3_0008:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_003e - at_1_0000    # prologue size
    .byte 0x14    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_003e - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x11
    .byte 0x00
    .byte at_1_0036 - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x12
    .byte 0x00
    .byte at_1_002e - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x13
    .byte 0x00
    .byte at_1_0025 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x14
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x15
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x2d
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_002c:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_21_unnamed_2:
at_5_0000:
    .quad 0x0000000000000001
def_19_unnamed_1:
at_5_0008:
    .quad 0xffffffffffffffff
at_5_0010:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_06da - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dl7ivm.obj
# Entry points: DL7IVM
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7IVM:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x28
at_1_0010:
    mov    r15,QWORD PTR [rcx]
    test   r15,r15
    {disp32} jle    at_1_00bd
    mov    rsi,r9
    mov    rdi,r8
    mov    rbx,rdx
    xor    eax,eax
    xorpd  xmm0,xmm0
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0030:
    movsd  xmm1,QWORD PTR [rsi+rax*8]
    ucomisd xmm0,xmm1
    setnp  cl
    sete   dl
    test   dl,cl
    je     at_1_0055
    mov    QWORD PTR [rbx+rax*8],0x0
    inc    rax
    cmp    rax,r15
    jl     at_1_0030
    jmp    at_1_00bd
at_1_0055:
    lea    r13,[rax+0x1]
    lea    r12,[rax+0x2]
    imul   r12,r13
    shr    r12,1
    divsd  xmm1,QWORD PTR [rdi+r12*8-0x8]
    movsd  QWORD PTR [rbx+rax*8],xmm1
    cmp    r13,r15
    jge    at_1_00bd
    lea    r14,[rsp+0x20]
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0080:
    lea    rbp,[r13+0x1]
    lea    rdx,[rdi+r12*8]
    mov    QWORD PTR [rsp+0x20],r13
    mov    rcx,r14
    mov    r8,rbx
    call   ref_14_DD7TPR
    add    r12,r13
    inc    r12
    movsd  xmm1,QWORD PTR [rsi+r13*8]
    subsd  xmm1,xmm0
    divsd  xmm1,QWORD PTR [rdi+r12*8-0x8]
    movsd  QWORD PTR [rbx+r13*8],xmm1
    mov    r13,rbp
    cmp    rbp,r15
    jl     at_1_0080
at_1_00bd:
    add    rsp,0x28
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_00ce:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0010 - at_1_0000    # prologue size
    .byte 0x09    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0x42
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_4_0018:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00ce - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dl7itv.obj
# Entry points: DL7ITV
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DL7ITV:
at_1_0000:
    push   r14
at_1_0002:
    push   rsi
at_1_0003:
    push   rdi
at_1_0004:
    push   rbp
at_1_0005:
    push   rbx
at_1_0006:
    sub    rsp,0x20
at_1_000a:
    mov    rsi,QWORD PTR [rcx]
    test   rsi,rsi
    {disp32} jle    at_1_0114
    lea    rdi,[rsi+0x1]
    cmp    rsi,0xc
    jbe    at_1_0044
    lea    rax,[rsi*8+0x0]
    mov    rcx,rdx
    mov    rbx,rdx
    mov    rdx,r9
    mov    r14,r8
    mov    r8,rax
    call   ref_14_intel_fast_memcpy
    mov    rdx,rbx
    mov    r8,r14
    jmp    at_1_0063
at_1_0044:
    xor    eax,eax
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0050:
    movsd  xmm0,QWORD PTR [r9+rax*8]
    movsd  QWORD PTR [rdx+rax*8],xmm0
    inc    rax
    cmp    rsi,rax
    jne    at_1_0050
at_1_0063:
    mov    rax,rdi
    imul   rax,rsi
    shr    rax,1
    lea    rcx,[rax*8+0x0]
    lea    r10,[rsi*8+0x0]
    sub    rcx,r10
    add    rcx,r8
    mov    r9d,0x8
    sub    r9,r10
    mov    r10d,0x1
    xorpd  xmm0,xmm0
    jmp    at_1_00b2
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_00a0:
    sub    rax,r11
    inc    r10
    add    rcx,r9
    add    r9,0x8
    cmp    r10,rsi
    jg     at_1_0114
at_1_00b2:
    mov    r11,rdi
    sub    r11,r10
    movsd  xmm1,QWORD PTR [rdx+r11*8-0x8]
    divsd  xmm1,QWORD PTR [r8+rax*8-0x8]
    movsd  QWORD PTR [rdx+r11*8-0x8],xmm1
    cmp    r10,rsi
    je     at_1_0114
    ucomisd xmm1,xmm0
    setnp  bl
    sete   bpl
    test   bpl,bl
    jne    at_1_00a0
    lea    rbx,[r11-0x1]
    xor    r14d,r14d
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_00f0:
    movsd  xmm2,QWORD PTR [rdx+r14*8]
    movsd  xmm3,QWORD PTR [rcx+r14*8]
    mulsd  xmm3,xmm1
    subsd  xmm2,xmm3
    movsd  QWORD PTR [rdx+r14*8],xmm2
    inc    r14
    cmp    r14,rbx
    jl     at_1_00f0
    jmp    at_1_00a0
at_1_0114:
    add    rsp,0x20
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r14
    ret
at_1_011f:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000a - at_1_0000    # prologue size
    .byte 0x06    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000a - at_1_0000    # ALLOC_SMALL
    .byte 0x32
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0005 - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
at_4_0010:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_011f - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER divset.obj
# Entry points: DIVSET
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DIVSET:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r12
at_1_0006:
    push   rsi
at_1_0007:
    push   rdi
at_1_0008:
    push   rbx
at_1_0009:
    sub    rsp,0x28
at_1_000d:
    mov    rdi,r9
    mov    rsi,rdx
    mov    rbx,rcx
    mov    r12,QWORD PTR [r8]
    cmp    r12,0x15
    jl     at_1_0044
    lea    rcx,[rip + ref_16_unnamed_1]
    call   ref_17_I7MDCN
    mov    QWORD PTR [rsi+0xa0],rax
    cmp    r12,0x33
    jb     at_1_0044
    mov    rbx,QWORD PTR [rbx]
    mov    QWORD PTR [rsi+0x190],rbx
    jmp    at_1_0047
at_1_0044:
    mov    rbx,QWORD PTR [rbx]
at_1_0047:
    lea    rax,[rbx-0x5]
    cmp    rax,0xfffffffffffffffb
    ja     at_1_005d
    mov    QWORD PTR [rsi],0x43
    {disp32} jmp    at_1_0224
at_1_005d:
    lea    rax,[rip + ref_18_DIVSET_MINIV]
    mov    r14,QWORD PTR [rax+rbx*8-0x8]
    lea    r15,[r14+0xa]
    cmp    r12,r15
    jge    at_1_007e
    mov    QWORD PTR [rsi],0xf
    {disp32} jmp    at_1_0224
at_1_007e:
    lea    rax,[rip + ref_19_DIVSET_MINV]
    mov    r12,QWORD PTR [rax+rbx*8-0x8]
    cmp    QWORD PTR [rdi],r12
    jge    at_1_009b
    mov    QWORD PTR [rsi],0x10
    {disp32} jmp    at_1_0224
at_1_009b:
    mov    r8,QWORD PTR [rsp+0x80]
    lea    rax,[rbx-0x1]
    lea    rcx,[rbx-0x3]
    cmp    rax,0x2
    cmovb  rcx,rax
    inc    rcx
    mov    QWORD PTR [rsp+0x20],rcx
    lea    rcx,[rsp+0x20]
    mov    rdx,rdi
    call   ref_20_DV7DFL
    mov    QWORD PTR [rsi],0xc
    cmp    rbx,0x3
    jb     at_1_00e0
    mov    QWORD PTR [rsi+0x320],0x1
at_1_00e0:
    xorps  xmm0,xmm0
    movups XMMWORD PTR [rsi+0x10],xmm0
    mov    QWORD PTR [rsi+0x158],r15
    mov    QWORD PTR [rsi+0x160],r12
    inc    r12
    mov    QWORD PTR [rsi+0x148],r12
    mov    QWORD PTR [rsi+0x80],0xc8
    mov    QWORD PTR [rsi+0x88],0x96
    mov    QWORD PTR [rsi+0x90],0x1
    mov    QWORD PTR [rsi+0x98],0x1
    add    r14,0xb
    mov    QWORD PTR [rsi+0x1c8],r14
    mov    QWORD PTR [rsi+0xa8],0x1
    mov    QWORD PTR [rsi+0xb0],0x1
    mov    QWORD PTR [rsi+0xb8],0x1
    cmp    QWORD PTR [rsp+0x20],0x2
    jl     at_1_01a2
    cmp    rbx,0x3
    mov    QWORD PTR [rsi+0x78],0x0
    mov    QWORD PTR [rsi+0xc0],0x1
    movups XMMWORD PTR [rsi+0x198],xmm0
    mov    QWORD PTR [rsi+0x188],0x19
    mov    eax,0x3d
    mov    ecx,0x2f
    cmovae rcx,rax
    mov    QWORD PTR [rsi+0x180],rcx
    {disp32} jmp    at_1_0224
at_1_01a2:
    xor    eax,eax
    cmp    rbx,0x3
    setae  al
    mov    QWORD PTR [rsi+0x68],0x3
    mov    QWORD PTR [rsi+0x70],0x1
    mov    QWORD PTR [rsi+0x78],0x1
    mov    QWORD PTR [rsi+0x230],0x0
    movups XMMWORD PTR [rsi+0x250],xmm0
    mov    QWORD PTR [rsi+0xc0],0x0
    mov    QWORD PTR [rsi+0x188],0x20
    lea    rcx,[rax+rax*2+0x3a]
    mov    QWORD PTR [rsi+0x1d8],rcx
    lea    rax,[rax+rax*2+0x43]
    mov    QWORD PTR [rsi+0x180],rax
    mov    QWORD PTR [rsi+0x278],0x1
    mov    QWORD PTR [rsi+0x1c0],0x3
    mov    QWORD PTR [rsi+0x268],0x0
at_1_0224:
    add    rsp,0x28
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r12
    pop    r14
    pop    r15
    ret
at_1_0232:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_000d - at_1_0000    # prologue size
    .byte 0x07    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000d - at_1_0000    # ALLOC_SMALL
    .byte 0x42
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0007 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_4_0014:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_19_DIVSET_MINV:
at_5_0000:
    .quad 0x0000000000000062
    .quad 0x0000000000000047
    .quad 0x0000000000000065
    .quad 0x0000000000000055
def_18_DIVSET_MINIV:
at_5_0020:
    .quad 0x0000000000000052
    .quad 0x000000000000003b
    .quad 0x0000000000000067
    .quad 0x0000000000000067
def_16_unnamed_1:
at_5_0040:
    .quad 0x0000000000000001
at_5_0048:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0232 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER ditsum.obj
# Entry points: DITSUM
.intel_syntax noprefix
# Iteration reporting uses Intel formatted internal writes followed by WRITELINES.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_18_DITSUM:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x928
at_1_0013:
    movapd XMMWORD PTR [rsp+0x910],xmm9
at_1_001d:
    movapd XMMWORD PTR [rsp+0x900],xmm8
at_1_0027:
    movapd XMMWORD PTR [rsp+0x8f0],xmm7
at_1_0030:
    movapd XMMWORD PTR [rsp+0x8e0],xmm6
at_1_0039:
    mov    QWORD PTR [rsp+0x38],r9
    mov    QWORD PTR [rsp+0x1e8],rdx
    mov    QWORD PTR [rsp+0x1d8],rcx
    mov    rax,QWORD PTR [r8+0xa0]
    mov    QWORD PTR [rsp+0x30],rax
    test   rax,rax
    {disp32} je     at_1_0130
    mov    rbp,r8
    mov    rax,QWORD PTR [r8]
    lea    r14,[rax-0x33]
    cmp    rax,0x3f
    cmovl  r14,rax
    lea    rcx,[r14-0x10]
    cmp    rcx,0xfffffffffffffff1
    {disp32} ja     at_1_0166
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xfa],0x10b0638
    mov    WORD PTR [rsp+0xfe],0x1
    mov    QWORD PTR [rsp+0x660],0x1e0
    lea    rcx,[rsp+0x700]
    mov    QWORD PTR [rsp+0x668],rcx
    mov    QWORD PTR [rsp+0x670],0x50
    mov    QWORD PTR [rsp+0x678],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_02e0 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xfa]
    lea    r9,[rsp+0x660]
    call   ref_20_for_write_int_fmt
at_1_0101:
    mov    rbx,QWORD PTR [rsp+0x38]
at_1_0106:
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    rdx,[rsp+0x700]
    lea    r8,[rsp+0x30]
    mov    r9,rbp
    call   ref_22_WRITELINES
at_1_0130:
    movaps xmm6,XMMWORD PTR [rsp+0x8e0]
    movaps xmm7,XMMWORD PTR [rsp+0x8f0]
    movaps xmm8,XMMWORD PTR [rsp+0x900]
    movaps xmm9,XMMWORD PTR [rsp+0x910]
    add    rsp,0x928
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0166:
    mov    rdi,QWORD PTR [rsp+0x9a0]
    mov    rsi,QWORD PTR [rsp+0x998]
    mov    r15,QWORD PTR [rbp+0x90]
    mov    rax,QWORD PTR [rbp+0x190]
    lea    r12,[rax-0x1]
    mov    rcx,r12
    shr    rcx,0x3f
    add    rax,rcx
    dec    rax
    and    rax,0xfffffffffffffffe
    sub    r12,rax
    lea    r8,[r12+0x1]
    cmp    r14,0xb
    {disp32} jbe    at_1_0253
at_1_01ab:
    mov    rax,QWORD PTR [rbp+0xb0]
    cmp    rax,0xffffffffffffffff
    {disp32} je     at_1_0df1
    add    rax,r14
    {disp32} js     at_1_0df1
    movabs rdx,0x801208384ff00
    mov    QWORD PTR [rsp+0x40],0x0
    lea    eax,[r14-0x4]
    cmp    eax,0xb
    {disp32} ja     at_1_1159
    lea    rcx,[rip + ref_9_rdata]
    movsxd rax,DWORD PTR [rcx+rax*4]
    add    rax,rcx
    mov    rbx,QWORD PTR [rsp+0x38]
    jmp    rax
at_1_01fa:
    mov    DWORD PTR [rsp+0x128],0x10638
    mov    QWORD PTR [rsp+0x4d0],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x4d8],rax
    mov    QWORD PTR [rsp+0x4e0],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0534 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x128]
    lea    r9,[rsp+0x4d0]
    {disp32} jmp    at_1_0b94
at_1_0253:
    mov    rax,QWORD PTR [rbp+0xf0]
    cmp    r14,0x2
    {disp32} jne    at_1_0669
    test   rax,rax
    {disp32} jne    at_1_0669
at_1_026d:
    mov    QWORD PTR [rsp+0x78],r14
    mov    QWORD PTR [rsp+0x80],r15
    mov    QWORD PTR [rsp+0x70],r8
    mov    QWORD PTR [rsp+0x1e0],r12
    cmp    QWORD PTR [rbp+0xb8],0x0
    mov    r14,rbp
    mov    rdi,QWORD PTR [rsp+0x38]
    mov    rbx,QWORD PTR [rsp+0x9a8]
    {disp32} je     at_1_0465
    movabs rdx,0x801208384ff00
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xf6],0x10638
    mov    QWORD PTR [rsp+0x3c8],0x1e0
    lea    r15,[rsp+0x700]
    mov    QWORD PTR [rsp+0x3d0],r15
    mov    QWORD PTR [rsp+0x3d8],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_02a0 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0xf6]
    lea    r9,[rsp+0x3c8]
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],rdi
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_23_unnamed_2]
    lea    r8,[rsp+0x30]
    mov    rdx,r15
    mov    r9,r14
    call   ref_22_WRITELINES
    mov    r12,QWORD PTR [rsi]
    test   r12,r12
    {disp32} jle    at_1_0465
    xor    r13d,r13d
    lea    rsi,[rsp+0x40]
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0350:
    lea    rbp,[r13+0x1]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xf0],0x10b0638
    mov    WORD PTR [rsp+0xf4],0x2
    mov    QWORD PTR [rsp+0x640],0x1e0
    mov    QWORD PTR [rsp+0x648],r15
    mov    QWORD PTR [rsp+0x650],0x50
    mov    QWORD PTR [rsp+0x658],rbp
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_025c - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rsi
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0xf0]
    lea    r9,[rsp+0x640]
    call   ref_20_for_write_int_fmt
    movsd  xmm0,QWORD PTR [rbx+r13*8]
    mov    DWORD PTR [rsp+0xec],0x20130
    movsd  QWORD PTR [rsp+0x250],xmm0
    mov    rcx,rsi
    lea    rdx,[rsp+0xec]
    lea    r8,[rsp+0x250]
    call   ref_24_for_write_int_fmt_xmit
    mov    rax,QWORD PTR [rsp+0x1d8]
    movsd  xmm0,QWORD PTR [rax+r13*8]
    mov    DWORD PTR [rsp+0xe8],0x10130
    movsd  QWORD PTR [rsp+0x248],xmm0
    mov    rcx,rsi
    lea    rdx,[rsp+0xe8]
    lea    r8,[rsp+0x248]
    call   ref_24_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],rdi
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_25_unnamed_3]
    mov    rdx,r15
    lea    r8,[rsp+0x30]
    mov    r9,r14
    call   ref_22_WRITELINES
    mov    r13,rbp
    cmp    rbp,r12
    {disp32} jl     at_1_0350
at_1_0465:
    mov    rax,QWORD PTR [rsp+0x9a0]
    mov    QWORD PTR [rax+0x8],0x0
    mov    QWORD PTR [rax+0x50],0x0
    xorps  xmm0,xmm0
    movups XMMWORD PTR [rax+0x28],xmm0
    mov    QWORD PTR [rax+0x80],0x0
    cmp    QWORD PTR [rsp+0x78],0xb
    mov    r12,QWORD PTR [rsp+0x1e0]
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    rax,QWORD PTR [rsp+0x80]
    {disp32} ja     at_1_0130
    mov    QWORD PTR [r14+0x118],0x0
    mov    QWORD PTR [r14+0x130],0x0
    test   rax,rax
    {disp32} je     at_1_0130
    movabs rbx,0x801208384ff00
    {disp32} jns    at_1_07bc
    test   r12,r12
    {disp32} jne    at_1_07bc
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xe4],0x10638
    mov    QWORD PTR [rsp+0x3b0],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x3b8],rsi
    mov    QWORD PTR [rsp+0x3c0],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0890 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0xe4]
    lea    r9,[rsp+0x3b0]
    mov    rdx,rbx
    call   ref_20_for_write_int_fmt
    mov    r15,QWORD PTR [rsp+0x38]
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    r9,r14
    call   ref_22_WRITELINES
    xor    ebp,ebp
at_1_0579:
    mov    rax,QWORD PTR [r14+0x28]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xd2],0x10b0638
    mov    WORD PTR [rsp+0xd6],0x2
    mov    QWORD PTR [rsp+0x620],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x628],rsi
    mov    QWORD PTR [rsp+0x630],0x50
    mov    QWORD PTR [rsp+0x638],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0220 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rdi,[rsp+0x40]
    lea    r8,[rsp+0xd2]
    lea    r9,[rsp+0x620]
    mov    rcx,rdi
    mov    rdx,rbx
    call   ref_20_for_write_int_fmt
    mov    rax,QWORD PTR [rsp+0x9a0]
    movsd  xmm0,QWORD PTR [rax+0x48]
    mov    DWORD PTR [rsp+0xce],0x10130
    movsd  QWORD PTR [rsp+0x240],xmm0
    lea    rdx,[rsp+0xce]
    lea    r8,[rsp+0x240]
    mov    rcx,rdi
    mov    rdi,rax
    call   ref_24_for_write_int_fmt_xmit
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    r9,r14
    call   ref_22_WRITELINES
    test   bpl,bpl
    mov    rbp,r14
    {disp32} je     at_1_0130
    {disp32} jmp    at_1_132a
at_1_0669:
    test   r15,r15
    {disp32} je     at_1_1f20
    mov    rcx,QWORD PTR [rbp+0x130]
    cmp    r14,0xa
    jb     at_1_0688
    test   rcx,rcx
    {disp32} je     at_1_01ab
at_1_0688:
    cmp    r14,0x2
    ja     at_1_06ab
    inc    rcx
    mov    QWORD PTR [rbp+0x130],rcx
    mov    rdx,r15
    neg    rdx
    cmovs  rdx,r15
    cmp    rcx,rdx
    {disp32} jl     at_1_0130
at_1_06ab:
    mov    rcx,QWORD PTR [rbp+0x198]
    mov    rbx,rcx
    neg    rbx
    cmovns rbx,rcx
    movsd  xmm0,QWORD PTR [rdi+0x48]
    movsd  xmm9,QWORD PTR [rdi+0x60]
    movapd xmm1,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm9,xmm1
    andpd  xmm0,xmm1
    xorpd  xmm7,xmm7
    add    rbx,QWORD PTR [rbp+0x28]
    mov    QWORD PTR [rbp+0x130],0x0
    maxsd  xmm9,xmm0
    xorpd  xmm6,xmm6
    ucomisd xmm6,xmm9
    jae    at_1_070f
    movsd  xmm6,QWORD PTR [rdi+0x30]
    movsd  xmm7,QWORD PTR [rdi+0x50]
    divsd  xmm7,xmm9
    divsd  xmm6,xmm9
at_1_070f:
    mov    rcx,QWORD PTR [rbp+0x118]
    mov    rdx,rcx
    xor    rdx,0x1
    or     rdx,r12
    sete   sil
    mov    QWORD PTR [rsp+0x80],r15
    test   r15,r15
    mov    r15,QWORD PTR [rsp+0x38]
    mov    QWORD PTR [rsp+0x70],r8
    {disp32} jle    at_1_13de
    movabs r15,0x801208384ff00
    test   sil,sil
    mov    QWORD PTR [rsp+0x78],r14
    {disp32} je     at_1_16e5
    mov    r14,rdi
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x188],0x10638
    mov    QWORD PTR [rsp+0x548],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x550],rax
    mov    QWORD PTR [rsp+0x558],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0738 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x188]
    lea    r9,[rsp+0x548]
    {disp32} jmp    at_1_1760
at_1_07bc:
    cmp    rcx,0x2
    sete   bpl
    test   rax,rax
    mov    r15,QWORD PTR [rsp+0x38]
    {disp32} jns    at_1_11bf
    cmp    rcx,0x2
    {disp32} jne    at_1_11bf
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xe0],0x10638
    mov    QWORD PTR [rsp+0x398],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x3a0],rsi
    mov    QWORD PTR [rsp+0x3a8],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0800 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0xe0]
    lea    r9,[rsp+0x398]
    mov    rdx,rbx
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    rbp,r14
    mov    r9,r14
    call   ref_22_WRITELINES
    mov    rdi,QWORD PTR [rsp+0x9a0]
    {disp32} jmp    at_1_132a
at_1_0876:
    mov    DWORD PTR [rsp+0x8c],0x10638
    mov    QWORD PTR [rsp+0x338],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x340],rax
    mov    QWORD PTR [rsp+0x348],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x8c]
    lea    r9,[rsp+0x338]
    {disp32} jmp    at_1_097c
at_1_08cf:
    mov    DWORD PTR [rsp+0x118],0x10638
    mov    QWORD PTR [rsp+0x470],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x478],rax
    mov    QWORD PTR [rsp+0x480],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0450 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x118]
    lea    r9,[rsp+0x470]
    {disp32} jmp    at_1_0b94
at_1_0928:
    mov    DWORD PTR [rsp+0x104],0x10638
    mov    QWORD PTR [rsp+0x3f8],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x400],rax
    mov    QWORD PTR [rsp+0x408],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0354 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x104]
    lea    r9,[rsp+0x3f8]
at_1_097c:
    call   ref_20_for_write_int_fmt
    {disp32} jmp    at_1_0106
at_1_0986:
    mov    DWORD PTR [rsp+0x120],0x10638
    mov    QWORD PTR [rsp+0x4a0],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x4a8],rax
    mov    QWORD PTR [rsp+0x4b0],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_04b4 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x120]
    lea    r9,[rsp+0x4a0]
    {disp32} jmp    at_1_0b94
at_1_09df:
    mov    DWORD PTR [rsp+0x11c],0x10638
    mov    QWORD PTR [rsp+0x488],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x490],rax
    mov    QWORD PTR [rsp+0x498],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0480 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x11c]
    lea    r9,[rsp+0x488]
    {disp32} jmp    at_1_0b94
at_1_0a38:
    mov    DWORD PTR [rsp+0x10c],0x10638
    mov    QWORD PTR [rsp+0x428],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x430],rax
    mov    QWORD PTR [rsp+0x438],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_03c8 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x10c]
    lea    r9,[rsp+0x428]
    {disp32} jmp    at_1_0b94
at_1_0a91:
    mov    DWORD PTR [rsp+0x124],0x10638
    mov    QWORD PTR [rsp+0x4b8],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x4c0],rax
    mov    QWORD PTR [rsp+0x4c8],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_04f0 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x124]
    lea    r9,[rsp+0x4b8]
    {disp32} jmp    at_1_0b94
at_1_0aea:
    mov    DWORD PTR [rsp+0x114],0x10638
    mov    QWORD PTR [rsp+0x458],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x460],rax
    mov    QWORD PTR [rsp+0x468],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0418 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x114]
    lea    r9,[rsp+0x458]
    jmp    at_1_0b94
at_1_0b40:
    mov    DWORD PTR [rsp+0x110],0x10638
    mov    QWORD PTR [rsp+0x440],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x448],rax
    mov    QWORD PTR [rsp+0x450],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_03ec - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x110]
    lea    r9,[rsp+0x440]
at_1_0b94:
    mov    r13,rdx
    call   ref_20_for_write_int_fmt
at_1_0b9c:
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r12,[rsp+0x700]
    lea    r8,[rsp+0x30]
    mov    rdx,r12
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    QWORD PTR [rbp+0x118],0x1
    cmp    QWORD PTR [rbp+0xb0],0x0
    {disp32} jle    at_1_0df1
    movsd  xmm1,QWORD PTR [rdi+0x48]
    movsd  xmm0,QWORD PTR [rdi+0x60]
    movapd xmm2,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm0,xmm2
    andpd  xmm1,xmm2
    maxsd  xmm0,xmm1
    xorpd  xmm6,xmm6
    ucomisd xmm6,xmm0
    xorpd  xmm7,xmm7
    jae    at_1_0c20
    movsd  xmm6,QWORD PTR [rdi+0x28]
    movsd  xmm7,QWORD PTR [rdi+0x30]
    divsd  xmm7,xmm0
    divsd  xmm6,xmm0
at_1_0c20:
    mov    r14,QWORD PTR [rbp+0x28]
    mov    rbx,QWORD PTR [rbp+0xe8]
    sub    r14,QWORD PTR [rbp+0x198]
    sub    rbx,QWORD PTR [rbp+0x1a0]
    mov    rax,QWORD PTR [rsi]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xbe],0x10b0638
    mov    WORD PTR [rsp+0xc2],0x2
    mov    QWORD PTR [rsp+0x5e0],0x1e0
    mov    QWORD PTR [rsp+0x5e8],r12
    mov    QWORD PTR [rsp+0x5f0],0x50
    mov    QWORD PTR [rsp+0x5f8],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_00f0 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    mov    r15,rsi
    lea    rsi,[rsp+0x40]
    lea    r8,[rsp+0xbe]
    lea    r9,[rsp+0x5e0]
    mov    rcx,rsi
    mov    rdx,r13
    call   ref_20_for_write_int_fmt
    movsd  xmm0,QWORD PTR [rdi+0x48]
    mov    DWORD PTR [rsp+0xba],0x20130
    movsd  QWORD PTR [rsp+0x230],xmm0
    lea    rdx,[rsp+0xba]
    lea    r8,[rsp+0x230]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [rdi+0x80]
    mov    DWORD PTR [rsp+0xb6],0x20130
    movsd  QWORD PTR [rsp+0x228],xmm0
    lea    rdx,[rsp+0xb6]
    lea    r8,[rsp+0x228]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0xb2],0x2010b
    mov    QWORD PTR [rsp+0x220],r14
    lea    rdx,[rsp+0xb2]
    lea    r8,[rsp+0x220]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0xae],0x2010b
    mov    QWORD PTR [rsp+0x218],rbx
    lea    rdx,[rsp+0xae]
    lea    r8,[rsp+0x218]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0xaa],0x20130
    movsd  QWORD PTR [rsp+0x210],xmm7
    lea    rdx,[rsp+0xaa]
    lea    r8,[rsp+0x210]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0xa6],0x10130
    movsd  QWORD PTR [rsp+0x208],xmm6
    lea    rdx,[rsp+0xa6]
    lea    r8,[rsp+0x208]
    mov    rcx,rsi
    mov    rsi,r15
    call   ref_24_for_write_int_fmt_xmit
    mov    rax,QWORD PTR [rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_26_unnamed_4]
    lea    r8,[rsp+0x30]
    mov    rdx,r12
    mov    r9,rbp
    call   ref_22_WRITELINES
at_1_0df1:
    cmp    QWORD PTR [rbp+0xa8],0x0
    mov    rdi,QWORD PTR [rsp+0x9a8]
    {disp32} je     at_1_0130
    mov    QWORD PTR [rbp+0x118],0x1
    cmp    QWORD PTR [rbp+0x190],0x2
    {disp32} jg     at_1_0130
    movabs rdx,0x801208384ff00
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xa2],0x10638
    mov    QWORD PTR [rsp+0x350],0x1e0
    lea    r12,[rsp+0x700]
    mov    QWORD PTR [rsp+0x358],r12
    mov    QWORD PTR [rsp+0x360],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_009c - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0xa2]
    lea    r9,[rsp+0x350]
    call   ref_20_for_write_int_fmt
    mov    rax,QWORD PTR [rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_23_unnamed_2]
    lea    r8,[rsp+0x30]
    mov    rdx,r12
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    rsi,QWORD PTR [rsi]
    test   rsi,rsi
    {disp32} jle    at_1_0130
    xor    r15d,r15d
    lea    r13,[rsp+0x40]
    lea    rbx,[rsp+0x30]
    nop
at_1_0ed0:
    mov    r14,rbp
    lea    rbp,[r15+0x1]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x9c],0x10b0638
    mov    WORD PTR [rsp+0xa0],0x2
    mov    QWORD PTR [rsp+0x5c0],0x1e0
    mov    QWORD PTR [rsp+0x5c8],r12
    mov    QWORD PTR [rsp+0x5d0],0x50
    mov    QWORD PTR [rsp+0x5d8],rbp
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0058 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,r13
    movabs rdx,0x801208384ff00
    lea    r8,[rsp+0x9c]
    lea    r9,[rsp+0x5c0]
    call   ref_20_for_write_int_fmt
    movsd  xmm0,QWORD PTR [rdi+r15*8]
    mov    DWORD PTR [rsp+0x98],0x20130
    movsd  QWORD PTR [rsp+0x200],xmm0
    mov    rcx,r13
    lea    rdx,[rsp+0x98]
    lea    r8,[rsp+0x200]
    call   ref_24_for_write_int_fmt_xmit
    mov    rax,QWORD PTR [rsp+0x1d8]
    movsd  xmm0,QWORD PTR [rax+r15*8]
    mov    DWORD PTR [rsp+0x94],0x20130
    movsd  QWORD PTR [rsp+0x1f8],xmm0
    mov    rcx,r13
    lea    rdx,[rsp+0x94]
    lea    r8,[rsp+0x1f8]
    call   ref_24_for_write_int_fmt_xmit
    mov    rax,QWORD PTR [rsp+0x1e8]
    movsd  xmm0,QWORD PTR [rax+r15*8]
    mov    DWORD PTR [rsp+0x90],0x10130
    movsd  QWORD PTR [rsp+0x1f0],xmm0
    mov    rcx,r13
    lea    rdx,[rsp+0x90]
    lea    r8,[rsp+0x1f0]
    call   ref_24_for_write_int_fmt_xmit
    mov    rax,QWORD PTR [rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_25_unnamed_3]
    mov    rdx,r12
    mov    r8,rbx
    mov    r9,r14
    call   ref_22_WRITELINES
    mov    r15,rbp
    cmp    rbp,rsi
    mov    rbp,r14
    {disp32} jl     at_1_0ed0
    {disp32} jmp    at_1_0130
at_1_102d:
    mov    DWORD PTR [rsp+0x100],0x10638
    mov    QWORD PTR [rsp+0x3e0],0x1e0
    lea    r13,[rsp+0x700]
    mov    QWORD PTR [rsp+0x3e8],r13
    mov    QWORD PTR [rsp+0x3f0],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0318 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    mov    rdi,r14
    mov    r14,r8
    lea    r8,[rsp+0x100]
    lea    r9,[rsp+0x3e0]
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,r13
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    r8,r14
    mov    r14,rdi
    cmp    QWORD PTR [rbp+0xf0],0x0
    {disp32} jg     at_1_0df1
    {disp32} jmp    at_1_026d
at_1_10ca:
    mov    DWORD PTR [rsp+0x108],0x10638
    mov    QWORD PTR [rsp+0x410],0x1e0
    lea    r13,[rsp+0x700]
    mov    QWORD PTR [rsp+0x418],r13
    mov    QWORD PTR [rsp+0x420],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_038c - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    mov    rdi,r14
    mov    r14,r8
    lea    r8,[rsp+0x108]
    lea    r9,[rsp+0x410]
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],rbx
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,r13
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    r8,r14
    mov    r14,rdi
    {disp32} jmp    at_1_026d
at_1_1159:
    mov    DWORD PTR [rsp+0x12c],0x10638
    mov    QWORD PTR [rsp+0x4e8],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x4f0],rax
    mov    QWORD PTR [rsp+0x4f8],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0570 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x12c]
    lea    r9,[rsp+0x4e8]
    mov    r13,rdx
    call   ref_20_for_write_int_fmt
    mov    rbx,QWORD PTR [rsp+0x38]
    {disp32} jmp    at_1_0b9c
at_1_11bf:
    cmp    QWORD PTR [rsp+0x80],0x0
    setg   al
    {disp32} jle    at_1_126b
    test   r12,r12
    {disp32} jne    at_1_126b
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xdc],0x10638
    mov    QWORD PTR [rsp+0x380],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x388],rsi
    mov    QWORD PTR [rsp+0x390],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0738 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0xdc]
    lea    r9,[rsp+0x380]
    mov    rdx,rbx
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    r9,r14
    call   ref_22_WRITELINES
    mov    rcx,QWORD PTR [rsp+0x70]
    mov    al,0x1
at_1_126b:
    test   al,al
    {disp32} je     at_1_130c
    cmp    rcx,0x2
    {disp32} jne    at_1_130c
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xd8],0x10638
    mov    QWORD PTR [rsp+0x368],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x370],rsi
    mov    QWORD PTR [rsp+0x378],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0678 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0xd8]
    lea    r9,[rsp+0x368]
    mov    rdx,rbx
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    r9,r14
    call   ref_22_WRITELINES
    mov    rcx,QWORD PTR [rsp+0x70]
at_1_130c:
    test   r12,r12
    {disp32} je     at_1_0579
    cmp    rcx,0x2
    mov    rbp,r14
    mov    rdi,QWORD PTR [rsp+0x9a0]
    {disp32} jne    at_1_0130
at_1_132a:
    mov    rax,QWORD PTR [rbp+0x28]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0xc8],0x10b0638
    mov    WORD PTR [rsp+0xcc],0x2
    mov    QWORD PTR [rsp+0x600],0x1e0
    lea    rcx,[rsp+0x700]
    mov    QWORD PTR [rsp+0x608],rcx
    mov    QWORD PTR [rsp+0x610],0x50
    mov    QWORD PTR [rsp+0x618],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_01e4 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rsi,[rsp+0x40]
    lea    r8,[rsp+0xc8]
    lea    r9,[rsp+0x600]
    mov    rcx,rsi
    mov    rdx,rbx
    call   ref_20_for_write_int_fmt
    movsd  xmm0,QWORD PTR [rdi+0x48]
    mov    DWORD PTR [rsp+0xc4],0x10130
    movsd  QWORD PTR [rsp+0x238],xmm0
    lea    rdx,[rsp+0xc4]
    lea    r8,[rsp+0x238]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    {disp32} jmp    at_1_0101
at_1_13de:
    movabs r13,0x801208384ff00
    test   sil,sil
    {disp32} je     at_1_1c87
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x1d4],0x10638
    mov    QWORD PTR [rsp+0x5a8],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x5b0],rsi
    mov    QWORD PTR [rsp+0x5b8],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0890 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x1d4]
    lea    r9,[rsp+0x5a8]
    mov    rdx,r13
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    QWORD PTR [rbp+0x118],0x0
    mov    rax,QWORD PTR [rbp+0xf0]
at_1_148d:
    mov    rsi,QWORD PTR [rbp+0x1f8]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x1ca],0x10b0638
    mov    WORD PTR [rsp+0x1ce],0x2
    mov    QWORD PTR [rsp+0x6e0],0x1e0
    lea    rcx,[rsp+0x700]
    mov    QWORD PTR [rsp+0x6e8],rcx
    mov    QWORD PTR [rsp+0x6f0],0x50
    mov    QWORD PTR [rsp+0x6f8],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_05f8 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    mov    r15,r14
    mov    r14,rdi
    mov    rdi,r12
    lea    r12,[rsp+0x40]
    lea    r8,[rsp+0x1ca]
    lea    r9,[rsp+0x6e0]
    mov    rcx,r12
    mov    rdx,r13
    call   ref_20_for_write_int_fmt
    mov    DWORD PTR [rsp+0x1c6],0x2010b
    mov    QWORD PTR [rsp+0x330],rbx
    lea    rdx,[rsp+0x1c6]
    lea    r8,[rsp+0x330]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x48]
    mov    DWORD PTR [rsp+0x1c2],0x20130
    movsd  QWORD PTR [rsp+0x328],xmm0
    lea    rdx,[rsp+0x1c2]
    lea    r8,[rsp+0x328]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x1be],0x20130
    movsd  QWORD PTR [rsp+0x320],xmm7
    lea    rdx,[rsp+0x1be]
    lea    r8,[rsp+0x320]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x1ba],0x20130
    movsd  QWORD PTR [rsp+0x318],xmm6
    lea    rdx,[rsp+0x1ba]
    lea    r8,[rsp+0x318]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x80]
    mov    DWORD PTR [rsp+0x1b6],0x20130
    movsd  QWORD PTR [rsp+0x310],xmm0
    lea    rdx,[rsp+0x1b6]
    lea    r8,[rsp+0x310]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    lea    rax,[rip + ref_27_DITSUM_MODEL1]
    lea    rax,[rax+rsi*4]
    add    rax,0xfffffffffffffffc
    mov    DWORD PTR [rsp+0x1b2],0x20638
    mov    QWORD PTR [rsp+0x578],0x4
    mov    QWORD PTR [rsp+0x580],rax
    mov    QWORD PTR [rsp+0x588],0x4
    lea    rdx,[rsp+0x1b2]
    lea    r8,[rsp+0x578]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    lea    rax,[rip + ref_28_DITSUM_MODEL2]
    lea    rax,[rax+rsi*4]
    add    rax,0xfffffffffffffffc
    mov    DWORD PTR [rsp+0x1ae],0x20638
    mov    QWORD PTR [rsp+0x560],0x4
    mov    QWORD PTR [rsp+0x568],rax
    mov    QWORD PTR [rsp+0x570],0x4
    lea    rdx,[rsp+0x1ae]
    lea    r8,[rsp+0x560]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x20]
    mov    DWORD PTR [rsp+0x1aa],0x10130
    movsd  QWORD PTR [rsp+0x308],xmm0
    lea    rdx,[rsp+0x1aa]
    lea    r8,[rsp+0x308]
    mov    rcx,r12
    mov    r12,rdi
    mov    rdi,r14
    mov    r14,r15
    mov    r15,QWORD PTR [rsp+0x38]
    {disp32} jmp    at_1_1edc
at_1_16e5:
    cmp    r8,0x2
    sete   al
    mov    r14,rdi
    cmp    rcx,0x1
    {disp32} jne    at_1_179d
    cmp    r8,0x2
    {disp32} jne    at_1_179d
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x184],0x10638
    mov    QWORD PTR [rsp+0x530],0x1e0
    lea    rax,[rsp+0x700]
    mov    QWORD PTR [rsp+0x538],rax
    mov    QWORD PTR [rsp+0x540],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0678 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x184]
    lea    r9,[rsp+0x530]
at_1_1760:
    mov    rdx,r15
    call   ref_20_for_write_int_fmt
    xor    sil,0x1
    mov    rax,QWORD PTR [rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    rdx,[rsp+0x700]
    lea    r8,[rsp+0x30]
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    eax,esi
at_1_179d:
    mov    QWORD PTR [rbp+0x118],0x0
    xorpd  xmm8,xmm8
    ucomisd xmm9,xmm8
    jbe    at_1_17bf
    movsd  xmm8,QWORD PTR [r14+0x28]
    divsd  xmm8,xmm9
at_1_17bf:
    mov    rdi,r12
    test   al,al
    {disp32} je     at_1_19c3
    mov    rax,QWORD PTR [rbp+0xf0]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x150],0x10b0638
    mov    WORD PTR [rsp+0x154],0x2
    mov    QWORD PTR [rsp+0x680],0x1e0
    lea    rcx,[rsp+0x700]
    mov    QWORD PTR [rsp+0x688],rcx
    mov    QWORD PTR [rsp+0x690],0x50
    mov    QWORD PTR [rsp+0x698],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_059c - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r12,[rsp+0x40]
    lea    r8,[rsp+0x150]
    lea    r9,[rsp+0x680]
    mov    rcx,r12
    mov    rdx,r15
    call   ref_20_for_write_int_fmt
    mov    DWORD PTR [rsp+0x14c],0x2010b
    mov    QWORD PTR [rsp+0x290],rbx
    lea    rdx,[rsp+0x14c]
    lea    r8,[rsp+0x290]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x48]
    mov    DWORD PTR [rsp+0x148],0x20130
    movsd  QWORD PTR [rsp+0x288],xmm0
    lea    rdx,[rsp+0x148]
    lea    r8,[rsp+0x288]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x144],0x20130
    movsd  QWORD PTR [rsp+0x280],xmm7
    lea    rdx,[rsp+0x144]
    lea    r8,[rsp+0x280]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x140],0x20130
    movsd  QWORD PTR [rsp+0x278],xmm6
    lea    rdx,[rsp+0x140]
    lea    r8,[rsp+0x278]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x80]
    mov    DWORD PTR [rsp+0x13c],0x20130
    movsd  QWORD PTR [rsp+0x270],xmm0
    lea    rdx,[rsp+0x13c]
    lea    r8,[rsp+0x270]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x20]
    mov    DWORD PTR [rsp+0x138],0x20130
    movsd  QWORD PTR [rsp+0x268],xmm0
    lea    rdx,[rsp+0x138]
    lea    r8,[rsp+0x268]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x8]
    mov    DWORD PTR [rsp+0x134],0x20130
    movsd  QWORD PTR [rsp+0x260],xmm0
    lea    rdx,[rsp+0x134]
    lea    r8,[rsp+0x260]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x130],0x10130
    movsd  QWORD PTR [rsp+0x258],xmm8
    lea    rdx,[rsp+0x130]
    lea    r8,[rsp+0x258]
    {disp32} jmp    at_1_1c62
at_1_19c3:
    mov    rax,QWORD PTR [rbp+0xf0]
    mov    rsi,QWORD PTR [rbp+0x1f8]
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x17e],0x10b0638
    mov    WORD PTR [rsp+0x182],0x2
    mov    QWORD PTR [rsp+0x6a0],0x1e0
    lea    rcx,[rsp+0x700]
    mov    QWORD PTR [rsp+0x6a8],rcx
    mov    QWORD PTR [rsp+0x6b0],0x50
    mov    QWORD PTR [rsp+0x6b8],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_05f8 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r12,[rsp+0x40]
    lea    r8,[rsp+0x17e]
    lea    r9,[rsp+0x6a0]
    mov    rcx,r12
    mov    rdx,r15
    call   ref_20_for_write_int_fmt
    mov    DWORD PTR [rsp+0x17a],0x2010b
    mov    QWORD PTR [rsp+0x2d0],rbx
    lea    rdx,[rsp+0x17a]
    lea    r8,[rsp+0x2d0]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x48]
    mov    DWORD PTR [rsp+0x176],0x20130
    movsd  QWORD PTR [rsp+0x2c8],xmm0
    lea    rdx,[rsp+0x176]
    lea    r8,[rsp+0x2c8]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x172],0x20130
    movsd  QWORD PTR [rsp+0x2c0],xmm7
    lea    rdx,[rsp+0x172]
    lea    r8,[rsp+0x2c0]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x16e],0x20130
    movsd  QWORD PTR [rsp+0x2b8],xmm6
    lea    rdx,[rsp+0x16e]
    lea    r8,[rsp+0x2b8]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x80]
    mov    DWORD PTR [rsp+0x16a],0x20130
    movsd  QWORD PTR [rsp+0x2b0],xmm0
    lea    rdx,[rsp+0x16a]
    lea    r8,[rsp+0x2b0]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    lea    rax,[rip + ref_27_DITSUM_MODEL1]
    lea    rax,[rax+rsi*4]
    add    rax,0xfffffffffffffffc
    mov    DWORD PTR [rsp+0x166],0x20638
    mov    QWORD PTR [rsp+0x518],0x4
    mov    QWORD PTR [rsp+0x520],rax
    mov    QWORD PTR [rsp+0x528],0x4
    lea    rdx,[rsp+0x166]
    lea    r8,[rsp+0x518]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    lea    rax,[rip + ref_28_DITSUM_MODEL2]
    lea    rax,[rax+rsi*4]
    add    rax,0xfffffffffffffffc
    mov    DWORD PTR [rsp+0x162],0x20638
    mov    QWORD PTR [rsp+0x500],0x4
    mov    QWORD PTR [rsp+0x508],rax
    mov    QWORD PTR [rsp+0x510],0x4
    lea    rdx,[rsp+0x162]
    lea    r8,[rsp+0x500]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x20]
    mov    DWORD PTR [rsp+0x15e],0x20130
    movsd  QWORD PTR [rsp+0x2a8],xmm0
    lea    rdx,[rsp+0x15e]
    lea    r8,[rsp+0x2a8]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [r14+0x8]
    mov    DWORD PTR [rsp+0x15a],0x20130
    movsd  QWORD PTR [rsp+0x2a0],xmm0
    lea    rdx,[rsp+0x15a]
    lea    r8,[rsp+0x2a0]
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x156],0x10130
    movsd  QWORD PTR [rsp+0x298],xmm8
    lea    rdx,[rsp+0x156]
    lea    r8,[rsp+0x298]
at_1_1c62:
    mov    rcx,r12
    call   ref_24_for_write_int_fmt_xmit
    mov    rsi,QWORD PTR [rsp+0x998]
    mov    r12,rdi
    mov    rdi,r14
    mov    r14,QWORD PTR [rsp+0x78]
    mov    r15,QWORD PTR [rsp+0x38]
    {disp32} jmp    at_1_1ee9
at_1_1c87:
    cmp    rcx,0x1
    {disp32} jne    at_1_1d39
    cmp    r8,0x2
    {disp32} jne    at_1_1d39
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x1d0],0x10638
    mov    QWORD PTR [rsp+0x590],0x1e0
    lea    rsi,[rsp+0x700]
    mov    QWORD PTR [rsp+0x598],rsi
    mov    QWORD PTR [rsp+0x5a0],0x50
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_0800 - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x40]
    lea    r8,[rsp+0x1d0]
    lea    r9,[rsp+0x590]
    mov    rdx,r13
    call   ref_20_for_write_int_fmt
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_21_unnamed_1]
    lea    r8,[rsp+0x30]
    mov    rdx,rsi
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    QWORD PTR [rbp+0x118],0x0
    mov    rax,QWORD PTR [rbp+0xf0]
    jmp    at_1_1d4e
at_1_1d39:
    mov    QWORD PTR [rbp+0x118],0x0
    cmp    r8,0x2
    {disp32} jne    at_1_148d
at_1_1d4e:
    mov    QWORD PTR [rsp+0x40],0x0
    mov    DWORD PTR [rsp+0x1a4],0x10b0638
    mov    WORD PTR [rsp+0x1a8],0x2
    mov    QWORD PTR [rsp+0x6c0],0x1e0
    lea    rcx,[rsp+0x700]
    mov    QWORD PTR [rsp+0x6c8],rcx
    mov    QWORD PTR [rsp+0x6d0],0x50
    mov    QWORD PTR [rsp+0x6d8],rax
    lea    rax,[rip + ref_19_DITSUM_format_pack + (at_2_059c - def_19_DITSUM_format_pack)]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rsi,[rsp+0x40]
    lea    r8,[rsp+0x1a4]
    lea    r9,[rsp+0x6c0]
    mov    rcx,rsi
    mov    rdx,r13
    call   ref_20_for_write_int_fmt
    mov    DWORD PTR [rsp+0x1a0],0x2010b
    mov    QWORD PTR [rsp+0x300],rbx
    lea    rdx,[rsp+0x1a0]
    lea    r8,[rsp+0x300]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [rdi+0x48]
    mov    DWORD PTR [rsp+0x19c],0x20130
    movsd  QWORD PTR [rsp+0x2f8],xmm0
    lea    rdx,[rsp+0x19c]
    lea    r8,[rsp+0x2f8]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x198],0x20130
    movsd  QWORD PTR [rsp+0x2f0],xmm7
    lea    rdx,[rsp+0x198]
    lea    r8,[rsp+0x2f0]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    mov    DWORD PTR [rsp+0x194],0x20130
    movsd  QWORD PTR [rsp+0x2e8],xmm6
    lea    rdx,[rsp+0x194]
    lea    r8,[rsp+0x2e8]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [rdi+0x80]
    mov    DWORD PTR [rsp+0x190],0x20130
    movsd  QWORD PTR [rsp+0x2e0],xmm0
    lea    rdx,[rsp+0x190]
    lea    r8,[rsp+0x2e0]
    mov    rcx,rsi
    call   ref_24_for_write_int_fmt_xmit
    movsd  xmm0,QWORD PTR [rdi+0x20]
    mov    DWORD PTR [rsp+0x18c],0x10130
    movsd  QWORD PTR [rsp+0x2d8],xmm0
    lea    rdx,[rsp+0x18c]
    lea    r8,[rsp+0x2d8]
    mov    rcx,rsi
at_1_1edc:
    call   ref_24_for_write_int_fmt_xmit
    mov    rsi,QWORD PTR [rsp+0x998]
at_1_1ee9:
    mov    QWORD PTR [rsp+0x20],r15
    mov    QWORD PTR [rsp+0x28],0x50
    lea    rcx,[rip + ref_25_unnamed_3]
    lea    rdx,[rsp+0x700]
    lea    r8,[rsp+0x30]
    mov    r9,rbp
    call   ref_22_WRITELINES
    mov    r8,QWORD PTR [rsp+0x70]
    mov    r15,QWORD PTR [rsp+0x80]
at_1_1f20:
    cmp    r14,0x3
    {disp32} jb     at_1_0130
    {disp32} jmp    at_1_01ab
at_1_1f2f:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
def_28_DITSUM_MODEL2:
at_2_0000:
    .ascii " G   S  G-S S-G -S-G-G-S"
def_27_DITSUM_MODEL1:
at_2_0018:
    .ascii "                  G   S "
def_19_DITSUM_format_pack:
at_2_0030:
    .quad 0x0001004700000036
    .long 0x0018001c
    .ascii " INCONSISTENT DIMENSIONS7"
    .zero 3
at_2_0058:
    .quad 0x0000000e00000036
    .quad 0x0000000100000001
    .quad 0x0000000100000024
    .quad 0x0000000a00000005
    .quad 0x0000000100000001
    .quad 0x000000010600001f
    .quad 0x0300001f00000010
    .quad 0x0000000e00000002
    .long 0x00000037
at_2_009c:
    .quad 0x0001004700000036
    .long 0x0016001c
    .ascii "     I      FINAL X(I)"
    .quad 0x00010000000e0000
    .quad 0x001c000000080000
    .short 0x0004
    .ascii "D(I)"
    .quad 0x000000010000000e
    .quad 0x0004001c0000000a
    .ascii "G(I)G"
    .long 0x37000100
    .short 0x0000
    .byte 0x00
at_2_00f0:
    .quad 0x0001004700000036
    .long 0x000c001c
    .ascii " # VARIABLES$"
    .quad 0x0800000001000000
    .quad 0x1c00010047000000
    .short 0x0900
    .byte 0x00
    .ascii " FUNCTION"
    .quad 0x010000000a000000
    .quad 0x1f00000001000000
    .quad 0x1100000001060000
    .long 0x1c000000
    .short 0x0800
    .byte 0x00
    .ascii "   RELDX"
    .quad 0x000000010300001f
    .quad 0x0001004700000011
    .long 0x000c001c
    .ascii " FUNC. EVALS$"
    .quad 0x0800000001000000
    .quad 0x010000000e000000
    .quad 0x1c00000009000000
    .short 0x0b00
    .byte 0x00
    .ascii "GRAD. EVALS"
    .quad 0x0000010000002400
    .quad 0x0100470000000800
    .long 0x07001c00
    .byte 0x00
    .ascii " PRELDF"
    .quad 0x0000010300001f00
    .quad 0x00000e0000001000
    .quad 0x0000060000000100
    .long 0x07001c00
    .byte 0x00
    .ascii "NPRELDF"
    .quad 0x0000010300001f00
    .quad 0x0000370000000f00
    .byte 0x00
at_2_01e4:
    .quad 0x0001004700000036
    .long 0x0006001c
    .ascii "     0"
    .quad 0x0001000000240000
    .quad 0x000a000000050000
    .quad 0x0001000000010000
    .quad 0x00010300001f0000
    .quad 0x00370000000b0000
    .short 0x0000
at_2_0220:
    .quad 0x0001004700000036
    .long 0x0006001c
    .ascii "     0"
    .quad 0x0001000000240000
    .quad 0x000a000000050000
    .quad 0x0001000000010000
    .quad 0x00010300001f0000
    .quad 0x00370000000a0000
    .short 0x0000
at_2_025c:
    .quad 0x0000000e00000036
    .quad 0x0000000100000001
    .quad 0x0000000100000024
    .quad 0x0000000a00000005
    .quad 0x0000000100000001
    .quad 0x000000010600001f
    .quad 0x0300001f00000011
    .quad 0x0000000e00000001
    .long 0x00000037
at_2_02a0:
    .quad 0x0001004700000036
    .long 0x0017001c
    .ascii "     I     INITIAL X(I)"
    .quad 0x0000010000000e00
    .quad 0x04001c0000000800
    .byte 0x00
    .ascii "D(I)G"
    .long 0x37000100
    .short 0x0000
    .byte 0x00
at_2_02e0:
    .quad 0x0001004700000036
    .long 0x000e001c
    .ascii " ***** IV(1) ="
    .quad 0x0001000000240000
    .quad 0x001c000000050000
    .short 0x0006
    .ascii " *****"
    .long 0x00370000
    .short 0x0000
at_2_0318:
    .quad 0x0001004700000036
    .long 0x002b001c
    .ascii " ***** GRADIENT COULD NOT BE COMPUTED *****"
    .long 0x00003700
    .byte 0x00
at_2_0354:
    .quad 0x0001004700000036
    .long 0x0025001c
    .ascii " ***** BAD PARAMETERS TO ASSESS *****"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_038c:
    .quad 0x0001004700000036
    .long 0x002c001c
    .ascii " ***** INITIAL F(X) CANNOT BE COMPUTED *****7"
    .zero 3
at_2_03c8:
    .quad 0x0001004700000036
    .long 0x0012001c
    .ascii " ***** STOPX *****"
    .long 0x00370000
    .short 0x0000
at_2_03ec:
    .quad 0x0001004700000036
    .long 0x001c001c
    .ascii " ***** ITERATION LIMIT *****7"
    .zero 3
at_2_0418:
    .quad 0x0001004700000036
    .long 0x0026001c
    .ascii " ***** FUNCTION EVALUATION LIMIT *****"
    .long 0x00370000
    .short 0x0000
at_2_0450:
    .quad 0x0001004700000036
    .long 0x001e001c
    .ascii " ***** FALSE CONVERGENCE *****"
    .long 0x00370000
    .short 0x0000
at_2_0480:
    .quad 0x0001004700000036
    .long 0x0021001c
    .ascii " ***** SINGULAR CONVERGENCE *****"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_04b4:
    .quad 0x0001004700000036
    .long 0x002a001c
    .ascii " ***** ABSOLUTE FUNCTION CONVERGENCE *****"
    .long 0x00370000
    .short 0x0000
at_2_04f0:
    .quad 0x0001004700000036
    .long 0x0031001c
    .ascii " ***** X- AND RELATIVE FUNCTION CONVERGENCE *****"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_0534:
    .quad 0x0001004700000036
    .long 0x002a001c
    .ascii " ***** RELATIVE FUNCTION CONVERGENCE *****"
    .long 0x00370000
    .short 0x0000
at_2_0570:
    .quad 0x0001004700000036
    .long 0x001a001c
    .ascii " ***** X-CONVERGENCE *****"
    .long 0x00370000
    .short 0x0000
at_2_059c:
    .quad 0x0000002400000036
    .quad 0x0000000600000001
    .quad 0x0000000100000024
    .quad 0x0000000a00000005
    .quad 0x0000000100000001
    .quad 0x000000010300001f
    .quad 0x0200001f0000000b
    .quad 0x0000000a00000002
    .quad 0x000000030100001f
    .quad 0x0200001f00000009
    .quad 0x0000000a00000001
    .long 0x00000037
at_2_05f8:
    .quad 0x0000002400000036
    .quad 0x0000000600000001
    .quad 0x0000000100000024
    .quad 0x0000000a00000005
    .quad 0x0000000100000001
    .quad 0x000000010300001f
    .quad 0x0200001f0000000a
    .quad 0x0000000900000002
    .quad 0x000000010100001f
    .quad 0x0000001d00000008
    .quad 0x0000000300000001
    .quad 0x000000010000001d
    .quad 0x0100001f00000004
    .quad 0x0000000800000002
    .quad 0x000000010200001f
    .quad 0x0000003700000009
at_2_0678:
    .quad 0x0001004700000036
    .long 0x000b001c
    .ascii "    IT   NF"
    .quad 0x0000010000000e00
    .quad 0x01001c0000000700
    .quad 0x00000e0000004600
    .quad 0x0000080000000100
    .long 0x05001c00
    .byte 0x00
    .ascii "RELDF"
    .quad 0x010000000e000000
    .quad 0x1c00000004000000
    .short 0x0600
    .byte 0x00
    .ascii "PRELDF"
    .quad 0x00010000000e0000
    .quad 0x001c000000040000
    .short 0x0005
    .ascii "RELDX"
    .quad 0x010000000e000000
    .quad 0x1c00000003000000
    .short 0x0600
    .byte 0x00
    .ascii "STPPAR"
    .quad 0x00010000000e0000
    .quad 0x001c000000030000
    .short 0x0006
    .ascii "D*STEP"
    .quad 0x00010000000e0000
    .quad 0x001c000000030000
    .short 0x0007
    .ascii "NPRELDF"
    .long 0x00003700
    .byte 0x00
at_2_0738:
    .quad 0x0001004700000036
    .long 0x000b001c
    .ascii "    IT   NF"
    .quad 0x0000010000000e00
    .quad 0x01001c0000000600
    .quad 0x00000e0000004600
    .quad 0x0000070000000100
    .long 0x05001c00
    .byte 0x00
    .ascii "RELDF"
    .quad 0x010000000e000000
    .quad 0x1c00000003000000
    .short 0x0600
    .byte 0x00
    .ascii "PRELDF"
    .quad 0x00010000000e0000
    .quad 0x001c000000030000
    .short 0x0005
    .ascii "RELDX"
    .quad 0x010000000e000000
    .quad 0x1c00000002000000
    .short 0x0d00
    .byte 0x00
    .ascii "MODEL  STPPAR"
    .quad 0x010000000e000000
    .quad 0x1c00000002000000
    .short 0x0600
    .byte 0x00
    .ascii "D*STEP"
    .quad 0x00010000000e0000
    .quad 0x001c000000020000
    .short 0x0007
    .ascii "NPRELDF"
    .long 0x00003700
    .byte 0x00
at_2_0800:
    .quad 0x0001004700000036
    .long 0x000b001c
    .ascii "    IT   NF"
    .quad 0x0000010000000e00
    .quad 0x01001c0000000700
    .quad 0x00000e0000004600
    .quad 0x0000080000000100
    .long 0x05001c00
    .byte 0x00
    .ascii "RELDF"
    .quad 0x010000000e000000
    .quad 0x1c00000004000000
    .short 0x0600
    .byte 0x00
    .ascii "PRELDF"
    .quad 0x00010000000e0000
    .quad 0x001c000000040000
    .short 0x0005
    .ascii "RELDX"
    .quad 0x010000000e000000
    .quad 0x1c00000003000000
    .short 0x0600
    .byte 0x00
    .ascii "STPPAR"
    .long 0x00370000
    .short 0x0000
at_2_0890:
    .quad 0x0001004700000036
    .long 0x000a001c
    .ascii "   IT   NF"
    .quad 0x00010000000e0000
    .quad 0x001c000000060000
    .quad 0x000e000000460001
    .quad 0x0007000000010000
    .long 0x001c0000
    .short 0x0005
    .ascii "RELDF"
    .quad 0x010000000e000000
    .quad 0x1c00000003000000
    .short 0x0600
    .byte 0x00
    .ascii "PRELDF"
    .quad 0x00010000000e0000
    .quad 0x001c000000030000
    .short 0x0005
    .ascii "RELDX"
    .quad 0x010000000e000000
    .quad 0x1c00000002000000
    .short 0x0d00
    .byte 0x00
    .ascii "MODEL  STPPAR"
    .long 0x37000000
    .short 0x0000
    .byte 0x00
at_2_0928:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
at_5_0000:
    .long ref_0_text + (at_1_01fa - at_1_0000) + (. - at_5_0000) + 4    # slot 0 -> at_1_01fa
    .long ref_0_text + (at_1_0a91 - at_1_0000) + (. - at_5_0000) + 4    # slot 1 -> at_1_0a91
    .long ref_0_text + (at_1_0986 - at_1_0000) + (. - at_5_0000) + 4    # slot 2 -> at_1_0986
    .long ref_0_text + (at_1_09df - at_1_0000) + (. - at_5_0000) + 4    # slot 3 -> at_1_09df
    .long ref_0_text + (at_1_08cf - at_1_0000) + (. - at_5_0000) + 4    # slot 4 -> at_1_08cf
    .long ref_0_text + (at_1_0aea - at_1_0000) + (. - at_5_0000) + 4    # slot 5 -> at_1_0aea
    .long ref_0_text + (at_1_0b40 - at_1_0000) + (. - at_5_0000) + 4    # slot 6 -> at_1_0b40
    .long ref_0_text + (at_1_0a38 - at_1_0000) + (. - at_5_0000) + 4    # slot 7 -> at_1_0a38
    .long ref_0_text + (at_1_10ca - at_1_0000) + (. - at_5_0000) + 4    # slot 8 -> at_1_10ca
    .long ref_0_text + (at_1_0928 - at_1_0000) + (. - at_5_0000) + 4    # slot 9 -> at_1_0928
    .long ref_0_text + (at_1_102d - at_1_0000) + (. - at_5_0000) + 4    # slot 10 -> at_1_102d
    .long ref_0_text + (at_1_0876 - at_1_0000) + (. - at_5_0000) + 4    # slot 11 -> at_1_0876
def_26_unnamed_4:
at_5_0030:
    .quad 0x0000000000000005
def_23_unnamed_2:
at_5_0038:
    .quad 0x0000000000000003
def_25_unnamed_3:
at_5_0040:
    .quad 0x0000000000000001
def_21_unnamed_1:
at_5_0048:
    .quad 0x0000000000000002
at_5_0050:
end_s5:

# .xdata  (COFF section 6)
.section .s6,"dr"
def_11_xdata:
at_6_0000:
    .byte 0x01    # version 1
    .byte at_1_0039 - at_1_0000    # prologue size
    .byte 0x12    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0039 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x8e
    .byte 0x00
    .byte at_1_0030 - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x8f
    .byte 0x00
    .byte at_1_0027 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x90
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x91
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x25
    .byte 0x01
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_6_0028:
end_s6:

# .drectve  (COFF section 7)
.section .s7,"dr"
def_13_drectve:
at_7_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_7_00b9:
end_s7:

# .pdata  (COFF section 8)
.section .s8,"dr"
def_15_pdata:
at_8_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_1f2f - def_0_text)    # image-relative end
    .long ref_11_xdata    # image-relative unwind info
at_8_000c:
end_s8:

# MEMBER dh2rfg.obj
# Entry points: DH2RFG
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DH2RFG:
at_1_0000:
    mov    rax,QWORD PTR [rsp+0x28]
    movsd  xmm1,QWORD PTR [rdx]
    xorpd  xmm3,xmm3
    ucomisd xmm3,xmm1
    setnp  dl
    sete   r10b
    movsd  xmm0,QWORD PTR [rcx]
    test   r10b,dl
    jne    at_1_008d
    movapd xmm2,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    movapd xmm3,xmm0
    andpd  xmm3,xmm2
    andpd  xmm2,xmm1
    addsd  xmm2,xmm3
    divsd  xmm0,xmm2
    divsd  xmm1,xmm2
    movapd xmm3,xmm0
    mulsd  xmm3,xmm0
    movapd xmm4,xmm1
    mulsd  xmm4,xmm1
    addsd  xmm4,xmm3
    sqrtsd xmm4,xmm4
    xorpd  xmm3,xmm3
    ucomisd xmm0,xmm3
    jbe    at_1_006b
    xorpd  xmm4,XMMWORD PTR [rip + ref_11_xmm_80000000000000008000000000000000]
at_1_006b:
    subsd  xmm0,xmm4
    movapd xmm3,xmm1
    divsd  xmm3,xmm0
    divsd  xmm0,xmm4
    divsd  xmm1,xmm4
    mulsd  xmm2,xmm4
    movapd xmm4,xmm0
    movapd xmm0,xmm2
    jmp    at_1_0095
at_1_008d:
    xorpd  xmm4,xmm4
    xorpd  xmm1,xmm1
at_1_0095:
    movsd  QWORD PTR [rax],xmm3
    movsd  QWORD PTR [r8],xmm4
    movsd  QWORD PTR [r9],xmm1
    ret
at_1_00a4:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_80000000000000008000000000000000:
at_5_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_5_0010:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_12_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# MEMBER dh2rfa.obj
# Entry points: DH2RFA
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_13_DH2RFA:
at_1_0000:
    sub    rsp,0x18
at_1_0004:
    movapd XMMWORD PTR [rsp],xmm6
at_1_0009:
    mov    rax,QWORD PTR [rcx]
    test   rax,rax
    jle    at_1_006e
    mov    rcx,QWORD PTR [rsp+0x48]
    mov    r10,QWORD PTR [rsp+0x40]
    movsd  xmm0,QWORD PTR [r9]
    movsd  xmm1,QWORD PTR [r10]
    movsd  xmm2,QWORD PTR [rcx]
    xor    ecx,ecx
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_0030:
    movsd  xmm3,QWORD PTR [rdx+rcx*8]
    movapd xmm4,xmm3
    mulsd  xmm4,xmm0
    movsd  xmm5,QWORD PTR [r8+rcx*8]
    movapd xmm6,xmm5
    mulsd  xmm6,xmm1
    addsd  xmm6,xmm4
    addsd  xmm3,xmm6
    movsd  QWORD PTR [rdx+rcx*8],xmm3
    mulsd  xmm6,xmm2
    addsd  xmm6,xmm5
    movsd  QWORD PTR [r8+rcx*8],xmm6
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0030
at_1_006e:
    movaps xmm6,XMMWORD PTR [rsp]
    add    rsp,0x18
    ret
at_1_0077:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0009 - at_1_0000    # prologue size
    .byte 0x03    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0009 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x00
    .byte 0x00
    .byte at_1_0004 - at_1_0000    # ALLOC_SMALL
    .byte 0x22
    .byte 0x00
    .byte 0x00
at_4_000c:
end_s4:

# .drectve  (COFF section 5)
.section .s5,"dr"
def_8_drectve:
at_5_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_5_00b9:
end_s5:

# .pdata  (COFF section 6)
.section .s6,"dr"
def_10_pdata:
at_6_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0077 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_6_000c:
end_s6:

# MEMBER dg7qts.obj
# Entry points: DG7QTS
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_48_DG7QTS:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x158
at_1_0013:
    movapd XMMWORD PTR [rsp+0x140],xmm15
at_1_001d:
    movaps XMMWORD PTR [rsp+0x130],xmm14
at_1_0026:
    movapd XMMWORD PTR [rsp+0x120],xmm13
at_1_0030:
    movapd XMMWORD PTR [rsp+0x110],xmm12
at_1_003a:
    movapd XMMWORD PTR [rsp+0x100],xmm11
at_1_0044:
    movapd XMMWORD PTR [rsp+0xf0],xmm10
at_1_004e:
    movapd XMMWORD PTR [rsp+0xe0],xmm9
at_1_0058:
    movaps XMMWORD PTR [rsp+0xd0],xmm8
at_1_0061:
    movapd XMMWORD PTR [rsp+0xc0],xmm7
at_1_006a:
    movapd XMMWORD PTR [rsp+0xb0],xmm6
at_1_0073:
    mov    QWORD PTR [rsp+0x30],r9
    mov    rsi,r8
    mov    QWORD PTR [rsp+0x58],rdx
    mov    rdi,rcx
    mov    r14,QWORD PTR [rsp+0x1d8]
    movsd  xmm8,QWORD PTR [rip + ref_49_DG7QTS_BIG]
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm8
    jb     at_1_00b8
    lea    rcx,[rip + ref_50_unnamed_1]
    call   ref_51_DR7MDC
    movapd xmm8,xmm0
    movsd  QWORD PTR [rip + ref_49_DG7QTS_BIG],xmm0
at_1_00b8:
    mov    QWORD PTR [rsp+0x78],rdi
    mov    rax,QWORD PTR [rsp+0x1c8]
    mov    rbp,QWORD PTR [rax]
    movsd  xmm14,QWORD PTR [r14+0x38]
    movsd  xmm3,QWORD PTR [r14+0x90]
    movapd xmm0,xmm14
    mulsd  xmm0,xmm14
    movsd  QWORD PTR [rsp+0xa0],xmm0
    movsd  xmm0,QWORD PTR [r14+0xa0]
    mulsd  xmm0,xmm14
    movsd  QWORD PTR [rsp+0x70],xmm0
    movsd  xmm1,QWORD PTR [r14+0x98]
    movapd xmm0,xmm1
    mulsd  xmm0,xmm14
    movsd  QWORD PTR [rsp+0xa8],xmm0
    movsd  xmm2,QWORD PTR [rip + ref_8_real_4000000000000000]
    movapd xmm0,xmm2
    movsd  QWORD PTR [rsp+0x80],xmm3
    mulsd  xmm0,xmm3
    movsd  xmm4,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    addsd  xmm1,xmm4
    mulsd  xmm1,QWORD PTR [rip + ref_14_real_4010000000000000]
    movsd  xmm3,QWORD PTR [rip + ref_17_real_4008000000000000]
    mulsd  xmm1,xmm3
    addsd  xmm2,xmm2
    addsd  xmm2,xmm1
    mulsd  xmm3,xmm14
    mulsd  xmm3,xmm2
    divsd  xmm0,xmm3
    movapd xmm1,xmm14
    minsd  xmm1,xmm4
    mulsd  xmm1,xmm8
    ucomisd xmm1,xmm0
    jbe    at_1_0185
    divsd  xmm0,xmm14
    movapd xmm8,xmm0
at_1_0185:
    mov    rbx,QWORD PTR [rsp+0x1e0]
    mov    r13,QWORD PTR [rsp+0x1c0]
    lea    rax,[rbp*2+0x7]
    mov    QWORD PTR [rsp+0x50],rax
    mov    QWORD PTR [rsp+0x38],0x0
    mov    rcx,QWORD PTR [rsp+0x30]
    mov    rdi,QWORD PTR [rcx]
    test   rdi,rdi
    mov    QWORD PTR [rsp+0x28],rbp
    movsd  QWORD PTR [rsp+0x48],xmm14
    js     at_1_0242
    movsd  xmm0,QWORD PTR [r14+0x10]
    movapd xmm1,xmm0
    subsd  xmm1,xmm14
    ucomisd xmm1,QWORD PTR [rsp+0x70]
    seta   al
    lea    rdx,[rdi+0x32]
    mov    QWORD PTR [rsp+0x68],rdx
    xorpd  xmm1,xmm1
    ucomisd xmm1,xmm0
    {disp32} jae    at_1_036c
    test   al,al
    {disp32} jne    at_1_036c
    inc    rdi
    mov    QWORD PTR [rcx],rdi
    mov    r12,0xffffffffffffffff
    test   rbp,rbp
    jle    at_1_023d
    lea    rax,[rbx+rbp*8]
    add    rax,0x38
    xor    ecx,ecx
    xor    edx,edx
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0220:
    add    rdx,rcx
    inc    rdx
    movsd  xmm0,QWORD PTR [rax+rcx*8]
    lea    r8,[rcx+0x1]
    movsd  QWORD PTR [rsi+rdx*8-0x8],xmm0
    mov    rcx,r8
    cmp    rbp,r8
    jne    at_1_0220
at_1_023d:
    {disp32} jmp    at_1_02ee
at_1_0242:
    mov    QWORD PTR [rcx],0x0
    mov    rdi,QWORD PTR [rsp+0x1c8]
    mov    rcx,rdi
    mov    rdx,QWORD PTR [rsp+0x58]
    call   ref_52_DV2NRM
    movsd  QWORD PTR [r14],xmm0
    mov    QWORD PTR [r14+0x28],0x0
    mov    QWORD PTR [r14+0x10],0x0
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    setp   al
    setne  cl
    or     cl,al
    movzx  eax,cl
    mov    rdx,QWORD PTR [rdi]
    test   rdx,rdx
    jle    at_1_02bf
    lea    rcx,[rbx+rbp*8]
    add    rcx,0x38
    xor    r8d,r8d
    xor    r9d,r9d
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_02a0:
    add    r9,r8
    inc    r9
    movsd  xmm0,QWORD PTR [rsi+r9*8-0x8]
    movsd  QWORD PTR [rcx+r8*8],xmm0
    lea    r10,[r8+0x1]
    mov    r8,r10
    cmp    rdx,r10
    jne    at_1_02a0
at_1_02bf:
    lea    rcx,[rdx+0x1]
    imul   rcx,rdx
    cmp    rcx,0x2
    {disp32} jae    at_1_0466
at_1_02d1:
    lea    rax,[rax+rax*2]
    mov    QWORD PTR [rsp+0x60],rax
    movsd  QWORD PTR [rbx+rbp*8],xmm1
    mov    eax,0x32
    mov    QWORD PTR [rsp+0x68],rax
    xor    edi,edi
    xor    r12d,r12d
at_1_02ee:
    lea    rax,[rsp+0x38]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rip + ref_53_unnamed_2]
    mov    rdx,QWORD PTR [rsp+0x1c8]
    mov    r8,r13
    mov    r9,rsi
    call   ref_54_DL7SRT
    mov    r15,QWORD PTR [rsp+0x38]
    test   r15,r15
    {disp32} je     at_1_0538
    lea    rax,[r15+0x1]
    imul   rax,r15
    and    rax,0xfffffffffffffffe
    movsd  xmm6,QWORD PTR [r13+rax*4-0x8]
    movabs rcx,0x3ff0000000000000
    mov    QWORD PTR [r13+rax*4-0x8],rcx
    test   r15,r15
    {disp32} jle    at_1_04c0
    cmp    r15,0xd
    {disp32} jb     at_1_04a5
    lea    r8,[r15*8+0x0]
    mov    rcx,rbx
    xor    edx,edx
    call   ref_55_intel_fast_memset
    {disp32} jmp    at_1_04c0
at_1_036c:
    movsd  xmm3,QWORD PTR [r14]
    xor    r12d,r12d
    ucomisd xmm1,xmm3
    lea    rax,[rdi+0x3]
    mov    ecx,0x0
    cmovne rcx,rax
    cmovp  rcx,rax
    mov    QWORD PTR [rsp+0x60],rcx
    test   rdi,rdi
    {disp32} je     at_1_052c
    movsd  xmm10,QWORD PTR [rbx+rbp*8+0x30]
    movsd  xmm15,QWORD PTR [r14+0x20]
    andpd  xmm15,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    movapd xmm1,xmm3
    divsd  xmm1,xmm14
    movapd xmm12,xmm1
    subsd  xmm12,QWORD PTR [rbx+rbp*8+0x10]
    movapd xmm7,xmm10
    xorpd  xmm2,xmm2
    ucomisd xmm3,xmm2
    subsd  xmm7,xmm14
    setp   al
    setne  cl
    or     cl,al
    jne    at_1_03fd
    movsd  xmm3,QWORD PTR [rip + ref_29_real_3f50624dd2f1a9fc]
    movapd xmm4,xmm12
    addsd  xmm4,xmm3
    mulsd  xmm3,xmm12
    addsd  xmm3,xmm4
    movapd xmm12,xmm3
at_1_03fd:
    ucomisd xmm2,xmm12
    jb     at_1_040d
    movsd  xmm12,QWORD PTR [rip + ref_29_real_3f50624dd2f1a9fc]
at_1_040d:
    ucomisd xmm15,xmm2
    seta   al
    ucomisd xmm14,QWORD PTR [r14+0x40]
    movsd  QWORD PTR [rsp+0x40],xmm8
    {disp32} jbe    at_1_0a51
    test   al,al
    je     at_1_0433
    minsd  xmm12,QWORD PTR [rbx+rbp*8+0x28]
at_1_0433:
    movapd xmm11,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    xorpd  xmm11,xmm0
    subsd  xmm1,QWORD PTR [rbx+rbp*8+0x8]
    maxsd  xmm11,xmm1
    xorpd  xmm9,xmm9
    maxsd  xmm11,xmm9
    ucomisd xmm0,xmm9
    {disp32} jbe    at_1_0fe7
    {disp32} jmp    at_1_0a7c
at_1_0466:
    shr    rcx,1
    xorpd  xmm2,xmm2
    xor    edx,edx
    movapd xmm0,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    jmp    at_1_0490
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0480:
    inc    rdx
    movapd xmm2,xmm1
    cmp    rcx,rdx
    {disp32} je     at_1_02d1
at_1_0490:
    movsd  xmm1,QWORD PTR [rsi+rdx*8]
    andpd  xmm1,xmm0
    ucomisd xmm1,xmm2
    ja     at_1_0480
    movapd xmm1,xmm2
    jmp    at_1_0480
at_1_04a5:
    xor    eax,eax
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_04b0:
    mov    QWORD PTR [rbx+rax*8],0x0
    inc    rax
    cmp    r15,rax
    jne    at_1_04b0
at_1_04c0:
    movsd  QWORD PTR [rsp+0x40],xmm8
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rbx+r15*8-0x8],rax
    lea    r15,[rsp+0x38]
    mov    rcx,r15
    mov    rdx,rbx
    mov    r8,r13
    mov    r9,rbx
    call   ref_56_DL7ITV
    mov    rcx,r15
    mov    rdx,rbx
    call   ref_52_DV2NRM
    divsd  xmm6,xmm0
    divsd  xmm6,xmm0
    movapd xmm11,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    xorpd  xmm11,xmm6
    movsd  QWORD PTR [r14+0x10],xmm6
    test   r12b,0x1
    je     at_1_058c
    movsd  xmm8,QWORD PTR [rip + ref_26_real_bff0000000000000]
    xorpd  xmm9,xmm9
    {disp32} jmp    at_1_0a91
at_1_052c:
    mov    eax,0x32
    mov    QWORD PTR [rsp+0x68],rax
    xor    edi,edi
at_1_0538:
    mov    rax,QWORD PTR [rsp+0x50]
    lea    r15,[rbx+rax*8]
    mov    rcx,QWORD PTR [rsp+0x1c8]
    mov    rdx,r13
    mov    r8,r15
    mov    r9,r15
    call   ref_57_DL7SVN
    ucomisd xmm0,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    {disp32} jae    at_1_0670
    movsd  xmm1,QWORD PTR [r14]
    mulsd  xmm0,xmm0
    mulsd  xmm0,QWORD PTR [rip + ref_49_DG7QTS_BIG]
    ucomisd xmm1,xmm0
    {disp32} jb     at_1_0670
    movsd  QWORD PTR [rsp+0x40],xmm8
    xorpd  xmm11,xmm11
at_1_058c:
    mov    rax,QWORD PTR [rsp+0x1c8]
    mov    rax,QWORD PTR [rax]
    test   rax,rax
    jle    at_1_0607
    mov    ecx,0x1
    xor    edx,edx
    movapd xmm0,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    xor    r8d,r8d
    jmp    at_1_05c4
at_1_05b0:
    movsd  QWORD PTR [rbx+rcx*8-0x8],xmm1
    inc    r8
    inc    rcx
    inc    rdx
    cmp    rdx,rax
    je     at_1_0607
at_1_05c4:
    xorpd  xmm1,xmm1
    cmp    rcx,0x1
    je     at_1_05b0
    lea    r9,[rsi+r8*8]
    xor    r10d,r10d
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_05e0:
    movsd  xmm2,QWORD PTR [r9+r10*8]
    andpd  xmm2,xmm0
    addsd  xmm1,xmm2
    addsd  xmm2,QWORD PTR [rbx+r10*8]
    movsd  QWORD PTR [rbx+r10*8],xmm2
    inc    r10
    cmp    rdx,r10
    jne    at_1_05e0
    add    r8,rdx
    jmp    at_1_05b0
at_1_0607:
    lea    rcx,[rbp+0x7]
    movsd  xmm0,QWORD PTR [rbx+rbp*8+0x38]
    movsd  xmm1,QWORD PTR [rbx]
    movapd xmm2,xmm0
    subsd  xmm2,xmm1
    mov    edx,0x1
    cmp    rax,0x2
    {disp32} jl     at_1_0719
    lea    r8,[rax-0x1]
    lea    r9,[rbx+rbp*8]
    add    r9,0x40
    xor    r10d,r10d
    jmp    at_1_064c
    nop    DWORD PTR [rax]
at_1_0640:
    inc    r10
    cmp    r8,r10
    {disp32} je     at_1_0713
at_1_064c:
    mov    r11,rdx
    lea    rdx,[r10+0x2]
    movsd  xmm1,QWORD PTR [r9+r10*8]
    subsd  xmm1,QWORD PTR [rbx+r10*8+0x8]
    ucomisd xmm1,xmm2
    cmovae rdx,r11
    jae    at_1_0640
    movapd xmm2,xmm1
    jmp    at_1_0640
at_1_0670:
    mov    QWORD PTR [rsp+0x90],r12
    mov    r12,QWORD PTR [rsp+0x1c8]
    mov    rcx,r12
    mov    rdx,r15
    mov    r8,r13
    mov    r9,QWORD PTR [rsp+0x58]
    call   ref_58_DL7IVM
    mov    rcx,r12
    mov    rdx,r15
    mov    r8,r15
    call   ref_59_DD7TPR
    movapd xmm13,xmm0
    movsd  xmm0,QWORD PTR [rip + ref_32_real_3fe0000000000000]
    mulsd  xmm0,xmm13
    movsd  QWORD PTR [r14+0x28],xmm0
    mov    rcx,r12
    mov    rdx,r15
    mov    r8,r13
    mov    r9,r15
    call   ref_56_DL7ITV
    mov    rcx,r12
    mov    rdx,r15
    call   ref_52_DV2NRM
    movapd xmm10,xmm0
    movsd  QWORD PTR [r14+0x10],xmm0
    movapd xmm12,xmm0
    subsd  xmm12,xmm14
    movsd  xmm0,QWORD PTR [rsp+0x70]
    ucomisd xmm0,xmm12
    {disp32} jb     at_1_0a27
    movsd  xmm12,QWORD PTR [rip + ref_26_real_bff0000000000000]
    xorpd  xmm15,xmm15
    xorpd  xmm11,xmm11
    {disp32} jmp    at_1_107b
at_1_0713:
    movsd  xmm1,QWORD PTR [rbx+rdx*8-0x8]
at_1_0719:
    lea    r8,[rdx+rcx*1]
    movsd  xmm2,QWORD PTR [rbx+r8*8-0x8]
    xorpd  xmm3,xmm3
    xorpd  xmm4,xmm4
    test   rax,rax
    {disp32} jle    at_1_07ee
    lea    r8,[rdx-0x1]
    mov    r9,r8
    imul   r9,rdx
    shr    r9,1
    inc    r9
    lea    r10,[rbx+rbp*8]
    add    r10,0x38
    mov    r11d,0x1
    xor    r14d,r14d
    movapd xmm5,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm6,QWORD PTR [rip + ref_32_real_3fe0000000000000]
    jmp    at_1_0786
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0770:
    cmp    r15,rdx
    cmovge r11,r15
    movapd xmm4,xmm7
at_1_077b:
    add    r9,r11
    mov    r14,r15
    cmp    rax,r15
    je     at_1_07ee
at_1_0786:
    lea    r15,[r14+0x1]
    cmp    r8,r14
    jne    at_1_07a0
    mov    r11,rdx
    jmp    at_1_077b
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07a0:
    movsd  xmm7,QWORD PTR [rsi+r9*8-0x8]
    andpd  xmm7,xmm5
    movapd xmm8,xmm2
    subsd  xmm8,QWORD PTR [r10+r14*8]
    addsd  xmm8,QWORD PTR [rbx+r14*8]
    subsd  xmm8,xmm7
    mulsd  xmm8,xmm6
    movapd xmm9,xmm8
    mulsd  xmm9,xmm8
    mulsd  xmm7,xmm1
    addsd  xmm7,xmm9
    sqrtsd xmm7,xmm7
    addsd  xmm7,xmm8
    ucomisd xmm7,xmm4
    ja     at_1_0770
    movapd xmm7,xmm4
    jmp    at_1_0770
at_1_07ee:
    subsd  xmm2,xmm4
    movsd  QWORD PTR [rbx+rbp*8+0x10],xmm2
    mov    rdx,QWORD PTR [rsp+0x1d8]
    movsd  xmm1,QWORD PTR [rdx]
    movapd xmm8,xmm1
    divsd  xmm8,xmm14
    ucomisd xmm3,xmm1
    subsd  xmm8,xmm2
    setp   dl
    setne  r8b
    or     r8b,dl
    jne    at_1_0842
    movsd  xmm2,QWORD PTR [rip + ref_29_real_3f50624dd2f1a9fc]
    movapd xmm3,xmm8
    addsd  xmm3,xmm2
    mulsd  xmm2,xmm8
    addsd  xmm2,xmm3
    movapd xmm8,xmm2
at_1_0842:
    xorpd  xmm2,xmm2
    ucomisd xmm2,xmm8
    jb     at_1_0856
    movsd  xmm8,QWORD PTR [rip + ref_29_real_3f50624dd2f1a9fc]
at_1_0856:
    movsd  xmm2,QWORD PTR [rbx]
    addsd  xmm0,xmm2
    mov    edx,0x1
    cmp    rax,0x2
    jl     at_1_08b2
    lea    r8,[rax-0x1]
    lea    r9,[rbx+rbp*8]
    add    r9,0x40
    xor    r10d,r10d
    jmp    at_1_0888
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0880:
    inc    r10
    cmp    r8,r10
    je     at_1_08ac
at_1_0888:
    mov    r11,rdx
    lea    rdx,[r10+0x2]
    movsd  xmm2,QWORD PTR [r9+r10*8]
    addsd  xmm2,QWORD PTR [rbx+r10*8+0x8]
    ucomisd xmm0,xmm2
    cmovae rdx,r11
    jae    at_1_0880
    movapd xmm0,xmm2
    jmp    at_1_0880
at_1_08ac:
    movsd  xmm2,QWORD PTR [rbx+rdx*8-0x8]
at_1_08b2:
    add    rcx,rdx
    movsd  xmm0,QWORD PTR [rbx+rcx*8-0x8]
    xorpd  xmm9,xmm9
    xorpd  xmm3,xmm3
    test   rax,rax
    {disp32} jle    at_1_098a
    lea    rcx,[rdx-0x1]
    mov    r8,rcx
    imul   r8,rdx
    shr    r8,1
    inc    r8
    lea    r9,[rbx+rbp*8]
    add    r9,0x38
    mov    r10d,0x1
    xor    r14d,r14d
    movapd xmm4,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm5,QWORD PTR [rip + ref_32_real_3fe0000000000000]
    jmp    at_1_0926
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0910:
    cmp    r11,rdx
    cmovge r10,r11
    movapd xmm3,xmm6
at_1_091b:
    add    r8,r10
    mov    r14,r11
    cmp    rax,r11
    je     at_1_098a
at_1_0926:
    lea    r11,[r14+0x1]
    cmp    rcx,r14
    jne    at_1_0940
    mov    r10,rdx
    jmp    at_1_091b
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0940:
    movsd  xmm6,QWORD PTR [rsi+r8*8-0x8]
    movsd  xmm7,QWORD PTR [r9+r14*8]
    addsd  xmm7,QWORD PTR [rbx+r14*8]
    andpd  xmm6,xmm4
    subsd  xmm7,xmm6
    subsd  xmm7,xmm0
    mulsd  xmm7,xmm5
    movapd xmm10,xmm7
    mulsd  xmm10,xmm7
    mulsd  xmm6,xmm2
    addsd  xmm6,xmm10
    sqrtsd xmm6,xmm6
    addsd  xmm6,xmm7
    ucomisd xmm6,xmm3
    ja     at_1_0910
    movapd xmm6,xmm3
    jmp    at_1_0910
at_1_098a:
    addsd  xmm0,xmm3
    movsd  QWORD PTR [rbx+rbp*8+0x8],xmm0
    divsd  xmm1,xmm14
    subsd  xmm1,xmm0
    maxsd  xmm11,xmm1
    mov    r14,QWORD PTR [rsp+0x1d8]
    movsd  xmm0,QWORD PTR [r14+0x20]
    andpd  xmm0,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    mulsd  xmm0,QWORD PTR [r14+0x40]
    divsd  xmm0,xmm14
    maxsd  xmm0,xmm11
    movapd xmm15,xmm8
    minsd  xmm15,xmm0
    cmp    QWORD PTR [rsp+0x38],0x0
    {disp32} jne    at_1_0a91
    mov    rax,QWORD PTR [rsp+0x50]
    lea    r9,[rbx+rax*8]
    mov    r15,QWORD PTR [rsp+0x1c8]
    mov    rcx,r15
    mov    rdx,rbx
    mov    r8,r13
    call   ref_58_DL7IVM
    mov    rcx,r15
    mov    rdx,rbx
    call   ref_52_DV2NRM
    movapd xmm1,xmm14
    divsd  xmm1,xmm0
    divsd  xmm1,xmm0
    movsd  QWORD PTR [rbx+rbp*8+0x20],xmm1
    mulsd  xmm12,xmm1
    maxsd  xmm11,xmm12
    jmp    at_1_0a91
at_1_0a27:
    movsd  QWORD PTR [rsp+0x40],xmm8
    xorpd  xmm11,xmm11
    test   BYTE PTR [rsp+0x90],0x1
    {disp32} je     at_1_058c
    movsd  xmm8,QWORD PTR [rip + ref_26_real_bff0000000000000]
    xorpd  xmm9,xmm9
    jmp    at_1_0a91
at_1_0a51:
    xorpd  xmm9,xmm9
    xorpd  xmm11,xmm11
    test   al,al
    je     at_1_0a66
    movsd  xmm11,QWORD PTR [rbx+rbp*8+0x18]
at_1_0a66:
    subsd  xmm1,QWORD PTR [rbx+rbp*8+0x8]
    maxsd  xmm11,xmm1
    ucomisd xmm0,xmm9
    {disp32} jbe    at_1_0fe7
at_1_0a7c:
    subsd  xmm0,xmm14
    mulsd  xmm0,QWORD PTR [rbx+rbp*8+0x20]
    maxsd  xmm11,xmm0
    {disp32} jmp    at_1_0fe7
at_1_0a91:
    mov    rax,QWORD PTR [rsp+0x30]
    movsd  xmm0,QWORD PTR [r14+0x10]
    lea    r12,[rbx+rbp*8]
    add    r12,0x38
    movapd xmm7,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    movsd  xmm10,QWORD PTR [rip + ref_29_real_3f50624dd2f1a9fc]
    xorpd  xmm13,xmm13
    movsd  xmm6,QWORD PTR [rip + ref_32_real_3fe0000000000000]
    lea    rbp,[rsp+0x38]
    lea    r15,[rip + ref_53_unnamed_2]
    movapd xmm12,xmm8
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0ae0:
    inc    rdi
    mov    QWORD PTR [rax],rdi
    ucomisd xmm11,xmm15
    seta   cl
    ucomisd xmm15,xmm12
    xorpd  xmm0,xmm7
    setae  al
    ucomisd xmm0,xmm15
    jae    at_1_0b09
    test   cl,cl
    jne    at_1_0b09
    test   al,al
    je     at_1_0b26
at_1_0b09:
    movapd xmm0,xmm11
    divsd  xmm0,xmm12
    xorps  xmm15,xmm15
    sqrtsd xmm15,xmm0
    maxsd  xmm15,xmm10
    mulsd  xmm15,xmm12
at_1_0b26:
    ucomisd xmm13,xmm15
    movapd xmm0,xmm15
    jb     at_1_0b3b
    movapd xmm0,xmm12
    mulsd  xmm0,xmm6
at_1_0b3b:
    ucomisd xmm13,xmm0
    movapd xmm15,xmm12
    jae    at_1_0b4c
    movapd xmm15,xmm0
at_1_0b4c:
    mov    rax,QWORD PTR [rsp+0x1c8]
    mov    rax,QWORD PTR [rax]
    test   rax,rax
    jle    at_1_0b83
    xor    edx,edx
    xor    ecx,ecx
at_1_0b60:
    add    rcx,rdx
    inc    rcx
    movsd  xmm0,QWORD PTR [r12+rdx*8]
    lea    r8,[rdx+0x1]
    addsd  xmm0,xmm15
    movsd  QWORD PTR [rsi+rcx*8-0x8],xmm0
    mov    rdx,r8
    cmp    rax,r8
    jne    at_1_0b60
at_1_0b83:
    mov    QWORD PTR [rsp+0x20],rbp
    mov    rcx,r15
    mov    rdx,QWORD PTR [rsp+0x1c8]
    mov    r8,r13
    mov    r9,rsi
    call   ref_54_DL7SRT
    mov    r14,QWORD PTR [rsp+0x38]
    test   r14,r14
    {disp32} je     at_1_0cce
    lea    rax,[r14+0x1]
    imul   rax,r14
    and    rax,0xfffffffffffffffe
    movsd  xmm8,QWORD PTR [r13+rax*4-0x8]
    movabs rcx,0x3ff0000000000000
    mov    QWORD PTR [r13+rax*4-0x8],rcx
    test   r14,r14
    jle    at_1_0c10
    cmp    r14,0xd
    jb     at_1_0bf0
    lea    r8,[r14*8+0x0]
    mov    rcx,rbx
    xor    edx,edx
    call   ref_55_intel_fast_memset
    jmp    at_1_0c10
    nop    DWORD PTR [rax]
at_1_0bf0:
    xor    eax,eax
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0c00:
    mov    QWORD PTR [rbx+rax*8],0x0
    inc    rax
    cmp    r14,rax
    jne    at_1_0c00
at_1_0c10:
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rbx+r14*8-0x8],rax
    mov    rcx,rbp
    mov    rdx,rbx
    mov    r8,r13
    mov    r9,rbx
    call   ref_56_DL7ITV
    mov    rcx,rbp
    mov    rdx,rbx
    call   ref_52_DV2NRM
    divsd  xmm8,xmm0
    divsd  xmm8,xmm0
    movapd xmm11,xmm15
    subsd  xmm11,xmm8
    movapd xmm0,xmm11
    xorpd  xmm0,xmm7
    mov    rax,QWORD PTR [rsp+0x1d8]
    movlpd QWORD PTR [rax+0x10],xmm0
    ucomisd xmm11,xmm12
    movapd xmm1,xmm11
    ja     at_1_0c76
    movapd xmm1,xmm12
at_1_0c76:
    ucomisd xmm11,xmm15
    movapd xmm12,xmm1
    mov    rax,QWORD PTR [rsp+0x30]
    {disp32} ja     at_1_0ae0
    movapd xmm3,xmm10
    mulsd  xmm3,xmm15
    ucomisd xmm13,xmm3
    movapd xmm2,xmm10
    jae    at_1_0ca5
    movapd xmm2,xmm3
at_1_0ca5:
    movapd xmm11,xmm15
    addsd  xmm11,xmm2
    ucomisd xmm11,xmm1
    movapd xmm12,xmm1
    {disp32} jb     at_1_0ae0
    addsd  xmm2,xmm11
    movapd xmm12,xmm2
    {disp32} jmp    at_1_0ae0
at_1_0cce:
    mov    rax,QWORD PTR [rsp+0x50]
    lea    rbp,[rbx+rax*8]
    mov    r14,QWORD PTR [rsp+0x1c8]
    mov    rcx,r14
    mov    rdx,rbp
    mov    r8,r13
    mov    r9,QWORD PTR [rsp+0x58]
    call   ref_58_DL7IVM
    mov    rcx,r14
    mov    rdx,rbp
    mov    r8,rbp
    call   ref_59_DD7TPR
    movapd xmm13,xmm0
    mov    rcx,r14
    mov    rdx,rbp
    mov    r8,r13
    mov    r9,rbp
    call   ref_56_DL7ITV
    mov    rcx,r14
    mov    rdx,rbp
    call   ref_52_DV2NRM
    movapd xmm10,xmm0
    movapd xmm7,xmm0
    subsd  xmm7,xmm14
    ucomisd xmm7,QWORD PTR [rsp+0xa8]
    setae  al
    movsd  xmm0,QWORD PTR [rsp+0x70]
    ucomisd xmm0,xmm7
    jb     at_1_0d4f
    test   al,al
    {disp32} jne    at_1_106e
at_1_0d4f:
    ucomisd xmm7,xmm9
    setnp  al
    sete   cl
    test   cl,al
    mov    r14,QWORD PTR [rsp+0x1d8]
    {disp32} jne    at_1_1076
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm7
    jbe    at_1_0dd2
    movsd  xmm8,QWORD PTR [r14+0x10]
    minsd  xmm8,xmm0
    addsd  xmm8,xmm15
    movapd xmm14,xmm15
    mulsd  xmm14,xmm10
    mulsd  xmm14,xmm10
    addsd  xmm14,xmm13
    cmp    rdi,QWORD PTR [rsp+0x60]
    jge    at_1_0ddc
    movsd  xmm0,QWORD PTR [rsp+0x40]
    ucomisd xmm0,QWORD PTR [rip + ref_49_DG7QTS_BIG]
    jae    at_1_0ddc
    movsd  xmm0,QWORD PTR [rsp+0x40]
    mulsd  xmm0,xmm14
    ucomisd xmm8,xmm0
    jb     at_1_0ddc
    mov    rbp,QWORD PTR [rsp+0x28]
    movsd  xmm14,QWORD PTR [rsp+0x48]
    {disp32} jmp    at_1_0f91
at_1_0dd2:
    mov    rbp,QWORD PTR [rsp+0x28]
    {disp32} jmp    at_1_0fd7
at_1_0ddc:
    movapd XMMWORD PTR [rsp+0x90],xmm13
    mov    rax,QWORD PTR [rsp+0x28]
    mov    rcx,QWORD PTR [rsp+0x50]
    add    rax,rcx
    lea    r15,[rbx+rax*8]
    mov    r12,QWORD PTR [rsp+0x1c8]
    mov    rcx,r12
    mov    rdx,r13
    mov    r8,r15
    mov    r9,rbx
    call   ref_57_DL7SVN
    movapd xmm9,xmm0
    mov    rax,QWORD PTR [r12]
    test   rax,rax
    jle    at_1_0e37
    xor    ecx,ecx
at_1_0e20:
    movsd  xmm0,QWORD PTR [rbx+rcx*8]
    mulsd  xmm0,xmm9
    movsd  QWORD PTR [rbx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0e20
at_1_0e37:
    movsd  QWORD PTR [rsp+0x88],xmm8
    mov    r12,QWORD PTR [rsp+0x1c8]
    mov    rcx,r12
    mov    rdx,rbx
    mov    r8,r13
    mov    r9,rbx
    call   ref_56_DL7ITV
    mov    rcx,r12
    mov    rdx,rbx
    call   ref_52_DV2NRM
    movsd  xmm13,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    divsd  xmm13,xmm0
    mov    rax,QWORD PTR [r12]
    test   rax,rax
    jle    at_1_0e97
    xor    ecx,ecx
    xchg   ax,ax
at_1_0e80:
    movsd  xmm0,QWORD PTR [rbx+rcx*8]
    mulsd  xmm0,xmm13
    movsd  QWORD PTR [rbx+rcx*8],xmm0
    inc    rcx
    cmp    rax,rcx
    jne    at_1_0e80
at_1_0e97:
    mulsd  xmm9,xmm13
    mov    rcx,QWORD PTR [rsp+0x1c8]
    mov    rdx,rbp
    mov    r8,rbx
    call   ref_59_DD7TPR
    movsd  xmm8,QWORD PTR [rsp+0x48]
    movapd xmm1,xmm8
    addsd  xmm1,xmm10
    subsd  xmm8,xmm10
    mulsd  xmm8,xmm1
    movapd xmm1,xmm0
    mulsd  xmm1,xmm0
    addsd  xmm1,xmm8
    sqrtsd xmm1,xmm1
    xorpd  xmm2,xmm2
    ucomisd xmm2,xmm0
    movapd xmm2,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    xorpd  xmm2,xmm1
    ja     at_1_0ef5
    movapd xmm2,xmm1
at_1_0ef5:
    movapd xmm1,xmm0
    addsd  xmm1,xmm2
    divsd  xmm8,xmm1
    movapd xmm1,xmm13
    mulsd  xmm1,xmm8
    mulsd  xmm1,xmm1
    movapd xmm2,xmm10
    mulsd  xmm2,xmm10
    movapd xmm3,xmm15
    mulsd  xmm3,QWORD PTR [rsp+0xa0]
    addsd  xmm3,xmm2
    mulsd  xmm3,QWORD PTR [rsp+0x80]
    ucomisd xmm3,xmm1
    {disp32} jae    at_1_11da
    movsd  xmm0,QWORD PTR [r14+0x10]
    xorpd  xmm1,xmm1
    ucomisd xmm1,xmm0
    jb     at_1_0f64
    mulsd  xmm13,xmm13
    subsd  xmm13,xmm15
    minsd  xmm0,xmm13
    movsd  QWORD PTR [r14+0x10],xmm0
at_1_0f64:
    mov    rbp,QWORD PTR [rsp+0x28]
    movsd  xmm14,QWORD PTR [rsp+0x48]
    movapd xmm13,XMMWORD PTR [rsp+0x90]
    movsd  xmm8,QWORD PTR [rsp+0x88]
    xorpd  xmm0,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    maxsd  xmm11,xmm0
at_1_0f91:
    movsd  xmm0,QWORD PTR [rip + ref_60_DG7QTS_DGXFAC]
    xorpd  xmm1,xmm1
    ucomisd xmm1,xmm0
    setp   al
    setne  cl
    or     cl,al
    jne    at_1_0fc7
    lea    rcx,[rip + ref_61_unnamed_3]
    call   ref_51_DR7MDC
    mulsd  xmm0,QWORD PTR [rip + ref_35_real_4049000000000000]
    movsd  QWORD PTR [rip + ref_60_DG7QTS_DGXFAC],xmm0
at_1_0fc7:
    mulsd  xmm0,QWORD PTR [rbx+rbp*8]
    ucomisd xmm8,xmm0
    {disp32} jbe    at_1_107b
at_1_0fd7:
    movapd xmm9,xmm7
    cmp    rdi,QWORD PTR [rsp+0x68]
    {disp32} jge    at_1_107b
at_1_0fe7:
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm7
    movapd xmm8,xmm12
    minsd  xmm8,xmm15
    ja     at_1_1000
    movapd xmm8,xmm12
at_1_1000:
    cmp    QWORD PTR [rsp+0x60],0x0
    je     at_1_1062
    mov    rax,QWORD PTR [rsp+0x50]
    lea    r9,[rbx+rax*8]
    mov    r15,QWORD PTR [rsp+0x1c8]
    mov    rcx,r15
    mov    rdx,rbx
    mov    r8,r13
    call   ref_58_DL7IVM
    mov    rcx,r15
    mov    rdx,rbx
    call   ref_52_DV2NRM
    divsd  xmm7,xmm0
    movapd xmm1,xmm10
    divsd  xmm1,xmm0
    divsd  xmm10,xmm14
    mulsd  xmm10,xmm1
    mulsd  xmm10,xmm7
    addsd  xmm15,xmm10
    maxsd  xmm11,xmm15
    movapd xmm15,xmm11
    {disp32} jmp    at_1_0a91
at_1_1062:
    xor    eax,eax
    mov    QWORD PTR [rsp+0x60],rax
    {disp32} jmp    at_1_0a91
at_1_106e:
    mov    r14,QWORD PTR [rsp+0x1d8]
at_1_1076:
    mov    rbp,QWORD PTR [rsp+0x28]
at_1_107b:
    mov    rax,QWORD PTR [rsp+0x1c8]
    mov    rax,QWORD PTR [rax]
    test   rax,rax
    mov    r8,QWORD PTR [rsp+0x78]
    mov    r9,QWORD PTR [rsp+0x1d0]
    jle    at_1_10cd
    mov    rcx,rbp
    shl    rcx,0x4
    add    rcx,rbx
    add    rcx,0x38
    xor    edx,edx
    movapd xmm0,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
at_1_10b0:
    movsd  xmm1,QWORD PTR [rcx+rdx*8]
    divsd  xmm1,QWORD PTR [r8+rdx*8]
    xorpd  xmm1,xmm0
    movlpd QWORD PTR [r9+rdx*8],xmm1
    inc    rdx
    cmp    rax,rdx
    jne    at_1_10b0
at_1_10cd:
    movapd xmm0,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    xorpd  xmm0,xmm13
    movlpd QWORD PTR [r14+0x18],xmm0
    movapd xmm0,XMMWORD PTR [rip + ref_20_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm0,xmm15
    movapd xmm1,xmm10
    mulsd  xmm1,xmm10
    mulsd  xmm1,xmm0
    addsd  xmm1,xmm13
    mulsd  xmm1,QWORD PTR [rip + ref_32_real_3fe0000000000000]
    movsd  QWORD PTR [r14+0x30],xmm1
at_1_110e:
    movsd  QWORD PTR [r14+0x8],xmm10
    movsd  QWORD PTR [r14+0x20],xmm15
    movsd  QWORD PTR [rbx+rbp*8+0x18],xmm11
    movsd  QWORD PTR [rbx+rbp*8+0x28],xmm12
    movsd  QWORD PTR [r14+0x40],xmm14
    movsd  QWORD PTR [rbx+rbp*8+0x30],xmm10
    test   rax,rax
    jle    at_1_116e
    lea    rcx,[rbx+rbp*8]
    add    rcx,0x38
    xor    edx,edx
    xor    r8d,r8d
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_1150:
    add    r8,rdx
    inc    r8
    movsd  xmm0,QWORD PTR [rcx+rdx*8]
    lea    r9,[rdx+0x1]
    movsd  QWORD PTR [rsi+r8*8-0x8],xmm0
    mov    rdx,r9
    cmp    rax,r9
    jne    at_1_1150
at_1_116e:
    movaps xmm6,XMMWORD PTR [rsp+0xb0]
    movaps xmm7,XMMWORD PTR [rsp+0xc0]
    movaps xmm8,XMMWORD PTR [rsp+0xd0]
    movaps xmm9,XMMWORD PTR [rsp+0xe0]
    movaps xmm10,XMMWORD PTR [rsp+0xf0]
    movaps xmm11,XMMWORD PTR [rsp+0x100]
    movaps xmm12,XMMWORD PTR [rsp+0x110]
    movaps xmm13,XMMWORD PTR [rsp+0x120]
    movaps xmm14,XMMWORD PTR [rsp+0x130]
    movaps xmm15,XMMWORD PTR [rsp+0x140]
    add    rsp,0x158
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_11da:
    movapd xmm7,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    xorpd  xmm7,xmm15
    movapd xmm1,xmm6
    mulsd  xmm1,xmm14
    movsd  QWORD PTR [r14+0x30],xmm1
    movapd xmm13,xmm7
    mulsd  xmm13,xmm0
    mov    rcx,QWORD PTR [rsp+0x1c8]
    mov    rdx,r15
    mov    r8,rbx
    call   ref_59_DD7TPR
    mulsd  xmm9,xmm0
    subsd  xmm9,xmm15
    mulsd  xmm9,xmm6
    mulsd  xmm9,xmm8
    subsd  xmm13,xmm9
    movsd  xmm1,QWORD PTR [rsp+0x80]
    mulsd  xmm1,xmm14
    divsd  xmm1,QWORD PTR [rip + ref_38_real_4018000000000000]
    mulsd  xmm13,xmm8
    xorpd  xmm0,xmm0
    ucomisd xmm1,xmm13
    movsd  xmm14,QWORD PTR [rsp+0x48]
    ja     at_1_1278
    addsd  xmm13,QWORD PTR [r14+0x30]
    movsd  QWORD PTR [r14+0x30],xmm13
    xorpd  xmm8,XMMWORD PTR [rip + ref_23_xmm_80000000000000008000000000000000]
    movapd xmm10,xmm14
    movapd xmm0,xmm8
at_1_1278:
    mov    rax,QWORD PTR [rsp+0x1c8]
    mov    rax,QWORD PTR [rax]
    test   rax,rax
    mov    r8,QWORD PTR [rsp+0x78]
    mov    r9,QWORD PTR [rsp+0x1d0]
    jle    at_1_12d7
    mov    rcx,QWORD PTR [rsp+0x28]
    shl    rcx,0x4
    add    rcx,rbx
    add    rcx,0x38
    xor    edx,edx
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_12b0:
    movsd  xmm1,QWORD PTR [rbx+rdx*8]
    mulsd  xmm1,xmm0
    subsd  xmm1,QWORD PTR [rcx+rdx*8]
    movsd  QWORD PTR [rcx+rdx*8],xmm1
    divsd  xmm1,QWORD PTR [r8+rdx*8]
    movsd  QWORD PTR [r9+rdx*8],xmm1
    inc    rdx
    cmp    rax,rdx
    jne    at_1_12b0
at_1_12d7:
    mov    rdi,QWORD PTR [rsp+0x1c8]
    mov    rcx,rdi
    mov    rdx,QWORD PTR [rsp+0x58]
    mov    r8,rbp
    call   ref_59_DD7TPR
    movsd  QWORD PTR [r14+0x18],xmm0
    mov    rax,QWORD PTR [rdi]
    movapd xmm15,xmm7
    mov    rbp,QWORD PTR [rsp+0x28]
    {disp32} jmp    at_1_110e
at_1_1307:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_60_DG7QTS_DGXFAC:
at_3_0000:
    .zero 8
def_49_DG7QTS_BIG:
at_3_0008:
    .zero 8
at_3_0010:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_4000000000000000:
at_4_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_4010000000000000:
at_6_0000:
    .quad 0x4010000000000000    # binary64 4.0
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_real_4008000000000000:
at_7_0000:
    .quad 0x4008000000000000    # binary64 3.0
at_7_0008:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_xmm_7fffffffffffffff7fffffffffffffff:
at_8_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_8_0010:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_xmm_80000000000000008000000000000000:
at_9_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_9_0010:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_24_rdata:
def_26_real_bff0000000000000:
at_10_0000:
    .quad 0xbff0000000000000    # binary64 -1.0
at_10_0008:
end_s10:

# .rdata  (COFF section 11)
.section .s11,"dr"
def_27_rdata:
def_29_real_3f50624dd2f1a9fc:
at_11_0000:
    .quad 0x3f50624dd2f1a9fc    # binary64 0.001
at_11_0008:
end_s11:

# .rdata  (COFF section 12)
.section .s12,"dr"
def_30_rdata:
def_32_real_3fe0000000000000:
at_12_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_12_0008:
end_s12:

# .rdata  (COFF section 13)
.section .s13,"dr"
def_33_rdata:
def_35_real_4049000000000000:
at_13_0000:
    .quad 0x4049000000000000    # binary64 50.0
at_13_0008:
end_s13:

# .rdata  (COFF section 14)
.section .s14,"dr"
def_36_rdata:
def_38_real_4018000000000000:
at_14_0000:
    .quad 0x4018000000000000    # binary64 6.0
at_14_0008:
end_s14:

# .xdata  (COFF section 15)
.section .s15,"dr"
def_39_xdata:
at_15_0000:
    .byte 0x01    # version 1
    .byte at_1_0073 - at_1_0000    # prologue size
    .byte 0x1e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0073 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0b
    .byte 0x00
    .byte at_1_006a - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x0c
    .byte 0x00
    .byte at_1_0061 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x0d
    .byte 0x00
    .byte at_1_0058 - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x0e
    .byte 0x00
    .byte at_1_004e - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x0f
    .byte 0x00
    .byte at_1_0044 - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x10
    .byte 0x00
    .byte at_1_003a - at_1_0000    # SAVE_XMM128
    .byte 0xc8
    .byte 0x11
    .byte 0x00
    .byte at_1_0030 - at_1_0000    # SAVE_XMM128
    .byte 0xd8
    .byte 0x12
    .byte 0x00
    .byte at_1_0026 - at_1_0000    # SAVE_XMM128
    .byte 0xe8
    .byte 0x13
    .byte 0x00
    .byte at_1_001d - at_1_0000    # SAVE_XMM128
    .byte 0xf8
    .byte 0x14
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x2b
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_15_0040:
end_s15:

# .rdata  (COFF section 16)
.section .s16,"dr"
def_41_rdata:
def_50_unnamed_1:
at_16_0000:
    .quad 0x0000000000000006
def_53_unnamed_2:
at_16_0008:
    .quad 0x0000000000000001
def_61_unnamed_3:
at_16_0010:
    .quad 0x0000000000000003
at_16_0018:
end_s16:

# .drectve  (COFF section 17)
.section .s17,"dr"
def_43_drectve:
at_17_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_17_00b9:
end_s17:

# .pdata  (COFF section 18)
.section .s18,"dr"
def_45_pdata:
at_18_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_1307 - def_0_text)    # image-relative end
    .long ref_39_xdata    # image-relative unwind info
at_18_000c:
end_s18:

# MEMBER dg7qsb.obj
# Entry points: DG7QSB
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_15_DG7QSB:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x138
at_1_0013:
    movaps XMMWORD PTR [rsp+0x120],xmm9
at_1_001c:
    movaps XMMWORD PTR [rsp+0x110],xmm8
at_1_0025:
    movaps XMMWORD PTR [rsp+0x100],xmm7
at_1_002d:
    movaps XMMWORD PTR [rsp+0xf0],xmm6
at_1_0035:
    mov    QWORD PTR [rsp+0x98],r9
    mov    QWORD PTR [rsp+0xa8],r8
    mov    QWORD PTR [rsp+0xa0],rdx
    mov    QWORD PTR [rsp+0xe0],rcx
    mov    rbp,QWORD PTR [rsp+0x200]
    mov    rcx,QWORD PTR [rsp+0x1d8]
    mov    r13,QWORD PTR [rsp+0x1d0]
    mov    rdx,QWORD PTR [rsp+0x1b8]
    mov    rax,QWORD PTR [rsp+0x1e0]
    mov    rbx,QWORD PTR [r13+0x0]
    mov    rdi,QWORD PTR [rax]
    mov    QWORD PTR [rsp+0xd0],rdi
    mov    r14,QWORD PTR [rdx]
    test   r14,r14
    js     at_1_00a3
    movsd  xmm6,QWORD PTR [rbp+0x10]
    movsd  xmm7,QWORD PTR [rbp+0x28]
    mov    rsi,QWORD PTR [rcx]
    jmp    at_1_00ba
at_1_00a3:
    mov    QWORD PTR [rcx],0x0
    mov    QWORD PTR [rdx],0xffffffffffffffff
    mov    r14,0xffffffffffffffff
    xor    esi,esi
at_1_00ba:
    mov    r15,QWORD PTR [rsp+0x1e8]
    mov    rcx,r13
    mov    rdx,QWORD PTR [rsp+0x210]
    mov    r8,QWORD PTR [rsp+0x218]
    call   ref_16_DV7CPY
    movsd  xmm8,QWORD PTR [rip + ref_17_DG7QSB_ZERO]
    movsd  xmm9,QWORD PTR [rbp+0x38]
    mov    QWORD PTR [rsp+0xc0],0xffffffffffffffff
    movsd  QWORD PTR [rbp+0x8],xmm8
    test   rdi,rdi
    {disp32} jle    at_1_03b4
    mov    r12,QWORD PTR [rsp+0x1f0]
    mov    r15,QWORD PTR [rsp+0x1a8]
    mov    rbp,QWORD PTR [rsp+0x1a0]
    shl    rbx,0x3
    cmp    rsi,rdi
    mov    rdi,0xffffffffffffffff
    mov    QWORD PTR [rsp+0xb0],r14
    cmove  rdi,r14
    mov    rcx,r13
    mov    rdx,r12
    mov    rsi,QWORD PTR [rsp+0xa0]
    mov    r8,rsi
    call   ref_16_DV7CPY
    mov    rcx,r13
    mov    r14,rbp
    mov    rdx,rbp
    mov    r8,r12
    call   ref_18_DV7IPR
    lea    rax,[rip + ref_19_unnamed_1]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,r13
    mov    rbp,QWORD PTR [rsp+0x1f8]
    mov    rdx,rbp
    mov    r8,QWORD PTR [rsp+0x98]
    mov    r9,rsi
    call   ref_20_DV7VMP
    mov    rcx,r13
    mov    r13,rbp
    mov    rbp,QWORD PTR [rsp+0x200]
    mov    rdx,r14
    mov    r8,r13
    call   ref_18_DV7IPR
    mov    r8,QWORD PTR [rsp+0x1e8]
    add    rbx,r8
    mov    QWORD PTR [rsp+0xd8],rbx
    lea    rax,[rsp+0xd0]
    jmp    at_1_01e7
    nop    DWORD PTR [rax]
at_1_01c0:
    mov    rdi,0xffffffffffffffff
    cmp    QWORD PTR [rsp+0xc0],0x0
    mov    r8,rsi
    mov    r13,rbp
    mov    rbp,QWORD PTR [rsp+0x200]
    mov    rax,rbx
    {disp32} jg     at_1_03d3
at_1_01e7:
    mov    r14,r15
    mov    QWORD PTR [rsp+0xb8],rdi
    movapd xmm0,xmm9
    subsd  xmm0,QWORD PTR [rbp+0x8]
    movsd  QWORD PTR [rbp+0x38],xmm0
    mov    rsi,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rsp+0x40],rsi
    mov    QWORD PTR [rsp+0x38],rbp
    mov    QWORD PTR [rsp+0x30],r8
    mov    QWORD PTR [rsp+0x28],rax
    mov    r15,QWORD PTR [rsp+0x1c0]
    mov    QWORD PTR [rsp+0x20],r15
    mov    rcx,r12
    mov    rdx,r13
    mov    rbx,r13
    mov    r13,r8
    mov    r8,QWORD PTR [rsp+0xa8]
    lea    r9,[rsp+0xb8]
    mov    r15,rax
    call   ref_21_DG7QTS
    mov    rax,QWORD PTR [rsp+0xd0]
    mov    rdi,QWORD PTR [rsp+0x1d8]
    mov    QWORD PTR [rdi],rax
    cmp    QWORD PTR [rsp+0xb0],0x0
    jns    at_1_0276
    movsd  xmm6,QWORD PTR [rbp+0x10]
    movsd  xmm7,QWORD PTR [rbp+0x28]
at_1_0276:
    mov    rdx,QWORD PTR [rsp+0xb8]
    mov    rcx,QWORD PTR [rsp+0x1b8]
    mov    QWORD PTR [rsp+0xb0],rdx
    mov    QWORD PTR [rcx],rdx
    movsd  QWORD PTR [rbp+0x38],xmm9
    mov    QWORD PTR [rsp+0xe8],rax
    mov    rax,QWORD PTR [rsp+0x218]
    mov    QWORD PTR [rsp+0x90],rax
    mov    rax,QWORD PTR [rsp+0x210]
    mov    QWORD PTR [rsp+0x88],rax
    mov    QWORD PTR [rsp+0x80],rsi
    mov    QWORD PTR [rsp+0x78],rbp
    mov    rbp,rbx
    mov    QWORD PTR [rsp+0x70],rbx
    mov    QWORD PTR [rsp+0x68],r12
    mov    rsi,r13
    mov    QWORD PTR [rsp+0x60],r13
    mov    rbx,r15
    mov    QWORD PTR [rsp+0x58],r15
    mov    rax,QWORD PTR [rsp+0x1d0]
    mov    QWORD PTR [rsp+0x50],rax
    lea    rax,[rsp+0xc8]
    mov    QWORD PTR [rsp+0x48],rax
    mov    rax,QWORD PTR [rsp+0x1c8]
    mov    QWORD PTR [rsp+0x40],rax
    mov    rax,QWORD PTR [rsp+0x1c0]
    mov    QWORD PTR [rsp+0x38],rax
    lea    rax,[rsp+0xc0]
    mov    QWORD PTR [rsp+0x30],rax
    mov    rax,QWORD PTR [rsp+0x1b0]
    mov    QWORD PTR [rsp+0x28],rax
    mov    r15,r14
    mov    QWORD PTR [rsp+0x20],r14
    mov    rcx,QWORD PTR [rsp+0xe0]
    mov    rdx,QWORD PTR [rsp+0xa0]
    mov    r8,QWORD PTR [rsp+0xd8]
    mov    r9,QWORD PTR [rsp+0x1a0]
    call   ref_22_DS7BQN
    mov    rax,QWORD PTR [rsp+0xc8]
    test   rax,rax
    jle    at_1_0391
    lea    rcx,[rsp+0xe8]
    mov    rdx,r15
    mov    r8,QWORD PTR [rsp+0xa8]
    call   ref_23_DS7IPR
    mov    rax,QWORD PTR [rsp+0xc8]
at_1_0391:
    mov    rcx,QWORD PTR [rsp+0x200]
    addsd  xmm8,QWORD PTR [rcx+0x30]
    test   rax,rax
    {disp32} je     at_1_01c0
    mov    QWORD PTR [rdi],0x0
    {disp32} jmp    at_1_01c0
at_1_03b4:
    lea    r8,[rip + ref_17_DG7QSB_ZERO]
    mov    rcx,r13
    mov    rdx,r15
    call   ref_24_DV7SCP
    movapd xmm6,xmm8
    movapd xmm7,xmm8
    mov    r8,r15
at_1_03d3:
    movsd  QWORD PTR [rbp+0x10],xmm6
    movsd  QWORD PTR [rbp+0x28],xmm7
    movsd  QWORD PTR [rbp+0x30],xmm8
    mov    rcx,QWORD PTR [rsp+0x1d0]
    mov    rdx,QWORD PTR [rsp+0x98]
    call   ref_25_DD7TPR
    movsd  QWORD PTR [rbp+0x18],xmm0
    movaps xmm6,XMMWORD PTR [rsp+0xf0]
    movaps xmm7,XMMWORD PTR [rsp+0x100]
    movaps xmm8,XMMWORD PTR [rsp+0x110]
    movaps xmm9,XMMWORD PTR [rsp+0x120]
    add    rsp,0x138
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0433:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_17_DG7QSB_ZERO:
at_3_0000:
    .zero 8
at_3_0008:
end_s3:

# .xdata  (COFF section 4)
.section .s4,"dr"
def_6_xdata:
at_4_0000:
    .byte 0x01    # version 1
    .byte at_1_0035 - at_1_0000    # prologue size
    .byte 0x12    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0035 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0f
    .byte 0x00
    .byte at_1_002d - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x10
    .byte 0x00
    .byte at_1_0025 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x11
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x12
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x27
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_4_0028:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_8_rdata:
def_19_unnamed_1:
at_5_0000:
    .quad 0xffffffffffffffff
at_5_0008:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_10_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_12_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0433 - def_0_text)    # image-relative end
    .long ref_6_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dg7lit.obj
# Entry points: DG7LIT
.intel_syntax noprefix
# Unconstrained iteration and step selection. The two dispatch tables share the same read-only section.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_30_DG7LIT:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0xc8
at_1_0013:
    movapd XMMWORD PTR [rsp+0xb0],xmm7
at_1_001c:
    movapd XMMWORD PTR [rsp+0xa0],xmm6
at_1_0025:
    mov    rbx,r9
    mov    rsi,r8
    mov    rdi,rdx
    mov    rbp,rcx
    mov    r12,QWORD PTR [rsp+0x148]
    mov    r14,QWORD PTR [rsp+0x138]
    mov    r13,QWORD PTR [rsp+0x130]
    mov    rax,QWORD PTR [r8]
    mov    QWORD PTR [rsp+0x58],rax
    cmp    rax,0x2
    mov    QWORD PTR [rsp+0x68],rdx
    mov    QWORD PTR [rsp+0x60],r9
    je     at_1_0092
    cmp    rax,0x1
    jne    at_1_00ce
    cmp    QWORD PTR [rsi+0x110],0x0
    {disp32} je     at_1_096f
    jg     at_1_00c1
    cmp    QWORD PTR [rsi+0x8],0x0
    mov    eax,0x2
    mov    ecx,0x3f
    cmove  rcx,rax
    mov    QWORD PTR [rsi],rcx
    {disp32} jmp    at_1_14a0
at_1_0092:
    mov    QWORD PTR [rsi+0x108],0xffffffffffffffff
    mov    QWORD PTR [rsi+0x100],0xffffffffffffffff
    mov    QWORD PTR [rsi+0x248],0x0
    cmp    QWORD PTR [rsi+0x110],0x0
    {disp32} jle    at_1_018e
at_1_00c1:
    mov    QWORD PTR [rsi+0x40],0x0
    {disp32} jmp    at_1_0cf7
at_1_00ce:
    and    rax,0xfffffffffffffffe
    cmp    rax,0xc
    jne    at_1_0103
    mov    rax,QWORD PTR [rsi+0x18]
    mov    rcx,QWORD PTR [r14]
    lea    rdx,[rcx+rcx*2]
    add    rdx,0x13
    imul   rdx,rcx
    mov    rcx,rdx
    shr    rcx,0x3f
    add    rcx,rdx
    sar    rcx,1
    add    rax,rcx
    add    rax,0x7
    mov    QWORD PTR [rsi+0x18],rax
at_1_0103:
    mov    QWORD PTR [rsp+0x30],r12
    mov    QWORD PTR [rsp+0x28],r14
    mov    QWORD PTR [rsp+0x20],r13
    lea    rcx,[rip + ref_31_unnamed_1]
    mov    rdx,rbp
    mov    r8,rsi
    mov    r9,rbx
    call   ref_32_DPARCK
    mov    rcx,QWORD PTR [rsi]
    lea    rax,[rcx-0x2]
    mov    QWORD PTR [rsp+0x58],rax
    cmp    rcx,0xe
    {disp32} jg     at_1_14a0
    dec    eax
    cmp    eax,0xb
    {disp32} ja     at_1_02b1
    lea    rdx,[rip + ref_21_rdata]
    movsxd rax,DWORD PTR [rdx+rax*4]
    add    rax,rdx
    jmp    rax
at_1_0158:
    movsd  xmm0,QWORD PTR [r12+0x48]
    ucomisd xmm0,QWORD PTR [r12+0x60]
    {disp32} jae    at_1_061d
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [r12+0x78],rax
    lea    rax,[rsi+0xf0]
    mov    rcx,QWORD PTR [rsi+0xf0]
    {disp32} jmp    at_1_0504
at_1_018e:
    cmp    QWORD PTR [rsi+0x8],0x0
    je     at_1_01a1
    mov    QWORD PTR [rsi],0x41
    {disp32} jmp    at_1_14a0
at_1_01a1:
    cmp    QWORD PTR [rsi+0x230],0x0
    jg     at_1_01c1
    cmp    QWORD PTR [rsi+0x268],0x0
    jg     at_1_01c1
    mov    QWORD PTR [rsi],0x578
    {disp32} jmp    at_1_14a0
at_1_01c1:
    mov    rax,QWORD PTR [rsi+0x120]
    mov    rcx,QWORD PTR [r14]
    mov    QWORD PTR [rsp+0x58],0x1
    test   rcx,rcx
    jle    at_1_0213
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    xor    r8d,r8d
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_01f0:
    movsd  xmm0,QWORD PTR [rdi+r8*8]
    divsd  xmm0,QWORD PTR [rbp+r8*8+0x0]
    movsd  QWORD PTR [rdx+r8*8],xmm0
    inc    r8
    cmp    r8,rcx
    jl     at_1_01f0
    inc    rcx
    mov    QWORD PTR [rsp+0x58],rcx
at_1_0213:
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    call   ref_33_DV2NRM
    movsd  QWORD PTR [r12],xmm0
    mov    rax,QWORD PTR [rsi+0x1b0]
    test   rax,rax
    {disp32} jne    at_1_0b30
    cmp    QWORD PTR [rsi+0x110],0x0
    mov    r14,QWORD PTR [rsp+0x138]
    mov    rbx,QWORD PTR [rsp+0x60]
    {disp32} je     at_1_0e84
    mov    QWORD PTR [rsi+0x110],0x0
    movsd  xmm0,QWORD PTR [r12+0x48]
    movsd  QWORD PTR [r12+0x60],xmm0
    cmp    QWORD PTR [rsi+0xc0],0x3
    {disp32} jl     at_1_04b5
    mov    rax,QWORD PTR [rsi+0x70]
    mov    QWORD PTR [rsi+0x60],rax
    setne  al
    movzx  eax,al
    lea    rax,[rax*2-0x1]
    mov    QWORD PTR [rsi+0x70],rax
    mov    QWORD PTR [rsi+0x1b0],0x46
    {disp32} jmp    at_1_0cf7
at_1_02a5:
    mov    rax,QWORD PTR [rsi+0x1e8]
    {disp32} jmp    at_1_033c
at_1_02b1:
    mov    rdx,QWORD PTR [r14]
    lea    r8,[rdx+0x1]
    imul   r8,rdx
    shr    r8,1
    mov    QWORD PTR [rsp+0x70],r8
    mov    rax,QWORD PTR [rsi+0x148]
    add    rax,r8
    mov    QWORD PTR [rsi+0x1e8],rax
    lea    r9,[rax+r8*1]
    mov    QWORD PTR [rsi+0x150],r9
    add    r9,rdx
    mov    QWORD PTR [rsi+0x138],r9
    add    r9,rdx
    mov    QWORD PTR [rsi+0x140],r9
    add    r9,rdx
    mov    QWORD PTR [rsi+0x120],r9
    add    r9,rdx
    mov    QWORD PTR [rsi+0x200],r9
    lea    r10,[r9+rdx*4]
    lea    rdx,[r9+rdx*4]
    add    rdx,0x7
    mov    QWORD PTR [rsi+0x1b8],rdx
    lea    rdx,[r8+r10*1]
    add    rdx,0x7
    mov    QWORD PTR [rsi+0x170],rdx
    cmp    rcx,0xd
    jne    at_1_033c
    mov    QWORD PTR [rsi],0xe
    {disp32} jmp    at_1_14a0
at_1_033c:
    mov    QWORD PTR [rsi+0xf0],0x0
    mov    QWORD PTR [rsi+0x28],0x1
    mov    QWORD PTR [rsi+0xe8],0x1
    mov    QWORD PTR [rsi+0x30],0x1
    mov    QWORD PTR [rsi+0x110],0xffffffffffffffff
    mov    QWORD PTR [rsi+0x50],0x2
    mov    QWORD PTR [rsi+0x8],0x0
    mov    QWORD PTR [rsi+0x1b0],0x0
    mov    QWORD PTR [rsi+0xc8],0x0
    xorps  xmm0,xmm0
    movups XMMWORD PTR [rsi+0x198],xmm0
    movups XMMWORD PTR [rsi+0x38],xmm0
    mov    QWORD PTR [rsi+0x248],0x0
    mov    QWORD PTR [r12+0x40],0x0
    mov    QWORD PTR [r12+0x20],0x0
    movsd  xmm0,QWORD PTR [r12+0x110]
    movsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    addsd  xmm1,QWORD PTR [r12+0xa0]
    divsd  xmm0,xmm1
    movsd  QWORD PTR [r12+0x38],xmm0
    mov    QWORD PTR [rsi+0x20],0x1
    test   rax,rax
    {disp32} js     at_1_14a0
    mov    rcx,QWORD PTR [rsi+0xc0]
    cmp    rcx,0x2
    jl     at_1_040b
    mov    QWORD PTR [rsi+0x20],0x2
at_1_040b:
    test   rcx,rcx
    je     at_1_0416
    cmp    rcx,0x3
    jl     at_1_0448
at_1_0416:
    mov    rcx,QWORD PTR [r14]
    lea    r8,[rcx+0x1]
    imul   r8,rcx
    shr    r8,1
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x98],r8
    lea    r8,[rip + ref_34_unnamed_2]
    lea    rcx,[rsp+0x98]
    call   ref_35_DV7SCP
at_1_0448:
    mov    QWORD PTR [rsi],0x1
    mov    rcx,QWORD PTR [rsi+0x258]
    test   rcx,rcx
    {disp32} jle    at_1_14a0
    mov    rax,QWORD PTR [r14]
    test   rax,rax
    {disp32} jle    at_1_14a0
    lea    rcx,[rsi+rcx*8]
    add    rcx,0xfffffffffffffff8
    xor    edx,edx
at_1_0475:
    lea    r8,[rdx+0x1]
    mov    QWORD PTR [rcx+rdx*8],r8
    mov    rdx,r8
    cmp    r8,rax
    jl     at_1_0475
    {disp32} jmp    at_1_14a0
at_1_048a:
    lea    r9,[r12+rax*8]
    add    r9,0xfffffffffffffff8
    lea    rax,[r12+rbx*8]
    add    rax,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_36_unnamed_3]
    lea    rcx,[rsp+0x70]
at_1_04ab:
    call   ref_37_DV2AXY
    mov    rbx,QWORD PTR [rsp+0x60]
at_1_04b5:
    mov    QWORD PTR [rsi],0x2
    mov    rax,QWORD PTR [rsp+0x150]
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],r12
    mov    QWORD PTR [rsp+0x28],r14
    mov    QWORD PTR [rsp+0x20],r13
    mov    rcx,rbp
    mov    rdx,rdi
    mov    r8,rsi
    mov    r9,rbx
    call   ref_38_DITSUM
at_1_04e9:
    lea    rax,[rsi+0xf0]
    mov    rcx,QWORD PTR [rsi+0xf0]
    cmp    rcx,QWORD PTR [rsi+0x88]
    {disp32} jge    at_1_05fc
at_1_0504:
    lea    rdx,[rcx+0x1]
    mov    QWORD PTR [rax],rdx
    test   rcx,rcx
    {disp32} je     at_1_05a4
    mov    rax,QWORD PTR [rsi+0x138]
    mov    rcx,QWORD PTR [r14]
    mov    QWORD PTR [rsp+0x58],0x1
    test   rcx,rcx
    jle    at_1_0563
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    xor    r8d,r8d
    {disp32} nop    WORD PTR [rax+rax*1+0x0]
at_1_0540:
    movsd  xmm0,QWORD PTR [rbp+r8*8+0x0]
    mulsd  xmm0,QWORD PTR [rdx+r8*8]
    movsd  QWORD PTR [rdx+r8*8],xmm0
    inc    r8
    cmp    r8,rcx
    jl     at_1_0540
    inc    rcx
    mov    QWORD PTR [rsp+0x58],rcx
at_1_0563:
    movsd  xmm6,QWORD PTR [r12+0x78]
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    call   ref_33_DV2NRM
    mulsd  xmm0,xmm6
    ucomisd xmm0,QWORD PTR [r12+0x38]
    seta   al
    movsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    ucomisd xmm1,QWORD PTR [r12+0x78]
    ja     at_1_059d
    test   al,al
    je     at_1_05a4
at_1_059d:
    movsd  QWORD PTR [r12+0x38],xmm0
at_1_05a4:
    mov    rax,QWORD PTR [rsi+0x150]
    movsd  xmm0,QWORD PTR [r12+0x48]
    movsd  QWORD PTR [r12+0x60],xmm0
    mov    QWORD PTR [rsi+0xe0],0x4
    mov    rcx,QWORD PTR [rsi+0x1b8]
    mov    rdx,rcx
    neg    rdx
    cmovns rdx,rcx
    mov    rcx,QWORD PTR [rsi+0x20]
    mov    QWORD PTR [rsi+0x1b8],rdx
    mov    QWORD PTR [rsi+0x1f8],rcx
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    mov    r8,QWORD PTR [rsp+0x150]
    jmp    at_1_0608
at_1_05fc:
    mov    QWORD PTR [rsi],0xa
    {disp32} jmp    at_1_14a0
at_1_0608:
    call   ref_39_DV7CPY
at_1_060d:
    mov    rcx,rsi
    call   ref_40_STOPX
    test   al,0x1
    {disp32} jne    at_1_1199
at_1_061d:
    mov    rax,QWORD PTR [rsi+0x198]
    add    rax,QWORD PTR [rsi+0x80]
    cmp    QWORD PTR [rsi+0x28],rax
    {disp32} jge    at_1_1192
    mov    rbx,QWORD PTR [rsi+0x20]
at_1_0639:
    mov    rdi,QWORD PTR [rsi+0x138]
    mov    r15,QWORD PTR [rsi+0x1b8]
    mov    r14,QWORD PTR [rsi+0x200]
    movsd  xmm6,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    cmp    rbx,0x2
    mov    rbx,QWORD PTR [rsp+0x60]
    {disp32} je     at_1_0713
    mov    rax,QWORD PTR [rsi+0x268]
    xorpd  xmm6,xmm6
    test   rax,rax
    {disp32} jle    at_1_0713
    mov    rcx,QWORD PTR [rsi+0x260]
    test   rcx,rcx
    {disp32} jle    at_1_0713
    mov    rdx,QWORD PTR [rsi+0x258]
    lea    r8,[rsi+0x250]
    lea    r9,[rsi+rdx*8]
    add    r9,0xfffffffffffffff8
    lea    rdx,[rsi+0x108]
    lea    rcx,[r12+rcx*8-0x8]
    lea    rax,[r12+rax*8-0x8]
    lea    r10,[r12+rdi*8-0x8]
    lea    r11,[r12+r14*8-0x8]
    mov    QWORD PTR [rsp+0x50],r11
    mov    QWORD PTR [rsp+0x48],r12
    mov    QWORD PTR [rsp+0x40],r10
    mov    QWORD PTR [rsp+0x38],rax
    mov    QWORD PTR [rsp+0x30],rcx
    mov    r14,QWORD PTR [rsp+0x138]
    mov    QWORD PTR [rsp+0x28],r14
    mov    QWORD PTR [rsp+0x20],rdx
    mov    rcx,rbp
    mov    rdx,QWORD PTR [rsp+0x68]
    call   ref_41_DL7MST
    mov    rax,r15
    neg    rax
    cmovns rax,r15
    mov    QWORD PTR [rsi+0x1b8],rax
    mov    QWORD PTR [rsi+0x100],0xffffffffffffffff
    {disp32} jmp    at_1_08b9
at_1_0713:
    test   r15,r15
    jle    at_1_0724
    lea    r9,[rsi+0x100]
    {disp32} jmp    at_1_0851
at_1_0724:
    mov    rbx,r15
    neg    rbx
    mov    QWORD PTR [rsi+0x1b8],rbx
    mov    QWORD PTR [rsi+0x248],0x0
    mov    rcx,QWORD PTR [rsi+0x230]
    test   rcx,rcx
    jg     at_1_0771
    mov    rax,QWORD PTR [rsi+0x268]
    mov    rcx,r15
    not    rcx
    lea    rdx,[r12+rcx*8]
    lea    r8,[r12+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x138]
    call   ref_42_DL7SQR
    mov    rcx,rbx
at_1_0771:
    mov    r8,QWORD PTR [rsi+0x1e8]
    mov    rax,QWORD PTR [rsp+0x138]
    mov    rax,QWORD PTR [rax]
    mov    QWORD PTR [rsp+0x58],0x1
    test   rax,rax
    {disp32} jle    at_1_0833
    lea    rcx,[r12+rcx*8]
    add    rcx,0xfffffffffffffff8
    shl    r15,0x3
    neg    r15
    lea    rdx,[r12+r15*1]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r12+r8*8]
    add    r8,0xfffffffffffffff8
    mov    r9d,0x1
    mov    r10d,0x8
    movsd  xmm0,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    {disp32} nop    DWORD PTR [rax+rax*1+0x0]
at_1_07d0:
    movapd xmm1,xmm0
    divsd  xmm1,QWORD PTR [rbp+r9*8-0x8]
    lea    r11,[r9+0x1]
    xor    ebx,ebx
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07f0:
    movsd  xmm2,QWORD PTR [r8+rbx*8]
    mulsd  xmm2,xmm6
    addsd  xmm2,QWORD PTR [rcx+rbx*8]
    mulsd  xmm2,xmm1
    divsd  xmm2,QWORD PTR [rbp+rbx*8+0x0]
    movsd  QWORD PTR [rdx+rbx*8],xmm2
    inc    rbx
    cmp    r9,rbx
    jne    at_1_07f0
    add    rcx,r10
    add    rdx,r10
    add    r8,r10
    add    r10,0x8
    cmp    r9,rax
    mov    r9,r11
    jl     at_1_07d0
    inc    rax
    mov    QWORD PTR [rsp+0x58],rax
at_1_0833:
    mov    r15,QWORD PTR [rsi+0x1b8]
    lea    r9,[rsi+0x100]
    mov    QWORD PTR [rsi+0x100],0xffffffffffffffff
    mov    rbx,QWORD PTR [rsp+0x60]
at_1_0851:
    mov    rax,QWORD PTR [rsi+0x120]
    mov    rcx,QWORD PTR [rsi+0x148]
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r12+r15*8-0x8]
    lea    rax,[r12+rcx*8-0x8]
    lea    rcx,[r12+rdi*8-0x8]
    lea    r10,[r12+r14*8-0x8]
    mov    QWORD PTR [rsp+0x40],r10
    mov    QWORD PTR [rsp+0x38],r12
    mov    QWORD PTR [rsp+0x30],rcx
    mov    r14,QWORD PTR [rsp+0x138]
    mov    QWORD PTR [rsp+0x28],r14
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rbp
    call   ref_43_DG7QTS
    cmp    QWORD PTR [rsi+0x108],0x0
    jle    at_1_08b9
    mov    QWORD PTR [rsi+0x108],0x0
at_1_08b9:
    mov    rax,QWORD PTR [rsi+0xe0]
    cmp    rax,0x6
    jne    at_1_08db
    mov    eax,0x2
    cmp    QWORD PTR [rsi+0x40],0x2
    {disp32} jne    at_1_096f
    {disp32} jmp    at_1_0974
at_1_08db:
    mov    QWORD PTR [rsi+0x8],0x0
    xorpd  xmm0,xmm0
    ucomisd xmm0,QWORD PTR [r12+0x8]
    jae    at_1_096f
    cmp    rax,0x5
    {disp32} jne    at_1_1226
    movsd  xmm0,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    ucomisd xmm0,QWORD PTR [r12+0x78]
    {disp32} jae    at_1_1226
    movsd  xmm0,QWORD PTR [r12+0x30]
    movsd  xmm1,QWORD PTR [rip + ref_20_real_3ff3333333333333]
    mulsd  xmm1,QWORD PTR [r12+0x50]
    ucomisd xmm0,xmm1
    {disp32} ja     at_1_1226
    mov    rax,QWORD PTR [rsi+0x138]
    mov    rcx,QWORD PTR [rsi+0x150]
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r9,[r12+rcx*8-0x8]
    mov    rax,QWORD PTR [rsp+0x150]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_36_unnamed_3]
    mov    rcx,r14
    call   ref_37_DV2AXY
    xor    eax,eax
    cmp    QWORD PTR [rsi+0x40],0x2
    je     at_1_0974
at_1_096f:
    mov    eax,0x3
at_1_0974:
    mov    QWORD PTR [rsp+0x78],rax
    mov    rax,QWORD PTR [rsi+0x150]
    lea    rdi,[r12+rax*8]
    add    rdi,0xfffffffffffffff8
    mov    rcx,r14
    mov    rdx,rbp
    mov    r8,QWORD PTR [rsp+0x150]
    mov    r9,rdi
    call   ref_44_DRLDST
    movsd  QWORD PTR [r12+0x80],xmm0
    mov    rcx,rsi
    mov    rdx,rbx
    mov    r8,r13
    mov    r9,r12
    call   ref_45_DA7SST
    mov    rcx,QWORD PTR [rsi+0x40]
    mov    r15,QWORD PTR [rsi+0x138]
    mov    rax,QWORD PTR [rsi+0x140]
    inc    rcx
    mov    QWORD PTR [rsp+0x58],rcx
    cmp    ecx,0x1
    {disp32} je     at_1_0a8f
    cmp    ecx,0x4
    je     at_1_0a02
    cmp    ecx,0x3
    {disp32} jne    at_1_0a7c
    lea    rdx,[r12+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r12+r15*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,r14
    {disp32} jmp    at_1_0a8a
at_1_0a02:
    lea    r14,[r12+r15*8]
    add    r14,0xfffffffffffffff8
    lea    r8,[r12+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    rdx,r14
    call   ref_39_DV7CPY
    mov    QWORD PTR [rsp+0x20],rdi
    lea    r8,[rip + ref_46_unnamed_4]
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    r13,QWORD PTR [rsp+0x150]
    mov    rdx,r13
    mov    r9,r14
    call   ref_37_DV2AXY
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    rdx,rbp
    mov    r8,r13
    mov    r13,QWORD PTR [rsp+0x130]
    mov    r9,rdi
    call   ref_44_DRLDST
    movsd  QWORD PTR [r12+0x80],xmm0
    mov    rax,QWORD PTR [rsp+0x78]
    mov    QWORD PTR [rsi+0x40],rax
    jmp    at_1_0a8f
at_1_0a7c:
    mov    rcx,r14
    mov    rdx,QWORD PTR [rsp+0x150]
    mov    r8,rdi
at_1_0a8a:
    call   ref_39_DV7CPY
at_1_0a8f:
    cmp    QWORD PTR [rsi+0x58],0x0
    je     at_1_0ad4
    mov    rax,QWORD PTR [rsi+0x1b8]
    mov    rcx,QWORD PTR [rsi+0x1d8]
    mov    rdx,rax
    neg    rdx
    cmovns rdx,rax
    mov    QWORD PTR [rsi+0x1b8],rdx
    add    QWORD PTR [rsi+0x1f8],0x2
    lea    r8,[r12+rcx*8]
    add    r8,0xfffffffffffffff8
    lea    rcx,[rip + ref_47_unnamed_5]
    mov    rdx,r12
    call   ref_39_DV7CPY
at_1_0ad4:
    mov    rbx,QWORD PTR [rsi+0x20]
    mov    r14,QWORD PTR [rsi+0xe0]
    cmp    r14,0x4
    {disp32} jle    at_1_0c12
    lea    rax,[r14-0x4]
    lea    ecx,[rax-0x1]
    cmp    ecx,0x9
    {disp32} ja     at_1_0c12
    lea    rdx,[rip + ref_21_rdata + (at_9_0030 - def_21_rdata)]
    movsxd rcx,DWORD PTR [rdx+rcx*4]
    add    rcx,rdx
    mov    rdi,QWORD PTR [rsp+0x68]
    jmp    rcx
at_1_0b0e:
    mov    QWORD PTR [rsi+0x1b0],rax
    movsd  xmm0,QWORD PTR [r12+0x48]
    ucomisd xmm0,QWORD PTR [r12+0x60]
    jae    at_1_0b30
    cmp    QWORD PTR [rsi+0x60],0xe
    {disp32} jne    at_1_1339
at_1_0b30:
    cmp    QWORD PTR [rsi+0x1c0],0x0
    {disp32} je     at_1_1314
    cmp    QWORD PTR [rsi+0x248],0x0
    {disp32} jne    at_1_1314
    cmp    rax,0x6
    {disp32} jg     at_1_1314
    cmp    QWORD PTR [rsi+0x210],0x0
    {disp32} jg     at_1_1314
    cmp    QWORD PTR [rsi+0xc8],0x0
    {disp32} jg     at_1_1314
    mov    rax,QWORD PTR [rsi+0x70]
    mov    rcx,rax
    neg    rcx
    cmovs  rcx,rax
    cmp    rcx,0x3
    {disp32} jb     at_1_0cdb
    lea    r15,[rsi+0x248]
    mov    rax,QWORD PTR [rsi+0x1b8]
    mov    rbx,rax
    neg    rbx
    cmovs  rbx,rax
    mov    rax,rbx
    neg    rax
    mov    QWORD PTR [rsi+0x1b8],rax
    mov    rax,QWORD PTR [rsp+0x138]
    mov    rcx,QWORD PTR [rax]
    lea    rax,[rcx+0x1]
    imul   rax,rcx
    shr    rax,1
    mov    QWORD PTR [rsp+0x70],rax
    mov    rcx,QWORD PTR [rsi+0x268]
    test   rcx,rcx
    {disp32} jg     at_1_126d
    mov    rcx,QWORD PTR [rsi+0x230]
    mov    QWORD PTR [rsi+0x248],rbx
    lea    rdx,[r12+rbx*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r12+rcx*8]
    add    r8,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x90],rax
    lea    rcx,[rsp+0x90]
    call   ref_39_DV7CPY
    {disp32} jmp    at_1_0d3f
at_1_0c12:
    movsd  xmm6,QWORD PTR [r12+0x30]
    subsd  xmm6,QWORD PTR [r12+0x50]
    mov    rax,QWORD PTR [rsi+0x1e8]
    lea    r8,[r12+rax*8]
    add    r8,0xfffffffffffffff8
    lea    rdi,[r12+r15*8-0x8]
    mov    r15,QWORD PTR [rsp+0x140]
    mov    rcx,r15
    mov    r13,QWORD PTR [rsp+0x158]
    mov    rdx,r13
    mov    r9,rdi
    call   ref_48_DS7LVM
    mov    rcx,r15
    mov    rdx,rdi
    mov    r8,r13
    call   ref_49_DD7TPR
    mulsd  xmm0,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    mov    rax,QWORD PTR [rsi+0x20]
    movapd xmm1,XMMWORD PTR [rip + ref_17_xmm_80000000000000008000000000000000]
    xorpd  xmm1,xmm0
    cmp    rax,0x1
    je     at_1_0c82
    movapd xmm1,xmm0
at_1_0c82:
    addsd  xmm1,xmm6
    movapd xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm1,xmm0
    mulsd  xmm1,QWORD PTR [r12+0x160]
    andpd  xmm6,xmm0
    ucomisd xmm1,xmm6
    mov    rdi,QWORD PTR [rsp+0x68]
    {disp32} jb     at_1_0e0a
    cmp    r14,0x1
    mov    r13,QWORD PTR [rsp+0x130]
    {disp32} jg     at_1_1341
at_1_0cc1:
    movsd  xmm0,QWORD PTR [r12+0x78]
    mulsd  xmm0,QWORD PTR [r12+0x8]
    movsd  QWORD PTR [r12+0x38],xmm0
    {disp32} jmp    at_1_060d
at_1_0cdb:
    cmp    QWORD PTR [rsi+0x40],0x0
    mov    r14,QWORD PTR [rsp+0x138]
    mov    rbx,QWORD PTR [rsp+0x60]
    jne    at_1_0cf7
    mov    QWORD PTR [rsi+0x40],0x2
at_1_0cf7:
    mov    rax,QWORD PTR [rsp+0x150]
    mov    QWORD PTR [rsp+0x40],rax
    mov    QWORD PTR [rsp+0x38],r12
    mov    QWORD PTR [rsp+0x30],r14
    mov    QWORD PTR [rsp+0x28],r13
    mov    QWORD PTR [rsp+0x20],rbx
    lea    r8,[rsp+0x58]
    mov    rcx,rbp
    mov    rdx,rdi
    mov    r9,rsi
    call   ref_50_DF7HES
    mov    eax,DWORD PTR [rsp+0x58]
    cmp    eax,0x3
    {disp32} jne    at_1_1161
    lea    r15,[rsi+0x248]
at_1_0d3f:
    mov    rbx,QWORD PTR [rsi+0x248]
    test   rbx,rbx
    {disp32} jle    at_1_1314
    cmp    QWORD PTR [rsi+0x1b0],0x46
    {disp32} jne    at_1_11d0
    mov    QWORD PTR [rsi+0x1b0],0x0
    mov    QWORD PTR [rsi+0x110],0x0
    xorpd  xmm0,xmm0
    movupd XMMWORD PTR [rsi+0x198],xmm0
    mov    rax,QWORD PTR [rsi+0x60]
    mov    r8,QWORD PTR [rsi+0x1e8]
    mov    QWORD PTR [rsi+0x70],rax
    mov    rcx,QWORD PTR [rsp+0x140]
    mov    rax,QWORD PTR [rcx]
    lea    rdx,[rax+0x1]
    imul   rdx,rax
    shr    rdx,1
    mov    QWORD PTR [rsp+0x70],rdx
    mov    rax,QWORD PTR [rsi+0x230]
    lea    rdx,[r12+r8*8]
    add    rdx,0xfffffffffffffff8
    test   rax,rax
    mov    r14,QWORD PTR [rsp+0x138]
    {disp32} jg     at_1_048a
    mov    rax,QWORD PTR [rsi+0x268]
    lea    r8,[r12+rax*8]
    add    r8,0xfffffffffffffff8
    mov    r15,rdi
    mov    rdi,rdx
    call   ref_42_DL7SQR
    lea    rax,[r12+rbx*8]
    add    rax,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_36_unnamed_3]
    lea    rcx,[rsp+0x70]
    mov    rdx,rdi
    mov    r9,rdi
    mov    rdi,r15
    {disp32} jmp    at_1_04ab
at_1_0e0a:
    mov    ecx,0x3
    sub    rcx,rax
    mov    QWORD PTR [rsi+0x20],rcx
    cmp    r14,0x2
    mov    r13,QWORD PTR [rsp+0x130]
    {disp32} jg     at_1_1341
    mov    rax,QWORD PTR [rsi+0x1b8]
    mov    rcx,QWORD PTR [rsi+0x1d8]
    mov    rdx,rax
    neg    rdx
    cmovns rdx,rax
    mov    QWORD PTR [rsi+0x1b8],rdx
    add    QWORD PTR [rsi+0x1f8],0x2
    lea    rdx,[r12+rcx*8]
    add    rdx,0xfffffffffffffff8
    lea    rcx,[rip + ref_47_unnamed_5]
    mov    r8,r12
    {disp32} jmp    at_1_0608
at_1_0e66:
    movsd  xmm0,QWORD PTR [r12+0x118]
    movsd  QWORD PTR [r12+0x38],xmm0
    {disp32} jmp    at_1_0639
at_1_0e7c:
    mov    r14,QWORD PTR [rsp+0x138]
at_1_0e84:
    mov    rax,QWORD PTR [rsi+0x200]
    lea    r13,[r12+rax*8]
    add    r13,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x20],rdi
    lea    r8,[rip + ref_36_unnamed_3]
    mov    rcx,r14
    mov    rdx,r13
    mov    r9,r13
    call   ref_37_DV2AXY
    mov    rdi,QWORD PTR [rsi+0x138]
    mov    rax,QWORD PTR [rsi+0x140]
    mov    rcx,QWORD PTR [rsi+0x200]
    mov    QWORD PTR [rsp+0x80],rcx
    cmp    QWORD PTR [rsi+0xe0],0x3
    {disp32} jne    at_1_0f8e
    mov    r15,r14
    mov    rcx,QWORD PTR [r14]
    mov    QWORD PTR [rsp+0x58],0x1
    test   rcx,rcx
    jle    at_1_0f2a
    mov    rdx,QWORD PTR [rsp+0x148]
    lea    rdx,[rdx+rax*8]
    add    rdx,0xfffffffffffffff8
    xor    r8d,r8d
    nop
at_1_0f00:
    movsd  xmm0,QWORD PTR [rdx+r8*8]
    subsd  xmm0,QWORD PTR [r13+r8*8+0x0]
    divsd  xmm0,QWORD PTR [rbp+r8*8+0x0]
    movsd  QWORD PTR [rdx+r8*8],xmm0
    inc    r8
    cmp    r8,rcx
    jl     at_1_0f00
    inc    rcx
    mov    QWORD PTR [rsp+0x58],rcx
at_1_0f2a:
    mov    rbx,QWORD PTR [rsp+0x148]
    lea    r14,[rbx+rax*8]
    add    r14,0xfffffffffffffff8
    mov    rcx,r15
    mov    rdx,r14
    call   ref_33_DV2NRM
    movsd  xmm1,QWORD PTR [rbx]
    mulsd  xmm1,QWORD PTR [rbx+0xe0]
    ucomisd xmm1,xmm0
    jae    at_1_0f7f
    lea    r8,[rbx+rdi*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,r15
    mov    rdx,QWORD PTR [rsp+0x68]
    call   ref_49_DD7TPR
    movsd  xmm1,QWORD PTR [rbx+0x18]
    mulsd  xmm1,QWORD PTR [rbx+0xe8]
    ucomisd xmm0,xmm1
    jae    at_1_0f9e
at_1_0f7f:
    movsd  xmm0,QWORD PTR [rbx+0xb0]
    movsd  QWORD PTR [rbx+0x78],xmm0
    jmp    at_1_0f9e
at_1_0f8e:
    mov    rbx,QWORD PTR [rsp+0x148]
    lea    r14,[rbx+rax*8]
    add    r14,0xfffffffffffffff8
at_1_0f9e:
    mov    rax,QWORD PTR [rsp+0x68]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_36_unnamed_3]
    mov    r15,QWORD PTR [rsp+0x140]
    mov    rcx,r15
    mov    r12,QWORD PTR [rsp+0x158]
    mov    rdx,r12
    mov    r9,r12
    call   ref_37_DV2AXY
    mov    rax,QWORD PTR [rsi+0x1e8]
    lea    r8,[rbx+rax*8]
    add    r8,0xfffffffffffffff8
    lea    rdi,[rbx+rdi*8-0x8]
    mov    rcx,r15
    mov    rdx,r14
    mov    QWORD PTR [rsp+0x78],r8
    mov    r9,rdi
    call   ref_48_DS7LVM
    mov    rcx,r15
    mov    rdx,rdi
    mov    r8,r14
    call   ref_49_DD7TPR
    movapd xmm6,xmm0
    movapd xmm7,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm6,xmm7
    mov    rcx,r15
    mov    rdx,rdi
    mov    r8,r12
    call   ref_49_DD7TPR
    andpd  xmm0,xmm7
    lea    rcx,[rbx+0x1b0]
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [rbx+0x1b0],rax
    ucomisd xmm6,xmm0
    jbe    at_1_104a
    divsd  xmm0,xmm6
    movsd  QWORD PTR [rcx],xmm0
at_1_104a:
    mov    QWORD PTR [rsp+0x88],rcx
    mov    rax,QWORD PTR [rsi+0x230]
    mov    r15,r14
    test   rax,rax
    jle    at_1_1089
    mov    r12,QWORD PTR [rsp+0x148]
    lea    r8,[r12+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rbx,QWORD PTR [rsp+0x140]
    mov    rcx,rbx
    mov    rdx,r13
    mov    r9,rdi
    call   ref_48_DS7LVM
    jmp    at_1_10cd
at_1_1089:
    mov    rax,QWORD PTR [rsi+0x268]
    mov    r12,QWORD PTR [rsp+0x148]
    lea    rbx,[r12+rax*8]
    add    rbx,0xfffffffffffffff8
    mov    r14,QWORD PTR [rsp+0x140]
    mov    rcx,r14
    mov    rdx,r13
    mov    r8,rbx
    mov    r9,rdi
    call   ref_51_DL7TVM
    mov    rcx,r14
    mov    rdx,r13
    mov    r8,rbx
    mov    rbx,r14
    mov    r9,r13
    call   ref_52_DL7VML
at_1_10cd:
    mov    QWORD PTR [rsp+0x20],r13
    lea    r8,[rip + ref_46_unnamed_4]
    mov    rcx,rbx
    mov    rdx,r13
    mov    r14,QWORD PTR [rsp+0x158]
    mov    r9,r14
    call   ref_37_DV2AXY
    lea    rdx,[r12+0x170]
    mov    rax,QWORD PTR [rsp+0x80]
    lea    rax,[r12+rax*8]
    add    rax,0xfffffffffffffff8
    lea    rcx,[r12+0x1b8]
    mov    QWORD PTR [rsp+0x48],r14
    mov    QWORD PTR [rsp+0x40],rcx
    mov    QWORD PTR [rsp+0x38],r13
    mov    QWORD PTR [rsp+0x30],rax
    mov    QWORD PTR [rsp+0x28],r15
    mov    QWORD PTR [rsp+0x20],rdi
    mov    rcx,QWORD PTR [rsp+0x78]
    mov    r8,rbx
    mov    r9,QWORD PTR [rsp+0x88]
    call   ref_53_DS7LUP
    mov    r14,QWORD PTR [rsp+0x138]
    mov    rdi,QWORD PTR [rsp+0x68]
    mov    rbx,QWORD PTR [rsp+0x60]
    mov    r13,QWORD PTR [rsp+0x130]
    {disp32} jmp    at_1_04b5
at_1_1161:
    cmp    eax,0x2
    jne    at_1_11c4
    mov    rax,QWORD PTR [rsi+0x1a0]
    inc    rax
    mov    QWORD PTR [rsi+0x1a0],rax
    inc    QWORD PTR [rsi+0xe8]
    add    rax,QWORD PTR [rsi+0x28]
    mov    QWORD PTR [rsi+0x30],rax
    mov    QWORD PTR [rsi],0x2
    {disp32} jmp    at_1_14a0
at_1_1192:
    mov    eax,0x9
    jmp    at_1_119e
at_1_1199:
    mov    eax,0xb
at_1_119e:
    mov    QWORD PTR [rsi],rax
    movsd  xmm0,QWORD PTR [r12+0x48]
    ucomisd xmm0,QWORD PTR [r12+0x60]
    {disp32} jae    at_1_14a0
    mov    r13,rdi
    mov    QWORD PTR [rsi+0x1b0],rax
    {disp32} jmp    at_1_1463
at_1_11c4:
    inc    QWORD PTR [rsi+0x198]
    {disp32} jmp    at_1_125d
at_1_11d0:
    mov    rax,QWORD PTR [rsi+0x148]
    lea    rdi,[r12+rax*8]
    add    rdi,0xfffffffffffffff8
    lea    r9,[r12+rbx*8-0x8]
    lea    rax,[rsp+0x58]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rip + ref_31_unnamed_1]
    mov    rdx,QWORD PTR [rsp+0x138]
    mov    r8,rdi
    call   ref_54_DL7SRT
    mov    QWORD PTR [r15],0xffffffffffffffff
    mov    QWORD PTR [r12+0x1a0],0x0
    cmp    QWORD PTR [rsp+0x58],0x0
    {disp32} jne    at_1_1314
    jmp    at_1_129d
at_1_1226:
    mov    rax,QWORD PTR [rsi+0x138]
    mov    rcx,QWORD PTR [rsi+0x150]
    lea    r9,[r12+rax*8]
    add    r9,0xfffffffffffffff8
    lea    rax,[r12+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_46_unnamed_4]
    mov    rcx,r14
    mov    rdx,QWORD PTR [rsp+0x150]
    call   ref_37_DV2AXY
at_1_125d:
    inc    QWORD PTR [rsi+0x28]
    mov    QWORD PTR [rsi],0x1
    {disp32} jmp    at_1_14a0
at_1_126d:
    mov    rax,QWORD PTR [rsi+0x148]
    lea    rdi,[r12+rax*8]
    add    rdi,0xfffffffffffffff8
    lea    r8,[r12+rcx*8]
    add    r8,0xfffffffffffffff8
    lea    rcx,[rsp+0x70]
    mov    rdx,rdi
    call   ref_39_DV7CPY
    mov    QWORD PTR [r12+0x1a0],0x0
at_1_129d:
    mov    QWORD PTR [rsi+0x248],0xffffffffffffffff
    mov    rax,QWORD PTR [rsi+0x138]
    lea    r14,[r12+rax*8]
    add    r14,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    rdx,rdi
    mov    r8,r14
    mov    r9,r14
    call   ref_55_DL7SVN
    movapd xmm6,xmm0
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm6
    jae    at_1_1314
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    rdx,rdi
    mov    r8,r14
    mov    r9,r14
    call   ref_56_DL7SVX
    divsd  xmm6,xmm0
    lea    rcx,[rip + ref_57_unnamed_6]
    call   ref_58_DR7MDC
    ucomisd xmm6,xmm0
    jbe    at_1_130a
    mov    QWORD PTR [r15],rbx
at_1_130a:
    movsd  QWORD PTR [r12+0x1a0],xmm6
at_1_1314:
    mov    QWORD PTR [rsi+0x110],0x0
    mov    rax,QWORD PTR [rsi+0x1b0]
    mov    QWORD PTR [rsi],rax
    mov    QWORD PTR [rsi+0x1b0],0x0
    {disp32} jmp    at_1_14a0
at_1_1339:
    mov    QWORD PTR [rsi+0x60],0xe
at_1_1341:
    mov    r13,rdi
    mov    QWORD PTR [rsi+0xc8],0x0
    mov    QWORD PTR [rsi+0x210],0x0
    cmp    QWORD PTR [rsi+0xe0],0x3
    {disp32} jne    at_1_1463
    mov    r12,QWORD PTR [rsi+0x138]
    mov    r15,QWORD PTR [rsi+0x140]
    mov    rdi,QWORD PTR [rsi+0x200]
    mov    rax,QWORD PTR [rsi+0x230]
    test   rax,rax
    jle    at_1_13b8
    mov    rcx,QWORD PTR [rsp+0x148]
    lea    rdx,[rcx+r15*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[rcx+rax*8]
    add    r8,0xfffffffffffffff8
    lea    r9,[rcx+r12*8]
    add    r9,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x138]
    call   ref_48_DS7LVM
    jmp    at_1_140a
at_1_13b8:
    mov    rax,QWORD PTR [rsi+0x268]
    mov    rcx,QWORD PTR [rsp+0x148]
    mov    QWORD PTR [rsp+0x60],rdi
    lea    rdi,[rcx+r15*8]
    add    rdi,0xfffffffffffffff8
    lea    r14,[rcx+rax*8-0x8]
    lea    r9,[rcx+r12*8-0x8]
    mov    rbp,QWORD PTR [rsp+0x138]
    mov    rcx,rbp
    mov    rdx,rdi
    mov    r8,r14
    call   ref_51_DL7TVM
    mov    rcx,rbp
    mov    rdx,rdi
    mov    r8,r14
    mov    r9,rdi
    mov    rdi,QWORD PTR [rsp+0x60]
    call   ref_52_DL7VML
at_1_140a:
    cmp    rbx,0x1
    je     at_1_1463
    mov    rax,QWORD PTR [rsi+0x1e8]
    mov    rbx,QWORD PTR [rsp+0x148]
    lea    rdi,[rbx+rdi*8]
    add    rdi,0xfffffffffffffff8
    lea    r8,[rbx+rax*8-0x8]
    lea    r9,[rbx+r12*8-0x8]
    mov    r14,QWORD PTR [rsp+0x140]
    mov    rcx,r14
    mov    rdx,rdi
    call   ref_48_DS7LVM
    lea    rdx,[rbx+r15*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x20],rdx
    lea    r8,[rip + ref_46_unnamed_4]
    mov    rcx,r14
    mov    r9,rdi
    call   ref_37_DV2AXY
at_1_1463:
    inc    QWORD PTR [rsi+0xe8]
    mov    rax,QWORD PTR [rsi+0x200]
    mov    rcx,QWORD PTR [rsp+0x148]
    lea    rdx,[rcx+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x138]
    mov    r8,r13
    call   ref_39_DV7CPY
    mov    QWORD PTR [rsi],0x2
    mov    QWORD PTR [rsi+0x8],0x0
at_1_14a0:
    movaps xmm6,XMMWORD PTR [rsp+0xa0]
    movaps xmm7,XMMWORD PTR [rsp+0xb0]
    add    rsp,0xc8
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_14c4:
    mov    QWORD PTR [rsi],0x40
    jmp    at_1_14a0
at_1_14cd:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fe0000000000000:
at_6_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_80000000000000008000000000000000:
at_7_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_3ff3333333333333:
at_8_0000:
    .quad 0x3ff3333333333333    # binary64 1.2
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
at_9_0000:
    .long ref_0_text + (at_1_096f - at_1_0000) + (. - at_9_0000) + 4    # slot 0 -> at_1_096f
    .long ref_0_text + (at_1_096f - at_1_0000) + (. - at_9_0000) + 4    # slot 1 -> at_1_096f
    .long ref_0_text + (at_1_096f - at_1_0000) + (. - at_9_0000) + 4    # slot 2 -> at_1_096f
    .long ref_0_text + (at_1_096f - at_1_0000) + (. - at_9_0000) + 4    # slot 3 -> at_1_096f
    .long ref_0_text + (at_1_096f - at_1_0000) + (. - at_9_0000) + 4    # slot 4 -> at_1_096f
    .long ref_0_text + (at_1_096f - at_1_0000) + (. - at_9_0000) + 4    # slot 5 -> at_1_096f
    .long ref_0_text + (at_1_0158 - at_1_0000) + (. - at_9_0000) + 4    # slot 6 -> at_1_0158
    .long ref_0_text + (at_1_04e9 - at_1_0000) + (. - at_9_0000) + 4    # slot 7 -> at_1_04e9
    .long ref_0_text + (at_1_0158 - at_1_0000) + (. - at_9_0000) + 4    # slot 8 -> at_1_0158
    .long ref_0_text + (at_1_02b1 - at_1_0000) + (. - at_9_0000) + 4    # slot 9 -> at_1_02b1
    .long ref_0_text + (at_1_02b1 - at_1_0000) + (. - at_9_0000) + 4    # slot 10 -> at_1_02b1
    .long ref_0_text + (at_1_02a5 - at_1_0000) + (. - at_9_0000) + 4    # slot 11 -> at_1_02a5
at_9_0030:
    .long ref_0_text + (at_1_0cc1 - at_1_0000) + (. - at_9_0030) + 4    # slot 0 -> at_1_0cc1
    .long ref_0_text + (at_1_0e66 - at_1_0000) + (. - at_9_0030) + 4    # slot 1 -> at_1_0e66
    .long ref_0_text + (at_1_0b0e - at_1_0000) + (. - at_9_0030) + 4    # slot 2 -> at_1_0b0e
    .long ref_0_text + (at_1_0b0e - at_1_0000) + (. - at_9_0030) + 4    # slot 3 -> at_1_0b0e
    .long ref_0_text + (at_1_0b0e - at_1_0000) + (. - at_9_0030) + 4    # slot 4 -> at_1_0b0e
    .long ref_0_text + (at_1_0b0e - at_1_0000) + (. - at_9_0030) + 4    # slot 5 -> at_1_0b0e
    .long ref_0_text + (at_1_0b0e - at_1_0000) + (. - at_9_0030) + 4    # slot 6 -> at_1_0b0e
    .long ref_0_text + (at_1_0b0e - at_1_0000) + (. - at_9_0030) + 4    # slot 7 -> at_1_0b0e
    .long ref_0_text + (at_1_14c4 - at_1_0000) + (. - at_9_0030) + 4    # slot 8 -> at_1_14c4
    .long ref_0_text + (at_1_0e7c - at_1_0000) + (. - at_9_0030) + 4    # slot 9 -> at_1_0e7c
def_34_unnamed_2:
at_9_0058:
    .zero 8
def_47_unnamed_5:
at_9_0060:
    .quad 0x0000000000000009
def_36_unnamed_3:
at_9_0068:
    .quad 0xbff0000000000000    # binary64 -1.0
def_46_unnamed_4:
at_9_0070:
    .quad 0x3ff0000000000000    # binary64 1.0
def_31_unnamed_1:
at_9_0078:
    .quad 0x0000000000000001
def_57_unnamed_6:
at_9_0080:
    .quad 0x0000000000000004
at_9_0088:
end_s9:

# .xdata  (COFF section 10)
.section .s10,"dr"
def_23_xdata:
at_10_0000:
    .byte 0x01    # version 1
    .byte at_1_0025 - at_1_0000    # prologue size
    .byte 0x0e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0025 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x0a
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x0b
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x19
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_10_0020:
end_s10:

# .drectve  (COFF section 11)
.section .s11,"dr"
def_25_drectve:
at_11_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_11_00b9:
end_s11:

# .pdata  (COFF section 12)
.section .s12,"dr"
def_27_pdata:
at_12_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_14cd - def_0_text)    # image-relative end
    .long ref_23_xdata    # image-relative unwind info
at_12_000c:
end_s12:

# MEMBER dg7itb.obj
# Entry points: DG7ITB
.intel_syntax noprefix
# Bound-constrained iteration and step selection. The two dispatch tables share the same read-only section.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_30_DG7ITB:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x198
at_1_0013:
    movapd XMMWORD PTR [rsp+0x180],xmm7
at_1_001c:
    movapd XMMWORD PTR [rsp+0x170],xmm6
at_1_0025:
    mov    rsi,r9
    mov    QWORD PTR [rsp+0xe0],r8
    mov    rbx,rdx
    mov    rdi,rcx
    mov    r14,QWORD PTR [rsp+0x228]
    mov    r15,QWORD PTR [rsp+0x220]
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    rax,QWORD PTR [r9]
    mov    QWORD PTR [rsp+0xc0],rax
    cmp    rax,0x2
    mov    QWORD PTR [rsp+0xd0],rdx
    je     at_1_0098
    cmp    rax,0x1
    jne    at_1_00af
    cmp    QWORD PTR [rsi+0x110],0x0
    {disp32} je     at_1_1145
    {disp32} jg     at_1_01b0
    cmp    QWORD PTR [rsi+0x8],0x0
    {disp32} je     at_1_1c26
    mov    QWORD PTR [rsi],0x3f
    {disp32} jmp    at_1_1ce1
at_1_0098:
    cmp    QWORD PTR [rsi+0x8],0x0
    {disp32} je     at_1_0185
    mov    QWORD PTR [rsi],0x41
    {disp32} jmp    at_1_1ce1
at_1_00af:
    add    rax,0xfffffffffffffff2
    cmp    rax,0xfffffffffffffffe
    jb     at_1_00ed
    mov    rax,QWORD PTR [rsi+0x18]
    mov    rcx,QWORD PTR [rbp+0x0]
    lea    rdx,[rcx+rcx*2]
    add    rdx,0x19
    imul   rdx,rcx
    mov    r8,rdx
    shr    r8,0x3f
    add    r8,rdx
    sar    r8,1
    add    rax,r8
    add    rax,0x7
    mov    QWORD PTR [rsi+0x18],rax
    shl    rcx,0x2
    add    QWORD PTR [rsi+0x10],rcx
at_1_00ed:
    mov    QWORD PTR [rsp+0x30],r15
    mov    QWORD PTR [rsp+0x28],rbp
    mov    rax,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rip + ref_31_unnamed_1]
    mov    rdx,rbx
    mov    r8,rsi
    mov    r9,QWORD PTR [rsp+0x200]
    call   ref_32_DPARCK
    mov    rdx,QWORD PTR [rsi]
    lea    rax,[rdx-0x2]
    mov    QWORD PTR [rsp+0xc0],rax
    cmp    rdx,0xe
    {disp32} jg     at_1_1ce1
    dec    eax
    cmp    eax,0xb
    {disp32} ja     at_1_0417
    lea    rcx,[rip + ref_21_rdata]
    movsxd rax,DWORD PTR [rcx+rax*4]
    add    rax,rcx
    jmp    rax
at_1_0152:
    movsd  xmm0,QWORD PTR [r15+0x48]
    ucomisd xmm0,QWORD PTR [r15+0x60]
    {disp32} jae    at_1_0af4
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [r15+0x78],rax
    lea    rax,[rsi+0xf0]
    mov    rcx,QWORD PTR [rsi+0xf0]
    {disp32} jmp    at_1_09e2
at_1_0185:
    mov    QWORD PTR [rsi+0x108],0xffffffffffffffff
    mov    QWORD PTR [rsi+0x100],0xffffffffffffffff
    mov    QWORD PTR [rsi+0x248],0x0
    cmp    QWORD PTR [rsi+0x110],0x0
    jle    at_1_01bd
at_1_01b0:
    mov    QWORD PTR [rsi+0x40],0x0
    {disp32} jmp    at_1_14be
at_1_01bd:
    cmp    QWORD PTR [rsi+0x230],0x0
    mov    rbp,QWORD PTR [rsi+0x268]
    jg     at_1_01df
    test   rbp,rbp
    jg     at_1_01df
    mov    QWORD PTR [rsi],0x578
    {disp32} jmp    at_1_1ce1
at_1_01df:
    mov    rax,QWORD PTR [rsi+0x258]
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    r14,QWORD PTR [rcx]
    mov    rcx,QWORD PTR [rsi+0x140]
    mov    QWORD PTR [rsp+0x118],rcx
    mov    r8,QWORD PTR [rsi+0x1c8]
    mov    QWORD PTR [rsp+0xf8],r14
    mov    rcx,QWORD PTR [rsi+0x260]
    xor    edx,edx
    test   rcx,rcx
    setg   dl
    neg    rdx
    mov    QWORD PTR [rsp+0x160],rdx
    mov    rdx,QWORD PTR [rsi+0x200]
    mov    QWORD PTR [rsp+0xc0],0x1
    test   r14,r14
    {disp32} jle    at_1_0698
    dec    r8
    mov    QWORD PTR [rsp+0x110],r8
    lea    r12,[r14+0x1]
    lea    r8,[rdx+r14*1]
    test   rcx,rcx
    cmovg  r8,rcx
    lea    rcx,[r14+rax*1]
    lea    rbx,[rsi+rax*8-0x8]
    lea    rax,[r15+r8*8-0x8]
    mov    QWORD PTR [rsp+0xd8],rax
    lea    rax,[r15+rbp*8-0x8]
    mov    QWORD PTR [rsp+0xc8],rax
    lea    rax,[r15+rdx*8-0x8]
    mov    QWORD PTR [rsp+0xf0],rax
    lea    r13,[rsi+rcx*8-0x10]
    mov    eax,0x1
    xorpd  xmm6,xmm6
    mov    rcx,r14
    jmp    at_1_02e7
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_02b0:
    mov    rcx,QWORD PTR [rsp+0xf8]
    dec    rcx
    mov    QWORD PTR [rsp+0xf8],rcx
    mov    rax,QWORD PTR [rsp+0xc0]
at_1_02cb:
    lea    rdx,[rax+0x1]
    mov    QWORD PTR [rsp+0xc0],rdx
    add    r13,0xfffffffffffffff8
    cmp    rax,r14
    mov    rax,rdx
    {disp32} jge    at_1_0627
at_1_02e7:
    mov    rdx,QWORD PTR [r13+0x0]
    mov    QWORD PTR [rsp+0x120],rdx
    mov    r8,rdx
    shl    r8,0x4
    movsd  xmm3,QWORD PTR [r8+rdi*1-0x10]
    movsd  xmm0,QWORD PTR [r8+rdi*1-0x8]
    ucomisd xmm3,xmm0
    jae    at_1_0360
    mov    r8,QWORD PTR [rsp+0x228]
    movsd  xmm1,QWORD PTR [r8+rdx*8-0x8]
    mov    r8,QWORD PTR [rsp+0xe0]
    movsd  xmm2,QWORD PTR [r8+rdx*8-0x8]
    ucomisd xmm2,xmm6
    seta   r8b
    ucomisd xmm3,xmm1
    jb     at_1_033f
    test   r8b,r8b
    jne    at_1_0360
at_1_033f:
    ucomisd xmm6,xmm2
    seta   r8b
    ucomisd xmm1,xmm0
    {disp32} jb     at_1_03dc
    test   r8b,r8b
    {disp32} je     at_1_03dc
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0360:
    cmp    rdx,rcx
    {disp32} jge    at_1_02b0
    mov    rcx,r12
    sub    rcx,rax
    mov    QWORD PTR [rsp+0x120],rcx
    lea    rcx,[rsp+0xf8]
    lea    rdx,[rsp+0x120]
    mov    r8,rbx
    call   ref_33_I7SHFT
    test   rbp,rbp
    {disp32} jle    at_1_02b0
    mov    rax,QWORD PTR [rsp+0xf0]
    mov    QWORD PTR [rsp+0x28],rax
    mov    rax,QWORD PTR [rsp+0xc8]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0x120]
    lea    rdx,[rsp+0xf8]
    lea    r8,[rsp+0x160]
    mov    r9,QWORD PTR [rsp+0xd8]
    call   ref_34_DQ7RSH
    {disp32} jmp    at_1_02b0
at_1_03dc:
    add    rdx,QWORD PTR [rsp+0x110]
    mov    r8,QWORD PTR [rsp+0x118]
    cmp    QWORD PTR [rsi+rdx*8-0x8],r8
    {disp32} jle    at_1_02cb
    mov    QWORD PTR [rsi+0x1b0],0x0
    {disp32} jmp    at_1_02cb
at_1_0407:
    mov    rax,QWORD PTR [rbp+0x0]
    mov    rcx,QWORD PTR [rsi+0x258]
    {disp32} jmp    at_1_04b6
at_1_0417:
    mov    rax,QWORD PTR [rbp+0x0]
    lea    r8,[rax+0x1]
    imul   r8,rax
    shr    r8,1
    mov    QWORD PTR [rsp+0x128],r8
    mov    rcx,QWORD PTR [rsi+0x148]
    add    rcx,r8
    mov    QWORD PTR [rsi+0x1e8],rcx
    add    rcx,r8
    mov    QWORD PTR [rsi+0x150],rcx
    lea    r9,[rcx+rax*2]
    mov    QWORD PTR [rsi+0x138],r9
    lea    rcx,[rax+rax*2]
    add    r9,rcx
    mov    QWORD PTR [rsi+0x120],r9
    lea    r9,[r9+rax*2]
    mov    QWORD PTR [rsi+0x200],r9
    lea    r10,[r9+rax*4]
    lea    r9,[r9+rax*4+0x7]
    mov    QWORD PTR [rsi+0x1b8],r9
    add    r8,r10
    add    r8,0x7
    mov    QWORD PTR [rsi+0x170],r8
    add    rcx,QWORD PTR [rsi+0x1c8]
    mov    QWORD PTR [rsi+0x258],rcx
    lea    r8,[rcx+rax*1]
    mov    QWORD PTR [rsi+0x168],r8
    cmp    rdx,0xd
    jne    at_1_04b6
    mov    QWORD PTR [rsi],0xe
    {disp32} jmp    at_1_1ce1
at_1_04b6:
    mov    QWORD PTR [rsi+0xf0],0x0
    mov    QWORD PTR [rsi+0x28],0x1
    mov    QWORD PTR [rsi+0xe8],0x1
    mov    QWORD PTR [rsi+0x30],0x1
    mov    QWORD PTR [rsi+0x110],0xffffffffffffffff
    mov    QWORD PTR [rsi+0x50],0x2
    mov    QWORD PTR [rsi+0x8],0x0
    mov    QWORD PTR [rsi+0x1b0],0x0
    mov    QWORD PTR [rsi+0xc8],0x0
    xorps  xmm0,xmm0
    movups XMMWORD PTR [rsi+0x198],xmm0
    mov    QWORD PTR [rsi+0x38],0x0
    mov    QWORD PTR [rsi+0x140],rax
    mov    QWORD PTR [r15+0x40],0x0
    mov    QWORD PTR [r15+0x20],0x0
    movsd  xmm0,QWORD PTR [r15+0x110]
    movsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    addsd  xmm1,QWORD PTR [r15+0xa0]
    divsd  xmm0,xmm1
    movsd  QWORD PTR [r15+0x38],xmm0
    mov    QWORD PTR [rsp+0xc0],0x1
    test   rax,rax
    jle    at_1_05b0
    lea    rdx,[rdi+0x8]
    mov    r8,rax
    neg    r8
    lea    r9,[rsi+rcx*8]
    mov    ecx,0x1
    xchg   ax,ax
at_1_0580:
    mov    QWORD PTR [r9+rcx*8-0x10],rcx
    movsd  xmm0,QWORD PTR [rdx-0x8]
    ucomisd xmm0,QWORD PTR [rdx]
    {disp32} ja     at_1_0736
    add    rdx,0x10
    lea    r10,[r8+rcx*1]
    inc    r10
    inc    rcx
    cmp    r10,0x1
    jne    at_1_0580
    mov    QWORD PTR [rsp+0xc0],rcx
at_1_05b0:
    mov    QWORD PTR [rsi+0x20],0x1
    mov    QWORD PTR [rsi],0x1
    mov    rcx,QWORD PTR [rsi+0x1e8]
    test   rcx,rcx
    {disp32} js     at_1_1c80
    mov    rdx,QWORD PTR [rsi+0xc0]
    cmp    rdx,0x2
    jl     at_1_05e4
    mov    QWORD PTR [rsi+0x20],0x2
at_1_05e4:
    test   rdx,rdx
    je     at_1_05f3
    cmp    rdx,0x3
    {disp32} jl     at_1_1c80
at_1_05f3:
    lea    r8,[rax+0x1]
    imul   r8,rax
    shr    r8,1
    lea    rdx,[r15+rcx*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x158],r8
    lea    r8,[rip + ref_35_unnamed_2]
    lea    rcx,[rsp+0x158]
    call   ref_36_DV7SCP
    {disp32} jmp    at_1_1c80
at_1_0627:
    mov    QWORD PTR [rsi+0x140],rcx
    mov    QWORD PTR [r15],0x0
    test   rcx,rcx
    mov    rbp,QWORD PTR [rsp+0x210]
    jle    at_1_06b0
    mov    rax,QWORD PTR [rsi+0x120]
    lea    r14,[r15+rax*8]
    add    r14,0xfffffffffffffff8
    lea    rax,[rip + ref_37_unnamed_3]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rbp
    mov    rdx,r14
    mov    r8,QWORD PTR [rsp+0xe0]
    mov    r9,QWORD PTR [rsp+0xd0]
    call   ref_38_DV7VMP
    mov    rcx,rbp
    mov    rdx,rbx
    mov    r8,r14
    call   ref_39_DV7IPR
    lea    rcx,[rsp+0xf8]
    mov    rdx,r14
    call   ref_40_DV2NRM
    jmp    at_1_06ab
at_1_0698:
    mov    QWORD PTR [rsi+0x140],r14
    xorpd  xmm0,xmm0
    mov    rbp,QWORD PTR [rsp+0x210]
at_1_06ab:
    movsd  QWORD PTR [r15],xmm0
at_1_06b0:
    mov    rax,QWORD PTR [rsi+0x1b0]
    test   rax,rax
    mov    rbx,QWORD PTR [rsp+0xd0]
    {disp32} jne    at_1_144d
    cmp    QWORD PTR [rsi+0x110],0x0
    je     at_1_0742
    mov    QWORD PTR [rsi+0x110],0x0
    movsd  xmm0,QWORD PTR [r15+0x48]
    movsd  QWORD PTR [r15+0x60],xmm0
    cmp    QWORD PTR [rsi+0xc0],0x3
    {disp32} jl     at_1_0971
    mov    rax,QWORD PTR [rsi+0x70]
    mov    QWORD PTR [rsi+0x60],rax
    setne  al
    movzx  eax,al
    lea    rax,[rax+rax*1-0x1]
    mov    QWORD PTR [rsi+0x70],rax
    mov    QWORD PTR [rsi+0x1b0],0x46
    mov    r14,QWORD PTR [rsp+0x228]
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    rbx,QWORD PTR [rsp+0xd0]
    {disp32} jmp    at_1_14be
at_1_0736:
    mov    QWORD PTR [rsi],0x52
    {disp32} jmp    at_1_1ce1
at_1_0742:
    lea    rax,[rsi+0x200]
    lea    r14,[rsi+0x138]
    lea    rcx,[rsi+0x150]
    mov    QWORD PTR [rsp+0xc8],rcx
    lea    rbx,[rsi+0xe0]
    mov    r12,QWORD PTR [rsp+0x218]
    {disp32} jmp    at_1_158c
at_1_0773:
    mov    QWORD PTR [rsi+0x1b0],0x0
    mov    QWORD PTR [rsi+0x110],0x0
    xorpd  xmm0,xmm0
    movupd XMMWORD PTR [rsi+0x198],xmm0
    mov    rax,QWORD PTR [rsi+0x60]
    mov    r12,QWORD PTR [rsi+0x1e8]
    mov    QWORD PTR [rsi+0x70],rax
    mov    rax,QWORD PTR [rsp+0x218]
    mov    rax,QWORD PTR [rax]
    lea    rcx,[rax+0x1]
    imul   rcx,rax
    shr    rcx,1
    mov    QWORD PTR [rsp+0x128],rcx
    mov    rax,QWORD PTR [rsi+0x230]
    test   rax,rax
    jle    at_1_07f9
    lea    rdx,[r15+r12*8]
    add    rdx,0xfffffffffffffff8
    lea    r9,[r15+rax*8-0x8]
    lea    rax,[r15+r13*8-0x8]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_41_unnamed_4]
    lea    rcx,[rsp+0x128]
    {disp32} jmp    at_1_0881
at_1_07f9:
    mov    rax,QWORD PTR [rsi+0x148]
    mov    rcx,QWORD PTR [rsi+0x268]
    lea    rbx,[r15+rax*8]
    add    rbx,0xfffffffffffffff8
    lea    r8,[r15+rcx*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,rbp
    mov    rdx,rbx
    call   ref_42_DL7SQR
    mov    rax,QWORD PTR [rsi+0x258]
    mov    rcx,QWORD PTR [rbp+0x0]
    add    rcx,QWORD PTR [rsi+0x1c8]
    lea    r14,[rsi+rcx*8]
    add    r14,0xfffffffffffffff8
    lea    r8,[rsi+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,rbp
    mov    rdx,r14
    call   ref_43_I7PNVR
    mov    rcx,rbp
    mov    rdx,r14
    mov    r8,rbx
    call   ref_44_DS7IPR
    lea    rdx,[r15+r12*8]
    add    rdx,0xfffffffffffffff8
    lea    rax,[r15+r13*8-0x8]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_41_unnamed_4]
    lea    rcx,[rsp+0x128]
    mov    r9,rbx
at_1_0881:
    call   ref_45_DV2AXY
    mov    r13,QWORD PTR [rbp+0x0]
    mov    QWORD PTR [rsp+0xc0],0x1
    test   r13,r13
    {disp32} jle    at_1_0971
    mov    eax,0x1
    lea    rbx,[rip + ref_35_unnamed_2]
    lea    r14,[rsp+0xc0]
    jmp    at_1_08d8
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_08c0:
    lea    rcx,[rax+0x1]
at_1_08c4:
    mov    QWORD PTR [rsp+0xc0],rcx
    cmp    rax,r13
    mov    rax,rcx
    {disp32} jge    at_1_0971
at_1_08d8:
    mov    rcx,rax
    shl    rcx,0x4
    movsd  xmm0,QWORD PTR [rcx+rdi*1-0x8]
    ucomisd xmm0,QWORD PTR [rcx+rdi*1-0x10]
    ja     at_1_08c0
    lea    rbp,[rax-0x1]
    imul   rbp,rax
    shr    rbp,1
    lea    rax,[r12+rbp*1]
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,r14
    mov    r8,rbx
    call   ref_36_DV7SCP
    mov    rax,QWORD PTR [rsp+0xc0]
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    rdx,QWORD PTR [rcx]
    cmp    rax,rdx
    jge    at_1_0971
    lea    rcx,[r12+rbp*1]
    dec    rcx
    lea    r8,[rcx+rax*2]
    lea    rcx,[rax+0x1]
    mov    QWORD PTR [rsp+0x120],rcx
    neg    rdx
    mov    r9,rcx
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0950:
    mov    QWORD PTR [r15+r8*8-0x8],0x0
    add    r8,r9
    lea    r10,[rdx+r9*1]
    inc    r10
    inc    r9
    cmp    r10,0x1
    jne    at_1_0950
    {disp32} jmp    at_1_08c4
at_1_0971:
    mov    QWORD PTR [rsi],0x2
    mov    r14,QWORD PTR [rsp+0x228]
    mov    QWORD PTR [rsp+0x38],r14
    mov    QWORD PTR [rsp+0x30],r15
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    QWORD PTR [rsp+0x28],rbp
    mov    rax,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rbx,QWORD PTR [rsp+0xd0]
    mov    rcx,rbx
    mov    rdx,QWORD PTR [rsp+0xe0]
    mov    r8,rsi
    mov    r9,QWORD PTR [rsp+0x200]
    call   ref_46_DITSUM
at_1_09c7:
    lea    rax,[rsi+0xf0]
    mov    rcx,QWORD PTR [rsi+0xf0]
    cmp    rcx,QWORD PTR [rsi+0x88]
    {disp32} jge    at_1_0ad8
at_1_09e2:
    lea    rdx,[rcx+0x1]
    mov    QWORD PTR [rax],rdx
    test   rcx,rcx
    {disp32} je     at_1_0a82
    mov    rax,QWORD PTR [rsi+0x138]
    mov    rcx,QWORD PTR [rbp+0x0]
    mov    QWORD PTR [rsp+0xc0],0x1
    test   rcx,rcx
    jle    at_1_0a45
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    xor    r8d,r8d
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0a20:
    movsd  xmm0,QWORD PTR [rbx+r8*8]
    mulsd  xmm0,QWORD PTR [rdx+r8*8]
    movsd  QWORD PTR [rdx+r8*8],xmm0
    inc    r8
    cmp    r8,rcx
    jl     at_1_0a20
    inc    rcx
    mov    QWORD PTR [rsp+0xc0],rcx
at_1_0a45:
    movsd  xmm6,QWORD PTR [r15+0x78]
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,rbp
    call   ref_40_DV2NRM
    mulsd  xmm0,xmm6
    ucomisd xmm0,QWORD PTR [r15+0x38]
    seta   al
    movsd  xmm1,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    ucomisd xmm1,QWORD PTR [r15+0x78]
    ja     at_1_0a7c
    test   al,al
    je     at_1_0a82
at_1_0a7c:
    movsd  QWORD PTR [r15+0x38],xmm0
at_1_0a82:
    mov    rax,QWORD PTR [rsi+0x150]
    movsd  xmm0,QWORD PTR [r15+0x48]
    movsd  QWORD PTR [r15+0x60],xmm0
    mov    QWORD PTR [rsi+0xe0],0x4
    mov    rcx,QWORD PTR [rsi+0x1b8]
    mov    rdx,rcx
    neg    rdx
    cmovns rdx,rcx
    mov    rcx,QWORD PTR [rsi+0x20]
    mov    QWORD PTR [rsi+0x1b8],rdx
    mov    QWORD PTR [rsi+0x1f8],rcx
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,rbp
    mov    r8,r14
    call   ref_47_DV7CPY
    jmp    at_1_0ae4
at_1_0ad8:
    mov    QWORD PTR [rsi],0xa
    {disp32} jmp    at_1_1ce1
at_1_0ae4:
    mov    rcx,rsi
    call   ref_48_STOPX
    test   al,0x1
    {disp32} jne    at_1_1936
at_1_0af4:
    mov    rax,QWORD PTR [rsi+0x198]
    add    rax,QWORD PTR [rsi+0x80]
    cmp    QWORD PTR [rsi+0x28],rax
    {disp32} jge    at_1_192f
    lea    rax,[rsi+0x20]
    mov    QWORD PTR [rsp+0xe8],rax
    mov    r11,QWORD PTR [rsi+0x20]
at_1_0b1c:
    mov    r12,QWORD PTR [rsi+0x120]
    mov    r9,QWORD PTR [rsi+0x138]
    mov    rax,QWORD PTR [rbp+0x0]
    lea    rcx,[rax+r12*1]
    mov    QWORD PTR [rsp+0xd8],rcx
    mov    r10,QWORD PTR [rsi+0x150]
    mov    r8,QWORD PTR [rsi+0x200]
    mov    r13,QWORD PTR [rsi+0x1b8]
    mov    rdx,QWORD PTR [rsi+0x140]
    mov    QWORD PTR [rsp+0xf8],rdx
    mov    rbp,QWORD PTR [rsi+0x1c8]
    mov    rcx,QWORD PTR [rsi+0x258]
    lea    rbx,[rax+rbp*1]
    lea    r14,[rbx+rax*1]
    mov    QWORD PTR [rsp+0xc8],r14
    cmp    r11,0x2
    {disp32} je     at_1_0d39
    mov    r11,QWORD PTR [rsi+0x268]
    test   r11,r11
    {disp32} jle    at_1_0d39
    mov    r14,QWORD PTR [rsi+0x260]
    test   r14,r14
    {disp32} jle    at_1_0d39
    lea    rdx,[rsi+0x140]
    mov    QWORD PTR [rsp+0x130],rdx
    mov    rdx,r12
    mov    r12,QWORD PTR [rsi+0x148]
    add    rax,r8
    lea    rbp,[rsi+0x250]
    mov    QWORD PTR [rsp+0xe8],rbp
    lea    rcx,[rsi+rcx*8]
    add    rcx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x108],rcx
    lea    rcx,[rsi+rbx*8-0x8]
    mov    QWORD PTR [rsp+0x100],rcx
    mov    rcx,QWORD PTR [rsp+0xc8]
    lea    rcx,[rsi+rcx*8-0x8]
    mov    QWORD PTR [rsp+0xc8],rcx
    lea    rbx,[rsi+0x108]
    lea    r12,[r15+r12*8-0x8]
    lea    r14,[r15+r14*8-0x8]
    lea    r11,[r15+r11*8-0x8]
    lea    rbp,[r15+r9*8-0x8]
    mov    rcx,QWORD PTR [rsp+0xd8]
    lea    r9,[r15+rcx*8-0x8]
    mov    rcx,r8
    lea    r8,[r15+rdx*8-0x8]
    lea    rdx,[r15+rcx*8-0x8]
    lea    rcx,[r15+rax*8-0x8]
    lea    rax,[r15+r10*8-0x8]
    lea    r10,[rsi+0x178]
    mov    QWORD PTR [rsp+0xb0],rax
    mov    QWORD PTR [rsp+0xa0],rcx
    mov    QWORD PTR [rsp+0x98],rdx
    mov    QWORD PTR [rsp+0x88],r8
    mov    QWORD PTR [rsp+0x80],r9
    mov    QWORD PTR [rsp+0x78],rbp
    mov    QWORD PTR [rsp+0x70],r11
    mov    QWORD PTR [rsp+0x68],r14
    mov    rax,QWORD PTR [rsp+0x130]
    mov    QWORD PTR [rsp+0x60],rax
    mov    QWORD PTR [rsp+0x58],r10
    mov    QWORD PTR [rsp+0x40],r12
    mov    QWORD PTR [rsp+0x38],rbx
    mov    rax,QWORD PTR [rsp+0xc8]
    mov    QWORD PTR [rsp+0x30],rax
    mov    r14,QWORD PTR [rsp+0x228]
    mov    QWORD PTR [rsp+0xa8],r14
    mov    QWORD PTR [rsp+0x90],r15
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    QWORD PTR [rsp+0x50],rbp
    mov    rax,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rsp+0x48],rax
    mov    rax,QWORD PTR [rsp+0x100]
    mov    QWORD PTR [rsp+0x28],rax
    mov    rax,QWORD PTR [rsp+0x108]
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rdi
    mov    rbx,QWORD PTR [rsp+0xd0]
    mov    rdx,rbx
    mov    r9,QWORD PTR [rsp+0xe8]
    mov    r8,QWORD PTR [rsp+0xe0]
    call   ref_49_DL7MSB
    mov    rax,r13
    neg    rax
    cmovns rax,r13
    mov    QWORD PTR [rsi+0x1b8],rax
    mov    QWORD PTR [rsi+0x100],0xffffffffffffffff
    {disp32} jmp    at_1_1099
at_1_0d39:
    test   r13,r13
    mov    QWORD PTR [rsp+0xf0],r10
    mov    QWORD PTR [rsp+0x118],r8
    mov    QWORD PTR [rsp+0x110],r9
    jle    at_1_0d5e
    mov    r14,r13
    {disp32} jmp    at_1_0f7b
at_1_0d5e:
    lea    rax,[rdx+0x1]
    imul   rax,rdx
    shr    rax,1
    mov    QWORD PTR [rsp+0x168],rax
    mov    r14,r13
    neg    r14
    mov    QWORD PTR [rsi+0x1b8],r14
    mov    QWORD PTR [rsi+0x248],0x0
    test   rdx,rdx
    {disp32} jle    at_1_0f7b
    lea    rdx,[rsi+rbp*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[rsi+rcx*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    QWORD PTR [rsp+0x108],rdx
    call   ref_50_I7COPY
    mov    rax,QWORD PTR [rsi+0x230]
    test   rax,rax
    jle    at_1_0e27
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    rcx,QWORD PTR [rcx]
    lea    r9,[rcx+0x1]
    imul   r9,rcx
    shr    r9,1
    mov    rcx,r13
    not    rcx
    lea    rdx,[r15+rcx*8]
    mov    QWORD PTR [rsp+0x100],rdx
    lea    r8,[r15+rax*8]
    add    r8,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x150],r9
    lea    rcx,[rsp+0x150]
    call   ref_47_DV7CPY
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    rdx,QWORD PTR [rsp+0x108]
    mov    r8,QWORD PTR [rsp+0x100]
    call   ref_44_DS7IPR
    jmp    at_1_0e4d
at_1_0e27:
    mov    rax,QWORD PTR [rsi+0x268]
    mov    rcx,r13
    not    rcx
    lea    rdx,[r15+rcx*8]
    lea    r8,[r15+rax*8]
    add    r8,0xfffffffffffffff8
    lea    rcx,[rsp+0xf8]
    call   ref_42_DL7SQR
at_1_0e4d:
    mov    QWORD PTR [rsp+0x100],r12
    mov    rax,QWORD PTR [rsp+0xe8]
    cmp    QWORD PTR [rax],0x1
    jne    at_1_0e77
    not    r13
    lea    rax,[r15+r13*8]
    mov    QWORD PTR [rsp+0xe8],rax
    {disp32} jmp    at_1_0f03
at_1_0e77:
    mov    rax,QWORD PTR [rsi+0x148]
    mov    rcx,QWORD PTR [rsi+0x1e8]
    mov    rdx,QWORD PTR [rsp+0x210]
    mov    rdx,QWORD PTR [rdx]
    lea    r9,[rdx+0x1]
    imul   r9,rdx
    shr    r9,1
    lea    r12,[r15+rax*8]
    add    r12,0xfffffffffffffff8
    lea    r8,[r15+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x148],r9
    lea    rcx,[rsp+0x148]
    mov    rdx,r12
    call   ref_47_DV7CPY
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    rdx,QWORD PTR [rsp+0x108]
    mov    r8,r12
    call   ref_44_DS7IPR
    not    r13
    lea    rdx,[r15+r13*8]
    mov    QWORD PTR [rsp+0x20],rdx
    lea    r8,[rip + ref_51_unnamed_5]
    lea    rcx,[rsp+0x168]
    mov    QWORD PTR [rsp+0xe8],rdx
    mov    r9,r12
    call   ref_45_DV2AXY
at_1_0f03:
    mov    rax,QWORD PTR [rsp+0xd8]
    lea    r12,[r15+rax*8]
    add    r12,0xfffffffffffffff8
    mov    r13,QWORD PTR [rsp+0x210]
    mov    rcx,r13
    mov    rdx,r12
    mov    r8,QWORD PTR [rsp+0xd0]
    call   ref_47_DV7CPY
    mov    rcx,r13
    mov    rdx,QWORD PTR [rsp+0x108]
    mov    r8,r12
    call   ref_39_DV7IPR
    lea    rax,[rip + ref_37_unnamed_3]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rcx,[rsp+0xf8]
    mov    rdx,QWORD PTR [rsp+0xe8]
    mov    r8,rdx
    mov    r9,r12
    call   ref_52_DS7DMP
    mov    QWORD PTR [rsi+0x100],0xffffffffffffffff
    mov    r12,QWORD PTR [rsp+0x100]
at_1_0f7b:
    mov    rdx,QWORD PTR [rsi+0x148]
    lea    r8,[r15+r14*8]
    add    r8,0xfffffffffffffff8
    lea    rax,[rsi+rbp*8-0x8]
    lea    rcx,[rsi+rbx*8-0x8]
    mov    r9,QWORD PTR [rsp+0xc8]
    lea    r9,[rsi+r9*8-0x8]
    lea    r10,[rsi+0x100]
    lea    rdx,[r15+rdx*8-0x8]
    lea    r11,[rsi+0x178]
    mov    rbx,QWORD PTR [rsp+0x110]
    lea    rbx,[r15+rbx*8-0x8]
    mov    r14,QWORD PTR [rsp+0xd8]
    lea    r14,[r15+r14*8-0x8]
    lea    r12,[r15+r12*8-0x8]
    mov    r13,QWORD PTR [rsp+0x118]
    lea    r13,[r15+r13*8-0x8]
    mov    rbp,QWORD PTR [rsp+0xf0]
    lea    rbp,[r15+rbp*8-0x8]
    mov    QWORD PTR [rsp+0x98],rbp
    mov    QWORD PTR [rsp+0x88],r13
    mov    QWORD PTR [rsp+0x78],r12
    mov    QWORD PTR [rsp+0x70],r14
    mov    QWORD PTR [rsp+0x68],rbx
    lea    rbx,[rsp+0xf8]
    mov    QWORD PTR [rsp+0x60],rbx
    mov    QWORD PTR [rsp+0x58],r11
    mov    QWORD PTR [rsp+0x40],rdx
    mov    QWORD PTR [rsp+0x38],r10
    mov    QWORD PTR [rsp+0x30],r9
    mov    r14,QWORD PTR [rsp+0x228]
    mov    QWORD PTR [rsp+0x90],r14
    mov    QWORD PTR [rsp+0x80],r15
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    QWORD PTR [rsp+0x50],rbp
    mov    rdx,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rsp+0x48],rdx
    mov    QWORD PTR [rsp+0x28],rcx
    mov    QWORD PTR [rsp+0x20],rax
    mov    rcx,rdi
    mov    rbx,QWORD PTR [rsp+0xd0]
    mov    rdx,rbx
    mov    r9,QWORD PTR [rsp+0xe0]
    call   ref_53_DG7QSB
    cmp    QWORD PTR [rsi+0x108],0x0
    jle    at_1_1099
    mov    QWORD PTR [rsi+0x108],0x0
at_1_1099:
    mov    rax,QWORD PTR [rsi+0xe0]
    cmp    rax,0x6
    jne    at_1_10bc
    mov    r12d,0x2
    cmp    QWORD PTR [rsi+0x40],0x2
    {disp32} jne    at_1_1145
    {disp32} jmp    at_1_114b
at_1_10bc:
    mov    QWORD PTR [rsi+0x8],0x0
    xorpd  xmm0,xmm0
    ucomisd xmm0,QWORD PTR [r15+0x8]
    jae    at_1_1145
    cmp    rax,0x5
    {disp32} jne    at_1_19cf
    movsd  xmm0,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    ucomisd xmm0,QWORD PTR [r15+0x78]
    {disp32} jae    at_1_19cf
    movsd  xmm0,QWORD PTR [r15+0x30]
    movsd  xmm1,QWORD PTR [rip + ref_20_real_3ff3333333333333]
    mulsd  xmm1,QWORD PTR [r15+0x50]
    ucomisd xmm0,xmm1
    {disp32} ja     at_1_19cf
    mov    rax,QWORD PTR [rsi+0x138]
    mov    rcx,QWORD PTR [rsi+0x150]
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r9,[r15+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x20],r14
    lea    r8,[rip + ref_41_unnamed_4]
    mov    rcx,rbp
    call   ref_45_DV2AXY
    xor    r12d,r12d
    cmp    QWORD PTR [rsi+0x40],0x2
    je     at_1_114b
at_1_1145:
    mov    r12d,0x3
at_1_114b:
    lea    rax,[rsi+0x150]
    mov    QWORD PTR [rsp+0xc8],rax
    mov    r13,rbp
    mov    rbp,QWORD PTR [rsi+0x150]
    mov    rdx,rbx
    lea    rbx,[r15+rbp*8-0x8]
    mov    rcx,r13
    mov    r8,r14
    mov    r9,rbx
    call   ref_54_DRLDST
    movsd  QWORD PTR [r15+0x80],xmm0
    mov    rcx,rsi
    mov    rdx,QWORD PTR [rsp+0x200]
    mov    r8,QWORD PTR [rsp+0x208]
    mov    r9,r15
    call   ref_55_DA7SST
    lea    rax,[rsi+0x138]
    mov    QWORD PTR [rsp+0xf0],rax
    mov    rax,QWORD PTR [rsi+0x40]
    add    rbp,QWORD PTR [r13+0x0]
    mov    r13,QWORD PTR [rsi+0x138]
    inc    rax
    mov    QWORD PTR [rsp+0xc0],rax
    cmp    eax,0x1
    {disp32} je     at_1_1274
    cmp    eax,0x4
    je     at_1_11f8
    cmp    eax,0x3
    {disp32} jne    at_1_1261
    lea    rdx,[r15+rbp*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r15+r13*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x210]
    jmp    at_1_126f
at_1_11f8:
    lea    r14,[r15+r13*8]
    add    r14,0xfffffffffffffff8
    lea    r8,[r15+rbp*8-0x8]
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    rcx,rbp
    mov    rdx,r14
    call   ref_47_DV7CPY
    mov    QWORD PTR [rsp+0x20],rbx
    lea    r8,[rip + ref_51_unnamed_5]
    mov    rcx,rbp
    mov    rdx,QWORD PTR [rsp+0x228]
    mov    r9,r14
    call   ref_45_DV2AXY
    mov    rcx,rbp
    mov    rdx,QWORD PTR [rsp+0xd0]
    mov    r8,QWORD PTR [rsp+0x228]
    mov    r9,rbx
    call   ref_54_DRLDST
    movsd  QWORD PTR [r15+0x80],xmm0
    mov    QWORD PTR [rsi+0x40],r12
    jmp    at_1_1274
at_1_1261:
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    rdx,r14
    mov    r8,rbx
at_1_126f:
    call   ref_47_DV7CPY
at_1_1274:
    cmp    QWORD PTR [rsi+0x58],0x0
    je     at_1_12b9
    mov    rax,QWORD PTR [rsi+0x1b8]
    mov    rcx,QWORD PTR [rsi+0x1d8]
    mov    rdx,rax
    neg    rdx
    cmovns rdx,rax
    mov    QWORD PTR [rsi+0x1b8],rdx
    add    QWORD PTR [rsi+0x1f8],0x2
    lea    r8,[r15+rcx*8]
    add    r8,0xfffffffffffffff8
    lea    rcx,[rip + ref_56_unnamed_6]
    mov    rdx,r15
    call   ref_47_DV7CPY
at_1_12b9:
    mov    rax,QWORD PTR [rsi+0x20]
    mov    QWORD PTR [rsp+0xd8],rax
    mov    rbp,QWORD PTR [rsi+0xe0]
    lea    r14,[rsi+0x20]
    cmp    rbp,0x4
    jle    at_1_1320
    lea    rax,[rbp-0x4]
    lea    ecx,[rax-0x1]
    cmp    ecx,0x9
    ja     at_1_1320
    lea    rdx,[rip + ref_21_rdata + (at_9_0030 - def_21_rdata)]
    movsxd rcx,DWORD PTR [rdx+rcx*4]
    add    rcx,rdx
    mov    rbx,QWORD PTR [rsp+0xd0]
    jmp    rcx
at_1_12fa:
    mov    QWORD PTR [rsi+0x1b0],rax
    movsd  xmm0,QWORD PTR [r15+0x48]
    ucomisd xmm0,QWORD PTR [r15+0x60]
    {disp32} jb     at_1_143a
    mov    rbp,QWORD PTR [rsp+0x210]
    {disp32} jmp    at_1_144d
at_1_1320:
    movsd  xmm6,QWORD PTR [r15+0x30]
    subsd  xmm6,QWORD PTR [r15+0x50]
    mov    rax,QWORD PTR [rsi+0x1e8]
    lea    r8,[r15+rax*8]
    add    r8,0xfffffffffffffff8
    lea    rbx,[r15+r13*8-0x8]
    mov    r13,QWORD PTR [rsp+0x218]
    mov    rcx,r13
    mov    r12,QWORD PTR [rsp+0x230]
    mov    rdx,r12
    mov    r9,rbx
    call   ref_57_DS7LVM
    mov    rcx,r13
    mov    rdx,rbx
    mov    r8,r12
    call   ref_58_DD7TPR
    mulsd  xmm0,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    mov    rax,QWORD PTR [rsi+0x20]
    movapd xmm1,XMMWORD PTR [rip + ref_17_xmm_80000000000000008000000000000000]
    xorpd  xmm1,xmm0
    cmp    rax,0x1
    je     at_1_138e
    movapd xmm1,xmm0
at_1_138e:
    addsd  xmm1,xmm6
    movapd xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm1,xmm0
    mulsd  xmm1,QWORD PTR [r15+0x160]
    andpd  xmm6,xmm0
    ucomisd xmm1,xmm6
    jb     at_1_13da
    cmp    rbp,0x1
    {disp32} jg     at_1_1a5d
at_1_13bb:
    movsd  xmm0,QWORD PTR [r15+0x78]
    mulsd  xmm0,QWORD PTR [r15+0x8]
    movsd  QWORD PTR [r15+0x38],xmm0
    mov    rbp,QWORD PTR [rsp+0x210]
    {disp32} jmp    at_1_0ae4
at_1_13da:
    mov    ecx,0x3
    sub    rcx,rax
    mov    QWORD PTR [r14],rcx
    cmp    rbp,0x2
    {disp32} jg     at_1_1a5d
    mov    rax,QWORD PTR [rsi+0x1b8]
    mov    rcx,QWORD PTR [rsi+0x1d8]
    mov    rdx,rax
    neg    rdx
    cmovns rdx,rax
    mov    QWORD PTR [rsi+0x1b8],rdx
    add    QWORD PTR [rsi+0x1f8],0x2
    lea    rdx,[r15+rcx*8]
    add    rdx,0xfffffffffffffff8
    lea    rcx,[rip + ref_56_unnamed_6]
    mov    r8,r15
    call   ref_47_DV7CPY
    mov    rbp,QWORD PTR [rsp+0x210]
    {disp32} jmp    at_1_0ae4
at_1_143a:
    cmp    QWORD PTR [rsi+0x60],0xe
    mov    rbp,QWORD PTR [rsp+0x210]
    {disp32} jne    at_1_1a55
at_1_144d:
    cmp    QWORD PTR [rsi+0x1c0],0x0
    mov    r14,QWORD PTR [rsp+0x228]
    {disp32} je     at_1_1a30
    cmp    QWORD PTR [rsi+0x248],0x0
    {disp32} jne    at_1_1a30
    cmp    rax,0x6
    {disp32} jg     at_1_1a30
    cmp    QWORD PTR [rsi+0x210],0x0
    {disp32} jg     at_1_1a30
    cmp    QWORD PTR [rsi+0xc8],0x0
    {disp32} jg     at_1_1a30
    mov    rax,QWORD PTR [rsi+0x70]
    mov    rcx,rax
    neg    rcx
    cmovs  rcx,rax
    cmp    rcx,0x3
    {disp32} jae    at_1_1968
    cmp    QWORD PTR [rsi+0x40],0x0
    jne    at_1_14be
    mov    QWORD PTR [rsi+0x40],0x2
at_1_14be:
    mov    QWORD PTR [rsp+0x48],r14
    mov    QWORD PTR [rsp+0x40],r15
    mov    QWORD PTR [rsp+0x38],rbp
    mov    rax,QWORD PTR [rsp+0x208]
    mov    QWORD PTR [rsp+0x30],rax
    mov    rax,QWORD PTR [rsp+0x200]
    mov    QWORD PTR [rsp+0x28],rax
    mov    QWORD PTR [rsp+0x20],rsi
    lea    r9,[rsp+0xc0]
    mov    rcx,rdi
    mov    rdx,rbx
    mov    r8,QWORD PTR [rsp+0xe0]
    call   ref_59_DF7DHB
    mov    eax,DWORD PTR [rsp+0xc0]
    cmp    eax,0x3
    {disp32} jne    at_1_1905
    cmp    QWORD PTR [rsi+0x1b0],0x46
    {disp32} jne    at_1_1a30
    mov    r13,QWORD PTR [rsi+0x248]
    test   r13,r13
    {disp32} jg     at_1_0773
    {disp32} jmp    at_1_1a30
at_1_153a:
    mov    QWORD PTR [rsp+0xe8],r14
    movsd  xmm0,QWORD PTR [r15+0x118]
    movsd  QWORD PTR [r15+0x38],xmm0
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    r11,QWORD PTR [rsp+0xd8]
    {disp32} jmp    at_1_0b1c
at_1_1566:
    lea    rbx,[rsi+0xe0]
    lea    rax,[rsi+0x200]
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    r12,QWORD PTR [rsp+0x218]
    mov    r14,QWORD PTR [rsp+0xf0]
at_1_158c:
    mov    rax,QWORD PTR [rax]
    mov    QWORD PTR [rsp+0xe8],rax
    lea    r13,[r15+rax*8]
    add    r13,0xfffffffffffffff8
    mov    rax,QWORD PTR [rsp+0xe0]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_41_unnamed_4]
    mov    rcx,rbp
    mov    rdx,r13
    mov    r9,r13
    call   ref_45_DV2AXY
    mov    r14,QWORD PTR [r14]
    mov    rcx,QWORD PTR [rbp+0x0]
    lea    rax,[rcx+r14*1]
    mov    rdx,QWORD PTR [rsp+0xc8]
    mov    rdx,QWORD PTR [rdx]
    mov    QWORD PTR [rsp+0xf0],rdx
    cmp    QWORD PTR [rbx],0x3
    mov    r9,QWORD PTR [rsp+0xd0]
    {disp32} jne    at_1_16a4
    mov    QWORD PTR [rsp+0xc0],0x1
    test   rcx,rcx
    jle    at_1_163c
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    xor    r8d,r8d
    nop    DWORD PTR [rax]
at_1_1610:
    movsd  xmm0,QWORD PTR [rdx+r8*8]
    subsd  xmm0,QWORD PTR [r13+r8*8+0x0]
    divsd  xmm0,QWORD PTR [r9+r8*8]
    movsd  QWORD PTR [rdx+r8*8],xmm0
    inc    r8
    cmp    r8,rcx
    jl     at_1_1610
    inc    rcx
    mov    QWORD PTR [rsp+0xc0],rcx
at_1_163c:
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,rbp
    mov    rbx,rdx
    call   ref_40_DV2NRM
    movsd  xmm1,QWORD PTR [r15]
    mulsd  xmm1,QWORD PTR [r15+0xe0]
    ucomisd xmm1,xmm0
    jae    at_1_1690
    lea    r8,[r15+r14*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,rbp
    mov    rdx,QWORD PTR [rsp+0xe0]
    call   ref_58_DD7TPR
    movsd  xmm1,QWORD PTR [r15+0x18]
    mulsd  xmm1,QWORD PTR [r15+0xe8]
    ucomisd xmm0,xmm1
    jae    at_1_169f
at_1_1690:
    movsd  xmm0,QWORD PTR [r15+0xb0]
    movsd  QWORD PTR [r15+0x78],xmm0
at_1_169f:
    mov    rbp,rbx
    jmp    at_1_16ac
at_1_16a4:
    lea    rbp,[r15+rax*8]
    add    rbp,0xfffffffffffffff8
at_1_16ac:
    mov    rax,QWORD PTR [rsp+0xe0]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_41_unnamed_4]
    mov    rcx,r12
    mov    rbx,QWORD PTR [rsp+0x230]
    mov    rdx,rbx
    mov    r9,rbx
    call   ref_45_DV2AXY
    mov    rax,QWORD PTR [rsi+0x1e8]
    lea    r8,[r15+rax*8]
    add    r8,0xfffffffffffffff8
    lea    r14,[r15+r14*8-0x8]
    mov    rcx,r12
    mov    rdx,rbp
    mov    QWORD PTR [rsp+0xd8],r8
    mov    r9,r14
    call   ref_57_DS7LVM
    mov    rcx,r12
    mov    rdx,r14
    mov    r8,rbp
    call   ref_58_DD7TPR
    movapd xmm6,xmm0
    movapd xmm7,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm6,xmm7
    mov    rcx,r12
    mov    rdx,r14
    mov    r8,rbx
    call   ref_58_DD7TPR
    andpd  xmm0,xmm7
    lea    rcx,[r15+0x1b0]
    movabs rax,0x3ff0000000000000
    mov    QWORD PTR [r15+0x1b0],rax
    ucomisd xmm6,xmm0
    jbe    at_1_1756
    divsd  xmm0,xmm6
    movsd  QWORD PTR [rcx],xmm0
at_1_1756:
    mov    QWORD PTR [rsp+0xc8],rcx
    mov    rax,QWORD PTR [rsi+0x230]
    test   rax,rax
    jle    at_1_1785
    lea    r8,[r15+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,r12
    mov    rdx,r13
    mov    r9,r14
    call   ref_57_DS7LVM
    {disp32} jmp    at_1_188a
at_1_1785:
    mov    QWORD PTR [rsp+0x118],rbp
    mov    rbp,QWORD PTR [rsi+0x258]
    mov    rax,QWORD PTR [rsi+0x268]
    mov    QWORD PTR [rsp+0x110],rax
    mov    rbx,QWORD PTR [rsp+0x210]
    mov    rcx,rbx
    mov    rdx,r13
    mov    r8,r14
    call   ref_47_DV7CPY
    mov    rcx,QWORD PTR [r12]
    mov    rdx,QWORD PTR [rsp+0xe8]
    add    rdx,rcx
    mov    QWORD PTR [rsp+0xc0],rdx
    mov    rax,QWORD PTR [rbx]
    sub    rax,rcx
    jle    at_1_17fc
    lea    rdx,[r15+rdx*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x140],rax
    lea    r8,[rip + ref_35_unnamed_2]
    lea    rcx,[rsp+0x140]
    call   ref_36_DV7SCP
at_1_17fc:
    lea    r12,[rsi+rbp*8]
    add    r12,0xfffffffffffffff8
    mov    rbx,QWORD PTR [rsp+0x210]
    mov    rcx,rbx
    mov    rdx,r12
    mov    r8,r13
    call   ref_39_DV7IPR
    mov    rax,QWORD PTR [rsp+0x110]
    lea    rbp,[r15+rax*8]
    add    rbp,0xfffffffffffffff8
    mov    rcx,rbx
    mov    rdx,r13
    mov    r8,rbp
    mov    r9,r13
    call   ref_60_DL7TVM
    mov    rcx,rbx
    mov    rdx,r13
    mov    r8,rbp
    mov    r9,r13
    call   ref_61_DL7VML
    mov    rax,QWORD PTR [rbx]
    add    rax,QWORD PTR [rsi+0x1c8]
    lea    rbp,[rsi+rax*8]
    add    rbp,0xfffffffffffffff8
    mov    rcx,rbx
    mov    rdx,rbp
    mov    r8,r12
    call   ref_43_I7PNVR
    mov    rcx,rbx
    mov    rdx,rbp
    mov    r8,r13
    call   ref_39_DV7IPR
    mov    r12,QWORD PTR [rsp+0x218]
    mov    rbp,QWORD PTR [rsp+0x118]
at_1_188a:
    mov    QWORD PTR [rsp+0x20],r13
    lea    r8,[rip + ref_51_unnamed_5]
    mov    rcx,r12
    mov    rdx,r13
    mov    rbx,QWORD PTR [rsp+0x230]
    mov    r9,rbx
    call   ref_45_DV2AXY
    lea    rdx,[r15+0x170]
    mov    rax,QWORD PTR [rsp+0xf0]
    lea    rax,[r15+rax*8]
    add    rax,0xfffffffffffffff8
    lea    rcx,[r15+0x1b8]
    mov    QWORD PTR [rsp+0x48],rbx
    mov    QWORD PTR [rsp+0x40],rcx
    mov    QWORD PTR [rsp+0x38],r13
    mov    QWORD PTR [rsp+0x30],rax
    mov    QWORD PTR [rsp+0x28],rbp
    mov    QWORD PTR [rsp+0x20],r14
    mov    rcx,QWORD PTR [rsp+0xd8]
    mov    r8,r12
    mov    r9,QWORD PTR [rsp+0xc8]
    call   ref_62_DS7LUP
    {disp32} jmp    at_1_0971
at_1_1905:
    cmp    eax,0x2
    jne    at_1_195c
    mov    rax,QWORD PTR [rsi+0x1a0]
    inc    rax
    mov    QWORD PTR [rsi+0x1a0],rax
    inc    QWORD PTR [rsi+0xe8]
    add    rax,QWORD PTR [rsi+0x28]
    mov    QWORD PTR [rsi+0x30],rax
    {disp32} jmp    at_1_1c26
at_1_192f:
    mov    eax,0x9
    jmp    at_1_193b
at_1_1936:
    mov    eax,0xb
at_1_193b:
    mov    QWORD PTR [rsi],rax
    movsd  xmm0,QWORD PTR [r15+0x48]
    ucomisd xmm0,QWORD PTR [r15+0x60]
    {disp32} jae    at_1_1ce1
    mov    QWORD PTR [rsi+0x1b0],rax
    {disp32} jmp    at_1_1bf0
at_1_195c:
    inc    QWORD PTR [rsi+0x198]
    {disp32} jmp    at_1_1a01
at_1_1968:
    mov    rdx,QWORD PTR [rsi+0x1b8]
    mov    rcx,QWORD PTR [rsi+0x230]
    mov    rax,rdx
    neg    rax
    cmovs  rax,rdx
    mov    QWORD PTR [rsi+0x248],rax
    mov    rdx,rax
    neg    rdx
    mov    QWORD PTR [rsi+0x1b8],rdx
    test   rcx,rcx
    jle    at_1_1a11
    mov    rdx,QWORD PTR [rbp+0x0]
    lea    r9,[rdx+0x1]
    imul   r9,rdx
    shr    r9,1
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r15+rcx*8]
    add    r8,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x138],r9
    lea    rcx,[rsp+0x138]
    call   ref_47_DV7CPY
    jmp    at_1_1a30
at_1_19cf:
    mov    rax,QWORD PTR [rsi+0x138]
    mov    rcx,QWORD PTR [rsi+0x150]
    lea    r9,[r15+rax*8]
    add    r9,0xfffffffffffffff8
    lea    rax,[r15+rcx*8-0x8]
    mov    QWORD PTR [rsp+0x20],rax
    lea    r8,[rip + ref_51_unnamed_5]
    mov    rcx,rbp
    mov    rdx,r14
    call   ref_45_DV2AXY
at_1_1a01:
    inc    QWORD PTR [rsi+0x28]
    mov    QWORD PTR [rsi],0x1
    {disp32} jmp    at_1_1c80
at_1_1a11:
    mov    rcx,QWORD PTR [rsi+0x268]
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r15+rcx*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,rbp
    call   ref_42_DL7SQR
at_1_1a30:
    mov    QWORD PTR [rsi+0x110],0x0
    mov    rax,QWORD PTR [rsi+0x1b0]
    mov    QWORD PTR [rsi],rax
    mov    QWORD PTR [rsi+0x1b0],0x0
    {disp32} jmp    at_1_1ce1
at_1_1a55:
    mov    QWORD PTR [rsi+0x60],0xe
at_1_1a5d:
    mov    QWORD PTR [rsi+0xc8],0x0
    mov    QWORD PTR [rsi+0x210],0x0
    cmp    QWORD PTR [rsi+0xe0],0x3
    mov    r12,QWORD PTR [rsp+0x218]
    {disp32} jne    at_1_1bf0
    mov    r13,QWORD PTR [rsi+0x138]
    mov    rbx,QWORD PTR [rsi+0x150]
    mov    rcx,QWORD PTR [rsp+0x210]
    mov    rbp,QWORD PTR [rcx]
    add    rbp,r13
    mov    rax,QWORD PTR [rsi+0x230]
    test   rax,rax
    jle    at_1_1ad3
    lea    rdx,[r15+rbp*8]
    add    rdx,0xfffffffffffffff8
    lea    r8,[r15+rax*8]
    add    r8,0xfffffffffffffff8
    lea    r9,[r15+r13*8]
    add    r9,0xfffffffffffffff8
    call   ref_57_DS7LVM
    {disp32} jmp    at_1_1b9c
at_1_1ad3:
    mov    r12,QWORD PTR [rsi+0x258]
    mov    rax,QWORD PTR [rsi+0x268]
    mov    QWORD PTR [rsp+0xf0],rax
    mov    QWORD PTR [rsp+0xd0],rbx
    lea    rbx,[r15+rbp*8]
    add    rbx,0xfffffffffffffff8
    lea    r8,[r15+r13*8]
    add    r8,0xfffffffffffffff8
    mov    r14,rcx
    mov    rdx,rbx
    call   ref_47_DV7CPY
    lea    rdx,[rsi+r12*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0xc8],rdx
    mov    rcx,r14
    mov    r8,rbx
    call   ref_39_DV7IPR
    mov    rax,QWORD PTR [rsp+0xf0]
    lea    r12,[r15+rax*8]
    add    r12,0xfffffffffffffff8
    mov    rcx,r14
    mov    rdx,rbx
    mov    r8,r12
    mov    r9,rbx
    call   ref_60_DL7TVM
    mov    rcx,r14
    mov    rdx,rbx
    mov    r8,r12
    mov    r9,rbx
    call   ref_61_DL7VML
    mov    rax,QWORD PTR [r14]
    add    rax,QWORD PTR [rsi+0x1c8]
    lea    r12,[rsi+rax*8]
    add    r12,0xfffffffffffffff8
    mov    rcx,r14
    mov    rdx,r12
    mov    r8,QWORD PTR [rsp+0xc8]
    call   ref_43_I7PNVR
    mov    rcx,r14
    mov    rdx,r12
    mov    r12,QWORD PTR [rsp+0x218]
    mov    r8,rbx
    mov    rbx,QWORD PTR [rsp+0xd0]
    call   ref_39_DV7IPR
at_1_1b9c:
    mov    rax,QWORD PTR [rsp+0xd8]
    cmp    rax,0x1
    je     at_1_1bf0
    mov    rax,QWORD PTR [rsi+0x1e8]
    lea    rbx,[r15+rbx*8]
    add    rbx,0xfffffffffffffff8
    lea    r8,[r15+rax*8-0x8]
    lea    r9,[r15+r13*8]
    add    r9,0xfffffffffffffff8
    mov    rcx,r12
    mov    rdx,rbx
    call   ref_57_DS7LVM
    lea    rdx,[r15+rbp*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x20],rdx
    lea    r8,[rip + ref_51_unnamed_5]
    mov    rcx,r12
    mov    r9,rbx
    call   ref_45_DV2AXY
at_1_1bf0:
    inc    QWORD PTR [rsi+0xe8]
    mov    rax,QWORD PTR [rsi+0x200]
    lea    rdx,[r15+rax*8]
    add    rdx,0xfffffffffffffff8
    mov    rbp,QWORD PTR [rsp+0x210]
    mov    rcx,rbp
    mov    r8,QWORD PTR [rsp+0xe0]
    call   ref_47_DV7CPY
    mov    r14,QWORD PTR [rsp+0x228]
at_1_1c26:
    mov    QWORD PTR [rsi],0x2
    mov    rax,QWORD PTR [rsi+0x1c8]
    mov    rcx,QWORD PTR [rsi+0x258]
    lea    rdx,[rsi+rax*8]
    add    rdx,0xfffffffffffffff8
    lea    rbx,[rsi+rcx*8]
    add    rbx,0xfffffffffffffff8
    mov    rcx,rbp
    mov    r8,rbx
    call   ref_43_I7PNVR
    mov    rax,QWORD PTR [rbp+0x0]
    test   rax,rax
    jle    at_1_1cd9
    xor    ecx,ecx
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1c70:
    lea    rdx,[rcx+0x1]
    mov    QWORD PTR [rbx+rcx*8],rdx
    mov    rcx,rdx
    cmp    rdx,rax
    jl     at_1_1c70
at_1_1c80:
    mov    rax,QWORD PTR [rbp+0x0]
    test   rax,rax
    jle    at_1_1cd9
    add    rdi,0x8
    xor    ecx,ecx
    jmp    at_1_1cac
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_1ca0:
    add    rdi,0x10
    inc    rcx
    cmp    rcx,rax
    jge    at_1_1cd9
at_1_1cac:
    movsd  xmm0,QWORD PTR [r14+rcx*8]
    movsd  xmm1,QWORD PTR [rdi-0x8]
    ucomisd xmm1,xmm0
    jbe    at_1_1cc7
    movsd  QWORD PTR [r14+rcx*8],xmm1
    movapd xmm0,xmm1
at_1_1cc7:
    movsd  xmm1,QWORD PTR [rdi]
    ucomisd xmm0,xmm1
    jbe    at_1_1ca0
    movsd  QWORD PTR [r14+rcx*8],xmm1
    jmp    at_1_1ca0
at_1_1cd9:
    mov    QWORD PTR [rsi+0x8],0x0
at_1_1ce1:
    movaps xmm6,XMMWORD PTR [rsp+0x170]
    movaps xmm7,XMMWORD PTR [rsp+0x180]
    add    rsp,0x198
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_1d05:
    mov    QWORD PTR [rsi],0x40
    jmp    at_1_1ce1
at_1_1d0e:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fe0000000000000:
at_6_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_80000000000000008000000000000000:
at_7_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_3ff3333333333333:
at_8_0000:
    .quad 0x3ff3333333333333    # binary64 1.2
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
at_9_0000:
    .long ref_0_text + (at_1_1145 - at_1_0000) + (. - at_9_0000) + 4    # slot 0 -> at_1_1145
    .long ref_0_text + (at_1_1145 - at_1_0000) + (. - at_9_0000) + 4    # slot 1 -> at_1_1145
    .long ref_0_text + (at_1_1145 - at_1_0000) + (. - at_9_0000) + 4    # slot 2 -> at_1_1145
    .long ref_0_text + (at_1_1145 - at_1_0000) + (. - at_9_0000) + 4    # slot 3 -> at_1_1145
    .long ref_0_text + (at_1_1145 - at_1_0000) + (. - at_9_0000) + 4    # slot 4 -> at_1_1145
    .long ref_0_text + (at_1_1145 - at_1_0000) + (. - at_9_0000) + 4    # slot 5 -> at_1_1145
    .long ref_0_text + (at_1_0152 - at_1_0000) + (. - at_9_0000) + 4    # slot 6 -> at_1_0152
    .long ref_0_text + (at_1_09c7 - at_1_0000) + (. - at_9_0000) + 4    # slot 7 -> at_1_09c7
    .long ref_0_text + (at_1_0152 - at_1_0000) + (. - at_9_0000) + 4    # slot 8 -> at_1_0152
    .long ref_0_text + (at_1_0417 - at_1_0000) + (. - at_9_0000) + 4    # slot 9 -> at_1_0417
    .long ref_0_text + (at_1_0417 - at_1_0000) + (. - at_9_0000) + 4    # slot 10 -> at_1_0417
    .long ref_0_text + (at_1_0407 - at_1_0000) + (. - at_9_0000) + 4    # slot 11 -> at_1_0407
at_9_0030:
    .long ref_0_text + (at_1_13bb - at_1_0000) + (. - at_9_0030) + 4    # slot 0 -> at_1_13bb
    .long ref_0_text + (at_1_153a - at_1_0000) + (. - at_9_0030) + 4    # slot 1 -> at_1_153a
    .long ref_0_text + (at_1_12fa - at_1_0000) + (. - at_9_0030) + 4    # slot 2 -> at_1_12fa
    .long ref_0_text + (at_1_12fa - at_1_0000) + (. - at_9_0030) + 4    # slot 3 -> at_1_12fa
    .long ref_0_text + (at_1_12fa - at_1_0000) + (. - at_9_0030) + 4    # slot 4 -> at_1_12fa
    .long ref_0_text + (at_1_12fa - at_1_0000) + (. - at_9_0030) + 4    # slot 5 -> at_1_12fa
    .long ref_0_text + (at_1_12fa - at_1_0000) + (. - at_9_0030) + 4    # slot 6 -> at_1_12fa
    .long ref_0_text + (at_1_12fa - at_1_0000) + (. - at_9_0030) + 4    # slot 7 -> at_1_12fa
    .long ref_0_text + (at_1_1d05 - at_1_0000) + (. - at_9_0030) + 4    # slot 8 -> at_1_1d05
    .long ref_0_text + (at_1_1566 - at_1_0000) + (. - at_9_0030) + 4    # slot 9 -> at_1_1566
def_31_unnamed_1:
at_9_0058:
    .quad 0x0000000000000001
def_37_unnamed_3:
at_9_0060:
    .quad 0xffffffffffffffff
def_56_unnamed_6:
at_9_0068:
    .quad 0x0000000000000009
def_41_unnamed_4:
at_9_0070:
    .quad 0xbff0000000000000    # binary64 -1.0
def_35_unnamed_2:
at_9_0078:
    .zero 8
def_51_unnamed_5:
at_9_0080:
    .quad 0x3ff0000000000000    # binary64 1.0
at_9_0088:
end_s9:

# .xdata  (COFF section 10)
.section .s10,"dr"
def_23_xdata:
at_10_0000:
    .byte 0x01    # version 1
    .byte at_1_0025 - at_1_0000    # prologue size
    .byte 0x0e    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0025 - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x17
    .byte 0x00
    .byte at_1_001c - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x18
    .byte 0x00
    .byte at_1_0013 - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x33
    .byte 0x00
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_10_0020:
end_s10:

# .drectve  (COFF section 11)
.section .s11,"dr"
def_25_drectve:
at_11_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_11_00b9:
end_s11:

# .pdata  (COFF section 12)
.section .s12,"dr"
def_27_pdata:
at_12_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_1d0e - def_0_text)    # image-relative end
    .long ref_23_xdata    # image-relative unwind info
at_12_000c:
end_s12:

# MEMBER df7hes.obj
# Entry points: DF7HES
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_31_DF7HES:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x38
at_1_0010:
    mov    rbx,QWORD PTR [rsp+0xb8]
    mov    rsi,QWORD PTR [rsp+0xb0]
    mov    QWORD PTR [r8],0x4
    mov    r14,QWORD PTR [r9+0x110]
    test   r14,r14
    jg     at_1_006e
    mov    rax,QWORD PTR [r9+0x1b8]
    mov    r10,rax
    neg    r10
    cmovns r10,rax
    mov    QWORD PTR [r9+0x1b8],r10
    mov    QWORD PTR [r9+0x248],0x0
    mov    QWORD PTR [r9+0x100],0xffffffffffffffff
    movsd  xmm0,QWORD PTR [rbx+0x48]
    movsd  QWORD PTR [rbx+0x1a0],xmm0
at_1_006e:
    mov    rax,QWORD PTR [rsi]
    cmp    r14,rax
    {disp32} jg     at_1_0480
    mov    r13,QWORD PTR [rsp+0xc0]
    mov    r12,QWORD PTR [r9+0x70]
    mov    rdi,QWORD PTR [r9+0x200]
    add    rdi,rax
    test   r12,r12
    js     at_1_00fc
    test   r14,r14
    {disp32} jle    at_1_01c3
    movsd  xmm1,QWORD PTR [rbx+0x190]
    movsd  xmm0,QWORD PTR [rbx+0x198]
    movsd  QWORD PTR [r13+r14*8-0x8],xmm1
    cmp    QWORD PTR [r9+0x8],0x0
    {disp32} je     at_1_0209
    movapd xmm2,xmm0
    mulsd  xmm2,xmm1
    mov    r11,0xfffffffffffffffe
    xorpd  xmm3,xmm3
    ucomisd xmm2,xmm3
    {disp32} jbe    at_1_0441
    add    rbx,0x198
    lea    rax,[r14*8-0x8]
    add    rax,r13
    mulsd  xmm0,QWORD PTR [rip + ref_8_real_bfe0000000000000]
    {disp32} jmp    at_1_0346
at_1_00fc:
    test   r14,r14
    {disp32} jle    at_1_035e
    lea    r10,[rdi-0x1]
    mov    QWORD PTR [rsp+0x20],r10
    lea    r11,[r14-0x1]
    mov    rbp,r11
    imul   rbp,r14
    shr    rbp,1
    mov    r10,QWORD PTR [r9+0x1b8]
    mov    r15,QWORD PTR [r9+0x1f0]
    test   r15,r15
    {disp32} jle    at_1_03e4
    movsd  xmm0,QWORD PTR [rbx+0x198]
    movsd  QWORD PTR [r13+r15*8-0x8],xmm0
    mov    r11,0xfffffffffffffffe
    cmp    QWORD PTR [r9+0x8],0x0
    {disp32} jne    at_1_0441
    mov    r13,QWORD PTR [rsp+0x20]
    lea    r11,[r15+r13*1]
    mov    QWORD PTR [rsp+0x30],r11
    add    rbp,r15
    mov    r11,r10
    mov    r10,r13
    mov    r13,r11
    not    r13
    add    r13,rbp
    movsd  xmm0,QWORD PTR [rbx+r13*8-0x8]
    addsd  xmm0,QWORD PTR [rbx+0x48]
    lea    rbp,[r10+r14*1]
    mov    QWORD PTR [rsp+0x28],rbp
    mov    rbp,QWORD PTR [rsp+0x30]
    movsd  xmm1,QWORD PTR [rbx+rbp*8-0x8]
    mov    rbp,QWORD PTR [rsp+0x28]
    mulsd  xmm1,QWORD PTR [rbx+rbp*8-0x8]
    divsd  xmm0,xmm1
    movsd  QWORD PTR [rbx+r13*8-0x8],xmm0
    cmp    r15,r14
    {disp32} jae    at_1_051e
    inc    r15
    mov    r13,QWORD PTR [rsp+0xc0]
    {disp32} jmp    at_1_0575
at_1_01c3:
    lea    rax,[rbx+rdi*8]
    add    rax,0xfffffffffffffff8
    mov    r15,rcx
    mov    rcx,rsi
    mov    rdi,rdx
    mov    rdx,rax
    mov    r13,r8
    mov    r8,rdi
    mov    rbp,r9
    call   ref_32_DV7CPY
    mov    rcx,r15
    mov    rdx,rdi
    mov    r9,rbp
    mov    r8,r13
    mov    rbp,QWORD PTR [rsp+0xc0]
    mov    rax,QWORD PTR [r9+0x30]
    mov    QWORD PTR [r9+0x58],rax
    mov    rax,QWORD PTR [rsi]
    {disp32} jmp    at_1_02d9
at_1_0209:
    mov    rbp,r13
    lea    r10,[r14-0x1]
    mov    r11,QWORD PTR [r9+0x1b8]
    lea    rdi,[rbx+rdi*8]
    add    rdi,0xfffffffffffffff8
    xor    r15d,r15d
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0230:
    movsd  xmm1,QWORD PTR [rdx+r15*8]
    subsd  xmm1,QWORD PTR [rdi+r15*8]
    divsd  xmm1,xmm0
    movsd  QWORD PTR [rdx+r15*8],xmm1
    inc    r15
    cmp    rax,r15
    jne    at_1_0230
    mov    r15,r10
    imul   r15,r14
    shr    r15,1
    mov    rdi,r15
    sub    rdi,r11
    cmp    r14,0x1
    je     at_1_02ae
    shl    r15,0x3
    lea    r13,[r11*8+0x0]
    sub    r15,r13
    add    r15,rbx
    add    r15,0xfffffffffffffff8
    xor    r13d,r13d
    movsd  xmm0,QWORD PTR [rip + ref_11_real_3fe0000000000000]
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0290:
    movsd  xmm1,QWORD PTR [r15+r13*8]
    addsd  xmm1,QWORD PTR [rdx+r13*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [r15+r13*8],xmm1
    inc    r13
    cmp    r10,r13
    jne    at_1_0290
at_1_02ae:
    neg    r11
    add    r10,rdi
    lea    rdi,[rax+0x1]
    mov    r15,r14
    {disp8} nop    DWORD PTR [rax+rax*1+0x0]
at_1_02c0:
    movsd  xmm0,QWORD PTR [rdx+r15*8-0x8]
    movsd  QWORD PTR [rbx+r10*8-0x8],xmm0
    add    r10,r15
    inc    r15
    cmp    rdi,r15
    jne    at_1_02c0
at_1_02d9:
    lea    r10,[r14+0x1]
    mov    QWORD PTR [r9+0x110],r10
    cmp    r14,rax
    {disp32} jge    at_1_0441
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    divsd  xmm0,QWORD PTR [rcx+r14*8]
    movsd  xmm1,QWORD PTR [rbp+r14*8+0x0]
    movapd xmm2,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm2,xmm1
    maxsd  xmm0,xmm2
    mulsd  xmm0,QWORD PTR [rbx+0x158]
    xorpd  xmm2,xmm2
    ucomisd xmm2,xmm1
    jbe    at_1_032c
    xorpd  xmm0,XMMWORD PTR [rip + ref_20_xmm_80000000000000008000000000000000]
at_1_032c:
    lea    rax,[r14*8+0x0]
    add    rax,rbp
    movsd  QWORD PTR [rbx+0x190],xmm1
    add    rbx,0x198
at_1_0346:
    addsd  xmm1,xmm0
    movsd  QWORD PTR [rax],xmm1
    movsd  QWORD PTR [rbx],xmm0
    mov    QWORD PTR [r8],0x2
    {disp32} jmp    at_1_0480
at_1_035e:
    mov    QWORD PTR [r9+0x1f0],0x0
at_1_0369:
    lea    r10,[r14+0x1]
    mov    QWORD PTR [r9+0x110],r10
    cmp    r14,rax
    {disp32} jge    at_1_0441
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    divsd  xmm0,QWORD PTR [rcx+r14*8]
    movsd  xmm1,QWORD PTR [r13+r14*8+0x0]
    movapd xmm2,XMMWORD PTR [rip + ref_17_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm2,xmm1
    maxsd  xmm0,xmm2
    mulsd  xmm0,QWORD PTR [rbx+0x148]
    xorpd  xmm2,xmm2
    ucomisd xmm2,xmm1
    jbe    at_1_03bc
    xorpd  xmm0,XMMWORD PTR [rip + ref_20_xmm_80000000000000008000000000000000]
at_1_03bc:
    movsd  QWORD PTR [rbx+0x190],xmm1
    addsd  xmm1,xmm0
    movsd  QWORD PTR [r13+r14*8+0x0],xmm1
    add    rdi,r14
    movsd  QWORD PTR [rbx+rdi*8-0x8],xmm0
    mov    QWORD PTR [r8],0x1
    {disp32} jmp    at_1_0480
at_1_03e4:
    cmp    QWORD PTR [r9+0x8],0x0
    {disp32} je     at_1_0492
    mov    rcx,QWORD PTR [rsp+0x20]
    add    rcx,r14
    movsd  xmm0,QWORD PTR [rbx+rcx*8-0x8]
    movsd  xmm1,QWORD PTR [r13+0x190]
    movapd xmm2,xmm0
    mulsd  xmm2,xmm1
    mov    r11,0xfffffffffffffffe
    xorpd  xmm3,xmm3
    ucomisd xmm2,xmm3
    jbe    at_1_0441
    mulsd  xmm0,QWORD PTR [rip + ref_8_real_bfe0000000000000]
    addsd  xmm1,xmm0
    movsd  QWORD PTR [r13+r14*8-0x8],xmm1
    movsd  QWORD PTR [rbx+rcx*8-0x8],xmm0
    mov    QWORD PTR [r8],0x1
    jmp    at_1_0480
at_1_0441:
    mov    QWORD PTR [r9+0x248],r11
    movsd  xmm0,QWORD PTR [rbx+0x1a0]
    movsd  QWORD PTR [rbx+0x48],xmm0
    mov    QWORD PTR [r8],0x3
    test   r12,r12
    js     at_1_0480
    mov    rcx,QWORD PTR [r9+0x58]
    mov    QWORD PTR [r9+0x30],rcx
    add    rax,QWORD PTR [r9+0x200]
    lea    r8,[rbx+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,rsi
    call   ref_32_DV7CPY
at_1_0480:
    nop
    add    rsp,0x38
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_0492:
    lea    rcx,[rax-0x1]
    imul   rcx,rax
    shr    rcx,1
    mov    rax,rcx
    sub    rax,r10
    add    rax,r11
    movsd  xmm0,QWORD PTR [rbx+0x48]
    movsd  QWORD PTR [rbx+rax*8-0x8],xmm0
    test   r11,r11
    {disp32} je     at_1_0548
    lea    rax,[rbp*8+0x0]
    lea    rdx,[r10*8+0x0]
    sub    rax,rdx
    add    rax,rbx
    add    rax,0xfffffffffffffff8
    shl    rcx,0x3
    sub    rcx,rdx
    add    rcx,rbx
    add    rcx,0xfffffffffffffff8
    xor    edx,edx
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_04f0:
    movsd  xmm0,QWORD PTR [rbx+0x48]
    movsd  xmm1,QWORD PTR [rbx+0x1a0]
    addsd  xmm0,QWORD PTR [rcx+rdx*8]
    subsd  xmm1,xmm0
    movsd  QWORD PTR [rax+rdx*8],xmm1
    inc    rdx
    cmp    r11,rdx
    jne    at_1_04f0
    add    rbp,r14
    not    r10
    add    rbp,r10
    jmp    at_1_054b
at_1_051e:
    neg    r11
    mov    QWORD PTR [r9+0x1f0],0x0
    movsd  xmm0,QWORD PTR [rbx+0x190]
    mov    r13,QWORD PTR [rsp+0xc0]
    movsd  QWORD PTR [r13+r14*8-0x8],xmm0
    {disp32} jmp    at_1_0369
at_1_0548:
    sub    rbp,r10
at_1_054b:
    mov    r10,QWORD PTR [rsp+0x20]
    movsd  xmm0,QWORD PTR [rip + ref_23_real_4000000000000000]
    mulsd  xmm0,QWORD PTR [rbx+0x1a0]
    movsd  xmm1,QWORD PTR [rbx+0x48]
    subsd  xmm1,xmm0
    movsd  QWORD PTR [rbx+rbp*8-0x8],xmm1
    mov    r15d,0x1
at_1_0575:
    mov    QWORD PTR [r9+0x1f0],r15
    add    r10,r15
    movsd  xmm1,QWORD PTR [r13+r15*8-0x8]
    movsd  QWORD PTR [rbx+0x198],xmm1
    movsd  xmm0,QWORD PTR [rbx+r10*8-0x8]
    addsd  xmm1,xmm0
    movsd  QWORD PTR [r13+r15*8-0x8],xmm1
    cmp    r15,r14
    jne    at_1_05b8
    movsd  xmm1,QWORD PTR [rbx+0x190]
    subsd  xmm1,xmm0
    movsd  QWORD PTR [r13+r15*8-0x8],xmm1
at_1_05b8:
    mov    QWORD PTR [r8],0x1
    {disp32} jmp    at_1_0480
at_1_05c4:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_bfe0000000000000:
at_4_0000:
    .quad 0xbfe0000000000000    # binary64 -0.5
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3fe0000000000000:
at_5_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_5_0008:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3ff0000000000000:
at_6_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_xmm_7fffffffffffffff7fffffffffffffff:
at_7_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_7_0010:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_xmm_80000000000000008000000000000000:
at_8_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_8_0010:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_4000000000000000:
at_9_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_9_0008:
end_s9:

# .xdata  (COFF section 10)
.section .s10,"dr"
def_24_xdata:
at_10_0000:
    .byte 0x01    # version 1
    .byte at_1_0010 - at_1_0000    # prologue size
    .byte 0x09    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0x62
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_10_0018:
end_s10:

# .drectve  (COFF section 11)
.section .s11,"dr"
def_26_drectve:
at_11_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_11_00b9:
end_s11:

# .pdata  (COFF section 12)
.section .s12,"dr"
def_28_pdata:
at_12_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_05c4 - def_0_text)    # image-relative end
    .long ref_24_xdata    # image-relative unwind info
at_12_000c:
end_s12:

# MEMBER df7dhb.obj
# Entry points: DF7DHB
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_33_DF7DHB:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbp
at_1_000b:
    push   rbx
at_1_000c:
    sub    rsp,0x68
at_1_0010:
    mov    rsi,r9
    mov    rdi,r8
    mov    QWORD PTR [rsp+0x40],rdx
    mov    r15,rcx
    mov    r12,QWORD PTR [rsp+0xf0]
    mov    rbp,QWORD PTR [rsp+0xe8]
    mov    r13,QWORD PTR [rsp+0xd0]
    mov    QWORD PTR [r9],0x4
    mov    rax,QWORD PTR [r13+0x70]
    mov    QWORD PTR [rsp+0x50],rax
    mov    rbx,QWORD PTR [r13+0x110]
    test   rbx,rbx
    jg     at_1_00c4
    mov    rax,QWORD PTR [r13+0x1b8]
    mov    r14,rax
    neg    r14
    cmovs  r14,rax
    mov    rax,r14
    neg    rax
    mov    QWORD PTR [r13+0x1b8],rax
    mov    QWORD PTR [r13+0x248],0x0
    mov    QWORD PTR [r13+0x100],0xffffffffffffffff
    movsd  xmm0,QWORD PTR [r12+0x48]
    movsd  QWORD PTR [r12+0x1a0],xmm0
    mov    rax,QWORD PTR [rbp+0x0]
    lea    rcx,[rax+0x1]
    imul   rcx,rax
    shr    rcx,1
    lea    rdx,[r12+r14*8]
    add    rdx,0xfffffffffffffff8
    mov    QWORD PTR [rsp+0x60],rcx
    lea    r8,[rip + ref_34_unnamed_1]
    lea    rcx,[rsp+0x60]
    call   ref_35_DV7SCP
at_1_00c4:
    mov    rax,QWORD PTR [rbp+0x0]
    cmp    rbx,rax
    {disp32} jg     at_1_0529
    mov    rcx,QWORD PTR [rsp+0xf8]
    mov    r11,QWORD PTR [r13+0x200]
    lea    r8,[r11+rax*1]
    cmp    QWORD PTR [rsp+0x50],0x0
    {disp32} js     at_1_0230
    test   rbx,rbx
    {disp32} jle    at_1_02ee
    movsd  xmm1,QWORD PTR [r12+0x190]
    movsd  xmm0,QWORD PTR [r12+0x198]
    movsd  QWORD PTR [rcx+rbx*8-0x8],xmm1
    cmp    QWORD PTR [r13+0x8],0x0
    je     at_1_0174
    movsd  xmm2,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    rcx,QWORD PTR [rsp+0x40]
    divsd  xmm2,QWORD PTR [rcx+rbx*8-0x8]
    movapd xmm3,XMMWORD PTR [rip + ref_11_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm1,xmm3
    maxsd  xmm2,xmm1
    mulsd  xmm2,QWORD PTR [r12+0x158]
    mulsd  xmm0,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    movapd xmm1,xmm0
    divsd  xmm1,xmm2
    andpd  xmm1,xmm3
    mov    r14,0xfffffffffffffffe
    movsd  xmm2,QWORD PTR [rip + ref_17_real_3fb999999999999a]
    ucomisd xmm2,xmm1
    {disp32} jae    at_1_04dc
at_1_0174:
    lea    rdx,[rbx-0x1]
    mov    r14,QWORD PTR [r13+0x1b8]
    movsd  xmm1,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    divsd  xmm1,xmm0
    lea    rcx,[r12+r8*8]
    add    rcx,0xfffffffffffffff8
    xor    r8d,r8d
    .fill 1, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_01a0:
    movsd  xmm0,QWORD PTR [rdi+r8*8]
    subsd  xmm0,QWORD PTR [rcx+r8*8]
    mulsd  xmm0,xmm1
    movsd  QWORD PTR [rdi+r8*8],xmm0
    inc    r8
    cmp    rax,r8
    jne    at_1_01a0
    mov    r8,rdx
    imul   r8,rbx
    shr    r8,1
    mov    rcx,r8
    sub    rcx,r14
    cmp    rbx,0x1
    {disp32} jne    at_1_038a
at_1_01d8:
    neg    r14
    add    rdx,rcx
    lea    rcx,[rax+0x1]
    mov    r8,rbx
    shl    r8,0x4
    add    r8,r15
    add    r8,0xfffffffffffffff8
    mov    r9,rbx
    jmp    at_1_0213
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0200:
    add    rdx,r9
    inc    r9
    add    r8,0x10
    cmp    rcx,r9
    {disp32} je     at_1_030d
at_1_0213:
    movsd  xmm0,QWORD PTR [r8]
    ucomisd xmm0,QWORD PTR [r8-0x8]
    jbe    at_1_0200
    movsd  xmm0,QWORD PTR [rdi+r9*8-0x8]
    movsd  QWORD PTR [r12+rdx*8-0x8],xmm0
    jmp    at_1_0200
at_1_0230:
    dec    r8
    lea    r9,[rbx-0x1]
    mov    r10,r9
    imul   r10,rbx
    shr    r10,1
    mov    rcx,QWORD PTR [r13+0x1b8]
    mov    rdx,rcx
    mov    QWORD PTR [rsp+0x28],rcx
    neg    rcx
    test   rbx,rbx
    {disp32} jle    at_1_0368
    mov    r14,0xfffffffffffffffe
    cmp    QWORD PTR [r13+0x8],0x0
    {disp32} jne    at_1_04dc
    mov    QWORD PTR [rsp+0x48],r11
    mov    QWORD PTR [rsp+0x38],rcx
    mov    QWORD PTR [rsp+0x30],r8
    mov    rdx,QWORD PTR [r13+0x1f0]
    mov    r11,QWORD PTR [rsp+0x28]
    not    r11
    test   rdx,rdx
    {disp32} jle    at_1_04b4
    movsd  xmm0,QWORD PTR [r12+0x198]
    mov    r8,QWORD PTR [rsp+0x30]
    lea    rcx,[rdx+r8*1]
    add    r11,r10
    add    r11,rdx
    movsd  xmm1,QWORD PTR [r12+r11*8-0x8]
    addsd  xmm1,QWORD PTR [r12+0x48]
    add    r8,rbx
    movsd  xmm2,QWORD PTR [r12+rcx*8-0x8]
    mulsd  xmm2,QWORD PTR [r12+r8*8-0x8]
    mov    rcx,QWORD PTR [rsp+0xf8]
    movsd  QWORD PTR [rcx+rdx*8-0x8],xmm0
    divsd  xmm1,xmm2
    movsd  QWORD PTR [r12+r11*8-0x8],xmm1
    mov    r11,rbx
    {disp32} jmp    at_1_0732
at_1_02ee:
    lea    rdx,[r12+r8*8]
    add    rdx,0xfffffffffffffff8
    mov    rcx,rbp
    mov    r8,rdi
    call   ref_36_DV7CPY
    mov    rax,QWORD PTR [r13+0x30]
    mov    QWORD PTR [r13+0x58],rax
    mov    rax,QWORD PTR [rbp+0x0]
at_1_030d:
    lea    rcx,[rbx+0x1]
    cmp    rbx,rax
    jge    at_1_035c
    lea    rdx,[rax+0x1]
    neg    rax
    shl    rbx,0x4
    lea    r8,[rbx+r15*1]
    add    r8,0x8
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0330:
    movsd  xmm4,QWORD PTR [r8-0x8]
    movsd  xmm3,QWORD PTR [r8]
    ucomisd xmm4,xmm3
    {disp32} jb     at_1_03f5
    lea    r9,[rax+rcx*1]
    inc    r9
    inc    rcx
    add    r8,0x10
    cmp    r9,0x1
    jne    at_1_0330
    mov    rcx,rdx
at_1_035c:
    mov    QWORD PTR [r13+0x110],rcx
    {disp32} jmp    at_1_04dc
at_1_0368:
    mov    QWORD PTR [rsp+0x48],r11
    mov    QWORD PTR [rsp+0x38],rcx
    mov    QWORD PTR [rsp+0x30],r8
    mov    QWORD PTR [r13+0x1f0],0x0
    mov    r11,rbx
    {disp32} jmp    at_1_0797
at_1_038a:
    shl    r8,0x3
    lea    r9,[r14*8+0x0]
    sub    r8,r9
    add    r8,r12
    add    r8,0xfffffffffffffff8
    lea    r9,[r15+0x8]
    xor    r10d,r10d
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3fe0000000000000]
    jmp    at_1_03d0
    .fill 6, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_03c0:
    inc    r10
    add    r9,0x10
    cmp    rdx,r10
    {disp32} je     at_1_01d8
at_1_03d0:
    movsd  xmm1,QWORD PTR [r9]
    ucomisd xmm1,QWORD PTR [r9-0x8]
    jbe    at_1_03c0
    movsd  xmm1,QWORD PTR [r8+r10*8]
    addsd  xmm1,QWORD PTR [rdi+r10*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [r8+r10*8],xmm1
    jmp    at_1_03c0
at_1_03f5:
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    rax,QWORD PTR [rsp+0x40]
    divsd  xmm0,QWORD PTR [rax+rcx*8-0x8]
    mov    rax,QWORD PTR [rsp+0xf8]
    movsd  xmm1,QWORD PTR [rax+rcx*8-0x8]
    movapd xmm2,XMMWORD PTR [rip + ref_11_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm2,xmm1
    maxsd  xmm0,xmm2
    mulsd  xmm0,QWORD PTR [r12+0x158]
    mov    QWORD PTR [r13+0x110],rcx
    xorpd  xmm2,xmm2
    ucomisd xmm2,xmm1
    jbe    at_1_0466
    movapd xmm2,xmm1
    subsd  xmm2,xmm0
    ucomisd xmm2,xmm4
    jae    at_1_0489
    movapd xmm2,xmm1
    addsd  xmm2,xmm0
    mov    r14,0xfffffffffffffffe
    ucomisd xmm3,xmm2
    jae    at_1_0491
    jmp    at_1_04dc
at_1_0466:
    movapd xmm2,xmm1
    addsd  xmm2,xmm0
    ucomisd xmm3,xmm2
    jae    at_1_0491
    movapd xmm2,xmm1
    subsd  xmm2,xmm0
    mov    r14,0xfffffffffffffffe
    ucomisd xmm2,xmm4
    jb     at_1_04dc
at_1_0489:
    xorpd  xmm0,XMMWORD PTR [rip + ref_20_xmm_80000000000000008000000000000000]
at_1_0491:
    movsd  QWORD PTR [r12+0x190],xmm1
    movsd  QWORD PTR [rax+rcx*8-0x8],xmm2
    movsd  QWORD PTR [r12+0x198],xmm0
    mov    QWORD PTR [rsi],0x2
    jmp    at_1_0529
at_1_04b4:
    lea    rdx,[rax-0x1]
    imul   rdx,rax
    shr    rdx,1
    lea    rbp,[r12+0x48]
    add    r11,r9
    mov    rcx,rdx
    mov    QWORD PTR [rsp+0x58],rdx
    add    r11,rdx
    mov    edx,0x1
    mov    r14,rbx
    jmp    at_1_053b
at_1_04dc:
    mov    QWORD PTR [r13+0x248],r14
    movsd  xmm0,QWORD PTR [r12+0x1a0]
    movsd  QWORD PTR [r12+0x48],xmm0
    mov    QWORD PTR [rsi],0x3
    cmp    QWORD PTR [rsp+0x50],0x0
    js     at_1_0529
    mov    rax,QWORD PTR [r13+0x58]
    mov    QWORD PTR [r13+0x30],rax
    mov    rax,QWORD PTR [rbp+0x0]
    add    rax,QWORD PTR [r13+0x200]
    lea    r8,[r12+rax*8]
    add    r8,0xfffffffffffffff8
    mov    rcx,rbp
    mov    rdx,rdi
    call   ref_36_DV7CPY
at_1_0529:
    nop
    add    rsp,0x68
    pop    rbx
    pop    rbp
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_053b:
    movsd  xmm0,QWORD PTR [rbp+0x0]
    movsd  QWORD PTR [r12+r11*8],xmm0
    mov    r11,r14
    mov    rbp,QWORD PTR [rsp+0xe8]
at_1_0551:
    movsd  xmm1,QWORD PTR [r12+0x190]
    lea    r8,[r11-0x1]
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    mov    rcx,QWORD PTR [rsp+0x40]
    divsd  xmm0,QWORD PTR [rcx+r11*8-0x8]
    movapd xmm2,XMMWORD PTR [rip + ref_11_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm2,xmm1
    maxsd  xmm0,xmm2
    mulsd  xmm0,QWORD PTR [r12+0x148]
    movapd xmm2,xmm1
    addsd  xmm2,xmm0
    lea    rcx,[r11*2-0x2]
    shl    r8,0x4
    movsd  xmm4,QWORD PTR [r15+r8*1+0x8]
    ucomisd xmm4,xmm2
    movapd xmm3,xmm1
    subsd  xmm3,xmm0
    jb     at_1_05d8
    ucomisd xmm3,QWORD PTR [r15+rcx*8]
    jb     at_1_060d
    xor    r14d,r14d
    xorpd  xmm3,xmm3
    ucomisd xmm1,xmm3
    jae    at_1_062e
    movapd xmm3,xmm1
    subsd  xmm3,xmm0
    xor    r14d,r14d
    jmp    at_1_05ff
at_1_05d8:
    movsd  xmm2,QWORD PTR [rip + ref_23_real_4000000000000000]
    mulsd  xmm2,xmm0
    movapd xmm4,xmm1
    subsd  xmm4,xmm2
    mov    r14,0xffffffffffffffff
    ucomisd xmm4,QWORD PTR [r15+rcx*8]
    {disp32} jb     at_1_092c
at_1_05ff:
    xorpd  xmm0,XMMWORD PTR [rip + ref_20_xmm_80000000000000008000000000000000]
    movapd xmm2,xmm3
    jmp    at_1_062e
at_1_060d:
    movsd  xmm3,QWORD PTR [rip + ref_23_real_4000000000000000]
    mulsd  xmm3,xmm0
    addsd  xmm3,xmm1
    mov    r14,0xffffffffffffffff
    ucomisd xmm4,xmm3
    {disp32} jb     at_1_092c
at_1_062e:
    cmp    edx,0x1
    {disp32} jne    at_1_08c4
    cmp    rbx,0x1
    jg     at_1_064a
    mov    rcx,r10
    sub    rcx,QWORD PTR [rsp+0x28]
    {disp32} jmp    at_1_06e4
at_1_064a:
    lea    rdx,[r15+0x8]
    lea    rcx,[r10*8+0x0]
    mov    r8,QWORD PTR [rsp+0x28]
    lea    r8,[r8*8+0x0]
    sub    rcx,r8
    lea    rbp,[rcx+r12*1]
    add    rbp,0xfffffffffffffff8
    mov    rcx,QWORD PTR [rsp+0x58]
    lea    rcx,[rcx*8+0x0]
    sub    rcx,r8
    lea    r8,[rcx+r12*1]
    add    r8,0xfffffffffffffff8
    xor    ecx,ecx
    jmp    at_1_06a2
    {disp8} nop    WORD PTR [rax+rax*1+0x0]
at_1_0690:
    movsd  QWORD PTR [rbp+rcx*8+0x0],xmm0
    inc    rcx
    add    rdx,0x10
    cmp    r9,rcx
    je     at_1_06ce
at_1_06a2:
    movsd  xmm1,QWORD PTR [rdx]
    xorpd  xmm0,xmm0
    ucomisd xmm1,QWORD PTR [rdx-0x8]
    jbe    at_1_0690
    movsd  xmm1,QWORD PTR [r12+0x48]
    movsd  xmm0,QWORD PTR [r12+0x1a0]
    addsd  xmm1,QWORD PTR [r8+rcx*8]
    subsd  xmm0,xmm1
    jmp    at_1_0690
at_1_06ce:
    mov    rcx,QWORD PTR [rsp+0x28]
    not    rcx
    add    rcx,rbx
    add    rcx,r10
    mov    rbp,QWORD PTR [rsp+0xe8]
at_1_06e4:
    movsd  xmm1,QWORD PTR [r12+0x48]
    movsd  xmm0,QWORD PTR [rip + ref_23_real_4000000000000000]
    movsd  xmm2,QWORD PTR [r12+0x1a0]
    mulsd  xmm2,xmm0
    subsd  xmm1,xmm2
    movsd  QWORD PTR [r12+rcx*8-0x8],xmm1
    xor    edx,edx
    test   r14b,0x1
    je     at_1_0732
    mulsd  xmm0,QWORD PTR [r12+0x48]
    movsd  xmm1,QWORD PTR [r12+0x1a0]
    subsd  xmm1,xmm0
    movsd  QWORD PTR [r12+rcx*8-0x8],xmm1
    xor    edx,edx
at_1_0732:
    cmp    rdx,r11
    jge    at_1_0773
    lea    r14,[rdx+0x1]
    shl    rdx,0x4
    lea    rcx,[rdx+r15*1]
    add    rcx,0x8
    mov    rdx,r11
    neg    rdx
    nop    DWORD PTR [rax]
at_1_0750:
    movsd  xmm0,QWORD PTR [rcx]
    ucomisd xmm0,QWORD PTR [rcx-0x8]
    {disp32} ja     at_1_0868
    add    rcx,0x10
    lea    r8,[rdx+r14*1]
    inc    r8
    inc    r14
    cmp    r8,0x1
    jne    at_1_0750
at_1_0773:
    mov    QWORD PTR [r13+0x1f0],0x0
    movsd  xmm0,QWORD PTR [r12+0x190]
    mov    rcx,QWORD PTR [rsp+0xf8]
    movsd  QWORD PTR [rcx+r11*8-0x8],xmm0
at_1_0797:
    lea    r14,[r11+0x1]
    cmp    r11,rax
    jge    at_1_0800
    lea    rcx,[rax+0x1]
    mov    rdx,rax
    neg    rdx
    mov    r8,QWORD PTR [rsp+0xf8]
    lea    rbp,[r8+r11*8]
    shl    r11,0x4
    lea    r8,[r11+r15*1]
    add    r8,0x8
    .fill 5, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_07d0:
    movsd  xmm0,QWORD PTR [r8]
    ucomisd xmm0,QWORD PTR [r8-0x8]
    ja     at_1_0851
    lea    r11,[rdx+r14*1]
    inc    r11
    inc    r14
    add    rbp,0x8
    add    r8,0x10
    cmp    r11,0x1
    jne    at_1_07d0
    mov    r14,rcx
    mov    rbp,QWORD PTR [rsp+0xe8]
at_1_0800:
    mov    QWORD PTR [r13+0x110],r14
    mov    rcx,rax
    shl    rcx,0x4
    movsd  xmm0,QWORD PTR [rcx+r15*1-0x8]
    ucomisd xmm0,QWORD PTR [rcx+r15*1-0x10]
    ja     at_1_0847
    lea    rcx,[rax-0x1]
    imul   rcx,rax
    shr    rcx,1
    mov    rax,QWORD PTR [rsp+0x28]
    not    rax
    add    rax,rcx
    lea    rdx,[r12+rax*8]
    lea    r8,[rip + ref_34_unnamed_1]
    mov    rcx,rbp
    call   ref_35_DV7SCP
at_1_0847:
    mov    r14,QWORD PTR [rsp+0x38]
    {disp32} jmp    at_1_04dc
at_1_0851:
    mov    QWORD PTR [r13+0x110],r14
    mov    edx,0x3
    mov    r11d,0x32
    {disp32} jmp    at_1_053b
at_1_0868:
    mov    QWORD PTR [r13+0x1f0],r14
    mov    rdx,QWORD PTR [rsp+0xf8]
    movsd  xmm0,QWORD PTR [rdx+r14*8-0x8]
    movsd  QWORD PTR [r12+0x198],xmm0
    mov    rcx,QWORD PTR [rsp+0x48]
    lea    rcx,[rcx*8+0x0]
    lea    rcx,[rcx+rax*8]
    add    rcx,r12
    addsd  xmm0,QWORD PTR [rcx+r14*8-0x10]
    movsd  QWORD PTR [rdx+r14*8-0x8],xmm0
    mov    QWORD PTR [rsi],0x1
    mov    edx,0x2
    cmp    r14,r11
    {disp32} jge    at_1_0551
    {disp32} jmp    at_1_0529
at_1_08c4:
    cmp    edx,0x2
    jne    at_1_0902
    movapd xmm2,xmm1
    subsd  xmm2,xmm0
    mov    rax,QWORD PTR [rsp+0xf8]
    movsd  QWORD PTR [rax+r11*8-0x8],xmm2
    test   r14b,0x1
    {disp32} je     at_1_0529
    mulsd  xmm0,QWORD PTR [rip + ref_23_real_4000000000000000]
    addsd  xmm1,xmm0
    movsd  QWORD PTR [rax+r11*8-0x8],xmm1
    {disp32} jmp    at_1_0529
at_1_0902:
    mov    rax,QWORD PTR [rsp+0xf8]
    movsd  QWORD PTR [rax+r11*8-0x8],xmm2
    mov    rax,QWORD PTR [rsp+0x30]
    add    rax,r11
    movsd  QWORD PTR [r12+rax*8-0x8],xmm0
    mov    QWORD PTR [rsi],0x1
    {disp32} jmp    at_1_0529
at_1_092c:
    mov    r14,0xfffffffffffffffe
    {disp32} jmp    at_1_04dc
at_1_0938:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_7fffffffffffffff7fffffffffffffff:
at_5_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_5_0010:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3fe0000000000000:
at_6_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_real_3fb999999999999a:
at_7_0000:
    .quad 0x3fb999999999999a    # binary64 0.1
at_7_0008:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_xmm_80000000000000008000000000000000:
at_8_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_8_0010:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_4000000000000000:
at_9_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_9_0008:
end_s9:

# .xdata  (COFF section 10)
.section .s10,"dr"
def_24_xdata:
at_10_0000:
    .byte 0x01    # version 1
    .byte at_1_0010 - at_1_0000    # prologue size
    .byte 0x09    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0010 - at_1_0000    # ALLOC_SMALL
    .byte 0xc2
    .byte at_1_000c - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x50
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
    .byte 0x00
    .byte 0x00
at_10_0018:
end_s10:

# .rdata  (COFF section 11)
.section .s11,"dr"
def_26_rdata:
def_34_unnamed_1:
at_11_0000:
    .zero 8
at_11_0008:
end_s11:

# .drectve  (COFF section 12)
.section .s12,"dr"
def_28_drectve:
at_12_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_12_00b9:
end_s12:

# .pdata  (COFF section 13)
.section .s13,"dr"
def_30_pdata:
at_13_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0938 - def_0_text)    # image-relative end
    .long ref_24_xdata    # image-relative unwind info
at_13_000c:
end_s13:

# MEMBER dd7upd.obj
# Entry points: DD7UPD
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_18_DD7UPD:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbx
at_1_000b:
    sub    rsp,0x20
at_1_000f:
    mov    rax,QWORD PTR [rsp+0x90]
    mov    r14,QWORD PTR [rax]
    cmp    QWORD PTR [r8+0x78],0x1
    je     at_1_002f
    cmp    QWORD PTR [r8+0xf0],0x0
    {disp32} jg     at_1_01d2
at_1_002f:
    mov    rdi,QWORD PTR [rsp+0xb0]
    mov    rsi,QWORD PTR [rsp+0xa8]
    mov    rax,QWORD PTR [r8+0x208]
    mov    r9,rax
    neg    r9
    mov    rbx,rax
    cmovns rbx,r9
    test   rax,rax
    js     at_1_008e
    mov    QWORD PTR [r8+0x208],r9
    lea    rax,[rdi+rax*8]
    add    rax,0xfffffffffffffff8
    lea    r9,[rip + ref_19_unnamed_1]
    mov    r15,rcx
    mov    rcx,rsi
    mov    r12,rdx
    mov    rdx,rax
    mov    r13,r8
    mov    r8,r9
    call   ref_20_DV7SCP
    mov    rdx,r12
    mov    r8,r13
    mov    rcx,r15
at_1_008e:
    mov    r10,QWORD PTR [rsp+0xa0]
    mov    r9,QWORD PTR [rsp+0x88]
    mov    rax,QWORD PTR [rsi]
    test   rax,rax
    jle    at_1_0118
    mov    rsi,QWORD PTR [rsp+0x98]
    shl    r14,0x3
    lea    r11,[rbx-0x1]
    mov    rsi,QWORD PTR [rsi]
    mov    r15d,0x1
    movapd xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    jmp    at_1_00e6
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_00d0:
    movsd  QWORD PTR [rdi+r12*8-0x8],xmm1
    lea    r12,[r15+0x1]
    add    rdx,r14
    cmp    r15,rax
    mov    r15,r12
    je     at_1_0118
at_1_00e6:
    lea    r12,[r15+r11*1]
    movsd  xmm1,QWORD PTR [rdi+r12*8-0x8]
    test   rsi,rsi
    jle    at_1_00d0
    xor    r13d,r13d
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0100:
    movsd  xmm2,QWORD PTR [rdx+r13*8]
    andpd  xmm2,xmm0
    maxsd  xmm1,xmm2
    inc    r13
    cmp    rsi,r13
    jne    at_1_0100
    jmp    at_1_00d0
at_1_0118:
    mov    rdx,QWORD PTR [r10]
    cmp    rdx,QWORD PTR [r9]
    {disp32} jl     at_1_01d2
    test   rax,rax
    {disp32} jle    at_1_01d2
    movsd  xmm0,QWORD PTR [rdi+0x140]
    mov    r9,QWORD PTR [r8+0x1d0]
    mov    rdx,QWORD PTR [r8+0x1e8]
    dec    rdx
    lea    r8,[r9+rax*1]
    lea    r8,[rdi+r8*8]
    neg    rax
    lea    r9,[rdi+r9*8]
    lea    r10,[rdi+rbx*8]
    mov    r11d,0x1
    xorpd  xmm1,xmm1
    jmp    at_1_0196
    .fill 2, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0170:
    movsd  xmm3,QWORD PTR [rcx+r11*8-0x8]
    mulsd  xmm3,xmm0
    maxsd  xmm3,xmm2
    movsd  QWORD PTR [rcx+r11*8-0x8],xmm3
    lea    rsi,[rax+r11*1]
    inc    rsi
    inc    r11
    cmp    rsi,0x1
    je     at_1_01d2
at_1_0196:
    add    rdx,r11
    movsd  xmm2,QWORD PTR [r10+r11*8-0x10]
    movsd  xmm3,QWORD PTR [rdi+rdx*8-0x8]
    ucomisd xmm3,xmm1
    jbe    at_1_01b8
    sqrtsd xmm3,xmm3
    maxsd  xmm3,xmm2
    movapd xmm2,xmm3
at_1_01b8:
    movsd  xmm3,QWORD PTR [r9+r11*8-0x10]
    ucomisd xmm3,xmm2
    jbe    at_1_0170
    movsd  xmm2,QWORD PTR [r8+r11*8-0x10]
    maxsd  xmm2,xmm3
    jmp    at_1_0170
at_1_01d2:
    add    rsp,0x20
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_01e2:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_000f - at_1_0000    # prologue size
    .byte 0x08    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000f - at_1_0000    # ALLOC_SMALL
    .byte 0x32
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_5_0014:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_11_rdata:
def_19_unnamed_1:
at_6_0000:
    .zero 8
at_6_0008:
end_s6:

# .drectve  (COFF section 7)
.section .s7,"dr"
def_13_drectve:
at_7_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_7_00b9:
end_s7:

# .pdata  (COFF section 8)
.section .s8,"dr"
def_15_pdata:
at_8_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_01e2 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_8_000c:
end_s8:

# MEMBER dd7tpr.obj
# Entry points: DD7TPR
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_21_DD7TPR:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    push   rbx
at_1_0003:
    sub    rsp,0x50
at_1_0007:
    movapd XMMWORD PTR [rsp+0x40],xmm8
at_1_000e:
    movapd XMMWORD PTR [rsp+0x30],xmm7
at_1_0014:
    movapd XMMWORD PTR [rsp+0x20],xmm6
at_1_001a:
    mov    rsi,QWORD PTR [rcx]
    test   rsi,rsi
    {disp32} jle    at_1_00e6
    movsd  xmm1,QWORD PTR [rip + ref_22_DD7TPR_SQTETA]
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm1
    setp   al
    setne  cl
    or     cl,al
    jne    at_1_0068
    lea    rcx,[rip + ref_23_unnamed_1]
    mov    rdi,r8
    mov    rbx,rdx
    call   ref_24_DR7MDC
    mov    rdx,rbx
    mov    r8,rdi
    movapd xmm1,xmm0
    xorpd  xmm0,xmm0
    movsd  QWORD PTR [rip + ref_22_DD7TPR_SQTETA],xmm1
at_1_0068:
    xor    eax,eax
    movapd xmm2,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm3,QWORD PTR [rip + ref_11_real_3ff0000000000000]
    movapd xmm4,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    jmp    at_1_00a0
    .fill 3, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_0090:
    mulsd  xmm5,xmm6
    addsd  xmm0,xmm5
at_1_0098:
    inc    rax
    cmp    rsi,rax
    je     at_1_00ea
at_1_00a0:
    movsd  xmm5,QWORD PTR [rdx+rax*8]
    movapd xmm7,xmm5
    andpd  xmm7,xmm2
    movsd  xmm6,QWORD PTR [r8+rax*8]
    movapd xmm8,xmm6
    andpd  xmm8,xmm2
    maxsd  xmm7,xmm8
    ucomisd xmm7,xmm3
    ja     at_1_0090
    ucomisd xmm1,xmm7
    ja     at_1_0098
    movapd xmm7,xmm5
    divsd  xmm7,xmm1
    mulsd  xmm7,xmm6
    andpd  xmm7,xmm4
    ucomisd xmm1,xmm7
    jbe    at_1_0090
    jmp    at_1_0098
at_1_00e6:
    xorpd  xmm0,xmm0
at_1_00ea:
    movaps xmm6,XMMWORD PTR [rsp+0x20]
    movaps xmm7,XMMWORD PTR [rsp+0x30]
    movaps xmm8,XMMWORD PTR [rsp+0x40]
    add    rsp,0x50
    pop    rbx
    pop    rdi
    pop    rsi
    ret
at_1_0102:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_22_DD7TPR_SQTETA:
at_3_0000:
    .zero 8
at_3_0008:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_real_3ff0000000000000:
at_5_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_5_0008:
end_s5:

# .xdata  (COFF section 6)
.section .s6,"dr"
def_12_xdata:
at_6_0000:
    .byte 0x01    # version 1
    .byte at_1_001a - at_1_0000    # prologue size
    .byte 0x0a    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_001a - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x02
    .byte 0x00
    .byte at_1_0014 - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x03
    .byte 0x00
    .byte at_1_000e - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x04
    .byte 0x00
    .byte at_1_0007 - at_1_0000    # ALLOC_SMALL
    .byte 0x92
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
at_6_0018:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_14_rdata:
def_23_unnamed_1:
at_7_0000:
    .quad 0x0000000000000002
at_7_0008:
end_s7:

# .drectve  (COFF section 8)
.section .s8,"dr"
def_16_drectve:
at_8_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_8_00b9:
end_s8:

# .pdata  (COFF section 9)
.section .s9,"dr"
def_18_pdata:
at_9_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_0102 - def_0_text)    # image-relative end
    .long ref_12_xdata    # image-relative unwind info
at_9_000c:
end_s9:

# MEMBER dd7mlp.obj
# Entry points: DD7MLP
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_16_DD7MLP:
at_1_0000:
    push   rsi
at_1_0001:
    mov    rax,QWORD PTR [rsp+0x30]
    cmp    QWORD PTR [rax],0x0
    mov    rax,QWORD PTR [rcx]
    js     at_1_0072
    test   rax,rax
    {disp32} jle    at_1_00e0
    inc    rax
    mov    ecx,0x1
    mov    r10d,0x2
    mov    r11d,0x8
    {disp8} nop    DWORD PTR [rax+0x0]
at_1_0030:
    movsd  xmm0,QWORD PTR [r8+rcx*8-0x8]
    xor    esi,esi
    {disp32} nop    DWORD PTR [rax+0x0]
at_1_0040:
    movsd  xmm1,QWORD PTR [r9+rsi*8]
    mulsd  xmm1,xmm0
    movsd  QWORD PTR [rdx+rsi*8],xmm1
    inc    rsi
    cmp    rcx,rsi
    jne    at_1_0040
    inc    rcx
    lea    rsi,[r10+0x1]
    add    r9,r11
    add    rdx,r11
    add    r11,0x8
    cmp    r10,rax
    mov    r10,rsi
    jne    at_1_0030
    jmp    at_1_00e0
at_1_0072:
    test   rax,rax
    jle    at_1_00e0
    inc    rax
    mov    ecx,0x1
    mov    r10d,0x2
    mov    r11d,0x8
    movsd  xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    .fill 4, 1, 0x66    # redundant operand-size prefixes for Intel alignment NOP
    {disp32} cs nop DWORD PTR [rax+rax]
at_1_00a0:
    movapd xmm1,xmm0
    divsd  xmm1,QWORD PTR [r8+rcx*8-0x8]
    xor    esi,esi
    nop    DWORD PTR [rax]
at_1_00b0:
    movsd  xmm2,QWORD PTR [r9+rsi*8]
    mulsd  xmm2,xmm1
    movsd  QWORD PTR [rdx+rsi*8],xmm2
    inc    rsi
    cmp    rcx,rsi
    jne    at_1_00b0
    inc    rcx
    lea    rsi,[r10+0x1]
    add    r9,r11
    add    rdx,r11
    add    r11,0x8
    cmp    r10,rax
    mov    r10,rsi
    jne    at_1_00a0
at_1_00e0:
    pop    rsi
    ret
at_1_00e2:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_0001 - at_1_0000    # prologue size
    .byte 0x01    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte 0x00
    .byte 0x00
at_5_0008:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_11_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_13_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_00e2 - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER dc7vfn.obj
# Entry points: DC7VFN
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_16_DC7VFN:
at_1_0000:
    push   r15
at_1_0002:
    push   r14
at_1_0004:
    push   r13
at_1_0006:
    push   r12
at_1_0008:
    push   rsi
at_1_0009:
    push   rdi
at_1_000a:
    push   rbx
at_1_000b:
    sub    rsp,0x30
at_1_000f:
    mov    rsi,QWORD PTR [rsp+0xa0]
    mov    r9,QWORD PTR [rcx+0x110]
    mov    rax,QWORD PTR [rcx+0x1b0]
    mov    QWORD PTR [rcx],rax
    mov    rax,QWORD PTR [rsi]
    mov    QWORD PTR [rcx+0x110],0x0
    mov    QWORD PTR [rcx+0x1b0],0x0
    cmp    QWORD PTR [rcx+0x248],0x0
    {disp32} jle    at_1_014b
    sub    r9,rax
    lea    r10,[r9-0x2]
    imul   r10,r10
    cmp    r10,0x1
    jne    at_1_006b
    mov    QWORD PTR [rcx+0x210],0x1
at_1_006b:
    movabs r10,0x8000000000000001
    and    r10,QWORD PTR [rcx+0x1c0]
    cmp    r10,0x1
    {disp32} jne    at_1_014b
    mov    r10,QWORD PTR [rcx+0x1b8]
    mov    rbx,r10
    neg    rbx
    cmovs  rbx,r10
    mov    QWORD PTR [rcx+0x248],0x0
    cmp    QWORD PTR [rcx+0xc8],0x0
    {disp32} jne    at_1_014b
    mov    r14,rcx
    mov    r12,QWORD PTR [rsp+0xa8]
    mov    r15,QWORD PTR [rsp+0x98]
    lea    rdi,[r12+rbx*8]
    add    rdi,0xfffffffffffffff8
    cmp    r9,0x1
    jg     at_1_00f9
    mov    rcx,rsi
    mov    rax,rdx
    mov    rdx,rdi
    mov    r13,r8
    mov    r8,rax
    call   ref_17_DL7NVR
    mov    rcx,rsi
    mov    rdx,rdi
    mov    r8,rdi
    call   ref_18_DL7TSQ
    mov    r8,r13
    mov    rax,QWORD PTR [rsi]
at_1_00f9:
    movsd  xmm0,QWORD PTR [r12+0x48]
    mov    rcx,QWORD PTR [r15]
    sub    rcx,rax
    cmp    rcx,0x2
    mov    eax,0x1
    cmovge rax,rcx
    cvtsi2ss xmm1,rax
    cvtss2sd xmm1,xmm1
    mulsd  xmm1,QWORD PTR [rip + ref_8_real_3fe0000000000000]
    divsd  xmm0,xmm1
    movsd  QWORD PTR [rsp+0x28],xmm0
    lea    rax,[rsp+0x28]
    mov    rcx,r8
    mov    rdx,rdi
    mov    r8,rax
    mov    r9,rdi
    call   ref_19_DV7SCL
    mov    QWORD PTR [r14+0xc8],rbx
at_1_014b:
    add    rsp,0x30
    pop    rbx
    pop    rdi
    pop    rsi
    pop    r12
    pop    r13
    pop    r14
    pop    r15
    ret
at_1_015b:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3fe0000000000000:
at_4_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_000f - at_1_0000    # prologue size
    .byte 0x08    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000f - at_1_0000    # ALLOC_SMALL
    .byte 0x52
    .byte at_1_000b - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_000a - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0009 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte at_1_0008 - at_1_0000    # PUSH_NONVOL
    .byte 0xc0
    .byte at_1_0006 - at_1_0000    # PUSH_NONVOL
    .byte 0xd0
    .byte at_1_0004 - at_1_0000    # PUSH_NONVOL
    .byte 0xe0
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0xf0
at_5_0014:
end_s5:

# .drectve  (COFF section 6)
.section .s6,"dr"
def_11_drectve:
at_6_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_6_00b9:
end_s6:

# .pdata  (COFF section 7)
.section .s7,"dr"
def_13_pdata:
at_7_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_015b - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_7_000c:
end_s7:

# MEMBER da7sst.obj
# Entry points: DA7SST
.intel_syntax noprefix

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_33_DA7SST:
at_1_0000:
    push   rsi
at_1_0001:
    push   rbx
at_1_0002:
    sub    rsp,0x68
at_1_0006:
    movapd XMMWORD PTR [rsp+0x50],xmm11
at_1_000d:
    movapd XMMWORD PTR [rsp+0x40],xmm10
at_1_0014:
    movapd XMMWORD PTR [rsp+0x30],xmm9
at_1_001b:
    movapd XMMWORD PTR [rsp+0x20],xmm8
at_1_0022:
    movapd XMMWORD PTR [rsp+0x10],xmm7
at_1_0028:
    movapd XMMWORD PTR [rsp],xmm6
at_1_002d:
    mov    r8,QWORD PTR [rcx+0x28]
    mov    rax,QWORD PTR [rcx+0xe0]
    mov    QWORD PTR [rcx+0x58],0x0
    mov    QWORD PTR [rcx+0x40],0x0
    lea    rdx,[rax-0x1]
    cmp    rdx,0xc
    jae    at_1_0096
    lea    edx,[rax-0x1]
    cmp    edx,0xb
    ja     at_1_0096
    lea    r10,[rip + ref_24_rdata]
    movsxd rdx,DWORD PTR [r10+rdx*4]
    add    rdx,r10
    jmp    rdx
at_1_006a:
    mov    r10,QWORD PTR [rcx+0x60]
    mov    QWORD PTR [rcx+0xe0],r10
    movsd  xmm0,QWORD PTR [r9+0x88]
    mov    rdx,0xffffffffffffffff
    xorpd  xmm1,xmm1
    ucomisd xmm0,xmm1
    jb     at_1_00a6
    xor    eax,eax
    {disp32} jmp    at_1_0430
at_1_0096:
    mov    QWORD PTR [rcx+0xe0],0xd
    {disp32} jmp    at_1_0851
at_1_00a6:
    mov    QWORD PTR [rcx+0xe0],0xc
    mov    r10d,0xc
    xor    eax,eax
    {disp32} jmp    at_1_0430
at_1_00be:
    mov    QWORD PTR [rcx+0x48],0x1
    mov    QWORD PTR [rcx+0x38],0x0
    movsd  xmm0,QWORD PTR [r9+0x60]
    movsd  QWORD PTR [r9+0x58],xmm0
    cmp    QWORD PTR [rcx+0x8],0x0
    {disp32} je     at_1_01bb
    mov    QWORD PTR [rcx+0x48],0xffffffffffffffff
    mov    QWORD PTR [rcx+0x60],rax
    xor    edx,edx
    {disp32} jmp    at_1_0814
at_1_00f8:
    movsd  xmm0,QWORD PTR [r9+0x68]
    movsd  xmm1,QWORD PTR [r9+0x88]
    movsd  QWORD PTR [r9+0x18],xmm0
    movapd xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    andpd  xmm0,xmm1
    movlpd QWORD PTR [r9+0x8],xmm0
    mov    rax,QWORD PTR [rcx+0x60]
    mov    QWORD PTR [rcx+0xe0],rax
    xorpd  xmm0,xmm0
    ucomisd xmm0,xmm1
    jb     at_1_013f
    mov    QWORD PTR [rcx+0xe0],0xc
at_1_013f:
    movsd  xmm4,QWORD PTR [r9+0x30]
    xorpd  xmm4,XMMWORD PTR [rip + ref_11_xmm_80000000000000008000000000000000]
    movlpd QWORD PTR [r9+0x28],xmm4
    movsd  xmm0,QWORD PTR [r9+0x70]
    movsd  QWORD PTR [r9+0x30],xmm0
    mov    QWORD PTR [rcx+0x40],0x3
    movsd  xmm2,QWORD PTR [r9+0x120]
    movsd  xmm0,QWORD PTR [r9+0x60]
    andpd  xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
at_1_017e:
    xorpd  xmm4,XMMWORD PTR [rip + ref_11_xmm_80000000000000008000000000000000]
    mulsd  xmm0,xmm2
    ucomisd xmm0,xmm4
    {disp32} jb     at_1_0851
    mov    QWORD PTR [rcx+0xe0],0xb
    {disp32} jmp    at_1_0851
at_1_01a4:
    mov    rdx,0xffffffffffffffff
    xor    eax,eax
    {disp32} jmp    at_1_039a
at_1_01b2:
    mov    r10,QWORD PTR [rcx+0x48]
    {disp32} jmp    at_1_0789
at_1_01bb:
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    mov    rdx,0xffffffffffffffff
    mov    r10d,0x1
    jmp    at_1_0202
at_1_01d2:
    mov    rdx,QWORD PTR [rcx+0x20]
    cmp    rdx,QWORD PTR [rcx+0xf8]
    {disp32} jne    at_1_077e
    mov    r10,QWORD PTR [rcx+0x50]
    mov    QWORD PTR [rcx+0x48],r10
    mov    QWORD PTR [rcx+0x38],0xffffffffffffffff
at_1_01f3:
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    mov    rdx,0xffffffffffffffff
at_1_0202:
    xor    eax,eax
at_1_0204:
    movsd  xmm3,QWORD PTR [r9+0x60]
    movsd  xmm4,QWORD PTR [r9+0x30]
    movsd  xmm2,QWORD PTR [r9+0x48]
    movapd xmm1,xmm3
    subsd  xmm1,xmm2
    movsd  QWORD PTR [r9+0x50],xmm1
    movsd  xmm5,QWORD PTR [r9+0xd0]
    mulsd  xmm5,xmm4
    ucomisd xmm1,xmm5
    ja     at_1_0244
    mov    r11,QWORD PTR [rcx+0x38]
    test   r11,r11
    {disp32} jle    at_1_02ff
at_1_0244:
    mov    QWORD PTR [rcx+0x30],r8
    movsd  xmm0,QWORD PTR [r9+0x8]
    movsd  QWORD PTR [r9+0x88],xmm0
    mulsd  xmm4,QWORD PTR [r9+0xc8]
    ucomisd xmm1,xmm4
    jbe    at_1_02c5
    movsd  xmm3,QWORD PTR [r9+0x18]
    movsd  xmm4,QWORD PTR [r9+0xd8]
    mulsd  xmm4,xmm3
    xorpd  xmm4,XMMWORD PTR [rip + ref_11_xmm_80000000000000008000000000000000]
    ucomisd xmm4,xmm1
    ja     at_1_02a1
    mov    r11,QWORD PTR [rcx+0x38]
    test   r11,r11
    js     at_1_02a1
    mov    r10d,eax
    or     r10d,0x2
    cmp    r10d,0x3
    {disp32} jne    at_1_06ac
at_1_02a1:
    movabs r8,0x3ff0000000000000
    mov    QWORD PTR [r9+0x78],r8
    mov    QWORD PTR [rcx+0xe0],0x3
    mov    r10d,0x3
    {disp32} jmp    at_1_042c
at_1_02c5:
    cmp    r10,QWORD PTR [rcx+0x50]
    jge    at_1_02e5
    mov    QWORD PTR [rcx+0xe0],0x2
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    mov    esi,0x2
    jmp    at_1_0351
at_1_02e5:
    mov    QWORD PTR [rcx+0xe0],0x4
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    mov    esi,0x4
    jmp    at_1_0351
at_1_02ff:
    ucomisd xmm3,xmm2
    jbe    at_1_030b
    mov    QWORD PTR [rcx+0x30],r8
    jmp    at_1_032f
at_1_030b:
    mov    rax,QWORD PTR [rcx+0x20]
    mov    QWORD PTR [rcx+0xf8],rax
    movsd  QWORD PTR [r9+0x58],xmm2
    movsd  QWORD PTR [r9+0x48],xmm3
    mov    QWORD PTR [rcx+0x40],0x1
    mov    eax,0x1
at_1_032f:
    mov    esi,0x1
    cmp    r10,QWORD PTR [rcx+0x50]
    jl     at_1_0351
    mov    QWORD PTR [rcx+0xe0],0x5
    dec    r11
    mov    QWORD PTR [rcx+0x38],r11
    mov    esi,0x5
at_1_0351:
    mov    QWORD PTR [rcx+0x60],rsi
    movsd  xmm2,QWORD PTR [r9+0x18]
    addsd  xmm1,xmm2
    movsd  xmm3,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    mulsd  xmm3,xmm0
    movsd  QWORD PTR [r9+0x78],xmm3
    ucomisd xmm2,xmm1
    jbe    at_1_039a
    movsd  xmm3,QWORD PTR [r9+0xb8]
    mulsd  xmm2,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    divsd  xmm2,xmm1
    maxsd  xmm3,xmm2
    mulsd  xmm0,xmm3
    movsd  QWORD PTR [r9+0x78],xmm0
at_1_039a:
    movsd  xmm0,QWORD PTR [r9+0x108]
    ucomisd xmm0,QWORD PTR [r9+0x80]
    jb     at_1_03c1
    mov    QWORD PTR [rcx+0xe0],0xc
    mov    r10d,0xc
    jmp    at_1_0430
at_1_03c1:
    mov    r10,QWORD PTR [rcx+0x60]
    mov    QWORD PTR [rcx+0xe0],r10
    movsd  xmm2,QWORD PTR [r9+0x48]
    movsd  xmm0,QWORD PTR [r9+0x60]
    ucomisd xmm0,xmm2
    jbe    at_1_042c
at_1_03de:
    movsd  QWORD PTR [r9+0x58],xmm2
    mov    r11,QWORD PTR [rcx+0x20]
    mov    QWORD PTR [rcx+0xf8],r11
    test   rax,rax
    jne    at_1_0401
    mov    QWORD PTR [rcx+0x40],0x2
    mov    eax,0x2
at_1_0401:
    movsd  xmm0,QWORD PTR [r9+0x8]
    movsd  QWORD PTR [r9+0x88],xmm0
    mov    QWORD PTR [rcx+0x30],r8
    movsd  xmm0,QWORD PTR [r9+0x18]
    movsd  xmm1,QWORD PTR [r9+0x30]
    movsd  QWORD PTR [r9+0x70],xmm1
    movsd  QWORD PTR [r9+0x68],xmm0
at_1_042c:
    mov    QWORD PTR [rcx+0x60],r10
at_1_0430:
    movsd  xmm0,QWORD PTR [r9+0x60]
    ucomisd xmm0,QWORD PTR [r9+0x58]
    seta   r8b
    cmp    eax,0x1
    jne    at_1_0457
    test   r8b,r8b
    je     at_1_0457
    mov    QWORD PTR [rcx+0x40],0x3
    mov    eax,0x3
at_1_0457:
    movsd  xmm1,QWORD PTR [r9+0x48]
    andpd  xmm1,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm2,QWORD PTR [r9+0xf0]
    ucomisd xmm2,xmm1
    jbe    at_1_0485
    mov    QWORD PTR [rcx+0xe0],0xa
    mov    r10d,0xa
at_1_0485:
    movsd  xmm2,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    mulsd  xmm2,QWORD PTR [r9+0x50]
    movsd  xmm1,QWORD PTR [r9+0x30]
    ucomisd xmm2,xmm1
    {disp32} ja     at_1_0851
    andpd  xmm0,XMMWORD PTR [rip + ref_8_xmm_7fffffffffffffff7fffffffffffffff]
    movsd  xmm8,QWORD PTR [r9+0xf8]
    mulsd  xmm8,xmm0
    movsd  xmm2,QWORD PTR [r9+0x120]
    movapd xmm5,xmm2
    mulsd  xmm5,xmm0
    movsd  xmm4,QWORD PTR [r9+0x118]
    movsd  xmm3,QWORD PTR [r9+0x8]
    ucomisd xmm3,xmm4
    seta   r8b
    movsd  xmm6,QWORD PTR [r9+0x20]
    xorpd  xmm9,xmm9
    ucomisd xmm9,xmm6
    setnp  bl
    sete   r11b
    ucomisd xmm5,xmm1
    jb     at_1_0517
    and    r11b,bl
    or     r8b,r11b
    je     at_1_0517
    mov    QWORD PTR [rcx+0xe0],0xb
    mov    r10d,0xb
at_1_0517:
    movsd  xmm7,QWORD PTR [r9+0x10]
    ucomisd xmm9,xmm7
    {disp32} ja     at_1_05c2
    movsd  xmm9,QWORD PTR [r9+0x28]
    movsd  xmm10,QWORD PTR [r9+0x100]
    xorpd  xmm11,xmm11
    ucomisd xmm9,xmm11
    seta   r8b
    ucomisd xmm8,xmm9
    setae  r11b
    and    r11b,r8b
    ucomisd xmm11,xmm9
    setnp  r8b
    sete   bl
    and    bl,r8b
    ucomisd xmm1,xmm11
    setnp  sil
    sete   r8b
    and    r8b,sil
    and    r8b,bl
    or     r8b,r11b
    ucomisd xmm6,xmm11
    setp   r11b
    setne  bl
    or     bl,r11b
    ucomisd xmm10,QWORD PTR [r9+0x80]
    setae  r11b
    test   bl,bl
    jne    at_1_05ae
    test   r11b,r11b
    je     at_1_05ae
    and    edx,0x1
    je     at_1_05ae
    movzx  edx,r8b
    lea    rdx,[rdx*2+0x7]
    jmp    at_1_05b8
at_1_05ae:
    mov    edx,0x8
    test   r8b,r8b
    je     at_1_05c2
at_1_05b8:
    mov    QWORD PTR [rcx+0xe0],rdx
    mov    r10,rdx
at_1_05c2:
    cmp    r10,0x6
    jl     at_1_05d2
    cmp    r10,0xc
    {disp32} jne    at_1_0851
at_1_05d2:
    xorpd  xmm8,xmm8
    ucomisd xmm6,xmm8
    setnp  dl
    sete   r8b
    test   r8b,dl
    {disp32} jne    at_1_0851
    ucomisd xmm3,xmm4
    jbe    at_1_062b
    movsd  xmm6,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    mulsd  xmm6,xmm3
    ucomisd xmm4,xmm6
    {disp32} jae    at_1_0851
    divsd  xmm4,xmm3
    movsd  xmm6,QWORD PTR [rip + ref_20_real_4000000000000000]
    subsd  xmm6,xmm4
    mulsd  xmm4,xmm1
    mulsd  xmm4,xmm6
    ucomisd xmm4,xmm5
    jb     at_1_0651
    {disp32} jmp    at_1_0851
at_1_062b:
    ucomisd xmm1,xmm5
    {disp32} jae    at_1_0851
    xorpd  xmm5,xmm5
    ucomisd xmm5,xmm7
    jae    at_1_0651
    mulsd  xmm7,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    ucomisd xmm4,xmm7
    {disp32} jae    at_1_0851
at_1_0651:
    movsd  xmm4,QWORD PTR [r9+0x28]
    xorpd  xmm5,xmm5
    ucomisd xmm5,xmm4
    {disp32} ja     at_1_017e
    movsd  xmm0,QWORD PTR [r9+0x18]
    movsd  QWORD PTR [r9+0x68],xmm0
    cmp    r10,0xc
    jne    at_1_067f
    xorpd  xmm3,XMMWORD PTR [rip + ref_11_xmm_80000000000000008000000000000000]
at_1_067f:
    movsd  QWORD PTR [r9+0x88],xmm3
    movsd  QWORD PTR [r9+0x70],xmm1
    xor    edx,edx
    cmp    eax,0x3
    setne  dl
    add    edx,edx
    mov    QWORD PTR [rcx+0x40],rdx
    mov    QWORD PTR [rcx+0xe0],0x6
    {disp32} jmp    at_1_0851
at_1_06ac:
    movsd  xmm4,QWORD PTR [r9+0xc0]
    movsd  xmm5,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    divsd  xmm5,xmm4
    subsd  xmm5,QWORD PTR [rip + ref_14_real_3ff0000000000000]
    movsd  QWORD PTR [r9+0x78],xmm4
    mulsd  xmm5,xmm3
    ucomisd xmm5,xmm1
    jbe    at_1_0700
    movsd  xmm4,QWORD PTR [r9+0xb0]
    movsd  xmm5,QWORD PTR [rip + ref_17_real_3fe0000000000000]
    mulsd  xmm5,xmm3
    addsd  xmm3,xmm1
    divsd  xmm5,xmm3
    maxsd  xmm4,xmm5
    movsd  QWORD PTR [r9+0x78],xmm4
at_1_0700:
    mov    QWORD PTR [rcx+0xe0],0x4
    xorpd  xmm3,xmm3
    ucomisd xmm3,QWORD PTR [r9+0x20]
    setnp  bl
    sete   sil
    mov    r10d,0x4
    test   sil,bl
    {disp32} jne    at_1_042c
    movsd  xmm4,QWORD PTR [r9+0x10]
    mulsd  xmm0,QWORD PTR [rip + ref_20_real_4000000000000000]
    ucomisd xmm0,xmm4
    seta   bl
    mulsd  xmm1,QWORD PTR [rip + ref_23_real_3ff3333333333333]
    ucomisd xmm1,QWORD PTR [r9+0x28]
    seta   sil
    ucomisd xmm4,xmm3
    jb     at_1_0761
    or     bl,sil
    {disp32} jne    at_1_042c
at_1_0761:
    mov    QWORD PTR [rcx+0xe0],0x5
    inc    r11
    mov    QWORD PTR [rcx+0x38],r11
    mov    r10d,0x5
    {disp32} jmp    at_1_03de
at_1_077e:
    mov    r10,QWORD PTR [rcx+0x48]
    inc    r10
    mov    QWORD PTR [rcx+0x48],r10
at_1_0789:
    mov    rdx,QWORD PTR [rcx+0x8]
    test   r10,r10
    jg     at_1_07c0
    test   rdx,rdx
    jne    at_1_07b8
    neg    r10
    mov    QWORD PTR [rcx+0x48],r10
    mov    edx,DWORD PTR [rcx+0x60]
    dec    edx
    cmp    edx,0x4
    ja     at_1_07be
    lea    r11,[rip + ref_24_rdata + (at_10_0030 - def_24_rdata)]
    movsxd rdx,DWORD PTR [r11+rdx*4]
    add    rdx,r11
    jmp    rdx
at_1_07b8:
    mov    rdx,QWORD PTR [rcx+0x38]
    jmp    at_1_0814
at_1_07be:
    xor    edx,edx
at_1_07c0:
    test   rdx,rdx
    je     at_1_07de
    mov    QWORD PTR [rcx+0x8],0x0
    mov    rdx,QWORD PTR [rcx+0x38]
    test   rdx,rdx
    jle    at_1_0809
    movsd  xmm1,QWORD PTR [r9+0x58]
    jmp    at_1_07fd
at_1_07de:
    movsd  xmm1,QWORD PTR [r9+0x58]
    ucomisd xmm1,QWORD PTR [r9+0x48]
    {disp32} ja     at_1_01f3
    mov    rax,QWORD PTR [rcx+0xf8]
    cmp    QWORD PTR [rcx+0x20],rax
    jne    at_1_0879
at_1_07fd:
    mov    dl,0x1
    mov    eax,0x1
    {disp32} jmp    at_1_0889
at_1_0809:
    neg    r10
    mov    QWORD PTR [rcx+0x48],r10
    mov    QWORD PTR [rcx+0x60],rax
at_1_0814:
    mov    QWORD PTR [rcx+0x8],0x0
    movsd  xmm0,QWORD PTR [r9+0xa8]
    movsd  QWORD PTR [r9+0x78],xmm0
    dec    rdx
    mov    QWORD PTR [rcx+0x38],rdx
    mov    QWORD PTR [rcx+0xe0],0x5
    mov    QWORD PTR [rcx+0x40],0x1
    movsd  xmm0,QWORD PTR [r9+0x58]
    movsd  QWORD PTR [r9+0x48],xmm0
at_1_0851:
    movaps xmm6,XMMWORD PTR [rsp]
    movaps xmm7,XMMWORD PTR [rsp+0x10]
    movaps xmm8,XMMWORD PTR [rsp+0x20]
    movaps xmm9,XMMWORD PTR [rsp+0x30]
    movaps xmm10,XMMWORD PTR [rsp+0x40]
    movaps xmm11,XMMWORD PTR [rsp+0x50]
    add    rsp,0x68
    pop    rbx
    pop    rsi
    ret
at_1_0879:
    mov    QWORD PTR [rcx+0x20],rax
    mov    QWORD PTR [rcx+0x58],0x1
    xor    eax,eax
    xor    edx,edx
at_1_0889:
    movsd  xmm2,QWORD PTR [r9+0x60]
    ucomisd xmm1,xmm2
    {disp32} jae    at_1_01f3
    mov    r11,QWORD PTR [rcx+0x50]
    cmp    r10,r11
    jge    at_1_08a6
    xor    eax,eax
    jmp    at_1_08ba
at_1_08a6:
    mov    rsi,QWORD PTR [rcx+0x30]
    add    r11,rsi
    add    r11,0x2
    xor    esi,esi
    cmp    r8,r11
    cmovl  rax,rsi
at_1_08ba:
    mov    QWORD PTR [rcx+0x40],0x3
    movsd  QWORD PTR [r9+0x48],xmm1
    movsd  xmm0,QWORD PTR [r9+0x68]
    movsd  xmm3,QWORD PTR [r9+0x70]
    movsd  QWORD PTR [r9+0x30],xmm3
    movsd  QWORD PTR [r9+0x18],xmm0
    test   dl,dl
    je     at_1_08fd
    lea    rdx,[r9+0x8]
    movsd  xmm0,QWORD PTR [r9+0x8]
    movsd  xmm3,QWORD PTR [r9+0x88]
    divsd  xmm0,xmm3
    jmp    at_1_0912
at_1_08fd:
    lea    rdx,[r9+0x8]
    movsd  xmm3,QWORD PTR [r9+0x88]
    movsd  xmm0,QWORD PTR [rip + ref_14_real_3ff0000000000000]
at_1_0912:
    movsd  QWORD PTR [rdx],xmm3
    test   rax,rax
    je     at_1_093b
    subsd  xmm2,xmm1
    movsd  QWORD PTR [r9+0x50],xmm2
    mov    QWORD PTR [rcx+0xe0],0x4
    movsd  QWORD PTR [r9+0x78],xmm0
    {disp32} jmp    at_1_0851
at_1_093b:
    mov    r8,QWORD PTR [rcx+0x30]
    mov    eax,0x3
    xor    edx,edx
    {disp32} jmp    at_1_0204
at_1_094b:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
at_3_0000:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_xmm_7fffffffffffffff7fffffffffffffff:
at_4_0000:
    .quad 0x7fffffffffffffff
    .quad 0x7fffffffffffffff
at_4_0010:
end_s4:

# .rdata  (COFF section 5)
.section .s5,"dr"
def_9_rdata:
def_11_xmm_80000000000000008000000000000000:
at_5_0000:
    .quad 0x8000000000000000
    .quad 0x8000000000000000
at_5_0010:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_12_rdata:
def_14_real_3ff0000000000000:
at_6_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_6_0008:
end_s6:

# .rdata  (COFF section 7)
.section .s7,"dr"
def_15_rdata:
def_17_real_3fe0000000000000:
at_7_0000:
    .quad 0x3fe0000000000000    # binary64 0.5
at_7_0008:
end_s7:

# .rdata  (COFF section 8)
.section .s8,"dr"
def_18_rdata:
def_20_real_4000000000000000:
at_8_0000:
    .quad 0x4000000000000000    # binary64 2.0
at_8_0008:
end_s8:

# .rdata  (COFF section 9)
.section .s9,"dr"
def_21_rdata:
def_23_real_3ff3333333333333:
at_9_0000:
    .quad 0x3ff3333333333333    # binary64 1.2
at_9_0008:
end_s9:

# .rdata  (COFF section 10)
.section .s10,"dr"
def_24_rdata:
at_10_0000:
    .long ref_0_text + (at_1_01d2 - at_1_0000) + (. - at_10_0000) + 4    # slot 0 -> at_1_01d2
    .long ref_0_text + (at_1_077e - at_1_0000) + (. - at_10_0000) + 4    # slot 1 -> at_1_077e
    .long ref_0_text + (at_1_00be - at_1_0000) + (. - at_10_0000) + 4    # slot 2 -> at_1_00be
    .long ref_0_text + (at_1_00be - at_1_0000) + (. - at_10_0000) + 4    # slot 3 -> at_1_00be
    .long ref_0_text + (at_1_01b2 - at_1_0000) + (. - at_10_0000) + 4    # slot 4 -> at_1_01b2
    .long ref_0_text + (at_1_00f8 - at_1_0000) + (. - at_10_0000) + 4    # slot 5 -> at_1_00f8
    .long ref_0_text + (at_1_006a - at_1_0000) + (. - at_10_0000) + 4    # slot 6 -> at_1_006a
    .long ref_0_text + (at_1_006a - at_1_0000) + (. - at_10_0000) + 4    # slot 7 -> at_1_006a
    .long ref_0_text + (at_1_006a - at_1_0000) + (. - at_10_0000) + 4    # slot 8 -> at_1_006a
    .long ref_0_text + (at_1_006a - at_1_0000) + (. - at_10_0000) + 4    # slot 9 -> at_1_006a
    .long ref_0_text + (at_1_006a - at_1_0000) + (. - at_10_0000) + 4    # slot 10 -> at_1_006a
    .long ref_0_text + (at_1_01a4 - at_1_0000) + (. - at_10_0000) + 4    # slot 11 -> at_1_01a4
at_10_0030:
    .long ref_0_text + (at_1_01d2 - at_1_0000) + (. - at_10_0030) + 4    # slot 0 -> at_1_01d2
    .long ref_0_text + (at_1_077e - at_1_0000) + (. - at_10_0030) + 4    # slot 1 -> at_1_077e
    .long ref_0_text + (at_1_01f3 - at_1_0000) + (. - at_10_0030) + 4    # slot 2 -> at_1_01f3
    .long ref_0_text + (at_1_01f3 - at_1_0000) + (. - at_10_0030) + 4    # slot 3 -> at_1_01f3
    .long ref_0_text + (at_1_07de - at_1_0000) + (. - at_10_0030) + 4    # slot 4 -> at_1_07de
at_10_0044:
end_s10:

# .xdata  (COFF section 11)
.section .s11,"dr"
def_26_xdata:
at_11_0000:
    .byte 0x01    # version 1
    .byte at_1_002d - at_1_0000    # prologue size
    .byte 0x0f    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_002d - at_1_0000    # SAVE_XMM128
    .byte 0x68
    .byte 0x00
    .byte 0x00
    .byte at_1_0028 - at_1_0000    # SAVE_XMM128
    .byte 0x78
    .byte 0x01
    .byte 0x00
    .byte at_1_0022 - at_1_0000    # SAVE_XMM128
    .byte 0x88
    .byte 0x02
    .byte 0x00
    .byte at_1_001b - at_1_0000    # SAVE_XMM128
    .byte 0x98
    .byte 0x03
    .byte 0x00
    .byte at_1_0014 - at_1_0000    # SAVE_XMM128
    .byte 0xa8
    .byte 0x04
    .byte 0x00
    .byte at_1_000d - at_1_0000    # SAVE_XMM128
    .byte 0xb8
    .byte 0x05
    .byte 0x00
    .byte at_1_0006 - at_1_0000    # ALLOC_SMALL
    .byte 0xc2
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte 0x00
    .byte 0x00
at_11_0024:
end_s11:

# .drectve  (COFF section 12)
.section .s12,"dr"
def_28_drectve:
at_12_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_12_00b9:
end_s12:

# .pdata  (COFF section 13)
.section .s13,"dr"
def_30_pdata:
at_13_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_094b - def_0_text)    # image-relative end
    .long ref_26_xdata    # image-relative unwind info
at_13_000c:
end_s13:

# MEMBER d1mach.obj
# Entry points: D1MACH, I1MCRY
.intel_syntax noprefix
# Machine constants. D9MACH is a 304-byte COFF common symbol in this object.

# .text  (COFF section 1)
.section .s1,"dr"
def_0_text:
def_18_D1MACH:
at_1_0000:
    push   rsi
at_1_0001:
    push   rdi
at_1_0002:
    push   rbx
at_1_0003:
    sub    rsp,0xa0
at_1_000a:
    mov    rdi,rcx
    cmp    BYTE PTR [rip + ref_19_D1MACH_SC],0x0
    jne    at_1_0075
    movabs rax,0xffffffff00100000
    mov    QWORD PTR [rip + ref_20_T1 + (at_3_0004 - def_20_T1)],rax
    mov    DWORD PTR [rip + ref_20_T1],0x0
    mov    DWORD PTR [rip + ref_20_T1 + (at_3_000c - def_20_T1)],0x7fefffff
    movabs rax,0x3ca0000000000000
    mov    QWORD PTR [rip + ref_20_T1 + (at_3_0010 - def_20_T1)],rax
    movabs rax,0x3cb0000000000000
    mov    QWORD PTR [rip + ref_20_T1 + (at_3_0018 - def_20_T1)],rax
    movabs rax,0x3fd34413509f79ff
    mov    QWORD PTR [rip + ref_20_T1 + (at_3_0020 - def_20_T1)],rax
    mov    BYTE PTR [rip + ref_19_D1MACH_SC],0x1
at_1_0075:
    movabs rsi,0x801208384ff00
    movsd  xmm0,QWORD PTR [rip + ref_20_T1 + (at_3_0018 - def_20_T1)]
    ucomisd xmm0,QWORD PTR [rip + ref_8_real_3ff0000000000000]
    jb     at_1_00b8
    mov    DWORD PTR [rsp+0x28],0x1
    mov    DWORD PTR [rsp+0x20],0x30a
    lea    rcx,[rip + ref_21_strlit_8]
    mov    edx,0x3
    xor    r8d,r8d
    mov    r9,rsi
    call   ref_22_for_stop_core_quiet
at_1_00b8:
    mov    rbx,QWORD PTR [rdi]
    lea    rax,[rbx-0x6]
    cmp    rax,0xfffffffffffffffa
    {disp32} ja     at_1_0185
    mov    QWORD PTR [rsp+0x70],0x0
    mov    DWORD PTR [rsp+0x44],0x20438
    mov    QWORD PTR [rsp+0x60],0xe
    lea    rax,[rip + ref_23_strlit_3]
    mov    QWORD PTR [rsp+0x68],rax
    lea    rax,[rsp+0x60]
    mov    QWORD PTR [rsp+0x20],rax
    lea    rdi,[rsp+0x70]
    lea    r9,[rsp+0x44]
    mov    rcx,rdi
    mov    edx,0xffffffff
    mov    r8,rsi
    call   ref_24_for_write_seq_lis
    mov    DWORD PTR [rsp+0x40],0x2010b
    mov    QWORD PTR [rsp+0x48],rbx
    lea    rdx,[rsp+0x40]
    lea    r8,[rsp+0x48]
    mov    rcx,rdi
    call   ref_25_for_write_seq_lis_xmit
    mov    DWORD PTR [rsp+0x3c],0x10438
    mov    QWORD PTR [rsp+0x50],0x12
    lea    rax,[rip + ref_26_strlit_2]
    mov    QWORD PTR [rsp+0x58],rax
    lea    rdx,[rsp+0x3c]
    lea    r8,[rsp+0x50]
    mov    rcx,rdi
    call   ref_25_for_write_seq_lis_xmit
    mov    DWORD PTR [rsp+0x28],0x0
    mov    DWORD PTR [rsp+0x20],0x0
    lea    rcx,[rip + ref_27_strlit_9]
    xor    edx,edx
    xor    r8d,r8d
    mov    r9,rsi
    call   ref_22_for_stop_core_quiet
at_1_0185:
    lea    rax,[rip + ref_20_T1]
    movsd  xmm0,QWORD PTR [rax+rbx*8-0x8]
    add    rsp,0xa0
    pop    rbx
    pop    rdi
    pop    rsi
    ret
at_1_019d:
    nop    DWORD PTR [rax]
def_28_I1MCRY:
at_1_01a0:
    mov    rax,QWORD PTR [rsp+0x28]
    mov    r8,QWORD PTR [r8]
    shl    r8,0x18
    add    r8,QWORD PTR [r9]
    mov    QWORD PTR [rdx],r8
    shl    r8,0x18
    add    r8,QWORD PTR [rax]
    mov    QWORD PTR [rcx],r8
    ret
at_1_01bd:
end_s1:

# .data  (COFF section 2)
.section .s2,"dr"
def_2_data:
at_2_0000:
end_s2:

# .bss  (COFF section 3)
.section .s3,"dr"
def_4_bss:
def_20_T1:
at_3_0000:
    .zero 4
at_3_0004:
    .zero 8
at_3_000c:
    .zero 4
at_3_0010:
    .zero 8
at_3_0018:
    .zero 8
at_3_0020:
    .zero 8
def_19_D1MACH_SC:
at_3_0028:
    .zero 1
at_3_0029:
end_s3:

# .rdata  (COFF section 4)
.section .s4,"dr"
def_6_rdata:
def_8_real_3ff0000000000000:
at_4_0000:
    .quad 0x3ff0000000000000    # binary64 1.0
at_4_0008:
end_s4:

# .xdata  (COFF section 5)
.section .s5,"dr"
def_9_xdata:
at_5_0000:
    .byte 0x01    # version 1
    .byte at_1_000a - at_1_0000    # prologue size
    .byte 0x05    # unwind slot count
    .byte 0x00    # frame register / offset
    .byte at_1_000a - at_1_0000    # ALLOC_LARGE
    .byte 0x01
    .byte 0x14
    .byte 0x00
    .byte at_1_0003 - at_1_0000    # PUSH_NONVOL
    .byte 0x30
    .byte at_1_0002 - at_1_0000    # PUSH_NONVOL
    .byte 0x70
    .byte at_1_0001 - at_1_0000    # PUSH_NONVOL
    .byte 0x60
    .byte 0x00
    .byte 0x00
at_5_0010:
end_s5:

# .rdata  (COFF section 6)
.section .s6,"dr"
def_11_rdata:
def_26_strlit_2:
at_6_0000:
    .quad 0x2074756f20736920    # binary64 2.44141049951849e-152
    .quad 0x646e756f6220666f    # binary64 6.026696098525067e+175
    .short 0x2e73
def_23_strlit_3:
at_6_0012:
    .quad 0x49284843414d3144    # binary64 2.707564275355156e+44
    .long 0x49203a29
    .short 0x3d20
def_21_strlit_8:
at_6_0020:
    .short 0x3737
    .byte 0x38
def_27_strlit_9:
at_6_0023:
end_s6:

# .drectve  (COFF section 7)
.section .s7,"dr"
def_13_drectve:
at_7_0000:
    .ascii " /DEFAULTLIB:msvcrt /DEFAULTLIB:ifconsol.lib /DEFAULTLIB:libifcoremd.lib /DEFAULTLIB:libifportmd.lib /DEFAULTLIB:libircmt /DEFAULTLIB:libmmd /DEFAULTLIB:oldnames /DEFAULTLIB:svml_dispmd"
at_7_00b9:
end_s7:

# .pdata  (COFF section 8)
.section .s8,"dr"
def_15_pdata:
at_8_0000:
    .long ref_0_text    # image-relative begin
    .long ref_0_text + (at_1_019d - def_0_text)    # image-relative end
    .long ref_9_xdata    # image-relative unwind info
at_8_000c:
end_s8:
