.module AspenTech.Visualisation.Controls.Assistant.W1.dll
// MVID: {E9B8BA0F-58AC-4331-9F93-6DB6CC9292F3}
.imagebase 0x00400000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi abstract sealed beforefieldinit AspenTech.Visualisation.Controls.Assistant.Aspen
	extends [mscorlib]System.Object
{
	// Nested Types
	.class /* 02000003 */ nested public auto ansi sealed VersionSource
		extends [mscorlib]System.Enum
	{
		// Fields
		.field /* 04000002 */ public specialname rtspecialname int32 value__
		.field /* 04000003 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource ExecutingAssembly = int32(0)
		.field /* 04000004 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource CallingAssembly = int32(1)
		.field /* 04000005 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource EntryAssembly = int32(2)

	} // end of class VersionSource


	// Fields
	.field /* 04000001 */ private static class [mscorlib]System.Func`2<char, bool> 'CS$<>9__CachedAnonymousMethodDelegate1'
	.custom /* 0C000001 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000001 */ private hidebysig static 
		class [mscorlib]System.Reflection.Assembly Assembly (
			valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource source
		) cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 12
		// Code size: 51 (0x33)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource
		)

		/* 0x00002050 02                 */ IL_0000: ldarg.0
		/* 0x00002051 0A                 */ IL_0001: stloc.0
		/* 0x00002052 06                 */ IL_0002: ldloc.0
		/* 0x00002053 4503000000         */ IL_0003: switch (
		/*              0E000000         */                  IL_0022,
		/*              02000000         */                  IL_0016,
		/*              08000000         */                  IL_001c)
		/* 0x00002064 2B12               */ IL_0014: br.s IL_0028
		/* 0x00002066 281700000A         */ IL_0016: call class [mscorlib]System.Reflection.Assembly [mscorlib]System.Reflection.Assembly::GetCallingAssembly() /* 0A000017 */
		/* 0x0000206B 2A                 */ IL_001b: ret
		/* 0x0000206C 281800000A         */ IL_001c: call class [mscorlib]System.Reflection.Assembly [mscorlib]System.Reflection.Assembly::GetEntryAssembly() /* 0A000018 */
		/* 0x00002071 2A                 */ IL_0021: ret
		/* 0x00002072 281900000A         */ IL_0022: call class [mscorlib]System.Reflection.Assembly [mscorlib]System.Reflection.Assembly::GetExecutingAssembly() /* 0A000019 */
		/* 0x00002077 2A                 */ IL_0027: ret
		/* 0x00002078 7201000070         */ IL_0028: ldstr "source" /* 70000001 */
		/* 0x0000207D 731A00000A         */ IL_002d: newobj instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string) /* 0A00001A */
		/* 0x00002082 7A                 */ IL_0032: throw
	} // end of method Aspen::Assembly

	.method /* 06000002 */ public hidebysig static 
		void About (
			valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource source
		) cil managed 
	{
		// Method begins at RVA 0x2098
		// Header size: 12
		// Code size: 326 (0x146)
		.maxstack 4
		.locals /* 11000002 */ init (
			[0] class ASPENABOUTBOXLib.AspenAboutBox,
			[1] class [mscorlib]System.Reflection.Assembly,
			[2] class [System]System.Diagnostics.FileVersionInfo,
			[3] string,
			[4] string,
			[5] bool,
			[6] char,
			[7] int16,
			[8] string,
			[9] int32,
			[10] string,
			[11] int32
		)

		/* 0x00002098 720F000070         */ IL_0000: ldstr "55E3D11A-F9BB-4C89-B8B8-1344CB67F182" /* 7000000F */
		/* 0x0000209D 731C00000A         */ IL_0005: newobj instance void [mscorlib]System.Guid::.ctor(string) /* 0A00001C */
		/* 0x000020A2 281D00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromCLSID(valuetype [mscorlib]System.Guid) /* 0A00001D */
		/* 0x000020A7 281E00000A         */ IL_000f: call object [mscorlib]System.Activator::CreateInstance(class [mscorlib]System.Type) /* 0A00001E */
		/* 0x000020AC 7426000002         */ IL_0014: castclass ASPENABOUTBOXLib.AspenAboutBox /* 02000026 */
		/* 0x000020B1 0A                 */ IL_0019: stloc.0
		/* 0x000020B2 02                 */ IL_001a: ldarg.0
		/* 0x000020B3 2801000006         */ IL_001b: call class [mscorlib]System.Reflection.Assembly AspenTech.Visualisation.Controls.Assistant.Aspen::Assembly(valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource) /* 06000001 */
		/* 0x000020B8 0B                 */ IL_0020: stloc.1
		/* 0x000020B9 07                 */ IL_0021: ldloc.1
		/* 0x000020BA 6F1F00000A         */ IL_0022: callvirt instance string [mscorlib]System.Reflection.Assembly::get_Location() /* 0A00001F */
		/* 0x000020BF 282000000A         */ IL_0027: call class [System]System.Diagnostics.FileVersionInfo [System]System.Diagnostics.FileVersionInfo::GetVersionInfo(string) /* 0A000020 */
		/* 0x000020C4 0C                 */ IL_002c: stloc.2
		/* 0x000020C5 06                 */ IL_002d: ldloc.0
		/* 0x000020C6 08                 */ IL_002e: ldloc.2
		/* 0x000020C7 6F2100000A         */ IL_002f: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_LegalCopyright() /* 0A000021 */
		/* 0x000020CC 6FE6000006         */ IL_0034: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::set_AppCopyright(string) /* 060000E6 */
		/* 0x000020D1 06                 */ IL_0039: ldloc.0
		/* 0x000020D2 08                 */ IL_003a: ldloc.2
		/* 0x000020D3 6F2300000A         */ IL_003b: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_FileDescription() /* 0A000023 */
		/* 0x000020D8 6FE4000006         */ IL_0040: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::set_AppName(string) /* 060000E4 */
		/* 0x000020DD 06                 */ IL_0045: ldloc.0
		/* 0x000020DE 08                 */ IL_0046: ldloc.2
		/* 0x000020DF 6F2500000A         */ IL_0047: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_FileVersion() /* 0A000025 */
		/* 0x000020E4 6FEC000006         */ IL_004c: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::set_AppVersion(string) /* 060000EC */
		/* 0x000020E9 08                 */ IL_0051: ldloc.2
		/* 0x000020EA 6F2100000A         */ IL_0052: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_LegalCopyright() /* 0A000021 */
		/* 0x000020EF 6F2700000A         */ IL_0057: callvirt instance string [mscorlib]System.String::Trim() /* 0A000027 */
		/* 0x000020F4 0D                 */ IL_005c: stloc.3
		/* 0x000020F5 7E2800000A         */ IL_005d: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x000020FA 1304               */ IL_0062: stloc.s 4
		/* 0x000020FC 17                 */ IL_0064: ldc.i4.1
		/* 0x000020FD 1305               */ IL_0065: stloc.s 5
		/* 0x000020FF 09                 */ IL_0067: ldloc.3
		/* 0x00002100 130A               */ IL_0068: stloc.s 10
		/* 0x00002102 16                 */ IL_006a: ldc.i4.0
		/* 0x00002103 130B               */ IL_006b: stloc.s 11
		/* 0x00002105 2B74               */ IL_006d: br.s IL_00e3
		/* 0x00002107 110A               */ IL_006f: ldloc.s 10
		/* 0x00002109 110B               */ IL_0071: ldloc.s 11
		/* 0x0000210B 6F2900000A         */ IL_0073: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00002110 1306               */ IL_0078: stloc.s 6
		/* 0x00002112 1106               */ IL_007a: ldloc.s 6
		/* 0x00002114 282A00000A         */ IL_007c: call bool [mscorlib]System.Char::IsDigit(char) /* 0A00002A */
		/* 0x00002119 2C12               */ IL_0081: brfalse.s IL_0095
		/* 0x0000211B 1104               */ IL_0083: ldloc.s 4
		/* 0x0000211D 1106               */ IL_0085: ldloc.s 6
		/* 0x0000211F 8C46000001         */ IL_0087: box [mscorlib]System.Char /* 01000046 */
		/* 0x00002124 282B00000A         */ IL_008c: call string [mscorlib]System.String::Concat(object, object) /* 0A00002B */
		/* 0x00002129 1304               */ IL_0091: stloc.s 4
		/* 0x0000212B 2B48               */ IL_0093: br.s IL_00dd
		/* 0x0000212D 1104               */ IL_0095: ldloc.s 4
		/* 0x0000212F 282C00000A         */ IL_0097: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00002134 2D38               */ IL_009c: brtrue.s IL_00d6
		/* 0x00002136 1104               */ IL_009e: ldloc.s 4
		/* 0x00002138 1D                 */ IL_00a0: ldc.i4.7
		/* 0x00002139 282D00000A         */ IL_00a1: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x0000213E 282E00000A         */ IL_00a6: call int16 [mscorlib]System.Int16::Parse(string, valuetype [mscorlib]System.Globalization.NumberStyles, class [mscorlib]System.IFormatProvider) /* 0A00002E */
		/* 0x00002143 1307               */ IL_00ab: stloc.s 7
		/* 0x00002145 1107               */ IL_00ad: ldloc.s 7
		/* 0x00002147 206C070000         */ IL_00af: ldc.i4 1900
		/* 0x0000214C 3120               */ IL_00b4: ble.s IL_00d6
		/* 0x0000214E 1107               */ IL_00b6: ldloc.s 7
		/* 0x00002150 2098080000         */ IL_00b8: ldc.i4 2200
		/* 0x00002155 2F17               */ IL_00bd: bge.s IL_00d6
		/* 0x00002157 1105               */ IL_00bf: ldloc.s 5
		/* 0x00002159 2C0B               */ IL_00c1: brfalse.s IL_00ce
		/* 0x0000215B 06                 */ IL_00c3: ldloc.0
		/* 0x0000215C 1104               */ IL_00c4: ldloc.s 4
		/* 0x0000215E 6FE8000006         */ IL_00c6: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::set_BeginCopyDate(string) /* 060000E8 */
		/* 0x00002163 16                 */ IL_00cb: ldc.i4.0
		/* 0x00002164 1305               */ IL_00cc: stloc.s 5
		/* 0x00002166 06                 */ IL_00ce: ldloc.0
		/* 0x00002167 1104               */ IL_00cf: ldloc.s 4
		/* 0x00002169 6FEA000006         */ IL_00d1: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::set_EndCopyDate(string) /* 060000EA */
		/* 0x0000216E 7E2800000A         */ IL_00d6: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00002173 1304               */ IL_00db: stloc.s 4
		/* 0x00002175 110B               */ IL_00dd: ldloc.s 11
		/* 0x00002177 17                 */ IL_00df: ldc.i4.1
		/* 0x00002178 58                 */ IL_00e0: add
		/* 0x00002179 130B               */ IL_00e1: stloc.s 11
		/* 0x0000217B 110B               */ IL_00e3: ldloc.s 11
		/* 0x0000217D 110A               */ IL_00e5: ldloc.s 10
		/* 0x0000217F 6F3100000A         */ IL_00e7: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00002184 3281               */ IL_00ec: blt.s IL_006f
		/* 0x00002186 08                 */ IL_00ee: ldloc.2
		/* 0x00002187 6F3200000A         */ IL_00ef: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_ProductVersion() /* 0A000032 */
		/* 0x0000218C 1308               */ IL_00f4: stloc.s 8
		/* 0x0000218E 1108               */ IL_00f6: ldloc.s 8
		/* 0x00002190 7E01000004         */ IL_00f8: ldsfld class [mscorlib]System.Func`2<char, bool> AspenTech.Visualisation.Controls.Assistant.Aspen::'CS$<>9__CachedAnonymousMethodDelegate1' /* 04000001 */
		/* 0x00002195 2D11               */ IL_00fd: brtrue.s IL_0110
		/* 0x00002197 14                 */ IL_00ff: ldnull
		/* 0x00002198 FE0604000006       */ IL_0100: ldftn bool AspenTech.Visualisation.Controls.Assistant.Aspen::'<About>b__0'(char) /* 06000004 */
		/* 0x0000219E 733300000A         */ IL_0106: newobj instance void class [mscorlib]System.Func`2<char, bool>::.ctor(object, native int) /* 0A000033 */
		/* 0x000021A3 8001000004         */ IL_010b: stsfld class [mscorlib]System.Func`2<char, bool> AspenTech.Visualisation.Controls.Assistant.Aspen::'CS$<>9__CachedAnonymousMethodDelegate1' /* 04000001 */
		/* 0x000021A8 7E01000004         */ IL_0110: ldsfld class [mscorlib]System.Func`2<char, bool> AspenTech.Visualisation.Controls.Assistant.Aspen::'CS$<>9__CachedAnonymousMethodDelegate1' /* 04000001 */
		/* 0x000021AD 280100002B         */ IL_0115: call int32 [System.Core]System.Linq.Enumerable::Count<char>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000001 */
		/* 0x000021B2 1309               */ IL_011a: stloc.s 9
		/* 0x000021B4 2B14               */ IL_011c: br.s IL_0132
		/* 0x000021B6 1108               */ IL_011e: ldloc.s 8
		/* 0x000021B8 7259000070         */ IL_0120: ldstr ".0" /* 70000059 */
		/* 0x000021BD 283500000A         */ IL_0125: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x000021C2 1308               */ IL_012a: stloc.s 8
		/* 0x000021C4 1109               */ IL_012c: ldloc.s 9
		/* 0x000021C6 17                 */ IL_012e: ldc.i4.1
		/* 0x000021C7 58                 */ IL_012f: add
		/* 0x000021C8 1309               */ IL_0130: stloc.s 9
		/* 0x000021CA 1109               */ IL_0132: ldloc.s 9
		/* 0x000021CC 19                 */ IL_0134: ldc.i4.3
		/* 0x000021CD 32E7               */ IL_0135: blt.s IL_011e
		/* 0x000021CF 06                 */ IL_0137: ldloc.0
		/* 0x000021D0 1108               */ IL_0138: ldloc.s 8
		/* 0x000021D2 6FEE000006         */ IL_013a: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::set_ExternalVersion(string) /* 060000EE */
		/* 0x000021D7 06                 */ IL_013f: ldloc.0
		/* 0x000021D8 6FE2000006         */ IL_0140: callvirt instance void ASPENABOUTBOXLib.IAspenAboutBox::Show() /* 060000E2 */
		/* 0x000021DD 2A                 */ IL_0145: ret
	} // end of method Aspen::About

	.method /* 06000003 */ public hidebysig static 
		void Splash (
			valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource source
		) cil managed 
	{
		// Method begins at RVA 0x21ec
		// Header size: 12
		// Code size: 379 (0x17b)
		.maxstack 7
		.locals /* 11000003 */ init (
			[0] class ASPENSPLASHLib.SplashWindow,
			[1] class [mscorlib]System.Reflection.Assembly,
			[2] class [System]System.Diagnostics.FileVersionInfo,
			[3] string,
			[4] int16,
			[5] int16,
			[6] string,
			[7] char,
			[8] int16,
			[9] class [mscorlib]System.Collections.Generic.List`1<string>,
			[10] string,
			[11] int32,
			[12] valuetype [mscorlib]System.DateTime,
			[13] char[]
		)

		/* 0x000021EC 725F000070         */ IL_0000: ldstr "5EC5EB43-13E3-11D3-840D-000000000000" /* 7000005F */
		/* 0x000021F1 731C00000A         */ IL_0005: newobj instance void [mscorlib]System.Guid::.ctor(string) /* 0A00001C */
		/* 0x000021F6 281D00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromCLSID(valuetype [mscorlib]System.Guid) /* 0A00001D */
		/* 0x000021FB 281E00000A         */ IL_000f: call object [mscorlib]System.Activator::CreateInstance(class [mscorlib]System.Type) /* 0A00001E */
		/* 0x00002200 7428000002         */ IL_0014: castclass ASPENSPLASHLib.SplashWindow /* 02000028 */
		/* 0x00002205 0A                 */ IL_0019: stloc.0
		/* 0x00002206 02                 */ IL_001a: ldarg.0
		/* 0x00002207 2801000006         */ IL_001b: call class [mscorlib]System.Reflection.Assembly AspenTech.Visualisation.Controls.Assistant.Aspen::Assembly(valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource) /* 06000001 */
		/* 0x0000220C 0B                 */ IL_0020: stloc.1
		/* 0x0000220D 07                 */ IL_0021: ldloc.1
		/* 0x0000220E 6F1F00000A         */ IL_0022: callvirt instance string [mscorlib]System.Reflection.Assembly::get_Location() /* 0A00001F */
		/* 0x00002213 282000000A         */ IL_0027: call class [System]System.Diagnostics.FileVersionInfo [System]System.Diagnostics.FileVersionInfo::GetVersionInfo(string) /* 0A000020 */
		/* 0x00002218 0C                 */ IL_002c: stloc.2
		/* 0x00002219 08                 */ IL_002d: ldloc.2
		/* 0x0000221A 6F3200000A         */ IL_002e: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_ProductVersion() /* 0A000032 */
		/* 0x0000221F 26                 */ IL_0033: pop
		/* 0x00002220 08                 */ IL_0034: ldloc.2
		/* 0x00002221 6F2100000A         */ IL_0035: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_LegalCopyright() /* 0A000021 */
		/* 0x00002226 6F2700000A         */ IL_003a: callvirt instance string [mscorlib]System.String::Trim() /* 0A000027 */
		/* 0x0000222B 0D                 */ IL_003f: stloc.3
		/* 0x0000222C 16                 */ IL_0040: ldc.i4.0
		/* 0x0000222D 1304               */ IL_0041: stloc.s 4
		/* 0x0000222F 16                 */ IL_0043: ldc.i4.0
		/* 0x00002230 1305               */ IL_0044: stloc.s 5
		/* 0x00002232 7E2800000A         */ IL_0046: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00002237 1306               */ IL_004b: stloc.s 6
		/* 0x00002239 09                 */ IL_004d: ldloc.3
		/* 0x0000223A 130A               */ IL_004e: stloc.s 10
		/* 0x0000223C 16                 */ IL_0050: ldc.i4.0
		/* 0x0000223D 130B               */ IL_0051: stloc.s 11
		/* 0x0000223F 2B65               */ IL_0053: br.s IL_00ba
		/* 0x00002241 110A               */ IL_0055: ldloc.s 10
		/* 0x00002243 110B               */ IL_0057: ldloc.s 11
		/* 0x00002245 6F2900000A         */ IL_0059: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x0000224A 1307               */ IL_005e: stloc.s 7
		/* 0x0000224C 1107               */ IL_0060: ldloc.s 7
		/* 0x0000224E 282A00000A         */ IL_0062: call bool [mscorlib]System.Char::IsDigit(char) /* 0A00002A */
		/* 0x00002253 2C12               */ IL_0067: brfalse.s IL_007b
		/* 0x00002255 1106               */ IL_0069: ldloc.s 6
		/* 0x00002257 1107               */ IL_006b: ldloc.s 7
		/* 0x00002259 8C46000001         */ IL_006d: box [mscorlib]System.Char /* 01000046 */
		/* 0x0000225E 282B00000A         */ IL_0072: call string [mscorlib]System.String::Concat(object, object) /* 0A00002B */
		/* 0x00002263 1306               */ IL_0077: stloc.s 6
		/* 0x00002265 2B39               */ IL_0079: br.s IL_00b4
		/* 0x00002267 1106               */ IL_007b: ldloc.s 6
		/* 0x00002269 282C00000A         */ IL_007d: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x0000226E 2D29               */ IL_0082: brtrue.s IL_00ad
		/* 0x00002270 1106               */ IL_0084: ldloc.s 6
		/* 0x00002272 1D                 */ IL_0086: ldc.i4.7
		/* 0x00002273 282D00000A         */ IL_0087: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x00002278 282E00000A         */ IL_008c: call int16 [mscorlib]System.Int16::Parse(string, valuetype [mscorlib]System.Globalization.NumberStyles, class [mscorlib]System.IFormatProvider) /* 0A00002E */
		/* 0x0000227D 1308               */ IL_0091: stloc.s 8
		/* 0x0000227F 1108               */ IL_0093: ldloc.s 8
		/* 0x00002281 206C070000         */ IL_0095: ldc.i4 1900
		/* 0x00002286 3111               */ IL_009a: ble.s IL_00ad
		/* 0x00002288 1108               */ IL_009c: ldloc.s 8
		/* 0x0000228A 2098080000         */ IL_009e: ldc.i4 2200
		/* 0x0000228F 2F08               */ IL_00a3: bge.s IL_00ad
		/* 0x00002291 1105               */ IL_00a5: ldloc.s 5
		/* 0x00002293 1304               */ IL_00a7: stloc.s 4
		/* 0x00002295 1108               */ IL_00a9: ldloc.s 8
		/* 0x00002297 1305               */ IL_00ab: stloc.s 5
		/* 0x00002299 7E2800000A         */ IL_00ad: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x0000229E 1306               */ IL_00b2: stloc.s 6
		/* 0x000022A0 110B               */ IL_00b4: ldloc.s 11
		/* 0x000022A2 17                 */ IL_00b6: ldc.i4.1
		/* 0x000022A3 58                 */ IL_00b7: add
		/* 0x000022A4 130B               */ IL_00b8: stloc.s 11
		/* 0x000022A6 110B               */ IL_00ba: ldloc.s 11
		/* 0x000022A8 110A               */ IL_00bc: ldloc.s 10
		/* 0x000022AA 6F3100000A         */ IL_00be: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x000022AF 3290               */ IL_00c3: blt.s IL_0055
		/* 0x000022B1 1104               */ IL_00c5: ldloc.s 4
		/* 0x000022B3 2D04               */ IL_00c7: brtrue.s IL_00cd
		/* 0x000022B5 1105               */ IL_00c9: ldloc.s 5
		/* 0x000022B7 1304               */ IL_00cb: stloc.s 4
		/* 0x000022B9 1104               */ IL_00cd: ldloc.s 4
		/* 0x000022BB 2D14               */ IL_00cf: brtrue.s IL_00e5
		/* 0x000022BD 283800000A         */ IL_00d1: call valuetype [mscorlib]System.DateTime [mscorlib]System.DateTime::get_Now() /* 0A000038 */
		/* 0x000022C2 130C               */ IL_00d6: stloc.s 12
		/* 0x000022C4 120C               */ IL_00d8: ldloca.s 12
		/* 0x000022C6 283900000A         */ IL_00da: call instance int32 [mscorlib]System.DateTime::get_Year() /* 0A000039 */
		/* 0x000022CB 68                 */ IL_00df: conv.i2
		/* 0x000022CC 25                 */ IL_00e0: dup
		/* 0x000022CD 1305               */ IL_00e1: stloc.s 5
		/* 0x000022CF 1304               */ IL_00e3: stloc.s 4
		/* 0x000022D1 08                 */ IL_00e5: ldloc.2
		/* 0x000022D2 6F3200000A         */ IL_00e6: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_ProductVersion() /* 0A000032 */
		/* 0x000022D7 17                 */ IL_00eb: ldc.i4.1
		/* 0x000022D8 8D46000001         */ IL_00ec: newarr [mscorlib]System.Char /* 01000046 */
		/* 0x000022DD 130D               */ IL_00f1: stloc.s 13
		/* 0x000022DF 110D               */ IL_00f3: ldloc.s 13
		/* 0x000022E1 16                 */ IL_00f5: ldc.i4.0
		/* 0x000022E2 1F2E               */ IL_00f6: ldc.i4.s 46
		/* 0x000022E4 9D                 */ IL_00f8: stelem.i2
		/* 0x000022E5 110D               */ IL_00f9: ldloc.s 13
		/* 0x000022E7 6F3A00000A         */ IL_00fb: callvirt instance string[] [mscorlib]System.String::Split(char[]) /* 0A00003A */
		/* 0x000022EC 280200002B         */ IL_0100: call class [mscorlib]System.Collections.Generic.List`1<!!0> [System.Core]System.Linq.Enumerable::ToList<string>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000002 */
		/* 0x000022F1 1309               */ IL_0105: stloc.s 9
		/* 0x000022F3 2B08               */ IL_0107: br.s IL_0111
		/* 0x000022F5 1109               */ IL_0109: ldloc.s 9
		/* 0x000022F7 19                 */ IL_010b: ldc.i4.3
		/* 0x000022F8 6F3C00000A         */ IL_010c: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<string>::RemoveAt(int32) /* 0A00003C */
		/* 0x000022FD 1109               */ IL_0111: ldloc.s 9
		/* 0x000022FF 6F3D00000A         */ IL_0113: callvirt instance int32 class [mscorlib]System.Collections.Generic.List`1<string>::get_Count() /* 0A00003D */
		/* 0x00002304 19                 */ IL_0118: ldc.i4.3
		/* 0x00002305 30EE               */ IL_0119: bgt.s IL_0109
		/* 0x00002307 1109               */ IL_011b: ldloc.s 9
		/* 0x00002309 6F3D00000A         */ IL_011d: callvirt instance int32 class [mscorlib]System.Collections.Generic.List`1<string>::get_Count() /* 0A00003D */
		/* 0x0000230E 19                 */ IL_0122: ldc.i4.3
		/* 0x0000230F 331C               */ IL_0123: bne.un.s IL_0141
		/* 0x00002311 1109               */ IL_0125: ldloc.s 9
		/* 0x00002313 18                 */ IL_0127: ldc.i4.2
		/* 0x00002314 6F3E00000A         */ IL_0128: callvirt instance !0 class [mscorlib]System.Collections.Generic.List`1<string>::get_Item(int32) /* 0A00003E */
		/* 0x00002319 72A9000070         */ IL_012d: ldstr "0" /* 700000A9 */
		/* 0x0000231E 283F00000A         */ IL_0132: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
		/* 0x00002323 2C08               */ IL_0137: brfalse.s IL_0141
		/* 0x00002325 1109               */ IL_0139: ldloc.s 9
		/* 0x00002327 18                 */ IL_013b: ldc.i4.2
		/* 0x00002328 6F3C00000A         */ IL_013c: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<string>::RemoveAt(int32) /* 0A00003C */
		/* 0x0000232D 1109               */ IL_0141: ldloc.s 9
		/* 0x0000232F 6F3D00000A         */ IL_0143: callvirt instance int32 class [mscorlib]System.Collections.Generic.List`1<string>::get_Count() /* 0A00003D */
		/* 0x00002334 17                 */ IL_0148: ldc.i4.1
		/* 0x00002335 330C               */ IL_0149: bne.un.s IL_0157
		/* 0x00002337 1109               */ IL_014b: ldloc.s 9
		/* 0x00002339 72A9000070         */ IL_014d: ldstr "0" /* 700000A9 */
		/* 0x0000233E 6F4000000A         */ IL_0152: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<string>::Add(!0) /* 0A000040 */
		/* 0x00002343 06                 */ IL_0157: ldloc.0
		/* 0x00002344 08                 */ IL_0158: ldloc.2
		/* 0x00002345 6F2300000A         */ IL_0159: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_FileDescription() /* 0A000023 */
		/* 0x0000234A 08                 */ IL_015e: ldloc.2
		/* 0x0000234B 6F4100000A         */ IL_015f: callvirt instance string [System]System.Diagnostics.FileVersionInfo::get_Comments() /* 0A000041 */
		/* 0x00002350 72AD000070         */ IL_0164: ldstr "." /* 700000AD */
		/* 0x00002355 1109               */ IL_0169: ldloc.s 9
		/* 0x00002357 284200000A         */ IL_016b: call string [mscorlib]System.String::Join(string, class [mscorlib]System.Collections.Generic.IEnumerable`1<string>) /* 0A000042 */
		/* 0x0000235C 1104               */ IL_0170: ldloc.s 4
		/* 0x0000235E 1105               */ IL_0172: ldloc.s 5
		/* 0x00002360 14                 */ IL_0174: ldnull
		/* 0x00002361 6FF0000006         */ IL_0175: callvirt instance void ASPENSPLASHLib.ISplashWindow::ShowSplash2(string, string, string, int16, int16, string) /* 060000F0 */
		/* 0x00002366 2A                 */ IL_017a: ret
	} // end of method Aspen::Splash

	.method /* 06000004 */ private hidebysig static 
		bool '<About>b__0' (
			char x
		) cil managed 
	{
		.custom /* 0C000015 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x208f
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x0000208F 02                 */ IL_0000: ldarg.0
		/* 0x00002090 1F2E               */ IL_0001: ldc.i4.s 46
		/* 0x00002092 FE01               */ IL_0003: ceq
		/* 0x00002094 2A                 */ IL_0005: ret
	} // end of method Aspen::'<About>b__0'

} // end of class AspenTech.Visualisation.Controls.Assistant.Aspen

.class /* 02000004 */ private auto ansi sealed beforefieldinit AspenTech.Visualisation.Controls.Assistant.Properties.Settings
	extends [System]System.Configuration.ApplicationSettingsBase
{
	.custom /* 0C000016 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000017 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 4b 4d 69 63 72 6f 73 6f 66 74 2e 56 69 73
		75 61 6c 53 74 75 64 69 6f 2e 45 64 69 74 6f 72
		73 2e 53 65 74 74 69 6e 67 73 44 65 73 69 67 6e
		65 72 2e 53 65 74 74 69 6e 67 73 53 69 6e 67 6c
		65 46 69 6c 65 47 65 6e 65 72 61 74 6f 72 08 31
		30 2e 30 2e 30 2e 30 00 00
	)
	// Fields
	.field /* 04000006 */ private static class AspenTech.Visualisation.Controls.Assistant.Properties.Settings defaultInstance

	// Methods
	.method /* 06000005 */ public hidebysig specialname static 
		class AspenTech.Visualisation.Controls.Assistant.Properties.Settings get_Default () cil managed 
	{
		// Method begins at RVA 0x2373
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00002373 7E06000004         */ IL_0000: ldsfld class AspenTech.Visualisation.Controls.Assistant.Properties.Settings AspenTech.Visualisation.Controls.Assistant.Properties.Settings::defaultInstance /* 04000006 */
		/* 0x00002378 2A                 */ IL_0005: ret
	} // end of method Settings::get_Default

	.method /* 06000006 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2390
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002390 02                 */ IL_0000: ldarg.0
		/* 0x00002391 284600000A         */ IL_0001: call instance void [System]System.Configuration.ApplicationSettingsBase::.ctor() /* 0A000046 */
		/* 0x00002396 2A                 */ IL_0006: ret
	} // end of method Settings::.ctor

	.method /* 06000007 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x237a
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x0000237A 7306000006         */ IL_0000: newobj instance void AspenTech.Visualisation.Controls.Assistant.Properties.Settings::.ctor() /* 06000006 */
		/* 0x0000237F 284500000A         */ IL_0005: call class [System]System.Configuration.SettingsBase [System]System.Configuration.SettingsBase::Synchronized(class [System]System.Configuration.SettingsBase) /* 0A000045 */
		/* 0x00002384 7404000002         */ IL_000a: castclass AspenTech.Visualisation.Controls.Assistant.Properties.Settings /* 02000004 */
		/* 0x00002389 8006000004         */ IL_000f: stsfld class AspenTech.Visualisation.Controls.Assistant.Properties.Settings AspenTech.Visualisation.Controls.Assistant.Properties.Settings::defaultInstance /* 04000006 */
		/* 0x0000238E 2A                 */ IL_0014: ret
	} // end of method Settings::.cctor

	// Properties
	.property /* 17000001 */ class AspenTech.Visualisation.Controls.Assistant.Properties.Settings Default()
	{
		.get class AspenTech.Visualisation.Controls.Assistant.Properties.Settings AspenTech.Visualisation.Controls.Assistant.Properties.Settings::get_Default()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.Properties.Settings

.class /* 02000005 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.Properties.Resources
	extends [mscorlib]System.Object
{
	.custom /* 0C000018 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000019 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C00001A */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 33 53 79 73 74 65 6d 2e 52 65 73 6f 75 72
		63 65 73 2e 54 6f 6f 6c 73 2e 53 74 72 6f 6e 67
		6c 79 54 79 70 65 64 52 65 73 6f 75 72 63 65 42
		75 69 6c 64 65 72 07 34 2e 30 2e 30 2e 30 00 00
	)
	// Fields
	.field /* 04000007 */ private static class [mscorlib]System.Resources.ResourceManager resourceMan
	.field /* 04000008 */ private static class [mscorlib]System.Globalization.CultureInfo resourceCulture

	// Methods
	.method /* 06000008 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2398
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002398 02                 */ IL_0000: ldarg.0
		/* 0x00002399 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x0000239E 2A                 */ IL_0006: ret
	} // end of method Resources::.ctor

	.method /* 06000009 */ assembly hidebysig specialname static 
		class [mscorlib]System.Resources.ResourceManager get_ResourceManager () cil managed 
	{
		// Method begins at RVA 0x23a0
		// Header size: 12
		// Code size: 51 (0x33)
		.maxstack 3
		.locals /* 11000004 */ init (
			[0] class [mscorlib]System.Resources.ResourceManager
		)

		/* 0x000023A0 7E07000004         */ IL_0000: ldsfld class [mscorlib]System.Resources.ResourceManager AspenTech.Visualisation.Controls.Assistant.Properties.Resources::resourceMan /* 04000007 */
		/* 0x000023A5 14                 */ IL_0005: ldnull
		/* 0x000023A6 284900000A         */ IL_0006: call bool [mscorlib]System.Object::ReferenceEquals(object, object) /* 0A000049 */
		/* 0x000023AB 2C20               */ IL_000b: brfalse.s IL_002d
		/* 0x000023AD 72B1000070         */ IL_000d: ldstr "AspenTech.Visualisation.Controls.Assistant.Properties.Resources" /* 700000B1 */
		/* 0x000023B2 D005000002         */ IL_0012: ldtoken AspenTech.Visualisation.Controls.Assistant.Properties.Resources /* 02000005 */
		/* 0x000023B7 284A00000A         */ IL_0017: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00004A */
		/* 0x000023BC 6F4B00000A         */ IL_001c: callvirt instance class [mscorlib]System.Reflection.Assembly [mscorlib]System.Type::get_Assembly() /* 0A00004B */
		/* 0x000023C1 734C00000A         */ IL_0021: newobj instance void [mscorlib]System.Resources.ResourceManager::.ctor(string, class [mscorlib]System.Reflection.Assembly) /* 0A00004C */
		/* 0x000023C6 0A                 */ IL_0026: stloc.0
		/* 0x000023C7 06                 */ IL_0027: ldloc.0
		/* 0x000023C8 8007000004         */ IL_0028: stsfld class [mscorlib]System.Resources.ResourceManager AspenTech.Visualisation.Controls.Assistant.Properties.Resources::resourceMan /* 04000007 */
		/* 0x000023CD 7E07000004         */ IL_002d: ldsfld class [mscorlib]System.Resources.ResourceManager AspenTech.Visualisation.Controls.Assistant.Properties.Resources::resourceMan /* 04000007 */
		/* 0x000023D2 2A                 */ IL_0032: ret
	} // end of method Resources::get_ResourceManager

	.method /* 0600000A */ assembly hidebysig specialname static 
		class [mscorlib]System.Globalization.CultureInfo get_Culture () cil managed 
	{
		// Method begins at RVA 0x23df
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023DF 7E08000004         */ IL_0000: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.Visualisation.Controls.Assistant.Properties.Resources::resourceCulture /* 04000008 */
		/* 0x000023E4 2A                 */ IL_0005: ret
	} // end of method Resources::get_Culture

	.method /* 0600000B */ assembly hidebysig specialname static 
		void set_Culture (
			class [mscorlib]System.Globalization.CultureInfo 'value'
		) cil managed 
	{
		// Method begins at RVA 0x23e6
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023E6 02                 */ IL_0000: ldarg.0
		/* 0x000023E7 8008000004         */ IL_0001: stsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.Visualisation.Controls.Assistant.Properties.Resources::resourceCulture /* 04000008 */
		/* 0x000023EC 2A                 */ IL_0006: ret
	} // end of method Resources::set_Culture

	// Properties
	.property /* 17000002 */ class [mscorlib]System.Resources.ResourceManager ResourceManager()
	{
		.custom /* 0C000013 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 02 00 00 00 00 00
		)
		.get class [mscorlib]System.Resources.ResourceManager AspenTech.Visualisation.Controls.Assistant.Properties.Resources::get_ResourceManager()
	}
	.property /* 17000003 */ class [mscorlib]System.Globalization.CultureInfo Culture()
	{
		.custom /* 0C000014 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 02 00 00 00 00 00
		)
		.get class [mscorlib]System.Globalization.CultureInfo AspenTech.Visualisation.Controls.Assistant.Properties.Resources::get_Culture()
		.set void AspenTech.Visualisation.Controls.Assistant.Properties.Resources::set_Culture(class [mscorlib]System.Globalization.CultureInfo)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.Properties.Resources

.class /* 02000006 */ private auto ansi sealed AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute
	extends [mscorlib]System.MulticastDelegate
{
	// Methods
	.method /* 0600000C */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			object 'object',
			native int 'method'
		) runtime managed 
	{
	} // end of method GenericCommandExecute::.ctor

	.method /* 0600000D */ public hidebysig newslot virtual 
		instance void Invoke (
			object parameter
		) runtime managed 
	{
	} // end of method GenericCommandExecute::Invoke

	.method /* 0600000E */ public hidebysig newslot virtual 
		instance class [mscorlib]System.IAsyncResult BeginInvoke (
			object parameter,
			class [mscorlib]System.AsyncCallback callback,
			object 'object'
		) runtime managed 
	{
	} // end of method GenericCommandExecute::BeginInvoke

	.method /* 0600000F */ public hidebysig newslot virtual 
		instance void EndInvoke (
			class [mscorlib]System.IAsyncResult result
		) runtime managed 
	{
	} // end of method GenericCommandExecute::EndInvoke

} // end of class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute

.class /* 02000007 */ private auto ansi sealed AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute
	extends [mscorlib]System.MulticastDelegate
{
	// Methods
	.method /* 06000010 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			object 'object',
			native int 'method'
		) runtime managed 
	{
	} // end of method GenericCommandCanExecute::.ctor

	.method /* 06000011 */ public hidebysig newslot virtual 
		instance bool Invoke (
			object parameter
		) runtime managed 
	{
	} // end of method GenericCommandCanExecute::Invoke

	.method /* 06000012 */ public hidebysig newslot virtual 
		instance class [mscorlib]System.IAsyncResult BeginInvoke (
			object parameter,
			class [mscorlib]System.AsyncCallback callback,
			object 'object'
		) runtime managed 
	{
	} // end of method GenericCommandCanExecute::BeginInvoke

	.method /* 06000013 */ public hidebysig newslot virtual 
		instance bool EndInvoke (
			class [mscorlib]System.IAsyncResult result
		) runtime managed 
	{
	} // end of method GenericCommandCanExecute::EndInvoke

} // end of class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute

.class /* 02000008 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler
	extends [mscorlib]System.Object
	implements [PresentationCore]System.Windows.Input.ICommand,
	           [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 04000009 */ private class [mscorlib]System.EventHandler CanExecuteChanged
	.field /* 0400000A */ private class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute _execute
	.field /* 0400000B */ private class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute _canExecute
	.field /* 0400000C */ private object _tag
	.field /* 0400000D */ private string _toolTip
	.field /* 0400000E */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged

	// Methods
	.method /* 06000014 */ public final hidebysig specialname newslot virtual 
		instance void add_CanExecuteChanged (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x23f0
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000005 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x000023F0 02                 */ IL_0000: ldarg.0
		/* 0x000023F1 7B09000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::CanExecuteChanged /* 04000009 */
		/* 0x000023F6 0A                 */ IL_0006: stloc.0
		/* 0x000023F7 06                 */ IL_0007: ldloc.0
		/* 0x000023F8 0B                 */ IL_0008: stloc.1
		/* 0x000023F9 07                 */ IL_0009: ldloc.1
		/* 0x000023FA 03                 */ IL_000a: ldarg.1
		/* 0x000023FB 284E00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00004E */
		/* 0x00002400 7411000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000011 */
		/* 0x00002405 0C                 */ IL_0015: stloc.2
		/* 0x00002406 02                 */ IL_0016: ldarg.0
		/* 0x00002407 7C09000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::CanExecuteChanged /* 04000009 */
		/* 0x0000240C 08                 */ IL_001c: ldloc.2
		/* 0x0000240D 07                 */ IL_001d: ldloc.1
		/* 0x0000240E 280300002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000003 */
		/* 0x00002413 0A                 */ IL_0023: stloc.0
		/* 0x00002414 06                 */ IL_0024: ldloc.0
		/* 0x00002415 07                 */ IL_0025: ldloc.1
		/* 0x00002416 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002418 2A                 */ IL_0028: ret
	} // end of method GenericCommandHandler::add_CanExecuteChanged

	.method /* 06000015 */ public final hidebysig specialname newslot virtual 
		instance void remove_CanExecuteChanged (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2428
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000005 */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00002428 02                 */ IL_0000: ldarg.0
		/* 0x00002429 7B09000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::CanExecuteChanged /* 04000009 */
		/* 0x0000242E 0A                 */ IL_0006: stloc.0
		/* 0x0000242F 06                 */ IL_0007: ldloc.0
		/* 0x00002430 0B                 */ IL_0008: stloc.1
		/* 0x00002431 07                 */ IL_0009: ldloc.1
		/* 0x00002432 03                 */ IL_000a: ldarg.1
		/* 0x00002433 285000000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000050 */
		/* 0x00002438 7411000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000011 */
		/* 0x0000243D 0C                 */ IL_0015: stloc.2
		/* 0x0000243E 02                 */ IL_0016: ldarg.0
		/* 0x0000243F 7C09000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::CanExecuteChanged /* 04000009 */
		/* 0x00002444 08                 */ IL_001c: ldloc.2
		/* 0x00002445 07                 */ IL_001d: ldloc.1
		/* 0x00002446 280300002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000003 */
		/* 0x0000244B 0A                 */ IL_0023: stloc.0
		/* 0x0000244C 06                 */ IL_0024: ldloc.0
		/* 0x0000244D 07                 */ IL_0025: ldloc.1
		/* 0x0000244E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002450 2A                 */ IL_0028: ret
	} // end of method GenericCommandHandler::remove_CanExecuteChanged

	.method /* 06000016 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute execute
		) cil managed 
	{
		// Method begins at RVA 0x245d
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x0000245D 02                 */ IL_0000: ldarg.0
		/* 0x0000245E 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00002463 02                 */ IL_0006: ldarg.0
		/* 0x00002464 03                 */ IL_0007: ldarg.1
		/* 0x00002465 7D0A000004         */ IL_0008: stfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_execute /* 0400000A */
		/* 0x0000246A 2A                 */ IL_000d: ret
	} // end of method GenericCommandHandler::.ctor

	.method /* 06000017 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute canExecute,
			class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute execute
		) cil managed 
	{
		// Method begins at RVA 0x246c
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x0000246C 02                 */ IL_0000: ldarg.0
		/* 0x0000246D 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00002472 02                 */ IL_0006: ldarg.0
		/* 0x00002473 03                 */ IL_0007: ldarg.1
		/* 0x00002474 7D0B000004         */ IL_0008: stfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_canExecute /* 0400000B */
		/* 0x00002479 02                 */ IL_000d: ldarg.0
		/* 0x0000247A 04                 */ IL_000e: ldarg.2
		/* 0x0000247B 7D0A000004         */ IL_000f: stfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_execute /* 0400000A */
		/* 0x00002480 2A                 */ IL_0014: ret
	} // end of method GenericCommandHandler::.ctor

	.method /* 06000018 */ public hidebysig 
		instance void RaiseCanExecuteChanged () cil managed 
	{
		// Method begins at RVA 0x2484
		// Header size: 12
		// Code size: 23 (0x17)
		.maxstack 3
		.locals /* 11000006 */ init (
			[0] class [mscorlib]System.EventHandler
		)

		/* 0x00002484 02                 */ IL_0000: ldarg.0
		/* 0x00002485 7B09000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::CanExecuteChanged /* 04000009 */
		/* 0x0000248A 0A                 */ IL_0006: stloc.0
		/* 0x0000248B 06                 */ IL_0007: ldloc.0
		/* 0x0000248C 2C0C               */ IL_0008: brfalse.s IL_0016
		/* 0x0000248E 06                 */ IL_000a: ldloc.0
		/* 0x0000248F 02                 */ IL_000b: ldarg.0
		/* 0x00002490 7E5100000A         */ IL_000c: ldsfld class [mscorlib]System.EventArgs [mscorlib]System.EventArgs::Empty /* 0A000051 */
		/* 0x00002495 6F5200000A         */ IL_0011: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs) /* 0A000052 */
		/* 0x0000249A 2A                 */ IL_0016: ret
	} // end of method GenericCommandHandler::RaiseCanExecuteChanged

	.method /* 06000019 */ public final hidebysig newslot virtual 
		instance bool CanExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x24a7
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x000024A7 02                 */ IL_0000: ldarg.0
		/* 0x000024A8 7B0B000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_canExecute /* 0400000B */
		/* 0x000024AD 2C0D               */ IL_0006: brfalse.s IL_0015
		/* 0x000024AF 02                 */ IL_0008: ldarg.0
		/* 0x000024B0 7B0B000004         */ IL_0009: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_canExecute /* 0400000B */
		/* 0x000024B5 03                 */ IL_000e: ldarg.1
		/* 0x000024B6 6F11000006         */ IL_000f: callvirt instance bool AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute::Invoke(object) /* 06000011 */
		/* 0x000024BB 2A                 */ IL_0014: ret
		/* 0x000024BC 17                 */ IL_0015: ldc.i4.1
		/* 0x000024BD 2A                 */ IL_0016: ret
	} // end of method GenericCommandHandler::CanExecute

	.method /* 0600001A */ public final hidebysig newslot virtual 
		instance void Execute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x24bf
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x000024BF 02                 */ IL_0000: ldarg.0
		/* 0x000024C0 7B0A000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_execute /* 0400000A */
		/* 0x000024C5 2C0C               */ IL_0006: brfalse.s IL_0014
		/* 0x000024C7 02                 */ IL_0008: ldarg.0
		/* 0x000024C8 7B0A000004         */ IL_0009: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_execute /* 0400000A */
		/* 0x000024CD 03                 */ IL_000e: ldarg.1
		/* 0x000024CE 6F0D000006         */ IL_000f: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute::Invoke(object) /* 0600000D */
		/* 0x000024D3 2A                 */ IL_0014: ret
	} // end of method GenericCommandHandler::Execute

	.method /* 0600001B */ public hidebysig specialname 
		instance object get_Tag () cil managed 
	{
		// Method begins at RVA 0x24d5
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000024D5 02                 */ IL_0000: ldarg.0
		/* 0x000024D6 7B0C000004         */ IL_0001: ldfld object AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_tag /* 0400000C */
		/* 0x000024DB 2A                 */ IL_0006: ret
	} // end of method GenericCommandHandler::get_Tag

	.method /* 0600001C */ public hidebysig specialname 
		instance void set_Tag (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x24dd
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000024DD 02                 */ IL_0000: ldarg.0
		/* 0x000024DE 7B0C000004         */ IL_0001: ldfld object AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_tag /* 0400000C */
		/* 0x000024E3 03                 */ IL_0006: ldarg.1
		/* 0x000024E4 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000024E6 02                 */ IL_0009: ldarg.0
		/* 0x000024E7 03                 */ IL_000a: ldarg.1
		/* 0x000024E8 7D0C000004         */ IL_000b: stfld object AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_tag /* 0400000C */
		/* 0x000024ED 02                 */ IL_0010: ldarg.0
		/* 0x000024EE 7231010070         */ IL_0011: ldstr "Tag" /* 70000131 */
		/* 0x000024F3 281F000006         */ IL_0016: call instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::RaisePropertyChanged(string) /* 0600001F */
		/* 0x000024F8 2A                 */ IL_001b: ret
	} // end of method GenericCommandHandler::set_Tag

	.method /* 0600001D */ public hidebysig specialname 
		instance string get_ToolTip () cil managed 
	{
		// Method begins at RVA 0x24fa
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000024FA 02                 */ IL_0000: ldarg.0
		/* 0x000024FB 7B0D000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_toolTip /* 0400000D */
		/* 0x00002500 2A                 */ IL_0006: ret
	} // end of method GenericCommandHandler::get_ToolTip

	.method /* 0600001E */ public hidebysig specialname 
		instance void set_ToolTip (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2502
		// Header size: 1
		// Code size: 33 (0x21)
		.maxstack 8

		/* 0x00002502 02                 */ IL_0000: ldarg.0
		/* 0x00002503 7B0D000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_toolTip /* 0400000D */
		/* 0x00002508 03                 */ IL_0006: ldarg.1
		/* 0x00002509 285300000A         */ IL_0007: call bool [mscorlib]System.String::op_Inequality(string, string) /* 0A000053 */
		/* 0x0000250E 2C12               */ IL_000c: brfalse.s IL_0020
		/* 0x00002510 02                 */ IL_000e: ldarg.0
		/* 0x00002511 03                 */ IL_000f: ldarg.1
		/* 0x00002512 7D0D000004         */ IL_0010: stfld string AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::_toolTip /* 0400000D */
		/* 0x00002517 02                 */ IL_0015: ldarg.0
		/* 0x00002518 7239010070         */ IL_0016: ldstr "ToolTip" /* 70000139 */
		/* 0x0000251D 281F000006         */ IL_001b: call instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::RaisePropertyChanged(string) /* 0600001F */
		/* 0x00002522 2A                 */ IL_0020: ret
	} // end of method GenericCommandHandler::set_ToolTip

	.method /* 0600001F */ private hidebysig 
		instance void RaisePropertyChanged (
			string 'property'
		) cil managed 
	{
		// Method begins at RVA 0x2524
		// Header size: 12
		// Code size: 24 (0x18)
		.maxstack 4
		.locals /* 11000007 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002524 02                 */ IL_0000: ldarg.0
		/* 0x00002525 7B0E000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::PropertyChanged /* 0400000E */
		/* 0x0000252A 0A                 */ IL_0006: stloc.0
		/* 0x0000252B 06                 */ IL_0007: ldloc.0
		/* 0x0000252C 2C0D               */ IL_0008: brfalse.s IL_0017
		/* 0x0000252E 06                 */ IL_000a: ldloc.0
		/* 0x0000252F 02                 */ IL_000b: ldarg.0
		/* 0x00002530 03                 */ IL_000c: ldarg.1
		/* 0x00002531 735400000A         */ IL_000d: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000054 */
		/* 0x00002536 6F5500000A         */ IL_0012: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000055 */
		/* 0x0000253B 2A                 */ IL_0017: ret
	} // end of method GenericCommandHandler::RaisePropertyChanged

	.method /* 06000020 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2548
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002548 02                 */ IL_0000: ldarg.0
		/* 0x00002549 7B0E000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::PropertyChanged /* 0400000E */
		/* 0x0000254E 0A                 */ IL_0006: stloc.0
		/* 0x0000254F 06                 */ IL_0007: ldloc.0
		/* 0x00002550 0B                 */ IL_0008: stloc.1
		/* 0x00002551 07                 */ IL_0009: ldloc.1
		/* 0x00002552 03                 */ IL_000a: ldarg.1
		/* 0x00002553 284E00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00004E */
		/* 0x00002558 7412000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000012 */
		/* 0x0000255D 0C                 */ IL_0015: stloc.2
		/* 0x0000255E 02                 */ IL_0016: ldarg.0
		/* 0x0000255F 7C0E000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::PropertyChanged /* 0400000E */
		/* 0x00002564 08                 */ IL_001c: ldloc.2
		/* 0x00002565 07                 */ IL_001d: ldloc.1
		/* 0x00002566 280400002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000004 */
		/* 0x0000256B 0A                 */ IL_0023: stloc.0
		/* 0x0000256C 06                 */ IL_0024: ldloc.0
		/* 0x0000256D 07                 */ IL_0025: ldloc.1
		/* 0x0000256E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002570 2A                 */ IL_0028: ret
	} // end of method GenericCommandHandler::add_PropertyChanged

	.method /* 06000021 */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2580
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00002580 02                 */ IL_0000: ldarg.0
		/* 0x00002581 7B0E000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::PropertyChanged /* 0400000E */
		/* 0x00002586 0A                 */ IL_0006: stloc.0
		/* 0x00002587 06                 */ IL_0007: ldloc.0
		/* 0x00002588 0B                 */ IL_0008: stloc.1
		/* 0x00002589 07                 */ IL_0009: ldloc.1
		/* 0x0000258A 03                 */ IL_000a: ldarg.1
		/* 0x0000258B 285000000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000050 */
		/* 0x00002590 7412000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000012 */
		/* 0x00002595 0C                 */ IL_0015: stloc.2
		/* 0x00002596 02                 */ IL_0016: ldarg.0
		/* 0x00002597 7C0E000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::PropertyChanged /* 0400000E */
		/* 0x0000259C 08                 */ IL_001c: ldloc.2
		/* 0x0000259D 07                 */ IL_001d: ldloc.1
		/* 0x0000259E 280400002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000004 */
		/* 0x000025A3 0A                 */ IL_0023: stloc.0
		/* 0x000025A4 06                 */ IL_0024: ldloc.0
		/* 0x000025A5 07                 */ IL_0025: ldloc.1
		/* 0x000025A6 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000025A8 2A                 */ IL_0028: ret
	} // end of method GenericCommandHandler::remove_PropertyChanged

	// Events
	.event /* 14000001 */ [mscorlib]System.EventHandler CanExecuteChanged
	{
		.addon instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::add_CanExecuteChanged(class [mscorlib]System.EventHandler)
		.removeon instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::remove_CanExecuteChanged(class [mscorlib]System.EventHandler)
	}

	.event /* 14000002 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 17000004 */ instance object Tag()
	{
		.get instance object AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::get_Tag()
		.set instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::set_Tag(object)
	}
	.property /* 17000005 */ instance string ToolTip()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::get_ToolTip()
		.set instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::set_ToolTip(string)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler

.class /* 02000009 */ private auto ansi sealed AspenTech.Visualisation.Controls.Assistant.HtmlStyle
	extends [mscorlib]System.Enum
{
	.custom /* 0C00001B */ instance void [mscorlib]System.FlagsAttribute::.ctor() = (
		01 00 00 00
	)
	// Fields
	.field /* 0400000F */ public specialname rtspecialname int32 value__
	.field /* 04000010 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle includeTitle = int32(1)
	.field /* 04000011 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle liveOptions = int32(2)
	.field /* 04000012 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle processManualLink = int32(4)

} // end of class AspenTech.Visualisation.Controls.Assistant.HtmlStyle

.class /* 0200000A */ private auto ansi abstract sealed beforefieldinit AspenTech.Visualisation.Controls.Assistant.Renderer
	extends [mscorlib]System.Object
{
	// Methods
	.method /* 06000022 */ assembly hidebysig static 
		void RenderStyleFile (
			class [System.Web]System.Web.UI.HtmlTextWriter writer,
			string fileName
		) cil managed 
	{
		// Method begins at RVA 0x25b8
		// Header size: 12
		// Code size: 73 (0x49)
		.maxstack 3
		.locals /* 11000009 */ init (
			[0] string
		)

		/* 0x000025B8 281900000A         */ IL_0000: call class [mscorlib]System.Reflection.Assembly [mscorlib]System.Reflection.Assembly::GetExecutingAssembly() /* 0A000019 */
		/* 0x000025BD 6F1F00000A         */ IL_0005: callvirt instance string [mscorlib]System.Reflection.Assembly::get_Location() /* 0A00001F */
		/* 0x000025C2 285700000A         */ IL_000a: call string [mscorlib]System.IO.Path::GetDirectoryName(string) /* 0A000057 */
		/* 0x000025C7 03                 */ IL_000f: ldarg.1
		/* 0x000025C8 285800000A         */ IL_0010: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x000025CD 0A                 */ IL_0015: stloc.0
		/* 0x000025CE 06                 */ IL_0016: ldloc.0
		/* 0x000025CF 285900000A         */ IL_0017: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x000025D4 2C2A               */ IL_001c: brfalse.s IL_0048
		/* 0x000025D6 02                 */ IL_001e: ldarg.0
		/* 0x000025D7 1F23               */ IL_001f: ldc.i4.s 35
		/* 0x000025D9 7249010070         */ IL_0021: ldstr "text/css" /* 70000149 */
		/* 0x000025DE 6F5A00000A         */ IL_0026: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(valuetype [System.Web]System.Web.UI.HtmlTextWriterAttribute, string) /* 0A00005A */
		/* 0x000025E3 02                 */ IL_002b: ldarg.0
		/* 0x000025E4 725B010070         */ IL_002c: ldstr "style" /* 7000015B */
		/* 0x000025E9 6F5B00000A         */ IL_0031: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x000025EE 02                 */ IL_0036: ldarg.0
		/* 0x000025EF 06                 */ IL_0037: ldloc.0
		/* 0x000025F0 285C00000A         */ IL_0038: call string [mscorlib]System.IO.File::ReadAllText(string) /* 0A00005C */
		/* 0x000025F5 6F5D00000A         */ IL_003d: callvirt instance void [mscorlib]System.IO.TextWriter::Write(string) /* 0A00005D */
		/* 0x000025FA 02                 */ IL_0042: ldarg.0
		/* 0x000025FB 6F5E00000A         */ IL_0043: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00002600 2A                 */ IL_0048: ret
	} // end of method Renderer::RenderStyleFile

	.method /* 06000023 */ assembly hidebysig static 
		void RenderAssistantInfo (
			class [System.Web]System.Web.UI.HtmlTextWriter writer,
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot root
		) cil managed 
	{
		// Method begins at RVA 0x2610
		// Header size: 12
		// Code size: 211 (0xd3)
		.maxstack 3
		.locals /* 1100000A */ init (
			[0] valuetype [mscorlib]System.DateTime
		)

		/* 0x00002610 02                 */ IL_0000: ldarg.0
		/* 0x00002611 1F2A               */ IL_0001: ldc.i4.s 42
		/* 0x00002613 6F5F00000A         */ IL_0003: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002618 02                 */ IL_0008: ldarg.0
		/* 0x00002619 6F5E00000A         */ IL_0009: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x0000261E 02                 */ IL_000e: ldarg.0
		/* 0x0000261F 1F0A               */ IL_000f: ldc.i4.s 10
		/* 0x00002621 7267010070         */ IL_0011: ldstr "infoBlock" /* 70000167 */
		/* 0x00002626 6F5A00000A         */ IL_0016: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(valuetype [System.Web]System.Web.UI.HtmlTextWriterAttribute, string) /* 0A00005A */
		/* 0x0000262B 02                 */ IL_001b: ldarg.0
		/* 0x0000262C 1F52               */ IL_001c: ldc.i4.s 82
		/* 0x0000262E 6F5F00000A         */ IL_001e: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002633 03                 */ IL_0023: ldarg.1
		/* 0x00002634 6F4B000006         */ IL_0024: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Copyright() /* 0600004B */
		/* 0x00002639 282C00000A         */ IL_0029: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x0000263E 2D2B               */ IL_002e: brtrue.s IL_005b
		/* 0x00002640 02                 */ IL_0030: ldarg.0
		/* 0x00002641 1F5A               */ IL_0031: ldc.i4.s 90
		/* 0x00002643 6F5F00000A         */ IL_0033: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002648 02                 */ IL_0038: ldarg.0
		/* 0x00002649 1F57               */ IL_0039: ldc.i4.s 87
		/* 0x0000264B 727B010070         */ IL_003b: ldstr "Copyright:" /* 7000017B */
		/* 0x00002650 28B9000006         */ IL_0040: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002655 26                 */ IL_0045: pop
		/* 0x00002656 02                 */ IL_0046: ldarg.0
		/* 0x00002657 1F54               */ IL_0047: ldc.i4.s 84
		/* 0x00002659 03                 */ IL_0049: ldarg.1
		/* 0x0000265A 6F4B000006         */ IL_004a: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Copyright() /* 0600004B */
		/* 0x0000265F 28B9000006         */ IL_004f: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002664 26                 */ IL_0054: pop
		/* 0x00002665 02                 */ IL_0055: ldarg.0
		/* 0x00002666 6F5E00000A         */ IL_0056: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x0000266B 03                 */ IL_005b: ldarg.1
		/* 0x0000266C 6F41000006         */ IL_005c: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Author() /* 06000041 */
		/* 0x00002671 282C00000A         */ IL_0061: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00002676 2D2B               */ IL_0066: brtrue.s IL_0093
		/* 0x00002678 02                 */ IL_0068: ldarg.0
		/* 0x00002679 1F5A               */ IL_0069: ldc.i4.s 90
		/* 0x0000267B 6F5F00000A         */ IL_006b: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002680 02                 */ IL_0070: ldarg.0
		/* 0x00002681 1F57               */ IL_0071: ldc.i4.s 87
		/* 0x00002683 7291010070         */ IL_0073: ldstr "Author:" /* 70000191 */
		/* 0x00002688 28B9000006         */ IL_0078: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x0000268D 26                 */ IL_007d: pop
		/* 0x0000268E 02                 */ IL_007e: ldarg.0
		/* 0x0000268F 1F54               */ IL_007f: ldc.i4.s 84
		/* 0x00002691 03                 */ IL_0081: ldarg.1
		/* 0x00002692 6F41000006         */ IL_0082: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Author() /* 06000041 */
		/* 0x00002697 28B9000006         */ IL_0087: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x0000269C 26                 */ IL_008c: pop
		/* 0x0000269D 02                 */ IL_008d: ldarg.0
		/* 0x0000269E 6F5E00000A         */ IL_008e: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x000026A3 02                 */ IL_0093: ldarg.0
		/* 0x000026A4 1F5A               */ IL_0094: ldc.i4.s 90
		/* 0x000026A6 6F5F00000A         */ IL_0096: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x000026AB 02                 */ IL_009b: ldarg.0
		/* 0x000026AC 1F57               */ IL_009c: ldc.i4.s 87
		/* 0x000026AE 72A1010070         */ IL_009e: ldstr "Build date:" /* 700001A1 */
		/* 0x000026B3 28B9000006         */ IL_00a3: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x000026B8 26                 */ IL_00a8: pop
		/* 0x000026B9 02                 */ IL_00a9: ldarg.0
		/* 0x000026BA 1F54               */ IL_00aa: ldc.i4.s 84
		/* 0x000026BC 03                 */ IL_00ac: ldarg.1
		/* 0x000026BD 6F4D000006         */ IL_00ad: callvirt instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate() /* 0600004D */
		/* 0x000026C2 0A                 */ IL_00b2: stloc.0
		/* 0x000026C3 1200               */ IL_00b3: ldloca.s 0
		/* 0x000026C5 FE1617000001       */ IL_00b5: constrained. [mscorlib]System.DateTime /* 01000017 */
		/* 0x000026CB 6F6000000A         */ IL_00bb: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x000026D0 28B9000006         */ IL_00c0: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x000026D5 26                 */ IL_00c5: pop
		/* 0x000026D6 02                 */ IL_00c6: ldarg.0
		/* 0x000026D7 6F5E00000A         */ IL_00c7: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x000026DC 02                 */ IL_00cc: ldarg.0
		/* 0x000026DD 6F5E00000A         */ IL_00cd: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x000026E2 2A                 */ IL_00d2: ret
	} // end of method Renderer::RenderAssistantInfo

	.method /* 06000024 */ assembly hidebysig static 
		void RenderGenerationInfo (
			class [System.Web]System.Web.UI.HtmlTextWriter writer
		) cil managed 
	{
		// Method begins at RVA 0x26f0
		// Header size: 12
		// Code size: 197 (0xc5)
		.maxstack 5
		.locals /* 1100000A */ init (
			[0] valuetype [mscorlib]System.DateTime
		)

		/* 0x000026F0 02                 */ IL_0000: ldarg.0
		/* 0x000026F1 1F2A               */ IL_0001: ldc.i4.s 42
		/* 0x000026F3 6F5F00000A         */ IL_0003: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x000026F8 02                 */ IL_0008: ldarg.0
		/* 0x000026F9 6F5E00000A         */ IL_0009: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x000026FE 02                 */ IL_000e: ldarg.0
		/* 0x000026FF 1F0A               */ IL_000f: ldc.i4.s 10
		/* 0x00002701 7267010070         */ IL_0011: ldstr "infoBlock" /* 70000167 */
		/* 0x00002706 6F5A00000A         */ IL_0016: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(valuetype [System.Web]System.Web.UI.HtmlTextWriterAttribute, string) /* 0A00005A */
		/* 0x0000270B 02                 */ IL_001b: ldarg.0
		/* 0x0000270C 1F52               */ IL_001c: ldc.i4.s 82
		/* 0x0000270E 6F5F00000A         */ IL_001e: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002713 02                 */ IL_0023: ldarg.0
		/* 0x00002714 1F5A               */ IL_0024: ldc.i4.s 90
		/* 0x00002716 6F5F00000A         */ IL_0026: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x0000271B 02                 */ IL_002b: ldarg.0
		/* 0x0000271C 1F57               */ IL_002c: ldc.i4.s 87
		/* 0x0000271E 72B9010070         */ IL_002e: ldstr "User:" /* 700001B9 */
		/* 0x00002723 28B9000006         */ IL_0033: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002728 26                 */ IL_0038: pop
		/* 0x00002729 02                 */ IL_0039: ldarg.0
		/* 0x0000272A 1F54               */ IL_003a: ldc.i4.s 84
		/* 0x0000272C 286100000A         */ IL_003c: call string [mscorlib]System.Environment::get_UserDomainName() /* 0A000061 */
		/* 0x00002731 72C5010070         */ IL_0041: ldstr "\\" /* 700001C5 */
		/* 0x00002736 286200000A         */ IL_0046: call string [mscorlib]System.Environment::get_UserName() /* 0A000062 */
		/* 0x0000273B 286300000A         */ IL_004b: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000063 */
		/* 0x00002740 28B9000006         */ IL_0050: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002745 26                 */ IL_0055: pop
		/* 0x00002746 02                 */ IL_0056: ldarg.0
		/* 0x00002747 6F5E00000A         */ IL_0057: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x0000274C 02                 */ IL_005c: ldarg.0
		/* 0x0000274D 1F5A               */ IL_005d: ldc.i4.s 90
		/* 0x0000274F 6F5F00000A         */ IL_005f: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002754 02                 */ IL_0064: ldarg.0
		/* 0x00002755 1F57               */ IL_0065: ldc.i4.s 87
		/* 0x00002757 72C9010070         */ IL_0067: ldstr "Computer:" /* 700001C9 */
		/* 0x0000275C 28B9000006         */ IL_006c: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002761 26                 */ IL_0071: pop
		/* 0x00002762 02                 */ IL_0072: ldarg.0
		/* 0x00002763 1F54               */ IL_0073: ldc.i4.s 84
		/* 0x00002765 286400000A         */ IL_0075: call string [mscorlib]System.Environment::get_MachineName() /* 0A000064 */
		/* 0x0000276A 28B9000006         */ IL_007a: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x0000276F 26                 */ IL_007f: pop
		/* 0x00002770 02                 */ IL_0080: ldarg.0
		/* 0x00002771 6F5E00000A         */ IL_0081: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00002776 02                 */ IL_0086: ldarg.0
		/* 0x00002777 1F5A               */ IL_0087: ldc.i4.s 90
		/* 0x00002779 6F5F00000A         */ IL_0089: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x0000277E 02                 */ IL_008e: ldarg.0
		/* 0x0000277F 1F57               */ IL_008f: ldc.i4.s 87
		/* 0x00002781 72DD010070         */ IL_0091: ldstr "Generated:" /* 700001DD */
		/* 0x00002786 28B9000006         */ IL_0096: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x0000278B 26                 */ IL_009b: pop
		/* 0x0000278C 02                 */ IL_009c: ldarg.0
		/* 0x0000278D 1F54               */ IL_009d: ldc.i4.s 84
		/* 0x0000278F 283800000A         */ IL_009f: call valuetype [mscorlib]System.DateTime [mscorlib]System.DateTime::get_Now() /* 0A000038 */
		/* 0x00002794 0A                 */ IL_00a4: stloc.0
		/* 0x00002795 1200               */ IL_00a5: ldloca.s 0
		/* 0x00002797 FE1617000001       */ IL_00a7: constrained. [mscorlib]System.DateTime /* 01000017 */
		/* 0x0000279D 6F6000000A         */ IL_00ad: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x000027A2 28B9000006         */ IL_00b2: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x000027A7 26                 */ IL_00b7: pop
		/* 0x000027A8 02                 */ IL_00b8: ldarg.0
		/* 0x000027A9 6F5E00000A         */ IL_00b9: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x000027AE 02                 */ IL_00be: ldarg.0
		/* 0x000027AF 6F5E00000A         */ IL_00bf: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x000027B4 2A                 */ IL_00c4: ret
	} // end of method Renderer::RenderGenerationInfo

	.method /* 06000025 */ assembly hidebysig static 
		void RenderAsHtml (
			class [System.Web]System.Web.UI.HtmlTextWriter html,
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot root,
			valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle style,
			string linkPrefix,
			string highlightOption
		) cil managed 
	{
		// Method begins at RVA 0x27c1
		// Header size: 1
		// Code size: 60 (0x3c)
		.maxstack 8

		/* 0x000027C1 02                 */ IL_0000: ldarg.0
		/* 0x000027C2 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x000027C4 72F3010070         */ IL_0003: ldstr "html" /* 700001F3 */
		/* 0x000027C9 736500000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000065 */
		/* 0x000027CE 7A                 */ IL_000d: throw
		/* 0x000027CF 03                 */ IL_000e: ldarg.1
		/* 0x000027D0 2D01               */ IL_000f: brtrue.s IL_0012
		/* 0x000027D2 2A                 */ IL_0011: ret
		/* 0x000027D3 04                 */ IL_0012: ldarg.2
		/* 0x000027D4 8C09000002         */ IL_0013: box AspenTech.Visualisation.Controls.Assistant.HtmlStyle /* 02000009 */
		/* 0x000027D9 17                 */ IL_0018: ldc.i4.1
		/* 0x000027DA 8C09000002         */ IL_0019: box AspenTech.Visualisation.Controls.Assistant.HtmlStyle /* 02000009 */
		/* 0x000027DF 286600000A         */ IL_001e: call instance bool [mscorlib]System.Enum::HasFlag(class [mscorlib]System.Enum) /* 0A000066 */
		/* 0x000027E4 2C0F               */ IL_0023: brfalse.s IL_0034
		/* 0x000027E6 02                 */ IL_0025: ldarg.0
		/* 0x000027E7 1F24               */ IL_0026: ldc.i4.s 36
		/* 0x000027E9 03                 */ IL_0028: ldarg.1
		/* 0x000027EA 6F2F000006         */ IL_0029: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x000027EF 28B9000006         */ IL_002e: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x000027F4 26                 */ IL_0033: pop
		/* 0x000027F5 02                 */ IL_0034: ldarg.0
		/* 0x000027F6 03                 */ IL_0035: ldarg.1
		/* 0x000027F7 2827000006         */ IL_0036: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderExplanations(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistBase) /* 06000027 */
		/* 0x000027FC 2A                 */ IL_003b: ret
	} // end of method Renderer::RenderAsHtml

	.method /* 06000026 */ assembly hidebysig static 
		void RenderAsHtml (
			class [System.Web]System.Web.UI.HtmlTextWriter html,
			class AspenTech.Visualisation.Controls.Assistant.AssistScreen screen,
			valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle style,
			string linkPrefix,
			string highlightOption
		) cil managed 
	{
		// Method begins at RVA 0x2800
		// Header size: 12
		// Code size: 328 (0x148)
		.maxstack 5
		.locals /* 1100000B */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistOption,
			[1] bool,
			[2] valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>,
			[3] string[]
		)

		/* 0x00002800 02                 */ IL_0000: ldarg.0
		/* 0x00002801 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x00002803 72F3010070         */ IL_0003: ldstr "html" /* 700001F3 */
		/* 0x00002808 736500000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000065 */
		/* 0x0000280D 7A                 */ IL_000d: throw
		/* 0x0000280E 03                 */ IL_000e: ldarg.1
		/* 0x0000280F 2D01               */ IL_000f: brtrue.s IL_0012
		/* 0x00002811 2A                 */ IL_0011: ret
		/* 0x00002812 04                 */ IL_0012: ldarg.2
		/* 0x00002813 8C09000002         */ IL_0013: box AspenTech.Visualisation.Controls.Assistant.HtmlStyle /* 02000009 */
		/* 0x00002818 17                 */ IL_0018: ldc.i4.1
		/* 0x00002819 8C09000002         */ IL_0019: box AspenTech.Visualisation.Controls.Assistant.HtmlStyle /* 02000009 */
		/* 0x0000281E 286600000A         */ IL_001e: call instance bool [mscorlib]System.Enum::HasFlag(class [mscorlib]System.Enum) /* 0A000066 */
		/* 0x00002823 2C0F               */ IL_0023: brfalse.s IL_0034
		/* 0x00002825 02                 */ IL_0025: ldarg.0
		/* 0x00002826 1F24               */ IL_0026: ldc.i4.s 36
		/* 0x00002828 03                 */ IL_0028: ldarg.1
		/* 0x00002829 6F2F000006         */ IL_0029: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x0000282E 28B9000006         */ IL_002e: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002833 26                 */ IL_0033: pop
		/* 0x00002834 02                 */ IL_0034: ldarg.0
		/* 0x00002835 03                 */ IL_0035: ldarg.1
		/* 0x00002836 2827000006         */ IL_0036: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderExplanations(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistBase) /* 06000027 */
		/* 0x0000283B 02                 */ IL_003b: ldarg.0
		/* 0x0000283C 1F5D               */ IL_003c: ldc.i4.s 93
		/* 0x0000283E 6F5F00000A         */ IL_003e: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002843 03                 */ IL_0043: ldarg.1
		/* 0x00002844 6FBA000006         */ IL_0044: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x00002849 6F6700000A         */ IL_0049: callvirt instance valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<!0> class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::GetEnumerator() /* 0A000067 */
		/* 0x0000284E 0C                 */ IL_004e: stloc.2
		/* 0x0000284F 38D1000000         */ IL_004f: br IL_0125
		/* 0x00002854 1202               */ IL_0054: ldloca.s 2
		/* 0x00002856 286800000A         */ IL_0056: call instance !0 valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::get_Current() /* 0A000068 */
		/* 0x0000285B 0A                 */ IL_005b: stloc.0
		/* 0x0000285C 06                 */ IL_005c: ldloc.0
		/* 0x0000285D 6F2F000006         */ IL_005d: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00002862 282C00000A         */ IL_0062: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00002867 3AB9000000         */ IL_0067: brtrue IL_0125
		/* 0x0000286C 02                 */ IL_006c: ldarg.0
		/* 0x0000286D 1F35               */ IL_006d: ldc.i4.s 53
		/* 0x0000286F 6F5F00000A         */ IL_006f: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002874 0E04               */ IL_0074: ldarg.s highlightOption
		/* 0x00002876 06                 */ IL_0076: ldloc.0
		/* 0x00002877 6F28000006         */ IL_0077: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x0000287C 1B                 */ IL_007c: ldc.i4.5
		/* 0x0000287D 286900000A         */ IL_007d: call int32 [mscorlib]System.String::Compare(string, string, valuetype [mscorlib]System.StringComparison) /* 0A000069 */
		/* 0x00002882 16                 */ IL_0082: ldc.i4.0
		/* 0x00002883 FE01               */ IL_0083: ceq
		/* 0x00002885 0B                 */ IL_0085: stloc.1
		/* 0x00002886 07                 */ IL_0086: ldloc.1
		/* 0x00002887 2C07               */ IL_0087: brfalse.s IL_0090
		/* 0x00002889 02                 */ IL_0089: ldarg.0
		/* 0x0000288A 1B                 */ IL_008a: ldc.i4.5
		/* 0x0000288B 6F5F00000A         */ IL_008b: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x00002890 04                 */ IL_0090: ldarg.2
		/* 0x00002891 8C09000002         */ IL_0091: box AspenTech.Visualisation.Controls.Assistant.HtmlStyle /* 02000009 */
		/* 0x00002896 18                 */ IL_0096: ldc.i4.2
		/* 0x00002897 8C09000002         */ IL_0097: box AspenTech.Visualisation.Controls.Assistant.HtmlStyle /* 02000009 */
		/* 0x0000289C 286600000A         */ IL_009c: call instance bool [mscorlib]System.Enum::HasFlag(class [mscorlib]System.Enum) /* 0A000066 */
		/* 0x000028A1 2C44               */ IL_00a1: brfalse.s IL_00e7
		/* 0x000028A3 02                 */ IL_00a3: ldarg.0
		/* 0x000028A4 1F10               */ IL_00a4: ldc.i4.s 16
		/* 0x000028A6 1B                 */ IL_00a6: ldc.i4.5
		/* 0x000028A7 8D45000001         */ IL_00a7: newarr [mscorlib]System.String /* 01000045 */
		/* 0x000028AC 0D                 */ IL_00ac: stloc.3
		/* 0x000028AD 09                 */ IL_00ad: ldloc.3
		/* 0x000028AE 16                 */ IL_00ae: ldc.i4.0
		/* 0x000028AF 05                 */ IL_00af: ldarg.3
		/* 0x000028B0 A2                 */ IL_00b0: stelem.ref
		/* 0x000028B1 09                 */ IL_00b1: ldloc.3
		/* 0x000028B2 17                 */ IL_00b2: ldc.i4.1
		/* 0x000028B3 72FD010070         */ IL_00b3: ldstr "/" /* 700001FD */
		/* 0x000028B8 A2                 */ IL_00b8: stelem.ref
		/* 0x000028B9 09                 */ IL_00b9: ldloc.3
		/* 0x000028BA 18                 */ IL_00ba: ldc.i4.2
		/* 0x000028BB 03                 */ IL_00bb: ldarg.1
		/* 0x000028BC 6F28000006         */ IL_00bc: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000028C1 A2                 */ IL_00c1: stelem.ref
		/* 0x000028C2 09                 */ IL_00c2: ldloc.3
		/* 0x000028C3 19                 */ IL_00c3: ldc.i4.3
		/* 0x000028C4 72FD010070         */ IL_00c4: ldstr "/" /* 700001FD */
		/* 0x000028C9 A2                 */ IL_00c9: stelem.ref
		/* 0x000028CA 09                 */ IL_00ca: ldloc.3
		/* 0x000028CB 1A                 */ IL_00cb: ldc.i4.4
		/* 0x000028CC 06                 */ IL_00cc: ldloc.0
		/* 0x000028CD 6F28000006         */ IL_00cd: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000028D2 A2                 */ IL_00d2: stelem.ref
		/* 0x000028D3 09                 */ IL_00d3: ldloc.3
		/* 0x000028D4 286A00000A         */ IL_00d4: call string [mscorlib]System.String::Concat(string[]) /* 0A00006A */
		/* 0x000028D9 6F5A00000A         */ IL_00d9: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(valuetype [System.Web]System.Web.UI.HtmlTextWriterAttribute, string) /* 0A00005A */
		/* 0x000028DE 02                 */ IL_00de: ldarg.0
		/* 0x000028DF 17                 */ IL_00df: ldc.i4.1
		/* 0x000028E0 6F5F00000A         */ IL_00e0: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x000028E5 2B08               */ IL_00e5: br.s IL_00ef
		/* 0x000028E7 02                 */ IL_00e7: ldarg.0
		/* 0x000028E8 1F5C               */ IL_00e8: ldc.i4.s 92
		/* 0x000028EA 6F5F00000A         */ IL_00ea: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x000028EF 02                 */ IL_00ef: ldarg.0
		/* 0x000028F0 06                 */ IL_00f0: ldloc.0
		/* 0x000028F1 6F2F000006         */ IL_00f1: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x000028F6 6F6B00000A         */ IL_00f6: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::WriteEncodedText(string) /* 0A00006B */
		/* 0x000028FB 02                 */ IL_00fb: ldarg.0
		/* 0x000028FC 6F5E00000A         */ IL_00fc: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00002901 07                 */ IL_0101: ldloc.1
		/* 0x00002902 2C0B               */ IL_0102: brfalse.s IL_010f
		/* 0x00002904 02                 */ IL_0104: ldarg.0
		/* 0x00002905 7201020070         */ IL_0105: ldstr " &#10004;" /* 70000201 */
		/* 0x0000290A 6F5D00000A         */ IL_010a: callvirt instance void [mscorlib]System.IO.TextWriter::Write(string) /* 0A00005D */
		/* 0x0000290F 02                 */ IL_010f: ldarg.0
		/* 0x00002910 06                 */ IL_0110: ldloc.0
		/* 0x00002911 2827000006         */ IL_0111: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderExplanations(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistBase) /* 06000027 */
		/* 0x00002916 07                 */ IL_0116: ldloc.1
		/* 0x00002917 2C06               */ IL_0117: brfalse.s IL_011f
		/* 0x00002919 02                 */ IL_0119: ldarg.0
		/* 0x0000291A 6F5E00000A         */ IL_011a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x0000291F 02                 */ IL_011f: ldarg.0
		/* 0x00002920 6F5E00000A         */ IL_0120: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00002925 1202               */ IL_0125: ldloca.s 2
		/* 0x00002927 286C00000A         */ IL_0127: call instance bool valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::MoveNext() /* 0A00006C */
		/* 0x0000292C 3A23FFFFFF         */ IL_012c: brtrue IL_0054
		/* 0x00002931 DE0E               */ IL_0131: leave.s IL_0141
		/* 0x00002933 1202               */ IL_0133: ldloca.s 2
		/* 0x00002935 FE160500001B       */ IL_0135: constrained. valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption> /* 1B000005 */
		/* 0x0000293B 6F6D00000A         */ IL_013b: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00002940 DC                 */ IL_0140: endfinally
		/* 0x00002941 02                 */ IL_0141: ldarg.0
		/* 0x00002942 6F5E00000A         */ IL_0142: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00002947 2A                 */ IL_0147: ret

		.try IL_004f-IL_0133 finally IL_0133-IL_0141
	} // end of method Renderer::RenderAsHtml

	.method /* 06000027 */ private hidebysig static 
		void RenderExplanations (
			class [System.Web]System.Web.UI.HtmlTextWriter html,
			class AspenTech.Visualisation.Controls.Assistant.AssistBase item
		) cil managed 
	{
		// Method begins at RVA 0x2964
		// Header size: 12
		// Code size: 229 (0xe5)
		.maxstack 4
		.locals /* 1100000C */ init (
			[0] int32,
			[1] string,
			[2] int32,
			[3] string,
			[4] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>
		)

		/* 0x00002964 03                 */ IL_0000: ldarg.1
		/* 0x00002965 39DE000000         */ IL_0001: brfalse IL_00e4
		/* 0x0000296A 03                 */ IL_0006: ldarg.1
		/* 0x0000296B 6F31000006         */ IL_0007: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x00002970 39D3000000         */ IL_000c: brfalse IL_00e4
		/* 0x00002975 03                 */ IL_0011: ldarg.1
		/* 0x00002976 6F31000006         */ IL_0012: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x0000297B 6F6E00000A         */ IL_0017: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<string>::get_Count() /* 0A00006E */
		/* 0x00002980 16                 */ IL_001c: ldc.i4.0
		/* 0x00002981 3EC2000000         */ IL_001d: ble IL_00e4
		/* 0x00002986 03                 */ IL_0022: ldarg.1
		/* 0x00002987 6F31000006         */ IL_0023: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x0000298C 16                 */ IL_0028: ldc.i4.0
		/* 0x0000298D 6F6F00000A         */ IL_0029: callvirt instance !0 class [mscorlib]System.Collections.Generic.IList`1<string>::get_Item(int32) /* 0A00006F */
		/* 0x00002992 7215020070         */ IL_002e: ldstr "<html" /* 70000215 */
		/* 0x00002997 19                 */ IL_0033: ldc.i4.3
		/* 0x00002998 6F7000000A         */ IL_0034: callvirt instance bool [mscorlib]System.String::StartsWith(string, valuetype [mscorlib]System.StringComparison) /* 0A000070 */
		/* 0x0000299D 2C71               */ IL_0039: brfalse.s IL_00ac
		/* 0x0000299F 16                 */ IL_003b: ldc.i4.0
		/* 0x000029A0 0A                 */ IL_003c: stloc.0
		/* 0x000029A1 2B5C               */ IL_003d: br.s IL_009b
		/* 0x000029A3 03                 */ IL_003f: ldarg.1
		/* 0x000029A4 6F31000006         */ IL_0040: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x000029A9 06                 */ IL_0045: ldloc.0
		/* 0x000029AA 6F6F00000A         */ IL_0046: callvirt instance !0 class [mscorlib]System.Collections.Generic.IList`1<string>::get_Item(int32) /* 0A00006F */
		/* 0x000029AF 0B                 */ IL_004b: stloc.1
		/* 0x000029B0 06                 */ IL_004c: ldloc.0
		/* 0x000029B1 2D1F               */ IL_004d: brtrue.s IL_006e
		/* 0x000029B3 07                 */ IL_004f: ldloc.1
		/* 0x000029B4 1F3E               */ IL_0050: ldc.i4.s 62
		/* 0x000029B6 6F7100000A         */ IL_0052: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x000029BB 0C                 */ IL_0057: stloc.2
		/* 0x000029BC 08                 */ IL_0058: ldloc.2
		/* 0x000029BD 16                 */ IL_0059: ldc.i4.0
		/* 0x000029BE 310C               */ IL_005a: ble.s IL_0068
		/* 0x000029C0 07                 */ IL_005c: ldloc.1
		/* 0x000029C1 08                 */ IL_005d: ldloc.2
		/* 0x000029C2 17                 */ IL_005e: ldc.i4.1
		/* 0x000029C3 58                 */ IL_005f: add
		/* 0x000029C4 6F7200000A         */ IL_0060: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x000029C9 0B                 */ IL_0065: stloc.1
		/* 0x000029CA 2B06               */ IL_0066: br.s IL_006e
		/* 0x000029CC 7E2800000A         */ IL_0068: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x000029D1 0B                 */ IL_006d: stloc.1
		/* 0x000029D2 07                 */ IL_006e: ldloc.1
		/* 0x000029D3 7221020070         */ IL_006f: ldstr "</html" /* 70000221 */
		/* 0x000029D8 19                 */ IL_0074: ldc.i4.3
		/* 0x000029D9 6F7300000A         */ IL_0075: callvirt instance int32 [mscorlib]System.String::IndexOf(string, valuetype [mscorlib]System.StringComparison) /* 0A000073 */
		/* 0x000029DE 0C                 */ IL_007a: stloc.2
		/* 0x000029DF 08                 */ IL_007b: ldloc.2
		/* 0x000029E0 16                 */ IL_007c: ldc.i4.0
		/* 0x000029E1 2F09               */ IL_007d: bge.s IL_0088
		/* 0x000029E3 02                 */ IL_007f: ldarg.0
		/* 0x000029E4 07                 */ IL_0080: ldloc.1
		/* 0x000029E5 6F5D00000A         */ IL_0081: callvirt instance void [mscorlib]System.IO.TextWriter::Write(string) /* 0A00005D */
		/* 0x000029EA 2B0F               */ IL_0086: br.s IL_0097
		/* 0x000029EC 02                 */ IL_0088: ldarg.0
		/* 0x000029ED 07                 */ IL_0089: ldloc.1
		/* 0x000029EE 16                 */ IL_008a: ldc.i4.0
		/* 0x000029EF 08                 */ IL_008b: ldloc.2
		/* 0x000029F0 6F7400000A         */ IL_008c: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x000029F5 6F5D00000A         */ IL_0091: callvirt instance void [mscorlib]System.IO.TextWriter::Write(string) /* 0A00005D */
		/* 0x000029FA 2A                 */ IL_0096: ret
		/* 0x000029FB 06                 */ IL_0097: ldloc.0
		/* 0x000029FC 17                 */ IL_0098: ldc.i4.1
		/* 0x000029FD 58                 */ IL_0099: add
		/* 0x000029FE 0A                 */ IL_009a: stloc.0
		/* 0x000029FF 06                 */ IL_009b: ldloc.0
		/* 0x00002A00 03                 */ IL_009c: ldarg.1
		/* 0x00002A01 6F31000006         */ IL_009d: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x00002A06 6F6E00000A         */ IL_00a2: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<string>::get_Count() /* 0A00006E */
		/* 0x00002A0B 17                 */ IL_00a7: ldc.i4.1
		/* 0x00002A0C 59                 */ IL_00a8: sub
		/* 0x00002A0D 3294               */ IL_00a9: blt.s IL_003f
		/* 0x00002A0F 2A                 */ IL_00ab: ret
		/* 0x00002A10 03                 */ IL_00ac: ldarg.1
		/* 0x00002A11 6F31000006         */ IL_00ad: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x00002A16 6F7500000A         */ IL_00b2: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A000075 */
		/* 0x00002A1B 1304               */ IL_00b7: stloc.s 4
		/* 0x00002A1D 2B12               */ IL_00b9: br.s IL_00cd
		/* 0x00002A1F 1104               */ IL_00bb: ldloc.s 4
		/* 0x00002A21 6F7600000A         */ IL_00bd: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A000076 */
		/* 0x00002A26 0D                 */ IL_00c2: stloc.3
		/* 0x00002A27 02                 */ IL_00c3: ldarg.0
		/* 0x00002A28 1F41               */ IL_00c4: ldc.i4.s 65
		/* 0x00002A2A 09                 */ IL_00c6: ldloc.3
		/* 0x00002A2B 28B9000006         */ IL_00c7: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00002A30 26                 */ IL_00cc: pop
		/* 0x00002A31 1104               */ IL_00cd: ldloc.s 4
		/* 0x00002A33 6F7700000A         */ IL_00cf: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00002A38 2DE5               */ IL_00d4: brtrue.s IL_00bb
		/* 0x00002A3A DE0C               */ IL_00d6: leave.s IL_00e4
		/* 0x00002A3C 1104               */ IL_00d8: ldloc.s 4
		/* 0x00002A3E 2C07               */ IL_00da: brfalse.s IL_00e3
		/* 0x00002A40 1104               */ IL_00dc: ldloc.s 4
		/* 0x00002A42 6F6D00000A         */ IL_00de: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00002A47 DC                 */ IL_00e3: endfinally
		/* 0x00002A48 2A                 */ IL_00e4: ret

		.try IL_00b9-IL_00d8 finally IL_00d8-IL_00e4
	} // end of method Renderer::RenderExplanations

} // end of class AspenTech.Visualisation.Controls.Assistant.Renderer

.class /* 0200000B */ public auto ansi abstract beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistBasic
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000013 */ private string '<Id>k__BackingField'
	.custom /* 0C00001C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000014 */ private class [System.Xml.Linq]System.Xml.Linq.XName '<RootElementName>k__BackingField'
	.custom /* 0C00001D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000028 */ public hidebysig specialname 
		instance string get_Id () cil managed 
	{
		.custom /* 0C000037 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a68
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002A68 02                 */ IL_0000: ldarg.0
		/* 0x00002A69 7B13000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistBasic::'<Id>k__BackingField' /* 04000013 */
		/* 0x00002A6E 2A                 */ IL_0006: ret
	} // end of method AssistBasic::get_Id

	.method /* 06000029 */ public hidebysig specialname 
		instance void set_Id (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00003C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a70
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002A70 02                 */ IL_0000: ldarg.0
		/* 0x00002A71 03                 */ IL_0001: ldarg.1
		/* 0x00002A72 7D13000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistBasic::'<Id>k__BackingField' /* 04000013 */
		/* 0x00002A77 2A                 */ IL_0007: ret
	} // end of method AssistBasic::set_Id

	.method /* 0600002A */ assembly hidebysig specialname 
		instance class [System.Xml.Linq]System.Xml.Linq.XName get_RootElementName () cil managed 
	{
		.custom /* 0C000040 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a79
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002A79 02                 */ IL_0000: ldarg.0
		/* 0x00002A7A 7B14000004         */ IL_0001: ldfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.AssistBasic::'<RootElementName>k__BackingField' /* 04000014 */
		/* 0x00002A7F 2A                 */ IL_0006: ret
	} // end of method AssistBasic::get_RootElementName

	.method /* 0600002B */ private hidebysig specialname 
		instance void set_RootElementName (
			class [System.Xml.Linq]System.Xml.Linq.XName 'value'
		) cil managed 
	{
		.custom /* 0C000042 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a81
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002A81 02                 */ IL_0000: ldarg.0
		/* 0x00002A82 03                 */ IL_0001: ldarg.1
		/* 0x00002A83 7D14000004         */ IL_0002: stfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.AssistBasic::'<RootElementName>k__BackingField' /* 04000014 */
		/* 0x00002A88 2A                 */ IL_0007: ret
	} // end of method AssistBasic::set_RootElementName

	.method /* 0600002C */ assembly hidebysig newslot strict abstract virtual 
		instance class [System.Xml.Linq]System.Xml.Linq.XElement DehydrateToXml () cil managed 
	{
	} // end of method AssistBasic::DehydrateToXml

	.method /* 0600002D */ assembly hidebysig newslot strict abstract virtual 
		instance void HydrateFromXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement root
		) cil managed 
	{
	} // end of method AssistBasic::HydrateFromXml

	.method /* 0600002E */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class [System.Xml.Linq]System.Xml.Linq.XName rootElementName
		) cil managed 
	{
		// Method begins at RVA 0x2a8a
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x00002A8A 02                 */ IL_0000: ldarg.0
		/* 0x00002A8B 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00002A90 02                 */ IL_0006: ldarg.0
		/* 0x00002A91 03                 */ IL_0007: ldarg.1
		/* 0x00002A92 282B000006         */ IL_0008: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_RootElementName(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0600002B */
		/* 0x00002A97 2A                 */ IL_000d: ret
	} // end of method AssistBasic::.ctor

	// Properties
	.property /* 17000006 */ instance string Id()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_Id(string)
	}
	.property /* 17000007 */ instance class [System.Xml.Linq]System.Xml.Linq.XName RootElementName()
	{
		.get instance class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_RootElementName()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_RootElementName(class [System.Xml.Linq]System.Xml.Linq.XName)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistBasic

.class /* 0200000C */ public auto ansi abstract beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistBase
	extends AspenTech.Visualisation.Controls.Assistant.AssistBasic
{
	// Fields
	.field /* 04000015 */ private string '<Caption>k__BackingField'
	.custom /* 0C00001E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000016 */ private class [mscorlib]System.Collections.Generic.IList`1<string> '<Explanation>k__BackingField'
	.custom /* 0C00001F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000017 */ private class AspenTech.Visualisation.Controls.Assistant.AssistRoot '<Root>k__BackingField'
	.custom /* 0C000020 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600002F */ public hidebysig specialname 
		instance string get_Caption () cil managed 
	{
		.custom /* 0C000049 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a99
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002A99 02                 */ IL_0000: ldarg.0
		/* 0x00002A9A 7B15000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistBase::'<Caption>k__BackingField' /* 04000015 */
		/* 0x00002A9F 2A                 */ IL_0006: ret
	} // end of method AssistBase::get_Caption

	.method /* 06000030 */ public hidebysig specialname 
		instance void set_Caption (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00004B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2aa1
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002AA1 02                 */ IL_0000: ldarg.0
		/* 0x00002AA2 03                 */ IL_0001: ldarg.1
		/* 0x00002AA3 7D15000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistBase::'<Caption>k__BackingField' /* 04000015 */
		/* 0x00002AA8 2A                 */ IL_0007: ret
	} // end of method AssistBase::set_Caption

	.method /* 06000031 */ public hidebysig specialname 
		instance class [mscorlib]System.Collections.Generic.IList`1<string> get_Explanation () cil managed 
	{
		.custom /* 0C00004C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2aaa
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002AAA 02                 */ IL_0000: ldarg.0
		/* 0x00002AAB 7B16000004         */ IL_0001: ldfld class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::'<Explanation>k__BackingField' /* 04000016 */
		/* 0x00002AB0 2A                 */ IL_0006: ret
	} // end of method AssistBase::get_Explanation

	.method /* 06000032 */ private hidebysig specialname 
		instance void set_Explanation (
			class [mscorlib]System.Collections.Generic.IList`1<string> 'value'
		) cil managed 
	{
		.custom /* 0C00004D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2ab2
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002AB2 02                 */ IL_0000: ldarg.0
		/* 0x00002AB3 03                 */ IL_0001: ldarg.1
		/* 0x00002AB4 7D16000004         */ IL_0002: stfld class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::'<Explanation>k__BackingField' /* 04000016 */
		/* 0x00002AB9 2A                 */ IL_0007: ret
	} // end of method AssistBase::set_Explanation

	.method /* 06000033 */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot get_Root () cil managed 
	{
		.custom /* 0C00004E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2abb
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002ABB 02                 */ IL_0000: ldarg.0
		/* 0x00002ABC 7B17000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::'<Root>k__BackingField' /* 04000017 */
		/* 0x00002AC1 2A                 */ IL_0006: ret
	} // end of method AssistBase::get_Root

	.method /* 06000034 */ family hidebysig specialname 
		instance void set_Root (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot 'value'
		) cil managed 
	{
		.custom /* 0C00004F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2ac3
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002AC3 02                 */ IL_0000: ldarg.0
		/* 0x00002AC4 03                 */ IL_0001: ldarg.1
		/* 0x00002AC5 7D17000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::'<Root>k__BackingField' /* 04000017 */
		/* 0x00002ACA 2A                 */ IL_0007: ret
	} // end of method AssistBase::set_Root

	.method /* 06000035 */ family hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot root,
			class [System.Xml.Linq]System.Xml.Linq.XName rootElementName
		) cil managed 
	{
		// Method begins at RVA 0x2acc
		// Header size: 1
		// Code size: 33 (0x21)
		.maxstack 8

		/* 0x00002ACC 02                 */ IL_0000: ldarg.0
		/* 0x00002ACD 04                 */ IL_0001: ldarg.2
		/* 0x00002ACE 282E000006         */ IL_0002: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0600002E */
		/* 0x00002AD3 02                 */ IL_0007: ldarg.0
		/* 0x00002AD4 03                 */ IL_0008: ldarg.1
		/* 0x00002AD5 2834000006         */ IL_0009: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Root(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 06000034 */
		/* 0x00002ADA 02                 */ IL_000e: ldarg.0
		/* 0x00002ADB 737800000A         */ IL_000f: newobj instance void class [mscorlib]System.Collections.Generic.List`1<string>::.ctor() /* 0A000078 */
		/* 0x00002AE0 2832000006         */ IL_0014: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Explanation(class [mscorlib]System.Collections.Generic.IList`1<string>) /* 06000032 */
		/* 0x00002AE5 02                 */ IL_0019: ldarg.0
		/* 0x00002AE6 14                 */ IL_001a: ldnull
		/* 0x00002AE7 2830000006         */ IL_001b: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x00002AEC 2A                 */ IL_0020: ret
	} // end of method AssistBase::.ctor

	.method /* 06000036 */ family hidebysig 
		instance void ExplanationsToXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement parent
		) cil managed 
	{
		// Method begins at RVA 0x2af0
		// Header size: 12
		// Code size: 59 (0x3b)
		.maxstack 4
		.locals /* 1100000D */ init (
			[0] string,
			[1] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>
		)

		/* 0x00002AF0 02                 */ IL_0000: ldarg.0
		/* 0x00002AF1 2831000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x00002AF6 6F7500000A         */ IL_0006: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A000075 */
		/* 0x00002AFB 0B                 */ IL_000b: stloc.1
		/* 0x00002AFC 2B18               */ IL_000c: br.s IL_0026
		/* 0x00002AFE 07                 */ IL_000e: ldloc.1
		/* 0x00002AFF 6F7600000A         */ IL_000f: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A000076 */
		/* 0x00002B04 0A                 */ IL_0014: stloc.0
		/* 0x00002B05 03                 */ IL_0015: ldarg.1
		/* 0x00002B06 7E61000004         */ IL_0016: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Explanation /* 04000061 */
		/* 0x00002B0B 06                 */ IL_001b: ldloc.0
		/* 0x00002B0C 737900000A         */ IL_001c: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x00002B11 6F7A00000A         */ IL_0021: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object) /* 0A00007A */
		/* 0x00002B16 07                 */ IL_0026: ldloc.1
		/* 0x00002B17 6F7700000A         */ IL_0027: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00002B1C 2DE0               */ IL_002c: brtrue.s IL_000e
		/* 0x00002B1E DE0A               */ IL_002e: leave.s IL_003a
		/* 0x00002B20 07                 */ IL_0030: ldloc.1
		/* 0x00002B21 2C06               */ IL_0031: brfalse.s IL_0039
		/* 0x00002B23 07                 */ IL_0033: ldloc.1
		/* 0x00002B24 6F6D00000A         */ IL_0034: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00002B29 DC                 */ IL_0039: endfinally
		/* 0x00002B2A 2A                 */ IL_003a: ret

		.try IL_000c-IL_0030 finally IL_0030-IL_003a
	} // end of method AssistBase::ExplanationsToXml

	.method /* 06000037 */ family hidebysig 
		instance void ExplanationsFromXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement parent
		) cil managed 
	{
		// Method begins at RVA 0x2b48
		// Header size: 12
		// Code size: 64 (0x40)
		.maxstack 2
		.locals /* 1100000E */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[1] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>
		)

		/* 0x00002B48 03                 */ IL_0000: ldarg.1
		/* 0x00002B49 7E61000004         */ IL_0001: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Explanation /* 04000061 */
		/* 0x00002B4E 6F7B00000A         */ IL_0006: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement> [System.Xml.Linq]System.Xml.Linq.XContainer::Elements(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00007B */
		/* 0x00002B53 6F7C00000A         */ IL_000b: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::GetEnumerator() /* 0A00007C */
		/* 0x00002B58 0B                 */ IL_0010: stloc.1
		/* 0x00002B59 2B18               */ IL_0011: br.s IL_002b
		/* 0x00002B5B 07                 */ IL_0013: ldloc.1
		/* 0x00002B5C 6F7D00000A         */ IL_0014: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::get_Current() /* 0A00007D */
		/* 0x00002B61 0A                 */ IL_0019: stloc.0
		/* 0x00002B62 02                 */ IL_001a: ldarg.0
		/* 0x00002B63 2831000006         */ IL_001b: call instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x00002B68 06                 */ IL_0020: ldloc.0
		/* 0x00002B69 6F7E00000A         */ IL_0021: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XElement::get_Value() /* 0A00007E */
		/* 0x00002B6E 6F7F00000A         */ IL_0026: callvirt instance void class [mscorlib]System.Collections.Generic.ICollection`1<string>::Add(!0) /* 0A00007F */
		/* 0x00002B73 07                 */ IL_002b: ldloc.1
		/* 0x00002B74 6F7700000A         */ IL_002c: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00002B79 2DE0               */ IL_0031: brtrue.s IL_0013
		/* 0x00002B7B DE0A               */ IL_0033: leave.s IL_003f
		/* 0x00002B7D 07                 */ IL_0035: ldloc.1
		/* 0x00002B7E 2C06               */ IL_0036: brfalse.s IL_003e
		/* 0x00002B80 07                 */ IL_0038: ldloc.1
		/* 0x00002B81 6F6D00000A         */ IL_0039: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00002B86 DC                 */ IL_003e: endfinally
		/* 0x00002B87 2A                 */ IL_003f: ret

		.try IL_0011-IL_0035 finally IL_0035-IL_003f
	} // end of method AssistBase::ExplanationsFromXml

	.method /* 06000038 */ public hidebysig 
		instance void Change () cil managed 
	{
		// Method begins at RVA 0x2ba4
		// Header size: 1
		// Code size: 37 (0x25)
		.maxstack 8

		/* 0x00002BA4 02                 */ IL_0000: ldarg.0
		/* 0x00002BA5 2833000006         */ IL_0001: call instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x00002BAA 2C1C               */ IL_0006: brfalse.s IL_0024
		/* 0x00002BAC 02                 */ IL_0008: ldarg.0
		/* 0x00002BAD 2833000006         */ IL_0009: call instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x00002BB2 17                 */ IL_000e: ldc.i4.1
		/* 0x00002BB3 6F3E000006         */ IL_000f: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool) /* 0600003E */
		/* 0x00002BB8 02                 */ IL_0014: ldarg.0
		/* 0x00002BB9 2833000006         */ IL_0015: call instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x00002BBE 283800000A         */ IL_001a: call valuetype [mscorlib]System.DateTime [mscorlib]System.DateTime::get_Now() /* 0A000038 */
		/* 0x00002BC3 6F4E000006         */ IL_001f: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_BuildDate(valuetype [mscorlib]System.DateTime) /* 0600004E */
		/* 0x00002BC8 2A                 */ IL_0024: ret
	} // end of method AssistBase::Change

	// Properties
	.property /* 17000008 */ instance string Caption()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string)
	}
	.property /* 17000009 */ instance class [mscorlib]System.Collections.Generic.IList`1<string> Explanation()
	{
		.get instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Explanation(class [mscorlib]System.Collections.Generic.IList`1<string>)
	}
	.property /* 1700000A */ instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot Root()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Root(class AspenTech.Visualisation.Controls.Assistant.AssistRoot)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistBase

.class /* 0200000D */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistRoot
	extends AspenTech.Visualisation.Controls.Assistant.AssistBase
{
	// Fields
	.field /* 04000018 */ private class AspenTech.Visualisation.Controls.Assistant.AssistScreens '<Screens>k__BackingField'
	.custom /* 0C000021 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000019 */ private string '<Filename>k__BackingField'
	.custom /* 0C000022 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001A */ private bool '<Changed>k__BackingField'
	.custom /* 0C000023 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001B */ private string '<First>k__BackingField'
	.custom /* 0C000024 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001C */ private string '<Author>k__BackingField'
	.custom /* 0C000026 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001D */ private string '<AuthorId>k__BackingField'
	.custom /* 0C000027 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001E */ private string '<Version>k__BackingField'
	.custom /* 0C000029 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001F */ private string '<ModifierId>k__BackingField'
	.custom /* 0C00002B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000020 */ private string '<CurrentUserId>k__BackingField'
	.custom /* 0C00002C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000021 */ private string '<Copyright>k__BackingField'
	.custom /* 0C00002D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000022 */ private valuetype [mscorlib]System.DateTime '<BuildDate>k__BackingField'
	.custom /* 0C00002E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000023 */ private class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> '<Translations>k__BackingField'
	.custom /* 0C00002F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000039 */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens get_Screens () cil managed 
	{
		.custom /* 0C000050 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2bca
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002BCA 02                 */ IL_0000: ldarg.0
		/* 0x00002BCB 7B18000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Screens>k__BackingField' /* 04000018 */
		/* 0x00002BD0 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Screens

	.method /* 0600003A */ private hidebysig specialname 
		instance void set_Screens (
			class AspenTech.Visualisation.Controls.Assistant.AssistScreens 'value'
		) cil managed 
	{
		.custom /* 0C000051 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2bd2
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002BD2 02                 */ IL_0000: ldarg.0
		/* 0x00002BD3 03                 */ IL_0001: ldarg.1
		/* 0x00002BD4 7D18000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Screens>k__BackingField' /* 04000018 */
		/* 0x00002BD9 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Screens

	.method /* 0600003B */ public hidebysig specialname 
		instance string get_Filename () cil managed 
	{
		.custom /* 0C000053 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2bdb
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002BDB 02                 */ IL_0000: ldarg.0
		/* 0x00002BDC 7B19000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Filename>k__BackingField' /* 04000019 */
		/* 0x00002BE1 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Filename

	.method /* 0600003C */ private hidebysig specialname 
		instance void set_Filename (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000055 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2be3
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002BE3 02                 */ IL_0000: ldarg.0
		/* 0x00002BE4 03                 */ IL_0001: ldarg.1
		/* 0x00002BE5 7D19000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Filename>k__BackingField' /* 04000019 */
		/* 0x00002BEA 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Filename

	.method /* 0600003D */ public hidebysig specialname 
		instance bool get_Changed () cil managed 
	{
		.custom /* 0C000057 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2bec
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002BEC 02                 */ IL_0000: ldarg.0
		/* 0x00002BED 7B1A000004         */ IL_0001: ldfld bool AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Changed>k__BackingField' /* 0400001A */
		/* 0x00002BF2 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Changed

	.method /* 0600003E */ public hidebysig specialname 
		instance void set_Changed (
			bool 'value'
		) cil managed 
	{
		.custom /* 0C000058 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2bf4
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002BF4 02                 */ IL_0000: ldarg.0
		/* 0x00002BF5 03                 */ IL_0001: ldarg.1
		/* 0x00002BF6 7D1A000004         */ IL_0002: stfld bool AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Changed>k__BackingField' /* 0400001A */
		/* 0x00002BFB 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Changed

	.method /* 0600003F */ public hidebysig specialname 
		instance string get_First () cil managed 
	{
		.custom /* 0C000059 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2bfd
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002BFD 02                 */ IL_0000: ldarg.0
		/* 0x00002BFE 7B1B000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<First>k__BackingField' /* 0400001B */
		/* 0x00002C03 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_First

	.method /* 06000040 */ public hidebysig specialname 
		instance void set_First (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00005A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c05
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C05 02                 */ IL_0000: ldarg.0
		/* 0x00002C06 03                 */ IL_0001: ldarg.1
		/* 0x00002C07 7D1B000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<First>k__BackingField' /* 0400001B */
		/* 0x00002C0C 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_First

	.method /* 06000041 */ public hidebysig specialname 
		instance string get_Author () cil managed 
	{
		.custom /* 0C00005B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c0e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C0E 02                 */ IL_0000: ldarg.0
		/* 0x00002C0F 7B1C000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Author>k__BackingField' /* 0400001C */
		/* 0x00002C14 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Author

	.method /* 06000042 */ public hidebysig specialname 
		instance void set_Author (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00005C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c16
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C16 02                 */ IL_0000: ldarg.0
		/* 0x00002C17 03                 */ IL_0001: ldarg.1
		/* 0x00002C18 7D1C000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Author>k__BackingField' /* 0400001C */
		/* 0x00002C1D 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Author

	.method /* 06000043 */ public hidebysig specialname 
		instance string get_AuthorId () cil managed 
	{
		.custom /* 0C00005D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c1f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C1F 02                 */ IL_0000: ldarg.0
		/* 0x00002C20 7B1D000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<AuthorId>k__BackingField' /* 0400001D */
		/* 0x00002C25 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_AuthorId

	.method /* 06000044 */ public hidebysig specialname 
		instance void set_AuthorId (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00005E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c27
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C27 02                 */ IL_0000: ldarg.0
		/* 0x00002C28 03                 */ IL_0001: ldarg.1
		/* 0x00002C29 7D1D000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<AuthorId>k__BackingField' /* 0400001D */
		/* 0x00002C2E 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_AuthorId

	.method /* 06000045 */ public hidebysig specialname 
		instance string get_Version () cil managed 
	{
		.custom /* 0C00005F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c30
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C30 02                 */ IL_0000: ldarg.0
		/* 0x00002C31 7B1E000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Version>k__BackingField' /* 0400001E */
		/* 0x00002C36 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Version

	.method /* 06000046 */ public hidebysig specialname 
		instance void set_Version (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000060 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c38
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C38 02                 */ IL_0000: ldarg.0
		/* 0x00002C39 03                 */ IL_0001: ldarg.1
		/* 0x00002C3A 7D1E000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Version>k__BackingField' /* 0400001E */
		/* 0x00002C3F 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Version

	.method /* 06000047 */ public hidebysig specialname 
		instance string get_ModifierId () cil managed 
	{
		.custom /* 0C000062 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c41
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C41 02                 */ IL_0000: ldarg.0
		/* 0x00002C42 7B1F000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<ModifierId>k__BackingField' /* 0400001F */
		/* 0x00002C47 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_ModifierId

	.method /* 06000048 */ public hidebysig specialname 
		instance void set_ModifierId (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000064 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c49
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C49 02                 */ IL_0000: ldarg.0
		/* 0x00002C4A 03                 */ IL_0001: ldarg.1
		/* 0x00002C4B 7D1F000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<ModifierId>k__BackingField' /* 0400001F */
		/* 0x00002C50 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_ModifierId

	.method /* 06000049 */ public hidebysig specialname 
		instance string get_CurrentUserId () cil managed 
	{
		.custom /* 0C000066 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c52
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C52 02                 */ IL_0000: ldarg.0
		/* 0x00002C53 7B20000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<CurrentUserId>k__BackingField' /* 04000020 */
		/* 0x00002C58 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_CurrentUserId

	.method /* 0600004A */ public hidebysig specialname 
		instance void set_CurrentUserId (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000067 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c5a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C5A 02                 */ IL_0000: ldarg.0
		/* 0x00002C5B 03                 */ IL_0001: ldarg.1
		/* 0x00002C5C 7D20000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<CurrentUserId>k__BackingField' /* 04000020 */
		/* 0x00002C61 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_CurrentUserId

	.method /* 0600004B */ public hidebysig specialname 
		instance string get_Copyright () cil managed 
	{
		.custom /* 0C000069 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c63
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C63 02                 */ IL_0000: ldarg.0
		/* 0x00002C64 7B21000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Copyright>k__BackingField' /* 04000021 */
		/* 0x00002C69 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Copyright

	.method /* 0600004C */ public hidebysig specialname 
		instance void set_Copyright (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00006B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c6b
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C6B 02                 */ IL_0000: ldarg.0
		/* 0x00002C6C 03                 */ IL_0001: ldarg.1
		/* 0x00002C6D 7D21000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Copyright>k__BackingField' /* 04000021 */
		/* 0x00002C72 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Copyright

	.method /* 0600004D */ public hidebysig specialname 
		instance valuetype [mscorlib]System.DateTime get_BuildDate () cil managed 
	{
		.custom /* 0C00006C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c74
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C74 02                 */ IL_0000: ldarg.0
		/* 0x00002C75 7B22000004         */ IL_0001: ldfld valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<BuildDate>k__BackingField' /* 04000022 */
		/* 0x00002C7A 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_BuildDate

	.method /* 0600004E */ public hidebysig specialname 
		instance void set_BuildDate (
			valuetype [mscorlib]System.DateTime 'value'
		) cil managed 
	{
		.custom /* 0C00006D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c7c
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C7C 02                 */ IL_0000: ldarg.0
		/* 0x00002C7D 03                 */ IL_0001: ldarg.1
		/* 0x00002C7E 7D22000004         */ IL_0002: stfld valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<BuildDate>k__BackingField' /* 04000022 */
		/* 0x00002C83 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_BuildDate

	.method /* 0600004F */ public hidebysig specialname 
		instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> get_Translations () cil managed 
	{
		.custom /* 0C00006F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c85
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002C85 02                 */ IL_0000: ldarg.0
		/* 0x00002C86 7B23000004         */ IL_0001: ldfld class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Translations>k__BackingField' /* 04000023 */
		/* 0x00002C8B 2A                 */ IL_0006: ret
	} // end of method AssistRoot::get_Translations

	.method /* 06000050 */ private hidebysig specialname 
		instance void set_Translations (
			class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> 'value'
		) cil managed 
	{
		.custom /* 0C000071 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2c8d
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002C8D 02                 */ IL_0000: ldarg.0
		/* 0x00002C8E 03                 */ IL_0001: ldarg.1
		/* 0x00002C8F 7D23000004         */ IL_0002: stfld class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::'<Translations>k__BackingField' /* 04000023 */
		/* 0x00002C94 2A                 */ IL_0007: ret
	} // end of method AssistRoot::set_Translations

	.method /* 06000051 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2c98
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 4
		.locals /* 1100000F */ init (
			[0] valuetype [mscorlib]System.Guid
		)

		/* 0x00002C98 02                 */ IL_0000: ldarg.0
		/* 0x00002C99 288000000A         */ IL_0001: call valuetype [mscorlib]System.Guid [mscorlib]System.Guid::NewGuid() /* 0A000080 */
		/* 0x00002C9E 0A                 */ IL_0006: stloc.0
		/* 0x00002C9F 1200               */ IL_0007: ldloca.s 0
		/* 0x00002CA1 FE161D000001       */ IL_0009: constrained. [mscorlib]System.Guid /* 0100001D */
		/* 0x00002CA7 6F6000000A         */ IL_000f: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00002CAC 722F020070         */ IL_0014: ldstr " " /* 7000022F */
		/* 0x00002CB1 286200000A         */ IL_0019: call string [mscorlib]System.Environment::get_UserName() /* 0A000062 */
		/* 0x00002CB6 286300000A         */ IL_001e: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000063 */
		/* 0x00002CBB 2852000006         */ IL_0023: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::.ctor(string) /* 06000052 */
		/* 0x00002CC0 2A                 */ IL_0028: ret
	} // end of method AssistRoot::.ctor

	.method /* 06000052 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			string currentUserId
		) cil managed 
	{
		// Method begins at RVA 0x2cd0
		// Header size: 12
		// Code size: 114 (0x72)
		.maxstack 3

		/* 0x00002CD0 02                 */ IL_0000: ldarg.0
		/* 0x00002CD1 14                 */ IL_0001: ldnull
		/* 0x00002CD2 7E5D000004         */ IL_0002: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Assistant /* 0400005D */
		/* 0x00002CD7 2835000006         */ IL_0007: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot, class [System.Xml.Linq]System.Xml.Linq.XName) /* 06000035 */
		/* 0x00002CDC 02                 */ IL_000c: ldarg.0
		/* 0x00002CDD 738100000A         */ IL_000d: newobj instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::.ctor() /* 0A000081 */
		/* 0x00002CE2 2850000006         */ IL_0012: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Translations(class [mscorlib]System.Collections.Generic.IDictionary`2<string, string>) /* 06000050 */
		/* 0x00002CE7 02                 */ IL_0017: ldarg.0
		/* 0x00002CE8 7233020070         */ IL_0018: ldstr "A1" /* 70000233 */
		/* 0x00002CED 2829000006         */ IL_001d: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_Id(string) /* 06000029 */
		/* 0x00002CF2 02                 */ IL_0022: ldarg.0
		/* 0x00002CF3 7239020070         */ IL_0023: ldstr "Assistant " /* 70000239 */
		/* 0x00002CF8 02                 */ IL_0028: ldarg.0
		/* 0x00002CF9 2828000006         */ IL_0029: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00002CFE 283500000A         */ IL_002e: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x00002D03 2830000006         */ IL_0033: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x00002D08 02                 */ IL_0038: ldarg.0
		/* 0x00002D09 724F020070         */ IL_0039: ldstr "Copyright Aspen Technology Inc" /* 7000024F */
		/* 0x00002D0E 284C000006         */ IL_003e: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Copyright(string) /* 0600004C */
		/* 0x00002D13 02                 */ IL_0043: ldarg.0
		/* 0x00002D14 16                 */ IL_0044: ldc.i4.0
		/* 0x00002D15 283E000006         */ IL_0045: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool) /* 0600003E */
		/* 0x00002D1A 02                 */ IL_004a: ldarg.0
		/* 0x00002D1B 03                 */ IL_004b: ldarg.1
		/* 0x00002D1C 2844000006         */ IL_004c: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_AuthorId(string) /* 06000044 */
		/* 0x00002D21 02                 */ IL_0051: ldarg.0
		/* 0x00002D22 03                 */ IL_0052: ldarg.1
		/* 0x00002D23 2848000006         */ IL_0053: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_ModifierId(string) /* 06000048 */
		/* 0x00002D28 02                 */ IL_0058: ldarg.0
		/* 0x00002D29 03                 */ IL_0059: ldarg.1
		/* 0x00002D2A 284A000006         */ IL_005a: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_CurrentUserId(string) /* 0600004A */
		/* 0x00002D2F 02                 */ IL_005f: ldarg.0
		/* 0x00002D30 02                 */ IL_0060: ldarg.0
		/* 0x00002D31 2834000006         */ IL_0061: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Root(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 06000034 */
		/* 0x00002D36 02                 */ IL_0066: ldarg.0
		/* 0x00002D37 735B000006         */ IL_0067: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistScreens::.ctor() /* 0600005B */
		/* 0x00002D3C 283A000006         */ IL_006c: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Screens(class AspenTech.Visualisation.Controls.Assistant.AssistScreens) /* 0600003A */
		/* 0x00002D41 2A                 */ IL_0071: ret
	} // end of method AssistRoot::.ctor

	.method /* 06000053 */ public hidebysig 
		instance void Save (
			bool saveAs
		) cil managed 
	{
		// Method begins at RVA 0x2d50
		// Header size: 12
		// Code size: 240 (0xf0)
		.maxstack 4
		.locals /* 11000010 */ init (
			[0] class [PresentationFramework]Microsoft.Win32.SaveFileDialog,
			[1] class [PresentationFramework]Microsoft.Win32.SaveFileDialog,
			[2] string[],
			[3] valuetype [mscorlib]System.Nullable`1<bool>
		)

		/* 0x00002D50 03                 */ IL_0000: ldarg.1
		/* 0x00002D51 2D10               */ IL_0001: brtrue.s IL_0013
		/* 0x00002D53 02                 */ IL_0003: ldarg.0
		/* 0x00002D54 283B000006         */ IL_0004: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002D59 282C00000A         */ IL_0009: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00002D5E 39C4000000         */ IL_000e: brfalse IL_00d7
		/* 0x00002D63 738200000A         */ IL_0013: newobj instance void [PresentationFramework]Microsoft.Win32.SaveFileDialog::.ctor() /* 0A000082 */
		/* 0x00002D68 0B                 */ IL_0018: stloc.1
		/* 0x00002D69 07                 */ IL_0019: ldloc.1
		/* 0x00002D6A 728D020070         */ IL_001a: ldstr "Save assistant definition" /* 7000028D */
		/* 0x00002D6F 6F8300000A         */ IL_001f: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_Title(string) /* 0A000083 */
		/* 0x00002D74 07                 */ IL_0024: ldloc.1
		/* 0x00002D75 1F09               */ IL_0025: ldc.i4.s 9
		/* 0x00002D77 8D45000001         */ IL_0027: newarr [mscorlib]System.String /* 01000045 */
		/* 0x00002D7C 0C                 */ IL_002c: stloc.2
		/* 0x00002D7D 08                 */ IL_002d: ldloc.2
		/* 0x00002D7E 16                 */ IL_002e: ldc.i4.0
		/* 0x00002D7F 72C1020070         */ IL_002f: ldstr "Assistant files (*." /* 700002C1 */
		/* 0x00002D84 A2                 */ IL_0034: stelem.ref
		/* 0x00002D85 08                 */ IL_0035: ldloc.2
		/* 0x00002D86 17                 */ IL_0036: ldc.i4.1
		/* 0x00002D87 7E77000004         */ IL_0037: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00002D8C A2                 */ IL_003c: stelem.ref
		/* 0x00002D8D 08                 */ IL_003d: ldloc.2
		/* 0x00002D8E 18                 */ IL_003e: ldc.i4.2
		/* 0x00002D8F 72E9020070         */ IL_003f: ldstr ",*." /* 700002E9 */
		/* 0x00002D94 A2                 */ IL_0044: stelem.ref
		/* 0x00002D95 08                 */ IL_0045: ldloc.2
		/* 0x00002D96 19                 */ IL_0046: ldc.i4.3
		/* 0x00002D97 7E78000004         */ IL_0047: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtensionExtended /* 04000078 */
		/* 0x00002D9C A2                 */ IL_004c: stelem.ref
		/* 0x00002D9D 08                 */ IL_004d: ldloc.2
		/* 0x00002D9E 1A                 */ IL_004e: ldc.i4.4
		/* 0x00002D9F 72F1020070         */ IL_004f: ldstr ")|*." /* 700002F1 */
		/* 0x00002DA4 A2                 */ IL_0054: stelem.ref
		/* 0x00002DA5 08                 */ IL_0055: ldloc.2
		/* 0x00002DA6 1B                 */ IL_0056: ldc.i4.5
		/* 0x00002DA7 7E77000004         */ IL_0057: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00002DAC A2                 */ IL_005c: stelem.ref
		/* 0x00002DAD 08                 */ IL_005d: ldloc.2
		/* 0x00002DAE 1C                 */ IL_005e: ldc.i4.6
		/* 0x00002DAF 72E9020070         */ IL_005f: ldstr ",*." /* 700002E9 */
		/* 0x00002DB4 A2                 */ IL_0064: stelem.ref
		/* 0x00002DB5 08                 */ IL_0065: ldloc.2
		/* 0x00002DB6 1D                 */ IL_0066: ldc.i4.7
		/* 0x00002DB7 7E78000004         */ IL_0067: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtensionExtended /* 04000078 */
		/* 0x00002DBC A2                 */ IL_006c: stelem.ref
		/* 0x00002DBD 08                 */ IL_006d: ldloc.2
		/* 0x00002DBE 1E                 */ IL_006e: ldc.i4.8
		/* 0x00002DBF 72FB020070         */ IL_006f: ldstr "|All files (*.*)|*.*" /* 700002FB */
		/* 0x00002DC4 A2                 */ IL_0074: stelem.ref
		/* 0x00002DC5 08                 */ IL_0075: ldloc.2
		/* 0x00002DC6 286A00000A         */ IL_0076: call string [mscorlib]System.String::Concat(string[]) /* 0A00006A */
		/* 0x00002DCB 6F8400000A         */ IL_007b: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_Filter(string) /* 0A000084 */
		/* 0x00002DD0 07                 */ IL_0080: ldloc.1
		/* 0x00002DD1 16                 */ IL_0081: ldc.i4.0
		/* 0x00002DD2 6F8500000A         */ IL_0082: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_FilterIndex(int32) /* 0A000085 */
		/* 0x00002DD7 07                 */ IL_0087: ldloc.1
		/* 0x00002DD8 02                 */ IL_0088: ldarg.0
		/* 0x00002DD9 283B000006         */ IL_0089: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002DDE 6F8600000A         */ IL_008e: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_FileName(string) /* 0A000086 */
		/* 0x00002DE3 07                 */ IL_0093: ldloc.1
		/* 0x00002DE4 7E77000004         */ IL_0094: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00002DE9 6F8700000A         */ IL_0099: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_DefaultExt(string) /* 0A000087 */
		/* 0x00002DEE 07                 */ IL_009e: ldloc.1
		/* 0x00002DEF 17                 */ IL_009f: ldc.i4.1
		/* 0x00002DF0 6F8800000A         */ IL_00a0: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_CheckPathExists(bool) /* 0A000088 */
		/* 0x00002DF5 07                 */ IL_00a5: ldloc.1
		/* 0x00002DF6 16                 */ IL_00a6: ldc.i4.0
		/* 0x00002DF7 6F8900000A         */ IL_00a7: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_CheckFileExists(bool) /* 0A000089 */
		/* 0x00002DFC 07                 */ IL_00ac: ldloc.1
		/* 0x00002DFD 0A                 */ IL_00ad: stloc.0
		/* 0x00002DFE 06                 */ IL_00ae: ldloc.0
		/* 0x00002DFF 6F8A00000A         */ IL_00af: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]Microsoft.Win32.CommonDialog::ShowDialog() /* 0A00008A */
		/* 0x00002E04 0D                 */ IL_00b4: stloc.3
		/* 0x00002E05 1203               */ IL_00b5: ldloca.s 3
		/* 0x00002E07 288B00000A         */ IL_00b7: call instance bool valuetype [mscorlib]System.Nullable`1<bool>::get_HasValue() /* 0A00008B */
		/* 0x00002E0C 2D03               */ IL_00bc: brtrue.s IL_00c1
		/* 0x00002E0E 16                 */ IL_00be: ldc.i4.0
		/* 0x00002E0F 2B07               */ IL_00bf: br.s IL_00c8
		/* 0x00002E11 1203               */ IL_00c1: ldloca.s 3
		/* 0x00002E13 288C00000A         */ IL_00c3: call instance !0 valuetype [mscorlib]System.Nullable`1<bool>::GetValueOrDefault() /* 0A00008C */
		/* 0x00002E18 2D01               */ IL_00c8: brtrue.s IL_00cb
		/* 0x00002E1A 2A                 */ IL_00ca: ret
		/* 0x00002E1B 02                 */ IL_00cb: ldarg.0
		/* 0x00002E1C 02                 */ IL_00cc: ldarg.0
		/* 0x00002E1D 283B000006         */ IL_00cd: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002E22 283C000006         */ IL_00d2: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Filename(string) /* 0600003C */
		/* 0x00002E27 02                 */ IL_00d7: ldarg.0
		/* 0x00002E28 283B000006         */ IL_00d8: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002E2D 02                 */ IL_00dd: ldarg.0
		/* 0x00002E2E 2857000006         */ IL_00de: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::SaveString() /* 06000057 */
		/* 0x00002E33 288D00000A         */ IL_00e3: call void [mscorlib]System.IO.File::WriteAllText(string, string) /* 0A00008D */
		/* 0x00002E38 02                 */ IL_00e8: ldarg.0
		/* 0x00002E39 16                 */ IL_00e9: ldc.i4.0
		/* 0x00002E3A 283E000006         */ IL_00ea: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool) /* 0600003E */
		/* 0x00002E3F 2A                 */ IL_00ef: ret
	} // end of method AssistRoot::Save

	.method /* 06000054 */ public hidebysig 
		instance void Load (
			bool showDialog
		) cil managed 
	{
		// Method begins at RVA 0x2e4c
		// Header size: 12
		// Code size: 286 (0x11e)
		.maxstack 4
		.locals /* 11000011 */ init (
			[0] class [PresentationFramework]Microsoft.Win32.OpenFileDialog,
			[1] class [PresentationFramework]Microsoft.Win32.OpenFileDialog,
			[2] valuetype [PresentationFramework]System.Windows.MessageBoxResult,
			[3] string[],
			[4] valuetype [mscorlib]System.Nullable`1<bool>
		)

		/* 0x00002E4C 02                 */ IL_0000: ldarg.0
		/* 0x00002E4D 283D000006         */ IL_0001: call instance bool AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Changed() /* 0600003D */
		/* 0x00002E52 2C31               */ IL_0006: brfalse.s IL_0039
		/* 0x00002E54 7225030070         */ IL_0008: ldstr "Existing information not saved. Would you like to save it first?" /* 70000325 */
		/* 0x00002E59 72A8030070         */ IL_000d: ldstr "Data not saved" /* 700003A8 */
		/* 0x00002E5E 19                 */ IL_0012: ldc.i4.3
		/* 0x00002E5F 288E00000A         */ IL_0013: call valuetype [PresentationFramework]System.Windows.MessageBoxResult [PresentationFramework]System.Windows.MessageBox::Show(string, string, valuetype [PresentationFramework]System.Windows.MessageBoxButton) /* 0A00008E */
		/* 0x00002E64 0C                 */ IL_0018: stloc.2
		/* 0x00002E65 08                 */ IL_0019: ldloc.2
		/* 0x00002E66 18                 */ IL_001a: ldc.i4.2
		/* 0x00002E67 2E1B               */ IL_001b: beq.s IL_0038
		/* 0x00002E69 08                 */ IL_001d: ldloc.2
		/* 0x00002E6A 1C                 */ IL_001e: ldc.i4.6
		/* 0x00002E6B 59                 */ IL_001f: sub
		/* 0x00002E6C 4502000000         */ IL_0020: switch (
		/*              02000000         */                  IL_002f,
		/*              0C000000         */                  IL_0039)
		/* 0x00002E79 2B0A               */ IL_002d: br.s IL_0039
		/* 0x00002E7B 02                 */ IL_002f: ldarg.0
		/* 0x00002E7C 16                 */ IL_0030: ldc.i4.0
		/* 0x00002E7D 2853000006         */ IL_0031: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::Save(bool) /* 06000053 */
		/* 0x00002E82 2B01               */ IL_0036: br.s IL_0039
		/* 0x00002E84 2A                 */ IL_0038: ret
		/* 0x00002E85 03                 */ IL_0039: ldarg.1
		/* 0x00002E86 2D10               */ IL_003a: brtrue.s IL_004c
		/* 0x00002E88 02                 */ IL_003c: ldarg.0
		/* 0x00002E89 283B000006         */ IL_003d: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002E8E 282C00000A         */ IL_0042: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00002E93 39C5000000         */ IL_0047: brfalse IL_0111
		/* 0x00002E98 738F00000A         */ IL_004c: newobj instance void [PresentationFramework]Microsoft.Win32.OpenFileDialog::.ctor() /* 0A00008F */
		/* 0x00002E9D 0B                 */ IL_0051: stloc.1
		/* 0x00002E9E 07                 */ IL_0052: ldloc.1
		/* 0x00002E9F 728D020070         */ IL_0053: ldstr "Save assistant definition" /* 7000028D */
		/* 0x00002EA4 6F8300000A         */ IL_0058: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_Title(string) /* 0A000083 */
		/* 0x00002EA9 07                 */ IL_005d: ldloc.1
		/* 0x00002EAA 1F09               */ IL_005e: ldc.i4.s 9
		/* 0x00002EAC 8D45000001         */ IL_0060: newarr [mscorlib]System.String /* 01000045 */
		/* 0x00002EB1 0D                 */ IL_0065: stloc.3
		/* 0x00002EB2 09                 */ IL_0066: ldloc.3
		/* 0x00002EB3 16                 */ IL_0067: ldc.i4.0
		/* 0x00002EB4 72C1020070         */ IL_0068: ldstr "Assistant files (*." /* 700002C1 */
		/* 0x00002EB9 A2                 */ IL_006d: stelem.ref
		/* 0x00002EBA 09                 */ IL_006e: ldloc.3
		/* 0x00002EBB 17                 */ IL_006f: ldc.i4.1
		/* 0x00002EBC 7E77000004         */ IL_0070: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00002EC1 A2                 */ IL_0075: stelem.ref
		/* 0x00002EC2 09                 */ IL_0076: ldloc.3
		/* 0x00002EC3 18                 */ IL_0077: ldc.i4.2
		/* 0x00002EC4 72E9020070         */ IL_0078: ldstr ",*." /* 700002E9 */
		/* 0x00002EC9 A2                 */ IL_007d: stelem.ref
		/* 0x00002ECA 09                 */ IL_007e: ldloc.3
		/* 0x00002ECB 19                 */ IL_007f: ldc.i4.3
		/* 0x00002ECC 7E78000004         */ IL_0080: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtensionExtended /* 04000078 */
		/* 0x00002ED1 A2                 */ IL_0085: stelem.ref
		/* 0x00002ED2 09                 */ IL_0086: ldloc.3
		/* 0x00002ED3 1A                 */ IL_0087: ldc.i4.4
		/* 0x00002ED4 72F1020070         */ IL_0088: ldstr ")|*." /* 700002F1 */
		/* 0x00002ED9 A2                 */ IL_008d: stelem.ref
		/* 0x00002EDA 09                 */ IL_008e: ldloc.3
		/* 0x00002EDB 1B                 */ IL_008f: ldc.i4.5
		/* 0x00002EDC 7E77000004         */ IL_0090: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00002EE1 A2                 */ IL_0095: stelem.ref
		/* 0x00002EE2 09                 */ IL_0096: ldloc.3
		/* 0x00002EE3 1C                 */ IL_0097: ldc.i4.6
		/* 0x00002EE4 72E9020070         */ IL_0098: ldstr ",*." /* 700002E9 */
		/* 0x00002EE9 A2                 */ IL_009d: stelem.ref
		/* 0x00002EEA 09                 */ IL_009e: ldloc.3
		/* 0x00002EEB 1D                 */ IL_009f: ldc.i4.7
		/* 0x00002EEC 7E78000004         */ IL_00a0: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtensionExtended /* 04000078 */
		/* 0x00002EF1 A2                 */ IL_00a5: stelem.ref
		/* 0x00002EF2 09                 */ IL_00a6: ldloc.3
		/* 0x00002EF3 1E                 */ IL_00a7: ldc.i4.8
		/* 0x00002EF4 72FB020070         */ IL_00a8: ldstr "|All files (*.*)|*.*" /* 700002FB */
		/* 0x00002EF9 A2                 */ IL_00ad: stelem.ref
		/* 0x00002EFA 09                 */ IL_00ae: ldloc.3
		/* 0x00002EFB 286A00000A         */ IL_00af: call string [mscorlib]System.String::Concat(string[]) /* 0A00006A */
		/* 0x00002F00 6F8400000A         */ IL_00b4: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_Filter(string) /* 0A000084 */
		/* 0x00002F05 07                 */ IL_00b9: ldloc.1
		/* 0x00002F06 16                 */ IL_00ba: ldc.i4.0
		/* 0x00002F07 6F8500000A         */ IL_00bb: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_FilterIndex(int32) /* 0A000085 */
		/* 0x00002F0C 07                 */ IL_00c0: ldloc.1
		/* 0x00002F0D 17                 */ IL_00c1: ldc.i4.1
		/* 0x00002F0E 6F8900000A         */ IL_00c2: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_CheckFileExists(bool) /* 0A000089 */
		/* 0x00002F13 07                 */ IL_00c7: ldloc.1
		/* 0x00002F14 17                 */ IL_00c8: ldc.i4.1
		/* 0x00002F15 6F8800000A         */ IL_00c9: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_CheckPathExists(bool) /* 0A000088 */
		/* 0x00002F1A 07                 */ IL_00ce: ldloc.1
		/* 0x00002F1B 02                 */ IL_00cf: ldarg.0
		/* 0x00002F1C 283B000006         */ IL_00d0: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002F21 6F8600000A         */ IL_00d5: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_FileName(string) /* 0A000086 */
		/* 0x00002F26 07                 */ IL_00da: ldloc.1
		/* 0x00002F27 7E77000004         */ IL_00db: ldsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00002F2C 6F8700000A         */ IL_00e0: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_DefaultExt(string) /* 0A000087 */
		/* 0x00002F31 07                 */ IL_00e5: ldloc.1
		/* 0x00002F32 0A                 */ IL_00e6: stloc.0
		/* 0x00002F33 06                 */ IL_00e7: ldloc.0
		/* 0x00002F34 6F8A00000A         */ IL_00e8: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]Microsoft.Win32.CommonDialog::ShowDialog() /* 0A00008A */
		/* 0x00002F39 1304               */ IL_00ed: stloc.s 4
		/* 0x00002F3B 1204               */ IL_00ef: ldloca.s 4
		/* 0x00002F3D 288B00000A         */ IL_00f1: call instance bool valuetype [mscorlib]System.Nullable`1<bool>::get_HasValue() /* 0A00008B */
		/* 0x00002F42 2D03               */ IL_00f6: brtrue.s IL_00fb
		/* 0x00002F44 16                 */ IL_00f8: ldc.i4.0
		/* 0x00002F45 2B07               */ IL_00f9: br.s IL_0102
		/* 0x00002F47 1204               */ IL_00fb: ldloca.s 4
		/* 0x00002F49 288C00000A         */ IL_00fd: call instance !0 valuetype [mscorlib]System.Nullable`1<bool>::GetValueOrDefault() /* 0A00008C */
		/* 0x00002F4E 2D01               */ IL_0102: brtrue.s IL_0105
		/* 0x00002F50 2A                 */ IL_0104: ret
		/* 0x00002F51 02                 */ IL_0105: ldarg.0
		/* 0x00002F52 02                 */ IL_0106: ldarg.0
		/* 0x00002F53 283B000006         */ IL_0107: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002F58 283C000006         */ IL_010c: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Filename(string) /* 0600003C */
		/* 0x00002F5D 02                 */ IL_0111: ldarg.0
		/* 0x00002F5E 02                 */ IL_0112: ldarg.0
		/* 0x00002F5F 283B000006         */ IL_0113: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00002F64 2856000006         */ IL_0118: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::LoadFile(string) /* 06000056 */
		/* 0x00002F69 2A                 */ IL_011d: ret
	} // end of method AssistRoot::Load

	.method /* 06000055 */ public hidebysig 
		instance void LoadString (
			string text
		) cil managed 
	{
		// Method begins at RVA 0x2f78
		// Header size: 12
		// Code size: 27 (0x1b)
		.maxstack 2
		.locals /* 11000012 */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XDocument
		)

		/* 0x00002F78 03                 */ IL_0000: ldarg.1
		/* 0x00002F79 289000000A         */ IL_0001: call class [System.Xml.Linq]System.Xml.Linq.XDocument [System.Xml.Linq]System.Xml.Linq.XDocument::Parse(string) /* 0A000090 */
		/* 0x00002F7E 0A                 */ IL_0006: stloc.0
		/* 0x00002F7F 02                 */ IL_0007: ldarg.0
		/* 0x00002F80 06                 */ IL_0008: ldloc.0
		/* 0x00002F81 6F9100000A         */ IL_0009: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XDocument::get_Root() /* 0A000091 */
		/* 0x00002F86 6F2D000006         */ IL_000e: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::HydrateFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 0600002D */
		/* 0x00002F8B 02                 */ IL_0013: ldarg.0
		/* 0x00002F8C 16                 */ IL_0014: ldc.i4.0
		/* 0x00002F8D 283E000006         */ IL_0015: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool) /* 0600003E */
		/* 0x00002F92 2A                 */ IL_001a: ret
	} // end of method AssistRoot::LoadString

	.method /* 06000056 */ public hidebysig 
		instance void LoadFile (
			string fileName
		) cil managed 
	{
		// Method begins at RVA 0x2f9f
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x00002F9F 02                 */ IL_0000: ldarg.0
		/* 0x00002FA0 03                 */ IL_0001: ldarg.1
		/* 0x00002FA1 285C00000A         */ IL_0002: call string [mscorlib]System.IO.File::ReadAllText(string) /* 0A00005C */
		/* 0x00002FA6 2855000006         */ IL_0007: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::LoadString(string) /* 06000055 */
		/* 0x00002FAB 02                 */ IL_000c: ldarg.0
		/* 0x00002FAC 03                 */ IL_000d: ldarg.1
		/* 0x00002FAD 283C000006         */ IL_000e: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Filename(string) /* 0600003C */
		/* 0x00002FB2 2A                 */ IL_0013: ret
	} // end of method AssistRoot::LoadFile

	.method /* 06000057 */ public hidebysig 
		instance string SaveString () cil managed 
	{
		// Method begins at RVA 0x2fb4
		// Header size: 12
		// Code size: 76 (0x4c)
		.maxstack 3
		.locals /* 11000013 */ init (
			[0] class [mscorlib]System.Text.StringBuilder,
			[1] class [System.Xml]System.Xml.XmlWriter,
			[2] class [System.Xml]System.Xml.XmlWriterSettings
		)

		/* 0x00002FB4 739200000A         */ IL_0000: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000092 */
		/* 0x00002FB9 0A                 */ IL_0005: stloc.0
		/* 0x00002FBA 06                 */ IL_0006: ldloc.0
		/* 0x00002FBB 739300000A         */ IL_0007: newobj instance void [System.Xml]System.Xml.XmlWriterSettings::.ctor() /* 0A000093 */
		/* 0x00002FC0 0C                 */ IL_000c: stloc.2
		/* 0x00002FC1 08                 */ IL_000d: ldloc.2
		/* 0x00002FC2 17                 */ IL_000e: ldc.i4.1
		/* 0x00002FC3 6F9400000A         */ IL_000f: callvirt instance void [System.Xml]System.Xml.XmlWriterSettings::set_Indent(bool) /* 0A000094 */
		/* 0x00002FC8 08                 */ IL_0014: ldloc.2
		/* 0x00002FC9 289500000A         */ IL_0015: call class [mscorlib]System.Text.Encoding [mscorlib]System.Text.Encoding::get_UTF8() /* 0A000095 */
		/* 0x00002FCE 6F9600000A         */ IL_001a: callvirt instance void [System.Xml]System.Xml.XmlWriterSettings::set_Encoding(class [mscorlib]System.Text.Encoding) /* 0A000096 */
		/* 0x00002FD3 08                 */ IL_001f: ldloc.2
		/* 0x00002FD4 289700000A         */ IL_0020: call class [System.Xml]System.Xml.XmlWriter [System.Xml]System.Xml.XmlWriter::Create(class [mscorlib]System.Text.StringBuilder, class [System.Xml]System.Xml.XmlWriterSettings) /* 0A000097 */
		/* 0x00002FD9 0B                 */ IL_0025: stloc.1
		/* 0x00002FDA 02                 */ IL_0026: ldarg.0
		/* 0x00002FDB 6F2C000006         */ IL_0027: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement AspenTech.Visualisation.Controls.Assistant.AssistBasic::DehydrateToXml() /* 0600002C */
		/* 0x00002FE0 07                 */ IL_002c: ldloc.1
		/* 0x00002FE1 6F9800000A         */ IL_002d: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XNode::WriteTo(class [System.Xml]System.Xml.XmlWriter) /* 0A000098 */
		/* 0x00002FE6 DE0A               */ IL_0032: leave.s IL_003e
		/* 0x00002FE8 07                 */ IL_0034: ldloc.1
		/* 0x00002FE9 2C06               */ IL_0035: brfalse.s IL_003d
		/* 0x00002FEB 07                 */ IL_0037: ldloc.1
		/* 0x00002FEC 6F6D00000A         */ IL_0038: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00002FF1 DC                 */ IL_003d: endfinally
		/* 0x00002FF2 02                 */ IL_003e: ldarg.0
		/* 0x00002FF3 16                 */ IL_003f: ldc.i4.0
		/* 0x00002FF4 283E000006         */ IL_0040: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool) /* 0600003E */
		/* 0x00002FF9 06                 */ IL_0045: ldloc.0
		/* 0x00002FFA 6F6000000A         */ IL_0046: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00002FFF 2A                 */ IL_004b: ret

		.try IL_0026-IL_0034 finally IL_0034-IL_003e
	} // end of method AssistRoot::SaveString

	.method /* 06000058 */ public hidebysig 
		instance void FromXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement root
		) cil managed 
	{
		// Method begins at RVA 0x301c
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000301C 02                 */ IL_0000: ldarg.0
		/* 0x0000301D 03                 */ IL_0001: ldarg.1
		/* 0x0000301E 6F2D000006         */ IL_0002: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::HydrateFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 0600002D */
		/* 0x00003023 2A                 */ IL_0007: ret
	} // end of method AssistRoot::FromXml

	.method /* 06000059 */ assembly hidebysig strict virtual 
		instance void HydrateFromXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement root
		) cil managed 
	{
		// Method begins at RVA 0x3028
		// Header size: 12
		// Code size: 631 (0x277)
		.maxstack 5
		.locals /* 11000014 */ init (
			[0] int32,
			[1] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[2] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[3] int32,
			[4] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[5] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[6] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[7] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[8] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>,
			[9] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>,
			[10] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>
		)

		/* 0x00003028 03                 */ IL_0000: ldarg.1
		/* 0x00003029 6F9900000A         */ IL_0001: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XElement::get_Name() /* 0A000099 */
		/* 0x0000302E 7E5D000004         */ IL_0006: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Assistant /* 0400005D */
		/* 0x00003033 289A00000A         */ IL_000b: call bool [System.Xml.Linq]System.Xml.Linq.XName::op_Inequality(class [System.Xml.Linq]System.Xml.Linq.XName, class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009A */
		/* 0x00003038 2C0B               */ IL_0010: brfalse.s IL_001d
		/* 0x0000303A 72C6030070         */ IL_0012: ldstr "root" /* 700003C6 */
		/* 0x0000303F 731A00000A         */ IL_0017: newobj instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string) /* 0A00001A */
		/* 0x00003044 7A                 */ IL_001c: throw
		/* 0x00003045 03                 */ IL_001d: ldarg.1
		/* 0x00003046 7E70000004         */ IL_001e: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Version /* 04000070 */
		/* 0x0000304B 6F9B00000A         */ IL_0023: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x00003050 15                 */ IL_0028: ldc.i4.m1
		/* 0x00003051 28B2000006         */ IL_0029: call int32 AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, int32) /* 060000B2 */
		/* 0x00003056 0A                 */ IL_002e: stloc.0
		/* 0x00003057 06                 */ IL_002f: ldloc.0
		/* 0x00003058 7E79000004         */ IL_0030: ldsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionBack /* 04000079 */
		/* 0x0000305D 2F25               */ IL_0035: bge.s IL_005c
		/* 0x0000305F 72C6030070         */ IL_0037: ldstr "root" /* 700003C6 */
		/* 0x00003064 72D0030070         */ IL_003c: ldstr "File version {0}, but only backward compatible to {1}" /* 700003D0 */
		/* 0x00003069 06                 */ IL_0041: ldloc.0
		/* 0x0000306A 8C73000001         */ IL_0042: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x0000306F 7E79000004         */ IL_0047: ldsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionBack /* 04000079 */
		/* 0x00003074 8C73000001         */ IL_004c: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x00003079 289C00000A         */ IL_0051: call string [mscorlib]System.String::Format(string, object, object) /* 0A00009C */
		/* 0x0000307E 739D00000A         */ IL_0056: newobj instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string, string) /* 0A00009D */
		/* 0x00003083 7A                 */ IL_005b: throw
		/* 0x00003084 03                 */ IL_005c: ldarg.1
		/* 0x00003085 7E71000004         */ IL_005d: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Backwards /* 04000071 */
		/* 0x0000308A 6F9B00000A         */ IL_0062: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x0000308F 15                 */ IL_0067: ldc.i4.m1
		/* 0x00003090 28B2000006         */ IL_0068: call int32 AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, int32) /* 060000B2 */
		/* 0x00003095 0A                 */ IL_006d: stloc.0
		/* 0x00003096 06                 */ IL_006e: ldloc.0
		/* 0x00003097 7E7A000004         */ IL_006f: ldsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionNow /* 0400007A */
		/* 0x0000309C 3125               */ IL_0074: ble.s IL_009b
		/* 0x0000309E 72C6030070         */ IL_0076: ldstr "root" /* 700003C6 */
		/* 0x000030A3 723C040070         */ IL_007b: ldstr "File version is backward compatible to {1}, not {0}" /* 7000043C */
		/* 0x000030A8 06                 */ IL_0080: ldloc.0
		/* 0x000030A9 8C73000001         */ IL_0081: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x000030AE 7E7A000004         */ IL_0086: ldsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionNow /* 0400007A */
		/* 0x000030B3 8C73000001         */ IL_008b: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x000030B8 289C00000A         */ IL_0090: call string [mscorlib]System.String::Format(string, object, object) /* 0A00009C */
		/* 0x000030BD 739D00000A         */ IL_0095: newobj instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string, string) /* 0A00009D */
		/* 0x000030C2 7A                 */ IL_009a: throw
		/* 0x000030C3 03                 */ IL_009b: ldarg.1
		/* 0x000030C4 7E5F000004         */ IL_009c: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Author /* 0400005F */
		/* 0x000030C9 6F9E00000A         */ IL_00a1: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x000030CE 0B                 */ IL_00a6: stloc.1
		/* 0x000030CF 02                 */ IL_00a7: ldarg.0
		/* 0x000030D0 07                 */ IL_00a8: ldloc.1
		/* 0x000030D1 6F7E00000A         */ IL_00a9: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XElement::get_Value() /* 0A00007E */
		/* 0x000030D6 2842000006         */ IL_00ae: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Author(string) /* 06000042 */
		/* 0x000030DB 02                 */ IL_00b3: ldarg.0
		/* 0x000030DC 07                 */ IL_00b4: ldloc.1
		/* 0x000030DD 7E6C000004         */ IL_00b5: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x000030E2 6F9B00000A         */ IL_00ba: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x000030E7 7E2800000A         */ IL_00bf: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x000030EC 28B1000006         */ IL_00c4: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, string) /* 060000B1 */
		/* 0x000030F1 2844000006         */ IL_00c9: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_AuthorId(string) /* 06000044 */
		/* 0x000030F6 03                 */ IL_00ce: ldarg.1
		/* 0x000030F7 7E67000004         */ IL_00cf: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Modifier /* 04000067 */
		/* 0x000030FC 6F9E00000A         */ IL_00d4: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00003101 0C                 */ IL_00d9: stloc.2
		/* 0x00003102 02                 */ IL_00da: ldarg.0
		/* 0x00003103 08                 */ IL_00db: ldloc.2
		/* 0x00003104 7E6C000004         */ IL_00dc: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x00003109 6F9B00000A         */ IL_00e1: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x0000310E 7E2800000A         */ IL_00e6: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00003113 28B1000006         */ IL_00eb: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, string) /* 060000B1 */
		/* 0x00003118 2848000006         */ IL_00f0: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_ModifierId(string) /* 06000048 */
		/* 0x0000311D 03                 */ IL_00f5: ldarg.1
		/* 0x0000311E 7E65000004         */ IL_00f6: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::BuildDate /* 04000065 */
		/* 0x00003123 6F9E00000A         */ IL_00fb: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00003128 16                 */ IL_0100: ldc.i4.0
		/* 0x00003129 28B6000006         */ IL_0101: call int32 AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XElement, int32) /* 060000B6 */
		/* 0x0000312E 0D                 */ IL_0106: stloc.3
		/* 0x0000312F 02                 */ IL_0107: ldarg.0
		/* 0x00003130 09                 */ IL_0108: ldloc.3
		/* 0x00003131 2010270000         */ IL_0109: ldc.i4 10000
		/* 0x00003136 5B                 */ IL_010e: div
		/* 0x00003137 09                 */ IL_010f: ldloc.3
		/* 0x00003138 1F64               */ IL_0110: ldc.i4.s 100
		/* 0x0000313A 5B                 */ IL_0112: div
		/* 0x0000313B 1F64               */ IL_0113: ldc.i4.s 100
		/* 0x0000313D 5D                 */ IL_0115: rem
		/* 0x0000313E 09                 */ IL_0116: ldloc.3
		/* 0x0000313F 1F64               */ IL_0117: ldc.i4.s 100
		/* 0x00003141 5D                 */ IL_0119: rem
		/* 0x00003142 739F00000A         */ IL_011a: newobj instance void [mscorlib]System.DateTime::.ctor(int32, int32, int32) /* 0A00009F */
		/* 0x00003147 284E000006         */ IL_011f: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_BuildDate(valuetype [mscorlib]System.DateTime) /* 0600004E */
		/* 0x0000314C 02                 */ IL_0124: ldarg.0
		/* 0x0000314D 03                 */ IL_0125: ldarg.1
		/* 0x0000314E 7E66000004         */ IL_0126: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Copyright /* 04000066 */
		/* 0x00003153 6F9E00000A         */ IL_012b: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00003158 7E2800000A         */ IL_0130: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x0000315D 28B5000006         */ IL_0135: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XElement, string) /* 060000B5 */
		/* 0x00003162 284C000006         */ IL_013a: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Copyright(string) /* 0600004C */
		/* 0x00003167 02                 */ IL_013f: ldarg.0
		/* 0x00003168 03                 */ IL_0140: ldarg.1
		/* 0x00003169 7E64000004         */ IL_0141: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::First /* 04000064 */
		/* 0x0000316E 6F9E00000A         */ IL_0146: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00003173 7E2800000A         */ IL_014b: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00003178 28B5000006         */ IL_0150: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XElement, string) /* 060000B5 */
		/* 0x0000317D 2840000006         */ IL_0155: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_First(string) /* 06000040 */
		/* 0x00003182 02                 */ IL_015a: ldarg.0
		/* 0x00003183 03                 */ IL_015b: ldarg.1
		/* 0x00003184 7E5E000004         */ IL_015c: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Caption /* 0400005E */
		/* 0x00003189 6F9E00000A         */ IL_0161: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x0000318E 7E2800000A         */ IL_0166: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00003193 28B5000006         */ IL_016b: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XElement, string) /* 060000B5 */
		/* 0x00003198 2830000006         */ IL_0170: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x0000319D 02                 */ IL_0175: ldarg.0
		/* 0x0000319E 03                 */ IL_0176: ldarg.1
		/* 0x0000319F 2837000006         */ IL_0177: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::ExplanationsFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 06000037 */
		/* 0x000031A4 03                 */ IL_017c: ldarg.1
		/* 0x000031A5 7E62000004         */ IL_017d: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Screen /* 04000062 */
		/* 0x000031AA 6F7B00000A         */ IL_0182: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement> [System.Xml.Linq]System.Xml.Linq.XContainer::Elements(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00007B */
		/* 0x000031AF 6F7C00000A         */ IL_0187: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::GetEnumerator() /* 0A00007C */
		/* 0x000031B4 1308               */ IL_018c: stloc.s 8
		/* 0x000031B6 2B27               */ IL_018e: br.s IL_01b7
		/* 0x000031B8 1108               */ IL_0190: ldloc.s 8
		/* 0x000031BA 6F7D00000A         */ IL_0192: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::get_Current() /* 0A00007D */
		/* 0x000031BF 1304               */ IL_0197: stloc.s 4
		/* 0x000031C1 02                 */ IL_0199: ldarg.0
		/* 0x000031C2 73BE000006         */ IL_019a: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistScreen::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 060000BE */
		/* 0x000031C7 1305               */ IL_019f: stloc.s 5
		/* 0x000031C9 1105               */ IL_01a1: ldloc.s 5
		/* 0x000031CB 1104               */ IL_01a3: ldloc.s 4
		/* 0x000031CD 6F2D000006         */ IL_01a5: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::HydrateFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 0600002D */
		/* 0x000031D2 02                 */ IL_01aa: ldarg.0
		/* 0x000031D3 2839000006         */ IL_01ab: call instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens() /* 06000039 */
		/* 0x000031D8 1105               */ IL_01b0: ldloc.s 5
		/* 0x000031DA 6FA000000A         */ IL_01b2: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::Add(!0) /* 0A0000A0 */
		/* 0x000031DF 1108               */ IL_01b7: ldloc.s 8
		/* 0x000031E1 6F7700000A         */ IL_01b9: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x000031E6 2DD0               */ IL_01be: brtrue.s IL_0190
		/* 0x000031E8 DE0C               */ IL_01c0: leave.s IL_01ce
		/* 0x000031EA 1108               */ IL_01c2: ldloc.s 8
		/* 0x000031EC 2C07               */ IL_01c4: brfalse.s IL_01cd
		/* 0x000031EE 1108               */ IL_01c6: ldloc.s 8
		/* 0x000031F0 6F6D00000A         */ IL_01c8: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x000031F5 DC                 */ IL_01cd: endfinally
		/* 0x000031F6 02                 */ IL_01ce: ldarg.0
		/* 0x000031F7 284F000006         */ IL_01cf: call instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Translations() /* 0600004F */
		/* 0x000031FC 6FA100000A         */ IL_01d4: callvirt instance void class [mscorlib]System.Collections.Generic.ICollection`1<valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>>::Clear() /* 0A0000A1 */
		/* 0x00003201 03                 */ IL_01d9: ldarg.1
		/* 0x00003202 7E6A000004         */ IL_01da: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Translations /* 0400006A */
		/* 0x00003207 6F7B00000A         */ IL_01df: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement> [System.Xml.Linq]System.Xml.Linq.XContainer::Elements(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00007B */
		/* 0x0000320C 6F7C00000A         */ IL_01e4: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::GetEnumerator() /* 0A00007C */
		/* 0x00003211 1309               */ IL_01e9: stloc.s 9
		/* 0x00003213 2B6B               */ IL_01eb: br.s IL_0258
		/* 0x00003215 1109               */ IL_01ed: ldloc.s 9
		/* 0x00003217 6F7D00000A         */ IL_01ef: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::get_Current() /* 0A00007D */
		/* 0x0000321C 1306               */ IL_01f4: stloc.s 6
		/* 0x0000321E 1106               */ IL_01f6: ldloc.s 6
		/* 0x00003220 7E6B000004         */ IL_01f8: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Translation /* 0400006B */
		/* 0x00003225 6F7B00000A         */ IL_01fd: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement> [System.Xml.Linq]System.Xml.Linq.XContainer::Elements(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00007B */
		/* 0x0000322A 6F7C00000A         */ IL_0202: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::GetEnumerator() /* 0A00007C */
		/* 0x0000322F 130A               */ IL_0207: stloc.s 10
		/* 0x00003231 2B36               */ IL_0209: br.s IL_0241
		/* 0x00003233 110A               */ IL_020b: ldloc.s 10
		/* 0x00003235 6F7D00000A         */ IL_020d: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::get_Current() /* 0A00007D */
		/* 0x0000323A 1307               */ IL_0212: stloc.s 7
		/* 0x0000323C 02                 */ IL_0214: ldarg.0
		/* 0x0000323D 284F000006         */ IL_0215: call instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Translations() /* 0600004F */
		/* 0x00003242 1107               */ IL_021a: ldloc.s 7
		/* 0x00003244 7E75000004         */ IL_021c: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::TranslationKey /* 04000075 */
		/* 0x00003249 6F9B00000A         */ IL_0221: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x0000324E 6FA200000A         */ IL_0226: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XAttribute::get_Value() /* 0A0000A2 */
		/* 0x00003253 1107               */ IL_022b: ldloc.s 7
		/* 0x00003255 7E76000004         */ IL_022d: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::TranslationValue /* 04000076 */
		/* 0x0000325A 6F9B00000A         */ IL_0232: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x0000325F 6FA200000A         */ IL_0237: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XAttribute::get_Value() /* 0A0000A2 */
		/* 0x00003264 6FA300000A         */ IL_023c: callvirt instance void class [mscorlib]System.Collections.Generic.IDictionary`2<string, string>::set_Item(!0, !1) /* 0A0000A3 */
		/* 0x00003269 110A               */ IL_0241: ldloc.s 10
		/* 0x0000326B 6F7700000A         */ IL_0243: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00003270 2DC1               */ IL_0248: brtrue.s IL_020b
		/* 0x00003272 DE0C               */ IL_024a: leave.s IL_0258
		/* 0x00003274 110A               */ IL_024c: ldloc.s 10
		/* 0x00003276 2C07               */ IL_024e: brfalse.s IL_0257
		/* 0x00003278 110A               */ IL_0250: ldloc.s 10
		/* 0x0000327A 6F6D00000A         */ IL_0252: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x0000327F DC                 */ IL_0257: endfinally
		/* 0x00003280 1109               */ IL_0258: ldloc.s 9
		/* 0x00003282 6F7700000A         */ IL_025a: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00003287 2D8C               */ IL_025f: brtrue.s IL_01ed
		/* 0x00003289 DE0C               */ IL_0261: leave.s IL_026f
		/* 0x0000328B 1109               */ IL_0263: ldloc.s 9
		/* 0x0000328D 2C07               */ IL_0265: brfalse.s IL_026e
		/* 0x0000328F 1109               */ IL_0267: ldloc.s 9
		/* 0x00003291 6F6D00000A         */ IL_0269: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00003296 DC                 */ IL_026e: endfinally
		/* 0x00003297 02                 */ IL_026f: ldarg.0
		/* 0x00003298 16                 */ IL_0270: ldc.i4.0
		/* 0x00003299 283E000006         */ IL_0271: call instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool) /* 0600003E */
		/* 0x0000329E 2A                 */ IL_0276: ret

		.try IL_018e-IL_01c2 finally IL_01c2-IL_01ce
		.try IL_0209-IL_024c finally IL_024c-IL_0258
		.try IL_01eb-IL_0263 finally IL_0263-IL_026f
	} // end of method AssistRoot::HydrateFromXml

	.method /* 0600005A */ assembly hidebysig strict virtual 
		instance class [System.Xml.Linq]System.Xml.Linq.XElement DehydrateToXml () cil managed 
	{
		// Method begins at RVA 0x32d4
		// Header size: 12
		// Code size: 516 (0x204)
		.maxstack 9
		.locals /* 11000015 */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[1] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[2] valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>,
			[3] object[],
			[4] object[],
			[5] valuetype [mscorlib]System.DateTime,
			[6] valuetype [mscorlib]System.DateTime,
			[7] valuetype [mscorlib]System.DateTime,
			[8] valuetype [mscorlib]System.DateTime,
			[9] valuetype [mscorlib]System.DateTime,
			[10] class [mscorlib]System.Collections.Generic.IEnumerator`1<valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>>,
			[11] object[]
		)

		/* 0x000032D4 7E5D000004         */ IL_0000: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Assistant /* 0400005D */
		/* 0x000032D9 1F0A               */ IL_0005: ldc.i4.s 10
		/* 0x000032DB 8D01000001         */ IL_0007: newarr [mscorlib]System.Object /* 01000001 */
		/* 0x000032E0 0D                 */ IL_000c: stloc.3
		/* 0x000032E1 09                 */ IL_000d: ldloc.3
		/* 0x000032E2 16                 */ IL_000e: ldc.i4.0
		/* 0x000032E3 7E6C000004         */ IL_000f: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x000032E8 02                 */ IL_0014: ldarg.0
		/* 0x000032E9 2828000006         */ IL_0015: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000032EE 73A400000A         */ IL_001a: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x000032F3 A2                 */ IL_001f: stelem.ref
		/* 0x000032F4 09                 */ IL_0020: ldloc.3
		/* 0x000032F5 17                 */ IL_0021: ldc.i4.1
		/* 0x000032F6 7E70000004         */ IL_0022: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Version /* 04000070 */
		/* 0x000032FB 7E7A000004         */ IL_0027: ldsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionNow /* 0400007A */
		/* 0x00003300 8C73000001         */ IL_002c: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x00003305 73A400000A         */ IL_0031: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x0000330A A2                 */ IL_0036: stelem.ref
		/* 0x0000330B 09                 */ IL_0037: ldloc.3
		/* 0x0000330C 18                 */ IL_0038: ldc.i4.2
		/* 0x0000330D 7E71000004         */ IL_0039: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Backwards /* 04000071 */
		/* 0x00003312 7E79000004         */ IL_003e: ldsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionBack /* 04000079 */
		/* 0x00003317 8C73000001         */ IL_0043: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x0000331C 73A400000A         */ IL_0048: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x00003321 A2                 */ IL_004d: stelem.ref
		/* 0x00003322 09                 */ IL_004e: ldloc.3
		/* 0x00003323 19                 */ IL_004f: ldc.i4.3
		/* 0x00003324 7E5F000004         */ IL_0050: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Author /* 0400005F */
		/* 0x00003329 18                 */ IL_0055: ldc.i4.2
		/* 0x0000332A 8D01000001         */ IL_0056: newarr [mscorlib]System.Object /* 01000001 */
		/* 0x0000332F 1304               */ IL_005b: stloc.s 4
		/* 0x00003331 1104               */ IL_005d: ldloc.s 4
		/* 0x00003333 16                 */ IL_005f: ldc.i4.0
		/* 0x00003334 7E6C000004         */ IL_0060: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x00003339 02                 */ IL_0065: ldarg.0
		/* 0x0000333A 2843000006         */ IL_0066: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_AuthorId() /* 06000043 */
		/* 0x0000333F 73A400000A         */ IL_006b: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x00003344 A2                 */ IL_0070: stelem.ref
		/* 0x00003345 1104               */ IL_0071: ldloc.s 4
		/* 0x00003347 17                 */ IL_0073: ldc.i4.1
		/* 0x00003348 02                 */ IL_0074: ldarg.0
		/* 0x00003349 2841000006         */ IL_0075: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Author() /* 06000041 */
		/* 0x0000334E A2                 */ IL_007a: stelem.ref
		/* 0x0000334F 1104               */ IL_007b: ldloc.s 4
		/* 0x00003351 73A500000A         */ IL_007d: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object[]) /* 0A0000A5 */
		/* 0x00003356 A2                 */ IL_0082: stelem.ref
		/* 0x00003357 09                 */ IL_0083: ldloc.3
		/* 0x00003358 1A                 */ IL_0084: ldc.i4.4
		/* 0x00003359 7E67000004         */ IL_0085: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Modifier /* 04000067 */
		/* 0x0000335E 7E6C000004         */ IL_008a: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x00003363 02                 */ IL_008f: ldarg.0
		/* 0x00003364 2847000006         */ IL_0090: call instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_ModifierId() /* 06000047 */
		/* 0x00003369 73A400000A         */ IL_0095: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x0000336E 737900000A         */ IL_009a: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x00003373 A2                 */ IL_009f: stelem.ref
		/* 0x00003374 09                 */ IL_00a0: ldloc.3
		/* 0x00003375 1B                 */ IL_00a1: ldc.i4.5
		/* 0x00003376 7E65000004         */ IL_00a2: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::BuildDate /* 04000065 */
		/* 0x0000337B 02                 */ IL_00a7: ldarg.0
		/* 0x0000337C 284D000006         */ IL_00a8: call instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate() /* 0600004D */
		/* 0x00003381 1305               */ IL_00ad: stloc.s 5
		/* 0x00003383 1205               */ IL_00af: ldloca.s 5
		/* 0x00003385 72A4040070         */ IL_00b1: ldstr "yyyyMMdd" /* 700004A4 */
		/* 0x0000338A 282D00000A         */ IL_00b6: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x0000338F 28A600000A         */ IL_00bb: call instance string [mscorlib]System.DateTime::ToString(string, class [mscorlib]System.IFormatProvider) /* 0A0000A6 */
		/* 0x00003394 737900000A         */ IL_00c0: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x00003399 A2                 */ IL_00c5: stelem.ref
		/* 0x0000339A 09                 */ IL_00c6: ldloc.3
		/* 0x0000339B 1C                 */ IL_00c7: ldc.i4.6
		/* 0x0000339C 7E68000004         */ IL_00c8: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Version /* 04000068 */
		/* 0x000033A1 02                 */ IL_00cd: ldarg.0
		/* 0x000033A2 284D000006         */ IL_00ce: call instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate() /* 0600004D */
		/* 0x000033A7 1306               */ IL_00d3: stloc.s 6
		/* 0x000033A9 1206               */ IL_00d5: ldloca.s 6
		/* 0x000033AB 72A4040070         */ IL_00d7: ldstr "yyyyMMdd" /* 700004A4 */
		/* 0x000033B0 282D00000A         */ IL_00dc: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x000033B5 28A600000A         */ IL_00e1: call instance string [mscorlib]System.DateTime::ToString(string, class [mscorlib]System.IFormatProvider) /* 0A0000A6 */
		/* 0x000033BA 737900000A         */ IL_00e6: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x000033BF A2                 */ IL_00eb: stelem.ref
		/* 0x000033C0 09                 */ IL_00ec: ldloc.3
		/* 0x000033C1 1D                 */ IL_00ed: ldc.i4.7
		/* 0x000033C2 7E65000004         */ IL_00ee: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::BuildDate /* 04000065 */
		/* 0x000033C7 02                 */ IL_00f3: ldarg.0
		/* 0x000033C8 284D000006         */ IL_00f4: call instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate() /* 0600004D */
		/* 0x000033CD 1307               */ IL_00f9: stloc.s 7
		/* 0x000033CF 1207               */ IL_00fb: ldloca.s 7
		/* 0x000033D1 72A4040070         */ IL_00fd: ldstr "yyyyMMdd" /* 700004A4 */
		/* 0x000033D6 282D00000A         */ IL_0102: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x000033DB 28A600000A         */ IL_0107: call instance string [mscorlib]System.DateTime::ToString(string, class [mscorlib]System.IFormatProvider) /* 0A0000A6 */
		/* 0x000033E0 737900000A         */ IL_010c: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x000033E5 A2                 */ IL_0111: stelem.ref
		/* 0x000033E6 09                 */ IL_0112: ldloc.3
		/* 0x000033E7 1E                 */ IL_0113: ldc.i4.8
		/* 0x000033E8 7E65000004         */ IL_0114: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::BuildDate /* 04000065 */
		/* 0x000033ED 02                 */ IL_0119: ldarg.0
		/* 0x000033EE 284D000006         */ IL_011a: call instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate() /* 0600004D */
		/* 0x000033F3 1308               */ IL_011f: stloc.s 8
		/* 0x000033F5 1208               */ IL_0121: ldloca.s 8
		/* 0x000033F7 72A4040070         */ IL_0123: ldstr "yyyyMMdd" /* 700004A4 */
		/* 0x000033FC 282D00000A         */ IL_0128: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x00003401 28A600000A         */ IL_012d: call instance string [mscorlib]System.DateTime::ToString(string, class [mscorlib]System.IFormatProvider) /* 0A0000A6 */
		/* 0x00003406 737900000A         */ IL_0132: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x0000340B A2                 */ IL_0137: stelem.ref
		/* 0x0000340C 09                 */ IL_0138: ldloc.3
		/* 0x0000340D 1F09               */ IL_0139: ldc.i4.s 9
		/* 0x0000340F 7E65000004         */ IL_013b: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::BuildDate /* 04000065 */
		/* 0x00003414 02                 */ IL_0140: ldarg.0
		/* 0x00003415 284D000006         */ IL_0141: call instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate() /* 0600004D */
		/* 0x0000341A 1309               */ IL_0146: stloc.s 9
		/* 0x0000341C 1209               */ IL_0148: ldloca.s 9
		/* 0x0000341E 72A4040070         */ IL_014a: ldstr "yyyyMMdd" /* 700004A4 */
		/* 0x00003423 282D00000A         */ IL_014f: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x00003428 28A600000A         */ IL_0154: call instance string [mscorlib]System.DateTime::ToString(string, class [mscorlib]System.IFormatProvider) /* 0A0000A6 */
		/* 0x0000342D 737900000A         */ IL_0159: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x00003432 A2                 */ IL_015e: stelem.ref
		/* 0x00003433 09                 */ IL_015f: ldloc.3
		/* 0x00003434 73A500000A         */ IL_0160: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object[]) /* 0A0000A5 */
		/* 0x00003439 0A                 */ IL_0165: stloc.0
		/* 0x0000343A 02                 */ IL_0166: ldarg.0
		/* 0x0000343B 06                 */ IL_0167: ldloc.0
		/* 0x0000343C 2836000006         */ IL_0168: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::ExplanationsToXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 06000036 */
		/* 0x00003441 02                 */ IL_016d: ldarg.0
		/* 0x00003442 284F000006         */ IL_016e: call instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Translations() /* 0600004F */
		/* 0x00003447 6FA700000A         */ IL_0173: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>>::get_Count() /* 0A0000A7 */
		/* 0x0000344C 16                 */ IL_0178: ldc.i4.0
		/* 0x0000344D 3E84000000         */ IL_0179: ble IL_0202
		/* 0x00003452 7E6A000004         */ IL_017e: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Translations /* 0400006A */
		/* 0x00003457 73A800000A         */ IL_0183: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A0000A8 */
		/* 0x0000345C 0B                 */ IL_0188: stloc.1
		/* 0x0000345D 02                 */ IL_0189: ldarg.0
		/* 0x0000345E 284F000006         */ IL_018a: call instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Translations() /* 0600004F */
		/* 0x00003463 6FA900000A         */ IL_018f: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>>::GetEnumerator() /* 0A0000A9 */
		/* 0x00003468 130A               */ IL_0194: stloc.s 10
		/* 0x0000346A 2B4C               */ IL_0196: br.s IL_01e4
		/* 0x0000346C 110A               */ IL_0198: ldloc.s 10
		/* 0x0000346E 6FAA00000A         */ IL_019a: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>>::get_Current() /* 0A0000AA */
		/* 0x00003473 0C                 */ IL_019f: stloc.2
		/* 0x00003474 07                 */ IL_01a0: ldloc.1
		/* 0x00003475 7E6B000004         */ IL_01a1: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Translation /* 0400006B */
		/* 0x0000347A 18                 */ IL_01a6: ldc.i4.2
		/* 0x0000347B 8D01000001         */ IL_01a7: newarr [mscorlib]System.Object /* 01000001 */
		/* 0x00003480 130B               */ IL_01ac: stloc.s 11
		/* 0x00003482 110B               */ IL_01ae: ldloc.s 11
		/* 0x00003484 16                 */ IL_01b0: ldc.i4.0
		/* 0x00003485 7E75000004         */ IL_01b1: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::TranslationKey /* 04000075 */
		/* 0x0000348A 1202               */ IL_01b6: ldloca.s 2
		/* 0x0000348C 28AB00000A         */ IL_01b8: call instance !0 valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>::get_Key() /* 0A0000AB */
		/* 0x00003491 73A400000A         */ IL_01bd: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x00003496 A2                 */ IL_01c2: stelem.ref
		/* 0x00003497 110B               */ IL_01c3: ldloc.s 11
		/* 0x00003499 17                 */ IL_01c5: ldc.i4.1
		/* 0x0000349A 7E76000004         */ IL_01c6: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::TranslationValue /* 04000076 */
		/* 0x0000349F 1202               */ IL_01cb: ldloca.s 2
		/* 0x000034A1 28AC00000A         */ IL_01cd: call instance !1 valuetype [mscorlib]System.Collections.Generic.KeyValuePair`2<string, string>::get_Value() /* 0A0000AC */
		/* 0x000034A6 73A400000A         */ IL_01d2: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x000034AB A2                 */ IL_01d7: stelem.ref
		/* 0x000034AC 110B               */ IL_01d8: ldloc.s 11
		/* 0x000034AE 73A500000A         */ IL_01da: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object[]) /* 0A0000A5 */
		/* 0x000034B3 6F7A00000A         */ IL_01df: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object) /* 0A00007A */
		/* 0x000034B8 110A               */ IL_01e4: ldloc.s 10
		/* 0x000034BA 6F7700000A         */ IL_01e6: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x000034BF 2DAB               */ IL_01eb: brtrue.s IL_0198
		/* 0x000034C1 DE0C               */ IL_01ed: leave.s IL_01fb
		/* 0x000034C3 110A               */ IL_01ef: ldloc.s 10
		/* 0x000034C5 2C07               */ IL_01f1: brfalse.s IL_01fa
		/* 0x000034C7 110A               */ IL_01f3: ldloc.s 10
		/* 0x000034C9 6F6D00000A         */ IL_01f5: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x000034CE DC                 */ IL_01fa: endfinally
		/* 0x000034CF 06                 */ IL_01fb: ldloc.0
		/* 0x000034D0 07                 */ IL_01fc: ldloc.1
		/* 0x000034D1 6F7A00000A         */ IL_01fd: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object) /* 0A00007A */
		/* 0x000034D6 06                 */ IL_0202: ldloc.0
		/* 0x000034D7 2A                 */ IL_0203: ret

		.try IL_0196-IL_01ef finally IL_01ef-IL_01fb
	} // end of method AssistRoot::DehydrateToXml

	// Properties
	.property /* 1700000B */ instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens Screens()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Screens(class AspenTech.Visualisation.Controls.Assistant.AssistScreens)
	}
	.property /* 1700000C */ instance string Filename()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Filename(string)
	}
	.property /* 1700000D */ instance bool Changed()
	{
		.get instance bool AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Changed()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Changed(bool)
	}
	.property /* 1700000E */ instance string First()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_First()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_First(string)
	}
	.property /* 1700000F */ instance string Author()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Author()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Author(string)
	}
	.property /* 17000010 */ instance string AuthorId()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_AuthorId()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_AuthorId(string)
	}
	.property /* 17000011 */ instance string Version()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Version()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Version(string)
	}
	.property /* 17000012 */ instance string ModifierId()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_ModifierId()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_ModifierId(string)
	}
	.property /* 17000013 */ instance string CurrentUserId()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_CurrentUserId()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_CurrentUserId(string)
	}
	.property /* 17000014 */ instance string Copyright()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Copyright()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Copyright(string)
	}
	.property /* 17000015 */ instance valuetype [mscorlib]System.DateTime BuildDate()
	{
		.get instance valuetype [mscorlib]System.DateTime AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_BuildDate()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_BuildDate(valuetype [mscorlib]System.DateTime)
	}
	.property /* 17000016 */ instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> Translations()
	{
		.get instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Translations()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_Translations(class [mscorlib]System.Collections.Generic.IDictionary`2<string, string>)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistRoot

.class /* 0200000E */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistScreens
	extends class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>
{
	// Methods
	.method /* 0600005B */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x34f4
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000034F4 02                 */ IL_0000: ldarg.0
		/* 0x000034F5 28AD00000A         */ IL_0001: call instance void class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::.ctor() /* 0A0000AD */
		/* 0x000034FA 2A                 */ IL_0006: ret
	} // end of method AssistScreens::.ctor

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistScreens

.class /* 0200000F */ interface private auto ansi abstract AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Methods
	.method /* 0600005C */ public hidebysig specialname newslot abstract virtual 
		instance string get_ScreenId () cil managed 
	{
	} // end of method IAssistantViewModel::get_ScreenId

	.method /* 0600005D */ public hidebysig specialname newslot abstract virtual 
		instance void set_ScreenId (
			string 'value'
		) cil managed 
	{
	} // end of method IAssistantViewModel::set_ScreenId

	.method /* 0600005E */ public hidebysig newslot abstract virtual 
		instance string RenderToHtml (
			valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget target
		) cil managed 
	{
	} // end of method IAssistantViewModel::RenderToHtml

	.method /* 0600005F */ public hidebysig newslot abstract virtual 
		instance string RenderAllToHtml (
			valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget target
		) cil managed 
	{
	} // end of method IAssistantViewModel::RenderAllToHtml

	.method /* 06000060 */ public hidebysig specialname newslot abstract virtual 
		instance class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel get_Screen () cil managed 
	{
	} // end of method IAssistantViewModel::get_Screen

	.method /* 06000061 */ public hidebysig specialname newslot abstract virtual 
		instance class AspenTech.Visualisation.Controls.Assistant.IRootViewModel get_Root () cil managed 
	{
	} // end of method IAssistantViewModel::get_Root

	.method /* 06000062 */ public hidebysig specialname newslot abstract virtual 
		instance class [PresentationCore]System.Windows.Input.ICommand get_SelectCommand () cil managed 
	{
	} // end of method IAssistantViewModel::get_SelectCommand

	.method /* 06000063 */ public hidebysig specialname newslot abstract virtual 
		instance class [PresentationCore]System.Windows.Input.ICommand get_RedoCommand () cil managed 
	{
	} // end of method IAssistantViewModel::get_RedoCommand

	.method /* 06000064 */ public hidebysig specialname newslot abstract virtual 
		instance class [PresentationCore]System.Windows.Input.ICommand get_UndoCommand () cil managed 
	{
	} // end of method IAssistantViewModel::get_UndoCommand

	// Properties
	.property /* 17000017 */ instance string ScreenId()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_ScreenId()
		.set instance void AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::set_ScreenId(string)
	}
	.property /* 17000018 */ instance class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel Screen()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_Screen()
	}
	.property /* 17000019 */ instance class AspenTech.Visualisation.Controls.Assistant.IRootViewModel Root()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.IRootViewModel AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_Root()
	}
	.property /* 1700001A */ instance class [PresentationCore]System.Windows.Input.ICommand SelectCommand()
	{
		.get instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_SelectCommand()
	}
	.property /* 1700001B */ instance class [PresentationCore]System.Windows.Input.ICommand RedoCommand()
	{
		.get instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_RedoCommand()
	}
	.property /* 1700001C */ instance class [PresentationCore]System.Windows.Input.ICommand UndoCommand()
	{
		.get instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_UndoCommand()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel

.class /* 02000010 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistantViewModel
	extends [mscorlib]System.Object
	implements AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel,
	           [System]System.ComponentModel.INotifyPropertyChanged
{
	// Nested Types
	.class /* 0200002A */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClass5'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000041 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400007B */ public int32 pos
		.field /* 0400007C */ public string path

		// Methods
		.method /* 060000F1 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x3569
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003569 02                 */ IL_0000: ldarg.0
			/* 0x0000356A 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
			/* 0x0000356F 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClass5'::.ctor

		.method /* 060000F2 */ public hidebysig 
			instance bool '<Find>b__0' (
				class AspenTech.Visualisation.Controls.Assistant.AssistScreen x
			) cil managed 
		{
			// Method begins at RVA 0x3571
			// Header size: 1
			// Code size: 30 (0x1e)
			.maxstack 8

			/* 0x00003571 03                 */ IL_0000: ldarg.1
			/* 0x00003572 6F28000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
			/* 0x00003577 02                 */ IL_0006: ldarg.0
			/* 0x00003578 7B7C000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
			/* 0x0000357D 16                 */ IL_000c: ldc.i4.0
			/* 0x0000357E 02                 */ IL_000d: ldarg.0
			/* 0x0000357F 7B7B000004         */ IL_000e: ldfld int32 AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::pos /* 0400007B */
			/* 0x00003584 6F7400000A         */ IL_0013: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
			/* 0x00003589 283F00000A         */ IL_0018: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x0000358E 2A                 */ IL_001d: ret
		} // end of method '<>c__DisplayClass5'::'<Find>b__0'

		.method /* 060000F3 */ public hidebysig 
			instance bool '<Find>b__1' (
				class AspenTech.Visualisation.Controls.Assistant.AssistOption x
			) cil managed 
		{
			// Method begins at RVA 0x3590
			// Header size: 1
			// Code size: 31 (0x1f)
			.maxstack 8

			/* 0x00003590 03                 */ IL_0000: ldarg.1
			/* 0x00003591 6F28000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
			/* 0x00003596 02                 */ IL_0006: ldarg.0
			/* 0x00003597 7B7C000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
			/* 0x0000359C 02                 */ IL_000c: ldarg.0
			/* 0x0000359D 7B7B000004         */ IL_000d: ldfld int32 AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::pos /* 0400007B */
			/* 0x000035A2 17                 */ IL_0012: ldc.i4.1
			/* 0x000035A3 58                 */ IL_0013: add
			/* 0x000035A4 6F7200000A         */ IL_0014: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
			/* 0x000035A9 283F00000A         */ IL_0019: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x000035AE 2A                 */ IL_001e: ret
		} // end of method '<>c__DisplayClass5'::'<Find>b__1'

		.method /* 060000F4 */ public hidebysig 
			instance bool '<Find>b__2' (
				class AspenTech.Visualisation.Controls.Assistant.AssistScreen x
			) cil managed 
		{
			// Method begins at RVA 0x35b0
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x000035B0 03                 */ IL_0000: ldarg.1
			/* 0x000035B1 6F28000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
			/* 0x000035B6 02                 */ IL_0006: ldarg.0
			/* 0x000035B7 7B7C000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
			/* 0x000035BC 283F00000A         */ IL_000c: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x000035C1 2A                 */ IL_0011: ret
		} // end of method '<>c__DisplayClass5'::'<Find>b__2'

	} // end of class <>c__DisplayClass5

	.class /* 0200002B */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClass9'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000043 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400007D */ public string 'value'

		// Methods
		.method /* 060000F5 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x36cf
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x000036CF 02                 */ IL_0000: ldarg.0
			/* 0x000036D0 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
			/* 0x000036D5 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClass9'::.ctor

		.method /* 060000F6 */ public hidebysig 
			instance bool '<set_ScreenId>b__7' (
				class AspenTech.Visualisation.Controls.Assistant.AssistScreen x
			) cil managed 
		{
			// Method begins at RVA 0x36d7
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x000036D7 03                 */ IL_0000: ldarg.1
			/* 0x000036D8 6F28000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
			/* 0x000036DD 02                 */ IL_0006: ldarg.0
			/* 0x000036DE 7B7D000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass9'::'value' /* 0400007D */
			/* 0x000036E3 283F00000A         */ IL_000c: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x000036E8 2A                 */ IL_0011: ret
		} // end of method '<>c__DisplayClass9'::'<set_ScreenId>b__7'

	} // end of class <>c__DisplayClass9

	.class /* 0200002C */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClassc'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000045 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400007E */ public string 'opt'

		// Methods
		.method /* 060000F7 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x37b1
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x000037B1 02                 */ IL_0000: ldarg.0
			/* 0x000037B2 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
			/* 0x000037B7 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClassc'::.ctor

		.method /* 060000F8 */ public hidebysig 
			instance bool '<DefaultOption>b__b' (
				class AspenTech.Visualisation.Controls.Assistant.AssistOption x
			) cil managed 
		{
			// Method begins at RVA 0x37b9
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x000037B9 03                 */ IL_0000: ldarg.1
			/* 0x000037BA 6F28000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
			/* 0x000037BF 02                 */ IL_0006: ldarg.0
			/* 0x000037C0 7B7E000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClassc'::'opt' /* 0400007E */
			/* 0x000037C5 283F00000A         */ IL_000c: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x000037CA 2A                 */ IL_0011: ret
		} // end of method '<>c__DisplayClassc'::'<DefaultOption>b__b'

	} // end of class <>c__DisplayClassc

	.class /* 0200002D */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClass10'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000047 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400007F */ public class AspenTech.Visualisation.Controls.Assistant.AssistOption option

		// Methods
		.method /* 060000F9 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x383e
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x0000383E 02                 */ IL_0000: ldarg.0
			/* 0x0000383F 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
			/* 0x00003844 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClass10'::.ctor

		.method /* 060000FA */ public hidebysig 
			instance bool '<OptionCaption>b__e' (
				class AspenTech.Visualisation.Controls.Assistant.AssistScreen x
			) cil managed 
		{
			// Method begins at RVA 0x3846
			// Header size: 1
			// Code size: 23 (0x17)
			.maxstack 8

			/* 0x00003846 03                 */ IL_0000: ldarg.1
			/* 0x00003847 6F28000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
			/* 0x0000384C 02                 */ IL_0006: ldarg.0
			/* 0x0000384D 7B7F000004         */ IL_0007: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::option /* 0400007F */
			/* 0x00003852 6F8B000006         */ IL_000c: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
			/* 0x00003857 283F00000A         */ IL_0011: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x0000385C 2A                 */ IL_0016: ret
		} // end of method '<>c__DisplayClass10'::'<OptionCaption>b__e'

	} // end of class <>c__DisplayClass10


	// Fields
	.field /* 04000024 */ private class AspenTech.Visualisation.Controls.Assistant.AssistRoot _root
	.field /* 04000025 */ private class AspenTech.Visualisation.Controls.Assistant.AssistScreen _screen
	.field /* 04000026 */ private class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> _selected
	.field /* 04000027 */ private class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler _selectCommand
	.field /* 04000028 */ private class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler _redoCommand
	.field /* 04000029 */ private class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler _undoCommand
	.field /* 0400002A */ private class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> _history
	.field /* 0400002B */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.field /* 0400002C */ private class AspenTech.Visualisation.Controls.Assistant.IRootViewModel '<Root>k__BackingField'
	.custom /* 0C000044 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400002D */ private class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel '<Screen>k__BackingField'
	.custom /* 0C000046 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000065 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot assistant
		) cil managed 
	{
		// Method begins at RVA 0x34fc
		// Header size: 12
		// Code size: 97 (0x61)
		.maxstack 3

		/* 0x000034FC 02                 */ IL_0000: ldarg.0
		/* 0x000034FD 738100000A         */ IL_0001: newobj instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::.ctor() /* 0A000081 */
		/* 0x00003502 7D26000004         */ IL_0006: stfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003507 02                 */ IL_000b: ldarg.0
		/* 0x00003508 73AE00000A         */ IL_000c: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::.ctor() /* 0A0000AE */
		/* 0x0000350D 7D2A000004         */ IL_0011: stfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003512 02                 */ IL_0016: ldarg.0
		/* 0x00003513 284800000A         */ IL_0017: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00003518 02                 */ IL_001c: ldarg.0
		/* 0x00003519 03                 */ IL_001d: ldarg.1
		/* 0x0000351A 7D24000004         */ IL_001e: stfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x0000351F 02                 */ IL_0023: ldarg.0
		/* 0x00003520 7B26000004         */ IL_0024: ldfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003525 6FAF00000A         */ IL_0029: callvirt instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::Clear() /* 0A0000AF */
		/* 0x0000352A 02                 */ IL_002e: ldarg.0
		/* 0x0000352B 02                 */ IL_002f: ldarg.0
		/* 0x0000352C 7B24000004         */ IL_0030: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003531 7383000006         */ IL_0035: newobj instance void AspenTech.Visualisation.Controls.Assistant.RootViewModel::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 06000083 */
		/* 0x00003536 286D000006         */ IL_003a: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::set_Root(class AspenTech.Visualisation.Controls.Assistant.IRootViewModel) /* 0600006D */
		/* 0x0000353B 02                 */ IL_003f: ldarg.0
		/* 0x0000353C 7B26000004         */ IL_0040: ldfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003541 02                 */ IL_0045: ldarg.0
		/* 0x00003542 7B24000004         */ IL_0046: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003547 6F28000006         */ IL_004b: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x0000354C 02                 */ IL_0050: ldarg.0
		/* 0x0000354D 7B24000004         */ IL_0051: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003552 6F3F000006         */ IL_0056: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_First() /* 0600003F */
		/* 0x00003557 6FB000000A         */ IL_005b: callvirt instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::Add(!0, !1) /* 0A0000B0 */
		/* 0x0000355C 2A                 */ IL_0060: ret
	} // end of method AssistantViewModel::.ctor

	.method /* 06000066 */ private hidebysig 
		instance void Find (
			string path,
			[out] class AspenTech.Visualisation.Controls.Assistant.AssistScreen& screen,
			[out] class AspenTech.Visualisation.Controls.Assistant.AssistOption& option
		) cil managed 
	{
		// Method begins at RVA 0x35c4
		// Header size: 12
		// Code size: 242 (0xf2)
		.maxstack 5
		.locals /* 11000016 */ init (
			[0] class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>,
			[1] class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistOption, bool>,
			[2] class AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'
		)

		/* 0x000035C4 14                 */ IL_0000: ldnull
		/* 0x000035C5 0A                 */ IL_0001: stloc.0
		/* 0x000035C6 14                 */ IL_0002: ldnull
		/* 0x000035C7 0B                 */ IL_0003: stloc.1
		/* 0x000035C8 73F1000006         */ IL_0004: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::.ctor() /* 060000F1 */
		/* 0x000035CD 0C                 */ IL_0009: stloc.2
		/* 0x000035CE 08                 */ IL_000a: ldloc.2
		/* 0x000035CF 03                 */ IL_000b: ldarg.1
		/* 0x000035D0 7D7C000004         */ IL_000c: stfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x000035D5 04                 */ IL_0011: ldarg.2
		/* 0x000035D6 14                 */ IL_0012: ldnull
		/* 0x000035D7 51                 */ IL_0013: stind.ref
		/* 0x000035D8 05                 */ IL_0014: ldarg.3
		/* 0x000035D9 14                 */ IL_0015: ldnull
		/* 0x000035DA 51                 */ IL_0016: stind.ref
		/* 0x000035DB 08                 */ IL_0017: ldloc.2
		/* 0x000035DC 7B7C000004         */ IL_0018: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x000035E1 282C00000A         */ IL_001d: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000035E6 2C01               */ IL_0022: brfalse.s IL_0025
		/* 0x000035E8 2A                 */ IL_0024: ret
		/* 0x000035E9 08                 */ IL_0025: ldloc.2
		/* 0x000035EA 7B7C000004         */ IL_0026: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x000035EF 72B6040070         */ IL_002b: ldstr "assist:" /* 700004B6 */
		/* 0x000035F4 1B                 */ IL_0030: ldc.i4.5
		/* 0x000035F5 6F7000000A         */ IL_0031: callvirt instance bool [mscorlib]System.String::StartsWith(string, valuetype [mscorlib]System.StringComparison) /* 0A000070 */
		/* 0x000035FA 2C13               */ IL_0036: brfalse.s IL_004b
		/* 0x000035FC 08                 */ IL_0038: ldloc.2
		/* 0x000035FD 08                 */ IL_0039: ldloc.2
		/* 0x000035FE 7B7C000004         */ IL_003a: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x00003603 16                 */ IL_003f: ldc.i4.0
		/* 0x00003604 1D                 */ IL_0040: ldc.i4.7
		/* 0x00003605 6FB100000A         */ IL_0041: callvirt instance string [mscorlib]System.String::Remove(int32, int32) /* 0A0000B1 */
		/* 0x0000360A 7D7C000004         */ IL_0046: stfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x0000360F 08                 */ IL_004b: ldloc.2
		/* 0x00003610 7B7C000004         */ IL_004c: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x00003615 72FD010070         */ IL_0051: ldstr "/" /* 700001FD */
		/* 0x0000361A 6FB200000A         */ IL_0056: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x0000361F 2C13               */ IL_005b: brfalse.s IL_0070
		/* 0x00003621 08                 */ IL_005d: ldloc.2
		/* 0x00003622 08                 */ IL_005e: ldloc.2
		/* 0x00003623 7B7C000004         */ IL_005f: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x00003628 16                 */ IL_0064: ldc.i4.0
		/* 0x00003629 17                 */ IL_0065: ldc.i4.1
		/* 0x0000362A 6FB100000A         */ IL_0066: callvirt instance string [mscorlib]System.String::Remove(int32, int32) /* 0A0000B1 */
		/* 0x0000362F 7D7C000004         */ IL_006b: stfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x00003634 08                 */ IL_0070: ldloc.2
		/* 0x00003635 08                 */ IL_0071: ldloc.2
		/* 0x00003636 7B7C000004         */ IL_0072: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::path /* 0400007C */
		/* 0x0000363B 1F2F               */ IL_0077: ldc.i4.s 47
		/* 0x0000363D 6F7100000A         */ IL_0079: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x00003642 7D7B000004         */ IL_007e: stfld int32 AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::pos /* 0400007B */
		/* 0x00003647 08                 */ IL_0083: ldloc.2
		/* 0x00003648 7B7B000004         */ IL_0084: ldfld int32 AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::pos /* 0400007B */
		/* 0x0000364D 16                 */ IL_0089: ldc.i4.0
		/* 0x0000364E 3147               */ IL_008a: ble.s IL_00d3
		/* 0x00003650 04                 */ IL_008c: ldarg.2
		/* 0x00003651 02                 */ IL_008d: ldarg.0
		/* 0x00003652 7B24000004         */ IL_008e: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003657 6F39000006         */ IL_0093: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens() /* 06000039 */
		/* 0x0000365C 06                 */ IL_0098: ldloc.0
		/* 0x0000365D 2D0D               */ IL_0099: brtrue.s IL_00a8
		/* 0x0000365F 08                 */ IL_009b: ldloc.2
		/* 0x00003660 FE06F2000006       */ IL_009c: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::'<Find>b__0'(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 060000F2 */
		/* 0x00003666 73B300000A         */ IL_00a2: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>::.ctor(object, native int) /* 0A0000B3 */
		/* 0x0000366B 0A                 */ IL_00a7: stloc.0
		/* 0x0000366C 06                 */ IL_00a8: ldloc.0
		/* 0x0000366D 280500002B         */ IL_00a9: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000005 */
		/* 0x00003672 51                 */ IL_00ae: stind.ref
		/* 0x00003673 04                 */ IL_00af: ldarg.2
		/* 0x00003674 50                 */ IL_00b0: ldind.ref
		/* 0x00003675 2C3E               */ IL_00b1: brfalse.s IL_00f1
		/* 0x00003677 05                 */ IL_00b3: ldarg.3
		/* 0x00003678 04                 */ IL_00b4: ldarg.2
		/* 0x00003679 50                 */ IL_00b5: ldind.ref
		/* 0x0000367A 6FBA000006         */ IL_00b6: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x0000367F 07                 */ IL_00bb: ldloc.1
		/* 0x00003680 2D0D               */ IL_00bc: brtrue.s IL_00cb
		/* 0x00003682 08                 */ IL_00be: ldloc.2
		/* 0x00003683 FE06F3000006       */ IL_00bf: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::'<Find>b__1'(class AspenTech.Visualisation.Controls.Assistant.AssistOption) /* 060000F3 */
		/* 0x00003689 73B500000A         */ IL_00c5: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistOption, bool>::.ctor(object, native int) /* 0A0000B5 */
		/* 0x0000368E 0B                 */ IL_00ca: stloc.1
		/* 0x0000368F 07                 */ IL_00cb: ldloc.1
		/* 0x00003690 280600002B         */ IL_00cc: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.AssistOption>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000006 */
		/* 0x00003695 51                 */ IL_00d1: stind.ref
		/* 0x00003696 2A                 */ IL_00d2: ret
		/* 0x00003697 04                 */ IL_00d3: ldarg.2
		/* 0x00003698 02                 */ IL_00d4: ldarg.0
		/* 0x00003699 7B24000004         */ IL_00d5: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x0000369E 6F39000006         */ IL_00da: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens() /* 06000039 */
		/* 0x000036A3 08                 */ IL_00df: ldloc.2
		/* 0x000036A4 FE06F4000006       */ IL_00e0: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass5'::'<Find>b__2'(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 060000F4 */
		/* 0x000036AA 73B300000A         */ IL_00e6: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>::.ctor(object, native int) /* 0A0000B3 */
		/* 0x000036AF 280500002B         */ IL_00eb: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000005 */
		/* 0x000036B4 51                 */ IL_00f0: stind.ref
		/* 0x000036B5 2A                 */ IL_00f1: ret
	} // end of method AssistantViewModel::Find

	.method /* 06000067 */ public final hidebysig specialname newslot virtual 
		instance string get_ScreenId () cil managed 
	{
		// Method begins at RVA 0x36c2
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000036C2 02                 */ IL_0000: ldarg.0
		/* 0x000036C3 7B25000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x000036C8 6F28000006         */ IL_0006: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000036CD 2A                 */ IL_000b: ret
	} // end of method AssistantViewModel::get_ScreenId

	.method /* 06000068 */ public final hidebysig specialname newslot virtual 
		instance void set_ScreenId (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x36ec
		// Header size: 12
		// Code size: 185 (0xb9)
		.maxstack 4
		.locals /* 11000017 */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[1] int32,
			[2] class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>,
			[3] class AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass9'
		)

		/* 0x000036EC 14                 */ IL_0000: ldnull
		/* 0x000036ED 0C                 */ IL_0001: stloc.2
		/* 0x000036EE 73F5000006         */ IL_0002: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass9'::.ctor() /* 060000F5 */
		/* 0x000036F3 0D                 */ IL_0007: stloc.3
		/* 0x000036F4 09                 */ IL_0008: ldloc.3
		/* 0x000036F5 03                 */ IL_0009: ldarg.1
		/* 0x000036F6 7D7D000004         */ IL_000a: stfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass9'::'value' /* 0400007D */
		/* 0x000036FB 02                 */ IL_000f: ldarg.0
		/* 0x000036FC 7B24000004         */ IL_0010: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003701 399E000000         */ IL_0015: brfalse IL_00b8
		/* 0x00003706 02                 */ IL_001a: ldarg.0
		/* 0x00003707 7B25000004         */ IL_001b: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x0000370C 2C0D               */ IL_0020: brfalse.s IL_002f
		/* 0x0000370E 02                 */ IL_0022: ldarg.0
		/* 0x0000370F 7B25000004         */ IL_0023: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003714 6F28000006         */ IL_0028: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00003719 2B01               */ IL_002d: br.s IL_0030
		/* 0x0000371B 14                 */ IL_002f: ldnull
		/* 0x0000371C 09                 */ IL_0030: ldloc.3
		/* 0x0000371D 7B7D000004         */ IL_0031: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass9'::'value' /* 0400007D */
		/* 0x00003722 285300000A         */ IL_0036: call bool [mscorlib]System.String::op_Inequality(string, string) /* 0A000053 */
		/* 0x00003727 2C7B               */ IL_003b: brfalse.s IL_00b8
		/* 0x00003729 02                 */ IL_003d: ldarg.0
		/* 0x0000372A 7B24000004         */ IL_003e: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x0000372F 6F39000006         */ IL_0043: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens() /* 06000039 */
		/* 0x00003734 08                 */ IL_0048: ldloc.2
		/* 0x00003735 2D0D               */ IL_0049: brtrue.s IL_0058
		/* 0x00003737 09                 */ IL_004b: ldloc.3
		/* 0x00003738 FE06F6000006       */ IL_004c: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass9'::'<set_ScreenId>b__7'(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 060000F6 */
		/* 0x0000373E 73B300000A         */ IL_0052: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>::.ctor(object, native int) /* 0A0000B3 */
		/* 0x00003743 0C                 */ IL_0057: stloc.2
		/* 0x00003744 08                 */ IL_0058: ldloc.2
		/* 0x00003745 280500002B         */ IL_0059: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000005 */
		/* 0x0000374A 0A                 */ IL_005e: stloc.0
		/* 0x0000374B 06                 */ IL_005f: ldloc.0
		/* 0x0000374C 2C56               */ IL_0060: brfalse.s IL_00b8
		/* 0x0000374E 16                 */ IL_0062: ldc.i4.0
		/* 0x0000374F 0B                 */ IL_0063: stloc.1
		/* 0x00003750 2B31               */ IL_0064: br.s IL_0097
		/* 0x00003752 02                 */ IL_0066: ldarg.0
		/* 0x00003753 7B2A000004         */ IL_0067: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003758 07                 */ IL_006c: ldloc.1
		/* 0x00003759 6FB600000A         */ IL_006d: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Item(int32) /* 0A0000B6 */
		/* 0x0000375E 06                 */ IL_0072: ldloc.0
		/* 0x0000375F 331E               */ IL_0073: bne.un.s IL_0093
		/* 0x00003761 2B0C               */ IL_0075: br.s IL_0083
		/* 0x00003763 02                 */ IL_0077: ldarg.0
		/* 0x00003764 7B2A000004         */ IL_0078: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003769 07                 */ IL_007d: ldloc.1
		/* 0x0000376A 6FB700000A         */ IL_007e: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::RemoveAt(int32) /* 0A0000B7 */
		/* 0x0000376F 07                 */ IL_0083: ldloc.1
		/* 0x00003770 02                 */ IL_0084: ldarg.0
		/* 0x00003771 7B2A000004         */ IL_0085: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003776 6FB800000A         */ IL_008a: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x0000377B 32E6               */ IL_008f: blt.s IL_0077
		/* 0x0000377D 2B12               */ IL_0091: br.s IL_00a5
		/* 0x0000377F 07                 */ IL_0093: ldloc.1
		/* 0x00003780 17                 */ IL_0094: ldc.i4.1
		/* 0x00003781 58                 */ IL_0095: add
		/* 0x00003782 0B                 */ IL_0096: stloc.1
		/* 0x00003783 07                 */ IL_0097: ldloc.1
		/* 0x00003784 02                 */ IL_0098: ldarg.0
		/* 0x00003785 7B2A000004         */ IL_0099: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x0000378A 6FB800000A         */ IL_009e: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x0000378F 32C1               */ IL_00a3: blt.s IL_0066
		/* 0x00003791 02                 */ IL_00a5: ldarg.0
		/* 0x00003792 7B2A000004         */ IL_00a6: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003797 06                 */ IL_00ab: ldloc.0
		/* 0x00003798 6FB900000A         */ IL_00ac: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::Add(!0) /* 0A0000B9 */
		/* 0x0000379D 02                 */ IL_00b1: ldarg.0
		/* 0x0000379E 06                 */ IL_00b2: ldloc.0
		/* 0x0000379F 286B000006         */ IL_00b3: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::SelectScreen(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 0600006B */
		/* 0x000037A4 2A                 */ IL_00b8: ret
	} // end of method AssistantViewModel::set_ScreenId

	.method /* 06000069 */ private hidebysig 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistOption DefaultOption (
			class AspenTech.Visualisation.Controls.Assistant.AssistScreen screen,
			bool includeSelections
		) cil managed 
	{
		// Method begins at RVA 0x37cc
		// Header size: 12
		// Code size: 102 (0x66)
		.maxstack 4
		.locals /* 11000018 */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClassc'
		)

		/* 0x000037CC 03                 */ IL_0000: ldarg.1
		/* 0x000037CD 2D0C               */ IL_0001: brtrue.s IL_000f
		/* 0x000037CF 02                 */ IL_0003: ldarg.0
		/* 0x000037D0 7B24000004         */ IL_0004: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x000037D5 7390000006         */ IL_0009: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 06000090 */
		/* 0x000037DA 2A                 */ IL_000e: ret
		/* 0x000037DB 03                 */ IL_000f: ldarg.1
		/* 0x000037DC 6FBA000006         */ IL_0010: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x000037E1 6FBA00000A         */ IL_0015: callvirt instance int32 class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::get_Count() /* 0A0000BA */
		/* 0x000037E6 17                 */ IL_001a: ldc.i4.1
		/* 0x000037E7 330D               */ IL_001b: bne.un.s IL_002a
		/* 0x000037E9 03                 */ IL_001d: ldarg.1
		/* 0x000037EA 6FBA000006         */ IL_001e: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x000037EF 16                 */ IL_0023: ldc.i4.0
		/* 0x000037F0 6FBB00000A         */ IL_0024: callvirt instance !0 class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::get_Item(int32) /* 0A0000BB */
		/* 0x000037F5 2A                 */ IL_0029: ret
		/* 0x000037F6 04                 */ IL_002a: ldarg.2
		/* 0x000037F7 2C37               */ IL_002b: brfalse.s IL_0064
		/* 0x000037F9 73F7000006         */ IL_002d: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClassc'::.ctor() /* 060000F7 */
		/* 0x000037FE 0A                 */ IL_0032: stloc.0
		/* 0x000037FF 02                 */ IL_0033: ldarg.0
		/* 0x00003800 7B26000004         */ IL_0034: ldfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003805 03                 */ IL_0039: ldarg.1
		/* 0x00003806 6F28000006         */ IL_003a: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x0000380B 06                 */ IL_003f: ldloc.0
		/* 0x0000380C 7C7E000004         */ IL_0040: ldflda string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClassc'::'opt' /* 0400007E */
		/* 0x00003811 6FBC00000A         */ IL_0045: callvirt instance bool class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::TryGetValue(!0, !1&) /* 0A0000BC */
		/* 0x00003816 2C18               */ IL_004a: brfalse.s IL_0064
		/* 0x00003818 03                 */ IL_004c: ldarg.1
		/* 0x00003819 6FBA000006         */ IL_004d: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x0000381E 06                 */ IL_0052: ldloc.0
		/* 0x0000381F FE06F8000006       */ IL_0053: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClassc'::'<DefaultOption>b__b'(class AspenTech.Visualisation.Controls.Assistant.AssistOption) /* 060000F8 */
		/* 0x00003825 73B500000A         */ IL_0059: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistOption, bool>::.ctor(object, native int) /* 0A0000B5 */
		/* 0x0000382A 280600002B         */ IL_005e: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.AssistOption>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000006 */
		/* 0x0000382F 2A                 */ IL_0063: ret
		/* 0x00003830 14                 */ IL_0064: ldnull
		/* 0x00003831 2A                 */ IL_0065: ret
	} // end of method AssistantViewModel::DefaultOption

	.method /* 0600006A */ private hidebysig 
		instance string OptionCaption (
			class AspenTech.Visualisation.Controls.Assistant.AssistOption option
		) cil managed 
	{
		// Method begins at RVA 0x3860
		// Header size: 12
		// Code size: 205 (0xcd)
		.maxstack 4
		.locals /* 11000019 */ init (
			[0] class [mscorlib]System.Text.StringBuilder,
			[1] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[2] string,
			[3] class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>,
			[4] class AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10',
			[5] valuetype AspenTech.Visualisation.Controls.Assistant.Action
		)

		/* 0x00003860 14                 */ IL_0000: ldnull
		/* 0x00003861 0D                 */ IL_0001: stloc.3
		/* 0x00003862 73F9000006         */ IL_0002: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::.ctor() /* 060000F9 */
		/* 0x00003867 1304               */ IL_0007: stloc.s 4
		/* 0x00003869 1104               */ IL_0009: ldloc.s 4
		/* 0x0000386B 03                 */ IL_000b: ldarg.1
		/* 0x0000386C 7D7F000004         */ IL_000c: stfld class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::option /* 0400007F */
		/* 0x00003871 1104               */ IL_0011: ldloc.s 4
		/* 0x00003873 7B7F000004         */ IL_0013: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::option /* 0400007F */
		/* 0x00003878 2D02               */ IL_0018: brtrue.s IL_001c
		/* 0x0000387A 14                 */ IL_001a: ldnull
		/* 0x0000387B 2A                 */ IL_001b: ret
		/* 0x0000387C 739200000A         */ IL_001c: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000092 */
		/* 0x00003881 0A                 */ IL_0021: stloc.0
		/* 0x00003882 1104               */ IL_0022: ldloc.s 4
		/* 0x00003884 7B7F000004         */ IL_0024: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::option /* 0400007F */
		/* 0x00003889 6F2F000006         */ IL_0029: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x0000388E 2C13               */ IL_002e: brfalse.s IL_0043
		/* 0x00003890 06                 */ IL_0030: ldloc.0
		/* 0x00003891 1104               */ IL_0031: ldloc.s 4
		/* 0x00003893 7B7F000004         */ IL_0033: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::option /* 0400007F */
		/* 0x00003898 6F2F000006         */ IL_0038: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x0000389D 6FBD00000A         */ IL_003d: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A0000BD */
		/* 0x000038A2 26                 */ IL_0042: pop
		/* 0x000038A3 06                 */ IL_0043: ldloc.0
		/* 0x000038A4 6FBE00000A         */ IL_0044: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::AppendLine() /* 0A0000BE */
		/* 0x000038A9 26                 */ IL_0049: pop
		/* 0x000038AA 1104               */ IL_004a: ldloc.s 4
		/* 0x000038AC 7B7F000004         */ IL_004c: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::option /* 0400007F */
		/* 0x000038B1 6F89000006         */ IL_0051: callvirt instance valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Action() /* 06000089 */
		/* 0x000038B6 1305               */ IL_0056: stloc.s 5
		/* 0x000038B8 1105               */ IL_0058: ldloc.s 5
		/* 0x000038BA 17                 */ IL_005a: ldc.i4.1
		/* 0x000038BB 59                 */ IL_005b: sub
		/* 0x000038BC 4502000000         */ IL_005c: switch (
		/*              02000000         */                  IL_006b,
		/*              02000000         */                  IL_006b)
		/* 0x000038C9 2B40               */ IL_0069: br.s IL_00ab
		/* 0x000038CB 02                 */ IL_006b: ldarg.0
		/* 0x000038CC 7B24000004         */ IL_006c: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x000038D1 6F39000006         */ IL_0071: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens() /* 06000039 */
		/* 0x000038D6 09                 */ IL_0076: ldloc.3
		/* 0x000038D7 2D0E               */ IL_0077: brtrue.s IL_0087
		/* 0x000038D9 1104               */ IL_0079: ldloc.s 4
		/* 0x000038DB FE06FA000006       */ IL_007b: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel/'<>c__DisplayClass10'::'<OptionCaption>b__e'(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 060000FA */
		/* 0x000038E1 73B300000A         */ IL_0081: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool>::.ctor(object, native int) /* 0A0000B3 */
		/* 0x000038E6 0D                 */ IL_0086: stloc.3
		/* 0x000038E7 09                 */ IL_0087: ldloc.3
		/* 0x000038E8 280500002B         */ IL_0088: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000005 */
		/* 0x000038ED 0B                 */ IL_008d: stloc.1
		/* 0x000038EE 07                 */ IL_008e: ldloc.1
		/* 0x000038EF 2C1A               */ IL_008f: brfalse.s IL_00ab
		/* 0x000038F1 07                 */ IL_0091: ldloc.1
		/* 0x000038F2 6F2F000006         */ IL_0092: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x000038F7 282C00000A         */ IL_0097: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000038FC 2D0D               */ IL_009c: brtrue.s IL_00ab
		/* 0x000038FE 06                 */ IL_009e: ldloc.0
		/* 0x000038FF 07                 */ IL_009f: ldloc.1
		/* 0x00003900 6F2F000006         */ IL_00a0: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00003905 6FBD00000A         */ IL_00a5: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A0000BD */
		/* 0x0000390A 26                 */ IL_00aa: pop
		/* 0x0000390B 06                 */ IL_00ab: ldloc.0
		/* 0x0000390C 6FBF00000A         */ IL_00ac: callvirt instance int32 [mscorlib]System.Text.StringBuilder::get_Length() /* 0A0000BF */
		/* 0x00003911 2D02               */ IL_00b1: brtrue.s IL_00b5
		/* 0x00003913 14                 */ IL_00b3: ldnull
		/* 0x00003914 2A                 */ IL_00b4: ret
		/* 0x00003915 06                 */ IL_00b5: ldloc.0
		/* 0x00003916 6F6000000A         */ IL_00b6: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x0000391B 6F2700000A         */ IL_00bb: callvirt instance string [mscorlib]System.String::Trim() /* 0A000027 */
		/* 0x00003920 0C                 */ IL_00c0: stloc.2
		/* 0x00003921 08                 */ IL_00c1: ldloc.2
		/* 0x00003922 282C00000A         */ IL_00c2: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00003927 2C02               */ IL_00c7: brfalse.s IL_00cb
		/* 0x00003929 14                 */ IL_00c9: ldnull
		/* 0x0000392A 2A                 */ IL_00ca: ret
		/* 0x0000392B 08                 */ IL_00cb: ldloc.2
		/* 0x0000392C 2A                 */ IL_00cc: ret
	} // end of method AssistantViewModel::OptionCaption

	.method /* 0600006B */ private hidebysig 
		instance void SelectScreen (
			class AspenTech.Visualisation.Controls.Assistant.AssistScreen screen
		) cil managed 
	{
		// Method begins at RVA 0x393c
		// Header size: 12
		// Code size: 164 (0xa4)
		.maxstack 5
		.locals /* 1100001A */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistScreen
		)

		/* 0x0000393C 02                 */ IL_0000: ldarg.0
		/* 0x0000393D 02                 */ IL_0001: ldarg.0
		/* 0x0000393E 03                 */ IL_0002: ldarg.1
		/* 0x0000393F 25                 */ IL_0003: dup
		/* 0x00003940 0A                 */ IL_0004: stloc.0
		/* 0x00003941 7D25000004         */ IL_0005: stfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003946 06                 */ IL_000a: ldloc.0
		/* 0x00003947 7386000006         */ IL_000b: newobj instance void AspenTech.Visualisation.Controls.Assistant.ScreenViewModel::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 06000086 */
		/* 0x0000394C 286F000006         */ IL_0010: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::set_Screen(class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel) /* 0600006F */
		/* 0x00003951 02                 */ IL_0015: ldarg.0
		/* 0x00003952 72C6040070         */ IL_0016: ldstr "ScreenId" /* 700004C6 */
		/* 0x00003957 287B000006         */ IL_001b: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::DoPropertyChanged(string) /* 0600007B */
		/* 0x0000395C 02                 */ IL_0020: ldarg.0
		/* 0x0000395D 72D8040070         */ IL_0021: ldstr "Screen" /* 700004D8 */
		/* 0x00003962 287B000006         */ IL_0026: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::DoPropertyChanged(string) /* 0600007B */
		/* 0x00003967 02                 */ IL_002b: ldarg.0
		/* 0x00003968 7B28000004         */ IL_002c: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x0000396D 2C24               */ IL_0031: brfalse.s IL_0057
		/* 0x0000396F 02                 */ IL_0033: ldarg.0
		/* 0x00003970 7B28000004         */ IL_0034: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x00003975 02                 */ IL_0039: ldarg.0
		/* 0x00003976 02                 */ IL_003a: ldarg.0
		/* 0x00003977 03                 */ IL_003b: ldarg.1
		/* 0x00003978 17                 */ IL_003c: ldc.i4.1
		/* 0x00003979 2869000006         */ IL_003d: call instance class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::DefaultOption(class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool) /* 06000069 */
		/* 0x0000397E 286A000006         */ IL_0042: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::OptionCaption(class AspenTech.Visualisation.Controls.Assistant.AssistOption) /* 0600006A */
		/* 0x00003983 6F1E000006         */ IL_0047: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::set_ToolTip(string) /* 0600001E */
		/* 0x00003988 02                 */ IL_004c: ldarg.0
		/* 0x00003989 7B28000004         */ IL_004d: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x0000398E 6F18000006         */ IL_0052: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::RaiseCanExecuteChanged() /* 06000018 */
		/* 0x00003993 02                 */ IL_0057: ldarg.0
		/* 0x00003994 7B29000004         */ IL_0058: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x00003999 2C44               */ IL_005d: brfalse.s IL_00a3
		/* 0x0000399B 02                 */ IL_005f: ldarg.0
		/* 0x0000399C 7B29000004         */ IL_0060: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x000039A1 02                 */ IL_0065: ldarg.0
		/* 0x000039A2 7B2A000004         */ IL_0066: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x000039A7 6FB800000A         */ IL_006b: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x000039AC 17                 */ IL_0070: ldc.i4.1
		/* 0x000039AD 3003               */ IL_0071: bgt.s IL_0076
		/* 0x000039AF 14                 */ IL_0073: ldnull
		/* 0x000039B0 2B1D               */ IL_0074: br.s IL_0093
		/* 0x000039B2 02                 */ IL_0076: ldarg.0
		/* 0x000039B3 7B2A000004         */ IL_0077: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x000039B8 02                 */ IL_007c: ldarg.0
		/* 0x000039B9 7B2A000004         */ IL_007d: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x000039BE 6FB800000A         */ IL_0082: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x000039C3 18                 */ IL_0087: ldc.i4.2
		/* 0x000039C4 59                 */ IL_0088: sub
		/* 0x000039C5 6FB600000A         */ IL_0089: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Item(int32) /* 0A0000B6 */
		/* 0x000039CA 6F2F000006         */ IL_008e: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x000039CF 6F1E000006         */ IL_0093: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::set_ToolTip(string) /* 0600001E */
		/* 0x000039D4 02                 */ IL_0098: ldarg.0
		/* 0x000039D5 7B29000004         */ IL_0099: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x000039DA 6F18000006         */ IL_009e: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::RaiseCanExecuteChanged() /* 06000018 */
		/* 0x000039DF 2A                 */ IL_00a3: ret
	} // end of method AssistantViewModel::SelectScreen

	.method /* 0600006C */ public final hidebysig specialname newslot virtual 
		instance class AspenTech.Visualisation.Controls.Assistant.IRootViewModel get_Root () cil managed 
	{
		.custom /* 0C000072 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x39ec
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000039EC 02                 */ IL_0000: ldarg.0
		/* 0x000039ED 7B2C000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.IRootViewModel AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<Root>k__BackingField' /* 0400002C */
		/* 0x000039F2 2A                 */ IL_0006: ret
	} // end of method AssistantViewModel::get_Root

	.method /* 0600006D */ private hidebysig specialname 
		instance void set_Root (
			class AspenTech.Visualisation.Controls.Assistant.IRootViewModel 'value'
		) cil managed 
	{
		.custom /* 0C000073 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x39f4
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000039F4 02                 */ IL_0000: ldarg.0
		/* 0x000039F5 03                 */ IL_0001: ldarg.1
		/* 0x000039F6 7D2C000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.IRootViewModel AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<Root>k__BackingField' /* 0400002C */
		/* 0x000039FB 2A                 */ IL_0007: ret
	} // end of method AssistantViewModel::set_Root

	.method /* 0600006E */ public final hidebysig specialname newslot virtual 
		instance class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel get_Screen () cil managed 
	{
		.custom /* 0C000074 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x39fd
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000039FD 02                 */ IL_0000: ldarg.0
		/* 0x000039FE 7B2D000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<Screen>k__BackingField' /* 0400002D */
		/* 0x00003A03 2A                 */ IL_0006: ret
	} // end of method AssistantViewModel::get_Screen

	.method /* 0600006F */ private hidebysig specialname 
		instance void set_Screen (
			class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel 'value'
		) cil managed 
	{
		.custom /* 0C000075 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3a05
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00003A05 02                 */ IL_0000: ldarg.0
		/* 0x00003A06 03                 */ IL_0001: ldarg.1
		/* 0x00003A07 7D2D000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<Screen>k__BackingField' /* 0400002D */
		/* 0x00003A0C 2A                 */ IL_0007: ret
	} // end of method AssistantViewModel::set_Screen

	.method /* 06000070 */ public final hidebysig newslot virtual 
		instance string RenderToHtml (
			valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget target
		) cil managed 
	{
		// Method begins at RVA 0x3a10
		// Header size: 12
		// Code size: 316 (0x13c)
		.maxstack 5
		.locals /* 1100001B */ init (
			[0] class [mscorlib]System.Text.StringBuilder,
			[1] class [mscorlib]System.IO.StringWriter,
			[2] class [System.Web]System.Web.UI.HtmlTextWriter,
			[3] string
		)

		/* 0x00003A10 739200000A         */ IL_0000: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000092 */
		/* 0x00003A15 0A                 */ IL_0005: stloc.0
		/* 0x00003A16 06                 */ IL_0006: ldloc.0
		/* 0x00003A17 73C000000A         */ IL_0007: newobj instance void [mscorlib]System.IO.StringWriter::.ctor(class [mscorlib]System.Text.StringBuilder) /* 0A0000C0 */
		/* 0x00003A1C 0B                 */ IL_000c: stloc.1
		/* 0x00003A1D 07                 */ IL_000d: ldloc.1
		/* 0x00003A1E 73C100000A         */ IL_000e: newobj instance void [System.Web]System.Web.UI.HtmlTextWriter::.ctor(class [mscorlib]System.IO.TextWriter) /* 0A0000C1 */
		/* 0x00003A23 0C                 */ IL_0013: stloc.2
		/* 0x00003A24 08                 */ IL_0014: ldloc.2
		/* 0x00003A25 72F3010070         */ IL_0015: ldstr "html" /* 700001F3 */
		/* 0x00003A2A 6F5B00000A         */ IL_001a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003A2F 08                 */ IL_001f: ldloc.2
		/* 0x00003A30 72E6040070         */ IL_0020: ldstr "http-equiv" /* 700004E6 */
		/* 0x00003A35 72FC040070         */ IL_0025: ldstr "Content-Type" /* 700004FC */
		/* 0x00003A3A 6FC200000A         */ IL_002a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(string, string) /* 0A0000C2 */
		/* 0x00003A3F 08                 */ IL_002f: ldloc.2
		/* 0x00003A40 7216050070         */ IL_0030: ldstr "content" /* 70000516 */
		/* 0x00003A45 7226050070         */ IL_0035: ldstr "text/html;charset=utf-16" /* 70000526 */
		/* 0x00003A4A 6FC200000A         */ IL_003a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(string, string) /* 0A0000C2 */
		/* 0x00003A4F 08                 */ IL_003f: ldloc.2
		/* 0x00003A50 7258050070         */ IL_0040: ldstr "meta" /* 70000558 */
		/* 0x00003A55 6F5B00000A         */ IL_0045: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003A5A 08                 */ IL_004a: ldloc.2
		/* 0x00003A5B 6F5E00000A         */ IL_004b: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003A60 08                 */ IL_0050: ldloc.2
		/* 0x00003A61 7262050070         */ IL_0051: ldstr "head" /* 70000562 */
		/* 0x00003A66 6F5B00000A         */ IL_0056: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003A6B 08                 */ IL_005b: ldloc.2
		/* 0x00003A6C 1F59               */ IL_005c: ldc.i4.s 89
		/* 0x00003A6E 02                 */ IL_005e: ldarg.0
		/* 0x00003A6F 7B25000004         */ IL_005f: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003A74 2C0D               */ IL_0064: brfalse.s IL_0073
		/* 0x00003A76 02                 */ IL_0066: ldarg.0
		/* 0x00003A77 7B25000004         */ IL_0067: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003A7C 6F2F000006         */ IL_006c: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00003A81 2B0B               */ IL_0071: br.s IL_007e
		/* 0x00003A83 02                 */ IL_0073: ldarg.0
		/* 0x00003A84 7B24000004         */ IL_0074: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003A89 6F2F000006         */ IL_0079: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00003A8E 28B9000006         */ IL_007e: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00003A93 26                 */ IL_0083: pop
		/* 0x00003A94 08                 */ IL_0084: ldloc.2
		/* 0x00003A95 726C050070         */ IL_0085: ldstr "AspenTech.Visualisation.Controls.Assistant." /* 7000056C */
		/* 0x00003A9A 03                 */ IL_008a: ldarg.1
		/* 0x00003A9B 8C1F000002         */ IL_008b: box AspenTech.Visualisation.Controls.Assistant.RenderTarget /* 0200001F */
		/* 0x00003AA0 6F6000000A         */ IL_0090: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00003AA5 72C4050070         */ IL_0095: ldstr ".css" /* 700005C4 */
		/* 0x00003AAA 286300000A         */ IL_009a: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000063 */
		/* 0x00003AAF 2822000006         */ IL_009f: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderStyleFile(class [System.Web]System.Web.UI.HtmlTextWriter, string) /* 06000022 */
		/* 0x00003AB4 08                 */ IL_00a4: ldloc.2
		/* 0x00003AB5 6F5E00000A         */ IL_00a5: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003ABA 08                 */ IL_00aa: ldloc.2
		/* 0x00003ABB 72CE050070         */ IL_00ab: ldstr "body" /* 700005CE */
		/* 0x00003AC0 6F5B00000A         */ IL_00b0: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003AC5 02                 */ IL_00b5: ldarg.0
		/* 0x00003AC6 7B25000004         */ IL_00b6: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003ACB 2D1F               */ IL_00bb: brtrue.s IL_00dc
		/* 0x00003ACD 08                 */ IL_00bd: ldloc.2
		/* 0x00003ACE 02                 */ IL_00be: ldarg.0
		/* 0x00003ACF 7B24000004         */ IL_00bf: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003AD4 18                 */ IL_00c4: ldc.i4.2
		/* 0x00003AD5 72B6040070         */ IL_00c5: ldstr "assist:" /* 700004B6 */
		/* 0x00003ADA 02                 */ IL_00ca: ldarg.0
		/* 0x00003ADB 7B24000004         */ IL_00cb: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003AE0 6F3F000006         */ IL_00d0: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_First() /* 0600003F */
		/* 0x00003AE5 2825000006         */ IL_00d5: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderAsHtml(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistRoot, valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle, string, string) /* 06000025 */
		/* 0x00003AEA 2B2C               */ IL_00da: br.s IL_0108
		/* 0x00003AEC 02                 */ IL_00dc: ldarg.0
		/* 0x00003AED 7B26000004         */ IL_00dd: ldfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003AF2 02                 */ IL_00e2: ldarg.0
		/* 0x00003AF3 7B25000004         */ IL_00e3: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003AF8 6F28000006         */ IL_00e8: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00003AFD 1203               */ IL_00ed: ldloca.s 3
		/* 0x00003AFF 6FBC00000A         */ IL_00ef: callvirt instance bool class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::TryGetValue(!0, !1&) /* 0A0000BC */
		/* 0x00003B04 26                 */ IL_00f4: pop
		/* 0x00003B05 08                 */ IL_00f5: ldloc.2
		/* 0x00003B06 02                 */ IL_00f6: ldarg.0
		/* 0x00003B07 7B25000004         */ IL_00f7: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003B0C 18                 */ IL_00fc: ldc.i4.2
		/* 0x00003B0D 72B6040070         */ IL_00fd: ldstr "assist:" /* 700004B6 */
		/* 0x00003B12 09                 */ IL_0102: ldloc.3
		/* 0x00003B13 2826000006         */ IL_0103: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderAsHtml(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistScreen, valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle, string, string) /* 06000026 */
		/* 0x00003B18 08                 */ IL_0108: ldloc.2
		/* 0x00003B19 6F5E00000A         */ IL_0109: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003B1E 08                 */ IL_010e: ldloc.2
		/* 0x00003B1F 6F5E00000A         */ IL_010f: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003B24 DE07               */ IL_0114: leave.s IL_011d
		/* 0x00003B26 08                 */ IL_0116: ldloc.2
		/* 0x00003B27 6FC300000A         */ IL_0117: callvirt instance void [mscorlib]System.IO.TextWriter::Close() /* 0A0000C3 */
		/* 0x00003B2C DC                 */ IL_011c: endfinally
		/* 0x00003B2D DE0A               */ IL_011d: leave.s IL_0129
		/* 0x00003B2F 08                 */ IL_011f: ldloc.2
		/* 0x00003B30 2C06               */ IL_0120: brfalse.s IL_0128
		/* 0x00003B32 08                 */ IL_0122: ldloc.2
		/* 0x00003B33 6F6D00000A         */ IL_0123: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00003B38 DC                 */ IL_0128: endfinally
		/* 0x00003B39 DE0A               */ IL_0129: leave.s IL_0135
		/* 0x00003B3B 07                 */ IL_012b: ldloc.1
		/* 0x00003B3C 2C06               */ IL_012c: brfalse.s IL_0134
		/* 0x00003B3E 07                 */ IL_012e: ldloc.1
		/* 0x00003B3F 6F6D00000A         */ IL_012f: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00003B44 DC                 */ IL_0134: endfinally
		/* 0x00003B45 06                 */ IL_0135: ldloc.0
		/* 0x00003B46 6F6000000A         */ IL_0136: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00003B4B 2A                 */ IL_013b: ret

		.try IL_0014-IL_0116 finally IL_0116-IL_011d
		.try IL_0014-IL_011f finally IL_011f-IL_0129
		.try IL_000d-IL_012b finally IL_012b-IL_0135
	} // end of method AssistantViewModel::RenderToHtml

	.method /* 06000071 */ public final hidebysig newslot virtual 
		instance string RenderAllToHtml (
			valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget target
		) cil managed 
	{
		// Method begins at RVA 0x3ba4
		// Header size: 12
		// Code size: 344 (0x158)
		.maxstack 5
		.locals /* 1100001C */ init (
			[0] class [mscorlib]System.Text.StringBuilder,
			[1] class [mscorlib]System.IO.StringWriter,
			[2] class [System.Web]System.Web.UI.HtmlTextWriter,
			[3] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[4] string,
			[5] class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>
		)

		/* 0x00003BA4 739200000A         */ IL_0000: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000092 */
		/* 0x00003BA9 0A                 */ IL_0005: stloc.0
		/* 0x00003BAA 06                 */ IL_0006: ldloc.0
		/* 0x00003BAB 73C000000A         */ IL_0007: newobj instance void [mscorlib]System.IO.StringWriter::.ctor(class [mscorlib]System.Text.StringBuilder) /* 0A0000C0 */
		/* 0x00003BB0 0B                 */ IL_000c: stloc.1
		/* 0x00003BB1 07                 */ IL_000d: ldloc.1
		/* 0x00003BB2 73C100000A         */ IL_000e: newobj instance void [System.Web]System.Web.UI.HtmlTextWriter::.ctor(class [mscorlib]System.IO.TextWriter) /* 0A0000C1 */
		/* 0x00003BB7 0C                 */ IL_0013: stloc.2
		/* 0x00003BB8 08                 */ IL_0014: ldloc.2
		/* 0x00003BB9 72F3010070         */ IL_0015: ldstr "html" /* 700001F3 */
		/* 0x00003BBE 6F5B00000A         */ IL_001a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003BC3 08                 */ IL_001f: ldloc.2
		/* 0x00003BC4 72E6040070         */ IL_0020: ldstr "http-equiv" /* 700004E6 */
		/* 0x00003BC9 72FC040070         */ IL_0025: ldstr "Content-Type" /* 700004FC */
		/* 0x00003BCE 6FC200000A         */ IL_002a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(string, string) /* 0A0000C2 */
		/* 0x00003BD3 08                 */ IL_002f: ldloc.2
		/* 0x00003BD4 7216050070         */ IL_0030: ldstr "content" /* 70000516 */
		/* 0x00003BD9 7226050070         */ IL_0035: ldstr "text/html;charset=utf-16" /* 70000526 */
		/* 0x00003BDE 6FC200000A         */ IL_003a: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::AddAttribute(string, string) /* 0A0000C2 */
		/* 0x00003BE3 08                 */ IL_003f: ldloc.2
		/* 0x00003BE4 7258050070         */ IL_0040: ldstr "meta" /* 70000558 */
		/* 0x00003BE9 6F5B00000A         */ IL_0045: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003BEE 08                 */ IL_004a: ldloc.2
		/* 0x00003BEF 6F5E00000A         */ IL_004b: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003BF4 08                 */ IL_0050: ldloc.2
		/* 0x00003BF5 7262050070         */ IL_0051: ldstr "head" /* 70000562 */
		/* 0x00003BFA 6F5B00000A         */ IL_0056: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003BFF 08                 */ IL_005b: ldloc.2
		/* 0x00003C00 1F59               */ IL_005c: ldc.i4.s 89
		/* 0x00003C02 02                 */ IL_005e: ldarg.0
		/* 0x00003C03 7B24000004         */ IL_005f: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003C08 6F2F000006         */ IL_0064: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00003C0D 28B9000006         */ IL_0069: call class [System.Web]System.Web.UI.HtmlTextWriter AspenTech.Visualisation.Controls.Assistant.Extensions::WriteTagText(class [System.Web]System.Web.UI.HtmlTextWriter, valuetype [System.Web]System.Web.UI.HtmlTextWriterTag, string) /* 060000B9 */
		/* 0x00003C12 26                 */ IL_006e: pop
		/* 0x00003C13 08                 */ IL_006f: ldloc.2
		/* 0x00003C14 726C050070         */ IL_0070: ldstr "AspenTech.Visualisation.Controls.Assistant." /* 7000056C */
		/* 0x00003C19 03                 */ IL_0075: ldarg.1
		/* 0x00003C1A 8C1F000002         */ IL_0076: box AspenTech.Visualisation.Controls.Assistant.RenderTarget /* 0200001F */
		/* 0x00003C1F 6F6000000A         */ IL_007b: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00003C24 72C4050070         */ IL_0080: ldstr ".css" /* 700005C4 */
		/* 0x00003C29 286300000A         */ IL_0085: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000063 */
		/* 0x00003C2E 2822000006         */ IL_008a: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderStyleFile(class [System.Web]System.Web.UI.HtmlTextWriter, string) /* 06000022 */
		/* 0x00003C33 08                 */ IL_008f: ldloc.2
		/* 0x00003C34 6F5E00000A         */ IL_0090: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003C39 08                 */ IL_0095: ldloc.2
		/* 0x00003C3A 72CE050070         */ IL_0096: ldstr "body" /* 700005CE */
		/* 0x00003C3F 6F5B00000A         */ IL_009b: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(string) /* 0A00005B */
		/* 0x00003C44 08                 */ IL_00a0: ldloc.2
		/* 0x00003C45 02                 */ IL_00a1: ldarg.0
		/* 0x00003C46 7B24000004         */ IL_00a2: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003C4B 17                 */ IL_00a7: ldc.i4.1
		/* 0x00003C4C 72B6040070         */ IL_00a8: ldstr "assist:" /* 700004B6 */
		/* 0x00003C51 02                 */ IL_00ad: ldarg.0
		/* 0x00003C52 7B24000004         */ IL_00ae: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003C57 6F3F000006         */ IL_00b3: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_First() /* 0600003F */
		/* 0x00003C5C 2825000006         */ IL_00b8: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderAsHtml(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistRoot, valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle, string, string) /* 06000025 */
		/* 0x00003C61 02                 */ IL_00bd: ldarg.0
		/* 0x00003C62 7B2A000004         */ IL_00be: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003C67 6FC400000A         */ IL_00c3: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::GetEnumerator() /* 0A0000C4 */
		/* 0x00003C6C 1305               */ IL_00c8: stloc.s 5
		/* 0x00003C6E 2B2B               */ IL_00ca: br.s IL_00f7
		/* 0x00003C70 1105               */ IL_00cc: ldloc.s 5
		/* 0x00003C72 6FC500000A         */ IL_00ce: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Current() /* 0A0000C5 */
		/* 0x00003C77 0D                 */ IL_00d3: stloc.3
		/* 0x00003C78 02                 */ IL_00d4: ldarg.0
		/* 0x00003C79 7B26000004         */ IL_00d5: ldfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003C7E 09                 */ IL_00da: ldloc.3
		/* 0x00003C7F 6F28000006         */ IL_00db: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00003C84 1204               */ IL_00e0: ldloca.s 4
		/* 0x00003C86 6FBC00000A         */ IL_00e2: callvirt instance bool class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::TryGetValue(!0, !1&) /* 0A0000BC */
		/* 0x00003C8B 26                 */ IL_00e7: pop
		/* 0x00003C8C 08                 */ IL_00e8: ldloc.2
		/* 0x00003C8D 09                 */ IL_00e9: ldloc.3
		/* 0x00003C8E 17                 */ IL_00ea: ldc.i4.1
		/* 0x00003C8F 72B6040070         */ IL_00eb: ldstr "assist:" /* 700004B6 */
		/* 0x00003C94 1104               */ IL_00f0: ldloc.s 4
		/* 0x00003C96 2826000006         */ IL_00f2: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderAsHtml(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistScreen, valuetype AspenTech.Visualisation.Controls.Assistant.HtmlStyle, string, string) /* 06000026 */
		/* 0x00003C9B 1105               */ IL_00f7: ldloc.s 5
		/* 0x00003C9D 6F7700000A         */ IL_00f9: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00003CA2 2DCC               */ IL_00fe: brtrue.s IL_00cc
		/* 0x00003CA4 DE0C               */ IL_0100: leave.s IL_010e
		/* 0x00003CA6 1105               */ IL_0102: ldloc.s 5
		/* 0x00003CA8 2C07               */ IL_0104: brfalse.s IL_010d
		/* 0x00003CAA 1105               */ IL_0106: ldloc.s 5
		/* 0x00003CAC 6F6D00000A         */ IL_0108: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00003CB1 DC                 */ IL_010d: endfinally
		/* 0x00003CB2 08                 */ IL_010e: ldloc.2
		/* 0x00003CB3 02                 */ IL_010f: ldarg.0
		/* 0x00003CB4 7B24000004         */ IL_0110: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_root /* 04000024 */
		/* 0x00003CB9 2823000006         */ IL_0115: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderAssistantInfo(class [System.Web]System.Web.UI.HtmlTextWriter, class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 06000023 */
		/* 0x00003CBE 03                 */ IL_011a: ldarg.1
		/* 0x00003CBF 17                 */ IL_011b: ldc.i4.1
		/* 0x00003CC0 3306               */ IL_011c: bne.un.s IL_0124
		/* 0x00003CC2 08                 */ IL_011e: ldloc.2
		/* 0x00003CC3 2824000006         */ IL_011f: call void AspenTech.Visualisation.Controls.Assistant.Renderer::RenderGenerationInfo(class [System.Web]System.Web.UI.HtmlTextWriter) /* 06000024 */
		/* 0x00003CC8 08                 */ IL_0124: ldloc.2
		/* 0x00003CC9 6F5E00000A         */ IL_0125: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003CCE 08                 */ IL_012a: ldloc.2
		/* 0x00003CCF 6F5E00000A         */ IL_012b: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x00003CD4 DE07               */ IL_0130: leave.s IL_0139
		/* 0x00003CD6 08                 */ IL_0132: ldloc.2
		/* 0x00003CD7 6FC300000A         */ IL_0133: callvirt instance void [mscorlib]System.IO.TextWriter::Close() /* 0A0000C3 */
		/* 0x00003CDC DC                 */ IL_0138: endfinally
		/* 0x00003CDD DE0A               */ IL_0139: leave.s IL_0145
		/* 0x00003CDF 08                 */ IL_013b: ldloc.2
		/* 0x00003CE0 2C06               */ IL_013c: brfalse.s IL_0144
		/* 0x00003CE2 08                 */ IL_013e: ldloc.2
		/* 0x00003CE3 6F6D00000A         */ IL_013f: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00003CE8 DC                 */ IL_0144: endfinally
		/* 0x00003CE9 DE0A               */ IL_0145: leave.s IL_0151
		/* 0x00003CEB 07                 */ IL_0147: ldloc.1
		/* 0x00003CEC 2C06               */ IL_0148: brfalse.s IL_0150
		/* 0x00003CEE 07                 */ IL_014a: ldloc.1
		/* 0x00003CEF 6F6D00000A         */ IL_014b: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00003CF4 DC                 */ IL_0150: endfinally
		/* 0x00003CF5 06                 */ IL_0151: ldloc.0
		/* 0x00003CF6 6F6000000A         */ IL_0152: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00003CFB 2A                 */ IL_0157: ret

		.try IL_00ca-IL_0102 finally IL_0102-IL_010e
		.try IL_0014-IL_0132 finally IL_0132-IL_0139
		.try IL_0014-IL_013b finally IL_013b-IL_0145
		.try IL_000d-IL_0147 finally IL_0147-IL_0151
	} // end of method AssistantViewModel::RenderAllToHtml

	.method /* 06000072 */ public final hidebysig specialname newslot virtual 
		instance class [PresentationCore]System.Windows.Input.ICommand get_SelectCommand () cil managed 
	{
		// Method begins at RVA 0x3dd1
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x00003DD1 02                 */ IL_0000: ldarg.0
		/* 0x00003DD2 7B27000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selectCommand /* 04000027 */
		/* 0x00003DD7 2D23               */ IL_0006: brtrue.s IL_002b
		/* 0x00003DD9 02                 */ IL_0008: ldarg.0
		/* 0x00003DDA 02                 */ IL_0009: ldarg.0
		/* 0x00003DDB FE067C000006       */ IL_000a: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<get_SelectCommand>b__12'(object) /* 0600007C */
		/* 0x00003DE1 7310000006         */ IL_0010: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute::.ctor(object, native int) /* 06000010 */
		/* 0x00003DE6 02                 */ IL_0015: ldarg.0
		/* 0x00003DE7 FE067D000006       */ IL_0016: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<get_SelectCommand>b__13'(object) /* 0600007D */
		/* 0x00003DED 730C000006         */ IL_001c: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute::.ctor(object, native int) /* 0600000C */
		/* 0x00003DF2 7317000006         */ IL_0021: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::.ctor(class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute, class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute) /* 06000017 */
		/* 0x00003DF7 7D27000004         */ IL_0026: stfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selectCommand /* 04000027 */
		/* 0x00003DFC 02                 */ IL_002b: ldarg.0
		/* 0x00003DFD 7B27000004         */ IL_002c: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selectCommand /* 04000027 */
		/* 0x00003E02 2A                 */ IL_0031: ret
	} // end of method AssistantViewModel::get_SelectCommand

	.method /* 06000073 */ public final hidebysig specialname newslot virtual 
		instance class [PresentationCore]System.Windows.Input.ICommand get_RedoCommand () cil managed 
	{
		// Method begins at RVA 0x3e44
		// Header size: 12
		// Code size: 94 (0x5e)
		.maxstack 5
		.locals /* 1100001F */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute,
			[1] class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute
		)

		/* 0x00003E44 14                 */ IL_0000: ldnull
		/* 0x00003E45 0A                 */ IL_0001: stloc.0
		/* 0x00003E46 14                 */ IL_0002: ldnull
		/* 0x00003E47 0B                 */ IL_0003: stloc.1
		/* 0x00003E48 02                 */ IL_0004: ldarg.0
		/* 0x00003E49 7B28000004         */ IL_0005: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x00003E4E 2D4B               */ IL_000a: brtrue.s IL_0057
		/* 0x00003E50 02                 */ IL_000c: ldarg.0
		/* 0x00003E51 06                 */ IL_000d: ldloc.0
		/* 0x00003E52 2D0D               */ IL_000e: brtrue.s IL_001d
		/* 0x00003E54 02                 */ IL_0010: ldarg.0
		/* 0x00003E55 FE067E000006       */ IL_0011: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<get_RedoCommand>b__14'(object) /* 0600007E */
		/* 0x00003E5B 7310000006         */ IL_0017: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute::.ctor(object, native int) /* 06000010 */
		/* 0x00003E60 0A                 */ IL_001c: stloc.0
		/* 0x00003E61 06                 */ IL_001d: ldloc.0
		/* 0x00003E62 07                 */ IL_001e: ldloc.1
		/* 0x00003E63 2D0D               */ IL_001f: brtrue.s IL_002e
		/* 0x00003E65 02                 */ IL_0021: ldarg.0
		/* 0x00003E66 FE067F000006       */ IL_0022: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<get_RedoCommand>b__15'(object) /* 0600007F */
		/* 0x00003E6C 730C000006         */ IL_0028: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute::.ctor(object, native int) /* 0600000C */
		/* 0x00003E71 0B                 */ IL_002d: stloc.1
		/* 0x00003E72 07                 */ IL_002e: ldloc.1
		/* 0x00003E73 7317000006         */ IL_002f: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::.ctor(class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute, class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute) /* 06000017 */
		/* 0x00003E78 7D28000004         */ IL_0034: stfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x00003E7D 02                 */ IL_0039: ldarg.0
		/* 0x00003E7E 7B28000004         */ IL_003a: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x00003E83 02                 */ IL_003f: ldarg.0
		/* 0x00003E84 02                 */ IL_0040: ldarg.0
		/* 0x00003E85 02                 */ IL_0041: ldarg.0
		/* 0x00003E86 7B25000004         */ IL_0042: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003E8B 17                 */ IL_0047: ldc.i4.1
		/* 0x00003E8C 2869000006         */ IL_0048: call instance class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::DefaultOption(class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool) /* 06000069 */
		/* 0x00003E91 286A000006         */ IL_004d: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::OptionCaption(class AspenTech.Visualisation.Controls.Assistant.AssistOption) /* 0600006A */
		/* 0x00003E96 6F1E000006         */ IL_0052: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::set_ToolTip(string) /* 0600001E */
		/* 0x00003E9B 02                 */ IL_0057: ldarg.0
		/* 0x00003E9C 7B28000004         */ IL_0058: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_redoCommand /* 04000028 */
		/* 0x00003EA1 2A                 */ IL_005d: ret
	} // end of method AssistantViewModel::get_RedoCommand

	.method /* 06000074 */ public final hidebysig specialname newslot virtual 
		instance class [PresentationCore]System.Windows.Input.ICommand get_UndoCommand () cil managed 
	{
		// Method begins at RVA 0x3f08
		// Header size: 12
		// Code size: 121 (0x79)
		.maxstack 5
		.locals /* 1100001F */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute,
			[1] class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute
		)

		/* 0x00003F08 14                 */ IL_0000: ldnull
		/* 0x00003F09 0A                 */ IL_0001: stloc.0
		/* 0x00003F0A 14                 */ IL_0002: ldnull
		/* 0x00003F0B 0B                 */ IL_0003: stloc.1
		/* 0x00003F0C 02                 */ IL_0004: ldarg.0
		/* 0x00003F0D 7B29000004         */ IL_0005: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x00003F12 2D66               */ IL_000a: brtrue.s IL_0072
		/* 0x00003F14 02                 */ IL_000c: ldarg.0
		/* 0x00003F15 06                 */ IL_000d: ldloc.0
		/* 0x00003F16 2D0D               */ IL_000e: brtrue.s IL_001d
		/* 0x00003F18 02                 */ IL_0010: ldarg.0
		/* 0x00003F19 FE0680000006       */ IL_0011: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<get_UndoCommand>b__18'(object) /* 06000080 */
		/* 0x00003F1F 7310000006         */ IL_0017: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute::.ctor(object, native int) /* 06000010 */
		/* 0x00003F24 0A                 */ IL_001c: stloc.0
		/* 0x00003F25 06                 */ IL_001d: ldloc.0
		/* 0x00003F26 07                 */ IL_001e: ldloc.1
		/* 0x00003F27 2D0D               */ IL_001f: brtrue.s IL_002e
		/* 0x00003F29 02                 */ IL_0021: ldarg.0
		/* 0x00003F2A FE0681000006       */ IL_0022: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::'<get_UndoCommand>b__19'(object) /* 06000081 */
		/* 0x00003F30 730C000006         */ IL_0028: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute::.ctor(object, native int) /* 0600000C */
		/* 0x00003F35 0B                 */ IL_002d: stloc.1
		/* 0x00003F36 07                 */ IL_002e: ldloc.1
		/* 0x00003F37 7317000006         */ IL_002f: newobj instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::.ctor(class AspenTech.Visualisation.Controls.Assistant.GenericCommandCanExecute, class AspenTech.Visualisation.Controls.Assistant.GenericCommandExecute) /* 06000017 */
		/* 0x00003F3C 7D29000004         */ IL_0034: stfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x00003F41 02                 */ IL_0039: ldarg.0
		/* 0x00003F42 7B29000004         */ IL_003a: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x00003F47 02                 */ IL_003f: ldarg.0
		/* 0x00003F48 7B2A000004         */ IL_0040: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003F4D 6FB800000A         */ IL_0045: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x00003F52 17                 */ IL_004a: ldc.i4.1
		/* 0x00003F53 3003               */ IL_004b: bgt.s IL_0050
		/* 0x00003F55 14                 */ IL_004d: ldnull
		/* 0x00003F56 2B1D               */ IL_004e: br.s IL_006d
		/* 0x00003F58 02                 */ IL_0050: ldarg.0
		/* 0x00003F59 7B2A000004         */ IL_0051: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003F5E 02                 */ IL_0056: ldarg.0
		/* 0x00003F5F 7B2A000004         */ IL_0057: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003F64 6FB800000A         */ IL_005c: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x00003F69 18                 */ IL_0061: ldc.i4.2
		/* 0x00003F6A 59                 */ IL_0062: sub
		/* 0x00003F6B 6FB600000A         */ IL_0063: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Item(int32) /* 0A0000B6 */
		/* 0x00003F70 6F2F000006         */ IL_0068: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00003F75 6F1E000006         */ IL_006d: callvirt instance void AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler::set_ToolTip(string) /* 0600001E */
		/* 0x00003F7A 02                 */ IL_0072: ldarg.0
		/* 0x00003F7B 7B29000004         */ IL_0073: ldfld class AspenTech.Visualisation.Controls.Assistant.GenericCommandHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_undoCommand /* 04000029 */
		/* 0x00003F80 2A                 */ IL_0078: ret
	} // end of method AssistantViewModel::get_UndoCommand

	.method /* 06000075 */ private hidebysig 
		instance string Comma (
			string& text
		) cil managed 
	{
		// Method begins at RVA 0x3f90
		// Header size: 12
		// Code size: 100 (0x64)
		.maxstack 4
		.locals /* 11000020 */ init (
			[0] int32,
			[1] string
		)

		/* 0x00003F90 03                 */ IL_0000: ldarg.1
		/* 0x00003F91 50                 */ IL_0001: ldind.ref
		/* 0x00003F92 2D02               */ IL_0002: brtrue.s IL_0006
		/* 0x00003F94 14                 */ IL_0004: ldnull
		/* 0x00003F95 2A                 */ IL_0005: ret
		/* 0x00003F96 03                 */ IL_0006: ldarg.1
		/* 0x00003F97 50                 */ IL_0007: ldind.ref
		/* 0x00003F98 72D8050070         */ IL_0008: ldstr "\"" /* 700005D8 */
		/* 0x00003F9D 6FB200000A         */ IL_000d: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x00003FA2 2C46               */ IL_0012: brfalse.s IL_005a
		/* 0x00003FA4 03                 */ IL_0014: ldarg.1
		/* 0x00003FA5 50                 */ IL_0015: ldind.ref
		/* 0x00003FA6 72D8050070         */ IL_0016: ldstr "\"" /* 700005D8 */
		/* 0x00003FAB 17                 */ IL_001b: ldc.i4.1
		/* 0x00003FAC 6FC700000A         */ IL_001c: callvirt instance int32 [mscorlib]System.String::IndexOf(string, int32) /* 0A0000C7 */
		/* 0x00003FB1 0A                 */ IL_0021: stloc.0
		/* 0x00003FB2 06                 */ IL_0022: ldloc.0
		/* 0x00003FB3 16                 */ IL_0023: ldc.i4.0
		/* 0x00003FB4 3134               */ IL_0024: ble.s IL_005a
		/* 0x00003FB6 06                 */ IL_0026: ldloc.0
		/* 0x00003FB7 03                 */ IL_0027: ldarg.1
		/* 0x00003FB8 50                 */ IL_0028: ldind.ref
		/* 0x00003FB9 6F3100000A         */ IL_0029: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00003FBE 17                 */ IL_002e: ldc.i4.1
		/* 0x00003FBF 59                 */ IL_002f: sub
		/* 0x00003FC0 2E0E               */ IL_0030: beq.s IL_0040
		/* 0x00003FC2 03                 */ IL_0032: ldarg.1
		/* 0x00003FC3 50                 */ IL_0033: ldind.ref
		/* 0x00003FC4 06                 */ IL_0034: ldloc.0
		/* 0x00003FC5 17                 */ IL_0035: ldc.i4.1
		/* 0x00003FC6 58                 */ IL_0036: add
		/* 0x00003FC7 6F2900000A         */ IL_0037: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00003FCC 1F2C               */ IL_003c: ldc.i4.s 44
		/* 0x00003FCE 331A               */ IL_003e: bne.un.s IL_005a
		/* 0x00003FD0 03                 */ IL_0040: ldarg.1
		/* 0x00003FD1 50                 */ IL_0041: ldind.ref
		/* 0x00003FD2 17                 */ IL_0042: ldc.i4.1
		/* 0x00003FD3 06                 */ IL_0043: ldloc.0
		/* 0x00003FD4 17                 */ IL_0044: ldc.i4.1
		/* 0x00003FD5 59                 */ IL_0045: sub
		/* 0x00003FD6 6F7400000A         */ IL_0046: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00003FDB 0B                 */ IL_004b: stloc.1
		/* 0x00003FDC 03                 */ IL_004c: ldarg.1
		/* 0x00003FDD 03                 */ IL_004d: ldarg.1
		/* 0x00003FDE 50                 */ IL_004e: ldind.ref
		/* 0x00003FDF 06                 */ IL_004f: ldloc.0
		/* 0x00003FE0 18                 */ IL_0050: ldc.i4.2
		/* 0x00003FE1 58                 */ IL_0051: add
		/* 0x00003FE2 6F7200000A         */ IL_0052: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x00003FE7 51                 */ IL_0057: stind.ref
		/* 0x00003FE8 07                 */ IL_0058: ldloc.1
		/* 0x00003FE9 2A                 */ IL_0059: ret
		/* 0x00003FEA 02                 */ IL_005a: ldarg.0
		/* 0x00003FEB 1F2C               */ IL_005b: ldc.i4.s 44
		/* 0x00003FED 03                 */ IL_005d: ldarg.1
		/* 0x00003FEE 2876000006         */ IL_005e: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Token(char, string&) /* 06000076 */
		/* 0x00003FF3 2A                 */ IL_0063: ret
	} // end of method AssistantViewModel::Comma

	.method /* 06000076 */ private hidebysig 
		instance string Token (
			char delimiter,
			string& text
		) cil managed 
	{
		// Method begins at RVA 0x4000
		// Header size: 12
		// Code size: 51 (0x33)
		.maxstack 4
		.locals /* 11000021 */ init (
			[0] int32,
			[1] string,
			[2] string
		)

		/* 0x00004000 04                 */ IL_0000: ldarg.2
		/* 0x00004001 50                 */ IL_0001: ldind.ref
		/* 0x00004002 2D02               */ IL_0002: brtrue.s IL_0006
		/* 0x00004004 14                 */ IL_0004: ldnull
		/* 0x00004005 2A                 */ IL_0005: ret
		/* 0x00004006 04                 */ IL_0006: ldarg.2
		/* 0x00004007 50                 */ IL_0007: ldind.ref
		/* 0x00004008 03                 */ IL_0008: ldarg.1
		/* 0x00004009 6F7100000A         */ IL_0009: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x0000400E 0A                 */ IL_000e: stloc.0
		/* 0x0000400F 06                 */ IL_000f: ldloc.0
		/* 0x00004010 16                 */ IL_0010: ldc.i4.0
		/* 0x00004011 2F08               */ IL_0011: bge.s IL_001b
		/* 0x00004013 04                 */ IL_0013: ldarg.2
		/* 0x00004014 50                 */ IL_0014: ldind.ref
		/* 0x00004015 0B                 */ IL_0015: stloc.1
		/* 0x00004016 04                 */ IL_0016: ldarg.2
		/* 0x00004017 14                 */ IL_0017: ldnull
		/* 0x00004018 51                 */ IL_0018: stind.ref
		/* 0x00004019 07                 */ IL_0019: ldloc.1
		/* 0x0000401A 2A                 */ IL_001a: ret
		/* 0x0000401B 04                 */ IL_001b: ldarg.2
		/* 0x0000401C 50                 */ IL_001c: ldind.ref
		/* 0x0000401D 16                 */ IL_001d: ldc.i4.0
		/* 0x0000401E 06                 */ IL_001e: ldloc.0
		/* 0x0000401F 6F7400000A         */ IL_001f: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00004024 0C                 */ IL_0024: stloc.2
		/* 0x00004025 04                 */ IL_0025: ldarg.2
		/* 0x00004026 04                 */ IL_0026: ldarg.2
		/* 0x00004027 50                 */ IL_0027: ldind.ref
		/* 0x00004028 06                 */ IL_0028: ldloc.0
		/* 0x00004029 17                 */ IL_0029: ldc.i4.1
		/* 0x0000402A 58                 */ IL_002a: add
		/* 0x0000402B 6F7200000A         */ IL_002b: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x00004030 51                 */ IL_0030: stind.ref
		/* 0x00004031 08                 */ IL_0031: ldloc.2
		/* 0x00004032 2A                 */ IL_0032: ret
	} // end of method AssistantViewModel::Token

	.method /* 06000077 */ private hidebysig 
		instance void Execute (
			class AspenTech.Visualisation.Controls.Assistant.AssistOption option
		) cil managed 
	{
		// Method begins at RVA 0x4040
		// Header size: 12
		// Code size: 745 (0x2e9)
		.maxstack 6
		.locals /* 11000022 */ init (
			[0] string,
			[1] string,
			[2] string,
			[3] class AspenTech.Visualisation.Controls.Assistant.ProManLink,
			[4] int32,
			[5] string,
			[6] string,
			[7] string,
			[8] class AspenTech.Visualisation.Controls.Assistant.AssistRoot,
			[9] class AspenTech.Visualisation.Controls.Assistant.AssistantDialog,
			[10] string,
			[11] string,
			[12] string,
			[13] string,
			[14] string,
			[15] class [mscorlib]System.Exception,
			[16] valuetype AspenTech.Visualisation.Controls.Assistant.Action,
			[17] string[]
		)

		/* 0x00004040 03                 */ IL_0000: ldarg.1
		/* 0x00004041 6F89000006         */ IL_0001: callvirt instance valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Action() /* 06000089 */
		/* 0x00004046 1310               */ IL_0006: stloc.s 16
		/* 0x00004048 1110               */ IL_0008: ldloc.s 16
		/* 0x0000404A 17                 */ IL_000a: ldc.i4.1
		/* 0x0000404B 59                 */ IL_000b: sub
		/* 0x0000404C 4508000000         */ IL_000c: switch (
		/*              05000000         */                  IL_0036,
		/*              05000000         */                  IL_0036,
		/*              B4000000         */                  IL_00e5,
		/*              56010000         */                  IL_0187,
		/*              16000000         */                  IL_0047,
		/*              56010000         */                  IL_0187,
		/*              9A020000         */                  IL_02cb,
		/*              67010000         */                  IL_0198)
		/* 0x00004071 3895020000         */ IL_0031: br IL_02cb
		/* 0x00004076 02                 */ IL_0036: ldarg.0
		/* 0x00004077 03                 */ IL_0037: ldarg.1
		/* 0x00004078 6F8B000006         */ IL_0038: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x0000407D 2868000006         */ IL_003d: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::set_ScreenId(string) /* 06000068 */
		/* 0x00004082 3884020000         */ IL_0042: br IL_02cb
		/* 0x00004087 03                 */ IL_0047: ldarg.1
		/* 0x00004088 6F8B000006         */ IL_0048: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x0000408D 0A                 */ IL_004d: stloc.0
		/* 0x0000408E 06                 */ IL_004e: ldloc.0
		/* 0x0000408F 72DC050070         */ IL_004f: ldstr "SHOW(" /* 700005DC */
		/* 0x00004094 1B                 */ IL_0054: ldc.i4.5
		/* 0x00004095 6F7000000A         */ IL_0055: callvirt instance bool [mscorlib]System.String::StartsWith(string, valuetype [mscorlib]System.StringComparison) /* 0A000070 */
		/* 0x0000409A 2C26               */ IL_005a: brfalse.s IL_0082
		/* 0x0000409C 06                 */ IL_005c: ldloc.0
		/* 0x0000409D 16                 */ IL_005d: ldc.i4.0
		/* 0x0000409E 1B                 */ IL_005e: ldc.i4.5
		/* 0x0000409F 6FB100000A         */ IL_005f: callvirt instance string [mscorlib]System.String::Remove(int32, int32) /* 0A0000B1 */
		/* 0x000040A4 0A                 */ IL_0064: stloc.0
		/* 0x000040A5 06                 */ IL_0065: ldloc.0
		/* 0x000040A6 72E8050070         */ IL_0066: ldstr ")" /* 700005E8 */
		/* 0x000040AB 6FC800000A         */ IL_006b: callvirt instance bool [mscorlib]System.String::EndsWith(string) /* 0A0000C8 */
		/* 0x000040B0 2C10               */ IL_0070: brfalse.s IL_0082
		/* 0x000040B2 06                 */ IL_0072: ldloc.0
		/* 0x000040B3 16                 */ IL_0073: ldc.i4.0
		/* 0x000040B4 06                 */ IL_0074: ldloc.0
		/* 0x000040B5 6F3100000A         */ IL_0075: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x000040BA 18                 */ IL_007a: ldc.i4.2
		/* 0x000040BB 59                 */ IL_007b: sub
		/* 0x000040BC 6F7400000A         */ IL_007c: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x000040C1 0A                 */ IL_0081: stloc.0
		/* 0x000040C2 02                 */ IL_0082: ldarg.0
		/* 0x000040C3 1200               */ IL_0083: ldloca.s 0
		/* 0x000040C5 2875000006         */ IL_0085: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Comma(string&) /* 06000075 */
		/* 0x000040CA 0B                 */ IL_008a: stloc.1
		/* 0x000040CB 06                 */ IL_008b: ldloc.0
		/* 0x000040CC 282C00000A         */ IL_008c: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000040D1 2C08               */ IL_0091: brfalse.s IL_009b
		/* 0x000040D3 07                 */ IL_0093: ldloc.1
		/* 0x000040D4 0A                 */ IL_0094: stloc.0
		/* 0x000040D5 72EC050070         */ IL_0095: ldstr "Text" /* 700005EC */
		/* 0x000040DA 0B                 */ IL_009a: stloc.1
		/* 0x000040DB 02                 */ IL_009b: ldarg.0
		/* 0x000040DC 1200               */ IL_009c: ldloca.s 0
		/* 0x000040DE 2875000006         */ IL_009e: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Comma(string&) /* 06000075 */
		/* 0x000040E3 0C                 */ IL_00a3: stloc.2
		/* 0x000040E4 73AF000006         */ IL_00a4: newobj instance void AspenTech.Visualisation.Controls.Assistant.ProManLink::.ctor() /* 060000AF */
		/* 0x000040E9 0D                 */ IL_00a9: stloc.3
		/* 0x000040EA 09                 */ IL_00aa: ldloc.3
		/* 0x000040EB 72F6050070         */ IL_00ab: ldstr "Assist: " /* 700005F6 */
		/* 0x000040F0 03                 */ IL_00b0: ldarg.1
		/* 0x000040F1 6F33000006         */ IL_00b1: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x000040F6 6F28000006         */ IL_00b6: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000040FB 283500000A         */ IL_00bb: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x00004100 03                 */ IL_00c0: ldarg.1
		/* 0x00004101 6F33000006         */ IL_00c1: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x00004106 6F45000006         */ IL_00c6: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Version() /* 06000045 */
		/* 0x0000410B 09                 */ IL_00cb: ldloc.3
		/* 0x0000410C 07                 */ IL_00cc: ldloc.1
		/* 0x0000410D 6FA9000006         */ IL_00cd: callvirt instance valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction AspenTech.Visualisation.Controls.Assistant.ProManLink::StringToAction(string) /* 060000A9 */
		/* 0x00004112 02                 */ IL_00d2: ldarg.0
		/* 0x00004113 1202               */ IL_00d3: ldloca.s 2
		/* 0x00004115 2875000006         */ IL_00d5: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Comma(string&) /* 06000075 */
		/* 0x0000411A 06                 */ IL_00da: ldloc.0
		/* 0x0000411B 6FA4000006         */ IL_00db: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManLink::Action(string, string, valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction, string, string) /* 060000A4 */
		/* 0x00004120 38E6010000         */ IL_00e0: br IL_02cb
		/* 0x00004125 03                 */ IL_00e5: ldarg.1
		/* 0x00004126 6F8B000006         */ IL_00e6: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x0000412B 1F2C               */ IL_00eb: ldc.i4.s 44
		/* 0x0000412D 6F7100000A         */ IL_00ed: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x00004132 1304               */ IL_00f2: stloc.s 4
		/* 0x00004134 1104               */ IL_00f4: ldloc.s 4
		/* 0x00004136 16                 */ IL_00f6: ldc.i4.0
		/* 0x00004137 3123               */ IL_00f7: ble.s IL_011c
		/* 0x00004139 03                 */ IL_00f9: ldarg.1
		/* 0x0000413A 6F8B000006         */ IL_00fa: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x0000413F 1104               */ IL_00ff: ldloc.s 4
		/* 0x00004141 17                 */ IL_0101: ldc.i4.1
		/* 0x00004142 58                 */ IL_0102: add
		/* 0x00004143 6F7200000A         */ IL_0103: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x00004148 1305               */ IL_0108: stloc.s 5
		/* 0x0000414A 03                 */ IL_010a: ldarg.1
		/* 0x0000414B 6F8B000006         */ IL_010b: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x00004150 16                 */ IL_0110: ldc.i4.0
		/* 0x00004151 1104               */ IL_0111: ldloc.s 4
		/* 0x00004153 6F7400000A         */ IL_0113: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00004158 1306               */ IL_0118: stloc.s 6
		/* 0x0000415A 2B0B               */ IL_011a: br.s IL_0127
		/* 0x0000415C 14                 */ IL_011c: ldnull
		/* 0x0000415D 1305               */ IL_011d: stloc.s 5
		/* 0x0000415F 03                 */ IL_011f: ldarg.1
		/* 0x00004160 6F8B000006         */ IL_0120: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x00004165 1306               */ IL_0125: stloc.s 6
		/* 0x00004167 1106               */ IL_0127: ldloc.s 6
		/* 0x00004169 03                 */ IL_0129: ldarg.1
		/* 0x0000416A 6F33000006         */ IL_012a: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x0000416F 6F3B000006         */ IL_012f: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00004174 2878000006         */ IL_0134: call string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::FindFile(string, string) /* 06000078 */
		/* 0x00004179 1307               */ IL_0139: stloc.s 7
		/* 0x0000417B 1107               */ IL_013b: ldloc.s 7
		/* 0x0000417D 3989010000         */ IL_013d: brfalse IL_02cb
		/* 0x00004182 03                 */ IL_0142: ldarg.1
		/* 0x00004183 6F33000006         */ IL_0143: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x00004188 6F49000006         */ IL_0148: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_CurrentUserId() /* 06000049 */
		/* 0x0000418D 7352000006         */ IL_014d: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::.ctor(string) /* 06000052 */
		/* 0x00004192 1308               */ IL_0152: stloc.s 8
		/* 0x00004194 1108               */ IL_0154: ldloc.s 8
		/* 0x00004196 1107               */ IL_0156: ldloc.s 7
		/* 0x00004198 6F56000006         */ IL_0158: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::LoadFile(string) /* 06000056 */
		/* 0x0000419D 73C1000006         */ IL_015d: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::.ctor() /* 060000C1 */
		/* 0x000041A2 1309               */ IL_0162: stloc.s 9
		/* 0x000041A4 1109               */ IL_0164: ldloc.s 9
		/* 0x000041A6 1108               */ IL_0166: ldloc.s 8
		/* 0x000041A8 6FC3000006         */ IL_0168: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::set_Assistant(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 060000C3 */
		/* 0x000041AD 1105               */ IL_016d: ldloc.s 5
		/* 0x000041AF 2C09               */ IL_016f: brfalse.s IL_017a
		/* 0x000041B1 1108               */ IL_0171: ldloc.s 8
		/* 0x000041B3 1105               */ IL_0173: ldloc.s 5
		/* 0x000041B5 6F4A000006         */ IL_0175: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistRoot::set_CurrentUserId(string) /* 0600004A */
		/* 0x000041BA 1109               */ IL_017a: ldloc.s 9
		/* 0x000041BC 6FC900000A         */ IL_017c: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]System.Windows.Window::ShowDialog() /* 0A0000C9 */
		/* 0x000041C1 26                 */ IL_0181: pop
		/* 0x000041C2 3844010000         */ IL_0182: br IL_02cb
		/* 0x000041C7 03                 */ IL_0187: ldarg.1
		/* 0x000041C8 6F8B000006         */ IL_0188: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x000041CD 28CA00000A         */ IL_018d: call class [System]System.Diagnostics.Process [System]System.Diagnostics.Process::Start(string) /* 0A0000CA */
		/* 0x000041D2 26                 */ IL_0192: pop
		/* 0x000041D3 3833010000         */ IL_0193: br IL_02cb
		/* 0x000041D8 03                 */ IL_0198: ldarg.1
		/* 0x000041D9 6F8B000006         */ IL_0199: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x000041DE 130A               */ IL_019e: stloc.s 10
		/* 0x000041E0 14                 */ IL_01a0: ldnull
		/* 0x000041E1 130B               */ IL_01a1: stloc.s 11
		/* 0x000041E3 7E2800000A         */ IL_01a3: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x000041E8 130E               */ IL_01a8: stloc.s 14
		/* 0x000041EA 3801010000         */ IL_01aa: br IL_02b0
		/* 0x000041EF 110A               */ IL_01af: ldloc.s 10
		/* 0x000041F1 16                 */ IL_01b1: ldc.i4.0
		/* 0x000041F2 6F2900000A         */ IL_01b2: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x000041F7 1F27               */ IL_01b7: ldc.i4.s 39
		/* 0x000041F9 331F               */ IL_01b9: bne.un.s IL_01da
		/* 0x000041FB 110A               */ IL_01bb: ldloc.s 10
		/* 0x000041FD 17                 */ IL_01bd: ldc.i4.1
		/* 0x000041FE 6F7200000A         */ IL_01be: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x00004203 130A               */ IL_01c3: stloc.s 10
		/* 0x00004205 02                 */ IL_01c5: ldarg.0
		/* 0x00004206 1F27               */ IL_01c6: ldc.i4.s 39
		/* 0x00004208 120A               */ IL_01c8: ldloca.s 10
		/* 0x0000420A 2876000006         */ IL_01ca: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Token(char, string&) /* 06000076 */
		/* 0x0000420F 130C               */ IL_01cf: stloc.s 12
		/* 0x00004211 7208060070         */ IL_01d1: ldstr "'" /* 70000608 */
		/* 0x00004216 130D               */ IL_01d6: stloc.s 13
		/* 0x00004218 2B3E               */ IL_01d8: br.s IL_0218
		/* 0x0000421A 110A               */ IL_01da: ldloc.s 10
		/* 0x0000421C 16                 */ IL_01dc: ldc.i4.0
		/* 0x0000421D 6F2900000A         */ IL_01dd: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00004222 1F22               */ IL_01e2: ldc.i4.s 34
		/* 0x00004224 331F               */ IL_01e4: bne.un.s IL_0205
		/* 0x00004226 110A               */ IL_01e6: ldloc.s 10
		/* 0x00004228 17                 */ IL_01e8: ldc.i4.1
		/* 0x00004229 6F7200000A         */ IL_01e9: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x0000422E 130A               */ IL_01ee: stloc.s 10
		/* 0x00004230 02                 */ IL_01f0: ldarg.0
		/* 0x00004231 1F22               */ IL_01f1: ldc.i4.s 34
		/* 0x00004233 120A               */ IL_01f3: ldloca.s 10
		/* 0x00004235 2876000006         */ IL_01f5: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Token(char, string&) /* 06000076 */
		/* 0x0000423A 130C               */ IL_01fa: stloc.s 12
		/* 0x0000423C 72D8050070         */ IL_01fc: ldstr "\"" /* 700005D8 */
		/* 0x00004241 130D               */ IL_0201: stloc.s 13
		/* 0x00004243 2B13               */ IL_0203: br.s IL_0218
		/* 0x00004245 02                 */ IL_0205: ldarg.0
		/* 0x00004246 1F20               */ IL_0206: ldc.i4.s 32
		/* 0x00004248 120A               */ IL_0208: ldloca.s 10
		/* 0x0000424A 2876000006         */ IL_020a: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Token(char, string&) /* 06000076 */
		/* 0x0000424F 130C               */ IL_020f: stloc.s 12
		/* 0x00004251 7E2800000A         */ IL_0211: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00004256 130D               */ IL_0216: stloc.s 13
		/* 0x00004258 110B               */ IL_0218: ldloc.s 11
		/* 0x0000425A 2D25               */ IL_021a: brtrue.s IL_0241
		/* 0x0000425C 110C               */ IL_021c: ldloc.s 12
		/* 0x0000425E 285900000A         */ IL_021e: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x00004263 2D16               */ IL_0223: brtrue.s IL_023b
		/* 0x00004265 110C               */ IL_0225: ldloc.s 12
		/* 0x00004267 03                 */ IL_0227: ldarg.1
		/* 0x00004268 6F33000006         */ IL_0228: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x0000426D 6F3B000006         */ IL_022d: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x00004272 2878000006         */ IL_0232: call string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::FindFile(string, string) /* 06000078 */
		/* 0x00004277 130B               */ IL_0237: stloc.s 11
		/* 0x00004279 2B75               */ IL_0239: br.s IL_02b0
		/* 0x0000427B 110C               */ IL_023b: ldloc.s 12
		/* 0x0000427D 130B               */ IL_023d: stloc.s 11
		/* 0x0000427F 2B6F               */ IL_023f: br.s IL_02b0
		/* 0x00004281 110C               */ IL_0241: ldloc.s 12
		/* 0x00004283 720C060070         */ IL_0243: ldstr "{$" /* 7000060C */
		/* 0x00004288 6FB200000A         */ IL_0248: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x0000428D 2C2F               */ IL_024d: brfalse.s IL_027e
		/* 0x0000428F 110C               */ IL_024f: ldloc.s 12
		/* 0x00004291 03                 */ IL_0251: ldarg.1
		/* 0x00004292 6F33000006         */ IL_0252: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x00004297 6F3B000006         */ IL_0257: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Filename() /* 0600003B */
		/* 0x0000429C 2878000006         */ IL_025c: call string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::FindFile(string, string) /* 06000078 */
		/* 0x000042A1 130C               */ IL_0261: stloc.s 12
		/* 0x000042A3 110D               */ IL_0263: ldloc.s 13
		/* 0x000042A5 282C00000A         */ IL_0265: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000042AA 2C12               */ IL_026a: brfalse.s IL_027e
		/* 0x000042AC 110C               */ IL_026c: ldloc.s 12
		/* 0x000042AE 1F20               */ IL_026e: ldc.i4.s 32
		/* 0x000042B0 280700002B         */ IL_0270: call bool [System.Core]System.Linq.Enumerable::Contains<char>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, !!0) /* 2B000007 */
		/* 0x000042B5 2C07               */ IL_0275: brfalse.s IL_027e
		/* 0x000042B7 72D8050070         */ IL_0277: ldstr "\"" /* 700005D8 */
		/* 0x000042BC 130D               */ IL_027c: stloc.s 13
		/* 0x000042BE 1B                 */ IL_027e: ldc.i4.5
		/* 0x000042BF 8D45000001         */ IL_027f: newarr [mscorlib]System.String /* 01000045 */
		/* 0x000042C4 1311               */ IL_0284: stloc.s 17
		/* 0x000042C6 1111               */ IL_0286: ldloc.s 17
		/* 0x000042C8 16                 */ IL_0288: ldc.i4.0
		/* 0x000042C9 110E               */ IL_0289: ldloc.s 14
		/* 0x000042CB A2                 */ IL_028b: stelem.ref
		/* 0x000042CC 1111               */ IL_028c: ldloc.s 17
		/* 0x000042CE 17                 */ IL_028e: ldc.i4.1
		/* 0x000042CF 722F020070         */ IL_028f: ldstr " " /* 7000022F */
		/* 0x000042D4 A2                 */ IL_0294: stelem.ref
		/* 0x000042D5 1111               */ IL_0295: ldloc.s 17
		/* 0x000042D7 18                 */ IL_0297: ldc.i4.2
		/* 0x000042D8 110D               */ IL_0298: ldloc.s 13
		/* 0x000042DA A2                 */ IL_029a: stelem.ref
		/* 0x000042DB 1111               */ IL_029b: ldloc.s 17
		/* 0x000042DD 19                 */ IL_029d: ldc.i4.3
		/* 0x000042DE 110C               */ IL_029e: ldloc.s 12
		/* 0x000042E0 A2                 */ IL_02a0: stelem.ref
		/* 0x000042E1 1111               */ IL_02a1: ldloc.s 17
		/* 0x000042E3 1A                 */ IL_02a3: ldc.i4.4
		/* 0x000042E4 110D               */ IL_02a4: ldloc.s 13
		/* 0x000042E6 A2                 */ IL_02a6: stelem.ref
		/* 0x000042E7 1111               */ IL_02a7: ldloc.s 17
		/* 0x000042E9 286A00000A         */ IL_02a9: call string [mscorlib]System.String::Concat(string[]) /* 0A00006A */
		/* 0x000042EE 130E               */ IL_02ae: stloc.s 14
		/* 0x000042F0 110A               */ IL_02b0: ldloc.s 10
		/* 0x000042F2 282C00000A         */ IL_02b2: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000042F7 39F3FEFFFF         */ IL_02b7: brfalse IL_01af
		/* 0x000042FC 110B               */ IL_02bc: ldloc.s 11
		/* 0x000042FE 110E               */ IL_02be: ldloc.s 14
		/* 0x00004300 6F2700000A         */ IL_02c0: callvirt instance string [mscorlib]System.String::Trim() /* 0A000027 */
		/* 0x00004305 28CC00000A         */ IL_02c5: call class [System]System.Diagnostics.Process [System]System.Diagnostics.Process::Start(string, string) /* 0A0000CC */
		/* 0x0000430A 26                 */ IL_02ca: pop
		/* 0x0000430B DE1B               */ IL_02cb: leave.s IL_02e8
		/* 0x0000430D 130F               */ IL_02cd: stloc.s 15
		/* 0x0000430F 110F               */ IL_02cf: ldloc.s 15
		/* 0x00004311 6FCD00000A         */ IL_02d1: callvirt instance string [mscorlib]System.Exception::get_Message() /* 0A0000CD */
		/* 0x00004316 7212060070         */ IL_02d6: ldstr "\r\n\r\nSee log file for details." /* 70000612 */
		/* 0x0000431B 283500000A         */ IL_02db: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x00004320 28CE00000A         */ IL_02e0: call valuetype [PresentationFramework]System.Windows.MessageBoxResult [PresentationFramework]System.Windows.MessageBox::Show(string) /* 0A0000CE */
		/* 0x00004325 26                 */ IL_02e5: pop
		/* 0x00004326 DE00               */ IL_02e6: leave.s IL_02e8
		/* 0x00004328 2A                 */ IL_02e8: ret

		.try IL_0000-IL_02cd catch [mscorlib]System.Exception IL_02cd-IL_02e8
	} // end of method AssistantViewModel::Execute

	.method /* 06000078 */ private hidebysig static 
		string FindFile (
			string fileName,
			string baseFile
		) cil managed 
	{
		// Method begins at RVA 0x4354
		// Header size: 12
		// Code size: 302 (0x12e)
		.maxstack 4
		.locals /* 11000023 */ init (
			[0] int32,
			[1] string,
			[2] string,
			[3] string,
			[4] char[],
			[5] string[],
			[6] int32
		)

		/* 0x00004354 02                 */ IL_0000: ldarg.0
		/* 0x00004355 28CF00000A         */ IL_0001: call bool [mscorlib]System.IO.Path::IsPathRooted(string) /* 0A0000CF */
		/* 0x0000435A 2C0D               */ IL_0006: brfalse.s IL_0015
		/* 0x0000435C 02                 */ IL_0008: ldarg.0
		/* 0x0000435D 285900000A         */ IL_0009: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x00004362 3917010000         */ IL_000e: brfalse IL_012a
		/* 0x00004367 02                 */ IL_0013: ldarg.0
		/* 0x00004368 2A                 */ IL_0014: ret
		/* 0x00004369 02                 */ IL_0015: ldarg.0
		/* 0x0000436A 724E060070         */ IL_0016: ldstr "{" /* 7000064E */
		/* 0x0000436F 6FB200000A         */ IL_001b: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x00004374 2C2F               */ IL_0020: brfalse.s IL_0051
		/* 0x00004376 02                 */ IL_0022: ldarg.0
		/* 0x00004377 1F7D               */ IL_0023: ldc.i4.s 125
		/* 0x00004379 6F7100000A         */ IL_0025: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x0000437E 0A                 */ IL_002a: stloc.0
		/* 0x0000437F 06                 */ IL_002b: ldloc.0
		/* 0x00004380 16                 */ IL_002c: ldc.i4.0
		/* 0x00004381 3122               */ IL_002d: ble.s IL_0051
		/* 0x00004383 02                 */ IL_002f: ldarg.0
		/* 0x00004384 06                 */ IL_0030: ldloc.0
		/* 0x00004385 17                 */ IL_0031: ldc.i4.1
		/* 0x00004386 58                 */ IL_0032: add
		/* 0x00004387 6F7200000A         */ IL_0033: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x0000438C 1000               */ IL_0038: starg.s fileName
		/* 0x0000438E 02                 */ IL_003a: ldarg.0
		/* 0x0000438F 72C5010070         */ IL_003b: ldstr "\\" /* 700001C5 */
		/* 0x00004394 6FB200000A         */ IL_0040: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x00004399 2C0A               */ IL_0045: brfalse.s IL_0051
		/* 0x0000439B 02                 */ IL_0047: ldarg.0
		/* 0x0000439C 16                 */ IL_0048: ldc.i4.0
		/* 0x0000439D 17                 */ IL_0049: ldc.i4.1
		/* 0x0000439E 6FB100000A         */ IL_004a: callvirt instance string [mscorlib]System.String::Remove(int32, int32) /* 0A0000B1 */
		/* 0x000043A3 1000               */ IL_004f: starg.s fileName
		/* 0x000043A5 03                 */ IL_0051: ldarg.1
		/* 0x000043A6 282C00000A         */ IL_0052: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000043AB 2D17               */ IL_0057: brtrue.s IL_0070
		/* 0x000043AD 03                 */ IL_0059: ldarg.1
		/* 0x000043AE 285700000A         */ IL_005a: call string [mscorlib]System.IO.Path::GetDirectoryName(string) /* 0A000057 */
		/* 0x000043B3 02                 */ IL_005f: ldarg.0
		/* 0x000043B4 285800000A         */ IL_0060: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x000043B9 0B                 */ IL_0065: stloc.1
		/* 0x000043BA 07                 */ IL_0066: ldloc.1
		/* 0x000043BB 285900000A         */ IL_0067: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x000043C0 2C02               */ IL_006c: brfalse.s IL_0070
		/* 0x000043C2 07                 */ IL_006e: ldloc.1
		/* 0x000043C3 2A                 */ IL_006f: ret
		/* 0x000043C4 28D000000A         */ IL_0070: call class [mscorlib]System.AppDomain [mscorlib]System.AppDomain::get_CurrentDomain() /* 0A0000D0 */
		/* 0x000043C9 2C1B               */ IL_0075: brfalse.s IL_0092
		/* 0x000043CB 28D000000A         */ IL_0077: call class [mscorlib]System.AppDomain [mscorlib]System.AppDomain::get_CurrentDomain() /* 0A0000D0 */
		/* 0x000043D0 6FD100000A         */ IL_007c: callvirt instance string [mscorlib]System.AppDomain::get_BaseDirectory() /* 0A0000D1 */
		/* 0x000043D5 02                 */ IL_0081: ldarg.0
		/* 0x000043D6 285800000A         */ IL_0082: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x000043DB 0B                 */ IL_0087: stloc.1
		/* 0x000043DC 07                 */ IL_0088: ldloc.1
		/* 0x000043DD 285900000A         */ IL_0089: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x000043E2 2C02               */ IL_008e: brfalse.s IL_0092
		/* 0x000043E4 07                 */ IL_0090: ldloc.1
		/* 0x000043E5 2A                 */ IL_0091: ret
		/* 0x000043E6 281900000A         */ IL_0092: call class [mscorlib]System.Reflection.Assembly [mscorlib]System.Reflection.Assembly::GetExecutingAssembly() /* 0A000019 */
		/* 0x000043EB 6F1F00000A         */ IL_0097: callvirt instance string [mscorlib]System.Reflection.Assembly::get_Location() /* 0A00001F */
		/* 0x000043F0 285700000A         */ IL_009c: call string [mscorlib]System.IO.Path::GetDirectoryName(string) /* 0A000057 */
		/* 0x000043F5 02                 */ IL_00a1: ldarg.0
		/* 0x000043F6 285800000A         */ IL_00a2: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x000043FB 0B                 */ IL_00a7: stloc.1
		/* 0x000043FC 07                 */ IL_00a8: ldloc.1
		/* 0x000043FD 285900000A         */ IL_00a9: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x00004402 2C02               */ IL_00ae: brfalse.s IL_00b2
		/* 0x00004404 07                 */ IL_00b0: ldloc.1
		/* 0x00004405 2A                 */ IL_00b1: ret
		/* 0x00004406 281800000A         */ IL_00b2: call class [mscorlib]System.Reflection.Assembly [mscorlib]System.Reflection.Assembly::GetEntryAssembly() /* 0A000018 */
		/* 0x0000440B 6F1F00000A         */ IL_00b7: callvirt instance string [mscorlib]System.Reflection.Assembly::get_Location() /* 0A00001F */
		/* 0x00004410 285700000A         */ IL_00bc: call string [mscorlib]System.IO.Path::GetDirectoryName(string) /* 0A000057 */
		/* 0x00004415 02                 */ IL_00c1: ldarg.0
		/* 0x00004416 285800000A         */ IL_00c2: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x0000441B 0B                 */ IL_00c7: stloc.1
		/* 0x0000441C 07                 */ IL_00c8: ldloc.1
		/* 0x0000441D 285900000A         */ IL_00c9: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x00004422 2C02               */ IL_00ce: brfalse.s IL_00d2
		/* 0x00004424 07                 */ IL_00d0: ldloc.1
		/* 0x00004425 2A                 */ IL_00d1: ret
		/* 0x00004426 7252060070         */ IL_00d2: ldstr "Path" /* 70000652 */
		/* 0x0000442B 28D200000A         */ IL_00d7: call string [mscorlib]System.Environment::GetEnvironmentVariable(string) /* 0A0000D2 */
		/* 0x00004430 0B                 */ IL_00dc: stloc.1
		/* 0x00004431 07                 */ IL_00dd: ldloc.1
		/* 0x00004432 282C00000A         */ IL_00de: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00004437 2D45               */ IL_00e3: brtrue.s IL_012a
		/* 0x00004439 07                 */ IL_00e5: ldloc.1
		/* 0x0000443A 17                 */ IL_00e6: ldc.i4.1
		/* 0x0000443B 8D46000001         */ IL_00e7: newarr [mscorlib]System.Char /* 01000046 */
		/* 0x00004440 1304               */ IL_00ec: stloc.s 4
		/* 0x00004442 1104               */ IL_00ee: ldloc.s 4
		/* 0x00004444 16                 */ IL_00f0: ldc.i4.0
		/* 0x00004445 1F3B               */ IL_00f1: ldc.i4.s 59
		/* 0x00004447 9D                 */ IL_00f3: stelem.i2
		/* 0x00004448 1104               */ IL_00f4: ldloc.s 4
		/* 0x0000444A 6F3A00000A         */ IL_00f6: callvirt instance string[] [mscorlib]System.String::Split(char[]) /* 0A00003A */
		/* 0x0000444F 1305               */ IL_00fb: stloc.s 5
		/* 0x00004451 16                 */ IL_00fd: ldc.i4.0
		/* 0x00004452 1306               */ IL_00fe: stloc.s 6
		/* 0x00004454 2B20               */ IL_0100: br.s IL_0122
		/* 0x00004456 1105               */ IL_0102: ldloc.s 5
		/* 0x00004458 1106               */ IL_0104: ldloc.s 6
		/* 0x0000445A 9A                 */ IL_0106: ldelem.ref
		/* 0x0000445B 0C                 */ IL_0107: stloc.2
		/* 0x0000445C 08                 */ IL_0108: ldloc.2
		/* 0x0000445D 02                 */ IL_0109: ldarg.0
		/* 0x0000445E 285800000A         */ IL_010a: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x00004463 0B                 */ IL_010f: stloc.1
		/* 0x00004464 07                 */ IL_0110: ldloc.1
		/* 0x00004465 285900000A         */ IL_0111: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x0000446A 2C04               */ IL_0116: brfalse.s IL_011c
		/* 0x0000446C 07                 */ IL_0118: ldloc.1
		/* 0x0000446D 0D                 */ IL_0119: stloc.3
		/* 0x0000446E DE10               */ IL_011a: leave.s IL_012c
		/* 0x00004470 1106               */ IL_011c: ldloc.s 6
		/* 0x00004472 17                 */ IL_011e: ldc.i4.1
		/* 0x00004473 58                 */ IL_011f: add
		/* 0x00004474 1306               */ IL_0120: stloc.s 6
		/* 0x00004476 1106               */ IL_0122: ldloc.s 6
		/* 0x00004478 1105               */ IL_0124: ldloc.s 5
		/* 0x0000447A 8E                 */ IL_0126: ldlen
		/* 0x0000447B 69                 */ IL_0127: conv.i4
		/* 0x0000447C 32D8               */ IL_0128: blt.s IL_0102
		/* 0x0000447E 14                 */ IL_012a: ldnull
		/* 0x0000447F 2A                 */ IL_012b: ret
		/* 0x00004480 09                 */ IL_012c: ldloc.3
		/* 0x00004481 2A                 */ IL_012d: ret
	} // end of method AssistantViewModel::FindFile

	.method /* 06000079 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x4490
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00004490 02                 */ IL_0000: ldarg.0
		/* 0x00004491 7B2B000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::PropertyChanged /* 0400002B */
		/* 0x00004496 0A                 */ IL_0006: stloc.0
		/* 0x00004497 06                 */ IL_0007: ldloc.0
		/* 0x00004498 0B                 */ IL_0008: stloc.1
		/* 0x00004499 07                 */ IL_0009: ldloc.1
		/* 0x0000449A 03                 */ IL_000a: ldarg.1
		/* 0x0000449B 284E00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00004E */
		/* 0x000044A0 7412000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000012 */
		/* 0x000044A5 0C                 */ IL_0015: stloc.2
		/* 0x000044A6 02                 */ IL_0016: ldarg.0
		/* 0x000044A7 7C2B000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::PropertyChanged /* 0400002B */
		/* 0x000044AC 08                 */ IL_001c: ldloc.2
		/* 0x000044AD 07                 */ IL_001d: ldloc.1
		/* 0x000044AE 280400002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000004 */
		/* 0x000044B3 0A                 */ IL_0023: stloc.0
		/* 0x000044B4 06                 */ IL_0024: ldloc.0
		/* 0x000044B5 07                 */ IL_0025: ldloc.1
		/* 0x000044B6 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000044B8 2A                 */ IL_0028: ret
	} // end of method AssistantViewModel::add_PropertyChanged

	.method /* 0600007A */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x44c8
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000008 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000044C8 02                 */ IL_0000: ldarg.0
		/* 0x000044C9 7B2B000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::PropertyChanged /* 0400002B */
		/* 0x000044CE 0A                 */ IL_0006: stloc.0
		/* 0x000044CF 06                 */ IL_0007: ldloc.0
		/* 0x000044D0 0B                 */ IL_0008: stloc.1
		/* 0x000044D1 07                 */ IL_0009: ldloc.1
		/* 0x000044D2 03                 */ IL_000a: ldarg.1
		/* 0x000044D3 285000000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000050 */
		/* 0x000044D8 7412000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000012 */
		/* 0x000044DD 0C                 */ IL_0015: stloc.2
		/* 0x000044DE 02                 */ IL_0016: ldarg.0
		/* 0x000044DF 7C2B000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::PropertyChanged /* 0400002B */
		/* 0x000044E4 08                 */ IL_001c: ldloc.2
		/* 0x000044E5 07                 */ IL_001d: ldloc.1
		/* 0x000044E6 280400002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000004 */
		/* 0x000044EB 0A                 */ IL_0023: stloc.0
		/* 0x000044EC 06                 */ IL_0024: ldloc.0
		/* 0x000044ED 07                 */ IL_0025: ldloc.1
		/* 0x000044EE 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000044F0 2A                 */ IL_0028: ret
	} // end of method AssistantViewModel::remove_PropertyChanged

	.method /* 0600007B */ private hidebysig 
		instance void DoPropertyChanged (
			string 'property'
		) cil managed 
	{
		// Method begins at RVA 0x4500
		// Header size: 12
		// Code size: 24 (0x18)
		.maxstack 4
		.locals /* 11000007 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00004500 02                 */ IL_0000: ldarg.0
		/* 0x00004501 7B2B000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::PropertyChanged /* 0400002B */
		/* 0x00004506 0A                 */ IL_0006: stloc.0
		/* 0x00004507 06                 */ IL_0007: ldloc.0
		/* 0x00004508 2C0D               */ IL_0008: brfalse.s IL_0017
		/* 0x0000450A 06                 */ IL_000a: ldloc.0
		/* 0x0000450B 02                 */ IL_000b: ldarg.0
		/* 0x0000450C 03                 */ IL_000c: ldarg.1
		/* 0x0000450D 735400000A         */ IL_000d: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000054 */
		/* 0x00004512 6F5500000A         */ IL_0012: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000055 */
		/* 0x00004517 2A                 */ IL_0017: ret
	} // end of method AssistantViewModel::DoPropertyChanged

	.method /* 0600007C */ private hidebysig 
		instance bool '<get_SelectCommand>b__12' (
			object param
		) cil managed 
	{
		.custom /* 0C000076 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3d6c
		// Header size: 12
		// Code size: 24 (0x18)
		.maxstack 4
		.locals /* 1100001D */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[1] class AspenTech.Visualisation.Controls.Assistant.AssistOption
		)

		/* 0x00003D6C 02                 */ IL_0000: ldarg.0
		/* 0x00003D6D 03                 */ IL_0001: ldarg.1
		/* 0x00003D6E 7545000001         */ IL_0002: isinst [mscorlib]System.String /* 01000045 */
		/* 0x00003D73 1200               */ IL_0007: ldloca.s 0
		/* 0x00003D75 1201               */ IL_0009: ldloca.s 1
		/* 0x00003D77 2866000006         */ IL_000b: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Find(string, class AspenTech.Visualisation.Controls.Assistant.AssistScreen&, class AspenTech.Visualisation.Controls.Assistant.AssistOption&) /* 06000066 */
		/* 0x00003D7C 07                 */ IL_0010: ldloc.1
		/* 0x00003D7D 14                 */ IL_0011: ldnull
		/* 0x00003D7E FE01               */ IL_0012: ceq
		/* 0x00003D80 16                 */ IL_0014: ldc.i4.0
		/* 0x00003D81 FE01               */ IL_0015: ceq
		/* 0x00003D83 2A                 */ IL_0017: ret
	} // end of method AssistantViewModel::'<get_SelectCommand>b__12'

	.method /* 0600007D */ private hidebysig 
		instance void '<get_SelectCommand>b__13' (
			object param
		) cil managed 
	{
		.custom /* 0C000077 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3d90
		// Header size: 12
		// Code size: 53 (0x35)
		.maxstack 4
		.locals /* 1100001D */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[1] class AspenTech.Visualisation.Controls.Assistant.AssistOption
		)

		/* 0x00003D90 02                 */ IL_0000: ldarg.0
		/* 0x00003D91 03                 */ IL_0001: ldarg.1
		/* 0x00003D92 7545000001         */ IL_0002: isinst [mscorlib]System.String /* 01000045 */
		/* 0x00003D97 1200               */ IL_0007: ldloca.s 0
		/* 0x00003D99 1201               */ IL_0009: ldloca.s 1
		/* 0x00003D9B 2866000006         */ IL_000b: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Find(string, class AspenTech.Visualisation.Controls.Assistant.AssistScreen&, class AspenTech.Visualisation.Controls.Assistant.AssistOption&) /* 06000066 */
		/* 0x00003DA0 06                 */ IL_0010: ldloc.0
		/* 0x00003DA1 2C21               */ IL_0011: brfalse.s IL_0034
		/* 0x00003DA3 07                 */ IL_0013: ldloc.1
		/* 0x00003DA4 2C1E               */ IL_0014: brfalse.s IL_0034
		/* 0x00003DA6 02                 */ IL_0016: ldarg.0
		/* 0x00003DA7 7B26000004         */ IL_0017: ldfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_selected /* 04000026 */
		/* 0x00003DAC 06                 */ IL_001c: ldloc.0
		/* 0x00003DAD 6F28000006         */ IL_001d: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00003DB2 07                 */ IL_0022: ldloc.1
		/* 0x00003DB3 6F28000006         */ IL_0023: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00003DB8 6FC600000A         */ IL_0028: callvirt instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, string>::set_Item(!0, !1) /* 0A0000C6 */
		/* 0x00003DBD 02                 */ IL_002d: ldarg.0
		/* 0x00003DBE 07                 */ IL_002e: ldloc.1
		/* 0x00003DBF 2877000006         */ IL_002f: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Execute(class AspenTech.Visualisation.Controls.Assistant.AssistOption) /* 06000077 */
		/* 0x00003DC4 2A                 */ IL_0034: ret
	} // end of method AssistantViewModel::'<get_SelectCommand>b__13'

	.method /* 0600007E */ private hidebysig 
		instance bool '<get_RedoCommand>b__14' (
			object param
		) cil managed 
	{
		.custom /* 0C000078 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3e04
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x00003E04 02                 */ IL_0000: ldarg.0
		/* 0x00003E05 02                 */ IL_0001: ldarg.0
		/* 0x00003E06 7B25000004         */ IL_0002: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003E0B 17                 */ IL_0007: ldc.i4.1
		/* 0x00003E0C 2869000006         */ IL_0008: call instance class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::DefaultOption(class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool) /* 06000069 */
		/* 0x00003E11 14                 */ IL_000d: ldnull
		/* 0x00003E12 FE01               */ IL_000e: ceq
		/* 0x00003E14 16                 */ IL_0010: ldc.i4.0
		/* 0x00003E15 FE01               */ IL_0011: ceq
		/* 0x00003E17 2A                 */ IL_0013: ret
	} // end of method AssistantViewModel::'<get_RedoCommand>b__14'

	.method /* 0600007F */ private hidebysig 
		instance void '<get_RedoCommand>b__15' (
			object param
		) cil managed 
	{
		.custom /* 0C000079 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3e1c
		// Header size: 12
		// Code size: 25 (0x19)
		.maxstack 3
		.locals /* 1100001E */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistOption
		)

		/* 0x00003E1C 02                 */ IL_0000: ldarg.0
		/* 0x00003E1D 02                 */ IL_0001: ldarg.0
		/* 0x00003E1E 7B25000004         */ IL_0002: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_screen /* 04000025 */
		/* 0x00003E23 17                 */ IL_0007: ldc.i4.1
		/* 0x00003E24 2869000006         */ IL_0008: call instance class AspenTech.Visualisation.Controls.Assistant.AssistOption AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::DefaultOption(class AspenTech.Visualisation.Controls.Assistant.AssistScreen, bool) /* 06000069 */
		/* 0x00003E29 0A                 */ IL_000d: stloc.0
		/* 0x00003E2A 06                 */ IL_000e: ldloc.0
		/* 0x00003E2B 2C07               */ IL_000f: brfalse.s IL_0018
		/* 0x00003E2D 02                 */ IL_0011: ldarg.0
		/* 0x00003E2E 06                 */ IL_0012: ldloc.0
		/* 0x00003E2F 2877000006         */ IL_0013: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::Execute(class AspenTech.Visualisation.Controls.Assistant.AssistOption) /* 06000077 */
		/* 0x00003E34 2A                 */ IL_0018: ret
	} // end of method AssistantViewModel::'<get_RedoCommand>b__15'

	.method /* 06000080 */ private hidebysig 
		instance bool '<get_UndoCommand>b__18' (
			object param
		) cil managed 
	{
		.custom /* 0C00007A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3eae
		// Header size: 1
		// Code size: 15 (0xf)
		.maxstack 8

		/* 0x00003EAE 02                 */ IL_0000: ldarg.0
		/* 0x00003EAF 7B2A000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003EB4 6FB800000A         */ IL_0006: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x00003EB9 17                 */ IL_000b: ldc.i4.1
		/* 0x00003EBA FE02               */ IL_000c: cgt
		/* 0x00003EBC 2A                 */ IL_000e: ret
	} // end of method AssistantViewModel::'<get_UndoCommand>b__18'

	.method /* 06000081 */ private hidebysig 
		instance void '<get_UndoCommand>b__19' (
			object param
		) cil managed 
	{
		.custom /* 0C00007B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3ec0
		// Header size: 12
		// Code size: 57 (0x39)
		.maxstack 3
		.locals /* 1100001A */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.AssistScreen
		)

		/* 0x00003EC0 02                 */ IL_0000: ldarg.0
		/* 0x00003EC1 7B2A000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003EC6 02                 */ IL_0006: ldarg.0
		/* 0x00003EC7 7B2A000004         */ IL_0007: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003ECC 6FB800000A         */ IL_000c: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x00003ED1 18                 */ IL_0011: ldc.i4.2
		/* 0x00003ED2 59                 */ IL_0012: sub
		/* 0x00003ED3 6FB600000A         */ IL_0013: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Item(int32) /* 0A0000B6 */
		/* 0x00003ED8 0A                 */ IL_0018: stloc.0
		/* 0x00003ED9 02                 */ IL_0019: ldarg.0
		/* 0x00003EDA 7B2A000004         */ IL_001a: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003EDF 02                 */ IL_001f: ldarg.0
		/* 0x00003EE0 7B2A000004         */ IL_0020: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::_history /* 0400002A */
		/* 0x00003EE5 6FB800000A         */ IL_0025: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Count() /* 0A0000B8 */
		/* 0x00003EEA 17                 */ IL_002a: ldc.i4.1
		/* 0x00003EEB 59                 */ IL_002b: sub
		/* 0x00003EEC 6FB700000A         */ IL_002c: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::RemoveAt(int32) /* 0A0000B7 */
		/* 0x00003EF1 02                 */ IL_0031: ldarg.0
		/* 0x00003EF2 06                 */ IL_0032: ldloc.0
		/* 0x00003EF3 286B000006         */ IL_0033: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::SelectScreen(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 0600006B */
		/* 0x00003EF8 2A                 */ IL_0038: ret
	} // end of method AssistantViewModel::'<get_UndoCommand>b__19'

	// Events
	.event /* 14000003 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 1700001D */ instance string ScreenId()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::get_ScreenId()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::set_ScreenId(string)
	}
	.property /* 1700001E */ instance class AspenTech.Visualisation.Controls.Assistant.IRootViewModel Root()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.IRootViewModel AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::get_Root()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::set_Root(class AspenTech.Visualisation.Controls.Assistant.IRootViewModel)
	}
	.property /* 1700001F */ instance class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel Screen()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::get_Screen()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::set_Screen(class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel)
	}
	.property /* 17000020 */ instance class [PresentationCore]System.Windows.Input.ICommand SelectCommand()
	{
		.get instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::get_SelectCommand()
	}
	.property /* 17000021 */ instance class [PresentationCore]System.Windows.Input.ICommand RedoCommand()
	{
		.get instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::get_RedoCommand()
	}
	.property /* 17000022 */ instance class [PresentationCore]System.Windows.Input.ICommand UndoCommand()
	{
		.get instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::get_UndoCommand()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistantViewModel

.class /* 02000011 */ interface private auto ansi abstract AspenTech.Visualisation.Controls.Assistant.IRootViewModel
{
	// Methods
	.method /* 06000082 */ public hidebysig specialname newslot abstract virtual 
		instance string get_Title () cil managed 
	{
	} // end of method IRootViewModel::get_Title

	// Properties
	.property /* 17000023 */ instance string Title()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.IRootViewModel::get_Title()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.IRootViewModel

.class /* 02000012 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.RootViewModel
	extends [mscorlib]System.Object
	implements AspenTech.Visualisation.Controls.Assistant.IRootViewModel
{
	// Fields
	.field /* 0400002E */ private class AspenTech.Visualisation.Controls.Assistant.AssistRoot _root

	// Methods
	.method /* 06000083 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot root
		) cil managed 
	{
		// Method begins at RVA 0x4524
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x00004524 02                 */ IL_0000: ldarg.0
		/* 0x00004525 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x0000452A 02                 */ IL_0006: ldarg.0
		/* 0x0000452B 03                 */ IL_0007: ldarg.1
		/* 0x0000452C 7D2E000004         */ IL_0008: stfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.RootViewModel::_root /* 0400002E */
		/* 0x00004531 2A                 */ IL_000d: ret
	} // end of method RootViewModel::.ctor

	.method /* 06000084 */ public final hidebysig specialname newslot virtual 
		instance string get_Title () cil managed 
	{
		// Method begins at RVA 0x4533
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00004533 02                 */ IL_0000: ldarg.0
		/* 0x00004534 7B2E000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.RootViewModel::_root /* 0400002E */
		/* 0x00004539 6F2F000006         */ IL_0006: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x0000453E 2A                 */ IL_000b: ret
	} // end of method RootViewModel::get_Title

	// Properties
	.property /* 17000024 */ instance string Title()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.RootViewModel::get_Title()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.RootViewModel

.class /* 02000013 */ interface private auto ansi abstract AspenTech.Visualisation.Controls.Assistant.IScreenViewModel
{
	// Methods
	.method /* 06000085 */ public hidebysig specialname newslot abstract virtual 
		instance string get_Title () cil managed 
	{
	} // end of method IScreenViewModel::get_Title

	// Properties
	.property /* 17000025 */ instance string Title()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.IScreenViewModel::get_Title()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.IScreenViewModel

.class /* 02000014 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.ScreenViewModel
	extends [mscorlib]System.Object
	implements AspenTech.Visualisation.Controls.Assistant.IScreenViewModel
{
	// Fields
	.field /* 0400002F */ private class AspenTech.Visualisation.Controls.Assistant.AssistScreen _screen

	// Methods
	.method /* 06000086 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistScreen screen
		) cil managed 
	{
		// Method begins at RVA 0x4540
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x00004540 02                 */ IL_0000: ldarg.0
		/* 0x00004541 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00004546 02                 */ IL_0006: ldarg.0
		/* 0x00004547 03                 */ IL_0007: ldarg.1
		/* 0x00004548 7D2F000004         */ IL_0008: stfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.ScreenViewModel::_screen /* 0400002F */
		/* 0x0000454D 2A                 */ IL_000d: ret
	} // end of method ScreenViewModel::.ctor

	.method /* 06000087 */ public final hidebysig specialname newslot virtual 
		instance string get_Title () cil managed 
	{
		// Method begins at RVA 0x454f
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x0000454F 02                 */ IL_0000: ldarg.0
		/* 0x00004550 7B2F000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.ScreenViewModel::_screen /* 0400002F */
		/* 0x00004555 6F2F000006         */ IL_0006: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x0000455A 2A                 */ IL_000b: ret
	} // end of method ScreenViewModel::get_Title

	.method /* 06000088 */ public hidebysig specialname 
		instance string get_Id () cil managed 
	{
		// Method begins at RVA 0x455c
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x0000455C 02                 */ IL_0000: ldarg.0
		/* 0x0000455D 7B2F000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.ScreenViewModel::_screen /* 0400002F */
		/* 0x00004562 6F28000006         */ IL_0006: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00004567 2A                 */ IL_000b: ret
	} // end of method ScreenViewModel::get_Id

	// Properties
	.property /* 17000026 */ instance string Title()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.ScreenViewModel::get_Title()
	}
	.property /* 17000027 */ instance string Id()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.ScreenViewModel::get_Id()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.ScreenViewModel

.class /* 02000015 */ public auto ansi sealed AspenTech.Visualisation.Controls.Assistant.Action
	extends [mscorlib]System.Enum
{
	// Fields
	.field /* 04000030 */ public specialname rtspecialname int32 value__
	.field /* 04000031 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action NoOperation = int32(0)
	.field /* 04000032 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Goto = int32(1)
	.field /* 04000033 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action GotoButton = int32(2)
	.field /* 04000034 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Assistant = int32(3)
	.field /* 04000035 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Run = int32(4)
	.field /* 04000036 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Browse = int32(5)
	.field /* 04000037 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Internet = int32(6)
	.field /* 04000038 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Note = int32(7)
	.field /* 04000039 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.Action Exec = int32(8)

} // end of class AspenTech.Visualisation.Controls.Assistant.Action

.class /* 02000016 */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistOption
	extends AspenTech.Visualisation.Controls.Assistant.AssistBase
{
	// Fields
	.field /* 0400003A */ private valuetype AspenTech.Visualisation.Controls.Assistant.Action '<Action>k__BackingField'
	.custom /* 0C000052 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400003B */ private string '<Command>k__BackingField'
	.custom /* 0C000054 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400003C */ private class AspenTech.Visualisation.Controls.Assistant.AssistScreen '<Parent>k__BackingField'
	.custom /* 0C000056 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000089 */ public hidebysig specialname 
		instance valuetype AspenTech.Visualisation.Controls.Assistant.Action get_Action () cil managed 
	{
		.custom /* 0C00007C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4569
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004569 02                 */ IL_0000: ldarg.0
		/* 0x0000456A 7B3A000004         */ IL_0001: ldfld valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::'<Action>k__BackingField' /* 0400003A */
		/* 0x0000456F 2A                 */ IL_0006: ret
	} // end of method AssistOption::get_Action

	.method /* 0600008A */ public hidebysig specialname 
		instance void set_Action (
			valuetype AspenTech.Visualisation.Controls.Assistant.Action 'value'
		) cil managed 
	{
		.custom /* 0C00007D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4571
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004571 02                 */ IL_0000: ldarg.0
		/* 0x00004572 03                 */ IL_0001: ldarg.1
		/* 0x00004573 7D3A000004         */ IL_0002: stfld valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::'<Action>k__BackingField' /* 0400003A */
		/* 0x00004578 2A                 */ IL_0007: ret
	} // end of method AssistOption::set_Action

	.method /* 0600008B */ public hidebysig specialname 
		instance string get_Command () cil managed 
	{
		.custom /* 0C00007E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x457a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000457A 02                 */ IL_0000: ldarg.0
		/* 0x0000457B 7B3B000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.AssistOption::'<Command>k__BackingField' /* 0400003B */
		/* 0x00004580 2A                 */ IL_0006: ret
	} // end of method AssistOption::get_Command

	.method /* 0600008C */ public hidebysig specialname 
		instance void set_Command (
			string 'value'
		) cil managed 
	{
		.custom /* 0C00007F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4582
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004582 02                 */ IL_0000: ldarg.0
		/* 0x00004583 03                 */ IL_0001: ldarg.1
		/* 0x00004584 7D3B000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.AssistOption::'<Command>k__BackingField' /* 0400003B */
		/* 0x00004589 2A                 */ IL_0007: ret
	} // end of method AssistOption::set_Command

	.method /* 0600008D */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistScreen get_Parent () cil managed 
	{
		.custom /* 0C000081 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x458b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000458B 02                 */ IL_0000: ldarg.0
		/* 0x0000458C 7B3C000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistOption::'<Parent>k__BackingField' /* 0400003C */
		/* 0x00004591 2A                 */ IL_0006: ret
	} // end of method AssistOption::get_Parent

	.method /* 0600008E */ private hidebysig specialname 
		instance void set_Parent (
			class AspenTech.Visualisation.Controls.Assistant.AssistScreen 'value'
		) cil managed 
	{
		.custom /* 0C000082 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4593
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004593 02                 */ IL_0000: ldarg.0
		/* 0x00004594 03                 */ IL_0001: ldarg.1
		/* 0x00004595 7D3C000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistOption::'<Parent>k__BackingField' /* 0400003C */
		/* 0x0000459A 2A                 */ IL_0007: ret
	} // end of method AssistOption::set_Parent

	.method /* 0600008F */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistScreen parent
		) cil managed 
	{
		// Method begins at RVA 0x459c
		// Header size: 12
		// Code size: 181 (0xb5)
		.maxstack 5
		.locals /* 11000024 */ init (
			[0] int32,
			[1] string,
			[2] class AspenTech.Visualisation.Controls.Assistant.AssistOption,
			[3] int32,
			[4] valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>
		)

		/* 0x0000459C 02                 */ IL_0000: ldarg.0
		/* 0x0000459D 03                 */ IL_0001: ldarg.1
		/* 0x0000459E 6F33000006         */ IL_0002: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Root() /* 06000033 */
		/* 0x000045A3 7E63000004         */ IL_0007: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Option /* 04000063 */
		/* 0x000045A8 2835000006         */ IL_000c: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot, class [System.Xml.Linq]System.Xml.Linq.XName) /* 06000035 */
		/* 0x000045AD 02                 */ IL_0011: ldarg.0
		/* 0x000045AE 03                 */ IL_0012: ldarg.1
		/* 0x000045AF 288E000006         */ IL_0013: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Parent(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 0600008E */
		/* 0x000045B4 16                 */ IL_0018: ldc.i4.0
		/* 0x000045B5 0A                 */ IL_0019: stloc.0
		/* 0x000045B6 03                 */ IL_001a: ldarg.1
		/* 0x000045B7 6F28000006         */ IL_001b: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000045BC 72AD000070         */ IL_0020: ldstr "." /* 700000AD */
		/* 0x000045C1 283500000A         */ IL_0025: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x000045C6 0B                 */ IL_002a: stloc.1
		/* 0x000045C7 03                 */ IL_002b: ldarg.1
		/* 0x000045C8 6FBA000006         */ IL_002c: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x000045CD 6F6700000A         */ IL_0031: callvirt instance valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<!0> class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::GetEnumerator() /* 0A000067 */
		/* 0x000045D2 1304               */ IL_0036: stloc.s 4
		/* 0x000045D4 2B3E               */ IL_0038: br.s IL_0078
		/* 0x000045D6 1204               */ IL_003a: ldloca.s 4
		/* 0x000045D8 286800000A         */ IL_003c: call instance !0 valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::get_Current() /* 0A000068 */
		/* 0x000045DD 0C                 */ IL_0041: stloc.2
		/* 0x000045DE 08                 */ IL_0042: ldloc.2
		/* 0x000045DF 6F28000006         */ IL_0043: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000045E4 07                 */ IL_0048: ldloc.1
		/* 0x000045E5 6FB200000A         */ IL_0049: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x000045EA 2C28               */ IL_004e: brfalse.s IL_0078
		/* 0x000045EC 08                 */ IL_0050: ldloc.2
		/* 0x000045ED 6F28000006         */ IL_0051: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000045F2 07                 */ IL_0056: ldloc.1
		/* 0x000045F3 6F3100000A         */ IL_0057: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x000045F8 6F7200000A         */ IL_005c: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x000045FD 1D                 */ IL_0061: ldc.i4.7
		/* 0x000045FE 282D00000A         */ IL_0062: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x00004603 1203               */ IL_0067: ldloca.s 3
		/* 0x00004605 28D300000A         */ IL_0069: call bool [mscorlib]System.Int32::TryParse(string, valuetype [mscorlib]System.Globalization.NumberStyles, class [mscorlib]System.IFormatProvider, int32&) /* 0A0000D3 */
		/* 0x0000460A 2C08               */ IL_006e: brfalse.s IL_0078
		/* 0x0000460C 06                 */ IL_0070: ldloc.0
		/* 0x0000460D 09                 */ IL_0071: ldloc.3
		/* 0x0000460E 28D400000A         */ IL_0072: call int32 [mscorlib]System.Math::Max(int32, int32) /* 0A0000D4 */
		/* 0x00004613 0A                 */ IL_0077: stloc.0
		/* 0x00004614 1204               */ IL_0078: ldloca.s 4
		/* 0x00004616 286C00000A         */ IL_007a: call instance bool valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::MoveNext() /* 0A00006C */
		/* 0x0000461B 2DB9               */ IL_007f: brtrue.s IL_003a
		/* 0x0000461D DE0E               */ IL_0081: leave.s IL_0091
		/* 0x0000461F 1204               */ IL_0083: ldloca.s 4
		/* 0x00004621 FE160500001B       */ IL_0085: constrained. valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption> /* 1B000005 */
		/* 0x00004627 6F6D00000A         */ IL_008b: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x0000462C DC                 */ IL_0090: endfinally
		/* 0x0000462D 02                 */ IL_0091: ldarg.0
		/* 0x0000462E 02                 */ IL_0092: ldarg.0
		/* 0x0000462F 288D000006         */ IL_0093: call instance class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Parent() /* 0600008D */
		/* 0x00004634 6F28000006         */ IL_0098: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00004639 72AD000070         */ IL_009d: ldstr "." /* 700000AD */
		/* 0x0000463E 06                 */ IL_00a2: ldloc.0
		/* 0x0000463F 17                 */ IL_00a3: ldc.i4.1
		/* 0x00004640 58                 */ IL_00a4: add
		/* 0x00004641 8C73000001         */ IL_00a5: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x00004646 28D500000A         */ IL_00aa: call string [mscorlib]System.String::Concat(object, object, object) /* 0A0000D5 */
		/* 0x0000464B 2829000006         */ IL_00af: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_Id(string) /* 06000029 */
		/* 0x00004650 2A                 */ IL_00b4: ret

		.try IL_0038-IL_0083 finally IL_0083-IL_0091
	} // end of method AssistOption::.ctor

	.method /* 06000090 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot root
		) cil managed 
	{
		// Method begins at RVA 0x4670
		// Header size: 12
		// Code size: 100 (0x64)
		.maxstack 3
		.locals /* 1100000D */ init (
			[0] string,
			[1] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>
		)

		/* 0x00004670 02                 */ IL_0000: ldarg.0
		/* 0x00004671 03                 */ IL_0001: ldarg.1
		/* 0x00004672 14                 */ IL_0002: ldnull
		/* 0x00004673 2835000006         */ IL_0003: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot, class [System.Xml.Linq]System.Xml.Linq.XName) /* 06000035 */
		/* 0x00004678 02                 */ IL_0008: ldarg.0
		/* 0x00004679 14                 */ IL_0009: ldnull
		/* 0x0000467A 288E000006         */ IL_000a: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Parent(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 0600008E */
		/* 0x0000467F 02                 */ IL_000f: ldarg.0
		/* 0x00004680 17                 */ IL_0010: ldc.i4.1
		/* 0x00004681 288A000006         */ IL_0011: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Action(valuetype AspenTech.Visualisation.Controls.Assistant.Action) /* 0600008A */
		/* 0x00004686 02                 */ IL_0016: ldarg.0
		/* 0x00004687 03                 */ IL_0017: ldarg.1
		/* 0x00004688 6F3F000006         */ IL_0018: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_First() /* 0600003F */
		/* 0x0000468D 288C000006         */ IL_001d: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Command(string) /* 0600008C */
		/* 0x00004692 02                 */ IL_0022: ldarg.0
		/* 0x00004693 03                 */ IL_0023: ldarg.1
		/* 0x00004694 6F2F000006         */ IL_0024: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00004699 2830000006         */ IL_0029: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x0000469E 03                 */ IL_002e: ldarg.1
		/* 0x0000469F 6F31000006         */ IL_002f: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x000046A4 6F7500000A         */ IL_0034: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A000075 */
		/* 0x000046A9 0B                 */ IL_0039: stloc.1
		/* 0x000046AA 2B13               */ IL_003a: br.s IL_004f
		/* 0x000046AC 07                 */ IL_003c: ldloc.1
		/* 0x000046AD 6F7600000A         */ IL_003d: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A000076 */
		/* 0x000046B2 0A                 */ IL_0042: stloc.0
		/* 0x000046B3 02                 */ IL_0043: ldarg.0
		/* 0x000046B4 2831000006         */ IL_0044: call instance class [mscorlib]System.Collections.Generic.IList`1<string> AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Explanation() /* 06000031 */
		/* 0x000046B9 06                 */ IL_0049: ldloc.0
		/* 0x000046BA 6F7F00000A         */ IL_004a: callvirt instance void class [mscorlib]System.Collections.Generic.ICollection`1<string>::Add(!0) /* 0A00007F */
		/* 0x000046BF 07                 */ IL_004f: ldloc.1
		/* 0x000046C0 6F7700000A         */ IL_0050: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x000046C5 2DE5               */ IL_0055: brtrue.s IL_003c
		/* 0x000046C7 DE0A               */ IL_0057: leave.s IL_0063
		/* 0x000046C9 07                 */ IL_0059: ldloc.1
		/* 0x000046CA 2C06               */ IL_005a: brfalse.s IL_0062
		/* 0x000046CC 07                 */ IL_005c: ldloc.1
		/* 0x000046CD 6F6D00000A         */ IL_005d: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x000046D2 DC                 */ IL_0062: endfinally
		/* 0x000046D3 2A                 */ IL_0063: ret

		.try IL_003a-IL_0059 finally IL_0059-IL_0063
	} // end of method AssistOption::.ctor

	.method /* 06000091 */ assembly hidebysig strict virtual 
		instance void HydrateFromXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement root
		) cil managed 
	{
		// Method begins at RVA 0x46f0
		// Header size: 12
		// Code size: 206 (0xce)
		.maxstack 4
		.locals /* 11000025 */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XElement
		)

		/* 0x000046F0 03                 */ IL_0000: ldarg.1
		/* 0x000046F1 6F9900000A         */ IL_0001: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XElement::get_Name() /* 0A000099 */
		/* 0x000046F6 7E63000004         */ IL_0006: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Option /* 04000063 */
		/* 0x000046FB 289A00000A         */ IL_000b: call bool [System.Xml.Linq]System.Xml.Linq.XName::op_Inequality(class [System.Xml.Linq]System.Xml.Linq.XName, class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009A */
		/* 0x00004700 2C0B               */ IL_0010: brfalse.s IL_001d
		/* 0x00004702 72C6030070         */ IL_0012: ldstr "root" /* 700003C6 */
		/* 0x00004707 731A00000A         */ IL_0017: newobj instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string) /* 0A00001A */
		/* 0x0000470C 7A                 */ IL_001c: throw
		/* 0x0000470D 02                 */ IL_001d: ldarg.0
		/* 0x0000470E 03                 */ IL_001e: ldarg.1
		/* 0x0000470F 7E6C000004         */ IL_001f: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x00004714 6F9B00000A         */ IL_0024: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x00004719 7E2800000A         */ IL_0029: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x0000471E 28B1000006         */ IL_002e: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, string) /* 060000B1 */
		/* 0x00004723 2829000006         */ IL_0033: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_Id(string) /* 06000029 */
		/* 0x00004728 02                 */ IL_0038: ldarg.0
		/* 0x00004729 03                 */ IL_0039: ldarg.1
		/* 0x0000472A 7E5E000004         */ IL_003a: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Caption /* 0400005E */
		/* 0x0000472F 6F9E00000A         */ IL_003f: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00004734 7E2800000A         */ IL_0044: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00004739 28B5000006         */ IL_0049: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XElement, string) /* 060000B5 */
		/* 0x0000473E 2830000006         */ IL_004e: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x00004743 02                 */ IL_0053: ldarg.0
		/* 0x00004744 03                 */ IL_0054: ldarg.1
		/* 0x00004745 2837000006         */ IL_0055: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::ExplanationsFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 06000037 */
		/* 0x0000474A 03                 */ IL_005a: ldarg.1
		/* 0x0000474B 7E60000004         */ IL_005b: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Action /* 04000060 */
		/* 0x00004750 6F9E00000A         */ IL_0060: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00004755 0A                 */ IL_0065: stloc.0
		/* 0x00004756 06                 */ IL_0066: ldloc.0
		/* 0x00004757 2D13               */ IL_0067: brtrue.s IL_007c
		/* 0x00004759 02                 */ IL_0069: ldarg.0
		/* 0x0000475A 16                 */ IL_006a: ldc.i4.0
		/* 0x0000475B 288A000006         */ IL_006b: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Action(valuetype AspenTech.Visualisation.Controls.Assistant.Action) /* 0600008A */
		/* 0x00004760 02                 */ IL_0070: ldarg.0
		/* 0x00004761 7E2800000A         */ IL_0071: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00004766 288C000006         */ IL_0076: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Command(string) /* 0600008C */
		/* 0x0000476B 2A                 */ IL_007b: ret
		/* 0x0000476C 02                 */ IL_007c: ldarg.0
		/* 0x0000476D D015000002         */ IL_007d: ldtoken AspenTech.Visualisation.Controls.Assistant.Action /* 02000015 */
		/* 0x00004772 284A00000A         */ IL_0082: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00004A */
		/* 0x00004777 06                 */ IL_0087: ldloc.0
		/* 0x00004778 7E6F000004         */ IL_0088: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::ActionType /* 0400006F */
		/* 0x0000477D 6F9B00000A         */ IL_008d: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x00004782 16                 */ IL_0092: ldc.i4.0
		/* 0x00004783 8C15000002         */ IL_0093: box AspenTech.Visualisation.Controls.Assistant.Action /* 02000015 */
		/* 0x00004788 6F6000000A         */ IL_0098: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x0000478D 28B1000006         */ IL_009d: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, string) /* 060000B1 */
		/* 0x00004792 17                 */ IL_00a2: ldc.i4.1
		/* 0x00004793 28D600000A         */ IL_00a3: call object [mscorlib]System.Enum::Parse(class [mscorlib]System.Type, string, bool) /* 0A0000D6 */
		/* 0x00004798 A515000002         */ IL_00a8: unbox.any AspenTech.Visualisation.Controls.Assistant.Action /* 02000015 */
		/* 0x0000479D 288A000006         */ IL_00ad: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Action(valuetype AspenTech.Visualisation.Controls.Assistant.Action) /* 0600008A */
		/* 0x000047A2 02                 */ IL_00b2: ldarg.0
		/* 0x000047A3 06                 */ IL_00b3: ldloc.0
		/* 0x000047A4 7E6E000004         */ IL_00b4: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Command /* 0400006E */
		/* 0x000047A9 6F9B00000A         */ IL_00b9: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x000047AE 7E2800000A         */ IL_00be: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x000047B3 28B1000006         */ IL_00c3: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, string) /* 060000B1 */
		/* 0x000047B8 288C000006         */ IL_00c8: call instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Command(string) /* 0600008C */
		/* 0x000047BD 2A                 */ IL_00cd: ret
	} // end of method AssistOption::HydrateFromXml

	.method /* 06000092 */ assembly hidebysig strict virtual 
		instance class [System.Xml.Linq]System.Xml.Linq.XElement DehydrateToXml () cil managed 
	{
		// Method begins at RVA 0x47cc
		// Header size: 12
		// Code size: 151 (0x97)
		.maxstack 7
		.locals /* 11000026 */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[1] object[],
			[2] object[]
		)

		/* 0x000047CC 7E63000004         */ IL_0000: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Option /* 04000063 */
		/* 0x000047D1 18                 */ IL_0005: ldc.i4.2
		/* 0x000047D2 8D01000001         */ IL_0006: newarr [mscorlib]System.Object /* 01000001 */
		/* 0x000047D7 0B                 */ IL_000b: stloc.1
		/* 0x000047D8 07                 */ IL_000c: ldloc.1
		/* 0x000047D9 16                 */ IL_000d: ldc.i4.0
		/* 0x000047DA 7E6C000004         */ IL_000e: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x000047DF 02                 */ IL_0013: ldarg.0
		/* 0x000047E0 2828000006         */ IL_0014: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000047E5 73A400000A         */ IL_0019: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x000047EA A2                 */ IL_001e: stelem.ref
		/* 0x000047EB 07                 */ IL_001f: ldloc.1
		/* 0x000047EC 17                 */ IL_0020: ldc.i4.1
		/* 0x000047ED 7E5E000004         */ IL_0021: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Caption /* 0400005E */
		/* 0x000047F2 02                 */ IL_0026: ldarg.0
		/* 0x000047F3 282F000006         */ IL_0027: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x000047F8 737900000A         */ IL_002c: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A000079 */
		/* 0x000047FD A2                 */ IL_0031: stelem.ref
		/* 0x000047FE 07                 */ IL_0032: ldloc.1
		/* 0x000047FF 73A500000A         */ IL_0033: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object[]) /* 0A0000A5 */
		/* 0x00004804 0A                 */ IL_0038: stloc.0
		/* 0x00004805 02                 */ IL_0039: ldarg.0
		/* 0x00004806 06                 */ IL_003a: ldloc.0
		/* 0x00004807 2836000006         */ IL_003b: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::ExplanationsToXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 06000036 */
		/* 0x0000480C 02                 */ IL_0040: ldarg.0
		/* 0x0000480D 2889000006         */ IL_0041: call instance valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Action() /* 06000089 */
		/* 0x00004812 2C4D               */ IL_0046: brfalse.s IL_0095
		/* 0x00004814 06                 */ IL_0048: ldloc.0
		/* 0x00004815 7E60000004         */ IL_0049: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Action /* 04000060 */
		/* 0x0000481A 18                 */ IL_004e: ldc.i4.2
		/* 0x0000481B 8D01000001         */ IL_004f: newarr [mscorlib]System.Object /* 01000001 */
		/* 0x00004820 0C                 */ IL_0054: stloc.2
		/* 0x00004821 08                 */ IL_0055: ldloc.2
		/* 0x00004822 16                 */ IL_0056: ldc.i4.0
		/* 0x00004823 7E6F000004         */ IL_0057: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::ActionType /* 0400006F */
		/* 0x00004828 02                 */ IL_005c: ldarg.0
		/* 0x00004829 2889000006         */ IL_005d: call instance valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Action() /* 06000089 */
		/* 0x0000482E 8C15000002         */ IL_0062: box AspenTech.Visualisation.Controls.Assistant.Action /* 02000015 */
		/* 0x00004833 6F6000000A         */ IL_0067: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00004838 6FD700000A         */ IL_006c: callvirt instance string [mscorlib]System.String::ToUpperInvariant() /* 0A0000D7 */
		/* 0x0000483D 73A400000A         */ IL_0071: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x00004842 A2                 */ IL_0076: stelem.ref
		/* 0x00004843 08                 */ IL_0077: ldloc.2
		/* 0x00004844 17                 */ IL_0078: ldc.i4.1
		/* 0x00004845 7E6E000004         */ IL_0079: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Command /* 0400006E */
		/* 0x0000484A 02                 */ IL_007e: ldarg.0
		/* 0x0000484B 288B000006         */ IL_007f: call instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command() /* 0600008B */
		/* 0x00004850 73A400000A         */ IL_0084: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x00004855 A2                 */ IL_0089: stelem.ref
		/* 0x00004856 08                 */ IL_008a: ldloc.2
		/* 0x00004857 73A500000A         */ IL_008b: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object[]) /* 0A0000A5 */
		/* 0x0000485C 6F7A00000A         */ IL_0090: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object) /* 0A00007A */
		/* 0x00004861 06                 */ IL_0095: ldloc.0
		/* 0x00004862 2A                 */ IL_0096: ret
	} // end of method AssistOption::DehydrateToXml

	// Properties
	.property /* 17000028 */ instance valuetype AspenTech.Visualisation.Controls.Assistant.Action Action()
	{
		.get instance valuetype AspenTech.Visualisation.Controls.Assistant.Action AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Action()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Action(valuetype AspenTech.Visualisation.Controls.Assistant.Action)
	}
	.property /* 17000029 */ instance string Command()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Command()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Command(string)
	}
	.property /* 1700002A */ instance class AspenTech.Visualisation.Controls.Assistant.AssistScreen Parent()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistScreen AspenTech.Visualisation.Controls.Assistant.AssistOption::get_Parent()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::set_Parent(class AspenTech.Visualisation.Controls.Assistant.AssistScreen)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistOption

.class /* 02000017 */ public auto ansi sealed AspenTech.Visualisation.Controls.Assistant.ProManAction
	extends [mscorlib]System.Enum
{
	// Fields
	.field /* 0400003D */ public specialname rtspecialname int32 value__
	.field /* 0400003E */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Text = int32(0)
	.field /* 0400003F */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Search = int32(1)
	.field /* 04000040 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Structure = int32(2)
	.field /* 04000041 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Content = int32(3)
	.field /* 04000042 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Home = int32(4)
	.field /* 04000043 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Login = int32(5)
	.field /* 04000044 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Reindex = int32(6)
	.field /* 04000045 */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction Support = int32(7)

} // end of class AspenTech.Visualisation.Controls.Assistant.ProManAction

.class /* 02000018 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.ProManBrowser
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000046 */ private string '<Title>k__BackingField'
	.custom /* 0C000061 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000047 */ private string '<Name>k__BackingField'
	.custom /* 0C000063 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000048 */ private string '<Url>k__BackingField'
	.custom /* 0C000065 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000093 */ assembly hidebysig specialname 
		instance string get_Title () cil managed 
	{
		.custom /* 0C000083 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x486f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000486F 02                 */ IL_0000: ldarg.0
		/* 0x00004870 7B46000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::'<Title>k__BackingField' /* 04000046 */
		/* 0x00004875 2A                 */ IL_0006: ret
	} // end of method ProManBrowser::get_Title

	.method /* 06000094 */ private hidebysig specialname 
		instance void set_Title (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000084 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4877
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004877 02                 */ IL_0000: ldarg.0
		/* 0x00004878 03                 */ IL_0001: ldarg.1
		/* 0x00004879 7D46000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::'<Title>k__BackingField' /* 04000046 */
		/* 0x0000487E 2A                 */ IL_0007: ret
	} // end of method ProManBrowser::set_Title

	.method /* 06000095 */ assembly hidebysig specialname 
		instance string get_Name () cil managed 
	{
		.custom /* 0C000085 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4880
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004880 02                 */ IL_0000: ldarg.0
		/* 0x00004881 7B47000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::'<Name>k__BackingField' /* 04000047 */
		/* 0x00004886 2A                 */ IL_0006: ret
	} // end of method ProManBrowser::get_Name

	.method /* 06000096 */ private hidebysig specialname 
		instance void set_Name (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000086 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4888
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004888 02                 */ IL_0000: ldarg.0
		/* 0x00004889 03                 */ IL_0001: ldarg.1
		/* 0x0000488A 7D47000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::'<Name>k__BackingField' /* 04000047 */
		/* 0x0000488F 2A                 */ IL_0007: ret
	} // end of method ProManBrowser::set_Name

	.method /* 06000097 */ assembly hidebysig specialname 
		instance string get_Url () cil managed 
	{
		.custom /* 0C000087 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4891
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004891 02                 */ IL_0000: ldarg.0
		/* 0x00004892 7B48000004         */ IL_0001: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::'<Url>k__BackingField' /* 04000048 */
		/* 0x00004897 2A                 */ IL_0006: ret
	} // end of method ProManBrowser::get_Url

	.method /* 06000098 */ private hidebysig specialname 
		instance void set_Url (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000088 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4899
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004899 02                 */ IL_0000: ldarg.0
		/* 0x0000489A 03                 */ IL_0001: ldarg.1
		/* 0x0000489B 7D48000004         */ IL_0002: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::'<Url>k__BackingField' /* 04000048 */
		/* 0x000048A0 2A                 */ IL_0007: ret
	} // end of method ProManBrowser::set_Url

	.method /* 06000099 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor (
			string name,
			string title,
			string url
		) cil managed 
	{
		// Method begins at RVA 0x48a2
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000048A2 02                 */ IL_0000: ldarg.0
		/* 0x000048A3 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x000048A8 02                 */ IL_0006: ldarg.0
		/* 0x000048A9 03                 */ IL_0007: ldarg.1
		/* 0x000048AA 2896000006         */ IL_0008: call instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::set_Name(string) /* 06000096 */
		/* 0x000048AF 02                 */ IL_000d: ldarg.0
		/* 0x000048B0 04                 */ IL_000e: ldarg.2
		/* 0x000048B1 2894000006         */ IL_000f: call instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::set_Title(string) /* 06000094 */
		/* 0x000048B6 02                 */ IL_0014: ldarg.0
		/* 0x000048B7 05                 */ IL_0015: ldarg.3
		/* 0x000048B8 2898000006         */ IL_0016: call instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::set_Url(string) /* 06000098 */
		/* 0x000048BD 2A                 */ IL_001b: ret
	} // end of method ProManBrowser::.ctor

	// Properties
	.property /* 1700002B */ instance string Title()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Title()
		.set instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::set_Title(string)
	}
	.property /* 1700002C */ instance string Name()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Name()
		.set instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::set_Name(string)
	}
	.property /* 1700002D */ instance string Url()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Url()
		.set instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::set_Url(string)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.ProManBrowser

.class /* 02000019 */ private auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.ProManBrowsers
	extends [mscorlib]System.Object
{
	// Nested Types
	.class /* 0200002E */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClass1'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000048 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 04000080 */ public string current

		// Methods
		.method /* 060000FB */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x4990
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00004990 02                 */ IL_0000: ldarg.0
			/* 0x00004991 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
			/* 0x00004996 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClass1'::.ctor

		.method /* 060000FC */ public hidebysig 
			instance bool '<TryBaseKey>b__0' (
				class AspenTech.Visualisation.Controls.Assistant.ProManBrowser x
			) cil managed 
		{
			// Method begins at RVA 0x4998
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x00004998 03                 */ IL_0000: ldarg.1
			/* 0x00004999 6F95000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Name() /* 06000095 */
			/* 0x0000499E 02                 */ IL_0006: ldarg.0
			/* 0x0000499F 7B80000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::current /* 04000080 */
			/* 0x000049A4 283F00000A         */ IL_000c: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x000049A9 2A                 */ IL_0011: ret
		} // end of method '<>c__DisplayClass1'::'<TryBaseKey>b__0'

	} // end of class <>c__DisplayClass1

	.class /* 0200002F */ nested private auto ansi sealed beforefieldinit '<>c__DisplayClass5'
		extends [mscorlib]System.Object
	{
		.custom /* 0C00004A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 04000081 */ public string 'value'

		// Methods
		.method /* 060000FD */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x4ac3
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00004AC3 02                 */ IL_0000: ldarg.0
			/* 0x00004AC4 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
			/* 0x00004AC9 2A                 */ IL_0006: ret
		} // end of method '<>c__DisplayClass5'::.ctor

		.method /* 060000FE */ public hidebysig 
			instance bool '<AddBrowsers>b__3' (
				class AspenTech.Visualisation.Controls.Assistant.ProManBrowser x
			) cil managed 
		{
			// Method begins at RVA 0x4acb
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x00004ACB 03                 */ IL_0000: ldarg.1
			/* 0x00004ACC 6F95000006         */ IL_0001: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Name() /* 06000095 */
			/* 0x00004AD1 02                 */ IL_0006: ldarg.0
			/* 0x00004AD2 7B81000004         */ IL_0007: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5'::'value' /* 04000081 */
			/* 0x00004AD7 283F00000A         */ IL_000c: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
			/* 0x00004ADC 2A                 */ IL_0011: ret
		} // end of method '<>c__DisplayClass5'::'<AddBrowsers>b__3'

	} // end of class <>c__DisplayClass5


	// Fields
	.field /* 04000049 */ private static class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers _global
	.field /* 0400004A */ private class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> '<Browsers>k__BackingField'
	.custom /* 0C000068 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400004B */ private class AspenTech.Visualisation.Controls.Assistant.ProManBrowser '<CurrentBrowser>k__BackingField'
	.custom /* 0C00006A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600009A */ assembly hidebysig specialname 
		instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> get_Browsers () cil managed 
	{
		.custom /* 0C000089 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x48bf
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000048BF 02                 */ IL_0000: ldarg.0
		/* 0x000048C0 7B4A000004         */ IL_0001: ldfld class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::'<Browsers>k__BackingField' /* 0400004A */
		/* 0x000048C5 2A                 */ IL_0006: ret
	} // end of method ProManBrowsers::get_Browsers

	.method /* 0600009B */ private hidebysig specialname 
		instance void set_Browsers (
			class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> 'value'
		) cil managed 
	{
		.custom /* 0C00008A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x48c7
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000048C7 02                 */ IL_0000: ldarg.0
		/* 0x000048C8 03                 */ IL_0001: ldarg.1
		/* 0x000048C9 7D4A000004         */ IL_0002: stfld class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::'<Browsers>k__BackingField' /* 0400004A */
		/* 0x000048CE 2A                 */ IL_0007: ret
	} // end of method ProManBrowsers::set_Browsers

	.method /* 0600009C */ assembly hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser get_CurrentBrowser () cil managed 
	{
		.custom /* 0C00008B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x48d0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000048D0 02                 */ IL_0000: ldarg.0
		/* 0x000048D1 7B4B000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::'<CurrentBrowser>k__BackingField' /* 0400004B */
		/* 0x000048D6 2A                 */ IL_0006: ret
	} // end of method ProManBrowsers::get_CurrentBrowser

	.method /* 0600009D */ assembly hidebysig specialname 
		instance void set_CurrentBrowser (
			class AspenTech.Visualisation.Controls.Assistant.ProManBrowser 'value'
		) cil managed 
	{
		.custom /* 0C00008C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x48d8
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000048D8 02                 */ IL_0000: ldarg.0
		/* 0x000048D9 03                 */ IL_0001: ldarg.1
		/* 0x000048DA 7D4B000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::'<CurrentBrowser>k__BackingField' /* 0400004B */
		/* 0x000048DF 2A                 */ IL_0007: ret
	} // end of method ProManBrowsers::set_CurrentBrowser

	.method /* 0600009E */ assembly hidebysig specialname static 
		class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers get_Global () cil managed 
	{
		// Method begins at RVA 0x48e4
		// Header size: 12
		// Code size: 130 (0x82)
		.maxstack 4
		.locals /* 11000009 */ init (
			[0] string
		)

		/* 0x000048E4 7E49000004         */ IL_0000: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x000048E9 2D75               */ IL_0005: brtrue.s IL_007c
		/* 0x000048EB 73A0000006         */ IL_0007: newobj instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::.ctor() /* 060000A0 */
		/* 0x000048F0 8049000004         */ IL_000c: stsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x000048F5 7E49000004         */ IL_0011: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x000048FA 725C060070         */ IL_0016: ldstr "Software\\AspenTech" /* 7000065C */
		/* 0x000048FF 6F9F000006         */ IL_001b: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::TryBaseKey(string) /* 0600009F */
		/* 0x00004904 7E49000004         */ IL_0020: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x00004909 7ED800000A         */ IL_0025: ldsfld class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.Registry::LocalMachine /* 0A0000D8 */
		/* 0x0000490E 7282060070         */ IL_002a: ldstr "Software\\AspenTech\\Aspen Process Manual" /* 70000682 */
		/* 0x00004913 6FA1000006         */ IL_002f: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::AddBrowsers(class [mscorlib]Microsoft.Win32.RegistryKey, string) /* 060000A1 */
		/* 0x00004918 7E49000004         */ IL_0034: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x0000491D 7ED900000A         */ IL_0039: ldsfld class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.Registry::CurrentUser /* 0A0000D9 */
		/* 0x00004922 72D2060070         */ IL_003e: ldstr "Software\\AEA Technology\\BaSYS\\ProMan\\Global" /* 700006D2 */
		/* 0x00004927 6FA1000006         */ IL_0043: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::AddBrowsers(class [mscorlib]Microsoft.Win32.RegistryKey, string) /* 060000A1 */
		/* 0x0000492C 28DA00000A         */ IL_0048: call class [mscorlib]System.Security.Principal.WindowsIdentity [mscorlib]System.Security.Principal.WindowsIdentity::GetCurrent() /* 0A0000DA */
		/* 0x00004931 6FDB00000A         */ IL_004d: callvirt instance class [mscorlib]System.Security.Principal.SecurityIdentifier [mscorlib]System.Security.Principal.WindowsIdentity::get_User() /* 0A0000DB */
		/* 0x00004936 6FDC00000A         */ IL_0052: callvirt instance string [mscorlib]System.Security.Principal.IdentityReference::get_Value() /* 0A0000DC */
		/* 0x0000493B 0A                 */ IL_0057: stloc.0
		/* 0x0000493C 7E49000004         */ IL_0058: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x00004941 722A070070         */ IL_005d: ldstr "Software\\Microsoft\\Internet Explorer\\InternetRegistry\\REGISTRY\\USER\\" /* 7000072A */
		/* 0x00004946 06                 */ IL_0062: ldloc.0
		/* 0x00004947 72B5070070         */ IL_0063: ldstr "\\Software\\AspenTech" /* 700007B5 */
		/* 0x0000494C 286300000A         */ IL_0068: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000063 */
		/* 0x00004951 6F9F000006         */ IL_006d: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::TryBaseKey(string) /* 0600009F */
		/* 0x00004956 DE03               */ IL_0072: leave.s IL_0077
		/* 0x00004958 26                 */ IL_0074: pop
		/* 0x00004959 DE00               */ IL_0075: leave.s IL_0077
		/* 0x0000495B DE03               */ IL_0077: leave.s IL_007c
		/* 0x0000495D 26                 */ IL_0079: pop
		/* 0x0000495E DE00               */ IL_007a: leave.s IL_007c
		/* 0x00004960 7E49000004         */ IL_007c: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x00004965 2A                 */ IL_0081: ret

		.try IL_0048-IL_0074 catch [mscorlib]System.Exception IL_0074-IL_0077
		.try IL_0011-IL_0079 catch [mscorlib]System.Exception IL_0079-IL_007c
	} // end of method ProManBrowsers::get_Global

	.method /* 0600009F */ private hidebysig 
		instance void TryBaseKey (
			string key
		) cil managed 
	{
		// Method begins at RVA 0x49ac
		// Header size: 12
		// Code size: 231 (0xe7)
		.maxstack 5
		.locals /* 11000027 */ init (
			[0] class [mscorlib]Microsoft.Win32.RegistryKey,
			[1] class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'
		)

		/* 0x000049AC 7E49000004         */ IL_0000: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x000049B1 7ED900000A         */ IL_0005: ldsfld class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.Registry::CurrentUser /* 0A0000D9 */
		/* 0x000049B6 03                 */ IL_000a: ldarg.1
		/* 0x000049B7 72DD070070         */ IL_000b: ldstr "\\Aspen Process Manual" /* 700007DD */
		/* 0x000049BC 283500000A         */ IL_0010: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x000049C1 6FA1000006         */ IL_0015: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::AddBrowsers(class [mscorlib]Microsoft.Win32.RegistryKey, string) /* 060000A1 */
		/* 0x000049C6 7E49000004         */ IL_001a: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x000049CB 7ED900000A         */ IL_001f: ldsfld class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.Registry::CurrentUser /* 0A0000D9 */
		/* 0x000049D0 03                 */ IL_0024: ldarg.1
		/* 0x000049D1 7209080070         */ IL_0025: ldstr "\\Process Manual\\Provider" /* 70000809 */
		/* 0x000049D6 283500000A         */ IL_002a: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x000049DB 6FA1000006         */ IL_002f: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::AddBrowsers(class [mscorlib]Microsoft.Win32.RegistryKey, string) /* 060000A1 */
		/* 0x000049E0 7E49000004         */ IL_0034: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x000049E5 6F9C000006         */ IL_0039: callvirt instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_CurrentBrowser() /* 0600009C */
		/* 0x000049EA 3AA3000000         */ IL_003e: brtrue IL_00e6
		/* 0x000049EF 73FB000006         */ IL_0043: newobj instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::.ctor() /* 060000FB */
		/* 0x000049F4 0B                 */ IL_0048: stloc.1
		/* 0x000049F5 07                 */ IL_0049: ldloc.1
		/* 0x000049F6 14                 */ IL_004a: ldnull
		/* 0x000049F7 7D80000004         */ IL_004b: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::current /* 04000080 */
		/* 0x000049FC 7ED900000A         */ IL_0050: ldsfld class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.Registry::CurrentUser /* 0A0000D9 */
		/* 0x00004A01 03                 */ IL_0055: ldarg.1
		/* 0x00004A02 72DD070070         */ IL_0056: ldstr "\\Aspen Process Manual" /* 700007DD */
		/* 0x00004A07 283500000A         */ IL_005b: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x00004A0C 6FDD00000A         */ IL_0060: callvirt instance class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.RegistryKey::OpenSubKey(string) /* 0A0000DD */
		/* 0x00004A11 0A                 */ IL_0065: stloc.0
		/* 0x00004A12 06                 */ IL_0066: ldloc.0
		/* 0x00004A13 2C39               */ IL_0067: brfalse.s IL_00a2
		/* 0x00004A15 07                 */ IL_0069: ldloc.1
		/* 0x00004A16 06                 */ IL_006a: ldloc.0
		/* 0x00004A17 723B080070         */ IL_006b: ldstr "Provider.Current" /* 7000083B */
		/* 0x00004A1C 6FDE00000A         */ IL_0070: callvirt instance object [mscorlib]Microsoft.Win32.RegistryKey::GetValue(string) /* 0A0000DE */
		/* 0x00004A21 7545000001         */ IL_0075: isinst [mscorlib]System.String /* 01000045 */
		/* 0x00004A26 7D80000004         */ IL_007a: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::current /* 04000080 */
		/* 0x00004A2B 07                 */ IL_007f: ldloc.1
		/* 0x00004A2C 7B80000004         */ IL_0080: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::current /* 04000080 */
		/* 0x00004A31 282C00000A         */ IL_0085: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00004A36 2C16               */ IL_008a: brfalse.s IL_00a2
		/* 0x00004A38 07                 */ IL_008c: ldloc.1
		/* 0x00004A39 06                 */ IL_008d: ldloc.0
		/* 0x00004A3A 725D080070         */ IL_008e: ldstr "Provider.LastAccess" /* 7000085D */
		/* 0x00004A3F 6FDE00000A         */ IL_0093: callvirt instance object [mscorlib]Microsoft.Win32.RegistryKey::GetValue(string) /* 0A0000DE */
		/* 0x00004A44 7545000001         */ IL_0098: isinst [mscorlib]System.String /* 01000045 */
		/* 0x00004A49 7D80000004         */ IL_009d: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::current /* 04000080 */
		/* 0x00004A4E DE0A               */ IL_00a2: leave.s IL_00ae
		/* 0x00004A50 06                 */ IL_00a4: ldloc.0
		/* 0x00004A51 2C06               */ IL_00a5: brfalse.s IL_00ad
		/* 0x00004A53 06                 */ IL_00a7: ldloc.0
		/* 0x00004A54 6F6D00000A         */ IL_00a8: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00004A59 DC                 */ IL_00ad: endfinally
		/* 0x00004A5A 7E49000004         */ IL_00ae: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x00004A5F 7E49000004         */ IL_00b3: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x00004A64 6F9A000006         */ IL_00b8: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004A69 07                 */ IL_00bd: ldloc.1
		/* 0x00004A6A FE06FC000006       */ IL_00be: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass1'::'<TryBaseKey>b__0'(class AspenTech.Visualisation.Controls.Assistant.ProManBrowser) /* 060000FC */
		/* 0x00004A70 73DF00000A         */ IL_00c4: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser, bool>::.ctor(object, native int) /* 0A0000DF */
		/* 0x00004A75 280800002B         */ IL_00c9: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B000008 */
		/* 0x00004A7A 25                 */ IL_00ce: dup
		/* 0x00004A7B 2D10               */ IL_00cf: brtrue.s IL_00e1
		/* 0x00004A7D 26                 */ IL_00d1: pop
		/* 0x00004A7E 7E49000004         */ IL_00d2: ldsfld class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::_global /* 04000049 */
		/* 0x00004A83 6F9A000006         */ IL_00d7: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004A88 280900002B         */ IL_00dc: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000009 */
		/* 0x00004A8D 6F9D000006         */ IL_00e1: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::set_CurrentBrowser(class AspenTech.Visualisation.Controls.Assistant.ProManBrowser) /* 0600009D */
		/* 0x00004A92 2A                 */ IL_00e6: ret

		.try IL_0066-IL_00a4 finally IL_00a4-IL_00ae
	} // end of method ProManBrowsers::TryBaseKey

	.method /* 060000A0 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x4ab0
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00004AB0 02                 */ IL_0000: ldarg.0
		/* 0x00004AB1 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00004AB6 02                 */ IL_0006: ldarg.0
		/* 0x00004AB7 73E100000A         */ IL_0007: newobj instance void class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::.ctor() /* 0A0000E1 */
		/* 0x00004ABC 289B000006         */ IL_000c: call instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::set_Browsers(class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>) /* 0600009B */
		/* 0x00004AC1 2A                 */ IL_0011: ret
	} // end of method ProManBrowsers::.ctor

	.method /* 060000A1 */ private hidebysig 
		instance void AddBrowsers (
			class [mscorlib]Microsoft.Win32.RegistryKey key,
			string path
		) cil managed 
	{
		// Method begins at RVA 0x4ae0
		// Header size: 12
		// Code size: 185 (0xb9)
		.maxstack 6
		.locals /* 11000028 */ init (
			[0] class [mscorlib]Microsoft.Win32.RegistryKey,
			[1] string,
			[2] int32,
			[3] class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser, bool>,
			[4] class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5',
			[5] string[],
			[6] int32
		)

		/* 0x00004AE0 03                 */ IL_0000: ldarg.1
		/* 0x00004AE1 04                 */ IL_0001: ldarg.2
		/* 0x00004AE2 16                 */ IL_0002: ldc.i4.0
		/* 0x00004AE3 6FE200000A         */ IL_0003: callvirt instance class [mscorlib]Microsoft.Win32.RegistryKey [mscorlib]Microsoft.Win32.RegistryKey::OpenSubKey(string, bool) /* 0A0000E2 */
		/* 0x00004AE8 0A                 */ IL_0008: stloc.0
		/* 0x00004AE9 06                 */ IL_0009: ldloc.0
		/* 0x00004AEA 399D000000         */ IL_000a: brfalse IL_00ac
		/* 0x00004AEF 14                 */ IL_000f: ldnull
		/* 0x00004AF0 0D                 */ IL_0010: stloc.3
		/* 0x00004AF1 73FD000006         */ IL_0011: newobj instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5'::.ctor() /* 060000FD */
		/* 0x00004AF6 1304               */ IL_0016: stloc.s 4
		/* 0x00004AF8 06                 */ IL_0018: ldloc.0
		/* 0x00004AF9 6FE300000A         */ IL_0019: callvirt instance string[] [mscorlib]Microsoft.Win32.RegistryKey::GetValueNames() /* 0A0000E3 */
		/* 0x00004AFE 1305               */ IL_001e: stloc.s 5
		/* 0x00004B00 16                 */ IL_0020: ldc.i4.0
		/* 0x00004B01 1306               */ IL_0021: stloc.s 6
		/* 0x00004B03 2B7C               */ IL_0023: br.s IL_00a1
		/* 0x00004B05 1104               */ IL_0025: ldloc.s 4
		/* 0x00004B07 1105               */ IL_0027: ldloc.s 5
		/* 0x00004B09 1106               */ IL_0029: ldloc.s 6
		/* 0x00004B0B 9A                 */ IL_002b: ldelem.ref
		/* 0x00004B0C 7D81000004         */ IL_002c: stfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5'::'value' /* 04000081 */
		/* 0x00004B11 06                 */ IL_0031: ldloc.0
		/* 0x00004B12 1104               */ IL_0032: ldloc.s 4
		/* 0x00004B14 7B81000004         */ IL_0034: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5'::'value' /* 04000081 */
		/* 0x00004B19 6FDE00000A         */ IL_0039: callvirt instance object [mscorlib]Microsoft.Win32.RegistryKey::GetValue(string) /* 0A0000DE */
		/* 0x00004B1E 7545000001         */ IL_003e: isinst [mscorlib]System.String /* 01000045 */
		/* 0x00004B23 0B                 */ IL_0043: stloc.1
		/* 0x00004B24 07                 */ IL_0044: ldloc.1
		/* 0x00004B25 2C54               */ IL_0045: brfalse.s IL_009b
		/* 0x00004B27 07                 */ IL_0047: ldloc.1
		/* 0x00004B28 1F2C               */ IL_0048: ldc.i4.s 44
		/* 0x00004B2A 6F7100000A         */ IL_004a: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x00004B2F 0C                 */ IL_004f: stloc.2
		/* 0x00004B30 08                 */ IL_0050: ldloc.2
		/* 0x00004B31 16                 */ IL_0051: ldc.i4.0
		/* 0x00004B32 3147               */ IL_0052: ble.s IL_009b
		/* 0x00004B34 02                 */ IL_0054: ldarg.0
		/* 0x00004B35 289A000006         */ IL_0055: call instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004B3A 09                 */ IL_005a: ldloc.3
		/* 0x00004B3B 2D0E               */ IL_005b: brtrue.s IL_006b
		/* 0x00004B3D 1104               */ IL_005d: ldloc.s 4
		/* 0x00004B3F FE06FE000006       */ IL_005f: ldftn instance bool AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5'::'<AddBrowsers>b__3'(class AspenTech.Visualisation.Controls.Assistant.ProManBrowser) /* 060000FE */
		/* 0x00004B45 73DF00000A         */ IL_0065: newobj instance void class [mscorlib]System.Func`2<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser, bool>::.ctor(object, native int) /* 0A0000DF */
		/* 0x00004B4A 0D                 */ IL_006a: stloc.3
		/* 0x00004B4B 09                 */ IL_006b: ldloc.3
		/* 0x00004B4C 280A00002B         */ IL_006c: call bool [System.Core]System.Linq.Enumerable::Any<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, bool>) /* 2B00000A */
		/* 0x00004B51 2D28               */ IL_0071: brtrue.s IL_009b
		/* 0x00004B53 02                 */ IL_0073: ldarg.0
		/* 0x00004B54 289A000006         */ IL_0074: call instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004B59 1104               */ IL_0079: ldloc.s 4
		/* 0x00004B5B 7B81000004         */ IL_007b: ldfld string AspenTech.Visualisation.Controls.Assistant.ProManBrowsers/'<>c__DisplayClass5'::'value' /* 04000081 */
		/* 0x00004B60 07                 */ IL_0080: ldloc.1
		/* 0x00004B61 16                 */ IL_0081: ldc.i4.0
		/* 0x00004B62 08                 */ IL_0082: ldloc.2
		/* 0x00004B63 6F7400000A         */ IL_0083: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00004B68 07                 */ IL_0088: ldloc.1
		/* 0x00004B69 08                 */ IL_0089: ldloc.2
		/* 0x00004B6A 17                 */ IL_008a: ldc.i4.1
		/* 0x00004B6B 58                 */ IL_008b: add
		/* 0x00004B6C 6F7200000A         */ IL_008c: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x00004B71 7399000006         */ IL_0091: newobj instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowser::.ctor(string, string, string) /* 06000099 */
		/* 0x00004B76 6FE500000A         */ IL_0096: callvirt instance void class [mscorlib]System.Collections.Generic.ICollection`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::Add(!0) /* 0A0000E5 */
		/* 0x00004B7B 1106               */ IL_009b: ldloc.s 6
		/* 0x00004B7D 17                 */ IL_009d: ldc.i4.1
		/* 0x00004B7E 58                 */ IL_009e: add
		/* 0x00004B7F 1306               */ IL_009f: stloc.s 6
		/* 0x00004B81 1106               */ IL_00a1: ldloc.s 6
		/* 0x00004B83 1105               */ IL_00a3: ldloc.s 5
		/* 0x00004B85 8E                 */ IL_00a5: ldlen
		/* 0x00004B86 69                 */ IL_00a6: conv.i4
		/* 0x00004B87 3F79FFFFFF         */ IL_00a7: blt IL_0025
		/* 0x00004B8C DE0A               */ IL_00ac: leave.s IL_00b8
		/* 0x00004B8E 06                 */ IL_00ae: ldloc.0
		/* 0x00004B8F 2C06               */ IL_00af: brfalse.s IL_00b7
		/* 0x00004B91 06                 */ IL_00b1: ldloc.0
		/* 0x00004B92 6F6D00000A         */ IL_00b2: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00004B97 DC                 */ IL_00b7: endfinally
		/* 0x00004B98 2A                 */ IL_00b8: ret

		.try IL_0009-IL_00ae finally IL_00ae-IL_00b8
	} // end of method ProManBrowsers::AddBrowsers

	// Properties
	.property /* 1700002E */ instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> Browsers()
	{
		.get instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers()
		.set instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::set_Browsers(class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>)
	}
	.property /* 1700002F */ instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser CurrentBrowser()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_CurrentBrowser()
		.set instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::set_CurrentBrowser(class AspenTech.Visualisation.Controls.Assistant.ProManBrowser)
	}
	.property /* 17000030 */ class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers Global()
	{
		.get class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global()
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers

.class /* 0200001A */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.ProManLink
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 0400004C */ private static string[] _actionNames
	.field /* 0400004D */ private static string[] _dataNames

	// Methods
	.method /* 060000A2 */ assembly hidebysig specialname 
		instance bool get_IsCustomisable () cil managed 
	{
		// Method begins at RVA 0x4bb8
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x00004BB8 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004BBD 6F9A000006         */ IL_0005: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004BC2 6FE600000A         */ IL_000a: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Count() /* 0A0000E6 */
		/* 0x00004BC7 17                 */ IL_000f: ldc.i4.1
		/* 0x00004BC8 FE02               */ IL_0010: cgt
		/* 0x00004BCA 2A                 */ IL_0012: ret
	} // end of method ProManLink::get_IsCustomisable

	.method /* 060000A3 */ public hidebysig specialname 
		instance bool get_IsOk () cil managed 
	{
		// Method begins at RVA 0x4bcc
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x00004BCC 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004BD1 6F9A000006         */ IL_0005: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004BD6 6FE600000A         */ IL_000a: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Count() /* 0A0000E6 */
		/* 0x00004BDB 16                 */ IL_000f: ldc.i4.0
		/* 0x00004BDC FE02               */ IL_0010: cgt
		/* 0x00004BDE 2A                 */ IL_0012: ret
	} // end of method ProManLink::get_IsOk

	.method /* 060000A4 */ public hidebysig 
		instance void Action (
			string source,
			string version,
			valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction action,
			string code,
			string data
		) cil managed 
	{
		// Method begins at RVA 0x4be0
		// Header size: 12
		// Code size: 30 (0x1e)
		.maxstack 6
		.locals /* 11000009 */ init (
			[0] string
		)

		/* 0x00004BE0 02                 */ IL_0000: ldarg.0
		/* 0x00004BE1 03                 */ IL_0001: ldarg.1
		/* 0x00004BE2 04                 */ IL_0002: ldarg.2
		/* 0x00004BE3 05                 */ IL_0003: ldarg.3
		/* 0x00004BE4 0E04               */ IL_0004: ldarg.s code
		/* 0x00004BE6 0E05               */ IL_0006: ldarg.s data
		/* 0x00004BE8 28A5000006         */ IL_0008: call instance string AspenTech.Visualisation.Controls.Assistant.ProManLink::GetUrl(string, string, valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction, string, string) /* 060000A5 */
		/* 0x00004BED 0A                 */ IL_000d: stloc.0
		/* 0x00004BEE 06                 */ IL_000e: ldloc.0
		/* 0x00004BEF 282C00000A         */ IL_000f: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00004BF4 2D07               */ IL_0014: brtrue.s IL_001d
		/* 0x00004BF6 06                 */ IL_0016: ldloc.0
		/* 0x00004BF7 28CA00000A         */ IL_0017: call class [System]System.Diagnostics.Process [System]System.Diagnostics.Process::Start(string) /* 0A0000CA */
		/* 0x00004BFC 26                 */ IL_001c: pop
		/* 0x00004BFD 2A                 */ IL_001d: ret
	} // end of method ProManLink::Action

	.method /* 060000A5 */ assembly hidebysig 
		instance string GetUrl (
			string source,
			string version,
			valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction action,
			string code,
			string data
		) cil managed 
	{
		// Method begins at RVA 0x4c0c
		// Header size: 12
		// Code size: 167 (0xa7)
		.maxstack 5
		.locals /* 11000029 */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.ProManBrowser,
			[1] string,
			[2] valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction,
			[3] string[]
		)

		/* 0x00004C0C 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004C11 6F9C000006         */ IL_0005: callvirt instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_CurrentBrowser() /* 0600009C */
		/* 0x00004C16 0A                 */ IL_000a: stloc.0
		/* 0x00004C17 06                 */ IL_000b: ldloc.0
		/* 0x00004C18 3994000000         */ IL_000c: brfalse IL_00a5
		/* 0x00004C1D 05                 */ IL_0011: ldarg.3
		/* 0x00004C1E 0C                 */ IL_0012: stloc.2
		/* 0x00004C1F 08                 */ IL_0013: ldloc.2
		/* 0x00004C20 4508000000         */ IL_0014: switch (
		/*              02000000         */                  IL_003b,
		/*              12000000         */                  IL_004b,
		/*              0A000000         */                  IL_0043,
		/*              3A000000         */                  IL_0073,
		/*              1A000000         */                  IL_0053,
		/*              22000000         */                  IL_005b,
		/*              2A000000         */                  IL_0063,
		/*              32000000         */                  IL_006b)
		/* 0x00004C45 2B38               */ IL_0039: br.s IL_0073
		/* 0x00004C47 7285080070         */ IL_003b: ldstr "TEXT" /* 70000885 */
		/* 0x00004C4C 0B                 */ IL_0040: stloc.1
		/* 0x00004C4D 2B32               */ IL_0041: br.s IL_0075
		/* 0x00004C4F 728F080070         */ IL_0043: ldstr "STRUCTURE" /* 7000088F */
		/* 0x00004C54 0B                 */ IL_0048: stloc.1
		/* 0x00004C55 2B2A               */ IL_0049: br.s IL_0075
		/* 0x00004C57 72A3080070         */ IL_004b: ldstr "SEARCH" /* 700008A3 */
		/* 0x00004C5C 0B                 */ IL_0050: stloc.1
		/* 0x00004C5D 2B22               */ IL_0051: br.s IL_0075
		/* 0x00004C5F 72B1080070         */ IL_0053: ldstr "HOME" /* 700008B1 */
		/* 0x00004C64 0B                 */ IL_0058: stloc.1
		/* 0x00004C65 2B1A               */ IL_0059: br.s IL_0075
		/* 0x00004C67 72BB080070         */ IL_005b: ldstr "LOGIN" /* 700008BB */
		/* 0x00004C6C 0B                 */ IL_0060: stloc.1
		/* 0x00004C6D 2B12               */ IL_0061: br.s IL_0075
		/* 0x00004C6F 72C7080070         */ IL_0063: ldstr "REINDEX" /* 700008C7 */
		/* 0x00004C74 0B                 */ IL_0068: stloc.1
		/* 0x00004C75 2B0A               */ IL_0069: br.s IL_0075
		/* 0x00004C77 72D7080070         */ IL_006b: ldstr "SUPPORT" /* 700008D7 */
		/* 0x00004C7C 0B                 */ IL_0070: stloc.1
		/* 0x00004C7D 2B02               */ IL_0071: br.s IL_0075
		/* 0x00004C7F 14                 */ IL_0073: ldnull
		/* 0x00004C80 2A                 */ IL_0074: ret
		/* 0x00004C81 02                 */ IL_0075: ldarg.0
		/* 0x00004C82 06                 */ IL_0076: ldloc.0
		/* 0x00004C83 6F97000006         */ IL_0077: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Url() /* 06000097 */
		/* 0x00004C88 1C                 */ IL_007c: ldc.i4.6
		/* 0x00004C89 8D45000001         */ IL_007d: newarr [mscorlib]System.String /* 01000045 */
		/* 0x00004C8E 0D                 */ IL_0082: stloc.3
		/* 0x00004C8F 09                 */ IL_0083: ldloc.3
		/* 0x00004C90 16                 */ IL_0084: ldc.i4.0
		/* 0x00004C91 0E04               */ IL_0085: ldarg.s code
		/* 0x00004C93 A2                 */ IL_0087: stelem.ref
		/* 0x00004C94 09                 */ IL_0088: ldloc.3
		/* 0x00004C95 17                 */ IL_0089: ldc.i4.1
		/* 0x00004C96 0E04               */ IL_008a: ldarg.s code
		/* 0x00004C98 A2                 */ IL_008c: stelem.ref
		/* 0x00004C99 09                 */ IL_008d: ldloc.3
		/* 0x00004C9A 18                 */ IL_008e: ldc.i4.2
		/* 0x00004C9B 07                 */ IL_008f: ldloc.1
		/* 0x00004C9C A2                 */ IL_0090: stelem.ref
		/* 0x00004C9D 09                 */ IL_0091: ldloc.3
		/* 0x00004C9E 19                 */ IL_0092: ldc.i4.3
		/* 0x00004C9F 03                 */ IL_0093: ldarg.1
		/* 0x00004CA0 A2                 */ IL_0094: stelem.ref
		/* 0x00004CA1 09                 */ IL_0095: ldloc.3
		/* 0x00004CA2 1A                 */ IL_0096: ldc.i4.4
		/* 0x00004CA3 04                 */ IL_0097: ldarg.2
		/* 0x00004CA4 A2                 */ IL_0098: stelem.ref
		/* 0x00004CA5 09                 */ IL_0099: ldloc.3
		/* 0x00004CA6 1B                 */ IL_009a: ldc.i4.5
		/* 0x00004CA7 0E05               */ IL_009b: ldarg.s data
		/* 0x00004CA9 A2                 */ IL_009d: stelem.ref
		/* 0x00004CAA 09                 */ IL_009e: ldloc.3
		/* 0x00004CAB 28A6000006         */ IL_009f: call instance string AspenTech.Visualisation.Controls.Assistant.ProManLink::Render(string, string[]) /* 060000A6 */
		/* 0x00004CB0 2A                 */ IL_00a4: ret
		/* 0x00004CB1 14                 */ IL_00a5: ldnull
		/* 0x00004CB2 2A                 */ IL_00a6: ret
	} // end of method ProManLink::GetUrl

	.method /* 060000A6 */ private hidebysig 
		instance string Render (
			string format,
			string[] values
		) cil managed 
	{
		.param [2]
			.custom /* 0C000080 */ instance void [mscorlib]System.ParamArrayAttribute::.ctor() = (
				01 00 00 00
			)
		// Method begins at RVA 0x4cc0
		// Header size: 12
		// Code size: 311 (0x137)
		.maxstack 5
		.locals /* 1100002A */ init (
			[0] class [mscorlib]System.Text.StringBuilder,
			[1] int32,
			[2] int32,
			[3] string,
			[4] int32,
			[5] int32,
			[6] int32,
			[7] int32
		)

		/* 0x00004CC0 739200000A         */ IL_0000: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000092 */
		/* 0x00004CC5 0A                 */ IL_0005: stloc.0
		/* 0x00004CC6 03                 */ IL_0006: ldarg.1
		/* 0x00004CC7 282C00000A         */ IL_0007: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x00004CCC 3A14010000         */ IL_000c: brtrue IL_0125
		/* 0x00004CD1 16                 */ IL_0011: ldc.i4.0
		/* 0x00004CD2 0B                 */ IL_0012: stloc.1
		/* 0x00004CD3 3801010000         */ IL_0013: br IL_0119
		/* 0x00004CD8 03                 */ IL_0018: ldarg.1
		/* 0x00004CD9 07                 */ IL_0019: ldloc.1
		/* 0x00004CDA 6F2900000A         */ IL_001a: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00004CDF 1F25               */ IL_001f: ldc.i4.s 37
		/* 0x00004CE1 408A000000         */ IL_0021: bne.un IL_00b0
		/* 0x00004CE6 07                 */ IL_0026: ldloc.1
		/* 0x00004CE7 17                 */ IL_0027: ldc.i4.1
		/* 0x00004CE8 58                 */ IL_0028: add
		/* 0x00004CE9 0B                 */ IL_0029: stloc.1
		/* 0x00004CEA 07                 */ IL_002a: ldloc.1
		/* 0x00004CEB 03                 */ IL_002b: ldarg.1
		/* 0x00004CEC 6F3100000A         */ IL_002c: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00004CF1 2E0B               */ IL_0031: beq.s IL_003e
		/* 0x00004CF3 03                 */ IL_0033: ldarg.1
		/* 0x00004CF4 07                 */ IL_0034: ldloc.1
		/* 0x00004CF5 6F2900000A         */ IL_0035: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00004CFA 1F25               */ IL_003a: ldc.i4.s 37
		/* 0x00004CFC 330E               */ IL_003c: bne.un.s IL_004c
		/* 0x00004CFE 06                 */ IL_003e: ldloc.0
		/* 0x00004CFF 1F25               */ IL_003f: ldc.i4.s 37
		/* 0x00004D01 6FE700000A         */ IL_0041: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(char) /* 0A0000E7 */
		/* 0x00004D06 26                 */ IL_0046: pop
		/* 0x00004D07 38CD000000         */ IL_0047: br IL_0119
		/* 0x00004D0C 03                 */ IL_004c: ldarg.1
		/* 0x00004D0D 1F73               */ IL_004d: ldc.i4.s 115
		/* 0x00004D0F 07                 */ IL_004f: ldloc.1
		/* 0x00004D10 6FE800000A         */ IL_0050: callvirt instance int32 [mscorlib]System.String::IndexOf(char, int32) /* 0A0000E8 */
		/* 0x00004D15 0C                 */ IL_0055: stloc.2
		/* 0x00004D16 08                 */ IL_0056: ldloc.2
		/* 0x00004D17 16                 */ IL_0057: ldc.i4.0
		/* 0x00004D18 2F07               */ IL_0058: bge.s IL_0061
		/* 0x00004D1A 03                 */ IL_005a: ldarg.1
		/* 0x00004D1B 6F3100000A         */ IL_005b: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00004D20 0C                 */ IL_0060: stloc.2
		/* 0x00004D21 03                 */ IL_0061: ldarg.1
		/* 0x00004D22 07                 */ IL_0062: ldloc.1
		/* 0x00004D23 08                 */ IL_0063: ldloc.2
		/* 0x00004D24 07                 */ IL_0064: ldloc.1
		/* 0x00004D25 59                 */ IL_0065: sub
		/* 0x00004D26 6F7400000A         */ IL_0066: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00004D2B 0D                 */ IL_006b: stloc.3
		/* 0x00004D2C 08                 */ IL_006c: ldloc.2
		/* 0x00004D2D 17                 */ IL_006d: ldc.i4.1
		/* 0x00004D2E 58                 */ IL_006e: add
		/* 0x00004D2F 0B                 */ IL_006f: stloc.1
		/* 0x00004D30 09                 */ IL_0070: ldloc.3
		/* 0x00004D31 1F3A               */ IL_0071: ldc.i4.s 58
		/* 0x00004D33 6F7100000A         */ IL_0073: callvirt instance int32 [mscorlib]System.String::IndexOf(char) /* 0A000071 */
		/* 0x00004D38 1304               */ IL_0078: stloc.s 4
		/* 0x00004D3A 09                 */ IL_007a: ldloc.3
		/* 0x00004D3B 16                 */ IL_007b: ldc.i4.0
		/* 0x00004D3C 1104               */ IL_007c: ldloc.s 4
		/* 0x00004D3E 16                 */ IL_007e: ldc.i4.0
		/* 0x00004D3F 3204               */ IL_007f: blt.s IL_0085
		/* 0x00004D41 1104               */ IL_0081: ldloc.s 4
		/* 0x00004D43 2B06               */ IL_0083: br.s IL_008b
		/* 0x00004D45 09                 */ IL_0085: ldloc.3
		/* 0x00004D46 6F3100000A         */ IL_0086: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00004D4B 6F7400000A         */ IL_008b: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00004D50 28E900000A         */ IL_0090: call int32 [System.Xml]System.Xml.XmlConvert::ToInt32(string) /* 0A0000E9 */
		/* 0x00004D55 1305               */ IL_0095: stloc.s 5
		/* 0x00004D57 1105               */ IL_0097: ldloc.s 5
		/* 0x00004D59 16                 */ IL_0099: ldc.i4.0
		/* 0x00004D5A 327D               */ IL_009a: blt.s IL_0119
		/* 0x00004D5C 1105               */ IL_009c: ldloc.s 5
		/* 0x00004D5E 04                 */ IL_009e: ldarg.2
		/* 0x00004D5F 8E                 */ IL_009f: ldlen
		/* 0x00004D60 69                 */ IL_00a0: conv.i4
		/* 0x00004D61 2F76               */ IL_00a1: bge.s IL_0119
		/* 0x00004D63 06                 */ IL_00a3: ldloc.0
		/* 0x00004D64 04                 */ IL_00a4: ldarg.2
		/* 0x00004D65 1105               */ IL_00a5: ldloc.s 5
		/* 0x00004D67 9A                 */ IL_00a7: ldelem.ref
		/* 0x00004D68 6FBD00000A         */ IL_00a8: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A0000BD */
		/* 0x00004D6D 26                 */ IL_00ad: pop
		/* 0x00004D6E 2B69               */ IL_00ae: br.s IL_0119
		/* 0x00004D70 03                 */ IL_00b0: ldarg.1
		/* 0x00004D71 07                 */ IL_00b1: ldloc.1
		/* 0x00004D72 6F2900000A         */ IL_00b2: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00004D77 1F7B               */ IL_00b7: ldc.i4.s 123
		/* 0x00004D79 334C               */ IL_00b9: bne.un.s IL_0107
		/* 0x00004D7B 03                 */ IL_00bb: ldarg.1
		/* 0x00004D7C 1F7D               */ IL_00bc: ldc.i4.s 125
		/* 0x00004D7E 07                 */ IL_00be: ldloc.1
		/* 0x00004D7F 6FE800000A         */ IL_00bf: callvirt instance int32 [mscorlib]System.String::IndexOf(char, int32) /* 0A0000E8 */
		/* 0x00004D84 1306               */ IL_00c4: stloc.s 6
		/* 0x00004D86 1106               */ IL_00c6: ldloc.s 6
		/* 0x00004D88 16                 */ IL_00c8: ldc.i4.0
		/* 0x00004D89 2F08               */ IL_00c9: bge.s IL_00d3
		/* 0x00004D8B 03                 */ IL_00cb: ldarg.1
		/* 0x00004D8C 6F3100000A         */ IL_00cc: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00004D91 1306               */ IL_00d1: stloc.s 6
		/* 0x00004D93 03                 */ IL_00d3: ldarg.1
		/* 0x00004D94 07                 */ IL_00d4: ldloc.1
		/* 0x00004D95 17                 */ IL_00d5: ldc.i4.1
		/* 0x00004D96 58                 */ IL_00d6: add
		/* 0x00004D97 1106               */ IL_00d7: ldloc.s 6
		/* 0x00004D99 07                 */ IL_00d9: ldloc.1
		/* 0x00004D9A 59                 */ IL_00da: sub
		/* 0x00004D9B 17                 */ IL_00db: ldc.i4.1
		/* 0x00004D9C 59                 */ IL_00dc: sub
		/* 0x00004D9D 6F7400000A         */ IL_00dd: callvirt instance string [mscorlib]System.String::Substring(int32, int32) /* 0A000074 */
		/* 0x00004DA2 28E900000A         */ IL_00e2: call int32 [System.Xml]System.Xml.XmlConvert::ToInt32(string) /* 0A0000E9 */
		/* 0x00004DA7 1307               */ IL_00e7: stloc.s 7
		/* 0x00004DA9 1107               */ IL_00e9: ldloc.s 7
		/* 0x00004DAB 16                 */ IL_00eb: ldc.i4.0
		/* 0x00004DAC 3212               */ IL_00ec: blt.s IL_0100
		/* 0x00004DAE 1107               */ IL_00ee: ldloc.s 7
		/* 0x00004DB0 04                 */ IL_00f0: ldarg.2
		/* 0x00004DB1 8E                 */ IL_00f1: ldlen
		/* 0x00004DB2 69                 */ IL_00f2: conv.i4
		/* 0x00004DB3 2F0B               */ IL_00f3: bge.s IL_0100
		/* 0x00004DB5 06                 */ IL_00f5: ldloc.0
		/* 0x00004DB6 04                 */ IL_00f6: ldarg.2
		/* 0x00004DB7 1107               */ IL_00f7: ldloc.s 7
		/* 0x00004DB9 9A                 */ IL_00f9: ldelem.ref
		/* 0x00004DBA 6FBD00000A         */ IL_00fa: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A0000BD */
		/* 0x00004DBF 26                 */ IL_00ff: pop
		/* 0x00004DC0 1106               */ IL_0100: ldloc.s 6
		/* 0x00004DC2 17                 */ IL_0102: ldc.i4.1
		/* 0x00004DC3 58                 */ IL_0103: add
		/* 0x00004DC4 0B                 */ IL_0104: stloc.1
		/* 0x00004DC5 2B12               */ IL_0105: br.s IL_0119
		/* 0x00004DC7 06                 */ IL_0107: ldloc.0
		/* 0x00004DC8 03                 */ IL_0108: ldarg.1
		/* 0x00004DC9 07                 */ IL_0109: ldloc.1
		/* 0x00004DCA 25                 */ IL_010a: dup
		/* 0x00004DCB 17                 */ IL_010b: ldc.i4.1
		/* 0x00004DCC 58                 */ IL_010c: add
		/* 0x00004DCD 0B                 */ IL_010d: stloc.1
		/* 0x00004DCE 6F2900000A         */ IL_010e: callvirt instance char [mscorlib]System.String::get_Chars(int32) /* 0A000029 */
		/* 0x00004DD3 6FE700000A         */ IL_0113: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(char) /* 0A0000E7 */
		/* 0x00004DD8 26                 */ IL_0118: pop
		/* 0x00004DD9 07                 */ IL_0119: ldloc.1
		/* 0x00004DDA 03                 */ IL_011a: ldarg.1
		/* 0x00004DDB 6F3100000A         */ IL_011b: callvirt instance int32 [mscorlib]System.String::get_Length() /* 0A000031 */
		/* 0x00004DE0 3FF3FEFFFF         */ IL_0120: blt IL_0018
		/* 0x00004DE5 06                 */ IL_0125: ldloc.0
		/* 0x00004DE6 6FBF00000A         */ IL_0126: callvirt instance int32 [mscorlib]System.Text.StringBuilder::get_Length() /* 0A0000BF */
		/* 0x00004DEB 16                 */ IL_012b: ldc.i4.0
		/* 0x00004DEC 3002               */ IL_012c: bgt.s IL_0130
		/* 0x00004DEE 14                 */ IL_012e: ldnull
		/* 0x00004DEF 2A                 */ IL_012f: ret
		/* 0x00004DF0 06                 */ IL_0130: ldloc.0
		/* 0x00004DF1 6F6000000A         */ IL_0131: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00004DF6 2A                 */ IL_0136: ret
	} // end of method ProManLink::Render

	.method /* 060000A7 */ public hidebysig 
		instance string Data (
			string source,
			string version,
			valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction action,
			string code,
			string data
		) cil managed 
	{
		// Method begins at RVA 0x4e04
		// Header size: 12
		// Code size: 187 (0xbb)
		.maxstack 5
		.locals /* 1100002B */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.ProManBrowser,
			[1] string,
			[2] class [System]System.Net.WebRequest,
			[3] class [System]System.Net.WebResponse,
			[4] class [mscorlib]System.IO.StreamReader,
			[5] string,
			[6] valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction,
			[7] string[]
		)

		/* 0x00004E04 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004E09 6F9C000006         */ IL_0005: callvirt instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_CurrentBrowser() /* 0600009C */
		/* 0x00004E0E 0A                 */ IL_000a: stloc.0
		/* 0x00004E0F 06                 */ IL_000b: ldloc.0
		/* 0x00004E10 39A5000000         */ IL_000c: brfalse IL_00b6
		/* 0x00004E15 05                 */ IL_0011: ldarg.3
		/* 0x00004E16 1306               */ IL_0012: stloc.s 6
		/* 0x00004E18 1106               */ IL_0014: ldloc.s 6
		/* 0x00004E1A 18                 */ IL_0016: ldc.i4.2
		/* 0x00004E1B 59                 */ IL_0017: sub
		/* 0x00004E1C 4502000000         */ IL_0018: switch (
		/*              0A000000         */                  IL_002f,
		/*              02000000         */                  IL_0027)
		/* 0x00004E29 2B10               */ IL_0025: br.s IL_0037
		/* 0x00004E2B 72E7080070         */ IL_0027: ldstr "CONTENTDATA" /* 700008E7 */
		/* 0x00004E30 0B                 */ IL_002c: stloc.1
		/* 0x00004E31 2B0A               */ IL_002d: br.s IL_0039
		/* 0x00004E33 72FF080070         */ IL_002f: ldstr "STRUCTUREDATA" /* 700008FF */
		/* 0x00004E38 0B                 */ IL_0034: stloc.1
		/* 0x00004E39 2B02               */ IL_0035: br.s IL_0039
		/* 0x00004E3B 14                 */ IL_0037: ldnull
		/* 0x00004E3C 2A                 */ IL_0038: ret
		/* 0x00004E3D 02                 */ IL_0039: ldarg.0
		/* 0x00004E3E 06                 */ IL_003a: ldloc.0
		/* 0x00004E3F 6F97000006         */ IL_003b: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Url() /* 06000097 */
		/* 0x00004E44 1C                 */ IL_0040: ldc.i4.6
		/* 0x00004E45 8D45000001         */ IL_0041: newarr [mscorlib]System.String /* 01000045 */
		/* 0x00004E4A 1307               */ IL_0046: stloc.s 7
		/* 0x00004E4C 1107               */ IL_0048: ldloc.s 7
		/* 0x00004E4E 16                 */ IL_004a: ldc.i4.0
		/* 0x00004E4F 0E04               */ IL_004b: ldarg.s code
		/* 0x00004E51 A2                 */ IL_004d: stelem.ref
		/* 0x00004E52 1107               */ IL_004e: ldloc.s 7
		/* 0x00004E54 17                 */ IL_0050: ldc.i4.1
		/* 0x00004E55 0E04               */ IL_0051: ldarg.s code
		/* 0x00004E57 A2                 */ IL_0053: stelem.ref
		/* 0x00004E58 1107               */ IL_0054: ldloc.s 7
		/* 0x00004E5A 18                 */ IL_0056: ldc.i4.2
		/* 0x00004E5B 07                 */ IL_0057: ldloc.1
		/* 0x00004E5C A2                 */ IL_0058: stelem.ref
		/* 0x00004E5D 1107               */ IL_0059: ldloc.s 7
		/* 0x00004E5F 19                 */ IL_005b: ldc.i4.3
		/* 0x00004E60 03                 */ IL_005c: ldarg.1
		/* 0x00004E61 A2                 */ IL_005d: stelem.ref
		/* 0x00004E62 1107               */ IL_005e: ldloc.s 7
		/* 0x00004E64 1A                 */ IL_0060: ldc.i4.4
		/* 0x00004E65 04                 */ IL_0061: ldarg.2
		/* 0x00004E66 A2                 */ IL_0062: stelem.ref
		/* 0x00004E67 1107               */ IL_0063: ldloc.s 7
		/* 0x00004E69 1B                 */ IL_0065: ldc.i4.5
		/* 0x00004E6A 0E05               */ IL_0066: ldarg.s data
		/* 0x00004E6C A2                 */ IL_0068: stelem.ref
		/* 0x00004E6D 1107               */ IL_0069: ldloc.s 7
		/* 0x00004E6F 28A6000006         */ IL_006b: call instance string AspenTech.Visualisation.Controls.Assistant.ProManLink::Render(string, string[]) /* 060000A6 */
		/* 0x00004E74 28EA00000A         */ IL_0070: call class [System]System.Net.WebRequest [System]System.Net.WebRequest::Create(string) /* 0A0000EA */
		/* 0x00004E79 0C                 */ IL_0075: stloc.2
		/* 0x00004E7A 08                 */ IL_0076: ldloc.2
		/* 0x00004E7B 28EB00000A         */ IL_0077: call class [System]System.Net.ICredentials [System]System.Net.CredentialCache::get_DefaultCredentials() /* 0A0000EB */
		/* 0x00004E80 6FEC00000A         */ IL_007c: callvirt instance void [System]System.Net.WebRequest::set_Credentials(class [System]System.Net.ICredentials) /* 0A0000EC */
		/* 0x00004E85 08                 */ IL_0081: ldloc.2
		/* 0x00004E86 6FED00000A         */ IL_0082: callvirt instance class [System]System.Net.WebResponse [System]System.Net.WebRequest::GetResponse() /* 0A0000ED */
		/* 0x00004E8B 0D                 */ IL_0087: stloc.3
		/* 0x00004E8C 09                 */ IL_0088: ldloc.3
		/* 0x00004E8D 6FEE00000A         */ IL_0089: callvirt instance class [mscorlib]System.IO.Stream [System]System.Net.WebResponse::GetResponseStream() /* 0A0000EE */
		/* 0x00004E92 73EF00000A         */ IL_008e: newobj instance void [mscorlib]System.IO.StreamReader::.ctor(class [mscorlib]System.IO.Stream) /* 0A0000EF */
		/* 0x00004E97 1304               */ IL_0093: stloc.s 4
		/* 0x00004E99 1104               */ IL_0095: ldloc.s 4
		/* 0x00004E9B 6FF000000A         */ IL_0097: callvirt instance string [mscorlib]System.IO.TextReader::ReadToEnd() /* 0A0000F0 */
		/* 0x00004EA0 1305               */ IL_009c: stloc.s 5
		/* 0x00004EA2 DE18               */ IL_009e: leave.s IL_00b8
		/* 0x00004EA4 1104               */ IL_00a0: ldloc.s 4
		/* 0x00004EA6 2C07               */ IL_00a2: brfalse.s IL_00ab
		/* 0x00004EA8 1104               */ IL_00a4: ldloc.s 4
		/* 0x00004EAA 6F6D00000A         */ IL_00a6: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00004EAF DC                 */ IL_00ab: endfinally
		/* 0x00004EB0 09                 */ IL_00ac: ldloc.3
		/* 0x00004EB1 2C06               */ IL_00ad: brfalse.s IL_00b5
		/* 0x00004EB3 09                 */ IL_00af: ldloc.3
		/* 0x00004EB4 6F6D00000A         */ IL_00b0: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00004EB9 DC                 */ IL_00b5: endfinally
		/* 0x00004EBA 14                 */ IL_00b6: ldnull
		/* 0x00004EBB 2A                 */ IL_00b7: ret
		/* 0x00004EBC 1105               */ IL_00b8: ldloc.s 5
		/* 0x00004EBE 2A                 */ IL_00ba: ret

		.try IL_0095-IL_00a0 finally IL_00a0-IL_00ac
		.try IL_0088-IL_00ac finally IL_00ac-IL_00b6
	} // end of method ProManLink::Data

	.method /* 060000A8 */ assembly hidebysig 
		instance string ActionToString (
			valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction action
		) cil managed 
	{
		// Method begins at RVA 0x4ee8
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00004EE8 03                 */ IL_0000: ldarg.1
		/* 0x00004EE9 8C17000002         */ IL_0001: box AspenTech.Visualisation.Controls.Assistant.ProManAction /* 02000017 */
		/* 0x00004EEE 6F6000000A         */ IL_0006: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00004EF3 2A                 */ IL_000b: ret
	} // end of method ProManLink::ActionToString

	.method /* 060000A9 */ assembly hidebysig 
		instance valuetype AspenTech.Visualisation.Controls.Assistant.ProManAction StringToAction (
			string action
		) cil managed 
	{
		// Method begins at RVA 0x4ef5
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x00004EF5 D017000002         */ IL_0000: ldtoken AspenTech.Visualisation.Controls.Assistant.ProManAction /* 02000017 */
		/* 0x00004EFA 284A00000A         */ IL_0005: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00004A */
		/* 0x00004EFF 03                 */ IL_000a: ldarg.1
		/* 0x00004F00 17                 */ IL_000b: ldc.i4.1
		/* 0x00004F01 28D600000A         */ IL_000c: call object [mscorlib]System.Enum::Parse(class [mscorlib]System.Type, string, bool) /* 0A0000D6 */
		/* 0x00004F06 A517000002         */ IL_0011: unbox.any AspenTech.Visualisation.Controls.Assistant.ProManAction /* 02000017 */
		/* 0x00004F0B 2A                 */ IL_0016: ret
	} // end of method ProManLink::StringToAction

	.method /* 060000AA */ public hidebysig specialname 
		instance int32 get_ProviderCount () cil managed 
	{
		// Method begins at RVA 0x4f0d
		// Header size: 1
		// Code size: 16 (0x10)
		.maxstack 8

		/* 0x00004F0D 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F12 6F9A000006         */ IL_0005: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004F17 6FE600000A         */ IL_000a: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Count() /* 0A0000E6 */
		/* 0x00004F1C 2A                 */ IL_000f: ret
	} // end of method ProManLink::get_ProviderCount

	.method /* 060000AB */ public hidebysig 
		instance string ProviderTitle (
			int32 index
		) cil managed 
	{
		// Method begins at RVA 0x4f1e
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x00004F1E 03                 */ IL_0000: ldarg.1
		/* 0x00004F1F 16                 */ IL_0001: ldc.i4.0
		/* 0x00004F20 3212               */ IL_0002: blt.s IL_0016
		/* 0x00004F22 03                 */ IL_0004: ldarg.1
		/* 0x00004F23 289E000006         */ IL_0005: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F28 6F9A000006         */ IL_000a: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004F2D 6FE600000A         */ IL_000f: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Count() /* 0A0000E6 */
		/* 0x00004F32 3202               */ IL_0014: blt.s IL_0018
		/* 0x00004F34 14                 */ IL_0016: ldnull
		/* 0x00004F35 2A                 */ IL_0017: ret
		/* 0x00004F36 289E000006         */ IL_0018: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F3B 6F9A000006         */ IL_001d: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004F40 03                 */ IL_0022: ldarg.1
		/* 0x00004F41 6FF100000A         */ IL_0023: callvirt instance !0 class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Item(int32) /* 0A0000F1 */
		/* 0x00004F46 6F93000006         */ IL_0028: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Title() /* 06000093 */
		/* 0x00004F4B 2A                 */ IL_002d: ret
	} // end of method ProManLink::ProviderTitle

	.method /* 060000AC */ public hidebysig 
		instance string ProviderId (
			int32 index
		) cil managed 
	{
		// Method begins at RVA 0x4f4d
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x00004F4D 03                 */ IL_0000: ldarg.1
		/* 0x00004F4E 16                 */ IL_0001: ldc.i4.0
		/* 0x00004F4F 3212               */ IL_0002: blt.s IL_0016
		/* 0x00004F51 03                 */ IL_0004: ldarg.1
		/* 0x00004F52 289E000006         */ IL_0005: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F57 6F9A000006         */ IL_000a: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004F5C 6FE600000A         */ IL_000f: callvirt instance int32 class [mscorlib]System.Collections.Generic.ICollection`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Count() /* 0A0000E6 */
		/* 0x00004F61 3202               */ IL_0014: blt.s IL_0018
		/* 0x00004F63 14                 */ IL_0016: ldnull
		/* 0x00004F64 2A                 */ IL_0017: ret
		/* 0x00004F65 289E000006         */ IL_0018: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F6A 6F9A000006         */ IL_001d: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004F6F 03                 */ IL_0022: ldarg.1
		/* 0x00004F70 6FF100000A         */ IL_0023: callvirt instance !0 class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Item(int32) /* 0A0000F1 */
		/* 0x00004F75 6F95000006         */ IL_0028: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Name() /* 06000095 */
		/* 0x00004F7A 2A                 */ IL_002d: ret
	} // end of method ProManLink::ProviderId

	.method /* 060000AD */ public hidebysig specialname 
		instance string get_ProviderActive () cil managed 
	{
		// Method begins at RVA 0x4f7c
		// Header size: 1
		// Code size: 30 (0x1e)
		.maxstack 8

		/* 0x00004F7C 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F81 6F9C000006         */ IL_0005: callvirt instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_CurrentBrowser() /* 0600009C */
		/* 0x00004F86 2C10               */ IL_000a: brfalse.s IL_001c
		/* 0x00004F88 289E000006         */ IL_000c: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004F8D 6F9C000006         */ IL_0011: callvirt instance class AspenTech.Visualisation.Controls.Assistant.ProManBrowser AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_CurrentBrowser() /* 0600009C */
		/* 0x00004F92 6F95000006         */ IL_0016: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Name() /* 06000095 */
		/* 0x00004F97 2A                 */ IL_001b: ret
		/* 0x00004F98 14                 */ IL_001c: ldnull
		/* 0x00004F99 2A                 */ IL_001d: ret
	} // end of method ProManLink::get_ProviderActive

	.method /* 060000AE */ public hidebysig specialname 
		instance void set_ProviderActive (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x4f9c
		// Header size: 12
		// Code size: 71 (0x47)
		.maxstack 2
		.locals /* 1100002C */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.ProManBrowser,
			[1] class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>
		)

		/* 0x00004F9C 289E000006         */ IL_0000: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004FA1 6F9A000006         */ IL_0005: callvirt instance class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser> AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Browsers() /* 0600009A */
		/* 0x00004FA6 6FF200000A         */ IL_000a: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::GetEnumerator() /* 0A0000F2 */
		/* 0x00004FAB 0B                 */ IL_000f: stloc.1
		/* 0x00004FAC 2B20               */ IL_0010: br.s IL_0032
		/* 0x00004FAE 07                 */ IL_0012: ldloc.1
		/* 0x00004FAF 6FF300000A         */ IL_0013: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.Visualisation.Controls.Assistant.ProManBrowser>::get_Current() /* 0A0000F3 */
		/* 0x00004FB4 0A                 */ IL_0018: stloc.0
		/* 0x00004FB5 06                 */ IL_0019: ldloc.0
		/* 0x00004FB6 6F95000006         */ IL_001a: callvirt instance string AspenTech.Visualisation.Controls.Assistant.ProManBrowser::get_Name() /* 06000095 */
		/* 0x00004FBB 03                 */ IL_001f: ldarg.1
		/* 0x00004FBC 283F00000A         */ IL_0020: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
		/* 0x00004FC1 2C0B               */ IL_0025: brfalse.s IL_0032
		/* 0x00004FC3 289E000006         */ IL_0027: call class AspenTech.Visualisation.Controls.Assistant.ProManBrowsers AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::get_Global() /* 0600009E */
		/* 0x00004FC8 06                 */ IL_002c: ldloc.0
		/* 0x00004FC9 6F9D000006         */ IL_002d: callvirt instance void AspenTech.Visualisation.Controls.Assistant.ProManBrowsers::set_CurrentBrowser(class AspenTech.Visualisation.Controls.Assistant.ProManBrowser) /* 0600009D */
		/* 0x00004FCE 07                 */ IL_0032: ldloc.1
		/* 0x00004FCF 6F7700000A         */ IL_0033: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x00004FD4 2DD8               */ IL_0038: brtrue.s IL_0012
		/* 0x00004FD6 DE0A               */ IL_003a: leave.s IL_0046
		/* 0x00004FD8 07                 */ IL_003c: ldloc.1
		/* 0x00004FD9 2C06               */ IL_003d: brfalse.s IL_0045
		/* 0x00004FDB 07                 */ IL_003f: ldloc.1
		/* 0x00004FDC 6F6D00000A         */ IL_0040: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x00004FE1 DC                 */ IL_0045: endfinally
		/* 0x00004FE2 2A                 */ IL_0046: ret

		.try IL_0010-IL_003c finally IL_003c-IL_0046
	} // end of method ProManLink::set_ProviderActive

	.method /* 060000AF */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x5090
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00005090 02                 */ IL_0000: ldarg.0
		/* 0x00005091 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00005096 2A                 */ IL_0006: ret
	} // end of method ProManLink::.ctor

	.method /* 060000B0 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x5000
		// Header size: 12
		// Code size: 132 (0x84)
		.maxstack 3
		.locals /* 1100002D */ init (
			[0] string[],
			[1] string[]
		)

		/* 0x00005000 1F09               */ IL_0000: ldc.i4.s 9
		/* 0x00005002 8D45000001         */ IL_0002: newarr [mscorlib]System.String /* 01000045 */
		/* 0x00005007 0A                 */ IL_0007: stloc.0
		/* 0x00005008 06                 */ IL_0008: ldloc.0
		/* 0x00005009 16                 */ IL_0009: ldc.i4.0
		/* 0x0000500A 721B090070         */ IL_000a: ldstr "None" /* 7000091B */
		/* 0x0000500F A2                 */ IL_000f: stelem.ref
		/* 0x00005010 06                 */ IL_0010: ldloc.0
		/* 0x00005011 17                 */ IL_0011: ldc.i4.1
		/* 0x00005012 72EC050070         */ IL_0012: ldstr "Text" /* 700005EC */
		/* 0x00005017 A2                 */ IL_0017: stelem.ref
		/* 0x00005018 06                 */ IL_0018: ldloc.0
		/* 0x00005019 18                 */ IL_0019: ldc.i4.2
		/* 0x0000501A 7225090070         */ IL_001a: ldstr "Structure" /* 70000925 */
		/* 0x0000501F A2                 */ IL_001f: stelem.ref
		/* 0x00005020 06                 */ IL_0020: ldloc.0
		/* 0x00005021 19                 */ IL_0021: ldc.i4.3
		/* 0x00005022 7239090070         */ IL_0022: ldstr "Search" /* 70000939 */
		/* 0x00005027 A2                 */ IL_0027: stelem.ref
		/* 0x00005028 06                 */ IL_0028: ldloc.0
		/* 0x00005029 1A                 */ IL_0029: ldc.i4.4
		/* 0x0000502A 7247090070         */ IL_002a: ldstr "Topic" /* 70000947 */
		/* 0x0000502F A2                 */ IL_002f: stelem.ref
		/* 0x00005030 06                 */ IL_0030: ldloc.0
		/* 0x00005031 1B                 */ IL_0031: ldc.i4.5
		/* 0x00005032 7253090070         */ IL_0032: ldstr "Home" /* 70000953 */
		/* 0x00005037 A2                 */ IL_0037: stelem.ref
		/* 0x00005038 06                 */ IL_0038: ldloc.0
		/* 0x00005039 1C                 */ IL_0039: ldc.i4.6
		/* 0x0000503A 725D090070         */ IL_003a: ldstr "Login" /* 7000095D */
		/* 0x0000503F A2                 */ IL_003f: stelem.ref
		/* 0x00005040 06                 */ IL_0040: ldloc.0
		/* 0x00005041 1D                 */ IL_0041: ldc.i4.7
		/* 0x00005042 7269090070         */ IL_0042: ldstr "ReIndex" /* 70000969 */
		/* 0x00005047 A2                 */ IL_0047: stelem.ref
		/* 0x00005048 06                 */ IL_0048: ldloc.0
		/* 0x00005049 1E                 */ IL_0049: ldc.i4.8
		/* 0x0000504A 7279090070         */ IL_004a: ldstr "Support" /* 70000979 */
		/* 0x0000504F A2                 */ IL_004f: stelem.ref
		/* 0x00005050 06                 */ IL_0050: ldloc.0
		/* 0x00005051 804C000004         */ IL_0051: stsfld string[] AspenTech.Visualisation.Controls.Assistant.ProManLink::_actionNames /* 0400004C */
		/* 0x00005056 1A                 */ IL_0056: ldc.i4.4
		/* 0x00005057 8D45000001         */ IL_0057: newarr [mscorlib]System.String /* 01000045 */
		/* 0x0000505C 0B                 */ IL_005c: stloc.1
		/* 0x0000505D 07                 */ IL_005d: ldloc.1
		/* 0x0000505E 16                 */ IL_005e: ldc.i4.0
		/* 0x0000505F 721B090070         */ IL_005f: ldstr "None" /* 7000091B */
		/* 0x00005064 A2                 */ IL_0064: stelem.ref
		/* 0x00005065 07                 */ IL_0065: ldloc.1
		/* 0x00005066 17                 */ IL_0066: ldc.i4.1
		/* 0x00005067 7247090070         */ IL_0067: ldstr "Topic" /* 70000947 */
		/* 0x0000506C A2                 */ IL_006c: stelem.ref
		/* 0x0000506D 07                 */ IL_006d: ldloc.1
		/* 0x0000506E 18                 */ IL_006e: ldc.i4.2
		/* 0x0000506F 7225090070         */ IL_006f: ldstr "Structure" /* 70000925 */
		/* 0x00005074 A2                 */ IL_0074: stelem.ref
		/* 0x00005075 07                 */ IL_0075: ldloc.1
		/* 0x00005076 19                 */ IL_0076: ldc.i4.3
		/* 0x00005077 7289090070         */ IL_0077: ldstr "Content" /* 70000989 */
		/* 0x0000507C A2                 */ IL_007c: stelem.ref
		/* 0x0000507D 07                 */ IL_007d: ldloc.1
		/* 0x0000507E 804D000004         */ IL_007e: stsfld string[] AspenTech.Visualisation.Controls.Assistant.ProManLink::_dataNames /* 0400004D */
		/* 0x00005083 2A                 */ IL_0083: ret
	} // end of method ProManLink::.cctor

	// Properties
	.property /* 17000031 */ instance bool IsCustomisable()
	{
		.get instance bool AspenTech.Visualisation.Controls.Assistant.ProManLink::get_IsCustomisable()
	}
	.property /* 17000032 */ instance bool IsOk()
	{
		.get instance bool AspenTech.Visualisation.Controls.Assistant.ProManLink::get_IsOk()
	}
	.property /* 17000033 */ instance int32 ProviderCount()
	{
		.get instance int32 AspenTech.Visualisation.Controls.Assistant.ProManLink::get_ProviderCount()
	}
	.property /* 17000034 */ instance string ProviderActive()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.ProManLink::get_ProviderActive()
		.set instance void AspenTech.Visualisation.Controls.Assistant.ProManLink::set_ProviderActive(string)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.ProManLink

.class /* 0200001B */ private auto ansi abstract sealed beforefieldinit AspenTech.Visualisation.Controls.Assistant.Extensions
	extends [mscorlib]System.Object
{
	.custom /* 0C000025 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 060000B1 */ assembly hidebysig static 
		string Value (
			class [System.Xml.Linq]System.Xml.Linq.XAttribute attribute,
			string defaultValue
		) cil managed 
	{
		.custom /* 0C00008D */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5098
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00005098 02                 */ IL_0000: ldarg.0
		/* 0x00005099 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x0000509B 03                 */ IL_0003: ldarg.1
		/* 0x0000509C 2A                 */ IL_0004: ret
		/* 0x0000509D 02                 */ IL_0005: ldarg.0
		/* 0x0000509E 6FA200000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XAttribute::get_Value() /* 0A0000A2 */
		/* 0x000050A3 2A                 */ IL_000b: ret
	} // end of method Extensions::Value

	.method /* 060000B2 */ assembly hidebysig static 
		int32 Value (
			class [System.Xml.Linq]System.Xml.Linq.XAttribute attribute,
			int32 defaultValue
		) cil managed 
	{
		.custom /* 0C00008E */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x50a8
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 1100002E */ init (
			[0] int32
		)

		/* 0x000050A8 02                 */ IL_0000: ldarg.0
		/* 0x000050A9 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x000050AB 03                 */ IL_0003: ldarg.1
		/* 0x000050AC 2A                 */ IL_0004: ret
		/* 0x000050AD 02                 */ IL_0005: ldarg.0
		/* 0x000050AE 6FA200000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XAttribute::get_Value() /* 0A0000A2 */
		/* 0x000050B3 28E900000A         */ IL_000b: call int32 [System.Xml]System.Xml.XmlConvert::ToInt32(string) /* 0A0000E9 */
		/* 0x000050B8 0A                 */ IL_0010: stloc.0
		/* 0x000050B9 DE05               */ IL_0011: leave.s IL_0018
		/* 0x000050BB 26                 */ IL_0013: pop
		/* 0x000050BC 03                 */ IL_0014: ldarg.1
		/* 0x000050BD 0A                 */ IL_0015: stloc.0
		/* 0x000050BE DE00               */ IL_0016: leave.s IL_0018
		/* 0x000050C0 06                 */ IL_0018: ldloc.0
		/* 0x000050C1 2A                 */ IL_0019: ret

		.try IL_0005-IL_0013 catch [mscorlib]System.Object IL_0013-IL_0018
	} // end of method Extensions::Value

	.method /* 060000B3 */ assembly hidebysig static 
		int64 Value (
			class [System.Xml.Linq]System.Xml.Linq.XAttribute attribute,
			int64 defaultValue
		) cil managed 
	{
		.custom /* 0C00008F */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x50e0
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 1100002F */ init (
			[0] int64
		)

		/* 0x000050E0 02                 */ IL_0000: ldarg.0
		/* 0x000050E1 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x000050E3 03                 */ IL_0003: ldarg.1
		/* 0x000050E4 2A                 */ IL_0004: ret
		/* 0x000050E5 02                 */ IL_0005: ldarg.0
		/* 0x000050E6 6FA200000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XAttribute::get_Value() /* 0A0000A2 */
		/* 0x000050EB 28F400000A         */ IL_000b: call int64 [System.Xml]System.Xml.XmlConvert::ToInt64(string) /* 0A0000F4 */
		/* 0x000050F0 0A                 */ IL_0010: stloc.0
		/* 0x000050F1 DE05               */ IL_0011: leave.s IL_0018
		/* 0x000050F3 26                 */ IL_0013: pop
		/* 0x000050F4 03                 */ IL_0014: ldarg.1
		/* 0x000050F5 0A                 */ IL_0015: stloc.0
		/* 0x000050F6 DE00               */ IL_0016: leave.s IL_0018
		/* 0x000050F8 06                 */ IL_0018: ldloc.0
		/* 0x000050F9 2A                 */ IL_0019: ret

		.try IL_0005-IL_0013 catch [mscorlib]System.Object IL_0013-IL_0018
	} // end of method Extensions::Value

	.method /* 060000B4 */ assembly hidebysig static 
		valuetype [mscorlib]System.Guid Value (
			class [System.Xml.Linq]System.Xml.Linq.XAttribute attribute,
			valuetype [mscorlib]System.Guid defaultValue
		) cil managed 
	{
		.custom /* 0C000090 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5118
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 1100000F */ init (
			[0] valuetype [mscorlib]System.Guid
		)

		/* 0x00005118 02                 */ IL_0000: ldarg.0
		/* 0x00005119 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x0000511B 03                 */ IL_0003: ldarg.1
		/* 0x0000511C 2A                 */ IL_0004: ret
		/* 0x0000511D 02                 */ IL_0005: ldarg.0
		/* 0x0000511E 6FA200000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XAttribute::get_Value() /* 0A0000A2 */
		/* 0x00005123 28F500000A         */ IL_000b: call valuetype [mscorlib]System.Guid [System.Xml]System.Xml.XmlConvert::ToGuid(string) /* 0A0000F5 */
		/* 0x00005128 0A                 */ IL_0010: stloc.0
		/* 0x00005129 DE05               */ IL_0011: leave.s IL_0018
		/* 0x0000512B 26                 */ IL_0013: pop
		/* 0x0000512C 03                 */ IL_0014: ldarg.1
		/* 0x0000512D 0A                 */ IL_0015: stloc.0
		/* 0x0000512E DE00               */ IL_0016: leave.s IL_0018
		/* 0x00005130 06                 */ IL_0018: ldloc.0
		/* 0x00005131 2A                 */ IL_0019: ret

		.try IL_0005-IL_0013 catch [mscorlib]System.Object IL_0013-IL_0018
	} // end of method Extensions::Value

	.method /* 060000B5 */ assembly hidebysig static 
		string Value (
			class [System.Xml.Linq]System.Xml.Linq.XElement element,
			string defaultValue
		) cil managed 
	{
		.custom /* 0C000091 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5150
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00005150 02                 */ IL_0000: ldarg.0
		/* 0x00005151 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x00005153 03                 */ IL_0003: ldarg.1
		/* 0x00005154 2A                 */ IL_0004: ret
		/* 0x00005155 02                 */ IL_0005: ldarg.0
		/* 0x00005156 6F7E00000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XElement::get_Value() /* 0A00007E */
		/* 0x0000515B 2A                 */ IL_000b: ret
	} // end of method Extensions::Value

	.method /* 060000B6 */ assembly hidebysig static 
		int32 Value (
			class [System.Xml.Linq]System.Xml.Linq.XElement element,
			int32 defaultValue
		) cil managed 
	{
		.custom /* 0C000092 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5160
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 1100002E */ init (
			[0] int32
		)

		/* 0x00005160 02                 */ IL_0000: ldarg.0
		/* 0x00005161 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x00005163 03                 */ IL_0003: ldarg.1
		/* 0x00005164 2A                 */ IL_0004: ret
		/* 0x00005165 02                 */ IL_0005: ldarg.0
		/* 0x00005166 6F7E00000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XElement::get_Value() /* 0A00007E */
		/* 0x0000516B 28E900000A         */ IL_000b: call int32 [System.Xml]System.Xml.XmlConvert::ToInt32(string) /* 0A0000E9 */
		/* 0x00005170 0A                 */ IL_0010: stloc.0
		/* 0x00005171 DE05               */ IL_0011: leave.s IL_0018
		/* 0x00005173 26                 */ IL_0013: pop
		/* 0x00005174 03                 */ IL_0014: ldarg.1
		/* 0x00005175 0A                 */ IL_0015: stloc.0
		/* 0x00005176 DE00               */ IL_0016: leave.s IL_0018
		/* 0x00005178 06                 */ IL_0018: ldloc.0
		/* 0x00005179 2A                 */ IL_0019: ret

		.try IL_0005-IL_0013 catch [mscorlib]System.Object IL_0013-IL_0018
	} // end of method Extensions::Value

	.method /* 060000B7 */ assembly hidebysig static 
		int64 Value (
			class [System.Xml.Linq]System.Xml.Linq.XElement element,
			int64 defaultValue
		) cil managed 
	{
		.custom /* 0C000093 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5198
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 1100002F */ init (
			[0] int64
		)

		/* 0x00005198 02                 */ IL_0000: ldarg.0
		/* 0x00005199 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x0000519B 03                 */ IL_0003: ldarg.1
		/* 0x0000519C 2A                 */ IL_0004: ret
		/* 0x0000519D 02                 */ IL_0005: ldarg.0
		/* 0x0000519E 6F7E00000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XElement::get_Value() /* 0A00007E */
		/* 0x000051A3 28F400000A         */ IL_000b: call int64 [System.Xml]System.Xml.XmlConvert::ToInt64(string) /* 0A0000F4 */
		/* 0x000051A8 0A                 */ IL_0010: stloc.0
		/* 0x000051A9 DE05               */ IL_0011: leave.s IL_0018
		/* 0x000051AB 26                 */ IL_0013: pop
		/* 0x000051AC 03                 */ IL_0014: ldarg.1
		/* 0x000051AD 0A                 */ IL_0015: stloc.0
		/* 0x000051AE DE00               */ IL_0016: leave.s IL_0018
		/* 0x000051B0 06                 */ IL_0018: ldloc.0
		/* 0x000051B1 2A                 */ IL_0019: ret

		.try IL_0005-IL_0013 catch [mscorlib]System.Object IL_0013-IL_0018
	} // end of method Extensions::Value

	.method /* 060000B8 */ assembly hidebysig static 
		valuetype [mscorlib]System.Guid Value (
			class [System.Xml.Linq]System.Xml.Linq.XElement element,
			valuetype [mscorlib]System.Guid defaultValue
		) cil managed 
	{
		.custom /* 0C000094 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x51d0
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 1100000F */ init (
			[0] valuetype [mscorlib]System.Guid
		)

		/* 0x000051D0 02                 */ IL_0000: ldarg.0
		/* 0x000051D1 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x000051D3 03                 */ IL_0003: ldarg.1
		/* 0x000051D4 2A                 */ IL_0004: ret
		/* 0x000051D5 02                 */ IL_0005: ldarg.0
		/* 0x000051D6 6F7E00000A         */ IL_0006: callvirt instance string [System.Xml.Linq]System.Xml.Linq.XElement::get_Value() /* 0A00007E */
		/* 0x000051DB 28F500000A         */ IL_000b: call valuetype [mscorlib]System.Guid [System.Xml]System.Xml.XmlConvert::ToGuid(string) /* 0A0000F5 */
		/* 0x000051E0 0A                 */ IL_0010: stloc.0
		/* 0x000051E1 DE05               */ IL_0011: leave.s IL_0018
		/* 0x000051E3 26                 */ IL_0013: pop
		/* 0x000051E4 03                 */ IL_0014: ldarg.1
		/* 0x000051E5 0A                 */ IL_0015: stloc.0
		/* 0x000051E6 DE00               */ IL_0016: leave.s IL_0018
		/* 0x000051E8 06                 */ IL_0018: ldloc.0
		/* 0x000051E9 2A                 */ IL_0019: ret

		.try IL_0005-IL_0013 catch [mscorlib]System.Object IL_0013-IL_0018
	} // end of method Extensions::Value

	.method /* 060000B9 */ assembly hidebysig static 
		class [System.Web]System.Web.UI.HtmlTextWriter WriteTagText (
			class [System.Web]System.Web.UI.HtmlTextWriter writer,
			valuetype [System.Web]System.Web.UI.HtmlTextWriterTag tag,
			string text
		) cil managed 
	{
		.custom /* 0C000095 */ instance void [System.Core]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5208
		// Header size: 1
		// Code size: 22 (0x16)
		.maxstack 8

		/* 0x00005208 02                 */ IL_0000: ldarg.0
		/* 0x00005209 03                 */ IL_0001: ldarg.1
		/* 0x0000520A 6F5F00000A         */ IL_0002: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderBeginTag(valuetype [System.Web]System.Web.UI.HtmlTextWriterTag) /* 0A00005F */
		/* 0x0000520F 02                 */ IL_0007: ldarg.0
		/* 0x00005210 04                 */ IL_0008: ldarg.2
		/* 0x00005211 6F6B00000A         */ IL_0009: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::WriteEncodedText(string) /* 0A00006B */
		/* 0x00005216 02                 */ IL_000e: ldarg.0
		/* 0x00005217 6F5E00000A         */ IL_000f: callvirt instance void [System.Web]System.Web.UI.HtmlTextWriter::RenderEndTag() /* 0A00005E */
		/* 0x0000521C 02                 */ IL_0014: ldarg.0
		/* 0x0000521D 2A                 */ IL_0015: ret
	} // end of method Extensions::WriteTagText

} // end of class AspenTech.Visualisation.Controls.Assistant.Extensions

.class /* 0200001C */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistScreen
	extends AspenTech.Visualisation.Controls.Assistant.AssistBase
{
	// Fields
	.field /* 0400004E */ private class AspenTech.Visualisation.Controls.Assistant.AssistOptions '<Options>k__BackingField'
	.custom /* 0C00006E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400004F */ private class AspenTech.Visualisation.Controls.Assistant.AssistRoot '<Parent>k__BackingField'
	.custom /* 0C000070 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 060000BA */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions get_Options () cil managed 
	{
		.custom /* 0C000096 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x521f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000521F 02                 */ IL_0000: ldarg.0
		/* 0x00005220 7B4E000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::'<Options>k__BackingField' /* 0400004E */
		/* 0x00005225 2A                 */ IL_0006: ret
	} // end of method AssistScreen::get_Options

	.method /* 060000BB */ private hidebysig specialname 
		instance void set_Options (
			class AspenTech.Visualisation.Controls.Assistant.AssistOptions 'value'
		) cil managed 
	{
		.custom /* 0C000097 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5227
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00005227 02                 */ IL_0000: ldarg.0
		/* 0x00005228 03                 */ IL_0001: ldarg.1
		/* 0x00005229 7D4E000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::'<Options>k__BackingField' /* 0400004E */
		/* 0x0000522E 2A                 */ IL_0007: ret
	} // end of method AssistScreen::set_Options

	.method /* 060000BC */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot get_Parent () cil managed 
	{
		.custom /* 0C000098 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5230
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00005230 02                 */ IL_0000: ldarg.0
		/* 0x00005231 7B4F000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistScreen::'<Parent>k__BackingField' /* 0400004F */
		/* 0x00005236 2A                 */ IL_0006: ret
	} // end of method AssistScreen::get_Parent

	.method /* 060000BD */ private hidebysig specialname 
		instance void set_Parent (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot 'value'
		) cil managed 
	{
		.custom /* 0C000099 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5238
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00005238 02                 */ IL_0000: ldarg.0
		/* 0x00005239 03                 */ IL_0001: ldarg.1
		/* 0x0000523A 7D4F000004         */ IL_0002: stfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistScreen::'<Parent>k__BackingField' /* 0400004F */
		/* 0x0000523F 2A                 */ IL_0007: ret
	} // end of method AssistScreen::set_Parent

	.method /* 060000BE */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot root
		) cil managed 
	{
		// Method begins at RVA 0x5244
		// Header size: 12
		// Code size: 187 (0xbb)
		.maxstack 4
		.locals /* 11000030 */ init (
			[0] int32,
			[1] class AspenTech.Visualisation.Controls.Assistant.AssistScreen,
			[2] int32,
			[3] valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>
		)

		/* 0x00005244 02                 */ IL_0000: ldarg.0
		/* 0x00005245 03                 */ IL_0001: ldarg.1
		/* 0x00005246 7E62000004         */ IL_0002: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Screen /* 04000062 */
		/* 0x0000524B 2835000006         */ IL_0007: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot, class [System.Xml.Linq]System.Xml.Linq.XName) /* 06000035 */
		/* 0x00005250 02                 */ IL_000c: ldarg.0
		/* 0x00005251 03                 */ IL_000d: ldarg.1
		/* 0x00005252 28BD000006         */ IL_000e: call instance void AspenTech.Visualisation.Controls.Assistant.AssistScreen::set_Parent(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 060000BD */
		/* 0x00005257 02                 */ IL_0013: ldarg.0
		/* 0x00005258 73E1000006         */ IL_0014: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistOptions::.ctor() /* 060000E1 */
		/* 0x0000525D 28BB000006         */ IL_0019: call instance void AspenTech.Visualisation.Controls.Assistant.AssistScreen::set_Options(class AspenTech.Visualisation.Controls.Assistant.AssistOptions) /* 060000BB */
		/* 0x00005262 16                 */ IL_001e: ldc.i4.0
		/* 0x00005263 0A                 */ IL_001f: stloc.0
		/* 0x00005264 03                 */ IL_0020: ldarg.1
		/* 0x00005265 6F39000006         */ IL_0021: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistScreens AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Screens() /* 06000039 */
		/* 0x0000526A 6FF600000A         */ IL_0026: callvirt instance valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<!0> class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::GetEnumerator() /* 0A0000F6 */
		/* 0x0000526F 0D                 */ IL_002b: stloc.3
		/* 0x00005270 2B3D               */ IL_002c: br.s IL_006b
		/* 0x00005272 1203               */ IL_002e: ldloca.s 3
		/* 0x00005274 28F700000A         */ IL_0030: call instance !0 valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::get_Current() /* 0A0000F7 */
		/* 0x00005279 0B                 */ IL_0035: stloc.1
		/* 0x0000527A 07                 */ IL_0036: ldloc.1
		/* 0x0000527B 6F28000006         */ IL_0037: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00005280 7299090070         */ IL_003c: ldstr "S" /* 70000999 */
		/* 0x00005285 6FB200000A         */ IL_0041: callvirt instance bool [mscorlib]System.String::StartsWith(string) /* 0A0000B2 */
		/* 0x0000528A 2C23               */ IL_0046: brfalse.s IL_006b
		/* 0x0000528C 07                 */ IL_0048: ldloc.1
		/* 0x0000528D 6F28000006         */ IL_0049: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00005292 17                 */ IL_004e: ldc.i4.1
		/* 0x00005293 6F7200000A         */ IL_004f: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A000072 */
		/* 0x00005298 1D                 */ IL_0054: ldc.i4.7
		/* 0x00005299 282D00000A         */ IL_0055: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00002D */
		/* 0x0000529E 1202               */ IL_005a: ldloca.s 2
		/* 0x000052A0 28D300000A         */ IL_005c: call bool [mscorlib]System.Int32::TryParse(string, valuetype [mscorlib]System.Globalization.NumberStyles, class [mscorlib]System.IFormatProvider, int32&) /* 0A0000D3 */
		/* 0x000052A5 2C08               */ IL_0061: brfalse.s IL_006b
		/* 0x000052A7 06                 */ IL_0063: ldloc.0
		/* 0x000052A8 08                 */ IL_0064: ldloc.2
		/* 0x000052A9 28D400000A         */ IL_0065: call int32 [mscorlib]System.Math::Max(int32, int32) /* 0A0000D4 */
		/* 0x000052AE 0A                 */ IL_006a: stloc.0
		/* 0x000052AF 1203               */ IL_006b: ldloca.s 3
		/* 0x000052B1 28F800000A         */ IL_006d: call instance bool valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistScreen>::MoveNext() /* 0A0000F8 */
		/* 0x000052B6 2DBA               */ IL_0072: brtrue.s IL_002e
		/* 0x000052B8 DE0E               */ IL_0074: leave.s IL_0084
		/* 0x000052BA 1203               */ IL_0076: ldloca.s 3
		/* 0x000052BC FE161E00001B       */ IL_0078: constrained. valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistScreen> /* 1B00001E */
		/* 0x000052C2 6F6D00000A         */ IL_007e: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x000052C7 DC                 */ IL_0083: endfinally
		/* 0x000052C8 02                 */ IL_0084: ldarg.0
		/* 0x000052C9 729D090070         */ IL_0085: ldstr "Screen " /* 7000099D */
		/* 0x000052CE 06                 */ IL_008a: ldloc.0
		/* 0x000052CF 17                 */ IL_008b: ldc.i4.1
		/* 0x000052D0 58                 */ IL_008c: add
		/* 0x000052D1 8C73000001         */ IL_008d: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x000052D6 282B00000A         */ IL_0092: call string [mscorlib]System.String::Concat(object, object) /* 0A00002B */
		/* 0x000052DB 2830000006         */ IL_0097: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x000052E0 02                 */ IL_009c: ldarg.0
		/* 0x000052E1 7299090070         */ IL_009d: ldstr "S" /* 70000999 */
		/* 0x000052E6 06                 */ IL_00a2: ldloc.0
		/* 0x000052E7 17                 */ IL_00a3: ldc.i4.1
		/* 0x000052E8 58                 */ IL_00a4: add
		/* 0x000052E9 8C73000001         */ IL_00a5: box [mscorlib]System.Int32 /* 01000073 */
		/* 0x000052EE 282B00000A         */ IL_00aa: call string [mscorlib]System.String::Concat(object, object) /* 0A00002B */
		/* 0x000052F3 2829000006         */ IL_00af: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_Id(string) /* 06000029 */
		/* 0x000052F8 02                 */ IL_00b4: ldarg.0
		/* 0x000052F9 2838000006         */ IL_00b5: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::Change() /* 06000038 */
		/* 0x000052FE 2A                 */ IL_00ba: ret

		.try IL_002c-IL_0076 finally IL_0076-IL_0084
	} // end of method AssistScreen::.ctor

	.method /* 060000BF */ assembly hidebysig strict virtual 
		instance void HydrateFromXml (
			class [System.Xml.Linq]System.Xml.Linq.XElement root
		) cil managed 
	{
		// Method begins at RVA 0x531c
		// Header size: 12
		// Code size: 163 (0xa3)
		.maxstack 3
		.locals /* 11000031 */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[1] class AspenTech.Visualisation.Controls.Assistant.AssistOption,
			[2] class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>
		)

		/* 0x0000531C 03                 */ IL_0000: ldarg.1
		/* 0x0000531D 6F9900000A         */ IL_0001: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XElement::get_Name() /* 0A000099 */
		/* 0x00005322 7E62000004         */ IL_0006: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Screen /* 04000062 */
		/* 0x00005327 289A00000A         */ IL_000b: call bool [System.Xml.Linq]System.Xml.Linq.XName::op_Inequality(class [System.Xml.Linq]System.Xml.Linq.XName, class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009A */
		/* 0x0000532C 2C0B               */ IL_0010: brfalse.s IL_001d
		/* 0x0000532E 72C6030070         */ IL_0012: ldstr "root" /* 700003C6 */
		/* 0x00005333 731A00000A         */ IL_0017: newobj instance void [mscorlib]System.ArgumentOutOfRangeException::.ctor(string) /* 0A00001A */
		/* 0x00005338 7A                 */ IL_001c: throw
		/* 0x00005339 02                 */ IL_001d: ldarg.0
		/* 0x0000533A 03                 */ IL_001e: ldarg.1
		/* 0x0000533B 7E5E000004         */ IL_001f: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Caption /* 0400005E */
		/* 0x00005340 6F9E00000A         */ IL_0024: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement [System.Xml.Linq]System.Xml.Linq.XContainer::Element(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009E */
		/* 0x00005345 7E2800000A         */ IL_0029: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x0000534A 28B5000006         */ IL_002e: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XElement, string) /* 060000B5 */
		/* 0x0000534F 2830000006         */ IL_0033: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::set_Caption(string) /* 06000030 */
		/* 0x00005354 02                 */ IL_0038: ldarg.0
		/* 0x00005355 03                 */ IL_0039: ldarg.1
		/* 0x00005356 7E6C000004         */ IL_003a: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x0000535B 6F9B00000A         */ IL_003f: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XAttribute [System.Xml.Linq]System.Xml.Linq.XElement::Attribute(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00009B */
		/* 0x00005360 7E2800000A         */ IL_0044: ldsfld string [mscorlib]System.String::Empty /* 0A000028 */
		/* 0x00005365 28B1000006         */ IL_0049: call string AspenTech.Visualisation.Controls.Assistant.Extensions::Value(class [System.Xml.Linq]System.Xml.Linq.XAttribute, string) /* 060000B1 */
		/* 0x0000536A 2829000006         */ IL_004e: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::set_Id(string) /* 06000029 */
		/* 0x0000536F 02                 */ IL_0053: ldarg.0
		/* 0x00005370 03                 */ IL_0054: ldarg.1
		/* 0x00005371 2837000006         */ IL_0055: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::ExplanationsFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 06000037 */
		/* 0x00005376 03                 */ IL_005a: ldarg.1
		/* 0x00005377 7E63000004         */ IL_005b: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Option /* 04000063 */
		/* 0x0000537C 6F7B00000A         */ IL_0060: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement> [System.Xml.Linq]System.Xml.Linq.XContainer::Elements(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A00007B */
		/* 0x00005381 6F7C00000A         */ IL_0065: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::GetEnumerator() /* 0A00007C */
		/* 0x00005386 0C                 */ IL_006a: stloc.2
		/* 0x00005387 2B21               */ IL_006b: br.s IL_008e
		/* 0x00005389 08                 */ IL_006d: ldloc.2
		/* 0x0000538A 6F7D00000A         */ IL_006e: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class [System.Xml.Linq]System.Xml.Linq.XElement>::get_Current() /* 0A00007D */
		/* 0x0000538F 0A                 */ IL_0073: stloc.0
		/* 0x00005390 02                 */ IL_0074: ldarg.0
		/* 0x00005391 738F000006         */ IL_0075: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistOption::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistScreen) /* 0600008F */
		/* 0x00005396 0B                 */ IL_007a: stloc.1
		/* 0x00005397 07                 */ IL_007b: ldloc.1
		/* 0x00005398 06                 */ IL_007c: ldloc.0
		/* 0x00005399 6F2D000006         */ IL_007d: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistBasic::HydrateFromXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 0600002D */
		/* 0x0000539E 02                 */ IL_0082: ldarg.0
		/* 0x0000539F 28BA000006         */ IL_0083: call instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x000053A4 07                 */ IL_0088: ldloc.1
		/* 0x000053A5 6FF900000A         */ IL_0089: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::Add(!0) /* 0A0000F9 */
		/* 0x000053AA 08                 */ IL_008e: ldloc.2
		/* 0x000053AB 6F7700000A         */ IL_008f: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000077 */
		/* 0x000053B0 2DD7               */ IL_0094: brtrue.s IL_006d
		/* 0x000053B2 DE0A               */ IL_0096: leave.s IL_00a2
		/* 0x000053B4 08                 */ IL_0098: ldloc.2
		/* 0x000053B5 2C06               */ IL_0099: brfalse.s IL_00a1
		/* 0x000053B7 08                 */ IL_009b: ldloc.2
		/* 0x000053B8 6F6D00000A         */ IL_009c: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x000053BD DC                 */ IL_00a1: endfinally
		/* 0x000053BE 2A                 */ IL_00a2: ret

		.try IL_006b-IL_0098 finally IL_0098-IL_00a2
	} // end of method AssistScreen::HydrateFromXml

	.method /* 060000C0 */ assembly hidebysig strict virtual 
		instance class [System.Xml.Linq]System.Xml.Linq.XElement DehydrateToXml () cil managed 
	{
		// Method begins at RVA 0x53dc
		// Header size: 12
		// Code size: 150 (0x96)
		.maxstack 5
		.locals /* 11000032 */ init (
			[0] class [System.Xml.Linq]System.Xml.Linq.XElement,
			[1] class AspenTech.Visualisation.Controls.Assistant.AssistOption,
			[2] object[],
			[3] valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>
		)

		/* 0x000053DC 7E62000004         */ IL_0000: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Screen /* 04000062 */
		/* 0x000053E1 73A800000A         */ IL_0005: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A0000A8 */
		/* 0x000053E6 0A                 */ IL_000a: stloc.0
		/* 0x000053E7 02                 */ IL_000b: ldarg.0
		/* 0x000053E8 2828000006         */ IL_000c: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x000053ED 282C00000A         */ IL_0011: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00002C */
		/* 0x000053F2 2D16               */ IL_0016: brtrue.s IL_002e
		/* 0x000053F4 06                 */ IL_0018: ldloc.0
		/* 0x000053F5 7E6C000004         */ IL_0019: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
		/* 0x000053FA 02                 */ IL_001e: ldarg.0
		/* 0x000053FB 2828000006         */ IL_001f: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBasic::get_Id() /* 06000028 */
		/* 0x00005400 73A400000A         */ IL_0024: newobj instance void [System.Xml.Linq]System.Xml.Linq.XAttribute::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName, object) /* 0A0000A4 */
		/* 0x00005405 6F7A00000A         */ IL_0029: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object) /* 0A00007A */
		/* 0x0000540A 06                 */ IL_002e: ldloc.0
		/* 0x0000540B 18                 */ IL_002f: ldc.i4.2
		/* 0x0000540C 8D01000001         */ IL_0030: newarr [mscorlib]System.Object /* 01000001 */
		/* 0x00005411 0C                 */ IL_0035: stloc.2
		/* 0x00005412 08                 */ IL_0036: ldloc.2
		/* 0x00005413 16                 */ IL_0037: ldc.i4.0
		/* 0x00005414 7E5E000004         */ IL_0038: ldsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Caption /* 0400005E */
		/* 0x00005419 73A800000A         */ IL_003d: newobj instance void [System.Xml.Linq]System.Xml.Linq.XElement::.ctor(class [System.Xml.Linq]System.Xml.Linq.XName) /* 0A0000A8 */
		/* 0x0000541E A2                 */ IL_0042: stelem.ref
		/* 0x0000541F 08                 */ IL_0043: ldloc.2
		/* 0x00005420 17                 */ IL_0044: ldc.i4.1
		/* 0x00005421 02                 */ IL_0045: ldarg.0
		/* 0x00005422 282F000006         */ IL_0046: call instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x00005427 A2                 */ IL_004b: stelem.ref
		/* 0x00005428 08                 */ IL_004c: ldloc.2
		/* 0x00005429 6FFA00000A         */ IL_004d: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object[]) /* 0A0000FA */
		/* 0x0000542E 02                 */ IL_0052: ldarg.0
		/* 0x0000542F 06                 */ IL_0053: ldloc.0
		/* 0x00005430 2836000006         */ IL_0054: call instance void AspenTech.Visualisation.Controls.Assistant.AssistBase::ExplanationsToXml(class [System.Xml.Linq]System.Xml.Linq.XElement) /* 06000036 */
		/* 0x00005435 02                 */ IL_0059: ldarg.0
		/* 0x00005436 28BA000006         */ IL_005a: call instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options() /* 060000BA */
		/* 0x0000543B 6F6700000A         */ IL_005f: callvirt instance valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<!0> class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::GetEnumerator() /* 0A000067 */
		/* 0x00005440 0D                 */ IL_0064: stloc.3
		/* 0x00005441 2B14               */ IL_0065: br.s IL_007b
		/* 0x00005443 1203               */ IL_0067: ldloca.s 3
		/* 0x00005445 286800000A         */ IL_0069: call instance !0 valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::get_Current() /* 0A000068 */
		/* 0x0000544A 0B                 */ IL_006e: stloc.1
		/* 0x0000544B 06                 */ IL_006f: ldloc.0
		/* 0x0000544C 07                 */ IL_0070: ldloc.1
		/* 0x0000544D 6F2C000006         */ IL_0071: callvirt instance class [System.Xml.Linq]System.Xml.Linq.XElement AspenTech.Visualisation.Controls.Assistant.AssistBasic::DehydrateToXml() /* 0600002C */
		/* 0x00005452 6F7A00000A         */ IL_0076: callvirt instance void [System.Xml.Linq]System.Xml.Linq.XContainer::Add(object) /* 0A00007A */
		/* 0x00005457 1203               */ IL_007b: ldloca.s 3
		/* 0x00005459 286C00000A         */ IL_007d: call instance bool valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::MoveNext() /* 0A00006C */
		/* 0x0000545E 2DE3               */ IL_0082: brtrue.s IL_0067
		/* 0x00005460 DE0E               */ IL_0084: leave.s IL_0094
		/* 0x00005462 1203               */ IL_0086: ldloca.s 3
		/* 0x00005464 FE160500001B       */ IL_0088: constrained. valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.Visualisation.Controls.Assistant.AssistOption> /* 1B000005 */
		/* 0x0000546A 6F6D00000A         */ IL_008e: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00006D */
		/* 0x0000546F DC                 */ IL_0093: endfinally
		/* 0x00005470 06                 */ IL_0094: ldloc.0
		/* 0x00005471 2A                 */ IL_0095: ret

		.try IL_0065-IL_0086 finally IL_0086-IL_0094
	} // end of method AssistScreen::DehydrateToXml

	// Properties
	.property /* 17000035 */ instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions Options()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistOptions AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Options()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistScreen::set_Options(class AspenTech.Visualisation.Controls.Assistant.AssistOptions)
	}
	.property /* 17000036 */ instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot Parent()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistScreen::get_Parent()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistScreen::set_Parent(class AspenTech.Visualisation.Controls.Assistant.AssistRoot)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistScreen

.class /* 0200001D */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistantDialog
	extends [PresentationFramework]System.Windows.Window
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	.custom /* 0C000028 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
		75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
		30 00 00
	)
	// Fields
	.field /* 04000050 */ private class [mscorlib]System.Collections.Generic.List`1<string> _deleteTheseFiles
	.field /* 04000051 */ assembly class AspenTech.Visualisation.Controls.Assistant.AssistantControl AssistantControl
	.field /* 04000052 */ assembly class [PresentationFramework]System.Windows.Controls.Button AboutButton
	.field /* 04000053 */ assembly class [PresentationFramework]System.Windows.Controls.Button ReportButton
	.field /* 04000054 */ assembly class [PresentationFramework]System.Windows.Controls.Button CloseButton
	.field /* 04000055 */ private bool _contentLoaded

	// Methods
	.method /* 060000C1 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x5490
		// Header size: 1
		// Code size: 24 (0x18)
		.maxstack 8

		/* 0x00005490 02                 */ IL_0000: ldarg.0
		/* 0x00005491 737800000A         */ IL_0001: newobj instance void class [mscorlib]System.Collections.Generic.List`1<string>::.ctor() /* 0A000078 */
		/* 0x00005496 7D50000004         */ IL_0006: stfld class [mscorlib]System.Collections.Generic.List`1<string> AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_deleteTheseFiles /* 04000050 */
		/* 0x0000549B 02                 */ IL_000b: ldarg.0
		/* 0x0000549C 28FB00000A         */ IL_000c: call instance void [PresentationFramework]System.Windows.Window::.ctor() /* 0A0000FB */
		/* 0x000054A1 02                 */ IL_0011: ldarg.0
		/* 0x000054A2 28CD000006         */ IL_0012: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::InitializeComponent() /* 060000CD */
		/* 0x000054A7 2A                 */ IL_0017: ret
	} // end of method AssistantDialog::.ctor

	.method /* 060000C2 */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot get_Assistant () cil managed 
	{
		// Method begins at RVA 0x54a9
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000054A9 02                 */ IL_0000: ldarg.0
		/* 0x000054AA 7B51000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistantControl AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AssistantControl /* 04000051 */
		/* 0x000054AF 6FD0000006         */ IL_0006: callvirt instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_Assistant() /* 060000D0 */
		/* 0x000054B4 2A                 */ IL_000b: ret
	} // end of method AssistantDialog::get_Assistant

	.method /* 060000C3 */ public hidebysig specialname 
		instance void set_Assistant (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot 'value'
		) cil managed 
	{
		// Method begins at RVA 0x54b6
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x000054B6 02                 */ IL_0000: ldarg.0
		/* 0x000054B7 7B51000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistantControl AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AssistantControl /* 04000051 */
		/* 0x000054BC 03                 */ IL_0006: ldarg.1
		/* 0x000054BD 6FD1000006         */ IL_0007: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::set_Assistant(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 060000D1 */
		/* 0x000054C2 02                 */ IL_000c: ldarg.0
		/* 0x000054C3 28CA000006         */ IL_000d: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::Translate() /* 060000CA */
		/* 0x000054C8 2A                 */ IL_0012: ret
	} // end of method AssistantDialog::set_Assistant

	.method /* 060000C4 */ public hidebysig specialname 
		instance string get_CurrentScreen () cil managed 
	{
		// Method begins at RVA 0x54ca
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000054CA 02                 */ IL_0000: ldarg.0
		/* 0x000054CB 7B51000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistantControl AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AssistantControl /* 04000051 */
		/* 0x000054D0 6FD3000006         */ IL_0006: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_CurrentScreen() /* 060000D3 */
		/* 0x000054D5 2A                 */ IL_000b: ret
	} // end of method AssistantDialog::get_CurrentScreen

	.method /* 060000C5 */ public hidebysig specialname 
		instance void set_CurrentScreen (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x54d7
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000054D7 02                 */ IL_0000: ldarg.0
		/* 0x000054D8 7B51000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistantControl AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AssistantControl /* 04000051 */
		/* 0x000054DD 03                 */ IL_0006: ldarg.1
		/* 0x000054DE 6FD4000006         */ IL_0007: callvirt instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::set_CurrentScreen(string) /* 060000D4 */
		/* 0x000054E3 2A                 */ IL_000c: ret
	} // end of method AssistantDialog::set_CurrentScreen

	.method /* 060000C6 */ private hidebysig 
		instance void CloseButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x54e5
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000054E5 02                 */ IL_0000: ldarg.0
		/* 0x000054E6 28FC00000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Window::Close() /* 0A0000FC */
		/* 0x000054EB 2A                 */ IL_0006: ret
	} // end of method AssistantDialog::CloseButton_Click

	.method /* 060000C7 */ private hidebysig 
		instance void AboutButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x54ed
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000054ED 17                 */ IL_0000: ldc.i4.1
		/* 0x000054EE 2802000006         */ IL_0001: call void AspenTech.Visualisation.Controls.Assistant.Aspen::About(valuetype AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource) /* 06000002 */
		/* 0x000054F3 2A                 */ IL_0006: ret
	} // end of method AssistantDialog::AboutButton_Click

	.method /* 060000C8 */ private hidebysig 
		instance void ReportButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x54f8
		// Header size: 12
		// Code size: 95 (0x5f)
		.maxstack 3
		.locals /* 11000033 */ init (
			[0] string,
			[1] string,
			[2] string,
			[3] valuetype [mscorlib]System.Guid
		)

		/* 0x000054F8 02                 */ IL_0000: ldarg.0
		/* 0x000054F9 7B51000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistantControl AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AssistantControl /* 04000051 */
		/* 0x000054FE 6FD2000006         */ IL_0006: callvirt instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x00005503 17                 */ IL_000b: ldc.i4.1
		/* 0x00005504 6F5F000006         */ IL_000c: callvirt instance string AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::RenderAllToHtml(valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget) /* 0600005F */
		/* 0x00005509 0A                 */ IL_0011: stloc.0
		/* 0x0000550A 28FD00000A         */ IL_0012: call string [mscorlib]System.IO.Path::GetTempPath() /* 0A0000FD */
		/* 0x0000550F 0B                 */ IL_0017: stloc.1
		/* 0x00005510 07                 */ IL_0018: ldloc.1
		/* 0x00005511 288000000A         */ IL_0019: call valuetype [mscorlib]System.Guid [mscorlib]System.Guid::NewGuid() /* 0A000080 */
		/* 0x00005516 0D                 */ IL_001e: stloc.3
		/* 0x00005517 1203               */ IL_001f: ldloca.s 3
		/* 0x00005519 FE161D000001       */ IL_0021: constrained. [mscorlib]System.Guid /* 0100001D */
		/* 0x0000551F 6F6000000A         */ IL_0027: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x00005524 72AD090070         */ IL_002c: ldstr ".html" /* 700009AD */
		/* 0x00005529 283500000A         */ IL_0031: call string [mscorlib]System.String::Concat(string, string) /* 0A000035 */
		/* 0x0000552E 285800000A         */ IL_0036: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A000058 */
		/* 0x00005533 0C                 */ IL_003b: stloc.2
		/* 0x00005534 08                 */ IL_003c: ldloc.2
		/* 0x00005535 285900000A         */ IL_003d: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x0000553A 2DD4               */ IL_0042: brtrue.s IL_0018
		/* 0x0000553C 02                 */ IL_0044: ldarg.0
		/* 0x0000553D 7B50000004         */ IL_0045: ldfld class [mscorlib]System.Collections.Generic.List`1<string> AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_deleteTheseFiles /* 04000050 */
		/* 0x00005542 08                 */ IL_004a: ldloc.2
		/* 0x00005543 6F4000000A         */ IL_004b: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<string>::Add(!0) /* 0A000040 */
		/* 0x00005548 08                 */ IL_0050: ldloc.2
		/* 0x00005549 06                 */ IL_0051: ldloc.0
		/* 0x0000554A 288D00000A         */ IL_0052: call void [mscorlib]System.IO.File::WriteAllText(string, string) /* 0A00008D */
		/* 0x0000554F 08                 */ IL_0057: ldloc.2
		/* 0x00005550 28CA00000A         */ IL_0058: call class [System]System.Diagnostics.Process [System]System.Diagnostics.Process::Start(string) /* 0A0000CA */
		/* 0x00005555 26                 */ IL_005d: pop
		/* 0x00005556 2A                 */ IL_005e: ret
	} // end of method AssistantDialog::ReportButton_Click

	.method /* 060000C9 */ private hidebysig 
		instance void ClearDeleteFiles () cil managed 
	{
		// Method begins at RVA 0x5564
		// Header size: 12
		// Code size: 63 (0x3f)
		.maxstack 2
		.locals /* 11000034 */ init (
			[0] string[],
			[1] string,
			[2] string[],
			[3] int32
		)

		/* 0x00005564 02                 */ IL_0000: ldarg.0
		/* 0x00005565 7B50000004         */ IL_0001: ldfld class [mscorlib]System.Collections.Generic.List`1<string> AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_deleteTheseFiles /* 04000050 */
		/* 0x0000556A 6FFE00000A         */ IL_0006: callvirt instance !0[] class [mscorlib]System.Collections.Generic.List`1<string>::ToArray() /* 0A0000FE */
		/* 0x0000556F 0A                 */ IL_000b: stloc.0
		/* 0x00005570 02                 */ IL_000c: ldarg.0
		/* 0x00005571 7B50000004         */ IL_000d: ldfld class [mscorlib]System.Collections.Generic.List`1<string> AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_deleteTheseFiles /* 04000050 */
		/* 0x00005576 6FFF00000A         */ IL_0012: callvirt instance void class [mscorlib]System.Collections.Generic.List`1<string>::Clear() /* 0A0000FF */
		/* 0x0000557B 06                 */ IL_0017: ldloc.0
		/* 0x0000557C 0C                 */ IL_0018: stloc.2
		/* 0x0000557D 16                 */ IL_0019: ldc.i4.0
		/* 0x0000557E 0D                 */ IL_001a: stloc.3
		/* 0x0000557F 2B1B               */ IL_001b: br.s IL_0038
		/* 0x00005581 08                 */ IL_001d: ldloc.2
		/* 0x00005582 09                 */ IL_001e: ldloc.3
		/* 0x00005583 9A                 */ IL_001f: ldelem.ref
		/* 0x00005584 0B                 */ IL_0020: stloc.1
		/* 0x00005585 07                 */ IL_0021: ldloc.1
		/* 0x00005586 285900000A         */ IL_0022: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000059 */
		/* 0x0000558B 2C0B               */ IL_0027: brfalse.s IL_0034
		/* 0x0000558D 07                 */ IL_0029: ldloc.1
		/* 0x0000558E 280001000A         */ IL_002a: call void [mscorlib]System.IO.File::Delete(string) /* 0A000100 */
		/* 0x00005593 DE03               */ IL_002f: leave.s IL_0034
		/* 0x00005595 26                 */ IL_0031: pop
		/* 0x00005596 DE00               */ IL_0032: leave.s IL_0034
		/* 0x00005598 09                 */ IL_0034: ldloc.3
		/* 0x00005599 17                 */ IL_0035: ldc.i4.1
		/* 0x0000559A 58                 */ IL_0036: add
		/* 0x0000559B 0D                 */ IL_0037: stloc.3
		/* 0x0000559C 09                 */ IL_0038: ldloc.3
		/* 0x0000559D 08                 */ IL_0039: ldloc.2
		/* 0x0000559E 8E                 */ IL_003a: ldlen
		/* 0x0000559F 69                 */ IL_003b: conv.i4
		/* 0x000055A0 32DF               */ IL_003c: blt.s IL_001d
		/* 0x000055A2 2A                 */ IL_003e: ret

		.try IL_0029-IL_0031 catch [mscorlib]System.Object IL_0031-IL_0034
	} // end of method AssistantDialog::ClearDeleteFiles

	.method /* 060000CA */ private hidebysig 
		instance void Translate () cil managed 
	{
		// Method begins at RVA 0x55c0
		// Header size: 12
		// Code size: 105 (0x69)
		.maxstack 4

		/* 0x000055C0 02                 */ IL_0000: ldarg.0
		/* 0x000055C1 7B52000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AboutButton /* 04000052 */
		/* 0x000055C6 02                 */ IL_0006: ldarg.0
		/* 0x000055C7 72B9090070         */ IL_0007: ldstr "About…" /* 700009B9 */
		/* 0x000055CC 28CB000006         */ IL_000c: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantDialog::Translate(string) /* 060000CB */
		/* 0x000055D1 6F0101000A         */ IL_0011: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A000101 */
		/* 0x000055D6 02                 */ IL_0016: ldarg.0
		/* 0x000055D7 7B53000004         */ IL_0017: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::ReportButton /* 04000053 */
		/* 0x000055DC 02                 */ IL_001c: ldarg.0
		/* 0x000055DD 72C7090070         */ IL_001d: ldstr "Report…" /* 700009C7 */
		/* 0x000055E2 28CB000006         */ IL_0022: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantDialog::Translate(string) /* 060000CB */
		/* 0x000055E7 6F0101000A         */ IL_0027: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A000101 */
		/* 0x000055EC 02                 */ IL_002c: ldarg.0
		/* 0x000055ED 7B54000004         */ IL_002d: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::CloseButton /* 04000054 */
		/* 0x000055F2 02                 */ IL_0032: ldarg.0
		/* 0x000055F3 72D7090070         */ IL_0033: ldstr "Close" /* 700009D7 */
		/* 0x000055F8 28CB000006         */ IL_0038: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantDialog::Translate(string) /* 060000CB */
		/* 0x000055FD 6F0101000A         */ IL_003d: callvirt instance void [PresentationFramework]System.Windows.Controls.ContentControl::set_Content(object) /* 0A000101 */
		/* 0x00005602 02                 */ IL_0042: ldarg.0
		/* 0x00005603 02                 */ IL_0043: ldarg.0
		/* 0x00005604 72E3090070         */ IL_0044: ldstr "Assistant" /* 700009E3 */
		/* 0x00005609 28CB000006         */ IL_0049: call instance string AspenTech.Visualisation.Controls.Assistant.AssistantDialog::Translate(string) /* 060000CB */
		/* 0x0000560E 72F7090070         */ IL_004e: ldstr " - " /* 700009F7 */
		/* 0x00005613 02                 */ IL_0053: ldarg.0
		/* 0x00005614 28C2000006         */ IL_0054: call instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantDialog::get_Assistant() /* 060000C2 */
		/* 0x00005619 6F2F000006         */ IL_0059: callvirt instance string AspenTech.Visualisation.Controls.Assistant.AssistBase::get_Caption() /* 0600002F */
		/* 0x0000561E 286300000A         */ IL_005e: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000063 */
		/* 0x00005623 280201000A         */ IL_0063: call instance void [PresentationFramework]System.Windows.Window::set_Title(string) /* 0A000102 */
		/* 0x00005628 2A                 */ IL_0068: ret
	} // end of method AssistantDialog::Translate

	.method /* 060000CB */ private hidebysig 
		instance string Translate (
			string text
		) cil managed 
	{
		// Method begins at RVA 0x5638
		// Header size: 12
		// Code size: 33 (0x21)
		.maxstack 3
		.locals /* 11000009 */ init (
			[0] string
		)

		/* 0x00005638 02                 */ IL_0000: ldarg.0
		/* 0x00005639 28C2000006         */ IL_0001: call instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantDialog::get_Assistant() /* 060000C2 */
		/* 0x0000563E 2C17               */ IL_0006: brfalse.s IL_001f
		/* 0x00005640 02                 */ IL_0008: ldarg.0
		/* 0x00005641 28C2000006         */ IL_0009: call instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantDialog::get_Assistant() /* 060000C2 */
		/* 0x00005646 6F4F000006         */ IL_000e: callvirt instance class [mscorlib]System.Collections.Generic.IDictionary`2<string, string> AspenTech.Visualisation.Controls.Assistant.AssistRoot::get_Translations() /* 0600004F */
		/* 0x0000564B 03                 */ IL_0013: ldarg.1
		/* 0x0000564C 1200               */ IL_0014: ldloca.s 0
		/* 0x0000564E 6F0301000A         */ IL_0016: callvirt instance bool class [mscorlib]System.Collections.Generic.IDictionary`2<string, string>::TryGetValue(!0, !1&) /* 0A000103 */
		/* 0x00005653 2C02               */ IL_001b: brfalse.s IL_001f
		/* 0x00005655 06                 */ IL_001d: ldloc.0
		/* 0x00005656 2A                 */ IL_001e: ret
		/* 0x00005657 03                 */ IL_001f: ldarg.1
		/* 0x00005658 2A                 */ IL_0020: ret
	} // end of method AssistantDialog::Translate

	.method /* 060000CC */ private hidebysig 
		instance void Window_Closing (
			object sender,
			class [System]System.ComponentModel.CancelEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x5665
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00005665 02                 */ IL_0000: ldarg.0
		/* 0x00005666 28C9000006         */ IL_0001: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::ClearDeleteFiles() /* 060000C9 */
		/* 0x0000566B 2A                 */ IL_0006: ret
	} // end of method AssistantDialog::Window_Closing

	.method /* 060000CD */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00009A */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x5670
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 3
		.locals /* 11000035 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00005670 02                 */ IL_0000: ldarg.0
		/* 0x00005671 7B55000004         */ IL_0001: ldfld bool AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_contentLoaded /* 04000055 */
		/* 0x00005676 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00005678 2A                 */ IL_0008: ret
		/* 0x00005679 02                 */ IL_0009: ldarg.0
		/* 0x0000567A 17                 */ IL_000a: ldc.i4.1
		/* 0x0000567B 7D55000004         */ IL_000b: stfld bool AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_contentLoaded /* 04000055 */
		/* 0x00005680 72FF090070         */ IL_0010: ldstr "/AspenTech.Visualisation.Controls.Assistant.W1;component/controls/assistantdialog.xaml" /* 700009FF */
		/* 0x00005685 18                 */ IL_0015: ldc.i4.2
		/* 0x00005686 730401000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A000104 */
		/* 0x0000568B 0A                 */ IL_001b: stloc.0
		/* 0x0000568C 02                 */ IL_001c: ldarg.0
		/* 0x0000568D 06                 */ IL_001d: ldloc.0
		/* 0x0000568E 280501000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000105 */
		/* 0x00005693 2A                 */ IL_0023: ret
	} // end of method AssistantDialog::InitializeComponent

	.method /* 060000CE */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C00009B */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00009C */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x56a0
		// Header size: 12
		// Code size: 188 (0xbc)
		.maxstack 4
		.locals /* 1100002E */ init (
			[0] int32
		)

		/* 0x000056A0 03                 */ IL_0000: ldarg.1
		/* 0x000056A1 0A                 */ IL_0001: stloc.0
		/* 0x000056A2 06                 */ IL_0002: ldloc.0
		/* 0x000056A3 17                 */ IL_0003: ldc.i4.1
		/* 0x000056A4 59                 */ IL_0004: sub
		/* 0x000056A5 4505000000         */ IL_0005: switch (
		/*              05000000         */                  IL_0023,
		/*              1D000000         */                  IL_003b,
		/*              2A000000         */                  IL_0048,
		/*              4E000000         */                  IL_006c,
		/*              72000000         */                  IL_0090)
		/* 0x000056BE 3891000000         */ IL_001e: br IL_00b4
		/* 0x000056C3 04                 */ IL_0023: ldarg.2
		/* 0x000056C4 741D000002         */ IL_0024: castclass AspenTech.Visualisation.Controls.Assistant.AssistantDialog /* 0200001D */
		/* 0x000056C9 02                 */ IL_0029: ldarg.0
		/* 0x000056CA FE06CC000006       */ IL_002a: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::Window_Closing(object, class [System]System.ComponentModel.CancelEventArgs) /* 060000CC */
		/* 0x000056D0 730601000A         */ IL_0030: newobj instance void [System]System.ComponentModel.CancelEventHandler::.ctor(object, native int) /* 0A000106 */
		/* 0x000056D5 6F0701000A         */ IL_0035: callvirt instance void [PresentationFramework]System.Windows.Window::add_Closing(class [System]System.ComponentModel.CancelEventHandler) /* 0A000107 */
		/* 0x000056DA 2A                 */ IL_003a: ret
		/* 0x000056DB 02                 */ IL_003b: ldarg.0
		/* 0x000056DC 04                 */ IL_003c: ldarg.2
		/* 0x000056DD 741E000002         */ IL_003d: castclass AspenTech.Visualisation.Controls.Assistant.AssistantControl /* 0200001E */
		/* 0x000056E2 7D51000004         */ IL_0042: stfld class AspenTech.Visualisation.Controls.Assistant.AssistantControl AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AssistantControl /* 04000051 */
		/* 0x000056E7 2A                 */ IL_0047: ret
		/* 0x000056E8 02                 */ IL_0048: ldarg.0
		/* 0x000056E9 04                 */ IL_0049: ldarg.2
		/* 0x000056EA 7421000001         */ IL_004a: castclass [PresentationFramework]System.Windows.Controls.Button /* 01000021 */
		/* 0x000056EF 7D52000004         */ IL_004f: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AboutButton /* 04000052 */
		/* 0x000056F4 02                 */ IL_0054: ldarg.0
		/* 0x000056F5 7B52000004         */ IL_0055: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AboutButton /* 04000052 */
		/* 0x000056FA 02                 */ IL_005a: ldarg.0
		/* 0x000056FB FE06C7000006       */ IL_005b: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::AboutButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000C7 */
		/* 0x00005701 730801000A         */ IL_0061: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000108 */
		/* 0x00005706 6F0901000A         */ IL_0066: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000109 */
		/* 0x0000570B 2A                 */ IL_006b: ret
		/* 0x0000570C 02                 */ IL_006c: ldarg.0
		/* 0x0000570D 04                 */ IL_006d: ldarg.2
		/* 0x0000570E 7421000001         */ IL_006e: castclass [PresentationFramework]System.Windows.Controls.Button /* 01000021 */
		/* 0x00005713 7D53000004         */ IL_0073: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::ReportButton /* 04000053 */
		/* 0x00005718 02                 */ IL_0078: ldarg.0
		/* 0x00005719 7B53000004         */ IL_0079: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::ReportButton /* 04000053 */
		/* 0x0000571E 02                 */ IL_007e: ldarg.0
		/* 0x0000571F FE06C8000006       */ IL_007f: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::ReportButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000C8 */
		/* 0x00005725 730801000A         */ IL_0085: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000108 */
		/* 0x0000572A 6F0901000A         */ IL_008a: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000109 */
		/* 0x0000572F 2A                 */ IL_008f: ret
		/* 0x00005730 02                 */ IL_0090: ldarg.0
		/* 0x00005731 04                 */ IL_0091: ldarg.2
		/* 0x00005732 7421000001         */ IL_0092: castclass [PresentationFramework]System.Windows.Controls.Button /* 01000021 */
		/* 0x00005737 7D54000004         */ IL_0097: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::CloseButton /* 04000054 */
		/* 0x0000573C 02                 */ IL_009c: ldarg.0
		/* 0x0000573D 7B54000004         */ IL_009d: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.Visualisation.Controls.Assistant.AssistantDialog::CloseButton /* 04000054 */
		/* 0x00005742 02                 */ IL_00a2: ldarg.0
		/* 0x00005743 FE06C6000006       */ IL_00a3: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::CloseButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000C6 */
		/* 0x00005749 730801000A         */ IL_00a9: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000108 */
		/* 0x0000574E 6F0901000A         */ IL_00ae: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000109 */
		/* 0x00005753 2A                 */ IL_00b3: ret
		/* 0x00005754 02                 */ IL_00b4: ldarg.0
		/* 0x00005755 17                 */ IL_00b5: ldc.i4.1
		/* 0x00005756 7D55000004         */ IL_00b6: stfld bool AspenTech.Visualisation.Controls.Assistant.AssistantDialog::_contentLoaded /* 04000055 */
		/* 0x0000575B 2A                 */ IL_00bb: ret
	} // end of method AssistantDialog::System.Windows.Markup.IComponentConnector.Connect

	// Properties
	.property /* 17000037 */ instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot Assistant()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantDialog::get_Assistant()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::set_Assistant(class AspenTech.Visualisation.Controls.Assistant.AssistRoot)
	}
	.property /* 17000038 */ instance string CurrentScreen()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistantDialog::get_CurrentScreen()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantDialog::set_CurrentScreen(string)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistantDialog

.class /* 0200001E */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistantControl
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	.custom /* 0C00002A */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
		75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
		30 00 00
	)
	// Fields
	.field /* 04000056 */ private class AspenTech.Visualisation.Controls.Assistant.AssistRoot _root
	.field /* 04000057 */ assembly class [PresentationFramework]System.Windows.Controls.WebBrowser webBrowser
	.field /* 04000058 */ private bool _contentLoaded

	// Methods
	.method /* 060000CF */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x5768
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00005768 02                 */ IL_0000: ldarg.0
		/* 0x00005769 280A01000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A00010A */
		/* 0x0000576E 02                 */ IL_0006: ldarg.0
		/* 0x0000576F 28D8000006         */ IL_0007: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::InitializeComponent() /* 060000D8 */
		/* 0x00005774 2A                 */ IL_000c: ret
	} // end of method AssistantControl::.ctor

	.method /* 060000D0 */ public hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot get_Assistant () cil managed 
	{
		// Method begins at RVA 0x5776
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00005776 02                 */ IL_0000: ldarg.0
		/* 0x00005777 7B56000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::_root /* 04000056 */
		/* 0x0000577C 2A                 */ IL_0006: ret
	} // end of method AssistantControl::get_Assistant

	.method /* 060000D1 */ public hidebysig specialname 
		instance void set_Assistant (
			class AspenTech.Visualisation.Controls.Assistant.AssistRoot 'value'
		) cil managed 
	{
		// Method begins at RVA 0x5780
		// Header size: 12
		// Code size: 118 (0x76)
		.maxstack 4
		.locals /* 11000036 */ init (
			[0] class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel
		)

		/* 0x00005780 02                 */ IL_0000: ldarg.0
		/* 0x00005781 7B56000004         */ IL_0001: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::_root /* 04000056 */
		/* 0x00005786 03                 */ IL_0006: ldarg.1
		/* 0x00005787 2E6C               */ IL_0007: beq.s IL_0075
		/* 0x00005789 02                 */ IL_0009: ldarg.0
		/* 0x0000578A 03                 */ IL_000a: ldarg.1
		/* 0x0000578B 7D56000004         */ IL_000b: stfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::_root /* 04000056 */
		/* 0x00005790 02                 */ IL_0010: ldarg.0
		/* 0x00005791 280B01000A         */ IL_0011: call instance object [PresentationFramework]System.Windows.FrameworkElement::get_DataContext() /* 0A00010B */
		/* 0x00005796 750F000002         */ IL_0016: isinst AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel /* 0200000F */
		/* 0x0000579B 0A                 */ IL_001b: stloc.0
		/* 0x0000579C 06                 */ IL_001c: ldloc.0
		/* 0x0000579D 03                 */ IL_001d: ldarg.1
		/* 0x0000579E 2E55               */ IL_001e: beq.s IL_0075
		/* 0x000057A0 02                 */ IL_0020: ldarg.0
		/* 0x000057A1 280B01000A         */ IL_0021: call instance object [PresentationFramework]System.Windows.FrameworkElement::get_DataContext() /* 0A00010B */
		/* 0x000057A6 2C12               */ IL_0026: brfalse.s IL_003a
		/* 0x000057A8 06                 */ IL_0028: ldloc.0
		/* 0x000057A9 02                 */ IL_0029: ldarg.0
		/* 0x000057AA FE06D5000006       */ IL_002a: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::ModelPropertyChanged(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 060000D5 */
		/* 0x000057B0 730C01000A         */ IL_0030: newobj instance void [System]System.ComponentModel.PropertyChangedEventHandler::.ctor(object, native int) /* 0A00010C */
		/* 0x000057B5 6F0D01000A         */ IL_0035: callvirt instance void [System]System.ComponentModel.INotifyPropertyChanged::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler) /* 0A00010D */
		/* 0x000057BA 02                 */ IL_003a: ldarg.0
		/* 0x000057BB 7B56000004         */ IL_003b: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::_root /* 04000056 */
		/* 0x000057C0 2C2C               */ IL_0040: brfalse.s IL_006e
		/* 0x000057C2 02                 */ IL_0042: ldarg.0
		/* 0x000057C3 7B56000004         */ IL_0043: ldfld class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::_root /* 04000056 */
		/* 0x000057C8 7365000006         */ IL_0048: newobj instance void AspenTech.Visualisation.Controls.Assistant.AssistantViewModel::.ctor(class AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 06000065 */
		/* 0x000057CD 0A                 */ IL_004d: stloc.0
		/* 0x000057CE 02                 */ IL_004e: ldarg.0
		/* 0x000057CF 06                 */ IL_004f: ldloc.0
		/* 0x000057D0 280E01000A         */ IL_0050: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A00010E */
		/* 0x000057D5 06                 */ IL_0055: ldloc.0
		/* 0x000057D6 02                 */ IL_0056: ldarg.0
		/* 0x000057D7 FE06D5000006       */ IL_0057: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::ModelPropertyChanged(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 060000D5 */
		/* 0x000057DD 730C01000A         */ IL_005d: newobj instance void [System]System.ComponentModel.PropertyChangedEventHandler::.ctor(object, native int) /* 0A00010C */
		/* 0x000057E2 6F0F01000A         */ IL_0062: callvirt instance void [System]System.ComponentModel.INotifyPropertyChanged::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler) /* 0A00010F */
		/* 0x000057E7 02                 */ IL_0067: ldarg.0
		/* 0x000057E8 28D6000006         */ IL_0068: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::ShowScreen() /* 060000D6 */
		/* 0x000057ED 2A                 */ IL_006d: ret
		/* 0x000057EE 02                 */ IL_006e: ldarg.0
		/* 0x000057EF 14                 */ IL_006f: ldnull
		/* 0x000057F0 280E01000A         */ IL_0070: call instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A00010E */
		/* 0x000057F5 2A                 */ IL_0075: ret
	} // end of method AssistantControl::set_Assistant

	.method /* 060000D2 */ assembly hidebysig specialname 
		instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel get_AssistantViewModel () cil managed 
	{
		// Method begins at RVA 0x5802
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00005802 02                 */ IL_0000: ldarg.0
		/* 0x00005803 280B01000A         */ IL_0001: call instance object [PresentationFramework]System.Windows.FrameworkElement::get_DataContext() /* 0A00010B */
		/* 0x00005808 740F000002         */ IL_0006: castclass AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel /* 0200000F */
		/* 0x0000580D 2A                 */ IL_000b: ret
	} // end of method AssistantControl::get_AssistantViewModel

	.method /* 060000D3 */ public hidebysig specialname 
		instance string get_CurrentScreen () cil managed 
	{
		// Method begins at RVA 0x580f
		// Header size: 1
		// Code size: 22 (0x16)
		.maxstack 8

		/* 0x0000580F 02                 */ IL_0000: ldarg.0
		/* 0x00005810 28D2000006         */ IL_0001: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x00005815 2D02               */ IL_0006: brtrue.s IL_000a
		/* 0x00005817 14                 */ IL_0008: ldnull
		/* 0x00005818 2A                 */ IL_0009: ret
		/* 0x00005819 02                 */ IL_000a: ldarg.0
		/* 0x0000581A 28D2000006         */ IL_000b: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x0000581F 6F5C000006         */ IL_0010: callvirt instance string AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_ScreenId() /* 0600005C */
		/* 0x00005824 2A                 */ IL_0015: ret
	} // end of method AssistantControl::get_CurrentScreen

	.method /* 060000D4 */ public hidebysig specialname 
		instance void set_CurrentScreen (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x5826
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00005826 02                 */ IL_0000: ldarg.0
		/* 0x00005827 28D2000006         */ IL_0001: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x0000582C 2C0C               */ IL_0006: brfalse.s IL_0014
		/* 0x0000582E 02                 */ IL_0008: ldarg.0
		/* 0x0000582F 28D2000006         */ IL_0009: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x00005834 03                 */ IL_000e: ldarg.1
		/* 0x00005835 6F5D000006         */ IL_000f: callvirt instance void AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::set_ScreenId(string) /* 0600005D */
		/* 0x0000583A 2A                 */ IL_0014: ret
	} // end of method AssistantControl::set_CurrentScreen

	.method /* 060000D5 */ private hidebysig 
		instance void ModelPropertyChanged (
			object sender,
			class [System]System.ComponentModel.PropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x583c
		// Header size: 12
		// Code size: 31 (0x1f)
		.maxstack 2
		.locals /* 11000009 */ init (
			[0] string
		)

		/* 0x0000583C 04                 */ IL_0000: ldarg.2
		/* 0x0000583D 6F1001000A         */ IL_0001: callvirt instance string [System]System.ComponentModel.PropertyChangedEventArgs::get_PropertyName() /* 0A000110 */
		/* 0x00005842 25                 */ IL_0006: dup
		/* 0x00005843 0A                 */ IL_0007: stloc.0
		/* 0x00005844 2C14               */ IL_0008: brfalse.s IL_001e
		/* 0x00005846 06                 */ IL_000a: ldloc.0
		/* 0x00005847 72D8040070         */ IL_000b: ldstr "Screen" /* 700004D8 */
		/* 0x0000584C 283F00000A         */ IL_0010: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
		/* 0x00005851 2D01               */ IL_0015: brtrue.s IL_0018
		/* 0x00005853 2A                 */ IL_0017: ret
		/* 0x00005854 02                 */ IL_0018: ldarg.0
		/* 0x00005855 28D6000006         */ IL_0019: call instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::ShowScreen() /* 060000D6 */
		/* 0x0000585A 2A                 */ IL_001e: ret
	} // end of method AssistantControl::ModelPropertyChanged

	.method /* 060000D6 */ private hidebysig 
		instance void ShowScreen () cil managed 
	{
		// Method begins at RVA 0x5868
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 2
		.locals /* 11000009 */ init (
			[0] string
		)

		/* 0x00005868 02                 */ IL_0000: ldarg.0
		/* 0x00005869 28D2000006         */ IL_0001: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x0000586E 16                 */ IL_0006: ldc.i4.0
		/* 0x0000586F 6F5E000006         */ IL_0007: callvirt instance string AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::RenderToHtml(valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget) /* 0600005E */
		/* 0x00005874 0A                 */ IL_000c: stloc.0
		/* 0x00005875 02                 */ IL_000d: ldarg.0
		/* 0x00005876 7B57000004         */ IL_000e: ldfld class [PresentationFramework]System.Windows.Controls.WebBrowser AspenTech.Visualisation.Controls.Assistant.AssistantControl::webBrowser /* 04000057 */
		/* 0x0000587B 06                 */ IL_0013: ldloc.0
		/* 0x0000587C 6F1101000A         */ IL_0014: callvirt instance void [PresentationFramework]System.Windows.Controls.WebBrowser::NavigateToString(string) /* 0A000111 */
		/* 0x00005881 2A                 */ IL_0019: ret
	} // end of method AssistantControl::ShowScreen

	.method /* 060000D7 */ private hidebysig 
		instance void webBrowser_Navigating (
			object sender,
			class [PresentationFramework]System.Windows.Navigation.NavigatingCancelEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x5890
		// Header size: 12
		// Code size: 88 (0x58)
		.maxstack 2
		.locals /* 11000035 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00005890 04                 */ IL_0000: ldarg.2
		/* 0x00005891 6F1201000A         */ IL_0001: callvirt instance class [System]System.Uri [PresentationFramework]System.Windows.Navigation.NavigatingCancelEventArgs::get_Uri() /* 0A000112 */
		/* 0x00005896 0A                 */ IL_0006: stloc.0
		/* 0x00005897 06                 */ IL_0007: ldloc.0
		/* 0x00005898 14                 */ IL_0008: ldnull
		/* 0x00005899 281301000A         */ IL_0009: call bool [System]System.Uri::op_Inequality(class [System]System.Uri, class [System]System.Uri) /* 0A000113 */
		/* 0x0000589E 2C47               */ IL_000e: brfalse.s IL_0057
		/* 0x000058A0 06                 */ IL_0010: ldloc.0
		/* 0x000058A1 6F1401000A         */ IL_0011: callvirt instance string [System]System.Uri::get_Scheme() /* 0A000114 */
		/* 0x000058A6 72AE0A0070         */ IL_0016: ldstr "assist" /* 70000AAE */
		/* 0x000058AB 283F00000A         */ IL_001b: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003F */
		/* 0x000058B0 2C35               */ IL_0020: brfalse.s IL_0057
		/* 0x000058B2 02                 */ IL_0022: ldarg.0
		/* 0x000058B3 28D2000006         */ IL_0023: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x000058B8 6F62000006         */ IL_0028: callvirt instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_SelectCommand() /* 06000062 */
		/* 0x000058BD 06                 */ IL_002d: ldloc.0
		/* 0x000058BE 6F6000000A         */ IL_002e: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x000058C3 6F1501000A         */ IL_0033: callvirt instance bool [PresentationCore]System.Windows.Input.ICommand::CanExecute(object) /* 0A000115 */
		/* 0x000058C8 2C16               */ IL_0038: brfalse.s IL_0050
		/* 0x000058CA 02                 */ IL_003a: ldarg.0
		/* 0x000058CB 28D2000006         */ IL_003b: call instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel() /* 060000D2 */
		/* 0x000058D0 6F62000006         */ IL_0040: callvirt instance class [PresentationCore]System.Windows.Input.ICommand AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel::get_SelectCommand() /* 06000062 */
		/* 0x000058D5 06                 */ IL_0045: ldloc.0
		/* 0x000058D6 6F6000000A         */ IL_0046: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000060 */
		/* 0x000058DB 6F1601000A         */ IL_004b: callvirt instance void [PresentationCore]System.Windows.Input.ICommand::Execute(object) /* 0A000116 */
		/* 0x000058E0 04                 */ IL_0050: ldarg.2
		/* 0x000058E1 17                 */ IL_0051: ldc.i4.1
		/* 0x000058E2 6F1701000A         */ IL_0052: callvirt instance void [System]System.ComponentModel.CancelEventArgs::set_Cancel(bool) /* 0A000117 */
		/* 0x000058E7 2A                 */ IL_0057: ret
	} // end of method AssistantControl::webBrowser_Navigating

	.method /* 060000D8 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00009D */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x58f4
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 3
		.locals /* 11000035 */ init (
			[0] class [System]System.Uri
		)

		/* 0x000058F4 02                 */ IL_0000: ldarg.0
		/* 0x000058F5 7B58000004         */ IL_0001: ldfld bool AspenTech.Visualisation.Controls.Assistant.AssistantControl::_contentLoaded /* 04000058 */
		/* 0x000058FA 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x000058FC 2A                 */ IL_0008: ret
		/* 0x000058FD 02                 */ IL_0009: ldarg.0
		/* 0x000058FE 17                 */ IL_000a: ldc.i4.1
		/* 0x000058FF 7D58000004         */ IL_000b: stfld bool AspenTech.Visualisation.Controls.Assistant.AssistantControl::_contentLoaded /* 04000058 */
		/* 0x00005904 72BC0A0070         */ IL_0010: ldstr "/AspenTech.Visualisation.Controls.Assistant.W1;component/controls/assistantcontrol.xaml" /* 70000ABC */
		/* 0x00005909 18                 */ IL_0015: ldc.i4.2
		/* 0x0000590A 730401000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A000104 */
		/* 0x0000590F 0A                 */ IL_001b: stloc.0
		/* 0x00005910 02                 */ IL_001c: ldarg.0
		/* 0x00005911 06                 */ IL_001d: ldloc.0
		/* 0x00005912 280501000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000105 */
		/* 0x00005917 2A                 */ IL_0023: ret
	} // end of method AssistantControl::InitializeComponent

	.method /* 060000D9 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C00009E */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.custom /* 0C00009F */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x5924
		// Header size: 12
		// Code size: 50 (0x32)
		.maxstack 4
		.locals /* 1100002E */ init (
			[0] int32
		)

		/* 0x00005924 03                 */ IL_0000: ldarg.1
		/* 0x00005925 0A                 */ IL_0001: stloc.0
		/* 0x00005926 06                 */ IL_0002: ldloc.0
		/* 0x00005927 17                 */ IL_0003: ldc.i4.1
		/* 0x00005928 3324               */ IL_0004: bne.un.s IL_002a
		/* 0x0000592A 02                 */ IL_0006: ldarg.0
		/* 0x0000592B 04                 */ IL_0007: ldarg.2
		/* 0x0000592C 7424000001         */ IL_0008: castclass [PresentationFramework]System.Windows.Controls.WebBrowser /* 01000024 */
		/* 0x00005931 7D57000004         */ IL_000d: stfld class [PresentationFramework]System.Windows.Controls.WebBrowser AspenTech.Visualisation.Controls.Assistant.AssistantControl::webBrowser /* 04000057 */
		/* 0x00005936 02                 */ IL_0012: ldarg.0
		/* 0x00005937 7B57000004         */ IL_0013: ldfld class [PresentationFramework]System.Windows.Controls.WebBrowser AspenTech.Visualisation.Controls.Assistant.AssistantControl::webBrowser /* 04000057 */
		/* 0x0000593C 02                 */ IL_0018: ldarg.0
		/* 0x0000593D FE06D7000006       */ IL_0019: ldftn instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::webBrowser_Navigating(object, class [PresentationFramework]System.Windows.Navigation.NavigatingCancelEventArgs) /* 060000D7 */
		/* 0x00005943 731801000A         */ IL_001f: newobj instance void [PresentationFramework]System.Windows.Navigation.NavigatingCancelEventHandler::.ctor(object, native int) /* 0A000118 */
		/* 0x00005948 6F1901000A         */ IL_0024: callvirt instance void [PresentationFramework]System.Windows.Controls.WebBrowser::add_Navigating(class [PresentationFramework]System.Windows.Navigation.NavigatingCancelEventHandler) /* 0A000119 */
		/* 0x0000594D 2A                 */ IL_0029: ret
		/* 0x0000594E 02                 */ IL_002a: ldarg.0
		/* 0x0000594F 17                 */ IL_002b: ldc.i4.1
		/* 0x00005950 7D58000004         */ IL_002c: stfld bool AspenTech.Visualisation.Controls.Assistant.AssistantControl::_contentLoaded /* 04000058 */
		/* 0x00005955 2A                 */ IL_0031: ret
	} // end of method AssistantControl::System.Windows.Markup.IComponentConnector.Connect

	// Properties
	.property /* 17000039 */ instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot Assistant()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.AssistRoot AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_Assistant()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::set_Assistant(class AspenTech.Visualisation.Controls.Assistant.AssistRoot)
	}
	.property /* 1700003A */ instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AssistantViewModel()
	{
		.get instance class AspenTech.Visualisation.Controls.Assistant.IAssistantViewModel AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_AssistantViewModel()
	}
	.property /* 1700003B */ instance string CurrentScreen()
	{
		.get instance string AspenTech.Visualisation.Controls.Assistant.AssistantControl::get_CurrentScreen()
		.set instance void AspenTech.Visualisation.Controls.Assistant.AssistantControl::set_CurrentScreen(string)
	}

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistantControl

.class /* 0200001F */ private auto ansi sealed AspenTech.Visualisation.Controls.Assistant.RenderTarget
	extends [mscorlib]System.Enum
{
	// Fields
	.field /* 04000059 */ public specialname rtspecialname int32 value__
	.field /* 0400005A */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget Screen = int32(0)
	.field /* 0400005B */ public static literal valuetype AspenTech.Visualisation.Controls.Assistant.RenderTarget Report = int32(1)

} // end of class AspenTech.Visualisation.Controls.Assistant.RenderTarget

.class /* 02000020 */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.BoolOpacityConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IValueConverter
{
	// Methods
	.method /* 060000DA */ public final hidebysig newslot virtual 
		instance object Convert (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x5962
		// Header size: 1
		// Code size: 25 (0x19)
		.maxstack 8

		/* 0x00005962 03                 */ IL_0000: ldarg.1
		/* 0x00005963 A590000001         */ IL_0001: unbox.any [mscorlib]System.Boolean /* 01000090 */
		/* 0x00005968 2C0F               */ IL_0006: brfalse.s IL_0017
		/* 0x0000596A 23000000000000F03F */ IL_0008: ldc.r8 1
		/* 0x00005973 8C91000001         */ IL_0011: box [mscorlib]System.Double /* 01000091 */
		/* 0x00005978 2A                 */ IL_0016: ret
		/* 0x00005979 05                 */ IL_0017: ldarg.3
		/* 0x0000597A 2A                 */ IL_0018: ret
	} // end of method BoolOpacityConverter::Convert

	.method /* 060000DB */ public final hidebysig newslot virtual 
		instance object ConvertBack (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x597c
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x0000597C 731A01000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A00011A */
		/* 0x00005981 7A                 */ IL_0005: throw
	} // end of method BoolOpacityConverter::ConvertBack

	.method /* 060000DC */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x5983
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00005983 02                 */ IL_0000: ldarg.0
		/* 0x00005984 284800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000048 */
		/* 0x00005989 2A                 */ IL_0006: ret
	} // end of method BoolOpacityConverter::.ctor

} // end of class AspenTech.Visualisation.Controls.Assistant.BoolOpacityConverter

.class /* 02000021 */ private auto ansi abstract sealed beforefieldinit AspenTech.Visualisation.Controls.Assistant.XmlConstants
	extends [mscorlib]System.Object
{
	// Nested Types
	.class /* 02000022 */ nested assembly auto ansi abstract sealed beforefieldinit Elements
		extends [mscorlib]System.Object
	{
		// Fields
		.field /* 0400005D */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Assistant
		.field /* 0400005E */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Caption
		.field /* 0400005F */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Author
		.field /* 04000060 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Action
		.field /* 04000061 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Explanation
		.field /* 04000062 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Screen
		.field /* 04000063 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Option
		.field /* 04000064 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName First
		.field /* 04000065 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName BuildDate
		.field /* 04000066 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Copyright
		.field /* 04000067 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Modifier
		.field /* 04000068 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Version
		.field /* 04000069 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Notes
		.field /* 0400006A */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Translations
		.field /* 0400006B */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Translation

		// Methods
		.method /* 060000DE */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x599c
			// Header size: 12
			// Code size: 281 (0x119)
			.maxstack 2

			/* 0x0000599C 7E5C000004         */ IL_0000: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x000059A1 726F0B0070         */ IL_0005: ldstr "ASSISTANT" /* 70000B6F */
			/* 0x000059A6 281C01000A         */ IL_000a: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x000059AB 805D000004         */ IL_000f: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Assistant /* 0400005D */
			/* 0x000059B0 7E5C000004         */ IL_0014: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x000059B5 72830B0070         */ IL_0019: ldstr "CAPTION" /* 70000B83 */
			/* 0x000059BA 281C01000A         */ IL_001e: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x000059BF 805E000004         */ IL_0023: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Caption /* 0400005E */
			/* 0x000059C4 7E5C000004         */ IL_0028: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x000059C9 72930B0070         */ IL_002d: ldstr "AUTHOR" /* 70000B93 */
			/* 0x000059CE 281C01000A         */ IL_0032: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x000059D3 805F000004         */ IL_0037: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Author /* 0400005F */
			/* 0x000059D8 7E5C000004         */ IL_003c: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x000059DD 72A10B0070         */ IL_0041: ldstr "ACTION" /* 70000BA1 */
			/* 0x000059E2 281C01000A         */ IL_0046: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x000059E7 8060000004         */ IL_004b: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Action /* 04000060 */
			/* 0x000059EC 7E5C000004         */ IL_0050: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x000059F1 72AF0B0070         */ IL_0055: ldstr "DESCRIPTION" /* 70000BAF */
			/* 0x000059F6 281C01000A         */ IL_005a: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x000059FB 8061000004         */ IL_005f: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Explanation /* 04000061 */
			/* 0x00005A00 7E5C000004         */ IL_0064: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x00005A05 72C70B0070         */ IL_0069: ldstr "SCREEN" /* 70000BC7 */
			/* 0x00005A0A 281C01000A         */ IL_006e: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x00005A0F 8062000004         */ IL_0073: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Screen /* 04000062 */
			/* 0x00005A14 7E5C000004         */ IL_0078: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x00005A19 72D50B0070         */ IL_007d: ldstr "OPTION" /* 70000BD5 */
			/* 0x00005A1E 281C01000A         */ IL_0082: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x00005A23 8063000004         */ IL_0087: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Option /* 04000063 */
			/* 0x00005A28 7E5C000004         */ IL_008c: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x00005A2D 72E30B0070         */ IL_0091: ldstr "FIRST" /* 70000BE3 */
			/* 0x00005A32 281C01000A         */ IL_0096: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x00005A37 8064000004         */ IL_009b: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::First /* 04000064 */
			/* 0x00005A3C 7E5C000004         */ IL_00a0: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x00005A41 72EF0B0070         */ IL_00a5: ldstr "BUILDDATE" /* 70000BEF */
			/* 0x00005A46 281C01000A         */ IL_00aa: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x00005A4B 8065000004         */ IL_00af: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::BuildDate /* 04000065 */
			/* 0x00005A50 7E5C000004         */ IL_00b4: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x00005A55 72030C0070         */ IL_00b9: ldstr "COPYRIGHT" /* 70000C03 */
			/* 0x00005A5A 281C01000A         */ IL_00be: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x00005A5F 8066000004         */ IL_00c3: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Copyright /* 04000066 */
			/* 0x00005A64 7E5C000004         */ IL_00c8: ldsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
			/* 0x00005A69 72170C0070         */ IL_00cd: ldstr "MODIFIER" /* 70000C17 */
			/* 0x00005A6E 281C01000A         */ IL_00d2: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Addition(class [System.Xml.Linq]System.Xml.Linq.XNamespace, string) /* 0A00011C */
			/* 0x00005A73 8067000004         */ IL_00d7: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Modifier /* 04000067 */
			/* 0x00005A78 72290C0070         */ IL_00dc: ldstr "VERSION" /* 70000C29 */
			/* 0x00005A7D 281D01000A         */ IL_00e1: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005A82 8068000004         */ IL_00e6: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Version /* 04000068 */
			/* 0x00005A87 72390C0070         */ IL_00eb: ldstr "NOTES" /* 70000C39 */
			/* 0x00005A8C 281D01000A         */ IL_00f0: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005A91 8069000004         */ IL_00f5: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Notes /* 04000069 */
			/* 0x00005A96 72450C0070         */ IL_00fa: ldstr "TRANSLATIONS" /* 70000C45 */
			/* 0x00005A9B 281D01000A         */ IL_00ff: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005AA0 806A000004         */ IL_0104: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Translations /* 0400006A */
			/* 0x00005AA5 725F0C0070         */ IL_0109: ldstr "ITEM" /* 70000C5F */
			/* 0x00005AAA 281D01000A         */ IL_010e: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005AAF 806B000004         */ IL_0113: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Elements::Translation /* 0400006B */
			/* 0x00005AB4 2A                 */ IL_0118: ret
		} // end of method Elements::.cctor

	} // end of class Elements

	.class /* 02000023 */ nested assembly auto ansi abstract sealed beforefieldinit Attributes
		extends [mscorlib]System.Object
	{
		// Fields
		.field /* 0400006C */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Id
		.field /* 0400006D */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Code
		.field /* 0400006E */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Command
		.field /* 0400006F */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName ActionType
		.field /* 04000070 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Version
		.field /* 04000071 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName Backwards
		.field /* 04000072 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName NoteName
		.field /* 04000073 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName NoteType
		.field /* 04000074 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName NoteId
		.field /* 04000075 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName TranslationKey
		.field /* 04000076 */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XName TranslationValue

		// Methods
		.method /* 060000DF */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x5ac4
			// Header size: 12
			// Code size: 166 (0xa6)
			.maxstack 1

			/* 0x00005AC4 72690C0070         */ IL_0000: ldstr "NAME" /* 70000C69 */
			/* 0x00005AC9 281D01000A         */ IL_0005: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005ACE 806C000004         */ IL_000a: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Id /* 0400006C */
			/* 0x00005AD3 72730C0070         */ IL_000f: ldstr "CODE" /* 70000C73 */
			/* 0x00005AD8 281D01000A         */ IL_0014: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005ADD 806D000004         */ IL_0019: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Code /* 0400006D */
			/* 0x00005AE2 727D0C0070         */ IL_001e: ldstr "COMMAND" /* 70000C7D */
			/* 0x00005AE7 281D01000A         */ IL_0023: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005AEC 806E000004         */ IL_0028: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Command /* 0400006E */
			/* 0x00005AF1 728D0C0070         */ IL_002d: ldstr "TYPE" /* 70000C8D */
			/* 0x00005AF6 281D01000A         */ IL_0032: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005AFB 806F000004         */ IL_0037: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::ActionType /* 0400006F */
			/* 0x00005B00 72290C0070         */ IL_003c: ldstr "VERSION" /* 70000C29 */
			/* 0x00005B05 281D01000A         */ IL_0041: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B0A 8070000004         */ IL_0046: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Version /* 04000070 */
			/* 0x00005B0F 72970C0070         */ IL_004b: ldstr "BACKWARDS" /* 70000C97 */
			/* 0x00005B14 281D01000A         */ IL_0050: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B19 8071000004         */ IL_0055: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::Backwards /* 04000071 */
			/* 0x00005B1E 72690C0070         */ IL_005a: ldstr "NAME" /* 70000C69 */
			/* 0x00005B23 281D01000A         */ IL_005f: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B28 8072000004         */ IL_0064: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::NoteName /* 04000072 */
			/* 0x00005B2D 728D0C0070         */ IL_0069: ldstr "TYPE" /* 70000C8D */
			/* 0x00005B32 281D01000A         */ IL_006e: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B37 8073000004         */ IL_0073: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::NoteType /* 04000073 */
			/* 0x00005B3C 72AB0C0070         */ IL_0078: ldstr "ID" /* 70000CAB */
			/* 0x00005B41 281D01000A         */ IL_007d: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B46 8074000004         */ IL_0082: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::NoteId /* 04000074 */
			/* 0x00005B4B 72B10C0070         */ IL_0087: ldstr "KEY" /* 70000CB1 */
			/* 0x00005B50 281D01000A         */ IL_008c: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B55 8075000004         */ IL_0091: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::TranslationKey /* 04000075 */
			/* 0x00005B5A 7285080070         */ IL_0096: ldstr "TEXT" /* 70000885 */
			/* 0x00005B5F 281D01000A         */ IL_009b: call class [System.Xml.Linq]System.Xml.Linq.XName [System.Xml.Linq]System.Xml.Linq.XName::op_Implicit(string) /* 0A00011D */
			/* 0x00005B64 8076000004         */ IL_00a0: stsfld class [System.Xml.Linq]System.Xml.Linq.XName AspenTech.Visualisation.Controls.Assistant.XmlConstants/Attributes::TranslationValue /* 04000076 */
			/* 0x00005B69 2A                 */ IL_00a5: ret
		} // end of method Attributes::.cctor

	} // end of class Attributes


	// Fields
	.field /* 0400005C */ assembly static initonly class [System.Xml.Linq]System.Xml.Linq.XNamespace Namespace

	// Methods
	.method /* 060000DD */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x598b
		// Header size: 1
		// Code size: 16 (0x10)
		.maxstack 8

		/* 0x0000598B 726D0B0070         */ IL_0000: ldstr "" /* 70000B6D */
		/* 0x00005990 281B01000A         */ IL_0005: call class [System.Xml.Linq]System.Xml.Linq.XNamespace [System.Xml.Linq]System.Xml.Linq.XNamespace::op_Implicit(string) /* 0A00011B */
		/* 0x00005995 805C000004         */ IL_000a: stsfld class [System.Xml.Linq]System.Xml.Linq.XNamespace AspenTech.Visualisation.Controls.Assistant.XmlConstants::Namespace /* 0400005C */
		/* 0x0000599A 2A                 */ IL_000f: ret
	} // end of method XmlConstants::.cctor

} // end of class AspenTech.Visualisation.Controls.Assistant.XmlConstants

.class /* 02000024 */ private auto ansi abstract sealed beforefieldinit AspenTech.Visualisation.Controls.Assistant.Constants
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000077 */ assembly static initonly string AssistantExtension
	.field /* 04000078 */ assembly static initonly string AssistantExtensionExtended
	.field /* 04000079 */ assembly static int32 VersionBack
	.field /* 0400007A */ assembly static int32 VersionNow

	// Methods
	.method /* 060000E0 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x5b76
		// Header size: 1
		// Code size: 33 (0x21)
		.maxstack 8

		/* 0x00005B76 72B90C0070         */ IL_0000: ldstr "amf" /* 70000CB9 */
		/* 0x00005B7B 8077000004         */ IL_0005: stsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtension /* 04000077 */
		/* 0x00005B80 72C10C0070         */ IL_000a: ldstr "amfx" /* 70000CC1 */
		/* 0x00005B85 8078000004         */ IL_000f: stsfld string AspenTech.Visualisation.Controls.Assistant.Constants::AssistantExtensionExtended /* 04000078 */
		/* 0x00005B8A 16                 */ IL_0014: ldc.i4.0
		/* 0x00005B8B 8079000004         */ IL_0015: stsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionBack /* 04000079 */
		/* 0x00005B90 18                 */ IL_001a: ldc.i4.2
		/* 0x00005B91 807A000004         */ IL_001b: stsfld int32 AspenTech.Visualisation.Controls.Assistant.Constants::VersionNow /* 0400007A */
		/* 0x00005B96 2A                 */ IL_0020: ret
	} // end of method Constants::.cctor

} // end of class AspenTech.Visualisation.Controls.Assistant.Constants

.class /* 02000025 */ public auto ansi beforefieldinit AspenTech.Visualisation.Controls.Assistant.AssistOptions
	extends class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>
{
	// Methods
	.method /* 060000E1 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x5b98
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00005B98 02                 */ IL_0000: ldarg.0
		/* 0x00005B99 281E01000A         */ IL_0001: call instance void class [mscorlib]System.Collections.Generic.List`1<class AspenTech.Visualisation.Controls.Assistant.AssistOption>::.ctor() /* 0A00011E */
		/* 0x00005B9E 2A                 */ IL_0006: ret
	} // end of method AssistOptions::.ctor

} // end of class AspenTech.Visualisation.Controls.Assistant.AssistOptions

.class /* 02000026 */ interface public auto ansi abstract import ASPENABOUTBOXLib.AspenAboutBox
	implements ASPENABOUTBOXLib.IAspenAboutBox
{
	.custom /* 0C000030 */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000031 */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 37 30 42 42 41 33 39 34 2d 34 46 33 38
		2d 34 32 31 41 2d 42 44 42 34 2d 38 39 44 30 32
		32 41 32 35 31 35 41 00 00
	)
	.custom /* 0C000032 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000033 */ instance void [mscorlib]System.Runtime.InteropServices.CoClassAttribute::.ctor(class [mscorlib]System.Type) = (
		01 00 5a 53 79 73 74 65 6d 2e 4f 62 6a 65 63 74
		2c 20 6d 73 63 6f 72 6c 69 62 2c 20 56 65 72 73
		69 6f 6e 3d 34 2e 30 2e 30 2e 30 2c 20 43 75 6c
		74 75 72 65 3d 6e 65 75 74 72 61 6c 2c 20 50 75
		62 6c 69 63 4b 65 79 54 6f 6b 65 6e 3d 62 37 37
		61 35 63 35 36 31 39 33 34 65 30 38 39 00 00
	)
} // end of class ASPENABOUTBOXLib.AspenAboutBox

.class /* 02000027 */ interface public auto ansi abstract import ASPENABOUTBOXLib.IAspenAboutBox
{
	.custom /* 0C000034 */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 37 30 42 42 41 33 39 34 2d 34 46 33 38
		2d 34 32 31 41 2d 42 44 42 34 2d 38 39 44 30 32
		32 41 32 35 31 35 41 00 00
	)
	.custom /* 0C000035 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000036 */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 060000E2 */ public hidebysig newslot abstract virtual 
		instance void Show () cil managed 
	{
		.custom /* 0C0000A0 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 01 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::Show

	.method /* 060000E3 */ public hidebysig specialname newslot abstract virtual 
		instance string marshal(bstr) get_AppName () cil managed 
	{
		.custom /* 0C0000A1 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 02 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::get_AppName

	.method /* 060000E4 */ public hidebysig specialname newslot abstract virtual 
		instance void set_AppName (
			[in] string marshal(bstr) pVal
		) cil managed 
	{
		.custom /* 0C0000A2 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 02 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::set_AppName

	.method /* 060000E5 */ public hidebysig specialname newslot abstract virtual 
		instance string marshal(bstr) get_AppCopyright () cil managed 
	{
		.custom /* 0C0000A3 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 03 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::get_AppCopyright

	.method /* 060000E6 */ public hidebysig specialname newslot abstract virtual 
		instance void set_AppCopyright (
			[in] string marshal(bstr) pVal
		) cil managed 
	{
		.custom /* 0C0000A4 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 03 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::set_AppCopyright

	.method /* 060000E7 */ public hidebysig specialname newslot abstract virtual 
		instance string marshal(bstr) get_BeginCopyDate () cil managed 
	{
		.custom /* 0C0000A5 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 04 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::get_BeginCopyDate

	.method /* 060000E8 */ public hidebysig specialname newslot abstract virtual 
		instance void set_BeginCopyDate (
			[in] string marshal(bstr) pVal
		) cil managed 
	{
		.custom /* 0C0000A6 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 04 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::set_BeginCopyDate

	.method /* 060000E9 */ public hidebysig specialname newslot abstract virtual 
		instance string marshal(bstr) get_EndCopyDate () cil managed 
	{
		.custom /* 0C0000A7 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 05 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::get_EndCopyDate

	.method /* 060000EA */ public hidebysig specialname newslot abstract virtual 
		instance void set_EndCopyDate (
			[in] string marshal(bstr) pVal
		) cil managed 
	{
		.custom /* 0C0000A8 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 05 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::set_EndCopyDate

	.method /* 060000EB */ public hidebysig specialname newslot abstract virtual 
		instance string marshal(bstr) get_AppVersion () cil managed 
	{
		.custom /* 0C0000A9 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 06 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::get_AppVersion

	.method /* 060000EC */ public hidebysig specialname newslot abstract virtual 
		instance void set_AppVersion (
			[in] string marshal(bstr) pVal
		) cil managed 
	{
		.custom /* 0C0000AA */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 06 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::set_AppVersion

	.method /* 060000ED */ public hidebysig specialname newslot abstract virtual 
		instance string marshal(bstr) get_ExternalVersion () cil managed 
	{
		.custom /* 0C0000AB */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 07 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::get_ExternalVersion

	.method /* 060000EE */ public hidebysig specialname newslot abstract virtual 
		instance void set_ExternalVersion (
			[in] string marshal(bstr) pVal
		) cil managed 
	{
		.custom /* 0C0000AC */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 07 00 00 00 00 00
		)
	} // end of method IAspenAboutBox::set_ExternalVersion

	// Properties
	.property /* 1700003C */ instance string AppName()
	{
		.get instance string ASPENABOUTBOXLib.IAspenAboutBox::get_AppName()
		.set instance void ASPENABOUTBOXLib.IAspenAboutBox::set_AppName(string)
	}
	.property /* 1700003D */ instance string AppCopyright()
	{
		.get instance string ASPENABOUTBOXLib.IAspenAboutBox::get_AppCopyright()
		.set instance void ASPENABOUTBOXLib.IAspenAboutBox::set_AppCopyright(string)
	}
	.property /* 1700003E */ instance string BeginCopyDate()
	{
		.get instance string ASPENABOUTBOXLib.IAspenAboutBox::get_BeginCopyDate()
		.set instance void ASPENABOUTBOXLib.IAspenAboutBox::set_BeginCopyDate(string)
	}
	.property /* 1700003F */ instance string EndCopyDate()
	{
		.get instance string ASPENABOUTBOXLib.IAspenAboutBox::get_EndCopyDate()
		.set instance void ASPENABOUTBOXLib.IAspenAboutBox::set_EndCopyDate(string)
	}
	.property /* 17000040 */ instance string AppVersion()
	{
		.get instance string ASPENABOUTBOXLib.IAspenAboutBox::get_AppVersion()
		.set instance void ASPENABOUTBOXLib.IAspenAboutBox::set_AppVersion(string)
	}
	.property /* 17000041 */ instance string ExternalVersion()
	{
		.get instance string ASPENABOUTBOXLib.IAspenAboutBox::get_ExternalVersion()
		.set instance void ASPENABOUTBOXLib.IAspenAboutBox::set_ExternalVersion(string)
	}

} // end of class ASPENABOUTBOXLib.IAspenAboutBox

.class /* 02000028 */ interface public auto ansi abstract import ASPENSPLASHLib.SplashWindow
	implements ASPENSPLASHLib.ISplashWindow
{
	.custom /* 0C000038 */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 35 45 43 35 45 42 34 32 2d 31 33 45 33
		2d 31 31 44 33 2d 38 34 30 44 2d 30 30 30 30 30
		30 30 30 30 30 30 30 00 00
	)
	.custom /* 0C000039 */ instance void [mscorlib]System.Runtime.InteropServices.CoClassAttribute::.ctor(class [mscorlib]System.Type) = (
		01 00 5a 53 79 73 74 65 6d 2e 4f 62 6a 65 63 74
		2c 20 6d 73 63 6f 72 6c 69 62 2c 20 56 65 72 73
		69 6f 6e 3d 34 2e 30 2e 30 2e 30 2c 20 43 75 6c
		74 75 72 65 3d 6e 65 75 74 72 61 6c 2c 20 50 75
		62 6c 69 63 4b 65 79 54 6f 6b 65 6e 3d 62 37 37
		61 35 63 35 36 31 39 33 34 65 30 38 39 00 00
	)
	.custom /* 0C00003A */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C00003B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
} // end of class ASPENSPLASHLib.SplashWindow

.class /* 02000029 */ interface public auto ansi abstract import ASPENSPLASHLib.ISplashWindow
{
	.custom /* 0C00003D */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C00003E */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 35 45 43 35 45 42 34 32 2d 31 33 45 33
		2d 31 31 44 33 2d 38 34 30 44 2d 30 30 30 30 30
		30 30 30 30 30 30 30 00 00
	)
	.custom /* 0C00003F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 060000EF */ public specialname rtspecialname 
		instance void _VtblGap1_9 () cil managed 
	{
	} // end of method ISplashWindow::_VtblGap1_9

	.method /* 060000F0 */ public hidebysig newslot abstract virtual 
		instance void ShowSplash2 (
			[in] string marshal(bstr) bstrTitle,
			[in] string marshal(bstr) bstrSubtitle,
			[in] string marshal(bstr) bstrVersion,
			[in] int16 nCopyrightFrom,
			[in] int16 nCopyrightTo,
			[in] string marshal(bstr) bstrLicensee
		) cil managed 
	{
		.custom /* 0C0000AD */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 0a 00 00 00 00 00
		)
	} // end of method ISplashWindow::ShowSplash2

} // end of class ASPENSPLASHLib.ISplashWindow

