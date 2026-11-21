; Reconstructed Windows AMD64 COFF for the Aspen Plus Nylon-6 example.
; Build with usrny6.obj.build.py to preserve the original COFF metadata.
; USRNY6 forwards the host's 28 argument pointers and appends four PLEX arguments.
bits 64
default rel

global USRNY6
extern SHS_FIPOLM, DMS_LOCATI, USR002
extern __imp_DMS_IPOFF1, __imp_DMS_IPOFF4, __imp_DMS_PLEX
required __ImageBase, _fltused
common PPEXEC_USER 224
common DMS_RGLOB 160
common DMS_NCOMP 192
common DMS_PLEX 128
common DMS_IPOFF1 12800
common DMS_IPOFF4 12000

; The post-prologue stack holds caller arguments 5..28 at rsp+0x160..0x218.
; Outgoing arguments 5..32 occupy rsp+0x20..0xf8 above the Win64 shadow space.
frame_size equ 0x108
ipoff1_mw equ 305 * 8
ipoff4_dscc equ 1 * 8

section .text code align=16
USRNY6:
    push rsi
.save_rsi:
    push rdi
.save_rdi:
    push r12
.save_r12:
    push r13
.save_r13:
    push r14
.save_r14:
    push r15
.save_r15:
    sub rsp, frame_size
.prologue_end:
    mov r12, rcx
    mov rax, [__imp_DMS_IPOFF1]
    lea rcx, [USRNY6$NBPDIR.0.1]
    mov r10, [__imp_DMS_IPOFF4]
    mov r13, r9
    mov r14, r8
    mov r15, rdx
    mov rsi, [rax + ipoff1_mw]
    mov rdi, [r10 + ipoff4_dscc]
    call SHS_FIPOLM
.check_polymer_directory:
    cmp qword [USRNY6$NBPDIR.0.1], 0
    jle near USRNY6.return

    ; Look up the polymer directory and read its segment bead.
    lea rcx, [USRNY6$NBPDIR.0.1]
    call DMS_LOCATI
    mov r10, rax
    mov rax, [__imp_DMS_PLEX]
    mov r10, [rax + r10 * 8]
    mov [USRNY6$NBSEG.0.1], r10
    test r10, r10
    jle near USRNY6.return

    lea rcx, [USRNY6$NBSEG.0.1]
    call DMS_LOCATI
    mov rcx, rax
    mov rax, [__imp_DMS_PLEX]
    mov r10, [rsp + 0x168]
    mov r11, [rsp + 0x170]
    mov rax, [rax + rcx * 8 - 8]
    mov [USRNY6$NSEG.0.1], rax

    ; Marshal the original argument pointers into USR002's call frame.
    mov rax, rsp
    mov r8, [rsp + 0x160]
    mov r9, [rsp + 0x178]
    mov rdx, [rsp + 0x180]
    mov [rax + 0x28], r10
    mov r10, [rsp + 0x188]
    mov [rax + 0x48], r10
    mov r10, [rsp + 0x198]
    mov [rax + 0x58], r10
    mov r10, [rsp + 0x1a0]
    mov [rax + 0x60], r10
    mov r10, [rsp + 0x1a8]
    mov [rax + 0x68], r10
    mov r10, [rsp + 0x1b0]
    mov [rax + 0x70], r10
    mov r10, [rsp + 0x1b8]
    mov [rax + 0x78], r10
    mov r10, [rsp + 0x1c0]
    mov [rax + 0x80], r10
    mov r10, [rsp + 0x1c8]
    mov [rax + 0x88], r10
    mov r10, [rsp + 0x1d0]
    mov [rax + 0x90], r10
    mov r10, [rsp + 0x1d8]
    mov [rax + 0x98], r10
    mov r10, [rsp + 0x1e0]
    mov [rax + 0xa0], r10
    mov r10, [rsp + 0x1e8]
    mov [rax + 0xa8], r10
    mov r10, [rsp + 0x1f0]
    mov [rax + 0xb0], r10
    mov r10, [rsp + 0x1f8]
    mov [rax + 0xb8], r10
    mov r10, [rsp + 0x200]
    mov [rax + 0xc0], r10
    mov r10, [rsp + 0x208]
    mov [rax + 0xc8], r10
    mov r10, [rsp + 0x210]
    mov [rax + 0xd0], r10
    mov r10, [rsp + 0x218]
    mov [rax + 0xd8], r10
    mov r10, [__imp_DMS_PLEX]
    mov [rax + 0x30], r11
    mov r11, [rsp + 0x190]
    mov [rax + 0x20], r8
    lea r10, [r10]
    mov [rax + 0x38], r9
    lea rsi, [r10 + rsi * 8]
    mov [rax + 0xe0], rsi          ; 29: B(KMW)
    mov r8, r14
    mov rsi, [__imp_DMS_PLEX]
    mov r9, r13
    mov [rax + 0x40], rdx
    mov rdx, r15
    mov [rax + 0x50], r11
    lea r10, [rsi]
    lea rsi, [USRNY6$NSEG.0.1]
    mov [rax + 0xf0], rsi          ; 31: NSEG by reference
    lea rdi, [r10 + rdi * 8]
    mov [rax + 0xe8], rdi          ; 30: IB(KDSCC)
    mov rdi, [__imp_DMS_PLEX]
    lea r10, [rdi]
    lea r11, [r10 + rcx * 8]
    mov rcx, r12
    mov [rax + 0xf8], r11          ; 32: IB(LIDXSG)
    call USR002

.return:
    add rsp, frame_size
    pop r15
    pop r14
    pop r13
    pop r12
    pop rdi
    pop rsi
    ret

    ; Original 5- and 8-byte x86 alignment NOP encodings.
    db 0x0f, 0x1f, 0x44, 0x00, 0x00
    db 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00
.end:

section .bss bss align=8
USRNY6$NBPDIR.0.1: resq 1
USRNY6$NBSEG.0.1:  resq 1
USRNY6$NSEG.0.1:   resq 1

section .xdata rdata align=4
unwind_usrny6:
    db 1, USRNY6.prologue_end - USRNY6, 8, 0
    db USRNY6.prologue_end - USRNY6, 0x01 ; UWOP_ALLOC_LARGE (form 0)
    dw frame_size / 8
    db USRNY6.save_r15 - USRNY6, 0xf0   ; UWOP_PUSH_NONVOL with register number
    db USRNY6.save_r14 - USRNY6, 0xe0
    db USRNY6.save_r13 - USRNY6, 0xd0
    db USRNY6.save_r12 - USRNY6, 0xc0
    db USRNY6.save_rdi - USRNY6, 0x70
    db USRNY6.save_rsi - USRNY6, 0x60

section .pdata rdata align=4
    dd USRNY6 wrt ..imagebase
    dd USRNY6.end wrt ..imagebase
    dd unwind_usrny6 wrt ..imagebase

section .drectve info align=1
    db '-defaultlib:"ifconsol" -defaultlib:"libifcoremd" -defaultlib:"libifportmd" '
    db '-defaultlib:"libmmd" -defaultlib:"MSVCRT" -defaultlib:"libirc" '
    db '-defaultlib:"svml_dispmd" -defaultlib:"OLDNAMES" '
