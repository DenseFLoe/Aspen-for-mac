# @member x64\Release\rtanalyzeqn.obj 1743626478
# Windows AMD64 COFF. GNU as / AT&T syntax. Tables below preserve link and unwind contracts.

# @symbol section .text
# @symbol function RTANALYZEQN
# @symbol function RTANALYZEQN_ROWS_COLS
# @symbol function RT_FIND_COLUMN
# @symbol function RT_FIND_ROW
# @symbol section .xdata
# @symbol section .pdata
# @symbol section .rdata
# @symbol local _2il0floatpacket.0
# @symbol section .drectve
# @symbol external_function __ImageBase
# @symbol external_data _fltused


# @section .text 0x60300020
    .section .text
.Lbase_text:

# Retain the indirect callbacks and the equation rows/columns work routine.
    .globl RTANALYZEQN
RTANALYZEQN:
    pushq %rbp
.Ltext_0001:
    subq $0x380,%rsp
.Ltext_0008:
    leaq 0xc0(%rsp),%rbp
.Ltext_0010:
    movq %rdi,0xd8(%rbp)
.Ltext_0017:
    movq %rsi,0xd0(%rbp)
.Ltext_001e:
    movq %rbx,0xc8(%rbp)
.Ltext_0025:
    movq %rcx,0x2d0(%rbp)
    movq %rdx,0x2d8(%rbp)
    movq %r8,0x2e0(%rbp)
    movq %r9,0x2e8(%rbp)
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x310(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0x318(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x2e8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq 0x358(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x2e8(%rbp),%rax
    movq (%rax),%rax
    movq 0x2f0(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_00b3
    movq 0x358(%rbp),%rax
    movq $0xfffffffffffffffb,(%rax)
    {disp32} jmp .Ltext_0920
.Ltext_00b3:
    movq $0x1,0x20(%rbp)
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    addq 0x20(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x2f0(%rbp),%rax
    movq (%rax),%rax
    imulq $0x3,%rax,%rax
    movq 0x2e8(%rbp),%rdx
    addq (%rdx),%rax
    addq 0x28(%rbp),%rax
    movq %rax,0x30(%rbp)
    movq 0x2f0(%rbp),%rax
    movq (%rax),%rax
    addq 0x30(%rbp),%rax
    movq %rax,0x38(%rbp)
    movq 0x2e8(%rbp),%rax
    movq (%rax),%rax
    addq 0x38(%rbp),%rax
    decq %rax
    movq %rax,0x40(%rbp)
    movq $0x1,0x48(%rbp)
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    addq 0x48(%rbp),%rax
    movq %rax,0x50(%rbp)
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    addq 0x50(%rbp),%rax
    movq %rax,0x58(%rbp)
    movq 0x2e8(%rbp),%rax
    movq 0x2f0(%rbp),%rdx
    movq (%rdx),%rdx
    imulq $0x9,%rdx,%rdx
    addq (%rax),%rdx
    addq $0x7,%rdx
    addq 0x58(%rbp),%rdx
    movq %rdx,0x60(%rbp)
    movq 0x2e8(%rbp),%rax
    movq (%rax),%rax
    imulq $0x6,%rax,%rax
    movq 0x2f0(%rbp),%rdx
    movq (%rdx),%rdx
    imulq $0x3,%rdx,%rdx
    addq.s %rdx,%rax
    addq 0x60(%rbp),%rax
    movq %rax,0x68(%rbp)
    movq 0x2e8(%rbp),%rax
    movq (%rax),%rax
    addq 0x68(%rbp),%rax
    movq %rax,0x70(%rbp)
    movq 0x2f0(%rbp),%rax
    movq (%rax),%rax
    addq 0x70(%rbp),%rax
    movq %rax,0x78(%rbp)
    movq 0x2e8(%rbp),%rax
    movq (%rax),%rax
    addq 0x78(%rbp),%rax
    decq %rax
    movq %rax,0x80(%rbp)
    movq 0x318(%rbp),%rax
    movq (%rax),%rax
    movq 0x80(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_01fc
    movq 0x358(%rbp),%rax
    movq $0xfffffffffffffffe,(%rax)
    movq 0x318(%rbp),%rax
    movq 0x80(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_01fc:
    movq 0x310(%rbp),%rax
    movq (%rax),%rax
    movq 0x40(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_022b
    movq 0x358(%rbp),%rax
    movq $0xffffffffffffffff,(%rax)
    movq 0x310(%rbp),%rax
    movq 0x40(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_022b:
    movq 0x318(%rbp),%rax
    movq (%rax),%rax
    movq 0x80(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0262
    movq 0x310(%rbp),%rax
    movq (%rax),%rax
    movq 0x40(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0262
    movq 0x358(%rbp),%rax
    movq $0xfffffffffffffffd,(%rax)
.Ltext_0262:
    movq 0x358(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jne .Ltext_0920
    movq 0x370(%rbp),%rax
    leaq 0xe0(%rbp),%rdx
    leaq 0x130(%rbp),%rcx
    movq %rcx,0xa8(%rbp)
    movq %rdx,%rcx
    movq 0xa8(%rbp),%rdx
    callq *%rax
    leaq 0x130(%rbp),%rax
    addq $0x10,%rax
    movq $0x0,(%rax)
    leaq 0x130(%rbp),%rax
    addq $0x8,%rax
    movq $0x6,(%rax)
    leaq 0x130(%rbp),%rax
    addq $0x30,%rax
    movq $0x0,(%rax)
    movq 0x2f0(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    leaq 0x130(%rbp),%rax
    addq $0x28,%rax
    movq %rdx,(%rax)
    movq 0x368(%rbp),%rax
    leaq 0xe0(%rbp),%rdx
    addq $0x18,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movq 0x2f8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x88(%rbp)
    movq $0x1,0x90(%rbp)
    movq 0x88(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_040d
.Ltext_0336:
    movq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2d0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x90(%rbp),%rdx
    addq 0x20(%rbp),%rdx
    decq %rdx
    imulq $0x8,%rdx,%rdx
    addq 0x300(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2d8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x90(%rbp),%rdx
    addq 0x48(%rbp),%rdx
    decq %rdx
    imulq $0x8,%rdx,%rdx
    addq 0x308(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2e0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x90(%rbp),%rdx
    addq 0x50(%rbp),%rdx
    decq %rdx
    imulq $0x8,%rdx,%rdx
    addq 0x308(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x90(%rbp),%rax
    movq %rax,0x90(%rbp)
    movq 0x90(%rbp),%rax
    movq 0x88(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0336
.Ltext_040d:
    movq $0x1,0x98(%rbp)
    movq 0x378(%rbp),%rax
    movq 0x2e8(%rbp),%rdx
    movq 0x2f0(%rbp),%rcx
    movq 0x2f8(%rbp),%rbx
    leaq 0x98(%rbp),%rsi
    movq 0x320(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x20(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x300(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x28(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x48(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x30(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x50(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x38(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x58(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x40(%rsp)
    leaq 0xe0(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    leaq 0x130(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x60(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x1d0(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    leaq 0x270(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    movq %rcx,0xb0(%rbp)
    movq %rdx,%rcx
    movq 0xb0(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    leaq 0x1d0(%rbp),%rax
    movq (%rax),%rax
    cmpq $0xfffffffffffffffd,%rax
    jne .Ltext_0584
    movq 0x358(%rbp),%rax
    movq $0xfffffffffffffffc,(%rax)
    leaq 0x1d0(%rbp),%rax
    addq $0x10,%rax
    movq 0x320(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    {disp32} jmp .Ltext_0920
.Ltext_0584:
    movq 0x380(%rbp),%rax
    movq 0x2e8(%rbp),%rdx
    movq 0x2f0(%rbp),%rcx
    movq 0x2f8(%rbp),%rbx
    leaq 0x98(%rbp),%rsi
    movq 0x320(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x20(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x300(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x28(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x48(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x30(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x50(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x38(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x58(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x40(%rsp)
    leaq 0xe0(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    leaq 0x130(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x28(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x300(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x58(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x60(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x308(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x60(%rsp)
    leaq 0x1d0(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    leaq 0x270(%rbp),%rdi
    movq %rdi,0x70(%rsp)
    movq %rcx,0xb8(%rbp)
    movq %rdx,%rcx
    movq 0xb8(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    leaq 0x1d0(%rbp),%rax
    movq (%rax),%rax
    cmpq $0xfffffffffffffffd,%rax
    jne .Ltext_0715
    movq 0x358(%rbp),%rax
    movq $0xfffffffffffffffc,(%rax)
    leaq 0x1d0(%rbp),%rax
    addq $0x18,%rax
    movq 0x320(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    {disp32} jmp .Ltext_0920
.Ltext_0715:
    leaq 0x1d0(%rbp),%rax
    addq $0x20,%rax
    movq 0x348(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    leaq 0x1d0(%rbp),%rax
    addq $0x48,%rax
    movq 0x350(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq $0xffffffffffffffff,0xa0(%rbp)
    movq 0x2e8(%rbp),%rax
    movq 0x2f0(%rbp),%rdx
    movq 0x2f8(%rbp),%rcx
    movq 0x348(%rbp),%rbx
    movq 0x320(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x20(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x300(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x28(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x48(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x308(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x30(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x50(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x308(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x38(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x58(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x308(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x40(%rsp)
    movq 0x2d0(%rbp),%rsi
    movq %rsi,0x48(%rsp)
    movq 0x2d8(%rbp),%rsi
    movq %rsi,0x50(%rsp)
    movq 0x2e0(%rbp),%rsi
    movq %rsi,0x58(%rsp)
    movq 0x328(%rbp),%rsi
    movq %rsi,0x60(%rsp)
    movq 0x338(%rbp),%rsi
    movq %rsi,0x68(%rsp)
    movq 0x330(%rbp),%rsi
    movq %rsi,0x70(%rsp)
    movq 0x340(%rbp),%rsi
    movq %rsi,0x78(%rsp)
    movq 0x360(%rbp),%rsi
    movq %rsi,0x80(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x28(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x300(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x88(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x60(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x308(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x90(%rsp)
    leaq 0xe0(%rbp),%rsi
    movq %rsi,0x98(%rsp)
    leaq 0x130(%rbp),%rsi
    movq %rsi,0xa0(%rsp)
    leaq 0xa0(%rbp),%rsi
    movq %rsi,0xa8(%rsp)
    movq 0x388(%rbp),%rsi
    movq %rsi,0xb0(%rsp)
    movq 0x390(%rbp),%rsi
    movq %rsi,0xb8(%rsp)
    movq %rcx,0xc0(%rbp)
    movq %rax,%rcx
    movq 0xc0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.RTANALYZEQN_ROWS_COLS
.Ltext_0920:
    movq 0xc8(%rbp),%rbx
    movq 0xd0(%rbp),%rsi
    movq 0xd8(%rbp),%rdi
    leaq 0x2c0(%rbp),%rsp
    popq %rbp
    retq

    .globl RTANALYZEQN_ROWS_COLS
RTANALYZEQN_ROWS_COLS:
.Lend_RTANALYZEQN:
    pushq %rbp
.Ltext_093f:
    subq $0x270,%rsp
.Ltext_0946:
    leaq 0x80(%rsp),%rbp
.Ltext_094e:
    movq %rdi,0x120(%rbp)
.Ltext_0955:
    movq %rsi,0x118(%rbp)
.Ltext_095c:
    movq %rbx,0x110(%rbp)
.Ltext_0963:
    movq %rcx,0x200(%rbp)
    movq %rdx,0x208(%rbp)
    movq %r8,0x210(%rbp)
    movq %r9,0x218(%rbp)
    movq 0x220(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x210(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x2a8(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    jne .Ltext_09d3
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    movq 0x208(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} jne .Ltext_139b
.Ltext_09d3:
    movq $0x1,0x18(%rbp)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    addq 0x18(%rbp),%rax
    movq %rax,0x20(%rbp)
    movq 0x208(%rbp),%rax
    movq (%rax),%rax
    addq 0x20(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    addq 0x28(%rbp),%rax
    movq %rax,0x30(%rbp)
    movq 0x208(%rbp),%rax
    movq (%rax),%rax
    addq 0x30(%rbp),%rax
    decq %rax
    movq %rax,0x38(%rbp)
    movq $0x1,0x40(%rbp)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    addq 0x40(%rbp),%rax
    movq %rax,0x48(%rbp)
    movq 0x208(%rbp),%rax
    movq (%rax),%rax
    addq 0x48(%rbp),%rax
    movq %rax,0x50(%rbp)
    movq 0x208(%rbp),%rax
    movq (%rax),%rax
    imulq $0x3,%rax,%rax
    addq 0x50(%rbp),%rax
    movq 0x200(%rbp),%rdx
    addq (%rdx),%rax
    decq %rax
    movq %rax,0x58(%rbp)
    movq 0x260(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x60(%rbp)
    movq $0x1,0x68(%rbp)
    movq 0x60(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_0b0a
.Ltext_0aa2:
    movq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x270(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x268(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x278(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    movq %rax,0x68(%rbp)
    movq 0x68(%rbp),%rax
    movq 0x60(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_0aa2
.Ltext_0b0a:
    movq 0x200(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x270(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movq 0x218(%rbp),%rax
    movq (%rax),%rax
    movq 0x200(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} je .Ltext_139b
    movq 0x2b0(%rbp),%rax
    movq 0x200(%rbp),%rdx
    movq 0x208(%rbp),%rcx
    movq 0x220(%rbp),%rbx
    movq 0x230(%rbp),%rsi
    movq 0x240(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    leaq 0x70(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x18(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x290(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x30(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x20(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x290(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x38(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x30(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x290(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x40(%rsp)
    movq %rcx,0xf0(%rbp)
    movq %rdx,%rcx
    movq 0xf0(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x200(%rbp),%rax
    movq 0x218(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq %rdx,0x78(%rbp)
    movq $0x0,0x80(%rbp)
    movq 0x200(%rbp),%rax
    movq $0xffffffffffffffff,%rdx
    addq (%rax),%rdx
    movq %rdx,0x88(%rbp)
    movq $0x0,0x68(%rbp)
    movq 0x88(%rbp),%rax
    testq %rax,%rax
    {disp32} jl .Ltext_0d19
.Ltext_0c62:
    movq 0x2a8(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    je .Ltext_0c92
    movq 0x68(%rbp),%rax
    addq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x290(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x98(%rbp)
    jmp .Ltext_0cb3
.Ltext_0c92:
    movq 0x68(%rbp),%rax
    addq 0x20(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x290(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x98(%rbp)
.Ltext_0cb3:
    movq 0x98(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_0cf8
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    movq 0x80(%rbp),%rdx
    addq 0x28(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x290(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq %rax,0x80(%rbp)
.Ltext_0cf8:
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    movq %rax,0x68(%rbp)
    movq 0x68(%rbp),%rax
    movq 0x88(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0c62
.Ltext_0d19:
    movq 0x80(%rbp),%rax
    movq %rax,0x78(%rbp)
    movq 0x2a8(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    je .Ltext_0d3e
    movq $0xffffffffffffffff,0x90(%rbp)
    jmp .Ltext_0d49
.Ltext_0d3e:
    movq $0x0,0x90(%rbp)
.Ltext_0d49:
    movq $0x1,0xa0(%rbp)
    movq 0x260(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x78(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq $0x1,0x68(%rbp)
    movq 0xa8(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_124b
.Ltext_0d85:
    movq 0x68(%rbp),%rax
    addq 0x28(%rbp),%rax
    decq %rax
    imulq $0x8,%rax,%rax
    addq 0x290(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xb8(%rbp)
    movq 0x2a8(%rbp),%rax
    movl (%rax),%eax
    testb $0x1,%al
    je .Ltext_0e2c
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0x40(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x288(%rbp),%rdx
    addq.s %rdx,%rax
    movq 0x248(%rbp),%rdx
    movq 0x208(%rbp),%rcx
    leaq 0xb8(%rbp),%rbx
    movq 0x250(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0x258(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x210(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq %rcx,0xf8(%rbp)
    movq %rax,%rcx
    movq 0xf8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.RT_FIND_ROW
    jmp .Ltext_0ea0
.Ltext_0e2c:
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0x40(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x288(%rbp),%rdx
    addq.s %rdx,%rax
    movq 0x248(%rbp),%rdx
    movq 0x200(%rbp),%rcx
    leaq 0xb8(%rbp),%rbx
    movq 0x250(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0x258(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x210(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq %rcx,0x100(%rbp)
    movq %rax,%rcx
    movq 0x100(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.RT_FIND_COLUMN
.Ltext_0ea0:
    movq 0x2b8(%rbp),%rax
    movq 0x200(%rbp),%rdx
    movq 0x208(%rbp),%rcx
    leaq 0x90(%rbp),%rbx
    leaq 0xa0(%rbp),%rsi
    movq 0x220(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x228(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x230(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x240(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movq 0x298(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    movq 0x2a0(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x40(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x288(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x50(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x48(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x288(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x130(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x50(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x288(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x68(%rsp)
    movl $0x0,%edi
    movl $0x8,%r8d
    subq.s %r8,%rdi
    movq 0x30(%rbp),%r8
    imulq $0x8,%r8,%r8
    addq 0x290(%rbp),%r8
    addq.s %r8,%rdi
    movq %rdi,0x70(%rsp)
    leaq 0x150(%rbp),%rdi
    movq %rdi,0x78(%rsp)
    movq %rcx,0x108(%rbp)
    movq %rdx,%rcx
    movq 0x108(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x30(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x290(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0xb8(%rbp),%rdx
    movq %rdx,(%rax)
    movq $0x1,0xc0(%rbp)
    movq 0x200(%rbp),%rax
    movq $0xffffffffffffffff,%rdx
    addq (%rax),%rdx
    movq %rdx,0xd8(%rbp)
    movq $0x0,0x80(%rbp)
    movq 0xd8(%rbp),%rax
    testq %rax,%rax
    {disp32} jl .Ltext_10c8
.Ltext_102b:
    movq 0x80(%rbp),%rax
    addq 0x48(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x288(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    andpd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm0
    movq 0x280(%rbp),%rax
    movsd (%rax),%xmm1
    comisd %xmm1,%xmm0
    jbe .Ltext_109e
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq 0xc0(%rbp),%rdx
    addq 0x30(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x290(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0xc0(%rbp),%rax
    movq %rax,0xc0(%rbp)
.Ltext_109e:
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq %rax,0x80(%rbp)
    movq 0x80(%rbp),%rax
    movq 0xd8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_102b
.Ltext_10c8:
    movq $0xffffffffffffffff,%rax
    addq 0xc0(%rbp),%rax
    movq %rax,0xe0(%rbp)
    movq $0x0,0x80(%rbp)
    movq 0xe0(%rbp),%rax
    testq %rax,%rax
    jl .Ltext_116a
.Ltext_10f4:
    movq 0x80(%rbp),%rax
    addq 0x30(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x290(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xb8(%rbp)
    movq 0xb8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x278(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xd0(%rbp)
    movq 0xd0(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_1194
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq %rax,0x80(%rbp)
    movq 0x80(%rbp),%rax
    movq 0xe0(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_10f4
.Ltext_116a:
    movq 0x260(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0x260(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x260(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xd0(%rbp)
.Ltext_1194:
    movq $0xffffffffffffffff,%rax
    addq 0xc0(%rbp),%rax
    movq %rax,0xe8(%rbp)
    movq $0x0,0x80(%rbp)
    movq 0xe8(%rbp),%rax
    testq %rax,%rax
    jl .Ltext_122a
.Ltext_11c0:
    movq 0x80(%rbp),%rax
    addq 0x30(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x290(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xb8(%rbp)
    movq 0xb8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x278(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0xd0(%rbp),%rdx
    movq %rdx,(%rax)
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq %rax,0x80(%rbp)
    movq 0x80(%rbp),%rax
    movq 0xe8(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_11c0
.Ltext_122a:
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    movq %rax,0x68(%rbp)
    movq 0x68(%rbp),%rax
    movq 0xa8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0d85
.Ltext_124b:
    movq 0x270(%rbp),%rax
    movq $0x1,(%rax)
    movq 0x260(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xb0(%rbp)
    movq $0x1,0x68(%rbp)
    movq 0xb0(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_139b
.Ltext_1282:
    movq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x270(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xc0(%rbp)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xc8(%rbp)
    movq $0x1,0x80(%rbp)
    movq 0xc8(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1358
.Ltext_12cb:
    movq 0x80(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x278(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0xd0(%rbp)
    movq 0xd0(%rbp),%rax
    movq 0x68(%rbp),%rdx
    cmpq.s %rdx,%rax
    jne .Ltext_132e
    movq 0xc0(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x268(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x80(%rbp),%rdx
    movq %rdx,(%rax)
    movl $0x1,%eax
    addq 0xc0(%rbp),%rax
    movq %rax,0xc0(%rbp)
.Ltext_132e:
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq %rax,0x80(%rbp)
    movq 0x80(%rbp),%rax
    movq 0xc8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_12cb
.Ltext_1358:
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x270(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0xc0(%rbp),%rdx
    movq %rdx,(%rax)
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    movq %rax,0x68(%rbp)
    movq 0x68(%rbp),%rax
    movq 0xb0(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1282
.Ltext_139b:
    movq 0x110(%rbp),%rbx
    movq 0x118(%rbp),%rsi
    movq 0x120(%rbp),%rdi
    leaq 0x1f0(%rbp),%rsp
    popq %rbp
    retq

# Clear the destination and accumulate entries for the selected sparse column.
    .globl RT_FIND_COLUMN
RT_FIND_COLUMN:
.Lend_RTANALYZEQN_ROWS_COLS:
    pushq %rbp
.Ltext_13ba:
    subq $0x50,%rsp
.Ltext_13be:
    leaq 0x20(%rsp),%rbp
.Ltext_13c3:
    movq %rcx,0x40(%rbp)
    movq %rdx,0x48(%rbp)
    movq %r8,0x50(%rbp)
    movq %r9,0x58(%rbp)
    movq 0x50(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x50(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq $0x1,0x10(%rbp)
    movq 0x8(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_142c
.Ltext_13fa:
    pxor %xmm0,%xmm0
    movq 0x10(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd %xmm0,(%rax)
    movl $0x1,%eax
    addq 0x10(%rbp),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    movq 0x8(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_13fa
.Ltext_142c:
    movq 0x70(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq $0x1,0x10(%rbp)
    movq 0x18(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_14e8
.Ltext_144c:
    movq 0x10(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x68(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq 0x20(%rbp),%rax
    movq 0x58(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jne .Ltext_14ca
    movq 0x10(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x60(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x10(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x48(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd (%rdx),%xmm1
    addsd %xmm1,%xmm0
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd %xmm0,(%rax)
.Ltext_14ca:
    movl $0x1,%eax
    addq 0x10(%rbp),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    movq 0x18(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_144c
.Ltext_14e8:
    leaq 0x30(%rbp),%rsp
    popq %rbp
    retq

# Clear the destination and accumulate entries for the selected sparse row.
    .globl RT_FIND_ROW
RT_FIND_ROW:
.Lend_RT_FIND_COLUMN:
    pushq %rbp
.Ltext_14ef:
    subq $0x50,%rsp
.Ltext_14f3:
    leaq 0x20(%rsp),%rbp
.Ltext_14f8:
    movq %rcx,0x40(%rbp)
    movq %rdx,0x48(%rbp)
    movq %r8,0x50(%rbp)
    movq %r9,0x58(%rbp)
    movq 0x50(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x50(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq $0x1,0x10(%rbp)
    movq 0x8(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_1561
.Ltext_152f:
    pxor %xmm0,%xmm0
    movq 0x10(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd %xmm0,(%rax)
    movl $0x1,%eax
    addq 0x10(%rbp),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    movq 0x8(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_152f
.Ltext_1561:
    movq 0x70(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq $0x1,0x10(%rbp)
    movq 0x18(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_161d
.Ltext_1581:
    movq 0x10(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x60(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq 0x20(%rbp),%rax
    movq 0x58(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jne .Ltext_15ff
    movq 0x10(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x68(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x10(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x48(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd (%rdx),%xmm1
    addsd %xmm1,%xmm0
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd %xmm0,(%rax)
.Ltext_15ff:
    movl $0x1,%eax
    addq 0x10(%rbp),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    movq 0x18(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1581
.Ltext_161d:
    leaq 0x30(%rbp),%rsp
    popq %rbp
    retq
.Lend_RT_FIND_ROW:
    nop
coff_end.text:

# @section .xdata 0x40300040
    .section .xdata
.Lbase_xdata:
.Lunwind_RTANALYZEQN:
    .byte 1, .Ltext_0025-RTANALYZEQN, 10, 0xc5  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0025-RTANALYZEQN, 0x34  # save rbx
    .short 392/8  # stack bytes in 8-byte units
    .byte .Ltext_001e-RTANALYZEQN, 0x64  # save rsi
    .short 400/8  # stack bytes in 8-byte units
    .byte .Ltext_0017-RTANALYZEQN, 0x74  # save rdi
    .short 408/8  # stack bytes in 8-byte units
    .byte .Ltext_0010-RTANALYZEQN, 0x03  # set frame pointer
    .byte .Ltext_0008-RTANALYZEQN, 0x01  # allocate large stack frame
    .short 896/8  # stack bytes in 8-byte units
    .byte .Ltext_0001-RTANALYZEQN, 0x50  # push rbp
.Lunwind_RTANALYZEQN_ROWS_COLS:
    .byte 1, .Ltext_0963-RTANALYZEQN_ROWS_COLS, 10, 0x85  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0963-RTANALYZEQN_ROWS_COLS, 0x34  # save rbx
    .short 400/8  # stack bytes in 8-byte units
    .byte .Ltext_095c-RTANALYZEQN_ROWS_COLS, 0x64  # save rsi
    .short 408/8  # stack bytes in 8-byte units
    .byte .Ltext_0955-RTANALYZEQN_ROWS_COLS, 0x74  # save rdi
    .short 416/8  # stack bytes in 8-byte units
    .byte .Ltext_094e-RTANALYZEQN_ROWS_COLS, 0x03  # set frame pointer
    .byte .Ltext_0946-RTANALYZEQN_ROWS_COLS, 0x01  # allocate large stack frame
    .short 624/8  # stack bytes in 8-byte units
    .byte .Ltext_093f-RTANALYZEQN_ROWS_COLS, 0x50  # push rbp
.Lunwind_RT_FIND_COLUMN:
    .byte 1, .Ltext_13c3-RT_FIND_COLUMN, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_13c3-RT_FIND_COLUMN, 0x03  # set frame pointer
    .byte .Ltext_13be-RT_FIND_COLUMN, 0x92  # allocate 80 stack bytes
    .byte .Ltext_13ba-RT_FIND_COLUMN, 0x50  # push rbp
    .short 0  # unwind slot padding
.Lunwind_RT_FIND_ROW:
    .byte 1, .Ltext_14f8-RT_FIND_ROW, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_14f8-RT_FIND_ROW, 0x03  # set frame pointer
    .byte .Ltext_14f3-RT_FIND_ROW, 0x92  # allocate 80 stack bytes
    .byte .Ltext_14ef-RT_FIND_ROW, 0x50  # push rbp
    .short 0  # unwind slot padding
coff_end.xdata:

# @section .pdata 0x40300040
    .section .pdata
.Lbase_pdata:
    .long coff_rva.RTANALYZEQN
    .long coff_rva.RTANALYZEQN+(.Lend_RTANALYZEQN-RTANALYZEQN)
    .long coff_rva..xdata+(.Lunwind_RTANALYZEQN-.Lbase_xdata)
    .long coff_rva.RTANALYZEQN_ROWS_COLS
    .long coff_rva.RTANALYZEQN_ROWS_COLS+(.Lend_RTANALYZEQN_ROWS_COLS-RTANALYZEQN_ROWS_COLS)
    .long coff_rva..xdata+(.Lunwind_RTANALYZEQN_ROWS_COLS-.Lbase_xdata)
    .long coff_rva.RT_FIND_COLUMN
    .long coff_rva.RT_FIND_COLUMN+(.Lend_RT_FIND_COLUMN-RT_FIND_COLUMN)
    .long coff_rva..xdata+(.Lunwind_RT_FIND_COLUMN-.Lbase_xdata)
    .long coff_rva.RT_FIND_ROW
    .long coff_rva.RT_FIND_ROW+(.Lend_RT_FIND_ROW-RT_FIND_ROW)
    .long coff_rva..xdata+(.Lunwind_RT_FIND_ROW-.Lbase_xdata)
coff_end.pdata:

# @section .rdata 0x40500040
    .section .rdata
.Lbase_rdata:
_2il0floatpacket.0:
    .quad 0x7fffffffffffffff, 0x0  # IEEE / SIMD bit pattern
coff_end.rdata:

# @section .drectve 0x100a00
    .section .drectve
.Lbase_drectve:
    .ascii "-export:RTANALYZEQN_ROWS_COLS  -export:RTANALYZEQN  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "
coff_end.drectve:
