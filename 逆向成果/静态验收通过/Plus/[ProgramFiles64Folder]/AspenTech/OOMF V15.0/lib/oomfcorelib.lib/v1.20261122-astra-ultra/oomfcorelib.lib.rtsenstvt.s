# @member x64\Release\rtsenstvt.obj 1743626478
# Windows AMD64 COFF. GNU as / AT&T syntax. Tables below preserve link and unwind contracts.

# @symbol section .text
# @symbol function RTSENSITIVITY
# @symbol function CONTACT_ME
# @symbol section .rdata
# @symbol local _2il0floatpacket.0
# @symbol local _2il0floatpacket.1
# @symbol section .bss
# @symbol external_function FIND_COLUMN
# @symbol external_function RTPACKVECTOR
# @symbol section .xdata
# @symbol section .pdata
# @symbol local RTSENSITIVITY$CNTL
# @symbol local RTSENSITIVITY$ICNTL
# @symbol local RTSENSITIVITY$KEEP_PTR
# @symbol local RTSENSITIVITY$IW_PTR
# @symbol local RTSENSITIVITY$W_PTR
# @symbol local __STRLITPACK_8
# @symbol local __STRLITPACK_7
# @symbol local __STRLITPACK_6
# @symbol local __STRLITPACK_5
# @symbol local __STRLITPACK_4
# @symbol local __STRLITPACK_3
# @symbol local __STRLITPACK_2
# @symbol local __STRLITPACK_1
# @symbol local __STRLITPACK_0
# @symbol local __STRLITPACK_18
# @symbol external_function for_write_seq_lis
# @symbol external_function for_stop_core_quiet
# @symbol local __STRLITPACK_9
# @symbol local __STRLITPACK_10
# @symbol local __STRLITPACK_11
# @symbol local __STRLITPACK_12
# @symbol local __STRLITPACK_13
# @symbol local __STRLITPACK_14
# @symbol local __STRLITPACK_15
# @symbol local __STRLITPACK_16
# @symbol local __STRLITPACK_17
# @symbol section .drectve
# @symbol external_function __ImageBase
# @symbol external_data _fltused


# @section .text 0x60300020
    .section .text
.Lbase_text:

# Keep the caller-supplied callbacks and saved work-array pointers in the original member.
    .globl RTSENSITIVITY
RTSENSITIVITY:
    pushq %rbp
.Ltext_0001:
    subq $0x2d0,%rsp
.Ltext_0008:
    leaq 0x80(%rsp),%rbp
.Ltext_0010:
    movq %rdi,0x138(%rbp)
.Ltext_0017:
    movq %rsi,0x130(%rbp)
.Ltext_001e:
    movq %rbx,0x128(%rbp)
.Ltext_0025:
    movq %rcx,0x260(%rbp)
    movq %rdx,0x268(%rbp)
    movq %r8,0x270(%rbp)
    movq %r9,0x278(%rbp)
    movq 0x2c8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0x2b8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x2c0(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq 0x318(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} je .Ltext_0f3f
    movq 0x328(%rbp),%rax
    leaq coff_ref..bss+(RTSENSITIVITY$CNTL-.Lbase_bss)(%rip),%rdx
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rcx
    movq %rcx,0xe8(%rbp)
    movq %rdx,%rcx
    movq 0xe8(%rbp),%rdx
    callq *%rax
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rax
    movl $0x10,%edx
    addq.s %rdx,%rax
    movq $0x0,(%rax)
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rax
    movl $0x8,%edx
    addq.s %rdx,%rax
    movq $0x6,(%rax)
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rax
    movl $0x30,%edx
    addq.s %rdx,%rax
    movq $0x0,(%rax)
    movq $0x1,coff_rel32_4..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    imulq $0x6,%rax,%rax
    movq 0x298(%rbp),%rdx
    movq (%rdx),%rdx
    imulq $0x4,%rdx,%rdx
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rcx
    movl $0x28,%ebx
    addq.s %rbx,%rcx
    movq (%rcx),%rcx
    movq %rax,0xf0(%rbp)
    movq %rdx,%rax
    cqto
    idivq %rcx
    movq 0xf0(%rbp),%rdx
    addq.s %rax,%rdx
    addq $0x7,%rdx
    addq coff_ref..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip),%rdx
    movq %rdx,coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    imulq $0x9,%rax,%rax
    addq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%rax
    movq %rax,0x30(%rbp)
    movq 0x2a0(%rbp),%rax
    movq (%rax),%rax
    addq 0x30(%rbp),%rax
    movq %rax,0x38(%rbp)
    movq 0x2a0(%rbp),%rax
    movq (%rax),%rax
    addq 0x38(%rbp),%rax
    decq %rax
    movq %rax,0x40(%rbp)
    movq $0x1,coff_rel32_4..bss+(RTSENSITIVITY$W_PTR-.Lbase_bss)(%rip)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    imulq $0x2,%rax,%rax
    addq coff_ref..bss+(RTSENSITIVITY$W_PTR-.Lbase_bss)(%rip),%rax
    movq %rax,0x48(%rbp)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    addq 0x48(%rbp),%rax
    movq %rax,0x50(%rbp)
    movq 0x2a0(%rbp),%rax
    movq (%rax),%rax
    addq 0x50(%rbp),%rax
    movq %rax,0x58(%rbp)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    addq 0x58(%rbp),%rax
    decq %rax
    movq %rax,0x60(%rbp)
    movq 0x2d0(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x60(%rbp),%rax
    movq 0x2b8(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_0234
    movq 0x2d0(%rbp),%rax
    movq $0xffffffffffffffff,(%rax)
    movq 0x2b8(%rbp),%rax
    movq 0x60(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_0234:
    movq 0x40(%rbp),%rax
    movq 0x2c0(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_0282
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_0266
    movq 0x2d0(%rbp),%rax
    movq $0xfffffffffffffffe,(%rax)
    jmp .Ltext_0274
.Ltext_0266:
    movq 0x2d0(%rbp),%rax
    movq $0xfffffffffffffffd,(%rax)
.Ltext_0274:
    movq 0x2c0(%rbp),%rax
    movq 0x40(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_0282:
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jne .Ltext_1248
    movq 0x2a0(%rbp),%rax
    movq $0xffffffffffffffff,%rdx
    addq (%rax),%rdx
    movq %rdx,0x80(%rbp)
    movq $0x0,0x28(%rbp)
    movq 0x80(%rbp),%rax
    testq %rax,%rax
    {disp32} jl .Ltext_0387
.Ltext_02c5:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x260(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    addq 0x50(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x2a8(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x270(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    addq 0x30(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x2b0(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x268(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    addq 0x38(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x2b0(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x80(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_02c5
.Ltext_0387:
    movq $0x1,0x70(%rbp)
    movq 0x330(%rbp),%rax
    movq 0x298(%rbp),%rdx
    movq 0x298(%rbp),%rcx
    movq 0x2a0(%rbp),%rbx
    leaq 0x70(%rbp),%rsi
    movq 0x2c8(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x260(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x268(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x270(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x40(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$CNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x48(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x50(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x160(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    leaq 0x200(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    movq %rcx,0xf8(%rbp)
    movq %rdx,%rcx
    movq 0xf8(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    leaq 0x160(%rbp),%rax
    movq (%rax),%rax
    cmpq $0xfffffffffffffffd,%rax
    jne .Ltext_04b3
    movq 0x2d0(%rbp),%rax
    movq $0xfffffffffffffffc,(%rax)
    leaq 0x160(%rbp),%rax
    addq $0x10,%rax
    movq 0x2c8(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    {disp32} jmp .Ltext_1248
.Ltext_04b3:
    leaq 0x160(%rbp),%rax
    movq (%rax),%rax
    testq $0xfffffffffffffffd,%rax
    jne .Ltext_04d5
    movq 0x2d0(%rbp),%rax
    movq $0x0,(%rax)
    jmp .Ltext_04e3
.Ltext_04d5:
    movq 0x2d0(%rbp),%rax
    movq $0x1,(%rax)
.Ltext_04e3:
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    je .Ltext_04f7
    callq coff_ref.CONTACT_ME
.Ltext_04f7:
    leaq 0x160(%rbp),%rax
    addq $0x48,%rax
    movq 0x2e0(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq $0x1,0x70(%rbp)
    movq 0x338(%rbp),%rax
    movq 0x298(%rbp),%rdx
    movq 0x298(%rbp),%rcx
    movq 0x2a0(%rbp),%rbx
    leaq 0x70(%rbp),%rsi
    movq 0x2c8(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x260(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x268(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x270(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x40(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$CNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x48(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x50(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$W_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2a8(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x58(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x60(%rsp)
    leaq 0x160(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    leaq 0x200(%rbp),%rdi
    movq %rdi,0x70(%rsp)
    movq %rcx,0x100(%rbp)
    movq %rdx,%rcx
    movq 0x100(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    leaq 0x160(%rbp),%rax
    movq (%rax),%rax
    cmpq $0xfffffffffffffffd,%rax
    jne .Ltext_0663
    movq 0x2d0(%rbp),%rax
    movq $0xfffffffffffffffc,(%rax)
    leaq 0x160(%rbp),%rax
    addq $0x18,%rax
    movq 0x2c8(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    {disp32} jmp .Ltext_1248
.Ltext_0663:
    leaq 0x160(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    je .Ltext_0686
    leaq 0x160(%rbp),%rax
    movq (%rax),%rax
    andq $0xfffffffffffffffe,%rax
    cmpq $0x2,%rax
    jne .Ltext_0696
.Ltext_0686:
    movq 0x2d0(%rbp),%rax
    movq $0x0,(%rax)
    jmp .Ltext_06a4
.Ltext_0696:
    movq 0x2d0(%rbp),%rax
    movq $0x1,(%rax)
.Ltext_06a4:
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    je .Ltext_06b8
    callq coff_ref.CONTACT_ME
.Ltext_06b8:
    leaq 0x160(%rbp),%rax
    addq $0x20,%rax
    movq 0x2d8(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x2d8(%rbp),%rax
    movq (%rax),%rax
    movq 0x298(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0720
    movq 0x2e0(%rbp),%rax
    movq (%rax),%rax
    movq 0x298(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0712
    movq 0x2d0(%rbp),%rax
    movq $0x1,(%rax)
    jmp .Ltext_0720
.Ltext_0712:
    movq 0x2d0(%rbp),%rax
    movq $0x2,(%rax)
.Ltext_0720:
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x90(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x90(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_0796
.Ltext_0745:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2f0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x90(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_0745
.Ltext_0796:
    movq 0x320(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    je .Ltext_07c8
    movq 0x298(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
.Ltext_07c8:
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} je .Ltext_1248
    movq 0x350(%rbp),%rax
    movq 0x298(%rbp),%rdx
    movq 0x298(%rbp),%rcx
    movq 0x2c8(%rbp),%rbx
    movq 0x268(%rbp),%rsi
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x20(%rsp)
    movq 0x2d8(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x2f0(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x2e8(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x40(%rsp)
    movq %rcx,0x108(%rbp)
    movq %rdx,%rcx
    movq 0x108(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x298(%rbp),%rax
    movq 0x2d8(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x300(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x298(%rbp),%rax
    movq 0x300(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x2f8(%rbp),%rax
    movq %rdx,(%rax)
    movq $0x0,0x98(%rbp)
    movq 0x300(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xa0(%rbp)
    movq $0xffffffffffffffff,%rax
    addq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%rax
    movq %rax,0xa8(%rbp)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xb0(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0xb0(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_09d3
.Ltext_0927:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_097b
    movl $0x1,%eax
    addq 0x98(%rbp),%rax
    movq %rax,0x98(%rbp)
    movq 0x98(%rbp),%rax
    addq 0xa8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    movq %rdx,(%rax)
    jmp .Ltext_09b2
.Ltext_097b:
    movl $0x1,%eax
    addq 0xa0(%rbp),%rax
    movq %rax,0xa0(%rbp)
    movq 0xa0(%rbp),%rax
    addq 0xa8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_09b2:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0xb0(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0927
.Ltext_09d3:
    movq 0x300(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xb8(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0xb8(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0e15
.Ltext_09fc:
    movq 0x28(%rbp),%rax
    addq 0xa8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xc0(%rbp)
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0x48(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x2a8(%rbp),%rdx
    addq.s %rdx,%rax
    movl $0x0,%edx
    movl $0x8,%ecx
    subq.s %rcx,%rdx
    movq 0x50(%rbp),%rcx
    imulq $0x8,%rcx,%rcx
    addq 0x2a8(%rbp),%rcx
    addq.s %rcx,%rdx
    movq 0x298(%rbp),%rcx
    leaq 0xc0(%rbp),%rbx
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x38(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x20(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x30(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x28(%rsp)
    movq 0x2a0(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq %rcx,0x110(%rbp)
    movq %rax,%rcx
    movq 0x110(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq FIND_COLUMN
    movq $0x1,0x70(%rbp)
    movq $0x0,0x68(%rbp)
    movq 0x348(%rbp),%rax
    movq 0x298(%rbp),%rdx
    movq 0x298(%rbp),%rcx
    leaq 0x68(%rbp),%rbx
    leaq 0x70(%rbp),%rsi
    movq 0x2c8(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x260(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x268(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x38(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$CNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x40(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x48(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x48(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x2a8(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x50(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x58(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x2a8(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x140(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$W_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2a8(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x68(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x70(%rsp)
    leaq 0x160(%rbp),%rdi
    movq %rdi,0x78(%rsp)
    movq %rcx,0x118(%rbp)
    movq %rdx,%rcx
    movq 0x118(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq $0x0,0xd0(%rbp)
    movq 0x2f8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xd8(%rbp)
    movq $0x1,0x98(%rbp)
    movq 0xd8(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0d70
.Ltext_0c6f:
    movq 0x300(%rbp),%rax
    movq (%rax),%rax
    addq 0xa8(%rbp),%rax
    addq 0x98(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xe0(%rbp)
    movq 0xe0(%rbp),%rax
    addq 0x58(%rbp),%rax
    decq %rax
    imulq $0x8,%rax,%rax
    addq 0x2a8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    andpd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm0
    movq 0x308(%rbp),%rax
    movsd (%rax),%xmm1
    comisd %xmm1,%xmm0
    jbe .Ltext_0d46
    movq 0xe0(%rbp),%rax
    movq %rax,0xc0(%rbp)
    movq 0xc0(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movl $0x1,%eax
    addq 0xd0(%rbp),%rax
    movq %rax,0xd0(%rbp)
    movq 0x300(%rbp),%rax
    movq (%rax),%rax
    addq 0xa8(%rbp),%rax
    addq 0x98(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
.Ltext_0d46:
    movl $0x1,%eax
    addq 0x98(%rbp),%rax
    movq %rax,0x98(%rbp)
    movq 0x98(%rbp),%rax
    movq 0xd8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0c6f
.Ltext_0d70:
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0x300(%rbp),%rdx
    movq (%rdx),%rdx
    addq 0xa8(%rbp),%rdx
    incq %rdx
    imulq $0x8,%rdx,%rdx
    addq 0x2b0(%rbp),%rdx
    addq.s %rdx,%rax
    movq 0x2f8(%rbp),%rdx
    movq %rax,%rcx
    callq RTPACKVECTOR
    movq 0x2f8(%rbp),%rax
    movq 0xd0(%rbp),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x2f8(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x2f8(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_0df4
    movq 0x298(%rbp),%rax
    movq 0x300(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    {disp32} jmp .Ltext_1248
.Ltext_0df4:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0xb8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_09fc
.Ltext_0e15:
    movq 0x298(%rbp),%rax
    movq 0x2f8(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x300(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x320(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    {disp32} je .Ltext_1248
    movq 0x298(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xc8(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0xc8(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1248
.Ltext_0e95:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_0f19
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x288(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    andpd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm0
    movq 0x308(%rbp),%rax
    movsd (%rax),%xmm1
    comisd %xmm1,%xmm0
    jbe .Ltext_0f19
    movq 0x298(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    pxor %xmm0,%xmm0
    movq 0x280(%rbp),%rax
    movsd %xmm0,(%rax)
    {disp32} jmp .Ltext_1248
.Ltext_0f19:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0xc8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0e95
    {disp32} jmp .Ltext_1248
.Ltext_0f3f:
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x20(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_0fae
.Ltext_0f5e:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x278(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    xorpd coff_ref..rdata+(_2il0floatpacket.1-.Lbase_rdata)(%rip),%xmm0
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x278(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd %xmm0,(%rax)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x20(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_0f5e
.Ltext_0fae:
    movq $0x0,0x68(%rbp)
    movq $0x1,0x70(%rbp)
    movq 0x348(%rbp),%rax
    movq 0x298(%rbp),%rdx
    movq 0x298(%rbp),%rcx
    leaq 0x68(%rbp),%rbx
    leaq 0x70(%rbp),%rsi
    movq 0x2c8(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x260(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x268(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$KEEP_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x38(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$CNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x40(%rsp)
    leaq coff_ref..bss+(RTSENSITIVITY$ICNTL-.Lbase_bss)(%rip),%rdi
    movq %rdi,0x48(%rsp)
    movq 0x278(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movq 0x290(%rbp),%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x140(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$W_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2a8(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x68(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq coff_ref..bss+(RTSENSITIVITY$IW_PTR-.Lbase_bss)(%rip),%r8
    imulq $0x8,%r8,%r8
    addq 0x2b0(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x70(%rsp)
    leaq 0x160(%rbp),%rdi
    movq %rdi,0x78(%rsp)
    movq %rcx,0x120(%rbp)
    movq %rdx,%rcx
    movq 0x120(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    leaq 0x160(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    je .Ltext_10ec
    callq coff_ref.CONTACT_ME
.Ltext_10ec:
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x78(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x78(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_1162
.Ltext_110b:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_1148
    movq 0x310(%rbp),%rax
    movq 0x28(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x290(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
.Ltext_1148:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x78(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_110b
.Ltext_1162:
    movq 0x320(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    {disp32} je .Ltext_1248
    movq 0x298(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x2e8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    cmpq $0x1,%rax
    {disp32} jne .Ltext_1232
    movq 0x298(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x88(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x88(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1248
.Ltext_11c7:
    movq 0x280(%rbp),%rax
    movq 0x28(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x288(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rdx),%xmm0
    movq 0x28(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x290(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rdx),%xmm1
    mulsd %xmm1,%xmm0
    movsd (%rax),%xmm1
    addsd %xmm0,%xmm1
    movq 0x280(%rbp),%rax
    movsd %xmm1,(%rax)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x88(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_11c7
    jmp .Ltext_1248
.Ltext_1232:
    movq 0x310(%rbp),%rax
    movq 0x280(%rbp),%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
.Ltext_1248:
    movq 0x128(%rbp),%rbx
    movq 0x130(%rbp),%rsi
    movq 0x138(%rbp),%rdi
    leaq 0x250(%rbp),%rsp
    popq %rbp
    retq

# Write diagnostics with the Fortran runtime and invoke its stop routine.
    .globl CONTACT_ME
CONTACT_ME:
.Lend_RTSENSITIVITY:
    pushq %rbp
.Ltext_1267:
    subq $0x150,%rsp
.Ltext_126e:
    leaq 0x30(%rsp),%rbp
.Ltext_1273:
    movq %rsi,0x118(%rbp)
.Ltext_127a:
    movq %rbx,0x110(%rbp)
.Ltext_1281:
    movq $0x0,0x0(%rbp)
    movq $0x1,0x30(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_8-.Lbase_rdata)(%rip),%rax
    movq %rax,0x38(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_9-.Lbase_rdata)(%rip),%rbx
    leaq 0x30(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xc0(%rbp)
    movq %rax,%rcx
    movq 0xc0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0x11,0x40(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_7-.Lbase_rdata)(%rip),%rax
    movq %rax,0x48(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_10-.Lbase_rdata)(%rip),%rbx
    leaq 0x40(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xc8(%rbp)
    movq %rax,%rcx
    movq 0xc8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0x25,0x50(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_6-.Lbase_rdata)(%rip),%rax
    movq %rax,0x58(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_11-.Lbase_rdata)(%rip),%rbx
    leaq 0x50(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xd0(%rbp)
    movq %rax,%rcx
    movq 0xd0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0xe,0x60(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_5-.Lbase_rdata)(%rip),%rax
    movq %rax,0x68(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_12-.Lbase_rdata)(%rip),%rbx
    leaq 0x60(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xd8(%rbp)
    movq %rax,%rcx
    movq 0xd8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0x18,0x70(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_4-.Lbase_rdata)(%rip),%rax
    movq %rax,0x78(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_13-.Lbase_rdata)(%rip),%rbx
    leaq 0x70(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xe0(%rbp)
    movq %rax,%rcx
    movq 0xe0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0x3,0x80(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_3-.Lbase_rdata)(%rip),%rax
    movq %rax,0x88(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_14-.Lbase_rdata)(%rip),%rbx
    leaq 0x80(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xe8(%rbp)
    movq %rax,%rcx
    movq 0xe8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0x1,0x90(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_2-.Lbase_rdata)(%rip),%rax
    movq %rax,0x98(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_15-.Lbase_rdata)(%rip),%rbx
    leaq 0x90(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xf0(%rbp)
    movq %rax,%rcx
    movq 0xf0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0xa,0xa0(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_1-.Lbase_rdata)(%rip),%rax
    movq %rax,0xa8(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_16-.Lbase_rdata)(%rip),%rbx
    leaq 0xa0(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0xf8(%rbp)
    movq %rax,%rcx
    movq 0xf8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    movq $0x0,0x0(%rbp)
    movq $0x1,0xb0(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_0-.Lbase_rdata)(%rip),%rax
    movq %rax,0xb8(%rbp)
    leaq 0x0(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_17-.Lbase_rdata)(%rip),%rbx
    leaq 0xb0(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0x100(%rbp)
    movq %rax,%rcx
    movq 0x100(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
    leaq coff_ref..rdata+(__STRLITPACK_18-.Lbase_rdata)(%rip),%rax
    movl $0x0,%edx
    movl $0x0,%ecx
    movabsq $0x801208384ff00,%rbx
    movq $0x0,0x20(%rsp)
    movq $0x0,0x28(%rsp)
    movq %rcx,0x108(%rbp)
    movq %rax,%rcx
    movq 0x108(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_stop_core_quiet
    movq 0x110(%rbp),%rbx
    movq 0x118(%rbp),%rsi
    leaq 0x120(%rbp),%rsp
    popq %rbp
    retq
.Lend_CONTACT_ME:
    nop
coff_end.text:

# @section .rdata 0x40500040
    .section .rdata
.Lbase_rdata:
_2il0floatpacket.0:
    .quad 0x7fffffffffffffff, 0x0  # IEEE / SIMD bit pattern
_2il0floatpacket.1:
    .quad 0x8000000000000000, 0x0  # IEEE / SIMD bit pattern
__STRLITPACK_8:
    .byte 0x20
    .zero 3
__STRLITPACK_7:
    .ascii "Unexpected error."
    .zero 3
__STRLITPACK_6:
    .ascii "Please contact Aspen Technology, Inc."
    .zero 3
__STRLITPACK_5:
    .ascii "Ten Canal Park"
    .zero 2
__STRLITPACK_4:
    .ascii "Cambridge, MA 02141-2201"
    .zero 4
__STRLITPACK_3:
    .ascii "USA"
    .zero 1
__STRLITPACK_2:
    .byte 0x20
    .zero 3
__STRLITPACK_1:
    .ascii "Thank you."
    .zero 2
__STRLITPACK_0:
    .byte 0x20
    .zero 3
__STRLITPACK_18:
    .zero 4
__STRLITPACK_9:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_10:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_11:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_12:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_13:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_14:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_15:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_16:
    .byte 0x38, 0x04, 0x01
    .zero 5
__STRLITPACK_17:
    .byte 0x38, 0x04, 0x01
    .zero 5
coff_end.rdata:

# @section .bss 0xc0600080
    .section .bss
.Lbase_bss:
RTSENSITIVITY$CNTL:
    .zero 96
RTSENSITIVITY$ICNTL:
    .zero 160
RTSENSITIVITY$KEEP_PTR:
    .zero 8
RTSENSITIVITY$IW_PTR:
    .zero 8
RTSENSITIVITY$W_PTR:
    .zero 16
coff_end.bss:

# @section .xdata 0x40300040
    .section .xdata
.Lbase_xdata:
.Lunwind_RTSENSITIVITY:
    .byte 1, .Ltext_0025-RTSENSITIVITY, 10, 0x85  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0025-RTSENSITIVITY, 0x34  # save rbx
    .short 424/8  # stack bytes in 8-byte units
    .byte .Ltext_001e-RTSENSITIVITY, 0x64  # save rsi
    .short 432/8  # stack bytes in 8-byte units
    .byte .Ltext_0017-RTSENSITIVITY, 0x74  # save rdi
    .short 440/8  # stack bytes in 8-byte units
    .byte .Ltext_0010-RTSENSITIVITY, 0x03  # set frame pointer
    .byte .Ltext_0008-RTSENSITIVITY, 0x01  # allocate large stack frame
    .short 720/8  # stack bytes in 8-byte units
    .byte .Ltext_0001-RTSENSITIVITY, 0x50  # push rbp
.Lunwind_CONTACT_ME:
    .byte 1, .Ltext_1281-CONTACT_ME, 8, 0x35  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_1281-CONTACT_ME, 0x34  # save rbx
    .short 320/8  # stack bytes in 8-byte units
    .byte .Ltext_127a-CONTACT_ME, 0x64  # save rsi
    .short 328/8  # stack bytes in 8-byte units
    .byte .Ltext_1273-CONTACT_ME, 0x03  # set frame pointer
    .byte .Ltext_126e-CONTACT_ME, 0x01  # allocate large stack frame
    .short 336/8  # stack bytes in 8-byte units
    .byte .Ltext_1267-CONTACT_ME, 0x50  # push rbp
coff_end.xdata:

# @section .pdata 0x40300040
    .section .pdata
.Lbase_pdata:
    .long coff_rva.RTSENSITIVITY
    .long coff_rva.RTSENSITIVITY+(.Lend_RTSENSITIVITY-RTSENSITIVITY)
    .long coff_rva..xdata+(.Lunwind_RTSENSITIVITY-.Lbase_xdata)
    .long coff_rva.CONTACT_ME
    .long coff_rva.CONTACT_ME+(.Lend_CONTACT_ME-CONTACT_ME)
    .long coff_rva..xdata+(.Lunwind_CONTACT_ME-.Lbase_xdata)
coff_end.pdata:

# @section .drectve 0x100a00
    .section .drectve
.Lbase_drectve:
    .ascii "-export:RTSENSITIVITY  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "
coff_end.drectve:
