.module AspenTech.AspenPlus.Printing.dll
// MVID: {FBDE7299-3412-405E-B41A-7BB111F08C9E}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi abstract sealed beforefieldinit AspenTech.AspenPlus.Printing.GenericPrinting
	extends [mscorlib]System.Object
{
	// Nested Types
	.class /* 02000008 */ nested private auto ansi sealed serializable beforefieldinit '<>c'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000012 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 04000009 */ public static initonly class AspenTech.AspenPlus.Printing.GenericPrinting/'<>c' '<>9'
		.field /* 0400000A */ public static class [PresentationCore]System.Windows.RoutedEventHandler '<>9__2_0'

		// Methods
		.method /* 0600001E */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x2bab
			// Header size: 1
			// Code size: 11 (0xb)
			.maxstack 8

			/* 0x00002BAB 731F000006         */ IL_0000: newobj instance void AspenTech.AspenPlus.Printing.GenericPrinting/'<>c'::.ctor() /* 0600001F */
			/* 0x00002BB0 8009000004         */ IL_0005: stsfld class AspenTech.AspenPlus.Printing.GenericPrinting/'<>c' AspenTech.AspenPlus.Printing.GenericPrinting/'<>c'::'<>9' /* 04000009 */
			/* 0x00002BB5 2A                 */ IL_000a: ret
		} // end of method '<>c'::.cctor

		.method /* 0600001F */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x2bb7
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00002BB7 02                 */ IL_0000: ldarg.0
			/* 0x00002BB8 289500000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000095 */
			/* 0x00002BBD 2A                 */ IL_0006: ret
		} // end of method '<>c'::.ctor

		.method /* 06000020 */ assembly hidebysig 
			instance void '<DoGenericPrintPreview>b__2_0' (
				object sender,
				class [PresentationCore]System.Windows.RoutedEventArgs args
			) cil managed 
		{
			// Method begins at RVA 0x2bbf
			// Header size: 1
			// Code size: 11 (0xb)
			.maxstack 8

			/* 0x00002BBF 28A800000A         */ IL_0000: call class [PresentationCore]System.Windows.Input.Cursor [PresentationCore]System.Windows.Input.Cursors::get_Arrow() /* 0A0000A8 */
			/* 0x00002BC4 283B00000A         */ IL_0005: call void [PresentationCore]System.Windows.Input.Mouse::set_OverrideCursor(class [PresentationCore]System.Windows.Input.Cursor) /* 0A00003B */
			/* 0x00002BC9 2A                 */ IL_000a: ret
		} // end of method '<>c'::'<DoGenericPrintPreview>b__2_0'

	} // end of class <>c


	// Fields
	.field /* 04000001 */ private static literal float64 DefaultDpi = float64(96)

	// Methods
	.method /* 06000001 */ public hidebysig static 
		void DoGenericPrintSetup () cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 12
		// Code size: 180 (0xb4)
		.maxstack 5
		.locals /* 11000001 */ init (
			[0] class [System.Windows.Forms]System.Windows.Forms.PageSetupDialog,
			[1] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings,
			[2] class [System.Drawing]System.Drawing.Printing.Margins,
			[3] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings
		)

		/* 0x00002050 731D00000A         */ IL_0000: newobj instance void [System.Windows.Forms]System.Windows.Forms.PageSetupDialog::.ctor() /* 0A00001D */
		/* 0x00002055 25                 */ IL_0005: dup
		/* 0x00002056 2804000006         */ IL_0006: call class [System.Drawing]System.Drawing.Printing.PageSettings AspenTech.AspenPlus.Printing.PrintHelper::get_DefaultPageSettings() /* 06000004 */
		/* 0x0000205B 6F1E00000A         */ IL_000b: callvirt instance void [System.Windows.Forms]System.Windows.Forms.PageSetupDialog::set_PageSettings(class [System.Drawing]System.Drawing.Printing.PageSettings) /* 0A00001E */
		/* 0x00002060 0A                 */ IL_0010: stloc.0
		/* 0x00002061 06                 */ IL_0011: ldloc.0
		/* 0x00002062 6F1F00000A         */ IL_0012: callvirt instance valuetype [System.Windows.Forms]System.Windows.Forms.DialogResult [System.Windows.Forms]System.Windows.Forms.CommonDialog::ShowDialog() /* 0A00001F */
		/* 0x00002067 17                 */ IL_0017: ldc.i4.1
		/* 0x00002068 4096000000         */ IL_0018: bne.un IL_00b3
		/* 0x0000206D 282000000A         */ IL_001d: call class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.ApplicationSettings [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.SystemEnvironment::get_ApplicationSettings() /* 0A000020 */
		/* 0x00002072 6F2100000A         */ IL_0022: callvirt instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.ApplicationSettings::get_PrintSettings() /* 0A000021 */
		/* 0x00002077 0B                 */ IL_0027: stloc.1
		/* 0x00002078 07                 */ IL_0028: ldloc.1
		/* 0x00002079 2D13               */ IL_0029: brtrue.s IL_003e
		/* 0x0000207B 282000000A         */ IL_002b: call class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.ApplicationSettings [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.SystemEnvironment::get_ApplicationSettings() /* 0A000020 */
		/* 0x00002080 732200000A         */ IL_0030: newobj instance void [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::.ctor() /* 0A000022 */
		/* 0x00002085 25                 */ IL_0035: dup
		/* 0x00002086 0D                 */ IL_0036: stloc.3
		/* 0x00002087 6F2300000A         */ IL_0037: callvirt instance void [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.ApplicationSettings::set_PrintSettings(class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings) /* 0A000023 */
		/* 0x0000208C 09                 */ IL_003c: ldloc.3
		/* 0x0000208D 0B                 */ IL_003d: stloc.1
		/* 0x0000208E 07                 */ IL_003e: ldloc.1
		/* 0x0000208F 06                 */ IL_003f: ldloc.0
		/* 0x00002090 6F2400000A         */ IL_0040: callvirt instance class [System.Drawing]System.Drawing.Printing.PageSettings [System.Windows.Forms]System.Windows.Forms.PageSetupDialog::get_PageSettings() /* 0A000024 */
		/* 0x00002095 6F2500000A         */ IL_0045: callvirt instance class [System.Drawing]System.Drawing.Printing.PaperSize [System.Drawing]System.Drawing.Printing.PageSettings::get_PaperSize() /* 0A000025 */
		/* 0x0000209A 6F2600000A         */ IL_004a: callvirt instance string [System.Drawing]System.Drawing.Printing.PaperSize::get_PaperName() /* 0A000026 */
		/* 0x0000209F 6F2700000A         */ IL_004f: callvirt instance void [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::set_PaperSize(string) /* 0A000027 */
		/* 0x000020A4 07                 */ IL_0054: ldloc.1
		/* 0x000020A5 06                 */ IL_0055: ldloc.0
		/* 0x000020A6 6F2400000A         */ IL_0056: callvirt instance class [System.Drawing]System.Drawing.Printing.PageSettings [System.Windows.Forms]System.Windows.Forms.PageSetupDialog::get_PageSettings() /* 0A000024 */
		/* 0x000020AB 6F2800000A         */ IL_005b: callvirt instance class [System.Drawing]System.Drawing.Printing.PaperSource [System.Drawing]System.Drawing.Printing.PageSettings::get_PaperSource() /* 0A000028 */
		/* 0x000020B0 6F2900000A         */ IL_0060: callvirt instance string [System.Drawing]System.Drawing.Printing.PaperSource::get_SourceName() /* 0A000029 */
		/* 0x000020B5 6F2A00000A         */ IL_0065: callvirt instance void [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::set_PaperSource(string) /* 0A00002A */
		/* 0x000020BA 07                 */ IL_006a: ldloc.1
		/* 0x000020BB 06                 */ IL_006b: ldloc.0
		/* 0x000020BC 6F2400000A         */ IL_006c: callvirt instance class [System.Drawing]System.Drawing.Printing.PageSettings [System.Windows.Forms]System.Windows.Forms.PageSetupDialog::get_PageSettings() /* 0A000024 */
		/* 0x000020C1 6F2B00000A         */ IL_0071: callvirt instance bool [System.Drawing]System.Drawing.Printing.PageSettings::get_Landscape() /* 0A00002B */
		/* 0x000020C6 6F2C00000A         */ IL_0076: callvirt instance void [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::set_IsLandscape(bool) /* 0A00002C */
		/* 0x000020CB 06                 */ IL_007b: ldloc.0
		/* 0x000020CC 6F2400000A         */ IL_007c: callvirt instance class [System.Drawing]System.Drawing.Printing.PageSettings [System.Windows.Forms]System.Windows.Forms.PageSetupDialog::get_PageSettings() /* 0A000024 */
		/* 0x000020D1 6F2D00000A         */ IL_0081: callvirt instance class [System.Drawing]System.Drawing.Printing.Margins [System.Drawing]System.Drawing.Printing.PageSettings::get_Margins() /* 0A00002D */
		/* 0x000020D6 0C                 */ IL_0086: stloc.2
		/* 0x000020D7 07                 */ IL_0087: ldloc.1
		/* 0x000020D8 08                 */ IL_0088: ldloc.2
		/* 0x000020D9 6F2E00000A         */ IL_0089: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Left() /* 0A00002E */
		/* 0x000020DE 6C                 */ IL_008e: conv.r8
		/* 0x000020DF 08                 */ IL_008f: ldloc.2
		/* 0x000020E0 6F2F00000A         */ IL_0090: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Top() /* 0A00002F */
		/* 0x000020E5 6C                 */ IL_0095: conv.r8
		/* 0x000020E6 08                 */ IL_0096: ldloc.2
		/* 0x000020E7 6F3000000A         */ IL_0097: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Right() /* 0A000030 */
		/* 0x000020EC 6C                 */ IL_009c: conv.r8
		/* 0x000020ED 08                 */ IL_009d: ldloc.2
		/* 0x000020EE 6F3100000A         */ IL_009e: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Bottom() /* 0A000031 */
		/* 0x000020F3 6C                 */ IL_00a3: conv.r8
		/* 0x000020F4 733200000A         */ IL_00a4: newobj instance void [PresentationFramework]System.Windows.Thickness::.ctor(float64, float64, float64, float64) /* 0A000032 */
		/* 0x000020F9 733300000A         */ IL_00a9: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::.ctor(!0) /* 0A000033 */
		/* 0x000020FE 6F3400000A         */ IL_00ae: callvirt instance void [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::set_Margin(valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>) /* 0A000034 */
		/* 0x00002103 2A                 */ IL_00b3: ret
	} // end of method GenericPrinting::DoGenericPrintSetup

	.method /* 06000002 */ public hidebysig static 
		void DoGenericPrintPreview (
			class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport ps,
			class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer unityContainer
		) cil managed 
	{
		// Method begins at RVA 0x2110
		// Header size: 12
		// Code size: 332 (0x14c)
		.maxstack 5
		.locals /* 11000002 */ init (
			[0] class [PresentationFramework]System.Windows.Window,
			[1] class [PresentationCore]System.Windows.Input.Cursor,
			[2] class [System.Drawing]System.Drawing.Printing.PageSettings,
			[3] valuetype [WindowsBase]System.Windows.Size,
			[4] valuetype [WindowsBase]System.Windows.Rect,
			[5] valuetype [PresentationFramework]System.Windows.Thickness,
			[6] valuetype [System.Drawing]System.Drawing.RectangleF
		)

		/* 0x00002110 02                 */ IL_0000: ldarg.0
		/* 0x00002111 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x00002113 7201000070         */ IL_0003: ldstr "ps" /* 70000001 */
		/* 0x00002118 733500000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x0000211D 7A                 */ IL_000d: throw
		/* 0x0000211E 03                 */ IL_000e: ldarg.1
		/* 0x0000211F 2D0B               */ IL_000f: brtrue.s IL_001c
		/* 0x00002121 7207000070         */ IL_0011: ldstr "unityContainer" /* 70000007 */
		/* 0x00002126 733500000A         */ IL_0016: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x0000212B 7A                 */ IL_001b: throw
		/* 0x0000212C 03                 */ IL_001c: ldarg.1
		/* 0x0000212D 280100002B         */ IL_001d: call !!0[] [mscorlib]System.Array::Empty<class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.ResolverOverride>() /* 2B000001 */
		/* 0x00002132 280200002B         */ IL_0022: call !!0 [Microsoft.Practices.Unity]Microsoft.Practices.Unity.UnityContainerExtensions::Resolve<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellApplication>(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.ResolverOverride[]) /* 2B000002 */
		/* 0x00002137 6F3800000A         */ IL_0027: callvirt instance class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellApplication::get_ActiveWindow() /* 0A000038 */
		/* 0x0000213C 7517000001         */ IL_002c: isinst [PresentationFramework]System.Windows.Window /* 01000017 */
		/* 0x00002141 0A                 */ IL_0031: stloc.0
		/* 0x00002142 283900000A         */ IL_0032: call class [PresentationCore]System.Windows.Input.Cursor [PresentationCore]System.Windows.Input.Mouse::get_OverrideCursor() /* 0A000039 */
		/* 0x00002147 0B                 */ IL_0037: stloc.1
		/* 0x00002148 283A00000A         */ IL_0038: call class [PresentationCore]System.Windows.Input.Cursor [PresentationCore]System.Windows.Input.Cursors::get_Wait() /* 0A00003A */
		/* 0x0000214D 283B00000A         */ IL_003d: call void [PresentationCore]System.Windows.Input.Mouse::set_OverrideCursor(class [PresentationCore]System.Windows.Input.Cursor) /* 0A00003B */
		/* 0x00002152 2804000006         */ IL_0042: call class [System.Drawing]System.Drawing.Printing.PageSettings AspenTech.AspenPlus.Printing.PrintHelper::get_DefaultPageSettings() /* 06000004 */
		/* 0x00002157 0C                 */ IL_0047: stloc.2
		/* 0x00002158 1203               */ IL_0048: ldloca.s 3
		/* 0x0000215A 08                 */ IL_004a: ldloc.2
		/* 0x0000215B 6F2500000A         */ IL_004b: callvirt instance class [System.Drawing]System.Drawing.Printing.PaperSize [System.Drawing]System.Drawing.Printing.PageSettings::get_PaperSize() /* 0A000025 */
		/* 0x00002160 6F3C00000A         */ IL_0050: callvirt instance int32 [System.Drawing]System.Drawing.Printing.PaperSize::get_Width() /* 0A00003C */
		/* 0x00002165 6C                 */ IL_0055: conv.r8
		/* 0x00002166 2809000006         */ IL_0056: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x0000216B 08                 */ IL_005b: ldloc.2
		/* 0x0000216C 6F2500000A         */ IL_005c: callvirt instance class [System.Drawing]System.Drawing.Printing.PaperSize [System.Drawing]System.Drawing.Printing.PageSettings::get_PaperSize() /* 0A000025 */
		/* 0x00002171 6F3D00000A         */ IL_0061: callvirt instance int32 [System.Drawing]System.Drawing.Printing.PaperSize::get_Height() /* 0A00003D */
		/* 0x00002176 6C                 */ IL_0066: conv.r8
		/* 0x00002177 2809000006         */ IL_0067: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x0000217C 283E00000A         */ IL_006c: call instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00003E */
		/* 0x00002181 08                 */ IL_0071: ldloc.2
		/* 0x00002182 6F3F00000A         */ IL_0072: callvirt instance valuetype [System.Drawing]System.Drawing.RectangleF [System.Drawing]System.Drawing.Printing.PageSettings::get_PrintableArea() /* 0A00003F */
		/* 0x00002187 1306               */ IL_0077: stloc.s 6
		/* 0x00002189 1206               */ IL_0079: ldloca.s 6
		/* 0x0000218B 284000000A         */ IL_007b: call instance bool [System.Drawing]System.Drawing.RectangleF::get_IsEmpty() /* 0A000040 */
		/* 0x00002190 2D5B               */ IL_0080: brtrue.s IL_00dd
		/* 0x00002192 08                 */ IL_0082: ldloc.2
		/* 0x00002193 6F3F00000A         */ IL_0083: callvirt instance valuetype [System.Drawing]System.Drawing.RectangleF [System.Drawing]System.Drawing.Printing.PageSettings::get_PrintableArea() /* 0A00003F */
		/* 0x00002198 1306               */ IL_0088: stloc.s 6
		/* 0x0000219A 1206               */ IL_008a: ldloca.s 6
		/* 0x0000219C 284100000A         */ IL_008c: call instance float32 [System.Drawing]System.Drawing.RectangleF::get_Left() /* 0A000041 */
		/* 0x000021A1 6C                 */ IL_0091: conv.r8
		/* 0x000021A2 2809000006         */ IL_0092: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x000021A7 08                 */ IL_0097: ldloc.2
		/* 0x000021A8 6F3F00000A         */ IL_0098: callvirt instance valuetype [System.Drawing]System.Drawing.RectangleF [System.Drawing]System.Drawing.Printing.PageSettings::get_PrintableArea() /* 0A00003F */
		/* 0x000021AD 1306               */ IL_009d: stloc.s 6
		/* 0x000021AF 1206               */ IL_009f: ldloca.s 6
		/* 0x000021B1 284200000A         */ IL_00a1: call instance float32 [System.Drawing]System.Drawing.RectangleF::get_Top() /* 0A000042 */
		/* 0x000021B6 6C                 */ IL_00a6: conv.r8
		/* 0x000021B7 2809000006         */ IL_00a7: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x000021BC 08                 */ IL_00ac: ldloc.2
		/* 0x000021BD 6F3F00000A         */ IL_00ad: callvirt instance valuetype [System.Drawing]System.Drawing.RectangleF [System.Drawing]System.Drawing.Printing.PageSettings::get_PrintableArea() /* 0A00003F */
		/* 0x000021C2 1306               */ IL_00b2: stloc.s 6
		/* 0x000021C4 1206               */ IL_00b4: ldloca.s 6
		/* 0x000021C6 284300000A         */ IL_00b6: call instance float32 [System.Drawing]System.Drawing.RectangleF::get_Width() /* 0A000043 */
		/* 0x000021CB 6C                 */ IL_00bb: conv.r8
		/* 0x000021CC 2809000006         */ IL_00bc: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x000021D1 08                 */ IL_00c1: ldloc.2
		/* 0x000021D2 6F3F00000A         */ IL_00c2: callvirt instance valuetype [System.Drawing]System.Drawing.RectangleF [System.Drawing]System.Drawing.Printing.PageSettings::get_PrintableArea() /* 0A00003F */
		/* 0x000021D7 1306               */ IL_00c7: stloc.s 6
		/* 0x000021D9 1206               */ IL_00c9: ldloca.s 6
		/* 0x000021DB 284400000A         */ IL_00cb: call instance float32 [System.Drawing]System.Drawing.RectangleF::get_Height() /* 0A000044 */
		/* 0x000021E0 6C                 */ IL_00d0: conv.r8
		/* 0x000021E1 2809000006         */ IL_00d1: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x000021E6 734500000A         */ IL_00d6: newobj instance void [WindowsBase]System.Windows.Rect::.ctor(float64, float64, float64, float64) /* 0A000045 */
		/* 0x000021EB 2B06               */ IL_00db: br.s IL_00e3
		/* 0x000021ED 09                 */ IL_00dd: ldloc.3
		/* 0x000021EE 734600000A         */ IL_00de: newobj instance void [WindowsBase]System.Windows.Rect::.ctor(valuetype [WindowsBase]System.Windows.Size) /* 0A000046 */
		/* 0x000021F3 1304               */ IL_00e3: stloc.s 4
		/* 0x000021F5 08                 */ IL_00e5: ldloc.2
		/* 0x000021F6 6F2D00000A         */ IL_00e6: callvirt instance class [System.Drawing]System.Drawing.Printing.Margins [System.Drawing]System.Drawing.Printing.PageSettings::get_Margins() /* 0A00002D */
		/* 0x000021FB 280A000006         */ IL_00eb: call valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper::ConvertMargins(class [System.Drawing]System.Drawing.Printing.Margins) /* 0600000A */
		/* 0x00002200 1305               */ IL_00f0: stloc.s 5
		/* 0x00002202 02                 */ IL_00f2: ldarg.0
		/* 0x00002203 1104               */ IL_00f3: ldloc.s 4
		/* 0x00002205 09                 */ IL_00f5: ldloc.3
		/* 0x00002206 1105               */ IL_00f6: ldloc.s 5
		/* 0x00002208 733300000A         */ IL_00f8: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::.ctor(!0) /* 0A000033 */
		/* 0x0000220D 08                 */ IL_00fd: ldloc.2
		/* 0x0000220E 6F2B00000A         */ IL_00fe: callvirt instance bool [System.Drawing]System.Drawing.Printing.PageSettings::get_Landscape() /* 0A00002B */
		/* 0x00002213 2806000006         */ IL_0103: call class [PresentationFramework]System.Windows.Documents.FixedDocument AspenTech.AspenPlus.Printing.PrintHelper::CreateFixedDocument(class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport, valuetype [WindowsBase]System.Windows.Rect, valuetype [WindowsBase]System.Windows.Size, valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>, bool) /* 06000006 */
		/* 0x00002218 7317000006         */ IL_0108: newobj instance void AspenTech.AspenPlus.Printing.PrintPreviewWindow::.ctor(class [PresentationFramework]System.Windows.Documents.FixedDocument) /* 06000017 */
		/* 0x0000221D 25                 */ IL_010d: dup
		/* 0x0000221E 06                 */ IL_010e: ldloc.0
		/* 0x0000221F 6F4700000A         */ IL_010f: callvirt instance void [PresentationFramework]System.Windows.Window::set_Owner(class [PresentationFramework]System.Windows.Window) /* 0A000047 */
		/* 0x00002224 25                 */ IL_0114: dup
		/* 0x00002225 7E0A000004         */ IL_0115: ldsfld class [PresentationCore]System.Windows.RoutedEventHandler AspenTech.AspenPlus.Printing.GenericPrinting/'<>c'::'<>9__2_0' /* 0400000A */
		/* 0x0000222A 25                 */ IL_011a: dup
		/* 0x0000222B 2D17               */ IL_011b: brtrue.s IL_0134
		/* 0x0000222D 26                 */ IL_011d: pop
		/* 0x0000222E 7E09000004         */ IL_011e: ldsfld class AspenTech.AspenPlus.Printing.GenericPrinting/'<>c' AspenTech.AspenPlus.Printing.GenericPrinting/'<>c'::'<>9' /* 04000009 */
		/* 0x00002233 FE0620000006       */ IL_0123: ldftn instance void AspenTech.AspenPlus.Printing.GenericPrinting/'<>c'::'<DoGenericPrintPreview>b__2_0'(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 06000020 */
		/* 0x00002239 734800000A         */ IL_0129: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000048 */
		/* 0x0000223E 25                 */ IL_012e: dup
		/* 0x0000223F 800A000004         */ IL_012f: stsfld class [PresentationCore]System.Windows.RoutedEventHandler AspenTech.AspenPlus.Printing.GenericPrinting/'<>c'::'<>9__2_0' /* 0400000A */
		/* 0x00002244 6F4900000A         */ IL_0134: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000049 */
		/* 0x00002249 6F4A00000A         */ IL_0139: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]System.Windows.Window::ShowDialog() /* 0A00004A */
		/* 0x0000224E 26                 */ IL_013e: pop
		/* 0x0000224F DE0A               */ IL_013f: leave.s IL_014b
		/* 0x00002251 26                 */ IL_0141: pop
		/* 0x00002252 DE07               */ IL_0142: leave.s IL_014b
		/* 0x00002254 07                 */ IL_0144: ldloc.1
		/* 0x00002255 283B00000A         */ IL_0145: call void [PresentationCore]System.Windows.Input.Mouse::set_OverrideCursor(class [PresentationCore]System.Windows.Input.Cursor) /* 0A00003B */
		/* 0x0000225A DC                 */ IL_014a: endfinally
		/* 0x0000225B 2A                 */ IL_014b: ret

		.try IL_00f2-IL_0141 catch [mscorlib]System.InvalidOperationException IL_0141-IL_0144
		.try IL_00f2-IL_0144 finally IL_0144-IL_014b
	} // end of method GenericPrinting::DoGenericPrintPreview

	.method /* 06000003 */ public hidebysig static 
		void DoGenericPrint (
			class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport ps
		) cil managed 
	{
		// Method begins at RVA 0x2284
		// Header size: 12
		// Code size: 281 (0x119)
		.maxstack 5
		.locals /* 11000003 */ init (
			[0] class [System.Drawing]System.Drawing.Printing.PageSettings,
			[1] valuetype [PresentationFramework]System.Windows.Thickness,
			[2] class [PresentationFramework]System.Windows.Controls.PrintDialog,
			[3] class [System.Printing]System.Printing.PrintQueue,
			[4] class [ReachFramework]System.Printing.PrintTicket,
			[5] valuetype [mscorlib]System.Nullable`1<bool>,
			[6] bool,
			[7] bool,
			[8] valuetype [WindowsBase]System.Windows.Size,
			[9] valuetype [WindowsBase]System.Windows.Rect,
			[10] class [PresentationFramework]System.Windows.Documents.FixedDocument,
			[11] valuetype [mscorlib]System.Nullable`1<valuetype [ReachFramework]System.Printing.PageOrientation>,
			[12] valuetype [ReachFramework]System.Printing.PageOrientation
		)

		/* 0x00002284 02                 */ IL_0000: ldarg.0
		/* 0x00002285 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x00002287 7201000070         */ IL_0003: ldstr "ps" /* 70000001 */
		/* 0x0000228C 733500000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x00002291 7A                 */ IL_000d: throw
		/* 0x00002292 00                 */ IL_000e: nop
		/* 0x00002293 2804000006         */ IL_000f: call class [System.Drawing]System.Drawing.Printing.PageSettings AspenTech.AspenPlus.Printing.PrintHelper::get_DefaultPageSettings() /* 06000004 */
		/* 0x00002298 0A                 */ IL_0014: stloc.0
		/* 0x00002299 06                 */ IL_0015: ldloc.0
		/* 0x0000229A 6F2D00000A         */ IL_0016: callvirt instance class [System.Drawing]System.Drawing.Printing.Margins [System.Drawing]System.Drawing.Printing.PageSettings::get_Margins() /* 0A00002D */
		/* 0x0000229F 280A000006         */ IL_001b: call valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper::ConvertMargins(class [System.Drawing]System.Drawing.Printing.Margins) /* 0600000A */
		/* 0x000022A4 0B                 */ IL_0020: stloc.1
		/* 0x000022A5 734B00000A         */ IL_0021: newobj instance void [PresentationFramework]System.Windows.Controls.PrintDialog::.ctor() /* 0A00004B */
		/* 0x000022AA 0C                 */ IL_0026: stloc.2
		/* 0x000022AB 08                 */ IL_0027: ldloc.2
		/* 0x000022AC 6F4C00000A         */ IL_0028: callvirt instance class [System.Printing]System.Printing.PrintQueue [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintQueue() /* 0A00004C */
		/* 0x000022B1 0D                 */ IL_002d: stloc.3
		/* 0x000022B2 08                 */ IL_002e: ldloc.2
		/* 0x000022B3 6F4D00000A         */ IL_002f: callvirt instance class [ReachFramework]System.Printing.PrintTicket [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintTicket() /* 0A00004D */
		/* 0x000022B8 1304               */ IL_0034: stloc.s 4
		/* 0x000022BA 06                 */ IL_0036: ldloc.0
		/* 0x000022BB 6F2500000A         */ IL_0037: callvirt instance class [System.Drawing]System.Drawing.Printing.PaperSize [System.Drawing]System.Drawing.Printing.PageSettings::get_PaperSize() /* 0A000025 */
		/* 0x000022C0 2C1F               */ IL_003c: brfalse.s IL_005d
		/* 0x000022C2 1104               */ IL_003e: ldloc.s 4
		/* 0x000022C4 06                 */ IL_0040: ldloc.0
		/* 0x000022C5 6F2500000A         */ IL_0041: callvirt instance class [System.Drawing]System.Drawing.Printing.PaperSize [System.Drawing]System.Drawing.Printing.PageSettings::get_PaperSize() /* 0A000025 */
		/* 0x000022CA 09                 */ IL_0046: ldloc.3
		/* 0x000022CB 1104               */ IL_0047: ldloc.s 4
		/* 0x000022CD 6F4E00000A         */ IL_0049: callvirt instance class [ReachFramework]System.Printing.PrintCapabilities [System.Printing]System.Printing.PrintQueue::GetPrintCapabilities(class [ReachFramework]System.Printing.PrintTicket) /* 0A00004E */
		/* 0x000022D2 6F4F00000A         */ IL_004e: callvirt instance class [mscorlib]System.Collections.ObjectModel.ReadOnlyCollection`1<class [ReachFramework]System.Printing.PageMediaSize> [ReachFramework]System.Printing.PrintCapabilities::get_PageMediaSizeCapability() /* 0A00004F */
		/* 0x000022D7 2805000006         */ IL_0053: call class [ReachFramework]System.Printing.PageMediaSize AspenTech.AspenPlus.Printing.PrintHelper::ConvertPaperSizeToPageMediaSize(class [System.Drawing]System.Drawing.Printing.PaperSize, class [mscorlib]System.Collections.Generic.IEnumerable`1<class [ReachFramework]System.Printing.PageMediaSize>) /* 06000005 */
		/* 0x000022DC 6F5000000A         */ IL_0058: callvirt instance void [ReachFramework]System.Printing.PrintTicket::set_PageMediaSize(class [ReachFramework]System.Printing.PageMediaSize) /* 0A000050 */
		/* 0x000022E1 1104               */ IL_005d: ldloc.s 4
		/* 0x000022E3 06                 */ IL_005f: ldloc.0
		/* 0x000022E4 6F2B00000A         */ IL_0060: callvirt instance bool [System.Drawing]System.Drawing.Printing.PageSettings::get_Landscape() /* 0A00002B */
		/* 0x000022E9 2D03               */ IL_0065: brtrue.s IL_006a
		/* 0x000022EB 18                 */ IL_0067: ldc.i4.2
		/* 0x000022EC 2B01               */ IL_0068: br.s IL_006b
		/* 0x000022EE 17                 */ IL_006a: ldc.i4.1
		/* 0x000022EF 735100000A         */ IL_006b: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [ReachFramework]System.Printing.PageOrientation>::.ctor(!0) /* 0A000051 */
		/* 0x000022F4 6F5200000A         */ IL_0070: callvirt instance void [ReachFramework]System.Printing.PrintTicket::set_PageOrientation(valuetype [mscorlib]System.Nullable`1<valuetype [ReachFramework]System.Printing.PageOrientation>) /* 0A000052 */
		/* 0x000022F9 08                 */ IL_0075: ldloc.2
		/* 0x000022FA 6F5300000A         */ IL_0076: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]System.Windows.Controls.PrintDialog::ShowDialog() /* 0A000053 */
		/* 0x000022FF 1305               */ IL_007b: stloc.s 5
		/* 0x00002301 17                 */ IL_007d: ldc.i4.1
		/* 0x00002302 1306               */ IL_007e: stloc.s 6
		/* 0x00002304 1205               */ IL_0080: ldloca.s 5
		/* 0x00002306 285400000A         */ IL_0082: call instance !0 valuetype [mscorlib]System.Nullable`1<bool>::GetValueOrDefault() /* 0A000054 */
		/* 0x0000230B 1106               */ IL_0087: ldloc.s 6
		/* 0x0000230D FE01               */ IL_0089: ceq
		/* 0x0000230F 1205               */ IL_008b: ldloca.s 5
		/* 0x00002311 285500000A         */ IL_008d: call instance bool valuetype [mscorlib]System.Nullable`1<bool>::get_HasValue() /* 0A000055 */
		/* 0x00002316 5F                 */ IL_0092: and
		/* 0x00002317 2C7E               */ IL_0093: brfalse.s IL_0113
		/* 0x00002319 08                 */ IL_0095: ldloc.2
		/* 0x0000231A 6F4D00000A         */ IL_0096: callvirt instance class [ReachFramework]System.Printing.PrintTicket [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintTicket() /* 0A00004D */
		/* 0x0000231F 6F5600000A         */ IL_009b: callvirt instance valuetype [mscorlib]System.Nullable`1<valuetype [ReachFramework]System.Printing.PageOrientation> [ReachFramework]System.Printing.PrintTicket::get_PageOrientation() /* 0A000056 */
		/* 0x00002324 130B               */ IL_00a0: stloc.s 11
		/* 0x00002326 17                 */ IL_00a2: ldc.i4.1
		/* 0x00002327 130C               */ IL_00a3: stloc.s 12
		/* 0x00002329 120B               */ IL_00a5: ldloca.s 11
		/* 0x0000232B 285700000A         */ IL_00a7: call instance !0 valuetype [mscorlib]System.Nullable`1<valuetype [ReachFramework]System.Printing.PageOrientation>::GetValueOrDefault() /* 0A000057 */
		/* 0x00002330 110C               */ IL_00ac: ldloc.s 12
		/* 0x00002332 FE01               */ IL_00ae: ceq
		/* 0x00002334 120B               */ IL_00b0: ldloca.s 11
		/* 0x00002336 285800000A         */ IL_00b2: call instance bool valuetype [mscorlib]System.Nullable`1<valuetype [ReachFramework]System.Printing.PageOrientation>::get_HasValue() /* 0A000058 */
		/* 0x0000233B 5F                 */ IL_00b7: and
		/* 0x0000233C 1307               */ IL_00b8: stloc.s 7
		/* 0x0000233E 1107               */ IL_00ba: ldloc.s 7
		/* 0x00002340 2D13               */ IL_00bc: brtrue.s IL_00d1
		/* 0x00002342 08                 */ IL_00be: ldloc.2
		/* 0x00002343 6F5900000A         */ IL_00bf: callvirt instance float64 [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintableAreaWidth() /* 0A000059 */
		/* 0x00002348 08                 */ IL_00c4: ldloc.2
		/* 0x00002349 6F5A00000A         */ IL_00c5: callvirt instance float64 [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintableAreaHeight() /* 0A00005A */
		/* 0x0000234E 733E00000A         */ IL_00ca: newobj instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00003E */
		/* 0x00002353 2B11               */ IL_00cf: br.s IL_00e2
		/* 0x00002355 08                 */ IL_00d1: ldloc.2
		/* 0x00002356 6F5A00000A         */ IL_00d2: callvirt instance float64 [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintableAreaHeight() /* 0A00005A */
		/* 0x0000235B 08                 */ IL_00d7: ldloc.2
		/* 0x0000235C 6F5900000A         */ IL_00d8: callvirt instance float64 [PresentationFramework]System.Windows.Controls.PrintDialog::get_PrintableAreaWidth() /* 0A000059 */
		/* 0x00002361 733E00000A         */ IL_00dd: newobj instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00003E */
		/* 0x00002366 1308               */ IL_00e2: stloc.s 8
		/* 0x00002368 1209               */ IL_00e4: ldloca.s 9
		/* 0x0000236A 1108               */ IL_00e6: ldloc.s 8
		/* 0x0000236C 284600000A         */ IL_00e8: call instance void [WindowsBase]System.Windows.Rect::.ctor(valuetype [WindowsBase]System.Windows.Size) /* 0A000046 */
		/* 0x00002371 02                 */ IL_00ed: ldarg.0
		/* 0x00002372 1109               */ IL_00ee: ldloc.s 9
		/* 0x00002374 1108               */ IL_00f0: ldloc.s 8
		/* 0x00002376 07                 */ IL_00f2: ldloc.1
		/* 0x00002377 733300000A         */ IL_00f3: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::.ctor(!0) /* 0A000033 */
		/* 0x0000237C 1107               */ IL_00f8: ldloc.s 7
		/* 0x0000237E 2806000006         */ IL_00fa: call class [PresentationFramework]System.Windows.Documents.FixedDocument AspenTech.AspenPlus.Printing.PrintHelper::CreateFixedDocument(class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport, valuetype [WindowsBase]System.Windows.Rect, valuetype [WindowsBase]System.Windows.Size, valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>, bool) /* 06000006 */
		/* 0x00002383 130A               */ IL_00ff: stloc.s 10
		/* 0x00002385 08                 */ IL_0101: ldloc.2
		/* 0x00002386 110A               */ IL_0102: ldloc.s 10
		/* 0x00002388 6F5B00000A         */ IL_0104: callvirt instance class [PresentationCore]System.Windows.Documents.DocumentPaginator [PresentationFramework]System.Windows.Documents.FixedDocument::get_DocumentPaginator() /* 0A00005B */
		/* 0x0000238D 285C00000A         */ IL_0109: call string [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.SystemEnvironment::get_ApplicationNameWithVersion() /* 0A00005C */
		/* 0x00002392 6F5D00000A         */ IL_010e: callvirt instance void [PresentationFramework]System.Windows.Controls.PrintDialog::PrintDocument(class [PresentationCore]System.Windows.Documents.DocumentPaginator, string) /* 0A00005D */
		/* 0x00002397 DE03               */ IL_0113: leave.s IL_0118
		/* 0x00002399 26                 */ IL_0115: pop
		/* 0x0000239A DE00               */ IL_0116: leave.s IL_0118
		/* 0x0000239C 2A                 */ IL_0118: ret

		.try IL_000f-IL_0115 catch [mscorlib]System.InvalidOperationException IL_0115-IL_0118
	} // end of method GenericPrinting::DoGenericPrint

} // end of class AspenTech.AspenPlus.Printing.GenericPrinting

.class /* 02000003 */ private auto ansi abstract sealed beforefieldinit AspenTech.AspenPlus.Printing.PrintHelper
	extends [mscorlib]System.Object
{
	// Nested Types
	.class /* 02000009 */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClass2_0'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000013 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400000B */ public class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings pps

		// Methods
		.method /* 06000021 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x2bb7
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00002BB7 02                 */ IL_0000: ldarg.0
			/* 0x00002BB8 289500000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000095 */
			/* 0x00002BBD 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClass2_0'::.ctor

		.method /* 06000022 */ assembly hidebysig 
			instance bool '<get_DefaultPageSettings>b__0' (
				class [System.Drawing]System.Drawing.Printing.PaperSize x
			) cil managed 
		{
			// Method begins at RVA 0x2bcb
			// Header size: 1
			// Code size: 23 (0x17)
			.maxstack 8

			/* 0x00002BCB 03                 */ IL_0000: ldarg.1
			/* 0x00002BCC 6F2600000A         */ IL_0001: callvirt instance string [System.Drawing]System.Drawing.Printing.PaperSize::get_PaperName() /* 0A000026 */
			/* 0x00002BD1 02                 */ IL_0006: ldarg.0
			/* 0x00002BD2 7B0B000004         */ IL_0007: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
			/* 0x00002BD7 6F6000000A         */ IL_000c: callvirt instance string [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_PaperSize() /* 0A000060 */
			/* 0x00002BDC 28A900000A         */ IL_0011: call bool [mscorlib]System.String::Equals(string, string) /* 0A0000A9 */
			/* 0x00002BE1 2A                 */ IL_0016: ret
		} // end of method '<>c__DisplayClass2_0'::'<get_DefaultPageSettings>b__0'

		.method /* 06000023 */ assembly hidebysig 
			instance bool '<get_DefaultPageSettings>b__1' (
				class [System.Drawing]System.Drawing.Printing.PaperSource x
			) cil managed 
		{
			// Method begins at RVA 0x2be3
			// Header size: 1
			// Code size: 23 (0x17)
			.maxstack 8

			/* 0x00002BE3 03                 */ IL_0000: ldarg.1
			/* 0x00002BE4 6F2900000A         */ IL_0001: callvirt instance string [System.Drawing]System.Drawing.Printing.PaperSource::get_SourceName() /* 0A000029 */
			/* 0x00002BE9 02                 */ IL_0006: ldarg.0
			/* 0x00002BEA 7B0B000004         */ IL_0007: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
			/* 0x00002BEF 6F6700000A         */ IL_000c: callvirt instance string [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_PaperSource() /* 0A000067 */
			/* 0x00002BF4 28A900000A         */ IL_0011: call bool [mscorlib]System.String::Equals(string, string) /* 0A0000A9 */
			/* 0x00002BF9 2A                 */ IL_0016: ret
		} // end of method '<>c__DisplayClass2_0'::'<get_DefaultPageSettings>b__1'

	} // end of class <>c__DisplayClass2_0

	.class /* 0200000A */ nested private auto ansi sealed beforefieldinit '<GeneratePrintingElements>d__5'
		extends [mscorlib]System.Object
		implements class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement>,
		           [mscorlib]System.Collections.IEnumerable,
		           class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement>,
		           [mscorlib]System.IDisposable,
		           [mscorlib]System.Collections.IEnumerator
	{
		.custom /* 0C000014 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400000C */ private int32 '<>1__state'
		.field /* 0400000D */ private class [PresentationFramework]System.Windows.FrameworkElement '<>2__current'
		.field /* 0400000E */ private int32 '<>l__initialThreadId'
		.field /* 0400000F */ private valuetype [WindowsBase]System.Windows.Rect adjustedPrintableArea
		.field /* 04000010 */ public valuetype [WindowsBase]System.Windows.Rect '<>3__adjustedPrintableArea'
		.field /* 04000011 */ private valuetype [WindowsBase]System.Windows.Size adjustedPaperSize
		.field /* 04000012 */ public valuetype [WindowsBase]System.Windows.Size '<>3__adjustedPaperSize'
		.field /* 04000013 */ private valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> margin
		.field /* 04000014 */ public valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> '<>3__margin'
		.field /* 04000015 */ private class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport ps
		.field /* 04000016 */ public class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport '<>3__ps'
		.field /* 04000017 */ private valuetype [PresentationFramework]System.Windows.Thickness '<borderPadding>5__2'
		.field /* 04000018 */ private class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> '<>7__wrap2'

		// Methods
		.method /* 06000024 */ public hidebysig specialname rtspecialname 
			instance void .ctor (
				int32 '<>1__state'
			) cil managed 
		{
			.custom /* 0C00001A */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x2bfb
			// Header size: 1
			// Code size: 25 (0x19)
			.maxstack 8

			/* 0x00002BFB 02                 */ IL_0000: ldarg.0
			/* 0x00002BFC 289500000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000095 */
			/* 0x00002C01 02                 */ IL_0006: ldarg.0
			/* 0x00002C02 03                 */ IL_0007: ldarg.1
			/* 0x00002C03 7D0C000004         */ IL_0008: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002C08 02                 */ IL_000d: ldarg.0
			/* 0x00002C09 28AA00000A         */ IL_000e: call int32 [mscorlib]System.Environment::get_CurrentManagedThreadId() /* 0A0000AA */
			/* 0x00002C0E 7D0E000004         */ IL_0013: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>l__initialThreadId' /* 0400000E */
			/* 0x00002C13 2A                 */ IL_0018: ret
		} // end of method '<GeneratePrintingElements>d__5'::.ctor

		.method /* 06000025 */ private final hidebysig newslot virtual 
			instance void System.IDisposable.Dispose () cil managed 
		{
			.custom /* 0C00001B */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance void [mscorlib]System.IDisposable::Dispose()
			// Method begins at RVA 0x2c18
			// Header size: 12
			// Code size: 27 (0x1b)
			.maxstack 2
			.locals /* 1100000D */ init (
				[0] int32
			)

			/* 0x00002C18 02                 */ IL_0000: ldarg.0
			/* 0x00002C19 7B0C000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002C1E 0A                 */ IL_0006: stloc.0
			/* 0x00002C1F 06                 */ IL_0007: ldloc.0
			/* 0x00002C20 1FFD               */ IL_0008: ldc.i4.s -3
			/* 0x00002C22 2E04               */ IL_000a: beq.s IL_0010
			/* 0x00002C24 06                 */ IL_000c: ldloc.0
			/* 0x00002C25 17                 */ IL_000d: ldc.i4.1
			/* 0x00002C26 330A               */ IL_000e: bne.un.s IL_001a
			/* 0x00002C28 00                 */ IL_0010: nop
			/* 0x00002C29 DE07               */ IL_0011: leave.s IL_001a
			/* 0x00002C2B 02                 */ IL_0013: ldarg.0
			/* 0x00002C2C 2827000006         */ IL_0014: call instance void AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>m__Finally1'() /* 06000027 */
			/* 0x00002C31 DC                 */ IL_0019: endfinally
			/* 0x00002C32 2A                 */ IL_001a: ret

			.try IL_0011-IL_0013 finally IL_0013-IL_001a
		} // end of method '<GeneratePrintingElements>d__5'::System.IDisposable.Dispose

		.method /* 06000026 */ private final hidebysig newslot virtual 
			instance bool MoveNext () cil managed 
		{
			.override method instance bool [mscorlib]System.Collections.IEnumerator::MoveNext()
			// Method begins at RVA 0x2c50
			// Header size: 12
			// Code size: 361 (0x169)
			.maxstack 4
			.locals /* 1100000E */ init (
				[0] bool,
				[1] int32,
				[2] valuetype [WindowsBase]System.Windows.Size,
				[3] class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement>,
				[4] class [PresentationFramework]System.Windows.FrameworkElement
			)

			/* 0x00002C50 02                 */ IL_0000: ldarg.0
			/* 0x00002C51 7B0C000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002C56 0B                 */ IL_0006: stloc.1
			/* 0x00002C57 07                 */ IL_0007: ldloc.1
			/* 0x00002C58 2C0E               */ IL_0008: brfalse.s IL_0018
			/* 0x00002C5A 07                 */ IL_000a: ldloc.1
			/* 0x00002C5B 17                 */ IL_000b: ldc.i4.1
			/* 0x00002C5C 3B26010000         */ IL_000c: beq IL_0137
			/* 0x00002C61 16                 */ IL_0011: ldc.i4.0
			/* 0x00002C62 0A                 */ IL_0012: stloc.0
			/* 0x00002C63 DD4F010000         */ IL_0013: leave IL_0167
			/* 0x00002C68 02                 */ IL_0018: ldarg.0
			/* 0x00002C69 15                 */ IL_0019: ldc.i4.m1
			/* 0x00002C6A 7D0C000004         */ IL_001a: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002C6F 02                 */ IL_001f: ldarg.0
			/* 0x00002C70 02                 */ IL_0020: ldarg.0
			/* 0x00002C71 7B0F000004         */ IL_0021: ldfld valuetype [WindowsBase]System.Windows.Rect AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPrintableArea /* 0400000F */
			/* 0x00002C76 02                 */ IL_0026: ldarg.0
			/* 0x00002C77 7B11000004         */ IL_0027: ldfld valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPaperSize /* 04000011 */
			/* 0x00002C7C 02                 */ IL_002c: ldarg.0
			/* 0x00002C7D 7B13000004         */ IL_002d: ldfld valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::margin /* 04000013 */
			/* 0x00002C82 2808000006         */ IL_0032: call valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper::CalculateBorderPadding(valuetype [WindowsBase]System.Windows.Rect, valuetype [WindowsBase]System.Windows.Size, valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>) /* 06000008 */
			/* 0x00002C87 7D17000004         */ IL_0037: stfld valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002C8C 02                 */ IL_003c: ldarg.0
			/* 0x00002C8D 02                 */ IL_003d: ldarg.0
			/* 0x00002C8E 7B17000004         */ IL_003e: ldfld valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002C93 280C000006         */ IL_0043: call valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper::FixThickness(valuetype [PresentationFramework]System.Windows.Thickness) /* 0600000C */
			/* 0x00002C98 7D17000004         */ IL_0048: stfld valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002C9D 1202               */ IL_004d: ldloca.s 2
			/* 0x00002C9F 02                 */ IL_004f: ldarg.0
			/* 0x00002CA0 7C11000004         */ IL_0050: ldflda valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPaperSize /* 04000011 */
			/* 0x00002CA5 287C00000A         */ IL_0055: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
			/* 0x00002CAA 02                 */ IL_005a: ldarg.0
			/* 0x00002CAB 7C17000004         */ IL_005b: ldflda valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002CB0 287000000A         */ IL_0060: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Left() /* 0A000070 */
			/* 0x00002CB5 59                 */ IL_0065: sub
			/* 0x00002CB6 02                 */ IL_0066: ldarg.0
			/* 0x00002CB7 7C17000004         */ IL_0067: ldflda valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002CBC 287100000A         */ IL_006c: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Right() /* 0A000071 */
			/* 0x00002CC1 59                 */ IL_0071: sub
			/* 0x00002CC2 02                 */ IL_0072: ldarg.0
			/* 0x00002CC3 7C11000004         */ IL_0073: ldflda valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPaperSize /* 04000011 */
			/* 0x00002CC8 287D00000A         */ IL_0078: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
			/* 0x00002CCD 02                 */ IL_007d: ldarg.0
			/* 0x00002CCE 7C17000004         */ IL_007e: ldflda valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002CD3 287200000A         */ IL_0083: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Top() /* 0A000072 */
			/* 0x00002CD8 59                 */ IL_0088: sub
			/* 0x00002CD9 02                 */ IL_0089: ldarg.0
			/* 0x00002CDA 7C17000004         */ IL_008a: ldflda valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002CDF 287300000A         */ IL_008f: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Bottom() /* 0A000073 */
			/* 0x00002CE4 59                 */ IL_0094: sub
			/* 0x00002CE5 283E00000A         */ IL_0095: call instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00003E */
			/* 0x00002CEA 02                 */ IL_009a: ldarg.0
			/* 0x00002CEB 7B15000004         */ IL_009b: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::ps /* 04000015 */
			/* 0x00002CF0 08                 */ IL_00a0: ldloc.2
			/* 0x00002CF1 6FAB00000A         */ IL_00a1: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement> [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport::GeneratePrintPages(valuetype [WindowsBase]System.Windows.Size) /* 0A0000AB */
			/* 0x00002CF6 0D                 */ IL_00a6: stloc.3
			/* 0x00002CF7 09                 */ IL_00a7: ldloc.3
			/* 0x00002CF8 39AF000000         */ IL_00a8: brfalse IL_015c
			/* 0x00002CFD 02                 */ IL_00ad: ldarg.0
			/* 0x00002CFE 09                 */ IL_00ae: ldloc.3
			/* 0x00002CFF 6F1600000A         */ IL_00af: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement>::GetEnumerator() /* 0A000016 */
			/* 0x00002D04 7D18000004         */ IL_00b4: stfld class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>7__wrap2' /* 04000018 */
			/* 0x00002D09 02                 */ IL_00b9: ldarg.0
			/* 0x00002D0A 1FFD               */ IL_00ba: ldc.i4.s -3
			/* 0x00002D0C 7D0C000004         */ IL_00bc: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002D11 2B7C               */ IL_00c1: br.s IL_013f
			/* 0x00002D13 02                 */ IL_00c3: ldarg.0
			/* 0x00002D14 7B18000004         */ IL_00c4: ldfld class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>7__wrap2' /* 04000018 */
			/* 0x00002D19 6F1300000A         */ IL_00c9: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement>::get_Current() /* 0A000013 */
			/* 0x00002D1E 1304               */ IL_00ce: stloc.s 4
			/* 0x00002D20 1104               */ IL_00d0: ldloc.s 4
			/* 0x00002D22 16                 */ IL_00d2: ldc.i4.0
			/* 0x00002D23 6FAC00000A         */ IL_00d3: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_HorizontalAlignment(valuetype [PresentationFramework]System.Windows.HorizontalAlignment) /* 0A0000AC */
			/* 0x00002D28 1104               */ IL_00d8: ldloc.s 4
			/* 0x00002D2A 16                 */ IL_00da: ldc.i4.0
			/* 0x00002D2B 6FAD00000A         */ IL_00db: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_VerticalAlignment(valuetype [PresentationFramework]System.Windows.VerticalAlignment) /* 0A0000AD */
			/* 0x00002D30 02                 */ IL_00e0: ldarg.0
			/* 0x00002D31 73AE00000A         */ IL_00e1: newobj instance void [PresentationFramework]System.Windows.Controls.Border::.ctor() /* 0A0000AE */
			/* 0x00002D36 25                 */ IL_00e6: dup
			/* 0x00002D37 02                 */ IL_00e7: ldarg.0
			/* 0x00002D38 7C11000004         */ IL_00e8: ldflda valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPaperSize /* 04000011 */
			/* 0x00002D3D 287C00000A         */ IL_00ed: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
			/* 0x00002D42 6F8500000A         */ IL_00f2: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_Width(float64) /* 0A000085 */
			/* 0x00002D47 25                 */ IL_00f7: dup
			/* 0x00002D48 02                 */ IL_00f8: ldarg.0
			/* 0x00002D49 7C11000004         */ IL_00f9: ldflda valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPaperSize /* 04000011 */
			/* 0x00002D4E 287D00000A         */ IL_00fe: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
			/* 0x00002D53 6F8600000A         */ IL_0103: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_Height(float64) /* 0A000086 */
			/* 0x00002D58 25                 */ IL_0108: dup
			/* 0x00002D59 02                 */ IL_0109: ldarg.0
			/* 0x00002D5A 7B17000004         */ IL_010a: ldfld valuetype [PresentationFramework]System.Windows.Thickness AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<borderPadding>5__2' /* 04000017 */
			/* 0x00002D5F 6FAF00000A         */ IL_010f: callvirt instance void [PresentationFramework]System.Windows.Controls.Border::set_Padding(valuetype [PresentationFramework]System.Windows.Thickness) /* 0A0000AF */
			/* 0x00002D64 25                 */ IL_0114: dup
			/* 0x00002D65 1104               */ IL_0115: ldloc.s 4
			/* 0x00002D67 6FB000000A         */ IL_0117: callvirt instance void [PresentationFramework]System.Windows.Controls.Decorator::set_Child(class [PresentationCore]System.Windows.UIElement) /* 0A0000B0 */
			/* 0x00002D6C 25                 */ IL_011c: dup
			/* 0x00002D6D 28B100000A         */ IL_011d: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_White() /* 0A0000B1 */
			/* 0x00002D72 6FB200000A         */ IL_0122: callvirt instance void [PresentationFramework]System.Windows.Controls.Border::set_Background(class [PresentationCore]System.Windows.Media.Brush) /* 0A0000B2 */
			/* 0x00002D77 7D0D000004         */ IL_0127: stfld class [PresentationFramework]System.Windows.FrameworkElement AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>2__current' /* 0400000D */
			/* 0x00002D7C 02                 */ IL_012c: ldarg.0
			/* 0x00002D7D 17                 */ IL_012d: ldc.i4.1
			/* 0x00002D7E 7D0C000004         */ IL_012e: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002D83 17                 */ IL_0133: ldc.i4.1
			/* 0x00002D84 0A                 */ IL_0134: stloc.0
			/* 0x00002D85 DE30               */ IL_0135: leave.s IL_0167
			/* 0x00002D87 02                 */ IL_0137: ldarg.0
			/* 0x00002D88 1FFD               */ IL_0138: ldc.i4.s -3
			/* 0x00002D8A 7D0C000004         */ IL_013a: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002D8F 02                 */ IL_013f: ldarg.0
			/* 0x00002D90 7B18000004         */ IL_0140: ldfld class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>7__wrap2' /* 04000018 */
			/* 0x00002D95 6F1200000A         */ IL_0145: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000012 */
			/* 0x00002D9A 3A74FFFFFF         */ IL_014a: brtrue IL_00c3
			/* 0x00002D9F 02                 */ IL_014f: ldarg.0
			/* 0x00002DA0 2827000006         */ IL_0150: call instance void AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>m__Finally1'() /* 06000027 */
			/* 0x00002DA5 02                 */ IL_0155: ldarg.0
			/* 0x00002DA6 14                 */ IL_0156: ldnull
			/* 0x00002DA7 7D18000004         */ IL_0157: stfld class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>7__wrap2' /* 04000018 */
			/* 0x00002DAC 16                 */ IL_015c: ldc.i4.0
			/* 0x00002DAD 0A                 */ IL_015d: stloc.0
			/* 0x00002DAE DE07               */ IL_015e: leave.s IL_0167
			/* 0x00002DB0 02                 */ IL_0160: ldarg.0
			/* 0x00002DB1 2825000006         */ IL_0161: call instance void AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::System.IDisposable.Dispose() /* 06000025 */
			/* 0x00002DB6 DC                 */ IL_0166: endfinally
			/* 0x00002DB7 06                 */ IL_0167: ldloc.0
			/* 0x00002DB8 2A                 */ IL_0168: ret

			.try IL_0000-IL_0160 fault IL_0160-IL_0167
		} // end of method '<GeneratePrintingElements>d__5'::MoveNext

		.method /* 06000027 */ private hidebysig 
			instance void '<>m__Finally1' () cil managed 
		{
			// Method begins at RVA 0x2de4
			// Header size: 1
			// Code size: 27 (0x1b)
			.maxstack 8

			/* 0x00002DE4 02                 */ IL_0000: ldarg.0
			/* 0x00002DE5 15                 */ IL_0001: ldc.i4.m1
			/* 0x00002DE6 7D0C000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002DEB 02                 */ IL_0007: ldarg.0
			/* 0x00002DEC 7B18000004         */ IL_0008: ldfld class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>7__wrap2' /* 04000018 */
			/* 0x00002DF1 2C0B               */ IL_000d: brfalse.s IL_001a
			/* 0x00002DF3 02                 */ IL_000f: ldarg.0
			/* 0x00002DF4 7B18000004         */ IL_0010: ldfld class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>7__wrap2' /* 04000018 */
			/* 0x00002DF9 6F1100000A         */ IL_0015: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000011 */
			/* 0x00002DFE 2A                 */ IL_001a: ret
		} // end of method '<GeneratePrintingElements>d__5'::'<>m__Finally1'

		.method /* 06000028 */ private final hidebysig specialname newslot virtual 
			instance class [PresentationFramework]System.Windows.FrameworkElement 'System.Collections.Generic.IEnumerator<System.Windows.FrameworkElement>.get_Current' () cil managed 
		{
			.custom /* 0C00001C */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement>::get_Current()
			// Method begins at RVA 0x2e00
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00002E00 02                 */ IL_0000: ldarg.0
			/* 0x00002E01 7B0D000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.FrameworkElement AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>2__current' /* 0400000D */
			/* 0x00002E06 2A                 */ IL_0006: ret
		} // end of method '<GeneratePrintingElements>d__5'::'System.Collections.Generic.IEnumerator<System.Windows.FrameworkElement>.get_Current'

		.method /* 06000029 */ private final hidebysig newslot virtual 
			instance void System.Collections.IEnumerator.Reset () cil managed 
		{
			.custom /* 0C00001D */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance void [mscorlib]System.Collections.IEnumerator::Reset()
			// Method begins at RVA 0x2e08
			// Header size: 1
			// Code size: 6 (0x6)
			.maxstack 8

			/* 0x00002E08 73B300000A         */ IL_0000: newobj instance void [mscorlib]System.NotSupportedException::.ctor() /* 0A0000B3 */
			/* 0x00002E0D 7A                 */ IL_0005: throw
		} // end of method '<GeneratePrintingElements>d__5'::System.Collections.IEnumerator.Reset

		.method /* 0600002A */ private final hidebysig specialname newslot virtual 
			instance object System.Collections.IEnumerator.get_Current () cil managed 
		{
			.custom /* 0C00001E */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance object [mscorlib]System.Collections.IEnumerator::get_Current()
			// Method begins at RVA 0x2e00
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00002E00 02                 */ IL_0000: ldarg.0
			/* 0x00002E01 7B0D000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.FrameworkElement AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>2__current' /* 0400000D */
			/* 0x00002E06 2A                 */ IL_0006: ret
		} // end of method '<GeneratePrintingElements>d__5'::System.Collections.IEnumerator.get_Current

		.method /* 0600002B */ private final hidebysig newslot virtual 
			instance class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> 'System.Collections.Generic.IEnumerable<System.Windows.FrameworkElement>.GetEnumerator' () cil managed 
		{
			.custom /* 0C00001F */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement>::GetEnumerator()
			// Method begins at RVA 0x2e10
			// Header size: 12
			// Code size: 91 (0x5b)
			.maxstack 2
			.locals /* 1100000F */ init (
				[0] class AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'
			)

			/* 0x00002E10 02                 */ IL_0000: ldarg.0
			/* 0x00002E11 7B0C000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002E16 1FFE               */ IL_0006: ldc.i4.s -2
			/* 0x00002E18 3318               */ IL_0008: bne.un.s IL_0022
			/* 0x00002E1A 02                 */ IL_000a: ldarg.0
			/* 0x00002E1B 7B0E000004         */ IL_000b: ldfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>l__initialThreadId' /* 0400000E */
			/* 0x00002E20 28AA00000A         */ IL_0010: call int32 [mscorlib]System.Environment::get_CurrentManagedThreadId() /* 0A0000AA */
			/* 0x00002E25 330B               */ IL_0015: bne.un.s IL_0022
			/* 0x00002E27 02                 */ IL_0017: ldarg.0
			/* 0x00002E28 16                 */ IL_0018: ldc.i4.0
			/* 0x00002E29 7D0C000004         */ IL_0019: stfld int32 AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>1__state' /* 0400000C */
			/* 0x00002E2E 02                 */ IL_001e: ldarg.0
			/* 0x00002E2F 0A                 */ IL_001f: stloc.0
			/* 0x00002E30 2B07               */ IL_0020: br.s IL_0029
			/* 0x00002E32 16                 */ IL_0022: ldc.i4.0
			/* 0x00002E33 7324000006         */ IL_0023: newobj instance void AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::.ctor(int32) /* 06000024 */
			/* 0x00002E38 0A                 */ IL_0028: stloc.0
			/* 0x00002E39 06                 */ IL_0029: ldloc.0
			/* 0x00002E3A 02                 */ IL_002a: ldarg.0
			/* 0x00002E3B 7B16000004         */ IL_002b: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__ps' /* 04000016 */
			/* 0x00002E40 7D15000004         */ IL_0030: stfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::ps /* 04000015 */
			/* 0x00002E45 06                 */ IL_0035: ldloc.0
			/* 0x00002E46 02                 */ IL_0036: ldarg.0
			/* 0x00002E47 7B12000004         */ IL_0037: ldfld valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__adjustedPaperSize' /* 04000012 */
			/* 0x00002E4C 7D11000004         */ IL_003c: stfld valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPaperSize /* 04000011 */
			/* 0x00002E51 06                 */ IL_0041: ldloc.0
			/* 0x00002E52 02                 */ IL_0042: ldarg.0
			/* 0x00002E53 7B10000004         */ IL_0043: ldfld valuetype [WindowsBase]System.Windows.Rect AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__adjustedPrintableArea' /* 04000010 */
			/* 0x00002E58 7D0F000004         */ IL_0048: stfld valuetype [WindowsBase]System.Windows.Rect AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::adjustedPrintableArea /* 0400000F */
			/* 0x00002E5D 06                 */ IL_004d: ldloc.0
			/* 0x00002E5E 02                 */ IL_004e: ldarg.0
			/* 0x00002E5F 7B14000004         */ IL_004f: ldfld valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__margin' /* 04000014 */
			/* 0x00002E64 7D13000004         */ IL_0054: stfld valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::margin /* 04000013 */
			/* 0x00002E69 06                 */ IL_0059: ldloc.0
			/* 0x00002E6A 2A                 */ IL_005a: ret
		} // end of method '<GeneratePrintingElements>d__5'::'System.Collections.Generic.IEnumerable<System.Windows.FrameworkElement>.GetEnumerator'

		.method /* 0600002C */ private final hidebysig newslot virtual 
			instance class [mscorlib]System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator () cil managed 
		{
			.custom /* 0C000020 */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance class [mscorlib]System.Collections.IEnumerator [mscorlib]System.Collections.IEnumerable::GetEnumerator()
			// Method begins at RVA 0x2e77
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00002E77 02                 */ IL_0000: ldarg.0
			/* 0x00002E78 282B000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'System.Collections.Generic.IEnumerable<System.Windows.FrameworkElement>.GetEnumerator'() /* 0600002B */
			/* 0x00002E7D 2A                 */ IL_0006: ret
		} // end of method '<GeneratePrintingElements>d__5'::System.Collections.IEnumerable.GetEnumerator

		// Properties
		.property /* 17000007 */ instance class [PresentationFramework]System.Windows.FrameworkElement 'System.Collections.Generic.IEnumerator<System.Windows.FrameworkElement>.Current'()
		{
			.get instance class [PresentationFramework]System.Windows.FrameworkElement AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'System.Collections.Generic.IEnumerator<System.Windows.FrameworkElement>.get_Current'()
		}
		.property /* 17000008 */ instance object System.Collections.IEnumerator.Current()
		{
			.get instance object AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::System.Collections.IEnumerator.get_Current()
		}

	} // end of class <GeneratePrintingElements>d__5


	// Fields
	.field /* 04000002 */ private static literal float64 MinimumMagin = float64(15)

	// Methods
	.method /* 06000004 */ public hidebysig specialname static 
		class [System.Drawing]System.Drawing.Printing.PageSettings get_DefaultPageSettings () cil managed 
	{
		// Method begins at RVA 0x23c8
		// Header size: 12
		// Code size: 269 (0x10d)
		.maxstack 5
		.locals /* 11000004 */ init (
			[0] class AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0',
			[1] class [System.Drawing]System.Drawing.Printing.PrinterSettings,
			[2] class [System.Drawing]System.Drawing.Printing.PageSettings,
			[3] class [System.Drawing]System.Drawing.Printing.PaperSize,
			[4] class [System.Drawing]System.Drawing.Printing.PaperSource,
			[5] valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>,
			[6] valuetype [PresentationFramework]System.Windows.Thickness
		)

		/* 0x000023C8 7321000006         */ IL_0000: newobj instance void AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::.ctor() /* 06000021 */
		/* 0x000023CD 0A                 */ IL_0005: stloc.0
		/* 0x000023CE 735E00000A         */ IL_0006: newobj instance void [System.Drawing]System.Drawing.Printing.PrinterSettings::.ctor() /* 0A00005E */
		/* 0x000023D3 0B                 */ IL_000b: stloc.1
		/* 0x000023D4 07                 */ IL_000c: ldloc.1
		/* 0x000023D5 735F00000A         */ IL_000d: newobj instance void [System.Drawing]System.Drawing.Printing.PageSettings::.ctor(class [System.Drawing]System.Drawing.Printing.PrinterSettings) /* 0A00005F */
		/* 0x000023DA 0C                 */ IL_0012: stloc.2
		/* 0x000023DB 06                 */ IL_0013: ldloc.0
		/* 0x000023DC 282000000A         */ IL_0014: call class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.ApplicationSettings [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.SystemEnvironment::get_ApplicationSettings() /* 0A000020 */
		/* 0x000023E1 6F2100000A         */ IL_0019: callvirt instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.ApplicationSettings::get_PrintSettings() /* 0A000021 */
		/* 0x000023E6 7D0B000004         */ IL_001e: stfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x000023EB 06                 */ IL_0023: ldloc.0
		/* 0x000023EC 7B0B000004         */ IL_0024: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x000023F1 39DD000000         */ IL_0029: brfalse IL_010b
		/* 0x000023F6 06                 */ IL_002e: ldloc.0
		/* 0x000023F7 7B0B000004         */ IL_002f: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x000023FC 6F6000000A         */ IL_0034: callvirt instance string [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_PaperSize() /* 0A000060 */
		/* 0x00002401 286100000A         */ IL_0039: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000061 */
		/* 0x00002406 2D27               */ IL_003e: brtrue.s IL_0067
		/* 0x00002408 07                 */ IL_0040: ldloc.1
		/* 0x00002409 6F6200000A         */ IL_0041: callvirt instance class [System.Drawing]System.Drawing.Printing.PrinterSettings/PaperSizeCollection [System.Drawing]System.Drawing.Printing.PrinterSettings::get_PaperSizes() /* 0A000062 */
		/* 0x0000240E 280300002B         */ IL_0046: call class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0> [System.Core]System.Linq.Enumerable::OfType<class [System.Drawing]System.Drawing.Printing.PaperSize>(class [mscorlib]System.Collections.IEnumerable) /* 2B000003 */
		/* 0x00002413 06                 */ IL_004b: ldloc.0
		/* 0x00002414 FE0622000006       */ IL_004c: ldftn instance bool AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::'<get_DefaultPageSettings>b__0'(class [System.Drawing]System.Drawing.Printing.PaperSize) /* 06000022 */
		/* 0x0000241A 736400000A         */ IL_0052: newobj instance void class [mscorlib]System.Func`2<class [System.Drawing]System.Drawing.Printing.PaperSize, bool>::.ctor(object, native int) /* 0A000064 */
		/* 0x0000241F 280400002B         */ IL_0057: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class [System.Drawing]System.Drawing.Printing.PaperSize>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000004 */
		/* 0x00002424 0D                 */ IL_005c: stloc.3
		/* 0x00002425 09                 */ IL_005d: ldloc.3
		/* 0x00002426 2C07               */ IL_005e: brfalse.s IL_0067
		/* 0x00002428 08                 */ IL_0060: ldloc.2
		/* 0x00002429 09                 */ IL_0061: ldloc.3
		/* 0x0000242A 6F6600000A         */ IL_0062: callvirt instance void [System.Drawing]System.Drawing.Printing.PageSettings::set_PaperSize(class [System.Drawing]System.Drawing.Printing.PaperSize) /* 0A000066 */
		/* 0x0000242F 06                 */ IL_0067: ldloc.0
		/* 0x00002430 7B0B000004         */ IL_0068: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x00002435 6F6700000A         */ IL_006d: callvirt instance string [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_PaperSource() /* 0A000067 */
		/* 0x0000243A 286100000A         */ IL_0072: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000061 */
		/* 0x0000243F 2D2A               */ IL_0077: brtrue.s IL_00a3
		/* 0x00002441 07                 */ IL_0079: ldloc.1
		/* 0x00002442 6F6800000A         */ IL_007a: callvirt instance class [System.Drawing]System.Drawing.Printing.PrinterSettings/PaperSourceCollection [System.Drawing]System.Drawing.Printing.PrinterSettings::get_PaperSources() /* 0A000068 */
		/* 0x00002447 280500002B         */ IL_007f: call class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0> [System.Core]System.Linq.Enumerable::OfType<class [System.Drawing]System.Drawing.Printing.PaperSource>(class [mscorlib]System.Collections.IEnumerable) /* 2B000005 */
		/* 0x0000244C 06                 */ IL_0084: ldloc.0
		/* 0x0000244D FE0623000006       */ IL_0085: ldftn instance bool AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::'<get_DefaultPageSettings>b__1'(class [System.Drawing]System.Drawing.Printing.PaperSource) /* 06000023 */
		/* 0x00002453 736900000A         */ IL_008b: newobj instance void class [mscorlib]System.Func`2<class [System.Drawing]System.Drawing.Printing.PaperSource, bool>::.ctor(object, native int) /* 0A000069 */
		/* 0x00002458 280600002B         */ IL_0090: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class [System.Drawing]System.Drawing.Printing.PaperSource>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000006 */
		/* 0x0000245D 1304               */ IL_0095: stloc.s 4
		/* 0x0000245F 1104               */ IL_0097: ldloc.s 4
		/* 0x00002461 2C08               */ IL_0099: brfalse.s IL_00a3
		/* 0x00002463 08                 */ IL_009b: ldloc.2
		/* 0x00002464 1104               */ IL_009c: ldloc.s 4
		/* 0x00002466 6F6A00000A         */ IL_009e: callvirt instance void [System.Drawing]System.Drawing.Printing.PageSettings::set_PaperSource(class [System.Drawing]System.Drawing.Printing.PaperSource) /* 0A00006A */
		/* 0x0000246B 08                 */ IL_00a3: ldloc.2
		/* 0x0000246C 06                 */ IL_00a4: ldloc.0
		/* 0x0000246D 7B0B000004         */ IL_00a5: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x00002472 6F6B00000A         */ IL_00aa: callvirt instance bool [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_IsLandscape() /* 0A00006B */
		/* 0x00002477 6F6C00000A         */ IL_00af: callvirt instance void [System.Drawing]System.Drawing.Printing.PageSettings::set_Landscape(bool) /* 0A00006C */
		/* 0x0000247C 06                 */ IL_00b4: ldloc.0
		/* 0x0000247D 7B0B000004         */ IL_00b5: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x00002482 6F6D00000A         */ IL_00ba: callvirt instance valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_Margin() /* 0A00006D */
		/* 0x00002487 1305               */ IL_00bf: stloc.s 5
		/* 0x00002489 1205               */ IL_00c1: ldloca.s 5
		/* 0x0000248B 286E00000A         */ IL_00c3: call instance bool valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::get_HasValue() /* 0A00006E */
		/* 0x00002490 2C41               */ IL_00c8: brfalse.s IL_010b
		/* 0x00002492 06                 */ IL_00ca: ldloc.0
		/* 0x00002493 7B0B000004         */ IL_00cb: ldfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings AspenTech.AspenPlus.Printing.PrintHelper/'<>c__DisplayClass2_0'::pps /* 0400000B */
		/* 0x00002498 6F6D00000A         */ IL_00d0: callvirt instance valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.PrintPageSettings::get_Margin() /* 0A00006D */
		/* 0x0000249D 1305               */ IL_00d5: stloc.s 5
		/* 0x0000249F 1205               */ IL_00d7: ldloca.s 5
		/* 0x000024A1 286F00000A         */ IL_00d9: call instance !0 valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::get_Value() /* 0A00006F */
		/* 0x000024A6 1306               */ IL_00de: stloc.s 6
		/* 0x000024A8 08                 */ IL_00e0: ldloc.2
		/* 0x000024A9 1206               */ IL_00e1: ldloca.s 6
		/* 0x000024AB 287000000A         */ IL_00e3: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Left() /* 0A000070 */
		/* 0x000024B0 69                 */ IL_00e8: conv.i4
		/* 0x000024B1 1206               */ IL_00e9: ldloca.s 6
		/* 0x000024B3 287100000A         */ IL_00eb: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Right() /* 0A000071 */
		/* 0x000024B8 69                 */ IL_00f0: conv.i4
		/* 0x000024B9 1206               */ IL_00f1: ldloca.s 6
		/* 0x000024BB 287200000A         */ IL_00f3: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Top() /* 0A000072 */
		/* 0x000024C0 69                 */ IL_00f8: conv.i4
		/* 0x000024C1 1206               */ IL_00f9: ldloca.s 6
		/* 0x000024C3 287300000A         */ IL_00fb: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Bottom() /* 0A000073 */
		/* 0x000024C8 69                 */ IL_0100: conv.i4
		/* 0x000024C9 737400000A         */ IL_0101: newobj instance void [System.Drawing]System.Drawing.Printing.Margins::.ctor(int32, int32, int32, int32) /* 0A000074 */
		/* 0x000024CE 6F7500000A         */ IL_0106: callvirt instance void [System.Drawing]System.Drawing.Printing.PageSettings::set_Margins(class [System.Drawing]System.Drawing.Printing.Margins) /* 0A000075 */
		/* 0x000024D3 08                 */ IL_010b: ldloc.2
		/* 0x000024D4 2A                 */ IL_010c: ret
	} // end of method PrintHelper::get_DefaultPageSettings

	.method /* 06000005 */ public hidebysig static 
		class [ReachFramework]System.Printing.PageMediaSize ConvertPaperSizeToPageMediaSize (
			class [System.Drawing]System.Drawing.Printing.PaperSize paperSize,
			class [mscorlib]System.Collections.Generic.IEnumerable`1<class [ReachFramework]System.Printing.PageMediaSize> pageMediaSizeCapability
		) cil managed 
	{
		// Method begins at RVA 0x24e4
		// Header size: 12
		// Code size: 180 (0xb4)
		.maxstack 2
		.locals /* 11000005 */ init (
			[0] float64,
			[1] float64,
			[2] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [ReachFramework]System.Printing.PageMediaSize>,
			[3] class [ReachFramework]System.Printing.PageMediaSize,
			[4] valuetype [mscorlib]System.Nullable`1<float64>,
			[5] class [ReachFramework]System.Printing.PageMediaSize
		)

		/* 0x000024E4 02                 */ IL_0000: ldarg.0
		/* 0x000024E5 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x000024E7 7225000070         */ IL_0003: ldstr "paperSize" /* 70000025 */
		/* 0x000024EC 733500000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x000024F1 7A                 */ IL_000d: throw
		/* 0x000024F2 03                 */ IL_000e: ldarg.1
		/* 0x000024F3 2D0B               */ IL_000f: brtrue.s IL_001c
		/* 0x000024F5 7239000070         */ IL_0011: ldstr "pageMediaSizeCapability" /* 70000039 */
		/* 0x000024FA 733500000A         */ IL_0016: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x000024FF 7A                 */ IL_001b: throw
		/* 0x00002500 02                 */ IL_001c: ldarg.0
		/* 0x00002501 6F3C00000A         */ IL_001d: callvirt instance int32 [System.Drawing]System.Drawing.Printing.PaperSize::get_Width() /* 0A00003C */
		/* 0x00002506 6C                 */ IL_0022: conv.r8
		/* 0x00002507 2809000006         */ IL_0023: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x0000250C 0A                 */ IL_0028: stloc.0
		/* 0x0000250D 02                 */ IL_0029: ldarg.0
		/* 0x0000250E 6F3D00000A         */ IL_002a: callvirt instance int32 [System.Drawing]System.Drawing.Printing.PaperSize::get_Height() /* 0A00003D */
		/* 0x00002513 6C                 */ IL_002f: conv.r8
		/* 0x00002514 2809000006         */ IL_0030: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x00002519 0B                 */ IL_0035: stloc.1
		/* 0x0000251A 03                 */ IL_0036: ldarg.1
		/* 0x0000251B 6F7600000A         */ IL_0037: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [ReachFramework]System.Printing.PageMediaSize>::GetEnumerator() /* 0A000076 */
		/* 0x00002520 0C                 */ IL_003c: stloc.2
		/* 0x00002521 2B5C               */ IL_003d: br.s IL_009b
		/* 0x00002523 08                 */ IL_003f: ldloc.2
		/* 0x00002524 6F7700000A         */ IL_0040: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [ReachFramework]System.Printing.PageMediaSize>::get_Current() /* 0A000077 */
		/* 0x00002529 0D                 */ IL_0045: stloc.3
		/* 0x0000252A 09                 */ IL_0046: ldloc.3
		/* 0x0000252B 6F7800000A         */ IL_0047: callvirt instance valuetype [mscorlib]System.Nullable`1<float64> [ReachFramework]System.Printing.PageMediaSize::get_Width() /* 0A000078 */
		/* 0x00002530 1304               */ IL_004c: stloc.s 4
		/* 0x00002532 1204               */ IL_004e: ldloca.s 4
		/* 0x00002534 287900000A         */ IL_0050: call instance bool valuetype [mscorlib]System.Nullable`1<float64>::get_HasValue() /* 0A000079 */
		/* 0x00002539 2C44               */ IL_0055: brfalse.s IL_009b
		/* 0x0000253B 09                 */ IL_0057: ldloc.3
		/* 0x0000253C 6F7A00000A         */ IL_0058: callvirt instance valuetype [mscorlib]System.Nullable`1<float64> [ReachFramework]System.Printing.PageMediaSize::get_Height() /* 0A00007A */
		/* 0x00002541 1304               */ IL_005d: stloc.s 4
		/* 0x00002543 1204               */ IL_005f: ldloca.s 4
		/* 0x00002545 287900000A         */ IL_0061: call instance bool valuetype [mscorlib]System.Nullable`1<float64>::get_HasValue() /* 0A000079 */
		/* 0x0000254A 2C33               */ IL_0066: brfalse.s IL_009b
		/* 0x0000254C 09                 */ IL_0068: ldloc.3
		/* 0x0000254D 6F7800000A         */ IL_0069: callvirt instance valuetype [mscorlib]System.Nullable`1<float64> [ReachFramework]System.Printing.PageMediaSize::get_Width() /* 0A000078 */
		/* 0x00002552 1304               */ IL_006e: stloc.s 4
		/* 0x00002554 1204               */ IL_0070: ldloca.s 4
		/* 0x00002556 287B00000A         */ IL_0072: call instance !0 valuetype [mscorlib]System.Nullable`1<float64>::get_Value() /* 0A00007B */
		/* 0x0000255B 06                 */ IL_0077: ldloc.0
		/* 0x0000255C 280B000006         */ IL_0078: call bool AspenTech.AspenPlus.Printing.PrintHelper::IsRoughlyEqual(float64, float64) /* 0600000B */
		/* 0x00002561 2C1C               */ IL_007d: brfalse.s IL_009b
		/* 0x00002563 09                 */ IL_007f: ldloc.3
		/* 0x00002564 6F7A00000A         */ IL_0080: callvirt instance valuetype [mscorlib]System.Nullable`1<float64> [ReachFramework]System.Printing.PageMediaSize::get_Height() /* 0A00007A */
		/* 0x00002569 1304               */ IL_0085: stloc.s 4
		/* 0x0000256B 1204               */ IL_0087: ldloca.s 4
		/* 0x0000256D 287B00000A         */ IL_0089: call instance !0 valuetype [mscorlib]System.Nullable`1<float64>::get_Value() /* 0A00007B */
		/* 0x00002572 07                 */ IL_008e: ldloc.1
		/* 0x00002573 280B000006         */ IL_008f: call bool AspenTech.AspenPlus.Printing.PrintHelper::IsRoughlyEqual(float64, float64) /* 0600000B */
		/* 0x00002578 2C05               */ IL_0094: brfalse.s IL_009b
		/* 0x0000257A 09                 */ IL_0096: ldloc.3
		/* 0x0000257B 1305               */ IL_0097: stloc.s 5
		/* 0x0000257D DE16               */ IL_0099: leave.s IL_00b1
		/* 0x0000257F 08                 */ IL_009b: ldloc.2
		/* 0x00002580 6F1200000A         */ IL_009c: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000012 */
		/* 0x00002585 2D9C               */ IL_00a1: brtrue.s IL_003f
		/* 0x00002587 DE0A               */ IL_00a3: leave.s IL_00af
		/* 0x00002589 08                 */ IL_00a5: ldloc.2
		/* 0x0000258A 2C06               */ IL_00a6: brfalse.s IL_00ae
		/* 0x0000258C 08                 */ IL_00a8: ldloc.2
		/* 0x0000258D 6F1100000A         */ IL_00a9: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000011 */
		/* 0x00002592 DC                 */ IL_00ae: endfinally
		/* 0x00002593 14                 */ IL_00af: ldnull
		/* 0x00002594 2A                 */ IL_00b0: ret
		/* 0x00002595 1105               */ IL_00b1: ldloc.s 5
		/* 0x00002597 2A                 */ IL_00b3: ret

		.try IL_003d-IL_00a5 finally IL_00a5-IL_00af
	} // end of method PrintHelper::ConvertPaperSizeToPageMediaSize

	.method /* 06000006 */ public hidebysig static 
		class [PresentationFramework]System.Windows.Documents.FixedDocument CreateFixedDocument (
			class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport ps,
			valuetype [WindowsBase]System.Windows.Rect printableArea,
			valuetype [WindowsBase]System.Windows.Size paperSize,
			valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> margin,
			bool landscape
		) cil managed 
	{
		// Method begins at RVA 0x25b4
		// Header size: 12
		// Code size: 223 (0xdf)
		.maxstack 4
		.locals /* 11000006 */ init (
			[0] valuetype [WindowsBase]System.Windows.Size,
			[1] valuetype [WindowsBase]System.Windows.Rect,
			[2] class [PresentationFramework]System.Windows.Documents.FixedDocument,
			[3] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement>,
			[4] class [PresentationFramework]System.Windows.FrameworkElement,
			[5] class [PresentationFramework]System.Windows.Documents.FixedPage
		)

		/* 0x000025B4 0E04               */ IL_0000: ldarg.s landscape
		/* 0x000025B6 2D15               */ IL_0002: brtrue.s IL_0019
		/* 0x000025B8 0F02               */ IL_0004: ldarga.s paperSize
		/* 0x000025BA 287C00000A         */ IL_0006: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
		/* 0x000025BF 0F02               */ IL_000b: ldarga.s paperSize
		/* 0x000025C1 287D00000A         */ IL_000d: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
		/* 0x000025C6 733E00000A         */ IL_0012: newobj instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00003E */
		/* 0x000025CB 2B13               */ IL_0017: br.s IL_002c
		/* 0x000025CD 0F02               */ IL_0019: ldarga.s paperSize
		/* 0x000025CF 287D00000A         */ IL_001b: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
		/* 0x000025D4 0F02               */ IL_0020: ldarga.s paperSize
		/* 0x000025D6 287C00000A         */ IL_0022: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
		/* 0x000025DB 733E00000A         */ IL_0027: newobj instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00003E */
		/* 0x000025E0 0A                 */ IL_002c: stloc.0
		/* 0x000025E1 0E04               */ IL_002d: ldarg.s landscape
		/* 0x000025E3 2D03               */ IL_002f: brtrue.s IL_0034
		/* 0x000025E5 03                 */ IL_0031: ldarg.1
		/* 0x000025E6 2B21               */ IL_0032: br.s IL_0055
		/* 0x000025E8 0F01               */ IL_0034: ldarga.s printableArea
		/* 0x000025EA 287E00000A         */ IL_0036: call instance float64 [WindowsBase]System.Windows.Rect::get_Top() /* 0A00007E */
		/* 0x000025EF 0F01               */ IL_003b: ldarga.s printableArea
		/* 0x000025F1 287F00000A         */ IL_003d: call instance float64 [WindowsBase]System.Windows.Rect::get_Left() /* 0A00007F */
		/* 0x000025F6 0F01               */ IL_0042: ldarga.s printableArea
		/* 0x000025F8 288000000A         */ IL_0044: call instance float64 [WindowsBase]System.Windows.Rect::get_Height() /* 0A000080 */
		/* 0x000025FD 0F01               */ IL_0049: ldarga.s printableArea
		/* 0x000025FF 288100000A         */ IL_004b: call instance float64 [WindowsBase]System.Windows.Rect::get_Width() /* 0A000081 */
		/* 0x00002604 734500000A         */ IL_0050: newobj instance void [WindowsBase]System.Windows.Rect::.ctor(float64, float64, float64, float64) /* 0A000045 */
		/* 0x00002609 0B                 */ IL_0055: stloc.1
		/* 0x0000260A 738200000A         */ IL_0056: newobj instance void [PresentationFramework]System.Windows.Documents.FixedDocument::.ctor() /* 0A000082 */
		/* 0x0000260F 0C                 */ IL_005b: stloc.2
		/* 0x00002610 08                 */ IL_005c: ldloc.2
		/* 0x00002611 6F5B00000A         */ IL_005d: callvirt instance class [PresentationCore]System.Windows.Documents.DocumentPaginator [PresentationFramework]System.Windows.Documents.FixedDocument::get_DocumentPaginator() /* 0A00005B */
		/* 0x00002616 06                 */ IL_0062: ldloc.0
		/* 0x00002617 6F8300000A         */ IL_0063: callvirt instance void [PresentationCore]System.Windows.Documents.DocumentPaginator::set_PageSize(valuetype [WindowsBase]System.Windows.Size) /* 0A000083 */
		/* 0x0000261C 02                 */ IL_0068: ldarg.0
		/* 0x0000261D 06                 */ IL_0069: ldloc.0
		/* 0x0000261E 07                 */ IL_006a: ldloc.1
		/* 0x0000261F 05                 */ IL_006b: ldarg.3
		/* 0x00002620 2807000006         */ IL_006c: call class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement> AspenTech.AspenPlus.Printing.PrintHelper::GeneratePrintingElements(class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport, valuetype [WindowsBase]System.Windows.Size, valuetype [WindowsBase]System.Windows.Rect, valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>) /* 06000007 */
		/* 0x00002625 6F1600000A         */ IL_0071: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement>::GetEnumerator() /* 0A000016 */
		/* 0x0000262A 0D                 */ IL_0076: stloc.3
		/* 0x0000262B 2B50               */ IL_0077: br.s IL_00c9
		/* 0x0000262D 09                 */ IL_0079: ldloc.3
		/* 0x0000262E 6F1300000A         */ IL_007a: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [PresentationFramework]System.Windows.FrameworkElement>::get_Current() /* 0A000013 */
		/* 0x00002633 1304               */ IL_007f: stloc.s 4
		/* 0x00002635 738400000A         */ IL_0081: newobj instance void [PresentationFramework]System.Windows.Documents.FixedPage::.ctor() /* 0A000084 */
		/* 0x0000263A 25                 */ IL_0086: dup
		/* 0x0000263B 1200               */ IL_0087: ldloca.s 0
		/* 0x0000263D 287C00000A         */ IL_0089: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
		/* 0x00002642 6F8500000A         */ IL_008e: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_Width(float64) /* 0A000085 */
		/* 0x00002647 25                 */ IL_0093: dup
		/* 0x00002648 1200               */ IL_0094: ldloca.s 0
		/* 0x0000264A 287D00000A         */ IL_0096: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
		/* 0x0000264F 6F8600000A         */ IL_009b: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_Height(float64) /* 0A000086 */
		/* 0x00002654 25                 */ IL_00a0: dup
		/* 0x00002655 6F8700000A         */ IL_00a1: callvirt instance class [PresentationFramework]System.Windows.Controls.UIElementCollection [PresentationFramework]System.Windows.Documents.FixedPage::get_Children() /* 0A000087 */
		/* 0x0000265A 1104               */ IL_00a6: ldloc.s 4
		/* 0x0000265C 6F8800000A         */ IL_00a8: callvirt instance int32 [PresentationFramework]System.Windows.Controls.UIElementCollection::Add(class [PresentationCore]System.Windows.UIElement) /* 0A000088 */
		/* 0x00002661 26                 */ IL_00ad: pop
		/* 0x00002662 1305               */ IL_00ae: stloc.s 5
		/* 0x00002664 08                 */ IL_00b0: ldloc.2
		/* 0x00002665 6F8900000A         */ IL_00b1: callvirt instance class [PresentationFramework]System.Windows.Documents.PageContentCollection [PresentationFramework]System.Windows.Documents.FixedDocument::get_Pages() /* 0A000089 */
		/* 0x0000266A 738A00000A         */ IL_00b6: newobj instance void [PresentationFramework]System.Windows.Documents.PageContent::.ctor() /* 0A00008A */
		/* 0x0000266F 25                 */ IL_00bb: dup
		/* 0x00002670 1105               */ IL_00bc: ldloc.s 5
		/* 0x00002672 6F8B00000A         */ IL_00be: callvirt instance void [PresentationFramework]System.Windows.Documents.PageContent::set_Child(class [PresentationFramework]System.Windows.Documents.FixedPage) /* 0A00008B */
		/* 0x00002677 6F8C00000A         */ IL_00c3: callvirt instance int32 [PresentationFramework]System.Windows.Documents.PageContentCollection::Add(class [PresentationFramework]System.Windows.Documents.PageContent) /* 0A00008C */
		/* 0x0000267C 26                 */ IL_00c8: pop
		/* 0x0000267D 09                 */ IL_00c9: ldloc.3
		/* 0x0000267E 6F1200000A         */ IL_00ca: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000012 */
		/* 0x00002683 2DA8               */ IL_00cf: brtrue.s IL_0079
		/* 0x00002685 DE0A               */ IL_00d1: leave.s IL_00dd
		/* 0x00002687 09                 */ IL_00d3: ldloc.3
		/* 0x00002688 2C06               */ IL_00d4: brfalse.s IL_00dc
		/* 0x0000268A 09                 */ IL_00d6: ldloc.3
		/* 0x0000268B 6F1100000A         */ IL_00d7: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000011 */
		/* 0x00002690 DC                 */ IL_00dc: endfinally
		/* 0x00002691 08                 */ IL_00dd: ldloc.2
		/* 0x00002692 2A                 */ IL_00de: ret

		.try IL_0077-IL_00d3 finally IL_00d3-IL_00dd
	} // end of method PrintHelper::CreateFixedDocument

	.method /* 06000007 */ private hidebysig static 
		class [mscorlib]System.Collections.Generic.IEnumerable`1<class [PresentationFramework]System.Windows.FrameworkElement> GeneratePrintingElements (
			class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport ps,
			valuetype [WindowsBase]System.Windows.Size adjustedPaperSize,
			valuetype [WindowsBase]System.Windows.Rect adjustedPrintableArea,
			valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> margin
		) cil managed 
	{
		.custom /* 0C00000F */ instance void [mscorlib]System.Runtime.CompilerServices.IteratorStateMachineAttribute::.ctor(class [mscorlib]System.Type) = (
			01 00 47 41 73 70 65 6e 54 65 63 68 2e 41 73 70
			65 6e 50 6c 75 73 2e 50 72 69 6e 74 69 6e 67 2e
			50 72 69 6e 74 48 65 6c 70 65 72 2b 3c 47 65 6e
			65 72 61 74 65 50 72 69 6e 74 69 6e 67 45 6c 65
			6d 65 6e 74 73 3e 64 5f 5f 35 00 00
		)
		// Method begins at RVA 0x26b0
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x000026B0 1FFE               */ IL_0000: ldc.i4.s -2
		/* 0x000026B2 7324000006         */ IL_0002: newobj instance void AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::.ctor(int32) /* 06000024 */
		/* 0x000026B7 25                 */ IL_0007: dup
		/* 0x000026B8 02                 */ IL_0008: ldarg.0
		/* 0x000026B9 7D16000004         */ IL_0009: stfld class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__ps' /* 04000016 */
		/* 0x000026BE 25                 */ IL_000e: dup
		/* 0x000026BF 03                 */ IL_000f: ldarg.1
		/* 0x000026C0 7D12000004         */ IL_0010: stfld valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__adjustedPaperSize' /* 04000012 */
		/* 0x000026C5 25                 */ IL_0015: dup
		/* 0x000026C6 04                 */ IL_0016: ldarg.2
		/* 0x000026C7 7D10000004         */ IL_0017: stfld valuetype [WindowsBase]System.Windows.Rect AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__adjustedPrintableArea' /* 04000010 */
		/* 0x000026CC 25                 */ IL_001c: dup
		/* 0x000026CD 05                 */ IL_001d: ldarg.3
		/* 0x000026CE 7D14000004         */ IL_001e: stfld valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> AspenTech.AspenPlus.Printing.PrintHelper/'<GeneratePrintingElements>d__5'::'<>3__margin' /* 04000014 */
		/* 0x000026D3 2A                 */ IL_0023: ret
	} // end of method PrintHelper::GeneratePrintingElements

	.method /* 06000008 */ private hidebysig static 
		valuetype [PresentationFramework]System.Windows.Thickness CalculateBorderPadding (
			valuetype [WindowsBase]System.Windows.Rect adjustedPrintableArea,
			valuetype [WindowsBase]System.Windows.Size adjustedPaperSize,
			valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness> margin
		) cil managed 
	{
		// Method begins at RVA 0x26d8
		// Header size: 12
		// Code size: 373 (0x175)
		.maxstack 4
		.locals /* 11000007 */ init (
			[0] float64,
			[1] float64,
			[2] float64,
			[3] float64,
			[4] float64,
			[5] float64,
			[6] float64,
			[7] float64,
			[8] valuetype [PresentationFramework]System.Windows.Thickness,
			[9] float64,
			[10] float64,
			[11] float64,
			[12] float64
		)

		/* 0x000026D8 0F00               */ IL_0000: ldarga.s adjustedPrintableArea
		/* 0x000026DA 287F00000A         */ IL_0002: call instance float64 [WindowsBase]System.Windows.Rect::get_Left() /* 0A00007F */
		/* 0x000026DF 288D00000A         */ IL_0007: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x000026E4 2D09               */ IL_000c: brtrue.s IL_0017
		/* 0x000026E6 0F00               */ IL_000e: ldarga.s adjustedPrintableArea
		/* 0x000026E8 287F00000A         */ IL_0010: call instance float64 [WindowsBase]System.Windows.Rect::get_Left() /* 0A00007F */
		/* 0x000026ED 2B09               */ IL_0015: br.s IL_0020
		/* 0x000026EF 230000000000000000 */ IL_0017: ldc.r8 0.0
		/* 0x000026F8 0A                 */ IL_0020: stloc.0
		/* 0x000026F9 0F00               */ IL_0021: ldarga.s adjustedPrintableArea
		/* 0x000026FB 287E00000A         */ IL_0023: call instance float64 [WindowsBase]System.Windows.Rect::get_Top() /* 0A00007E */
		/* 0x00002700 288D00000A         */ IL_0028: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x00002705 2D09               */ IL_002d: brtrue.s IL_0038
		/* 0x00002707 0F00               */ IL_002f: ldarga.s adjustedPrintableArea
		/* 0x00002709 287E00000A         */ IL_0031: call instance float64 [WindowsBase]System.Windows.Rect::get_Top() /* 0A00007E */
		/* 0x0000270E 2B09               */ IL_0036: br.s IL_0041
		/* 0x00002710 230000000000000000 */ IL_0038: ldc.r8 0.0
		/* 0x00002719 0B                 */ IL_0041: stloc.1
		/* 0x0000271A 0F00               */ IL_0042: ldarga.s adjustedPrintableArea
		/* 0x0000271C 288100000A         */ IL_0044: call instance float64 [WindowsBase]System.Windows.Rect::get_Width() /* 0A000081 */
		/* 0x00002721 288D00000A         */ IL_0049: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x00002726 2D09               */ IL_004e: brtrue.s IL_0059
		/* 0x00002728 0F00               */ IL_0050: ldarga.s adjustedPrintableArea
		/* 0x0000272A 288100000A         */ IL_0052: call instance float64 [WindowsBase]System.Windows.Rect::get_Width() /* 0A000081 */
		/* 0x0000272F 2B07               */ IL_0057: br.s IL_0060
		/* 0x00002731 0F01               */ IL_0059: ldarga.s adjustedPaperSize
		/* 0x00002733 287C00000A         */ IL_005b: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
		/* 0x00002738 0C                 */ IL_0060: stloc.2
		/* 0x00002739 0F00               */ IL_0061: ldarga.s adjustedPrintableArea
		/* 0x0000273B 288000000A         */ IL_0063: call instance float64 [WindowsBase]System.Windows.Rect::get_Height() /* 0A000080 */
		/* 0x00002740 288D00000A         */ IL_0068: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x00002745 2D09               */ IL_006d: brtrue.s IL_0078
		/* 0x00002747 0F00               */ IL_006f: ldarga.s adjustedPrintableArea
		/* 0x00002749 288000000A         */ IL_0071: call instance float64 [WindowsBase]System.Windows.Rect::get_Height() /* 0A000080 */
		/* 0x0000274E 2B07               */ IL_0076: br.s IL_007f
		/* 0x00002750 0F01               */ IL_0078: ldarga.s adjustedPaperSize
		/* 0x00002752 287D00000A         */ IL_007a: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
		/* 0x00002757 0D                 */ IL_007f: stloc.3
		/* 0x00002758 06                 */ IL_0080: ldloc.0
		/* 0x00002759 230000000000002E40 */ IL_0081: ldc.r8 15
		/* 0x00002762 288E00000A         */ IL_008a: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x00002767 1304               */ IL_008f: stloc.s 4
		/* 0x00002769 07                 */ IL_0091: ldloc.1
		/* 0x0000276A 230000000000002E40 */ IL_0092: ldc.r8 15
		/* 0x00002773 288E00000A         */ IL_009b: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x00002778 1305               */ IL_00a0: stloc.s 5
		/* 0x0000277A 0F01               */ IL_00a2: ldarga.s adjustedPaperSize
		/* 0x0000277C 287C00000A         */ IL_00a4: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
		/* 0x00002781 08                 */ IL_00a9: ldloc.2
		/* 0x00002782 59                 */ IL_00aa: sub
		/* 0x00002783 06                 */ IL_00ab: ldloc.0
		/* 0x00002784 59                 */ IL_00ac: sub
		/* 0x00002785 230000000000002E40 */ IL_00ad: ldc.r8 15
		/* 0x0000278E 288E00000A         */ IL_00b6: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x00002793 1306               */ IL_00bb: stloc.s 6
		/* 0x00002795 0F01               */ IL_00bd: ldarga.s adjustedPaperSize
		/* 0x00002797 287D00000A         */ IL_00bf: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
		/* 0x0000279C 09                 */ IL_00c4: ldloc.3
		/* 0x0000279D 59                 */ IL_00c5: sub
		/* 0x0000279E 07                 */ IL_00c6: ldloc.1
		/* 0x0000279F 59                 */ IL_00c7: sub
		/* 0x000027A0 230000000000002E40 */ IL_00c8: ldc.r8 15
		/* 0x000027A9 288E00000A         */ IL_00d1: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x000027AE 1307               */ IL_00d6: stloc.s 7
		/* 0x000027B0 0F02               */ IL_00d8: ldarga.s margin
		/* 0x000027B2 286E00000A         */ IL_00da: call instance bool valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::get_HasValue() /* 0A00006E */
		/* 0x000027B7 3983000000         */ IL_00df: brfalse IL_0167
		/* 0x000027BC 0F02               */ IL_00e4: ldarga.s margin
		/* 0x000027BE 286F00000A         */ IL_00e6: call instance !0 valuetype [mscorlib]System.Nullable`1<valuetype [PresentationFramework]System.Windows.Thickness>::get_Value() /* 0A00006F */
		/* 0x000027C3 1308               */ IL_00eb: stloc.s 8
		/* 0x000027C5 1104               */ IL_00ed: ldloc.s 4
		/* 0x000027C7 1208               */ IL_00ef: ldloca.s 8
		/* 0x000027C9 287000000A         */ IL_00f1: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Left() /* 0A000070 */
		/* 0x000027CE 288E00000A         */ IL_00f6: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x000027D3 1309               */ IL_00fb: stloc.s 9
		/* 0x000027D5 1105               */ IL_00fd: ldloc.s 5
		/* 0x000027D7 1208               */ IL_00ff: ldloca.s 8
		/* 0x000027D9 287200000A         */ IL_0101: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Top() /* 0A000072 */
		/* 0x000027DE 288E00000A         */ IL_0106: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x000027E3 130A               */ IL_010b: stloc.s 10
		/* 0x000027E5 1106               */ IL_010d: ldloc.s 6
		/* 0x000027E7 1208               */ IL_010f: ldloca.s 8
		/* 0x000027E9 287100000A         */ IL_0111: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Right() /* 0A000071 */
		/* 0x000027EE 288E00000A         */ IL_0116: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x000027F3 130B               */ IL_011b: stloc.s 11
		/* 0x000027F5 1107               */ IL_011d: ldloc.s 7
		/* 0x000027F7 1208               */ IL_011f: ldloca.s 8
		/* 0x000027F9 287300000A         */ IL_0121: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Bottom() /* 0A000073 */
		/* 0x000027FE 288E00000A         */ IL_0126: call float64 [mscorlib]System.Math::Max(float64, float64) /* 0A00008E */
		/* 0x00002803 130C               */ IL_012b: stloc.s 12
		/* 0x00002805 1109               */ IL_012d: ldloc.s 9
		/* 0x00002807 110B               */ IL_012f: ldloc.s 11
		/* 0x00002809 58                 */ IL_0131: add
		/* 0x0000280A 0F01               */ IL_0132: ldarga.s adjustedPaperSize
		/* 0x0000280C 287C00000A         */ IL_0134: call instance float64 [WindowsBase]System.Windows.Size::get_Width() /* 0A00007C */
		/* 0x00002811 3708               */ IL_0139: blt.un.s IL_0143
		/* 0x00002813 1104               */ IL_013b: ldloc.s 4
		/* 0x00002815 1309               */ IL_013d: stloc.s 9
		/* 0x00002817 1106               */ IL_013f: ldloc.s 6
		/* 0x00002819 130B               */ IL_0141: stloc.s 11
		/* 0x0000281B 110A               */ IL_0143: ldloc.s 10
		/* 0x0000281D 110C               */ IL_0145: ldloc.s 12
		/* 0x0000281F 58                 */ IL_0147: add
		/* 0x00002820 0F01               */ IL_0148: ldarga.s adjustedPaperSize
		/* 0x00002822 287D00000A         */ IL_014a: call instance float64 [WindowsBase]System.Windows.Size::get_Height() /* 0A00007D */
		/* 0x00002827 3708               */ IL_014f: blt.un.s IL_0159
		/* 0x00002829 1105               */ IL_0151: ldloc.s 5
		/* 0x0000282B 130A               */ IL_0153: stloc.s 10
		/* 0x0000282D 1107               */ IL_0155: ldloc.s 7
		/* 0x0000282F 130C               */ IL_0157: stloc.s 12
		/* 0x00002831 1109               */ IL_0159: ldloc.s 9
		/* 0x00002833 110A               */ IL_015b: ldloc.s 10
		/* 0x00002835 110B               */ IL_015d: ldloc.s 11
		/* 0x00002837 110C               */ IL_015f: ldloc.s 12
		/* 0x00002839 733200000A         */ IL_0161: newobj instance void [PresentationFramework]System.Windows.Thickness::.ctor(float64, float64, float64, float64) /* 0A000032 */
		/* 0x0000283E 2A                 */ IL_0166: ret
		/* 0x0000283F 1104               */ IL_0167: ldloc.s 4
		/* 0x00002841 1105               */ IL_0169: ldloc.s 5
		/* 0x00002843 1106               */ IL_016b: ldloc.s 6
		/* 0x00002845 1107               */ IL_016d: ldloc.s 7
		/* 0x00002847 733200000A         */ IL_016f: newobj instance void [PresentationFramework]System.Windows.Thickness::.ctor(float64, float64, float64, float64) /* 0A000032 */
		/* 0x0000284C 2A                 */ IL_0174: ret
	} // end of method PrintHelper::CalculateBorderPadding

	.method /* 06000009 */ public hidebysig static 
		float64 ConvertDotsToPixels (
			float64 dots
		) cil managed 
	{
		// Method begins at RVA 0x2859
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00002859 02                 */ IL_0000: ldarg.0
		/* 0x0000285A 23B81E85EB51B8EE3F */ IL_0001: ldc.r8 0.96
		/* 0x00002863 5A                 */ IL_000a: mul
		/* 0x00002864 2A                 */ IL_000b: ret
	} // end of method PrintHelper::ConvertDotsToPixels

	.method /* 0600000A */ public hidebysig static 
		valuetype [PresentationFramework]System.Windows.Thickness ConvertMargins (
			class [System.Drawing]System.Drawing.Printing.Margins mgs
		) cil managed 
	{
		// Method begins at RVA 0x2866
		// Header size: 1
		// Code size: 54 (0x36)
		.maxstack 8

		/* 0x00002866 02                 */ IL_0000: ldarg.0
		/* 0x00002867 6F2E00000A         */ IL_0001: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Left() /* 0A00002E */
		/* 0x0000286C 6C                 */ IL_0006: conv.r8
		/* 0x0000286D 2809000006         */ IL_0007: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x00002872 02                 */ IL_000c: ldarg.0
		/* 0x00002873 6F2F00000A         */ IL_000d: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Top() /* 0A00002F */
		/* 0x00002878 6C                 */ IL_0012: conv.r8
		/* 0x00002879 2809000006         */ IL_0013: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x0000287E 02                 */ IL_0018: ldarg.0
		/* 0x0000287F 6F3000000A         */ IL_0019: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Right() /* 0A000030 */
		/* 0x00002884 6C                 */ IL_001e: conv.r8
		/* 0x00002885 2809000006         */ IL_001f: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x0000288A 02                 */ IL_0024: ldarg.0
		/* 0x0000288B 6F3100000A         */ IL_0025: callvirt instance int32 [System.Drawing]System.Drawing.Printing.Margins::get_Bottom() /* 0A000031 */
		/* 0x00002890 6C                 */ IL_002a: conv.r8
		/* 0x00002891 2809000006         */ IL_002b: call float64 AspenTech.AspenPlus.Printing.PrintHelper::ConvertDotsToPixels(float64) /* 06000009 */
		/* 0x00002896 733200000A         */ IL_0030: newobj instance void [PresentationFramework]System.Windows.Thickness::.ctor(float64, float64, float64, float64) /* 0A000032 */
		/* 0x0000289B 2A                 */ IL_0035: ret
	} // end of method PrintHelper::ConvertMargins

	.method /* 0600000B */ private hidebysig static 
		bool IsRoughlyEqual (
			float64 x,
			float64 y
		) cil managed 
	{
		// Method begins at RVA 0x289d
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x0000289D 02                 */ IL_0000: ldarg.0
		/* 0x0000289E 03                 */ IL_0001: ldarg.1
		/* 0x0000289F 59                 */ IL_0002: sub
		/* 0x000028A0 288F00000A         */ IL_0003: call float64 [mscorlib]System.Math::Abs(float64) /* 0A00008F */
		/* 0x000028A5 23000000000000F03F */ IL_0008: ldc.r8 1
		/* 0x000028AE FE03               */ IL_0011: cgt.un
		/* 0x000028B0 16                 */ IL_0013: ldc.i4.0
		/* 0x000028B1 FE01               */ IL_0014: ceq
		/* 0x000028B3 2A                 */ IL_0016: ret
	} // end of method PrintHelper::IsRoughlyEqual

	.method /* 0600000C */ private hidebysig static 
		valuetype [PresentationFramework]System.Windows.Thickness FixThickness (
			valuetype [PresentationFramework]System.Windows.Thickness tn
		) cil managed 
	{
		// Method begins at RVA 0x28b8
		// Header size: 12
		// Code size: 180 (0xb4)
		.maxstack 2
		.locals /* 11000008 */ init (
			[0] valuetype [PresentationFramework]System.Windows.Thickness
		)

		/* 0x000028B8 02                 */ IL_0000: ldarg.0
		/* 0x000028B9 0A                 */ IL_0001: stloc.0
		/* 0x000028BA 0F00               */ IL_0002: ldarga.s tn
		/* 0x000028BC 287000000A         */ IL_0004: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Left() /* 0A000070 */
		/* 0x000028C1 289000000A         */ IL_0009: call bool [mscorlib]System.Double::IsInfinity(float64) /* 0A000090 */
		/* 0x000028C6 2D0E               */ IL_000e: brtrue.s IL_001e
		/* 0x000028C8 0F00               */ IL_0010: ldarga.s tn
		/* 0x000028CA 287000000A         */ IL_0012: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Left() /* 0A000070 */
		/* 0x000028CF 288D00000A         */ IL_0017: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x000028D4 2C10               */ IL_001c: brfalse.s IL_002e
		/* 0x000028D6 1200               */ IL_001e: ldloca.s 0
		/* 0x000028D8 230000000000000000 */ IL_0020: ldc.r8 0.0
		/* 0x000028E1 289100000A         */ IL_0029: call instance void [PresentationFramework]System.Windows.Thickness::set_Left(float64) /* 0A000091 */
		/* 0x000028E6 0F00               */ IL_002e: ldarga.s tn
		/* 0x000028E8 287100000A         */ IL_0030: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Right() /* 0A000071 */
		/* 0x000028ED 289000000A         */ IL_0035: call bool [mscorlib]System.Double::IsInfinity(float64) /* 0A000090 */
		/* 0x000028F2 2D0E               */ IL_003a: brtrue.s IL_004a
		/* 0x000028F4 0F00               */ IL_003c: ldarga.s tn
		/* 0x000028F6 287100000A         */ IL_003e: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Right() /* 0A000071 */
		/* 0x000028FB 288D00000A         */ IL_0043: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x00002900 2C10               */ IL_0048: brfalse.s IL_005a
		/* 0x00002902 1200               */ IL_004a: ldloca.s 0
		/* 0x00002904 230000000000000000 */ IL_004c: ldc.r8 0.0
		/* 0x0000290D 289200000A         */ IL_0055: call instance void [PresentationFramework]System.Windows.Thickness::set_Right(float64) /* 0A000092 */
		/* 0x00002912 0F00               */ IL_005a: ldarga.s tn
		/* 0x00002914 287200000A         */ IL_005c: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Top() /* 0A000072 */
		/* 0x00002919 289000000A         */ IL_0061: call bool [mscorlib]System.Double::IsInfinity(float64) /* 0A000090 */
		/* 0x0000291E 2D0E               */ IL_0066: brtrue.s IL_0076
		/* 0x00002920 0F00               */ IL_0068: ldarga.s tn
		/* 0x00002922 287200000A         */ IL_006a: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Top() /* 0A000072 */
		/* 0x00002927 288D00000A         */ IL_006f: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x0000292C 2C10               */ IL_0074: brfalse.s IL_0086
		/* 0x0000292E 1200               */ IL_0076: ldloca.s 0
		/* 0x00002930 230000000000000000 */ IL_0078: ldc.r8 0.0
		/* 0x00002939 289300000A         */ IL_0081: call instance void [PresentationFramework]System.Windows.Thickness::set_Top(float64) /* 0A000093 */
		/* 0x0000293E 0F00               */ IL_0086: ldarga.s tn
		/* 0x00002940 287300000A         */ IL_0088: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Bottom() /* 0A000073 */
		/* 0x00002945 289000000A         */ IL_008d: call bool [mscorlib]System.Double::IsInfinity(float64) /* 0A000090 */
		/* 0x0000294A 2D0E               */ IL_0092: brtrue.s IL_00a2
		/* 0x0000294C 0F00               */ IL_0094: ldarga.s tn
		/* 0x0000294E 287300000A         */ IL_0096: call instance float64 [PresentationFramework]System.Windows.Thickness::get_Bottom() /* 0A000073 */
		/* 0x00002953 288D00000A         */ IL_009b: call bool [mscorlib]System.Double::IsNaN(float64) /* 0A00008D */
		/* 0x00002958 2C10               */ IL_00a0: brfalse.s IL_00b2
		/* 0x0000295A 1200               */ IL_00a2: ldloca.s 0
		/* 0x0000295C 230000000000000000 */ IL_00a4: ldc.r8 0.0
		/* 0x00002965 289400000A         */ IL_00ad: call instance void [PresentationFramework]System.Windows.Thickness::set_Bottom(float64) /* 0A000094 */
		/* 0x0000296A 06                 */ IL_00b2: ldloc.0
		/* 0x0000296B 2A                 */ IL_00b3: ret
	} // end of method PrintHelper::FixThickness

	// Properties
	.property /* 17000001 */ class [System.Drawing]System.Drawing.Printing.PageSettings DefaultPageSettings()
	{
		.get class [System.Drawing]System.Drawing.Printing.PageSettings AspenTech.AspenPlus.Printing.PrintHelper::get_DefaultPageSettings()
	}

} // end of class AspenTech.AspenPlus.Printing.PrintHelper

.class /* 02000004 */ public auto ansi beforefieldinit AspenTech.AspenPlus.Printing.PrintingModule
	extends [mscorlib]System.Object
	implements [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Modularity.IModule
{
	// Fields
	.field /* 04000003 */ private initonly class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer _unityContainer

	// Methods
	.method /* 0600000D */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer unityContainer
		) cil managed 
	{
		// Method begins at RVA 0x2978
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002978 02                 */ IL_0000: ldarg.0
		/* 0x00002979 289500000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000095 */
		/* 0x0000297E 03                 */ IL_0006: ldarg.1
		/* 0x0000297F 2D0B               */ IL_0007: brtrue.s IL_0014
		/* 0x00002981 7207000070         */ IL_0009: ldstr "unityContainer" /* 70000007 */
		/* 0x00002986 733500000A         */ IL_000e: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x0000298B 7A                 */ IL_0013: throw
		/* 0x0000298C 02                 */ IL_0014: ldarg.0
		/* 0x0000298D 03                 */ IL_0015: ldarg.1
		/* 0x0000298E 7D03000004         */ IL_0016: stfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AspenTech.AspenPlus.Printing.PrintingModule::_unityContainer /* 04000003 */
		/* 0x00002993 2A                 */ IL_001b: ret
	} // end of method PrintingModule::.ctor

	.method /* 0600000E */ public final hidebysig newslot virtual 
		instance void Initialize () cil managed 
	{
		// Method begins at RVA 0x2995
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x00002995 02                 */ IL_0000: ldarg.0
		/* 0x00002996 7B03000004         */ IL_0001: ldfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AspenTech.AspenPlus.Printing.PrintingModule::_unityContainer /* 04000003 */
		/* 0x0000299B 739600000A         */ IL_0006: newobj instance void [Microsoft.Practices.Unity]Microsoft.Practices.Unity.ContainerControlledLifetimeManager::.ctor() /* 0A000096 */
		/* 0x000029A0 280700002B         */ IL_000b: call !!0[] [mscorlib]System.Array::Empty<class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.InjectionMember>() /* 2B000007 */
		/* 0x000029A5 280800002B         */ IL_0010: call class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer [Microsoft.Practices.Unity]Microsoft.Practices.Unity.UnityContainerExtensions::RegisterType<class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintPresenter, class AspenTech.AspenPlus.Printing.PrintPresenter>(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.LifetimeManager, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.InjectionMember[]) /* 2B000008 */
		/* 0x000029AA 26                 */ IL_0015: pop
		/* 0x000029AB 2A                 */ IL_0016: ret
	} // end of method PrintingModule::Initialize

} // end of class AspenTech.AspenPlus.Printing.PrintingModule

.class /* 02000005 */ public auto ansi beforefieldinit AspenTech.AspenPlus.Printing.PrintPresenter
	extends [mscorlib]System.Object
	implements [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintPresenter
{
	// Fields
	.field /* 04000004 */ private initonly class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer _unityContainer

	// Methods
	.method /* 0600000F */ private hidebysig specialname 
		instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport get_ActiveScreenToPrint () cil managed 
	{
		// Method begins at RVA 0x29b0
		// Header size: 12
		// Code size: 44 (0x2c)
		.maxstack 2
		.locals /* 11000009 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellApplication,
			[1] class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow
		)

		/* 0x000029B0 02                 */ IL_0000: ldarg.0
		/* 0x000029B1 7B04000004         */ IL_0001: ldfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AspenTech.AspenPlus.Printing.PrintPresenter::_unityContainer /* 04000004 */
		/* 0x000029B6 280100002B         */ IL_0006: call !!0[] [mscorlib]System.Array::Empty<class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.ResolverOverride>() /* 2B000001 */
		/* 0x000029BB 280200002B         */ IL_000b: call !!0 [Microsoft.Practices.Unity]Microsoft.Practices.Unity.UnityContainerExtensions::Resolve<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellApplication>(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.ResolverOverride[]) /* 2B000002 */
		/* 0x000029C0 0A                 */ IL_0010: stloc.0
		/* 0x000029C1 06                 */ IL_0011: ldloc.0
		/* 0x000029C2 2C16               */ IL_0012: brfalse.s IL_002a
		/* 0x000029C4 06                 */ IL_0014: ldloc.0
		/* 0x000029C5 6F3800000A         */ IL_0015: callvirt instance class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellApplication::get_ActiveWindow() /* 0A000038 */
		/* 0x000029CA 0B                 */ IL_001a: stloc.1
		/* 0x000029CB 07                 */ IL_001b: ldloc.1
		/* 0x000029CC 2C0C               */ IL_001c: brfalse.s IL_002a
		/* 0x000029CE 07                 */ IL_001e: ldloc.1
		/* 0x000029CF 6F9800000A         */ IL_001f: callvirt instance class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow::get_ActiveDocumentScreen() /* 0A000098 */
		/* 0x000029D4 7515000001         */ IL_0024: isinst [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport /* 01000015 */
		/* 0x000029D9 2A                 */ IL_0029: ret
		/* 0x000029DA 14                 */ IL_002a: ldnull
		/* 0x000029DB 2A                 */ IL_002b: ret
	} // end of method PrintPresenter::get_ActiveScreenToPrint

	.method /* 06000010 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer unityContainer
		) cil managed 
	{
		// Method begins at RVA 0x29e8
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000029E8 02                 */ IL_0000: ldarg.0
		/* 0x000029E9 289500000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000095 */
		/* 0x000029EE 03                 */ IL_0006: ldarg.1
		/* 0x000029EF 2D0B               */ IL_0007: brtrue.s IL_0014
		/* 0x000029F1 7207000070         */ IL_0009: ldstr "unityContainer" /* 70000007 */
		/* 0x000029F6 733500000A         */ IL_000e: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x000029FB 7A                 */ IL_0013: throw
		/* 0x000029FC 02                 */ IL_0014: ldarg.0
		/* 0x000029FD 03                 */ IL_0015: ldarg.1
		/* 0x000029FE 7D04000004         */ IL_0016: stfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AspenTech.AspenPlus.Printing.PrintPresenter::_unityContainer /* 04000004 */
		/* 0x00002A03 2A                 */ IL_001b: ret
	} // end of method PrintPresenter::.ctor

	.method /* 06000011 */ public final hidebysig specialname newslot virtual 
		instance bool get_CanPrint () cil managed 
	{
		// Method begins at RVA 0x2a08
		// Header size: 12
		// Code size: 19 (0x13)
		.maxstack 1
		.locals /* 1100000A */ init (
			[0] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport
		)

		/* 0x00002A08 02                 */ IL_0000: ldarg.0
		/* 0x00002A09 280F000006         */ IL_0001: call instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintPresenter::get_ActiveScreenToPrint() /* 0600000F */
		/* 0x00002A0E 0A                 */ IL_0006: stloc.0
		/* 0x00002A0F 06                 */ IL_0007: ldloc.0
		/* 0x00002A10 2C07               */ IL_0008: brfalse.s IL_0011
		/* 0x00002A12 06                 */ IL_000a: ldloc.0
		/* 0x00002A13 6F9900000A         */ IL_000b: callvirt instance bool [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport::get_CanPrint() /* 0A000099 */
		/* 0x00002A18 2A                 */ IL_0010: ret
		/* 0x00002A19 16                 */ IL_0011: ldc.i4.0
		/* 0x00002A1A 2A                 */ IL_0012: ret
	} // end of method PrintPresenter::get_CanPrint

	.method /* 06000012 */ public final hidebysig specialname newslot virtual 
		instance bool get_CanPrintPreview () cil managed 
	{
		// Method begins at RVA 0x2a28
		// Header size: 12
		// Code size: 19 (0x13)
		.maxstack 1
		.locals /* 1100000A */ init (
			[0] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport
		)

		/* 0x00002A28 02                 */ IL_0000: ldarg.0
		/* 0x00002A29 280F000006         */ IL_0001: call instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintPresenter::get_ActiveScreenToPrint() /* 0600000F */
		/* 0x00002A2E 0A                 */ IL_0006: stloc.0
		/* 0x00002A2F 06                 */ IL_0007: ldloc.0
		/* 0x00002A30 2C07               */ IL_0008: brfalse.s IL_0011
		/* 0x00002A32 06                 */ IL_000a: ldloc.0
		/* 0x00002A33 6F9A00000A         */ IL_000b: callvirt instance bool [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport::get_CanPrintPreview() /* 0A00009A */
		/* 0x00002A38 2A                 */ IL_0010: ret
		/* 0x00002A39 16                 */ IL_0011: ldc.i4.0
		/* 0x00002A3A 2A                 */ IL_0012: ret
	} // end of method PrintPresenter::get_CanPrintPreview

	.method /* 06000013 */ public final hidebysig specialname newslot virtual 
		instance bool get_CanPrintSetup () cil managed 
	{
		// Method begins at RVA 0x2a47
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002A47 02                 */ IL_0000: ldarg.0
		/* 0x00002A48 2811000006         */ IL_0001: call instance bool AspenTech.AspenPlus.Printing.PrintPresenter::get_CanPrint() /* 06000011 */
		/* 0x00002A4D 2A                 */ IL_0006: ret
	} // end of method PrintPresenter::get_CanPrintSetup

	.method /* 06000014 */ public final hidebysig newslot virtual 
		instance void DoPrint () cil managed 
	{
		// Method begins at RVA 0x2a50
		// Header size: 12
		// Code size: 25 (0x19)
		.maxstack 1
		.locals /* 1100000A */ init (
			[0] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport
		)

		/* 0x00002A50 02                 */ IL_0000: ldarg.0
		/* 0x00002A51 280F000006         */ IL_0001: call instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintPresenter::get_ActiveScreenToPrint() /* 0600000F */
		/* 0x00002A56 0A                 */ IL_0006: stloc.0
		/* 0x00002A57 06                 */ IL_0007: ldloc.0
		/* 0x00002A58 2C0E               */ IL_0008: brfalse.s IL_0018
		/* 0x00002A5A 06                 */ IL_000a: ldloc.0
		/* 0x00002A5B 6F9B00000A         */ IL_000b: callvirt instance bool [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport::DoCustomPrint() /* 0A00009B */
		/* 0x00002A60 2D06               */ IL_0010: brtrue.s IL_0018
		/* 0x00002A62 06                 */ IL_0012: ldloc.0
		/* 0x00002A63 2803000006         */ IL_0013: call void AspenTech.AspenPlus.Printing.GenericPrinting::DoGenericPrint(class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport) /* 06000003 */
		/* 0x00002A68 2A                 */ IL_0018: ret
	} // end of method PrintPresenter::DoPrint

	.method /* 06000015 */ public final hidebysig newslot virtual 
		instance void DoPrintPreview () cil managed 
	{
		// Method begins at RVA 0x2a78
		// Header size: 12
		// Code size: 31 (0x1f)
		.maxstack 2
		.locals /* 1100000A */ init (
			[0] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport
		)

		/* 0x00002A78 02                 */ IL_0000: ldarg.0
		/* 0x00002A79 280F000006         */ IL_0001: call instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintPresenter::get_ActiveScreenToPrint() /* 0600000F */
		/* 0x00002A7E 0A                 */ IL_0006: stloc.0
		/* 0x00002A7F 06                 */ IL_0007: ldloc.0
		/* 0x00002A80 2C14               */ IL_0008: brfalse.s IL_001e
		/* 0x00002A82 06                 */ IL_000a: ldloc.0
		/* 0x00002A83 6F9C00000A         */ IL_000b: callvirt instance bool [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport::DoCustomPrintPreview() /* 0A00009C */
		/* 0x00002A88 2D0C               */ IL_0010: brtrue.s IL_001e
		/* 0x00002A8A 06                 */ IL_0012: ldloc.0
		/* 0x00002A8B 02                 */ IL_0013: ldarg.0
		/* 0x00002A8C 7B04000004         */ IL_0014: ldfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AspenTech.AspenPlus.Printing.PrintPresenter::_unityContainer /* 04000004 */
		/* 0x00002A91 2802000006         */ IL_0019: call void AspenTech.AspenPlus.Printing.GenericPrinting::DoGenericPrintPreview(class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer) /* 06000002 */
		/* 0x00002A96 2A                 */ IL_001e: ret
	} // end of method PrintPresenter::DoPrintPreview

	.method /* 06000016 */ public final hidebysig newslot virtual 
		instance void DoPrintSetup () cil managed 
	{
		// Method begins at RVA 0x2aa4
		// Header size: 12
		// Code size: 25 (0x19)
		.maxstack 1
		.locals /* 1100000A */ init (
			[0] class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport
		)

		/* 0x00002AA4 02                 */ IL_0000: ldarg.0
		/* 0x00002AA5 280F000006         */ IL_0001: call instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintPresenter::get_ActiveScreenToPrint() /* 0600000F */
		/* 0x00002AAA 0A                 */ IL_0006: stloc.0
		/* 0x00002AAB 06                 */ IL_0007: ldloc.0
		/* 0x00002AAC 2C09               */ IL_0008: brfalse.s IL_0013
		/* 0x00002AAE 06                 */ IL_000a: ldloc.0
		/* 0x00002AAF 6F9D00000A         */ IL_000b: callvirt instance bool [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport::DoCustomPrintSetup() /* 0A00009D */
		/* 0x00002AB4 2C01               */ IL_0010: brfalse.s IL_0013
		/* 0x00002AB6 2A                 */ IL_0012: ret
		/* 0x00002AB7 2801000006         */ IL_0013: call void AspenTech.AspenPlus.Printing.GenericPrinting::DoGenericPrintSetup() /* 06000001 */
		/* 0x00002ABC 2A                 */ IL_0018: ret
	} // end of method PrintPresenter::DoPrintSetup

	// Properties
	.property /* 17000002 */ instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport ActiveScreenToPrint()
	{
		.get instance class [AspenTech.AspenPlus.Infrastructure]AspenTech.AspenPlus.Infrastructure.IPrintSupport AspenTech.AspenPlus.Printing.PrintPresenter::get_ActiveScreenToPrint()
	}
	.property /* 17000003 */ instance bool CanPrint()
	{
		.get instance bool AspenTech.AspenPlus.Printing.PrintPresenter::get_CanPrint()
	}
	.property /* 17000004 */ instance bool CanPrintPreview()
	{
		.get instance bool AspenTech.AspenPlus.Printing.PrintPresenter::get_CanPrintPreview()
	}
	.property /* 17000005 */ instance bool CanPrintSetup()
	{
		.get instance bool AspenTech.AspenPlus.Printing.PrintPresenter::get_CanPrintSetup()
	}

} // end of class AspenTech.AspenPlus.Printing.PrintPresenter

.class /* 02000006 */ public auto ansi beforefieldinit AspenTech.AspenPlus.Printing.PrintPreviewWindow
	extends [PresentationFramework]System.Windows.Window
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 04000005 */ private initonly class [PresentationFramework]System.Windows.Documents.FixedDocument _document
	.field /* 04000006 */ assembly class [PresentationFramework]System.Windows.Controls.DocumentViewer theDocumentViewer
	.field /* 04000007 */ private bool _contentLoaded

	// Methods
	.method /* 06000017 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class [PresentationFramework]System.Windows.Documents.FixedDocument document
		) cil managed 
	{
		// Method begins at RVA 0x2ac9
		// Header size: 1
		// Code size: 34 (0x22)
		.maxstack 8

		/* 0x00002AC9 02                 */ IL_0000: ldarg.0
		/* 0x00002ACA 289E00000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Window::.ctor() /* 0A00009E */
		/* 0x00002ACF 03                 */ IL_0006: ldarg.1
		/* 0x00002AD0 2D0B               */ IL_0007: brtrue.s IL_0014
		/* 0x00002AD2 7269000070         */ IL_0009: ldstr "document" /* 70000069 */
		/* 0x00002AD7 733500000A         */ IL_000e: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000035 */
		/* 0x00002ADC 7A                 */ IL_0013: throw
		/* 0x00002ADD 02                 */ IL_0014: ldarg.0
		/* 0x00002ADE 03                 */ IL_0015: ldarg.1
		/* 0x00002ADF 7D05000004         */ IL_0016: stfld class [PresentationFramework]System.Windows.Documents.FixedDocument AspenTech.AspenPlus.Printing.PrintPreviewWindow::_document /* 04000005 */
		/* 0x00002AE4 02                 */ IL_001b: ldarg.0
		/* 0x00002AE5 2819000006         */ IL_001c: call instance void AspenTech.AspenPlus.Printing.PrintPreviewWindow::InitializeComponent() /* 06000019 */
		/* 0x00002AEA 2A                 */ IL_0021: ret
	} // end of method PrintPreviewWindow::.ctor

	.method /* 06000018 */ family hidebysig virtual 
		instance void OnInitialized (
			class [mscorlib]System.EventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2aec
		// Header size: 12
		// Code size: 68 (0x44)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [PresentationFramework]System.Windows.FrameworkElement
		)

		/* 0x00002AEC 02                 */ IL_0000: ldarg.0
		/* 0x00002AED 7B06000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.DocumentViewer AspenTech.AspenPlus.Printing.PrintPreviewWindow::theDocumentViewer /* 04000006 */
		/* 0x00002AF2 02                 */ IL_0006: ldarg.0
		/* 0x00002AF3 7B05000004         */ IL_0007: ldfld class [PresentationFramework]System.Windows.Documents.FixedDocument AspenTech.AspenPlus.Printing.PrintPreviewWindow::_document /* 04000005 */
		/* 0x00002AF8 6F9F00000A         */ IL_000c: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.DocumentViewerBase::set_Document(class [PresentationCore]System.Windows.Documents.IDocumentPaginatorSource) /* 0A00009F */
		/* 0x00002AFD 02                 */ IL_0011: ldarg.0
		/* 0x00002AFE 7B06000004         */ IL_0012: ldfld class [PresentationFramework]System.Windows.Controls.DocumentViewer AspenTech.AspenPlus.Printing.PrintPreviewWindow::theDocumentViewer /* 04000006 */
		/* 0x00002B03 6FA000000A         */ IL_0017: callvirt instance class [PresentationFramework]System.Windows.Controls.ControlTemplate [PresentationFramework]System.Windows.Controls.Control::get_Template() /* 0A0000A0 */
		/* 0x00002B08 727B000070         */ IL_001c: ldstr "PART_FindToolBarHost" /* 7000007B */
		/* 0x00002B0D 02                 */ IL_0021: ldarg.0
		/* 0x00002B0E 7B06000004         */ IL_0022: ldfld class [PresentationFramework]System.Windows.Controls.DocumentViewer AspenTech.AspenPlus.Printing.PrintPreviewWindow::theDocumentViewer /* 04000006 */
		/* 0x00002B13 6FA100000A         */ IL_0027: callvirt instance object [PresentationFramework]System.Windows.FrameworkTemplate::FindName(string, class [PresentationFramework]System.Windows.FrameworkElement) /* 0A0000A1 */
		/* 0x00002B18 752E000001         */ IL_002c: isinst [PresentationFramework]System.Windows.FrameworkElement /* 0100002E */
		/* 0x00002B1D 0A                 */ IL_0031: stloc.0
		/* 0x00002B1E 06                 */ IL_0032: ldloc.0
		/* 0x00002B1F 2C07               */ IL_0033: brfalse.s IL_003c
		/* 0x00002B21 06                 */ IL_0035: ldloc.0
		/* 0x00002B22 18                 */ IL_0036: ldc.i4.2
		/* 0x00002B23 6FA200000A         */ IL_0037: callvirt instance void [PresentationCore]System.Windows.UIElement::set_Visibility(valuetype [PresentationCore]System.Windows.Visibility) /* 0A0000A2 */
		/* 0x00002B28 02                 */ IL_003c: ldarg.0
		/* 0x00002B29 03                 */ IL_003d: ldarg.1
		/* 0x00002B2A 28A300000A         */ IL_003e: call instance void [PresentationFramework]System.Windows.FrameworkElement::OnInitialized(class [mscorlib]System.EventArgs) /* 0A0000A3 */
		/* 0x00002B2F 2A                 */ IL_0043: ret
	} // end of method PrintPreviewWindow::OnInitialized

	.method /* 06000019 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000015 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000016 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x2b3c
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 1100000C */ init (
			[0] class [System]System.Uri
		)

		/* 0x00002B3C 02                 */ IL_0000: ldarg.0
		/* 0x00002B3D 7B07000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.Printing.PrintPreviewWindow::_contentLoaded /* 04000007 */
		/* 0x00002B42 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00002B44 2A                 */ IL_0008: ret
		/* 0x00002B45 02                 */ IL_0009: ldarg.0
		/* 0x00002B46 17                 */ IL_000a: ldc.i4.1
		/* 0x00002B47 7D07000004         */ IL_000b: stfld bool AspenTech.AspenPlus.Printing.PrintPreviewWindow::_contentLoaded /* 04000007 */
		/* 0x00002B4C 72A5000070         */ IL_0010: ldstr "/AspenTech.AspenPlus.Printing;component/printpreviewwindow.xaml" /* 700000A5 */
		/* 0x00002B51 18                 */ IL_0015: ldc.i4.2
		/* 0x00002B52 73A400000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A0000A4 */
		/* 0x00002B57 0A                 */ IL_001b: stloc.0
		/* 0x00002B58 02                 */ IL_001c: ldarg.0
		/* 0x00002B59 06                 */ IL_001d: ldloc.0
		/* 0x00002B5A 28A500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A0000A5 */
		/* 0x00002B5F 2A                 */ IL_0023: ret
	} // end of method PrintPreviewWindow::InitializeComponent

	.method /* 0600001A */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000017 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000018 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000019 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x2b6c
		// Header size: 1
		// Code size: 25 (0x19)
		.maxstack 8

		/* 0x00002B6C 03                 */ IL_0000: ldarg.1
		/* 0x00002B6D 17                 */ IL_0001: ldc.i4.1
		/* 0x00002B6E 330D               */ IL_0002: bne.un.s IL_0011
		/* 0x00002B70 02                 */ IL_0004: ldarg.0
		/* 0x00002B71 04                 */ IL_0005: ldarg.2
		/* 0x00002B72 743B000001         */ IL_0006: castclass [PresentationFramework]System.Windows.Controls.DocumentViewer /* 0100003B */
		/* 0x00002B77 7D06000004         */ IL_000b: stfld class [PresentationFramework]System.Windows.Controls.DocumentViewer AspenTech.AspenPlus.Printing.PrintPreviewWindow::theDocumentViewer /* 04000006 */
		/* 0x00002B7C 2A                 */ IL_0010: ret
		/* 0x00002B7D 02                 */ IL_0011: ldarg.0
		/* 0x00002B7E 17                 */ IL_0012: ldc.i4.1
		/* 0x00002B7F 7D07000004         */ IL_0013: stfld bool AspenTech.AspenPlus.Printing.PrintPreviewWindow::_contentLoaded /* 04000007 */
		/* 0x00002B84 2A                 */ IL_0018: ret
	} // end of method PrintPreviewWindow::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.Printing.PrintPreviewWindow

.class /* 02000007 */ private auto ansi sealed beforefieldinit AspenTech.AspenPlus.Printing.Properties.Settings
	extends [System]System.Configuration.ApplicationSettingsBase
{
	.custom /* 0C000010 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000011 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 4b 4d 69 63 72 6f 73 6f 66 74 2e 56 69 73
		75 61 6c 53 74 75 64 69 6f 2e 45 64 69 74 6f 72
		73 2e 53 65 74 74 69 6e 67 73 44 65 73 69 67 6e
		65 72 2e 53 65 74 74 69 6e 67 73 53 69 6e 67 6c
		65 46 69 6c 65 47 65 6e 65 72 61 74 6f 72 09 31
		36 2e 31 30 2e 30 2e 30 00 00
	)
	// Fields
	.field /* 04000008 */ private static class AspenTech.AspenPlus.Printing.Properties.Settings defaultInstance

	// Methods
	.method /* 0600001B */ public hidebysig specialname static 
		class AspenTech.AspenPlus.Printing.Properties.Settings get_Default () cil managed 
	{
		// Method begins at RVA 0x2b86
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00002B86 7E08000004         */ IL_0000: ldsfld class AspenTech.AspenPlus.Printing.Properties.Settings AspenTech.AspenPlus.Printing.Properties.Settings::defaultInstance /* 04000008 */
		/* 0x00002B8B 2A                 */ IL_0005: ret
	} // end of method Settings::get_Default

	.method /* 0600001C */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2b8d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002B8D 02                 */ IL_0000: ldarg.0
		/* 0x00002B8E 28A600000A         */ IL_0001: call instance void [System]System.Configuration.ApplicationSettingsBase::.ctor() /* 0A0000A6 */
		/* 0x00002B93 2A                 */ IL_0006: ret
	} // end of method Settings::.ctor

	.method /* 0600001D */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2b95
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002B95 731C000006         */ IL_0000: newobj instance void AspenTech.AspenPlus.Printing.Properties.Settings::.ctor() /* 0600001C */
		/* 0x00002B9A 28A700000A         */ IL_0005: call class [System]System.Configuration.SettingsBase [System]System.Configuration.SettingsBase::Synchronized(class [System]System.Configuration.SettingsBase) /* 0A0000A7 */
		/* 0x00002B9F 7407000002         */ IL_000a: castclass AspenTech.AspenPlus.Printing.Properties.Settings /* 02000007 */
		/* 0x00002BA4 8008000004         */ IL_000f: stsfld class AspenTech.AspenPlus.Printing.Properties.Settings AspenTech.AspenPlus.Printing.Properties.Settings::defaultInstance /* 04000008 */
		/* 0x00002BA9 2A                 */ IL_0014: ret
	} // end of method Settings::.cctor

	// Properties
	.property /* 17000006 */ class AspenTech.AspenPlus.Printing.Properties.Settings Default()
	{
		.get class AspenTech.AspenPlus.Printing.Properties.Settings AspenTech.AspenPlus.Printing.Properties.Settings::get_Default()
	}

} // end of class AspenTech.AspenPlus.Printing.Properties.Settings

