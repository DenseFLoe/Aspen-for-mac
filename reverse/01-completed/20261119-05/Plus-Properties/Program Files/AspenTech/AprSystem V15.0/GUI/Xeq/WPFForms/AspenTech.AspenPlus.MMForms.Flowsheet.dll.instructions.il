.module AspenTech.AspenPlus.MMForms.Flowsheet.dll
// MVID: {B4439948-8EA6-4B80-B59F-AFBD9EE68C09}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ public auto ansi sealed beforefieldinit XamlGeneratedNamespace.GeneratedInternalTypeHelper
	extends [WindowsBase]System.Windows.Markup.InternalTypeHelper
{
	.custom /* 0C000011 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000012 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
		75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
		30 00 00
	)
	.custom /* 0C000013 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
		01 00 01 00 00 00 00 00
	)
	// Methods
	.method /* 06000001 */ family hidebysig virtual 
		instance object CreateInstance (
			class [mscorlib]System.Type 'type',
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 1
		// Code size: 15 (0xf)
		.maxstack 8

		/* 0x00002050 03                 */ IL_0000: ldarg.1
		/* 0x00002051 2034020000         */ IL_0001: ldc.i4 564
		/* 0x00002056 14                 */ IL_0006: ldnull
		/* 0x00002057 14                 */ IL_0007: ldnull
		/* 0x00002058 04                 */ IL_0008: ldarg.2
		/* 0x00002059 282300000A         */ IL_0009: call object [mscorlib]System.Activator::CreateInstance(class [mscorlib]System.Type, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A000023 */
		/* 0x0000205E 2A                 */ IL_000e: ret
	} // end of method GeneratedInternalTypeHelper::CreateInstance

	.method /* 06000002 */ family hidebysig virtual 
		instance object GetPropertyValue (
			class [mscorlib]System.Reflection.PropertyInfo propertyInfo,
			object target,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x2060
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00002060 03                 */ IL_0000: ldarg.1
		/* 0x00002061 04                 */ IL_0001: ldarg.2
		/* 0x00002062 16                 */ IL_0002: ldc.i4.0
		/* 0x00002063 14                 */ IL_0003: ldnull
		/* 0x00002064 14                 */ IL_0004: ldnull
		/* 0x00002065 05                 */ IL_0005: ldarg.3
		/* 0x00002066 6F2400000A         */ IL_0006: callvirt instance object [mscorlib]System.Reflection.PropertyInfo::GetValue(object, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A000024 */
		/* 0x0000206B 2A                 */ IL_000b: ret
	} // end of method GeneratedInternalTypeHelper::GetPropertyValue

	.method /* 06000003 */ family hidebysig virtual 
		instance void SetPropertyValue (
			class [mscorlib]System.Reflection.PropertyInfo propertyInfo,
			object target,
			object 'value',
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x206d
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x0000206D 03                 */ IL_0000: ldarg.1
		/* 0x0000206E 04                 */ IL_0001: ldarg.2
		/* 0x0000206F 05                 */ IL_0002: ldarg.3
		/* 0x00002070 16                 */ IL_0003: ldc.i4.0
		/* 0x00002071 14                 */ IL_0004: ldnull
		/* 0x00002072 14                 */ IL_0005: ldnull
		/* 0x00002073 0E04               */ IL_0006: ldarg.s culture
		/* 0x00002075 6F2500000A         */ IL_0008: callvirt instance void [mscorlib]System.Reflection.PropertyInfo::SetValue(object, object, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A000025 */
		/* 0x0000207A 2A                 */ IL_000d: ret
	} // end of method GeneratedInternalTypeHelper::SetPropertyValue

	.method /* 06000004 */ family hidebysig virtual 
		instance class [mscorlib]System.Delegate CreateDelegate (
			class [mscorlib]System.Type delegateType,
			object target,
			string 'handler'
		) cil managed 
	{
		// Method begins at RVA 0x207c
		// Header size: 12
		// Code size: 44 (0x2c)
		.maxstack 9

		/* 0x0000207C 04                 */ IL_0000: ldarg.2
		/* 0x0000207D 6F2600000A         */ IL_0001: callvirt instance class [mscorlib]System.Type [mscorlib]System.Object::GetType() /* 0A000026 */
		/* 0x00002082 7201000070         */ IL_0006: ldstr "_CreateDelegate" /* 70000001 */
		/* 0x00002087 2024010000         */ IL_000b: ldc.i4 292
		/* 0x0000208C 14                 */ IL_0010: ldnull
		/* 0x0000208D 04                 */ IL_0011: ldarg.2
		/* 0x0000208E 18                 */ IL_0012: ldc.i4.2
		/* 0x0000208F 8D19000001         */ IL_0013: newarr [mscorlib]System.Object /* 01000019 */
		/* 0x00002094 25                 */ IL_0018: dup
		/* 0x00002095 16                 */ IL_0019: ldc.i4.0
		/* 0x00002096 03                 */ IL_001a: ldarg.1
		/* 0x00002097 A2                 */ IL_001b: stelem.ref
		/* 0x00002098 25                 */ IL_001c: dup
		/* 0x00002099 17                 */ IL_001d: ldc.i4.1
		/* 0x0000209A 05                 */ IL_001e: ldarg.3
		/* 0x0000209B A2                 */ IL_001f: stelem.ref
		/* 0x0000209C 14                 */ IL_0020: ldnull
		/* 0x0000209D 6F2700000A         */ IL_0021: callvirt instance object [mscorlib]System.Type::InvokeMember(string, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A000027 */
		/* 0x000020A2 741D000001         */ IL_0026: castclass [mscorlib]System.Delegate /* 0100001D */
		/* 0x000020A7 2A                 */ IL_002b: ret
	} // end of method GeneratedInternalTypeHelper::CreateDelegate

	.method /* 06000005 */ family hidebysig virtual 
		instance void AddEventHandler (
			class [mscorlib]System.Reflection.EventInfo eventInfo,
			object target,
			class [mscorlib]System.Delegate 'handler'
		) cil managed 
	{
		// Method begins at RVA 0x20b4
		// Header size: 1
		// Code size: 9 (0x9)
		.maxstack 8

		/* 0x000020B4 03                 */ IL_0000: ldarg.1
		/* 0x000020B5 04                 */ IL_0001: ldarg.2
		/* 0x000020B6 05                 */ IL_0002: ldarg.3
		/* 0x000020B7 6F2800000A         */ IL_0003: callvirt instance void [mscorlib]System.Reflection.EventInfo::AddEventHandler(object, class [mscorlib]System.Delegate) /* 0A000028 */
		/* 0x000020BC 2A                 */ IL_0008: ret
	} // end of method GeneratedInternalTypeHelper::AddEventHandler

	.method /* 06000006 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x20be
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000020BE 02                 */ IL_0000: ldarg.0
		/* 0x000020BF 282900000A         */ IL_0001: call instance void [WindowsBase]System.Windows.Markup.InternalTypeHelper::.ctor() /* 0A000029 */
		/* 0x000020C4 2A                 */ IL_0006: ret
	} // end of method GeneratedInternalTypeHelper::.ctor

} // end of class XamlGeneratedNamespace.GeneratedInternalTypeHelper

.class /* 02000003 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel
{
	// Fields
	.field /* 04000001 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration spec_Property
	.field /* 04000002 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration NOTPFSLOCK_Property
	.field /* 04000003 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration tab0_var_Property

	// Methods
	.method /* 06000007 */ public hidebysig specialname 
		instance object get_spec () cil managed 
	{
		// Method begins at RVA 0x20c6
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000020C6 02                 */ IL_0000: ldarg.0
		/* 0x000020C7 7E01000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::spec_Property /* 04000001 */
		/* 0x000020CC 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
		/* 0x000020D1 2A                 */ IL_000b: ret
	} // end of method MMFlowsh_Input_ViewModel::get_spec

	.method /* 06000008 */ public hidebysig specialname 
		instance object get_NOTPFSLOCK () cil managed 
	{
		// Method begins at RVA 0x20d3
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000020D3 02                 */ IL_0000: ldarg.0
		/* 0x000020D4 7E02000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::NOTPFSLOCK_Property /* 04000002 */
		/* 0x000020D9 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
		/* 0x000020DE 2A                 */ IL_000b: ret
	} // end of method MMFlowsh_Input_ViewModel::get_NOTPFSLOCK

	.method /* 06000009 */ public hidebysig specialname 
		instance object get_tab0_var () cil managed 
	{
		// Method begins at RVA 0x20e0
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000020E0 02                 */ IL_0000: ldarg.0
		/* 0x000020E1 7E03000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::tab0_var_Property /* 04000003 */
		/* 0x000020E6 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
		/* 0x000020EB 2A                 */ IL_000b: ret
	} // end of method MMFlowsh_Input_ViewModel::get_tab0_var

	.method /* 0600000A */ family hidebysig virtual 
		instance void OnUpdateData () cil managed 
	{
		// Method begins at RVA 0x20ed
		// Header size: 1
		// Code size: 47 (0x2f)
		.maxstack 8

		/* 0x000020ED 02                 */ IL_0000: ldarg.0
		/* 0x000020EE 282B00000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel::OnUpdateData() /* 0A00002B */
		/* 0x000020F3 02                 */ IL_0006: ldarg.0
		/* 0x000020F4 282C00000A         */ IL_0007: call instance bool [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::get_IsInitialUpdate() /* 0A00002C */
		/* 0x000020F9 2C20               */ IL_000c: brfalse.s IL_002e
		/* 0x000020FB 02                 */ IL_000e: ldarg.0
		/* 0x000020FC 7221000070         */ IL_000f: ldstr "NotNeedName" /* 70000021 */
		/* 0x00002101 7239000070         */ IL_0014: ldstr "NotNull" /* 70000039 */
		/* 0x00002106 282D00000A         */ IL_0019: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveUpdateParameter(string, object) /* 0A00002D */
		/* 0x0000210B 02                 */ IL_001e: ldarg.0
		/* 0x0000210C 7249000070         */ IL_001f: ldstr "NotNeedType" /* 70000049 */
		/* 0x00002111 7239000070         */ IL_0024: ldstr "NotNull" /* 70000039 */
		/* 0x00002116 282D00000A         */ IL_0029: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveUpdateParameter(string, object) /* 0A00002D */
		/* 0x0000211B 2A                 */ IL_002e: ret
	} // end of method MMFlowsh_Input_ViewModel::OnUpdateData

	.method /* 0600000B */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x211d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000211D 02                 */ IL_0000: ldarg.0
		/* 0x0000211E 282E00000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel::.ctor() /* 0A00002E */
		/* 0x00002123 2A                 */ IL_0006: ret
	} // end of method MMFlowsh_Input_ViewModel::.ctor

	.method /* 0600000C */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2128
		// Header size: 12
		// Code size: 145 (0x91)
		.maxstack 5

		/* 0x00002128 7261000070         */ IL_0000: ldstr "spec" /* 70000061 */
		/* 0x0000212D D003000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel /* 02000003 */
		/* 0x00002132 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002137 733000000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
		/* 0x0000213C 25                 */ IL_0014: dup
		/* 0x0000213D 726B000070         */ IL_0015: ldstr "@main.CC Nodes.MAIN" /* 7000006B */
		/* 0x00002142 6F3100000A         */ IL_001a: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
		/* 0x00002147 283200000A         */ IL_001f: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
		/* 0x0000214C 8001000004         */ IL_0024: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::spec_Property /* 04000001 */
		/* 0x00002151 7293000070         */ IL_0029: ldstr "NOTPFSLOCK" /* 70000093 */
		/* 0x00002156 D003000002         */ IL_002e: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel /* 02000003 */
		/* 0x0000215B 282F00000A         */ IL_0033: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002160 733000000A         */ IL_0038: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
		/* 0x00002165 25                 */ IL_003d: dup
		/* 0x00002166 72A9000070         */ IL_003e: ldstr "@main.CC Nodes.NOTPFSLOCK" /* 700000A9 */
		/* 0x0000216B 6F3100000A         */ IL_0043: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
		/* 0x00002170 283200000A         */ IL_0048: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
		/* 0x00002175 8002000004         */ IL_004d: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::NOTPFSLOCK_Property /* 04000002 */
		/* 0x0000217A 72DD000070         */ IL_0052: ldstr "tab0_var" /* 700000DD */
		/* 0x0000217F D003000002         */ IL_0057: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel /* 02000003 */
		/* 0x00002184 282F00000A         */ IL_005c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002189 733300000A         */ IL_0061: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvTabItemProperty::.ctor() /* 0A000033 */
		/* 0x0000218E 25                 */ IL_0066: dup
		/* 0x0000218F 6F3400000A         */ IL_0067: callvirt instance class [mscorlib]System.Collections.ObjectModel.Collection`1<string> [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvTabItemProperty::get_CompleteDataPaths() /* 0A000034 */
		/* 0x00002194 72EF000070         */ IL_006c: ldstr "@spec" /* 700000EF */
		/* 0x00002199 6F3500000A         */ IL_0071: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Add(!0) /* 0A000035 */
		/* 0x0000219E 25                 */ IL_0076: dup
		/* 0x0000219F 6F3600000A         */ IL_0077: callvirt instance class [mscorlib]System.Collections.ObjectModel.Collection`1<string> [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvTabItemProperty::get_AccessibleDataPaths() /* 0A000036 */
		/* 0x000021A4 72FB000070         */ IL_007c: ldstr "@NOTPFSLOCK" /* 700000FB */
		/* 0x000021A9 6F3500000A         */ IL_0081: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Add(!0) /* 0A000035 */
		/* 0x000021AE 283200000A         */ IL_0086: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
		/* 0x000021B3 8003000004         */ IL_008b: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::tab0_var_Property /* 04000003 */
		/* 0x000021B8 2A                 */ IL_0090: ret
	} // end of method MMFlowsh_Input_ViewModel::.cctor

	// Properties
	.property /* 17000001 */ instance object spec()
	{
		.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::get_spec()
	}
	.property /* 17000002 */ instance object NOTPFSLOCK()
	{
		.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::get_NOTPFSLOCK()
	}
	.property /* 17000003 */ instance object tab0_var()
	{
		.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel::get_tab0_var()
	}

} // end of class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel

.class /* 02000004 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabTemplate
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	.custom /* 0C000014 */ instance void [mscorlib]System.Runtime.InteropServices.ProgIdAttribute::.ctor(string) = (
		01 00 1b 4d 4d 46 6c 6f 77 73 68 46 6f 72 6d 2e
		4d 4d 46 6c 6f 77 73 68 5f 49 6e 70 75 74 00 00
	)
	// Fields
	.field /* 04000004 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabStrip MMSSTab1
	.field /* 04000005 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabItem tab0
	.field /* 04000006 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabItem tabInfo
	.field /* 04000007 */ private bool _contentLoaded

	// Methods
	.method /* 0600000D */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x21c5
		// Header size: 1
		// Code size: 29 (0x1d)
		.maxstack 8

		/* 0x000021C5 02                 */ IL_0000: ldarg.0
		/* 0x000021C6 283700000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabTemplate::.ctor() /* 0A000037 */
		/* 0x000021CB 02                 */ IL_0006: ldarg.0
		/* 0x000021CC D003000002         */ IL_0007: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_ViewModel /* 02000003 */
		/* 0x000021D1 282F00000A         */ IL_000c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x000021D6 283800000A         */ IL_0011: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModelContainer::set_ViewModelType(class [mscorlib]System.Type) /* 0A000038 */
		/* 0x000021DB 02                 */ IL_0016: ldarg.0
		/* 0x000021DC 280E000006         */ IL_0017: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::InitializeComponent() /* 0600000E */
		/* 0x000021E1 2A                 */ IL_001c: ret
	} // end of method MMFlowsh_Input::.ctor

	.method /* 0600000E */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00001A */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00001B */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x21e4
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] class [System]System.Uri
		)

		/* 0x000021E4 02                 */ IL_0000: ldarg.0
		/* 0x000021E5 7B07000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::_contentLoaded /* 04000007 */
		/* 0x000021EA 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x000021EC 2A                 */ IL_0008: ret
		/* 0x000021ED 02                 */ IL_0009: ldarg.0
		/* 0x000021EE 17                 */ IL_000a: ldc.i4.1
		/* 0x000021EF 7D07000004         */ IL_000b: stfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::_contentLoaded /* 04000007 */
		/* 0x000021F4 7213010070         */ IL_0010: ldstr "/AspenTech.AspenPlus.MMForms.Flowsheet;component/mmflowsh_input.xaml" /* 70000113 */
		/* 0x000021F9 18                 */ IL_0015: ldc.i4.2
		/* 0x000021FA 733900000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A000039 */
		/* 0x000021FF 0A                 */ IL_001b: stloc.0
		/* 0x00002200 02                 */ IL_001c: ldarg.0
		/* 0x00002201 06                 */ IL_001d: ldloc.0
		/* 0x00002202 283A00000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A00003A */
		/* 0x00002207 2A                 */ IL_0023: ret
	} // end of method MMFlowsh_Input::InitializeComponent

	.method /* 0600000F */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C00001C */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00001D */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C00001E */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x2214
		// Header size: 12
		// Code size: 69 (0x45)
		.maxstack 2

		/* 0x00002214 03                 */ IL_0000: ldarg.1
		/* 0x00002215 17                 */ IL_0001: ldc.i4.1
		/* 0x00002216 59                 */ IL_0002: sub
		/* 0x00002217 4503000000         */ IL_0003: switch (
		/*              02000000         */                  IL_0016,
		/*              0F000000         */                  IL_0023,
		/*              1C000000         */                  IL_0030)
		/* 0x00002228 2B27               */ IL_0014: br.s IL_003d
		/* 0x0000222A 02                 */ IL_0016: ldarg.0
		/* 0x0000222B 04                 */ IL_0017: ldarg.2
		/* 0x0000222C 7424000001         */ IL_0018: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabStrip /* 01000024 */
		/* 0x00002231 7D04000004         */ IL_001d: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabStrip AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::MMSSTab1 /* 04000004 */
		/* 0x00002236 2A                 */ IL_0022: ret
		/* 0x00002237 02                 */ IL_0023: ldarg.0
		/* 0x00002238 04                 */ IL_0024: ldarg.2
		/* 0x00002239 7425000001         */ IL_0025: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabItem /* 01000025 */
		/* 0x0000223E 7D05000004         */ IL_002a: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabItem AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::tab0 /* 04000005 */
		/* 0x00002243 2A                 */ IL_002f: ret
		/* 0x00002244 02                 */ IL_0030: ldarg.0
		/* 0x00002245 04                 */ IL_0031: ldarg.2
		/* 0x00002246 7425000001         */ IL_0032: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabItem /* 01000025 */
		/* 0x0000224B 7D06000004         */ IL_0037: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabItem AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::tabInfo /* 04000006 */
		/* 0x00002250 2A                 */ IL_003c: ret
		/* 0x00002251 02                 */ IL_003d: ldarg.0
		/* 0x00002252 17                 */ IL_003e: ldc.i4.1
		/* 0x00002253 7D07000004         */ IL_003f: stfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input::_contentLoaded /* 04000007 */
		/* 0x00002258 2A                 */ IL_0044: ret
	} // end of method MMFlowsh_Input::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input

.class /* 02000005 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel
{
	// Nested Types
	.class /* 0200000A */ nested public auto ansi beforefieldinit grdFlowsheet_GridData_ItemTemplate
		extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel
	{
		// Fields
		.field /* 0400001E */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration cboBlkType_var1_Property
		.field /* 0400001F */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration MMTextBox1_var1_Property
		.field /* 04000020 */ private valuetype [mscorlib]System.Nullable`1<bool> '<IsProxy>k__BackingField'
		.custom /* 0C000020 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		.field /* 04000021 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration Inner_Property
		.field /* 04000022 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration Inlets_Property
		.field /* 04000023 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration Outlets_Property

		// Methods
		.method /* 06000043 */ public hidebysig specialname 
			instance object get_cboBlkType_var1 () cil managed 
		{
			// Method begins at RVA 0x3027
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003027 02                 */ IL_0000: ldarg.0
			/* 0x00003028 7E1E000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::cboBlkType_var1_Property /* 0400001E */
			/* 0x0000302D 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003032 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::get_cboBlkType_var1

		.method /* 06000044 */ public hidebysig specialname 
			instance object get_MMTextBox1_var1 () cil managed 
		{
			// Method begins at RVA 0x3034
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003034 02                 */ IL_0000: ldarg.0
			/* 0x00003035 7E1F000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::MMTextBox1_var1_Property /* 0400001F */
			/* 0x0000303A 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x0000303F 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::get_MMTextBox1_var1

		.method /* 06000045 */ public hidebysig specialname 
			instance valuetype [mscorlib]System.Nullable`1<bool> get_IsProxy () cil managed 
		{
			.custom /* 0C000030 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3041
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003041 02                 */ IL_0000: ldarg.0
			/* 0x00003042 7B20000004         */ IL_0001: ldfld valuetype [mscorlib]System.Nullable`1<bool> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::'<IsProxy>k__BackingField' /* 04000020 */
			/* 0x00003047 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::get_IsProxy

		.method /* 06000046 */ public hidebysig specialname 
			instance void set_IsProxy (
				valuetype [mscorlib]System.Nullable`1<bool> 'value'
			) cil managed 
		{
			.custom /* 0C000031 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3049
			// Header size: 1
			// Code size: 8 (0x8)
			.maxstack 8

			/* 0x00003049 02                 */ IL_0000: ldarg.0
			/* 0x0000304A 03                 */ IL_0001: ldarg.1
			/* 0x0000304B 7D20000004         */ IL_0002: stfld valuetype [mscorlib]System.Nullable`1<bool> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::'<IsProxy>k__BackingField' /* 04000020 */
			/* 0x00003050 2A                 */ IL_0007: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::set_IsProxy

		.method /* 06000047 */ public hidebysig specialname 
			instance object get_Inner () cil managed 
		{
			// Method begins at RVA 0x3052
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003052 02                 */ IL_0000: ldarg.0
			/* 0x00003053 7E21000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Inner_Property /* 04000021 */
			/* 0x00003058 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x0000305D 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::get_Inner

		.method /* 06000048 */ public hidebysig specialname 
			instance object get_Inlets () cil managed 
		{
			// Method begins at RVA 0x305f
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x0000305F 02                 */ IL_0000: ldarg.0
			/* 0x00003060 7E22000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Inlets_Property /* 04000022 */
			/* 0x00003065 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x0000306A 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::get_Inlets

		.method /* 06000049 */ public hidebysig specialname 
			instance object get_Outlets () cil managed 
		{
			// Method begins at RVA 0x306c
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x0000306C 02                 */ IL_0000: ldarg.0
			/* 0x0000306D 7E23000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Outlets_Property /* 04000023 */
			/* 0x00003072 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003077 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::get_Outlets

		.method /* 0600004A */ family hidebysig virtual 
			instance void OnSubPropertyDataChanged (
				class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration pd,
				string subPropertyName
			) cil managed 
		{
			// Method begins at RVA 0x3079
			// Header size: 1
			// Code size: 57 (0x39)
			.maxstack 8

			/* 0x00003079 03                 */ IL_0000: ldarg.1
			/* 0x0000307A 7E22000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Inlets_Property /* 04000022 */
			/* 0x0000307F 330D               */ IL_0006: bne.un.s IL_0015
			/* 0x00003081 04                 */ IL_0008: ldarg.2
			/* 0x00003082 729E010070         */ IL_0009: ldstr "Count" /* 7000019E */
			/* 0x00003087 283C00000A         */ IL_000e: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x0000308C 2D15               */ IL_0013: brtrue.s IL_002a
			/* 0x0000308E 03                 */ IL_0015: ldarg.1
			/* 0x0000308F 7E23000004         */ IL_0016: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Outlets_Property /* 04000023 */
			/* 0x00003094 3313               */ IL_001b: bne.un.s IL_0030
			/* 0x00003096 04                 */ IL_001d: ldarg.2
			/* 0x00003097 729E010070         */ IL_001e: ldstr "Count" /* 7000019E */
			/* 0x0000309C 283C00000A         */ IL_0023: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000030A1 2C06               */ IL_0028: brfalse.s IL_0030
			/* 0x000030A3 02                 */ IL_002a: ldarg.0
			/* 0x000030A4 284B000006         */ IL_002b: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::UpdateInnerItems() /* 0600004B */
			/* 0x000030A9 02                 */ IL_0030: ldarg.0
			/* 0x000030AA 03                 */ IL_0031: ldarg.1
			/* 0x000030AB 04                 */ IL_0032: ldarg.2
			/* 0x000030AC 283B00000A         */ IL_0033: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::OnSubPropertyDataChanged(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration, string) /* 0A00003B */
			/* 0x000030B1 2A                 */ IL_0038: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::OnSubPropertyDataChanged

		.method /* 0600004B */ assembly hidebysig 
			instance void UpdateInnerItems () cil managed 
		{
			// Method begins at RVA 0x30b4
			// Header size: 12
			// Code size: 351 (0x15f)
			.maxstack 4
			.locals /* 11000010 */ init (
				[0] class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData,
				[1] class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData,
				[2] int32,
				[3] class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData,
				[4] valuetype [mscorlib]System.Nullable`1<bool>,
				[5] int32,
				[6] class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate,
				[7] class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate,
				[8] class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate
			)

			/* 0x000030B4 02                 */ IL_0000: ldarg.0
			/* 0x000030B5 2845000006         */ IL_0001: call instance valuetype [mscorlib]System.Nullable`1<bool> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_IsProxy() /* 06000045 */
			/* 0x000030BA 1304               */ IL_0006: stloc.s 4
			/* 0x000030BC 1204               */ IL_0008: ldloca.s 4
			/* 0x000030BE 289E00000A         */ IL_000a: call instance bool valuetype [mscorlib]System.Nullable`1<bool>::get_HasValue() /* 0A00009E */
			/* 0x000030C3 2C24               */ IL_000f: brfalse.s IL_0035
			/* 0x000030C5 02                 */ IL_0011: ldarg.0
			/* 0x000030C6 2845000006         */ IL_0012: call instance valuetype [mscorlib]System.Nullable`1<bool> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_IsProxy() /* 06000045 */
			/* 0x000030CB 1304               */ IL_0017: stloc.s 4
			/* 0x000030CD 1204               */ IL_0019: ldloca.s 4
			/* 0x000030CF 289F00000A         */ IL_001b: call instance !0 valuetype [mscorlib]System.Nullable`1<bool>::get_Value() /* 0A00009F */
			/* 0x000030D4 2C13               */ IL_0020: brfalse.s IL_0035
			/* 0x000030D6 02                 */ IL_0022: ldarg.0
			/* 0x000030D7 7224050070         */ IL_0023: ldstr "NumRows" /* 70000524 */
			/* 0x000030DC 16                 */ IL_0028: ldc.i4.0
			/* 0x000030DD 8C85000001         */ IL_0029: box [mscorlib]System.Int32 /* 01000085 */
			/* 0x000030E2 17                 */ IL_002e: ldc.i4.1
			/* 0x000030E3 28C100000A         */ IL_002f: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveUpdateParameter(string, object, bool) /* 0A0000C1 */
			/* 0x000030E8 2A                 */ IL_0034: ret
			/* 0x000030E9 02                 */ IL_0035: ldarg.0
			/* 0x000030EA 2848000006         */ IL_0036: call instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_Inlets() /* 06000048 */
			/* 0x000030EF 7529000001         */ IL_003b: isinst [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData /* 01000029 */
			/* 0x000030F4 0A                 */ IL_0040: stloc.0
			/* 0x000030F5 02                 */ IL_0041: ldarg.0
			/* 0x000030F6 2849000006         */ IL_0042: call instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_Outlets() /* 06000049 */
			/* 0x000030FB 7529000001         */ IL_0047: isinst [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData /* 01000029 */
			/* 0x00003100 0B                 */ IL_004c: stloc.1
			/* 0x00003101 16                 */ IL_004d: ldc.i4.0
			/* 0x00003102 0C                 */ IL_004e: stloc.2
			/* 0x00003103 06                 */ IL_004f: ldloc.0
			/* 0x00003104 2C07               */ IL_0050: brfalse.s IL_0059
			/* 0x00003106 06                 */ IL_0052: ldloc.0
			/* 0x00003107 6F3D00000A         */ IL_0053: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
			/* 0x0000310C 0C                 */ IL_0058: stloc.2
			/* 0x0000310D 07                 */ IL_0059: ldloc.1
			/* 0x0000310E 2C10               */ IL_005a: brfalse.s IL_006c
			/* 0x00003110 07                 */ IL_005c: ldloc.1
			/* 0x00003111 6F3D00000A         */ IL_005d: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
			/* 0x00003116 08                 */ IL_0062: ldloc.2
			/* 0x00003117 3107               */ IL_0063: ble.s IL_006c
			/* 0x00003119 07                 */ IL_0065: ldloc.1
			/* 0x0000311A 6F3D00000A         */ IL_0066: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
			/* 0x0000311F 0C                 */ IL_006b: stloc.2
			/* 0x00003120 02                 */ IL_006c: ldarg.0
			/* 0x00003121 7224050070         */ IL_006d: ldstr "NumRows" /* 70000524 */
			/* 0x00003126 16                 */ IL_0072: ldc.i4.0
			/* 0x00003127 8C85000001         */ IL_0073: box [mscorlib]System.Int32 /* 01000085 */
			/* 0x0000312C 17                 */ IL_0078: ldc.i4.1
			/* 0x0000312D 28C100000A         */ IL_0079: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveUpdateParameter(string, object, bool) /* 0A0000C1 */
			/* 0x00003132 02                 */ IL_007e: ldarg.0
			/* 0x00003133 7224050070         */ IL_007f: ldstr "NumRows" /* 70000524 */
			/* 0x00003138 08                 */ IL_0084: ldloc.2
			/* 0x00003139 8C85000001         */ IL_0085: box [mscorlib]System.Int32 /* 01000085 */
			/* 0x0000313E 17                 */ IL_008a: ldc.i4.1
			/* 0x0000313F 28C100000A         */ IL_008b: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveUpdateParameter(string, object, bool) /* 0A0000C1 */
			/* 0x00003144 02                 */ IL_0090: ldarg.0
			/* 0x00003145 2847000006         */ IL_0091: call instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_Inner() /* 06000047 */
			/* 0x0000314A 7529000001         */ IL_0096: isinst [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData /* 01000029 */
			/* 0x0000314F 0D                 */ IL_009b: stloc.3
			/* 0x00003150 16                 */ IL_009c: ldc.i4.0
			/* 0x00003151 1305               */ IL_009d: stloc.s 5
			/* 0x00003153 38B2000000         */ IL_009f: br IL_0156
			/* 0x00003158 09                 */ IL_00a4: ldloc.3
			/* 0x00003159 1105               */ IL_00a5: ldloc.s 5
			/* 0x0000315B 6F3E00000A         */ IL_00a7: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Item(int32) /* 0A00003E */
			/* 0x00003160 750B000002         */ IL_00ac: isinst AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate /* 0200000B */
			/* 0x00003165 1306               */ IL_00b1: stloc.s 6
			/* 0x00003167 1106               */ IL_00b3: ldloc.s 6
			/* 0x00003169 3996000000         */ IL_00b5: brfalse IL_0150
			/* 0x0000316E 1105               */ IL_00ba: ldloc.s 5
			/* 0x00003170 06                 */ IL_00bc: ldloc.0
			/* 0x00003171 6F3D00000A         */ IL_00bd: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
			/* 0x00003176 2F31               */ IL_00c2: bge.s IL_00f5
			/* 0x00003178 06                 */ IL_00c4: ldloc.0
			/* 0x00003179 1105               */ IL_00c5: ldloc.s 5
			/* 0x0000317B 6F3E00000A         */ IL_00c7: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Item(int32) /* 0A00003E */
			/* 0x00003180 750C000002         */ IL_00cc: isinst AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate /* 0200000C */
			/* 0x00003185 1307               */ IL_00d1: stloc.s 7
			/* 0x00003187 1107               */ IL_00d3: ldloc.s 7
			/* 0x00003189 2C2E               */ IL_00d5: brfalse.s IL_0105
			/* 0x0000318B 1106               */ IL_00d7: ldloc.s 6
			/* 0x0000318D 1107               */ IL_00d9: ldloc.s 7
			/* 0x0000318F 6F5A000006         */ IL_00db: callvirt instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::get_grdInlet_StrmNode() /* 0600005A */
			/* 0x00003194 6F51000006         */ IL_00e0: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdInlet_StrmNode(object) /* 06000051 */
			/* 0x00003199 1106               */ IL_00e5: ldloc.s 6
			/* 0x0000319B 1107               */ IL_00e7: ldloc.s 7
			/* 0x0000319D 6F59000006         */ IL_00e9: callvirt instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::get_grdInlet_PortNode() /* 06000059 */
			/* 0x000031A2 6F53000006         */ IL_00ee: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdInlet_PortNode(object) /* 06000053 */
			/* 0x000031A7 2B10               */ IL_00f3: br.s IL_0105
			/* 0x000031A9 1106               */ IL_00f5: ldloc.s 6
			/* 0x000031AB 14                 */ IL_00f7: ldnull
			/* 0x000031AC 6F51000006         */ IL_00f8: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdInlet_StrmNode(object) /* 06000051 */
			/* 0x000031B1 1106               */ IL_00fd: ldloc.s 6
			/* 0x000031B3 14                 */ IL_00ff: ldnull
			/* 0x000031B4 6F53000006         */ IL_0100: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdInlet_PortNode(object) /* 06000053 */
			/* 0x000031B9 1105               */ IL_0105: ldloc.s 5
			/* 0x000031BB 07                 */ IL_0107: ldloc.1
			/* 0x000031BC 6F3D00000A         */ IL_0108: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
			/* 0x000031C1 2F31               */ IL_010d: bge.s IL_0140
			/* 0x000031C3 07                 */ IL_010f: ldloc.1
			/* 0x000031C4 1105               */ IL_0110: ldloc.s 5
			/* 0x000031C6 6F3E00000A         */ IL_0112: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Item(int32) /* 0A00003E */
			/* 0x000031CB 750D000002         */ IL_0117: isinst AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate /* 0200000D */
			/* 0x000031D0 1308               */ IL_011c: stloc.s 8
			/* 0x000031D2 1108               */ IL_011e: ldloc.s 8
			/* 0x000031D4 2C2E               */ IL_0120: brfalse.s IL_0150
			/* 0x000031D6 1106               */ IL_0122: ldloc.s 6
			/* 0x000031D8 1108               */ IL_0124: ldloc.s 8
			/* 0x000031DA 6F5F000006         */ IL_0126: callvirt instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::get_grdOutlet_StrmNode() /* 0600005F */
			/* 0x000031DF 6F55000006         */ IL_012b: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_StrmNode(object) /* 06000055 */
			/* 0x000031E4 1106               */ IL_0130: ldloc.s 6
			/* 0x000031E6 1108               */ IL_0132: ldloc.s 8
			/* 0x000031E8 6F60000006         */ IL_0134: callvirt instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::get_grdOutlet_PortNode() /* 06000060 */
			/* 0x000031ED 6F57000006         */ IL_0139: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_PortNode(object) /* 06000057 */
			/* 0x000031F2 2B10               */ IL_013e: br.s IL_0150
			/* 0x000031F4 1106               */ IL_0140: ldloc.s 6
			/* 0x000031F6 14                 */ IL_0142: ldnull
			/* 0x000031F7 6F55000006         */ IL_0143: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_StrmNode(object) /* 06000055 */
			/* 0x000031FC 1106               */ IL_0148: ldloc.s 6
			/* 0x000031FE 14                 */ IL_014a: ldnull
			/* 0x000031FF 6F57000006         */ IL_014b: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_PortNode(object) /* 06000057 */
			/* 0x00003204 1105               */ IL_0150: ldloc.s 5
			/* 0x00003206 17                 */ IL_0152: ldc.i4.1
			/* 0x00003207 58                 */ IL_0153: add
			/* 0x00003208 1305               */ IL_0154: stloc.s 5
			/* 0x0000320A 1105               */ IL_0156: ldloc.s 5
			/* 0x0000320C 08                 */ IL_0158: ldloc.2
			/* 0x0000320D 3F46FFFFFF         */ IL_0159: blt IL_00a4
			/* 0x00003212 2A                 */ IL_015e: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::UpdateInnerItems

		.method /* 0600004C */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x321f
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x0000321F 02                 */ IL_0000: ldarg.0
			/* 0x00003220 28C200000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::.ctor() /* 0A0000C2 */
			/* 0x00003225 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::.ctor

		.method /* 0600004D */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x3228
			// Header size: 12
			// Code size: 461 (0x1cd)
			.maxstack 9

			/* 0x00003228 7234050070         */ IL_0000: ldstr "cboBlkType_var1" /* 70000534 */
			/* 0x0000322D D00A000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
			/* 0x00003232 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003237 733000000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x0000323C 25                 */ IL_0014: dup
			/* 0x0000323D 18                 */ IL_0015: ldc.i4.2
			/* 0x0000323E 6FC300000A         */ IL_0016: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A0000C3 */
			/* 0x00003243 25                 */ IL_001b: dup
			/* 0x00003244 7254050070         */ IL_001c: ldstr "@main.Input.MDLTYPE.@y" /* 70000554 */
			/* 0x00003249 6F3100000A         */ IL_0021: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x0000324E 25                 */ IL_0026: dup
			/* 0x0000324F 73C400000A         */ IL_0027: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003254 25                 */ IL_002c: dup
			/* 0x00003255 6FC500000A         */ IL_002d: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x0000325A 73C400000A         */ IL_0032: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x0000325F 25                 */ IL_0037: dup
			/* 0x00003260 7282050070         */ IL_0038: ldstr "@main.CC Nodes.SPECBLKID.@y" /* 70000582 */
			/* 0x00003265 6FC600000A         */ IL_003d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x0000326A 6FC700000A         */ IL_0042: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x0000326F 25                 */ IL_0047: dup
			/* 0x00003270 6FC500000A         */ IL_0048: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x00003275 73C400000A         */ IL_004d: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x0000327A 25                 */ IL_0052: dup
			/* 0x0000327B 72BA050070         */ IL_0053: ldstr "Top.appModelV8.Settings.EnableFlowsheetSectionForm" /* 700005BA */
			/* 0x00003280 6FC600000A         */ IL_0058: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x00003285 6FC700000A         */ IL_005d: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x0000328A 25                 */ IL_0062: dup
			/* 0x0000328B 1E                 */ IL_0063: ldc.i4.8
			/* 0x0000328C 6FC800000A         */ IL_0064: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_Operator(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalOperator) /* 0A0000C8 */
			/* 0x00003291 6FC900000A         */ IL_0069: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsEnabledCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000C9 */
			/* 0x00003296 283200000A         */ IL_006e: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x0000329B 801E000004         */ IL_0073: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::cboBlkType_var1_Property /* 0400001E */
			/* 0x000032A0 7220060070         */ IL_0078: ldstr "MMTextBox1_var1" /* 70000620 */
			/* 0x000032A5 D00A000002         */ IL_007d: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
			/* 0x000032AA 282F00000A         */ IL_0082: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x000032AF 733000000A         */ IL_0087: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x000032B4 25                 */ IL_008c: dup
			/* 0x000032B5 1C                 */ IL_008d: ldc.i4.6
			/* 0x000032B6 6FC300000A         */ IL_008e: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A0000C3 */
			/* 0x000032BB 25                 */ IL_0093: dup
			/* 0x000032BC 7240060070         */ IL_0094: ldstr "@main.Input.BLKTYPE.@y" /* 70000640 */
			/* 0x000032C1 6F3100000A         */ IL_0099: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x000032C6 25                 */ IL_009e: dup
			/* 0x000032C7 17                 */ IL_009f: ldc.i4.1
			/* 0x000032C8 73CA00000A         */ IL_00a0: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDisplayedCase>::.ctor(!0) /* 0A0000CA */
			/* 0x000032CD 6FCB00000A         */ IL_00a5: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DisplayedCase(valuetype [mscorlib]System.Nullable`1<valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDisplayedCase>) /* 0A0000CB */
			/* 0x000032D2 25                 */ IL_00aa: dup
			/* 0x000032D3 14                 */ IL_00ab: ldnull
			/* 0x000032D4 FE0616000006       */ IL_00ac: ldftn bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::ValidateBlockId(object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer) /* 06000016 */
			/* 0x000032DA 73CC00000A         */ IL_00b2: newobj instance void class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>::.ctor(object, native int) /* 0A0000CC */
			/* 0x000032DF 6FCD00000A         */ IL_00b7: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ValueValidator(class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>) /* 0A0000CD */
			/* 0x000032E4 25                 */ IL_00bc: dup
			/* 0x000032E5 73C400000A         */ IL_00bd: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000032EA 25                 */ IL_00c2: dup
			/* 0x000032EB 72BA050070         */ IL_00c3: ldstr "Top.appModelV8.Settings.EnableFlowsheetSectionForm" /* 700005BA */
			/* 0x000032F0 6FC600000A         */ IL_00c8: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x000032F5 6FC900000A         */ IL_00cd: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsEnabledCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000C9 */
			/* 0x000032FA 283200000A         */ IL_00d2: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x000032FF 801F000004         */ IL_00d7: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::MMTextBox1_var1_Property /* 0400001F */
			/* 0x00003304 726E060070         */ IL_00dc: ldstr "Inner" /* 7000066E */
			/* 0x00003309 D00A000002         */ IL_00e1: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
			/* 0x0000330E 282F00000A         */ IL_00e6: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003313 736800000A         */ IL_00eb: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::.ctor() /* 0A000068 */
			/* 0x00003318 25                 */ IL_00f0: dup
			/* 0x00003319 D00B000002         */ IL_00f1: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate /* 0200000B */
			/* 0x0000331E 282F00000A         */ IL_00f6: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003323 6F6900000A         */ IL_00fb: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_ItemType(class [mscorlib]System.Type) /* 0A000069 */
			/* 0x00003328 25                 */ IL_0100: dup
			/* 0x00003329 73CE00000A         */ IL_0101: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvParameterIndexBasis::.ctor() /* 0A0000CE */
			/* 0x0000332E 25                 */ IL_0106: dup
			/* 0x0000332F 7224050070         */ IL_0107: ldstr "NumRows" /* 70000524 */
			/* 0x00003334 6FCF00000A         */ IL_010c: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvParameterIndexBasis::set_Parameter(string) /* 0A0000CF */
			/* 0x00003339 6F6E00000A         */ IL_0111: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_IndexBasis(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase) /* 0A00006E */
			/* 0x0000333E 283200000A         */ IL_0116: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003343 8021000004         */ IL_011b: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Inner_Property /* 04000021 */
			/* 0x00003348 72AA010070         */ IL_0120: ldstr "Inlets" /* 700001AA */
			/* 0x0000334D D00A000002         */ IL_0125: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
			/* 0x00003352 282F00000A         */ IL_012a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003357 736800000A         */ IL_012f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::.ctor() /* 0A000068 */
			/* 0x0000335C 25                 */ IL_0134: dup
			/* 0x0000335D D00C000002         */ IL_0135: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate /* 0200000C */
			/* 0x00003362 282F00000A         */ IL_013a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003367 6F6900000A         */ IL_013f: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_ItemType(class [mscorlib]System.Type) /* 0A000069 */
			/* 0x0000336C 25                 */ IL_0144: dup
			/* 0x0000336D 736A00000A         */ IL_0145: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::.ctor() /* 0A00006A */
			/* 0x00003372 25                 */ IL_014a: dup
			/* 0x00003373 727A060070         */ IL_014b: ldstr "@main.Input.INSTRM.@y" /* 7000067A */
			/* 0x00003378 6F6B00000A         */ IL_0150: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_DataPath(string) /* 0A00006B */
			/* 0x0000337D 25                 */ IL_0155: dup
			/* 0x0000337E 16                 */ IL_0156: ldc.i4.0
			/* 0x0000337F 6F6C00000A         */ IL_0157: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_UseChildId(bool) /* 0A00006C */
			/* 0x00003384 25                 */ IL_015c: dup
			/* 0x00003385 72A6060070         */ IL_015d: ldstr "x" /* 700006A6 */
			/* 0x0000338A 6F6D00000A         */ IL_0162: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase::set_Name(string) /* 0A00006D */
			/* 0x0000338F 6F6E00000A         */ IL_0167: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_IndexBasis(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase) /* 0A00006E */
			/* 0x00003394 283200000A         */ IL_016c: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003399 8022000004         */ IL_0171: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Inlets_Property /* 04000022 */
			/* 0x0000339E 72B8010070         */ IL_0176: ldstr "Outlets" /* 700001B8 */
			/* 0x000033A3 D00A000002         */ IL_017b: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
			/* 0x000033A8 282F00000A         */ IL_0180: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x000033AD 736800000A         */ IL_0185: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::.ctor() /* 0A000068 */
			/* 0x000033B2 25                 */ IL_018a: dup
			/* 0x000033B3 D00D000002         */ IL_018b: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate /* 0200000D */
			/* 0x000033B8 282F00000A         */ IL_0190: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x000033BD 6F6900000A         */ IL_0195: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_ItemType(class [mscorlib]System.Type) /* 0A000069 */
			/* 0x000033C2 25                 */ IL_019a: dup
			/* 0x000033C3 736A00000A         */ IL_019b: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::.ctor() /* 0A00006A */
			/* 0x000033C8 25                 */ IL_01a0: dup
			/* 0x000033C9 72AA060070         */ IL_01a1: ldstr "@main.Input.OUTSTRM.@y" /* 700006AA */
			/* 0x000033CE 6F6B00000A         */ IL_01a6: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_DataPath(string) /* 0A00006B */
			/* 0x000033D3 25                 */ IL_01ab: dup
			/* 0x000033D4 16                 */ IL_01ac: ldc.i4.0
			/* 0x000033D5 6F6C00000A         */ IL_01ad: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_UseChildId(bool) /* 0A00006C */
			/* 0x000033DA 25                 */ IL_01b2: dup
			/* 0x000033DB 72A6060070         */ IL_01b3: ldstr "x" /* 700006A6 */
			/* 0x000033E0 6F6D00000A         */ IL_01b8: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase::set_Name(string) /* 0A00006D */
			/* 0x000033E5 6F6E00000A         */ IL_01bd: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_IndexBasis(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase) /* 0A00006E */
			/* 0x000033EA 283200000A         */ IL_01c2: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x000033EF 8023000004         */ IL_01c7: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::Outlets_Property /* 04000023 */
			/* 0x000033F4 2A                 */ IL_01cc: ret
		} // end of method grdFlowsheet_GridData_ItemTemplate::.cctor

		// Properties
		.property /* 1700000F */ instance object cboBlkType_var1()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_cboBlkType_var1()
		}
		.property /* 17000010 */ instance object MMTextBox1_var1()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_MMTextBox1_var1()
		}
		.property /* 17000011 */ instance valuetype [mscorlib]System.Nullable`1<bool> IsProxy()
		{
			.get instance valuetype [mscorlib]System.Nullable`1<bool> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_IsProxy()
			.set instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::set_IsProxy(valuetype [mscorlib]System.Nullable`1<bool>)
		}
		.property /* 17000012 */ instance object Inner()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_Inner()
		}
		.property /* 17000013 */ instance object Inlets()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_Inlets()
		}
		.property /* 17000014 */ instance object Outlets()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::get_Outlets()
		}

	} // end of class grdFlowsheet_GridData_ItemTemplate

	.class /* 0200000B */ nested public auto ansi beforefieldinit grdFlowsheet_GridData_InnerTemplate
		extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel
	{
		// Fields
		.field /* 04000024 */ private static int32 count
		.field /* 04000025 */ private int32 mycount
		.field /* 04000026 */ private object _GrdInlet_StrmNode
		.field /* 04000027 */ private object '<grdInlet_PortNode>k__BackingField'
		.custom /* 0C000026 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		.field /* 04000028 */ private object '<grdOutlet_StrmNode>k__BackingField'
		.custom /* 0C000027 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		.field /* 04000029 */ private object '<grdOutlet_PortNode>k__BackingField'
		.custom /* 0C000028 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)

		// Methods
		.method /* 0600004E */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x3401
			// Header size: 1
			// Code size: 30 (0x1e)
			.maxstack 8

			/* 0x00003401 02                 */ IL_0000: ldarg.0
			/* 0x00003402 28C200000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::.ctor() /* 0A0000C2 */
			/* 0x00003407 7E24000004         */ IL_0006: ldsfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::count /* 04000024 */
			/* 0x0000340C 17                 */ IL_000b: ldc.i4.1
			/* 0x0000340D 58                 */ IL_000c: add
			/* 0x0000340E 8024000004         */ IL_000d: stsfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::count /* 04000024 */
			/* 0x00003413 02                 */ IL_0012: ldarg.0
			/* 0x00003414 7E24000004         */ IL_0013: ldsfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::count /* 04000024 */
			/* 0x00003419 7D25000004         */ IL_0018: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::mycount /* 04000025 */
			/* 0x0000341E 2A                 */ IL_001d: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::.ctor

		.method /* 0600004F */ public hidebysig specialname 
			instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData get_Test () cil managed 
		{
			// Method begins at RVA 0x3420
			// Header size: 1
			// Code size: 23 (0x17)
			.maxstack 8

			/* 0x00003420 73D000000A         */ IL_0000: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData::.ctor() /* 0A0000D0 */
			/* 0x00003425 25                 */ IL_0005: dup
			/* 0x00003426 02                 */ IL_0006: ldarg.0
			/* 0x00003427 7C25000004         */ IL_0007: ldflda int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::mycount /* 04000025 */
			/* 0x0000342C 28B200000A         */ IL_000c: call instance string [mscorlib]System.Int32::ToString() /* 0A0000B2 */
			/* 0x00003431 6FD100000A         */ IL_0011: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData::set_Value(object) /* 0A0000D1 */
			/* 0x00003436 2A                 */ IL_0016: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::get_Test

		.method /* 06000050 */ public hidebysig specialname 
			instance object get_grdInlet_StrmNode () cil managed 
		{
			// Method begins at RVA 0x3438
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003438 02                 */ IL_0000: ldarg.0
			/* 0x00003439 7B26000004         */ IL_0001: ldfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::_GrdInlet_StrmNode /* 04000026 */
			/* 0x0000343E 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::get_grdInlet_StrmNode

		.method /* 06000051 */ public hidebysig specialname 
			instance void set_grdInlet_StrmNode (
				object 'value'
			) cil managed 
		{
			// Method begins at RVA 0x3440
			// Header size: 1
			// Code size: 8 (0x8)
			.maxstack 8

			/* 0x00003440 02                 */ IL_0000: ldarg.0
			/* 0x00003441 03                 */ IL_0001: ldarg.1
			/* 0x00003442 7D26000004         */ IL_0002: stfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::_GrdInlet_StrmNode /* 04000026 */
			/* 0x00003447 2A                 */ IL_0007: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::set_grdInlet_StrmNode

		.method /* 06000052 */ public hidebysig specialname 
			instance object get_grdInlet_PortNode () cil managed 
		{
			.custom /* 0C000032 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3449
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003449 02                 */ IL_0000: ldarg.0
			/* 0x0000344A 7B27000004         */ IL_0001: ldfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::'<grdInlet_PortNode>k__BackingField' /* 04000027 */
			/* 0x0000344F 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::get_grdInlet_PortNode

		.method /* 06000053 */ public hidebysig specialname 
			instance void set_grdInlet_PortNode (
				object 'value'
			) cil managed 
		{
			.custom /* 0C000033 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3451
			// Header size: 1
			// Code size: 8 (0x8)
			.maxstack 8

			/* 0x00003451 02                 */ IL_0000: ldarg.0
			/* 0x00003452 03                 */ IL_0001: ldarg.1
			/* 0x00003453 7D27000004         */ IL_0002: stfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::'<grdInlet_PortNode>k__BackingField' /* 04000027 */
			/* 0x00003458 2A                 */ IL_0007: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::set_grdInlet_PortNode

		.method /* 06000054 */ public hidebysig specialname 
			instance object get_grdOutlet_StrmNode () cil managed 
		{
			.custom /* 0C000034 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x345a
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x0000345A 02                 */ IL_0000: ldarg.0
			/* 0x0000345B 7B28000004         */ IL_0001: ldfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::'<grdOutlet_StrmNode>k__BackingField' /* 04000028 */
			/* 0x00003460 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::get_grdOutlet_StrmNode

		.method /* 06000055 */ public hidebysig specialname 
			instance void set_grdOutlet_StrmNode (
				object 'value'
			) cil managed 
		{
			.custom /* 0C000035 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3462
			// Header size: 1
			// Code size: 8 (0x8)
			.maxstack 8

			/* 0x00003462 02                 */ IL_0000: ldarg.0
			/* 0x00003463 03                 */ IL_0001: ldarg.1
			/* 0x00003464 7D28000004         */ IL_0002: stfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::'<grdOutlet_StrmNode>k__BackingField' /* 04000028 */
			/* 0x00003469 2A                 */ IL_0007: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_StrmNode

		.method /* 06000056 */ public hidebysig specialname 
			instance object get_grdOutlet_PortNode () cil managed 
		{
			.custom /* 0C000036 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x346b
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x0000346B 02                 */ IL_0000: ldarg.0
			/* 0x0000346C 7B29000004         */ IL_0001: ldfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::'<grdOutlet_PortNode>k__BackingField' /* 04000029 */
			/* 0x00003471 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::get_grdOutlet_PortNode

		.method /* 06000057 */ public hidebysig specialname 
			instance void set_grdOutlet_PortNode (
				object 'value'
			) cil managed 
		{
			.custom /* 0C000037 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3473
			// Header size: 1
			// Code size: 8 (0x8)
			.maxstack 8

			/* 0x00003473 02                 */ IL_0000: ldarg.0
			/* 0x00003474 03                 */ IL_0001: ldarg.1
			/* 0x00003475 7D29000004         */ IL_0002: stfld object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::'<grdOutlet_PortNode>k__BackingField' /* 04000029 */
			/* 0x0000347A 2A                 */ IL_0007: ret
		} // end of method grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_PortNode

		// Properties
		.property /* 17000015 */ instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData Test()
		{
			.get instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::get_Test()
		}
		.property /* 17000016 */ instance object grdInlet_StrmNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::get_grdInlet_StrmNode()
			.set instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdInlet_StrmNode(object)
		}
		.property /* 17000017 */ instance object grdInlet_PortNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::get_grdInlet_PortNode()
			.set instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdInlet_PortNode(object)
		}
		.property /* 17000018 */ instance object grdOutlet_StrmNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::get_grdOutlet_StrmNode()
			.set instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_StrmNode(object)
		}
		.property /* 17000019 */ instance object grdOutlet_PortNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::get_grdOutlet_PortNode()
			.set instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InnerTemplate::set_grdOutlet_PortNode(object)
		}

	} // end of class grdFlowsheet_GridData_InnerTemplate

	.class /* 0200000C */ nested public auto ansi beforefieldinit grdFlowsheet_GridData_InletsTemplate
		extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel
	{
		// Fields
		.field /* 0400002A */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration grdInlet_PortNode_Property
		.field /* 0400002B */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration grdInlet_StrmNode_Property

		// Methods
		.method /* 06000058 */ family hidebysig virtual 
			instance void OnSubPropertyDataChanged (
				class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration pd,
				string subPropertyName
			) cil managed 
		{
			// Method begins at RVA 0x347c
			// Header size: 12
			// Code size: 114 (0x72)
			.maxstack 4
			.locals /* 11000011 */ init (
				[0] class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage
			)

			/* 0x0000347C 03                 */ IL_0000: ldarg.1
			/* 0x0000347D 6FD200000A         */ IL_0001: callvirt instance string [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::get_Name() /* 0A0000D2 */
			/* 0x00003482 72D8060070         */ IL_0006: ldstr "grdInlet_StrmNode" /* 700006D8 */
			/* 0x00003487 283C00000A         */ IL_000b: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x0000348C 2C57               */ IL_0010: brfalse.s IL_0069
			/* 0x0000348E 04                 */ IL_0012: ldarg.2
			/* 0x0000348F 72FC060070         */ IL_0013: ldstr "Value" /* 700006FC */
			/* 0x00003494 283C00000A         */ IL_0018: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x00003499 2C4A               */ IL_001d: brfalse.s IL_0069
			/* 0x0000349B 02                 */ IL_001f: ldarg.0
			/* 0x0000349C 28D300000A         */ IL_0020: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::get_Parent() /* 0A0000D3 */
			/* 0x000034A1 7530000001         */ IL_0025: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel /* 01000030 */
			/* 0x000034A6 25                 */ IL_002a: dup
			/* 0x000034A7 2D04               */ IL_002b: brtrue.s IL_0031
			/* 0x000034A9 26                 */ IL_002d: pop
			/* 0x000034AA 14                 */ IL_002e: ldnull
			/* 0x000034AB 2B05               */ IL_002f: br.s IL_0036
			/* 0x000034AD 28D300000A         */ IL_0031: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::get_Parent() /* 0A0000D3 */
			/* 0x000034B2 7530000001         */ IL_0036: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel /* 01000030 */
			/* 0x000034B7 25                 */ IL_003b: dup
			/* 0x000034B8 2D04               */ IL_003c: brtrue.s IL_0042
			/* 0x000034BA 26                 */ IL_003e: pop
			/* 0x000034BB 14                 */ IL_003f: ldnull
			/* 0x000034BC 2B05               */ IL_0040: br.s IL_0047
			/* 0x000034BE 28D400000A         */ IL_0042: call instance object [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::get_View() /* 0A0000D4 */
			/* 0x000034C3 7534000001         */ IL_0047: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage /* 01000034 */
			/* 0x000034C8 0A                 */ IL_004c: stloc.0
			/* 0x000034C9 06                 */ IL_004d: ldloc.0
			/* 0x000034CA 2C19               */ IL_004e: brfalse.s IL_0069
			/* 0x000034CC 06                 */ IL_0050: ldloc.0
			/* 0x000034CD 6FD500000A         */ IL_0051: callvirt instance class [WindowsBase]System.Windows.Threading.Dispatcher [WindowsBase]System.Windows.Threading.DispatcherObject::get_Dispatcher() /* 0A0000D5 */
			/* 0x000034D2 1B                 */ IL_0056: ldc.i4.5
			/* 0x000034D3 02                 */ IL_0057: ldarg.0
			/* 0x000034D4 FE065D000006       */ IL_0058: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::'<OnSubPropertyDataChanged>b__0_0'() /* 0600005D */
			/* 0x000034DA 73D600000A         */ IL_005e: newobj instance void [mscorlib]System.Action::.ctor(object, native int) /* 0A0000D6 */
			/* 0x000034DF 6FD700000A         */ IL_0063: callvirt instance class [WindowsBase]System.Windows.Threading.DispatcherOperation [WindowsBase]System.Windows.Threading.Dispatcher::BeginInvoke(valuetype [WindowsBase]System.Windows.Threading.DispatcherPriority, class [mscorlib]System.Delegate) /* 0A0000D7 */
			/* 0x000034E4 26                 */ IL_0068: pop
			/* 0x000034E5 02                 */ IL_0069: ldarg.0
			/* 0x000034E6 03                 */ IL_006a: ldarg.1
			/* 0x000034E7 04                 */ IL_006b: ldarg.2
			/* 0x000034E8 283B00000A         */ IL_006c: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::OnSubPropertyDataChanged(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration, string) /* 0A00003B */
			/* 0x000034ED 2A                 */ IL_0071: ret
		} // end of method grdFlowsheet_GridData_InletsTemplate::OnSubPropertyDataChanged

		.method /* 06000059 */ public hidebysig specialname 
			instance object get_grdInlet_PortNode () cil managed 
		{
			// Method begins at RVA 0x34fa
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x000034FA 02                 */ IL_0000: ldarg.0
			/* 0x000034FB 7E2A000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::grdInlet_PortNode_Property /* 0400002A */
			/* 0x00003500 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003505 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_InletsTemplate::get_grdInlet_PortNode

		.method /* 0600005A */ public hidebysig specialname 
			instance object get_grdInlet_StrmNode () cil managed 
		{
			// Method begins at RVA 0x3507
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003507 02                 */ IL_0000: ldarg.0
			/* 0x00003508 7E2B000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::grdInlet_StrmNode_Property /* 0400002B */
			/* 0x0000350D 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003512 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_InletsTemplate::get_grdInlet_StrmNode

		.method /* 0600005B */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x321f
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x0000321F 02                 */ IL_0000: ldarg.0
			/* 0x00003220 28C200000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::.ctor() /* 0A0000C2 */
			/* 0x00003225 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_InletsTemplate::.ctor

		.method /* 0600005C */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x3514
			// Header size: 12
			// Code size: 331 (0x14b)
			.maxstack 9

			/* 0x00003514 7208070070         */ IL_0000: ldstr "grdInlet_PortNode" /* 70000708 */
			/* 0x00003519 D00C000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate /* 0200000C */
			/* 0x0000351E 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003523 733000000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x00003528 25                 */ IL_0014: dup
			/* 0x00003529 722C070070         */ IL_0015: ldstr "@main.Input.INPORT.@y.@x" /* 7000072C */
			/* 0x0000352E 6F3100000A         */ IL_001a: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003533 25                 */ IL_001f: dup
			/* 0x00003534 73C400000A         */ IL_0020: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003539 25                 */ IL_0025: dup
			/* 0x0000353A 6FC500000A         */ IL_0026: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x0000353F 73C400000A         */ IL_002b: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003544 25                 */ IL_0030: dup
			/* 0x00003545 72BA050070         */ IL_0031: ldstr "Top.appModelV8.Settings.EnableFlowsheetSectionForm" /* 700005BA */
			/* 0x0000354A 6FC600000A         */ IL_0036: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x0000354F 6FC700000A         */ IL_003b: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x00003554 25                 */ IL_0040: dup
			/* 0x00003555 6FC500000A         */ IL_0041: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x0000355A 73C400000A         */ IL_0046: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x0000355F 25                 */ IL_004b: dup
			/* 0x00003560 725E070070         */ IL_004c: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x00003565 6FC600000A         */ IL_0051: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x0000356A 6FC700000A         */ IL_0056: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x0000356F 25                 */ IL_005b: dup
			/* 0x00003570 1E                 */ IL_005c: ldc.i4.8
			/* 0x00003571 6FC800000A         */ IL_005d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_Operator(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalOperator) /* 0A0000C8 */
			/* 0x00003576 6FC900000A         */ IL_0062: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsEnabledCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000C9 */
			/* 0x0000357B 25                 */ IL_0067: dup
			/* 0x0000357C 73C400000A         */ IL_0068: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003581 25                 */ IL_006d: dup
			/* 0x00003582 725E070070         */ IL_006e: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x00003587 6FC600000A         */ IL_0073: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x0000358C 6FD800000A         */ IL_0078: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsVisibleCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000D8 */
			/* 0x00003591 25                 */ IL_007d: dup
			/* 0x00003592 14                 */ IL_007e: ldnull
			/* 0x00003593 FE0618000006       */ IL_007f: ldftn bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::ValidatePort(object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer) /* 06000018 */
			/* 0x00003599 73CC00000A         */ IL_0085: newobj instance void class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>::.ctor(object, native int) /* 0A0000CC */
			/* 0x0000359E 6FCD00000A         */ IL_008a: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ValueValidator(class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>) /* 0A0000CD */
			/* 0x000035A3 283200000A         */ IL_008f: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x000035A8 802A000004         */ IL_0094: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::grdInlet_PortNode_Property /* 0400002A */
			/* 0x000035AD 72D8060070         */ IL_0099: ldstr "grdInlet_StrmNode" /* 700006D8 */
			/* 0x000035B2 D00C000002         */ IL_009e: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate /* 0200000C */
			/* 0x000035B7 282F00000A         */ IL_00a3: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x000035BC 733000000A         */ IL_00a8: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x000035C1 25                 */ IL_00ad: dup
			/* 0x000035C2 7296070070         */ IL_00ae: ldstr "@main.Input.INSTRM.@y.@x" /* 70000796 */
			/* 0x000035C7 6F3100000A         */ IL_00b3: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x000035CC 25                 */ IL_00b8: dup
			/* 0x000035CD 73C400000A         */ IL_00b9: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000035D2 25                 */ IL_00be: dup
			/* 0x000035D3 6FC500000A         */ IL_00bf: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x000035D8 73C400000A         */ IL_00c4: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000035DD 25                 */ IL_00c9: dup
			/* 0x000035DE 72BA050070         */ IL_00ca: ldstr "Top.appModelV8.Settings.EnableFlowsheetSectionForm" /* 700005BA */
			/* 0x000035E3 6FC600000A         */ IL_00cf: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x000035E8 6FC700000A         */ IL_00d4: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x000035ED 25                 */ IL_00d9: dup
			/* 0x000035EE 6FC500000A         */ IL_00da: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x000035F3 73C400000A         */ IL_00df: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000035F8 25                 */ IL_00e4: dup
			/* 0x000035F9 725E070070         */ IL_00e5: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x000035FE 6FC600000A         */ IL_00ea: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x00003603 6FC700000A         */ IL_00ef: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x00003608 25                 */ IL_00f4: dup
			/* 0x00003609 1E                 */ IL_00f5: ldc.i4.8
			/* 0x0000360A 6FC800000A         */ IL_00f6: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_Operator(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalOperator) /* 0A0000C8 */
			/* 0x0000360F 6FC900000A         */ IL_00fb: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsEnabledCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000C9 */
			/* 0x00003614 25                 */ IL_0100: dup
			/* 0x00003615 73C400000A         */ IL_0101: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x0000361A 25                 */ IL_0106: dup
			/* 0x0000361B 725E070070         */ IL_0107: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x00003620 6FC600000A         */ IL_010c: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x00003625 6FD800000A         */ IL_0111: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsVisibleCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000D8 */
			/* 0x0000362A 25                 */ IL_0116: dup
			/* 0x0000362B 16                 */ IL_0117: ldc.i4.0
			/* 0x0000362C 733F00000A         */ IL_0118: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x00003631 6FD900000A         */ IL_011d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_AllowNew(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000D9 */
			/* 0x00003636 25                 */ IL_0122: dup
			/* 0x00003637 17                 */ IL_0123: ldc.i4.1
			/* 0x00003638 733F00000A         */ IL_0124: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x0000363D 6FDA00000A         */ IL_0129: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_AllowEmptyOptions(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000DA */
			/* 0x00003642 25                 */ IL_012e: dup
			/* 0x00003643 14                 */ IL_012f: ldnull
			/* 0x00003644 FE0617000006       */ IL_0130: ldftn bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::ValidateStreamId(object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer) /* 06000017 */
			/* 0x0000364A 73CC00000A         */ IL_0136: newobj instance void class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>::.ctor(object, native int) /* 0A0000CC */
			/* 0x0000364F 6FCD00000A         */ IL_013b: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ValueValidator(class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>) /* 0A0000CD */
			/* 0x00003654 283200000A         */ IL_0140: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003659 802B000004         */ IL_0145: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::grdInlet_StrmNode_Property /* 0400002B */
			/* 0x0000365E 2A                 */ IL_014a: ret
		} // end of method grdFlowsheet_GridData_InletsTemplate::.cctor

		.method /* 0600005D */ private hidebysig 
			instance void '<OnSubPropertyDataChanged>b__0_0' () cil managed 
		{
			.custom /* 0C000038 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x366c
			// Header size: 12
			// Code size: 102 (0x66)
			.maxstack 5
			.locals /* 11000012 */ init (
				[0] string,
				[1] string
			)

			/* 0x0000366C 02                 */ IL_0000: ldarg.0
			/* 0x0000366D 7296070070         */ IL_0001: ldstr "@main.Input.INSTRM.@y.@x" /* 70000796 */
			/* 0x00003672 72C8070070         */ IL_0006: ldstr "value" /* 700007C8 */
			/* 0x00003677 28DB00000A         */ IL_000b: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPathAndGet(string, string) /* 0A0000DB */
			/* 0x0000367C 289B00000A         */ IL_0010: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
			/* 0x00003681 0A                 */ IL_0015: stloc.0
			/* 0x00003682 06                 */ IL_0016: ldloc.0
			/* 0x00003683 28AE00000A         */ IL_0017: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x00003688 2D47               */ IL_001c: brtrue.s IL_0065
			/* 0x0000368A 02                 */ IL_001e: ldarg.0
			/* 0x0000368B 722C070070         */ IL_001f: ldstr "@main.Input.INPORT.@y.@x" /* 7000072C */
			/* 0x00003690 72C8070070         */ IL_0024: ldstr "value" /* 700007C8 */
			/* 0x00003695 28DB00000A         */ IL_0029: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPathAndGet(string, string) /* 0A0000DB */
			/* 0x0000369A 289B00000A         */ IL_002e: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
			/* 0x0000369F 0B                 */ IL_0033: stloc.1
			/* 0x000036A0 07                 */ IL_0034: ldloc.1
			/* 0x000036A1 28AE00000A         */ IL_0035: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x000036A6 2D0D               */ IL_003a: brtrue.s IL_0049
			/* 0x000036A8 07                 */ IL_003c: ldloc.1
			/* 0x000036A9 7236020070         */ IL_003d: ldstr "$(IN)" /* 70000236 */
			/* 0x000036AE 6F6700000A         */ IL_0042: callvirt instance bool [mscorlib]System.String::EndsWith(string) /* 0A000067 */
			/* 0x000036B3 2C1C               */ IL_0047: brfalse.s IL_0065
			/* 0x000036B5 02                 */ IL_0049: ldarg.0
			/* 0x000036B6 722C070070         */ IL_004a: ldstr "@main.Input.INPORT.@y.@x" /* 7000072C */
			/* 0x000036BB 72C8070070         */ IL_004f: ldstr "value" /* 700007C8 */
			/* 0x000036C0 06                 */ IL_0054: ldloc.0
			/* 0x000036C1 72D4070070         */ IL_0055: ldstr "(IN)" /* 700007D4 */
			/* 0x000036C6 28A000000A         */ IL_005a: call string [mscorlib]System.String::Concat(string, string) /* 0A0000A0 */
			/* 0x000036CB 28DC00000A         */ IL_005f: call instance bool [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPathAndSet(string, string, object) /* 0A0000DC */
			/* 0x000036D0 26                 */ IL_0064: pop
			/* 0x000036D1 2A                 */ IL_0065: ret
		} // end of method grdFlowsheet_GridData_InletsTemplate::'<OnSubPropertyDataChanged>b__0_0'

		// Properties
		.property /* 1700001A */ instance object grdInlet_PortNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::get_grdInlet_PortNode()
		}
		.property /* 1700001B */ instance object grdInlet_StrmNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_InletsTemplate::get_grdInlet_StrmNode()
		}

	} // end of class grdFlowsheet_GridData_InletsTemplate

	.class /* 0200000D */ nested public auto ansi beforefieldinit grdFlowsheet_GridData_OutletsTemplate
		extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel
	{
		// Fields
		.field /* 0400002C */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration grdOutlet_StrmNode_Property
		.field /* 0400002D */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration grdOutlet_PortNode_Property

		// Methods
		.method /* 0600005E */ family hidebysig virtual 
			instance void OnSubPropertyDataChanged (
				class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration pd,
				string subPropertyName
			) cil managed 
		{
			// Method begins at RVA 0x36e0
			// Header size: 12
			// Code size: 114 (0x72)
			.maxstack 4
			.locals /* 11000011 */ init (
				[0] class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage
			)

			/* 0x000036E0 03                 */ IL_0000: ldarg.1
			/* 0x000036E1 6FD200000A         */ IL_0001: callvirt instance string [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::get_Name() /* 0A0000D2 */
			/* 0x000036E6 72DE070070         */ IL_0006: ldstr "grdOutlet_StrmNode" /* 700007DE */
			/* 0x000036EB 283C00000A         */ IL_000b: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000036F0 2C57               */ IL_0010: brfalse.s IL_0069
			/* 0x000036F2 04                 */ IL_0012: ldarg.2
			/* 0x000036F3 72FC060070         */ IL_0013: ldstr "Value" /* 700006FC */
			/* 0x000036F8 283C00000A         */ IL_0018: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000036FD 2C4A               */ IL_001d: brfalse.s IL_0069
			/* 0x000036FF 02                 */ IL_001f: ldarg.0
			/* 0x00003700 28D300000A         */ IL_0020: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::get_Parent() /* 0A0000D3 */
			/* 0x00003705 7530000001         */ IL_0025: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel /* 01000030 */
			/* 0x0000370A 25                 */ IL_002a: dup
			/* 0x0000370B 2D04               */ IL_002b: brtrue.s IL_0031
			/* 0x0000370D 26                 */ IL_002d: pop
			/* 0x0000370E 14                 */ IL_002e: ldnull
			/* 0x0000370F 2B05               */ IL_002f: br.s IL_0036
			/* 0x00003711 28D300000A         */ IL_0031: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::get_Parent() /* 0A0000D3 */
			/* 0x00003716 7530000001         */ IL_0036: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel /* 01000030 */
			/* 0x0000371B 25                 */ IL_003b: dup
			/* 0x0000371C 2D04               */ IL_003c: brtrue.s IL_0042
			/* 0x0000371E 26                 */ IL_003e: pop
			/* 0x0000371F 14                 */ IL_003f: ldnull
			/* 0x00003720 2B05               */ IL_0040: br.s IL_0047
			/* 0x00003722 28D400000A         */ IL_0042: call instance object [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::get_View() /* 0A0000D4 */
			/* 0x00003727 7534000001         */ IL_0047: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage /* 01000034 */
			/* 0x0000372C 0A                 */ IL_004c: stloc.0
			/* 0x0000372D 06                 */ IL_004d: ldloc.0
			/* 0x0000372E 2C19               */ IL_004e: brfalse.s IL_0069
			/* 0x00003730 06                 */ IL_0050: ldloc.0
			/* 0x00003731 6FD500000A         */ IL_0051: callvirt instance class [WindowsBase]System.Windows.Threading.Dispatcher [WindowsBase]System.Windows.Threading.DispatcherObject::get_Dispatcher() /* 0A0000D5 */
			/* 0x00003736 1B                 */ IL_0056: ldc.i4.5
			/* 0x00003737 02                 */ IL_0057: ldarg.0
			/* 0x00003738 FE0663000006       */ IL_0058: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::'<OnSubPropertyDataChanged>b__0_0'() /* 06000063 */
			/* 0x0000373E 73D600000A         */ IL_005e: newobj instance void [mscorlib]System.Action::.ctor(object, native int) /* 0A0000D6 */
			/* 0x00003743 6FD700000A         */ IL_0063: callvirt instance class [WindowsBase]System.Windows.Threading.DispatcherOperation [WindowsBase]System.Windows.Threading.Dispatcher::BeginInvoke(valuetype [WindowsBase]System.Windows.Threading.DispatcherPriority, class [mscorlib]System.Delegate) /* 0A0000D7 */
			/* 0x00003748 26                 */ IL_0068: pop
			/* 0x00003749 02                 */ IL_0069: ldarg.0
			/* 0x0000374A 03                 */ IL_006a: ldarg.1
			/* 0x0000374B 04                 */ IL_006b: ldarg.2
			/* 0x0000374C 283B00000A         */ IL_006c: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::OnSubPropertyDataChanged(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration, string) /* 0A00003B */
			/* 0x00003751 2A                 */ IL_0071: ret
		} // end of method grdFlowsheet_GridData_OutletsTemplate::OnSubPropertyDataChanged

		.method /* 0600005F */ public hidebysig specialname 
			instance object get_grdOutlet_StrmNode () cil managed 
		{
			// Method begins at RVA 0x375e
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x0000375E 02                 */ IL_0000: ldarg.0
			/* 0x0000375F 7E2C000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::grdOutlet_StrmNode_Property /* 0400002C */
			/* 0x00003764 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003769 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_OutletsTemplate::get_grdOutlet_StrmNode

		.method /* 06000060 */ public hidebysig specialname 
			instance object get_grdOutlet_PortNode () cil managed 
		{
			// Method begins at RVA 0x376b
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x0000376B 02                 */ IL_0000: ldarg.0
			/* 0x0000376C 7E2D000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::grdOutlet_PortNode_Property /* 0400002D */
			/* 0x00003771 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003776 2A                 */ IL_000b: ret
		} // end of method grdFlowsheet_GridData_OutletsTemplate::get_grdOutlet_PortNode

		.method /* 06000061 */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x321f
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x0000321F 02                 */ IL_0000: ldarg.0
			/* 0x00003220 28C200000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::.ctor() /* 0A0000C2 */
			/* 0x00003225 2A                 */ IL_0006: ret
		} // end of method grdFlowsheet_GridData_OutletsTemplate::.ctor

		.method /* 06000062 */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x3778
			// Header size: 12
			// Code size: 331 (0x14b)
			.maxstack 9

			/* 0x00003778 72DE070070         */ IL_0000: ldstr "grdOutlet_StrmNode" /* 700007DE */
			/* 0x0000377D D00D000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate /* 0200000D */
			/* 0x00003782 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003787 733000000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x0000378C 25                 */ IL_0014: dup
			/* 0x0000378D 7204080070         */ IL_0015: ldstr "@main.Input.OUTSTRM.@y.@x" /* 70000804 */
			/* 0x00003792 6F3100000A         */ IL_001a: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003797 25                 */ IL_001f: dup
			/* 0x00003798 73C400000A         */ IL_0020: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x0000379D 25                 */ IL_0025: dup
			/* 0x0000379E 6FC500000A         */ IL_0026: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x000037A3 73C400000A         */ IL_002b: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000037A8 25                 */ IL_0030: dup
			/* 0x000037A9 72BA050070         */ IL_0031: ldstr "Top.appModelV8.Settings.EnableFlowsheetSectionForm" /* 700005BA */
			/* 0x000037AE 6FC600000A         */ IL_0036: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x000037B3 6FC700000A         */ IL_003b: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x000037B8 25                 */ IL_0040: dup
			/* 0x000037B9 6FC500000A         */ IL_0041: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x000037BE 73C400000A         */ IL_0046: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000037C3 25                 */ IL_004b: dup
			/* 0x000037C4 725E070070         */ IL_004c: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x000037C9 6FC600000A         */ IL_0051: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x000037CE 6FC700000A         */ IL_0056: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x000037D3 25                 */ IL_005b: dup
			/* 0x000037D4 1E                 */ IL_005c: ldc.i4.8
			/* 0x000037D5 6FC800000A         */ IL_005d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_Operator(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalOperator) /* 0A0000C8 */
			/* 0x000037DA 6FC900000A         */ IL_0062: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsEnabledCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000C9 */
			/* 0x000037DF 25                 */ IL_0067: dup
			/* 0x000037E0 73C400000A         */ IL_0068: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x000037E5 25                 */ IL_006d: dup
			/* 0x000037E6 725E070070         */ IL_006e: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x000037EB 6FC600000A         */ IL_0073: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x000037F0 6FD800000A         */ IL_0078: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsVisibleCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000D8 */
			/* 0x000037F5 25                 */ IL_007d: dup
			/* 0x000037F6 16                 */ IL_007e: ldc.i4.0
			/* 0x000037F7 733F00000A         */ IL_007f: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x000037FC 6FD900000A         */ IL_0084: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_AllowNew(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000D9 */
			/* 0x00003801 25                 */ IL_0089: dup
			/* 0x00003802 17                 */ IL_008a: ldc.i4.1
			/* 0x00003803 733F00000A         */ IL_008b: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x00003808 6FDA00000A         */ IL_0090: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_AllowEmptyOptions(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000DA */
			/* 0x0000380D 25                 */ IL_0095: dup
			/* 0x0000380E 14                 */ IL_0096: ldnull
			/* 0x0000380F FE0617000006       */ IL_0097: ldftn bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::ValidateStreamId(object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer) /* 06000017 */
			/* 0x00003815 73CC00000A         */ IL_009d: newobj instance void class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>::.ctor(object, native int) /* 0A0000CC */
			/* 0x0000381A 6FCD00000A         */ IL_00a2: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ValueValidator(class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>) /* 0A0000CD */
			/* 0x0000381F 283200000A         */ IL_00a7: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003824 802C000004         */ IL_00ac: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::grdOutlet_StrmNode_Property /* 0400002C */
			/* 0x00003829 7238080070         */ IL_00b1: ldstr "grdOutlet_PortNode" /* 70000838 */
			/* 0x0000382E D00D000002         */ IL_00b6: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate /* 0200000D */
			/* 0x00003833 282F00000A         */ IL_00bb: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003838 733000000A         */ IL_00c0: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x0000383D 25                 */ IL_00c5: dup
			/* 0x0000383E 725E080070         */ IL_00c6: ldstr "@main.Input.OUTPORT.@y.@x" /* 7000085E */
			/* 0x00003843 6F3100000A         */ IL_00cb: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003848 25                 */ IL_00d0: dup
			/* 0x00003849 73C400000A         */ IL_00d1: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x0000384E 25                 */ IL_00d6: dup
			/* 0x0000384F 6FC500000A         */ IL_00d7: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x00003854 73C400000A         */ IL_00dc: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003859 25                 */ IL_00e1: dup
			/* 0x0000385A 72BA050070         */ IL_00e2: ldstr "Top.appModelV8.Settings.EnableFlowsheetSectionForm" /* 700005BA */
			/* 0x0000385F 6FC600000A         */ IL_00e7: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x00003864 6FC700000A         */ IL_00ec: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x00003869 25                 */ IL_00f1: dup
			/* 0x0000386A 6FC500000A         */ IL_00f2: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTestCollection [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::get_SubConditions() /* 0A0000C5 */
			/* 0x0000386F 73C400000A         */ IL_00f7: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003874 25                 */ IL_00fc: dup
			/* 0x00003875 725E070070         */ IL_00fd: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x0000387A 6FC600000A         */ IL_0102: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x0000387F 6FC700000A         */ IL_0107: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest>::Add(!0) /* 0A0000C7 */
			/* 0x00003884 25                 */ IL_010c: dup
			/* 0x00003885 1E                 */ IL_010d: ldc.i4.8
			/* 0x00003886 6FC800000A         */ IL_010e: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_Operator(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalOperator) /* 0A0000C8 */
			/* 0x0000388B 6FC900000A         */ IL_0113: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsEnabledCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000C9 */
			/* 0x00003890 25                 */ IL_0118: dup
			/* 0x00003891 73C400000A         */ IL_0119: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::.ctor() /* 0A0000C4 */
			/* 0x00003896 25                 */ IL_011e: dup
			/* 0x00003897 725E070070         */ IL_011f: ldstr "@main.CC Nodes.CONNVALID.@y" /* 7000075E */
			/* 0x0000389C 6FC600000A         */ IL_0124: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest::set_DataPath(string) /* 0A0000C6 */
			/* 0x000038A1 6FD800000A         */ IL_0129: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvStatePropertyBase::set_IsVisibleCondition(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvLogicalTest) /* 0A0000D8 */
			/* 0x000038A6 25                 */ IL_012e: dup
			/* 0x000038A7 14                 */ IL_012f: ldnull
			/* 0x000038A8 FE0618000006       */ IL_0130: ldftn bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::ValidatePort(object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer) /* 06000018 */
			/* 0x000038AE 73CC00000A         */ IL_0136: newobj instance void class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>::.ctor(object, native int) /* 0A0000CC */
			/* 0x000038B3 6FCD00000A         */ IL_013b: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ValueValidator(class [mscorlib]System.Func`3<object, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer, bool>) /* 0A0000CD */
			/* 0x000038B8 283200000A         */ IL_0140: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x000038BD 802D000004         */ IL_0145: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::grdOutlet_PortNode_Property /* 0400002D */
			/* 0x000038C2 2A                 */ IL_014a: ret
		} // end of method grdFlowsheet_GridData_OutletsTemplate::.cctor

		.method /* 06000063 */ private hidebysig 
			instance void '<OnSubPropertyDataChanged>b__0_0' () cil managed 
		{
			.custom /* 0C000039 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x38d0
			// Header size: 12
			// Code size: 102 (0x66)
			.maxstack 5
			.locals /* 11000012 */ init (
				[0] string,
				[1] string
			)

			/* 0x000038D0 02                 */ IL_0000: ldarg.0
			/* 0x000038D1 7204080070         */ IL_0001: ldstr "@main.Input.OUTSTRM.@y.@x" /* 70000804 */
			/* 0x000038D6 72C8070070         */ IL_0006: ldstr "value" /* 700007C8 */
			/* 0x000038DB 28DB00000A         */ IL_000b: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPathAndGet(string, string) /* 0A0000DB */
			/* 0x000038E0 289B00000A         */ IL_0010: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
			/* 0x000038E5 0A                 */ IL_0015: stloc.0
			/* 0x000038E6 06                 */ IL_0016: ldloc.0
			/* 0x000038E7 28AE00000A         */ IL_0017: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x000038EC 2D47               */ IL_001c: brtrue.s IL_0065
			/* 0x000038EE 02                 */ IL_001e: ldarg.0
			/* 0x000038EF 725E080070         */ IL_001f: ldstr "@main.Input.OUTPORT.@y.@x" /* 7000085E */
			/* 0x000038F4 72C8070070         */ IL_0024: ldstr "value" /* 700007C8 */
			/* 0x000038F9 28DB00000A         */ IL_0029: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPathAndGet(string, string) /* 0A0000DB */
			/* 0x000038FE 289B00000A         */ IL_002e: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
			/* 0x00003903 0B                 */ IL_0033: stloc.1
			/* 0x00003904 07                 */ IL_0034: ldloc.1
			/* 0x00003905 28AE00000A         */ IL_0035: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x0000390A 2D0D               */ IL_003a: brtrue.s IL_0049
			/* 0x0000390C 07                 */ IL_003c: ldloc.1
			/* 0x0000390D 7242020070         */ IL_003d: ldstr "$(OUT)" /* 70000242 */
			/* 0x00003912 6F6700000A         */ IL_0042: callvirt instance bool [mscorlib]System.String::EndsWith(string) /* 0A000067 */
			/* 0x00003917 2C1C               */ IL_0047: brfalse.s IL_0065
			/* 0x00003919 02                 */ IL_0049: ldarg.0
			/* 0x0000391A 725E080070         */ IL_004a: ldstr "@main.Input.OUTPORT.@y.@x" /* 7000085E */
			/* 0x0000391F 72C8070070         */ IL_004f: ldstr "value" /* 700007C8 */
			/* 0x00003924 06                 */ IL_0054: ldloc.0
			/* 0x00003925 7292080070         */ IL_0055: ldstr "(OUT)" /* 70000892 */
			/* 0x0000392A 28A000000A         */ IL_005a: call string [mscorlib]System.String::Concat(string, string) /* 0A0000A0 */
			/* 0x0000392F 28DC00000A         */ IL_005f: call instance bool [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPathAndSet(string, string, object) /* 0A0000DC */
			/* 0x00003934 26                 */ IL_0064: pop
			/* 0x00003935 2A                 */ IL_0065: ret
		} // end of method grdFlowsheet_GridData_OutletsTemplate::'<OnSubPropertyDataChanged>b__0_0'

		// Properties
		.property /* 1700001C */ instance object grdOutlet_StrmNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::get_grdOutlet_StrmNode()
		}
		.property /* 1700001D */ instance object grdOutlet_PortNode()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_OutletsTemplate::get_grdOutlet_PortNode()
		}

	} // end of class grdFlowsheet_GridData_OutletsTemplate


	// Fields
	.field /* 04000008 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration grdFlowsheet_GridData_Property
	.field /* 04000009 */ private class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> _Reorder_Command

	// Methods
	.method /* 06000010 */ public hidebysig specialname 
		instance object get_grdFlowsheet_GridData () cil managed 
	{
		// Method begins at RVA 0x2265
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00002265 02                 */ IL_0000: ldarg.0
		/* 0x00002266 7E08000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::grdFlowsheet_GridData_Property /* 04000008 */
		/* 0x0000226B 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
		/* 0x00002270 2A                 */ IL_000b: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::get_grdFlowsheet_GridData

	.method /* 06000011 */ family hidebysig virtual 
		instance void OnUpdateData () cil managed 
	{
		// Method begins at RVA 0x2272
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002272 02                 */ IL_0000: ldarg.0
		/* 0x00002273 282B00000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel::OnUpdateData() /* 0A00002B */
		/* 0x00002278 02                 */ IL_0006: ldarg.0
		/* 0x00002279 282C00000A         */ IL_0007: call instance bool [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::get_IsInitialUpdate() /* 0A00002C */
		/* 0x0000227E 2C06               */ IL_000c: brfalse.s IL_0014
		/* 0x00002280 02                 */ IL_000e: ldarg.0
		/* 0x00002281 2813000006         */ IL_000f: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::UpdateInnerItems() /* 06000013 */
		/* 0x00002286 2A                 */ IL_0014: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::OnUpdateData

	.method /* 06000012 */ family hidebysig virtual 
		instance void OnSubPropertyDataChanged (
			class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration pd,
			string subPropertyName
		) cil managed 
	{
		// Method begins at RVA 0x2288
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x00002288 02                 */ IL_0000: ldarg.0
		/* 0x00002289 03                 */ IL_0001: ldarg.1
		/* 0x0000228A 04                 */ IL_0002: ldarg.2
		/* 0x0000228B 283B00000A         */ IL_0003: call instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::OnSubPropertyDataChanged(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration, string) /* 0A00003B */
		/* 0x00002290 03                 */ IL_0008: ldarg.1
		/* 0x00002291 7E08000004         */ IL_0009: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::grdFlowsheet_GridData_Property /* 04000008 */
		/* 0x00002296 3313               */ IL_000e: bne.un.s IL_0023
		/* 0x00002298 04                 */ IL_0010: ldarg.2
		/* 0x00002299 729E010070         */ IL_0011: ldstr "Count" /* 7000019E */
		/* 0x0000229E 283C00000A         */ IL_0016: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
		/* 0x000022A3 2C06               */ IL_001b: brfalse.s IL_0023
		/* 0x000022A5 02                 */ IL_001d: ldarg.0
		/* 0x000022A6 2813000006         */ IL_001e: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::UpdateInnerItems() /* 06000013 */
		/* 0x000022AB 2A                 */ IL_0023: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::OnSubPropertyDataChanged

	.method /* 06000013 */ private hidebysig 
		instance void UpdateInnerItems () cil managed 
	{
		// Method begins at RVA 0x22b0
		// Header size: 12
		// Code size: 107 (0x6b)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData,
			[1] class [mscorlib]System.Collections.IEnumerator,
			[2] class [mscorlib]System.IDisposable
		)

		/* 0x000022B0 02                 */ IL_0000: ldarg.0
		/* 0x000022B1 2810000006         */ IL_0001: call instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::get_grdFlowsheet_GridData() /* 06000010 */
		/* 0x000022B6 7529000001         */ IL_0006: isinst [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData /* 01000029 */
		/* 0x000022BB 0A                 */ IL_000b: stloc.0
		/* 0x000022BC 06                 */ IL_000c: ldloc.0
		/* 0x000022BD 2C5B               */ IL_000d: brfalse.s IL_006a
		/* 0x000022BF 06                 */ IL_000f: ldloc.0
		/* 0x000022C0 6F3D00000A         */ IL_0010: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
		/* 0x000022C5 16                 */ IL_0015: ldc.i4.0
		/* 0x000022C6 311E               */ IL_0016: ble.s IL_0036
		/* 0x000022C8 06                 */ IL_0018: ldloc.0
		/* 0x000022C9 06                 */ IL_0019: ldloc.0
		/* 0x000022CA 6F3D00000A         */ IL_001a: callvirt instance int32 [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Count() /* 0A00003D */
		/* 0x000022CF 17                 */ IL_001f: ldc.i4.1
		/* 0x000022D0 59                 */ IL_0020: sub
		/* 0x000022D1 6F3E00000A         */ IL_0021: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Item(int32) /* 0A00003E */
		/* 0x000022D6 750A000002         */ IL_0026: isinst AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
		/* 0x000022DB 17                 */ IL_002b: ldc.i4.1
		/* 0x000022DC 733F00000A         */ IL_002c: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
		/* 0x000022E1 6F46000006         */ IL_0031: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::set_IsProxy(valuetype [mscorlib]System.Nullable`1<bool>) /* 06000046 */
		/* 0x000022E6 06                 */ IL_0036: ldloc.0
		/* 0x000022E7 6F4000000A         */ IL_0037: callvirt instance class [mscorlib]System.Collections.IEnumerator [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::GetEnumerator() /* 0A000040 */
		/* 0x000022EC 0B                 */ IL_003c: stloc.1
		/* 0x000022ED 2B10               */ IL_003d: br.s IL_004f
		/* 0x000022EF 07                 */ IL_003f: ldloc.1
		/* 0x000022F0 6F1C00000A         */ IL_0040: callvirt instance object [mscorlib]System.Collections.IEnumerator::get_Current() /* 0A00001C */
		/* 0x000022F5 740A000002         */ IL_0045: castclass AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
		/* 0x000022FA 6F4B000006         */ IL_004a: callvirt instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate::UpdateInnerItems() /* 0600004B */
		/* 0x000022FF 07                 */ IL_004f: ldloc.1
		/* 0x00002300 6F1900000A         */ IL_0050: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002305 2DE8               */ IL_0055: brtrue.s IL_003f
		/* 0x00002307 DE11               */ IL_0057: leave.s IL_006a
		/* 0x00002309 07                 */ IL_0059: ldloc.1
		/* 0x0000230A 752B000001         */ IL_005a: isinst [mscorlib]System.IDisposable /* 0100002B */
		/* 0x0000230F 0C                 */ IL_005f: stloc.2
		/* 0x00002310 08                 */ IL_0060: ldloc.2
		/* 0x00002311 2C06               */ IL_0061: brfalse.s IL_0069
		/* 0x00002313 08                 */ IL_0063: ldloc.2
		/* 0x00002314 6F1800000A         */ IL_0064: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000018 */
		/* 0x00002319 DC                 */ IL_0069: endfinally
		/* 0x0000231A 2A                 */ IL_006a: ret

		.try IL_003d-IL_0059 finally IL_0059-IL_006a
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::UpdateInnerItems

	.method /* 06000014 */ public hidebysig specialname 
		instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> get_Reorder_Command () cil managed 
	{
		// Method begins at RVA 0x2338
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x00002338 02                 */ IL_0000: ldarg.0
		/* 0x00002339 7B09000004         */ IL_0001: ldfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::_Reorder_Command /* 04000009 */
		/* 0x0000233E 2D17               */ IL_0006: brtrue.s IL_001f
		/* 0x00002340 02                 */ IL_0008: ldarg.0
		/* 0x00002341 02                 */ IL_0009: ldarg.0
		/* 0x00002342 FE0615000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::Reorder_CommandExecute(class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter) /* 06000015 */
		/* 0x00002348 734100000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter>::.ctor(object, native int) /* 0A000041 */
		/* 0x0000234D 734200000A         */ IL_0015: newobj instance void class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter>::.ctor(class [mscorlib]System.Action`1<!0>) /* 0A000042 */
		/* 0x00002352 7D09000004         */ IL_001a: stfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::_Reorder_Command /* 04000009 */
		/* 0x00002357 02                 */ IL_001f: ldarg.0
		/* 0x00002358 7B09000004         */ IL_0020: ldfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::_Reorder_Command /* 04000009 */
		/* 0x0000235D 2A                 */ IL_0025: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::get_Reorder_Command

	.method /* 06000015 */ private hidebysig 
		instance void Reorder_CommandExecute (
			class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter parameter
		) cil managed 
	{
		// Method begins at RVA 0x2360
		// Header size: 12
		// Code size: 213 (0xd5)
		.maxstack 3
		.locals /* 11000003 */ init (
			[0] class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell,
			[1] class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorder,
			[2] int32
		)

		/* 0x00002360 03                 */ IL_0000: ldarg.1
		/* 0x00002361 16                 */ IL_0001: ldc.i4.0
		/* 0x00002362 6F4300000A         */ IL_0002: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter::set_Handled(bool) /* 0A000043 */
		/* 0x00002367 03                 */ IL_0007: ldarg.1
		/* 0x00002368 6F4400000A         */ IL_0008: callvirt instance class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter::get_ScrollArea() /* 0A000044 */
		/* 0x0000236D 6F4500000A         */ IL_000d: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002372 6F4600000A         */ IL_0012: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase/SelectedItemHolder [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_SelectedItems() /* 0A000046 */
		/* 0x00002377 6F4700000A         */ IL_0017: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.SelectedCellCollection [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase/SelectedItemHolder::get_Cells() /* 0A000047 */
		/* 0x0000237C 6F4800000A         */ IL_001c: callvirt instance int32 [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.SelectedItemCollectionBase::get_Count() /* 0A000048 */
		/* 0x00002381 2D01               */ IL_0021: brtrue.s IL_0024
		/* 0x00002383 2A                 */ IL_0023: ret
		/* 0x00002384 03                 */ IL_0024: ldarg.1
		/* 0x00002385 6F4400000A         */ IL_0025: callvirt instance class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter::get_ScrollArea() /* 0A000044 */
		/* 0x0000238A 6F4500000A         */ IL_002a: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x0000238F 6F4600000A         */ IL_002f: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase/SelectedItemHolder [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_SelectedItems() /* 0A000046 */
		/* 0x00002394 6F4700000A         */ IL_0034: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.SelectedCellCollection [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase/SelectedItemHolder::get_Cells() /* 0A000047 */
		/* 0x00002399 16                 */ IL_0039: ldc.i4.0
		/* 0x0000239A 6F4900000A         */ IL_003a: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.SelectedCellCollection::get_Item(int32) /* 0A000049 */
		/* 0x0000239F 0A                 */ IL_003f: stloc.0
		/* 0x000023A0 06                 */ IL_0040: ldloc.0
		/* 0x000023A1 6F4A00000A         */ IL_0041: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Field [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::get_Field() /* 0A00004A */
		/* 0x000023A6 6F4B00000A         */ IL_0046: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.FieldLayout [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.FieldItem::get_Owner() /* 0A00004B */
		/* 0x000023AB 06                 */ IL_004b: ldloc.0
		/* 0x000023AC 6F4C00000A         */ IL_004c: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataRecord [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::get_Record() /* 0A00004C */
		/* 0x000023B1 6F4D00000A         */ IL_0051: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record::get_DataPresenter() /* 0A00004D */
		/* 0x000023B6 6F4E00000A         */ IL_0056: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.FieldLayout [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_DefaultFieldLayout() /* 0A00004E */
		/* 0x000023BB 3301               */ IL_005b: bne.un.s IL_005e
		/* 0x000023BD 2A                 */ IL_005d: ret
		/* 0x000023BE 03                 */ IL_005e: ldarg.1
		/* 0x000023BF 17                 */ IL_005f: ldc.i4.1
		/* 0x000023C0 6F4300000A         */ IL_0060: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter::set_Handled(bool) /* 0A000043 */
		/* 0x000023C5 734F00000A         */ IL_0065: newobj instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorder::.ctor() /* 0A00004F */
		/* 0x000023CA 25                 */ IL_006a: dup
		/* 0x000023CB 17                 */ IL_006b: ldc.i4.1
		/* 0x000023CC 6F5000000A         */ IL_006c: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorder::set_AllowUseValueInReorder(bool) /* 0A000050 */
		/* 0x000023D1 0B                 */ IL_0071: stloc.1
		/* 0x000023D2 07                 */ IL_0072: ldloc.1
		/* 0x000023D3 02                 */ IL_0073: ldarg.0
		/* 0x000023D4 2810000006         */ IL_0074: call instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::get_grdFlowsheet_GridData() /* 06000010 */
		/* 0x000023D9 7529000001         */ IL_0079: isinst [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData /* 01000029 */
		/* 0x000023DE 06                 */ IL_007e: ldloc.0
		/* 0x000023DF 6F4C00000A         */ IL_007f: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataRecord [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::get_Record() /* 0A00004C */
		/* 0x000023E4 6F5100000A         */ IL_0084: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record::get_UltimateParentRecord() /* 0A000051 */
		/* 0x000023E9 6F5200000A         */ IL_0089: callvirt instance int32 [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record::get_Index() /* 0A000052 */
		/* 0x000023EE 6F3E00000A         */ IL_008e: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVectorPropertyData::get_Item(int32) /* 0A00003E */
		/* 0x000023F3 7530000001         */ IL_0093: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel /* 01000030 */
		/* 0x000023F8 6F5300000A         */ IL_0098: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorder::set_ViewModel(class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel) /* 0A000053 */
		/* 0x000023FD 06                 */ IL_009d: ldloc.0
		/* 0x000023FE 6F4A00000A         */ IL_009e: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Field [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::get_Field() /* 0A00004A */
		/* 0x00002403 6F5400000A         */ IL_00a3: callvirt instance int32 [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Field::get_Index() /* 0A000054 */
		/* 0x00002408 0C                 */ IL_00a8: stloc.2
		/* 0x00002409 08                 */ IL_00a9: ldloc.2
		/* 0x0000240A 17                 */ IL_00aa: ldc.i4.1
		/* 0x0000240B 3608               */ IL_00ab: ble.un.s IL_00b5
		/* 0x0000240D 08                 */ IL_00ad: ldloc.2
		/* 0x0000240E 18                 */ IL_00ae: ldc.i4.2
		/* 0x0000240F 59                 */ IL_00af: sub
		/* 0x00002410 17                 */ IL_00b0: ldc.i4.1
		/* 0x00002411 360F               */ IL_00b1: ble.un.s IL_00c2
		/* 0x00002413 2B18               */ IL_00b3: br.s IL_00cd
		/* 0x00002415 07                 */ IL_00b5: ldloc.1
		/* 0x00002416 72AA010070         */ IL_00b6: ldstr "Inlets" /* 700001AA */
		/* 0x0000241B 6F5500000A         */ IL_00bb: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorder::set_DataProperty(string) /* 0A000055 */
		/* 0x00002420 2B0B               */ IL_00c0: br.s IL_00cd
		/* 0x00002422 07                 */ IL_00c2: ldloc.1
		/* 0x00002423 72B8010070         */ IL_00c3: ldstr "Outlets" /* 700001B8 */
		/* 0x00002428 6F5500000A         */ IL_00c8: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorder::set_DataProperty(string) /* 0A000055 */
		/* 0x0000242D 07                 */ IL_00cd: ldloc.1
		/* 0x0000242E 6F5600000A         */ IL_00ce: callvirt instance valuetype [mscorlib]System.Nullable`1<bool> [PresentationFramework]System.Windows.Window::ShowDialog() /* 0A000056 */
		/* 0x00002433 26                 */ IL_00d3: pop
		/* 0x00002434 2A                 */ IL_00d4: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::Reorder_CommandExecute

	.method /* 06000016 */ private hidebysig static 
		bool ValidateBlockId (
			object id,
			class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer vm
		) cil managed 
	{
		// Method begins at RVA 0x2444
		// Header size: 12
		// Code size: 109 (0x6d)
		.maxstack 4
		.locals /* 11000004 */ init (
			[0] class [mscorlib]System.Collections.ObjectModel.Collection`1<string>
		)

		/* 0x00002444 02                 */ IL_0000: ldarg.0
		/* 0x00002445 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x00002447 17                 */ IL_0003: ldc.i4.1
		/* 0x00002448 2A                 */ IL_0004: ret
		/* 0x00002449 03                 */ IL_0005: ldarg.1
		/* 0x0000244A 6F5700000A         */ IL_0006: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDataProvider [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer::get_ResolvedCxsProvider() /* 0A000057 */
		/* 0x0000244F 72C8010070         */ IL_000b: ldstr "Top.appModelV8.Streams" /* 700001C8 */
		/* 0x00002454 72F6010070         */ IL_0010: ldstr "child_ids" /* 700001F6 */
		/* 0x00002459 14                 */ IL_0015: ldnull
		/* 0x0000245A 6F5800000A         */ IL_0016: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDataProvider::BatchGet(string, string, string) /* 0A000058 */
		/* 0x0000245F 285900000A         */ IL_001b: call class [mscorlib]System.Collections.ObjectModel.Collection`1<string> [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToStringCollection(object) /* 0A000059 */
		/* 0x00002464 0A                 */ IL_0020: stloc.0
		/* 0x00002465 06                 */ IL_0021: ldloc.0
		/* 0x00002466 2D02               */ IL_0022: brtrue.s IL_0026
		/* 0x00002468 17                 */ IL_0024: ldc.i4.1
		/* 0x00002469 2A                 */ IL_0025: ret
		/* 0x0000246A 06                 */ IL_0026: ldloc.0
		/* 0x0000246B 02                 */ IL_0027: ldarg.0
		/* 0x0000246C 6F5A00000A         */ IL_0028: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00005A */
		/* 0x00002471 6F5B00000A         */ IL_002d: callvirt instance string [mscorlib]System.String::ToUpper() /* 0A00005B */
		/* 0x00002476 6F5C00000A         */ IL_0032: callvirt instance bool class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Contains(!0) /* 0A00005C */
		/* 0x0000247B 2C32               */ IL_0037: brfalse.s IL_006b
		/* 0x0000247D 03                 */ IL_0039: ldarg.1
		/* 0x0000247E 735D00000A         */ IL_003a: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::.ctor() /* 0A00005D */
		/* 0x00002483 25                 */ IL_003f: dup
		/* 0x00002484 285E00000A         */ IL_0040: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.Properties.Resources::get_MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Message1() /* 0A00005E */
		/* 0x00002489 6F5F00000A         */ IL_0045: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_Message(string) /* 0A00005F */
		/* 0x0000248E 25                 */ IL_004a: dup
		/* 0x0000248F 286000000A         */ IL_004b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.Properties.Resources::get_MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Title_AddBlock() /* 0A000060 */
		/* 0x00002494 6F6100000A         */ IL_0050: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_Title(string) /* 0A000061 */
		/* 0x00002499 25                 */ IL_0055: dup
		/* 0x0000249A 16                 */ IL_0056: ldc.i4.0
		/* 0x0000249B 6F6200000A         */ IL_0057: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_MsgBoxButton(valuetype [PresentationFramework]System.Windows.MessageBoxButton) /* 0A000062 */
		/* 0x000024A0 25                 */ IL_005c: dup
		/* 0x000024A1 1F30               */ IL_005d: ldc.i4.s 48
		/* 0x000024A3 6F6300000A         */ IL_005f: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_MsgBoxImage(valuetype [PresentationFramework]System.Windows.MessageBoxImage) /* 0A000063 */
		/* 0x000024A8 6F6400000A         */ IL_0064: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer::ShowMessageBox(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs) /* 0A000064 */
		/* 0x000024AD 16                 */ IL_0069: ldc.i4.0
		/* 0x000024AE 2A                 */ IL_006a: ret
		/* 0x000024AF 17                 */ IL_006b: ldc.i4.1
		/* 0x000024B0 2A                 */ IL_006c: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::ValidateBlockId

	.method /* 06000017 */ private hidebysig static 
		bool ValidateStreamId (
			object id,
			class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer vm
		) cil managed 
	{
		// Method begins at RVA 0x24c0
		// Header size: 12
		// Code size: 109 (0x6d)
		.maxstack 4
		.locals /* 11000004 */ init (
			[0] class [mscorlib]System.Collections.ObjectModel.Collection`1<string>
		)

		/* 0x000024C0 02                 */ IL_0000: ldarg.0
		/* 0x000024C1 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x000024C3 17                 */ IL_0003: ldc.i4.1
		/* 0x000024C4 2A                 */ IL_0004: ret
		/* 0x000024C5 03                 */ IL_0005: ldarg.1
		/* 0x000024C6 6F5700000A         */ IL_0006: callvirt instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDataProvider [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer::get_ResolvedCxsProvider() /* 0A000057 */
		/* 0x000024CB 720A020070         */ IL_000b: ldstr "Top.appModelV8.Blocks" /* 7000020A */
		/* 0x000024D0 72F6010070         */ IL_0010: ldstr "child_ids" /* 700001F6 */
		/* 0x000024D5 14                 */ IL_0015: ldnull
		/* 0x000024D6 6F5800000A         */ IL_0016: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDataProvider::BatchGet(string, string, string) /* 0A000058 */
		/* 0x000024DB 285900000A         */ IL_001b: call class [mscorlib]System.Collections.ObjectModel.Collection`1<string> [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToStringCollection(object) /* 0A000059 */
		/* 0x000024E0 0A                 */ IL_0020: stloc.0
		/* 0x000024E1 06                 */ IL_0021: ldloc.0
		/* 0x000024E2 2D02               */ IL_0022: brtrue.s IL_0026
		/* 0x000024E4 17                 */ IL_0024: ldc.i4.1
		/* 0x000024E5 2A                 */ IL_0025: ret
		/* 0x000024E6 06                 */ IL_0026: ldloc.0
		/* 0x000024E7 02                 */ IL_0027: ldarg.0
		/* 0x000024E8 6F5A00000A         */ IL_0028: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00005A */
		/* 0x000024ED 6F5B00000A         */ IL_002d: callvirt instance string [mscorlib]System.String::ToUpper() /* 0A00005B */
		/* 0x000024F2 6F5C00000A         */ IL_0032: callvirt instance bool class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Contains(!0) /* 0A00005C */
		/* 0x000024F7 2C32               */ IL_0037: brfalse.s IL_006b
		/* 0x000024F9 03                 */ IL_0039: ldarg.1
		/* 0x000024FA 735D00000A         */ IL_003a: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::.ctor() /* 0A00005D */
		/* 0x000024FF 25                 */ IL_003f: dup
		/* 0x00002500 286500000A         */ IL_0040: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.Properties.Resources::get_MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Message2() /* 0A000065 */
		/* 0x00002505 6F5F00000A         */ IL_0045: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_Message(string) /* 0A00005F */
		/* 0x0000250A 25                 */ IL_004a: dup
		/* 0x0000250B 286600000A         */ IL_004b: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.Properties.Resources::get_MMFlowsh_Input_Flowsh_ViewModel__MSGBox_Title_AddStream() /* 0A000066 */
		/* 0x00002510 6F6100000A         */ IL_0050: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_Title(string) /* 0A000061 */
		/* 0x00002515 25                 */ IL_0055: dup
		/* 0x00002516 16                 */ IL_0056: ldc.i4.0
		/* 0x00002517 6F6200000A         */ IL_0057: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_MsgBoxButton(valuetype [PresentationFramework]System.Windows.MessageBoxButton) /* 0A000062 */
		/* 0x0000251C 25                 */ IL_005c: dup
		/* 0x0000251D 1F30               */ IL_005d: ldc.i4.s 48
		/* 0x0000251F 6F6300000A         */ IL_005f: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs::set_MsgBoxImage(valuetype [PresentationFramework]System.Windows.MessageBoxImage) /* 0A000063 */
		/* 0x00002524 6F6400000A         */ IL_0064: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer::ShowMessageBox(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CompositeEvents.ShowMessageBoxEventArgs) /* 0A000064 */
		/* 0x00002529 16                 */ IL_0069: ldc.i4.0
		/* 0x0000252A 2A                 */ IL_006a: ret
		/* 0x0000252B 17                 */ IL_006b: ldc.i4.1
		/* 0x0000252C 2A                 */ IL_006c: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::ValidateStreamId

	.method /* 06000018 */ private hidebysig static 
		bool ValidatePort (
			object id,
			class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ICxvViewDataContainer vm
		) cil managed 
	{
		// Method begins at RVA 0x253c
		// Header size: 12
		// Code size: 45 (0x2d)
		.maxstack 2
		.locals /* 11000005 */ init (
			[0] string
		)

		/* 0x0000253C 02                 */ IL_0000: ldarg.0
		/* 0x0000253D 2D02               */ IL_0001: brtrue.s IL_0005
		/* 0x0000253F 17                 */ IL_0003: ldc.i4.1
		/* 0x00002540 2A                 */ IL_0004: ret
		/* 0x00002541 02                 */ IL_0005: ldarg.0
		/* 0x00002542 7559000001         */ IL_0006: isinst [mscorlib]System.String /* 01000059 */
		/* 0x00002547 0A                 */ IL_000b: stloc.0
		/* 0x00002548 06                 */ IL_000c: ldloc.0
		/* 0x00002549 2C1C               */ IL_000d: brfalse.s IL_002b
		/* 0x0000254B 06                 */ IL_000f: ldloc.0
		/* 0x0000254C 7236020070         */ IL_0010: ldstr "$(IN)" /* 70000236 */
		/* 0x00002551 6F6700000A         */ IL_0015: callvirt instance bool [mscorlib]System.String::EndsWith(string) /* 0A000067 */
		/* 0x00002556 2D0F               */ IL_001a: brtrue.s IL_002b
		/* 0x00002558 06                 */ IL_001c: ldloc.0
		/* 0x00002559 7242020070         */ IL_001d: ldstr "$(OUT)" /* 70000242 */
		/* 0x0000255E 6F6700000A         */ IL_0022: callvirt instance bool [mscorlib]System.String::EndsWith(string) /* 0A000067 */
		/* 0x00002563 16                 */ IL_0027: ldc.i4.0
		/* 0x00002564 FE01               */ IL_0028: ceq
		/* 0x00002566 2A                 */ IL_002a: ret
		/* 0x00002567 16                 */ IL_002b: ldc.i4.0
		/* 0x00002568 2A                 */ IL_002c: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::ValidatePort

	.method /* 06000019 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x211d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000211D 02                 */ IL_0000: ldarg.0
		/* 0x0000211E 282E00000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel::.ctor() /* 0A00002E */
		/* 0x00002123 2A                 */ IL_0006: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::.ctor

	.method /* 0600001A */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2578
		// Header size: 12
		// Code size: 99 (0x63)
		.maxstack 7

		/* 0x00002578 7250020070         */ IL_0000: ldstr "grdFlowsheet_GridData" /* 70000250 */
		/* 0x0000257D D005000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel /* 02000005 */
		/* 0x00002582 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002587 736800000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::.ctor() /* 0A000068 */
		/* 0x0000258C 25                 */ IL_0014: dup
		/* 0x0000258D D00A000002         */ IL_0015: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel/grdFlowsheet_GridData_ItemTemplate /* 0200000A */
		/* 0x00002592 282F00000A         */ IL_001a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002597 6F6900000A         */ IL_001f: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_ItemType(class [mscorlib]System.Type) /* 0A000069 */
		/* 0x0000259C 25                 */ IL_0024: dup
		/* 0x0000259D 736A00000A         */ IL_0025: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::.ctor() /* 0A00006A */
		/* 0x000025A2 25                 */ IL_002a: dup
		/* 0x000025A3 727C020070         */ IL_002b: ldstr "@main.Input.BLKTYPE" /* 7000027C */
		/* 0x000025A8 6F6B00000A         */ IL_0030: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_DataPath(string) /* 0A00006B */
		/* 0x000025AD 25                 */ IL_0035: dup
		/* 0x000025AE 17                 */ IL_0036: ldc.i4.1
		/* 0x000025AF 6F6C00000A         */ IL_0037: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_UseChildId(bool) /* 0A00006C */
		/* 0x000025B4 25                 */ IL_003c: dup
		/* 0x000025B5 72A4020070         */ IL_003d: ldstr "y" /* 700002A4 */
		/* 0x000025BA 6F6D00000A         */ IL_0042: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase::set_Name(string) /* 0A00006D */
		/* 0x000025BF 6F6E00000A         */ IL_0047: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_IndexBasis(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase) /* 0A00006E */
		/* 0x000025C4 25                 */ IL_004c: dup
		/* 0x000025C5 16                 */ IL_004d: ldc.i4.0
		/* 0x000025C6 733F00000A         */ IL_004e: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
		/* 0x000025CB 6F6F00000A         */ IL_0053: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_AllowCollectionChange(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A00006F */
		/* 0x000025D0 283200000A         */ IL_0058: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
		/* 0x000025D5 8008000004         */ IL_005d: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::grdFlowsheet_GridData_Property /* 04000008 */
		/* 0x000025DA 2A                 */ IL_0062: ret
	} // end of method MMFlowsh_Input_Flowsh_ViewModel::.cctor

	// Properties
	.property /* 17000004 */ instance object grdFlowsheet_GridData()
	{
		.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::get_grdFlowsheet_GridData()
	}
	.property /* 17000005 */ instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> Reorder_Command()
	{
		.get instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaReorderParameter> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel::get_Reorder_Command()
	}

} // end of class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel

.class /* 02000006 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	.custom /* 0C000015 */ instance void [mscorlib]System.Runtime.InteropServices.ProgIdAttribute::.ctor(string) = (
		01 00 22 4d 4d 46 6c 6f 77 73 68 46 6f 72 6d 2e
		4d 4d 46 6c 6f 77 73 68 5f 49 6e 70 75 74 5f 46
		6c 6f 77 73 68 00 00
	)
	// Fields
	.field /* 0400000A */ private valuetype [mscorlib]System.Nullable`1<int32> _recordToBeExpandedIndex
	.field /* 0400000B */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea grdFlowsheet
	.field /* 0400000C */ assembly class [PresentationFramework]System.Windows.Controls.Button btnExpandAll
	.field /* 0400000D */ assembly class [PresentationFramework]System.Windows.Controls.Button btnCollapseAll
	.field /* 0400000E */ private bool _contentLoaded

	// Methods
	.method /* 0600001B */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x25e7
		// Header size: 1
		// Code size: 52 (0x34)
		.maxstack 8

		/* 0x000025E7 02                 */ IL_0000: ldarg.0
		/* 0x000025E8 287000000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage::.ctor() /* 0A000070 */
		/* 0x000025ED 02                 */ IL_0006: ldarg.0
		/* 0x000025EE D005000002         */ IL_0007: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh_ViewModel /* 02000005 */
		/* 0x000025F3 282F00000A         */ IL_000c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x000025F8 283800000A         */ IL_0011: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModelContainer::set_ViewModelType(class [mscorlib]System.Type) /* 0A000038 */
		/* 0x000025FD 02                 */ IL_0016: ldarg.0
		/* 0x000025FE 2823000006         */ IL_0017: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::InitializeComponent() /* 06000023 */
		/* 0x00002603 02                 */ IL_001c: ldarg.0
		/* 0x00002604 7B0B000004         */ IL_001d: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x00002609 02                 */ IL_0022: ldarg.0
		/* 0x0000260A FE061C000006       */ IL_0023: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600001C */
		/* 0x00002610 737100000A         */ IL_0029: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000071 */
		/* 0x00002615 6F7200000A         */ IL_002e: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000072 */
		/* 0x0000261A 2A                 */ IL_0033: ret
	} // end of method MMFlowsh_Input_Flowsh::.ctor

	.method /* 0600001C */ private hidebysig 
		instance void grdFlowsheet_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x261c
		// Header size: 12
		// Code size: 104 (0x68)
		.maxstack 4

		/* 0x0000261C 02                 */ IL_0000: ldarg.0
		/* 0x0000261D 7B0B000004         */ IL_0001: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x00002622 6F4500000A         */ IL_0006: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002627 2C5A               */ IL_000b: brfalse.s IL_0067
		/* 0x00002629 02                 */ IL_000d: ldarg.0
		/* 0x0000262A 7B0B000004         */ IL_000e: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x0000262F 6F4500000A         */ IL_0013: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002634 02                 */ IL_0018: ldarg.0
		/* 0x00002635 FE061F000006       */ IL_0019: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::DataGrid_CustomFilterSelectionControlOpening(object, class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs) /* 0600001F */
		/* 0x0000263B 737300000A         */ IL_001f: newobj instance void class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs>::.ctor(object, native int) /* 0A000073 */
		/* 0x00002640 6F7400000A         */ IL_0024: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::add_CustomFilterSelectionControlOpening(class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs>) /* 0A000074 */
		/* 0x00002645 02                 */ IL_0029: ldarg.0
		/* 0x00002646 7B0B000004         */ IL_002a: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x0000264B 6F4500000A         */ IL_002f: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002650 02                 */ IL_0034: ldarg.0
		/* 0x00002651 FE061E000006       */ IL_0035: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::DataGrid_EditModeEnded(object, class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs) /* 0600001E */
		/* 0x00002657 737500000A         */ IL_003b: newobj instance void class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs>::.ctor(object, native int) /* 0A000075 */
		/* 0x0000265C 6F7600000A         */ IL_0040: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::add_EditModeEnded(class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs>) /* 0A000076 */
		/* 0x00002661 02                 */ IL_0045: ldarg.0
		/* 0x00002662 7B0B000004         */ IL_0046: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x00002667 6F4500000A         */ IL_004b: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x0000266C 7E7700000A         */ IL_0050: ldsfld class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.UIElement::MouseLeftButtonUpEvent /* 0A000077 */
		/* 0x00002671 02                 */ IL_0055: ldarg.0
		/* 0x00002672 FE061D000006       */ IL_0056: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::DataGrid_MouseLeftButtonUp(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600001D */
		/* 0x00002678 737100000A         */ IL_005c: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000071 */
		/* 0x0000267D 17                 */ IL_0061: ldc.i4.1
		/* 0x0000267E 6F7800000A         */ IL_0062: callvirt instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate, bool) /* 0A000078 */
		/* 0x00002683 2A                 */ IL_0067: ret
	} // end of method MMFlowsh_Input_Flowsh::grdFlowsheet_Loaded

	.method /* 0600001D */ private hidebysig 
		instance void DataGrid_MouseLeftButtonUp (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2690
		// Header size: 12
		// Code size: 112 (0x70)
		.maxstack 3
		.locals /* 11000006 */ init (
			[0] class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell
		)

		/* 0x00002690 02                 */ IL_0000: ldarg.0
		/* 0x00002691 7C0A000004         */ IL_0001: ldflda valuetype [mscorlib]System.Nullable`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_recordToBeExpandedIndex /* 0400000A */
		/* 0x00002696 FE150900001B       */ IL_0006: initobj valuetype [mscorlib]System.Nullable`1<int32> /* 1B000009 */
		/* 0x0000269C 04                 */ IL_000c: ldarg.2
		/* 0x0000269D 6F7900000A         */ IL_000d: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000079 */
		/* 0x000026A2 7575000001         */ IL_0012: isinst [InfragisticsWPF]Infragistics.Windows.Controls.ExpansionIndicator /* 01000075 */
		/* 0x000026A7 2D1D               */ IL_0017: brtrue.s IL_0036
		/* 0x000026A9 04                 */ IL_0019: ldarg.2
		/* 0x000026AA 6F7900000A         */ IL_001a: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000079 */
		/* 0x000026AF 7576000001         */ IL_001f: isinst [WindowsBase]System.Windows.DependencyObject /* 01000076 */
		/* 0x000026B4 D075000001         */ IL_0024: ldtoken [InfragisticsWPF]Infragistics.Windows.Controls.ExpansionIndicator /* 01000075 */
		/* 0x000026B9 282F00000A         */ IL_0029: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x000026BE 17                 */ IL_002e: ldc.i4.1
		/* 0x000026BF 287A00000A         */ IL_002f: call class [WindowsBase]System.Windows.DependencyObject [InfragisticsWPF]Infragistics.Windows.Utilities::GetAncestorFromType(class [WindowsBase]System.Windows.DependencyObject, class [mscorlib]System.Type, bool) /* 0A00007A */
		/* 0x000026C4 2C39               */ IL_0034: brfalse.s IL_006f
		/* 0x000026C6 02                 */ IL_0036: ldarg.0
		/* 0x000026C7 7B0B000004         */ IL_0037: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x000026CC 6F4500000A         */ IL_003c: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x000026D1 6F7B00000A         */ IL_0041: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_ActiveCell() /* 0A00007B */
		/* 0x000026D6 0A                 */ IL_0046: stloc.0
		/* 0x000026D7 06                 */ IL_0047: ldloc.0
		/* 0x000026D8 2C25               */ IL_0048: brfalse.s IL_006f
		/* 0x000026DA 06                 */ IL_004a: ldloc.0
		/* 0x000026DB 6F7C00000A         */ IL_004b: callvirt instance bool [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::get_IsInEditMode() /* 0A00007C */
		/* 0x000026E0 2C1D               */ IL_0050: brfalse.s IL_006f
		/* 0x000026E2 02                 */ IL_0052: ldarg.0
		/* 0x000026E3 06                 */ IL_0053: ldloc.0
		/* 0x000026E4 6F4C00000A         */ IL_0054: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataRecord [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::get_Record() /* 0A00004C */
		/* 0x000026E9 6F5200000A         */ IL_0059: callvirt instance int32 [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record::get_Index() /* 0A000052 */
		/* 0x000026EE 737D00000A         */ IL_005e: newobj instance void valuetype [mscorlib]System.Nullable`1<int32>::.ctor(!0) /* 0A00007D */
		/* 0x000026F3 7D0A000004         */ IL_0063: stfld valuetype [mscorlib]System.Nullable`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_recordToBeExpandedIndex /* 0400000A */
		/* 0x000026F8 06                 */ IL_0068: ldloc.0
		/* 0x000026F9 6F7E00000A         */ IL_0069: callvirt instance bool [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Cell::EndEditMode() /* 0A00007E */
		/* 0x000026FE 26                 */ IL_006e: pop
		/* 0x000026FF 2A                 */ IL_006f: ret
	} // end of method MMFlowsh_Input_Flowsh::DataGrid_MouseLeftButtonUp

	.method /* 0600001E */ private hidebysig 
		instance void DataGrid_EditModeEnded (
			object sender,
			class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x270c
		// Header size: 12
		// Code size: 98 (0x62)
		.maxstack 2

		/* 0x0000270C 02                 */ IL_0000: ldarg.0
		/* 0x0000270D 7C0A000004         */ IL_0001: ldflda valuetype [mscorlib]System.Nullable`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_recordToBeExpandedIndex /* 0400000A */
		/* 0x00002712 287F00000A         */ IL_0006: call instance bool valuetype [mscorlib]System.Nullable`1<int32>::get_HasValue() /* 0A00007F */
		/* 0x00002717 2C54               */ IL_000b: brfalse.s IL_0061
		/* 0x00002719 02                 */ IL_000d: ldarg.0
		/* 0x0000271A 7B0B000004         */ IL_000e: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x0000271F 6F4500000A         */ IL_0013: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002724 6F8000000A         */ IL_0018: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_Records() /* 0A000080 */
		/* 0x00002729 6F8100000A         */ IL_001d: callvirt instance int32 [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase::get_Count() /* 0A000081 */
		/* 0x0000272E 02                 */ IL_0022: ldarg.0
		/* 0x0000272F 7C0A000004         */ IL_0023: ldflda valuetype [mscorlib]System.Nullable`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_recordToBeExpandedIndex /* 0400000A */
		/* 0x00002734 288200000A         */ IL_0028: call instance !0 valuetype [mscorlib]System.Nullable`1<int32>::get_Value() /* 0A000082 */
		/* 0x00002739 3132               */ IL_002d: ble.s IL_0061
		/* 0x0000273B 02                 */ IL_002f: ldarg.0
		/* 0x0000273C 7B0B000004         */ IL_0030: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x00002741 6F4500000A         */ IL_0035: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002746 6F8000000A         */ IL_003a: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_Records() /* 0A000080 */
		/* 0x0000274B 02                 */ IL_003f: ldarg.0
		/* 0x0000274C 7C0A000004         */ IL_0040: ldflda valuetype [mscorlib]System.Nullable`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_recordToBeExpandedIndex /* 0400000A */
		/* 0x00002751 288200000A         */ IL_0045: call instance !0 valuetype [mscorlib]System.Nullable`1<int32>::get_Value() /* 0A000082 */
		/* 0x00002756 6F8300000A         */ IL_004a: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase::get_Item(int32) /* 0A000083 */
		/* 0x0000275B 17                 */ IL_004f: ldc.i4.1
		/* 0x0000275C 6F8400000A         */ IL_0050: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Record::set_IsExpanded(bool) /* 0A000084 */
		/* 0x00002761 02                 */ IL_0055: ldarg.0
		/* 0x00002762 7C0A000004         */ IL_0056: ldflda valuetype [mscorlib]System.Nullable`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_recordToBeExpandedIndex /* 0400000A */
		/* 0x00002767 FE150900001B       */ IL_005b: initobj valuetype [mscorlib]System.Nullable`1<int32> /* 1B000009 */
		/* 0x0000276D 2A                 */ IL_0061: ret
	} // end of method MMFlowsh_Input_Flowsh::DataGrid_EditModeEnded

	.method /* 0600001F */ private hidebysig 
		instance void DataGrid_CustomFilterSelectionControlOpening (
			object sender,
			class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x277c
		// Header size: 12
		// Code size: 55 (0x37)
		.maxstack 2
		.locals /* 11000007 */ init (
			[0] class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.LabelHeader,
			[1] string
		)

		/* 0x0000277C 04                 */ IL_0000: ldarg.2
		/* 0x0000277D 6F8500000A         */ IL_0001: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordFilter [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs::get_RecordFilter() /* 0A000085 */
		/* 0x00002782 6F8600000A         */ IL_0006: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Field [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordFilter::get_Field() /* 0A000086 */
		/* 0x00002787 6F8700000A         */ IL_000b: callvirt instance object [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.FieldItem::get_Label() /* 0A000087 */
		/* 0x0000278C 753A000001         */ IL_0010: isinst [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.LabelHeader /* 0100003A */
		/* 0x00002791 0A                 */ IL_0015: stloc.0
		/* 0x00002792 06                 */ IL_0016: ldloc.0
		/* 0x00002793 2C1D               */ IL_0017: brfalse.s IL_0036
		/* 0x00002795 288800000A         */ IL_0019: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.ApwnResources::get_ForField() /* 0A000088 */
		/* 0x0000279A 06                 */ IL_001e: ldloc.0
		/* 0x0000279B 6F8900000A         */ IL_001f: callvirt instance string [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.LabelHeader::get_LabelText() /* 0A000089 */
		/* 0x000027A0 288A00000A         */ IL_0024: call string [mscorlib]System.String::Format(string, object) /* 0A00008A */
		/* 0x000027A5 0B                 */ IL_0029: stloc.1
		/* 0x000027A6 04                 */ IL_002a: ldarg.2
		/* 0x000027A7 6F8B00000A         */ IL_002b: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.CustomFilterSelectionControl [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs::get_Control() /* 0A00008B */
		/* 0x000027AC 07                 */ IL_0030: ldloc.1
		/* 0x000027AD 6F8C00000A         */ IL_0031: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.CustomFilterSelectionControl::set_FieldDescription(string) /* 0A00008C */
		/* 0x000027B2 2A                 */ IL_0036: ret
	} // end of method MMFlowsh_Input_Flowsh::DataGrid_CustomFilterSelectionControlOpening

	.method /* 06000020 */ private hidebysig 
		instance void btnExpandAll_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x27bf
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x000027BF 02                 */ IL_0000: ldarg.0
		/* 0x000027C0 7B0B000004         */ IL_0001: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x000027C5 6F4500000A         */ IL_0006: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x000027CA 6F8000000A         */ IL_000b: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_Records() /* 0A000080 */
		/* 0x000027CF 16                 */ IL_0010: ldc.i4.0
		/* 0x000027D0 6F8D00000A         */ IL_0011: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase::ExpandAll(bool) /* 0A00008D */
		/* 0x000027D5 2A                 */ IL_0016: ret
	} // end of method MMFlowsh_Input_Flowsh::btnExpandAll_Click

	.method /* 06000021 */ private hidebysig 
		instance void btnCollapseAll_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x27d7
		// Header size: 1
		// Code size: 23 (0x17)
		.maxstack 8

		/* 0x000027D7 02                 */ IL_0000: ldarg.0
		/* 0x000027D8 7B0B000004         */ IL_0001: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x000027DD 6F4500000A         */ IL_0006: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x000027E2 6F8000000A         */ IL_000b: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::get_Records() /* 0A000080 */
		/* 0x000027E7 16                 */ IL_0010: ldc.i4.0
		/* 0x000027E8 6F8E00000A         */ IL_0011: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.RecordCollectionBase::CollapseAll(bool) /* 0A00008E */
		/* 0x000027ED 2A                 */ IL_0016: ret
	} // end of method MMFlowsh_Input_Flowsh::btnCollapseAll_Click

	.method /* 06000022 */ public hidebysig virtual 
		instance bool OnClosing () cil managed 
	{
		// Method begins at RVA 0x27f0
		// Header size: 12
		// Code size: 109 (0x6d)
		.maxstack 4

		/* 0x000027F0 02                 */ IL_0000: ldarg.0
		/* 0x000027F1 7B0B000004         */ IL_0001: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x000027F6 6F4500000A         */ IL_0006: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x000027FB 2C59               */ IL_000b: brfalse.s IL_0066
		/* 0x000027FD 02                 */ IL_000d: ldarg.0
		/* 0x000027FE 7B0B000004         */ IL_000e: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x00002803 6F4500000A         */ IL_0013: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002808 02                 */ IL_0018: ldarg.0
		/* 0x00002809 FE061F000006       */ IL_0019: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::DataGrid_CustomFilterSelectionControlOpening(object, class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs) /* 0600001F */
		/* 0x0000280F 737300000A         */ IL_001f: newobj instance void class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs>::.ctor(object, native int) /* 0A000073 */
		/* 0x00002814 6F8F00000A         */ IL_0024: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::remove_CustomFilterSelectionControlOpening(class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.CustomFilterSelectionControlOpeningEventArgs>) /* 0A00008F */
		/* 0x00002819 02                 */ IL_0029: ldarg.0
		/* 0x0000281A 7B0B000004         */ IL_002a: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x0000281F 6F4500000A         */ IL_002f: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002824 02                 */ IL_0034: ldarg.0
		/* 0x00002825 FE061E000006       */ IL_0035: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::DataGrid_EditModeEnded(object, class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs) /* 0600001E */
		/* 0x0000282B 737500000A         */ IL_003b: newobj instance void class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs>::.ctor(object, native int) /* 0A000075 */
		/* 0x00002830 6F9000000A         */ IL_0040: callvirt instance void [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.DataPresenterBase::remove_EditModeEnded(class [mscorlib]System.EventHandler`1<class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.Events.EditModeEndedEventArgs>) /* 0A000090 */
		/* 0x00002835 02                 */ IL_0045: ldarg.0
		/* 0x00002836 7B0B000004         */ IL_0046: ldfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x0000283B 6F4500000A         */ IL_004b: callvirt instance class [InfragisticsWPF.DataPresenter]Infragistics.Windows.DataPresenter.XamDataGrid [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaBase::get_DataGrid() /* 0A000045 */
		/* 0x00002840 7E7700000A         */ IL_0050: ldsfld class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.UIElement::MouseLeftButtonUpEvent /* 0A000077 */
		/* 0x00002845 02                 */ IL_0055: ldarg.0
		/* 0x00002846 FE061D000006       */ IL_0056: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::DataGrid_MouseLeftButtonUp(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600001D */
		/* 0x0000284C 737100000A         */ IL_005c: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000071 */
		/* 0x00002851 6F9100000A         */ IL_0061: callvirt instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000091 */
		/* 0x00002856 02                 */ IL_0066: ldarg.0
		/* 0x00002857 289200000A         */ IL_0067: call instance bool [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage::OnClosing() /* 0A000092 */
		/* 0x0000285C 2A                 */ IL_006c: ret
	} // end of method MMFlowsh_Input_Flowsh::OnClosing

	.method /* 06000023 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000021 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000022 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x286c
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] class [System]System.Uri
		)

		/* 0x0000286C 02                 */ IL_0000: ldarg.0
		/* 0x0000286D 7B0E000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_contentLoaded /* 0400000E */
		/* 0x00002872 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00002874 2A                 */ IL_0008: ret
		/* 0x00002875 02                 */ IL_0009: ldarg.0
		/* 0x00002876 17                 */ IL_000a: ldc.i4.1
		/* 0x00002877 7D0E000004         */ IL_000b: stfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_contentLoaded /* 0400000E */
		/* 0x0000287C 72A8020070         */ IL_0010: ldstr "/AspenTech.AspenPlus.MMForms.Flowsheet;component/mmflowsh_input_flowsh.xaml" /* 700002A8 */
		/* 0x00002881 18                 */ IL_0015: ldc.i4.2
		/* 0x00002882 733900000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A000039 */
		/* 0x00002887 0A                 */ IL_001b: stloc.0
		/* 0x00002888 02                 */ IL_001c: ldarg.0
		/* 0x00002889 06                 */ IL_001d: ldloc.0
		/* 0x0000288A 283A00000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A00003A */
		/* 0x0000288F 2A                 */ IL_0023: ret
	} // end of method MMFlowsh_Input_Flowsh::InitializeComponent

	.method /* 06000024 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000023 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000024 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C000025 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x289c
		// Header size: 12
		// Code size: 115 (0x73)
		.maxstack 3

		/* 0x0000289C 03                 */ IL_0000: ldarg.1
		/* 0x0000289D 17                 */ IL_0001: ldc.i4.1
		/* 0x0000289E 59                 */ IL_0002: sub
		/* 0x0000289F 4503000000         */ IL_0003: switch (
		/*              02000000         */                  IL_0016,
		/*              0F000000         */                  IL_0023,
		/*              33000000         */                  IL_0047)
		/* 0x000028B0 2B55               */ IL_0014: br.s IL_006b
		/* 0x000028B2 02                 */ IL_0016: ldarg.0
		/* 0x000028B3 04                 */ IL_0017: ldarg.2
		/* 0x000028B4 7435000001         */ IL_0018: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea /* 01000035 */
		/* 0x000028B9 7D0B000004         */ IL_001d: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollArea AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::grdFlowsheet /* 0400000B */
		/* 0x000028BE 2A                 */ IL_0022: ret
		/* 0x000028BF 02                 */ IL_0023: ldarg.0
		/* 0x000028C0 04                 */ IL_0024: ldarg.2
		/* 0x000028C1 7436000001         */ IL_0025: castclass [PresentationFramework]System.Windows.Controls.Button /* 01000036 */
		/* 0x000028C6 7D0C000004         */ IL_002a: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::btnExpandAll /* 0400000C */
		/* 0x000028CB 02                 */ IL_002f: ldarg.0
		/* 0x000028CC 7B0C000004         */ IL_0030: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::btnExpandAll /* 0400000C */
		/* 0x000028D1 02                 */ IL_0035: ldarg.0
		/* 0x000028D2 FE0620000006       */ IL_0036: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::btnExpandAll_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 06000020 */
		/* 0x000028D8 737100000A         */ IL_003c: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000071 */
		/* 0x000028DD 6F9300000A         */ IL_0041: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000093 */
		/* 0x000028E2 2A                 */ IL_0046: ret
		/* 0x000028E3 02                 */ IL_0047: ldarg.0
		/* 0x000028E4 04                 */ IL_0048: ldarg.2
		/* 0x000028E5 7436000001         */ IL_0049: castclass [PresentationFramework]System.Windows.Controls.Button /* 01000036 */
		/* 0x000028EA 7D0D000004         */ IL_004e: stfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::btnCollapseAll /* 0400000D */
		/* 0x000028EF 02                 */ IL_0053: ldarg.0
		/* 0x000028F0 7B0D000004         */ IL_0054: ldfld class [PresentationFramework]System.Windows.Controls.Button AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::btnCollapseAll /* 0400000D */
		/* 0x000028F5 02                 */ IL_0059: ldarg.0
		/* 0x000028F6 FE0621000006       */ IL_005a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::btnCollapseAll_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 06000021 */
		/* 0x000028FC 737100000A         */ IL_0060: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000071 */
		/* 0x00002901 6F9300000A         */ IL_0065: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A000093 */
		/* 0x00002906 2A                 */ IL_006a: ret
		/* 0x00002907 02                 */ IL_006b: ldarg.0
		/* 0x00002908 17                 */ IL_006c: ldc.i4.1
		/* 0x00002909 7D0E000004         */ IL_006d: stfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh::_contentLoaded /* 0400000E */
		/* 0x0000290E 2A                 */ IL_0072: ret
	} // end of method MMFlowsh_Input_Flowsh::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_Input_Flowsh

.class /* 02000007 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel
{
	// Nested Types
	.class /* 0200000E */ nested public auto ansi beforefieldinit grdChild_GridData_ItemTemplate
		extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel
	{
		// Fields
		.field /* 0400002E */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration cboSClass_VarCol1_Property
		.field /* 0400002F */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration txtName_var1_Property
		.field /* 04000030 */ private string _recType
		.field /* 04000031 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration txtType_VarCol1_Property
		.field /* 04000032 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration cboStatus_Status_Property
		.field /* 04000033 */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration txtDescription_var1_Property

		// Methods
		.method /* 06000064 */ public hidebysig specialname 
			instance object get_cboSClass_VarCol1 () cil managed 
		{
			// Method begins at RVA 0x3942
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003942 02                 */ IL_0000: ldarg.0
			/* 0x00003943 7E2E000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::cboSClass_VarCol1_Property /* 0400002E */
			/* 0x00003948 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x0000394D 2A                 */ IL_000b: ret
		} // end of method grdChild_GridData_ItemTemplate::get_cboSClass_VarCol1

		.method /* 06000065 */ public hidebysig specialname 
			instance object get_txtName_var1 () cil managed 
		{
			// Method begins at RVA 0x394f
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x0000394F 02                 */ IL_0000: ldarg.0
			/* 0x00003950 7E2F000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::txtName_var1_Property /* 0400002F */
			/* 0x00003955 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x0000395A 2A                 */ IL_000b: ret
		} // end of method grdChild_GridData_ItemTemplate::get_txtName_var1

		.method /* 06000066 */ public hidebysig 
			instance string GetId () cil managed 
		{
			// Method begins at RVA 0x395c
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x0000395C 02                 */ IL_0000: ldarg.0
			/* 0x0000395D 729E080070         */ IL_0001: ldstr "txtName_var1.Value" /* 7000089E */
			/* 0x00003962 14                 */ IL_0006: ldnull
			/* 0x00003963 28B400000A         */ IL_0007: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveViewPropertyPath(string, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyWatch) /* 0A0000B4 */
			/* 0x00003968 289B00000A         */ IL_000c: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
			/* 0x0000396D 2A                 */ IL_0011: ret
		} // end of method grdChild_GridData_ItemTemplate::GetId

		.method /* 06000067 */ private hidebysig specialname 
			instance string get_RecType () cil managed 
		{
			// Method begins at RVA 0x3970
			// Header size: 12
			// Code size: 180 (0xb4)
			.maxstack 3
			.locals /* 11000005 */ init (
				[0] string
			)

			/* 0x00003970 02                 */ IL_0000: ldarg.0
			/* 0x00003971 7B30000004         */ IL_0001: ldfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x00003976 28AE00000A         */ IL_0006: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x0000397B 399D000000         */ IL_000b: brfalse IL_00ad
			/* 0x00003980 02                 */ IL_0010: ldarg.0
			/* 0x00003981 7251030070         */ IL_0011: ldstr "@main" /* 70000351 */
			/* 0x00003986 28A200000A         */ IL_0016: call instance string [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPath(string) /* 0A0000A2 */
			/* 0x0000398B 72C4080070         */ IL_001b: ldstr "Top.appModelV8." /* 700008C4 */
			/* 0x00003990 7EDD00000A         */ IL_0020: ldsfld string [mscorlib]System.String::Empty /* 0A0000DD */
			/* 0x00003995 6FDE00000A         */ IL_0025: callvirt instance string [mscorlib]System.String::Replace(string, string) /* 0A0000DE */
			/* 0x0000399A 0A                 */ IL_002a: stloc.0
			/* 0x0000399B 06                 */ IL_002b: ldloc.0
			/* 0x0000399C 72E4080070         */ IL_002c: ldstr "Reactions.Reactions" /* 700008E4 */
			/* 0x000039A1 283C00000A         */ IL_0031: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000039A6 2D36               */ IL_0036: brtrue.s IL_006e
			/* 0x000039A8 06                 */ IL_0038: ldloc.0
			/* 0x000039A9 720C090070         */ IL_0039: ldstr "Properties.Analysis" /* 7000090C */
			/* 0x000039AE 283C00000A         */ IL_003e: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000039B3 2D36               */ IL_0043: brtrue.s IL_007b
			/* 0x000039B5 06                 */ IL_0045: ldloc.0
			/* 0x000039B6 7234090070         */ IL_0046: ldstr "Convergence.Convergence" /* 70000934 */
			/* 0x000039BB 283C00000A         */ IL_004b: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000039C0 2D36               */ IL_0050: brtrue.s IL_0088
			/* 0x000039C2 06                 */ IL_0052: ldloc.0
			/* 0x000039C3 7264090070         */ IL_0053: ldstr "Model Analysis Tools.Data-Fit.Data-Set" /* 70000964 */
			/* 0x000039C8 283C00000A         */ IL_0058: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000039CD 2D36               */ IL_005d: brtrue.s IL_0095
			/* 0x000039CF 06                 */ IL_005f: ldloc.0
			/* 0x000039D0 72B2090070         */ IL_0060: ldstr "Properties.Data" /* 700009B2 */
			/* 0x000039D5 283C00000A         */ IL_0065: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A00003C */
			/* 0x000039DA 2D36               */ IL_006a: brtrue.s IL_00a2
			/* 0x000039DC 2B3F               */ IL_006c: br.s IL_00ad
			/* 0x000039DE 02                 */ IL_006e: ldarg.0
			/* 0x000039DF 72D2090070         */ IL_006f: ldstr "reactions" /* 700009D2 */
			/* 0x000039E4 7D30000004         */ IL_0074: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x000039E9 2B32               */ IL_0079: br.s IL_00ad
			/* 0x000039EB 02                 */ IL_007b: ldarg.0
			/* 0x000039EC 72E6090070         */ IL_007c: ldstr "analysis" /* 700009E6 */
			/* 0x000039F1 7D30000004         */ IL_0081: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x000039F6 2B25               */ IL_0086: br.s IL_00ad
			/* 0x000039F8 02                 */ IL_0088: ldarg.0
			/* 0x000039F9 72F8090070         */ IL_0089: ldstr "convergence" /* 700009F8 */
			/* 0x000039FE 7D30000004         */ IL_008e: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x00003A03 2B18               */ IL_0093: br.s IL_00ad
			/* 0x00003A05 02                 */ IL_0095: ldarg.0
			/* 0x00003A06 72100A0070         */ IL_0096: ldstr "data_set" /* 70000A10 */
			/* 0x00003A0B 7D30000004         */ IL_009b: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x00003A10 2B0B               */ IL_00a0: br.s IL_00ad
			/* 0x00003A12 02                 */ IL_00a2: ldarg.0
			/* 0x00003A13 72220A0070         */ IL_00a3: ldstr "data" /* 70000A22 */
			/* 0x00003A18 7D30000004         */ IL_00a8: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x00003A1D 02                 */ IL_00ad: ldarg.0
			/* 0x00003A1E 7B30000004         */ IL_00ae: ldfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x00003A23 2A                 */ IL_00b3: ret
		} // end of method grdChild_GridData_ItemTemplate::get_RecType

		.method /* 06000068 */ private hidebysig 
			instance string GetLocalizedCol1 (
				string key,
				string defaultOptionValue
			) cil managed 
		{
			// Method begins at RVA 0x3a30
			// Header size: 12
			// Code size: 70 (0x46)
			.maxstack 3
			.locals /* 11000012 */ init (
				[0] string,
				[1] string
			)

			/* 0x00003A30 7EDD00000A         */ IL_0000: ldsfld string [mscorlib]System.String::Empty /* 0A0000DD */
			/* 0x00003A35 0A                 */ IL_0005: stloc.0
			/* 0x00003A36 03                 */ IL_0006: ldarg.1
			/* 0x00003A37 28AE00000A         */ IL_0007: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x00003A3C 2D2C               */ IL_000c: brtrue.s IL_003a
			/* 0x00003A3E 03                 */ IL_000e: ldarg.1
			/* 0x00003A3F 722C0A0070         */ IL_000f: ldstr "[^a-zA-Z0-9]" /* 70000A2C */
			/* 0x00003A44 72460A0070         */ IL_0014: ldstr "_" /* 70000A46 */
			/* 0x00003A49 28DF00000A         */ IL_0019: call string [System]System.Text.RegularExpressions.Regex::Replace(string, string, string) /* 0A0000DF */
			/* 0x00003A4E 6FE000000A         */ IL_001e: callvirt instance string [mscorlib]System.String::ToLower() /* 0A0000E0 */
			/* 0x00003A53 0B                 */ IL_0023: stloc.1
			/* 0x00003A54 28E100000A         */ IL_0024: call class [mscorlib]System.Resources.ResourceManager [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.ApwnRecTypeResource::get_ResourceManager() /* 0A0000E1 */
			/* 0x00003A59 07                 */ IL_0029: ldloc.1
			/* 0x00003A5A 28E200000A         */ IL_002a: call class [mscorlib]System.Globalization.CultureInfo [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.ApwnRecTypeResource::get_Culture() /* 0A0000E2 */
			/* 0x00003A5F 6FE300000A         */ IL_002f: callvirt instance object [mscorlib]System.Resources.ResourceManager::GetObject(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A0000E3 */
			/* 0x00003A64 7559000001         */ IL_0034: isinst [mscorlib]System.String /* 01000059 */
			/* 0x00003A69 0A                 */ IL_0039: stloc.0
			/* 0x00003A6A 06                 */ IL_003a: ldloc.0
			/* 0x00003A6B 28AE00000A         */ IL_003b: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x00003A70 2D02               */ IL_0040: brtrue.s IL_0044
			/* 0x00003A72 06                 */ IL_0042: ldloc.0
			/* 0x00003A73 2A                 */ IL_0043: ret
			/* 0x00003A74 04                 */ IL_0044: ldarg.2
			/* 0x00003A75 2A                 */ IL_0045: ret
		} // end of method grdChild_GridData_ItemTemplate::GetLocalizedCol1

		.method /* 06000069 */ public hidebysig specialname 
			instance object get_txtType_VarCol1 () cil managed 
		{
			// Method begins at RVA 0x3a84
			// Header size: 12
			// Code size: 130 (0x82)
			.maxstack 5
			.locals /* 11000013 */ init (
				[0] class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVariableData,
				[1] string
			)

			/* 0x00003A84 02                 */ IL_0000: ldarg.0
			/* 0x00003A85 7E31000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::txtType_VarCol1_Property /* 04000031 */
			/* 0x00003A8A 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003A8F 7545000001         */ IL_000b: isinst [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVariableData /* 01000045 */
			/* 0x00003A94 0A                 */ IL_0010: stloc.0
			/* 0x00003A95 06                 */ IL_0011: ldloc.0
			/* 0x00003A96 2C6C               */ IL_0012: brfalse.s IL_0080
			/* 0x00003A98 06                 */ IL_0014: ldloc.0
			/* 0x00003A99 6FE400000A         */ IL_0015: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVariableData::get_Value() /* 0A0000E4 */
			/* 0x00003A9E 2C64               */ IL_001a: brfalse.s IL_0080
			/* 0x00003AA0 06                 */ IL_001c: ldloc.0
			/* 0x00003AA1 6FE400000A         */ IL_001d: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVariableData::get_Value() /* 0A0000E4 */
			/* 0x00003AA6 6F5A00000A         */ IL_0022: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00005A */
			/* 0x00003AAB 28AE00000A         */ IL_0027: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
			/* 0x00003AB0 2D52               */ IL_002c: brtrue.s IL_0080
			/* 0x00003AB2 02                 */ IL_002e: ldarg.0
			/* 0x00003AB3 724A0A0070         */ IL_002f: ldstr "rectype_" /* 70000A4A */
			/* 0x00003AB8 02                 */ IL_0034: ldarg.0
			/* 0x00003AB9 2867000006         */ IL_0035: call instance string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_RecType() /* 06000067 */
			/* 0x00003ABE 72460A0070         */ IL_003a: ldstr "_" /* 70000A46 */
			/* 0x00003AC3 06                 */ IL_003f: ldloc.0
			/* 0x00003AC4 6FE400000A         */ IL_0040: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVariableData::get_Value() /* 0A0000E4 */
			/* 0x00003AC9 6F5A00000A         */ IL_0045: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00005A */
			/* 0x00003ACE 28AC00000A         */ IL_004a: call string [mscorlib]System.String::Concat(string, string, string, string) /* 0A0000AC */
			/* 0x00003AD3 06                 */ IL_004f: ldloc.0
			/* 0x00003AD4 6FE400000A         */ IL_0050: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvVariableData::get_Value() /* 0A0000E4 */
			/* 0x00003AD9 6F5A00000A         */ IL_0055: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00005A */
			/* 0x00003ADE 2868000006         */ IL_005a: call instance string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::GetLocalizedCol1(string, string) /* 06000068 */
			/* 0x00003AE3 0B                 */ IL_005f: stloc.1
			/* 0x00003AE4 73D000000A         */ IL_0060: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData::.ctor() /* 0A0000D0 */
			/* 0x00003AE9 25                 */ IL_0065: dup
			/* 0x00003AEA 07                 */ IL_0066: ldloc.1
			/* 0x00003AEB 6FD100000A         */ IL_0067: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData::set_Value(object) /* 0A0000D1 */
			/* 0x00003AF0 25                 */ IL_006c: dup
			/* 0x00003AF1 17                 */ IL_006d: ldc.i4.1
			/* 0x00003AF2 8C97000001         */ IL_006e: box [mscorlib]System.Boolean /* 01000097 */
			/* 0x00003AF7 6FE500000A         */ IL_0073: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData::set_IsReadOnly(object) /* 0A0000E5 */
			/* 0x00003AFC 25                 */ IL_0078: dup
			/* 0x00003AFD 16                 */ IL_0079: ldc.i4.0
			/* 0x00003AFE 6FE600000A         */ IL_007a: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.ViewData.CxvManualVariableData::set_IsCalculated(bool) /* 0A0000E6 */
			/* 0x00003B03 2A                 */ IL_007f: ret
			/* 0x00003B04 06                 */ IL_0080: ldloc.0
			/* 0x00003B05 2A                 */ IL_0081: ret
		} // end of method grdChild_GridData_ItemTemplate::get_txtType_VarCol1

		.method /* 0600006A */ public hidebysig specialname 
			instance object get_cboStatus_Status () cil managed 
		{
			// Method begins at RVA 0x3b12
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003B12 02                 */ IL_0000: ldarg.0
			/* 0x00003B13 7E32000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::cboStatus_Status_Property /* 04000032 */
			/* 0x00003B18 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003B1D 2A                 */ IL_000b: ret
		} // end of method grdChild_GridData_ItemTemplate::get_cboStatus_Status

		.method /* 0600006B */ public hidebysig specialname 
			instance object get_txtDescription_var1 () cil managed 
		{
			// Method begins at RVA 0x3b1f
			// Header size: 1
			// Code size: 12 (0xc)
			.maxstack 8

			/* 0x00003B1F 02                 */ IL_0000: ldarg.0
			/* 0x00003B20 7E33000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::txtDescription_var1_Property /* 04000033 */
			/* 0x00003B25 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
			/* 0x00003B2A 2A                 */ IL_000b: ret
		} // end of method grdChild_GridData_ItemTemplate::get_txtDescription_var1

		.method /* 0600006C */ public hidebysig specialname rtspecialname 
			instance void .ctor () cil managed 
		{
			// Method begins at RVA 0x3b2c
			// Header size: 1
			// Code size: 18 (0x12)
			.maxstack 8

			/* 0x00003B2C 02                 */ IL_0000: ldarg.0
			/* 0x00003B2D 7EDD00000A         */ IL_0001: ldsfld string [mscorlib]System.String::Empty /* 0A0000DD */
			/* 0x00003B32 7D30000004         */ IL_0006: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::_recType /* 04000030 */
			/* 0x00003B37 02                 */ IL_000b: ldarg.0
			/* 0x00003B38 28C200000A         */ IL_000c: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::.ctor() /* 0A0000C2 */
			/* 0x00003B3D 2A                 */ IL_0011: ret
		} // end of method grdChild_GridData_ItemTemplate::.ctor

		.method /* 0600006D */ private hidebysig specialname rtspecialname static 
			void .cctor () cil managed 
		{
			// Method begins at RVA 0x3b40
			// Header size: 12
			// Code size: 304 (0x130)
			.maxstack 5

			/* 0x00003B40 725C0A0070         */ IL_0000: ldstr "cboSClass_VarCol1" /* 70000A5C */
			/* 0x00003B45 D00E000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
			/* 0x00003B4A 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003B4F 733000000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x00003B54 25                 */ IL_0014: dup
			/* 0x00003B55 18                 */ IL_0015: ldc.i4.2
			/* 0x00003B56 6FC300000A         */ IL_0016: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A0000C3 */
			/* 0x00003B5B 25                 */ IL_001b: dup
			/* 0x00003B5C 72800A0070         */ IL_001c: ldstr "@main.@y.Input.SCLASS" /* 70000A80 */
			/* 0x00003B61 6F3100000A         */ IL_0021: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003B66 283200000A         */ IL_0026: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003B6B 802E000004         */ IL_002b: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::cboSClass_VarCol1_Property /* 0400002E */
			/* 0x00003B70 72AC0A0070         */ IL_0030: ldstr "txtName_var1" /* 70000AAC */
			/* 0x00003B75 D00E000002         */ IL_0035: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
			/* 0x00003B7A 282F00000A         */ IL_003a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003B7F 73E700000A         */ IL_003f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvCustomTooltipProperty::.ctor() /* 0A0000E7 */
			/* 0x00003B84 25                 */ IL_0044: dup
			/* 0x00003B85 1C                 */ IL_0045: ldc.i4.6
			/* 0x00003B86 6FC300000A         */ IL_0046: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A0000C3 */
			/* 0x00003B8B 25                 */ IL_004b: dup
			/* 0x00003B8C 72C60A0070         */ IL_004c: ldstr "@main.@y" /* 70000AC6 */
			/* 0x00003B91 6F3100000A         */ IL_0051: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003B96 25                 */ IL_0056: dup
			/* 0x00003B97 17                 */ IL_0057: ldc.i4.1
			/* 0x00003B98 73CA00000A         */ IL_0058: newobj instance void valuetype [mscorlib]System.Nullable`1<valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDisplayedCase>::.ctor(!0) /* 0A0000CA */
			/* 0x00003B9D 6FCB00000A         */ IL_005d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DisplayedCase(valuetype [mscorlib]System.Nullable`1<valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxsDisplayedCase>) /* 0A0000CB */
			/* 0x00003BA2 283200000A         */ IL_0062: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003BA7 802F000004         */ IL_0067: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::txtName_var1_Property /* 0400002F */
			/* 0x00003BAC 72D80A0070         */ IL_006c: ldstr "txtType_VarCol1" /* 70000AD8 */
			/* 0x00003BB1 D00E000002         */ IL_0071: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
			/* 0x00003BB6 282F00000A         */ IL_0076: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003BBB 733000000A         */ IL_007b: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x00003BC0 25                 */ IL_0080: dup
			/* 0x00003BC1 18                 */ IL_0081: ldc.i4.2
			/* 0x00003BC2 6FC300000A         */ IL_0082: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A0000C3 */
			/* 0x00003BC7 25                 */ IL_0087: dup
			/* 0x00003BC8 72C60A0070         */ IL_0088: ldstr "@main.@y" /* 70000AC6 */
			/* 0x00003BCD 6F3100000A         */ IL_008d: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003BD2 25                 */ IL_0092: dup
			/* 0x00003BD3 72F80A0070         */ IL_0093: ldstr "type" /* 70000AF8 */
			/* 0x00003BD8 6FE800000A         */ IL_0098: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataAttribute(string) /* 0A0000E8 */
			/* 0x00003BDD 25                 */ IL_009d: dup
			/* 0x00003BDE 17                 */ IL_009e: ldc.i4.1
			/* 0x00003BDF 733F00000A         */ IL_009f: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x00003BE4 6FE900000A         */ IL_00a4: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_IsReadOnly(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000E9 */
			/* 0x00003BE9 25                 */ IL_00a9: dup
			/* 0x00003BEA 16                 */ IL_00aa: ldc.i4.0
			/* 0x00003BEB 733F00000A         */ IL_00ab: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x00003BF0 6FEA00000A         */ IL_00b0: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_IsCalculated(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000EA */
			/* 0x00003BF5 283200000A         */ IL_00b5: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003BFA 8031000004         */ IL_00ba: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::txtType_VarCol1_Property /* 04000031 */
			/* 0x00003BFF 72020B0070         */ IL_00bf: ldstr "cboStatus_Status" /* 70000B02 */
			/* 0x00003C04 D00E000002         */ IL_00c4: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
			/* 0x00003C09 282F00000A         */ IL_00c9: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003C0E 733000000A         */ IL_00ce: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x00003C13 25                 */ IL_00d3: dup
			/* 0x00003C14 18                 */ IL_00d4: ldc.i4.2
			/* 0x00003C15 6FC300000A         */ IL_00d5: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_ExposeAs(valuetype [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableTypeCode) /* 0A0000C3 */
			/* 0x00003C1A 25                 */ IL_00da: dup
			/* 0x00003C1B 72C60A0070         */ IL_00db: ldstr "@main.@y" /* 70000AC6 */
			/* 0x00003C20 6F3100000A         */ IL_00e0: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003C25 25                 */ IL_00e5: dup
			/* 0x00003C26 72240B0070         */ IL_00e6: ldstr "status" /* 70000B24 */
			/* 0x00003C2B 6FE800000A         */ IL_00eb: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataAttribute(string) /* 0A0000E8 */
			/* 0x00003C30 25                 */ IL_00f0: dup
			/* 0x00003C31 17                 */ IL_00f1: ldc.i4.1
			/* 0x00003C32 733F00000A         */ IL_00f2: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
			/* 0x00003C37 6FE900000A         */ IL_00f7: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_IsReadOnly(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000E9 */
			/* 0x00003C3C 283200000A         */ IL_00fc: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003C41 8032000004         */ IL_0101: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::cboStatus_Status_Property /* 04000032 */
			/* 0x00003C46 72320B0070         */ IL_0106: ldstr "txtDescription_var1" /* 70000B32 */
			/* 0x00003C4B D00E000002         */ IL_010b: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
			/* 0x00003C50 282F00000A         */ IL_0110: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
			/* 0x00003C55 733000000A         */ IL_0115: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::.ctor() /* 0A000030 */
			/* 0x00003C5A 25                 */ IL_011a: dup
			/* 0x00003C5B 725A0B0070         */ IL_011b: ldstr "@main.@y.Input.DESCRIPTION" /* 70000B5A */
			/* 0x00003C60 6F3100000A         */ IL_0120: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVariableProperty::set_DataPath(string) /* 0A000031 */
			/* 0x00003C65 283200000A         */ IL_0125: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
			/* 0x00003C6A 8033000004         */ IL_012a: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::txtDescription_var1_Property /* 04000033 */
			/* 0x00003C6F 2A                 */ IL_012f: ret
		} // end of method grdChild_GridData_ItemTemplate::.cctor

		// Properties
		.property /* 1700001E */ instance object cboSClass_VarCol1()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_cboSClass_VarCol1()
		}
		.property /* 1700001F */ instance object txtName_var1()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_txtName_var1()
		}
		.property /* 17000020 */ instance string RecType()
		{
			.get instance string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_RecType()
		}
		.property /* 17000021 */ instance object txtType_VarCol1()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_txtType_VarCol1()
		}
		.property /* 17000022 */ instance object cboStatus_Status()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_cboStatus_Status()
		}
		.property /* 17000023 */ instance object txtDescription_var1()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::get_txtDescription_var1()
		}

	} // end of class grdChild_GridData_ItemTemplate

	.class /* 0200000F */ nested private auto ansi sealed beforefieldinit '<GetSelectedIds>d__40'
		extends [mscorlib]System.Object
		implements class [mscorlib]System.Collections.Generic.IEnumerable`1<string>,
		           [mscorlib]System.Collections.IEnumerable,
		           class [mscorlib]System.Collections.Generic.IEnumerator`1<string>,
		           [mscorlib]System.IDisposable,
		           [mscorlib]System.Collections.IEnumerator
	{
		.custom /* 0C00001F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Fields
		.field /* 04000034 */ private int32 '<>1__state'
		.field /* 04000035 */ private string '<>2__current'
		.field /* 04000036 */ private int32 '<>l__initialThreadId'
		.field /* 04000037 */ public class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel '<>4__this'
		.field /* 04000038 */ private class [mscorlib]System.Collections.IList '<gridData>5__2'
		.field /* 04000039 */ private int32 '<i>5__3'

		// Methods
		.method /* 0600006E */ public hidebysig specialname rtspecialname 
			instance void .ctor (
				int32 '<>1__state'
			) cil managed 
		{
			.custom /* 0C00003A */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			// Method begins at RVA 0x3c7c
			// Header size: 1
			// Code size: 25 (0x19)
			.maxstack 8

			/* 0x00003C7C 02                 */ IL_0000: ldarg.0
			/* 0x00003C7D 28EB00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A0000EB */
			/* 0x00003C82 02                 */ IL_0006: ldarg.0
			/* 0x00003C83 03                 */ IL_0007: ldarg.1
			/* 0x00003C84 7D34000004         */ IL_0008: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003C89 02                 */ IL_000d: ldarg.0
			/* 0x00003C8A 28EC00000A         */ IL_000e: call int32 [mscorlib]System.Environment::get_CurrentManagedThreadId() /* 0A0000EC */
			/* 0x00003C8F 7D36000004         */ IL_0013: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>l__initialThreadId' /* 04000036 */
			/* 0x00003C94 2A                 */ IL_0018: ret
		} // end of method '<GetSelectedIds>d__40'::.ctor

		.method /* 0600006F */ private final hidebysig newslot virtual 
			instance void System.IDisposable.Dispose () cil managed 
		{
			.custom /* 0C00003B */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance void [mscorlib]System.IDisposable::Dispose()
			// Method begins at RVA 0x2eb6
			// Header size: 1
			// Code size: 1 (0x1)
			.maxstack 8

			/* 0x00002EB6 2A                 */ IL_0000: ret
		} // end of method '<GetSelectedIds>d__40'::System.IDisposable.Dispose

		.method /* 06000070 */ private final hidebysig newslot virtual 
			instance bool MoveNext () cil managed 
		{
			.override method instance bool [mscorlib]System.Collections.IEnumerator::MoveNext()
			// Method begins at RVA 0x3c98
			// Header size: 12
			// Code size: 157 (0x9d)
			.maxstack 3
			.locals /* 11000014 */ init (
				[0] int32,
				[1] class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel,
				[2] class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate,
				[3] int32
			)

			/* 0x00003C98 02                 */ IL_0000: ldarg.0
			/* 0x00003C99 7B34000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003C9E 0A                 */ IL_0006: stloc.0
			/* 0x00003C9F 02                 */ IL_0007: ldarg.0
			/* 0x00003CA0 7B37000004         */ IL_0008: ldfld class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>4__this' /* 04000037 */
			/* 0x00003CA5 0B                 */ IL_000d: stloc.1
			/* 0x00003CA6 06                 */ IL_000e: ldloc.0
			/* 0x00003CA7 2C06               */ IL_000f: brfalse.s IL_0017
			/* 0x00003CA9 06                 */ IL_0011: ldloc.0
			/* 0x00003CAA 17                 */ IL_0012: ldc.i4.1
			/* 0x00003CAB 2E66               */ IL_0013: beq.s IL_007b
			/* 0x00003CAD 16                 */ IL_0015: ldc.i4.0
			/* 0x00003CAE 2A                 */ IL_0016: ret
			/* 0x00003CAF 02                 */ IL_0017: ldarg.0
			/* 0x00003CB0 15                 */ IL_0018: ldc.i4.m1
			/* 0x00003CB1 7D34000004         */ IL_0019: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003CB6 02                 */ IL_001e: ldarg.0
			/* 0x00003CB7 07                 */ IL_001f: ldloc.1
			/* 0x00003CB8 2825000006         */ IL_0020: call instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_grdChild_GridData() /* 06000025 */
			/* 0x00003CBD 7547000001         */ IL_0025: isinst [mscorlib]System.Collections.IList /* 01000047 */
			/* 0x00003CC2 7D38000004         */ IL_002a: stfld class [mscorlib]System.Collections.IList AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<gridData>5__2' /* 04000038 */
			/* 0x00003CC7 02                 */ IL_002f: ldarg.0
			/* 0x00003CC8 07                 */ IL_0030: ldloc.1
			/* 0x00003CC9 2837000006         */ IL_0031: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
			/* 0x00003CCE 6FB600000A         */ IL_0036: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::get_Count() /* 0A0000B6 */
			/* 0x00003CD3 17                 */ IL_003b: ldc.i4.1
			/* 0x00003CD4 59                 */ IL_003c: sub
			/* 0x00003CD5 7D39000004         */ IL_003d: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<i>5__3' /* 04000039 */
			/* 0x00003CDA 2B4E               */ IL_0042: br.s IL_0092
			/* 0x00003CDC 02                 */ IL_0044: ldarg.0
			/* 0x00003CDD 7B38000004         */ IL_0045: ldfld class [mscorlib]System.Collections.IList AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<gridData>5__2' /* 04000038 */
			/* 0x00003CE2 07                 */ IL_004a: ldloc.1
			/* 0x00003CE3 2837000006         */ IL_004b: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
			/* 0x00003CE8 02                 */ IL_0050: ldarg.0
			/* 0x00003CE9 7B39000004         */ IL_0051: ldfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<i>5__3' /* 04000039 */
			/* 0x00003CEE 6FB100000A         */ IL_0056: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::get_Item(int32) /* 0A0000B1 */
			/* 0x00003CF3 6FED00000A         */ IL_005b: callvirt instance object [mscorlib]System.Collections.IList::get_Item(int32) /* 0A0000ED */
			/* 0x00003CF8 750E000002         */ IL_0060: isinst AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
			/* 0x00003CFD 0C                 */ IL_0065: stloc.2
			/* 0x00003CFE 02                 */ IL_0066: ldarg.0
			/* 0x00003CFF 08                 */ IL_0067: ldloc.2
			/* 0x00003D00 6F66000006         */ IL_0068: callvirt instance string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate::GetId() /* 06000066 */
			/* 0x00003D05 7D35000004         */ IL_006d: stfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>2__current' /* 04000035 */
			/* 0x00003D0A 02                 */ IL_0072: ldarg.0
			/* 0x00003D0B 17                 */ IL_0073: ldc.i4.1
			/* 0x00003D0C 7D34000004         */ IL_0074: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003D11 17                 */ IL_0079: ldc.i4.1
			/* 0x00003D12 2A                 */ IL_007a: ret
			/* 0x00003D13 02                 */ IL_007b: ldarg.0
			/* 0x00003D14 15                 */ IL_007c: ldc.i4.m1
			/* 0x00003D15 7D34000004         */ IL_007d: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003D1A 02                 */ IL_0082: ldarg.0
			/* 0x00003D1B 7B39000004         */ IL_0083: ldfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<i>5__3' /* 04000039 */
			/* 0x00003D20 0D                 */ IL_0088: stloc.3
			/* 0x00003D21 02                 */ IL_0089: ldarg.0
			/* 0x00003D22 09                 */ IL_008a: ldloc.3
			/* 0x00003D23 17                 */ IL_008b: ldc.i4.1
			/* 0x00003D24 59                 */ IL_008c: sub
			/* 0x00003D25 7D39000004         */ IL_008d: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<i>5__3' /* 04000039 */
			/* 0x00003D2A 02                 */ IL_0092: ldarg.0
			/* 0x00003D2B 7B39000004         */ IL_0093: ldfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<i>5__3' /* 04000039 */
			/* 0x00003D30 16                 */ IL_0098: ldc.i4.0
			/* 0x00003D31 2FA9               */ IL_0099: bge.s IL_0044
			/* 0x00003D33 16                 */ IL_009b: ldc.i4.0
			/* 0x00003D34 2A                 */ IL_009c: ret
		} // end of method '<GetSelectedIds>d__40'::MoveNext

		.method /* 06000071 */ private final hidebysig specialname newslot virtual 
			instance string 'System.Collections.Generic.IEnumerator<System.String>.get_Current' () cil managed 
		{
			.custom /* 0C00003C */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current()
			// Method begins at RVA 0x3d41
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003D41 02                 */ IL_0000: ldarg.0
			/* 0x00003D42 7B35000004         */ IL_0001: ldfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>2__current' /* 04000035 */
			/* 0x00003D47 2A                 */ IL_0006: ret
		} // end of method '<GetSelectedIds>d__40'::'System.Collections.Generic.IEnumerator<System.String>.get_Current'

		.method /* 06000072 */ private final hidebysig newslot virtual 
			instance void System.Collections.IEnumerator.Reset () cil managed 
		{
			.custom /* 0C00003D */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance void [mscorlib]System.Collections.IEnumerator::Reset()
			// Method begins at RVA 0x3d49
			// Header size: 1
			// Code size: 6 (0x6)
			.maxstack 8

			/* 0x00003D49 73EE00000A         */ IL_0000: newobj instance void [mscorlib]System.NotSupportedException::.ctor() /* 0A0000EE */
			/* 0x00003D4E 7A                 */ IL_0005: throw
		} // end of method '<GetSelectedIds>d__40'::System.Collections.IEnumerator.Reset

		.method /* 06000073 */ private final hidebysig specialname newslot virtual 
			instance object System.Collections.IEnumerator.get_Current () cil managed 
		{
			.custom /* 0C00003E */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance object [mscorlib]System.Collections.IEnumerator::get_Current()
			// Method begins at RVA 0x3d41
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003D41 02                 */ IL_0000: ldarg.0
			/* 0x00003D42 7B35000004         */ IL_0001: ldfld string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>2__current' /* 04000035 */
			/* 0x00003D47 2A                 */ IL_0006: ret
		} // end of method '<GetSelectedIds>d__40'::System.Collections.IEnumerator.get_Current

		.method /* 06000074 */ private final hidebysig newslot virtual 
			instance class [mscorlib]System.Collections.Generic.IEnumerator`1<string> 'System.Collections.Generic.IEnumerable<System.String>.GetEnumerator' () cil managed 
		{
			.custom /* 0C00003F */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator()
			// Method begins at RVA 0x3d50
			// Header size: 12
			// Code size: 55 (0x37)
			.maxstack 2
			.locals /* 11000015 */ init (
				[0] class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'
			)

			/* 0x00003D50 02                 */ IL_0000: ldarg.0
			/* 0x00003D51 7B34000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003D56 1FFE               */ IL_0006: ldc.i4.s -2
			/* 0x00003D58 3318               */ IL_0008: bne.un.s IL_0022
			/* 0x00003D5A 02                 */ IL_000a: ldarg.0
			/* 0x00003D5B 7B36000004         */ IL_000b: ldfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>l__initialThreadId' /* 04000036 */
			/* 0x00003D60 28EC00000A         */ IL_0010: call int32 [mscorlib]System.Environment::get_CurrentManagedThreadId() /* 0A0000EC */
			/* 0x00003D65 330B               */ IL_0015: bne.un.s IL_0022
			/* 0x00003D67 02                 */ IL_0017: ldarg.0
			/* 0x00003D68 16                 */ IL_0018: ldc.i4.0
			/* 0x00003D69 7D34000004         */ IL_0019: stfld int32 AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>1__state' /* 04000034 */
			/* 0x00003D6E 02                 */ IL_001e: ldarg.0
			/* 0x00003D6F 0A                 */ IL_001f: stloc.0
			/* 0x00003D70 2B13               */ IL_0020: br.s IL_0035
			/* 0x00003D72 16                 */ IL_0022: ldc.i4.0
			/* 0x00003D73 736E000006         */ IL_0023: newobj instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::.ctor(int32) /* 0600006E */
			/* 0x00003D78 0A                 */ IL_0028: stloc.0
			/* 0x00003D79 06                 */ IL_0029: ldloc.0
			/* 0x00003D7A 02                 */ IL_002a: ldarg.0
			/* 0x00003D7B 7B37000004         */ IL_002b: ldfld class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>4__this' /* 04000037 */
			/* 0x00003D80 7D37000004         */ IL_0030: stfld class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>4__this' /* 04000037 */
			/* 0x00003D85 06                 */ IL_0035: ldloc.0
			/* 0x00003D86 2A                 */ IL_0036: ret
		} // end of method '<GetSelectedIds>d__40'::'System.Collections.Generic.IEnumerable<System.String>.GetEnumerator'

		.method /* 06000075 */ private final hidebysig newslot virtual 
			instance class [mscorlib]System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator () cil managed 
		{
			.custom /* 0C000040 */ instance void [mscorlib]System.Diagnostics.DebuggerHiddenAttribute::.ctor() = (
				01 00 00 00
			)
			.override method instance class [mscorlib]System.Collections.IEnumerator [mscorlib]System.Collections.IEnumerable::GetEnumerator()
			// Method begins at RVA 0x3d93
			// Header size: 1
			// Code size: 7 (0x7)
			.maxstack 8

			/* 0x00003D93 02                 */ IL_0000: ldarg.0
			/* 0x00003D94 2874000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IEnumerator`1<string> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'System.Collections.Generic.IEnumerable<System.String>.GetEnumerator'() /* 06000074 */
			/* 0x00003D99 2A                 */ IL_0006: ret
		} // end of method '<GetSelectedIds>d__40'::System.Collections.IEnumerable.GetEnumerator

		// Properties
		.property /* 17000024 */ instance string 'System.Collections.Generic.IEnumerator<System.String>.Current'()
		{
			.get instance string AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'System.Collections.Generic.IEnumerator<System.String>.get_Current'()
		}
		.property /* 17000025 */ instance object System.Collections.IEnumerator.Current()
		{
			.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::System.Collections.IEnumerator.get_Current()
		}

	} // end of class <GetSelectedIds>d__40


	// Fields
	.field /* 0400000F */ public static initonly class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration grdChild_GridData_Property
	.field /* 04000010 */ private class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> _cmdAdd_Command
	.field /* 04000011 */ private class [System]System.Windows.Input.ICommand _cmdEdit_Command
	.field /* 04000012 */ private class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> _cmdDelete_Command
	.field /* 04000013 */ private class [System]System.Windows.Input.ICommand _cmdRename_Command
	.field /* 04000014 */ private class [System]System.Windows.Input.ICommand _cmdCurrent_Command
	.field /* 04000015 */ private class [System]System.Windows.Input.ICommand _grid_RowDoubleClickCommand
	.field /* 04000016 */ private class [System]System.Windows.Input.ICommand _cmdExport_Command
	.field /* 04000017 */ private class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> _SelectedRowIndexes

	// Methods
	.method /* 06000025 */ public hidebysig specialname 
		instance object get_grdChild_GridData () cil managed 
	{
		// Method begins at RVA 0x291b
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x0000291B 02                 */ IL_0000: ldarg.0
		/* 0x0000291C 7E0F000004         */ IL_0001: ldsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::grdChild_GridData_Property /* 0400000F */
		/* 0x00002921 6F2A00000A         */ IL_0006: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::GetValue(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration) /* 0A00002A */
		/* 0x00002926 2A                 */ IL_000b: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_grdChild_GridData

	.method /* 06000026 */ public hidebysig specialname 
		instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> get_cmdAdd_Command () cil managed 
	{
		// Method begins at RVA 0x2928
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x00002928 02                 */ IL_0000: ldarg.0
		/* 0x00002929 7B10000004         */ IL_0001: ldfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdAdd_Command /* 04000010 */
		/* 0x0000292E 2D17               */ IL_0006: brtrue.s IL_001f
		/* 0x00002930 02                 */ IL_0008: ldarg.0
		/* 0x00002931 02                 */ IL_0009: ldarg.0
		/* 0x00002932 FE062C000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::cmdAdd_CommandExecute(object) /* 0600002C */
		/* 0x00002938 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x0000293D 739500000A         */ IL_0015: newobj instance void class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>) /* 0A000095 */
		/* 0x00002942 7D10000004         */ IL_001a: stfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdAdd_Command /* 04000010 */
		/* 0x00002947 02                 */ IL_001f: ldarg.0
		/* 0x00002948 7B10000004         */ IL_0020: ldfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdAdd_Command /* 04000010 */
		/* 0x0000294D 2A                 */ IL_0025: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_cmdAdd_Command

	.method /* 06000027 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_cmdEdit_Command () cil managed 
	{
		// Method begins at RVA 0x294f
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x0000294F 02                 */ IL_0000: ldarg.0
		/* 0x00002950 7B11000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdEdit_Command /* 04000011 */
		/* 0x00002955 2D23               */ IL_0006: brtrue.s IL_002b
		/* 0x00002957 02                 */ IL_0008: ldarg.0
		/* 0x00002958 02                 */ IL_0009: ldarg.0
		/* 0x00002959 FE062D000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::cmdEdit_CommandExecute(object) /* 0600002D */
		/* 0x0000295F 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x00002964 02                 */ IL_0015: ldarg.0
		/* 0x00002965 FE0632000006       */ IL_0016: ldftn instance bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::CommandCanExecute(object) /* 06000032 */
		/* 0x0000296B 739600000A         */ IL_001c: newobj instance void class [mscorlib]System.Func`2<object, bool>::.ctor(object, native int) /* 0A000096 */
		/* 0x00002970 739700000A         */ IL_0021: newobj instance void class [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>, class [mscorlib]System.Func`2<!0, bool>) /* 0A000097 */
		/* 0x00002975 7D11000004         */ IL_0026: stfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdEdit_Command /* 04000011 */
		/* 0x0000297A 02                 */ IL_002b: ldarg.0
		/* 0x0000297B 7B11000004         */ IL_002c: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdEdit_Command /* 04000011 */
		/* 0x00002980 2A                 */ IL_0031: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_cmdEdit_Command

	.method /* 06000028 */ public hidebysig specialname 
		instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> get_cmdDelete_Command () cil managed 
	{
		// Method begins at RVA 0x2982
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x00002982 02                 */ IL_0000: ldarg.0
		/* 0x00002983 7B12000004         */ IL_0001: ldfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdDelete_Command /* 04000012 */
		/* 0x00002988 2D17               */ IL_0006: brtrue.s IL_001f
		/* 0x0000298A 02                 */ IL_0008: ldarg.0
		/* 0x0000298B 02                 */ IL_0009: ldarg.0
		/* 0x0000298C FE062F000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::cmdDelete_CommandExecute(object) /* 0600002F */
		/* 0x00002992 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x00002997 739500000A         */ IL_0015: newobj instance void class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>) /* 0A000095 */
		/* 0x0000299C 7D12000004         */ IL_001a: stfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdDelete_Command /* 04000012 */
		/* 0x000029A1 02                 */ IL_001f: ldarg.0
		/* 0x000029A2 7B12000004         */ IL_0020: ldfld class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdDelete_Command /* 04000012 */
		/* 0x000029A7 2A                 */ IL_0025: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_cmdDelete_Command

	.method /* 06000029 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_cmdRename_Command () cil managed 
	{
		// Method begins at RVA 0x29a9
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x000029A9 02                 */ IL_0000: ldarg.0
		/* 0x000029AA 7B13000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdRename_Command /* 04000013 */
		/* 0x000029AF 2D23               */ IL_0006: brtrue.s IL_002b
		/* 0x000029B1 02                 */ IL_0008: ldarg.0
		/* 0x000029B2 02                 */ IL_0009: ldarg.0
		/* 0x000029B3 FE0630000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::cmdRename_CommandExecute(object) /* 06000030 */
		/* 0x000029B9 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x000029BE 02                 */ IL_0015: ldarg.0
		/* 0x000029BF FE0632000006       */ IL_0016: ldftn instance bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::CommandCanExecute(object) /* 06000032 */
		/* 0x000029C5 739600000A         */ IL_001c: newobj instance void class [mscorlib]System.Func`2<object, bool>::.ctor(object, native int) /* 0A000096 */
		/* 0x000029CA 739700000A         */ IL_0021: newobj instance void class [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>, class [mscorlib]System.Func`2<!0, bool>) /* 0A000097 */
		/* 0x000029CF 7D13000004         */ IL_0026: stfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdRename_Command /* 04000013 */
		/* 0x000029D4 02                 */ IL_002b: ldarg.0
		/* 0x000029D5 7B13000004         */ IL_002c: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdRename_Command /* 04000013 */
		/* 0x000029DA 2A                 */ IL_0031: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_cmdRename_Command

	.method /* 0600002A */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_cmdCurrent_Command () cil managed 
	{
		// Method begins at RVA 0x29dc
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x000029DC 02                 */ IL_0000: ldarg.0
		/* 0x000029DD 7B14000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdCurrent_Command /* 04000014 */
		/* 0x000029E2 2D23               */ IL_0006: brtrue.s IL_002b
		/* 0x000029E4 02                 */ IL_0008: ldarg.0
		/* 0x000029E5 02                 */ IL_0009: ldarg.0
		/* 0x000029E6 FE0631000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::cmdCurrent_CommandExecute(object) /* 06000031 */
		/* 0x000029EC 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x000029F1 02                 */ IL_0015: ldarg.0
		/* 0x000029F2 FE0632000006       */ IL_0016: ldftn instance bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::CommandCanExecute(object) /* 06000032 */
		/* 0x000029F8 739600000A         */ IL_001c: newobj instance void class [mscorlib]System.Func`2<object, bool>::.ctor(object, native int) /* 0A000096 */
		/* 0x000029FD 739700000A         */ IL_0021: newobj instance void class [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>, class [mscorlib]System.Func`2<!0, bool>) /* 0A000097 */
		/* 0x00002A02 7D14000004         */ IL_0026: stfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdCurrent_Command /* 04000014 */
		/* 0x00002A07 02                 */ IL_002b: ldarg.0
		/* 0x00002A08 7B14000004         */ IL_002c: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdCurrent_Command /* 04000014 */
		/* 0x00002A0D 2A                 */ IL_0031: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_cmdCurrent_Command

	.method /* 0600002B */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_grid_RowDoubleClickCommand () cil managed 
	{
		// Method begins at RVA 0x2a0f
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x00002A0F 02                 */ IL_0000: ldarg.0
		/* 0x00002A10 7B15000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_grid_RowDoubleClickCommand /* 04000015 */
		/* 0x00002A15 2D17               */ IL_0006: brtrue.s IL_001f
		/* 0x00002A17 02                 */ IL_0008: ldarg.0
		/* 0x00002A18 02                 */ IL_0009: ldarg.0
		/* 0x00002A19 FE0634000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::grid_RowDoubleClickCommandExecute(object) /* 06000034 */
		/* 0x00002A1F 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x00002A24 739800000A         */ IL_0015: newobj instance void class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvDelegateCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>) /* 0A000098 */
		/* 0x00002A29 7D15000004         */ IL_001a: stfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_grid_RowDoubleClickCommand /* 04000015 */
		/* 0x00002A2E 02                 */ IL_001f: ldarg.0
		/* 0x00002A2F 7B15000004         */ IL_0020: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_grid_RowDoubleClickCommand /* 04000015 */
		/* 0x00002A34 2A                 */ IL_0025: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_grid_RowDoubleClickCommand

	.method /* 0600002C */ private hidebysig 
		instance void cmdAdd_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2a38
		// Header size: 12
		// Code size: 101 (0x65)
		.maxstack 5
		.locals /* 11000008 */ init (
			[0] string,
			[1] string,
			[2] valuetype [mscorlib]System.Nullable`1<bool>,
			[3] string
		)

		/* 0x00002A38 739900000A         */ IL_0000: newobj instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.CompositeEvents.ShowAddChildDialogEventArgs::.ctor() /* 0A000099 */
		/* 0x00002A3D 25                 */ IL_0005: dup
		/* 0x00002A3E 02                 */ IL_0006: ldarg.0
		/* 0x00002A3F 7241030070         */ IL_0007: ldstr "main" /* 70000341 */
		/* 0x00002A44 14                 */ IL_000c: ldnull
		/* 0x00002A45 289A00000A         */ IL_000d: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveParameter(string, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyWatch) /* 0A00009A */
		/* 0x00002A4A 289B00000A         */ IL_0012: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
		/* 0x00002A4F 6F9C00000A         */ IL_0017: callvirt instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.CompositeEvents.ShowAddChildDialogEventArgs::set_ParentPath(string) /* 0A00009C */
		/* 0x00002A54 26                 */ IL_001c: pop
		/* 0x00002A55 02                 */ IL_001d: ldarg.0
		/* 0x00002A56 7241030070         */ IL_001e: ldstr "main" /* 70000341 */
		/* 0x00002A5B 14                 */ IL_0023: ldnull
		/* 0x00002A5C 289A00000A         */ IL_0024: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveParameter(string, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyWatch) /* 0A00009A */
		/* 0x00002A61 289B00000A         */ IL_0029: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
		/* 0x00002A66 0A                 */ IL_002e: stloc.0
		/* 0x00002A67 14                 */ IL_002f: ldnull
		/* 0x00002A68 0B                 */ IL_0030: stloc.1
		/* 0x00002A69 02                 */ IL_0031: ldarg.0
		/* 0x00002A6A 06                 */ IL_0032: ldloc.0
		/* 0x00002A6B 1201               */ IL_0033: ldloca.s 1
		/* 0x00002A6D 16                 */ IL_0035: ldc.i4.0
		/* 0x00002A6E 289D00000A         */ IL_0036: call instance valuetype [mscorlib]System.Nullable`1<bool> [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::ShowAddChildDialog(string, string&, bool) /* 0A00009D */
		/* 0x00002A73 0C                 */ IL_003b: stloc.2
		/* 0x00002A74 1202               */ IL_003c: ldloca.s 2
		/* 0x00002A76 289E00000A         */ IL_003e: call instance bool valuetype [mscorlib]System.Nullable`1<bool>::get_HasValue() /* 0A00009E */
		/* 0x00002A7B 2C1F               */ IL_0043: brfalse.s IL_0064
		/* 0x00002A7D 1202               */ IL_0045: ldloca.s 2
		/* 0x00002A7F 289F00000A         */ IL_0047: call instance !0 valuetype [mscorlib]System.Nullable`1<bool>::get_Value() /* 0A00009F */
		/* 0x00002A84 2C16               */ IL_004c: brfalse.s IL_0064
		/* 0x00002A86 724B030070         */ IL_004e: ldstr ".!" /* 7000034B */
		/* 0x00002A8B 07                 */ IL_0053: ldloc.1
		/* 0x00002A8C 28A000000A         */ IL_0054: call string [mscorlib]System.String::Concat(string, string) /* 0A0000A0 */
		/* 0x00002A91 0D                 */ IL_0059: stloc.3
		/* 0x00002A92 02                 */ IL_005a: ldarg.0
		/* 0x00002A93 09                 */ IL_005b: ldloc.3
		/* 0x00002A94 14                 */ IL_005c: ldnull
		/* 0x00002A95 16                 */ IL_005d: ldc.i4.0
		/* 0x00002A96 28A100000A         */ IL_005e: call instance bool [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::GoToNode(string, string, bool) /* 0A0000A1 */
		/* 0x00002A9B 26                 */ IL_0063: pop
		/* 0x00002A9C 2A                 */ IL_0064: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::cmdAdd_CommandExecute

	.method /* 0600002D */ private hidebysig 
		instance void cmdEdit_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2aac
		// Header size: 12
		// Code size: 63 (0x3f)
		.maxstack 2
		.locals /* 11000009 */ init (
			[0] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>,
			[1] string,
			[2] string
		)

		/* 0x00002AAC 02                 */ IL_0000: ldarg.0
		/* 0x00002AAD 283A000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IEnumerable`1<string> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::GetSelectedIds() /* 0600003A */
		/* 0x00002AB2 6F1D00000A         */ IL_0006: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A00001D */
		/* 0x00002AB7 0A                 */ IL_000b: stloc.0
		/* 0x00002AB8 2B1C               */ IL_000c: br.s IL_002a
		/* 0x00002ABA 06                 */ IL_000e: ldloc.0
		/* 0x00002ABB 6F1A00000A         */ IL_000f: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A00001A */
		/* 0x00002AC0 0B                 */ IL_0014: stloc.1
		/* 0x00002AC1 724B030070         */ IL_0015: ldstr ".!" /* 7000034B */
		/* 0x00002AC6 07                 */ IL_001a: ldloc.1
		/* 0x00002AC7 28A000000A         */ IL_001b: call string [mscorlib]System.String::Concat(string, string) /* 0A0000A0 */
		/* 0x00002ACC 0C                 */ IL_0020: stloc.2
		/* 0x00002ACD 02                 */ IL_0021: ldarg.0
		/* 0x00002ACE 08                 */ IL_0022: ldloc.2
		/* 0x00002ACF 282E000006         */ IL_0023: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::GoToNodeEx(string) /* 0600002E */
		/* 0x00002AD4 DE14               */ IL_0028: leave.s IL_003e
		/* 0x00002AD6 06                 */ IL_002a: ldloc.0
		/* 0x00002AD7 6F1900000A         */ IL_002b: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002ADC 2DDC               */ IL_0030: brtrue.s IL_000e
		/* 0x00002ADE DE0A               */ IL_0032: leave.s IL_003e
		/* 0x00002AE0 06                 */ IL_0034: ldloc.0
		/* 0x00002AE1 2C06               */ IL_0035: brfalse.s IL_003d
		/* 0x00002AE3 06                 */ IL_0037: ldloc.0
		/* 0x00002AE4 6F1800000A         */ IL_0038: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000018 */
		/* 0x00002AE9 DC                 */ IL_003d: endfinally
		/* 0x00002AEA 2A                 */ IL_003e: ret

		.try IL_000c-IL_0034 finally IL_0034-IL_003e
	} // end of method MMFlowsh_ObjMan_ViewModel::cmdEdit_CommandExecute

	.method /* 0600002E */ private hidebysig 
		instance void GoToNodeEx (
			string path
		) cil managed 
	{
		// Method begins at RVA 0x2b08
		// Header size: 12
		// Code size: 175 (0xaf)
		.maxstack 6
		.locals /* 1100000A */ init (
			[0] string,
			[1] class [mscorlib]System.Text.StringBuilder,
			[2] class [System]System.Text.RegularExpressions.MatchCollection,
			[3] class [mscorlib]System.Collections.IEnumerator,
			[4] class [System]System.Text.RegularExpressions.Match,
			[5] class [mscorlib]System.IDisposable
		)

		/* 0x00002B08 02                 */ IL_0000: ldarg.0
		/* 0x00002B09 7251030070         */ IL_0001: ldstr "@main" /* 70000351 */
		/* 0x00002B0E 28A200000A         */ IL_0006: call instance string [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPath(string) /* 0A0000A2 */
		/* 0x00002B13 0A                 */ IL_000b: stloc.0
		/* 0x00002B14 06                 */ IL_000c: ldloc.0
		/* 0x00002B15 725D030070         */ IL_000d: ldstr "Blocks" /* 7000035D */
		/* 0x00002B1A 6FA300000A         */ IL_0012: callvirt instance bool [mscorlib]System.String::Contains(string) /* 0A0000A3 */
		/* 0x00002B1F 3988000000         */ IL_0017: brfalse IL_00a4
		/* 0x00002B24 726B030070         */ IL_001c: ldstr "Blocks\\.\\w+\\." /* 7000036B */
		/* 0x00002B29 73A400000A         */ IL_0021: newobj instance void [System]System.Text.RegularExpressions.Regex::.ctor(string) /* 0A0000A4 */
		/* 0x00002B2E 73A500000A         */ IL_0026: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A0000A5 */
		/* 0x00002B33 0B                 */ IL_002b: stloc.1
		/* 0x00002B34 06                 */ IL_002c: ldloc.0
		/* 0x00002B35 6FA600000A         */ IL_002d: callvirt instance class [System]System.Text.RegularExpressions.MatchCollection [System]System.Text.RegularExpressions.Regex::Matches(string) /* 0A0000A6 */
		/* 0x00002B3A 0C                 */ IL_0032: stloc.2
		/* 0x00002B3B 08                 */ IL_0033: ldloc.2
		/* 0x00002B3C 6FA700000A         */ IL_0034: callvirt instance int32 [System]System.Text.RegularExpressions.MatchCollection::get_Count() /* 0A0000A7 */
		/* 0x00002B41 16                 */ IL_0039: ldc.i4.0
		/* 0x00002B42 3142               */ IL_003a: ble.s IL_007e
		/* 0x00002B44 08                 */ IL_003c: ldloc.2
		/* 0x00002B45 6FA800000A         */ IL_003d: callvirt instance class [mscorlib]System.Collections.IEnumerator [System]System.Text.RegularExpressions.MatchCollection::GetEnumerator() /* 0A0000A8 */
		/* 0x00002B4A 0D                 */ IL_0042: stloc.3
		/* 0x00002B4B 2B1B               */ IL_0043: br.s IL_0060
		/* 0x00002B4D 09                 */ IL_0045: ldloc.3
		/* 0x00002B4E 6F1C00000A         */ IL_0046: callvirt instance object [mscorlib]System.Collections.IEnumerator::get_Current() /* 0A00001C */
		/* 0x00002B53 7440000001         */ IL_004b: castclass [System]System.Text.RegularExpressions.Match /* 01000040 */
		/* 0x00002B58 1304               */ IL_0050: stloc.s 4
		/* 0x00002B5A 07                 */ IL_0052: ldloc.1
		/* 0x00002B5B 1104               */ IL_0053: ldloc.s 4
		/* 0x00002B5D 6FA900000A         */ IL_0055: callvirt instance string [System]System.Text.RegularExpressions.Capture::get_Value() /* 0A0000A9 */
		/* 0x00002B62 6FAA00000A         */ IL_005a: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A0000AA */
		/* 0x00002B67 26                 */ IL_005f: pop
		/* 0x00002B68 09                 */ IL_0060: ldloc.3
		/* 0x00002B69 6F1900000A         */ IL_0061: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002B6E 2DDD               */ IL_0066: brtrue.s IL_0045
		/* 0x00002B70 DE14               */ IL_0068: leave.s IL_007e
		/* 0x00002B72 09                 */ IL_006a: ldloc.3
		/* 0x00002B73 752B000001         */ IL_006b: isinst [mscorlib]System.IDisposable /* 0100002B */
		/* 0x00002B78 1305               */ IL_0070: stloc.s 5
		/* 0x00002B7A 1105               */ IL_0072: ldloc.s 5
		/* 0x00002B7C 2C07               */ IL_0074: brfalse.s IL_007d
		/* 0x00002B7E 1105               */ IL_0076: ldloc.s 5
		/* 0x00002B80 6F1800000A         */ IL_0078: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000018 */
		/* 0x00002B85 DC                 */ IL_007d: endfinally
		/* 0x00002B86 02                 */ IL_007e: ldarg.0
		/* 0x00002B87 7287030070         */ IL_007f: ldstr "Simulation!" /* 70000387 */
		/* 0x00002B8C 07                 */ IL_0084: ldloc.1
		/* 0x00002B8D 6F5A00000A         */ IL_0085: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00005A */
		/* 0x00002B92 729F030070         */ IL_008a: ldstr "Flowsheet.Section." /* 7000039F */
		/* 0x00002B97 03                 */ IL_008f: ldarg.1
		/* 0x00002B98 18                 */ IL_0090: ldc.i4.2
		/* 0x00002B99 6FAB00000A         */ IL_0091: callvirt instance string [mscorlib]System.String::Substring(int32) /* 0A0000AB */
		/* 0x00002B9E 28AC00000A         */ IL_0096: call string [mscorlib]System.String::Concat(string, string, string, string) /* 0A0000AC */
		/* 0x00002BA3 14                 */ IL_009b: ldnull
		/* 0x00002BA4 16                 */ IL_009c: ldc.i4.0
		/* 0x00002BA5 28A100000A         */ IL_009d: call instance bool [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::GoToNode(string, string, bool) /* 0A0000A1 */
		/* 0x00002BAA 26                 */ IL_00a2: pop
		/* 0x00002BAB 2A                 */ IL_00a3: ret
		/* 0x00002BAC 02                 */ IL_00a4: ldarg.0
		/* 0x00002BAD 03                 */ IL_00a5: ldarg.1
		/* 0x00002BAE 14                 */ IL_00a6: ldnull
		/* 0x00002BAF 16                 */ IL_00a7: ldc.i4.0
		/* 0x00002BB0 28A100000A         */ IL_00a8: call instance bool [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::GoToNode(string, string, bool) /* 0A0000A1 */
		/* 0x00002BB5 26                 */ IL_00ad: pop
		/* 0x00002BB6 2A                 */ IL_00ae: ret

		.try IL_0043-IL_006a finally IL_006a-IL_007e
	} // end of method MMFlowsh_ObjMan_ViewModel::GoToNodeEx

	.method /* 0600002F */ private hidebysig 
		instance void cmdDelete_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2bd4
		// Header size: 12
		// Code size: 109 (0x6d)
		.maxstack 4
		.locals /* 1100000B */ init (
			[0] class [mscorlib]System.Collections.ObjectModel.Collection`1<string>,
			[1] string,
			[2] string,
			[3] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>,
			[4] string
		)

		/* 0x00002BD4 73AD00000A         */ IL_0000: newobj instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::.ctor() /* 0A0000AD */
		/* 0x00002BD9 0A                 */ IL_0005: stloc.0
		/* 0x00002BDA 03                 */ IL_0006: ldarg.1
		/* 0x00002BDB 7559000001         */ IL_0007: isinst [mscorlib]System.String /* 01000059 */
		/* 0x00002BE0 0B                 */ IL_000c: stloc.1
		/* 0x00002BE1 07                 */ IL_000d: ldloc.1
		/* 0x00002BE2 28AE00000A         */ IL_000e: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A0000AE */
		/* 0x00002BE7 2D09               */ IL_0013: brtrue.s IL_001e
		/* 0x00002BE9 06                 */ IL_0015: ldloc.0
		/* 0x00002BEA 07                 */ IL_0016: ldloc.1
		/* 0x00002BEB 6F3500000A         */ IL_0017: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Add(!0) /* 0A000035 */
		/* 0x00002BF0 2B32               */ IL_001c: br.s IL_0050
		/* 0x00002BF2 02                 */ IL_001e: ldarg.0
		/* 0x00002BF3 283A000006         */ IL_001f: call instance class [mscorlib]System.Collections.Generic.IEnumerable`1<string> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::GetSelectedIds() /* 0600003A */
		/* 0x00002BF8 6F1D00000A         */ IL_0024: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A00001D */
		/* 0x00002BFD 0D                 */ IL_0029: stloc.3
		/* 0x00002BFE 2B10               */ IL_002a: br.s IL_003c
		/* 0x00002C00 09                 */ IL_002c: ldloc.3
		/* 0x00002C01 6F1A00000A         */ IL_002d: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A00001A */
		/* 0x00002C06 1304               */ IL_0032: stloc.s 4
		/* 0x00002C08 06                 */ IL_0034: ldloc.0
		/* 0x00002C09 1104               */ IL_0035: ldloc.s 4
		/* 0x00002C0B 6F3500000A         */ IL_0037: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<string>::Add(!0) /* 0A000035 */
		/* 0x00002C10 09                 */ IL_003c: ldloc.3
		/* 0x00002C11 6F1900000A         */ IL_003d: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002C16 2DE8               */ IL_0042: brtrue.s IL_002c
		/* 0x00002C18 DE0A               */ IL_0044: leave.s IL_0050
		/* 0x00002C1A 09                 */ IL_0046: ldloc.3
		/* 0x00002C1B 2C06               */ IL_0047: brfalse.s IL_004f
		/* 0x00002C1D 09                 */ IL_0049: ldloc.3
		/* 0x00002C1E 6F1800000A         */ IL_004a: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000018 */
		/* 0x00002C23 DC                 */ IL_004f: endfinally
		/* 0x00002C24 02                 */ IL_0050: ldarg.0
		/* 0x00002C25 7241030070         */ IL_0051: ldstr "main" /* 70000341 */
		/* 0x00002C2A 14                 */ IL_0056: ldnull
		/* 0x00002C2B 289A00000A         */ IL_0057: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveParameter(string, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyWatch) /* 0A00009A */
		/* 0x00002C30 289B00000A         */ IL_005c: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
		/* 0x00002C35 0C                 */ IL_0061: stloc.2
		/* 0x00002C36 02                 */ IL_0062: ldarg.0
		/* 0x00002C37 08                 */ IL_0063: ldloc.2
		/* 0x00002C38 06                 */ IL_0064: ldloc.0
		/* 0x00002C39 16                 */ IL_0065: ldc.i4.0
		/* 0x00002C3A 28AF00000A         */ IL_0066: call instance class [mscorlib]System.Collections.Generic.IList`1<string> [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::DeleteChildren(string, class [mscorlib]System.Collections.Generic.IEnumerable`1<string>, bool) /* 0A0000AF */
		/* 0x00002C3F 26                 */ IL_006b: pop
		/* 0x00002C40 2A                 */ IL_006c: ret

		.try IL_002a-IL_0046 finally IL_0046-IL_0050
	} // end of method MMFlowsh_ObjMan_ViewModel::cmdDelete_CommandExecute

	.method /* 06000030 */ private hidebysig 
		instance void cmdRename_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2c60
		// Header size: 12
		// Code size: 77 (0x4d)
		.maxstack 4
		.locals /* 1100000C */ init (
			[0] string,
			[1] string,
			[2] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>
		)

		/* 0x00002C60 02                 */ IL_0000: ldarg.0
		/* 0x00002C61 7241030070         */ IL_0001: ldstr "main" /* 70000341 */
		/* 0x00002C66 14                 */ IL_0006: ldnull
		/* 0x00002C67 289A00000A         */ IL_0007: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveParameter(string, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyWatch) /* 0A00009A */
		/* 0x00002C6C 289B00000A         */ IL_000c: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
		/* 0x00002C71 0A                 */ IL_0011: stloc.0
		/* 0x00002C72 72C5030070         */ IL_0012: ldstr "" /* 700003C5 */
		/* 0x00002C77 0B                 */ IL_0017: stloc.1
		/* 0x00002C78 02                 */ IL_0018: ldarg.0
		/* 0x00002C79 283A000006         */ IL_0019: call instance class [mscorlib]System.Collections.Generic.IEnumerable`1<string> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::GetSelectedIds() /* 0600003A */
		/* 0x00002C7E 6F1D00000A         */ IL_001e: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A00001D */
		/* 0x00002C83 0C                 */ IL_0023: stloc.2
		/* 0x00002C84 2B12               */ IL_0024: br.s IL_0038
		/* 0x00002C86 08                 */ IL_0026: ldloc.2
		/* 0x00002C87 6F1A00000A         */ IL_0027: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A00001A */
		/* 0x00002C8C 0B                 */ IL_002c: stloc.1
		/* 0x00002C8D 02                 */ IL_002d: ldarg.0
		/* 0x00002C8E 06                 */ IL_002e: ldloc.0
		/* 0x00002C8F 1201               */ IL_002f: ldloca.s 1
		/* 0x00002C91 16                 */ IL_0031: ldc.i4.0
		/* 0x00002C92 28B000000A         */ IL_0032: call instance valuetype [mscorlib]System.Nullable`1<bool> [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::ShowRenameChildDialog(string, string&, bool) /* 0A0000B0 */
		/* 0x00002C97 26                 */ IL_0037: pop
		/* 0x00002C98 08                 */ IL_0038: ldloc.2
		/* 0x00002C99 6F1900000A         */ IL_0039: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002C9E 2DE6               */ IL_003e: brtrue.s IL_0026
		/* 0x00002CA0 DE0A               */ IL_0040: leave.s IL_004c
		/* 0x00002CA2 08                 */ IL_0042: ldloc.2
		/* 0x00002CA3 2C06               */ IL_0043: brfalse.s IL_004b
		/* 0x00002CA5 08                 */ IL_0045: ldloc.2
		/* 0x00002CA6 6F1800000A         */ IL_0046: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000018 */
		/* 0x00002CAB DC                 */ IL_004b: endfinally
		/* 0x00002CAC 2A                 */ IL_004c: ret

		.try IL_0024-IL_0042 finally IL_0042-IL_004c
	} // end of method MMFlowsh_ObjMan_ViewModel::cmdRename_CommandExecute

	.method /* 06000031 */ private hidebysig 
		instance void cmdCurrent_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2ccc
		// Header size: 12
		// Code size: 66 (0x42)
		.maxstack 6
		.locals /* 1100000D */ init (
			[0] int32
		)

		/* 0x00002CCC 02                 */ IL_0000: ldarg.0
		/* 0x00002CCD 02                 */ IL_0001: ldarg.0
		/* 0x00002CCE 7251030070         */ IL_0002: ldstr "@main" /* 70000351 */
		/* 0x00002CD3 28A200000A         */ IL_0007: call instance string [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPath(string) /* 0A0000A2 */
		/* 0x00002CD8 02                 */ IL_000c: ldarg.0
		/* 0x00002CD9 72C7030070         */ IL_000d: ldstr "grdChild_GridData[" /* 700003C7 */
		/* 0x00002CDE 02                 */ IL_0012: ldarg.0
		/* 0x00002CDF 2837000006         */ IL_0013: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002CE4 16                 */ IL_0018: ldc.i4.0
		/* 0x00002CE5 6FB100000A         */ IL_0019: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::get_Item(int32) /* 0A0000B1 */
		/* 0x00002CEA 0A                 */ IL_001e: stloc.0
		/* 0x00002CEB 1200               */ IL_001f: ldloca.s 0
		/* 0x00002CED 28B200000A         */ IL_0021: call instance string [mscorlib]System.Int32::ToString() /* 0A0000B2 */
		/* 0x00002CF2 72ED030070         */ IL_0026: ldstr "].txtName_var1.Value" /* 700003ED */
		/* 0x00002CF7 28B300000A         */ IL_002b: call string [mscorlib]System.String::Concat(string, string, string) /* 0A0000B3 */
		/* 0x00002CFC 14                 */ IL_0030: ldnull
		/* 0x00002CFD 28B400000A         */ IL_0031: call instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ResolveViewPropertyPath(string, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyWatch) /* 0A0000B4 */
		/* 0x00002D02 289B00000A         */ IL_0036: call string [AspenTech.AspenCxs]AspenTech.AspenCxs.CxsConverter::ValueToString(object) /* 0A00009B */
		/* 0x00002D07 28B500000A         */ IL_003b: call bool [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.ViewModelExtensions.MmgExtensions::ChangeSection(class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel, string, string) /* 0A0000B5 */
		/* 0x00002D0C 26                 */ IL_0040: pop
		/* 0x00002D0D 2A                 */ IL_0041: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::cmdCurrent_CommandExecute

	.method /* 06000032 */ private hidebysig 
		instance bool CommandCanExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2d1a
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00002D1A 02                 */ IL_0000: ldarg.0
		/* 0x00002D1B 2837000006         */ IL_0001: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002D20 2C10               */ IL_0006: brfalse.s IL_0018
		/* 0x00002D22 02                 */ IL_0008: ldarg.0
		/* 0x00002D23 2837000006         */ IL_0009: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002D28 6FB600000A         */ IL_000e: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::get_Count() /* 0A0000B6 */
		/* 0x00002D2D 17                 */ IL_0013: ldc.i4.1
		/* 0x00002D2E 3302               */ IL_0014: bne.un.s IL_0018
		/* 0x00002D30 17                 */ IL_0016: ldc.i4.1
		/* 0x00002D31 2A                 */ IL_0017: ret
		/* 0x00002D32 16                 */ IL_0018: ldc.i4.0
		/* 0x00002D33 2A                 */ IL_0019: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::CommandCanExecute

	.method /* 06000033 */ private hidebysig 
		instance bool DeleteCommandCanExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2d35
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00002D35 02                 */ IL_0000: ldarg.0
		/* 0x00002D36 2837000006         */ IL_0001: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002D3B 2C10               */ IL_0006: brfalse.s IL_0018
		/* 0x00002D3D 02                 */ IL_0008: ldarg.0
		/* 0x00002D3E 2837000006         */ IL_0009: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002D43 6FB600000A         */ IL_000e: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::get_Count() /* 0A0000B6 */
		/* 0x00002D48 16                 */ IL_0013: ldc.i4.0
		/* 0x00002D49 3102               */ IL_0014: ble.s IL_0018
		/* 0x00002D4B 17                 */ IL_0016: ldc.i4.1
		/* 0x00002D4C 2A                 */ IL_0017: ret
		/* 0x00002D4D 16                 */ IL_0018: ldc.i4.0
		/* 0x00002D4E 2A                 */ IL_0019: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::DeleteCommandCanExecute

	.method /* 06000034 */ private hidebysig 
		instance void grid_RowDoubleClickCommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2d50
		// Header size: 12
		// Code size: 48 (0x30)
		.maxstack 4
		.locals /* 1100000E */ init (
			[0] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>,
			[1] string
		)

		/* 0x00002D50 02                 */ IL_0000: ldarg.0
		/* 0x00002D51 283A000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IEnumerable`1<string> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::GetSelectedIds() /* 0600003A */
		/* 0x00002D56 6F1D00000A         */ IL_0006: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A00001D */
		/* 0x00002D5B 0A                 */ IL_000b: stloc.0
		/* 0x00002D5C 06                 */ IL_000c: ldloc.0
		/* 0x00002D5D 6F1900000A         */ IL_000d: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002D62 2C1B               */ IL_0012: brfalse.s IL_002f
		/* 0x00002D64 724B030070         */ IL_0014: ldstr ".!" /* 7000034B */
		/* 0x00002D69 06                 */ IL_0019: ldloc.0
		/* 0x00002D6A 6F1A00000A         */ IL_001a: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A00001A */
		/* 0x00002D6F 28A000000A         */ IL_001f: call string [mscorlib]System.String::Concat(string, string) /* 0A0000A0 */
		/* 0x00002D74 0B                 */ IL_0024: stloc.1
		/* 0x00002D75 02                 */ IL_0025: ldarg.0
		/* 0x00002D76 07                 */ IL_0026: ldloc.1
		/* 0x00002D77 14                 */ IL_0027: ldnull
		/* 0x00002D78 16                 */ IL_0028: ldc.i4.0
		/* 0x00002D79 28A100000A         */ IL_0029: call instance bool [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModel::GoToNode(string, string, bool) /* 0A0000A1 */
		/* 0x00002D7E 26                 */ IL_002e: pop
		/* 0x00002D7F 2A                 */ IL_002f: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::grid_RowDoubleClickCommandExecute

	.method /* 06000035 */ public hidebysig specialname 
		instance class [System]System.Windows.Input.ICommand get_cmdExport_Command () cil managed 
	{
		// Method begins at RVA 0x2d8c
		// Header size: 1
		// Code size: 50 (0x32)
		.maxstack 8

		/* 0x00002D8C 02                 */ IL_0000: ldarg.0
		/* 0x00002D8D 7B16000004         */ IL_0001: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdExport_Command /* 04000016 */
		/* 0x00002D92 2D23               */ IL_0006: brtrue.s IL_002b
		/* 0x00002D94 02                 */ IL_0008: ldarg.0
		/* 0x00002D95 02                 */ IL_0009: ldarg.0
		/* 0x00002D96 FE0636000006       */ IL_000a: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::cmdExport_CommandExecute(object) /* 06000036 */
		/* 0x00002D9C 739400000A         */ IL_0010: newobj instance void class [mscorlib]System.Action`1<object>::.ctor(object, native int) /* 0A000094 */
		/* 0x00002DA1 02                 */ IL_0015: ldarg.0
		/* 0x00002DA2 FE0632000006       */ IL_0016: ldftn instance bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::CommandCanExecute(object) /* 06000032 */
		/* 0x00002DA8 739600000A         */ IL_001c: newobj instance void class [mscorlib]System.Func`2<object, bool>::.ctor(object, native int) /* 0A000096 */
		/* 0x00002DAD 739700000A         */ IL_0021: newobj instance void class [AspenTech.Visualisation.Controls.Support.Wpf]AspenTech.Visualisation.Controls.Support.Commands.RelayActionCommand`1<object>::.ctor(class [mscorlib]System.Action`1<!0>, class [mscorlib]System.Func`2<!0, bool>) /* 0A000097 */
		/* 0x00002DB2 7D16000004         */ IL_0026: stfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdExport_Command /* 04000016 */
		/* 0x00002DB7 02                 */ IL_002b: ldarg.0
		/* 0x00002DB8 7B16000004         */ IL_002c: ldfld class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_cmdExport_Command /* 04000016 */
		/* 0x00002DBD 2A                 */ IL_0031: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_cmdExport_Command

	.method /* 06000036 */ private hidebysig 
		instance void cmdExport_CommandExecute (
			object parameter
		) cil managed 
	{
		// Method begins at RVA 0x2dc0
		// Header size: 12
		// Code size: 125 (0x7d)
		.maxstack 8
		.locals /* 1100000F */ init (
			[0] class [mscorlib]System.Collections.Generic.IEnumerator`1<string>,
			[1] string,
			[2] string,
			[3] class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvActionResult,
			[4] class AspenTech.AspenPlus.Happ.IHNode
		)

		/* 0x00002DC0 02                 */ IL_0000: ldarg.0
		/* 0x00002DC1 283A000006         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IEnumerable`1<string> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::GetSelectedIds() /* 0600003A */
		/* 0x00002DC6 6F1D00000A         */ IL_0006: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.Generic.IEnumerable`1<string>::GetEnumerator() /* 0A00001D */
		/* 0x00002DCB 0A                 */ IL_000b: stloc.0
		/* 0x00002DCC 2B5A               */ IL_000c: br.s IL_0068
		/* 0x00002DCE 06                 */ IL_000e: ldloc.0
		/* 0x00002DCF 6F1A00000A         */ IL_000f: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<string>::get_Current() /* 0A00001A */
		/* 0x00002DD4 0B                 */ IL_0014: stloc.1
		/* 0x00002DD5 02                 */ IL_0015: ldarg.0
		/* 0x00002DD6 7217040070         */ IL_0016: ldstr "@main." /* 70000417 */
		/* 0x00002DDB 07                 */ IL_001b: ldloc.1
		/* 0x00002DDC 28A000000A         */ IL_001c: call string [mscorlib]System.String::Concat(string, string) /* 0A0000A0 */
		/* 0x00002DE1 28A200000A         */ IL_0021: call instance string [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::ExpandDataPath(string) /* 0A0000A2 */
		/* 0x00002DE6 0C                 */ IL_0026: stloc.2
		/* 0x00002DE7 02                 */ IL_0027: ldarg.0
		/* 0x00002DE8 7225040070         */ IL_0028: ldstr "Top.appModelV8.Custom Actions" /* 70000425 */
		/* 0x00002DED 7261040070         */ IL_002d: ldstr "HappNode" /* 70000461 */
		/* 0x00002DF2 16                 */ IL_0032: ldc.i4.0
		/* 0x00002DF3 17                 */ IL_0033: ldc.i4.1
		/* 0x00002DF4 8D19000001         */ IL_0034: newarr [mscorlib]System.Object /* 01000019 */
		/* 0x00002DF9 25                 */ IL_0039: dup
		/* 0x00002DFA 16                 */ IL_003a: ldc.i4.0
		/* 0x00002DFB 08                 */ IL_003b: ldloc.2
		/* 0x00002DFC A2                 */ IL_003c: stelem.ref
		/* 0x00002DFD 28B700000A         */ IL_003d: call instance class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvActionResult [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvViewModel::InvokeAction(string, string, bool, object[]) /* 0A0000B7 */
		/* 0x00002E02 0D                 */ IL_0042: stloc.3
		/* 0x00002E03 09                 */ IL_0043: ldloc.3
		/* 0x00002E04 6FB800000A         */ IL_0044: callvirt instance bool [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvActionResult::get_Succeeded() /* 0A0000B8 */
		/* 0x00002E09 2C1D               */ IL_0049: brfalse.s IL_0068
		/* 0x00002E0B 09                 */ IL_004b: ldloc.3
		/* 0x00002E0C 6FB900000A         */ IL_004c: callvirt instance object [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvActionResult::get_Result() /* 0A0000B9 */
		/* 0x00002E11 7509000002         */ IL_0051: isinst AspenTech.AspenPlus.Happ.IHNode /* 02000009 */
		/* 0x00002E16 1304               */ IL_0056: stloc.s 4
		/* 0x00002E18 1104               */ IL_0058: ldloc.s 4
		/* 0x00002E1A 2C0C               */ IL_005a: brfalse.s IL_0068
		/* 0x00002E1C 1104               */ IL_005c: ldloc.s 4
		/* 0x00002E1E 72C5030070         */ IL_005e: ldstr "" /* 700003C5 */
		/* 0x00002E23 6F42000006         */ IL_0063: callvirt instance void AspenTech.AspenPlus.Happ.IHNode::Export(string) /* 06000042 */
		/* 0x00002E28 06                 */ IL_0068: ldloc.0
		/* 0x00002E29 6F1900000A         */ IL_0069: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A000019 */
		/* 0x00002E2E 2D9E               */ IL_006e: brtrue.s IL_000e
		/* 0x00002E30 DE0A               */ IL_0070: leave.s IL_007c
		/* 0x00002E32 06                 */ IL_0072: ldloc.0
		/* 0x00002E33 2C06               */ IL_0073: brfalse.s IL_007b
		/* 0x00002E35 06                 */ IL_0075: ldloc.0
		/* 0x00002E36 6F1800000A         */ IL_0076: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A000018 */
		/* 0x00002E3B DC                 */ IL_007b: endfinally
		/* 0x00002E3C 2A                 */ IL_007c: ret

		.try IL_000c-IL_0072 finally IL_0072-IL_007c
	} // end of method MMFlowsh_ObjMan_ViewModel::cmdExport_CommandExecute

	.method /* 06000037 */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> get_SelectedRowIndexes () cil managed 
	{
		// Method begins at RVA 0x2e5c
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002E5C 02                 */ IL_0000: ldarg.0
		/* 0x00002E5D 7B17000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes /* 04000017 */
		/* 0x00002E62 2A                 */ IL_0006: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes

	.method /* 06000038 */ public hidebysig specialname 
		instance void set_SelectedRowIndexes (
			class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2e64
		// Header size: 12
		// Code size: 70 (0x46)
		.maxstack 3

		/* 0x00002E64 02                 */ IL_0000: ldarg.0
		/* 0x00002E65 7B17000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes /* 04000017 */
		/* 0x00002E6A 2C17               */ IL_0006: brfalse.s IL_001f
		/* 0x00002E6C 02                 */ IL_0008: ldarg.0
		/* 0x00002E6D 7B17000004         */ IL_0009: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes /* 04000017 */
		/* 0x00002E72 02                 */ IL_000e: ldarg.0
		/* 0x00002E73 FE0639000006       */ IL_000f: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes_CollectionChanged(object, class [System]System.Collections.Specialized.NotifyCollectionChangedEventArgs) /* 06000039 */
		/* 0x00002E79 73BA00000A         */ IL_0015: newobj instance void [System]System.Collections.Specialized.NotifyCollectionChangedEventHandler::.ctor(object, native int) /* 0A0000BA */
		/* 0x00002E7E 6FBB00000A         */ IL_001a: callvirt instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<int32>::remove_CollectionChanged(class [System]System.Collections.Specialized.NotifyCollectionChangedEventHandler) /* 0A0000BB */
		/* 0x00002E83 02                 */ IL_001f: ldarg.0
		/* 0x00002E84 03                 */ IL_0020: ldarg.1
		/* 0x00002E85 7D17000004         */ IL_0021: stfld class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes /* 04000017 */
		/* 0x00002E8A 02                 */ IL_0026: ldarg.0
		/* 0x00002E8B 7B17000004         */ IL_0027: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes /* 04000017 */
		/* 0x00002E90 2C17               */ IL_002c: brfalse.s IL_0045
		/* 0x00002E92 02                 */ IL_002e: ldarg.0
		/* 0x00002E93 7B17000004         */ IL_002f: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes /* 04000017 */
		/* 0x00002E98 02                 */ IL_0034: ldarg.0
		/* 0x00002E99 FE0639000006       */ IL_0035: ldftn instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes_CollectionChanged(object, class [System]System.Collections.Specialized.NotifyCollectionChangedEventArgs) /* 06000039 */
		/* 0x00002E9F 73BA00000A         */ IL_003b: newobj instance void [System]System.Collections.Specialized.NotifyCollectionChangedEventHandler::.ctor(object, native int) /* 0A0000BA */
		/* 0x00002EA4 6FBC00000A         */ IL_0040: callvirt instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<int32>::add_CollectionChanged(class [System]System.Collections.Specialized.NotifyCollectionChangedEventHandler) /* 0A0000BC */
		/* 0x00002EA9 2A                 */ IL_0045: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::set_SelectedRowIndexes

	.method /* 06000039 */ private hidebysig 
		instance void _SelectedRowIndexes_CollectionChanged (
			object sender,
			class [System]System.Collections.Specialized.NotifyCollectionChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2eb6
		// Header size: 1
		// Code size: 1 (0x1)
		.maxstack 8

		/* 0x00002EB6 2A                 */ IL_0000: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::_SelectedRowIndexes_CollectionChanged

	.method /* 0600003A */ private hidebysig 
		instance class [mscorlib]System.Collections.Generic.IEnumerable`1<string> GetSelectedIds () cil managed 
	{
		.custom /* 0C000029 */ instance void [mscorlib]System.Runtime.CompilerServices.IteratorStateMachineAttribute::.ctor(class [mscorlib]System.Type) = (
			01 00 55 41 73 70 65 6e 54 65 63 68 2e 41 73 70
			65 6e 50 6c 75 73 2e 4d 4d 46 6f 72 6d 73 2e 46
			6c 6f 77 73 68 65 65 74 2e 4d 4d 46 6c 6f 77 73
			68 5f 4f 62 6a 4d 61 6e 5f 56 69 65 77 4d 6f 64
			65 6c 2b 3c 47 65 74 53 65 6c 65 63 74 65 64 49
			64 73 3e 64 5f 5f 34 30 00 00
		)
		// Method begins at RVA 0x2eb8
		// Header size: 1
		// Code size: 15 (0xf)
		.maxstack 8

		/* 0x00002EB8 1FFE               */ IL_0000: ldc.i4.s -2
		/* 0x00002EBA 736E000006         */ IL_0002: newobj instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::.ctor(int32) /* 0600006E */
		/* 0x00002EBF 25                 */ IL_0007: dup
		/* 0x00002EC0 02                 */ IL_0008: ldarg.0
		/* 0x00002EC1 7D37000004         */ IL_0009: stfld class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/'<GetSelectedIds>d__40'::'<>4__this' /* 04000037 */
		/* 0x00002EC6 2A                 */ IL_000e: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::GetSelectedIds

	.method /* 0600003B */ public hidebysig 
		instance void SetSelectedRowFromScript (
			int32 row
		) cil managed 
	{
		// Method begins at RVA 0x2ec8
		// Header size: 1
		// Code size: 43 (0x2b)
		.maxstack 8

		/* 0x00002EC8 02                 */ IL_0000: ldarg.0
		/* 0x00002EC9 2837000006         */ IL_0001: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002ECE 2D0B               */ IL_0006: brtrue.s IL_0013
		/* 0x00002ED0 02                 */ IL_0008: ldarg.0
		/* 0x00002ED1 73BD00000A         */ IL_0009: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<int32>::.ctor() /* 0A0000BD */
		/* 0x00002ED6 2838000006         */ IL_000e: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::set_SelectedRowIndexes(class [System]System.Collections.ObjectModel.ObservableCollection`1<int32>) /* 06000038 */
		/* 0x00002EDB 02                 */ IL_0013: ldarg.0
		/* 0x00002EDC 2837000006         */ IL_0014: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002EE1 6FBE00000A         */ IL_0019: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::Clear() /* 0A0000BE */
		/* 0x00002EE6 02                 */ IL_001e: ldarg.0
		/* 0x00002EE7 2837000006         */ IL_001f: call instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes() /* 06000037 */
		/* 0x00002EEC 03                 */ IL_0024: ldarg.1
		/* 0x00002EED 6FBF00000A         */ IL_0025: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<int32>::Add(!0) /* 0A0000BF */
		/* 0x00002EF2 2A                 */ IL_002a: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::SetSelectedRowFromScript

	.method /* 0600003C */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x211d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000211D 02                 */ IL_0000: ldarg.0
		/* 0x0000211E 282E00000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPageViewModel::.ctor() /* 0A00002E */
		/* 0x00002123 2A                 */ IL_0006: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::.ctor

	.method /* 0600003D */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2ef4
		// Header size: 12
		// Code size: 99 (0x63)
		.maxstack 7

		/* 0x00002EF4 7273040070         */ IL_0000: ldstr "grdChild_GridData" /* 70000473 */
		/* 0x00002EF9 D007000002         */ IL_0005: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel /* 02000007 */
		/* 0x00002EFE 282F00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002F03 736800000A         */ IL_000f: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::.ctor() /* 0A000068 */
		/* 0x00002F08 25                 */ IL_0014: dup
		/* 0x00002F09 D00E000002         */ IL_0015: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel/grdChild_GridData_ItemTemplate /* 0200000E */
		/* 0x00002F0E 282F00000A         */ IL_001a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002F13 6F6900000A         */ IL_001f: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_ItemType(class [mscorlib]System.Type) /* 0A000069 */
		/* 0x00002F18 25                 */ IL_0024: dup
		/* 0x00002F19 736A00000A         */ IL_0025: newobj instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::.ctor() /* 0A00006A */
		/* 0x00002F1E 25                 */ IL_002a: dup
		/* 0x00002F1F 7251030070         */ IL_002b: ldstr "@main" /* 70000351 */
		/* 0x00002F24 6F6B00000A         */ IL_0030: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_DataPath(string) /* 0A00006B */
		/* 0x00002F29 25                 */ IL_0035: dup
		/* 0x00002F2A 17                 */ IL_0036: ldc.i4.1
		/* 0x00002F2B 6F6C00000A         */ IL_0037: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_UseChildId(bool) /* 0A00006C */
		/* 0x00002F30 25                 */ IL_003c: dup
		/* 0x00002F31 72A4020070         */ IL_003d: ldstr "y" /* 700002A4 */
		/* 0x00002F36 6F6D00000A         */ IL_0042: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase::set_Name(string) /* 0A00006D */
		/* 0x00002F3B 25                 */ IL_0047: dup
		/* 0x00002F3C 16                 */ IL_0048: ldc.i4.0
		/* 0x00002F3D 733F00000A         */ IL_0049: newobj instance void valuetype [mscorlib]System.Nullable`1<bool>::.ctor(!0) /* 0A00003F */
		/* 0x00002F42 6FC000000A         */ IL_004e: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvChildCountIndexBasis::set_ProxyRow(valuetype [mscorlib]System.Nullable`1<bool>) /* 0A0000C0 */
		/* 0x00002F47 6F6E00000A         */ IL_0053: callvirt instance void [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvVectorProperty::set_IndexBasis(class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvIndexBasisBase) /* 0A00006E */
		/* 0x00002F4C 283200000A         */ IL_0058: call class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration::Register(string, class [mscorlib]System.Type, class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyBase) /* 0A000032 */
		/* 0x00002F51 800F000004         */ IL_005d: stsfld class [AspenTech.AspenCxs.CxsViewModel]AspenTech.AspenCxs.CxsViewModel.CxvPropertyDeclaration AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::grdChild_GridData_Property /* 0400000F */
		/* 0x00002F56 2A                 */ IL_0062: ret
	} // end of method MMFlowsh_ObjMan_ViewModel::.cctor

	// Properties
	.property /* 17000006 */ instance object grdChild_GridData()
	{
		.get instance object AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_grdChild_GridData()
	}
	.property /* 17000007 */ instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> cmdAdd_Command()
	{
		.get instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_cmdAdd_Command()
	}
	.property /* 17000008 */ instance class [System]System.Windows.Input.ICommand cmdEdit_Command()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_cmdEdit_Command()
	}
	.property /* 17000009 */ instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> cmdDelete_Command()
	{
		.get instance class [Microsoft.Practices.Composite.Presentation]Microsoft.Practices.Composite.Presentation.Commands.DelegateCommand`1<object> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_cmdDelete_Command()
	}
	.property /* 1700000A */ instance class [System]System.Windows.Input.ICommand cmdRename_Command()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_cmdRename_Command()
	}
	.property /* 1700000B */ instance class [System]System.Windows.Input.ICommand cmdCurrent_Command()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_cmdCurrent_Command()
	}
	.property /* 1700000C */ instance class [System]System.Windows.Input.ICommand grid_RowDoubleClickCommand()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_grid_RowDoubleClickCommand()
	}
	.property /* 1700000D */ instance class [System]System.Windows.Input.ICommand cmdExport_Command()
	{
		.get instance class [System]System.Windows.Input.ICommand AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_cmdExport_Command()
	}
	.property /* 1700000E */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> SelectedRowIndexes()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<int32> AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::get_SelectedRowIndexes()
		.set instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel::set_SelectedRowIndexes(class [System]System.Collections.ObjectModel.ObservableCollection`1<int32>)
	}

} // end of class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel

.class /* 02000008 */ public auto ansi beforefieldinit AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan
	extends [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	.custom /* 0C000016 */ instance void [mscorlib]System.Runtime.InteropServices.ProgIdAttribute::.ctor(string) = (
		01 00 1c 4d 4d 46 6c 6f 77 73 68 46 6f 72 6d 2e
		4d 4d 46 6c 6f 77 73 68 5f 4f 62 6a 4d 61 6e 00 00
	)
	// Fields
	.field /* 04000018 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton cmdAdd
	.field /* 04000019 */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton cmdExport
	.field /* 0400001A */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton cmdEdit
	.field /* 0400001B */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton cmdCurrent
	.field /* 0400001C */ assembly class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaMS grdChild
	.field /* 0400001D */ private bool _contentLoaded

	// Methods
	.method /* 0600003E */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2f63
		// Header size: 1
		// Code size: 29 (0x1d)
		.maxstack 8

		/* 0x00002F63 02                 */ IL_0000: ldarg.0
		/* 0x00002F64 287000000A         */ IL_0001: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMTabPage::.ctor() /* 0A000070 */
		/* 0x00002F69 02                 */ IL_0006: ldarg.0
		/* 0x00002F6A D007000002         */ IL_0007: ldtoken AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan_ViewModel /* 02000007 */
		/* 0x00002F6F 282F00000A         */ IL_000c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00002F */
		/* 0x00002F74 283800000A         */ IL_0011: call instance void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMViewModelContainer::set_ViewModelType(class [mscorlib]System.Type) /* 0A000038 */
		/* 0x00002F79 02                 */ IL_0016: ldarg.0
		/* 0x00002F7A 283F000006         */ IL_0017: call instance void AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::InitializeComponent() /* 0600003F */
		/* 0x00002F7F 2A                 */ IL_001c: ret
	} // end of method MMFlowsh_ObjMan::.ctor

	.method /* 0600003F */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C00002A */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00002B */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x2f84
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] class [System]System.Uri
		)

		/* 0x00002F84 02                 */ IL_0000: ldarg.0
		/* 0x00002F85 7B1D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::_contentLoaded /* 0400001D */
		/* 0x00002F8A 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x00002F8C 2A                 */ IL_0008: ret
		/* 0x00002F8D 02                 */ IL_0009: ldarg.0
		/* 0x00002F8E 17                 */ IL_000a: ldc.i4.1
		/* 0x00002F8F 7D1D000004         */ IL_000b: stfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::_contentLoaded /* 0400001D */
		/* 0x00002F94 7297040070         */ IL_0010: ldstr "/AspenTech.AspenPlus.MMForms.Flowsheet;component/mmflowsh_objman.xaml" /* 70000497 */
		/* 0x00002F99 18                 */ IL_0015: ldc.i4.2
		/* 0x00002F9A 733900000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A000039 */
		/* 0x00002F9F 0A                 */ IL_001b: stloc.0
		/* 0x00002FA0 02                 */ IL_001c: ldarg.0
		/* 0x00002FA1 06                 */ IL_001d: ldloc.0
		/* 0x00002FA2 283A00000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A00003A */
		/* 0x00002FA7 2A                 */ IL_0023: ret
	} // end of method MMFlowsh_ObjMan::InitializeComponent

	.method /* 06000040 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C00002C */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C00002D */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C00002E */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x2fb4
		// Header size: 12
		// Code size: 103 (0x67)
		.maxstack 2

		/* 0x00002FB4 03                 */ IL_0000: ldarg.1
		/* 0x00002FB5 17                 */ IL_0001: ldc.i4.1
		/* 0x00002FB6 59                 */ IL_0002: sub
		/* 0x00002FB7 4505000000         */ IL_0003: switch (
		/*              02000000         */                  IL_001e,
		/*              0F000000         */                  IL_002b,
		/*              1C000000         */                  IL_0038,
		/*              29000000         */                  IL_0045,
		/*              36000000         */                  IL_0052)
		/* 0x00002FD0 2B41               */ IL_001c: br.s IL_005f
		/* 0x00002FD2 02                 */ IL_001e: ldarg.0
		/* 0x00002FD3 04                 */ IL_001f: ldarg.2
		/* 0x00002FD4 7449000001         */ IL_0020: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton /* 01000049 */
		/* 0x00002FD9 7D18000004         */ IL_0025: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::cmdAdd /* 04000018 */
		/* 0x00002FDE 2A                 */ IL_002a: ret
		/* 0x00002FDF 02                 */ IL_002b: ldarg.0
		/* 0x00002FE0 04                 */ IL_002c: ldarg.2
		/* 0x00002FE1 7449000001         */ IL_002d: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton /* 01000049 */
		/* 0x00002FE6 7D19000004         */ IL_0032: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::cmdExport /* 04000019 */
		/* 0x00002FEB 2A                 */ IL_0037: ret
		/* 0x00002FEC 02                 */ IL_0038: ldarg.0
		/* 0x00002FED 04                 */ IL_0039: ldarg.2
		/* 0x00002FEE 7449000001         */ IL_003a: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton /* 01000049 */
		/* 0x00002FF3 7D1A000004         */ IL_003f: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::cmdEdit /* 0400001A */
		/* 0x00002FF8 2A                 */ IL_0044: ret
		/* 0x00002FF9 02                 */ IL_0045: ldarg.0
		/* 0x00002FFA 04                 */ IL_0046: ldarg.2
		/* 0x00002FFB 7449000001         */ IL_0047: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton /* 01000049 */
		/* 0x00003000 7D1B000004         */ IL_004c: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMFlatButton AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::cmdCurrent /* 0400001B */
		/* 0x00003005 2A                 */ IL_0051: ret
		/* 0x00003006 02                 */ IL_0052: ldarg.0
		/* 0x00003007 04                 */ IL_0053: ldarg.2
		/* 0x00003008 744A000001         */ IL_0054: castclass [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaMS /* 0100004A */
		/* 0x0000300D 7D1C000004         */ IL_0059: stfld class [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMScrollAreaMS AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::grdChild /* 0400001C */
		/* 0x00003012 2A                 */ IL_005e: ret
		/* 0x00003013 02                 */ IL_005f: ldarg.0
		/* 0x00003014 17                 */ IL_0060: ldc.i4.1
		/* 0x00003015 7D1D000004         */ IL_0061: stfld bool AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan::_contentLoaded /* 0400001D */
		/* 0x0000301A 2A                 */ IL_0066: ret
	} // end of method MMFlowsh_ObjMan::System.Windows.Markup.IComponentConnector.Connect

} // end of class AspenTech.AspenPlus.MMForms.Flowsheet.MMFlowsh_ObjMan

.class /* 02000009 */ interface public auto ansi abstract import AspenTech.AspenPlus.Happ.IHNode
{
	.custom /* 0C000017 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000018 */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 38 45 35 36 37 35 32 32 2d 46 39 42 41
		2d 31 31 43 46 2d 39 30 42 32 2d 30 30 30 30 43
		30 41 38 31 30 43 34 00 00
	)
	.custom /* 0C000019 */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 06000041 */ public specialname rtspecialname 
		instance void _VtblGap1_51 () runtime managed 
	{
	} // end of method IHNode::_VtblGap1_51

	.method /* 06000042 */ public hidebysig newslot abstract virtual 
		instance void Export (
			[in] [opt] string marshal(bstr) filename
		) runtime managed internalcall 
	{
		.custom /* 0C00002F */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 33 00 02 60 00 00
		)
		.param [1] = ""
	} // end of method IHNode::Export

} // end of class AspenTech.AspenPlus.Happ.IHNode

