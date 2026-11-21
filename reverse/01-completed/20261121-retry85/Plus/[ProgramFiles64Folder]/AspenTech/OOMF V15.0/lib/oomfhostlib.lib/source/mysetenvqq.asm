; x64\Release\mysetenvqq.obj
; Reconstructed Win64 NASM source. Original .text offsets follow the instructions.
bits 64

extern SETENVQQ:function
required __ImageBase:function
global MYSETENVQQ:function

section .drectve info align=1
    db '-defaultlib:"ifmodintr.lib" '
    db '-defaultlib:"IFWIN.LIB" '
    db '-defaultlib:"ifconsol" '
    db '-defaultlib:"libifcoremd" '
    db '-defaultlib:"libifportmd" '
    db '-defaultlib:"ifwin" '
    db '-defaultlib:"user32" '
    db '-defaultlib:"gdi32" '
    db '-defaultlib:"libmmd" '
    db '-defaultlib:"MSVCRT" '
    db '-defaultlib:"libirc" '
    db '-defaultlib:"svml_dispmd" '
    db '-defaultlib:"OLDNAMES" '

section .text code align=16

; Call Intel Fortran SETENVQQ and sign-extend its 32-bit result.
MYSETENVQQ:
section_text:
    sub rsp, strict byte 0x28                                                   ; .text+0x0000
    call SETENVQQ                                                               ; .text+0x0004
    movsxd rax, eax                                                             ; .text+0x0009
    add rsp, strict byte 0x28                                                   ; .text+0x000c
    ret                                                                         ; .text+0x0010
    nop dword [dword rax + rax]                                                 ; .text+0x0011
    nop dword [dword rax]                                                       ; .text+0x0019
boundary_0020:

section .xdata rdata align=4
section_xdata:
    db 0x01, 0x04, 0x01, 0x00, 0x04, 0x42, 0x00, 0x00

section .pdata rdata align=4
    ; RUNTIME_FUNCTION for MYSETENVQQ: begin, end, unwind.
    dd MYSETENVQQ wrt ..imagebase
    dd boundary_0020 wrt ..imagebase
    dd section_xdata wrt ..imagebase
