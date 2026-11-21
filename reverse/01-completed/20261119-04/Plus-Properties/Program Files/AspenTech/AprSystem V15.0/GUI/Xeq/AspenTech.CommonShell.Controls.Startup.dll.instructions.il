.module AspenTech.CommonShell.Controls.Startup.dll
// MVID: {9AE11808-5243-4721-A1B0-C78D5BE6CE88}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000009 // ILOnly, StrongNameSigned
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi abstract sealed beforefieldinit AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions
	extends [mscorlib]System.Object
{
	.custom /* 0C000013 */ instance void [mscorlib]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
		01 00 00 00
	)
	// Nested Types
	.class /* 02000011 */ nested private auto ansi sealed serializable beforefieldinit '<>c'
		extends [mscorlib]System.Object
	{
		.custom /* 0C000020 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 04000028 */ public static initonly class AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c' '<>9'
		.field /* 04000029 */ public static class [mscorlib]System.Func`2<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl, bool> '<>9__0_0'

		// Methods
		.method /* 06000072 */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x3154
			// Header size: 1
			// Code size: 11 (0xb)
			.maxstack 8

			/* 0x00003154 7373000006         */ IL_0000: newobj instance void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c'::.ctor() /* 06000073 */
			/* 0x00003159 8028000004         */ IL_0005: stsfld class AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c' AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c'::'<>9' /* 04000028 */
			/* 0x0000315E 2A                 */ IL_000a: ret
		} // end of method '<>c'::.cctor

		.method /* 06000073 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x3160
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003160 02                 */ IL_0000: ldarg.0
			/* 0x00003161 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
			/* 0x00003166 2A                 */ IL_0006: ret
		} // end of method '<>c'::.ctor

		.method /* 06000074 */ assembly hidebysig 
			instance bool '<ShowStartupDialog>b__0_0' (
				class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl x
			) cil managed 
		{
			// Method begins at RVA 0x3168
			// Header size: 1
			// Code size: 2 (0x2)
			.maxstack 8

			/* 0x00003168 17                 */ IL_0000: ldc.i4.1
			/* 0x00003169 2A                 */ IL_0001: ret
		} // end of method '<>c'::'<ShowStartupDialog>b__0_0'

	} // end of class <>c

	.class /* 02000012 */ nested private auto ansi sealed beforefieldinit '<GetLoadedStartupDialogs>d__5'
		extends [mscorlib]System.Object
		implements class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog>,
		           [mscorlib]System.Collections.IEnumerable,
		           class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog>,
		           [mscorlib]System.IDisposable,
		           [mscorlib]System.Collections.IEnumerator
	{
		.custom /* 0C000021 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 0400002A */ private int32 '<>1__state'
		.field /* 0400002B */ private class AspenTech.CommonShell.Controls.Startup.StartupDialog '<>2__current'
		.field /* 0400002C */ private int32 '<>l__initialThreadId'
		.field /* 0400002D */ private class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow window
		.field /* 0400002E */ public class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow '<>3__window'
		.field /* 0400002F */ private class [mscorlib]System.Collections.IEnumerator '<>7__wrap1'

		// Methods
		.method /* 06000075 */ public hidebysig specialname rtspecialname 
			instance void .ctor (
				int32 '<>1__state'
			) cil managed 
		{
			.custom /* 0C00003C */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x316b
			// Header size: 1
			// Code size: 25 (0x19)
			.maxstack 8

			/* 0x0000316B 02                 */ IL_0000: ldarg.0
			/* 0x0000316C 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
			/* 0x00003171 02                 */ IL_0006: ldarg.0
			/* 0x00003172 03                 */ IL_0007: ldarg.1
			/* 0x00003173 7D2A000004         */ IL_0008: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x00003178 02                 */ IL_000d: ldarg.0
			/* 0x00003179 287600000A         */ IL_000e: call int32 [mscorlib]System.Environment::get_CurrentManagedThreadId() /* 0A000076 */
			/* 0x0000317E 7D2C000004         */ IL_0013: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>l__initialThreadId' /* 0400002C */
			/* 0x00003183 2A                 */ IL_0018: ret
		} // end of method '<GetLoadedStartupDialogs>d__5'::.ctor

		.method /* 06000076 */ private final hidebysig newslot virtual 
			instance void System.IDisposable.Dispose () cil managed 
		{
			.custom /* 0C00003D */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance void [mscorlib]System.IDisposable::Dispose()
			// Method begins at RVA 0x3188
			// Header size: 12
			// Code size: 27 (0x1b)
			.maxstack 2
			.locals /* 1100000F */ init (
				[0] int32
			)

			/* 0x00003188 02                 */ IL_0000: ldarg.0
			/* 0x00003189 7B2A000004         */ IL_0001: ldfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x0000318E 0A                 */ IL_0006: stloc.0
			/* 0x0000318F 06                 */ IL_0007: ldloc.0
			/* 0x00003190 1FFD               */ IL_0008: ldc.i4.s -3
			/* 0x00003192 2E04               */ IL_000a: beq.s IL_0010
			/* 0x00003194 06                 */ IL_000c: ldloc.0
			/* 0x00003195 17                 */ IL_000d: ldc.i4.1
			/* 0x00003196 330A               */ IL_000e: bne.un.s IL_001a
			/* 0x00003198 00                 */ IL_0010: nop
			/* 0x00003199 DE07               */ IL_0011: leave.s IL_001a
			/* 0x0000319B 02                 */ IL_0013: ldarg.0
			/* 0x0000319C 2878000006         */ IL_0014: call instance void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>m__Finally1'() /* 06000078 */
			/* 0x000031A1 DC                 */ IL_0019: endfinally
			/* 0x000031A2 2A                 */ IL_001a: ret

			.try IL_0011-IL_0013 finally IL_0013-IL_001a
		} // end of method '<GetLoadedStartupDialogs>d__5'::System.IDisposable.Dispose

		.method /* 06000077 */ private final hidebysig newslot virtual 
			instance bool MoveNext () cil managed 
		{
			.override method instance bool [mscorlib]System.Collections.IEnumerator::MoveNext()
			// Method begins at RVA 0x31c0
			// Header size: 12
			// Code size: 178 (0xb2)
			.maxstack 2
			.locals /* 11000010 */ init (
				[0] bool,
				[1] int32,
				[2] class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow,
				[3] class [PresentationFramework]System.Windows.Controls.Grid,
				[4] class AspenTech.CommonShell.Controls.Startup.StartupDialog
			)

			/* 0x000031C0 02                 */ IL_0000: ldarg.0
			/* 0x000031C1 7B2A000004         */ IL_0001: ldfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x000031C6 0B                 */ IL_0006: stloc.1
			/* 0x000031C7 07                 */ IL_0007: ldloc.1
			/* 0x000031C8 2C0B               */ IL_0008: brfalse.s IL_0015
			/* 0x000031CA 07                 */ IL_000a: ldloc.1
			/* 0x000031CB 17                 */ IL_000b: ldc.i4.1
			/* 0x000031CC 2E75               */ IL_000c: beq.s IL_0083
			/* 0x000031CE 16                 */ IL_000e: ldc.i4.0
			/* 0x000031CF 0A                 */ IL_000f: stloc.0
			/* 0x000031D0 DD9B000000         */ IL_0010: leave IL_00b0
			/* 0x000031D5 02                 */ IL_0015: ldarg.0
			/* 0x000031D6 15                 */ IL_0016: ldc.i4.m1
			/* 0x000031D7 7D2A000004         */ IL_0017: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x000031DC 02                 */ IL_001c: ldarg.0
			/* 0x000031DD 7B2D000004         */ IL_001d: ldfld class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::window /* 0400002D */
			/* 0x000031E2 7514000001         */ IL_0022: isinst [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow /* 01000014 */
			/* 0x000031E7 0C                 */ IL_0027: stloc.2
			/* 0x000031E8 08                 */ IL_0028: ldloc.2
			/* 0x000031E9 2C7A               */ IL_0029: brfalse.s IL_00a5
			/* 0x000031EB 08                 */ IL_002b: ldloc.2
			/* 0x000031EC 6F1E00000A         */ IL_002c: callvirt instance class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow::get_ScreenManager() /* 0A00001E */
			/* 0x000031F1 6F2400000A         */ IL_0031: callvirt instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::get_Parent() /* 0A000024 */
			/* 0x000031F6 7516000001         */ IL_0036: isinst [PresentationFramework]System.Windows.Controls.Grid /* 01000016 */
			/* 0x000031FB 0D                 */ IL_003b: stloc.3
			/* 0x000031FC 09                 */ IL_003c: ldloc.3
			/* 0x000031FD 2C66               */ IL_003d: brfalse.s IL_00a5
			/* 0x000031FF 02                 */ IL_003f: ldarg.0
			/* 0x00003200 09                 */ IL_0040: ldloc.3
			/* 0x00003201 6F2700000A         */ IL_0041: callvirt instance class [PresentationFramework]System.Windows.Controls.UIElementCollection [PresentationFramework]System.Windows.Controls.Panel::get_Children() /* 0A000027 */
			/* 0x00003206 6F7700000A         */ IL_0046: callvirt instance class [mscorlib]System.Collections.IEnumerator [PresentationFramework]System.Windows.Controls.UIElementCollection::GetEnumerator() /* 0A000077 */
			/* 0x0000320B 7D2F000004         */ IL_004b: stfld class [mscorlib]System.Collections.IEnumerator AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>7__wrap1' /* 0400002F */
			/* 0x00003210 02                 */ IL_0050: ldarg.0
			/* 0x00003211 1FFD               */ IL_0051: ldc.i4.s -3
			/* 0x00003213 7D2A000004         */ IL_0053: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x00003218 2B31               */ IL_0058: br.s IL_008b
			/* 0x0000321A 02                 */ IL_005a: ldarg.0
			/* 0x0000321B 7B2F000004         */ IL_005b: ldfld class [mscorlib]System.Collections.IEnumerator AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>7__wrap1' /* 0400002F */
			/* 0x00003220 6F1600000A         */ IL_0060: callvirt instance object [mscorlib]System.Collections.IEnumerator::get_Current() /* 0A000016 */
			/* 0x00003225 7503000002         */ IL_0065: isinst AspenTech.CommonShell.Controls.Startup.StartupDialog /* 02000003 */
			/* 0x0000322A 1304               */ IL_006a: stloc.s 4
			/* 0x0000322C 1104               */ IL_006c: ldloc.s 4
			/* 0x0000322E 2C1B               */ IL_006e: brfalse.s IL_008b
			/* 0x00003230 02                 */ IL_0070: ldarg.0
			/* 0x00003231 1104               */ IL_0071: ldloc.s 4
			/* 0x00003233 7D2B000004         */ IL_0073: stfld class AspenTech.CommonShell.Controls.Startup.StartupDialog AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>2__current' /* 0400002B */
			/* 0x00003238 02                 */ IL_0078: ldarg.0
			/* 0x00003239 17                 */ IL_0079: ldc.i4.1
			/* 0x0000323A 7D2A000004         */ IL_007a: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x0000323F 17                 */ IL_007f: ldc.i4.1
			/* 0x00003240 0A                 */ IL_0080: stloc.0
			/* 0x00003241 DE2D               */ IL_0081: leave.s IL_00b0
			/* 0x00003243 02                 */ IL_0083: ldarg.0
			/* 0x00003244 1FFD               */ IL_0084: ldc.i4.s -3
			/* 0x00003246 7D2A000004         */ IL_0086: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x0000324B 02                 */ IL_008b: ldarg.0
			/* 0x0000324C 7B2F000004         */ IL_008c: ldfld class [mscorlib]System.Collections.IEnumerator AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>7__wrap1' /* 0400002F */
			/* 0x00003251 6F1300000A         */ IL_0091: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000013 */
			/* 0x00003256 2DC2               */ IL_0096: brtrue.s IL_005a
			/* 0x00003258 02                 */ IL_0098: ldarg.0
			/* 0x00003259 2878000006         */ IL_0099: call instance void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>m__Finally1'() /* 06000078 */
			/* 0x0000325E 02                 */ IL_009e: ldarg.0
			/* 0x0000325F 14                 */ IL_009f: ldnull
			/* 0x00003260 7D2F000004         */ IL_00a0: stfld class [mscorlib]System.Collections.IEnumerator AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>7__wrap1' /* 0400002F */
			/* 0x00003265 16                 */ IL_00a5: ldc.i4.0
			/* 0x00003266 0A                 */ IL_00a6: stloc.0
			/* 0x00003267 DE07               */ IL_00a7: leave.s IL_00b0
			/* 0x00003269 02                 */ IL_00a9: ldarg.0
			/* 0x0000326A 2876000006         */ IL_00aa: call instance void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::System.IDisposable.Dispose() /* 06000076 */
			/* 0x0000326F DC                 */ IL_00af: endfinally
			/* 0x00003270 06                 */ IL_00b0: ldloc.0
			/* 0x00003271 2A                 */ IL_00b1: ret

			.try IL_0000-IL_00a9 fault IL_00a9-IL_00b0
		} // end of method '<GetLoadedStartupDialogs>d__5'::MoveNext

		.method /* 06000078 */ private hidebysig 
			instance void '<>m__Finally1' () cil managed 
		{
			// Method begins at RVA 0x3290
			// Header size: 12
			// Code size: 29 (0x1d)
			.maxstack 2
			.locals /* 11000011 */ init (
				[0] class [mscorlib]System.IDisposable
			)

			/* 0x00003290 02                 */ IL_0000: ldarg.0
			/* 0x00003291 15                 */ IL_0001: ldc.i4.m1
			/* 0x00003292 7D2A000004         */ IL_0002: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x00003297 02                 */ IL_0007: ldarg.0
			/* 0x00003298 7B2F000004         */ IL_0008: ldfld class [mscorlib]System.Collections.IEnumerator AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>7__wrap1' /* 0400002F */
			/* 0x0000329D 751F000001         */ IL_000d: isinst [mscorlib]System.IDisposable /* 0100001F */
			/* 0x000032A2 0A                 */ IL_0012: stloc.0
			/* 0x000032A3 06                 */ IL_0013: ldloc.0
			/* 0x000032A4 2C06               */ IL_0014: brfalse.s IL_001c
			/* 0x000032A6 06                 */ IL_0016: ldloc.0
			/* 0x000032A7 6F1200000A         */ IL_0017: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000012 */
			/* 0x000032AC 2A                 */ IL_001c: ret
		} // end of method '<GetLoadedStartupDialogs>d__5'::'<>m__Finally1'

		.method /* 06000079 */ private final hidebysig specialname newslot virtual 
			instance class AspenTech.CommonShell.Controls.Startup.StartupDialog 'System.Collections.Generic.IEnumerator<AspenTech.CommonShell.Controls.Startup.StartupDialog>.get_Current' () cil managed 
		{
			.custom /* 0C00003E */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog>::get_Current()
			// Method begins at RVA 0x32b9
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x000032B9 02                 */ IL_0000: ldarg.0
			/* 0x000032BA 7B2B000004         */ IL_0001: ldfld class AspenTech.CommonShell.Controls.Startup.StartupDialog AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>2__current' /* 0400002B */
			/* 0x000032BF 2A                 */ IL_0006: ret
		} // end of method '<GetLoadedStartupDialogs>d__5'::'System.Collections.Generic.IEnumerator<AspenTech.CommonShell.Controls.Startup.StartupDialog>.get_Current'

		.method /* 0600007A */ private final hidebysig newslot virtual 
			instance void System.Collections.IEnumerator.Reset () cil managed 
		{
			.custom /* 0C00003F */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance void [mscorlib]System.Collections.IEnumerator::Reset()
			// Method begins at RVA 0x32c1
			// Header size: 1
			// Code size: 6 (0x6)
			.maxstack 8

			/* 0x000032C1 737800000A         */ IL_0000: newobj instance void [mscorlib]System.NotSupportedException::.ctor() /* 0A000078 */
			/* 0x000032C6 7A                 */ IL_0005: throw
		} // end of method '<GetLoadedStartupDialogs>d__5'::System.Collections.IEnumerator.Reset

		.method /* 0600007B */ private final hidebysig specialname newslot virtual 
			instance object System.Collections.IEnumerator.get_Current () cil managed 
		{
			.custom /* 0C000040 */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance object [mscorlib]System.Collections.IEnumerator::get_Current()
			// Method begins at RVA 0x32c8
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x000032C8 02                 */ IL_0000: ldarg.0
			/* 0x000032C9 7B2B000004         */ IL_0001: ldfld class AspenTech.CommonShell.Controls.Startup.StartupDialog AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>2__current' /* 0400002B */
			/* 0x000032CE 2A                 */ IL_0006: ret
		} // end of method '<GetLoadedStartupDialogs>d__5'::System.Collections.IEnumerator.get_Current

		.method /* 0600007C */ private final hidebysig newslot virtual 
			instance class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog> 'System.Collections.Generic.IEnumerable<AspenTech.CommonShell.Controls.Startup.StartupDialog>.GetEnumerator' () cil managed 
		{
			.custom /* 0C000041 */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog>::GetEnumerator()
			// Method begins at RVA 0x32d0
			// Header size: 12
			// Code size: 55 (0x37)
			.maxstack 2
			.locals /* 11000012 */ init (
				[0] class AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'
			)

			/* 0x000032D0 02                 */ IL_0000: ldarg.0
			/* 0x000032D1 7B2A000004         */ IL_0001: ldfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x000032D6 1FFE               */ IL_0006: ldc.i4.s -2
			/* 0x000032D8 3318               */ IL_0008: bne.un.s IL_0022
			/* 0x000032DA 02                 */ IL_000a: ldarg.0
			/* 0x000032DB 7B2C000004         */ IL_000b: ldfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>l__initialThreadId' /* 0400002C */
			/* 0x000032E0 287600000A         */ IL_0010: call int32 [mscorlib]System.Environment::get_CurrentManagedThreadId() /* 0A000076 */
			/* 0x000032E5 330B               */ IL_0015: bne.un.s IL_0022
			/* 0x000032E7 02                 */ IL_0017: ldarg.0
			/* 0x000032E8 16                 */ IL_0018: ldc.i4.0
			/* 0x000032E9 7D2A000004         */ IL_0019: stfld int32 AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>1__state' /* 0400002A */
			/* 0x000032EE 02                 */ IL_001e: ldarg.0
			/* 0x000032EF 0A                 */ IL_001f: stloc.0
			/* 0x000032F0 2B07               */ IL_0020: br.s IL_0029
			/* 0x000032F2 16                 */ IL_0022: ldc.i4.0
			/* 0x000032F3 7375000006         */ IL_0023: newobj instance void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::.ctor(int32) /* 06000075 */
			/* 0x000032F8 0A                 */ IL_0028: stloc.0
			/* 0x000032F9 06                 */ IL_0029: ldloc.0
			/* 0x000032FA 02                 */ IL_002a: ldarg.0
			/* 0x000032FB 7B2E000004         */ IL_002b: ldfld class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>3__window' /* 0400002E */
			/* 0x00003300 7D2D000004         */ IL_0030: stfld class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::window /* 0400002D */
			/* 0x00003305 06                 */ IL_0035: ldloc.0
			/* 0x00003306 2A                 */ IL_0036: ret
		} // end of method '<GetLoadedStartupDialogs>d__5'::'System.Collections.Generic.IEnumerable<AspenTech.CommonShell.Controls.Startup.StartupDialog>.GetEnumerator'

		.method /* 0600007D */ private final hidebysig newslot virtual 
			instance class [mscorlib]System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator () cil managed 
		{
			.custom /* 0C000042 */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance class [mscorlib]System.Collections.IEnumerator [mscorlib]System.Collections.IEnumerable::GetEnumerator()
			// Method begins at RVA 0x3313
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003313 02                 */ IL_0000: ldarg.0
			/* 0x00003314 287C000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog> AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'System.Collections.Generic.IEnumerable<AspenTech.CommonShell.Controls.Startup.StartupDialog>.GetEnumerator'() /* 0600007C */
			/* 0x00003319 2A                 */ IL_0006: ret
		} // end of method '<GetLoadedStartupDialogs>d__5'::System.Collections.IEnumerable.GetEnumerator

		// Properties
		.property /* 17000026 */ instance class AspenTech.CommonShell.Controls.Startup.StartupDialog 'System.Collections.Generic.IEnumerator<AspenTech.CommonShell.Controls.Startup.StartupDialog>.Current'()
		{
			.get instance class AspenTech.CommonShell.Controls.Startup.StartupDialog AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'System.Collections.Generic.IEnumerator<AspenTech.CommonShell.Controls.Startup.StartupDialog>.get_Current'()
		}
		.property /* 17000027 */ instance object System.Collections.IEnumerator.Current()
		{
			.get instance object AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::System.Collections.IEnumerator.get_Current()
		}

	} // end of class <GetLoadedStartupDialogs>d__5


	// Methods
	.method /* 06000001 */ public hidebysig static 
		void ShowStartupDialog (
			class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow window,
			class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions options,
			[opt] bool keepOpenedScreens
		) cil managed 
	{
		.custom /* 0C000001 */ instance void [mscorlib]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		.param [3] = bool(false)
		// Method begins at RVA 0x2050
		// Header size: 12
		// Code size: 143 (0x8f)
		.maxstack 5
		.locals /* 11000001 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow,
			[1] class AspenTech.CommonShell.Controls.Startup.StartupDialog,
			[2] class AspenTech.CommonShell.Controls.Startup.StartupDialog
		)

		/* 0x00002050 02                 */ IL_0000: ldarg.0
		/* 0x00002051 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x00002053 7201000070         */ IL_0003: ldstr "window" /* 70000001 */
		/* 0x00002058 731D00000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x0000205D 7A                 */ IL_000d: throw
		/* 0x0000205E 03                 */ IL_000e: ldarg.1
		/* 0x0000205F 2D0B               */ IL_000f: brtrue.s IL_001c
		/* 0x00002061 720F000070         */ IL_0011: ldstr "options" /* 7000000F */
		/* 0x00002066 731D00000A         */ IL_0016: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x0000206B 7A                 */ IL_001b: throw
		/* 0x0000206C 02                 */ IL_001c: ldarg.0
		/* 0x0000206D 7514000001         */ IL_001d: isinst [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow /* 01000014 */
		/* 0x00002072 0A                 */ IL_0022: stloc.0
		/* 0x00002073 06                 */ IL_0023: ldloc.0
		/* 0x00002074 2C68               */ IL_0024: brfalse.s IL_008e
		/* 0x00002076 04                 */ IL_0026: ldarg.2
		/* 0x00002077 2D33               */ IL_0027: brtrue.s IL_005c
		/* 0x00002079 06                 */ IL_0029: ldloc.0
		/* 0x0000207A 6F1E00000A         */ IL_002a: callvirt instance class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow::get_ScreenManager() /* 0A00001E */
		/* 0x0000207F 25                 */ IL_002f: dup
		/* 0x00002080 2D03               */ IL_0030: brtrue.s IL_0035
		/* 0x00002082 26                 */ IL_0032: pop
		/* 0x00002083 2B27               */ IL_0033: br.s IL_005c
		/* 0x00002085 7E29000004         */ IL_0035: ldsfld class [mscorlib]System.Func`2<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl, bool> AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c'::'<>9__0_0' /* 04000029 */
		/* 0x0000208A 25                 */ IL_003a: dup
		/* 0x0000208B 2D17               */ IL_003b: brtrue.s IL_0054
		/* 0x0000208D 26                 */ IL_003d: pop
		/* 0x0000208E 7E28000004         */ IL_003e: ldsfld class AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c' AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c'::'<>9' /* 04000028 */
		/* 0x00002093 FE0674000006       */ IL_0043: ldftn instance bool AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c'::'<ShowStartupDialog>b__0_0'(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl) /* 06000074 */
		/* 0x00002099 731F00000A         */ IL_0049: newobj instance void class [mscorlib]System.Func`2<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl, bool>::.ctor(object, native int) /* 0A00001F */
		/* 0x0000209E 25                 */ IL_004e: dup
		/* 0x0000209F 8029000004         */ IL_004f: stsfld class [mscorlib]System.Func`2<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl, bool> AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<>c'::'<>9__0_0' /* 04000029 */
		/* 0x000020A4 14                 */ IL_0054: ldnull
		/* 0x000020A5 16                 */ IL_0055: ldc.i4.0
		/* 0x000020A6 16                 */ IL_0056: ldc.i4.0
		/* 0x000020A7 282000000A         */ IL_0057: call instance void [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager::CloseScreens(class [mscorlib]System.Func`2<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl, bool>, class [System]System.ComponentModel.CancelEventArgs, bool, bool) /* 0A000020 */
		/* 0x000020AC 02                 */ IL_005c: ldarg.0
		/* 0x000020AD 2806000006         */ IL_005d: call class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog> AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::GetLoadedStartupDialogs(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow) /* 06000006 */
		/* 0x000020B2 280100002B         */ IL_0062: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.CommonShell.Controls.Startup.StartupDialog>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000001 */
		/* 0x000020B7 0B                 */ IL_0067: stloc.1
		/* 0x000020B8 07                 */ IL_0068: ldloc.1
		/* 0x000020B9 2D15               */ IL_0069: brtrue.s IL_0080
		/* 0x000020BB 730B000006         */ IL_006b: newobj instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::.ctor() /* 0600000B */
		/* 0x000020C0 25                 */ IL_0070: dup
		/* 0x000020C1 03                 */ IL_0071: ldarg.1
		/* 0x000020C2 6F08000006         */ IL_0072: callvirt instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::set_Options(class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions) /* 06000008 */
		/* 0x000020C7 0C                 */ IL_0077: stloc.2
		/* 0x000020C8 06                 */ IL_0078: ldloc.0
		/* 0x000020C9 08                 */ IL_0079: ldloc.2
		/* 0x000020CA 2804000006         */ IL_007a: call void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::DisplayStartupDialog(class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow, class AspenTech.CommonShell.Controls.Startup.StartupDialog) /* 06000004 */
		/* 0x000020CF 2A                 */ IL_007f: ret
		/* 0x000020D0 07                 */ IL_0080: ldloc.1
		/* 0x000020D1 03                 */ IL_0081: ldarg.1
		/* 0x000020D2 6F08000006         */ IL_0082: callvirt instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::set_Options(class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions) /* 06000008 */
		/* 0x000020D7 06                 */ IL_0087: ldloc.0
		/* 0x000020D8 07                 */ IL_0088: ldloc.1
		/* 0x000020D9 2804000006         */ IL_0089: call void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::DisplayStartupDialog(class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow, class AspenTech.CommonShell.Controls.Startup.StartupDialog) /* 06000004 */
		/* 0x000020DE 2A                 */ IL_008e: ret
	} // end of method CommonShellWindowExtensions::ShowStartupDialog

	.method /* 06000002 */ public hidebysig static 
		void CloseStartupDialog (
			class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow window
		) cil managed 
	{
		.custom /* 0C000011 */ instance void [mscorlib]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x20ec
		// Header size: 12
		// Code size: 43 (0x2b)
		.maxstack 2
		.locals /* 11000002 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow
		)

		/* 0x000020EC 02                 */ IL_0000: ldarg.0
		/* 0x000020ED 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x000020EF 7201000070         */ IL_0003: ldstr "window" /* 70000001 */
		/* 0x000020F4 731D00000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x000020F9 7A                 */ IL_000d: throw
		/* 0x000020FA 02                 */ IL_000e: ldarg.0
		/* 0x000020FB 7514000001         */ IL_000f: isinst [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow /* 01000014 */
		/* 0x00002100 0A                 */ IL_0014: stloc.0
		/* 0x00002101 06                 */ IL_0015: ldloc.0
		/* 0x00002102 2C12               */ IL_0016: brfalse.s IL_002a
		/* 0x00002104 06                 */ IL_0018: ldloc.0
		/* 0x00002105 2805000006         */ IL_0019: call void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::RemoveStartupDialog(class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow) /* 06000005 */
		/* 0x0000210A 06                 */ IL_001e: ldloc.0
		/* 0x0000210B 6F1E00000A         */ IL_001f: callvirt instance class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow::get_ScreenManager() /* 0A00001E */
		/* 0x00002110 16                 */ IL_0024: ldc.i4.0
		/* 0x00002111 6F2200000A         */ IL_0025: callvirt instance void [PresentationCore]System.Windows.UIElement::set_Visibility(valuetype [PresentationCore]System.Windows.Visibility) /* 0A000022 */
		/* 0x00002116 2A                 */ IL_002a: ret
	} // end of method CommonShellWindowExtensions::CloseStartupDialog

	.method /* 06000003 */ public hidebysig static 
		bool IsStartupDialogLoaded (
			class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow window
		) cil managed 
	{
		.custom /* 0C000014 */ instance void [mscorlib]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2123
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00002123 02                 */ IL_0000: ldarg.0
		/* 0x00002124 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x00002126 7201000070         */ IL_0003: ldstr "window" /* 70000001 */
		/* 0x0000212B 731D00000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x00002130 7A                 */ IL_000d: throw
		/* 0x00002131 02                 */ IL_000e: ldarg.0
		/* 0x00002132 2806000006         */ IL_000f: call class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog> AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::GetLoadedStartupDialogs(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow) /* 06000006 */
		/* 0x00002137 280200002B         */ IL_0014: call bool [System.Core]System.Linq.Enumerable::Any<class AspenTech.CommonShell.Controls.Startup.StartupDialog>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000002 */
		/* 0x0000213C 2A                 */ IL_0019: ret
	} // end of method CommonShellWindowExtensions::IsStartupDialogLoaded

	.method /* 06000004 */ private hidebysig static 
		void DisplayStartupDialog (
			class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow csw,
			class AspenTech.CommonShell.Controls.Startup.StartupDialog dialog
		) cil managed 
	{
		// Method begins at RVA 0x2140
		// Header size: 12
		// Code size: 62 (0x3e)
		.maxstack 2
		.locals /* 11000003 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager,
			[1] class [PresentationFramework]System.Windows.Controls.Grid
		)

		/* 0x00002140 02                 */ IL_0000: ldarg.0
		/* 0x00002141 6F1E00000A         */ IL_0001: callvirt instance class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow::get_ScreenManager() /* 0A00001E */
		/* 0x00002146 0A                 */ IL_0006: stloc.0
		/* 0x00002147 06                 */ IL_0007: ldloc.0
		/* 0x00002148 6F2400000A         */ IL_0008: callvirt instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::get_Parent() /* 0A000024 */
		/* 0x0000214D 7516000001         */ IL_000d: isinst [PresentationFramework]System.Windows.Controls.Grid /* 01000016 */
		/* 0x00002152 0B                 */ IL_0012: stloc.1
		/* 0x00002153 07                 */ IL_0013: ldloc.1
		/* 0x00002154 2C27               */ IL_0014: brfalse.s IL_003d
		/* 0x00002156 03                 */ IL_0016: ldarg.1
		/* 0x00002157 06                 */ IL_0017: ldloc.0
		/* 0x00002158 282500000A         */ IL_0018: call int32 [PresentationFramework]System.Windows.Controls.Grid::GetRow(class [PresentationCore]System.Windows.UIElement) /* 0A000025 */
		/* 0x0000215D 282600000A         */ IL_001d: call void [PresentationFramework]System.Windows.Controls.Grid::SetRow(class [PresentationCore]System.Windows.UIElement, int32) /* 0A000026 */
		/* 0x00002162 07                 */ IL_0022: ldloc.1
		/* 0x00002163 6F2700000A         */ IL_0023: callvirt instance class [PresentationFramework]System.Windows.Controls.UIElementCollection [PresentationFramework]System.Windows.Controls.Panel::get_Children() /* 0A000027 */
		/* 0x00002168 03                 */ IL_0028: ldarg.1
		/* 0x00002169 6F2800000A         */ IL_0029: callvirt instance bool [PresentationFramework]System.Windows.Controls.UIElementCollection::Contains(class [PresentationCore]System.Windows.UIElement) /* 0A000028 */
		/* 0x0000216E 2D0D               */ IL_002e: brtrue.s IL_003d
		/* 0x00002170 07                 */ IL_0030: ldloc.1
		/* 0x00002171 6F2700000A         */ IL_0031: callvirt instance class [PresentationFramework]System.Windows.Controls.UIElementCollection [PresentationFramework]System.Windows.Controls.Panel::get_Children() /* 0A000027 */
		/* 0x00002176 03                 */ IL_0036: ldarg.1
		/* 0x00002177 6F2900000A         */ IL_0037: callvirt instance int32 [PresentationFramework]System.Windows.Controls.UIElementCollection::Add(class [PresentationCore]System.Windows.UIElement) /* 0A000029 */
		/* 0x0000217C 26                 */ IL_003c: pop
		/* 0x0000217D 2A                 */ IL_003d: ret
	} // end of method CommonShellWindowExtensions::DisplayStartupDialog

	.method /* 06000005 */ private hidebysig static 
		void RemoveStartupDialog (
			class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow csw
		) cil managed 
	{
		// Method begins at RVA 0x218c
		// Header size: 12
		// Code size: 90 (0x5a)
		.maxstack 2
		.locals /* 11000004 */ init (
			[0] class [PresentationFramework]System.Windows.Controls.Grid,
			[1] valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.CommonShell.Controls.Startup.StartupDialog>,
			[2] class AspenTech.CommonShell.Controls.Startup.StartupDialog
		)

		/* 0x0000218C 02                 */ IL_0000: ldarg.0
		/* 0x0000218D 6F1E00000A         */ IL_0001: callvirt instance class [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.ScreenManager [AspenTech.Visualisation.CommonShell.Wpf]AspenTech.Visualisation.CommonShell.CommonShellWindow::get_ScreenManager() /* 0A00001E */
		/* 0x00002192 6F2400000A         */ IL_0006: callvirt instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::get_Parent() /* 0A000024 */
		/* 0x00002197 7516000001         */ IL_000b: isinst [PresentationFramework]System.Windows.Controls.Grid /* 01000016 */
		/* 0x0000219C 0A                 */ IL_0010: stloc.0
		/* 0x0000219D 06                 */ IL_0011: ldloc.0
		/* 0x0000219E 2C45               */ IL_0012: brfalse.s IL_0059
		/* 0x000021A0 06                 */ IL_0014: ldloc.0
		/* 0x000021A1 6F2700000A         */ IL_0015: callvirt instance class [PresentationFramework]System.Windows.Controls.UIElementCollection [PresentationFramework]System.Windows.Controls.Panel::get_Children() /* 0A000027 */
		/* 0x000021A6 280300002B         */ IL_001a: call class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0> [System.Core]System.Linq.Enumerable::OfType<class AspenTech.CommonShell.Controls.Startup.StartupDialog>(class [mscorlib]System.Collections.IEnumerable) /* 2B000003 */
		/* 0x000021AB 280400002B         */ IL_001f: call class [mscorlib]System.Collections.Generic.List`1<!!0> [System.Core]System.Linq.Enumerable::ToList<class AspenTech.CommonShell.Controls.Startup.StartupDialog>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000004 */
		/* 0x000021B0 6F2C00000A         */ IL_0024: callvirt instance valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<!0> class [mscorlib]System.Collections.Generic.List`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog>::GetEnumerator() /* 0A00002C */
		/* 0x000021B5 0B                 */ IL_0029: stloc.1
		/* 0x000021B6 2B14               */ IL_002a: br.s IL_0040
		/* 0x000021B8 1201               */ IL_002c: ldloca.s 1
		/* 0x000021BA 282D00000A         */ IL_002e: call instance !0 valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.CommonShell.Controls.Startup.StartupDialog>::get_Current() /* 0A00002D */
		/* 0x000021BF 0C                 */ IL_0033: stloc.2
		/* 0x000021C0 06                 */ IL_0034: ldloc.0
		/* 0x000021C1 6F2700000A         */ IL_0035: callvirt instance class [PresentationFramework]System.Windows.Controls.UIElementCollection [PresentationFramework]System.Windows.Controls.Panel::get_Children() /* 0A000027 */
		/* 0x000021C6 08                 */ IL_003a: ldloc.2
		/* 0x000021C7 6F2E00000A         */ IL_003b: callvirt instance void [PresentationFramework]System.Windows.Controls.UIElementCollection::Remove(class [PresentationCore]System.Windows.UIElement) /* 0A00002E */
		/* 0x000021CC 1201               */ IL_0040: ldloca.s 1
		/* 0x000021CE 282F00000A         */ IL_0042: call instance bool valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.CommonShell.Controls.Startup.StartupDialog>::MoveNext() /* 0A00002F */
		/* 0x000021D3 2DE3               */ IL_0047: brtrue.s IL_002c
		/* 0x000021D5 DE0E               */ IL_0049: leave.s IL_0059
		/* 0x000021D7 1201               */ IL_004b: ldloca.s 1
		/* 0x000021D9 FE160600001B       */ IL_004d: constrained. valuetype [mscorlib]System.Collections.Generic.List`1/Enumerator<class AspenTech.CommonShell.Controls.Startup.StartupDialog> /* 1B000006 */
		/* 0x000021DF 6F1200000A         */ IL_0053: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000012 */
		/* 0x000021E4 DC                 */ IL_0058: endfinally
		/* 0x000021E5 2A                 */ IL_0059: ret

		.try IL_002a-IL_004b finally IL_004b-IL_0059
	} // end of method CommonShellWindowExtensions::RemoveStartupDialog

	.method /* 06000006 */ private hidebysig static 
		class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.StartupDialog> GetLoadedStartupDialogs (
			class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow window
		) cil managed 
	{
		.custom /* 0C00001C */ instance void [mscorlib]System.Runtime.CompilerServices.IteratorStateMachineAttribute::.ctor(class [mscorlib]System.Type) = (
			01 00 60 41 73 70 65 6e 54 65 63 68 2e 43 6f 6d
			6d 6f 6e 53 68 65 6c 6c 2e 43 6f 6e 74 72 6f 6c
			73 2e 53 74 61 72 74 75 70 2e 43 6f 6d 6d 6f 6e
			53 68 65 6c 6c 57 69 6e 64 6f 77 45 78 74 65 6e
			73 69 6f 6e 73 2b 3c 47 65 74 4c 6f 61 64 65 64
			53 74 61 72 74 75 70 44 69 61 6c 6f 67 73 3e 64
			5f 5f 35 00 00
		)
		// Method begins at RVA 0x2204
		// Header size: 1
		// Code size: 15 (0xf)
		.maxstack 8

		/* 0x00002204 1FFE               */ IL_0000: ldc.i4.s -2
		/* 0x00002206 7375000006         */ IL_0002: newobj instance void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::.ctor(int32) /* 06000075 */
		/* 0x0000220B 25                 */ IL_0007: dup
		/* 0x0000220C 02                 */ IL_0008: ldarg.0
		/* 0x0000220D 7D2E000004         */ IL_0009: stfld class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions/'<GetLoadedStartupDialogs>d__5'::'<>3__window' /* 0400002E */
		/* 0x00002212 2A                 */ IL_000e: ret
	} // end of method CommonShellWindowExtensions::GetLoadedStartupDialogs

} // end of class AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions

.class /* 02000003 */ public auto ansi AspenTech.CommonShell.Controls.Startup.StartupDialog
	extends [PresentationFramework]System.Windows.Controls.Control
{
	// Fields
	.field /* 04000001 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty OptionsProperty
	.field /* 04000002 */ private initonly class [System]System.Windows.Input.ICommand '<CloseCommand>k__BackingField'
	.custom /* 0C000012 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000003 */ private class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator _usedEventAggregator

	// Methods
	.method /* 06000007 */ public hidebysig specialname 
		instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions get_Options () cil managed 
	{
		// Method begins at RVA 0x2214
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002214 02                 */ IL_0000: ldarg.0
		/* 0x00002215 7E01000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.StartupDialog::OptionsProperty /* 04000001 */
		/* 0x0000221A 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x0000221F 740D000002         */ IL_000b: castclass AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002224 2A                 */ IL_0010: ret
	} // end of method StartupDialog::get_Options

	.method /* 06000008 */ public hidebysig specialname 
		instance void set_Options (
			class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2226
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002226 02                 */ IL_0000: ldarg.0
		/* 0x00002227 7E01000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.StartupDialog::OptionsProperty /* 04000001 */
		/* 0x0000222C 03                 */ IL_0006: ldarg.1
		/* 0x0000222D 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002232 2A                 */ IL_000c: ret
	} // end of method StartupDialog::set_Options

	.method /* 06000009 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_CloseCommand () cil managed 
	{
		.custom /* 0C00001E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2234
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002234 02                 */ IL_0000: ldarg.0
		/* 0x00002235 7B02000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.StartupDialog::'<CloseCommand>k__BackingField' /* 04000002 */
		/* 0x0000223A 2A                 */ IL_0006: ret
	} // end of method StartupDialog::get_CloseCommand

	.method /* 0600000A */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x223c
		// Header size: 12
		// Code size: 71 (0x47)
		.maxstack 3

		/* 0x0000223C 721F000070         */ IL_0000: ldstr "Options" /* 7000001F */
		/* 0x00002241 D00D000002         */ IL_0005: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002246 283200000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000224B D003000002         */ IL_000f: ldtoken AspenTech.CommonShell.Controls.Startup.StartupDialog /* 02000003 */
		/* 0x00002250 283200000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002255 283300000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x0000225A 8001000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.StartupDialog::OptionsProperty /* 04000001 */
		/* 0x0000225F 7E3400000A         */ IL_0023: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A000034 */
		/* 0x00002264 D003000002         */ IL_0028: ldtoken AspenTech.CommonShell.Controls.Startup.StartupDialog /* 02000003 */
		/* 0x00002269 283200000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000226E D003000002         */ IL_0032: ldtoken AspenTech.CommonShell.Controls.Startup.StartupDialog /* 02000003 */
		/* 0x00002273 283200000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002278 733500000A         */ IL_003c: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000035 */
		/* 0x0000227D 6F3600000A         */ IL_0041: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000036 */
		/* 0x00002282 2A                 */ IL_0046: ret
	} // end of method StartupDialog::.cctor

	.method /* 0600000B */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2290
		// Header size: 12
		// Code size: 66 (0x42)
		.maxstack 3

		/* 0x00002290 02                 */ IL_0000: ldarg.0
		/* 0x00002291 283700000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Control::.ctor() /* 0A000037 */
		/* 0x00002296 02                 */ IL_0006: ldarg.0
		/* 0x00002297 02                 */ IL_0007: ldarg.0
		/* 0x00002298 FE060D000006       */ IL_0008: ldftn instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::StartupDialog_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600000D */
		/* 0x0000229E 733800000A         */ IL_000e: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000038 */
		/* 0x000022A3 283900000A         */ IL_0013: call instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000039 */
		/* 0x000022A8 02                 */ IL_0018: ldarg.0
		/* 0x000022A9 02                 */ IL_0019: ldarg.0
		/* 0x000022AA FE060C000006       */ IL_001a: ldftn instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::StartupDialog_Unloaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600000C */
		/* 0x000022B0 733800000A         */ IL_0020: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000038 */
		/* 0x000022B5 283A00000A         */ IL_0025: call instance void [PresentationFramework]System.Windows.FrameworkElement::add_Unloaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A00003A */
		/* 0x000022BA 02                 */ IL_002a: ldarg.0
		/* 0x000022BB 02                 */ IL_002b: ldarg.0
		/* 0x000022BC FE060F000006       */ IL_002c: ldftn instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::CloseCommand_Execute() /* 0600000F */
		/* 0x000022C2 733B00000A         */ IL_0032: newobj instance void [mscorlib]System.Action::.ctor(object, native int) /* 0A00003B */
		/* 0x000022C7 733C00000A         */ IL_0037: newobj instance void [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand::.ctor(class [mscorlib]System.Action) /* 0A00003C */
		/* 0x000022CC 7D02000004         */ IL_003c: stfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.StartupDialog::'<CloseCommand>k__BackingField' /* 04000002 */
		/* 0x000022D1 2A                 */ IL_0041: ret
	} // end of method StartupDialog::.ctor

	.method /* 0600000C */ private hidebysig 
		instance void StartupDialog_Unloaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x22de
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x000022DE 02                 */ IL_0000: ldarg.0
		/* 0x000022DF 7B03000004         */ IL_0001: ldfld class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator AspenTech.CommonShell.Controls.Startup.StartupDialog::_usedEventAggregator /* 04000003 */
		/* 0x000022E4 2C1D               */ IL_0006: brfalse.s IL_0025
		/* 0x000022E6 02                 */ IL_0008: ldarg.0
		/* 0x000022E7 7B03000004         */ IL_0009: ldfld class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator AspenTech.CommonShell.Controls.Startup.StartupDialog::_usedEventAggregator /* 04000003 */
		/* 0x000022EC 6F0500002B         */ IL_000e: callvirt instance !!0 [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator::GetEvent<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEvent>() /* 2B000005 */
		/* 0x000022F1 02                 */ IL_0013: ldarg.0
		/* 0x000022F2 FE060E000006       */ IL_0014: ldftn instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::OnActiveScreenChangedEvent(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs) /* 0600000E */
		/* 0x000022F8 733E00000A         */ IL_001a: newobj instance void class [mscorlib]System.Action`1<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs>::.ctor(object, native int) /* 0A00003E */
		/* 0x000022FD 6F3F00000A         */ IL_001f: callvirt instance class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.SubscriptionToken class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Events.CompositePresentationEvent`1<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs>::Subscribe(class [mscorlib]System.Action`1<!0>) /* 0A00003F */
		/* 0x00002302 26                 */ IL_0024: pop
		/* 0x00002303 2A                 */ IL_0025: ret
	} // end of method StartupDialog::StartupDialog_Unloaded

	.method /* 0600000D */ private hidebysig 
		instance void StartupDialog_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2308
		// Header size: 12
		// Code size: 69 (0x45)
		.maxstack 3
		.locals /* 11000005 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow,
			[1] class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator
		)

		/* 0x00002308 02                 */ IL_0000: ldarg.0
		/* 0x00002309 284000000A         */ IL_0001: call class [PresentationFramework]System.Windows.Window [PresentationFramework]System.Windows.Window::GetWindow(class [WindowsBase]System.Windows.DependencyObject) /* 0A000040 */
		/* 0x0000230E 7513000001         */ IL_0006: isinst [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow /* 01000013 */
		/* 0x00002313 0A                 */ IL_000b: stloc.0
		/* 0x00002314 06                 */ IL_000c: ldloc.0
		/* 0x00002315 2C35               */ IL_000d: brfalse.s IL_0044
		/* 0x00002317 06                 */ IL_000f: ldloc.0
		/* 0x00002318 6F4100000A         */ IL_0010: callvirt instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow::get_Container() /* 0A000041 */
		/* 0x0000231D 25                 */ IL_0015: dup
		/* 0x0000231E 2D04               */ IL_0016: brtrue.s IL_001c
		/* 0x00002320 26                 */ IL_0018: pop
		/* 0x00002321 14                 */ IL_0019: ldnull
		/* 0x00002322 2B05               */ IL_001a: br.s IL_0021
		/* 0x00002324 280600002B         */ IL_001c: call !!0 [Microsoft.Practices.Composite.UnityExtensions]Microsoft.Practices.Composite.UnityExtensions.UnityContainerHelper::TryResolve<class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator>(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer) /* 2B000006 */
		/* 0x00002329 0B                 */ IL_0021: stloc.1
		/* 0x0000232A 07                 */ IL_0022: ldloc.1
		/* 0x0000232B 2C1F               */ IL_0023: brfalse.s IL_0044
		/* 0x0000232D 07                 */ IL_0025: ldloc.1
		/* 0x0000232E 6F0500002B         */ IL_0026: callvirt instance !!0 [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator::GetEvent<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEvent>() /* 2B000005 */
		/* 0x00002333 02                 */ IL_002b: ldarg.0
		/* 0x00002334 FE060E000006       */ IL_002c: ldftn instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::OnActiveScreenChangedEvent(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs) /* 0600000E */
		/* 0x0000233A 733E00000A         */ IL_0032: newobj instance void class [mscorlib]System.Action`1<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs>::.ctor(object, native int) /* 0A00003E */
		/* 0x0000233F 6F3F00000A         */ IL_0037: callvirt instance class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.SubscriptionToken class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Events.CompositePresentationEvent`1<class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs>::Subscribe(class [mscorlib]System.Action`1<!0>) /* 0A00003F */
		/* 0x00002344 26                 */ IL_003c: pop
		/* 0x00002345 02                 */ IL_003d: ldarg.0
		/* 0x00002346 07                 */ IL_003e: ldloc.1
		/* 0x00002347 7D03000004         */ IL_003f: stfld class [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Events.IEventAggregator AspenTech.CommonShell.Controls.Startup.StartupDialog::_usedEventAggregator /* 04000003 */
		/* 0x0000234C 2A                 */ IL_0044: ret
	} // end of method StartupDialog::StartupDialog_Loaded

	.method /* 0600000E */ private hidebysig 
		instance void OnActiveScreenChangedEvent (
			class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ActiveScreenChangedEventArgs args
		) cil managed 
	{
		// Method begins at RVA 0x235c
		// Header size: 12
		// Code size: 30 (0x1e)
		.maxstack 1
		.locals /* 11000006 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow
		)

		/* 0x0000235C 02                 */ IL_0000: ldarg.0
		/* 0x0000235D 284000000A         */ IL_0001: call class [PresentationFramework]System.Windows.Window [PresentationFramework]System.Windows.Window::GetWindow(class [WindowsBase]System.Windows.DependencyObject) /* 0A000040 */
		/* 0x00002362 7513000001         */ IL_0006: isinst [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow /* 01000013 */
		/* 0x00002367 0A                 */ IL_000b: stloc.0
		/* 0x00002368 06                 */ IL_000c: ldloc.0
		/* 0x00002369 2C0E               */ IL_000d: brfalse.s IL_001d
		/* 0x0000236B 06                 */ IL_000f: ldloc.0
		/* 0x0000236C 6F4300000A         */ IL_0010: callvirt instance class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.ScreenContentControl [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow::get_ActiveScreen() /* 0A000043 */
		/* 0x00002371 2C06               */ IL_0015: brfalse.s IL_001d
		/* 0x00002373 06                 */ IL_0017: ldloc.0
		/* 0x00002374 2802000006         */ IL_0018: call void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::CloseStartupDialog(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow) /* 06000002 */
		/* 0x00002379 2A                 */ IL_001d: ret
	} // end of method StartupDialog::OnActiveScreenChangedEvent

	.method /* 0600000F */ private hidebysig 
		instance void CloseCommand_Execute () cil managed 
	{
		// Method begins at RVA 0x2388
		// Header size: 12
		// Code size: 22 (0x16)
		.maxstack 1
		.locals /* 11000006 */ init (
			[0] class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow
		)

		/* 0x00002388 02                 */ IL_0000: ldarg.0
		/* 0x00002389 284000000A         */ IL_0001: call class [PresentationFramework]System.Windows.Window [PresentationFramework]System.Windows.Window::GetWindow(class [WindowsBase]System.Windows.DependencyObject) /* 0A000040 */
		/* 0x0000238E 7513000001         */ IL_0006: isinst [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow /* 01000013 */
		/* 0x00002393 0A                 */ IL_000b: stloc.0
		/* 0x00002394 06                 */ IL_000c: ldloc.0
		/* 0x00002395 2C06               */ IL_000d: brfalse.s IL_0015
		/* 0x00002397 06                 */ IL_000f: ldloc.0
		/* 0x00002398 2802000006         */ IL_0010: call void AspenTech.CommonShell.Controls.Startup.CommonShellWindowExtensions::CloseStartupDialog(class [AspenTech.Visualisation.CommonShell.Infrastructure.Wpf]AspenTech.Visualisation.CommonShell.IShellMainWindow) /* 06000002 */
		/* 0x0000239D 2A                 */ IL_0015: ret
	} // end of method StartupDialog::CloseCommand_Execute

	// Properties
	.property /* 17000001 */ instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions Options()
	{
		.get instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions AspenTech.CommonShell.Controls.Startup.StartupDialog::get_Options()
		.set instance void AspenTech.CommonShell.Controls.Startup.StartupDialog::set_Options(class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions)
	}
	.property /* 17000002 */ instance class [System]System.Windows.Input.ICommand CloseCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.StartupDialog::get_CloseCommand()
	}

} // end of class AspenTech.CommonShell.Controls.Startup.StartupDialog

.class /* 02000004 */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Properties.Resources
	extends [mscorlib]System.Object
{
	.custom /* 0C000016 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 33 53 79 73 74 65 6d 2e 52 65 73 6f 75 72
		63 65 73 2e 54 6f 6f 6c 73 2e 53 74 72 6f 6e 67
		6c 79 54 79 70 65 64 52 65 73 6f 75 72 63 65 42
		75 69 6c 64 65 72 08 31 36 2e 30 2e 30 2e 30 00 00
	)
	.custom /* 0C000017 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000018 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	// Fields
	.field /* 04000004 */ private static class [mscorlib]System.Resources.ResourceManager resourceMan
	.field /* 04000005 */ private static class [mscorlib]System.Globalization.CultureInfo resourceCulture

	// Methods
	.method /* 06000010 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x23aa
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023AA 02                 */ IL_0000: ldarg.0
		/* 0x000023AB 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x000023B0 2A                 */ IL_0006: ret
	} // end of method Resources::.ctor

	.method /* 06000011 */ public hidebysig specialname static 
		class [mscorlib]System.Resources.ResourceManager get_ResourceManager () cil managed 
	{
		// Method begins at RVA 0x23b2
		// Header size: 1
		// Code size: 43 (0x2b)
		.maxstack 8

		/* 0x000023B2 7E04000004         */ IL_0000: ldsfld class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceMan /* 04000004 */
		/* 0x000023B7 2D1E               */ IL_0005: brtrue.s IL_0025
		/* 0x000023B9 722F000070         */ IL_0007: ldstr "AspenTech.CommonShell.Controls.Startup.Properties.Resources" /* 7000002F */
		/* 0x000023BE D004000002         */ IL_000c: ldtoken AspenTech.CommonShell.Controls.Startup.Properties.Resources /* 02000004 */
		/* 0x000023C3 283200000A         */ IL_0011: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x000023C8 6F4500000A         */ IL_0016: callvirt instance class [mscorlib]System.Reflection.Assembly [mscorlib]System.Type::get_Assembly() /* 0A000045 */
		/* 0x000023CD 734600000A         */ IL_001b: newobj instance void [mscorlib]System.Resources.ResourceManager::.ctor(string, class [mscorlib]System.Reflection.Assembly) /* 0A000046 */
		/* 0x000023D2 8004000004         */ IL_0020: stsfld class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceMan /* 04000004 */
		/* 0x000023D7 7E04000004         */ IL_0025: ldsfld class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceMan /* 04000004 */
		/* 0x000023DC 2A                 */ IL_002a: ret
	} // end of method Resources::get_ResourceManager

	.method /* 06000012 */ public hidebysig specialname static 
		class [mscorlib]System.Globalization.CultureInfo get_Culture () cil managed 
	{
		// Method begins at RVA 0x23de
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000023DE 7E05000004         */ IL_0000: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x000023E3 2A                 */ IL_0005: ret
	} // end of method Resources::get_Culture

	.method /* 06000013 */ public hidebysig specialname static 
		void set_Culture (
			class [mscorlib]System.Globalization.CultureInfo 'value'
		) cil managed 
	{
		// Method begins at RVA 0x23e5
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023E5 02                 */ IL_0000: ldarg.0
		/* 0x000023E6 8005000004         */ IL_0001: stsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x000023EB 2A                 */ IL_0006: ret
	} // end of method Resources::set_Culture

	.method /* 06000014 */ public hidebysig specialname static 
		string get_Button_New_Caption () cil managed 
	{
		// Method begins at RVA 0x23ed
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x000023ED 2811000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_ResourceManager() /* 06000011 */
		/* 0x000023F2 72A7000070         */ IL_0005: ldstr "Button_New_Caption" /* 700000A7 */
		/* 0x000023F7 7E05000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x000023FC 6F4700000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A000047 */
		/* 0x00002401 2A                 */ IL_0014: ret
	} // end of method Resources::get_Button_New_Caption

	.method /* 06000015 */ public hidebysig specialname static 
		string get_Button_Open_Caption () cil managed 
	{
		// Method begins at RVA 0x2403
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002403 2811000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_ResourceManager() /* 06000011 */
		/* 0x00002408 72CD000070         */ IL_0005: ldstr "Button_Open_Caption" /* 700000CD */
		/* 0x0000240D 7E05000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x00002412 6F4700000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A000047 */
		/* 0x00002417 2A                 */ IL_0014: ret
	} // end of method Resources::get_Button_Open_Caption

	.method /* 06000016 */ public hidebysig specialname static 
		string get_RecentFileList_Caption () cil managed 
	{
		// Method begins at RVA 0x2419
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002419 2811000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_ResourceManager() /* 06000011 */
		/* 0x0000241E 72F5000070         */ IL_0005: ldstr "RecentFileList_Caption" /* 700000F5 */
		/* 0x00002423 7E05000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x00002428 6F4700000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A000047 */
		/* 0x0000242D 2A                 */ IL_0014: ret
	} // end of method Resources::get_RecentFileList_Caption

	.method /* 06000017 */ public hidebysig specialname static 
		string get_RecentFileList_Placeholder () cil managed 
	{
		// Method begins at RVA 0x242f
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x0000242F 2811000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_ResourceManager() /* 06000011 */
		/* 0x00002434 7223010070         */ IL_0005: ldstr "RecentFileList_Placeholder" /* 70000123 */
		/* 0x00002439 7E05000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x0000243E 6F4700000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A000047 */
		/* 0x00002443 2A                 */ IL_0014: ret
	} // end of method Resources::get_RecentFileList_Placeholder

	.method /* 06000018 */ public hidebysig specialname static 
		string get_StartupDialog_Title () cil managed 
	{
		// Method begins at RVA 0x2445
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002445 2811000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_ResourceManager() /* 06000011 */
		/* 0x0000244A 7259010070         */ IL_0005: ldstr "StartupDialog_Title" /* 70000159 */
		/* 0x0000244F 7E05000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::resourceCulture /* 04000005 */
		/* 0x00002454 6F4700000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A000047 */
		/* 0x00002459 2A                 */ IL_0014: ret
	} // end of method Resources::get_StartupDialog_Title

	// Properties
	.property /* 17000003 */ class [mscorlib]System.Resources.ResourceManager ResourceManager()
	{
		.custom /* 0C000015 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 02 00 00 00 00 00
		)
		.get class [mscorlib]System.Resources.ResourceManager AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_ResourceManager()
	}
	.property /* 17000004 */ class [mscorlib]System.Globalization.CultureInfo Culture()
	{
		.custom /* 0C000019 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 02 00 00 00 00 00
		)
		.get class [mscorlib]System.Globalization.CultureInfo AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_Culture()
		.set void AspenTech.CommonShell.Controls.Startup.Properties.Resources::set_Culture(class [mscorlib]System.Globalization.CultureInfo)
	}
	.property /* 17000005 */ string Button_New_Caption()
	{
		.get string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_Button_New_Caption()
	}
	.property /* 17000006 */ string Button_Open_Caption()
	{
		.get string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_Button_Open_Caption()
	}
	.property /* 17000007 */ string RecentFileList_Caption()
	{
		.get string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_RecentFileList_Caption()
	}
	.property /* 17000008 */ string RecentFileList_Placeholder()
	{
		.get string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_RecentFileList_Placeholder()
	}
	.property /* 17000009 */ string StartupDialog_Title()
	{
		.get string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_StartupDialog_Title()
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Properties.Resources

.class /* 02000005 */ private auto ansi sealed beforefieldinit AspenTech.CommonShell.Controls.Startup.Properties.Settings
	extends [System]System.Configuration.ApplicationSettingsBase
{
	.custom /* 0C00001A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C00001B */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 4b 4d 69 63 72 6f 73 6f 66 74 2e 56 69 73
		75 61 6c 53 74 75 64 69 6f 2e 45 64 69 74 6f 72
		73 2e 53 65 74 74 69 6e 67 73 44 65 73 69 67 6e
		65 72 2e 53 65 74 74 69 6e 67 73 53 69 6e 67 6c
		65 46 69 6c 65 47 65 6e 65 72 61 74 6f 72 09 31
		36 2e 31 30 2e 30 2e 30 00 00
	)
	// Fields
	.field /* 04000006 */ private static class AspenTech.CommonShell.Controls.Startup.Properties.Settings defaultInstance

	// Methods
	.method /* 06000019 */ public hidebysig specialname static 
		class AspenTech.CommonShell.Controls.Startup.Properties.Settings get_Default () cil managed 
	{
		// Method begins at RVA 0x245b
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x0000245B 7E06000004         */ IL_0000: ldsfld class AspenTech.CommonShell.Controls.Startup.Properties.Settings AspenTech.CommonShell.Controls.Startup.Properties.Settings::defaultInstance /* 04000006 */
		/* 0x00002460 2A                 */ IL_0005: ret
	} // end of method Settings::get_Default

	.method /* 0600001A */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2462
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002462 02                 */ IL_0000: ldarg.0
		/* 0x00002463 284800000A         */ IL_0001: call instance void [System]System.Configuration.ApplicationSettingsBase::.ctor() /* 0A000048 */
		/* 0x00002468 2A                 */ IL_0006: ret
	} // end of method Settings::.ctor

	.method /* 0600001B */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x246a
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x0000246A 731A000006         */ IL_0000: newobj instance void AspenTech.CommonShell.Controls.Startup.Properties.Settings::.ctor() /* 0600001A */
		/* 0x0000246F 284900000A         */ IL_0005: call class [System]System.Configuration.SettingsBase [System]System.Configuration.SettingsBase::Synchronized(class [System]System.Configuration.SettingsBase) /* 0A000049 */
		/* 0x00002474 7405000002         */ IL_000a: castclass AspenTech.CommonShell.Controls.Startup.Properties.Settings /* 02000005 */
		/* 0x00002479 8006000004         */ IL_000f: stsfld class AspenTech.CommonShell.Controls.Startup.Properties.Settings AspenTech.CommonShell.Controls.Startup.Properties.Settings::defaultInstance /* 04000006 */
		/* 0x0000247E 2A                 */ IL_0014: ret
	} // end of method Settings::.cctor

	// Properties
	.property /* 1700000A */ class AspenTech.CommonShell.Controls.Startup.Properties.Settings Default()
	{
		.get class AspenTech.CommonShell.Controls.Startup.Properties.Settings AspenTech.CommonShell.Controls.Startup.Properties.Settings::get_Default()
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Properties.Settings

.class /* 02000006 */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IValueConverter
{
	// Fields
	.field /* 04000007 */ private bool '<IsPositiveCheck>k__BackingField'
	.custom /* 0C00001D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600001C */ public hidebysig specialname 
		instance bool get_IsPositiveCheck () cil managed 
	{
		.custom /* 0C000025 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2480
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002480 02                 */ IL_0000: ldarg.0
		/* 0x00002481 7B07000004         */ IL_0001: ldfld bool AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter::'<IsPositiveCheck>k__BackingField' /* 04000007 */
		/* 0x00002486 2A                 */ IL_0006: ret
	} // end of method FileItemsToVisibilityConverter::get_IsPositiveCheck

	.method /* 0600001D */ public hidebysig specialname 
		instance void set_IsPositiveCheck (
			bool 'value'
		) cil managed 
	{
		.custom /* 0C000026 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2488
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002488 02                 */ IL_0000: ldarg.0
		/* 0x00002489 03                 */ IL_0001: ldarg.1
		/* 0x0000248A 7D07000004         */ IL_0002: stfld bool AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter::'<IsPositiveCheck>k__BackingField' /* 04000007 */
		/* 0x0000248F 2A                 */ IL_0007: ret
	} // end of method FileItemsToVisibilityConverter::set_IsPositiveCheck

	.method /* 0600001E */ public final hidebysig newslot virtual 
		instance object Convert (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2494
		// Header size: 12
		// Code size: 54 (0x36)
		.maxstack 1
		.locals /* 11000007 */ init (
			[0] class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem>
		)

		/* 0x00002494 03                 */ IL_0000: ldarg.1
		/* 0x00002495 750900001B         */ IL_0001: isinst class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> /* 1B000009 */
		/* 0x0000249A 0A                 */ IL_0006: stloc.0
		/* 0x0000249B 06                 */ IL_0007: ldloc.0
		/* 0x0000249C 2C1A               */ IL_0008: brfalse.s IL_0024
		/* 0x0000249E 06                 */ IL_000a: ldloc.0
		/* 0x0000249F 280700002B         */ IL_000b: call bool [System.Core]System.Linq.Enumerable::Any<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000007 */
		/* 0x000024A4 2C12               */ IL_0010: brfalse.s IL_0024
		/* 0x000024A6 02                 */ IL_0012: ldarg.0
		/* 0x000024A7 281C000006         */ IL_0013: call instance bool AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter::get_IsPositiveCheck() /* 0600001C */
		/* 0x000024AC 2D03               */ IL_0018: brtrue.s IL_001d
		/* 0x000024AE 18                 */ IL_001a: ldc.i4.2
		/* 0x000024AF 2B01               */ IL_001b: br.s IL_001e
		/* 0x000024B1 16                 */ IL_001d: ldc.i4.0
		/* 0x000024B2 8C42000001         */ IL_001e: box [PresentationCore]System.Windows.Visibility /* 01000042 */
		/* 0x000024B7 2A                 */ IL_0023: ret
		/* 0x000024B8 02                 */ IL_0024: ldarg.0
		/* 0x000024B9 281C000006         */ IL_0025: call instance bool AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter::get_IsPositiveCheck() /* 0600001C */
		/* 0x000024BE 2D03               */ IL_002a: brtrue.s IL_002f
		/* 0x000024C0 16                 */ IL_002c: ldc.i4.0
		/* 0x000024C1 2B01               */ IL_002d: br.s IL_0030
		/* 0x000024C3 18                 */ IL_002f: ldc.i4.2
		/* 0x000024C4 8C42000001         */ IL_0030: box [PresentationCore]System.Windows.Visibility /* 01000042 */
		/* 0x000024C9 2A                 */ IL_0035: ret
	} // end of method FileItemsToVisibilityConverter::Convert

	.method /* 0600001F */ public final hidebysig newslot virtual 
		instance object ConvertBack (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x24d6
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000024D6 734A00000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A00004A */
		/* 0x000024DB 7A                 */ IL_0005: throw
	} // end of method FileItemsToVisibilityConverter::ConvertBack

	.method /* 06000020 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x24dd
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000024DD 02                 */ IL_0000: ldarg.0
		/* 0x000024DE 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x000024E3 2A                 */ IL_0006: ret
	} // end of method FileItemsToVisibilityConverter::.ctor

	// Properties
	.property /* 1700000B */ instance bool IsPositiveCheck()
	{
		.get instance bool AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter::get_IsPositiveCheck()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter::set_IsPositiveCheck(bool)
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.FileItemsToVisibilityConverter

.class /* 02000007 */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.MouseOverToBackgroundConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IValueConverter
{
	// Methods
	.method /* 06000021 */ public final hidebysig newslot virtual 
		instance object Convert (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x24e8
		// Header size: 12
		// Code size: 26 (0x1a)
		.maxstack 1
		.locals /* 11000008 */ init (
			[0] bool
		)

		/* 0x000024E8 03                 */ IL_0000: ldarg.1
		/* 0x000024E9 7556000001         */ IL_0001: isinst [mscorlib]System.Boolean /* 01000056 */
		/* 0x000024EE 2C0C               */ IL_0006: brfalse.s IL_0014
		/* 0x000024F0 03                 */ IL_0008: ldarg.1
		/* 0x000024F1 A556000001         */ IL_0009: unbox.any [mscorlib]System.Boolean /* 01000056 */
		/* 0x000024F6 0A                 */ IL_000e: stloc.0
		/* 0x000024F7 06                 */ IL_000f: ldloc.0
		/* 0x000024F8 2C02               */ IL_0010: brfalse.s IL_0014
		/* 0x000024FA 05                 */ IL_0012: ldarg.3
		/* 0x000024FB 2A                 */ IL_0013: ret
		/* 0x000024FC 284B00000A         */ IL_0014: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_Transparent() /* 0A00004B */
		/* 0x00002501 2A                 */ IL_0019: ret
	} // end of method MouseOverToBackgroundConverter::Convert

	.method /* 06000022 */ public final hidebysig newslot virtual 
		instance object ConvertBack (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x250e
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x0000250E 734A00000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A00004A */
		/* 0x00002513 7A                 */ IL_0005: throw
	} // end of method MouseOverToBackgroundConverter::ConvertBack

	.method /* 06000023 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2515
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002515 02                 */ IL_0000: ldarg.0
		/* 0x00002516 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x0000251B 2A                 */ IL_0006: ret
	} // end of method MouseOverToBackgroundConverter::.ctor

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.MouseOverToBackgroundConverter

.class /* 02000008 */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.FileItemModifiedTimeDisplayConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IValueConverter
{
	// Methods
	.method /* 06000024 */ public final hidebysig newslot virtual 
		instance object Convert (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2520
		// Header size: 12
		// Code size: 30 (0x1e)
		.maxstack 2
		.locals /* 11000009 */ init (
			[0] valuetype [mscorlib]System.DateTime
		)

		/* 0x00002520 03                 */ IL_0000: ldarg.1
		/* 0x00002521 7532000001         */ IL_0001: isinst [mscorlib]System.DateTime /* 01000032 */
		/* 0x00002526 2C14               */ IL_0006: brfalse.s IL_001c
		/* 0x00002528 03                 */ IL_0008: ldarg.1
		/* 0x00002529 A532000001         */ IL_0009: unbox.any [mscorlib]System.DateTime /* 01000032 */
		/* 0x0000252E 0A                 */ IL_000e: stloc.0
		/* 0x0000252F 1200               */ IL_000f: ldloca.s 0
		/* 0x00002531 7281010070         */ IL_0011: ldstr "MMMM dd yyyy" /* 70000181 */
		/* 0x00002536 284C00000A         */ IL_0016: call instance string [mscorlib]System.DateTime::ToString(string) /* 0A00004C */
		/* 0x0000253B 2A                 */ IL_001b: ret
		/* 0x0000253C 14                 */ IL_001c: ldnull
		/* 0x0000253D 2A                 */ IL_001d: ret
	} // end of method FileItemModifiedTimeDisplayConverter::Convert

	.method /* 06000025 */ public final hidebysig newslot virtual 
		instance object ConvertBack (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x254a
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x0000254A 734A00000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A00004A */
		/* 0x0000254F 7A                 */ IL_0005: throw
	} // end of method FileItemModifiedTimeDisplayConverter::ConvertBack

	.method /* 06000026 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2551
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002551 02                 */ IL_0000: ldarg.0
		/* 0x00002552 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x00002557 2A                 */ IL_0006: ret
	} // end of method FileItemModifiedTimeDisplayConverter::.ctor

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.FileItemModifiedTimeDisplayConverter

.class /* 02000009 */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleTextConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IMultiValueConverter
{
	// Methods
	.method /* 06000027 */ public final hidebysig newslot virtual 
		instance object Convert (
			object[] values,
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2559
		// Header size: 1
		// Code size: 42 (0x2a)
		.maxstack 8

		/* 0x00002559 03                 */ IL_0000: ldarg.1
		/* 0x0000255A 2C25               */ IL_0001: brfalse.s IL_0028
		/* 0x0000255C 03                 */ IL_0003: ldarg.1
		/* 0x0000255D 8E                 */ IL_0004: ldlen
		/* 0x0000255E 69                 */ IL_0005: conv.i4
		/* 0x0000255F 18                 */ IL_0006: ldc.i4.2
		/* 0x00002560 331F               */ IL_0007: bne.un.s IL_0028
		/* 0x00002562 03                 */ IL_0009: ldarg.1
		/* 0x00002563 16                 */ IL_000a: ldc.i4.0
		/* 0x00002564 9A                 */ IL_000b: ldelem.ref
		/* 0x00002565 7559000001         */ IL_000c: isinst [mscorlib]System.String /* 01000059 */
		/* 0x0000256A 25                 */ IL_0011: dup
		/* 0x0000256B 2D13               */ IL_0012: brtrue.s IL_0027
		/* 0x0000256D 26                 */ IL_0014: pop
		/* 0x0000256E 2818000006         */ IL_0015: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_StartupDialog_Title() /* 06000018 */
		/* 0x00002573 03                 */ IL_001a: ldarg.1
		/* 0x00002574 17                 */ IL_001b: ldc.i4.1
		/* 0x00002575 9A                 */ IL_001c: ldelem.ref
		/* 0x00002576 7559000001         */ IL_001d: isinst [mscorlib]System.String /* 01000059 */
		/* 0x0000257B 284D00000A         */ IL_0022: call string [mscorlib]System.String::Format(string, object) /* 0A00004D */
		/* 0x00002580 2A                 */ IL_0027: ret
		/* 0x00002581 14                 */ IL_0028: ldnull
		/* 0x00002582 2A                 */ IL_0029: ret
	} // end of method DialogTitleTextConverter::Convert

	.method /* 06000028 */ public final hidebysig newslot virtual 
		instance object[] ConvertBack (
			object 'value',
			class [mscorlib]System.Type[] targetTypes,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2584
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00002584 734A00000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A00004A */
		/* 0x00002589 7A                 */ IL_0005: throw
	} // end of method DialogTitleTextConverter::ConvertBack

	.method /* 06000029 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x258b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000258B 02                 */ IL_0000: ldarg.0
		/* 0x0000258C 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x00002591 2A                 */ IL_0006: ret
	} // end of method DialogTitleTextConverter::.ctor

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleTextConverter

.class /* 0200000A */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IMultiValueConverter
{
	// Fields
	.field /* 04000008 */ private static initonly class [PresentationCore]System.Windows.Media.Brush DefaultTitleBackground
	.field /* 04000009 */ private static initonly class [PresentationCore]System.Windows.Media.Brush HYSYSTitleBackground
	.field /* 0400000A */ private static initonly class [PresentationCore]System.Windows.Media.Brush APlusTitleBackground

	// Methods
	.method /* 0600002A */ public final hidebysig newslot virtual 
		instance object Convert (
			object[] values,
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2594
		// Header size: 12
		// Code size: 89 (0x59)
		.maxstack 2
		.locals /* 1100000A */ init (
			[0] class [PresentationCore]System.Windows.Media.Brush,
			[1] string
		)

		/* 0x00002594 03                 */ IL_0000: ldarg.1
		/* 0x00002595 2C50               */ IL_0001: brfalse.s IL_0053
		/* 0x00002597 03                 */ IL_0003: ldarg.1
		/* 0x00002598 8E                 */ IL_0004: ldlen
		/* 0x00002599 69                 */ IL_0005: conv.i4
		/* 0x0000259A 18                 */ IL_0006: ldc.i4.2
		/* 0x0000259B 334A               */ IL_0007: bne.un.s IL_0053
		/* 0x0000259D 03                 */ IL_0009: ldarg.1
		/* 0x0000259E 16                 */ IL_000a: ldc.i4.0
		/* 0x0000259F 9A                 */ IL_000b: ldelem.ref
		/* 0x000025A0 7534000001         */ IL_000c: isinst [PresentationCore]System.Windows.Media.Brush /* 01000034 */
		/* 0x000025A5 0A                 */ IL_0011: stloc.0
		/* 0x000025A6 06                 */ IL_0012: ldloc.0
		/* 0x000025A7 2C02               */ IL_0013: brfalse.s IL_0017
		/* 0x000025A9 06                 */ IL_0015: ldloc.0
		/* 0x000025AA 2A                 */ IL_0016: ret
		/* 0x000025AB 03                 */ IL_0017: ldarg.1
		/* 0x000025AC 17                 */ IL_0018: ldc.i4.1
		/* 0x000025AD 9A                 */ IL_0019: ldelem.ref
		/* 0x000025AE 7559000001         */ IL_001a: isinst [mscorlib]System.String /* 01000059 */
		/* 0x000025B3 0B                 */ IL_001f: stloc.1
		/* 0x000025B4 07                 */ IL_0020: ldloc.1
		/* 0x000025B5 2C30               */ IL_0021: brfalse.s IL_0053
		/* 0x000025B7 07                 */ IL_0023: ldloc.1
		/* 0x000025B8 6F4E00000A         */ IL_0024: callvirt instance string [mscorlib]System.String::ToLower() /* 0A00004E */
		/* 0x000025BD 729B010070         */ IL_0029: ldstr "hysys" /* 7000019B */
		/* 0x000025C2 6F4F00000A         */ IL_002e: callvirt instance bool [mscorlib]System.String::Contains(string) /* 0A00004F */
		/* 0x000025C7 2C06               */ IL_0033: brfalse.s IL_003b
		/* 0x000025C9 7E09000004         */ IL_0035: ldsfld class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter::HYSYSTitleBackground /* 04000009 */
		/* 0x000025CE 2A                 */ IL_003a: ret
		/* 0x000025CF 07                 */ IL_003b: ldloc.1
		/* 0x000025D0 6F4E00000A         */ IL_003c: callvirt instance string [mscorlib]System.String::ToLower() /* 0A00004E */
		/* 0x000025D5 72A7010070         */ IL_0041: ldstr "plus" /* 700001A7 */
		/* 0x000025DA 6F4F00000A         */ IL_0046: callvirt instance bool [mscorlib]System.String::Contains(string) /* 0A00004F */
		/* 0x000025DF 2C06               */ IL_004b: brfalse.s IL_0053
		/* 0x000025E1 7E0A000004         */ IL_004d: ldsfld class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter::APlusTitleBackground /* 0400000A */
		/* 0x000025E6 2A                 */ IL_0052: ret
		/* 0x000025E7 7E08000004         */ IL_0053: ldsfld class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter::DefaultTitleBackground /* 04000008 */
		/* 0x000025EC 2A                 */ IL_0058: ret
	} // end of method DialogTitleBackgroundConverter::Convert

	.method /* 0600002B */ public final hidebysig newslot virtual 
		instance object[] ConvertBack (
			object 'value',
			class [mscorlib]System.Type[] targetTypes,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x25f9
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000025F9 734A00000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A00004A */
		/* 0x000025FE 7A                 */ IL_0005: throw
	} // end of method DialogTitleBackgroundConverter::ConvertBack

	.method /* 0600002C */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2600
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002600 02                 */ IL_0000: ldarg.0
		/* 0x00002601 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x00002606 2A                 */ IL_0006: ret
	} // end of method DialogTitleBackgroundConverter::.ctor

	.method /* 0600002D */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2608
		// Header size: 12
		// Code size: 465 (0x1d1)
		.maxstack 6

		/* 0x00002608 735000000A         */ IL_0000: newobj instance void [PresentationCore]System.Windows.Media.LinearGradientBrush::.ctor() /* 0A000050 */
		/* 0x0000260D 25                 */ IL_0005: dup
		/* 0x0000260E 23000000000000E03F */ IL_0006: ldc.r8 0.5
		/* 0x00002617 230000000000000000 */ IL_000f: ldc.r8 0.0
		/* 0x00002620 735100000A         */ IL_0018: newobj instance void [WindowsBase]System.Windows.Point::.ctor(float64, float64) /* 0A000051 */
		/* 0x00002625 6F5200000A         */ IL_001d: callvirt instance void [PresentationCore]System.Windows.Media.LinearGradientBrush::set_StartPoint(valuetype [WindowsBase]System.Windows.Point) /* 0A000052 */
		/* 0x0000262A 25                 */ IL_0022: dup
		/* 0x0000262B 23000000000000E03F */ IL_0023: ldc.r8 0.5
		/* 0x00002634 23000000000000F03F */ IL_002c: ldc.r8 1
		/* 0x0000263D 735100000A         */ IL_0035: newobj instance void [WindowsBase]System.Windows.Point::.ctor(float64, float64) /* 0A000051 */
		/* 0x00002642 6F5300000A         */ IL_003a: callvirt instance void [PresentationCore]System.Windows.Media.LinearGradientBrush::set_EndPoint(valuetype [WindowsBase]System.Windows.Point) /* 0A000053 */
		/* 0x00002647 25                 */ IL_003f: dup
		/* 0x00002648 735400000A         */ IL_0040: newobj instance void [PresentationCore]System.Windows.Media.GradientStopCollection::.ctor() /* 0A000054 */
		/* 0x0000264D 25                 */ IL_0045: dup
		/* 0x0000264E 72B1010070         */ IL_0046: ldstr "#FFA3A1E0" /* 700001B1 */
		/* 0x00002653 285500000A         */ IL_004b: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x00002658 A55E000001         */ IL_0050: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x0000265D 230000000000000000 */ IL_0055: ldc.r8 0.0
		/* 0x00002666 735600000A         */ IL_005e: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x0000266B 6F5700000A         */ IL_0063: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x00002670 25                 */ IL_0068: dup
		/* 0x00002671 72C5010070         */ IL_0069: ldstr "#FFDADAEE" /* 700001C5 */
		/* 0x00002676 285500000A         */ IL_006e: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x0000267B A55E000001         */ IL_0073: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x00002680 23C976BE9F1A2FCD3F */ IL_0078: ldc.r8 0.228
		/* 0x00002689 735600000A         */ IL_0081: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x0000268E 6F5700000A         */ IL_0086: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x00002693 25                 */ IL_008b: dup
		/* 0x00002694 72D9010070         */ IL_008c: ldstr "#FF99A4A3" /* 700001D9 */
		/* 0x00002699 285500000A         */ IL_0091: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x0000269E A55E000001         */ IL_0096: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x000026A3 236DE7FBA9F1D2E53F */ IL_009b: ldc.r8 0.682
		/* 0x000026AC 735600000A         */ IL_00a4: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x000026B1 6F5700000A         */ IL_00a9: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x000026B6 25                 */ IL_00ae: dup
		/* 0x000026B7 72ED010070         */ IL_00af: ldstr "#FFE6EAE9" /* 700001ED */
		/* 0x000026BC 285500000A         */ IL_00b4: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x000026C1 A55E000001         */ IL_00b9: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x000026C6 2385EB51B81E85EF3F */ IL_00be: ldc.r8 0.985
		/* 0x000026CF 735600000A         */ IL_00c7: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x000026D4 6F5700000A         */ IL_00cc: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x000026D9 6F5800000A         */ IL_00d1: callvirt instance void [PresentationCore]System.Windows.Media.GradientBrush::set_GradientStops(class [PresentationCore]System.Windows.Media.GradientStopCollection) /* 0A000058 */
		/* 0x000026DE 8008000004         */ IL_00d6: stsfld class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter::DefaultTitleBackground /* 04000008 */
		/* 0x000026E3 735000000A         */ IL_00db: newobj instance void [PresentationCore]System.Windows.Media.LinearGradientBrush::.ctor() /* 0A000050 */
		/* 0x000026E8 25                 */ IL_00e0: dup
		/* 0x000026E9 23000000000000E03F */ IL_00e1: ldc.r8 0.5
		/* 0x000026F2 230000000000000000 */ IL_00ea: ldc.r8 0.0
		/* 0x000026FB 735100000A         */ IL_00f3: newobj instance void [WindowsBase]System.Windows.Point::.ctor(float64, float64) /* 0A000051 */
		/* 0x00002700 6F5200000A         */ IL_00f8: callvirt instance void [PresentationCore]System.Windows.Media.LinearGradientBrush::set_StartPoint(valuetype [WindowsBase]System.Windows.Point) /* 0A000052 */
		/* 0x00002705 25                 */ IL_00fd: dup
		/* 0x00002706 23000000000000E03F */ IL_00fe: ldc.r8 0.5
		/* 0x0000270F 23000000000000F03F */ IL_0107: ldc.r8 1
		/* 0x00002718 735100000A         */ IL_0110: newobj instance void [WindowsBase]System.Windows.Point::.ctor(float64, float64) /* 0A000051 */
		/* 0x0000271D 6F5300000A         */ IL_0115: callvirt instance void [PresentationCore]System.Windows.Media.LinearGradientBrush::set_EndPoint(valuetype [WindowsBase]System.Windows.Point) /* 0A000053 */
		/* 0x00002722 25                 */ IL_011a: dup
		/* 0x00002723 735400000A         */ IL_011b: newobj instance void [PresentationCore]System.Windows.Media.GradientStopCollection::.ctor() /* 0A000054 */
		/* 0x00002728 25                 */ IL_0120: dup
		/* 0x00002729 7201020070         */ IL_0121: ldstr "#FF2EAA97" /* 70000201 */
		/* 0x0000272E 285500000A         */ IL_0126: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x00002733 A55E000001         */ IL_012b: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x00002738 230000000000000000 */ IL_0130: ldc.r8 0.0
		/* 0x00002741 735600000A         */ IL_0139: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x00002746 6F5700000A         */ IL_013e: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x0000274B 25                 */ IL_0143: dup
		/* 0x0000274C 7215020070         */ IL_0144: ldstr "#FF248F7F" /* 70000215 */
		/* 0x00002751 285500000A         */ IL_0149: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x00002756 A55E000001         */ IL_014e: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x0000275B 23C976BE9F1A2FCD3F */ IL_0153: ldc.r8 0.228
		/* 0x00002764 735600000A         */ IL_015c: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x00002769 6F5700000A         */ IL_0161: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x0000276E 25                 */ IL_0166: dup
		/* 0x0000276F 7229020070         */ IL_0167: ldstr "#FF24B6A0" /* 70000229 */
		/* 0x00002774 285500000A         */ IL_016c: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x00002779 A55E000001         */ IL_0171: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x0000277E 236DE7FBA9F1D2E53F */ IL_0176: ldc.r8 0.682
		/* 0x00002787 735600000A         */ IL_017f: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x0000278C 6F5700000A         */ IL_0184: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x00002791 25                 */ IL_0189: dup
		/* 0x00002792 723D020070         */ IL_018a: ldstr "#FF5BCCBB" /* 7000023D */
		/* 0x00002797 285500000A         */ IL_018f: call object [PresentationCore]System.Windows.Media.ColorConverter::ConvertFromString(string) /* 0A000055 */
		/* 0x0000279C A55E000001         */ IL_0194: unbox.any [PresentationCore]System.Windows.Media.Color /* 0100005E */
		/* 0x000027A1 2385EB51B81E85EF3F */ IL_0199: ldc.r8 0.985
		/* 0x000027AA 735600000A         */ IL_01a2: newobj instance void [PresentationCore]System.Windows.Media.GradientStop::.ctor(valuetype [PresentationCore]System.Windows.Media.Color, float64) /* 0A000056 */
		/* 0x000027AF 6F5700000A         */ IL_01a7: callvirt instance void [PresentationCore]System.Windows.Media.GradientStopCollection::Add(class [PresentationCore]System.Windows.Media.GradientStop) /* 0A000057 */
		/* 0x000027B4 6F5800000A         */ IL_01ac: callvirt instance void [PresentationCore]System.Windows.Media.GradientBrush::set_GradientStops(class [PresentationCore]System.Windows.Media.GradientStopCollection) /* 0A000058 */
		/* 0x000027B9 8009000004         */ IL_01b1: stsfld class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter::HYSYSTitleBackground /* 04000009 */
		/* 0x000027BE 16                 */ IL_01b6: ldc.i4.0
		/* 0x000027BF 20A3000000         */ IL_01b7: ldc.i4 163
		/* 0x000027C4 20D5000000         */ IL_01bc: ldc.i4 213
		/* 0x000027C9 285900000A         */ IL_01c1: call valuetype [PresentationCore]System.Windows.Media.Color [PresentationCore]System.Windows.Media.Color::FromRgb(uint8, uint8, uint8) /* 0A000059 */
		/* 0x000027CE 735A00000A         */ IL_01c6: newobj instance void [PresentationCore]System.Windows.Media.SolidColorBrush::.ctor(valuetype [PresentationCore]System.Windows.Media.Color) /* 0A00005A */
		/* 0x000027D3 800A000004         */ IL_01cb: stsfld class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter::APlusTitleBackground /* 0400000A */
		/* 0x000027D8 2A                 */ IL_01d0: ret
	} // end of method DialogTitleBackgroundConverter::.cctor

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.DialogTitleBackgroundConverter

.class /* 0200000B */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs
	extends [mscorlib]System.EventArgs
{
	// Fields
	.field /* 0400000B */ private initonly class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem '<RecentFile>k__BackingField'
	.custom /* 0C00001F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600002E */ public hidebysig specialname 
		instance class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem get_RecentFile () cil managed 
	{
		.custom /* 0C00002E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x27e5
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000027E5 02                 */ IL_0000: ldarg.0
		/* 0x000027E6 7B0B000004         */ IL_0001: ldfld class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs::'<RecentFile>k__BackingField' /* 0400000B */
		/* 0x000027EB 2A                 */ IL_0006: ret
	} // end of method RecentFileClickedEventArgs::get_RecentFile

	.method /* 0600002F */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem recentFile
		) cil managed 
	{
		// Method begins at RVA 0x27ed
		// Header size: 1
		// Code size: 29 (0x1d)
		.maxstack 8

		/* 0x000027ED 02                 */ IL_0000: ldarg.0
		/* 0x000027EE 285B00000A         */ IL_0001: call instance void [mscorlib]System.EventArgs::.ctor() /* 0A00005B */
		/* 0x000027F3 02                 */ IL_0006: ldarg.0
		/* 0x000027F4 03                 */ IL_0007: ldarg.1
		/* 0x000027F5 25                 */ IL_0008: dup
		/* 0x000027F6 2D0C               */ IL_0009: brtrue.s IL_0017
		/* 0x000027F8 26                 */ IL_000b: pop
		/* 0x000027F9 7251020070         */ IL_000c: ldstr "recentFile" /* 70000251 */
		/* 0x000027FE 731D00000A         */ IL_0011: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x00002803 7A                 */ IL_0016: throw
		/* 0x00002804 7D0B000004         */ IL_0017: stfld class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs::'<RecentFile>k__BackingField' /* 0400000B */
		/* 0x00002809 2A                 */ IL_001c: ret
	} // end of method RecentFileClickedEventArgs::.ctor

	// Properties
	.property /* 1700000C */ instance class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem RecentFile()
	{
		.get instance class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs::get_RecentFile()
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs

.class /* 0200000C */ public auto ansi AspenTech.CommonShell.Controls.Startup.Primitive.IconButton
	extends [PresentationFramework]System.Windows.Controls.Button
{
	// Fields
	.field /* 0400000C */ public static initonly class [WindowsBase]System.Windows.DependencyProperty IconProperty
	.field /* 0400000D */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CaptionProperty

	// Methods
	.method /* 06000030 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.ImageSource get_Icon () cil managed 
	{
		// Method begins at RVA 0x280b
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000280B 02                 */ IL_0000: ldarg.0
		/* 0x0000280C 7E0C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::IconProperty /* 0400000C */
		/* 0x00002811 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002816 7437000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.ImageSource /* 01000037 */
		/* 0x0000281B 2A                 */ IL_0010: ret
	} // end of method IconButton::get_Icon

	.method /* 06000031 */ public hidebysig specialname 
		instance void set_Icon (
			class [PresentationCore]System.Windows.Media.ImageSource 'value'
		) cil managed 
	{
		// Method begins at RVA 0x281d
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000281D 02                 */ IL_0000: ldarg.0
		/* 0x0000281E 7E0C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::IconProperty /* 0400000C */
		/* 0x00002823 03                 */ IL_0006: ldarg.1
		/* 0x00002824 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002829 2A                 */ IL_000c: ret
	} // end of method IconButton::set_Icon

	.method /* 06000032 */ public hidebysig specialname 
		instance string get_Caption () cil managed 
	{
		// Method begins at RVA 0x282b
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000282B 02                 */ IL_0000: ldarg.0
		/* 0x0000282C 7E0D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::CaptionProperty /* 0400000D */
		/* 0x00002831 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002836 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x0000283B 2A                 */ IL_0010: ret
	} // end of method IconButton::get_Caption

	.method /* 06000033 */ public hidebysig specialname 
		instance void set_Caption (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x283d
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000283D 02                 */ IL_0000: ldarg.0
		/* 0x0000283E 7E0D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::CaptionProperty /* 0400000D */
		/* 0x00002843 03                 */ IL_0006: ldarg.1
		/* 0x00002844 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002849 2A                 */ IL_000c: ret
	} // end of method IconButton::set_Caption

	.method /* 06000034 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x284c
		// Header size: 12
		// Code size: 106 (0x6a)
		.maxstack 3

		/* 0x0000284C 7267020070         */ IL_0000: ldstr "Icon" /* 70000267 */
		/* 0x00002851 D037000001         */ IL_0005: ldtoken [PresentationCore]System.Windows.Media.ImageSource /* 01000037 */
		/* 0x00002856 283200000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000285B D00C000002         */ IL_000f: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.IconButton /* 0200000C */
		/* 0x00002860 283200000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002865 283300000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x0000286A 800C000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::IconProperty /* 0400000C */
		/* 0x0000286F 7271020070         */ IL_0023: ldstr "Caption" /* 70000271 */
		/* 0x00002874 D059000001         */ IL_0028: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002879 283200000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000287E D00C000002         */ IL_0032: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.IconButton /* 0200000C */
		/* 0x00002883 283200000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002888 283300000A         */ IL_003c: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x0000288D 800D000004         */ IL_0041: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::CaptionProperty /* 0400000D */
		/* 0x00002892 7E3400000A         */ IL_0046: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A000034 */
		/* 0x00002897 D00C000002         */ IL_004b: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.IconButton /* 0200000C */
		/* 0x0000289C 283200000A         */ IL_0050: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x000028A1 D00C000002         */ IL_0055: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.IconButton /* 0200000C */
		/* 0x000028A6 283200000A         */ IL_005a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x000028AB 733500000A         */ IL_005f: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000035 */
		/* 0x000028B0 6F3600000A         */ IL_0064: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000036 */
		/* 0x000028B5 2A                 */ IL_0069: ret
	} // end of method IconButton::.cctor

	.method /* 06000035 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x28c2
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000028C2 02                 */ IL_0000: ldarg.0
		/* 0x000028C3 285C00000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Button::.ctor() /* 0A00005C */
		/* 0x000028C8 2A                 */ IL_0006: ret
	} // end of method IconButton::.ctor

	// Properties
	.property /* 1700000D */ instance class [PresentationCore]System.Windows.Media.ImageSource Icon()
	{
		.get instance class [PresentationCore]System.Windows.Media.ImageSource AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::get_Icon()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::set_Icon(class [PresentationCore]System.Windows.Media.ImageSource)
	}
	.property /* 1700000E */ instance string Caption()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::get_Caption()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.IconButton::set_Caption(string)
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.IconButton

.class /* 0200000D */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions
	extends [WindowsBase]System.Windows.DependencyObject
{
	// Fields
	.field /* 0400000E */ public static initonly class [WindowsBase]System.Windows.DependencyProperty DialogTitleProperty
	.field /* 0400000F */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ApplicationNameProperty
	.field /* 04000010 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty TitleBackgroundProperty
	.field /* 04000011 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty TitleForegroundProperty
	.field /* 04000012 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ButtonOpenCaptionProperty
	.field /* 04000013 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ButtonNewCaptionProperty
	.field /* 04000014 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFilesListCaptionProperty
	.field /* 04000015 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFilesPlaceholderTextProperty
	.field /* 04000016 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFilesProperty
	.field /* 04000017 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty TagProperty
	.field /* 04000018 */ private class [mscorlib]System.EventHandler ButtonOpenClicked
	.custom /* 0C000022 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000019 */ private class [mscorlib]System.EventHandler ButtonNewClicked
	.custom /* 0C000023 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001A */ private class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> RecentFileClicked
	.custom /* 0C000024 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000036 */ public hidebysig specialname 
		instance string get_DialogTitle () cil managed 
	{
		// Method begins at RVA 0x28ca
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000028CA 02                 */ IL_0000: ldarg.0
		/* 0x000028CB 7E0E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::DialogTitleProperty /* 0400000E */
		/* 0x000028D0 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x000028D5 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x000028DA 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_DialogTitle

	.method /* 06000037 */ public hidebysig specialname 
		instance void set_DialogTitle (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x28dc
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000028DC 02                 */ IL_0000: ldarg.0
		/* 0x000028DD 7E0E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::DialogTitleProperty /* 0400000E */
		/* 0x000028E2 03                 */ IL_0006: ldarg.1
		/* 0x000028E3 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x000028E8 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_DialogTitle

	.method /* 06000038 */ public hidebysig specialname 
		instance string get_ApplicationName () cil managed 
	{
		// Method begins at RVA 0x28ea
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000028EA 02                 */ IL_0000: ldarg.0
		/* 0x000028EB 7E0F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ApplicationNameProperty /* 0400000F */
		/* 0x000028F0 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x000028F5 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x000028FA 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_ApplicationName

	.method /* 06000039 */ public hidebysig specialname 
		instance void set_ApplicationName (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x28fc
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000028FC 02                 */ IL_0000: ldarg.0
		/* 0x000028FD 7E0F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ApplicationNameProperty /* 0400000F */
		/* 0x00002902 03                 */ IL_0006: ldarg.1
		/* 0x00002903 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002908 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_ApplicationName

	.method /* 0600003A */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_TitleBackground () cil managed 
	{
		// Method begins at RVA 0x290a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000290A 02                 */ IL_0000: ldarg.0
		/* 0x0000290B 7E10000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TitleBackgroundProperty /* 04000010 */
		/* 0x00002910 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002915 7434000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000034 */
		/* 0x0000291A 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_TitleBackground

	.method /* 0600003B */ public hidebysig specialname 
		instance void set_TitleBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x291c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000291C 02                 */ IL_0000: ldarg.0
		/* 0x0000291D 7E10000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TitleBackgroundProperty /* 04000010 */
		/* 0x00002922 03                 */ IL_0006: ldarg.1
		/* 0x00002923 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002928 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_TitleBackground

	.method /* 0600003C */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_TitleForeground () cil managed 
	{
		// Method begins at RVA 0x292a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000292A 02                 */ IL_0000: ldarg.0
		/* 0x0000292B 7E11000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TitleForegroundProperty /* 04000011 */
		/* 0x00002930 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002935 7434000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000034 */
		/* 0x0000293A 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_TitleForeground

	.method /* 0600003D */ public hidebysig specialname 
		instance void set_TitleForeground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x293c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000293C 02                 */ IL_0000: ldarg.0
		/* 0x0000293D 7E11000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TitleForegroundProperty /* 04000011 */
		/* 0x00002942 03                 */ IL_0006: ldarg.1
		/* 0x00002943 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002948 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_TitleForeground

	.method /* 0600003E */ public hidebysig specialname 
		instance string get_ButtonOpenCaption () cil managed 
	{
		// Method begins at RVA 0x294a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000294A 02                 */ IL_0000: ldarg.0
		/* 0x0000294B 7E12000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenCaptionProperty /* 04000012 */
		/* 0x00002950 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002955 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x0000295A 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_ButtonOpenCaption

	.method /* 0600003F */ public hidebysig specialname 
		instance void set_ButtonOpenCaption (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x295c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000295C 02                 */ IL_0000: ldarg.0
		/* 0x0000295D 7E12000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenCaptionProperty /* 04000012 */
		/* 0x00002962 03                 */ IL_0006: ldarg.1
		/* 0x00002963 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002968 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_ButtonOpenCaption

	.method /* 06000040 */ public hidebysig specialname 
		instance string get_ButtonNewCaption () cil managed 
	{
		// Method begins at RVA 0x296a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000296A 02                 */ IL_0000: ldarg.0
		/* 0x0000296B 7E13000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewCaptionProperty /* 04000013 */
		/* 0x00002970 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002975 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x0000297A 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_ButtonNewCaption

	.method /* 06000041 */ public hidebysig specialname 
		instance void set_ButtonNewCaption (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x297c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000297C 02                 */ IL_0000: ldarg.0
		/* 0x0000297D 7E13000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewCaptionProperty /* 04000013 */
		/* 0x00002982 03                 */ IL_0006: ldarg.1
		/* 0x00002983 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002988 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_ButtonNewCaption

	.method /* 06000042 */ public hidebysig specialname 
		instance string get_RecentFilesListCaption () cil managed 
	{
		// Method begins at RVA 0x298a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000298A 02                 */ IL_0000: ldarg.0
		/* 0x0000298B 7E14000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesListCaptionProperty /* 04000014 */
		/* 0x00002990 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002995 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x0000299A 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_RecentFilesListCaption

	.method /* 06000043 */ public hidebysig specialname 
		instance void set_RecentFilesListCaption (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x299c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000299C 02                 */ IL_0000: ldarg.0
		/* 0x0000299D 7E14000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesListCaptionProperty /* 04000014 */
		/* 0x000029A2 03                 */ IL_0006: ldarg.1
		/* 0x000029A3 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x000029A8 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_RecentFilesListCaption

	.method /* 06000044 */ public hidebysig specialname 
		instance string get_RecentFilesPlaceholderText () cil managed 
	{
		// Method begins at RVA 0x29aa
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000029AA 02                 */ IL_0000: ldarg.0
		/* 0x000029AB 7E15000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesPlaceholderTextProperty /* 04000015 */
		/* 0x000029B0 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x000029B5 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x000029BA 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_RecentFilesPlaceholderText

	.method /* 06000045 */ public hidebysig specialname 
		instance void set_RecentFilesPlaceholderText (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x29bc
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000029BC 02                 */ IL_0000: ldarg.0
		/* 0x000029BD 7E15000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesPlaceholderTextProperty /* 04000015 */
		/* 0x000029C2 03                 */ IL_0006: ldarg.1
		/* 0x000029C3 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x000029C8 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_RecentFilesPlaceholderText

	.method /* 06000046 */ public hidebysig specialname 
		instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> get_RecentFiles () cil managed 
	{
		// Method begins at RVA 0x29ca
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000029CA 02                 */ IL_0000: ldarg.0
		/* 0x000029CB 7E16000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesProperty /* 04000016 */
		/* 0x000029D0 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x000029D5 740900001B         */ IL_000b: castclass class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> /* 1B000009 */
		/* 0x000029DA 2A                 */ IL_0010: ret
	} // end of method StartupDialogOptions::get_RecentFiles

	.method /* 06000047 */ public hidebysig specialname 
		instance void set_RecentFiles (
			class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x29dc
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000029DC 02                 */ IL_0000: ldarg.0
		/* 0x000029DD 7E16000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesProperty /* 04000016 */
		/* 0x000029E2 03                 */ IL_0006: ldarg.1
		/* 0x000029E3 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x000029E8 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_RecentFiles

	.method /* 06000048 */ public hidebysig specialname 
		instance object get_Tag () cil managed 
	{
		// Method begins at RVA 0x29ea
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000029EA 02                 */ IL_0000: ldarg.0
		/* 0x000029EB 7E17000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TagProperty /* 04000017 */
		/* 0x000029F0 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x000029F5 2A                 */ IL_000b: ret
	} // end of method StartupDialogOptions::get_Tag

	.method /* 06000049 */ public hidebysig specialname 
		instance void set_Tag (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x29f7
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000029F7 02                 */ IL_0000: ldarg.0
		/* 0x000029F8 7E17000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TagProperty /* 04000017 */
		/* 0x000029FD 03                 */ IL_0006: ldarg.1
		/* 0x000029FE 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002A03 2A                 */ IL_000c: ret
	} // end of method StartupDialogOptions::set_Tag

	.method /* 0600004A */ public hidebysig specialname 
		instance void add_ButtonOpenClicked (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00002F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a08
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00002A08 02                 */ IL_0000: ldarg.0
		/* 0x00002A09 7B18000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenClicked /* 04000018 */
		/* 0x00002A0E 0A                 */ IL_0006: stloc.0
		/* 0x00002A0F 06                 */ IL_0007: ldloc.0
		/* 0x00002A10 0B                 */ IL_0008: stloc.1
		/* 0x00002A11 07                 */ IL_0009: ldloc.1
		/* 0x00002A12 03                 */ IL_000a: ldarg.1
		/* 0x00002A13 285D00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00005D */
		/* 0x00002A18 7439000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000039 */
		/* 0x00002A1D 0C                 */ IL_0015: stloc.2
		/* 0x00002A1E 02                 */ IL_0016: ldarg.0
		/* 0x00002A1F 7C18000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenClicked /* 04000018 */
		/* 0x00002A24 08                 */ IL_001c: ldloc.2
		/* 0x00002A25 07                 */ IL_001d: ldloc.1
		/* 0x00002A26 280800002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000008 */
		/* 0x00002A2B 0A                 */ IL_0023: stloc.0
		/* 0x00002A2C 06                 */ IL_0024: ldloc.0
		/* 0x00002A2D 07                 */ IL_0025: ldloc.1
		/* 0x00002A2E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002A30 2A                 */ IL_0028: ret
	} // end of method StartupDialogOptions::add_ButtonOpenClicked

	.method /* 0600004B */ public hidebysig specialname 
		instance void remove_ButtonOpenClicked (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000030 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a40
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00002A40 02                 */ IL_0000: ldarg.0
		/* 0x00002A41 7B18000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenClicked /* 04000018 */
		/* 0x00002A46 0A                 */ IL_0006: stloc.0
		/* 0x00002A47 06                 */ IL_0007: ldloc.0
		/* 0x00002A48 0B                 */ IL_0008: stloc.1
		/* 0x00002A49 07                 */ IL_0009: ldloc.1
		/* 0x00002A4A 03                 */ IL_000a: ldarg.1
		/* 0x00002A4B 285F00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00005F */
		/* 0x00002A50 7439000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000039 */
		/* 0x00002A55 0C                 */ IL_0015: stloc.2
		/* 0x00002A56 02                 */ IL_0016: ldarg.0
		/* 0x00002A57 7C18000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenClicked /* 04000018 */
		/* 0x00002A5C 08                 */ IL_001c: ldloc.2
		/* 0x00002A5D 07                 */ IL_001d: ldloc.1
		/* 0x00002A5E 280800002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000008 */
		/* 0x00002A63 0A                 */ IL_0023: stloc.0
		/* 0x00002A64 06                 */ IL_0024: ldloc.0
		/* 0x00002A65 07                 */ IL_0025: ldloc.1
		/* 0x00002A66 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002A68 2A                 */ IL_0028: ret
	} // end of method StartupDialogOptions::remove_ButtonOpenClicked

	.method /* 0600004C */ public hidebysig specialname 
		instance void add_ButtonNewClicked (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000031 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2a78
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00002A78 02                 */ IL_0000: ldarg.0
		/* 0x00002A79 7B19000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewClicked /* 04000019 */
		/* 0x00002A7E 0A                 */ IL_0006: stloc.0
		/* 0x00002A7F 06                 */ IL_0007: ldloc.0
		/* 0x00002A80 0B                 */ IL_0008: stloc.1
		/* 0x00002A81 07                 */ IL_0009: ldloc.1
		/* 0x00002A82 03                 */ IL_000a: ldarg.1
		/* 0x00002A83 285D00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00005D */
		/* 0x00002A88 7439000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000039 */
		/* 0x00002A8D 0C                 */ IL_0015: stloc.2
		/* 0x00002A8E 02                 */ IL_0016: ldarg.0
		/* 0x00002A8F 7C19000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewClicked /* 04000019 */
		/* 0x00002A94 08                 */ IL_001c: ldloc.2
		/* 0x00002A95 07                 */ IL_001d: ldloc.1
		/* 0x00002A96 280800002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000008 */
		/* 0x00002A9B 0A                 */ IL_0023: stloc.0
		/* 0x00002A9C 06                 */ IL_0024: ldloc.0
		/* 0x00002A9D 07                 */ IL_0025: ldloc.1
		/* 0x00002A9E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002AA0 2A                 */ IL_0028: ret
	} // end of method StartupDialogOptions::add_ButtonNewClicked

	.method /* 0600004D */ public hidebysig specialname 
		instance void remove_ButtonNewClicked (
			class [mscorlib]System.EventHandler 'value'
		) cil managed 
	{
		.custom /* 0C000032 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2ab0
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [mscorlib]System.EventHandler,
			[1] class [mscorlib]System.EventHandler,
			[2] class [mscorlib]System.EventHandler
		)

		/* 0x00002AB0 02                 */ IL_0000: ldarg.0
		/* 0x00002AB1 7B19000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewClicked /* 04000019 */
		/* 0x00002AB6 0A                 */ IL_0006: stloc.0
		/* 0x00002AB7 06                 */ IL_0007: ldloc.0
		/* 0x00002AB8 0B                 */ IL_0008: stloc.1
		/* 0x00002AB9 07                 */ IL_0009: ldloc.1
		/* 0x00002ABA 03                 */ IL_000a: ldarg.1
		/* 0x00002ABB 285F00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00005F */
		/* 0x00002AC0 7439000001         */ IL_0010: castclass [mscorlib]System.EventHandler /* 01000039 */
		/* 0x00002AC5 0C                 */ IL_0015: stloc.2
		/* 0x00002AC6 02                 */ IL_0016: ldarg.0
		/* 0x00002AC7 7C19000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewClicked /* 04000019 */
		/* 0x00002ACC 08                 */ IL_001c: ldloc.2
		/* 0x00002ACD 07                 */ IL_001d: ldloc.1
		/* 0x00002ACE 280800002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler>(!!0&, !!0, !!0) /* 2B000008 */
		/* 0x00002AD3 0A                 */ IL_0023: stloc.0
		/* 0x00002AD4 06                 */ IL_0024: ldloc.0
		/* 0x00002AD5 07                 */ IL_0025: ldloc.1
		/* 0x00002AD6 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002AD8 2A                 */ IL_0028: ret
	} // end of method StartupDialogOptions::remove_ButtonNewClicked

	.method /* 0600004E */ public hidebysig specialname 
		instance void add_RecentFileClicked (
			class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> 'value'
		) cil managed 
	{
		.custom /* 0C000033 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2ae8
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000C */ init (
			[0] class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>,
			[1] class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>,
			[2] class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>
		)

		/* 0x00002AE8 02                 */ IL_0000: ldarg.0
		/* 0x00002AE9 7B1A000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFileClicked /* 0400001A */
		/* 0x00002AEE 0A                 */ IL_0006: stloc.0
		/* 0x00002AEF 06                 */ IL_0007: ldloc.0
		/* 0x00002AF0 0B                 */ IL_0008: stloc.1
		/* 0x00002AF1 07                 */ IL_0009: ldloc.1
		/* 0x00002AF2 03                 */ IL_000a: ldarg.1
		/* 0x00002AF3 285D00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00005D */
		/* 0x00002AF8 740300001B         */ IL_0010: castclass class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> /* 1B000003 */
		/* 0x00002AFD 0C                 */ IL_0015: stloc.2
		/* 0x00002AFE 02                 */ IL_0016: ldarg.0
		/* 0x00002AFF 7C1A000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFileClicked /* 0400001A */
		/* 0x00002B04 08                 */ IL_001c: ldloc.2
		/* 0x00002B05 07                 */ IL_001d: ldloc.1
		/* 0x00002B06 280900002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>>(!!0&, !!0, !!0) /* 2B000009 */
		/* 0x00002B0B 0A                 */ IL_0023: stloc.0
		/* 0x00002B0C 06                 */ IL_0024: ldloc.0
		/* 0x00002B0D 07                 */ IL_0025: ldloc.1
		/* 0x00002B0E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002B10 2A                 */ IL_0028: ret
	} // end of method StartupDialogOptions::add_RecentFileClicked

	.method /* 0600004F */ public hidebysig specialname 
		instance void remove_RecentFileClicked (
			class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> 'value'
		) cil managed 
	{
		.custom /* 0C000034 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b20
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000C */ init (
			[0] class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>,
			[1] class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>,
			[2] class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>
		)

		/* 0x00002B20 02                 */ IL_0000: ldarg.0
		/* 0x00002B21 7B1A000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFileClicked /* 0400001A */
		/* 0x00002B26 0A                 */ IL_0006: stloc.0
		/* 0x00002B27 06                 */ IL_0007: ldloc.0
		/* 0x00002B28 0B                 */ IL_0008: stloc.1
		/* 0x00002B29 07                 */ IL_0009: ldloc.1
		/* 0x00002B2A 03                 */ IL_000a: ldarg.1
		/* 0x00002B2B 285F00000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A00005F */
		/* 0x00002B30 740300001B         */ IL_0010: castclass class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> /* 1B000003 */
		/* 0x00002B35 0C                 */ IL_0015: stloc.2
		/* 0x00002B36 02                 */ IL_0016: ldarg.0
		/* 0x00002B37 7C1A000004         */ IL_0017: ldflda class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFileClicked /* 0400001A */
		/* 0x00002B3C 08                 */ IL_001c: ldloc.2
		/* 0x00002B3D 07                 */ IL_001d: ldloc.1
		/* 0x00002B3E 280900002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>>(!!0&, !!0, !!0) /* 2B000009 */
		/* 0x00002B43 0A                 */ IL_0023: stloc.0
		/* 0x00002B44 06                 */ IL_0024: ldloc.0
		/* 0x00002B45 07                 */ IL_0025: ldloc.1
		/* 0x00002B46 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002B48 2A                 */ IL_0028: ret
	} // end of method StartupDialogOptions::remove_RecentFileClicked

	.method /* 06000050 */ famorassem hidebysig newslot virtual 
		instance void OnButtonOpenClicked () cil managed 
	{
		// Method begins at RVA 0x2b55
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x00002B55 02                 */ IL_0000: ldarg.0
		/* 0x00002B56 7B18000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenClicked /* 04000018 */
		/* 0x00002B5B 25                 */ IL_0006: dup
		/* 0x00002B5C 2D02               */ IL_0007: brtrue.s IL_000b
		/* 0x00002B5E 26                 */ IL_0009: pop
		/* 0x00002B5F 2A                 */ IL_000a: ret
		/* 0x00002B60 02                 */ IL_000b: ldarg.0
		/* 0x00002B61 7E6000000A         */ IL_000c: ldsfld class [mscorlib]System.EventArgs [mscorlib]System.EventArgs::Empty /* 0A000060 */
		/* 0x00002B66 6F6100000A         */ IL_0011: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs) /* 0A000061 */
		/* 0x00002B6B 2A                 */ IL_0016: ret
	} // end of method StartupDialogOptions::OnButtonOpenClicked

	.method /* 06000051 */ famorassem hidebysig newslot virtual 
		instance void OnButtonNewClicked () cil managed 
	{
		// Method begins at RVA 0x2b6d
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x00002B6D 02                 */ IL_0000: ldarg.0
		/* 0x00002B6E 7B19000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewClicked /* 04000019 */
		/* 0x00002B73 25                 */ IL_0006: dup
		/* 0x00002B74 2D02               */ IL_0007: brtrue.s IL_000b
		/* 0x00002B76 26                 */ IL_0009: pop
		/* 0x00002B77 2A                 */ IL_000a: ret
		/* 0x00002B78 02                 */ IL_000b: ldarg.0
		/* 0x00002B79 7E6000000A         */ IL_000c: ldsfld class [mscorlib]System.EventArgs [mscorlib]System.EventArgs::Empty /* 0A000060 */
		/* 0x00002B7E 6F6100000A         */ IL_0011: callvirt instance void [mscorlib]System.EventHandler::Invoke(object, class [mscorlib]System.EventArgs) /* 0A000061 */
		/* 0x00002B83 2A                 */ IL_0016: ret
	} // end of method StartupDialogOptions::OnButtonNewClicked

	.method /* 06000052 */ famorassem hidebysig newslot virtual 
		instance void OnRecentFileClicked (
			class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem recentFile
		) cil managed 
	{
		// Method begins at RVA 0x2b85
		// Header size: 1
		// Code size: 24 (0x18)
		.maxstack 8

		/* 0x00002B85 02                 */ IL_0000: ldarg.0
		/* 0x00002B86 7B1A000004         */ IL_0001: ldfld class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFileClicked /* 0400001A */
		/* 0x00002B8B 25                 */ IL_0006: dup
		/* 0x00002B8C 2D02               */ IL_0007: brtrue.s IL_000b
		/* 0x00002B8E 26                 */ IL_0009: pop
		/* 0x00002B8F 2A                 */ IL_000a: ret
		/* 0x00002B90 02                 */ IL_000b: ldarg.0
		/* 0x00002B91 03                 */ IL_000c: ldarg.1
		/* 0x00002B92 732F000006         */ IL_000d: newobj instance void AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs::.ctor(class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem) /* 0600002F */
		/* 0x00002B97 6F6200000A         */ IL_0012: callvirt instance void class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>::Invoke(object, !0) /* 0A000062 */
		/* 0x00002B9C 2A                 */ IL_0017: ret
	} // end of method StartupDialogOptions::OnRecentFileClicked

	.method /* 06000053 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2b9e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002B9E 02                 */ IL_0000: ldarg.0
		/* 0x00002B9F 286300000A         */ IL_0001: call instance void [WindowsBase]System.Windows.DependencyObject::.ctor() /* 0A000063 */
		/* 0x00002BA4 2A                 */ IL_0006: ret
	} // end of method StartupDialogOptions::.ctor

	.method /* 06000054 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2ba8
		// Header size: 12
		// Code size: 406 (0x196)
		.maxstack 4

		/* 0x00002BA8 7281020070         */ IL_0000: ldstr "DialogTitle" /* 70000281 */
		/* 0x00002BAD D059000001         */ IL_0005: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002BB2 283200000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002BB7 D00D000002         */ IL_000f: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002BBC 283200000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002BC1 283300000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00002BC6 800E000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::DialogTitleProperty /* 0400000E */
		/* 0x00002BCB 7299020070         */ IL_0023: ldstr "ApplicationName" /* 70000299 */
		/* 0x00002BD0 D059000001         */ IL_0028: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002BD5 283200000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002BDA D00D000002         */ IL_0032: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002BDF 283200000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002BE4 283300000A         */ IL_003c: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00002BE9 800F000004         */ IL_0041: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ApplicationNameProperty /* 0400000F */
		/* 0x00002BEE 72B9020070         */ IL_0046: ldstr "TitleBackground" /* 700002B9 */
		/* 0x00002BF3 D034000001         */ IL_004b: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000034 */
		/* 0x00002BF8 283200000A         */ IL_0050: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002BFD D00D000002         */ IL_0055: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002C02 283200000A         */ IL_005a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C07 736400000A         */ IL_005f: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor() /* 0A000064 */
		/* 0x00002C0C 286500000A         */ IL_0064: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002C11 8010000004         */ IL_0069: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TitleBackgroundProperty /* 04000010 */
		/* 0x00002C16 72D9020070         */ IL_006e: ldstr "TitleForeground" /* 700002D9 */
		/* 0x00002C1B D034000001         */ IL_0073: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000034 */
		/* 0x00002C20 283200000A         */ IL_0078: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C25 D00D000002         */ IL_007d: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002C2A 283200000A         */ IL_0082: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C2F 286600000A         */ IL_0087: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_White() /* 0A000066 */
		/* 0x00002C34 736700000A         */ IL_008c: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00002C39 286500000A         */ IL_0091: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002C3E 8011000004         */ IL_0096: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TitleForegroundProperty /* 04000011 */
		/* 0x00002C43 72F9020070         */ IL_009b: ldstr "ButtonOpenCaption" /* 700002F9 */
		/* 0x00002C48 D059000001         */ IL_00a0: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002C4D 283200000A         */ IL_00a5: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C52 D00D000002         */ IL_00aa: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002C57 283200000A         */ IL_00af: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C5C 2815000006         */ IL_00b4: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_Button_Open_Caption() /* 06000015 */
		/* 0x00002C61 736700000A         */ IL_00b9: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00002C66 286500000A         */ IL_00be: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002C6B 8012000004         */ IL_00c3: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonOpenCaptionProperty /* 04000012 */
		/* 0x00002C70 721D030070         */ IL_00c8: ldstr "ButtonNewCaption" /* 7000031D */
		/* 0x00002C75 D059000001         */ IL_00cd: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002C7A 283200000A         */ IL_00d2: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C7F D00D000002         */ IL_00d7: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002C84 283200000A         */ IL_00dc: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002C89 2814000006         */ IL_00e1: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_Button_New_Caption() /* 06000014 */
		/* 0x00002C8E 736700000A         */ IL_00e6: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00002C93 286500000A         */ IL_00eb: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002C98 8013000004         */ IL_00f0: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::ButtonNewCaptionProperty /* 04000013 */
		/* 0x00002C9D 723F030070         */ IL_00f5: ldstr "RecentFilesListCaption" /* 7000033F */
		/* 0x00002CA2 D059000001         */ IL_00fa: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002CA7 283200000A         */ IL_00ff: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002CAC D00D000002         */ IL_0104: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002CB1 283200000A         */ IL_0109: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002CB6 2816000006         */ IL_010e: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_RecentFileList_Caption() /* 06000016 */
		/* 0x00002CBB 736700000A         */ IL_0113: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00002CC0 286500000A         */ IL_0118: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002CC5 8014000004         */ IL_011d: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesListCaptionProperty /* 04000014 */
		/* 0x00002CCA 726D030070         */ IL_0122: ldstr "RecentFilesPlaceholderText" /* 7000036D */
		/* 0x00002CCF D059000001         */ IL_0127: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002CD4 283200000A         */ IL_012c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002CD9 D00D000002         */ IL_0131: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002CDE 283200000A         */ IL_0136: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002CE3 2817000006         */ IL_013b: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_RecentFileList_Placeholder() /* 06000017 */
		/* 0x00002CE8 736700000A         */ IL_0140: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00002CED 286500000A         */ IL_0145: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002CF2 8015000004         */ IL_014a: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesPlaceholderTextProperty /* 04000015 */
		/* 0x00002CF7 72A3030070         */ IL_014f: ldstr "RecentFiles" /* 700003A3 */
		/* 0x00002CFC D00900001B         */ IL_0154: ldtoken class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> /* 1B000009 */
		/* 0x00002D01 283200000A         */ IL_0159: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002D06 D00D000002         */ IL_015e: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002D0B 283200000A         */ IL_0163: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002D10 283300000A         */ IL_0168: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00002D15 8016000004         */ IL_016d: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::RecentFilesProperty /* 04000016 */
		/* 0x00002D1A 72BB030070         */ IL_0172: ldstr "Tag" /* 700003BB */
		/* 0x00002D1F D012000001         */ IL_0177: ldtoken [mscorlib]System.Object /* 01000012 */
		/* 0x00002D24 283200000A         */ IL_017c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002D29 D00D000002         */ IL_0181: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002D2E 283200000A         */ IL_0186: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002D33 283300000A         */ IL_018b: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00002D38 8017000004         */ IL_0190: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::TagProperty /* 04000017 */
		/* 0x00002D3D 2A                 */ IL_0195: ret
	} // end of method StartupDialogOptions::.cctor

	// Events
	.event /* 14000001 */ [mscorlib]System.EventHandler ButtonOpenClicked
	{
		.addon instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::add_ButtonOpenClicked(class [mscorlib]System.EventHandler)
		.removeon instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::remove_ButtonOpenClicked(class [mscorlib]System.EventHandler)
	}

	.event /* 14000002 */ [mscorlib]System.EventHandler ButtonNewClicked
	{
		.addon instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::add_ButtonNewClicked(class [mscorlib]System.EventHandler)
		.removeon instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::remove_ButtonNewClicked(class [mscorlib]System.EventHandler)
	}

	.event /* 14000003 */ class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs> RecentFileClicked
	{
		.addon instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::add_RecentFileClicked(class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>)
		.removeon instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::remove_RecentFileClicked(class [mscorlib]System.EventHandler`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileClickedEventArgs>)
	}


	// Properties
	.property /* 1700000F */ instance string DialogTitle()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_DialogTitle()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_DialogTitle(string)
	}
	.property /* 17000010 */ instance string ApplicationName()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_ApplicationName()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_ApplicationName(string)
	}
	.property /* 17000011 */ instance class [PresentationCore]System.Windows.Media.Brush TitleBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_TitleBackground()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_TitleBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000012 */ instance class [PresentationCore]System.Windows.Media.Brush TitleForeground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_TitleForeground()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_TitleForeground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000013 */ instance string ButtonOpenCaption()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_ButtonOpenCaption()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_ButtonOpenCaption(string)
	}
	.property /* 17000014 */ instance string ButtonNewCaption()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_ButtonNewCaption()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_ButtonNewCaption(string)
	}
	.property /* 17000015 */ instance string RecentFilesListCaption()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_RecentFilesListCaption()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_RecentFilesListCaption(string)
	}
	.property /* 17000016 */ instance string RecentFilesPlaceholderText()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_RecentFilesPlaceholderText()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_RecentFilesPlaceholderText(string)
	}
	.property /* 17000017 */ instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> RecentFiles()
	{
		.get instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_RecentFiles()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_RecentFiles(class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem>)
	}
	.property /* 17000018 */ instance object Tag()
	{
		.get instance object AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::get_Tag()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::set_Tag(object)
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions

.class /* 0200000E */ public auto ansi AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl
	extends [PresentationFramework]System.Windows.Controls.Control
{
	// Fields
	.field /* 0400001B */ public static initonly class [WindowsBase]System.Windows.DependencyProperty OptionsProperty
	.field /* 0400001C */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CloseCommandProperty
	.field /* 0400001D */ private initonly class [System]System.Windows.Input.ICommand '<OpenCommand>k__BackingField'
	.custom /* 0C000027 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001E */ private initonly class [System]System.Windows.Input.ICommand '<NewCommand>k__BackingField'
	.custom /* 0C000028 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001F */ private initonly class [System]System.Windows.Input.ICommand '<RecentFileCommand>k__BackingField'
	.custom /* 0C000029 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000055 */ public hidebysig specialname 
		instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions get_Options () cil managed 
	{
		// Method begins at RVA 0x2d4a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002D4A 02                 */ IL_0000: ldarg.0
		/* 0x00002D4B 7E1B000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::OptionsProperty /* 0400001B */
		/* 0x00002D50 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002D55 740D000002         */ IL_000b: castclass AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002D5A 2A                 */ IL_0010: ret
	} // end of method StartupControl::get_Options

	.method /* 06000056 */ public hidebysig specialname 
		instance void set_Options (
			class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2d5c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002D5C 02                 */ IL_0000: ldarg.0
		/* 0x00002D5D 7E1B000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::OptionsProperty /* 0400001B */
		/* 0x00002D62 03                 */ IL_0006: ldarg.1
		/* 0x00002D63 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002D68 2A                 */ IL_000c: ret
	} // end of method StartupControl::set_Options

	.method /* 06000057 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_CloseCommand () cil managed 
	{
		// Method begins at RVA 0x2d6a
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002D6A 02                 */ IL_0000: ldarg.0
		/* 0x00002D6B 7E1C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::CloseCommandProperty /* 0400001C */
		/* 0x00002D70 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002D75 7426000001         */ IL_000b: castclass [System]System.Windows.Input.ICommand /* 01000026 */
		/* 0x00002D7A 2A                 */ IL_0010: ret
	} // end of method StartupControl::get_CloseCommand

	.method /* 06000058 */ public hidebysig specialname 
		instance void set_CloseCommand (
			class [System]System.Windows.Input.ICommand 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2d7c
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002D7C 02                 */ IL_0000: ldarg.0
		/* 0x00002D7D 7E1C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::CloseCommandProperty /* 0400001C */
		/* 0x00002D82 03                 */ IL_0006: ldarg.1
		/* 0x00002D83 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002D88 2A                 */ IL_000c: ret
	} // end of method StartupControl::set_CloseCommand

	.method /* 06000059 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_OpenCommand () cil managed 
	{
		.custom /* 0C000035 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2d8a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002D8A 02                 */ IL_0000: ldarg.0
		/* 0x00002D8B 7B1D000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::'<OpenCommand>k__BackingField' /* 0400001D */
		/* 0x00002D90 2A                 */ IL_0006: ret
	} // end of method StartupControl::get_OpenCommand

	.method /* 0600005A */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_NewCommand () cil managed 
	{
		.custom /* 0C000036 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2d92
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002D92 02                 */ IL_0000: ldarg.0
		/* 0x00002D93 7B1E000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::'<NewCommand>k__BackingField' /* 0400001E */
		/* 0x00002D98 2A                 */ IL_0006: ret
	} // end of method StartupControl::get_NewCommand

	.method /* 0600005B */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_RecentFileCommand () cil managed 
	{
		.custom /* 0C000037 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2d9a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002D9A 02                 */ IL_0000: ldarg.0
		/* 0x00002D9B 7B1F000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::'<RecentFileCommand>k__BackingField' /* 0400001F */
		/* 0x00002DA0 2A                 */ IL_0006: ret
	} // end of method StartupControl::get_RecentFileCommand

	.method /* 0600005C */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2da4
		// Header size: 12
		// Code size: 106 (0x6a)
		.maxstack 3

		/* 0x00002DA4 721F000070         */ IL_0000: ldstr "Options" /* 7000001F */
		/* 0x00002DA9 D00D000002         */ IL_0005: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions /* 0200000D */
		/* 0x00002DAE 283200000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002DB3 D00E000002         */ IL_000f: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl /* 0200000E */
		/* 0x00002DB8 283200000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002DBD 283300000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00002DC2 801B000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::OptionsProperty /* 0400001B */
		/* 0x00002DC7 72C3030070         */ IL_0023: ldstr "CloseCommand" /* 700003C3 */
		/* 0x00002DCC D026000001         */ IL_0028: ldtoken [System]System.Windows.Input.ICommand /* 01000026 */
		/* 0x00002DD1 283200000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002DD6 D00E000002         */ IL_0032: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl /* 0200000E */
		/* 0x00002DDB 283200000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002DE0 283300000A         */ IL_003c: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00002DE5 801C000004         */ IL_0041: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::CloseCommandProperty /* 0400001C */
		/* 0x00002DEA 7E3400000A         */ IL_0046: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A000034 */
		/* 0x00002DEF D00E000002         */ IL_004b: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl /* 0200000E */
		/* 0x00002DF4 283200000A         */ IL_0050: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002DF9 D00E000002         */ IL_0055: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl /* 0200000E */
		/* 0x00002DFE 283200000A         */ IL_005a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002E03 733500000A         */ IL_005f: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000035 */
		/* 0x00002E08 6F3600000A         */ IL_0064: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000036 */
		/* 0x00002E0D 2A                 */ IL_0069: ret
	} // end of method StartupControl::.cctor

	.method /* 0600005D */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2e1c
		// Header size: 12
		// Code size: 76 (0x4c)
		.maxstack 3

		/* 0x00002E1C 02                 */ IL_0000: ldarg.0
		/* 0x00002E1D 283700000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Control::.ctor() /* 0A000037 */
		/* 0x00002E22 02                 */ IL_0006: ldarg.0
		/* 0x00002E23 02                 */ IL_0007: ldarg.0
		/* 0x00002E24 FE065E000006       */ IL_0008: ldftn instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::OpenCommand_Execute() /* 0600005E */
		/* 0x00002E2A 733B00000A         */ IL_000e: newobj instance void [mscorlib]System.Action::.ctor(object, native int) /* 0A00003B */
		/* 0x00002E2F 733C00000A         */ IL_0013: newobj instance void [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand::.ctor(class [mscorlib]System.Action) /* 0A00003C */
		/* 0x00002E34 7D1D000004         */ IL_0018: stfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::'<OpenCommand>k__BackingField' /* 0400001D */
		/* 0x00002E39 02                 */ IL_001d: ldarg.0
		/* 0x00002E3A 02                 */ IL_001e: ldarg.0
		/* 0x00002E3B FE065F000006       */ IL_001f: ldftn instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::NewCommand_Execute() /* 0600005F */
		/* 0x00002E41 733B00000A         */ IL_0025: newobj instance void [mscorlib]System.Action::.ctor(object, native int) /* 0A00003B */
		/* 0x00002E46 733C00000A         */ IL_002a: newobj instance void [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand::.ctor(class [mscorlib]System.Action) /* 0A00003C */
		/* 0x00002E4B 7D1E000004         */ IL_002f: stfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::'<NewCommand>k__BackingField' /* 0400001E */
		/* 0x00002E50 02                 */ IL_0034: ldarg.0
		/* 0x00002E51 02                 */ IL_0035: ldarg.0
		/* 0x00002E52 FE0660000006       */ IL_0036: ldftn instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::RecentFileCommand_Execute(object) /* 06000060 */
		/* 0x00002E58 736800000A         */ IL_003c: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000068 */
		/* 0x00002E5D 736900000A         */ IL_0041: newobj instance void class [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>) /* 0A000069 */
		/* 0x00002E62 7D1F000004         */ IL_0046: stfld class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::'<RecentFileCommand>k__BackingField' /* 0400001F */
		/* 0x00002E67 2A                 */ IL_004b: ret
	} // end of method StartupControl::.ctor

	.method /* 0600005E */ private hidebysig 
		instance void OpenCommand_Execute () cil managed 
	{
		// Method begins at RVA 0x2e74
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002E74 02                 */ IL_0000: ldarg.0
		/* 0x00002E75 2855000006         */ IL_0001: call instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_Options() /* 06000055 */
		/* 0x00002E7A 25                 */ IL_0006: dup
		/* 0x00002E7B 2D02               */ IL_0007: brtrue.s IL_000b
		/* 0x00002E7D 26                 */ IL_0009: pop
		/* 0x00002E7E 2A                 */ IL_000a: ret
		/* 0x00002E7F 6F50000006         */ IL_000b: callvirt instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::OnButtonOpenClicked() /* 06000050 */
		/* 0x00002E84 2A                 */ IL_0010: ret
	} // end of method StartupControl::OpenCommand_Execute

	.method /* 0600005F */ private hidebysig 
		instance void NewCommand_Execute () cil managed 
	{
		// Method begins at RVA 0x2e86
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002E86 02                 */ IL_0000: ldarg.0
		/* 0x00002E87 2855000006         */ IL_0001: call instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_Options() /* 06000055 */
		/* 0x00002E8C 25                 */ IL_0006: dup
		/* 0x00002E8D 2D02               */ IL_0007: brtrue.s IL_000b
		/* 0x00002E8F 26                 */ IL_0009: pop
		/* 0x00002E90 2A                 */ IL_000a: ret
		/* 0x00002E91 6F51000006         */ IL_000b: callvirt instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::OnButtonNewClicked() /* 06000051 */
		/* 0x00002E96 2A                 */ IL_0010: ret
	} // end of method StartupControl::NewCommand_Execute

	.method /* 06000060 */ private hidebysig 
		instance void RecentFileCommand_Execute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2e98
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x00002E98 02                 */ IL_0000: ldarg.0
		/* 0x00002E99 2855000006         */ IL_0001: call instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_Options() /* 06000055 */
		/* 0x00002E9E 25                 */ IL_0006: dup
		/* 0x00002E9F 2D02               */ IL_0007: brtrue.s IL_000b
		/* 0x00002EA1 26                 */ IL_0009: pop
		/* 0x00002EA2 2A                 */ IL_000a: ret
		/* 0x00002EA3 03                 */ IL_000b: ldarg.1
		/* 0x00002EA4 750F000002         */ IL_000c: isinst AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem /* 0200000F */
		/* 0x00002EA9 6F52000006         */ IL_0011: callvirt instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions::OnRecentFileClicked(class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem) /* 06000052 */
		/* 0x00002EAE 2A                 */ IL_0016: ret
	} // end of method StartupControl::RecentFileCommand_Execute

	// Properties
	.property /* 17000019 */ instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions Options()
	{
		.get instance class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_Options()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::set_Options(class AspenTech.CommonShell.Controls.Startup.Primitive.StartupDialogOptions)
	}
	.property /* 1700001A */ instance class [System]System.Windows.Input.ICommand CloseCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_CloseCommand()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::set_CloseCommand(class [System]System.Windows.Input.ICommand)
	}
	.property /* 1700001B */ instance class [System]System.Windows.Input.ICommand OpenCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_OpenCommand()
	}
	.property /* 1700001C */ instance class [System]System.Windows.Input.ICommand NewCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_NewCommand()
	}
	.property /* 1700001D */ instance class [System]System.Windows.Input.ICommand RecentFileCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl::get_RecentFileCommand()
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.StartupControl

.class /* 0200000F */ public auto ansi beforefieldinit AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 04000020 */ private initonly string '<FilePath>k__BackingField'
	.custom /* 0C00002A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000021 */ private initonly class [PresentationCore]System.Windows.Media.ImageSource '<FileIcon>k__BackingField'
	.custom /* 0C00002B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000022 */ private initonly string '<FileName>k__BackingField'
	.custom /* 0C00002C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000023 */ private initonly valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime> '<ModifiedTime>k__BackingField'
	.custom /* 0C00002D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000061 */ public hidebysig specialname 
		instance string get_FilePath () cil managed 
	{
		.custom /* 0C000038 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2eb0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002EB0 02                 */ IL_0000: ldarg.0
		/* 0x00002EB1 7B20000004         */ IL_0001: ldfld string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<FilePath>k__BackingField' /* 04000020 */
		/* 0x00002EB6 2A                 */ IL_0006: ret
	} // end of method RecentFileItem::get_FilePath

	.method /* 06000062 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.ImageSource get_FileIcon () cil managed 
	{
		.custom /* 0C000039 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2eb8
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002EB8 02                 */ IL_0000: ldarg.0
		/* 0x00002EB9 7B21000004         */ IL_0001: ldfld class [PresentationCore]System.Windows.Media.ImageSource AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<FileIcon>k__BackingField' /* 04000021 */
		/* 0x00002EBE 2A                 */ IL_0006: ret
	} // end of method RecentFileItem::get_FileIcon

	.method /* 06000063 */ public hidebysig specialname 
		instance string get_FileName () cil managed 
	{
		.custom /* 0C00003A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2ec0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002EC0 02                 */ IL_0000: ldarg.0
		/* 0x00002EC1 7B22000004         */ IL_0001: ldfld string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<FileName>k__BackingField' /* 04000022 */
		/* 0x00002EC6 2A                 */ IL_0006: ret
	} // end of method RecentFileItem::get_FileName

	.method /* 06000064 */ public hidebysig specialname 
		instance valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime> get_ModifiedTime () cil managed 
	{
		.custom /* 0C00003B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2ec8
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002EC8 02                 */ IL_0000: ldarg.0
		/* 0x00002EC9 7B23000004         */ IL_0001: ldfld valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime> AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<ModifiedTime>k__BackingField' /* 04000023 */
		/* 0x00002ECE 2A                 */ IL_0006: ret
	} // end of method RecentFileItem::get_ModifiedTime

	.method /* 06000065 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			string filePath,
			class [PresentationCore]System.Windows.Media.ImageSource fileIcon
		) cil managed 
	{
		// Method begins at RVA 0x2ed0
		// Header size: 12
		// Code size: 116 (0x74)
		.maxstack 3

		/* 0x00002ED0 02                 */ IL_0000: ldarg.0
		/* 0x00002ED1 284400000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A000044 */
		/* 0x00002ED6 02                 */ IL_0006: ldarg.0
		/* 0x00002ED7 03                 */ IL_0007: ldarg.1
		/* 0x00002ED8 25                 */ IL_0008: dup
		/* 0x00002ED9 2D0C               */ IL_0009: brtrue.s IL_0017
		/* 0x00002EDB 26                 */ IL_000b: pop
		/* 0x00002EDC 72DD030070         */ IL_000c: ldstr "filePath" /* 700003DD */
		/* 0x00002EE1 731D00000A         */ IL_0011: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x00002EE6 7A                 */ IL_0016: throw
		/* 0x00002EE7 7D20000004         */ IL_0017: stfld string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<FilePath>k__BackingField' /* 04000020 */
		/* 0x00002EEC 02                 */ IL_001c: ldarg.0
		/* 0x00002EED 04                 */ IL_001d: ldarg.2
		/* 0x00002EEE 25                 */ IL_001e: dup
		/* 0x00002EEF 2D0C               */ IL_001f: brtrue.s IL_002d
		/* 0x00002EF1 26                 */ IL_0021: pop
		/* 0x00002EF2 72EF030070         */ IL_0022: ldstr "fileIcon" /* 700003EF */
		/* 0x00002EF7 731D00000A         */ IL_0027: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A00001D */
		/* 0x00002EFC 7A                 */ IL_002c: throw
		/* 0x00002EFD 7D21000004         */ IL_002d: stfld class [PresentationCore]System.Windows.Media.ImageSource AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<FileIcon>k__BackingField' /* 04000021 */
		/* 0x00002F02 02                 */ IL_0032: ldarg.0
		/* 0x00002F03 2861000006         */ IL_0033: call instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FilePath() /* 06000061 */
		/* 0x00002F08 286A00000A         */ IL_0038: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00006A */
		/* 0x00002F0D 2D34               */ IL_003d: brtrue.s IL_0073
		/* 0x00002F0F 02                 */ IL_003f: ldarg.0
		/* 0x00002F10 02                 */ IL_0040: ldarg.0
		/* 0x00002F11 2861000006         */ IL_0041: call instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FilePath() /* 06000061 */
		/* 0x00002F16 286B00000A         */ IL_0046: call string [mscorlib]System.IO.Path::GetFileName(string) /* 0A00006B */
		/* 0x00002F1B 7D22000004         */ IL_004b: stfld string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<FileName>k__BackingField' /* 04000022 */
		/* 0x00002F20 02                 */ IL_0050: ldarg.0
		/* 0x00002F21 2861000006         */ IL_0051: call instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FilePath() /* 06000061 */
		/* 0x00002F26 286C00000A         */ IL_0056: call bool [mscorlib]System.IO.File::Exists(string) /* 0A00006C */
		/* 0x00002F2B 2C16               */ IL_005b: brfalse.s IL_0073
		/* 0x00002F2D 02                 */ IL_005d: ldarg.0
		/* 0x00002F2E 02                 */ IL_005e: ldarg.0
		/* 0x00002F2F 2861000006         */ IL_005f: call instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FilePath() /* 06000061 */
		/* 0x00002F34 286D00000A         */ IL_0064: call valuetype [mscorlib]System.DateTime [mscorlib]System.IO.File::GetLastAccessTime(string) /* 0A00006D */
		/* 0x00002F39 736E00000A         */ IL_0069: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime>::.ctor(!0) /* 0A00006E */
		/* 0x00002F3E 7D23000004         */ IL_006e: stfld valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime> AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::'<ModifiedTime>k__BackingField' /* 04000023 */
		/* 0x00002F43 2A                 */ IL_0073: ret
	} // end of method RecentFileItem::.ctor

	// Properties
	.property /* 1700001E */ instance string FilePath()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FilePath()
	}
	.property /* 1700001F */ instance class [PresentationCore]System.Windows.Media.ImageSource FileIcon()
	{
		.get instance class [PresentationCore]System.Windows.Media.ImageSource AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FileIcon()
	}
	.property /* 17000020 */ instance string FileName()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_FileName()
	}
	.property /* 17000021 */ instance valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime> ModifiedTime()
	{
		.get instance valuetype [mscorlib]System.Nullable`1<valuetype [mscorlib]System.DateTime> AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem::get_ModifiedTime()
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem

.class /* 02000010 */ public auto ansi AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl
	extends [PresentationFramework]System.Windows.Controls.Control
{
	// Fields
	.field /* 04000024 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFilesListCaptionProperty
	.field /* 04000025 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFilesPlaceholderTextProperty
	.field /* 04000026 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFilesProperty
	.field /* 04000027 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty RecentFileCommandProperty

	// Methods
	.method /* 06000066 */ public hidebysig specialname 
		instance string get_RecentFilesListCaption () cil managed 
	{
		// Method begins at RVA 0x2f50
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002F50 02                 */ IL_0000: ldarg.0
		/* 0x00002F51 7E24000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesListCaptionProperty /* 04000024 */
		/* 0x00002F56 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002F5B 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x00002F60 2A                 */ IL_0010: ret
	} // end of method RecentFileListControl::get_RecentFilesListCaption

	.method /* 06000067 */ public hidebysig specialname 
		instance void set_RecentFilesListCaption (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2f62
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002F62 02                 */ IL_0000: ldarg.0
		/* 0x00002F63 7E24000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesListCaptionProperty /* 04000024 */
		/* 0x00002F68 03                 */ IL_0006: ldarg.1
		/* 0x00002F69 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002F6E 2A                 */ IL_000c: ret
	} // end of method RecentFileListControl::set_RecentFilesListCaption

	.method /* 06000068 */ public hidebysig specialname 
		instance string get_RecentFilesPlaceholderText () cil managed 
	{
		// Method begins at RVA 0x2f70
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002F70 02                 */ IL_0000: ldarg.0
		/* 0x00002F71 7E25000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesPlaceholderTextProperty /* 04000025 */
		/* 0x00002F76 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002F7B 7459000001         */ IL_000b: castclass [mscorlib]System.String /* 01000059 */
		/* 0x00002F80 2A                 */ IL_0010: ret
	} // end of method RecentFileListControl::get_RecentFilesPlaceholderText

	.method /* 06000069 */ public hidebysig specialname 
		instance void set_RecentFilesPlaceholderText (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2f82
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002F82 02                 */ IL_0000: ldarg.0
		/* 0x00002F83 7E25000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesPlaceholderTextProperty /* 04000025 */
		/* 0x00002F88 03                 */ IL_0006: ldarg.1
		/* 0x00002F89 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002F8E 2A                 */ IL_000c: ret
	} // end of method RecentFileListControl::set_RecentFilesPlaceholderText

	.method /* 0600006A */ public hidebysig specialname 
		instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> get_RecentFiles () cil managed 
	{
		// Method begins at RVA 0x2f90
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002F90 02                 */ IL_0000: ldarg.0
		/* 0x00002F91 7E26000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesProperty /* 04000026 */
		/* 0x00002F96 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002F9B 740900001B         */ IL_000b: castclass class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> /* 1B000009 */
		/* 0x00002FA0 2A                 */ IL_0010: ret
	} // end of method RecentFileListControl::get_RecentFiles

	.method /* 0600006B */ public hidebysig specialname 
		instance void set_RecentFiles (
			class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2fa2
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002FA2 02                 */ IL_0000: ldarg.0
		/* 0x00002FA3 7E26000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesProperty /* 04000026 */
		/* 0x00002FA8 03                 */ IL_0006: ldarg.1
		/* 0x00002FA9 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002FAE 2A                 */ IL_000c: ret
	} // end of method RecentFileListControl::set_RecentFiles

	.method /* 0600006C */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_RecentFileCommand () cil managed 
	{
		// Method begins at RVA 0x2fb0
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002FB0 02                 */ IL_0000: ldarg.0
		/* 0x00002FB1 7E27000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFileCommandProperty /* 04000027 */
		/* 0x00002FB6 283000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000030 */
		/* 0x00002FBB 7426000001         */ IL_000b: castclass [System]System.Windows.Input.ICommand /* 01000026 */
		/* 0x00002FC0 2A                 */ IL_0010: ret
	} // end of method RecentFileListControl::get_RecentFileCommand

	.method /* 0600006D */ public hidebysig specialname 
		instance void set_RecentFileCommand (
			class [System]System.Windows.Input.ICommand 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2fc2
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002FC2 02                 */ IL_0000: ldarg.0
		/* 0x00002FC3 7E27000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFileCommandProperty /* 04000027 */
		/* 0x00002FC8 03                 */ IL_0006: ldarg.1
		/* 0x00002FC9 283100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000031 */
		/* 0x00002FCE 2A                 */ IL_000c: ret
	} // end of method RecentFileListControl::set_RecentFileCommand

	.method /* 0600006E */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2fd0
		// Header size: 12
		// Code size: 196 (0xc4)
		.maxstack 4

		/* 0x00002FD0 723F030070         */ IL_0000: ldstr "RecentFilesListCaption" /* 7000033F */
		/* 0x00002FD5 D059000001         */ IL_0005: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00002FDA 283200000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002FDF D010000002         */ IL_000f: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl /* 02000010 */
		/* 0x00002FE4 283200000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00002FE9 2816000006         */ IL_0019: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_RecentFileList_Caption() /* 06000016 */
		/* 0x00002FEE 736700000A         */ IL_001e: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00002FF3 286500000A         */ IL_0023: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00002FF8 8024000004         */ IL_0028: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesListCaptionProperty /* 04000024 */
		/* 0x00002FFD 726D030070         */ IL_002d: ldstr "RecentFilesPlaceholderText" /* 7000036D */
		/* 0x00003002 D059000001         */ IL_0032: ldtoken [mscorlib]System.String /* 01000059 */
		/* 0x00003007 283200000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000300C D010000002         */ IL_003c: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl /* 02000010 */
		/* 0x00003011 283200000A         */ IL_0041: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00003016 2817000006         */ IL_0046: call string AspenTech.CommonShell.Controls.Startup.Properties.Resources::get_RecentFileList_Placeholder() /* 06000017 */
		/* 0x0000301B 736700000A         */ IL_004b: newobj instance void [WindowsBase]System.Windows.PropertyMetadata::.ctor(object) /* 0A000067 */
		/* 0x00003020 286500000A         */ IL_0050: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000065 */
		/* 0x00003025 8025000004         */ IL_0055: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesPlaceholderTextProperty /* 04000025 */
		/* 0x0000302A 72A3030070         */ IL_005a: ldstr "RecentFiles" /* 700003A3 */
		/* 0x0000302F D00900001B         */ IL_005f: ldtoken class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> /* 1B000009 */
		/* 0x00003034 283200000A         */ IL_0064: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00003039 D010000002         */ IL_0069: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl /* 02000010 */
		/* 0x0000303E 283200000A         */ IL_006e: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00003043 283300000A         */ IL_0073: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x00003048 8026000004         */ IL_0078: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFilesProperty /* 04000026 */
		/* 0x0000304D 7201040070         */ IL_007d: ldstr "RecentFileCommand" /* 70000401 */
		/* 0x00003052 D026000001         */ IL_0082: ldtoken [System]System.Windows.Input.ICommand /* 01000026 */
		/* 0x00003057 283200000A         */ IL_0087: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000305C D010000002         */ IL_008c: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl /* 02000010 */
		/* 0x00003061 283200000A         */ IL_0091: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00003066 283300000A         */ IL_0096: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000033 */
		/* 0x0000306B 8027000004         */ IL_009b: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::RecentFileCommandProperty /* 04000027 */
		/* 0x00003070 7E3400000A         */ IL_00a0: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A000034 */
		/* 0x00003075 D010000002         */ IL_00a5: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl /* 02000010 */
		/* 0x0000307A 283200000A         */ IL_00aa: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x0000307F D010000002         */ IL_00af: ldtoken AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl /* 02000010 */
		/* 0x00003084 283200000A         */ IL_00b4: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00003089 733500000A         */ IL_00b9: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000035 */
		/* 0x0000308E 6F3600000A         */ IL_00be: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000036 */
		/* 0x00003093 2A                 */ IL_00c3: ret
	} // end of method RecentFileListControl::.cctor

	.method /* 0600006F */ family hidebysig virtual 
		instance void OnMouseUp (
			class [PresentationCore]System.Windows.Input.MouseButtonEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x30a0
		// Header size: 12
		// Code size: 78 (0x4e)
		.maxstack 2
		.locals /* 1100000D */ init (
			[0] class [PresentationFramework]System.Windows.Controls.ListBoxItem,
			[1] class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem
		)

		/* 0x000030A0 02                 */ IL_0000: ldarg.0
		/* 0x000030A1 03                 */ IL_0001: ldarg.1
		/* 0x000030A2 6F6F00000A         */ IL_0002: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A00006F */
		/* 0x000030A7 7538000001         */ IL_0007: isinst [WindowsBase]System.Windows.DependencyObject /* 01000038 */
		/* 0x000030AC 280A00002B         */ IL_000c: call instance !!0 AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::GetAncestor<class [PresentationFramework]System.Windows.Controls.ListBoxItem>(class [WindowsBase]System.Windows.DependencyObject) /* 2B00000A */
		/* 0x000030B1 0A                 */ IL_0011: stloc.0
		/* 0x000030B2 06                 */ IL_0012: ldloc.0
		/* 0x000030B3 2C31               */ IL_0013: brfalse.s IL_0046
		/* 0x000030B5 06                 */ IL_0015: ldloc.0
		/* 0x000030B6 6F7000000A         */ IL_0016: callvirt instance object [PresentationFramework]System.Windows.FrameworkElement::get_DataContext() /* 0A000070 */
		/* 0x000030BB 750F000002         */ IL_001b: isinst AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem /* 0200000F */
		/* 0x000030C0 0B                 */ IL_0020: stloc.1
		/* 0x000030C1 07                 */ IL_0021: ldloc.1
		/* 0x000030C2 2C22               */ IL_0022: brfalse.s IL_0046
		/* 0x000030C4 02                 */ IL_0024: ldarg.0
		/* 0x000030C5 286C000006         */ IL_0025: call instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFileCommand() /* 0600006C */
		/* 0x000030CA 2C1A               */ IL_002a: brfalse.s IL_0046
		/* 0x000030CC 02                 */ IL_002c: ldarg.0
		/* 0x000030CD 286C000006         */ IL_002d: call instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFileCommand() /* 0600006C */
		/* 0x000030D2 07                 */ IL_0032: ldloc.1
		/* 0x000030D3 6F7100000A         */ IL_0033: callvirt instance bool [System]System.Windows.Input.ICommand::CanExecute(object) /* 0A000071 */
		/* 0x000030D8 2C0C               */ IL_0038: brfalse.s IL_0046
		/* 0x000030DA 02                 */ IL_003a: ldarg.0
		/* 0x000030DB 286C000006         */ IL_003b: call instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFileCommand() /* 0600006C */
		/* 0x000030E0 07                 */ IL_0040: ldloc.1
		/* 0x000030E1 6F7200000A         */ IL_0041: callvirt instance void [System]System.Windows.Input.ICommand::Execute(object) /* 0A000072 */
		/* 0x000030E6 02                 */ IL_0046: ldarg.0
		/* 0x000030E7 03                 */ IL_0047: ldarg.1
		/* 0x000030E8 287300000A         */ IL_0048: call instance void [PresentationCore]System.Windows.UIElement::OnMouseUp(class [PresentationCore]System.Windows.Input.MouseButtonEventArgs) /* 0A000073 */
		/* 0x000030ED 2A                 */ IL_004d: ret
	} // end of method RecentFileListControl::OnMouseUp

	.method /* 06000070 */ private hidebysig 
		instance !!T GetAncestor<class T> (
			class [WindowsBase]System.Windows.DependencyObject d
		) cil managed 
	{
		// Method begins at RVA 0x30fc
		// Header size: 12
		// Code size: 68 (0x44)
		.maxstack 2
		.locals /* 1100000E */ init (
			[0] class [WindowsBase]System.Windows.DependencyObject,
			[1] !!T
		)

		/* 0x000030FC 03                 */ IL_0000: ldarg.1
		/* 0x000030FD 0A                 */ IL_0001: stloc.0
		/* 0x000030FE 06                 */ IL_0002: ldloc.0
		/* 0x000030FF 2D0A               */ IL_0003: brtrue.s IL_000f
		/* 0x00003101 1201               */ IL_0005: ldloca.s 1
		/* 0x00003103 FE150D00001B       */ IL_0007: initobj !!T /* 1B00000D */
		/* 0x00003109 07                 */ IL_000d: ldloc.1
		/* 0x0000310A 2A                 */ IL_000e: ret
		/* 0x0000310B 06                 */ IL_000f: ldloc.0
		/* 0x0000310C 02                 */ IL_0010: ldarg.0
		/* 0x0000310D 330A               */ IL_0011: bne.un.s IL_001d
		/* 0x0000310F 1201               */ IL_0013: ldloca.s 1
		/* 0x00003111 FE150D00001B       */ IL_0015: initobj !!T /* 1B00000D */
		/* 0x00003117 07                 */ IL_001b: ldloc.1
		/* 0x00003118 2A                 */ IL_001c: ret
		/* 0x00003119 D00D00001B         */ IL_001d: ldtoken !!T /* 1B00000D */
		/* 0x0000311E 283200000A         */ IL_0022: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000032 */
		/* 0x00003123 06                 */ IL_0027: ldloc.0
		/* 0x00003124 6F7400000A         */ IL_0028: callvirt instance bool [mscorlib]System.Type::IsInstanceOfType(object) /* 0A000074 */
		/* 0x00003129 2C0C               */ IL_002d: brfalse.s IL_003b
		/* 0x0000312B 06                 */ IL_002f: ldloc.0
		/* 0x0000312C 750D00001B         */ IL_0030: isinst !!T /* 1B00000D */
		/* 0x00003131 A50D00001B         */ IL_0035: unbox.any !!T /* 1B00000D */
		/* 0x00003136 2A                 */ IL_003a: ret
		/* 0x00003137 06                 */ IL_003b: ldloc.0
		/* 0x00003138 287500000A         */ IL_003c: call class [WindowsBase]System.Windows.DependencyObject [PresentationCore]System.Windows.Media.VisualTreeHelper::GetParent(class [WindowsBase]System.Windows.DependencyObject) /* 0A000075 */
		/* 0x0000313D 0A                 */ IL_0041: stloc.0
		/* 0x0000313E 2BBE               */ IL_0042: br.s IL_0002
	} // end of method RecentFileListControl::GetAncestor

	.method /* 06000071 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x314c
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000314C 02                 */ IL_0000: ldarg.0
		/* 0x0000314D 283700000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Control::.ctor() /* 0A000037 */
		/* 0x00003152 2A                 */ IL_0006: ret
	} // end of method RecentFileListControl::.ctor

	// Properties
	.property /* 17000022 */ instance string RecentFilesListCaption()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFilesListCaption()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::set_RecentFilesListCaption(string)
	}
	.property /* 17000023 */ instance string RecentFilesPlaceholderText()
	{
		.get instance string AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFilesPlaceholderText()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::set_RecentFilesPlaceholderText(string)
	}
	.property /* 17000024 */ instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> RecentFiles()
	{
		.get instance class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem> AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFiles()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::set_RecentFiles(class [mscorlib]System.Collections.Generic.IEnumerable`1<class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileItem>)
	}
	.property /* 17000025 */ instance class [System]System.Windows.Input.ICommand RecentFileCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::get_RecentFileCommand()
		.set instance void AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl::set_RecentFileCommand(class [System]System.Windows.Input.ICommand)
	}

} // end of class AspenTech.CommonShell.Controls.Startup.Primitive.RecentFileListControl

