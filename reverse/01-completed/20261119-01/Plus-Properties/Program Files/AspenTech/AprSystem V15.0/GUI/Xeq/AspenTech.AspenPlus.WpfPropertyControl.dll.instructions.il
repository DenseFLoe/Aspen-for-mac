.module AspenTech.AspenPlus.WpfPropertyControl.dll
// MVID: {771B489E-05BE-48D8-9EAA-35088A4C82BA}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi abstract sealed beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000001 */ private static initonly class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> _imageSources

	// Methods
	.method /* 06000001 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Circle () cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002050 7201000070         */ IL_0000: ldstr "Circle.bmp" /* 70000001 */
		/* 0x00002055 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000205A 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Circle

	.method /* 06000002 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_CircleFill () cil managed 
	{
		// Method begins at RVA 0x205c
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x0000205C 7217000070         */ IL_0000: ldstr "CircleFill.bmp" /* 70000017 */
		/* 0x00002061 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002066 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_CircleFill

	.method /* 06000003 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_CrisCross () cil managed 
	{
		// Method begins at RVA 0x2068
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002068 7235000070         */ IL_0000: ldstr "CrisCross.bmp" /* 70000035 */
		/* 0x0000206D 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002072 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_CrisCross

	.method /* 06000004 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Cross () cil managed 
	{
		// Method begins at RVA 0x2074
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002074 7251000070         */ IL_0000: ldstr "Cross.bmp" /* 70000051 */
		/* 0x00002079 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000207E 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Cross

	.method /* 06000005 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Dashed () cil managed 
	{
		// Method begins at RVA 0x2080
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002080 7265000070         */ IL_0000: ldstr "Dashed.bmp" /* 70000065 */
		/* 0x00002085 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000208A 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Dashed

	.method /* 06000006 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_DiagLeft () cil managed 
	{
		// Method begins at RVA 0x208c
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x0000208C 727B000070         */ IL_0000: ldstr "DiagLeft.bmp" /* 7000007B */
		/* 0x00002091 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002096 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_DiagLeft

	.method /* 06000007 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_DiagRight () cil managed 
	{
		// Method begins at RVA 0x2098
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002098 7295000070         */ IL_0000: ldstr "DiagRight.bmp" /* 70000095 */
		/* 0x0000209D 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020A2 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_DiagRight

	.method /* 06000008 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Diamond () cil managed 
	{
		// Method begins at RVA 0x20a4
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020A4 72B1000070         */ IL_0000: ldstr "Diamond.bmp" /* 700000B1 */
		/* 0x000020A9 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020AE 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Diamond

	.method /* 06000009 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_DiamondFill () cil managed 
	{
		// Method begins at RVA 0x20b0
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020B0 72C9000070         */ IL_0000: ldstr "DiamondFill.bmp" /* 700000C9 */
		/* 0x000020B5 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020BA 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_DiamondFill

	.method /* 0600000A */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_DotDashed () cil managed 
	{
		// Method begins at RVA 0x20bc
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020BC 72E9000070         */ IL_0000: ldstr "Dot-Dashed.bmp" /* 700000E9 */
		/* 0x000020C1 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020C6 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_DotDashed

	.method /* 0600000B */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Dot1 () cil managed 
	{
		// Method begins at RVA 0x20c8
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020C8 7207010070         */ IL_0000: ldstr "Dot1.bmp" /* 70000107 */
		/* 0x000020CD 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020D2 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Dot1

	.method /* 0600000C */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Dot2 () cil managed 
	{
		// Method begins at RVA 0x20d4
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020D4 7219010070         */ IL_0000: ldstr "Dot2.bmp" /* 70000119 */
		/* 0x000020D9 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020DE 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Dot2

	.method /* 0600000D */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Dot3 () cil managed 
	{
		// Method begins at RVA 0x20e0
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020E0 722B010070         */ IL_0000: ldstr "Dot3.bmp" /* 7000012B */
		/* 0x000020E5 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020EA 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Dot3

	.method /* 0600000E */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Dotted () cil managed 
	{
		// Method begins at RVA 0x20ec
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020EC 723D010070         */ IL_0000: ldstr "Dotted.bmp" /* 7000013D */
		/* 0x000020F1 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x000020F6 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Dotted

	.method /* 0600000F */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_HorizVert () cil managed 
	{
		// Method begins at RVA 0x20f8
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000020F8 7253010070         */ IL_0000: ldstr "HorizVert.bmp" /* 70000153 */
		/* 0x000020FD 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002102 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_HorizVert

	.method /* 06000010 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Normal () cil managed 
	{
		// Method begins at RVA 0x2104
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002104 726F010070         */ IL_0000: ldstr "Normal.bmp" /* 7000016F */
		/* 0x00002109 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000210E 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Normal

	.method /* 06000011 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Solid () cil managed 
	{
		// Method begins at RVA 0x2110
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002110 7285010070         */ IL_0000: ldstr "Solid.bmp" /* 70000185 */
		/* 0x00002115 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000211A 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Solid

	.method /* 06000012 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Square () cil managed 
	{
		// Method begins at RVA 0x211c
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x0000211C 7299010070         */ IL_0000: ldstr "Square.bmp" /* 70000199 */
		/* 0x00002121 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002126 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Square

	.method /* 06000013 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_SquareFill () cil managed 
	{
		// Method begins at RVA 0x2128
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002128 72AF010070         */ IL_0000: ldstr "SquareFill.bmp" /* 700001AF */
		/* 0x0000212D 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002132 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_SquareFill

	.method /* 06000014 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_StripeHoriz () cil managed 
	{
		// Method begins at RVA 0x2134
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002134 72CD010070         */ IL_0000: ldstr "StripeHoriz.bmp" /* 700001CD */
		/* 0x00002139 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000213E 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_StripeHoriz

	.method /* 06000015 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_StripeVert () cil managed 
	{
		// Method begins at RVA 0x2140
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002140 72ED010070         */ IL_0000: ldstr "StripeVert.bmp" /* 700001ED */
		/* 0x00002145 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000214A 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_StripeVert

	.method /* 06000016 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Thick1 () cil managed 
	{
		// Method begins at RVA 0x214c
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x0000214C 720B020070         */ IL_0000: ldstr "Thick1.bmp" /* 7000020B */
		/* 0x00002151 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002156 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Thick1

	.method /* 06000017 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Thick2 () cil managed 
	{
		// Method begins at RVA 0x2158
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002158 7221020070         */ IL_0000: ldstr "Thick2.bmp" /* 70000221 */
		/* 0x0000215D 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002162 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Thick2

	.method /* 06000018 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Thick3 () cil managed 
	{
		// Method begins at RVA 0x2164
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002164 7237020070         */ IL_0000: ldstr "Thick3.bmp" /* 70000237 */
		/* 0x00002169 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000216E 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Thick3

	.method /* 06000019 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_TriDown () cil managed 
	{
		// Method begins at RVA 0x2170
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002170 724D020070         */ IL_0000: ldstr "TriDown.bmp" /* 7000024D */
		/* 0x00002175 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000217A 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_TriDown

	.method /* 0600001A */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_TriDownFill () cil managed 
	{
		// Method begins at RVA 0x217c
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x0000217C 7265020070         */ IL_0000: ldstr "TriDownFill.bmp" /* 70000265 */
		/* 0x00002181 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002186 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_TriDownFill

	.method /* 0600001B */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_TriUp () cil managed 
	{
		// Method begins at RVA 0x2188
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002188 7285020070         */ IL_0000: ldstr "TriUp.bmp" /* 70000285 */
		/* 0x0000218D 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x00002192 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_TriUp

	.method /* 0600001C */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_TriUpFill () cil managed 
	{
		// Method begins at RVA 0x2194
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002194 7299020070         */ IL_0000: ldstr "TriUpFill.bmp" /* 70000299 */
		/* 0x00002199 281D000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::GetImageSource(string) /* 0600001D */
		/* 0x0000219E 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_TriUpFill

	.method /* 0600001D */ private hidebysig static 
		class [PresentationCore]System.Windows.Media.ImageSource GetImageSource (
			string imageFileName
		) cil managed 
	{
		// Method begins at RVA 0x21a0
		// Header size: 12
		// Code size: 118 (0x76)
		.maxstack 4
		.locals /* 11000001 */ init (
			[0] class [mscorlib]System.Text.StringBuilder
		)

		/* 0x000021A0 7E01000004         */ IL_0000: ldsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::_imageSources /* 04000001 */
		/* 0x000021A5 02                 */ IL_0005: ldarg.0
		/* 0x000021A6 6F1500000A         */ IL_0006: callvirt instance bool class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::ContainsKey(!0) /* 0A000015 */
		/* 0x000021AB 2D5D               */ IL_000b: brtrue.s IL_006a
		/* 0x000021AD 731600000A         */ IL_000d: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000016 */
		/* 0x000021B2 0A                 */ IL_0012: stloc.0
		/* 0x000021B3 06                 */ IL_0013: ldloc.0
		/* 0x000021B4 72B5020070         */ IL_0014: ldstr "pack://application:,,,/" /* 700002B5 */
		/* 0x000021B9 6F1700000A         */ IL_0019: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000017 */
		/* 0x000021BE 26                 */ IL_001e: pop
		/* 0x000021BF 06                 */ IL_001f: ldloc.0
		/* 0x000021C0 D002000002         */ IL_0020: ldtoken AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources /* 02000002 */
		/* 0x000021C5 281800000A         */ IL_0025: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000018 */
		/* 0x000021CA 6F1900000A         */ IL_002a: callvirt instance class [mscorlib]System.Reflection.Assembly [mscorlib]System.Type::get_Assembly() /* 0A000019 */
		/* 0x000021CF 6F1A00000A         */ IL_002f: callvirt instance string [mscorlib]System.Reflection.Assembly::get_FullName() /* 0A00001A */
		/* 0x000021D4 6F1700000A         */ IL_0034: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000017 */
		/* 0x000021D9 26                 */ IL_0039: pop
		/* 0x000021DA 06                 */ IL_003a: ldloc.0
		/* 0x000021DB 72E5020070         */ IL_003b: ldstr ";component/Images/" /* 700002E5 */
		/* 0x000021E0 6F1700000A         */ IL_0040: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000017 */
		/* 0x000021E5 26                 */ IL_0045: pop
		/* 0x000021E6 06                 */ IL_0046: ldloc.0
		/* 0x000021E7 02                 */ IL_0047: ldarg.0
		/* 0x000021E8 6F1700000A         */ IL_0048: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000017 */
		/* 0x000021ED 26                 */ IL_004d: pop
		/* 0x000021EE 7E01000004         */ IL_004e: ldsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::_imageSources /* 04000001 */
		/* 0x000021F3 02                 */ IL_0053: ldarg.0
		/* 0x000021F4 06                 */ IL_0054: ldloc.0
		/* 0x000021F5 6F1B00000A         */ IL_0055: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00001B */
		/* 0x000021FA 16                 */ IL_005a: ldc.i4.0
		/* 0x000021FB 731C00000A         */ IL_005b: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x00002200 731D00000A         */ IL_0060: newobj instance void [PresentationCore]System.Windows.Media.Imaging.BitmapImage::.ctor(class [System]System.Uri) /* 0A00001D */
		/* 0x00002205 6F1E00000A         */ IL_0065: callvirt instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::Add(!0, !1) /* 0A00001E */
		/* 0x0000220A 7E01000004         */ IL_006a: ldsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::_imageSources /* 04000001 */
		/* 0x0000220F 02                 */ IL_006f: ldarg.0
		/* 0x00002210 6F1F00000A         */ IL_0070: callvirt instance !1 class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::get_Item(!0) /* 0A00001F */
		/* 0x00002215 2A                 */ IL_0075: ret
	} // end of method ImageResources::GetImageSource

	.method /* 0600001E */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2222
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002222 732000000A         */ IL_0000: newobj instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::.ctor() /* 0A000020 */
		/* 0x00002227 8001000004         */ IL_0005: stsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::_imageSources /* 04000001 */
		/* 0x0000222C 2A                 */ IL_000a: ret
	} // end of method ImageResources::.cctor

	// Properties
	.property /* 17000001 */ class [PresentationCore]System.Windows.Media.ImageSource Circle()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Circle()
	}
	.property /* 17000002 */ class [PresentationCore]System.Windows.Media.ImageSource CircleFill()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_CircleFill()
	}
	.property /* 17000003 */ class [PresentationCore]System.Windows.Media.ImageSource CrisCross()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_CrisCross()
	}
	.property /* 17000004 */ class [PresentationCore]System.Windows.Media.ImageSource Cross()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Cross()
	}
	.property /* 17000005 */ class [PresentationCore]System.Windows.Media.ImageSource Dashed()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dashed()
	}
	.property /* 17000006 */ class [PresentationCore]System.Windows.Media.ImageSource DiagLeft()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DiagLeft()
	}
	.property /* 17000007 */ class [PresentationCore]System.Windows.Media.ImageSource DiagRight()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DiagRight()
	}
	.property /* 17000008 */ class [PresentationCore]System.Windows.Media.ImageSource Diamond()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Diamond()
	}
	.property /* 17000009 */ class [PresentationCore]System.Windows.Media.ImageSource DiamondFill()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DiamondFill()
	}
	.property /* 1700000A */ class [PresentationCore]System.Windows.Media.ImageSource DotDashed()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DotDashed()
	}
	.property /* 1700000B */ class [PresentationCore]System.Windows.Media.ImageSource Dot1()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dot1()
	}
	.property /* 1700000C */ class [PresentationCore]System.Windows.Media.ImageSource Dot2()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dot2()
	}
	.property /* 1700000D */ class [PresentationCore]System.Windows.Media.ImageSource Dot3()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dot3()
	}
	.property /* 1700000E */ class [PresentationCore]System.Windows.Media.ImageSource Dotted()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dotted()
	}
	.property /* 1700000F */ class [PresentationCore]System.Windows.Media.ImageSource HorizVert()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_HorizVert()
	}
	.property /* 17000010 */ class [PresentationCore]System.Windows.Media.ImageSource Normal()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Normal()
	}
	.property /* 17000011 */ class [PresentationCore]System.Windows.Media.ImageSource Solid()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Solid()
	}
	.property /* 17000012 */ class [PresentationCore]System.Windows.Media.ImageSource Square()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Square()
	}
	.property /* 17000013 */ class [PresentationCore]System.Windows.Media.ImageSource SquareFill()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_SquareFill()
	}
	.property /* 17000014 */ class [PresentationCore]System.Windows.Media.ImageSource StripeHoriz()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_StripeHoriz()
	}
	.property /* 17000015 */ class [PresentationCore]System.Windows.Media.ImageSource StripeVert()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_StripeVert()
	}
	.property /* 17000016 */ class [PresentationCore]System.Windows.Media.ImageSource Thick1()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Thick1()
	}
	.property /* 17000017 */ class [PresentationCore]System.Windows.Media.ImageSource Thick2()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Thick2()
	}
	.property /* 17000018 */ class [PresentationCore]System.Windows.Media.ImageSource Thick3()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Thick3()
	}
	.property /* 17000019 */ class [PresentationCore]System.Windows.Media.ImageSource TriDown()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriDown()
	}
	.property /* 1700001A */ class [PresentationCore]System.Windows.Media.ImageSource TriDownFill()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriDownFill()
	}
	.property /* 1700001B */ class [PresentationCore]System.Windows.Media.ImageSource TriUp()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriUp()
	}
	.property /* 1700001C */ class [PresentationCore]System.Windows.Media.ImageSource TriUpFill()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriUpFill()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources

.class /* 02000003 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000002 */ private string '<ProductName>k__BackingField'
	.custom /* 0C000010 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000003 */ private string '<Version>k__BackingField'
	.custom /* 0C000011 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000004 */ private string '<Release>k__BackingField'
	.custom /* 0C000012 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600001F */ public hidebysig specialname 
		instance string get_ProductName () cil managed 
	{
		.custom /* 0C00001F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x222e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000222E 02                 */ IL_0000: ldarg.0
		/* 0x0000222F 7B02000004         */ IL_0001: ldfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::'<ProductName>k__BackingField' /* 04000002 */
		/* 0x00002234 2A                 */ IL_0006: ret
	} // end of method AboutPage::get_ProductName

	.method /* 06000020 */ public hidebysig specialname 
		instance void set_ProductName (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000020 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2236
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002236 02                 */ IL_0000: ldarg.0
		/* 0x00002237 03                 */ IL_0001: ldarg.1
		/* 0x00002238 7D02000004         */ IL_0002: stfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::'<ProductName>k__BackingField' /* 04000002 */
		/* 0x0000223D 2A                 */ IL_0007: ret
	} // end of method AboutPage::set_ProductName

	.method /* 06000021 */ public hidebysig specialname 
		instance string get_Version () cil managed 
	{
		.custom /* 0C000021 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x223f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000223F 02                 */ IL_0000: ldarg.0
		/* 0x00002240 7B03000004         */ IL_0001: ldfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::'<Version>k__BackingField' /* 04000003 */
		/* 0x00002245 2A                 */ IL_0006: ret
	} // end of method AboutPage::get_Version

	.method /* 06000022 */ public hidebysig specialname 
		instance void set_Version (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000022 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2247
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002247 02                 */ IL_0000: ldarg.0
		/* 0x00002248 03                 */ IL_0001: ldarg.1
		/* 0x00002249 7D03000004         */ IL_0002: stfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::'<Version>k__BackingField' /* 04000003 */
		/* 0x0000224E 2A                 */ IL_0007: ret
	} // end of method AboutPage::set_Version

	.method /* 06000023 */ public hidebysig specialname 
		instance string get_Release () cil managed 
	{
		.custom /* 0C000023 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2250
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002250 02                 */ IL_0000: ldarg.0
		/* 0x00002251 7B04000004         */ IL_0001: ldfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::'<Release>k__BackingField' /* 04000004 */
		/* 0x00002256 2A                 */ IL_0006: ret
	} // end of method AboutPage::get_Release

	.method /* 06000024 */ public hidebysig specialname 
		instance void set_Release (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000024 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2258
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002258 02                 */ IL_0000: ldarg.0
		/* 0x00002259 03                 */ IL_0001: ldarg.1
		/* 0x0000225A 7D04000004         */ IL_0002: stfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::'<Release>k__BackingField' /* 04000004 */
		/* 0x0000225F 2A                 */ IL_0007: ret
	} // end of method AboutPage::set_Release

	.method /* 06000025 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2261
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002261 02                 */ IL_0000: ldarg.0
		/* 0x00002262 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002267 2A                 */ IL_0006: ret
	} // end of method AboutPage::.ctor

	// Properties
	.property /* 1700001D */ instance string ProductName()
	{
		.get instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::get_ProductName()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::set_ProductName(string)
	}
	.property /* 1700001E */ instance string Version()
	{
		.get instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::get_Version()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::set_Version(string)
	}
	.property /* 1700001F */ instance string Release()
	{
		.get instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::get_Release()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::set_Release(string)
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage

.class /* 02000004 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000005 */ private class [PresentationCore]System.Windows.Media.ImageSource '<ImageValue>k__BackingField'
	.custom /* 0C000013 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000006 */ private string '<TextValue>k__BackingField'
	.custom /* 0C000014 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000026 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.ImageSource get_ImageValue () cil managed 
	{
		.custom /* 0C000026 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2269
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002269 02                 */ IL_0000: ldarg.0
		/* 0x0000226A 7B05000004         */ IL_0001: ldfld class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::'<ImageValue>k__BackingField' /* 04000005 */
		/* 0x0000226F 2A                 */ IL_0006: ret
	} // end of method ComboItemClass::get_ImageValue

	.method /* 06000027 */ public hidebysig specialname 
		instance void set_ImageValue (
			class [PresentationCore]System.Windows.Media.ImageSource 'value'
		) cil managed 
	{
		.custom /* 0C000027 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2271
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002271 02                 */ IL_0000: ldarg.0
		/* 0x00002272 03                 */ IL_0001: ldarg.1
		/* 0x00002273 7D05000004         */ IL_0002: stfld class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::'<ImageValue>k__BackingField' /* 04000005 */
		/* 0x00002278 2A                 */ IL_0007: ret
	} // end of method ComboItemClass::set_ImageValue

	.method /* 06000028 */ public hidebysig specialname 
		instance string get_TextValue () cil managed 
	{
		.custom /* 0C000028 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x227a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000227A 02                 */ IL_0000: ldarg.0
		/* 0x0000227B 7B06000004         */ IL_0001: ldfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::'<TextValue>k__BackingField' /* 04000006 */
		/* 0x00002280 2A                 */ IL_0006: ret
	} // end of method ComboItemClass::get_TextValue

	.method /* 06000029 */ public hidebysig specialname 
		instance void set_TextValue (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000029 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2282
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002282 02                 */ IL_0000: ldarg.0
		/* 0x00002283 03                 */ IL_0001: ldarg.1
		/* 0x00002284 7D06000004         */ IL_0002: stfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::'<TextValue>k__BackingField' /* 04000006 */
		/* 0x00002289 2A                 */ IL_0007: ret
	} // end of method ComboItemClass::set_TextValue

	.method /* 0600002A */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class [PresentationCore]System.Windows.Media.ImageSource image,
			string text
		) cil managed 
	{
		// Method begins at RVA 0x228b
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x0000228B 02                 */ IL_0000: ldarg.0
		/* 0x0000228C 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002291 02                 */ IL_0006: ldarg.0
		/* 0x00002292 03                 */ IL_0007: ldarg.1
		/* 0x00002293 2827000006         */ IL_0008: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::set_ImageValue(class [PresentationCore]System.Windows.Media.ImageSource) /* 06000027 */
		/* 0x00002298 02                 */ IL_000d: ldarg.0
		/* 0x00002299 04                 */ IL_000e: ldarg.2
		/* 0x0000229A 2829000006         */ IL_000f: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::set_TextValue(string) /* 06000029 */
		/* 0x0000229F 2A                 */ IL_0014: ret
	} // end of method ComboItemClass::.ctor

	// Properties
	.property /* 17000020 */ instance class [PresentationCore]System.Windows.Media.ImageSource ImageValue()
	{
		.get instance class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::get_ImageValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::set_ImageValue(class [PresentationCore]System.Windows.Media.ImageSource)
	}
	.property /* 17000021 */ instance string TextValue()
	{
		.get instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::get_TextValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::set_TextValue(string)
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass

.class /* 02000005 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 04000007 */ private valuetype [PresentationCore]System.Windows.Media.Color m_Curve1ColourValue
	.field /* 04000008 */ private valuetype [PresentationCore]System.Windows.Media.Color m_Curve2ColourValue
	.field /* 04000009 */ private int32 '<Curve1Colour>k__BackingField'
	.custom /* 0C000015 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000A */ private int32 '<Curve2Colour>k__BackingField'
	.custom /* 0C000016 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000B */ private int32 '<Curve1Style>k__BackingField'
	.custom /* 0C000017 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000C */ private int32 '<Curve2Style>k__BackingField'
	.custom /* 0C000018 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000D */ private int32 '<Curve1MarkerStyle>k__BackingField'
	.custom /* 0C000019 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000E */ private int32 '<Curve2MarkerStyle>k__BackingField'
	.custom /* 0C00001A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000F */ private int32 '<Curve1MarkerSize>k__BackingField'
	.custom /* 0C00001B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000010 */ private int32 '<Curve2MarkerSize>k__BackingField'
	.custom /* 0C00001C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000011 */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C00001D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600002B */ public hidebysig specialname 
		instance valuetype [PresentationCore]System.Windows.Media.Color get_Curve1ColourValue () cil managed 
	{
		// Method begins at RVA 0x22a1
		// Header size: 1
		// Code size: 48 (0x30)
		.maxstack 8

		/* 0x000022A1 02                 */ IL_0000: ldarg.0
		/* 0x000022A2 7B07000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve1ColourValue /* 04000007 */
		/* 0x000022A7 02                 */ IL_0006: ldarg.0
		/* 0x000022A8 282F000006         */ IL_0007: call instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1Colour() /* 0600002F */
		/* 0x000022AD 2877000006         */ IL_000c: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x000022B2 282200000A         */ IL_0011: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x000022B7 2C11               */ IL_0016: brfalse.s IL_0029
		/* 0x000022B9 02                 */ IL_0018: ldarg.0
		/* 0x000022BA 02                 */ IL_0019: ldarg.0
		/* 0x000022BB 282F000006         */ IL_001a: call instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1Colour() /* 0600002F */
		/* 0x000022C0 2877000006         */ IL_001f: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x000022C5 7D07000004         */ IL_0024: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve1ColourValue /* 04000007 */
		/* 0x000022CA 02                 */ IL_0029: ldarg.0
		/* 0x000022CB 7B07000004         */ IL_002a: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve1ColourValue /* 04000007 */
		/* 0x000022D0 2A                 */ IL_002f: ret
	} // end of method CurvesPage::get_Curve1ColourValue

	.method /* 0600002C */ public hidebysig specialname 
		instance void set_Curve1ColourValue (
			valuetype [PresentationCore]System.Windows.Media.Color 'value'
		) cil managed 
	{
		// Method begins at RVA 0x22d2
		// Header size: 1
		// Code size: 45 (0x2d)
		.maxstack 8

		/* 0x000022D2 02                 */ IL_0000: ldarg.0
		/* 0x000022D3 7B07000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve1ColourValue /* 04000007 */
		/* 0x000022D8 03                 */ IL_0006: ldarg.1
		/* 0x000022D9 282200000A         */ IL_0007: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x000022DE 2C1E               */ IL_000c: brfalse.s IL_002c
		/* 0x000022E0 02                 */ IL_000e: ldarg.0
		/* 0x000022E1 03                 */ IL_000f: ldarg.1
		/* 0x000022E2 7D07000004         */ IL_0010: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve1ColourValue /* 04000007 */
		/* 0x000022E7 02                 */ IL_0015: ldarg.0
		/* 0x000022E8 03                 */ IL_0016: ldarg.1
		/* 0x000022E9 2876000006         */ IL_0017: call int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorIndex(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000076 */
		/* 0x000022EE 2830000006         */ IL_001c: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve1Colour(int32) /* 06000030 */
		/* 0x000022F3 02                 */ IL_0021: ldarg.0
		/* 0x000022F4 720B030070         */ IL_0022: ldstr "Curve1ColourValue" /* 7000030B */
		/* 0x000022F9 2843000006         */ IL_0027: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::OnPropertyChanged(string) /* 06000043 */
		/* 0x000022FE 2A                 */ IL_002c: ret
	} // end of method CurvesPage::set_Curve1ColourValue

	.method /* 0600002D */ public hidebysig specialname 
		instance valuetype [PresentationCore]System.Windows.Media.Color get_Curve2ColourValue () cil managed 
	{
		// Method begins at RVA 0x2300
		// Header size: 1
		// Code size: 48 (0x30)
		.maxstack 8

		/* 0x00002300 02                 */ IL_0000: ldarg.0
		/* 0x00002301 7B08000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve2ColourValue /* 04000008 */
		/* 0x00002306 02                 */ IL_0006: ldarg.0
		/* 0x00002307 2831000006         */ IL_0007: call instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2Colour() /* 06000031 */
		/* 0x0000230C 2877000006         */ IL_000c: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002311 282200000A         */ IL_0011: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x00002316 2C11               */ IL_0016: brfalse.s IL_0029
		/* 0x00002318 02                 */ IL_0018: ldarg.0
		/* 0x00002319 02                 */ IL_0019: ldarg.0
		/* 0x0000231A 2831000006         */ IL_001a: call instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2Colour() /* 06000031 */
		/* 0x0000231F 2877000006         */ IL_001f: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002324 7D08000004         */ IL_0024: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve2ColourValue /* 04000008 */
		/* 0x00002329 02                 */ IL_0029: ldarg.0
		/* 0x0000232A 7B08000004         */ IL_002a: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve2ColourValue /* 04000008 */
		/* 0x0000232F 2A                 */ IL_002f: ret
	} // end of method CurvesPage::get_Curve2ColourValue

	.method /* 0600002E */ public hidebysig specialname 
		instance void set_Curve2ColourValue (
			valuetype [PresentationCore]System.Windows.Media.Color 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2331
		// Header size: 1
		// Code size: 45 (0x2d)
		.maxstack 8

		/* 0x00002331 02                 */ IL_0000: ldarg.0
		/* 0x00002332 7B08000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve2ColourValue /* 04000008 */
		/* 0x00002337 03                 */ IL_0006: ldarg.1
		/* 0x00002338 282200000A         */ IL_0007: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x0000233D 2C1E               */ IL_000c: brfalse.s IL_002c
		/* 0x0000233F 02                 */ IL_000e: ldarg.0
		/* 0x00002340 03                 */ IL_000f: ldarg.1
		/* 0x00002341 7D08000004         */ IL_0010: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::m_Curve2ColourValue /* 04000008 */
		/* 0x00002346 02                 */ IL_0015: ldarg.0
		/* 0x00002347 03                 */ IL_0016: ldarg.1
		/* 0x00002348 2876000006         */ IL_0017: call int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorIndex(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000076 */
		/* 0x0000234D 2832000006         */ IL_001c: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve2Colour(int32) /* 06000032 */
		/* 0x00002352 02                 */ IL_0021: ldarg.0
		/* 0x00002353 722F030070         */ IL_0022: ldstr "Curve2ColourValue" /* 7000032F */
		/* 0x00002358 2843000006         */ IL_0027: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::OnPropertyChanged(string) /* 06000043 */
		/* 0x0000235D 2A                 */ IL_002c: ret
	} // end of method CurvesPage::set_Curve2ColourValue

	.method /* 0600002F */ public hidebysig specialname 
		instance int32 get_Curve1Colour () cil managed 
	{
		.custom /* 0C00002A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x235f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000235F 02                 */ IL_0000: ldarg.0
		/* 0x00002360 7B09000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1Colour>k__BackingField' /* 04000009 */
		/* 0x00002365 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve1Colour

	.method /* 06000030 */ public hidebysig specialname 
		instance void set_Curve1Colour (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C00002B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2367
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002367 02                 */ IL_0000: ldarg.0
		/* 0x00002368 03                 */ IL_0001: ldarg.1
		/* 0x00002369 7D09000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1Colour>k__BackingField' /* 04000009 */
		/* 0x0000236E 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve1Colour

	.method /* 06000031 */ public hidebysig specialname 
		instance int32 get_Curve2Colour () cil managed 
	{
		.custom /* 0C00002C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2370
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002370 02                 */ IL_0000: ldarg.0
		/* 0x00002371 7B0A000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2Colour>k__BackingField' /* 0400000A */
		/* 0x00002376 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve2Colour

	.method /* 06000032 */ public hidebysig specialname 
		instance void set_Curve2Colour (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C00002D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2378
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002378 02                 */ IL_0000: ldarg.0
		/* 0x00002379 03                 */ IL_0001: ldarg.1
		/* 0x0000237A 7D0A000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2Colour>k__BackingField' /* 0400000A */
		/* 0x0000237F 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve2Colour

	.method /* 06000033 */ public hidebysig specialname 
		instance int32 get_Curve1Style () cil managed 
	{
		.custom /* 0C00002E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2381
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002381 02                 */ IL_0000: ldarg.0
		/* 0x00002382 7B0B000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1Style>k__BackingField' /* 0400000B */
		/* 0x00002387 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve1Style

	.method /* 06000034 */ public hidebysig specialname 
		instance void set_Curve1Style (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C00002F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2389
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002389 02                 */ IL_0000: ldarg.0
		/* 0x0000238A 03                 */ IL_0001: ldarg.1
		/* 0x0000238B 7D0B000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1Style>k__BackingField' /* 0400000B */
		/* 0x00002390 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve1Style

	.method /* 06000035 */ public hidebysig specialname 
		instance int32 get_Curve2Style () cil managed 
	{
		.custom /* 0C000030 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2392
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002392 02                 */ IL_0000: ldarg.0
		/* 0x00002393 7B0C000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2Style>k__BackingField' /* 0400000C */
		/* 0x00002398 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve2Style

	.method /* 06000036 */ public hidebysig specialname 
		instance void set_Curve2Style (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C000031 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x239a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000239A 02                 */ IL_0000: ldarg.0
		/* 0x0000239B 03                 */ IL_0001: ldarg.1
		/* 0x0000239C 7D0C000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2Style>k__BackingField' /* 0400000C */
		/* 0x000023A1 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve2Style

	.method /* 06000037 */ public hidebysig specialname 
		instance int32 get_Curve1MarkerStyle () cil managed 
	{
		.custom /* 0C000032 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23a3
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023A3 02                 */ IL_0000: ldarg.0
		/* 0x000023A4 7B0D000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1MarkerStyle>k__BackingField' /* 0400000D */
		/* 0x000023A9 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve1MarkerStyle

	.method /* 06000038 */ public hidebysig specialname 
		instance void set_Curve1MarkerStyle (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C000033 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23ab
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000023AB 02                 */ IL_0000: ldarg.0
		/* 0x000023AC 03                 */ IL_0001: ldarg.1
		/* 0x000023AD 7D0D000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1MarkerStyle>k__BackingField' /* 0400000D */
		/* 0x000023B2 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve1MarkerStyle

	.method /* 06000039 */ public hidebysig specialname 
		instance int32 get_Curve2MarkerStyle () cil managed 
	{
		.custom /* 0C000034 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23b4
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023B4 02                 */ IL_0000: ldarg.0
		/* 0x000023B5 7B0E000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2MarkerStyle>k__BackingField' /* 0400000E */
		/* 0x000023BA 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve2MarkerStyle

	.method /* 0600003A */ public hidebysig specialname 
		instance void set_Curve2MarkerStyle (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C000035 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23bc
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000023BC 02                 */ IL_0000: ldarg.0
		/* 0x000023BD 03                 */ IL_0001: ldarg.1
		/* 0x000023BE 7D0E000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2MarkerStyle>k__BackingField' /* 0400000E */
		/* 0x000023C3 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve2MarkerStyle

	.method /* 0600003B */ public hidebysig specialname 
		instance int32 get_Curve1MarkerSize () cil managed 
	{
		.custom /* 0C000036 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23c5
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023C5 02                 */ IL_0000: ldarg.0
		/* 0x000023C6 7B0F000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1MarkerSize>k__BackingField' /* 0400000F */
		/* 0x000023CB 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve1MarkerSize

	.method /* 0600003C */ public hidebysig specialname 
		instance void set_Curve1MarkerSize (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C000037 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23cd
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000023CD 02                 */ IL_0000: ldarg.0
		/* 0x000023CE 03                 */ IL_0001: ldarg.1
		/* 0x000023CF 7D0F000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve1MarkerSize>k__BackingField' /* 0400000F */
		/* 0x000023D4 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve1MarkerSize

	.method /* 0600003D */ public hidebysig specialname 
		instance int32 get_Curve2MarkerSize () cil managed 
	{
		.custom /* 0C000038 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23d6
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023D6 02                 */ IL_0000: ldarg.0
		/* 0x000023D7 7B10000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2MarkerSize>k__BackingField' /* 04000010 */
		/* 0x000023DC 2A                 */ IL_0006: ret
	} // end of method CurvesPage::get_Curve2MarkerSize

	.method /* 0600003E */ public hidebysig specialname 
		instance void set_Curve2MarkerSize (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C000039 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23de
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000023DE 02                 */ IL_0000: ldarg.0
		/* 0x000023DF 03                 */ IL_0001: ldarg.1
		/* 0x000023E0 7D10000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::'<Curve2MarkerSize>k__BackingField' /* 04000010 */
		/* 0x000023E5 2A                 */ IL_0007: ret
	} // end of method CurvesPage::set_Curve2MarkerSize

	.method /* 0600003F */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_CurveStyleItemList () cil managed 
	{
		// Method begins at RVA 0x23e7
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023E7 287B000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetLineStyleList() /* 0600007B */
		/* 0x000023EC 2A                 */ IL_0005: ret
	} // end of method CurvesPage::get_CurveStyleItemList

	.method /* 06000040 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_MarkerStyleItemList () cil managed 
	{
		// Method begins at RVA 0x23ee
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023EE 2879000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetMarkStyleList() /* 06000079 */
		/* 0x000023F3 2A                 */ IL_0005: ret
	} // end of method CurvesPage::get_MarkerStyleItemList

	.method /* 06000041 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00003B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23f8
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000023F8 02                 */ IL_0000: ldarg.0
		/* 0x000023F9 7B11000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::PropertyChanged /* 04000011 */
		/* 0x000023FE 0A                 */ IL_0006: stloc.0
		/* 0x000023FF 06                 */ IL_0007: ldloc.0
		/* 0x00002400 0B                 */ IL_0008: stloc.1
		/* 0x00002401 07                 */ IL_0009: ldloc.1
		/* 0x00002402 03                 */ IL_000a: ldarg.1
		/* 0x00002403 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x00002408 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x0000240D 0C                 */ IL_0015: stloc.2
		/* 0x0000240E 02                 */ IL_0016: ldarg.0
		/* 0x0000240F 7C11000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::PropertyChanged /* 04000011 */
		/* 0x00002414 08                 */ IL_001c: ldloc.2
		/* 0x00002415 07                 */ IL_001d: ldloc.1
		/* 0x00002416 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x0000241B 0A                 */ IL_0023: stloc.0
		/* 0x0000241C 06                 */ IL_0024: ldloc.0
		/* 0x0000241D 07                 */ IL_0025: ldloc.1
		/* 0x0000241E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002420 2A                 */ IL_0028: ret
	} // end of method CurvesPage::add_PropertyChanged

	.method /* 06000042 */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00003C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2430
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002430 02                 */ IL_0000: ldarg.0
		/* 0x00002431 7B11000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::PropertyChanged /* 04000011 */
		/* 0x00002436 0A                 */ IL_0006: stloc.0
		/* 0x00002437 06                 */ IL_0007: ldloc.0
		/* 0x00002438 0B                 */ IL_0008: stloc.1
		/* 0x00002439 07                 */ IL_0009: ldloc.1
		/* 0x0000243A 03                 */ IL_000a: ldarg.1
		/* 0x0000243B 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x00002440 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x00002445 0C                 */ IL_0015: stloc.2
		/* 0x00002446 02                 */ IL_0016: ldarg.0
		/* 0x00002447 7C11000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::PropertyChanged /* 04000011 */
		/* 0x0000244C 08                 */ IL_001c: ldloc.2
		/* 0x0000244D 07                 */ IL_001d: ldloc.1
		/* 0x0000244E 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00002453 0A                 */ IL_0023: stloc.0
		/* 0x00002454 06                 */ IL_0024: ldloc.0
		/* 0x00002455 07                 */ IL_0025: ldloc.1
		/* 0x00002456 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002458 2A                 */ IL_0028: ret
	} // end of method CurvesPage::remove_PropertyChanged

	.method /* 06000043 */ private hidebysig 
		instance void OnPropertyChanged (
			string propName
		) cil managed 
	{
		// Method begins at RVA 0x2465
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x00002465 02                 */ IL_0000: ldarg.0
		/* 0x00002466 7B11000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::PropertyChanged /* 04000011 */
		/* 0x0000246B 2C12               */ IL_0006: brfalse.s IL_001a
		/* 0x0000246D 02                 */ IL_0008: ldarg.0
		/* 0x0000246E 7B11000004         */ IL_0009: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::PropertyChanged /* 04000011 */
		/* 0x00002473 02                 */ IL_000e: ldarg.0
		/* 0x00002474 03                 */ IL_000f: ldarg.1
		/* 0x00002475 732600000A         */ IL_0010: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000026 */
		/* 0x0000247A 6F2700000A         */ IL_0015: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000027 */
		/* 0x0000247F 2A                 */ IL_001a: ret
	} // end of method CurvesPage::OnPropertyChanged

	.method /* 06000044 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2261
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002261 02                 */ IL_0000: ldarg.0
		/* 0x00002262 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002267 2A                 */ IL_0006: ret
	} // end of method CurvesPage::.ctor

	// Events
	.event /* 14000001 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 17000022 */ instance valuetype [PresentationCore]System.Windows.Media.Color Curve1ColourValue()
	{
		.get instance valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1ColourValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve1ColourValue(valuetype [PresentationCore]System.Windows.Media.Color)
	}
	.property /* 17000023 */ instance valuetype [PresentationCore]System.Windows.Media.Color Curve2ColourValue()
	{
		.get instance valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2ColourValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve2ColourValue(valuetype [PresentationCore]System.Windows.Media.Color)
	}
	.property /* 17000024 */ instance int32 Curve1Colour()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1Colour()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve1Colour(int32)
	}
	.property /* 17000025 */ instance int32 Curve2Colour()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2Colour()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve2Colour(int32)
	}
	.property /* 17000026 */ instance int32 Curve1Style()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1Style()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve1Style(int32)
	}
	.property /* 17000027 */ instance int32 Curve2Style()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2Style()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve2Style(int32)
	}
	.property /* 17000028 */ instance int32 Curve1MarkerStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1MarkerStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve1MarkerStyle(int32)
	}
	.property /* 17000029 */ instance int32 Curve2MarkerStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2MarkerStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve2MarkerStyle(int32)
	}
	.property /* 1700002A */ instance int32 Curve1MarkerSize()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve1MarkerSize()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve1MarkerSize(int32)
	}
	.property /* 1700002B */ instance int32 Curve2MarkerSize()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_Curve2MarkerSize()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::set_Curve2MarkerSize(int32)
	}
	.property /* 1700002C */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> CurveStyleItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_CurveStyleItemList()
	}
	.property /* 1700002D */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> MarkerStyleItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::get_MarkerStyleItemList()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage

.class /* 02000006 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 04000012 */ private int32 m_VapMarkerSize
	.field /* 04000013 */ private int32 m_EnvPatern
	.field /* 04000014 */ private int32 m_LineStyle
	.field /* 04000015 */ private int32 m_LineMarkerStyle
	.field /* 04000016 */ private int32 m_VapMarkerStyle
	.field /* 04000017 */ private int64 m_EnvColourIndex
	.field /* 04000018 */ private valuetype [PresentationCore]System.Windows.Media.Color m_EnvColourValue
	.field /* 04000019 */ private int64 m_LineColourIndex
	.field /* 0400001A */ private valuetype [PresentationCore]System.Windows.Media.Color m_LineColourValue
	.field /* 0400001B */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C00001E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000045 */ public hidebysig specialname 
		instance valuetype [PresentationCore]System.Windows.Media.Color get_EnvColorValue () cil managed 
	{
		// Method begins at RVA 0x2481
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x00002481 02                 */ IL_0000: ldarg.0
		/* 0x00002482 7B18000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourValue /* 04000018 */
		/* 0x00002487 02                 */ IL_0006: ldarg.0
		/* 0x00002488 7B17000004         */ IL_0007: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourIndex /* 04000017 */
		/* 0x0000248D 69                 */ IL_000c: conv.i4
		/* 0x0000248E 2877000006         */ IL_000d: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002493 282200000A         */ IL_0012: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x00002498 2C12               */ IL_0017: brfalse.s IL_002b
		/* 0x0000249A 02                 */ IL_0019: ldarg.0
		/* 0x0000249B 02                 */ IL_001a: ldarg.0
		/* 0x0000249C 7B17000004         */ IL_001b: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourIndex /* 04000017 */
		/* 0x000024A1 69                 */ IL_0020: conv.i4
		/* 0x000024A2 2877000006         */ IL_0021: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x000024A7 7D18000004         */ IL_0026: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourValue /* 04000018 */
		/* 0x000024AC 02                 */ IL_002b: ldarg.0
		/* 0x000024AD 7B18000004         */ IL_002c: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourValue /* 04000018 */
		/* 0x000024B2 2A                 */ IL_0031: ret
	} // end of method EnvelopPage::get_EnvColorValue

	.method /* 06000046 */ public hidebysig specialname 
		instance void set_EnvColorValue (
			valuetype [PresentationCore]System.Windows.Media.Color 'value'
		) cil managed 
	{
		// Method begins at RVA 0x24b4
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x000024B4 02                 */ IL_0000: ldarg.0
		/* 0x000024B5 7B18000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourValue /* 04000018 */
		/* 0x000024BA 03                 */ IL_0006: ldarg.1
		/* 0x000024BB 282200000A         */ IL_0007: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x000024C0 2C1F               */ IL_000c: brfalse.s IL_002d
		/* 0x000024C2 02                 */ IL_000e: ldarg.0
		/* 0x000024C3 03                 */ IL_000f: ldarg.1
		/* 0x000024C4 7D18000004         */ IL_0010: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourValue /* 04000018 */
		/* 0x000024C9 02                 */ IL_0015: ldarg.0
		/* 0x000024CA 03                 */ IL_0016: ldarg.1
		/* 0x000024CB 2876000006         */ IL_0017: call int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorIndex(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000076 */
		/* 0x000024D0 6A                 */ IL_001c: conv.i8
		/* 0x000024D1 2848000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_EnvColour(int64) /* 06000048 */
		/* 0x000024D6 02                 */ IL_0022: ldarg.0
		/* 0x000024D7 7253030070         */ IL_0023: ldstr "EnvColorValue" /* 70000353 */
		/* 0x000024DC 285C000006         */ IL_0028: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x000024E1 2A                 */ IL_002d: ret
	} // end of method EnvelopPage::set_EnvColorValue

	.method /* 06000047 */ public hidebysig specialname 
		instance int64 get_EnvColour () cil managed 
	{
		// Method begins at RVA 0x24e3
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000024E3 02                 */ IL_0000: ldarg.0
		/* 0x000024E4 7B17000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourIndex /* 04000017 */
		/* 0x000024E9 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_EnvColour

	.method /* 06000048 */ public hidebysig specialname 
		instance void set_EnvColour (
			int64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x24eb
		// Header size: 1
		// Code size: 35 (0x23)
		.maxstack 8

		/* 0x000024EB 02                 */ IL_0000: ldarg.0
		/* 0x000024EC 7B17000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourIndex /* 04000017 */
		/* 0x000024F1 03                 */ IL_0006: ldarg.1
		/* 0x000024F2 2E19               */ IL_0007: beq.s IL_0022
		/* 0x000024F4 02                 */ IL_0009: ldarg.0
		/* 0x000024F5 03                 */ IL_000a: ldarg.1
		/* 0x000024F6 7D17000004         */ IL_000b: stfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourIndex /* 04000017 */
		/* 0x000024FB 02                 */ IL_0010: ldarg.0
		/* 0x000024FC 02                 */ IL_0011: ldarg.0
		/* 0x000024FD 7B17000004         */ IL_0012: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvColourIndex /* 04000017 */
		/* 0x00002502 69                 */ IL_0017: conv.i4
		/* 0x00002503 2877000006         */ IL_0018: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002508 2846000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_EnvColorValue(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000046 */
		/* 0x0000250D 2A                 */ IL_0022: ret
	} // end of method EnvelopPage::set_EnvColour

	.method /* 06000049 */ public hidebysig specialname 
		instance valuetype [PresentationCore]System.Windows.Media.Color get_LineColorValue () cil managed 
	{
		// Method begins at RVA 0x250f
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x0000250F 02                 */ IL_0000: ldarg.0
		/* 0x00002510 7B1A000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourValue /* 0400001A */
		/* 0x00002515 02                 */ IL_0006: ldarg.0
		/* 0x00002516 7B19000004         */ IL_0007: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourIndex /* 04000019 */
		/* 0x0000251B 69                 */ IL_000c: conv.i4
		/* 0x0000251C 2877000006         */ IL_000d: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002521 282200000A         */ IL_0012: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x00002526 2C12               */ IL_0017: brfalse.s IL_002b
		/* 0x00002528 02                 */ IL_0019: ldarg.0
		/* 0x00002529 02                 */ IL_001a: ldarg.0
		/* 0x0000252A 7B19000004         */ IL_001b: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourIndex /* 04000019 */
		/* 0x0000252F 69                 */ IL_0020: conv.i4
		/* 0x00002530 2877000006         */ IL_0021: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002535 7D1A000004         */ IL_0026: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourValue /* 0400001A */
		/* 0x0000253A 02                 */ IL_002b: ldarg.0
		/* 0x0000253B 7B1A000004         */ IL_002c: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourValue /* 0400001A */
		/* 0x00002540 2A                 */ IL_0031: ret
	} // end of method EnvelopPage::get_LineColorValue

	.method /* 0600004A */ public hidebysig specialname 
		instance void set_LineColorValue (
			valuetype [PresentationCore]System.Windows.Media.Color 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2542
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x00002542 02                 */ IL_0000: ldarg.0
		/* 0x00002543 7B1A000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourValue /* 0400001A */
		/* 0x00002548 03                 */ IL_0006: ldarg.1
		/* 0x00002549 282200000A         */ IL_0007: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x0000254E 2C1F               */ IL_000c: brfalse.s IL_002d
		/* 0x00002550 02                 */ IL_000e: ldarg.0
		/* 0x00002551 03                 */ IL_000f: ldarg.1
		/* 0x00002552 7D1A000004         */ IL_0010: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourValue /* 0400001A */
		/* 0x00002557 02                 */ IL_0015: ldarg.0
		/* 0x00002558 03                 */ IL_0016: ldarg.1
		/* 0x00002559 2876000006         */ IL_0017: call int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorIndex(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000076 */
		/* 0x0000255E 6A                 */ IL_001c: conv.i8
		/* 0x0000255F 284C000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_LineColour(int64) /* 0600004C */
		/* 0x00002564 02                 */ IL_0022: ldarg.0
		/* 0x00002565 726F030070         */ IL_0023: ldstr "LineColorValue" /* 7000036F */
		/* 0x0000256A 285C000006         */ IL_0028: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x0000256F 2A                 */ IL_002d: ret
	} // end of method EnvelopPage::set_LineColorValue

	.method /* 0600004B */ public hidebysig specialname 
		instance int64 get_LineColour () cil managed 
	{
		// Method begins at RVA 0x2571
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002571 02                 */ IL_0000: ldarg.0
		/* 0x00002572 7B19000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourIndex /* 04000019 */
		/* 0x00002577 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_LineColour

	.method /* 0600004C */ public hidebysig specialname 
		instance void set_LineColour (
			int64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2579
		// Header size: 1
		// Code size: 35 (0x23)
		.maxstack 8

		/* 0x00002579 02                 */ IL_0000: ldarg.0
		/* 0x0000257A 7B19000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourIndex /* 04000019 */
		/* 0x0000257F 03                 */ IL_0006: ldarg.1
		/* 0x00002580 2E19               */ IL_0007: beq.s IL_0022
		/* 0x00002582 02                 */ IL_0009: ldarg.0
		/* 0x00002583 03                 */ IL_000a: ldarg.1
		/* 0x00002584 7D19000004         */ IL_000b: stfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourIndex /* 04000019 */
		/* 0x00002589 02                 */ IL_0010: ldarg.0
		/* 0x0000258A 02                 */ IL_0011: ldarg.0
		/* 0x0000258B 7B19000004         */ IL_0012: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineColourIndex /* 04000019 */
		/* 0x00002590 69                 */ IL_0017: conv.i4
		/* 0x00002591 2877000006         */ IL_0018: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002596 284A000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_LineColorValue(valuetype [PresentationCore]System.Windows.Media.Color) /* 0600004A */
		/* 0x0000259B 2A                 */ IL_0022: ret
	} // end of method EnvelopPage::set_LineColour

	.method /* 0600004D */ public hidebysig specialname 
		instance int32 get_EnvPatern () cil managed 
	{
		// Method begins at RVA 0x259d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000259D 02                 */ IL_0000: ldarg.0
		/* 0x0000259E 7B13000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvPatern /* 04000013 */
		/* 0x000025A3 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_EnvPatern

	.method /* 0600004E */ public hidebysig specialname 
		instance void set_EnvPatern (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x25a5
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000025A5 02                 */ IL_0000: ldarg.0
		/* 0x000025A6 7B13000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvPatern /* 04000013 */
		/* 0x000025AB 03                 */ IL_0006: ldarg.1
		/* 0x000025AC 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000025AE 02                 */ IL_0009: ldarg.0
		/* 0x000025AF 03                 */ IL_000a: ldarg.1
		/* 0x000025B0 7D13000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_EnvPatern /* 04000013 */
		/* 0x000025B5 02                 */ IL_0010: ldarg.0
		/* 0x000025B6 728D030070         */ IL_0011: ldstr "EnvPatern" /* 7000038D */
		/* 0x000025BB 285C000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x000025C0 2A                 */ IL_001b: ret
	} // end of method EnvelopPage::set_EnvPatern

	.method /* 0600004F */ public hidebysig specialname 
		instance int32 get_LineStyle () cil managed 
	{
		// Method begins at RVA 0x25c2
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000025C2 02                 */ IL_0000: ldarg.0
		/* 0x000025C3 7B14000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineStyle /* 04000014 */
		/* 0x000025C8 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_LineStyle

	.method /* 06000050 */ public hidebysig specialname 
		instance void set_LineStyle (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x25ca
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000025CA 02                 */ IL_0000: ldarg.0
		/* 0x000025CB 7B14000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineStyle /* 04000014 */
		/* 0x000025D0 03                 */ IL_0006: ldarg.1
		/* 0x000025D1 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000025D3 02                 */ IL_0009: ldarg.0
		/* 0x000025D4 03                 */ IL_000a: ldarg.1
		/* 0x000025D5 7D14000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineStyle /* 04000014 */
		/* 0x000025DA 02                 */ IL_0010: ldarg.0
		/* 0x000025DB 72A1030070         */ IL_0011: ldstr "LineStyle" /* 700003A1 */
		/* 0x000025E0 285C000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x000025E5 2A                 */ IL_001b: ret
	} // end of method EnvelopPage::set_LineStyle

	.method /* 06000051 */ public hidebysig specialname 
		instance int32 get_LineMarkerStyle () cil managed 
	{
		// Method begins at RVA 0x25e7
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000025E7 02                 */ IL_0000: ldarg.0
		/* 0x000025E8 7B15000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineMarkerStyle /* 04000015 */
		/* 0x000025ED 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_LineMarkerStyle

	.method /* 06000052 */ public hidebysig specialname 
		instance void set_LineMarkerStyle (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x25ef
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000025EF 02                 */ IL_0000: ldarg.0
		/* 0x000025F0 7B15000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineMarkerStyle /* 04000015 */
		/* 0x000025F5 03                 */ IL_0006: ldarg.1
		/* 0x000025F6 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000025F8 02                 */ IL_0009: ldarg.0
		/* 0x000025F9 03                 */ IL_000a: ldarg.1
		/* 0x000025FA 7D15000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_LineMarkerStyle /* 04000015 */
		/* 0x000025FF 02                 */ IL_0010: ldarg.0
		/* 0x00002600 72B5030070         */ IL_0011: ldstr "LineMarkerStyle" /* 700003B5 */
		/* 0x00002605 285C000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x0000260A 2A                 */ IL_001b: ret
	} // end of method EnvelopPage::set_LineMarkerStyle

	.method /* 06000053 */ public hidebysig specialname 
		instance int32 get_VapMarkerStyle () cil managed 
	{
		// Method begins at RVA 0x260c
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000260C 02                 */ IL_0000: ldarg.0
		/* 0x0000260D 7B16000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_VapMarkerStyle /* 04000016 */
		/* 0x00002612 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_VapMarkerStyle

	.method /* 06000054 */ public hidebysig specialname 
		instance void set_VapMarkerStyle (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2614
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002614 02                 */ IL_0000: ldarg.0
		/* 0x00002615 7B16000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_VapMarkerStyle /* 04000016 */
		/* 0x0000261A 03                 */ IL_0006: ldarg.1
		/* 0x0000261B 2E12               */ IL_0007: beq.s IL_001b
		/* 0x0000261D 02                 */ IL_0009: ldarg.0
		/* 0x0000261E 03                 */ IL_000a: ldarg.1
		/* 0x0000261F 7D16000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_VapMarkerStyle /* 04000016 */
		/* 0x00002624 02                 */ IL_0010: ldarg.0
		/* 0x00002625 72D5030070         */ IL_0011: ldstr "VapMarkerStyle" /* 700003D5 */
		/* 0x0000262A 285C000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x0000262F 2A                 */ IL_001b: ret
	} // end of method EnvelopPage::set_VapMarkerStyle

	.method /* 06000055 */ public hidebysig specialname 
		instance int32 get_VapMarkerSize () cil managed 
	{
		// Method begins at RVA 0x2631
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002631 02                 */ IL_0000: ldarg.0
		/* 0x00002632 7B12000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_VapMarkerSize /* 04000012 */
		/* 0x00002637 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::get_VapMarkerSize

	.method /* 06000056 */ public hidebysig specialname 
		instance void set_VapMarkerSize (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2639
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002639 02                 */ IL_0000: ldarg.0
		/* 0x0000263A 7B12000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_VapMarkerSize /* 04000012 */
		/* 0x0000263F 03                 */ IL_0006: ldarg.1
		/* 0x00002640 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002642 02                 */ IL_0009: ldarg.0
		/* 0x00002643 03                 */ IL_000a: ldarg.1
		/* 0x00002644 7D12000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::m_VapMarkerSize /* 04000012 */
		/* 0x00002649 02                 */ IL_0010: ldarg.0
		/* 0x0000264A 72F3030070         */ IL_0011: ldstr "VapMarkerSize" /* 700003F3 */
		/* 0x0000264F 285C000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::OnPropertyChanged(string) /* 0600005C */
		/* 0x00002654 2A                 */ IL_001b: ret
	} // end of method EnvelopPage::set_VapMarkerSize

	.method /* 06000057 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_MarkerItemList () cil managed 
	{
		// Method begins at RVA 0x23ee
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023EE 2879000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetMarkStyleList() /* 06000079 */
		/* 0x000023F3 2A                 */ IL_0005: ret
	} // end of method EnvelopPage::get_MarkerItemList

	.method /* 06000058 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_EnvItemList () cil managed 
	{
		// Method begins at RVA 0x2656
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00002656 287A000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetEnvPatternList() /* 0600007A */
		/* 0x0000265B 2A                 */ IL_0005: ret
	} // end of method EnvelopPage::get_EnvItemList

	.method /* 06000059 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_LineItemList () cil managed 
	{
		// Method begins at RVA 0x23e7
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023E7 287B000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetLineStyleList() /* 0600007B */
		/* 0x000023EC 2A                 */ IL_0005: ret
	} // end of method EnvelopPage::get_LineItemList

	.method /* 0600005A */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00003E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2660
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002660 02                 */ IL_0000: ldarg.0
		/* 0x00002661 7B1B000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::PropertyChanged /* 0400001B */
		/* 0x00002666 0A                 */ IL_0006: stloc.0
		/* 0x00002667 06                 */ IL_0007: ldloc.0
		/* 0x00002668 0B                 */ IL_0008: stloc.1
		/* 0x00002669 07                 */ IL_0009: ldloc.1
		/* 0x0000266A 03                 */ IL_000a: ldarg.1
		/* 0x0000266B 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x00002670 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x00002675 0C                 */ IL_0015: stloc.2
		/* 0x00002676 02                 */ IL_0016: ldarg.0
		/* 0x00002677 7C1B000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::PropertyChanged /* 0400001B */
		/* 0x0000267C 08                 */ IL_001c: ldloc.2
		/* 0x0000267D 07                 */ IL_001d: ldloc.1
		/* 0x0000267E 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00002683 0A                 */ IL_0023: stloc.0
		/* 0x00002684 06                 */ IL_0024: ldloc.0
		/* 0x00002685 07                 */ IL_0025: ldloc.1
		/* 0x00002686 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002688 2A                 */ IL_0028: ret
	} // end of method EnvelopPage::add_PropertyChanged

	.method /* 0600005B */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00003F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2698
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002698 02                 */ IL_0000: ldarg.0
		/* 0x00002699 7B1B000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::PropertyChanged /* 0400001B */
		/* 0x0000269E 0A                 */ IL_0006: stloc.0
		/* 0x0000269F 06                 */ IL_0007: ldloc.0
		/* 0x000026A0 0B                 */ IL_0008: stloc.1
		/* 0x000026A1 07                 */ IL_0009: ldloc.1
		/* 0x000026A2 03                 */ IL_000a: ldarg.1
		/* 0x000026A3 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x000026A8 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x000026AD 0C                 */ IL_0015: stloc.2
		/* 0x000026AE 02                 */ IL_0016: ldarg.0
		/* 0x000026AF 7C1B000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::PropertyChanged /* 0400001B */
		/* 0x000026B4 08                 */ IL_001c: ldloc.2
		/* 0x000026B5 07                 */ IL_001d: ldloc.1
		/* 0x000026B6 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x000026BB 0A                 */ IL_0023: stloc.0
		/* 0x000026BC 06                 */ IL_0024: ldloc.0
		/* 0x000026BD 07                 */ IL_0025: ldloc.1
		/* 0x000026BE 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000026C0 2A                 */ IL_0028: ret
	} // end of method EnvelopPage::remove_PropertyChanged

	.method /* 0600005C */ private hidebysig 
		instance void OnPropertyChanged (
			string propName
		) cil managed 
	{
		// Method begins at RVA 0x26cd
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x000026CD 02                 */ IL_0000: ldarg.0
		/* 0x000026CE 7B1B000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::PropertyChanged /* 0400001B */
		/* 0x000026D3 2C12               */ IL_0006: brfalse.s IL_001a
		/* 0x000026D5 02                 */ IL_0008: ldarg.0
		/* 0x000026D6 7B1B000004         */ IL_0009: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::PropertyChanged /* 0400001B */
		/* 0x000026DB 02                 */ IL_000e: ldarg.0
		/* 0x000026DC 03                 */ IL_000f: ldarg.1
		/* 0x000026DD 732600000A         */ IL_0010: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000026 */
		/* 0x000026E2 6F2700000A         */ IL_0015: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000027 */
		/* 0x000026E7 2A                 */ IL_001a: ret
	} // end of method EnvelopPage::OnPropertyChanged

	.method /* 0600005D */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2261
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002261 02                 */ IL_0000: ldarg.0
		/* 0x00002262 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002267 2A                 */ IL_0006: ret
	} // end of method EnvelopPage::.ctor

	// Events
	.event /* 14000002 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 1700002E */ instance valuetype [PresentationCore]System.Windows.Media.Color EnvColorValue()
	{
		.get instance valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_EnvColorValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_EnvColorValue(valuetype [PresentationCore]System.Windows.Media.Color)
	}
	.property /* 1700002F */ instance int64 EnvColour()
	{
		.get instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_EnvColour()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_EnvColour(int64)
	}
	.property /* 17000030 */ instance valuetype [PresentationCore]System.Windows.Media.Color LineColorValue()
	{
		.get instance valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_LineColorValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_LineColorValue(valuetype [PresentationCore]System.Windows.Media.Color)
	}
	.property /* 17000031 */ instance int64 LineColour()
	{
		.get instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_LineColour()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_LineColour(int64)
	}
	.property /* 17000032 */ instance int32 EnvPatern()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_EnvPatern()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_EnvPatern(int32)
	}
	.property /* 17000033 */ instance int32 LineStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_LineStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_LineStyle(int32)
	}
	.property /* 17000034 */ instance int32 LineMarkerStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_LineMarkerStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_LineMarkerStyle(int32)
	}
	.property /* 17000035 */ instance int32 VapMarkerStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_VapMarkerStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_VapMarkerStyle(int32)
	}
	.property /* 17000036 */ instance int32 VapMarkerSize()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_VapMarkerSize()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::set_VapMarkerSize(int32)
	}
	.property /* 17000037 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> MarkerItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_MarkerItemList()
	}
	.property /* 17000038 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> EnvItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_EnvItemList()
	}
	.property /* 17000039 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> LineItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::get_LineItemList()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage

.class /* 02000007 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 0400001C */ private class [System]System.Collections.ObjectModel.ObservableCollection`1<string> m_FontFamilies
	.field /* 0400001D */ private bool m_Coord
	.field /* 0400001E */ private bool m_BoilingPoint
	.field /* 0400001F */ private bool m_Transparent
	.field /* 04000020 */ private bool m_Stages
	.field /* 04000021 */ private string m_Font
	.field /* 04000022 */ private int32 m_FontSize
	.field /* 04000023 */ private int64 m_ToolBarPos
	.field /* 04000024 */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C000025 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600005E */ public hidebysig specialname 
		instance bool get_Coord () cil managed 
	{
		// Method begins at RVA 0x26e9
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000026E9 02                 */ IL_0000: ldarg.0
		/* 0x000026EA 7B1D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Coord /* 0400001D */
		/* 0x000026EF 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_Coord

	.method /* 0600005F */ public hidebysig specialname 
		instance void set_Coord (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x26f1
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000026F1 02                 */ IL_0000: ldarg.0
		/* 0x000026F2 7B1D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Coord /* 0400001D */
		/* 0x000026F7 03                 */ IL_0006: ldarg.1
		/* 0x000026F8 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000026FA 02                 */ IL_0009: ldarg.0
		/* 0x000026FB 03                 */ IL_000a: ldarg.1
		/* 0x000026FC 7D1D000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Coord /* 0400001D */
		/* 0x00002701 02                 */ IL_0010: ldarg.0
		/* 0x00002702 720F040070         */ IL_0011: ldstr "Coord" /* 7000040F */
		/* 0x00002707 2874000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x0000270C 2A                 */ IL_001b: ret
	} // end of method GeneralPage::set_Coord

	.method /* 06000060 */ public hidebysig specialname 
		instance bool get_BoilingPoint () cil managed 
	{
		// Method begins at RVA 0x270e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000270E 02                 */ IL_0000: ldarg.0
		/* 0x0000270F 7B1E000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_BoilingPoint /* 0400001E */
		/* 0x00002714 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_BoilingPoint

	.method /* 06000061 */ public hidebysig specialname 
		instance void set_BoilingPoint (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2716
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002716 02                 */ IL_0000: ldarg.0
		/* 0x00002717 7B1E000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_BoilingPoint /* 0400001E */
		/* 0x0000271C 03                 */ IL_0006: ldarg.1
		/* 0x0000271D 2E12               */ IL_0007: beq.s IL_001b
		/* 0x0000271F 02                 */ IL_0009: ldarg.0
		/* 0x00002720 03                 */ IL_000a: ldarg.1
		/* 0x00002721 7D1E000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_BoilingPoint /* 0400001E */
		/* 0x00002726 02                 */ IL_0010: ldarg.0
		/* 0x00002727 721B040070         */ IL_0011: ldstr "BoilingPoint" /* 7000041B */
		/* 0x0000272C 2874000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x00002731 2A                 */ IL_001b: ret
	} // end of method GeneralPage::set_BoilingPoint

	.method /* 06000062 */ public hidebysig specialname 
		instance bool get_Transparent () cil managed 
	{
		// Method begins at RVA 0x2733
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002733 02                 */ IL_0000: ldarg.0
		/* 0x00002734 7B1F000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Transparent /* 0400001F */
		/* 0x00002739 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_Transparent

	.method /* 06000063 */ public hidebysig specialname 
		instance void set_Transparent (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x273b
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x0000273B 02                 */ IL_0000: ldarg.0
		/* 0x0000273C 7B1F000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Transparent /* 0400001F */
		/* 0x00002741 03                 */ IL_0006: ldarg.1
		/* 0x00002742 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002744 02                 */ IL_0009: ldarg.0
		/* 0x00002745 03                 */ IL_000a: ldarg.1
		/* 0x00002746 7D1F000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Transparent /* 0400001F */
		/* 0x0000274B 02                 */ IL_0010: ldarg.0
		/* 0x0000274C 7235040070         */ IL_0011: ldstr "Transparent" /* 70000435 */
		/* 0x00002751 2874000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x00002756 2A                 */ IL_001b: ret
	} // end of method GeneralPage::set_Transparent

	.method /* 06000064 */ public hidebysig specialname 
		instance bool get_Stages () cil managed 
	{
		// Method begins at RVA 0x2758
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002758 02                 */ IL_0000: ldarg.0
		/* 0x00002759 7B20000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Stages /* 04000020 */
		/* 0x0000275E 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_Stages

	.method /* 06000065 */ public hidebysig specialname 
		instance void set_Stages (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2760
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002760 02                 */ IL_0000: ldarg.0
		/* 0x00002761 7B20000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Stages /* 04000020 */
		/* 0x00002766 03                 */ IL_0006: ldarg.1
		/* 0x00002767 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002769 02                 */ IL_0009: ldarg.0
		/* 0x0000276A 03                 */ IL_000a: ldarg.1
		/* 0x0000276B 7D20000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Stages /* 04000020 */
		/* 0x00002770 02                 */ IL_0010: ldarg.0
		/* 0x00002771 724D040070         */ IL_0011: ldstr "Stages" /* 7000044D */
		/* 0x00002776 2874000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x0000277B 2A                 */ IL_001b: ret
	} // end of method GeneralPage::set_Stages

	.method /* 06000066 */ public hidebysig specialname 
		instance string get_Font () cil managed 
	{
		// Method begins at RVA 0x277d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000277D 02                 */ IL_0000: ldarg.0
		/* 0x0000277E 7B21000004         */ IL_0001: ldfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Font /* 04000021 */
		/* 0x00002783 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_Font

	.method /* 06000067 */ public hidebysig specialname 
		instance void set_Font (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2785
		// Header size: 1
		// Code size: 33 (0x21)
		.maxstack 8

		/* 0x00002785 02                 */ IL_0000: ldarg.0
		/* 0x00002786 7B21000004         */ IL_0001: ldfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Font /* 04000021 */
		/* 0x0000278B 03                 */ IL_0006: ldarg.1
		/* 0x0000278C 282800000A         */ IL_0007: call bool [mscorlib]System.String::op_Inequality(string, string) /* 0A000028 */
		/* 0x00002791 2C12               */ IL_000c: brfalse.s IL_0020
		/* 0x00002793 02                 */ IL_000e: ldarg.0
		/* 0x00002794 03                 */ IL_000f: ldarg.1
		/* 0x00002795 7D21000004         */ IL_0010: stfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Font /* 04000021 */
		/* 0x0000279A 02                 */ IL_0015: ldarg.0
		/* 0x0000279B 725B040070         */ IL_0016: ldstr "Font" /* 7000045B */
		/* 0x000027A0 2874000006         */ IL_001b: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x000027A5 2A                 */ IL_0020: ret
	} // end of method GeneralPage::set_Font

	.method /* 06000068 */ public hidebysig specialname 
		instance int32 get_FontSize () cil managed 
	{
		// Method begins at RVA 0x27a7
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000027A7 02                 */ IL_0000: ldarg.0
		/* 0x000027A8 7B22000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_FontSize /* 04000022 */
		/* 0x000027AD 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_FontSize

	.method /* 06000069 */ public hidebysig specialname 
		instance void set_FontSize (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x27af
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000027AF 02                 */ IL_0000: ldarg.0
		/* 0x000027B0 7B22000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_FontSize /* 04000022 */
		/* 0x000027B5 03                 */ IL_0006: ldarg.1
		/* 0x000027B6 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000027B8 02                 */ IL_0009: ldarg.0
		/* 0x000027B9 03                 */ IL_000a: ldarg.1
		/* 0x000027BA 7D22000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_FontSize /* 04000022 */
		/* 0x000027BF 02                 */ IL_0010: ldarg.0
		/* 0x000027C0 7265040070         */ IL_0011: ldstr "FontSize" /* 70000465 */
		/* 0x000027C5 2874000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x000027CA 2A                 */ IL_001b: ret
	} // end of method GeneralPage::set_FontSize

	.method /* 0600006A */ public hidebysig specialname 
		instance int64 get_ToolBarPos () cil managed 
	{
		// Method begins at RVA 0x27cc
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000027CC 02                 */ IL_0000: ldarg.0
		/* 0x000027CD 7B23000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_ToolBarPos /* 04000023 */
		/* 0x000027D2 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_ToolBarPos

	.method /* 0600006B */ public hidebysig specialname 
		instance void set_ToolBarPos (
			int64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x27d4
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000027D4 02                 */ IL_0000: ldarg.0
		/* 0x000027D5 03                 */ IL_0001: ldarg.1
		/* 0x000027D6 7D23000004         */ IL_0002: stfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_ToolBarPos /* 04000023 */
		/* 0x000027DB 2A                 */ IL_0007: ret
	} // end of method GeneralPage::set_ToolBarPos

	.method /* 0600006C */ public hidebysig specialname 
		instance string get_ToolBarPosString () cil managed 
	{
		// Method begins at RVA 0x27dd
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x000027DD 02                 */ IL_0000: ldarg.0
		/* 0x000027DE 2871000006         */ IL_0001: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPositions() /* 06000071 */
		/* 0x000027E3 02                 */ IL_0006: ldarg.0
		/* 0x000027E4 286A000006         */ IL_0007: call instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPos() /* 0600006A */
		/* 0x000027E9 69                 */ IL_000c: conv.i4
		/* 0x000027EA 6F2900000A         */ IL_000d: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::get_Item(int32) /* 0A000029 */
		/* 0x000027EF 2A                 */ IL_0012: ret
	} // end of method GeneralPage::get_ToolBarPosString

	.method /* 0600006D */ public hidebysig specialname 
		instance void set_ToolBarPosString (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x27f4
		// Header size: 12
		// Code size: 43 (0x2b)
		.maxstack 2
		.locals /* 11000003 */ init (
			[0] int32
		)

		/* 0x000027F4 02                 */ IL_0000: ldarg.0
		/* 0x000027F5 2871000006         */ IL_0001: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPositions() /* 06000071 */
		/* 0x000027FA 03                 */ IL_0006: ldarg.1
		/* 0x000027FB 6F2A00000A         */ IL_0007: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::IndexOf(!0) /* 0A00002A */
		/* 0x00002800 0A                 */ IL_000c: stloc.0
		/* 0x00002801 06                 */ IL_000d: ldloc.0
		/* 0x00002802 6A                 */ IL_000e: conv.i8
		/* 0x00002803 02                 */ IL_000f: ldarg.0
		/* 0x00002804 286A000006         */ IL_0010: call instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPos() /* 0600006A */
		/* 0x00002809 2E13               */ IL_0015: beq.s IL_002a
		/* 0x0000280B 02                 */ IL_0017: ldarg.0
		/* 0x0000280C 06                 */ IL_0018: ldloc.0
		/* 0x0000280D 6A                 */ IL_0019: conv.i8
		/* 0x0000280E 286B000006         */ IL_001a: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_ToolBarPos(int64) /* 0600006B */
		/* 0x00002813 02                 */ IL_001f: ldarg.0
		/* 0x00002814 7277040070         */ IL_0020: ldstr "ToolBarPosString" /* 70000477 */
		/* 0x00002819 2874000006         */ IL_0025: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::OnPropertyChanged(string) /* 06000074 */
		/* 0x0000281E 2A                 */ IL_002a: ret
	} // end of method GeneralPage::set_ToolBarPosString

	.method /* 0600006E */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x282b
		// Header size: 1
		// Code size: 24 (0x18)
		.maxstack 8

		/* 0x0000282B 02                 */ IL_0000: ldarg.0
		/* 0x0000282C 7E2B00000A         */ IL_0001: ldsfld string [mscorlib]System.String::Empty /* 0A00002B */
		/* 0x00002831 7D21000004         */ IL_0006: stfld string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_Font /* 04000021 */
		/* 0x00002836 02                 */ IL_000b: ldarg.0
		/* 0x00002837 282100000A         */ IL_000c: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x0000283C 02                 */ IL_0011: ldarg.0
		/* 0x0000283D 286F000006         */ IL_0012: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::GetFontFamilies() /* 0600006F */
		/* 0x00002842 2A                 */ IL_0017: ret
	} // end of method GeneralPage::.ctor

	.method /* 0600006F */ private hidebysig 
		instance void GetFontFamilies () cil managed 
	{
		// Method begins at RVA 0x2844
		// Header size: 12
		// Code size: 53 (0x35)
		.maxstack 2
		.locals /* 11000004 */ init (
			[0] class [System.Drawing]System.Drawing.FontFamily[],
			[1] int32,
			[2] class [System.Drawing]System.Drawing.FontFamily
		)

		/* 0x00002844 02                 */ IL_0000: ldarg.0
		/* 0x00002845 732C00000A         */ IL_0001: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<string>::.ctor() /* 0A00002C */
		/* 0x0000284A 7D1C000004         */ IL_0006: stfld class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_FontFamilies /* 0400001C */
		/* 0x0000284F 282D00000A         */ IL_000b: call class [System.Drawing]System.Drawing.FontFamily[] [System.Drawing]System.Drawing.FontFamily::get_Families() /* 0A00002D */
		/* 0x00002854 0A                 */ IL_0010: stloc.0
		/* 0x00002855 16                 */ IL_0011: ldc.i4.0
		/* 0x00002856 0B                 */ IL_0012: stloc.1
		/* 0x00002857 2B19               */ IL_0013: br.s IL_002e
		/* 0x00002859 06                 */ IL_0015: ldloc.0
		/* 0x0000285A 07                 */ IL_0016: ldloc.1
		/* 0x0000285B 9A                 */ IL_0017: ldelem.ref
		/* 0x0000285C 0C                 */ IL_0018: stloc.2
		/* 0x0000285D 02                 */ IL_0019: ldarg.0
		/* 0x0000285E 7B1C000004         */ IL_001a: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_FontFamilies /* 0400001C */
		/* 0x00002863 08                 */ IL_001f: ldloc.2
		/* 0x00002864 6F2E00000A         */ IL_0020: callvirt instance string [System.Drawing]System.Drawing.FontFamily::get_Name() /* 0A00002E */
		/* 0x00002869 6F2F00000A         */ IL_0025: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Add(!0) /* 0A00002F */
		/* 0x0000286E 07                 */ IL_002a: ldloc.1
		/* 0x0000286F 17                 */ IL_002b: ldc.i4.1
		/* 0x00002870 58                 */ IL_002c: add
		/* 0x00002871 0B                 */ IL_002d: stloc.1
		/* 0x00002872 07                 */ IL_002e: ldloc.1
		/* 0x00002873 06                 */ IL_002f: ldloc.0
		/* 0x00002874 8E                 */ IL_0030: ldlen
		/* 0x00002875 69                 */ IL_0031: conv.i4
		/* 0x00002876 32E1               */ IL_0032: blt.s IL_0015
		/* 0x00002878 2A                 */ IL_0034: ret
	} // end of method GeneralPage::GetFontFamilies

	.method /* 06000070 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> get_SystemFontFamilies () cil managed 
	{
		// Method begins at RVA 0x2885
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002885 02                 */ IL_0000: ldarg.0
		/* 0x00002886 7B1C000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::m_FontFamilies /* 0400001C */
		/* 0x0000288B 2A                 */ IL_0006: ret
	} // end of method GeneralPage::get_SystemFontFamilies

	.method /* 06000071 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> get_ToolBarPositions () cil managed 
	{
		// Method begins at RVA 0x288d
		// Header size: 1
		// Code size: 44 (0x2c)
		.maxstack 8

		/* 0x0000288D 1A                 */ IL_0000: ldc.i4.4
		/* 0x0000288E 8D3C000001         */ IL_0001: newarr [mscorlib]System.String /* 0100003C */
		/* 0x00002893 25                 */ IL_0006: dup
		/* 0x00002894 16                 */ IL_0007: ldc.i4.0
		/* 0x00002895 283000000A         */ IL_0008: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R309_NoneString() /* 0A000030 */
		/* 0x0000289A A2                 */ IL_000d: stelem.ref
		/* 0x0000289B 25                 */ IL_000e: dup
		/* 0x0000289C 17                 */ IL_000f: ldc.i4.1
		/* 0x0000289D 283100000A         */ IL_0010: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R310_TopString() /* 0A000031 */
		/* 0x000028A2 A2                 */ IL_0015: stelem.ref
		/* 0x000028A3 25                 */ IL_0016: dup
		/* 0x000028A4 18                 */ IL_0017: ldc.i4.2
		/* 0x000028A5 283200000A         */ IL_0018: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R311_BottomString() /* 0A000032 */
		/* 0x000028AA A2                 */ IL_001d: stelem.ref
		/* 0x000028AB 25                 */ IL_001e: dup
		/* 0x000028AC 19                 */ IL_001f: ldc.i4.3
		/* 0x000028AD 283300000A         */ IL_0020: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R312_RightString() /* 0A000033 */
		/* 0x000028B2 A2                 */ IL_0025: stelem.ref
		/* 0x000028B3 733400000A         */ IL_0026: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<string>::.ctor(class [mscorlib]System.Collections.Generic.IEnumerable`1<!0>) /* 0A000034 */
		/* 0x000028B8 2A                 */ IL_002b: ret
	} // end of method GeneralPage::get_ToolBarPositions

	.method /* 06000072 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000040 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x28bc
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000028BC 02                 */ IL_0000: ldarg.0
		/* 0x000028BD 7B24000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::PropertyChanged /* 04000024 */
		/* 0x000028C2 0A                 */ IL_0006: stloc.0
		/* 0x000028C3 06                 */ IL_0007: ldloc.0
		/* 0x000028C4 0B                 */ IL_0008: stloc.1
		/* 0x000028C5 07                 */ IL_0009: ldloc.1
		/* 0x000028C6 03                 */ IL_000a: ldarg.1
		/* 0x000028C7 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000028CC 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x000028D1 0C                 */ IL_0015: stloc.2
		/* 0x000028D2 02                 */ IL_0016: ldarg.0
		/* 0x000028D3 7C24000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::PropertyChanged /* 04000024 */
		/* 0x000028D8 08                 */ IL_001c: ldloc.2
		/* 0x000028D9 07                 */ IL_001d: ldloc.1
		/* 0x000028DA 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x000028DF 0A                 */ IL_0023: stloc.0
		/* 0x000028E0 06                 */ IL_0024: ldloc.0
		/* 0x000028E1 07                 */ IL_0025: ldloc.1
		/* 0x000028E2 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000028E4 2A                 */ IL_0028: ret
	} // end of method GeneralPage::add_PropertyChanged

	.method /* 06000073 */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000041 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x28f4
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000028F4 02                 */ IL_0000: ldarg.0
		/* 0x000028F5 7B24000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::PropertyChanged /* 04000024 */
		/* 0x000028FA 0A                 */ IL_0006: stloc.0
		/* 0x000028FB 06                 */ IL_0007: ldloc.0
		/* 0x000028FC 0B                 */ IL_0008: stloc.1
		/* 0x000028FD 07                 */ IL_0009: ldloc.1
		/* 0x000028FE 03                 */ IL_000a: ldarg.1
		/* 0x000028FF 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x00002904 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x00002909 0C                 */ IL_0015: stloc.2
		/* 0x0000290A 02                 */ IL_0016: ldarg.0
		/* 0x0000290B 7C24000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::PropertyChanged /* 04000024 */
		/* 0x00002910 08                 */ IL_001c: ldloc.2
		/* 0x00002911 07                 */ IL_001d: ldloc.1
		/* 0x00002912 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00002917 0A                 */ IL_0023: stloc.0
		/* 0x00002918 06                 */ IL_0024: ldloc.0
		/* 0x00002919 07                 */ IL_0025: ldloc.1
		/* 0x0000291A 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x0000291C 2A                 */ IL_0028: ret
	} // end of method GeneralPage::remove_PropertyChanged

	.method /* 06000074 */ private hidebysig 
		instance void OnPropertyChanged (
			string propertyName
		) cil managed 
	{
		// Method begins at RVA 0x2929
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x00002929 02                 */ IL_0000: ldarg.0
		/* 0x0000292A 7B24000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::PropertyChanged /* 04000024 */
		/* 0x0000292F 2C12               */ IL_0006: brfalse.s IL_001a
		/* 0x00002931 02                 */ IL_0008: ldarg.0
		/* 0x00002932 7B24000004         */ IL_0009: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::PropertyChanged /* 04000024 */
		/* 0x00002937 02                 */ IL_000e: ldarg.0
		/* 0x00002938 03                 */ IL_000f: ldarg.1
		/* 0x00002939 732600000A         */ IL_0010: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000026 */
		/* 0x0000293E 6F2700000A         */ IL_0015: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000027 */
		/* 0x00002943 2A                 */ IL_001a: ret
	} // end of method GeneralPage::OnPropertyChanged

	// Events
	.event /* 14000003 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 1700003A */ instance bool Coord()
	{
		.get instance bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_Coord()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_Coord(bool)
	}
	.property /* 1700003B */ instance bool BoilingPoint()
	{
		.get instance bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_BoilingPoint()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_BoilingPoint(bool)
	}
	.property /* 1700003C */ instance bool Transparent()
	{
		.get instance bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_Transparent()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_Transparent(bool)
	}
	.property /* 1700003D */ instance bool Stages()
	{
		.get instance bool AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_Stages()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_Stages(bool)
	}
	.property /* 1700003E */ instance string Font()
	{
		.get instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_Font()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_Font(string)
	}
	.property /* 1700003F */ instance int32 FontSize()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_FontSize()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_FontSize(int32)
	}
	.property /* 17000040 */ instance int64 ToolBarPos()
	{
		.get instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPos()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_ToolBarPos(int64)
	}
	.property /* 17000041 */ instance string ToolBarPosString()
	{
		.get instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPosString()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::set_ToolBarPosString(string)
	}
	.property /* 17000042 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> SystemFontFamilies()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_SystemFontFamilies()
	}
	.property /* 17000043 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> ToolBarPositions()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<string> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::get_ToolBarPositions()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage

.class /* 02000008 */ private auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000025 */ public static initonly int32 SW_SHOWNORMAL
	.field /* 04000026 */ public static initonly class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> BuiltInColors

	// Methods
	.method /* 06000075 */ public hidebysig static 
		void FillColour (
			class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker myColorPicker
		) cil managed 
	{
		// Method begins at RVA 0x2948
		// Header size: 12
		// Code size: 127 (0x7f)
		.maxstack 3
		.locals /* 11000005 */ init (
			[0] class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette,
			[1] class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette,
			[2] int32,
			[3] int32
		)

		/* 0x00002948 733500000A         */ IL_0000: newobj instance void [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette::.ctor() /* 0A000035 */
		/* 0x0000294D 0A                 */ IL_0005: stloc.0
		/* 0x0000294E 16                 */ IL_0006: ldc.i4.0
		/* 0x0000294F 0C                 */ IL_0007: stloc.2
		/* 0x00002950 2B1A               */ IL_0008: br.s IL_0024
		/* 0x00002952 06                 */ IL_000a: ldloc.0
		/* 0x00002953 6F3600000A         */ IL_000b: callvirt instance class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPatchCollection [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette::get_Colors() /* 0A000036 */
		/* 0x00002958 7E26000004         */ IL_0010: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x0000295D 08                 */ IL_0015: ldloc.2
		/* 0x0000295E 6F3700000A         */ IL_0016: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::get_Item(int32) /* 0A000037 */
		/* 0x00002963 6F3800000A         */ IL_001b: callvirt instance void [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPatchCollection::Add(valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000038 */
		/* 0x00002968 08                 */ IL_0020: ldloc.2
		/* 0x00002969 17                 */ IL_0021: ldc.i4.1
		/* 0x0000296A 58                 */ IL_0022: add
		/* 0x0000296B 0C                 */ IL_0023: stloc.2
		/* 0x0000296C 08                 */ IL_0024: ldloc.2
		/* 0x0000296D 1F09               */ IL_0025: ldc.i4.s 9
		/* 0x0000296F 31E1               */ IL_0027: ble.s IL_000a
		/* 0x00002971 733500000A         */ IL_0029: newobj instance void [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette::.ctor() /* 0A000035 */
		/* 0x00002976 0B                 */ IL_002e: stloc.1
		/* 0x00002977 1F0A               */ IL_002f: ldc.i4.s 10
		/* 0x00002979 0D                 */ IL_0031: stloc.3
		/* 0x0000297A 2B1A               */ IL_0032: br.s IL_004e
		/* 0x0000297C 07                 */ IL_0034: ldloc.1
		/* 0x0000297D 6F3600000A         */ IL_0035: callvirt instance class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPatchCollection [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette::get_Colors() /* 0A000036 */
		/* 0x00002982 7E26000004         */ IL_003a: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x00002987 09                 */ IL_003f: ldloc.3
		/* 0x00002988 6F3700000A         */ IL_0040: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::get_Item(int32) /* 0A000037 */
		/* 0x0000298D 6F3800000A         */ IL_0045: callvirt instance void [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPatchCollection::Add(valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000038 */
		/* 0x00002992 09                 */ IL_004a: ldloc.3
		/* 0x00002993 17                 */ IL_004b: ldc.i4.1
		/* 0x00002994 58                 */ IL_004c: add
		/* 0x00002995 0D                 */ IL_004d: stloc.3
		/* 0x00002996 09                 */ IL_004e: ldloc.3
		/* 0x00002997 7E26000004         */ IL_004f: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x0000299C 6F3900000A         */ IL_0054: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::get_Count() /* 0A000039 */
		/* 0x000029A1 32D9               */ IL_0059: blt.s IL_0034
		/* 0x000029A3 02                 */ IL_005b: ldarg.0
		/* 0x000029A4 6F3A00000A         */ IL_005c: callvirt instance class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPaletteCollection [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker::get_ColorPalettes() /* 0A00003A */
		/* 0x000029A9 6F3B00000A         */ IL_0061: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette>::Clear() /* 0A00003B */
		/* 0x000029AE 02                 */ IL_0066: ldarg.0
		/* 0x000029AF 6F3A00000A         */ IL_0067: callvirt instance class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPaletteCollection [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker::get_ColorPalettes() /* 0A00003A */
		/* 0x000029B4 06                 */ IL_006c: ldloc.0
		/* 0x000029B5 6F3C00000A         */ IL_006d: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette>::Add(!0) /* 0A00003C */
		/* 0x000029BA 02                 */ IL_0072: ldarg.0
		/* 0x000029BB 6F3A00000A         */ IL_0073: callvirt instance class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPaletteCollection [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker::get_ColorPalettes() /* 0A00003A */
		/* 0x000029C0 07                 */ IL_0078: ldloc.1
		/* 0x000029C1 6F3C00000A         */ IL_0079: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.ColorPalette>::Add(!0) /* 0A00003C */
		/* 0x000029C6 2A                 */ IL_007e: ret
	} // end of method Globals::FillColour

	.method /* 06000076 */ public hidebysig static 
		int32 GetColorIndex (
			valuetype [PresentationCore]System.Windows.Media.Color selectedColor
		) cil managed 
	{
		// Method begins at RVA 0x29d4
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 2
		.locals /* 11000003 */ init (
			[0] int32
		)

		/* 0x000029D4 7E26000004         */ IL_0000: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x000029D9 02                 */ IL_0005: ldarg.0
		/* 0x000029DA 6F3D00000A         */ IL_0006: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::IndexOf(!0) /* 0A00003D */
		/* 0x000029DF 0A                 */ IL_000b: stloc.0
		/* 0x000029E0 06                 */ IL_000c: ldloc.0
		/* 0x000029E1 16                 */ IL_000d: ldc.i4.0
		/* 0x000029E2 2F02               */ IL_000e: bge.s IL_0012
		/* 0x000029E4 16                 */ IL_0010: ldc.i4.0
		/* 0x000029E5 0A                 */ IL_0011: stloc.0
		/* 0x000029E6 06                 */ IL_0012: ldloc.0
		/* 0x000029E7 2A                 */ IL_0013: ret
	} // end of method Globals::GetColorIndex

	.method /* 06000077 */ public hidebysig static 
		valuetype [PresentationCore]System.Windows.Media.Color GetColorByIndex (
			int32 selectedColorIndex
		) cil managed 
	{
		// Method begins at RVA 0x29f4
		// Header size: 1
		// Code size: 41 (0x29)
		.maxstack 8

		/* 0x000029F4 02                 */ IL_0000: ldarg.0
		/* 0x000029F5 16                 */ IL_0001: ldc.i4.0
		/* 0x000029F6 3219               */ IL_0002: blt.s IL_001d
		/* 0x000029F8 02                 */ IL_0004: ldarg.0
		/* 0x000029F9 7E26000004         */ IL_0005: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x000029FE 6F3900000A         */ IL_000a: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::get_Count() /* 0A000039 */
		/* 0x00002A03 2F0C               */ IL_000f: bge.s IL_001d
		/* 0x00002A05 7E26000004         */ IL_0011: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x00002A0A 02                 */ IL_0016: ldarg.0
		/* 0x00002A0B 6F3700000A         */ IL_0017: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::get_Item(int32) /* 0A000037 */
		/* 0x00002A10 2A                 */ IL_001c: ret
		/* 0x00002A11 7E26000004         */ IL_001d: ldsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x00002A16 16                 */ IL_0022: ldc.i4.0
		/* 0x00002A17 6F3700000A         */ IL_0023: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::get_Item(int32) /* 0A000037 */
		/* 0x00002A1C 2A                 */ IL_0028: ret
	} // end of method Globals::GetColorByIndex

	.method /* 06000078 */ public hidebysig static 
		int64 StartURL (
			string URL
		) cil managed 
	{
		// Method begins at RVA 0x2a1e
		// Header size: 1
		// Code size: 10 (0xa)
		.maxstack 8

		/* 0x00002A1E 02                 */ IL_0000: ldarg.0
		/* 0x00002A1F 283E00000A         */ IL_0001: call class [System]System.Diagnostics.Process [System]System.Diagnostics.Process::Start(string) /* 0A00003E */
		/* 0x00002A24 26                 */ IL_0006: pop
		/* 0x00002A25 16                 */ IL_0007: ldc.i4.0
		/* 0x00002A26 6A                 */ IL_0008: conv.i8
		/* 0x00002A27 2A                 */ IL_0009: ret
	} // end of method Globals::StartURL

	.method /* 06000079 */ public hidebysig static 
		class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> GetMarkStyleList () cil managed 
	{
		// Method begins at RVA 0x2a2c
		// Header size: 12
		// Code size: 254 (0xfe)
		.maxstack 4

		/* 0x00002A2C 733F00000A         */ IL_0000: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::.ctor() /* 0A00003F */
		/* 0x00002A31 25                 */ IL_0005: dup
		/* 0x00002A32 14                 */ IL_0006: ldnull
		/* 0x00002A33 284000000A         */ IL_0007: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R104_NoneItemString() /* 0A000040 */
		/* 0x00002A38 732A000006         */ IL_000c: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002A3D 6F4100000A         */ IL_0011: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002A42 25                 */ IL_0016: dup
		/* 0x00002A43 2801000006         */ IL_0017: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Circle() /* 06000001 */
		/* 0x00002A48 7299040070         */ IL_001c: ldstr "1" /* 70000499 */
		/* 0x00002A4D 732A000006         */ IL_0021: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002A52 6F4100000A         */ IL_0026: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002A57 25                 */ IL_002b: dup
		/* 0x00002A58 2812000006         */ IL_002c: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Square() /* 06000012 */
		/* 0x00002A5D 729D040070         */ IL_0031: ldstr "2" /* 7000049D */
		/* 0x00002A62 732A000006         */ IL_0036: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002A67 6F4100000A         */ IL_003b: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002A6C 25                 */ IL_0040: dup
		/* 0x00002A6D 2808000006         */ IL_0041: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Diamond() /* 06000008 */
		/* 0x00002A72 72A1040070         */ IL_0046: ldstr "3" /* 700004A1 */
		/* 0x00002A77 732A000006         */ IL_004b: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002A7C 6F4100000A         */ IL_0050: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002A81 25                 */ IL_0055: dup
		/* 0x00002A82 281B000006         */ IL_0056: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriUp() /* 0600001B */
		/* 0x00002A87 72A5040070         */ IL_005b: ldstr "4" /* 700004A5 */
		/* 0x00002A8C 732A000006         */ IL_0060: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002A91 6F4100000A         */ IL_0065: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002A96 25                 */ IL_006a: dup
		/* 0x00002A97 2819000006         */ IL_006b: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriDown() /* 06000019 */
		/* 0x00002A9C 72A9040070         */ IL_0070: ldstr "5" /* 700004A9 */
		/* 0x00002AA1 732A000006         */ IL_0075: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002AA6 6F4100000A         */ IL_007a: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002AAB 25                 */ IL_007f: dup
		/* 0x00002AAC 2802000006         */ IL_0080: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_CircleFill() /* 06000002 */
		/* 0x00002AB1 72AD040070         */ IL_0085: ldstr "6" /* 700004AD */
		/* 0x00002AB6 732A000006         */ IL_008a: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002ABB 6F4100000A         */ IL_008f: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002AC0 25                 */ IL_0094: dup
		/* 0x00002AC1 2813000006         */ IL_0095: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_SquareFill() /* 06000013 */
		/* 0x00002AC6 72B1040070         */ IL_009a: ldstr "7" /* 700004B1 */
		/* 0x00002ACB 732A000006         */ IL_009f: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002AD0 6F4100000A         */ IL_00a4: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002AD5 25                 */ IL_00a9: dup
		/* 0x00002AD6 2809000006         */ IL_00aa: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DiamondFill() /* 06000009 */
		/* 0x00002ADB 72B5040070         */ IL_00af: ldstr "8" /* 700004B5 */
		/* 0x00002AE0 732A000006         */ IL_00b4: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002AE5 6F4100000A         */ IL_00b9: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002AEA 25                 */ IL_00be: dup
		/* 0x00002AEB 281C000006         */ IL_00bf: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriUpFill() /* 0600001C */
		/* 0x00002AF0 72B9040070         */ IL_00c4: ldstr "9" /* 700004B9 */
		/* 0x00002AF5 732A000006         */ IL_00c9: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002AFA 6F4100000A         */ IL_00ce: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002AFF 25                 */ IL_00d3: dup
		/* 0x00002B00 281A000006         */ IL_00d4: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_TriDownFill() /* 0600001A */
		/* 0x00002B05 72BD040070         */ IL_00d9: ldstr "10" /* 700004BD */
		/* 0x00002B0A 732A000006         */ IL_00de: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002B0F 6F4100000A         */ IL_00e3: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002B14 25                 */ IL_00e8: dup
		/* 0x00002B15 2804000006         */ IL_00e9: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Cross() /* 06000004 */
		/* 0x00002B1A 72C3040070         */ IL_00ee: ldstr "11" /* 700004C3 */
		/* 0x00002B1F 732A000006         */ IL_00f3: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002B24 6F4100000A         */ IL_00f8: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002B29 2A                 */ IL_00fd: ret
	} // end of method Globals::GetMarkStyleList

	.method /* 0600007A */ public hidebysig static 
		class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> GetEnvPatternList () cil managed 
	{
		// Method begins at RVA 0x2b38
		// Header size: 12
		// Code size: 216 (0xd8)
		.maxstack 4

		/* 0x00002B38 733F00000A         */ IL_0000: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::.ctor() /* 0A00003F */
		/* 0x00002B3D 25                 */ IL_0005: dup
		/* 0x00002B3E 2811000006         */ IL_0006: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Solid() /* 06000011 */
		/* 0x00002B43 72C9040070         */ IL_000b: ldstr "" /* 700004C9 */
		/* 0x00002B48 732A000006         */ IL_0010: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002B4D 6F4100000A         */ IL_0015: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002B52 25                 */ IL_001a: dup
		/* 0x00002B53 2806000006         */ IL_001b: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DiagLeft() /* 06000006 */
		/* 0x00002B58 72C9040070         */ IL_0020: ldstr "" /* 700004C9 */
		/* 0x00002B5D 732A000006         */ IL_0025: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002B62 6F4100000A         */ IL_002a: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002B67 25                 */ IL_002f: dup
		/* 0x00002B68 280F000006         */ IL_0030: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_HorizVert() /* 0600000F */
		/* 0x00002B6D 72C9040070         */ IL_0035: ldstr "" /* 700004C9 */
		/* 0x00002B72 732A000006         */ IL_003a: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002B77 6F4100000A         */ IL_003f: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002B7C 25                 */ IL_0044: dup
		/* 0x00002B7D 2803000006         */ IL_0045: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_CrisCross() /* 06000003 */
		/* 0x00002B82 72C9040070         */ IL_004a: ldstr "" /* 700004C9 */
		/* 0x00002B87 732A000006         */ IL_004f: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002B8C 6F4100000A         */ IL_0054: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002B91 25                 */ IL_0059: dup
		/* 0x00002B92 2807000006         */ IL_005a: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DiagRight() /* 06000007 */
		/* 0x00002B97 72C9040070         */ IL_005f: ldstr "" /* 700004C9 */
		/* 0x00002B9C 732A000006         */ IL_0064: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002BA1 6F4100000A         */ IL_0069: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002BA6 25                 */ IL_006e: dup
		/* 0x00002BA7 2814000006         */ IL_006f: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_StripeHoriz() /* 06000014 */
		/* 0x00002BAC 72C9040070         */ IL_0074: ldstr "" /* 700004C9 */
		/* 0x00002BB1 732A000006         */ IL_0079: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002BB6 6F4100000A         */ IL_007e: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002BBB 25                 */ IL_0083: dup
		/* 0x00002BBC 2815000006         */ IL_0084: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_StripeVert() /* 06000015 */
		/* 0x00002BC1 72C9040070         */ IL_0089: ldstr "" /* 700004C9 */
		/* 0x00002BC6 732A000006         */ IL_008e: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002BCB 6F4100000A         */ IL_0093: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002BD0 25                 */ IL_0098: dup
		/* 0x00002BD1 280B000006         */ IL_0099: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dot1() /* 0600000B */
		/* 0x00002BD6 72C9040070         */ IL_009e: ldstr "" /* 700004C9 */
		/* 0x00002BDB 732A000006         */ IL_00a3: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002BE0 6F4100000A         */ IL_00a8: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002BE5 25                 */ IL_00ad: dup
		/* 0x00002BE6 280C000006         */ IL_00ae: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dot2() /* 0600000C */
		/* 0x00002BEB 72C9040070         */ IL_00b3: ldstr "" /* 700004C9 */
		/* 0x00002BF0 732A000006         */ IL_00b8: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002BF5 6F4100000A         */ IL_00bd: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002BFA 25                 */ IL_00c2: dup
		/* 0x00002BFB 280D000006         */ IL_00c3: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dot3() /* 0600000D */
		/* 0x00002C00 72C9040070         */ IL_00c8: ldstr "" /* 700004C9 */
		/* 0x00002C05 732A000006         */ IL_00cd: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C0A 6F4100000A         */ IL_00d2: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C0F 2A                 */ IL_00d7: ret
	} // end of method Globals::GetEnvPatternList

	.method /* 0600007B */ public hidebysig static 
		class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> GetLineStyleList () cil managed 
	{
		// Method begins at RVA 0x2c1c
		// Header size: 12
		// Code size: 153 (0x99)
		.maxstack 4

		/* 0x00002C1C 733F00000A         */ IL_0000: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::.ctor() /* 0A00003F */
		/* 0x00002C21 25                 */ IL_0005: dup
		/* 0x00002C22 2810000006         */ IL_0006: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Normal() /* 06000010 */
		/* 0x00002C27 72C9040070         */ IL_000b: ldstr "" /* 700004C9 */
		/* 0x00002C2C 732A000006         */ IL_0010: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C31 6F4100000A         */ IL_0015: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C36 25                 */ IL_001a: dup
		/* 0x00002C37 280E000006         */ IL_001b: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dotted() /* 0600000E */
		/* 0x00002C3C 72C9040070         */ IL_0020: ldstr "" /* 700004C9 */
		/* 0x00002C41 732A000006         */ IL_0025: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C46 6F4100000A         */ IL_002a: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C4B 25                 */ IL_002f: dup
		/* 0x00002C4C 2805000006         */ IL_0030: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Dashed() /* 06000005 */
		/* 0x00002C51 72C9040070         */ IL_0035: ldstr "" /* 700004C9 */
		/* 0x00002C56 732A000006         */ IL_003a: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C5B 6F4100000A         */ IL_003f: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C60 25                 */ IL_0044: dup
		/* 0x00002C61 280A000006         */ IL_0045: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_DotDashed() /* 0600000A */
		/* 0x00002C66 72C9040070         */ IL_004a: ldstr "" /* 700004C9 */
		/* 0x00002C6B 732A000006         */ IL_004f: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C70 6F4100000A         */ IL_0054: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C75 25                 */ IL_0059: dup
		/* 0x00002C76 2816000006         */ IL_005a: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Thick1() /* 06000016 */
		/* 0x00002C7B 72C9040070         */ IL_005f: ldstr "" /* 700004C9 */
		/* 0x00002C80 732A000006         */ IL_0064: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C85 6F4100000A         */ IL_0069: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C8A 25                 */ IL_006e: dup
		/* 0x00002C8B 2817000006         */ IL_006f: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Thick2() /* 06000017 */
		/* 0x00002C90 72C9040070         */ IL_0074: ldstr "" /* 700004C9 */
		/* 0x00002C95 732A000006         */ IL_0079: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002C9A 6F4100000A         */ IL_007e: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002C9F 25                 */ IL_0083: dup
		/* 0x00002CA0 2818000006         */ IL_0084: call class [PresentationCore]System.Windows.Media.ImageSource AspenTech.AspenPlus.WpfPropertyControl.Images.ImageResources::get_Thick3() /* 06000018 */
		/* 0x00002CA5 72C9040070         */ IL_0089: ldstr "" /* 700004C9 */
		/* 0x00002CAA 732A000006         */ IL_008e: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass::.ctor(class [PresentationCore]System.Windows.Media.ImageSource, string) /* 0600002A */
		/* 0x00002CAF 6F4100000A         */ IL_0093: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass>::Add(!0) /* 0A000041 */
		/* 0x00002CB4 2A                 */ IL_0098: ret
	} // end of method Globals::GetLineStyleList

	.method /* 0600007C */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2261
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002261 02                 */ IL_0000: ldarg.0
		/* 0x00002262 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002267 2A                 */ IL_0006: ret
	} // end of method Globals::.ctor

	.method /* 0600007D */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2cc4
		// Header size: 12
		// Code size: 406 (0x196)
		.maxstack 5

		/* 0x00002CC4 17                 */ IL_0000: ldc.i4.1
		/* 0x00002CC5 8025000004         */ IL_0001: stsfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::SW_SHOWNORMAL /* 04000025 */
		/* 0x00002CCA 734200000A         */ IL_0006: newobj instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::.ctor() /* 0A000042 */
		/* 0x00002CCF 25                 */ IL_000b: dup
		/* 0x00002CD0 16                 */ IL_000c: ldc.i4.0
		/* 0x00002CD1 16                 */ IL_000d: ldc.i4.0
		/* 0x00002CD2 16                 */ IL_000e: ldc.i4.0
		/* 0x00002CD3 284300000A         */ IL_000f: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002CD8 6F4400000A         */ IL_0014: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002CDD 25                 */ IL_0019: dup
		/* 0x00002CDE 1F40               */ IL_001a: ldc.i4.s 64
		/* 0x00002CE0 1F40               */ IL_001c: ldc.i4.s 64
		/* 0x00002CE2 20C0000000         */ IL_001e: ldc.i4 192
		/* 0x00002CE7 284300000A         */ IL_0023: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002CEC 6F4400000A         */ IL_0028: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002CF1 25                 */ IL_002d: dup
		/* 0x00002CF2 16                 */ IL_002e: ldc.i4.0
		/* 0x00002CF3 2080000000         */ IL_002f: ldc.i4 128
		/* 0x00002CF8 16                 */ IL_0034: ldc.i4.0
		/* 0x00002CF9 284300000A         */ IL_0035: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002CFE 6F4400000A         */ IL_003a: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D03 25                 */ IL_003f: dup
		/* 0x00002D04 20FF000000         */ IL_0040: ldc.i4 255
		/* 0x00002D09 1F40               */ IL_0045: ldc.i4.s 64
		/* 0x00002D0B 2080000000         */ IL_0047: ldc.i4 128
		/* 0x00002D10 284300000A         */ IL_004c: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D15 6F4400000A         */ IL_0051: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D1A 25                 */ IL_0056: dup
		/* 0x00002D1B 20C0000000         */ IL_0057: ldc.i4 192
		/* 0x00002D20 1F40               */ IL_005c: ldc.i4.s 64
		/* 0x00002D22 20C0000000         */ IL_005e: ldc.i4 192
		/* 0x00002D27 284300000A         */ IL_0063: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D2C 6F4400000A         */ IL_0068: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D31 25                 */ IL_006d: dup
		/* 0x00002D32 2080000000         */ IL_006e: ldc.i4 128
		/* 0x00002D37 2080000000         */ IL_0073: ldc.i4 128
		/* 0x00002D3C 2080000000         */ IL_0078: ldc.i4 128
		/* 0x00002D41 284300000A         */ IL_007d: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D46 6F4400000A         */ IL_0082: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D4B 25                 */ IL_0087: dup
		/* 0x00002D4C 1F20               */ IL_0088: ldc.i4.s 32
		/* 0x00002D4E 20A0000000         */ IL_008a: ldc.i4 160
		/* 0x00002D53 20A0000000         */ IL_008f: ldc.i4 160
		/* 0x00002D58 284300000A         */ IL_0094: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D5D 6F4400000A         */ IL_0099: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D62 25                 */ IL_009e: dup
		/* 0x00002D63 20C0000000         */ IL_009f: ldc.i4 192
		/* 0x00002D68 20C0000000         */ IL_00a4: ldc.i4 192
		/* 0x00002D6D 20C0000000         */ IL_00a9: ldc.i4 192
		/* 0x00002D72 284300000A         */ IL_00ae: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D77 6F4400000A         */ IL_00b3: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D7C 25                 */ IL_00b8: dup
		/* 0x00002D7D 20C0000000         */ IL_00b9: ldc.i4 192
		/* 0x00002D82 20C0000000         */ IL_00be: ldc.i4 192
		/* 0x00002D87 16                 */ IL_00c3: ldc.i4.0
		/* 0x00002D88 284300000A         */ IL_00c4: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D8D 6F4400000A         */ IL_00c9: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002D92 25                 */ IL_00ce: dup
		/* 0x00002D93 16                 */ IL_00cf: ldc.i4.0
		/* 0x00002D94 16                 */ IL_00d0: ldc.i4.0
		/* 0x00002D95 20FF000000         */ IL_00d1: ldc.i4 255
		/* 0x00002D9A 284300000A         */ IL_00d6: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002D9F 6F4400000A         */ IL_00db: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002DA4 25                 */ IL_00e0: dup
		/* 0x00002DA5 16                 */ IL_00e1: ldc.i4.0
		/* 0x00002DA6 20FF000000         */ IL_00e2: ldc.i4 255
		/* 0x00002DAB 16                 */ IL_00e7: ldc.i4.0
		/* 0x00002DAC 284300000A         */ IL_00e8: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002DB1 6F4400000A         */ IL_00ed: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002DB6 25                 */ IL_00f2: dup
		/* 0x00002DB7 20FF000000         */ IL_00f3: ldc.i4 255
		/* 0x00002DBC 16                 */ IL_00f8: ldc.i4.0
		/* 0x00002DBD 16                 */ IL_00f9: ldc.i4.0
		/* 0x00002DBE 284300000A         */ IL_00fa: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002DC3 6F4400000A         */ IL_00ff: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002DC8 25                 */ IL_0104: dup
		/* 0x00002DC9 20FF000000         */ IL_0105: ldc.i4 255
		/* 0x00002DCE 16                 */ IL_010a: ldc.i4.0
		/* 0x00002DCF 20FF000000         */ IL_010b: ldc.i4 255
		/* 0x00002DD4 284300000A         */ IL_0110: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002DD9 6F4400000A         */ IL_0115: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002DDE 25                 */ IL_011a: dup
		/* 0x00002DDF 20E0000000         */ IL_011b: ldc.i4 224
		/* 0x00002DE4 20E0000000         */ IL_0120: ldc.i4 224
		/* 0x00002DE9 20E0000000         */ IL_0125: ldc.i4 224
		/* 0x00002DEE 284300000A         */ IL_012a: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002DF3 6F4400000A         */ IL_012f: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002DF8 25                 */ IL_0134: dup
		/* 0x00002DF9 16                 */ IL_0135: ldc.i4.0
		/* 0x00002DFA 20FF000000         */ IL_0136: ldc.i4 255
		/* 0x00002DFF 20FF000000         */ IL_013b: ldc.i4 255
		/* 0x00002E04 284300000A         */ IL_0140: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002E09 6F4400000A         */ IL_0145: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002E0E 25                 */ IL_014a: dup
		/* 0x00002E0F 20FF000000         */ IL_014b: ldc.i4 255
		/* 0x00002E14 20FF000000         */ IL_0150: ldc.i4 255
		/* 0x00002E19 16                 */ IL_0155: ldc.i4.0
		/* 0x00002E1A 284300000A         */ IL_0156: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002E1F 6F4400000A         */ IL_015b: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002E24 25                 */ IL_0160: dup
		/* 0x00002E25 20FF000000         */ IL_0161: ldc.i4 255
		/* 0x00002E2A 20FF000000         */ IL_0166: ldc.i4 255
		/* 0x00002E2F 20FF000000         */ IL_016b: ldc.i4 255
		/* 0x00002E34 284300000A         */ IL_0170: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002E39 6F4400000A         */ IL_0175: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002E3E 25                 */ IL_017a: dup
		/* 0x00002E3F 20FF000000         */ IL_017b: ldc.i4 255
		/* 0x00002E44 2080000000         */ IL_0180: ldc.i4 128
		/* 0x00002E49 16                 */ IL_0185: ldc.i4.0
		/* 0x00002E4A 284300000A         */ IL_0186: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000043 */
		/* 0x00002E4F 6F4400000A         */ IL_018b: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color>::Add(!0) /* 0A000044 */
		/* 0x00002E54 8026000004         */ IL_0190: stsfld class [mscorlib]System.Collections.ObjectModel.Collection`1<valuetype [PresentationCore]System.Windows.Media.Color> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::BuiltInColors /* 04000026 */
		/* 0x00002E59 2A                 */ IL_0195: ret
	} // end of method Globals::.cctor

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals

.class /* 02000009 */ public auto ansi sealed AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings
	extends [mscorlib]System.Enum
{
	// Fields
	.field /* 04000027 */ public specialname rtspecialname int32 value__
	.field /* 04000028 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings set_AdjustYes = int32(0)
	.field /* 04000029 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings set_AdjustNo = int32(1)
	.field /* 0400002A */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings set_AdjustDefault = int32(2)

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings

.class /* 0200000A */ public auto ansi sealed AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum
	extends [mscorlib]System.Enum
{
	// Fields
	.field /* 0400002B */ public specialname rtspecialname int32 value__
	.field /* 0400002C */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_General = int32(0)
	.field /* 0400002D */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Azeotropes = int32(1)
	.field /* 0400002E */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Boundary = int32(2)
	.field /* 0400002F */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Envelope = int32(3)
	.field /* 04000030 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Curves = int32(4)
	.field /* 04000031 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Markers = int32(5)
	.field /* 04000032 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_FreeHand = int32(6)
	.field /* 04000033 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_MatBal = int32(7)
	.field /* 04000034 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Product = int32(8)
	.field /* 04000035 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Feed = int32(9)
	.field /* 04000036 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Profiles = int32(10)
	.field /* 04000037 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_Decanter = int32(11)
	.field /* 04000038 */ public static literal valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum page_ColumnVapor = int32(12)

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum

.class /* 0200000B */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 04000039 */ private int32 m_MarkerSize
	.field /* 0400003A */ private int32 m_LineStyle
	.field /* 0400003B */ private int32 m_MarkerStyle
	.field /* 0400003C */ private valuetype [PresentationCore]System.Windows.Media.Color m_LineColourValue
	.field /* 0400003D */ private int64 m_LineColourIndex
	.field /* 0400003E */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C00003A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600007E */ public hidebysig specialname 
		instance valuetype [PresentationCore]System.Windows.Media.Color get_LineColourValue () cil managed 
	{
		// Method begins at RVA 0x2e66
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x00002E66 02                 */ IL_0000: ldarg.0
		/* 0x00002E67 7B3C000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourValue /* 0400003C */
		/* 0x00002E6C 02                 */ IL_0006: ldarg.0
		/* 0x00002E6D 7B3D000004         */ IL_0007: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourIndex /* 0400003D */
		/* 0x00002E72 69                 */ IL_000c: conv.i4
		/* 0x00002E73 2877000006         */ IL_000d: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002E78 282200000A         */ IL_0012: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x00002E7D 2C12               */ IL_0017: brfalse.s IL_002b
		/* 0x00002E7F 02                 */ IL_0019: ldarg.0
		/* 0x00002E80 02                 */ IL_001a: ldarg.0
		/* 0x00002E81 7B3D000004         */ IL_001b: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourIndex /* 0400003D */
		/* 0x00002E86 69                 */ IL_0020: conv.i4
		/* 0x00002E87 2877000006         */ IL_0021: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002E8C 7D3C000004         */ IL_0026: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourValue /* 0400003C */
		/* 0x00002E91 02                 */ IL_002b: ldarg.0
		/* 0x00002E92 7B3C000004         */ IL_002c: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourValue /* 0400003C */
		/* 0x00002E97 2A                 */ IL_0031: ret
	} // end of method LinePage::get_LineColourValue

	.method /* 0600007F */ public hidebysig specialname 
		instance void set_LineColourValue (
			valuetype [PresentationCore]System.Windows.Media.Color 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2e99
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x00002E99 02                 */ IL_0000: ldarg.0
		/* 0x00002E9A 7B3C000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourValue /* 0400003C */
		/* 0x00002E9F 03                 */ IL_0006: ldarg.1
		/* 0x00002EA0 282200000A         */ IL_0007: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x00002EA5 2C1F               */ IL_000c: brfalse.s IL_002d
		/* 0x00002EA7 02                 */ IL_000e: ldarg.0
		/* 0x00002EA8 03                 */ IL_000f: ldarg.1
		/* 0x00002EA9 7D3C000004         */ IL_0010: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourValue /* 0400003C */
		/* 0x00002EAE 02                 */ IL_0015: ldarg.0
		/* 0x00002EAF 03                 */ IL_0016: ldarg.1
		/* 0x00002EB0 2876000006         */ IL_0017: call int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorIndex(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000076 */
		/* 0x00002EB5 6A                 */ IL_001c: conv.i8
		/* 0x00002EB6 2881000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_LineColour(int64) /* 06000081 */
		/* 0x00002EBB 02                 */ IL_0022: ldarg.0
		/* 0x00002EBC 72CB040070         */ IL_0023: ldstr "LineColourValue" /* 700004CB */
		/* 0x00002EC1 288A000006         */ IL_0028: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::OnPropertyChanged(string) /* 0600008A */
		/* 0x00002EC6 2A                 */ IL_002d: ret
	} // end of method LinePage::set_LineColourValue

	.method /* 06000080 */ public hidebysig specialname 
		instance int64 get_LineColour () cil managed 
	{
		// Method begins at RVA 0x2ec8
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002EC8 02                 */ IL_0000: ldarg.0
		/* 0x00002EC9 7B3D000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourIndex /* 0400003D */
		/* 0x00002ECE 2A                 */ IL_0006: ret
	} // end of method LinePage::get_LineColour

	.method /* 06000081 */ public hidebysig specialname 
		instance void set_LineColour (
			int64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2ed0
		// Header size: 1
		// Code size: 35 (0x23)
		.maxstack 8

		/* 0x00002ED0 02                 */ IL_0000: ldarg.0
		/* 0x00002ED1 7B3D000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourIndex /* 0400003D */
		/* 0x00002ED6 03                 */ IL_0006: ldarg.1
		/* 0x00002ED7 2E19               */ IL_0007: beq.s IL_0022
		/* 0x00002ED9 02                 */ IL_0009: ldarg.0
		/* 0x00002EDA 03                 */ IL_000a: ldarg.1
		/* 0x00002EDB 7D3D000004         */ IL_000b: stfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourIndex /* 0400003D */
		/* 0x00002EE0 02                 */ IL_0010: ldarg.0
		/* 0x00002EE1 02                 */ IL_0011: ldarg.0
		/* 0x00002EE2 7B3D000004         */ IL_0012: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineColourIndex /* 0400003D */
		/* 0x00002EE7 69                 */ IL_0017: conv.i4
		/* 0x00002EE8 2877000006         */ IL_0018: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002EED 287F000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_LineColourValue(valuetype [PresentationCore]System.Windows.Media.Color) /* 0600007F */
		/* 0x00002EF2 2A                 */ IL_0022: ret
	} // end of method LinePage::set_LineColour

	.method /* 06000082 */ public hidebysig specialname 
		instance int32 get_MarkerSize () cil managed 
	{
		// Method begins at RVA 0x2ef4
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002EF4 02                 */ IL_0000: ldarg.0
		/* 0x00002EF5 7B39000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_MarkerSize /* 04000039 */
		/* 0x00002EFA 2A                 */ IL_0006: ret
	} // end of method LinePage::get_MarkerSize

	.method /* 06000083 */ public hidebysig specialname 
		instance void set_MarkerSize (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2efc
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002EFC 02                 */ IL_0000: ldarg.0
		/* 0x00002EFD 7B39000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_MarkerSize /* 04000039 */
		/* 0x00002F02 03                 */ IL_0006: ldarg.1
		/* 0x00002F03 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002F05 02                 */ IL_0009: ldarg.0
		/* 0x00002F06 03                 */ IL_000a: ldarg.1
		/* 0x00002F07 7D39000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_MarkerSize /* 04000039 */
		/* 0x00002F0C 02                 */ IL_0010: ldarg.0
		/* 0x00002F0D 72EB040070         */ IL_0011: ldstr "MarkerSize" /* 700004EB */
		/* 0x00002F12 288A000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::OnPropertyChanged(string) /* 0600008A */
		/* 0x00002F17 2A                 */ IL_001b: ret
	} // end of method LinePage::set_MarkerSize

	.method /* 06000084 */ public hidebysig specialname 
		instance int32 get_LineStyle () cil managed 
	{
		// Method begins at RVA 0x2f19
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002F19 02                 */ IL_0000: ldarg.0
		/* 0x00002F1A 7B3A000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineStyle /* 0400003A */
		/* 0x00002F1F 2A                 */ IL_0006: ret
	} // end of method LinePage::get_LineStyle

	.method /* 06000085 */ public hidebysig specialname 
		instance void set_LineStyle (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2f21
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002F21 02                 */ IL_0000: ldarg.0
		/* 0x00002F22 7B3A000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineStyle /* 0400003A */
		/* 0x00002F27 03                 */ IL_0006: ldarg.1
		/* 0x00002F28 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002F2A 02                 */ IL_0009: ldarg.0
		/* 0x00002F2B 03                 */ IL_000a: ldarg.1
		/* 0x00002F2C 7D3A000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_LineStyle /* 0400003A */
		/* 0x00002F31 02                 */ IL_0010: ldarg.0
		/* 0x00002F32 72A1030070         */ IL_0011: ldstr "LineStyle" /* 700003A1 */
		/* 0x00002F37 288A000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::OnPropertyChanged(string) /* 0600008A */
		/* 0x00002F3C 2A                 */ IL_001b: ret
	} // end of method LinePage::set_LineStyle

	.method /* 06000086 */ public hidebysig specialname 
		instance int32 get_MarkerStyle () cil managed 
	{
		// Method begins at RVA 0x2f3e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002F3E 02                 */ IL_0000: ldarg.0
		/* 0x00002F3F 7B3B000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_MarkerStyle /* 0400003B */
		/* 0x00002F44 2A                 */ IL_0006: ret
	} // end of method LinePage::get_MarkerStyle

	.method /* 06000087 */ public hidebysig specialname 
		instance void set_MarkerStyle (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2f46
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002F46 02                 */ IL_0000: ldarg.0
		/* 0x00002F47 7B3B000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_MarkerStyle /* 0400003B */
		/* 0x00002F4C 03                 */ IL_0006: ldarg.1
		/* 0x00002F4D 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002F4F 02                 */ IL_0009: ldarg.0
		/* 0x00002F50 03                 */ IL_000a: ldarg.1
		/* 0x00002F51 7D3B000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::m_MarkerStyle /* 0400003B */
		/* 0x00002F56 02                 */ IL_0010: ldarg.0
		/* 0x00002F57 7201050070         */ IL_0011: ldstr "MarkerStyle" /* 70000501 */
		/* 0x00002F5C 288A000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::OnPropertyChanged(string) /* 0600008A */
		/* 0x00002F61 2A                 */ IL_001b: ret
	} // end of method LinePage::set_MarkerStyle

	.method /* 06000088 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000042 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2f64
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002F64 02                 */ IL_0000: ldarg.0
		/* 0x00002F65 7B3E000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::PropertyChanged /* 0400003E */
		/* 0x00002F6A 0A                 */ IL_0006: stloc.0
		/* 0x00002F6B 06                 */ IL_0007: ldloc.0
		/* 0x00002F6C 0B                 */ IL_0008: stloc.1
		/* 0x00002F6D 07                 */ IL_0009: ldloc.1
		/* 0x00002F6E 03                 */ IL_000a: ldarg.1
		/* 0x00002F6F 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x00002F74 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x00002F79 0C                 */ IL_0015: stloc.2
		/* 0x00002F7A 02                 */ IL_0016: ldarg.0
		/* 0x00002F7B 7C3E000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::PropertyChanged /* 0400003E */
		/* 0x00002F80 08                 */ IL_001c: ldloc.2
		/* 0x00002F81 07                 */ IL_001d: ldloc.1
		/* 0x00002F82 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00002F87 0A                 */ IL_0023: stloc.0
		/* 0x00002F88 06                 */ IL_0024: ldloc.0
		/* 0x00002F89 07                 */ IL_0025: ldloc.1
		/* 0x00002F8A 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002F8C 2A                 */ IL_0028: ret
	} // end of method LinePage::add_PropertyChanged

	.method /* 06000089 */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000043 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2f9c
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002F9C 02                 */ IL_0000: ldarg.0
		/* 0x00002F9D 7B3E000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::PropertyChanged /* 0400003E */
		/* 0x00002FA2 0A                 */ IL_0006: stloc.0
		/* 0x00002FA3 06                 */ IL_0007: ldloc.0
		/* 0x00002FA4 0B                 */ IL_0008: stloc.1
		/* 0x00002FA5 07                 */ IL_0009: ldloc.1
		/* 0x00002FA6 03                 */ IL_000a: ldarg.1
		/* 0x00002FA7 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x00002FAC 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x00002FB1 0C                 */ IL_0015: stloc.2
		/* 0x00002FB2 02                 */ IL_0016: ldarg.0
		/* 0x00002FB3 7C3E000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::PropertyChanged /* 0400003E */
		/* 0x00002FB8 08                 */ IL_001c: ldloc.2
		/* 0x00002FB9 07                 */ IL_001d: ldloc.1
		/* 0x00002FBA 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00002FBF 0A                 */ IL_0023: stloc.0
		/* 0x00002FC0 06                 */ IL_0024: ldloc.0
		/* 0x00002FC1 07                 */ IL_0025: ldloc.1
		/* 0x00002FC2 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002FC4 2A                 */ IL_0028: ret
	} // end of method LinePage::remove_PropertyChanged

	.method /* 0600008A */ private hidebysig 
		instance void OnPropertyChanged (
			string propName
		) cil managed 
	{
		// Method begins at RVA 0x2fd1
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x00002FD1 02                 */ IL_0000: ldarg.0
		/* 0x00002FD2 7B3E000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::PropertyChanged /* 0400003E */
		/* 0x00002FD7 2C12               */ IL_0006: brfalse.s IL_001a
		/* 0x00002FD9 02                 */ IL_0008: ldarg.0
		/* 0x00002FDA 7B3E000004         */ IL_0009: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::PropertyChanged /* 0400003E */
		/* 0x00002FDF 02                 */ IL_000e: ldarg.0
		/* 0x00002FE0 03                 */ IL_000f: ldarg.1
		/* 0x00002FE1 732600000A         */ IL_0010: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000026 */
		/* 0x00002FE6 6F2700000A         */ IL_0015: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000027 */
		/* 0x00002FEB 2A                 */ IL_001a: ret
	} // end of method LinePage::OnPropertyChanged

	.method /* 0600008B */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_MarkerItemList () cil managed 
	{
		// Method begins at RVA 0x23ee
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023EE 2879000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetMarkStyleList() /* 06000079 */
		/* 0x000023F3 2A                 */ IL_0005: ret
	} // end of method LinePage::get_MarkerItemList

	.method /* 0600008C */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_LineItemList () cil managed 
	{
		// Method begins at RVA 0x23e7
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023E7 287B000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetLineStyleList() /* 0600007B */
		/* 0x000023EC 2A                 */ IL_0005: ret
	} // end of method LinePage::get_LineItemList

	.method /* 0600008D */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2261
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002261 02                 */ IL_0000: ldarg.0
		/* 0x00002262 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002267 2A                 */ IL_0006: ret
	} // end of method LinePage::.ctor

	// Events
	.event /* 14000004 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 17000044 */ instance valuetype [PresentationCore]System.Windows.Media.Color LineColourValue()
	{
		.get instance valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_LineColourValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_LineColourValue(valuetype [PresentationCore]System.Windows.Media.Color)
	}
	.property /* 17000045 */ instance int64 LineColour()
	{
		.get instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_LineColour()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_LineColour(int64)
	}
	.property /* 17000046 */ instance int32 MarkerSize()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_MarkerSize()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_MarkerSize(int32)
	}
	.property /* 17000047 */ instance int32 LineStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_LineStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_LineStyle(int32)
	}
	.property /* 17000048 */ instance int32 MarkerStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_MarkerStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::set_MarkerStyle(int32)
	}
	.property /* 17000049 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> MarkerItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_MarkerItemList()
	}
	.property /* 1700004A */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> LineItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::get_LineItemList()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage

.class /* 0200000C */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 0400003F */ private int32 m_MarkerSize
	.field /* 04000040 */ private int32 m_MarkerStyleIndex
	.field /* 04000041 */ private int64 m_MarkerColorIndex
	.field /* 04000042 */ private valuetype [PresentationCore]System.Windows.Media.Color m_MarkerColorValue
	.field /* 04000043 */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C00003D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600008E */ public hidebysig specialname 
		instance valuetype [PresentationCore]System.Windows.Media.Color get_MarkerColorValue () cil managed 
	{
		// Method begins at RVA 0x2fed
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x00002FED 02                 */ IL_0000: ldarg.0
		/* 0x00002FEE 7B42000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorValue /* 04000042 */
		/* 0x00002FF3 02                 */ IL_0006: ldarg.0
		/* 0x00002FF4 7B41000004         */ IL_0007: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorIndex /* 04000041 */
		/* 0x00002FF9 69                 */ IL_000c: conv.i4
		/* 0x00002FFA 2877000006         */ IL_000d: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00002FFF 282200000A         */ IL_0012: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x00003004 2C12               */ IL_0017: brfalse.s IL_002b
		/* 0x00003006 02                 */ IL_0019: ldarg.0
		/* 0x00003007 02                 */ IL_001a: ldarg.0
		/* 0x00003008 7B41000004         */ IL_001b: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorIndex /* 04000041 */
		/* 0x0000300D 69                 */ IL_0020: conv.i4
		/* 0x0000300E 2877000006         */ IL_0021: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00003013 7D42000004         */ IL_0026: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorValue /* 04000042 */
		/* 0x00003018 02                 */ IL_002b: ldarg.0
		/* 0x00003019 7B42000004         */ IL_002c: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorValue /* 04000042 */
		/* 0x0000301E 2A                 */ IL_0031: ret
	} // end of method MarkerPage::get_MarkerColorValue

	.method /* 0600008F */ public hidebysig specialname 
		instance void set_MarkerColorValue (
			valuetype [PresentationCore]System.Windows.Media.Color 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3020
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x00003020 02                 */ IL_0000: ldarg.0
		/* 0x00003021 7B42000004         */ IL_0001: ldfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorValue /* 04000042 */
		/* 0x00003026 03                 */ IL_0006: ldarg.1
		/* 0x00003027 282200000A         */ IL_0007: call bool [PresentationCore]System.Windows.Media.Color::op_Inequality(valuetype [PresentationCore]System.Windows.Media.Color, valuetype [PresentationCore]System.Windows.Media.Color) /* 0A000022 */
		/* 0x0000302C 2C1F               */ IL_000c: brfalse.s IL_002d
		/* 0x0000302E 02                 */ IL_000e: ldarg.0
		/* 0x0000302F 03                 */ IL_000f: ldarg.1
		/* 0x00003030 7D42000004         */ IL_0010: stfld valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorValue /* 04000042 */
		/* 0x00003035 02                 */ IL_0015: ldarg.0
		/* 0x00003036 03                 */ IL_0016: ldarg.1
		/* 0x00003037 2876000006         */ IL_0017: call int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorIndex(valuetype [PresentationCore]System.Windows.Media.Color) /* 06000076 */
		/* 0x0000303C 6A                 */ IL_001c: conv.i8
		/* 0x0000303D 2891000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::set_MarkerColour(int64) /* 06000091 */
		/* 0x00003042 02                 */ IL_0022: ldarg.0
		/* 0x00003043 7219050070         */ IL_0023: ldstr "MarkerColorValue" /* 70000519 */
		/* 0x00003048 2899000006         */ IL_0028: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::OnPropertyChanged(string) /* 06000099 */
		/* 0x0000304D 2A                 */ IL_002d: ret
	} // end of method MarkerPage::set_MarkerColorValue

	.method /* 06000090 */ public hidebysig specialname 
		instance int64 get_MarkerColour () cil managed 
	{
		// Method begins at RVA 0x304f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000304F 02                 */ IL_0000: ldarg.0
		/* 0x00003050 7B41000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorIndex /* 04000041 */
		/* 0x00003055 2A                 */ IL_0006: ret
	} // end of method MarkerPage::get_MarkerColour

	.method /* 06000091 */ public hidebysig specialname 
		instance void set_MarkerColour (
			int64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3057
		// Header size: 1
		// Code size: 35 (0x23)
		.maxstack 8

		/* 0x00003057 02                 */ IL_0000: ldarg.0
		/* 0x00003058 7B41000004         */ IL_0001: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorIndex /* 04000041 */
		/* 0x0000305D 03                 */ IL_0006: ldarg.1
		/* 0x0000305E 2E19               */ IL_0007: beq.s IL_0022
		/* 0x00003060 02                 */ IL_0009: ldarg.0
		/* 0x00003061 03                 */ IL_000a: ldarg.1
		/* 0x00003062 7D41000004         */ IL_000b: stfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorIndex /* 04000041 */
		/* 0x00003067 02                 */ IL_0010: ldarg.0
		/* 0x00003068 02                 */ IL_0011: ldarg.0
		/* 0x00003069 7B41000004         */ IL_0012: ldfld int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerColorIndex /* 04000041 */
		/* 0x0000306E 69                 */ IL_0017: conv.i4
		/* 0x0000306F 2877000006         */ IL_0018: call valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetColorByIndex(int32) /* 06000077 */
		/* 0x00003074 288F000006         */ IL_001d: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::set_MarkerColorValue(valuetype [PresentationCore]System.Windows.Media.Color) /* 0600008F */
		/* 0x00003079 2A                 */ IL_0022: ret
	} // end of method MarkerPage::set_MarkerColour

	.method /* 06000092 */ public hidebysig specialname 
		instance int32 get_MarkerStyle () cil managed 
	{
		// Method begins at RVA 0x307b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000307B 02                 */ IL_0000: ldarg.0
		/* 0x0000307C 7B40000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerStyleIndex /* 04000040 */
		/* 0x00003081 2A                 */ IL_0006: ret
	} // end of method MarkerPage::get_MarkerStyle

	.method /* 06000093 */ public hidebysig specialname 
		instance void set_MarkerStyle (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3083
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00003083 02                 */ IL_0000: ldarg.0
		/* 0x00003084 7B40000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerStyleIndex /* 04000040 */
		/* 0x00003089 03                 */ IL_0006: ldarg.1
		/* 0x0000308A 2E12               */ IL_0007: beq.s IL_001b
		/* 0x0000308C 02                 */ IL_0009: ldarg.0
		/* 0x0000308D 03                 */ IL_000a: ldarg.1
		/* 0x0000308E 7D40000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerStyleIndex /* 04000040 */
		/* 0x00003093 02                 */ IL_0010: ldarg.0
		/* 0x00003094 7201050070         */ IL_0011: ldstr "MarkerStyle" /* 70000501 */
		/* 0x00003099 2899000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::OnPropertyChanged(string) /* 06000099 */
		/* 0x0000309E 2A                 */ IL_001b: ret
	} // end of method MarkerPage::set_MarkerStyle

	.method /* 06000094 */ public hidebysig specialname 
		instance int32 get_MarkerSize () cil managed 
	{
		// Method begins at RVA 0x30a0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000030A0 02                 */ IL_0000: ldarg.0
		/* 0x000030A1 7B3F000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerSize /* 0400003F */
		/* 0x000030A6 2A                 */ IL_0006: ret
	} // end of method MarkerPage::get_MarkerSize

	.method /* 06000095 */ public hidebysig specialname 
		instance void set_MarkerSize (
			int32 'value'
		) cil managed 
	{
		// Method begins at RVA 0x30a8
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000030A8 02                 */ IL_0000: ldarg.0
		/* 0x000030A9 7B3F000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerSize /* 0400003F */
		/* 0x000030AE 03                 */ IL_0006: ldarg.1
		/* 0x000030AF 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000030B1 02                 */ IL_0009: ldarg.0
		/* 0x000030B2 03                 */ IL_000a: ldarg.1
		/* 0x000030B3 7D3F000004         */ IL_000b: stfld int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::m_MarkerSize /* 0400003F */
		/* 0x000030B8 02                 */ IL_0010: ldarg.0
		/* 0x000030B9 72EB040070         */ IL_0011: ldstr "MarkerSize" /* 700004EB */
		/* 0x000030BE 2899000006         */ IL_0016: call instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::OnPropertyChanged(string) /* 06000099 */
		/* 0x000030C3 2A                 */ IL_001b: ret
	} // end of method MarkerPage::set_MarkerSize

	.method /* 06000096 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> get_ItemList () cil managed 
	{
		// Method begins at RVA 0x23ee
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023EE 2879000006         */ IL_0000: call class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::GetMarkStyleList() /* 06000079 */
		/* 0x000023F3 2A                 */ IL_0005: ret
	} // end of method MarkerPage::get_ItemList

	.method /* 06000097 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000044 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x30c8
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000030C8 02                 */ IL_0000: ldarg.0
		/* 0x000030C9 7B43000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::PropertyChanged /* 04000043 */
		/* 0x000030CE 0A                 */ IL_0006: stloc.0
		/* 0x000030CF 06                 */ IL_0007: ldloc.0
		/* 0x000030D0 0B                 */ IL_0008: stloc.1
		/* 0x000030D1 07                 */ IL_0009: ldloc.1
		/* 0x000030D2 03                 */ IL_000a: ldarg.1
		/* 0x000030D3 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000030D8 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x000030DD 0C                 */ IL_0015: stloc.2
		/* 0x000030DE 02                 */ IL_0016: ldarg.0
		/* 0x000030DF 7C43000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::PropertyChanged /* 04000043 */
		/* 0x000030E4 08                 */ IL_001c: ldloc.2
		/* 0x000030E5 07                 */ IL_001d: ldloc.1
		/* 0x000030E6 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x000030EB 0A                 */ IL_0023: stloc.0
		/* 0x000030EC 06                 */ IL_0024: ldloc.0
		/* 0x000030ED 07                 */ IL_0025: ldloc.1
		/* 0x000030EE 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000030F0 2A                 */ IL_0028: ret
	} // end of method MarkerPage::add_PropertyChanged

	.method /* 06000098 */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000045 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3100
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00003100 02                 */ IL_0000: ldarg.0
		/* 0x00003101 7B43000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::PropertyChanged /* 04000043 */
		/* 0x00003106 0A                 */ IL_0006: stloc.0
		/* 0x00003107 06                 */ IL_0007: ldloc.0
		/* 0x00003108 0B                 */ IL_0008: stloc.1
		/* 0x00003109 07                 */ IL_0009: ldloc.1
		/* 0x0000310A 03                 */ IL_000a: ldarg.1
		/* 0x0000310B 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x00003110 7418000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000018 */
		/* 0x00003115 0C                 */ IL_0015: stloc.2
		/* 0x00003116 02                 */ IL_0016: ldarg.0
		/* 0x00003117 7C43000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::PropertyChanged /* 04000043 */
		/* 0x0000311C 08                 */ IL_001c: ldloc.2
		/* 0x0000311D 07                 */ IL_001d: ldloc.1
		/* 0x0000311E 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00003123 0A                 */ IL_0023: stloc.0
		/* 0x00003124 06                 */ IL_0024: ldloc.0
		/* 0x00003125 07                 */ IL_0025: ldloc.1
		/* 0x00003126 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00003128 2A                 */ IL_0028: ret
	} // end of method MarkerPage::remove_PropertyChanged

	.method /* 06000099 */ private hidebysig 
		instance void OnPropertyChanged (
			string propName
		) cil managed 
	{
		// Method begins at RVA 0x3135
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x00003135 02                 */ IL_0000: ldarg.0
		/* 0x00003136 7B43000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::PropertyChanged /* 04000043 */
		/* 0x0000313B 2C12               */ IL_0006: brfalse.s IL_001a
		/* 0x0000313D 02                 */ IL_0008: ldarg.0
		/* 0x0000313E 7B43000004         */ IL_0009: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::PropertyChanged /* 04000043 */
		/* 0x00003143 02                 */ IL_000e: ldarg.0
		/* 0x00003144 03                 */ IL_000f: ldarg.1
		/* 0x00003145 732600000A         */ IL_0010: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000026 */
		/* 0x0000314A 6F2700000A         */ IL_0015: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000027 */
		/* 0x0000314F 2A                 */ IL_001a: ret
	} // end of method MarkerPage::OnPropertyChanged

	.method /* 0600009A */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2261
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002261 02                 */ IL_0000: ldarg.0
		/* 0x00002262 282100000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x00002267 2A                 */ IL_0006: ret
	} // end of method MarkerPage::.ctor

	// Events
	.event /* 14000005 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 1700004B */ instance valuetype [PresentationCore]System.Windows.Media.Color MarkerColorValue()
	{
		.get instance valuetype [PresentationCore]System.Windows.Media.Color AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::get_MarkerColorValue()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::set_MarkerColorValue(valuetype [PresentationCore]System.Windows.Media.Color)
	}
	.property /* 1700004C */ instance int64 MarkerColour()
	{
		.get instance int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::get_MarkerColour()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::set_MarkerColour(int64)
	}
	.property /* 1700004D */ instance int32 MarkerStyle()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::get_MarkerStyle()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::set_MarkerStyle(int32)
	}
	.property /* 1700004E */ instance int32 MarkerSize()
	{
		.get instance int32 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::get_MarkerSize()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::set_MarkerSize(int32)
	}
	.property /* 1700004F */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> ItemList()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.ComboItemClass> AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::get_ItemList()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage

.class /* 0200000D */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000044 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage _objAboutProps
	.field /* 04000045 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage _objGeneralProps
	.field /* 04000046 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage _objAzeoProps
	.field /* 04000047 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage _objBoundayProps
	.field /* 04000048 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage _objEnvelopeProps
	.field /* 04000049 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage _objCurveProps
	.field /* 0400004A */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage _objMarkerProps
	.field /* 0400004B */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage _objFreeHandProps
	.field /* 0400004C */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage _objMatBalProps
	.field /* 0400004D */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage _objProductProps
	.field /* 0400004E */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage _objFeedProps
	.field /* 0400004F */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage _objProfilesProps
	.field /* 04000050 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage _objDecanterProps
	.field /* 04000051 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage _objColumnVapourProps

	// Methods
	.method /* 0600009B */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage get_AboutProps () cil managed 
	{
		// Method begins at RVA 0x3151
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003151 02                 */ IL_0000: ldarg.0
		/* 0x00003152 7B44000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objAboutProps /* 04000044 */
		/* 0x00003157 2A                 */ IL_0006: ret
	} // end of method PropPage::get_AboutProps

	.method /* 0600009C */ public hidebysig specialname 
		instance void set_AboutProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3159
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003159 02                 */ IL_0000: ldarg.0
		/* 0x0000315A 03                 */ IL_0001: ldarg.1
		/* 0x0000315B 7D44000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objAboutProps /* 04000044 */
		/* 0x00003160 2A                 */ IL_0007: ret
	} // end of method PropPage::set_AboutProps

	.method /* 0600009D */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage get_GeneralProps () cil managed 
	{
		// Method begins at RVA 0x3162
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003162 02                 */ IL_0000: ldarg.0
		/* 0x00003163 7B45000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objGeneralProps /* 04000045 */
		/* 0x00003168 2A                 */ IL_0006: ret
	} // end of method PropPage::get_GeneralProps

	.method /* 0600009E */ public hidebysig specialname 
		instance void set_GeneralProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x316a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000316A 02                 */ IL_0000: ldarg.0
		/* 0x0000316B 03                 */ IL_0001: ldarg.1
		/* 0x0000316C 7D45000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objGeneralProps /* 04000045 */
		/* 0x00003171 2A                 */ IL_0007: ret
	} // end of method PropPage::set_GeneralProps

	.method /* 0600009F */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage get_AzeoProps () cil managed 
	{
		// Method begins at RVA 0x3173
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003173 02                 */ IL_0000: ldarg.0
		/* 0x00003174 7B46000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objAzeoProps /* 04000046 */
		/* 0x00003179 2A                 */ IL_0006: ret
	} // end of method PropPage::get_AzeoProps

	.method /* 060000A0 */ public hidebysig specialname 
		instance void set_AzeoProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x317b
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000317B 02                 */ IL_0000: ldarg.0
		/* 0x0000317C 03                 */ IL_0001: ldarg.1
		/* 0x0000317D 7D46000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objAzeoProps /* 04000046 */
		/* 0x00003182 2A                 */ IL_0007: ret
	} // end of method PropPage::set_AzeoProps

	.method /* 060000A1 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage get_BoundayProps () cil managed 
	{
		// Method begins at RVA 0x3184
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003184 02                 */ IL_0000: ldarg.0
		/* 0x00003185 7B47000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objBoundayProps /* 04000047 */
		/* 0x0000318A 2A                 */ IL_0006: ret
	} // end of method PropPage::get_BoundayProps

	.method /* 060000A2 */ public hidebysig specialname 
		instance void set_BoundayProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x318c
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000318C 02                 */ IL_0000: ldarg.0
		/* 0x0000318D 03                 */ IL_0001: ldarg.1
		/* 0x0000318E 7D47000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objBoundayProps /* 04000047 */
		/* 0x00003193 2A                 */ IL_0007: ret
	} // end of method PropPage::set_BoundayProps

	.method /* 060000A3 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage get_EnvelopeProps () cil managed 
	{
		// Method begins at RVA 0x3195
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003195 02                 */ IL_0000: ldarg.0
		/* 0x00003196 7B48000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objEnvelopeProps /* 04000048 */
		/* 0x0000319B 2A                 */ IL_0006: ret
	} // end of method PropPage::get_EnvelopeProps

	.method /* 060000A4 */ public hidebysig specialname 
		instance void set_EnvelopeProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x319d
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000319D 02                 */ IL_0000: ldarg.0
		/* 0x0000319E 03                 */ IL_0001: ldarg.1
		/* 0x0000319F 7D48000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objEnvelopeProps /* 04000048 */
		/* 0x000031A4 2A                 */ IL_0007: ret
	} // end of method PropPage::set_EnvelopeProps

	.method /* 060000A5 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage get_CurveProps () cil managed 
	{
		// Method begins at RVA 0x31a6
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000031A6 02                 */ IL_0000: ldarg.0
		/* 0x000031A7 7B49000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objCurveProps /* 04000049 */
		/* 0x000031AC 2A                 */ IL_0006: ret
	} // end of method PropPage::get_CurveProps

	.method /* 060000A6 */ public hidebysig specialname 
		instance void set_CurveProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x31ae
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000031AE 02                 */ IL_0000: ldarg.0
		/* 0x000031AF 03                 */ IL_0001: ldarg.1
		/* 0x000031B0 7D49000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objCurveProps /* 04000049 */
		/* 0x000031B5 2A                 */ IL_0007: ret
	} // end of method PropPage::set_CurveProps

	.method /* 060000A7 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage get_MarkerProps () cil managed 
	{
		// Method begins at RVA 0x31b7
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000031B7 02                 */ IL_0000: ldarg.0
		/* 0x000031B8 7B4A000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objMarkerProps /* 0400004A */
		/* 0x000031BD 2A                 */ IL_0006: ret
	} // end of method PropPage::get_MarkerProps

	.method /* 060000A8 */ public hidebysig specialname 
		instance void set_MarkerProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x31bf
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000031BF 02                 */ IL_0000: ldarg.0
		/* 0x000031C0 03                 */ IL_0001: ldarg.1
		/* 0x000031C1 7D4A000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objMarkerProps /* 0400004A */
		/* 0x000031C6 2A                 */ IL_0007: ret
	} // end of method PropPage::set_MarkerProps

	.method /* 060000A9 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage get_FreeHandProps () cil managed 
	{
		// Method begins at RVA 0x31c8
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000031C8 02                 */ IL_0000: ldarg.0
		/* 0x000031C9 7B4B000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objFreeHandProps /* 0400004B */
		/* 0x000031CE 2A                 */ IL_0006: ret
	} // end of method PropPage::get_FreeHandProps

	.method /* 060000AA */ public hidebysig specialname 
		instance void set_FreeHandProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x31d0
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000031D0 02                 */ IL_0000: ldarg.0
		/* 0x000031D1 03                 */ IL_0001: ldarg.1
		/* 0x000031D2 7D4B000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objFreeHandProps /* 0400004B */
		/* 0x000031D7 2A                 */ IL_0007: ret
	} // end of method PropPage::set_FreeHandProps

	.method /* 060000AB */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage get_MatBalProps () cil managed 
	{
		// Method begins at RVA 0x31d9
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000031D9 02                 */ IL_0000: ldarg.0
		/* 0x000031DA 7B4C000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objMatBalProps /* 0400004C */
		/* 0x000031DF 2A                 */ IL_0006: ret
	} // end of method PropPage::get_MatBalProps

	.method /* 060000AC */ public hidebysig specialname 
		instance void set_MatBalProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x31e1
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000031E1 02                 */ IL_0000: ldarg.0
		/* 0x000031E2 03                 */ IL_0001: ldarg.1
		/* 0x000031E3 7D4C000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objMatBalProps /* 0400004C */
		/* 0x000031E8 2A                 */ IL_0007: ret
	} // end of method PropPage::set_MatBalProps

	.method /* 060000AD */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage get_ProductProps () cil managed 
	{
		// Method begins at RVA 0x31ea
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000031EA 02                 */ IL_0000: ldarg.0
		/* 0x000031EB 7B4D000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objProductProps /* 0400004D */
		/* 0x000031F0 2A                 */ IL_0006: ret
	} // end of method PropPage::get_ProductProps

	.method /* 060000AE */ public hidebysig specialname 
		instance void set_ProductProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x31f2
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000031F2 02                 */ IL_0000: ldarg.0
		/* 0x000031F3 03                 */ IL_0001: ldarg.1
		/* 0x000031F4 7D4D000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objProductProps /* 0400004D */
		/* 0x000031F9 2A                 */ IL_0007: ret
	} // end of method PropPage::set_ProductProps

	.method /* 060000AF */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage get_FeedProps () cil managed 
	{
		// Method begins at RVA 0x31fb
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000031FB 02                 */ IL_0000: ldarg.0
		/* 0x000031FC 7B4E000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objFeedProps /* 0400004E */
		/* 0x00003201 2A                 */ IL_0006: ret
	} // end of method PropPage::get_FeedProps

	.method /* 060000B0 */ public hidebysig specialname 
		instance void set_FeedProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3203
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003203 02                 */ IL_0000: ldarg.0
		/* 0x00003204 03                 */ IL_0001: ldarg.1
		/* 0x00003205 7D4E000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objFeedProps /* 0400004E */
		/* 0x0000320A 2A                 */ IL_0007: ret
	} // end of method PropPage::set_FeedProps

	.method /* 060000B1 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage get_ProfilesProps () cil managed 
	{
		// Method begins at RVA 0x320c
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000320C 02                 */ IL_0000: ldarg.0
		/* 0x0000320D 7B4F000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objProfilesProps /* 0400004F */
		/* 0x00003212 2A                 */ IL_0006: ret
	} // end of method PropPage::get_ProfilesProps

	.method /* 060000B2 */ public hidebysig specialname 
		instance void set_ProfilesProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3214
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003214 02                 */ IL_0000: ldarg.0
		/* 0x00003215 03                 */ IL_0001: ldarg.1
		/* 0x00003216 7D4F000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objProfilesProps /* 0400004F */
		/* 0x0000321B 2A                 */ IL_0007: ret
	} // end of method PropPage::set_ProfilesProps

	.method /* 060000B3 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage get_DecanterProps () cil managed 
	{
		// Method begins at RVA 0x321d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000321D 02                 */ IL_0000: ldarg.0
		/* 0x0000321E 7B50000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objDecanterProps /* 04000050 */
		/* 0x00003223 2A                 */ IL_0006: ret
	} // end of method PropPage::get_DecanterProps

	.method /* 060000B4 */ public hidebysig specialname 
		instance void set_DecanterProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3225
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003225 02                 */ IL_0000: ldarg.0
		/* 0x00003226 03                 */ IL_0001: ldarg.1
		/* 0x00003227 7D50000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objDecanterProps /* 04000050 */
		/* 0x0000322C 2A                 */ IL_0007: ret
	} // end of method PropPage::set_DecanterProps

	.method /* 060000B5 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage get_ColumnVapourProps () cil managed 
	{
		// Method begins at RVA 0x322e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000322E 02                 */ IL_0000: ldarg.0
		/* 0x0000322F 7B51000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objColumnVapourProps /* 04000051 */
		/* 0x00003234 2A                 */ IL_0006: ret
	} // end of method PropPage::get_ColumnVapourProps

	.method /* 060000B6 */ public hidebysig specialname 
		instance void set_ColumnVapourProps (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3236
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003236 02                 */ IL_0000: ldarg.0
		/* 0x00003237 03                 */ IL_0001: ldarg.1
		/* 0x00003238 7D51000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objColumnVapourProps /* 04000051 */
		/* 0x0000323D 2A                 */ IL_0007: ret
	} // end of method PropPage::set_ColumnVapourProps

	.method /* 060000B7 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3240
		// Header size: 12
		// Code size: 161 (0xa1)
		.maxstack 2

		/* 0x00003240 02                 */ IL_0000: ldarg.0
		/* 0x00003241 7325000006         */ IL_0001: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::.ctor() /* 06000025 */
		/* 0x00003246 7D44000004         */ IL_0006: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objAboutProps /* 04000044 */
		/* 0x0000324B 02                 */ IL_000b: ldarg.0
		/* 0x0000324C 736E000006         */ IL_000c: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage::.ctor() /* 0600006E */
		/* 0x00003251 7D45000004         */ IL_0011: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objGeneralProps /* 04000045 */
		/* 0x00003256 02                 */ IL_0016: ldarg.0
		/* 0x00003257 739A000006         */ IL_0017: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::.ctor() /* 0600009A */
		/* 0x0000325C 7D46000004         */ IL_001c: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objAzeoProps /* 04000046 */
		/* 0x00003261 02                 */ IL_0021: ldarg.0
		/* 0x00003262 739A000006         */ IL_0022: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::.ctor() /* 0600009A */
		/* 0x00003267 7D47000004         */ IL_0027: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objBoundayProps /* 04000047 */
		/* 0x0000326C 02                 */ IL_002c: ldarg.0
		/* 0x0000326D 735D000006         */ IL_002d: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage::.ctor() /* 0600005D */
		/* 0x00003272 7D48000004         */ IL_0032: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objEnvelopeProps /* 04000048 */
		/* 0x00003277 02                 */ IL_0037: ldarg.0
		/* 0x00003278 7344000006         */ IL_0038: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::.ctor() /* 06000044 */
		/* 0x0000327D 7D49000004         */ IL_003d: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objCurveProps /* 04000049 */
		/* 0x00003282 02                 */ IL_0042: ldarg.0
		/* 0x00003283 739A000006         */ IL_0043: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::.ctor() /* 0600009A */
		/* 0x00003288 7D4A000004         */ IL_0048: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objMarkerProps /* 0400004A */
		/* 0x0000328D 02                 */ IL_004d: ldarg.0
		/* 0x0000328E 738D000006         */ IL_004e: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::.ctor() /* 0600008D */
		/* 0x00003293 7D4B000004         */ IL_0053: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objFreeHandProps /* 0400004B */
		/* 0x00003298 02                 */ IL_0058: ldarg.0
		/* 0x00003299 738D000006         */ IL_0059: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::.ctor() /* 0600008D */
		/* 0x0000329E 7D4C000004         */ IL_005e: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objMatBalProps /* 0400004C */
		/* 0x000032A3 02                 */ IL_0063: ldarg.0
		/* 0x000032A4 739A000006         */ IL_0064: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::.ctor() /* 0600009A */
		/* 0x000032A9 7D4D000004         */ IL_0069: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objProductProps /* 0400004D */
		/* 0x000032AE 02                 */ IL_006e: ldarg.0
		/* 0x000032AF 739A000006         */ IL_006f: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::.ctor() /* 0600009A */
		/* 0x000032B4 7D4E000004         */ IL_0074: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objFeedProps /* 0400004E */
		/* 0x000032B9 02                 */ IL_0079: ldarg.0
		/* 0x000032BA 7344000006         */ IL_007a: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage::.ctor() /* 06000044 */
		/* 0x000032BF 7D4F000004         */ IL_007f: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objProfilesProps /* 0400004F */
		/* 0x000032C4 02                 */ IL_0084: ldarg.0
		/* 0x000032C5 738D000006         */ IL_0085: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage::.ctor() /* 0600008D */
		/* 0x000032CA 7D50000004         */ IL_008a: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objDecanterProps /* 04000050 */
		/* 0x000032CF 02                 */ IL_008f: ldarg.0
		/* 0x000032D0 739A000006         */ IL_0090: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage::.ctor() /* 0600009A */
		/* 0x000032D5 7D51000004         */ IL_0095: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::_objColumnVapourProps /* 04000051 */
		/* 0x000032DA 02                 */ IL_009a: ldarg.0
		/* 0x000032DB 282100000A         */ IL_009b: call instance void [mscorlib]System.Object::.ctor() /* 0A000021 */
		/* 0x000032E0 2A                 */ IL_00a0: ret
	} // end of method PropPage::.ctor

	// Properties
	.property /* 17000050 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AboutProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_AboutProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_AboutProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage)
	}
	.property /* 17000051 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage GeneralProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_GeneralProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_GeneralProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage)
	}
	.property /* 17000052 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AzeoProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_AzeoProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_AzeoProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage)
	}
	.property /* 17000053 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage BoundayProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_BoundayProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_BoundayProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage)
	}
	.property /* 17000054 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage EnvelopeProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_EnvelopeProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_EnvelopeProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage)
	}
	.property /* 17000055 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage CurveProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_CurveProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_CurveProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage)
	}
	.property /* 17000056 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage MarkerProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_MarkerProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_MarkerProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage)
	}
	.property /* 17000057 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage FreeHandProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_FreeHandProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_FreeHandProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage)
	}
	.property /* 17000058 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage MatBalProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_MatBalProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_MatBalProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage)
	}
	.property /* 17000059 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage ProductProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_ProductProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_ProductProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage)
	}
	.property /* 1700005A */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage FeedProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_FeedProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_FeedProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage)
	}
	.property /* 1700005B */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage ProfilesProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_ProfilesProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_ProfilesProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage)
	}
	.property /* 1700005C */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage DecanterProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_DecanterProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_DecanterProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage)
	}
	.property /* 1700005D */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage ColumnVapourProps()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_ColumnVapourProps()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::set_ColumnVapourProps(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage)
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage

.class /* 0200000E */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 04000052 */ private valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum m_PageType
	.field /* 04000053 */ assembly class [PresentationFramework]System.Windows.Controls.GroupBox fraCurve
	.field /* 04000054 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblCurve1
	.field /* 04000055 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblCurve2
	.field /* 04000056 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblCurveColour
	.field /* 04000057 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblCurveStyle
	.field /* 04000058 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblCurveMarkerStyle
	.field /* 04000059 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblCurveMarkerSize
	.field /* 0400005A */ assembly class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker cboCurve1Colour
	.field /* 0400005B */ assembly class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker cboCurve2Colour
	.field /* 0400005C */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox cboCurve1Style
	.field /* 0400005D */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox cboCurve2Style
	.field /* 0400005E */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox cboCurve1MarkerStyle
	.field /* 0400005F */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox cboCurve2MarkerStyle
	.field /* 04000060 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesSpinBox txtCurve1MarkerSize
	.field /* 04000061 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesSpinBox txtCurve2MarkerSize
	.field /* 04000062 */ private bool _contentLoaded

	// Methods
	.method /* 060000B8 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage pageObject
		) cil managed 
	{
		// Method begins at RVA 0x32ed
		// Header size: 1
		// Code size: 60 (0x3c)
		.maxstack 8

		/* 0x000032ED 02                 */ IL_0000: ldarg.0
		/* 0x000032EE 284500000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x000032F3 02                 */ IL_0006: ldarg.0
		/* 0x000032F4 28BC000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::InitializeComponent() /* 060000BC */
		/* 0x000032F9 02                 */ IL_000c: ldarg.0
		/* 0x000032FA 02                 */ IL_000d: ldarg.0
		/* 0x000032FB FE06B9000006       */ IL_000e: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::UsrCurvesPage_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000B9 */
		/* 0x00003301 734600000A         */ IL_0014: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x00003306 284700000A         */ IL_0019: call instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000047 */
		/* 0x0000330B 02                 */ IL_001e: ldarg.0
		/* 0x0000330C 03                 */ IL_001f: ldarg.1
		/* 0x0000330D 284800000A         */ IL_0020: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x00003312 02                 */ IL_0025: ldarg.0
		/* 0x00003313 7B5A000004         */ IL_0026: ldfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve1Colour /* 0400005A */
		/* 0x00003318 2875000006         */ IL_002b: call void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::FillColour(class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker) /* 06000075 */
		/* 0x0000331D 02                 */ IL_0030: ldarg.0
		/* 0x0000331E 7B5B000004         */ IL_0031: ldfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve2Colour /* 0400005B */
		/* 0x00003323 2875000006         */ IL_0036: call void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::FillColour(class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker) /* 06000075 */
		/* 0x00003328 2A                 */ IL_003b: ret
	} // end of method UsrCurvesPage::.ctor

	.method /* 060000B9 */ private hidebysig 
		instance void UsrCurvesPage_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x332a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000332A 02                 */ IL_0000: ldarg.0
		/* 0x0000332B 28BB000006         */ IL_0001: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::LoadCaptions() /* 060000BB */
		/* 0x00003330 2A                 */ IL_0006: ret
	} // end of method UsrCurvesPage::UsrCurvesPage_Loaded

	.method /* 060000BA */ public hidebysig 
		instance void SetPageType (
			valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum 'type'
		) cil managed 
	{
		// Method begins at RVA 0x3332
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003332 02                 */ IL_0000: ldarg.0
		/* 0x00003333 03                 */ IL_0001: ldarg.1
		/* 0x00003334 7D52000004         */ IL_0002: stfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::m_PageType /* 04000052 */
		/* 0x00003339 2A                 */ IL_0007: ret
	} // end of method UsrCurvesPage::SetPageType

	.method /* 060000BB */ private hidebysig 
		instance void LoadCaptions () cil managed 
	{
		// Method begins at RVA 0x333c
		// Header size: 12
		// Code size: 243 (0xf3)
		.maxstack 2
		.locals /* 11000006 */ init (
			[0] valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum
		)

		/* 0x0000333C 02                 */ IL_0000: ldarg.0
		/* 0x0000333D 7B52000004         */ IL_0001: ldfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::m_PageType /* 04000052 */
		/* 0x00003342 0A                 */ IL_0006: stloc.0
		/* 0x00003343 06                 */ IL_0007: ldloc.0
		/* 0x00003344 1A                 */ IL_0008: ldc.i4.4
		/* 0x00003345 2E06               */ IL_0009: beq.s IL_0011
		/* 0x00003347 06                 */ IL_000b: ldloc.0
		/* 0x00003348 1F0A               */ IL_000c: ldc.i4.s 10
		/* 0x0000334A 2E72               */ IL_000e: beq.s IL_0082
		/* 0x0000334C 2A                 */ IL_0010: ret
		/* 0x0000334D 02                 */ IL_0011: ldarg.0
		/* 0x0000334E 7B53000004         */ IL_0012: ldfld class [PresentationFramework]System.Windows.Controls.GroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::fraCurve /* 04000053 */
		/* 0x00003353 284900000A         */ IL_0017: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R701_RDCString() /* 0A000049 */
		/* 0x00003358 6F4A00000A         */ IL_001c: callvirt instance void [PresentationFramework]System.Windows.Controls.HeaderedContentControl::set_Header(object) /* 0A00004A */
		/* 0x0000335D 02                 */ IL_0021: ldarg.0
		/* 0x0000335E 7B54000004         */ IL_0022: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurve1 /* 04000054 */
		/* 0x00003363 284B00000A         */ IL_0027: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R702_ResidueString() /* 0A00004B */
		/* 0x00003368 6F4C00000A         */ IL_002c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000336D 02                 */ IL_0031: ldarg.0
		/* 0x0000336E 7B55000004         */ IL_0032: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurve2 /* 04000055 */
		/* 0x00003373 284D00000A         */ IL_0037: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R703_DistiString() /* 0A00004D */
		/* 0x00003378 6F4C00000A         */ IL_003c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000337D 02                 */ IL_0041: ldarg.0
		/* 0x0000337E 7B56000004         */ IL_0042: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveColour /* 04000056 */
		/* 0x00003383 284E00000A         */ IL_0047: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R704_CCString() /* 0A00004E */
		/* 0x00003388 6F4C00000A         */ IL_004c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000338D 02                 */ IL_0051: ldarg.0
		/* 0x0000338E 7B57000004         */ IL_0052: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveStyle /* 04000057 */
		/* 0x00003393 284F00000A         */ IL_0057: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R705_CSString() /* 0A00004F */
		/* 0x00003398 6F4C00000A         */ IL_005c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000339D 02                 */ IL_0061: ldarg.0
		/* 0x0000339E 7B58000004         */ IL_0062: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveMarkerStyle /* 04000058 */
		/* 0x000033A3 285000000A         */ IL_0067: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R706_MarkerStyleString() /* 0A000050 */
		/* 0x000033A8 6F4C00000A         */ IL_006c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000033AD 02                 */ IL_0071: ldarg.0
		/* 0x000033AE 7B59000004         */ IL_0072: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveMarkerSize /* 04000059 */
		/* 0x000033B3 285100000A         */ IL_0077: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R707_MarkerSizeString() /* 0A000051 */
		/* 0x000033B8 6F4C00000A         */ IL_007c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000033BD 2A                 */ IL_0081: ret
		/* 0x000033BE 02                 */ IL_0082: ldarg.0
		/* 0x000033BF 7B53000004         */ IL_0083: ldfld class [PresentationFramework]System.Windows.Controls.GroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::fraCurve /* 04000053 */
		/* 0x000033C4 285200000A         */ IL_0088: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1301_SRPString() /* 0A000052 */
		/* 0x000033C9 6F4A00000A         */ IL_008d: callvirt instance void [PresentationFramework]System.Windows.Controls.HeaderedContentControl::set_Header(object) /* 0A00004A */
		/* 0x000033CE 02                 */ IL_0092: ldarg.0
		/* 0x000033CF 7B54000004         */ IL_0093: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurve1 /* 04000054 */
		/* 0x000033D4 285300000A         */ IL_0098: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1302_StrippingString() /* 0A000053 */
		/* 0x000033D9 6F4C00000A         */ IL_009d: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000033DE 02                 */ IL_00a2: ldarg.0
		/* 0x000033DF 7B55000004         */ IL_00a3: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurve2 /* 04000055 */
		/* 0x000033E4 285400000A         */ IL_00a8: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1303_RectifyingString() /* 0A000054 */
		/* 0x000033E9 6F4C00000A         */ IL_00ad: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000033EE 02                 */ IL_00b2: ldarg.0
		/* 0x000033EF 7B56000004         */ IL_00b3: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveColour /* 04000056 */
		/* 0x000033F4 284E00000A         */ IL_00b8: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R704_CCString() /* 0A00004E */
		/* 0x000033F9 6F4C00000A         */ IL_00bd: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000033FE 02                 */ IL_00c2: ldarg.0
		/* 0x000033FF 7B57000004         */ IL_00c3: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveStyle /* 04000057 */
		/* 0x00003404 284F00000A         */ IL_00c8: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R705_CSString() /* 0A00004F */
		/* 0x00003409 6F4C00000A         */ IL_00cd: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000340E 02                 */ IL_00d2: ldarg.0
		/* 0x0000340F 7B58000004         */ IL_00d3: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveMarkerStyle /* 04000058 */
		/* 0x00003414 285000000A         */ IL_00d8: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R706_MarkerStyleString() /* 0A000050 */
		/* 0x00003419 6F4C00000A         */ IL_00dd: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000341E 02                 */ IL_00e2: ldarg.0
		/* 0x0000341F 7B59000004         */ IL_00e3: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveMarkerSize /* 04000059 */
		/* 0x00003424 285100000A         */ IL_00e8: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R707_MarkerSizeString() /* 0A000051 */
		/* 0x00003429 6F4C00000A         */ IL_00ed: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000342E 2A                 */ IL_00f2: ret
	} // end of method UsrCurvesPage::LoadCaptions

	.method /* 060000BC */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00004B */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00004C */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x343c
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x0000343C 02                 */ IL_0000: ldarg.0
		/* 0x0000343D 7B62000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::_contentLoaded /* 04000062 */
		/* 0x00003442 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00003444 2A                 */ IL_0008: ret
		/* 0x00003445 02                 */ IL_0009: ldarg.0
		/* 0x00003446 17                 */ IL_000a: ldc.i4.1
		/* 0x00003447 7D62000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::_contentLoaded /* 04000062 */
		/* 0x0000344C 723B050070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrcurvespage.xaml" /* 7000053B */
		/* 0x00003451 18                 */ IL_0015: ldc.i4.2
		/* 0x00003452 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x00003457 0A                 */ IL_001b: stloc.0
		/* 0x00003458 02                 */ IL_001c: ldarg.0
		/* 0x00003459 06                 */ IL_001d: ldloc.0
		/* 0x0000345A 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x0000345F 2A                 */ IL_0023: ret
	} // end of method UsrCurvesPage::InitializeComponent

	.method /* 060000BD */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C00004D */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00004E */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C00004F */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x346c
		// Header size: 12
		// Code size: 276 (0x114)
		.maxstack 2

		/* 0x0000346C 03                 */ IL_0000: ldarg.1
		/* 0x0000346D 17                 */ IL_0001: ldc.i4.1
		/* 0x0000346E 59                 */ IL_0002: sub
		/* 0x0000346F 450F000000         */ IL_0003: switch (
		/*              05000000         */                  IL_0049,
		/*              12000000         */                  IL_0056,
		/*              1F000000         */                  IL_0063,
		/*              2C000000         */                  IL_0070,
		/*              39000000         */                  IL_007d,
		/*              46000000         */                  IL_008a,
		/*              53000000         */                  IL_0097,
		/*              60000000         */                  IL_00a4,
		/*              6D000000         */                  IL_00b1,
		/*              7A000000         */                  IL_00be,
		/*              87000000         */                  IL_00cb,
		/*              94000000         */                  IL_00d8,
		/*              A1000000         */                  IL_00e5,
		/*              AE000000         */                  IL_00f2,
		/*              BB000000         */                  IL_00ff)
		/* 0x000034B0 38C3000000         */ IL_0044: br IL_010c
		/* 0x000034B5 02                 */ IL_0049: ldarg.0
		/* 0x000034B6 04                 */ IL_004a: ldarg.2
		/* 0x000034B7 7422000001         */ IL_004b: castclass [PresentationFramework]System.Windows.Controls.GroupBox /* 01000022 */
		/* 0x000034BC 7D53000004         */ IL_0050: stfld class [PresentationFramework]System.Windows.Controls.GroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::fraCurve /* 04000053 */
		/* 0x000034C1 2A                 */ IL_0055: ret
		/* 0x000034C2 02                 */ IL_0056: ldarg.0
		/* 0x000034C3 04                 */ IL_0057: ldarg.2
		/* 0x000034C4 7423000001         */ IL_0058: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000034C9 7D54000004         */ IL_005d: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurve1 /* 04000054 */
		/* 0x000034CE 2A                 */ IL_0062: ret
		/* 0x000034CF 02                 */ IL_0063: ldarg.0
		/* 0x000034D0 04                 */ IL_0064: ldarg.2
		/* 0x000034D1 7423000001         */ IL_0065: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000034D6 7D55000004         */ IL_006a: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurve2 /* 04000055 */
		/* 0x000034DB 2A                 */ IL_006f: ret
		/* 0x000034DC 02                 */ IL_0070: ldarg.0
		/* 0x000034DD 04                 */ IL_0071: ldarg.2
		/* 0x000034DE 7423000001         */ IL_0072: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000034E3 7D56000004         */ IL_0077: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveColour /* 04000056 */
		/* 0x000034E8 2A                 */ IL_007c: ret
		/* 0x000034E9 02                 */ IL_007d: ldarg.0
		/* 0x000034EA 04                 */ IL_007e: ldarg.2
		/* 0x000034EB 7423000001         */ IL_007f: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000034F0 7D57000004         */ IL_0084: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveStyle /* 04000057 */
		/* 0x000034F5 2A                 */ IL_0089: ret
		/* 0x000034F6 02                 */ IL_008a: ldarg.0
		/* 0x000034F7 04                 */ IL_008b: ldarg.2
		/* 0x000034F8 7423000001         */ IL_008c: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000034FD 7D58000004         */ IL_0091: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveMarkerStyle /* 04000058 */
		/* 0x00003502 2A                 */ IL_0096: ret
		/* 0x00003503 02                 */ IL_0097: ldarg.0
		/* 0x00003504 04                 */ IL_0098: ldarg.2
		/* 0x00003505 7423000001         */ IL_0099: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x0000350A 7D59000004         */ IL_009e: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::lblCurveMarkerSize /* 04000059 */
		/* 0x0000350F 2A                 */ IL_00a3: ret
		/* 0x00003510 02                 */ IL_00a4: ldarg.0
		/* 0x00003511 04                 */ IL_00a5: ldarg.2
		/* 0x00003512 741D000001         */ IL_00a6: castclass [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker /* 0100001D */
		/* 0x00003517 7D5A000004         */ IL_00ab: stfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve1Colour /* 0400005A */
		/* 0x0000351C 2A                 */ IL_00b0: ret
		/* 0x0000351D 02                 */ IL_00b1: ldarg.0
		/* 0x0000351E 04                 */ IL_00b2: ldarg.2
		/* 0x0000351F 741D000001         */ IL_00b3: castclass [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker /* 0100001D */
		/* 0x00003524 7D5B000004         */ IL_00b8: stfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve2Colour /* 0400005B */
		/* 0x00003529 2A                 */ IL_00bd: ret
		/* 0x0000352A 02                 */ IL_00be: ldarg.0
		/* 0x0000352B 04                 */ IL_00bf: ldarg.2
		/* 0x0000352C 7424000001         */ IL_00c0: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00003531 7D5C000004         */ IL_00c5: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve1Style /* 0400005C */
		/* 0x00003536 2A                 */ IL_00ca: ret
		/* 0x00003537 02                 */ IL_00cb: ldarg.0
		/* 0x00003538 04                 */ IL_00cc: ldarg.2
		/* 0x00003539 7424000001         */ IL_00cd: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x0000353E 7D5D000004         */ IL_00d2: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve2Style /* 0400005D */
		/* 0x00003543 2A                 */ IL_00d7: ret
		/* 0x00003544 02                 */ IL_00d8: ldarg.0
		/* 0x00003545 04                 */ IL_00d9: ldarg.2
		/* 0x00003546 7424000001         */ IL_00da: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x0000354B 7D5E000004         */ IL_00df: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve1MarkerStyle /* 0400005E */
		/* 0x00003550 2A                 */ IL_00e4: ret
		/* 0x00003551 02                 */ IL_00e5: ldarg.0
		/* 0x00003552 04                 */ IL_00e6: ldarg.2
		/* 0x00003553 7424000001         */ IL_00e7: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00003558 7D5F000004         */ IL_00ec: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::cboCurve2MarkerStyle /* 0400005F */
		/* 0x0000355D 2A                 */ IL_00f1: ret
		/* 0x0000355E 02                 */ IL_00f2: ldarg.0
		/* 0x0000355F 04                 */ IL_00f3: ldarg.2
		/* 0x00003560 7425000001         */ IL_00f4: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesSpinBox /* 01000025 */
		/* 0x00003565 7D60000004         */ IL_00f9: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesSpinBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::txtCurve1MarkerSize /* 04000060 */
		/* 0x0000356A 2A                 */ IL_00fe: ret
		/* 0x0000356B 02                 */ IL_00ff: ldarg.0
		/* 0x0000356C 04                 */ IL_0100: ldarg.2
		/* 0x0000356D 7425000001         */ IL_0101: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesSpinBox /* 01000025 */
		/* 0x00003572 7D61000004         */ IL_0106: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesSpinBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::txtCurve2MarkerSize /* 04000061 */
		/* 0x00003577 2A                 */ IL_010b: ret
		/* 0x00003578 02                 */ IL_010c: ldarg.0
		/* 0x00003579 17                 */ IL_010d: ldc.i4.1
		/* 0x0000357A 7D62000004         */ IL_010e: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::_contentLoaded /* 04000062 */
		/* 0x0000357F 2A                 */ IL_0113: ret
	} // end of method UsrCurvesPage::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage

.class /* 0200000F */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 04000063 */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage _AboutPage
	.field /* 04000064 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox fraAbout
	.field /* 04000065 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel lblGUIName
	.field /* 04000066 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel lblProductName
	.field /* 04000067 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel lblRelease
	.field /* 04000068 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel lblVersion
	.field /* 04000069 */ assembly class [PresentationFramework]System.Windows.Controls.Button cmdWebLink
	.field /* 0400006A */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel lblCompany
	.field /* 0400006B */ private bool _contentLoaded

	// Methods
	.method /* 060000BE */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x358c
		// Header size: 12
		// Code size: 98 (0x62)
		.maxstack 3

		/* 0x0000358C 02                 */ IL_0000: ldarg.0
		/* 0x0000358D 7325000006         */ IL_0001: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::.ctor() /* 06000025 */
		/* 0x00003592 7D63000004         */ IL_0006: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x00003597 02                 */ IL_000b: ldarg.0
		/* 0x00003598 284500000A         */ IL_000c: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x0000359D 02                 */ IL_0011: ldarg.0
		/* 0x0000359E 28C3000006         */ IL_0012: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::InitializeComponent() /* 060000C3 */
		/* 0x000035A3 02                 */ IL_0017: ldarg.0
		/* 0x000035A4 7B64000004         */ IL_0018: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::fraAbout /* 04000064 */
		/* 0x000035A9 285600000A         */ IL_001d: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R201_AboutString() /* 0A000056 */
		/* 0x000035AE 6F5700000A         */ IL_0022: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x000035B3 02                 */ IL_0027: ldarg.0
		/* 0x000035B4 7B65000004         */ IL_0028: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblGUIName /* 04000065 */
		/* 0x000035B9 285800000A         */ IL_002d: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R202_TitleString() /* 0A000058 */
		/* 0x000035BE 6F5900000A         */ IL_0032: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel::set_Content(object) /* 0A000059 */
		/* 0x000035C3 02                 */ IL_0037: ldarg.0
		/* 0x000035C4 7B6A000004         */ IL_0038: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblCompany /* 0400006A */
		/* 0x000035C9 285A00000A         */ IL_003d: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R205_CopyRightString() /* 0A00005A */
		/* 0x000035CE 285B00000A         */ IL_0042: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R206_ATCompamyString() /* 0A00005B */
		/* 0x000035D3 285C00000A         */ IL_0047: call string [mscorlib]System.String::Concat(string, string) /* 0A00005C */
		/* 0x000035D8 6F5900000A         */ IL_004c: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel::set_Content(object) /* 0A000059 */
		/* 0x000035DD 02                 */ IL_0051: ldarg.0
		/* 0x000035DE 7B69000004         */ IL_0052: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::cmdWebLink /* 04000069 */
		/* 0x000035E3 285D00000A         */ IL_0057: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R207_ATWebLinkString() /* 0A00005D */
		/* 0x000035E8 6F4C00000A         */ IL_005c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000035ED 2A                 */ IL_0061: ret
	} // end of method UsrAboutPage::.ctor

	.method /* 060000BF */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage get_AboutPage () cil managed 
	{
		// Method begins at RVA 0x35fa
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000035FA 02                 */ IL_0000: ldarg.0
		/* 0x000035FB 7B63000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x00003600 2A                 */ IL_0006: ret
	} // end of method UsrAboutPage::get_AboutPage

	.method /* 060000C0 */ public hidebysig specialname 
		instance void set_AboutPage (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3602
		// Header size: 1
		// Code size: 25 (0x19)
		.maxstack 8

		/* 0x00003602 03                 */ IL_0000: ldarg.1
		/* 0x00003603 2C0E               */ IL_0001: brfalse.s IL_0011
		/* 0x00003605 02                 */ IL_0003: ldarg.0
		/* 0x00003606 03                 */ IL_0004: ldarg.1
		/* 0x00003607 7D63000004         */ IL_0005: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x0000360C 02                 */ IL_000a: ldarg.0
		/* 0x0000360D 28C2000006         */ IL_000b: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::SetData() /* 060000C2 */
		/* 0x00003612 2A                 */ IL_0010: ret
		/* 0x00003613 02                 */ IL_0011: ldarg.0
		/* 0x00003614 14                 */ IL_0012: ldnull
		/* 0x00003615 7D63000004         */ IL_0013: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x0000361A 2A                 */ IL_0018: ret
	} // end of method UsrAboutPage::set_AboutPage

	.method /* 060000C1 */ private hidebysig 
		instance void cmdWebLink_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x361c
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x0000361C 285D00000A         */ IL_0000: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R207_ATWebLinkString() /* 0A00005D */
		/* 0x00003621 2878000006         */ IL_0005: call int64 AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::StartURL(string) /* 06000078 */
		/* 0x00003626 26                 */ IL_000a: pop
		/* 0x00003627 2A                 */ IL_000b: ret
	} // end of method UsrAboutPage::cmdWebLink_Click

	.method /* 060000C2 */ private hidebysig 
		instance void SetData () cil managed 
	{
		// Method begins at RVA 0x362c
		// Header size: 12
		// Code size: 87 (0x57)
		.maxstack 3

		/* 0x0000362C 02                 */ IL_0000: ldarg.0
		/* 0x0000362D 7B66000004         */ IL_0001: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblProductName /* 04000066 */
		/* 0x00003632 02                 */ IL_0006: ldarg.0
		/* 0x00003633 7B63000004         */ IL_0007: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x00003638 6F1F000006         */ IL_000c: callvirt instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::get_ProductName() /* 0600001F */
		/* 0x0000363D 6F5900000A         */ IL_0011: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel::set_Content(object) /* 0A000059 */
		/* 0x00003642 02                 */ IL_0016: ldarg.0
		/* 0x00003643 7B67000004         */ IL_0017: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblRelease /* 04000067 */
		/* 0x00003648 285E00000A         */ IL_001c: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R203_ReleaseString() /* 0A00005E */
		/* 0x0000364D 02                 */ IL_0021: ldarg.0
		/* 0x0000364E 7B63000004         */ IL_0022: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x00003653 6F23000006         */ IL_0027: callvirt instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::get_Release() /* 06000023 */
		/* 0x00003658 285C00000A         */ IL_002c: call string [mscorlib]System.String::Concat(string, string) /* 0A00005C */
		/* 0x0000365D 6F5900000A         */ IL_0031: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel::set_Content(object) /* 0A000059 */
		/* 0x00003662 02                 */ IL_0036: ldarg.0
		/* 0x00003663 7B68000004         */ IL_0037: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblVersion /* 04000068 */
		/* 0x00003668 285F00000A         */ IL_003c: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R204_VersionString() /* 0A00005F */
		/* 0x0000366D 02                 */ IL_0041: ldarg.0
		/* 0x0000366E 7B63000004         */ IL_0042: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_AboutPage /* 04000063 */
		/* 0x00003673 6F21000006         */ IL_0047: callvirt instance string AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage::get_Version() /* 06000021 */
		/* 0x00003678 285C00000A         */ IL_004c: call string [mscorlib]System.String::Concat(string, string) /* 0A00005C */
		/* 0x0000367D 6F5900000A         */ IL_0051: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel::set_Content(object) /* 0A000059 */
		/* 0x00003682 2A                 */ IL_0056: ret
	} // end of method UsrAboutPage::SetData

	.method /* 060000C3 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000050 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000051 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x3690
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00003690 02                 */ IL_0000: ldarg.0
		/* 0x00003691 7B6B000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_contentLoaded /* 0400006B */
		/* 0x00003696 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00003698 2A                 */ IL_0008: ret
		/* 0x00003699 02                 */ IL_0009: ldarg.0
		/* 0x0000369A 17                 */ IL_000a: ldc.i4.1
		/* 0x0000369B 7D6B000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_contentLoaded /* 0400006B */
		/* 0x000036A0 72D8050070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usraboutpage.xaml" /* 700005D8 */
		/* 0x000036A5 18                 */ IL_0015: ldc.i4.2
		/* 0x000036A6 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x000036AB 0A                 */ IL_001b: stloc.0
		/* 0x000036AC 02                 */ IL_001c: ldarg.0
		/* 0x000036AD 06                 */ IL_001d: ldloc.0
		/* 0x000036AE 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x000036B3 2A                 */ IL_0023: ret
	} // end of method UsrAboutPage::InitializeComponent

	.method /* 060000C4 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000052 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000053 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000054 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x36c0
		// Header size: 12
		// Code size: 160 (0xa0)
		.maxstack 3

		/* 0x000036C0 03                 */ IL_0000: ldarg.1
		/* 0x000036C1 17                 */ IL_0001: ldc.i4.1
		/* 0x000036C2 59                 */ IL_0002: sub
		/* 0x000036C3 4507000000         */ IL_0003: switch (
		/*              02000000         */                  IL_0026,
		/*              0F000000         */                  IL_0033,
		/*              1C000000         */                  IL_0040,
		/*              29000000         */                  IL_004d,
		/*              36000000         */                  IL_005a,
		/*              43000000         */                  IL_0067,
		/*              67000000         */                  IL_008b)
		/* 0x000036E4 2B72               */ IL_0024: br.s IL_0098
		/* 0x000036E6 02                 */ IL_0026: ldarg.0
		/* 0x000036E7 04                 */ IL_0027: ldarg.2
		/* 0x000036E8 742C000001         */ IL_0028: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox /* 0100002C */
		/* 0x000036ED 7D64000004         */ IL_002d: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::fraAbout /* 04000064 */
		/* 0x000036F2 2A                 */ IL_0032: ret
		/* 0x000036F3 02                 */ IL_0033: ldarg.0
		/* 0x000036F4 04                 */ IL_0034: ldarg.2
		/* 0x000036F5 742D000001         */ IL_0035: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel /* 0100002D */
		/* 0x000036FA 7D65000004         */ IL_003a: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblGUIName /* 04000065 */
		/* 0x000036FF 2A                 */ IL_003f: ret
		/* 0x00003700 02                 */ IL_0040: ldarg.0
		/* 0x00003701 04                 */ IL_0041: ldarg.2
		/* 0x00003702 742D000001         */ IL_0042: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel /* 0100002D */
		/* 0x00003707 7D66000004         */ IL_0047: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblProductName /* 04000066 */
		/* 0x0000370C 2A                 */ IL_004c: ret
		/* 0x0000370D 02                 */ IL_004d: ldarg.0
		/* 0x0000370E 04                 */ IL_004e: ldarg.2
		/* 0x0000370F 742D000001         */ IL_004f: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel /* 0100002D */
		/* 0x00003714 7D67000004         */ IL_0054: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblRelease /* 04000067 */
		/* 0x00003719 2A                 */ IL_0059: ret
		/* 0x0000371A 02                 */ IL_005a: ldarg.0
		/* 0x0000371B 04                 */ IL_005b: ldarg.2
		/* 0x0000371C 742D000001         */ IL_005c: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel /* 0100002D */
		/* 0x00003721 7D68000004         */ IL_0061: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblVersion /* 04000068 */
		/* 0x00003726 2A                 */ IL_0066: ret
		/* 0x00003727 02                 */ IL_0067: ldarg.0
		/* 0x00003728 04                 */ IL_0068: ldarg.2
		/* 0x00003729 742E000001         */ IL_0069: castclass [PresentationFramework]System.Windows.Controls.Button /* 0100002E */
		/* 0x0000372E 7D69000004         */ IL_006e: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::cmdWebLink /* 04000069 */
		/* 0x00003733 02                 */ IL_0073: ldarg.0
		/* 0x00003734 7B69000004         */ IL_0074: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::cmdWebLink /* 04000069 */
		/* 0x00003739 02                 */ IL_0079: ldarg.0
		/* 0x0000373A FE06C1000006       */ IL_007a: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::cmdWebLink_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000C1 */
		/* 0x00003740 734600000A         */ IL_0080: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x00003745 6F6000000A         */ IL_0085: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000060 */
		/* 0x0000374A 2A                 */ IL_008a: ret
		/* 0x0000374B 02                 */ IL_008b: ldarg.0
		/* 0x0000374C 04                 */ IL_008c: ldarg.2
		/* 0x0000374D 742D000001         */ IL_008d: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel /* 0100002D */
		/* 0x00003752 7D6A000004         */ IL_0092: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesLabel AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::lblCompany /* 0400006A */
		/* 0x00003757 2A                 */ IL_0097: ret
		/* 0x00003758 02                 */ IL_0098: ldarg.0
		/* 0x00003759 17                 */ IL_0099: ldc.i4.1
		/* 0x0000375A 7D6B000004         */ IL_009a: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::_contentLoaded /* 0400006B */
		/* 0x0000375F 2A                 */ IL_009f: ret
	} // end of method UsrAboutPage::System.Windows.Markup.IComponentConnector.Connect

	// Properties
	.property /* 1700005E */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AboutPage()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::get_AboutPage()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage::set_AboutPage(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.AboutPage)
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrAboutPage

.class /* 02000010 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 0400006C */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox fraEnvelope
	.field /* 0400006D */ assembly class [PresentationFramework]System.Windows.Controls.Label lblEnvColour
	.field /* 0400006E */ assembly class [PresentationFramework]System.Windows.Controls.Label lblEnvPattern
	.field /* 0400006F */ assembly class [PresentationFramework]System.Windows.Controls.Label lblLineColour
	.field /* 04000070 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblLineStyle
	.field /* 04000071 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblLineMarkerStyle
	.field /* 04000072 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblVapMarkerStyle
	.field /* 04000073 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblVapMarkerSize
	.field /* 04000074 */ assembly class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker EnvColorPicker
	.field /* 04000075 */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox EnvPatternStyleEditor
	.field /* 04000076 */ assembly class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker LineColorPicker
	.field /* 04000077 */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox LineStyleEditor
	.field /* 04000078 */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox LineMarkerEditor
	.field /* 04000079 */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox VapMarkerStyleEditor
	.field /* 0400007A */ private bool _contentLoaded

	// Methods
	.method /* 060000C5 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage pageObject
		) cil managed 
	{
		// Method begins at RVA 0x376c
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x0000376C 02                 */ IL_0000: ldarg.0
		/* 0x0000376D 284500000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x00003772 02                 */ IL_0006: ldarg.0
		/* 0x00003773 28C9000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::InitializeComponent() /* 060000C9 */
		/* 0x00003778 02                 */ IL_000c: ldarg.0
		/* 0x00003779 03                 */ IL_000d: ldarg.1
		/* 0x0000377A 284800000A         */ IL_000e: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x0000377F 2A                 */ IL_0013: ret
	} // end of method UsrEnvelopePage::.ctor

	.method /* 060000C6 */ private hidebysig 
		instance void UserControl_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3781
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003781 02                 */ IL_0000: ldarg.0
		/* 0x00003782 28C7000006         */ IL_0001: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::LoadCaptions() /* 060000C7 */
		/* 0x00003787 02                 */ IL_0006: ldarg.0
		/* 0x00003788 28C8000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::LoadColors() /* 060000C8 */
		/* 0x0000378D 2A                 */ IL_000c: ret
	} // end of method UsrEnvelopePage::UserControl_Loaded

	.method /* 060000C7 */ private hidebysig 
		instance void LoadCaptions () cil managed 
	{
		// Method begins at RVA 0x3790
		// Header size: 12
		// Code size: 129 (0x81)
		.maxstack 2

		/* 0x00003790 02                 */ IL_0000: ldarg.0
		/* 0x00003791 7B6C000004         */ IL_0001: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::fraEnvelope /* 0400006C */
		/* 0x00003796 286100000A         */ IL_0006: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R601_EATString() /* 0A000061 */
		/* 0x0000379B 6F5700000A         */ IL_000b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x000037A0 02                 */ IL_0010: ldarg.0
		/* 0x000037A1 7B6D000004         */ IL_0011: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblEnvColour /* 0400006D */
		/* 0x000037A6 286200000A         */ IL_0016: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R602_ECString() /* 0A000062 */
		/* 0x000037AB 6F4C00000A         */ IL_001b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000037B0 02                 */ IL_0020: ldarg.0
		/* 0x000037B1 7B6E000004         */ IL_0021: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblEnvPattern /* 0400006E */
		/* 0x000037B6 286300000A         */ IL_0026: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R603_EFPString() /* 0A000063 */
		/* 0x000037BB 6F4C00000A         */ IL_002b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000037C0 02                 */ IL_0030: ldarg.0
		/* 0x000037C1 7B6F000004         */ IL_0031: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblLineColour /* 0400006F */
		/* 0x000037C6 286400000A         */ IL_0036: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R604_TLCString() /* 0A000064 */
		/* 0x000037CB 6F4C00000A         */ IL_003b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000037D0 02                 */ IL_0040: ldarg.0
		/* 0x000037D1 7B70000004         */ IL_0041: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblLineStyle /* 04000070 */
		/* 0x000037D6 286500000A         */ IL_0046: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R605_TLSString() /* 0A000065 */
		/* 0x000037DB 6F4C00000A         */ IL_004b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000037E0 02                 */ IL_0050: ldarg.0
		/* 0x000037E1 7B71000004         */ IL_0051: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblLineMarkerStyle /* 04000071 */
		/* 0x000037E6 286600000A         */ IL_0056: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R606_TLMSString() /* 0A000066 */
		/* 0x000037EB 6F4C00000A         */ IL_005b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000037F0 02                 */ IL_0060: ldarg.0
		/* 0x000037F1 7B72000004         */ IL_0061: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblVapMarkerStyle /* 04000072 */
		/* 0x000037F6 286700000A         */ IL_0066: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R607_VMSString() /* 0A000067 */
		/* 0x000037FB 6F4C00000A         */ IL_006b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003800 02                 */ IL_0070: ldarg.0
		/* 0x00003801 7B73000004         */ IL_0071: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblVapMarkerSize /* 04000073 */
		/* 0x00003806 286800000A         */ IL_0076: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R608_MarkerSizeString() /* 0A000068 */
		/* 0x0000380B 6F4C00000A         */ IL_007b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003810 2A                 */ IL_0080: ret
	} // end of method UsrEnvelopePage::LoadCaptions

	.method /* 060000C8 */ private hidebysig 
		instance void LoadColors () cil managed 
	{
		// Method begins at RVA 0x381d
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x0000381D 02                 */ IL_0000: ldarg.0
		/* 0x0000381E 7B74000004         */ IL_0001: ldfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::EnvColorPicker /* 04000074 */
		/* 0x00003823 2875000006         */ IL_0006: call void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::FillColour(class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker) /* 06000075 */
		/* 0x00003828 02                 */ IL_000b: ldarg.0
		/* 0x00003829 7B76000004         */ IL_000c: ldfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::LineColorPicker /* 04000076 */
		/* 0x0000382E 2875000006         */ IL_0011: call void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::FillColour(class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker) /* 06000075 */
		/* 0x00003833 2A                 */ IL_0016: ret
	} // end of method UsrEnvelopePage::LoadColors

	.method /* 060000C9 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000055 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000056 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x3838
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00003838 02                 */ IL_0000: ldarg.0
		/* 0x00003839 7B7A000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::_contentLoaded /* 0400007A */
		/* 0x0000383E 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00003840 2A                 */ IL_0008: ret
		/* 0x00003841 02                 */ IL_0009: ldarg.0
		/* 0x00003842 17                 */ IL_000a: ldc.i4.1
		/* 0x00003843 7D7A000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::_contentLoaded /* 0400007A */
		/* 0x00003848 7273060070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrenvelopepage.xaml" /* 70000673 */
		/* 0x0000384D 18                 */ IL_0015: ldc.i4.2
		/* 0x0000384E 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x00003853 0A                 */ IL_001b: stloc.0
		/* 0x00003854 02                 */ IL_001c: ldarg.0
		/* 0x00003855 06                 */ IL_001d: ldloc.0
		/* 0x00003856 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x0000385B 2A                 */ IL_0023: ret
	} // end of method UsrEnvelopePage::InitializeComponent

	.method /* 060000CA */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000057 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000058 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000059 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x3868
		// Header size: 12
		// Code size: 287 (0x11f)
		.maxstack 3

		/* 0x00003868 03                 */ IL_0000: ldarg.1
		/* 0x00003869 17                 */ IL_0001: ldc.i4.1
		/* 0x0000386A 59                 */ IL_0002: sub
		/* 0x0000386B 450F000000         */ IL_0003: switch (
		/*              05000000         */                  IL_0049,
		/*              1D000000         */                  IL_0061,
		/*              2A000000         */                  IL_006e,
		/*              37000000         */                  IL_007b,
		/*              44000000         */                  IL_0088,
		/*              51000000         */                  IL_0095,
		/*              5E000000         */                  IL_00a2,
		/*              6B000000         */                  IL_00af,
		/*              78000000         */                  IL_00bc,
		/*              85000000         */                  IL_00c9,
		/*              92000000         */                  IL_00d6,
		/*              9F000000         */                  IL_00e3,
		/*              AC000000         */                  IL_00f0,
		/*              B9000000         */                  IL_00fd,
		/*              C6000000         */                  IL_010a)
		/* 0x000038AC 38CE000000         */ IL_0044: br IL_0117
		/* 0x000038B1 04                 */ IL_0049: ldarg.2
		/* 0x000038B2 7410000002         */ IL_004a: castclass AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage /* 02000010 */
		/* 0x000038B7 02                 */ IL_004f: ldarg.0
		/* 0x000038B8 FE06C6000006       */ IL_0050: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::UserControl_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000C6 */
		/* 0x000038BE 734600000A         */ IL_0056: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x000038C3 6F4700000A         */ IL_005b: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000047 */
		/* 0x000038C8 2A                 */ IL_0060: ret
		/* 0x000038C9 02                 */ IL_0061: ldarg.0
		/* 0x000038CA 04                 */ IL_0062: ldarg.2
		/* 0x000038CB 742C000001         */ IL_0063: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox /* 0100002C */
		/* 0x000038D0 7D6C000004         */ IL_0068: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::fraEnvelope /* 0400006C */
		/* 0x000038D5 2A                 */ IL_006d: ret
		/* 0x000038D6 02                 */ IL_006e: ldarg.0
		/* 0x000038D7 04                 */ IL_006f: ldarg.2
		/* 0x000038D8 7423000001         */ IL_0070: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000038DD 7D6D000004         */ IL_0075: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblEnvColour /* 0400006D */
		/* 0x000038E2 2A                 */ IL_007a: ret
		/* 0x000038E3 02                 */ IL_007b: ldarg.0
		/* 0x000038E4 04                 */ IL_007c: ldarg.2
		/* 0x000038E5 7423000001         */ IL_007d: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000038EA 7D6E000004         */ IL_0082: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblEnvPattern /* 0400006E */
		/* 0x000038EF 2A                 */ IL_0087: ret
		/* 0x000038F0 02                 */ IL_0088: ldarg.0
		/* 0x000038F1 04                 */ IL_0089: ldarg.2
		/* 0x000038F2 7423000001         */ IL_008a: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x000038F7 7D6F000004         */ IL_008f: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblLineColour /* 0400006F */
		/* 0x000038FC 2A                 */ IL_0094: ret
		/* 0x000038FD 02                 */ IL_0095: ldarg.0
		/* 0x000038FE 04                 */ IL_0096: ldarg.2
		/* 0x000038FF 7423000001         */ IL_0097: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003904 7D70000004         */ IL_009c: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblLineStyle /* 04000070 */
		/* 0x00003909 2A                 */ IL_00a1: ret
		/* 0x0000390A 02                 */ IL_00a2: ldarg.0
		/* 0x0000390B 04                 */ IL_00a3: ldarg.2
		/* 0x0000390C 7423000001         */ IL_00a4: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003911 7D71000004         */ IL_00a9: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblLineMarkerStyle /* 04000071 */
		/* 0x00003916 2A                 */ IL_00ae: ret
		/* 0x00003917 02                 */ IL_00af: ldarg.0
		/* 0x00003918 04                 */ IL_00b0: ldarg.2
		/* 0x00003919 7423000001         */ IL_00b1: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x0000391E 7D72000004         */ IL_00b6: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblVapMarkerStyle /* 04000072 */
		/* 0x00003923 2A                 */ IL_00bb: ret
		/* 0x00003924 02                 */ IL_00bc: ldarg.0
		/* 0x00003925 04                 */ IL_00bd: ldarg.2
		/* 0x00003926 7423000001         */ IL_00be: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x0000392B 7D73000004         */ IL_00c3: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::lblVapMarkerSize /* 04000073 */
		/* 0x00003930 2A                 */ IL_00c8: ret
		/* 0x00003931 02                 */ IL_00c9: ldarg.0
		/* 0x00003932 04                 */ IL_00ca: ldarg.2
		/* 0x00003933 741D000001         */ IL_00cb: castclass [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker /* 0100001D */
		/* 0x00003938 7D74000004         */ IL_00d0: stfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::EnvColorPicker /* 04000074 */
		/* 0x0000393D 2A                 */ IL_00d5: ret
		/* 0x0000393E 02                 */ IL_00d6: ldarg.0
		/* 0x0000393F 04                 */ IL_00d7: ldarg.2
		/* 0x00003940 7424000001         */ IL_00d8: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00003945 7D75000004         */ IL_00dd: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::EnvPatternStyleEditor /* 04000075 */
		/* 0x0000394A 2A                 */ IL_00e2: ret
		/* 0x0000394B 02                 */ IL_00e3: ldarg.0
		/* 0x0000394C 04                 */ IL_00e4: ldarg.2
		/* 0x0000394D 741D000001         */ IL_00e5: castclass [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker /* 0100001D */
		/* 0x00003952 7D76000004         */ IL_00ea: stfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::LineColorPicker /* 04000076 */
		/* 0x00003957 2A                 */ IL_00ef: ret
		/* 0x00003958 02                 */ IL_00f0: ldarg.0
		/* 0x00003959 04                 */ IL_00f1: ldarg.2
		/* 0x0000395A 7424000001         */ IL_00f2: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x0000395F 7D77000004         */ IL_00f7: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::LineStyleEditor /* 04000077 */
		/* 0x00003964 2A                 */ IL_00fc: ret
		/* 0x00003965 02                 */ IL_00fd: ldarg.0
		/* 0x00003966 04                 */ IL_00fe: ldarg.2
		/* 0x00003967 7424000001         */ IL_00ff: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x0000396C 7D78000004         */ IL_0104: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::LineMarkerEditor /* 04000078 */
		/* 0x00003971 2A                 */ IL_0109: ret
		/* 0x00003972 02                 */ IL_010a: ldarg.0
		/* 0x00003973 04                 */ IL_010b: ldarg.2
		/* 0x00003974 7424000001         */ IL_010c: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00003979 7D79000004         */ IL_0111: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::VapMarkerStyleEditor /* 04000079 */
		/* 0x0000397E 2A                 */ IL_0116: ret
		/* 0x0000397F 02                 */ IL_0117: ldarg.0
		/* 0x00003980 17                 */ IL_0118: ldc.i4.1
		/* 0x00003981 7D7A000004         */ IL_0119: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::_contentLoaded /* 0400007A */
		/* 0x00003986 2A                 */ IL_011e: ret
	} // end of method UsrEnvelopePage::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage

.class /* 02000011 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 0400007B */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage m_GeneralPage
	.field /* 0400007C */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox fraGeneral
	.field /* 0400007D */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox chkCoord
	.field /* 0400007E */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox chkBoilingPoint
	.field /* 0400007F */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox chkTransparent
	.field /* 04000080 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox chkStages
	.field /* 04000081 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblFont
	.field /* 04000082 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblFontSize
	.field /* 04000083 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblToolBarPos
	.field /* 04000084 */ private bool _contentLoaded

	// Methods
	.method /* 060000CB */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage pageObject
		) cil managed 
	{
		// Method begins at RVA 0x3993
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x00003993 02                 */ IL_0000: ldarg.0
		/* 0x00003994 284500000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x00003999 02                 */ IL_0006: ldarg.0
		/* 0x0000399A 28CF000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::InitializeComponent() /* 060000CF */
		/* 0x0000399F 02                 */ IL_000c: ldarg.0
		/* 0x000039A0 03                 */ IL_000d: ldarg.1
		/* 0x000039A1 7D7B000004         */ IL_000e: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::m_GeneralPage /* 0400007B */
		/* 0x000039A6 2A                 */ IL_0013: ret
	} // end of method UsrGeneralPage::.ctor

	.method /* 060000CC */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage get_GeneralPage () cil managed 
	{
		// Method begins at RVA 0x39a8
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000039A8 02                 */ IL_0000: ldarg.0
		/* 0x000039A9 7B7B000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::m_GeneralPage /* 0400007B */
		/* 0x000039AE 2A                 */ IL_0006: ret
	} // end of method UsrGeneralPage::get_GeneralPage

	.method /* 060000CD */ private hidebysig 
		instance void UserControl_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x39b0
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x000039B0 02                 */ IL_0000: ldarg.0
		/* 0x000039B1 02                 */ IL_0001: ldarg.0
		/* 0x000039B2 7B7B000004         */ IL_0002: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::m_GeneralPage /* 0400007B */
		/* 0x000039B7 284800000A         */ IL_0007: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x000039BC 02                 */ IL_000c: ldarg.0
		/* 0x000039BD 28CE000006         */ IL_000d: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::LoadCaptions() /* 060000CE */
		/* 0x000039C2 2A                 */ IL_0012: ret
	} // end of method UsrGeneralPage::UserControl_Loaded

	.method /* 060000CE */ private hidebysig 
		instance void LoadCaptions () cil managed 
	{
		// Method begins at RVA 0x39c4
		// Header size: 12
		// Code size: 129 (0x81)
		.maxstack 2

		/* 0x000039C4 02                 */ IL_0000: ldarg.0
		/* 0x000039C5 7B7C000004         */ IL_0001: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::fraGeneral /* 0400007C */
		/* 0x000039CA 286900000A         */ IL_0006: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R301_GeneralString() /* 0A000069 */
		/* 0x000039CF 6F5700000A         */ IL_000b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x000039D4 02                 */ IL_0010: ldarg.0
		/* 0x000039D5 7B7D000004         */ IL_0011: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkCoord /* 0400007D */
		/* 0x000039DA 286A00000A         */ IL_0016: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R302_DisplayFeedbackString() /* 0A00006A */
		/* 0x000039DF 6F6B00000A         */ IL_001b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox::set_Content(object) /* 0A00006B */
		/* 0x000039E4 02                 */ IL_0020: ldarg.0
		/* 0x000039E5 7B7E000004         */ IL_0021: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkBoilingPoint /* 0400007E */
		/* 0x000039EA 286C00000A         */ IL_0026: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R303_BoilingPointInfoString() /* 0A00006C */
		/* 0x000039EF 6F6B00000A         */ IL_002b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox::set_Content(object) /* 0A00006B */
		/* 0x000039F4 02                 */ IL_0030: ldarg.0
		/* 0x000039F5 7B7F000004         */ IL_0031: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkTransparent /* 0400007F */
		/* 0x000039FA 286D00000A         */ IL_0036: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R304_TransparentLabelString() /* 0A00006D */
		/* 0x000039FF 6F6B00000A         */ IL_003b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox::set_Content(object) /* 0A00006B */
		/* 0x00003A04 02                 */ IL_0040: ldarg.0
		/* 0x00003A05 7B80000004         */ IL_0041: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkStages /* 04000080 */
		/* 0x00003A0A 286E00000A         */ IL_0046: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R305_StageDataString() /* 0A00006E */
		/* 0x00003A0F 6F6B00000A         */ IL_004b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox::set_Content(object) /* 0A00006B */
		/* 0x00003A14 02                 */ IL_0050: ldarg.0
		/* 0x00003A15 7B81000004         */ IL_0051: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::lblFont /* 04000081 */
		/* 0x00003A1A 286F00000A         */ IL_0056: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R306_FontLabelString() /* 0A00006F */
		/* 0x00003A1F 6F4C00000A         */ IL_005b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003A24 02                 */ IL_0060: ldarg.0
		/* 0x00003A25 7B82000004         */ IL_0061: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::lblFontSize /* 04000082 */
		/* 0x00003A2A 287000000A         */ IL_0066: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R307_FontSizeString() /* 0A000070 */
		/* 0x00003A2F 6F4C00000A         */ IL_006b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003A34 02                 */ IL_0070: ldarg.0
		/* 0x00003A35 7B83000004         */ IL_0071: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::lblToolBarPos /* 04000083 */
		/* 0x00003A3A 287100000A         */ IL_0076: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R308_ToolbarPosString() /* 0A000071 */
		/* 0x00003A3F 6F4C00000A         */ IL_007b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003A44 2A                 */ IL_0080: ret
	} // end of method UsrGeneralPage::LoadCaptions

	.method /* 060000CF */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00005A */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00005B */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x3a54
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00003A54 02                 */ IL_0000: ldarg.0
		/* 0x00003A55 7B84000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::_contentLoaded /* 04000084 */
		/* 0x00003A5A 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00003A5C 2A                 */ IL_0008: ret
		/* 0x00003A5D 02                 */ IL_0009: ldarg.0
		/* 0x00003A5E 17                 */ IL_000a: ldc.i4.1
		/* 0x00003A5F 7D84000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::_contentLoaded /* 04000084 */
		/* 0x00003A64 7214070070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrgeneralpage.xaml" /* 70000714 */
		/* 0x00003A69 18                 */ IL_0015: ldc.i4.2
		/* 0x00003A6A 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x00003A6F 0A                 */ IL_001b: stloc.0
		/* 0x00003A70 02                 */ IL_001c: ldarg.0
		/* 0x00003A71 06                 */ IL_001d: ldloc.0
		/* 0x00003A72 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x00003A77 2A                 */ IL_0023: ret
	} // end of method UsrGeneralPage::InitializeComponent

	.method /* 060000D0 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C00005C */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00005D */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C00005E */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x3a84
		// Header size: 12
		// Code size: 185 (0xb9)
		.maxstack 3

		/* 0x00003A84 03                 */ IL_0000: ldarg.1
		/* 0x00003A85 17                 */ IL_0001: ldc.i4.1
		/* 0x00003A86 59                 */ IL_0002: sub
		/* 0x00003A87 4509000000         */ IL_0003: switch (
		/*              05000000         */                  IL_0031,
		/*              1D000000         */                  IL_0049,
		/*              2A000000         */                  IL_0056,
		/*              37000000         */                  IL_0063,
		/*              44000000         */                  IL_0070,
		/*              51000000         */                  IL_007d,
		/*              5E000000         */                  IL_008a,
		/*              6B000000         */                  IL_0097,
		/*              78000000         */                  IL_00a4)
		/* 0x00003AB0 3880000000         */ IL_002c: br IL_00b1
		/* 0x00003AB5 04                 */ IL_0031: ldarg.2
		/* 0x00003AB6 7411000002         */ IL_0032: castclass AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage /* 02000011 */
		/* 0x00003ABB 02                 */ IL_0037: ldarg.0
		/* 0x00003ABC FE06CD000006       */ IL_0038: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::UserControl_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000CD */
		/* 0x00003AC2 734600000A         */ IL_003e: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x00003AC7 6F4700000A         */ IL_0043: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000047 */
		/* 0x00003ACC 2A                 */ IL_0048: ret
		/* 0x00003ACD 02                 */ IL_0049: ldarg.0
		/* 0x00003ACE 04                 */ IL_004a: ldarg.2
		/* 0x00003ACF 742C000001         */ IL_004b: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox /* 0100002C */
		/* 0x00003AD4 7D7C000004         */ IL_0050: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::fraGeneral /* 0400007C */
		/* 0x00003AD9 2A                 */ IL_0055: ret
		/* 0x00003ADA 02                 */ IL_0056: ldarg.0
		/* 0x00003ADB 04                 */ IL_0057: ldarg.2
		/* 0x00003ADC 742F000001         */ IL_0058: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox /* 0100002F */
		/* 0x00003AE1 7D7D000004         */ IL_005d: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkCoord /* 0400007D */
		/* 0x00003AE6 2A                 */ IL_0062: ret
		/* 0x00003AE7 02                 */ IL_0063: ldarg.0
		/* 0x00003AE8 04                 */ IL_0064: ldarg.2
		/* 0x00003AE9 742F000001         */ IL_0065: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox /* 0100002F */
		/* 0x00003AEE 7D7E000004         */ IL_006a: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkBoilingPoint /* 0400007E */
		/* 0x00003AF3 2A                 */ IL_006f: ret
		/* 0x00003AF4 02                 */ IL_0070: ldarg.0
		/* 0x00003AF5 04                 */ IL_0071: ldarg.2
		/* 0x00003AF6 742F000001         */ IL_0072: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox /* 0100002F */
		/* 0x00003AFB 7D7F000004         */ IL_0077: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkTransparent /* 0400007F */
		/* 0x00003B00 2A                 */ IL_007c: ret
		/* 0x00003B01 02                 */ IL_007d: ldarg.0
		/* 0x00003B02 04                 */ IL_007e: ldarg.2
		/* 0x00003B03 742F000001         */ IL_007f: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox /* 0100002F */
		/* 0x00003B08 7D80000004         */ IL_0084: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesCheckBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::chkStages /* 04000080 */
		/* 0x00003B0D 2A                 */ IL_0089: ret
		/* 0x00003B0E 02                 */ IL_008a: ldarg.0
		/* 0x00003B0F 04                 */ IL_008b: ldarg.2
		/* 0x00003B10 7423000001         */ IL_008c: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003B15 7D81000004         */ IL_0091: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::lblFont /* 04000081 */
		/* 0x00003B1A 2A                 */ IL_0096: ret
		/* 0x00003B1B 02                 */ IL_0097: ldarg.0
		/* 0x00003B1C 04                 */ IL_0098: ldarg.2
		/* 0x00003B1D 7423000001         */ IL_0099: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003B22 7D82000004         */ IL_009e: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::lblFontSize /* 04000082 */
		/* 0x00003B27 2A                 */ IL_00a3: ret
		/* 0x00003B28 02                 */ IL_00a4: ldarg.0
		/* 0x00003B29 04                 */ IL_00a5: ldarg.2
		/* 0x00003B2A 7423000001         */ IL_00a6: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003B2F 7D83000004         */ IL_00ab: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::lblToolBarPos /* 04000083 */
		/* 0x00003B34 2A                 */ IL_00b0: ret
		/* 0x00003B35 02                 */ IL_00b1: ldarg.0
		/* 0x00003B36 17                 */ IL_00b2: ldc.i4.1
		/* 0x00003B37 7D84000004         */ IL_00b3: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::_contentLoaded /* 04000084 */
		/* 0x00003B3C 2A                 */ IL_00b8: ret
	} // end of method UsrGeneralPage::System.Windows.Markup.IComponentConnector.Connect

	// Properties
	.property /* 1700005F */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage GeneralPage()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::get_GeneralPage()
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage

.class /* 02000012 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 04000085 */ private valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum m_PageType
	.field /* 04000086 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox fraLine
	.field /* 04000087 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblLineColour
	.field /* 04000088 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblLineStyle
	.field /* 04000089 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblMarkerStyle
	.field /* 0400008A */ assembly class [PresentationFramework]System.Windows.Controls.Label lblMarkerSize
	.field /* 0400008B */ assembly class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker LineColorPicker
	.field /* 0400008C */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox LineStyleEditor
	.field /* 0400008D */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox LineMarkStyleEditor
	.field /* 0400008E */ private bool _contentLoaded

	// Methods
	.method /* 060000D1 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage pageObject
		) cil managed 
	{
		// Method begins at RVA 0x3b49
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00003B49 02                 */ IL_0000: ldarg.0
		/* 0x00003B4A 284500000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x00003B4F 02                 */ IL_0006: ldarg.0
		/* 0x00003B50 28D7000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::InitializeComponent() /* 060000D7 */
		/* 0x00003B55 02                 */ IL_000c: ldarg.0
		/* 0x00003B56 03                 */ IL_000d: ldarg.1
		/* 0x00003B57 284800000A         */ IL_000e: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x00003B5C 02                 */ IL_0013: ldarg.0
		/* 0x00003B5D 28D4000006         */ IL_0014: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::LoadColors() /* 060000D4 */
		/* 0x00003B62 2A                 */ IL_0019: ret
	} // end of method UsrLinePage::.ctor

	.method /* 060000D2 */ public hidebysig 
		instance void SetDataContext (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage page
		) cil managed 
	{
		// Method begins at RVA 0x3b64
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003B64 02                 */ IL_0000: ldarg.0
		/* 0x00003B65 03                 */ IL_0001: ldarg.1
		/* 0x00003B66 284800000A         */ IL_0002: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x00003B6B 2A                 */ IL_0007: ret
	} // end of method UsrLinePage::SetDataContext

	.method /* 060000D3 */ public hidebysig 
		instance void SetPageType (
			valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum 'type'
		) cil managed 
	{
		// Method begins at RVA 0x3b6d
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003B6D 02                 */ IL_0000: ldarg.0
		/* 0x00003B6E 03                 */ IL_0001: ldarg.1
		/* 0x00003B6F 7D85000004         */ IL_0002: stfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::m_PageType /* 04000085 */
		/* 0x00003B74 2A                 */ IL_0007: ret
	} // end of method UsrLinePage::SetPageType

	.method /* 060000D4 */ private hidebysig 
		instance void LoadColors () cil managed 
	{
		// Method begins at RVA 0x3b76
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00003B76 02                 */ IL_0000: ldarg.0
		/* 0x00003B77 7B8B000004         */ IL_0001: ldfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::LineColorPicker /* 0400008B */
		/* 0x00003B7C 2875000006         */ IL_0006: call void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::FillColour(class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker) /* 06000075 */
		/* 0x00003B81 2A                 */ IL_000b: ret
	} // end of method UsrLinePage::LoadColors

	.method /* 060000D5 */ private hidebysig 
		instance void LoadCaptions () cil managed 
	{
		// Method begins at RVA 0x3b84
		// Header size: 12
		// Code size: 183 (0xb7)
		.maxstack 2
		.locals /* 11000006 */ init (
			[0] valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum
		)

		/* 0x00003B84 02                 */ IL_0000: ldarg.0
		/* 0x00003B85 7B85000004         */ IL_0001: ldfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::m_PageType /* 04000085 */
		/* 0x00003B8A 0A                 */ IL_0006: stloc.0
		/* 0x00003B8B 06                 */ IL_0007: ldloc.0
		/* 0x00003B8C 1C                 */ IL_0008: ldc.i4.6
		/* 0x00003B8D 2E0A               */ IL_0009: beq.s IL_0015
		/* 0x00003B8F 06                 */ IL_000b: ldloc.0
		/* 0x00003B90 1D                 */ IL_000c: ldc.i4.7
		/* 0x00003B91 2E57               */ IL_000d: beq.s IL_0066
		/* 0x00003B93 06                 */ IL_000f: ldloc.0
		/* 0x00003B94 1F0B               */ IL_0010: ldc.i4.s 11
		/* 0x00003B96 2E52               */ IL_0012: beq.s IL_0066
		/* 0x00003B98 2A                 */ IL_0014: ret
		/* 0x00003B99 02                 */ IL_0015: ldarg.0
		/* 0x00003B9A 7B86000004         */ IL_0016: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::fraLine /* 04000086 */
		/* 0x00003B9F 287200000A         */ IL_001b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R901_FLinesString() /* 0A000072 */
		/* 0x00003BA4 6F5700000A         */ IL_0020: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003BA9 02                 */ IL_0025: ldarg.0
		/* 0x00003BAA 7B87000004         */ IL_0026: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblLineColour /* 04000087 */
		/* 0x00003BAF 287300000A         */ IL_002b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R902_LCString() /* 0A000073 */
		/* 0x00003BB4 6F4C00000A         */ IL_0030: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003BB9 02                 */ IL_0035: ldarg.0
		/* 0x00003BBA 7B88000004         */ IL_0036: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblLineStyle /* 04000088 */
		/* 0x00003BBF 287400000A         */ IL_003b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R903_LSString() /* 0A000074 */
		/* 0x00003BC4 6F4C00000A         */ IL_0040: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003BC9 02                 */ IL_0045: ldarg.0
		/* 0x00003BCA 7B89000004         */ IL_0046: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblMarkerStyle /* 04000089 */
		/* 0x00003BCF 287500000A         */ IL_004b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R904_LMStyleString() /* 0A000075 */
		/* 0x00003BD4 6F4C00000A         */ IL_0050: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003BD9 02                 */ IL_0055: ldarg.0
		/* 0x00003BDA 7B8A000004         */ IL_0056: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblMarkerSize /* 0400008A */
		/* 0x00003BDF 287600000A         */ IL_005b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R905_LMSizeString() /* 0A000076 */
		/* 0x00003BE4 6F4C00000A         */ IL_0060: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003BE9 2A                 */ IL_0065: ret
		/* 0x00003BEA 02                 */ IL_0066: ldarg.0
		/* 0x00003BEB 7B86000004         */ IL_0067: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::fraLine /* 04000086 */
		/* 0x00003BF0 287700000A         */ IL_006c: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1001_MBLString() /* 0A000077 */
		/* 0x00003BF5 6F5700000A         */ IL_0071: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003BFA 02                 */ IL_0076: ldarg.0
		/* 0x00003BFB 7B87000004         */ IL_0077: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblLineColour /* 04000087 */
		/* 0x00003C00 287300000A         */ IL_007c: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R902_LCString() /* 0A000073 */
		/* 0x00003C05 6F4C00000A         */ IL_0081: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003C0A 02                 */ IL_0086: ldarg.0
		/* 0x00003C0B 7B88000004         */ IL_0087: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblLineStyle /* 04000088 */
		/* 0x00003C10 287400000A         */ IL_008c: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R903_LSString() /* 0A000074 */
		/* 0x00003C15 6F4C00000A         */ IL_0091: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003C1A 02                 */ IL_0096: ldarg.0
		/* 0x00003C1B 7B89000004         */ IL_0097: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblMarkerStyle /* 04000089 */
		/* 0x00003C20 287500000A         */ IL_009c: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R904_LMStyleString() /* 0A000075 */
		/* 0x00003C25 6F4C00000A         */ IL_00a1: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003C2A 02                 */ IL_00a6: ldarg.0
		/* 0x00003C2B 7B8A000004         */ IL_00a7: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblMarkerSize /* 0400008A */
		/* 0x00003C30 287600000A         */ IL_00ac: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R905_LMSizeString() /* 0A000076 */
		/* 0x00003C35 6F4C00000A         */ IL_00b1: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003C3A 2A                 */ IL_00b6: ret
	} // end of method UsrLinePage::LoadCaptions

	.method /* 060000D6 */ private hidebysig 
		instance void UserControl_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3c47
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003C47 02                 */ IL_0000: ldarg.0
		/* 0x00003C48 28D5000006         */ IL_0001: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::LoadCaptions() /* 060000D5 */
		/* 0x00003C4D 2A                 */ IL_0006: ret
	} // end of method UsrLinePage::UserControl_Loaded

	.method /* 060000D7 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00005F */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000060 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x3c50
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00003C50 02                 */ IL_0000: ldarg.0
		/* 0x00003C51 7B8E000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::_contentLoaded /* 0400008E */
		/* 0x00003C56 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00003C58 2A                 */ IL_0008: ret
		/* 0x00003C59 02                 */ IL_0009: ldarg.0
		/* 0x00003C5A 17                 */ IL_000a: ldc.i4.1
		/* 0x00003C5B 7D8E000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::_contentLoaded /* 0400008E */
		/* 0x00003C60 72B3070070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrlinepage.xaml" /* 700007B3 */
		/* 0x00003C65 18                 */ IL_0015: ldc.i4.2
		/* 0x00003C66 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x00003C6B 0A                 */ IL_001b: stloc.0
		/* 0x00003C6C 02                 */ IL_001c: ldarg.0
		/* 0x00003C6D 06                 */ IL_001d: ldloc.0
		/* 0x00003C6E 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x00003C73 2A                 */ IL_0023: ret
	} // end of method UsrLinePage::InitializeComponent

	.method /* 060000D8 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000061 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000062 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000063 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x3c80
		// Header size: 12
		// Code size: 185 (0xb9)
		.maxstack 3

		/* 0x00003C80 03                 */ IL_0000: ldarg.1
		/* 0x00003C81 17                 */ IL_0001: ldc.i4.1
		/* 0x00003C82 59                 */ IL_0002: sub
		/* 0x00003C83 4509000000         */ IL_0003: switch (
		/*              05000000         */                  IL_0031,
		/*              1D000000         */                  IL_0049,
		/*              2A000000         */                  IL_0056,
		/*              37000000         */                  IL_0063,
		/*              44000000         */                  IL_0070,
		/*              51000000         */                  IL_007d,
		/*              5E000000         */                  IL_008a,
		/*              6B000000         */                  IL_0097,
		/*              78000000         */                  IL_00a4)
		/* 0x00003CAC 3880000000         */ IL_002c: br IL_00b1
		/* 0x00003CB1 04                 */ IL_0031: ldarg.2
		/* 0x00003CB2 7412000002         */ IL_0032: castclass AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage /* 02000012 */
		/* 0x00003CB7 02                 */ IL_0037: ldarg.0
		/* 0x00003CB8 FE06D6000006       */ IL_0038: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::UserControl_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000D6 */
		/* 0x00003CBE 734600000A         */ IL_003e: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x00003CC3 6F4700000A         */ IL_0043: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000047 */
		/* 0x00003CC8 2A                 */ IL_0048: ret
		/* 0x00003CC9 02                 */ IL_0049: ldarg.0
		/* 0x00003CCA 04                 */ IL_004a: ldarg.2
		/* 0x00003CCB 742C000001         */ IL_004b: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox /* 0100002C */
		/* 0x00003CD0 7D86000004         */ IL_0050: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::fraLine /* 04000086 */
		/* 0x00003CD5 2A                 */ IL_0055: ret
		/* 0x00003CD6 02                 */ IL_0056: ldarg.0
		/* 0x00003CD7 04                 */ IL_0057: ldarg.2
		/* 0x00003CD8 7423000001         */ IL_0058: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003CDD 7D87000004         */ IL_005d: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblLineColour /* 04000087 */
		/* 0x00003CE2 2A                 */ IL_0062: ret
		/* 0x00003CE3 02                 */ IL_0063: ldarg.0
		/* 0x00003CE4 04                 */ IL_0064: ldarg.2
		/* 0x00003CE5 7423000001         */ IL_0065: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003CEA 7D88000004         */ IL_006a: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblLineStyle /* 04000088 */
		/* 0x00003CEF 2A                 */ IL_006f: ret
		/* 0x00003CF0 02                 */ IL_0070: ldarg.0
		/* 0x00003CF1 04                 */ IL_0071: ldarg.2
		/* 0x00003CF2 7423000001         */ IL_0072: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003CF7 7D89000004         */ IL_0077: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblMarkerStyle /* 04000089 */
		/* 0x00003CFC 2A                 */ IL_007c: ret
		/* 0x00003CFD 02                 */ IL_007d: ldarg.0
		/* 0x00003CFE 04                 */ IL_007e: ldarg.2
		/* 0x00003CFF 7423000001         */ IL_007f: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003D04 7D8A000004         */ IL_0084: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::lblMarkerSize /* 0400008A */
		/* 0x00003D09 2A                 */ IL_0089: ret
		/* 0x00003D0A 02                 */ IL_008a: ldarg.0
		/* 0x00003D0B 04                 */ IL_008b: ldarg.2
		/* 0x00003D0C 741D000001         */ IL_008c: castclass [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker /* 0100001D */
		/* 0x00003D11 7D8B000004         */ IL_0091: stfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::LineColorPicker /* 0400008B */
		/* 0x00003D16 2A                 */ IL_0096: ret
		/* 0x00003D17 02                 */ IL_0097: ldarg.0
		/* 0x00003D18 04                 */ IL_0098: ldarg.2
		/* 0x00003D19 7424000001         */ IL_0099: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00003D1E 7D8C000004         */ IL_009e: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::LineStyleEditor /* 0400008C */
		/* 0x00003D23 2A                 */ IL_00a3: ret
		/* 0x00003D24 02                 */ IL_00a4: ldarg.0
		/* 0x00003D25 04                 */ IL_00a5: ldarg.2
		/* 0x00003D26 7424000001         */ IL_00a6: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00003D2B 7D8D000004         */ IL_00ab: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::LineMarkStyleEditor /* 0400008D */
		/* 0x00003D30 2A                 */ IL_00b0: ret
		/* 0x00003D31 02                 */ IL_00b1: ldarg.0
		/* 0x00003D32 17                 */ IL_00b2: ldc.i4.1
		/* 0x00003D33 7D8E000004         */ IL_00b3: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::_contentLoaded /* 0400008E */
		/* 0x00003D38 2A                 */ IL_00b8: ret
	} // end of method UsrLinePage::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage

.class /* 02000013 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 0400008F */ private valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum m_PageType
	.field /* 04000090 */ assembly class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox fraMarker
	.field /* 04000091 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblMarkerColour
	.field /* 04000092 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblMarkerStyle
	.field /* 04000093 */ assembly class [PresentationFramework]System.Windows.Controls.Label lblMarkerSize
	.field /* 04000094 */ assembly class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker MyColorPicker
	.field /* 04000095 */ assembly class [PresentationFramework]System.Windows.Controls.ComboBox MyMarkStyleEditor
	.field /* 04000096 */ private bool _contentLoaded

	// Methods
	.method /* 060000D9 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage pageObject
		) cil managed 
	{
		// Method begins at RVA 0x3d45
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x00003D45 02                 */ IL_0000: ldarg.0
		/* 0x00003D46 284500000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x00003D4B 02                 */ IL_0006: ldarg.0
		/* 0x00003D4C 28DF000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::InitializeComponent() /* 060000DF */
		/* 0x00003D51 02                 */ IL_000c: ldarg.0
		/* 0x00003D52 03                 */ IL_000d: ldarg.1
		/* 0x00003D53 284800000A         */ IL_000e: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x00003D58 2A                 */ IL_0013: ret
	} // end of method UsrMarkerPage::.ctor

	.method /* 060000DA */ public hidebysig 
		instance void SetDataContext (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage page
		) cil managed 
	{
		// Method begins at RVA 0x3b64
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003B64 02                 */ IL_0000: ldarg.0
		/* 0x00003B65 03                 */ IL_0001: ldarg.1
		/* 0x00003B66 284800000A         */ IL_0002: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A000048 */
		/* 0x00003B6B 2A                 */ IL_0007: ret
	} // end of method UsrMarkerPage::SetDataContext

	.method /* 060000DB */ public hidebysig 
		instance void SetPageType (
			valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum 'type'
		) cil managed 
	{
		// Method begins at RVA 0x3d5a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003D5A 02                 */ IL_0000: ldarg.0
		/* 0x00003D5B 03                 */ IL_0001: ldarg.1
		/* 0x00003D5C 7D8F000004         */ IL_0002: stfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::m_PageType /* 0400008F */
		/* 0x00003D61 2A                 */ IL_0007: ret
	} // end of method UsrMarkerPage::SetPageType

	.method /* 060000DC */ private hidebysig 
		instance void UserControl_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3d63
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003D63 02                 */ IL_0000: ldarg.0
		/* 0x00003D64 28DD000006         */ IL_0001: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::LoadCaptions() /* 060000DD */
		/* 0x00003D69 02                 */ IL_0006: ldarg.0
		/* 0x00003D6A 28DE000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::LoadColors() /* 060000DE */
		/* 0x00003D6F 2A                 */ IL_000c: ret
	} // end of method UsrMarkerPage::UserControl_Loaded

	.method /* 060000DD */ private hidebysig 
		instance void LoadCaptions () cil managed 
	{
		// Method begins at RVA 0x3d74
		// Header size: 12
		// Code size: 450 (0x1c2)
		.maxstack 2
		.locals /* 11000006 */ init (
			[0] valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum
		)

		/* 0x00003D74 02                 */ IL_0000: ldarg.0
		/* 0x00003D75 7B8F000004         */ IL_0001: ldfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::m_PageType /* 0400008F */
		/* 0x00003D7A 0A                 */ IL_0006: stloc.0
		/* 0x00003D7B 06                 */ IL_0007: ldloc.0
		/* 0x00003D7C 17                 */ IL_0008: ldc.i4.1
		/* 0x00003D7D 59                 */ IL_0009: sub
		/* 0x00003D7E 4509000000         */ IL_000a: switch (
		/*              09000000         */                  IL_003c,
		/*              4A000000         */                  IL_007d,
		/*              8E010000         */                  IL_01c1,
		/*              8E010000         */                  IL_01c1,
		/*              8B000000         */                  IL_00be,
		/*              8E010000         */                  IL_01c1,
		/*              8E010000         */                  IL_01c1,
		/*              CC000000         */                  IL_00ff,
		/*              0D010000         */                  IL_0140)
		/* 0x00003DA7 06                 */ IL_0033: ldloc.0
		/* 0x00003DA8 1F0C               */ IL_0034: ldc.i4.s 12
		/* 0x00003DAA 3B46010000         */ IL_0036: beq IL_0181
		/* 0x00003DAF 2A                 */ IL_003b: ret
		/* 0x00003DB0 02                 */ IL_003c: ldarg.0
		/* 0x00003DB1 7B90000004         */ IL_003d: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003DB6 287800000A         */ IL_0042: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R401_AzeotropesString() /* 0A000078 */
		/* 0x00003DBB 6F5700000A         */ IL_0047: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003DC0 02                 */ IL_004c: ldarg.0
		/* 0x00003DC1 7B91000004         */ IL_004d: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003DC6 287900000A         */ IL_0052: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R402_BPMColorString() /* 0A000079 */
		/* 0x00003DCB 6F4C00000A         */ IL_0057: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003DD0 02                 */ IL_005c: ldarg.0
		/* 0x00003DD1 7B92000004         */ IL_005d: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003DD6 287A00000A         */ IL_0062: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R403_BPMStyleString() /* 0A00007A */
		/* 0x00003DDB 6F4C00000A         */ IL_0067: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003DE0 02                 */ IL_006c: ldarg.0
		/* 0x00003DE1 7B93000004         */ IL_006d: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003DE6 287B00000A         */ IL_0072: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R404_BPMSizeString() /* 0A00007B */
		/* 0x00003DEB 6F4C00000A         */ IL_0077: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003DF0 2A                 */ IL_007c: ret
		/* 0x00003DF1 02                 */ IL_007d: ldarg.0
		/* 0x00003DF2 7B90000004         */ IL_007e: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003DF7 287C00000A         */ IL_0083: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R501_DistBoundaryString() /* 0A00007C */
		/* 0x00003DFC 6F5700000A         */ IL_0088: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003E01 02                 */ IL_008d: ldarg.0
		/* 0x00003E02 7B91000004         */ IL_008e: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003E07 287D00000A         */ IL_0093: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R502_BoundaryColorString() /* 0A00007D */
		/* 0x00003E0C 6F4C00000A         */ IL_0098: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E11 02                 */ IL_009d: ldarg.0
		/* 0x00003E12 7B92000004         */ IL_009e: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003E17 287E00000A         */ IL_00a3: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R503_BMStyleString() /* 0A00007E */
		/* 0x00003E1C 6F4C00000A         */ IL_00a8: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E21 02                 */ IL_00ad: ldarg.0
		/* 0x00003E22 7B93000004         */ IL_00ae: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003E27 287F00000A         */ IL_00b3: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R504_BMSizeString() /* 0A00007F */
		/* 0x00003E2C 6F4C00000A         */ IL_00b8: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E31 2A                 */ IL_00bd: ret
		/* 0x00003E32 02                 */ IL_00be: ldarg.0
		/* 0x00003E33 7B90000004         */ IL_00bf: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003E38 288000000A         */ IL_00c4: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R801_UMString() /* 0A000080 */
		/* 0x00003E3D 6F5700000A         */ IL_00c9: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003E42 02                 */ IL_00ce: ldarg.0
		/* 0x00003E43 7B91000004         */ IL_00cf: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003E48 288100000A         */ IL_00d4: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R802_UMCString() /* 0A000081 */
		/* 0x00003E4D 6F4C00000A         */ IL_00d9: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E52 02                 */ IL_00de: ldarg.0
		/* 0x00003E53 7B92000004         */ IL_00df: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003E58 288200000A         */ IL_00e4: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R803_UMStyleString() /* 0A000082 */
		/* 0x00003E5D 6F4C00000A         */ IL_00e9: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E62 02                 */ IL_00ee: ldarg.0
		/* 0x00003E63 7B93000004         */ IL_00ef: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003E68 288300000A         */ IL_00f4: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R804_UMSizeString() /* 0A000083 */
		/* 0x00003E6D 6F4C00000A         */ IL_00f9: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E72 2A                 */ IL_00fe: ret
		/* 0x00003E73 02                 */ IL_00ff: ldarg.0
		/* 0x00003E74 7B90000004         */ IL_0100: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003E79 288400000A         */ IL_0105: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1101_PMString() /* 0A000084 */
		/* 0x00003E7E 6F5700000A         */ IL_010a: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003E83 02                 */ IL_010f: ldarg.0
		/* 0x00003E84 7B91000004         */ IL_0110: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003E89 288500000A         */ IL_0115: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1102_PMColorString() /* 0A000085 */
		/* 0x00003E8E 6F4C00000A         */ IL_011a: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003E93 02                 */ IL_011f: ldarg.0
		/* 0x00003E94 7B92000004         */ IL_0120: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003E99 288600000A         */ IL_0125: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1103_PMStyleString() /* 0A000086 */
		/* 0x00003E9E 6F4C00000A         */ IL_012a: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003EA3 02                 */ IL_012f: ldarg.0
		/* 0x00003EA4 7B93000004         */ IL_0130: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003EA9 288700000A         */ IL_0135: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1104_PMSizeString() /* 0A000087 */
		/* 0x00003EAE 6F4C00000A         */ IL_013a: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003EB3 2A                 */ IL_013f: ret
		/* 0x00003EB4 02                 */ IL_0140: ldarg.0
		/* 0x00003EB5 7B90000004         */ IL_0141: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003EBA 288800000A         */ IL_0146: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1201_FMString() /* 0A000088 */
		/* 0x00003EBF 6F5700000A         */ IL_014b: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003EC4 02                 */ IL_0150: ldarg.0
		/* 0x00003EC5 7B91000004         */ IL_0151: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003ECA 288900000A         */ IL_0156: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1202_FMColorString() /* 0A000089 */
		/* 0x00003ECF 6F4C00000A         */ IL_015b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003ED4 02                 */ IL_0160: ldarg.0
		/* 0x00003ED5 7B92000004         */ IL_0161: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003EDA 288A00000A         */ IL_0166: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1203_FMStyleString() /* 0A00008A */
		/* 0x00003EDF 6F4C00000A         */ IL_016b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003EE4 02                 */ IL_0170: ldarg.0
		/* 0x00003EE5 7B93000004         */ IL_0171: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003EEA 288B00000A         */ IL_0176: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1204_FMSizeString() /* 0A00008B */
		/* 0x00003EEF 6F4C00000A         */ IL_017b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003EF4 2A                 */ IL_0180: ret
		/* 0x00003EF5 02                 */ IL_0181: ldarg.0
		/* 0x00003EF6 7B90000004         */ IL_0182: ldfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003EFB 288C00000A         */ IL_0187: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1501_CVString() /* 0A00008C */
		/* 0x00003F00 6F5700000A         */ IL_018c: callvirt instance void [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox::set_Header(object) /* 0A000057 */
		/* 0x00003F05 02                 */ IL_0191: ldarg.0
		/* 0x00003F06 7B91000004         */ IL_0192: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003F0B 288D00000A         */ IL_0197: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1502_CMCString() /* 0A00008D */
		/* 0x00003F10 6F4C00000A         */ IL_019c: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003F15 02                 */ IL_01a1: ldarg.0
		/* 0x00003F16 7B92000004         */ IL_01a2: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003F1B 288E00000A         */ IL_01a7: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1503_CMStyleString() /* 0A00008E */
		/* 0x00003F20 6F4C00000A         */ IL_01ac: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003F25 02                 */ IL_01b1: ldarg.0
		/* 0x00003F26 7B93000004         */ IL_01b2: ldfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003F2B 288F00000A         */ IL_01b7: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1504_CMSizeString() /* 0A00008F */
		/* 0x00003F30 6F4C00000A         */ IL_01bc: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00003F35 2A                 */ IL_01c1: ret
	} // end of method UsrMarkerPage::LoadCaptions

	.method /* 060000DE */ private hidebysig 
		instance void LoadColors () cil managed 
	{
		// Method begins at RVA 0x3f42
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00003F42 02                 */ IL_0000: ldarg.0
		/* 0x00003F43 7B94000004         */ IL_0001: ldfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::MyColorPicker /* 04000094 */
		/* 0x00003F48 2875000006         */ IL_0006: call void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Globals::FillColour(class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker) /* 06000075 */
		/* 0x00003F4D 2A                 */ IL_000b: ret
	} // end of method UsrMarkerPage::LoadColors

	.method /* 060000DF */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000064 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000065 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x3f50
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00003F50 02                 */ IL_0000: ldarg.0
		/* 0x00003F51 7B96000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::_contentLoaded /* 04000096 */
		/* 0x00003F56 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00003F58 2A                 */ IL_0008: ret
		/* 0x00003F59 02                 */ IL_0009: ldarg.0
		/* 0x00003F5A 17                 */ IL_000a: ldc.i4.1
		/* 0x00003F5B 7D96000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::_contentLoaded /* 04000096 */
		/* 0x00003F60 724C080070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrmarkerpage.xaml" /* 7000084C */
		/* 0x00003F65 18                 */ IL_0015: ldc.i4.2
		/* 0x00003F66 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x00003F6B 0A                 */ IL_001b: stloc.0
		/* 0x00003F6C 02                 */ IL_001c: ldarg.0
		/* 0x00003F6D 06                 */ IL_001d: ldloc.0
		/* 0x00003F6E 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x00003F73 2A                 */ IL_0023: ret
	} // end of method UsrMarkerPage::InitializeComponent

	.method /* 060000E0 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000066 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000067 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000068 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x3f80
		// Header size: 12
		// Code size: 148 (0x94)
		.maxstack 3

		/* 0x00003F80 03                 */ IL_0000: ldarg.1
		/* 0x00003F81 17                 */ IL_0001: ldc.i4.1
		/* 0x00003F82 59                 */ IL_0002: sub
		/* 0x00003F83 4507000000         */ IL_0003: switch (
		/*              02000000         */                  IL_0026,
		/*              1A000000         */                  IL_003e,
		/*              27000000         */                  IL_004b,
		/*              34000000         */                  IL_0058,
		/*              41000000         */                  IL_0065,
		/*              4E000000         */                  IL_0072,
		/*              5B000000         */                  IL_007f)
		/* 0x00003FA4 2B66               */ IL_0024: br.s IL_008c
		/* 0x00003FA6 04                 */ IL_0026: ldarg.2
		/* 0x00003FA7 7413000002         */ IL_0027: castclass AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage /* 02000013 */
		/* 0x00003FAC 02                 */ IL_002c: ldarg.0
		/* 0x00003FAD FE06DC000006       */ IL_002d: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::UserControl_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000DC */
		/* 0x00003FB3 734600000A         */ IL_0033: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x00003FB8 6F4700000A         */ IL_0038: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000047 */
		/* 0x00003FBD 2A                 */ IL_003d: ret
		/* 0x00003FBE 02                 */ IL_003e: ldarg.0
		/* 0x00003FBF 04                 */ IL_003f: ldarg.2
		/* 0x00003FC0 742C000001         */ IL_0040: castclass [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox /* 0100002C */
		/* 0x00003FC5 7D90000004         */ IL_0045: stfld class [AspenTech.WpfControls.Engineering]AspenTech.WpfControls.Engineering.AesGroupBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::fraMarker /* 04000090 */
		/* 0x00003FCA 2A                 */ IL_004a: ret
		/* 0x00003FCB 02                 */ IL_004b: ldarg.0
		/* 0x00003FCC 04                 */ IL_004c: ldarg.2
		/* 0x00003FCD 7423000001         */ IL_004d: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003FD2 7D91000004         */ IL_0052: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerColour /* 04000091 */
		/* 0x00003FD7 2A                 */ IL_0057: ret
		/* 0x00003FD8 02                 */ IL_0058: ldarg.0
		/* 0x00003FD9 04                 */ IL_0059: ldarg.2
		/* 0x00003FDA 7423000001         */ IL_005a: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003FDF 7D92000004         */ IL_005f: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerStyle /* 04000092 */
		/* 0x00003FE4 2A                 */ IL_0064: ret
		/* 0x00003FE5 02                 */ IL_0065: ldarg.0
		/* 0x00003FE6 04                 */ IL_0066: ldarg.2
		/* 0x00003FE7 7423000001         */ IL_0067: castclass [PresentationFramework]System.Windows.Controls.Label /* 01000023 */
		/* 0x00003FEC 7D93000004         */ IL_006c: stfld class [PresentationFramework]System.Windows.Controls.Label AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::lblMarkerSize /* 04000093 */
		/* 0x00003FF1 2A                 */ IL_0071: ret
		/* 0x00003FF2 02                 */ IL_0072: ldarg.0
		/* 0x00003FF3 04                 */ IL_0073: ldarg.2
		/* 0x00003FF4 741D000001         */ IL_0074: castclass [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker /* 0100001D */
		/* 0x00003FF9 7D94000004         */ IL_0079: stfld class [InfragisticsWPF.Controls.Editors.XamColorPicker]Infragistics.Controls.Editors.XamColorPicker AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::MyColorPicker /* 04000094 */
		/* 0x00003FFE 2A                 */ IL_007e: ret
		/* 0x00003FFF 02                 */ IL_007f: ldarg.0
		/* 0x00004000 04                 */ IL_0080: ldarg.2
		/* 0x00004001 7424000001         */ IL_0081: castclass [PresentationFramework]System.Windows.Controls.ComboBox /* 01000024 */
		/* 0x00004006 7D95000004         */ IL_0086: stfld class [PresentationFramework]System.Windows.Controls.ComboBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::MyMarkStyleEditor /* 04000095 */
		/* 0x0000400B 2A                 */ IL_008b: ret
		/* 0x0000400C 02                 */ IL_008c: ldarg.0
		/* 0x0000400D 17                 */ IL_008d: ldc.i4.1
		/* 0x0000400E 7D96000004         */ IL_008e: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::_contentLoaded /* 04000096 */
		/* 0x00004013 2A                 */ IL_0093: ret
	} // end of method UsrMarkerPage::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage

.class /* 02000014 */ public auto ansi beforefieldinit AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 04000097 */ private class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage m_CurvesPage
	.field /* 04000098 */ private class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage m_EnvelopePage
	.field /* 04000099 */ private class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage m_GeneralPage
	.field /* 0400009A */ private class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage m_LinePage
	.field /* 0400009B */ private class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage m_MarkerPage
	.field /* 0400009C */ private valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings '<AdjustSettings>k__BackingField'
	.custom /* 0C000046 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400009D */ private class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage '<PropPage>k__BackingField'
	.custom /* 0C000047 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400009E */ private valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum _propStartPage
	.field /* 0400009F */ private class [mscorlib]System.EventHandler OKButtonClick
	.custom /* 0C000048 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 040000A0 */ private class [mscorlib]System.EventHandler DefaultButtonClick
	.custom /* 0C000049 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 040000A1 */ private class [mscorlib]System.EventHandler CancelButtonClick
	.custom /* 0C00004A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 040000A2 */ assembly class [PresentationFramework]System.Windows.Controls.ListBox PropertyPageList
	.field /* 040000A3 */ assembly class [PresentationFramework]System.Windows.Controls.GridSplitter gridSplitter1
	.field /* 040000A4 */ assembly class [PresentationFramework]System.Windows.Controls.UserControl rightViewPanel
	.field /* 040000A5 */ assembly class [PresentationFramework]System.Windows.Controls.Button btnOk
	.field /* 040000A6 */ assembly class [PresentationFramework]System.Windows.Controls.Button btnDefault
	.field /* 040000A7 */ assembly class [PresentationFramework]System.Windows.Controls.Button btnCancel
	.field /* 040000A8 */ private bool _contentLoaded

	// Methods
	.method /* 060000E1 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x4020
		// Header size: 1
		// Code size: 30 (0x1e)
		.maxstack 8

		/* 0x00004020 02                 */ IL_0000: ldarg.0
		/* 0x00004021 284500000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000045 */
		/* 0x00004026 02                 */ IL_0006: ldarg.0
		/* 0x00004027 28F8000006         */ IL_0007: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::InitializeComponent() /* 060000F8 */
		/* 0x0000402C 02                 */ IL_000c: ldarg.0
		/* 0x0000402D 73B7000006         */ IL_000d: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::.ctor() /* 060000B7 */
		/* 0x00004032 28E5000006         */ IL_0012: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_PropPage(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage) /* 060000E5 */
		/* 0x00004037 02                 */ IL_0017: ldarg.0
		/* 0x00004038 28E9000006         */ IL_0018: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::LoadPropertyPageList() /* 060000E9 */
		/* 0x0000403D 2A                 */ IL_001d: ret
	} // end of method UsrPropPage::.ctor

	.method /* 060000E2 */ public hidebysig specialname 
		instance valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings get_AdjustSettings () cil managed 
	{
		.custom /* 0C000069 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x403f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000403F 02                 */ IL_0000: ldarg.0
		/* 0x00004040 7B9C000004         */ IL_0001: ldfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::'<AdjustSettings>k__BackingField' /* 0400009C */
		/* 0x00004045 2A                 */ IL_0006: ret
	} // end of method UsrPropPage::get_AdjustSettings

	.method /* 060000E3 */ public hidebysig specialname 
		instance void set_AdjustSettings (
			valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings 'value'
		) cil managed 
	{
		.custom /* 0C00006A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4047
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004047 02                 */ IL_0000: ldarg.0
		/* 0x00004048 03                 */ IL_0001: ldarg.1
		/* 0x00004049 7D9C000004         */ IL_0002: stfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::'<AdjustSettings>k__BackingField' /* 0400009C */
		/* 0x0000404E 2A                 */ IL_0007: ret
	} // end of method UsrPropPage::set_AdjustSettings

	.method /* 060000E4 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage get_PropPage () cil managed 
	{
		.custom /* 0C00006B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4050
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004050 02                 */ IL_0000: ldarg.0
		/* 0x00004051 7B9D000004         */ IL_0001: ldfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::'<PropPage>k__BackingField' /* 0400009D */
		/* 0x00004056 2A                 */ IL_0006: ret
	} // end of method UsrPropPage::get_PropPage

	.method /* 060000E5 */ public hidebysig specialname 
		instance void set_PropPage (
			class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage 'value'
		) cil managed 
	{
		.custom /* 0C00006C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4058
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004058 02                 */ IL_0000: ldarg.0
		/* 0x00004059 03                 */ IL_0001: ldarg.1
		/* 0x0000405A 7D9D000004         */ IL_0002: stfld class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::'<PropPage>k__BackingField' /* 0400009D */
		/* 0x0000405F 2A                 */ IL_0007: ret
	} // end of method UsrPropPage::set_PropPage

	.method /* 060000E6 */ public hidebysig specialname 
		instance void set_PropStartPage (
			valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum 'value'
		) cil managed 
	{
		// Method begins at RVA 0x4061
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x00004061 02                 */ IL_0000: ldarg.0
		/* 0x00004062 03                 */ IL_0001: ldarg.1
		/* 0x00004063 7D9E000004         */ IL_0002: stfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::_propStartPage /* 0400009E */
		/* 0x00004068 02                 */ IL_0007: ldarg.0
		/* 0x00004069 7BA2000004         */ IL_0008: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x0000406E 03                 */ IL_000d: ldarg.1
		/* 0x0000406F 6F9000000A         */ IL_000e: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Selector::set_SelectedIndex(int32) /* 0A000090 */
		/* 0x00004074 2A                 */ IL_0013: ret
	} // end of method UsrPropPage::set_PropStartPage

	.method /* 060000E7 */ public hidebysig specialname 
		instance valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum get_PropStartPage () cil managed 
	{
		// Method begins at RVA 0x4076
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004076 02                 */ IL_0000: ldarg.0
		/* 0x00004077 7B9E000004         */ IL_0001: ldfld valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::_propStartPage /* 0400009E */
		/* 0x0000407C 2A                 */ IL_0006: ret
	} // end of method UsrPropPage::get_PropStartPage

	.method /* 060000E8 */ private hidebysig 
		instance void UserControl_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x407e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000407E 02                 */ IL_0000: ldarg.0
		/* 0x0000407F 28EA000006         */ IL_0001: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::LoadButtonText() /* 060000EA */
		/* 0x00004084 2A                 */ IL_0006: ret
	} // end of method UsrPropPage::UserControl_Loaded

	.method /* 060000E9 */ private hidebysig 
		instance void LoadPropertyPageList () cil managed 
	{
		// Method begins at RVA 0x4088
		// Header size: 12
		// Code size: 299 (0x12b)
		.maxstack 2

		/* 0x00004088 02                 */ IL_0000: ldarg.0
		/* 0x00004089 7BA2000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x0000408E 6F9100000A         */ IL_0006: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x00004093 286900000A         */ IL_000b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R301_GeneralString() /* 0A000069 */
		/* 0x00004098 6F9200000A         */ IL_0010: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x0000409D 26                 */ IL_0015: pop
		/* 0x0000409E 02                 */ IL_0016: ldarg.0
		/* 0x0000409F 7BA2000004         */ IL_0017: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x000040A4 6F9100000A         */ IL_001c: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x000040A9 287800000A         */ IL_0021: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R401_AzeotropesString() /* 0A000078 */
		/* 0x000040AE 6F9200000A         */ IL_0026: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x000040B3 26                 */ IL_002b: pop
		/* 0x000040B4 02                 */ IL_002c: ldarg.0
		/* 0x000040B5 7BA2000004         */ IL_002d: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x000040BA 6F9100000A         */ IL_0032: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x000040BF 287C00000A         */ IL_0037: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R501_DistBoundaryString() /* 0A00007C */
		/* 0x000040C4 6F9200000A         */ IL_003c: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x000040C9 26                 */ IL_0041: pop
		/* 0x000040CA 02                 */ IL_0042: ldarg.0
		/* 0x000040CB 7BA2000004         */ IL_0043: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x000040D0 6F9100000A         */ IL_0048: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x000040D5 286100000A         */ IL_004d: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R601_EATString() /* 0A000061 */
		/* 0x000040DA 6F9200000A         */ IL_0052: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x000040DF 26                 */ IL_0057: pop
		/* 0x000040E0 02                 */ IL_0058: ldarg.0
		/* 0x000040E1 7BA2000004         */ IL_0059: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x000040E6 6F9100000A         */ IL_005e: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x000040EB 284900000A         */ IL_0063: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R701_RDCString() /* 0A000049 */
		/* 0x000040F0 6F9200000A         */ IL_0068: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x000040F5 26                 */ IL_006d: pop
		/* 0x000040F6 02                 */ IL_006e: ldarg.0
		/* 0x000040F7 7BA2000004         */ IL_006f: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x000040FC 6F9100000A         */ IL_0074: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x00004101 288000000A         */ IL_0079: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R801_UMString() /* 0A000080 */
		/* 0x00004106 6F9200000A         */ IL_007e: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x0000410B 26                 */ IL_0083: pop
		/* 0x0000410C 02                 */ IL_0084: ldarg.0
		/* 0x0000410D 7BA2000004         */ IL_0085: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004112 6F9100000A         */ IL_008a: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x00004117 287200000A         */ IL_008f: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R901_FLinesString() /* 0A000072 */
		/* 0x0000411C 6F9200000A         */ IL_0094: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x00004121 26                 */ IL_0099: pop
		/* 0x00004122 02                 */ IL_009a: ldarg.0
		/* 0x00004123 7BA2000004         */ IL_009b: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004128 6F9100000A         */ IL_00a0: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x0000412D 287700000A         */ IL_00a5: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1001_MBLString() /* 0A000077 */
		/* 0x00004132 6F9200000A         */ IL_00aa: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x00004137 26                 */ IL_00af: pop
		/* 0x00004138 02                 */ IL_00b0: ldarg.0
		/* 0x00004139 7BA2000004         */ IL_00b1: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x0000413E 6F9100000A         */ IL_00b6: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x00004143 288400000A         */ IL_00bb: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1101_PMString() /* 0A000084 */
		/* 0x00004148 6F9200000A         */ IL_00c0: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x0000414D 26                 */ IL_00c5: pop
		/* 0x0000414E 02                 */ IL_00c6: ldarg.0
		/* 0x0000414F 7BA2000004         */ IL_00c7: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004154 6F9100000A         */ IL_00cc: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x00004159 288800000A         */ IL_00d1: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1201_FMString() /* 0A000088 */
		/* 0x0000415E 6F9200000A         */ IL_00d6: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x00004163 26                 */ IL_00db: pop
		/* 0x00004164 02                 */ IL_00dc: ldarg.0
		/* 0x00004165 7BA2000004         */ IL_00dd: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x0000416A 6F9100000A         */ IL_00e2: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x0000416F 285200000A         */ IL_00e7: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1301_SRPString() /* 0A000052 */
		/* 0x00004174 6F9200000A         */ IL_00ec: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x00004179 26                 */ IL_00f1: pop
		/* 0x0000417A 02                 */ IL_00f2: ldarg.0
		/* 0x0000417B 7BA2000004         */ IL_00f3: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004180 6F9100000A         */ IL_00f8: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x00004185 289300000A         */ IL_00fd: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1401_DecanterString() /* 0A000093 */
		/* 0x0000418A 6F9200000A         */ IL_0102: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x0000418F 26                 */ IL_0107: pop
		/* 0x00004190 02                 */ IL_0108: ldarg.0
		/* 0x00004191 7BA2000004         */ IL_0109: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004196 6F9100000A         */ IL_010e: callvirt instance class [PresentationFramework]System.Windows.Controls.ItemCollection [PresentationFramework]System.Windows.Controls.ItemsControl::get_Items() /* 0A000091 */
		/* 0x0000419B 288C00000A         */ IL_0113: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R1501_CVString() /* 0A00008C */
		/* 0x000041A0 6F9200000A         */ IL_0118: callvirt instance int32 [PresentationFramework]System.Windows.Controls.ItemCollection::Add(object) /* 0A000092 */
		/* 0x000041A5 26                 */ IL_011d: pop
		/* 0x000041A6 02                 */ IL_011e: ldarg.0
		/* 0x000041A7 7BA2000004         */ IL_011f: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x000041AC 16                 */ IL_0124: ldc.i4.0
		/* 0x000041AD 6F9000000A         */ IL_0125: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Selector::set_SelectedIndex(int32) /* 0A000090 */
		/* 0x000041B2 2A                 */ IL_012a: ret
	} // end of method UsrPropPage::LoadPropertyPageList

	.method /* 060000EA */ private hidebysig 
		instance void LoadButtonText () cil managed 
	{
		// Method begins at RVA 0x41bf
		// Header size: 1
		// Code size: 49 (0x31)
		.maxstack 8

		/* 0x000041BF 02                 */ IL_0000: ldarg.0
		/* 0x000041C0 7BA5000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnOk /* 040000A5 */
		/* 0x000041C5 289400000A         */ IL_0006: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R101_OKString() /* 0A000094 */
		/* 0x000041CA 6F4C00000A         */ IL_000b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000041CF 02                 */ IL_0010: ldarg.0
		/* 0x000041D0 7BA6000004         */ IL_0011: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnDefault /* 040000A6 */
		/* 0x000041D5 289500000A         */ IL_0016: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R102_DefaultString() /* 0A000095 */
		/* 0x000041DA 6F4C00000A         */ IL_001b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000041DF 02                 */ IL_0020: ldarg.0
		/* 0x000041E0 7BA7000004         */ IL_0021: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnCancel /* 040000A7 */
		/* 0x000041E5 289600000A         */ IL_0026: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.WpfPropertyControlResources::get_R103_CancelString() /* 0A000096 */
		/* 0x000041EA 6F4C00000A         */ IL_002b: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000041EF 2A                 */ IL_0030: ret
	} // end of method UsrPropPage::LoadButtonText

	.method /* 060000EB */ private hidebysig 
		instance void btnOk_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x41f1
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x000041F1 02                 */ IL_0000: ldarg.0
		/* 0x000041F2 16                 */ IL_0001: ldc.i4.0
		/* 0x000041F3 28E3000006         */ IL_0002: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_AdjustSettings(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings) /* 060000E3 */
		/* 0x000041F8 02                 */ IL_0007: ldarg.0
		/* 0x000041F9 28F1000006         */ IL_0008: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OnOKButtonClick() /* 060000F1 */
		/* 0x000041FE 2A                 */ IL_000d: ret
	} // end of method UsrPropPage::btnOk_Click

	.method /* 060000EC */ private hidebysig 
		instance void btnDefault_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4200
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x00004200 02                 */ IL_0000: ldarg.0
		/* 0x00004201 18                 */ IL_0001: ldc.i4.2
		/* 0x00004202 28E3000006         */ IL_0002: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_AdjustSettings(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings) /* 060000E3 */
		/* 0x00004207 02                 */ IL_0007: ldarg.0
		/* 0x00004208 28F4000006         */ IL_0008: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OnDefaultButtonClick() /* 060000F4 */
		/* 0x0000420D 2A                 */ IL_000d: ret
	} // end of method UsrPropPage::btnDefault_Click

	.method /* 060000ED */ private hidebysig 
		instance void btnCancel_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x420f
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x0000420F 02                 */ IL_0000: ldarg.0
		/* 0x00004210 17                 */ IL_0001: ldc.i4.1
		/* 0x00004211 28E3000006         */ IL_0002: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_AdjustSettings(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings) /* 060000E3 */
		/* 0x00004216 02                 */ IL_0007: ldarg.0
		/* 0x00004217 28F7000006         */ IL_0008: call instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OnCancelButtonClick() /* 060000F7 */
		/* 0x0000421C 2A                 */ IL_000d: ret
	} // end of method UsrPropPage::btnCancel_Click

	.method /* 060000EE */ private hidebysig 
		instance void PropertyPageList_SelectionChanged (
			object sender,
			class [PresentationFramework]System.Windows.Controls.SelectionChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4220
		// Header size: 12
		// Code size: 752 (0x2f0)
		.maxstack 2
		.locals /* 11000003 */ init (
			[0] int32
		)

		/* 0x00004220 02                 */ IL_0000: ldarg.0
		/* 0x00004221 7BA2000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004226 6F9700000A         */ IL_0006: callvirt instance int32 [PresentationFramework]System.Windows.Controls.Primitives.Selector::get_SelectedIndex() /* 0A000097 */
		/* 0x0000422B 0A                 */ IL_000b: stloc.0
		/* 0x0000422C 06                 */ IL_000c: ldloc.0
		/* 0x0000422D 450D000000         */ IL_000d: switch (
		/*              05000000         */                  IL_004b,
		/*              35000000         */                  IL_007b,
		/*              69000000         */                  IL_00af,
		/*              9D000000         */                  IL_00e3,
		/*              69020000         */                  IL_02af,
		/*              C5000000         */                  IL_010b,
		/*              F9000000         */                  IL_013f,
		/*              2D010000         */                  IL_0173,
		/*              61010000         */                  IL_01a7,
		/*              95010000         */                  IL_01db,
		/*              CA010000         */                  IL_0210,
		/*              FF010000         */                  IL_0245,
		/*              34020000         */                  IL_027a)
		/* 0x00004266 3898020000         */ IL_0046: br IL_02e3
		/* 0x0000426B 02                 */ IL_004b: ldarg.0
		/* 0x0000426C 7B99000004         */ IL_004c: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_GeneralPage /* 04000099 */
		/* 0x00004271 2D16               */ IL_0051: brtrue.s IL_0069
		/* 0x00004273 02                 */ IL_0053: ldarg.0
		/* 0x00004274 02                 */ IL_0054: ldarg.0
		/* 0x00004275 28E4000006         */ IL_0055: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x0000427A 6F9D000006         */ IL_005a: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_GeneralProps() /* 0600009D */
		/* 0x0000427F 73CB000006         */ IL_005f: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.GeneralPage) /* 060000CB */
		/* 0x00004284 7D99000004         */ IL_0064: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_GeneralPage /* 04000099 */
		/* 0x00004289 02                 */ IL_0069: ldarg.0
		/* 0x0000428A 7BA4000004         */ IL_006a: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x0000428F 02                 */ IL_006f: ldarg.0
		/* 0x00004290 7B99000004         */ IL_0070: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrGeneralPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_GeneralPage /* 04000099 */
		/* 0x00004295 6F4C00000A         */ IL_0075: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000429A 2A                 */ IL_007a: ret
		/* 0x0000429B 02                 */ IL_007b: ldarg.0
		/* 0x0000429C 02                 */ IL_007c: ldarg.0
		/* 0x0000429D 28E4000006         */ IL_007d: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x000042A2 6F9F000006         */ IL_0082: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_AzeoProps() /* 0600009F */
		/* 0x000042A7 73D9000006         */ IL_0087: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage) /* 060000D9 */
		/* 0x000042AC 7D9B000004         */ IL_008c: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000042B1 02                 */ IL_0091: ldarg.0
		/* 0x000042B2 7B9B000004         */ IL_0092: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000042B7 17                 */ IL_0097: ldc.i4.1
		/* 0x000042B8 6FDB000006         */ IL_0098: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000DB */
		/* 0x000042BD 02                 */ IL_009d: ldarg.0
		/* 0x000042BE 7BA4000004         */ IL_009e: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x000042C3 02                 */ IL_00a3: ldarg.0
		/* 0x000042C4 7B9B000004         */ IL_00a4: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000042C9 6F4C00000A         */ IL_00a9: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000042CE 2A                 */ IL_00ae: ret
		/* 0x000042CF 02                 */ IL_00af: ldarg.0
		/* 0x000042D0 02                 */ IL_00b0: ldarg.0
		/* 0x000042D1 28E4000006         */ IL_00b1: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x000042D6 6FA1000006         */ IL_00b6: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_BoundayProps() /* 060000A1 */
		/* 0x000042DB 73D9000006         */ IL_00bb: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage) /* 060000D9 */
		/* 0x000042E0 7D9B000004         */ IL_00c0: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000042E5 02                 */ IL_00c5: ldarg.0
		/* 0x000042E6 7B9B000004         */ IL_00c6: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000042EB 18                 */ IL_00cb: ldc.i4.2
		/* 0x000042EC 6FDB000006         */ IL_00cc: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000DB */
		/* 0x000042F1 02                 */ IL_00d1: ldarg.0
		/* 0x000042F2 7BA4000004         */ IL_00d2: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x000042F7 02                 */ IL_00d7: ldarg.0
		/* 0x000042F8 7B9B000004         */ IL_00d8: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000042FD 6F4C00000A         */ IL_00dd: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00004302 2A                 */ IL_00e2: ret
		/* 0x00004303 02                 */ IL_00e3: ldarg.0
		/* 0x00004304 02                 */ IL_00e4: ldarg.0
		/* 0x00004305 28E4000006         */ IL_00e5: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x0000430A 6FA3000006         */ IL_00ea: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_EnvelopeProps() /* 060000A3 */
		/* 0x0000430F 73C5000006         */ IL_00ef: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.EnvelopPage) /* 060000C5 */
		/* 0x00004314 7D98000004         */ IL_00f4: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_EnvelopePage /* 04000098 */
		/* 0x00004319 02                 */ IL_00f9: ldarg.0
		/* 0x0000431A 7BA4000004         */ IL_00fa: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x0000431F 02                 */ IL_00ff: ldarg.0
		/* 0x00004320 7B98000004         */ IL_0100: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrEnvelopePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_EnvelopePage /* 04000098 */
		/* 0x00004325 6F4C00000A         */ IL_0105: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000432A 2A                 */ IL_010a: ret
		/* 0x0000432B 02                 */ IL_010b: ldarg.0
		/* 0x0000432C 02                 */ IL_010c: ldarg.0
		/* 0x0000432D 28E4000006         */ IL_010d: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x00004332 6FA7000006         */ IL_0112: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_MarkerProps() /* 060000A7 */
		/* 0x00004337 73D9000006         */ IL_0117: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage) /* 060000D9 */
		/* 0x0000433C 7D9B000004         */ IL_011c: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x00004341 02                 */ IL_0121: ldarg.0
		/* 0x00004342 7B9B000004         */ IL_0122: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x00004347 1B                 */ IL_0127: ldc.i4.5
		/* 0x00004348 6FDB000006         */ IL_0128: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000DB */
		/* 0x0000434D 02                 */ IL_012d: ldarg.0
		/* 0x0000434E 7BA4000004         */ IL_012e: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x00004353 02                 */ IL_0133: ldarg.0
		/* 0x00004354 7B9B000004         */ IL_0134: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x00004359 6F4C00000A         */ IL_0139: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000435E 2A                 */ IL_013e: ret
		/* 0x0000435F 02                 */ IL_013f: ldarg.0
		/* 0x00004360 02                 */ IL_0140: ldarg.0
		/* 0x00004361 28E4000006         */ IL_0141: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x00004366 6FA9000006         */ IL_0146: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_FreeHandProps() /* 060000A9 */
		/* 0x0000436B 73D1000006         */ IL_014b: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage) /* 060000D1 */
		/* 0x00004370 7D9A000004         */ IL_0150: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x00004375 02                 */ IL_0155: ldarg.0
		/* 0x00004376 7B9A000004         */ IL_0156: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x0000437B 1C                 */ IL_015b: ldc.i4.6
		/* 0x0000437C 6FD3000006         */ IL_015c: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000D3 */
		/* 0x00004381 02                 */ IL_0161: ldarg.0
		/* 0x00004382 7BA4000004         */ IL_0162: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x00004387 02                 */ IL_0167: ldarg.0
		/* 0x00004388 7B9A000004         */ IL_0168: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x0000438D 6F4C00000A         */ IL_016d: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00004392 2A                 */ IL_0172: ret
		/* 0x00004393 02                 */ IL_0173: ldarg.0
		/* 0x00004394 02                 */ IL_0174: ldarg.0
		/* 0x00004395 28E4000006         */ IL_0175: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x0000439A 6FAB000006         */ IL_017a: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_MatBalProps() /* 060000AB */
		/* 0x0000439F 73D1000006         */ IL_017f: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage) /* 060000D1 */
		/* 0x000043A4 7D9A000004         */ IL_0184: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x000043A9 02                 */ IL_0189: ldarg.0
		/* 0x000043AA 7B9A000004         */ IL_018a: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x000043AF 1D                 */ IL_018f: ldc.i4.7
		/* 0x000043B0 6FD3000006         */ IL_0190: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000D3 */
		/* 0x000043B5 02                 */ IL_0195: ldarg.0
		/* 0x000043B6 7BA4000004         */ IL_0196: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x000043BB 02                 */ IL_019b: ldarg.0
		/* 0x000043BC 7B9A000004         */ IL_019c: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x000043C1 6F4C00000A         */ IL_01a1: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000043C6 2A                 */ IL_01a6: ret
		/* 0x000043C7 02                 */ IL_01a7: ldarg.0
		/* 0x000043C8 02                 */ IL_01a8: ldarg.0
		/* 0x000043C9 28E4000006         */ IL_01a9: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x000043CE 6FAD000006         */ IL_01ae: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_ProductProps() /* 060000AD */
		/* 0x000043D3 73D9000006         */ IL_01b3: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage) /* 060000D9 */
		/* 0x000043D8 7D9B000004         */ IL_01b8: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000043DD 02                 */ IL_01bd: ldarg.0
		/* 0x000043DE 7B9B000004         */ IL_01be: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000043E3 1E                 */ IL_01c3: ldc.i4.8
		/* 0x000043E4 6FDB000006         */ IL_01c4: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000DB */
		/* 0x000043E9 02                 */ IL_01c9: ldarg.0
		/* 0x000043EA 7BA4000004         */ IL_01ca: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x000043EF 02                 */ IL_01cf: ldarg.0
		/* 0x000043F0 7B9B000004         */ IL_01d0: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000043F5 6F4C00000A         */ IL_01d5: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000043FA 2A                 */ IL_01da: ret
		/* 0x000043FB 02                 */ IL_01db: ldarg.0
		/* 0x000043FC 02                 */ IL_01dc: ldarg.0
		/* 0x000043FD 28E4000006         */ IL_01dd: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x00004402 6FAF000006         */ IL_01e2: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_FeedProps() /* 060000AF */
		/* 0x00004407 73D9000006         */ IL_01e7: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage) /* 060000D9 */
		/* 0x0000440C 7D9B000004         */ IL_01ec: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x00004411 02                 */ IL_01f1: ldarg.0
		/* 0x00004412 7B9B000004         */ IL_01f2: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x00004417 1F09               */ IL_01f7: ldc.i4.s 9
		/* 0x00004419 6FDB000006         */ IL_01f9: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000DB */
		/* 0x0000441E 02                 */ IL_01fe: ldarg.0
		/* 0x0000441F 7BA4000004         */ IL_01ff: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x00004424 02                 */ IL_0204: ldarg.0
		/* 0x00004425 7B9B000004         */ IL_0205: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x0000442A 6F4C00000A         */ IL_020a: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000442F 2A                 */ IL_020f: ret
		/* 0x00004430 02                 */ IL_0210: ldarg.0
		/* 0x00004431 02                 */ IL_0211: ldarg.0
		/* 0x00004432 28E4000006         */ IL_0212: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x00004437 6FB1000006         */ IL_0217: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_ProfilesProps() /* 060000B1 */
		/* 0x0000443C 73B8000006         */ IL_021c: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage) /* 060000B8 */
		/* 0x00004441 7D97000004         */ IL_0221: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_CurvesPage /* 04000097 */
		/* 0x00004446 02                 */ IL_0226: ldarg.0
		/* 0x00004447 7B97000004         */ IL_0227: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_CurvesPage /* 04000097 */
		/* 0x0000444C 1F0A               */ IL_022c: ldc.i4.s 10
		/* 0x0000444E 6FBA000006         */ IL_022e: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000BA */
		/* 0x00004453 02                 */ IL_0233: ldarg.0
		/* 0x00004454 7BA4000004         */ IL_0234: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x00004459 02                 */ IL_0239: ldarg.0
		/* 0x0000445A 7B97000004         */ IL_023a: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_CurvesPage /* 04000097 */
		/* 0x0000445F 6F4C00000A         */ IL_023f: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00004464 2A                 */ IL_0244: ret
		/* 0x00004465 02                 */ IL_0245: ldarg.0
		/* 0x00004466 02                 */ IL_0246: ldarg.0
		/* 0x00004467 28E4000006         */ IL_0247: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x0000446C 6FB3000006         */ IL_024c: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_DecanterProps() /* 060000B3 */
		/* 0x00004471 73D1000006         */ IL_0251: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.LinePage) /* 060000D1 */
		/* 0x00004476 7D9A000004         */ IL_0256: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x0000447B 02                 */ IL_025b: ldarg.0
		/* 0x0000447C 7B9A000004         */ IL_025c: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x00004481 1F0B               */ IL_0261: ldc.i4.s 11
		/* 0x00004483 6FD3000006         */ IL_0263: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000D3 */
		/* 0x00004488 02                 */ IL_0268: ldarg.0
		/* 0x00004489 7BA4000004         */ IL_0269: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x0000448E 02                 */ IL_026e: ldarg.0
		/* 0x0000448F 7B9A000004         */ IL_026f: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrLinePage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_LinePage /* 0400009A */
		/* 0x00004494 6F4C00000A         */ IL_0274: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00004499 2A                 */ IL_0279: ret
		/* 0x0000449A 02                 */ IL_027a: ldarg.0
		/* 0x0000449B 02                 */ IL_027b: ldarg.0
		/* 0x0000449C 28E4000006         */ IL_027c: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x000044A1 6FB5000006         */ IL_0281: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_ColumnVapourProps() /* 060000B5 */
		/* 0x000044A6 73D9000006         */ IL_0286: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.MarkerPage) /* 060000D9 */
		/* 0x000044AB 7D9B000004         */ IL_028b: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000044B0 02                 */ IL_0290: ldarg.0
		/* 0x000044B1 7B9B000004         */ IL_0291: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000044B6 1F0C               */ IL_0296: ldc.i4.s 12
		/* 0x000044B8 6FDB000006         */ IL_0298: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000DB */
		/* 0x000044BD 02                 */ IL_029d: ldarg.0
		/* 0x000044BE 7BA4000004         */ IL_029e: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x000044C3 02                 */ IL_02a3: ldarg.0
		/* 0x000044C4 7B9B000004         */ IL_02a4: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrMarkerPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_MarkerPage /* 0400009B */
		/* 0x000044C9 6F4C00000A         */ IL_02a9: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x000044CE 2A                 */ IL_02ae: ret
		/* 0x000044CF 02                 */ IL_02af: ldarg.0
		/* 0x000044D0 02                 */ IL_02b0: ldarg.0
		/* 0x000044D1 28E4000006         */ IL_02b1: call instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage() /* 060000E4 */
		/* 0x000044D6 6FA5000006         */ IL_02b6: callvirt instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage::get_CurveProps() /* 060000A5 */
		/* 0x000044DB 73B8000006         */ IL_02bb: newobj instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::.ctor(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.CurvesPage) /* 060000B8 */
		/* 0x000044E0 7D97000004         */ IL_02c0: stfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_CurvesPage /* 04000097 */
		/* 0x000044E5 02                 */ IL_02c5: ldarg.0
		/* 0x000044E6 7B97000004         */ IL_02c6: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_CurvesPage /* 04000097 */
		/* 0x000044EB 1A                 */ IL_02cb: ldc.i4.4
		/* 0x000044EC 6FBA000006         */ IL_02cc: callvirt instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage::SetPageType(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum) /* 060000BA */
		/* 0x000044F1 02                 */ IL_02d1: ldarg.0
		/* 0x000044F2 7BA4000004         */ IL_02d2: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x000044F7 02                 */ IL_02d7: ldarg.0
		/* 0x000044F8 7B97000004         */ IL_02d8: ldfld class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrCurvesPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::m_CurvesPage /* 04000097 */
		/* 0x000044FD 6F4C00000A         */ IL_02dd: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x00004502 2A                 */ IL_02e2: ret
		/* 0x00004503 02                 */ IL_02e3: ldarg.0
		/* 0x00004504 7BA4000004         */ IL_02e4: ldfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x00004509 14                 */ IL_02e9: ldnull
		/* 0x0000450A 6F4C00000A         */ IL_02ea: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A00004C */
		/* 0x0000450F 2A                 */ IL_02ef: ret
	} // end of method UsrPropPage::PropertyPageList_SelectionChanged

	.method /* 060000EF */ public hidebysig specialname 
		instance void add_OKButtonClick (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00006D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x451c
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x0000451C 02                 */ IL_0000: ldarg.0
		/* 0x0000451D 7B9F000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OKButtonClick /* 0400009F */
		/* 0x00004522 0A                 */ IL_0006: stloc.0
		/* 0x00004523 06                 */ IL_0007: ldloc.0
		/* 0x00004524 0B                 */ IL_0008: stloc.1
		/* 0x00004525 07                 */ IL_0009: ldloc.1
		/* 0x00004526 03                 */ IL_000a: ldarg.1
		/* 0x00004527 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x0000452C 7430000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000030 */
		/* 0x00004531 0C                 */ IL_0015: stloc.2
		/* 0x00004532 02                 */ IL_0016: ldarg.0
		/* 0x00004533 7C9F000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OKButtonClick /* 0400009F */
		/* 0x00004538 08                 */ IL_001c: ldloc.2
		/* 0x00004539 07                 */ IL_001d: ldloc.1
		/* 0x0000453A 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x0000453F 0A                 */ IL_0023: stloc.0
		/* 0x00004540 06                 */ IL_0024: ldloc.0
		/* 0x00004541 07                 */ IL_0025: ldloc.1
		/* 0x00004542 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00004544 2A                 */ IL_0028: ret
	} // end of method UsrPropPage::add_OKButtonClick

	.method /* 060000F0 */ public hidebysig specialname 
		instance void remove_OKButtonClick (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00006E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4554
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00004554 02                 */ IL_0000: ldarg.0
		/* 0x00004555 7B9F000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OKButtonClick /* 0400009F */
		/* 0x0000455A 0A                 */ IL_0006: stloc.0
		/* 0x0000455B 06                 */ IL_0007: ldloc.0
		/* 0x0000455C 0B                 */ IL_0008: stloc.1
		/* 0x0000455D 07                 */ IL_0009: ldloc.1
		/* 0x0000455E 03                 */ IL_000a: ldarg.1
		/* 0x0000455F 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x00004564 7430000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000030 */
		/* 0x00004569 0C                 */ IL_0015: stloc.2
		/* 0x0000456A 02                 */ IL_0016: ldarg.0
		/* 0x0000456B 7C9F000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OKButtonClick /* 0400009F */
		/* 0x00004570 08                 */ IL_001c: ldloc.2
		/* 0x00004571 07                 */ IL_001d: ldloc.1
		/* 0x00004572 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x00004577 0A                 */ IL_0023: stloc.0
		/* 0x00004578 06                 */ IL_0024: ldloc.0
		/* 0x00004579 07                 */ IL_0025: ldloc.1
		/* 0x0000457A 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x0000457C 2A                 */ IL_0028: ret
	} // end of method UsrPropPage::remove_OKButtonClick

	.method /* 060000F1 */ private hidebysig 
		instance void OnOKButtonClick () cil managed 
	{
		// Method begins at RVA 0x4589
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00004589 02                 */ IL_0000: ldarg.0
		/* 0x0000458A 7B9F000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OKButtonClick /* 0400009F */
		/* 0x0000458F 2C11               */ IL_0006: brfalse.s IL_0019
		/* 0x00004591 02                 */ IL_0008: ldarg.0
		/* 0x00004592 7B9F000004         */ IL_0009: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::OKButtonClick /* 0400009F */
		/* 0x00004597 02                 */ IL_000e: ldarg.0
		/* 0x00004598 739800000A         */ IL_000f: newobj instance void [mscorlib]System.EventArgs::.ctor() /* 0A000098 */
		/* 0x0000459D 6F9900000A         */ IL_0014: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs) /* 0A000099 */
		/* 0x000045A2 2A                 */ IL_0019: ret
	} // end of method UsrPropPage::OnOKButtonClick

	.method /* 060000F2 */ public hidebysig specialname 
		instance void add_DefaultButtonClick (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00006F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x45a4
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x000045A4 02                 */ IL_0000: ldarg.0
		/* 0x000045A5 7BA0000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::DefaultButtonClick /* 040000A0 */
		/* 0x000045AA 0A                 */ IL_0006: stloc.0
		/* 0x000045AB 06                 */ IL_0007: ldloc.0
		/* 0x000045AC 0B                 */ IL_0008: stloc.1
		/* 0x000045AD 07                 */ IL_0009: ldloc.1
		/* 0x000045AE 03                 */ IL_000a: ldarg.1
		/* 0x000045AF 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000045B4 7430000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000030 */
		/* 0x000045B9 0C                 */ IL_0015: stloc.2
		/* 0x000045BA 02                 */ IL_0016: ldarg.0
		/* 0x000045BB 7CA0000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::DefaultButtonClick /* 040000A0 */
		/* 0x000045C0 08                 */ IL_001c: ldloc.2
		/* 0x000045C1 07                 */ IL_001d: ldloc.1
		/* 0x000045C2 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x000045C7 0A                 */ IL_0023: stloc.0
		/* 0x000045C8 06                 */ IL_0024: ldloc.0
		/* 0x000045C9 07                 */ IL_0025: ldloc.1
		/* 0x000045CA 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000045CC 2A                 */ IL_0028: ret
	} // end of method UsrPropPage::add_DefaultButtonClick

	.method /* 060000F3 */ public hidebysig specialname 
		instance void remove_DefaultButtonClick (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000070 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x45dc
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x000045DC 02                 */ IL_0000: ldarg.0
		/* 0x000045DD 7BA0000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::DefaultButtonClick /* 040000A0 */
		/* 0x000045E2 0A                 */ IL_0006: stloc.0
		/* 0x000045E3 06                 */ IL_0007: ldloc.0
		/* 0x000045E4 0B                 */ IL_0008: stloc.1
		/* 0x000045E5 07                 */ IL_0009: ldloc.1
		/* 0x000045E6 03                 */ IL_000a: ldarg.1
		/* 0x000045E7 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x000045EC 7430000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000030 */
		/* 0x000045F1 0C                 */ IL_0015: stloc.2
		/* 0x000045F2 02                 */ IL_0016: ldarg.0
		/* 0x000045F3 7CA0000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::DefaultButtonClick /* 040000A0 */
		/* 0x000045F8 08                 */ IL_001c: ldloc.2
		/* 0x000045F9 07                 */ IL_001d: ldloc.1
		/* 0x000045FA 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x000045FF 0A                 */ IL_0023: stloc.0
		/* 0x00004600 06                 */ IL_0024: ldloc.0
		/* 0x00004601 07                 */ IL_0025: ldloc.1
		/* 0x00004602 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00004604 2A                 */ IL_0028: ret
	} // end of method UsrPropPage::remove_DefaultButtonClick

	.method /* 060000F4 */ private hidebysig 
		instance void OnDefaultButtonClick () cil managed 
	{
		// Method begins at RVA 0x4611
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00004611 02                 */ IL_0000: ldarg.0
		/* 0x00004612 7BA0000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::DefaultButtonClick /* 040000A0 */
		/* 0x00004617 2C11               */ IL_0006: brfalse.s IL_0019
		/* 0x00004619 02                 */ IL_0008: ldarg.0
		/* 0x0000461A 7BA0000004         */ IL_0009: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::DefaultButtonClick /* 040000A0 */
		/* 0x0000461F 02                 */ IL_000e: ldarg.0
		/* 0x00004620 739800000A         */ IL_000f: newobj instance void [mscorlib]System.EventArgs::.ctor() /* 0A000098 */
		/* 0x00004625 6F9900000A         */ IL_0014: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs) /* 0A000099 */
		/* 0x0000462A 2A                 */ IL_0019: ret
	} // end of method UsrPropPage::OnDefaultButtonClick

	.method /* 060000F5 */ public hidebysig specialname 
		instance void add_CancelButtonClick (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000071 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x462c
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x0000462C 02                 */ IL_0000: ldarg.0
		/* 0x0000462D 7BA1000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::CancelButtonClick /* 040000A1 */
		/* 0x00004632 0A                 */ IL_0006: stloc.0
		/* 0x00004633 06                 */ IL_0007: ldloc.0
		/* 0x00004634 0B                 */ IL_0008: stloc.1
		/* 0x00004635 07                 */ IL_0009: ldloc.1
		/* 0x00004636 03                 */ IL_000a: ldarg.1
		/* 0x00004637 282300000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x0000463C 7430000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000030 */
		/* 0x00004641 0C                 */ IL_0015: stloc.2
		/* 0x00004642 02                 */ IL_0016: ldarg.0
		/* 0x00004643 7CA1000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::CancelButtonClick /* 040000A1 */
		/* 0x00004648 08                 */ IL_001c: ldloc.2
		/* 0x00004649 07                 */ IL_001d: ldloc.1
		/* 0x0000464A 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x0000464F 0A                 */ IL_0023: stloc.0
		/* 0x00004650 06                 */ IL_0024: ldloc.0
		/* 0x00004651 07                 */ IL_0025: ldloc.1
		/* 0x00004652 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00004654 2A                 */ IL_0028: ret
	} // end of method UsrPropPage::add_CancelButtonClick

	.method /* 060000F6 */ public hidebysig specialname 
		instance void remove_CancelButtonClick (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000072 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4664
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00004664 02                 */ IL_0000: ldarg.0
		/* 0x00004665 7BA1000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::CancelButtonClick /* 040000A1 */
		/* 0x0000466A 0A                 */ IL_0006: stloc.0
		/* 0x0000466B 06                 */ IL_0007: ldloc.0
		/* 0x0000466C 0B                 */ IL_0008: stloc.1
		/* 0x0000466D 07                 */ IL_0009: ldloc.1
		/* 0x0000466E 03                 */ IL_000a: ldarg.1
		/* 0x0000466F 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x00004674 7430000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000030 */
		/* 0x00004679 0C                 */ IL_0015: stloc.2
		/* 0x0000467A 02                 */ IL_0016: ldarg.0
		/* 0x0000467B 7CA1000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::CancelButtonClick /* 040000A1 */
		/* 0x00004680 08                 */ IL_001c: ldloc.2
		/* 0x00004681 07                 */ IL_001d: ldloc.1
		/* 0x00004682 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x00004687 0A                 */ IL_0023: stloc.0
		/* 0x00004688 06                 */ IL_0024: ldloc.0
		/* 0x00004689 07                 */ IL_0025: ldloc.1
		/* 0x0000468A 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x0000468C 2A                 */ IL_0028: ret
	} // end of method UsrPropPage::remove_CancelButtonClick

	.method /* 060000F7 */ private hidebysig 
		instance void OnCancelButtonClick () cil managed 
	{
		// Method begins at RVA 0x4699
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00004699 02                 */ IL_0000: ldarg.0
		/* 0x0000469A 7BA1000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::CancelButtonClick /* 040000A1 */
		/* 0x0000469F 2C11               */ IL_0006: brfalse.s IL_0019
		/* 0x000046A1 02                 */ IL_0008: ldarg.0
		/* 0x000046A2 7BA1000004         */ IL_0009: ldfld class [mscorlib]System.EventHandler AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::CancelButtonClick /* 040000A1 */
		/* 0x000046A7 02                 */ IL_000e: ldarg.0
		/* 0x000046A8 739800000A         */ IL_000f: newobj instance void [mscorlib]System.EventArgs::.ctor() /* 0A000098 */
		/* 0x000046AD 6F9900000A         */ IL_0014: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs) /* 0A000099 */
		/* 0x000046B2 2A                 */ IL_0019: ret
	} // end of method UsrPropPage::OnCancelButtonClick

	.method /* 060000F8 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000073 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000074 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x46b4
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [System]System.Uri
		)

		/* 0x000046B4 02                 */ IL_0000: ldarg.0
		/* 0x000046B5 7BA8000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::_contentLoaded /* 040000A8 */
		/* 0x000046BA 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x000046BC 2A                 */ IL_0008: ret
		/* 0x000046BD 02                 */ IL_0009: ldarg.0
		/* 0x000046BE 17                 */ IL_000a: ldc.i4.1
		/* 0x000046BF 7DA8000004         */ IL_000b: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::_contentLoaded /* 040000A8 */
		/* 0x000046C4 72E9080070         */ IL_0010: ldstr "/AspenTech.AspenPlus.WpfPropertyControl;component/controls/usrproppage.xaml" /* 700008E9 */
		/* 0x000046C9 18                 */ IL_0015: ldc.i4.2
		/* 0x000046CA 731C00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00001C */
		/* 0x000046CF 0A                 */ IL_001b: stloc.0
		/* 0x000046D0 02                 */ IL_001c: ldarg.0
		/* 0x000046D1 06                 */ IL_001d: ldloc.0
		/* 0x000046D2 285500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000055 */
		/* 0x000046D7 2A                 */ IL_0023: ret
	} // end of method UsrPropPage::InitializeComponent

	.method /* 060000F9 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000075 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000076 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000077 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x46e4
		// Header size: 12
		// Code size: 243 (0xf3)
		.maxstack 3

		/* 0x000046E4 03                 */ IL_0000: ldarg.1
		/* 0x000046E5 17                 */ IL_0001: ldc.i4.1
		/* 0x000046E6 59                 */ IL_0002: sub
		/* 0x000046E7 4507000000         */ IL_0003: switch (
		/*              05000000         */                  IL_0029,
		/*              1D000000         */                  IL_0041,
		/*              41000000         */                  IL_0065,
		/*              4E000000         */                  IL_0072,
		/*              5B000000         */                  IL_007f,
		/*              7F000000         */                  IL_00a3,
		/*              A3000000         */                  IL_00c7)
		/* 0x00004708 38C2000000         */ IL_0024: br IL_00eb
		/* 0x0000470D 04                 */ IL_0029: ldarg.2
		/* 0x0000470E 7414000002         */ IL_002a: castclass AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage /* 02000014 */
		/* 0x00004713 02                 */ IL_002f: ldarg.0
		/* 0x00004714 FE06E8000006       */ IL_0030: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::UserControl_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000E8 */
		/* 0x0000471A 734600000A         */ IL_0036: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x0000471F 6F4700000A         */ IL_003b: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000047 */
		/* 0x00004724 2A                 */ IL_0040: ret
		/* 0x00004725 02                 */ IL_0041: ldarg.0
		/* 0x00004726 04                 */ IL_0042: ldarg.2
		/* 0x00004727 7431000001         */ IL_0043: castclass [PresentationFramework]System.Windows.Controls.ListBox /* 01000031 */
		/* 0x0000472C 7DA2000004         */ IL_0048: stfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004731 02                 */ IL_004d: ldarg.0
		/* 0x00004732 7BA2000004         */ IL_004e: ldfld class [PresentationFramework]System.Windows.Controls.ListBox AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList /* 040000A2 */
		/* 0x00004737 02                 */ IL_0053: ldarg.0
		/* 0x00004738 FE06EE000006       */ IL_0054: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::PropertyPageList_SelectionChanged(object, class [PresentationFramework]System.Windows.Controls.SelectionChangedEventArgs) /* 060000EE */
		/* 0x0000473E 739A00000A         */ IL_005a: newobj instance void [PresentationFramework]System.Windows.Controls.SelectionChangedEventHandler::.ctor(object, native int) /* 0A00009A */
		/* 0x00004743 6F9B00000A         */ IL_005f: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Selector::add_SelectionChanged(class [PresentationFramework]System.Windows.Controls.SelectionChangedEventHandler) /* 0A00009B */
		/* 0x00004748 2A                 */ IL_0064: ret
		/* 0x00004749 02                 */ IL_0065: ldarg.0
		/* 0x0000474A 04                 */ IL_0066: ldarg.2
		/* 0x0000474B 7432000001         */ IL_0067: castclass [PresentationFramework]System.Windows.Controls.GridSplitter /* 01000032 */
		/* 0x00004750 7DA3000004         */ IL_006c: stfld class [PresentationFramework]System.Windows.Controls.GridSplitter AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::gridSplitter1 /* 040000A3 */
		/* 0x00004755 2A                 */ IL_0071: ret
		/* 0x00004756 02                 */ IL_0072: ldarg.0
		/* 0x00004757 04                 */ IL_0073: ldarg.2
		/* 0x00004758 7420000001         */ IL_0074: castclass [PresentationFramework]System.Windows.Controls.UserControl /* 01000020 */
		/* 0x0000475D 7DA4000004         */ IL_0079: stfld class [PresentationFramework]System.Windows.Controls.UserControl AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::rightViewPanel /* 040000A4 */
		/* 0x00004762 2A                 */ IL_007e: ret
		/* 0x00004763 02                 */ IL_007f: ldarg.0
		/* 0x00004764 04                 */ IL_0080: ldarg.2
		/* 0x00004765 742E000001         */ IL_0081: castclass [PresentationFramework]System.Windows.Controls.Button /* 0100002E */
		/* 0x0000476A 7DA5000004         */ IL_0086: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnOk /* 040000A5 */
		/* 0x0000476F 02                 */ IL_008b: ldarg.0
		/* 0x00004770 7BA5000004         */ IL_008c: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnOk /* 040000A5 */
		/* 0x00004775 02                 */ IL_0091: ldarg.0
		/* 0x00004776 FE06EB000006       */ IL_0092: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnOk_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000EB */
		/* 0x0000477C 734600000A         */ IL_0098: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x00004781 6F6000000A         */ IL_009d: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000060 */
		/* 0x00004786 2A                 */ IL_00a2: ret
		/* 0x00004787 02                 */ IL_00a3: ldarg.0
		/* 0x00004788 04                 */ IL_00a4: ldarg.2
		/* 0x00004789 742E000001         */ IL_00a5: castclass [PresentationFramework]System.Windows.Controls.Button /* 0100002E */
		/* 0x0000478E 7DA6000004         */ IL_00aa: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnDefault /* 040000A6 */
		/* 0x00004793 02                 */ IL_00af: ldarg.0
		/* 0x00004794 7BA6000004         */ IL_00b0: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnDefault /* 040000A6 */
		/* 0x00004799 02                 */ IL_00b5: ldarg.0
		/* 0x0000479A FE06EC000006       */ IL_00b6: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnDefault_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000EC */
		/* 0x000047A0 734600000A         */ IL_00bc: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x000047A5 6F6000000A         */ IL_00c1: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000060 */
		/* 0x000047AA 2A                 */ IL_00c6: ret
		/* 0x000047AB 02                 */ IL_00c7: ldarg.0
		/* 0x000047AC 04                 */ IL_00c8: ldarg.2
		/* 0x000047AD 742E000001         */ IL_00c9: castclass [PresentationFramework]System.Windows.Controls.Button /* 0100002E */
		/* 0x000047B2 7DA7000004         */ IL_00ce: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnCancel /* 040000A7 */
		/* 0x000047B7 02                 */ IL_00d3: ldarg.0
		/* 0x000047B8 7BA7000004         */ IL_00d4: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnCancel /* 040000A7 */
		/* 0x000047BD 02                 */ IL_00d9: ldarg.0
		/* 0x000047BE FE06ED000006       */ IL_00da: ldftn instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::btnCancel_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000ED */
		/* 0x000047C4 734600000A         */ IL_00e0: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000046 */
		/* 0x000047C9 6F6000000A         */ IL_00e5: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000060 */
		/* 0x000047CE 2A                 */ IL_00ea: ret
		/* 0x000047CF 02                 */ IL_00eb: ldarg.0
		/* 0x000047D0 17                 */ IL_00ec: ldc.i4.1
		/* 0x000047D1 7DA8000004         */ IL_00ed: stfld bool AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::_contentLoaded /* 040000A8 */
		/* 0x000047D6 2A                 */ IL_00f2: ret
	} // end of method UsrPropPage::System.Windows.Markup.IComponentConnector.Connect

	// Events
	.event /* 14000006 */ [mscorlib]System.EventHandler OKButtonClick
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::add_OKButtonClick(class [mscorlib]System.EventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::remove_OKButtonClick(class [mscorlib]System.EventHandler)
	}

	.event /* 14000007 */ [mscorlib]System.EventHandler DefaultButtonClick
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::add_DefaultButtonClick(class [mscorlib]System.EventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::remove_DefaultButtonClick(class [mscorlib]System.EventHandler)
	}

	.event /* 14000008 */ [mscorlib]System.EventHandler CancelButtonClick
	{
		.addon instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::add_CancelButtonClick(class [mscorlib]System.EventHandler)
		.removeon instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::remove_CancelButtonClick(class [mscorlib]System.EventHandler)
	}


	// Properties
	.property /* 17000060 */ instance valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings AdjustSettings()
	{
		.get instance valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_AdjustSettings()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_AdjustSettings(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.Settings)
	}
	.property /* 17000061 */ instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage PropPage()
	{
		.get instance class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropPage()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_PropPage(class AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PropPage)
	}
	.property /* 17000062 */ instance valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum PropStartPage()
	{
		.get instance valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::get_PropStartPage()
		.set instance void AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage::set_PropStartPage(valuetype AspenTech.AspenPlus.WpfPropertyControl.DataHelper.PageEnum)
	}

} // end of class AspenTech.AspenPlus.WpfPropertyControl.Controls.UsrPropPage

