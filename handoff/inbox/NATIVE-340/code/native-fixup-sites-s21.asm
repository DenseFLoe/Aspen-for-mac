; NATIVE-340 s21 .nep slot jumps that s17 did not register
; each site is the direct target of the EB 08 predecessor recorded above it

; FUNC 0000500A-00005010 fixup_stub_0000500A pred 0x5000 (eb08) -> slot 0x19020 token 0x06000001 std.exception.{ctor} RVA 0x10A0
0000500A  FF 25 10 40 01 00  JMP qword ptr [0x180019020]

; FUNC 0000501A-00005020 fixup_stub_0000501A pred 0x5010 (eb08) -> slot 0x19030 token 0x0600000A std.exception_ptr.{ctor} RVA 0x1120
0000501A  FF 25 10 40 01 00  JMP qword ptr [0x180019030]

; FUNC 0000502A-00005030 fixup_stub_0000502A pred 0x5020 (eb08) -> slot 0x19058 token 0x0600000C std.bad_alloc.{ctor} RVA 0x1138
0000502A  FF 25 28 40 01 00  JMP qword ptr [0x180019058]

; FUNC 0000503A-00005040 fixup_stub_0000503A pred 0x5030 (eb08) -> slot 0x19080 token 0x0600000B std.bad_array_new_length.{ctor} RVA 0x1198
0000503A  FF 25 40 40 01 00  JMP qword ptr [0x180019080]

; FUNC 0000504A-00005050 fixup_stub_0000504A pred 0x5040 (eb08) -> slot 0x19090 token 0x060000A3 <MarshalCopy> RVA 0x1224
0000504A  FF 25 40 40 01 00  JMP qword ptr [0x180019090]

; FUNC 0000505A-00005060 fixup_stub_0000505A pred 0x5050 (eb08) -> slot 0x190a0 token 0x060000A4 <MarshalDestroy> RVA 0x123C
0000505A  FF 25 40 40 01 00  JMP qword ptr [0x1800190A0]

; FUNC 0000506A-00005070 fixup_stub_0000506A pred 0x5060 (eb08) -> slot 0x190c8 token 0x0600000F std.bad_variant_access.{ctor} RVA 0x1250
0000506A  FF 25 58 40 01 00  JMP qword ptr [0x1800190C8]

; FUNC 0000507A-00005080 fixup_stub_0000507A pred 0x5070 (eb08) -> slot 0x190f0 token 0x06000013 std.bad_cast.{ctor} RVA 0x12B0
0000507A  FF 25 70 40 01 00  JMP qword ptr [0x1800190F0]

; FUNC 0000508A-00005090 fixup_stub_0000508A pred 0x5080 (eb08) -> slot 0x19118 token 0x06000019 std.bad_weak_ptr.{ctor} RVA 0x1324
0000508A  FF 25 88 40 01 00  JMP qword ptr [0x180019118]

; FUNC 0000509A-000050A0 fixup_stub_0000509A pred 0x5090 (eb08) -> slot 0x19128 token 0x06000014 std._Iterator_base12.{ctor} RVA 0x1700
0000509A  FF 25 88 40 01 00  JMP qword ptr [0x180019128]

; FUNC 000050BA-000050C0 fixup_stub_000050BA pred 0x50B0 (eb08) -> slot 0x19148 token 0x0600002A new RVA 0x1090
000050BA  FF 25 88 40 01 00  JMP qword ptr [0x180019148]

; FUNC 000050DA-000050E0 fixup_stub_000050DA pred 0x50D0 (eb08) -> slot 0x19168 token 0x06000003 std.exception.what RVA 0x1AFC
000050DA  FF 25 88 40 01 00  JMP qword ptr [0x180019168]

; FUNC 000050EA-000050F0 fixup_stub_000050EA pred 0x50E0 (eb08) -> slot 0x19178 token 0x06000002 std.exception.{dtor} RVA 0x10CC
000050EA  FF 25 88 40 01 00  JMP qword ptr [0x180019178]

; FUNC 000050FA-00005100 fixup_stub_000050FA pred 0x50F0 (eb08) -> slot 0x19188 token 0x06000006 std.bad_alloc.{dtor} RVA 0x10EC
000050FA  FF 25 88 40 01 00  JMP qword ptr [0x180019188]

; FUNC 0000510A-00005110 fixup_stub_0000510A pred 0x5100 (eb08) -> slot 0x19198 token 0x06000009 std.exception_ptr.{dtor} RVA 0x110C
0000510A  FF 25 88 40 01 00  JMP qword ptr [0x180019198]

; FUNC 0000516A-00005170 fixup_stub_0000516A pred 0x5160 (eb08) -> slot 0x191f8 token 0x06000015 std._Iterator_base12.= RVA 0x1310
0000516A  FF 25 88 40 01 00  JMP qword ptr [0x1800191F8]

; FUNC 0000519A-000051A0 fixup_stub_0000519A pred 0x5190 (eb08) -> slot 0x19228 token 0x0600001A PtrToStringChars RVA 0x1384
0000519A  FF 25 88 40 01 00  JMP qword ptr [0x180019228]

; FUNC 000051AA-000051B0 fixup_stub_000051AA pred 0x51A0 (eb08) -> slot 0x19238 token 0x0600001B msclr.interop.details.GetAnsiStringSize RVA 0x13A0
000051AA  FF 25 88 40 01 00  JMP qword ptr [0x180019238]

; FUNC 000051BA-000051C0 fixup_stub_000051BA pred 0x51B0 (eb08) -> slot 0x19248 token 0x0600001C msclr.interop.details.WriteAnsiString RVA 0x13F4
000051BA  FF 25 88 40 01 00  JMP qword ptr [0x180019248]

; FUNC 000051CA-000051D0 fixup_stub_000051CA pred 0x51C0 (eb08) -> slot 0x19258 token 0x0600001D msclr.interop.details.GetUnicodeStringSize RVA 0x1460
000051CA  FF 25 88 40 01 00  JMP qword ptr [0x180019258]

; FUNC 000051DA-000051E0 fixup_stub_000051DA pred 0x51D0 (eb08) -> slot 0x19268 token 0x0600001E msclr.interop.details.WriteUnicodeString RVA 0x14A8
000051DA  FF 25 88 40 01 00  JMP qword ptr [0x180019268]

; FUNC 000051EA-000051F0 fixup_stub_000051EA pred 0x51E0 (eb08) -> slot 0x19278 token 0x06000021 msclr.interop.details.char_buffer<char>.release RVA 0x1658
000051EA  FF 25 88 40 01 00  JMP qword ptr [0x180019278]

; FUNC 000051FA-00005200 fixup_stub_000051FA pred 0x51F0 (eb08) -> slot 0x19288 token 0x06000022 msclr.interop.details.char_buffer<char>.get RVA 0x166C
000051FA  FF 25 88 40 01 00  JMP qword ptr [0x180019288]

; FUNC 0000520A-00005210 fixup_stub_0000520A pred 0x5200 (eb08) -> slot 0x19298 token 0x06000023 msclr.interop.details.char_buffer<char>.{dtor} RVA 0x167C
0000520A  FF 25 88 40 01 00  JMP qword ptr [0x180019298]

; FUNC 0000521A-00005220 fixup_stub_0000521A pred 0x5210 (eb08) -> slot 0x192a8 token 0x06000024 msclr.interop.details.char_buffer<char>.{ctor} RVA 0x1690
0000521A  FF 25 88 40 01 00  JMP qword ptr [0x1800192A8]

; FUNC 0000522A-00005230 fixup_stub_0000522A pred 0x5220 (eb08) -> slot 0x192b8 token 0x06000025 msclr.interop.details.char_buffer<wchar_t>.get RVA 0x16A8
0000522A  FF 25 88 40 01 00  JMP qword ptr [0x1800192B8]

; FUNC 0000523A-00005240 fixup_stub_0000523A pred 0x5230 (eb08) -> slot 0x192c8 token 0x06000026 msclr.interop.details.char_buffer<wchar_t>.{dtor} RVA 0x16B8
0000523A  FF 25 88 40 01 00  JMP qword ptr [0x1800192C8]

; FUNC 0000524A-00005250 fixup_stub_0000524A pred 0x5240 (eb08) -> slot 0x192d8 token 0x06000027 msclr.interop.details.char_buffer<wchar_t>.{ctor} RVA 0x16CC
0000524A  FF 25 88 40 01 00  JMP qword ptr [0x1800192D8]

; FUNC 0000525A-00005260 fixup_stub_0000525A pred 0x5250 (eb08) -> slot 0x192e8 token 0x0600001F msclr.interop.details.InternalAnsiToStringHelper RVA 0x171C
0000525A  FF 25 88 40 01 00  JMP qword ptr [0x1800192E8]

; FUNC 0000526A-00005270 fixup_stub_0000526A pred 0x5260 (eb08) -> slot 0x192f8 token 0x06000029 msclr.interop._Marshal_as_impl<class System::String ^> RVA 0x19BC
0000526A  FF 25 88 40 01 00  JMP qword ptr [0x1800192F8]

; FUNC 0000527A-00005280 fixup_stub_0000527A pred 0x5270 (eb08) -> slot 0x19308 token 0x06000028 msclr.interop.marshal_as<class System::String ^,char *> RVA 0x1A28
0000527A  FF 25 88 40 01 00  JMP qword ptr [0x180019308]

; FUNC 0000528A-00005290 fixup_stub_0000528A pred 0x5280 (eb08) -> slot 0x19318 token 0x06000008 std.bad_array_new_length.{dtor} RVA 0x1BDC
0000528A  FF 25 88 40 01 00  JMP qword ptr [0x180019318]

; FUNC 0000529A-000052A0 fixup_stub_0000529A pred 0x5290 (eb08) -> slot 0x19328 token 0x0600000E std.bad_variant_access.{dtor} RVA 0x1C5C
0000529A  FF 25 88 40 01 00  JMP qword ptr [0x180019328]

; FUNC 000052AA-000052B0 fixup_stub_000052AA pred 0x52A0 (eb08) -> slot 0x19338 token 0x06000012 std.bad_cast.{dtor} RVA 0x1CF0
000052AA  FF 25 88 40 01 00  JMP qword ptr [0x180019338]

; FUNC 000052BA-000052C0 fixup_stub_000052BA pred 0x52B0 (eb08) -> slot 0x19348 token 0x06000018 std.bad_weak_ptr.{dtor} RVA 0x1D70
000052BA  FF 25 88 40 01 00  JMP qword ptr [0x180019348]

; FUNC 000052CA-000052D0 fixup_stub_000052CA pred 0x52C0 (eb08) -> slot 0x19390 token 0x06000051 .cctor RVA 0x3D80
000052CA  FF 25 C0 40 01 00  JMP qword ptr [0x180019390]

; FUNC 000052DA-000052E0 fixup_stub_000052DA pred 0x52D0 (eb08) -> slot 0x193a0 token 0x0600002C <CrtImplementationDetails>.ThrowModuleLoadException RVA 0x32F0
000052DA  FF 25 C0 40 01 00  JMP qword ptr [0x1800193A0]

; FUNC 000052EA-000052F0 fixup_stub_000052EA pred 0x52E0 (eb08) -> slot 0x193b0 token 0x0600002D <CrtImplementationDetails>.ThrowModuleLoadException RVA 0x3304
000052EA  FF 25 C0 40 01 00  JMP qword ptr [0x1800193B0]

; FUNC 000052FA-00005300 fixup_stub_000052FA pred 0x52F0 (eb08) -> slot 0x193c0 token 0x0600002E <CrtImplementationDetails>.RegisterModuleUninitializer RVA 0x3420
000052FA  FF 25 C0 40 01 00  JMP qword ptr [0x1800193C0]

; FUNC 0000530A-00005310 fixup_stub_0000530A pred 0x5300 (eb08) -> slot 0x193d0 token 0x0600002F <CrtImplementationDetails>.FromGUID RVA 0x3438
0000530A  FF 25 C0 40 01 00  JMP qword ptr [0x1800193D0]

; FUNC 0000531A-00005320 fixup_stub_0000531A pred 0x5310 (eb08) -> slot 0x193e0 token 0x06000030 __get_default_appdomain RVA 0x3488
0000531A  FF 25 C0 40 01 00  JMP qword ptr [0x1800193E0]

; FUNC 0000532A-00005330 fixup_stub_0000532A pred 0x5320 (eb08) -> slot 0x193f0 token 0x06000031 __release_appdomain RVA 0x3508
0000532A  FF 25 C0 40 01 00  JMP qword ptr [0x1800193F0]

; FUNC 0000533A-00005340 fixup_stub_0000533A pred 0x5330 (eb08) -> slot 0x19400 token 0x06000032 <CrtImplementationDetails>.GetDefaultDomain RVA 0x3524
0000533A  FF 25 C0 40 01 00  JMP qword ptr [0x180019400]

; FUNC 0000534A-00005350 fixup_stub_0000534A pred 0x5340 (eb08) -> slot 0x19410 token 0x06000033 <CrtImplementationDetails>.DoCallBackInDefaultDomain RVA 0x3584
0000534A  FF 25 C0 40 01 00  JMP qword ptr [0x180019410]

; FUNC 0000535A-00005360 fixup_stub_0000535A pred 0x5350 (eb08) -> slot 0x19420 token 0x06000034 __scrt_is_safe_for_managed_code RVA 0x363C
0000535A  FF 25 C0 40 01 00  JMP qword ptr [0x180019420]

; FUNC 0000536A-00005370 fixup_stub_0000536A pred 0x5360 (eb08) -> slot 0x19430 token 0x06000035 <CrtImplementationDetails>.DefaultDomain.DoNothing RVA 0x3670
0000536A  FF 25 C0 40 01 00  JMP qword ptr [0x180019430]

; FUNC 0000537A-00005380 fixup_stub_0000537A pred 0x5370 (eb08) -> slot 0x19440 token 0x06000036 <CrtImplementationDetails>.DefaultDomain.HasPerProcess RVA 0x3690
0000537A  FF 25 C0 40 01 00  JMP qword ptr [0x180019440]

; FUNC 0000538A-00005390 fixup_stub_0000538A pred 0x5380 (eb08) -> slot 0x19450 token 0x06000037 <CrtImplementationDetails>.DefaultDomain.HasNative RVA 0x36E4
0000538A  FF 25 C0 40 01 00  JMP qword ptr [0x180019450]

; FUNC 0000539A-000053A0 fixup_stub_0000539A pred 0x5390 (eb08) -> slot 0x19460 token 0x06000038 <CrtImplementationDetails>.DefaultDomain.NeedsInitialization RVA 0x3764
0000539A  FF 25 C0 40 01 00  JMP qword ptr [0x180019460]

; FUNC 000053AA-000053B0 fixup_stub_000053AA pred 0x53A0 (eb08) -> slot 0x19470 token 0x06000039 <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization RVA 0x379C
000053AA  FF 25 C0 40 01 00  JMP qword ptr [0x180019470]

; FUNC 000053BA-000053C0 fixup_stub_000053BA pred 0x53B0 (eb08) -> slot 0x19480 token 0x0600003A <CrtImplementationDetails>.DefaultDomain.Initialize RVA 0x37B0
000053BA  FF 25 C0 40 01 00  JMP qword ptr [0x180019480]

; FUNC 000053CA-000053D0 fixup_stub_000053CA pred 0x53C0 (eb08) -> slot 0x19490 token 0x06000049 <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain RVA 0x37CC
000053CA  FF 25 C0 40 01 00  JMP qword ptr [0x180019490]

; FUNC 000053DA-000053E0 fixup_stub_000053DA pred 0x53D0 (eb08) -> slot 0x194a0 token 0x0600004A <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain RVA 0x37E0
000053DA  FF 25 C0 40 01 00  JMP qword ptr [0x1800194A0]

; FUNC 000053EA-000053F0 fixup_stub_000053EA pred 0x53E0 (eb08) -> slot 0x194b0 token 0x0600004B <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain RVA 0x3818
000053EA  FF 25 C0 40 01 00  JMP qword ptr [0x1800194B0]

; FUNC 000053FA-00005400 fixup_stub_000053FA pred 0x53F0 (eb08) -> slot 0x194c0 token 0x0600004C <CrtImplementationDetails>.LanguageSupport.DomainUnload RVA 0x3850
000053FA  FF 25 C0 40 01 00  JMP qword ptr [0x1800194C0]

; FUNC 0000540A-00005410 fixup_stub_0000540A pred 0x5400 (eb08) -> slot 0x194d0 token 0x06000052 gcroot<System::String ^>..PE$AAVString@System@@ RVA 0x388C
0000540A  FF 25 C0 40 01 00  JMP qword ptr [0x1800194D0]

; FUNC 0000541A-00005420 fixup_stub_0000541A pred 0x5410 (eb08) -> slot 0x194e0 token 0x06000053 gcroot<System::String ^>.= RVA 0x38B0
0000541A  FF 25 C0 40 01 00  JMP qword ptr [0x1800194E0]

; FUNC 0000542A-00005430 fixup_stub_0000542A pred 0x5420 (eb08) -> slot 0x194f0 token 0x06000054 gcroot<System::String ^>.{dtor} RVA 0x38D8
0000542A  FF 25 C0 40 01 00  JMP qword ptr [0x1800194F0]

; FUNC 0000543A-00005440 fixup_stub_0000543A pred 0x5430 (eb08) -> slot 0x19500 token 0x06000055 gcroot<System::String ^>.{ctor} RVA 0x3900
0000543A  FF 25 C0 40 01 00  JMP qword ptr [0x180019500]

; FUNC 0000544A-00005450 fixup_stub_0000544A pred 0x5440 (eb08) -> slot 0x19510 token 0x0600002B <CrtImplementationDetails>.ThrowNestedModuleLoadException RVA 0x3940
0000544A  FF 25 C0 40 01 00  JMP qword ptr [0x180019510]

; FUNC 0000545A-00005460 fixup_stub_0000545A pred 0x5450 (eb08) -> slot 0x19520 token 0x06000042 <CrtImplementationDetails>.LanguageSupport.InitializeVtables RVA 0x3994
0000545A  FF 25 C0 40 01 00  JMP qword ptr [0x180019520]

; FUNC 0000546A-00005470 fixup_stub_0000546A pred 0x5460 (eb08) -> slot 0x19530 token 0x06000043 <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain RVA 0x39C8
0000546A  FF 25 C0 40 01 00  JMP qword ptr [0x180019530]

; FUNC 0000547A-00005480 fixup_stub_0000547A pred 0x5470 (eb08) -> slot 0x19540 token 0x06000044 <CrtImplementationDetails>.LanguageSupport.InitializeNative RVA 0x39E8
0000547A  FF 25 C0 40 01 00  JMP qword ptr [0x180019540]

; FUNC 0000548A-00005490 fixup_stub_0000548A pred 0x5480 (eb08) -> slot 0x19550 token 0x06000045 <CrtImplementationDetails>.LanguageSupport.InitializePerProcess RVA 0x3A78
0000548A  FF 25 C0 40 01 00  JMP qword ptr [0x180019550]

; FUNC 0000549A-000054A0 fixup_stub_0000549A pred 0x5490 (eb08) -> slot 0x19560 token 0x06000046 <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain RVA 0x3AB8
0000549A  FF 25 C0 40 01 00  JMP qword ptr [0x180019560]

; FUNC 000054AA-000054B0 fixup_stub_000054AA pred 0x54A0 (eb08) -> slot 0x19570 token 0x06000047 <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer RVA 0x3AF4
000054AA  FF 25 C0 40 01 00  JMP qword ptr [0x180019570]

; FUNC 000054BA-000054C0 fixup_stub_000054BA pred 0x54B0 (eb08) -> slot 0x19580 token 0x06000048 <CrtImplementationDetails>.LanguageSupport._Initialize RVA 0x3B20
000054BA  FF 25 C0 40 01 00  JMP qword ptr [0x180019580]

; FUNC 000054CA-000054D0 fixup_stub_000054CA pred 0x54C0 (eb08) -> slot 0x19590 token 0x0600004D <CrtImplementationDetails>.LanguageSupport.Cleanup RVA 0x3C24
000054CA  FF 25 C0 40 01 00  JMP qword ptr [0x180019590]

; FUNC 000054DA-000054E0 fixup_stub_000054DA pred 0x54D0 (eb08) -> slot 0x195a0 token 0x0600004E <CrtImplementationDetails>.LanguageSupport.{ctor} RVA 0x3C98
000054DA  FF 25 C0 40 01 00  JMP qword ptr [0x1800195A0]

; FUNC 000054EA-000054F0 fixup_stub_000054EA pred 0x54E0 (eb08) -> slot 0x195b0 token 0x0600004F <CrtImplementationDetails>.LanguageSupport.{dtor} RVA 0x3CB0
000054EA  FF 25 C0 40 01 00  JMP qword ptr [0x1800195B0]

; FUNC 000054FA-00005500 fixup_stub_000054FA pred 0x54F0 (eb08) -> slot 0x195c0 token 0x06000050 <CrtImplementationDetails>.LanguageSupport.Initialize RVA 0x3CC4
000054FA  FF 25 C0 40 01 00  JMP qword ptr [0x1800195C0]

; FUNC 0000557A-00005580 fixup_stub_0000557A pred 0x5570 (eb08) -> slot 0x19608 token 0x06000056 ___CxxCallUnwindDtor RVA 0x3E08
0000557A  FF 25 88 40 01 00  JMP qword ptr [0x180019608]

; FUNC 0000558A-00005590 fixup_stub_0000558A pred 0x5580 (eb08) -> slot 0x19618 token 0x06000057 ___CxxCallUnwindDelDtor RVA 0x3E4C
0000558A  FF 25 88 40 01 00  JMP qword ptr [0x180019618]

; FUNC 0000559A-000055A0 fixup_stub_0000559A pred 0x5590 (eb08) -> slot 0x19628 token 0x06000058 ___CxxCallUnwindVecDtor RVA 0x3E90
0000559A  FF 25 88 40 01 00  JMP qword ptr [0x180019628]

; FUNC 000055AA-000055B0 fixup_stub_000055AA pred 0x55A0 (eb08) -> slot 0x19638 token 0x0600005B __ArrayUnwind RVA 0x3F24
000055AA  FF 25 88 40 01 00  JMP qword ptr [0x180019638]

; FUNC 000055BA-000055C0 fixup_stub_000055BA pred 0x55B0 (eb08) -> slot 0x19648 token 0x06000059 __ehvec_dtor RVA 0x3F7C
000055BA  FF 25 88 40 01 00  JMP qword ptr [0x180019648]

; FUNC 000055CA-000055D0 fixup_stub_000055CA pred 0x55C0 (eb08) -> slot 0x19658 token 0x0600005C __ehvec_dtor RVA 0x3FDC
000055CA  FF 25 88 40 01 00  JMP qword ptr [0x180019658]

; FUNC 000055DA-000055E0 fixup_stub_000055DA pred 0x55D0 (eb08) -> slot 0x19668 token 0x0600005A ?A0x9c83a709.ArrayUnwindFilter RVA 0x3EEC
000055DA  FF 25 88 40 01 00  JMP qword ptr [0x180019668]

; FUNC 000055EA-000055F0 fixup_stub_000055EA pred 0x55E0 (eb08) -> slot 0x19678 token 0x0600006B _atexit_helper RVA 0x419C
000055EA  FF 25 88 40 01 00  JMP qword ptr [0x180019678]

; FUNC 000055FA-00005600 fixup_stub_000055FA pred 0x55F0 (eb08) -> slot 0x19688 token 0x0600006C _exit_callback RVA 0x4314
000055FA  FF 25 88 40 01 00  JMP qword ptr [0x180019688]

; FUNC 0000560A-00005610 fixup_stub_0000560A pred 0x5600 (eb08) -> slot 0x19698 token 0x0600006F _atexit_m RVA 0x43C4
0000560A  FF 25 88 40 01 00  JMP qword ptr [0x180019698]

; FUNC 0000561A-00005620 fixup_stub_0000561A pred 0x5610 (eb08) -> slot 0x196a8 token 0x06000071 _app_exit_callback RVA 0x43EC
0000561A  FF 25 88 40 01 00  JMP qword ptr [0x1800196A8]

; FUNC 0000562A-00005630 fixup_stub_0000562A pred 0x5620 (eb08) -> slot 0x196b8 token 0x06000073 _atexit_m_appdomain RVA 0x44D8
0000562A  FF 25 88 40 01 00  JMP qword ptr [0x1800196B8]

; FUNC 0000563A-00005640 fixup_stub_0000563A pred 0x5630 (eb08) -> slot 0x196c8 token 0x0600006D _initatexit_m RVA 0x4564
0000563A  FF 25 88 40 01 00  JMP qword ptr [0x1800196C8]

; FUNC 0000564A-00005650 fixup_stub_0000564A pred 0x5640 (eb08) -> slot 0x196d8 token 0x0600006E _onexit_m RVA 0x45AC
0000564A  FF 25 88 40 01 00  JMP qword ptr [0x1800196D8]

; FUNC 0000565A-00005660 fixup_stub_0000565A pred 0x5650 (eb08) -> slot 0x196e8 token 0x06000070 _initatexit_app_domain RVA 0x45C8
0000565A  FF 25 88 40 01 00  JMP qword ptr [0x1800196E8]

; FUNC 0000566A-00005670 fixup_stub_0000566A pred 0x5660 (eb08) -> slot 0x196f8 token 0x06000072 _onexit_m_appdomain RVA 0x460C
0000566A  FF 25 88 40 01 00  JMP qword ptr [0x1800196F8]

; FUNC 0000567A-00005680 fixup_stub_0000567A pred 0x5670 (eb08) -> slot 0x19708 token 0x0600005D <CrtImplementationDetails>.AtExitLock._handle RVA 0x4008
0000567A  FF 25 88 40 01 00  JMP qword ptr [0x180019708]

; FUNC 0000568A-00005690 fixup_stub_0000568A pred 0x5680 (eb08) -> slot 0x19718 token 0x0600005F <CrtImplementationDetails>.AtExitLock._lock_Set RVA 0x4038
0000568A  FF 25 88 40 01 00  JMP qword ptr [0x180019718]

; FUNC 0000569A-000056A0 fixup_stub_0000569A pred 0x5690 (eb08) -> slot 0x19728 token 0x06000060 <CrtImplementationDetails>.AtExitLock._lock_Get RVA 0x4088
0000569A  FF 25 88 40 01 00  JMP qword ptr [0x180019728]

; FUNC 000056AA-000056B0 fixup_stub_000056AA pred 0x56A0 (eb08) -> slot 0x19738 token 0x06000061 <CrtImplementationDetails>.AtExitLock._lock_Destruct RVA 0x40AC
000056AA  FF 25 88 40 01 00  JMP qword ptr [0x180019738]

; FUNC 000056BA-000056C0 fixup_stub_000056BA pred 0x56B0 (eb08) -> slot 0x19748 token 0x06000062 <CrtImplementationDetails>.AtExitLock.IsInitialized RVA 0x40D4
000056BA  FF 25 88 40 01 00  JMP qword ptr [0x180019748]

; FUNC 000056CA-000056D0 fixup_stub_000056CA pred 0x56C0 (eb08) -> slot 0x19758 token 0x06000064 <CrtImplementationDetails>.AtExitLock.RemoveRef RVA 0x40F0
000056CA  FF 25 88 40 01 00  JMP qword ptr [0x180019758]

; FUNC 000056DA-000056E0 fixup_stub_000056DA pred 0x56D0 (eb08) -> slot 0x19768 token 0x06000065 <CrtImplementationDetails>.AtExitLock.Enter RVA 0x4118
000056DA  FF 25 88 40 01 00  JMP qword ptr [0x180019768]

; FUNC 000056EA-000056F0 fixup_stub_000056EA pred 0x56E0 (eb08) -> slot 0x19778 token 0x06000066 <CrtImplementationDetails>.AtExitLock.Exit RVA 0x4130
000056EA  FF 25 88 40 01 00  JMP qword ptr [0x180019778]

; FUNC 000056FA-00005700 fixup_stub_000056FA pred 0x56F0 (eb08) -> slot 0x19788 token 0x06000067 ?A0xdf32f105.__global_lock RVA 0x4148
000056FA  FF 25 88 40 01 00  JMP qword ptr [0x180019788]

; FUNC 0000570A-00005710 fixup_stub_0000570A pred 0x5700 (eb08) -> slot 0x19798 token 0x06000068 ?A0xdf32f105.__global_unlock RVA 0x4168
0000570A  FF 25 88 40 01 00  JMP qword ptr [0x180019798]

; FUNC 0000571A-00005720 fixup_stub_0000571A pred 0x5710 (eb08) -> slot 0x197a8 token 0x0600006A ?A0xdf32f105.__dealloc_global_lock RVA 0x4188
0000571A  FF 25 88 40 01 00  JMP qword ptr [0x1800197A8]

; FUNC 0000572A-00005730 fixup_stub_0000572A pred 0x5720 (eb08) -> slot 0x197b8 token 0x0600005E <CrtImplementationDetails>.AtExitLock._lock_Construct RVA 0x4500
0000572A  FF 25 88 40 01 00  JMP qword ptr [0x1800197B8]

; FUNC 0000573A-00005740 fixup_stub_0000573A pred 0x5730 (eb08) -> slot 0x197c8 token 0x06000063 <CrtImplementationDetails>.AtExitLock.AddRef RVA 0x451C
0000573A  FF 25 88 40 01 00  JMP qword ptr [0x1800197C8]

; FUNC 0000574A-00005750 fixup_stub_0000574A pred 0x5740 (eb08) -> slot 0x197d8 token 0x06000069 ?A0xdf32f105.__alloc_global_lock RVA 0x454C
0000574A  FF 25 88 40 01 00  JMP qword ptr [0x1800197D8]

; FUNC 0000575A-00005760 fixup_stub_0000575A pred 0x5750 (eb08) -> slot 0x197e8 token 0x06000076 _initterm_e RVA 0x463C
0000575A  FF 25 88 40 01 00  JMP qword ptr [0x1800197E8]

; FUNC 0000576A-00005770 fixup_stub_0000576A pred 0x5760 (eb08) -> slot 0x197f8 token 0x06000077 _initterm RVA 0x466C
0000576A  FF 25 88 40 01 00  JMP qword ptr [0x1800197F8]

; FUNC 0000577A-00005780 fixup_stub_0000577A pred 0x5770 (eb08) -> slot 0x19808 token 0x06000079 _initterm_m RVA 0x46E4
0000577A  FF 25 88 40 01 00  JMP qword ptr [0x180019808]

; FUNC 0000578A-00005790 fixup_stub_0000578A pred 0x5780 (eb08) -> slot 0x19818 token 0x06000078 <CrtImplementationDetails>.ThisModule.Handle RVA 0x4694
0000578A  FF 25 88 40 01 00  JMP qword ptr [0x180019818]

; FUNC 0000579A-000057A0 fixup_stub_0000579A pred 0x5790 (eb08) -> slot 0x19828 token 0x0600007A <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)> RVA 0x46B8
0000579A  FF 25 88 40 01 00  JMP qword ptr [0x180019828]
