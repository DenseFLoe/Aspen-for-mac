/* NATIVE-340 .nep dispatch stubs: jmp qword ptr [slot]; the vtable slot is
   filled by the CLR loader, so the runtime entry is not statically known. */

/* FUNC 00005004  native -> managed via CLR VTableFixups */
void fixup_stub_00005004(void)
{
    /* site 00005004: jmp qword ptr [0x180019018]; static slot value = MethodDef 0x06000001
       (std.exception.{ctor}, RVA 0x10a0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005014  native -> managed via CLR VTableFixups */
void fixup_stub_00005014(void)
{
    /* site 00005014: jmp qword ptr [0x180019028]; static slot value = MethodDef 0x0600000A
       (std.exception_ptr.{ctor}, RVA 0x1120). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005024  native -> managed via CLR VTableFixups */
void fixup_stub_00005024(void)
{
    /* site 00005024: jmp qword ptr [0x180019050]; static slot value = MethodDef 0x0600000C
       (std.bad_alloc.{ctor}, RVA 0x1138). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005034  native -> managed via CLR VTableFixups */
void fixup_stub_00005034(void)
{
    /* site 00005034: jmp qword ptr [0x180019078]; static slot value = MethodDef 0x0600000B
       (std.bad_array_new_length.{ctor}, RVA 0x1198). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005044  native -> managed via CLR VTableFixups */
void fixup_stub_00005044(void)
{
    /* site 00005044: jmp qword ptr [0x180019088]; static slot value = MethodDef 0x060000A3
       (<MarshalCopy>, RVA 0x1224). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005054  native -> managed via CLR VTableFixups */
void fixup_stub_00005054(void)
{
    /* site 00005054: jmp qword ptr [0x180019098]; static slot value = MethodDef 0x060000A4
       (<MarshalDestroy>, RVA 0x123c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005064  native -> managed via CLR VTableFixups */
void fixup_stub_00005064(void)
{
    /* site 00005064: jmp qword ptr [0x1800190C0]; static slot value = MethodDef 0x0600000F
       (std.bad_variant_access.{ctor}, RVA 0x1250). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005074  native -> managed via CLR VTableFixups */
void fixup_stub_00005074(void)
{
    /* site 00005074: jmp qword ptr [0x1800190E8]; static slot value = MethodDef 0x06000013
       (std.bad_cast.{ctor}, RVA 0x12b0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005084  native -> managed via CLR VTableFixups */
void fixup_stub_00005084(void)
{
    /* site 00005084: jmp qword ptr [0x180019110]; static slot value = MethodDef 0x06000019
       (std.bad_weak_ptr.{ctor}, RVA 0x1324). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005094  native -> managed via CLR VTableFixups */
void fixup_stub_00005094(void)
{
    /* site 00005094: jmp qword ptr [0x180019120]; static slot value = MethodDef 0x06000014
       (std._Iterator_base12.{ctor}, RVA 0x1700). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000050A4  native -> managed via CLR VTableFixups */
void fixup_stub_000050A4(void)
{
    /* site 000050A4: jmp qword ptr [0x180019130]; static slot value = MethodDef 0x06000020
       (SaveMergennFiles, RVA 0x1a80). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000050B4  native -> managed via CLR VTableFixups */
void fixup_stub_000050B4(void)
{
    /* site 000050B4: jmp qword ptr [0x180019140]; static slot value = MethodDef 0x0600002A
       (new, RVA 0x1090). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000050C4  native -> managed via CLR VTableFixups */
void fixup_stub_000050C4(void)
{
    /* site 000050C4: jmp qword ptr [0x180019150]; static slot value = MethodDef 0x06000004
       (std.exception.__vecDelDtor, RVA 0x1a9c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000050D4  native -> managed via CLR VTableFixups */
void fixup_stub_000050D4(void)
{
    /* site 000050D4: jmp qword ptr [0x180019160]; static slot value = MethodDef 0x06000003
       (std.exception.what, RVA 0x1afc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000050E4  native -> managed via CLR VTableFixups */
void fixup_stub_000050E4(void)
{
    /* site 000050E4: jmp qword ptr [0x180019170]; static slot value = MethodDef 0x06000002
       (std.exception.{dtor}, RVA 0x10cc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000050F4  native -> managed via CLR VTableFixups */
void fixup_stub_000050F4(void)
{
    /* site 000050F4: jmp qword ptr [0x180019180]; static slot value = MethodDef 0x06000006
       (std.bad_alloc.{dtor}, RVA 0x10ec). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005104  native -> managed via CLR VTableFixups */
void fixup_stub_00005104(void)
{
    /* site 00005104: jmp qword ptr [0x180019190]; static slot value = MethodDef 0x06000009
       (std.exception_ptr.{dtor}, RVA 0x110c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005114  native -> managed via CLR VTableFixups */
void fixup_stub_00005114(void)
{
    /* site 00005114: jmp qword ptr [0x1800191A0]; static slot value = MethodDef 0x06000005
       (std.bad_alloc.__vecDelDtor, RVA 0x1b1c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005124  native -> managed via CLR VTableFixups */
void fixup_stub_00005124(void)
{
    /* site 00005124: jmp qword ptr [0x1800191B0]; static slot value = MethodDef 0x06000007
       (std.bad_array_new_length.__vecDelDtor, RVA 0x1b7c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005134  native -> managed via CLR VTableFixups */
void fixup_stub_00005134(void)
{
    /* site 00005134: jmp qword ptr [0x1800191C0]; static slot value = MethodDef 0x06000010
       (std.bad_variant_access.__vecDelDtor, RVA 0x1bfc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005144  native -> managed via CLR VTableFixups */
void fixup_stub_00005144(void)
{
    /* site 00005144: jmp qword ptr [0x1800191D0]; static slot value = MethodDef 0x0600000D
       (std.bad_variant_access.what, RVA 0x1c7c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005154  native -> managed via CLR VTableFixups */
void fixup_stub_00005154(void)
{
    /* site 00005154: jmp qword ptr [0x1800191E0]; static slot value = MethodDef 0x06000011
       (std.bad_cast.__vecDelDtor, RVA 0x1c90). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005164  native -> managed via CLR VTableFixups */
void fixup_stub_00005164(void)
{
    /* site 00005164: jmp qword ptr [0x1800191F0]; static slot value = MethodDef 0x06000015
       (std._Iterator_base12.=, RVA 0x1310). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005174  native -> managed via CLR VTableFixups */
void fixup_stub_00005174(void)
{
    /* site 00005174: jmp qword ptr [0x180019200]; static slot value = MethodDef 0x06000017
       (std.bad_weak_ptr.__vecDelDtor, RVA 0x1d10). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005184  native -> managed via CLR VTableFixups */
void fixup_stub_00005184(void)
{
    /* site 00005184: jmp qword ptr [0x180019210]; static slot value = MethodDef 0x06000016
       (std.bad_weak_ptr.what, RVA 0x1d90). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005194  native -> managed via CLR VTableFixups */
void fixup_stub_00005194(void)
{
    /* site 00005194: jmp qword ptr [0x180019220]; static slot value = MethodDef 0x0600001A
       (PtrToStringChars, RVA 0x1384). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000051A4  native -> managed via CLR VTableFixups */
void fixup_stub_000051A4(void)
{
    /* site 000051A4: jmp qword ptr [0x180019230]; static slot value = MethodDef 0x0600001B
       (msclr.interop.details.GetAnsiStringSize, RVA 0x13a0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000051B4  native -> managed via CLR VTableFixups */
void fixup_stub_000051B4(void)
{
    /* site 000051B4: jmp qword ptr [0x180019240]; static slot value = MethodDef 0x0600001C
       (msclr.interop.details.WriteAnsiString, RVA 0x13f4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000051C4  native -> managed via CLR VTableFixups */
void fixup_stub_000051C4(void)
{
    /* site 000051C4: jmp qword ptr [0x180019250]; static slot value = MethodDef 0x0600001D
       (msclr.interop.details.GetUnicodeStringSize, RVA 0x1460). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000051D4  native -> managed via CLR VTableFixups */
void fixup_stub_000051D4(void)
{
    /* site 000051D4: jmp qword ptr [0x180019260]; static slot value = MethodDef 0x0600001E
       (msclr.interop.details.WriteUnicodeString, RVA 0x14a8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000051E4  native -> managed via CLR VTableFixups */
void fixup_stub_000051E4(void)
{
    /* site 000051E4: jmp qword ptr [0x180019270]; static slot value = MethodDef 0x06000021
       (msclr.interop.details.char_buffer<char>.release, RVA 0x1658). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000051F4  native -> managed via CLR VTableFixups */
void fixup_stub_000051F4(void)
{
    /* site 000051F4: jmp qword ptr [0x180019280]; static slot value = MethodDef 0x06000022
       (msclr.interop.details.char_buffer<char>.get, RVA 0x166c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005204  native -> managed via CLR VTableFixups */
void fixup_stub_00005204(void)
{
    /* site 00005204: jmp qword ptr [0x180019290]; static slot value = MethodDef 0x06000023
       (msclr.interop.details.char_buffer<char>.{dtor}, RVA 0x167c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005214  native -> managed via CLR VTableFixups */
void fixup_stub_00005214(void)
{
    /* site 00005214: jmp qword ptr [0x1800192A0]; static slot value = MethodDef 0x06000024
       (msclr.interop.details.char_buffer<char>.{ctor}, RVA 0x1690). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005224  native -> managed via CLR VTableFixups */
void fixup_stub_00005224(void)
{
    /* site 00005224: jmp qword ptr [0x1800192B0]; static slot value = MethodDef 0x06000025
       (msclr.interop.details.char_buffer<wchar_t>.get, RVA 0x16a8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005234  native -> managed via CLR VTableFixups */
void fixup_stub_00005234(void)
{
    /* site 00005234: jmp qword ptr [0x1800192C0]; static slot value = MethodDef 0x06000026
       (msclr.interop.details.char_buffer<wchar_t>.{dtor}, RVA 0x16b8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005244  native -> managed via CLR VTableFixups */
void fixup_stub_00005244(void)
{
    /* site 00005244: jmp qword ptr [0x1800192D0]; static slot value = MethodDef 0x06000027
       (msclr.interop.details.char_buffer<wchar_t>.{ctor}, RVA 0x16cc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005254  native -> managed via CLR VTableFixups */
void fixup_stub_00005254(void)
{
    /* site 00005254: jmp qword ptr [0x1800192E0]; static slot value = MethodDef 0x0600001F
       (msclr.interop.details.InternalAnsiToStringHelper, RVA 0x171c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005264  native -> managed via CLR VTableFixups */
void fixup_stub_00005264(void)
{
    /* site 00005264: jmp qword ptr [0x1800192F0]; static slot value = MethodDef 0x06000029
       (msclr.interop._Marshal_as_impl<class System::String ^>, RVA 0x19bc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005274  native -> managed via CLR VTableFixups */
void fixup_stub_00005274(void)
{
    /* site 00005274: jmp qword ptr [0x180019300]; static slot value = MethodDef 0x06000028
       (msclr.interop.marshal_as<class System::String ^,char *>, RVA 0x1a28). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005284  native -> managed via CLR VTableFixups */
void fixup_stub_00005284(void)
{
    /* site 00005284: jmp qword ptr [0x180019310]; static slot value = MethodDef 0x06000008
       (std.bad_array_new_length.{dtor}, RVA 0x1bdc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005294  native -> managed via CLR VTableFixups */
void fixup_stub_00005294(void)
{
    /* site 00005294: jmp qword ptr [0x180019320]; static slot value = MethodDef 0x0600000E
       (std.bad_variant_access.{dtor}, RVA 0x1c5c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000052A4  native -> managed via CLR VTableFixups */
void fixup_stub_000052A4(void)
{
    /* site 000052A4: jmp qword ptr [0x180019330]; static slot value = MethodDef 0x06000012
       (std.bad_cast.{dtor}, RVA 0x1cf0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000052B4  native -> managed via CLR VTableFixups */
void fixup_stub_000052B4(void)
{
    /* site 000052B4: jmp qword ptr [0x180019340]; static slot value = MethodDef 0x06000018
       (std.bad_weak_ptr.{dtor}, RVA 0x1d70). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000052C4  native -> managed via CLR VTableFixups */
void fixup_stub_000052C4(void)
{
    /* site 000052C4: jmp qword ptr [0x180019388]; static slot value = MethodDef 0x06000051
       (.cctor, RVA 0x3d80). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000052D4  native -> managed via CLR VTableFixups */
void fixup_stub_000052D4(void)
{
    /* site 000052D4: jmp qword ptr [0x180019398]; static slot value = MethodDef 0x0600002C
       (<CrtImplementationDetails>.ThrowModuleLoadException, RVA 0x32f0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000052E4  native -> managed via CLR VTableFixups */
void fixup_stub_000052E4(void)
{
    /* site 000052E4: jmp qword ptr [0x1800193A8]; static slot value = MethodDef 0x0600002D
       (<CrtImplementationDetails>.ThrowModuleLoadException, RVA 0x3304). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000052F4  native -> managed via CLR VTableFixups */
void fixup_stub_000052F4(void)
{
    /* site 000052F4: jmp qword ptr [0x1800193B8]; static slot value = MethodDef 0x0600002E
       (<CrtImplementationDetails>.RegisterModuleUninitializer, RVA 0x3420). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005304  native -> managed via CLR VTableFixups */
void fixup_stub_00005304(void)
{
    /* site 00005304: jmp qword ptr [0x1800193C8]; static slot value = MethodDef 0x0600002F
       (<CrtImplementationDetails>.FromGUID, RVA 0x3438). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005314  native -> managed via CLR VTableFixups */
void fixup_stub_00005314(void)
{
    /* site 00005314: jmp qword ptr [0x1800193D8]; static slot value = MethodDef 0x06000030
       (__get_default_appdomain, RVA 0x3488). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005324  native -> managed via CLR VTableFixups */
void fixup_stub_00005324(void)
{
    /* site 00005324: jmp qword ptr [0x1800193E8]; static slot value = MethodDef 0x06000031
       (__release_appdomain, RVA 0x3508). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005334  native -> managed via CLR VTableFixups */
void fixup_stub_00005334(void)
{
    /* site 00005334: jmp qword ptr [0x1800193F8]; static slot value = MethodDef 0x06000032
       (<CrtImplementationDetails>.GetDefaultDomain, RVA 0x3524). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005344  native -> managed via CLR VTableFixups */
void fixup_stub_00005344(void)
{
    /* site 00005344: jmp qword ptr [0x180019408]; static slot value = MethodDef 0x06000033
       (<CrtImplementationDetails>.DoCallBackInDefaultDomain, RVA 0x3584). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005354  native -> managed via CLR VTableFixups */
void fixup_stub_00005354(void)
{
    /* site 00005354: jmp qword ptr [0x180019418]; static slot value = MethodDef 0x06000034
       (__scrt_is_safe_for_managed_code, RVA 0x363c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005364  native -> managed via CLR VTableFixups */
void fixup_stub_00005364(void)
{
    /* site 00005364: jmp qword ptr [0x180019428]; static slot value = MethodDef 0x06000035
       (<CrtImplementationDetails>.DefaultDomain.DoNothing, RVA 0x3670). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005374  native -> managed via CLR VTableFixups */
void fixup_stub_00005374(void)
{
    /* site 00005374: jmp qword ptr [0x180019438]; static slot value = MethodDef 0x06000036
       (<CrtImplementationDetails>.DefaultDomain.HasPerProcess, RVA 0x3690). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005384  native -> managed via CLR VTableFixups */
void fixup_stub_00005384(void)
{
    /* site 00005384: jmp qword ptr [0x180019448]; static slot value = MethodDef 0x06000037
       (<CrtImplementationDetails>.DefaultDomain.HasNative, RVA 0x36e4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005394  native -> managed via CLR VTableFixups */
void fixup_stub_00005394(void)
{
    /* site 00005394: jmp qword ptr [0x180019458]; static slot value = MethodDef 0x06000038
       (<CrtImplementationDetails>.DefaultDomain.NeedsInitialization, RVA 0x3764). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000053A4  native -> managed via CLR VTableFixups */
void fixup_stub_000053A4(void)
{
    /* site 000053A4: jmp qword ptr [0x180019468]; static slot value = MethodDef 0x06000039
       (<CrtImplementationDetails>.DefaultDomain.NeedsUninitialization, RVA 0x379c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000053B4  native -> managed via CLR VTableFixups */
void fixup_stub_000053B4(void)
{
    /* site 000053B4: jmp qword ptr [0x180019478]; static slot value = MethodDef 0x0600003A
       (<CrtImplementationDetails>.DefaultDomain.Initialize, RVA 0x37b0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000053C4  native -> managed via CLR VTableFixups */
void fixup_stub_000053C4(void)
{
    /* site 000053C4: jmp qword ptr [0x180019488]; static slot value = MethodDef 0x06000049
       (<CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain, RVA 0x37cc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000053D4  native -> managed via CLR VTableFixups */
void fixup_stub_000053D4(void)
{
    /* site 000053D4: jmp qword ptr [0x180019498]; static slot value = MethodDef 0x0600004A
       (<CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain, RVA 0x37e0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000053E4  native -> managed via CLR VTableFixups */
void fixup_stub_000053E4(void)
{
    /* site 000053E4: jmp qword ptr [0x1800194A8]; static slot value = MethodDef 0x0600004B
       (<CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain, RVA 0x3818). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000053F4  native -> managed via CLR VTableFixups */
void fixup_stub_000053F4(void)
{
    /* site 000053F4: jmp qword ptr [0x1800194B8]; static slot value = MethodDef 0x0600004C
       (<CrtImplementationDetails>.LanguageSupport.DomainUnload, RVA 0x3850). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005404  native -> managed via CLR VTableFixups */
void fixup_stub_00005404(void)
{
    /* site 00005404: jmp qword ptr [0x1800194C8]; static slot value = MethodDef 0x06000052
       (gcroot<System::String ^>..PE$AAVString@System@@, RVA 0x388c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005414  native -> managed via CLR VTableFixups */
void fixup_stub_00005414(void)
{
    /* site 00005414: jmp qword ptr [0x1800194D8]; static slot value = MethodDef 0x06000053
       (gcroot<System::String ^>.=, RVA 0x38b0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005424  native -> managed via CLR VTableFixups */
void fixup_stub_00005424(void)
{
    /* site 00005424: jmp qword ptr [0x1800194E8]; static slot value = MethodDef 0x06000054
       (gcroot<System::String ^>.{dtor}, RVA 0x38d8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005434  native -> managed via CLR VTableFixups */
void fixup_stub_00005434(void)
{
    /* site 00005434: jmp qword ptr [0x1800194F8]; static slot value = MethodDef 0x06000055
       (gcroot<System::String ^>.{ctor}, RVA 0x3900). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005444  native -> managed via CLR VTableFixups */
void fixup_stub_00005444(void)
{
    /* site 00005444: jmp qword ptr [0x180019508]; static slot value = MethodDef 0x0600002B
       (<CrtImplementationDetails>.ThrowNestedModuleLoadException, RVA 0x3940). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005454  native -> managed via CLR VTableFixups */
void fixup_stub_00005454(void)
{
    /* site 00005454: jmp qword ptr [0x180019518]; static slot value = MethodDef 0x06000042
       (<CrtImplementationDetails>.LanguageSupport.InitializeVtables, RVA 0x3994). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005464  native -> managed via CLR VTableFixups */
void fixup_stub_00005464(void)
{
    /* site 00005464: jmp qword ptr [0x180019528]; static slot value = MethodDef 0x06000043
       (<CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain, RVA 0x39c8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005474  native -> managed via CLR VTableFixups */
void fixup_stub_00005474(void)
{
    /* site 00005474: jmp qword ptr [0x180019538]; static slot value = MethodDef 0x06000044
       (<CrtImplementationDetails>.LanguageSupport.InitializeNative, RVA 0x39e8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005484  native -> managed via CLR VTableFixups */
void fixup_stub_00005484(void)
{
    /* site 00005484: jmp qword ptr [0x180019548]; static slot value = MethodDef 0x06000045
       (<CrtImplementationDetails>.LanguageSupport.InitializePerProcess, RVA 0x3a78). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005494  native -> managed via CLR VTableFixups */
void fixup_stub_00005494(void)
{
    /* site 00005494: jmp qword ptr [0x180019558]; static slot value = MethodDef 0x06000046
       (<CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain, RVA 0x3ab8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000054A4  native -> managed via CLR VTableFixups */
void fixup_stub_000054A4(void)
{
    /* site 000054A4: jmp qword ptr [0x180019568]; static slot value = MethodDef 0x06000047
       (<CrtImplementationDetails>.LanguageSupport.InitializeUninitializer, RVA 0x3af4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000054B4  native -> managed via CLR VTableFixups */
void fixup_stub_000054B4(void)
{
    /* site 000054B4: jmp qword ptr [0x180019578]; static slot value = MethodDef 0x06000048
       (<CrtImplementationDetails>.LanguageSupport._Initialize, RVA 0x3b20). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000054C4  native -> managed via CLR VTableFixups */
void fixup_stub_000054C4(void)
{
    /* site 000054C4: jmp qword ptr [0x180019588]; static slot value = MethodDef 0x0600004D
       (<CrtImplementationDetails>.LanguageSupport.Cleanup, RVA 0x3c24). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000054D4  native -> managed via CLR VTableFixups */
void fixup_stub_000054D4(void)
{
    /* site 000054D4: jmp qword ptr [0x180019598]; static slot value = MethodDef 0x0600004E
       (<CrtImplementationDetails>.LanguageSupport.{ctor}, RVA 0x3c98). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000054E4  native -> managed via CLR VTableFixups */
void fixup_stub_000054E4(void)
{
    /* site 000054E4: jmp qword ptr [0x1800195A8]; static slot value = MethodDef 0x0600004F
       (<CrtImplementationDetails>.LanguageSupport.{dtor}, RVA 0x3cb0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000054F4  native -> managed via CLR VTableFixups */
void fixup_stub_000054F4(void)
{
    /* site 000054F4: jmp qword ptr [0x1800195B8]; static slot value = MethodDef 0x06000050
       (<CrtImplementationDetails>.LanguageSupport.Initialize, RVA 0x3cc4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005500  native -> managed via CLR VTableFixups */
void fixup_stub_00005500(void)
{
    /* site 00005500: jmp qword ptr [0x1800195C8]; static slot value = MethodDef 0x0600003B
       (?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ, RVA 0x1000). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005510  native -> managed via CLR VTableFixups */
void fixup_stub_00005510(void)
{
    /* site 00005510: jmp qword ptr [0x1800195D0]; static slot value = MethodDef 0x0600003C
       (?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ, RVA 0x1014). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005520  native -> managed via CLR VTableFixups */
void fixup_stub_00005520(void)
{
    /* site 00005520: jmp qword ptr [0x1800195D8]; static slot value = MethodDef 0x0600003D
       (?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ, RVA 0x1028). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005530  native -> managed via CLR VTableFixups */
void fixup_stub_00005530(void)
{
    /* site 00005530: jmp qword ptr [0x1800195E0]; static slot value = MethodDef 0x0600003E
       (?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x103c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005540  native -> managed via CLR VTableFixups */
void fixup_stub_00005540(void)
{
    /* site 00005540: jmp qword ptr [0x1800195E8]; static slot value = MethodDef 0x0600003F
       (?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x1050). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005550  native -> managed via CLR VTableFixups */
void fixup_stub_00005550(void)
{
    /* site 00005550: jmp qword ptr [0x1800195F0]; static slot value = MethodDef 0x06000040
       (?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x1064). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005560  native -> managed via CLR VTableFixups */
void fixup_stub_00005560(void)
{
    /* site 00005560: jmp qword ptr [0x1800195F8]; static slot value = MethodDef 0x06000041
       (?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ, RVA 0x1078). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005574  native -> managed via CLR VTableFixups */
void fixup_stub_00005574(void)
{
    /* site 00005574: jmp qword ptr [0x180019600]; static slot value = MethodDef 0x06000056
       (___CxxCallUnwindDtor, RVA 0x3e08). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005584  native -> managed via CLR VTableFixups */
void fixup_stub_00005584(void)
{
    /* site 00005584: jmp qword ptr [0x180019610]; static slot value = MethodDef 0x06000057
       (___CxxCallUnwindDelDtor, RVA 0x3e4c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005594  native -> managed via CLR VTableFixups */
void fixup_stub_00005594(void)
{
    /* site 00005594: jmp qword ptr [0x180019620]; static slot value = MethodDef 0x06000058
       (___CxxCallUnwindVecDtor, RVA 0x3e90). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000055A4  native -> managed via CLR VTableFixups */
void fixup_stub_000055A4(void)
{
    /* site 000055A4: jmp qword ptr [0x180019630]; static slot value = MethodDef 0x0600005B
       (__ArrayUnwind, RVA 0x3f24). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000055B4  native -> managed via CLR VTableFixups */
void fixup_stub_000055B4(void)
{
    /* site 000055B4: jmp qword ptr [0x180019640]; static slot value = MethodDef 0x06000059
       (__ehvec_dtor, RVA 0x3f7c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000055C4  native -> managed via CLR VTableFixups */
void fixup_stub_000055C4(void)
{
    /* site 000055C4: jmp qword ptr [0x180019650]; static slot value = MethodDef 0x0600005C
       (__ehvec_dtor, RVA 0x3fdc). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000055D4  native -> managed via CLR VTableFixups */
void fixup_stub_000055D4(void)
{
    /* site 000055D4: jmp qword ptr [0x180019660]; static slot value = MethodDef 0x0600005A
       (?A0x9c83a709.ArrayUnwindFilter, RVA 0x3eec). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000055E4  native -> managed via CLR VTableFixups */
void fixup_stub_000055E4(void)
{
    /* site 000055E4: jmp qword ptr [0x180019670]; static slot value = MethodDef 0x0600006B
       (_atexit_helper, RVA 0x419c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000055F4  native -> managed via CLR VTableFixups */
void fixup_stub_000055F4(void)
{
    /* site 000055F4: jmp qword ptr [0x180019680]; static slot value = MethodDef 0x0600006C
       (_exit_callback, RVA 0x4314). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005604  native -> managed via CLR VTableFixups */
void fixup_stub_00005604(void)
{
    /* site 00005604: jmp qword ptr [0x180019690]; static slot value = MethodDef 0x0600006F
       (_atexit_m, RVA 0x43c4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005614  native -> managed via CLR VTableFixups */
void fixup_stub_00005614(void)
{
    /* site 00005614: jmp qword ptr [0x1800196A0]; static slot value = MethodDef 0x06000071
       (_app_exit_callback, RVA 0x43ec). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005624  native -> managed via CLR VTableFixups */
void fixup_stub_00005624(void)
{
    /* site 00005624: jmp qword ptr [0x1800196B0]; static slot value = MethodDef 0x06000073
       (_atexit_m_appdomain, RVA 0x44d8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005634  native -> managed via CLR VTableFixups */
void fixup_stub_00005634(void)
{
    /* site 00005634: jmp qword ptr [0x1800196C0]; static slot value = MethodDef 0x0600006D
       (_initatexit_m, RVA 0x4564). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005644  native -> managed via CLR VTableFixups */
void fixup_stub_00005644(void)
{
    /* site 00005644: jmp qword ptr [0x1800196D0]; static slot value = MethodDef 0x0600006E
       (_onexit_m, RVA 0x45ac). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005654  native -> managed via CLR VTableFixups */
void fixup_stub_00005654(void)
{
    /* site 00005654: jmp qword ptr [0x1800196E0]; static slot value = MethodDef 0x06000070
       (_initatexit_app_domain, RVA 0x45c8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005664  native -> managed via CLR VTableFixups */
void fixup_stub_00005664(void)
{
    /* site 00005664: jmp qword ptr [0x1800196F0]; static slot value = MethodDef 0x06000072
       (_onexit_m_appdomain, RVA 0x460c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005674  native -> managed via CLR VTableFixups */
void fixup_stub_00005674(void)
{
    /* site 00005674: jmp qword ptr [0x180019700]; static slot value = MethodDef 0x0600005D
       (<CrtImplementationDetails>.AtExitLock._handle, RVA 0x4008). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005684  native -> managed via CLR VTableFixups */
void fixup_stub_00005684(void)
{
    /* site 00005684: jmp qword ptr [0x180019710]; static slot value = MethodDef 0x0600005F
       (<CrtImplementationDetails>.AtExitLock._lock_Set, RVA 0x4038). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005694  native -> managed via CLR VTableFixups */
void fixup_stub_00005694(void)
{
    /* site 00005694: jmp qword ptr [0x180019720]; static slot value = MethodDef 0x06000060
       (<CrtImplementationDetails>.AtExitLock._lock_Get, RVA 0x4088). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000056A4  native -> managed via CLR VTableFixups */
void fixup_stub_000056A4(void)
{
    /* site 000056A4: jmp qword ptr [0x180019730]; static slot value = MethodDef 0x06000061
       (<CrtImplementationDetails>.AtExitLock._lock_Destruct, RVA 0x40ac). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000056B4  native -> managed via CLR VTableFixups */
void fixup_stub_000056B4(void)
{
    /* site 000056B4: jmp qword ptr [0x180019740]; static slot value = MethodDef 0x06000062
       (<CrtImplementationDetails>.AtExitLock.IsInitialized, RVA 0x40d4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000056C4  native -> managed via CLR VTableFixups */
void fixup_stub_000056C4(void)
{
    /* site 000056C4: jmp qword ptr [0x180019750]; static slot value = MethodDef 0x06000064
       (<CrtImplementationDetails>.AtExitLock.RemoveRef, RVA 0x40f0). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000056D4  native -> managed via CLR VTableFixups */
void fixup_stub_000056D4(void)
{
    /* site 000056D4: jmp qword ptr [0x180019760]; static slot value = MethodDef 0x06000065
       (<CrtImplementationDetails>.AtExitLock.Enter, RVA 0x4118). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000056E4  native -> managed via CLR VTableFixups */
void fixup_stub_000056E4(void)
{
    /* site 000056E4: jmp qword ptr [0x180019770]; static slot value = MethodDef 0x06000066
       (<CrtImplementationDetails>.AtExitLock.Exit, RVA 0x4130). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 000056F4  native -> managed via CLR VTableFixups */
void fixup_stub_000056F4(void)
{
    /* site 000056F4: jmp qword ptr [0x180019780]; static slot value = MethodDef 0x06000067
       (?A0xdf32f105.__global_lock, RVA 0x4148). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005704  native -> managed via CLR VTableFixups */
void fixup_stub_00005704(void)
{
    /* site 00005704: jmp qword ptr [0x180019790]; static slot value = MethodDef 0x06000068
       (?A0xdf32f105.__global_unlock, RVA 0x4168). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005714  native -> managed via CLR VTableFixups */
void fixup_stub_00005714(void)
{
    /* site 00005714: jmp qword ptr [0x1800197A0]; static slot value = MethodDef 0x0600006A
       (?A0xdf32f105.__dealloc_global_lock, RVA 0x4188). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005724  native -> managed via CLR VTableFixups */
void fixup_stub_00005724(void)
{
    /* site 00005724: jmp qword ptr [0x1800197B0]; static slot value = MethodDef 0x0600005E
       (<CrtImplementationDetails>.AtExitLock._lock_Construct, RVA 0x4500). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005734  native -> managed via CLR VTableFixups */
void fixup_stub_00005734(void)
{
    /* site 00005734: jmp qword ptr [0x1800197C0]; static slot value = MethodDef 0x06000063
       (<CrtImplementationDetails>.AtExitLock.AddRef, RVA 0x451c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005744  native -> managed via CLR VTableFixups */
void fixup_stub_00005744(void)
{
    /* site 00005744: jmp qword ptr [0x1800197D0]; static slot value = MethodDef 0x06000069
       (?A0xdf32f105.__alloc_global_lock, RVA 0x454c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005754  native -> managed via CLR VTableFixups */
void fixup_stub_00005754(void)
{
    /* site 00005754: jmp qword ptr [0x1800197E0]; static slot value = MethodDef 0x06000076
       (_initterm_e, RVA 0x463c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005764  native -> managed via CLR VTableFixups */
void fixup_stub_00005764(void)
{
    /* site 00005764: jmp qword ptr [0x1800197F0]; static slot value = MethodDef 0x06000077
       (_initterm, RVA 0x466c). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005774  native -> managed via CLR VTableFixups */
void fixup_stub_00005774(void)
{
    /* site 00005774: jmp qword ptr [0x180019800]; static slot value = MethodDef 0x06000079
       (_initterm_m, RVA 0x46e4). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005784  native -> managed via CLR VTableFixups */
void fixup_stub_00005784(void)
{
    /* site 00005784: jmp qword ptr [0x180019810]; static slot value = MethodDef 0x06000078
       (<CrtImplementationDetails>.ThisModule.Handle, RVA 0x4694). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}

/* FUNC 00005794  native -> managed via CLR VTableFixups */
void fixup_stub_00005794(void)
{
    /* site 00005794: jmp qword ptr [0x180019820]; static slot value = MethodDef 0x0600007A
       (<CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)>, RVA 0x46b8). The CLR loader rewrites this slot with the runtime
       entry, so the effective target address stays a runtime value. */
}
