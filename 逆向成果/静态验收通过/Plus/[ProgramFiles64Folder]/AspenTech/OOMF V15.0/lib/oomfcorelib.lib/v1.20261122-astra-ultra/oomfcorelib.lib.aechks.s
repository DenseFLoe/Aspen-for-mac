# @member x64\Release\aechks.obj 1743626480
# Windows AMD64 COFF. GNU as / AT&T syntax. Tables below preserve link and unwind contracts.

# @symbol section .text
# @symbol function USR3_AECHKS
# @symbol section .rdata
# @symbol local __STRLITPACK_0
# @symbol external_data __imp_OOMF_PLEX
# @symbol external_function U3MAP_REL_INCIDENCE
# @symbol external_function U3PERM_EQN_CREATE_INCIDENCE
# @symbol external_function RTO_IFREE
# @symbol external_function U3MAP_VAR_INCIDENCE
# @symbol external_function U3PERM_VAR_CREATE_INCIDENCE
# @symbol external_function U3PERM_JAC_CREATE_INCIDENCE
# @symbol external_function U3PERM_JAC_COPY_APPLY_ROW
# @symbol external_function U3PERM_JAC_COPY_APPLY_COL
# @symbol external_function SLATEC_ISORT
# @symbol external_function RTO_IMALLOC
# @symbol external_function U3RINC
# @symbol external_function U3RGMT
# @symbol external_function U3PERM_COMP2UNCOMP
# @symbol external_function for_write_seq_lis
# @symbol external_function U3PERM_DESTROY
# @symbol section .xdata
# @symbol section .pdata
# @symbol local __NLITPACK_0
# @symbol local __STRLITPACK_1
# @symbol common OOMF_PLEX 128
# @symbol section .drectve
# @symbol external_function __ImageBase


# @section .text 0x60300020
    .section .text
.Lbase_text:

# Map row and variable incidences, apply permutations, and release the work vectors.
    .globl USR3_AECHKS
USR3_AECHKS:
    pushq %rbp
.Ltext_0001:
    subq $0x240,%rsp
.Ltext_0008:
    leaq 0x50(%rsp),%rbp
.Ltext_000d:
    movq %rdi,0x1e0(%rbp)
.Ltext_0014:
    movq %rsi,0x1d8(%rbp)
.Ltext_001b:
    movq %rbx,0x1d0(%rbp)
.Ltext_0022:
    movq %rcx,0x200(%rbp)
    movq %rdx,0x208(%rbp)
    movq %r8,0x210(%rbp)
    movq %r9,0x218(%rbp)
    movq 0x200(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x0(%rbp)
    movq 0x210(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x8(%rbp)
    movq 0x220(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x10(%rbp)
    movq 0x238(%rbp),%rax
    movq $0xffffffffffffffff,(%rax)
    movq 0x240(%rbp),%rax
    movq $0xffffffffffffffff,(%rax)
    movq 0x248(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x210(%rbp),%rax
    movq 0x208(%rbp),%rdx
    movq 0x228(%rbp),%rcx
    movq 0x230(%rbp),%rbx
    movq 0x220(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    leaq 0x18(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq %rcx,0x180(%rbp)
    movq %rax,%rcx
    movq 0x180(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3MAP_REL_INCIDENCE
    movq 0x218(%rbp),%rax
    movq 0x210(%rbp),%rdx
    leaq 0x18(%rbp),%rcx
    leaq 0x20(%rbp),%rbx
    leaq 0x28(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0x188(%rbp)
    movq %rax,%rcx
    movq 0x188(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3PERM_EQN_CREATE_INCIDENCE
    movq 0x28(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_0134
    leaq 0x18(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    {disp32} jmp .Ltext_0b9c
.Ltext_0134:
    movq 0x200(%rbp),%rax
    movq 0x218(%rbp),%rdx
    movq 0x228(%rbp),%rcx
    movq 0x230(%rbp),%rbx
    movq 0x220(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    leaq 0x30(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq %rcx,0x190(%rbp)
    movq %rax,%rcx
    movq 0x190(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3MAP_VAR_INCIDENCE
    movq 0x208(%rbp),%rax
    movq 0x200(%rbp),%rdx
    leaq 0x30(%rbp),%rcx
    leaq 0x38(%rbp),%rbx
    leaq 0x40(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0x198(%rbp)
    movq %rax,%rcx
    movq 0x198(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3PERM_VAR_CREATE_INCIDENCE
    movq 0x40(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_01d6
    leaq 0x30(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    {disp32} jmp .Ltext_0b9c
.Ltext_01d6:
    movq 0x218(%rbp),%rax
    movq 0x208(%rbp),%rdx
    leaq 0x30(%rbp),%rcx
    leaq 0x18(%rbp),%rbx
    movq 0x228(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq 0x230(%rbp),%rsi
    movq %rsi,0x28(%rsp)
    movq 0x220(%rbp),%rsi
    movq %rsi,0x30(%rsp)
    leaq 0x48(%rbp),%rsi
    movq %rsi,0x38(%rsp)
    leaq 0x50(%rbp),%rsi
    movq %rsi,0x40(%rsp)
    movq %rcx,0x1a0(%rbp)
    movq %rax,%rcx
    movq 0x1a0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3PERM_JAC_CREATE_INCIDENCE
    movq 0x50(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_0264
    leaq 0x30(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0x18(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    {disp32} jmp .Ltext_0b9c
.Ltext_0264:
    leaq 0x48(%rbp),%rax
    leaq 0x20(%rbp),%rdx
    movq 0x228(%rbp),%rcx
    leaq 0x58(%rbp),%rbx
    movq %rcx,0x1a8(%rbp)
    movq %rax,%rcx
    movq 0x1a8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3PERM_JAC_COPY_APPLY_ROW
    leaq 0x48(%rbp),%rax
    leaq 0x38(%rbp),%rdx
    movq 0x230(%rbp),%rcx
    leaq 0x60(%rbp),%rbx
    movq %rcx,0x1b0(%rbp)
    movq %rax,%rcx
    movq 0x1b0(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq U3PERM_JAC_COPY_APPLY_COL
    movl $0x8,%eax
    negq %rax
    movq 0x58(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    movq __imp_OOMF_PLEX(%rip),%rcx
    addq.s %rdx,%rcx
    addq.s %rcx,%rax
    movl $0x8,%edx
    negq %rdx
    movq 0x60(%rbp),%rcx
    imulq $0x8,%rcx,%rcx
    movq __imp_OOMF_PLEX(%rip),%rbx
    addq.s %rcx,%rbx
    addq.s %rbx,%rdx
    leaq 0x50(%rbp),%rcx
    leaq coff_ref..rdata+(__NLITPACK_0-.Lbase_rdata)(%rip),%rbx
    movq %rcx,0x1b8(%rbp)
    movq %rax,%rcx
    movq 0x1b8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq SLATEC_ISORT
    movq 0x28(%rbp),%rax
    movq 0x40(%rbp),%rdx
    cmpq.s %rdx,%rax
    jge .Ltext_033a
    movq 0x40(%rbp),%rax
    movq %rax,0x68(%rbp)
    jmp .Ltext_0342
.Ltext_033a:
    movq 0x28(%rbp),%rax
    movq %rax,0x68(%rbp)
.Ltext_0342:
    movq 0x68(%rbp),%rax
    movq %rax,0x70(%rbp)
    leaq 0x70(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IMALLOC
    movq %rax,0x78(%rbp)
    movq 0x78(%rbp),%rax
    movq %rax,0x80(%rbp)
    leaq 0x70(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IMALLOC
    movq %rax,0x88(%rbp)
    movq 0x88(%rbp),%rax
    movq %rax,0x90(%rbp)
    movq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq $0x1,(%rdx)
    movq $0x1,0x98(%rbp)
    movq 0x50(%rbp),%rax
    movq %rax,0xa0(%rbp)
    movq $0x2,0xa8(%rbp)
    movq 0xa0(%rbp),%rax
    cmpq $0x2,%rax
    {disp32} jl .Ltext_04f0
.Ltext_03d8:
    movq $0xffffffffffffffff,%rax
    addq 0x58(%rbp),%rax
    addq 0xa8(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rdx),%rax
    movq 0x98(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_04c6
    movq 0x98(%rbp),%rax
    addq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq 0xa8(%rbp),%rax
    movq %rax,(%rdx)
    movq 0x98(%rbp),%rax
    addq 0x90(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq $0xffffffffffffffff,%rax
    addq 0x90(%rbp),%rax
    addq 0x98(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rcx
    addq.s %rax,%rcx
    addq $0xfffffffffffffff8,%rcx
    movq (%rcx),%rax
    negq %rax
    addq (%rdx),%rax
    movq $0xffffffffffffffff,%rdx
    addq 0x80(%rbp),%rdx
    addq 0x98(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    movq __imp_OOMF_PLEX(%rip),%rcx
    addq.s %rdx,%rcx
    addq $0xfffffffffffffff8,%rcx
    movq %rax,(%rcx)
    movl $0x1,%eax
    addq 0x98(%rbp),%rax
    movq %rax,0x98(%rbp)
.Ltext_04c6:
    movl $0x1,%eax
    addq 0xa8(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq 0xa8(%rbp),%rax
    movq 0xa0(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_03d8
.Ltext_04f0:
    movl $0x1,%eax
    addq 0x50(%rbp),%rax
    movq 0x28(%rbp),%rdx
    addq 0x90(%rbp),%rdx
    decq %rdx
    imulq $0x8,%rdx,%rdx
    movq __imp_OOMF_PLEX(%rip),%rcx
    addq.s %rdx,%rcx
    addq $0xfffffffffffffff8,%rcx
    movq (%rcx),%rdx
    negq %rdx
    addq.s %rdx,%rax
    movq 0x28(%rbp),%rdx
    addq 0x80(%rbp),%rdx
    decq %rdx
    imulq $0x8,%rdx,%rdx
    movq __imp_OOMF_PLEX(%rip),%rcx
    addq.s %rdx,%rcx
    addq $0xfffffffffffffff8,%rcx
    movq %rax,(%rcx)
    movq 0x70(%rbp),%rax
    movq %rax,0xb0(%rbp)
    movl $0x1,%eax
    addq 0x28(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq 0xb0(%rbp),%rax
    movl $0x1,%edx
    addq 0x28(%rbp),%rdx
    cmpq.s %rdx,%rax
    jl .Ltext_05c5
.Ltext_0575:
    movq 0xa8(%rbp),%rax
    addq 0x80(%rbp),%rax
    decq %rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq $0x0,(%rdx)
    movl $0x1,%eax
    addq 0xa8(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq 0xa8(%rbp),%rax
    movq 0xb0(%rbp),%rdx
    cmpq.s %rdx,%rax
    jle .Ltext_0575
.Ltext_05c5:
    movq 0x70(%rbp),%rax
    imulq $0x5,%rax,%rax
    movq %rax,0xb8(%rbp)
    leaq 0xb8(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IMALLOC
    movq %rax,0xc0(%rbp)
    movq 0xc0(%rbp),%rax
    movq %rax,0xc8(%rbp)
    leaq 0x70(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IMALLOC
    movq %rax,0xd0(%rbp)
    movq 0xd0(%rbp),%rax
    movq %rax,0xd8(%rbp)
    movq 0x250(%rbp),%rax
    leaq 0x70(%rbp),%rdx
    movl $0x8,%ecx
    negq %rcx
    movq 0x60(%rbp),%rbx
    imulq $0x8,%rbx,%rbx
    movq __imp_OOMF_PLEX(%rip),%rsi
    addq.s %rbx,%rsi
    addq.s %rsi,%rcx
    leaq 0x50(%rbp),%rbx
    movl $0x8,%esi
    negq %rsi
    movq 0x90(%rbp),%rdi
    imulq $0x8,%rdi,%rdi
    movq __imp_OOMF_PLEX(%rip),%r8
    addq.s %rdi,%r8
    addq.s %r8,%rsi
    movl $0x8,%edi
    negq %rdi
    movq 0x80(%rbp),%r8
    imulq $0x8,%r8,%r8
    movq __imp_OOMF_PLEX(%rip),%r9
    addq.s %r8,%r9
    addq.s %r9,%rdi
    movq %rdi,0x20(%rsp)
    movl $0x8,%edi
    negq %rdi
    movq 0xd8(%rbp),%r8
    imulq $0x8,%r8,%r8
    movq __imp_OOMF_PLEX(%rip),%r9
    addq.s %r8,%r9
    addq.s %r9,%rdi
    movq %rdi,0x28(%rsp)
    leaq 0xe0(%rbp),%rdi
    movq %rdi,0x30(%rsp)
    movl $0x8,%edi
    negq %rdi
    movq 0xc8(%rbp),%r8
    imulq $0x8,%r8,%r8
    movq __imp_OOMF_PLEX(%rip),%r9
    addq.s %r8,%r9
    addq.s %r9,%rdi
    movq %rdi,0x38(%rsp)
    movq %rcx,0x1c0(%rbp)
    movq %rdx,%rcx
    movq 0x1c0(%rbp),%rdx
    movq %rbx,%r8
    movq %rsi,%r9
    callq *%rax
    movq 0x238(%rbp),%rax
    movq $0x0,(%rax)
    movq 0x210(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0xe8(%rbp)
    movq $0x1,0xa8(%rbp)
    movq 0xe8(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_07f5
.Ltext_0733:
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0xa8(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x218(%rbp),%rdx
    addq.s %rdx,%rax
    movq %rax,%rcx
    callq U3RINC
    movq %rax,0xf0(%rbp)
    jmp .Ltext_077f
.Ltext_0766:
    movl 0xf0(%rbp),%eax
    testb $0x1,%al
    je .Ltext_07cb
    movq 0x100(%rbp),%rax
    cmpq $0x5,%rax
    jne .Ltext_07b2
    jmp .Ltext_07cb
.Ltext_077f:
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0xa8(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x218(%rbp),%rdx
    addq.s %rdx,%rax
    movq %rax,%rcx
    callq U3RGMT
    movq %rax,0x100(%rbp)
    jmp .Ltext_0766
.Ltext_07b2:
    movq 0x238(%rbp),%rax
    movl $0x1,%edx
    addq (%rax),%rdx
    movq 0x238(%rbp),%rax
    movq %rdx,(%rax)
.Ltext_07cb:
    movl $0x1,%eax
    addq 0xa8(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq 0xa8(%rbp),%rax
    movq 0xe8(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_0733
.Ltext_07f5:
    movq 0x238(%rbp),%rax
    movq 0xe0(%rbp),%rdx
    negq %rdx
    addq (%rax),%rdx
    movq 0x238(%rbp),%rax
    movq %rdx,(%rax)
    movq 0xe0(%rbp),%rax
    negq %rax
    addq 0x40(%rbp),%rax
    movq 0x240(%rbp),%rdx
    movq %rax,(%rdx)
    movq 0x238(%rbp),%rax
    movq (%rax),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0b0c
    movq 0x238(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IMALLOC
    movq %rax,0xf8(%rbp)
    movq 0x248(%rbp),%rax
    movq 0xf8(%rbp),%rdx
    movq %rdx,(%rax)
    movq $0x0,0x108(%rbp)
    movq 0xe0(%rbp),%rax
    movq 0x70(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} je .Ltext_0982
    movq $0xffffffffffffffff,%rax
    addq 0x28(%rbp),%rax
    movq %rax,0x110(%rbp)
    movq $0x0,0xa8(%rbp)
    movq 0x110(%rbp),%rax
    testq %rax,%rax
    {disp32} jl .Ltext_0982
.Ltext_08b1:
    movq 0x70(%rbp),%rax
    addq 0xc8(%rbp),%rax
    addq 0xa8(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rdx),%rax
    movq %rax,0x98(%rbp)
    movq 0x98(%rbp),%rax
    testq %rax,%rax
    jne .Ltext_0958
    movl $0x1,%eax
    addq 0xa8(%rbp),%rax
    movq %rax,0x130(%rbp)
    leaq 0x20(%rbp),%rax
    leaq 0x130(%rbp),%rdx
    movq %rax,%rcx
    callq U3PERM_COMP2UNCOMP
    movq %rax,0x138(%rbp)
    movq 0x248(%rbp),%rax
    movq 0x108(%rbp),%rdx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq 0x138(%rbp),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x108(%rbp),%rax
    movq %rax,0x108(%rbp)
.Ltext_0958:
    movl $0x1,%eax
    addq 0xa8(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq 0xa8(%rbp),%rax
    movq 0x110(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_08b1
.Ltext_0982:
    movq $0xffffffffffffffff,%rax
    addq 0x18(%rbp),%rax
    movq %rax,0x118(%rbp)
    movq 0x210(%rbp),%rax
    movq (%rax),%rax
    movq %rax,0x120(%rbp)
    movq $0x1,0xa8(%rbp)
    movq 0x120(%rbp),%rax
    testq %rax,%rax
    {disp32} jle .Ltext_0a8d
.Ltext_09c0:
    movl $0x0,%eax
    movl $0x8,%edx
    subq.s %rdx,%rax
    movq 0xa8(%rbp),%rdx
    imulq $0x8,%rdx,%rdx
    addq 0x218(%rbp),%rdx
    addq.s %rdx,%rax
    movq %rax,%rcx
    callq U3RINC
    movq %rax,0x128(%rbp)
    movl 0x128(%rbp),%eax
    testb $0x1,%al
    je .Ltext_0a63
    movq 0xa8(%rbp),%rax
    addq 0x118(%rbp),%rax
    imulq $0x8,%rax,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq (%rdx),%rax
    testq %rax,%rax
    jne .Ltext_0a63
    movq 0x248(%rbp),%rax
    movq 0x108(%rbp),%rdx
    addq (%rax),%rdx
    imulq $0x8,%rdx,%rax
    movq __imp_OOMF_PLEX(%rip),%rdx
    addq.s %rax,%rdx
    addq $0xfffffffffffffff8,%rdx
    movq 0xa8(%rbp),%rax
    movq %rax,(%rdx)
    movl $0x1,%eax
    addq 0x108(%rbp),%rax
    movq %rax,0x108(%rbp)
.Ltext_0a63:
    movl $0x1,%eax
    addq 0xa8(%rbp),%rax
    movq %rax,0xa8(%rbp)
    movq 0xa8(%rbp),%rax
    movq 0x120(%rbp),%rdx
    cmpq.s %rdx,%rax
    {disp32} jle .Ltext_09c0
.Ltext_0a8d:
    movq 0x108(%rbp),%rax
    movq 0x238(%rbp),%rdx
    movq (%rdx),%rdx
    cmpq.s %rdx,%rax
    je .Ltext_0b0c
    movq $0x0,0x140(%rbp)
    movq $0x1b,0x170(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_0-.Lbase_rdata)(%rip),%rax
    movq %rax,0x178(%rbp)
    leaq 0x140(%rbp),%rax
    movl $0xffffffff,%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_1-.Lbase_rdata)(%rip),%rbx
    leaq 0x170(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0x1c8(%rbp)
    movq %rax,%rcx
    movq 0x1c8(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_write_seq_lis
.Ltext_0b0c:
    leaq 0x30(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0x18(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0x20(%rbp),%rax
    movq %rax,%rcx
    callq U3PERM_DESTROY
    leaq 0x38(%rbp),%rax
    movq %rax,%rcx
    callq U3PERM_DESTROY
    leaq 0x48(%rbp),%rax
    movq %rax,%rcx
    callq U3PERM_DESTROY
    leaq 0x58(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0x60(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0xc8(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0x90(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0x80(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
    leaq 0xd8(%rbp),%rax
    movq %rax,%rcx
    callq RTO_IFREE
.Ltext_0b9c:
    movq 0x1d0(%rbp),%rbx
    movq 0x1d8(%rbp),%rsi
    movq 0x1e0(%rbp),%rdi
    leaq 0x1f0(%rbp),%rsp
    popq %rbp
    retq
.Lend_USR3_AECHKS:
    nop
    nop
coff_end.text:

# @section .rdata 0x40400040
    .section .rdata
.Lbase_rdata:
__STRLITPACK_0:
    .ascii "BAD PROBLEM IN DOF ANALYSIS"
    .zero 5
__NLITPACK_0:
    .byte 0x02
    .zero 7
__STRLITPACK_1:
    .byte 0x38, 0x04, 0x01
    .zero 5
coff_end.rdata:

# @section .xdata 0x40300040
    .section .xdata
.Lbase_xdata:
.Lunwind_USR3_AECHKS:
    .byte 1, .Ltext_0022-USR3_AECHKS, 10, 0x55  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0022-USR3_AECHKS, 0x34  # save rbx
    .short 544/8  # stack bytes in 8-byte units
    .byte .Ltext_001b-USR3_AECHKS, 0x64  # save rsi
    .short 552/8  # stack bytes in 8-byte units
    .byte .Ltext_0014-USR3_AECHKS, 0x74  # save rdi
    .short 560/8  # stack bytes in 8-byte units
    .byte .Ltext_000d-USR3_AECHKS, 0x03  # set frame pointer
    .byte .Ltext_0008-USR3_AECHKS, 0x01  # allocate large stack frame
    .short 576/8  # stack bytes in 8-byte units
    .byte .Ltext_0001-USR3_AECHKS, 0x50  # push rbp
coff_end.xdata:

# @section .pdata 0x40300040
    .section .pdata
.Lbase_pdata:
    .long coff_rva.USR3_AECHKS
    .long coff_rva.USR3_AECHKS+(.Lend_USR3_AECHKS-USR3_AECHKS)
    .long coff_rva..xdata+(.Lunwind_USR3_AECHKS-.Lbase_xdata)
coff_end.pdata:

# @section .drectve 0x100a00
    .section .drectve
.Lbase_drectve:
    .ascii "-export:USR3_AECHKS  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "
coff_end.drectve:
