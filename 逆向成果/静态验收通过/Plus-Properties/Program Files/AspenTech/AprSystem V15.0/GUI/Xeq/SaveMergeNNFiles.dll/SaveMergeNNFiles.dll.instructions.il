.module SaveMergeNNFiles.dll
// MVID: {CB3671D4-0C0E-4414-9DE8-925DAB81DB3F}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi abstract sealed beforefieldinit AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles
	extends [mscorlib]System.Object
{
	// Nested Types
	.class /* 02000003 */ nested private auto ansi sealed serializable beforefieldinit '<>c'
		extends [mscorlib]System.Object
	{
		.custom /* 0C00000F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 04000001 */ public static initonly class AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c' '<>9'
		.field /* 04000002 */ public static class [mscorlib]System.Func`2<string, string> '<>9__0_0'

		// Methods
		.method /* 06000004 */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x21cc
			// Header size: 1
			// Code size: 11 (0xb)
			.maxstack 8

			/* 0x000021CC 7305000006         */ IL_0000: newobj instance void AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c'::.ctor() /* 06000005 */
			/* 0x000021D1 8001000004         */ IL_0005: stsfld class AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c' AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c'::'<>9' /* 04000001 */
			/* 0x000021D6 2A                 */ IL_000a: ret
		} // end of method '<>c'::.cctor

		.method /* 06000005 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x21d8
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x000021D8 02                 */ IL_0000: ldarg.0
			/* 0x000021D9 282800000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000028 */
			/* 0x000021DE 2A                 */ IL_0006: ret
		} // end of method '<>c'::.ctor

		.method /* 06000006 */ assembly hidebysig 
			instance string '<CSharpSaveMergennFiles>b__0_0' (
				string t
			) cil managed 
		{
			// Method begins at RVA 0x21e0
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x000021E0 03                 */ IL_0000: ldarg.1
			/* 0x000021E1 6F2900000A         */ IL_0001: callvirt instance string [mscorlib]System.String::Trim() /* 0A000029 */
			/* 0x000021E6 2A                 */ IL_0006: ret
		} // end of method '<>c'::'<CSharpSaveMergennFiles>b__0_0'

	} // end of class <>c


	// Methods
	.method /* 06000001 */ public hidebysig static 
		void CSharpSaveMergennFiles (
			string filename,
			string values
		) cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 12
		// Code size: 67 (0x43)
		.maxstack 5
		.locals /* 11000001 */ init (
			[0] class [mscorlib]System.Collections.Generic.List`1<string>
		)

		/* 0x00002050 03                 */ IL_0000: ldarg.1
		/* 0x00002051 17                 */ IL_0001: ldc.i4.1
		/* 0x00002052 8D18000001         */ IL_0002: newarr [mscorlib]System.Char /* 01000018 */
		/* 0x00002057 25                 */ IL_0007: dup
		/* 0x00002058 16                 */ IL_0008: ldc.i4.0
		/* 0x00002059 1F2C               */ IL_0009: ldc.i4.s 44
		/* 0x0000205B 9D                 */ IL_000b: stelem.i2
		/* 0x0000205C 6F1000000A         */ IL_000c: callvirt instance string[] [mscorlib]System.String::Split(char[]) /* 0A000010 */
		/* 0x00002061 7E02000004         */ IL_0011: ldsfld class [mscorlib]System.Func`2<string, string> AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c'::'<>9__0_0' /* 04000002 */
		/* 0x00002066 25                 */ IL_0016: dup
		/* 0x00002067 2D17               */ IL_0017: brtrue.s IL_0030
		/* 0x00002069 26                 */ IL_0019: pop
		/* 0x0000206A 7E01000004         */ IL_001a: ldsfld class AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c' AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c'::'<>9' /* 04000001 */
		/* 0x0000206F FE0606000006       */ IL_001f: ldftn instance string AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c'::'<CSharpSaveMergennFiles>b__0_0'(string) /* 06000006 */
		/* 0x00002075 731100000A         */ IL_0025: newobj instance void class [mscorlib]System.Func`2<string, string>::.ctor(object, native int) /* 0A000011 */
		/* 0x0000207A 25                 */ IL_002a: dup
		/* 0x0000207B 8002000004         */ IL_002b: stsfld class [mscorlib]System.Func`2<string, string> AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles/'<>c'::'<>9__0_0' /* 04000002 */
		/* 0x00002080 280100002B         */ IL_0030: call class [mscorlib]System.Collections.Generic.IEnumerable`1<!!1> [System.Core]System.Linq.Enumerable::Select<string, string>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>, class [mscorlib]System.Func`2<!!0, !!1>) /* 2B000001 */
		/* 0x00002085 280200002B         */ IL_0035: call class [mscorlib]System.Collections.Generic.List`1<!!0> [System.Core]System.Linq.Enumerable::ToList<string>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000002 */
		/* 0x0000208A 0A                 */ IL_003a: stloc.0
		/* 0x0000208B 02                 */ IL_003b: ldarg.0
		/* 0x0000208C 06                 */ IL_003c: ldloc.0
		/* 0x0000208D 2802000006         */ IL_003d: call void AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles::SaveFiles(string, class [mscorlib]System.Collections.Generic.List`1<string>) /* 06000002 */
		/* 0x00002092 2A                 */ IL_0042: ret
	} // end of method SaveMergeNNFiles::CSharpSaveMergennFiles

	.method /* 06000002 */ private hidebysig static 
		void SaveFiles (
			string fileName,
			class [mscorlib]System.Collections.Generic.List`1<string> mergennFileNames
		) cil managed 
	{
		// Method begins at RVA 0x20a0
		// Header size: 12
		// Code size: 189 (0xbd)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [mscorlib]System.Text.StringBuilder,
			[1] valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<string>,
			[2] string,
			[3] class [mscorlib]System.IO.StreamReader
		)

		/* 0x000020A0 02                 */ IL_0000: ldarg.0
		/* 0x000020A1 281400000A         */ IL_0001: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000014 */
		/* 0x000020A6 39B1000000         */ IL_0006: brfalse IL_00bc
		/* 0x000020AB 03                 */ IL_000b: ldarg.1
		/* 0x000020AC 39AB000000         */ IL_000c: brfalse IL_00bc
		/* 0x000020B1 14                 */ IL_0011: ldnull
		/* 0x000020B2 0A                 */ IL_0012: stloc.0
		/* 0x000020B3 03                 */ IL_0013: ldarg.1
		/* 0x000020B4 6F1500000A         */ IL_0014: callvirt instance valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<!0> class [mscorlib]System.Collections.Generic.List`1<string>::GetEnumerator() /* 0A000015 */
		/* 0x000020B9 0B                 */ IL_0019: stloc.1
		/* 0x000020BA 2B6E               */ IL_001a: br.s IL_008a
		/* 0x000020BC 1201               */ IL_001c: ldloca.s 1
		/* 0x000020BE 281600000A         */ IL_001e: call instance !0 valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<string>::get_Current() /* 0A000016 */
		/* 0x000020C3 0C                 */ IL_0023: stloc.2
		/* 0x000020C4 08                 */ IL_0024: ldloc.2
		/* 0x000020C5 281400000A         */ IL_0025: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000014 */
		/* 0x000020CA 2D07               */ IL_002a: brtrue.s IL_0033
		/* 0x000020CC 08                 */ IL_002c: ldloc.2
		/* 0x000020CD 281700000A         */ IL_002d: call string [mscorlib]System.IO.Path::GetFileName(string) /* 0A000017 */
		/* 0x000020D2 0C                 */ IL_0032: stloc.2
		/* 0x000020D3 08                 */ IL_0033: ldloc.2
		/* 0x000020D4 281400000A         */ IL_0034: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000014 */
		/* 0x000020D9 2D18               */ IL_0039: brtrue.s IL_0053
		/* 0x000020DB 1F1C               */ IL_003b: ldc.i4.s 28
		/* 0x000020DD 281800000A         */ IL_003d: call string [mscorlib]System.Environment::GetFolderPath(valuetype [mscorlib]System.Environment/SpecialFolder) /* 0A000018 */
		/* 0x000020E2 7201000070         */ IL_0042: ldstr "\\AspenTech\\AIModeling\\MergeNNFiles" /* 70000001 */
		/* 0x000020E7 281900000A         */ IL_0047: call string [mscorlib]System.String::Concat(string, string) /* 0A000019 */
		/* 0x000020EC 08                 */ IL_004c: ldloc.2
		/* 0x000020ED 281A00000A         */ IL_004d: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A00001A */
		/* 0x000020F2 0C                 */ IL_0052: stloc.2
		/* 0x000020F3 08                 */ IL_0053: ldloc.2
		/* 0x000020F4 281400000A         */ IL_0054: call bool [mscorlib]System.IO.File::Exists(string) /* 0A000014 */
		/* 0x000020F9 2C2F               */ IL_0059: brfalse.s IL_008a
		/* 0x000020FB 06                 */ IL_005b: ldloc.0
		/* 0x000020FC 2D25               */ IL_005c: brtrue.s IL_0083
		/* 0x000020FE 731B00000A         */ IL_005e: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A00001B */
		/* 0x00002103 0A                 */ IL_0063: stloc.0
		/* 0x00002104 02                 */ IL_0064: ldarg.0
		/* 0x00002105 281C00000A         */ IL_0065: call class [mscorlib]System.Text.Encoding [mscorlib]System.Text.Encoding::get_Default() /* 0A00001C */
		/* 0x0000210A 731D00000A         */ IL_006a: newobj instance void [mscorlib]System.IO.StreamReader::.ctor(string, class [mscorlib]System.Text.Encoding) /* 0A00001D */
		/* 0x0000210F 0D                 */ IL_006f: stloc.3
		/* 0x00002110 06                 */ IL_0070: ldloc.0
		/* 0x00002111 09                 */ IL_0071: ldloc.3
		/* 0x00002112 6F1E00000A         */ IL_0072: callvirt instance string [mscorlib]System.IO.TextReader::ReadToEnd() /* 0A00001E */
		/* 0x00002117 6F1F00000A         */ IL_0077: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A00001F */
		/* 0x0000211C 26                 */ IL_007c: pop
		/* 0x0000211D 09                 */ IL_007d: ldloc.3
		/* 0x0000211E 6F2000000A         */ IL_007e: callvirt instance void [mscorlib]System.IO.TextReader::Close() /* 0A000020 */
		/* 0x00002123 06                 */ IL_0083: ldloc.0
		/* 0x00002124 08                 */ IL_0084: ldloc.2
		/* 0x00002125 2803000006         */ IL_0085: call void AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles::AddFnnFile(class [mscorlib]System.Text.StringBuilder, string) /* 06000003 */
		/* 0x0000212A 1201               */ IL_008a: ldloca.s 1
		/* 0x0000212C 282100000A         */ IL_008c: call instance bool valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<string>::MoveNext() /* 0A000021 */
		/* 0x00002131 2D89               */ IL_0091: brtrue.s IL_001c
		/* 0x00002133 DE0E               */ IL_0093: leave.s IL_00a3
		/* 0x00002135 1201               */ IL_0095: ldloca.s 1
		/* 0x00002137 FE160300001B       */ IL_0097: constrained. valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<string> /* 1B000003 */
		/* 0x0000213D 6F2200000A         */ IL_009d: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000022 */
		/* 0x00002142 DC                 */ IL_00a2: endfinally
		/* 0x00002143 06                 */ IL_00a3: ldloc.0
		/* 0x00002144 2C11               */ IL_00a4: brfalse.s IL_00b7
		/* 0x00002146 02                 */ IL_00a6: ldarg.0
		/* 0x00002147 06                 */ IL_00a7: ldloc.0
		/* 0x00002148 6F2300000A         */ IL_00a8: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000023 */
		/* 0x0000214D 281C00000A         */ IL_00ad: call class [mscorlib]System.Text.Encoding [mscorlib]System.Text.Encoding::get_Default() /* 0A00001C */
		/* 0x00002152 282400000A         */ IL_00b2: call void [mscorlib]System.IO.File::WriteAllText(string, string, class [mscorlib]System.Text.Encoding) /* 0A000024 */
		/* 0x00002157 DE03               */ IL_00b7: leave.s IL_00bc
		/* 0x00002159 26                 */ IL_00b9: pop
		/* 0x0000215A DE00               */ IL_00ba: leave.s IL_00bc
		/* 0x0000215C 2A                 */ IL_00bc: ret

		.try IL_001a-IL_0095 finally IL_0095-IL_00a3
		.try IL_0011-IL_00b9 catch [mscorlib]System.Exception IL_00b9-IL_00bc
	} // end of method SaveMergeNNFiles::SaveFiles

	.method /* 06000003 */ private hidebysig static 
		void AddFnnFile (
			class [mscorlib]System.Text.StringBuilder sb,
			string fnnFile
		) cil managed 
	{
		// Method begins at RVA 0x2188
		// Header size: 12
		// Code size: 56 (0x38)
		.maxstack 4
		.locals /* 11000003 */ init (
			[0] string
		)

		/* 0x00002188 02                 */ IL_0000: ldarg.0
		/* 0x00002189 7247000070         */ IL_0001: ldstr "$_FNN_FILE " /* 70000047 */
		/* 0x0000218E 03                 */ IL_0006: ldarg.1
		/* 0x0000218F 725F000070         */ IL_0007: ldstr "\r\n" /* 7000005F */
		/* 0x00002194 282500000A         */ IL_000c: call string [mscorlib]System.String::Concat(string, string, string) /* 0A000025 */
		/* 0x00002199 6F1F00000A         */ IL_0011: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A00001F */
		/* 0x0000219E 26                 */ IL_0016: pop
		/* 0x0000219F 03                 */ IL_0017: ldarg.1
		/* 0x000021A0 282600000A         */ IL_0018: call uint8[] [mscorlib]System.IO.File::ReadAllBytes(string) /* 0A000026 */
		/* 0x000021A5 282700000A         */ IL_001d: call string [mscorlib]System.Convert::ToBase64String(uint8[]) /* 0A000027 */
		/* 0x000021AA 0A                 */ IL_0022: stloc.0
		/* 0x000021AB 02                 */ IL_0023: ldarg.0
		/* 0x000021AC 06                 */ IL_0024: ldloc.0
		/* 0x000021AD 6F1F00000A         */ IL_0025: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A00001F */
		/* 0x000021B2 26                 */ IL_002a: pop
		/* 0x000021B3 02                 */ IL_002b: ldarg.0
		/* 0x000021B4 7265000070         */ IL_002c: ldstr "\r\n$_END_FNN_FILE\r\n" /* 70000065 */
		/* 0x000021B9 6F1F00000A         */ IL_0031: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A00001F */
		/* 0x000021BE 26                 */ IL_0036: pop
		/* 0x000021BF 2A                 */ IL_0037: ret
	} // end of method SaveMergeNNFiles::AddFnnFile

} // end of class AspenTech.AspenPlus.SaveMergeNNFiles.SaveMergeNNFiles

