# AMD64 COFF member .\Release\atdll.obj
# External reference identifiers encode the original relocation type, COFF symbol index and name.
.intel_syntax noprefix

.section a1,"dr"
# COFF section 1: .drectve
begin_1:
symbol_3:  # .drectve
    .ascii "   /DEFAULTLIB:\"MSVCRT\" /DEFAULTLIB:\"OLDNAMES\" "
end_1:

.section a3,"dr"
# COFF section 3: .data
begin_3:
symbol_7:  # .data
# Public pointer relocated to the 41.0 / Apr 11 2025 version text.
symbol_9:  # ?LIBATDLL_VERSION@@3PEBDEB
    .quad R01_ADDR64_S12_C__0GD_GDICMOMO_libatdll_4lib_3_541_40_5Apr_511_52025_5
end_3:

.section a4,"dr"
# COFF section 4: .rdata
begin_4:
symbol_10:  # .rdata
symbol_12:  # ??_C@_0GD@GDICMOMO@libatdll?4lib?3?541?40?5Apr?511?52025?5@
    .ascii "libatdll.lib: 41.0 Apr 11 2025 "
    .byte 0xa9, 0x20, 0x41, 0x73, 0x70, 0x65, 0x6e, 0x20, 0x54, 0x65, 0x63, 0x68
    .ascii "nology, Inc. All rights reserved Aspen Technology, Inc.\000"
end_4:
