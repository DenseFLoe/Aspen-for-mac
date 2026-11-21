.module AspenTech.AspenPlus.MMForms.Pure_Databanks.dll
// MVID: {FAAA1A9D-5AA6-44DA-BBD6-4931E7772B2A}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel
{
	// Fields
	.field /* 04000001 */ private class [System]System.Windows.Input.ICommand _cmdClose_Command
	.field /* 04000002 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration lstpPureDataBanks_filesymnam_Property

	// Methods
	.method /* 06000001 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_cmdClose_Command () cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x00002050 02                 */ IL_0000: ldarg.0
		/* 0x00002051 7B01000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::_cmdClose_Command /* 04000001 */
		/* 0x00002056 2D17               */ IL_0006: brtrue.s IL_001f
		/* 0x00002058 02                 */ IL_0008: ldarg.0
		/* 0x00002059 02                 */ IL_0009: ldarg.0
		/* 0x0000205A FE0602000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::cmdClose_CommandExecute(object) /* 06000002 */
		/* 0x00002060 731600000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000016 */
		/* 0x00002065 731700000A         */ IL_0015: newobj instance void class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvDelegateCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>) /* 0A000017 */
		/* 0x0000206A 7D01000004         */ IL_001a: stfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::_cmdClose_Command /* 04000001 */
		/* 0x0000206F 02                 */ IL_001f: ldarg.0
		/* 0x00002070 7B01000004         */ IL_0020: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::_cmdClose_Command /* 04000001 */
		/* 0x00002075 2A                 */ IL_0025: ret
	} // end of method MMPureDataBank_Input_ViewModel::get_cmdClose_Command

	.method /* 06000002 */ private hidebysig 
		instance void cmdClose_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2077
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002077 02                 */ IL_0000: ldarg.0
		/* 0x00002078 281800000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::CloseForm() /* 0A000018 */
		/* 0x0000207D 2A                 */ IL_0006: ret
	} // end of method MMPureDataBank_Input_ViewModel::cmdClose_CommandExecute

	.method /* 06000003 */ public hidebysig specialname 
		instance object get_lstpPureDataBanks_filesymnam () cil managed 
	{
		// Method begins at RVA 0x207f
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x0000207F 02                 */ IL_0000: ldarg.0
		/* 0x00002080 7E02000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::lstpPureDataBanks_filesymnam_Property /* 04000002 */
		/* 0x00002085 6F1900000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A000019 */
		/* 0x0000208A 2A                 */ IL_000b: ret
	} // end of method MMPureDataBank_Input_ViewModel::get_lstpPureDataBanks_filesymnam

	.method /* 06000004 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x208c
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000208C 02                 */ IL_0000: ldarg.0
		/* 0x0000208D 281A00000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel::.ctor() /* 0A00001A */
		/* 0x00002092 2A                 */ IL_0006: ret
	} // end of method MMPureDataBank_Input_ViewModel::.ctor

	.method /* 06000005 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2094
		// Header size: 1
		// Code size: 61 (0x3d)
		.maxstack 8

		/* 0x00002094 7201000070         */ IL_0000: ldstr "lstpPureDataBanks_filesymnam" /* 70000001 */
		/* 0x00002099 D002000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel /* 02000002 */
		/* 0x0000209E 281B00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00001B */
		/* 0x000020A3 731C00000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A00001C */
		/* 0x000020A8 25                 */ IL_0014: dup
		/* 0x000020A9 1B                 */ IL_0015: ldc.i4.5
		/* 0x000020AA 6F1D00000A         */ IL_0016: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A00001D */
		/* 0x000020AF 25                 */ IL_001b: dup
		/* 0x000020B0 723B000070         */ IL_001c: ldstr "@main.Input.FILE_SYM_NAM" /* 7000003B */
		/* 0x000020B5 6F1E00000A         */ IL_0021: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A00001E */
		/* 0x000020BA 25                 */ IL_0026: dup
		/* 0x000020BB 17                 */ IL_0027: ldc.i4.1
		/* 0x000020BC 731F00000A         */ IL_0028: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00001F */
		/* 0x000020C1 6F2000000A         */ IL_002d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_RestoreDefaultOnClear(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A000020 */
		/* 0x000020C6 282100000A         */ IL_0032: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000021 */
		/* 0x000020CB 8002000004         */ IL_0037: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::lstpPureDataBanks_filesymnam_Property /* 04000002 */
		/* 0x000020D0 2A                 */ IL_003c: ret
	} // end of method MMPureDataBank_Input_ViewModel::.cctor

	// Properties
	.property /* 17000001 */ instance class [System]System.Windows.Input.ICommand cmdClose_Command()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::get_cmdClose_Command()
	}
	.property /* 17000002 */ instance object lstpPureDataBanks_filesymnam()
	{
		.get instance object AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel::get_lstpPureDataBanks_filesymnam()
	}

} // end of class AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel

.class /* 02000003 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	.custom /* 0C000011 */ instance void [mscorlib]System.Runtime.InteropServices.ProgIdAttribute::.ctor(string) = (
		01 00 23 4d 4d 50 75 72 65 44 61 74 61 42 61 6e
		6b 2e 4d 4d 50 75 72 65 44 61 74 61 42 61 6e 6b
		5f 49 6e 70 75 74 00 00
	)
	// Fields
	.field /* 04000003 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMListPicker lstpPureDataBanks
	.field /* 04000004 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMCmdButton cmdClose
	.field /* 04000005 */ private bool _contentLoaded

	// Methods
	.method /* 06000006 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x20d2
		// Header size: 1
		// Code size: 29 (0x1d)
		.maxstack 8

		/* 0x000020D2 02                 */ IL_0000: ldarg.0
		/* 0x000020D3 282200000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage::.ctor() /* 0A000022 */
		/* 0x000020D8 02                 */ IL_0006: ldarg.0
		/* 0x000020D9 D002000002         */ IL_0007: ldtoken AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input_ViewModel /* 02000002 */
		/* 0x000020DE 281B00000A         */ IL_000c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00001B */
		/* 0x000020E3 282300000A         */ IL_0011: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModelContainer::set_ViewModelType(class [mscorlib]System.Type) /* 0A000023 */
		/* 0x000020E8 02                 */ IL_0016: ldarg.0
		/* 0x000020E9 2807000006         */ IL_0017: call instance void AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input::InitializeComponent() /* 06000007 */
		/* 0x000020EE 2A                 */ IL_001c: ret
	} // end of method MMPureDataBank_Input::.ctor

	.method /* 06000007 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000012 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000013 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x20f0
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] class [System]System.Uri
		)

		/* 0x000020F0 02                 */ IL_0000: ldarg.0
		/* 0x000020F1 7B05000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input::_contentLoaded /* 04000005 */
		/* 0x000020F6 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x000020F8 2A                 */ IL_0008: ret
		/* 0x000020F9 02                 */ IL_0009: ldarg.0
		/* 0x000020FA 17                 */ IL_000a: ldc.i4.1
		/* 0x000020FB 7D05000004         */ IL_000b: stfld bool AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input::_contentLoaded /* 04000005 */
		/* 0x00002100 726D000070         */ IL_0010: ldstr "/AspenTech.AspenPlus.MMForms.Pure_Databanks;component/mmpuredatabank_input.xaml" /* 7000006D */
		/* 0x00002105 18                 */ IL_0015: ldc.i4.2
		/* 0x00002106 732400000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A000024 */
		/* 0x0000210B 0A                 */ IL_001b: stloc.0
		/* 0x0000210C 02                 */ IL_001c: ldarg.0
		/* 0x0000210D 06                 */ IL_001d: ldloc.0
		/* 0x0000210E 282500000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A000025 */
		/* 0x00002113 2A                 */ IL_0023: ret
	} // end of method MMPureDataBank_Input::InitializeComponent

	.method /* 06000008 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000014 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000015 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000016 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x2120
		// Header size: 1
		// Code size: 44 (0x2c)
		.maxstack 8

		/* 0x00002120 03                 */ IL_0000: ldarg.1
		/* 0x00002121 17                 */ IL_0001: ldc.i4.1
		/* 0x00002122 2E06               */ IL_0002: beq.s IL_000a
		/* 0x00002124 03                 */ IL_0004: ldarg.1
		/* 0x00002125 18                 */ IL_0005: ldc.i4.2
		/* 0x00002126 2E0F               */ IL_0006: beq.s IL_0017
		/* 0x00002128 2B1A               */ IL_0008: br.s IL_0024
		/* 0x0000212A 02                 */ IL_000a: ldarg.0
		/* 0x0000212B 04                 */ IL_000b: ldarg.2
		/* 0x0000212C 741B000001         */ IL_000c: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMListPicker /* 0100001B */
		/* 0x00002131 7D03000004         */ IL_0011: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMListPicker AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input::lstpPureDataBanks /* 04000003 */
		/* 0x00002136 2A                 */ IL_0016: ret
		/* 0x00002137 02                 */ IL_0017: ldarg.0
		/* 0x00002138 04                 */ IL_0018: ldarg.2
		/* 0x00002139 741C000001         */ IL_0019: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMCmdButton /* 0100001C */
		/* 0x0000213E 7D04000004         */ IL_001e: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMCmdButton AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input::cmdClose /* 04000004 */
		/* 0x00002143 2A                 */ IL_0023: ret
		/* 0x00002144 02                 */ IL_0024: ldarg.0
		/* 0x00002145 17                 */ IL_0025: ldc.i4.1
		/* 0x00002146 7D05000004         */ IL_0026: stfld bool AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input::_contentLoaded /* 04000005 */
		/* 0x0000214B 2A                 */ IL_002b: ret
	} // end of method MMPureDataBank_Input::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.MMForms.Pure_Databanks.MMPureDataBank_Input

