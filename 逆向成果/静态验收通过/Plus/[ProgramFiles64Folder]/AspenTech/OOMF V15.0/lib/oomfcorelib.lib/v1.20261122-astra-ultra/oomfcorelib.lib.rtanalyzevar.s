# @member x64\Release\rtanalyzevar.obj 1743626479
# Windows AMD64 COFF. GNU as / AT&T syntax. Tables below preserve link and unwind contracts.

# @symbol section .text
# @symbol function CLASSIFY_VARIABLES
# @symbol function SPLIT_THINGS
# @symbol function OBSERVABILITY
# @symbol function REDUNDANCY
# @symbol function Z_BASIS
# @symbol function IJ_PRODUCT
# @symbol function FIND_COLUMN
# @symbol function FIND_ROW
# @symbol function RTPACKVECTOR
# @symbol section .xdata
# @symbol section .pdata
# @symbol section .rdata
# @symbol local _2il0floatpacket.0
# @symbol local _2il0floatpacket.1
# @symbol section .drectve
# @symbol external_function __ImageBase
# @symbol external_data _fltused


# @section .text 0x60300020
    .section .text
.Lbase_text:

# Drive SPLIT_THINGS, OBSERVABILITY and REDUNDANCY using the original by-reference arguments.
    .globl CLASSIFY_VARIABLES
CLASSIFY_VARIABLES:
    pushq %rbp
.Ltext_0001:
    subq $0x260,%rsp
.Ltext_0008:
    movq %rsp,%rbp
.Ltext_000b:
    movq %rdi,0x250(%rbp)
.Ltext_0012:
    movq %rsi,0x248(%rbp)
.Ltext_0019:
    movq %rbx,0x240(%rbp)
.Ltext_0020:
    movq %rcx,0x270(%rbp)
    movq %rdx,0x278(%rbp)
    movq %r8,0x280(%rbp)
    movq %r9,0x288(%rbp)
    movq 0x280(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x100(%rbp)
    movq 0x278(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x108(%rbp)
    movq 0x2b8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x110(%rbp)
    movq 0x2c0(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x118(%rbp)
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x120(%rbp)
    movq $0x1,0x128(%rbp)
    movq 0x280(%rbp),%rax
    movq (%rax),%rax
    addq 0x128(%rbp),%rax
    movq %rax,0x130(%rbp)
    movq 0x280(%rbp),%rax
    movq (%rax),%rax
    addq 0x130(%rbp),%rax
    movq %rax,0x138(%rbp)
    movq $0x1,0x140(%rbp)
    movq 0x280(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x148(%rbp)
    movq 0x280(%rbp),%rax
    movq (%rax),%rax
    imulq $0x2,%rax,%rax
    movq 0x278(%rbp),%rdx
    addq (%rdx),%rax
    movq %rax,0x150(%rbp)
    movq 0x2c0(%rbp),%rax
    movq (%rax),%rax
    movq 0x150(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jl .Ltext_0257
    movq 0x2b8(%rbp),%rax
    movq (%rax),%rax
    movq 0x148(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jl .Ltext_0257
    movq 0x288(%rbp),%rax
    movq 0x290(%rbp),%rdx
    movq 0x298(%rbp),%rcx
    movq 0x278(%rbp),%rbx
    movq 0x280(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x140(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x28(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x128(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x30(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x130(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x38(%rsp)
    leaq 0x158(%rbp),%rsi
    movq %rsi,0x40(%rsp)
    leaq 0x170(%rbp),%rsi
    movq %rsi,0x48(%rsp)
    leaq 0x190(%rbp),%rsi
    movq %rsi,0x50(%rsp)
    leaq 0x180(%rbp),%rsi
    movq %rsi,0x58(%rsp)
    movq 0x2a0(%rbp),%rsi
    movq %rsi,0x60(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x138(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x68(%rsp)
    movq %rcx,0x228(%rbp)
    movq %rax,%rcx
    movq 0x228(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.SPLIT_THINGS
.Ltext_0257:
    movq 0x158(%rbp),%rax
    addq 0x128(%rbp),%rax
    movq %rax,0x160(%rbp)
    movq 0x158(%rbp),%rax
    addq 0x130(%rbp),%rax
    movq %rax,0x168(%rbp)
    movq 0x170(%rbp),%rax
    addq 0x168(%rbp),%rax
    movq %rax,0x178(%rbp)
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    addq 0x178(%rbp),%rax
    movq 0x180(%rbp),%rdx
    imulq $0x9,%rdx,%rdx
    addq.s %rdx,%rax
    addq $0x7,%rax
    movq %rax,0x188(%rbp)
    movq 0x190(%rbp),%rax
    movq 0x180(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_02e3
    movq 0x180(%rbp),%rax
    movq %rax,0x198(%rbp)
    jmp .Ltext_02f1
.Ltext_02e3:
    movq 0x190(%rbp),%rax
    movq %rax,0x198(%rbp)
.Ltext_02f1:
    movq 0x198(%rbp),%rax
    addq 0x188(%rbp),%rax
    movq %rax,0x1a0(%rbp)
    movq 0x2c8(%rbp),%rax
    movq (%rax),%rax
    addq 0x1a0(%rbp),%rax
    movq %rax,0x1a8(%rbp)
    movq 0x2c8(%rbp),%rax
    movq (%rax),%rax
    addq 0x1a8(%rbp),%rax
    movq %rax,0x1b0(%rbp)
    movq 0x180(%rbp),%rax
    addq 0x1b0(%rbp),%rax
    movq %rax,0x1b8(%rbp)
    movq 0x190(%rbp),%rax
    addq 0x1b8(%rbp),%rax
    movq %rax,0x1c0(%rbp)
    movq 0x180(%rbp),%rax
    addq 0x1c0(%rbp),%rax
    movq %rax,0x138(%rbp)
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    imulq $0x6,%rax,%rax
    addq 0x138(%rbp),%rax
    movq 0x180(%rbp),%rdx
    imulq $0x3,%rdx,%rdx
    addq.s %rdx,%rax
    decq %rax
    movq %rax,0x150(%rbp)
    movq 0x158(%rbp),%rax
    addq 0x140(%rbp),%rax
    movq %rax,0x1c8(%rbp)
    movq 0x170(%rbp),%rax
    addq 0x1c8(%rbp),%rax
    movq %rax,0x1d0(%rbp)
    movq 0x1d0(%rbp),%rax
    movq %rax,0x1d8(%rbp)
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    addq 0x1d0(%rbp),%rax
    movq %rax,0x1e0(%rbp)
    movq 0x180(%rbp),%rax
    addq 0x1e0(%rbp),%rax
    movq %rax,0x1e8(%rbp)
    movq 0x2c8(%rbp),%rax
    movq (%rax),%rax
    addq 0x1e8(%rbp),%rax
    movq %rax,0x1f0(%rbp)
    movq 0x180(%rbp),%rax
    addq 0x1f0(%rbp),%rax
    movq %rax,0x1f8(%rbp)
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    imulq $0x3,%rax,%rax
    addq 0x180(%rbp),%rax
    movq 0x180(%rbp),%rdx
    imulq $0x3,%rdx,%rdx
    movq 0x270(%rbp),%rcx
    addq (%rcx),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0481
    movq 0x180(%rbp),%rax
    imulq $0x3,%rax,%rax
    movq 0x270(%rbp),%rdx
    addq (%rdx),%rax
    movq %rax,0x200(%rbp)
    jmp .Ltext_049d
.Ltext_0481:
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    imulq $0x3,%rax,%rax
    addq 0x180(%rbp),%rax
    movq %rax,0x200(%rbp)
.Ltext_049d:
    movq 0x200(%rbp),%rax
    addq 0x1f8(%rbp),%rax
    decq %rax
    movq %rax,0x148(%rbp)
    movq 0x2d0(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x2b8(%rbp),%rax
    movq (%rax),%rax
    movq 0x148(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_04f8
    movq 0x2d0(%rbp),%rax
    movq $0x2,(%rax)
    movq 0x2b8(%rbp),%rax
    movq 0x148(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_04f8:
    movq 0x2c0(%rbp),%rax
    movq (%rax),%rax
    movq 0x150(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_052d
    movq 0x2d0(%rbp),%rax
    movq $0x1,(%rax)
    movq 0x2c0(%rbp),%rax
    movq 0x150(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_052d:
    movq 0x2c0(%rbp),%rax
    movq (%rax),%rax
    movq 0x150(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0567
    movq 0x2b8(%rbp),%rax
    movq (%rax),%rax
    movq 0x148(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_0567
    movq 0x2d0(%rbp),%rax
    movq $0x3,(%rax)
.Ltext_0567:
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jne .Ltext_0dab
    movq 0x180(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_05a2
    movq 0x2d8(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x2e0(%rbp),%rax
    movq $0x0,(%rax)
.Ltext_05a2:
    movq 0x190(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_05ca
    movq 0x2e8(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x2f0(%rbp),%rax
    movq $0x0,(%rax)
.Ltext_05ca:
    movq 0x180(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0910
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0x1c8(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x2a8(%rbp),%rdx
    addq.s %rdx,%rax
    movl $0x0,%edx
    movl $0x8,%ecx
    subq.s %rcx,%rdx
    movq 0x160(%rbp),%rcx
    imulq $0x8,%rcx,%rcx
    addq 0x2b0(%rbp),%rcx
    addq.s %rcx,%rdx
    movl $0x0,%ecx
    movl $0x8,%ebx
    subq.s %rbx,%rcx
    movq 0x168(%rbp),%rbx
    imulq $0x8,%rbx,%rbx
    addq 0x2b0(%rbp),%rbx
    addq.s %rbx,%rcx
    movq 0x270(%rbp),%rbx
    leaq 0x180(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    leaq 0x170(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x2c8(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x178(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x38(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x138(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x40(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1f8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x48(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1d0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x50(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1e0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x58(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x188(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x60(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1a0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x68(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1a8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x70(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1e8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x78(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1b0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x80(%rsp)
    movq 0x2f8(%rbp),%rsi
    movq %rsi,0x88(%rsp)
    movq 0x2d8(%rbp),%rsi
    movq %rsi,0x90(%rsp)
    movq 0x2e0(%rbp),%rsi
    movq %rsi,0x98(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1c0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0xa0(%rsp)
    movq 0x300(%rbp),%rsi
    movq %rsi,0xa8(%rsp)
    movq 0x308(%rbp),%rsi
    movq %rsi,0xb0(%rsp)
    movq 0x2d0(%rbp),%rsi
    movq %rsi,0xb8(%rsp)
    movq 0x310(%rbp),%rsi
    movq %rsi,0xc0(%rsp)
    movq 0x318(%rbp),%rsi
    movq %rsi,0xc8(%rsp)
    movq 0x320(%rbp),%rsi
    movq %rsi,0xd0(%rsp)
    movq 0x328(%rbp),%rsi
    movq %rsi,0xd8(%rsp)
    movq 0x330(%rbp),%rsi
    movq %rsi,0xe0(%rsp)
    movq 0x338(%rbp),%rsi
    movq %rsi,0xe8(%rsp)
    movq 0x340(%rbp),%rsi
    movq %rsi,0xf0(%rsp)
    movq %rcx,0x230(%rbp)
    movq %rax,%rcx
    movq 0x230(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.OBSERVABILITY
    movq 0x2d0(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jg .Ltext_0dab
.Ltext_0910:
    movq 0x190(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0c31
    movq 0x270(%rbp),%rax
    leaq 0x190(%rbp),%rdx
    leaq 0x158(%rbp),%rcx
    leaq 0x180(%rbp),%rbx
    leaq 0x170(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x140(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x28(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1c8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x30(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x128(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x38(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x160(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x40(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x130(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x48(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x168(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x50(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1b8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x58(%rsp)
    movq 0x2e8(%rbp),%rsi
    movq %rsi,0x60(%rsp)
    movq 0x2f0(%rbp),%rsi
    movq %rsi,0x68(%rsp)
    movq 0x2c8(%rbp),%rsi
    movq %rsi,0x70(%rsp)
    movq 0x300(%rbp),%rsi
    movq %rsi,0x78(%rsp)
    movq 0x2f8(%rbp),%rsi
    movq %rsi,0x80(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x138(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x88(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1a0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x90(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x178(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0x98(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1e8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0xa0(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1d8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0xa8(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1f0(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0xb0(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x1f8(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2a8(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0xb8(%rsp)
    movl $0x0,%esi
    movl $0x8,%edi
    subq.s %rdi,%rsi
    movq 0x188(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    addq 0x2b0(%rbp),%rdi
    addq.s %rdi,%rsi
    movq %rsi,0xc0(%rsp)
    movq 0x310(%rbp),%rsi
    movq %rsi,0xc8(%rsp)
    movq 0x340(%rbp),%rsi
    movq %rsi,0xd0(%rsp)
    movq 0x320(%rbp),%rsi
    movq %rsi,0xd8(%rsp)
    movq %rcx,0x238(%rbp)
    movq %rax,%rcx
    movq 0x238(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.REDUNDANCY
.Ltext_0c31:
    movq $0x0,0x208(%rbp)
    movq $0x0,0x210(%rbp)
    movq 0x278(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x218(%rbp)
    movq $0x1,0x220(%rbp)
    movq 0x218(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0dab
.Ltext_0c73:
    movq 0x220(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0d0c
    movq 0x208(%rbp),%rax
    addq 0x1b8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    cmpq $0x1,%rax
    jne .Ltext_0cda
    movq 0x220(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
    jmp .Ltext_0cf7
.Ltext_0cda:
    movq 0x220(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x2,(%rax)
.Ltext_0cf7:
    movl $0x1,%eax
    addq 0x208(%rbp),%rax
    movq %rax,0x208(%rbp)
    jmp .Ltext_0d81
.Ltext_0d0c:
    movq 0x210(%rbp),%rax
    addq 0x1c0(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2b0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    cmpq $0x1,%rax
    jne .Ltext_0d51
    movq 0x220(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0xffffffffffffffff,(%rax)
    jmp .Ltext_0d6e
.Ltext_0d51:
    movq 0x220(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x2a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0xfffffffffffffffe,(%rax)
.Ltext_0d6e:
    movl $0x1,%eax
    addq 0x210(%rbp),%rax
    movq %rax,0x210(%rbp)
.Ltext_0d81:
    movl $0x1,%eax
    addq 0x220(%rbp),%rax
    movq %rax,0x220(%rbp)
    movq 0x220(%rbp),%rax
    movq 0x218(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0c73
.Ltext_0dab:
    movq 0x240(%rbp),%rbx
    movq 0x248(%rbp),%rsi
    movq 0x250(%rbp),%rdi
    leaq 0x260(%rbp),%rsp
    popq %rbp
    retq

# Build two index sets from the classification flags using one-based indices.
    .globl SPLIT_THINGS
SPLIT_THINGS:
.Lend_CLASSIFY_VARIABLES:
    pushq %rbp
.Ltext_0dca:
    subq $0x60,%rsp
.Ltext_0dce:
    leaq 0x20(%rsp),%rbp
.Ltext_0dd3:
    movq %rcx,0x50(%rbp)
    movq %rdx,0x58(%rbp)
    movq %r8,0x60(%rbp)
    movq %r9,0x68(%rbp)
    movq 0x70(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x68(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0xa0(%rbp),%rax
    movq $0x0,(%rax)
    movq 0xa8(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x68(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq $0x1,0x18(%rbp)
    movq 0x10(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0ee3
.Ltext_0e35:
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0xb0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    cmpq $0x1,%rax
    jne .Ltext_0e8c
    movq 0xa0(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0xa0(%rbp),%rax
    movq %rdx,(%rax)
    movq 0xa0(%rbp),%rax
    movq 0x18(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0xb8(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    jmp .Ltext_0ec5
.Ltext_0e8c:
    movq 0xa8(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0xa8(%rbp),%rax
    movq %rdx,(%rax)
    movq 0xa8(%rbp),%rax
    movq 0x18(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0xb8(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
.Ltext_0ec5:
    movl $0x1,%eax
    addq 0x18(%rbp),%rax
    movq %rax,0x18(%rbp)
    movq 0x18(%rbp),%rax
    movq 0x10(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0e35
.Ltext_0ee3:
    movq 0x90(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x98(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x70(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq $0x1,0x18(%rbp)
    movq 0x20(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1106
.Ltext_0f1f:
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x58(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x28(%rbp)
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x60(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x30(%rbp)
    movq 0x30(%rbp),%rax
    movq %rax,0x38(%rbp)
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0xb0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    cmpq $0x1,%rax
    {disp32} jne .Ltext_1022
    movq 0x90(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0x90(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x50(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x90(%rbp),%rdx
    movq (%rdx),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x78(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x58(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x90(%rbp),%rdx
    movq (%rdx),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x80(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0xb8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x90(%rbp),%rdx
    movq (%rdx),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x88(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    {disp32} jmp .Ltext_10e8
.Ltext_1022:
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x50(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x70(%rbp),%rdx
    movq 0x98(%rbp),%rcx
    movq (%rcx),%rcx
    negq %rcx
    addq (%rdx),%rcx
    imulq $0x8,%rcx,%rdx
    addq 0x78(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x58(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x70(%rbp),%rdx
    movq 0x98(%rbp),%rcx
    movq (%rcx),%rcx
    negq %rcx
    addq (%rdx),%rcx
    imulq $0x8,%rcx,%rdx
    addq 0x80(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0xb8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x70(%rbp),%rdx
    movq 0x98(%rbp),%rcx
    movq (%rcx),%rcx
    negq %rcx
    addq (%rdx),%rcx
    imulq $0x8,%rcx,%rdx
    addq 0x88(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x98(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0x98(%rbp),%rax
    movq %rdx,(%rax)
.Ltext_10e8:
    movl $0x1,%eax
    addq 0x18(%rbp),%rax
    movq %rax,0x18(%rbp)
    movq 0x18(%rbp),%rax
    movq 0x20(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0f1f
.Ltext_1106:
    leaq 0x40(%rbp),%rsp
    popq %rbp
    retq

    .globl OBSERVABILITY
OBSERVABILITY:
.Lend_SPLIT_THINGS:
    pushq %rbp
.Ltext_110d:
    subq $0x370,%rsp
.Ltext_1114:
    leaq 0x80(%rsp),%rbp
.Ltext_111c:
    movq %rdi,0xe0(%rbp)
.Ltext_1123:
    movq %rsi,0xd8(%rbp)
.Ltext_112a:
    movq %rbx,0xd0(%rbp)
.Ltext_1131:
    movq %rcx,0x300(%rbp)
    movq %rdx,0x308(%rbp)
    movq %r8,0x310(%rbp)
    movq %r9,0x318(%rbp)
    movq 0x328(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x318(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x330(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq 0x3d0(%rbp),%rax
    leaq 0xf0(%rbp),%rdx
    leaq 0x140(%rbp),%rcx
    movq %rcx,0x98(%rbp)
    movq %rdx,%rcx
    movq 0x98(%rbp),%rdx
    callq *%rax
    leaq 0x140(%rbp),%rax
    addq $0x10,%rax
    movq $0x0,(%rax)
    leaq 0x140(%rbp),%rax
    addq $0x8,%rax
    movq $0x6,(%rax)
    leaq 0x140(%rbp),%rax
    addq $0x30,%rax
    movq $0x0,(%rax)
    movq 0x3c8(%rbp),%rax
    leaq 0xf0(%rbp),%rdx
    addq $0x18,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movq 0x328(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x20(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_12dc
.Ltext_1220:
    movq 0x328(%rbp),%rax
    movq 0x28(%rbp),%rdx
    negq %rdx
    addq (%rax),%rdx
    incq %rdx
    movq %rdx,0x38(%rbp)
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x308(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x38(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x368(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x310(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x38(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x370(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x300(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x38(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x378(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movsd (%rax),%xmm0
    movsd %xmm0,(%rdx)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x20(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1220
.Ltext_12dc:
    movq $0x1,0x30(%rbp)
    movq 0x3d8(%rbp),%rax
    movq 0x318(%rbp),%rdx
    movq 0x320(%rbp),%rcx
    movq 0x328(%rbp),%rbx
    leaq 0x30(%rbp),%rsi
    movq 0x330(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x378(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x368(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x370(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movq 0x338(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    leaq 0xf0(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    leaq 0x140(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movq 0x340(%rbp),%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x1e0(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    leaq 0x280(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    movq %rcx,0xa0(%rbp)
    movq %rdx,%rcx
    movq 0xa0(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x3b8(%rbp),%rax
    movq $0x0,(%rax)
    leaq 0x1e0(%rbp),%rax
    movq (%rax),%rax
    cmpq $0xfffffffffffffffd,%rax
    jne .Ltext_13de
    leaq 0x1e0(%rbp),%rax
    addq $0x10,%rax
    movq 0x330(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x3b8(%rbp),%rax
    movq $0x4,(%rax)
    {disp32} jmp .Ltext_1b7e
.Ltext_13de:
    leaq 0x1e0(%rbp),%rax
    addq $0x48,%rax
    movq 0x3b0(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq $0x1,0x30(%rbp)
    movq 0x3e0(%rbp),%rax
    movq 0x318(%rbp),%rdx
    movq 0x320(%rbp),%rcx
    movq 0x328(%rbp),%rbx
    leaq 0x30(%rbp),%rsi
    movq 0x330(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x378(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x368(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x370(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movq 0x338(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    leaq 0xf0(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    leaq 0x140(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movq 0x348(%rbp),%rdi
    movq %rdi,0x58(%rsp)
    movq 0x340(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    leaq 0x1e0(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    leaq 0x280(%rbp),%rdi
    movq %rdi,0x70(%rsp)
    movq %rcx,0xa8(%rbp)
    movq %rdx,%rcx
    movq 0xa8(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x3b8(%rbp),%rax
    movq $0x0,(%rax)
    leaq 0x1e0(%rbp),%rax
    movq (%rax),%rax
    cmpq $0xfffffffffffffffd,%rax
    jne .Ltext_1504
    leaq 0x1e0(%rbp),%rax
    addq $0x18,%rax
    movq 0x330(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x3b8(%rbp),%rax
    movq $0x4,(%rax)
    {disp32} jmp .Ltext_1b7e
.Ltext_1504:
    leaq 0x1e0(%rbp),%rax
    addq $0x20,%rax
    movq 0x3a8(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x318(%rbp),%rax
    movq (%rax),%rax
    movq 0x320(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} jl .Ltext_165e
    movq 0x3a8(%rbp),%rax
    movq (%rax),%rax
    movq 0x320(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} jne .Ltext_165e
    movq 0x320(%rbp),%rax
    movq 0x390(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x398(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x3e8(%rbp),%rax
    movq 0x318(%rbp),%rdx
    movq 0x320(%rbp),%rcx
    movq 0x330(%rbp),%rbx
    movq 0x368(%rbp),%rsi
    movq 0x338(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x3a8(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x388(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x3a0(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movq 0x340(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    movq %rcx,0xb0(%rbp)
    movq %rdx,%rcx
    movq 0xb0(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x48(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x48(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1b7e
.Ltext_1613:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x3a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x380(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x48(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_1613
    {disp32} jmp .Ltext_1b7e
.Ltext_165e:
    movq 0x3e8(%rbp),%rax
    movq 0x318(%rbp),%rdx
    movq 0x320(%rbp),%rcx
    movq 0x330(%rbp),%rbx
    movq 0x368(%rbp),%rsi
    movq 0x338(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x3a8(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x388(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x3a0(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    movq 0x340(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    movq %rcx,0xb8(%rbp)
    movq %rdx,%rcx
    movq 0xb8(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x40(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x40(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_173b
.Ltext_16f5:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x3a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x380(%rbp),%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x40(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_16f5
.Ltext_173b:
    movq 0x320(%rbp),%rax
    movq 0x3a8(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x398(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x320(%rbp),%rax
    movq 0x398(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x390(%rbp),%rax
    movq %rdx,(%rax)
    movq $0x0,0x50(%rbp)
    movq 0x398(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x58(%rbp)
    movq 0x320(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x60(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x60(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_183f
.Ltext_17b6:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x3a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_17fa
    movl $0x1,%eax
    addq 0x50(%rbp),%rax
    movq %rax,0x50(%rbp)
    movq 0x50(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x360(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    movq %rdx,(%rax)
    jmp .Ltext_1821
.Ltext_17fa:
    movl $0x1,%eax
    addq 0x58(%rbp),%rax
    movq %rax,0x58(%rbp)
    movq 0x58(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x360(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x28(%rbp),%rdx
    movq %rdx,(%rax)
.Ltext_1821:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x60(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_17b6
.Ltext_183f:
    movq $0x1,0x30(%rbp)
    movq $0x0,0x68(%rbp)
    movq 0x398(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x70(%rbp)
    movq $0x1,0x28(%rbp)
    movq 0x70(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1b5d
.Ltext_1872:
    movq 0x28(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x360(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x78(%rbp)
    movq 0x350(%rbp),%rax
    movq 0x300(%rbp),%rdx
    movq 0x318(%rbp),%rcx
    leaq 0x78(%rbp),%rbx
    movq 0x308(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0x310(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x328(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq %rcx,0xc0(%rbp)
    movq %rax,%rcx
    movq 0xc0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.FIND_COLUMN
    movq 0x3f0(%rbp),%rax
    movq 0x318(%rbp),%rdx
    movq 0x320(%rbp),%rcx
    leaq 0x68(%rbp),%rbx
    leaq 0x30(%rbp),%rsi
    movq 0x330(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x378(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x368(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x338(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    leaq 0xf0(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    leaq 0x140(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    movq 0x350(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movq 0x358(%rbp),%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x2d0(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    movq 0x348(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    movq 0x340(%rbp),%rdi
    movq %rdi,0x70(%rsp)
    leaq 0x1e0(%rbp),%rdi
    movq %rdi,0x78(%rsp)
    movq %rcx,0xc8(%rbp)
    movq %rdx,%rcx
    movq 0xc8(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq $0x0,0x80(%rbp)
    movq 0x390(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x88(%rbp)
    movq $0x1,0x50(%rbp)
    movq 0x88(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_1ab6
.Ltext_19df:
    movq 0x398(%rbp),%rax
    movq 0x50(%rbp),%rdx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x360(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x90(%rbp)
    movq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x358(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    andpd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm0
    movq 0x3c0(%rbp),%rax
    movsd (%rax),%xmm1
    comisd %xmm1,%xmm0
    jbe .Ltext_1a95
    movq 0x90(%rbp),%rax
    movq %rax,0x78(%rbp)
    movq 0x78(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x3a0(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movl $0x1,%eax
    addq 0x80(%rbp),%rax
    movq %rax,0x80(%rbp)
    movq 0x398(%rbp),%rax
    movq 0x50(%rbp),%rdx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    addq 0x360(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
.Ltext_1a95:
    movl $0x1,%eax
    addq 0x50(%rbp),%rax
    movq %rax,0x50(%rbp)
    movq 0x50(%rbp),%rax
    movq 0x88(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_19df
.Ltext_1ab6:
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0x398(%rbp),%rdx
    movl $0x1,%ecx
    addq (%rdx),%rcx
    imulq $0x8,%rcx,%rdx
    addq 0x360(%rbp),%rdx
    addq.s %rdx,%rax
    movq 0x390(%rbp),%rdx
    movq %rax,%rcx
    callq coff_ref.RTPACKVECTOR
    movq 0x390(%rbp),%rax
    movq 0x80(%rbp),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x390(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x390(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_1b3f
    movq 0x320(%rbp),%rax
    movq 0x390(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x398(%rbp),%rax
    movq %rdx,(%rax)
    jmp .Ltext_1b7e
.Ltext_1b3f:
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x70(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1872
.Ltext_1b5d:
    movq 0x320(%rbp),%rax
    movq 0x390(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x398(%rbp),%rax
    movq %rdx,(%rax)
.Ltext_1b7e:
    movq 0xd0(%rbp),%rbx
    movq 0xd8(%rbp),%rsi
    movq 0xe0(%rbp),%rdi
    leaq 0x2f0(%rbp),%rsp
    popq %rbp
    retq

    .globl REDUNDANCY
REDUNDANCY:
.Lend_OBSERVABILITY:
    pushq %rbp
.Ltext_1b9d:
    subq $0x140,%rsp
.Ltext_1ba4:
    leaq 0xa0(%rsp),%rbp
.Ltext_1bac:
    movq %rsi,0x98(%rbp)
.Ltext_1bb3:
    movq %rbx,0x90(%rbp)
.Ltext_1bba:
    movq %rcx,0xb0(%rbp)
    movq %rdx,0xb8(%rbp)
    movq %r8,0xc0(%rbp)
    movq %r9,0xc8(%rbp)
    movq 0xc0(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0xd0(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0xb8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0xb0(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq 0xc8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq 0x120(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x28(%rbp)
    movq 0xb8(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x30(%rbp)
    movq $0x1,0x38(%rbp)
    movq 0x30(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_1c97
.Ltext_1c49:
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x108(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x170(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x38(%rbp),%rdx
    movq %rdx,(%rax)
    movl $0x1,%eax
    addq 0x38(%rbp),%rax
    movq %rax,0x38(%rbp)
    movq 0x38(%rbp),%rax
    movq 0x30(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_1c49
.Ltext_1c97:
    movq 0x110(%rbp),%rax
    movq $0x0,(%rax)
    movq 0xb8(%rbp),%rax
    movq 0x118(%rbp),%rdx
    movq (%rax),%rax
    movq %rax,(%rdx)
    movq 0x128(%rbp),%rax
    movq (%rax),%rax
    movq 0xb0(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} je .Ltext_207c
    movq 0xc8(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jne .Ltext_1dc9
    movq 0xc0(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x40(%rbp)
    movq $0x1,0x38(%rbp)
    movq 0x40(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_207c
.Ltext_1d0c:
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0xf8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x50(%rbp)
    movq 0x50(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0xd8(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    andpd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm0
    movq 0x178(%rbp),%rax
    movsd (%rax),%xmm1
    comisd %xmm1,%xmm0
    jae .Ltext_1da6
    jp .Ltext_1da6
    movq 0x50(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x108(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
    movq 0x110(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0x110(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x118(%rbp),%rax
    movq $0xffffffffffffffff,%rdx
    addq (%rax),%rdx
    movq 0x118(%rbp),%rax
    movq %rdx,(%rax)
.Ltext_1da6:
    movl $0x1,%eax
    addq 0x38(%rbp),%rax
    movq %rax,0x38(%rbp)
    movq 0x38(%rbp),%rax
    movq 0x40(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1d0c
    {disp32} jmp .Ltext_207c
.Ltext_1dc9:
    movq 0xb0(%rbp),%rax
    movq 0x128(%rbp),%rdx
    movq (%rdx),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq %rdx,0x48(%rbp)
    movq $0x1,0x38(%rbp)
    movq 0x48(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_207c
.Ltext_1df9:
    leaq 0x38(%rbp),%rax
    movq 0xe0(%rbp),%rdx
    movq 0x158(%rbp),%rcx
    movq 0xb0(%rbp),%rbx
    movq 0xc8(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0xd0(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x120(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq 0x128(%rbp),%rsi
    movq %rsi,0x38(%rsp)
    movq 0x130(%rbp),%rsi
    movq %rsi,0x40(%rsp)
    movq 0xf0(%rbp),%rsi
    movq %rsi,0x48(%rsp)
    movq 0x100(%rbp),%rsi
    movq %rsi,0x50(%rsp)
    movq 0x138(%rbp),%rsi
    movq %rsi,0x58(%rsp)
    movq 0x168(%rbp),%rsi
    movq %rsi,0x60(%rsp)
    movq 0x140(%rbp),%rsi
    movq %rsi,0x68(%rsp)
    movq 0x150(%rbp),%rsi
    movq %rsi,0x70(%rsp)
    movq 0x148(%rbp),%rsi
    movq %rsi,0x78(%rsp)
    movq 0x160(%rbp),%rsi
    movq %rsi,0x80(%rsp)
    movq 0x180(%rbp),%rsi
    movq %rsi,0x88(%rsp)
    movq 0x188(%rbp),%rsi
    movq %rsi,0x90(%rsp)
    movq %rcx,0x80(%rbp)
    movq %rax,%rcx
    movq 0x80(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.Z_BASIS
    movq $0x0,0x58(%rbp)
    movq 0x118(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x60(%rbp)
    movq $0x1,0x68(%rbp)
    movq 0x60(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_2015
.Ltext_1f16:
    movq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x170(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x50(%rbp)
    leaq 0x50(%rbp),%rax
    movq 0xb0(%rbp),%rdx
    movq 0xc0(%rbp),%rcx
    movq 0x158(%rbp),%rbx
    movq 0xd8(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0xe8(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0xf8(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq %rcx,0x88(%rbp)
    movq %rax,%rcx
    movq 0x88(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.IJ_PRODUCT
    movsd %xmm0,0x70(%rbp)
    movsd 0x70(%rbp),%xmm0
    movsd %xmm0,0x78(%rbp)
    movsd 0x78(%rbp),%xmm0
    andpd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm0
    movq 0x178(%rbp),%rax
    movsd (%rax),%xmm1
    comisd %xmm1,%xmm0
    jbe .Ltext_1ff7
    movl $0x1,%eax
    addq 0x58(%rbp),%rax
    movq %rax,0x58(%rbp)
    movq 0x50(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x108(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x1,(%rax)
    movq 0x68(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x170(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
.Ltext_1ff7:
    movl $0x1,%eax
    addq 0x68(%rbp),%rax
    movq %rax,0x68(%rbp)
    movq 0x68(%rbp),%rax
    movq 0x60(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1f16
.Ltext_2015:
    movq 0x170(%rbp),%rax
    movq 0x118(%rbp),%rdx
    movq %rax,%rcx
    callq coff_ref.RTPACKVECTOR
    movq 0x110(%rbp),%rax
    movq 0x58(%rbp),%rdx
    addq (%rax),%rdx
    movq 0x110(%rbp),%rax
    movq %rdx,(%rax)
    movq 0x118(%rbp),%rax
    movq 0x58(%rbp),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x118(%rbp),%rax
    movq %rdx,(%rax)
    movl $0x1,%eax
    addq 0x38(%rbp),%rax
    movq %rax,0x38(%rbp)
    movq 0x38(%rbp),%rax
    movq 0x48(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_1df9
.Ltext_207c:
    movq 0x90(%rbp),%rbx
    movq 0x98(%rbp),%rsi
    leaq 0xa0(%rbp),%rsp
    popq %rbp
    retq

# Preserve the ordered floating-point operations and the original index loops.
    .globl Z_BASIS
Z_BASIS:
.Lend_REDUNDANCY:
    pushq %rbp
.Ltext_2094:
    subq $0x2b0,%rsp
.Ltext_209b:
    leaq 0x80(%rsp),%rbp
.Ltext_20a3:
    movq %rdi,0x78(%rbp)
.Ltext_20a7:
    movq %rsi,0x70(%rbp)
.Ltext_20ab:
    movq %rbx,0x68(%rbp)
.Ltext_20af:
    movq %rcx,0x240(%rbp)
    movq %rdx,0x248(%rbp)
    movq %r8,0x250(%rbp)
    movq %r9,0x258(%rbp)
    movq 0x268(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x258(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0x260(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x270(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq 0x278(%rbp),%rax
    movq (%rax),%rax
    movq 0x258(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} je .Ltext_237d
    movq 0x240(%rbp),%rax
    movq (%rax),%rax
    movq 0x258(%rbp),%rdx
    movq 0x278(%rbp),%rcx
    movq (%rcx),%rcx
    negq %rcx
    addq (%rdx),%rcx
    cmpq.s %rcx,%rax
    {disp32} jg .Ltext_237d
    movq 0x260(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} je .Ltext_237d
    movq $0x0,0x20(%rbp)
    movq 0x258(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x28(%rbp)
    movq $0x1,0x30(%rbp)
    movq 0x28(%rbp),%rax
    testq %rax,%rax
    jle .Ltext_21e3
.Ltext_2184:
    movq 0x30(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x280(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    testq %rax,%rax
    jne .Ltext_21c9
    movl $0x1,%eax
    addq 0x20(%rbp),%rax
    movq %rax,0x20(%rbp)
    movq 0x20(%rbp),%rax
    movq 0x240(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jne .Ltext_21c9
    movq 0x30(%rbp),%rax
    movq %rax,0x38(%rbp)
    jmp .Ltext_21e3
.Ltext_21c9:
    movl $0x1,%eax
    addq 0x30(%rbp),%rax
    movq %rax,0x30(%rbp)
    movq 0x30(%rbp),%rax
    movq 0x28(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_2184
.Ltext_21e3:
    movq 0x2c0(%rbp),%rax
    movq 0x248(%rbp),%rdx
    movq 0x260(%rbp),%rcx
    leaq 0x38(%rbp),%rbx
    movq 0x288(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0x290(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x268(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    movq %rcx,0x50(%rbp)
    movq %rax,%rcx
    movq 0x50(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq coff_ref.FIND_ROW
    movq 0x2d0(%rbp),%rax
    leaq 0x80(%rbp),%rdx
    leaq 0xd0(%rbp),%rcx
    movq %rcx,0x58(%rbp)
    movq %rdx,%rcx
    movq 0x58(%rbp),%rdx
    callq *%rax
    leaq 0xd0(%rbp),%rax
    addq $0x10,%rax
    movq $0x0,(%rax)
    leaq 0xd0(%rbp),%rax
    addq $0x8,%rax
    movq $0x6,(%rax)
    leaq 0xd0(%rbp),%rax
    addq $0x30,%rax
    movq $0x0,(%rax)
    movq $0x1,0x40(%rbp)
    movq $0xffffffffffffffff,0x48(%rbp)
    movq 0x2c8(%rbp),%rax
    movq 0x258(%rbp),%rdx
    movq 0x260(%rbp),%rcx
    leaq 0x48(%rbp),%rbx
    leaq 0x40(%rbp),%rsi
    movq 0x270(%rbp),%rdi
    movq %rdi,0x20(%rsp)
    movq 0x2b0(%rbp),%rdi
    movq %rdi,0x28(%rsp)
    movq 0x2a8(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movq 0x2b8(%rbp),%rdi
    movq %rdi,0x38(%rsp)
    leaq 0x80(%rbp),%rdi
    movq %rdi,0x40(%rsp)
    leaq 0xd0(%rbp),%rdi
    movq %rdi,0x48(%rsp)
    movq 0x2c0(%rbp),%rdi
    movq %rdi,0x50(%rsp)
    movq 0x250(%rbp),%rdi
    movq %rdi,0x58(%rsp)
    leaq 0x170(%rbp),%rdi
    movq %rdi,0x60(%rsp)
    movq 0x2a0(%rbp),%rdi
    movq %rdi,0x68(%rsp)
    movq 0x298(%rbp),%rdi
    movq %rdi,0x70(%rsp)
    leaq 0x190(%rbp),%rdi
    movq %rdi,0x78(%rsp)
    movq %rcx,0x60(%rbp)
    movq %rdx,%rcx
    movq 0x60(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movsd coff_ref..rdata+(_2il0floatpacket.1-.Lbase_rdata)(%rip),%xmm0
    movq 0x38(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x250(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd %xmm0,(%rax)
.Ltext_237d:
    movq 0x68(%rbp),%rbx
    movq 0x70(%rbp),%rsi
    movq 0x78(%rbp),%rdi
    leaq 0x230(%rbp),%rsp
    popq %rbp
    retq

    .globl IJ_PRODUCT
IJ_PRODUCT:
.Lend_Z_BASIS:
    pushq %rbp
.Ltext_2393:
    subq $0x60,%rsp
.Ltext_2397:
    leaq 0x20(%rsp),%rbp
.Ltext_239c:
    movq %rcx,0x50(%rbp)
    movq %rdx,0x58(%rbp)
    movq %r8,0x60(%rbp)
    movq %r9,0x68(%rbp)
    movq 0x58(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x60(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    pxor %xmm0,%xmm0
    movsd %xmm0,0x10(%rbp)
    movq 0x60(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq $0x1,0x20(%rbp)
    movq 0x18(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_2484
.Ltext_23eb:
    movq 0x20(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x80(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x28(%rbp)
    movq 0x28(%rbp),%rax
    movq 0x50(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    jne .Ltext_2466
    movq 0x20(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x78(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x30(%rbp)
    movq 0x20(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x70(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm0
    movq 0x30(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x68(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movsd (%rax),%xmm1
    mulsd %xmm1,%xmm0
    movsd 0x10(%rbp),%xmm1
    addsd %xmm0,%xmm1
    movsd %xmm1,0x10(%rbp)
.Ltext_2466:
    movl $0x1,%eax
    addq 0x20(%rbp),%rax
    movq %rax,0x20(%rbp)
    movq 0x20(%rbp),%rax
    movq 0x18(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_23eb
.Ltext_2484:
    movsd 0x10(%rbp),%xmm0
    leaq 0x40(%rbp),%rsp
    popq %rbp
    retq

# Clear the destination and accumulate entries for the selected sparse column.
    .globl FIND_COLUMN
FIND_COLUMN:
.Lend_IJ_PRODUCT:
    pushq %rbp
.Ltext_2490:
    subq $0x50,%rsp
.Ltext_2494:
    leaq 0x20(%rsp),%rbp
.Ltext_2499:
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
    jle .Ltext_2502
.Ltext_24d0:
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
    jle .Ltext_24d0
.Ltext_2502:
    movq 0x70(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq $0x1,0x10(%rbp)
    movq 0x18(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_25be
.Ltext_2522:
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
    jne .Ltext_25a0
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
.Ltext_25a0:
    movl $0x1,%eax
    addq 0x10(%rbp),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    movq 0x18(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_2522
.Ltext_25be:
    leaq 0x30(%rbp),%rsp
    popq %rbp
    retq

# Clear the destination and accumulate entries for the selected sparse row.
    .globl FIND_ROW
FIND_ROW:
.Lend_FIND_COLUMN:
    pushq %rbp
.Ltext_25c5:
    subq $0x50,%rsp
.Ltext_25c9:
    leaq 0x20(%rsp),%rbp
.Ltext_25ce:
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
    jle .Ltext_2637
.Ltext_2605:
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
    jle .Ltext_2605
.Ltext_2637:
    movq 0x70(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x18(%rbp)
    movq $0x1,0x10(%rbp)
    movq 0x18(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_26f3
.Ltext_2657:
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
    jne .Ltext_26d5
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
.Ltext_26d5:
    movl $0x1,%eax
    addq 0x10(%rbp),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    movq 0x18(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_2657
.Ltext_26f3:
    leaq 0x30(%rbp),%rsp
    popq %rbp
    retq

# Move the next nonzero 64-bit entry into each hole; clear its former slot.
    .globl RTPACKVECTOR
RTPACKVECTOR:
.Lend_FIND_ROW:
    pushq %rbp
.Ltext_26fa:
    subq $0x50,%rsp
.Ltext_26fe:
    leaq 0x20(%rsp),%rbp
.Ltext_2703:
    movq %rcx,0x40(%rbp)
    movq %rdx,0x48(%rbp)
    movq 0x48(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} je .Ltext_27fd
    movq 0x48(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq $0x1,0x8(%rbp)
    movq 0x0(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_27fd
.Ltext_273b:
    movq 0x8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x10(%rbp),%rax
    testq %rax,%rax
    {disp32} jne .Ltext_27df
    movl $0x1,%eax
    addq 0x8(%rbp),%rax
    movq %rax,0x18(%rbp)
.Ltext_276c:
    movq 0x18(%rbp),%rax
    movq 0x48(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    {disp32} jg .Ltext_27fd
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq (%rax),%rax
    movq %rax,0x20(%rbp)
    movq 0x20(%rbp),%rax
    testq %rax,%rax
    je .Ltext_27d0
    movq 0x8(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq 0x20(%rbp),%rdx
    movq %rdx,(%rax)
    movq 0x18(%rbp),%rax
    imulq $0x8,%rax,%rax
    addq 0x40(%rbp),%rax
    addq $0xfffffffffffffff8,%rax
    movq $0x0,(%rax)
    jmp .Ltext_27df
.Ltext_27d0:
    movl $0x1,%eax
    addq 0x18(%rbp),%rax
    movq %rax,0x18(%rbp)
    jmp .Ltext_276c
.Ltext_27df:
    movl $0x1,%eax
    addq 0x8(%rbp),%rax
    movq %rax,0x8(%rbp)
    movq 0x8(%rbp),%rax
    movq 0x0(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_273b
.Ltext_27fd:
    leaq 0x30(%rbp),%rsp
    popq %rbp
    retq
.Lend_RTPACKVECTOR:
    nop
coff_end.text:

# @section .xdata 0x40300040
    .section .xdata
.Lbase_xdata:
.Lunwind_CLASSIFY_VARIABLES:
    .byte 1, .Ltext_0020-CLASSIFY_VARIABLES, 10, 0x05  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0020-CLASSIFY_VARIABLES, 0x34  # save rbx
    .short 576/8  # stack bytes in 8-byte units
    .byte .Ltext_0019-CLASSIFY_VARIABLES, 0x64  # save rsi
    .short 584/8  # stack bytes in 8-byte units
    .byte .Ltext_0012-CLASSIFY_VARIABLES, 0x74  # save rdi
    .short 592/8  # stack bytes in 8-byte units
    .byte .Ltext_000b-CLASSIFY_VARIABLES, 0x03  # set frame pointer
    .byte .Ltext_0008-CLASSIFY_VARIABLES, 0x01  # allocate large stack frame
    .short 608/8  # stack bytes in 8-byte units
    .byte .Ltext_0001-CLASSIFY_VARIABLES, 0x50  # push rbp
.Lunwind_SPLIT_THINGS:
    .byte 1, .Ltext_0dd3-SPLIT_THINGS, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0dd3-SPLIT_THINGS, 0x03  # set frame pointer
    .byte .Ltext_0dce-SPLIT_THINGS, 0xb2  # allocate 96 stack bytes
    .byte .Ltext_0dca-SPLIT_THINGS, 0x50  # push rbp
    .short 0  # unwind slot padding
.Lunwind_OBSERVABILITY:
    .byte 1, .Ltext_1131-OBSERVABILITY, 10, 0x85  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_1131-OBSERVABILITY, 0x34  # save rbx
    .short 336/8  # stack bytes in 8-byte units
    .byte .Ltext_112a-OBSERVABILITY, 0x64  # save rsi
    .short 344/8  # stack bytes in 8-byte units
    .byte .Ltext_1123-OBSERVABILITY, 0x74  # save rdi
    .short 352/8  # stack bytes in 8-byte units
    .byte .Ltext_111c-OBSERVABILITY, 0x03  # set frame pointer
    .byte .Ltext_1114-OBSERVABILITY, 0x01  # allocate large stack frame
    .short 880/8  # stack bytes in 8-byte units
    .byte .Ltext_110d-OBSERVABILITY, 0x50  # push rbp
.Lunwind_REDUNDANCY:
    .byte 1, .Ltext_1bba-REDUNDANCY, 8, 0xa5  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_1bba-REDUNDANCY, 0x34  # save rbx
    .short 304/8  # stack bytes in 8-byte units
    .byte .Ltext_1bb3-REDUNDANCY, 0x64  # save rsi
    .short 312/8  # stack bytes in 8-byte units
    .byte .Ltext_1bac-REDUNDANCY, 0x03  # set frame pointer
    .byte .Ltext_1ba4-REDUNDANCY, 0x01  # allocate large stack frame
    .short 320/8  # stack bytes in 8-byte units
    .byte .Ltext_1b9d-REDUNDANCY, 0x50  # push rbp
.Lunwind_Z_BASIS:
    .byte 1, .Ltext_20af-Z_BASIS, 10, 0x85  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_20af-Z_BASIS, 0x34  # save rbx
    .short 232/8  # stack bytes in 8-byte units
    .byte .Ltext_20ab-Z_BASIS, 0x64  # save rsi
    .short 240/8  # stack bytes in 8-byte units
    .byte .Ltext_20a7-Z_BASIS, 0x74  # save rdi
    .short 248/8  # stack bytes in 8-byte units
    .byte .Ltext_20a3-Z_BASIS, 0x03  # set frame pointer
    .byte .Ltext_209b-Z_BASIS, 0x01  # allocate large stack frame
    .short 688/8  # stack bytes in 8-byte units
    .byte .Ltext_2094-Z_BASIS, 0x50  # push rbp
.Lunwind_IJ_PRODUCT:
    .byte 1, .Ltext_239c-IJ_PRODUCT, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_239c-IJ_PRODUCT, 0x03  # set frame pointer
    .byte .Ltext_2397-IJ_PRODUCT, 0xb2  # allocate 96 stack bytes
    .byte .Ltext_2393-IJ_PRODUCT, 0x50  # push rbp
    .short 0  # unwind slot padding
.Lunwind_FIND_COLUMN:
    .byte 1, .Ltext_2499-FIND_COLUMN, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_2499-FIND_COLUMN, 0x03  # set frame pointer
    .byte .Ltext_2494-FIND_COLUMN, 0x92  # allocate 80 stack bytes
    .byte .Ltext_2490-FIND_COLUMN, 0x50  # push rbp
    .short 0  # unwind slot padding
.Lunwind_FIND_ROW:
    .byte 1, .Ltext_25ce-FIND_ROW, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_25ce-FIND_ROW, 0x03  # set frame pointer
    .byte .Ltext_25c9-FIND_ROW, 0x92  # allocate 80 stack bytes
    .byte .Ltext_25c5-FIND_ROW, 0x50  # push rbp
    .short 0  # unwind slot padding
.Lunwind_RTPACKVECTOR:
    .byte 1, .Ltext_2703-RTPACKVECTOR, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_2703-RTPACKVECTOR, 0x03  # set frame pointer
    .byte .Ltext_26fe-RTPACKVECTOR, 0x92  # allocate 80 stack bytes
    .byte .Ltext_26fa-RTPACKVECTOR, 0x50  # push rbp
    .short 0  # unwind slot padding
coff_end.xdata:

# @section .pdata 0x40300040
    .section .pdata
.Lbase_pdata:
    .long coff_rva.CLASSIFY_VARIABLES
    .long coff_rva.CLASSIFY_VARIABLES+(.Lend_CLASSIFY_VARIABLES-CLASSIFY_VARIABLES)
    .long coff_rva..xdata+(.Lunwind_CLASSIFY_VARIABLES-.Lbase_xdata)
    .long coff_rva.SPLIT_THINGS
    .long coff_rva.SPLIT_THINGS+(.Lend_SPLIT_THINGS-SPLIT_THINGS)
    .long coff_rva..xdata+(.Lunwind_SPLIT_THINGS-.Lbase_xdata)
    .long coff_rva.OBSERVABILITY
    .long coff_rva.OBSERVABILITY+(.Lend_OBSERVABILITY-OBSERVABILITY)
    .long coff_rva..xdata+(.Lunwind_OBSERVABILITY-.Lbase_xdata)
    .long coff_rva.REDUNDANCY
    .long coff_rva.REDUNDANCY+(.Lend_REDUNDANCY-REDUNDANCY)
    .long coff_rva..xdata+(.Lunwind_REDUNDANCY-.Lbase_xdata)
    .long coff_rva.Z_BASIS
    .long coff_rva.Z_BASIS+(.Lend_Z_BASIS-Z_BASIS)
    .long coff_rva..xdata+(.Lunwind_Z_BASIS-.Lbase_xdata)
    .long coff_rva.IJ_PRODUCT
    .long coff_rva.IJ_PRODUCT+(.Lend_IJ_PRODUCT-IJ_PRODUCT)
    .long coff_rva..xdata+(.Lunwind_IJ_PRODUCT-.Lbase_xdata)
    .long coff_rva.FIND_COLUMN
    .long coff_rva.FIND_COLUMN+(.Lend_FIND_COLUMN-FIND_COLUMN)
    .long coff_rva..xdata+(.Lunwind_FIND_COLUMN-.Lbase_xdata)
    .long coff_rva.FIND_ROW
    .long coff_rva.FIND_ROW+(.Lend_FIND_ROW-FIND_ROW)
    .long coff_rva..xdata+(.Lunwind_FIND_ROW-.Lbase_xdata)
    .long coff_rva.RTPACKVECTOR
    .long coff_rva.RTPACKVECTOR+(.Lend_RTPACKVECTOR-RTPACKVECTOR)
    .long coff_rva..xdata+(.Lunwind_RTPACKVECTOR-.Lbase_xdata)
coff_end.pdata:

# @section .rdata 0x40500040
    .section .rdata
.Lbase_rdata:
_2il0floatpacket.0:
    .quad 0x7fffffffffffffff, 0x0  # IEEE / SIMD bit pattern
_2il0floatpacket.1:
    .quad 0xbff0000000000000, 0x0  # IEEE / SIMD bit pattern
coff_end.rdata:

# @section .drectve 0x100a00
    .section .drectve
.Lbase_drectve:
    .ascii "-export:CLASSIFY_VARIABLES  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "
coff_end.drectve:
