; NATIVE-340 external newobj sites (IL opcode 0x73) with their resolved ctor
; newobj = allocate + call .ctor, so each line is a managed -> external ctor edge

; caller MethodDef 0x0600001B msclr.interop.details.GetAnsiStringSize RVA 0x13A0
  IL_003B: newobj    0x0A000027   // newobj = alloc + call .ctor; target System.ArgumentException::.ctor [external]

; caller MethodDef 0x0600001C msclr.interop.details.WriteAnsiString RVA 0x13F4
  IL_001E: newobj    0x0A000026   // newobj = alloc + call .ctor; target System.ArgumentOutOfRangeException::.ctor [external]

; caller MethodDef 0x0600001C msclr.interop.details.WriteAnsiString RVA 0x13F4
  IL_0057: newobj    0x0A000027   // newobj = alloc + call .ctor; target System.ArgumentException::.ctor [external]

; caller MethodDef 0x0600001D msclr.interop.details.GetUnicodeStringSize RVA 0x1460
  IL_000E: newobj    0x0A000026   // newobj = alloc + call .ctor; target System.ArgumentOutOfRangeException::.ctor [external]

; caller MethodDef 0x0600001D msclr.interop.details.GetUnicodeStringSize RVA 0x1460
  IL_002E: newobj    0x0A000027   // newobj = alloc + call .ctor; target System.ArgumentException::.ctor [external]

; caller MethodDef 0x0600001E msclr.interop.details.WriteUnicodeString RVA 0x14A8
  IL_003C: newobj    0x0A000027   // newobj = alloc + call .ctor; target System.ArgumentException::.ctor [external]

; caller MethodDef 0x0600001E msclr.interop.details.WriteUnicodeString RVA 0x14A8
  IL_0047: newobj    0x0A000026   // newobj = alloc + call .ctor; target System.ArgumentOutOfRangeException::.ctor [external]

; caller MethodDef 0x0600001F msclr.interop.details.InternalAnsiToStringHelper RVA 0x171C
  IL_003C: newobj    0x0A000025   // newobj = alloc + call .ctor; target System.InsufficientMemoryException::.ctor [external]

; caller MethodDef 0x0600001F msclr.interop.details.InternalAnsiToStringHelper RVA 0x171C
  IL_0051: newobj    0x0A000024   // newobj = alloc + call .ctor; target System.String::.ctor [external]

; caller MethodDef 0x0600001F msclr.interop.details.InternalAnsiToStringHelper RVA 0x171C
  IL_0074: newobj    0x0A000026   // newobj = alloc + call .ctor; target System.ArgumentOutOfRangeException::.ctor [external]

; caller MethodDef 0x06000047 <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer RVA 0x3AF4
  IL_0013: newobj    0x0A00004A   // newobj = alloc + call .ctor; target System.EventHandler::.ctor [external]

; caller MethodDef 0x06000063 <CrtImplementationDetails>.AtExitLock.AddRef RVA 0x451C
  IL_0007: newobj    0x0A000023   // newobj = alloc + call .ctor; target System.Object::.ctor [external]

; caller MethodDef 0x06000091 .ctor RVA 0x17EC
  IL_0038: newobj    0x0A000025   // newobj = alloc + call .ctor; target System.InsufficientMemoryException::.ctor [external]

; caller MethodDef 0x0600009D .ctor RVA 0x15BC
  IL_0001: newobj    0x0A000019   // newobj = alloc + call .ctor; target ::.ctor [external]

; caller MethodDef 0x060000B4 .cctor RVA 0x3DD0
  IL_0000: newobj    0x0A000023   // newobj = alloc + call .ctor; target System.Object::.ctor [external]

; caller MethodDef 0x060000B5 .ctor RVA 0x395C
  IL_000D: newobj    0x0A00004A   // newobj = alloc + call .ctor; target System.EventHandler::.ctor [external]
