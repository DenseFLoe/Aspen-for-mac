/* NATIVE-340 MethodDef bodies: IL disassembly (original bytes via IDA CLR loader), native methods point to native.c */
// MethodDef 0x06000001  std.exception.{ctor}  flavor=IL rva=0x10A0
.method /* std.exception.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: stloc.0  
  IL_000C: ldloc.0  
  IL_000D: ldc.i4.0 
  IL_000E: ldc.i4.s 0x10
  IL_0010: conv.i8  
  IL_0011: initblk  
  IL_0013: ldarg.1  
  IL_0014: ldc.i4.8 
  IL_0015: conv.i8  
  IL_0016: add      
  IL_0017: ldloc.0  
  IL_0018: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_copy(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __std_exception_data* A_0, valuetype __std_exception_data* _to_object)
  IL_001D: ldarg.0  
  IL_001E: ret      
}
// MethodDef 0x06000002  std.exception.{dtor}  flavor=IL rva=0x10CC
.method /* std.exception.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
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
  IL_0009: bne.un.s loc_122
  IL_000B: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY0BC@$$CBD ??_C@_0BC@EOODALEL@Unknown?5exception@
  IL_0010: br.s     loc_123
  IL_0012: ldloc.0  
  IL_0013: ret      
}
// MethodDef 0x06000004  std.exception.__vecDelDtor  flavor=IL rva=0x1A9C
.method /* std.exception.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4.2 
  IL_0002: and      
  IL_0003: brfalse.s loc_161
  IL_0005: ldarg.0  
  IL_0006: ldc.i4.8 
  IL_0007: conv.i8  
  IL_0008: sub      
  IL_0009: stloc.0  
  IL_000A: ldarg.0  
  IL_000B: ldc.i4.s 0x18
  IL_000D: conv.i8  
  IL_000E: ldloc.0  
  IL_000F: ldind.i8 
  IL_0010: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.exception.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.exception* A_0)
  IL_0016: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_001B: ldarg.1  
  IL_001C: ldc.i4.1 
  IL_001D: and      
  IL_001E: brfalse.s loc_15F
  IL_0020: ldloc.0  
  IL_0021: dup      
  IL_0022: ldind.i8 
  IL_0023: ldc.i4.s 0x18
  IL_0025: conv.i8  
  IL_0026: mul      
  IL_0027: ldc.i4.8 
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0, unsigned int64 _to_object)
  IL_002F: ldloc.0  
  IL_0030: ret      
  IL_0031: ldarg.0  
  IL_0032: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0037: stind.i8 
  IL_0038: ldarg.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0041: ldarg.1  
  IL_0042: ldc.i4.1 
  IL_0043: and      
  IL_0044: brfalse.s loc_17F
  IL_0046: ldarg.0  
  IL_0047: ldc.i4.s 0x18
  IL_0049: conv.i8  
  IL_004A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete(void* A_0, unsigned int64 _to_object)
  IL_004F: ldarg.0  
  IL_0050: ret      
}
// MethodDef 0x06000005  std.bad_alloc.__vecDelDtor  flavor=IL rva=0x1B1C
.method /* std.bad_alloc.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4.2 
  IL_0002: and      
  IL_0003: brfalse.s loc_1C1
  IL_0005: ldarg.0  
  IL_0006: ldc.i4.8 
  IL_0007: conv.i8  
  IL_0008: sub      
  IL_0009: stloc.0  
  IL_000A: ldarg.0  
  IL_000B: ldc.i4.s 0x18
  IL_000D: conv.i8  
  IL_000E: ldloc.0  
  IL_000F: ldind.i8 
  IL_0010: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.bad_alloc.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.bad_alloc* A_0)
  IL_0016: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_001B: ldarg.1  
  IL_001C: ldc.i4.1 
  IL_001D: and      
  IL_001E: brfalse.s loc_1BF
  IL_0020: ldloc.0  
  IL_0021: dup      
  IL_0022: ldind.i8 
  IL_0023: ldc.i4.s 0x18
  IL_0025: conv.i8  
  IL_0026: mul      
  IL_0027: ldc.i4.8 
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0, unsigned int64 _to_object)
  IL_002F: ldloc.0  
  IL_0030: ret      
  IL_0031: ldarg.0  
  IL_0032: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0037: stind.i8 
  IL_0038: ldarg.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0041: ldarg.1  
  IL_0042: ldc.i4.1 
  IL_0043: and      
  IL_0044: brfalse.s loc_1DF
  IL_0046: ldarg.0  
  IL_0047: ldc.i4.s 0x18
  IL_0049: conv.i8  
  IL_004A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete(void* A_0, unsigned int64 _to_object)
  IL_004F: ldarg.0  
  IL_0050: ret      
}
// MethodDef 0x06000006  std.bad_alloc.{dtor}  flavor=IL rva=0x10EC
.method /* std.bad_alloc.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0010: ret      
}
// MethodDef 0x06000007  std.bad_array_new_length.__vecDelDtor  flavor=IL rva=0x1B7C
.method /* std.bad_array_new_length.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4.2 
  IL_0002: and      
  IL_0003: brfalse.s loc_241
  IL_0005: ldarg.0  
  IL_0006: ldc.i4.8 
  IL_0007: conv.i8  
  IL_0008: sub      
  IL_0009: stloc.0  
  IL_000A: ldarg.0  
  IL_000B: ldc.i4.s 0x18
  IL_000D: conv.i8  
  IL_000E: ldloc.0  
  IL_000F: ldind.i8 
  IL_0010: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.bad_array_new_length.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.bad_array_new_length* _Rhs)
  IL_0016: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_001B: ldarg.1  
  IL_001C: ldc.i4.1 
  IL_001D: and      
  IL_001E: brfalse.s loc_23F
  IL_0020: ldloc.0  
  IL_0021: dup      
  IL_0022: ldind.i8 
  IL_0023: ldc.i4.s 0x18
  IL_0025: conv.i8  
  IL_0026: mul      
  IL_0027: ldc.i4.8 
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0, unsigned int64 _to_object)
  IL_002F: ldloc.0  
  IL_0030: ret      
  IL_0031: ldarg.0  
  IL_0032: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0037: stind.i8 
  IL_0038: ldarg.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0041: ldarg.1  
  IL_0042: ldc.i4.1 
  IL_0043: and      
  IL_0044: brfalse.s loc_25F
  IL_0046: ldarg.0  
  IL_0047: ldc.i4.s 0x18
  IL_0049: conv.i8  
  IL_004A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete(void* A_0, unsigned int64 _to_object)
  IL_004F: ldarg.0  
  IL_0050: ret      
}
// MethodDef 0x06000008  std.bad_array_new_length.{dtor}  flavor=IL rva=0x1BDC
.method /* std.bad_array_new_length.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0010: ret      
}
// MethodDef 0x06000009  std.exception_ptr.{dtor}  flavor=IL rva=0x110C
.method /* std.exception_ptr.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __ExceptionPtrDestroy(void* A_0)
  IL_0006: ret      
}
// MethodDef 0x0600000A  std.exception_ptr.{ctor}  flavor=IL rva=0x1120
.method /* std.exception_ptr.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __ExceptionPtrCopy(void* A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void* _to_object)
  IL_0007: ldarg.0  
  IL_0008: ret      
}
// MethodDef 0x0600000B  std.bad_array_new_length.{ctor}  flavor=IL rva=0x1198
.method /* std.bad_array_new_length.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: stloc.0  
  IL_000C: ldloc.0  
  IL_000D: ldc.i4.0 
  IL_000E: ldc.i4.s 0x10
  IL_0010: conv.i8  
  IL_0011: initblk  
  IL_0013: ldarg.1  
  IL_0014: ldc.i4.8 
  IL_0015: conv.i8  
  IL_0016: add      
  IL_0017: ldloc.0  
  IL_0018: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_copy(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __std_exception_data* A_0, valuetype __std_exception_data* _to_object)
  IL_001D: ldarg.0  
  IL_001E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7bad_alloc@std@@6B@
  IL_0023: stind.i8 
  IL_0024: leave.s  loc_2E3
  IL_0026: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.exception.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.exception* A_0)
  IL_002C: ldarg.0  
  IL_002D: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0032: endfinally 
  IL_0033: nop      
  IL_0034: ldarg.0  
  IL_0035: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7bad_array_new_length@std@@6B@
  IL_003A: stind.i8 
  IL_003B: leave.s  loc_2FA
  IL_003D: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.bad_alloc.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.bad_alloc* A_0)
  IL_0043: ldarg.0  
  IL_0044: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0049: endfinally 
  IL_004A: ldarg.0  
  IL_004B: ret      
}
// MethodDef 0x0600000C  std.bad_alloc.{ctor}  flavor=IL rva=0x1138
.method /* std.bad_alloc.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: stloc.0  
  IL_000C: ldloc.0  
  IL_000D: ldc.i4.0 
  IL_000E: ldc.i4.s 0x10
  IL_0010: conv.i8  
  IL_0011: initblk  
  IL_0013: ldarg.1  
  IL_0014: ldc.i4.8 
  IL_0015: conv.i8  
  IL_0016: add      
  IL_0017: ldloc.0  
  IL_0018: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_copy(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __std_exception_data* A_0, valuetype __std_exception_data* _to_object)
  IL_001D: ldarg.0  
  IL_001E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7bad_alloc@std@@6B@
  IL_0023: stind.i8 
  IL_0024: leave.s  loc_333
  IL_0026: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.exception.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.exception* A_0)
  IL_002C: ldarg.0  
  IL_002D: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0032: endfinally 
  IL_0033: ldarg.0  
  IL_0034: ret      
}
// MethodDef 0x0600000D  std.bad_variant_access.what  flavor=IL rva=0x1C7C
.method /* std.bad_variant_access.what */ cil managed { 
  IL_0000: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY0BD@$$CBD ??_C@_0BD@FGIAGBIG@bad?5variant?5access@
  IL_0005: ret      
}
// MethodDef 0x0600000E  std.bad_variant_access.{dtor}  flavor=IL rva=0x1C5C
.method /* std.bad_variant_access.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0010: ret      
}
// MethodDef 0x0600000F  std.bad_variant_access.{ctor}  flavor=IL rva=0x1250
.method /* std.bad_variant_access.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: stloc.0  
  IL_000C: ldloc.0  
  IL_000D: ldc.i4.0 
  IL_000E: ldc.i4.s 0x10
  IL_0010: conv.i8  
  IL_0011: initblk  
  IL_0013: ldarg.1  
  IL_0014: ldc.i4.8 
  IL_0015: conv.i8  
  IL_0016: add      
  IL_0017: ldloc.0  
  IL_0018: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_copy(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __std_exception_data* A_0, valuetype __std_exception_data* _to_object)
  IL_001D: ldarg.0  
  IL_001E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7bad_variant_access@std@@6B@
  IL_0023: stind.i8 
  IL_0024: leave.s  loc_3A3
  IL_0026: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.exception.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.exception* A_0)
  IL_002C: ldarg.0  
  IL_002D: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0032: endfinally 
  IL_0033: ldarg.0  
  IL_0034: ret      
}
// MethodDef 0x06000010  std.bad_variant_access.__vecDelDtor  flavor=IL rva=0x1BFC
.method /* std.bad_variant_access.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4.2 
  IL_0002: and      
  IL_0003: brfalse.s loc_3E1
  IL_0005: ldarg.0  
  IL_0006: ldc.i4.8 
  IL_0007: conv.i8  
  IL_0008: sub      
  IL_0009: stloc.0  
  IL_000A: ldarg.0  
  IL_000B: ldc.i4.s 0x18
  IL_000D: conv.i8  
  IL_000E: ldloc.0  
  IL_000F: ldind.i8 
  IL_0010: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.bad_variant_access.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.bad_variant_access* A_0)
  IL_0016: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_001B: ldarg.1  
  IL_001C: ldc.i4.1 
  IL_001D: and      
  IL_001E: brfalse.s loc_3DF
  IL_0020: ldloc.0  
  IL_0021: dup      
  IL_0022: ldind.i8 
  IL_0023: ldc.i4.s 0x18
  IL_0025: conv.i8  
  IL_0026: mul      
  IL_0027: ldc.i4.8 
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0, unsigned int64 _to_object)
  IL_002F: ldloc.0  
  IL_0030: ret      
  IL_0031: ldarg.0  
  IL_0032: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0037: stind.i8 
  IL_0038: ldarg.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0041: ldarg.1  
  IL_0042: ldc.i4.1 
  IL_0043: and      
  IL_0044: brfalse.s loc_3FF
  IL_0046: ldarg.0  
  IL_0047: ldc.i4.s 0x18
  IL_0049: conv.i8  
  IL_004A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete(void* A_0, unsigned int64 _to_object)
  IL_004F: ldarg.0  
  IL_0050: ret      
}
// MethodDef 0x06000011  std.bad_cast.__vecDelDtor  flavor=IL rva=0x1C90
.method /* std.bad_cast.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4.2 
  IL_0002: and      
  IL_0003: brfalse.s loc_441
  IL_0005: ldarg.0  
  IL_0006: ldc.i4.8 
  IL_0007: conv.i8  
  IL_0008: sub      
  IL_0009: stloc.0  
  IL_000A: ldarg.0  
  IL_000B: ldc.i4.s 0x18
  IL_000D: conv.i8  
  IL_000E: ldloc.0  
  IL_000F: ldind.i8 
  IL_0010: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.bad_cast.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.bad_cast* A_0)
  IL_0016: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_001B: ldarg.1  
  IL_001C: ldc.i4.1 
  IL_001D: and      
  IL_001E: brfalse.s loc_43F
  IL_0020: ldloc.0  
  IL_0021: dup      
  IL_0022: ldind.i8 
  IL_0023: ldc.i4.s 0x18
  IL_0025: conv.i8  
  IL_0026: mul      
  IL_0027: ldc.i4.8 
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0, unsigned int64 _to_object)
  IL_002F: ldloc.0  
  IL_0030: ret      
  IL_0031: ldarg.0  
  IL_0032: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0037: stind.i8 
  IL_0038: ldarg.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0041: ldarg.1  
  IL_0042: ldc.i4.1 
  IL_0043: and      
  IL_0044: brfalse.s loc_45F
  IL_0046: ldarg.0  
  IL_0047: ldc.i4.s 0x18
  IL_0049: conv.i8  
  IL_004A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete(void* A_0, unsigned int64 _to_object)
  IL_004F: ldarg.0  
  IL_0050: ret      
}
// MethodDef 0x06000012  std.bad_cast.{dtor}  flavor=IL rva=0x1CF0
.method /* std.bad_cast.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0010: ret      
}
// MethodDef 0x06000013  std.bad_cast.{ctor}  flavor=IL rva=0x12B0
.method /* std.bad_cast.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: stloc.0  
  IL_000C: ldloc.0  
  IL_000D: ldc.i4.0 
  IL_000E: ldc.i4.s 0x10
  IL_0010: conv.i8  
  IL_0011: initblk  
  IL_0013: ldarg.1  
  IL_0014: ldc.i4.8 
  IL_0015: conv.i8  
  IL_0016: add      
  IL_0017: ldloc.0  
  IL_0018: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_copy(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __std_exception_data* A_0, valuetype __std_exception_data* _to_object)
  IL_001D: ldarg.0  
  IL_001E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7bad_cast@std@@6B@
  IL_0023: stind.i8 
  IL_0024: leave.s  loc_4C3
  IL_0026: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.exception.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.exception* A_0)
  IL_002C: ldarg.0  
  IL_002D: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
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
  IL_0000: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY0N@$$CBD ??_C@_0N@FJHHFFAF@bad_weak_ptr@
  IL_0005: ret      
}
// MethodDef 0x06000017  std.bad_weak_ptr.__vecDelDtor  flavor=IL rva=0x1D10
.method /* std.bad_weak_ptr.__vecDelDtor */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4.2 
  IL_0002: and      
  IL_0003: brfalse.s loc_531
  IL_0005: ldarg.0  
  IL_0006: ldc.i4.8 
  IL_0007: conv.i8  
  IL_0008: sub      
  IL_0009: stloc.0  
  IL_000A: ldarg.0  
  IL_000B: ldc.i4.s 0x18
  IL_000D: conv.i8  
  IL_000E: ldloc.0  
  IL_000F: ldind.i8 
  IL_0010: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.bad_weak_ptr.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.bad_weak_ptr* A_0)
  IL_0016: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_001B: ldarg.1  
  IL_001C: ldc.i4.1 
  IL_001D: and      
  IL_001E: brfalse.s loc_52F
  IL_0020: ldloc.0  
  IL_0021: dup      
  IL_0022: ldind.i8 
  IL_0023: ldc.i4.s 0x18
  IL_0025: conv.i8  
  IL_0026: mul      
  IL_0027: ldc.i4.8 
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0, unsigned int64 _to_object)
  IL_002F: ldloc.0  
  IL_0030: ret      
  IL_0031: ldarg.0  
  IL_0032: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0037: stind.i8 
  IL_0038: ldarg.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0041: ldarg.1  
  IL_0042: ldc.i4.1 
  IL_0043: and      
  IL_0044: brfalse.s loc_54F
  IL_0046: ldarg.0  
  IL_0047: ldc.i4.s 0x18
  IL_0049: conv.i8  
  IL_004A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete(void* A_0, unsigned int64 _to_object)
  IL_004F: ldarg.0  
  IL_0050: ret      
}
// MethodDef 0x06000018  std.bad_weak_ptr.{dtor}  flavor=IL rva=0x1D70
.method /* std.bad_weak_ptr.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_destroy(valuetype __std_exception_data* A_0)
  IL_0010: ret      
}
// MethodDef 0x06000019  std.bad_weak_ptr.{ctor}  flavor=IL rva=0x1324
.method /* std.bad_weak_ptr.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7exception@std@@6B@
  IL_0006: stind.i8 
  IL_0007: ldarg.0  
  IL_0008: ldc.i4.8 
  IL_0009: conv.i8  
  IL_000A: add      
  IL_000B: stloc.0  
  IL_000C: ldloc.0  
  IL_000D: ldc.i4.0 
  IL_000E: ldc.i4.s 0x10
  IL_0010: conv.i8  
  IL_0011: initblk  
  IL_0013: ldarg.1  
  IL_0014: ldc.i4.8 
  IL_0015: conv.i8  
  IL_0016: add      
  IL_0017: ldloc.0  
  IL_0018: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __std_exception_copy(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __std_exception_data* A_0, valuetype __std_exception_data* _to_object)
  IL_001D: ldarg.0  
  IL_001E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY02Q6AXXZ ??_7bad_weak_ptr@std@@6B@
  IL_0023: stind.i8 
  IL_0024: leave.s  loc_5B3
  IL_0026: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void std.exception.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype std.exception* A_0)
  IL_002C: ldarg.0  
  IL_002D: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0032: endfinally 
  IL_0033: ldarg.0  
  IL_0034: ret      
}
// MethodDef 0x0600001A  PtrToStringChars  flavor=IL rva=0x1384
.method /* PtrToStringChars */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: stloc.0  
  IL_0002: ldloc.0  
  IL_0003: brfalse.s loc_5CE
  IL_0005: call     int32 [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::get_OffsetToStringData()
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
  IL_0003: brfalse.s loc_5DE
  IL_0005: call     int32 [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::get_OffsetToStringData()
  IL_000A: conv.i8  
  IL_000B: ldloc.0  
  IL_000C: add      
  IL_000D: stloc.0  
  IL_000E: ldloc.0  
  IL_000F: stloc.2  
  IL_0010: ldc.i4.3 
  IL_0011: ldc.i4   0x400
  IL_0016: ldloc.2  
  IL_0017: ldarg.0  
  IL_0018: call     instance int32 [mscorlib]System.String::get_Length()
  IL_001D: ldc.i4.0 
  IL_001E: conv.i8  
  IL_001F: ldc.i4.0 
  IL_0020: ldc.i4.0 
  IL_0021: conv.i8  
  IL_0022: ldc.i4.0 
  IL_0023: conv.i8  
  IL_0024: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 WideCharToMultiByte(unsigned int32 A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsLong) unsigned int32 _to_object, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) char* _from_object, [hasfieldmarshal] int32 A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _to_object, int32 _from_object, [hasfieldmarshal] modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* A_0, [hasfieldmarshal] int32* A_0)
  IL_0029: conv.i8  
  IL_002A: stloc.1  
  IL_002B: ldloc.1  
  IL_002C: brtrue.s loc_611
  IL_002E: ldarg.0  
  IL_002F: call     instance int32 [mscorlib]System.String::get_Length()
  IL_0034: brfalse.s loc_611
  IL_0036: ldstr    aConversionFrom// "Conversion from WideChar to MultiByte f"...
  IL_003B: newobj   instance void [mscorlib]System.ArgumentException::.ctor(string)
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
  IL_0003: brfalse.s loc_62E
  IL_0005: call     int32 [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::get_OffsetToStringData()
  IL_000A: conv.i8  
  IL_000B: ldloc.0  
  IL_000C: add      
  IL_000D: stloc.0  
  IL_000E: ldloc.0  
  IL_000F: stloc.2  
  IL_0010: ldarg.1  
  IL_0011: ldc.i4   0x7FFFFFFF
  IL_0016: conv.i8  
  IL_0017: ble.un.s loc_644
  IL_0019: ldstr    aSizeOfStringEx// "Size of string exceeds INT_MAX."
  IL_001E: newobj   instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string)
  IL_0023: throw    
  IL_0024: ldc.i4.3 
  IL_0025: ldc.i4   0x400
  IL_002A: ldloc.2  
  IL_002B: ldarg.2  
  IL_002C: call     instance int32 [mscorlib]System.String::get_Length()
  IL_0031: ldarg.0  
  IL_0032: ldarg.1  
  IL_0033: conv.i4  
  IL_0034: ldc.i4.0 
  IL_0035: conv.i8  
  IL_0036: ldc.i4.0 
  IL_0037: conv.i8  
  IL_0038: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 WideCharToMultiByte(unsigned int32 A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsLong) unsigned int32 _to_object, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) char* _from_object, [hasfieldmarshal] int32 A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _to_object, int32 _from_object, [hasfieldmarshal] modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* A_0, [hasfieldmarshal] int32* A_0)
  IL_003D: conv.i8  
  IL_003E: stloc.1  
  IL_003F: ldloc.1  
  IL_0040: ldarg.1  
  IL_0041: bge.un.s loc_672
  IL_0043: ldloc.1  
  IL_0044: brtrue.s loc_66B
  IL_0046: ldarg.1  
  IL_0047: ldc.i4.1 
  IL_0048: conv.i8  
  IL_0049: bne.un.s loc_672
  IL_004B: ldloc.1  
  IL_004C: ldarg.0  
  IL_004D: add      
  IL_004E: ldc.i4.0 
  IL_004F: stind.i1 
  IL_0050: br.s     loc_67D
  IL_0052: ldstr    aConversionFrom// "Conversion from WideChar to MultiByte f"...
  IL_0057: newobj   instance void [mscorlib]System.ArgumentException::.ctor(string)
  IL_005C: throw    
  IL_005D: ret      
}
// MethodDef 0x0600001D  msclr.interop.details.GetUnicodeStringSize  flavor=IL rva=0x1460
.method /* msclr.interop.details.GetUnicodeStringSize */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i4   0x7FFFFFFF
  IL_0006: conv.i8  
  IL_0007: ble.un.s loc_694
  IL_0009: ldstr    aSizeOfStringEx// "Size of string exceeds INT_MAX."
  IL_000E: newobj   instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string)
  IL_0013: throw    
  IL_0014: ldc.i4.3 
  IL_0015: ldc.i4.0 
  IL_0016: ldarg.0  
  IL_0017: ldarg.1  
  IL_0018: conv.i4  
  IL_0019: ldc.i4.0 
  IL_001A: conv.i8  
  IL_001B: ldc.i4.0 
  IL_001C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 MultiByteToWideChar(unsigned int32 A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsLong) unsigned int32 _to_object, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _from_object, [hasfieldmarshal] int32 A_0, char* _to_object, int32 _from_object)
  IL_0021: conv.i8  
  IL_0022: stloc.0  
  IL_0023: ldloc.0  
  IL_0024: brtrue.s loc_6B4
  IL_0026: ldarg.1  
  IL_0027: brfalse.s loc_6B4
  IL_0029: ldstr    aConversionFrom_0// "Conversion from MultiByte to WideChar f"...
  IL_002E: newobj   instance void [mscorlib]System.ArgumentException::.ctor(string)
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
  IL_0001: ldc.i4   0x7FFFFFFF
  IL_0006: conv.i8  
  IL_0007: bgt.un.s loc_702
  IL_0009: ldarg.3  
  IL_000A: ldc.i4   0x7FFFFFFF
  IL_000F: conv.i8  
  IL_0010: bgt.un.s loc_702
  IL_0012: ldc.i4.3 
  IL_0013: ldc.i4.0 
  IL_0014: ldarg.2  
  IL_0015: ldarg.3  
  IL_0016: conv.i4  
  IL_0017: ldarg.0  
  IL_0018: ldarg.1  
  IL_0019: conv.i4  
  IL_001A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 MultiByteToWideChar(unsigned int32 A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsLong) unsigned int32 _to_object, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _from_object, [hasfieldmarshal] int32 A_0, char* _to_object, int32 _from_object)
  IL_001F: conv.i8  
  IL_0020: stloc.0  
  IL_0021: ldloc.0  
  IL_0022: ldarg.1  
  IL_0023: bge.un.s loc_6F7
  IL_0025: ldloc.0  
  IL_0026: brtrue.s loc_6ED
  IL_0028: ldarg.1  
  IL_0029: ldc.i4.1 
  IL_002A: conv.i8  
  IL_002B: bne.un.s loc_6F7
  IL_002D: ldloc.0  
  IL_002E: ldc.i4.2 
  IL_002F: conv.i8  
  IL_0030: mul      
  IL_0031: ldarg.0  
  IL_0032: add      
  IL_0033: ldc.i4.0 
  IL_0034: stind.i2 
  IL_0035: br.s     loc_70D
  IL_0037: ldstr    aConversionFrom_0// "Conversion from MultiByte to WideChar f"...
  IL_003C: newobj   instance void [mscorlib]System.ArgumentException::.ctor(string)
  IL_0041: throw    
  IL_0042: ldstr    aSizeOfStringEx// "Size of string exceeds INT_MAX."
  IL_0047: newobj   instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string)
  IL_004C: throw    
  IL_004D: ret      
}
// MethodDef 0x0600001F  msclr.interop.details.InternalAnsiToStringHelper  flavor=IL rva=0x171C
.method /* msclr.interop.details.InternalAnsiToStringHelper */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) unsigned int64 msclr.interop.details.GetUnicodeStringSize(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _str, unsigned int64 _count)
  IL_0007: stloc.1  
  IL_0008: ldloc.1  
  IL_0009: ldc.i4.1 
  IL_000A: conv.i8  
  IL_000B: sub      
  IL_000C: ldc.i4   0x7FFFFFFE
  IL_0011: conv.i8  
  IL_0012: bgt.un.s loc_77F
  IL_0014: ldloc.1  
  IL_0015: ldc.i8   0x7FFFFFFFFFFFFFFF
  IL_001E: bgt.un.s loc_736
  IL_0020: ldloc.1  
  IL_0021: ldc.i4.2 
  IL_0022: conv.i8  
  IL_0023: mul      
  IL_0024: br.s     loc_73F
  IL_0026: ldc.i8   0xFFFFFFFFFFFFFFFF
  IL_002F: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void* new[](unsigned int64 A_0)
  IL_0034: stloc.0  
  IL_0035: ldloca.s 4
  IL_0037: ldloc.0  
  IL_0038: stind.i8 
  IL_0039: ldloc.0  
  IL_003A: brtrue.s loc_752
  IL_003C: newobj   instance void [mscorlib]System.InsufficientMemoryException::.ctor()
  IL_0041: throw    
  IL_0042: ldloc.0  
  IL_0043: ldloc.1  
  IL_0044: ldarg.0  
  IL_0045: ldarg.1  
  IL_0046: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void msclr.interop.details.WriteUnicodeString(char* _dest, unsigned int64 _size, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _src, unsigned int64 _count)
  IL_004B: ldloc.0  
  IL_004C: ldc.i4.0 
  IL_004D: ldloc.1  
  IL_004E: conv.i4  
  IL_004F: ldc.i4.1 
  IL_0050: sub      
  IL_0051: newobj   instance void [mscorlib]System.String::.ctor(char*, int32, int32)
  IL_0056: stloc.3  
  IL_0057: leave.s  loc_777
  IL_0059: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void msclr.interop.details.char_buffer<wchar_t>.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype msclr.interop.details.char_buffer<wchar_t>* _size)
  IL_005F: ldloca.s 4
  IL_0061: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0066: endfinally 
  IL_0067: ldloc.0  
  IL_0068: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_006D: ldloc.3  
  IL_006E: ret      
  IL_006F: ldstr    aSizeOfStringEx// "Size of string exceeds INT_MAX."
  IL_0074: newobj   instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string)
  IL_0079: throw    
  IL_007A: .byte    0
  IL_007B: ldnull   
  IL_007C: stloc.2  
  IL_007D: leave.s  loc_79D
  IL_007F: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void msclr.interop.details.char_buffer<wchar_t>.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype msclr.interop.details.char_buffer<wchar_t>* _size)
  IL_0085: ldloca.s 4
  IL_0087: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_008C: endfinally 
  IL_008D: ldloc.2  
  IL_008E: ret      
}
// MethodDef 0x06000020  SaveMergennFiles  flavor=IL rva=0x1A80
.method /* SaveMergennFiles */ cil managed { 
  IL_0000: newobj   instance void WrapSaveMergeNNFiles.WrapCall::.ctor()
  IL_0005: ldarg.0  
  IL_0006: ldarg.1  
  IL_0007: call     instance void WrapSaveMergeNNFiles.WrapCall::WrapperSaveMergennFiles(modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* filename, modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* values)
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
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_0007: ret      
}
// MethodDef 0x06000024  msclr.interop.details.char_buffer<char>.{ctor}  flavor=IL rva=0x1690
.method /* msclr.interop.details.char_buffer<char>.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void* new[](unsigned int64 A_0)
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
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_0007: ret      
}
// MethodDef 0x06000027  msclr.interop.details.char_buffer<wchar_t>.{ctor}  flavor=IL rva=0x16CC
.method /* msclr.interop.details.char_buffer<wchar_t>.{ctor} */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ldc.i8   0x7FFFFFFFFFFFFFFF
  IL_000A: bgt.un.s loc_823
  IL_000C: ldarg.1  
  IL_000D: ldc.i4.2 
  IL_000E: conv.i8  
  IL_000F: mul      
  IL_0010: stloc.0  
  IL_0011: br.s     loc_82D
  IL_0013: ldc.i8   0xFFFFFFFFFFFFFFFF
  IL_001C: stloc.0  
  IL_001D: ldarg.0  
  IL_001E: ldloc.0  
  IL_001F: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void* new[](unsigned int64 A_0)
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
  IL_0004: brtrue.s loc_84A
  IL_0006: ldnull   
  IL_0007: stloc.2  
  IL_0008: br.s     loc_865
  IL_000A: ldloc.0  
  IL_000B: stloc.1  
  IL_000C: ldloc.0  
  IL_000D: ldind.i1 
  IL_000E: brfalse.s loc_859
  IL_0010: ldloc.1  
  IL_0011: ldc.i4.1 
  IL_0012: conv.i8  
  IL_0013: add      
  IL_0014: stloc.1  
  IL_0015: ldloc.1  
  IL_0016: ldind.i1 
  IL_0017: brtrue.s loc_850
  IL_0019: ldloc.1  
  IL_001A: ldloc.0  
  IL_001B: sub      
  IL_001C: stloc.3  
  IL_001D: ldloc.0  
  IL_001E: ldloc.3  
  IL_001F: call     string msclr.interop.details.InternalAnsiToStringHelper(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _src, unsigned int64 _count)
  IL_0024: stloc.2  
  IL_0025: ldloc.2  
  IL_0026: ret      
}
// MethodDef 0x06000029  msclr.interop._Marshal_as_impl<class System::String ^>  flavor=IL rva=0x19BC
.method /* msclr.interop._Marshal_as_impl<class System::String ^> */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: brtrue.s loc_875
  IL_0003: ldnull   
  IL_0004: ret      
  IL_0005: ldarg.1  
  IL_0006: stloc.0  
  IL_0007: ldarg.1  
  IL_0008: ldind.i1 
  IL_0009: brfalse.s loc_884
  IL_000B: ldloc.0  
  IL_000C: ldc.i4.1 
  IL_000D: conv.i8  
  IL_000E: add      
  IL_000F: stloc.0  
  IL_0010: ldloc.0  
  IL_0011: ldind.i1 
  IL_0012: brtrue.s loc_87B
  IL_0014: ldloc.0  
  IL_0015: ldarg.1  
  IL_0016: sub      
  IL_0017: stloc.1  
  IL_0018: ldarg.1  
  IL_0019: ldloc.1  
  IL_001A: call     string msclr.interop.details.InternalAnsiToStringHelper(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _src, unsigned int64 _count)
  IL_001F: ret      
}
// MethodDef 0x0600002A  new  flavor=IL rva=0x1090
.method /* new */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: ret      
}
// MethodDef 0x0600002B  <CrtImplementationDetails>.ThrowNestedModuleLoadException  flavor=IL rva=0x3940
.method /* <CrtImplementationDetails>.ThrowNestedModuleLoadException */ cil managed { 
  IL_0000: ldstr    aANestedExcepti// "A nested exception occurred after the p"...
  IL_0005: ldarg.0  
  IL_0006: ldarg.1  
  IL_0007: newobj   instance void <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::.ctor(string message, class [mscorlib]System.Exception innerException, class [mscorlib]System.Exception nestedException)
  IL_000C: throw    
  IL_000D: ret      
}
// MethodDef 0x0600002C  <CrtImplementationDetails>.ThrowModuleLoadException  flavor=IL rva=0x32F0
.method /* <CrtImplementationDetails>.ThrowModuleLoadException */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: newobj   instance void <CrtImplementationDetails>.ModuleLoadException::.ctor(string message)
  IL_0006: throw    
  IL_0007: ret      
}
// MethodDef 0x0600002D  <CrtImplementationDetails>.ThrowModuleLoadException  flavor=IL rva=0x3304
.method /* <CrtImplementationDetails>.ThrowModuleLoadException */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: newobj   instance void <CrtImplementationDetails>.ModuleLoadException::.ctor(string message, class [mscorlib]System.Exception innerException)
  IL_0007: throw    
  IL_0008: ret      
}
// MethodDef 0x0600002E  <CrtImplementationDetails>.RegisterModuleUninitializer  flavor=IL rva=0x3420
.method /* <CrtImplementationDetails>.RegisterModuleUninitializer */ cil managed { 
  IL_0000: ldsfld   class <CrtImplementationDetails>.ModuleUninitializer <CrtImplementationDetails>.ModuleUninitializer::_ModuleUninitializer
  IL_0005: ldarg.0  
  IL_0006: call     instance void <CrtImplementationDetails>.ModuleUninitializer::AddHandler(class [mscorlib]System.EventHandler handler)
  IL_000B: ret      
}
// MethodDef 0x0600002F  <CrtImplementationDetails>.FromGUID  flavor=IL rva=0x3438
.method /* <CrtImplementationDetails>.FromGUID */ cil managed { 
  IL_0000: ldloca.s 0
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
  IL_0014: ldc.i4.s 9
  IL_0016: conv.i8  
  IL_0017: add      
  IL_0018: ldind.u1 
  IL_0019: ldarg.0  
  IL_001A: ldc.i4.s 0xA
  IL_001C: conv.i8  
  IL_001D: add      
  IL_001E: ldind.u1 
  IL_001F: ldarg.0  
  IL_0020: ldc.i4.s 0xB
  IL_0022: conv.i8  
  IL_0023: add      
  IL_0024: ldind.u1 
  IL_0025: ldarg.0  
  IL_0026: ldc.i4.s 0xC
  IL_0028: conv.i8  
  IL_0029: add      
  IL_002A: ldind.u1 
  IL_002B: ldarg.0  
  IL_002C: ldc.i4.s 0xD
  IL_002E: conv.i8  
  IL_002F: add      
  IL_0030: ldind.u1 
  IL_0031: ldarg.0  
  IL_0032: ldc.i4.s 0xE
  IL_0034: conv.i8  
  IL_0035: add      
  IL_0036: ldind.u1 
  IL_0037: ldarg.0  
  IL_0038: ldc.i4.s 0xF
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: ldind.u1 
  IL_003D: call     instance void [mscorlib]System.Guid::.ctor(unsigned int32, unsigned int16, unsigned int16, unsigned int8, unsigned int8, unsigned int8, unsigned int8, unsigned int8, unsigned int8, unsigned int8, unsigned int8)
  IL_0042: ldloc.0  
  IL_0043: ret      
}
// MethodDef 0x06000030  __get_default_appdomain  flavor=IL rva=0x3488
.method /* __get_default_appdomain */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: conv.i8  
  IL_0002: stloc.0  
  IL_0003: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __s_GUID _GUID_cb2f6722_ab3a_11d2_9c40_00c04fa30a3e
  IL_0008: call     valuetype [mscorlib]System.Guid <CrtImplementationDetails>.FromGUID(modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype _GUID* guid)
  IL_000D: stloc.3  
  IL_000E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __s_GUID _GUID_cb2f6723_ab3a_11d2_9c40_00c04fa30a3e
  IL_0013: call     valuetype [mscorlib]System.Guid <CrtImplementationDetails>.FromGUID(modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype _GUID* guid)
  IL_0018: ldloc.3  
  IL_0019: call     native int [mscorlib]System.Runtime.InteropServices.RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(valuetype [mscorlib]System.Guid, valuetype [mscorlib]System.Guid)
  IL_001E: stloc.s  4
  IL_0020: ldloca.s 4
  IL_0022: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_0027: stloc.0  
  IL_0028: leave.s  loc_966
  IL_002A: call     int32 [mscorlib]System.Runtime.InteropServices.Marshal::GetHRForException(class [mscorlib]System.Exception)
  IL_002F: stloc.1  
  IL_0030: leave.s  loc_962
  IL_0032: ldloc.1  
  IL_0033: ldc.i4.0 
  IL_0034: blt.s    loc_985
  IL_0036: ldloc.0  
  IL_0037: ldind.i8 
  IL_0038: ldc.i4.s 0x68
  IL_003A: conv.i8  
  IL_003B: add      
  IL_003C: ldind.i8 
  IL_003D: stloc.2  
  IL_003E: ldloc.0  
  IL_003F: ldarg.0  
  IL_0040: ldloc.2  
  IL_0041: calli    T0x11000044
  IL_0046: stloc.1  
  IL_0047: ldloc.0  
  IL_0048: dup      
  IL_0049: ldind.i8 
  IL_004A: ldc.i4.s 0x10
  IL_004C: conv.i8  
  IL_004D: add      
  IL_004E: ldind.i8 
  IL_004F: calli    T0x11000043
  IL_0054: pop      
  IL_0055: ldloc.1  
  IL_0056: ret      
}
// MethodDef 0x06000031  __release_appdomain  flavor=IL rva=0x3508
.method /* __release_appdomain */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: dup      
  IL_0002: ldind.i8 
  IL_0003: ldc.i4.s 0x10
  IL_0005: conv.i8  
  IL_0006: add      
  IL_0007: ldind.i8 
  IL_0008: calli    T0x11000043
  IL_000D: pop      
  IL_000E: ret      
}
// MethodDef 0x06000032  <CrtImplementationDetails>.GetDefaultDomain  flavor=IL rva=0x3524
.method /* <CrtImplementationDetails>.GetDefaultDomain */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: conv.i8  
  IL_0002: stloc.1  
  IL_0003: ldloca.s 1
  IL_0005: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) modopt([mscorlib]System.Runtime.CompilerServices.IsLong) int32 __get_default_appdomain(valuetype IUnknown** ppUnk)
  IL_000A: stloc.0  
  IL_000B: ldloc.0  
  IL_000C: ldc.i4.0 
  IL_000D: blt.s    loc_9CC
  IL_000F: ldloca.s 3
  IL_0011: ldloc.1  
  IL_0012: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0017: ldloc.3  
  IL_0018: call     object [mscorlib]System.Runtime.InteropServices.Marshal::GetObjectForIUnknown(native int)
  IL_001D: castclass [mscorlib]System.AppDomain
  IL_0022: stloc.2  
  IL_0023: leave.s  loc_9D4
  IL_0025: ldloc.1  
  IL_0026: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __release_appdomain(valuetype IUnknown* ppUnk)
  IL_002B: endfinally 
  IL_002C: ldloc.0  
  IL_002D: call     void [mscorlib]System.Runtime.InteropServices.Marshal::ThrowExceptionForHR(int32)
  IL_0032: ldnull   
  IL_0033: ret      
  IL_0034: ldloc.2  
  IL_0035: ret      
}
// MethodDef 0x06000033  <CrtImplementationDetails>.DoCallBackInDefaultDomain  flavor=IL rva=0x3584
.method /* <CrtImplementationDetails>.DoCallBackInDefaultDomain */ cil managed { 
  IL_0000: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __s_GUID _GUID_90f1a06c_7712_4762_86b5_7a5eba6bdb02
  IL_0005: call     valuetype [mscorlib]System.Guid <CrtImplementationDetails>.FromGUID(modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype _GUID* guid)
  IL_000A: stloc.s  4
  IL_000C: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype __s_GUID _GUID_90f1a06e_7712_4762_86b5_7a5eba6bdb02
  IL_0011: call     valuetype [mscorlib]System.Guid <CrtImplementationDetails>.FromGUID(modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype _GUID* guid)
  IL_0016: ldloc.s  4
  IL_0018: call     native int [mscorlib]System.Runtime.InteropServices.RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(valuetype [mscorlib]System.Guid, valuetype [mscorlib]System.Guid)
  IL_001D: stloc.s  5
  IL_001F: ldloca.s 5
  IL_0021: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_0026: stloc.0  
  IL_0027: call     class [mscorlib]System.AppDomain <CrtImplementationDetails>.GetDefaultDomain()
  IL_002C: ldloc.0  
  IL_002D: ldind.i8 
  IL_002E: ldc.i4.s 0x40
  IL_0030: conv.i8  
  IL_0031: add      
  IL_0032: ldind.i8 
  IL_0033: stloc.3  
  IL_0034: call     instance int32 [mscorlib]System.AppDomain::get_Id()
  IL_0039: stloc.2  
  IL_003A: ldloc.0  
  IL_003B: ldloc.2  
  IL_003C: ldarg.0  
  IL_003D: ldarg.1  
  IL_003E: ldloc.3  
  IL_003F: calli    T0x11000045
  IL_0044: stloc.1  
  IL_0045: ldloc.1  
  IL_0046: ldc.i4.0 
  IL_0047: bge.s    loc_A2F
  IL_0049: ldloc.1  
  IL_004A: call     void [mscorlib]System.Runtime.InteropServices.Marshal::ThrowExceptionForHR(int32)
  IL_004F: leave.s  loc_A40
  IL_0051: ldloc.0  
  IL_0052: dup      
  IL_0053: ldind.i8 
  IL_0054: ldc.i4.s 0x10
  IL_0056: conv.i8  
  IL_0057: add      
  IL_0058: ldind.i8 
  IL_0059: calli    T0x11000043
  IL_005E: pop      
  IL_005F: endfinally 
  IL_0060: ret      
}
// MethodDef 0x06000034  __scrt_is_safe_for_managed_code  flavor=IL rva=0x363C
.method /* __scrt_is_safe_for_managed_code */ cil managed { 
  IL_0000: ldsfld   unsigned int32 __scrt_native_dllmain_reason
  IL_0005: stloc.0  
  IL_0006: ldloc.0  
  IL_0007: brfalse.s loc_A5F
  IL_0009: ldloc.0  
  IL_000A: ldc.i4.1 
  IL_000B: beq.s    loc_A5F
  IL_000D: ldc.i4.1 
  IL_000E: ret      
  IL_000F: ldc.i4.0 
  IL_0010: ret      
}
// MethodDef 0x06000035  <CrtImplementationDetails>.DefaultDomain.DoNothing  flavor=IL rva=0x3670
.method /* <CrtImplementationDetails>.DefaultDomain.DoNothing */ cil managed { 
  IL_0000: ldc.i4   0x7FFFFFFF
  IL_0005: box      [mscorlib]System.Int32
  IL_000A: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_000F: ldc.i4.0 
  IL_0010: ret      
}
// MethodDef 0x06000036  <CrtImplementationDetails>.DefaultDomain.HasPerProcess  flavor=IL rva=0x3690
.method /* <CrtImplementationDetails>.DefaultDomain.HasPerProcess */ cil managed { 
  IL_0000: ldsfld   valuetype <CrtImplementationDetails>.TriBool ?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0005: ldc.i4.2 
  IL_0006: bne.un.s loc_ACD
  IL_0008: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_mp_a
  IL_000D: stloc.0  
  IL_000E: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_mp_a
  IL_0013: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_mp_z
  IL_0018: bge.un.s loc_AC5
  IL_001A: ldloc.0  
  IL_001B: ldind.i8 
  IL_001C: brtrue.s loc_ABD
  IL_001E: ldloc.0  
  IL_001F: ldc.i4.8 
  IL_0020: conv.i8  
  IL_0021: add      
  IL_0022: stloc.0  
  IL_0023: ldloc.0  
  IL_0024: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_mp_z
  IL_0029: blt.un.s loc_AAA
  IL_002B: br.s     loc_AC5
  IL_002D: ldc.i4.m1 
  IL_002E: stsfld   valuetype <CrtImplementationDetails>.TriBool ?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0033: ldc.i4.1 
  IL_0034: ret      
  IL_0035: ldc.i4.0 
  IL_0036: stsfld   valuetype <CrtImplementationDetails>.TriBool ?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_003B: ldc.i4.0 
  IL_003C: ret      
  IL_003D: ldsfld   valuetype <CrtImplementationDetails>.TriBool ?hasPerProcess@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0042: ldc.i4.m1 
  IL_0043: ceq      
  IL_0045: conv.u1  
  IL_0046: ret      
}
// MethodDef 0x06000037  <CrtImplementationDetails>.DefaultDomain.HasNative  flavor=IL rva=0x36E4
.method /* <CrtImplementationDetails>.DefaultDomain.HasNative */ cil managed { 
  IL_0000: ldsfld   valuetype <CrtImplementationDetails>.TriBool ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0005: ldc.i4.2 
  IL_0006: bne.un.s loc_B4A
  IL_0008: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AHXZ __xi_a
  IL_000D: stloc.1  
  IL_000E: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AHXZ __xi_a
  IL_0013: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AHXZ __xi_z
  IL_0018: bge.un.s loc_B15
  IL_001A: ldloc.1  
  IL_001B: ldind.i8 
  IL_001C: brtrue.s loc_B0D
  IL_001E: ldloc.1  
  IL_001F: ldc.i4.8 
  IL_0020: conv.i8  
  IL_0021: add      
  IL_0022: stloc.1  
  IL_0023: ldloc.1  
  IL_0024: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AHXZ __xi_z
  IL_0029: blt.un.s loc_AFA
  IL_002B: br.s     loc_B15
  IL_002D: ldc.i4.m1 
  IL_002E: stsfld   valuetype <CrtImplementationDetails>.TriBool ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0033: ldc.i4.1 
  IL_0034: ret      
  IL_0035: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AXXZ __xc_a
  IL_003A: stloc.0  
  IL_003B: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AXXZ __xc_a
  IL_0040: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AXXZ __xc_z
  IL_0045: bge.un.s loc_B42
  IL_0047: ldloc.0  
  IL_0048: ldind.i8 
  IL_0049: brtrue.s loc_B3A
  IL_004B: ldloc.0  
  IL_004C: ldc.i4.8 
  IL_004D: conv.i8  
  IL_004E: add      
  IL_004F: stloc.0  
  IL_0050: ldloc.0  
  IL_0051: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AXXZ __xc_z
  IL_0056: blt.un.s loc_B27
  IL_0058: br.s     loc_B42
  IL_005A: ldc.i4.m1 
  IL_005B: stsfld   valuetype <CrtImplementationDetails>.TriBool ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0060: ldc.i4.1 
  IL_0061: ret      
  IL_0062: ldc.i4.0 
  IL_0063: stsfld   valuetype <CrtImplementationDetails>.TriBool ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_0068: ldc.i4.0 
  IL_0069: ret      
  IL_006A: ldsfld   valuetype <CrtImplementationDetails>.TriBool ?hasNative@DefaultDomain@<CrtImplementationDetails>@@0W4TriBool@2@A
  IL_006F: ldc.i4.m1 
  IL_0070: ceq      
  IL_0072: conv.u1  
  IL_0073: ret      
}
// MethodDef 0x06000038  <CrtImplementationDetails>.DefaultDomain.NeedsInitialization  flavor=IL rva=0x3764
.method /* <CrtImplementationDetails>.DefaultDomain.NeedsInitialization */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.DefaultDomain.HasPerProcess()
  IL_0005: brfalse.s loc_B6E
  IL_0007: ldsfld   bool ?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_000C: brfalse.s loc_B83
  IL_000E: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.DefaultDomain.HasNative()
  IL_0013: brfalse.s loc_B87
  IL_0015: ldsfld   bool ?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_001A: brtrue.s loc_B87
  IL_001C: ldsfld   valuetype __scrt_native_startup_state __scrt_current_native_startup_state
  IL_0021: brtrue.s loc_B87
  IL_0023: ldc.i4.1 
  IL_0024: stloc.0  
  IL_0025: br.s     loc_B89
  IL_0027: ldc.i4.0 
  IL_0028: stloc.0  
  IL_0029: ldloc.0  
  IL_002A: conv.u1  
  IL_002B: ret      
}
// MethodDef 0x06000039  <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization  flavor=IL rva=0x379C
.method /* <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization */ cil managed { 
  IL_0000: ldsfld   bool ?Entered@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0005: ret      
}
// MethodDef 0x0600003A  <CrtImplementationDetails>.DefaultDomain.Initialize  flavor=IL rva=0x37B0
.method /* <CrtImplementationDetails>.DefaultDomain.Initialize */ cil managed { 
  IL_0000: ldsfld   int32** __unep@?DoNothing@DefaultDomain@<CrtImplementationDetails>@@$$FCAJPEAX@Z
  IL_0005: ldc.i4.0 
  IL_0006: conv.i8  
  IL_0007: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.DoCallBackInDefaultDomain(cdecl modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) modopt([mscorlib]System.Runtime.CompilerServices.IsLong) int32((void*)) function, void* cookie)
  IL_000C: ret      
}
// MethodDef 0x0600003B  ?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ  flavor=IL rva=0x1000
.method /* ?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   int32 ?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA
  IL_0006: ret      
}
// MethodDef 0x0600003C  ?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ  flavor=IL rva=0x1014
.method /* ?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   int32 ?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA
  IL_0006: ret      
}
// MethodDef 0x0600003D  ?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ  flavor=IL rva=0x1028
.method /* ?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   bool ?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA
  IL_0006: ret      
}
// MethodDef 0x0600003E  ?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x103C
.method /* ?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0006: ret      
}
// MethodDef 0x0600003F  ?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x1050
.method /* ?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0006: ret      
}
// MethodDef 0x06000040  ?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x1064
.method /* ?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0006: ret      
}
// MethodDef 0x06000041  ?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ  flavor=IL rva=0x1078
.method /* ?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0006: ret      
}
// MethodDef 0x06000042  <CrtImplementationDetails>.LanguageSupport.InitializeVtables  flavor=IL rva=0x3994
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeVtables */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldstr    aTheCModuleFail// "The C++ module failed to load during vt"...
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_000B: pop      
  IL_000C: ldc.i4.1 
  IL_000D: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0012: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xi_vt_a
  IL_0017: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xi_vt_z
  IL_001C: call     void _initterm_m(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(())* pfbegin, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(())* pfend)
  IL_0021: ldc.i4.2 
  IL_0022: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0027: ret      
}
// MethodDef 0x06000043  <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain  flavor=IL rva=0x39C8
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldstr    aTheCModuleFail_0// "The C++ module failed to load while att"...
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_000B: pop      
  IL_000C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.DefaultDomain.Initialize()
  IL_0011: ret      
}
// MethodDef 0x06000044  <CrtImplementationDetails>.LanguageSupport.InitializeNative  flavor=IL rva=0x39E8
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeNative */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldstr    aTheCModuleFail_1// "The C++ module failed to load during na"...
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_000B: pop      
  IL_000C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __security_init_cookie()
  IL_0011: ldc.i4.1 
  IL_0012: stsfld   bool ?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0017: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool __scrt_is_safe_for_managed_code()
  IL_001C: brtrue.s loc_C93
  IL_001E: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void abort()
  IL_0023: ldsfld   valuetype __scrt_native_startup_state __scrt_current_native_startup_state
  IL_0028: ldc.i4.1 
  IL_0029: bne.un.s loc_CA0
  IL_002B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void abort()
  IL_0030: ldsfld   valuetype __scrt_native_startup_state __scrt_current_native_startup_state
  IL_0035: brtrue.s loc_CF0
  IL_0037: ldc.i4.1 
  IL_0038: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_003D: ldc.i4.1 
  IL_003E: stsfld   valuetype __scrt_native_startup_state __scrt_current_native_startup_state
  IL_0043: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AHXZ __xi_a
  IL_0048: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AHXZ __xi_z
  IL_004D: call     int32 _initterm_e(cdecl modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32(())* pfbegin, cdecl modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32(())* pfend)
  IL_0052: brfalse.s loc_CCF
  IL_0054: ldarg.0  
  IL_0055: call     string 'gcroot<System::String ^>..PE$AAVString@System@@'(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t)
  IL_005A: call     void <CrtImplementationDetails>.ThrowModuleLoadException(string errorMessage)
  IL_005F: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AXXZ __xc_a
  IL_0064: ldsflda  valuetype <CppImplementationDetails>.$ArrayType$$$BY0A@P6AXXZ __xc_z
  IL_0069: call     void _initterm(cdecl modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void(())* pfbegin, cdecl modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void(())* pfend)
  IL_006E: ldc.i4.2 
  IL_006F: stsfld   valuetype __scrt_native_startup_state __scrt_current_native_startup_state
  IL_0074: ldc.i4.1 
  IL_0075: stsfld   bool ?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_007A: ldc.i4.2 
  IL_007B: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0080: ret      
}
// MethodDef 0x06000045  <CrtImplementationDetails>.LanguageSupport.InitializePerProcess  flavor=IL rva=0x3A78
.method /* <CrtImplementationDetails>.LanguageSupport.InitializePerProcess */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldstr    aTheCModuleFail_2// "The C++ module failed to load during pr"...
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_000B: pop      
  IL_000C: ldc.i4.1 
  IL_000D: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0012: call     int32 _initatexit_m()
  IL_0017: pop      
  IL_0018: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_mp_a
  IL_001D: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_mp_z
  IL_0022: call     void _initterm_m(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(())* pfbegin, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(())* pfend)
  IL_0027: ldc.i4.2 
  IL_0028: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_002D: ldc.i4.1 
  IL_002E: stsfld   bool ?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0033: ret      
}
// MethodDef 0x06000046  <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain  flavor=IL rva=0x3AB8
.method /* <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldstr    aTheCModuleFail_3// "The C++ module failed to load during ap"...
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_000B: pop      
  IL_000C: ldc.i4.1 
  IL_000D: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_0012: call     int32 _initatexit_app_domain()
  IL_0017: pop      
  IL_0018: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_ma_a
  IL_001D: ldsflda  modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CppImplementationDetails>.$ArrayType$$$BY00Q6MPEBXXZ __xc_ma_z
  IL_0022: call     void _initterm_m(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(())* pfbegin, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(())* pfend)
  IL_0027: ldc.i4.2 
  IL_0028: stsfld   valuetype <CrtImplementationDetails>.Progress ?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A
  IL_002D: ret      
}
// MethodDef 0x06000047  <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer  flavor=IL rva=0x3AF4
.method /* <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldstr    aTheCModuleFail_4// "The C++ module failed to load during re"...
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_000B: pop      
  IL_000C: ldnull   
  IL_000D: ldftn    void <CrtImplementationDetails>.LanguageSupport.DomainUnload(object A_0, class [mscorlib]System.EventArgs A_1)
  IL_0013: newobj   instance void [mscorlib]System.EventHandler::.ctor(object, native int)
  IL_0018: call     void <CrtImplementationDetails>.RegisterModuleUninitializer(class [mscorlib]System.EventHandler handler)
  IL_001D: ret      
}
// MethodDef 0x06000048  <CrtImplementationDetails>.LanguageSupport._Initialize  flavor=IL rva=0x3B20
.method /* <CrtImplementationDetails>.LanguageSupport._Initialize */ cil managed { 
  IL_0000: call     class [mscorlib]System.AppDomain [mscorlib]System.AppDomain::get_CurrentDomain()
  IL_0005: call     instance bool [mscorlib]System.AppDomain::IsDefaultAppDomain()
  IL_000A: stsfld   bool ?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA
  IL_000F: ldsfld   bool ?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA
  IL_0014: ldc.i4.0 
  IL_0015: bne.un.s loc_DAE
  IL_0017: ldsfld   bool ?Entered@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_001C: br.s     loc_DAF
  IL_001E: ldc.i4.1 
  IL_001F: stsfld   bool ?Entered@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0024: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void* _getFiberPtrId()
  IL_0029: stloc.s  4
  IL_002B: ldc.i4.0 
  IL_002C: stloc.3  
  IL_002D: ldc.i4.0 
  IL_002E: stloc.0  
  IL_002F: ldc.i4.0 
  IL_0030: stloc.1  
  IL_0031: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_0036: ldloc.0  
  IL_0037: brtrue.s loc_DFA
  IL_0039: leave.s  loc_DEB
  IL_003B: ldsflda  void* __scrt_native_startup_lock
  IL_0040: ldloc.s  4
  IL_0042: ldc.i4.0 
  IL_0043: conv.i8  
  IL_0044: call     int64 [mscorlib]System.Threading.Interlocked::CompareExchange(int64&, int64, int64)
  IL_0049: stloc.2  
  IL_004A: ldloc.2  
  IL_004B: brtrue.s loc_DE1
  IL_004D: ldc.i4.1 
  IL_004E: stloc.0  
  IL_004F: br.s     loc_DEA
  IL_0051: ldloc.2  
  IL_0052: ldloc.s  4
  IL_0054: bne.un.s loc_DEA
  IL_0056: ldc.i4.1 
  IL_0057: stloc.3  
  IL_0058: ldc.i4.1 
  IL_0059: stloc.0  
  IL_005A: endfinally 
  IL_005B: ldloc.0  
  IL_005C: brtrue.s loc_DF8
  IL_005E: ldc.i4   0x3E8
  IL_0063: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void Sleep(modopt([mscorlib]System.Runtime.CompilerServices.IsLong) unsigned int32 A_0)
  IL_0068: br.s     loc_DC6
  IL_006A: ldarg.0  
  IL_006B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.InitializeVtables(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_0070: ldsfld   bool ?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA
  IL_0075: brfalse.s loc_E15
  IL_0077: ldarg.0  
  IL_0078: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.InitializeNative(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_007D: ldarg.0  
  IL_007E: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.InitializePerProcess(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_0083: br.s     loc_E22
  IL_0085: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.DefaultDomain.NeedsInitialization()
  IL_008A: ldc.i4.0 
  IL_008B: bne.un.s loc_E20
  IL_008D: ldloc.1  
  IL_008E: br.s     loc_E21
  IL_0090: ldc.i4.1 
  IL_0091: stloc.1  
  IL_0092: leave.s  loc_E35
  IL_0094: ldloc.3  
  IL_0095: brtrue.s loc_E34
  IL_0097: ldsflda  void* __scrt_native_startup_lock
  IL_009C: ldc.i4.0 
  IL_009D: conv.i8  
  IL_009E: call     int64 [mscorlib]System.Threading.Interlocked::Exchange(int64&, int64)
  IL_00A3: pop      
  IL_00A4: endfinally 
  IL_00A5: ldloc.1  
  IL_00A6: brfalse.s loc_E3E
  IL_00A8: ldarg.0  
  IL_00A9: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_00AE: ldarg.0  
  IL_00AF: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_00B4: ldc.i4.1 
  IL_00B5: stsfld   int32 ?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA
  IL_00BA: ldarg.0  
  IL_00BB: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_00C0: ret      
}
// MethodDef 0x06000049  <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain  flavor=IL rva=0x37CC
.method /* <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain */ cil managed { 
  IL_0000: call     void _app_exit_callback()
  IL_0005: ret      
}
// MethodDef 0x0600004A  <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain  flavor=IL rva=0x37E0
.method /* <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain */ cil managed { 
  IL_0000: call     void _exit_callback()
  IL_0005: ldc.i4.0 
  IL_0006: stsfld   bool ?InitializedPerProcess@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_000B: ldsfld   bool ?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0010: brfalse.s loc_E93
  IL_0012: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void _cexit()
  IL_0017: ldc.i4.0 
  IL_0018: stsfld   valuetype __scrt_native_startup_state __scrt_current_native_startup_state
  IL_001D: ldc.i4.0 
  IL_001E: stsfld   bool ?InitializedNativeFromCCTOR@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0023: ldc.i4.0 
  IL_0024: stsfld   bool ?InitializedNative@DefaultDomain@<CrtImplementationDetails>@@2_NA
  IL_0029: ldc.i4.0 
  IL_002A: ret      
}
// MethodDef 0x0600004B  <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain  flavor=IL rva=0x3818
.method /* <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization()
  IL_0005: brfalse.s loc_EC9
  IL_0007: call     class [mscorlib]System.AppDomain [mscorlib]System.AppDomain::get_CurrentDomain()
  IL_000C: call     instance bool [mscorlib]System.AppDomain::IsDefaultAppDomain()
  IL_0011: brfalse.s loc_EBD
  IL_0013: ldc.i4.0 
  IL_0014: conv.i8  
  IL_0015: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) modopt([mscorlib]System.Runtime.CompilerServices.IsLong) int32 <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain(void* cookie)
  IL_001A: pop      
  IL_001B: br.s     loc_EC9
  IL_001D: ldsfld   int32** __unep@?_UninitializeDefaultDomain@LanguageSupport@<CrtImplementationDetails>@@$$FCAJPEAX@Z
  IL_0022: ldc.i4.0 
  IL_0023: conv.i8  
  IL_0024: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.DoCallBackInDefaultDomain(cdecl modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) modopt([mscorlib]System.Runtime.CompilerServices.IsLong) int32((void*)) function, void* cookie)
  IL_0029: ret      
}
// MethodDef 0x0600004C  <CrtImplementationDetails>.LanguageSupport.DomainUnload  flavor=IL rva=0x3850
.method /* <CrtImplementationDetails>.LanguageSupport.DomainUnload */ cil managed { 
  IL_0000: ldsfld   int32 ?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA
  IL_0005: brfalse.s loc_EFE
  IL_0007: ldsflda  int32 ?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA
  IL_000C: ldc.i4.1 
  IL_000D: call     int32 [mscorlib]System.Threading.Interlocked::Exchange(int32&, int32)
  IL_0012: brtrue.s loc_EFE
  IL_0014: ldsflda  int32 ?Count@AllDomains@<CrtImplementationDetails>@@2HA
  IL_0019: call     int32 [mscorlib]System.Threading.Interlocked::Decrement(int32&)
  IL_001E: ldc.i4.0 
  IL_001F: ceq      
  IL_0021: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain()
  IL_0026: conv.u1  
  IL_0027: brfalse.s loc_EFE
  IL_0029: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain()
  IL_002E: ret      
}
// MethodDef 0x0600004D  <CrtImplementationDetails>.LanguageSupport.Cleanup  flavor=IL rva=0x3C24
.method /* <CrtImplementationDetails>.LanguageSupport.Cleanup */ cil managed { 
  IL_0000: ldsflda  int32 ?Count@AllDomains@<CrtImplementationDetails>@@2HA
  IL_0005: call     int32 [mscorlib]System.Threading.Interlocked::Decrement(int32&)
  IL_000A: ldc.i4.0 
  IL_000B: ceq      
  IL_000D: conv.u1  
  IL_000E: stloc.1  
  IL_000F: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain()
  IL_0014: ldloc.1  
  IL_0015: brfalse.s loc_F1C
  IL_0017: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain()
  IL_001C: leave.s  loc_F32
  IL_001E: stloc.0  
  IL_001F: ldarg.1  
  IL_0020: ldloc.0  
  IL_0021: call     void <CrtImplementationDetails>.ThrowNestedModuleLoadException(class [mscorlib]System.Exception innerException, class [mscorlib]System.Exception nestedException)
  IL_0026: leave.s  loc_F32
  IL_0028: stloc.2  
  IL_0029: ldarg.1  
  IL_002A: ldnull   
  IL_002B: call     void <CrtImplementationDetails>.ThrowNestedModuleLoadException(class [mscorlib]System.Exception innerException, class [mscorlib]System.Exception nestedException)
  IL_0030: leave.s  loc_F32
  IL_0032: ret      
}
// MethodDef 0x0600004E  <CrtImplementationDetails>.LanguageSupport.{ctor}  flavor=IL rva=0x3C98
.method /* <CrtImplementationDetails>.LanguageSupport.{ctor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.{ctor}'(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* pDtor)
  IL_0006: pop      
  IL_0007: ldarg.0  
  IL_0008: ret      
}
// MethodDef 0x0600004F  <CrtImplementationDetails>.LanguageSupport.{dtor}  flavor=IL rva=0x3CB0
.method /* <CrtImplementationDetails>.LanguageSupport.{dtor} */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void 'gcroot<System::String ^>.{dtor}'(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* pDtor)
  IL_0006: ret      
}
// MethodDef 0x06000050  <CrtImplementationDetails>.LanguageSupport.Initialize  flavor=IL rva=0x3CC4
.method /* <CrtImplementationDetails>.LanguageSupport.Initialize */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stloc.0  
  IL_0002: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_0007: ldarg.0  
  IL_0008: ldstr    aTheCModuleFail_5// "The C++ module failed to load.\n"
  IL_000D: call     modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) valuetype 'gcroot<System::String ^>'* 'gcroot<System::String ^>.='(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t, string pDtor)
  IL_0012: pop      
  IL_0013: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_0018: leave.s  loc_F88
  IL_001A: ldsflda  int32 ?Count@AllDomains@<CrtImplementationDetails>@@2HA
  IL_001F: call     int32 [mscorlib]System.Threading.Interlocked::Increment(int32&)
  IL_0024: pop      
  IL_0025: ldc.i4.1 
  IL_0026: stloc.0  
  IL_0027: endfinally 
  IL_0028: ldarg.0  
  IL_0029: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport._Initialize(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* cookie)
  IL_002E: leave.s  loc_FC2
  IL_0030: stloc.1  
  IL_0031: ldloc.0  
  IL_0032: brfalse.s loc_F9B
  IL_0034: ldarg.0  
  IL_0035: ldloc.1  
  IL_0036: call     void <CrtImplementationDetails>.LanguageSupport.Cleanup(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* innerException, class [mscorlib]System.Exception t)
  IL_003B: ldarg.0  
  IL_003C: call     string 'gcroot<System::String ^>..PE$AAVString@System@@'(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t)
  IL_0041: ldloc.1  
  IL_0042: call     void <CrtImplementationDetails>.ThrowModuleLoadException(string errorMessage, class [mscorlib]System.Exception innerException)
  IL_0047: leave.s  loc_FC2
  IL_0049: stloc.2  
  IL_004A: ldloc.0  
  IL_004B: brfalse.s loc_FB4
  IL_004D: ldarg.0  
  IL_004E: ldnull   
  IL_004F: call     void <CrtImplementationDetails>.LanguageSupport.Cleanup(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* innerException, class [mscorlib]System.Exception t)
  IL_0054: ldarg.0  
  IL_0055: call     string 'gcroot<System::String ^>..PE$AAVString@System@@'(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype 'gcroot<System::String ^>'* t)
  IL_005A: ldnull   
  IL_005B: call     void <CrtImplementationDetails>.ThrowModuleLoadException(string errorMessage, class [mscorlib]System.Exception innerException)
  IL_0060: leave.s  loc_FC2
  IL_0062: ret      
}
// MethodDef 0x06000051  .cctor  flavor=IL rva=0x3D80
.method /* .cctor */ cil managed { 
  IL_0000: ldloca.s 0
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) valuetype <CrtImplementationDetails>.LanguageSupport* <CrtImplementationDetails>.LanguageSupport.{ctor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* t)
  IL_0007: pop      
  IL_0008: ldloca.s 0
  IL_000A: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.Initialize(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* t)
  IL_000F: leave.s  loc_FEF
  IL_0011: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* t)
  IL_0017: ldloca.s 0
  IL_0019: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_001E: endfinally 
  IL_001F: ldloca.s 0
  IL_0021: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.LanguageSupport.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype <CrtImplementationDetails>.LanguageSupport* t)
  IL_0026: ret      
}
// MethodDef 0x06000052  gcroot<System::String ^>..PE$AAVString@System@@  flavor=IL rva=0x388C
.method /* gcroot<System::String ^>..PE$AAVString@System@@ */ cil managed { 
  IL_0000: ldloca.s 0
  IL_0002: ldarg.0  
  IL_0003: ldind.i8 
  IL_0004: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0009: ldloc.0  
  IL_000A: call     valuetype [mscorlib]System.Runtime.InteropServices.GCHandle [mscorlib]System.Runtime.InteropServices.GCHandle::op_Explicit(native int)
  IL_000F: stloc.1  
  IL_0010: ldloca.s 1
  IL_0012: call     instance object [mscorlib]System.Runtime.InteropServices.GCHandle::get_Target()
  IL_0017: ret      
}
// MethodDef 0x06000053  gcroot<System::String ^>.=  flavor=IL rva=0x38B0
.method /* gcroot<System::String ^>.= */ cil managed { 
  IL_0000: ldloca.s 0
  IL_0002: ldarg.0  
  IL_0003: ldind.i8 
  IL_0004: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0009: ldloc.0  
  IL_000A: call     valuetype [mscorlib]System.Runtime.InteropServices.GCHandle [mscorlib]System.Runtime.InteropServices.GCHandle::op_Explicit(native int)
  IL_000F: stloc.1  
  IL_0010: ldloca.s 1
  IL_0012: ldarg.1  
  IL_0013: call     instance void [mscorlib]System.Runtime.InteropServices.GCHandle::set_Target(object)
  IL_0018: ldarg.0  
  IL_0019: ret      
}
// MethodDef 0x06000054  gcroot<System::String ^>.{dtor}  flavor=IL rva=0x38D8
.method /* gcroot<System::String ^>.{dtor} */ cil managed { 
  IL_0000: ldloca.s 0
  IL_0002: ldarg.0  
  IL_0003: ldind.i8 
  IL_0004: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0009: ldloc.0  
  IL_000A: call     valuetype [mscorlib]System.Runtime.InteropServices.GCHandle [mscorlib]System.Runtime.InteropServices.GCHandle::op_Explicit(native int)
  IL_000F: stloc.1  
  IL_0010: ldloca.s 1
  IL_0012: call     instance void [mscorlib]System.Runtime.InteropServices.GCHandle::Free()
  IL_0017: ldarg.0  
  IL_0018: ldc.i4.0 
  IL_0019: conv.i8  
  IL_001A: stind.i8 
  IL_001B: ret      
}
// MethodDef 0x06000055  gcroot<System::String ^>.{ctor}  flavor=IL rva=0x3900
.method /* gcroot<System::String ^>.{ctor} */ cil managed { 
  IL_0000: ldnull   
  IL_0001: call     valuetype [mscorlib]System.Runtime.InteropServices.GCHandle [mscorlib]System.Runtime.InteropServices.GCHandle::Alloc(object)
  IL_0006: call     native int [mscorlib]System.Runtime.InteropServices.GCHandle::op_Explicit(valuetype [mscorlib]System.Runtime.InteropServices.GCHandle)
  IL_000B: stloc.0  
  IL_000C: ldarg.0  
  IL_000D: ldloca.s 0
  IL_000F: call     instance void* [mscorlib]System.IntPtr::ToPointer()
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
  IL_0004: calli    T0x11000075
  IL_0009: leave.s  loc_109B
  IL_000B: pop      
  IL_000C: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::GetExceptionPointers()
  IL_0011: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 __FrameUnwindFilter(valuetype _EXCEPTION_POINTERS* A_0)
  IL_0016: endfilter 
  IL_0018: pop      
  IL_0019: leave.s  loc_109B
  IL_001B: ret      
}
// MethodDef 0x06000057  ___CxxCallUnwindDelDtor  flavor=IL rva=0x3E4C
.method /* ___CxxCallUnwindDelDtor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: stloc.0  
  IL_0002: ldarg.1  
  IL_0003: ldloc.0  
  IL_0004: calli    T0x11000075
  IL_0009: leave.s  loc_109B
  IL_000B: pop      
  IL_000C: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::GetExceptionPointers()
  IL_0011: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 __FrameUnwindFilter(valuetype _EXCEPTION_POINTERS* A_0)
  IL_0016: endfilter 
  IL_0018: pop      
  IL_0019: leave.s  loc_109B
  IL_001B: ret      
}
// MethodDef 0x06000058  ___CxxCallUnwindVecDtor  flavor=IL rva=0x3E90
.method /* ___CxxCallUnwindVecDtor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: stloc.0  
  IL_0002: ldarg.1  
  IL_0003: ldarg.2  
  IL_0004: ldarg.3  
  IL_0005: ldarg.s  4
  IL_0007: ldloc.0  
  IL_0008: calli    T0x11000076
  IL_000D: leave.s  loc_10DF
  IL_000F: pop      
  IL_0010: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::GetExceptionPointers()
  IL_0015: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 __FrameUnwindFilter(valuetype _EXCEPTION_POINTERS* A_0)
  IL_001A: endfilter 
  IL_001C: pop      
  IL_001D: leave.s  loc_10DF
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
  IL_0007: starg.s  0
  IL_0009: ldarg.2  
  IL_000A: ldarg.2  
  IL_000B: ldc.i4.1 
  IL_000C: conv.i8  
  IL_000D: sub      
  IL_000E: starg.s  2
  IL_0010: ldc.i4.0 
  IL_0011: conv.i8  
  IL_0012: ble.un.s loc_1104
  IL_0014: ldarg.0  
  IL_0015: ldarg.1  
  IL_0016: sub      
  IL_0017: starg.s  0
  IL_0019: ldarg.3  
  IL_001A: stloc.1  
  IL_001B: ldarg.0  
  IL_001C: ldloc.1  
  IL_001D: calli    T0x11000075
  IL_0022: br.s     loc_10E9
  IL_0024: ldc.i4.1 
  IL_0025: stloc.0  
  IL_0026: leave.s  loc_1115
  IL_0028: ldloc.0  
  IL_0029: brtrue.s loc_1114
  IL_002B: ldarg.0  
  IL_002C: ldarg.1  
  IL_002D: ldarg.2  
  IL_002E: ldarg.3  
  IL_002F: call     void __ArrayUnwind(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
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
  IL_0005: ldc.i4   0xE06D7363
  IL_000A: beq.s    loc_112E
  IL_000C: ldc.i4.0 
  IL_000D: ret      
  IL_000E: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void** __current_exception()
  IL_0013: ldloc.0  
  IL_0014: stind.i8 
  IL_0015: ldarg.0  
  IL_0016: ldc.i4.8 
  IL_0017: conv.i8  
  IL_0018: add      
  IL_0019: ldind.i8 
  IL_001A: stloc.1  
  IL_001B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void** __current_exception_context()
  IL_0020: ldloc.1  
  IL_0021: stind.i8 
  IL_0022: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void terminate()
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
  IL_0005: beq.s    loc_116C
  IL_0007: ldarg.0  
  IL_0008: ldarg.1  
  IL_0009: sub      
  IL_000A: starg.s  0
  IL_000C: ldarg.3  
  IL_000D: stloc.1  
  IL_000E: ldarg.0  
  IL_000F: ldloc.1  
  IL_0010: calli    T0x11000075
  IL_0015: ldloc.0  
  IL_0016: ldc.i4.1 
  IL_0017: conv.i8  
  IL_0018: add      
  IL_0019: stloc.0  
  IL_001A: br.s     loc_1153
  IL_001C: leave.s  loc_117E
  IL_001E: pop      
  IL_001F: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::GetExceptionPointers()
  IL_0024: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) int32 ?A0x9c83a709.ArrayUnwindFilter(valuetype _EXCEPTION_POINTERS* pExPtrs)
  IL_0029: endfilter 
  IL_002B: pop      
  IL_002C: leave.s  loc_117E
  IL_002E: ret      
}
// MethodDef 0x0600005C  __ehvec_dtor  flavor=IL rva=0x3FDC
.method /* __ehvec_dtor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: conv.i8  
  IL_0004: ldarg.3  
  IL_0005: call     void __ehvec_dtor(void* ptr, unsigned int64 size, unsigned int64 count, void((void*)) destructor)
  IL_000A: ret      
}
// MethodDef 0x0600005D  <CrtImplementationDetails>.AtExitLock._handle  flavor=IL rva=0x4008
.method /* <CrtImplementationDetails>.AtExitLock._handle */ cil managed { 
  IL_0000: ldsfld   void* ?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PEAXEA
  IL_0005: brfalse.s loc_11AF
  IL_0007: ldloca.s 0
  IL_0009: ldsfld   void* ?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PEAXEA
  IL_000E: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0013: ldloc.0  
  IL_0014: call     valuetype [mscorlib]System.Runtime.InteropServices.GCHandle [mscorlib]System.Runtime.InteropServices.GCHandle::FromIntPtr(native int)
  IL_0019: box      [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_001E: ret      
  IL_001F: ldnull   
  IL_0020: ret      
}
// MethodDef 0x0600005E  <CrtImplementationDetails>.AtExitLock._lock_Construct  flavor=IL rva=0x4500
.method /* <CrtImplementationDetails>.AtExitLock._lock_Construct */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: conv.i8  
  IL_0002: stsfld   void* ?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PEAXEA
  IL_0007: ldarg.0  
  IL_0008: call     void <CrtImplementationDetails>.AtExitLock._lock_Set(object value)
  IL_000D: ret      
}
// MethodDef 0x0600005F  <CrtImplementationDetails>.AtExitLock._lock_Set  flavor=IL rva=0x4038
.method /* <CrtImplementationDetails>.AtExitLock._lock_Set */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.IsBoxed) modopt([mscorlib]System.Runtime.InteropServices.GCHandle) class [mscorlib]System.ValueType <CrtImplementationDetails>.AtExitLock._handle()
  IL_0005: stloc.0  
  IL_0006: ldloc.0  
  IL_0007: brtrue.s loc_1204
  IL_0009: ldarg.0  
  IL_000A: call     valuetype [mscorlib]System.Runtime.InteropServices.GCHandle [mscorlib]System.Runtime.InteropServices.GCHandle::Alloc(object)
  IL_000F: box      [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_0014: stloc.0  
  IL_0015: ldloc.0  
  IL_0016: unbox    [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_001B: ldobj    [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_0020: call     native int [mscorlib]System.Runtime.InteropServices.GCHandle::ToIntPtr(valuetype [mscorlib]System.Runtime.InteropServices.GCHandle)
  IL_0025: stloc.1  
  IL_0026: ldloca.s 1
  IL_0028: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_002D: stsfld   void* ?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PEAXEA
  IL_0032: br.s     loc_1210
  IL_0034: ldloc.0  
  IL_0035: unbox    [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_003A: ldarg.0  
  IL_003B: call     instance void [mscorlib]System.Runtime.InteropServices.GCHandle::set_Target(object)
  IL_0040: ret      
}
// MethodDef 0x06000060  <CrtImplementationDetails>.AtExitLock._lock_Get  flavor=IL rva=0x4088
.method /* <CrtImplementationDetails>.AtExitLock._lock_Get */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.IsBoxed) modopt([mscorlib]System.Runtime.InteropServices.GCHandle) class [mscorlib]System.ValueType <CrtImplementationDetails>.AtExitLock._handle()
  IL_0005: stloc.0  
  IL_0006: ldloc.0  
  IL_0007: brfalse.s loc_1235
  IL_0009: ldloc.0  
  IL_000A: unbox    [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_000F: call     instance object [mscorlib]System.Runtime.InteropServices.GCHandle::get_Target()
  IL_0014: ret      
  IL_0015: ldnull   
  IL_0016: ret      
}
// MethodDef 0x06000061  <CrtImplementationDetails>.AtExitLock._lock_Destruct  flavor=IL rva=0x40AC
.method /* <CrtImplementationDetails>.AtExitLock._lock_Destruct */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.IsBoxed) modopt([mscorlib]System.Runtime.InteropServices.GCHandle) class [mscorlib]System.ValueType <CrtImplementationDetails>.AtExitLock._handle()
  IL_0005: stloc.0  
  IL_0006: ldloc.0  
  IL_0007: brfalse.s loc_125B
  IL_0009: ldloc.0  
  IL_000A: unbox    [mscorlib]System.Runtime.InteropServices.GCHandle
  IL_000F: call     instance void [mscorlib]System.Runtime.InteropServices.GCHandle::Free()
  IL_0014: ldc.i4.0 
  IL_0015: conv.i8  
  IL_0016: stsfld   void* ?_lock@AtExitLock@<CrtImplementationDetails>@@$$Q0PEAXEA
  IL_001B: ret      
}
// MethodDef 0x06000062  <CrtImplementationDetails>.AtExitLock.IsInitialized  flavor=IL rva=0x40D4
.method /* <CrtImplementationDetails>.AtExitLock.IsInitialized */ cil managed { 
  IL_0000: call     object <CrtImplementationDetails>.AtExitLock._lock_Get()
  IL_0005: ldnull   
  IL_0006: bne.un.s loc_126B
  IL_0008: ldc.i4.0 
  IL_0009: br.s     loc_126C
  IL_000B: ldc.i4.1 
  IL_000C: conv.u1  
  IL_000D: ret      
}
// MethodDef 0x06000063  <CrtImplementationDetails>.AtExitLock.AddRef  flavor=IL rva=0x451C
.method /* <CrtImplementationDetails>.AtExitLock.AddRef */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.AtExitLock.IsInitialized()
  IL_0005: brtrue.s loc_1287
  IL_0007: newobj   instance void [mscorlib]System.Object::.ctor()
  IL_000C: call     void <CrtImplementationDetails>.AtExitLock._lock_Construct(object value)
  IL_0011: ldc.i4.0 
  IL_0012: stsfld   int32 ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA
  IL_0017: ldsfld   int32 ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA
  IL_001C: ldc.i4.1 
  IL_001D: add      
  IL_001E: stsfld   int32 ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA
  IL_0023: ret      
}
// MethodDef 0x06000064  <CrtImplementationDetails>.AtExitLock.RemoveRef  flavor=IL rva=0x40F0
.method /* <CrtImplementationDetails>.AtExitLock.RemoveRef */ cil managed { 
  IL_0000: ldsfld   int32 ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA
  IL_0005: ldc.i4.m1 
  IL_0006: add      
  IL_0007: stsfld   int32 ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA
  IL_000C: ldsfld   int32 ?_ref_count@AtExitLock@<CrtImplementationDetails>@@$$Q0HA
  IL_0011: brtrue.s loc_12B8
  IL_0013: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.AtExitLock._lock_Destruct()
  IL_0018: ret      
}
// MethodDef 0x06000065  <CrtImplementationDetails>.AtExitLock.Enter  flavor=IL rva=0x4118
.method /* <CrtImplementationDetails>.AtExitLock.Enter */ cil managed { 
  IL_0000: call     object <CrtImplementationDetails>.AtExitLock._lock_Get()
  IL_0005: call     void [mscorlib]System.Threading.Monitor::Enter(object)
  IL_000A: ret      
}
// MethodDef 0x06000066  <CrtImplementationDetails>.AtExitLock.Exit  flavor=IL rva=0x4130
.method /* <CrtImplementationDetails>.AtExitLock.Exit */ cil managed { 
  IL_0000: call     object <CrtImplementationDetails>.AtExitLock._lock_Get()
  IL_0005: call     void [mscorlib]System.Threading.Monitor::Exit(object)
  IL_000A: ret      
}
// MethodDef 0x06000067  ?A0xdf32f105.__global_lock  flavor=IL rva=0x4148
.method /* ?A0xdf32f105.__global_lock */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stloc.0  
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.AtExitLock.IsInitialized()
  IL_0007: brfalse.s loc_12F0
  IL_0009: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.AtExitLock.Enter()
  IL_000E: ldc.i4.1 
  IL_000F: stloc.0  
  IL_0010: ldloc.0  
  IL_0011: ret      
}
// MethodDef 0x06000068  ?A0xdf32f105.__global_unlock  flavor=IL rva=0x4168
.method /* ?A0xdf32f105.__global_unlock */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stloc.0  
  IL_0002: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.AtExitLock.IsInitialized()
  IL_0007: brfalse.s loc_1310
  IL_0009: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.AtExitLock.Exit()
  IL_000E: ldc.i4.1 
  IL_000F: stloc.0  
  IL_0010: ldloc.0  
  IL_0011: ret      
}
// MethodDef 0x06000069  ?A0xdf32f105.__alloc_global_lock  flavor=IL rva=0x454C
.method /* ?A0xdf32f105.__alloc_global_lock */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.AtExitLock.AddRef()
  IL_0005: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool <CrtImplementationDetails>.AtExitLock.IsInitialized()
  IL_000A: ret      
}
// MethodDef 0x0600006A  ?A0xdf32f105.__dealloc_global_lock  flavor=IL rva=0x4188
.method /* ?A0xdf32f105.__dealloc_global_lock */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void <CrtImplementationDetails>.AtExitLock.RemoveRef()
  IL_0005: ret      
}
// MethodDef 0x0600006B  _atexit_helper  flavor=IL rva=0x419C
.method /* _atexit_helper */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: conv.i8  
  IL_0002: stloc.s  6
  IL_0004: ldarg.0  
  IL_0005: brtrue.s loc_1349
  IL_0007: ldc.i4.m1 
  IL_0008: ret      
  IL_0009: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool ?A0xdf32f105.__global_lock()
  IL_000E: ldc.i4.1 
  IL_000F: bne.un   loc_1453
  IL_0014: ldarg.3  
  IL_0015: ldind.i8 
  IL_0016: call     void* DecodePointer(void* _Ptr)
  IL_001B: stloc.1  
  IL_001C: ldarg.2  
  IL_001D: ldind.i8 
  IL_001E: call     void* DecodePointer(void* _Ptr)
  IL_0023: stloc.0  
  IL_0024: ldloc.0  
  IL_0025: ldloc.1  
  IL_0026: sub      
  IL_0027: stloc.s  5
  IL_0029: ldarg.1  
  IL_002A: ldind.i8 
  IL_002B: ldc.i4.1 
  IL_002C: conv.i8  
  IL_002D: sub      
  IL_002E: ldloc.s  5
  IL_0030: ldc.i4.3 
  IL_0031: shr.un   
  IL_0032: bge.un   loc_1424
  IL_0037: ldarg.1  
  IL_0038: ldind.i8 
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: mul      
  IL_003C: stloc.3  
  IL_003D: ldloc.3  
  IL_003E: ldc.i4   0x1000
  IL_0043: conv.i8  
  IL_0044: blt.un.s loc_138E
  IL_0046: ldc.i4   0x1000
  IL_004B: conv.i8  
  IL_004C: br.s     loc_138F
  IL_004E: ldloc.3  
  IL_004F: stloc.s  0xC
  IL_0051: ldloca.s 0xB
  IL_0053: ldloc.3  
  IL_0054: ldloc.s  0xC
  IL_0056: add      
  IL_0057: conv.i4  
  IL_0058: call     instance void [mscorlib]System.IntPtr::.ctor(int32)
  IL_005D: ldloca.s 0xA
  IL_005F: ldloc.1  
  IL_0060: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0065: ldloc.s  0xA
  IL_0067: ldloc.s  0xB
  IL_0069: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::ReAllocHGlobal(native int, native int)
  IL_006E: stloc.s  0xE
  IL_0070: ldloca.s 0xE
  IL_0072: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_0077: ldloc.s  5
  IL_0079: add      
  IL_007A: stloc.0  
  IL_007B: ldloca.s 0xE
  IL_007D: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_0082: stloc.1  
  IL_0083: ldarg.1  
  IL_0084: ldind.i8 
  IL_0085: stloc.2  
  IL_0086: ldc.i4   0x200
  IL_008B: conv.i8  
  IL_008C: ldloc.2  
  IL_008D: blt.un.s loc_13D2
  IL_008F: ldloc.2  
  IL_0090: br.s     loc_13D8
  IL_0092: ldc.i4   0x200
  IL_0097: conv.i8  
  IL_0098: stloc.s  9
  IL_009A: ldarg.1  
  IL_009B: ldloc.2  
  IL_009C: ldloc.s  9
  IL_009E: add      
  IL_009F: stind.i8 
  IL_00A0: leave.s  loc_1424
  IL_00A2: pop      
  IL_00A3: ldloca.s 8
  IL_00A5: ldarg.1  
  IL_00A6: ldind.i8 
  IL_00A7: ldc.i4.8 
  IL_00A8: conv.i8  
  IL_00A9: mul      
  IL_00AA: ldc.i4.s 0xC
  IL_00AC: conv.i8  
  IL_00AD: add      
  IL_00AE: conv.i4  
  IL_00AF: call     instance void [mscorlib]System.IntPtr::.ctor(int32)
  IL_00B4: ldloca.s 7
  IL_00B6: ldloc.1  
  IL_00B7: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_00BC: ldloc.s  7
  IL_00BE: ldloc.s  8
  IL_00C0: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::ReAllocHGlobal(native int, native int)
  IL_00C5: stloc.s  0xD
  IL_00C7: ldloca.s 0xD
  IL_00C9: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_00CE: ldloc.1  
  IL_00CF: sub      
  IL_00D0: ldloc.0  
  IL_00D1: add      
  IL_00D2: stloc.0  
  IL_00D3: ldloca.s 0xD
  IL_00D5: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_00DA: stloc.1  
  IL_00DB: ldarg.1  
  IL_00DC: dup      
  IL_00DD: ldind.i8 
  IL_00DE: ldc.i4.4 
  IL_00DF: conv.i8  
  IL_00E0: add      
  IL_00E1: stind.i8 
  IL_00E2: leave.s  loc_1424
  IL_00E4: ldloc.0  
  IL_00E5: ldarg.0  
  IL_00E6: stind.i8 
  IL_00E7: ldloc.0  
  IL_00E8: ldc.i4.8 
  IL_00E9: conv.i8  
  IL_00EA: add      
  IL_00EB: stloc.0  
  IL_00EC: ldarg.0  
  IL_00ED: stloc.s  6
  IL_00EF: ldarg.3  
  IL_00F0: ldloc.1  
  IL_00F1: call     void* EncodePointer(void* _Ptr)
  IL_00F6: stind.i8 
  IL_00F7: ldarg.2  
  IL_00F8: ldloc.0  
  IL_00F9: call     void* EncodePointer(void* _Ptr)
  IL_00FE: stind.i8 
  IL_00FF: leave.s  loc_1446
  IL_0101: pop      
  IL_0102: leave.s  loc_1444
  IL_0104: leave.s  loc_144F
  IL_0106: leave.s  loc_144F
  IL_0108: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool ?A0xdf32f105.__global_unlock()
  IL_010D: pop      
  IL_010E: endfinally 
  IL_010F: ldloc.s  6
  IL_0111: brtrue.s loc_1458
  IL_0113: ldc.i4.m1 
  IL_0114: stloc.s  4
  IL_0116: br.s     loc_145B
  IL_0118: ldc.i4.0 
  IL_0119: stloc.s  4
  IL_011B: ldloc.s  4
  IL_011D: ret      
}
// MethodDef 0x0600006C  _exit_callback  flavor=IL rva=0x4314
.method /* _exit_callback */ cil managed { 
  IL_0000: ldsfld   unsigned int64 ?A0xdf32f105.__exit_list_size
  IL_0005: brfalse  loc_1501
  IL_000A: ldsfld   void(())* ?A0xdf32f105.__onexitbegin_m
  IL_000F: call     void* DecodePointer(void* _Ptr)
  IL_0014: stloc.1  
  IL_0015: ldsfld   void(())* ?A0xdf32f105.__onexitend_m
  IL_001A: call     void* DecodePointer(void* _Ptr)
  IL_001F: stloc.0  
  IL_0020: ldloc.1  
  IL_0021: ldc.i8   0xFFFFFFFFFFFFFFFF
  IL_002A: beq.s    loc_14FC
  IL_002C: ldloc.1  
  IL_002D: brfalse.s loc_14FC
  IL_002F: ldloc.0  
  IL_0030: brfalse.s loc_14FC
  IL_0032: ldloc.1  
  IL_0033: stloc.s  5
  IL_0035: ldloc.0  
  IL_0036: stloc.s  4
  IL_0038: ldloc.0  
  IL_0039: ldc.i4.8 
  IL_003A: conv.i8  
  IL_003B: sub      
  IL_003C: stloc.0  
  IL_003D: ldloc.0  
  IL_003E: ldloc.1  
  IL_003F: blt.un.s loc_14ED
  IL_0041: ldloc.0  
  IL_0042: ldind.i8 
  IL_0043: ldc.i4.0 
  IL_0044: conv.i8  
  IL_0045: call     void* EncodePointer(void* _Ptr)
  IL_004A: beq.s    loc_1498
  IL_004C: ldloc.0  
  IL_004D: ldind.i8 
  IL_004E: call     void* DecodePointer(void* _Ptr)
  IL_0053: ldloc.0  
  IL_0054: ldc.i4.0 
  IL_0055: conv.i8  
  IL_0056: call     void* EncodePointer(void* _Ptr)
  IL_005B: stind.i8 
  IL_005C: calli    T0x11000082
  IL_0061: ldsfld   void(())* ?A0xdf32f105.__onexitbegin_m
  IL_0066: call     void* DecodePointer(void* _Ptr)
  IL_006B: stloc.3  
  IL_006C: ldsfld   void(())* ?A0xdf32f105.__onexitend_m
  IL_0071: call     void* DecodePointer(void* _Ptr)
  IL_0076: stloc.2  
  IL_0077: ldloc.s  5
  IL_0079: ldloc.3  
  IL_007A: bne.un.s loc_14E1
  IL_007C: ldloc.s  4
  IL_007E: ldloc.2  
  IL_007F: beq.s    loc_1498
  IL_0081: ldloc.3  
  IL_0082: stloc.s  5
  IL_0084: ldloc.3  
  IL_0085: stloc.1  
  IL_0086: ldloc.2  
  IL_0087: stloc.s  4
  IL_0089: ldloc.2  
  IL_008A: stloc.0  
  IL_008B: br.s     loc_1498
  IL_008D: ldloca.s 6
  IL_008F: ldloc.1  
  IL_0090: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_0095: ldloc.s  6
  IL_0097: call     void [mscorlib]System.Runtime.InteropServices.Marshal::FreeHGlobal(native int)
  IL_009C: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void ?A0xdf32f105.__dealloc_global_lock()
  IL_00A1: ret      
}
// MethodDef 0x0600006D  _initatexit_m  flavor=IL rva=0x4564
.method /* _initatexit_m */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool ?A0xdf32f105.__alloc_global_lock()
  IL_0006: ldc.i4.1 
  IL_0007: bne.un.s loc_1549
  IL_0009: pop      
  IL_000A: ldc.i4   0x100
  IL_000F: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::AllocHGlobal(int32)
  IL_0014: stloc.0  
  IL_0015: ldloca.s 0
  IL_0017: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_001C: call     void* EncodePointer(void* _Ptr)
  IL_0021: stsfld   void(())* ?A0xdf32f105.__onexitbegin_m
  IL_0026: ldsfld   void(())* ?A0xdf32f105.__onexitbegin_m
  IL_002B: stsfld   void(())* ?A0xdf32f105.__onexitend_m
  IL_0030: ldc.i4.s 0x20
  IL_0032: conv.i8  
  IL_0033: stsfld   unsigned int64 ?A0xdf32f105.__exit_list_size
  IL_0038: ldc.i4.1 
  IL_0039: ret      
}
// MethodDef 0x0600006E  _onexit_m  flavor=IL rva=0x45AC
.method /* _onexit_m */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     int32 _atexit_m(void(()) func)
  IL_0006: ldc.i4.m1 
  IL_0007: beq.s    loc_155C
  IL_0009: ldarg.0  
  IL_000A: br.s     loc_155E
  IL_000C: ldc.i4.0 
  IL_000D: conv.i8  
  IL_000E: ret      
}
// MethodDef 0x0600006F  _atexit_m  flavor=IL rva=0x43C4
.method /* _atexit_m */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     void* EncodePointer(void* _Ptr)
  IL_0006: ldsflda  unsigned int64 ?A0xdf32f105.__exit_list_size
  IL_000B: ldsflda  void(())* ?A0xdf32f105.__onexitend_m
  IL_0010: ldsflda  void(())* ?A0xdf32f105.__onexitbegin_m
  IL_0015: call     int32 _atexit_helper(void(()) func, unsigned int64* __pexit_list_size, void(())** __ponexitend_e, void(())** __ponexitbegin_e)
  IL_001A: ret      
}
// MethodDef 0x06000070  _initatexit_app_domain  flavor=IL rva=0x45C8
.method /* _initatexit_app_domain */ cil managed { 
  IL_0000: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) bool ?A0xdf32f105.__alloc_global_lock()
  IL_0005: ldc.i4.1 
  IL_0006: bne.un.s loc_15B6
  IL_0008: ldc.i4   0x100
  IL_000D: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::AllocHGlobal(int32)
  IL_0012: stloc.0  
  IL_0013: ldloca.s 0
  IL_0015: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_001A: call     void* EncodePointer(void* _Ptr)
  IL_001F: stsfld   void(())* __onexitbegin_app_domain
  IL_0024: ldsfld   void(())* __onexitbegin_app_domain
  IL_0029: stsfld   void(())* __onexitend_app_domain
  IL_002E: ldc.i4.s 0x20
  IL_0030: conv.i8  
  IL_0031: stsfld   unsigned int64 __exit_list_size_app_domain
  IL_0036: ldc.i4.1 
  IL_0037: ret      
}
// MethodDef 0x06000071  _app_exit_callback  flavor=IL rva=0x43EC
.method /* _app_exit_callback */ cil managed { 
  IL_0000: ldsfld   unsigned int64 __exit_list_size_app_domain
  IL_0005: brfalse  loc_1680
  IL_000A: ldsfld   void(())* __onexitbegin_app_domain
  IL_000F: call     void* DecodePointer(void* _Ptr)
  IL_0014: stloc.1  
  IL_0015: ldsfld   void(())* __onexitend_app_domain
  IL_001A: call     void* DecodePointer(void* _Ptr)
  IL_001F: stloc.0  
  IL_0020: ldloc.1  
  IL_0021: ldc.i8   0xFFFFFFFFFFFFFFFF
  IL_002A: beq      loc_1669
  IL_002F: ldloc.1  
  IL_0030: brfalse  loc_1669
  IL_0035: ldloc.0  
  IL_0036: brfalse.s loc_1669
  IL_0038: ldc.i4.0 
  IL_0039: conv.i8  
  IL_003A: stloc.s  6
  IL_003C: ldloc.1  
  IL_003D: stloc.s  5
  IL_003F: ldloc.0  
  IL_0040: stloc.s  4
  IL_0042: ldc.i4.0 
  IL_0043: conv.i8  
  IL_0044: stloc.s  9
  IL_0046: ldc.i4.0 
  IL_0047: conv.i8  
  IL_0048: stloc.s  8
  IL_004A: ldloc.0  
  IL_004B: ldc.i4.8 
  IL_004C: conv.i8  
  IL_004D: sub      
  IL_004E: stloc.0  
  IL_004F: ldloc.0  
  IL_0050: ldloc.1  
  IL_0051: blt.un.s loc_1620
  IL_0053: ldloc.0  
  IL_0054: ldind.i8 
  IL_0055: ldc.i4.0 
  IL_0056: conv.i8  
  IL_0057: call     void* EncodePointer(void* _Ptr)
  IL_005C: bne.un.s loc_1620
  IL_005E: br.s     loc_160A
  IL_0060: ldloc.0  
  IL_0061: ldloc.1  
  IL_0062: blt.un.s loc_1669
  IL_0064: ldloc.0  
  IL_0065: ldind.i8 
  IL_0066: call     void* DecodePointer(void* _Ptr)
  IL_006B: stloc.s  6
  IL_006D: ldloc.0  
  IL_006E: ldc.i4.0 
  IL_006F: conv.i8  
  IL_0070: call     void* EncodePointer(void* _Ptr)
  IL_0075: stind.i8 
  IL_0076: ldloc.s  6
  IL_0078: calli    T0x11000082
  IL_007D: ldsfld   void(())* __onexitbegin_app_domain
  IL_0082: call     void* DecodePointer(void* _Ptr)
  IL_0087: stloc.3  
  IL_0088: ldsfld   void(())* __onexitend_app_domain
  IL_008D: call     void* DecodePointer(void* _Ptr)
  IL_0092: stloc.2  
  IL_0093: ldloc.s  5
  IL_0095: ldloc.3  
  IL_0096: bne.un.s loc_165D
  IL_0098: ldloc.s  4
  IL_009A: ldloc.2  
  IL_009B: beq.s    loc_1667
  IL_009D: ldloc.3  
  IL_009E: stloc.s  5
  IL_00A0: ldloc.3  
  IL_00A1: stloc.1  
  IL_00A2: ldloc.2  
  IL_00A3: stloc.s  4
  IL_00A5: ldloc.2  
  IL_00A6: stloc.0  
  IL_00A7: br.s     loc_1602
  IL_00A9: leave.s  loc_1680
  IL_00AB: ldloca.s 7
  IL_00AD: ldloc.1  
  IL_00AE: call     instance void [mscorlib]System.IntPtr::.ctor(void*)
  IL_00B3: ldloc.s  7
  IL_00B5: call     void [mscorlib]System.Runtime.InteropServices.Marshal::FreeHGlobal(native int)
  IL_00BA: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void ?A0xdf32f105.__dealloc_global_lock()
  IL_00BF: endfinally 
  IL_00C0: ret      
}
// MethodDef 0x06000072  _onexit_m_appdomain  flavor=IL rva=0x460C
.method /* _onexit_m_appdomain */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     int32 _atexit_m_appdomain(void(()) func)
  IL_0006: ldc.i4.m1 
  IL_0007: beq.s    loc_169C
  IL_0009: ldarg.0  
  IL_000A: br.s     loc_169E
  IL_000C: ldc.i4.0 
  IL_000D: conv.i8  
  IL_000E: ret      
}
// MethodDef 0x06000073  _atexit_m_appdomain  flavor=IL rva=0x44D8
.method /* _atexit_m_appdomain */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     void* EncodePointer(void* _Ptr)
  IL_0006: ldsflda  unsigned int64 __exit_list_size_app_domain
  IL_000B: ldsflda  void(())* __onexitend_app_domain
  IL_0010: ldsflda  void(())* __onexitbegin_app_domain
  IL_0015: call     int32 _atexit_helper(void(()) func, unsigned int64* __pexit_list_size, void(())** __ponexitend_e, void(())** __ponexitbegin_e)
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
  IL_0004: bge.un.s loc_1700
  IL_0006: ldloc.0  
  IL_0007: brtrue.s loc_1700
  IL_0009: ldarg.0  
  IL_000A: ldind.i8 
  IL_000B: stloc.1  
  IL_000C: ldloc.1  
  IL_000D: brfalse.s loc_16F6
  IL_000F: ldloc.1  
  IL_0010: calli    T0x11000092
  IL_0015: stloc.0  
  IL_0016: ldarg.0  
  IL_0017: ldc.i4.8 
  IL_0018: conv.i8  
  IL_0019: add      
  IL_001A: starg.s  0
  IL_001C: ldarg.0  
  IL_001D: ldarg.1  
  IL_001E: blt.un.s loc_16E6
  IL_0020: ldloc.0  
  IL_0021: ret      
}
// MethodDef 0x06000077  _initterm  flavor=IL rva=0x466C
.method /* _initterm */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: bge.un.s loc_172A
  IL_0004: ldarg.0  
  IL_0005: ldind.i8 
  IL_0006: stloc.0  
  IL_0007: ldloc.0  
  IL_0008: brfalse.s loc_1720
  IL_000A: ldloc.0  
  IL_000B: calli    T0x11000090
  IL_0010: ldarg.0  
  IL_0011: ldc.i4.8 
  IL_0012: conv.i8  
  IL_0013: add      
  IL_0014: starg.s  0
  IL_0016: ldarg.0  
  IL_0017: ldarg.1  
  IL_0018: blt.un.s loc_1714
  IL_001A: ret      
}
// MethodDef 0x06000078  <CrtImplementationDetails>.ThisModule.Handle  flavor=IL rva=0x4694
.method /* <CrtImplementationDetails>.ThisModule.Handle */ cil managed { 
  IL_0000: ldtoken  <CrtImplementationDetails>.ThisModule
  IL_0005: call     class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle)
  IL_000A: callvirt instance class [mscorlib]System.Reflection.Module [mscorlib]System.Type::get_Module()
  IL_000F: call     instance valuetype [mscorlib]System.ModuleHandle [mscorlib]System.Reflection.Module::get_ModuleHandle()
  IL_0014: ret      
}
// MethodDef 0x06000079  _initterm_m  flavor=IL rva=0x46E4
.method /* _initterm_m */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: bge.un.s loc_1770
  IL_0004: ldarg.0  
  IL_0005: ldind.i8 
  IL_0006: stloc.0  
  IL_0007: ldloc.0  
  IL_0008: brfalse.s loc_1766
  IL_000A: ldloc.0  
  IL_000B: call     modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(()) '<CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>'(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void*(()))
  IL_0010: calli    T0x11000091
  IL_0015: pop      
  IL_0016: ldarg.0  
  IL_0017: ldc.i4.8 
  IL_0018: conv.i8  
  IL_0019: add      
  IL_001A: starg.s  0
  IL_001C: ldarg.0  
  IL_001D: ldarg.1  
  IL_001E: blt.un.s loc_1754
  IL_0020: ret      
}
// MethodDef 0x0600007A  <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>  flavor=IL rva=0x46B8
.method /* <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)> */ cil managed { 
  IL_0000: call     valuetype [mscorlib]System.ModuleHandle <CrtImplementationDetails>.ThisModule.Handle()
  IL_0005: stloc.2  
  IL_0006: ldloca.s 2
  IL_0008: ldarg.0  
  IL_0009: conv.i4  
  IL_000A: call     instance valuetype [mscorlib]System.RuntimeMethodHandle [mscorlib]System.ModuleHandle::ResolveMethodHandle(int32)
  IL_000F: stloc.1  
  IL_0010: ldloca.s 1
  IL_0012: call     instance native int [mscorlib]System.RuntimeMethodHandle::GetFunctionPointer()
  IL_0017: stloc.0  
  IL_0018: ldloca.s 0
  IL_001A: call     instance void* [mscorlib]System.IntPtr::ToPointer()
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
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
// MethodDef 0x0600008F  .ctor  flavor=IL rva=0x1504
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Object::.ctor()
  IL_0006: ret      
}
// MethodDef 0x06000090  .cctor  flavor=IL rva=0x1518
.method /* .cctor */ cil managed { 
  IL_0000: ldc.i4.1 
  IL_0001: stsfld   modopt([mscorlib]System.Runtime.CompilerServices.IsConst) bool msclr.interop.context_node_base::_Needs_Context
  IL_0006: ret      
}
// MethodDef 0x06000091  .ctor  flavor=IL rva=0x17EC
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void msclr.interop.context_node_base::.ctor()
  IL_0006: ldarg.0  
  IL_0007: ldc.i4.0 
  IL_0008: conv.i8  
  IL_0009: stfld    modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* 'msclr.interop.context_node<char const *,System::String ^>'::_ptr
  IL_000E: ldarg.2  
  IL_000F: ldnull   
  IL_0010: call     bool [mscorlib]System.String::op_Equality(string, string)
  IL_0015: brfalse.s loc_1823
  IL_0017: ldarg.1  
  IL_0018: ldc.i4.0 
  IL_0019: conv.i8  
  IL_001A: stind.i8 
  IL_001B: ldarg.0  
  IL_001C: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0021: br.s     loc_186C
  IL_0023: ldarg.2  
  IL_0024: call     unsigned int64 msclr.interop.details.GetAnsiStringSize(string _str)
  IL_0029: stloc.1  
  IL_002A: ldloc.1  
  IL_002B: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void* new[](unsigned int64 A_0)
  IL_0030: stloc.0  
  IL_0031: ldloca.s 2
  IL_0033: ldloc.0  
  IL_0034: stind.i8 
  IL_0035: ldloc.0  
  IL_0036: brtrue.s loc_183E
  IL_0038: newobj   instance void [mscorlib]System.InsufficientMemoryException::.ctor()
  IL_003D: throw    
  IL_003E: ldloc.0  
  IL_003F: ldloc.1  
  IL_0040: ldarg.2  
  IL_0041: call     void msclr.interop.details.WriteAnsiString(modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* _buf, unsigned int64 _size, string _str)
  IL_0046: ldloca.s 2
  IL_0048: ldc.i4.0 
  IL_0049: conv.i8  
  IL_004A: stind.i8 
  IL_004B: ldarg.0  
  IL_004C: ldloc.0  
  IL_004D: stfld    modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* 'msclr.interop.context_node<char const *,System::String ^>'::_ptr
  IL_0052: ldarg.1  
  IL_0053: ldloc.0  
  IL_0054: stind.i8 
  IL_0055: leave.s  loc_1865
  IL_0057: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void msclr.interop.details.char_buffer<char>.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype msclr.interop.details.char_buffer<char>* _size)
  IL_005D: ldloca.s 2
  IL_005F: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_0064: endfinally 
  IL_0065: ldc.i4.0 
  IL_0066: conv.i8  
  IL_0067: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_006C: nop      
  IL_006D: leave.s  loc_187D
  IL_006F: ldftn    modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void msclr.interop.details.char_buffer<char>.{dtor}(modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) valuetype msclr.interop.details.char_buffer<char>* _size)
  IL_0075: ldloca.s 2
  IL_0077: call     void ___CxxCallUnwindDtor(void((void*)) pDtor, void* pThis)
  IL_007C: endfinally 
  IL_007D: ret      
}
// MethodDef 0x06000092  ~context_node<char const *,System::String ^>  flavor=IL rva=0x18AC
.method /* ~context_node<char const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldfld    modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* 'msclr.interop.context_node<char const *,System::String ^>'::_ptr
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_000B: ldarg.0  
  IL_000C: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0011: ret      
}
// MethodDef 0x06000093  !context_node<char const *,System::String ^>  flavor=IL rva=0x152C
.method /* !context_node<char const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldfld    modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* 'msclr.interop.context_node<char const *,System::String ^>'::_ptr
  IL_0006: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_000B: ldarg.0  
  IL_000C: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0011: ret      
}
// MethodDef 0x06000094  Dispose  flavor=IL rva=0x18CC
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: brfalse.s loc_18D6
  IL_0003: ldarg.0  
  IL_0004: ldfld    modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8* 'msclr.interop.context_node<char const *,System::String ^>'::_ptr
  IL_0009: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void delete[](void* A_0)
  IL_000E: ldarg.0  
  IL_000F: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0014: br.s     loc_18E6
  IL_0016: nop      
  IL_0017: ldarg.0  
  IL_0018: call     instance void 'msclr.interop.context_node<char const *,System::String ^>'::'!context_node<char const *,System::String ^>'()
  IL_001D: leave.s  loc_18E6
  IL_001F: ldarg.0  
  IL_0020: call     instance void [mscorlib]System.Object::Finalize()
  IL_0025: endfinally 
  IL_0026: ret      
}
// MethodDef 0x06000095  Dispose  flavor=IL rva=0x19E8
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldc.i4.1 
  IL_0002: callvirt instance void 'msclr.interop.context_node<char const *,System::String ^>'::Dispose([hasfieldmarshal] bool A_0)
  IL_0007: ldarg.0  
  IL_0008: call     void [mscorlib]System.GC::SuppressFinalize(object)
  IL_000D: ldarg.0  
  IL_000E: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0013: ret      
}
// MethodDef 0x06000096  Finalize  flavor=IL rva=0x191C
.method /* Finalize */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldc.i4.0 
  IL_0002: callvirt instance void 'msclr.interop.context_node<char const *,System::String ^>'::Dispose([hasfieldmarshal] bool A_0)
  IL_0007: ret      
}
// MethodDef 0x06000097  .ctor  flavor=IL rva=0x154C
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void msclr.interop.context_node_base::.ctor()
  IL_0006: ldarg.2  
  IL_0007: call     native int [mscorlib]System.Runtime.InteropServices.Marshal::StringToHGlobalUni(string)
  IL_000C: stloc.0  
  IL_000D: ldarg.0  
  IL_000E: ldloc.0  
  IL_000F: stfld    native int 'msclr.interop.context_node<wchar_t const *,System::String ^>'::_ip
  IL_0014: ldarg.1  
  IL_0015: ldarg.0  
  IL_0016: ldflda   native int 'msclr.interop.context_node<wchar_t const *,System::String ^>'::_ip
  IL_001B: call     instance void* [mscorlib]System.IntPtr::ToPointer()
  IL_0020: stind.i8 
  IL_0021: ldarg.0  
  IL_0022: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0027: ret      
}
// MethodDef 0x06000098  ~context_node<wchar_t const *,System::String ^>  flavor=IL rva=0x1930
.method /* ~context_node<wchar_t const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void 'msclr.interop.context_node<wchar_t const *,System::String ^>'::'!context_node<wchar_t const *,System::String ^>'()
  IL_0006: ret      
}
// MethodDef 0x06000099  !context_node<wchar_t const *,System::String ^>  flavor=IL rva=0x1580
.method /* !context_node<wchar_t const *,System::String ^> */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldflda   native int 'msclr.interop.context_node<wchar_t const *,System::String ^>'::_ip
  IL_0006: ldobj    [mscorlib]System.IntPtr
  IL_000B: ldsfld   native int [mscorlib]System.IntPtr::Zero
  IL_0010: call     bool [mscorlib]System.IntPtr::op_Inequality(native int, native int)
  IL_0015: brfalse.s loc_1997
  IL_0017: ldarg.0  
  IL_0018: ldflda   native int 'msclr.interop.context_node<wchar_t const *,System::String ^>'::_ip
  IL_001D: ldobj    [mscorlib]System.IntPtr
  IL_0022: call     void [mscorlib]System.Runtime.InteropServices.Marshal::FreeHGlobal(native int)
  IL_0027: ldarg.0  
  IL_0028: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_002D: ret      
}
// MethodDef 0x0600009A  Dispose  flavor=IL rva=0x1944
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: brfalse.s loc_19AB
  IL_0003: ldarg.0  
  IL_0004: call     instance void 'msclr.interop.context_node<wchar_t const *,System::String ^>'::'!context_node<wchar_t const *,System::String ^>'()
  IL_0009: br.s     loc_19BB
  IL_000B: nop      
  IL_000C: ldarg.0  
  IL_000D: call     instance void 'msclr.interop.context_node<wchar_t const *,System::String ^>'::'!context_node<wchar_t const *,System::String ^>'()
  IL_0012: leave.s  loc_19BB
  IL_0014: ldarg.0  
  IL_0015: call     instance void [mscorlib]System.Object::Finalize()
  IL_001A: endfinally 
  IL_001B: ret      
}
// MethodDef 0x0600009B  Dispose  flavor=IL rva=0x1A08
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldc.i4.1 
  IL_0002: callvirt instance void 'msclr.interop.context_node<wchar_t const *,System::String ^>'::Dispose([hasfieldmarshal] bool A_0)
  IL_0007: ldarg.0  
  IL_0008: call     void [mscorlib]System.GC::SuppressFinalize(object)
  IL_000D: ldarg.0  
  IL_000E: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0013: ret      
}
// MethodDef 0x0600009C  Finalize  flavor=IL rva=0x1988
.method /* Finalize */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldc.i4.0 
  IL_0002: callvirt instance void 'msclr.interop.context_node<wchar_t const *,System::String ^>'::Dispose([hasfieldmarshal] bool A_0)
  IL_0007: ret      
}
// MethodDef 0x0600009D  .ctor  flavor=IL rva=0x15BC
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: newobj   instance void class [System]System.Collections.Generic.LinkedList`1<object>::.ctor()
  IL_0006: stfld    modreq([mscorlib]System.Runtime.CompilerServices.IsByValue) class [System]System.Collections.Generic.LinkedList`1<object> msclr.interop.marshal_context::_clean_up_list
  IL_000B: ldarg.0  
  IL_000C: call     instance void [mscorlib]System.Object::.ctor()
  IL_0011: ret      
}
// MethodDef 0x0600009E  ~marshal_context  flavor=IL rva=0x15DC
.method /* ~marshal_context */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldfld    modreq([mscorlib]System.Runtime.CompilerServices.IsByValue) class [System]System.Collections.Generic.LinkedList`1<object> msclr.interop.marshal_context::_clean_up_list
  IL_0006: call     instance valuetype [System]System.Collections.Generic.LinkedList`1/Enumerator<var<u1>> class [System]System.Collections.Generic.LinkedList`1<object>::GetEnumerator()
  IL_000B: stloc.1  
  IL_000C: ldloca.s 1
  IL_000E: call     instance bool valuetype [System]System.Collections.Generic.LinkedList`1/Enumerator<object>::MoveNext()
  IL_0013: brfalse.s loc_1A54
  IL_0015: ldloca.s 1
  IL_0017: call     instance var<u1> valuetype [System]System.Collections.Generic.LinkedList`1/Enumerator<object>::get_Current()
  IL_001C: isinst   [mscorlib]System.IDisposable
  IL_0021: stloc.0  
  IL_0022: ldloc.0  
  IL_0023: brfalse.s loc_1A4B
  IL_0025: ldloc.0  
  IL_0026: callvirt instance void [mscorlib]System.IDisposable::Dispose()
  IL_002B: ldloca.s 1
  IL_002D: call     instance bool valuetype [System]System.Collections.Generic.LinkedList`1/Enumerator<object>::MoveNext()
  IL_0032: brtrue.s loc_1A35
  IL_0034: ldarg.0  
  IL_0035: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_003A: ret      
}
// MethodDef 0x0600009F  Dispose  flavor=IL rva=0x1624
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.1  
  IL_0001: brfalse.s loc_1A6B
  IL_0003: ldarg.0  
  IL_0004: call     instance void msclr.interop.marshal_context::~marshal_context()
  IL_0009: br.s     loc_1A71
  IL_000B: ldarg.0  
  IL_000C: call     instance void [mscorlib]System.Object::Finalize()
  IL_0011: ret      
}
// MethodDef 0x060000A0  Dispose  flavor=IL rva=0x199C
.method /* Dispose */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldc.i4.1 
  IL_0002: callvirt instance void msclr.interop.marshal_context::Dispose([hasfieldmarshal] bool A_0)
  IL_0007: ldarg.0  
  IL_0008: call     void [mscorlib]System.GC::SuppressFinalize(object)
  IL_000D: ldarg.0  
  IL_000E: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0013: ret      
}
// MethodDef 0x060000A1  WrapperSaveMergennFiles  flavor=IL rva=0x1A5C
.method /* WrapperSaveMergennFiles */ cil managed { 
  IL_0000: ldarga.s 2
  IL_0002: call     string 'msclr.interop.marshal_as<class System::String ^,char *>'(modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8** _from_object)
  IL_0007: stloc.0  
  IL_0008: ldarga.s 1
  IL_000A: call     string 'msclr.interop.marshal_as<class System::String ^,char *>'(modopt([mscorlib]System.Runtime.CompilerServices.IsImplicitlyDereferenced) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsConst) modopt([mscorlib]System.Runtime.CompilerServices.IsSignUnspecifiedByte) int8** _from_object)
  IL_000F: ldloc.0  
  IL_0010: call     void [SaveMergeNNFiles]AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles::CSharpSaveMergennFiles(string, string)
  IL_0015: ret      
}
// MethodDef 0x060000A2  .ctor  flavor=IL rva=0x1644
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Object::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000A3  <MarshalCopy>  flavor=IL rva=0x1224
.method /* <MarshalCopy> */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: brfalse.s loc_311A
  IL_0003: ldarg.0  
  IL_0004: ldarg.1  
  IL_0005: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __ExceptionPtrCopy(void* A_0, modopt([mscorlib]System.Runtime.CompilerServices.IsConst) void* _to_object)
  IL_000A: ret      
}
// MethodDef 0x060000A4  <MarshalDestroy>  flavor=IL rva=0x123C
.method /* <MarshalDestroy> */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     modopt([mscorlib]System.Runtime.CompilerServices.CallConvCdecl) void __ExceptionPtrDestroy(void* A_0)
  IL_0006: ret      
}
// MethodDef 0x060000A5  .ctor  flavor=IL rva=0x1DB8
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000A6  .ctor  flavor=IL rva=0x3100
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000A7  .ctor  flavor=IL rva=0x3140
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void [mscorlib]System.Exception::.ctor(class [mscorlib]System.Runtime.Serialization.SerializationInfo, valuetype [mscorlib]System.Runtime.Serialization.StreamingContext)
  IL_0008: ret      
}
// MethodDef 0x060000A8  .ctor  flavor=IL rva=0x3128
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void [mscorlib]System.Exception::.ctor(string, class [mscorlib]System.Exception)
  IL_0008: ret      
}
// MethodDef 0x060000A9  .ctor  flavor=IL rva=0x3114
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: call     instance void [mscorlib]System.Exception::.ctor(string)
  IL_0007: ret      
}
// MethodDef 0x060000AA  .ctor  flavor=IL rva=0x3184
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void [mscorlib]System.Exception::.ctor(class [mscorlib]System.Runtime.Serialization.SerializationInfo, valuetype [mscorlib]System.Runtime.Serialization.StreamingContext)
  IL_0008: ret      
}
// MethodDef 0x060000AB  .ctor  flavor=IL rva=0x316C
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void [mscorlib]System.Exception::.ctor(string, class [mscorlib]System.Exception)
  IL_0008: ret      
}
// MethodDef 0x060000AC  .ctor  flavor=IL rva=0x3158
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: call     instance void [mscorlib]System.Exception::.ctor(string)
  IL_0007: ret      
}
// MethodDef 0x060000AD  .ctor  flavor=IL rva=0x32B0
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void <CrtImplementationDetails>.ModuleLoadException::.ctor(class [mscorlib]System.Runtime.Serialization.SerializationInfo info, valuetype [mscorlib]System.Runtime.Serialization.StreamingContext context)
  IL_0008: ldtoken  [mscorlib]System.Exception
  IL_000D: call     class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle)
  IL_0012: stloc.1  
  IL_0013: ldstr    aNestedexceptio// "NestedException"
  IL_0018: stloc.0  
  IL_0019: ldarg.0  
  IL_001A: ldarg.1  
  IL_001B: ldloc.0  
  IL_001C: ldloc.1  
  IL_001D: call     instance object [mscorlib]System.Runtime.Serialization.SerializationInfo::GetValue(string, class [mscorlib]System.Type)
  IL_0022: castclass [mscorlib]System.Exception
  IL_0027: call     instance void <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::set_NestedException(class [mscorlib]System.Exception __set_formal)
  IL_002C: ldarg.0  
  IL_002D: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_0032: ret      
}
// MethodDef 0x060000AE  .ctor  flavor=IL rva=0x3924
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void <CrtImplementationDetails>.ModuleLoadException::.ctor(string message, class [mscorlib]System.Exception innerException)
  IL_0008: ldarg.0  
  IL_0009: ldarg.3  
  IL_000A: call     instance void <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::set_NestedException(class [mscorlib]System.Exception __set_formal)
  IL_000F: ret      
}
// MethodDef 0x060000AF  get_NestedException  flavor=IL rva=0x319C
.method /* get_NestedException */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldfld    class [mscorlib]System.Exception <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::<backing_store>NestedException
  IL_0006: ret      
}
// MethodDef 0x060000B0  set_NestedException  flavor=IL rva=0x31B0
.method /* set_NestedException */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: stfld    class [mscorlib]System.Exception <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::<backing_store>NestedException
  IL_0007: ret      
}
// MethodDef 0x060000B1  ToString  flavor=IL rva=0x31C4
.method /* ToString */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: callvirt instance class [mscorlib]System.Exception [mscorlib]System.Exception::get_InnerException()
  IL_0006: brfalse.s loc_3886
  IL_0008: ldarg.0  
  IL_0009: callvirt instance class [mscorlib]System.Exception [mscorlib]System.Exception::get_InnerException()
  IL_000E: callvirt instance string [mscorlib]System.Exception::ToString()
  IL_0013: stloc.2  
  IL_0014: br.s     loc_388C
  IL_0016: ldsfld   string [mscorlib]System.String::Empty
  IL_001B: stloc.2  
  IL_001C: ldarg.0  
  IL_001D: call     instance class [mscorlib]System.Exception <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::get_NestedException()
  IL_0022: brfalse.s loc_38A2
  IL_0024: ldarg.0  
  IL_0025: call     instance class [mscorlib]System.Exception <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::get_NestedException()
  IL_002A: callvirt instance string [mscorlib]System.Exception::ToString()
  IL_002F: stloc.1  
  IL_0030: br.s     loc_38A8
  IL_0032: ldsfld   string [mscorlib]System.String::Empty
  IL_0037: stloc.1  
  IL_0038: ldc.i4.4 
  IL_0039: newarr   [mscorlib]System.Object
  IL_003E: stloc.0  
  IL_003F: ldarg.0  
  IL_0040: callvirt instance class [mscorlib]System.Type [mscorlib]System.Exception::GetType()
  IL_0045: stloc.s  6
  IL_0047: ldloc.0  
  IL_0048: ldc.i4.0 
  IL_0049: ldloc.s  6
  IL_004B: stelem.ref 
  IL_004C: ldarg.0  
  IL_004D: callvirt instance string [mscorlib]System.Exception::get_Message()
  IL_0052: brfalse.s loc_38CE
  IL_0054: ldarg.0  
  IL_0055: callvirt instance string [mscorlib]System.Exception::get_Message()
  IL_005A: stloc.s  5
  IL_005C: br.s     loc_38D5
  IL_005E: ldsfld   string [mscorlib]System.String::Empty
  IL_0063: stloc.s  5
  IL_0065: ldloc.0  
  IL_0066: ldc.i4.1 
  IL_0067: ldloc.s  5
  IL_0069: stelem.ref 
  IL_006A: ldloc.2  
  IL_006B: brfalse.s loc_38E2
  IL_006D: ldloc.2  
  IL_006E: stloc.s  4
  IL_0070: br.s     loc_38E9
  IL_0072: ldsfld   string [mscorlib]System.String::Empty
  IL_0077: stloc.s  4
  IL_0079: ldloc.0  
  IL_007A: ldc.i4.2 
  IL_007B: ldloc.s  4
  IL_007D: stelem.ref 
  IL_007E: ldloc.1  
  IL_007F: brfalse.s loc_38F5
  IL_0081: ldloc.1  
  IL_0082: stloc.3  
  IL_0083: br.s     loc_38FB
  IL_0085: ldsfld   string [mscorlib]System.String::Empty
  IL_008A: stloc.3  
  IL_008B: ldloc.0  
  IL_008C: ldc.i4.3 
  IL_008D: ldloc.3  
  IL_008E: stelem.ref 
  IL_008F: ldstr    a01StartOfPrima// "\n{0}: {1}\n--- Start of primary except"...
  IL_0094: ldloc.0  
  IL_0095: call     string [mscorlib]System.String::Format(string, object[])
  IL_009A: ldarg.0  
  IL_009B: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_00A0: ret      
}
// MethodDef 0x060000B2  GetObjectData  flavor=IL rva=0x3274
.method /* GetObjectData */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void [mscorlib]System.Exception::GetObjectData(class [mscorlib]System.Runtime.Serialization.SerializationInfo, valuetype [mscorlib]System.Runtime.Serialization.StreamingContext)
  IL_0008: ldtoken  [mscorlib]System.Exception
  IL_000D: call     class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle)
  IL_0012: stloc.1  
  IL_0013: ldarg.0  
  IL_0014: call     instance class [mscorlib]System.Exception <CrtImplementationDetails>.ModuleLoadExceptionHandlerException::get_NestedException()
  IL_0019: stloc.0  
  IL_001A: ldarg.1  
  IL_001B: ldstr    aNestedexceptio// "NestedException"
  IL_0020: ldloc.0  
  IL_0021: ldloc.1  
  IL_0022: call     instance void [mscorlib]System.Runtime.Serialization.SerializationInfo::AddValue(string, object, class [mscorlib]System.Type)
  IL_0027: ldarg.0  
  IL_0028: call     void [mscorlib]System.GC::KeepAlive(object)
  IL_002D: ret      
}
// MethodDef 0x060000B3  AddHandler  flavor=IL rva=0x331C
.method /* AddHandler */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stloc.0  
  IL_0002: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_0007: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_000C: ldsfld   object <CrtImplementationDetails>.ModuleUninitializer::lock
  IL_0011: ldloca.s 0
  IL_0013: call     void [mscorlib]System.Threading.Monitor::Enter(object, bool&)
  IL_0018: ldarg.1  
  IL_0019: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareDelegate(class [mscorlib]System.Delegate)
  IL_001E: ldarg.0  
  IL_001F: ldarg.1  
  IL_0020: callvirt instance void [mscorlib]System.Collections.Stack::Push(object)
  IL_0025: leave.s  loc_3995
  IL_0027: ldloc.0  
  IL_0028: brfalse.s loc_3994
  IL_002A: ldsfld   object <CrtImplementationDetails>.ModuleUninitializer::lock
  IL_002F: call     void [mscorlib]System.Threading.Monitor::Exit(object)
  IL_0034: endfinally 
  IL_0035: ret      
}
// MethodDef 0x060000B4  .cctor  flavor=IL rva=0x3DD0
.method /* .cctor */ cil managed { 
  IL_0000: newobj   instance void [mscorlib]System.Object::.ctor()
  IL_0005: stsfld   object <CrtImplementationDetails>.ModuleUninitializer::lock
  IL_000A: newobj   instance void <CrtImplementationDetails>.ModuleUninitializer::.ctor()
  IL_000F: stsfld   class <CrtImplementationDetails>.ModuleUninitializer <CrtImplementationDetails>.ModuleUninitializer::_ModuleUninitializer
  IL_0014: ret      
}
// MethodDef 0x060000B5  .ctor  flavor=IL rva=0x395C
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Collections.Stack::.ctor()
  IL_0006: ldarg.0  
  IL_0007: ldftn    instance void <CrtImplementationDetails>.ModuleUninitializer::SingletonDomainUnload(object source, class [mscorlib]System.EventArgs arguments)
  IL_000D: newobj   instance void [mscorlib]System.EventHandler::.ctor(object, native int)
  IL_0012: stloc.0  
  IL_0013: call     class [mscorlib]System.AppDomain [mscorlib]System.AppDomain::get_CurrentDomain()
  IL_0018: ldloc.0  
  IL_0019: callvirt instance void [mscorlib]System.AppDomain::add_DomainUnload(class [mscorlib]System.EventHandler)
  IL_001E: call     class [mscorlib]System.AppDomain [mscorlib]System.AppDomain::get_CurrentDomain()
  IL_0023: ldloc.0  
  IL_0024: callvirt instance void [mscorlib]System.AppDomain::add_ProcessExit(class [mscorlib]System.EventHandler)
  IL_0029: ret      
}
// MethodDef 0x060000B6  SingletonDomainUnload  flavor=IL rva=0x337C
.method /* SingletonDomainUnload */ cil managed { 
  IL_0000: ldc.i4.0 
  IL_0001: stloc.2  
  IL_0002: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_0007: call     void [mscorlib]System.Runtime.CompilerServices.RuntimeHelpers::PrepareConstrainedRegions()
  IL_000C: ldsfld   object <CrtImplementationDetails>.ModuleUninitializer::lock
  IL_0011: ldloca.s 2
  IL_0013: call     void [mscorlib]System.Threading.Monitor::Enter(object, bool&)
  IL_0018: ldarg.0  
  IL_0019: callvirt instance class [mscorlib]System.Collections.IEnumerator [mscorlib]System.Collections.Stack::GetEnumerator()
  IL_001E: stloc.0  
  IL_001F: ldloc.0  
  IL_0020: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext()
  IL_0025: brfalse.s loc_3A2B
  IL_0027: ldloc.0  
  IL_0028: callvirt instance object [mscorlib]System.Collections.IEnumerator::get_Current()
  IL_002D: castclass [mscorlib]System.EventHandler
  IL_0032: ldarg.1  
  IL_0033: ldarg.2  
  IL_0034: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs)
  IL_0039: br.s     loc_3A0F
  IL_003B: leave.s  loc_3A40
  IL_003D: ldloc.0  
  IL_003E: stloc.3  
  IL_003F: ldloc.0  
  IL_0040: isinst   [mscorlib]System.IDisposable
  IL_0045: stloc.1  
  IL_0046: ldloc.1  
  IL_0047: brfalse.s loc_3A3F
  IL_0049: ldloc.1  
  IL_004A: callvirt instance void [mscorlib]System.IDisposable::Dispose()
  IL_004F: endfinally 
  IL_0050: leave.s  loc_3A50
  IL_0052: ldloc.2  
  IL_0053: brfalse.s loc_3A4F
  IL_0055: ldsfld   object <CrtImplementationDetails>.ModuleUninitializer::lock
  IL_005A: call     void [mscorlib]System.Threading.Monitor::Exit(object)
  IL_005F: endfinally 
  IL_0060: ret      
}
// MethodDef 0x060000B7  .ctor  flavor=IL rva=0x3624
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: ldarg.1  
  IL_0002: ldarg.2  
  IL_0003: call     instance void [mscorlib]System.Exception::.ctor(class [mscorlib]System.Runtime.Serialization.SerializationInfo, valuetype [mscorlib]System.Runtime.Serialization.StreamingContext)
  IL_0008: ret      
}
// MethodDef 0x060000B8  .ctor  flavor=IL rva=0x3610
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Exception::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000B9  .ctor  flavor=IL rva=0x3DF4
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000BA  .ctor  flavor=IL rva=0x3ED8
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000BB  .ctor  flavor=IL rva=0x3FF4
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
// MethodDef 0x060000BC  .ctor  flavor=IL rva=0x4628
.method /* .ctor */ cil managed { 
  IL_0000: ldarg.0  
  IL_0001: call     instance void [mscorlib]System.Attribute::.ctor()
  IL_0006: ret      
}
