; NATIVE-340 .nep CLR VTableFixups dispatch stubs (native -> managed edges)
; one line per upstream fixup-target row; bytes read from the pinned original

; FUNC 00005004-0000500A fixup_stub_00005004 -> slot 0x19018 token 0x06000001 std.exception.{ctor} RVA 0x10a0
00005004  FF 25 0E 40 01 00  JMP qword ptr [0x180019018]

; FUNC 00005014-0000501A fixup_stub_00005014 -> slot 0x19028 token 0x0600000A std.exception_ptr.{ctor} RVA 0x1120
00005014  FF 25 0E 40 01 00  JMP qword ptr [0x180019028]

; FUNC 00005024-0000502A fixup_stub_00005024 -> slot 0x19050 token 0x0600000C std.bad_alloc.{ctor} RVA 0x1138
00005024  FF 25 26 40 01 00  JMP qword ptr [0x180019050]

; FUNC 00005034-0000503A fixup_stub_00005034 -> slot 0x19078 token 0x0600000B std.bad_array_new_length.{ctor} RVA 0x1198
00005034  FF 25 3E 40 01 00  JMP qword ptr [0x180019078]

; FUNC 00005044-0000504A fixup_stub_00005044 -> slot 0x19088 token 0x060000A3 <MarshalCopy> RVA 0x1224
00005044  FF 25 3E 40 01 00  JMP qword ptr [0x180019088]

; FUNC 00005054-0000505A fixup_stub_00005054 -> slot 0x19098 token 0x060000A4 <MarshalDestroy> RVA 0x123c
00005054  FF 25 3E 40 01 00  JMP qword ptr [0x180019098]

; FUNC 00005064-0000506A fixup_stub_00005064 -> slot 0x190c0 token 0x0600000F std.bad_variant_access.{ctor} RVA 0x1250
00005064  FF 25 56 40 01 00  JMP qword ptr [0x1800190C0]

; FUNC 00005074-0000507A fixup_stub_00005074 -> slot 0x190e8 token 0x06000013 std.bad_cast.{ctor} RVA 0x12b0
00005074  FF 25 6E 40 01 00  JMP qword ptr [0x1800190E8]

; FUNC 00005084-0000508A fixup_stub_00005084 -> slot 0x19110 token 0x06000019 std.bad_weak_ptr.{ctor} RVA 0x1324
00005084  FF 25 86 40 01 00  JMP qword ptr [0x180019110]

; FUNC 00005094-0000509A fixup_stub_00005094 -> slot 0x19120 token 0x06000014 std._Iterator_base12.{ctor} RVA 0x1700
00005094  FF 25 86 40 01 00  JMP qword ptr [0x180019120]

; FUNC 000050A4-000050AA fixup_stub_000050a4 -> slot 0x19130 token 0x06000020 SaveMergennFiles RVA 0x1a80
000050A4  FF 25 86 40 01 00  JMP qword ptr [0x180019130]

; FUNC 000050B4-000050BA fixup_stub_000050b4 -> slot 0x19140 token 0x0600002A new RVA 0x1090
000050B4  FF 25 86 40 01 00  JMP qword ptr [0x180019140]

; FUNC 000050C4-000050CA fixup_stub_000050c4 -> slot 0x19150 token 0x06000004 std.exception.__vecDelDtor RVA 0x1a9c
000050C4  FF 25 86 40 01 00  JMP qword ptr [0x180019150]

; FUNC 000050D4-000050DA fixup_stub_000050d4 -> slot 0x19160 token 0x06000003 std.exception.what RVA 0x1afc
000050D4  FF 25 86 40 01 00  JMP qword ptr [0x180019160]

; FUNC 000050E4-000050EA fixup_stub_000050e4 -> slot 0x19170 token 0x06000002 std.exception.{dtor} RVA 0x10cc
000050E4  FF 25 86 40 01 00  JMP qword ptr [0x180019170]

; FUNC 000050F4-000050FA fixup_stub_000050f4 -> slot 0x19180 token 0x06000006 std.bad_alloc.{dtor} RVA 0x10ec
000050F4  FF 25 86 40 01 00  JMP qword ptr [0x180019180]

; FUNC 00005104-0000510A fixup_stub_00005104 -> slot 0x19190 token 0x06000009 std.exception_ptr.{dtor} RVA 0x110c
00005104  FF 25 86 40 01 00  JMP qword ptr [0x180019190]

; FUNC 00005114-0000511A fixup_stub_00005114 -> slot 0x191a0 token 0x06000005 std.bad_alloc.__vecDelDtor RVA 0x1b1c
00005114  FF 25 86 40 01 00  JMP qword ptr [0x1800191A0]

; FUNC 00005124-0000512A fixup_stub_00005124 -> slot 0x191b0 token 0x06000007 std.bad_array_new_length.__vecDelDtor RVA 0x1b7c
00005124  FF 25 86 40 01 00  JMP qword ptr [0x1800191B0]

; FUNC 00005134-0000513A fixup_stub_00005134 -> slot 0x191c0 token 0x06000010 std.bad_variant_access.__vecDelDtor RVA 0x1bfc
00005134  FF 25 86 40 01 00  JMP qword ptr [0x1800191C0]

; FUNC 00005144-0000514A fixup_stub_00005144 -> slot 0x191d0 token 0x0600000D std.bad_variant_access.what RVA 0x1c7c
00005144  FF 25 86 40 01 00  JMP qword ptr [0x1800191D0]

; FUNC 00005154-0000515A fixup_stub_00005154 -> slot 0x191e0 token 0x06000011 std.bad_cast.__vecDelDtor RVA 0x1c90
00005154  FF 25 86 40 01 00  JMP qword ptr [0x1800191E0]

; FUNC 00005164-0000516A fixup_stub_00005164 -> slot 0x191f0 token 0x06000015 std._Iterator_base12.= RVA 0x1310
00005164  FF 25 86 40 01 00  JMP qword ptr [0x1800191F0]

; FUNC 00005174-0000517A fixup_stub_00005174 -> slot 0x19200 token 0x06000017 std.bad_weak_ptr.__vecDelDtor RVA 0x1d10
00005174  FF 25 86 40 01 00  JMP qword ptr [0x180019200]

; FUNC 00005184-0000518A fixup_stub_00005184 -> slot 0x19210 token 0x06000016 std.bad_weak_ptr.what RVA 0x1d90
00005184  FF 25 86 40 01 00  JMP qword ptr [0x180019210]

; FUNC 00005194-0000519A fixup_stub_00005194 -> slot 0x19220 token 0x0600001A PtrToStringChars RVA 0x1384
00005194  FF 25 86 40 01 00  JMP qword ptr [0x180019220]

; FUNC 000051A4-000051AA fixup_stub_000051a4 -> slot 0x19230 token 0x0600001B msclr.interop.details.GetAnsiStringSize RVA 0x13a0
000051A4  FF 25 86 40 01 00  JMP qword ptr [0x180019230]

; FUNC 000051B4-000051BA fixup_stub_000051b4 -> slot 0x19240 token 0x0600001C msclr.interop.details.WriteAnsiString RVA 0x13f4
000051B4  FF 25 86 40 01 00  JMP qword ptr [0x180019240]

; FUNC 000051C4-000051CA fixup_stub_000051c4 -> slot 0x19250 token 0x0600001D msclr.interop.details.GetUnicodeStringSize RVA 0x1460
000051C4  FF 25 86 40 01 00  JMP qword ptr [0x180019250]

; FUNC 000051D4-000051DA fixup_stub_000051d4 -> slot 0x19260 token 0x0600001E msclr.interop.details.WriteUnicodeString RVA 0x14a8
000051D4  FF 25 86 40 01 00  JMP qword ptr [0x180019260]

; FUNC 000051E4-000051EA fixup_stub_000051e4 -> slot 0x19270 token 0x06000021 msclr.interop.details.char_buffer<char>.release RVA 0x1658
000051E4  FF 25 86 40 01 00  JMP qword ptr [0x180019270]

; FUNC 000051F4-000051FA fixup_stub_000051f4 -> slot 0x19280 token 0x06000022 msclr.interop.details.char_buffer<char>.get RVA 0x166c
000051F4  FF 25 86 40 01 00  JMP qword ptr [0x180019280]

; FUNC 00005204-0000520A fixup_stub_00005204 -> slot 0x19290 token 0x06000023 msclr.interop.details.char_buffer<char>.{dtor} RVA 0x167c
00005204  FF 25 86 40 01 00  JMP qword ptr [0x180019290]

; FUNC 00005214-0000521A fixup_stub_00005214 -> slot 0x192a0 token 0x06000024 msclr.interop.details.char_buffer<char>.{ctor} RVA 0x1690
00005214  FF 25 86 40 01 00  JMP qword ptr [0x1800192A0]

; FUNC 00005224-0000522A fixup_stub_00005224 -> slot 0x192b0 token 0x06000025 msclr.interop.details.char_buffer<wchar_t>.get RVA 0x16a8
00005224  FF 25 86 40 01 00  JMP qword ptr [0x1800192B0]

; FUNC 00005234-0000523A fixup_stub_00005234 -> slot 0x192c0 token 0x06000026 msclr.interop.details.char_buffer<wchar_t>.{dtor} RVA 0x16b8
00005234  FF 25 86 40 01 00  JMP qword ptr [0x1800192C0]

; FUNC 00005244-0000524A fixup_stub_00005244 -> slot 0x192d0 token 0x06000027 msclr.interop.details.char_buffer<wchar_t>.{ctor} RVA 0x16cc
00005244  FF 25 86 40 01 00  JMP qword ptr [0x1800192D0]

; FUNC 00005254-0000525A fixup_stub_00005254 -> slot 0x192e0 token 0x0600001F msclr.interop.details.InternalAnsiToStringHelper RVA 0x171c
00005254  FF 25 86 40 01 00  JMP qword ptr [0x1800192E0]

; FUNC 00005264-0000526A fixup_stub_00005264 -> slot 0x192f0 token 0x06000029 msclr.interop._Marshal_as_impl<class System::String ^> RVA 0x19bc
00005264  FF 25 86 40 01 00  JMP qword ptr [0x1800192F0]

; FUNC 00005274-0000527A fixup_stub_00005274 -> slot 0x19300 token 0x06000028 msclr.interop.marshal_as<class System::String ^,char *> RVA 0x1a28
00005274  FF 25 86 40 01 00  JMP qword ptr [0x180019300]

; FUNC 00005284-0000528A fixup_stub_00005284 -> slot 0x19310 token 0x06000008 std.bad_array_new_length.{dtor} RVA 0x1bdc
00005284  FF 25 86 40 01 00  JMP qword ptr [0x180019310]

; FUNC 00005294-0000529A fixup_stub_00005294 -> slot 0x19320 token 0x0600000E std.bad_variant_access.{dtor} RVA 0x1c5c
00005294  FF 25 86 40 01 00  JMP qword ptr [0x180019320]

; FUNC 000052A4-000052AA fixup_stub_000052a4 -> slot 0x19330 token 0x06000012 std.bad_cast.{dtor} RVA 0x1cf0
000052A4  FF 25 86 40 01 00  JMP qword ptr [0x180019330]

; FUNC 000052B4-000052BA fixup_stub_000052b4 -> slot 0x19340 token 0x06000018 std.bad_weak_ptr.{dtor} RVA 0x1d70
000052B4  FF 25 86 40 01 00  JMP qword ptr [0x180019340]

; FUNC 000052C4-000052CA fixup_stub_000052c4 -> slot 0x19388 token 0x06000051 .cctor RVA 0x3d80
000052C4  FF 25 BE 40 01 00  JMP qword ptr [0x180019388]

; FUNC 000052D4-000052DA fixup_stub_000052d4 -> slot 0x19398 token 0x0600002C <CrtImplementationDetails>.ThrowModuleLoadException RVA 0x32f0
000052D4  FF 25 BE 40 01 00  JMP qword ptr [0x180019398]

; FUNC 000052E4-000052EA fixup_stub_000052e4 -> slot 0x193a8 token 0x0600002D <CrtImplementationDetails>.ThrowModuleLoadException RVA 0x3304
000052E4  FF 25 BE 40 01 00  JMP qword ptr [0x1800193A8]

; FUNC 000052F4-000052FA fixup_stub_000052f4 -> slot 0x193b8 token 0x0600002E <CrtImplementationDetails>.RegisterModuleUninitializer RVA 0x3420
000052F4  FF 25 BE 40 01 00  JMP qword ptr [0x1800193B8]

; FUNC 00005304-0000530A fixup_stub_00005304 -> slot 0x193c8 token 0x0600002F <CrtImplementationDetails>.FromGUID RVA 0x3438
00005304  FF 25 BE 40 01 00  JMP qword ptr [0x1800193C8]

; FUNC 00005314-0000531A fixup_stub_00005314 -> slot 0x193d8 token 0x06000030 __get_default_appdomain RVA 0x3488
00005314  FF 25 BE 40 01 00  JMP qword ptr [0x1800193D8]

; FUNC 00005324-0000532A fixup_stub_00005324 -> slot 0x193e8 token 0x06000031 __release_appdomain RVA 0x3508
00005324  FF 25 BE 40 01 00  JMP qword ptr [0x1800193E8]

; FUNC 00005334-0000533A fixup_stub_00005334 -> slot 0x193f8 token 0x06000032 <CrtImplementationDetails>.GetDefaultDomain RVA 0x3524
00005334  FF 25 BE 40 01 00  JMP qword ptr [0x1800193F8]

; FUNC 00005344-0000534A fixup_stub_00005344 -> slot 0x19408 token 0x06000033 <CrtImplementationDetails>.DoCallBackInDefaultDomain RVA 0x3584
00005344  FF 25 BE 40 01 00  JMP qword ptr [0x180019408]

; FUNC 00005354-0000535A fixup_stub_00005354 -> slot 0x19418 token 0x06000034 __scrt_is_safe_for_managed_code RVA 0x363c
00005354  FF 25 BE 40 01 00  JMP qword ptr [0x180019418]

; FUNC 00005364-0000536A fixup_stub_00005364 -> slot 0x19428 token 0x06000035 <CrtImplementationDetails>.DefaultDomain.DoNothing RVA 0x3670
00005364  FF 25 BE 40 01 00  JMP qword ptr [0x180019428]

; FUNC 00005374-0000537A fixup_stub_00005374 -> slot 0x19438 token 0x06000036 <CrtImplementationDetails>.DefaultDomain.HasPerProcess RVA 0x3690
00005374  FF 25 BE 40 01 00  JMP qword ptr [0x180019438]

; FUNC 00005384-0000538A fixup_stub_00005384 -> slot 0x19448 token 0x06000037 <CrtImplementationDetails>.DefaultDomain.HasNative RVA 0x36e4
00005384  FF 25 BE 40 01 00  JMP qword ptr [0x180019448]

; FUNC 00005394-0000539A fixup_stub_00005394 -> slot 0x19458 token 0x06000038 <CrtImplementationDetails>.DefaultDomain.NeedsInitialization RVA 0x3764
00005394  FF 25 BE 40 01 00  JMP qword ptr [0x180019458]

; FUNC 000053A4-000053AA fixup_stub_000053a4 -> slot 0x19468 token 0x06000039 <CrtImplementationDetails>.DefaultDomain.NeedsUninitialization RVA 0x379c
000053A4  FF 25 BE 40 01 00  JMP qword ptr [0x180019468]

; FUNC 000053B4-000053BA fixup_stub_000053b4 -> slot 0x19478 token 0x0600003A <CrtImplementationDetails>.DefaultDomain.Initialize RVA 0x37b0
000053B4  FF 25 BE 40 01 00  JMP qword ptr [0x180019478]

; FUNC 000053C4-000053CA fixup_stub_000053c4 -> slot 0x19488 token 0x06000049 <CrtImplementationDetails>.LanguageSupport.UninitializeAppDomain RVA 0x37cc
000053C4  FF 25 BE 40 01 00  JMP qword ptr [0x180019488]

; FUNC 000053D4-000053DA fixup_stub_000053d4 -> slot 0x19498 token 0x0600004A <CrtImplementationDetails>.LanguageSupport._UninitializeDefaultDomain RVA 0x37e0
000053D4  FF 25 BE 40 01 00  JMP qword ptr [0x180019498]

; FUNC 000053E4-000053EA fixup_stub_000053e4 -> slot 0x194a8 token 0x0600004B <CrtImplementationDetails>.LanguageSupport.UninitializeDefaultDomain RVA 0x3818
000053E4  FF 25 BE 40 01 00  JMP qword ptr [0x1800194A8]

; FUNC 000053F4-000053FA fixup_stub_000053f4 -> slot 0x194b8 token 0x0600004C <CrtImplementationDetails>.LanguageSupport.DomainUnload RVA 0x3850
000053F4  FF 25 BE 40 01 00  JMP qword ptr [0x1800194B8]

; FUNC 00005404-0000540A fixup_stub_00005404 -> slot 0x194c8 token 0x06000052 gcroot<System::String ^>..PE$AAVString@System@@ RVA 0x388c
00005404  FF 25 BE 40 01 00  JMP qword ptr [0x1800194C8]

; FUNC 00005414-0000541A fixup_stub_00005414 -> slot 0x194d8 token 0x06000053 gcroot<System::String ^>.= RVA 0x38b0
00005414  FF 25 BE 40 01 00  JMP qword ptr [0x1800194D8]

; FUNC 00005424-0000542A fixup_stub_00005424 -> slot 0x194e8 token 0x06000054 gcroot<System::String ^>.{dtor} RVA 0x38d8
00005424  FF 25 BE 40 01 00  JMP qword ptr [0x1800194E8]

; FUNC 00005434-0000543A fixup_stub_00005434 -> slot 0x194f8 token 0x06000055 gcroot<System::String ^>.{ctor} RVA 0x3900
00005434  FF 25 BE 40 01 00  JMP qword ptr [0x1800194F8]

; FUNC 00005444-0000544A fixup_stub_00005444 -> slot 0x19508 token 0x0600002B <CrtImplementationDetails>.ThrowNestedModuleLoadException RVA 0x3940
00005444  FF 25 BE 40 01 00  JMP qword ptr [0x180019508]

; FUNC 00005454-0000545A fixup_stub_00005454 -> slot 0x19518 token 0x06000042 <CrtImplementationDetails>.LanguageSupport.InitializeVtables RVA 0x3994
00005454  FF 25 BE 40 01 00  JMP qword ptr [0x180019518]

; FUNC 00005464-0000546A fixup_stub_00005464 -> slot 0x19528 token 0x06000043 <CrtImplementationDetails>.LanguageSupport.InitializeDefaultAppDomain RVA 0x39c8
00005464  FF 25 BE 40 01 00  JMP qword ptr [0x180019528]

; FUNC 00005474-0000547A fixup_stub_00005474 -> slot 0x19538 token 0x06000044 <CrtImplementationDetails>.LanguageSupport.InitializeNative RVA 0x39e8
00005474  FF 25 BE 40 01 00  JMP qword ptr [0x180019538]

; FUNC 00005484-0000548A fixup_stub_00005484 -> slot 0x19548 token 0x06000045 <CrtImplementationDetails>.LanguageSupport.InitializePerProcess RVA 0x3a78
00005484  FF 25 BE 40 01 00  JMP qword ptr [0x180019548]

; FUNC 00005494-0000549A fixup_stub_00005494 -> slot 0x19558 token 0x06000046 <CrtImplementationDetails>.LanguageSupport.InitializePerAppDomain RVA 0x3ab8
00005494  FF 25 BE 40 01 00  JMP qword ptr [0x180019558]

; FUNC 000054A4-000054AA fixup_stub_000054a4 -> slot 0x19568 token 0x06000047 <CrtImplementationDetails>.LanguageSupport.InitializeUninitializer RVA 0x3af4
000054A4  FF 25 BE 40 01 00  JMP qword ptr [0x180019568]

; FUNC 000054B4-000054BA fixup_stub_000054b4 -> slot 0x19578 token 0x06000048 <CrtImplementationDetails>.LanguageSupport._Initialize RVA 0x3b20
000054B4  FF 25 BE 40 01 00  JMP qword ptr [0x180019578]

; FUNC 000054C4-000054CA fixup_stub_000054c4 -> slot 0x19588 token 0x0600004D <CrtImplementationDetails>.LanguageSupport.Cleanup RVA 0x3c24
000054C4  FF 25 BE 40 01 00  JMP qword ptr [0x180019588]

; FUNC 000054D4-000054DA fixup_stub_000054d4 -> slot 0x19598 token 0x0600004E <CrtImplementationDetails>.LanguageSupport.{ctor} RVA 0x3c98
000054D4  FF 25 BE 40 01 00  JMP qword ptr [0x180019598]

; FUNC 000054E4-000054EA fixup_stub_000054e4 -> slot 0x195a8 token 0x0600004F <CrtImplementationDetails>.LanguageSupport.{dtor} RVA 0x3cb0
000054E4  FF 25 BE 40 01 00  JMP qword ptr [0x1800195A8]

; FUNC 000054F4-000054FA fixup_stub_000054f4 -> slot 0x195b8 token 0x06000050 <CrtImplementationDetails>.LanguageSupport.Initialize RVA 0x3cc4
000054F4  FF 25 BE 40 01 00  JMP qword ptr [0x1800195B8]

; FUNC 00005500-00005506 fixup_stub_00005500 -> slot 0x195c8 token 0x0600003B ?A0xeb4f7d22.??__E?Initialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ RVA 0x1000
00005500  FF 25 C2 40 01 00  JMP qword ptr [0x1800195C8]

; FUNC 00005510-00005516 fixup_stub_00005510 -> slot 0x195d0 token 0x0600003C ?A0xeb4f7d22.??__E?Uninitialized@CurrentDomain@<CrtImplementationDetails>@@$$Q2HA@@YMXXZ RVA 0x1014
00005510  FF 25 BA 40 01 00  JMP qword ptr [0x1800195D0]

; FUNC 00005520-00005526 fixup_stub_00005520 -> slot 0x195d8 token 0x0600003D ?A0xeb4f7d22.??__E?IsDefaultDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2_NA@@YMXXZ RVA 0x1028
00005520  FF 25 B2 40 01 00  JMP qword ptr [0x1800195D8]

; FUNC 00005530-00005536 fixup_stub_00005530 -> slot 0x195e0 token 0x0600003E ?A0xeb4f7d22.??__E?InitializedVtables@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ RVA 0x103c
00005530  FF 25 AA 40 01 00  JMP qword ptr [0x1800195E0]

; FUNC 00005540-00005546 fixup_stub_00005540 -> slot 0x195e8 token 0x0600003F ?A0xeb4f7d22.??__E?InitializedNative@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ RVA 0x1050
00005540  FF 25 A2 40 01 00  JMP qword ptr [0x1800195E8]

; FUNC 00005550-00005556 fixup_stub_00005550 -> slot 0x195f0 token 0x06000040 ?A0xeb4f7d22.??__E?InitializedPerProcess@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ RVA 0x1064
00005550  FF 25 9A 40 01 00  JMP qword ptr [0x1800195F0]

; FUNC 00005560-00005566 fixup_stub_00005560 -> slot 0x195f8 token 0x06000041 ?A0xeb4f7d22.??__E?InitializedPerAppDomain@CurrentDomain@<CrtImplementationDetails>@@$$Q2W4Progress@2@A@@YMXXZ RVA 0x1078
00005560  FF 25 92 40 01 00  JMP qword ptr [0x1800195F8]

; FUNC 00005574-0000557A fixup_stub_00005574 -> slot 0x19600 token 0x06000056 ___CxxCallUnwindDtor RVA 0x3e08
00005574  FF 25 86 40 01 00  JMP qword ptr [0x180019600]

; FUNC 00005584-0000558A fixup_stub_00005584 -> slot 0x19610 token 0x06000057 ___CxxCallUnwindDelDtor RVA 0x3e4c
00005584  FF 25 86 40 01 00  JMP qword ptr [0x180019610]

; FUNC 00005594-0000559A fixup_stub_00005594 -> slot 0x19620 token 0x06000058 ___CxxCallUnwindVecDtor RVA 0x3e90
00005594  FF 25 86 40 01 00  JMP qword ptr [0x180019620]

; FUNC 000055A4-000055AA fixup_stub_000055a4 -> slot 0x19630 token 0x0600005B __ArrayUnwind RVA 0x3f24
000055A4  FF 25 86 40 01 00  JMP qword ptr [0x180019630]

; FUNC 000055B4-000055BA fixup_stub_000055b4 -> slot 0x19640 token 0x06000059 __ehvec_dtor RVA 0x3f7c
000055B4  FF 25 86 40 01 00  JMP qword ptr [0x180019640]

; FUNC 000055C4-000055CA fixup_stub_000055c4 -> slot 0x19650 token 0x0600005C __ehvec_dtor RVA 0x3fdc
000055C4  FF 25 86 40 01 00  JMP qword ptr [0x180019650]

; FUNC 000055D4-000055DA fixup_stub_000055d4 -> slot 0x19660 token 0x0600005A ?A0x9c83a709.ArrayUnwindFilter RVA 0x3eec
000055D4  FF 25 86 40 01 00  JMP qword ptr [0x180019660]

; FUNC 000055E4-000055EA fixup_stub_000055e4 -> slot 0x19670 token 0x0600006B _atexit_helper RVA 0x419c
000055E4  FF 25 86 40 01 00  JMP qword ptr [0x180019670]

; FUNC 000055F4-000055FA fixup_stub_000055f4 -> slot 0x19680 token 0x0600006C _exit_callback RVA 0x4314
000055F4  FF 25 86 40 01 00  JMP qword ptr [0x180019680]

; FUNC 00005604-0000560A fixup_stub_00005604 -> slot 0x19690 token 0x0600006F _atexit_m RVA 0x43c4
00005604  FF 25 86 40 01 00  JMP qword ptr [0x180019690]

; FUNC 00005614-0000561A fixup_stub_00005614 -> slot 0x196a0 token 0x06000071 _app_exit_callback RVA 0x43ec
00005614  FF 25 86 40 01 00  JMP qword ptr [0x1800196A0]

; FUNC 00005624-0000562A fixup_stub_00005624 -> slot 0x196b0 token 0x06000073 _atexit_m_appdomain RVA 0x44d8
00005624  FF 25 86 40 01 00  JMP qword ptr [0x1800196B0]

; FUNC 00005634-0000563A fixup_stub_00005634 -> slot 0x196c0 token 0x0600006D _initatexit_m RVA 0x4564
00005634  FF 25 86 40 01 00  JMP qword ptr [0x1800196C0]

; FUNC 00005644-0000564A fixup_stub_00005644 -> slot 0x196d0 token 0x0600006E _onexit_m RVA 0x45ac
00005644  FF 25 86 40 01 00  JMP qword ptr [0x1800196D0]

; FUNC 00005654-0000565A fixup_stub_00005654 -> slot 0x196e0 token 0x06000070 _initatexit_app_domain RVA 0x45c8
00005654  FF 25 86 40 01 00  JMP qword ptr [0x1800196E0]

; FUNC 00005664-0000566A fixup_stub_00005664 -> slot 0x196f0 token 0x06000072 _onexit_m_appdomain RVA 0x460c
00005664  FF 25 86 40 01 00  JMP qword ptr [0x1800196F0]

; FUNC 00005674-0000567A fixup_stub_00005674 -> slot 0x19700 token 0x0600005D <CrtImplementationDetails>.AtExitLock._handle RVA 0x4008
00005674  FF 25 86 40 01 00  JMP qword ptr [0x180019700]

; FUNC 00005684-0000568A fixup_stub_00005684 -> slot 0x19710 token 0x0600005F <CrtImplementationDetails>.AtExitLock._lock_Set RVA 0x4038
00005684  FF 25 86 40 01 00  JMP qword ptr [0x180019710]

; FUNC 00005694-0000569A fixup_stub_00005694 -> slot 0x19720 token 0x06000060 <CrtImplementationDetails>.AtExitLock._lock_Get RVA 0x4088
00005694  FF 25 86 40 01 00  JMP qword ptr [0x180019720]

; FUNC 000056A4-000056AA fixup_stub_000056a4 -> slot 0x19730 token 0x06000061 <CrtImplementationDetails>.AtExitLock._lock_Destruct RVA 0x40ac
000056A4  FF 25 86 40 01 00  JMP qword ptr [0x180019730]

; FUNC 000056B4-000056BA fixup_stub_000056b4 -> slot 0x19740 token 0x06000062 <CrtImplementationDetails>.AtExitLock.IsInitialized RVA 0x40d4
000056B4  FF 25 86 40 01 00  JMP qword ptr [0x180019740]

; FUNC 000056C4-000056CA fixup_stub_000056c4 -> slot 0x19750 token 0x06000064 <CrtImplementationDetails>.AtExitLock.RemoveRef RVA 0x40f0
000056C4  FF 25 86 40 01 00  JMP qword ptr [0x180019750]

; FUNC 000056D4-000056DA fixup_stub_000056d4 -> slot 0x19760 token 0x06000065 <CrtImplementationDetails>.AtExitLock.Enter RVA 0x4118
000056D4  FF 25 86 40 01 00  JMP qword ptr [0x180019760]

; FUNC 000056E4-000056EA fixup_stub_000056e4 -> slot 0x19770 token 0x06000066 <CrtImplementationDetails>.AtExitLock.Exit RVA 0x4130
000056E4  FF 25 86 40 01 00  JMP qword ptr [0x180019770]

; FUNC 000056F4-000056FA fixup_stub_000056f4 -> slot 0x19780 token 0x06000067 ?A0xdf32f105.__global_lock RVA 0x4148
000056F4  FF 25 86 40 01 00  JMP qword ptr [0x180019780]

; FUNC 00005704-0000570A fixup_stub_00005704 -> slot 0x19790 token 0x06000068 ?A0xdf32f105.__global_unlock RVA 0x4168
00005704  FF 25 86 40 01 00  JMP qword ptr [0x180019790]

; FUNC 00005714-0000571A fixup_stub_00005714 -> slot 0x197a0 token 0x0600006A ?A0xdf32f105.__dealloc_global_lock RVA 0x4188
00005714  FF 25 86 40 01 00  JMP qword ptr [0x1800197A0]

; FUNC 00005724-0000572A fixup_stub_00005724 -> slot 0x197b0 token 0x0600005E <CrtImplementationDetails>.AtExitLock._lock_Construct RVA 0x4500
00005724  FF 25 86 40 01 00  JMP qword ptr [0x1800197B0]

; FUNC 00005734-0000573A fixup_stub_00005734 -> slot 0x197c0 token 0x06000063 <CrtImplementationDetails>.AtExitLock.AddRef RVA 0x451c
00005734  FF 25 86 40 01 00  JMP qword ptr [0x1800197C0]

; FUNC 00005744-0000574A fixup_stub_00005744 -> slot 0x197d0 token 0x06000069 ?A0xdf32f105.__alloc_global_lock RVA 0x454c
00005744  FF 25 86 40 01 00  JMP qword ptr [0x1800197D0]

; FUNC 00005754-0000575A fixup_stub_00005754 -> slot 0x197e0 token 0x06000076 _initterm_e RVA 0x463c
00005754  FF 25 86 40 01 00  JMP qword ptr [0x1800197E0]

; FUNC 00005764-0000576A fixup_stub_00005764 -> slot 0x197f0 token 0x06000077 _initterm RVA 0x466c
00005764  FF 25 86 40 01 00  JMP qword ptr [0x1800197F0]

; FUNC 00005774-0000577A fixup_stub_00005774 -> slot 0x19800 token 0x06000079 _initterm_m RVA 0x46e4
00005774  FF 25 86 40 01 00  JMP qword ptr [0x180019800]

; FUNC 00005784-0000578A fixup_stub_00005784 -> slot 0x19810 token 0x06000078 <CrtImplementationDetails>.ThisModule.Handle RVA 0x4694
00005784  FF 25 86 40 01 00  JMP qword ptr [0x180019810]

; FUNC 00005794-0000579A fixup_stub_00005794 -> slot 0x19820 token 0x0600007A <CrtImplementationDetails>.ThisModule.ResolveMethod<void const * __clrcall(void)> RVA 0x46b8
00005794  FF 25 86 40 01 00  JMP qword ptr [0x180019820]
