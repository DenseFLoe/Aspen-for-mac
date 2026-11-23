/* NATIVE-340 MethodDef bodies: IL disassembly from original bytes (tool/il_disasm.py) */
// MethodDef 0x06000001  std.exception.{ctor}  flavor=IL rva=0x10A0
.method /* std.exception.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: stloc.0
  IL_000C: ldloc.0
  IL_000D: ldc.i4.0
  IL_000E: ldc.i4.s  0x10
  IL_0010: conv.i8
  IL_0011: initblk
  IL_0013: ldarg.1
  IL_0014: ldc.i4.8
  IL_0015: conv.i8
  IL_0016: add
  IL_0017: ldloc.0
  IL_0018: call      0x06000084 __std_exception_copy
  IL_001D: ldarg.0
  IL_001E: ret
}
// MethodDef 0x06000002  std.exception.{dtor}  flavor=IL rva=0x10CC
.method /* std.exception.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: call      0x06000083 __std_exception_destroy
  IL_0010: ret
}
// MethodDef 0x06000003  std.exception.what  flavor=IL rva=0x1AFC
.method /* std.exception.what */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.8
  IL_0002: conv.i8
  IL_0003: add
  IL_0004: ldind.i8
  IL_0005: stloc.0
  IL_0006: ldloc.0
  IL_0007: ldc.i4.0
  IL_0008: conv.i8
  IL_0009: bne.un.s  0x7
  IL_000B: ldsflda   0x04000001
  IL_0010: br.s      0x1
  IL_0012: ldloc.0
  IL_0013: ret
}
// MethodDef 0x06000004  std.exception.__vecDelDtor  flavor=IL rva=0x1A9C
.method /* std.exception.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4.2
  IL_0002: and
  IL_0003: brfalse.s 0x2c
  IL_0005: ldarg.0
  IL_0006: ldc.i4.8
  IL_0007: conv.i8
  IL_0008: sub
  IL_0009: stloc.0
  IL_000A: ldarg.0
  IL_000B: ldc.i4.s  0x18
  IL_000D: conv.i8
  IL_000E: ldloc.0
  IL_000F: ldind.i8
  IL_0010: ldftn     0x06000002 std.exception.{dtor}
  IL_0016: call      0x06000059 __ehvec_dtor
  IL_001B: ldarg.1
  IL_001C: ldc.i4.1
  IL_001D: and
  IL_001E: brfalse.s 0xf
  IL_0020: ldloc.0
  IL_0021: dup
  IL_0022: ldind.i8
  IL_0023: ldc.i4.s  0x18
  IL_0025: conv.i8
  IL_0026: mul
  IL_0027: ldc.i4.8
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: call      0x06000081 delete[]
  IL_002F: ldloc.0
  IL_0030: ret
  IL_0031: ldarg.0
  IL_0032: ldsflda   0x04000027
  IL_0037: stind.i8
  IL_0038: ldarg.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: call      0x06000083 __std_exception_destroy
  IL_0041: ldarg.1
  IL_0042: ldc.i4.1
  IL_0043: and
  IL_0044: brfalse.s 0x9
  IL_0046: ldarg.0
  IL_0047: ldc.i4.s  0x18
  IL_0049: conv.i8
  IL_004A: call      0x06000082 delete
  IL_004F: ldarg.0
  IL_0050: ret
}
// MethodDef 0x06000005  std.bad_alloc.__vecDelDtor  flavor=IL rva=0x1B1C
.method /* std.bad_alloc.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4.2
  IL_0002: and
  IL_0003: brfalse.s 0x2c
  IL_0005: ldarg.0
  IL_0006: ldc.i4.8
  IL_0007: conv.i8
  IL_0008: sub
  IL_0009: stloc.0
  IL_000A: ldarg.0
  IL_000B: ldc.i4.s  0x18
  IL_000D: conv.i8
  IL_000E: ldloc.0
  IL_000F: ldind.i8
  IL_0010: ldftn     0x06000006 std.bad_alloc.{dtor}
  IL_0016: call      0x06000059 __ehvec_dtor
  IL_001B: ldarg.1
  IL_001C: ldc.i4.1
  IL_001D: and
  IL_001E: brfalse.s 0xf
  IL_0020: ldloc.0
  IL_0021: dup
  IL_0022: ldind.i8
  IL_0023: ldc.i4.s  0x18
  IL_0025: conv.i8
  IL_0026: mul
  IL_0027: ldc.i4.8
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: call      0x06000081 delete[]
  IL_002F: ldloc.0
  IL_0030: ret
  IL_0031: ldarg.0
  IL_0032: ldsflda   0x04000027
  IL_0037: stind.i8
  IL_0038: ldarg.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: call      0x06000083 __std_exception_destroy
  IL_0041: ldarg.1
  IL_0042: ldc.i4.1
  IL_0043: and
  IL_0044: brfalse.s 0x9
  IL_0046: ldarg.0
  IL_0047: ldc.i4.s  0x18
  IL_0049: conv.i8
  IL_004A: call      0x06000082 delete
  IL_004F: ldarg.0
  IL_0050: ret
}
// MethodDef 0x06000006  std.bad_alloc.{dtor}  flavor=IL rva=0x10EC
.method /* std.bad_alloc.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: call      0x06000083 __std_exception_destroy
  IL_0010: ret
}
// MethodDef 0x06000007  std.bad_array_new_length.__vecDelDtor  flavor=IL rva=0x1B7C
.method /* std.bad_array_new_length.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4.2
  IL_0002: and
  IL_0003: brfalse.s 0x2c
  IL_0005: ldarg.0
  IL_0006: ldc.i4.8
  IL_0007: conv.i8
  IL_0008: sub
  IL_0009: stloc.0
  IL_000A: ldarg.0
  IL_000B: ldc.i4.s  0x18
  IL_000D: conv.i8
  IL_000E: ldloc.0
  IL_000F: ldind.i8
  IL_0010: ldftn     0x06000008 std.bad_array_new_length.{dtor}
  IL_0016: call      0x06000059 __ehvec_dtor
  IL_001B: ldarg.1
  IL_001C: ldc.i4.1
  IL_001D: and
  IL_001E: brfalse.s 0xf
  IL_0020: ldloc.0
  IL_0021: dup
  IL_0022: ldind.i8
  IL_0023: ldc.i4.s  0x18
  IL_0025: conv.i8
  IL_0026: mul
  IL_0027: ldc.i4.8
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: call      0x06000081 delete[]
  IL_002F: ldloc.0
  IL_0030: ret
  IL_0031: ldarg.0
  IL_0032: ldsflda   0x04000027
  IL_0037: stind.i8
  IL_0038: ldarg.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: call      0x06000083 __std_exception_destroy
  IL_0041: ldarg.1
  IL_0042: ldc.i4.1
  IL_0043: and
  IL_0044: brfalse.s 0x9
  IL_0046: ldarg.0
  IL_0047: ldc.i4.s  0x18
  IL_0049: conv.i8
  IL_004A: call      0x06000082 delete
  IL_004F: ldarg.0
  IL_0050: ret
}
// MethodDef 0x06000008  std.bad_array_new_length.{dtor}  flavor=IL rva=0x1BDC
.method /* std.bad_array_new_length.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: call      0x06000083 __std_exception_destroy
  IL_0010: ret
}
// MethodDef 0x06000009  std.exception_ptr.{dtor}  flavor=IL rva=0x110C
.method /* std.exception_ptr.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000080 __ExceptionPtrDestroy
  IL_0006: ret
}
// MethodDef 0x0600000A  std.exception_ptr.{ctor}  flavor=IL rva=0x1120
.method /* std.exception_ptr.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: call      0x0600007F __ExceptionPtrCopy
  IL_0007: ldarg.0
  IL_0008: ret
}
// MethodDef 0x0600000B  std.bad_array_new_length.{ctor}  flavor=IL rva=0x1198
.method /* std.bad_array_new_length.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: stloc.0
  IL_000C: ldloc.0
  IL_000D: ldc.i4.0
  IL_000E: ldc.i4.s  0x10
  IL_0010: conv.i8
  IL_0011: initblk
  IL_0013: ldarg.1
  IL_0014: ldc.i4.8
  IL_0015: conv.i8
  IL_0016: add
  IL_0017: ldloc.0
  IL_0018: call      0x06000084 __std_exception_copy
  IL_001D: ldarg.0
  IL_001E: ldsflda   0x04000026
  IL_0023: stind.i8
  IL_0024: leave.s   0xd
  IL_0026: ldftn     0x06000002 std.exception.{dtor}
  IL_002C: ldarg.0
  IL_002D: call      0x06000056 ___CxxCallUnwindDtor
  IL_0032: endfinally
  IL_0033: nop
  IL_0034: ldarg.0
  IL_0035: ldsflda   0x04000025
  IL_003A: stind.i8
  IL_003B: leave.s   0xd
  IL_003D: ldftn     0x06000006 std.bad_alloc.{dtor}
  IL_0043: ldarg.0
  IL_0044: call      0x06000056 ___CxxCallUnwindDtor
  IL_0049: endfinally
  IL_004A: ldarg.0
  IL_004B: ret
}
// MethodDef 0x0600000C  std.bad_alloc.{ctor}  flavor=IL rva=0x1138
.method /* std.bad_alloc.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: stloc.0
  IL_000C: ldloc.0
  IL_000D: ldc.i4.0
  IL_000E: ldc.i4.s  0x10
  IL_0010: conv.i8
  IL_0011: initblk
  IL_0013: ldarg.1
  IL_0014: ldc.i4.8
  IL_0015: conv.i8
  IL_0016: add
  IL_0017: ldloc.0
  IL_0018: call      0x06000084 __std_exception_copy
  IL_001D: ldarg.0
  IL_001E: ldsflda   0x04000026
  IL_0023: stind.i8
  IL_0024: leave.s   0xd
  IL_0026: ldftn     0x06000002 std.exception.{dtor}
  IL_002C: ldarg.0
  IL_002D: call      0x06000056 ___CxxCallUnwindDtor
  IL_0032: endfinally
  IL_0033: ldarg.0
  IL_0034: ret
}
// MethodDef 0x0600000D  std.bad_variant_access.what  flavor=IL rva=0x1C7C
.method /* std.bad_variant_access.what */ cil managed { 
  IL_0000: ldsflda   0x04000002
  IL_0005: ret
}
// MethodDef 0x0600000E  std.bad_variant_access.{dtor}  flavor=IL rva=0x1C5C
.method /* std.bad_variant_access.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: call      0x06000083 __std_exception_destroy
  IL_0010: ret
}
// MethodDef 0x0600000F  std.bad_variant_access.{ctor}  flavor=IL rva=0x1250
.method /* std.bad_variant_access.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: stloc.0
  IL_000C: ldloc.0
  IL_000D: ldc.i4.0
  IL_000E: ldc.i4.s  0x10
  IL_0010: conv.i8
  IL_0011: initblk
  IL_0013: ldarg.1
  IL_0014: ldc.i4.8
  IL_0015: conv.i8
  IL_0016: add
  IL_0017: ldloc.0
  IL_0018: call      0x06000084 __std_exception_copy
  IL_001D: ldarg.0
  IL_001E: ldsflda   0x04000020
  IL_0023: stind.i8
  IL_0024: leave.s   0xd
  IL_0026: ldftn     0x06000002 std.exception.{dtor}
  IL_002C: ldarg.0
  IL_002D: call      0x06000056 ___CxxCallUnwindDtor
  IL_0032: endfinally
  IL_0033: ldarg.0
  IL_0034: ret
}
// MethodDef 0x06000010  std.bad_variant_access.__vecDelDtor  flavor=IL rva=0x1BFC
.method /* std.bad_variant_access.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4.2
  IL_0002: and
  IL_0003: brfalse.s 0x2c
  IL_0005: ldarg.0
  IL_0006: ldc.i4.8
  IL_0007: conv.i8
  IL_0008: sub
  IL_0009: stloc.0
  IL_000A: ldarg.0
  IL_000B: ldc.i4.s  0x18
  IL_000D: conv.i8
  IL_000E: ldloc.0
  IL_000F: ldind.i8
  IL_0010: ldftn     0x0600000E std.bad_variant_access.{dtor}
  IL_0016: call      0x06000059 __ehvec_dtor
  IL_001B: ldarg.1
  IL_001C: ldc.i4.1
  IL_001D: and
  IL_001E: brfalse.s 0xf
  IL_0020: ldloc.0
  IL_0021: dup
  IL_0022: ldind.i8
  IL_0023: ldc.i4.s  0x18
  IL_0025: conv.i8
  IL_0026: mul
  IL_0027: ldc.i4.8
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: call      0x06000081 delete[]
  IL_002F: ldloc.0
  IL_0030: ret
  IL_0031: ldarg.0
  IL_0032: ldsflda   0x04000027
  IL_0037: stind.i8
  IL_0038: ldarg.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: call      0x06000083 __std_exception_destroy
  IL_0041: ldarg.1
  IL_0042: ldc.i4.1
  IL_0043: and
  IL_0044: brfalse.s 0x9
  IL_0046: ldarg.0
  IL_0047: ldc.i4.s  0x18
  IL_0049: conv.i8
  IL_004A: call      0x06000082 delete
  IL_004F: ldarg.0
  IL_0050: ret
}
// MethodDef 0x06000011  std.bad_cast.__vecDelDtor  flavor=IL rva=0x1C90
.method /* std.bad_cast.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4.2
  IL_0002: and
  IL_0003: brfalse.s 0x2c
  IL_0005: ldarg.0
  IL_0006: ldc.i4.8
  IL_0007: conv.i8
  IL_0008: sub
  IL_0009: stloc.0
  IL_000A: ldarg.0
  IL_000B: ldc.i4.s  0x18
  IL_000D: conv.i8
  IL_000E: ldloc.0
  IL_000F: ldind.i8
  IL_0010: ldftn     0x06000012 std.bad_cast.{dtor}
  IL_0016: call      0x06000059 __ehvec_dtor
  IL_001B: ldarg.1
  IL_001C: ldc.i4.1
  IL_001D: and
  IL_001E: brfalse.s 0xf
  IL_0020: ldloc.0
  IL_0021: dup
  IL_0022: ldind.i8
  IL_0023: ldc.i4.s  0x18
  IL_0025: conv.i8
  IL_0026: mul
  IL_0027: ldc.i4.8
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: call      0x06000081 delete[]
  IL_002F: ldloc.0
  IL_0030: ret
  IL_0031: ldarg.0
  IL_0032: ldsflda   0x04000027
  IL_0037: stind.i8
  IL_0038: ldarg.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: call      0x06000083 __std_exception_destroy
  IL_0041: ldarg.1
  IL_0042: ldc.i4.1
  IL_0043: and
  IL_0044: brfalse.s 0x9
  IL_0046: ldarg.0
  IL_0047: ldc.i4.s  0x18
  IL_0049: conv.i8
  IL_004A: call      0x06000082 delete
  IL_004F: ldarg.0
  IL_0050: ret
}
// MethodDef 0x06000012  std.bad_cast.{dtor}  flavor=IL rva=0x1CF0
.method /* std.bad_cast.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: call      0x06000083 __std_exception_destroy
  IL_0010: ret
}
// MethodDef 0x06000013  std.bad_cast.{ctor}  flavor=IL rva=0x12B0
.method /* std.bad_cast.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: stloc.0
  IL_000C: ldloc.0
  IL_000D: ldc.i4.0
  IL_000E: ldc.i4.s  0x10
  IL_0010: conv.i8
  IL_0011: initblk
  IL_0013: ldarg.1
  IL_0014: ldc.i4.8
  IL_0015: conv.i8
  IL_0016: add
  IL_0017: ldloc.0
  IL_0018: call      0x06000084 __std_exception_copy
  IL_001D: ldarg.0
  IL_001E: ldsflda   0x0400001F
  IL_0023: stind.i8
  IL_0024: leave.s   0xd
  IL_0026: ldftn     0x06000002 std.exception.{dtor}
  IL_002C: ldarg.0
  IL_002D: call      0x06000056 ___CxxCallUnwindDtor
  IL_0032: endfinally
  IL_0033: ldarg.0
  IL_0034: ret
}
// MethodDef 0x06000014  std._Iterator_base12.{ctor}  flavor=IL rva=0x1700
.method /* std._Iterator_base12.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.8
  IL_0002: conv.i8
  IL_0003: add
  IL_0004: ldc.i4.0
  IL_0005: conv.i8
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldarg.1
  IL_0009: ldind.i8
  IL_000A: stind.i8
  IL_000B: ldarg.0
  IL_000C: ret
}
// MethodDef 0x06000015  std._Iterator_base12.=  flavor=IL rva=0x1310
.method /* std._Iterator_base12.= */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldind.i8
  IL_0003: stind.i8
  IL_0004: ldarg.0
  IL_0005: ret
}
// MethodDef 0x06000016  std.bad_weak_ptr.what  flavor=IL rva=0x1D90
.method /* std.bad_weak_ptr.what */ cil managed { 
  IL_0000: ldsflda   0x04000003
  IL_0005: ret
}
// MethodDef 0x06000017  std.bad_weak_ptr.__vecDelDtor  flavor=IL rva=0x1D10
.method /* std.bad_weak_ptr.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4.2
  IL_0002: and
  IL_0003: brfalse.s 0x2c
  IL_0005: ldarg.0
  IL_0006: ldc.i4.8
  IL_0007: conv.i8
  IL_0008: sub
  IL_0009: stloc.0
  IL_000A: ldarg.0
  IL_000B: ldc.i4.s  0x18
  IL_000D: conv.i8
  IL_000E: ldloc.0
  IL_000F: ldind.i8
  IL_0010: ldftn     0x06000018 std.bad_weak_ptr.{dtor}
  IL_0016: call      0x06000059 __ehvec_dtor
  IL_001B: ldarg.1
  IL_001C: ldc.i4.1
  IL_001D: and
  IL_001E: brfalse.s 0xf
  IL_0020: ldloc.0
  IL_0021: dup
  IL_0022: ldind.i8
  IL_0023: ldc.i4.s  0x18
  IL_0025: conv.i8
  IL_0026: mul
  IL_0027: ldc.i4.8
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: call      0x06000081 delete[]
  IL_002F: ldloc.0
  IL_0030: ret
  IL_0031: ldarg.0
  IL_0032: ldsflda   0x04000027
  IL_0037: stind.i8
  IL_0038: ldarg.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: call      0x06000083 __std_exception_destroy
  IL_0041: ldarg.1
  IL_0042: ldc.i4.1
  IL_0043: and
  IL_0044: brfalse.s 0x9
  IL_0046: ldarg.0
  IL_0047: ldc.i4.s  0x18
  IL_0049: conv.i8
  IL_004A: call      0x06000082 delete
  IL_004F: ldarg.0
  IL_0050: ret
}
// MethodDef 0x06000018  std.bad_weak_ptr.{dtor}  flavor=IL rva=0x1D70
.method /* std.bad_weak_ptr.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: call      0x06000083 __std_exception_destroy
  IL_0010: ret
}
// MethodDef 0x06000019  std.bad_weak_ptr.{ctor}  flavor=IL rva=0x1324
.method /* std.bad_weak_ptr.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldsflda   0x04000027
  IL_0006: stind.i8
  IL_0007: ldarg.0
  IL_0008: ldc.i4.8
  IL_0009: conv.i8
  IL_000A: add
  IL_000B: stloc.0
  IL_000C: ldloc.0
  IL_000D: ldc.i4.0
  IL_000E: ldc.i4.s  0x10
  IL_0010: conv.i8
  IL_0011: initblk
  IL_0013: ldarg.1
  IL_0014: ldc.i4.8
  IL_0015: conv.i8
  IL_0016: add
  IL_0017: ldloc.0
  IL_0018: call      0x06000084 __std_exception_copy
  IL_001D: ldarg.0
  IL_001E: ldsflda   0x0400001D
  IL_0023: stind.i8
  IL_0024: leave.s   0xd
  IL_0026: ldftn     0x06000002 std.exception.{dtor}
  IL_002C: ldarg.0
  IL_002D: call      0x06000056 ___CxxCallUnwindDtor
  IL_0032: endfinally
  IL_0033: ldarg.0
  IL_0034: ret
}
// MethodDef 0x0600001A  PtrToStringChars  flavor=IL rva=0x1384
.method /* PtrToStringChars */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: stloc.0
  IL_0002: ldloc.0
  IL_0003: brfalse.s 0x9
  IL_0005: call      0x0A000029
  IL_000A: conv.i8
  IL_000B: ldloc.0
  IL_000C: add
  IL_000D: stloc.0
  IL_000E: ldloc.0
  IL_000F: ret
}
// MethodDef 0x0600001B  msclr.interop.details.GetAnsiStringSize  flavor=IL rva=0x13A0
.method /* msclr.interop.details.GetAnsiStringSize */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: stloc.0
  IL_0002: ldloc.0
  IL_0003: brfalse.s 0x9
  IL_0005: call      0x0A000029
  IL_000A: conv.i8
  IL_000B: ldloc.0
  IL_000C: add
  IL_000D: stloc.0
  IL_000E: ldloc.0
  IL_000F: stloc.2
  IL_0010: ldc.i4.3
  IL_0011: ldc.i4    0x00000400
  IL_0016: ldloc.2
  IL_0017: ldarg.0
  IL_0018: call      0x0A000028
  IL_001D: ldc.i4.0
  IL_001E: conv.i8
  IL_001F: ldc.i4.0
  IL_0020: ldc.i4.0
  IL_0021: conv.i8
  IL_0022: ldc.i4.0
  IL_0023: conv.i8
  IL_0024: call      0x0600007E WideCharToMultiByte
  IL_0029: conv.i8
  IL_002A: stloc.1
  IL_002B: ldloc.1
  IL_002C: brtrue.s  0x13
  IL_002E: ldarg.0
  IL_002F: call      0x0A000028
  IL_0034: brfalse.s 0xb
  IL_0036: ldstr     0x70000001
  IL_003B: newobj    0x0A000027
  IL_0040: throw
  IL_0041: ldloc.1
  IL_0042: ldc.i4.1
  IL_0043: conv.i8
  IL_0044: add
  IL_0045: ret
}
// MethodDef 0x0600001C  msclr.interop.details.WriteAnsiString  flavor=IL rva=0x13F4
.method /* msclr.interop.details.WriteAnsiString */ cil managed { 
  IL_0000: ldarg.2
  IL_0001: stloc.0
  IL_0002: ldloc.0
  IL_0003: brfalse.s 0x9
  IL_0005: call      0x0A000029
  IL_000A: conv.i8
  IL_000B: ldloc.0
  IL_000C: add
  IL_000D: stloc.0
  IL_000E: ldloc.0
  IL_000F: stloc.2
  IL_0010: ldarg.1
  IL_0011: ldc.i4    0x7FFFFFFF
  IL_0016: conv.i8
  IL_0017: ble.un.s  0xb
  IL_0019: ldstr     0x700000DE
  IL_001E: newobj    0x0A000026
  IL_0023: throw
  IL_0024: ldc.i4.3
  IL_0025: ldc.i4    0x00000400
  IL_002A: ldloc.2
  IL_002B: ldarg.2
  IL_002C: call      0x0A000028
  IL_0031: ldarg.0
  IL_0032: ldarg.1
  IL_0033: conv.i4
  IL_0034: ldc.i4.0
  IL_0035: conv.i8
  IL_0036: ldc.i4.0
  IL_0037: conv.i8
  IL_0038: call      0x0600007E WideCharToMultiByte
  IL_003D: conv.i8
  IL_003E: stloc.1
  IL_003F: ldloc.1
  IL_0040: ldarg.1
  IL_0041: bge.un.s  0xf
  IL_0043: ldloc.1
  IL_0044: brtrue.s  0x5
  IL_0046: ldarg.1
  IL_0047: ldc.i4.1
  IL_0048: conv.i8
  IL_0049: bne.un.s  0x7
  IL_004B: ldloc.1
  IL_004C: ldarg.0
  IL_004D: add
  IL_004E: ldc.i4.0
  IL_004F: stind.i1
  IL_0050: br.s      0xb
  IL_0052: ldstr     0x70000001
  IL_0057: newobj    0x0A000027
  IL_005C: throw
  IL_005D: ret
}
// MethodDef 0x0600001D  msclr.interop.details.GetUnicodeStringSize  flavor=IL rva=0x1460
.method /* msclr.interop.details.GetUnicodeStringSize */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4    0x7FFFFFFF
  IL_0006: conv.i8
  IL_0007: ble.un.s  0xb
  IL_0009: ldstr     0x700000DE
  IL_000E: newobj    0x0A000026
  IL_0013: throw
  IL_0014: ldc.i4.3
  IL_0015: ldc.i4.0
  IL_0016: ldarg.0
  IL_0017: ldarg.1
  IL_0018: conv.i4
  IL_0019: ldc.i4.0
  IL_001A: conv.i8
  IL_001B: ldc.i4.0
  IL_001C: call      0x0600007D MultiByteToWideChar
  IL_0021: conv.i8
  IL_0022: stloc.0
  IL_0023: ldloc.0
  IL_0024: brtrue.s  0xe
  IL_0026: ldarg.1
  IL_0027: brfalse.s 0xb
  IL_0029: ldstr     0x7000011E
  IL_002E: newobj    0x0A000027
  IL_0033: throw
  IL_0034: ldloc.0
  IL_0035: ldc.i4.1
  IL_0036: conv.i8
  IL_0037: add
  IL_0038: ret
}
// MethodDef 0x0600001E  msclr.interop.details.WriteUnicodeString  flavor=IL rva=0x14A8
.method /* msclr.interop.details.WriteUnicodeString */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i4    0x7FFFFFFF
  IL_0006: conv.i8
  IL_0007: bgt.un.s  0x39
  IL_0009: ldarg.3
  IL_000A: ldc.i4    0x7FFFFFFF
  IL_000F: conv.i8
  IL_0010: bgt.un.s  0x30
  IL_0012: ldc.i4.3
  IL_0013: ldc.i4.0
  IL_0014: ldarg.2
  IL_0015: ldarg.3
  IL_0016: conv.i4
  IL_0017: ldarg.0
  IL_0018: ldarg.1
  IL_0019: conv.i4
  IL_001A: call      0x0600007D MultiByteToWideChar
  IL_001F: conv.i8
  IL_0020: stloc.0
  IL_0021: ldloc.0
  IL_0022: ldarg.1
  IL_0023: bge.un.s  0x12
  IL_0025: ldloc.0
  IL_0026: brtrue.s  0x5
  IL_0028: ldarg.1
  IL_0029: ldc.i4.1
  IL_002A: conv.i8
  IL_002B: bne.un.s  0xa
  IL_002D: ldloc.0
  IL_002E: ldc.i4.2
  IL_002F: conv.i8
  IL_0030: mul
  IL_0031: ldarg.0
  IL_0032: add
  IL_0033: ldc.i4.0
  IL_0034: stind.i2
  IL_0035: br.s      0x16
  IL_0037: ldstr     0x7000011E
  IL_003C: newobj    0x0A000027
  IL_0041: throw
  IL_0042: ldstr     0x700000DE
  IL_0047: newobj    0x0A000026
  IL_004C: throw
  IL_004D: ret
}
// MethodDef 0x0600001F  msclr.interop.details.InternalAnsiToStringHelper  flavor=IL rva=0x171C
.method /* msclr.interop.details.InternalAnsiToStringHelper */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: call      0x0600001D msclr.interop.details.GetUnicodeStringSize
  IL_0007: stloc.1
  IL_0008: ldloc.1
  IL_0009: ldc.i4.1
  IL_000A: conv.i8
  IL_000B: sub
  IL_000C: ldc.i4    0x7FFFFFFE
  IL_0011: conv.i8
  IL_0012: bgt.un.s  0x5b
  IL_0014: ldloc.1
  IL_0015: ldc.i8    9223372036854775807
  IL_001E: bgt.un.s  0x6
  IL_0020: ldloc.1
  IL_0021: ldc.i4.2
  IL_0022: conv.i8
  IL_0023: mul
  IL_0024: br.s      0x9
  IL_0026: ldc.i8    18446744073709551615
  IL_002F: call      0x0600007B new[]
  IL_0034: stloc.0
  IL_0035: ldloca.s  0x4
  IL_0037: ldloc.0
  IL_0038: stind.i8
  IL_0039: ldloc.0
  IL_003A: brtrue.s  0x6
  IL_003C: newobj    0x0A000025
  IL_0041: throw
  IL_0042: ldloc.0
  IL_0043: ldloc.1
  IL_0044: ldarg.0
  IL_0045: ldarg.1
  IL_0046: call      0x0600001E msclr.interop.details.WriteUnicodeString
  IL_004B: ldloc.0
  IL_004C: ldc.i4.0
  IL_004D: ldloc.1
  IL_004E: conv.i4
  IL_004F: ldc.i4.1
  IL_0050: sub
  IL_0051: newobj    0x0A000024
  IL_0056: stloc.3
  IL_0057: leave.s   0xe
  IL_0059: ldftn     0x06000026 msclr.interop.details.char_buffer<wchar_t>.{dtor}
  IL_005F: ldloca.s  0x4
  IL_0061: call      0x06000056 ___CxxCallUnwindDtor
  IL_0066: endfinally
  IL_0067: ldloc.0
  IL_0068: call      0x0600007C delete[]
  IL_006D: ldloc.3
  IL_006E: ret
  IL_006F: ldstr     0x700000DE
  IL_0074: newobj    0x0A000026
  IL_0079: throw
  IL_007A: nop
  IL_007B: ldnull
  IL_007C: stloc.2
  IL_007D: leave.s   0xe
  IL_007F: ldftn     0x06000026 msclr.interop.details.char_buffer<wchar_t>.{dtor}
  IL_0085: ldloca.s  0x4
  IL_0087: call      0x06000056 ___CxxCallUnwindDtor
  IL_008C: endfinally
  IL_008D: ldloc.2
  IL_008E: ret
}
// MethodDef 0x06000020  SaveMergennFiles  flavor=IL rva=0x1A80
.method /* SaveMergennFiles */ cil managed { 
  IL_0000: newobj    0x060000A2 .ctor
  IL_0005: ldarg.0
  IL_0006: ldarg.1
  IL_0007: call      0x060000A1 WrapperSaveMergennFiles
  IL_000C: ret
}
// MethodDef 0x06000021  msclr.interop.details.char_buffer<char>.release  flavor=IL rva=0x1658
.method /* msclr.interop.details.char_buffer<char>.release */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: ldarg.0
  IL_0003: ldc.i4.0
  IL_0004: conv.i8
  IL_0005: stind.i8
  IL_0006: ret
}
// MethodDef 0x06000022  msclr.interop.details.char_buffer<char>.get  flavor=IL rva=0x166C
.method /* msclr.interop.details.char_buffer<char>.get */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: ret
}
// MethodDef 0x06000023  msclr.interop.details.char_buffer<char>.{dtor}  flavor=IL rva=0x167C
.method /* msclr.interop.details.char_buffer<char>.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: call      0x0600007C delete[]
  IL_0007: ret
}
// MethodDef 0x06000024  msclr.interop.details.char_buffer<char>.{ctor}  flavor=IL rva=0x1690
.method /* msclr.interop.details.char_buffer<char>.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: call      0x0600007B new[]
  IL_0007: stind.i8
  IL_0008: ldarg.0
  IL_0009: ret
}
// MethodDef 0x06000025  msclr.interop.details.char_buffer<wchar_t>.get  flavor=IL rva=0x16A8
.method /* msclr.interop.details.char_buffer<wchar_t>.get */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: ret
}
// MethodDef 0x06000026  msclr.interop.details.char_buffer<wchar_t>.{dtor}  flavor=IL rva=0x16B8
.method /* msclr.interop.details.char_buffer<wchar_t>.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: call      0x0600007C delete[]
  IL_0007: ret
}
// MethodDef 0x06000027  msclr.interop.details.char_buffer<wchar_t>.{ctor}  flavor=IL rva=0x16CC
.method /* msclr.interop.details.char_buffer<wchar_t>.{ctor} */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ldc.i8    9223372036854775807
  IL_000A: bgt.un.s  0x7
  IL_000C: ldarg.1
  IL_000D: ldc.i4.2
  IL_000E: conv.i8
  IL_000F: mul
  IL_0010: stloc.0
  IL_0011: br.s      0xa
  IL_0013: ldc.i8    18446744073709551615
  IL_001C: stloc.0
  IL_001D: ldarg.0
  IL_001E: ldloc.0
  IL_001F: call      0x0600007B new[]
  IL_0024: stind.i8
  IL_0025: ldarg.0
  IL_0026: ret
}
// MethodDef 0x06000028  msclr.interop.marshal_as<class System::String ^,char *>  flavor=IL rva=0x1A28
.method /* msclr.interop.marshal_as<class System::String ^,char *> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: stloc.0
  IL_0003: ldloc.0
  IL_0004: brtrue.s  0x4
  IL_0006: ldnull
  IL_0007: stloc.2
  IL_0008: br.s      0x1b
  IL_000A: ldloc.0
  IL_000B: stloc.1
  IL_000C: ldloc.0
  IL_000D: ldind.i1
  IL_000E: brfalse.s 0x9
  IL_0010: ldloc.1
  IL_0011: ldc.i4.1
  IL_0012: conv.i8
  IL_0013: add
  IL_0014: stloc.1
  IL_0015: ldloc.1
  IL_0016: ldind.i1
  IL_0017: brtrue.s  0xf7
  IL_0019: ldloc.1
  IL_001A: ldloc.0
  IL_001B: sub
  IL_001C: stloc.3
  IL_001D: ldloc.0
  IL_001E: ldloc.3
  IL_001F: call      0x0600001F msclr.interop.details.InternalAnsiToStringHelper
  IL_0024: stloc.2
  IL_0025: ldloc.2
  IL_0026: ret
}
// MethodDef 0x06000029  msclr.interop._Marshal_as_impl<class System::String ^>  flavor=IL rva=0x19BC
.method /* msclr.interop._Marshal_as_impl<class System::String ^> */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: brtrue.s  0x2
  IL_0003: ldnull
  IL_0004: ret
  IL_0005: ldarg.1
  IL_0006: stloc.0
  IL_0007: ldarg.1
  IL_0008: ldind.i1
  IL_0009: brfalse.s 0x9
  IL_000B: ldloc.0
  IL_000C: ldc.i4.1
  IL_000D: conv.i8
  IL_000E: add
  IL_000F: stloc.0
  IL_0010: ldloc.0
  IL_0011: ldind.i1
  IL_0012: brtrue.s  0xf7
  IL_0014: ldloc.0
  IL_0015: ldarg.1
  IL_0016: sub
  IL_0017: stloc.1
  IL_0018: ldarg.1
  IL_0019: ldloc.1
  IL_001A: call      0x0600001F msclr.interop.details.InternalAnsiToStringHelper
  IL_001F: ret
}
// MethodDef 0x0600002A  new  flavor=IL rva=0x1090
.method /* new */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: ret
}
// MethodDef 0x0600002B  <CrtImplementationDetails>.ThrowNestedModuleLoadException  flavor=IL rva=0x3940
.method /* <CrtImplementationDetails>.ThrowNestedModuleLoadException */ cil managed { 
  IL_0000: ldstr     0x700001FB
  IL_0005: ldarg.0
  IL_0006: ldarg.1
  IL_0007: newobj    0x060000AE .ctor
  IL_000C: throw
  IL_000D: ret
}
// MethodDef 0x0600002C  <CrtImplementationDetails>.ThrowModuleLoadException  flavor=IL rva=0x32F0
.method /* <CrtImplementationDetails>.ThrowModuleLoadException */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: newobj    0x060000AC .ctor
  IL_0006: throw
  IL_0007: ret
}
// MethodDef 0x0600002D  <CrtImplementationDetails>.ThrowModuleLoadException  flavor=IL rva=0x3304
.method /* <CrtImplementationDetails>.ThrowModuleLoadException */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: newobj    0x060000AB .ctor
  IL_0007: throw
  IL_0008: ret
}
// MethodDef 0x0600002E  <CrtImplementationDetails>.RegisterModuleUninitializer  flavor=IL rva=0x3420
.method /* <CrtImplementationDetails>.RegisterModuleUninitializer */ cil managed { 
  IL_0000: ldsfld    0x0400026B
  IL_0005: ldarg.0
  IL_0006: call      0x060000B3 AddHandler
  IL_000B: ret
}
// MethodDef 0x0600002F  <CrtImplementationDetails>.FromGUID  flavor=IL rva=0x3438
.method /* <CrtImplementationDetails>.FromGUID */ cil managed { 
  IL_0000: ldloca.s  0x0
  IL_0002: ldarg.0
  IL_0003: ldind.i4
  IL_0004: ldarg.0
  IL_0005: ldc.i4.4
  IL_0006: conv.i8
  IL_0007: add
  IL_0008: ldind.u2
  IL_0009: ldarg.0
  IL_000A: ldc.i4.6
  IL_000B: conv.i8
  IL_000C: add
  IL_000D: ldind.u2
  IL_000E: ldarg.0
  IL_000F: ldc.i4.8
  IL_0010: conv.i8
  IL_0011: add
  IL_0012: ldind.u1
  IL_0013: ldarg.0
  IL_0014: ldc.i4.s  0x9
  IL_0016: conv.i8
  IL_0017: add
  IL_0018: ldind.u1
  IL_0019: ldarg.0
  IL_001A: ldc.i4.s  0xa
  IL_001C: conv.i8
  IL_001D: add
  IL_001E: ldind.u1
  IL_001F: ldarg.0
  IL_0020: ldc.i4.s  0xb
  IL_0022: conv.i8
  IL_0023: add
  IL_0024: ldind.u1
  IL_0025: ldarg.0
  IL_0026: ldc.i4.s  0xc
  IL_0028: conv.i8
  IL_0029: add
  IL_002A: ldind.u1
  IL_002B: ldarg.0
  IL_002C: ldc.i4.s  0xd
  IL_002E: conv.i8
  IL_002F: add
  IL_0030: ldind.u1
  IL_0031: ldarg.0
  IL_0032: ldc.i4.s  0xe
  IL_0034: conv.i8
  IL_0035: add
  IL_0036: ldind.u1
  IL_0037: ldarg.0
  IL_0038: ldc.i4.s  0xf
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: ldind.u1
  IL_003D: call      0x0A00005B
  IL_0042: ldloc.0
  IL_0043: ret
}
// MethodDef 0x06000030  __get_default_appdomain  flavor=IL rva=0x3488
.method /* __get_default_appdomain */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: conv.i8
  IL_0002: stloc.0
  IL_0003: ldsflda   0x04000056
  IL_0008: call      0x0600002F <CrtImplementationDetails>.FromGUID
  IL_000D: stloc.3
  IL_000E: ldsflda   0x04000055
  IL_0013: call      0x0600002F <CrtImplementationDetails>.FromGUID
  IL_0018: ldloc.3
  IL_0019: call      0x0A000039
  IL_001E: stloc.s   0x4
  IL_0020: ldloca.s  0x4
  IL_0022: call      0x0A00001D
  IL_0027: stloc.0
  IL_0028: leave.s   0xc
  IL_002A: call      0x0A000041
  IL_002F: stloc.1
  IL_0030: leave.s   0x0
  IL_0032: ldloc.1
  IL_0033: ldc.i4.0
  IL_0034: blt.s     0x1f
  IL_0036: ldloc.0
  IL_0037: ldind.i8
  IL_0038: ldc.i4.s  0x68
  IL_003A: conv.i8
  IL_003B: add
  IL_003C: ldind.i8
  IL_003D: stloc.2
  IL_003E: ldloc.0
  IL_003F: ldarg.0
  IL_0040: ldloc.2
  IL_0041: calli     0x11000044
  IL_0046: stloc.1
  IL_0047: ldloc.0
  IL_0048: dup
  IL_0049: ldind.i8
  IL_004A: ldc.i4.s  0x10
  IL_004C: conv.i8
  IL_004D: add
  IL_004E: ldind.i8
  IL_004F: calli     0x11000043
  IL_0054: pop
  IL_0055: ldloc.1
  IL_0056: ret
}
// MethodDef 0x06000031  __release_appdomain  flavor=IL rva=0x3508
.method /* __release_appdomain */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: dup
  IL_0002: ldind.i8
  IL_0003: ldc.i4.s  0x10
  IL_0005: conv.i8
  IL_0006: add
  IL_0007: ldind.i8
  IL_0008: calli     0x11000043
  IL_000D: pop
  IL_000E: ret
}
// MethodDef 0x06000032  <CrtImplementationDetails>.GetDefaultDomain  flavor=IL rva=0x3524
.method /* <CrtImplementationDetails>.GetDefaultDomain */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: conv.i8
  IL_0002: stloc.1
  IL_0003: ldloca.s  0x1
  IL_0005: call      0x06000030 __get_default_appdomain
  IL_000A: stloc.0
  IL_000B: ldloc.0
  IL_000C: ldc.i4.0
  IL_000D: blt.s     0x1d
  IL_000F: ldloca.s  0x3
  IL_0011: ldloc.1
  IL_0012: call      0x0A000049
  IL_0017: ldloc.3
  IL_0018: call      0x0A000042
  IL_001D: castclass 0x01000039
  IL_0022: stloc.2
  IL_0023: leave.s   0xf
  IL_0025: ldloc.1
  IL_0026: call      0x06000031 __release_appdomain
  IL_002B: endfinally
  IL_002C: ldloc.0
  IL_002D: call      0x0A000040
  IL_0032: ldnull
  IL_0033: ret
  IL_0034: ldloc.2
  IL_0035: ret
}
// MethodDef 0x06000033  <CrtImplementationDetails>.DoCallBackInDefaultDomain  flavor=IL rva=0x3584
.method /* <CrtImplementationDetails>.DoCallBackInDefaultDomain */ cil managed { 
  IL_0000: ldsflda   0x0400005B
  IL_0005: call      0x0600002F <CrtImplementationDetails>.FromGUID
  IL_000A: stloc.s   0x4
  IL_000C: ldsflda   0x0400005C
  IL_0011: call      0x0600002F <CrtImplementationDetails>.FromGUID
  IL_0016: ldloc.s   0x4
  IL_0018: call      0x0A000039
  IL_001D: stloc.s   0x5
  IL_001F: ldloca.s  0x5
  IL_0021: call      0x0A00001D
  IL_0026: stloc.0
  IL_0027: call      0x06000032 <CrtImplementationDetails>.GetDefaultDomain
  IL_002C: ldloc.0
  IL_002D: ldind.i8
  IL_002E: ldc.i4.s  0x40
  IL_0030: conv.i8
  IL_0031: add
  IL_0032: ldind.i8
  IL_0033: stloc.3
  IL_0034: call      0x0A000057
  IL_0039: stloc.2
  IL_003A: ldloc.0
  IL_003B: ldloc.2
  IL_003C: ldarg.0
  IL_003D: ldarg.1
  IL_003E: ldloc.3
  IL_003F: calli     0x11000045
  IL_0044: stloc.1
  IL_0045: ldloc.1
  IL_0046: ldc.i4.0
  IL_0047: bge.s     0x6
  IL_0049: ldloc.1
  IL_004A: call      0x0A000040
  IL_004F: leave.s   0xf
  IL_0051: ldloc.0
  IL_0052: dup
  IL_0053: ldind.i8
  IL_0054: ldc.i4.s  0x10
  IL_0056: conv.i8
  IL_0057: add
  IL_0058: ldind.i8
  IL_0059: calli     0x11000043
  IL_005E: pop
  IL_005F: endfinally
  IL_0060: ret
}
// MethodDef 0x06000034  __scrt_is_safe_for_managed_code  flavor=IL rva=0x363C
.method /* __scrt_is_safe_for_managed_code */ cil managed { 
  IL_0000: ldsfld    0x040000CB
  IL_0005: stloc.0
  IL_0006: ldloc.0
  IL_0007: brfalse.s 0x6
  IL_0009: ldloc.0
  IL_000A: ldc.i4.1
  IL_000B: beq.s     0x2
  IL_000D: ldc.i4.1
  IL_000E: ret
  IL_000F: ldc.i4.0
  IL_0010: ret
}
// MethodDef 0x06000035  <CrtImplementationDetails>.DefaultDomain.DoNothing  flavor=IL rva=0x3670
.method /* <CrtImplementationDetails>.DefaultDomain.DoNothing */ cil managed { 
  IL_0000: ldc.i4    0x7FFFFFFF
  IL_0005: box       0x0100003A
  IL_000A: call      0x0A000021
  IL_000F: ldc.i4.0
  IL_0010: ret
}
// MethodDef 0x06000036  <CrtImplementationDetails>.DefaultDomain.HasPerProcess  flavor=IL rva=0x3690
.method /* <CrtImplementationDetails>.DefaultDomain.HasPerProcess */ cil managed { 
  IL_0000: ldsfld    0x04000068
  IL_0005: ldc.i4.2
  IL_0006: bne.un.s  0x35
  IL_0008: ldsflda   0x04000071
  IL_000D: stloc.0
  IL_000E: ldsflda   0x04000071
  IL_0013: ldsflda   0x04000069
  IL_0018: bge.un.s  0x1b
  IL_001A: ldloc.0
  IL_001B: ldind.i8
  IL_001C: brtrue.s  0xf
  IL_001E: ldloc.0
  IL_001F: ldc.i4.8
  IL_0020: conv.i8
  IL_0021: add
  IL_0022: stloc.0
  IL_0023: ldloc.0
  IL_0024: ldsflda   0x04000069
  IL_0029: blt.un.s  0xef
  IL_002B: br.s      0x8
  IL_002D: ldc.i4.m1
  IL_002E: stsfld    0x04000068
  IL_0033: ldc.i4.1
  IL_0034: ret
  IL_0035: ldc.i4.0
  IL_0036: stsfld    0x04000068
  IL_003B: ldc.i4.0
  IL_003C: ret
  IL_003D: ldsfld    0x04000068
  IL_0042: ldc.i4.m1
  IL_0043: ceq
  IL_0045: conv.u1
  IL_0046: ret
}
// MethodDef 0x06000037  <CrtImplementationDetails>.DefaultDomain.HasNative  flavor=IL rva=0x36E4
.method /* <CrtImplementationDetails>.DefaultDomain.HasNative */ cil managed { 
  IL_0000: ldsfld    0x0400005F
  IL_0005: ldc.i4.2
  IL_0006: bne.un.s  0x62
  IL_0008: ldsflda   0x040000CA
  IL_000D: stloc.1
  IL_000E: ldsflda   0x040000CA
  IL_0013: ldsflda   0x040000C6
  IL_0018: bge.un.s  0x1b
  IL_001A: ldloc.1
  IL_001B: ldind.i8
  IL_001C: brtrue.s  0xf
  IL_001E: ldloc.1
  IL_001F: ldc.i4.8
  IL_0020: conv.i8
  IL_0021: add
  IL_0022: stloc.1
  IL_0023: ldloc.1
  IL_0024: ldsflda   0x040000C6
  IL_0029: blt.un.s  0xef
  IL_002B: br.s      0x8
  IL_002D: ldc.i4.m1
  IL_002E: stsfld    0x0400005F
  IL_0033: ldc.i4.1
  IL_0034: ret
  IL_0035: ldsflda   0x040000C9
  IL_003A: stloc.0
  IL_003B: ldsflda   0x040000C9
  IL_0040: ldsflda   0x040000CC
  IL_0045: bge.un.s  0x1b
  IL_0047: ldloc.0
  IL_0048: ldind.i8
  IL_0049: brtrue.s  0xf
  IL_004B: ldloc.0
  IL_004C: ldc.i4.8
  IL_004D: conv.i8
  IL_004E: add
  IL_004F: stloc.0
  IL_0050: ldloc.0
  IL_0051: ldsflda   0x040000CC
  IL_0056: blt.un.s  0xef
  IL_0058: br.s      0x8
  IL_005A: ldc.i4.m1
  IL_005B: stsfld    0x0400005F
  IL_0060: ldc.i4.1
  IL_0061: ret
  IL_0062: ldc.i4.0
  IL_0063: stsfld    0x0400005F
  IL_0068: ldc.i4.0
  IL_0069: ret
  IL_006A: ldsfld    0x0400005F
  IL_006F: ldc.i4.m1
  IL_0070: ceq
  IL_0072: conv.u1
  IL_0073: ret
}
// MethodDef 0x06000038  <CrtImplementationDetails>.DefaultDomain.NeedsInitialization  flavor=IL rva=0x3764
.method /* <CrtImplementationDetails>.DefaultDomain.NeedsInitialization */ cil managed { 
  IL_0000: call      0x06000036 <CrtImplementationDetails>.DefaultDomain.HasPerProcess
  IL_0005: brfalse.s 0x7
  IL_0007: ldsfld    0x04000060
  IL_000C: brfalse.s 0x15
  IL_000E: call      0x06000037 <CrtImplementationDetails>.DefaultDomain.HasNative
  IL_0013: brfalse.s 0x12
  IL_0015: ldsfld    0x04000066
  IL_001A: brtrue.s  0xb
  IL_001C: ldsfld    0x040000C7
  IL_0021: brtrue.s  0x4
  IL_0023: ldc.i4.1
  IL_0024: stloc.0
  IL_0025: br.s      0x2
  IL_0027: ldc.i4.0
  IL_0028: stloc.0
  IL_0029: ldloc.0
  IL_002A: conv.u1
  IL_002B: ret
}
// MethodDef 0x06000039  <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization  flavor=IL rva=0x379C
.method /* <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization */ cil managed { 
  IL_0000: ldsfld    0x0400005E
  IL_0005: ret
}
// MethodDef 0x0600003A  <CrtImplementationDetails>.DefaultDomain.Initialize  flavor=IL rva=0x37B0
.method /* <CrtImplementationDetails>.DefaultDomain.Initialize */ cil managed { 
  IL_0000: ldsfld    0x04000098
  IL_0005: ldc.i4.0
  IL_0006: conv.i8
  IL_0007: call      0x06000033 <CrtImplementationDetails>.DoCallBackInDefaultDomain
  IL_000C: ret
}
// MethodDef 0x0600003B  ?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ  flavor=IL rva=0x1000
.method /* ?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x04000062
  IL_0006: ret
}
// MethodDef 0x0600003C  ?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ  flavor=IL rva=0x1014
.method /* ?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x04000057
  IL_0006: ret
}
// MethodDef 0x0600003D  ?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ  flavor=IL rva=0x1028
.method /* ?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x04000064
  IL_0006: ret
}
// MethodDef 0x0600003E  ?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x103C
.method /* ?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x04000065
  IL_0006: ret
}
// MethodDef 0x0600003F  ?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x1050
.method /* ?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x04000059
  IL_0006: ret
}
// MethodDef 0x06000040  ?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x1064
.method /* ?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x04000067
  IL_0006: ret
}
// MethodDef 0x06000041  ?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x1078
.method /* ?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stsfld    0x0400005D
  IL_0006: ret
}
// MethodDef 0x06000042  <CrtImplementationDetails>.LanguageSupport.InitializeVtables  flavor=IL rva=0x3994
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeVtables */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldstr     0x7000041B
  IL_0006: call      0x06000053 gcroot<System::String ^>.=
  IL_000B: pop
  IL_000C: ldc.i4.1
  IL_000D: stsfld    0x04000065
  IL_0012: ldsflda   0x0400006F
  IL_0017: ldsflda   0x0400006A
  IL_001C: call      0x06000079 _initterm_m
  IL_0021: ldc.i4.2
  IL_0022: stsfld    0x04000065
  IL_0027: ret
}
// MethodDef 0x06000043  <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain  flavor=IL rva=0x39C8
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldstr     0x70000495
  IL_0006: call      0x06000053 gcroot<System::String ^>.=
  IL_000B: pop
  IL_000C: call      0x0600003A <CrtImplementationDetails>.DefaultDomain.Initialize
  IL_0011: ret
}
// MethodDef 0x06000044  <CrtImplementationDetails>.LanguageSupport.InitializeNative  flavor=IL rva=0x39E8
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeNative */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldstr     0x70000540
  IL_0006: call      0x06000053 gcroot<System::String ^>.=
  IL_000B: pop
  IL_000C: call      0x06000089 __security_init_cookie
  IL_0011: ldc.i4.1
  IL_0012: stsfld    0x04000066
  IL_0017: call      0x06000034 __scrt_is_safe_for_managed_code
  IL_001C: brtrue.s  0x5
  IL_001E: call      0x06000088 abort
  IL_0023: ldsfld    0x040000C7
  IL_0028: ldc.i4.1
  IL_0029: bne.un.s  0x5
  IL_002B: call      0x06000088 abort
  IL_0030: ldsfld    0x040000C7
  IL_0035: brtrue.s  0x49
  IL_0037: ldc.i4.1
  IL_0038: stsfld    0x04000059
  IL_003D: ldc.i4.1
  IL_003E: stsfld    0x040000C7
  IL_0043: ldsflda   0x040000CA
  IL_0048: ldsflda   0x040000C6
  IL_004D: call      0x06000076 _initterm_e
  IL_0052: brfalse.s 0xb
  IL_0054: ldarg.0
  IL_0055: call      0x06000052 gcroot<System::String ^>..PE$AAVString@System@@
  IL_005A: call      0x0600002C <CrtImplementationDetails>.ThrowModuleLoadException
  IL_005F: ldsflda   0x040000C9
  IL_0064: ldsflda   0x040000CC
  IL_0069: call      0x06000077 _initterm
  IL_006E: ldc.i4.2
  IL_006F: stsfld    0x040000C7
  IL_0074: ldc.i4.1
  IL_0075: stsfld    0x04000063
  IL_007A: ldc.i4.2
  IL_007B: stsfld    0x04000059
  IL_0080: ret
}
// MethodDef 0x06000045  <CrtImplementationDetails>.LanguageSupport.InitializePerProcess  flavor=IL rva=0x3A78
.method /* <CrtImplementationDetails>.LanguageSupport.InitializePerProcess */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldstr     0x700005BA
  IL_0006: call      0x06000053 gcroot<System::String ^>.=
  IL_000B: pop
  IL_000C: ldc.i4.1
  IL_000D: stsfld    0x04000067
  IL_0012: call      0x0600006D _initatexit_m
  IL_0017: pop
  IL_0018: ldsflda   0x04000071
  IL_001D: ldsflda   0x04000069
  IL_0022: call      0x06000079 _initterm_m
  IL_0027: ldc.i4.2
  IL_0028: stsfld    0x04000067
  IL_002D: ldc.i4.1
  IL_002E: stsfld    0x04000060
  IL_0033: ret
}
// MethodDef 0x06000046  <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain  flavor=IL rva=0x3AB8
.method /* <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldstr     0x70000636
  IL_0006: call      0x06000053 gcroot<System::String ^>.=
  IL_000B: pop
  IL_000C: ldc.i4.1
  IL_000D: stsfld    0x0400005D
  IL_0012: call      0x06000070 _initatexit_app_domain
  IL_0017: pop
  IL_0018: ldsflda   0x0400006C
  IL_001D: ldsflda   0x0400006D
  IL_0022: call      0x06000079 _initterm_m
  IL_0027: ldc.i4.2
  IL_0028: stsfld    0x0400005D
  IL_002D: ret
}
// MethodDef 0x06000047  <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer  flavor=IL rva=0x3AF4
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldstr     0x700006B6
  IL_0006: call      0x06000053 gcroot<System::String ^>.=
  IL_000B: pop
  IL_000C: ldnull
  IL_000D: ldftn     0x0600004C <CrtImplementationDetails>.LanguageSupport.DomainUnload
  IL_0013: newobj    0x0A00004A
  IL_0018: call      0x0600002E <CrtImplementationDetails>.RegisterModuleUninitializer
  IL_001D: ret
}
// MethodDef 0x06000048  <CrtImplementationDetails>.LanguageSupport._Initialize  flavor=IL rva=0x3B20
.method /* <CrtImplementationDetails>.LanguageSupport._Initialize */ cil managed { 
  IL_0000: call      0x0A000056
  IL_0005: call      0x0A000055
  IL_000A: stsfld    0x04000064
  IL_000F: ldsfld    0x04000064
  IL_0014: ldc.i4.0
  IL_0015: bne.un.s  0x7
  IL_0017: ldsfld    0x0400005E
  IL_001C: br.s      0x1
  IL_001E: ldc.i4.1
  IL_001F: stsfld    0x0400005E
  IL_0024: call      0x06000085 _getFiberPtrId
  IL_0029: stloc.s   0x4
  IL_002B: ldc.i4.0
  IL_002C: stloc.3
  IL_002D: ldc.i4.0
  IL_002E: stloc.0
  IL_002F: ldc.i4.0
  IL_0030: stloc.1
  IL_0031: call      0x0A000044
  IL_0036: ldloc.0
  IL_0037: brtrue.s  0x31
  IL_0039: leave.s   0x20
  IL_003B: ldsflda   0x040000C8
  IL_0040: ldloc.s   0x4
  IL_0042: ldc.i4.0
  IL_0043: conv.i8
  IL_0044: call      0x0A000036
  IL_0049: stloc.2
  IL_004A: ldloc.2
  IL_004B: brtrue.s  0x4
  IL_004D: ldc.i4.1
  IL_004E: stloc.0
  IL_004F: br.s      0x9
  IL_0051: ldloc.2
  IL_0052: ldloc.s   0x4
  IL_0054: bne.un.s  0x4
  IL_0056: ldc.i4.1
  IL_0057: stloc.3
  IL_0058: ldc.i4.1
  IL_0059: stloc.0
  IL_005A: endfinally
  IL_005B: ldloc.0
  IL_005C: brtrue.s  0xa
  IL_005E: ldc.i4    0x000003E8
  IL_0063: call      0x06000087 Sleep
  IL_0068: br.s      0xcc
  IL_006A: ldarg.0
  IL_006B: call      0x06000042 <CrtImplementationDetails>.LanguageSupport.InitializeVtables
  IL_0070: ldsfld    0x04000064
  IL_0075: brfalse.s 0xe
  IL_0077: ldarg.0
  IL_0078: call      0x06000044 <CrtImplementationDetails>.LanguageSupport.InitializeNative
  IL_007D: ldarg.0
  IL_007E: call      0x06000045 <CrtImplementationDetails>.LanguageSupport.InitializePerProcess
  IL_0083: br.s      0xd
  IL_0085: call      0x06000038 <CrtImplementationDetails>.DefaultDomain.NeedsInitialization
  IL_008A: ldc.i4.0
  IL_008B: bne.un.s  0x3
  IL_008D: ldloc.1
  IL_008E: br.s      0x1
  IL_0090: ldc.i4.1
  IL_0091: stloc.1
  IL_0092: leave.s   0x11
  IL_0094: ldloc.3
  IL_0095: brtrue.s  0xd
  IL_0097: ldsflda   0x040000C8
  IL_009C: ldc.i4.0
  IL_009D: conv.i8
  IL_009E: call      0x0A000034
  IL_00A3: pop
  IL_00A4: endfinally
  IL_00A5: ldloc.1
  IL_00A6: brfalse.s 0x6
  IL_00A8: ldarg.0
  IL_00A9: call      0x06000043 <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain
  IL_00AE: ldarg.0
  IL_00AF: call      0x06000046 <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain
  IL_00B4: ldc.i4.1
  IL_00B5: stsfld    0x04000062
  IL_00BA: ldarg.0
  IL_00BB: call      0x06000047 <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer
  IL_00C0: ret
}
// MethodDef 0x06000049  <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain  flavor=IL rva=0x37CC
.method /* <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain */ cil managed { 
  IL_0000: call      0x06000071 _app_exit_callback
  IL_0005: ret
}
// MethodDef 0x0600004A  <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain  flavor=IL rva=0x37E0
.method /* <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain */ cil managed { 
  IL_0000: call      0x0600006C _exit_callback
  IL_0005: ldc.i4.0
  IL_0006: stsfld    0x04000060
  IL_000B: ldsfld    0x04000063
  IL_0010: brfalse.s 0x11
  IL_0012: call      0x06000086 _cexit
  IL_0017: ldc.i4.0
  IL_0018: stsfld    0x040000C7
  IL_001D: ldc.i4.0
  IL_001E: stsfld    0x04000063
  IL_0023: ldc.i4.0
  IL_0024: stsfld    0x04000066
  IL_0029: ldc.i4.0
  IL_002A: ret
}
// MethodDef 0x0600004B  <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain  flavor=IL rva=0x3818
.method /* <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain */ cil managed { 
  IL_0000: call      0x06000039 <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization
  IL_0005: brfalse.s 0x22
  IL_0007: call      0x0A000056
  IL_000C: call      0x0A000055
  IL_0011: brfalse.s 0xa
  IL_0013: ldc.i4.0
  IL_0014: conv.i8
  IL_0015: call      0x0600004A <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain
  IL_001A: pop
  IL_001B: br.s      0xc
  IL_001D: ldsfld    0x04000099
  IL_0022: ldc.i4.0
  IL_0023: conv.i8
  IL_0024: call      0x06000033 <CrtImplementationDetails>.DoCallBackInDefaultDomain
  IL_0029: ret
}
// MethodDef 0x0600004C  <CrtImplementationDetails>.LanguageSupport.DomainUnload  flavor=IL rva=0x3850
.method /* <CrtImplementationDetails>.LanguageSupport.DomainUnload */ cil managed { 
  IL_0000: ldsfld    0x04000062
  IL_0005: brfalse.s 0x27
  IL_0007: ldsflda   0x04000057
  IL_000C: ldc.i4.1
  IL_000D: call      0x0A000035
  IL_0012: brtrue.s  0x1a
  IL_0014: ldsflda   0x04000061
  IL_0019: call      0x0A000033
  IL_001E: ldc.i4.0
  IL_001F: ceq
  IL_0021: call      0x06000049 <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain
  IL_0026: conv.u1
  IL_0027: brfalse.s 0x5
  IL_0029: call      0x0600004B <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain
  IL_002E: ret
}
// MethodDef 0x0600004D  <CrtImplementationDetails>.LanguageSupport.Cleanup  flavor=IL rva=0x3C24
.method /* <CrtImplementationDetails>.LanguageSupport.Cleanup */ cil managed { 
  IL_0000: ldsflda   0x04000061
  IL_0005: call      0x0A000033
  IL_000A: ldc.i4.0
  IL_000B: ceq
  IL_000D: conv.u1
  IL_000E: stloc.1
  IL_000F: call      0x06000049 <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain
  IL_0014: ldloc.1
  IL_0015: brfalse.s 0x5
  IL_0017: call      0x0600004B <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain
  IL_001C: leave.s   0x14
  IL_001E: stloc.0
  IL_001F: ldarg.1
  IL_0020: ldloc.0
  IL_0021: call      0x0600002B <CrtImplementationDetails>.ThrowNestedModuleLoadException
  IL_0026: leave.s   0xa
  IL_0028: stloc.2
  IL_0029: ldarg.1
  IL_002A: ldnull
  IL_002B: call      0x0600002B <CrtImplementationDetails>.ThrowNestedModuleLoadException
  IL_0030: leave.s   0x0
  IL_0032: ret
}
// MethodDef 0x0600004E  <CrtImplementationDetails>.LanguageSupport.{ctor}  flavor=IL rva=0x3C98
.method /* <CrtImplementationDetails>.LanguageSupport.{ctor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000055 gcroot<System::String ^>.{ctor}
  IL_0006: pop
  IL_0007: ldarg.0
  IL_0008: ret
}
// MethodDef 0x0600004F  <CrtImplementationDetails>.LanguageSupport.{dtor}  flavor=IL rva=0x3CB0
.method /* <CrtImplementationDetails>.LanguageSupport.{dtor} */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000054 gcroot<System::String ^>.{dtor}
  IL_0006: ret
}
// MethodDef 0x06000050  <CrtImplementationDetails>.LanguageSupport.Initialize  flavor=IL rva=0x3CC4
.method /* <CrtImplementationDetails>.LanguageSupport.Initialize */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.0
  IL_0002: call      0x0A000044
  IL_0007: ldarg.0
  IL_0008: ldstr     0x7000074B
  IL_000D: call      0x06000053 gcroot<System::String ^>.=
  IL_0012: pop
  IL_0013: call      0x0A000044
  IL_0018: leave.s   0xe
  IL_001A: ldsflda   0x04000061
  IL_001F: call      0x0A000032
  IL_0024: pop
  IL_0025: ldc.i4.1
  IL_0026: stloc.0
  IL_0027: endfinally
  IL_0028: ldarg.0
  IL_0029: call      0x06000048 <CrtImplementationDetails>.LanguageSupport._Initialize
  IL_002E: leave.s   0x32
  IL_0030: stloc.1
  IL_0031: ldloc.0
  IL_0032: brfalse.s 0x7
  IL_0034: ldarg.0
  IL_0035: ldloc.1
  IL_0036: call      0x0600004D <CrtImplementationDetails>.LanguageSupport.Cleanup
  IL_003B: ldarg.0
  IL_003C: call      0x06000052 gcroot<System::String ^>..PE$AAVString@System@@
  IL_0041: ldloc.1
  IL_0042: call      0x0600002D <CrtImplementationDetails>.ThrowModuleLoadException
  IL_0047: leave.s   0x19
  IL_0049: stloc.2
  IL_004A: ldloc.0
  IL_004B: brfalse.s 0x7
  IL_004D: ldarg.0
  IL_004E: ldnull
  IL_004F: call      0x0600004D <CrtImplementationDetails>.LanguageSupport.Cleanup
  IL_0054: ldarg.0
  IL_0055: call      0x06000052 gcroot<System::String ^>..PE$AAVString@System@@
  IL_005A: ldnull
  IL_005B: call      0x0600002D <CrtImplementationDetails>.ThrowModuleLoadException
  IL_0060: leave.s   0x0
  IL_0062: ret
}
// MethodDef 0x06000051  .cctor  flavor=IL rva=0x3D80
.method /* .cctor */ cil managed { 
  IL_0000: ldloca.s  0x0
  IL_0002: call      0x0600004E <CrtImplementationDetails>.LanguageSupport.{ctor}
  IL_0007: pop
  IL_0008: ldloca.s  0x0
  IL_000A: call      0x06000050 <CrtImplementationDetails>.LanguageSupport.Initialize
  IL_000F: leave.s   0xe
  IL_0011: ldftn     0x0600004F <CrtImplementationDetails>.LanguageSupport.{dtor}
  IL_0017: ldloca.s  0x0
  IL_0019: call      0x06000056 ___CxxCallUnwindDtor
  IL_001E: endfinally
  IL_001F: ldloca.s  0x0
  IL_0021: call      0x0600004F <CrtImplementationDetails>.LanguageSupport.{dtor}
  IL_0026: ret
}
// MethodDef 0x06000052  gcroot<System::String ^>..PE$AAVString@System@@  flavor=IL rva=0x388C
.method /* gcroot<System::String ^>..PE$AAVString@System@@ */ cil managed { 
  IL_0000: ldloca.s  0x0
  IL_0002: ldarg.0
  IL_0003: ldind.i8
  IL_0004: call      0x0A000049
  IL_0009: ldloc.0
  IL_000A: call      0x0A00003C
  IL_000F: stloc.1
  IL_0010: ldloca.s  0x1
  IL_0012: call      0x0A00003E
  IL_0017: ret
}
// MethodDef 0x06000053  gcroot<System::String ^>.=  flavor=IL rva=0x38B0
.method /* gcroot<System::String ^>.= */ cil managed { 
  IL_0000: ldloca.s  0x0
  IL_0002: ldarg.0
  IL_0003: ldind.i8
  IL_0004: call      0x0A000049
  IL_0009: ldloc.0
  IL_000A: call      0x0A00003C
  IL_000F: stloc.1
  IL_0010: ldloca.s  0x1
  IL_0012: ldarg.1
  IL_0013: call      0x0A00003F
  IL_0018: ldarg.0
  IL_0019: ret
}
// MethodDef 0x06000054  gcroot<System::String ^>.{dtor}  flavor=IL rva=0x38D8
.method /* gcroot<System::String ^>.{dtor} */ cil managed { 
  IL_0000: ldloca.s  0x0
  IL_0002: ldarg.0
  IL_0003: ldind.i8
  IL_0004: call      0x0A000049
  IL_0009: ldloc.0
  IL_000A: call      0x0A00003C
  IL_000F: stloc.1
  IL_0010: ldloca.s  0x1
  IL_0012: call      0x0A00003B
  IL_0017: ldarg.0
  IL_0018: ldc.i4.0
  IL_0019: conv.i8
  IL_001A: stind.i8
  IL_001B: ret
}
// MethodDef 0x06000055  gcroot<System::String ^>.{ctor}  flavor=IL rva=0x3900
.method /* gcroot<System::String ^>.{ctor} */ cil managed { 
  IL_0000: ldnull
  IL_0001: call      0x0A00003A
  IL_0006: call      0x0A00003D
  IL_000B: stloc.0
  IL_000C: ldarg.0
  IL_000D: ldloca.s  0x0
  IL_000F: call      0x0A00001D
  IL_0014: stind.i8
  IL_0015: ldarg.0
  IL_0016: ret
}
// MethodDef 0x06000056  ___CxxCallUnwindDtor  flavor=IL rva=0x3E08
.method /* ___CxxCallUnwindDtor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: stloc.0
  IL_0002: ldarg.1
  IL_0003: ldloc.0
  IL_0004: calli     0x11000075
  IL_0009: leave.s   0x10
  IL_000B: pop
  IL_000C: call      0x0A000062
  IL_0011: call      0x0600008A __FrameUnwindFilter
  IL_0016: endfilter
  IL_0018: pop
  IL_0019: leave.s   0x0
  IL_001B: ret
}
// MethodDef 0x06000057  ___CxxCallUnwindDelDtor  flavor=IL rva=0x3E4C
.method /* ___CxxCallUnwindDelDtor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: stloc.0
  IL_0002: ldarg.1
  IL_0003: ldloc.0
  IL_0004: calli     0x11000075
  IL_0009: leave.s   0x10
  IL_000B: pop
  IL_000C: call      0x0A000062
  IL_0011: call      0x0600008A __FrameUnwindFilter
  IL_0016: endfilter
  IL_0018: pop
  IL_0019: leave.s   0x0
  IL_001B: ret
}
// MethodDef 0x06000058  ___CxxCallUnwindVecDtor  flavor=IL rva=0x3E90
.method /* ___CxxCallUnwindVecDtor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: stloc.0
  IL_0002: ldarg.1
  IL_0003: ldarg.2
  IL_0004: ldarg.3
  IL_0005: ldarg.s   0x4
  IL_0007: ldloc.0
  IL_0008: calli     0x11000076
  IL_000D: leave.s   0x10
  IL_000F: pop
  IL_0010: call      0x0A000062
  IL_0015: call      0x0600008A __FrameUnwindFilter
  IL_001A: endfilter
  IL_001C: pop
  IL_001D: leave.s   0x0
  IL_001F: ret
}
// MethodDef 0x06000059  __ehvec_dtor  flavor=IL rva=0x3F7C
.method /* __ehvec_dtor */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.0
  IL_0002: ldarg.1
  IL_0003: ldarg.2
  IL_0004: mul
  IL_0005: ldarg.0
  IL_0006: add
  IL_0007: starg.s   0x0
  IL_0009: ldarg.2
  IL_000A: ldarg.2
  IL_000B: ldc.i4.1
  IL_000C: conv.i8
  IL_000D: sub
  IL_000E: starg.s   0x2
  IL_0010: ldc.i4.0
  IL_0011: conv.i8
  IL_0012: ble.un.s  0x10
  IL_0014: ldarg.0
  IL_0015: ldarg.1
  IL_0016: sub
  IL_0017: starg.s   0x0
  IL_0019: ldarg.3
  IL_001A: stloc.1
  IL_001B: ldarg.0
  IL_001C: ldloc.1
  IL_001D: calli     0x11000075
  IL_0022: br.s      0xe5
  IL_0024: ldc.i4.1
  IL_0025: stloc.0
  IL_0026: leave.s   0xd
  IL_0028: ldloc.0
  IL_0029: brtrue.s  0x9
  IL_002B: ldarg.0
  IL_002C: ldarg.1
  IL_002D: ldarg.2
  IL_002E: ldarg.3
  IL_002F: call      0x0600005B __ArrayUnwind
  IL_0034: endfinally
  IL_0035: ret
}
// MethodDef 0x0600005A  ?A0x9c83a709.ArrayUnwindFilter  flavor=IL rva=0x3EEC
.method /* ?A0x9c83a709.ArrayUnwindFilter */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldind.i8
  IL_0002: stloc.0
  IL_0003: ldloc.0
  IL_0004: ldind.i4
  IL_0005: ldc.i4    0xE06D7363
  IL_000A: beq.s     0x2
  IL_000C: ldc.i4.0
  IL_000D: ret
  IL_000E: call      0x0600008D __current_exception
  IL_0013: ldloc.0
  IL_0014: stind.i8
  IL_0015: ldarg.0
  IL_0016: ldc.i4.8
  IL_0017: conv.i8
  IL_0018: add
  IL_0019: ldind.i8
  IL_001A: stloc.1
  IL_001B: call      0x0600008B __current_exception_context
  IL_0020: ldloc.1
  IL_0021: stind.i8
  IL_0022: call      0x0600008C terminate
  IL_0027: ldc.i4.0
  IL_0028: ret
}
// MethodDef 0x0600005B  __ArrayUnwind  flavor=IL rva=0x3F24
.method /* __ArrayUnwind */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: conv.i8
  IL_0002: stloc.0
  IL_0003: ldloc.0
  IL_0004: ldarg.2
  IL_0005: beq.s     0x15
  IL_0007: ldarg.0
  IL_0008: ldarg.1
  IL_0009: sub
  IL_000A: starg.s   0x0
  IL_000C: ldarg.3
  IL_000D: stloc.1
  IL_000E: ldarg.0
  IL_000F: ldloc.1
  IL_0010: calli     0x11000075
  IL_0015: ldloc.0
  IL_0016: ldc.i4.1
  IL_0017: conv.i8
  IL_0018: add
  IL_0019: stloc.0
  IL_001A: br.s      0xe7
  IL_001C: leave.s   0x10
  IL_001E: pop
  IL_001F: call      0x0A000062
  IL_0024: call      0x0600005A ?A0x9c83a709.ArrayUnwindFilter
  IL_0029: endfilter
  IL_002B: pop
  IL_002C: leave.s   0x0
  IL_002E: ret
}
// MethodDef 0x0600005C  __ehvec_dtor  flavor=IL rva=0x3FDC
.method /* __ehvec_dtor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: conv.i8
  IL_0004: ldarg.3
  IL_0005: call      0x06000059 __ehvec_dtor
  IL_000A: ret
}
// MethodDef 0x0600005D  <CrtImplementationDetails>.AtExitLock._handle  flavor=IL rva=0x4008
.method /* <CrtImplementationDetails>.AtExitLock._handle */ cil managed { 
  IL_0000: ldsfld    0x040000A4
  IL_0005: brfalse.s 0x18
  IL_0007: ldloca.s  0x0
  IL_0009: ldsfld    0x040000A4
  IL_000E: call      0x0A000049
  IL_0013: ldloc.0
  IL_0014: call      0x0A000065
  IL_0019: box       0x01000042
  IL_001E: ret
  IL_001F: ldnull
  IL_0020: ret
}
// MethodDef 0x0600005E  <CrtImplementationDetails>.AtExitLock._lock_Construct  flavor=IL rva=0x4500
.method /* <CrtImplementationDetails>.AtExitLock._lock_Construct */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: conv.i8
  IL_0002: stsfld    0x040000A4
  IL_0007: ldarg.0
  IL_0008: call      0x0600005F <CrtImplementationDetails>.AtExitLock._lock_Set
  IL_000D: ret
}
// MethodDef 0x0600005F  <CrtImplementationDetails>.AtExitLock._lock_Set  flavor=IL rva=0x4038
.method /* <CrtImplementationDetails>.AtExitLock._lock_Set */ cil managed { 
  IL_0000: call      0x0600005D <CrtImplementationDetails>.AtExitLock._handle
  IL_0005: stloc.0
  IL_0006: ldloc.0
  IL_0007: brtrue.s  0x2b
  IL_0009: ldarg.0
  IL_000A: call      0x0A00003A
  IL_000F: box       0x01000042
  IL_0014: stloc.0
  IL_0015: ldloc.0
  IL_0016: unbox     0x01000042
  IL_001B: ldobj     0x01000042
  IL_0020: call      0x0A000066
  IL_0025: stloc.1
  IL_0026: ldloca.s  0x1
  IL_0028: call      0x0A00001D
  IL_002D: stsfld    0x040000A4
  IL_0032: br.s      0xc
  IL_0034: ldloc.0
  IL_0035: unbox     0x01000042
  IL_003A: ldarg.0
  IL_003B: call      0x0A00003F
  IL_0040: ret
}
// MethodDef 0x06000060  <CrtImplementationDetails>.AtExitLock._lock_Get  flavor=IL rva=0x4088
.method /* <CrtImplementationDetails>.AtExitLock._lock_Get */ cil managed { 
  IL_0000: call      0x0600005D <CrtImplementationDetails>.AtExitLock._handle
  IL_0005: stloc.0
  IL_0006: ldloc.0
  IL_0007: brfalse.s 0xc
  IL_0009: ldloc.0
  IL_000A: unbox     0x01000042
  IL_000F: call      0x0A00003E
  IL_0014: ret
  IL_0015: ldnull
  IL_0016: ret
}
// MethodDef 0x06000061  <CrtImplementationDetails>.AtExitLock._lock_Destruct  flavor=IL rva=0x40AC
.method /* <CrtImplementationDetails>.AtExitLock._lock_Destruct */ cil managed { 
  IL_0000: call      0x0600005D <CrtImplementationDetails>.AtExitLock._handle
  IL_0005: stloc.0
  IL_0006: ldloc.0
  IL_0007: brfalse.s 0x12
  IL_0009: ldloc.0
  IL_000A: unbox     0x01000042
  IL_000F: call      0x0A00003B
  IL_0014: ldc.i4.0
  IL_0015: conv.i8
  IL_0016: stsfld    0x040000A4
  IL_001B: ret
}
// MethodDef 0x06000062  <CrtImplementationDetails>.AtExitLock.IsInitialized  flavor=IL rva=0x40D4
.method /* <CrtImplementationDetails>.AtExitLock.IsInitialized */ cil managed { 
  IL_0000: call      0x06000060 <CrtImplementationDetails>.AtExitLock._lock_Get
  IL_0005: ldnull
  IL_0006: bne.un.s  0x3
  IL_0008: ldc.i4.0
  IL_0009: br.s      0x1
  IL_000B: ldc.i4.1
  IL_000C: conv.u1
  IL_000D: ret
}
// MethodDef 0x06000063  <CrtImplementationDetails>.AtExitLock.AddRef  flavor=IL rva=0x451C
.method /* <CrtImplementationDetails>.AtExitLock.AddRef */ cil managed { 
  IL_0000: call      0x06000062 <CrtImplementationDetails>.AtExitLock.IsInitialized
  IL_0005: brtrue.s  0x10
  IL_0007: newobj    0x0A000023
  IL_000C: call      0x0600005E <CrtImplementationDetails>.AtExitLock._lock_Construct
  IL_0011: ldc.i4.0
  IL_0012: stsfld    0x040000A5
  IL_0017: ldsfld    0x040000A5
  IL_001C: ldc.i4.1
  IL_001D: add
  IL_001E: stsfld    0x040000A5
  IL_0023: ret
}
// MethodDef 0x06000064  <CrtImplementationDetails>.AtExitLock.RemoveRef  flavor=IL rva=0x40F0
.method /* <CrtImplementationDetails>.AtExitLock.RemoveRef */ cil managed { 
  IL_0000: ldsfld    0x040000A5
  IL_0005: ldc.i4.m1
  IL_0006: add
  IL_0007: stsfld    0x040000A5
  IL_000C: ldsfld    0x040000A5
  IL_0011: brtrue.s  0x5
  IL_0013: call      0x06000061 <CrtImplementationDetails>.AtExitLock._lock_Destruct
  IL_0018: ret
}
// MethodDef 0x06000065  <CrtImplementationDetails>.AtExitLock.Enter  flavor=IL rva=0x4118
.method /* <CrtImplementationDetails>.AtExitLock.Enter */ cil managed { 
  IL_0000: call      0x06000060 <CrtImplementationDetails>.AtExitLock._lock_Get
  IL_0005: call      0x0A000064
  IL_000A: ret
}
// MethodDef 0x06000066  <CrtImplementationDetails>.AtExitLock.Exit  flavor=IL rva=0x4130
.method /* <CrtImplementationDetails>.AtExitLock.Exit */ cil managed { 
  IL_0000: call      0x06000060 <CrtImplementationDetails>.AtExitLock._lock_Get
  IL_0005: call      0x0A000038
  IL_000A: ret
}
// MethodDef 0x06000067  ?A0xdf32f105.__global_lock  flavor=IL rva=0x4148
.method /* ?A0xdf32f105.__global_lock */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.0
  IL_0002: call      0x06000062 <CrtImplementationDetails>.AtExitLock.IsInitialized
  IL_0007: brfalse.s 0x7
  IL_0009: call      0x06000065 <CrtImplementationDetails>.AtExitLock.Enter
  IL_000E: ldc.i4.1
  IL_000F: stloc.0
  IL_0010: ldloc.0
  IL_0011: ret
}
// MethodDef 0x06000068  ?A0xdf32f105.__global_unlock  flavor=IL rva=0x4168
.method /* ?A0xdf32f105.__global_unlock */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.0
  IL_0002: call      0x06000062 <CrtImplementationDetails>.AtExitLock.IsInitialized
  IL_0007: brfalse.s 0x7
  IL_0009: call      0x06000066 <CrtImplementationDetails>.AtExitLock.Exit
  IL_000E: ldc.i4.1
  IL_000F: stloc.0
  IL_0010: ldloc.0
  IL_0011: ret
}
// MethodDef 0x06000069  ?A0xdf32f105.__alloc_global_lock  flavor=IL rva=0x454C
.method /* ?A0xdf32f105.__alloc_global_lock */ cil managed { 
  IL_0000: call      0x06000063 <CrtImplementationDetails>.AtExitLock.AddRef
  IL_0005: call      0x06000062 <CrtImplementationDetails>.AtExitLock.IsInitialized
  IL_000A: ret
}
// MethodDef 0x0600006A  ?A0xdf32f105.__dealloc_global_lock  flavor=IL rva=0x4188
.method /* ?A0xdf32f105.__dealloc_global_lock */ cil managed { 
  IL_0000: call      0x06000064 <CrtImplementationDetails>.AtExitLock.RemoveRef
  IL_0005: ret
}
// MethodDef 0x0600006B  _atexit_helper  flavor=IL rva=0x419C
.method /* _atexit_helper */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: conv.i8
  IL_0002: stloc.s   0x6
  IL_0004: ldarg.0
  IL_0005: brtrue.s  0x2
  IL_0007: ldc.i4.m1
  IL_0008: ret
  IL_0009: call      0x06000067 ?A0xdf32f105.__global_lock
  IL_000E: ldc.i4.1
  IL_000F: bne.un    0x000000FF
  IL_0014: ldarg.3
  IL_0015: ldind.i8
  IL_0016: call      0x06000074 DecodePointer
  IL_001B: stloc.1
  IL_001C: ldarg.2
  IL_001D: ldind.i8
  IL_001E: call      0x06000074 DecodePointer
  IL_0023: stloc.0
  IL_0024: ldloc.0
  IL_0025: ldloc.1
  IL_0026: sub
  IL_0027: stloc.s   0x5
  IL_0029: ldarg.1
  IL_002A: ldind.i8
  IL_002B: ldc.i4.1
  IL_002C: conv.i8
  IL_002D: sub
  IL_002E: ldloc.s   0x5
  IL_0030: ldc.i4.3
  IL_0031: shr.un
  IL_0032: bge.un    0x000000AD
  IL_0037: ldarg.1
  IL_0038: ldind.i8
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: mul
  IL_003C: stloc.3
  IL_003D: ldloc.3
  IL_003E: ldc.i4    0x00001000
  IL_0043: conv.i8
  IL_0044: blt.un.s  0x8
  IL_0046: ldc.i4    0x00001000
  IL_004B: conv.i8
  IL_004C: br.s      0x1
  IL_004E: ldloc.3
  IL_004F: stloc.s   0xc
  IL_0051: ldloca.s  0xb
  IL_0053: ldloc.3
  IL_0054: ldloc.s   0xc
  IL_0056: add
  IL_0057: conv.i4
  IL_0058: call      0x0A000069
  IL_005D: ldloca.s  0xa
  IL_005F: ldloc.1
  IL_0060: call      0x0A000049
  IL_0065: ldloc.s   0xa
  IL_0067: ldloc.s   0xb
  IL_0069: call      0x0A000068
  IL_006E: stloc.s   0xe
  IL_0070: ldloca.s  0xe
  IL_0072: call      0x0A00001D
  IL_0077: ldloc.s   0x5
  IL_0079: add
  IL_007A: stloc.0
  IL_007B: ldloca.s  0xe
  IL_007D: call      0x0A00001D
  IL_0082: stloc.1
  IL_0083: ldarg.1
  IL_0084: ldind.i8
  IL_0085: stloc.2
  IL_0086: ldc.i4    0x00000200
  IL_008B: conv.i8
  IL_008C: ldloc.2
  IL_008D: blt.un.s  0x3
  IL_008F: ldloc.2
  IL_0090: br.s      0x6
  IL_0092: ldc.i4    0x00000200
  IL_0097: conv.i8
  IL_0098: stloc.s   0x9
  IL_009A: ldarg.1
  IL_009B: ldloc.2
  IL_009C: ldloc.s   0x9
  IL_009E: add
  IL_009F: stind.i8
  IL_00A0: leave.s   0x42
  IL_00A2: pop
  IL_00A3: ldloca.s  0x8
  IL_00A5: ldarg.1
  IL_00A6: ldind.i8
  IL_00A7: ldc.i4.8
  IL_00A8: conv.i8
  IL_00A9: mul
  IL_00AA: ldc.i4.s  0xc
  IL_00AC: conv.i8
  IL_00AD: add
  IL_00AE: conv.i4
  IL_00AF: call      0x0A000069
  IL_00B4: ldloca.s  0x7
  IL_00B6: ldloc.1
  IL_00B7: call      0x0A000049
  IL_00BC: ldloc.s   0x7
  IL_00BE: ldloc.s   0x8
  IL_00C0: call      0x0A000068
  IL_00C5: stloc.s   0xd
  IL_00C7: ldloca.s  0xd
  IL_00C9: call      0x0A00001D
  IL_00CE: ldloc.1
  IL_00CF: sub
  IL_00D0: ldloc.0
  IL_00D1: add
  IL_00D2: stloc.0
  IL_00D3: ldloca.s  0xd
  IL_00D5: call      0x0A00001D
  IL_00DA: stloc.1
  IL_00DB: ldarg.1
  IL_00DC: dup
  IL_00DD: ldind.i8
  IL_00DE: ldc.i4.4
  IL_00DF: conv.i8
  IL_00E0: add
  IL_00E1: stind.i8
  IL_00E2: leave.s   0x0
  IL_00E4: ldloc.0
  IL_00E5: ldarg.0
  IL_00E6: stind.i8
  IL_00E7: ldloc.0
  IL_00E8: ldc.i4.8
  IL_00E9: conv.i8
  IL_00EA: add
  IL_00EB: stloc.0
  IL_00EC: ldarg.0
  IL_00ED: stloc.s   0x6
  IL_00EF: ldarg.3
  IL_00F0: ldloc.1
  IL_00F1: call      0x06000075 EncodePointer
  IL_00F6: stind.i8
  IL_00F7: ldarg.2
  IL_00F8: ldloc.0
  IL_00F9: call      0x06000075 EncodePointer
  IL_00FE: stind.i8
  IL_00FF: leave.s   0x5
  IL_0101: pop
  IL_0102: leave.s   0x0
  IL_0104: leave.s   0x9
  IL_0106: leave.s   0x7
  IL_0108: call      0x06000068 ?A0xdf32f105.__global_unlock
  IL_010D: pop
  IL_010E: endfinally
  IL_010F: ldloc.s   0x6
  IL_0111: brtrue.s  0x5
  IL_0113: ldc.i4.m1
  IL_0114: stloc.s   0x4
  IL_0116: br.s      0x3
  IL_0118: ldc.i4.0
  IL_0119: stloc.s   0x4
  IL_011B: ldloc.s   0x4
  IL_011D: ret
}
// MethodDef 0x0600006C  _exit_callback  flavor=IL rva=0x4314
.method /* _exit_callback */ cil managed { 
  IL_0000: ldsfld    0x040000A2
  IL_0005: brfalse   0x00000097
  IL_000A: ldsfld    0x040000A1
  IL_000F: call      0x06000074 DecodePointer
  IL_0014: stloc.1
  IL_0015: ldsfld    0x040000A6
  IL_001A: call      0x06000074 DecodePointer
  IL_001F: stloc.0
  IL_0020: ldloc.1
  IL_0021: ldc.i8    18446744073709551615
  IL_002A: beq.s     0x70
  IL_002C: ldloc.1
  IL_002D: brfalse.s 0x6d
  IL_002F: ldloc.0
  IL_0030: brfalse.s 0x6a
  IL_0032: ldloc.1
  IL_0033: stloc.s   0x5
  IL_0035: ldloc.0
  IL_0036: stloc.s   0x4
  IL_0038: ldloc.0
  IL_0039: ldc.i4.8
  IL_003A: conv.i8
  IL_003B: sub
  IL_003C: stloc.0
  IL_003D: ldloc.0
  IL_003E: ldloc.1
  IL_003F: blt.un.s  0x4c
  IL_0041: ldloc.0
  IL_0042: ldind.i8
  IL_0043: ldc.i4.0
  IL_0044: conv.i8
  IL_0045: call      0x06000075 EncodePointer
  IL_004A: beq.s     0xec
  IL_004C: ldloc.0
  IL_004D: ldind.i8
  IL_004E: call      0x06000074 DecodePointer
  IL_0053: ldloc.0
  IL_0054: ldc.i4.0
  IL_0055: conv.i8
  IL_0056: call      0x06000075 EncodePointer
  IL_005B: stind.i8
  IL_005C: calli     0x11000082
  IL_0061: ldsfld    0x040000A1
  IL_0066: call      0x06000074 DecodePointer
  IL_006B: stloc.3
  IL_006C: ldsfld    0x040000A6
  IL_0071: call      0x06000074 DecodePointer
  IL_0076: stloc.2
  IL_0077: ldloc.s   0x5
  IL_0079: ldloc.3
  IL_007A: bne.un.s  0x5
  IL_007C: ldloc.s   0x4
  IL_007E: ldloc.2
  IL_007F: beq.s     0xb7
  IL_0081: ldloc.3
  IL_0082: stloc.s   0x5
  IL_0084: ldloc.3
  IL_0085: stloc.1
  IL_0086: ldloc.2
  IL_0087: stloc.s   0x4
  IL_0089: ldloc.2
  IL_008A: stloc.0
  IL_008B: br.s      0xab
  IL_008D: ldloca.s  0x6
  IL_008F: ldloc.1
  IL_0090: call      0x0A000049
  IL_0095: ldloc.s   0x6
  IL_0097: call      0x0A00001A
  IL_009C: call      0x0600006A ?A0xdf32f105.__dealloc_global_lock
  IL_00A1: ret
}
// MethodDef 0x0600006D  _initatexit_m  flavor=IL rva=0x4564
.method /* _initatexit_m */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: call      0x06000069 ?A0xdf32f105.__alloc_global_lock
  IL_0006: ldc.i4.1
  IL_0007: bne.un.s  0x30
  IL_0009: pop
  IL_000A: ldc.i4    0x00000100
  IL_000F: call      0x0A000067
  IL_0014: stloc.0
  IL_0015: ldloca.s  0x0
  IL_0017: call      0x0A00001D
  IL_001C: call      0x06000075 EncodePointer
  IL_0021: stsfld    0x040000A1
  IL_0026: ldsfld    0x040000A1
  IL_002B: stsfld    0x040000A6
  IL_0030: ldc.i4.s  0x20
  IL_0032: conv.i8
  IL_0033: stsfld    0x040000A2
  IL_0038: ldc.i4.1
  IL_0039: ret
}
// MethodDef 0x0600006E  _onexit_m  flavor=IL rva=0x45AC
.method /* _onexit_m */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0600006F _atexit_m
  IL_0006: ldc.i4.m1
  IL_0007: beq.s     0x3
  IL_0009: ldarg.0
  IL_000A: br.s      0x2
  IL_000C: ldc.i4.0
  IL_000D: conv.i8
  IL_000E: ret
}
// MethodDef 0x0600006F  _atexit_m  flavor=IL rva=0x43C4
.method /* _atexit_m */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000075 EncodePointer
  IL_0006: ldsflda   0x040000A2
  IL_000B: ldsflda   0x040000A6
  IL_0010: ldsflda   0x040000A1
  IL_0015: call      0x0600006B _atexit_helper
  IL_001A: ret
}
// MethodDef 0x06000070  _initatexit_app_domain  flavor=IL rva=0x45C8
.method /* _initatexit_app_domain */ cil managed { 
  IL_0000: call      0x06000069 ?A0xdf32f105.__alloc_global_lock
  IL_0005: ldc.i4.1
  IL_0006: bne.un.s  0x2e
  IL_0008: ldc.i4    0x00000100
  IL_000D: call      0x0A000067
  IL_0012: stloc.0
  IL_0013: ldloca.s  0x0
  IL_0015: call      0x0A00001D
  IL_001A: call      0x06000075 EncodePointer
  IL_001F: stsfld    0x040000A8
  IL_0024: ldsfld    0x040000A8
  IL_0029: stsfld    0x040000A3
  IL_002E: ldc.i4.s  0x20
  IL_0030: conv.i8
  IL_0031: stsfld    0x040000A7
  IL_0036: ldc.i4.1
  IL_0037: ret
}
// MethodDef 0x06000071  _app_exit_callback  flavor=IL rva=0x43EC
.method /* _app_exit_callback */ cil managed { 
  IL_0000: ldsfld    0x040000A7
  IL_0005: brfalse   0x000000B6
  IL_000A: ldsfld    0x040000A8
  IL_000F: call      0x06000074 DecodePointer
  IL_0014: stloc.1
  IL_0015: ldsfld    0x040000A3
  IL_001A: call      0x06000074 DecodePointer
  IL_001F: stloc.0
  IL_0020: ldloc.1
  IL_0021: ldc.i8    18446744073709551615
  IL_002A: beq       0x0000007A
  IL_002F: ldloc.1
  IL_0030: brfalse   0x00000074
  IL_0035: ldloc.0
  IL_0036: brfalse.s 0x71
  IL_0038: ldc.i4.0
  IL_0039: conv.i8
  IL_003A: stloc.s   0x6
  IL_003C: ldloc.1
  IL_003D: stloc.s   0x5
  IL_003F: ldloc.0
  IL_0040: stloc.s   0x4
  IL_0042: ldc.i4.0
  IL_0043: conv.i8
  IL_0044: stloc.s   0x9
  IL_0046: ldc.i4.0
  IL_0047: conv.i8
  IL_0048: stloc.s   0x8
  IL_004A: ldloc.0
  IL_004B: ldc.i4.8
  IL_004C: conv.i8
  IL_004D: sub
  IL_004E: stloc.0
  IL_004F: ldloc.0
  IL_0050: ldloc.1
  IL_0051: blt.un.s  0xd
  IL_0053: ldloc.0
  IL_0054: ldind.i8
  IL_0055: ldc.i4.0
  IL_0056: conv.i8
  IL_0057: call      0x06000075 EncodePointer
  IL_005C: bne.un.s  0x2
  IL_005E: br.s      0xea
  IL_0060: ldloc.0
  IL_0061: ldloc.1
  IL_0062: blt.un.s  0x45
  IL_0064: ldloc.0
  IL_0065: ldind.i8
  IL_0066: call      0x06000074 DecodePointer
  IL_006B: stloc.s   0x6
  IL_006D: ldloc.0
  IL_006E: ldc.i4.0
  IL_006F: conv.i8
  IL_0070: call      0x06000075 EncodePointer
  IL_0075: stind.i8
  IL_0076: ldloc.s   0x6
  IL_0078: calli     0x11000082
  IL_007D: ldsfld    0x040000A8
  IL_0082: call      0x06000074 DecodePointer
  IL_0087: stloc.3
  IL_0088: ldsfld    0x040000A3
  IL_008D: call      0x06000074 DecodePointer
  IL_0092: stloc.2
  IL_0093: ldloc.s   0x5
  IL_0095: ldloc.3
  IL_0096: bne.un.s  0x5
  IL_0098: ldloc.s   0x4
  IL_009A: ldloc.2
  IL_009B: beq.s     0xa
  IL_009D: ldloc.3
  IL_009E: stloc.s   0x5
  IL_00A0: ldloc.3
  IL_00A1: stloc.1
  IL_00A2: ldloc.2
  IL_00A3: stloc.s   0x4
  IL_00A5: ldloc.2
  IL_00A6: stloc.0
  IL_00A7: br.s      0x99
  IL_00A9: leave.s   0x15
  IL_00AB: ldloca.s  0x7
  IL_00AD: ldloc.1
  IL_00AE: call      0x0A000049
  IL_00B3: ldloc.s   0x7
  IL_00B5: call      0x0A00001A
  IL_00BA: call      0x0600006A ?A0xdf32f105.__dealloc_global_lock
  IL_00BF: endfinally
  IL_00C0: ret
}
// MethodDef 0x06000072  _onexit_m_appdomain  flavor=IL rva=0x460C
.method /* _onexit_m_appdomain */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000073 _atexit_m_appdomain
  IL_0006: ldc.i4.m1
  IL_0007: beq.s     0x3
  IL_0009: ldarg.0
  IL_000A: br.s      0x2
  IL_000C: ldc.i4.0
  IL_000D: conv.i8
  IL_000E: ret
}
// MethodDef 0x06000073  _atexit_m_appdomain  flavor=IL rva=0x44D8
.method /* _atexit_m_appdomain */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000075 EncodePointer
  IL_0006: ldsflda   0x040000A7
  IL_000B: ldsflda   0x040000A3
  IL_0010: ldsflda   0x040000A8
  IL_0015: call      0x0600006B _atexit_helper
  IL_001A: ret
}
// MethodDef 0x06000074  DecodePointer  flavor=IL rva=0x0
.method /* DecodePointer */ declaration only, no RVA (import/runtime implementation)
// MethodDef 0x06000075  EncodePointer  flavor=IL rva=0x0
.method /* EncodePointer */ declaration only, no RVA (import/runtime implementation)
// MethodDef 0x06000076  _initterm_e  flavor=IL rva=0x463C
.method /* _initterm_e */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.0
  IL_0002: ldarg.0
  IL_0003: ldarg.1
  IL_0004: bge.un.s  0x1a
  IL_0006: ldloc.0
  IL_0007: brtrue.s  0x17
  IL_0009: ldarg.0
  IL_000A: ldind.i8
  IL_000B: stloc.1
  IL_000C: ldloc.1
  IL_000D: brfalse.s 0x7
  IL_000F: ldloc.1
  IL_0010: calli     0x11000092
  IL_0015: stloc.0
  IL_0016: ldarg.0
  IL_0017: ldc.i4.8
  IL_0018: conv.i8
  IL_0019: add
  IL_001A: starg.s   0x0
  IL_001C: ldarg.0
  IL_001D: ldarg.1
  IL_001E: blt.un.s  0xe6
  IL_0020: ldloc.0
  IL_0021: ret
}
// MethodDef 0x06000077  _initterm  flavor=IL rva=0x466C
.method /* _initterm */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: bge.un.s  0x16
  IL_0004: ldarg.0
  IL_0005: ldind.i8
  IL_0006: stloc.0
  IL_0007: ldloc.0
  IL_0008: brfalse.s 0x6
  IL_000A: ldloc.0
  IL_000B: calli     0x11000090
  IL_0010: ldarg.0
  IL_0011: ldc.i4.8
  IL_0012: conv.i8
  IL_0013: add
  IL_0014: starg.s   0x0
  IL_0016: ldarg.0
  IL_0017: ldarg.1
  IL_0018: blt.un.s  0xea
  IL_001A: ret
}
// MethodDef 0x06000078  <CrtImplementationDetails>.ThisModule.Handle  flavor=IL rva=0x4694
.method /* <CrtImplementationDetails>.ThisModule.Handle */ cil managed { 
  IL_0000: ldtoken   0x02000229
  IL_0005: call      0x0A00005A
  IL_000A: callvirt  0x0A00006C
  IL_000F: call      0x0A00006D
  IL_0014: ret
}
// MethodDef 0x06000079  _initterm_m  flavor=IL rva=0x46E4
.method /* _initterm_m */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: bge.un.s  0x1c
  IL_0004: ldarg.0
  IL_0005: ldind.i8
  IL_0006: stloc.0
  IL_0007: ldloc.0
  IL_0008: brfalse.s 0xc
  IL_000A: ldloc.0
  IL_000B: call      0x0600007A <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>
  IL_0010: calli     0x11000091
  IL_0015: pop
  IL_0016: ldarg.0
  IL_0017: ldc.i4.8
  IL_0018: conv.i8
  IL_0019: add
  IL_001A: starg.s   0x0
  IL_001C: ldarg.0
  IL_001D: ldarg.1
  IL_001E: blt.un.s  0xe4
  IL_0020: ret
}
// MethodDef 0x0600007A  <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>  flavor=IL rva=0x46B8
.method /* <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)> */ cil managed { 
  IL_0000: call      0x06000078 <CrtImplementationDetails>.ThisModule.Handle
  IL_0005: stloc.2
  IL_0006: ldloca.s  0x2
  IL_0008: ldarg.0
  IL_0009: conv.i4
  IL_000A: call      0x0A00006A
  IL_000F: stloc.1
  IL_0010: ldloca.s  0x1
  IL_0012: call      0x0A00006B
  IL_0017: stloc.0
  IL_0018: ldloca.s  0x0
  IL_001A: call      0x0A00001D
  IL_001F: ret
}
// MethodDef 0x0600007B  new[]  flavor=native rva=0x480C
.method /* new[] */ pinvokeimpl native, body in code/native.c at RVA 0x480C
// MethodDef 0x0600007C  delete[]  flavor=native rva=0x4804
.method /* delete[] */ pinvokeimpl native, body in code/native.c at RVA 0x4804
// MethodDef 0x0600007D  MultiByteToWideChar  flavor=native rva=0x486A
.method /* MultiByteToWideChar */ pinvokeimpl native, body in code/native.c at RVA 0x486A
// MethodDef 0x0600007E  WideCharToMultiByte  flavor=native rva=0x4864
.method /* WideCharToMultiByte */ pinvokeimpl native, body in code/native.c at RVA 0x4864
// MethodDef 0x0600007F  __ExceptionPtrCopy  flavor=native rva=0x485E
.method /* __ExceptionPtrCopy */ pinvokeimpl native, body in code/native.c at RVA 0x485E
// MethodDef 0x06000080  __ExceptionPtrDestroy  flavor=native rva=0x4858
.method /* __ExceptionPtrDestroy */ pinvokeimpl native, body in code/native.c at RVA 0x4858
// MethodDef 0x06000081  delete[]  flavor=native rva=0x4814
.method /* delete[] */ pinvokeimpl native, body in code/native.c at RVA 0x4814
// MethodDef 0x06000082  delete  flavor=native rva=0x2400
.method /* delete */ pinvokeimpl native, body in code/native.c at RVA 0x2400
// MethodDef 0x06000083  __std_exception_destroy  flavor=native rva=0x4771
.method /* __std_exception_destroy */ pinvokeimpl native, body in code/native.c at RVA 0x4771
// MethodDef 0x06000084  __std_exception_copy  flavor=native rva=0x476B
.method /* __std_exception_copy */ pinvokeimpl native, body in code/native.c at RVA 0x476B
// MethodDef 0x06000085  _getFiberPtrId  flavor=native rva=0x3660
.method /* _getFiberPtrId */ pinvokeimpl native, body in code/native.c at RVA 0x3660
// MethodDef 0x06000086  _cexit  flavor=native rva=0x47D7
.method /* _cexit */ pinvokeimpl native, body in code/native.c at RVA 0x47D7
// MethodDef 0x06000087  Sleep  flavor=native rva=0x4870
.method /* Sleep */ pinvokeimpl native, body in code/native.c at RVA 0x4870
// MethodDef 0x06000088  abort  flavor=native rva=0x487C
.method /* abort */ pinvokeimpl native, body in code/native.c at RVA 0x487C
// MethodDef 0x06000089  __security_init_cookie  flavor=native rva=0x2474
.method /* __security_init_cookie */ pinvokeimpl native, body in code/native.c at RVA 0x2474
// MethodDef 0x0600008A  __FrameUnwindFilter  flavor=native rva=0x4876
.method /* __FrameUnwindFilter */ pinvokeimpl native, body in code/native.c at RVA 0x4876
// MethodDef 0x0600008B  __current_exception_context  flavor=native rva=0x478F
.method /* __current_exception_context */ pinvokeimpl native, body in code/native.c at RVA 0x478F
// MethodDef 0x0600008C  terminate  flavor=native rva=0x47DD
.method /* terminate */ pinvokeimpl native, body in code/native.c at RVA 0x47DD
// MethodDef 0x0600008D  __current_exception  flavor=native rva=0x4789
.method /* __current_exception */ pinvokeimpl native, body in code/native.c at RVA 0x4789
// MethodDef 0x0600008E  .ctor  flavor=IL rva=0x1DA4
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
// MethodDef 0x0600008F  .ctor  flavor=IL rva=0x1504
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A000023
  IL_0006: ret
}
// MethodDef 0x06000090  .cctor  flavor=IL rva=0x1518
.method /* .cctor */ cil managed { 
  IL_0000: ldc.i4.1
  IL_0001: stsfld    0x040000CD
  IL_0006: ret
}
// MethodDef 0x06000091  .ctor  flavor=IL rva=0x17EC
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0600008F .ctor
  IL_0006: ldarg.0
  IL_0007: ldc.i4.0
  IL_0008: conv.i8
  IL_0009: stfld     0x040000CE
  IL_000E: ldarg.2
  IL_000F: ldnull
  IL_0010: call      0x0A000022
  IL_0015: brfalse.s 0xc
  IL_0017: ldarg.1
  IL_0018: ldc.i4.0
  IL_0019: conv.i8
  IL_001A: stind.i8
  IL_001B: ldarg.0
  IL_001C: call      0x0A000021
  IL_0021: br.s      0x49
  IL_0023: ldarg.2
  IL_0024: call      0x0600001B msclr.interop.details.GetAnsiStringSize
  IL_0029: stloc.1
  IL_002A: ldloc.1
  IL_002B: call      0x0600007B new[]
  IL_0030: stloc.0
  IL_0031: ldloca.s  0x2
  IL_0033: ldloc.0
  IL_0034: stind.i8
  IL_0035: ldloc.0
  IL_0036: brtrue.s  0x6
  IL_0038: newobj    0x0A000025
  IL_003D: throw
  IL_003E: ldloc.0
  IL_003F: ldloc.1
  IL_0040: ldarg.2
  IL_0041: call      0x0600001C msclr.interop.details.WriteAnsiString
  IL_0046: ldloca.s  0x2
  IL_0048: ldc.i4.0
  IL_0049: conv.i8
  IL_004A: stind.i8
  IL_004B: ldarg.0
  IL_004C: ldloc.0
  IL_004D: stfld     0x040000CE
  IL_0052: ldarg.1
  IL_0053: ldloc.0
  IL_0054: stind.i8
  IL_0055: leave.s   0xe
  IL_0057: ldftn     0x06000023 msclr.interop.details.char_buffer<char>.{dtor}
  IL_005D: ldloca.s  0x2
  IL_005F: call      0x06000056 ___CxxCallUnwindDtor
  IL_0064: endfinally
  IL_0065: ldc.i4.0
  IL_0066: conv.i8
  IL_0067: call      0x0600007C delete[]
  IL_006C: nop
  IL_006D: leave.s   0xe
  IL_006F: ldftn     0x06000023 msclr.interop.details.char_buffer<char>.{dtor}
  IL_0075: ldloca.s  0x2
  IL_0077: call      0x06000056 ___CxxCallUnwindDtor
  IL_007C: endfinally
  IL_007D: ret
}
// MethodDef 0x06000092  ~context_node<char const *,System::String ^>  flavor=IL rva=0x18AC
.method /* ~context_node<char const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldfld     0x040000CE
  IL_0006: call      0x0600007C delete[]
  IL_000B: ldarg.0
  IL_000C: call      0x0A000021
  IL_0011: ret
}
// MethodDef 0x06000093  !context_node<char const *,System::String ^>  flavor=IL rva=0x152C
.method /* !context_node<char const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldfld     0x040000CE
  IL_0006: call      0x0600007C delete[]
  IL_000B: ldarg.0
  IL_000C: call      0x0A000021
  IL_0011: ret
}
// MethodDef 0x06000094  Dispose  flavor=IL rva=0x18CC
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: brfalse.s 0x13
  IL_0003: ldarg.0
  IL_0004: ldfld     0x040000CE
  IL_0009: call      0x0600007C delete[]
  IL_000E: ldarg.0
  IL_000F: call      0x0A000021
  IL_0014: br.s      0x10
  IL_0016: nop
  IL_0017: ldarg.0
  IL_0018: call      0x06000093 !context_node<char const *,System::String ^>
  IL_001D: leave.s   0x7
  IL_001F: ldarg.0
  IL_0020: call      0x0A00001F
  IL_0025: endfinally
  IL_0026: ret
}
// MethodDef 0x06000095  Dispose  flavor=IL rva=0x19E8
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.1
  IL_0002: callvirt  0x06000094 Dispose
  IL_0007: ldarg.0
  IL_0008: call      0x0A000020
  IL_000D: ldarg.0
  IL_000E: call      0x0A000021
  IL_0013: ret
}
// MethodDef 0x06000096  Finalize  flavor=IL rva=0x191C
.method /* Finalize */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.0
  IL_0002: callvirt  0x06000094 Dispose
  IL_0007: ret
}
// MethodDef 0x06000097  .ctor  flavor=IL rva=0x154C
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0600008F .ctor
  IL_0006: ldarg.2
  IL_0007: call      0x0A00001E
  IL_000C: stloc.0
  IL_000D: ldarg.0
  IL_000E: ldloc.0
  IL_000F: stfld     0x040000CF
  IL_0014: ldarg.1
  IL_0015: ldarg.0
  IL_0016: ldflda    0x040000CF
  IL_001B: call      0x0A00001D
  IL_0020: stind.i8
  IL_0021: ldarg.0
  IL_0022: call      0x0A000021
  IL_0027: ret
}
// MethodDef 0x06000098  ~context_node<wchar_t const *,System::String ^>  flavor=IL rva=0x1930
.method /* ~context_node<wchar_t const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000099 !context_node<wchar_t const *,System::String ^>
  IL_0006: ret
}
// MethodDef 0x06000099  !context_node<wchar_t const *,System::String ^>  flavor=IL rva=0x1580
.method /* !context_node<wchar_t const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldflda    0x040000CF
  IL_0006: ldobj     0x01000021
  IL_000B: ldsfld    0x0A00001B
  IL_0010: call      0x0A00001C
  IL_0015: brfalse.s 0x10
  IL_0017: ldarg.0
  IL_0018: ldflda    0x040000CF
  IL_001D: ldobj     0x01000021
  IL_0022: call      0x0A00001A
  IL_0027: ldarg.0
  IL_0028: call      0x0A000021
  IL_002D: ret
}
// MethodDef 0x0600009A  Dispose  flavor=IL rva=0x1944
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: brfalse.s 0x8
  IL_0003: ldarg.0
  IL_0004: call      0x06000099 !context_node<wchar_t const *,System::String ^>
  IL_0009: br.s      0x10
  IL_000B: nop
  IL_000C: ldarg.0
  IL_000D: call      0x06000099 !context_node<wchar_t const *,System::String ^>
  IL_0012: leave.s   0x7
  IL_0014: ldarg.0
  IL_0015: call      0x0A00001F
  IL_001A: endfinally
  IL_001B: ret
}
// MethodDef 0x0600009B  Dispose  flavor=IL rva=0x1A08
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.1
  IL_0002: callvirt  0x0600009A Dispose
  IL_0007: ldarg.0
  IL_0008: call      0x0A000020
  IL_000D: ldarg.0
  IL_000E: call      0x0A000021
  IL_0013: ret
}
// MethodDef 0x0600009C  Finalize  flavor=IL rva=0x1988
.method /* Finalize */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.0
  IL_0002: callvirt  0x0600009A Dispose
  IL_0007: ret
}
// MethodDef 0x0600009D  .ctor  flavor=IL rva=0x15BC
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: newobj    0x0A000019
  IL_0006: stfld     0x040000D0
  IL_000B: ldarg.0
  IL_000C: call      0x0A000023
  IL_0011: ret
}
// MethodDef 0x0600009E  ~marshal_context  flavor=IL rva=0x15DC
.method /* ~marshal_context */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldfld     0x040000D0
  IL_0006: call      0x0A000018
  IL_000B: stloc.1
  IL_000C: ldloca.s  0x1
  IL_000E: call      0x0A000017
  IL_0013: brfalse.s 0x1f
  IL_0015: ldloca.s  0x1
  IL_0017: call      0x0A000016
  IL_001C: isinst    0x0100001E
  IL_0021: stloc.0
  IL_0022: ldloc.0
  IL_0023: brfalse.s 0x6
  IL_0025: ldloc.0
  IL_0026: callvirt  0x0A000015
  IL_002B: ldloca.s  0x1
  IL_002D: call      0x0A000017
  IL_0032: brtrue.s  0xe1
  IL_0034: ldarg.0
  IL_0035: call      0x0A000021
  IL_003A: ret
}
// MethodDef 0x0600009F  Dispose  flavor=IL rva=0x1624
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.1
  IL_0001: brfalse.s 0x8
  IL_0003: ldarg.0
  IL_0004: call      0x0600009E ~marshal_context
  IL_0009: br.s      0x6
  IL_000B: ldarg.0
  IL_000C: call      0x0A00001F
  IL_0011: ret
}
// MethodDef 0x060000A0  Dispose  flavor=IL rva=0x199C
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldc.i4.1
  IL_0002: callvirt  0x0600009F Dispose
  IL_0007: ldarg.0
  IL_0008: call      0x0A000020
  IL_000D: ldarg.0
  IL_000E: call      0x0A000021
  IL_0013: ret
}
// MethodDef 0x060000A1  WrapperSaveMergennFiles  flavor=IL rva=0x1A5C
.method /* WrapperSaveMergennFiles */ cil managed { 
  IL_0000: ldarga.s  0x2
  IL_0002: call      0x06000028 msclr.interop.marshal_as<class System::String ^,char *>
  IL_0007: stloc.0
  IL_0008: ldarga.s  0x1
  IL_000A: call      0x06000028 msclr.interop.marshal_as<class System::String ^,char *>
  IL_000F: ldloc.0
  IL_0010: call      0x0A000014
  IL_0015: ret
}
// MethodDef 0x060000A2  .ctor  flavor=IL rva=0x1644
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A000023
  IL_0006: ret
}
// MethodDef 0x060000A3  <MarshalCopy>  flavor=IL rva=0x1224
.method /* <MarshalCopy> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: brfalse.s 0x7
  IL_0003: ldarg.0
  IL_0004: ldarg.1
  IL_0005: call      0x0600007F __ExceptionPtrCopy
  IL_000A: ret
}
// MethodDef 0x060000A4  <MarshalDestroy>  flavor=IL rva=0x123C
.method /* <MarshalDestroy> */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x06000080 __ExceptionPtrDestroy
  IL_0006: ret
}
// MethodDef 0x060000A5  .ctor  flavor=IL rva=0x1DB8
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
// MethodDef 0x060000A6  .ctor  flavor=IL rva=0x3100
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
// MethodDef 0x060000A7  .ctor  flavor=IL rva=0x3140
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x0A00004C
  IL_0008: ret
}
// MethodDef 0x060000A8  .ctor  flavor=IL rva=0x3128
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x0A00004D
  IL_0008: ret
}
// MethodDef 0x060000A9  .ctor  flavor=IL rva=0x3114
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: call      0x0A00004E
  IL_0007: ret
}
// MethodDef 0x060000AA  .ctor  flavor=IL rva=0x3184
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x0A00004C
  IL_0008: ret
}
// MethodDef 0x060000AB  .ctor  flavor=IL rva=0x316C
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x0A00004D
  IL_0008: ret
}
// MethodDef 0x060000AC  .ctor  flavor=IL rva=0x3158
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: call      0x0A00004E
  IL_0007: ret
}
// MethodDef 0x060000AD  .ctor  flavor=IL rva=0x32B0
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x060000AA .ctor
  IL_0008: ldtoken   0x01000030
  IL_000D: call      0x0A00005A
  IL_0012: stloc.1
  IL_0013: ldstr     0x700003FB
  IL_0018: stloc.0
  IL_0019: ldarg.0
  IL_001A: ldarg.1
  IL_001B: ldloc.0
  IL_001C: ldloc.1
  IL_001D: call      0x0A000046
  IL_0022: castclass 0x01000030
  IL_0027: call      0x060000B0 set_NestedException
  IL_002C: ldarg.0
  IL_002D: call      0x0A000021
  IL_0032: ret
}
// MethodDef 0x060000AE  .ctor  flavor=IL rva=0x3924
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x060000AB .ctor
  IL_0008: ldarg.0
  IL_0009: ldarg.3
  IL_000A: call      0x060000B0 set_NestedException
  IL_000F: ret
}
// MethodDef 0x060000AF  get_NestedException  flavor=IL rva=0x319C
.method /* get_NestedException */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldfld     0x04000269
  IL_0006: ret
}
// MethodDef 0x060000B0  set_NestedException  flavor=IL rva=0x31B0
.method /* set_NestedException */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: stfld     0x04000269
  IL_0007: ret
}
// MethodDef 0x060000B1  ToString  flavor=IL rva=0x31C4
.method /* ToString */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: callvirt  0x0A000054
  IL_0006: brfalse.s 0xe
  IL_0008: ldarg.0
  IL_0009: callvirt  0x0A000054
  IL_000E: callvirt  0x0A000050
  IL_0013: stloc.2
  IL_0014: br.s      0x6
  IL_0016: ldsfld    0x0A000048
  IL_001B: stloc.2
  IL_001C: ldarg.0
  IL_001D: call      0x060000AF get_NestedException
  IL_0022: brfalse.s 0xe
  IL_0024: ldarg.0
  IL_0025: call      0x060000AF get_NestedException
  IL_002A: callvirt  0x0A000050
  IL_002F: stloc.1
  IL_0030: br.s      0x6
  IL_0032: ldsfld    0x0A000048
  IL_0037: stloc.1
  IL_0038: ldc.i4.4
  IL_0039: newarr    0x0100001D
  IL_003E: stloc.0
  IL_003F: ldarg.0
  IL_0040: callvirt  0x0A000052
  IL_0045: stloc.s   0x6
  IL_0047: ldloc.0
  IL_0048: ldc.i4.0
  IL_0049: ldloc.s   0x6
  IL_004B: stelem.ref
  IL_004C: ldarg.0
  IL_004D: callvirt  0x0A000053
  IL_0052: brfalse.s 0xa
  IL_0054: ldarg.0
  IL_0055: callvirt  0x0A000053
  IL_005A: stloc.s   0x5
  IL_005C: br.s      0x7
  IL_005E: ldsfld    0x0A000048
  IL_0063: stloc.s   0x5
  IL_0065: ldloc.0
  IL_0066: ldc.i4.1
  IL_0067: ldloc.s   0x5
  IL_0069: stelem.ref
  IL_006A: ldloc.2
  IL_006B: brfalse.s 0x5
  IL_006D: ldloc.2
  IL_006E: stloc.s   0x4
  IL_0070: br.s      0x7
  IL_0072: ldsfld    0x0A000048
  IL_0077: stloc.s   0x4
  IL_0079: ldloc.0
  IL_007A: ldc.i4.2
  IL_007B: ldloc.s   0x4
  IL_007D: stelem.ref
  IL_007E: ldloc.1
  IL_007F: brfalse.s 0x4
  IL_0081: ldloc.1
  IL_0082: stloc.3
  IL_0083: br.s      0x6
  IL_0085: ldsfld    0x0A000048
  IL_008A: stloc.3
  IL_008B: ldloc.0
  IL_008C: ldc.i4.3
  IL_008D: ldloc.3
  IL_008E: stelem.ref
  IL_008F: ldstr     0x700002C6
  IL_0094: ldloc.0
  IL_0095: call      0x0A000047
  IL_009A: ldarg.0
  IL_009B: call      0x0A000021
  IL_00A0: ret
}
// MethodDef 0x060000B2  GetObjectData  flavor=IL rva=0x3274
.method /* GetObjectData */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x0A000051
  IL_0008: ldtoken   0x01000030
  IL_000D: call      0x0A00005A
  IL_0012: stloc.1
  IL_0013: ldarg.0
  IL_0014: call      0x060000AF get_NestedException
  IL_0019: stloc.0
  IL_001A: ldarg.1
  IL_001B: ldstr     0x700003FB
  IL_0020: ldloc.0
  IL_0021: ldloc.1
  IL_0022: call      0x0A000045
  IL_0027: ldarg.0
  IL_0028: call      0x0A000021
  IL_002D: ret
}
// MethodDef 0x060000B3  AddHandler  flavor=IL rva=0x331C
.method /* AddHandler */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.0
  IL_0002: call      0x0A000044
  IL_0007: call      0x0A000044
  IL_000C: ldsfld    0x0400026A
  IL_0011: ldloca.s  0x0
  IL_0013: call      0x0A000037
  IL_0018: ldarg.1
  IL_0019: call      0x0A000043
  IL_001E: ldarg.0
  IL_001F: ldarg.1
  IL_0020: callvirt  0x0A00005E
  IL_0025: leave.s   0xe
  IL_0027: ldloc.0
  IL_0028: brfalse.s 0xa
  IL_002A: ldsfld    0x0400026A
  IL_002F: call      0x0A000038
  IL_0034: endfinally
  IL_0035: ret
}
// MethodDef 0x060000B4  .cctor  flavor=IL rva=0x3DD0
.method /* .cctor */ cil managed { 
  IL_0000: newobj    0x0A000023
  IL_0005: stsfld    0x0400026A
  IL_000A: newobj    0x060000B5 .ctor
  IL_000F: stsfld    0x0400026B
  IL_0014: ret
}
// MethodDef 0x060000B5  .ctor  flavor=IL rva=0x395C
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00005C
  IL_0006: ldarg.0
  IL_0007: ldftn     0x060000B6 SingletonDomainUnload
  IL_000D: newobj    0x0A00004A
  IL_0012: stloc.0
  IL_0013: call      0x0A000056
  IL_0018: ldloc.0
  IL_0019: callvirt  0x0A000059
  IL_001E: call      0x0A000056
  IL_0023: ldloc.0
  IL_0024: callvirt  0x0A000058
  IL_0029: ret
}
// MethodDef 0x060000B6  SingletonDomainUnload  flavor=IL rva=0x337C
.method /* SingletonDomainUnload */ cil managed { 
  IL_0000: ldc.i4.0
  IL_0001: stloc.2
  IL_0002: call      0x0A000044
  IL_0007: call      0x0A000044
  IL_000C: ldsfld    0x0400026A
  IL_0011: ldloca.s  0x2
  IL_0013: call      0x0A000037
  IL_0018: ldarg.0
  IL_0019: callvirt  0x0A00005D
  IL_001E: stloc.0
  IL_001F: ldloc.0
  IL_0020: callvirt  0x0A00005F
  IL_0025: brfalse.s 0x14
  IL_0027: ldloc.0
  IL_0028: callvirt  0x0A000060
  IL_002D: castclass 0x01000035
  IL_0032: ldarg.1
  IL_0033: ldarg.2
  IL_0034: callvirt  0x0A00004B
  IL_0039: br.s      0xe4
  IL_003B: leave.s   0x13
  IL_003D: ldloc.0
  IL_003E: stloc.3
  IL_003F: ldloc.0
  IL_0040: isinst    0x0100001E
  IL_0045: stloc.1
  IL_0046: ldloc.1
  IL_0047: brfalse.s 0x6
  IL_0049: ldloc.1
  IL_004A: callvirt  0x0A000015
  IL_004F: endfinally
  IL_0050: leave.s   0xe
  IL_0052: ldloc.2
  IL_0053: brfalse.s 0xa
  IL_0055: ldsfld    0x0400026A
  IL_005A: call      0x0A000038
  IL_005F: endfinally
  IL_0060: ret
}
// MethodDef 0x060000B7  .ctor  flavor=IL rva=0x3624
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: ldarg.1
  IL_0002: ldarg.2
  IL_0003: call      0x0A00004C
  IL_0008: ret
}
// MethodDef 0x060000B8  .ctor  flavor=IL rva=0x3610
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00004F
  IL_0006: ret
}
// MethodDef 0x060000B9  .ctor  flavor=IL rva=0x3DF4
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
// MethodDef 0x060000BA  .ctor  flavor=IL rva=0x3ED8
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
// MethodDef 0x060000BB  .ctor  flavor=IL rva=0x3FF4
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
// MethodDef 0x060000BC  .ctor  flavor=IL rva=0x4628
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0
  IL_0001: call      0x0A00002A
  IL_0006: ret
}
