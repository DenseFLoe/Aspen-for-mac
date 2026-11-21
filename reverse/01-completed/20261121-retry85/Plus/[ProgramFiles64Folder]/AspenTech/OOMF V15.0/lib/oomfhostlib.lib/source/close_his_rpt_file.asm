; x64\Release\close_his_rpt_file.obj
; Reconstructed Win64 NASM source. Original .text offsets follow the instructions.
bits 64

extern for_close:function
required __ImageBase:function
global CLOSE_HIS_RPT_FILE:function

section .text code align=16

; Close Fortran logical units 36, 14, and 6, in that order.
CLOSE_HIS_RPT_FILE:
section_text:
    push rbx                                                                    ; .text+0x0000
    sub rsp, strict byte 0x60                                                   ; .text+0x0001
    mov edx, 0x24                                                               ; .text+0x0005
    mov rax, rsp                                                                ; .text+0x000a
    lea rcx, [byte rsp + 0x30]                                                  ; .text+0x000d
    mov r8, 0x801208384ff00                                                     ; .text+0x0012
    lea r9, [rel __STRLITPACK_0.0.1]                                            ; .text+0x001c
    xor ebx, ebx                                                                ; .text+0x0023
    mov [rcx], rbx                                                              ; .text+0x0025
    mov [byte rax + 0x20], rbx                                                  ; .text+0x0028
    call for_close                                                              ; .text+0x002c
    mov rax, rsp                                                                ; .text+0x0031
    lea rcx, [byte rsp + 0x30]                                                  ; .text+0x0034
    mov edx, 0xe                                                                ; .text+0x0039
    mov r8, 0x801208384ff00                                                     ; .text+0x003e
    lea r9, [rel __STRLITPACK_1.0.1]                                            ; .text+0x0048
    mov [rcx], rbx                                                              ; .text+0x004f
    mov [byte rax + 0x20], rbx                                                  ; .text+0x0052
    call for_close                                                              ; .text+0x0056
    mov rax, rsp                                                                ; .text+0x005b
    lea rcx, [byte rsp + 0x30]                                                  ; .text+0x005e
    mov edx, 6                                                                  ; .text+0x0063
    mov r8, 0x801208384ff00                                                     ; .text+0x0068
    lea r9, [rel __STRLITPACK_2.0.1]                                            ; .text+0x0072
    mov [rcx], rbx                                                              ; .text+0x0079
    mov [byte rax + 0x20], rbx                                                  ; .text+0x007c
    call for_close                                                              ; .text+0x0080
    add rsp, strict byte 0x60                                                   ; .text+0x0085
    pop rbx                                                                     ; .text+0x0089
    ret                                                                         ; .text+0x008a
    nop dword [byte rax + rax]                                                  ; .text+0x008b
boundary_0090:

section .rdata rdata align=4
__STRLITPACK_0.0.1:
section_rdata:
    db 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
__STRLITPACK_1.0.1:
    db 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
__STRLITPACK_2.0.1:
    db 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

section .xdata rdata align=4
section_xdata:
    db 0x01, 0x05, 0x02, 0x00, 0x05, 0xb2, 0x01, 0x30

section .pdata rdata align=4
    ; RUNTIME_FUNCTION for CLOSE_HIS_RPT_FILE: begin, end, unwind.
    dd CLOSE_HIS_RPT_FILE wrt ..imagebase
    dd boundary_0090 wrt ..imagebase
    dd section_xdata wrt ..imagebase

section .drectve info align=1
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
