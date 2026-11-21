; x86 source for the exception cleanup and stack probing entries.
; The EH entry labels use the parent frame's EBP supplied by the exception runtime.
; Link delete_sized_x86 to the original 10001bee equivalent.
bits 32
section .text
extern delete_sized_x86
extern security_check_cookie_x86, cxx_frame_handler3_x86

global cleanup_if_allocated, unwind_dllmain_1, unwind_dllmain_2, unwind_dllmain_3
global alloca_probe_16, alloca_probe_8, alloca_probe
global eh_dispatch_10002a24, eh_dispatch_10002a5d, eh_dispatch_10002a94

cleanup_if_allocated:                 ; 100019f0, context pointer in ECX
    mov eax, [ecx + 4]
    test eax, eax
    jz .done
    push 0x18
    push eax
    call delete_sized_x86
    add esp, 8
.done:
    ret

unwind_dllmain_1:                      ; 10002a10, map pointer at 100037c8
    push 8
    mov eax, [ebp - 0x14]
    push eax
    call delete_sized_x86
    add esp, 8
    ret

unwind_dllmain_2:                      ; 10002a50, map pointer at 100037f4
    lea ecx, [ebp - 0x18]
    jmp cleanup_if_allocated

unwind_dllmain_3:                      ; 10002a80, map pointer at 10003820
    push 8
    mov eax, [ebp + 0x0c]
    push eax
    call delete_sized_x86
    add esp, 8
    ret

eh_dispatch_10002a24:
    nop
    nop
    mov edx, [esp + 8]
    lea eax, [edx + 0x0c]
    mov ecx, [edx - 0x18]
    xor ecx, eax
    call security_check_cookie_x86
    mov eax, eh_funcinfo_100037a0
    jmp cxx_frame_handler3_x86

eh_dispatch_10002a5d:
    nop
    nop
    mov edx, [esp + 8]
    lea eax, [edx + 0x0c]
    mov ecx, [edx - 0x20]
    xor ecx, eax
    call security_check_cookie_x86
    mov eax, eh_funcinfo_100037cc
    jmp cxx_frame_handler3_x86

eh_dispatch_10002a94:
    nop
    nop
    mov edx, [esp + 8]
    lea eax, [edx + 0x0c]
    mov ecx, [edx - 0x10]
    xor ecx, eax
    call security_check_cookie_x86
    mov eax, eh_funcinfo_100037f8
    jmp cxx_frame_handler3_x86

alloca_probe_16:                       ; 100029b0, request size in EAX
    push ecx
    lea ecx, [esp + 8]
    sub ecx, eax
    and ecx, 0x0f
    add eax, ecx
    sbb ecx, ecx
    or eax, ecx
    pop ecx
    jmp alloca_probe

alloca_probe_8:                        ; 100029c6, request size in EAX
    push ecx
    lea ecx, [esp + 8]
    sub ecx, eax
    and ecx, 7
    add eax, ecx
    sbb ecx, ecx
    or eax, ecx
    pop ecx
    jmp alloca_probe

alloca_probe:                          ; 100029e0, moves ESP and its return address
    push ecx
    lea ecx, [esp + 4]
    sub ecx, eax
    sbb eax, eax
    not eax
    and ecx, eax
    mov eax, esp
    and eax, 0xfffff000
.check_page:
    cmp ecx, eax
    jb .touch_previous_page
    mov eax, ecx
    pop ecx
    xchg eax, esp
    mov eax, [eax]
    mov [esp], eax
    ret
.touch_previous_page:
    sub eax, 0x1000
    test [eax], eax
    jmp .check_page

section .rdata align=4

eh_funcinfo_100037a0:
    dd 0x19930522, 1, .unwind_map
    dd 0, 0, 0, 0, 0, 1
.unwind_map:
    dd -1, unwind_dllmain_1

eh_funcinfo_100037cc:
    dd 0x19930522, 1, .unwind_map
    dd 0, 0, 0, 0, 0, 1
.unwind_map:
    dd -1, unwind_dllmain_2

eh_funcinfo_100037f8:
    dd 0x19930522, 1, .unwind_map
    dd 0, 0, 0, 0, 0, 1
.unwind_map:
    dd -1, unwind_dllmain_3
