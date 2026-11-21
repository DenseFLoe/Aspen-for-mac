.module AspenTech.Visualisation.Assistant.Run.exe
// MVID: {8F8CA8EC-3BD8-4F4F-AA2D-F117D092195E}
.imagebase 0x00400000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0002 // WindowsGui
.corflags 0x00000003 // ILOnly, Requires32Bit
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi beforefieldinit AspenTech.Visualisation.Assistant.Run.App
	extends [PresentationFramework]System.Windows.Application
{
	.custom /* 0C000011 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
		75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
		30 00 00
	)
	// Methods
	.method /* 06000001 */ private hidebysig 
		instance void Application_Startup (
			object sender,
			class [PresentationFramework]System.Windows.StartupEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 12
		// Code size: 217 (0xd9)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] class [PresentationFramework]Microsoft.Win32.OpenFileDialog,
			[1] class [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot,
			[2] class [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistantDialog,
			[3] class [PresentationFramework]Microsoft.Win32.OpenFileDialog,
			[4] string,
			[5] class [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot,
			[6] class [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistantDialog,
			[7] valuetype [mscorlib]System.Nullable`1<bool>,
			[8] string[],
			[9] int32
		)

		/* 0x00002050 04                 */ IL_0000: ldarg.2
		/* 0x00002051 6F1400000A         */ IL_0001: callvirt instance string[] [PresentationFramework]System.Windows.StartupEventArgs::get_Args() /* 0A000014 */
		/* 0x00002056 8E                 */ IL_0006: ldlen
		/* 0x00002057 69                 */ IL_0007: conv.i4
		/* 0x00002058 3A81000000         */ IL_0008: brtrue IL_008e
		/* 0x0000205D 16                 */ IL_000d: ldc.i4.0
		/* 0x0000205E 281500000A         */ IL_000e: call void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.Aspen::Splash(valuetype [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.Aspen/VersionSource) /* 0A000015 */
		/* 0x00002063 731600000A         */ IL_0013: newobj instance void [PresentationFramework]Microsoft.Win32.OpenFileDialog::.ctor() /* 0A000016 */
		/* 0x00002068 0D                 */ IL_0018: stloc.3
		/* 0x00002069 09                 */ IL_0019: ldloc.3
		/* 0x0000206A 7201000070         */ IL_001a: ldstr "Select assistant file" /* 70000001 */
		/* 0x0000206F 6F1700000A         */ IL_001f: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_Title(string) /* 0A000017 */
		/* 0x00002074 09                 */ IL_0024: ldloc.3
		/* 0x00002075 722D000070         */ IL_0025: ldstr "amf" /* 7000002D */
		/* 0x0000207A 6F1800000A         */ IL_002a: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_DefaultExt(string) /* 0A000018 */
		/* 0x0000207F 09                 */ IL_002f: ldloc.3
		/* 0x00002080 7235000070         */ IL_0030: ldstr "Assistant files (*.amf)|*.amf|All files|*.*" /* 70000035 */
		/* 0x00002085 6F1900000A         */ IL_0035: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_Filter(string) /* 0A000019 */
		/* 0x0000208A 09                 */ IL_003a: ldloc.3
		/* 0x0000208B 17                 */ IL_003b: ldc.i4.1
		/* 0x0000208C 6F1A00000A         */ IL_003c: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_CheckFileExists(bool) /* 0A00001A */
		/* 0x00002091 09                 */ IL_0041: ldloc.3
		/* 0x00002092 17                 */ IL_0042: ldc.i4.1
		/* 0x00002093 6F1B00000A         */ IL_0043: callvirt instance void [PresentationFramework]Microsoft.Win32.FileDialog::set_CheckPathExists(bool) /* 0A00001B */
		/* 0x00002098 09                 */ IL_0048: ldloc.3
		/* 0x00002099 0A                 */ IL_0049: stloc.0
		/* 0x0000209A 06                 */ IL_004a: ldloc.0
		/* 0x0000209B 6F1C00000A         */ IL_004b: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]Microsoft.Win32.CommonDialog::ShowDialog() /* 0A00001C */
		/* 0x000020A0 1307               */ IL_0050: stloc.s 7
		/* 0x000020A2 1207               */ IL_0052: ldloca.s 7
		/* 0x000020A4 281D00000A         */ IL_0054: call instance bool valuetype [mscorlib]System.Nullable`1<bool>::get_HasValue() /* 0A00001D */
		/* 0x000020A9 2D03               */ IL_0059: brtrue.s IL_005e
		/* 0x000020AB 16                 */ IL_005b: ldc.i4.0
		/* 0x000020AC 2B07               */ IL_005c: br.s IL_0065
		/* 0x000020AE 1207               */ IL_005e: ldloca.s 7
		/* 0x000020B0 281E00000A         */ IL_0060: call instance !0 valuetype [mscorlib]System.Nullable`1<bool>::GetValueOrDefault() /* 0A00001E */
		/* 0x000020B5 2C71               */ IL_0065: brfalse.s IL_00d8
		/* 0x000020B7 731F00000A         */ IL_0067: newobj instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot::.ctor() /* 0A00001F */
		/* 0x000020BC 0B                 */ IL_006c: stloc.1
		/* 0x000020BD 07                 */ IL_006d: ldloc.1
		/* 0x000020BE 06                 */ IL_006e: ldloc.0
		/* 0x000020BF 6F2000000A         */ IL_006f: callvirt instance string [PresentationFramework]Microsoft.Win32.FileDialog::get_FileName() /* 0A000020 */
		/* 0x000020C4 6F2100000A         */ IL_0074: callvirt instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot::LoadFile(string) /* 0A000021 */
		/* 0x000020C9 732200000A         */ IL_0079: newobj instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistantDialog::.ctor() /* 0A000022 */
		/* 0x000020CE 0C                 */ IL_007e: stloc.2
		/* 0x000020CF 08                 */ IL_007f: ldloc.2
		/* 0x000020D0 07                 */ IL_0080: ldloc.1
		/* 0x000020D1 6F2300000A         */ IL_0081: callvirt instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistantDialog::set_Assistant(class [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 0A000023 */
		/* 0x000020D6 08                 */ IL_0086: ldloc.2
		/* 0x000020D7 6F2400000A         */ IL_0087: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]System.Windows.Window::ShowDialog() /* 0A000024 */
		/* 0x000020DC 26                 */ IL_008c: pop
		/* 0x000020DD 2A                 */ IL_008d: ret
		/* 0x000020DE 04                 */ IL_008e: ldarg.2
		/* 0x000020DF 6F1400000A         */ IL_008f: callvirt instance string[] [PresentationFramework]System.Windows.StartupEventArgs::get_Args() /* 0A000014 */
		/* 0x000020E4 1308               */ IL_0094: stloc.s 8
		/* 0x000020E6 16                 */ IL_0096: ldc.i4.0
		/* 0x000020E7 1309               */ IL_0097: stloc.s 9
		/* 0x000020E9 2B35               */ IL_0099: br.s IL_00d0
		/* 0x000020EB 1108               */ IL_009b: ldloc.s 8
		/* 0x000020ED 1109               */ IL_009d: ldloc.s 9
		/* 0x000020EF 9A                 */ IL_009f: ldelem.ref
		/* 0x000020F0 1304               */ IL_00a0: stloc.s 4
		/* 0x000020F2 731F00000A         */ IL_00a2: newobj instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot::.ctor() /* 0A00001F */
		/* 0x000020F7 1305               */ IL_00a7: stloc.s 5
		/* 0x000020F9 1105               */ IL_00a9: ldloc.s 5
		/* 0x000020FB 1104               */ IL_00ab: ldloc.s 4
		/* 0x000020FD 6F2100000A         */ IL_00ad: callvirt instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot::LoadFile(string) /* 0A000021 */
		/* 0x00002102 732200000A         */ IL_00b2: newobj instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistantDialog::.ctor() /* 0A000022 */
		/* 0x00002107 1306               */ IL_00b7: stloc.s 6
		/* 0x00002109 1106               */ IL_00b9: ldloc.s 6
		/* 0x0000210B 1105               */ IL_00bb: ldloc.s 5
		/* 0x0000210D 6F2300000A         */ IL_00bd: callvirt instance void [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistantDialog::set_Assistant(class [AspenTech.Visualisation.Controls.Assistant.W1]AspenTech.Visualisation.Controls.Assistant.AssistRoot) /* 0A000023 */
		/* 0x00002112 1106               */ IL_00c2: ldloc.s 6
		/* 0x00002114 6F2400000A         */ IL_00c4: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]System.Windows.Window::ShowDialog() /* 0A000024 */
		/* 0x00002119 26                 */ IL_00c9: pop
		/* 0x0000211A 1109               */ IL_00ca: ldloc.s 9
		/* 0x0000211C 17                 */ IL_00cc: ldc.i4.1
		/* 0x0000211D 58                 */ IL_00cd: add
		/* 0x0000211E 1309               */ IL_00ce: stloc.s 9
		/* 0x00002120 1109               */ IL_00d0: ldloc.s 9
		/* 0x00002122 1108               */ IL_00d2: ldloc.s 8
		/* 0x00002124 8E                 */ IL_00d4: ldlen
		/* 0x00002125 69                 */ IL_00d5: conv.i4
		/* 0x00002126 32C3               */ IL_00d6: blt.s IL_009b
		/* 0x00002128 2A                 */ IL_00d8: ret
	} // end of method App::Application_Startup

	.method /* 06000002 */ private hidebysig 
		instance void Application_DispatcherUnhandledException (
			object sender,
			class [WindowsBase]System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2135
		// Header size: 1
		// Code size: 1 (0x1)
		.maxstack 8

		/* 0x00002135 2A                 */ IL_0000: ret
	} // end of method App::Application_DispatcherUnhandledException

	.method /* 06000003 */ public hidebysig 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000012 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2137
		// Header size: 1
		// Code size: 37 (0x25)
		.maxstack 8

		/* 0x00002137 02                 */ IL_0000: ldarg.0
		/* 0x00002138 02                 */ IL_0001: ldarg.0
		/* 0x00002139 FE0601000006       */ IL_0002: ldftn instance void AspenTech.Visualisation.Assistant.Run.App::Application_Startup(object, class [PresentationFramework]System.Windows.StartupEventArgs) /* 06000001 */
		/* 0x0000213F 732600000A         */ IL_0008: newobj instance void [PresentationFramework]System.Windows.StartupEventHandler::.ctor(object, native int) /* 0A000026 */
		/* 0x00002144 282700000A         */ IL_000d: call instance void [PresentationFramework]System.Windows.Application::add_Startup(class [PresentationFramework]System.Windows.StartupEventHandler) /* 0A000027 */
		/* 0x00002149 02                 */ IL_0012: ldarg.0
		/* 0x0000214A 02                 */ IL_0013: ldarg.0
		/* 0x0000214B FE0602000006       */ IL_0014: ldftn instance void AspenTech.Visualisation.Assistant.Run.App::Application_DispatcherUnhandledException(object, class [WindowsBase]System.Windows.Threading.DispatcherUnhandledExceptionEventArgs) /* 06000002 */
		/* 0x00002151 732800000A         */ IL_001a: newobj instance void [WindowsBase]System.Windows.Threading.DispatcherUnhandledExceptionEventHandler::.ctor(object, native int) /* 0A000028 */
		/* 0x00002156 282900000A         */ IL_001f: call instance void [PresentationFramework]System.Windows.Application::add_DispatcherUnhandledException(class [WindowsBase]System.Windows.Threading.DispatcherUnhandledExceptionEventHandler) /* 0A000029 */
		/* 0x0000215B 2A                 */ IL_0024: ret
	} // end of method App::InitializeComponent

	.method /* 06000004 */ public hidebysig static 
		void Main () cil managed 
	{
		.custom /* 0C000013 */ instance void [mscorlib]System.STAThreadAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000014 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2160
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 1
		.entrypoint
		.locals /* 11000002 */ init (
			[0] class AspenTech.Visualisation.Assistant.Run.App
		)

		/* 0x00002160 7305000006         */ IL_0000: newobj instance void AspenTech.Visualisation.Assistant.Run.App::.ctor() /* 06000005 */
		/* 0x00002165 0A                 */ IL_0005: stloc.0
		/* 0x00002166 06                 */ IL_0006: ldloc.0
		/* 0x00002167 6F03000006         */ IL_0007: callvirt instance void AspenTech.Visualisation.Assistant.Run.App::InitializeComponent() /* 06000003 */
		/* 0x0000216C 06                 */ IL_000c: ldloc.0
		/* 0x0000216D 6F2B00000A         */ IL_000d: callvirt instance int32 [PresentationFramework]System.Windows.Application::Run() /* 0A00002B */
		/* 0x00002172 26                 */ IL_0012: pop
		/* 0x00002173 2A                 */ IL_0013: ret
	} // end of method App::Main

	.method /* 06000005 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2180
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002180 02                 */ IL_0000: ldarg.0
		/* 0x00002181 282C00000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Application::.ctor() /* 0A00002C */
		/* 0x00002186 2A                 */ IL_0006: ret
	} // end of method App::.ctor

} // end of class AspenTech.Visualisation.Assistant.Run.App

