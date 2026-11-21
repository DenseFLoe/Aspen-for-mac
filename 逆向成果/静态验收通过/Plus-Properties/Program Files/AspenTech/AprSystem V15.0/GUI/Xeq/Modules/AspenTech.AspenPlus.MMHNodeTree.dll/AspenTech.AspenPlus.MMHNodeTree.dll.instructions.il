.module AspenTech.AspenPlus.MMHNodeTree.dll
// MVID: {50F94724-9D05-45C1-A1F1-22E93C6180A8}
.imagebase 0x10000000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003 // WindowsCui
.corflags 0x00000001 // ILOnly
.class /* 02000001 */ private auto ansi '<Module>'
{
} // end of class <Module>

.class /* 02000002 */ private auto ansi beforefieldinit AspenTech.AspenPlus.MMHNodeTree.Properties.Resources
	extends [mscorlib]System.Object
{
	.custom /* 0C000010 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 33 53 79 73 74 65 6d 2e 52 65 73 6f 75 72
		63 65 73 2e 54 6f 6f 6c 73 2e 53 74 72 6f 6e 67
		6c 79 54 79 70 65 64 52 65 73 6f 75 72 63 65 42
		75 69 6c 64 65 72 08 31 36 2e 30 2e 30 2e 30 00 00
	)
	.custom /* 0C000011 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000012 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	// Fields
	.field /* 04000001 */ private static class [mscorlib]System.Resources.ResourceManager resourceMan
	.field /* 04000002 */ private static class [mscorlib]System.Globalization.CultureInfo resourceCulture

	// Methods
	.method /* 06000001 */ assembly hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002050 02                 */ IL_0000: ldarg.0
		/* 0x00002051 281A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00001A */
		/* 0x00002056 2A                 */ IL_0006: ret
	} // end of method Resources::.ctor

	.method /* 06000002 */ assembly hidebysig specialname static 
		class [mscorlib]System.Resources.ResourceManager get_ResourceManager () cil managed 
	{
		// Method begins at RVA 0x2058
		// Header size: 1
		// Code size: 43 (0x2b)
		.maxstack 8

		/* 0x00002058 7E01000004         */ IL_0000: ldsfld class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceMan /* 04000001 */
		/* 0x0000205D 2D1E               */ IL_0005: brtrue.s IL_0025
		/* 0x0000205F 7201000070         */ IL_0007: ldstr "AspenTech.AspenPlus.MMHNodeTree.Properties.Resources" /* 70000001 */
		/* 0x00002064 D002000002         */ IL_000c: ldtoken AspenTech.AspenPlus.MMHNodeTree.Properties.Resources /* 02000002 */
		/* 0x00002069 281B00000A         */ IL_0011: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00001B */
		/* 0x0000206E 6F1C00000A         */ IL_0016: callvirt instance class [mscorlib]System.Reflection.Assembly [mscorlib]System.Type::get_Assembly() /* 0A00001C */
		/* 0x00002073 731D00000A         */ IL_001b: newobj instance void [mscorlib]System.Resources.ResourceManager::.ctor(string, class [mscorlib]System.Reflection.Assembly) /* 0A00001D */
		/* 0x00002078 8001000004         */ IL_0020: stsfld class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceMan /* 04000001 */
		/* 0x0000207D 7E01000004         */ IL_0025: ldsfld class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceMan /* 04000001 */
		/* 0x00002082 2A                 */ IL_002a: ret
	} // end of method Resources::get_ResourceManager

	.method /* 06000003 */ assembly hidebysig specialname static 
		class [mscorlib]System.Globalization.CultureInfo get_Culture () cil managed 
	{
		// Method begins at RVA 0x2084
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00002084 7E02000004         */ IL_0000: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceCulture /* 04000002 */
		/* 0x00002089 2A                 */ IL_0005: ret
	} // end of method Resources::get_Culture

	.method /* 06000004 */ assembly hidebysig specialname static 
		void set_Culture (
			class [mscorlib]System.Globalization.CultureInfo 'value'
		) cil managed 
	{
		// Method begins at RVA 0x208b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000208B 02                 */ IL_0000: ldarg.0
		/* 0x0000208C 8002000004         */ IL_0001: stsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceCulture /* 04000002 */
		/* 0x00002091 2A                 */ IL_0006: ret
	} // end of method Resources::set_Culture

	.method /* 06000005 */ assembly hidebysig specialname static 
		string get_DataSetText () cil managed 
	{
		// Method begins at RVA 0x2093
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002093 2802000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_ResourceManager() /* 06000002 */
		/* 0x00002098 726B000070         */ IL_0005: ldstr "DataSetText" /* 7000006B */
		/* 0x0000209D 7E02000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceCulture /* 04000002 */
		/* 0x000020A2 6F1E00000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A00001E */
		/* 0x000020A7 2A                 */ IL_0014: ret
	} // end of method Resources::get_DataSetText

	.method /* 06000006 */ assembly hidebysig specialname static 
		string get_MethodText () cil managed 
	{
		// Method begins at RVA 0x20a9
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x000020A9 2802000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_ResourceManager() /* 06000002 */
		/* 0x000020AE 7283000070         */ IL_0005: ldstr "MethodText" /* 70000083 */
		/* 0x000020B3 7E02000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceCulture /* 04000002 */
		/* 0x000020B8 6F1E00000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A00001E */
		/* 0x000020BD 2A                 */ IL_0014: ret
	} // end of method Resources::get_MethodText

	.method /* 06000007 */ assembly hidebysig specialname static 
		string get_ModelText () cil managed 
	{
		// Method begins at RVA 0x20bf
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x000020BF 2802000006         */ IL_0000: call class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_ResourceManager() /* 06000002 */
		/* 0x000020C4 7299000070         */ IL_0005: ldstr "ModelText" /* 70000099 */
		/* 0x000020C9 7E02000004         */ IL_000a: ldsfld class [mscorlib]System.Globalization.CultureInfo AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::resourceCulture /* 04000002 */
		/* 0x000020CE 6F1E00000A         */ IL_000f: callvirt instance string [mscorlib]System.Resources.ResourceManager::GetString(string, class [mscorlib]System.Globalization.CultureInfo) /* 0A00001E */
		/* 0x000020D3 2A                 */ IL_0014: ret
	} // end of method Resources::get_ModelText

	// Properties
	.property /* 17000001 */ class [mscorlib]System.Resources.ResourceManager ResourceManager()
	{
		.custom /* 0C000001 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 02 00 00 00 00 00
		)
		.get class [mscorlib]System.Resources.ResourceManager AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_ResourceManager()
	}
	.property /* 17000002 */ class [mscorlib]System.Globalization.CultureInfo Culture()
	{
		.custom /* 0C000013 */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 02 00 00 00 00 00
		)
		.get class [mscorlib]System.Globalization.CultureInfo AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_Culture()
		.set void AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::set_Culture(class [mscorlib]System.Globalization.CultureInfo)
	}
	.property /* 17000003 */ string DataSetText()
	{
		.get string AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_DataSetText()
	}
	.property /* 17000004 */ string MethodText()
	{
		.get string AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_MethodText()
	}
	.property /* 17000005 */ string ModelText()
	{
		.get string AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_ModelText()
	}

} // end of class AspenTech.AspenPlus.MMHNodeTree.Properties.Resources

.class /* 02000003 */ private auto ansi sealed beforefieldinit AspenTech.AspenPlus.MMHNodeTree.Properties.Settings
	extends [System]System.Configuration.ApplicationSettingsBase
{
	.custom /* 0C000014 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000015 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 4b 4d 69 63 72 6f 73 6f 66 74 2e 56 69 73
		75 61 6c 53 74 75 64 69 6f 2e 45 64 69 74 6f 72
		73 2e 53 65 74 74 69 6e 67 73 44 65 73 69 67 6e
		65 72 2e 53 65 74 74 69 6e 67 73 53 69 6e 67 6c
		65 46 69 6c 65 47 65 6e 65 72 61 74 6f 72 09 31
		36 2e 31 30 2e 30 2e 30 00 00
	)
	// Fields
	.field /* 04000003 */ private static class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings defaultInstance

	// Methods
	.method /* 06000008 */ public hidebysig specialname static 
		class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings get_Default () cil managed 
	{
		// Method begins at RVA 0x20d5
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x000020D5 7E03000004         */ IL_0000: ldsfld class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings AspenTech.AspenPlus.MMHNodeTree.Properties.Settings::defaultInstance /* 04000003 */
		/* 0x000020DA 2A                 */ IL_0005: ret
	} // end of method Settings::get_Default

	.method /* 06000009 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x20dc
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000020DC 02                 */ IL_0000: ldarg.0
		/* 0x000020DD 281F00000A         */ IL_0001: call instance void [System]System.Configuration.ApplicationSettingsBase::.ctor() /* 0A00001F */
		/* 0x000020E2 2A                 */ IL_0006: ret
	} // end of method Settings::.ctor

	.method /* 0600000A */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x20e4
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x000020E4 7309000006         */ IL_0000: newobj instance void AspenTech.AspenPlus.MMHNodeTree.Properties.Settings::.ctor() /* 06000009 */
		/* 0x000020E9 282000000A         */ IL_0005: call class [System]System.Configuration.SettingsBase [System]System.Configuration.SettingsBase::Synchronized(class [System]System.Configuration.SettingsBase) /* 0A000020 */
		/* 0x000020EE 7403000002         */ IL_000a: castclass AspenTech.AspenPlus.MMHNodeTree.Properties.Settings /* 02000003 */
		/* 0x000020F3 8003000004         */ IL_000f: stsfld class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings AspenTech.AspenPlus.MMHNodeTree.Properties.Settings::defaultInstance /* 04000003 */
		/* 0x000020F8 2A                 */ IL_0014: ret
	} // end of method Settings::.cctor

	// Properties
	.property /* 17000006 */ class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings Default()
	{
		.get class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings AspenTech.AspenPlus.MMHNodeTree.Properties.Settings::get_Default()
	}

} // end of class AspenTech.AspenPlus.MMHNodeTree.Properties.Settings

.class /* 02000004 */ public auto ansi beforefieldinit AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 04000004 */ private class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> _rootNode
	.field /* 04000005 */ private string '<Prompt>k__BackingField'
	.custom /* 0C000016 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000006 */ private bool '<ExpandOnBuild>k__BackingField'
	.custom /* 0C000017 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000007 */ private class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode _selection
	.field /* 04000008 */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C000019 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600000B */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002050 02                 */ IL_0000: ldarg.0
		/* 0x00002051 281A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00001A */
		/* 0x00002056 2A                 */ IL_0006: ret
	} // end of method NodeTree_ViewModel::.ctor

	.method /* 0600000C */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> get_RootNode () cil managed 
	{
		// Method begins at RVA 0x20fa
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000020FA 02                 */ IL_0000: ldarg.0
		/* 0x000020FB 7B04000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::_rootNode /* 04000004 */
		/* 0x00002100 2A                 */ IL_0006: ret
	} // end of method NodeTree_ViewModel::get_RootNode

	.method /* 0600000D */ public hidebysig specialname 
		instance string get_Prompt () cil managed 
	{
		.custom /* 0C000024 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2102
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002102 02                 */ IL_0000: ldarg.0
		/* 0x00002103 7B05000004         */ IL_0001: ldfld string AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::'<Prompt>k__BackingField' /* 04000005 */
		/* 0x00002108 2A                 */ IL_0006: ret
	} // end of method NodeTree_ViewModel::get_Prompt

	.method /* 0600000E */ private hidebysig specialname 
		instance void set_Prompt (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000025 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x210a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000210A 02                 */ IL_0000: ldarg.0
		/* 0x0000210B 03                 */ IL_0001: ldarg.1
		/* 0x0000210C 7D05000004         */ IL_0002: stfld string AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::'<Prompt>k__BackingField' /* 04000005 */
		/* 0x00002111 2A                 */ IL_0007: ret
	} // end of method NodeTree_ViewModel::set_Prompt

	.method /* 0600000F */ public hidebysig 
		instance void Initialize (
			object root,
			bool expandOnBuild
		) cil managed 
	{
		// Method begins at RVA 0x2114
		// Header size: 12
		// Code size: 73 (0x49)
		.maxstack 4

		/* 0x00002114 02                 */ IL_0000: ldarg.0
		/* 0x00002115 04                 */ IL_0001: ldarg.2
		/* 0x00002116 2811000006         */ IL_0002: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::set_ExpandOnBuild(bool) /* 06000011 */
		/* 0x0000211B 02                 */ IL_0007: ldarg.0
		/* 0x0000211C 732100000A         */ IL_0008: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode>::.ctor() /* 0A000021 */
		/* 0x00002121 7D04000004         */ IL_000d: stfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::_rootNode /* 04000004 */
		/* 0x00002126 02                 */ IL_0012: ldarg.0
		/* 0x00002127 7B04000004         */ IL_0013: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::_rootNode /* 04000004 */
		/* 0x0000212C 03                 */ IL_0018: ldarg.1
		/* 0x0000212D 7509000002         */ IL_0019: isinst AspenTech.AspenPlus.Happ.IHNode /* 02000009 */
		/* 0x00002132 02                 */ IL_001e: ldarg.0
		/* 0x00002133 17                 */ IL_001f: ldc.i4.1
		/* 0x00002134 7329000006         */ IL_0020: newobj instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::.ctor(class AspenTech.AspenPlus.Happ.IHNode, class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel, bool) /* 06000029 */
		/* 0x00002139 6F2200000A         */ IL_0025: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode>::Add(!0) /* 0A000022 */
		/* 0x0000213E 02                 */ IL_002a: ldarg.0
		/* 0x0000213F 7B08000004         */ IL_002b: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x00002144 2C16               */ IL_0030: brfalse.s IL_0048
		/* 0x00002146 02                 */ IL_0032: ldarg.0
		/* 0x00002147 7B08000004         */ IL_0033: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x0000214C 02                 */ IL_0038: ldarg.0
		/* 0x0000214D 72AD000070         */ IL_0039: ldstr "RootNode" /* 700000AD */
		/* 0x00002152 732300000A         */ IL_003e: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000023 */
		/* 0x00002157 6F2400000A         */ IL_0043: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000024 */
		/* 0x0000215C 2A                 */ IL_0048: ret
	} // end of method NodeTree_ViewModel::Initialize

	.method /* 06000010 */ public hidebysig specialname 
		instance bool get_ExpandOnBuild () cil managed 
	{
		.custom /* 0C000027 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2169
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002169 02                 */ IL_0000: ldarg.0
		/* 0x0000216A 7B06000004         */ IL_0001: ldfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::'<ExpandOnBuild>k__BackingField' /* 04000006 */
		/* 0x0000216F 2A                 */ IL_0006: ret
	} // end of method NodeTree_ViewModel::get_ExpandOnBuild

	.method /* 06000011 */ private hidebysig specialname 
		instance void set_ExpandOnBuild (
			bool 'value'
		) cil managed 
	{
		.custom /* 0C000028 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2171
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002171 02                 */ IL_0000: ldarg.0
		/* 0x00002172 03                 */ IL_0001: ldarg.1
		/* 0x00002173 7D06000004         */ IL_0002: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::'<ExpandOnBuild>k__BackingField' /* 04000006 */
		/* 0x00002178 2A                 */ IL_0007: ret
	} // end of method NodeTree_ViewModel::set_ExpandOnBuild

	.method /* 06000012 */ assembly hidebysig specialname 
		instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode get_Selection () cil managed 
	{
		// Method begins at RVA 0x217a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000217A 02                 */ IL_0000: ldarg.0
		/* 0x0000217B 7B07000004         */ IL_0001: ldfld class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::_selection /* 04000007 */
		/* 0x00002180 2A                 */ IL_0006: ret
	} // end of method NodeTree_ViewModel::get_Selection

	.method /* 06000013 */ assembly hidebysig specialname 
		instance void set_Selection (
			class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2182
		// Header size: 1
		// Code size: 47 (0x2f)
		.maxstack 8

		/* 0x00002182 02                 */ IL_0000: ldarg.0
		/* 0x00002183 03                 */ IL_0001: ldarg.1
		/* 0x00002184 7D07000004         */ IL_0002: stfld class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::_selection /* 04000007 */
		/* 0x00002189 02                 */ IL_0007: ldarg.0
		/* 0x0000218A 02                 */ IL_0008: ldarg.0
		/* 0x0000218B 7B07000004         */ IL_0009: ldfld class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::_selection /* 04000007 */
		/* 0x00002190 6F35000006         */ IL_000e: callvirt instance string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_Prompt() /* 06000035 */
		/* 0x00002195 280E000006         */ IL_0013: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::set_Prompt(string) /* 0600000E */
		/* 0x0000219A 02                 */ IL_0018: ldarg.0
		/* 0x0000219B 7B08000004         */ IL_0019: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x000021A0 02                 */ IL_001e: ldarg.0
		/* 0x000021A1 72BF000070         */ IL_001f: ldstr "Prompt" /* 700000BF */
		/* 0x000021A6 732300000A         */ IL_0024: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000023 */
		/* 0x000021AB 6F2400000A         */ IL_0029: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000024 */
		/* 0x000021B0 2A                 */ IL_002e: ret
	} // end of method NodeTree_ViewModel::set_Selection

	.method /* 06000014 */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00002A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x21b4
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000001 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000021B4 02                 */ IL_0000: ldarg.0
		/* 0x000021B5 7B08000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x000021BA 0A                 */ IL_0006: stloc.0
		/* 0x000021BB 06                 */ IL_0007: ldloc.0
		/* 0x000021BC 0B                 */ IL_0008: stloc.1
		/* 0x000021BD 07                 */ IL_0009: ldloc.1
		/* 0x000021BE 03                 */ IL_000a: ldarg.1
		/* 0x000021BF 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x000021C4 741B000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 0100001B */
		/* 0x000021C9 0C                 */ IL_0015: stloc.2
		/* 0x000021CA 02                 */ IL_0016: ldarg.0
		/* 0x000021CB 7C08000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x000021D0 08                 */ IL_001c: ldloc.2
		/* 0x000021D1 07                 */ IL_001d: ldloc.1
		/* 0x000021D2 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x000021D7 0A                 */ IL_0023: stloc.0
		/* 0x000021D8 06                 */ IL_0024: ldloc.0
		/* 0x000021D9 07                 */ IL_0025: ldloc.1
		/* 0x000021DA 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x000021DC 2A                 */ IL_0028: ret
	} // end of method NodeTree_ViewModel::add_PropertyChanged

	.method /* 06000015 */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00002B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x21ec
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000001 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000021EC 02                 */ IL_0000: ldarg.0
		/* 0x000021ED 7B08000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x000021F2 0A                 */ IL_0006: stloc.0
		/* 0x000021F3 06                 */ IL_0007: ldloc.0
		/* 0x000021F4 0B                 */ IL_0008: stloc.1
		/* 0x000021F5 07                 */ IL_0009: ldloc.1
		/* 0x000021F6 03                 */ IL_000a: ldarg.1
		/* 0x000021F7 282700000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000027 */
		/* 0x000021FC 741B000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 0100001B */
		/* 0x00002201 0C                 */ IL_0015: stloc.2
		/* 0x00002202 02                 */ IL_0016: ldarg.0
		/* 0x00002203 7C08000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::PropertyChanged /* 04000008 */
		/* 0x00002208 08                 */ IL_001c: ldloc.2
		/* 0x00002209 07                 */ IL_001d: ldloc.1
		/* 0x0000220A 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x0000220F 0A                 */ IL_0023: stloc.0
		/* 0x00002210 06                 */ IL_0024: ldloc.0
		/* 0x00002211 07                 */ IL_0025: ldloc.1
		/* 0x00002212 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002214 2A                 */ IL_0028: ret
	} // end of method NodeTree_ViewModel::remove_PropertyChanged

	// Events
	.event /* 14000001 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 17000007 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> RootNode()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::get_RootNode()
	}
	.property /* 17000008 */ instance string Prompt()
	{
		.get instance string AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::get_Prompt()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::set_Prompt(string)
	}
	.property /* 17000009 */ instance bool ExpandOnBuild()
	{
		.get instance bool AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::get_ExpandOnBuild()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::set_ExpandOnBuild(bool)
	}
	.property /* 1700000A */ instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode Selection()
	{
		.get instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::get_Selection()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::set_Selection(class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode)
	}

} // end of class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel

.class /* 02000005 */ public auto ansi beforefieldinit AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl
	extends [PresentationFramework]System.Windows.Controls.UserControl
	implements [System.Xaml]System.Windows.Markup.IComponentConnector
{
	// Fields
	.field /* 04000009 */ public static class [WindowsBase]System.Windows.DependencyProperty ViewModelProperty
	.field /* 0400000A */ private object _rootNode
	.field /* 0400000B */ private bool '<ExpandOnBuild>k__BackingField'
	.custom /* 0C000021 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000C */ private class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer '<UnityContainer>k__BackingField'
	.custom /* 0C000023 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400000D */ assembly class [PresentationFramework]System.Windows.Controls.TreeView nodeTree
	.field /* 0400000E */ assembly class [PresentationFramework]System.Windows.Controls.TextBlock Prompt
	.field /* 0400000F */ private bool _contentLoaded

	// Methods
	.method /* 06000016 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2221
		// Header size: 1
		// Code size: 20 (0x14)
		.maxstack 8

		/* 0x00002221 02                 */ IL_0000: ldarg.0
		/* 0x00002222 282800000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.UserControl::.ctor() /* 0A000028 */
		/* 0x00002227 02                 */ IL_0006: ldarg.0
		/* 0x00002228 17                 */ IL_0007: ldc.i4.1
		/* 0x00002229 281D000006         */ IL_0008: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::set_ExpandOnBuild(bool) /* 0600001D */
		/* 0x0000222E 02                 */ IL_000d: ldarg.0
		/* 0x0000222F 2822000006         */ IL_000e: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::InitializeComponent() /* 06000022 */
		/* 0x00002234 2A                 */ IL_0013: ret
	} // end of method NodeTreeControl::.ctor

	.method /* 06000017 */ public hidebysig specialname 
		instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel get_ViewModel () cil managed 
	{
		// Method begins at RVA 0x2236
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002236 02                 */ IL_0000: ldarg.0
		/* 0x00002237 7E09000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::ViewModelProperty /* 04000009 */
		/* 0x0000223C 282900000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000029 */
		/* 0x00002241 7504000002         */ IL_000b: isinst AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel /* 02000004 */
		/* 0x00002246 2A                 */ IL_0010: ret
	} // end of method NodeTreeControl::get_ViewModel

	.method /* 06000018 */ public hidebysig specialname 
		instance void set_ViewModel (
			class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2248
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002248 02                 */ IL_0000: ldarg.0
		/* 0x00002249 7E09000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::ViewModelProperty /* 04000009 */
		/* 0x0000224E 03                 */ IL_0006: ldarg.1
		/* 0x0000224F 282A00000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A00002A */
		/* 0x00002254 2A                 */ IL_000c: ret
	} // end of method NodeTreeControl::set_ViewModel

	.method /* 06000019 */ private hidebysig static 
		void OnViewModelPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs args
		) cil managed 
	{
		// Method begins at RVA 0x2258
		// Header size: 12
		// Code size: 30 (0x1e)
		.maxstack 2
		.locals /* 11000002 */ init (
			[0] class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl
		)

		/* 0x00002258 02                 */ IL_0000: ldarg.0
		/* 0x00002259 7505000002         */ IL_0001: isinst AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl /* 02000005 */
		/* 0x0000225E 0A                 */ IL_0006: stloc.0
		/* 0x0000225F 0F01               */ IL_0007: ldarga.s args
		/* 0x00002261 282B00000A         */ IL_0009: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00002B */
		/* 0x00002266 2C0D               */ IL_000e: brfalse.s IL_001d
		/* 0x00002268 06                 */ IL_0010: ldloc.0
		/* 0x00002269 0F01               */ IL_0011: ldarga.s args
		/* 0x0000226B 282B00000A         */ IL_0013: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00002B */
		/* 0x00002270 6F2C00000A         */ IL_0018: callvirt instance void [PresentationFramework]System.Windows.FrameworkElement::set_DataContext(object) /* 0A00002C */
		/* 0x00002275 2A                 */ IL_001d: ret
	} // end of method NodeTreeControl::OnViewModelPropertyChanged

	.method /* 0600001A */ public hidebysig specialname 
		instance object get_RootNode () cil managed 
	{
		// Method begins at RVA 0x2282
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002282 02                 */ IL_0000: ldarg.0
		/* 0x00002283 7B0A000004         */ IL_0001: ldfld object AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_rootNode /* 0400000A */
		/* 0x00002288 2A                 */ IL_0006: ret
	} // end of method NodeTreeControl::get_RootNode

	.method /* 0600001B */ public hidebysig specialname 
		instance void set_RootNode (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x228a
		// Header size: 1
		// Code size: 39 (0x27)
		.maxstack 8

		/* 0x0000228A 02                 */ IL_0000: ldarg.0
		/* 0x0000228B 03                 */ IL_0001: ldarg.1
		/* 0x0000228C 7D0A000004         */ IL_0002: stfld object AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_rootNode /* 0400000A */
		/* 0x00002291 02                 */ IL_0007: ldarg.0
		/* 0x00002292 7B0A000004         */ IL_0008: ldfld object AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_rootNode /* 0400000A */
		/* 0x00002297 2C17               */ IL_000d: brfalse.s IL_0026
		/* 0x00002299 02                 */ IL_000f: ldarg.0
		/* 0x0000229A 2817000006         */ IL_0010: call instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::get_ViewModel() /* 06000017 */
		/* 0x0000229F 02                 */ IL_0015: ldarg.0
		/* 0x000022A0 7B0A000004         */ IL_0016: ldfld object AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_rootNode /* 0400000A */
		/* 0x000022A5 02                 */ IL_001b: ldarg.0
		/* 0x000022A6 281C000006         */ IL_001c: call instance bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::get_ExpandOnBuild() /* 0600001C */
		/* 0x000022AB 6F0F000006         */ IL_0021: callvirt instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::Initialize(object, bool) /* 0600000F */
		/* 0x000022B0 2A                 */ IL_0026: ret
	} // end of method NodeTreeControl::set_RootNode

	.method /* 0600001C */ public hidebysig specialname 
		instance bool get_ExpandOnBuild () cil managed 
	{
		.custom /* 0C000032 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x22b2
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000022B2 02                 */ IL_0000: ldarg.0
		/* 0x000022B3 7B0B000004         */ IL_0001: ldfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::'<ExpandOnBuild>k__BackingField' /* 0400000B */
		/* 0x000022B8 2A                 */ IL_0006: ret
	} // end of method NodeTreeControl::get_ExpandOnBuild

	.method /* 0600001D */ public hidebysig specialname 
		instance void set_ExpandOnBuild (
			bool 'value'
		) cil managed 
	{
		.custom /* 0C000033 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x22ba
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000022BA 02                 */ IL_0000: ldarg.0
		/* 0x000022BB 03                 */ IL_0001: ldarg.1
		/* 0x000022BC 7D0B000004         */ IL_0002: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::'<ExpandOnBuild>k__BackingField' /* 0400000B */
		/* 0x000022C1 2A                 */ IL_0007: ret
	} // end of method NodeTreeControl::set_ExpandOnBuild

	.method /* 0600001E */ public hidebysig specialname 
		instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer get_UnityContainer () cil managed 
	{
		.custom /* 0C000034 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x22c3
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000022C3 02                 */ IL_0000: ldarg.0
		/* 0x000022C4 7B0C000004         */ IL_0001: ldfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::'<UnityContainer>k__BackingField' /* 0400000C */
		/* 0x000022C9 2A                 */ IL_0006: ret
	} // end of method NodeTreeControl::get_UnityContainer

	.method /* 0600001F */ public hidebysig specialname 
		instance void set_UnityContainer (
			class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer 'value'
		) cil managed 
	{
		.custom /* 0C000035 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x22cb
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000022CB 02                 */ IL_0000: ldarg.0
		/* 0x000022CC 03                 */ IL_0001: ldarg.1
		/* 0x000022CD 7D0C000004         */ IL_0002: stfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::'<UnityContainer>k__BackingField' /* 0400000C */
		/* 0x000022D2 2A                 */ IL_0007: ret
	} // end of method NodeTreeControl::set_UnityContainer

	.method /* 06000020 */ private hidebysig 
		instance void UserControl_PreviewMouseDown (
			object sender,
			class [PresentationCore]System.Windows.Input.MouseButtonEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x22d4
		// Header size: 1
		// Code size: 1 (0x1)
		.maxstack 8

		/* 0x000022D4 2A                 */ IL_0000: ret
	} // end of method NodeTreeControl::UserControl_PreviewMouseDown

	.method /* 06000021 */ private hidebysig 
		instance void nodeTree_PreviewMouseDown (
			object sender,
			class [PresentationCore]System.Windows.Input.MouseButtonEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x22d4
		// Header size: 1
		// Code size: 1 (0x1)
		.maxstack 8

		/* 0x000022D4 2A                 */ IL_0000: ret
	} // end of method NodeTreeControl::nodeTree_PreviewMouseDown

	.method /* 06000022 */ public final hidebysig newslot virtual 
		instance void InitializeComponent () cil managed 
	{
		.custom /* 0C000036 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000037 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		// Method begins at RVA 0x22d8
		// Header size: 12
		// Code size: 36 (0x24)
		.maxstack 2
		.locals /* 11000003 */ init (
			[0] class [System]System.Uri
		)

		/* 0x000022D8 02                 */ IL_0000: ldarg.0
		/* 0x000022D9 7B0F000004         */ IL_0001: ldfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_contentLoaded /* 0400000F */
		/* 0x000022DE 2C01               */ IL_0006: brfalse.s IL_0009
		/* 0x000022E0 2A                 */ IL_0008: ret
		/* 0x000022E1 02                 */ IL_0009: ldarg.0
		/* 0x000022E2 17                 */ IL_000a: ldc.i4.1
		/* 0x000022E3 7D0F000004         */ IL_000b: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_contentLoaded /* 0400000F */
		/* 0x000022E8 72CD000070         */ IL_0010: ldstr "/AspenTech.AspenPlus.MMHNodeTree;component/nodetree.xaml" /* 700000CD */
		/* 0x000022ED 18                 */ IL_0015: ldc.i4.2
		/* 0x000022EE 732D00000A         */ IL_0016: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00002D */
		/* 0x000022F3 0A                 */ IL_001b: stloc.0
		/* 0x000022F4 02                 */ IL_001c: ldarg.0
		/* 0x000022F5 06                 */ IL_001d: ldloc.0
		/* 0x000022F6 282E00000A         */ IL_001e: call void [PresentationFramework]System.Windows.Application::LoadComponent(object, class [System]System.Uri) /* 0A00002E */
		/* 0x000022FB 2A                 */ IL_0023: ret
	} // end of method NodeTreeControl::InitializeComponent

	.method /* 06000023 */ private final hidebysig newslot virtual 
		instance void System.Windows.Markup.IComponentConnector.Connect (
			int32 connectionId,
			object target
		) cil managed 
	{
		.custom /* 0C000038 */ instance void [mscorlib]System.Diagnostics.DebuggerNonUserCodeAttribute::.ctor() = (
			01 00 00 00
		)
		.custom /* 0C000039 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
			01 00 16 50 72 65 73 65 6e 74 61 74 69 6f 6e 42
			75 69 6c 64 54 61 73 6b 73 07 34 2e 30 2e 30 2e
			30 00 00
		)
		.custom /* 0C00003A */ instance void [System]System.ComponentModel.EditorBrowsableAttribute::.ctor(valuetype [System]System.ComponentModel.EditorBrowsableState) = (
			01 00 01 00 00 00 00 00
		)
		.override method instance void [System.Xaml]System.Windows.Markup.IComponentConnector::Connect(int32, object)
		// Method begins at RVA 0x2308
		// Header size: 12
		// Code size: 80 (0x50)
		.maxstack 3

		/* 0x00002308 03                 */ IL_0000: ldarg.1
		/* 0x00002309 17                 */ IL_0001: ldc.i4.1
		/* 0x0000230A 59                 */ IL_0002: sub
		/* 0x0000230B 4503000000         */ IL_0003: switch (
		/*              02000000         */                  IL_0016,
		/*              1A000000         */                  IL_002e,
		/*              27000000         */                  IL_003b)
		/* 0x0000231C 2B32               */ IL_0014: br.s IL_0048
		/* 0x0000231E 04                 */ IL_0016: ldarg.2
		/* 0x0000231F 7405000002         */ IL_0017: castclass AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl /* 02000005 */
		/* 0x00002324 02                 */ IL_001c: ldarg.0
		/* 0x00002325 FE0620000006       */ IL_001d: ldftn instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::UserControl_PreviewMouseDown(object, class [PresentationCore]System.Windows.Input.MouseButtonEventArgs) /* 06000020 */
		/* 0x0000232B 732F00000A         */ IL_0023: newobj instance void [PresentationCore]System.Windows.Input.MouseButtonEventHandler::.ctor(object, native int) /* 0A00002F */
		/* 0x00002330 6F3000000A         */ IL_0028: callvirt instance void [PresentationCore]System.Windows.UIElement::add_PreviewMouseDown(class [PresentationCore]System.Windows.Input.MouseButtonEventHandler) /* 0A000030 */
		/* 0x00002335 2A                 */ IL_002d: ret
		/* 0x00002336 02                 */ IL_002e: ldarg.0
		/* 0x00002337 04                 */ IL_002f: ldarg.2
		/* 0x00002338 7421000001         */ IL_0030: castclass [PresentationFramework]System.Windows.Controls.TreeView /* 01000021 */
		/* 0x0000233D 7D0D000004         */ IL_0035: stfld class [PresentationFramework]System.Windows.Controls.TreeView AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::nodeTree /* 0400000D */
		/* 0x00002342 2A                 */ IL_003a: ret
		/* 0x00002343 02                 */ IL_003b: ldarg.0
		/* 0x00002344 04                 */ IL_003c: ldarg.2
		/* 0x00002345 7422000001         */ IL_003d: castclass [PresentationFramework]System.Windows.Controls.TextBlock /* 01000022 */
		/* 0x0000234A 7D0E000004         */ IL_0042: stfld class [PresentationFramework]System.Windows.Controls.TextBlock AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::Prompt /* 0400000E */
		/* 0x0000234F 2A                 */ IL_0047: ret
		/* 0x00002350 02                 */ IL_0048: ldarg.0
		/* 0x00002351 17                 */ IL_0049: ldc.i4.1
		/* 0x00002352 7D0F000004         */ IL_004a: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::_contentLoaded /* 0400000F */
		/* 0x00002357 2A                 */ IL_004f: ret
	} // end of method NodeTreeControl::System.Windows.Markup.IComponentConnector.Connect

	.method /* 06000024 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2364
		// Header size: 1
		// Code size: 54 (0x36)
		.maxstack 8

		/* 0x00002364 723F010070         */ IL_0000: ldstr "ViewModel" /* 7000013F */
		/* 0x00002369 D004000002         */ IL_0005: ldtoken AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel /* 02000004 */
		/* 0x0000236E 281B00000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00001B */
		/* 0x00002373 D005000002         */ IL_000f: ldtoken AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl /* 02000005 */
		/* 0x00002378 281B00000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00001B */
		/* 0x0000237D 14                 */ IL_0019: ldnull
		/* 0x0000237E 14                 */ IL_001a: ldnull
		/* 0x0000237F FE0619000006       */ IL_001b: ldftn void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::OnViewModelPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 06000019 */
		/* 0x00002385 733100000A         */ IL_0021: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000031 */
		/* 0x0000238A 733200000A         */ IL_0026: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000032 */
		/* 0x0000238F 283300000A         */ IL_002b: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000033 */
		/* 0x00002394 8009000004         */ IL_0030: stsfld class [WindowsBase]System.Windows.DependencyProperty AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::ViewModelProperty /* 04000009 */
		/* 0x00002399 2A                 */ IL_0035: ret
	} // end of method NodeTreeControl::.cctor

	// Properties
	.property /* 1700000B */ instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel ViewModel()
	{
		.custom /* 0C000022 */ instance void [Microsoft.Practices.Unity]Microsoft.Practices.Unity.DependencyAttribute::.ctor() = (
			01 00 00 00
		)
		.get instance class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::get_ViewModel()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::set_ViewModel(class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel)
	}
	.property /* 1700000C */ instance object RootNode()
	{
		.get instance object AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::get_RootNode()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::set_RootNode(object)
	}
	.property /* 1700000D */ instance bool ExpandOnBuild()
	{
		.get instance bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::get_ExpandOnBuild()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::set_ExpandOnBuild(bool)
	}
	.property /* 1700000E */ instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer UnityContainer()
	{
		.custom /* 0C000026 */ instance void [Microsoft.Practices.Unity]Microsoft.Practices.Unity.DependencyAttribute::.ctor() = (
			01 00 00 00
		)
		.get instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::get_UnityContainer()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl::set_UnityContainer(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer)
	}

} // end of class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl

.class /* 02000006 */ public auto ansi beforefieldinit AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule
	extends [mscorlib]System.Object
	implements [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Modularity.IModule
{
	.custom /* 0C000018 */ instance void [Microsoft.Practices.Composite]Microsoft.Practices.Composite.Modularity.ModuleAttribute::.ctor() = (
		01 00 01 00 54 0e 0a 4d 6f 64 75 6c 65 4e 61 6d
		65 1e 41 73 70 65 6e 54 65 63 68 2e 41 73 70 65
		6e 50 6c 75 73 2e 4d 4d 4e 6f 64 65 54 72 65 65
	)
	// Fields
	.field /* 04000010 */ public static literal string MMNodeTreeModuleName = "AspenTech.AspenPlus.MMNodeTree"
	.field /* 04000011 */ private class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer '<Container>k__BackingField'
	.custom /* 0C000029 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000025 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer container
		) cil managed 
	{
		// Method begins at RVA 0x239b
		// Header size: 1
		// Code size: 14 (0xe)
		.maxstack 8

		/* 0x0000239B 02                 */ IL_0000: ldarg.0
		/* 0x0000239C 281A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00001A */
		/* 0x000023A1 02                 */ IL_0006: ldarg.0
		/* 0x000023A2 03                 */ IL_0007: ldarg.1
		/* 0x000023A3 2827000006         */ IL_0008: call instance void AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule::set_Container(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer) /* 06000027 */
		/* 0x000023A8 2A                 */ IL_000d: ret
	} // end of method MMNodeTreeModule::.ctor

	.method /* 06000026 */ public hidebysig specialname 
		instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer get_Container () cil managed 
	{
		.custom /* 0C00003B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23aa
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000023AA 02                 */ IL_0000: ldarg.0
		/* 0x000023AB 7B11000004         */ IL_0001: ldfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule::'<Container>k__BackingField' /* 04000011 */
		/* 0x000023B0 2A                 */ IL_0006: ret
	} // end of method MMNodeTreeModule::get_Container

	.method /* 06000027 */ private hidebysig specialname 
		instance void set_Container (
			class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer 'value'
		) cil managed 
	{
		.custom /* 0C00003C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x23b2
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000023B2 02                 */ IL_0000: ldarg.0
		/* 0x000023B3 03                 */ IL_0001: ldarg.1
		/* 0x000023B4 7D11000004         */ IL_0002: stfld class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule::'<Container>k__BackingField' /* 04000011 */
		/* 0x000023B9 2A                 */ IL_0007: ret
	} // end of method MMNodeTreeModule::set_Container

	.method /* 06000028 */ public final hidebysig newslot virtual 
		instance void Initialize () cil managed 
	{
		// Method begins at RVA 0x23bb
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000023BB 02                 */ IL_0000: ldarg.0
		/* 0x000023BC 2826000006         */ IL_0001: call instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule::get_Container() /* 06000026 */
		/* 0x000023C1 7253010070         */ IL_0006: ldstr "MMNodeTree" /* 70000153 */
		/* 0x000023C6 733400000A         */ IL_000b: newobj instance void [Microsoft.Practices.Unity]Microsoft.Practices.Unity.TransientLifetimeManager::.ctor() /* 0A000034 */
		/* 0x000023CB 280200002B         */ IL_0010: call !!0[] [mscorlib]System.Array::Empty<class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.InjectionMember>() /* 2B000002 */
		/* 0x000023D0 280300002B         */ IL_0015: call class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer [Microsoft.Practices.Unity]Microsoft.Practices.Unity.UnityContainerExtensions::RegisterType<class [PresentationFramework]System.Windows.Controls.UserControl, class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeControl>(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer, string, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.LifetimeManager, class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.InjectionMember[]) /* 2B000003 */
		/* 0x000023D5 26                 */ IL_001a: pop
		/* 0x000023D6 2A                 */ IL_001b: ret
	} // end of method MMNodeTreeModule::Initialize

	// Properties
	.property /* 1700000F */ instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer Container()
	{
		.get instance class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule::get_Container()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule::set_Container(class [Microsoft.Practices.Unity]Microsoft.Practices.Unity.IUnityContainer)
	}

} // end of class AsepnTech.AspenPlus.MMHNodeTree.MMNodeTreeModule

.class /* 02000007 */ public auto ansi beforefieldinit AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged,
	           [mscorlib]System.IDisposable
{
	// Fields
	.field /* 04000012 */ private class AspenTech.AspenPlus.Happ.IHNode _node
	.field /* 04000013 */ private class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> _children
	.field /* 04000014 */ private class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel _tree
	.field /* 04000015 */ private bool _isExpanded
	.field /* 04000016 */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C00002C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000017 */ private string _text
	.field /* 04000018 */ private class [PresentationCore]System.Windows.Media.ImageSource '<Image>k__BackingField'
	.custom /* 0C00002D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000019 */ private string '<Prompt>k__BackingField'
	.custom /* 0C00002F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001A */ private bool _isSelected

	// Methods
	.method /* 06000029 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.Happ.IHNode node,
			class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel tree,
			[opt] bool top
		) cil managed 
	{
		.param [3] = bool(true)
		// Method begins at RVA 0x23d8
		// Header size: 12
		// Code size: 329 (0x149)
		.maxstack 5
		.locals /* 11000004 */ init (
			[0] string,
			[1] string,
			[2] valuetype [mscorlib]System.Nullable`1<int32>,
			[3] string,
			[4] class AspenTech.AspenPlus.Happ.IHNodeCol,
			[5] int32
		)

		/* 0x000023D8 02                 */ IL_0000: ldarg.0
		/* 0x000023D9 281A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00001A */
		/* 0x000023DE 02                 */ IL_0006: ldarg.0
		/* 0x000023DF 03                 */ IL_0007: ldarg.1
		/* 0x000023E0 7D12000004         */ IL_0008: stfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x000023E5 02                 */ IL_000d: ldarg.0
		/* 0x000023E6 04                 */ IL_000e: ldarg.2
		/* 0x000023E7 7D14000004         */ IL_000f: stfld class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_tree /* 04000014 */
		/* 0x000023EC 04                 */ IL_0014: ldarg.2
		/* 0x000023ED 2C0C               */ IL_0015: brfalse.s IL_0023
		/* 0x000023EF 02                 */ IL_0017: ldarg.0
		/* 0x000023F0 04                 */ IL_0018: ldarg.2
		/* 0x000023F1 6F10000006         */ IL_0019: callvirt instance bool AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::get_ExpandOnBuild() /* 06000010 */
		/* 0x000023F6 7D15000004         */ IL_001e: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_isExpanded /* 04000015 */
		/* 0x000023FB 02                 */ IL_0023: ldarg.0
		/* 0x000023FC 7B12000004         */ IL_0024: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x00002401 391A010000         */ IL_0029: brfalse IL_0148
		/* 0x00002406 7269010070         */ IL_002e: ldstr "" /* 70000169 */
		/* 0x0000240B 0A                 */ IL_0033: stloc.0
		/* 0x0000240C 7269010070         */ IL_0034: ldstr "" /* 70000169 */
		/* 0x00002411 0B                 */ IL_0039: stloc.1
		/* 0x00002412 1202               */ IL_003a: ldloca.s 2
		/* 0x00002414 16                 */ IL_003c: ldc.i4.0
		/* 0x00002415 283700000A         */ IL_003d: call instance void valuetype [mscorlib]System.Nullable`1<int32>::.ctor(!0) /* 0A000037 */
		/* 0x0000241A 7269010070         */ IL_0042: ldstr "" /* 70000169 */
		/* 0x0000241F 0D                 */ IL_0047: stloc.3
		/* 0x00002420 02                 */ IL_0048: ldarg.0
		/* 0x00002421 7B12000004         */ IL_0049: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x00002426 7E3800000A         */ IL_004e: ldsfld object [mscorlib]System.Type::Missing /* 0A000038 */
		/* 0x0000242B 6F3F000006         */ IL_0053: callvirt instance object AspenTech.AspenPlus.Happ.IHNode::get_Value(object) /* 0600003F */
		/* 0x00002430 754B000001         */ IL_0058: isinst [mscorlib]System.String /* 0100004B */
		/* 0x00002435 0A                 */ IL_005d: stloc.0
		/* 0x00002436 02                 */ IL_005e: ldarg.0
		/* 0x00002437 7B12000004         */ IL_005f: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x0000243C 1F18               */ IL_0064: ldc.i4.s 24
		/* 0x0000243E 7E3800000A         */ IL_0066: ldsfld object [mscorlib]System.Type::Missing /* 0A000038 */
		/* 0x00002443 6F42000006         */ IL_006b: callvirt instance object AspenTech.AspenPlus.Happ.IHNode::get_AttributeValue(int16, object) /* 06000042 */
		/* 0x00002448 754B000001         */ IL_0070: isinst [mscorlib]System.String /* 0100004B */
		/* 0x0000244D 0B                 */ IL_0075: stloc.1
		/* 0x0000244E 02                 */ IL_0076: ldarg.0
		/* 0x0000244F 7B12000004         */ IL_0077: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x00002454 1F19               */ IL_007c: ldc.i4.s 25
		/* 0x00002456 7E3800000A         */ IL_007e: ldsfld object [mscorlib]System.Type::Missing /* 0A000038 */
		/* 0x0000245B 6F42000006         */ IL_0083: callvirt instance object AspenTech.AspenPlus.Happ.IHNode::get_AttributeValue(int16, object) /* 06000042 */
		/* 0x00002460 750300001B         */ IL_0088: isinst valuetype [mscorlib]System.Nullable`1<int32> /* 1B000003 */
		/* 0x00002465 A50300001B         */ IL_008d: unbox.any valuetype [mscorlib]System.Nullable`1<int32> /* 1B000003 */
		/* 0x0000246A 0C                 */ IL_0092: stloc.2
		/* 0x0000246B 1202               */ IL_0093: ldloca.s 2
		/* 0x0000246D 17                 */ IL_0095: ldc.i4.1
		/* 0x0000246E 283900000A         */ IL_0096: call instance !0 valuetype [mscorlib]System.Nullable`1<int32>::GetValueOrDefault(!0) /* 0A000039 */
		/* 0x00002473 1305               */ IL_009b: stloc.s 5
		/* 0x00002475 1205               */ IL_009d: ldloca.s 5
		/* 0x00002477 283A00000A         */ IL_009f: call class [mscorlib]System.Globalization.CultureInfo [mscorlib]System.Globalization.CultureInfo::get_InvariantCulture() /* 0A00003A */
		/* 0x0000247C 283B00000A         */ IL_00a4: call instance string [mscorlib]System.Int32::ToString(class [mscorlib]System.IFormatProvider) /* 0A00003B */
		/* 0x00002481 0D                 */ IL_00a9: stloc.3
		/* 0x00002482 DE03               */ IL_00aa: leave.s IL_00af
		/* 0x00002484 26                 */ IL_00ac: pop
		/* 0x00002485 DE00               */ IL_00ad: leave.s IL_00af
		/* 0x00002487 00                 */ IL_00af: nop
		/* 0x00002488 02                 */ IL_00b0: ldarg.0
		/* 0x00002489 02                 */ IL_00b1: ldarg.0
		/* 0x0000248A 7B12000004         */ IL_00b2: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x0000248F 1F13               */ IL_00b7: ldc.i4.s 19
		/* 0x00002491 7E3800000A         */ IL_00b9: ldsfld object [mscorlib]System.Type::Missing /* 0A000038 */
		/* 0x00002496 6F42000006         */ IL_00be: callvirt instance object AspenTech.AspenPlus.Happ.IHNode::get_AttributeValue(int16, object) /* 06000042 */
		/* 0x0000249B 754B000001         */ IL_00c3: isinst [mscorlib]System.String /* 0100004B */
		/* 0x000024A0 2836000006         */ IL_00c8: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Prompt(string) /* 06000036 */
		/* 0x000024A5 DE03               */ IL_00cd: leave.s IL_00d2
		/* 0x000024A7 26                 */ IL_00cf: pop
		/* 0x000024A8 DE00               */ IL_00d0: leave.s IL_00d2
		/* 0x000024AA 14                 */ IL_00d2: ldnull
		/* 0x000024AB 1304               */ IL_00d3: stloc.s 4
		/* 0x000024AD 02                 */ IL_00d5: ldarg.0
		/* 0x000024AE 7B12000004         */ IL_00d6: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x000024B3 6F45000006         */ IL_00db: callvirt instance class AspenTech.AspenPlus.Happ.IHNodeCol AspenTech.AspenPlus.Happ.IHNode::get_Elements() /* 06000045 */
		/* 0x000024B8 1304               */ IL_00e0: stloc.s 4
		/* 0x000024BA DE03               */ IL_00e2: leave.s IL_00e7
		/* 0x000024BC 26                 */ IL_00e4: pop
		/* 0x000024BD DE00               */ IL_00e5: leave.s IL_00e7
		/* 0x000024BF 1104               */ IL_00e7: ldloc.s 4
		/* 0x000024C1 2C27               */ IL_00e9: brfalse.s IL_0112
		/* 0x000024C3 02                 */ IL_00eb: ldarg.0
		/* 0x000024C4 2806000006         */ IL_00ec: call string AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_MethodText() /* 06000006 */
		/* 0x000024C9 06                 */ IL_00f1: ldloc.0
		/* 0x000024CA 07                 */ IL_00f2: ldloc.1
		/* 0x000024CB 09                 */ IL_00f3: ldloc.3
		/* 0x000024CC 283C00000A         */ IL_00f4: call string [mscorlib]System.String::Format(string, object, object, object) /* 0A00003C */
		/* 0x000024D1 2832000006         */ IL_00f9: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Text(string) /* 06000032 */
		/* 0x000024D6 02                 */ IL_00fe: ldarg.0
		/* 0x000024D7 283A000006         */ IL_00ff: call class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::get_Method() /* 0600003A */
		/* 0x000024DC 2834000006         */ IL_0104: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Image(class [PresentationCore]System.Windows.Media.ImageSource) /* 06000034 */
		/* 0x000024E1 02                 */ IL_0109: ldarg.0
		/* 0x000024E2 1104               */ IL_010a: ldloc.s 4
		/* 0x000024E4 282A000006         */ IL_010c: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::RefreshChildren(class AspenTech.AspenPlus.Happ.IHNodeCol) /* 0600002A */
		/* 0x000024E9 2A                 */ IL_0111: ret
		/* 0x000024EA 05                 */ IL_0112: ldarg.3
		/* 0x000024EB 2C15               */ IL_0113: brfalse.s IL_012a
		/* 0x000024ED 02                 */ IL_0115: ldarg.0
		/* 0x000024EE 2807000006         */ IL_0116: call string AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_ModelText() /* 06000007 */
		/* 0x000024F3 06                 */ IL_011b: ldloc.0
		/* 0x000024F4 07                 */ IL_011c: ldloc.1
		/* 0x000024F5 09                 */ IL_011d: ldloc.3
		/* 0x000024F6 283C00000A         */ IL_011e: call string [mscorlib]System.String::Format(string, object, object, object) /* 0A00003C */
		/* 0x000024FB 2832000006         */ IL_0123: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Text(string) /* 06000032 */
		/* 0x00002500 2B13               */ IL_0128: br.s IL_013d
		/* 0x00002502 02                 */ IL_012a: ldarg.0
		/* 0x00002503 2805000006         */ IL_012b: call string AspenTech.AspenPlus.MMHNodeTree.Properties.Resources::get_DataSetText() /* 06000005 */
		/* 0x00002508 06                 */ IL_0130: ldloc.0
		/* 0x00002509 07                 */ IL_0131: ldloc.1
		/* 0x0000250A 09                 */ IL_0132: ldloc.3
		/* 0x0000250B 283C00000A         */ IL_0133: call string [mscorlib]System.String::Format(string, object, object, object) /* 0A00003C */
		/* 0x00002510 2832000006         */ IL_0138: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Text(string) /* 06000032 */
		/* 0x00002515 02                 */ IL_013d: ldarg.0
		/* 0x00002516 2839000006         */ IL_013e: call class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::get_Model() /* 06000039 */
		/* 0x0000251B 2834000006         */ IL_0143: call instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Image(class [PresentationCore]System.Windows.Media.ImageSource) /* 06000034 */
		/* 0x00002520 2A                 */ IL_0148: ret

		.try IL_0048-IL_00ac catch [mscorlib]System.Runtime.InteropServices.COMException IL_00ac-IL_00af
		.try IL_00b0-IL_00cf catch [mscorlib]System.Runtime.InteropServices.COMException IL_00cf-IL_00d2
		.try IL_00d5-IL_00e4 catch [mscorlib]System.Runtime.InteropServices.COMException IL_00e4-IL_00e7
	} // end of method NodeTreeNode::.ctor

	.method /* 0600002A */ private hidebysig 
		instance void RefreshChildren (
			class AspenTech.AspenPlus.Happ.IHNodeCol elements
		) cil managed 
	{
		// Method begins at RVA 0x2558
		// Header size: 12
		// Code size: 84 (0x54)
		.maxstack 4
		.locals /* 11000005 */ init (
			[0] class [mscorlib]System.Collections.IEnumerator,
			[1] class AspenTech.AspenPlus.Happ.IHNode,
			[2] class [mscorlib]System.IDisposable
		)

		/* 0x00002558 02                 */ IL_0000: ldarg.0
		/* 0x00002559 732100000A         */ IL_0001: newobj instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode>::.ctor() /* 0A000021 */
		/* 0x0000255E 7D13000004         */ IL_0006: stfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_children /* 04000013 */
		/* 0x00002563 03                 */ IL_000b: ldarg.1
		/* 0x00002564 6F47000006         */ IL_000c: callvirt instance class [mscorlib]System.Collections.IEnumerator AspenTech.AspenPlus.Happ.IHNodeCol::GetEnumerator() /* 06000047 */
		/* 0x00002569 0A                 */ IL_0011: stloc.0
		/* 0x0000256A 2B24               */ IL_0012: br.s IL_0038
		/* 0x0000256C 06                 */ IL_0014: ldloc.0
		/* 0x0000256D 6F3D00000A         */ IL_0015: callvirt instance object [mscorlib]System.Collections.IEnumerator::get_Current() /* 0A00003D */
		/* 0x00002572 7409000002         */ IL_001a: castclass AspenTech.AspenPlus.Happ.IHNode /* 02000009 */
		/* 0x00002577 0B                 */ IL_001f: stloc.1
		/* 0x00002578 02                 */ IL_0020: ldarg.0
		/* 0x00002579 7B13000004         */ IL_0021: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_children /* 04000013 */
		/* 0x0000257E 07                 */ IL_0026: ldloc.1
		/* 0x0000257F 02                 */ IL_0027: ldarg.0
		/* 0x00002580 7B14000004         */ IL_0028: ldfld class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_tree /* 04000014 */
		/* 0x00002585 16                 */ IL_002d: ldc.i4.0
		/* 0x00002586 7329000006         */ IL_002e: newobj instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::.ctor(class AspenTech.AspenPlus.Happ.IHNode, class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel, bool) /* 06000029 */
		/* 0x0000258B 6F2200000A         */ IL_0033: callvirt instance void class [mscorlib]System.Collections.ObjectModel.Collection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode>::Add(!0) /* 0A000022 */
		/* 0x00002590 06                 */ IL_0038: ldloc.0
		/* 0x00002591 6F3E00000A         */ IL_0039: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A00003E */
		/* 0x00002596 2DD4               */ IL_003e: brtrue.s IL_0014
		/* 0x00002598 DE11               */ IL_0040: leave.s IL_0053
		/* 0x0000259A 06                 */ IL_0042: ldloc.0
		/* 0x0000259B 752A000001         */ IL_0043: isinst [mscorlib]System.IDisposable /* 0100002A */
		/* 0x000025A0 0C                 */ IL_0048: stloc.2
		/* 0x000025A1 08                 */ IL_0049: ldloc.2
		/* 0x000025A2 2C06               */ IL_004a: brfalse.s IL_0052
		/* 0x000025A4 08                 */ IL_004c: ldloc.2
		/* 0x000025A5 6F3F00000A         */ IL_004d: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00003F */
		/* 0x000025AA DC                 */ IL_0052: endfinally
		/* 0x000025AB 2A                 */ IL_0053: ret

		.try IL_0012-IL_0042 finally IL_0042-IL_0053
	} // end of method NodeTreeNode::RefreshChildren

	.method /* 0600002B */ public hidebysig specialname 
		instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> get_Children () cil managed 
	{
		// Method begins at RVA 0x25c8
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000025C8 02                 */ IL_0000: ldarg.0
		/* 0x000025C9 7B13000004         */ IL_0001: ldfld class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_children /* 04000013 */
		/* 0x000025CE 2A                 */ IL_0006: ret
	} // end of method NodeTreeNode::get_Children

	.method /* 0600002C */ public hidebysig specialname 
		instance bool get_IsExpanded () cil managed 
	{
		// Method begins at RVA 0x25d0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000025D0 02                 */ IL_0000: ldarg.0
		/* 0x000025D1 7B15000004         */ IL_0001: ldfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_isExpanded /* 04000015 */
		/* 0x000025D6 2A                 */ IL_0006: ret
	} // end of method NodeTreeNode::get_IsExpanded

	.method /* 0600002D */ public hidebysig specialname 
		instance void set_IsExpanded (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x25d8
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000025D8 02                 */ IL_0000: ldarg.0
		/* 0x000025D9 03                 */ IL_0001: ldarg.1
		/* 0x000025DA 7D15000004         */ IL_0002: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_isExpanded /* 04000015 */
		/* 0x000025DF 2A                 */ IL_0007: ret
	} // end of method NodeTreeNode::set_IsExpanded

	.method /* 0600002E */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00003D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x25e4
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000001 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000025E4 02                 */ IL_0000: ldarg.0
		/* 0x000025E5 7B16000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::PropertyChanged /* 04000016 */
		/* 0x000025EA 0A                 */ IL_0006: stloc.0
		/* 0x000025EB 06                 */ IL_0007: ldloc.0
		/* 0x000025EC 0B                 */ IL_0008: stloc.1
		/* 0x000025ED 07                 */ IL_0009: ldloc.1
		/* 0x000025EE 03                 */ IL_000a: ldarg.1
		/* 0x000025EF 282500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000025 */
		/* 0x000025F4 741B000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 0100001B */
		/* 0x000025F9 0C                 */ IL_0015: stloc.2
		/* 0x000025FA 02                 */ IL_0016: ldarg.0
		/* 0x000025FB 7C16000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::PropertyChanged /* 04000016 */
		/* 0x00002600 08                 */ IL_001c: ldloc.2
		/* 0x00002601 07                 */ IL_001d: ldloc.1
		/* 0x00002602 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x00002607 0A                 */ IL_0023: stloc.0
		/* 0x00002608 06                 */ IL_0024: ldloc.0
		/* 0x00002609 07                 */ IL_0025: ldloc.1
		/* 0x0000260A 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x0000260C 2A                 */ IL_0028: ret
	} // end of method NodeTreeNode::add_PropertyChanged

	.method /* 0600002F */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00003E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x261c
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 11000001 */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x0000261C 02                 */ IL_0000: ldarg.0
		/* 0x0000261D 7B16000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::PropertyChanged /* 04000016 */
		/* 0x00002622 0A                 */ IL_0006: stloc.0
		/* 0x00002623 06                 */ IL_0007: ldloc.0
		/* 0x00002624 0B                 */ IL_0008: stloc.1
		/* 0x00002625 07                 */ IL_0009: ldloc.1
		/* 0x00002626 03                 */ IL_000a: ldarg.1
		/* 0x00002627 282700000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000027 */
		/* 0x0000262C 741B000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 0100001B */
		/* 0x00002631 0C                 */ IL_0015: stloc.2
		/* 0x00002632 02                 */ IL_0016: ldarg.0
		/* 0x00002633 7C16000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::PropertyChanged /* 04000016 */
		/* 0x00002638 08                 */ IL_001c: ldloc.2
		/* 0x00002639 07                 */ IL_001d: ldloc.1
		/* 0x0000263A 280100002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000001 */
		/* 0x0000263F 0A                 */ IL_0023: stloc.0
		/* 0x00002640 06                 */ IL_0024: ldloc.0
		/* 0x00002641 07                 */ IL_0025: ldloc.1
		/* 0x00002642 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00002644 2A                 */ IL_0028: ret
	} // end of method NodeTreeNode::remove_PropertyChanged

	.method /* 06000030 */ public final hidebysig newslot virtual 
		instance void Dispose () cil managed 
	{
		// Method begins at RVA 0x2651
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002651 02                 */ IL_0000: ldarg.0
		/* 0x00002652 7B12000004         */ IL_0001: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x00002657 2C13               */ IL_0006: brfalse.s IL_001b
		/* 0x00002659 02                 */ IL_0008: ldarg.0
		/* 0x0000265A 7B12000004         */ IL_0009: ldfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x0000265F 284000000A         */ IL_000e: call int32 [mscorlib]System.Runtime.InteropServices.Marshal::ReleaseComObject(object) /* 0A000040 */
		/* 0x00002664 26                 */ IL_0013: pop
		/* 0x00002665 02                 */ IL_0014: ldarg.0
		/* 0x00002666 14                 */ IL_0015: ldnull
		/* 0x00002667 7D12000004         */ IL_0016: stfld class AspenTech.AspenPlus.Happ.IHNode AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_node /* 04000012 */
		/* 0x0000266C 2A                 */ IL_001b: ret
	} // end of method NodeTreeNode::Dispose

	.method /* 06000031 */ public hidebysig specialname 
		instance string get_Text () cil managed 
	{
		// Method begins at RVA 0x266e
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000266E 02                 */ IL_0000: ldarg.0
		/* 0x0000266F 7B17000004         */ IL_0001: ldfld string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_text /* 04000017 */
		/* 0x00002674 2A                 */ IL_0006: ret
	} // end of method NodeTreeNode::get_Text

	.method /* 06000032 */ private hidebysig specialname 
		instance void set_Text (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2676
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002676 02                 */ IL_0000: ldarg.0
		/* 0x00002677 03                 */ IL_0001: ldarg.1
		/* 0x00002678 7D17000004         */ IL_0002: stfld string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_text /* 04000017 */
		/* 0x0000267D 2A                 */ IL_0007: ret
	} // end of method NodeTreeNode::set_Text

	.method /* 06000033 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.ImageSource get_Image () cil managed 
	{
		.custom /* 0C00003F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x267f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000267F 02                 */ IL_0000: ldarg.0
		/* 0x00002680 7B18000004         */ IL_0001: ldfld class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::'<Image>k__BackingField' /* 04000018 */
		/* 0x00002685 2A                 */ IL_0006: ret
	} // end of method NodeTreeNode::get_Image

	.method /* 06000034 */ private hidebysig specialname 
		instance void set_Image (
			class [PresentationCore]System.Windows.Media.ImageSource 'value'
		) cil managed 
	{
		.custom /* 0C000040 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2687
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002687 02                 */ IL_0000: ldarg.0
		/* 0x00002688 03                 */ IL_0001: ldarg.1
		/* 0x00002689 7D18000004         */ IL_0002: stfld class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::'<Image>k__BackingField' /* 04000018 */
		/* 0x0000268E 2A                 */ IL_0007: ret
	} // end of method NodeTreeNode::set_Image

	.method /* 06000035 */ assembly hidebysig specialname 
		instance string get_Prompt () cil managed 
	{
		.custom /* 0C000041 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2690
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002690 02                 */ IL_0000: ldarg.0
		/* 0x00002691 7B19000004         */ IL_0001: ldfld string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::'<Prompt>k__BackingField' /* 04000019 */
		/* 0x00002696 2A                 */ IL_0006: ret
	} // end of method NodeTreeNode::get_Prompt

	.method /* 06000036 */ assembly hidebysig specialname 
		instance void set_Prompt (
			string 'value'
		) cil managed 
	{
		.custom /* 0C000042 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2698
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002698 02                 */ IL_0000: ldarg.0
		/* 0x00002699 03                 */ IL_0001: ldarg.1
		/* 0x0000269A 7D19000004         */ IL_0002: stfld string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::'<Prompt>k__BackingField' /* 04000019 */
		/* 0x0000269F 2A                 */ IL_0007: ret
	} // end of method NodeTreeNode::set_Prompt

	.method /* 06000037 */ public hidebysig specialname 
		instance bool get_IsSelected () cil managed 
	{
		// Method begins at RVA 0x26a1
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000026A1 02                 */ IL_0000: ldarg.0
		/* 0x000026A2 7B1A000004         */ IL_0001: ldfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_isSelected /* 0400001A */
		/* 0x000026A7 2A                 */ IL_0006: ret
	} // end of method NodeTreeNode::get_IsSelected

	.method /* 06000038 */ public hidebysig specialname 
		instance void set_IsSelected (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x26a9
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000026A9 02                 */ IL_0000: ldarg.0
		/* 0x000026AA 03                 */ IL_0001: ldarg.1
		/* 0x000026AB 7D1A000004         */ IL_0002: stfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_isSelected /* 0400001A */
		/* 0x000026B0 02                 */ IL_0007: ldarg.0
		/* 0x000026B1 7B1A000004         */ IL_0008: ldfld bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_isSelected /* 0400001A */
		/* 0x000026B6 2C0C               */ IL_000d: brfalse.s IL_001b
		/* 0x000026B8 02                 */ IL_000f: ldarg.0
		/* 0x000026B9 7B14000004         */ IL_0010: ldfld class AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::_tree /* 04000014 */
		/* 0x000026BE 02                 */ IL_0015: ldarg.0
		/* 0x000026BF 6F13000006         */ IL_0016: callvirt instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTree_ViewModel::set_Selection(class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode) /* 06000013 */
		/* 0x000026C4 2A                 */ IL_001b: ret
	} // end of method NodeTreeNode::set_IsSelected

	// Events
	.event /* 14000002 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


	// Properties
	.property /* 17000010 */ instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> Children()
	{
		.get instance class [System]System.Collections.ObjectModel.ObservableCollection`1<class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode> AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_Children()
	}
	.property /* 17000011 */ instance bool IsExpanded()
	{
		.get instance bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_IsExpanded()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_IsExpanded(bool)
	}
	.property /* 17000012 */ instance string Text()
	{
		.get instance string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_Text()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Text(string)
	}
	.property /* 17000013 */ instance class [PresentationCore]System.Windows.Media.ImageSource Image()
	{
		.get instance class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_Image()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Image(class [PresentationCore]System.Windows.Media.ImageSource)
	}
	.property /* 17000014 */ instance string Prompt()
	{
		.get instance string AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_Prompt()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_Prompt(string)
	}
	.property /* 17000015 */ instance bool IsSelected()
	{
		.get instance bool AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::get_IsSelected()
		.set instance void AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode::set_IsSelected(bool)
	}

} // end of class AsepnTech.AspenPlus.MMHNodeTree.NodeTreeNode

.class /* 02000008 */ private auto ansi beforefieldinit AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources
	extends [mscorlib]System.Object
{
	// Fields
	.field /* 0400001B */ private static initonly class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> _imageSources

	// Methods
	.method /* 06000039 */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Model () cil managed 
	{
		// Method begins at RVA 0x26c6
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000026C6 726B010070         */ IL_0000: ldstr "model.png" /* 7000016B */
		/* 0x000026CB 283B000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::GetImageSource(string) /* 0600003B */
		/* 0x000026D0 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Model

	.method /* 0600003A */ public hidebysig specialname static 
		class [PresentationCore]System.Windows.Media.ImageSource get_Method () cil managed 
	{
		// Method begins at RVA 0x26d2
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x000026D2 727F010070         */ IL_0000: ldstr "method.png" /* 7000017F */
		/* 0x000026D7 283B000006         */ IL_0005: call class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::GetImageSource(string) /* 0600003B */
		/* 0x000026DC 2A                 */ IL_000a: ret
	} // end of method ImageResources::get_Method

	.method /* 0600003B */ private hidebysig static 
		class [PresentationCore]System.Windows.Media.ImageSource GetImageSource (
			string imageFileName
		) cil managed 
	{
		// Method begins at RVA 0x26e0
		// Header size: 12
		// Code size: 118 (0x76)
		.maxstack 4
		.locals /* 11000006 */ init (
			[0] class [mscorlib]System.Text.StringBuilder
		)

		/* 0x000026E0 7E1B000004         */ IL_0000: ldsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::_imageSources /* 0400001B */
		/* 0x000026E5 02                 */ IL_0005: ldarg.0
		/* 0x000026E6 6F4100000A         */ IL_0006: callvirt instance bool class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::ContainsKey(!0) /* 0A000041 */
		/* 0x000026EB 2D5D               */ IL_000b: brtrue.s IL_006a
		/* 0x000026ED 734200000A         */ IL_000d: newobj instance void [mscorlib]System.Text.StringBuilder::.ctor() /* 0A000042 */
		/* 0x000026F2 0A                 */ IL_0012: stloc.0
		/* 0x000026F3 06                 */ IL_0013: ldloc.0
		/* 0x000026F4 7295010070         */ IL_0014: ldstr "pack://application:,,,/" /* 70000195 */
		/* 0x000026F9 6F4300000A         */ IL_0019: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000043 */
		/* 0x000026FE 26                 */ IL_001e: pop
		/* 0x000026FF 06                 */ IL_001f: ldloc.0
		/* 0x00002700 D008000002         */ IL_0020: ldtoken AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources /* 02000008 */
		/* 0x00002705 281B00000A         */ IL_0025: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A00001B */
		/* 0x0000270A 6F1C00000A         */ IL_002a: callvirt instance class [mscorlib]System.Reflection.Assembly [mscorlib]System.Type::get_Assembly() /* 0A00001C */
		/* 0x0000270F 6F4400000A         */ IL_002f: callvirt instance string [mscorlib]System.Reflection.Assembly::get_FullName() /* 0A000044 */
		/* 0x00002714 6F4300000A         */ IL_0034: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000043 */
		/* 0x00002719 26                 */ IL_0039: pop
		/* 0x0000271A 06                 */ IL_003a: ldloc.0
		/* 0x0000271B 72C5010070         */ IL_003b: ldstr ";component/Images/" /* 700001C5 */
		/* 0x00002720 6F4300000A         */ IL_0040: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000043 */
		/* 0x00002725 26                 */ IL_0045: pop
		/* 0x00002726 06                 */ IL_0046: ldloc.0
		/* 0x00002727 02                 */ IL_0047: ldarg.0
		/* 0x00002728 6F4300000A         */ IL_0048: callvirt instance class [mscorlib]System.Text.StringBuilder [mscorlib]System.Text.StringBuilder::Append(string) /* 0A000043 */
		/* 0x0000272D 26                 */ IL_004d: pop
		/* 0x0000272E 7E1B000004         */ IL_004e: ldsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::_imageSources /* 0400001B */
		/* 0x00002733 02                 */ IL_0053: ldarg.0
		/* 0x00002734 06                 */ IL_0054: ldloc.0
		/* 0x00002735 6F4500000A         */ IL_0055: callvirt instance string [mscorlib]System.Object::ToString() /* 0A000045 */
		/* 0x0000273A 16                 */ IL_005a: ldc.i4.0
		/* 0x0000273B 732D00000A         */ IL_005b: newobj instance void [System]System.Uri::.ctor(string, valuetype [System]System.UriKind) /* 0A00002D */
		/* 0x00002740 734600000A         */ IL_0060: newobj instance void [PresentationCore]System.Windows.Media.Imaging.BitmapImage::.ctor(class [System]System.Uri) /* 0A000046 */
		/* 0x00002745 6F4700000A         */ IL_0065: callvirt instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::Add(!0, !1) /* 0A000047 */
		/* 0x0000274A 7E1B000004         */ IL_006a: ldsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::_imageSources /* 0400001B */
		/* 0x0000274F 02                 */ IL_006f: ldarg.0
		/* 0x00002750 6F4800000A         */ IL_0070: callvirt instance !1 class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::get_Item(!0) /* 0A000048 */
		/* 0x00002755 2A                 */ IL_0075: ret
	} // end of method ImageResources::GetImageSource

	.method /* 0600003C */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2050
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002050 02                 */ IL_0000: ldarg.0
		/* 0x00002051 281A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00001A */
		/* 0x00002056 2A                 */ IL_0006: ret
	} // end of method ImageResources::.ctor

	.method /* 0600003D */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2762
		// Header size: 1
		// Code size: 11 (0xb)
		.maxstack 8

		/* 0x00002762 734900000A         */ IL_0000: newobj instance void class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource>::.ctor() /* 0A000049 */
		/* 0x00002767 801B000004         */ IL_0005: stsfld class [mscorlib]System.Collections.Generic.Dictionary`2<string, class [PresentationCore]System.Windows.Media.ImageSource> AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::_imageSources /* 0400001B */
		/* 0x0000276C 2A                 */ IL_000a: ret
	} // end of method ImageResources::.cctor

	// Properties
	.property /* 17000016 */ class [PresentationCore]System.Windows.Media.ImageSource Model()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::get_Model()
	}
	.property /* 17000017 */ class [PresentationCore]System.Windows.Media.ImageSource Method()
	{
		.get class [PresentationCore]System.Windows.Media.ImageSource AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources::get_Method()
	}

} // end of class AsepnTech.AspenPlus.MMHNodeTree.Images.ImageResources

.class /* 02000009 */ interface public auto ansi abstract import AspenTech.AspenPlus.Happ.IHNode
{
	.custom /* 0C00001A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C00001B */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 38 45 35 36 37 35 32 32 2d 46 39 42 41
		2d 31 31 43 46 2d 39 30 42 32 2d 30 30 30 30 43
		30 41 38 31 30 43 34 00 00
	)
	.custom /* 0C00001C */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 0600003E */ public specialname rtspecialname 
		instance void _VtblGap1_6 () runtime managed 
	{
	} // end of method IHNode::_VtblGap1_6

	.method /* 0600003F */ public hidebysig specialname newslot abstract virtual 
		instance object marshal(struct) get_Value (
			[in] [opt] object marshal(struct) force
		) runtime managed internalcall 
	{
		.custom /* 0C000043 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 06 00 02 60 00 00
		)
	} // end of method IHNode::get_Value

	.method /* 06000040 */ public hidebysig specialname newslot abstract virtual 
		instance void set_Value (
			[in] [opt] object marshal(struct) force,
			[in] object marshal(struct) Value
		) runtime managed internalcall 
	{
		.custom /* 0C000044 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 06 00 02 60 00 00
		)
	} // end of method IHNode::set_Value

	.method /* 06000041 */ public specialname rtspecialname 
		instance void _VtblGap2_4 () runtime managed 
	{
	} // end of method IHNode::_VtblGap2_4

	.method /* 06000042 */ public hidebysig specialname newslot abstract virtual 
		instance object marshal(struct) get_AttributeValue (
			[in] int16 attrnumber,
			[in] [opt] object marshal(struct) force
		) runtime managed internalcall 
	{
		.custom /* 0C000045 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 0c 00 02 60 00 00
		)
	} // end of method IHNode::get_AttributeValue

	.method /* 06000043 */ public hidebysig specialname newslot abstract virtual 
		instance void set_AttributeValue (
			[in] int16 attrnumber,
			[in] [opt] object marshal(struct) force,
			[in] object marshal(struct) Value
		) runtime managed internalcall 
	{
		.custom /* 0C000046 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 0c 00 02 60 00 00
		)
	} // end of method IHNode::set_AttributeValue

	.method /* 06000044 */ public specialname rtspecialname 
		instance void _VtblGap3_4 () runtime managed 
	{
	} // end of method IHNode::_VtblGap3_4

	.method /* 06000045 */ public hidebysig specialname newslot abstract virtual 
		instance class AspenTech.AspenPlus.Happ.IHNodeCol marshal(interface) get_Elements () runtime managed internalcall 
	{
		.custom /* 0C000047 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 12 00 02 60 00 00
		)
	} // end of method IHNode::get_Elements

	// Properties
	.property /* 17000018 */ object Value(
		[in] [opt] object marshal(struct) force
	)
	{
		.custom /* 0C00002E */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 06 00 02 60 00 00
		)
		.get instance object AspenTech.AspenPlus.Happ.IHNode::get_Value(object)
		.set instance void AspenTech.AspenPlus.Happ.IHNode::set_Value(object, object)
	}
	.property /* 17000019 */ object AttributeValue(
		[in] int16 attrnumber,
		[in] [opt] object marshal(struct) force
	)
	{
		.custom /* 0C000030 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 0c 00 02 60 00 00
		)
		.get instance object AspenTech.AspenPlus.Happ.IHNode::get_AttributeValue(int16, object)
		.set instance void AspenTech.AspenPlus.Happ.IHNode::set_AttributeValue(int16, object, object)
	}
	.property /* 1700001A */ class AspenTech.AspenPlus.Happ.IHNodeCol Elements()
	{
		.custom /* 0C000031 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 12 00 02 60 00 00
		)
		.get instance class AspenTech.AspenPlus.Happ.IHNodeCol AspenTech.AspenPlus.Happ.IHNode::get_Elements()
	}

} // end of class AspenTech.AspenPlus.Happ.IHNode

.class /* 0200000A */ interface public auto ansi abstract import AspenTech.AspenPlus.Happ.IHNodeCol
	implements [mscorlib]System.Collections.IEnumerable
{
	.custom /* 0C00001D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C00001E */ instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = (
		01 00 24 38 39 45 38 31 46 36 30 2d 30 31 39 41
		2d 31 31 44 30 2d 39 42 45 37 2d 30 30 30 30 43
		30 35 33 37 35 44 35 00 00
	)
	.custom /* 0C00001F */ instance void [mscorlib]System.Reflection.DefaultMemberAttribute::.ctor(string) = (
		01 00 04 49 74 65 6d 00 00
	)
	.custom /* 0C000020 */ instance void [mscorlib]System.Runtime.InteropServices.TypeIdentifierAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 06000046 */ public specialname rtspecialname 
		instance void _VtblGap1_16 () runtime managed 
	{
	} // end of method IHNodeCol::_VtblGap1_16

	.method /* 06000047 */ public hidebysig newslot abstract virtual 
		instance class [mscorlib]System.Collections.IEnumerator marshal(custom("System.Runtime.InteropServices.CustomMarshalers.EnumeratorToEnumVariantMarshaler, CustomMarshalers, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", "")) GetEnumerator () runtime managed internalcall 
	{
		.custom /* 0C000048 */ instance void [mscorlib]System.Runtime.InteropServices.DispIdAttribute::.ctor(int32) = (
			01 00 fc ff ff ff 00 00
		)
	} // end of method IHNodeCol::GetEnumerator

} // end of class AspenTech.AspenPlus.Happ.IHNodeCol

