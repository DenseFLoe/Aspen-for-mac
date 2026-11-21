.module AspenTech.AspenPlus.ModelLibrary.Controls.dll
// MVID: {95B8D504-87A6-4353-864A-DF73F659962C}
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
		/* 0x00002059 281900000A         */ IL_0009: call object [mscorlib]System.Activator::CreateInstance(class [mscorlib]System.Type, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A000019 */
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
		/* 0x00002066 6F1A00000A         */ IL_0006: callvirt instance object [mscorlib]System.Reflection.PropertyInfo::GetValue(object, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A00001A */
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
		/* 0x00002075 6F1B00000A         */ IL_0008: callvirt instance void [mscorlib]System.Reflection.PropertyInfo::SetValue(object, object, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A00001B */
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
		/* 0x0000207D 6F1C00000A         */ IL_0001: callvirt instance class [mscorlib]System.Type [mscorlib]System.Object::GetType() /* 0A00001C */
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
		/* 0x0000209D 6F1D00000A         */ IL_0021: callvirt instance object [mscorlib]System.Type::InvokeMember(string, valuetype [mscorlib]System.Reflection.BindingFlags, class [mscorlib]System.Reflection.Binder, object, object[], class [mscorlib]System.Globalization.CultureInfo) /* 0A00001D */
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
		/* 0x000020B7 6F1E00000A         */ IL_0003: callvirt instance void [mscorlib]System.Reflection.EventInfo::AddEventHandler(object, class [mscorlib]System.Delegate) /* 0A00001E */
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
		/* 0x000020BF 281F00000A         */ IL_0001: call instance void [WindowsBase]System.Windows.Markup.InternalTypeHelper::.ctor() /* 0A00001F */
		/* 0x000020C4 2A                 */ IL_0006: ret
	} // end of method GeneratedInternalTypeHelper::.ctor

} // end of class XamlGeneratedNamespace.GeneratedInternalTypeHelper

.class /* 02000003 */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl
	extends [PresentationFramework]System.Windows.Controls.Control
{
	.custom /* 0C000014 */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 0a 43 61 74 65 67 6f 72 69 65 73 00 00
	)
	// Fields
	.field /* 04000001 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty DockProperty
	.field /* 04000002 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CategoriesProperty
	.field /* 04000003 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty SelectedIconProperty
	.field /* 04000004 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CurrentCategoryProperty
	.field /* 04000005 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ButtonSizeProperty
	.field /* 04000006 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty DefaultButtonBackgroundProperty
	.field /* 04000007 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CheckedButtonBackgroundProperty
	.field /* 04000008 */ public static initonly class [PresentationCore]System.Windows.RoutedEvent SelectedIconChangedEvent
	.field /* 04000009 */ public static initonly class [PresentationCore]System.Windows.RoutedEvent CurrentCategoryChangedEvent

	// Methods
	.method /* 06000007 */ public hidebysig specialname 
		instance valuetype [PresentationFramework]System.Windows.Controls.Dock get_Dock () cil managed 
	{
		// Method begins at RVA 0x20c6
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000020C6 02                 */ IL_0000: ldarg.0
		/* 0x000020C7 7E01000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DockProperty /* 04000001 */
		/* 0x000020CC 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000020D1 A524000001         */ IL_000b: unbox.any [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x000020D6 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_Dock

	.method /* 06000008 */ public hidebysig specialname 
		instance void set_Dock (
			valuetype [PresentationFramework]System.Windows.Controls.Dock 'value'
		) cil managed 
	{
		// Method begins at RVA 0x20d8
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000020D8 02                 */ IL_0000: ldarg.0
		/* 0x000020D9 7E01000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DockProperty /* 04000001 */
		/* 0x000020DE 03                 */ IL_0006: ldarg.1
		/* 0x000020DF 8C24000001         */ IL_0007: box [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x000020E4 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000020E9 2A                 */ IL_0011: ret
	} // end of method BlockTableControl::set_Dock

	.method /* 06000009 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection get_Categories () cil managed 
	{
		// Method begins at RVA 0x20eb
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000020EB 02                 */ IL_0000: ldarg.0
		/* 0x000020EC 7E02000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CategoriesProperty /* 04000002 */
		/* 0x000020F1 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000020F6 7405000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection /* 02000005 */
		/* 0x000020FB 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_Categories

	.method /* 0600000A */ public hidebysig specialname 
		instance void set_Categories (
			class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection 'value'
		) cil managed 
	{
		// Method begins at RVA 0x20fd
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000020FD 02                 */ IL_0000: ldarg.0
		/* 0x000020FE 7E02000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CategoriesProperty /* 04000002 */
		/* 0x00002103 03                 */ IL_0006: ldarg.1
		/* 0x00002104 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002109 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::set_Categories

	.method /* 0600000B */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category get_CurrentCategory () cil managed 
	{
		// Method begins at RVA 0x210b
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000210B 02                 */ IL_0000: ldarg.0
		/* 0x0000210C 7E04000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryProperty /* 04000004 */
		/* 0x00002111 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002116 7404000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Category /* 02000004 */
		/* 0x0000211B 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_CurrentCategory

	.method /* 0600000C */ public hidebysig specialname 
		instance void set_CurrentCategory (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category 'value'
		) cil managed 
	{
		// Method begins at RVA 0x211d
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000211D 02                 */ IL_0000: ldarg.0
		/* 0x0000211E 7E04000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryProperty /* 04000004 */
		/* 0x00002123 03                 */ IL_0006: ldarg.1
		/* 0x00002124 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002129 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::set_CurrentCategory

	.method /* 0600000D */ public hidebysig specialname 
		instance valuetype [WindowsBase]System.Windows.Size get_ButtonSize () cil managed 
	{
		// Method begins at RVA 0x212b
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000212B 02                 */ IL_0000: ldarg.0
		/* 0x0000212C 7E05000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::ButtonSizeProperty /* 04000005 */
		/* 0x00002131 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002136 A525000001         */ IL_000b: unbox.any [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x0000213B 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_ButtonSize

	.method /* 0600000E */ public hidebysig specialname 
		instance void set_ButtonSize (
			valuetype [WindowsBase]System.Windows.Size 'value'
		) cil managed 
	{
		// Method begins at RVA 0x213d
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x0000213D 02                 */ IL_0000: ldarg.0
		/* 0x0000213E 7E05000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::ButtonSizeProperty /* 04000005 */
		/* 0x00002143 03                 */ IL_0006: ldarg.1
		/* 0x00002144 8C25000001         */ IL_0007: box [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x00002149 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000214E 2A                 */ IL_0011: ret
	} // end of method BlockTableControl::set_ButtonSize

	.method /* 0600000F */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon get_SelectedIcon () cil managed 
	{
		// Method begins at RVA 0x2150
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002150 02                 */ IL_0000: ldarg.0
		/* 0x00002151 7E03000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconProperty /* 04000003 */
		/* 0x00002156 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x0000215B 7407000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x00002160 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_SelectedIcon

	.method /* 06000010 */ public hidebysig specialname 
		instance void set_SelectedIcon (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2162
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002162 02                 */ IL_0000: ldarg.0
		/* 0x00002163 7E03000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconProperty /* 04000003 */
		/* 0x00002168 03                 */ IL_0006: ldarg.1
		/* 0x00002169 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000216E 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::set_SelectedIcon

	.method /* 06000011 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_DefaultButtonBackground () cil managed 
	{
		// Method begins at RVA 0x2170
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002170 02                 */ IL_0000: ldarg.0
		/* 0x00002171 7E06000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DefaultButtonBackgroundProperty /* 04000006 */
		/* 0x00002176 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x0000217B 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x00002180 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_DefaultButtonBackground

	.method /* 06000012 */ public hidebysig specialname 
		instance void set_DefaultButtonBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2182
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002182 02                 */ IL_0000: ldarg.0
		/* 0x00002183 7E06000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DefaultButtonBackgroundProperty /* 04000006 */
		/* 0x00002188 03                 */ IL_0006: ldarg.1
		/* 0x00002189 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000218E 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::set_DefaultButtonBackground

	.method /* 06000013 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_CheckedButtonBackground () cil managed 
	{
		// Method begins at RVA 0x2190
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002190 02                 */ IL_0000: ldarg.0
		/* 0x00002191 7E07000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CheckedButtonBackgroundProperty /* 04000007 */
		/* 0x00002196 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x0000219B 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x000021A0 2A                 */ IL_0010: ret
	} // end of method BlockTableControl::get_CheckedButtonBackground

	.method /* 06000014 */ public hidebysig specialname 
		instance void set_CheckedButtonBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x21a2
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000021A2 02                 */ IL_0000: ldarg.0
		/* 0x000021A3 7E07000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CheckedButtonBackgroundProperty /* 04000007 */
		/* 0x000021A8 03                 */ IL_0006: ldarg.1
		/* 0x000021A9 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000021AE 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::set_CheckedButtonBackground

	.method /* 06000015 */ public hidebysig specialname 
		instance void add_SelectedIconChanged (
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x21b0
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000021B0 02                 */ IL_0000: ldarg.0
		/* 0x000021B1 7E08000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconChangedEvent /* 04000008 */
		/* 0x000021B6 03                 */ IL_0006: ldarg.1
		/* 0x000021B7 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x000021BC 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::add_SelectedIconChanged

	.method /* 06000016 */ public hidebysig specialname 
		instance void remove_SelectedIconChanged (
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x21be
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000021BE 02                 */ IL_0000: ldarg.0
		/* 0x000021BF 7E08000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconChangedEvent /* 04000008 */
		/* 0x000021C4 03                 */ IL_0006: ldarg.1
		/* 0x000021C5 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000021CA 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::remove_SelectedIconChanged

	.method /* 06000017 */ public hidebysig specialname 
		instance void add_CurrentCategoryChanged (
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x21cc
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000021CC 02                 */ IL_0000: ldarg.0
		/* 0x000021CD 7E09000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryChangedEvent /* 04000009 */
		/* 0x000021D2 03                 */ IL_0006: ldarg.1
		/* 0x000021D3 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x000021D8 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::add_CurrentCategoryChanged

	.method /* 06000018 */ public hidebysig specialname 
		instance void remove_CurrentCategoryChanged (
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x21da
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000021DA 02                 */ IL_0000: ldarg.0
		/* 0x000021DB 7E09000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryChangedEvent /* 04000009 */
		/* 0x000021E0 03                 */ IL_0006: ldarg.1
		/* 0x000021E1 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000021E6 2A                 */ IL_000c: ret
	} // end of method BlockTableControl::remove_CurrentCategoryChanged

	.method /* 06000019 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x21e8
		// Header size: 12
		// Code size: 483 (0x1e3)
		.maxstack 5

		/* 0x000021E8 7221000070         */ IL_0000: ldstr "Dock" /* 70000021 */
		/* 0x000021ED D024000001         */ IL_0005: ldtoken [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x000021F2 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000021F7 D003000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x000021FC 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002201 19                 */ IL_0019: ldc.i4.3
		/* 0x00002202 8C24000001         */ IL_001a: box [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x00002207 732500000A         */ IL_001f: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000220C 282600000A         */ IL_0024: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002211 8001000004         */ IL_0029: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DockProperty /* 04000001 */
		/* 0x00002216 722B000070         */ IL_002e: ldstr "Categories" /* 7000002B */
		/* 0x0000221B D005000002         */ IL_0033: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection /* 02000005 */
		/* 0x00002220 282400000A         */ IL_0038: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002225 D003000002         */ IL_003d: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x0000222A 282400000A         */ IL_0042: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000222F 282700000A         */ IL_0047: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x00002234 8002000004         */ IL_004c: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CategoriesProperty /* 04000002 */
		/* 0x00002239 7241000070         */ IL_0051: ldstr "SelectedIcon" /* 70000041 */
		/* 0x0000223E D007000002         */ IL_0056: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x00002243 282400000A         */ IL_005b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002248 D003000002         */ IL_0060: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x0000224D 282400000A         */ IL_0065: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002252 14                 */ IL_006a: ldnull
		/* 0x00002253 FE061D000006       */ IL_006b: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::OnSelectedIconPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 0600001D */
		/* 0x00002259 732800000A         */ IL_0071: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x0000225E 732900000A         */ IL_0076: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000029 */
		/* 0x00002263 282600000A         */ IL_007b: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002268 8003000004         */ IL_0080: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconProperty /* 04000003 */
		/* 0x0000226D 725B000070         */ IL_0085: ldstr "CurrentCategory" /* 7000005B */
		/* 0x00002272 D004000002         */ IL_008a: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.Category /* 02000004 */
		/* 0x00002277 282400000A         */ IL_008f: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000227C D003000002         */ IL_0094: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002281 282400000A         */ IL_0099: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002286 14                 */ IL_009e: ldnull
		/* 0x00002287 FE061E000006       */ IL_009f: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::OnCurrentCategoryPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 0600001E */
		/* 0x0000228D 732800000A         */ IL_00a5: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00002292 732900000A         */ IL_00aa: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000029 */
		/* 0x00002297 282600000A         */ IL_00af: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x0000229C 8004000004         */ IL_00b4: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryProperty /* 04000004 */
		/* 0x000022A1 727B000070         */ IL_00b9: ldstr "ButtonSize" /* 7000007B */
		/* 0x000022A6 D025000001         */ IL_00be: ldtoken [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x000022AB 282400000A         */ IL_00c3: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000022B0 D003000002         */ IL_00c8: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x000022B5 282400000A         */ IL_00cd: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000022BA 230000000000805640 */ IL_00d2: ldc.r8 90
		/* 0x000022C3 230000000000805140 */ IL_00db: ldc.r8 70
		/* 0x000022CC 732A00000A         */ IL_00e4: newobj instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00002A */
		/* 0x000022D1 8C25000001         */ IL_00e9: box [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x000022D6 732500000A         */ IL_00ee: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x000022DB 282600000A         */ IL_00f3: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x000022E0 8005000004         */ IL_00f8: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::ButtonSizeProperty /* 04000005 */
		/* 0x000022E5 7291000070         */ IL_00fd: ldstr "DefaultButtonBackground" /* 70000091 */
		/* 0x000022EA D026000001         */ IL_0102: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x000022EF 282400000A         */ IL_0107: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000022F4 D003000002         */ IL_010c: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x000022F9 282400000A         */ IL_0111: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000022FE 282B00000A         */ IL_0116: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_LightGray() /* 0A00002B */
		/* 0x00002303 732500000A         */ IL_011b: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002308 282600000A         */ IL_0120: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x0000230D 8006000004         */ IL_0125: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DefaultButtonBackgroundProperty /* 04000006 */
		/* 0x00002312 72C1000070         */ IL_012a: ldstr "CheckedButtonBackground" /* 700000C1 */
		/* 0x00002317 D026000001         */ IL_012f: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x0000231C 282400000A         */ IL_0134: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002321 D003000002         */ IL_0139: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002326 282400000A         */ IL_013e: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000232B 282C00000A         */ IL_0143: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_White() /* 0A00002C */
		/* 0x00002330 732500000A         */ IL_0148: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002335 282600000A         */ IL_014d: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x0000233A 8007000004         */ IL_0152: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CheckedButtonBackgroundProperty /* 04000007 */
		/* 0x0000233F 72F1000070         */ IL_0157: ldstr "SelectedIconChanged" /* 700000F1 */
		/* 0x00002344 17                 */ IL_015c: ldc.i4.1
		/* 0x00002345 D00100001B         */ IL_015d: ldtoken class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon> /* 1B000001 */
		/* 0x0000234A 282400000A         */ IL_0162: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000234F D003000002         */ IL_0167: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002354 282400000A         */ IL_016c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002359 282D00000A         */ IL_0171: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x0000235E 8008000004         */ IL_0176: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconChangedEvent /* 04000008 */
		/* 0x00002363 7219010070         */ IL_017b: ldstr "CurrentCategoryChanged" /* 70000119 */
		/* 0x00002368 17                 */ IL_0180: ldc.i4.1
		/* 0x00002369 D00200001B         */ IL_0181: ldtoken class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category> /* 1B000002 */
		/* 0x0000236E 282400000A         */ IL_0186: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002373 D003000002         */ IL_018b: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002378 282400000A         */ IL_0190: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000237D 282D00000A         */ IL_0195: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x00002382 8009000004         */ IL_019a: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryChangedEvent /* 04000009 */
		/* 0x00002387 7E2E00000A         */ IL_019f: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x0000238C D003000002         */ IL_01a4: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002391 282400000A         */ IL_01a9: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002396 D003000002         */ IL_01ae: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x0000239B 282400000A         */ IL_01b3: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000023A0 732500000A         */ IL_01b8: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x000023A5 6F2F00000A         */ IL_01bd: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x000023AA D003000002         */ IL_01c2: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x000023AF 282400000A         */ IL_01c7: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000023B4 7E41000004         */ IL_01cc: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ClickEvent /* 04000041 */
		/* 0x000023B9 14                 */ IL_01d1: ldnull
		/* 0x000023BA FE061C000006       */ IL_01d2: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::DropdownButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600001C */
		/* 0x000023C0 733000000A         */ IL_01d8: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000030 */
		/* 0x000023C5 283100000A         */ IL_01dd: call void [PresentationCore]System.Windows.EventManager::RegisterClassHandler(class [mscorlib]System.Type, class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000031 */
		/* 0x000023CA 2A                 */ IL_01e2: ret
	} // end of method BlockTableControl::.cctor

	.method /* 0600001A */ family hidebysig newslot virtual 
		instance void OnSelectedIconChanged (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon oldSelected,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon newSelected
		) cil managed 
	{
		// Method begins at RVA 0x23d7
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x000023D7 02                 */ IL_0000: ldarg.0
		/* 0x000023D8 03                 */ IL_0001: ldarg.1
		/* 0x000023D9 04                 */ IL_0002: ldarg.2
		/* 0x000023DA 7E08000004         */ IL_0003: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::SelectedIconChangedEvent /* 04000008 */
		/* 0x000023DF 733200000A         */ IL_0008: newobj instance void class [PresentationFramework]System.Windows.RoutedPropertyChangedEventArgs`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon>::.ctor(!0, !0, class [PresentationCore]System.Windows.RoutedEvent) /* 0A000032 */
		/* 0x000023E4 283300000A         */ IL_000d: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x000023E9 2A                 */ IL_0012: ret
	} // end of method BlockTableControl::OnSelectedIconChanged

	.method /* 0600001B */ family hidebysig newslot virtual 
		instance void OnCurrentCategoryChanged (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category oldSelected,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category newSelected
		) cil managed 
	{
		// Method begins at RVA 0x23eb
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x000023EB 02                 */ IL_0000: ldarg.0
		/* 0x000023EC 03                 */ IL_0001: ldarg.1
		/* 0x000023ED 04                 */ IL_0002: ldarg.2
		/* 0x000023EE 7E09000004         */ IL_0003: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::CurrentCategoryChangedEvent /* 04000009 */
		/* 0x000023F3 733400000A         */ IL_0008: newobj instance void class [PresentationFramework]System.Windows.RoutedPropertyChangedEventArgs`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::.ctor(!0, !0, class [PresentationCore]System.Windows.RoutedEvent) /* 0A000034 */
		/* 0x000023F8 283300000A         */ IL_000d: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x000023FD 2A                 */ IL_0012: ret
	} // end of method BlockTableControl::OnCurrentCategoryChanged

	.method /* 0600001C */ private hidebysig static 
		void DropdownButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2400
		// Header size: 12
		// Code size: 35 (0x23)
		.maxstack 2
		.locals /* 11000001 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton
		)

		/* 0x00002400 03                 */ IL_0000: ldarg.1
		/* 0x00002401 6F3500000A         */ IL_0001: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000035 */
		/* 0x00002406 750F000002         */ IL_0006: isinst AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x0000240B 0A                 */ IL_000b: stloc.0
		/* 0x0000240C 02                 */ IL_000c: ldarg.0
		/* 0x0000240D 7503000002         */ IL_000d: isinst AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002412 06                 */ IL_0012: ldloc.0
		/* 0x00002413 6F3600000A         */ IL_0013: callvirt instance object [PresentationFramework]System.Windows.Controls.Primitives.Selector::get_SelectedItem() /* 0A000036 */
		/* 0x00002418 7507000002         */ IL_0018: isinst AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x0000241D 6F10000006         */ IL_001d: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_SelectedIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon) /* 06000010 */
		/* 0x00002422 2A                 */ IL_0022: ret
	} // end of method BlockTableControl::DropdownButton_Click

	.method /* 0600001D */ private hidebysig static 
		void OnSelectedIconPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2430
		// Header size: 12
		// Code size: 229 (0xe5)
		.maxstack 3
		.locals /* 11000002 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl,
			[1] class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>,
			[2] class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>
		)

		/* 0x00002430 02                 */ IL_0000: ldarg.0
		/* 0x00002431 7503000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002436 0A                 */ IL_0006: stloc.0
		/* 0x00002437 06                 */ IL_0007: ldloc.0
		/* 0x00002438 6F0F000006         */ IL_0008: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_SelectedIcon() /* 0600000F */
		/* 0x0000243D 2C62               */ IL_000d: brfalse.s IL_0071
		/* 0x0000243F 06                 */ IL_000f: ldloc.0
		/* 0x00002440 6F09000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_Categories() /* 06000009 */
		/* 0x00002445 6F3700000A         */ IL_0015: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::GetEnumerator() /* 0A000037 */
		/* 0x0000244A 0B                 */ IL_001a: stloc.1
		/* 0x0000244B 2B40               */ IL_001b: br.s IL_005d
		/* 0x0000244D 07                 */ IL_001d: ldloc.1
		/* 0x0000244E 6F3800000A         */ IL_001e: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::get_Current() /* 0A000038 */
		/* 0x00002453 6F2B000006         */ IL_0023: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Models() /* 0600002B */
		/* 0x00002458 6F3900000A         */ IL_0028: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>::GetEnumerator() /* 0A000039 */
		/* 0x0000245D 0C                 */ IL_002d: stloc.2
		/* 0x0000245E 2B19               */ IL_002e: br.s IL_0049
		/* 0x00002460 08                 */ IL_0030: ldloc.2
		/* 0x00002461 6F3A00000A         */ IL_0031: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>::get_Current() /* 0A00003A */
		/* 0x00002466 25                 */ IL_0036: dup
		/* 0x00002467 06                 */ IL_0037: ldloc.0
		/* 0x00002468 6F0F000006         */ IL_0038: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_SelectedIcon() /* 0600000F */
		/* 0x0000246D 6F37000006         */ IL_003d: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_Parent() /* 06000037 */
		/* 0x00002472 FE01               */ IL_0042: ceq
		/* 0x00002474 6F4C000006         */ IL_0044: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_IsChecked(bool) /* 0600004C */
		/* 0x00002479 08                 */ IL_0049: ldloc.2
		/* 0x0000247A 6F3B00000A         */ IL_004a: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A00003B */
		/* 0x0000247F 2DDF               */ IL_004f: brtrue.s IL_0030
		/* 0x00002481 DE0A               */ IL_0051: leave.s IL_005d
		/* 0x00002483 08                 */ IL_0053: ldloc.2
		/* 0x00002484 2C06               */ IL_0054: brfalse.s IL_005c
		/* 0x00002486 08                 */ IL_0056: ldloc.2
		/* 0x00002487 6F3C00000A         */ IL_0057: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00003C */
		/* 0x0000248C DC                 */ IL_005c: endfinally
		/* 0x0000248D 07                 */ IL_005d: ldloc.1
		/* 0x0000248E 6F3B00000A         */ IL_005e: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A00003B */
		/* 0x00002493 2DB8               */ IL_0063: brtrue.s IL_001d
		/* 0x00002495 DE5F               */ IL_0065: leave.s IL_00c6
		/* 0x00002497 07                 */ IL_0067: ldloc.1
		/* 0x00002498 2C06               */ IL_0068: brfalse.s IL_0070
		/* 0x0000249A 07                 */ IL_006a: ldloc.1
		/* 0x0000249B 6F3C00000A         */ IL_006b: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00003C */
		/* 0x000024A0 DC                 */ IL_0070: endfinally
		/* 0x000024A1 06                 */ IL_0071: ldloc.0
		/* 0x000024A2 6F09000006         */ IL_0072: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_Categories() /* 06000009 */
		/* 0x000024A7 6F3700000A         */ IL_0077: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::GetEnumerator() /* 0A000037 */
		/* 0x000024AC 0B                 */ IL_007c: stloc.1
		/* 0x000024AD 2B33               */ IL_007d: br.s IL_00b2
		/* 0x000024AF 07                 */ IL_007f: ldloc.1
		/* 0x000024B0 6F3800000A         */ IL_0080: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::get_Current() /* 0A000038 */
		/* 0x000024B5 6F2B000006         */ IL_0085: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Models() /* 0600002B */
		/* 0x000024BA 6F3900000A         */ IL_008a: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>::GetEnumerator() /* 0A000039 */
		/* 0x000024BF 0C                 */ IL_008f: stloc.2
		/* 0x000024C0 2B0C               */ IL_0090: br.s IL_009e
		/* 0x000024C2 08                 */ IL_0092: ldloc.2
		/* 0x000024C3 6F3A00000A         */ IL_0093: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>::get_Current() /* 0A00003A */
		/* 0x000024C8 16                 */ IL_0098: ldc.i4.0
		/* 0x000024C9 6F4C000006         */ IL_0099: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_IsChecked(bool) /* 0600004C */
		/* 0x000024CE 08                 */ IL_009e: ldloc.2
		/* 0x000024CF 6F3B00000A         */ IL_009f: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A00003B */
		/* 0x000024D4 2DEC               */ IL_00a4: brtrue.s IL_0092
		/* 0x000024D6 DE0A               */ IL_00a6: leave.s IL_00b2
		/* 0x000024D8 08                 */ IL_00a8: ldloc.2
		/* 0x000024D9 2C06               */ IL_00a9: brfalse.s IL_00b1
		/* 0x000024DB 08                 */ IL_00ab: ldloc.2
		/* 0x000024DC 6F3C00000A         */ IL_00ac: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00003C */
		/* 0x000024E1 DC                 */ IL_00b1: endfinally
		/* 0x000024E2 07                 */ IL_00b2: ldloc.1
		/* 0x000024E3 6F3B00000A         */ IL_00b3: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A00003B */
		/* 0x000024E8 2DC5               */ IL_00b8: brtrue.s IL_007f
		/* 0x000024EA DE0A               */ IL_00ba: leave.s IL_00c6
		/* 0x000024EC 07                 */ IL_00bc: ldloc.1
		/* 0x000024ED 2C06               */ IL_00bd: brfalse.s IL_00c5
		/* 0x000024EF 07                 */ IL_00bf: ldloc.1
		/* 0x000024F0 6F3C00000A         */ IL_00c0: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00003C */
		/* 0x000024F5 DC                 */ IL_00c5: endfinally
		/* 0x000024F6 06                 */ IL_00c6: ldloc.0
		/* 0x000024F7 0F01               */ IL_00c7: ldarga.s e
		/* 0x000024F9 283D00000A         */ IL_00c9: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_OldValue() /* 0A00003D */
		/* 0x000024FE 7507000002         */ IL_00ce: isinst AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x00002503 0F01               */ IL_00d3: ldarga.s e
		/* 0x00002505 283E00000A         */ IL_00d5: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00003E */
		/* 0x0000250A 7507000002         */ IL_00da: isinst AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x0000250F 6F1A000006         */ IL_00df: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::OnSelectedIconChanged(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon, class AspenTech.AspenPlus.ModelLibrary.Controls.Icon) /* 0600001A */
		/* 0x00002514 2A                 */ IL_00e4: ret

		.try IL_002e-IL_0053 finally IL_0053-IL_005d
		.try IL_001b-IL_0067 finally IL_0067-IL_0071
		.try IL_0090-IL_00a8 finally IL_00a8-IL_00b2
		.try IL_007d-IL_00bc finally IL_00bc-IL_00c6
	} // end of method BlockTableControl::OnSelectedIconPropertyChanged

	.method /* 0600001E */ private hidebysig static 
		void OnCurrentCategoryPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x2558
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x00002558 02                 */ IL_0000: ldarg.0
		/* 0x00002559 7503000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x0000255E 0F01               */ IL_0006: ldarga.s e
		/* 0x00002560 283D00000A         */ IL_0008: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_OldValue() /* 0A00003D */
		/* 0x00002565 7404000002         */ IL_000d: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Category /* 02000004 */
		/* 0x0000256A 0F01               */ IL_0012: ldarga.s e
		/* 0x0000256C 283E00000A         */ IL_0014: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00003E */
		/* 0x00002571 7404000002         */ IL_0019: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Category /* 02000004 */
		/* 0x00002576 6F1B000006         */ IL_001e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::OnCurrentCategoryChanged(class AspenTech.AspenPlus.ModelLibrary.Controls.Category, class AspenTech.AspenPlus.ModelLibrary.Controls.Category) /* 0600001B */
		/* 0x0000257B 2A                 */ IL_0023: ret
	} // end of method BlockTableControl::OnCurrentCategoryPropertyChanged

	.method /* 0600001F */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x257d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000257D 02                 */ IL_0000: ldarg.0
		/* 0x0000257E 283F00000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Control::.ctor() /* 0A00003F */
		/* 0x00002583 2A                 */ IL_0006: ret
	} // end of method BlockTableControl::.ctor

	// Events
	.event /* 14000001 */ class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon> SelectedIconChanged
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::add_SelectedIconChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon>)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::remove_SelectedIconChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon>)
	}

	.event /* 14000002 */ class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category> CurrentCategoryChanged
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::add_CurrentCategoryChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::remove_CurrentCategoryChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>)
	}


	// Properties
	.property /* 17000001 */ instance valuetype [PresentationFramework]System.Windows.Controls.Dock Dock()
	{
		.get instance valuetype [PresentationFramework]System.Windows.Controls.Dock AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_Dock()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_Dock(valuetype [PresentationFramework]System.Windows.Controls.Dock)
	}
	.property /* 17000002 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection Categories()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_Categories()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_Categories(class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection)
	}
	.property /* 17000003 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category CurrentCategory()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_CurrentCategory()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_CurrentCategory(class AspenTech.AspenPlus.ModelLibrary.Controls.Category)
	}
	.property /* 17000004 */ instance valuetype [WindowsBase]System.Windows.Size ButtonSize()
	{
		.get instance valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_ButtonSize()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_ButtonSize(valuetype [WindowsBase]System.Windows.Size)
	}
	.property /* 17000005 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon SelectedIcon()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_SelectedIcon()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_SelectedIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon)
	}
	.property /* 17000006 */ instance class [PresentationCore]System.Windows.Media.Brush DefaultButtonBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_DefaultButtonBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_DefaultButtonBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000007 */ instance class [PresentationCore]System.Windows.Media.Brush CheckedButtonBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_CheckedButtonBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::set_CheckedButtonBackground(class [PresentationCore]System.Windows.Media.Brush)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl

.class /* 02000004 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Category
	extends AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase
{
	.custom /* 0C000015 */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 06 4d 6f 64 65 6c 73 00 00
	)
	// Fields
	.field /* 0400000A */ private object _header
	.field /* 0400000B */ private object _name
	.field /* 0400000C */ private class AspenTech.AspenPlus.ModelLibrary.Controls.Model _selectedModel
	.field /* 0400000D */ private bool _isStreamCategory
	.field /* 0400000E */ public string HelpFile
	.field /* 0400000F */ private int32 '<HelpId>k__BackingField'
	.custom /* 0C00001F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000010 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection '<Models>k__BackingField'
	.custom /* 0C000022 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000011 */ private object '<Data>k__BackingField'
	.custom /* 0C000024 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000020 */ public hidebysig specialname 
		instance int32 get_HelpId () cil managed 
	{
		.custom /* 0C000030 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2585
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002585 02                 */ IL_0000: ldarg.0
		/* 0x00002586 7B0F000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.Category::'<HelpId>k__BackingField' /* 0400000F */
		/* 0x0000258B 2A                 */ IL_0006: ret
	} // end of method Category::get_HelpId

	.method /* 06000021 */ private hidebysig specialname 
		instance void set_HelpId (
			int32 'value'
		) cil managed 
	{
		.custom /* 0C000032 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x258d
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000258D 02                 */ IL_0000: ldarg.0
		/* 0x0000258E 03                 */ IL_0001: ldarg.1
		/* 0x0000258F 7D0F000004         */ IL_0002: stfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.Category::'<HelpId>k__BackingField' /* 0400000F */
		/* 0x00002594 2A                 */ IL_0007: ret
	} // end of method Category::set_HelpId

	.method /* 06000022 */ private hidebysig 
		instance void SetHelpIdByName () cil managed 
	{
		// Method begins at RVA 0x2598
		// Header size: 12
		// Code size: 407 (0x197)
		.maxstack 2
		.locals /* 11000003 */ init (
			[0] string,
			[1] int32,
			[2] char
		)

		/* 0x00002598 02                 */ IL_0000: ldarg.0
		/* 0x00002599 2823000006         */ IL_0001: call instance object AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Header() /* 06000023 */
		/* 0x0000259E 755A000001         */ IL_0006: isinst [mscorlib]System.String /* 0100005A */
		/* 0x000025A3 0A                 */ IL_000b: stloc.0
		/* 0x000025A4 06                 */ IL_000c: ldloc.0
		/* 0x000025A5 397C010000         */ IL_000d: brfalse IL_018e
		/* 0x000025AA 06                 */ IL_0012: ldloc.0
		/* 0x000025AB 284000000A         */ IL_0013: call instance int32 [mscorlib]System.String::get_Length() /* 0A000040 */
		/* 0x000025B0 0B                 */ IL_0018: stloc.1
		/* 0x000025B1 07                 */ IL_0019: ldloc.1
		/* 0x000025B2 1C                 */ IL_001a: ldc.i4.6
		/* 0x000025B3 59                 */ IL_001b: sub
		/* 0x000025B4 450C000000         */ IL_001c: switch (
		/*              CC000000         */                  IL_011d,
		/*              72000000         */                  IL_00c3,
		/*              87000000         */                  IL_00d8,
		/*              3D010000         */                  IL_018e,
		/*              05000000         */                  IL_0056,
		/*              DB000000         */                  IL_012c,
		/*              BD000000         */                  IL_010e,
		/*              3D010000         */                  IL_018e,
		/*              3D010000         */                  IL_018e,
		/*              3D010000         */                  IL_018e,
		/*              33000000         */                  IL_0084,
		/*              1C000000         */                  IL_006d)
		/* 0x000025E9 3838010000         */ IL_0051: br IL_018e
		/* 0x000025EE 06                 */ IL_0056: ldloc.0
		/* 0x000025EF 16                 */ IL_0057: ldc.i4.0
		/* 0x000025F0 284100000A         */ IL_0058: call instance char [mscorlib]System.String::get_Chars(int32) /* 0A000041 */
		/* 0x000025F5 0C                 */ IL_005d: stloc.2
		/* 0x000025F6 08                 */ IL_005e: ldloc.2
		/* 0x000025F7 1F45               */ IL_005f: ldc.i4.s 69
		/* 0x000025F9 2E4B               */ IL_0061: beq.s IL_00ae
		/* 0x000025FB 08                 */ IL_0063: ldloc.2
		/* 0x000025FC 1F53               */ IL_0064: ldc.i4.s 83
		/* 0x000025FE 2E31               */ IL_0066: beq.s IL_0099
		/* 0x00002600 3821010000         */ IL_0068: br IL_018e
		/* 0x00002605 06                 */ IL_006d: ldloc.0
		/* 0x00002606 16                 */ IL_006e: ldc.i4.0
		/* 0x00002607 284100000A         */ IL_006f: call instance char [mscorlib]System.String::get_Chars(int32) /* 0A000041 */
		/* 0x0000260C 0C                 */ IL_0074: stloc.2
		/* 0x0000260D 08                 */ IL_0075: ldloc.2
		/* 0x0000260E 1F50               */ IL_0076: ldc.i4.s 80
		/* 0x00002610 2E70               */ IL_0078: beq.s IL_00ea
		/* 0x00002612 08                 */ IL_007a: ldloc.2
		/* 0x00002613 1F53               */ IL_007b: ldc.i4.s 83
		/* 0x00002615 2E7D               */ IL_007d: beq.s IL_00fc
		/* 0x00002617 380A010000         */ IL_007f: br IL_018e
		/* 0x0000261C 06                 */ IL_0084: ldloc.0
		/* 0x0000261D 7247010070         */ IL_0085: ldstr "Mixers/Splitters" /* 70000147 */
		/* 0x00002622 284200000A         */ IL_008a: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x00002627 3AA7000000         */ IL_008f: brtrue IL_013b
		/* 0x0000262C 38F5000000         */ IL_0094: br IL_018e
		/* 0x00002631 06                 */ IL_0099: ldloc.0
		/* 0x00002632 7269010070         */ IL_009a: ldstr "Separators" /* 70000169 */
		/* 0x00002637 284200000A         */ IL_009f: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x0000263C 3A9A000000         */ IL_00a4: brtrue IL_0143
		/* 0x00002641 38E0000000         */ IL_00a9: br IL_018e
		/* 0x00002646 06                 */ IL_00ae: ldloc.0
		/* 0x00002647 727F010070         */ IL_00af: ldstr "Exchangers" /* 7000017F */
		/* 0x0000264C 284200000A         */ IL_00b4: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x00002651 3A8D000000         */ IL_00b9: brtrue IL_014b
		/* 0x00002656 38CB000000         */ IL_00be: br IL_018e
		/* 0x0000265B 06                 */ IL_00c3: ldloc.0
		/* 0x0000265C 7295010070         */ IL_00c4: ldstr "Columns" /* 70000195 */
		/* 0x00002661 284200000A         */ IL_00c9: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x00002666 3A80000000         */ IL_00ce: brtrue IL_0153
		/* 0x0000266B 38B6000000         */ IL_00d3: br IL_018e
		/* 0x00002670 06                 */ IL_00d8: ldloc.0
		/* 0x00002671 72A5010070         */ IL_00d9: ldstr "Reactors" /* 700001A5 */
		/* 0x00002676 284200000A         */ IL_00de: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x0000267B 2D76               */ IL_00e3: brtrue.s IL_015b
		/* 0x0000267D 38A4000000         */ IL_00e5: br IL_018e
		/* 0x00002682 06                 */ IL_00ea: ldloc.0
		/* 0x00002683 72B7010070         */ IL_00eb: ldstr "Pressure Changers" /* 700001B7 */
		/* 0x00002688 284200000A         */ IL_00f0: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x0000268D 2D6C               */ IL_00f5: brtrue.s IL_0163
		/* 0x0000268F 3892000000         */ IL_00f7: br IL_018e
		/* 0x00002694 06                 */ IL_00fc: ldloc.0
		/* 0x00002695 72DB010070         */ IL_00fd: ldstr "Solids Separators" /* 700001DB */
		/* 0x0000269A 284200000A         */ IL_0102: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x0000269F 2D73               */ IL_0107: brtrue.s IL_017c
		/* 0x000026A1 3880000000         */ IL_0109: br IL_018e
		/* 0x000026A6 06                 */ IL_010e: ldloc.0
		/* 0x000026A7 72FF010070         */ IL_010f: ldstr "Manipulators" /* 700001FF */
		/* 0x000026AC 284200000A         */ IL_0114: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x000026B1 2D50               */ IL_0119: brtrue.s IL_016b
		/* 0x000026B3 2B71               */ IL_011b: br.s IL_018e
		/* 0x000026B5 06                 */ IL_011d: ldloc.0
		/* 0x000026B6 7219020070         */ IL_011e: ldstr "Solids" /* 70000219 */
		/* 0x000026BB 284200000A         */ IL_0123: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x000026C0 2D49               */ IL_0128: brtrue.s IL_0173
		/* 0x000026C2 2B62               */ IL_012a: br.s IL_018e
		/* 0x000026C4 06                 */ IL_012c: ldloc.0
		/* 0x000026C5 7227020070         */ IL_012d: ldstr "User Models" /* 70000227 */
		/* 0x000026CA 284200000A         */ IL_0132: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x000026CF 2D4C               */ IL_0137: brtrue.s IL_0185
		/* 0x000026D1 2B53               */ IL_0139: br.s IL_018e
		/* 0x000026D3 02                 */ IL_013b: ldarg.0
		/* 0x000026D4 18                 */ IL_013c: ldc.i4.2
		/* 0x000026D5 2821000006         */ IL_013d: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x000026DA 2A                 */ IL_0142: ret
		/* 0x000026DB 02                 */ IL_0143: ldarg.0
		/* 0x000026DC 19                 */ IL_0144: ldc.i4.3
		/* 0x000026DD 2821000006         */ IL_0145: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x000026E2 2A                 */ IL_014a: ret
		/* 0x000026E3 02                 */ IL_014b: ldarg.0
		/* 0x000026E4 1A                 */ IL_014c: ldc.i4.4
		/* 0x000026E5 2821000006         */ IL_014d: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x000026EA 2A                 */ IL_0152: ret
		/* 0x000026EB 02                 */ IL_0153: ldarg.0
		/* 0x000026EC 1B                 */ IL_0154: ldc.i4.5
		/* 0x000026ED 2821000006         */ IL_0155: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x000026F2 2A                 */ IL_015a: ret
		/* 0x000026F3 02                 */ IL_015b: ldarg.0
		/* 0x000026F4 1C                 */ IL_015c: ldc.i4.6
		/* 0x000026F5 2821000006         */ IL_015d: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x000026FA 2A                 */ IL_0162: ret
		/* 0x000026FB 02                 */ IL_0163: ldarg.0
		/* 0x000026FC 1D                 */ IL_0164: ldc.i4.7
		/* 0x000026FD 2821000006         */ IL_0165: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x00002702 2A                 */ IL_016a: ret
		/* 0x00002703 02                 */ IL_016b: ldarg.0
		/* 0x00002704 1E                 */ IL_016c: ldc.i4.8
		/* 0x00002705 2821000006         */ IL_016d: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x0000270A 2A                 */ IL_0172: ret
		/* 0x0000270B 02                 */ IL_0173: ldarg.0
		/* 0x0000270C 1F09               */ IL_0174: ldc.i4.s 9
		/* 0x0000270E 2821000006         */ IL_0176: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x00002713 2A                 */ IL_017b: ret
		/* 0x00002714 02                 */ IL_017c: ldarg.0
		/* 0x00002715 1F0A               */ IL_017d: ldc.i4.s 10
		/* 0x00002717 2821000006         */ IL_017f: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x0000271C 2A                 */ IL_0184: ret
		/* 0x0000271D 02                 */ IL_0185: ldarg.0
		/* 0x0000271E 1F0B               */ IL_0186: ldc.i4.s 11
		/* 0x00002720 2821000006         */ IL_0188: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x00002725 2A                 */ IL_018d: ret
		/* 0x00002726 02                 */ IL_018e: ldarg.0
		/* 0x00002727 1F0C               */ IL_018f: ldc.i4.s 12
		/* 0x00002729 2821000006         */ IL_0191: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32) /* 06000021 */
		/* 0x0000272E 2A                 */ IL_0196: ret
	} // end of method Category::SetHelpIdByName

	.method /* 06000023 */ public hidebysig specialname 
		instance object get_Header () cil managed 
	{
		// Method begins at RVA 0x273b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000273B 02                 */ IL_0000: ldarg.0
		/* 0x0000273C 7B0A000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_header /* 0400000A */
		/* 0x00002741 2A                 */ IL_0006: ret
	} // end of method Category::get_Header

	.method /* 06000024 */ public hidebysig specialname 
		instance void set_Header (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2743
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002743 02                 */ IL_0000: ldarg.0
		/* 0x00002744 7B0A000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_header /* 0400000A */
		/* 0x00002749 03                 */ IL_0006: ldarg.1
		/* 0x0000274A 2E12               */ IL_0007: beq.s IL_001b
		/* 0x0000274C 02                 */ IL_0009: ldarg.0
		/* 0x0000274D 03                 */ IL_000a: ldarg.1
		/* 0x0000274E 7D0A000004         */ IL_000b: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_header /* 0400000A */
		/* 0x00002753 02                 */ IL_0010: ldarg.0
		/* 0x00002754 723F020070         */ IL_0011: ldstr "Header" /* 7000023F */
		/* 0x00002759 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x0000275E 2A                 */ IL_001b: ret
	} // end of method Category::set_Header

	.method /* 06000025 */ public hidebysig specialname 
		instance object get_Name () cil managed 
	{
		// Method begins at RVA 0x2760
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002760 02                 */ IL_0000: ldarg.0
		/* 0x00002761 7B0B000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_name /* 0400000B */
		/* 0x00002766 2A                 */ IL_0006: ret
	} // end of method Category::get_Name

	.method /* 06000026 */ public hidebysig specialname 
		instance void set_Name (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2768
		// Header size: 1
		// Code size: 61 (0x3d)
		.maxstack 8

		/* 0x00002768 02                 */ IL_0000: ldarg.0
		/* 0x00002769 7B0B000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_name /* 0400000B */
		/* 0x0000276E 03                 */ IL_0006: ldarg.1
		/* 0x0000276F 2E33               */ IL_0007: beq.s IL_003c
		/* 0x00002771 03                 */ IL_0009: ldarg.1
		/* 0x00002772 745A000001         */ IL_000a: castclass [mscorlib]System.String /* 0100005A */
		/* 0x00002777 284300000A         */ IL_000f: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000043 */
		/* 0x0000277C 2C0E               */ IL_0014: brfalse.s IL_0024
		/* 0x0000277E 02                 */ IL_0016: ldarg.0
		/* 0x0000277F 02                 */ IL_0017: ldarg.0
		/* 0x00002780 7B0A000004         */ IL_0018: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_header /* 0400000A */
		/* 0x00002785 7D0B000004         */ IL_001d: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_name /* 0400000B */
		/* 0x0000278A 2B07               */ IL_0022: br.s IL_002b
		/* 0x0000278C 02                 */ IL_0024: ldarg.0
		/* 0x0000278D 03                 */ IL_0025: ldarg.1
		/* 0x0000278E 7D0B000004         */ IL_0026: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::_name /* 0400000B */
		/* 0x00002793 02                 */ IL_002b: ldarg.0
		/* 0x00002794 724D020070         */ IL_002c: ldstr "Name" /* 7000024D */
		/* 0x00002799 6F80000006         */ IL_0031: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x0000279E 02                 */ IL_0036: ldarg.0
		/* 0x0000279F 2822000006         */ IL_0037: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::SetHelpIdByName() /* 06000022 */
		/* 0x000027A4 2A                 */ IL_003c: ret
	} // end of method Category::set_Name

	.method /* 06000027 */ public hidebysig specialname 
		instance bool get_IsStreamCategory () cil managed 
	{
		// Method begins at RVA 0x27a6
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000027A6 02                 */ IL_0000: ldarg.0
		/* 0x000027A7 7B0D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.ModelLibrary.Controls.Category::_isStreamCategory /* 0400000D */
		/* 0x000027AC 2A                 */ IL_0006: ret
	} // end of method Category::get_IsStreamCategory

	.method /* 06000028 */ public hidebysig specialname 
		instance void set_IsStreamCategory (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x27ae
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000027AE 02                 */ IL_0000: ldarg.0
		/* 0x000027AF 7B0D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.ModelLibrary.Controls.Category::_isStreamCategory /* 0400000D */
		/* 0x000027B4 03                 */ IL_0006: ldarg.1
		/* 0x000027B5 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000027B7 02                 */ IL_0009: ldarg.0
		/* 0x000027B8 03                 */ IL_000a: ldarg.1
		/* 0x000027B9 7D0D000004         */ IL_000b: stfld bool AspenTech.AspenPlus.ModelLibrary.Controls.Category::_isStreamCategory /* 0400000D */
		/* 0x000027BE 02                 */ IL_0010: ldarg.0
		/* 0x000027BF 7257020070         */ IL_0011: ldstr "IsStreamCategory" /* 70000257 */
		/* 0x000027C4 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x000027C9 2A                 */ IL_001b: ret
	} // end of method Category::set_IsStreamCategory

	.method /* 06000029 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model get_SelectedModel () cil managed 
	{
		// Method begins at RVA 0x27cb
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000027CB 02                 */ IL_0000: ldarg.0
		/* 0x000027CC 7B0C000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Category::_selectedModel /* 0400000C */
		/* 0x000027D1 2A                 */ IL_0006: ret
	} // end of method Category::get_SelectedModel

	.method /* 0600002A */ public hidebysig specialname 
		instance void set_SelectedModel (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model 'value'
		) cil managed 
	{
		// Method begins at RVA 0x27d3
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000027D3 02                 */ IL_0000: ldarg.0
		/* 0x000027D4 7B0C000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Category::_selectedModel /* 0400000C */
		/* 0x000027D9 03                 */ IL_0006: ldarg.1
		/* 0x000027DA 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000027DC 02                 */ IL_0009: ldarg.0
		/* 0x000027DD 03                 */ IL_000a: ldarg.1
		/* 0x000027DE 7D0C000004         */ IL_000b: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Category::_selectedModel /* 0400000C */
		/* 0x000027E3 02                 */ IL_0010: ldarg.0
		/* 0x000027E4 7279020070         */ IL_0011: ldstr "SelectedModel" /* 70000279 */
		/* 0x000027E9 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x000027EE 2A                 */ IL_001b: ret
	} // end of method Category::set_SelectedModel

	.method /* 0600002B */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection get_Models () cil managed 
	{
		.custom /* 0C000035 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x27f0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000027F0 02                 */ IL_0000: ldarg.0
		/* 0x000027F1 7B10000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection AspenTech.AspenPlus.ModelLibrary.Controls.Category::'<Models>k__BackingField' /* 04000010 */
		/* 0x000027F6 2A                 */ IL_0006: ret
	} // end of method Category::get_Models

	.method /* 0600002C */ private hidebysig specialname 
		instance void set_Models (
			class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection 'value'
		) cil managed 
	{
		.custom /* 0C000036 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x27f8
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000027F8 02                 */ IL_0000: ldarg.0
		/* 0x000027F9 03                 */ IL_0001: ldarg.1
		/* 0x000027FA 7D10000004         */ IL_0002: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection AspenTech.AspenPlus.ModelLibrary.Controls.Category::'<Models>k__BackingField' /* 04000010 */
		/* 0x000027FF 2A                 */ IL_0007: ret
	} // end of method Category::set_Models

	.method /* 0600002D */ public hidebysig specialname 
		instance object get_Data () cil managed 
	{
		.custom /* 0C000037 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2801
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002801 02                 */ IL_0000: ldarg.0
		/* 0x00002802 7B11000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::'<Data>k__BackingField' /* 04000011 */
		/* 0x00002807 2A                 */ IL_0006: ret
	} // end of method Category::get_Data

	.method /* 0600002E */ public hidebysig specialname 
		instance void set_Data (
			object 'value'
		) cil managed 
	{
		.custom /* 0C000038 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2809
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002809 02                 */ IL_0000: ldarg.0
		/* 0x0000280A 03                 */ IL_0001: ldarg.1
		/* 0x0000280B 7D11000004         */ IL_0002: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Category::'<Data>k__BackingField' /* 04000011 */
		/* 0x00002810 2A                 */ IL_0007: ret
	} // end of method Category::set_Data

	.method /* 0600002F */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2812
		// Header size: 1
		// Code size: 30 (0x1e)
		.maxstack 8

		/* 0x00002812 02                 */ IL_0000: ldarg.0
		/* 0x00002813 7295020070         */ IL_0001: ldstr "Palette.chm" /* 70000295 */
		/* 0x00002818 7D0E000004         */ IL_0006: stfld string AspenTech.AspenPlus.ModelLibrary.Controls.Category::HelpFile /* 0400000E */
		/* 0x0000281D 02                 */ IL_000b: ldarg.0
		/* 0x0000281E 2881000006         */ IL_000c: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::.ctor() /* 06000081 */
		/* 0x00002823 02                 */ IL_0011: ldarg.0
		/* 0x00002824 02                 */ IL_0012: ldarg.0
		/* 0x00002825 7359000006         */ IL_0013: newobj instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection::.ctor(class AspenTech.AspenPlus.ModelLibrary.Controls.Category) /* 06000059 */
		/* 0x0000282A 282C000006         */ IL_0018: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_Models(class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection) /* 0600002C */
		/* 0x0000282F 2A                 */ IL_001d: ret
	} // end of method Category::.ctor

	// Properties
	.property /* 17000008 */ instance int32 HelpId()
	{
		.get instance int32 AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_HelpId()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_HelpId(int32)
	}
	.property /* 17000009 */ instance object Header()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Header()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_Header(object)
	}
	.property /* 1700000A */ instance object Name()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Name()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_Name(object)
	}
	.property /* 1700000B */ instance bool IsStreamCategory()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_IsStreamCategory()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_IsStreamCategory(bool)
	}
	.property /* 1700000C */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model SelectedModel()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_SelectedModel()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_SelectedModel(class AspenTech.AspenPlus.ModelLibrary.Controls.Model)
	}
	.property /* 1700000D */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection Models()
	{
		.custom /* 0C00001E */ instance void [System]System.ComponentModel.DesignerSerializationVisibilityAttribute::.ctor(valuetype [System]System.ComponentModel.DesignerSerializationVisibility) = (
			01 00 02 00 00 00 00 00
		)
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Models()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_Models(class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection)
	}
	.property /* 1700000E */ instance object Data()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Data()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Category::set_Data(object)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Category

.class /* 02000005 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection
	extends class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>
{
	// Methods
	.method /* 06000030 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2831
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002831 02                 */ IL_0000: ldarg.0
		/* 0x00002832 284400000A         */ IL_0001: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::.ctor() /* 0A000044 */
		/* 0x00002837 2A                 */ IL_0006: ret
	} // end of method CategoryCollection::.ctor

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection

.class /* 02000006 */ public auto ansi abstract sealed beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Extensions
	extends [mscorlib]System.Object
{
	.custom /* 0C000016 */ instance void [mscorlib]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
		01 00 00 00
	)
	// Methods
	.method /* 06000031 */ public hidebysig static 
		class AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton GetMouseDropdownButton (
			class [PresentationCore]System.Windows.Input.MouseEventArgs mouseEventArgs,
			class [PresentationFramework]System.Windows.Controls.Control control
		) cil managed 
	{
		.custom /* 0C000039 */ instance void [mscorlib]System.Runtime.CompilerServices.ExtensionAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2839
		// Header size: 1
		// Code size: 46 (0x2e)
		.maxstack 8

		/* 0x00002839 02                 */ IL_0000: ldarg.0
		/* 0x0000283A 2D0B               */ IL_0001: brtrue.s IL_000e
		/* 0x0000283C 72AD020070         */ IL_0003: ldstr "mouseEventArgs" /* 700002AD */
		/* 0x00002841 734500000A         */ IL_0008: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000045 */
		/* 0x00002846 7A                 */ IL_000d: throw
		/* 0x00002847 03                 */ IL_000e: ldarg.1
		/* 0x00002848 2D0B               */ IL_000f: brtrue.s IL_001c
		/* 0x0000284A 72CB020070         */ IL_0011: ldstr "control" /* 700002CB */
		/* 0x0000284F 734500000A         */ IL_0016: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000045 */
		/* 0x00002854 7A                 */ IL_001b: throw
		/* 0x00002855 02                 */ IL_001c: ldarg.0
		/* 0x00002856 6F3500000A         */ IL_001d: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000035 */
		/* 0x0000285B 7528000001         */ IL_0022: isinst [WindowsBase]System.Windows.DependencyObject /* 01000028 */
		/* 0x00002860 03                 */ IL_0027: ldarg.1
		/* 0x00002861 280100002B         */ IL_0028: call !!0 AspenTech.AspenPlus.ModelLibrary.Controls.Extensions::GetAncestor<class AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton>(class [WindowsBase]System.Windows.DependencyObject, class [WindowsBase]System.Windows.DependencyObject) /* 2B000001 */
		/* 0x00002866 2A                 */ IL_002d: ret
	} // end of method Extensions::GetMouseDropdownButton

	.method /* 06000032 */ public hidebysig static 
		!!T GetAncestor<class T> (
			class [WindowsBase]System.Windows.DependencyObject d,
			class [WindowsBase]System.Windows.DependencyObject parentLimit
		) cil managed 
	{
		// Method begins at RVA 0x2868
		// Header size: 12
		// Code size: 75 (0x4b)
		.maxstack 2
		.locals /* 11000004 */ init (
			[0] class [WindowsBase]System.Windows.DependencyObject,
			[1] !!T
		)

		/* 0x00002868 02                 */ IL_0000: ldarg.0
		/* 0x00002869 0A                 */ IL_0001: stloc.0
		/* 0x0000286A 06                 */ IL_0002: ldloc.0
		/* 0x0000286B 2C04               */ IL_0003: brfalse.s IL_0009
		/* 0x0000286D 06                 */ IL_0005: ldloc.0
		/* 0x0000286E 03                 */ IL_0006: ldarg.1
		/* 0x0000286F 330A               */ IL_0007: bne.un.s IL_0013
		/* 0x00002871 1201               */ IL_0009: ldloca.s 1
		/* 0x00002873 FE150E00001B       */ IL_000b: initobj !!T /* 1B00000E */
		/* 0x00002879 07                 */ IL_0011: ldloc.1
		/* 0x0000287A 2A                 */ IL_0012: ret
		/* 0x0000287B D00E00001B         */ IL_0013: ldtoken !!T /* 1B00000E */
		/* 0x00002880 282400000A         */ IL_0018: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002885 06                 */ IL_001d: ldloc.0
		/* 0x00002886 6F4600000A         */ IL_001e: callvirt instance bool [mscorlib]System.Type::IsInstanceOfType(object) /* 0A000046 */
		/* 0x0000288B 2C0C               */ IL_0023: brfalse.s IL_0031
		/* 0x0000288D 06                 */ IL_0025: ldloc.0
		/* 0x0000288E 750E00001B         */ IL_0026: isinst !!T /* 1B00000E */
		/* 0x00002893 A50E00001B         */ IL_002b: unbox.any !!T /* 1B00000E */
		/* 0x00002898 2A                 */ IL_0030: ret
		/* 0x00002899 06                 */ IL_0031: ldloc.0
		/* 0x0000289A 755C000001         */ IL_0032: isinst [PresentationCore]System.Windows.Media.Visual /* 0100005C */
		/* 0x0000289F 2C09               */ IL_0037: brfalse.s IL_0042
		/* 0x000028A1 06                 */ IL_0039: ldloc.0
		/* 0x000028A2 284700000A         */ IL_003a: call class [WindowsBase]System.Windows.DependencyObject [PresentationCore]System.Windows.Media.VisualTreeHelper::GetParent(class [WindowsBase]System.Windows.DependencyObject) /* 0A000047 */
		/* 0x000028A7 0A                 */ IL_003f: stloc.0
		/* 0x000028A8 2BC0               */ IL_0040: br.s IL_0002
		/* 0x000028AA 06                 */ IL_0042: ldloc.0
		/* 0x000028AB 284800000A         */ IL_0043: call class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.LogicalTreeHelper::GetParent(class [WindowsBase]System.Windows.DependencyObject) /* 0A000048 */
		/* 0x000028B0 0A                 */ IL_0048: stloc.0
		/* 0x000028B1 2BB7               */ IL_0049: br.s IL_0002
	} // end of method Extensions::GetAncestor

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Extensions

.class /* 02000007 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Icon
	extends AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase
{
	.custom /* 0C000017 */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 0e 44 72 61 77 69 6e 67 45 6c 65 6d 65 6e
		74 00 00
	)
	// Fields
	.field /* 04000012 */ private object _header
	.field /* 04000013 */ private class [PresentationCore]System.Windows.UIElement _drawingElement
	.field /* 04000014 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.Model '<Parent>k__BackingField'
	.custom /* 0C000026 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000015 */ private object '<Data>k__BackingField'
	.custom /* 0C000029 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000033 */ public hidebysig specialname 
		instance object get_Header () cil managed 
	{
		// Method begins at RVA 0x28bf
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000028BF 02                 */ IL_0000: ldarg.0
		/* 0x000028C0 7B12000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::_header /* 04000012 */
		/* 0x000028C5 2A                 */ IL_0006: ret
	} // end of method Icon::get_Header

	.method /* 06000034 */ public hidebysig specialname 
		instance void set_Header (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x28c7
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000028C7 02                 */ IL_0000: ldarg.0
		/* 0x000028C8 7B12000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::_header /* 04000012 */
		/* 0x000028CD 03                 */ IL_0006: ldarg.1
		/* 0x000028CE 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000028D0 02                 */ IL_0009: ldarg.0
		/* 0x000028D1 03                 */ IL_000a: ldarg.1
		/* 0x000028D2 7D12000004         */ IL_000b: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::_header /* 04000012 */
		/* 0x000028D7 02                 */ IL_0010: ldarg.0
		/* 0x000028D8 723F020070         */ IL_0011: ldstr "Header" /* 7000023F */
		/* 0x000028DD 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x000028E2 2A                 */ IL_001b: ret
	} // end of method Icon::set_Header

	.method /* 06000035 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.UIElement get_DrawingElement () cil managed 
	{
		// Method begins at RVA 0x28e4
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000028E4 02                 */ IL_0000: ldarg.0
		/* 0x000028E5 7B13000004         */ IL_0001: ldfld class [PresentationCore]System.Windows.UIElement AspenTech.AspenPlus.ModelLibrary.Controls.Icon::_drawingElement /* 04000013 */
		/* 0x000028EA 2A                 */ IL_0006: ret
	} // end of method Icon::get_DrawingElement

	.method /* 06000036 */ public hidebysig specialname 
		instance void set_DrawingElement (
			class [PresentationCore]System.Windows.UIElement 'value'
		) cil managed 
	{
		// Method begins at RVA 0x28ec
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000028EC 02                 */ IL_0000: ldarg.0
		/* 0x000028ED 7B13000004         */ IL_0001: ldfld class [PresentationCore]System.Windows.UIElement AspenTech.AspenPlus.ModelLibrary.Controls.Icon::_drawingElement /* 04000013 */
		/* 0x000028F2 03                 */ IL_0006: ldarg.1
		/* 0x000028F3 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000028F5 02                 */ IL_0009: ldarg.0
		/* 0x000028F6 03                 */ IL_000a: ldarg.1
		/* 0x000028F7 7D13000004         */ IL_000b: stfld class [PresentationCore]System.Windows.UIElement AspenTech.AspenPlus.ModelLibrary.Controls.Icon::_drawingElement /* 04000013 */
		/* 0x000028FC 02                 */ IL_0010: ldarg.0
		/* 0x000028FD 72DB020070         */ IL_0011: ldstr "DrawingElement" /* 700002DB */
		/* 0x00002902 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002907 2A                 */ IL_001b: ret
	} // end of method Icon::set_DrawingElement

	.method /* 06000037 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model get_Parent () cil managed 
	{
		.custom /* 0C00003B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2909
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002909 02                 */ IL_0000: ldarg.0
		/* 0x0000290A 7B14000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Icon::'<Parent>k__BackingField' /* 04000014 */
		/* 0x0000290F 2A                 */ IL_0006: ret
	} // end of method Icon::get_Parent

	.method /* 06000038 */ assembly hidebysig specialname 
		instance void set_Parent (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model 'value'
		) cil managed 
	{
		.custom /* 0C00003D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2911
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002911 02                 */ IL_0000: ldarg.0
		/* 0x00002912 03                 */ IL_0001: ldarg.1
		/* 0x00002913 7D14000004         */ IL_0002: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Icon::'<Parent>k__BackingField' /* 04000014 */
		/* 0x00002918 2A                 */ IL_0007: ret
	} // end of method Icon::set_Parent

	.method /* 06000039 */ public hidebysig specialname 
		instance object get_Data () cil managed 
	{
		.custom /* 0C00003E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x291a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000291A 02                 */ IL_0000: ldarg.0
		/* 0x0000291B 7B15000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::'<Data>k__BackingField' /* 04000015 */
		/* 0x00002920 2A                 */ IL_0006: ret
	} // end of method Icon::get_Data

	.method /* 0600003A */ public hidebysig specialname 
		instance void set_Data (
			object 'value'
		) cil managed 
	{
		.custom /* 0C00003F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2922
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002922 02                 */ IL_0000: ldarg.0
		/* 0x00002923 03                 */ IL_0001: ldarg.1
		/* 0x00002924 7D15000004         */ IL_0002: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::'<Data>k__BackingField' /* 04000015 */
		/* 0x00002929 2A                 */ IL_0007: ret
	} // end of method Icon::set_Data

	.method /* 0600003B */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x292b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000292B 02                 */ IL_0000: ldarg.0
		/* 0x0000292C 2881000006         */ IL_0001: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::.ctor() /* 06000081 */
		/* 0x00002931 2A                 */ IL_0006: ret
	} // end of method Icon::.ctor

	// Properties
	.property /* 1700000F */ instance object Header()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_Header()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Icon::set_Header(object)
	}
	.property /* 17000010 */ instance class [PresentationCore]System.Windows.UIElement DrawingElement()
	{
		.get instance class [PresentationCore]System.Windows.UIElement AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_DrawingElement()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Icon::set_DrawingElement(class [PresentationCore]System.Windows.UIElement)
	}
	.property /* 17000011 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model Parent()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_Parent()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Icon::set_Parent(class AspenTech.AspenPlus.ModelLibrary.Controls.Model)
	}
	.property /* 17000012 */ instance object Data()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_Data()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Icon::set_Data(object)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Icon

.class /* 02000008 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection
	extends class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon>
{
	// Fields
	.field /* 04000016 */ private initonly class AspenTech.AspenPlus.ModelLibrary.Controls.Model _parent

	// Methods
	.method /* 0600003C */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model parent
		) cil managed 
	{
		// Method begins at RVA 0x2933
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002933 02                 */ IL_0000: ldarg.0
		/* 0x00002934 284900000A         */ IL_0001: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon>::.ctor() /* 0A000049 */
		/* 0x00002939 03                 */ IL_0006: ldarg.1
		/* 0x0000293A 2D0B               */ IL_0007: brtrue.s IL_0014
		/* 0x0000293C 72F9020070         */ IL_0009: ldstr "parent" /* 700002F9 */
		/* 0x00002941 734500000A         */ IL_000e: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000045 */
		/* 0x00002946 7A                 */ IL_0013: throw
		/* 0x00002947 02                 */ IL_0014: ldarg.0
		/* 0x00002948 03                 */ IL_0015: ldarg.1
		/* 0x00002949 7D16000004         */ IL_0016: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection::_parent /* 04000016 */
		/* 0x0000294E 2A                 */ IL_001b: ret
	} // end of method IconCollection::.ctor

	.method /* 0600003D */ family hidebysig virtual 
		instance void InsertItem (
			int32 index,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon item
		) cil managed 
	{
		// Method begins at RVA 0x2950
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002950 04                 */ IL_0000: ldarg.2
		/* 0x00002951 02                 */ IL_0001: ldarg.0
		/* 0x00002952 7B16000004         */ IL_0002: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection::_parent /* 04000016 */
		/* 0x00002957 6F38000006         */ IL_0007: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.Icon::set_Parent(class AspenTech.AspenPlus.ModelLibrary.Controls.Model) /* 06000038 */
		/* 0x0000295C 02                 */ IL_000c: ldarg.0
		/* 0x0000295D 03                 */ IL_000d: ldarg.1
		/* 0x0000295E 04                 */ IL_000e: ldarg.2
		/* 0x0000295F 284A00000A         */ IL_000f: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Icon>::InsertItem(int32, !0) /* 0A00004A */
		/* 0x00002964 2A                 */ IL_0014: ret
	} // end of method IconCollection::InsertItem

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection

.class /* 02000009 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Library
	extends AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase
{
	.custom /* 0C000018 */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 0f 42 6c 6f 63 6b 43 61 74 65 67 6f 72 69
		65 73 00 00
	)
	// Fields
	.field /* 04000017 */ private object _header
	.field /* 04000018 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.Category _streamCategory
	.field /* 04000019 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.Category _currentBlockCategory
	.field /* 0400001A */ private class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection '<BlockCategories>k__BackingField'
	.custom /* 0C00002D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 0400001B */ private object '<Data>k__BackingField'
	.custom /* 0C00002E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600003E */ public hidebysig specialname 
		instance object get_Header () cil managed 
	{
		// Method begins at RVA 0x2966
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002966 02                 */ IL_0000: ldarg.0
		/* 0x00002967 7B17000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Library::_header /* 04000017 */
		/* 0x0000296C 2A                 */ IL_0006: ret
	} // end of method Library::get_Header

	.method /* 0600003F */ public hidebysig specialname 
		instance void set_Header (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x296e
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x0000296E 02                 */ IL_0000: ldarg.0
		/* 0x0000296F 7B17000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Library::_header /* 04000017 */
		/* 0x00002974 03                 */ IL_0006: ldarg.1
		/* 0x00002975 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002977 02                 */ IL_0009: ldarg.0
		/* 0x00002978 03                 */ IL_000a: ldarg.1
		/* 0x00002979 7D17000004         */ IL_000b: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Library::_header /* 04000017 */
		/* 0x0000297E 02                 */ IL_0010: ldarg.0
		/* 0x0000297F 723F020070         */ IL_0011: ldstr "Header" /* 7000023F */
		/* 0x00002984 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002989 2A                 */ IL_001b: ret
	} // end of method Library::set_Header

	.method /* 06000040 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category get_StreamCategory () cil managed 
	{
		// Method begins at RVA 0x298b
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000298B 02                 */ IL_0000: ldarg.0
		/* 0x0000298C 7B18000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::_streamCategory /* 04000018 */
		/* 0x00002991 2A                 */ IL_0006: ret
	} // end of method Library::get_StreamCategory

	.method /* 06000041 */ public hidebysig specialname 
		instance void set_StreamCategory (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2993
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002993 02                 */ IL_0000: ldarg.0
		/* 0x00002994 7B18000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::_streamCategory /* 04000018 */
		/* 0x00002999 03                 */ IL_0006: ldarg.1
		/* 0x0000299A 2E12               */ IL_0007: beq.s IL_001b
		/* 0x0000299C 02                 */ IL_0009: ldarg.0
		/* 0x0000299D 03                 */ IL_000a: ldarg.1
		/* 0x0000299E 7D18000004         */ IL_000b: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::_streamCategory /* 04000018 */
		/* 0x000029A3 02                 */ IL_0010: ldarg.0
		/* 0x000029A4 7207030070         */ IL_0011: ldstr "StreamCategory" /* 70000307 */
		/* 0x000029A9 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x000029AE 2A                 */ IL_001b: ret
	} // end of method Library::set_StreamCategory

	.method /* 06000042 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection get_BlockCategories () cil managed 
	{
		.custom /* 0C000040 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x29b0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000029B0 02                 */ IL_0000: ldarg.0
		/* 0x000029B1 7B1A000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection AspenTech.AspenPlus.ModelLibrary.Controls.Library::'<BlockCategories>k__BackingField' /* 0400001A */
		/* 0x000029B6 2A                 */ IL_0006: ret
	} // end of method Library::get_BlockCategories

	.method /* 06000043 */ private hidebysig specialname 
		instance void set_BlockCategories (
			class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection 'value'
		) cil managed 
	{
		.custom /* 0C000041 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x29b8
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000029B8 02                 */ IL_0000: ldarg.0
		/* 0x000029B9 03                 */ IL_0001: ldarg.1
		/* 0x000029BA 7D1A000004         */ IL_0002: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection AspenTech.AspenPlus.ModelLibrary.Controls.Library::'<BlockCategories>k__BackingField' /* 0400001A */
		/* 0x000029BF 2A                 */ IL_0007: ret
	} // end of method Library::set_BlockCategories

	.method /* 06000044 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category get_CurrentBlockCategory () cil managed 
	{
		// Method begins at RVA 0x29c1
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000029C1 02                 */ IL_0000: ldarg.0
		/* 0x000029C2 7B19000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::_currentBlockCategory /* 04000019 */
		/* 0x000029C7 2A                 */ IL_0006: ret
	} // end of method Library::get_CurrentBlockCategory

	.method /* 06000045 */ public hidebysig specialname 
		instance void set_CurrentBlockCategory (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category 'value'
		) cil managed 
	{
		// Method begins at RVA 0x29c9
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x000029C9 02                 */ IL_0000: ldarg.0
		/* 0x000029CA 7B19000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::_currentBlockCategory /* 04000019 */
		/* 0x000029CF 03                 */ IL_0006: ldarg.1
		/* 0x000029D0 2E12               */ IL_0007: beq.s IL_001b
		/* 0x000029D2 02                 */ IL_0009: ldarg.0
		/* 0x000029D3 03                 */ IL_000a: ldarg.1
		/* 0x000029D4 7D19000004         */ IL_000b: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::_currentBlockCategory /* 04000019 */
		/* 0x000029D9 02                 */ IL_0010: ldarg.0
		/* 0x000029DA 7225030070         */ IL_0011: ldstr "CurrentBlockCategory" /* 70000325 */
		/* 0x000029DF 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x000029E4 2A                 */ IL_001b: ret
	} // end of method Library::set_CurrentBlockCategory

	.method /* 06000046 */ public hidebysig specialname 
		instance object get_Data () cil managed 
	{
		.custom /* 0C000042 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x29e6
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000029E6 02                 */ IL_0000: ldarg.0
		/* 0x000029E7 7B1B000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Library::'<Data>k__BackingField' /* 0400001B */
		/* 0x000029EC 2A                 */ IL_0006: ret
	} // end of method Library::get_Data

	.method /* 06000047 */ public hidebysig specialname 
		instance void set_Data (
			object 'value'
		) cil managed 
	{
		.custom /* 0C000043 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x29ee
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x000029EE 02                 */ IL_0000: ldarg.0
		/* 0x000029EF 03                 */ IL_0001: ldarg.1
		/* 0x000029F0 7D1B000004         */ IL_0002: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Library::'<Data>k__BackingField' /* 0400001B */
		/* 0x000029F5 2A                 */ IL_0007: ret
	} // end of method Library::set_Data

	.method /* 06000048 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x29f7
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000029F7 02                 */ IL_0000: ldarg.0
		/* 0x000029F8 2881000006         */ IL_0001: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::.ctor() /* 06000081 */
		/* 0x000029FD 02                 */ IL_0006: ldarg.0
		/* 0x000029FE 7330000006         */ IL_0007: newobj instance void AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection::.ctor() /* 06000030 */
		/* 0x00002A03 2843000006         */ IL_000c: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Library::set_BlockCategories(class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection) /* 06000043 */
		/* 0x00002A08 2A                 */ IL_0011: ret
	} // end of method Library::.ctor

	// Properties
	.property /* 17000013 */ instance object Header()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Library::get_Header()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Library::set_Header(object)
	}
	.property /* 17000014 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category StreamCategory()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::get_StreamCategory()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Library::set_StreamCategory(class AspenTech.AspenPlus.ModelLibrary.Controls.Category)
	}
	.property /* 17000015 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection BlockCategories()
	{
		.custom /* 0C00002B */ instance void [System]System.ComponentModel.DesignerSerializationVisibilityAttribute::.ctor(valuetype [System]System.ComponentModel.DesignerSerializationVisibility) = (
			01 00 02 00 00 00 00 00
		)
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection AspenTech.AspenPlus.ModelLibrary.Controls.Library::get_BlockCategories()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Library::set_BlockCategories(class AspenTech.AspenPlus.ModelLibrary.Controls.CategoryCollection)
	}
	.property /* 17000016 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category CurrentBlockCategory()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Library::get_CurrentBlockCategory()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Library::set_CurrentBlockCategory(class AspenTech.AspenPlus.ModelLibrary.Controls.Category)
	}
	.property /* 17000017 */ instance object Data()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Library::get_Data()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Library::set_Data(object)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Library

.class /* 0200000A */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Model
	extends AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase
{
	.custom /* 0C000019 */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 05 49 63 6f 6e 73 00 00
	)
	// Fields
	.field /* 0400001C */ private object _header
	.field /* 0400001D */ private bool _isChecked
	.field /* 0400001E */ private string _description
	.field /* 0400001F */ private class AspenTech.AspenPlus.ModelLibrary.Controls.Icon _selectedIcon
	.field /* 04000020 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection '<Icons>k__BackingField'
	.custom /* 0C000031 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000021 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.Category '<Parent>k__BackingField'
	.custom /* 0C000033 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000022 */ private object '<Data>k__BackingField'
	.custom /* 0C000034 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 06000049 */ public hidebysig specialname 
		instance object get_Header () cil managed 
	{
		// Method begins at RVA 0x2a0a
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002A0A 02                 */ IL_0000: ldarg.0
		/* 0x00002A0B 7B1C000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Model::_header /* 0400001C */
		/* 0x00002A10 2A                 */ IL_0006: ret
	} // end of method Model::get_Header

	.method /* 0600004A */ public hidebysig specialname 
		instance void set_Header (
			object 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2a12
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002A12 02                 */ IL_0000: ldarg.0
		/* 0x00002A13 7B1C000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Model::_header /* 0400001C */
		/* 0x00002A18 03                 */ IL_0006: ldarg.1
		/* 0x00002A19 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002A1B 02                 */ IL_0009: ldarg.0
		/* 0x00002A1C 03                 */ IL_000a: ldarg.1
		/* 0x00002A1D 7D1C000004         */ IL_000b: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Model::_header /* 0400001C */
		/* 0x00002A22 02                 */ IL_0010: ldarg.0
		/* 0x00002A23 723F020070         */ IL_0011: ldstr "Header" /* 7000023F */
		/* 0x00002A28 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002A2D 2A                 */ IL_001b: ret
	} // end of method Model::set_Header

	.method /* 0600004B */ public hidebysig specialname 
		instance bool get_IsChecked () cil managed 
	{
		// Method begins at RVA 0x2a2f
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002A2F 02                 */ IL_0000: ldarg.0
		/* 0x00002A30 7B1D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.ModelLibrary.Controls.Model::_isChecked /* 0400001D */
		/* 0x00002A35 2A                 */ IL_0006: ret
	} // end of method Model::get_IsChecked

	.method /* 0600004C */ public hidebysig specialname 
		instance void set_IsChecked (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2a37
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002A37 02                 */ IL_0000: ldarg.0
		/* 0x00002A38 7B1D000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.ModelLibrary.Controls.Model::_isChecked /* 0400001D */
		/* 0x00002A3D 03                 */ IL_0006: ldarg.1
		/* 0x00002A3E 2E12               */ IL_0007: beq.s IL_001b
		/* 0x00002A40 02                 */ IL_0009: ldarg.0
		/* 0x00002A41 03                 */ IL_000a: ldarg.1
		/* 0x00002A42 7D1D000004         */ IL_000b: stfld bool AspenTech.AspenPlus.ModelLibrary.Controls.Model::_isChecked /* 0400001D */
		/* 0x00002A47 02                 */ IL_0010: ldarg.0
		/* 0x00002A48 724F030070         */ IL_0011: ldstr "IsChecked" /* 7000034F */
		/* 0x00002A4D 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002A52 2A                 */ IL_001b: ret
	} // end of method Model::set_IsChecked

	.method /* 0600004D */ public hidebysig specialname 
		instance string get_Description () cil managed 
	{
		// Method begins at RVA 0x2a54
		// Header size: 1
		// Code size: 22 (0x16)
		.maxstack 8

		/* 0x00002A54 02                 */ IL_0000: ldarg.0
		/* 0x00002A55 7B1E000004         */ IL_0001: ldfld string AspenTech.AspenPlus.ModelLibrary.Controls.Model::_description /* 0400001E */
		/* 0x00002A5A 284300000A         */ IL_0006: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000043 */
		/* 0x00002A5F 2C02               */ IL_000b: brfalse.s IL_000f
		/* 0x00002A61 14                 */ IL_000d: ldnull
		/* 0x00002A62 2A                 */ IL_000e: ret
		/* 0x00002A63 02                 */ IL_000f: ldarg.0
		/* 0x00002A64 7B1E000004         */ IL_0010: ldfld string AspenTech.AspenPlus.ModelLibrary.Controls.Model::_description /* 0400001E */
		/* 0x00002A69 2A                 */ IL_0015: ret
	} // end of method Model::get_Description

	.method /* 0600004E */ public hidebysig specialname 
		instance void set_Description (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2a6b
		// Header size: 1
		// Code size: 44 (0x2c)
		.maxstack 8

		/* 0x00002A6B 02                 */ IL_0000: ldarg.0
		/* 0x00002A6C 7B1E000004         */ IL_0001: ldfld string AspenTech.AspenPlus.ModelLibrary.Controls.Model::_description /* 0400001E */
		/* 0x00002A71 03                 */ IL_0006: ldarg.1
		/* 0x00002A72 284B00000A         */ IL_0007: call bool [mscorlib]System.String::op_Inequality(string, string) /* 0A00004B */
		/* 0x00002A77 2C1D               */ IL_000c: brfalse.s IL_002b
		/* 0x00002A79 02                 */ IL_000e: ldarg.0
		/* 0x00002A7A 03                 */ IL_000f: ldarg.1
		/* 0x00002A7B 7D1E000004         */ IL_0010: stfld string AspenTech.AspenPlus.ModelLibrary.Controls.Model::_description /* 0400001E */
		/* 0x00002A80 02                 */ IL_0015: ldarg.0
		/* 0x00002A81 7263030070         */ IL_0016: ldstr "Description" /* 70000363 */
		/* 0x00002A86 6F80000006         */ IL_001b: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002A8B 02                 */ IL_0020: ldarg.0
		/* 0x00002A8C 727B030070         */ IL_0021: ldstr "Tooltip" /* 7000037B */
		/* 0x00002A91 6F80000006         */ IL_0026: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002A96 2A                 */ IL_002b: ret
	} // end of method Model::set_Description

	.method /* 0600004F */ public hidebysig specialname 
		instance string get_Tooltip () cil managed 
	{
		// Method begins at RVA 0x2a98
		// Header size: 12
		// Code size: 158 (0x9e)
		.maxstack 4
		.locals /* 11000005 */ init (
			[0] string,
			[1] string
		)

		/* 0x00002A98 02                 */ IL_0000: ldarg.0
		/* 0x00002A99 2854000006         */ IL_0001: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Parent() /* 06000054 */
		/* 0x00002A9E 2C14               */ IL_0006: brfalse.s IL_001c
		/* 0x00002AA0 02                 */ IL_0008: ldarg.0
		/* 0x00002AA1 2854000006         */ IL_0009: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Parent() /* 06000054 */
		/* 0x00002AA6 6F27000006         */ IL_000e: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_IsStreamCategory() /* 06000027 */
		/* 0x00002AAB 2C07               */ IL_0013: brfalse.s IL_001c
		/* 0x00002AAD 02                 */ IL_0015: ldarg.0
		/* 0x00002AAE 284D000006         */ IL_0016: call instance string AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Description() /* 0600004D */
		/* 0x00002AB3 2A                 */ IL_001b: ret
		/* 0x00002AB4 7E4C00000A         */ IL_001c: ldsfld string [mscorlib]System.String::Empty /* 0A00004C */
		/* 0x00002AB9 0A                 */ IL_0021: stloc.0
		/* 0x00002ABA 02                 */ IL_0022: ldarg.0
		/* 0x00002ABB 284D000006         */ IL_0023: call instance string AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Description() /* 0600004D */
		/* 0x00002AC0 284300000A         */ IL_0028: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000043 */
		/* 0x00002AC5 2D0F               */ IL_002d: brtrue.s IL_003e
		/* 0x00002AC7 06                 */ IL_002f: ldloc.0
		/* 0x00002AC8 02                 */ IL_0030: ldarg.0
		/* 0x00002AC9 284D000006         */ IL_0031: call instance string AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Description() /* 0600004D */
		/* 0x00002ACE 284D00000A         */ IL_0036: call string [mscorlib]System.String::Concat(string, string) /* 0A00004D */
		/* 0x00002AD3 0A                 */ IL_003b: stloc.0
		/* 0x00002AD4 2B2B               */ IL_003c: br.s IL_0069
		/* 0x00002AD6 02                 */ IL_003e: ldarg.0
		/* 0x00002AD7 2849000006         */ IL_003f: call instance object AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Header() /* 06000049 */
		/* 0x00002ADC 755A000001         */ IL_0044: isinst [mscorlib]System.String /* 0100005A */
		/* 0x00002AE1 284E00000A         */ IL_0049: call bool [mscorlib]System.String::IsNullOrWhiteSpace(string) /* 0A00004E */
		/* 0x00002AE6 2D19               */ IL_004e: brtrue.s IL_0069
		/* 0x00002AE8 06                 */ IL_0050: ldloc.0
		/* 0x00002AE9 02                 */ IL_0051: ldarg.0
		/* 0x00002AEA 2849000006         */ IL_0052: call instance object AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Header() /* 06000049 */
		/* 0x00002AEF 25                 */ IL_0057: dup
		/* 0x00002AF0 2D04               */ IL_0058: brtrue.s IL_005e
		/* 0x00002AF2 26                 */ IL_005a: pop
		/* 0x00002AF3 14                 */ IL_005b: ldnull
		/* 0x00002AF4 2B05               */ IL_005c: br.s IL_0063
		/* 0x00002AF6 6F4F00000A         */ IL_005e: callvirt instance string [mscorlib]System.Object::ToString() /* 0A00004F */
		/* 0x00002AFB 284D00000A         */ IL_0063: call string [mscorlib]System.String::Concat(string, string) /* 0A00004D */
		/* 0x00002B00 0A                 */ IL_0068: stloc.0
		/* 0x00002B01 02                 */ IL_0069: ldarg.0
		/* 0x00002B02 2850000006         */ IL_006a: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_SelectedIcon() /* 06000050 */
		/* 0x00002B07 2C2B               */ IL_006f: brfalse.s IL_009c
		/* 0x00002B09 02                 */ IL_0071: ldarg.0
		/* 0x00002B0A 2850000006         */ IL_0072: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_SelectedIcon() /* 06000050 */
		/* 0x00002B0F 6F33000006         */ IL_0077: callvirt instance object AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_Header() /* 06000033 */
		/* 0x00002B14 755A000001         */ IL_007c: isinst [mscorlib]System.String /* 0100005A */
		/* 0x00002B19 0B                 */ IL_0081: stloc.1
		/* 0x00002B1A 07                 */ IL_0082: ldloc.1
		/* 0x00002B1B 284300000A         */ IL_0083: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000043 */
		/* 0x00002B20 2D12               */ IL_0088: brtrue.s IL_009c
		/* 0x00002B22 06                 */ IL_008a: ldloc.0
		/* 0x00002B23 728B030070         */ IL_008b: ldstr " (" /* 7000038B */
		/* 0x00002B28 07                 */ IL_0090: ldloc.1
		/* 0x00002B29 7291030070         */ IL_0091: ldstr ")" /* 70000391 */
		/* 0x00002B2E 285000000A         */ IL_0096: call string [mscorlib]System.String::Concat(string, string, string, string) /* 0A000050 */
		/* 0x00002B33 0A                 */ IL_009b: stloc.0
		/* 0x00002B34 06                 */ IL_009c: ldloc.0
		/* 0x00002B35 2A                 */ IL_009d: ret
	} // end of method Model::get_Tooltip

	.method /* 06000050 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon get_SelectedIcon () cil managed 
	{
		// Method begins at RVA 0x2b42
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002B42 02                 */ IL_0000: ldarg.0
		/* 0x00002B43 7B1F000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.Model::_selectedIcon /* 0400001F */
		/* 0x00002B48 2A                 */ IL_0006: ret
	} // end of method Model::get_SelectedIcon

	.method /* 06000051 */ public hidebysig specialname 
		instance void set_SelectedIcon (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2b4a
		// Header size: 1
		// Code size: 39 (0x27)
		.maxstack 8

		/* 0x00002B4A 02                 */ IL_0000: ldarg.0
		/* 0x00002B4B 7B1F000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.Model::_selectedIcon /* 0400001F */
		/* 0x00002B50 03                 */ IL_0006: ldarg.1
		/* 0x00002B51 2E1D               */ IL_0007: beq.s IL_0026
		/* 0x00002B53 02                 */ IL_0009: ldarg.0
		/* 0x00002B54 03                 */ IL_000a: ldarg.1
		/* 0x00002B55 7D1F000004         */ IL_000b: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.Model::_selectedIcon /* 0400001F */
		/* 0x00002B5A 02                 */ IL_0010: ldarg.0
		/* 0x00002B5B 7241000070         */ IL_0011: ldstr "SelectedIcon" /* 70000041 */
		/* 0x00002B60 6F80000006         */ IL_0016: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002B65 02                 */ IL_001b: ldarg.0
		/* 0x00002B66 727B030070         */ IL_001c: ldstr "Tooltip" /* 7000037B */
		/* 0x00002B6B 6F80000006         */ IL_0021: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::OnPropertyChanged(string) /* 06000080 */
		/* 0x00002B70 2A                 */ IL_0026: ret
	} // end of method Model::set_SelectedIcon

	.method /* 06000052 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection get_Icons () cil managed 
	{
		.custom /* 0C000044 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b72
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002B72 02                 */ IL_0000: ldarg.0
		/* 0x00002B73 7B20000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection AspenTech.AspenPlus.ModelLibrary.Controls.Model::'<Icons>k__BackingField' /* 04000020 */
		/* 0x00002B78 2A                 */ IL_0006: ret
	} // end of method Model::get_Icons

	.method /* 06000053 */ private hidebysig specialname 
		instance void set_Icons (
			class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection 'value'
		) cil managed 
	{
		.custom /* 0C000045 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b7a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002B7A 02                 */ IL_0000: ldarg.0
		/* 0x00002B7B 03                 */ IL_0001: ldarg.1
		/* 0x00002B7C 7D20000004         */ IL_0002: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection AspenTech.AspenPlus.ModelLibrary.Controls.Model::'<Icons>k__BackingField' /* 04000020 */
		/* 0x00002B81 2A                 */ IL_0007: ret
	} // end of method Model::set_Icons

	.method /* 06000054 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category get_Parent () cil managed 
	{
		.custom /* 0C000046 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b83
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002B83 02                 */ IL_0000: ldarg.0
		/* 0x00002B84 7B21000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Model::'<Parent>k__BackingField' /* 04000021 */
		/* 0x00002B89 2A                 */ IL_0006: ret
	} // end of method Model::get_Parent

	.method /* 06000055 */ assembly hidebysig specialname 
		instance void set_Parent (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category 'value'
		) cil managed 
	{
		.custom /* 0C000047 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b8b
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002B8B 02                 */ IL_0000: ldarg.0
		/* 0x00002B8C 03                 */ IL_0001: ldarg.1
		/* 0x00002B8D 7D21000004         */ IL_0002: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Model::'<Parent>k__BackingField' /* 04000021 */
		/* 0x00002B92 2A                 */ IL_0007: ret
	} // end of method Model::set_Parent

	.method /* 06000056 */ public hidebysig specialname 
		instance object get_Data () cil managed 
	{
		.custom /* 0C000048 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b94
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00002B94 02                 */ IL_0000: ldarg.0
		/* 0x00002B95 7B22000004         */ IL_0001: ldfld object AspenTech.AspenPlus.ModelLibrary.Controls.Model::'<Data>k__BackingField' /* 04000022 */
		/* 0x00002B9A 2A                 */ IL_0006: ret
	} // end of method Model::get_Data

	.method /* 06000057 */ public hidebysig specialname 
		instance void set_Data (
			object 'value'
		) cil managed 
	{
		.custom /* 0C000049 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x2b9c
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00002B9C 02                 */ IL_0000: ldarg.0
		/* 0x00002B9D 03                 */ IL_0001: ldarg.1
		/* 0x00002B9E 7D22000004         */ IL_0002: stfld object AspenTech.AspenPlus.ModelLibrary.Controls.Model::'<Data>k__BackingField' /* 04000022 */
		/* 0x00002BA3 2A                 */ IL_0007: ret
	} // end of method Model::set_Data

	.method /* 06000058 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x2ba5
		// Header size: 1
		// Code size: 19 (0x13)
		.maxstack 8

		/* 0x00002BA5 02                 */ IL_0000: ldarg.0
		/* 0x00002BA6 2881000006         */ IL_0001: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::.ctor() /* 06000081 */
		/* 0x00002BAB 02                 */ IL_0006: ldarg.0
		/* 0x00002BAC 02                 */ IL_0007: ldarg.0
		/* 0x00002BAD 733C000006         */ IL_0008: newobj instance void AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection::.ctor(class AspenTech.AspenPlus.ModelLibrary.Controls.Model) /* 0600003C */
		/* 0x00002BB2 2853000006         */ IL_000d: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Icons(class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection) /* 06000053 */
		/* 0x00002BB7 2A                 */ IL_0012: ret
	} // end of method Model::.ctor

	// Properties
	.property /* 17000018 */ instance object Header()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Header()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Header(object)
	}
	.property /* 17000019 */ instance bool IsChecked()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_IsChecked()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_IsChecked(bool)
	}
	.property /* 1700001A */ instance string Description()
	{
		.get instance string AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Description()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Description(string)
	}
	.property /* 1700001B */ instance string Tooltip()
	{
		.get instance string AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Tooltip()
	}
	.property /* 1700001C */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon SelectedIcon()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_SelectedIcon()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_SelectedIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon)
	}
	.property /* 1700001D */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection Icons()
	{
		.custom /* 0C00002F */ instance void [System]System.ComponentModel.DesignerSerializationVisibilityAttribute::.ctor(valuetype [System]System.ComponentModel.DesignerSerializationVisibility) = (
			01 00 02 00 00 00 00 00
		)
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Icons()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Icons(class AspenTech.AspenPlus.ModelLibrary.Controls.IconCollection)
	}
	.property /* 1700001E */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category Parent()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Parent()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Parent(class AspenTech.AspenPlus.ModelLibrary.Controls.Category)
	}
	.property /* 1700001F */ instance object Data()
	{
		.get instance object AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Data()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Data(object)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Model

.class /* 0200000B */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection
	extends class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>
{
	// Fields
	.field /* 04000023 */ private initonly class AspenTech.AspenPlus.ModelLibrary.Controls.Category _parent

	// Methods
	.method /* 06000059 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category parent
		) cil managed 
	{
		// Method begins at RVA 0x2bb9
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x00002BB9 02                 */ IL_0000: ldarg.0
		/* 0x00002BBA 285100000A         */ IL_0001: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>::.ctor() /* 0A000051 */
		/* 0x00002BBF 03                 */ IL_0006: ldarg.1
		/* 0x00002BC0 2D0B               */ IL_0007: brtrue.s IL_0014
		/* 0x00002BC2 72F9020070         */ IL_0009: ldstr "parent" /* 700002F9 */
		/* 0x00002BC7 734500000A         */ IL_000e: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000045 */
		/* 0x00002BCC 7A                 */ IL_0013: throw
		/* 0x00002BCD 02                 */ IL_0014: ldarg.0
		/* 0x00002BCE 03                 */ IL_0015: ldarg.1
		/* 0x00002BCF 7D23000004         */ IL_0016: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection::_parent /* 04000023 */
		/* 0x00002BD4 2A                 */ IL_001b: ret
	} // end of method ModelCollection::.ctor

	.method /* 0600005A */ family hidebysig virtual 
		instance void InsertItem (
			int32 index,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model item
		) cil managed 
	{
		// Method begins at RVA 0x2bd6
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00002BD6 04                 */ IL_0000: ldarg.2
		/* 0x00002BD7 02                 */ IL_0001: ldarg.0
		/* 0x00002BD8 7B23000004         */ IL_0002: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection::_parent /* 04000023 */
		/* 0x00002BDD 6F55000006         */ IL_0007: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.Model::set_Parent(class AspenTech.AspenPlus.ModelLibrary.Controls.Category) /* 06000055 */
		/* 0x00002BE2 02                 */ IL_000c: ldarg.0
		/* 0x00002BE3 03                 */ IL_000d: ldarg.1
		/* 0x00002BE4 04                 */ IL_000e: ldarg.2
		/* 0x00002BE5 285200000A         */ IL_000f: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Model>::InsertItem(int32, !0) /* 0A000052 */
		/* 0x00002BEA 2A                 */ IL_0014: ret
	} // end of method ModelCollection::InsertItem

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.ModelCollection

.class /* 0200000C */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl
	extends [PresentationFramework]System.Windows.Controls.Control
{
	.custom /* 0C00001A */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 0c 4d 6f 64 65 6c 4c 69 62 72 61 72 79 00 00
	)
	.custom /* 0C00001B */ instance void [PresentationFramework]System.Windows.TemplatePartAttribute::.ctor() = (
		01 00 02 00 54 0e 04 4e 61 6d 65 13 50 41 52 54
		5f 53 65 6c 65 63 74 6f 72 42 75 74 74 6f 6e 54
		50 04 54 79 70 65 36 41 73 70 65 6e 54 65 63 68
		2e 41 73 70 65 6e 50 6c 75 73 2e 4d 6f 64 65 6c
		4c 69 62 72 61 72 79 2e 43 6f 6e 74 72 6f 6c 73
		2e 4f 70 74 69 6f 6e 42 75 74 74 6f 6e
	)
	.custom /* 0C00001C */ instance void [PresentationFramework]System.Windows.TemplatePartAttribute::.ctor() = (
		01 00 02 00 54 0e 04 4e 61 6d 65 16 50 41 52 54
		5f 42 6c 6f 63 6b 54 61 62 6c 65 43 6f 6e 74 72
		6f 6c 54 50 04 54 79 70 65 3b 41 73 70 65 6e 54
		65 63 68 2e 41 73 70 65 6e 50 6c 75 73 2e 4d 6f
		64 65 6c 4c 69 62 72 61 72 79 2e 43 6f 6e 74 72
		6f 6c 73 2e 42 6c 6f 63 6b 54 61 62 6c 65 43 6f
		6e 74 72 6f 6c
	)
	.custom /* 0C00001D */ instance void [PresentationFramework]System.Windows.TemplatePartAttribute::.ctor() = (
		01 00 02 00 54 0e 04 4e 61 6d 65 1a 50 41 52 54
		5f 53 74 72 65 61 6d 73 44 72 6f 70 64 6f 77 6e
		42 75 74 74 6f 6e 54 50 04 54 79 70 65 38 41 73
		70 65 6e 54 65 63 68 2e 41 73 70 65 6e 50 6c 75
		73 2e 4d 6f 64 65 6c 4c 69 62 72 61 72 79 2e 43
		6f 6e 74 72 6f 6c 73 2e 44 72 6f 70 64 6f 77 6e
		42 75 74 74 6f 6e
	)
	// Fields
	.field /* 04000024 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl _theBlockTableControl
	.field /* 04000025 */ private static literal string PART_SelectorButton = "PART_SelectorButton"
	.field /* 04000026 */ private static literal string PART_BlockTableControl = "PART_BlockTableControl"
	.field /* 04000027 */ private static literal string PART_StreamsDropdownButton = "PART_StreamsDropdownButton"
	.field /* 04000028 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty DockProperty
	.field /* 04000029 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ModelLibraryProperty
	.field /* 0400002A */ public static initonly class [WindowsBase]System.Windows.DependencyProperty IsOptionIconCheckedProperty
	.field /* 0400002B */ public static initonly class [WindowsBase]System.Windows.DependencyProperty SelectedStreamModelProperty
	.field /* 0400002C */ public static initonly class [WindowsBase]System.Windows.DependencyProperty SelectedBlockIconProperty
	.field /* 0400002D */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ButtonSizeProperty
	.field /* 0400002E */ public static initonly class [WindowsBase]System.Windows.DependencyProperty DefaultButtonBackgroundProperty
	.field /* 0400002F */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CheckedButtonBackgroundProperty
	.field /* 04000030 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CurrentBlockCategoryProperty
	.field /* 04000031 */ public static initonly class [PresentationCore]System.Windows.RoutedEvent SelectionChangedEvent

	// Methods
	.method /* 0600005B */ public hidebysig specialname 
		instance valuetype [PresentationFramework]System.Windows.Controls.Dock get_Dock () cil managed 
	{
		// Method begins at RVA 0x2bec
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002BEC 02                 */ IL_0000: ldarg.0
		/* 0x00002BED 7E28000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DockProperty /* 04000028 */
		/* 0x00002BF2 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002BF7 A524000001         */ IL_000b: unbox.any [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x00002BFC 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_Dock

	.method /* 0600005C */ public hidebysig specialname 
		instance void set_Dock (
			valuetype [PresentationFramework]System.Windows.Controls.Dock 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2bfe
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00002BFE 02                 */ IL_0000: ldarg.0
		/* 0x00002BFF 7E28000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DockProperty /* 04000028 */
		/* 0x00002C04 03                 */ IL_0006: ldarg.1
		/* 0x00002C05 8C24000001         */ IL_0007: box [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x00002C0A 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002C0F 2A                 */ IL_0011: ret
	} // end of method ModelLibraryControl::set_Dock

	.method /* 0600005D */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Library get_ModelLibrary () cil managed 
	{
		// Method begins at RVA 0x2c11
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002C11 02                 */ IL_0000: ldarg.0
		/* 0x00002C12 7E29000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ModelLibraryProperty /* 04000029 */
		/* 0x00002C17 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002C1C 7409000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Library /* 02000009 */
		/* 0x00002C21 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_ModelLibrary

	.method /* 0600005E */ public hidebysig specialname 
		instance void set_ModelLibrary (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Library 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2c23
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002C23 02                 */ IL_0000: ldarg.0
		/* 0x00002C24 7E29000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ModelLibraryProperty /* 04000029 */
		/* 0x00002C29 03                 */ IL_0006: ldarg.1
		/* 0x00002C2A 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002C2F 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::set_ModelLibrary

	.method /* 0600005F */ public hidebysig specialname 
		instance bool get_IsOptionIconChecked () cil managed 
	{
		// Method begins at RVA 0x2c31
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002C31 02                 */ IL_0000: ldarg.0
		/* 0x00002C32 7E2A000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::IsOptionIconCheckedProperty /* 0400002A */
		/* 0x00002C37 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002C3C A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00002C41 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_IsOptionIconChecked

	.method /* 06000060 */ public hidebysig specialname 
		instance void set_IsOptionIconChecked (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2c43
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00002C43 02                 */ IL_0000: ldarg.0
		/* 0x00002C44 7E2A000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::IsOptionIconCheckedProperty /* 0400002A */
		/* 0x00002C49 03                 */ IL_0006: ldarg.1
		/* 0x00002C4A 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00002C4F 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002C54 2A                 */ IL_0011: ret
	} // end of method ModelLibraryControl::set_IsOptionIconChecked

	.method /* 06000061 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model get_SelectedStreamModel () cil managed 
	{
		// Method begins at RVA 0x2c56
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002C56 02                 */ IL_0000: ldarg.0
		/* 0x00002C57 7E2B000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectedStreamModelProperty /* 0400002B */
		/* 0x00002C5C 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002C61 740A000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x00002C66 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_SelectedStreamModel

	.method /* 06000062 */ public hidebysig specialname 
		instance void set_SelectedStreamModel (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2c68
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002C68 02                 */ IL_0000: ldarg.0
		/* 0x00002C69 7E2B000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectedStreamModelProperty /* 0400002B */
		/* 0x00002C6E 03                 */ IL_0006: ldarg.1
		/* 0x00002C6F 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002C74 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::set_SelectedStreamModel

	.method /* 06000063 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon get_SelectedBlockIcon () cil managed 
	{
		// Method begins at RVA 0x2c76
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002C76 02                 */ IL_0000: ldarg.0
		/* 0x00002C77 7E2C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectedBlockIconProperty /* 0400002C */
		/* 0x00002C7C 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002C81 7407000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x00002C86 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_SelectedBlockIcon

	.method /* 06000064 */ public hidebysig specialname 
		instance void set_SelectedBlockIcon (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2c88
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002C88 02                 */ IL_0000: ldarg.0
		/* 0x00002C89 7E2C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectedBlockIconProperty /* 0400002C */
		/* 0x00002C8E 03                 */ IL_0006: ldarg.1
		/* 0x00002C8F 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002C94 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::set_SelectedBlockIcon

	.method /* 06000065 */ public hidebysig specialname 
		instance valuetype [WindowsBase]System.Windows.Size get_ButtonSize () cil managed 
	{
		// Method begins at RVA 0x2c96
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002C96 02                 */ IL_0000: ldarg.0
		/* 0x00002C97 7E2D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ButtonSizeProperty /* 0400002D */
		/* 0x00002C9C 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002CA1 A525000001         */ IL_000b: unbox.any [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x00002CA6 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_ButtonSize

	.method /* 06000066 */ public hidebysig specialname 
		instance void set_ButtonSize (
			valuetype [WindowsBase]System.Windows.Size 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2ca8
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00002CA8 02                 */ IL_0000: ldarg.0
		/* 0x00002CA9 7E2D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ButtonSizeProperty /* 0400002D */
		/* 0x00002CAE 03                 */ IL_0006: ldarg.1
		/* 0x00002CAF 8C25000001         */ IL_0007: box [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x00002CB4 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002CB9 2A                 */ IL_0011: ret
	} // end of method ModelLibraryControl::set_ButtonSize

	.method /* 06000067 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_DefaultButtonBackground () cil managed 
	{
		// Method begins at RVA 0x2cbb
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002CBB 02                 */ IL_0000: ldarg.0
		/* 0x00002CBC 7E2E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DefaultButtonBackgroundProperty /* 0400002E */
		/* 0x00002CC1 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002CC6 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x00002CCB 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_DefaultButtonBackground

	.method /* 06000068 */ public hidebysig specialname 
		instance void set_DefaultButtonBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2ccd
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002CCD 02                 */ IL_0000: ldarg.0
		/* 0x00002CCE 7E2E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DefaultButtonBackgroundProperty /* 0400002E */
		/* 0x00002CD3 03                 */ IL_0006: ldarg.1
		/* 0x00002CD4 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002CD9 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::set_DefaultButtonBackground

	.method /* 06000069 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_CheckedButtonBackground () cil managed 
	{
		// Method begins at RVA 0x2cdb
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002CDB 02                 */ IL_0000: ldarg.0
		/* 0x00002CDC 7E2F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::CheckedButtonBackgroundProperty /* 0400002F */
		/* 0x00002CE1 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002CE6 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x00002CEB 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_CheckedButtonBackground

	.method /* 0600006A */ public hidebysig specialname 
		instance void set_CheckedButtonBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2ced
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002CED 02                 */ IL_0000: ldarg.0
		/* 0x00002CEE 7E2F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::CheckedButtonBackgroundProperty /* 0400002F */
		/* 0x00002CF3 03                 */ IL_0006: ldarg.1
		/* 0x00002CF4 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002CF9 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::set_CheckedButtonBackground

	.method /* 0600006B */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category get_CurrentBlockCategory () cil managed 
	{
		// Method begins at RVA 0x2cfb
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00002CFB 02                 */ IL_0000: ldarg.0
		/* 0x00002CFC 7E30000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::CurrentBlockCategoryProperty /* 04000030 */
		/* 0x00002D01 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00002D06 7404000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Category /* 02000004 */
		/* 0x00002D0B 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::get_CurrentBlockCategory

	.method /* 0600006C */ public hidebysig specialname 
		instance void set_CurrentBlockCategory (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Category 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2d0d
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002D0D 02                 */ IL_0000: ldarg.0
		/* 0x00002D0E 7E30000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::CurrentBlockCategoryProperty /* 04000030 */
		/* 0x00002D13 03                 */ IL_0006: ldarg.1
		/* 0x00002D14 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00002D19 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::set_CurrentBlockCategory

	.method /* 0600006D */ public hidebysig specialname 
		instance void add_SelectionChanged (
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<object> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2d1b
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002D1B 02                 */ IL_0000: ldarg.0
		/* 0x00002D1C 7E31000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectionChangedEvent /* 04000031 */
		/* 0x00002D21 03                 */ IL_0006: ldarg.1
		/* 0x00002D22 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x00002D27 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::add_SelectionChanged

	.method /* 0600006E */ public hidebysig specialname 
		instance void remove_SelectionChanged (
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<object> 'value'
		) cil managed 
	{
		// Method begins at RVA 0x2d29
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00002D29 02                 */ IL_0000: ldarg.0
		/* 0x00002D2A 7E31000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectionChangedEvent /* 04000031 */
		/* 0x00002D2F 03                 */ IL_0006: ldarg.1
		/* 0x00002D30 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x00002D35 2A                 */ IL_000c: ret
	} // end of method ModelLibraryControl::remove_SelectionChanged

	.method /* 0600006F */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x2d38
		// Header size: 12
		// Code size: 572 (0x23c)
		.maxstack 6

		/* 0x00002D38 7221000070         */ IL_0000: ldstr "Dock" /* 70000021 */
		/* 0x00002D3D D024000001         */ IL_0005: ldtoken [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x00002D42 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002D47 D00C000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002D4C 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002D51 19                 */ IL_0019: ldc.i4.3
		/* 0x00002D52 8C24000001         */ IL_001a: box [PresentationFramework]System.Windows.Controls.Dock /* 01000024 */
		/* 0x00002D57 732500000A         */ IL_001f: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002D5C 282600000A         */ IL_0024: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002D61 8028000004         */ IL_0029: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DockProperty /* 04000028 */
		/* 0x00002D66 7295030070         */ IL_002e: ldstr "ModelLibrary" /* 70000395 */
		/* 0x00002D6B D009000002         */ IL_0033: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.Library /* 02000009 */
		/* 0x00002D70 282400000A         */ IL_0038: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002D75 D00C000002         */ IL_003d: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002D7A 282400000A         */ IL_0042: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002D7F 282700000A         */ IL_0047: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x00002D84 8029000004         */ IL_004c: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ModelLibraryProperty /* 04000029 */
		/* 0x00002D89 72AF030070         */ IL_0051: ldstr "IsOptionIconChecked" /* 700003AF */
		/* 0x00002D8E D05F000001         */ IL_0056: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x00002D93 282400000A         */ IL_005b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002D98 D00C000002         */ IL_0060: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002D9D 282400000A         */ IL_0065: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002DA2 16                 */ IL_006a: ldc.i4.0
		/* 0x00002DA3 8C5F000001         */ IL_006b: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00002DA8 14                 */ IL_0070: ldnull
		/* 0x00002DA9 FE067A000006       */ IL_0071: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnIsOptionIconCheckedPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 0600007A */
		/* 0x00002DAF 732800000A         */ IL_0077: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00002DB4 735300000A         */ IL_007c: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000053 */
		/* 0x00002DB9 282600000A         */ IL_0081: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002DBE 802A000004         */ IL_0086: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::IsOptionIconCheckedProperty /* 0400002A */
		/* 0x00002DC3 72D7030070         */ IL_008b: ldstr "SelectedStreamModel" /* 700003D7 */
		/* 0x00002DC8 D00A000002         */ IL_0090: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x00002DCD 282400000A         */ IL_0095: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002DD2 D00C000002         */ IL_009a: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002DD7 282400000A         */ IL_009f: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002DDC 14                 */ IL_00a4: ldnull
		/* 0x00002DDD FE067B000006       */ IL_00a5: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectedStreamModelPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 0600007B */
		/* 0x00002DE3 732800000A         */ IL_00ab: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00002DE8 732900000A         */ IL_00b0: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000029 */
		/* 0x00002DED 282600000A         */ IL_00b5: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002DF2 802B000004         */ IL_00ba: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectedStreamModelProperty /* 0400002B */
		/* 0x00002DF7 72FF030070         */ IL_00bf: ldstr "SelectedBlockIcon" /* 700003FF */
		/* 0x00002DFC D007000002         */ IL_00c4: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x00002E01 282400000A         */ IL_00c9: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002E06 D00C000002         */ IL_00ce: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002E0B 282400000A         */ IL_00d3: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002E10 14                 */ IL_00d8: ldnull
		/* 0x00002E11 FE067C000006       */ IL_00d9: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectedBlockIconPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 0600007C */
		/* 0x00002E17 732800000A         */ IL_00df: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00002E1C 732900000A         */ IL_00e4: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000029 */
		/* 0x00002E21 282600000A         */ IL_00e9: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002E26 802C000004         */ IL_00ee: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectedBlockIconProperty /* 0400002C */
		/* 0x00002E2B 727B000070         */ IL_00f3: ldstr "ButtonSize" /* 7000007B */
		/* 0x00002E30 D025000001         */ IL_00f8: ldtoken [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x00002E35 282400000A         */ IL_00fd: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002E3A D00C000002         */ IL_0102: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002E3F 282400000A         */ IL_0107: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002E44 230000000000805640 */ IL_010c: ldc.r8 90
		/* 0x00002E4D 230000000000805140 */ IL_0115: ldc.r8 70
		/* 0x00002E56 732A00000A         */ IL_011e: newobj instance void [WindowsBase]System.Windows.Size::.ctor(float64, float64) /* 0A00002A */
		/* 0x00002E5B 8C25000001         */ IL_0123: box [WindowsBase]System.Windows.Size /* 01000025 */
		/* 0x00002E60 732500000A         */ IL_0128: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002E65 282600000A         */ IL_012d: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002E6A 802D000004         */ IL_0132: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ButtonSizeProperty /* 0400002D */
		/* 0x00002E6F 7291000070         */ IL_0137: ldstr "DefaultButtonBackground" /* 70000091 */
		/* 0x00002E74 D026000001         */ IL_013c: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x00002E79 282400000A         */ IL_0141: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002E7E D00C000002         */ IL_0146: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002E83 282400000A         */ IL_014b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002E88 282B00000A         */ IL_0150: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_LightGray() /* 0A00002B */
		/* 0x00002E8D 732500000A         */ IL_0155: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002E92 282600000A         */ IL_015a: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002E97 802E000004         */ IL_015f: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DefaultButtonBackgroundProperty /* 0400002E */
		/* 0x00002E9C 72C1000070         */ IL_0164: ldstr "CheckedButtonBackground" /* 700000C1 */
		/* 0x00002EA1 D026000001         */ IL_0169: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x00002EA6 282400000A         */ IL_016e: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002EAB D00C000002         */ IL_0173: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002EB0 282400000A         */ IL_0178: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002EB5 282C00000A         */ IL_017d: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_White() /* 0A00002C */
		/* 0x00002EBA 732500000A         */ IL_0182: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002EBF 282600000A         */ IL_0187: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00002EC4 802F000004         */ IL_018c: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::CheckedButtonBackgroundProperty /* 0400002F */
		/* 0x00002EC9 7225030070         */ IL_0191: ldstr "CurrentBlockCategory" /* 70000325 */
		/* 0x00002ECE D004000002         */ IL_0196: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.Category /* 02000004 */
		/* 0x00002ED3 282400000A         */ IL_019b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002ED8 D00C000002         */ IL_01a0: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002EDD 282400000A         */ IL_01a5: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002EE2 282700000A         */ IL_01aa: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x00002EE7 8030000004         */ IL_01af: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::CurrentBlockCategoryProperty /* 04000030 */
		/* 0x00002EEC 7223040070         */ IL_01b4: ldstr "SelectionChanged" /* 70000423 */
		/* 0x00002EF1 17                 */ IL_01b9: ldc.i4.1
		/* 0x00002EF2 D00600001B         */ IL_01ba: ldtoken class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<object> /* 1B000006 */
		/* 0x00002EF7 282400000A         */ IL_01bf: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002EFC D00C000002         */ IL_01c4: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002F01 282400000A         */ IL_01c9: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002F06 282D00000A         */ IL_01ce: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x00002F0B 8031000004         */ IL_01d3: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectionChangedEvent /* 04000031 */
		/* 0x00002F10 7E2E00000A         */ IL_01d8: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x00002F15 D00C000002         */ IL_01dd: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002F1A 282400000A         */ IL_01e2: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002F1F D00C000002         */ IL_01e7: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002F24 282400000A         */ IL_01ec: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002F29 732500000A         */ IL_01f1: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00002F2E 6F2F00000A         */ IL_01f6: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x00002F33 D00C000002         */ IL_01fb: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002F38 282400000A         */ IL_0200: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002F3D 7E36000004         */ IL_0205: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickEvent /* 04000036 */
		/* 0x00002F42 14                 */ IL_020a: ldnull
		/* 0x00002F43 FE0678000006       */ IL_020b: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OptionButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 06000078 */
		/* 0x00002F49 733000000A         */ IL_0211: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000030 */
		/* 0x00002F4E 283100000A         */ IL_0216: call void [PresentationCore]System.Windows.EventManager::RegisterClassHandler(class [mscorlib]System.Type, class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000031 */
		/* 0x00002F53 D00C000002         */ IL_021b: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00002F58 282400000A         */ IL_0220: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00002F5D 7E41000004         */ IL_0225: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ClickEvent /* 04000041 */
		/* 0x00002F62 14                 */ IL_022a: ldnull
		/* 0x00002F63 FE0679000006       */ IL_022b: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::DropdownButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 06000079 */
		/* 0x00002F69 733000000A         */ IL_0231: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000030 */
		/* 0x00002F6E 283100000A         */ IL_0236: call void [PresentationCore]System.Windows.EventManager::RegisterClassHandler(class [mscorlib]System.Type, class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000031 */
		/* 0x00002F73 2A                 */ IL_023b: ret
	} // end of method ModelLibraryControl::.cctor

	.method /* 06000070 */ public hidebysig virtual 
		instance void OnApplyTemplate () cil managed 
	{
		// Method begins at RVA 0x2f80
		// Header size: 1
		// Code size: 52 (0x34)
		.maxstack 8

		/* 0x00002F80 02                 */ IL_0000: ldarg.0
		/* 0x00002F81 02                 */ IL_0001: ldarg.0
		/* 0x00002F82 7245040070         */ IL_0002: ldstr "PART_BlockTableControl" /* 70000445 */
		/* 0x00002F87 285400000A         */ IL_0007: call instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::GetTemplateChild(string) /* 0A000054 */
		/* 0x00002F8C 7503000002         */ IL_000c: isinst AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl /* 02000003 */
		/* 0x00002F91 7D24000004         */ IL_0011: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::_theBlockTableControl /* 04000024 */
		/* 0x00002F96 02                 */ IL_0016: ldarg.0
		/* 0x00002F97 285500000A         */ IL_0017: call instance void [PresentationFramework]System.Windows.FrameworkElement::OnApplyTemplate() /* 0A000055 */
		/* 0x00002F9C 02                 */ IL_001c: ldarg.0
		/* 0x00002F9D 7B24000004         */ IL_001d: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::_theBlockTableControl /* 04000024 */
		/* 0x00002FA2 02                 */ IL_0022: ldarg.0
		/* 0x00002FA3 FE0671000006       */ IL_0023: ldftn instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::_theBlockTableControl_CurrentCategoryChanged(object, class [PresentationFramework]System.Windows.RoutedPropertyChangedEventArgs`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>) /* 06000071 */
		/* 0x00002FA9 735600000A         */ IL_0029: newobj instance void class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>::.ctor(object, native int) /* 0A000056 */
		/* 0x00002FAE 6F17000006         */ IL_002e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::add_CurrentCategoryChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category>) /* 06000017 */
		/* 0x00002FB3 2A                 */ IL_0033: ret
	} // end of method ModelLibraryControl::OnApplyTemplate

	.method /* 06000071 */ private hidebysig 
		instance void _theBlockTableControl_CurrentCategoryChanged (
			object sender,
			class [PresentationFramework]System.Windows.RoutedPropertyChangedEventArgs`1<class AspenTech.AspenPlus.ModelLibrary.Controls.Category> e
		) cil managed 
	{
		// Method begins at RVA 0x2fb5
		// Header size: 1
		// Code size: 63 (0x3f)
		.maxstack 8

		/* 0x00002FB5 02                 */ IL_0000: ldarg.0
		/* 0x00002FB6 7B24000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::_theBlockTableControl /* 04000024 */
		/* 0x00002FBB 6F0B000006         */ IL_0006: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_CurrentCategory() /* 0600000B */
		/* 0x00002FC0 2C31               */ IL_000b: brfalse.s IL_003e
		/* 0x00002FC2 02                 */ IL_000d: ldarg.0
		/* 0x00002FC3 02                 */ IL_000e: ldarg.0
		/* 0x00002FC4 7B24000004         */ IL_000f: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::_theBlockTableControl /* 04000024 */
		/* 0x00002FC9 6F0B000006         */ IL_0014: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_CurrentCategory() /* 0600000B */
		/* 0x00002FCE 7B0E000004         */ IL_0019: ldfld string AspenTech.AspenPlus.ModelLibrary.Controls.Category::HelpFile /* 0400000E */
		/* 0x00002FD3 285700000A         */ IL_001e: call void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMHelp::SetHelpFile(class [WindowsBase]System.Windows.DependencyObject, string) /* 0A000057 */
		/* 0x00002FD8 02                 */ IL_0023: ldarg.0
		/* 0x00002FD9 02                 */ IL_0024: ldarg.0
		/* 0x00002FDA 7B24000004         */ IL_0025: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::_theBlockTableControl /* 04000024 */
		/* 0x00002FDF 6F0B000006         */ IL_002a: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.BlockTableControl::get_CurrentCategory() /* 0600000B */
		/* 0x00002FE4 6F20000006         */ IL_002f: callvirt instance int32 AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_HelpId() /* 06000020 */
		/* 0x00002FE9 735800000A         */ IL_0034: newobj instance void valuetype [mscorlib]System.Nullable`1<int32>::.ctor(!0) /* 0A000058 */
		/* 0x00002FEE 285900000A         */ IL_0039: call void [AspenTech.AspenPlus.MMControls]AspenTech.AspenPlus.MMControls.MMHelp::SetHelpId(class [WindowsBase]System.Windows.DependencyObject, valuetype [mscorlib]System.Nullable`1<int32>) /* 0A000059 */
		/* 0x00002FF3 2A                 */ IL_003e: ret
	} // end of method ModelLibraryControl::_theBlockTableControl_CurrentCategoryChanged

	.method /* 06000072 */ family hidebysig newslot virtual 
		instance void OnSelectionChanged (
			object oldSelection,
			object newSelection
		) cil managed 
	{
		// Method begins at RVA 0x2ff5
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x00002FF5 02                 */ IL_0000: ldarg.0
		/* 0x00002FF6 03                 */ IL_0001: ldarg.1
		/* 0x00002FF7 04                 */ IL_0002: ldarg.2
		/* 0x00002FF8 7E31000004         */ IL_0003: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::SelectionChangedEvent /* 04000031 */
		/* 0x00002FFD 735A00000A         */ IL_0008: newobj instance void class [PresentationFramework]System.Windows.RoutedPropertyChangedEventArgs`1<object>::.ctor(!0, !0, class [PresentationCore]System.Windows.RoutedEvent) /* 0A00005A */
		/* 0x00003002 25                 */ IL_000d: dup
		/* 0x00003003 02                 */ IL_000e: ldarg.0
		/* 0x00003004 6F5B00000A         */ IL_000f: callvirt instance void [PresentationCore]System.Windows.RoutedEventArgs::set_Source(object) /* 0A00005B */
		/* 0x00003009 283300000A         */ IL_0014: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x0000300E 2A                 */ IL_0019: ret
	} // end of method ModelLibraryControl::OnSelectionChanged

	.method /* 06000073 */ family hidebysig newslot virtual 
		instance void OnOnIsOptionIconCheckedChanged (
			bool oldValue,
			bool newValue
		) cil managed 
	{
		// Method begins at RVA 0x3010
		// Header size: 12
		// Code size: 51 (0x33)
		.maxstack 4
		.locals /* 11000006 */ init (
			[0] object
		)

		/* 0x00003010 04                 */ IL_0000: ldarg.2
		/* 0x00003011 2C2F               */ IL_0001: brfalse.s IL_0032
		/* 0x00003013 02                 */ IL_0003: ldarg.0
		/* 0x00003014 02                 */ IL_0004: ldarg.0
		/* 0x00003015 2861000006         */ IL_0005: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_SelectedStreamModel() /* 06000061 */
		/* 0x0000301A 02                 */ IL_000a: ldarg.0
		/* 0x0000301B 2863000006         */ IL_000b: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_SelectedBlockIcon() /* 06000063 */
		/* 0x00003020 03                 */ IL_0010: ldarg.1
		/* 0x00003021 2877000006         */ IL_0011: call instance object AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::GetOldSelectedObject(class AspenTech.AspenPlus.ModelLibrary.Controls.Model, class AspenTech.AspenPlus.ModelLibrary.Controls.Icon, bool) /* 06000077 */
		/* 0x00003026 0A                 */ IL_0016: stloc.0
		/* 0x00003027 02                 */ IL_0017: ldarg.0
		/* 0x00003028 14                 */ IL_0018: ldnull
		/* 0x00003029 2862000006         */ IL_0019: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedStreamModel(class AspenTech.AspenPlus.ModelLibrary.Controls.Model) /* 06000062 */
		/* 0x0000302E 02                 */ IL_001e: ldarg.0
		/* 0x0000302F 14                 */ IL_001f: ldnull
		/* 0x00003030 2864000006         */ IL_0020: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedBlockIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon) /* 06000064 */
		/* 0x00003035 02                 */ IL_0025: ldarg.0
		/* 0x00003036 06                 */ IL_0026: ldloc.0
		/* 0x00003037 04                 */ IL_0027: ldarg.2
		/* 0x00003038 8C5F000001         */ IL_0028: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000303D 6F72000006         */ IL_002d: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectionChanged(object, object) /* 06000072 */
		/* 0x00003042 2A                 */ IL_0032: ret
	} // end of method ModelLibraryControl::OnOnIsOptionIconCheckedChanged

	.method /* 06000074 */ family hidebysig newslot virtual 
		instance void OnSelectedStreamModelChanged (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model oldValue,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model newValue
		) cil managed 
	{
		// Method begins at RVA 0x3050
		// Header size: 12
		// Code size: 46 (0x2e)
		.maxstack 4
		.locals /* 11000006 */ init (
			[0] object
		)

		/* 0x00003050 04                 */ IL_0000: ldarg.2
		/* 0x00003051 2C2A               */ IL_0001: brfalse.s IL_002d
		/* 0x00003053 02                 */ IL_0003: ldarg.0
		/* 0x00003054 03                 */ IL_0004: ldarg.1
		/* 0x00003055 02                 */ IL_0005: ldarg.0
		/* 0x00003056 2863000006         */ IL_0006: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_SelectedBlockIcon() /* 06000063 */
		/* 0x0000305B 02                 */ IL_000b: ldarg.0
		/* 0x0000305C 285F000006         */ IL_000c: call instance bool AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_IsOptionIconChecked() /* 0600005F */
		/* 0x00003061 2877000006         */ IL_0011: call instance object AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::GetOldSelectedObject(class AspenTech.AspenPlus.ModelLibrary.Controls.Model, class AspenTech.AspenPlus.ModelLibrary.Controls.Icon, bool) /* 06000077 */
		/* 0x00003066 0A                 */ IL_0016: stloc.0
		/* 0x00003067 02                 */ IL_0017: ldarg.0
		/* 0x00003068 16                 */ IL_0018: ldc.i4.0
		/* 0x00003069 2860000006         */ IL_0019: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_IsOptionIconChecked(bool) /* 06000060 */
		/* 0x0000306E 02                 */ IL_001e: ldarg.0
		/* 0x0000306F 14                 */ IL_001f: ldnull
		/* 0x00003070 2864000006         */ IL_0020: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedBlockIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon) /* 06000064 */
		/* 0x00003075 02                 */ IL_0025: ldarg.0
		/* 0x00003076 06                 */ IL_0026: ldloc.0
		/* 0x00003077 04                 */ IL_0027: ldarg.2
		/* 0x00003078 6F72000006         */ IL_0028: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectionChanged(object, object) /* 06000072 */
		/* 0x0000307D 2A                 */ IL_002d: ret
	} // end of method ModelLibraryControl::OnSelectedStreamModelChanged

	.method /* 06000075 */ family hidebysig 
		instance int32 ParseDescription (
			string sDescription,
			[out] string& sModelName,
			[out] string& sModelVersion
		) cil managed 
	{
		// Method begins at RVA 0x308c
		// Header size: 12
		// Code size: 152 (0x98)
		.maxstack 5
		.locals /* 11000007 */ init (
			[0] int32,
			[1] string[]
		)

		/* 0x0000308C 16                 */ IL_0000: ldc.i4.0
		/* 0x0000308D 0A                 */ IL_0001: stloc.0
		/* 0x0000308E 04                 */ IL_0002: ldarg.2
		/* 0x0000308F 7273040070         */ IL_0003: ldstr "" /* 70000473 */
		/* 0x00003094 51                 */ IL_0008: stind.ref
		/* 0x00003095 05                 */ IL_0009: ldarg.3
		/* 0x00003096 7273040070         */ IL_000a: ldstr "" /* 70000473 */
		/* 0x0000309B 51                 */ IL_000f: stind.ref
		/* 0x0000309C 03                 */ IL_0010: ldarg.1
		/* 0x0000309D 17                 */ IL_0011: ldc.i4.1
		/* 0x0000309E 8D61000001         */ IL_0012: newarr [mscorlib]System.Char /* 01000061 */
		/* 0x000030A3 25                 */ IL_0017: dup
		/* 0x000030A4 16                 */ IL_0018: ldc.i4.0
		/* 0x000030A5 1F20               */ IL_0019: ldc.i4.s 32
		/* 0x000030A7 9D                 */ IL_001b: stelem.i2
		/* 0x000030A8 6F5C00000A         */ IL_001c: callvirt instance string[] [mscorlib]System.String::Split(char[]) /* 0A00005C */
		/* 0x000030AD 0B                 */ IL_0021: stloc.1
		/* 0x000030AE 07                 */ IL_0022: ldloc.1
		/* 0x000030AF 16                 */ IL_0023: ldc.i4.0
		/* 0x000030B0 9A                 */ IL_0024: ldelem.ref
		/* 0x000030B1 7275040070         */ IL_0025: ldstr "ACM" /* 70000475 */
		/* 0x000030B6 284B00000A         */ IL_002a: call bool [mscorlib]System.String::op_Inequality(string, string) /* 0A00004B */
		/* 0x000030BB 2C02               */ IL_002f: brfalse.s IL_0033
		/* 0x000030BD 06                 */ IL_0031: ldloc.0
		/* 0x000030BE 2A                 */ IL_0032: ret
		/* 0x000030BF 07                 */ IL_0033: ldloc.1
		/* 0x000030C0 17                 */ IL_0034: ldc.i4.1
		/* 0x000030C1 9A                 */ IL_0035: ldelem.ref
		/* 0x000030C2 727D040070         */ IL_0036: ldstr "Model" /* 7000047D */
		/* 0x000030C7 284B00000A         */ IL_003b: call bool [mscorlib]System.String::op_Inequality(string, string) /* 0A00004B */
		/* 0x000030CC 2C02               */ IL_0040: brfalse.s IL_0044
		/* 0x000030CE 06                 */ IL_0042: ldloc.0
		/* 0x000030CF 2A                 */ IL_0043: ret
		/* 0x000030D0 18                 */ IL_0044: ldc.i4.2
		/* 0x000030D1 0A                 */ IL_0045: stloc.0
		/* 0x000030D2 07                 */ IL_0046: ldloc.1
		/* 0x000030D3 8E                 */ IL_0047: ldlen
		/* 0x000030D4 69                 */ IL_0048: conv.i4
		/* 0x000030D5 19                 */ IL_0049: ldc.i4.3
		/* 0x000030D6 3207               */ IL_004a: blt.s IL_0053
		/* 0x000030D8 04                 */ IL_004c: ldarg.2
		/* 0x000030D9 07                 */ IL_004d: ldloc.1
		/* 0x000030DA 18                 */ IL_004e: ldc.i4.2
		/* 0x000030DB 9A                 */ IL_004f: ldelem.ref
		/* 0x000030DC 51                 */ IL_0050: stind.ref
		/* 0x000030DD 2B02               */ IL_0051: br.s IL_0055
		/* 0x000030DF 06                 */ IL_0053: ldloc.0
		/* 0x000030E0 2A                 */ IL_0054: ret
		/* 0x000030E1 07                 */ IL_0055: ldloc.1
		/* 0x000030E2 8E                 */ IL_0056: ldlen
		/* 0x000030E3 69                 */ IL_0057: conv.i4
		/* 0x000030E4 1D                 */ IL_0058: ldc.i4.7
		/* 0x000030E5 3207               */ IL_0059: blt.s IL_0062
		/* 0x000030E7 05                 */ IL_005b: ldarg.3
		/* 0x000030E8 07                 */ IL_005c: ldloc.1
		/* 0x000030E9 1C                 */ IL_005d: ldc.i4.6
		/* 0x000030EA 9A                 */ IL_005e: ldelem.ref
		/* 0x000030EB 51                 */ IL_005f: stind.ref
		/* 0x000030EC 2B02               */ IL_0060: br.s IL_0064
		/* 0x000030EE 06                 */ IL_0062: ldloc.0
		/* 0x000030EF 2A                 */ IL_0063: ret
		/* 0x000030F0 1F1C               */ IL_0064: ldc.i4.s 28
		/* 0x000030F2 285D00000A         */ IL_0066: call string [mscorlib]System.Environment::GetFolderPath(valuetype [mscorlib]System.Environment/SpecialFolder) /* 0A00005D */
		/* 0x000030F7 7289040070         */ IL_006b: ldstr "AspenTech\\AES\\AM Models" /* 70000489 */
		/* 0x000030FC 285E00000A         */ IL_0070: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A00005E */
		/* 0x00003101 05                 */ IL_0075: ldarg.3
		/* 0x00003102 50                 */ IL_0076: ldind.ref
		/* 0x00003103 285E00000A         */ IL_0077: call string [mscorlib]System.IO.Path::Combine(string, string) /* 0A00005E */
		/* 0x00003108 72B9040070         */ IL_007c: ldstr "\\" /* 700004B9 */
		/* 0x0000310D 04                 */ IL_0081: ldarg.2
		/* 0x0000310E 50                 */ IL_0082: ldind.ref
		/* 0x0000310F 72BD040070         */ IL_0083: ldstr ".atmlz" /* 700004BD */
		/* 0x00003114 285000000A         */ IL_0088: call string [mscorlib]System.String::Concat(string, string, string, string) /* 0A000050 */
		/* 0x00003119 285F00000A         */ IL_008d: call bool [mscorlib]System.IO.File::Exists(string) /* 0A00005F */
		/* 0x0000311E 2C02               */ IL_0092: brfalse.s IL_0096
		/* 0x00003120 17                 */ IL_0094: ldc.i4.1
		/* 0x00003121 0A                 */ IL_0095: stloc.0
		/* 0x00003122 06                 */ IL_0096: ldloc.0
		/* 0x00003123 2A                 */ IL_0097: ret
	} // end of method ModelLibraryControl::ParseDescription

	.method /* 06000076 */ family hidebysig newslot virtual 
		instance void OnSelectedBlockIconChanged (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon oldValue,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon newValue
		) cil managed 
	{
		// Method begins at RVA 0x3130
		// Header size: 12
		// Code size: 179 (0xb3)
		.maxstack 4
		.locals /* 11000008 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.Category,
			[1] object,
			[2] string,
			[3] string,
			[4] string,
			[5] string,
			[6] string
		)

		/* 0x00003130 04                 */ IL_0000: ldarg.2
		/* 0x00003131 39AC000000         */ IL_0001: brfalse IL_00b2
		/* 0x00003136 02                 */ IL_0006: ldarg.0
		/* 0x00003137 286B000006         */ IL_0007: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_CurrentBlockCategory() /* 0600006B */
		/* 0x0000313C 0A                 */ IL_000c: stloc.0
		/* 0x0000313D 06                 */ IL_000d: ldloc.0
		/* 0x0000313E 2C78               */ IL_000e: brfalse.s IL_0088
		/* 0x00003140 06                 */ IL_0010: ldloc.0
		/* 0x00003141 6F25000006         */ IL_0011: callvirt instance object AspenTech.AspenPlus.ModelLibrary.Controls.Category::get_Name() /* 06000025 */
		/* 0x00003146 755A000001         */ IL_0016: isinst [mscorlib]System.String /* 0100005A */
		/* 0x0000314B 72CB040070         */ IL_001b: ldstr "ACM Models" /* 700004CB */
		/* 0x00003150 284200000A         */ IL_0020: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x00003155 2C61               */ IL_0025: brfalse.s IL_0088
		/* 0x00003157 04                 */ IL_0027: ldarg.2
		/* 0x00003158 6F37000006         */ IL_0028: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.Icon::get_Parent() /* 06000037 */
		/* 0x0000315D 6F4D000006         */ IL_002d: callvirt instance string AspenTech.AspenPlus.ModelLibrary.Controls.Model::get_Description() /* 0600004D */
		/* 0x00003162 0C                 */ IL_0032: stloc.2
		/* 0x00003163 08                 */ IL_0033: ldloc.2
		/* 0x00003164 284300000A         */ IL_0034: call bool [mscorlib]System.String::IsNullOrEmpty(string) /* 0A000043 */
		/* 0x00003169 2D4D               */ IL_0039: brtrue.s IL_0088
		/* 0x0000316B 7273040070         */ IL_003b: ldstr "" /* 70000473 */
		/* 0x00003170 0D                 */ IL_0040: stloc.3
		/* 0x00003171 7273040070         */ IL_0041: ldstr "" /* 70000473 */
		/* 0x00003176 1304               */ IL_0046: stloc.s 4
		/* 0x00003178 02                 */ IL_0048: ldarg.0
		/* 0x00003179 08                 */ IL_0049: ldloc.2
		/* 0x0000317A 1203               */ IL_004a: ldloca.s 3
		/* 0x0000317C 1204               */ IL_004c: ldloca.s 4
		/* 0x0000317E 2875000006         */ IL_004e: call instance int32 AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::ParseDescription(string, string&, string&) /* 06000075 */
		/* 0x00003183 18                 */ IL_0053: ldc.i4.2
		/* 0x00003184 3332               */ IL_0054: bne.un.s IL_0088
		/* 0x00003186 286000000A         */ IL_0056: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.SorResources::get__638() /* 0A000060 */
		/* 0x0000318B 1305               */ IL_005b: stloc.s 5
		/* 0x0000318D 286100000A         */ IL_005d: call string [AspenTech.AspenPlus.Localization]AspenTech.AspenPlus.Localization.SorResources::get__639() /* 0A000061 */
		/* 0x00003192 09                 */ IL_0062: ldloc.3
		/* 0x00003193 1104               */ IL_0063: ldloc.s 4
		/* 0x00003195 286200000A         */ IL_0065: call string [mscorlib]System.String::Format(string, object, object) /* 0A000062 */
		/* 0x0000319A 1105               */ IL_006a: ldloc.s 5
		/* 0x0000319C 1306               */ IL_006c: stloc.s 6
		/* 0x0000319E 1106               */ IL_006e: ldloc.s 6
		/* 0x000031A0 16                 */ IL_0070: ldc.i4.0
		/* 0x000031A1 1F30               */ IL_0071: ldc.i4.s 48
		/* 0x000031A3 286300000A         */ IL_0073: call valuetype [PresentationFramework]System.Windows.MessageBoxResult [PresentationFramework]System.Windows.MessageBox::Show(string, string, valuetype [PresentationFramework]System.Windows.MessageBoxButton, valuetype [PresentationFramework]System.Windows.MessageBoxImage) /* 0A000063 */
		/* 0x000031A8 26                 */ IL_0078: pop
		/* 0x000031A9 02                 */ IL_0079: ldarg.0
		/* 0x000031AA 16                 */ IL_007a: ldc.i4.0
		/* 0x000031AB 2860000006         */ IL_007b: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_IsOptionIconChecked(bool) /* 06000060 */
		/* 0x000031B0 02                 */ IL_0080: ldarg.0
		/* 0x000031B1 14                 */ IL_0081: ldnull
		/* 0x000031B2 2864000006         */ IL_0082: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedBlockIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon) /* 06000064 */
		/* 0x000031B7 2A                 */ IL_0087: ret
		/* 0x000031B8 02                 */ IL_0088: ldarg.0
		/* 0x000031B9 02                 */ IL_0089: ldarg.0
		/* 0x000031BA 2861000006         */ IL_008a: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_SelectedStreamModel() /* 06000061 */
		/* 0x000031BF 03                 */ IL_008f: ldarg.1
		/* 0x000031C0 02                 */ IL_0090: ldarg.0
		/* 0x000031C1 285F000006         */ IL_0091: call instance bool AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_IsOptionIconChecked() /* 0600005F */
		/* 0x000031C6 2877000006         */ IL_0096: call instance object AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::GetOldSelectedObject(class AspenTech.AspenPlus.ModelLibrary.Controls.Model, class AspenTech.AspenPlus.ModelLibrary.Controls.Icon, bool) /* 06000077 */
		/* 0x000031CB 0B                 */ IL_009b: stloc.1
		/* 0x000031CC 02                 */ IL_009c: ldarg.0
		/* 0x000031CD 16                 */ IL_009d: ldc.i4.0
		/* 0x000031CE 2860000006         */ IL_009e: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_IsOptionIconChecked(bool) /* 06000060 */
		/* 0x000031D3 02                 */ IL_00a3: ldarg.0
		/* 0x000031D4 14                 */ IL_00a4: ldnull
		/* 0x000031D5 2862000006         */ IL_00a5: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedStreamModel(class AspenTech.AspenPlus.ModelLibrary.Controls.Model) /* 06000062 */
		/* 0x000031DA 02                 */ IL_00aa: ldarg.0
		/* 0x000031DB 07                 */ IL_00ab: ldloc.1
		/* 0x000031DC 04                 */ IL_00ac: ldarg.2
		/* 0x000031DD 6F72000006         */ IL_00ad: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectionChanged(object, object) /* 06000072 */
		/* 0x000031E2 2A                 */ IL_00b2: ret
	} // end of method ModelLibraryControl::OnSelectedBlockIconChanged

	.method /* 06000077 */ private hidebysig 
		instance object GetOldSelectedObject (
			class AspenTech.AspenPlus.ModelLibrary.Controls.Model oldModel,
			class AspenTech.AspenPlus.ModelLibrary.Controls.Icon oldIcon,
			bool oldChecked
		) cil managed 
	{
		// Method begins at RVA 0x31ef
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000031EF 03                 */ IL_0000: ldarg.1
		/* 0x000031F0 2C02               */ IL_0001: brfalse.s IL_0005
		/* 0x000031F2 03                 */ IL_0003: ldarg.1
		/* 0x000031F3 2A                 */ IL_0004: ret
		/* 0x000031F4 04                 */ IL_0005: ldarg.2
		/* 0x000031F5 2C02               */ IL_0006: brfalse.s IL_000a
		/* 0x000031F7 04                 */ IL_0008: ldarg.2
		/* 0x000031F8 2A                 */ IL_0009: ret
		/* 0x000031F9 05                 */ IL_000a: ldarg.3
		/* 0x000031FA 8C5F000001         */ IL_000b: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x000031FF 2A                 */ IL_0010: ret
	} // end of method ModelLibraryControl::GetOldSelectedObject

	.method /* 06000078 */ private hidebysig static 
		void OptionButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3204
		// Header size: 12
		// Code size: 43 (0x2b)
		.maxstack 2
		.locals /* 11000009 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl
		)

		/* 0x00003204 02                 */ IL_0000: ldarg.0
		/* 0x00003205 750C000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x0000320A 0A                 */ IL_0006: stloc.0
		/* 0x0000320B 03                 */ IL_0007: ldarg.1
		/* 0x0000320C 6F3500000A         */ IL_0008: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000035 */
		/* 0x00003211 750E000002         */ IL_000d: isinst AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x00003216 6F6400000A         */ IL_0012: callvirt instance string [PresentationFramework]System.Windows.FrameworkElement::get_Name() /* 0A000064 */
		/* 0x0000321B 72E1040070         */ IL_0017: ldstr "PART_SelectorButton" /* 700004E1 */
		/* 0x00003220 284200000A         */ IL_001c: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x00003225 2C07               */ IL_0021: brfalse.s IL_002a
		/* 0x00003227 06                 */ IL_0023: ldloc.0
		/* 0x00003228 17                 */ IL_0024: ldc.i4.1
		/* 0x00003229 6F60000006         */ IL_0025: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_IsOptionIconChecked(bool) /* 06000060 */
		/* 0x0000322E 2A                 */ IL_002a: ret
	} // end of method ModelLibraryControl::OptionButton_Click

	.method /* 06000079 */ private hidebysig static 
		void DropdownButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x323c
		// Header size: 12
		// Code size: 55 (0x37)
		.maxstack 2
		.locals /* 1100000A */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl,
			[1] class AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton
		)

		/* 0x0000323C 02                 */ IL_0000: ldarg.0
		/* 0x0000323D 750C000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00003242 0A                 */ IL_0006: stloc.0
		/* 0x00003243 03                 */ IL_0007: ldarg.1
		/* 0x00003244 6F3500000A         */ IL_0008: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000035 */
		/* 0x00003249 750F000002         */ IL_000d: isinst AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x0000324E 0B                 */ IL_0012: stloc.1
		/* 0x0000324F 07                 */ IL_0013: ldloc.1
		/* 0x00003250 6F6400000A         */ IL_0014: callvirt instance string [PresentationFramework]System.Windows.FrameworkElement::get_Name() /* 0A000064 */
		/* 0x00003255 7209050070         */ IL_0019: ldstr "PART_StreamsDropdownButton" /* 70000509 */
		/* 0x0000325A 284200000A         */ IL_001e: call bool [mscorlib]System.String::op_Equality(string, string) /* 0A000042 */
		/* 0x0000325F 2C11               */ IL_0023: brfalse.s IL_0036
		/* 0x00003261 06                 */ IL_0025: ldloc.0
		/* 0x00003262 07                 */ IL_0026: ldloc.1
		/* 0x00003263 6F3600000A         */ IL_0027: callvirt instance object [PresentationFramework]System.Windows.Controls.Primitives.Selector::get_SelectedItem() /* 0A000036 */
		/* 0x00003268 750A000002         */ IL_002c: isinst AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x0000326D 6F62000006         */ IL_0031: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedStreamModel(class AspenTech.AspenPlus.ModelLibrary.Controls.Model) /* 06000062 */
		/* 0x00003272 2A                 */ IL_0036: ret
	} // end of method ModelLibraryControl::DropdownButton_Click

	.method /* 0600007A */ private hidebysig static 
		void OnIsOptionIconCheckedPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x327f
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x0000327F 02                 */ IL_0000: ldarg.0
		/* 0x00003280 750C000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x00003285 0F01               */ IL_0006: ldarga.s e
		/* 0x00003287 283D00000A         */ IL_0008: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_OldValue() /* 0A00003D */
		/* 0x0000328C A55F000001         */ IL_000d: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003291 0F01               */ IL_0012: ldarga.s e
		/* 0x00003293 283E00000A         */ IL_0014: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00003E */
		/* 0x00003298 A55F000001         */ IL_0019: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000329D 6F73000006         */ IL_001e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnOnIsOptionIconCheckedChanged(bool, bool) /* 06000073 */
		/* 0x000032A2 2A                 */ IL_0023: ret
	} // end of method ModelLibraryControl::OnIsOptionIconCheckedPropertyChanged

	.method /* 0600007B */ private hidebysig static 
		void OnSelectedStreamModelPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x32a4
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x000032A4 02                 */ IL_0000: ldarg.0
		/* 0x000032A5 750C000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x000032AA 0F01               */ IL_0006: ldarga.s e
		/* 0x000032AC 283D00000A         */ IL_0008: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_OldValue() /* 0A00003D */
		/* 0x000032B1 740A000002         */ IL_000d: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x000032B6 0F01               */ IL_0012: ldarga.s e
		/* 0x000032B8 283E00000A         */ IL_0014: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00003E */
		/* 0x000032BD 740A000002         */ IL_0019: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x000032C2 6F74000006         */ IL_001e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectedStreamModelChanged(class AspenTech.AspenPlus.ModelLibrary.Controls.Model, class AspenTech.AspenPlus.ModelLibrary.Controls.Model) /* 06000074 */
		/* 0x000032C7 2A                 */ IL_0023: ret
	} // end of method ModelLibraryControl::OnSelectedStreamModelPropertyChanged

	.method /* 0600007C */ private hidebysig static 
		void OnSelectedBlockIconPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x32c9
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x000032C9 02                 */ IL_0000: ldarg.0
		/* 0x000032CA 750C000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl /* 0200000C */
		/* 0x000032CF 0F01               */ IL_0006: ldarga.s e
		/* 0x000032D1 283D00000A         */ IL_0008: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_OldValue() /* 0A00003D */
		/* 0x000032D6 7407000002         */ IL_000d: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x000032DB 0F01               */ IL_0012: ldarga.s e
		/* 0x000032DD 283E00000A         */ IL_0014: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00003E */
		/* 0x000032E2 7407000002         */ IL_0019: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Icon /* 02000007 */
		/* 0x000032E7 6F76000006         */ IL_001e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::OnSelectedBlockIconChanged(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon, class AspenTech.AspenPlus.ModelLibrary.Controls.Icon) /* 06000076 */
		/* 0x000032EC 2A                 */ IL_0023: ret
	} // end of method ModelLibraryControl::OnSelectedBlockIconPropertyChanged

	.method /* 0600007D */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x257d
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x0000257D 02                 */ IL_0000: ldarg.0
		/* 0x0000257E 283F00000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Control::.ctor() /* 0A00003F */
		/* 0x00002583 2A                 */ IL_0006: ret
	} // end of method ModelLibraryControl::.ctor

	// Events
	.event /* 14000003 */ class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<object> SelectionChanged
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::add_SelectionChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<object>)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::remove_SelectionChanged(class [PresentationFramework]System.Windows.RoutedPropertyChangedEventHandler`1<object>)
	}


	// Properties
	.property /* 17000020 */ instance valuetype [PresentationFramework]System.Windows.Controls.Dock Dock()
	{
		.get instance valuetype [PresentationFramework]System.Windows.Controls.Dock AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_Dock()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_Dock(valuetype [PresentationFramework]System.Windows.Controls.Dock)
	}
	.property /* 17000021 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Library ModelLibrary()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Library AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_ModelLibrary()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_ModelLibrary(class AspenTech.AspenPlus.ModelLibrary.Controls.Library)
	}
	.property /* 17000022 */ instance bool IsOptionIconChecked()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_IsOptionIconChecked()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_IsOptionIconChecked(bool)
	}
	.property /* 17000023 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model SelectedStreamModel()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Model AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_SelectedStreamModel()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedStreamModel(class AspenTech.AspenPlus.ModelLibrary.Controls.Model)
	}
	.property /* 17000024 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon SelectedBlockIcon()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Icon AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_SelectedBlockIcon()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_SelectedBlockIcon(class AspenTech.AspenPlus.ModelLibrary.Controls.Icon)
	}
	.property /* 17000025 */ instance valuetype [WindowsBase]System.Windows.Size ButtonSize()
	{
		.get instance valuetype [WindowsBase]System.Windows.Size AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_ButtonSize()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_ButtonSize(valuetype [WindowsBase]System.Windows.Size)
	}
	.property /* 17000026 */ instance class [PresentationCore]System.Windows.Media.Brush DefaultButtonBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_DefaultButtonBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_DefaultButtonBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000027 */ instance class [PresentationCore]System.Windows.Media.Brush CheckedButtonBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_CheckedButtonBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_CheckedButtonBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000028 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category CurrentBlockCategory()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.Category AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::get_CurrentBlockCategory()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl::set_CurrentBlockCategory(class AspenTech.AspenPlus.ModelLibrary.Controls.Category)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.ModelLibraryControl

.class /* 0200000D */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase
	extends [mscorlib]System.Object
	implements [System]System.ComponentModel.INotifyPropertyChanged
{
	// Fields
	.field /* 04000032 */ private class [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	.custom /* 0C00003A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 0600007E */ public final hidebysig specialname newslot virtual 
		instance void add_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00004C */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x32f0
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x000032F0 02                 */ IL_0000: ldarg.0
		/* 0x000032F1 7B32000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::PropertyChanged /* 04000032 */
		/* 0x000032F6 0A                 */ IL_0006: stloc.0
		/* 0x000032F7 06                 */ IL_0007: ldloc.0
		/* 0x000032F8 0B                 */ IL_0008: stloc.1
		/* 0x000032F9 07                 */ IL_0009: ldloc.1
		/* 0x000032FA 03                 */ IL_000a: ldarg.1
		/* 0x000032FB 286500000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Combine(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000065 */
		/* 0x00003300 7434000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000034 */
		/* 0x00003305 0C                 */ IL_0015: stloc.2
		/* 0x00003306 02                 */ IL_0016: ldarg.0
		/* 0x00003307 7C32000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::PropertyChanged /* 04000032 */
		/* 0x0000330C 08                 */ IL_001c: ldloc.2
		/* 0x0000330D 07                 */ IL_001d: ldloc.1
		/* 0x0000330E 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x00003313 0A                 */ IL_0023: stloc.0
		/* 0x00003314 06                 */ IL_0024: ldloc.0
		/* 0x00003315 07                 */ IL_0025: ldloc.1
		/* 0x00003316 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00003318 2A                 */ IL_0028: ret
	} // end of method NotifyPropertyChangedBase::add_PropertyChanged

	.method /* 0600007F */ public final hidebysig specialname newslot virtual 
		instance void remove_PropertyChanged (
			class [System]System.ComponentModel.PropertyChangedEventHandler 'value'
		) cil managed 
	{
		.custom /* 0C00004D */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x3328
		// Header size: 12
		// Code size: 41 (0x29)
		.maxstack 3
		.locals /* 1100000B */ init (
			[0] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[1] class [System]System.ComponentModel.PropertyChangedEventHandler,
			[2] class [System]System.ComponentModel.PropertyChangedEventHandler
		)

		/* 0x00003328 02                 */ IL_0000: ldarg.0
		/* 0x00003329 7B32000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::PropertyChanged /* 04000032 */
		/* 0x0000332E 0A                 */ IL_0006: stloc.0
		/* 0x0000332F 06                 */ IL_0007: ldloc.0
		/* 0x00003330 0B                 */ IL_0008: stloc.1
		/* 0x00003331 07                 */ IL_0009: ldloc.1
		/* 0x00003332 03                 */ IL_000a: ldarg.1
		/* 0x00003333 286700000A         */ IL_000b: call class [mscorlib]System.Delegate [mscorlib]System.Delegate::Remove(class [mscorlib]System.Delegate, class [mscorlib]System.Delegate) /* 0A000067 */
		/* 0x00003338 7434000001         */ IL_0010: castclass [System]System.ComponentModel.PropertyChangedEventHandler /* 01000034 */
		/* 0x0000333D 0C                 */ IL_0015: stloc.2
		/* 0x0000333E 02                 */ IL_0016: ldarg.0
		/* 0x0000333F 7C32000004         */ IL_0017: ldflda class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::PropertyChanged /* 04000032 */
		/* 0x00003344 08                 */ IL_001c: ldloc.2
		/* 0x00003345 07                 */ IL_001d: ldloc.1
		/* 0x00003346 280200002B         */ IL_001e: call !!0 [mscorlib]System.Threading.Interlocked::CompareExchange<class [System]System.ComponentModel.PropertyChangedEventHandler>(!!0&, !!0, !!0) /* 2B000002 */
		/* 0x0000334B 0A                 */ IL_0023: stloc.0
		/* 0x0000334C 06                 */ IL_0024: ldloc.0
		/* 0x0000334D 07                 */ IL_0025: ldloc.1
		/* 0x0000334E 33DF               */ IL_0026: bne.un.s IL_0007
		/* 0x00003350 2A                 */ IL_0028: ret
	} // end of method NotifyPropertyChangedBase::remove_PropertyChanged

	.method /* 06000080 */ family hidebysig newslot virtual 
		instance void OnPropertyChanged (
			string propertyName
		) cil managed 
	{
		// Method begins at RVA 0x335d
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x0000335D 02                 */ IL_0000: ldarg.0
		/* 0x0000335E 7B32000004         */ IL_0001: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::PropertyChanged /* 04000032 */
		/* 0x00003363 2C12               */ IL_0006: brfalse.s IL_001a
		/* 0x00003365 02                 */ IL_0008: ldarg.0
		/* 0x00003366 7B32000004         */ IL_0009: ldfld class [System]System.ComponentModel.PropertyChangedEventHandler AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::PropertyChanged /* 04000032 */
		/* 0x0000336B 02                 */ IL_000e: ldarg.0
		/* 0x0000336C 03                 */ IL_000f: ldarg.1
		/* 0x0000336D 736800000A         */ IL_0010: newobj instance void [System]System.ComponentModel.PropertyChangedEventArgs::.ctor(string) /* 0A000068 */
		/* 0x00003372 6F6900000A         */ IL_0015: callvirt instance void [System]System.ComponentModel.PropertyChangedEventHandler::Invoke(object, class [System]System.ComponentModel.PropertyChangedEventArgs) /* 0A000069 */
		/* 0x00003377 2A                 */ IL_001a: ret
	} // end of method NotifyPropertyChangedBase::OnPropertyChanged

	.method /* 06000081 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3379
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003379 02                 */ IL_0000: ldarg.0
		/* 0x0000337A 286A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00006A */
		/* 0x0000337F 2A                 */ IL_0006: ret
	} // end of method NotifyPropertyChangedBase::.ctor

	// Events
	.event /* 14000004 */ [System]System.ComponentModel.PropertyChangedEventHandler PropertyChanged
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::add_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase::remove_PropertyChanged(class [System]System.ComponentModel.PropertyChangedEventHandler)
	}


} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.NotifyPropertyChangedBase

.class /* 0200000E */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton
	extends [PresentationFramework]System.Windows.Controls.ContentControl
{
	// Fields
	.field /* 04000033 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty IsCheckedProperty
	.field /* 04000034 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CheckedBackgroundProperty
	.field /* 04000035 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ClickModeProperty
	.field /* 04000036 */ public static initonly class [PresentationCore]System.Windows.RoutedEvent ClickEvent

	// Methods
	.method /* 06000082 */ public hidebysig specialname 
		instance bool get_IsChecked () cil managed 
	{
		// Method begins at RVA 0x3381
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003381 02                 */ IL_0000: ldarg.0
		/* 0x00003382 7E33000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::IsCheckedProperty /* 04000033 */
		/* 0x00003387 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x0000338C A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003391 2A                 */ IL_0010: ret
	} // end of method OptionButton::get_IsChecked

	.method /* 06000083 */ public hidebysig specialname 
		instance void set_IsChecked (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3393
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003393 02                 */ IL_0000: ldarg.0
		/* 0x00003394 7E33000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::IsCheckedProperty /* 04000033 */
		/* 0x00003399 03                 */ IL_0006: ldarg.1
		/* 0x0000339A 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000339F 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000033A4 2A                 */ IL_0011: ret
	} // end of method OptionButton::set_IsChecked

	.method /* 06000084 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_CheckedBackground () cil managed 
	{
		// Method begins at RVA 0x33a6
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000033A6 02                 */ IL_0000: ldarg.0
		/* 0x000033A7 7E34000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::CheckedBackgroundProperty /* 04000034 */
		/* 0x000033AC 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000033B1 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x000033B6 2A                 */ IL_0010: ret
	} // end of method OptionButton::get_CheckedBackground

	.method /* 06000085 */ public hidebysig specialname 
		instance void set_CheckedBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x33b8
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000033B8 02                 */ IL_0000: ldarg.0
		/* 0x000033B9 7E34000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::CheckedBackgroundProperty /* 04000034 */
		/* 0x000033BE 03                 */ IL_0006: ldarg.1
		/* 0x000033BF 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000033C4 2A                 */ IL_000c: ret
	} // end of method OptionButton::set_CheckedBackground

	.method /* 06000086 */ public hidebysig specialname 
		instance valuetype [PresentationFramework]System.Windows.Controls.ClickMode get_ClickMode () cil managed 
	{
		// Method begins at RVA 0x33c6
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000033C6 02                 */ IL_0000: ldarg.0
		/* 0x000033C7 7E35000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickModeProperty /* 04000035 */
		/* 0x000033CC 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000033D1 A537000001         */ IL_000b: unbox.any [PresentationFramework]System.Windows.Controls.ClickMode /* 01000037 */
		/* 0x000033D6 2A                 */ IL_0010: ret
	} // end of method OptionButton::get_ClickMode

	.method /* 06000087 */ public hidebysig specialname 
		instance void set_ClickMode (
			valuetype [PresentationFramework]System.Windows.Controls.ClickMode 'value'
		) cil managed 
	{
		// Method begins at RVA 0x33d8
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000033D8 02                 */ IL_0000: ldarg.0
		/* 0x000033D9 7E35000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickModeProperty /* 04000035 */
		/* 0x000033DE 03                 */ IL_0006: ldarg.1
		/* 0x000033DF 8C37000001         */ IL_0007: box [PresentationFramework]System.Windows.Controls.ClickMode /* 01000037 */
		/* 0x000033E4 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000033E9 2A                 */ IL_0011: ret
	} // end of method OptionButton::set_ClickMode

	.method /* 06000088 */ public hidebysig specialname 
		instance void add_Click (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x33eb
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000033EB 02                 */ IL_0000: ldarg.0
		/* 0x000033EC 7E36000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickEvent /* 04000036 */
		/* 0x000033F1 03                 */ IL_0006: ldarg.1
		/* 0x000033F2 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x000033F7 2A                 */ IL_000c: ret
	} // end of method OptionButton::add_Click

	.method /* 06000089 */ public hidebysig specialname 
		instance void remove_Click (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x33f9
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000033F9 02                 */ IL_0000: ldarg.0
		/* 0x000033FA 7E36000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickEvent /* 04000036 */
		/* 0x000033FF 03                 */ IL_0006: ldarg.1
		/* 0x00003400 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x00003405 2A                 */ IL_000c: ret
	} // end of method OptionButton::remove_Click

	.method /* 0600008A */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x3408
		// Header size: 12
		// Code size: 370 (0x172)
		.maxstack 4

		/* 0x00003408 724F030070         */ IL_0000: ldstr "IsChecked" /* 7000034F */
		/* 0x0000340D D05F000001         */ IL_0005: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003412 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003417 D00E000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000341C 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003421 282700000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x00003426 8033000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::IsCheckedProperty /* 04000033 */
		/* 0x0000342B 723F050070         */ IL_0023: ldstr "CheckedBackground" /* 7000053F */
		/* 0x00003430 D026000001         */ IL_0028: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x00003435 282400000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000343A D00E000002         */ IL_0032: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000343F 282400000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003444 282C00000A         */ IL_003c: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_White() /* 0A00002C */
		/* 0x00003449 732500000A         */ IL_0041: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000344E 282600000A         */ IL_0046: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00003453 8034000004         */ IL_004b: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::CheckedBackgroundProperty /* 04000034 */
		/* 0x00003458 7263050070         */ IL_0050: ldstr "ClickMode" /* 70000563 */
		/* 0x0000345D D037000001         */ IL_0055: ldtoken [PresentationFramework]System.Windows.Controls.ClickMode /* 01000037 */
		/* 0x00003462 282400000A         */ IL_005a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003467 D00E000002         */ IL_005f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000346C 282400000A         */ IL_0064: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003471 16                 */ IL_0069: ldc.i4.0
		/* 0x00003472 8C37000001         */ IL_006a: box [PresentationFramework]System.Windows.Controls.ClickMode /* 01000037 */
		/* 0x00003477 732500000A         */ IL_006f: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000347C 282600000A         */ IL_0074: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00003481 8035000004         */ IL_0079: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickModeProperty /* 04000035 */
		/* 0x00003486 7277050070         */ IL_007e: ldstr "Click" /* 70000577 */
		/* 0x0000348B 17                 */ IL_0083: ldc.i4.1
		/* 0x0000348C D036000001         */ IL_0084: ldtoken [PresentationCore]System.Windows.RoutedEventHandler /* 01000036 */
		/* 0x00003491 282400000A         */ IL_0089: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003496 D00E000002         */ IL_008e: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000349B 282400000A         */ IL_0093: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000034A0 282D00000A         */ IL_0098: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x000034A5 8036000004         */ IL_009d: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickEvent /* 04000036 */
		/* 0x000034AA 7E2E00000A         */ IL_00a2: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x000034AF D00E000002         */ IL_00a7: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x000034B4 282400000A         */ IL_00ac: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000034B9 D00E000002         */ IL_00b1: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x000034BE 282400000A         */ IL_00b6: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000034C3 732500000A         */ IL_00bb: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x000034C8 6F2F00000A         */ IL_00c0: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x000034CD 7E6B00000A         */ IL_00c5: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::MinWidthProperty /* 0A00006B */
		/* 0x000034D2 D00E000002         */ IL_00ca: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x000034D7 282400000A         */ IL_00cf: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000034DC 230000000000805140 */ IL_00d4: ldc.r8 70
		/* 0x000034E5 8C6D000001         */ IL_00dd: box [mscorlib]System.Double /* 0100006D */
		/* 0x000034EA 732500000A         */ IL_00e2: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x000034EF 6F2F00000A         */ IL_00e7: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x000034F4 7E6C00000A         */ IL_00ec: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::MinHeightProperty /* 0A00006C */
		/* 0x000034F9 D00E000002         */ IL_00f1: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x000034FE 282400000A         */ IL_00f6: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003503 230000000000805140 */ IL_00fb: ldc.r8 70
		/* 0x0000350C 8C6D000001         */ IL_0104: box [mscorlib]System.Double /* 0100006D */
		/* 0x00003511 732500000A         */ IL_0109: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003516 6F2F00000A         */ IL_010e: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x0000351B 7E6D00000A         */ IL_0113: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.Controls.Control::HorizontalContentAlignmentProperty /* 0A00006D */
		/* 0x00003520 D00E000002         */ IL_0118: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x00003525 282400000A         */ IL_011d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000352A 19                 */ IL_0122: ldc.i4.3
		/* 0x0000352B 8C6E000001         */ IL_0123: box [PresentationFramework]System.Windows.HorizontalAlignment /* 0100006E */
		/* 0x00003530 732500000A         */ IL_0128: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003535 6F2F00000A         */ IL_012d: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x0000353A 7E6E00000A         */ IL_0132: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.Controls.Control::VerticalContentAlignmentProperty /* 0A00006E */
		/* 0x0000353F D00E000002         */ IL_0137: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x00003544 282400000A         */ IL_013c: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003549 19                 */ IL_0141: ldc.i4.3
		/* 0x0000354A 8C6F000001         */ IL_0142: box [PresentationFramework]System.Windows.VerticalAlignment /* 0100006F */
		/* 0x0000354F 732500000A         */ IL_0147: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003554 6F2F00000A         */ IL_014c: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x00003559 D00E000002         */ IL_0151: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000355E 282400000A         */ IL_0156: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003563 7E6F00000A         */ IL_015b: ldsfld class [PresentationCore]System.Windows.RoutedEvent [PresentationFramework]System.Windows.Controls.Primitives.ButtonBase::ClickEvent /* 0A00006F */
		/* 0x00003568 14                 */ IL_0160: ldnull
		/* 0x00003569 FE068C000006       */ IL_0161: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::Button_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 0600008C */
		/* 0x0000356F 733000000A         */ IL_0167: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000030 */
		/* 0x00003574 283100000A         */ IL_016c: call void [PresentationCore]System.Windows.EventManager::RegisterClassHandler(class [mscorlib]System.Type, class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000031 */
		/* 0x00003579 2A                 */ IL_0171: ret
	} // end of method OptionButton::.cctor

	.method /* 0600008B */ family hidebysig newslot virtual 
		instance void OnClick () cil managed 
	{
		// Method begins at RVA 0x3586
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003586 02                 */ IL_0000: ldarg.0
		/* 0x00003587 7E36000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickEvent /* 04000036 */
		/* 0x0000358C 02                 */ IL_0006: ldarg.0
		/* 0x0000358D 737000000A         */ IL_0007: newobj instance void [PresentationCore]System.Windows.RoutedEventArgs::.ctor(class [PresentationCore]System.Windows.RoutedEvent, object) /* 0A000070 */
		/* 0x00003592 283300000A         */ IL_000c: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x00003597 2A                 */ IL_0011: ret
	} // end of method OptionButton::OnClick

	.method /* 0600008C */ private hidebysig static 
		void Button_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3599
		// Header size: 1
		// Code size: 38 (0x26)
		.maxstack 8

		/* 0x00003599 02                 */ IL_0000: ldarg.0
		/* 0x0000359A 750E000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000359F 25                 */ IL_0006: dup
		/* 0x000035A0 6F86000006         */ IL_0007: callvirt instance valuetype [PresentationFramework]System.Windows.Controls.ClickMode AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::get_ClickMode() /* 06000086 */
		/* 0x000035A5 17                 */ IL_000c: ldc.i4.1
		/* 0x000035A6 3311               */ IL_000d: bne.un.s IL_0020
		/* 0x000035A8 287100000A         */ IL_000f: call class [PresentationCore]System.Windows.IInputElement [PresentationCore]System.Windows.Input.Mouse::get_Captured() /* 0A000071 */
		/* 0x000035AD 2C0A               */ IL_0014: brfalse.s IL_0020
		/* 0x000035AF 287100000A         */ IL_0016: call class [PresentationCore]System.Windows.IInputElement [PresentationCore]System.Windows.Input.Mouse::get_Captured() /* 0A000071 */
		/* 0x000035B4 6F7200000A         */ IL_001b: callvirt instance void [PresentationCore]System.Windows.IInputElement::ReleaseMouseCapture() /* 0A000072 */
		/* 0x000035B9 6F8B000006         */ IL_0020: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::OnClick() /* 0600008B */
		/* 0x000035BE 2A                 */ IL_0025: ret
	} // end of method OptionButton::Button_Click

	.method /* 0600008D */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x35c0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000035C0 02                 */ IL_0000: ldarg.0
		/* 0x000035C1 287300000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.ContentControl::.ctor() /* 0A000073 */
		/* 0x000035C6 2A                 */ IL_0006: ret
	} // end of method OptionButton::.ctor

	// Events
	.event /* 14000005 */ [PresentationCore]System.Windows.RoutedEventHandler Click
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::remove_Click(class [PresentationCore]System.Windows.RoutedEventHandler)
	}


	// Properties
	.property /* 17000029 */ instance bool IsChecked()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::get_IsChecked()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::set_IsChecked(bool)
	}
	.property /* 1700002A */ instance class [PresentationCore]System.Windows.Media.Brush CheckedBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::get_CheckedBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::set_CheckedBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 1700002B */ instance valuetype [PresentationFramework]System.Windows.Controls.ClickMode ClickMode()
	{
		.get instance valuetype [PresentationFramework]System.Windows.Controls.ClickMode AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::get_ClickMode()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::set_ClickMode(valuetype [PresentationFramework]System.Windows.Controls.ClickMode)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton

.class /* 0200000F */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton
	extends [PresentationFramework]System.Windows.Controls.Primitives.Selector
{
	.custom /* 0C000020 */ instance void [PresentationFramework]System.Windows.TemplatePartAttribute::.ctor() = (
		01 00 02 00 54 0e 04 4e 61 6d 65 0a 50 41 52 54
		5f 50 6f 70 75 70 54 50 04 54 79 70 65 80 82 53
		79 73 74 65 6d 2e 57 69 6e 64 6f 77 73 2e 43 6f
		6e 74 72 6f 6c 73 2e 50 72 69 6d 69 74 69 76 65
		73 2e 50 6f 70 75 70 2c 20 50 72 65 73 65 6e 74
		61 74 69 6f 6e 46 72 61 6d 65 77 6f 72 6b 2c 20
		56 65 72 73 69 6f 6e 3d 34 2e 30 2e 30 2e 30 2c
		20 43 75 6c 74 75 72 65 3d 6e 65 75 74 72 61 6c
		2c 20 50 75 62 6c 69 63 4b 65 79 54 6f 6b 65 6e
		3d 33 31 62 66 33 38 35 36 61 64 33 36 34 65 33 35
	)
	.custom /* 0C000021 */ instance void [PresentationFramework]System.Windows.TemplatePartAttribute::.ctor() = (
		01 00 02 00 54 0e 04 4e 61 6d 65 0d 50 41 52 54
		5f 45 78 70 61 6e 64 65 72 54 50 04 54 79 70 65
		7a 53 79 73 74 65 6d 2e 57 69 6e 64 6f 77 73 2e
		43 6f 6e 74 72 6f 6c 73 2e 45 78 70 61 6e 64 65
		72 2c 20 50 72 65 73 65 6e 74 61 74 69 6f 6e 46
		72 61 6d 65 77 6f 72 6b 2c 20 56 65 72 73 69 6f
		6e 3d 34 2e 30 2e 30 2e 30 2c 20 43 75 6c 74 75
		72 65 3d 6e 65 75 74 72 61 6c 2c 20 50 75 62 6c
		69 63 4b 65 79 54 6f 6b 65 6e 3d 33 31 62 66 33
		38 35 36 61 64 33 36 34 65 33 35
	)
	// Fields
	.field /* 04000037 */ private static literal string PART_Expander = "PART_Expander"
	.field /* 04000038 */ private static literal string PART_Popup = "PART_Popup"
	.field /* 04000039 */ private static literal int32 DragValidLength = int32(10)
	.field /* 0400003A */ private class [PresentationFramework]System.Windows.Controls.Primitives.Popup _templatedPopup
	.field /* 0400003B */ private class [PresentationFramework]System.Windows.Controls.Expander _templatedExpander
	.field /* 0400003C */ public static initonly class [WindowsBase]System.Windows.DependencyProperty IsCheckedProperty
	.field /* 0400003D */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ItemControlTemplateProperty
	.field /* 0400003E */ public static initonly class [WindowsBase]System.Windows.DependencyProperty SelectedItemControlTemplateProperty
	.field /* 0400003F */ public static initonly class [WindowsBase]System.Windows.DependencyProperty DefaultButtonBackgroundProperty
	.field /* 04000040 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CheckedButtonBackgroundProperty
	.field /* 04000041 */ public static initonly class [PresentationCore]System.Windows.RoutedEvent ClickEvent
	.field /* 04000042 */ public static initonly class [PresentationCore]System.Windows.RoutedEvent PopupOpenedEvent
	.field /* 04000043 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ButtonSizeProperty

	// Methods
	.method /* 0600008E */ public hidebysig specialname 
		instance bool get_IsChecked () cil managed 
	{
		// Method begins at RVA 0x35c8
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000035C8 02                 */ IL_0000: ldarg.0
		/* 0x000035C9 7E3C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::IsCheckedProperty /* 0400003C */
		/* 0x000035CE 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000035D3 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x000035D8 2A                 */ IL_0010: ret
	} // end of method DropdownButton::get_IsChecked

	.method /* 0600008F */ public hidebysig specialname 
		instance void set_IsChecked (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x35da
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000035DA 02                 */ IL_0000: ldarg.0
		/* 0x000035DB 7E3C000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::IsCheckedProperty /* 0400003C */
		/* 0x000035E0 03                 */ IL_0006: ldarg.1
		/* 0x000035E1 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x000035E6 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000035EB 2A                 */ IL_0011: ret
	} // end of method DropdownButton::set_IsChecked

	.method /* 06000090 */ public hidebysig specialname 
		instance class [PresentationFramework]System.Windows.Controls.ControlTemplate get_ItemControlTemplate () cil managed 
	{
		// Method begins at RVA 0x35ed
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000035ED 02                 */ IL_0000: ldarg.0
		/* 0x000035EE 7E3D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ItemControlTemplateProperty /* 0400003D */
		/* 0x000035F3 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000035F8 743B000001         */ IL_000b: castclass [PresentationFramework]System.Windows.Controls.ControlTemplate /* 0100003B */
		/* 0x000035FD 2A                 */ IL_0010: ret
	} // end of method DropdownButton::get_ItemControlTemplate

	.method /* 06000091 */ public hidebysig specialname 
		instance void set_ItemControlTemplate (
			class [PresentationFramework]System.Windows.Controls.ControlTemplate 'value'
		) cil managed 
	{
		// Method begins at RVA 0x35ff
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000035FF 02                 */ IL_0000: ldarg.0
		/* 0x00003600 7E3D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ItemControlTemplateProperty /* 0400003D */
		/* 0x00003605 03                 */ IL_0006: ldarg.1
		/* 0x00003606 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000360B 2A                 */ IL_000c: ret
	} // end of method DropdownButton::set_ItemControlTemplate

	.method /* 06000092 */ public hidebysig specialname 
		instance class [PresentationFramework]System.Windows.Controls.ControlTemplate get_SelectedItemControlTemplate () cil managed 
	{
		// Method begins at RVA 0x360d
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000360D 02                 */ IL_0000: ldarg.0
		/* 0x0000360E 7E3E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::SelectedItemControlTemplateProperty /* 0400003E */
		/* 0x00003613 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003618 743B000001         */ IL_000b: castclass [PresentationFramework]System.Windows.Controls.ControlTemplate /* 0100003B */
		/* 0x0000361D 2A                 */ IL_0010: ret
	} // end of method DropdownButton::get_SelectedItemControlTemplate

	.method /* 06000093 */ public hidebysig specialname 
		instance void set_SelectedItemControlTemplate (
			class [PresentationFramework]System.Windows.Controls.ControlTemplate 'value'
		) cil managed 
	{
		// Method begins at RVA 0x361f
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000361F 02                 */ IL_0000: ldarg.0
		/* 0x00003620 7E3E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::SelectedItemControlTemplateProperty /* 0400003E */
		/* 0x00003625 03                 */ IL_0006: ldarg.1
		/* 0x00003626 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000362B 2A                 */ IL_000c: ret
	} // end of method DropdownButton::set_SelectedItemControlTemplate

	.method /* 06000094 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_DefaultButtonBackground () cil managed 
	{
		// Method begins at RVA 0x362d
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000362D 02                 */ IL_0000: ldarg.0
		/* 0x0000362E 7E3F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::DefaultButtonBackgroundProperty /* 0400003F */
		/* 0x00003633 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003638 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x0000363D 2A                 */ IL_0010: ret
	} // end of method DropdownButton::get_DefaultButtonBackground

	.method /* 06000095 */ public hidebysig specialname 
		instance void set_DefaultButtonBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x363f
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000363F 02                 */ IL_0000: ldarg.0
		/* 0x00003640 7E3F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::DefaultButtonBackgroundProperty /* 0400003F */
		/* 0x00003645 03                 */ IL_0006: ldarg.1
		/* 0x00003646 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000364B 2A                 */ IL_000c: ret
	} // end of method DropdownButton::set_DefaultButtonBackground

	.method /* 06000096 */ public hidebysig specialname 
		instance class [PresentationCore]System.Windows.Media.Brush get_CheckedButtonBackground () cil managed 
	{
		// Method begins at RVA 0x364d
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000364D 02                 */ IL_0000: ldarg.0
		/* 0x0000364E 7E40000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::CheckedButtonBackgroundProperty /* 04000040 */
		/* 0x00003653 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003658 7426000001         */ IL_000b: castclass [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x0000365D 2A                 */ IL_0010: ret
	} // end of method DropdownButton::get_CheckedButtonBackground

	.method /* 06000097 */ public hidebysig specialname 
		instance void set_CheckedButtonBackground (
			class [PresentationCore]System.Windows.Media.Brush 'value'
		) cil managed 
	{
		// Method begins at RVA 0x365f
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000365F 02                 */ IL_0000: ldarg.0
		/* 0x00003660 7E40000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::CheckedButtonBackgroundProperty /* 04000040 */
		/* 0x00003665 03                 */ IL_0006: ldarg.1
		/* 0x00003666 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000366B 2A                 */ IL_000c: ret
	} // end of method DropdownButton::set_CheckedButtonBackground

	.method /* 06000098 */ public hidebysig specialname 
		instance float64 get_ButtonSize () cil managed 
	{
		// Method begins at RVA 0x366d
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000366D 02                 */ IL_0000: ldarg.0
		/* 0x0000366E 7E43000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ButtonSizeProperty /* 04000043 */
		/* 0x00003673 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003678 A56D000001         */ IL_000b: unbox.any [mscorlib]System.Double /* 0100006D */
		/* 0x0000367D 2A                 */ IL_0010: ret
	} // end of method DropdownButton::get_ButtonSize

	.method /* 06000099 */ public hidebysig specialname 
		instance void set_ButtonSize (
			float64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x367f
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x0000367F 02                 */ IL_0000: ldarg.0
		/* 0x00003680 7E43000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ButtonSizeProperty /* 04000043 */
		/* 0x00003685 03                 */ IL_0006: ldarg.1
		/* 0x00003686 8C6D000001         */ IL_0007: box [mscorlib]System.Double /* 0100006D */
		/* 0x0000368B 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00003690 2A                 */ IL_0011: ret
	} // end of method DropdownButton::set_ButtonSize

	.method /* 0600009A */ public hidebysig specialname 
		instance void add_Click (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3692
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003692 02                 */ IL_0000: ldarg.0
		/* 0x00003693 7E41000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ClickEvent /* 04000041 */
		/* 0x00003698 03                 */ IL_0006: ldarg.1
		/* 0x00003699 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x0000369E 2A                 */ IL_000c: ret
	} // end of method DropdownButton::add_Click

	.method /* 0600009B */ public hidebysig specialname 
		instance void remove_Click (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x36a0
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000036A0 02                 */ IL_0000: ldarg.0
		/* 0x000036A1 7E41000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ClickEvent /* 04000041 */
		/* 0x000036A6 03                 */ IL_0006: ldarg.1
		/* 0x000036A7 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000036AC 2A                 */ IL_000c: ret
	} // end of method DropdownButton::remove_Click

	.method /* 0600009C */ public hidebysig specialname 
		instance void add_PopupOpened (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x36ae
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000036AE 02                 */ IL_0000: ldarg.0
		/* 0x000036AF 7E42000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::PopupOpenedEvent /* 04000042 */
		/* 0x000036B4 03                 */ IL_0006: ldarg.1
		/* 0x000036B5 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x000036BA 2A                 */ IL_000c: ret
	} // end of method DropdownButton::add_PopupOpened

	.method /* 0600009D */ public hidebysig specialname 
		instance void remove_PopupOpened (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x36bc
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x000036BC 02                 */ IL_0000: ldarg.0
		/* 0x000036BD 7E42000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::PopupOpenedEvent /* 04000042 */
		/* 0x000036C2 03                 */ IL_0006: ldarg.1
		/* 0x000036C3 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x000036C8 2A                 */ IL_000c: ret
	} // end of method DropdownButton::remove_PopupOpened

	.method /* 0600009E */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x36cc
		// Header size: 12
		// Code size: 389 (0x185)
		.maxstack 4

		/* 0x000036CC 724F030070         */ IL_0000: ldstr "IsChecked" /* 7000034F */
		/* 0x000036D1 D05F000001         */ IL_0005: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x000036D6 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000036DB D00F000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x000036E0 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000036E5 282700000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x000036EA 803C000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::IsCheckedProperty /* 0400003C */
		/* 0x000036EF 7283050070         */ IL_0023: ldstr "ItemControlTemplate" /* 70000583 */
		/* 0x000036F4 D03B000001         */ IL_0028: ldtoken [PresentationFramework]System.Windows.Controls.ControlTemplate /* 0100003B */
		/* 0x000036F9 282400000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000036FE D00F000002         */ IL_0032: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003703 282400000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003708 282700000A         */ IL_003c: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x0000370D 803D000004         */ IL_0041: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ItemControlTemplateProperty /* 0400003D */
		/* 0x00003712 72AB050070         */ IL_0046: ldstr "SelectedItemControlTemplate" /* 700005AB */
		/* 0x00003717 D03B000001         */ IL_004b: ldtoken [PresentationFramework]System.Windows.Controls.ControlTemplate /* 0100003B */
		/* 0x0000371C 282400000A         */ IL_0050: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003721 D00F000002         */ IL_0055: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003726 282400000A         */ IL_005a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000372B 282700000A         */ IL_005f: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x00003730 803E000004         */ IL_0064: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::SelectedItemControlTemplateProperty /* 0400003E */
		/* 0x00003735 7291000070         */ IL_0069: ldstr "DefaultButtonBackground" /* 70000091 */
		/* 0x0000373A D026000001         */ IL_006e: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x0000373F 282400000A         */ IL_0073: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003744 D00F000002         */ IL_0078: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003749 282400000A         */ IL_007d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000374E 282B00000A         */ IL_0082: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_LightGray() /* 0A00002B */
		/* 0x00003753 732500000A         */ IL_0087: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003758 282600000A         */ IL_008c: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x0000375D 803F000004         */ IL_0091: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::DefaultButtonBackgroundProperty /* 0400003F */
		/* 0x00003762 72C1000070         */ IL_0096: ldstr "CheckedButtonBackground" /* 700000C1 */
		/* 0x00003767 D026000001         */ IL_009b: ldtoken [PresentationCore]System.Windows.Media.Brush /* 01000026 */
		/* 0x0000376C 282400000A         */ IL_00a0: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003771 D00F000002         */ IL_00a5: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003776 282400000A         */ IL_00aa: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000377B 282C00000A         */ IL_00af: call class [PresentationCore]System.Windows.Media.SolidColorBrush [PresentationCore]System.Windows.Media.Brushes::get_White() /* 0A00002C */
		/* 0x00003780 732500000A         */ IL_00b4: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003785 282600000A         */ IL_00b9: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x0000378A 8040000004         */ IL_00be: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::CheckedButtonBackgroundProperty /* 04000040 */
		/* 0x0000378F 7277050070         */ IL_00c3: ldstr "Click" /* 70000577 */
		/* 0x00003794 17                 */ IL_00c8: ldc.i4.1
		/* 0x00003795 D036000001         */ IL_00c9: ldtoken [PresentationCore]System.Windows.RoutedEventHandler /* 01000036 */
		/* 0x0000379A 282400000A         */ IL_00ce: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000379F D00F000002         */ IL_00d3: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x000037A4 282400000A         */ IL_00d8: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000037A9 282D00000A         */ IL_00dd: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x000037AE 8041000004         */ IL_00e2: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ClickEvent /* 04000041 */
		/* 0x000037B3 72E3050070         */ IL_00e7: ldstr "PopupOpened" /* 700005E3 */
		/* 0x000037B8 17                 */ IL_00ec: ldc.i4.1
		/* 0x000037B9 D036000001         */ IL_00ed: ldtoken [PresentationCore]System.Windows.RoutedEventHandler /* 01000036 */
		/* 0x000037BE 282400000A         */ IL_00f2: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000037C3 D00F000002         */ IL_00f7: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x000037C8 282400000A         */ IL_00fc: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000037CD 282D00000A         */ IL_0101: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x000037D2 8042000004         */ IL_0106: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::PopupOpenedEvent /* 04000042 */
		/* 0x000037D7 727B000070         */ IL_010b: ldstr "ButtonSize" /* 7000007B */
		/* 0x000037DC D06D000001         */ IL_0110: ldtoken [mscorlib]System.Double /* 0100006D */
		/* 0x000037E1 282400000A         */ IL_0115: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000037E6 D00F000002         */ IL_011a: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x000037EB 282400000A         */ IL_011f: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000037F0 230000000000805140 */ IL_0124: ldc.r8 70
		/* 0x000037F9 8C6D000001         */ IL_012d: box [mscorlib]System.Double /* 0100006D */
		/* 0x000037FE 737400000A         */ IL_0132: newobj instance void [PresentationCore]System.Windows.UIPropertyMetadata::.ctor(object) /* 0A000074 */
		/* 0x00003803 282600000A         */ IL_0137: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00003808 8043000004         */ IL_013c: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ButtonSizeProperty /* 04000043 */
		/* 0x0000380D 7E2E00000A         */ IL_0141: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x00003812 D00F000002         */ IL_0146: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003817 282400000A         */ IL_014b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000381C D00F000002         */ IL_0150: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003821 282400000A         */ IL_0155: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003826 732500000A         */ IL_015a: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000382B 6F2F00000A         */ IL_015f: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x00003830 D00F000002         */ IL_0164: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003835 282400000A         */ IL_0169: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000383A 7E36000004         */ IL_016e: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton::ClickEvent /* 04000036 */
		/* 0x0000383F 14                 */ IL_0173: ldnull
		/* 0x00003840 FE06A4000006       */ IL_0174: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::OptionButton_Click(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000A4 */
		/* 0x00003846 733000000A         */ IL_017a: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000030 */
		/* 0x0000384B 283100000A         */ IL_017f: call void [PresentationCore]System.Windows.EventManager::RegisterClassHandler(class [mscorlib]System.Type, class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000031 */
		/* 0x00003850 2A                 */ IL_0184: ret
	} // end of method DropdownButton::.cctor

	.method /* 0600009F */ public hidebysig virtual 
		instance void OnApplyTemplate () cil managed 
	{
		// Method begins at RVA 0x3860
		// Header size: 12
		// Code size: 105 (0x69)
		.maxstack 3

		/* 0x00003860 02                 */ IL_0000: ldarg.0
		/* 0x00003861 02                 */ IL_0001: ldarg.0
		/* 0x00003862 72FB050070         */ IL_0002: ldstr "PART_Popup" /* 700005FB */
		/* 0x00003867 285400000A         */ IL_0007: call instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::GetTemplateChild(string) /* 0A000054 */
		/* 0x0000386C 7538000001         */ IL_000c: isinst [PresentationFramework]System.Windows.Controls.Primitives.Popup /* 01000038 */
		/* 0x00003871 7D3A000004         */ IL_0011: stfld class [PresentationFramework]System.Windows.Controls.Primitives.Popup AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup /* 0400003A */
		/* 0x00003876 02                 */ IL_0016: ldarg.0
		/* 0x00003877 7B3A000004         */ IL_0017: ldfld class [PresentationFramework]System.Windows.Controls.Primitives.Popup AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup /* 0400003A */
		/* 0x0000387C 2C2E               */ IL_001c: brfalse.s IL_004c
		/* 0x0000387E 02                 */ IL_001e: ldarg.0
		/* 0x0000387F 7B3A000004         */ IL_001f: ldfld class [PresentationFramework]System.Windows.Controls.Primitives.Popup AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup /* 0400003A */
		/* 0x00003884 02                 */ IL_0024: ldarg.0
		/* 0x00003885 FE06A0000006       */ IL_0025: ldftn instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup_Opened(object, class [mscorlib]System.EventArgs) /* 060000A0 */
		/* 0x0000388B 737500000A         */ IL_002b: newobj instance void [mscorlib]System.EventHandler::.ctor(object, native int) /* 0A000075 */
		/* 0x00003890 6F7600000A         */ IL_0030: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Popup::add_Opened(class [mscorlib]System.EventHandler) /* 0A000076 */
		/* 0x00003895 02                 */ IL_0035: ldarg.0
		/* 0x00003896 7B3A000004         */ IL_0036: ldfld class [PresentationFramework]System.Windows.Controls.Primitives.Popup AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup /* 0400003A */
		/* 0x0000389B 02                 */ IL_003b: ldarg.0
		/* 0x0000389C FE06A1000006       */ IL_003c: ldftn instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup_Closed(object, class [mscorlib]System.EventArgs) /* 060000A1 */
		/* 0x000038A2 737500000A         */ IL_0042: newobj instance void [mscorlib]System.EventHandler::.ctor(object, native int) /* 0A000075 */
		/* 0x000038A7 6F7700000A         */ IL_0047: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Popup::add_Closed(class [mscorlib]System.EventHandler) /* 0A000077 */
		/* 0x000038AC 02                 */ IL_004c: ldarg.0
		/* 0x000038AD 02                 */ IL_004d: ldarg.0
		/* 0x000038AE 7211060070         */ IL_004e: ldstr "PART_Expander" /* 70000611 */
		/* 0x000038B3 285400000A         */ IL_0053: call instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::GetTemplateChild(string) /* 0A000054 */
		/* 0x000038B8 7539000001         */ IL_0058: isinst [PresentationFramework]System.Windows.Controls.Expander /* 01000039 */
		/* 0x000038BD 7D3B000004         */ IL_005d: stfld class [PresentationFramework]System.Windows.Controls.Expander AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedExpander /* 0400003B */
		/* 0x000038C2 02                 */ IL_0062: ldarg.0
		/* 0x000038C3 285500000A         */ IL_0063: call instance void [PresentationFramework]System.Windows.FrameworkElement::OnApplyTemplate() /* 0A000055 */
		/* 0x000038C8 2A                 */ IL_0068: ret
	} // end of method DropdownButton::OnApplyTemplate

	.method /* 060000A0 */ private hidebysig 
		instance void _templatedPopup_Opened (
			object sender,
			class [mscorlib]System.EventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x38d5
		// Header size: 1
		// Code size: 27 (0x1b)
		.maxstack 8

		/* 0x000038D5 02                 */ IL_0000: ldarg.0
		/* 0x000038D6 6FA3000006         */ IL_0001: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::OnPopupOpened() /* 060000A3 */
		/* 0x000038DB 02                 */ IL_0006: ldarg.0
		/* 0x000038DC 7B3B000004         */ IL_0007: ldfld class [PresentationFramework]System.Windows.Controls.Expander AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedExpander /* 0400003B */
		/* 0x000038E1 2C0C               */ IL_000c: brfalse.s IL_001a
		/* 0x000038E3 02                 */ IL_000e: ldarg.0
		/* 0x000038E4 7B3B000004         */ IL_000f: ldfld class [PresentationFramework]System.Windows.Controls.Expander AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedExpander /* 0400003B */
		/* 0x000038E9 16                 */ IL_0014: ldc.i4.0
		/* 0x000038EA 6F7800000A         */ IL_0015: callvirt instance void [PresentationCore]System.Windows.UIElement::set_IsHitTestVisible(bool) /* 0A000078 */
		/* 0x000038EF 2A                 */ IL_001a: ret
	} // end of method DropdownButton::_templatedPopup_Opened

	.method /* 060000A1 */ private hidebysig 
		instance void _templatedPopup_Closed (
			object sender,
			class [mscorlib]System.EventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x38f1
		// Header size: 1
		// Code size: 39 (0x27)
		.maxstack 8

		/* 0x000038F1 02                 */ IL_0000: ldarg.0
		/* 0x000038F2 7B3B000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.Expander AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedExpander /* 0400003B */
		/* 0x000038F7 2C1E               */ IL_0006: brfalse.s IL_0026
		/* 0x000038F9 02                 */ IL_0008: ldarg.0
		/* 0x000038FA 287900000A         */ IL_0009: call instance class [WindowsBase]System.Windows.Threading.Dispatcher [WindowsBase]System.Windows.Threading.DispatcherObject::get_Dispatcher() /* 0A000079 */
		/* 0x000038FF 02                 */ IL_000e: ldarg.0
		/* 0x00003900 FE06A6000006       */ IL_000f: ldftn instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::'<_templatedPopup_Closed>b__40_0'() /* 060000A6 */
		/* 0x00003906 737A00000A         */ IL_0015: newobj instance void [mscorlib]System.Action::.ctor(object, native int) /* 0A00007A */
		/* 0x0000390B 1C                 */ IL_001a: ldc.i4.6
		/* 0x0000390C 280300002B         */ IL_001b: call !!0[] [mscorlib]System.Array::Empty<object>() /* 2B000003 */
		/* 0x00003911 6F7C00000A         */ IL_0020: callvirt instance class [WindowsBase]System.Windows.Threading.DispatcherOperation [WindowsBase]System.Windows.Threading.Dispatcher::BeginInvoke(class [mscorlib]System.Delegate, valuetype [WindowsBase]System.Windows.Threading.DispatcherPriority, object[]) /* 0A00007C */
		/* 0x00003916 26                 */ IL_0025: pop
		/* 0x00003917 2A                 */ IL_0026: ret
	} // end of method DropdownButton::_templatedPopup_Closed

	.method /* 060000A2 */ family hidebysig newslot virtual 
		instance void OnClick () cil managed 
	{
		// Method begins at RVA 0x3919
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003919 02                 */ IL_0000: ldarg.0
		/* 0x0000391A 7E41000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::ClickEvent /* 04000041 */
		/* 0x0000391F 02                 */ IL_0006: ldarg.0
		/* 0x00003920 737000000A         */ IL_0007: newobj instance void [PresentationCore]System.Windows.RoutedEventArgs::.ctor(class [PresentationCore]System.Windows.RoutedEvent, object) /* 0A000070 */
		/* 0x00003925 283300000A         */ IL_000c: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x0000392A 2A                 */ IL_0011: ret
	} // end of method DropdownButton::OnClick

	.method /* 060000A3 */ family hidebysig newslot virtual 
		instance void OnPopupOpened () cil managed 
	{
		// Method begins at RVA 0x392c
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x0000392C 02                 */ IL_0000: ldarg.0
		/* 0x0000392D 7E42000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::PopupOpenedEvent /* 04000042 */
		/* 0x00003932 02                 */ IL_0006: ldarg.0
		/* 0x00003933 737000000A         */ IL_0007: newobj instance void [PresentationCore]System.Windows.RoutedEventArgs::.ctor(class [PresentationCore]System.Windows.RoutedEvent, object) /* 0A000070 */
		/* 0x00003938 283300000A         */ IL_000c: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x0000393D 2A                 */ IL_0011: ret
	} // end of method DropdownButton::OnPopupOpened

	.method /* 060000A4 */ private hidebysig static 
		void OptionButton_Click (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3940
		// Header size: 12
		// Code size: 58 (0x3a)
		.maxstack 2
		.locals /* 1100000C */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton,
			[1] class AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton
		)

		/* 0x00003940 03                 */ IL_0000: ldarg.1
		/* 0x00003941 6F3500000A         */ IL_0001: callvirt instance object [PresentationCore]System.Windows.RoutedEventArgs::get_OriginalSource() /* 0A000035 */
		/* 0x00003946 750E000002         */ IL_0006: isinst AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x0000394B 0A                 */ IL_000b: stloc.0
		/* 0x0000394C 02                 */ IL_000c: ldarg.0
		/* 0x0000394D 750F000002         */ IL_000d: isinst AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton /* 0200000F */
		/* 0x00003952 0B                 */ IL_0012: stloc.1
		/* 0x00003953 07                 */ IL_0013: ldloc.1
		/* 0x00003954 06                 */ IL_0014: ldloc.0
		/* 0x00003955 6F7D00000A         */ IL_0015: callvirt instance object [PresentationFramework]System.Windows.FrameworkElement::get_Tag() /* 0A00007D */
		/* 0x0000395A 6F7E00000A         */ IL_001a: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Selector::set_SelectedItem(object) /* 0A00007E */
		/* 0x0000395F 07                 */ IL_001f: ldloc.1
		/* 0x00003960 6FA2000006         */ IL_0020: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::OnClick() /* 060000A2 */
		/* 0x00003965 07                 */ IL_0025: ldloc.1
		/* 0x00003966 7B3A000004         */ IL_0026: ldfld class [PresentationFramework]System.Windows.Controls.Primitives.Popup AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup /* 0400003A */
		/* 0x0000396B 2C0C               */ IL_002b: brfalse.s IL_0039
		/* 0x0000396D 07                 */ IL_002d: ldloc.1
		/* 0x0000396E 7B3A000004         */ IL_002e: ldfld class [PresentationFramework]System.Windows.Controls.Primitives.Popup AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedPopup /* 0400003A */
		/* 0x00003973 16                 */ IL_0033: ldc.i4.0
		/* 0x00003974 6F7F00000A         */ IL_0034: callvirt instance void [PresentationFramework]System.Windows.Controls.Primitives.Popup::set_IsOpen(bool) /* 0A00007F */
		/* 0x00003979 2A                 */ IL_0039: ret
	} // end of method DropdownButton::OptionButton_Click

	.method /* 060000A5 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3986
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003986 02                 */ IL_0000: ldarg.0
		/* 0x00003987 288000000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.Primitives.Selector::.ctor() /* 0A000080 */
		/* 0x0000398C 2A                 */ IL_0006: ret
	} // end of method DropdownButton::.ctor

	.method /* 060000A6 */ private hidebysig 
		instance void '<_templatedPopup_Closed>b__40_0' () cil managed 
	{
		.custom /* 0C00004E */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x398e
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000398E 02                 */ IL_0000: ldarg.0
		/* 0x0000398F 7B3B000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.Expander AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::_templatedExpander /* 0400003B */
		/* 0x00003994 17                 */ IL_0006: ldc.i4.1
		/* 0x00003995 6F7800000A         */ IL_0007: callvirt instance void [PresentationCore]System.Windows.UIElement::set_IsHitTestVisible(bool) /* 0A000078 */
		/* 0x0000399A 2A                 */ IL_000c: ret
	} // end of method DropdownButton::'<_templatedPopup_Closed>b__40_0'

	// Events
	.event /* 14000006 */ [PresentationCore]System.Windows.RoutedEventHandler Click
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::add_Click(class [PresentationCore]System.Windows.RoutedEventHandler)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::remove_Click(class [PresentationCore]System.Windows.RoutedEventHandler)
	}

	.event /* 14000007 */ [PresentationCore]System.Windows.RoutedEventHandler PopupOpened
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::add_PopupOpened(class [PresentationCore]System.Windows.RoutedEventHandler)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::remove_PopupOpened(class [PresentationCore]System.Windows.RoutedEventHandler)
	}


	// Properties
	.property /* 1700002C */ instance bool IsChecked()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::get_IsChecked()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::set_IsChecked(bool)
	}
	.property /* 1700002D */ instance class [PresentationFramework]System.Windows.Controls.ControlTemplate ItemControlTemplate()
	{
		.get instance class [PresentationFramework]System.Windows.Controls.ControlTemplate AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::get_ItemControlTemplate()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::set_ItemControlTemplate(class [PresentationFramework]System.Windows.Controls.ControlTemplate)
	}
	.property /* 1700002E */ instance class [PresentationFramework]System.Windows.Controls.ControlTemplate SelectedItemControlTemplate()
	{
		.get instance class [PresentationFramework]System.Windows.Controls.ControlTemplate AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::get_SelectedItemControlTemplate()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::set_SelectedItemControlTemplate(class [PresentationFramework]System.Windows.Controls.ControlTemplate)
	}
	.property /* 1700002F */ instance class [PresentationCore]System.Windows.Media.Brush DefaultButtonBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::get_DefaultButtonBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::set_DefaultButtonBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000030 */ instance class [PresentationCore]System.Windows.Media.Brush CheckedButtonBackground()
	{
		.get instance class [PresentationCore]System.Windows.Media.Brush AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::get_CheckedButtonBackground()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::set_CheckedButtonBackground(class [PresentationCore]System.Windows.Media.Brush)
	}
	.property /* 17000031 */ instance float64 ButtonSize()
	{
		.get instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::get_ButtonSize()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton::set_ButtonSize(float64)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.DropdownButton

.class /* 02000010 */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox
	extends [PresentationFramework]System.Windows.Controls.ContentControl
{
	.custom /* 0C000023 */ instance void [PresentationFramework]System.Windows.TemplatePartAttribute::.ctor() = (
		01 00 02 00 54 0e 04 4e 61 6d 65 11 50 41 52 54
		5f 53 63 72 6f 6c 6c 56 69 65 77 65 72 54 50 04
		54 79 70 65 7e 53 79 73 74 65 6d 2e 57 69 6e 64
		6f 77 73 2e 43 6f 6e 74 72 6f 6c 73 2e 53 63 72
		6f 6c 6c 56 69 65 77 65 72 2c 20 50 72 65 73 65
		6e 74 61 74 69 6f 6e 46 72 61 6d 65 77 6f 72 6b
		2c 20 56 65 72 73 69 6f 6e 3d 34 2e 30 2e 30 2e
		30 2c 20 43 75 6c 74 75 72 65 3d 6e 65 75 74 72
		61 6c 2c 20 50 75 62 6c 69 63 4b 65 79 54 6f 6b
		65 6e 3d 33 31 62 66 33 38 35 36 61 64 33 36 34
		65 33 35
	)
	// Fields
	.field /* 04000044 */ private class [PresentationFramework]System.Windows.Controls.ScrollViewer _scrollViewer
	.field /* 04000045 */ private static literal string PART_ScrollViewer = "PART_ScrollViewer"
	.field /* 04000046 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty OrientationProperty
	.field /* 04000047 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty StepSizeProperty
	.field /* 04000048 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ContentOffsetProperty
	.field /* 04000049 */ public static initonly class [PresentationCore]System.Windows.Input.RoutedUICommand MoveLeftCommand
	.field /* 0400004A */ public static initonly class [PresentationCore]System.Windows.Input.RoutedUICommand MoveRightCommand

	// Methods
	.method /* 060000A7 */ public hidebysig specialname 
		instance valuetype [PresentationFramework]System.Windows.Controls.Orientation get_Orientation () cil managed 
	{
		// Method begins at RVA 0x399c
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000399C 02                 */ IL_0000: ldarg.0
		/* 0x0000399D 7E46000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OrientationProperty /* 04000046 */
		/* 0x000039A2 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000039A7 A53F000001         */ IL_000b: unbox.any [PresentationFramework]System.Windows.Controls.Orientation /* 0100003F */
		/* 0x000039AC 2A                 */ IL_0010: ret
	} // end of method SlideBox::get_Orientation

	.method /* 060000A8 */ public hidebysig specialname 
		instance void set_Orientation (
			valuetype [PresentationFramework]System.Windows.Controls.Orientation 'value'
		) cil managed 
	{
		// Method begins at RVA 0x39ae
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000039AE 02                 */ IL_0000: ldarg.0
		/* 0x000039AF 7E46000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OrientationProperty /* 04000046 */
		/* 0x000039B4 03                 */ IL_0006: ldarg.1
		/* 0x000039B5 8C3F000001         */ IL_0007: box [PresentationFramework]System.Windows.Controls.Orientation /* 0100003F */
		/* 0x000039BA 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000039BF 2A                 */ IL_0011: ret
	} // end of method SlideBox::set_Orientation

	.method /* 060000A9 */ public hidebysig specialname 
		instance float64 get_StepSize () cil managed 
	{
		// Method begins at RVA 0x39c1
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000039C1 02                 */ IL_0000: ldarg.0
		/* 0x000039C2 7E47000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::StepSizeProperty /* 04000047 */
		/* 0x000039C7 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000039CC A56D000001         */ IL_000b: unbox.any [mscorlib]System.Double /* 0100006D */
		/* 0x000039D1 2A                 */ IL_0010: ret
	} // end of method SlideBox::get_StepSize

	.method /* 060000AA */ public hidebysig specialname 
		instance void set_StepSize (
			float64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x39d3
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000039D3 02                 */ IL_0000: ldarg.0
		/* 0x000039D4 7E47000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::StepSizeProperty /* 04000047 */
		/* 0x000039D9 03                 */ IL_0006: ldarg.1
		/* 0x000039DA 8C6D000001         */ IL_0007: box [mscorlib]System.Double /* 0100006D */
		/* 0x000039DF 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000039E4 2A                 */ IL_0011: ret
	} // end of method SlideBox::set_StepSize

	.method /* 060000AB */ public hidebysig specialname 
		instance float64 get_ContentOffset () cil managed 
	{
		// Method begins at RVA 0x39e6
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000039E6 02                 */ IL_0000: ldarg.0
		/* 0x000039E7 7E48000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ContentOffsetProperty /* 04000048 */
		/* 0x000039EC 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000039F1 A56D000001         */ IL_000b: unbox.any [mscorlib]System.Double /* 0100006D */
		/* 0x000039F6 2A                 */ IL_0010: ret
	} // end of method SlideBox::get_ContentOffset

	.method /* 060000AC */ public hidebysig specialname 
		instance void set_ContentOffset (
			float64 'value'
		) cil managed 
	{
		// Method begins at RVA 0x39f8
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000039F8 02                 */ IL_0000: ldarg.0
		/* 0x000039F9 7E48000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ContentOffsetProperty /* 04000048 */
		/* 0x000039FE 03                 */ IL_0006: ldarg.1
		/* 0x000039FF 8C6D000001         */ IL_0007: box [mscorlib]System.Double /* 0100006D */
		/* 0x00003A04 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00003A09 2A                 */ IL_0011: ret
	} // end of method SlideBox::set_ContentOffset

	.method /* 060000AD */ public hidebysig specialname newslot virtual 
		instance bool get_CanMoveLeft () cil managed 
	{
		// Method begins at RVA 0x3a0c
		// Header size: 12
		// Code size: 64 (0x40)
		.maxstack 2

		/* 0x00003A0C 02                 */ IL_0000: ldarg.0
		/* 0x00003A0D 7B44000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A12 2C36               */ IL_0006: brfalse.s IL_003e
		/* 0x00003A14 02                 */ IL_0008: ldarg.0
		/* 0x00003A15 28A7000006         */ IL_0009: call instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation() /* 060000A7 */
		/* 0x00003A1A 2D17               */ IL_000e: brtrue.s IL_0027
		/* 0x00003A1C 02                 */ IL_0010: ldarg.0
		/* 0x00003A1D 7B44000004         */ IL_0011: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A22 6F8100000A         */ IL_0016: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_HorizontalOffset() /* 0A000081 */
		/* 0x00003A27 230000000000000000 */ IL_001b: ldc.r8 0.0
		/* 0x00003A30 FE02               */ IL_0024: cgt
		/* 0x00003A32 2A                 */ IL_0026: ret
		/* 0x00003A33 02                 */ IL_0027: ldarg.0
		/* 0x00003A34 7B44000004         */ IL_0028: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A39 6F8200000A         */ IL_002d: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_VerticalOffset() /* 0A000082 */
		/* 0x00003A3E 230000000000000000 */ IL_0032: ldc.r8 0.0
		/* 0x00003A47 FE02               */ IL_003b: cgt
		/* 0x00003A49 2A                 */ IL_003d: ret
		/* 0x00003A4A 16                 */ IL_003e: ldc.i4.0
		/* 0x00003A4B 2A                 */ IL_003f: ret
	} // end of method SlideBox::get_CanMoveLeft

	.method /* 060000AE */ public hidebysig specialname newslot virtual 
		instance bool get_CanMoveRight () cil managed 
	{
		// Method begins at RVA 0x3a58
		// Header size: 12
		// Code size: 68 (0x44)
		.maxstack 2

		/* 0x00003A58 02                 */ IL_0000: ldarg.0
		/* 0x00003A59 7B44000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A5E 2C3A               */ IL_0006: brfalse.s IL_0042
		/* 0x00003A60 02                 */ IL_0008: ldarg.0
		/* 0x00003A61 28A7000006         */ IL_0009: call instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation() /* 060000A7 */
		/* 0x00003A66 2D19               */ IL_000e: brtrue.s IL_0029
		/* 0x00003A68 02                 */ IL_0010: ldarg.0
		/* 0x00003A69 7B44000004         */ IL_0011: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A6E 6F8300000A         */ IL_0016: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_ScrollableWidth() /* 0A000083 */
		/* 0x00003A73 02                 */ IL_001b: ldarg.0
		/* 0x00003A74 7B44000004         */ IL_001c: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A79 6F8100000A         */ IL_0021: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_HorizontalOffset() /* 0A000081 */
		/* 0x00003A7E FE02               */ IL_0026: cgt
		/* 0x00003A80 2A                 */ IL_0028: ret
		/* 0x00003A81 02                 */ IL_0029: ldarg.0
		/* 0x00003A82 7B44000004         */ IL_002a: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A87 6F8400000A         */ IL_002f: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_ScrollableHeight() /* 0A000084 */
		/* 0x00003A8C 02                 */ IL_0034: ldarg.0
		/* 0x00003A8D 7B44000004         */ IL_0035: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003A92 6F8200000A         */ IL_003a: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_VerticalOffset() /* 0A000082 */
		/* 0x00003A97 FE02               */ IL_003f: cgt
		/* 0x00003A99 2A                 */ IL_0041: ret
		/* 0x00003A9A 16                 */ IL_0042: ldc.i4.0
		/* 0x00003A9B 2A                 */ IL_0043: ret
	} // end of method SlideBox::get_CanMoveRight

	.method /* 060000AF */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x3aa8
		// Header size: 12
		// Code size: 360 (0x168)
		.maxstack 6

		/* 0x00003AA8 722D060070         */ IL_0000: ldstr "Orientation" /* 7000062D */
		/* 0x00003AAD D03F000001         */ IL_0005: ldtoken [PresentationFramework]System.Windows.Controls.Orientation /* 0100003F */
		/* 0x00003AB2 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003AB7 D010000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003ABC 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003AC1 16                 */ IL_0019: ldc.i4.0
		/* 0x00003AC2 8C3F000001         */ IL_001a: box [PresentationFramework]System.Windows.Controls.Orientation /* 0100003F */
		/* 0x00003AC7 732500000A         */ IL_001f: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003ACC 282600000A         */ IL_0024: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00003AD1 8046000004         */ IL_0029: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OrientationProperty /* 04000046 */
		/* 0x00003AD6 7245060070         */ IL_002e: ldstr "StepSize" /* 70000645 */
		/* 0x00003ADB D06D000001         */ IL_0033: ldtoken [mscorlib]System.Double /* 0100006D */
		/* 0x00003AE0 282400000A         */ IL_0038: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003AE5 D010000002         */ IL_003d: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003AEA 282400000A         */ IL_0042: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003AEF 230000000000805240 */ IL_0047: ldc.r8 74
		/* 0x00003AF8 8C6D000001         */ IL_0050: box [mscorlib]System.Double /* 0100006D */
		/* 0x00003AFD 732500000A         */ IL_0055: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003B02 282600000A         */ IL_005a: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00003B07 8047000004         */ IL_005f: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::StepSizeProperty /* 04000047 */
		/* 0x00003B0C 7257060070         */ IL_0064: ldstr "ContentOffset" /* 70000657 */
		/* 0x00003B11 D06D000001         */ IL_0069: ldtoken [mscorlib]System.Double /* 0100006D */
		/* 0x00003B16 282400000A         */ IL_006e: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003B1B D010000002         */ IL_0073: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003B20 282400000A         */ IL_0078: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003B25 230000000000000000 */ IL_007d: ldc.r8 0.0
		/* 0x00003B2E 8C6D000001         */ IL_0086: box [mscorlib]System.Double /* 0100006D */
		/* 0x00003B33 14                 */ IL_008b: ldnull
		/* 0x00003B34 FE06B9000006       */ IL_008c: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OnContentOffsetPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000B9 */
		/* 0x00003B3A 732800000A         */ IL_0092: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00003B3F 735300000A         */ IL_0097: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000053 */
		/* 0x00003B44 282600000A         */ IL_009c: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00003B49 8048000004         */ IL_00a1: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ContentOffsetProperty /* 04000048 */
		/* 0x00003B4E 7273060070         */ IL_00a6: ldstr "Move Left" /* 70000673 */
		/* 0x00003B53 7287060070         */ IL_00ab: ldstr "MoveLeft" /* 70000687 */
		/* 0x00003B58 D010000002         */ IL_00b0: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003B5D 282400000A         */ IL_00b5: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003B62 738500000A         */ IL_00ba: newobj instance void [PresentationCore]System.Windows.Input.RoutedUICommand::.ctor(string, string, class [mscorlib]System.Type) /* 0A000085 */
		/* 0x00003B67 8049000004         */ IL_00bf: stsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveLeftCommand /* 04000049 */
		/* 0x00003B6C 7299060070         */ IL_00c4: ldstr "Move Right" /* 70000699 */
		/* 0x00003B71 72AF060070         */ IL_00c9: ldstr "MoveRight" /* 700006AF */
		/* 0x00003B76 D010000002         */ IL_00ce: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003B7B 282400000A         */ IL_00d3: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003B80 738500000A         */ IL_00d8: newobj instance void [PresentationCore]System.Windows.Input.RoutedUICommand::.ctor(string, string, class [mscorlib]System.Type) /* 0A000085 */
		/* 0x00003B85 804A000004         */ IL_00dd: stsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveRightCommand /* 0400004A */
		/* 0x00003B8A 7E2E00000A         */ IL_00e2: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x00003B8F D010000002         */ IL_00e7: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003B94 282400000A         */ IL_00ec: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003B99 D010000002         */ IL_00f1: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003B9E 282400000A         */ IL_00f6: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003BA3 732500000A         */ IL_00fb: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003BA8 6F2F00000A         */ IL_0100: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x00003BAD D010000002         */ IL_0105: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003BB2 282400000A         */ IL_010a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003BB7 7E49000004         */ IL_010f: ldsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveLeftCommand /* 04000049 */
		/* 0x00003BBC 14                 */ IL_0114: ldnull
		/* 0x00003BBD FE06B5000006       */ IL_0115: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveLeftCommand_Executed(object, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs) /* 060000B5 */
		/* 0x00003BC3 738600000A         */ IL_011b: newobj instance void [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler::.ctor(object, native int) /* 0A000086 */
		/* 0x00003BC8 14                 */ IL_0120: ldnull
		/* 0x00003BC9 FE06B6000006       */ IL_0121: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveLeftCommand_CanExecute(object, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs) /* 060000B6 */
		/* 0x00003BCF 738700000A         */ IL_0127: newobj instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler::.ctor(object, native int) /* 0A000087 */
		/* 0x00003BD4 738800000A         */ IL_012c: newobj instance void [PresentationCore]System.Windows.Input.CommandBinding::.ctor(class [System]System.Windows.Input.ICommand, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler) /* 0A000088 */
		/* 0x00003BD9 288900000A         */ IL_0131: call void [PresentationCore]System.Windows.Input.CommandManager::RegisterClassCommandBinding(class [mscorlib]System.Type, class [PresentationCore]System.Windows.Input.CommandBinding) /* 0A000089 */
		/* 0x00003BDE D010000002         */ IL_0136: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003BE3 282400000A         */ IL_013b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003BE8 7E4A000004         */ IL_0140: ldsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveRightCommand /* 0400004A */
		/* 0x00003BED 14                 */ IL_0145: ldnull
		/* 0x00003BEE FE06B7000006       */ IL_0146: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveRightCommand_Executed(object, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs) /* 060000B7 */
		/* 0x00003BF4 738600000A         */ IL_014c: newobj instance void [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler::.ctor(object, native int) /* 0A000086 */
		/* 0x00003BF9 14                 */ IL_0151: ldnull
		/* 0x00003BFA FE06B8000006       */ IL_0152: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::MoveRightCommand_CanExecute(object, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs) /* 060000B8 */
		/* 0x00003C00 738700000A         */ IL_0158: newobj instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler::.ctor(object, native int) /* 0A000087 */
		/* 0x00003C05 738800000A         */ IL_015d: newobj instance void [PresentationCore]System.Windows.Input.CommandBinding::.ctor(class [System]System.Windows.Input.ICommand, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler) /* 0A000088 */
		/* 0x00003C0A 288900000A         */ IL_0162: call void [PresentationCore]System.Windows.Input.CommandManager::RegisterClassCommandBinding(class [mscorlib]System.Type, class [PresentationCore]System.Windows.Input.CommandBinding) /* 0A000089 */
		/* 0x00003C0F 2A                 */ IL_0167: ret
	} // end of method SlideBox::.cctor

	.method /* 060000B0 */ public hidebysig virtual 
		instance void OnApplyTemplate () cil managed 
	{
		// Method begins at RVA 0x3c1c
		// Header size: 1
		// Code size: 29 (0x1d)
		.maxstack 8

		/* 0x00003C1C 02                 */ IL_0000: ldarg.0
		/* 0x00003C1D 02                 */ IL_0001: ldarg.0
		/* 0x00003C1E 72C3060070         */ IL_0002: ldstr "PART_ScrollViewer" /* 700006C3 */
		/* 0x00003C23 285400000A         */ IL_0007: call instance class [WindowsBase]System.Windows.DependencyObject [PresentationFramework]System.Windows.FrameworkElement::GetTemplateChild(string) /* 0A000054 */
		/* 0x00003C28 753D000001         */ IL_000c: isinst [PresentationFramework]System.Windows.Controls.ScrollViewer /* 0100003D */
		/* 0x00003C2D 7D44000004         */ IL_0011: stfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C32 02                 */ IL_0016: ldarg.0
		/* 0x00003C33 285500000A         */ IL_0017: call instance void [PresentationFramework]System.Windows.FrameworkElement::OnApplyTemplate() /* 0A000055 */
		/* 0x00003C38 2A                 */ IL_001c: ret
	} // end of method SlideBox::OnApplyTemplate

	.method /* 060000B1 */ family hidebysig newslot virtual 
		instance void OnContentOffsetChanged (
			float64 oldValue,
			float64 newValue
		) cil managed 
	{
		// Method begins at RVA 0x3c3a
		// Header size: 1
		// Code size: 49 (0x31)
		.maxstack 8

		/* 0x00003C3A 02                 */ IL_0000: ldarg.0
		/* 0x00003C3B 7B44000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C40 2C28               */ IL_0006: brfalse.s IL_0030
		/* 0x00003C42 02                 */ IL_0008: ldarg.0
		/* 0x00003C43 28A7000006         */ IL_0009: call instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation() /* 060000A7 */
		/* 0x00003C48 2D0E               */ IL_000e: brtrue.s IL_001e
		/* 0x00003C4A 02                 */ IL_0010: ldarg.0
		/* 0x00003C4B 7B44000004         */ IL_0011: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C50 04                 */ IL_0016: ldarg.2
		/* 0x00003C51 6F8A00000A         */ IL_0017: callvirt instance void [PresentationFramework]System.Windows.Controls.ScrollViewer::ScrollToHorizontalOffset(float64) /* 0A00008A */
		/* 0x00003C56 2B0C               */ IL_001c: br.s IL_002a
		/* 0x00003C58 02                 */ IL_001e: ldarg.0
		/* 0x00003C59 7B44000004         */ IL_001f: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C5E 04                 */ IL_0024: ldarg.2
		/* 0x00003C5F 6F8B00000A         */ IL_0025: callvirt instance void [PresentationFramework]System.Windows.Controls.ScrollViewer::ScrollToVerticalOffset(float64) /* 0A00008B */
		/* 0x00003C64 02                 */ IL_002a: ldarg.0
		/* 0x00003C65 288C00000A         */ IL_002b: call instance void [PresentationCore]System.Windows.UIElement::UpdateLayout() /* 0A00008C */
		/* 0x00003C6A 2A                 */ IL_0030: ret
	} // end of method SlideBox::OnContentOffsetChanged

	.method /* 060000B2 */ family hidebysig newslot virtual 
		instance void OnMovedLeft () cil managed 
	{
		// Method begins at RVA 0x3c6c
		// Header size: 12
		// Code size: 88 (0x58)
		.maxstack 4

		/* 0x00003C6C 02                 */ IL_0000: ldarg.0
		/* 0x00003C6D 7B44000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C72 2C4F               */ IL_0006: brfalse.s IL_0057
		/* 0x00003C74 02                 */ IL_0008: ldarg.0
		/* 0x00003C75 28A7000006         */ IL_0009: call instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation() /* 060000A7 */
		/* 0x00003C7A 2D24               */ IL_000e: brtrue.s IL_0034
		/* 0x00003C7C 02                 */ IL_0010: ldarg.0
		/* 0x00003C7D 02                 */ IL_0011: ldarg.0
		/* 0x00003C7E 7B44000004         */ IL_0012: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C83 6F8100000A         */ IL_0017: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_HorizontalOffset() /* 0A000081 */
		/* 0x00003C88 02                 */ IL_001c: ldarg.0
		/* 0x00003C89 7B44000004         */ IL_001d: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003C8E 6F8100000A         */ IL_0022: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_HorizontalOffset() /* 0A000081 */
		/* 0x00003C93 02                 */ IL_0027: ldarg.0
		/* 0x00003C94 28A9000006         */ IL_0028: call instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_StepSize() /* 060000A9 */
		/* 0x00003C99 59                 */ IL_002d: sub
		/* 0x00003C9A 28B4000006         */ IL_002e: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ChangeOffsetSlightly(float64, float64) /* 060000B4 */
		/* 0x00003C9F 2A                 */ IL_0033: ret
		/* 0x00003CA0 02                 */ IL_0034: ldarg.0
		/* 0x00003CA1 02                 */ IL_0035: ldarg.0
		/* 0x00003CA2 7B44000004         */ IL_0036: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003CA7 6F8200000A         */ IL_003b: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_VerticalOffset() /* 0A000082 */
		/* 0x00003CAC 02                 */ IL_0040: ldarg.0
		/* 0x00003CAD 7B44000004         */ IL_0041: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003CB2 6F8200000A         */ IL_0046: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_VerticalOffset() /* 0A000082 */
		/* 0x00003CB7 02                 */ IL_004b: ldarg.0
		/* 0x00003CB8 28A9000006         */ IL_004c: call instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_StepSize() /* 060000A9 */
		/* 0x00003CBD 59                 */ IL_0051: sub
		/* 0x00003CBE 28B4000006         */ IL_0052: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ChangeOffsetSlightly(float64, float64) /* 060000B4 */
		/* 0x00003CC3 2A                 */ IL_0057: ret
	} // end of method SlideBox::OnMovedLeft

	.method /* 060000B3 */ family hidebysig newslot virtual 
		instance void OnMovedRight () cil managed 
	{
		// Method begins at RVA 0x3cd0
		// Header size: 12
		// Code size: 88 (0x58)
		.maxstack 4

		/* 0x00003CD0 02                 */ IL_0000: ldarg.0
		/* 0x00003CD1 7B44000004         */ IL_0001: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003CD6 2C4F               */ IL_0006: brfalse.s IL_0057
		/* 0x00003CD8 02                 */ IL_0008: ldarg.0
		/* 0x00003CD9 28A7000006         */ IL_0009: call instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation() /* 060000A7 */
		/* 0x00003CDE 2D24               */ IL_000e: brtrue.s IL_0034
		/* 0x00003CE0 02                 */ IL_0010: ldarg.0
		/* 0x00003CE1 02                 */ IL_0011: ldarg.0
		/* 0x00003CE2 7B44000004         */ IL_0012: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003CE7 6F8100000A         */ IL_0017: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_HorizontalOffset() /* 0A000081 */
		/* 0x00003CEC 02                 */ IL_001c: ldarg.0
		/* 0x00003CED 7B44000004         */ IL_001d: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003CF2 6F8100000A         */ IL_0022: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_HorizontalOffset() /* 0A000081 */
		/* 0x00003CF7 02                 */ IL_0027: ldarg.0
		/* 0x00003CF8 28A9000006         */ IL_0028: call instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_StepSize() /* 060000A9 */
		/* 0x00003CFD 58                 */ IL_002d: add
		/* 0x00003CFE 28B4000006         */ IL_002e: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ChangeOffsetSlightly(float64, float64) /* 060000B4 */
		/* 0x00003D03 2A                 */ IL_0033: ret
		/* 0x00003D04 02                 */ IL_0034: ldarg.0
		/* 0x00003D05 02                 */ IL_0035: ldarg.0
		/* 0x00003D06 7B44000004         */ IL_0036: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003D0B 6F8200000A         */ IL_003b: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_VerticalOffset() /* 0A000082 */
		/* 0x00003D10 02                 */ IL_0040: ldarg.0
		/* 0x00003D11 7B44000004         */ IL_0041: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003D16 6F8200000A         */ IL_0046: callvirt instance float64 [PresentationFramework]System.Windows.Controls.ScrollViewer::get_VerticalOffset() /* 0A000082 */
		/* 0x00003D1B 02                 */ IL_004b: ldarg.0
		/* 0x00003D1C 28A9000006         */ IL_004c: call instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_StepSize() /* 060000A9 */
		/* 0x00003D21 58                 */ IL_0051: add
		/* 0x00003D22 28B4000006         */ IL_0052: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ChangeOffsetSlightly(float64, float64) /* 060000B4 */
		/* 0x00003D27 2A                 */ IL_0057: ret
	} // end of method SlideBox::OnMovedRight

	.method /* 060000B4 */ private hidebysig 
		instance void ChangeOffsetSlightly (
			float64 startOffset,
			float64 endOffset
		) cil managed 
	{
		// Method begins at RVA 0x3d34
		// Header size: 12
		// Code size: 124 (0x7c)
		.maxstack 7
		.locals /* 1100000D */ init (
			[0] class [PresentationCore]System.Windows.Media.Animation.DoubleAnimation
		)

		/* 0x00003D34 03                 */ IL_0000: ldarg.1
		/* 0x00003D35 04                 */ IL_0001: ldarg.2
		/* 0x00003D36 16                 */ IL_0002: ldc.i4.0
		/* 0x00003D37 16                 */ IL_0003: ldc.i4.0
		/* 0x00003D38 16                 */ IL_0004: ldc.i4.0
		/* 0x00003D39 16                 */ IL_0005: ldc.i4.0
		/* 0x00003D3A 1F64               */ IL_0006: ldc.i4.s 100
		/* 0x00003D3C 738D00000A         */ IL_0008: newobj instance void [mscorlib]System.TimeSpan::.ctor(int32, int32, int32, int32, int32) /* 0A00008D */
		/* 0x00003D41 738E00000A         */ IL_000d: newobj instance void [PresentationCore]System.Windows.Duration::.ctor(valuetype [mscorlib]System.TimeSpan) /* 0A00008E */
		/* 0x00003D46 16                 */ IL_0012: ldc.i4.0
		/* 0x00003D47 738F00000A         */ IL_0013: newobj instance void [PresentationCore]System.Windows.Media.Animation.DoubleAnimation::.ctor(float64, float64, valuetype [PresentationCore]System.Windows.Duration, valuetype [PresentationCore]System.Windows.Media.Animation.FillBehavior) /* 0A00008F */
		/* 0x00003D4C 0A                 */ IL_0018: stloc.0
		/* 0x00003D4D 06                 */ IL_0019: ldloc.0
		/* 0x00003D4E 72E7060070         */ IL_001a: ldstr "PART_SlideBox" /* 700006E7 */
		/* 0x00003D53 289000000A         */ IL_001f: call void [PresentationFramework]System.Windows.Media.Animation.Storyboard::SetTargetName(class [WindowsBase]System.Windows.DependencyObject, string) /* 0A000090 */
		/* 0x00003D58 06                 */ IL_0024: ldloc.0
		/* 0x00003D59 7E48000004         */ IL_0025: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::ContentOffsetProperty /* 04000048 */
		/* 0x00003D5E 739100000A         */ IL_002a: newobj instance void [PresentationFramework]System.Windows.PropertyPath::.ctor(object) /* 0A000091 */
		/* 0x00003D63 289200000A         */ IL_002f: call void [PresentationFramework]System.Windows.Media.Animation.Storyboard::SetTargetProperty(class [WindowsBase]System.Windows.DependencyObject, class [PresentationFramework]System.Windows.PropertyPath) /* 0A000092 */
		/* 0x00003D68 739300000A         */ IL_0034: newobj instance void [PresentationFramework]System.Windows.Media.Animation.Storyboard::.ctor() /* 0A000093 */
		/* 0x00003D6D 25                 */ IL_0039: dup
		/* 0x00003D6E 6F9400000A         */ IL_003a: callvirt instance class [PresentationCore]System.Windows.Media.Animation.TimelineCollection [PresentationCore]System.Windows.Media.Animation.TimelineGroup::get_Children() /* 0A000094 */
		/* 0x00003D73 06                 */ IL_003f: ldloc.0
		/* 0x00003D74 6F9500000A         */ IL_0040: callvirt instance void [PresentationCore]System.Windows.Media.Animation.TimelineCollection::Add(class [PresentationCore]System.Windows.Media.Animation.Timeline) /* 0A000095 */
		/* 0x00003D79 02                 */ IL_0045: ldarg.0
		/* 0x00003D7A 6F9600000A         */ IL_0046: callvirt instance void [PresentationFramework]System.Windows.Media.Animation.Storyboard::Begin(class [PresentationFramework]System.Windows.FrameworkElement) /* 0A000096 */
		/* 0x00003D7F 02                 */ IL_004b: ldarg.0
		/* 0x00003D80 7B44000004         */ IL_004c: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003D85 2C28               */ IL_0051: brfalse.s IL_007b
		/* 0x00003D87 02                 */ IL_0053: ldarg.0
		/* 0x00003D88 28A7000006         */ IL_0054: call instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation() /* 060000A7 */
		/* 0x00003D8D 2D0E               */ IL_0059: brtrue.s IL_0069
		/* 0x00003D8F 02                 */ IL_005b: ldarg.0
		/* 0x00003D90 7B44000004         */ IL_005c: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003D95 04                 */ IL_0061: ldarg.2
		/* 0x00003D96 6F8A00000A         */ IL_0062: callvirt instance void [PresentationFramework]System.Windows.Controls.ScrollViewer::ScrollToHorizontalOffset(float64) /* 0A00008A */
		/* 0x00003D9B 2B0C               */ IL_0067: br.s IL_0075
		/* 0x00003D9D 02                 */ IL_0069: ldarg.0
		/* 0x00003D9E 7B44000004         */ IL_006a: ldfld class [PresentationFramework]System.Windows.Controls.ScrollViewer AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::_scrollViewer /* 04000044 */
		/* 0x00003DA3 04                 */ IL_006f: ldarg.2
		/* 0x00003DA4 6F8B00000A         */ IL_0070: callvirt instance void [PresentationFramework]System.Windows.Controls.ScrollViewer::ScrollToVerticalOffset(float64) /* 0A00008B */
		/* 0x00003DA9 02                 */ IL_0075: ldarg.0
		/* 0x00003DAA 288C00000A         */ IL_0076: call instance void [PresentationCore]System.Windows.UIElement::UpdateLayout() /* 0A00008C */
		/* 0x00003DAF 2A                 */ IL_007b: ret
	} // end of method SlideBox::ChangeOffsetSlightly

	.method /* 060000B5 */ private hidebysig static 
		void MoveLeftCommand_Executed (
			object sender,
			class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3dbc
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00003DBC 02                 */ IL_0000: ldarg.0
		/* 0x00003DBD 7510000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003DC2 6FB2000006         */ IL_0006: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OnMovedLeft() /* 060000B2 */
		/* 0x00003DC7 2A                 */ IL_000b: ret
	} // end of method SlideBox::MoveLeftCommand_Executed

	.method /* 060000B6 */ private hidebysig static 
		void MoveLeftCommand_CanExecute (
			object sender,
			class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3dcc
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 2
		.locals /* 1100000E */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox
		)

		/* 0x00003DCC 02                 */ IL_0000: ldarg.0
		/* 0x00003DCD 7510000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003DD2 0A                 */ IL_0006: stloc.0
		/* 0x00003DD3 03                 */ IL_0007: ldarg.1
		/* 0x00003DD4 06                 */ IL_0008: ldloc.0
		/* 0x00003DD5 6FAD000006         */ IL_0009: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_CanMoveLeft() /* 060000AD */
		/* 0x00003DDA 6F9700000A         */ IL_000e: callvirt instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs::set_CanExecute(bool) /* 0A000097 */
		/* 0x00003DDF 2A                 */ IL_0013: ret
	} // end of method SlideBox::MoveLeftCommand_CanExecute

	.method /* 060000B7 */ private hidebysig static 
		void MoveRightCommand_Executed (
			object sender,
			class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3dec
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00003DEC 02                 */ IL_0000: ldarg.0
		/* 0x00003DED 7510000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003DF2 6FB3000006         */ IL_0006: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OnMovedRight() /* 060000B3 */
		/* 0x00003DF7 2A                 */ IL_000b: ret
	} // end of method SlideBox::MoveRightCommand_Executed

	.method /* 060000B8 */ private hidebysig static 
		void MoveRightCommand_CanExecute (
			object sender,
			class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3dfc
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 2
		.locals /* 1100000E */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox
		)

		/* 0x00003DFC 02                 */ IL_0000: ldarg.0
		/* 0x00003DFD 7510000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003E02 0A                 */ IL_0006: stloc.0
		/* 0x00003E03 03                 */ IL_0007: ldarg.1
		/* 0x00003E04 06                 */ IL_0008: ldloc.0
		/* 0x00003E05 6FAE000006         */ IL_0009: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_CanMoveRight() /* 060000AE */
		/* 0x00003E0A 6F9700000A         */ IL_000e: callvirt instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs::set_CanExecute(bool) /* 0A000097 */
		/* 0x00003E0F 2A                 */ IL_0013: ret
	} // end of method SlideBox::MoveRightCommand_CanExecute

	.method /* 060000B9 */ private hidebysig static 
		void OnContentOffsetPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x3e1c
		// Header size: 1
		// Code size: 36 (0x24)
		.maxstack 8

		/* 0x00003E1C 02                 */ IL_0000: ldarg.0
		/* 0x00003E1D 7510000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox /* 02000010 */
		/* 0x00003E22 0F01               */ IL_0006: ldarga.s e
		/* 0x00003E24 283D00000A         */ IL_0008: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_OldValue() /* 0A00003D */
		/* 0x00003E29 A56D000001         */ IL_000d: unbox.any [mscorlib]System.Double /* 0100006D */
		/* 0x00003E2E 0F01               */ IL_0012: ldarga.s e
		/* 0x00003E30 283E00000A         */ IL_0014: call instance object [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs::get_NewValue() /* 0A00003E */
		/* 0x00003E35 A56D000001         */ IL_0019: unbox.any [mscorlib]System.Double /* 0100006D */
		/* 0x00003E3A 6FB1000006         */ IL_001e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::OnContentOffsetChanged(float64, float64) /* 060000B1 */
		/* 0x00003E3F 2A                 */ IL_0023: ret
	} // end of method SlideBox::OnContentOffsetPropertyChanged

	.method /* 060000BA */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x35c0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000035C0 02                 */ IL_0000: ldarg.0
		/* 0x000035C1 287300000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.ContentControl::.ctor() /* 0A000073 */
		/* 0x000035C6 2A                 */ IL_0006: ret
	} // end of method SlideBox::.ctor

	// Properties
	.property /* 17000032 */ instance valuetype [PresentationFramework]System.Windows.Controls.Orientation Orientation()
	{
		.get instance valuetype [PresentationFramework]System.Windows.Controls.Orientation AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_Orientation()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::set_Orientation(valuetype [PresentationFramework]System.Windows.Controls.Orientation)
	}
	.property /* 17000033 */ instance float64 StepSize()
	{
		.get instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_StepSize()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::set_StepSize(float64)
	}
	.property /* 17000034 */ instance float64 ContentOffset()
	{
		.get instance float64 AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_ContentOffset()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::set_ContentOffset(float64)
	}
	.property /* 17000035 */ instance bool CanMoveLeft()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_CanMoveLeft()
	}
	.property /* 17000036 */ instance bool CanMoveRight()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox::get_CanMoveRight()
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.SlideBox

.class /* 02000011 */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl
	extends [PresentationFramework]System.Windows.Controls.Control
{
	.custom /* 0C000025 */ instance void [System.Xaml]System.Windows.Markup.ContentPropertyAttribute::.ctor(string) = (
		01 00 05 49 74 65 6d 73 00 00
	)
	// Fields
	.field /* 0400004B */ private int32 _loadedTimes
	.field /* 0400004C */ private initonly class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> _nagivationHistory
	.field /* 0400004D */ private static initonly class [WindowsBase]System.Windows.DependencyPropertyKey ItemsPropertyKey
	.field /* 0400004E */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ItemsProperty
	.field /* 0400004F */ private static initonly class [WindowsBase]System.Windows.DependencyPropertyKey CurrentItemPropertyKey
	.field /* 04000050 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CurrentItemProperty
	.field /* 04000051 */ private static initonly class [WindowsBase]System.Windows.DependencyPropertyKey CanForwardPropertyKey
	.field /* 04000052 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanForwardProperty
	.field /* 04000053 */ private static initonly class [WindowsBase]System.Windows.DependencyPropertyKey CanBackwardPropertyKey
	.field /* 04000054 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanBackwardProperty
	.field /* 04000055 */ private static initonly class [WindowsBase]System.Windows.DependencyPropertyKey CanFinishPropertyKey
	.field /* 04000056 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanFinishProperty
	.field /* 04000057 */ private static initonly class [WindowsBase]System.Windows.DependencyPropertyKey CanCancelPropertyKey
	.field /* 04000058 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanCancelProperty
	.field /* 04000059 */ public static initonly class [PresentationCore]System.Windows.Input.RoutedUICommand BackwardCommand
	.field /* 0400005A */ public static initonly class [PresentationCore]System.Windows.Input.RoutedUICommand ForwardCommand
	.field /* 0400005B */ public static initonly class [PresentationCore]System.Windows.Input.RoutedUICommand FinishCommand
	.field /* 0400005C */ public static initonly class [PresentationCore]System.Windows.RoutedEvent FinishedEvent

	// Methods
	.method /* 060000BB */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection get_Items () cil managed 
	{
		// Method begins at RVA 0x3e41
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003E41 02                 */ IL_0000: ldarg.0
		/* 0x00003E42 7E4E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ItemsProperty /* 0400004E */
		/* 0x00003E47 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003E4C 7413000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection /* 02000013 */
		/* 0x00003E51 2A                 */ IL_0010: ret
	} // end of method WizardControl::get_Items

	.method /* 060000BC */ private hidebysig specialname 
		instance void set_Items (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3e53
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003E53 02                 */ IL_0000: ldarg.0
		/* 0x00003E54 7E4D000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ItemsPropertyKey /* 0400004D */
		/* 0x00003E59 03                 */ IL_0006: ldarg.1
		/* 0x00003E5A 289800000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyPropertyKey, object) /* 0A000098 */
		/* 0x00003E5F 2A                 */ IL_000c: ret
	} // end of method WizardControl::set_Items

	.method /* 060000BD */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem get_CurrentItem () cil managed 
	{
		// Method begins at RVA 0x3e61
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003E61 02                 */ IL_0000: ldarg.0
		/* 0x00003E62 7E50000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CurrentItemProperty /* 04000050 */
		/* 0x00003E67 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003E6C 7412000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00003E71 2A                 */ IL_0010: ret
	} // end of method WizardControl::get_CurrentItem

	.method /* 060000BE */ private hidebysig specialname 
		instance void set_CurrentItem (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3e73
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003E73 02                 */ IL_0000: ldarg.0
		/* 0x00003E74 7E4F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CurrentItemPropertyKey /* 0400004F */
		/* 0x00003E79 03                 */ IL_0006: ldarg.1
		/* 0x00003E7A 289800000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyPropertyKey, object) /* 0A000098 */
		/* 0x00003E7F 2A                 */ IL_000c: ret
	} // end of method WizardControl::set_CurrentItem

	.method /* 060000BF */ public hidebysig specialname 
		instance bool get_CanForward () cil managed 
	{
		// Method begins at RVA 0x3e81
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003E81 02                 */ IL_0000: ldarg.0
		/* 0x00003E82 7E52000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanForwardProperty /* 04000052 */
		/* 0x00003E87 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003E8C A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003E91 2A                 */ IL_0010: ret
	} // end of method WizardControl::get_CanForward

	.method /* 060000C0 */ private hidebysig specialname 
		instance void set_CanForward (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3e93
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003E93 02                 */ IL_0000: ldarg.0
		/* 0x00003E94 7E51000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanForwardPropertyKey /* 04000051 */
		/* 0x00003E99 03                 */ IL_0006: ldarg.1
		/* 0x00003E9A 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003E9F 289800000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyPropertyKey, object) /* 0A000098 */
		/* 0x00003EA4 2A                 */ IL_0011: ret
	} // end of method WizardControl::set_CanForward

	.method /* 060000C1 */ public hidebysig specialname 
		instance bool get_CanBackward () cil managed 
	{
		// Method begins at RVA 0x3ea6
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003EA6 02                 */ IL_0000: ldarg.0
		/* 0x00003EA7 7E54000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanBackwardProperty /* 04000054 */
		/* 0x00003EAC 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003EB1 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003EB6 2A                 */ IL_0010: ret
	} // end of method WizardControl::get_CanBackward

	.method /* 060000C2 */ private hidebysig specialname 
		instance void set_CanBackward (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3eb8
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003EB8 02                 */ IL_0000: ldarg.0
		/* 0x00003EB9 7E53000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanBackwardPropertyKey /* 04000053 */
		/* 0x00003EBE 03                 */ IL_0006: ldarg.1
		/* 0x00003EBF 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003EC4 289800000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyPropertyKey, object) /* 0A000098 */
		/* 0x00003EC9 2A                 */ IL_0011: ret
	} // end of method WizardControl::set_CanBackward

	.method /* 060000C3 */ public hidebysig specialname 
		instance bool get_CanFinish () cil managed 
	{
		// Method begins at RVA 0x3ecb
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003ECB 02                 */ IL_0000: ldarg.0
		/* 0x00003ECC 7E56000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanFinishProperty /* 04000056 */
		/* 0x00003ED1 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003ED6 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003EDB 2A                 */ IL_0010: ret
	} // end of method WizardControl::get_CanFinish

	.method /* 060000C4 */ private hidebysig specialname 
		instance void set_CanFinish (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3edd
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003EDD 02                 */ IL_0000: ldarg.0
		/* 0x00003EDE 7E55000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanFinishPropertyKey /* 04000055 */
		/* 0x00003EE3 03                 */ IL_0006: ldarg.1
		/* 0x00003EE4 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003EE9 289800000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyPropertyKey, object) /* 0A000098 */
		/* 0x00003EEE 2A                 */ IL_0011: ret
	} // end of method WizardControl::set_CanFinish

	.method /* 060000C5 */ public hidebysig specialname 
		instance bool get_CanCancel () cil managed 
	{
		// Method begins at RVA 0x3ef0
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00003EF0 02                 */ IL_0000: ldarg.0
		/* 0x00003EF1 7E58000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanCancelProperty /* 04000058 */
		/* 0x00003EF6 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00003EFB A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003F00 2A                 */ IL_0010: ret
	} // end of method WizardControl::get_CanCancel

	.method /* 060000C6 */ private hidebysig specialname 
		instance void set_CanCancel (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3f02
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00003F02 02                 */ IL_0000: ldarg.0
		/* 0x00003F03 7E57000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanCancelPropertyKey /* 04000057 */
		/* 0x00003F08 03                 */ IL_0006: ldarg.1
		/* 0x00003F09 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003F0E 289800000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyPropertyKey, object) /* 0A000098 */
		/* 0x00003F13 2A                 */ IL_0011: ret
	} // end of method WizardControl::set_CanCancel

	.method /* 060000C7 */ public hidebysig specialname 
		instance void add_Finished (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3f15
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003F15 02                 */ IL_0000: ldarg.0
		/* 0x00003F16 7E5C000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishedEvent /* 0400005C */
		/* 0x00003F1B 03                 */ IL_0006: ldarg.1
		/* 0x00003F1C 282200000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::AddHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000022 */
		/* 0x00003F21 2A                 */ IL_000c: ret
	} // end of method WizardControl::add_Finished

	.method /* 060000C8 */ public hidebysig specialname 
		instance void remove_Finished (
			class [PresentationCore]System.Windows.RoutedEventHandler 'value'
		) cil managed 
	{
		// Method begins at RVA 0x3f23
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00003F23 02                 */ IL_0000: ldarg.0
		/* 0x00003F24 7E5C000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishedEvent /* 0400005C */
		/* 0x00003F29 03                 */ IL_0006: ldarg.1
		/* 0x00003F2A 282300000A         */ IL_0007: call instance void [PresentationCore]System.Windows.UIElement::RemoveHandler(class [PresentationCore]System.Windows.RoutedEvent, class [mscorlib]System.Delegate) /* 0A000023 */
		/* 0x00003F2F 2A                 */ IL_000c: ret
	} // end of method WizardControl::remove_Finished

	.method /* 060000C9 */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x3f34
		// Header size: 12
		// Code size: 675 (0x2a3)
		.maxstack 5

		/* 0x00003F34 7203070070         */ IL_0000: ldstr "Items" /* 70000703 */
		/* 0x00003F39 D013000002         */ IL_0005: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection /* 02000013 */
		/* 0x00003F3E 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003F43 D011000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00003F48 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003F4D 739900000A         */ IL_0019: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor() /* 0A000099 */
		/* 0x00003F52 289A00000A         */ IL_001e: call class [WindowsBase]System.Windows.DependencyPropertyKey [WindowsBase]System.Windows.DependencyProperty::RegisterReadOnly(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00009A */
		/* 0x00003F57 804D000004         */ IL_0023: stsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ItemsPropertyKey /* 0400004D */
		/* 0x00003F5C 7E4D000004         */ IL_0028: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ItemsPropertyKey /* 0400004D */
		/* 0x00003F61 6F9B00000A         */ IL_002d: callvirt instance class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyPropertyKey::get_DependencyProperty() /* 0A00009B */
		/* 0x00003F66 804E000004         */ IL_0032: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ItemsProperty /* 0400004E */
		/* 0x00003F6B 720F070070         */ IL_0037: ldstr "CurrentItem" /* 7000070F */
		/* 0x00003F70 D012000002         */ IL_003c: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00003F75 282400000A         */ IL_0041: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003F7A D011000002         */ IL_0046: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00003F7F 282400000A         */ IL_004b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003F84 14                 */ IL_0050: ldnull
		/* 0x00003F85 FE06D2000006       */ IL_0051: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::OnWizardControlItemChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000D2 */
		/* 0x00003F8B 732800000A         */ IL_0057: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00003F90 732900000A         */ IL_005c: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000029 */
		/* 0x00003F95 289A00000A         */ IL_0061: call class [WindowsBase]System.Windows.DependencyPropertyKey [WindowsBase]System.Windows.DependencyProperty::RegisterReadOnly(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00009A */
		/* 0x00003F9A 804F000004         */ IL_0066: stsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CurrentItemPropertyKey /* 0400004F */
		/* 0x00003F9F 7E4F000004         */ IL_006b: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CurrentItemPropertyKey /* 0400004F */
		/* 0x00003FA4 6F9B00000A         */ IL_0070: callvirt instance class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyPropertyKey::get_DependencyProperty() /* 0A00009B */
		/* 0x00003FA9 8050000004         */ IL_0075: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CurrentItemProperty /* 04000050 */
		/* 0x00003FAE 7227070070         */ IL_007a: ldstr "CanForward" /* 70000727 */
		/* 0x00003FB3 D05F000001         */ IL_007f: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003FB8 282400000A         */ IL_0084: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003FBD D011000002         */ IL_0089: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00003FC2 282400000A         */ IL_008e: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003FC7 16                 */ IL_0093: ldc.i4.0
		/* 0x00003FC8 8C5F000001         */ IL_0094: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003FCD 732500000A         */ IL_0099: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00003FD2 289A00000A         */ IL_009e: call class [WindowsBase]System.Windows.DependencyPropertyKey [WindowsBase]System.Windows.DependencyProperty::RegisterReadOnly(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00009A */
		/* 0x00003FD7 8051000004         */ IL_00a3: stsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanForwardPropertyKey /* 04000051 */
		/* 0x00003FDC 7E51000004         */ IL_00a8: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanForwardPropertyKey /* 04000051 */
		/* 0x00003FE1 6F9B00000A         */ IL_00ad: callvirt instance class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyPropertyKey::get_DependencyProperty() /* 0A00009B */
		/* 0x00003FE6 8052000004         */ IL_00b2: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanForwardProperty /* 04000052 */
		/* 0x00003FEB 723D070070         */ IL_00b7: ldstr "CanBackward" /* 7000073D */
		/* 0x00003FF0 D05F000001         */ IL_00bc: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x00003FF5 282400000A         */ IL_00c1: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00003FFA D011000002         */ IL_00c6: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00003FFF 282400000A         */ IL_00cb: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004004 16                 */ IL_00d0: ldc.i4.0
		/* 0x00004005 8C5F000001         */ IL_00d1: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000400A 732500000A         */ IL_00d6: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000400F 289A00000A         */ IL_00db: call class [WindowsBase]System.Windows.DependencyPropertyKey [WindowsBase]System.Windows.DependencyProperty::RegisterReadOnly(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00009A */
		/* 0x00004014 8053000004         */ IL_00e0: stsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanBackwardPropertyKey /* 04000053 */
		/* 0x00004019 7E53000004         */ IL_00e5: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanBackwardPropertyKey /* 04000053 */
		/* 0x0000401E 6F9B00000A         */ IL_00ea: callvirt instance class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyPropertyKey::get_DependencyProperty() /* 0A00009B */
		/* 0x00004023 8054000004         */ IL_00ef: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanBackwardProperty /* 04000054 */
		/* 0x00004028 7255070070         */ IL_00f4: ldstr "CanFinish" /* 70000755 */
		/* 0x0000402D D05F000001         */ IL_00f9: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004032 282400000A         */ IL_00fe: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004037 D011000002         */ IL_0103: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x0000403C 282400000A         */ IL_0108: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004041 16                 */ IL_010d: ldc.i4.0
		/* 0x00004042 8C5F000001         */ IL_010e: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004047 732500000A         */ IL_0113: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000404C 289A00000A         */ IL_0118: call class [WindowsBase]System.Windows.DependencyPropertyKey [WindowsBase]System.Windows.DependencyProperty::RegisterReadOnly(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00009A */
		/* 0x00004051 8055000004         */ IL_011d: stsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanFinishPropertyKey /* 04000055 */
		/* 0x00004056 7E55000004         */ IL_0122: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanFinishPropertyKey /* 04000055 */
		/* 0x0000405B 6F9B00000A         */ IL_0127: callvirt instance class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyPropertyKey::get_DependencyProperty() /* 0A00009B */
		/* 0x00004060 8056000004         */ IL_012c: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanFinishProperty /* 04000056 */
		/* 0x00004065 7269070070         */ IL_0131: ldstr "CanCancel" /* 70000769 */
		/* 0x0000406A D05F000001         */ IL_0136: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000406F 282400000A         */ IL_013b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004074 D011000002         */ IL_0140: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00004079 282400000A         */ IL_0145: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000407E 16                 */ IL_014a: ldc.i4.0
		/* 0x0000407F 8C5F000001         */ IL_014b: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004084 732500000A         */ IL_0150: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x00004089 289A00000A         */ IL_0155: call class [WindowsBase]System.Windows.DependencyPropertyKey [WindowsBase]System.Windows.DependencyProperty::RegisterReadOnly(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00009A */
		/* 0x0000408E 8057000004         */ IL_015a: stsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanCancelPropertyKey /* 04000057 */
		/* 0x00004093 7E57000004         */ IL_015f: ldsfld class [WindowsBase]System.Windows.DependencyPropertyKey AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanCancelPropertyKey /* 04000057 */
		/* 0x00004098 6F9B00000A         */ IL_0164: callvirt instance class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyPropertyKey::get_DependencyProperty() /* 0A00009B */
		/* 0x0000409D 8058000004         */ IL_0169: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::CanCancelProperty /* 04000058 */
		/* 0x000040A2 727D070070         */ IL_016e: ldstr "Back" /* 7000077D */
		/* 0x000040A7 7287070070         */ IL_0173: ldstr "BackwardCommand" /* 70000787 */
		/* 0x000040AC D011000002         */ IL_0178: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000040B1 282400000A         */ IL_017d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000040B6 738500000A         */ IL_0182: newobj instance void [PresentationCore]System.Windows.Input.RoutedUICommand::.ctor(string, string, class [mscorlib]System.Type) /* 0A000085 */
		/* 0x000040BB 8059000004         */ IL_0187: stsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::BackwardCommand /* 04000059 */
		/* 0x000040C0 72A7070070         */ IL_018c: ldstr "Next" /* 700007A7 */
		/* 0x000040C5 72B1070070         */ IL_0191: ldstr "ForwardCommand" /* 700007B1 */
		/* 0x000040CA D011000002         */ IL_0196: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000040CF 282400000A         */ IL_019b: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000040D4 738500000A         */ IL_01a0: newobj instance void [PresentationCore]System.Windows.Input.RoutedUICommand::.ctor(string, string, class [mscorlib]System.Type) /* 0A000085 */
		/* 0x000040D9 805A000004         */ IL_01a5: stsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ForwardCommand /* 0400005A */
		/* 0x000040DE 72CF070070         */ IL_01aa: ldstr "Finish" /* 700007CF */
		/* 0x000040E3 72DD070070         */ IL_01af: ldstr "FinishCommand" /* 700007DD */
		/* 0x000040E8 D011000002         */ IL_01b4: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000040ED 282400000A         */ IL_01b9: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000040F2 738500000A         */ IL_01be: newobj instance void [PresentationCore]System.Windows.Input.RoutedUICommand::.ctor(string, string, class [mscorlib]System.Type) /* 0A000085 */
		/* 0x000040F7 805B000004         */ IL_01c3: stsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishCommand /* 0400005B */
		/* 0x000040FC 72F9070070         */ IL_01c8: ldstr "Finished" /* 700007F9 */
		/* 0x00004101 17                 */ IL_01cd: ldc.i4.1
		/* 0x00004102 D036000001         */ IL_01ce: ldtoken [PresentationCore]System.Windows.RoutedEventHandler /* 01000036 */
		/* 0x00004107 282400000A         */ IL_01d3: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000410C D011000002         */ IL_01d8: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00004111 282400000A         */ IL_01dd: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004116 282D00000A         */ IL_01e2: call class [PresentationCore]System.Windows.RoutedEvent [PresentationCore]System.Windows.EventManager::RegisterRoutedEvent(string, valuetype [PresentationCore]System.Windows.RoutingStrategy, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A00002D */
		/* 0x0000411B 805C000004         */ IL_01e7: stsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishedEvent /* 0400005C */
		/* 0x00004120 7E2E00000A         */ IL_01ec: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x00004125 D011000002         */ IL_01f1: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x0000412A 282400000A         */ IL_01f6: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000412F D011000002         */ IL_01fb: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00004134 282400000A         */ IL_0200: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004139 732500000A         */ IL_0205: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000413E 6F2F00000A         */ IL_020a: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x00004143 D011000002         */ IL_020f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00004148 282400000A         */ IL_0214: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000414D 7E59000004         */ IL_0219: ldsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::BackwardCommand /* 04000059 */
		/* 0x00004152 14                 */ IL_021e: ldnull
		/* 0x00004153 FE06D3000006       */ IL_021f: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::BackwardCommand_Executed(object, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs) /* 060000D3 */
		/* 0x00004159 738600000A         */ IL_0225: newobj instance void [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler::.ctor(object, native int) /* 0A000086 */
		/* 0x0000415E 14                 */ IL_022a: ldnull
		/* 0x0000415F FE06D4000006       */ IL_022b: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::BackwardCommand_CanExecute(object, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs) /* 060000D4 */
		/* 0x00004165 738700000A         */ IL_0231: newobj instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler::.ctor(object, native int) /* 0A000087 */
		/* 0x0000416A 738800000A         */ IL_0236: newobj instance void [PresentationCore]System.Windows.Input.CommandBinding::.ctor(class [System]System.Windows.Input.ICommand, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler) /* 0A000088 */
		/* 0x0000416F 288900000A         */ IL_023b: call void [PresentationCore]System.Windows.Input.CommandManager::RegisterClassCommandBinding(class [mscorlib]System.Type, class [PresentationCore]System.Windows.Input.CommandBinding) /* 0A000089 */
		/* 0x00004174 D011000002         */ IL_0240: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x00004179 282400000A         */ IL_0245: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000417E 7E5A000004         */ IL_024a: ldsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ForwardCommand /* 0400005A */
		/* 0x00004183 14                 */ IL_024f: ldnull
		/* 0x00004184 FE06D5000006       */ IL_0250: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ForwardCommand_Executed(object, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs) /* 060000D5 */
		/* 0x0000418A 738600000A         */ IL_0256: newobj instance void [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler::.ctor(object, native int) /* 0A000086 */
		/* 0x0000418F 14                 */ IL_025b: ldnull
		/* 0x00004190 FE06D6000006       */ IL_025c: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::ForwardCommand_CanExecute(object, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs) /* 060000D6 */
		/* 0x00004196 738700000A         */ IL_0262: newobj instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler::.ctor(object, native int) /* 0A000087 */
		/* 0x0000419B 738800000A         */ IL_0267: newobj instance void [PresentationCore]System.Windows.Input.CommandBinding::.ctor(class [System]System.Windows.Input.ICommand, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler) /* 0A000088 */
		/* 0x000041A0 288900000A         */ IL_026c: call void [PresentationCore]System.Windows.Input.CommandManager::RegisterClassCommandBinding(class [mscorlib]System.Type, class [PresentationCore]System.Windows.Input.CommandBinding) /* 0A000089 */
		/* 0x000041A5 D011000002         */ IL_0271: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000041AA 282400000A         */ IL_0276: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000041AF 7E5B000004         */ IL_027b: ldsfld class [PresentationCore]System.Windows.Input.RoutedUICommand AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishCommand /* 0400005B */
		/* 0x000041B4 14                 */ IL_0280: ldnull
		/* 0x000041B5 FE06D7000006       */ IL_0281: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishCommand_Executed(object, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs) /* 060000D7 */
		/* 0x000041BB 738600000A         */ IL_0287: newobj instance void [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler::.ctor(object, native int) /* 0A000086 */
		/* 0x000041C0 14                 */ IL_028c: ldnull
		/* 0x000041C1 FE06D8000006       */ IL_028d: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishCommand_CanExecute(object, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs) /* 060000D8 */
		/* 0x000041C7 738700000A         */ IL_0293: newobj instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler::.ctor(object, native int) /* 0A000087 */
		/* 0x000041CC 738800000A         */ IL_0298: newobj instance void [PresentationCore]System.Windows.Input.CommandBinding::.ctor(class [System]System.Windows.Input.ICommand, class [PresentationCore]System.Windows.Input.ExecutedRoutedEventHandler, class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventHandler) /* 0A000088 */
		/* 0x000041D1 288900000A         */ IL_029d: call void [PresentationCore]System.Windows.Input.CommandManager::RegisterClassCommandBinding(class [mscorlib]System.Type, class [PresentationCore]System.Windows.Input.CommandBinding) /* 0A000089 */
		/* 0x000041D6 2A                 */ IL_02a2: ret
	} // end of method WizardControl::.cctor

	.method /* 060000CA */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x41e3
		// Header size: 1
		// Code size: 48 (0x30)
		.maxstack 8

		/* 0x000041E3 02                 */ IL_0000: ldarg.0
		/* 0x000041E4 739C00000A         */ IL_0001: newobj instance void class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::.ctor() /* 0A00009C */
		/* 0x000041E9 7D4C000004         */ IL_0006: stfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x000041EE 02                 */ IL_000b: ldarg.0
		/* 0x000041EF 283F00000A         */ IL_000c: call instance void [PresentationFramework]System.Windows.Controls.Control::.ctor() /* 0A00003F */
		/* 0x000041F4 02                 */ IL_0011: ldarg.0
		/* 0x000041F5 02                 */ IL_0012: ldarg.0
		/* 0x000041F6 73F6000006         */ IL_0013: newobj instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection::.ctor(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl) /* 060000F6 */
		/* 0x000041FB 28BC000006         */ IL_0018: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_Items(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection) /* 060000BC */
		/* 0x00004200 02                 */ IL_001d: ldarg.0
		/* 0x00004201 02                 */ IL_001e: ldarg.0
		/* 0x00004202 FE06CB000006       */ IL_001f: ldftn instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::WizardControl_Loaded(object, class [PresentationCore]System.Windows.RoutedEventArgs) /* 060000CB */
		/* 0x00004208 733000000A         */ IL_0025: newobj instance void [PresentationCore]System.Windows.RoutedEventHandler::.ctor(object, native int) /* 0A000030 */
		/* 0x0000420D 289D00000A         */ IL_002a: call instance void [PresentationFramework]System.Windows.FrameworkElement::add_Loaded(class [PresentationCore]System.Windows.RoutedEventHandler) /* 0A00009D */
		/* 0x00004212 2A                 */ IL_002f: ret
	} // end of method WizardControl::.ctor

	.method /* 060000CB */ private hidebysig 
		instance void WizardControl_Loaded (
			object sender,
			class [PresentationCore]System.Windows.RoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4214
		// Header size: 12
		// Code size: 82 (0x52)
		.maxstack 3

		/* 0x00004214 02                 */ IL_0000: ldarg.0
		/* 0x00004215 7B4B000004         */ IL_0001: ldfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_loadedTimes /* 0400004B */
		/* 0x0000421A 2D3B               */ IL_0006: brtrue.s IL_0043
		/* 0x0000421C 02                 */ IL_0008: ldarg.0
		/* 0x0000421D 28BD000006         */ IL_0009: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x00004222 2D11               */ IL_000e: brtrue.s IL_0021
		/* 0x00004224 02                 */ IL_0010: ldarg.0
		/* 0x00004225 02                 */ IL_0011: ldarg.0
		/* 0x00004226 28BB000006         */ IL_0012: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x0000422B 280400002B         */ IL_0017: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000004 */
		/* 0x00004230 28BE000006         */ IL_001c: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CurrentItem(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000BE */
		/* 0x00004235 02                 */ IL_0021: ldarg.0
		/* 0x00004236 28BD000006         */ IL_0022: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000423B 2C1A               */ IL_0027: brfalse.s IL_0043
		/* 0x0000423D 02                 */ IL_0029: ldarg.0
		/* 0x0000423E 7B4C000004         */ IL_002a: ldfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x00004243 6F9F00000A         */ IL_002f: callvirt instance int32 class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Count() /* 0A00009F */
		/* 0x00004248 2D0D               */ IL_0034: brtrue.s IL_0043
		/* 0x0000424A 02                 */ IL_0036: ldarg.0
		/* 0x0000424B 28BD000006         */ IL_0037: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x00004250 14                 */ IL_003c: ldnull
		/* 0x00004251 17                 */ IL_003d: ldc.i4.1
		/* 0x00004252 6FEC000006         */ IL_003e: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnEnter(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem, bool) /* 060000EC */
		/* 0x00004257 02                 */ IL_0043: ldarg.0
		/* 0x00004258 02                 */ IL_0044: ldarg.0
		/* 0x00004259 7B4B000004         */ IL_0045: ldfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_loadedTimes /* 0400004B */
		/* 0x0000425E 17                 */ IL_004a: ldc.i4.1
		/* 0x0000425F 58                 */ IL_004b: add
		/* 0x00004260 7D4B000004         */ IL_004c: stfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_loadedTimes /* 0400004B */
		/* 0x00004265 2A                 */ IL_0051: ret
	} // end of method WizardControl::WizardControl_Loaded

	.method /* 060000CC */ public hidebysig 
		instance void GoForward () cil managed 
	{
		// Method begins at RVA 0x4274
		// Header size: 12
		// Code size: 94 (0x5e)
		.maxstack 3
		.locals /* 1100000F */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem,
			[1] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x00004274 02                 */ IL_0000: ldarg.0
		/* 0x00004275 28BF000006         */ IL_0001: call instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanForward() /* 060000BF */
		/* 0x0000427A 2C55               */ IL_0006: brfalse.s IL_005d
		/* 0x0000427C 02                 */ IL_0008: ldarg.0
		/* 0x0000427D 28BD000006         */ IL_0009: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x00004282 0A                 */ IL_000e: stloc.0
		/* 0x00004283 06                 */ IL_000f: ldloc.0
		/* 0x00004284 6FE5000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ForwardItem() /* 060000E5 */
		/* 0x00004289 2D1B               */ IL_0015: brtrue.s IL_0032
		/* 0x0000428B 02                 */ IL_0017: ldarg.0
		/* 0x0000428C 28BB000006         */ IL_0018: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x00004291 02                 */ IL_001d: ldarg.0
		/* 0x00004292 28BB000006         */ IL_001e: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x00004297 06                 */ IL_0023: ldloc.0
		/* 0x00004298 6FA000000A         */ IL_0024: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::IndexOf(!0) /* 0A0000A0 */
		/* 0x0000429D 17                 */ IL_0029: ldc.i4.1
		/* 0x0000429E 58                 */ IL_002a: add
		/* 0x0000429F 6FA100000A         */ IL_002b: callvirt instance !0 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Item(int32) /* 0A0000A1 */
		/* 0x000042A4 2B06               */ IL_0030: br.s IL_0038
		/* 0x000042A6 06                 */ IL_0032: ldloc.0
		/* 0x000042A7 6FE5000006         */ IL_0033: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ForwardItem() /* 060000E5 */
		/* 0x000042AC 0B                 */ IL_0038: stloc.1
		/* 0x000042AD 06                 */ IL_0039: ldloc.0
		/* 0x000042AE 07                 */ IL_003a: ldloc.1
		/* 0x000042AF 6FED000006         */ IL_003b: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnForward(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000ED */
		/* 0x000042B4 2C1B               */ IL_0040: brfalse.s IL_005d
		/* 0x000042B6 02                 */ IL_0042: ldarg.0
		/* 0x000042B7 7B4C000004         */ IL_0043: ldfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x000042BC 06                 */ IL_0048: ldloc.0
		/* 0x000042BD 6FA200000A         */ IL_0049: callvirt instance void class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::Push(!0) /* 0A0000A2 */
		/* 0x000042C2 02                 */ IL_004e: ldarg.0
		/* 0x000042C3 07                 */ IL_004f: ldloc.1
		/* 0x000042C4 28BE000006         */ IL_0050: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CurrentItem(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000BE */
		/* 0x000042C9 07                 */ IL_0055: ldloc.1
		/* 0x000042CA 06                 */ IL_0056: ldloc.0
		/* 0x000042CB 17                 */ IL_0057: ldc.i4.1
		/* 0x000042CC 6FEC000006         */ IL_0058: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnEnter(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem, bool) /* 060000EC */
		/* 0x000042D1 2A                 */ IL_005d: ret
	} // end of method WizardControl::GoForward

	.method /* 060000CD */ public hidebysig 
		instance void GoBackward () cil managed 
	{
		// Method begins at RVA 0x42e0
		// Header size: 12
		// Code size: 64 (0x40)
		.maxstack 3
		.locals /* 1100000F */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem,
			[1] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x000042E0 02                 */ IL_0000: ldarg.0
		/* 0x000042E1 28C1000006         */ IL_0001: call instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanBackward() /* 060000C1 */
		/* 0x000042E6 2C37               */ IL_0006: brfalse.s IL_003f
		/* 0x000042E8 02                 */ IL_0008: ldarg.0
		/* 0x000042E9 28BD000006         */ IL_0009: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x000042EE 0A                 */ IL_000e: stloc.0
		/* 0x000042EF 02                 */ IL_000f: ldarg.0
		/* 0x000042F0 7B4C000004         */ IL_0010: ldfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x000042F5 6FA300000A         */ IL_0015: callvirt instance !0 class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::Peek() /* 0A0000A3 */
		/* 0x000042FA 0B                 */ IL_001a: stloc.1
		/* 0x000042FB 06                 */ IL_001b: ldloc.0
		/* 0x000042FC 07                 */ IL_001c: ldloc.1
		/* 0x000042FD 6FEE000006         */ IL_001d: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnBackward(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000EE */
		/* 0x00004302 2C1B               */ IL_0022: brfalse.s IL_003f
		/* 0x00004304 02                 */ IL_0024: ldarg.0
		/* 0x00004305 7B4C000004         */ IL_0025: ldfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x0000430A 6FA400000A         */ IL_002a: callvirt instance !0 class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::Pop() /* 0A0000A4 */
		/* 0x0000430F 26                 */ IL_002f: pop
		/* 0x00004310 02                 */ IL_0030: ldarg.0
		/* 0x00004311 07                 */ IL_0031: ldloc.1
		/* 0x00004312 28BE000006         */ IL_0032: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CurrentItem(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000BE */
		/* 0x00004317 07                 */ IL_0037: ldloc.1
		/* 0x00004318 06                 */ IL_0038: ldloc.0
		/* 0x00004319 16                 */ IL_0039: ldc.i4.0
		/* 0x0000431A 6FEC000006         */ IL_003a: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnEnter(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem, bool) /* 060000EC */
		/* 0x0000431F 2A                 */ IL_003f: ret
	} // end of method WizardControl::GoBackward

	.method /* 060000CE */ public hidebysig 
		instance void Finish () cil managed 
	{
		// Method begins at RVA 0x432c
		// Header size: 12
		// Code size: 107 (0x6b)
		.maxstack 2
		.locals /* 11000010 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem,
			[1] class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>
		)

		/* 0x0000432C 02                 */ IL_0000: ldarg.0
		/* 0x0000432D 28C3000006         */ IL_0001: call instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanFinish() /* 060000C3 */
		/* 0x00004332 2C62               */ IL_0006: brfalse.s IL_006a
		/* 0x00004334 02                 */ IL_0008: ldarg.0
		/* 0x00004335 28BD000006         */ IL_0009: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000433A 0A                 */ IL_000e: stloc.0
		/* 0x0000433B 06                 */ IL_000f: ldloc.0
		/* 0x0000433C 2C21               */ IL_0010: brfalse.s IL_0033
		/* 0x0000433E 06                 */ IL_0012: ldloc.0
		/* 0x0000433F 6F1C00000A         */ IL_0013: callvirt instance class [mscorlib]System.Type [mscorlib]System.Object::GetType() /* 0A00001C */
		/* 0x00004344 6FA500000A         */ IL_0018: callvirt instance string [mscorlib]System.Reflection.MemberInfo::get_Name() /* 0A0000A5 */
		/* 0x00004349 720B080070         */ IL_001d: ldstr "UserDefinedComp1" /* 7000080B */
		/* 0x0000434E 6FA600000A         */ IL_0022: callvirt instance bool [mscorlib]System.String::Equals(string) /* 0A0000A6 */
		/* 0x00004353 2C0A               */ IL_0027: brfalse.s IL_0033
		/* 0x00004355 06                 */ IL_0029: ldloc.0
		/* 0x00004356 14                 */ IL_002a: ldnull
		/* 0x00004357 6FED000006         */ IL_002b: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnForward(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000ED */
		/* 0x0000435C 2D01               */ IL_0030: brtrue.s IL_0033
		/* 0x0000435E 2A                 */ IL_0032: ret
		/* 0x0000435F 02                 */ IL_0033: ldarg.0
		/* 0x00004360 28BB000006         */ IL_0034: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x00004365 6FA700000A         */ IL_0039: callvirt instance class [mscorlib]System.Collections.Generic.IEnumerator`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::GetEnumerator() /* 0A0000A7 */
		/* 0x0000436A 0B                 */ IL_003e: stloc.1
		/* 0x0000436B 2B0F               */ IL_003f: br.s IL_0050
		/* 0x0000436D 07                 */ IL_0041: ldloc.1
		/* 0x0000436E 6FA800000A         */ IL_0042: callvirt instance !0 class [mscorlib]System.Collections.Generic.IEnumerator`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Current() /* 0A0000A8 */
		/* 0x00004373 6FEF000006         */ IL_0047: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnFinished() /* 060000EF */
		/* 0x00004378 2D02               */ IL_004c: brtrue.s IL_0050
		/* 0x0000437A DE1A               */ IL_004e: leave.s IL_006a
		/* 0x0000437C 07                 */ IL_0050: ldloc.1
		/* 0x0000437D 6F3B00000A         */ IL_0051: callvirt instance bool [mscorlib]System.Collections.IEnumerator::MoveNext() /* 0A00003B */
		/* 0x00004382 2DE9               */ IL_0056: brtrue.s IL_0041
		/* 0x00004384 DE0A               */ IL_0058: leave.s IL_0064
		/* 0x00004386 07                 */ IL_005a: ldloc.1
		/* 0x00004387 2C06               */ IL_005b: brfalse.s IL_0063
		/* 0x00004389 07                 */ IL_005d: ldloc.1
		/* 0x0000438A 6F3C00000A         */ IL_005e: callvirt instance void [mscorlib]System.IDisposable::Dispose() /* 0A00003C */
		/* 0x0000438F DC                 */ IL_0063: endfinally
		/* 0x00004390 02                 */ IL_0064: ldarg.0
		/* 0x00004391 6FD1000006         */ IL_0065: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::OnFinished() /* 060000D1 */
		/* 0x00004396 2A                 */ IL_006a: ret

		.try IL_003f-IL_005a finally IL_005a-IL_0064
	} // end of method WizardControl::Finish

	.method /* 060000CF */ public hidebysig 
		instance void Reset () cil managed 
	{
		// Method begins at RVA 0x43b4
		// Header size: 1
		// Code size: 29 (0x1d)
		.maxstack 8

		/* 0x000043B4 02                 */ IL_0000: ldarg.0
		/* 0x000043B5 02                 */ IL_0001: ldarg.0
		/* 0x000043B6 28BB000006         */ IL_0002: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x000043BB 280400002B         */ IL_0007: call !!0 [System.Core]System.Linq.Enumerable::FirstOrDefault<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>(class [mscorlib]System.Collections.Generic.IEnumerable`1<!!0>) /* 2B000004 */
		/* 0x000043C0 28BE000006         */ IL_000c: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CurrentItem(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem) /* 060000BE */
		/* 0x000043C5 02                 */ IL_0011: ldarg.0
		/* 0x000043C6 7B4C000004         */ IL_0012: ldfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x000043CB 6FA900000A         */ IL_0017: callvirt instance void class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::Clear() /* 0A0000A9 */
		/* 0x000043D0 2A                 */ IL_001c: ret
	} // end of method WizardControl::Reset

	.method /* 060000D0 */ public hidebysig 
		instance void RefreshEnableStatus () cil managed 
	{
		// Method begins at RVA 0x43d4
		// Header size: 12
		// Code size: 232 (0xe8)
		.maxstack 6
		.locals /* 11000011 */ init (
			[0] bool,
			[1] bool,
			[2] bool,
			[3] int32
		)

		/* 0x000043D4 02                 */ IL_0000: ldarg.0
		/* 0x000043D5 28BD000006         */ IL_0001: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x000043DA 2D23               */ IL_0006: brtrue.s IL_002b
		/* 0x000043DC 02                 */ IL_0008: ldarg.0
		/* 0x000043DD 02                 */ IL_0009: ldarg.0
		/* 0x000043DE 02                 */ IL_000a: ldarg.0
		/* 0x000043DF 02                 */ IL_000b: ldarg.0
		/* 0x000043E0 16                 */ IL_000c: ldc.i4.0
		/* 0x000043E1 25                 */ IL_000d: dup
		/* 0x000043E2 0C                 */ IL_000e: stloc.2
		/* 0x000043E3 28C6000006         */ IL_000f: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanCancel(bool) /* 060000C6 */
		/* 0x000043E8 08                 */ IL_0014: ldloc.2
		/* 0x000043E9 25                 */ IL_0015: dup
		/* 0x000043EA 0B                 */ IL_0016: stloc.1
		/* 0x000043EB 28C4000006         */ IL_0017: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanFinish(bool) /* 060000C4 */
		/* 0x000043F0 07                 */ IL_001c: ldloc.1
		/* 0x000043F1 25                 */ IL_001d: dup
		/* 0x000043F2 0A                 */ IL_001e: stloc.0
		/* 0x000043F3 28C0000006         */ IL_001f: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanForward(bool) /* 060000C0 */
		/* 0x000043F8 06                 */ IL_0024: ldloc.0
		/* 0x000043F9 28C2000006         */ IL_0025: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanBackward(bool) /* 060000C2 */
		/* 0x000043FE 2A                 */ IL_002a: ret
		/* 0x000043FF 02                 */ IL_002b: ldarg.0
		/* 0x00004400 02                 */ IL_002c: ldarg.0
		/* 0x00004401 28BD000006         */ IL_002d: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x00004406 6FDF000006         */ IL_0032: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanFinish() /* 060000DF */
		/* 0x0000440B 28C4000006         */ IL_0037: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanFinish(bool) /* 060000C4 */
		/* 0x00004410 02                 */ IL_003c: ldarg.0
		/* 0x00004411 28BB000006         */ IL_003d: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x00004416 02                 */ IL_0042: ldarg.0
		/* 0x00004417 28BD000006         */ IL_0043: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000441C 6FAA00000A         */ IL_0048: callvirt instance bool class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::Contains(!0) /* 0A0000AA */
		/* 0x00004421 2C77               */ IL_004d: brfalse.s IL_00c6
		/* 0x00004423 02                 */ IL_004f: ldarg.0
		/* 0x00004424 28BB000006         */ IL_0050: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x00004429 02                 */ IL_0055: ldarg.0
		/* 0x0000442A 28BD000006         */ IL_0056: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000442F 6FA000000A         */ IL_005b: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::IndexOf(!0) /* 0A0000A0 */
		/* 0x00004434 0D                 */ IL_0060: stloc.3
		/* 0x00004435 02                 */ IL_0061: ldarg.0
		/* 0x00004436 02                 */ IL_0062: ldarg.0
		/* 0x00004437 28BD000006         */ IL_0063: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000443C 6FE5000006         */ IL_0068: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ForwardItem() /* 060000E5 */
		/* 0x00004441 2D10               */ IL_006d: brtrue.s IL_007f
		/* 0x00004443 09                 */ IL_006f: ldloc.3
		/* 0x00004444 02                 */ IL_0070: ldarg.0
		/* 0x00004445 28BB000006         */ IL_0071: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items() /* 060000BB */
		/* 0x0000444A 6FAB00000A         */ IL_0076: callvirt instance int32 class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Count() /* 0A0000AB */
		/* 0x0000444F 17                 */ IL_007b: ldc.i4.1
		/* 0x00004450 59                 */ IL_007c: sub
		/* 0x00004451 2F0D               */ IL_007d: bge.s IL_008c
		/* 0x00004453 02                 */ IL_007f: ldarg.0
		/* 0x00004454 28BD000006         */ IL_0080: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x00004459 6FDB000006         */ IL_0085: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanForward() /* 060000DB */
		/* 0x0000445E 2B01               */ IL_008a: br.s IL_008d
		/* 0x00004460 16                 */ IL_008c: ldc.i4.0
		/* 0x00004461 28C0000006         */ IL_008d: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanForward(bool) /* 060000C0 */
		/* 0x00004466 02                 */ IL_0092: ldarg.0
		/* 0x00004467 02                 */ IL_0093: ldarg.0
		/* 0x00004468 28BD000006         */ IL_0094: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000446D 6FE1000006         */ IL_0099: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanCancel() /* 060000E1 */
		/* 0x00004472 28C6000006         */ IL_009e: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanCancel(bool) /* 060000C6 */
		/* 0x00004477 02                 */ IL_00a3: ldarg.0
		/* 0x00004478 02                 */ IL_00a4: ldarg.0
		/* 0x00004479 7B4C000004         */ IL_00a5: ldfld class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem> AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::_nagivationHistory /* 0400004C */
		/* 0x0000447E 6F9F00000A         */ IL_00aa: callvirt instance int32 class [System]System.Collections.Generic.Stack`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Count() /* 0A00009F */
		/* 0x00004483 16                 */ IL_00af: ldc.i4.0
		/* 0x00004484 310D               */ IL_00b0: ble.s IL_00bf
		/* 0x00004486 02                 */ IL_00b2: ldarg.0
		/* 0x00004487 28BD000006         */ IL_00b3: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x0000448C 6FDD000006         */ IL_00b8: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanBackward() /* 060000DD */
		/* 0x00004491 2B01               */ IL_00bd: br.s IL_00c0
		/* 0x00004493 16                 */ IL_00bf: ldc.i4.0
		/* 0x00004494 28C2000006         */ IL_00c0: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanBackward(bool) /* 060000C2 */
		/* 0x00004499 2A                 */ IL_00c5: ret
		/* 0x0000449A 02                 */ IL_00c6: ldarg.0
		/* 0x0000449B 02                 */ IL_00c7: ldarg.0
		/* 0x0000449C 28BD000006         */ IL_00c8: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x000044A1 6FE5000006         */ IL_00cd: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ForwardItem() /* 060000E5 */
		/* 0x000044A6 2C0D               */ IL_00d2: brfalse.s IL_00e1
		/* 0x000044A8 02                 */ IL_00d4: ldarg.0
		/* 0x000044A9 28BD000006         */ IL_00d5: call instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem() /* 060000BD */
		/* 0x000044AE 6FDB000006         */ IL_00da: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanForward() /* 060000DB */
		/* 0x000044B3 2B01               */ IL_00df: br.s IL_00e2
		/* 0x000044B5 16                 */ IL_00e1: ldc.i4.0
		/* 0x000044B6 28C0000006         */ IL_00e2: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanForward(bool) /* 060000C0 */
		/* 0x000044BB 2A                 */ IL_00e7: ret
	} // end of method WizardControl::RefreshEnableStatus

	.method /* 060000D1 */ family hidebysig newslot virtual 
		instance void OnFinished () cil managed 
	{
		// Method begins at RVA 0x44c8
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000044C8 02                 */ IL_0000: ldarg.0
		/* 0x000044C9 7E5C000004         */ IL_0001: ldsfld class [PresentationCore]System.Windows.RoutedEvent AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::FinishedEvent /* 0400005C */
		/* 0x000044CE 02                 */ IL_0006: ldarg.0
		/* 0x000044CF 737000000A         */ IL_0007: newobj instance void [PresentationCore]System.Windows.RoutedEventArgs::.ctor(class [PresentationCore]System.Windows.RoutedEvent, object) /* 0A000070 */
		/* 0x000044D4 283300000A         */ IL_000c: call instance void [PresentationCore]System.Windows.UIElement::RaiseEvent(class [PresentationCore]System.Windows.RoutedEventArgs) /* 0A000033 */
		/* 0x000044D9 2A                 */ IL_0011: ret
	} // end of method WizardControl::OnFinished

	.method /* 060000D2 */ private hidebysig static 
		void OnWizardControlItemChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x44db
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000044DB 02                 */ IL_0000: ldarg.0
		/* 0x000044DC 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000044E1 6FD0000006         */ IL_0006: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::RefreshEnableStatus() /* 060000D0 */
		/* 0x000044E6 2A                 */ IL_000b: ret
	} // end of method WizardControl::OnWizardControlItemChanged

	.method /* 060000D3 */ private hidebysig static 
		void BackwardCommand_Executed (
			object sender,
			class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x44e8
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x000044E8 02                 */ IL_0000: ldarg.0
		/* 0x000044E9 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000044EE 6FCD000006         */ IL_0006: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::GoBackward() /* 060000CD */
		/* 0x000044F3 2A                 */ IL_000b: ret
	} // end of method WizardControl::BackwardCommand_Executed

	.method /* 060000D4 */ private hidebysig static 
		void BackwardCommand_CanExecute (
			object sender,
			class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x44f8
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 2
		.locals /* 11000012 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl
		)

		/* 0x000044F8 02                 */ IL_0000: ldarg.0
		/* 0x000044F9 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x000044FE 0A                 */ IL_0006: stloc.0
		/* 0x000044FF 03                 */ IL_0007: ldarg.1
		/* 0x00004500 06                 */ IL_0008: ldloc.0
		/* 0x00004501 6FC1000006         */ IL_0009: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanBackward() /* 060000C1 */
		/* 0x00004506 6F9700000A         */ IL_000e: callvirt instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs::set_CanExecute(bool) /* 0A000097 */
		/* 0x0000450B 2A                 */ IL_0013: ret
	} // end of method WizardControl::BackwardCommand_CanExecute

	.method /* 060000D5 */ private hidebysig static 
		void ForwardCommand_Executed (
			object sender,
			class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4518
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00004518 02                 */ IL_0000: ldarg.0
		/* 0x00004519 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x0000451E 6FCC000006         */ IL_0006: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::GoForward() /* 060000CC */
		/* 0x00004523 2A                 */ IL_000b: ret
	} // end of method WizardControl::ForwardCommand_Executed

	.method /* 060000D6 */ private hidebysig static 
		void ForwardCommand_CanExecute (
			object sender,
			class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4528
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 2
		.locals /* 11000012 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl
		)

		/* 0x00004528 02                 */ IL_0000: ldarg.0
		/* 0x00004529 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x0000452E 0A                 */ IL_0006: stloc.0
		/* 0x0000452F 03                 */ IL_0007: ldarg.1
		/* 0x00004530 06                 */ IL_0008: ldloc.0
		/* 0x00004531 6FBF000006         */ IL_0009: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanForward() /* 060000BF */
		/* 0x00004536 6F9700000A         */ IL_000e: callvirt instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs::set_CanExecute(bool) /* 0A000097 */
		/* 0x0000453B 2A                 */ IL_0013: ret
	} // end of method WizardControl::ForwardCommand_CanExecute

	.method /* 060000D7 */ private hidebysig static 
		void FinishCommand_Executed (
			object sender,
			class [PresentationCore]System.Windows.Input.ExecutedRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4548
		// Header size: 1
		// Code size: 12 (0xc)
		.maxstack 8

		/* 0x00004548 02                 */ IL_0000: ldarg.0
		/* 0x00004549 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x0000454E 6FCE000006         */ IL_0006: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::Finish() /* 060000CE */
		/* 0x00004553 2A                 */ IL_000b: ret
	} // end of method WizardControl::FinishCommand_Executed

	.method /* 060000D8 */ private hidebysig static 
		void FinishCommand_CanExecute (
			object sender,
			class [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4558
		// Header size: 12
		// Code size: 20 (0x14)
		.maxstack 2
		.locals /* 11000012 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl
		)

		/* 0x00004558 02                 */ IL_0000: ldarg.0
		/* 0x00004559 7511000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl /* 02000011 */
		/* 0x0000455E 0A                 */ IL_0006: stloc.0
		/* 0x0000455F 03                 */ IL_0007: ldarg.1
		/* 0x00004560 06                 */ IL_0008: ldloc.0
		/* 0x00004561 6FC3000006         */ IL_0009: callvirt instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanFinish() /* 060000C3 */
		/* 0x00004566 6F9700000A         */ IL_000e: callvirt instance void [PresentationCore]System.Windows.Input.CanExecuteRoutedEventArgs::set_CanExecute(bool) /* 0A000097 */
		/* 0x0000456B 2A                 */ IL_0013: ret
	} // end of method WizardControl::FinishCommand_CanExecute

	// Events
	.event /* 14000008 */ [PresentationCore]System.Windows.RoutedEventHandler Finished
	{
		.addon instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::add_Finished(class [PresentationCore]System.Windows.RoutedEventHandler)
		.removeon instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::remove_Finished(class [PresentationCore]System.Windows.RoutedEventHandler)
	}


	// Properties
	.property /* 17000037 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection Items()
	{
		.custom /* 0C00003C */ instance void [System]System.ComponentModel.DesignerSerializationVisibilityAttribute::.ctor(valuetype [System]System.ComponentModel.DesignerSerializationVisibility) = (
			01 00 02 00 00 00 00 00
		)
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_Items()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_Items(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection)
	}
	.property /* 17000038 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem CurrentItem()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CurrentItem()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CurrentItem(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem)
	}
	.property /* 17000039 */ instance bool CanForward()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanForward()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanForward(bool)
	}
	.property /* 1700003A */ instance bool CanBackward()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanBackward()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanBackward(bool)
	}
	.property /* 1700003B */ instance bool CanFinish()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanFinish()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanFinish(bool)
	}
	.property /* 1700003C */ instance bool CanCancel()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::get_CanCancel()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::set_CanCancel(bool)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl

.class /* 02000012 */ public auto ansi AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
	extends [PresentationFramework]System.Windows.Controls.ContentControl
{
	// Fields
	.field /* 0400005D */ private int32 _enteredTimes
	.field /* 0400005E */ public static initonly class [WindowsBase]System.Windows.DependencyProperty TitleProperty
	.field /* 0400005F */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanForwardProperty
	.field /* 04000060 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanBackwardProperty
	.field /* 04000061 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanFinishProperty
	.field /* 04000062 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty CanCancelProperty
	.field /* 04000063 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty UseScrollViewerInsideProperty
	.field /* 04000064 */ public static initonly class [WindowsBase]System.Windows.DependencyProperty ForwardItemProperty
	.field /* 04000065 */ private class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl '<ParentWizard>k__BackingField'
	.custom /* 0C00004A */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.field /* 04000066 */ private bool '<IsEnteredFirstTime>k__BackingField'
	.custom /* 0C00004B */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)

	// Methods
	.method /* 060000D9 */ public hidebysig specialname 
		instance string get_Title () cil managed 
	{
		// Method begins at RVA 0x4578
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00004578 02                 */ IL_0000: ldarg.0
		/* 0x00004579 7E5E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::TitleProperty /* 0400005E */
		/* 0x0000457E 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00004583 745A000001         */ IL_000b: castclass [mscorlib]System.String /* 0100005A */
		/* 0x00004588 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_Title

	.method /* 060000DA */ public hidebysig specialname 
		instance void set_Title (
			string 'value'
		) cil managed 
	{
		// Method begins at RVA 0x458a
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x0000458A 02                 */ IL_0000: ldarg.0
		/* 0x0000458B 7E5E000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::TitleProperty /* 0400005E */
		/* 0x00004590 03                 */ IL_0006: ldarg.1
		/* 0x00004591 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00004596 2A                 */ IL_000c: ret
	} // end of method WizardControlItem::set_Title

	.method /* 060000DB */ public hidebysig specialname 
		instance bool get_CanForward () cil managed 
	{
		// Method begins at RVA 0x4598
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00004598 02                 */ IL_0000: ldarg.0
		/* 0x00004599 7E5F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanForwardProperty /* 0400005F */
		/* 0x0000459E 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000045A3 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x000045A8 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_CanForward

	.method /* 060000DC */ public hidebysig specialname 
		instance void set_CanForward (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x45aa
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000045AA 02                 */ IL_0000: ldarg.0
		/* 0x000045AB 7E5F000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanForwardProperty /* 0400005F */
		/* 0x000045B0 03                 */ IL_0006: ldarg.1
		/* 0x000045B1 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x000045B6 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000045BB 2A                 */ IL_0011: ret
	} // end of method WizardControlItem::set_CanForward

	.method /* 060000DD */ public hidebysig specialname 
		instance bool get_CanBackward () cil managed 
	{
		// Method begins at RVA 0x45bd
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000045BD 02                 */ IL_0000: ldarg.0
		/* 0x000045BE 7E60000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanBackwardProperty /* 04000060 */
		/* 0x000045C3 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000045C8 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x000045CD 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_CanBackward

	.method /* 060000DE */ public hidebysig specialname 
		instance void set_CanBackward (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x45cf
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000045CF 02                 */ IL_0000: ldarg.0
		/* 0x000045D0 7E60000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanBackwardProperty /* 04000060 */
		/* 0x000045D5 03                 */ IL_0006: ldarg.1
		/* 0x000045D6 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x000045DB 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x000045E0 2A                 */ IL_0011: ret
	} // end of method WizardControlItem::set_CanBackward

	.method /* 060000DF */ public hidebysig specialname 
		instance bool get_CanFinish () cil managed 
	{
		// Method begins at RVA 0x45e2
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x000045E2 02                 */ IL_0000: ldarg.0
		/* 0x000045E3 7E61000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanFinishProperty /* 04000061 */
		/* 0x000045E8 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x000045ED A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x000045F2 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_CanFinish

	.method /* 060000E0 */ public hidebysig specialname 
		instance void set_CanFinish (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x45f4
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x000045F4 02                 */ IL_0000: ldarg.0
		/* 0x000045F5 7E61000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanFinishProperty /* 04000061 */
		/* 0x000045FA 03                 */ IL_0006: ldarg.1
		/* 0x000045FB 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004600 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x00004605 2A                 */ IL_0011: ret
	} // end of method WizardControlItem::set_CanFinish

	.method /* 060000E1 */ public hidebysig specialname 
		instance bool get_CanCancel () cil managed 
	{
		// Method begins at RVA 0x4607
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00004607 02                 */ IL_0000: ldarg.0
		/* 0x00004608 7E62000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanCancelProperty /* 04000062 */
		/* 0x0000460D 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00004612 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004617 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_CanCancel

	.method /* 060000E2 */ public hidebysig specialname 
		instance void set_CanCancel (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x4619
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x00004619 02                 */ IL_0000: ldarg.0
		/* 0x0000461A 7E62000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanCancelProperty /* 04000062 */
		/* 0x0000461F 03                 */ IL_0006: ldarg.1
		/* 0x00004620 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004625 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000462A 2A                 */ IL_0011: ret
	} // end of method WizardControlItem::set_CanCancel

	.method /* 060000E3 */ public hidebysig specialname 
		instance bool get_UseScrollViewerInside () cil managed 
	{
		// Method begins at RVA 0x462c
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x0000462C 02                 */ IL_0000: ldarg.0
		/* 0x0000462D 7E63000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::UseScrollViewerInsideProperty /* 04000063 */
		/* 0x00004632 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x00004637 A55F000001         */ IL_000b: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000463C 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_UseScrollViewerInside

	.method /* 060000E4 */ public hidebysig specialname 
		instance void set_UseScrollViewerInside (
			bool 'value'
		) cil managed 
	{
		// Method begins at RVA 0x463e
		// Header size: 1
		// Code size: 18 (0x12)
		.maxstack 8

		/* 0x0000463E 02                 */ IL_0000: ldarg.0
		/* 0x0000463F 7E63000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::UseScrollViewerInsideProperty /* 04000063 */
		/* 0x00004644 03                 */ IL_0006: ldarg.1
		/* 0x00004645 8C5F000001         */ IL_0007: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000464A 282100000A         */ IL_000c: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000464F 2A                 */ IL_0011: ret
	} // end of method WizardControlItem::set_UseScrollViewerInside

	.method /* 060000E5 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem get_ForwardItem () cil managed 
	{
		// Method begins at RVA 0x4651
		// Header size: 1
		// Code size: 17 (0x11)
		.maxstack 8

		/* 0x00004651 02                 */ IL_0000: ldarg.0
		/* 0x00004652 7E64000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::ForwardItemProperty /* 04000064 */
		/* 0x00004657 282000000A         */ IL_0006: call instance object [WindowsBase]System.Windows.DependencyObject::GetValue(class [WindowsBase]System.Windows.DependencyProperty) /* 0A000020 */
		/* 0x0000465C 7412000002         */ IL_000b: castclass AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00004661 2A                 */ IL_0010: ret
	} // end of method WizardControlItem::get_ForwardItem

	.method /* 060000E6 */ public hidebysig specialname 
		instance void set_ForwardItem (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem 'value'
		) cil managed 
	{
		// Method begins at RVA 0x4663
		// Header size: 1
		// Code size: 13 (0xd)
		.maxstack 8

		/* 0x00004663 02                 */ IL_0000: ldarg.0
		/* 0x00004664 7E64000004         */ IL_0001: ldsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::ForwardItemProperty /* 04000064 */
		/* 0x00004669 03                 */ IL_0006: ldarg.1
		/* 0x0000466A 282100000A         */ IL_0007: call instance void [WindowsBase]System.Windows.DependencyObject::SetValue(class [WindowsBase]System.Windows.DependencyProperty, object) /* 0A000021 */
		/* 0x0000466F 2A                 */ IL_000c: ret
	} // end of method WizardControlItem::set_ForwardItem

	.method /* 060000E7 */ public hidebysig specialname 
		instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl get_ParentWizard () cil managed 
	{
		.custom /* 0C00004F */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4671
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004671 02                 */ IL_0000: ldarg.0
		/* 0x00004672 7B65000004         */ IL_0001: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::'<ParentWizard>k__BackingField' /* 04000065 */
		/* 0x00004677 2A                 */ IL_0006: ret
	} // end of method WizardControlItem::get_ParentWizard

	.method /* 060000E8 */ assembly hidebysig specialname 
		instance void set_ParentWizard (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl 'value'
		) cil managed 
	{
		.custom /* 0C000050 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4679
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x00004679 02                 */ IL_0000: ldarg.0
		/* 0x0000467A 03                 */ IL_0001: ldarg.1
		/* 0x0000467B 7D65000004         */ IL_0002: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::'<ParentWizard>k__BackingField' /* 04000065 */
		/* 0x00004680 2A                 */ IL_0007: ret
	} // end of method WizardControlItem::set_ParentWizard

	.method /* 060000E9 */ family hidebysig specialname 
		instance bool get_IsEnteredFirstTime () cil managed 
	{
		.custom /* 0C000051 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x4682
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004682 02                 */ IL_0000: ldarg.0
		/* 0x00004683 7B66000004         */ IL_0001: ldfld bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::'<IsEnteredFirstTime>k__BackingField' /* 04000066 */
		/* 0x00004688 2A                 */ IL_0006: ret
	} // end of method WizardControlItem::get_IsEnteredFirstTime

	.method /* 060000EA */ private hidebysig specialname 
		instance void set_IsEnteredFirstTime (
			bool 'value'
		) cil managed 
	{
		.custom /* 0C000052 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
			01 00 00 00
		)
		// Method begins at RVA 0x468a
		// Header size: 1
		// Code size: 8 (0x8)
		.maxstack 8

		/* 0x0000468A 02                 */ IL_0000: ldarg.0
		/* 0x0000468B 03                 */ IL_0001: ldarg.1
		/* 0x0000468C 7D66000004         */ IL_0002: stfld bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::'<IsEnteredFirstTime>k__BackingField' /* 04000066 */
		/* 0x00004691 2A                 */ IL_0007: ret
	} // end of method WizardControlItem::set_IsEnteredFirstTime

	.method /* 060000EB */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x4694
		// Header size: 12
		// Code size: 401 (0x191)
		.maxstack 6

		/* 0x00004694 722D080070         */ IL_0000: ldstr "Title" /* 7000082D */
		/* 0x00004699 D05A000001         */ IL_0005: ldtoken [mscorlib]System.String /* 0100005A */
		/* 0x0000469E 282400000A         */ IL_000a: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000046A3 D012000002         */ IL_000f: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000046A8 282400000A         */ IL_0014: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000046AD 282700000A         */ IL_0019: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type) /* 0A000027 */
		/* 0x000046B2 805E000004         */ IL_001e: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::TitleProperty /* 0400005E */
		/* 0x000046B7 7227070070         */ IL_0023: ldstr "CanForward" /* 70000727 */
		/* 0x000046BC D05F000001         */ IL_0028: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x000046C1 282400000A         */ IL_002d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000046C6 D012000002         */ IL_0032: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000046CB 282400000A         */ IL_0037: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000046D0 16                 */ IL_003c: ldc.i4.0
		/* 0x000046D1 8C5F000001         */ IL_003d: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x000046D6 14                 */ IL_0042: ldnull
		/* 0x000046D7 FE06F0000006       */ IL_0043: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnCanForwardPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000F0 */
		/* 0x000046DD 732800000A         */ IL_0049: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x000046E2 735300000A         */ IL_004e: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000053 */
		/* 0x000046E7 282600000A         */ IL_0053: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x000046EC 805F000004         */ IL_0058: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanForwardProperty /* 0400005F */
		/* 0x000046F1 723D070070         */ IL_005d: ldstr "CanBackward" /* 7000073D */
		/* 0x000046F6 D05F000001         */ IL_0062: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x000046FB 282400000A         */ IL_0067: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004700 D012000002         */ IL_006c: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00004705 282400000A         */ IL_0071: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000470A 17                 */ IL_0076: ldc.i4.1
		/* 0x0000470B 8C5F000001         */ IL_0077: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004710 14                 */ IL_007c: ldnull
		/* 0x00004711 FE06F1000006       */ IL_007d: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnCanBackwardPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000F1 */
		/* 0x00004717 732800000A         */ IL_0083: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x0000471C 735300000A         */ IL_0088: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000053 */
		/* 0x00004721 282600000A         */ IL_008d: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00004726 8060000004         */ IL_0092: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanBackwardProperty /* 04000060 */
		/* 0x0000472B 7255070070         */ IL_0097: ldstr "CanFinish" /* 70000755 */
		/* 0x00004730 D05F000001         */ IL_009c: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004735 282400000A         */ IL_00a1: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000473A D012000002         */ IL_00a6: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x0000473F 282400000A         */ IL_00ab: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004744 16                 */ IL_00b0: ldc.i4.0
		/* 0x00004745 8C5F000001         */ IL_00b1: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000474A 14                 */ IL_00b6: ldnull
		/* 0x0000474B FE06F2000006       */ IL_00b7: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnCanFinishPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000F2 */
		/* 0x00004751 732800000A         */ IL_00bd: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00004756 735300000A         */ IL_00c2: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000053 */
		/* 0x0000475B 282600000A         */ IL_00c7: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x00004760 8061000004         */ IL_00cc: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanFinishProperty /* 04000061 */
		/* 0x00004765 7269070070         */ IL_00d1: ldstr "CanCancel" /* 70000769 */
		/* 0x0000476A D05F000001         */ IL_00d6: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x0000476F 282400000A         */ IL_00db: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004774 D012000002         */ IL_00e0: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00004779 282400000A         */ IL_00e5: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000477E 17                 */ IL_00ea: ldc.i4.1
		/* 0x0000477F 8C5F000001         */ IL_00eb: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004784 14                 */ IL_00f0: ldnull
		/* 0x00004785 FE06F3000006       */ IL_00f1: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnCanCancelPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000F3 */
		/* 0x0000478B 732800000A         */ IL_00f7: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x00004790 735300000A         */ IL_00fc: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object, class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000053 */
		/* 0x00004795 282600000A         */ IL_0101: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x0000479A 8062000004         */ IL_0106: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::CanCancelProperty /* 04000062 */
		/* 0x0000479F 7239080070         */ IL_010b: ldstr "UseScrollViewerInside" /* 70000839 */
		/* 0x000047A4 D05F000001         */ IL_0110: ldtoken [mscorlib]System.Boolean /* 0100005F */
		/* 0x000047A9 282400000A         */ IL_0115: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000047AE D012000002         */ IL_011a: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000047B3 282400000A         */ IL_011f: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000047B8 16                 */ IL_0124: ldc.i4.0
		/* 0x000047B9 8C5F000001         */ IL_0125: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x000047BE 732500000A         */ IL_012a: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x000047C3 282600000A         */ IL_012f: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x000047C8 8063000004         */ IL_0134: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::UseScrollViewerInsideProperty /* 04000063 */
		/* 0x000047CD 7265080070         */ IL_0139: ldstr "ForwardItem" /* 70000865 */
		/* 0x000047D2 D012000002         */ IL_013e: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000047D7 282400000A         */ IL_0143: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000047DC D012000002         */ IL_0148: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000047E1 282400000A         */ IL_014d: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000047E6 14                 */ IL_0152: ldnull
		/* 0x000047E7 FE06F4000006       */ IL_0153: ldftn void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::OnForwardItemPropertyChanged(class [WindowsBase]System.Windows.DependencyObject, valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs) /* 060000F4 */
		/* 0x000047ED 732800000A         */ IL_0159: newobj instance void [WindowsBase]System.Windows.PropertyChangedCallback::.ctor(object, native int) /* 0A000028 */
		/* 0x000047F2 732900000A         */ IL_015e: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(class [WindowsBase]System.Windows.PropertyChangedCallback) /* 0A000029 */
		/* 0x000047F7 282600000A         */ IL_0163: call class [WindowsBase]System.Windows.DependencyProperty [WindowsBase]System.Windows.DependencyProperty::Register(string, class [mscorlib]System.Type, class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A000026 */
		/* 0x000047FC 8064000004         */ IL_0168: stsfld class [WindowsBase]System.Windows.DependencyProperty AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::ForwardItemProperty /* 04000064 */
		/* 0x00004801 7E2E00000A         */ IL_016d: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::DefaultStyleKeyProperty /* 0A00002E */
		/* 0x00004806 D012000002         */ IL_0172: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x0000480B 282400000A         */ IL_0177: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x00004810 D012000002         */ IL_017c: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00004815 282400000A         */ IL_0181: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x0000481A 732500000A         */ IL_0186: newobj instance void [PresentationFramework]System.Windows.FrameworkPropertyMetadata::.ctor(object) /* 0A000025 */
		/* 0x0000481F 6F2F00000A         */ IL_018b: callvirt instance void [WindowsBase]System.Windows.DependencyProperty::OverrideMetadata(class [mscorlib]System.Type, class [WindowsBase]System.Windows.PropertyMetadata) /* 0A00002F */
		/* 0x00004824 2A                 */ IL_0190: ret
	} // end of method WizardControlItem::.cctor

	.method /* 060000EC */ famorassem hidebysig newslot virtual 
		instance void OnEnter (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem previousItem,
			bool positiveDirection
		) cil managed 
	{
		// Method begins at RVA 0x4831
		// Header size: 1
		// Code size: 30 (0x1e)
		.maxstack 8

		/* 0x00004831 02                 */ IL_0000: ldarg.0
		/* 0x00004832 02                 */ IL_0001: ldarg.0
		/* 0x00004833 7B5D000004         */ IL_0002: ldfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::_enteredTimes /* 0400005D */
		/* 0x00004838 16                 */ IL_0007: ldc.i4.0
		/* 0x00004839 FE01               */ IL_0008: ceq
		/* 0x0000483B 28EA000006         */ IL_000a: call instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_IsEnteredFirstTime(bool) /* 060000EA */
		/* 0x00004840 02                 */ IL_000f: ldarg.0
		/* 0x00004841 02                 */ IL_0010: ldarg.0
		/* 0x00004842 7B5D000004         */ IL_0011: ldfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::_enteredTimes /* 0400005D */
		/* 0x00004847 17                 */ IL_0016: ldc.i4.1
		/* 0x00004848 58                 */ IL_0017: add
		/* 0x00004849 7D5D000004         */ IL_0018: stfld int32 AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::_enteredTimes /* 0400005D */
		/* 0x0000484E 2A                 */ IL_001d: ret
	} // end of method WizardControlItem::OnEnter

	.method /* 060000ED */ famorassem hidebysig newslot virtual 
		instance bool OnForward (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem targetItem
		) cil managed 
	{
		// Method begins at RVA 0x4850
		// Header size: 1
		// Code size: 2 (0x2)
		.maxstack 8

		/* 0x00004850 17                 */ IL_0000: ldc.i4.1
		/* 0x00004851 2A                 */ IL_0001: ret
	} // end of method WizardControlItem::OnForward

	.method /* 060000EE */ famorassem hidebysig newslot virtual 
		instance bool OnBackward (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem targetItem
		) cil managed 
	{
		// Method begins at RVA 0x4850
		// Header size: 1
		// Code size: 2 (0x2)
		.maxstack 8

		/* 0x00004850 17                 */ IL_0000: ldc.i4.1
		/* 0x00004851 2A                 */ IL_0001: ret
	} // end of method WizardControlItem::OnBackward

	.method /* 060000EF */ famorassem hidebysig newslot virtual 
		instance bool OnFinished () cil managed 
	{
		// Method begins at RVA 0x4850
		// Header size: 1
		// Code size: 2 (0x2)
		.maxstack 8

		/* 0x00004850 17                 */ IL_0000: ldc.i4.1
		/* 0x00004851 2A                 */ IL_0001: ret
	} // end of method WizardControlItem::OnFinished

	.method /* 060000F0 */ private hidebysig static 
		void OnCanForwardPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x4854
		// Header size: 12
		// Code size: 27 (0x1b)
		.maxstack 1
		.locals /* 11000013 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x00004854 02                 */ IL_0000: ldarg.0
		/* 0x00004855 7512000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x0000485A 0A                 */ IL_0006: stloc.0
		/* 0x0000485B 06                 */ IL_0007: ldloc.0
		/* 0x0000485C 6FE7000006         */ IL_0008: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x00004861 2C0B               */ IL_000d: brfalse.s IL_001a
		/* 0x00004863 06                 */ IL_000f: ldloc.0
		/* 0x00004864 6FE7000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x00004869 6FD0000006         */ IL_0015: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::RefreshEnableStatus() /* 060000D0 */
		/* 0x0000486E 2A                 */ IL_001a: ret
	} // end of method WizardControlItem::OnCanForwardPropertyChanged

	.method /* 060000F1 */ private hidebysig static 
		void OnCanBackwardPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x487c
		// Header size: 12
		// Code size: 27 (0x1b)
		.maxstack 1
		.locals /* 11000013 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x0000487C 02                 */ IL_0000: ldarg.0
		/* 0x0000487D 7512000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x00004882 0A                 */ IL_0006: stloc.0
		/* 0x00004883 06                 */ IL_0007: ldloc.0
		/* 0x00004884 6FE7000006         */ IL_0008: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x00004889 2C0B               */ IL_000d: brfalse.s IL_001a
		/* 0x0000488B 06                 */ IL_000f: ldloc.0
		/* 0x0000488C 6FE7000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x00004891 6FD0000006         */ IL_0015: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::RefreshEnableStatus() /* 060000D0 */
		/* 0x00004896 2A                 */ IL_001a: ret
	} // end of method WizardControlItem::OnCanBackwardPropertyChanged

	.method /* 060000F2 */ private hidebysig static 
		void OnCanFinishPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x48a4
		// Header size: 12
		// Code size: 27 (0x1b)
		.maxstack 1
		.locals /* 11000013 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x000048A4 02                 */ IL_0000: ldarg.0
		/* 0x000048A5 7512000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000048AA 0A                 */ IL_0006: stloc.0
		/* 0x000048AB 06                 */ IL_0007: ldloc.0
		/* 0x000048AC 6FE7000006         */ IL_0008: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x000048B1 2C0B               */ IL_000d: brfalse.s IL_001a
		/* 0x000048B3 06                 */ IL_000f: ldloc.0
		/* 0x000048B4 6FE7000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x000048B9 6FD0000006         */ IL_0015: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::RefreshEnableStatus() /* 060000D0 */
		/* 0x000048BE 2A                 */ IL_001a: ret
	} // end of method WizardControlItem::OnCanFinishPropertyChanged

	.method /* 060000F3 */ private hidebysig static 
		void OnCanCancelPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x48cc
		// Header size: 12
		// Code size: 27 (0x1b)
		.maxstack 1
		.locals /* 11000013 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x000048CC 02                 */ IL_0000: ldarg.0
		/* 0x000048CD 7512000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000048D2 0A                 */ IL_0006: stloc.0
		/* 0x000048D3 06                 */ IL_0007: ldloc.0
		/* 0x000048D4 6FE7000006         */ IL_0008: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x000048D9 2C0B               */ IL_000d: brfalse.s IL_001a
		/* 0x000048DB 06                 */ IL_000f: ldloc.0
		/* 0x000048DC 6FE7000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x000048E1 6FD0000006         */ IL_0015: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::RefreshEnableStatus() /* 060000D0 */
		/* 0x000048E6 2A                 */ IL_001a: ret
	} // end of method WizardControlItem::OnCanCancelPropertyChanged

	.method /* 060000F4 */ private hidebysig static 
		void OnForwardItemPropertyChanged (
			class [WindowsBase]System.Windows.DependencyObject d,
			valuetype [WindowsBase]System.Windows.DependencyPropertyChangedEventArgs e
		) cil managed 
	{
		// Method begins at RVA 0x48f4
		// Header size: 12
		// Code size: 27 (0x1b)
		.maxstack 1
		.locals /* 11000013 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem
		)

		/* 0x000048F4 02                 */ IL_0000: ldarg.0
		/* 0x000048F5 7512000002         */ IL_0001: isinst AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem /* 02000012 */
		/* 0x000048FA 0A                 */ IL_0006: stloc.0
		/* 0x000048FB 06                 */ IL_0007: ldloc.0
		/* 0x000048FC 6FE7000006         */ IL_0008: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x00004901 2C0B               */ IL_000d: brfalse.s IL_001a
		/* 0x00004903 06                 */ IL_000f: ldloc.0
		/* 0x00004904 6FE7000006         */ IL_0010: callvirt instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard() /* 060000E7 */
		/* 0x00004909 6FD0000006         */ IL_0015: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl::RefreshEnableStatus() /* 060000D0 */
		/* 0x0000490E 2A                 */ IL_001a: ret
	} // end of method WizardControlItem::OnForwardItemPropertyChanged

	.method /* 060000F5 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x35c0
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x000035C0 02                 */ IL_0000: ldarg.0
		/* 0x000035C1 287300000A         */ IL_0001: call instance void [PresentationFramework]System.Windows.Controls.ContentControl::.ctor() /* 0A000073 */
		/* 0x000035C6 2A                 */ IL_0006: ret
	} // end of method WizardControlItem::.ctor

	// Properties
	.property /* 1700003D */ instance string Title()
	{
		.get instance string AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_Title()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_Title(string)
	}
	.property /* 1700003E */ instance bool CanForward()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanForward()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_CanForward(bool)
	}
	.property /* 1700003F */ instance bool CanBackward()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanBackward()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_CanBackward(bool)
	}
	.property /* 17000040 */ instance bool CanFinish()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanFinish()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_CanFinish(bool)
	}
	.property /* 17000041 */ instance bool CanCancel()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_CanCancel()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_CanCancel(bool)
	}
	.property /* 17000042 */ instance bool UseScrollViewerInside()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_UseScrollViewerInside()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_UseScrollViewerInside(bool)
	}
	.property /* 17000043 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem ForwardItem()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ForwardItem()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_ForwardItem(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem)
	}
	.property /* 17000044 */ instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl ParentWizard()
	{
		.get instance class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_ParentWizard()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_ParentWizard(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl)
	}
	.property /* 17000045 */ instance bool IsEnteredFirstTime()
	{
		.get instance bool AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::get_IsEnteredFirstTime()
		.set instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_IsEnteredFirstTime(bool)
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem

.class /* 02000013 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection
	extends class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>
{
	// Fields
	.field /* 04000067 */ private initonly class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl _parentWizard

	// Methods
	.method /* 060000F6 */ public hidebysig specialname rtspecialname 
		instance void .ctor (
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl parentWizard
		) cil managed 
	{
		// Method begins at RVA 0x491b
		// Header size: 1
		// Code size: 28 (0x1c)
		.maxstack 8

		/* 0x0000491B 02                 */ IL_0000: ldarg.0
		/* 0x0000491C 28AC00000A         */ IL_0001: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::.ctor() /* 0A0000AC */
		/* 0x00004921 03                 */ IL_0006: ldarg.1
		/* 0x00004922 2D0B               */ IL_0007: brtrue.s IL_0014
		/* 0x00004924 727D080070         */ IL_0009: ldstr "parentWizard" /* 7000087D */
		/* 0x00004929 734500000A         */ IL_000e: newobj instance void [mscorlib]System.ArgumentNullException::.ctor(string) /* 0A000045 */
		/* 0x0000492E 7A                 */ IL_0013: throw
		/* 0x0000492F 02                 */ IL_0014: ldarg.0
		/* 0x00004930 03                 */ IL_0015: ldarg.1
		/* 0x00004931 7D67000004         */ IL_0016: stfld class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection::_parentWizard /* 04000067 */
		/* 0x00004936 2A                 */ IL_001b: ret
	} // end of method WizardControlItemCollection::.ctor

	.method /* 060000F7 */ family hidebysig virtual 
		instance void InsertItem (
			int32 index,
			class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem item
		) cil managed 
	{
		// Method begins at RVA 0x4938
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00004938 04                 */ IL_0000: ldarg.2
		/* 0x00004939 02                 */ IL_0001: ldarg.0
		/* 0x0000493A 7B67000004         */ IL_0002: ldfld class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection::_parentWizard /* 04000067 */
		/* 0x0000493F 6FE8000006         */ IL_0007: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_ParentWizard(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl) /* 060000E8 */
		/* 0x00004944 02                 */ IL_000c: ldarg.0
		/* 0x00004945 03                 */ IL_000d: ldarg.1
		/* 0x00004946 04                 */ IL_000e: ldarg.2
		/* 0x00004947 28AD00000A         */ IL_000f: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::InsertItem(int32, !0) /* 0A0000AD */
		/* 0x0000494C 2A                 */ IL_0014: ret
	} // end of method WizardControlItemCollection::InsertItem

	.method /* 060000F8 */ family hidebysig virtual 
		instance void RemoveItem (
			int32 index
		) cil managed 
	{
		// Method begins at RVA 0x494e
		// Header size: 1
		// Code size: 26 (0x1a)
		.maxstack 8

		/* 0x0000494E 02                 */ IL_0000: ldarg.0
		/* 0x0000494F 28AE00000A         */ IL_0001: call instance class [mscorlib]System.Collections.Generic.IList`1<!0> class [mscorlib]System.Collections.ObjectModel.Collection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Items() /* 0A0000AE */
		/* 0x00004954 03                 */ IL_0006: ldarg.1
		/* 0x00004955 6FAF00000A         */ IL_0007: callvirt instance !0 class [mscorlib]System.Collections.Generic.IList`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::get_Item(int32) /* 0A0000AF */
		/* 0x0000495A 14                 */ IL_000c: ldnull
		/* 0x0000495B 6FE8000006         */ IL_000d: callvirt instance void AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem::set_ParentWizard(class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControl) /* 060000E8 */
		/* 0x00004960 02                 */ IL_0012: ldarg.0
		/* 0x00004961 03                 */ IL_0013: ldarg.1
		/* 0x00004962 28B000000A         */ IL_0014: call instance void class [System]System.Collections.ObjectModel.ObservableCollection`1<class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItem>::RemoveItem(int32) /* 0A0000B0 */
		/* 0x00004967 2A                 */ IL_0019: ret
	} // end of method WizardControlItemCollection::RemoveItem

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.WizardControlItemCollection

.class /* 02000014 */ private auto ansi sealed beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings
	extends [System]System.Configuration.ApplicationSettingsBase
{
	.custom /* 0C000027 */ instance void [mscorlib]System.Runtime.CompilerServices.CompilerGeneratedAttribute::.ctor() = (
		01 00 00 00
	)
	.custom /* 0C000028 */ instance void [System]System.CodeDom.Compiler.GeneratedCodeAttribute::.ctor(string, string) = (
		01 00 4b 4d 69 63 72 6f 73 6f 66 74 2e 56 69 73
		75 61 6c 53 74 75 64 69 6f 2e 45 64 69 74 6f 72
		73 2e 53 65 74 74 69 6e 67 73 44 65 73 69 67 6e
		65 72 2e 53 65 74 74 69 6e 67 73 53 69 6e 67 6c
		65 46 69 6c 65 47 65 6e 65 72 61 74 6f 72 09 31
		36 2e 31 30 2e 30 2e 30 00 00
	)
	// Fields
	.field /* 04000068 */ private static class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings defaultInstance

	// Methods
	.method /* 060000F9 */ public hidebysig specialname static 
		class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings get_Default () cil managed 
	{
		// Method begins at RVA 0x4969
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00004969 7E68000004         */ IL_0000: ldsfld class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings::defaultInstance /* 04000068 */
		/* 0x0000496E 2A                 */ IL_0005: ret
	} // end of method Settings::get_Default

	.method /* 060000FA */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x4970
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00004970 02                 */ IL_0000: ldarg.0
		/* 0x00004971 28B100000A         */ IL_0001: call instance void [System]System.Configuration.ApplicationSettingsBase::.ctor() /* 0A0000B1 */
		/* 0x00004976 2A                 */ IL_0006: ret
	} // end of method Settings::.ctor

	.method /* 060000FB */ private hidebysig specialname rtspecialname static 
		void .cctor () cil managed 
	{
		// Method begins at RVA 0x4978
		// Header size: 1
		// Code size: 21 (0x15)
		.maxstack 8

		/* 0x00004978 73FA000006         */ IL_0000: newobj instance void AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings::.ctor() /* 060000FA */
		/* 0x0000497D 28B200000A         */ IL_0005: call class [System]System.Configuration.SettingsBase [System]System.Configuration.SettingsBase::Synchronized(class [System]System.Configuration.SettingsBase) /* 0A0000B2 */
		/* 0x00004982 7414000002         */ IL_000a: castclass AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings /* 02000014 */
		/* 0x00004987 8068000004         */ IL_000f: stsfld class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings::defaultInstance /* 04000068 */
		/* 0x0000498C 2A                 */ IL_0014: ret
	} // end of method Settings::.cctor

	// Properties
	.property /* 17000046 */ class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings Default()
	{
		.get class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings::get_Default()
	}

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Properties.Settings

.class /* 02000015 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Converters.DropdownPopupWidthConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IValueConverter
{
	.custom /* 0C00002A */ instance void [PresentationFramework]System.Windows.Data.ValueConversionAttribute::.ctor(class [mscorlib]System.Type, class [mscorlib]System.Type) = (
		01 00 59 53 79 73 74 65 6d 2e 49 6e 74 33 32 2c
		20 6d 73 63 6f 72 6c 69 62 2c 20 56 65 72 73 69
		6f 6e 3d 34 2e 30 2e 30 2e 30 2c 20 43 75 6c 74
		75 72 65 3d 6e 65 75 74 72 61 6c 2c 20 50 75 62
		6c 69 63 4b 65 79 54 6f 6b 65 6e 3d 62 37 37 61
		35 63 35 36 31 39 33 34 65 30 38 39 5a 53 79 73
		74 65 6d 2e 44 6f 75 62 6c 65 2c 20 6d 73 63 6f
		72 6c 69 62 2c 20 56 65 72 73 69 6f 6e 3d 34 2e
		30 2e 30 2e 30 2c 20 43 75 6c 74 75 72 65 3d 6e
		65 75 74 72 61 6c 2c 20 50 75 62 6c 69 63 4b 65
		79 54 6f 6b 65 6e 3d 62 37 37 61 35 63 35 36 31
		39 33 34 65 30 38 39 00 00
	)
	// Methods
	.method /* 060000FC */ public final hidebysig newslot virtual 
		instance object Convert (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4990
		// Header size: 12
		// Code size: 105 (0x69)
		.maxstack 3
		.locals /* 11000014 */ init (
			[0] valuetype [mscorlib]System.Nullable`1<int32>,
			[1] int32
		)

		/* 0x00004990 03                 */ IL_0000: ldarg.1
		/* 0x00004991 7EB300000A         */ IL_0001: ldsfld object [WindowsBase]System.Windows.DependencyProperty::UnsetValue /* 0A0000B3 */
		/* 0x00004996 2E52               */ IL_0006: beq.s IL_005a
		/* 0x00004998 03                 */ IL_0008: ldarg.1
		/* 0x00004999 750F00001B         */ IL_0009: isinst valuetype [mscorlib]System.Nullable`1<int32> /* 1B00000F */
		/* 0x0000499E A50F00001B         */ IL_000e: unbox.any valuetype [mscorlib]System.Nullable`1<int32> /* 1B00000F */
		/* 0x000049A3 0A                 */ IL_0013: stloc.0
		/* 0x000049A4 1200               */ IL_0014: ldloca.s 0
		/* 0x000049A6 28B400000A         */ IL_0016: call instance bool valuetype [mscorlib]System.Nullable`1<int32>::get_HasValue() /* 0A0000B4 */
		/* 0x000049AB 2C3D               */ IL_001b: brfalse.s IL_005a
		/* 0x000049AD 1200               */ IL_001d: ldloca.s 0
		/* 0x000049AF 28B500000A         */ IL_001f: call instance !0 valuetype [mscorlib]System.Nullable`1<int32>::get_Value() /* 0A0000B5 */
		/* 0x000049B4 6C                 */ IL_0024: conv.r8
		/* 0x000049B5 28B600000A         */ IL_0025: call float64 [mscorlib]System.Math::Sqrt(float64) /* 0A0000B6 */
		/* 0x000049BA 69                 */ IL_002a: conv.i4
		/* 0x000049BB 0B                 */ IL_002b: stloc.1
		/* 0x000049BC 7E6B00000A         */ IL_002c: ldsfld class [WindowsBase]System.Windows.DependencyProperty [PresentationFramework]System.Windows.FrameworkElement::MinWidthProperty /* 0A00006B */
		/* 0x000049C1 D00E000002         */ IL_0031: ldtoken AspenTech.AspenPlus.ModelLibrary.Controls.OptionButton /* 0200000E */
		/* 0x000049C6 282400000A         */ IL_0036: call class [mscorlib]System.Type [mscorlib]System.Type::GetTypeFromHandle(valuetype [mscorlib]System.RuntimeTypeHandle) /* 0A000024 */
		/* 0x000049CB 6FB700000A         */ IL_003b: callvirt instance class [WindowsBase]System.Windows.PropertyMetadata [WindowsBase]System.Windows.DependencyProperty::GetMetadata(class [mscorlib]System.Type) /* 0A0000B7 */
		/* 0x000049D0 6FB800000A         */ IL_0040: callvirt instance object [WindowsBase]System.Windows.PropertyMetadata::get_DefaultValue() /* 0A0000B8 */
		/* 0x000049D5 A56D000001         */ IL_0045: unbox.any [mscorlib]System.Double /* 0100006D */
		/* 0x000049DA 07                 */ IL_004a: ldloc.1
		/* 0x000049DB 6C                 */ IL_004b: conv.r8
		/* 0x000049DC 5A                 */ IL_004c: mul
		/* 0x000049DD 07                 */ IL_004d: ldloc.1
		/* 0x000049DE 18                 */ IL_004e: ldc.i4.2
		/* 0x000049DF 5A                 */ IL_004f: mul
		/* 0x000049E0 18                 */ IL_0050: ldc.i4.2
		/* 0x000049E1 5A                 */ IL_0051: mul
		/* 0x000049E2 6C                 */ IL_0052: conv.r8
		/* 0x000049E3 58                 */ IL_0053: add
		/* 0x000049E4 8C6D000001         */ IL_0054: box [mscorlib]System.Double /* 0100006D */
		/* 0x000049E9 2A                 */ IL_0059: ret
		/* 0x000049EA 230000000000000000 */ IL_005a: ldc.r8 0.0
		/* 0x000049F3 8C6D000001         */ IL_0063: box [mscorlib]System.Double /* 0100006D */
		/* 0x000049F8 2A                 */ IL_0068: ret
	} // end of method DropdownPopupWidthConverter::Convert

	.method /* 060000FD */ public final hidebysig newslot virtual 
		instance object ConvertBack (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a05
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00004A05 73B900000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A0000B9 */
		/* 0x00004A0A 7A                 */ IL_0005: throw
	} // end of method DropdownPopupWidthConverter::ConvertBack

	.method /* 060000FE */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3379
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003379 02                 */ IL_0000: ldarg.0
		/* 0x0000337A 286A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00006A */
		/* 0x0000337F 2A                 */ IL_0006: ret
	} // end of method DropdownPopupWidthConverter::.ctor

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Converters.DropdownPopupWidthConverter

.class /* 02000016 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Converters.ExpanderVisibilityConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IValueConverter
{
	.custom /* 0C00002C */ instance void [PresentationFramework]System.Windows.Data.ValueConversionAttribute::.ctor(class [mscorlib]System.Type, class [mscorlib]System.Type) = (
		01 00 59 53 79 73 74 65 6d 2e 49 6e 74 33 32 2c
		20 6d 73 63 6f 72 6c 69 62 2c 20 56 65 72 73 69
		6f 6e 3d 34 2e 30 2e 30 2e 30 2c 20 43 75 6c 74
		75 72 65 3d 6e 65 75 74 72 61 6c 2c 20 50 75 62
		6c 69 63 4b 65 79 54 6f 6b 65 6e 3d 62 37 37 61
		35 63 35 36 31 39 33 34 65 30 38 39 6e 53 79 73
		74 65 6d 2e 57 69 6e 64 6f 77 73 2e 56 69 73 69
		62 69 6c 69 74 79 2c 20 50 72 65 73 65 6e 74 61
		74 69 6f 6e 43 6f 72 65 2c 20 56 65 72 73 69 6f
		6e 3d 34 2e 30 2e 30 2e 30 2c 20 43 75 6c 74 75
		72 65 3d 6e 65 75 74 72 61 6c 2c 20 50 75 62 6c
		69 63 4b 65 79 54 6f 6b 65 6e 3d 33 31 62 66 33
		38 35 36 61 64 33 36 34 65 33 35 00 00
	)
	// Methods
	.method /* 060000FF */ public final hidebysig newslot virtual 
		instance object Convert (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a0c
		// Header size: 12
		// Code size: 56 (0x38)
		.maxstack 2
		.locals /* 11000015 */ init (
			[0] valuetype [mscorlib]System.Nullable`1<int32>
		)

		/* 0x00004A0C 03                 */ IL_0000: ldarg.1
		/* 0x00004A0D 7EB300000A         */ IL_0001: ldsfld object [WindowsBase]System.Windows.DependencyProperty::UnsetValue /* 0A0000B3 */
		/* 0x00004A12 2E29               */ IL_0006: beq.s IL_0031
		/* 0x00004A14 03                 */ IL_0008: ldarg.1
		/* 0x00004A15 750F00001B         */ IL_0009: isinst valuetype [mscorlib]System.Nullable`1<int32> /* 1B00000F */
		/* 0x00004A1A A50F00001B         */ IL_000e: unbox.any valuetype [mscorlib]System.Nullable`1<int32> /* 1B00000F */
		/* 0x00004A1F 0A                 */ IL_0013: stloc.0
		/* 0x00004A20 1200               */ IL_0014: ldloca.s 0
		/* 0x00004A22 28B400000A         */ IL_0016: call instance bool valuetype [mscorlib]System.Nullable`1<int32>::get_HasValue() /* 0A0000B4 */
		/* 0x00004A27 2C14               */ IL_001b: brfalse.s IL_0031
		/* 0x00004A29 1200               */ IL_001d: ldloca.s 0
		/* 0x00004A2B 28B500000A         */ IL_001f: call instance !0 valuetype [mscorlib]System.Nullable`1<int32>::get_Value() /* 0A0000B5 */
		/* 0x00004A30 17                 */ IL_0024: ldc.i4.1
		/* 0x00004A31 3003               */ IL_0025: bgt.s IL_002a
		/* 0x00004A33 18                 */ IL_0027: ldc.i4.2
		/* 0x00004A34 2B01               */ IL_0028: br.s IL_002b
		/* 0x00004A36 16                 */ IL_002a: ldc.i4.0
		/* 0x00004A37 8C49000001         */ IL_002b: box [PresentationCore]System.Windows.Visibility /* 01000049 */
		/* 0x00004A3C 2A                 */ IL_0030: ret
		/* 0x00004A3D 18                 */ IL_0031: ldc.i4.2
		/* 0x00004A3E 8C49000001         */ IL_0032: box [PresentationCore]System.Windows.Visibility /* 01000049 */
		/* 0x00004A43 2A                 */ IL_0037: ret
	} // end of method ExpanderVisibilityConverter::Convert

	.method /* 06000100 */ public final hidebysig newslot virtual 
		instance object ConvertBack (
			object 'value',
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a05
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00004A05 73B900000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A0000B9 */
		/* 0x00004A0A 7A                 */ IL_0005: throw
	} // end of method ExpanderVisibilityConverter::ConvertBack

	.method /* 06000101 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3379
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003379 02                 */ IL_0000: ldarg.0
		/* 0x0000337A 286A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00006A */
		/* 0x0000337F 2A                 */ IL_0006: ret
	} // end of method ExpanderVisibilityConverter::.ctor

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Converters.ExpanderVisibilityConverter

.class /* 02000017 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Converters.PopupIconIsCheckedConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IMultiValueConverter
{
	// Methods
	.method /* 06000102 */ public final hidebysig newslot virtual 
		instance object Convert (
			object[] values,
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a50
		// Header size: 12
		// Code size: 47 (0x2f)
		.maxstack 3
		.locals /* 11000016 */ init (
			[0] object,
			[1] object
		)

		/* 0x00004A50 03                 */ IL_0000: ldarg.1
		/* 0x00004A51 2C25               */ IL_0001: brfalse.s IL_0028
		/* 0x00004A53 03                 */ IL_0003: ldarg.1
		/* 0x00004A54 8E                 */ IL_0004: ldlen
		/* 0x00004A55 69                 */ IL_0005: conv.i4
		/* 0x00004A56 19                 */ IL_0006: ldc.i4.3
		/* 0x00004A57 331F               */ IL_0007: bne.un.s IL_0028
		/* 0x00004A59 03                 */ IL_0009: ldarg.1
		/* 0x00004A5A 16                 */ IL_000a: ldc.i4.0
		/* 0x00004A5B 9A                 */ IL_000b: ldelem.ref
		/* 0x00004A5C A55F000001         */ IL_000c: unbox.any [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004A61 03                 */ IL_0011: ldarg.1
		/* 0x00004A62 17                 */ IL_0012: ldc.i4.1
		/* 0x00004A63 9A                 */ IL_0013: ldelem.ref
		/* 0x00004A64 0A                 */ IL_0014: stloc.0
		/* 0x00004A65 03                 */ IL_0015: ldarg.1
		/* 0x00004A66 18                 */ IL_0016: ldc.i4.2
		/* 0x00004A67 9A                 */ IL_0017: ldelem.ref
		/* 0x00004A68 0B                 */ IL_0018: stloc.1
		/* 0x00004A69 2C06               */ IL_0019: brfalse.s IL_0021
		/* 0x00004A6B 06                 */ IL_001b: ldloc.0
		/* 0x00004A6C 07                 */ IL_001c: ldloc.1
		/* 0x00004A6D FE01               */ IL_001d: ceq
		/* 0x00004A6F 2B01               */ IL_001f: br.s IL_0022
		/* 0x00004A71 16                 */ IL_0021: ldc.i4.0
		/* 0x00004A72 8C5F000001         */ IL_0022: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004A77 2A                 */ IL_0027: ret
		/* 0x00004A78 16                 */ IL_0028: ldc.i4.0
		/* 0x00004A79 8C5F000001         */ IL_0029: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004A7E 2A                 */ IL_002e: ret
	} // end of method PopupIconIsCheckedConverter::Convert

	.method /* 06000103 */ public final hidebysig newslot virtual 
		instance object[] ConvertBack (
			object 'value',
			class [mscorlib]System.Type[] targetTypes,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a05
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00004A05 73B900000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A0000B9 */
		/* 0x00004A0A 7A                 */ IL_0005: throw
	} // end of method PopupIconIsCheckedConverter::ConvertBack

	.method /* 06000104 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3379
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003379 02                 */ IL_0000: ldarg.0
		/* 0x0000337A 286A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00006A */
		/* 0x0000337F 2A                 */ IL_0006: ret
	} // end of method PopupIconIsCheckedConverter::.ctor

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Converters.PopupIconIsCheckedConverter

.class /* 02000018 */ public auto ansi beforefieldinit AspenTech.AspenPlus.ModelLibrary.Controls.Converters.StreamIsCheckedConverter
	extends [mscorlib]System.Object
	implements [PresentationFramework]System.Windows.Data.IMultiValueConverter
{
	// Methods
	.method /* 06000105 */ public final hidebysig newslot virtual 
		instance object Convert (
			object[] values,
			class [mscorlib]System.Type targetType,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a8c
		// Header size: 12
		// Code size: 50 (0x32)
		.maxstack 2
		.locals /* 11000017 */ init (
			[0] class AspenTech.AspenPlus.ModelLibrary.Controls.Model,
			[1] class AspenTech.AspenPlus.ModelLibrary.Controls.Model
		)

		/* 0x00004A8C 03                 */ IL_0000: ldarg.1
		/* 0x00004A8D 2C28               */ IL_0001: brfalse.s IL_002b
		/* 0x00004A8F 03                 */ IL_0003: ldarg.1
		/* 0x00004A90 8E                 */ IL_0004: ldlen
		/* 0x00004A91 69                 */ IL_0005: conv.i4
		/* 0x00004A92 18                 */ IL_0006: ldc.i4.2
		/* 0x00004A93 3322               */ IL_0007: bne.un.s IL_002b
		/* 0x00004A95 03                 */ IL_0009: ldarg.1
		/* 0x00004A96 16                 */ IL_000a: ldc.i4.0
		/* 0x00004A97 9A                 */ IL_000b: ldelem.ref
		/* 0x00004A98 750A000002         */ IL_000c: isinst AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x00004A9D 0A                 */ IL_0011: stloc.0
		/* 0x00004A9E 03                 */ IL_0012: ldarg.1
		/* 0x00004A9F 17                 */ IL_0013: ldc.i4.1
		/* 0x00004AA0 9A                 */ IL_0014: ldelem.ref
		/* 0x00004AA1 750A000002         */ IL_0015: isinst AspenTech.AspenPlus.ModelLibrary.Controls.Model /* 0200000A */
		/* 0x00004AA6 0B                 */ IL_001a: stloc.1
		/* 0x00004AA7 07                 */ IL_001b: ldloc.1
		/* 0x00004AA8 2C0D               */ IL_001c: brfalse.s IL_002b
		/* 0x00004AAA 06                 */ IL_001e: ldloc.0
		/* 0x00004AAB 2C0A               */ IL_001f: brfalse.s IL_002b
		/* 0x00004AAD 06                 */ IL_0021: ldloc.0
		/* 0x00004AAE 07                 */ IL_0022: ldloc.1
		/* 0x00004AAF FE01               */ IL_0023: ceq
		/* 0x00004AB1 8C5F000001         */ IL_0025: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004AB6 2A                 */ IL_002a: ret
		/* 0x00004AB7 16                 */ IL_002b: ldc.i4.0
		/* 0x00004AB8 8C5F000001         */ IL_002c: box [mscorlib]System.Boolean /* 0100005F */
		/* 0x00004ABD 2A                 */ IL_0031: ret
	} // end of method StreamIsCheckedConverter::Convert

	.method /* 06000106 */ public final hidebysig newslot virtual 
		instance object[] ConvertBack (
			object 'value',
			class [mscorlib]System.Type[] targetTypes,
			object parameter,
			class [mscorlib]System.Globalization.CultureInfo culture
		) cil managed 
	{
		// Method begins at RVA 0x4a05
		// Header size: 1
		// Code size: 6 (0x6)
		.maxstack 8

		/* 0x00004A05 73B900000A         */ IL_0000: newobj instance void [mscorlib]System.NotImplementedException::.ctor() /* 0A0000B9 */
		/* 0x00004A0A 7A                 */ IL_0005: throw
	} // end of method StreamIsCheckedConverter::ConvertBack

	.method /* 06000107 */ public hidebysig specialname rtspecialname 
		instance void .ctor () cil managed 
	{
		// Method begins at RVA 0x3379
		// Header size: 1
		// Code size: 7 (0x7)
		.maxstack 8

		/* 0x00003379 02                 */ IL_0000: ldarg.0
		/* 0x0000337A 286A00000A         */ IL_0001: call instance void [mscorlib]System.Object::.ctor() /* 0A00006A */
		/* 0x0000337F 2A                 */ IL_0006: ret
	} // end of method StreamIsCheckedConverter::.ctor

} // end of class AspenTech.AspenPlus.ModelLibrary.Controls.Converters.StreamIsCheckedConverter

