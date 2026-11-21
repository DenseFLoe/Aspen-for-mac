; URCNY6 from Aspen Plus V15.0's nylon6.apwz, Windows x64 COFF.
; Assemble with: nasm -f win64 urcny6.obj.asm -o urcny6.obj
; Original Fortran argument positions (1-based): 6=IDSCC, 46=CSS,
; 50=NURC, 51=RCUSER. The routine uses 8-byte INTEGER / REAL operands.
; The static indices survive calls and are initially zero in .bss.
bits 64
default rel

required __imp_DMS_NCOMP
required __imp_DMS_RGLOB
required __ImageBase
required _fltused
common DMS_NCOMP    0xc0
common DMS_RGLOB    0xa0
common PPEXEC_USER  0xe0
common DMS_GLOBAL  0x260
common DMS_FLSCOM   0x40
common DMS_RPTGLB   0x80
common SHS_STWORK  0x380
common DMS_STWKWK  0x180
common DMS_IPOFF1 0x3200
common DMS_PLEX     0x80
common DMS_ERROUT 0x1f40

section .text code align=16
global URCNY6
URCNY6:
    push    r15
.saved_r15:
    push    rbp
.saved_rbp:
    sub     rsp, 0x48
.allocated_stack:
    movups  oword [rsp + 0x20], xmm7
.saved_xmm7:
    mov     rax, qword [rel __imp_DMS_NCOMP]
    mov     rdx, qword [rel URCNY6$ITCO.0.1]
    mov     r8, qword [rel URCNY6$IACA.0.1]
    mov     r10, qword [rax]
    test    r10, r10
    jle     near .load_concentrations
    mov     rcx, r10
    xor     r9d, r9d
    shr     rcx, 0x3f
    xor     ebp, ebp
    add     rcx, r10
    mov     r15d, 0x1
    sar     rcx, 0x1
    xor     eax, eax

; IDSCC pointer from the sixth argument
    mov     r11, qword [rsp + 0x88]
    test    rcx, rcx
    jbe     near .scan_tail

; Scan two 16-byte IDs per iteration. A later match replaces the saved index.
.save_loop_registers:
    mov     qword [rsp + 0x30], r13
.saved_r13:
    mov     r15, 0x2020202020414341
    mov     qword [rsp + 0x38], r14
.scan_pair:
    mov     r13, qword [rax + r11*0x1]
    cmp     r13, r15
    jnz     short .L093
    mov     r13, 0x2020202020202020
    cmp     r13, qword [rax + r11*0x1 + 0x8]
    jnz     short .L0eb
    lea     r8, [rbp + 0x1]
    mov     qword [rel URCNY6$IACA.0.1], r8
    jmp     short .L0eb
.L093:
    mov     r14, 0x2020202044494341
    cmp     r13, r14
    jnz     short .L0c0
    mov     r13, 0x202020202020452d
    cmp     r13, qword [rax + r11*0x1 + 0x8]
    jnz     short .L0eb
    lea     rdx, [rbp + 0x1]
    mov     qword [rel URCNY6$ITCO.0.1], rdx
    jmp     short .L0eb
.L0c0:
    mov     r14, 0x202020202d414341
    cmp     r13, r14
    jnz     short .L0eb
    mov     r13, 0x2020202020202052
    cmp     r13, qword [rax + r11*0x1 + 0x8]
    jnz     short .L0eb
    lea     r13, [rbp + 0x1]
    mov     qword [rel URCNY6$IREP.0.1], r13
.L0eb:
    mov     r13, qword [rax + r11*0x1 + 0x10]
    cmp     r13, r15
    jnz     short .L113
    mov     r13, 0x2020202020202020
    cmp     r13, qword [rax + r11*0x1 + 0x18]
    jnz     short .L16b
    lea     r8, [rbp + 0x2]
    mov     qword [rel URCNY6$IACA.0.1], r8
    jmp     short .L16b
.L113:
    mov     r14, 0x2020202044494341
    cmp     r13, r14
    jnz     short .L140
    mov     r13, 0x202020202020452d
    cmp     r13, qword [rax + r11*0x1 + 0x18]
    jnz     short .L16b
    lea     rdx, [rbp + 0x2]
    mov     qword [rel URCNY6$ITCO.0.1], rdx
    jmp     short .L16b
.L140:
    mov     r14, 0x202020202d414341
    cmp     r13, r14
    jnz     short .L16b
    mov     r13, 0x2020202020202052
    cmp     r13, qword [rax + r11*0x1 + 0x18]
    jnz     short .L16b
    lea     r13, [rbp + 0x2]
    mov     qword [rel URCNY6$IREP.0.1], r13
.L16b:
    inc     r9
    add     rbp, 0x2
    add     rax, 0x20
    cmp     r9, rcx
    jc      near .scan_pair
    mov     r13, qword [rsp + 0x30]
    lea     r15, [nosplit r9*2 + 1]
    mov     r14, qword [rsp + 0x38]

; Process the last entry for an odd count.
.scan_tail:
    lea     rax, [r15 - 0x1]
    cmp     rax, r10
    jnc     near .load_concentrations
    shl     rax, 0x4
    mov     rcx, 0x2020202020414341
    mov     rbp, qword [rax + r11*0x1]
    cmp     rbp, rcx
    jnz     short .L1d2
    mov     rcx, 0x2020202020202020
    cmp     rcx, qword [rax + r11*0x1 + 0x8]
    jnz     short .load_concentrations
    mov     r8, r15
    mov     qword [rel URCNY6$IACA.0.1], r8
    jmp     short .load_concentrations
.L1d2:
    mov     rcx, 0x2020202044494341
    cmp     rbp, rcx
    jnz     short .L1fe
    mov     rcx, 0x202020202020452d
    cmp     rcx, qword [rax + r11*0x1 + 0x8]
    jnz     short .load_concentrations
    mov     rdx, r15
    mov     qword [rel URCNY6$ITCO.0.1], rdx
    jmp     short .load_concentrations
.L1fe:
    mov     rcx, 0x202020202d414341
    cmp     rbp, rcx
    jnz     short .load_concentrations
    mov     rcx, 0x2020202020202052
    cmp     rcx, qword [rax + r11*0x1 + 0x8]
    jnz     short .load_concentrations
    mov     qword [rel URCNY6$IREP.0.1], r15

; CSS is argument 46. Positive ACA / ACID-E indices contribute to output 1.
.load_concentrations:
    mov     rcx, qword [rsp + 0x1c8]
    pxor    xmm5, xmm5
    movaps  xmm4, xmm5
    movaps  xmm0, xmm5
    test    r8, r8
    jle     short .L243
    movsd   xmm4, qword [rcx + r8*0x8 - 0x8]
.L243:
    test    rdx, rdx
    jle     short .L24e
    movsd   xmm0, qword [rcx + rdx*0x8 - 0x8]

; NURC is argument 50, RCUSER is argument 51. Output 1 is unconditional.
.L24e:
    mov     rax, qword [rsp + 0x1e8]
    addsd   xmm4, xmm0
    mov     r8, qword [rsp + 0x1f0]
    mov     rbp, qword [rax]
    movsd   qword [r8], xmm4
    cmp     rbp, 0x2
    jl      near .restore_and_return

; Outputs 2 onward use ACID-E + ACA-R. The two CSS loads are unconditional here.
.load_denominator:
    mov     rax, qword [rel URCNY6$IREP.0.1]
    movsd   xmm3, qword [rcx + rdx*0x8 - 0x8]
    movaps  xmm1, xmm3
    movsd   xmm2, qword [rcx + rax*0x8 - 0x8]
    mov     rdx, qword [rel __imp_DMS_RGLOB]
    addsd   xmm1, xmm2

; RGLOB_RMIN at byte offset 8. JBE makes unordered comparisons take the zero path.
    movsd   xmm0, qword [rdx + 0x8]
    comisd  xmm1, xmm0
    jbe     short .L2af
    movaps  xmm7, xmm3
    divsd   xmm7, xmm1
    movsd   qword [r8 + 0x8], xmm7
    jmp     short .check_output_3
.L2af:
    movsd   qword [r8 + 0x8], xmm5
    pxor    xmm7, xmm7
.check_output_3:
    cmp     rbp, 0x3
    jl      near .restore_and_return
    mulsd   xmm7, xmm4
    movsd   qword [r8 + 0x10], xmm7
.check_output_4:
    cmp     rbp, 0x4
    jl      near .restore_and_return
    comisd  xmm1, xmm0
    jbe     short .L2ec
    movaps  xmm7, xmm2
    divsd   xmm7, xmm1
    movsd   qword [r8 + 0x18], xmm7
    jmp     short .check_output_5
.L2ec:
    movsd   qword [r8 + 0x18], xmm5
    pxor    xmm7, xmm7
.check_output_5:
    cmp     rbp, 0x5
    jl      short .restore_and_return
    mulsd   xmm7, xmm4
    movsd   qword [r8 + 0x20], xmm7
.check_output_6:
    cmp     rbp, 0x6
    jl      short .restore_and_return
    comisd  xmm1, xmm0
    jbe     short .L329
    movaps  xmm7, xmm2
    divsd   xmm3, xmm1
    divsd   xmm7, xmm1
    mulsd   xmm3, xmm7
    movsd   qword [r8 + 0x28], xmm3
    jmp     short .check_output_7
.L329:
    movsd   qword [r8 + 0x28], xmm5
    pxor    xmm3, xmm3

; At NURC >= 7 both outputs 7 and 8 are written.
.check_output_7:
    cmp     rbp, 0x7
    jl      short .restore_and_return
    mulsd   xmm3, xmm4
    comisd  xmm1, xmm0
    movsd   qword [r8 + 0x30], xmm3
    jbe     short .L35c
    divsd   xmm2, xmm1
    movaps  xmm5, xmm2
    mulsd   xmm5, xmm2
    movsd   qword [r8 + 0x38], xmm5
    jmp     short .check_output_9
.L35c:
    movsd   qword [r8 + 0x38], xmm5
.check_output_9:
    cmp     rbp, 0x9
    jl      short .restore_and_return
    mulsd   xmm4, xmm5
    movsd   qword [r8 + 0x40], xmm4
.restore_and_return:
    movups  xmm7, oword [rsp + 0x20]
    add     rsp, 0x48
    pop     rbp
    pop     r15
    ret
    nop                      ; original 16-byte section alignment
.end:

section .bss bss align=8
URCNY6$ITCO.0.1: resq 1
URCNY6$IACA.0.1: resq 1
URCNY6$IREP.0.1: resq 1

; Three Windows RUNTIME_FUNCTION ranges with the original scoped unwind state.
section .pdata rdata align=4
    dd URCNY6 wrt ..imagebase, URCNY6.save_loop_registers wrt ..imagebase, unwind_entry wrt ..imagebase
    dd URCNY6.save_loop_registers wrt ..imagebase, URCNY6.scan_tail wrt ..imagebase, unwind_loop wrt ..imagebase
    dd URCNY6.scan_tail wrt ..imagebase, URCNY6.end wrt ..imagebase, unwind_rest wrt ..imagebase

section .xdata rdata align=4
unwind_entry:
    db 1, URCNY6.saved_xmm7 - URCNY6, 5, 0
    db URCNY6.saved_xmm7 - URCNY6, 0x78      ; UWOP_SAVE_XMM128 XMM7
    dw 2
    db URCNY6.allocated_stack - URCNY6, 0x82 ; UWOP_ALLOC_SMALL 0x48
    db URCNY6.saved_rbp - URCNY6, 0x50       ; UWOP_PUSH_NONVOL RBP
    db URCNY6.saved_r15 - URCNY6, 0xf0       ; UWOP_PUSH_NONVOL R15
    dw 0
unwind_loop:
    db 1, URCNY6.scan_pair - URCNY6.save_loop_registers, 9, 0
    db URCNY6.scan_pair - URCNY6.save_loop_registers, 0xe4 ; UWOP_SAVE_NONVOL R14
    dw 7
    db URCNY6.saved_r13 - URCNY6.save_loop_registers, 0xd4 ; UWOP_SAVE_NONVOL R13
    dw 6
    db 0, 0x78
    dw 2
    db 0, 0x82, 0, 0x50, 0, 0xf0
    dw 0
unwind_rest:
    db 1, 0, 5, 0
    db 0, 0x78
    dw 2
    db 0, 0x82, 0, 0x50, 0, 0xf0
    dw 0

section .drectve info
    db '-defaultlib:"ifconsol" -defaultlib:"libifcoremd" '
    db '-defaultlib:"libifportmd" -defaultlib:"libmmd" '
    db '-defaultlib:"MSVCRT" -defaultlib:"libirc" '
    db '-defaultlib:"svml_dispmd" -defaultlib:"OLDNAMES" '
