; NATIVE-340 s29 in-module constructor calls (IL 0x73 whose token is a local MethodDef)
; newobj = allocate + call .ctor; the target lives in this module (managed -> managed)

; caller MethodDef 0x06000020 SaveMergennFiles RVA 0x1A80
  IL_0000: newobj    0x060000A2   // newobj = alloc + call .ctor; target MethodDef 100663458 WrapSaveMergeNNFiles.WrapCall (this module)

; caller MethodDef 0x0600002B <CrtImplementationDetails>.ThrowNestedModuleLoadException RVA 0x3940
  IL_0007: newobj    0x060000AE   // newobj = alloc + call .ctor; target MethodDef 100663470 <CrtImplementationDetails>.ModuleLoadExceptionHandlerException (this module)

; caller MethodDef 0x0600002C <CrtImplementationDetails>.ThrowModuleLoadException RVA 0x32F0
  IL_0001: newobj    0x060000AC   // newobj = alloc + call .ctor; target MethodDef 100663468 <CrtImplementationDetails>.ModuleLoadException (this module)

; caller MethodDef 0x0600002D <CrtImplementationDetails>.ThrowModuleLoadException RVA 0x3304
  IL_0002: newobj    0x060000AB   // newobj = alloc + call .ctor; target MethodDef 100663467 <CrtImplementationDetails>.ModuleLoadException (this module)

; caller MethodDef 0x060000B4 .cctor RVA 0x3DD0
  IL_000A: newobj    0x060000B5   // newobj = alloc + call .ctor; target MethodDef 100663477 <CrtImplementationDetails>.ModuleUninitializer (this module)
