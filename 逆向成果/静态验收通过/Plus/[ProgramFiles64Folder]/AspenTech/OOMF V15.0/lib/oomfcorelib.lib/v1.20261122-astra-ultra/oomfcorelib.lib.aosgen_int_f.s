# @member x64\Release\aosgen_int_f.obj 1743626478
# Windows AMD64 COFF. GNU as / AT&T syntax. Tables below preserve link and unwind contracts.

# @symbol section .text
# @symbol function GENSOLV_FOPEN
# @symbol function GENSOLV_FCLOSE
# @symbol function SET_GLOBAL_COMMONS
# @symbol section .rdata
# @symbol local __STRLITPACK_0
# @symbol external_function for_open
# @symbol section .xdata
# @symbol section .pdata
# @symbol local __STRLITPACK_1
# @symbol external_function for_close
# @symbol local __STRLITPACK_2
# @symbol local _2il0floatpacket.0
# @symbol local _2il0floatpacket.1
# @symbol external_data __imp_OOMF_GLOBAL
# @symbol external_data __imp_OOMF_RGLOB
# @symbol common OOMF_GLOBAL 32
# @symbol common OOMF_RGLOB 32
# @symbol section .drectve
# @symbol external_function __ImageBase
# @symbol external_data _fltused


# @section .text 0x60300020
    .section .text
.Lbase_text:

# Pass REPLACE and the original descriptors to for_open. Store -1 if its status is positive.
    .globl GENSOLV_FOPEN
GENSOLV_FOPEN:
    pushq %rbp
.Ltext_0001:
    subq $0xa0,%rsp
.Ltext_0008:
    leaq 0x30(%rsp),%rbp
.Ltext_000d:
    movq %rsi,0x68(%rbp)
.Ltext_0011:
    movq %rbx,0x60(%rbp)
.Ltext_0015:
    movq %rcx,0x80(%rbp)
    movq %rdx,0x88(%rbp)
    movq %r8,0x90(%rbp)
    movq %r9,0x98(%rbp)
    movq 0x90(%rbp),%rax
    movq $0x0,(%rax)
    movq $0x0,0x8(%rbp)
    movq $0xff,0x38(%rbp)
    movq 0x88(%rbp),%rax
    movq %rax,0x40(%rbp)
    movq $0x7,0x48(%rbp)
    leaq coff_ref..rdata+(__STRLITPACK_0-.Lbase_rdata)(%rip),%rax
    movq %rax,0x50(%rbp)
    leaq 0x8(%rbp),%rax
    movq 0x80(%rbp),%rdx
    movl (%rdx),%edx
    movabsq $0x801208384ff01,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_1-.Lbase_rdata)(%rip),%rbx
    leaq 0x38(%rbp),%rsi
    movq %rsi,0x20(%rsp)
    movq %rcx,0x58(%rbp)
    movq %rax,%rcx
    movq 0x58(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_open
    movl %eax,0x0(%rbp)
    movl 0x0(%rbp),%eax
    movl %eax,0x4(%rbp)
    movl 0x4(%rbp),%eax
    testl %eax,%eax
    jle .Ltext_00c8
    movq 0x90(%rbp),%rax
    movq $0xffffffffffffffff,(%rax)
.Ltext_00c8:
    movq 0x60(%rbp),%rbx
    movq 0x68(%rbp),%rsi
    leaq 0x70(%rbp),%rsp
    popq %rbp
    retq

# Read the unit by reference and call for_close with its original descriptor and fifth argument.
    .globl GENSOLV_FCLOSE
GENSOLV_FCLOSE:
.Lend_GENSOLV_FOPEN:
    pushq %rbp
.Ltext_00d7:
    subq $0x70,%rsp
.Ltext_00db:
    leaq 0x30(%rsp),%rbp
.Ltext_00e0:
    movq %rbx,0x38(%rbp)
.Ltext_00e4:
    movq %rcx,0x50(%rbp)
    movq $0x0,0x0(%rbp)
    leaq 0x0(%rbp),%rax
    movq 0x50(%rbp),%rdx
    movl (%rdx),%edx
    movabsq $0x801208384ff00,%rcx
    leaq coff_ref..rdata+(__STRLITPACK_2-.Lbase_rdata)(%rip),%rbx
    movq $0x0,0x20(%rsp)
    movq %rcx,0x30(%rbp)
    movq %rax,%rcx
    movq 0x30(%rbp),%rax
    movq %rax,%r8
    movq %rbx,%r9
    callq for_close
    movq 0x38(%rbp),%rbx
    leaq 0x40(%rbp),%rsp
    popq %rbp
    retq

# Compare the imported double, explicitly skip unordered results, then check the signed integer limit.
    .globl SET_GLOBAL_COMMONS
SET_GLOBAL_COMMONS:
.Lend_GENSOLV_FCLOSE:
    pushq %rbp
.Ltext_0135:
    subq $0x20,%rsp
.Ltext_0139:
    leaq 0x20(%rsp),%rbp
.Ltext_013e:
    movq __imp_OOMF_RGLOB(%rip),%rax
    movsd (%rax),%xmm0
    movsd coff_ref..rdata+(_2il0floatpacket.0-.Lbase_rdata)(%rip),%xmm1
    comisd %xmm1,%xmm0
    jae .Ltext_016c
    jp .Ltext_016c
    movsd coff_ref..rdata+(_2il0floatpacket.1-.Lbase_rdata)(%rip),%xmm0
    movq __imp_OOMF_RGLOB(%rip),%rax
    movsd %xmm0,(%rax)
.Ltext_016c:
    movq __imp_OOMF_GLOBAL(%rip),%rax
    movq (%rax),%rax
    cmpq $0x5f5e0ff,%rax
    jge .Ltext_018c
    movq __imp_OOMF_GLOBAL(%rip),%rax
    movq $0x5f5e0ff,(%rax)
.Ltext_018c:
    leaq 0x0(%rbp),%rsp
    popq %rbp
    retq
.Lend_SET_GLOBAL_COMMONS:
    nop
    nop
coff_end.text:

# @section .rdata 0x40400040
    .section .rdata
.Lbase_rdata:
__STRLITPACK_0:
    .ascii "REPLACE"
    .zero 1
__STRLITPACK_1:
    .byte 0x38, 0x04, 0x0d
    .zero 1
    .byte 0x38, 0x04, 0x1a
    .zero 1
    .byte 0x01
    .zero 7
__STRLITPACK_2:
    .byte 0x01
    .zero 3
    .byte 0x38
    .zero 3
_2il0floatpacket.0:
    .quad 0x46293e5940000000  # IEEE / SIMD bit pattern
_2il0floatpacket.1:
    .quad 0x4733426180000000  # IEEE / SIMD bit pattern
coff_end.rdata:

# @section .xdata 0x40300040
    .section .xdata
.Lbase_xdata:
.Lunwind_GENSOLV_FOPEN:
    .byte 1, .Ltext_0015-GENSOLV_FOPEN, 8, 0x35  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_0015-GENSOLV_FOPEN, 0x34  # save rbx
    .short 144/8  # stack bytes in 8-byte units
    .byte .Ltext_0011-GENSOLV_FOPEN, 0x64  # save rsi
    .short 152/8  # stack bytes in 8-byte units
    .byte .Ltext_000d-GENSOLV_FOPEN, 0x03  # set frame pointer
    .byte .Ltext_0008-GENSOLV_FOPEN, 0x01  # allocate large stack frame
    .short 160/8  # stack bytes in 8-byte units
    .byte .Ltext_0001-GENSOLV_FOPEN, 0x50  # push rbp
.Lunwind_GENSOLV_FCLOSE:
    .byte 1, .Ltext_00e4-GENSOLV_FCLOSE, 5, 0x35  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_00e4-GENSOLV_FCLOSE, 0x34  # save rbx
    .short 104/8  # stack bytes in 8-byte units
    .byte .Ltext_00e0-GENSOLV_FCLOSE, 0x03  # set frame pointer
    .byte .Ltext_00db-GENSOLV_FCLOSE, 0xd2  # allocate 112 stack bytes
    .byte .Ltext_00d7-GENSOLV_FCLOSE, 0x50  # push rbp
    .short 0  # unwind slot padding
.Lunwind_SET_GLOBAL_COMMONS:
    .byte 1, .Ltext_013e-SET_GLOBAL_COMMONS, 3, 0x25  # version, prologue length, slot count, frame register/offset
    .byte .Ltext_013e-SET_GLOBAL_COMMONS, 0x03  # set frame pointer
    .byte .Ltext_0139-SET_GLOBAL_COMMONS, 0x32  # allocate 32 stack bytes
    .byte .Ltext_0135-SET_GLOBAL_COMMONS, 0x50  # push rbp
    .short 0  # unwind slot padding
coff_end.xdata:

# @section .pdata 0x40300040
    .section .pdata
.Lbase_pdata:
    .long coff_rva.GENSOLV_FOPEN
    .long coff_rva.GENSOLV_FOPEN+(.Lend_GENSOLV_FOPEN-GENSOLV_FOPEN)
    .long coff_rva..xdata+(.Lunwind_GENSOLV_FOPEN-.Lbase_xdata)
    .long coff_rva.GENSOLV_FCLOSE
    .long coff_rva.GENSOLV_FCLOSE+(.Lend_GENSOLV_FCLOSE-GENSOLV_FCLOSE)
    .long coff_rva..xdata+(.Lunwind_GENSOLV_FCLOSE-.Lbase_xdata)
    .long coff_rva.SET_GLOBAL_COMMONS
    .long coff_rva.SET_GLOBAL_COMMONS+(.Lend_SET_GLOBAL_COMMONS-SET_GLOBAL_COMMONS)
    .long coff_rva..xdata+(.Lunwind_SET_GLOBAL_COMMONS-.Lbase_xdata)
coff_end.pdata:

# @section .drectve 0x100a00
    .section .drectve
.Lbase_drectve:
    .ascii "-export:SET_GLOBAL_COMMONS  -export:GENSOLV_FCLOSE  -export:GENSOLV_FOPEN  -defaultlib:\"ifconsol\" -defaultlib:\"libifcoremd\" -defaultlib:\"libifportmd\" -defaultlib:\"ifwin\" -defaultlib:\"user32\" -defaultlib:\"gdi32\" -defaultlib:\"libmmd\" -defaultlib:\"MSVCRT\" -defaultlib:\"libirc\" -defaultlib:\"svml_dispmd\" -defaultlib:\"OLDNAMES\" "
coff_end.drectve:
